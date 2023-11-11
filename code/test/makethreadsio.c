// programme utilisateur qui teste la creation de threads avec une synchronisation des operations d'ecriture/lecture, 

//!\\ à lancer avec -rs pour un ordonancement généré à partir d'une graine

#include "syscall.h"

const unsigned char ASCII_NUM = 0x30;
const unsigned char ASCII_LET = 0x61;

void SimpleThread(void *arg)
{
    char which = (char) arg;
    char num;

    char* str = "je suis un thread (x) looped y times\n";

    for (num = 1; num < 10; num++)
      {
        str[19] = ASCII_LET+which;
        str[29] = ASCII_NUM+num;
        PutString(str);
      }

    ThreadExit();
}

int main ()
{
    PutString("ici le main.\n");
    PutString("ici le main.\n");
    PutString("ici le main.\n");
    ThreadCreate(SimpleThread, (void*) 1);
    ThreadCreate(SimpleThread, (void*) 2);
    ThreadCreate(SimpleThread, (void*) 3);
    PutChar('\n');
    PutString("ici le main.\n");
    PutString("ici le main.\n");
    PutString("ici le main.\n");
    PutChar('\n');
    ThreadExit();
}