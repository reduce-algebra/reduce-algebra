/******************************************************************************
*
* File:         $PXK/OS-HOOKS.C
* Description:  OS specific startup and cleanup hooks.
* Author:       RAM, HP/FSD
* Created:      9-Mar-84
* Modified:    15-Jul-85 10:10:51 (RAM)
* Mode:         Text
* Package:
* Status:       Open Source: BSD License
*
*  (c) Copyright 1983, Hewlett-Packard Company, see the file
*             HP_disclaimer at the root of the PSL file tree
*
* Redistribution and use in source and binary forms, with or without
* modification, are permitted provided that the following conditions are met:
*
*    * Redistributions of source code must retain the relevant copyright
*      notice, this list of conditions and the following disclaimer.
*    * Redistributions in binary form must reproduce the above copyright
*      notice, this list of conditions and the following disclaimer in the
*      documentation and/or other materials provided with the distribution.
*
* THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
* AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
* THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
* PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNERS OR
* CONTRIBUTORS
* BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
* CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
* SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
* INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
* CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
* ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
* POSSIBILITY OF SUCH DAMAGE.
*
******************************************************************************
* Revisions:
*
* 23-Feb-89 (Chris Burdorf)
*  Made  call to psl_main in main call copy_argv to pass the static
*  copy of argv to get around unexec problems.
* 15-Jun-88, (Tsuyoshi Yamamoto)
*  Added init-malloc-param(), _iob[] initializer, _dtabsize for SUN4 PORT.
* 21-Sep-86 (Leigh Stoller)
*  Removed calls to the io-map functions. None of this was needed for the Sun.
*  Removed the 68020_advise function.
* 07-Jul-86 (Leigh Stoller)
*  Removed Calls to echooff and echoon since they are not needed for the top
*   loop, only for Nmode. Who knows why HP used them in the first place.
* 30-Apr-86 (Leigh Stoller)
* Copied this file from gator kernel directory and changed calls to terminal-
*  state to echooff and echoon, which are contained in echo.c
*
******************************************************************************
*/
#include <stdio.h>
#include <string.h>
#include <setjmp.h>
#include <stdlib.h>

#ifdef USE_CRLIBM
#include "crlibm.h"
#endif

#include <signal.h>
#include <windows.h>
#include <excpt.h>
#include <float.h>
#include <fenv.h>

jmp_buf mainenv;
char * abs_execfilepath;
 
int Debug = 0;
char * cygdrive_prefix = NULL;

extern void * saved_pxcptinfoptrs;

extern void gcleanup ();

void init_fp();

void clear_iob();
void clear_dtabsize();
void psl_main(int,char **);
char ** copy_argv(int argc,char * argv[]);
void os_startup_hook(int,char **);
int setupbpsandheap(int, char **);

// Install a global Vectored exception handler for exceptions in Lisp code
// to call the standard handler _gnu_exception_handler after saving the pointer
// to the exception info area, for use in trap.sl

long CALLBACK _gnu_exception_handler (EXCEPTION_POINTERS * exception_data);

LONG WINAPI
GlobalVectoredHandler1(
    struct _EXCEPTION_POINTERS *ExceptionInfo
    )
{
//    PCONTEXT Context;
//    PEXCEPTION_RECORD eRecord;
//    
//    eRecord = ExceptionInfo->ExceptionRecord;
//    Context = ExceptionInfo->ContextRecord;

    saved_pxcptinfoptrs = (void *)ExceptionInfo;

//
//  Stack overflow is not handled by _gnu_exception_handler,
//  therefore call the SIGSEGV handler by hand.
//
    if (ExceptionInfo->ExceptionRecord->ExceptionCode == STATUS_STACK_OVERFLOW) {
	void (*old_handler) (int);

//	fputs("Stack overflow",stderr);
//	fflush(stderr);

	old_handler = signal (SIGSEGV, SIG_DFL);
	(*old_handler) (SIGSEGV);
	return EXCEPTION_CONTINUE_EXECUTION;
    }

    return _gnu_exception_handler(ExceptionInfo);
}


void
main(argc,argv)
int argc;
char *argv[];
{
  int val;
 
  clear_iob();             /* clear garbage pointer in _iob[]    */
  clear_dtabsize();
  /* fpsetround(FP_RZ);  */

#ifdef USE_CRLIBM
  crlibm_init();
#endif
/*  init_malloc_param();        /* reset malloc parameters.        */
  setvbuf(stdout,NULL,_IONBF,BUFSIZ);
  if (argc > 0)
    abs_execfilepath = _fullpath(NULL,argv[0],_MAX_PATH);

  cygdrive_prefix = getenv("BPSL_CYGDRIVE_PREFIX");
  if (getenv("BPSL_DEBUG") != NULL) 
     Debug = 1;
 
  val=setjmp(mainenv);        /* set non-local return point for exit    */
 
  if (val == 0) {
    /*    init_fp();*/
    AddVectoredExceptionHandler(1,GlobalVectoredHandler1);
    psl_main(argc,copy_argv(argc,argv));
  }
 
  gcleanup ();
  exit(0);
}

/*
 * Initialize floating point exceptions
 * Allow hardware exception for floating point overflow, division by zero and invalid 
 */

void init_fp()
{
  unsigned int cw, cwOriginal;
  
  _clearfp();			/* always call _clearfp before setting the control word */

  /* clear OVERFLOW, ZERODIVIDE, INVALID */
  cw = ~(_EM_OVERFLOW|_EM_ZERODIVIDE|_EM_INVALID);
  cwOriginal = _controlfp(cw, _MCW_EM); //Set it.   
}


