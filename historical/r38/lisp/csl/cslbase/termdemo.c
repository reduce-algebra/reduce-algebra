/* termdemo.c                       Copyright (C) 2004-2007 Codemist Ltd */


/*
 * This code is a very simple test and demonstration of the "termed.c"
 * console-mode input local editing and history package that I have, and
 * in particular it illustrates how that code can be used stand-alone.
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



/* Signature: 35da8d00 18-Jan-2007 */

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


/*
 * Problem report:
 *
 * When I build termdemo (and hence termed) under cygwin WITHOUT mingw32
 * (and if I do that I must remember never to distribute code because of
 * license clashes) and I THEN run the resulting binary in a Cygwin X
 * terminal, I find that '\n' in the output does not perform a CR function.
 * This is as if reset_shell_mode() was not quite doing its job. I have
 * tried an explicit resetting of ONLCR after the reset_shell_mode but that
 * does not manage to improve things. Because the configuration in which this
 * one I do not want to support because the license terms on cygwin1.dll are
 * incompatible with others I wish to use, I will not worry much further
 * about this. It can be worked around by the user putting an explicit
 * "\r\n" rather than just "\n" in output strings for that platform.
 */

#include <stdio.h>
#include <stdlib.h>

#include "termed.h"

int main(int argc, char *argv[])
{
    int i;
    const char *colours = NULL;
    for (i=1; i<argc; i++)
    {   const char *a = argv[i];
        if (a[0] == '-' && a[1] == 'b') colours = &a[2];
    }
    i = term_setup(1, colours);
    printf("Hello: setup = %d\n", i);
    atexit(term_close);

    term_setprompt("IN: ");

    for (i=7; i<12; i++)
    {   char *d;
        printf("Ordinary output for line %d\n", i);
        d = term_getline();
        if (d == NULL)
        {   printf("EOF detected\n");
            break;
        }
        else
        {   printf("Input line was <");
            while (*d != 0)
            {   int ch = *d++ & 0xff;
                if (ch < 0x20) printf("^%c", ch | 0x40);
                else if (ch < 0x7f) putchar(ch);
                else printf("[%.2x]", ch);
            }
            printf(">\n");
        }
    }

    return 0;
}


/* end of termdemo.c */

