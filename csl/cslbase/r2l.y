/*
 * This is a "yacc" specification of the syntax of RLISP. It is used
 * to provide a (symbolic-mode) RLISP to Lisp translator that can be
 * made freely available without reference to anybody apart from
 * myself!  The Lisp dialect generated is Standard Lisp and in all reality
 * I intend it to be for use with CSL (my own Lisp). I am putting in
 * a switch that causes generation of something a bit more like Common
 * Lisp but please do not expect this to be fully sorted out and
 * suitable for use with full Common Lisp: again it is tuned to my own
 * private purposes...
 *
 * I will think about making this work with Bison as wall as Yacc but
 * maybe I prefer the licence terms associated with Yacc. But it is quite
 * certain that if you receive this code and can make it work with Bison
 * you can use it internally: the only issues are to do with distribution,
 * and if you are careful to use a sufficiently modern release of Bison
 * its skeleton code may be distributed without bad license consequences.
 * Hmm when I wrote that the change in Bison's treamnet of its "skeleton"
 * code maybe felt new enough to worry about the thought of somebody using
 * an old version, now I feel able to standardize on bison.
 *
 * Usage:
 *      r2l -common -rights -Dname=val source1.red ... sourcen.red dest.lsp
 */


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


%{

/*
 * This is a "yacc" specification of the syntax of RLISP. It is used
 * to provide a (symbolic-mode) RLISP to Lisp translator that can be
 * made freely available without reference to anybody apart from
 * myself!  The Lisp dialect generated is Standard Lisp and in all reality
 * I intend it to be for use with CSL (my own Lisp). I am putting in
 * a switch that causes generation of something a bit more like Common
 * Lisp but please do not expect this to be fully sorted out and
 * suitable for use with full Common Lisp: again it is tuned to my own
 * private purposes...
 *
 * I will think about making this work with Bison as wall as Yacc but
 * maybe I prefer the licence terms associated with Yacc. But it is quite
 * certain that if you receive this code and can make it work with Bison
 * you can use it internally: the only issues are to do with distribution,
 * and if you are careful to use a sufficiently modern release of Bison
 * its skeleton code may be distributed without bad license consequences.
 *
 * Usage:
 *      r2l -common -rights -Dname=val source1.red ... sourcen.red dest.lsp
 */

/*
 * This code may be used and modified, and redistributed in binary
 * or source form, subject to the "CCL Public License", which should
 * accompany it. This license is a variant on the BSD license, and thus
 * permits use of code derived from this in either open and commercial
 * projects: but it does require that updates to this code be made
 * available back to the originators of the package.
 * Before merging other code in with this or linking this code
 * with other packages or libraries please check that the license terms
 * of the other material are compatible with those of this.
 */


#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

/*
 * The next line is a bit of a cop-out!
 */
typedef long int intptr_t;

intptr_t *heap;
int heapfringe = 0;

int yyparse();

FILE *inputfile, *outputfile;
FILE *filestack[30];
int filestackp = 0;


char *defined_names[20];
int n_defined_names;
int common;

static char *rights_message[] =
{
"%",
"% Copyright (C) 2008, following the master REDUCE source files.          *",
"%                                                                        *",
"% Redistribution and use in source and binary forms, with or without     *",
"% modification, are permitted provided that the following conditions are *",
"% met:                                                                   *",
"%                                                                        *",
"%     * Redistributions of source code must retain the relevant          *",
"%       copyright notice, this list of conditions and the following      *",
"%       disclaimer.                                                      *",
"%     * Redistributions in binary form must reproduce the above          *",
"%       copyright notice, this list of conditions and the following      *",
"%       disclaimer in the documentation and/or other materials provided  *",
"%       with the distribution.                                           *",
"%                                                                        *",
"% THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS    *",
"% \"AS IS\" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT      *",
"% LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS      *",
"% FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE         *",
"% COPYRIGHT OWNERS OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,   *",
"% INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,   *",
"% BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS  *",
"% OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND *",
"% ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR  *",
"% TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF     *",
"% THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH   *",
"% DAMAGE.                                                                *",
"%",
    NULL
};

int main(int argc, char *argv[])
{
    int rights = 0;
    inputfile = NULL;
    outputfile = NULL;
    common = 0;
/*
 * If the very first arg is "-common" pick that off.
 */
    if (argc > 1 &&
        strcmp(argv[1], "-common") == 0)
    {   common = 1;
        printf("Common Lisp mode activated\n");
        argv++;
        argc--;
    }
/*
 * If the next arg is "-rights" then pick that off.
 */
    if (argc > 1 &&
        strcmp(argv[1], "-rights") == 0)
    {   rights = 1;
        printf("Will insert re-distribution rights notice\n");
        argv++;
        argc--;
    }
/*
 * Pick off initial command-line things of the form "-D..." and store the
 * "..." bit.
 */
    n_defined_names = 0;
    while (argc > 1 &&
           argv[1][0] == '-' &&
           argv[1][1] == 'D')
    {   if (n_defined_names < 20)
            defined_names[n_defined_names++] = &argv[1][2];
        argv++;
        argc--;
    }
/*
 * If > 1 arg then final arg is destination. If only one arg then arg is
 * a source!
 */
    if (argc > 2)
    {   if (strcmp(argv[--argc], "-") == 0) outputfile = stdout;
        else outputfile = fopen(argv[argc], "w");
    }
    if (outputfile == NULL) outputfile = stdout;

    if (common)
        fprintf(outputfile, "\n;; RLISP to LISP converter. A C Norman 2004\n");
    else fprintf(outputfile, "\n%% RLISP to LISP converter. A C Norman 2004\n");
    fprintf(outputfile, "\n\n");
    if (rights)
    {   char **p = rights_message;
        char *m;
        while ((m = *p++) != NULL)
        {   fprintf(outputfile, "%s%s\n", (common ? ";;" : "%"), m);
        }
        fprintf(outputfile, "\n\n");
    }
    heap = (intptr_t *)malloc(2000000); /* Rather arbitrary size! */
    if (argc == 1) filestack[filestackp++] = stdin;
    else while (--argc != 0)
    {   if ((inputfile = fopen(argv[argc], "r")) == NULL)
            printf("File %s not readable\n", argv[argc]);
        else filestack[filestackp++] = inputfile;
    }
    inputfile = filestack[--filestackp];
    yyparse();
    fclose(outputfile);
    printf("Finished...\n");
    return 0;
}

char *lookup_name(char *s)
{
    int i, n = strlen(s);
    for (i=0; i<n_defined_names; i++)
    {   char *w = defined_names[i];  /* name or name=value */
        if (strncmp(s, w, n) == 0 &&
            w[n] == 0 ||
            w[n] == '=') return (w[n]==0 ? "" : &w[n+1]);
    }
    return NULL;
}

char linebuffer[128];
int linep = 0;

int ch = '\n';
int linecount = 1;

int nextch()
{
    if (ch == -1) return ch; /* end of file sticks */
    for (;;)
    {   ch = getc(inputfile);
        if (ch == -1 && filestackp != 0)
        {   inputfile = filestack[--filestackp];
            continue;
        }
        else break;
    }
    if (ch == '\n') linecount++;
    linebuffer[127 & linep++] = ch;
    return ch;
}

void yyerror(char *m)
{
    int q = 0;
    fprintf(stderr, "\nSyntax error (%s) around line %d\n", m, linecount);
    if (linep >= 128) q = linep-128;
    while (q != linep) fprintf(stderr, "%c", linebuffer[127 & q++]);
    fprintf(stderr, "$$$");
    while ((q = nextch()) != -1 && q != '\n') fprintf(stderr, "%c", q);
    fprintf(stderr, "\n");
    fflush(stderr);
    exit(0);
}

typedef struct keyword_code
{
    char *name;
    intptr_t code;
} keyword_code;

static keyword_code operators[];

intptr_t find_symbol(char *s)
{
    char *r = (char *)&heap[heapfringe];
    int len = strlen(s);
    strcpy(r, s);
    heapfringe += (len+4)/4;
    return (intptr_t)(r+1);
}

static int gennum = 1000;

intptr_t genlabel()
{
    char name[32];
    sprintf(name, "lab%d", gennum++);
    return find_symbol(name);
}

intptr_t genvar()
{
    char name[32];
    sprintf(name, "var%d", gennum++);
    return find_symbol(name);
}


static intptr_t yylex();

#define C_nil ((intptr_t)0)
#define qcar(x) (((intptr_t *)(x))[0])
#define qcdr(x) (((intptr_t *)(x))[1])

intptr_t cons(intptr_t a, intptr_t b)
{
    intptr_t *r = &heap[heapfringe];
    heapfringe += 2;
    qcar(r) = a;
    qcdr(r) = b;
    return (intptr_t)r;
}

intptr_t ncons(intptr_t a)
{
    intptr_t *r = &heap[heapfringe];
    heapfringe += 2;
    qcar(r) = a;
    qcdr(r) = C_nil;
    return (intptr_t)r;
}

intptr_t list1(intptr_t a)
{
    return cons(a, C_nil);
}

intptr_t list2(intptr_t a, intptr_t b)
{
    return cons(a, cons(b, C_nil));
}

intptr_t list3(intptr_t a, intptr_t b, intptr_t c)
{
    return cons(a, cons(b, cons(c, C_nil)));
}

intptr_t list4(intptr_t a, intptr_t b, intptr_t c, intptr_t d)
{
    return cons(a, cons(b, cons(c, cons(d, C_nil))));
}

intptr_t list5(intptr_t a, intptr_t b, intptr_t c, intptr_t d, intptr_t e)
{
    return cons(a, cons(b, cons(c, cons(d, cons(e, C_nil)))));
}

intptr_t list6(intptr_t a, intptr_t b, intptr_t c, intptr_t d, intptr_t e, intptr_t f)
{
    return cons(a, cons(b, cons(c, cons(d, cons(e, cons(f, C_nil))))));
}

intptr_t list7(intptr_t a, intptr_t b, intptr_t c, intptr_t d, intptr_t e, intptr_t f, intptr_t g)
{
    return cons(a, cons(b, cons(c, cons(d,
                cons(e, cons(f, cons(g, C_nil)))))));
}

intptr_t list8(intptr_t a, intptr_t b, intptr_t c, intptr_t d, intptr_t e, intptr_t f, intptr_t g, intptr_t h)
{
    return cons(a, cons(b, cons(c, cons(d,
                cons(e, cons(f, cons(g, cons(h, C_nil))))))));
}

intptr_t list9(intptr_t a, intptr_t b, intptr_t c, intptr_t d, intptr_t e, intptr_t f, intptr_t g, intptr_t h, intptr_t i)
{
    return cons(a, cons(b, cons(c, cons(d,
                cons(e, cons(f, cons(g, cons(h, cons(i, C_nil)))))))));
}

intptr_t append(intptr_t a, intptr_t b)
{
    if (a == C_nil || ((a & 1) != 0)) return b;
    else return cons(qcar(a), append(qcdr(a), b));
}

#define atom(x) ((intptr_t)(x)==0 || (((intptr_t)(x)) & 1) != 0)

int otlpos = 0;

int checkspace(int n)
{
    if (otlpos + n < 78)
    {   otlpos += n;
        return 1;
    }
    fprintf(outputfile, "\n");
    otlpos = n;
    return 0;
}

static char common_name[256];

char *tocommon(char *s)
{
   int easy = 1, c;
   int p = 0, q = 0;
   if (s[0] == '"') return s;   /* a string */
   if (isdigit(s[0])) return s; /* a number */
   while ((c = s[p++]) != 0)
   {  if (c == '!') c = s[p++];
      common_name[q++] = c;
      if (c == ':') common_name[q++] = c;  /* double up ':' */
      else if (!isalpha(c) && !isdigit(c) && c != '-' &&
          c != '_' && c != '*' && c != '&' && c != '$') easy = 0;
   }
   common_name[q] = 0;
   if (!easy)
   {   common_name[q+1] = '|';
       common_name[q+2] = 0;
       while (q != 0)
       {   common_name[q] = common_name[q-1];
           q--;
       }
       common_name[0] = '|';
   }
   return common_name;
}

void print(intptr_t a)
{
    if (a == C_nil)
    {   checkspace(3);
        fprintf(outputfile, "nil");
        return;
    }
    else if (atom(a))
    {   char *s = ((char *)a) - 1;
        if (common) s = tocommon(s);
        checkspace(strlen(s));
        fprintf(outputfile, "%s", s);
        return;
    }
    checkspace(1);
    fprintf(outputfile, "(");
    print(qcar(a));
    a = qcdr(a);
    while (!atom(a))
    {   if (checkspace(1)) fprintf(outputfile, " ");
        print(qcar(a));
        a = qcdr(a);
    }
    if ((intptr_t)a != 0)
    {   checkspace(2);
        fprintf(outputfile, " .");
        if (checkspace(1)) fprintf(outputfile, " ");
        print(a);
    }
    checkspace(1);
    fprintf(outputfile, ")");
}

static void evalorprint(intptr_t a)
{
    if (a != C_nil && !atom(a))
    {   intptr_t fn = qcar(a);
        if (fn != C_nil && atom(fn) && strcmp((char *)fn-1, "in")==0)
        {   a = qcar(qcdr(a));
            if (a != C_nil && !atom(a))
            {   fn = qcar(a);
                if (fn != C_nil && atom(fn) &&
                    strcmp((char *)fn-1, "list")==0)
                {   a = qcar(qcdr(a));
                    if (a != C_nil && atom(a))
                    {   FILE *f;
                        char filename[200];
                        char *s = (char *)a-1;
                        if (*s == '"')
                        {   s++;
                            s[strlen(s)-1] = 0;
                        }
                        if (*s != '$') strcpy(filename, s);
                        else
                        {   char parmname[200];
                            int k=0;
                            char *val;
                            s++;
                            parmname[k++] = '@';
                            while (*s != '/') parmname[k++] = *s++;
                            parmname[k] = 0;
                            val = lookup_name(parmname);
                            if (val == NULL) val = ".";
                            strcpy(filename, val);
                            strcat(filename, s);
                        }
                        f = fopen(filename, "r");
                        if (f == NULL)
                        {   printf("File \"%s\" not found\n", filename);
                            exit(1);
                        }
                        filestack[filestackp++] = inputfile;
                        inputfile = f;
                        printf("READING FILE <%s>\n", filename);
                        return;
                    }
                }
            }
        }
    }
    print(a);
}


#define sym_0                                find_symbol("0")
#define sym_car                              find_symbol("car")
#define sym_cdr                              find_symbol("cdr")
/* I have reversip available even in Common Lisp mode for nreverse */
#define sym_reversip                         find_symbol("reversip")
#define sym_plus                             find_symbol("plus")
#define sym_minus                            find_symbol("minus")
#define sym_minusp                           find_symbol("minusp")
#define sym_getv                             find_symbol("getv")
#define sym_difference                       find_symbol("difference")
#define sym_times                            find_symbol("times")
#define sym_quotient                         find_symbol("quotient")
#define sym_expt                             find_symbol("expt")
#define sym_cons                             find_symbol("cons")
#define sym_list                             find_symbol("list")
#define sym_progn                            find_symbol("progn")
#define sym_prog                             find_symbol("prog")
#define sym_de                               find_symbol("de")
#define sym_dm                               find_symbol("dm")
#define sym_ds                               find_symbol("ds")
#define sym_greaterp                         find_symbol("greaterp")
#define sym_lessp                            find_symbol("lessp")
#define sym_equal                            find_symbol("equal")
#define sym_setq                             find_symbol("setq")
#define sym_and                              find_symbol("and")
#define sym_or                               find_symbol("or")
#define sym_not                              find_symbol("not")
#define sym_member                           find_symbol("member")
#define sym_memq                             find_symbol("memq")
#define sym_neq                              find_symbol("neq")
#define sym_eq                               find_symbol("eq")
#define sym_geq                              find_symbol("geq")
#define sym_leq                              find_symbol("leq")
#define sym_freeof                           find_symbol("freeof")
#define sym_symbolic                         find_symbol("symbolic")
#define sym_algebraic                        find_symbol("algebraic")
#define sym_expr                             find_symbol("expr")
#define sym_macro                            find_symbol("macro")
#define sym_smacro                           find_symbol("smacro")
#define sym_procedure                        find_symbol("procedure")
#define sym_for                              find_symbol("for")
#define sym_step                             find_symbol("step")
#define sym_until                            find_symbol("until")
#define sym_each                             find_symbol("each")
#define sym_foreach                          find_symbol("foreach")
#define sym_in                               find_symbol("in")
#define sym_on                               find_symbol("on")
#define sym_do                               find_symbol("do")
#define sym_collect                          find_symbol("collect")
#define sym_sum                              find_symbol("sum")
#define sym_if                               find_symbol("if")
#define sym_then                             find_symbol("then")
#define sym_else                             find_symbol("else")
#define sym_cond                             find_symbol("cond")
#define sym_repeat                           find_symbol("repeat")
#define sym_while                            find_symbol("while")
#define sym_begin                            find_symbol("begin")
#define sym_end                              find_symbol("end")
#define sym_lsect                            find_symbol("<<")
#define sym_rsect                            find_symbol(">>")
#define sym_go                               find_symbol("go")
#define sym_to                               find_symbol("to")
#define sym_t                                find_symbol("t")
#define sym_goto                             find_symbol("goto")
#define sym_scalar                           find_symbol("scalar")
#define sym_integer                          find_symbol("integer")
#define sym_lambda                           find_symbol("lambda")
#define sym_symbol                           find_symbol("symbol")
#define sym_number                           find_symbol("number")
#define sym_string                           find_symbol("string")
#define sym_quoted                           find_symbol("quoted")
#define sym_return                           find_symbol("return")
#define sym_where                            find_symbol("where")
#define sym_rlistat                          find_symbol("rlistat")
#define sym_endstat                          find_symbol("endstat")
#define sym_null                             find_symbol("null")

intptr_t make_where(intptr_t body, intptr_t var, intptr_t val)
{
    return list2(
       list3(sym_lambda, list1(var), body),
       val);
}

intptr_t make_in_do(intptr_t var, intptr_t input, intptr_t body)
{
    intptr_t lab1 = genlabel();
    intptr_t var1 = genvar();
    return list8(sym_prog, list1(var1),
        list3(sym_setq, var1, input),
    lab1,
        list2(sym_cond,
            list2(list2(sym_null, var1),
                  list2(sym_return, C_nil))),
        list4(sym_prog, list1(var), list3(sym_setq, var, list2(sym_car, var1)), body),
        list3(sym_setq, var1, list2(sym_cdr, var1)),
        list2(sym_go, lab1));
}

intptr_t make_on_do(intptr_t var, intptr_t input, intptr_t body)
{
    intptr_t lab1 = genlabel();
    return list8(sym_prog, list1(var),
        list3(sym_setq, var, input),
    lab1,
        list2(sym_cond, 
            list2(list2(sym_null, var),
                  list2(sym_return, C_nil))),
        body,
        list3(sym_setq, var, list2(sym_cdr, var)),
        list2(sym_go, lab1));
}

intptr_t make_in_collect(intptr_t var, intptr_t input, intptr_t body)
{
    intptr_t lab1 = genlabel();
    intptr_t var1 = genvar();
    intptr_t var2 = genvar();
    return list8(sym_prog, list2(var1, var2),
        list3(sym_setq, var1, input),
    lab1,
        list2(sym_cond,
            list2(list2(sym_null, var1), 
                  list2(sym_return, list2(sym_reversip, var2)))),
        list4(sym_prog, list1(var),
            list3(sym_setq, var, list2(sym_car, var1)),
            list3(sym_setq, var2, list3(sym_cons, body, var2))),
        list3(sym_setq, var1, list2(sym_cdr, var1)),
        list2(sym_go, lab1));
}

intptr_t make_on_collect(intptr_t var, intptr_t input, intptr_t body)
{
    intptr_t lab1 = genlabel();
    intptr_t var2 = genvar();
    return list8(sym_prog, list1(var),
        list3(sym_setq, var, input),
    lab1,
        list2(sym_cond,
            list2(list2(sym_null, var), 
                  list2(sym_return, list2(sym_reversip, var2)))),
        list3(sym_setq, var2, list3(sym_cons, body, var2)),
        list3(sym_setq, var, list2(sym_cdr, var)),
        list2(sym_go, lab1));
}

intptr_t make_in_sum(intptr_t var, intptr_t input, intptr_t body)
{
    intptr_t lab1 = genlabel();
    intptr_t var1 = genvar();
    intptr_t var2 = genvar();
    return list9(sym_prog, list2(var1, var2),
        list3(sym_setq, var1, input),
        list3(sym_setq, var2, sym_0),
    lab1,
        list2(sym_cond,
            list2(list2(sym_null, var1), 
                  list2(sym_return, var2))),
        list4(sym_prog, list1(var),
            list3(sym_setq, var, list2(sym_car, var1)),
            list3(sym_setq, var2, list3(sym_plus, body, var2))),
        list3(sym_setq, var1, list2(sym_cdr, var1)),
        list2(sym_go, lab1));
}

intptr_t make_foreach(intptr_t var, intptr_t type, intptr_t input, intptr_t action, intptr_t body)
{
    intptr_t inon = 0, docollect = 0;
    if (strcmp((char *)type-1, "on") == 0) inon = 1;
    if (strcmp((char *)action-1, "collect") == 0) docollect = 1;
    else if (strcmp((char *)action-1, "sum") == 0) docollect = 2;
    switch (inon+2*docollect)
    {
case 0: /* in/do */
        return make_in_do(var, input, body);
case 1: /* on/do */
        return make_on_do(var, input, body);
case 2: /* in/collect */
        return make_in_collect(var, input, body);
case 3: /* on/collect */
        return make_on_collect(var, input, body);
case 4: /* in/sum */
        return make_in_sum(var, input, body);
case 5: /* on/sum WHICH CAN NOT MAKE SENSE */
default:
        return C_nil;
   }
}

intptr_t for_do(intptr_t var, intptr_t init, intptr_t step, intptr_t end, intptr_t body)
{
    intptr_t lab1 = genlabel();
    return list8(sym_prog, list1(var),
        list3(sym_setq, var, init),
    lab1,
        list2(sym_cond,
            list2(list2(sym_minusp,
                        list3(sym_times, step,
                        list3(sym_difference, end, var))),
                  list2(sym_return, C_nil))),
        body,
        list3(sym_setq, var, list3(sym_plus, var, step)),
        list2(sym_go, lab1));
}

intptr_t for_collect(intptr_t var, intptr_t init, intptr_t step, intptr_t end, intptr_t body)
{
    intptr_t lab1 = genlabel();
    intptr_t var1 = genvar();
    return list8(sym_prog, list2(var, var1),
        list3(sym_setq, var, init),
    lab1,
        list2(sym_cond,
            list2(list2(sym_minusp,
                        list3(sym_times, step,
                        list3(sym_difference, end, var))),
                  list2(sym_return, list2(sym_reversip, var1)))),
        list3(sym_setq, var1, list3(sym_cons, body, var1)),
        list3(sym_setq, var, list3(sym_plus, var, step)),
        list2(sym_go, lab1));
}

intptr_t for_sum(intptr_t var, intptr_t init, intptr_t step, intptr_t end, intptr_t body)
{
    intptr_t lab1 = genlabel();
    intptr_t var1 = genvar();
    return list9(sym_prog, list2(var, var1),
        list3(sym_setq, var, init),
        list3(sym_setq, var1, sym_0),
    lab1,
        list2(sym_cond,
            list2(list2(sym_minusp,
                        list3(sym_times, step,
                              list3(sym_difference, end, var))),
                  list2(sym_return, var1))),
        list3(sym_setq, var1, list3(sym_plus, body, var1)),
        list3(sym_setq, var, list3(sym_plus, var, step)),
        list2(sym_go, lab1));
}

intptr_t make_for(intptr_t var, intptr_t init, intptr_t step, intptr_t end, intptr_t action, intptr_t body)
{
    intptr_t docollect = 0;
    if (strcmp((char *)action-1, "collect") == 0) docollect = 1;
    else if (strcmp((char *)action-1, "sum") == 0) docollect = 2;
    switch (docollect)
    {
case 0: /* do */
        return for_do(var, init, step, end, body);
case 1: /* collect */
        return for_collect(var, init, step, end, body);
case 2: /* sum */
        return for_sum(var, init, step, end, body);
default:
        return C_nil;
    }
}

intptr_t lex_eof = 0;

%}

