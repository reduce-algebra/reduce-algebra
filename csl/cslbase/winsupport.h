// winsupport.h                                 Copyright (C) 2021 Codemist

// $Id: winsupport.h 5728 2021-03-13 14:54:03Z arthurcnorman $


/**************************************************************************
 * Copyright (C) 2021, Codemist.                         A C Norman       *
 *                                                                        *
 * Redistribution and use in source and binary forms, with or without     *
 * modification, are permitted provided that the following conditions are *
 * met:                                                                   *
 *                                                                        *
 *     * Redistributions of source code must retain the relevant          *
 *       copyright notice, this list of conditions and the following      *
 *       disclaimer.                                                      *
 *     * Redistributions in binary form must reproduce the above          *
 *       copyright notice, this list of conditions and the following      *
 *       disclaimer in the documentation and/or other materials provided  *
 *       with the distribution.                                           *
 *                                                                        *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS    *
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT      *
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS      *
 * FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE         *
 * COPYRIGHT OWNERS OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,   *
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,   *
 * BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS  *
 * OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND *
 * ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR  *
 * TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF     *
 * THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH   *
 * DAMAGE.                                                                *
 *************************************************************************/

#ifndef __header_winsupport_h
#define __header_winsupport_h 1


extern uintptr_t *C_stackbase;
extern const char *fullProgramName;
extern const char *programName;
extern bool programNameDotCom;
extern const char *programDir;

#ifdef WIN32

// Various definitions in <windows.h> clash with other things I use in CSL
// and so I am putting all code that references such Windows specific stuff
// in a separate file, winsupport.cpp. This file declares the entrypoints
// that it provides.

// The aim here is to avoid use of the Microsoft versions of printf and
// friends and (hence) allow g++ to parse and check format strings reliably.
#define __USE_MINGW_ANSI_STDIO 1

#include <cstdint>
#include <cinttypes>
#include <cctype>
#include <ctime>
#include <new>

#include <windows.h>
#include <winsock.h>
#include <process.h>

extern void win32_stacklimit(uintptr_t &C_stacklimit);
extern int find_program_directory(const char *argv0);
extern size_t getMemorySize();
extern int windowsGetPid();
extern const char *WSAErrName(int i);
extern int windowsPrepareSockets();
extern HANDLE gnuplot_process;
extern HWND gnuplot_handle;
extern bool gnuplotActive;
class GnuplotClass
{
public:
    GnuplotClass()
    {   gnuplotActive = false;
    }
    ~GnuplotClass()
    {   if (gnuplotActive)
            TerminateProcess(gnuplot_process, 0);
    }
};
extern BOOL CALLBACK find_text(HWND h, LPARAM);
extern FILE *windowsFindGnuplot(const char *command, const char *direction);
extern int my_pipe_putc(int c, std::FILE *f);
extern int my_pipe_flush(std::FILE *f);
extern void my_pclose(std::FILE *stream);
extern uint64_t read_clock();
extern int windowsFindGnuplot1(char *name);
extern size_t windowsGetTempPath(size_t n, char *s);
extern bool valid_address(void *pointer);
extern int windowsFindGnuplot2(char *name);

#else
#ifdef __CYGWIN__

extern size_t windowsGetTempPath(size_t n, char *s);
extern int windowsFindGnuplot2(char *name);

#endif // __CYGWIN__
#endif // WIN32

#endif // __header_winsupport_h


// end of winsupport.h
