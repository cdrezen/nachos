#include "syscall.h"

int main()
{
    char buf[50];
    int i; // Déplacez la déclaration de i en dehors de la boucle
    for(i = 0; i < 50; i++){
        buf[i] = 'a';
    }

    PutString(buf);

    char buf1[2000];
    for(i = 0; i < 2000; i++){
        buf1[i] = 'a';
    }
    PutString(buf1);
}
