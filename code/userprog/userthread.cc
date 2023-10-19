#include "system.h"
#include "synch.h"
#include "translate.h"

/* UserThread::UserThread()
{
    userthread = new UserThread();
}

UserThread::~UserThread()
{
    delete userthread;
} */

int nameid = 0;

int do_ThreadCreate(int f, int arg)
{
    printf("do_ThreadCreate    f ptr: %d     arg ptr: %d.\n", f, arg);
    
    char[8] name;
    sprintf(name, "thread%d", nameid++);
    
    Thread *t = new Thread(name);
    
    int schmurtz[2] = {f, arg};
    t->Start(StarUserThread, schmurltz);
}

static void StartUserThread(void *schmurtz)
{
    
}