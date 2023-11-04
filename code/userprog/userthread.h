//#include "utility.h"

//class UserThread:dontcopythis {
//public:
// initialize the UserThread obj
//UserThread();
//~UserThread(); // clean up

extern int do_ThreadCreate(int f, int arg);
static void StartUserThread(void *schmurtz);
extern void do_ThreadExit(void);

//private:
//UserThread *userthread;
//};