%union
{
    intptr_t LO;
}

%token <LO>     SETQ
%token <LO>     AND
%token <LO>     OR
%token <LO>     NOT
%token <LO>     MEMBER
%token <LO>     MEMQ
%token <LO>     NEQ
%token <LO>     EQ
%token <LO>     GEQ
%token <LO>     LEQ
%token <LO>     FREEOF
%token <LO>     SYMBOLIC
%token <LO>     ALGEBRAIC
%token <LO>     EXPR
%token <LO>     MACRO
%token <LO>     SMACRO
%token <LO>     PROCEDURE
%token <LO>     FOR
%token <LO>     STEP
%token <LO>     UNTIL
%token <LO>     EACH
%token <LO>     FOREACH
%token <LO>     IN
%token <LO>     ON
%token <LO>     DO
%token <LO>     COLLECT
%token <LO>     SUM
%token <LO>     IF
%token <LO>     THEN
%token <LO>     ELSE
%token <LO>     REPEAT
%token <LO>     WHILE
%token <LO>     BEGIN
%token <LO>     END
%token <LO>     ENDFILE
%token <LO>     LSECT
%token <LO>     RSECT
%token <LO>     GO
%token <LO>     TO
%token <LO>     GOTO
%token <LO>     SCALAR
%token <LO>     INTEGER
%token <LO>     LAMBDA
%token <LO>     SYMBOL
%token <LO>     NUMBER
%token <LO>     STRING
%token <LO>     LIST
%token <LO>     RETURN
%token <LO>     WHERE
%token <LO>     RLISTAT
%token <LO>     ENDSTAT
%token <LO>     HASHIF
%token <LO>     HASHELSE
%token <LO>     HASHELIF
%token <LO>     HASHENDIF
%%

