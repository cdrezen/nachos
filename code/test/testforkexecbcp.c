#include "syscall.h"
// à lancer depuis /code
//lance 12 processus 'lent', chacun avec un 12 de threads.
//-rs 1234 déclenche une erreur, peut etre qu'il manque un verrou quelque part?

int main()
{
    const int NB_PROC = 12;

    int i = 0;
    for(i; i < NB_PROC; i++)
    {
        ForkExec("test/makethreadsbcp");
    }
    //while(1);
}