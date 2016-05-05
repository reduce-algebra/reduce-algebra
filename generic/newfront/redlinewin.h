
/* ---------------------------------------------------------------------
   $Id$
   ---------------------------------------------------------------------
   (c) 1999-2009 A. Dolzmann and T. Sturm, 1999-2014 T. Sturm
   ---------------------------------------------------------------------
   Redistribution and use in source and binary forms, with or without
   modification, are permitted provided that the following conditions
   are met:
  
      * Redistributions of source code must retain the relevant
        copyright notice, this list of conditions and the following
        disclaimer.
      * Redistributions in binary form must reproduce the above
        copyright notice, this list of conditions and the following
        disclaimer in the documentation and/or other materials provided
        with the distribution.
  
   THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
   "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
   LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
   A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
   OWNERS OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
   SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
   LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
   DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
   THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
   (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
   OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*/

/*
 * This part was extracted by Arthur Norman in May 2016 so that the
 * earlier filr redline.c was split into a version for use with native
 * Windows and a version for other (unix-like) platforms. Declarations
 * have then been split out to go in a header file so that references from
 * one source file to another can be checked a bit!
 */


#define SKIPPING_WHITESPACE 1
#define READING_PROMPT 2
#define LEARNING 3
#define FINISHED 0

extern int redfrontcolor;
extern int normalcolor;
extern int promptcolor;
extern int inputcolor;
extern int outputcolor;
extern int debugcolor;

extern int color;

extern void line_init(void);
extern void line_learn_completion(char *);
extern strl line_learn_until_prompt(char *,const char *);
extern char *line_read(char *);
extern char *line_quit(const char *);
extern char *line_color_prompt(char *);
extern void line_end(void);
extern void line_init_history(void);
extern void line_add_history(char *);
extern void line_end_history(void);
extern char *line_histname(void);
extern char *line_switch_completion_function(const char *, int);
extern char *line_pack_completion_function(const char *, int);
extern char *line_load_completion_function(const char *, int);
extern char *line_strl_completion_function(const char *, int, strl);

/* end of redlinewin.h */
