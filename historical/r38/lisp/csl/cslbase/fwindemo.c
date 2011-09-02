/* fwindemo.c                       Copyright (C) 2004-2007 Codemist Ltd */


/*
 * This code is a very simple test and demonstration of the "FXTerminal.cpp"
 * Window-mode input local editing and history package that I have, and
 * in particular it illustrates how that code can be used. Note that if the
 * executable here is launched as just
 *     fwindemo
 * it should create a window and run in it, but
 *     fwindemo -w
 * should run in console-mode.
 *
 *
 * NB that when compiling on Windows my Makefile will create TWO executables
 * for this program. One will be called fwindemo.com and will be linked
 * with "susbsystem:console", the other will be fwindemo.exe and is set
 * up as "susbsystem:windows". If you just say "fwindemo" and the directory
 * with these in is on your path then fwindemo.com gets launched. If you
 * want to double-click you should do so on fwindemo.exe. You can launch
 * fwindemo[.com] from the command line and it will still launch and
 * run in a window (unless you give it the "-w" flag). Thos who feel the
 * need to understand why I do all this can do web searches about creating
 * programs that can run in either Windowes or Console mode...
 *
 *
 * Copyright (c) 2004 A C Norman, Codemist Ltd
 * 
 * Permission is hereby granted, free of charge, to any person obtaining
 * a copy of this software and associated documentation files (the
 * "Software"), to deal in the Software without restriction, including
 * without limitation the rights to use, copy, modify, merge, publish,
 * distribute, sublicense, and/or sell copies of the Software, and to
 * permit persons to whom the Software is furnished to do so, subject
 * to the following conditions:
 * 
 * The above copyright notice and this permission notice shall be included
 * in all copies or substantial portions of the Software.
 * 
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS
 * OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL
 * THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR
 * OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE,
 * ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
 * OTHER DEALINGS IN THE SOFTWARE.
 * 
 */



/* Signature: 58846524 17-Mar-2008 */

