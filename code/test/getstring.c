#include "syscall.h"

int main()
{
    char test[5];
    PutChar('t');
    PutChar('e');
    PutChar('s');
    PutChar('t');
    PutChar('\n');
    char test1[7];
    GetString(test1, 7);
    for(int i = 0; i < 7; i++)
    {
        PutChar(test[i]);
    }
    Halt();
}