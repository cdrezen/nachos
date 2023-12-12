#include "synch.h"

class ForkExec 
{
private:
    int nbProc = 1;
    Lock* lock;
public:
    ForkExec();
    ~ForkExec();
    int getNbProc();
    void setNbProc(int value);
    int do_ForkExec(char* filename);
    static void StartUserProc(void * arg);

};