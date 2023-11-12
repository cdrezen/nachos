#include "usersync.h"

UserSync::UserSync()
{
    newid=0;
    userSemaphores = new List;
}

UserSync::~UserSync()
{
    delete userSemaphores;
}

UserSemaphore* UserSync::findSemaphore(int id)
{
    for (ListElement* e = userSemaphores->FirstElement(); e; e = e->next)
    {
        UserSemaphore* sem = (UserSemaphore*)e->item;
        if(sem->getId() == id) return sem;
    }

    return NULL;
}

int UserSync::createSemaphore(int init)
{
    if(init < 0) return -1;
    char name[16];
    int id = this->newid++;
    sprintf(name, "usem%d", id);  
    UserSemaphore* sem = new UserSemaphore(name, id, init);
    userSemaphores->Append(sem);
    return id;
}

int UserSync::P(int id, int init)
{
    if(id == -1) return createSemaphore(init);

    UserSemaphore* sem = findSemaphore(id);
    if(!sem) return -1;

    sem->P();

    return 0;
}

void UserSync::V(int id)
{
    UserSemaphore* sem = findSemaphore(id);
    if(!sem) return;
    sem->V();
}