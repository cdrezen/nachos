// programme utilisateur qui teste la creation de threads, 

//!\\ à lancer avec -rs pour un ordonancement généré à partir d'une graine

#include "syscall.h"

void SimpleThread(void *arg)
{
    char which = (char) arg;
    char num;

    for (num = 1; num < 10; num++)
      {
        //façons d'écrire dans la console qui mette en valeur le probleme de synchronisation de la console: 
        //monprintf("je suis un thread (%c) looped %c times\n", which+48, num+48);

        /* PutString("je suis un thread (");
        PutChar(48+which);
        PutString(") boucle ");
        PutChar(48+num);
        PutString(" fois\n"); */

        //snprintf(str, 100 "je suis un thread (%d) looped %d times\n", which, num);
        //PutString(str, which, num);

        char* str = "je suis un thread (x) looped y times\n";
        str[19] = 48+which;
        str[29] = 48+num;
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
    while(1);
}