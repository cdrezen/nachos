// programme utilisateur qui teste la creation d'un thread, 

//!\\ à lancer avec -rs pour un ordonancement généré à partir d'une graine

#include "syscall.h"

void SimpleThread(void *arg)
{
    PutChar((char)arg);
    //ThreadExit();
}

int main()
{
    ThreadCreate(SimpleThread, 'a');
    ThreadExit();
}