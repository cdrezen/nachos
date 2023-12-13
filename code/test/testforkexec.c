#include "syscall.h"
// à lancer depuis /code

int main()
{
    ForkExec("test/putchar");
    ForkExec("test/putchar");
    //while(1);
}