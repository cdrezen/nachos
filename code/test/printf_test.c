#include "syscall.h"
#include <stdarg.h>

static char ppbuf[1024];

void monprintf(char* fmt, ...)
{
    va_list args;
	char ch, *bptr;
	int i;

	va_start(args, fmt);
	i = vsprintf(ppbuf, fmt, args);

	bptr = ppbuf;

    if(!i) return;//echec

    //PutString(bptr, i);

	while((ch = *(bptr++)) != 0) {
		if(ch == '\n')
			PutChar('\r');

		PutChar(ch);
	}

	va_end(args);
}

int main()
{
    monprintf("blabla %s", "oui");
    Halt();
}