#include "syscall.h"

int main()
{
    char buf[500];
    int i; // Déplacez la déclaration de i en dehors de la boucle
    for(i = 0; i < 500; i++){
        buf[i] = 'a';
    }
    PutString(buf);
    Halt();
}
