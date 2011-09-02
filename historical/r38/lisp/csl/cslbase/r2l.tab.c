/* A Bison parser, made by GNU Bison 1.875b.  */

/* Skeleton parser for Yacc-like parsing with Bison,
   Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003 Free Software Foundation, Inc.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 59 Temple Place - Suite 330,
   Boston, MA 02111-1307, USA.  */

/* As a special exception, when this file is copied by Bison into a
   Bison output file, you may use that output file without restriction.
   This special exception was added by the Free Software Foundation
   in version 1.24 of Bison.  */

/* Written by Richard Stallman by simplifying the original so called
   ``semantic'' parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Using locations.  */
#define YYLSP_NEEDED 0



/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     SETQ = 258,
     AND = 259,
     OR = 260,
     NOT = 261,
     MEMBER = 262,
     MEMQ = 263,
     NEQ = 264,
     EQ = 265,
     GEQ = 266,
     LEQ = 267,
     FREEOF = 268,
     SYMBOLIC = 269,
     ALGEBRAIC = 270,
     EXPR = 271,
     MACRO = 272,
     SMACRO = 273,
     PROCEDURE = 274,
     FOR = 275,
     STEP = 276,
     UNTIL = 277,
     EACH = 278,
     FOREACH = 279,
     IN = 280,
     ON = 281,
     DO = 282,
     COLLECT = 283,
     SUM = 284,
     IF = 285,
     THEN = 286,
     ELSE = 287,
     REPEAT = 288,
     WHILE = 289,
     BEGIN = 290,
     END = 291,
     ENDFILE = 292,
     LSECT = 293,
     RSECT = 294,
     GO = 295,
     TO = 296,
     GOTO = 297,
     SCALAR = 298,
     INTEGER = 299,
     LAMBDA = 300,
     SYMBOL = 301,
     NUMBER = 302,
     STRING = 303,
     LIST = 304,
     RETURN = 305,
     WHERE = 306,
     RLISTAT = 307,
     ENDSTAT = 308,
     HASHIF = 309,
     HASHELSE = 310,
     HASHELIF = 311,
     HASHENDIF = 312
   };
#endif
#define SETQ 258
#define AND 259
#define OR 260
#define NOT 261
#define MEMBER 262
#define MEMQ 263
#define NEQ 264
#define EQ 265
#define GEQ 266
#define LEQ 267
#define FREEOF 268
#define SYMBOLIC 269
#define ALGEBRAIC 270
#define EXPR 271
#define MACRO 272
#define SMACRO 273
#define PROCEDURE 274
#define FOR 275
#define STEP 276
#define UNTIL 277
#define EACH 278
#define FOREACH 279
#define IN 280
#define ON 281
#define DO 282
#define COLLECT 283
#define SUM 284
#define IF 285
#define THEN 286
#define ELSE 287
#define REPEAT 288
#define WHILE 289
#define BEGIN 290
#define END 291
#define ENDFILE 292
#define LSECT 293
#define RSECT 294
#define GO 295
#define TO 296
#define GOTO 297
#define SCALAR 298
#define INTEGER 299
#define LAMBDA 300
#define SYMBOL 301
#define NUMBER 302
#define STRING 303
#define LIST 304
#define RETURN 305
#define WHERE 306
#define RLISTAT 307
#define ENDSTAT 308
#define HASHIF 309
#define HASHELSE 310
#define HASHELIF 311
#define HASHENDIF 312




/* Copy the first part of user declarations.  */
#line 36 "r2l.y"


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
    "",
    " This code may be used and modified, and redistributed in binary",
    " or source form, subject to the \"CCL Public License\", which should",
    " accompany it. This license is a variant on the BSD license, and thus",
    " permits use of code derived from this in either open and commercial",
    " projects: but it does require that updates to this code be made",
    " available back to the originators of the package.",
    " Before merging other code in with this or linking this code",
    " with other packages or libraries please check that the license terms",
    " of the other material are compatible with those of this.",
    "",
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



/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

#if ! defined (YYSTYPE) && ! defined (YYSTYPE_IS_DECLARED)
#line 734 "r2l.y"
typedef union YYSTYPE {
    intptr_t LO;
} YYSTYPE;
/* Line 191 of yacc.c.  */
#line 891 "r2l.tab.c"
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 214 of yacc.c.  */
#line 903 "r2l.tab.c"

#if ! defined (yyoverflow) || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# if YYSTACK_USE_ALLOCA
#  define YYSTACK_ALLOC alloca
# else
#  ifndef YYSTACK_USE_ALLOCA
#   if defined (alloca) || defined (_ALLOCA_H)
#    define YYSTACK_ALLOC alloca
#   else
#    ifdef __GNUC__
#     define YYSTACK_ALLOC __builtin_alloca
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning. */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
# else
#  if defined (__STDC__) || defined (__cplusplus)
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   define YYSIZE_T size_t
#  endif
#  define YYSTACK_ALLOC malloc
#  define YYSTACK_FREE free
# endif
#endif /* ! defined (yyoverflow) || YYERROR_VERBOSE */


#if (! defined (yyoverflow) \
     && (! defined (__cplusplus) \
	 || (YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  short yyss;
  YYSTYPE yyvs;
  };

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (short) + sizeof (YYSTYPE))				\
      + YYSTACK_GAP_MAXIMUM)

/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  register YYSIZE_T yyi;		\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (0)
#  endif
# endif

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack)					\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack, Stack, yysize);				\
	Stack = &yyptr->Stack;						\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (0)

#endif

#if defined (__STDC__) || defined (__cplusplus)
   typedef signed char yysigned_char;
#else
   typedef short yysigned_char;
#endif

/* YYFINAL -- State number of the termination state. */
#define YYFINAL  145
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   1441

/* YYNTOKENS -- Number of terminals. */
#define YYNTOKENS  77
/* YYNNTS -- Number of nonterminals. */
#define YYNNTS  85
/* YYNRULES -- Number of rules. */
#define YYNRULES  262
/* YYNRULES -- Number of states. */
#define YYNSTATES  417

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   312

#define YYTRANSLATE(YYX) 						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const unsigned char yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,    59,     2,     2,     2,
      71,    60,    67,    65,    61,    66,    70,    68,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    72,    58,
      64,    62,    63,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    74,     2,    75,    69,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    76,     2,    73,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const unsigned short yyprhs[] =
{
       0,     0,     3,     5,     8,    11,    14,    16,    19,    21,
      23,    25,    27,    29,    31,    33,    35,    39,    41,    43,
      45,    47,    49,    51,    53,    55,    57,    59,    61,    63,
      65,    67,    69,    71,    73,    75,    77,    79,    81,    83,
      85,    88,    92,    97,   100,   104,   109,   115,   121,   128,
     130,   132,   134,   136,   140,   142,   145,   152,   157,   160,
     165,   167,   169,   171,   173,   175,   183,   191,   198,   203,
     208,   210,   213,   216,   219,   223,   225,   228,   232,   236,
     238,   242,   246,   250,   254,   256,   259,   261,   264,   268,
     272,   275,   279,   282,   284,   288,   293,   299,   306,   308,
     310,   316,   318,   324,   326,   330,   332,   336,   338,   340,
     344,   348,   350,   352,   356,   360,   362,   364,   368,   372,
     374,   376,   380,   384,   386,   389,   391,   394,   396,   400,
     404,   408,   412,   416,   420,   424,   428,   432,   436,   438,
     442,   446,   450,   454,   458,   462,   466,   470,   474,   478,
     480,   483,   485,   488,   490,   492,   496,   500,   502,   504,
     508,   512,   514,   517,   519,   523,   525,   528,   530,   534,
     536,   539,   541,   544,   547,   549,   552,   554,   557,   560,
     562,   564,   568,   572,   574,   576,   580,   584,   586,   589,
     592,   595,   597,   601,   603,   606,   609,   612,   614,   618,
     620,   623,   626,   629,   631,   635,   637,   640,   643,   646,
     648,   652,   654,   657,   660,   663,   665,   669,   671,   673,
     675,   677,   679,   681,   683,   685,   687,   690,   693,   696,
     698,   702,   704,   706,   708,   712,   716,   722,   727,   731,
     734,   737,   740,   742,   744,   746,   749,   753,   756,   759,
     762,   765,   768,   771,   774,   777,   780,   783,   785,   787,
     789,   791,   793
};

