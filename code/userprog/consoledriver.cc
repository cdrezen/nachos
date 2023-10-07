#ifdef CHANGED
#include "copyright.h"
#include "system.h"
#include "consoledriver.h"
#include "synch.h"
#include "translate.h"




static Semaphore *readAvail;
static Semaphore *writeDone;
static Semaphore *stringIO;

static void ReadAvailHandler(void *arg) { (void) arg; readAvail->V(); }
static void WriteDoneHandler(void *arg) { (void) arg; writeDone->V(); }

ConsoleDriver::ConsoleDriver(const char *in, const char *out)
{
    readAvail = new Semaphore("read avail", 0);
    writeDone = new Semaphore("write done", 0);
    stringIO = new Semaphore("string operation", 0);//VII au cas où plusieurs thread veuillent lire ou ecrire en meme temps

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

//VII.4
void ConsoleDriver::PutInt(int i)
{

}

void  ConsoleDriver::GetInt(int ptr);

void ConsoleDriver::PutString(const char *s)
{
    stringIO->P();

    for (int i = 0; s+1 != NULL; i++){
        PutChar(*(s+i));
    }

    stringIO->V();
}

void ConsoleDriver::GetString(char *s, int n)
{
    stringIO->P();
    for(int i = 0; i < n; i++) s[i] = GetChar();
    stringIO->V();
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