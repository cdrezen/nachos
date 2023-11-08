// programme utilisateur qui teste la creation de threads et leur termination, 
// -d permet d'afficher le nombre de threads restant dans lespace d'adressage -1 avant l'appel à thread->finish ou interput->powerdown

#include "syscall.h"

void SimpleThread()
{
    PutString("je suis un thread\n");
    ThreadExit();
}

int main ()
{
    ThreadCreate(SimpleThread, 0);
    PutString("ici le main.\n");
    ThreadCreate(SimpleThread, 0);
    ThreadCreate(SimpleThread, 0);
    ThreadExit();
}