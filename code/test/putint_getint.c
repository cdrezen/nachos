//programme de test de GetInt et PutInt
//on doit entrer un entier de 1 à 11 caractères (signe inclu)
//le programme repete l'entier lu et ecrit un entier de taille 10
#include "syscall.h"

int main()
{
    int i = 0;
    GetInt(&i);
    PutInt(i);
    PutChar('\n');
    PutInt(1999999999);
    Halt();
}