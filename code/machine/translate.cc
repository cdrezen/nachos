// translate.cc
//	Routines to translate virtual addresses to physical addresses.
//	Software sets up a table of legal translations.  We look up
//	in the table on every memory reference to find the true physical
//	memory location.
//
// Two types of translation are supported here.
//
//	Linear page table -- the virtual page # is used as an index
//	into the table, to find the physical page #.
//
//	Translation lookaside buffer -- associative lookup in the table
//	to find an entry with the same virtual page #.  If found,
//	this entry is used for the translation.
//	If not, it traps to software with an exception.
//
//	In practice, the TLB is much smaller than the amount of physical
//	memory (16 entries is common on a machine that has 1000's of
//	pages).  Thus, there must also be a backup translation scheme
//	(such as page tables), but the hardware doesn't need to know
//	anything at all about that.
//
//	Note that the contents of the TLB are specific to an address space.
//	If the address space changes, so does the contents of the TLB!
//
// DO NOT CHANGE -- part of the machine emulation
//
// Copyright (c) 1992-1993 The Regents of the University of California.
// All rights reserved.  See copyright.h for copyright notice and limitation
// of liability and disclaimer of warranty provisions.

#include "copyright.h"
#include "machine.h"
#include "addrspace.h"
#include "system.h"

// Routines for converting Words and Short Words to and from the
// simulated machine's format of little endian.  These end up
// being NOPs when the host machine is also little endian (DEC and Intel).

unsigned int
WordToHost(unsigned int word)
{
#ifdef HOST_IS_BIG_ENDIAN
    register unsigned long result;
    result = (word >> 24) & 0x000000ff;
    result |= (word >> 8) & 0x0000ff00;
    result |= (word << 8) & 0x00ff0000;
    result |= (word << 24) & 0xff000000;
    return result;
#else
    return word;
#endif /* HOST_IS_BIG_ENDIAN */
}

unsigned short
ShortToHost(unsigned short shortword)
{
#ifdef HOST_IS_BIG_ENDIAN
    register unsigned short result;
    result = (shortword << 8) & 0xff00;
    result |= (shortword >> 8) & 0x00ff;
    return result;
#else
    return shortword;
#endif /* HOST_IS_BIG_ENDIAN */
}

unsigned int
WordToMachine(unsigned int word) { return WordToHost(word); }

unsigned short
ShortToMachine(unsigned short shortword) { return ShortToHost(shortword); }

//----------------------------------------------------------------------
// Machine::ReadMem
//	Read "size" (1, 2, or 4) bytes of virtual memory at "virtAddr" into
//	the location pointed to by "value".
//
//	Returns FALSE if the translation step from virtual to physical memory
//	failed.
//
//	"virtAddr" -- the virtual address to read from
//	"size" -- the number of bytes to read (1, 2, or 4)
//	"value" -- the place to write the result
//----------------------------------------------------------------------

bool Machine::ReadMem(int virtAddr, int size, int *value, bool debug)
{
    int data;
    ExceptionType exception;
    int physicalAddress;

    if (debug)
        DEBUG('a', "Reading VA 0x%x, size %d\n", virtAddr, size);

    exception = Translate(virtAddr, &physicalAddress, size, FALSE, debug);
    if (exception != NoException)
    {
        machine->RaiseException(exception, virtAddr);
        return FALSE;
    }
    switch (size)
    {
    case 1:
        data = machine->mainMemory[physicalAddress];
        *value = data;
        break;

    case 2:
        data = *(unsigned short *)&machine->mainMemory[physicalAddress];
        *value = ShortToHost(data);
        break;

    case 4:
        data = *(unsigned int *)&machine->mainMemory[physicalAddress];
        *value = WordToHost(data);
        break;

    default:
        ASSERT_MSG(FALSE, "Invalid size %d\n", size);
    }

    if (debug)
        DEBUG('a', "\tvalue read = %8.8x\n", *value);
    return (TRUE);
}

bool Machine::ReadMem(int virtAddr, int size, int *value)
{
    return ReadMem(virtAddr, size, value, TRUE);
}

//----------------------------------------------------------------------
// Machine::WriteMem
//	Write "size" (1, 2, or 4) bytes of the contents of "value" into
//	virtual memory at location "virtAddr".
//
//	Returns FALSE if the translation step from virtual to physical memory
//	failed.
//
//	"virtAddr" -- the virtual address to write to
//	"size" -- the number of bytes to be written (1, 2, or 4)
//	"value" -- the data to be written
//----------------------------------------------------------------------

bool Machine::WriteMem(int virtAddr, int size, int value)
{
    ExceptionType exception;
    int physicalAddress;

    DEBUG('a', "Writing VA 0x%x, size %d, value 0x%x\n", virtAddr, size, value);

    exception = Translate(virtAddr, &physicalAddress, size, TRUE, TRUE);
    if (exception != NoException)
    {
        machine->RaiseException(exception, virtAddr);
        return FALSE;
    }
    switch (size)
    {
    case 1:
        machine->mainMemory[physicalAddress] = (unsigned char)(value & 0xff);
        break;

    case 2:
        *(unsigned short *)&machine->mainMemory[physicalAddress] = ShortToMachine((unsigned short)(value & 0xffff));
        break;

    case 4:
        *(unsigned int *)&machine->mainMemory[physicalAddress] = WordToMachine((unsigned int)value);
        break;

    default:
        ASSERT_MSG(FALSE, "Invalid size %d\n", size);
    }

    return TRUE;
}

