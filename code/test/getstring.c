#include "syscall.h"

#define TAILLE_LIRE_ECRIRE 10

char buf[TAILLE_LIRE_ECRIRE];

int main()
{
    GetString(buf, TAILLE_LIRE_ECRIRE);
    PutString(buf);
}