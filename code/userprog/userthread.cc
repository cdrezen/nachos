#include "system.h"
#include "synch.h"
#include "translate.h"

/* UserThread::UserThread()
{
    userthread = new UserThread();
}

UserThread::~UserThread()
{
    delete userthread;
} */

int nameid = 0;

int do_ThreadCreate(int f, int arg)
{
    printf("do_ThreadCreate    f ptr: %d     arg ptr: %d.\n", f, arg);
    
    char[8] name;
    sprintf(name, "thread%d", nameid++);
    
    Thread *t = new Thread(name);
    
    void schmurtz[2] = {f, arg};
    t->Start(StarUserThread, schmurltz);
}

static void StartUserThread(void *schmurtz)
{
    int i;

    for (i = 0; i < NumTotalRegs; i++)
        machine->WriteRegister (i, 0);

    // Initial program counter -- must be location of the __start function
    machine->WriteRegister (PCReg, schmurtz[0]);

    // Need to also tell MIPS where next instruction is, because
    // of branch delay possibility
    machine->WriteRegister (NextPCReg, machine->ReadRegister(PCReg) + 4);

    // Set the stack register to the end of the address space, where we
    // allocated the stack; but subtract off a bit, to make sure we don't
    // accidentally reference off the end!
    machine->WriteRegister (StackReg, numPages * PageSize - 16);
    DEBUG ('a', "Initializing stack register to 0x%x\n",
           numPages * PageSize - 16);
}