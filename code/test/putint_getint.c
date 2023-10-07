#include "syscall.h"

int main()
{
    int i = 0;
    GetInt(&i);
    PutInt(199999999);
    Halt();
}