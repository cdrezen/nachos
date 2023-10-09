//programme de test pour putchar, il doit écrire abcd et retourner 67 sans appel Halt
#include "syscall.h"

void print(char c, int n)
{
    int i;
    for (i = 0; i < n; i++)
    {
        PutChar(c + i);
    }
    PutChar('\n');
}
int main()
{
    print('a', 4);
    //Halt(); -> return 1 à la place -> pas d'appel sys 1
    return 67;
}