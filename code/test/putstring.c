#include "syscall.h"

#define TAILLE_BEAUCOUP_LIRE_ECRIRE 2000

char bufbcp[TAILLE_BEAUCOUP_LIRE_ECRIRE];

int main()
{
    char buf[2000];
    //char buf1[2000];
    int i; // Déplacez la déclaration de i en dehors de la boucle

    for(i = 0; i < 2000; i++){
        buf[i] = 'a';
    }

    PutString(buf);

    PutChar('\n');

    for(i = 0; i < TAILLE_BEAUCOUP_LIRE_ECRIRE; i++){
        bufbcp[i] = 'b';
    }

    PutString(bufbcp);
}
