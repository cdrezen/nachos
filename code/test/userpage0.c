#include "syscall.h"

void SimpleThread(void *arg)
{
    PutChar((char)arg);
    //ThreadExit();
}

int main()
{
    PutChar('o');
    PutString("\nbob");
    ThreadCreate(SimpleThread, 'a');
    ThreadCreate(SimpleThread, 'b');
    ThreadExit();
}