// allocate_test.cpp                       Copyright (C) 1989-2018 Codemist    

//
// Code for testing storage allocation
//

/**************************************************************************
 * Copyright (C) 2018, Codemist.                         A C Norman       *
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

// $Id$

// The code in allocate.cpp involves an experimental change in how storage
// management is done in CSL. The code here is a TEMPORARY framework of
// test code to activate and exercise it. When (and if) everything stablizes
// the new code will be used by the main system and this file will be
// removed. I will have stubs here for all sorts of bits of CSL that are
// referenced from allocate.cpp - only s few of them will be truly relevant
// for the testing.


#include "headers.h"

void *allocate_segment(size_t);
void get_page_size();
extern size_t page_size;

void global_longjmp()
{   abort();
}

void term_printf(const char *fm, ...)
{   abort();
}

LispObject **get_stack_addr()
{   return NULL;
}

jmp_buf **get_global_jb_addr()
{   return NULL;
}

const volatile char *errorset_msg;

intptr_t miscflags;


void garbage_collect()
{
}

void my_abort()
{   abort();
}

int main(int argc, char *argv[])
{
    printf("Allocate test code\n");
    get_page_size();
    printf("page_size = %x\n", (int)page_size);
    LispObject *m = (LispObject *)allocate_segment(32*1024*1024);
    printf("segment at %p\n", m);
    return 0;
}



// end of allocate_test.cpp
