#include "syscall.h"

#define TAILLE_LIRE_ECRIRE 10
#define TAILLE_BEAUCOUP_LIRE_ECRIRE 2000

char buf[TAILLE_LIRE_ECRIRE];
char bufbcp[TAILLE_BEAUCOUP_LIRE_ECRIRE];

int main()
{
    GetString(buf, TAILLE_LIRE_ECRIRE);
    PutString(buf);
    GetString(bufbcp, TAILLE_BEAUCOUP_LIRE_ECRIRE);
    PutString(bufbcp);
}