/*
 * The grammar here is ambiguous or delicate in several areas:
 * (a) It has the standard "dangling else" problem.
 * (b) If R is a word tagged as RLIS, then R takes as its operands
 *     a whole bunch of things linked by commas. At present I have this
 *     grammar ambiguous on
 *       R1 a, b, c, R2 d, e, f;
 *     where R2 could (as far as the grammar is concerned) be being
 *     given one, two or three arguments. This problem arises if the
 *     operands of R may themselves end in an R. This is harded to avoid
 *     than I at first thought - one might well want conditionals in the
 *     are list of an R, but then
 *       R1 a, IF x THEN R2 b, c;
 *     comes and bites. I guess this is a "dangling comma" problem.
 * The above two problems are resolved by the parser genarator favouring
 * shift over reduce in the ambiguous cases.
 * (c) "IN", "ON" are both keywords, as used in
 *       for each x in y do ...
 *     and words with the RLISTAT property. This is sordid! Similarly
 *     "END" has a dual use. This is coped with by making special provision
 *     in the grammar for these cases.
 */

wholefile       :  ENDFILE              {  
    if (common) fprintf(outputfile, "\n;; end of file\n");
    else fprintf(outputfile, "\n%% end of file\n");
    exit(0);
                                        }
                |  command wholefile

