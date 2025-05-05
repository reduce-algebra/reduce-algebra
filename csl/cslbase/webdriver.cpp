// webdriver.cpp                          Copyright 2022-2025  E. Schruefer

/**************************************************************************
 * Copyright (C) 2025, Codemist.                         E. Schruefer     *
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

#include <cstdio>
#include <cstring>
#include <cstdint>
#include <cstdlib>
#include <stdexcept>

#include "proc.h"
#include "webview.h"
#include "embwebgui.h"

#include <iostream>
#include <filesystem>

static char obuff[10000];
static int obufp = 0;

static int iput(int c)
{   if (obufp < sizeof(obuff)-1)
    {   obuff[obufp++] = c;
        obuff[obufp] = 0;
    }
    return 0;
}

extern const char *programDir;

int buff_ready = 0;
const char *buffer = nullptr;
int buff_size = 0;


void insert_buffer(const char *buf, int size)
{   buffer = buf;
    buff_size = size;
    buff_ready = 1;
}


static int submain(int argc, const char *argv[])
{   char imageName[256];
    const char *nargv[5];
    volatile uintptr_t sp;
//    THREADID;
//    genuineThreadId = 0; // the thread_local master variable.
    std::sprintf(imageName, "%s/reduce.img", programDir);
    nargv[0] = argv[0];
    nargv[1] = "-i";
    nargv[2] = imageName;
    nargv[3] = "-v";
    nargv[4] = nullptr;
    obufp = 0;
    cslstart(4, nargv, iput);

    cslstart(argc, argv, nullptr);

// Set up Reduce
    PROC_prepare_for_web_top_level();

    setup_embweb_reduce();

    return 0;

}


int main(int argc, const char *argv[])
{   int res;
//    initThreadLocals();
    if ((res = find_program_directory(argv[0])) != 0)
    {   std::fprintf(stderr,
                     "Unable to identify program name and directory (%d)\n", res);
        return 1;
    }


//    std::strcpy(about_box_title, "About CSL");
//    std::strcpy(about_box_description, "Codemist Standard Lisp");
    try
    {   res = submain(argc, argv);
    }
    catch (std::runtime_error &e)
    {
// Here is where the EXIT exception is caught when somebody in the main
// thread obeys my_exit(). It is intended to be a fatal situation, and so if
// the "catch" here is ineffective and the application terminated not much is
// lost!
        res = EXIT_FAILURE;
    }
//    report_dependencies();

 //   ensure_screen();
    return res;
}

void setup_embweb_reduce(void) {
  webview::webview w(true, nullptr);
  w.set_title("Reduce");
  w.set_size(480, 320, WEBVIEW_HINT_NONE);
  w.bind("sendToReduce", sendToReduce);
  w.navigate(R"(file://)" +
             std::filesystem::current_path().string() +
             "/embwebgui.html");
  w.run();
  }
  
std::string sendToReduce(std::string arguments)
      {std::string c;
       c = webview::json_parse(arguments, "", 0);
       std::cout << c << '\n'; 
/*     insert_buffer(c.data(), 10); */
       buffer = c.data();
       buff_ready = 1;
       return {}; }

// end of webdriver.cpp

