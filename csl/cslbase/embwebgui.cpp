// embwebgui.cpp                       Copyright (C) 2022-2025 E. Schruefer

/**************************************************************************
 * Copyright (C) 2022,                                   E. Schruefer     *
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
 
 
#include "embwebgui.h"
#include "webview.h"
#include "proc.h"
#include "stdio.h"
#include <cstring>
#include <iostream>
#include <streambuf>
#include <sstream>
#include <filesystem>
#include "headers.h"

webview::webview redGUI(true, nullptr);


void setup_web_reduce(void)
 {
  redGUI.set_title("Reduce");
  redGUI.set_size(1080, 720, WEBVIEW_HINT_NONE);
  redGUI.bind("passToReduce", passToReduce);
  redGUI.bind("loadReducePackage", loadReducePackage);
  redGUI.bind("setReduceSwitch", setReduceSwitch);
  redGUI.bind("queryReduceSwitches", queryReduceSwitches);
  redGUI.bind("redBanner", redBanner);
  redGUI.bind("openDocuBrowser", openDocuBrowser);
  redGUI.bind("passKeyCodeToReduce", passKeyCodeToReduce);
  redGUI.navigate(R"(file://)" + std::filesystem::current_path().string() + "/embwebgui.html");
  redGUI.run();
  }
  
  
int PROC_process_one_reduce_statement0();
  
  
int char_from_cin()
{   char c;
    std::cin.get(c);
    int r = (int) c;
    if (r == 0) return EOF;
    return r;
}


static int redOut_to_cout(int c)  //treatment of LF should be improved
{   std::string bs = R"(\\)";
    switch(c) {
        case 10 : std::cout << char(32); break;
        case 92 : std::cout << bs; break;
        default : std::cout << char(c); break;
    }
    return 0;
}
 
std::string execRedCmdStrng(std::string c)
{   std::string res;
    std::stringstream redOutBuf;
    std::streambuf* oldOutBuf;
    std::streambuf* oldInpBuf;
       
    std::istringstream redInpBuf(c);
             
    oldInpBuf = std::cin.rdbuf(redInpBuf.rdbuf());
    oldOutBuf = std::cout.rdbuf(redOutBuf.rdbuf());
       
    PROC_process_one_reduce_statement0();
       
    res = redOutBuf.str();
       
    std::cin.rdbuf(oldInpBuf);
    std::cout.rdbuf(oldOutBuf);

    return res;
}

std::string passToReduce(std::string arguments)
{   std::string c, res;
    c = webview::json_parse(arguments, "", 0);
std::cerr << "passed string: " << c << '\n';
    res = execRedCmdStrng(c.data());
std::cerr << "returned string: " << res << '\n';
    return res;
}

int PROC_process_one_reduce_statement0()
{   LispObject w = nil, w1 = nil;
    volatile uintptr_t sp;
    character_reader *save_read = procedural_input;
    character_writer *save_write = procedural_output;
//    THREADID;
    procedural_input = char_from_cin;
    procedural_output = redOut_to_cout;
    C_stackBase = reinterpret_cast<uintptr_t>(&sp);
    // We need to 'quote' the result string to prevent JS to evaluate it.
    std::cout << '"';
    if_error(w1 = make_undefined_symbol("process-one-reduce-statement");
             w = Lapply0(nil, w1),
             // Error handler
             std::cout << '"';
             procedural_input = save_read;
             procedural_output = save_write;
             return 1);  // Failed one way or another
    std::cout << '"';
    procedural_input = save_read;
    procedural_output = save_write;
    return w != nil;
}

std::string loadReducePackage(std::string arguments)
{   std::string c;
    c = webview::json_parse(arguments, "", 0);
    PROC_load_package(c.data());

    return {};
}

std::string setReduceSwitch(std::string arguments)
{   std::string c; std::string v;
    int flg;
//    execRedCmdStrng("load embwebgui$");
//    execRedCmdStrng("on readlatextoken$");
    queryReduceSwitches({});

    c = webview::json_parse(arguments, "", 0);

    v = webview::json_parse(arguments, "", 1);

    flg = (v  == "true") ? 1 : 0;
    PROC_set_switch(c.data(), flg);

    return {};
}


std::string queryReduceSwitches(std::string arguments)
{   
    std::string cmd =
    "lisp sort(for each s in oblist() join "
    "if flagp(s, 'switch) then {{s, flagp(s,'switchdefault)}}, 'ordpcar);";

    std::string res = execRedCmdStrng(cmd);
std::cerr << res << '\n';
      return res;
}

std::string redBanner(std::string arguments)
{   std::string c;
    c = webview::json_parse(arguments, "", 0);
    std::cout << c << '\n';
 
    return {};
}

std::string openDocuBrowser(std::string arguments)
{   system("xdg-open file:///home/eschruefer/Reduce-Algebra-Webview-birkhoff/trunk/doc/manual/index.html");
    return {};
}

std::string passKeyCodeToReduce(std::string arguments)
{   std::string c;
    c = webview::json_parse(arguments, "", 0);
    std::cerr << c << '\n';
    return c;
}
    
LispObject Lexec_JS_in_webv(LispObject env, LispObject s)
   {Header h;
    if (!is_vector(s) || !is_string_header(h = vechdr(s)))
        return aerror1("exec_JS_in_webv", s);
     size_t len = length_of_byteheader(h) - CELL;
     char webviewJSstring[len + 1];
     std::memcpy(webviewJSstring,
                 reinterpret_cast<char *>(s) + (CELL-TAG_VECTOR),
                 (size_t)len);
     webviewJSstring[len] = 0;
     redGUI.eval(webviewJSstring);
     return onevalue(nil);
    }
    
LispObject queryval(const char *var)
{   LispObject s;
    volatile uintptr_t sp;
    C_stackBase = reinterpret_cast<uintptr_t>(&sp);
    s = make_undefined_symbol(var);
    return onevalue(qvalue(s));
}
//LispObject LbrowserDialog(LispObject env, LispObject s

//LispObject LbrowserMsg

      
// end of embwebgui.cpp


