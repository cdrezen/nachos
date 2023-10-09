//programme de test de GetString et PutString avec à peu près autant de caractères que l'on allouer
//on doit entrer au moins MAX_STRING_SIZE caractères à la main (si on n'appuie pas sur entrer plus tot)
//le programme repete l'entre jusqu'à MAX_STRING_SIZE avec PutString
#include "syscall.h"

#define TAILLE_BEAUCOUP_LIRE_ECRIRE 2700

char bufbcp[TAILLE_BEAUCOUP_LIRE_ECRIRE];

int main()
{
    GetString(bufbcp, TAILLE_BEAUCOUP_LIRE_ECRIRE);
    PutString(bufbcp);
}