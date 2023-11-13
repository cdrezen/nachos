// exception.cc
//      Entry point into the Nachos kernel from user programs.
//      There are two kinds of things that can cause control to
//      transfer back to here from user code:
//
//      syscall -- The user code explicitly requests to call a procedure
//      in the Nachos kernel.  Right now, the only function we support is
//      "Halt".
//
//      exceptions -- The user code does something that the CPU can't handle.
//      For instance, accessing memory that doesn't exist, arithmetic errors,
//      etc.
//
//      Interrupts (which can also cause control to transfer from user
//      code into the Nachos kernel) are handled elsewhere.
//
// For now, this only handles the Halt() system call.
// Everything else core dumps.
//
// Copyright (c) 1992-1993 The Regents of the University of California.
// All rights reserved.  See copyright.h for copyright notice and limitation
// of liability and disclaimer of warranty provisions.

#include "copyright.h"
#include "system.h"
#include "syscall.h"
//TD2.I.4
#include "userthread.h"

//----------------------------------------------------------------------
// UpdatePC : Increments the Program Counter register in order to resume
// the user program immediately after the "syscall" instruction.
//----------------------------------------------------------------------
static void
UpdatePC()
{
  int pc = machine->ReadRegister(PCReg);
  machine->WriteRegister(PrevPCReg, pc);
  pc = machine->ReadRegister(NextPCReg);
  machine->WriteRegister(PCReg, pc);
  pc += 4;
  machine->WriteRegister(NextPCReg, pc);
}

//----------------------------------------------------------------------
// ExceptionHandler
//      Entry point into the Nachos kernel.  Called when a user program
//      is executing, and either does a syscall, or generates an addressing
//      or arithmetic exception.
//
//      For system calls, the following is the calling convention:
//
//      system call code -- r2
//              arg1 -- r4
//              arg2 -- r5
//              arg3 -- r6
//              arg4 -- r7
//
//      The result of the system call, if any, must be put back into r2.
//
// And don't forget to increment the pc before returning. (Or else you'll
// loop making the same system call forever!
//
//      "which" is the kind of exception.  The list of possible exceptions
//      are in machine.h.
//----------------------------------------------------------------------

