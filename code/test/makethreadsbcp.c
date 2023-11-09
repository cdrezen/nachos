// programme utilisateur qui teste la creation de threads, 

//!\\ à lancer avec -rs pour un ordonancement généré à partir d'une graine

#include "syscall.h"

const unsigned char ASCII_NUM = 0x30;
const unsigned char ASCII_LET = 0x61;

void SimpleThread(void *arg)
{
    int nom = (int)arg;     
    char* str = "je suis un thread aabbccdd\n";
    int i,j,k = 0;
    long l = 0;

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

    PutString(str);

    for(j = 30; j< 8; j++) j *= 10;
    for(k = 30; k< 8; k++) k *= 10;

    for (j; j > 0; j--)
    {
      for(k; k > 0; k--)
      {
        l+= 1;
      }
    }

    str[0]='f';
    str[1]='i';
    str[2]='n';

    for(i=3;i < 11; i++) str[i] = 6;

    PutString(str);

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

//$31 | macro arg