// programme utilisateur qui teste la creation de threads, 

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
        //façons d'écrire dans la console qui mette en valeur d'autres problemes de synchronisation de la console: 
        //monprintf("je suis un thread (%c) looped %c times\n", which+48, num+48);

        /* PutString("je suis un thread (");
        PutChar(48+which);
        PutString(") boucle ");
        PutChar(48+num);
        PutString(" fois\n"); */

        //snprintf(str, 100 "je suis un thread (%d) looped %d times\n", which, num);
        //PutString(str, which, num);

        char* str = "je suis un thread (x) looped y times\n";
        str[19] = ASCII_LET+which;
        str[29] = ASCII_NUM+num;
        PutString(str);
      }

    ThreadExit();
}

int main ()
{
    ThreadCreate(SimpleThread, (void*) 1);
    PutChar('\n');
    ThreadCreate(SimpleThread, (void*) 2);
    PutString("ici le main.\n");
    ThreadCreate(SimpleThread, (void*) 3);
    ThreadCreate(SimpleThread, (void*) 4);
    ThreadCreate(SimpleThread, (void*) 5);
    ThreadCreate(SimpleThread, (void*) 6);
    ThreadCreate(SimpleThread, (void*) 7);
    ThreadExit();
}