/*
 * To the extent that (a) it is convenient and (b) that I have completed
 * development of this code, the behaviour of the Windowed interface in
 * FXTerminal.cpp and of the console mode one in termed.c are compatible.
 * The key-bindings are intended to be "emacs-like" so they support command
 * to move backwards and forwards by characters and words, to delete
 * characters or words, to adjust case and to scan up and down through a
 * history. More elaborate variants on this idea would permit the user to
 * re-assign key-bindings. I have not implemented that at all. Partly to
 * try to keep my code simple and partly because I feel customised key-
 * bindings are a source of terrible confusion.
 *
 * Because of my intended use for this code I have allocated some keys to
 * menu shortcuts that will not be relevant to other people but that are
 * useful to me. NOt all keys can and not all keys do work under both
 * FXTerminal and termed environments. I annotate this key-list with a
 * ($) for things not active under FXTerminal and with (!) for not active
 * or incomplete under termed.
 *
 *
 *
 *                         KEYBOARD HANDLING
 *
 *
 * Key-bindings that I hope to make work in both terminal and windowed mode,
 * on both Unix/Linux, Microsoft Windows and the Macintosh.
 * 
 * Note that ALT can be achieved either by holding the ALT key at the
 * same time as the listed key, or by pressing ESC before the key.
 * 
 * ALT takes priority over SHIFT, and Control takes priority over ALT so
 * that a character is only treated as having one attribute. If it has none
 * it just inserts itself.
 * 
 * Where I put a "-" in this table it means that I do not define the meaning
 * of the keystroke. In the short term at least that will either cause the
 * keystroke to be ignored, inserted, or treated the same way as the
 * corresponding character without Control or ALT. In the longer term I may
 * assign behaviours to some of those keys. I also want to reserve the
 * possibility of making keys with both Control and ALT have yet different
 * effects.
 *
 *Key   Control              ALT
 *
 * @    Set Mark ($!)        -                    (note this key is not
 *                                                 always detected!)
 * A    To beginning         -                    (also Home key)
 * B    Back char            Back word            (also left arrow key)
 * C    ^C interrupt         Capitalise word
 * D    Delete forward       Delete word          (also the Delete key)
 *      Also ^D before any other input on a line sends EOF
 * E    To end               [Edit menu] (!)      (also End key)
 * F    Forward char         Foward word          (also right arrow key)
 * G    ^G interrupt/cancel input (!)     -       <<also escape search mode>>
 *
 * H    Delete back          Del word back
 * I    TAB                  [File menu] (!)      (also TAB key)
 * J    Newline              -
 * K    Kill line            -
 * L    Clear screen         Lowercase word
 * M    Newline              [Module load menu] ($!)
 * N    Next history         Search history next  (also down arrow key)
 * O    Discard output (!?)  [Font menu] (!)
 *
 * P    Previous history     Search history prev  (also up arrow key)
 * Q    Resume output (!?)   -
 * R    Redisplay            [Break menu] (!)
 * S    Pause output (!?)    [Switch menu] (!)
 * T    Transpose chars      -
 * U    Undo($!)escape srch  Uppercase word
 * V    Quoted insert ($!)   -
 * W    Del Word back        Copy region ($!)
 *
 * X    eXtended command ($!)Obey command ($!)
 * Y    Yank (=Paste) (!)    -
 * Z    Stop execution (!?)  -
 * [    =ESC: Meta prefix    -
 * \    Quit                 -
 * ]    -                    -
 * _    -                    Copy previous word
 * ^    Reinput (!)          -
 *
 *
 * Arrow etc keys...
 *
 * ->   forward char/word
 * <-   backwards char/word
 * ^    history prev/search history prev
 * v    history next/search history next
 * home start line/start buffer
 * end  end line/end buffer
 *
 *
 * The items shown as menus behave as follows:
 *
 * ALT-E C cut          (all !)
 *       O copy
 *       P paste
 *       R reinput
 *       A select all
 *       L clear
 *       D redraw
 *       H home
 *       E end
 * ALT-I R read         (all !)
 *       S save
 *       L save selected text
 *       P print
 *       N print selected text
 *       X exit
 * ALT-M   &Module menu shortcut - load a module  ($! not used here)
 * ALT-O F select new font    (all !)
 *       R reset to default font
 *       W reset font and window to default
 * Alt-R C as ^C, interrupt current computation   (all !)
 *       D as ^O, discard pending output
 *       G as ^G, interrupt & backtrace current computation
 *       P as ^S, pause output
 *       R as ^Q, resume output
 *       X as ^X, stop current computation
 * ALT-S   &Switch menu shortcut - flip a switch ($! not used here)
 *
 */




#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include <stdio.h>
#include <string.h>

#include "fwin.h"

int fwin_main(int argc, char **argv)
{
    char line[1000];
    fwin_printf("Type lines. Type \"quit\" to exit\n");
    fwin_ensure_screen();
    for (;;)
    {   int i = 0, c;
        while ((c = fwin_getchar()) != EOF && c != '\n')
        {   if (i < sizeof(line)-10) line[i++] = c;
        }
        line[i] = 0;
        fwin_printf("Line was <%s>\n", line);
        if (c == EOF || strcmp(line, "quit") == 0) break;
    }
    fwin_printf("Done\n");
    /* fwin_exit(0); */
    return 0;
}

/*
 * The "fwin" package can be build free-standing, but if the symbol CSL
 * is defined it expects to be used with the CSL Lisp system from Codemist.
 * In that case it makes a call-back to a function as defined here. A
 * dummy version is included here in case you link with a version of fwin
 * that had been compiled with the CSL option enabled. This complication is
 * indeed an indication of bad partitioning of functionality but should not
 * have much effect on ordinary users!
 */
void review_switch_settings()
{
}

/*
 * Similarly here...
 */
char *look_in_lisp_variable(char *s, int c)
{
    return NULL;
}

/* end of fwindemo.c */



