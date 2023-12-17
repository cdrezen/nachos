#include "syscall.h"
// à lancer depuis /code
//lance 12 processus 'lent', chacun avec un 12 de threads.

int main()
{
    /*const int NB_PROC = 12;

    int i = 0;
    for(i; i < NB_PROC; i++)
    {
        ForkExec("test/userpage2");
    } */
    ForkExec("test/userpage2");
}