#include "syscall.h"

void SimpleThread(void *arg)
{
    PutChar((char)arg);
    return;//monprintf("%c\n", (char)arg);
}

void ExitThread(void *arg)
{
    Exit(0);
}

int main()
{
    const int NB_THREAD = 26;

    int i = 0;
    for(i; i < NB_THREAD; i++)
    {
        ThreadCreate(SimpleThread, 'a' + (char)i);
    }

    ThreadCreate(ExitThread, (void *)0);
    //Exit(0);
}