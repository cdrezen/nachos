#ifdef CHANGED
#include "copyright.h"
#include "system.h"
#include "consoledriver.h"
#include "translate.h"




static Semaphore *readAvail;
static Semaphore *writeDone;
//static Semaphore *stringIO;
//static Semaphore *charIO;
static Lock* stringIO;
static Lock* charIO;

static void ReadAvailHandler(void *arg) { (void) arg; readAvail->V(); }
static void WriteDoneHandler(void *arg) { (void) arg; writeDone->V(); }

ConsoleDriver::ConsoleDriver(const char *in, const char *out)
{
    readAvail = new Semaphore("read avail", 0);
    writeDone = new Semaphore("write done", 0);
    
    //stringIO = new Semaphore("string operation", 1);//VII au cas où plusieurs thread veuillent lire ou ecrire en meme temps (une fourchette pour tout le monde.)
    //charIO = new Semaphore("read/write char operation", 1);
    stringIO = new Lock("string operation");
    charIO = new Lock("read/write char operation");

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
    charIO->Acquire();//P();

    console->TX (ch);        // echo it!
    writeDone->P ();        // wait for write to finish
    
    charIO->Release();//V();
}

char ConsoleDriver::GetChar()
{
    charIO->Acquire();//P();

    readAvail->P ();        // wait for character to arrive
    char ch = console->RX();

    charIO->Release();//V();
    return ch;
}

void ConsoleDriver::PutString(const char *s)
{
    stringIO->Acquire();//P();
    int i = 0;
    for (i = 0; *(s+i) != NULL; i++){//on fait PutChar tant que s[i] n'est pas la terminaison de string
        PutChar(*(s+i));
    }
    stringIO->Release();//V();
}

void ConsoleDriver::GetString(char *s, int n)
{
    stringIO->Acquire();//P();//fourchette en cours d'utilisation

    for(int i = 0; i < n; i++)
    {
        s[i] = GetChar();
        if (s[i] == '\n' || s[i] == '\0') { break; }//nouvelle ligne ou fin de string ?
    }

    stringIO->Release();//V();//fourchette disponible
}



#endif // CHANGED