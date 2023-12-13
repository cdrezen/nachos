#include "syscall.h"
// à lancer depuis /code

int main()
{
    //ForkExec("test/makethreadsync1");
    ForkExec("test/userpage0");
    ForkExec("test/userpage1");
    ForkExec("test/makethreadsio");
    //while(1);
}