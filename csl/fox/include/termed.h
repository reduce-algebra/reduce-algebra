/* termed.h                       Copyright (C) 2004-2008 Codemist Ltd */



/**************************************************************************
 * Copyright (C) 2008, Codemist Ltd.                     A C Norman       *
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


/*
 * Note that when the code associated with this file forms part of a
 * modified version of the FOX library the whole work will be subject to
 * LGPL, but this "termed" package itself viewed as a separable part
 * remains under the above terms.
 */


/* Signature: 0c84fc53 24-May-2008 */

/*
 * This supports modest line-editing and history for terminal-mode
 * use of "fwin" applications.
 */


#ifdef __cplusplus
extern "C" {
#endif



/*
 * Start up input through this package. Returns 0 if local editing
 * actually gets enabled, or a non-zero value if there is some problem.
 * The problem will probably be that your terminal is unknown! But in
 * general you need not worry about the return value here in that if
 * local-editing can not be supported the remaining things still
 * have some sort of default behaviour.
 * Give an argument of 0 if you do not even want it to try to enable
 * local editing (eg because you know input will be generated not be
 * a real user but by a program).
 * The second argument is used to indicate colour options. NULL or "-"
 * will indicate "use default". An empty string will prevent any attempt
 * to use colour. Other strings set colours as follows:
 *      ...
 */

extern int term_setup(int flag, const char *colours);

/*
 * Set the prompt string.
 */
extern void term_setprompt(const char *s);

/*
 * Read a line from the terminal, applying history and local editing
 * operations as it goes
 */
extern char *term_getline(void);

/*
 * Before returning from your code it would be a really good idea to
 * call "term_close" since that can re-set all sorts of terminal
 * characteristics. In some cases use of "atext" to ensure this will
 * make sense.
 */
extern void term_close(void);

/*
 * What follows is to do with a history mechanism... it is not
 * intended for (much) direct use by the general public, but is
 * needed by the implementation of the "termed" stuff..
 */

#define INPUT_HISTORY_SIZE 100

extern char *input_history[INPUT_HISTORY_SIZE];
extern int input_history_next, input_history_current;

extern void input_history_init(void);

extern void input_history_end(void);

extern void input_history_add(const char *s);

extern const char *input_history_get(int n);

#ifdef __cplusplus
}
#endif


/* end of file termed.h */
