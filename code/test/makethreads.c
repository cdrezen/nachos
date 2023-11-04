// programme utilisateur qui teste la creation de threadsS

#include "syscall.h"

void SimpleThread(void *arg)
{
    int which = (long) arg;
    int num;

    monprintf("SimpleThread.");

    for (num = 0; num < 10; num++)
      {
          monprintf("*** thread %d looped %d times\n", which, num);
          //currentThread->Yield ();
      }
}

int main ()
{
    ThreadCreate(SimpleThread, (void*) 1);
    //while(1);
}