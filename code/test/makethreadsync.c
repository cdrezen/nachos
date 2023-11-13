// programme utilisateur qui teste la creation de threads avec des sempahores, 
// plusieurs threads augmentent le même compteur, écrivent dans le même string et affichent la progression.
// quand le compteur est arrivé à la valeur cible le mot "bogdanof" doit etre affiché

//!\\ à lancer avec -rs pour un ordonancement généré à partir d'une graine

#include "syscall.h"

#define monprintf(sem, format, args...) { P(sem); monprintf(format, ## args); V(sem); }//pour proteger le 'printf maison' car il semblait necessiter cela

typedef struct
{
  char* nom;
  int* fourchettes;
  sem_t* sem;
  sem_t* sem1;
  sem_t* io_sem;
} simple_args;

void philosophe(void *arg)
{
    simple_args* args = (struct simple_args*)(arg);
    char* nom = args->nom;
    int* fourchettes = args->fourchettes;
    sem_t* production_fourchette = args->sem;
    sem_t* consomation_fourchette = args->sem1;
    sem_t* io_sem = args->io_sem;
    int tmp_fourchette;
    while(1)
    {
      P(production_fourchette);
      //while((*fourchettes) < 200);// { monprintf(io_sem, "(%s) Oh non, il reste %d fourchettes.\n", nom, *fourchettes); }//attente active
        tmp_fourchette = --(*fourchettes);
      V(consomation_fourchette);
      monprintf(io_sem, "(%s) Miam, il reste %d fourchettes.\n", nom, tmp_fourchette);
    }
}

void fabricant_fourchettes(void* arg)
{
    simple_args* args = (struct simple_args*)(arg);
    char* nom = args->nom;
    int* fourchettes = args->fourchettes;
    sem_t* production_fourchette = args->sem;
    sem_t* consomation_fourchette = args->sem1;
    sem_t* io_sem = args->io_sem;
    int tmp_fourchette;

    while(1)
    {
      P(consomation_fourchette);
        tmp_fourchette = ++(*fourchettes);
      V(production_fourchette);
      monprintf(io_sem, "(%s) Tenez, voici 1 fouchette, il reste %d fourchettes.\n", nom, tmp_fourchette);
    }
}

const int FOURCHETTES_MIN = 1;

int main ()
{
    int fourchettes = 1;
    sem_t production_fourchette = { -1 };
    sem_t consomation_fourchette = { -1 };
    sem_t io_sem = { -1 };

    simple_args fabricant = { "Fabricant", &fourchettes, &production_fourchette, &consomation_fourchette, &io_sem };
    simple_args nietzsche = { "Nietzsche", &fourchettes, &production_fourchette, &consomation_fourchette, &io_sem };
    simple_args aristote = { "Aristote", &fourchettes, &production_fourchette, &consomation_fourchette, &io_sem };

    sem_t_init(&production_fourchette, 0);
    sem_t_init(&consomation_fourchette,2);
    sem_t_init(&io_sem, 1);

    //ThreadCreate(fabricant_fourchettes, &fabricant);
    ThreadCreate(philosophe, &nietzsche);
    ThreadCreate(philosophe, &aristote);

    //
    fabricant_fourchettes(&fabricant);

    ThreadExit();
}