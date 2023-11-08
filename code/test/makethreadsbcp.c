// programme utilisateur qui teste la creation de threads, 

//!\\ à lancer avec -rs pour un ordonancement généré à partir d'une graine

#include "syscall.h"

const unsigned char ASCII_NUM = 0x30;
const unsigned char ASCII_LET = 0x61;

void SimpleThread(void *arg)
{
    int nom = (int)arg;
    char num = 0;
    int i = 0;
    for (num = 1; num < 10; num++)
      {
        //façons d'écrire dans la console qui mette en valeur d'autres problemes de synchronisation de la console: 
        //monprintf("je suis un thread (%c) looped %c times\n", which+48, num+48);

        /* PutString("je suis un thread (");
        PutChar(48+which);
        PutString(") boucle ");
        PutChar(48+num);
        PutString(" fois\n"); */

        //snprintf(str, 100 "je suis un thread (%d) looped %d times\n", which, num);
        //PutString(str, which, num);
        char* str = "je suis un thread aabbccdd (e)\n";
        char a = (nom >> 24) & 0xFF;
        char b = (nom >> 16) & 0xFF;
        char c = (nom >> 8) & 0xFF;
        char d = nom & 0xFF;
        str[18] = (a >> 4);
        str[19] = (a & 15);
        str[20] = (b >> 4);
        str[21] = (b & 15);
        str[22] = (c >> 4);
        str[23] = (c & 15);
        str[24] = (d >> 4);
        str[25] = (d & 15);
        
        for(i=18;i < 26; i++) str[i] += 64;

        str[28] = ASCII_NUM + num;
        PutString(str);
      }

    ThreadExit();
}

int main ()
{
    int nom;
    for(nom = 0; nom < 2000; nom++)
    {
        ThreadCreate(SimpleThread, (void*) nom);
        //PutString("ici le main.\n");
    }

    ThreadExit();
}