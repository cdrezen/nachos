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
    stringIO = new Semaphore("string operation", 1);//VII au cas où plusieurs thread veuillent lire ou ecrire en meme temps

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
    stringIO->P();
    int i = 0;
    for (i = 0; *(s+i) != NULL; i++){
        PutChar(*(s+i));
    }
    stringIO->V();
}

void ConsoleDriver::GetString(char *s, int n)
{
    stringIO->P();

    for(int i = 0; i < n; i++)
    {
        s[i] = GetChar();
        if (s[i] == '\n' || s[i] == '\0') { break; }//nouvelle ligne ou fin de string ?
    }

    stringIO->V();
}

unsigned ConsoleDriver::copyStringFromMachine(int from, char *to, unsigned size){
    int p;
    unsigned int i;
    for(i = 0; i < size && machine->ReadMem(from+i, 1, &p); i++){
        //On caste car ReadMem demande en argument un int et to un char
            to[i] = (char)p; 
            if(to[i] == '\0'){
                break;
            }
        }
        to[i] = '\0';
        return true;
    }


#endif // CHANGED