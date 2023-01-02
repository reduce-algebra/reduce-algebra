// termdemo.cpp                            Copyright (C) 2004-2023 Codemist

// This code is a very simple test and demonstration of the "termed.cpp"
// console-mode input local editing and history package that I have, and
// in particular it illustrates how that code can be used stand-alone.


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
// To the extent that (a) it is convenient and (b) that I have completed
// development of this code, the behaviour of the Windowed interface in
// FXTerminal.cpp and of the console mode one in termed.c are compatible.
// The key-bindings are intended to be "emacs-like" so they support command
// to move backwards and forwards by characters and words, to delete
// characters or words, to adjust case and to scan up and down through a
// history. More elaborate variants on this idea would permit the user to
// re-assign key-bindings. I have not implemented that at all. Partly to
// try to keep my code simple and partly because I feel customised key-
// bindings are a source of terrible confusion.
//
// Because of my intended use for this code I have allocated some keys to
// menu shortcuts that will not be relevant to other people but that are
// useful to me. Not all keys can and not all keys do work under both
// FXTerminal and termed environments. I annotate this key-list with a
// ($) for things not active under FXTerminal and with (!) for not active
// or incomplete under termed.
//
//
//
//                         KEYBOARD HANDLING
//
//
// Key-bindings that I hope to make work in both terminal and windowed mode,
// on both Unix/Linux, Microsoft Windows and the Macintosh.
//
// Note that ALT can be achieved either by holding the ALT key at the
// same time as the listed key, or by pressing ESC before the key.
//
// ALT takes priority over SHIFT, and Control takes priority over ALT so
// that a character is only treated as having one attribute. If it has none
// it just inserts itself.
//
// Where I put a "-" in this table it means that I do not define the meaning
// of the keystroke. In the short term at least that will either cause the
// keystroke to be ignored, inserted, or treated the same way as the
// corresponding character without Control or ALT. In the longer term I may
// assign behaviours to some of those keys. I also want to reserve the
// possibility of making keys with both Control and ALT have yet different
// effects.
// I will put a comment line in here where I feel I am in a world of
// particular conflict, and will try to explain.
//
//Key   Control              ALT
//
// @    Set Mark ($!)        -                    (note this key is not
//                                                 always detected!)
//++ The input ^@ would have code U+0000 and at least on some platforms I
//++ do not seem to receive it reliably. For emacs users it may be expected
//++ to be "set mark" but at present because I can not make it work everywhere
//++ I will just not allocate it to any action.
// A    To beginning         -                    (also Home key)
// B    Back char            Back word            (also left arrow key)
// C    ^C interrupt         Capitalise word
//++ I choose to make ^C send an interrupt (as best I can, which is not in
//++ fact always very well) while in Windowed usage one might expect ^C to be
//++ for COPY (as in cut/copy/paste). This feels like a conflict of cultures
//++ where I just need to make a choice. The idea of making usage configurable
//++ by the users seems to me to be a path towards madness.
// D    Delete forward       Delete word          (also the Delete key)
//      Also ^D before any other input on a line sends EOF
//++ Observe the attempt to follow the tradition that U+0004 = EOT.
// E    To end               [Edit menu] (!)      (also End key)
//++ ALT-E opens an edit menu if you have a GUI.
// F    Forward char         Foward word          (also right arrow key)
//++ ALT-F might be expected to open a file menu, but I will not provide
//++ that keyboard shortcut.
// G    ^G interrupt/cancel input (!)     -       <<also escape search mode>>
//++ ^G is in some sense a relative of ^C.
// H    Delete back          Del word back
// I    complete             [File menu] (!)      (also TAB key)
//++ In the current implementation ^I just inserts a tab. As I change that
//++ to support bash/readline/libedit motivated completion I will need to
//++ force people to use ^V^I if they want a genuine tab character.
// J    Newline              -
// K    Kill line            -
// L    Clear screen         Lowercase word
// M    Newline              [Module load menu] ($!)
// N    Next history         Search history next  (also down arrow key)
// O    Discard output (!?)  [Font menu] (!)
//++ I think I see redfront binding ALT-OQ to "line_help"?
// P    Previous history     Search history prev  (also up arrow key)
// Q    Resume output (!?)   -
//++ I am not quite certain about the status of ^S and ^Q for pausing
//++ output - either in terms of what I actually do at present or in terms
//++ of what I want to!
// R    Redisplay            [Break menu] (!)
//++ redfront appears to use ^R to start a backwards incremental search
//++ which if it searchs history is something I trigger with ALT-P ?
// S    Pause output (!?)    [Switch menu] (!)
// T    Transpose chars      -
// U    Undo($!)escape srch  Uppercase word
// V    Quoted insert ($!)   -
// W    Del Word back        Copy region ($!)
// X    eXtended command ($!)Obey command ($!)
// Y    Yank (=Paste) (!)    -
// Z    pause ($!)           learn completion
//++ learning completions is not yet implemented and am not even certain
//++ what it should do!
// [    =ESC: Meta prefix    -
// \    Quit                 -
// ]    -                    -
// _    -                    Copy previous word
// ^    Reinput (!)          -
//
//
// Arrow etc keys...
//
// ->   forward char/word
// <-   backwards char/word
// ^    history prev/search history prev
// v    history next/search history next
// home start line/start buffer
// end  end line/end buffer
//
//
// The items shown as menus behave as follows:
//
// ALT-E C cut          (all !)
//       O copy
//       P paste
//       R reinput
//       A select all
//       L clear
//       D redraw
//       H home
//       E end
// ALT-I R read         (all !)
//       S save
//       L save selected text
//       P print
//       N print selected text
//       X exit
// ALT-M   &Module menu shortcut - load a module  ($! not used here)
// ALT-O F select new font    (all !)
//       R reset to default font
//       W reset font and window to default
// Alt-R C as ^C, interrupt current computation   (all !)
//       D as ^O, discard pending output
//       G as ^G, interrupt & backtrace current computation
//       P as ^S, pause output
//       R as ^Q, resume output
//       X as ^X, stop current computation
// ALT-S   &Switch menu shortcut - flip a switch ($! not used here)
//
//


