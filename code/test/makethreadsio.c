// programme utilisateur qui teste la creation de threads avec une synchronisation des operations d'ecriture/lecture, 

//!\\ à lancer avec -rs pour un ordonancement généré à partir d'une graine

#include "syscall.h"

const unsigned char ASCII_NUM = 0x30;
const unsigned char ASCII_LET = 0x61;

void SimpleThread(void *arg)
{
    char which = (char) arg;
    char num;

    for (num = 1; num < 10; num++)
      {
        monprintf("je suis un thread (%c) boucle %c fois\n", ASCII_LET + which, ASCII_NUM + num);
      }

    ThreadExit();
}

int main ()
{
    PutString("ici le main.\n");
    PutString("ici le main.\n");
    PutString("ici le main.\n");
    ThreadCreate(SimpleThread, (void*) 1);
    PutChar('\n');
    PutString("ici le main.\n");
    PutString("ici le main.\n");
    PutString("ici le main.\n");
    PutChar('\n');
    ThreadExit();
}