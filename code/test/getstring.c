#include "syscall.h"

char buf[7];

int main()
{
    char* test = "test\n";

    GetString(buf, 5);

    int i = 0;
    for(i = 0; i < 7; i++)
    {
        PutChar(buf[i]);
    }

    Halt();
}