command		:  cmnd sep		{ evalorprint($<LO>1); 
					  fprintf(outputfile, "\n\n");
                                          otlpos = 0;
                                          heapfringe = 0;
					}
		|  proc_type sep
                |  END
                |  END sep
		;

sep		:  ';'
		|  '$'
		;

proc_type	:  SYMBOLIC		{ $<LO>$ = sym_symbolic; }
		|  ALGEBRAIC		{ $<LO>$ = sym_algebraic; }
		;

proc_qual	:  EXPR			{ $<LO>$ = sym_de; }
		|  MACRO		{ $<LO>$ = sym_dm; }
		|  SMACRO		{ $<LO>$ = sym_ds; }
		;

sym_list	:  ')'			{ $<LO>$ = C_nil; }
		|  ',' SYMBOL sym_list	{ $<LO>$ = cons($<LO>2, $<LO>3); }
		;
/*
 * RLISP seems to want to be able to write
 *    procedure a >= b; ...
 * with an infix operator being defined!
 */

infix		:  SETQ			{ $<LO>$ = sym_setq; }
		|  OR			{ $<LO>$ = sym_or; }
		|  AND			{ $<LO>$ = sym_and; }
		|  MEMBER		{ $<LO>$ = sym_member; }
		|  MEMQ			{ $<LO>$ = sym_memq; }
		|  '='			{ $<LO>$ = sym_equal; }
		|  NEQ			{ $<LO>$ = sym_neq; }
		|  EQ			{ $<LO>$ = sym_eq; }
		|  GEQ			{ $<LO>$ = sym_geq; }
		|  '>'			{ $<LO>$ = sym_greaterp; }
		|  LEQ			{ $<LO>$ = sym_leq; }
		|  '<'			{ $<LO>$ = sym_lessp; }
		|  FREEOF		{ $<LO>$ = sym_freeof; }
		|  '+'			{ $<LO>$ = sym_plus; }
		|  '-'			{ $<LO>$ = sym_difference; }
		|  '*'			{ $<LO>$ = sym_times; }
		|  '/'			{ $<LO>$ = sym_quotient; }
		|  '^'			{ $<LO>$ = sym_expt; }
		|  '.'			{ $<LO>$ = sym_cons; }
		;

prefix		:  NOT			{ $<LO>$ = sym_not; }
		|  '+'			{ $<LO>$ = sym_plus; }
		|  '-'			{ $<LO>$ = sym_minus; }
		;

