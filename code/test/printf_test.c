#include "syscall.h"

int main()
{
    //on appel le printf fait maison dans vsprintf.c
    return monprintf("blabla %d trucs sont %s. mon char est '%c', hex: %#04x.\n", 3, "machin", '*', '*');
}