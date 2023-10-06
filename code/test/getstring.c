#include "syscall.h"

char buf[7];

int main()
{
    int i = 0;

    GetString(buf, 5);

    for(i = 0; i < 7; i++)
    {
        PutChar(buf[i]);
    }

    Halt();
}