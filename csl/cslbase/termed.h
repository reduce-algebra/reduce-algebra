// termed.h                                Copyright (C) 2004-2016 Codemist


/**************************************************************************
 * Copyright (C) 2016, Codemist.                         A C Norman       *
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


//
// Note that when the code associated with this file forms part of a
// modified version of the FOX library the whole work will be subject to
// LGPL, but this "termed" package itself viewed as a separable part
// remains under the above terms.
//


// $Id$

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
// Give an argument of 0 if you do not even want it to try to enable
// local editing (eg because you know input will be generated not be
// a real user but by a program).
// The second argument is used to indicate colour options. NULL or "-"
// will indicate "use default". An empty string will prevent any attempt
// to use colour. Other strings set colours as follows:
//      ...
//

extern "C" int term_setup(int flag, const char *colours);

//
// Set the prompt string.
//
extern "C" void term_setprompt(const char *s);
extern "C" void term_wide_setprompt(const wchar_t *s);

//
// Read a line from the terminal, applying history and local editing
// operations as it goes
//
extern "C" char *term_getline(void);
extern "C" wchar_t *term_wide_getline(void);

//
// Before returning from your code it would be a really good idea to
// call "term_close" since that can re-set all sorts of terminal
// characteristics. In some cases use of "atext" to ensure this will
// make sense.
//
extern "C" void term_close(void);

//
// What follows is to do with a history mechanism... it is not
// intended for (much) direct use by the general public, but is
// needed by the implementation of the "termed" stuff..
//

#define INPUT_HISTORY_SIZE 100

extern "C" wchar_t *input_history[INPUT_HISTORY_SIZE];
extern "C" int input_history_next;

extern "C" void input_history_init(void);

extern "C" void input_history_end(void);

extern "C" void input_history_add(const wchar_t *s);

extern "C" const wchar_t *input_history_get(int n);

//
// The next few are so I can access the Unicode conversion code here
// by pretending to be in console mode even if I am not.
//

extern "C" wchar_t *input_line;
extern "C" int prompt_length, insert_point;

//
// Encode character c in UTF-8 and place result at b. Return the number
// of bytes written.
//
extern "C" int utf_encode(unsigned char *b, int c);

//
// Decode UTF-8 from location b and return a code, or -1 in case of an
// invalid sequence. Set utf_bytes to the number of bytes consumed, which
// will be 1 in the case of errors.
//
extern "C" int utf_bytes;
extern "C" int utf_decode(const unsigned char *b);

extern "C" void term_unicode_convert();

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

extern "C" uniname unicode_names[];

//
// Surrogate pairs will only arise when wide characters are only 2 bytes
// (ie typically on Windows). These macros can be used to detect them and
// decent compiler optimisation will arrange that no code gets generated
// on systems using 32-bit values for wchar_t if these are used in tests.
//
#define is_surrogate(x)      (sizeof(wchar_t)==2 && ((x)&0xf800)==0xf800)
#define is_high_surrogate(x) (sizeof(wchar_t)==2 && ((x)&0xfc00)==0xf800)
#define is_low_surrogate(x)  (sizeof(wchar_t)==2 && ((x)&0xfc00)==0xfc00)


// end of file termed.h
