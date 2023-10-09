//programme de test de GetString et PutString
//on doit entrer des caractères et au moins appuyer sur entrer
//le programme repete l'entre jusqu'à TAILLE_LIRE_ECRIRE char avec PutString
#include "syscall.h"

#define TAILLE_LIRE_ECRIRE 10

char buf[TAILLE_LIRE_ECRIRE];

int main()
{
    GetString(buf, TAILLE_LIRE_ECRIRE);
    PutString(buf);
}