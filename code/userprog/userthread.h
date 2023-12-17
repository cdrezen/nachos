//#include "utility.h"

//class UserThread:dontcopythis {
//public:
// initialize the UserThread obj
//UserThread();
//~UserThread(); // clean up

extern int do_ThreadCreate(int f, int arg, int exit_address);
static void StartUserThread(void *schmurtz);
extern void do_ThreadExit(void);
extern void do_Exit();

//private:
//UserThread *userthread;
//};