proc_head	:  SYMBOL		{ $<LO>$ = cons($<LO>1, C_nil); }
		|  SYMBOL SYMBOL	{ $<LO>$ = list2($<LO>1, $<LO>2); }
		|  SYMBOL '(' ')'	{ $<LO>$ = cons($<LO>1, C_nil); }
		|  SYMBOL '(' SYMBOL sym_list
					{ $<LO>$ = cons($<LO>1, cons($<LO>3, $<LO>4)); }
		|  prefix SYMBOL	{ $<LO>$ = list2($<LO>1, $<LO>2); }
		|  SYMBOL infix SYMBOL	{ $<LO>$ = list3($<LO>2, $<LO>1, $<LO>3); }
		;

proc_def	:  PROCEDURE proc_head sep cmnd
					{ $<LO>$ = list4(sym_de, qcar($<LO>2), qcdr($<LO>2), $<LO>4); }
		|  proc_type PROCEDURE proc_head sep cmnd
					{ $<LO>$ = list4(sym_de, qcar($<LO>3), qcdr($<LO>3), $<LO>5); }
		|  proc_qual PROCEDURE proc_head sep cmnd
					{ $<LO>$ = list4($<LO>1, qcar($<LO>3), qcdr($<LO>3), $<LO>5); }
		|  proc_type proc_qual PROCEDURE proc_head sep cmnd
					{ $<LO>$ = list4($<LO>2, qcar($<LO>4), qcdr($<LO>4), $<LO>6); }
		;

rlistat		:  RLISTAT
		|  IN			{ $<LO>$ = sym_in; }
		|  ON			{ $<LO>$ = sym_on; }
		;

rltail		:  expr			{ $<LO>$ = cons($<LO>1, C_nil); }
		|  expr ',' rltail	{ $<LO>$ = cons($<LO>1, $<LO>3); }
		;

/*
 * The category "cmnd" really only needs separating out to try to
 * control the comma-lists in RLIS things.
 */

cmnd		:  expr
		|  rlistat rltail	{ $<LO>$ = list2($<LO>1, cons(sym_list, $<LO>2)); }
		;

/*
 * As written here the grammar exhibits the traditional "dangling else"
 * ambiguity.  This must be resolved as SHIFT rather than REDUCE for
 * the proper results to emerge.
 */

if_stmt		:  IF expr THEN cmnd ELSE cmnd
					{ $<LO>$ = list3(sym_cond, 
                                                       list2($<LO>2, $<LO>4),
                                                       list2(sym_t, $<LO>6)); }
		|  IF expr THEN cmnd	{ $<LO>$ = list2(sym_cond,
                                                       list2($<LO>2, $<LO>4)); }
		;

for_update	:  ':' expr		{ $<LO>$ = cons(find_symbol("1"), $<LO>2); }
		|  STEP expr UNTIL expr	{ $<LO>$ = cons($<LO>2, $<LO>4); }
		;

for_action	:  DO			{ $<LO>$ = sym_do; }
		|  SUM			{ $<LO>$ = sym_sum; }
		|  COLLECT		{ $<LO>$ = sym_collect; }
		;

for_inon	:  IN			{ $<LO>$ = sym_in; }
		|  ON			{ $<LO>$ = sym_on; }
		;

for_stmt	:  FOR SYMBOL SETQ expr for_update for_action cmnd
					{ $<LO>$ = make_for($<LO>2, $<LO>4, qcar($<LO>5), qcdr($<LO>5), $<LO>6, $<LO>7); }
		|  FOR EACH SYMBOL for_inon expr for_action cmnd
					{ $<LO>$ = make_foreach($<LO>3, $<LO>4, $<LO>5, $<LO>6, $<LO>7); }
		|  FOREACH SYMBOL for_inon expr for_action cmnd
					{ $<LO>$ = make_foreach($<LO>2, $<LO>3, $<LO>4, $<LO>5, $<LO>6); }
		;

while_stmt	:  WHILE expr DO cmnd {
       intptr_t lab1 = genlabel();
       $<LO>$ = list6(sym_prog, C_nil, lab1,
                  list2(sym_cond, list2(list2(sym_null, $<LO>2), list2(sym_return, C_nil))),
                  $<LO>4,
                  list2(sym_go, lab1)); }
		;

repeat_stmt	:  REPEAT cmnd UNTIL expr {
       intptr_t lab1 = genlabel();
       $<LO>$ = list5(sym_prog, C_nil, lab1,
                  $<LO>2,
                  list2(sym_cond, list2(list2(sym_null, $<LO>4), list2(sym_go, lab1)))); }
		;

return_stmt	:  RETURN		{ $<LO>$ = list2(sym_return, C_nil); }
		|  RETURN expr		{ $<LO>$ = list2(sym_return, $<LO>2); }
		;

goto_stmt	:  GOTO SYMBOL		{ $<LO>$ = list2(sym_go, $<LO>2); }
		|  GO SYMBOL		{ $<LO>$ = list2(sym_go, $<LO>2); }
		|  GO TO SYMBOL		{ $<LO>$ = list2(sym_go, $<LO>3); }
		;

group_tail	:  RSECT		{ $<LO>$ = C_nil; }
		|  sep RSECT		{ $<LO>$ = C_nil; }
		|  sep cmnd group_tail	{ $<LO>$ = cons($<LO>2, $<LO>3); }
		;

group_expr	:  LSECT cmnd group_tail{ $<LO>$ = cons(sym_progn, cons($<LO>2, $<LO>3)); }
		;

scalar_tail	:  sep			{ $<LO>$ = C_nil; }
		|  ',' SYMBOL scalar_tail
					{ $<LO>$ = cons($<LO>2, $<LO>3); }
		|  ',' INTEGER scalar_tail
					{ $<LO>$ = cons($<LO>2, $<LO>3); }
		;

scalar_def	:  SCALAR SYMBOL scalar_tail
					{ $<LO>$ = cons($<LO>2, $<LO>3); }
scalar_def	:  INTEGER SYMBOL scalar_tail
					{ $<LO>$ = cons($<LO>2, $<LO>3); }
		;

scalar_defs	:  scalar_def
		|  scalar_defs scalar_def
					{ $<LO>$ = append($<LO>1, $<LO>2); }
		;

block_tail	:  END			{ $<LO>$ = C_nil; }
		|  cmnd END		{ $<LO>$ = cons($<LO>1, C_nil); }
		|  SYMBOL ':' block_tail{ $<LO>$ = cons($<LO>1, $<LO>3); }
		|  cmnd sep block_tail	{ $<LO>$ = cons($<LO>1, $<LO>3); }
		|  sep block_tail	{ $<LO>$ = $<LO>2; }
		;

block_expr	:  BEGIN scalar_defs block_tail
					{ $<LO>$ = cons(sym_prog, cons($<LO>2, $<LO>3)); }
		|  BEGIN block_tail	{ $<LO>$ = cons(sym_prog, cons(C_nil, $<LO>2)); }
		;

lambda_vars	:  sep			{ $<LO>$ = C_nil; }
		|  ',' SYMBOL lambda_vars
					{ $<LO>$ = cons($<LO>2, $<LO>3); }
		;

lambda_expr	:  LAMBDA SYMBOL lambda_vars cmnd
					{ $<LO>$ = list3(sym_lambda, ncons($<LO>2), $<LO>3); }
		|  LAMBDA '(' ')' sep cmnd
					{ $<LO>$ = list3(sym_lambda, C_nil, $<LO>5); }
		|  LAMBDA '(' SYMBOL sym_list sep cmnd
					{ $<LO>$ = list3(sym_lambda, cons($<LO>3, $<LO>4), $<LO>6); }
		;

