#include "userthread.h"
#include "system.h"
#include "synch.h"
#include "addrspace.h"

int stackPtr;
// static Semaphore *th = new Semaphore("t",1);
// static Semaphore *mutexNumThread = new Semaphore("mutexNumThread", 1);

static void StartUserThread(void *schmurtz)
{
    int* args = (int*)(schmurtz);

    int f = args[0];
    int arg = args[1];
    int exit = args[2];
    int pos = args[3];
    delete[] args;

    DEBUG('t', "StartUserThread   f ptr: %d     arg ptr: %d.\n", f, arg);
    
     for (int i = 0; i < NumTotalRegs; i++)
        machine->WriteRegister (i, 0);

    // Initial program counter -- must be location of the __start function
    machine->WriteRegister (PCReg, f);
    machine->WriteRegister (4, arg);
    machine->WriteRegister (RetAddrReg, exit);

    // Need to also tell MIPS where next instruction is, because
    // of branch delay possibility
    machine->WriteRegister (NextPCReg, machine->ReadRegister(PCReg) + 4);

    // Set the stack register to the end of the address space, where we
    // allocated the stack; but subtract off a bit, to make sure we don't
    // accidentally reference off the end!
    
    stackPtr = currentThread->space->AllocateUserStack(pos);

    machine->WriteRegister (StackReg, stackPtr);
    if (DebugIsEnabled('t'))
    {
        char str[64];
        snprintf(str, 63, "dumps/mem_start_%s.svg", currentThread->getName());
        machine->DumpMem (str);
    }

    machine->Run();
}

int nameid = 1;
int* schmurtz;
char name[8];

int do_ThreadCreate(int f, int arg, int exit_address)
{

    DEBUG('t', "do_ThreadCreate    f ptr: %d     arg ptr: %d.\n", f, arg);
    
    sprintf(name, "thread%d", nameid++);  
    Thread *t = new Thread(name);

    if(!t) return -1;

    schmurtz = new int[4];
    schmurtz[0] = f;
    schmurtz[1] = arg;
    schmurtz[2] = exit_address;

    t->space = currentThread->space;
    int pos = t->space->synchFind();

    if(pos == -1){
        delete[] schmurtz;
        return -1;
    }

    schmurtz[3] = pos;
    t->space->nbUserThreads++;
    t->Start(StartUserThread, schmurtz);
    currentThread->Yield();

    return 0;
}

void do_ThreadExit()
{
    Thread* t = currentThread;

    t->space->nbUserThreads--;

    DEBUG('t', "thread exit: nbUserThreads=%d\n", t->space->nbUserThreads);//

    if (DebugIsEnabled('t'))
    {
        char str[64];
        snprintf(str, 63, "dumps/mem_exit_%s.svg", t->getName());
        machine->DumpMem (str);
    }

    if(t->space->nbUserThreads > 0)
    {
        t->space->FreeUserStack(machine->ReadRegister(StackReg));//clear(pos)
        t->Finish();
    }
    else
    {
        bool isChild = t->space->isChild;
        delete t->space;
        if(!isChild) interrupt->Powerdown();
    }
}