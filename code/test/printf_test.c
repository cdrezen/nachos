#include "syscall.h"
#include <stdarg.h>

char ppbuf[256];

void monprintf(char* fmt, ...)
{
    va_list args;
    int res_sz;

	va_start(args, fmt);

	res_sz = vsprintf(ppbuf, fmt, args);

    if(!res_sz) return;//echec

    PutString(ppbuf);//, res_sz);

	va_end(args);
}

int main()
{
    monprintf("blabla %d trucs sont %s. mon char est '%c', hex: %#04x\n", 3, "machin", '*', '*');
    Halt();
}