/*
 * In what follows rx0 is an expression which MUST end if a key-command,
 * while lx0 is an expression which MUST NOT.
 */

expr		:  rx0
		|  lx0
		;

rx0		:  lx0 WHERE SYMBOL '=' rx1
					{ $<LO>$ = make_where($<LO>1, $<LO>3, $<LO>5); }
		|  rx1
		;

lx0		:  lx0 WHERE SYMBOL '=' lx1
					{ $<LO>$ = make_where($<LO>1, $<LO>3, $<LO>5); }
		|  lx1
		;

rx1		:  lx2 SETQ rx1		{ $<LO>$ = list3(sym_setq, $<LO>1, $<LO>3); }
		|  rx2
		;

lx1		:  lx2 SETQ lx1		{ $<LO>$ = list3(sym_setq, $<LO>1, $<LO>3); }
		|  lx2
		;

rx2tail		:  rx3			{ $<LO>$ = ncons($<LO>1); }
		|  lx3 OR rx2tail	{ $<LO>$ = cons($<LO>1, $<LO>3); }

rx2		:  lx3 OR rx2tail	{ $<LO>$ = cons(sym_or, cons($<LO>1, $<LO>3)); }
		|  rx3
		;

lx2tail		:  lx3			{ $<LO>$ = ncons($<LO>1); }
		|  lx3 OR lx2tail	{ $<LO>$ = cons($<LO>1, $<LO>3); }

lx2		:  lx3 OR lx2tail	{ $<LO>$ = cons(sym_or, cons($<LO>1, $<LO>3)); }
		|  lx3
		;

rx3tail		:  rx4			{ $<LO>$ = ncons($<LO>1); }
		|  lx4 AND rx3tail	{ $<LO>$ = cons($<LO>1, $<LO>3); }

rx3		:  lx4 AND rx3tail	{ $<LO>$ = cons(sym_and, cons($<LO>1, $<LO>3)); }
		|  rx4
		;

lx3tail		:  lx4			{ $<LO>$ = ncons($<LO>1); }
		|  lx4 AND lx3tail	{ $<LO>$ = cons($<LO>1, $<LO>3); }

lx3		:  lx4 AND lx3tail	{ $<LO>$ = cons(sym_and, cons($<LO>1, $<LO>3)); }
		|  lx4
		;

rx4		:  NOT rx4		{ $<LO>$ = list2(sym_not, $<LO>2); }
		|  rx5
		;

lx4		:  NOT lx4		{ $<LO>$ = list2(sym_not, $<LO>2); }
		|  lx5
		;

rx5		:  lx6 MEMBER ry6	{ $<LO>$ = list3(sym_member, $<LO>1, $<LO>3); }
		|  lx6 MEMQ ry6		{ $<LO>$ = list3(sym_memq, $<LO>1, $<LO>3); }
		|  lx6 '=' ry6		{ $<LO>$ = list3(sym_equal, $<LO>1, $<LO>3); }
		|  lx6 NEQ ry6		{ $<LO>$ = list3(sym_neq, $<LO>1, $<LO>3); }
		|  lx6 EQ ry6		{ $<LO>$ = list3(sym_eq, $<LO>1, $<LO>3); }
		|  lx6 GEQ ry6		{ $<LO>$ = list3(sym_geq, $<LO>1, $<LO>3); }
		|  lx6 '>' ry6		{ $<LO>$ = list3(sym_greaterp, $<LO>1, $<LO>3); }
		|  lx6 LEQ ry6		{ $<LO>$ = list3(sym_leq, $<LO>1, $<LO>3); }
		|  lx6 '<' ry6		{ $<LO>$ = list3(sym_lessp, $<LO>1, $<LO>3); }
		|  lx6 FREEOF ry6	{ $<LO>$ = list3(sym_freeof, $<LO>1, $<LO>3); }
		|  rx6
		;

lx5		:  lx6 MEMBER ly6	{ $<LO>$ = list3(sym_member, $<LO>1, $<LO>3); }
		|  lx6 MEMQ ly6		{ $<LO>$ = list3(sym_memq, $<LO>1, $<LO>3); }
		|  lx6 '=' ly6		{ $<LO>$ = list3(sym_equal, $<LO>1, $<LO>3); }
		|  lx6 NEQ ly6		{ $<LO>$ = list3(sym_neq, $<LO>1, $<LO>3); }
		|  lx6 EQ ly6		{ $<LO>$ = list3(sym_eq, $<LO>1, $<LO>3); }
		|  lx6 GEQ ly6		{ $<LO>$ = list3(sym_geq, $<LO>1, $<LO>3); }
		|  lx6 '>' ly6		{ $<LO>$ = list3(sym_greaterp, $<LO>1, $<LO>3); }
		|  lx6 LEQ ly6		{ $<LO>$ = list3(sym_leq, $<LO>1, $<LO>3); }
		|  lx6 '<' ly6		{ $<LO>$ = list3(sym_lessp, $<LO>1, $<LO>3); }
		|  lx6 FREEOF ly6	{ $<LO>$ = list3(sym_freeof, $<LO>1, $<LO>3); }
		|  lx6
		;

ry6		:  NOT ry6		{ $<LO>$ = list2(sym_not, $<LO>2); }
		|  rx6
		;

ly6		:  NOT ly6		{ $<LO>$ = list2(sym_not, $<LO>2); }
		|  lx6
		;

rx6tail		:  ry6a			{ $<LO>$ = ncons($<LO>1); }
		|  ly6a '+' rx6tail	{ $<LO>$ = cons($<LO>1, $<LO>3); }

rx6		:  lx6a '+' rx6tail	{ $<LO>$ = cons(sym_plus, cons($<LO>1, $<LO>3)); }
		|  rx6a
		;

lx6tail		:  ly6a			{ $<LO>$ = ncons($<LO>1); }
		|  ly6a '+' lx6tail	{ $<LO>$ = cons($<LO>1, $<LO>3); }

lx6		:  lx6a '+' lx6tail	{ $<LO>$ = cons(sym_plus, cons($<LO>1, $<LO>3)); }
		|  lx6a
		;

ry6a		:  NOT ry6a		{ $<LO>$ = list2(sym_not, $<LO>2); }
		|  rx6a
		;

rx6a		:  lx6a '-' ry7		{ $<LO>$ = list3(sym_difference, $<LO>1, $<LO>3); }
		|  rx7
		;

ly6a		:  NOT ly6a		{ $<LO>$ = list2(sym_not, $<LO>2); }
		|  lx6a
		;

lx6a		:  lx6a '-' ly7		{ $<LO>$ = list3(sym_difference, $<LO>1, $<LO>3); }
		|  lx7
		;

ry7		:  NOT ry7		{ $<LO>$ = list2(sym_not, $<LO>2); }
		|  rx7
		;

rx7		:  '+' ry7		{ $<LO>$ = $<LO>2; }
		|  '-' ry7		{ $<LO>$ = list2(sym_minus, $<LO>2); }
		|  rx8
		;

ly7		:  NOT ly7		{ $<LO>$ = list2(sym_not, $<LO>2); }
		|  lx7
		;

lx7		:  '+' ly7		{ $<LO>$ = $<LO>2; }
		|  '-' ly7		{ $<LO>$ = list2(sym_minus, $<LO>2); }
		|  lx8
		;

rx8tail		:  ry9			{ $<LO>$ = ncons($<LO>1); }
		|  ly9 '*' rx8tail	{ $<LO>$ = cons($<LO>1, $<LO>3); }

rx8		:  lx9 '*' rx8tail	{ $<LO>$ = cons(sym_times, cons($<LO>1, $<LO>3)); }
		|  rx9
		;

