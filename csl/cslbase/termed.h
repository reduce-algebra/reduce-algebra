// termed.h                                Copyright (C) 2004-2022 Codemist


/**************************************************************************
 * Copyright (C) 2022, Codemist.                         A C Norman       *
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

#ifndef header_termed_h
#define header_termed_h 1

//
// Note that when the code associated with this file forms part of a
// modified version of the FOX library the whole work will be subject to
// LGPL, but this "termed" package itself viewed as a separable part
// remains under the above terms.
//


// $Id$

#include <cstdlib>

//
// This supports modest line-editing and history for terminal-mode
// use of "fwin" applications.
//

//
// Start up input through this package. Returns 0 if local editing
// actually gets enabled, or a non-zero value if there is some problem.
// The problem will probably be that your terminal is unknown! But in
// general you need not worry about the return value here in that if
// local-editing can not be supported the remaining things still
// have some sort of default behaviour.
// The second argument is used to indicate colour options. nullptr or "-"
// will indicate "use default". An empty string will prevent any attempt
// to use colour. Other strings set colours as follows:
//      There are three characters, which specify the colours for
//      output, input and prompt (in that order). Each character can be one
//      of
//      kw   black or white
//      rgb  red, green or blue
//      cmy  cyan, magenta or yellow
// (I think that the colour selection is not available on Windows).

extern bool termEnabled;

extern int term_setup(const char *argv0, const char *colours);

// Before returning from your code it would be a really good idea to
// call "term_close" since that can re-set all sorts of terminal
// characteristics. I use an object of class TermSetup to arrange this.
// On any normal exit the destructor is invoked, however if std::quick_exit
// is activated the at_quick_exit does the job for me.

extern void term_close(void);

class TermSetup
{
public:
    TermSetup(const char *argv0, const char *colours)
    {   termEnabled = false;
        term_setup(argv0, colours);
#ifdef HAVE_AT_QUICK_EXIT
        std::at_quick_exit(term_close);
#else // HAVE_QUICK_EXIT
#ifndef EMSCRIPTEN
        std::atexit(term_close);
#endif // EMSCRIPTEN
#endif // HAVE_AT_QUICK_EXIT
    }
    ~TermSetup()
    {   term_close();
    }
};



//
// Set the prompt string.
//
extern void term_setprompt(const char *s);
extern void term_wide_setprompt(const wchar_t *s);

//
// This sets callbacks for ^C and ^G and ALT-^C and ALT-^G input
//
typedef int (keyboard_interrupt_callback)(int);
extern keyboard_interrupt_callback *async_interrupt_callback;
extern void set_keyboard_callbacks(keyboard_interrupt_callback *f1);

#define QUERY_INTERRUPT 0
#define QUIET_INTERRUPT 1
#define NOISY_INTERRUPT 2
#define BREAK_LOOP      3
#define QUIT_PROGRAM    4

//
// Read a line from the terminal, applying history and local editing
// operations as it goes
//
extern char *term_getline(void);
extern wchar_t *term_wide_getline(void);

//
// What follows is to do with a history mechanism... it is not
// intended for (much) direct use by the general public, but is
// needed by the implementation of the "termed" stuff..
//

#define INPUT_HISTORY_SIZE 100

extern wchar_t *input_history[INPUT_HISTORY_SIZE];
extern int input_history_next;

extern void input_history_init(const char *argv0,
                               int &historyFirst, int &historyLast, int &historyNumber,
                               int &input_history_next, int &longest_history_line);

extern void input_history_end(void);

extern void input_history_add(const wchar_t *s);

extern const wchar_t *input_history_get(int n);

//
// The next few are so I can access the Unicode conversion code here
// by pretending to be in console mode even if I am not.
//

extern wchar_t *input_line;
extern int prompt_length, insert_point;

//
// Encode character c in UTF-8 and place result at b. Return the number
// of bytes written.
//
extern int utf_encode(unsigned char *b, int c);

//
// Decode UTF-8 from location b and return a code, or -1 in case of an
// invalid sequence. Set utf_bytes to the number of bytes consumed, which
// will be 1 in the case of errors.
//
extern int utf_bytes;
extern int utf_decode(const unsigned char *b);

extern void term_unicode_convert();

typedef struct _uniname
{
//
// Note that the names of special characters will never themselves include
// any special characters, so using "char *" here rather than "wchar_t *"
// is reasonable.
//
    const char *name;
    int code;
} uniname;

extern uniname unicode_names[];

//
// Surrogate pairs will only arise when wide characters are only 2 bytes
// (ie typically on Windows). These macros can be used to detect them and
// decent compiler optimisation will arrange that no code gets generated
// on systems using 32-bit values for wchar_t if these are used in tests.
//
#define is_surrogate(x)      (sizeof(wchar_t)==2 && ((x)&0xf800)==0xf800)
#define is_high_surrogate(x) (sizeof(wchar_t)==2 && ((x)&0xfc00)==0xf800)
#define is_low_surrogate(x)  (sizeof(wchar_t)==2 && ((x)&0xfc00)==0xfc00)

#endif // header_termed_h

// end of file termed.h