void
os_startup_hook(argc, argv)
     int argc;
     char *argv[];
{
  setupbpsandheap(argc, argv);   /* Allocate bps and heap areas. */
}

void
os_cleanup_hook()
{
longjmp(mainenv,1);
}

char * get_execfilepath ()
{
  return abs_execfilepath;
}

void
clear_iob()
{
}

char winpathbuffer[_MAX_PATH];

char *
cygpath2winpath(char * cygpath)
{
  if (Debug > 0) {
    fprintf(stderr,"input cygpath: %s\n",cygpath);
    fprintf(stderr,"prefix is %s\n",cygdrive_prefix == NULL ? "(NULL)" : cygdrive_prefix);
  }

  if (cygdrive_prefix != NULL && strlen(cygdrive_prefix) > 1 && cygpath[0] == '/' &&
      strncmp(cygpath,cygdrive_prefix,strlen(cygdrive_prefix))==0 && cygpath[strlen(cygdrive_prefix)] == '/') {

    strcpy(winpathbuffer,cygpath + strlen(cygdrive_prefix));
    if (Debug > 0) {
      fprintf(stderr,"prefix found, rest is: %s\n",winpathbuffer);
    }
    
    if (winpathbuffer[1] != 0 && winpathbuffer[2] == '/') {
      winpathbuffer[0] = winpathbuffer[1];
      winpathbuffer[1] = ':';
      return winpathbuffer;
    }
  }
  return cygpath;  
}



/*
 *    Some static area must be initialized on hot start.
 *    There may be other area to be initialized but we have no idea
 *    to know them.
 *
 *    _dtabsize ----_end
 */
 
 
extern char *end;
/*
 *     Size of dtabsize is 0x34c bytes.
 */
void
clear_dtabsize()
{
 int i;
 }

// The following attempt to install a Structured exception handler did not work,
// probably because Lisp doesn't use the stack in the same way as C/C++.
// In particular, it seems that you must not change the value of the stack pointer
// without putting corresponding info into the excpetin handler structure

#if 0

LONG exception_handler(PEXCEPTION_RECORD e, void *frame, PCONTEXT c, void *dispatch)
{
  struct _EXCEPTION_POINTERS eps = {e, c};

  _gnu_exception_handler(&eps);
}


typedef unsigned char UBYTE;

//const UBYTE UNW_FLAG_EHANDLER = 0x1;

struct UNWIND_INFO {
  UBYTE Version:3;
  UBYTE Flags:5;
  UBYTE SizeOfProlog;
  UBYTE CountOfCodes;
  UBYTE FrameRegister:4;
  UBYTE FrameOffset:4;
  ULONG ExceptionHandler;
  ULONG ExceptionData[1];
};

struct seh_data {
  struct UNWIND_INFO unwind_info;
  RUNTIME_FUNCTION func;
  UBYTE handler[32];
};

#pragma GCC diagnostic ignored "-Wreturn-local-addr"

int copy_exception_trampoline(void *dst) {
  size_t len =  &&exit-&&entry;

  if (dst != NULL) {
    unsigned char * s = (char *) &&entry;
    unsigned char * d = (char *) dst;
    size_t count = len;
    while (count-- > 0) {
      *d = *s;
      d++;
      s++;
    }
    return len;
  }

 entry:
  asm volatile 
     ("movabs %q0, %%rax\n\t"
      "rex.w jmpq *%%rax"
      :
      : "i" (&exception_handler));
 exit:
  return 0;
}

extern char __ImageBase[];
extern char __bss_start__[];

void * install_function_table(ULONG64 codebase, ULONG size)
{
  return (void *)codebase;
  /* The annoying thing about Win64 SEH is that the offsets in
   * function tables are 32-bit integers, and the exception handler
   * itself must reside between the start and end pointers, so
   * we stick everything at the beginning of the code heap and
   * generate a small trampoline that jumps to the real
   * exception handler. */
  //ULONG64 base = (ULONG64)__bss_start__;
  ULONG64 base = (ULONG64)__ImageBase;
  struct seh_data *seh_area = (struct seh_data *)codebase;
  int len = copy_exception_trampoline(&(seh_area->handler[0]));
  struct UNWIND_INFO *unwind_info = &seh_area->unwind_info;
  unwind_info->Version = 1;
  unwind_info->Flags = UNW_FLAG_EHANDLER;
  unwind_info->SizeOfProlog = 0;
  unwind_info->CountOfCodes = 0;
  unwind_info->FrameRegister = 0;
  unwind_info->FrameOffset = 0;
  unwind_info->ExceptionHandler = (DWORD)((ULONG64)&seh_area->handler[0] - base);
  //unwind_info->ExceptionHandler = (DWORD)((ULONG64) &exception_handler - base);
  unwind_info->ExceptionData[0] = 0;
  RUNTIME_FUNCTION *func = &seh_area->func;
  func->BeginAddress = (DWORD)(codebase - base);
  func->EndAddress = (DWORD) (codebase + size - base);
  func->UnwindData = (DWORD)((ULONG64)&seh_area->unwind_info - base);
  if(!RtlAddFunctionTable(func,1,base)) {
    printf("RtlAddFunctionTable() failed\n");
    return NULL;
  }
  return (void *)(codebase + sizeof(struct seh_data));
}
#endif
