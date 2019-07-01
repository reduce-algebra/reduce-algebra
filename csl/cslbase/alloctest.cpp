// alloctest.cpp                                Copyright (C) 2019 Codemist

// This is going to be so I can have a simple test harness for
// newalloc.cpp and its friends.


// $Id$


/**************************************************************************
 * Copyright (C) 2019, Codemist.                         A C Norman       *
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

#include "config.h"
#include "headers.h"

// I will need to provide definitions of a number of things that the main
// parts of CSL use, even if I will not actually make use of them here.

void fwin_report_left(const char *s)
{}

void fwin_report_right(const char *s)
{}

int window_heading;

void fwin_ensure_screen()
{
}

void ensure_screen()
{
}

volatile std::atomic<uintptr_t> event_flag;

int fwin_getchar()
{   return EOF;
}

LispObject make_undefined_symbol(const char *name)
{   return nil;
}

LispObject get_pname(LispObject a)
{   return a;
}

LispObject nil, lisp_true, unset_var;
LispObject *nilsegment, *stacksegment, *stack, *stackbase, *stacklimit;
uintptr_t *C_stackbase, C_stacklimit;

[[noreturn]] void fatal_error(int code, ...)
{   my_abort();
}
void trace_printf(const char *fmt, ...)
{
}

void global_longjmp()
{   my_abort();
}

void respond_to_stack_event()
{
}

int init_flags;
double maxStoreSize;
unsigned int exit_count;
intptr_t miscflags;

const char *programDir;
const char *programName;
const char *standard_directory;

LispObject free_vectors[LOG2_VECTOR_CHUNK_BYTES+1] = {0};

uint32_t Crand()
{   return 0;
}

bool file_exists(char*, char const*, unsigned long, char*)
{   return false;
}

const volatile char *errorset_msg;

[[noreturn]] void aerror(const char *msg)
{   my_abort();
}

[[noreturn]] void aerror1(const char *msg, LispObject a)
{   my_abort();
}

int64_t sixty_four_bits(LispObject a)
{   return 0;
}


int main(int argc, char *argv[])
{   printf("alloctest starting\n");

}

// end of alloctest.cpp