lx8tail		:  ly9			{ $<LO>$ = ncons($<LO>1); }
		|  ly9 '*' lx8tail	{ $<LO>$ = cons($<LO>1, $<LO>3); }

lx8		:  lx9 '*' lx8tail	{ $<LO>$ = cons(sym_times, cons($<LO>1, $<LO>3)); }
		|  lx9
		;

ry9		:  NOT ry9		{ $<LO>$ = list2(sym_not, $<LO>2); }
		|  '+' ry9              { $<LO>$ = $<LO>2; }
		|  '-' ry9              { $<LO>$ = list2(sym_minus, $<LO>2); }
		|  rx9
		;

rx9		:  lx9 '/' ry10		{ $<LO>$ = list3(sym_quotient, $<LO>1, $<LO>3); }
		|  rx10
		;

ly9		:  NOT ly9		{ $<LO>$ = list2(sym_not, $<LO>2); }
		|  '+' ly9              { $<LO>$ = $<LO>2; }
		|  '-' ly9              { $<LO>$ = list2(sym_minus, $<LO>2); }
		|  lx9
		;

lx9		:  lx9 '/' ly10		{ $<LO>$ = list3(sym_quotient, $<LO>1, $<LO>3); }
		|  lx10
		;

ly10		:  NOT ly10		{ $<LO>$ = list2(sym_not, $<LO>2); }
		|  '+' ly10		{ $<LO>$ = $<LO>2; }
		|  '-' ly10		{ $<LO>$ = list2(sym_minus, $<LO>2); }
		|  lx10
		;

lx10		:  lx11 '^' ly10	{ $<LO>$ = list3(sym_expt, $<LO>1, $<LO>3); }
		|  lx11
		;

ry10		:  NOT ry10		{ $<LO>$ = list2(sym_not, $<LO>2); }
		|  '+' ry10		{ $<LO>$ = $<LO>2; }
		|  '-' ry10		{ $<LO>$ = list2(sym_minus, $<LO>2); }
		|  rx10
		;

rx10		:  lx11 '^' ry10	{ $<LO>$ = list3(sym_expt, $<LO>1, $<LO>3); }
		|  rx11
		;

ry11		:  NOT ry11		{ $<LO>$ = list2(sym_not, $<LO>2); }
		|  '+' ry11		{ $<LO>$ = $<LO>2; }
		|  '-' ry11		{ $<LO>$ = list2(sym_minus, $<LO>2); }
		|  rx11
		;

rx11		:  x12 '.' ry11		{ $<LO>$ = list3(sym_cons, $<LO>1, $<LO>3); }
		|  if_stmt
		|  for_stmt
		|  while_stmt
		|  repeat_stmt
		|  return_stmt
		|  goto_stmt
		|  lambda_expr
		|  proc_def
		|  ENDSTAT		{ $<LO>$ = ncons($<LO>1); }
		;

ly11		:  NOT ly11		{ $<LO>$ = list2(sym_not, $<LO>2); }
		|  '+' ly11		{ $<LO>$ = $<LO>2; }
		|  '-' ly11		{ $<LO>$ = list2(sym_minus, $<LO>2); }
		|  lx11
		;

lx11		:  x12 '.' ly11		{ $<LO>$ = list3(sym_cons, $<LO>1, $<LO>3); }
		|  x12
		;

arg_list	:  ')'			{ $<LO>$ = C_nil; }
		|  '}'			{ $<LO>$ = C_nil; }
		|  ',' expr arg_list	{ $<LO>$ = cons($<LO>2, $<LO>3); }
		;

parened         :  '(' expr ')'		{ $<LO>$ = $<LO>2; }
		;

commaparened    :  '(' expr ',' expr arg_list { $<LO>$ = cons($<LO>2, cons($<LO>4,$<LO>5)); }
                ;

x12notparened	:  x13b '[' expr ']'	{ $<LO>$ = list3(sym_getv, $<LO>1, $<LO>3); }
                |  x13b '(' ')'         { $<LO>$ = cons($<LO>1, C_nil); }
		|  x13b parened    	{ $<LO>$ = cons($<LO>1, cons($<LO>2, C_nil)); }
		|  x13b commaparened   	{ $<LO>$ = cons($<LO>1, $<LO>2); }
		|  x13b x12notparened	{ $<LO>$ = list2($<LO>1, $<LO>2); }
		|  x13b
                ;

x12             :  x12notparened	{ $<LO>$ = $<LO>1; }
                |  parened		{ $<LO>$ = $<LO>1; }
		|  '{' '}'		{ $<LO>$ = C_nil; }
		|  '{' expr arg_list	{ $<LO>$ = cons(sym_list, cons($<LO>2, $<LO>3)); }
                |  SETQ commaparened	{ $<LO>$ = cons(sym_setq, $<LO>2); }
		|  OR commaparened	{ $<LO>$ = cons(sym_or, $<LO>2); }
		|  AND commaparened	{ $<LO>$ = cons(sym_and, $<LO>2); }
		|  MEMBER commaparened	{ $<LO>$ = cons(sym_member, $<LO>2); }
		|  MEMQ commaparened	{ $<LO>$ = cons(sym_memq, $<LO>2); }
		|  NEQ commaparened	{ $<LO>$ = cons(sym_neq, $<LO>2); }
		|  EQ commaparened	{ $<LO>$ = cons(sym_eq, $<LO>2); }
		|  GEQ commaparened	{ $<LO>$ = cons(sym_geq, $<LO>2); }
		|  LEQ commaparened	{ $<LO>$ = cons(sym_leq, $<LO>2); }
		|  FREEOF commaparened	{ $<LO>$ = cons(sym_freeof, $<LO>2); }
		;

x13b            :  SYMBOL
		|  NUMBER
		|  STRING
		|  LIST
		|  group_expr
		|  block_expr
                ;



%%


static keyword_code operators[] =
    {
       {"plus",                -1},
       {"minus",               -1},
       {"getv",                -1},
       {"difference",          -1},
       {"times",               -1},
       {"quotient",            -1},
       {"expt",                -1},
       {"cons",                -1},
       {"list",                -1},
       {"progn",               -1},
       {"prog",                -1},
       {"de",                  -1},
       {"dm",                  -1},
       {"ds",                  -1},
       {"greaterp",            -1},
       {"lessp",               -1},
       {"equal",               -1},
       {"setq",                SETQ},
       {"and",                 AND},
       {"or",                  OR},
       {"not",                 NOT},
       {"member",              MEMBER},
       {"memq",                MEMQ},
       {"neq",                 NEQ},
       {"eq",                  EQ},
       {"geq",                 GEQ},
       {"leq",                 LEQ},
       {"freeof",              FREEOF},
       {"symbolic",            SYMBOLIC},
       {"algebraic",           ALGEBRAIC},
       {"expr",                EXPR},
       {"macro",               MACRO},
       {"smacro",              SMACRO},
       {"procedure",           PROCEDURE},
       {"for",                 FOR},
       {"step",                STEP},
       {"until",               UNTIL},
       {"each",                EACH},
       {"foreach",             FOREACH},
       {"in",                  IN},
       {"on",                  ON},
       {"do",                  DO},
       {"collect",             COLLECT},
       {"sum",                 SUM},
       {"if",                  IF},
       {"then",                THEN},
       {"else",                ELSE},
       {"repeat",              REPEAT},
       {"while",               WHILE},
       {"begin",               BEGIN},
       {"end",                 END},
       {":lsect",              LSECT},
       {":rsect",              RSECT},
       {"go",                  GO},
       {"to",                  TO},
       {"goto",                GOTO},
       {"scalar",              SCALAR},
       {"integer",             INTEGER},
       {"lambda",              LAMBDA},
       {":symbol",             SYMBOL},
       {":number",             NUMBER},
       {":string",             STRING},
       {":list",               LIST},
       {"return",              RETURN},
       {"where",               WHERE},
       {"rlistat",             RLISTAT},
       {"endstat",             ENDSTAT},
       {"!#if",                HASHIF},
       {"!#else",              HASHELSE},
       {"!#elif",              HASHELIF},
       {"!#endif",             HASHENDIF},
       {NULL,                  0}
    };

