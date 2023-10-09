#include "syscall.h"

//const int TAILLE_LIRE_ECRIRE = 10;
char buf[10];

int main()
{
    int i = 0;

    GetString(buf, 800);

    for(i = 0; i < 800; i++)
    {
        PutChar(buf[i]);
    }

    Halt();
}