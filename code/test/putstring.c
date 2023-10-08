#include "syscall.h"

int main()
{
    char buf[50];
    int i; // Déplacez la déclaration de i en dehors de la boucle
    for(i = 0; i < 50; i++){
        buf[i] = 'a';
    }
    PutString(buf);
    Halt();
}