void ExceptionHandler(ExceptionType which)
{
  int type = machine->ReadRegister(2);
  int address = machine->ReadRegister(BadVAddrReg);

  switch (which)
  {
  case SyscallException:
  {
    switch (type)
    {
    case SC_Halt:
    {
      DEBUG('s', "Shutdown, initiated by user program.\n");
      interrupt->Powerdown();
      break;
    }

    //TD1:
    #pragma region TD1

    case SC_Exit: // partie VI
    {
      //char str[51];
      int exit = machine->ReadRegister(2); // r2: exit code r0 + 1
      int res = machine->ReadRegister(4);  // r4 : r2 du programme precedant copié dans r4 (voir start.S)
      
      //snprintf(str, 51, "programme termine, code=%d val retour=%d.\n", exit, res);
      //consoledriver->PutString(str);
      DEBUG('p', "programme termine, code=%d val retour=%d.\n", exit, res);
      
      interrupt->Powerdown(); // a modifier si on voulais faire autre chose ensuite comme executer un autre programme
      break;
    }
    case SC_PutChar:
    {
      DEBUG('s', "PutChar\n");
      consoledriver->PutChar(machine->ReadRegister(4)); // on recupere le char de r4 (1er argument) et on l'ecrit dans la console
      break;
    }
    case SC_GetChar:
    {
      machine->WriteRegister(2, consoledriver->GetChar()); // on recupere un char un on le met dans r2 (val de retour)
      break;
    }
    case SC_PutString:
    {

      // Initialisation des paramètres de copyStringFromMachine
      int from = machine->ReadRegister(4);
      int size = MAX_STRING_SIZE;
      char *to = new char[size];
      machine->copyStringFromMachine(from, to, size);
      consoledriver->PutString(to);

      delete[] to;
      break;
    }
    case SC_GetString:
    {
      DEBUG('s', "GetString\n");
      int to = machine->ReadRegister(4);   // arg0
      int size = machine->ReadRegister(5); // arg1

      DEBUG('s', "sz=%d\n", size);

      if (size > MAX_STRING_SIZE) // pas de dépacements de la taille autorisée
        size = MAX_STRING_SIZE;

      char *buf = new char[size];

      consoledriver->GetString(buf, size);

      /*/facon de recuperer la nouvelle taille sans modif la signature de consoledriver->GetString
      int i = 0;
      for(i; i < size && buf[i] != '\0'; i++);
      size = i;
      /*/

      machine->copyStringToMachine(to, buf, size); // on copie les char dans le buffer donne par l'utilisateur

      delete[] buf;

      break;
    }
    case SC_PutInt:
    {
      DEBUG('s', "PutInt\n");
      int val = machine->ReadRegister(4);
      char buf[12]; // 11: taille max d'un int signé représenté dans un string + 1 pour la terminsaison
      int size = snprintf(buf, 12, "%d", val);
      if (!size)
        break;

      DEBUG('s', "sz=%d", size);

      if (size > 11)
        buf[11] = NULL; // si 11 numeros serait lus
      else
        buf[size] = NULL;
      consoledriver->PutString(buf);

      break;
    }
    case SC_GetInt:
    {
      DEBUG('s', "GetInt\n");
      int ptr = machine->ReadRegister(4);
      int res = 0;

      char buf[12]; // 11: taille max d'un int signé (incluant le char '-' ) représenté dans un string +1 terminaison
      consoledriver->GetString(buf, 11);

      if (buf[0] != '-')
        buf[10] = NULL; // on ignore le dernier char si c'est un entier positif sinon ça ne rentre pas dans un int
      if (!sscanf(buf, "%d", &res))
        break;

      machine->WriteMem(ptr, sizeof(int), res); // on copie le int dans le int donne par l'utilisateur
      break;
    }
    #pragma endregion TD1
    
    //TD2:
    case SC_ThreadCreate:
    {
      int f = machine->ReadRegister(4);   // arg0
      int arg = machine->ReadRegister(5); // arg1

      DEBUG('t', "ThreadCreate f=%d, arg=%d.\n", f, arg);

      do_ThreadCreate(f, arg);

      break;
    }
    case SC_ThreadExit:
    {
      do_ThreadExit();
      break;
    }
    case SC_P:
    {
      int id = machine->ReadRegister(4); 
      int init = machine->ReadRegister(5);
      machine->WriteRegister(2, usync->P(id, init));
      break;
    }
    case SC_V:
    {
      int id = machine->ReadRegister(4); 
      usync->V(id);
      break;
    }

    default:
    {
      ASSERT_MSG(FALSE, "Unimplemented system call %d\n", type);
    }
    }

    // Do not forget to increment the pc before returning!
    // This skips over the syscall instruction, to continue execution
    // with the rest of the program
    UpdatePC();
    break;
  }

  case PageFaultException:
    if (!address)
    {
      ASSERT_MSG(FALSE, "NULL dereference at PC %x!\n", machine->registers[PCReg]);
    }
    else
    {
      // For now
      ASSERT_MSG(FALSE, "Page Fault at address %x at PC %x\n", address, machine->registers[PCReg]);
    }
    break;

  case ReadOnlyException:
    // For now
    ASSERT_MSG(FALSE, "Read-Only at address %x at PC %x\n", address, machine->registers[PCReg]);
    break;
 
  case BusErrorException:
    // For now
    ASSERT_MSG(FALSE, "Invalid physical address at address %x at PC %x\n", address, machine->registers[PCReg]);
    break;

  case AddressErrorException:
    // For now
    ASSERT_MSG(FALSE, "Invalid address %x at PC %x\n", address, machine->registers[PCReg]);
    break;

  case OverflowException:
    // For now
    ASSERT_MSG(FALSE, "Overflow at PC %x\n", machine->registers[PCReg]);
    break;

  case IllegalInstrException:
    // For now
    ASSERT_MSG(FALSE, "Illegal instruction at PC %x\n", machine->registers[PCReg]);
    break;

  default:
    ASSERT_MSG(FALSE, "Unexpected user mode exception %d %d %x at PC %x\n", which, type, address, machine->registers[PCReg]);
    break;
  }
}
