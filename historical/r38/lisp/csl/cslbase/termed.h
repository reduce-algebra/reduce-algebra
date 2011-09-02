/* termed.h                       Copyright (C) 2004-2007 Codemist Ltd */

/*
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



/* Signature: 0cb4a9f6 18-Jan-2007 */

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
