#include "syscall.h"

int main()
{
    monprintf("blabla %d trucs sont %s. mon char est '%c', hex: %#04x.\n", 3, "machin", '*', '*');
    Halt();
}