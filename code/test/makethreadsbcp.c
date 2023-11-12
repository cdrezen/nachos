// programme utilisateur qui teste la creation de beaucoup de threads, 

//!\\ à lancer avec -rs pour un ordonancement généré à partir d'une graine

#include "syscall.h"

const unsigned char ASCII_NUM = 0x30;
const unsigned char ASCII_LET = 0x61;

const unsigned int BONJOAAA = 517595136;
const unsigned int BONJOOLE = 517598900;
const unsigned int BOGDANOF = 509808101;

/* void uintToBase26(unsigned val, char* str)
{
  int i;
  for (i = 0; i < 8 && val > 0; i++) 
    {
        str[i] = ASCII_LET + (val % 26);
        val /= 26;
    }

  if(i < 26) for(i; i < 6; i++) str[i] = 'a';
  //str[7] = 0;
} */

void charSplit(unsigned char* c, unsigned char* c1, unsigned char* c2)
{
    *c1 = (*c >> 4);
    *c2 = (*c & 15);//[0;16[
}

//509807872 bogdanaa
//509808101 bogdanof
//517537792 bonjaaaa
//517595136 bonjoaaa
//517598900 bonjoole
//mot avec 'a' en i = 256*16*i*'a'?
void uintTo8Letters(unsigned val, char* str)
{
    unsigned char a = (val >> 24) & 0xFF;//[0;256[
    unsigned char b = (val >> 16) & 0xFF;
    unsigned char c = (val >> 8) & 0xFF;
    unsigned char d = val & 0xFF;
    int i;
    charSplit(&a, str, str+1);
    charSplit(&b, str+2, str+3);
    charSplit(&c, str+4, str+5);
    charSplit(&d, str+6, str+7);
    //monprintf("%d %d %d\n", d, str[6], str[7]);
    for(i=0;i < 8; i++) str[i] += ASCII_LET;
}

//on a du faire des threads plus 'gourmand' pour qu'ils puissent 'entrer en conflit'
void ThreadLent(void *arg)
{
    unsigned int id = (int)arg;     
    char* str = "je suis le thread 'aabbccdd'.\n";
    char* nom = str+19;
    char bjr[8];

    unsigned int i = 0;

    uintTo8Letters(id, nom);

    PutString(str);

    //une operation 'lourde' en temps cpu pour trouver "bonjoole"
    //en generant beaucoup des mots à partir d'entier et en comparant chacun leurs 3 derniers char
    for (i = BONJOAAA; i <= BONJOOLE; i++)
    {
      uintTo8Letters(i, bjr);
      if(bjr[5] == 'o' && bjr[6] == 'l' && bjr[7] == 'e') break;
    }

    for(i=0;i < 8; i++) str[i] = bjr[i];
    str[8] = ' ';
    str[9] = '@'; 

    PutString(str);

    ThreadExit();
}

//si ils partagent la meme pile et s'executent 'aleatoirement' ils réécrivent aux même adresses : problemes.
int main ()
{
    unsigned nom;
    const unsigned NB_THREAD = 10;

    for(nom = BOGDANOF; nom < BOGDANOF + NB_THREAD; nom++)
    {
      ThreadCreate(ThreadLent, (void*) nom);
      //PutString("ici le main.\n");
    }

    PutString("main: plus rien a faire.\n");

    //while(1);

    ThreadExit();
}

//$31 | macro arg