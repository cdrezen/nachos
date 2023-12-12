#include "userthread.h"
#include "system.h"
#include "synch.h"
#include "addrspace.h"


static void StartUserProc(void * arg)
{
    DEBUG('t', "StartUserProc.\n");
    
    currentThread->space->InitRegisters();

    currentThread->space->RestoreState ();	// load page table register

    machine->DumpMem ("proc.svg");

    machine->Run();


}

int do_ForkExec(char* filename)
{
    OpenFile *executable = fileSystem->Open (filename);
    AddrSpace *space;

    if (executable == NULL)
      {
          SetColor (stdout, ColorRed);
          SetBold (stdout);
          printf ("Unable to open file %s\n", filename);
          ClearColor (stdout);
          return -1;
      }
    space = new AddrSpace (executable);

    delete executable;		// close file

    Thread* t = new Thread("proc");
    t->space = space;
    t->Start(StartUserProc, NULL);

    return 0;
}



/*void
StartProcess (char *filename)
{
    OpenFile *executable = fileSystem->Open (filename);
    AddrSpace *space;

    if (executable == NULL)
      {
          SetColor (stdout, ColorRed);
          SetBold (stdout);
          printf ("Unable to open file %s\n", filename);
          ClearColor (stdout);
          return;
      }
    space = new AddrSpace (executable);
    currentThread->space = space;

    delete executable;		// close file

    space->InitRegisters ();	// set the initial register values
    space->RestoreState ();	// load page table register

    machine->DumpMem ("memory.svg");
    machine->Run ();		// jump to the user progam
    ASSERT_MSG (FALSE, "Machine->Run returned???\n");	// machine->Run never returns;
    // the address space exits
    // by doing the syscall "exit"
}*/