#include "syscall.h"
#include <stdlib.h>
#include <stdio.h>

int main()
{

    char test[5];
    PutChar('t');
    PutChar('e');
    PutChar('s');
    PutChar('t');
    PutChar('\n');
    GetString(test, 4);
    printf("%s", test);
    Halt();
}