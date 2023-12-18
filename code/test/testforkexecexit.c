#include "syscall.h"
// à lancer depuis /code
//Bonus II.5 lance un processus qui crée plusieurs thread dont un qui appel explicitement Exit afin de tester l'appel à Exit pour terminer les autres thread du processus prématurément.
//lance un processus qui lance 27 threads affichant chacun une lettre de l’alphabet excepté un thread qui doit arreter tout les autres, toutes les lettres ne doivent pas être affichées.

//ne fonctionne pas

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