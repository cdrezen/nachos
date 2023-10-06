#include "syscall.h"

char buf[7];

int main()
{
    char* test = "test\n";

    int i = 0;
    for(i = 0; i < 5; i++)
    {
        PutChar(test[i]);
    }

    GetString(buf, 5);

    for(i = 0; i < 7; i++)
    {
        PutChar(buf[i]);
    }

    Halt();
}