/* YYRHS -- A `-1'-separated list of the rules' RHS. */
static const short yyrhs[] =
{
      78,     0,    -1,    37,    -1,    79,    78,    -1,    90,    80,
      -1,    81,    80,    -1,    36,    -1,    36,    80,    -1,    58,
      -1,    59,    -1,    14,    -1,    15,    -1,    16,    -1,    17,
      -1,    18,    -1,    60,    -1,    61,    46,    83,    -1,     3,
      -1,     5,    -1,     4,    -1,     7,    -1,     8,    -1,    62,
      -1,     9,    -1,    10,    -1,    11,    -1,    63,    -1,    12,
      -1,    64,    -1,    13,    -1,    65,    -1,    66,    -1,    67,
      -1,    68,    -1,    69,    -1,    70,    -1,     6,    -1,    65,
      -1,    66,    -1,    46,    -1,    46,    46,    -1,    46,    71,
      60,    -1,    46,    71,    46,    83,    -1,    85,    46,    -1,
      46,    84,    46,    -1,    19,    86,    80,    90,    -1,    81,
      19,    86,    80,    90,    -1,    82,    19,    86,    80,    90,
      -1,    81,    82,    19,    86,    80,    90,    -1,    52,    -1,
      25,    -1,    26,    -1,   109,    -1,   109,    61,    89,    -1,
     109,    -1,    88,    89,    -1,    30,   109,    31,    90,    32,
      90,    -1,    30,   109,    31,    90,    -1,    72,   109,    -1,
      21,   109,    22,   109,    -1,    27,    -1,    29,    -1,    28,
      -1,    25,    -1,    26,    -1,    20,    46,     3,   109,    92,
      93,    90,    -1,    20,    23,    46,    94,   109,    93,    90,
      -1,    24,    46,    94,   109,    93,    90,    -1,    34,   109,
      27,    90,    -1,    33,    90,    22,   109,    -1,    50,    -1,
      50,   109,    -1,    42,    46,    -1,    40,    46,    -1,    40,
      41,    46,    -1,    39,    -1,    80,    39,    -1,    80,    90,
     100,    -1,    38,    90,   100,    -1,    80,    -1,    61,    46,
     102,    -1,    61,    44,   102,    -1,    43,    46,   102,    -1,
      44,    46,   102,    -1,   103,    -1,   104,   103,    -1,    36,
      -1,    90,    36,    -1,    46,    72,   105,    -1,    90,    80,
     105,    -1,    80,   105,    -1,    35,   104,   105,    -1,    35,
     105,    -1,    80,    -1,    61,    46,   107,    -1,    45,    46,
     107,    90,    -1,    45,    71,    60,    80,    90,    -1,    45,
      71,    46,    83,    80,    90,    -1,   110,    -1,   111,    -1,
     111,    51,    46,    62,   112,    -1,   112,    -1,   111,    51,
      46,    62,   113,    -1,   113,    -1,   117,     3,   112,    -1,
     115,    -1,   117,     3,   113,    -1,   117,    -1,   119,    -1,
     121,     5,   114,    -1,   121,     5,   114,    -1,   119,    -1,
     121,    -1,   121,     5,   116,    -1,   121,     5,   116,    -1,
     121,    -1,   122,    -1,   123,     4,   118,    -1,   123,     4,
     118,    -1,   122,    -1,   123,    -1,   123,     4,   120,    -1,
     123,     4,   120,    -1,   123,    -1,     6,   122,    -1,   124,
      -1,     6,   123,    -1,   125,    -1,   131,     7,   126,    -1,
     131,     8,   126,    -1,   131,    62,   126,    -1,   131,     9,
     126,    -1,   131,    10,   126,    -1,   131,    11,   126,    -1,
     131,    63,   126,    -1,   131,    12,   126,    -1,   131,    64,
     126,    -1,   131,    13,   126,    -1,   129,    -1,   131,     7,
     127,    -1,   131,     8,   127,    -1,   131,    62,   127,    -1,
     131,     9,   127,    -1,   131,    10,   127,    -1,   131,    11,
     127,    -1,   131,    63,   127,    -1,   131,    12,   127,    -1,
     131,    64,   127,    -1,   131,    13,   127,    -1,   131,    -1,
       6,   126,    -1,   129,    -1,     6,   127,    -1,   131,    -1,
     132,    -1,   134,    65,   128,    -1,   135,    65,   128,    -1,
     133,    -1,   134,    -1,   134,    65,   130,    -1,   135,    65,
     130,    -1,   135,    -1,     6,   132,    -1,   133,    -1,   135,
      66,   136,    -1,   137,    -1,     6,   134,    -1,   135,    -1,
     135,    66,   138,    -1,   139,    -1,     6,   136,    -1,   137,
      -1,    65,   136,    -1,    66,   136,    -1,   141,    -1,     6,
     138,    -1,   139,    -1,    65,   138,    -1,    66,   138,    -1,
     143,    -1,   144,    -1,   146,    67,   140,    -1,   147,    67,
     140,    -1,   145,    -1,   146,    -1,   146,    67,   142,    -1,
     147,    67,   142,    -1,   147,    -1,     6,   144,    -1,    65,
     144,    -1,    66,   144,    -1,   145,    -1,   147,    68,   150,
      -1,   151,    -1,     6,   146,    -1,    65,   146,    -1,    66,
     146,    -1,   147,    -1,   147,    68,   148,    -1,   149,    -1,
       6,   148,    -1,    65,   148,    -1,    66,   148,    -1,   149,
      -1,   155,    69,   148,    -1,   155,    -1,     6,   150,    -1,
      65,   150,    -1,    66,   150,    -1,   151,    -1,   155,    69,
     150,    -1,   153,    -1,     6,   152,    -1,    65,   152,    -1,
      66,   152,    -1,   153,    -1,   160,    70,   152,    -1,    91,
      -1,    95,    -1,    96,    -1,    97,    -1,    98,    -1,    99,
      -1,   108,    -1,    87,    -1,    53,    -1,     6,   154,    -1,
      65,   154,    -1,    66,   154,    -1,   155,    -1,   160,    70,
     154,    -1,   160,    -1,    60,    -1,    73,    -1,    61,   109,
     156,    -1,    71,   109,    60,    -1,    71,   109,    61,   109,
     156,    -1,   161,    74,   109,    75,    -1,   161,    71,    60,
      -1,   161,   157,    -1,   161,   158,    -1,   161,   159,    -1,
     161,    -1,   159,    -1,   157,    -1,    76,    73,    -1,    76,
     109,   156,    -1,     3,   158,    -1,     5,   158,    -1,     4,
     158,    -1,     7,   158,    -1,     8,   158,    -1,     9,   158,
      -1,    10,   158,    -1,    11,   158,    -1,    12,   158,    -1,
      13,   158,    -1,    46,    -1,    47,    -1,    48,    -1,    49,
      -1,   101,    -1,   106,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const unsigned short yyrline[] =
{
       0,   818,   818,   823,   825,   830,   831,   832,   835,   836,
     839,   840,   843,   844,   845,   848,   849,   857,   858,   859,
     860,   861,   862,   863,   864,   865,   866,   867,   868,   869,
     870,   871,   872,   873,   874,   875,   878,   879,   880,   883,
     884,   885,   886,   888,   889,   892,   894,   896,   898,   902,
     903,   904,   907,   908,   916,   917,   926,   930,   934,   935,
     938,   939,   940,   943,   944,   947,   949,   951,   955,   963,
     970,   971,   974,   975,   976,   979,   980,   981,   984,   987,
     988,   990,   994,   996,  1000,  1001,  1005,  1006,  1007,  1008,
    1009,  1012,  1014,  1017,  1018,  1022,  1024,  1026,  1035,  1036,
    1039,  1041,  1044,  1046,  1049,  1050,  1053,  1054,  1057,  1058,
    1060,  1061,  1064,  1065,  1067,  1068,  1071,  1072,  1074,  1075,
    1078,  1079,  1081,  1082,  1085,  1086,  1089,  1090,  1093,  1094,
    1095,  1096,  1097,  1098,  1099,  1100,  1101,  1102,  1103,  1106,
    1107,  1108,  1109,  1110,  1111,  1112,  1113,  1114,  1115,  1116,
    1119,  1120,  1123,  1124,  1127,  1128,  1130,  1131,  1134,  1135,
    1137,  1138,  1141,  1142,  1145,  1146,  1149,  1150,  1153,  1154,
    1157,  1158,  1161,  1162,  1163,  1166,  1167,  1170,  1171,  1172,
    1175,  1176,  1178,  1179,  1182,  1183,  1185,  1186,  1189,  1190,
    1191,  1192,  1195,  1196,  1199,  1200,  1201,  1202,  1205,  1206,
    1209,  1210,  1211,  1212,  1215,  1216,  1219,  1220,  1221,  1222,
    1225,  1226,  1229,  1230,  1231,  1232,  1235,  1236,  1237,  1238,
    1239,  1240,  1241,  1242,  1243,  1244,  1247,  1248,  1249,  1250,
    1253,  1254,  1257,  1258,  1259,  1262,  1265,  1268,  1269,  1270,
    1271,  1272,  1273,  1276,  1277,  1278,  1279,  1280,  1281,  1282,
    1283,  1284,  1285,  1286,  1287,  1288,  1289,  1292,  1293,  1294,
    1295,  1296,  1297
};
#endif

#if YYDEBUG || YYERROR_VERBOSE
/* YYTNME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals. */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "SETQ", "AND", "OR", "NOT", "MEMBER", 
  "MEMQ", "NEQ", "EQ", "GEQ", "LEQ", "FREEOF", "SYMBOLIC", "ALGEBRAIC", 
  "EXPR", "MACRO", "SMACRO", "PROCEDURE", "FOR", "STEP", "UNTIL", "EACH", 
  "FOREACH", "IN", "ON", "DO", "COLLECT", "SUM", "IF", "THEN", "ELSE", 
  "REPEAT", "WHILE", "BEGIN", "END", "ENDFILE", "LSECT", "RSECT", "GO", 
  "TO", "GOTO", "SCALAR", "INTEGER", "LAMBDA", "SYMBOL", "NUMBER", 
  "STRING", "LIST", "RETURN", "WHERE", "RLISTAT", "ENDSTAT", "HASHIF", 
  "HASHELSE", "HASHELIF", "HASHENDIF", "';'", "'$'", "')'", "','", "'='", 
  "'>'", "'<'", "'+'", "'-'", "'*'", "'/'", "'^'", "'.'", "'('", "':'", 
  "'}'", "'['", "']'", "'{'", "$accept", "wholefile", "command", "sep", 
  "proc_type", "proc_qual", "sym_list", "infix", "prefix", "proc_head", 
  "proc_def", "rlistat", "rltail", "cmnd", "if_stmt", "for_update", 
  "for_action", "for_inon", "for_stmt", "while_stmt", "repeat_stmt", 
  "return_stmt", "goto_stmt", "group_tail", "group_expr", "scalar_tail", 
  "scalar_def", "scalar_defs", "block_tail", "block_expr", "lambda_vars", 
  "lambda_expr", "expr", "rx0", "lx0", "rx1", "lx1", "rx2tail", "rx2", 
  "lx2tail", "lx2", "rx3tail", "rx3", "lx3tail", "lx3", "rx4", "lx4", 
  "rx5", "lx5", "ry6", "ly6", "rx6tail", "rx6", "lx6tail", "lx6", "ry6a", 
  "rx6a", "ly6a", "lx6a", "ry7", "rx7", "ly7", "lx7", "rx8tail", "rx8", 
  "lx8tail", "lx8", "ry9", "rx9", "ly9", "lx9", "ly10", "lx10", "ry10", 
  "rx10", "ry11", "rx11", "ly11", "lx11", "arg_list", "parened", 
  "commaparened", "x12notparened", "x12", "x13b", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const unsigned short yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,    59,    36,
      41,    44,    61,    62,    60,    43,    45,    42,    47,    94,
      46,    40,    58,   125,    91,    93,   123
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const unsigned char yyr1[] =
{
       0,    77,    78,    78,    79,    79,    79,    79,    80,    80,
      81,    81,    82,    82,    82,    83,    83,    84,    84,    84,
      84,    84,    84,    84,    84,    84,    84,    84,    84,    84,
      84,    84,    84,    84,    84,    84,    85,    85,    85,    86,
      86,    86,    86,    86,    86,    87,    87,    87,    87,    88,
      88,    88,    89,    89,    90,    90,    91,    91,    92,    92,
      93,    93,    93,    94,    94,    95,    95,    95,    96,    97,
      98,    98,    99,    99,    99,   100,   100,   100,   101,   102,
     102,   102,   103,   103,   104,   104,   105,   105,   105,   105,
     105,   106,   106,   107,   107,   108,   108,   108,   109,   109,
     110,   110,   111,   111,   112,   112,   113,   113,   114,   114,
     115,   115,   116,   116,   117,   117,   118,   118,   119,   119,
     120,   120,   121,   121,   122,   122,   123,   123,   124,   124,
     124,   124,   124,   124,   124,   124,   124,   124,   124,   125,
     125,   125,   125,   125,   125,   125,   125,   125,   125,   125,
     126,   126,   127,   127,   128,   128,   129,   129,   130,   130,
     131,   131,   132,   132,   133,   133,   134,   134,   135,   135,
     136,   136,   137,   137,   137,   138,   138,   139,   139,   139,
     140,   140,   141,   141,   142,   142,   143,   143,   144,   144,
     144,   144,   145,   145,   146,   146,   146,   146,   147,   147,
     148,   148,   148,   148,   149,   149,   150,   150,   150,   150,
     151,   151,   152,   152,   152,   152,   153,   153,   153,   153,
     153,   153,   153,   153,   153,   153,   154,   154,   154,   154,
     155,   155,   156,   156,   156,   157,   158,   159,   159,   159,
     159,   159,   159,   160,   160,   160,   160,   160,   160,   160,
     160,   160,   160,   160,   160,   160,   160,   161,   161,   161,
     161,   161,   161
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const unsigned char yyr2[] =
{
       0,     2,     1,     2,     2,     2,     1,     2,     1,     1,
       1,     1,     1,     1,     1,     1,     3,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       2,     3,     4,     2,     3,     4,     5,     5,     6,     1,
       1,     1,     1,     3,     1,     2,     6,     4,     2,     4,
       1,     1,     1,     1,     1,     7,     7,     6,     4,     4,
       1,     2,     2,     2,     3,     1,     2,     3,     3,     1,
       3,     3,     3,     3,     1,     2,     1,     2,     3,     3,
       2,     3,     2,     1,     3,     4,     5,     6,     1,     1,
       5,     1,     5,     1,     3,     1,     3,     1,     1,     3,
       3,     1,     1,     3,     3,     1,     1,     3,     3,     1,
       1,     3,     3,     1,     2,     1,     2,     1,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     1,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     1,
       2,     1,     2,     1,     1,     3,     3,     1,     1,     3,
       3,     1,     2,     1,     3,     1,     2,     1,     3,     1,
       2,     1,     2,     2,     1,     2,     1,     2,     2,     1,
       1,     3,     3,     1,     1,     3,     3,     1,     2,     2,
       2,     1,     3,     1,     2,     2,     2,     1,     3,     1,
       2,     2,     2,     1,     3,     1,     2,     2,     2,     1,
       3,     1,     2,     2,     2,     1,     3,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     2,     2,     2,     1,
       3,     1,     1,     1,     3,     3,     5,     4,     3,     2,
       2,     2,     1,     1,     1,     2,     3,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     1,     1,     1,
       1,     1,     1
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const unsigned short yydefact[] =
{
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    10,    11,    12,    13,    14,     0,     0,     0,
      50,    51,     0,     0,     0,     0,     6,     2,     0,     0,
       0,     0,   257,   258,   259,   260,    70,    49,   225,     0,
       0,     0,     0,     0,     0,     0,     0,   224,     0,     0,
     217,   218,   219,   220,   221,   222,   261,   262,   223,    54,
      98,    99,   101,   103,   105,   107,   111,   115,   119,   123,
     125,   127,   138,   149,   157,   161,   165,   169,   174,   179,
     183,   187,   199,   193,   211,   205,   244,   243,   231,   242,
       0,   247,   249,   248,     0,   124,   126,   250,   251,   252,
     253,   254,   255,   256,    36,    39,    37,    38,     0,     0,
       0,     0,     0,     0,     0,     0,    86,     0,     0,   257,
       8,     9,     0,     0,    84,     0,    92,     7,     0,     0,
      73,    72,     0,     0,    71,     0,   172,   171,   177,   176,
     173,   178,     0,   245,     0,     1,     3,     0,     5,     0,
       0,    55,    52,     4,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   239,   240,   241,     0,
      17,    19,    18,    20,    21,    23,    24,    25,    27,    29,
      40,    22,    26,    28,    30,    31,    32,    33,    34,    35,
       0,     0,    43,     0,     0,     0,    63,    64,     0,     0,
       0,     0,     0,     0,     0,    90,    87,     0,    85,    91,
      75,     0,    78,    74,     0,    93,     0,     0,     0,   170,
     175,   235,   232,     0,   233,   246,     0,     0,     0,     0,
       0,   104,   106,   110,   114,   108,   112,   118,   122,   116,
     120,     0,   128,   139,   151,   153,   129,   140,   131,   142,
     132,   143,   133,   144,   135,   146,   137,   148,   130,   141,
     134,   145,   136,   147,     0,   156,   160,   154,   163,   158,
     167,   164,   168,     0,     0,     0,   182,   186,   180,   191,
     184,   197,     0,     0,     0,   198,   203,   192,   209,   204,
     210,     0,     0,     0,   216,   215,   230,   229,   238,     0,
       0,     0,     0,    41,    44,    45,     0,     0,     0,    57,
      69,    68,     0,    79,    82,    83,    88,    89,    76,     0,
       0,    95,    15,     0,     0,     0,     0,     0,     0,     0,
      53,     0,     0,     0,   150,   152,   162,   166,     0,   188,
     194,   189,   195,   190,   196,     0,   200,   206,   201,   207,
     202,   208,   212,   226,   213,   227,   214,   228,   237,     0,
      42,     0,     0,     0,     0,    60,    62,    61,     0,     0,
       0,     0,    77,    94,     0,     0,    96,   234,    46,     0,
      47,   100,   102,   109,   113,   117,   121,   155,   159,   181,
     185,   236,     0,     0,    58,     0,    67,    56,    81,    80,
      16,    97,    48,    66,     0,    65,    59
};

/* YYDEFGOTO[NTERM-NUM]. */
static const short yydefgoto[] =
{
      -1,    43,    44,   122,    94,    46,   334,   201,   108,   109,
      47,    48,   151,   123,    50,   374,   378,   208,    51,    52,
      53,    54,    55,   222,    56,   324,   124,   125,   126,    57,
     226,    58,    59,    60,    61,    62,    63,   243,    64,   244,
      65,   247,    66,   248,    67,    68,    69,    70,    71,   252,
     253,   275,    72,   276,    73,   277,    74,   279,    75,   136,
      76,   138,    77,   286,    78,   287,    79,   288,    80,   290,
      81,   295,    82,   297,    83,   304,    84,   306,    85,   235,
      86,    91,    87,    88,    89
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -312
static const short yypact[] =
{
     551,   -31,   -31,   -31,   921,   -31,   -31,   -31,   -31,   -31,
     -31,   -31,  -312,  -312,  -312,  -312,  -312,    51,    18,    25,
    -312,  -312,   921,   699,   921,   403,     8,  -312,   699,     5,
      66,    -8,  -312,  -312,  -312,  -312,   921,  -312,  -312,   995,
     995,   921,   773,   127,   551,   240,    96,  -312,   921,     8,
    -312,  -312,  -312,  -312,  -312,  -312,  -312,  -312,  -312,  -312,
    -312,    82,  -312,  -312,  -312,   133,  -312,   168,  -312,   145,
    -312,  -312,  -312,   259,  -312,    55,  -312,  -312,  -312,  -312,
    -312,   115,  -312,  -312,  -312,   119,  -312,  -312,   130,   310,
     921,  -312,  -312,  -312,   188,  -312,  -312,  -312,  -312,  -312,
    -312,  -312,  -312,  -312,  -312,   242,  -312,  -312,   151,     8,
     162,   207,   144,   182,   201,   198,  -312,   202,   230,   205,
    -312,  -312,   477,    14,  -312,   403,  -312,  -312,    -5,   232,
    -312,  -312,    84,   -13,  -312,   995,  -312,  -312,  -312,  -312,
    -312,  -312,   219,  -312,    50,  -312,  -312,    51,  -312,   261,
      51,  -312,   220,  -312,   236,   921,   921,   921,  1069,  1069,
    1069,  1069,  1069,  1069,  1069,  1069,  1069,  1069,  1143,   995,
    1217,  1291,  1291,  1365,   847,   921,  -312,  -312,  -312,   222,
    -312,  -312,  -312,  -312,  -312,  -312,  -312,  -312,  -312,  -312,
    -312,  -312,  -312,  -312,  -312,  -312,  -312,  -312,  -312,  -312,
      62,   238,  -312,   699,   144,   921,  -312,  -312,   921,   699,
     921,   699,    98,    98,   477,  -312,  -312,   477,  -312,  -312,
    -312,   625,  -312,  -312,   239,  -312,   699,   125,     8,  -312,
    -312,  -312,  -312,   921,  -312,  -312,     8,    51,     8,   921,
     224,  -312,  -312,  -312,  -312,  -312,   282,  -312,  -312,  -312,
     285,  1069,  -312,  -312,  -312,  -312,  -312,  -312,  -312,  -312,
    -312,  -312,  -312,  -312,  -312,  -312,  -312,  -312,  -312,  -312,
    -312,  -312,  -312,  -312,  1143,  -312,  -312,  -312,  -312,   226,
     227,  -312,  -312,  1217,  1217,  1217,  -312,  -312,  -312,  -312,
     225,   228,  1291,  1291,  1291,  -312,  -312,  -312,  -312,  -312,
    -312,  1365,  1365,  1365,  -312,  -312,  -312,  -312,  -312,   159,
     243,   921,   125,  -312,  -312,  -312,   921,    -7,    33,   262,
    -312,  -312,   102,  -312,  -312,  -312,  -312,  -312,  -312,    -5,
      84,  -312,  -312,   251,     8,   699,    50,   699,     8,   699,
    -312,   921,   921,   921,  -312,  -312,  -312,  -312,  1143,  -312,
    -312,  -312,  -312,  -312,  -312,  1217,  -312,  -312,  -312,  -312,
    -312,  -312,  -312,  -312,  -312,  -312,  -312,  -312,  -312,    50,
    -312,    33,   921,   921,    33,  -312,  -312,  -312,   699,   699,
      98,    98,  -312,  -312,   125,   699,  -312,  -312,  -312,   699,
    -312,  -312,  -312,  -312,  -312,  -312,  -312,  -312,  -312,  -312,
    -312,  -312,   699,   278,  -312,   699,  -312,  -312,  -312,  -312,
    -312,  -312,  -312,  -312,   921,  -312,  -312
};

/* YYPGOTO[NTERM-NUM].  */
static const short yypgoto[] =
{
    -312,   257,  -312,   -14,    26,   -26,  -288,  -312,  -312,  -102,
    -312,  -312,    63,     0,  -312,  -312,  -287,    99,  -312,  -312,
    -312,  -312,  -312,   -15,  -312,  -206,   192,  -312,   -73,  -312,
      -4,  -312,   -21,  -312,  -312,  -151,  -149,   -17,  -312,   -12,
    -312,   -16,  -148,   -11,  -147,    -2,     1,  -312,  -312,    68,
      77,   -19,   -84,   -10,   -60,    57,  -155,    59,  -146,    -1,
     -22,     2,    -3,    -9,  -312,    -6,  -312,   -68,  -159,   -23,
    -154,  -129,  -142,  -113,  -116,   -38,  -163,   -28,  -141,  -311,
     245,    83,   247,  -312,  -312
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const unsigned short yytable[] =
{
      49,   113,    95,   115,   241,    96,   242,   325,   245,   246,
     305,   289,   127,   278,   372,   134,   291,   137,   137,   149,
     142,   144,   280,   114,   370,   387,    45,   152,   128,   296,
     296,   148,   307,   227,   220,   153,   139,   139,   132,   140,
      90,   110,   141,   299,    49,   236,   129,   228,   238,   215,
     216,   130,   219,   120,   121,   298,   298,   104,   401,   300,
     375,   376,   377,   133,   111,   373,   120,   121,   149,   179,
      45,   112,   120,   121,   254,   254,   254,   254,   254,   254,
     254,   254,   254,   254,   402,    92,    93,   405,    97,    98,
      99,   100,   101,   102,   103,   203,   410,   105,   255,   255,
     255,   255,   255,   255,   255,   255,   255,   255,   312,   217,
     232,   233,   131,   137,   221,   150,   106,   107,   225,   278,
     168,   169,   313,   234,   289,   289,   289,   145,   280,   291,
     291,   291,   139,   154,   229,   338,   155,   230,   305,   305,
     305,   326,   120,   121,   327,   224,   380,   137,   381,   157,
     296,   296,   296,   309,   310,   249,   120,   121,   250,   322,
     307,   307,   307,   356,   358,   360,   139,   254,   281,   206,
     207,   282,   177,   156,   408,   409,   298,   298,   298,   357,
     359,   361,   170,   171,   317,   332,   333,   318,   172,   320,
     391,   255,   392,   278,   245,   246,   289,   202,   323,   323,
     173,   291,   280,   315,    14,    15,    16,   147,   204,   319,
     205,   321,   336,   209,   335,   349,   351,   353,   152,   231,
     311,   329,   337,   210,   339,   211,   331,   256,   258,   260,
     262,   264,   266,   268,   270,   272,   257,   259,   261,   263,
     265,   267,   269,   271,   273,   180,   181,   182,   212,   183,
     184,   185,   186,   187,   188,   189,    14,    15,    16,   147,
     350,   352,   354,   362,   364,   366,   158,   159,   160,   161,
     162,   163,   164,   363,   365,   367,   213,   214,   223,   231,
     237,   239,   240,   311,   314,   330,   341,   342,   190,   343,
     369,   348,   355,   169,   379,   371,   171,   384,   120,   121,
     414,   146,   340,   316,   191,   192,   193,   194,   195,   196,
     197,   198,   199,   200,   382,   221,   225,   218,   368,   344,
     385,   165,   166,   167,   389,   393,   383,   395,   345,   397,
     394,   346,   396,   347,   176,   386,   178,   388,   398,   390,
       0,   249,     0,     0,   250,    25,   399,     0,    28,   400,
       0,   403,   404,     0,     0,     0,    32,    33,    34,    35,
       0,     0,     0,     0,     0,     0,   323,   323,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   406,   407,
       0,   174,     0,     0,   175,   411,     0,     0,     0,   412,
       0,     0,     0,   416,     0,     0,     0,     0,     0,     0,
       0,     0,   413,     0,     0,   415,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,     0,     0,     0,    19,    20,    21,
       0,     0,     0,    22,     0,     0,    23,    24,    25,   116,
       0,    28,     0,    29,     0,    30,   117,   118,    31,   119,
      33,    34,    35,    36,     0,    37,    38,     0,     0,     0,
       0,   120,   121,     0,     0,     0,     0,     0,    39,    40,
       0,     0,     0,     0,    41,     0,     0,     0,     0,    42,
       1,     2,     3,     4,     5,     6,     7,     8,     9,    10,
      11,    12,    13,    14,    15,    16,    17,    18,     0,     0,
       0,    19,    20,    21,     0,     0,     0,    22,     0,     0,
      23,    24,    25,   116,     0,    28,     0,    29,     0,    30,
       0,     0,    31,   119,    33,    34,    35,    36,     0,    37,
      38,     0,     0,     0,     0,   120,   121,     0,     0,     0,
       0,     0,    39,    40,     0,     0,     0,     0,    41,     0,
       0,     0,     0,    42,     1,     2,     3,     4,     5,     6,
       7,     8,     9,    10,    11,    12,    13,    14,    15,    16,
      17,    18,     0,     0,     0,    19,    20,    21,     0,     0,
       0,    22,     0,     0,    23,    24,    25,    26,    27,    28,
       0,    29,     0,    30,     0,     0,    31,    32,    33,    34,
      35,    36,     0,    37,    38,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    39,    40,     0,     0,
       0,     0,    41,     0,     0,     0,     0,    42,     1,     2,
       3,     4,     5,     6,     7,     8,     9,    10,    11,    12,
      13,    14,    15,    16,    17,    18,     0,     0,     0,    19,
      20,    21,     0,     0,     0,    22,     0,     0,    23,    24,
      25,     0,     0,    28,   328,    29,     0,    30,     0,     0,
      31,    32,    33,    34,    35,    36,     0,    37,    38,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      39,    40,     0,     0,     0,     0,    41,     0,     0,     0,
       0,    42,     1,     2,     3,     4,     5,     6,     7,     8,
       9,    10,    11,    12,    13,    14,    15,    16,    17,    18,
       0,     0,     0,    19,    20,    21,     0,     0,     0,    22,
       0,     0,    23,    24,    25,     0,     0,    28,     0,    29,
       0,    30,     0,     0,    31,    32,    33,    34,    35,    36,
       0,    37,    38,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    39,    40,     0,     0,     0,     0,
      41,     0,     0,     0,     0,    42,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,     0,     0,     0,    19,     0,     0,
       0,     0,     0,    22,     0,     0,    23,    24,    25,     0,
       0,    28,     0,    29,     0,    30,     0,     0,    31,    32,
      33,    34,    35,    36,     0,     0,    38,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    39,    40,
       0,     0,     0,     0,    41,     0,   143,     0,     0,    42,
       1,     2,     3,     4,     5,     6,     7,     8,     9,    10,
      11,    12,    13,    14,    15,    16,    17,    18,     0,     0,
       0,    19,     0,     0,     0,     0,     0,    22,     0,     0,
      23,    24,    25,     0,     0,    28,     0,    29,     0,    30,
       0,     0,    31,    32,    33,    34,    35,    36,     0,     0,
      38,     0,     0,     0,     0,     0,     0,   308,     0,     0,
       0,     0,    39,    40,     0,     0,     0,     0,    41,     0,
       0,     0,     0,    42,     1,     2,     3,     4,     5,     6,
       7,     8,     9,    10,    11,    12,    13,    14,    15,    16,
      17,    18,     0,     0,     0,    19,     0,     0,     0,     0,
       0,    22,     0,     0,    23,    24,    25,     0,     0,    28,
       0,    29,     0,    30,     0,     0,    31,    32,    33,    34,
      35,    36,     0,     0,    38,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    39,    40,     0,     0,
       0,     0,    41,     0,     0,     0,     0,    42,     1,     2,
       3,   135,     5,     6,     7,     8,     9,    10,    11,    12,
      13,    14,    15,    16,    17,    18,     0,     0,     0,    19,
       0,     0,     0,     0,     0,    22,     0,     0,    23,    24,
      25,     0,     0,    28,     0,    29,     0,    30,     0,     0,
      31,    32,    33,    34,    35,    36,     0,     0,    38,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      39,    40,     0,     0,     0,     0,    41,     0,     0,     0,
       0,    42,     1,     2,     3,   251,     5,     6,     7,     8,
       9,    10,    11,    12,    13,    14,    15,    16,    17,    18,
       0,     0,     0,    19,     0,     0,     0,     0,     0,    22,
       0,     0,    23,    24,    25,     0,     0,    28,     0,    29,
       0,    30,     0,     0,    31,    32,    33,    34,    35,    36,
       0,     0,    38,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    39,    40,     0,     0,     0,     0,
      41,     0,     0,     0,     0,    42,     1,     2,     3,   274,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,     0,     0,     0,    19,     0,     0,
       0,     0,     0,    22,     0,     0,    23,    24,    25,     0,
       0,    28,     0,    29,     0,    30,     0,     0,    31,    32,
      33,    34,    35,    36,     0,     0,    38,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    39,    40,
       0,     0,     0,     0,    41,     0,     0,     0,     0,    42,
       1,     2,     3,   283,     5,     6,     7,     8,     9,    10,
      11,    12,    13,    14,    15,    16,    17,    18,     0,     0,
       0,    19,     0,     0,     0,     0,     0,    22,     0,     0,
      23,    24,    25,     0,     0,    28,     0,    29,     0,    30,
       0,     0,    31,    32,    33,    34,    35,    36,     0,     0,
      38,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   284,   285,     0,     0,     0,     0,    41,     0,
       0,     0,     0,    42,     1,     2,     3,   292,     5,     6,
       7,     8,     9,    10,    11,    12,    13,    14,    15,    16,
      17,    18,     0,     0,     0,    19,     0,     0,     0,     0,
       0,    22,     0,     0,    23,    24,    25,     0,     0,    28,
       0,    29,     0,    30,     0,     0,    31,    32,    33,    34,
      35,    36,     0,     0,    38,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   293,   294,     0,     0,
       0,     0,    41,     0,     0,     0,     0,    42,     1,     2,
       3,   301,     5,     6,     7,     8,     9,    10,    11,    12,
      13,    14,    15,    16,    17,    18,     0,     0,     0,    19,
       0,     0,     0,     0,     0,    22,     0,     0,    23,    24,
      25,     0,     0,    28,     0,    29,     0,    30,     0,     0,
      31,    32,    33,    34,    35,    36,     0,     0,    38,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     302,   303,     0,     0,     0,     0,    41,     0,     0,     0,
       0,    42
};

static const short yycheck[] =
{
       0,    22,     4,    24,   155,     4,   155,   213,   156,   156,
     173,   170,    26,   168,    21,    36,   170,    39,    40,    45,
      41,    42,   168,    23,   312,   336,     0,    48,    28,   171,
     172,    45,   173,    46,    39,    49,    39,    40,    46,    40,
      71,    23,    40,   172,    44,   147,    41,    60,   150,   122,
      36,    46,   125,    58,    59,   171,   172,     6,   369,   172,
      27,    28,    29,    71,    46,    72,    58,    59,    94,    90,
      44,    46,    58,    59,   158,   159,   160,   161,   162,   163,
     164,   165,   166,   167,   371,     2,     3,   374,     5,     6,
       7,     8,     9,    10,    11,   109,   384,    46,   158,   159,
     160,   161,   162,   163,   164,   165,   166,   167,    46,   123,
      60,    61,    46,   135,   128,    19,    65,    66,   132,   274,
      65,    66,    60,    73,   283,   284,   285,     0,   274,   283,
     284,   285,   135,    51,   135,   237,     3,   135,   301,   302,
     303,   214,    58,    59,   217,    61,    44,   169,    46,     4,
     292,   293,   294,   174,   175,   157,    58,    59,   157,    61,
     301,   302,   303,   292,   293,   294,   169,   251,   169,    25,
      26,   169,    89,     5,   380,   381,   292,   293,   294,   292,
     293,   294,    67,    68,   205,    60,    61,   208,    69,   210,
     341,   251,   341,   348,   342,   342,   355,    46,   212,   213,
      70,   355,   348,   203,    16,    17,    18,    19,    46,   209,
       3,   211,   233,    31,   228,   283,   284,   285,   239,    60,
      61,   221,   236,    22,   238,    27,   226,   159,   160,   161,
     162,   163,   164,   165,   166,   167,   159,   160,   161,   162,
     163,   164,   165,   166,   167,     3,     4,     5,    46,     7,
       8,     9,    10,    11,    12,    13,    16,    17,    18,    19,
     283,   284,   285,   301,   302,   303,     7,     8,     9,    10,
      11,    12,    13,   301,   302,   303,    46,    72,    46,    60,
      19,    61,    46,    61,    46,    46,    62,     5,    46,     4,
     311,    65,    67,    66,    32,   316,    68,    46,    58,    59,
      22,    44,   239,   204,    62,    63,    64,    65,    66,    67,
      68,    69,    70,    71,   329,   329,   330,   125,    75,   251,
     334,    62,    63,    64,   338,   342,   330,   343,   251,   348,
     342,   274,   343,   274,    89,   335,    89,   337,   348,   339,
      -1,   343,    -1,    -1,   343,    35,   355,    -1,    38,   355,
      -1,   372,   373,    -1,    -1,    -1,    46,    47,    48,    49,
      -1,    -1,    -1,    -1,    -1,    -1,   380,   381,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   378,   379,
      -1,    71,    -1,    -1,    74,   385,    -1,    -1,    -1,   389,
      -1,    -1,    -1,   414,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   402,    -1,    -1,   405,     3,     4,     5,     6,
       7,     8,     9,    10,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    -1,    -1,    -1,    24,    25,    26,
      -1,    -1,    -1,    30,    -1,    -1,    33,    34,    35,    36,
      -1,    38,    -1,    40,    -1,    42,    43,    44,    45,    46,
      47,    48,    49,    50,    -1,    52,    53,    -1,    -1,    -1,
      -1,    58,    59,    -1,    -1,    -1,    -1,    -1,    65,    66,
      -1,    -1,    -1,    -1,    71,    -1,    -1,    -1,    -1,    76,
       3,     4,     5,     6,     7,     8,     9,    10,    11,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    -1,    -1,
      -1,    24,    25,    26,    -1,    -1,    -1,    30,    -1,    -1,
      33,    34,    35,    36,    -1,    38,    -1,    40,    -1,    42,
      -1,    -1,    45,    46,    47,    48,    49,    50,    -1,    52,
      53,    -1,    -1,    -1,    -1,    58,    59,    -1,    -1,    -1,
      -1,    -1,    65,    66,    -1,    -1,    -1,    -1,    71,    -1,
      -1,    -1,    -1,    76,     3,     4,     5,     6,     7,     8,
       9,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    -1,    -1,    -1,    24,    25,    26,    -1,    -1,
      -1,    30,    -1,    -1,    33,    34,    35,    36,    37,    38,
      -1,    40,    -1,    42,    -1,    -1,    45,    46,    47,    48,
      49,    50,    -1,    52,    53,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    65,    66,    -1,    -1,
      -1,    -1,    71,    -1,    -1,    -1,    -1,    76,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    -1,    -1,    -1,    24,
      25,    26,    -1,    -1,    -1,    30,    -1,    -1,    33,    34,
      35,    -1,    -1,    38,    39,    40,    -1,    42,    -1,    -1,
      45,    46,    47,    48,    49,    50,    -1,    52,    53,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      65,    66,    -1,    -1,    -1,    -1,    71,    -1,    -1,    -1,
      -1,    76,     3,     4,     5,     6,     7,     8,     9,    10,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      -1,    -1,    -1,    24,    25,    26,    -1,    -1,    -1,    30,
      -1,    -1,    33,    34,    35,    -1,    -1,    38,    -1,    40,
      -1,    42,    -1,    -1,    45,    46,    47,    48,    49,    50,
      -1,    52,    53,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    65,    66,    -1,    -1,    -1,    -1,
      71,    -1,    -1,    -1,    -1,    76,     3,     4,     5,     6,
       7,     8,     9,    10,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    -1,    -1,    -1,    24,    -1,    -1,
      -1,    -1,    -1,    30,    -1,    -1,    33,    34,    35,    -1,
      -1,    38,    -1,    40,    -1,    42,    -1,    -1,    45,    46,
      47,    48,    49,    50,    -1,    -1,    53,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    65,    66,
      -1,    -1,    -1,    -1,    71,    -1,    73,    -1,    -1,    76,
       3,     4,     5,     6,     7,     8,     9,    10,    11,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    -1,    -1,
      -1,    24,    -1,    -1,    -1,    -1,    -1,    30,    -1,    -1,
      33,    34,    35,    -1,    -1,    38,    -1,    40,    -1,    42,
      -1,    -1,    45,    46,    47,    48,    49,    50,    -1,    -1,
      53,    -1,    -1,    -1,    -1,    -1,    -1,    60,    -1,    -1,
      -1,    -1,    65,    66,    -1,    -1,    -1,    -1,    71,    -1,
      -1,    -1,    -1,    76,     3,     4,     5,     6,     7,     8,
       9,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    -1,    -1,    -1,    24,    -1,    -1,    -1,    -1,
      -1,    30,    -1,    -1,    33,    34,    35,    -1,    -1,    38,
      -1,    40,    -1,    42,    -1,    -1,    45,    46,    47,    48,
      49,    50,    -1,    -1,    53,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    65,    66,    -1,    -1,
      -1,    -1,    71,    -1,    -1,    -1,    -1,    76,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    -1,    -1,    -1,    24,
      -1,    -1,    -1,    -1,    -1,    30,    -1,    -1,    33,    34,
      35,    -1,    -1,    38,    -1,    40,    -1,    42,    -1,    -1,
      45,    46,    47,    48,    49,    50,    -1,    -1,    53,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      65,    66,    -1,    -1,    -1,    -1,    71,    -1,    -1,    -1,
      -1,    76,     3,     4,     5,     6,     7,     8,     9,    10,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      -1,    -1,    -1,    24,    -1,    -1,    -1,    -1,    -1,    30,
      -1,    -1,    33,    34,    35,    -1,    -1,    38,    -1,    40,
      -1,    42,    -1,    -1,    45,    46,    47,    48,    49,    50,
      -1,    -1,    53,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    65,    66,    -1,    -1,    -1,    -1,
      71,    -1,    -1,    -1,    -1,    76,     3,     4,     5,     6,
       7,     8,     9,    10,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    -1,    -1,    -1,    24,    -1,    -1,
      -1,    -1,    -1,    30,    -1,    -1,    33,    34,    35,    -1,
      -1,    38,    -1,    40,    -1,    42,    -1,    -1,    45,    46,
      47,    48,    49,    50,    -1,    -1,    53,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    65,    66,
      -1,    -1,    -1,    -1,    71,    -1,    -1,    -1,    -1,    76,
       3,     4,     5,     6,     7,     8,     9,    10,    11,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    -1,    -1,
      -1,    24,    -1,    -1,    -1,    -1,    -1,    30,    -1,    -1,
      33,    34,    35,    -1,    -1,    38,    -1,    40,    -1,    42,
      -1,    -1,    45,    46,    47,    48,    49,    50,    -1,    -1,
      53,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    65,    66,    -1,    -1,    -1,    -1,    71,    -1,
      -1,    -1,    -1,    76,     3,     4,     5,     6,     7,     8,
       9,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    -1,    -1,    -1,    24,    -1,    -1,    -1,    -1,
      -1,    30,    -1,    -1,    33,    34,    35,    -1,    -1,    38,
      -1,    40,    -1,    42,    -1,    -1,    45,    46,    47,    48,
      49,    50,    -1,    -1,    53,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    65,    66,    -1,    -1,
      -1,    -1,    71,    -1,    -1,    -1,    -1,    76,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    -1,    -1,    -1,    24,
      -1,    -1,    -1,    -1,    -1,    30,    -1,    -1,    33,    34,
      35,    -1,    -1,    38,    -1,    40,    -1,    42,    -1,    -1,
      45,    46,    47,    48,    49,    50,    -1,    -1,    53,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      65,    66,    -1,    -1,    -1,    -1,    71,    -1,    -1,    -1,
      -1,    76
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const unsigned char yystos[] =
{
       0,     3,     4,     5,     6,     7,     8,     9,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    24,
      25,    26,    30,    33,    34,    35,    36,    37,    38,    40,
      42,    45,    46,    47,    48,    49,    50,    52,    53,    65,
      66,    71,    76,    78,    79,    81,    82,    87,    88,    90,
      91,    95,    96,    97,    98,    99,   101,   106,   108,   109,
     110,   111,   112,   113,   115,   117,   119,   121,   122,   123,
     124,   125,   129,   131,   133,   135,   137,   139,   141,   143,
     145,   147,   149,   151,   153,   155,   157,   159,   160,   161,
      71,   158,   158,   158,    81,   122,   123,   158,   158,   158,
     158,   158,   158,   158,     6,    46,    65,    66,    85,    86,
      23,    46,    46,   109,    90,   109,    36,    43,    44,    46,
      58,    59,    80,    90,   103,   104,   105,    80,    90,    41,
      46,    46,    46,    71,   109,     6,   136,   137,   138,   139,
     136,   138,   109,    73,   109,     0,    78,    19,    80,    82,
      19,    89,   109,    80,    51,     3,     5,     4,     7,     8,
       9,    10,    11,    12,    13,    62,    63,    64,    65,    66,
      67,    68,    69,    70,    71,    74,   157,   158,   159,   109,
       3,     4,     5,     7,     8,     9,    10,    11,    12,    13,
      46,    62,    63,    64,    65,    66,    67,    68,    69,    70,
      71,    84,    46,    80,    46,     3,    25,    26,    94,    31,
      22,    27,    46,    46,    72,   105,    36,    80,   103,   105,
      39,    80,   100,    46,    61,    80,   107,    46,    60,   136,
     138,    60,    60,    61,    73,   156,    86,    19,    86,    61,
      46,   112,   113,   114,   116,   119,   121,   118,   120,   122,
     123,     6,   126,   127,   129,   131,   126,   127,   126,   127,
     126,   127,   126,   127,   126,   127,   126,   127,   126,   127,
     126,   127,   126,   127,     6,   128,   130,   132,   133,   134,
     135,   136,   138,     6,    65,    66,   140,   142,   144,   145,
     146,   147,     6,    65,    66,   148,   149,   150,   151,   148,
     150,     6,    65,    66,   152,   153,   154,   155,    60,   109,
     109,    61,    46,    60,    46,    90,    94,   109,   109,    90,
     109,    90,    61,    80,   102,   102,   105,   105,    39,    90,
      46,    90,    60,    61,    83,    80,   109,    80,    86,    80,
      89,    62,     5,     4,   126,   127,   132,   134,    65,   144,
     146,   144,   146,   144,   146,    67,   148,   150,   148,   150,
     148,   150,   152,   154,   152,   154,   152,   154,    75,   109,
      83,   109,    21,    72,    92,    27,    28,    29,    93,    32,
      44,    46,   100,   107,    46,    80,    90,   156,    90,    80,
      90,   112,   113,   114,   116,   118,   120,   128,   130,   140,
     142,   156,    93,   109,   109,    93,    90,    90,   102,   102,
      83,    90,    90,    90,    22,    90,   109
};

#if ! defined (YYSIZE_T) && defined (__SIZE_TYPE__)
# define YYSIZE_T __SIZE_TYPE__
#endif
#if ! defined (YYSIZE_T) && defined (size_t)
# define YYSIZE_T size_t
#endif
#if ! defined (YYSIZE_T)
# if defined (__STDC__) || defined (__cplusplus)
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# endif
#endif
#if ! defined (YYSIZE_T)
# define YYSIZE_T unsigned int
#endif

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrlab1


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  */

#define YYFAIL		goto yyerrlab

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      yytoken = YYTRANSLATE (yychar);				\
      YYPOPSTACK;						\
      goto yybackup;						\
    }								\
  else								\
    { 								\
      yyerror ("syntax error: cannot back up");\
      YYERROR;							\
    }								\
while (0)

#define YYTERROR	1
#define YYERRCODE	256

/* YYLLOC_DEFAULT -- Compute the default location (before the actions
   are run).  */

#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)         \
  Current.first_line   = Rhs[1].first_line;      \
  Current.first_column = Rhs[1].first_column;    \
  Current.last_line    = Rhs[N].last_line;       \
  Current.last_column  = Rhs[N].last_column;
#endif

/* YYLEX -- calling `yylex' with the right arguments.  */

#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (0)

# define YYDSYMPRINT(Args)			\
do {						\
  if (yydebug)					\
    yysymprint Args;				\
} while (0)

# define YYDSYMPRINTF(Title, Token, Value, Location)		\
do {								\
  if (yydebug)							\
    {								\
      YYFPRINTF (stderr, "%s ", Title);				\
      yysymprint (stderr, 					\
                  Token, Value);	\
      YYFPRINTF (stderr, "\n");					\
    }								\
} while (0)

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (cinluded).                                                   |
`------------------------------------------------------------------*/

#if defined (__STDC__) || defined (__cplusplus)
static void
yy_stack_print (short *bottom, short *top)
#else
static void
yy_stack_print (bottom, top)
    short *bottom;
    short *top;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (/* Nothing. */; bottom <= top; ++bottom)
    YYFPRINTF (stderr, " %d", *bottom);
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if defined (__STDC__) || defined (__cplusplus)
static void
yy_reduce_print (int yyrule)
#else
static void
yy_reduce_print (yyrule)
    int yyrule;
#endif
{
  int yyi;
  unsigned int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %u), ",
             yyrule - 1, yylno);
  /* Print the symbols being reduced, and their result.  */
  for (yyi = yyprhs[yyrule]; 0 <= yyrhs[yyi]; yyi++)
    YYFPRINTF (stderr, "%s ", yytname [yyrhs[yyi]]);
  YYFPRINTF (stderr, "-> %s\n", yytname [yyr1[yyrule]]);
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (Rule);		\
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YYDSYMPRINT(Args)
# define YYDSYMPRINTF(Title, Token, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef	YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   SIZE_MAX < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#if YYMAXDEPTH == 0
# undef YYMAXDEPTH
#endif

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif



#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined (__GLIBC__) && defined (_STRING_H)
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
static YYSIZE_T
#   if defined (__STDC__) || defined (__cplusplus)
yystrlen (const char *yystr)
#   else
yystrlen (yystr)
     const char *yystr;
#   endif
{
  register const char *yys = yystr;

  while (*yys++ != '\0')
    continue;

  return yys - yystr - 1;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined (__GLIBC__) && defined (_STRING_H) && defined (_GNU_SOURCE)
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
#   if defined (__STDC__) || defined (__cplusplus)
yystpcpy (char *yydest, const char *yysrc)
#   else
yystpcpy (yydest, yysrc)
     char *yydest;
     const char *yysrc;
#   endif
{
  register char *yyd = yydest;
  register const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

#endif /* !YYERROR_VERBOSE */



#if YYDEBUG
/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if defined (__STDC__) || defined (__cplusplus)
static void
yysymprint (FILE *yyoutput, int yytype, YYSTYPE *yyvaluep)
#else
static void
yysymprint (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  /* Pacify ``unused variable'' warnings.  */
  (void) yyvaluep;

  if (yytype < YYNTOKENS)
    {
      YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
# ifdef YYPRINT
      YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
    }
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  switch (yytype)
    {
      default:
        break;
    }
  YYFPRINTF (yyoutput, ")");
}

#endif /* ! YYDEBUG */
/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

#if defined (__STDC__) || defined (__cplusplus)
static void
yydestruct (int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yytype, yyvaluep)
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  /* Pacify ``unused variable'' warnings.  */
  (void) yyvaluep;

  switch (yytype)
    {

      default:
        break;
    }
}


/* Prevent warnings from -Wmissing-prototypes.  */

#ifdef YYPARSE_PARAM
# if defined (__STDC__) || defined (__cplusplus)
int yyparse (void *YYPARSE_PARAM);
# else
int yyparse ();
# endif
#else /* ! YYPARSE_PARAM */
#if defined (__STDC__) || defined (__cplusplus)
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */



/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;



/*----------.
| yyparse.  |
`----------*/

#ifdef YYPARSE_PARAM
# if defined (__STDC__) || defined (__cplusplus)
int yyparse (void *YYPARSE_PARAM)
# else
int yyparse (YYPARSE_PARAM)
  void *YYPARSE_PARAM;
# endif
#else /* ! YYPARSE_PARAM */
#if defined (__STDC__) || defined (__cplusplus)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{
  
  register int yystate;
  register int yyn;
  int yyresult;
  /* Number of tokens to shift before error messages enabled.  */
  int yyerrstatus;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;

  /* Three stacks and their tools:
     `yyss': related to states,
     `yyvs': related to semantic values,
     `yyls': related to locations.

     Refer to the stacks thru separate pointers, to allow yyoverflow
     to reallocate them elsewhere.  */

  /* The state stack.  */
  short	yyssa[YYINITDEPTH];
  short *yyss = yyssa;
  register short *yyssp;

  /* The semantic value stack.  */
  YYSTYPE yyvsa[YYINITDEPTH];
  YYSTYPE *yyvs = yyvsa;
  register YYSTYPE *yyvsp;



#define YYPOPSTACK   (yyvsp--, yyssp--)

  YYSIZE_T yystacksize = YYINITDEPTH;

  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;


  /* When reducing, the number of symbols on the RHS of the reduced
     rule.  */
  int yylen;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY;		/* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */

  yyssp = yyss;
  yyvsp = yyvs;

  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed. so pushing a state here evens the stacks.
     */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
	/* Give user a chance to reallocate the stack. Use copies of
	   these so that the &'s don't force the real ones into
	   memory.  */
	YYSTYPE *yyvs1 = yyvs;
	short *yyss1 = yyss;


	/* Each stack pointer address is followed by the size of the
	   data in use in that stack, in bytes.  This used to be a
	   conditional around just the two extra args, but that might
	   be undefined if yyoverflow is a macro.  */
	yyoverflow ("parser stack overflow",
		    &yyss1, yysize * sizeof (*yyssp),
		    &yyvs1, yysize * sizeof (*yyvsp),

		    &yystacksize);

	yyss = yyss1;
	yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyoverflowlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
	goto yyoverflowlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
	yystacksize = YYMAXDEPTH;

      {
	short *yyss1 = yyss;
	union yyalloc *yyptr =
	  (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
	if (! yyptr)
	  goto yyoverflowlab;
	YYSTACK_RELOCATE (yyss);
	YYSTACK_RELOCATE (yyvs);

#  undef YYSTACK_RELOCATE
	if (yyss1 != yyssa)
	  YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;


      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
		  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
	YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

/* Do appropriate processing given the current state.  */
/* Read a lookahead token if we need one and don't already have one.  */
/* yyresume: */

  /* First try to decide what to do without reference to lookahead token.  */

  yyn = yypact[yystate];
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = YYLEX;
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YYDSYMPRINTF ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yyn == 0 || yyn == YYTABLE_NINF)
	goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  if (yyn == YYFINAL)
    YYACCEPT;

  /* Shift the lookahead token.  */
  YYDPRINTF ((stderr, "Shifting token %s, ", yytname[yytoken]));

  /* Discard the token being shifted unless it is eof.  */
  if (yychar != YYEOF)
    yychar = YYEMPTY;

  *++yyvsp = yylval;


  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  yystate = yyn;
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     `$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:
#line 818 "r2l.y"
    {  
    if (common) fprintf(outputfile, "\n;; end of file\n");
    else fprintf(outputfile, "\n%% end of file\n");
    exit(0);
                                        ;}
    break;

  case 4:
#line 825 "r2l.y"
    { evalorprint(yyvsp[-1].LO); 
					  fprintf(outputfile, "\n\n");
                                          otlpos = 0;
                                          heapfringe = 0;
					;}
    break;

  case 10:
#line 839 "r2l.y"
    { yyval.LO = sym_symbolic; ;}
    break;

  case 11:
#line 840 "r2l.y"
    { yyval.LO = sym_algebraic; ;}
    break;

  case 12:
#line 843 "r2l.y"
    { yyval.LO = sym_de; ;}
    break;

  case 13:
#line 844 "r2l.y"
    { yyval.LO = sym_dm; ;}
    break;

  case 14:
#line 845 "r2l.y"
    { yyval.LO = sym_ds; ;}
    break;

  case 15:
#line 848 "r2l.y"
    { yyval.LO = C_nil; ;}
    break;

  case 16:
#line 849 "r2l.y"
    { yyval.LO = cons(yyvsp[-1].LO, yyvsp[0].LO); ;}
    break;

  case 17:
#line 857 "r2l.y"
    { yyval.LO = sym_setq; ;}
    break;

  case 18:
#line 858 "r2l.y"
    { yyval.LO = sym_or; ;}
    break;

  case 19:
#line 859 "r2l.y"
    { yyval.LO = sym_and; ;}
    break;

  case 20:
#line 860 "r2l.y"
    { yyval.LO = sym_member; ;}
    break;

  case 21:
#line 861 "r2l.y"
    { yyval.LO = sym_memq; ;}
    break;

  case 22:
#line 862 "r2l.y"
    { yyval.LO = sym_equal; ;}
    break;

  case 23:
#line 863 "r2l.y"
    { yyval.LO = sym_neq; ;}
    break;

  case 24:
#line 864 "r2l.y"
    { yyval.LO = sym_eq; ;}
    break;

  case 25:
#line 865 "r2l.y"
    { yyval.LO = sym_geq; ;}
    break;

  case 26:
#line 866 "r2l.y"
    { yyval.LO = sym_greaterp; ;}
    break;

  case 27:
#line 867 "r2l.y"
    { yyval.LO = sym_leq; ;}
    break;

  case 28:
#line 868 "r2l.y"
    { yyval.LO = sym_lessp; ;}
    break;

  case 29:
#line 869 "r2l.y"
    { yyval.LO = sym_freeof; ;}
    break;

  case 30:
#line 870 "r2l.y"
    { yyval.LO = sym_plus; ;}
    break;

  case 31:
#line 871 "r2l.y"
    { yyval.LO = sym_difference; ;}
    break;

  case 32:
#line 872 "r2l.y"
    { yyval.LO = sym_times; ;}
    break;

  case 33:
#line 873 "r2l.y"
    { yyval.LO = sym_quotient; ;}
    break;

  case 34:
#line 874 "r2l.y"
    { yyval.LO = sym_expt; ;}
    break;

  case 35:
#line 875 "r2l.y"
    { yyval.LO = sym_cons; ;}
    break;

  case 36:
#line 878 "r2l.y"
    { yyval.LO = sym_not; ;}
    break;

  case 37:
#line 879 "r2l.y"
    { yyval.LO = sym_plus; ;}
    break;

  case 38:
#line 880 "r2l.y"
    { yyval.LO = sym_minus; ;}
    break;

  case 39:
#line 883 "r2l.y"
    { yyval.LO = cons(yyvsp[0].LO, C_nil); ;}
    break;

  case 40:
#line 884 "r2l.y"
    { yyval.LO = list2(yyvsp[-1].LO, yyvsp[0].LO); ;}
    break;

  case 41:
#line 885 "r2l.y"
    { yyval.LO = cons(yyvsp[-2].LO, C_nil); ;}
    break;

  case 42:
#line 887 "r2l.y"
    { yyval.LO = cons(yyvsp[-3].LO, cons(yyvsp[-1].LO, yyvsp[0].LO)); ;}
    break;

  case 43:
#line 888 "r2l.y"
    { yyval.LO = list2(yyvsp[-1].LO, yyvsp[0].LO); ;}
    break;

  case 44:
#line 889 "r2l.y"
    { yyval.LO = list3(yyvsp[-1].LO, yyvsp[-2].LO, yyvsp[0].LO); ;}
    break;

  case 45:
#line 893 "r2l.y"
    { yyval.LO = list4(sym_de, qcar(yyvsp[-2].LO), qcdr(yyvsp[-2].LO), yyvsp[0].LO); ;}
    break;

  case 46:
#line 895 "r2l.y"
    { yyval.LO = list4(sym_de, qcar(yyvsp[-2].LO), qcdr(yyvsp[-2].LO), yyvsp[0].LO); ;}
    break;

  case 47:
#line 897 "r2l.y"
    { yyval.LO = list4(yyvsp[-4].LO, qcar(yyvsp[-2].LO), qcdr(yyvsp[-2].LO), yyvsp[0].LO); ;}
    break;

  case 48:
#line 899 "r2l.y"
    { yyval.LO = list4(yyvsp[-4].LO, qcar(yyvsp[-2].LO), qcdr(yyvsp[-2].LO), yyvsp[0].LO); ;}
    break;

  case 50:
#line 903 "r2l.y"
    { yyval.LO = sym_in; ;}
    break;

  case 51:
#line 904 "r2l.y"
    { yyval.LO = sym_on; ;}
    break;

  case 52:
#line 907 "r2l.y"
    { yyval.LO = cons(yyvsp[0].LO, C_nil); ;}
    break;

  case 53:
#line 908 "r2l.y"
    { yyval.LO = cons(yyvsp[-2].LO, yyvsp[0].LO); ;}
    break;

  case 55:
#line 917 "r2l.y"
    { yyval.LO = list2(yyvsp[-1].LO, cons(sym_list, yyvsp[0].LO)); ;}
    break;

  case 56:
#line 927 "r2l.y"
    { yyval.LO = list3(sym_cond, 
                                                       list2(yyvsp[-4].LO, yyvsp[-2].LO),
                                                       list2(sym_t, yyvsp[0].LO)); ;}
    break;

  case 57:
#line 930 "r2l.y"
    { yyval.LO = list2(sym_cond,
                                                       list2(yyvsp[-2].LO, yyvsp[0].LO)); ;}
    break;

  case 58:
#line 934 "r2l.y"
    { yyval.LO = cons(find_symbol("1"), yyvsp[0].LO); ;}
    break;

  case 59:
#line 935 "r2l.y"
    { yyval.LO = cons(yyvsp[-2].LO, yyvsp[0].LO); ;}
    break;

  case 60:
#line 938 "r2l.y"
    { yyval.LO = sym_do; ;}
    break;

  case 61:
#line 939 "r2l.y"
    { yyval.LO = sym_sum; ;}
    break;

  case 62:
#line 940 "r2l.y"
    { yyval.LO = sym_collect; ;}
    break;

  case 63:
#line 943 "r2l.y"
    { yyval.LO = sym_in; ;}
    break;

  case 64:
#line 944 "r2l.y"
    { yyval.LO = sym_on; ;}
    break;

  case 65:
#line 948 "r2l.y"
    { yyval.LO = make_for(yyvsp[-5].LO, yyvsp[-3].LO, qcar(yyvsp[-2].LO), qcdr(yyvsp[-2].LO), yyvsp[-1].LO, yyvsp[0].LO); ;}
    break;

  case 66:
#line 950 "r2l.y"
    { yyval.LO = make_foreach(yyvsp[-4].LO, yyvsp[-3].LO, yyvsp[-2].LO, yyvsp[-1].LO, yyvsp[0].LO); ;}
    break;

  case 67:
#line 952 "r2l.y"
    { yyval.LO = make_foreach(yyvsp[-4].LO, yyvsp[-3].LO, yyvsp[-2].LO, yyvsp[-1].LO, yyvsp[0].LO); ;}
    break;

  case 68:
#line 955 "r2l.y"
    {
       intptr_t lab1 = genlabel();
       yyval.LO = list6(sym_prog, C_nil, lab1,
                  list2(sym_cond, list2(list2(sym_null, yyvsp[-2].LO), list2(sym_return, C_nil))),
                  yyvsp[0].LO,
                  list2(sym_go, lab1)); ;}
    break;

  case 69:
#line 963 "r2l.y"
    {
       intptr_t lab1 = genlabel();
       yyval.LO = list5(sym_prog, C_nil, lab1,
                  yyvsp[-2].LO,
                  list2(sym_cond, list2(list2(sym_null, yyvsp[0].LO), list2(sym_go, lab1)))); ;}
    break;

  case 70:
#line 970 "r2l.y"
    { yyval.LO = list2(sym_return, C_nil); ;}
    break;

  case 71:
#line 971 "r2l.y"
    { yyval.LO = list2(sym_return, yyvsp[0].LO); ;}
    break;

  case 72:
#line 974 "r2l.y"
    { yyval.LO = list2(sym_go, yyvsp[0].LO); ;}
    break;

  case 73:
#line 975 "r2l.y"
    { yyval.LO = list2(sym_go, yyvsp[0].LO); ;}
    break;

  case 74:
#line 976 "r2l.y"
    { yyval.LO = list2(sym_go, yyvsp[0].LO); ;}
    break;

  case 75:
#line 979 "r2l.y"
    { yyval.LO = C_nil; ;}
    break;

  case 76:
#line 980 "r2l.y"
    { yyval.LO = C_nil; ;}
    break;

  case 77:
#line 981 "r2l.y"
    { yyval.LO = cons(yyvsp[-1].LO, yyvsp[0].LO); ;}
    break;

  case 78:
#line 984 "r2l.y"
    { yyval.LO = cons(sym_progn, cons(yyvsp[-1].LO, yyvsp[0].LO)); ;}
    break;

  case 79:
#line 987 "r2l.y"
    { yyval.LO = C_nil; ;}
    break;

  case 80:
#line 989 "r2l.y"
    { yyval.LO = cons(yyvsp[-1].LO, yyvsp[0].LO); ;}
    break;

  case 81:
#line 991 "r2l.y"
    { yyval.LO = cons(yyvsp[-1].LO, yyvsp[0].LO); ;}
    break;

  case 82:
#line 995 "r2l.y"
    { yyval.LO = cons(yyvsp[-1].LO, yyvsp[0].LO); ;}
    break;

  case 83:
#line 997 "r2l.y"
    { yyval.LO = cons(yyvsp[-1].LO, yyvsp[0].LO); ;}
    break;

  case 85:
#line 1002 "r2l.y"
    { yyval.LO = append(yyvsp[-1].LO, yyvsp[0].LO); ;}
    break;

  case 86:
#line 1005 "r2l.y"
    { yyval.LO = C_nil; ;}
    break;

  case 87:
#line 1006 "r2l.y"
    { yyval.LO = cons(yyvsp[-1].LO, C_nil); ;}
    break;

  case 88:
#line 1007 "r2l.y"
    { yyval.LO = cons(yyvsp[-2].LO, yyvsp[0].LO); ;}
    break;

  case 89:
#line 1008 "r2l.y"
    { yyval.LO = cons(yyvsp[-2].LO, yyvsp[0].LO); ;}
    break;

  case 90:
#line 1009 "r2l.y"
    { yyval.LO = yyvsp[0].LO; ;}
    break;

  case 91:
#line 1013 "r2l.y"
    { yyval.LO = cons(sym_prog, cons(yyvsp[-1].LO, yyvsp[0].LO)); ;}
    break;

  case 92:
#line 1014 "r2l.y"
    { yyval.LO = cons(sym_prog, cons(C_nil, yyvsp[0].LO)); ;}
    break;

  case 93:
#line 1017 "r2l.y"
    { yyval.LO = C_nil; ;}
    break;

  case 94:
#line 1019 "r2l.y"
    { yyval.LO = cons(yyvsp[-1].LO, yyvsp[0].LO); ;}
    break;

  case 95:
#line 1023 "r2l.y"
    { yyval.LO = list3(sym_lambda, ncons(yyvsp[-2].LO), yyvsp[-1].LO); ;}
    break;

  case 96:
#line 1025 "r2l.y"
    { yyval.LO = list3(sym_lambda, C_nil, yyvsp[0].LO); ;}
    break;

  case 97:
#line 1027 "r2l.y"
    { yyval.LO = list3(sym_lambda, cons(yyvsp[-3].LO, yyvsp[-2].LO), yyvsp[0].LO); ;}
    break;

  case 100:
#line 1040 "r2l.y"
    { yyval.LO = make_where(yyvsp[-4].LO, yyvsp[-2].LO, yyvsp[0].LO); ;}
    break;

  case 102:
#line 1045 "r2l.y"
    { yyval.LO = make_where(yyvsp[-4].LO, yyvsp[-2].LO, yyvsp[0].LO); ;}
    break;

  case 104:
#line 1049 "r2l.y"
    { yyval.LO = list3(sym_setq, yyvsp[-2].LO, yyvsp[0].LO); ;}
    break;

  case 106:
#line 1053 "r2l.y"
    { yyval.LO = list3(sym_setq, yyvsp[-2].LO, yyvsp[0].LO); ;}
    break;

  case 108:
#line 1057 "r2l.y"
    { yyval.LO = ncons(yyvsp[0].LO); ;}
    break;

  case 109:
#line 1058 "r2l.y"
    { yyval.LO = cons(yyvsp[-2].LO, yyvsp[0].LO); ;}
    break;

  case 110:
#line 1060 "r2l.y"
    { yyval.LO = cons(sym_or, cons(yyvsp[-2].LO, yyvsp[0].LO)); ;}
    break;

  case 112:
#line 1064 "r2l.y"
    { yyval.LO = ncons(yyvsp[0].LO); ;}
    break;

  case 113:
#line 1065 "r2l.y"
    { yyval.LO = cons(yyvsp[-2].LO, yyvsp[0].LO); ;}
    break;

  case 114:
#line 1067 "r2l.y"
    { yyval.LO = cons(sym_or, cons(yyvsp[-2].LO, yyvsp[0].LO)); ;}
    break;

  case 116:
#line 1071 "r2l.y"
    { yyval.LO = ncons(yyvsp[0].LO); ;}
    break;

  case 117:
#line 1072 "r2l.y"
    { yyval.LO = cons(yyvsp[-2].LO, yyvsp[0].LO); ;}
    break;

  case 118:
#line 1074 "r2l.y"
    { yyval.LO = cons(sym_and, cons(yyvsp[-2].LO, yyvsp[0].LO)); ;}
    break;

  case 120:
#line 1078 "r2l.y"
    { yyval.LO = ncons(yyvsp[0].LO); ;}
    break;

  case 121:
#line 1079 "r2l.y"
    { yyval.LO = cons(yyvsp[-2].LO, yyvsp[0].LO); ;}
    break;

  case 122:
#line 1081 "r2l.y"
    { yyval.LO = cons(sym_and, cons(yyvsp[-2].LO, yyvsp[0].LO)); ;}
    break;

  case 124:
#line 1085 "r2l.y"
    { yyval.LO = list2(sym_not, yyvsp[0].LO); ;}
    break;

  case 126:
#line 1089 "r2l.y"
    { yyval.LO = list2(sym_not, yyvsp[0].LO); ;}
    break;

  case 128:
#line 1093 "r2l.y"
    { yyval.LO = list3(sym_member, yyvsp[-2].LO, yyvsp[0].LO); ;}
    break;

  case 129:
#line 1094 "r2l.y"
    { yyval.LO = list3(sym_memq, yyvsp[-2].LO, yyvsp[0].LO); ;}
    break;

  case 130:
#line 1095 "r2l.y"
    { yyval.LO = list3(sym_equal, yyvsp[-2].LO, yyvsp[0].LO); ;}
    break;

  case 131:
#line 1096 "r2l.y"
    { yyval.LO = list3(sym_neq, yyvsp[-2].LO, yyvsp[0].LO); ;}
    break;

  case 132:
#line 1097 "r2l.y"
    { yyval.LO = list3(sym_eq, yyvsp[-2].LO, yyvsp[0].LO); ;}
    break;

  case 133:
#line 1098 "r2l.y"
    { yyval.LO = list3(sym_geq, yyvsp[-2].LO, yyvsp[0].LO); ;}
    break;

  case 134:
#line 1099 "r2l.y"
    { yyval.LO = list3(sym_greaterp, yyvsp[-2].LO, yyvsp[0].LO); ;}
    break;

  case 135:
#line 1100 "r2l.y"
    { yyval.LO = list3(sym_leq, yyvsp[-2].LO, yyvsp[0].LO); ;}
    break;

  case 136:
#line 1101 "r2l.y"
    { yyval.LO = list3(sym_lessp, yyvsp[-2].LO, yyvsp[0].LO); ;}
    break;

  case 137:
#line 1102 "r2l.y"
    { yyval.LO = list3(sym_freeof, yyvsp[-2].LO, yyvsp[0].LO); ;}
    break;

  case 139:
#line 1106 "r2l.y"
    { yyval.LO = list3(sym_member, yyvsp[-2].LO, yyvsp[0].LO); ;}
    break;

  case 140:
#line 1107 "r2l.y"
    { yyval.LO = list3(sym_memq, yyvsp[-2].LO, yyvsp[0].LO); ;}
    break;

  case 141:
#line 1108 "r2l.y"
    { yyval.LO = list3(sym_equal, yyvsp[-2].LO, yyvsp[0].LO); ;}
    break;

  case 142:
#line 1109 "r2l.y"
    { yyval.LO = list3(sym_neq, yyvsp[-2].LO, yyvsp[0].LO); ;}
    break;

  case 143:
#line 1110 "r2l.y"
    { yyval.LO = list3(sym_eq, yyvsp[-2].LO, yyvsp[0].LO); ;}
    break;

  case 144:
#line 1111 "r2l.y"
    { yyval.LO = list3(sym_geq, yyvsp[-2].LO, yyvsp[0].LO); ;}
    break;

  case 145:
#line 1112 "r2l.y"
    { yyval.LO = list3(sym_greaterp, yyvsp[-2].LO, yyvsp[0].LO); ;}
    break;

  case 146:
#line 1113 "r2l.y"
    { yyval.LO = list3(sym_leq, yyvsp[-2].LO, yyvsp[0].LO); ;}
    break;

  case 147:
#line 1114 "r2l.y"
    { yyval.LO = list3(sym_lessp, yyvsp[-2].LO, yyvsp[0].LO); ;}
    break;

  case 148:
#line 1115 "r2l.y"
    { yyval.LO = list3(sym_freeof, yyvsp[-2].LO, yyvsp[0].LO); ;}
    break;

  case 150:
#line 1119 "r2l.y"
    { yyval.LO = list2(sym_not, yyvsp[0].LO); ;}
    break;

  case 152:
#line 1123 "r2l.y"
    { yyval.LO = list2(sym_not, yyvsp[0].LO); ;}
    break;

  case 154:
#line 1127 "r2l.y"
    { yyval.LO = ncons(yyvsp[0].LO); ;}
    break;

  case 155:
#line 1128 "r2l.y"
    { yyval.LO = cons(yyvsp[-2].LO, yyvsp[0].LO); ;}
    break;

  case 156:
#line 1130 "r2l.y"
    { yyval.LO = cons(sym_plus, cons(yyvsp[-2].LO, yyvsp[0].LO)); ;}
    break;

  case 158:
#line 1134 "r2l.y"
    { yyval.LO = ncons(yyvsp[0].LO); ;}
    break;

  case 159:
#line 1135 "r2l.y"
    { yyval.LO = cons(yyvsp[-2].LO, yyvsp[0].LO); ;}
    break;

  case 160:
#line 1137 "r2l.y"
    { yyval.LO = cons(sym_plus, cons(yyvsp[-2].LO, yyvsp[0].LO)); ;}
    break;

  case 162:
#line 1141 "r2l.y"
    { yyval.LO = list2(sym_not, yyvsp[0].LO); ;}
    break;

  case 164:
#line 1145 "r2l.y"
    { yyval.LO = list3(sym_difference, yyvsp[-2].LO, yyvsp[0].LO); ;}
    break;

  case 166:
#line 1149 "r2l.y"
    { yyval.LO = list2(sym_not, yyvsp[0].LO); ;}
    break;

  case 168:
#line 1153 "r2l.y"
    { yyval.LO = list3(sym_difference, yyvsp[-2].LO, yyvsp[0].LO); ;}
    break;

  case 170:
#line 1157 "r2l.y"
    { yyval.LO = list2(sym_not, yyvsp[0].LO); ;}
    break;

  case 172:
#line 1161 "r2l.y"
    { yyval.LO = yyvsp[0].LO; ;}
    break;

  case 173:
#line 1162 "r2l.y"
    { yyval.LO = list2(sym_minus, yyvsp[0].LO); ;}
    break;

  case 175:
#line 1166 "r2l.y"
    { yyval.LO = list2(sym_not, yyvsp[0].LO); ;}
    break;

  case 177:
#line 1170 "r2l.y"
    { yyval.LO = yyvsp[0].LO; ;}
    break;

  case 178:
#line 1171 "r2l.y"
    { yyval.LO = list2(sym_minus, yyvsp[0].LO); ;}
    break;

  case 180:
#line 1175 "r2l.y"
    { yyval.LO = ncons(yyvsp[0].LO); ;}
    break;

  case 181:
#line 1176 "r2l.y"
    { yyval.LO = cons(yyvsp[-2].LO, yyvsp[0].LO); ;}
    break;

  case 182:
#line 1178 "r2l.y"
    { yyval.LO = cons(sym_times, cons(yyvsp[-2].LO, yyvsp[0].LO)); ;}
    break;

  case 184:
#line 1182 "r2l.y"
    { yyval.LO = ncons(yyvsp[0].LO); ;}
    break;

  case 185:
#line 1183 "r2l.y"
    { yyval.LO = cons(yyvsp[-2].LO, yyvsp[0].LO); ;}
    break;

  case 186:
#line 1185 "r2l.y"
    { yyval.LO = cons(sym_times, cons(yyvsp[-2].LO, yyvsp[0].LO)); ;}
    break;

  case 188:
#line 1189 "r2l.y"
    { yyval.LO = list2(sym_not, yyvsp[0].LO); ;}
    break;

  case 189:
#line 1190 "r2l.y"
    { yyval.LO = yyvsp[0].LO; ;}
    break;

  case 190:
#line 1191 "r2l.y"
    { yyval.LO = list2(sym_minus, yyvsp[0].LO); ;}
    break;

  case 192:
#line 1195 "r2l.y"
    { yyval.LO = list3(sym_quotient, yyvsp[-2].LO, yyvsp[0].LO); ;}
    break;

  case 194:
#line 1199 "r2l.y"
    { yyval.LO = list2(sym_not, yyvsp[0].LO); ;}
    break;

  case 195:
#line 1200 "r2l.y"
    { yyval.LO = yyvsp[0].LO; ;}
    break;

  case 196:
#line 1201 "r2l.y"
    { yyval.LO = list2(sym_minus, yyvsp[0].LO); ;}
    break;

  case 198:
#line 1205 "r2l.y"
    { yyval.LO = list3(sym_quotient, yyvsp[-2].LO, yyvsp[0].LO); ;}
    break;

  case 200:
#line 1209 "r2l.y"
    { yyval.LO = list2(sym_not, yyvsp[0].LO); ;}
    break;

  case 201:
#line 1210 "r2l.y"
    { yyval.LO = yyvsp[0].LO; ;}
    break;

  case 202:
#line 1211 "r2l.y"
    { yyval.LO = list2(sym_minus, yyvsp[0].LO); ;}
    break;

  case 204:
#line 1215 "r2l.y"
    { yyval.LO = list3(sym_expt, yyvsp[-2].LO, yyvsp[0].LO); ;}
    break;

  case 206:
#line 1219 "r2l.y"
    { yyval.LO = list2(sym_not, yyvsp[0].LO); ;}
    break;

  case 207:
#line 1220 "r2l.y"
    { yyval.LO = yyvsp[0].LO; ;}
    break;

  case 208:
#line 1221 "r2l.y"
    { yyval.LO = list2(sym_minus, yyvsp[0].LO); ;}
    break;

  case 210:
#line 1225 "r2l.y"
    { yyval.LO = list3(sym_expt, yyvsp[-2].LO, yyvsp[0].LO); ;}
    break;

  case 212:
#line 1229 "r2l.y"
    { yyval.LO = list2(sym_not, yyvsp[0].LO); ;}
    break;

  case 213:
#line 1230 "r2l.y"
    { yyval.LO = yyvsp[0].LO; ;}
    break;

  case 214:
#line 1231 "r2l.y"
    { yyval.LO = list2(sym_minus, yyvsp[0].LO); ;}
    break;

  case 216:
#line 1235 "r2l.y"
    { yyval.LO = list3(sym_cons, yyvsp[-2].LO, yyvsp[0].LO); ;}
    break;

  case 225:
#line 1244 "r2l.y"
    { yyval.LO = ncons(yyvsp[0].LO); ;}
    break;

  case 226:
#line 1247 "r2l.y"
    { yyval.LO = list2(sym_not, yyvsp[0].LO); ;}
    break;

  case 227:
#line 1248 "r2l.y"
    { yyval.LO = yyvsp[0].LO; ;}
    break;

  case 228:
#line 1249 "r2l.y"
    { yyval.LO = list2(sym_minus, yyvsp[0].LO); ;}
    break;

  case 230:
#line 1253 "r2l.y"
    { yyval.LO = list3(sym_cons, yyvsp[-2].LO, yyvsp[0].LO); ;}
    break;

  case 232:
#line 1257 "r2l.y"
    { yyval.LO = C_nil; ;}
    break;

  case 233:
#line 1258 "r2l.y"
    { yyval.LO = C_nil; ;}
    break;

  case 234:
#line 1259 "r2l.y"
    { yyval.LO = cons(yyvsp[-1].LO, yyvsp[0].LO); ;}
    break;

  case 235:
#line 1262 "r2l.y"
    { yyval.LO = yyvsp[-1].LO; ;}
    break;

  case 236:
#line 1265 "r2l.y"
    { yyval.LO = cons(yyvsp[-3].LO, cons(yyvsp[-1].LO,yyvsp[0].LO)); ;}
    break;

  case 237:
#line 1268 "r2l.y"
    { yyval.LO = list3(sym_getv, yyvsp[-3].LO, yyvsp[-1].LO); ;}
    break;

  case 238:
#line 1269 "r2l.y"
    { yyval.LO = cons(yyvsp[-2].LO, C_nil); ;}
    break;

  case 239:
#line 1270 "r2l.y"
    { yyval.LO = cons(yyvsp[-1].LO, cons(yyvsp[0].LO, C_nil)); ;}
    break;

  case 240:
#line 1271 "r2l.y"
    { yyval.LO = cons(yyvsp[-1].LO, yyvsp[0].LO); ;}
    break;

  case 241:
#line 1272 "r2l.y"
    { yyval.LO = list2(yyvsp[-1].LO, yyvsp[0].LO); ;}
    break;

  case 243:
#line 1276 "r2l.y"
    { yyval.LO = yyvsp[0].LO; ;}
    break;

  case 244:
#line 1277 "r2l.y"
    { yyval.LO = yyvsp[0].LO; ;}
    break;

  case 245:
#line 1278 "r2l.y"
    { yyval.LO = C_nil; ;}
    break;

  case 246:
#line 1279 "r2l.y"
    { yyval.LO = cons(sym_list, cons(yyvsp[-1].LO, yyvsp[0].LO)); ;}
    break;

  case 247:
#line 1280 "r2l.y"
    { yyval.LO = cons(sym_setq, yyvsp[0].LO); ;}
    break;

  case 248:
#line 1281 "r2l.y"
    { yyval.LO = cons(sym_or, yyvsp[0].LO); ;}
    break;

  case 249:
#line 1282 "r2l.y"
    { yyval.LO = cons(sym_and, yyvsp[0].LO); ;}
    break;

  case 250:
#line 1283 "r2l.y"
    { yyval.LO = cons(sym_member, yyvsp[0].LO); ;}
    break;

  case 251:
#line 1284 "r2l.y"
    { yyval.LO = cons(sym_memq, yyvsp[0].LO); ;}
    break;

  case 252:
#line 1285 "r2l.y"
    { yyval.LO = cons(sym_neq, yyvsp[0].LO); ;}
    break;

  case 253:
#line 1286 "r2l.y"
    { yyval.LO = cons(sym_eq, yyvsp[0].LO); ;}
    break;

  case 254:
#line 1287 "r2l.y"
    { yyval.LO = cons(sym_geq, yyvsp[0].LO); ;}
    break;

  case 255:
#line 1288 "r2l.y"
    { yyval.LO = cons(sym_leq, yyvsp[0].LO); ;}
    break;

  case 256:
#line 1289 "r2l.y"
    { yyval.LO = cons(sym_freeof, yyvsp[0].LO); ;}
    break;


    }

/* Line 999 of yacc.c.  */
#line 3417 "r2l.tab.c"

  yyvsp -= yylen;
  yyssp -= yylen;


  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;


  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
yyerrlab:
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if YYERROR_VERBOSE
      yyn = yypact[yystate];

      if (YYPACT_NINF < yyn && yyn < YYLAST)
	{
	  YYSIZE_T yysize = 0;
	  int yytype = YYTRANSLATE (yychar);
	  const char* yyprefix;
	  char *yymsg;
	  int yyx;

	  /* Start YYX at -YYN if negative to avoid negative indexes in
	     YYCHECK.  */
	  int yyxbegin = yyn < 0 ? -yyn : 0;

	  /* Stay within bounds of both yycheck and yytname.  */
	  int yychecklim = YYLAST - yyn;
	  int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
	  int yycount = 0;

	  yyprefix = ", expecting ";
	  for (yyx = yyxbegin; yyx < yyxend; ++yyx)
	    if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
	      {
		yysize += yystrlen (yyprefix) + yystrlen (yytname [yyx]);
		yycount += 1;
		if (yycount == 5)
		  {
		    yysize = 0;
		    break;
		  }
	      }
	  yysize += (sizeof ("syntax error, unexpected ")
		     + yystrlen (yytname[yytype]));
	  yymsg = (char *) YYSTACK_ALLOC (yysize);
	  if (yymsg != 0)
	    {
	      char *yyp = yystpcpy (yymsg, "syntax error, unexpected ");
	      yyp = yystpcpy (yyp, yytname[yytype]);

	      if (yycount < 5)
		{
		  yyprefix = ", expecting ";
		  for (yyx = yyxbegin; yyx < yyxend; ++yyx)
		    if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
		      {
			yyp = yystpcpy (yyp, yyprefix);
			yyp = yystpcpy (yyp, yytname[yyx]);
			yyprefix = " or ";
		      }
		}
	      yyerror (yymsg);
	      YYSTACK_FREE (yymsg);
	    }
	  else
	    yyerror ("syntax error; also virtual memory exhausted");
	}
      else
#endif /* YYERROR_VERBOSE */
	yyerror ("syntax error");
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
	 error, discard it.  */

      /* Return failure if at end of input.  */
      if (yychar == YYEOF)
        {
	  /* Pop the error token.  */
          YYPOPSTACK;
	  /* Pop the rest of the stack.  */
	  while (yyss < yyssp)
	    {
	      YYDSYMPRINTF ("Error: popping", yystos[*yyssp], yyvsp, yylsp);
	      yydestruct (yystos[*yyssp], yyvsp);
	      YYPOPSTACK;
	    }
	  YYABORT;
        }

      YYDSYMPRINTF ("Error: discarding", yytoken, &yylval, &yylloc);
      yydestruct (yytoken, &yylval);
      yychar = YYEMPTY;

    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*----------------------------------------------------.
| yyerrlab1 -- error raised explicitly by an action.  |
`----------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (yyn != YYPACT_NINF)
	{
	  yyn += YYTERROR;
	  if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
	    {
	      yyn = yytable[yyn];
	      if (0 < yyn)
		break;
	    }
	}

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
	YYABORT;

      YYDSYMPRINTF ("Error: popping", yystos[*yyssp], yyvsp, yylsp);
      yydestruct (yystos[yystate], yyvsp);
      yyvsp--;
      yystate = *--yyssp;

      YY_STACK_PRINT (yyss, yyssp);
    }

  if (yyn == YYFINAL)
    YYACCEPT;

  YYDPRINTF ((stderr, "Shifting error token, "));

  *++yyvsp = yylval;


  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#ifndef yyoverflow
/*----------------------------------------------.
| yyoverflowlab -- parser overflow comes here.  |
`----------------------------------------------*/
yyoverflowlab:
  yyerror ("parser stack overflow");
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
  return yyresult;
}


#line 1302 "r2l.y"



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


