#ifdef CHANGED
#include "copyright.h"
#include "system.h"
#include "consoledriver.h"
#include "synch.h"
#include "translate.h"




static Semaphore *readAvail;
static Semaphore *writeDone;

static void ReadAvailHandler(void *arg) { (void) arg; readAvail->V(); }
static void WriteDoneHandler(void *arg) { (void) arg; writeDone->V(); }

ConsoleDriver::ConsoleDriver(const char *in, const char *out)
{
    readAvail = new Semaphore("read avail", 0);
    writeDone = new Semaphore("write done", 0);
    console = new Console (in, out, ReadAvailHandler, WriteDoneHandler, NULL);
}

ConsoleDriver::~ConsoleDriver()
{
    delete console;
    delete writeDone;
    delete readAvail;
}

void ConsoleDriver::PutChar(int ch)
{
    console->TX (ch);        // echo it!
    writeDone->P ();        // wait for write to finish
}

char ConsoleDriver::GetChar()
{

 readAvail->P ();        // wait for character to arrive
 char ch = console->RX();
 return ch;
}

void ConsoleDriver::PutString(const char *s)
{
    for (int i = 0; s+1 != NULL; i++){
        PutChar(*(s+i));
    }
}

void ConsoleDriver::GetString(char *s, int n)
{
    for(int i = 0; i < n; i++) s[i] = GetChar();
}

unsigned ConsoleDriver::copyStringFromMachine(int from, char *to, unsigned size){
    int p;
    unsigned int i = 0;
    for(; i < size; i++){
        machine->ReadMem(from, 1, &p);
        if(p == '\0'){
            to[i] = p;
        }
        else{
            to[i+1] = '\0';
            break;
        }
    }
    return true;
}


#endif // CHANGED