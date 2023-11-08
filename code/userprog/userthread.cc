#include "system.h"
#include "synch.h"
#include "translate.h"
#include "machine.h"

int stackPtr;

static void StartUserThread(void *schmurtz)
{
    int* args = (int*)(schmurtz);

    int f = args[0];
    int arg = args[1];

    delete[] args;

    DEBUG('t', "StartUserThread   f ptr: %d     arg ptr: %d.\n", f, arg);
    
     for (int i = 0; i < NumTotalRegs; i++)
        machine->WriteRegister (i, 0);

    // Initial program counter -- must be location of the __start function
    machine->WriteRegister (PCReg, f);
    machine->WriteRegister (4, arg);

    // Need to also tell MIPS where next instruction is, because
    // of branch delay possibility
    machine->WriteRegister (NextPCReg, machine->ReadRegister(PCReg) + 4);

    // Set the stack register to the end of the address space, where we
    // allocated the stack; but subtract off a bit, to make sure we don't
    // accidentally reference off the end!
    
    stackPtr = currentThread->space->AllocateUserStack();

    machine->WriteRegister (StackReg, stackPtr);

    //currentThread->Yield();

    //currentThread->RestoreUserState();

    machine->Run();
}

int nameid = 1;
int* schmurtz;
char name[8];

int do_ThreadCreate(int f, int arg)
{
    DEBUG('t', "do_ThreadCreate    f ptr: %d     arg ptr: %d.\n", f, arg);
    
    sprintf(name, "thread%d", nameid++);  
    Thread *t = new Thread(name);

    if(!t) return -1;
    
    schmurtz = new int[2];
    schmurtz[0] = f;
    schmurtz[1] = arg;
    t->space = currentThread->space;
    t->space->nbUserThreads++;
    //t->RestoreUserState();
    t->SaveUserState();
    t->Start(StartUserThread, schmurtz);
    currentThread->Yield();
    
    return 0;
}

void do_ThreadExit()
{
    Thread* t = currentThread;

    t->RestoreUserState();

    t->space->nbUserThreads--;
    DEBUG('t', "thread exit: nbUserThreads=%d\n", t->space->nbUserThreads);//

    if(t->space->nbUserThreads > 0) t->Finish();
    else interrupt->Powerdown(); 
}