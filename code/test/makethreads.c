// programme utilisateur qui teste plusieurs threads avec l'utilisation du bitmap
// UserStacksAreaSize = 1024 dans cette exemple 
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
    ThreadCreate(SimpleThread, 'b');
    ThreadCreate(SimpleThread, 'c');
    ThreadCreate(SimpleThread, 'd');
    ThreadExit();
} 