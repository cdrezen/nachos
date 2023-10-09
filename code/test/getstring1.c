#include "syscall.h"

#define TAILLE_BEAUCOUP_LIRE_ECRIRE 4000

char bufbcp[TAILLE_BEAUCOUP_LIRE_ECRIRE];

int main()
{
    GetString(bufbcp, TAILLE_BEAUCOUP_LIRE_ECRIRE);
    PutString(bufbcp);
}