//
// Problem report:
//
// When I build termdemo (and hence termed) under cygwin WITHOUT mingw32
// and I THEN run the resulting binary in a Cygwin X terminal, I find
// that '\n' in the output does not perform a CR function.
// This is because I have the console set into raw mode basically all the
// time. And I have that so that I can be reading raw bytes all the time
// in my keyboard thread...
// It can be worked around by the user putting an explicit
// "\r\n" rather than just "\n" in output strings for that platform.
//

#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <unistd.h>

#include "termed.h"

const char *programDir = ".";

int main(int argc, char *argv[])
{   bool wait = 0;
    for (int i=1; i<argc; i++)
        if (std::strcmp(argv[i], "-w") == 0) wait = 1;
    if (wait)
    {   std::printf("Termdemo: PID = %d, now waiting for 15 seconds\n",
                    getpid());
        std::printf("in case you wish to attach a debugger session\n");
        std::fflush(stdout);
        sleep(15);
        std::printf("OK - now continuing... \n");
    }
    std::printf("Termdemo\n");
    std::printf("Type in 10 lines. Include a semicolon to mark a line as\n");
    std::printf("complete. It then gets stored as history for access via cursor keys.\n");
    int i;
    int oldpnumber = 0, pnumber = 1;
    const char *colours = nullptr;
    for (i=1; i<argc; i++)
    {   const char *a = argv[i];
        if (a[0] == '-' && a[1] == 'b') colours = &a[2];
    }
    TermSetup ts(argv[0], colours);

// On at least some non-Windows platforms console output will be in RAW mode
// where '\n' is interpreted as line feed and causes the cursor to move
// vertically down. On those platforms to active "newline" and extra carriage
// return is needed. I probably need to sort things out so that the magic mode
// for stdout is only applied when performing explicit curso movement steps.

#ifdef WIN32
#define EOL "\n"
#else
#define EOL "\r\n"
#endif

// This reads and echoes 10 lines or until EOF.
    for (i=0; i<10; i++)
    {   char *d;
        char prompt[16];
// The prompt number starts at 1 and increases if there is a ";" on the
// input line. I only reset it if it has changed, so if you enter several
// lines without semicolons then they all get the same prompt.
        if (pnumber != oldpnumber)
        {   std::snprintf(prompt, 16, "IN%d: ", pnumber);
            term_setprompt(prompt);
            oldpnumber = pnumber;
        }
        d = term_getline();
        if (d == nullptr)
        {   std::printf("EOF detected" EOL);
            break;
        }
        else
        {   if (std::strchr(d, ';') != nullptr) pnumber++;
            std::printf("Input line was <");
            while (*d != 0)
            {   int ch = *d++ & 0xff;
// In the echo of the input line I make unprintable characters visible. This
// is liable to mean that end-of-line shows up as "^J".
                if (ch < 0x20) std::printf("^%c", ch | 0x40);
                else if (ch < 0x7f) std::putchar(ch);
                else std::printf("[%.2x]", ch);
            }
            std::printf(">" EOL);
        }
    }
    std::printf("End of demonstration" EOL);
    std::fflush(stdout);
    return 0;
}

// end of termdemo.cpp
