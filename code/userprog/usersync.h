#include "synch.h"
#include "list.h"
#include "utility.h"

class UserSync:dontcopythis
{
    private:
    List *userSemaphores;
    int newid;
    UserSemaphore* findSemaphore(int id);
    int createSemaphore(int init);

    public:
    UserSync();
    ~UserSync();
    int     P(int id, int init);
    void    V(int id);
};
