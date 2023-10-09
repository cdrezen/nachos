//programme qui teste le uniquement le printf fait maison
//il doit renvoyer "blabla 3 trucs sont machin. mon char est '*', hex: 0x2a."
#include "syscall.h"

int main()
{
    //on appel le printf fait maison dans vsprintf.c
    return monprintf("blabla %d trucs sont %s. mon char est '%c', hex: %#04x.\n", 3, "machin", '*', '*');
}