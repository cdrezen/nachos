//programme de test de PutString
//le programme effectue une ecriture dans la console de taille TAILLE_LIRE_ECRIRE puis de taille TAILLE_BEAUCOUP_LIRE_ECRIRE
//cepandant il n'ecrira pas plus que MAX_STRING_SIZE

#include "syscall.h"

#define TAILLE_LIRE_ECRIRE 50
#define TAILLE_BEAUCOUP_LIRE_ECRIRE 2700

char buf[TAILLE_LIRE_ECRIRE];
char bufbcp[TAILLE_BEAUCOUP_LIRE_ECRIRE];

int main()
{
    int i; // Déplacez la déclaration de i en dehors de la boucle

    for(i = 0; i < TAILLE_LIRE_ECRIRE; i++){
        buf[i] = 'a';
    }

    monprintf("PrintString avec buffer de taille %d:\n", TAILLE_LIRE_ECRIRE);

    PutString(buf);

    monprintf("\nPrintString avec buffer de taille %d:\n", TAILLE_BEAUCOUP_LIRE_ECRIRE);

    for(i = 0; i < TAILLE_BEAUCOUP_LIRE_ECRIRE; i++){
        bufbcp[i] = 'b';
    }

    PutString(bufbcp);
}
