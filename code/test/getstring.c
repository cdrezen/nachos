#include "syscall.h"

int main()
{
    char test[100];
    PutChar('t');
    PutChar('e');
    PutChar('s');
    PutChar('t');
    PutChar('\n');
    GetString(test, 5);
    PutChar(test[0]);
    PutChar(test[1]);
    PutChar(test[2]);
    PutChar(test[3]);
    PutChar(test[4]);
    Halt();
}