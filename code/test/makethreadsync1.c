// programme utilisateur qui teste la creation de threads avec des sempahores, 
// plusieurs threads augmentent le même compteur, écrivent dans le même string et affichent la progression.
// quand le compteur est arrivé à la valeur cible le mot "bogdanof" doit etre affiché

//!\\ à lancer avec -rs pour un ordonancement généré à partir d'une graine

#include "syscall.h"

const unsigned char ASCII_NUM = 0x30;
const unsigned char ASCII_LET = 0x61;

const unsigned int BOGDANOF = 509808101;

#define monprintf(sem, format, args...) { P(sem); monprintf(format, ## args); V(sem); }//pour proteger le 'printf maison' car il semblait necessiter cela

void charSplit(unsigned char* c, unsigned char* c1, unsigned char* c2)
{
    *c1 = (*c >> 4);
    *c2 = (*c & 15);//[0;16[
}

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

typedef struct
{
  char name;
  char* str;
  int* compteur;
  sem_t* sem;
  sem_t* io_sem;
} simple_args;

void SimpleThread(void *arg)
{
    simple_args* args = (struct simple_args*)(arg);
    char name = args->name;
    char* str = args->str;
    int* compteur = args->compteur;
    sem_t* sem = args->sem;
    sem_t* io_sem = args->io_sem;
    int compteur_local = 0;
    int tmp_compteur = 0;

    P(sem);
      tmp_compteur = *compteur;
    V(sem);
    
    for (tmp_compteur; tmp_compteur < BOGDANOF; compteur_local++)
      {
        P(sem);

        if(*compteur <= BOGDANOF) uintTo8Letters(*compteur, str);
        tmp_compteur = (*compteur)++;

        monprintf(io_sem, "(%c) ilocal=%d compteur=%d: %s\n", name, compteur_local, tmp_compteur, str)
        
        V(sem);
      }
}

int main ()
{
    char* str = "aabbccdd";//"(x)(y) : aabbccdd\n";
    int compteur = BOGDANOF - 3000;
    sem_t sem = { -1 };
    sem_t io_sem = { -1 };

    simple_args a = { 'a', str, &compteur, &sem, &io_sem };
    simple_args b = { 'b', str, &compteur, &sem, &io_sem };
    simple_args c = { 'c', str, &compteur, &sem, &io_sem };

    sem_t_init(&sem, 1);
    sem_t_init(&io_sem, 1);

    ThreadCreate(SimpleThread, &a);
    ThreadCreate(SimpleThread, &b);
    ThreadCreate(SimpleThread, &c);

    //ThreadExit();
}