//----------------------------------------------------------------------
// Machine::Translate
//	Translate a virtual address into a physical address, using
//	either a page table or a TLB.  Check for alignment and all sorts
//	of other errors, and if everything is ok, set the use/dirty bits in
//	the translation table entry, and store the translated physical
//	address in "physAddr".  If there was an error, returns the type
//	of the exception.
//
//	"virtAddr" -- the virtual address to translate
//	"physAddr" -- the place to store the physical address
//	"size" -- the amount of memory being read or written
//	"writing" -- if TRUE, check the "read-only" bit in the TLB
//----------------------------------------------------------------------

ExceptionType
Machine::Translate(int virtAddr, int *physAddr, int size, bool writing, bool debug)
{
    int i;
    unsigned int vpn, offset;
    TranslationEntry *entry;
    unsigned int pageFrame;

    if (debug)
        DEBUG('a', "\tTranslate 0x%x, %s: ", virtAddr, writing ? "write" : "read");

    // check for alignment errors
    if (((size == 4) && (virtAddr & 0x3)) || ((size == 2) && (virtAddr & 0x1)))
    {
        if (debug)
            DEBUG('a', "alignment problem at %d, size %d!\n", virtAddr, size);
        return AddressErrorException;
    }

    // we must have either a TLB or a page table, but not both!
    ASSERT_MSG(tlb == NULL || currentPageTable == NULL, "We don't have a TLB nor a page table!\n");
    ASSERT_MSG(tlb != NULL || currentPageTable != NULL, "We have both a TLB and a page table!\n");

    // calculate the virtual page number, and offset within the page,
    // from the virtual address
    vpn = (unsigned)virtAddr / PageSize;
    offset = (unsigned)virtAddr % PageSize;

    if (tlb == NULL)
    { // => page table => vpn is index into table
        if (vpn >= currentPageTableSize)
        {
            if (debug)
                DEBUG('a', "virtual page # %d too large for page table size %d!\n",
                      virtAddr, currentPageTableSize);
            return AddressErrorException;
        }
        else if (!currentPageTable[vpn].valid)
        {
            if (debug)
                DEBUG('a', "virtual page # %d : page %d is invalid !\n",
                      virtAddr, vpn);
            return PageFaultException;
        }
        entry = &currentPageTable[vpn];
    }
    else
    {
        for (entry = NULL, i = 0; i < TLBSize; i++)
            if (tlb[i].valid && (tlb[i].virtualPage == vpn))
            {
                entry = &tlb[i]; // FOUND!
                break;
            }
        if (entry == NULL)
        { // not found
            if (debug)
                DEBUG('a', "*** no valid TLB entry found for this virtual page!\n");
            return PageFaultException; // really, this is a TLB fault,
                                       // the page may be in memory,
                                       // but not in the TLB
        }
    }

    if (entry->readOnly && writing)
    { // trying to write to a read-only page
        if (tlb == NULL)
        {
            if (debug)
                DEBUG('a', "%d mapped read-only in page table!\n", virtAddr);
        }
        else
        {
            if (debug)
                DEBUG('a', "%d mapped read-only at %d in TLB!\n", virtAddr, i);
        }
        return ReadOnlyException;
    }
    pageFrame = entry->physicalPage;

    // if the pageFrame is too big, there is something really wrong!
    // An invalid translation was loaded into the page table or TLB.
    if (pageFrame >= NumPhysPages)
    {
        if (debug)
            DEBUG('a', "*** frame %d > %d!\n", pageFrame, NumPhysPages);
        return BusErrorException;
    }
    entry->use = TRUE; // set the use, dirty bits
    if (writing)
        entry->dirty = TRUE;
    *physAddr = pageFrame * PageSize + offset;
    ASSERT_MSG((*physAddr >= 0) && ((*physAddr + size) <= MemorySize), "Invalid physical address %d (memory size is %d)\n", *physAddr, MemorySize);
    if (debug)
        DEBUG('a', "phys addr = 0x%x\n", *physAddr);
    return NoException;
}

#ifdef CHANGED
unsigned Machine::copyStringFromMachine(int from, char *to, unsigned size){
    int p;
    unsigned int i;
    for(i = 0; i < size && machine->ReadMem(from+i, 1, &p); i++){
        //On caste car ReadMem demande en argument un int et to un char
            to[i] = (char)p; 
            if(to[i] == '\0'){
                return 0;
            }
        }
        return i;
    }

unsigned Machine::copyStringToMachine(int to_ptr, char *buf, unsigned size)
{
    for (int i = 0; i < size; i++) // on ecrit 1 byte à la fois
    {
        if (!WriteMem(to_ptr + i, 1, (int)buf[i])) return -1;
        if(buf[i] == '\0') return i + 1;
    }

    // on rajoute la terminaison du string
    if (!WriteMem(to_ptr + size, 1, '\0')) return -1;

    return size;
}

#endif
