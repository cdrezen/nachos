#include "syscall.h"

    char buf[3000];
int main()
{
    int i; // Déplacez la déclaration de i en dehors de la boucle
    for(i = 0; i < 3000; i++){
        buf[i] = 'a';
    }
    PutString(buf);
    Halt();
}
