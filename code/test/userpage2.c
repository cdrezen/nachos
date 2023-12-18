//lance un processus qui lance 27 threads affichant chacun une lettre de l’alphabet excepté un thread qui doit arreter tout les autres, toutes les lettres ne doivent pas être affichées.
//ne fonctionne pas

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