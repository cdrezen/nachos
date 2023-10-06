#include "syscall.h"

int main()
{

    char test[5];
    PutChar('t');
    PutChar('e');
    PutChar('s');
    PutChar('t');
    PutChar('\n');
    GetString(test, 4);
    for(int i = 0; i < 5; i++)
    {
        PutChar(test[i]);
    }
    Halt();
}