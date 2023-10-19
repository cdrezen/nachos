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

int do_ThreadCreate(int f, int arg)
{
    printf("do_ThreadCreate    f ptr: %d     arg ptr: %d.\n", f, arg);
}