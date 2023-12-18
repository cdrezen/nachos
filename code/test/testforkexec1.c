#include "syscall.h"
// à lancer depuis /code
// pour tester le fait que le programme courant et le programme lancé peuvent eux-même contenir des thread et aussi pour tester d'éventuel problème de synchronisation de la console sous plusieurs processus
// (les lettres dans le désordres sont attendus pour userpage 0 et 1)
int main()
{
    //ForkExec("test/makethreadsync1");
    ForkExec("test/userpage0");
    ForkExec("test/userpage1");
    ForkExec("test/makethreadsio");
    //while(1);
}