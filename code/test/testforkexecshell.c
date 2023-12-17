//un petit shell, il faut préciser le chemin du programme à lancer. Il faut parfois appuyer de nouveau sur entrer quand on lance un programme à plusieurs thread

#include "syscall.h"

int
main ()
{
    // SpaceId newProc;
    // OpenFileId input = ConsoleInput;
    // OpenFileId output = ConsoleOutput;
    char prompt[2], buffer[60];
    int i;

    prompt[0] = '$';
    prompt[1] = ' ';

    while (1)
      {
          //Write (prompt, 2, output);
          PutString(prompt);

          i = 0;

          do
            {

                //Read (&buffer[i], 1, input);
                buffer[i] = GetChar();

            }
          while (buffer[i++] != '\n');

          buffer[--i] = '\0';

          if (i > 0)
            {
                //newProc = Exec (buffer);
                //Join (newProc);
                ForkExec(buffer);
            }
      }
}