int skipcomment()
{
    if (ch == '%')
    {   while (ch != '\n' && ch != -1) nextch();
        return 1;
    }
    else return 0;
}

static intptr_t onechar(int c)
{
    char b[4];
    b[0] = c;
    b[1] = 0;
    return find_symbol(b);
}

intptr_t lisp_token()
{
    char buffer[1000];
    int bp = 0, num = 0;
    intptr_t r;
    while (isspace(ch) || skipcomment()) nextch();
    num = isdigit(ch);
    while (isalpha(ch) || isdigit(ch) || ch=='_' || ch == '!' ||
           (num && ch == '.'))
    {   buffer[bp++] = ch;
        if (ch == '!')
        {   buffer[bp++] = nextch();
        }
        nextch();
    }
    buffer[bp] = 0;
    if (bp != 0)
    {   yylval.LO = find_symbol((char *)buffer);
        return num ? '0': 'a';
    }
    if (ch == '"')
    {   for (;;)
        {   buffer[bp++] = ch;
            while (nextch() != '"' && ch != '\n' && ch != EOF)
                buffer[bp++] = ch;
            buffer[bp++] = ch;
            if (nextch() != '"') break;
        }
        buffer[bp] = 0;
        yylval.LO = find_symbol((char *)buffer);
        return '"';
    }
    if (ch == '\'' || ch == '(' || ch == ')' || ch == '.')
    {   r = ch;
        nextch();
        return r;
    }
    r = ch;
    nextch();
    return onechar(r);
}


static intptr_t read_tail();
/*
 *    L  ->  atom
 *    L  ->  ' L
 *    L  ->  ( T
 *    L  ->  . error
 *    L  ->  ) error
 *
 *    T  ->  )
 *    T  ->  . L )
 *    T  ->  L T
 *
 */

static intptr_t read_list(intptr_t r)
{
    switch (r)
    {
case '(': return read_tail();

case '.':
case ')': return C_nil;   /* errors! */

case '\'':
          return list2(find_symbol("quote"), read_list(lisp_token()));
default:
          return yylval.LO;
    }
}

intptr_t read_tail()
{
    intptr_t r;
    switch (r = lisp_token())
    {
case ')': return C_nil;
case '.': r = read_list(lisp_token());
          if (lisp_token() != ')') fprintf(stderr, "\nBad syntax after '.'\n");
          return r;
case '\'':
          r = list2(find_symbol("quote"), read_list(lisp_token()));
          return cons(r, read_tail());
case '(': r = read_list(r);
          return cons(r, read_tail());
default:  r = yylval.LO;
          return cons(r, read_tail());
    }
}


static int skipping = 0;

static intptr_t genuine_yylex();

static int evaluates_to_true(intptr_t r)
{
    intptr_t fn, arg;
    char *s, *v;
    if (r == C_nil) return 0;
    else if (atom(r))
    {   s = (char *)r;
        v = lookup_name(s-1);
        if (v == NULL) return 0;
        else return 1;
    }
    fn = qcar(r);
    r = qcdr(r);
    if (fn == C_nil || !atom(fn)) return 0;
    s = (char *)fn;
    if (strcmp(s-1, "and") == 0)
    {   while (r != C_nil && !atom(r))
        {   arg = qcar(r);
            r = qcdr(r);
            if (!evaluates_to_true(arg)) return 0;
        }
        return 1;
    }
    else if (strcmp(s-1, "or") == 0)
    {   while (r != C_nil && !atom(r))
        {   arg = qcar(r);
            r = qcdr(r);
            if (evaluates_to_true(arg)) return 1;
        }
        return 0;
    }
    else if (strcmp(s-1, "not") == 0)
        return !evaluates_to_true(qcar(r));
    else return 0; /* junk treated as false! */
}


static void skip_tokens()
{
    intptr_t r;
    skipping = 1;
    for (;;)
    {   r = genuine_yylex();
        switch (r)
        {
    case HASHIF:
            skipping++;
            continue;
    case HASHELSE:
            if (skipping == 1)
            {   skipping = 0;
                return;
            }
            else continue;
    case HASHELIF:
            if (skipping == 1)
            {   skipping = 0;
                r = read_list(lisp_token());
                if (evaluates_to_true(r)) return;
                skipping = 1;
                continue;
            }
            else continue;
    case HASHENDIF:
            skipping--;
            if (skipping == 0) return;
            else continue;
    default:continue;
        }
    }
}

static intptr_t genuine_yylex()
{
    char buffer[1000];
    int bp, num;
    intptr_t r;
restart_lex:
    bp = 0;
    num = 0;
    while (isspace(ch) || skipcomment()) nextch();
    if (ch == -1)
    {   if (skipping)
        {   printf("\n+++ EOF while within !#if\n");
            exit(1);
        }
        return ENDFILE;
    }
    num = isdigit(ch);
    while (isalpha(ch) || isdigit(ch) || ch=='_' || ch == '!' ||
           (num && ch == '.'))
    {   buffer[bp++] = ch;
        if (ch == '!')
        {   buffer[bp++] = nextch();
        }
        nextch();
    }
    buffer[bp] = 0;
    if (bp != 0)
    {   int k;
        for (k=0;;k++)
        {   char *n = operators[k].name;
            int v = operators[k].code;
            if (n == NULL) break;
            if (v < 0) continue;
            if (strcmp(n, buffer) == 0)
            {
                switch (v)
                {
            case HASHIF:
                    if (skipping != 0) return v;
                    r = read_list(lisp_token());
                    if (!evaluates_to_true(r)) skip_tokens();
                    goto restart_lex;
            case HASHELSE:
            case HASHELIF:
                    if (skipping != 0) return v;
                    skip_tokens();
                    goto restart_lex;
            case HASHENDIF:
                    if (skipping != 0) return v;
                    else goto restart_lex; /* Ignore it! */
            default:break;
                }
                return v;
            }
        }
        yylval.LO = find_symbol((char *)buffer);
        return num ? NUMBER : SYMBOL;
    }
    if (ch == '"')
    {   for (;;)
        {   buffer[bp++] = ch;
            while (nextch() != '"' && ch != EOF && ch != '\n')
                buffer[bp++] = ch;
            buffer[bp++] = ch;
            if (nextch() != '"') break;
        }
        buffer[bp] = 0;
        yylval.LO = find_symbol((char *)buffer);
        return STRING;
    }
    if (ch == '\'')
    {   nextch();
        r = read_list(lisp_token());
        yylval.LO = list2(find_symbol("quote"), r);
        return LIST;
    }
    r = ch;
    nextch();
    if (r == ':' && ch == '=') { nextch(); r = SETQ; }
    else if (r == '<' && ch == '=') { nextch(); r = LEQ; }
    else if (r == '>' && ch == '=') { nextch(); r = GEQ; }
    else if (r == '<' && ch == '<') { nextch(); r = LSECT; }
    else if (r == '>' && ch == '>') { nextch(); r = RSECT; }
    return r;
}


static intptr_t yylex()
{
    return genuine_yylex();
}


/* end of file */
