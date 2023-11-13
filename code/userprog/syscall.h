/* syscalls.h
 *	Nachos system call interface.  These are Nachos kernel operations
 *	that can be invoked from user programs, by trapping to the kernel
 *	via the "syscall" instruction.
 *
 *	This file is included by user programs and by the Nachos kernel.
 *
 * Copyright (c) 1992-1993 The Regents of the University of California.
 * All rights reserved.  See copyright.h for copyright notice and limitation
 * of liability and disclaimer of warranty provisions.
 */

#ifndef SYSCALLS_H
#define SYSCALLS_H

#include "copyright.h"

#define USER_START_ADDRESS 0x80

/* system call codes -- used by the stubs to tell the kernel which system call
 * is being asked for
 */
#define SC_Halt		    0
#define SC_Exit		    1
#define SC_Exec		    2
#define SC_Join		    3
#define SC_Create	    4
#define SC_Open		    5
#define SC_Read		    6
#define SC_Write	    7
#define SC_Close	    8
#define SC_Fork		    9
#define SC_Yield	    10

//Action IV.2.
#define SC_PutChar      11
//VII
#define SC_GetChar      12

#define SC_PutString    13
#define SC_GetString    14
    
#define SC_PutInt       15
#define SC_GetInt       16

//TD2.I.3
#define SC_ThreadCreate 17
#define SC_ThreadExit   18
//TD2.IV
#define SC_P            19
#define SC_V            20

#ifdef IN_USER_MODE

// LB: This part is read only on compiling the test/*.c files.
// It is *not* read on compiling test/start.S


/* The system call interface.  These are the operations the Nachos
 * kernel needs to support, to be able to run user programs.
 *
 * Each of these is invoked by a user program by simply calling the
 * procedure; an assembly language stub stuffs the system call code
 * into a register, and traps to the kernel.  The kernel procedures
 * are then invoked in the Nachos kernel, after appropriate error checking,
 * from the system call entry point in exception.cc.
 */

/* Stop Nachos, and print out performance stats */
void Halt (void) __attribute__ ((__noreturn__));


/* Address space control operations: Exit, Exec, and Join */

/* This user program is done (status = 0 means exited normally). */
void Exit (int status) __attribute__ ((__noreturn__));

/* A unique identifier for an executing user program (address space) */
typedef int SpaceId;

/* Run the executable, stored in the Nachos file "name", and return the
 * address space identifier
 */
SpaceId Exec (const char *name);

/* Only return once the the user program "id" has finished.
 * Return the exit status.
 */
int Join (SpaceId id);


/* File system operations: Create, Open, Read, Write, Close
 * These functions are patterned after UNIX -- files represent
 * both files *and* hardware I/O devices.
 *
 * If this assignment is done before doing the file system assignment,
 * note that the Nachos file system has a stub implementation, which
 * will work for the purposes of testing out these routines.
 */

/* A unique identifier for an open Nachos file. */
typedef int OpenFileId;

/* when an address space starts up, it has two open files, representing
 * keyboard input and display output (in UNIX terms, stdin and stdout).
 * Read and Write can be used directly on these, without first opening
 * the console device.
 */

#define ConsoleInput	0
#define ConsoleOutput	1

/* Create a Nachos file, with "name" */
void Create (const char *name);

/* Open the Nachos file "name", and return an "OpenFileId" that can
 * be used to read and write to the file.
 */
OpenFileId Open (const char *name);

/* Write "size" bytes from "buffer" to the open file. */
void Write (const void *buffer, int size, OpenFileId id);

/* Read "size" bytes from the open file into "buffer".
 * Return the number of bytes actually read -- if the open file isn't
 * long enough, or if it is an I/O device, and there aren't enough
 * characters to read, return whatever is available (for I/O devices,
 * you should always wait until you can return at least one character).
 */
int Read (void *buffer, int size, OpenFileId id);

/* Close the file, we're done reading and writing to it. */
void Close (OpenFileId id);



/* User-level thread operations: Fork and Yield.  To allow multiple
 * threads to run within a user program.
 */

/* Fork a thread to run a procedure ("func") in the *same* address space
 * as the current thread.
 */
void Fork (void (*func) (void));

/* Yield the CPU to another runnable thread, whether in this address space
 * or not.
 */
void Yield (void);

//Action IV.2.
void PutChar(char c);
char GetChar();

//V & VII
void PutString(char *s);
void GetString(char *s, int n);

//VII.4
void PutInt(int i);
void GetInt(int* n);


//TD2.I.3
int ThreadCreate(void f(void *arg), void *arg);
void ThreadExit(void);

//TD2.III
/* Solution peu elegante pour forcer l'appel à ThreadExit à la fin de chaque nouveau thread utilisateur.
 * au lieu de lancer un thread avec (f, arg) on lance un thread avec (g={.f(.arg); ThreadExit()}, [f, arg])
 */

#define FORCETHREADEXIT_FULLMACRO
#ifdef FORCETHREADEXIT_FULLMACRO

typedef void (*func)(void* arg);
typedef struct 
{ 
  func f;
  void* arg;
} f_arg;

void* make_farg(func f, void* arg)
{
  f_arg farg = {f, arg};
  return &farg;//pas indefini?
}

func _F(f_arg* args) { 
  //f_arg* args = (struct f_arg*)(args_);
  args->f(args->arg);
  //free(args);...
  ThreadExit();
  return;
}

#define ThreadCreate(f, arg) ThreadCreate(_F, make_farg((func)f, (void*)arg))

/* func _F1(void** args) {
  func f = (func)args[0];
  void* arg = args[1];
  f(arg);
  ThreadExit();
  return;
}
#define ThreadCreate(f, arg) ThreadCreate(_F1, (void**){(void*)f, (void*)arg}) */

#endif // FORCE_THREADEXIT

int P(int id, int init);
void V(int id);

typedef struct
{
  int id;
} sem_t;

sem_t* make_sem_t() { sem_t s = { -1 }; return &s; }

void sem_t_init(sem_t* sem, int val) { if(!sem->id || sem->id < 0) { sem->id = P(-1, val); } else return; }

#define P(sem) P(sem->id, 0)
#define V(sem) V(sem->id)

#endif // IN_USER_MODE

#endif /* SYSCALL_H */
