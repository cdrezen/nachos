#include "syscall.h"

int main()
{
    char buf[1100];
    int i; // Déplacez la déclaration de i en dehors de la boucle
    for(i = 0; i < 1100; i++){
        buf[i] = 'a';
    }
    PutString(buf);
    Halt();
}
