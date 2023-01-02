// babyreduce.cpp                          Copyright (C) 2016-2023 Codemist


/**************************************************************************
 * Copyright (C) 2023, Codemist.                         A C Norman       *
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

//
// This is for use via the "new-embedded" structure and it provides a
// terminal-only version of Reduce that may be as small and easy to
// set up as anything can possibly be.
//

#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cstdint>

#include "config.h"
#include "machine.h"
#include "tags.h"
#include "cslread.h"
#include "termed.h"
#include "proc.h"

static const char *line = nullptr, *linep = nullptr;

static int iget()
{   if (linep == nullptr)
    {   term_setprompt(prompt_string);
        line = linep = term_getline();
        if (line == nullptr) return EOF;
    }
    if (*linep == 0)
    {   linep = nullptr;
        return '\n';
    }
    return *linep++;
}

static int iput(int c)
{   std::putchar(c);
    std::fflush(stdout);
    return 0;
}

extern const char *programDir;

static int submain(int argc, char *argv[])
{   int rc;
    PROC_set_callbacks(iget, iput);
    cslstart(argc, argv, iput);
    execute_lisp_function("begin", iget, iput);
    rc = cslfinish(iput);
    my_exit(rc);   // does a throw
    return 0;
}

int main(int argc, char *argv[])
{   int res;
    if (find_program_directory(argv[0]))
    {   std::fprintf(stderr,
                     "Unable to identify program name and directory\n");
        return 1;
    }
    TermSetup ts(argv[0], nullptr);
    try
    {   res = submain(argc, argv);
    }
    catch (std::runtime_error &e)
    {   res = EXIT_FAILURE;
    }
    return res;
}

// End of babyreduce.cpp
