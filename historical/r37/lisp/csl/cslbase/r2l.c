#if defined(__STDC__) || defined(__cplusplus)
#define YYCONST const
#define YYPARAMS(x) x
#define YYDEFUN(name, arglist, args) name(args)
#define YYAND ,
#define YYPTR void *
#else
#define YYCONST
#define YYPARAMS(x) ()
#define YYDEFUN(name, arglist, args) name arglist args;
#define YYAND ;
#define YYPTR char *
#endif
#ifndef lint
YYCONST static char yysccsid[] = "@(#)yaccpar	1.8 (Berkeley +Cygnus.28) 01/20/91";
#endif
#define YYBYACC 1
#ifndef YYDONT_INCLUDE_STDIO
#include <stdio.h>
#endif
#ifdef __cplusplus
#include <stdlib.h> /* for malloc/realloc/free */
#endif
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


/* Signature: 7db71bcc 21-Apr-2002 */


#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

int *heap;
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
        fprintf(outputfile, "\n;; RLISP to LISP converter. A C Norman 2002\n");
    else fprintf(outputfile, "\n%% RLISP to LISP converter. A C Norman 2002\n");
    fprintf(outputfile, "\n\n");
    if (rights)
    {   char **p = rights_message;
        char *m;
        while ((m = *p++) != NULL)
        {   fprintf(outputfile, "%s%s\n", (common ? ";;" : "%"), m);
        }
        fprintf(outputfile, "\n\n");
    }
    heap = (int *)malloc(2000000); /* Rather arbitrary size! */
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
    int code;
} keyword_code;

static keyword_code operators[];

int find_symbol(char *s)
{
    char *r = (char *)&heap[heapfringe];
    int len = strlen(s);
    strcpy(r, s);
    heapfringe += (len+4)/4;
    return (int)(r+1);
}

static int gennum = 1000;

int genlabel()
{
    char name[32];
    sprintf(name, "lab%d", gennum++);
    return find_symbol(name);
}

int genvar()
{
    char name[32];
    sprintf(name, "var%d", gennum++);
    return find_symbol(name);
}


static int yylex();

#define C_nil ((int)0)
#define qcar(x) (((int *)(x))[0])
#define qcdr(x) (((int *)(x))[1])

int cons(int a, int b)
{
    int *r = &heap[heapfringe];
    heapfringe += 2;
    qcar(r) = a;
    qcdr(r) = b;
    return (int)r;
}

int ncons(int a)
{
    int *r = &heap[heapfringe];
    heapfringe += 2;
    qcar(r) = a;
    qcdr(r) = C_nil;
    return (int)r;
}

int list1(int a)
{
    return cons(a, C_nil);
}

int list2(int a, int b)
{
    return cons(a, cons(b, C_nil));
}

int list3(int a, int b, int c)
{
    return cons(a, cons(b, cons(c, C_nil)));
}

int list4(int a, int b, int c, int d)
{
    return cons(a, cons(b, cons(c, cons(d, C_nil))));
}

int list5(int a, int b, int c, int d, int e)
{
    return cons(a, cons(b, cons(c, cons(d, cons(e, C_nil)))));
}

int list6(int a, int b, int c, int d, int e, int f)
{
    return cons(a, cons(b, cons(c, cons(d, cons(e, cons(f, C_nil))))));
}

int list7(int a, int b, int c, int d, int e, int f, int g)
{
    return cons(a, cons(b, cons(c, cons(d,
                cons(e, cons(f, cons(g, C_nil)))))));
}

int list8(int a, int b, int c, int d, int e, int f, int g, int h)
{
    return cons(a, cons(b, cons(c, cons(d,
                cons(e, cons(f, cons(g, cons(h, C_nil))))))));
}

int list9(int a, int b, int c, int d, int e, int f, int g, int h, int i)
{
    return cons(a, cons(b, cons(c, cons(d,
                cons(e, cons(f, cons(g, cons(h, cons(i, C_nil)))))))));
}

int append(int a, int b)
{
    if (a == C_nil || ((a & 1) != 0)) return b;
    else return cons(qcar(a), append(qcdr(a), b));
}

#define atom(x) ((int)(x)==0 || (((int)(x)) & 1) != 0)

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

void print(int a)
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
    if ((int)a != 0)
    {   checkspace(2);
        fprintf(outputfile, " .");
        if (checkspace(1)) fprintf(outputfile, " ");
        print(a);
    }
    checkspace(1);
    fprintf(outputfile, ")");
}

static void evalorprint(int a)
{
    if (a != C_nil && !atom(a))
    {   int fn = qcar(a);
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
#define sym_repeat                           find_symbol("repeat")
#define sym_while                            find_symbol("while")
#define sym_begin                            find_symbol("begin")
#define sym_end                              find_symbol("end")
#define sym_lsect                            find_symbol("<<")
#define sym_rsect                            find_symbol(">>")
#define sym_go                               find_symbol("go")
#define sym_to                               find_symbol("to")
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

int make_where(int body, int var, int val)
{
    return list2(
       list3(sym_lambda, list1(var), body),
       val);
}

int make_in_do(int var, int input, int body)
{
    int lab1 = genlabel();
    int var1 = genvar();
    return list8(sym_prog, list1(var1),
        list3(sym_setq, var1, input),
    lab1,
        list3(sym_if, list2(sym_null, var1), list2(sym_return, C_nil)),
        list4(sym_prog, list1(var), list3(sym_setq, var, list2(sym_car, var1)), body),
        list3(sym_setq, var1, list2(sym_cdr, var1)),
        list2(sym_go, lab1));
}

int make_on_do(int var, int input, int body)
{
    int lab1 = genlabel();
    return list8(sym_prog, list1(var),
        list3(sym_setq, var, input),
    lab1,
        list3(sym_if, list2(sym_null, var), list2(sym_return, C_nil)),
        body,
        list3(sym_setq, var, list2(sym_cdr, var)),
        list2(sym_go, lab1));
}

int make_in_collect(int var, int input, int body)
{
    int lab1 = genlabel();
    int var1 = genvar();
    int var2 = genvar();
    return list8(sym_prog, list2(var1, var2),
        list3(sym_setq, var1, input),
    lab1,
        list3(sym_if,
            list2(sym_null, var1), 
            list2(sym_return, list2(sym_reversip, var2))),
        list4(sym_prog, list1(var),
            list3(sym_setq, var, list2(sym_car, var1)),
            list3(sym_setq, var2, list3(sym_cons, body, var2))),
        list3(sym_setq, var1, list2(sym_cdr, var1)),
        list2(sym_go, lab1));
}

int make_on_collect(int var, int input, int body)
{
    int lab1 = genlabel();
    int var2 = genvar();
    return list8(sym_prog, list1(var),
        list3(sym_setq, var, input),
    lab1,
        list3(sym_if,
            list2(sym_null, var), 
            list2(sym_return, list2(sym_reversip, var2))),
        list3(sym_setq, var2, list3(sym_cons, body, var2)),
        list3(sym_setq, var, list2(sym_cdr, var)),
        list2(sym_go, lab1));
}

int make_in_sum(int var, int input, int body)
{
    int lab1 = genlabel();
    int var1 = genvar();
    int var2 = genvar();
    return list9(sym_prog, list2(var1, var2),
        list3(sym_setq, var1, input),
        list3(sym_setq, var2, sym_0),
    lab1,
        list3(sym_if,
            list2(sym_null, var1), 
            list2(sym_return, var2)),
        list4(sym_prog, list1(var),
            list3(sym_setq, var, list2(sym_car, var1)),
            list3(sym_setq, var2, list3(sym_plus, body, var2))),
        list3(sym_setq, var1, list2(sym_cdr, var1)),
        list2(sym_go, lab1));
}

int make_foreach(int var, int type, int input, int action, int body)
{
    int inon = 0, docollect = 0;
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

int for_do(int var, int init, int step, int end, int body)
{
    int lab1 = genlabel();
    return list8(sym_prog, list1(var),
        list3(sym_setq, var, init),
    lab1,
        list3(sym_if,
            list2(sym_minusp,
                list3(sym_times, step,
                    list3(sym_difference, end, var))),
            list2(sym_return, C_nil)),
        body,
        list3(sym_setq, var, list3(sym_plus, var, step)),
        list2(sym_go, lab1));
}

int for_collect(int var, int init, int step, int end, int body)
{
    int lab1 = genlabel();
    int var1 = genvar();
    return list8(sym_prog, list2(var, var1),
        list3(sym_setq, var, init),
    lab1,
        list3(sym_if,
            list2(sym_minusp,
                list3(sym_times, step,
                    list3(sym_difference, end, var))),
            list2(sym_return, list2(sym_reversip, var1))),
        list3(sym_setq, var1, list3(sym_cons, body, var1)),
        list3(sym_setq, var, list3(sym_plus, var, step)),
        list2(sym_go, lab1));
}

int for_sum(int var, int init, int step, int end, int body)
{
    int lab1 = genlabel();
    int var1 = genvar();
    return list9(sym_prog, list2(var, var1),
        list3(sym_setq, var, init),
        list3(sym_setq, var1, sym_0),
    lab1,
        list3(sym_if,
            list2(sym_minusp,
                list3(sym_times, step,
                    list3(sym_difference, end, var))),
            list2(sym_return, var1)),
        list3(sym_setq, var1, list3(sym_plus, body, var1)),
        list3(sym_setq, var, list3(sym_plus, var, step)),
        list2(sym_go, lab1));
}

int make_for(int var, int init, int step, int end, int action, int body)
{
    int docollect = 0;
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

int lex_eof = 0;

#line 716 "r2l.c"
#define SETQ 257
#define AND 258
#define OR 259
#define NOT 260
#define MEMBER 261
#define MEMQ 262
#define NEQ 263
#define EQ 264
#define GEQ 265
#define LEQ 266
#define FREEOF 267
#define SYMBOLIC 268
#define ALGEBRAIC 269
#define EXPR 270
#define MACRO 271
#define SMACRO 272
#define PROCEDURE 273
#define FOR 274
#define STEP 275
#define UNTIL 276
#define EACH 277
#define FOREACH 278
#define IN 279
#define ON 280
#define DO 281
#define COLLECT 282
#define SUM 283
#define IF 284
#define THEN 285
#define ELSE 286
#define REPEAT 287
#define WHILE 288
#define BEGIN 289
#define END 290
#define ENDFILE 291
#define LSECT 292
#define RSECT 293
#define GO 294
#define TO 295
#define GOTO 296
#define SCALAR 297
#define INTEGER 298
#define LAMBDA 299
#define SYMBOL 300
#define NUMBER 301
#define STRING 302
#define LIST 303
#define RETURN 304
#define WHERE 305
#define RLISTAT 306
#define ENDSTAT 307
#define HASHIF 308
#define HASHELSE 309
#define HASHELIF 310
#define HASHENDIF 311
#define YYERRCODE 256
static YYCONST short yylhs[] = {                                        -1,
    0,    0,    1,    1,    1,    1,    3,    3,    4,    4,
    5,    5,    5,    6,    6,    7,    7,    7,    7,    7,
    7,    7,    7,    7,    7,    7,    7,    7,    7,    7,
    7,    7,    7,    7,    8,    8,    8,    9,    9,    9,
    9,    9,    9,   10,   10,   10,   10,   11,   11,   11,
   12,   12,    2,    2,   14,   14,   15,   15,   16,   16,
   16,   17,   17,   18,   18,   18,   19,   20,   21,   21,
   22,   22,   22,   23,   23,   23,   24,   25,   25,   25,
   26,   26,   27,   27,   28,   28,   28,   28,   28,   29,
   29,   30,   30,   31,   31,   31,   13,   13,   32,   32,
   33,   33,   34,   34,   35,   35,   38,   38,   37,   37,
   41,   41,   36,   36,   42,   42,   39,   39,   45,   45,
   40,   40,   43,   43,   44,   44,   46,   46,   46,   46,
   46,   46,   46,   46,   46,   46,   46,   47,   47,   47,
   47,   47,   47,   47,   47,   47,   47,   47,   49,   49,
   51,   51,   52,   52,   50,   50,   57,   57,   48,   48,
   53,   53,   56,   56,   54,   54,   55,   55,   58,   58,
   59,   59,   59,   60,   60,   61,   61,   61,   64,   64,
   62,   62,   69,   69,   63,   63,   65,   65,   65,   65,
   68,   68,   66,   66,   66,   66,   67,   67,   72,   72,
   72,   72,   73,   73,   70,   70,   70,   70,   71,   71,
   76,   76,   76,   76,   75,   75,   75,   75,   75,   75,
   75,   75,   75,   75,   78,   78,   78,   78,   74,   74,
   79,   79,   80,   81,   82,   82,   82,   82,   82,   82,
   77,   77,   77,   77,   77,   77,   77,   77,   77,   77,
   77,   77,   83,   83,   83,   83,   83,   83,
};
static YYCONST short yylen[] = {                                         2,
    1,    2,    2,    2,    1,    2,    1,    1,    1,    1,
    1,    1,    1,    1,    3,    1,    1,    1,    1,    1,
    1,    1,    1,    1,    1,    1,    1,    1,    1,    1,
    1,    1,    1,    1,    1,    1,    1,    1,    2,    3,
    4,    2,    3,    4,    5,    5,    6,    1,    1,    1,
    1,    3,    1,    2,    6,    4,    2,    4,    1,    1,
    1,    1,    1,    7,    7,    6,    4,    4,    1,    2,
    2,    2,    3,    1,    2,    3,    3,    1,    3,    3,
    3,    3,    1,    2,    1,    2,    3,    3,    2,    3,
    2,    1,    3,    4,    5,    6,    1,    1,    5,    1,
    5,    1,    3,    1,    3,    1,    1,    3,    3,    1,
    1,    3,    3,    1,    1,    3,    3,    1,    1,    3,
    3,    1,    2,    1,    2,    1,    3,    3,    3,    3,
    3,    3,    3,    3,    3,    3,    1,    3,    3,    3,
    3,    3,    3,    3,    3,    3,    3,    1,    2,    1,
    2,    1,    1,    3,    3,    1,    1,    3,    3,    1,
    2,    1,    3,    1,    2,    1,    3,    1,    2,    1,
    2,    2,    1,    2,    1,    2,    2,    1,    1,    3,
    3,    1,    1,    3,    3,    1,    2,    2,    2,    1,
    3,    1,    2,    2,    2,    1,    3,    1,    2,    2,
    2,    1,    3,    1,    2,    2,    2,    1,    3,    1,
    2,    2,    2,    1,    3,    1,    1,    1,    1,    1,
    1,    1,    1,    1,    2,    2,    2,    1,    3,    1,
    1,    3,    3,    5,    4,    3,    2,    2,    2,    1,
    1,    1,    2,    2,    2,    2,    2,    2,    2,    2,
    2,    2,    1,    1,    1,    1,    1,    1,
};
static YYCONST short yydefred[] = {                                      0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    9,   10,   11,   12,   13,    0,    0,    0,   49,
   50,    0,    0,    0,    0,    0,    1,    0,    0,    0,
    0,  253,  254,  255,  256,    0,   48,  224,    0,    0,
    0,    0,    0,    0,    0,    0,  223,    0,   53,  216,
  217,  218,  219,  220,  221,  257,  258,  222,   97,    0,
  100,  102,    0,  104,  110,    0,  118,    0,  124,  126,
    0,  137,    0,  156,  164,  168,  173,  178,    0,  182,
  192,  198,    0,  210,    0,  242,  241,    0,    0,  243,
  245,  244,    0,  123,  125,  246,  247,  248,  249,  250,
  251,  252,   35,    0,   36,   37,    0,    0,    0,    0,
    0,    0,    0,    0,   85,    0,    0,    0,    7,    8,
    0,    0,   83,    0,   91,    6,    0,    0,   72,   71,
    0,    0,   70,    0,  171,  170,  176,  175,  172,  177,
    0,    2,    3,    0,    4,    0,    0,   54,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,  237,  238,  239,    0,   16,   18,   17,   19,   20,
   22,   23,   24,   26,   28,   39,   21,   25,   27,   29,
   30,   31,   32,   33,   34,    0,    0,   42,    0,    0,
    0,   62,   63,    0,    0,    0,    0,    0,    0,    0,
   86,    0,   89,   84,   90,   74,    0,   77,   73,    0,
   92,    0,    0,    0,  169,  174,  233,    0,    0,    0,
    0,    0,  103,  105,  109,  107,    0,  113,  117,  115,
    0,  121,    0,  152,  127,  150,  138,  128,  139,  130,
  141,  131,  142,  132,  143,  134,  145,  136,  147,  129,
  140,  133,  144,  135,  146,    0,  155,  153,    0,    0,
  162,  159,  163,  167,    0,    0,    0,  181,  179,    0,
    0,  190,  185,    0,    0,    0,  191,  208,  197,  202,
  209,  203,    0,    0,    0,  228,  214,  215,  229,  236,
    0,    0,    0,    0,   40,   43,   44,    0,    0,    0,
    0,   68,   67,    0,   78,   81,   82,   87,   88,   75,
    0,    0,   94,   14,    0,    0,    0,    0,    0,    0,
   52,    0,    0,    0,  149,  151,  161,  165,    0,  187,
  193,  188,  194,  189,  195,    0,  205,  199,  206,  200,
  207,  201,  211,  225,  212,  226,  213,  227,  235,    0,
   41,    0,    0,    0,    0,   59,   61,   60,    0,    0,
    0,    0,   76,   93,    0,    0,   95,   45,    0,   46,
   99,  101,  108,  112,  116,  120,  154,  158,  180,  184,
  231,    0,  234,    0,    0,   57,    0,   66,   55,   80,
   79,   15,   96,   47,    0,   65,    0,   64,  232,   58,
};
static YYCONST short yydgoto[] = {                                      42,
   43,  121,  122,   93,   46,  326,  197,  107,  108,   47,
   48,  148,   49,   50,  365,  369,  204,   51,   52,   53,
   54,   55,  218,   56,  316,  123,  124,  125,   57,  222,
   58,   59,   60,   61,   62,   63,   64,  235,   65,   66,
  238,  239,   67,   68,  242,   69,   70,   71,  245,   72,
  247,  267,  268,  269,   73,   74,  272,  135,   75,  137,
   76,   77,   78,  278,  279,  280,   79,   80,  283,  287,
   81,  289,   82,   83,   84,  298,   85,  299,  393,   86,
   90,   87,   88,
};
static YYCONST short yysindex[] = {                                   1038,
   14,   14,   14, 1303,   14,   14,   14,   14,   14,   14,
   14,    0,    0,    0,    0,    0,  -13, -235, -227,    0,
    0, 1303, 1199, 1303,  -28,   12,    0, 1199, -234, -219,
  -35,    0,    0,    0,    0, 1303,    0,    0, 1358, 1358,
 1303,    0, 1038,   12,   20, -174,    0, 1303,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0, -191,
    0,    0, -124,    0,    0, -131,    0, -120,    0,    0,
   50,    0,  111,    0,    0,    0,    0,    0,   28,    0,
    0,    0,   48,    0,  107,    0,    0,   38, 1303,    0,
    0,    0, -149,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0, 1925,    0,    0, -133,   12, -115,  -99,
 -173, -126, -101,  -88,    0, -103,  -91,  141,    0,    0,
  -23,  151,    0,  -28,    0,    0,  -16,  -87,    0,    0,
    3,  -19,    0, 1358,    0,    0,    0,    0,    0,    0,
  175,    0,    0,  -13,    0,  -56,  -13,    0,  205,  -81,
 1303, 1303, 1303, 1500, 1500, 1500, 1500, 1500, 1500, 1500,
 1500, 1500, 1500, 1553, 1358, 1608, 1659, 1659, 1736, 1449,
 1303,    0,    0,    0,  219,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,  -18,  -72,    0, 1199, -173,
 1303,    0,    0, 1303, 1199, 1303, 1199,   13,   13,  151,
    0,  151,    0,    0,    0,    0, 1148,    0,    0,  -15,
    0, 1199,   33,   12,    0,    0,    0,   12,  -13,   12,
 1303,  223,    0,    0,    0,    0,   21,    0,    0,    0,
   31,    0, 1500,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0, 1553,    0,    0,  243,  249,
    0,    0,    0,    0, 1608, 1608, 1608,    0,    0,  255,
  251,    0,    0, 1659, 1659, 1659,    0,    0,    0,    0,
    0,    0, 1736, 1736, 1736,    0,    0,    0,    0,    0,
   39,  208, 1303,   33,    0,    0,    0, 1303,  -51, -179,
   16,    0,    0, -240,    0,    0,    0,    0,    0,    0,
  -16,    3,    0,    0,   18,   12, 1199, 1199,   12, 1199,
    0, 1303, 1303, 1303,    0,    0,    0,    0, 1553,    0,
    0,    0,    0,    0,    0, 1608,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,   56,
    0, -179, 1303, 1303, -179,    0,    0,    0, 1199, 1199,
   13,   13,    0,    0,   33, 1199,    0,    0, 1199,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0, 1303,    0, 1199,   43,    0, 1199,    0,    0,    0,
    0,    0,    0,    0,   56,    0, 1303,    0,    0,    0,
};
static YYCONST short yyrindex[] = {                                      0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0, 1093,    0,    0,    0,    0,
    0,    0,    0,    0,    0, 1792,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0, 1847,
    0,    0,  930,    0,    0,  970,    0,  904,    0,    0,
  710,    0,  789,    0,    0,    0,    0,    0,  553,    0,
    0,    0,  457,    0,  420,    0,    0,  263,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,   17,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,  101,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0, 1933,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,  983,    0,    0,    0,
  943,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,  849,  668,
    0,    0,    0,    0,    0,    0,    0,    0,    0,  598,
  516,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
 2005,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
};
static YYCONST short yygindex[] = {                                    277,
    0,    1,  -26,   41,  -34, -277,    0,    0, -109,    0,
    0,   95,  -20,    0,    0, -298,  132,    0,    0,    0,
    0,    0,   26,    0, -199,  210,    0,   -9,    0,   27,
    0,    0,    0, -142, -125,    0,    0,    4, -119, -118,
    9,   19,   -1,    2,   35,    0,    0,  -69,  424,  329,
  445,   -4,   82,   84, -150, -127,   22,   15,    6,   23,
   11,    0,    0,    5, -158, -145, -141,  -98,    8, -116,
  -59,  184,   90, -129,  -73, -168,    0,  -40,  -50,  285,
  619,  290,    0,
};
#define YYTABLESIZE 2298
static YYCONST short yytable[] = {                                     126,
   44,  112,   94,  114,  132,   95,  364,  120,  233,  317,
  146,   41,  120,  270,   39,  133,   40,  143,  145,  120,
  141,  224,  305,  113,  281,  234,  361,  149,  127,  105,
  119,  106,  236,  237,  228,  119,  271,  230,  120,  296,
   45,  109,  119,   44,  136,  136,  220,  120,  120,  138,
  138,  291,   38,   89,  139,  120,  314,  371,  146,  372,
  128,  119,  140,  394,  110,  129,  397,  282,  175,  166,
  119,  119,  111,  324,  167,   38,  325,  170,  119,  227,
  130,  199,  303,   45,  244,  244,  244,  244,  244,  244,
  244,  244,  244,  244,  212,  297,  391,  402,  147,  392,
  217,  366,  367,  368,  221,  202,  203,  288,  288,  163,
  161,  162,  213,  150,  215,  270,  340,  342,  344,  329,
   14,   15,   16,  144,  353,  355,  357,  152,  171,  341,
  343,  345,  151,  281,  281,  281,  253,  153,  271,  136,
  253,  168,  253,  253,  138,  253,  253,  253,  225,  301,
  302,  240,  169,  164,  241,  165,  226,  201,  205,  253,
  253,  253,  253,  296,  296,  296,  198,  347,  349,  351,
  136,  400,  401,  244,  206,  138,  282,  282,  282,  273,
  309,  315,  315,  310,  200,  312,  120,  274,  270,  381,
   41,  253,  207,   39,  253,   40,  208,  327,  210,  307,
  318,  328,  319,  330,  281,  311,  382,  313,  209,  119,
  149,  271,  219,  236,  237,  227,  229,  321,  232,  297,
  297,  297,  323,  363,  288,  288,  288,  306,    1,    2,
    3,    4,    5,    6,    7,    8,    9,   10,   11,   12,
   13,   14,   15,   16,   17,   18,  103,  282,  231,   19,
   20,   21,  354,  356,  358,   22,  290,  290,   23,   24,
   25,  115,  303,   28,  131,   29,  211,   30,  116,  117,
   31,  118,   33,   34,   35,   36,  216,   37,   38,  333,
  223,  304,  360,  332,  322,  339,  104,  362,  334,   14,
   15,   16,  144,  165,  217,  221,  346,  167,  240,  376,
  359,  370,  379,  240,  240,  240,  240,  240,  240,  240,
  154,  155,  156,  157,  158,  159,  160,  375,  407,  142,
  240,  240,  240,  240,  240,  331,   25,  377,  378,   28,
  380,  308,  240,  214,  387,  241,  383,   32,   33,   34,
   35,  384,  395,  396,  315,  315,  373,  337,  374,  338,
  389,  292,  385,  390,  409,  240,  240,  253,  253,  253,
  388,  253,  253,  253,  253,  253,  253,  253,  386,  398,
  399,  405,  172,  290,  290,  290,  403,  174,    0,  404,
    0,    0,    0,    0,    0,    0,  410,    0,    0,  253,
  253,    0,  253,    0,  406,    0,    0,  408,    0,    0,
  253,  253,  253,  253,    0,  253,    0,    1,    2,    3,
    4,    5,    6,    7,    8,    9,   10,   11,   12,   13,
   14,   15,   16,   17,   18,    0,    0,    0,   19,   20,
   21,    0,    0,    0,   22,    0,    0,   23,   24,   25,
  115,    0,   28,    0,   29,    0,   30,    0,    0,   31,
  118,   33,   34,   35,   36,  230,   37,   38,    0,    0,
  230,  230,  230,  230,  230,    0,  230,  348,  350,  352,
    0,    0,    0,    0,    0,    0,    0,  230,  230,  230,
  230,  230,  246,  246,  246,  246,  246,  246,  246,  246,
  246,  246,  204,    0,    0,    0,    0,  204,  204,  204,
  204,  204,    0,  204,    0,    0,    0,    0,    0,    0,
    0,    0,  230,  230,  204,  204,  204,  204,  204,  240,
  240,  240,    0,  240,  240,  240,  240,  240,  240,  240,
    0,    0,    0,    0,    0,    0,    0,  240,  240,    0,
    0,    0,    0,  240,  240,  240,    0,  240,  240,  204,
    0,  196,  240,    0,    0,  240,  196,  196,  196,  196,
  196,    0,    0,    0,    0,    0,    0,  240,    0,    0,
    0,  246,    0,  196,  196,  196,  196,  196,  248,  250,
  252,  254,  256,  258,  260,  262,  264,    0,  186,    0,
    0,    0,    0,  186,    0,  186,  186,  186,    0,  249,
  251,  253,  255,  257,  259,  261,  263,  265,  196,    0,
  186,  186,  186,  186,  186,    0,    0,    0,    0,    0,
   91,   92,    0,   96,   97,   98,   99,  100,  101,  102,
    0,    0,    0,  183,    0,    0,    0,    0,  183,    0,
  183,  183,  183,    0,    0,  186,    0,    0,    0,    0,
    0,    0,    0,    0,    0,  183,  183,  183,  183,  183,
    0,    0,    0,    0,    0,    0,  335,    0,    0,    0,
    0,    0,    0,    0,    0,    0,  230,  230,  230,    0,
  230,  230,  230,  230,  230,  230,  230,  336,    0,    0,
  183,    0,    0,    0,  230,  230,    0,    0,    0,    0,
  230,  230,  230,  166,  230,  230,  173,    0,  166,  230,
  166,  166,  230,  204,  204,  204,    0,  204,  204,  204,
  204,  204,  204,  204,  230,  166,  166,  166,  166,  166,
    0,  204,  204,    0,    0,    0,    0,  204,  204,  204,
    0,  204,  204,    0,    0,  148,  204,    0,    0,  204,
  148,    0,    0,  148,    0,    0,    0,    0,    0,    0,
  166,  204,    0,    0,    0,    0,    0,  148,  148,    0,
    0,    0,  196,  196,  196,    0,  196,  196,  196,  196,
  196,  196,  196,    0,    0,    0,    0,    0,    0,    0,
  196,  196,    0,    0,    0,    0,  196,  196,  196,    0,
  196,  196,  148,    0,    0,  196,    0,    0,  196,  186,
  186,  186,    0,  186,  186,  186,  186,  186,  186,  186,
  196,    0,    0,    0,  160,    0,    0,  186,  186,  160,
    0,    0,  160,  186,  186,  186,    0,  186,  186,    0,
    0,    0,  186,    0,    0,  186,  160,  160,  160,  160,
  160,    0,    0,    0,  183,  183,  183,  186,  183,  183,
  183,  183,  183,  183,  183,    0,    0,    0,    0,    0,
    0,    0,  183,  183,    0,    0,    0,    0,  183,  183,
  183,  160,  183,  183,  157,    0,    0,  183,    0,  157,
  183,    0,  157,    0,    0,    0,    0,    0,    0,    0,
    0,    0,  183,    0,    0,    0,  157,  157,  157,  157,
  157,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,  166,  166,  166,    0,  166,  166,
  166,  166,  166,  166,  166,    0,    0,    0,    0,  122,
    0,  157,  166,  166,  122,    0,    0,  122,  166,  166,
  166,    0,  166,  166,    0,    0,    0,  166,    0,    0,
  166,  122,  122,    0,    0,  106,  148,  148,  148,    0,
  106,    0,  166,  106,    0,    0,    0,    0,  119,    0,
    0,    0,    0,  119,  148,  148,  119,  106,  106,    0,
  148,  148,  148,    0,  148,  148,  122,    0,    0,  148,
  119,  119,  148,    0,    0,  114,    0,    0,    0,    0,
  114,    0,    0,  114,  148,    0,    0,    0,  111,    0,
    0,    0,  106,  111,    0,    0,  111,  114,  114,    0,
    0,    0,    0,    0,    0,  119,    0,    0,    0,    0,
  111,  111,    0,    0,    0,  160,  160,  160,    0,  160,
  160,  160,  160,  160,  160,  160,    0,    0,    0,    0,
    0,    0,  114,  160,  160,    0,    0,    0,    0,  160,
  160,  160,    0,  160,  160,  111,    0,   41,  160,    0,
   39,  160,   40,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,  160,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,  157,  157,  157,    0,  157,
  157,  157,  157,  157,  157,  157,    0,    0,    0,    0,
    0,    0,    0,  157,  157,    0,    0,    0,    0,  157,
  157,  157,    5,  157,  157,    5,    0,    5,  157,    0,
    0,  157,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,  157,    0,    0,    0,    0,    0,    0,
  122,    0,  122,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,  122,  122,
    0,    0,    0,    0,  122,  122,  122,   41,  122,  122,
   39,    0,   40,  122,    0,    0,  122,    0,    0,  119,
    0,  119,    0,    0,  106,  106,    0,    0,  122,    0,
  106,  106,  106,    0,  106,  106,    0,  119,  119,  106,
    0,    0,  106,  119,  119,  119,  114,  119,  119,    0,
    0,    0,  119,    0,  106,  119,    0,    0,   41,  111,
    0,   39,    0,   40,  114,  114,    0,  119,    0,    0,
  114,  114,  114,    0,  114,  114,    0,  111,  111,  114,
    0,    0,  114,  111,  111,  111,    0,  111,  111,    0,
    0,    0,  111,    0,  114,  111,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,  111,    0,    0,
    0,    0,    0,    0,    1,    2,    3,    4,    5,    6,
    7,    8,    9,   10,   11,   12,   13,   14,   15,   16,
   17,   18,    0,    0,    0,   19,   20,   21,    0,    0,
    0,   22,    0,    0,   23,   24,   25,   26,   27,   28,
    0,   29,    0,   30,    0,    0,   31,   32,   33,   34,
   35,   36,   41,   37,   38,   39,    0,   40,    0,    5,
    5,    5,    5,    5,    5,    5,    5,    5,    5,    5,
    5,    5,    5,    5,    5,    5,    5,    0,    0,    0,
    5,    5,    5,    0,    0,    0,    5,    0,    0,    5,
    5,    5,    5,    5,    5,    0,    5,    0,    5,    0,
    0,    5,    5,    5,    5,    5,    5,   41,    5,    5,
   39,    0,   40,    0,    1,    2,    3,    4,    5,    6,
    7,    8,    9,   10,   11,   12,   13,   14,   15,   16,
   17,   18,    0,    0,    0,   19,   20,   21,    0,    0,
    0,   22,    0,    0,   23,   24,   25,    0,    0,   28,
  320,   29,    0,   30,    0,    0,   31,   32,   33,   34,
   35,   36,    0,   37,   38,    1,    2,    3,    4,    5,
    6,    7,    8,    9,   10,   11,   12,   13,   14,   15,
   16,   17,   18,    0,    0,    0,   19,   20,   21,    0,
    0,    0,   22,    0,    0,   23,   24,   25,   41,  300,
   28,   39,   29,   40,   30,    0,    0,   31,   32,   33,
   34,   35,   36,    0,   37,   38,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,   41,
    0,    0,   39,    0,   40,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    1,
    2,    3,    4,    5,    6,    7,    8,    9,   10,   11,
   12,   13,   14,   15,   16,   17,   18,    0,    0,    0,
   19,    0,    0,    0,    0,    0,   22,    0,    0,   23,
   24,   25,   41,    0,   28,   39,   29,   40,   30,    0,
    0,   31,   32,   33,   34,   35,   36,    0,    0,   38,
    0,    0,    0,    0,    1,    2,    3,  134,    5,    6,
    7,    8,    9,   10,   11,   12,   13,   14,   15,   16,
   17,   18,    0,    0,    0,   19,    0,    0,    0,    0,
    0,   22,    0,    0,   23,   24,   25,   41,    0,   28,
  276,   29,  277,   30,    0,    0,   31,   32,   33,   34,
   35,   36,    0,    0,   38,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,   41,    0,
    0,  285,    0,  286,    0,    1,    2,    3,    4,    5,
    6,    7,    8,    9,   10,   11,   12,   13,   14,   15,
   16,   17,   18,    0,    0,    0,   19,    0,    0,    0,
    0,    0,   22,    0,    0,   23,   24,   25,    0,    0,
   28,    0,   29,    0,   30,    0,    0,   31,   32,   33,
   34,   35,   36,    0,    0,   38,    1,    2,    3,  243,
    5,    6,    7,    8,    9,   10,   11,   12,   13,   14,
   15,   16,   17,   18,    0,   41,    0,   19,  294,    0,
  295,    0,    0,   22,    0,    0,   23,   24,   25,    0,
    0,   28,    0,   29,    0,   30,    0,    0,   31,   32,
   33,   34,   35,   36,    0,    0,   38,    0,    0,    1,
    2,    3,  266,    5,    6,    7,    8,    9,   10,   11,
   12,   13,   14,   15,   16,   17,   18,   69,    0,    0,
   19,    0,   69,    0,    0,   69,   22,    0,    0,   23,
   24,   25,    0,    0,   28,    0,   29,    0,   30,   69,
   69,   31,   32,   33,   34,   35,   36,    0,    0,   38,
    0,    0,    0,    0,    1,    2,    3,  275,    5,    6,
    7,    8,    9,   10,   11,   12,   13,   14,   15,   16,
   17,   18,   98,    0,   69,   19,    0,   98,    0,    0,
   98,   22,    0,    0,   23,   24,   25,    0,    0,   28,
    0,   29,    0,   30,   98,   98,   31,   32,   33,   34,
   35,   36,    0,    0,   38,    1,    2,    3,  284,    5,
    6,    7,    8,    9,   10,   11,   12,   13,   14,   15,
   16,   17,   18,    0,    0,    0,   19,    0,    0,   98,
    0,    0,   22,    0,    0,   23,   24,   25,    0,    0,
   28,    0,   29,    0,   30,    0,    0,   31,   32,   33,
   34,   35,   36,    0,  196,   38,  192,  190,   51,  191,
  195,  193,    0,   51,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,  189,  187,  188,    0,    0,    0,
   51,   51,    1,    2,    3,  293,    5,    6,    7,    8,
    9,   10,   11,   12,   13,   14,   15,   16,   17,   18,
    0,    0,    0,   19,    0,    0,    0,    0,  194,   22,
    0,    0,   23,   24,   25,   51,    0,   28,    0,   29,
    0,   30,    0,    0,   31,   32,   33,   34,   35,   36,
   56,    0,   38,    0,    0,   56,    0,    0,   56,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,   56,   56,    0,    0,   69,   69,    0,    0,
    0,    0,   69,   69,   69,    0,   69,   69,    0,    0,
    0,   69,    0,    0,   69,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,   56,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,   98,   98,    0,    0,    0,    0,   98,   98,   98,
    0,   98,   98,    0,    0,    0,   98,    0,    0,   98,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,  176,  177,  178,    0,  179,  180,  181,  182,  183,
  184,  185,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,   51,   51,    0,
    0,    0,    0,   51,   51,   51,    0,   51,   51,    0,
    0,    0,   51,    0,  186,   51,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,   56,
   56,    0,    0,    0,    0,   56,   56,   56,    0,   56,
    0,    0,    0,    0,   56,    0,    0,   56,
};
static YYCONST short yycheck[] = {                                      26,
    0,   22,    4,   24,   40,    4,   58,   36,  151,  209,
   45,   40,   36,  164,   43,   36,   45,   44,   45,   36,
   41,   41,   41,   23,  166,  151,  304,   48,   28,   43,
   59,   45,  152,  152,  144,   59,  164,  147,   36,  169,
    0,  277,   59,   43,   39,   40,   44,   36,   36,   39,
   40,  168,   36,   40,   40,   36,   44,  298,   93,  300,
  295,   59,   40,  362,  300,  300,  365,  166,   89,   42,
   59,   59,  300,   41,   47,   59,   44,   40,   59,   41,
  300,  108,   44,   43,  154,  155,  156,  157,  158,  159,
  160,  161,  162,  163,  121,  169,   41,  375,  273,   44,
  127,  281,  282,  283,  131,  279,  280,  167,  168,   60,
   61,   62,  122,  305,  124,  266,  275,  276,  277,  229,
  270,  271,  272,  273,  293,  294,  295,  259,   91,  275,
  276,  277,  257,  275,  276,  277,   36,  258,  266,  134,
   40,   94,   42,   43,  134,   45,   46,   47,  134,  170,
  171,  153,   46,   43,  153,   45,  134,  257,  285,   59,
   60,   61,   62,  293,  294,  295,  300,  284,  285,  286,
  165,  371,  372,  243,  276,  165,  275,  276,  277,  165,
  201,  208,  209,  204,  300,  206,   36,  165,  339,  332,
   40,   91,  281,   43,   94,   45,  300,  224,   58,  199,
  210,  228,  212,  230,  346,  205,  332,  207,  300,   59,
  231,  339,  300,  333,  333,   41,  273,  217,  300,  293,
  294,  295,  222,  275,  284,  285,  286,  300,  257,  258,
  259,  260,  261,  262,  263,  264,  265,  266,  267,  268,
  269,  270,  271,  272,  273,  274,  260,  346,   44,  278,
  279,  280,  293,  294,  295,  284,  167,  168,  287,  288,
  289,  290,   44,  292,  300,  294,  290,  296,  297,  298,
  299,  300,  301,  302,  303,  304,  293,  306,  307,  259,
  300,  300,  303,   61,  300,   43,  300,  308,  258,  270,
  271,  272,  273,   45,  321,  322,   42,   47,   36,  326,
   93,  286,  329,   41,   42,   43,   44,   45,   46,   47,
  261,  262,  263,  264,  265,  266,  267,  300,  276,   43,
   58,   59,   60,   61,   62,  231,  289,  327,  328,  292,
  330,  200,  334,  124,  339,  334,  333,  300,  301,  302,
  303,  333,  363,  364,  371,  372,  321,  266,  322,  266,
  346,  168,  334,  346,  405,   93,   94,  257,  258,  259,
  339,  261,  262,  263,  264,  265,  266,  267,  334,  369,
  370,  392,   88,  284,  285,  286,  376,   88,   -1,  379,
   -1,   -1,   -1,   -1,   -1,   -1,  407,   -1,   -1,  289,
  290,   -1,  292,   -1,  394,   -1,   -1,  397,   -1,   -1,
  300,  301,  302,  303,   -1,  305,   -1,  257,  258,  259,
  260,  261,  262,  263,  264,  265,  266,  267,  268,  269,
  270,  271,  272,  273,  274,   -1,   -1,   -1,  278,  279,
  280,   -1,   -1,   -1,  284,   -1,   -1,  287,  288,  289,
  290,   -1,  292,   -1,  294,   -1,  296,   -1,   -1,  299,
  300,  301,  302,  303,  304,   36,  306,  307,   -1,   -1,
   41,   42,   43,   44,   45,   -1,   47,  284,  285,  286,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   58,   59,   60,
   61,   62,  154,  155,  156,  157,  158,  159,  160,  161,
  162,  163,   36,   -1,   -1,   -1,   -1,   41,   42,   43,
   44,   45,   -1,   47,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   93,   94,   58,   59,   60,   61,   62,  257,
  258,  259,   -1,  261,  262,  263,  264,  265,  266,  267,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,  275,  276,   -1,
   -1,   -1,   -1,  281,  282,  283,   -1,  285,  286,   93,
   -1,   36,  290,   -1,   -1,  293,   41,   42,   43,   44,
   45,   -1,   -1,   -1,   -1,   -1,   -1,  305,   -1,   -1,
   -1,  243,   -1,   58,   59,   60,   61,   62,  155,  156,
  157,  158,  159,  160,  161,  162,  163,   -1,   36,   -1,
   -1,   -1,   -1,   41,   -1,   43,   44,   45,   -1,  155,
  156,  157,  158,  159,  160,  161,  162,  163,   93,   -1,
   58,   59,   60,   61,   62,   -1,   -1,   -1,   -1,   -1,
    2,    3,   -1,    5,    6,    7,    8,    9,   10,   11,
   -1,   -1,   -1,   36,   -1,   -1,   -1,   -1,   41,   -1,
   43,   44,   45,   -1,   -1,   93,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   58,   59,   60,   61,   62,
   -1,   -1,   -1,   -1,   -1,   -1,  243,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,  257,  258,  259,   -1,
  261,  262,  263,  264,  265,  266,  267,  243,   -1,   -1,
   93,   -1,   -1,   -1,  275,  276,   -1,   -1,   -1,   -1,
  281,  282,  283,   36,  285,  286,   88,   -1,   41,  290,
   43,   44,  293,  257,  258,  259,   -1,  261,  262,  263,
  264,  265,  266,  267,  305,   58,   59,   60,   61,   62,
   -1,  275,  276,   -1,   -1,   -1,   -1,  281,  282,  283,
   -1,  285,  286,   -1,   -1,   36,  290,   -1,   -1,  293,
   41,   -1,   -1,   44,   -1,   -1,   -1,   -1,   -1,   -1,
   93,  305,   -1,   -1,   -1,   -1,   -1,   58,   59,   -1,
   -1,   -1,  257,  258,  259,   -1,  261,  262,  263,  264,
  265,  266,  267,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
  275,  276,   -1,   -1,   -1,   -1,  281,  282,  283,   -1,
  285,  286,   93,   -1,   -1,  290,   -1,   -1,  293,  257,
  258,  259,   -1,  261,  262,  263,  264,  265,  266,  267,
  305,   -1,   -1,   -1,   36,   -1,   -1,  275,  276,   41,
   -1,   -1,   44,  281,  282,  283,   -1,  285,  286,   -1,
   -1,   -1,  290,   -1,   -1,  293,   58,   59,   60,   61,
   62,   -1,   -1,   -1,  257,  258,  259,  305,  261,  262,
  263,  264,  265,  266,  267,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,  275,  276,   -1,   -1,   -1,   -1,  281,  282,
  283,   93,  285,  286,   36,   -1,   -1,  290,   -1,   41,
  293,   -1,   44,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,  305,   -1,   -1,   -1,   58,   59,   60,   61,
   62,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,  257,  258,  259,   -1,  261,  262,
  263,  264,  265,  266,  267,   -1,   -1,   -1,   -1,   36,
   -1,   93,  275,  276,   41,   -1,   -1,   44,  281,  282,
  283,   -1,  285,  286,   -1,   -1,   -1,  290,   -1,   -1,
  293,   58,   59,   -1,   -1,   36,  257,  258,  259,   -1,
   41,   -1,  305,   44,   -1,   -1,   -1,   -1,   36,   -1,
   -1,   -1,   -1,   41,  275,  276,   44,   58,   59,   -1,
  281,  282,  283,   -1,  285,  286,   93,   -1,   -1,  290,
   58,   59,  293,   -1,   -1,   36,   -1,   -1,   -1,   -1,
   41,   -1,   -1,   44,  305,   -1,   -1,   -1,   36,   -1,
   -1,   -1,   93,   41,   -1,   -1,   44,   58,   59,   -1,
   -1,   -1,   -1,   -1,   -1,   93,   -1,   -1,   -1,   -1,
   58,   59,   -1,   -1,   -1,  257,  258,  259,   -1,  261,
  262,  263,  264,  265,  266,  267,   -1,   -1,   -1,   -1,
   -1,   -1,   93,  275,  276,   -1,   -1,   -1,   -1,  281,
  282,  283,   -1,  285,  286,   93,   -1,   40,  290,   -1,
   43,  293,   45,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,  305,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,  257,  258,  259,   -1,  261,
  262,  263,  264,  265,  266,  267,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,  275,  276,   -1,   -1,   -1,   -1,  281,
  282,  283,   40,  285,  286,   43,   -1,   45,  290,   -1,
   -1,  293,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,  305,   -1,   -1,   -1,   -1,   -1,   -1,
  257,   -1,  259,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  275,  276,
   -1,   -1,   -1,   -1,  281,  282,  283,   40,  285,  286,
   43,   -1,   45,  290,   -1,   -1,  293,   -1,   -1,  257,
   -1,  259,   -1,   -1,  275,  276,   -1,   -1,  305,   -1,
  281,  282,  283,   -1,  285,  286,   -1,  275,  276,  290,
   -1,   -1,  293,  281,  282,  283,  257,  285,  286,   -1,
   -1,   -1,  290,   -1,  305,  293,   -1,   -1,   40,  257,
   -1,   43,   -1,   45,  275,  276,   -1,  305,   -1,   -1,
  281,  282,  283,   -1,  285,  286,   -1,  275,  276,  290,
   -1,   -1,  293,  281,  282,  283,   -1,  285,  286,   -1,
   -1,   -1,  290,   -1,  305,  293,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,  305,   -1,   -1,
   -1,   -1,   -1,   -1,  257,  258,  259,  260,  261,  262,
  263,  264,  265,  266,  267,  268,  269,  270,  271,  272,
  273,  274,   -1,   -1,   -1,  278,  279,  280,   -1,   -1,
   -1,  284,   -1,   -1,  287,  288,  289,  290,  291,  292,
   -1,  294,   -1,  296,   -1,   -1,  299,  300,  301,  302,
  303,  304,   40,  306,  307,   43,   -1,   45,   -1,  257,
  258,  259,  260,  261,  262,  263,  264,  265,  266,  267,
  268,  269,  270,  271,  272,  273,  274,   -1,   -1,   -1,
  278,  279,  280,   -1,   -1,   -1,  284,   -1,   -1,  287,
  288,  289,  290,  291,  292,   -1,  294,   -1,  296,   -1,
   -1,  299,  300,  301,  302,  303,  304,   40,  306,  307,
   43,   -1,   45,   -1,  257,  258,  259,  260,  261,  262,
  263,  264,  265,  266,  267,  268,  269,  270,  271,  272,
  273,  274,   -1,   -1,   -1,  278,  279,  280,   -1,   -1,
   -1,  284,   -1,   -1,  287,  288,  289,   -1,   -1,  292,
  293,  294,   -1,  296,   -1,   -1,  299,  300,  301,  302,
  303,  304,   -1,  306,  307,  257,  258,  259,  260,  261,
  262,  263,  264,  265,  266,  267,  268,  269,  270,  271,
  272,  273,  274,   -1,   -1,   -1,  278,  279,  280,   -1,
   -1,   -1,  284,   -1,   -1,  287,  288,  289,   40,   41,
  292,   43,  294,   45,  296,   -1,   -1,  299,  300,  301,
  302,  303,  304,   -1,  306,  307,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   40,
   -1,   -1,   43,   -1,   45,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  257,
  258,  259,  260,  261,  262,  263,  264,  265,  266,  267,
  268,  269,  270,  271,  272,  273,  274,   -1,   -1,   -1,
  278,   -1,   -1,   -1,   -1,   -1,  284,   -1,   -1,  287,
  288,  289,   40,   -1,  292,   43,  294,   45,  296,   -1,
   -1,  299,  300,  301,  302,  303,  304,   -1,   -1,  307,
   -1,   -1,   -1,   -1,  257,  258,  259,  260,  261,  262,
  263,  264,  265,  266,  267,  268,  269,  270,  271,  272,
  273,  274,   -1,   -1,   -1,  278,   -1,   -1,   -1,   -1,
   -1,  284,   -1,   -1,  287,  288,  289,   40,   -1,  292,
   43,  294,   45,  296,   -1,   -1,  299,  300,  301,  302,
  303,  304,   -1,   -1,  307,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   40,   -1,
   -1,   43,   -1,   45,   -1,  257,  258,  259,  260,  261,
  262,  263,  264,  265,  266,  267,  268,  269,  270,  271,
  272,  273,  274,   -1,   -1,   -1,  278,   -1,   -1,   -1,
   -1,   -1,  284,   -1,   -1,  287,  288,  289,   -1,   -1,
  292,   -1,  294,   -1,  296,   -1,   -1,  299,  300,  301,
  302,  303,  304,   -1,   -1,  307,  257,  258,  259,  260,
  261,  262,  263,  264,  265,  266,  267,  268,  269,  270,
  271,  272,  273,  274,   -1,   40,   -1,  278,   43,   -1,
   45,   -1,   -1,  284,   -1,   -1,  287,  288,  289,   -1,
   -1,  292,   -1,  294,   -1,  296,   -1,   -1,  299,  300,
  301,  302,  303,  304,   -1,   -1,  307,   -1,   -1,  257,
  258,  259,  260,  261,  262,  263,  264,  265,  266,  267,
  268,  269,  270,  271,  272,  273,  274,   36,   -1,   -1,
  278,   -1,   41,   -1,   -1,   44,  284,   -1,   -1,  287,
  288,  289,   -1,   -1,  292,   -1,  294,   -1,  296,   58,
   59,  299,  300,  301,  302,  303,  304,   -1,   -1,  307,
   -1,   -1,   -1,   -1,  257,  258,  259,  260,  261,  262,
  263,  264,  265,  266,  267,  268,  269,  270,  271,  272,
  273,  274,   36,   -1,   93,  278,   -1,   41,   -1,   -1,
   44,  284,   -1,   -1,  287,  288,  289,   -1,   -1,  292,
   -1,  294,   -1,  296,   58,   59,  299,  300,  301,  302,
  303,  304,   -1,   -1,  307,  257,  258,  259,  260,  261,
  262,  263,  264,  265,  266,  267,  268,  269,  270,  271,
  272,  273,  274,   -1,   -1,   -1,  278,   -1,   -1,   93,
   -1,   -1,  284,   -1,   -1,  287,  288,  289,   -1,   -1,
  292,   -1,  294,   -1,  296,   -1,   -1,  299,  300,  301,
  302,  303,  304,   -1,   40,  307,   42,   43,   36,   45,
   46,   47,   -1,   41,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   60,   61,   62,   -1,   -1,   -1,
   58,   59,  257,  258,  259,  260,  261,  262,  263,  264,
  265,  266,  267,  268,  269,  270,  271,  272,  273,  274,
   -1,   -1,   -1,  278,   -1,   -1,   -1,   -1,   94,  284,
   -1,   -1,  287,  288,  289,   93,   -1,  292,   -1,  294,
   -1,  296,   -1,   -1,  299,  300,  301,  302,  303,  304,
   36,   -1,  307,   -1,   -1,   41,   -1,   -1,   44,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   58,   59,   -1,   -1,  275,  276,   -1,   -1,
   -1,   -1,  281,  282,  283,   -1,  285,  286,   -1,   -1,
   -1,  290,   -1,   -1,  293,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   93,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,  275,  276,   -1,   -1,   -1,   -1,  281,  282,  283,
   -1,  285,  286,   -1,   -1,   -1,  290,   -1,   -1,  293,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,  257,  258,  259,   -1,  261,  262,  263,  264,  265,
  266,  267,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,  275,  276,   -1,
   -1,   -1,   -1,  281,  282,  283,   -1,  285,  286,   -1,
   -1,   -1,  290,   -1,  300,  293,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  275,
  276,   -1,   -1,   -1,   -1,  281,  282,  283,   -1,  285,
   -1,   -1,   -1,   -1,  290,   -1,   -1,  293,
};
#define YYFINAL 42
#ifndef YYDEBUG
#define YYDEBUG 0
#endif
#define YYMAXTOKEN 311
#if YYDEBUG
static YYCONST char *YYCONST yyname[] = {
"end-of-file",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,"'$'",0,0,0,"'('","')'","'*'","'+'","','","'-'","'.'","'/'",0,0,0,0,0,0,0,0,
0,0,"':'","';'","'<'","'='","'>'",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,"'['",0,"']'","'^'",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"SETQ","AND","OR","NOT","MEMBER","MEMQ","NEQ",
"EQ","GEQ","LEQ","FREEOF","SYMBOLIC","ALGEBRAIC","EXPR","MACRO","SMACRO",
"PROCEDURE","FOR","STEP","UNTIL","EACH","FOREACH","IN","ON","DO","COLLECT",
"SUM","IF","THEN","ELSE","REPEAT","WHILE","BEGIN","END","ENDFILE","LSECT",
"RSECT","GO","TO","GOTO","SCALAR","INTEGER","LAMBDA","SYMBOL","NUMBER","STRING",
"LIST","RETURN","WHERE","RLISTAT","ENDSTAT","HASHIF","HASHELSE","HASHELIF",
"HASHENDIF",
};
static YYCONST char *YYCONST yyrule[] = {
"$accept : wholefile",
"wholefile : ENDFILE",
"wholefile : command wholefile",
"command : cmnd sep",
"command : proc_type sep",
"command : END",
"command : END sep",
"sep : ';'",
"sep : '$'",
"proc_type : SYMBOLIC",
"proc_type : ALGEBRAIC",
"proc_qual : EXPR",
"proc_qual : MACRO",
"proc_qual : SMACRO",
"sym_list : ')'",
"sym_list : ',' SYMBOL sym_list",
"infix : SETQ",
"infix : OR",
"infix : AND",
"infix : MEMBER",
"infix : MEMQ",
"infix : '='",
"infix : NEQ",
"infix : EQ",
"infix : GEQ",
"infix : '>'",
"infix : LEQ",
"infix : '<'",
"infix : FREEOF",
"infix : '+'",
"infix : '-'",
"infix : '*'",
"infix : '/'",
"infix : '^'",
"infix : '.'",
"prefix : NOT",
"prefix : '+'",
"prefix : '-'",
"proc_head : SYMBOL",
"proc_head : SYMBOL SYMBOL",
"proc_head : SYMBOL '(' ')'",
"proc_head : SYMBOL '(' SYMBOL sym_list",
"proc_head : prefix SYMBOL",
"proc_head : SYMBOL infix SYMBOL",
"proc_def : PROCEDURE proc_head sep cmnd",
"proc_def : proc_type PROCEDURE proc_head sep cmnd",
"proc_def : proc_qual PROCEDURE proc_head sep cmnd",
"proc_def : proc_type proc_qual PROCEDURE proc_head sep cmnd",
"rlistat : RLISTAT",
"rlistat : IN",
"rlistat : ON",
"rltail : expr",
"rltail : expr ',' rltail",
"cmnd : expr",
"cmnd : rlistat rltail",
"if_stmt : IF expr THEN cmnd ELSE cmnd",
"if_stmt : IF expr THEN cmnd",
"for_update : ':' expr",
"for_update : STEP expr UNTIL expr",
"for_action : DO",
"for_action : SUM",
"for_action : COLLECT",
"for_inon : IN",
"for_inon : ON",
"for_stmt : FOR SYMBOL SETQ expr for_update for_action cmnd",
"for_stmt : FOR EACH SYMBOL for_inon expr for_action cmnd",
"for_stmt : FOREACH SYMBOL for_inon expr for_action cmnd",
"while_stmt : WHILE expr DO cmnd",
"repeat_stmt : REPEAT cmnd UNTIL expr",
"return_stmt : RETURN",
"return_stmt : RETURN expr",
"goto_stmt : GOTO SYMBOL",
"goto_stmt : GO SYMBOL",
"goto_stmt : GO TO SYMBOL",
"group_tail : RSECT",
"group_tail : sep RSECT",
"group_tail : sep cmnd group_tail",
"group_expr : LSECT cmnd group_tail",
"scalar_tail : sep",
"scalar_tail : ',' SYMBOL scalar_tail",
"scalar_tail : ',' INTEGER scalar_tail",
"scalar_def : SCALAR SYMBOL scalar_tail",
"scalar_def : INTEGER SYMBOL scalar_tail",
"scalar_defs : scalar_def",
"scalar_defs : scalar_defs scalar_def",
"block_tail : END",
"block_tail : cmnd END",
"block_tail : SYMBOL ':' block_tail",
"block_tail : cmnd sep block_tail",
"block_tail : sep block_tail",
"block_expr : BEGIN scalar_defs block_tail",
"block_expr : BEGIN block_tail",
"lambda_vars : sep",
"lambda_vars : ',' SYMBOL lambda_vars",
"lambda_expr : LAMBDA SYMBOL lambda_vars cmnd",
"lambda_expr : LAMBDA '(' ')' sep cmnd",
"lambda_expr : LAMBDA '(' SYMBOL sym_list sep cmnd",
"expr : rx0",
"expr : lx0",
"rx0 : lx0 WHERE SYMBOL '=' rx1",
"rx0 : rx1",
"lx0 : lx0 WHERE SYMBOL '=' lx1",
"lx0 : lx1",
"rx1 : lx2 SETQ rx1",
"rx1 : rx2",
"lx1 : lx2 SETQ lx1",
"lx1 : lx2",
"rx2tail : rx3",
"rx2tail : lx3 OR rx2tail",
"rx2 : lx3 OR rx2tail",
"rx2 : rx3",
"lx2tail : lx3",
"lx2tail : lx3 OR lx2tail",
"lx2 : lx3 OR lx2tail",
"lx2 : lx3",
"rx3tail : rx4",
"rx3tail : lx4 AND rx3tail",
"rx3 : lx4 AND rx3tail",
"rx3 : rx4",
"lx3tail : lx4",
"lx3tail : lx4 AND lx3tail",
"lx3 : lx4 AND lx3tail",
"lx3 : lx4",
"rx4 : NOT rx4",
"rx4 : rx5",
"lx4 : NOT lx4",
"lx4 : lx5",
"rx5 : lx6 MEMBER ry6",
"rx5 : lx6 MEMQ ry6",
"rx5 : lx6 '=' ry6",
"rx5 : lx6 NEQ ry6",
"rx5 : lx6 EQ ry6",
"rx5 : lx6 GEQ ry6",
"rx5 : lx6 '>' ry6",
"rx5 : lx6 LEQ ry6",
"rx5 : lx6 '<' ry6",
"rx5 : lx6 FREEOF ry6",
"rx5 : rx6",
"lx5 : lx6 MEMBER ly6",
"lx5 : lx6 MEMQ ly6",
"lx5 : lx6 '=' ly6",
"lx5 : lx6 NEQ ly6",
"lx5 : lx6 EQ ly6",
"lx5 : lx6 GEQ ly6",
"lx5 : lx6 '>' ly6",
"lx5 : lx6 LEQ ly6",
"lx5 : lx6 '<' ly6",
"lx5 : lx6 FREEOF ly6",
"lx5 : lx6",
"ry6 : NOT ry6",
"ry6 : rx6",
"ly6 : NOT ly6",
"ly6 : lx6",
"rx6tail : ry6a",
"rx6tail : ly6a '+' rx6tail",
"rx6 : lx6a '+' rx6tail",
"rx6 : rx6a",
"lx6tail : ly6a",
"lx6tail : ly6a '+' lx6tail",
"lx6 : lx6a '+' lx6tail",
"lx6 : lx6a",
"ry6a : NOT ry6a",
"ry6a : rx6a",
"rx6a : lx6a '-' ry7",
"rx6a : rx7",
"ly6a : NOT ly6a",
"ly6a : lx6a",
"lx6a : lx6a '-' ly7",
"lx6a : lx7",
"ry7 : NOT ry7",
"ry7 : rx7",
"rx7 : '+' ry7",
"rx7 : '-' ry7",
"rx7 : rx8",
"ly7 : NOT ly7",
"ly7 : lx7",
"lx7 : '+' ly7",
"lx7 : '-' ly7",
"lx7 : lx8",
"rx8tail : ry9",
"rx8tail : ly9 '*' rx8tail",
"rx8 : lx9 '*' rx8tail",
"rx8 : rx9",
"lx8tail : ly9",
"lx8tail : ly9 '*' lx8tail",
"lx8 : lx9 '*' lx8tail",
"lx8 : lx9",
"ry9 : NOT ry9",
"ry9 : '+' ry9",
"ry9 : '-' ry9",
"ry9 : rx9",
"rx9 : lx9 '/' ry10",
"rx9 : rx10",
"ly9 : NOT ly9",
"ly9 : '+' ly9",
"ly9 : '-' ly9",
"ly9 : lx9",
"lx9 : lx9 '/' ly10",
"lx9 : lx10",
"ly10 : NOT ly10",
"ly10 : '+' ly10",
"ly10 : '-' ly10",
"ly10 : lx10",
"lx10 : lx11 '^' ly10",
"lx10 : lx11",
"ry10 : NOT ry10",
"ry10 : '+' ry10",
"ry10 : '-' ry10",
"ry10 : rx10",
"rx10 : lx11 '^' ry10",
"rx10 : rx11",
"ry11 : NOT ry11",
"ry11 : '+' ry11",
"ry11 : '-' ry11",
"ry11 : rx11",
"rx11 : x12 '.' ry11",
"rx11 : if_stmt",
"rx11 : for_stmt",
"rx11 : while_stmt",
"rx11 : repeat_stmt",
"rx11 : return_stmt",
"rx11 : goto_stmt",
"rx11 : lambda_expr",
"rx11 : proc_def",
"rx11 : ENDSTAT",
"ly11 : NOT ly11",
"ly11 : '+' ly11",
"ly11 : '-' ly11",
"ly11 : lx11",
"lx11 : x12 '.' ly11",
"lx11 : x12",
"arg_list : ')'",
"arg_list : ',' expr arg_list",
"parened : '(' expr ')'",
"commaparened : '(' expr ',' expr arg_list",
"x12notparened : x13b '[' expr ']'",
"x12notparened : x13b '(' ')'",
"x12notparened : x13b parened",
"x12notparened : x13b commaparened",
"x12notparened : x13b x12notparened",
"x12notparened : x13b",
"x12 : x12notparened",
"x12 : parened",
"x12 : SETQ commaparened",
"x12 : OR commaparened",
"x12 : AND commaparened",
"x12 : MEMBER commaparened",
"x12 : MEMQ commaparened",
"x12 : NEQ commaparened",
"x12 : EQ commaparened",
"x12 : GEQ commaparened",
"x12 : LEQ commaparened",
"x12 : FREEOF commaparened",
"x13b : SYMBOL",
"x13b : NUMBER",
"x13b : STRING",
"x13b : LIST",
"x13b : group_expr",
"x13b : block_expr",
};
#endif
#ifndef YYSTYPE
typedef int YYSTYPE;
#endif
#define YYLEX yylex()
#define YYEMPTY -1
#define yyclearin (yychar=(YYEMPTY))
#define yyerrok (yyerrflag=0)
#ifndef YYINITDEPTH
#define YYINITDEPTH 200
#endif
#ifdef YYSTACKSIZE
#ifndef YYMAXDEPTH
#define YYMAXDEPTH YYSTACKSIZE
#endif
#else
#ifdef YYMAXDEPTH
#define YYSTACKSIZE YYMAXDEPTH
#else
#define YYSTACKSIZE 500
#define YYMAXDEPTH 500
#endif
#endif
#ifndef YYMAXSTACKSIZE
#define YYMAXSTACKSIZE 10000
#endif
int yydebug;
int yynerrs;
int yyerrflag;
int yychar;
YYSTYPE yyval;
YYSTYPE yylval;
static short *yyss;
static YYSTYPE *yyvs;
static int yystacksize;
#define yyfree(x) free(x)
extern int yylex();

static YYPTR
YYDEFUN (yymalloc, (bytes), unsigned bytes)
{
    YYPTR ptr = (YYPTR) malloc (bytes);
    if (ptr != 0) return (ptr);
    yyerror ("yyparse: memory exhausted");
    return (0);
}

static YYPTR
YYDEFUN (yyrealloc, (old, bytes), YYPTR old YYAND unsigned bytes)
{
    YYPTR ptr = (YYPTR) realloc (old, bytes);
    if (ptr != 0) return (ptr);
    yyerror ("yyparse: memory exhausted");
    return (0);
}

static int
#ifdef __GNUC__
__inline__
#endif
yygrow ()
{
    int old_stacksize = yystacksize;
    short *new_yyss;
    YYSTYPE *new_yyvs;

    if (yystacksize == YYMAXSTACKSIZE)
        return (1);
    yystacksize += (yystacksize + 1 ) / 2;
    if (yystacksize > YYMAXSTACKSIZE)
        yystacksize = YYMAXSTACKSIZE;
#if YYDEBUG
    if (yydebug)
        printf("yydebug: growing stack size from %d to %d\n",
               old_stacksize, yystacksize);
#endif
    new_yyss = (short *) yyrealloc ((char *)yyss, yystacksize * sizeof (short));
    if (new_yyss == 0)
        return (1);
    new_yyvs = (YYSTYPE *) yyrealloc ((char *)yyvs, yystacksize * sizeof (YYSTYPE));
    if (new_yyvs == 0)
    {
        yyfree (new_yyss);
        return (1);
    }
    yyss = new_yyss;
    yyvs = new_yyvs;
    return (0);
}
#line 1287 "r2l.y"



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

static int onechar(int c)
{
    char b[4];
    b[0] = c;
    b[1] = 0;
    return find_symbol(b);
}

int lisp_token()
{
    char buffer[1000];
    int bp = 0, num = 0, r;
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
    {   yylval = find_symbol((char *)buffer);
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
        yylval = find_symbol((char *)buffer);
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


static int read_tail();
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

static int read_list(int r)
{
    switch (r)
    {
case '(': return read_tail();

case '.':
case ')': return C_nil;   /* errors! */

case '\'':
          return list2(find_symbol("quote"), read_list(lisp_token()));
default:
          return yylval;
    }
}

int read_tail()
{
    int r;
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
default:  r = yylval;
          return cons(r, read_tail());
    }
}


static int skipping = 0;

static int genuine_yylex();

static int evaluates_to_true(int r)
{
    int fn, arg;
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
    int r;
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

static int genuine_yylex()
{
    char buffer[1000];
    int bp, num, r;
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
        yylval = find_symbol((char *)buffer);
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
        yylval = find_symbol((char *)buffer);
        return STRING;
    }
    if (ch == '\'')
    {   nextch();
        r = read_list(lisp_token());
        yylval = list2(find_symbol("quote"), r);
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


static int yylex()
{
    return genuine_yylex();
}


/* end of file */
#line 2175 "r2l.c"
#define YYABORT goto yyabort
#define YYACCEPT goto yyaccept
#define YYERROR goto yyerrlab

#if YYDEBUG
#ifdef __cplusplus
extern "C" char *getenv();
#else
extern char *getenv();
#endif
#endif

int
yyparse()
{
    register int yym, yyn, yystate;
    register YYSTYPE *yyvsp;
    register short *yyssp;
    short *yysse;
#if YYDEBUG
    register YYCONST char *yys;

    if (yys = getenv("YYDEBUG"))
    {
        yyn = *yys;
        if (yyn >= '0' && yyn <= '9')
            yydebug = yyn - '0';
    }
#endif

    yynerrs = 0;
    yyerrflag = 0;
    yychar = (-1);

    if (yyss == 0)
    {
        yyss = (short *) yymalloc (YYSTACKSIZE * sizeof (short));
        if (yyss == 0)
          goto yyabort;
        yyvs = (YYSTYPE *) yymalloc (YYSTACKSIZE * sizeof (YYSTYPE));
        if (yyvs == 0)
        {
            yyfree (yyss);
            goto yyabort;
        }
        yystacksize = YYSTACKSIZE;
    }
    yysse = yyss + yystacksize - 1;
    yyssp = yyss;
    yyvsp = yyvs;
    *yyssp = yystate = 0;
    goto yyloop;

yypush_lex:
    yyval = yylval;
    yystate = yytable[yyn];
yypush:
    if (yyssp >= yysse)
    {
        int depth = yyssp - yyss;
        if (yygrow() != 0)
             goto yyoverflow;
        yysse = yyss + yystacksize -1;
        yyssp = depth + yyss;
        yyvsp = depth + yyvs;
    }
    *++yyssp = yystate;
    *++yyvsp = yyval;

yyloop:
    if (yyn = yydefred[yystate]) goto yyreduce;
    yyn = yysindex[yystate];
    if (yychar < 0)
    {
        if ((yychar = yylex()) < 0) yychar = 0;
#if YYDEBUG
        if (yydebug)
        {
            yys = 0;
            if (yychar <= YYMAXTOKEN) yys = yyname[yychar];
            if (!yys) yys = "illegal-symbol";
            printf("yydebug: state %d, reading %d (%s)\n", yystate,
                    yychar, yys);
        }
#endif
    }
    if (yyn != 0
        && ((yyn += yychar), ((unsigned)yyn <= (unsigned)YYTABLESIZE))
        && yycheck[yyn] == yychar)
    {
#if YYDEBUG
        if (yydebug)
            printf("yydebug: state %d, shifting to state %d\n",
                    yystate, yytable[yyn]);
#endif
        if (yyerrflag > 0)  --yyerrflag;
        yychar = (-1);
        goto yypush_lex;
    }
    yyn = yyrindex[yystate];
    if (yyn != 0
        && ((yyn += yychar), ((unsigned)yyn <= (unsigned)YYTABLESIZE))
        && yycheck[yyn] == yychar)
    {
        yyn = yytable[yyn];
        goto yyreduce;
    }
    if (yyerrflag) goto yyinrecovery;
#ifdef lint
    goto yynewerror;
#endif
yynewerror:
    yyerror("syntax error");
#ifdef lint
    goto yyerrlab;
#endif
yyerrlab:
    ++yynerrs;
yyinrecovery:
    if (yyerrflag < 3)
    {
        yyerrflag = 3;
        for (;;)
        {
            yyn = yysindex[*yyssp];
            if (yyn != 0
                && ((yyn += YYERRCODE), ((unsigned)yyn <= (unsigned)YYTABLESIZE))
                && yycheck[yyn] == YYERRCODE)
            {
#if YYDEBUG
                if (yydebug)
                    printf("yydebug: state %d, error recovery shifting\
 to state %d\n", *yyssp, yytable[yyn]);
#endif
                goto yypush_lex;
            }
            else
            {
#if YYDEBUG
                if (yydebug)
                    printf("yydebug: error recovery discarding state %d\n",
                            *yyssp);
#endif
                if (yyssp <= yyss) goto yyabort;
                --yyssp;
                --yyvsp;
            }
        }
    }
    else
    {
        if (yychar == 0) goto yyabort;
#if YYDEBUG
        if (yydebug)
        {
            yys = 0;
            if (yychar <= YYMAXTOKEN) yys = yyname[yychar];
            if (!yys) yys = "illegal-symbol";
            printf("yydebug: state %d, error recovery discards token %d (%s)\n",
                    yystate, yychar, yys);
        }
#endif
        yychar = (-1);
        goto yyloop;
    }
yyreduce:
#if YYDEBUG
    if (yydebug)
        printf("yydebug: state %d, reducing by rule %d (%s)\n",
                yystate, yyn, yyrule[yyn]);
#endif
    yym = yylen[yyn];
    yyval = yyvsp[1-yym];
    switch (yyn)
    {
case 1:
#line 809 "r2l.y"
{  
    if (common) fprintf(outputfile, "\n;; end of file\n");
    else fprintf(outputfile, "\n%% end of file\n");
    exit(0);
                                        }
break;
case 3:
#line 816 "r2l.y"
{ evalorprint(yyvsp[-1]); 
					  fprintf(outputfile, "\n\n");
                                          otlpos = 0;
                                          heapfringe = 0;
					}
break;
case 9:
#line 830 "r2l.y"
{ yyval = sym_symbolic; }
break;
case 10:
#line 831 "r2l.y"
{ yyval = sym_algebraic; }
break;
case 11:
#line 834 "r2l.y"
{ yyval = sym_de; }
break;
case 12:
#line 835 "r2l.y"
{ yyval = sym_dm; }
break;
case 13:
#line 836 "r2l.y"
{ yyval = sym_ds; }
break;
case 14:
#line 839 "r2l.y"
{ yyval = C_nil; }
break;
case 15:
#line 840 "r2l.y"
{ yyval = cons(yyvsp[-1], yyvsp[0]); }
break;
case 16:
#line 848 "r2l.y"
{ yyval = sym_setq; }
break;
case 17:
#line 849 "r2l.y"
{ yyval = sym_or; }
break;
case 18:
#line 850 "r2l.y"
{ yyval = sym_and; }
break;
case 19:
#line 851 "r2l.y"
{ yyval = sym_member; }
break;
case 20:
#line 852 "r2l.y"
{ yyval = sym_memq; }
break;
case 21:
#line 853 "r2l.y"
{ yyval = sym_equal; }
break;
case 22:
#line 854 "r2l.y"
{ yyval = sym_neq; }
break;
case 23:
#line 855 "r2l.y"
{ yyval = sym_eq; }
break;
case 24:
#line 856 "r2l.y"
{ yyval = sym_geq; }
break;
case 25:
#line 857 "r2l.y"
{ yyval = sym_greaterp; }
break;
case 26:
#line 858 "r2l.y"
{ yyval = sym_leq; }
break;
case 27:
#line 859 "r2l.y"
{ yyval = sym_lessp; }
break;
case 28:
#line 860 "r2l.y"
{ yyval = sym_freeof; }
break;
case 29:
#line 861 "r2l.y"
{ yyval = sym_plus; }
break;
case 30:
#line 862 "r2l.y"
{ yyval = sym_difference; }
break;
case 31:
#line 863 "r2l.y"
{ yyval = sym_times; }
break;
case 32:
#line 864 "r2l.y"
{ yyval = sym_quotient; }
break;
case 33:
#line 865 "r2l.y"
{ yyval = sym_expt; }
break;
case 34:
#line 866 "r2l.y"
{ yyval = sym_cons; }
break;
case 35:
#line 869 "r2l.y"
{ yyval = sym_not; }
break;
case 36:
#line 870 "r2l.y"
{ yyval = sym_plus; }
break;
case 37:
#line 871 "r2l.y"
{ yyval = sym_minus; }
break;
case 38:
#line 874 "r2l.y"
{ yyval = cons(yyvsp[0], C_nil); }
break;
case 39:
#line 875 "r2l.y"
{ yyval = list2(yyvsp[-1], yyvsp[0]); }
break;
case 40:
#line 876 "r2l.y"
{ yyval = cons(yyvsp[-2], C_nil); }
break;
case 41:
#line 878 "r2l.y"
{ yyval = cons(yyvsp[-3], cons(yyvsp[-1], yyvsp[0])); }
break;
case 42:
#line 879 "r2l.y"
{ yyval = list2(yyvsp[-1], yyvsp[0]); }
break;
case 43:
#line 880 "r2l.y"
{ yyval = list3(yyvsp[-1], yyvsp[-2], yyvsp[0]); }
break;
case 44:
#line 884 "r2l.y"
{ yyval = list4(sym_de, qcar(yyvsp[-2]), qcdr(yyvsp[-2]), yyvsp[0]); }
break;
case 45:
#line 886 "r2l.y"
{ yyval = list4(sym_de, qcar(yyvsp[-2]), qcdr(yyvsp[-2]), yyvsp[0]); }
break;
case 46:
#line 888 "r2l.y"
{ yyval = list4(yyvsp[-4], qcar(yyvsp[-2]), qcdr(yyvsp[-2]), yyvsp[0]); }
break;
case 47:
#line 890 "r2l.y"
{ yyval = list4(yyvsp[-4], qcar(yyvsp[-2]), qcdr(yyvsp[-2]), yyvsp[0]); }
break;
case 49:
#line 894 "r2l.y"
{ yyval = sym_in; }
break;
case 50:
#line 895 "r2l.y"
{ yyval = sym_on; }
break;
case 51:
#line 898 "r2l.y"
{ yyval = cons(yyvsp[0], C_nil); }
break;
case 52:
#line 899 "r2l.y"
{ yyval = cons(yyvsp[-2], yyvsp[0]); }
break;
case 54:
#line 908 "r2l.y"
{ yyval = list2(yyvsp[-1], cons(sym_list, yyvsp[0])); }
break;
case 55:
#line 918 "r2l.y"
{ yyval = list4(sym_if, yyvsp[-4], yyvsp[-2], yyvsp[0]); }
break;
case 56:
#line 919 "r2l.y"
{ yyval = list3(sym_if, yyvsp[-2], yyvsp[0]); }
break;
case 57:
#line 922 "r2l.y"
{ yyval = cons(find_symbol("1"), yyvsp[0]); }
break;
case 58:
#line 923 "r2l.y"
{ yyval = cons(yyvsp[-2], yyvsp[0]); }
break;
case 59:
#line 926 "r2l.y"
{ yyval = sym_do; }
break;
case 60:
#line 927 "r2l.y"
{ yyval = sym_sum; }
break;
case 61:
#line 928 "r2l.y"
{ yyval = sym_collect; }
break;
case 62:
#line 931 "r2l.y"
{ yyval = sym_in; }
break;
case 63:
#line 932 "r2l.y"
{ yyval = sym_on; }
break;
case 64:
#line 936 "r2l.y"
{ yyval = make_for(yyvsp[-5], yyvsp[-3], qcar(yyvsp[-2]), qcdr(yyvsp[-2]), yyvsp[-1], yyvsp[0]); }
break;
case 65:
#line 938 "r2l.y"
{ yyval = make_foreach(yyvsp[-4], yyvsp[-3], yyvsp[-2], yyvsp[-1], yyvsp[0]); }
break;
case 66:
#line 940 "r2l.y"
{ yyval = make_foreach(yyvsp[-4], yyvsp[-3], yyvsp[-2], yyvsp[-1], yyvsp[0]); }
break;
case 67:
#line 943 "r2l.y"
{
       int lab1 = genlabel();
       yyval = list6(sym_prog, C_nil, lab1,
                  list3(sym_if, list2(sym_null, yyvsp[-2]), list2(sym_return, C_nil)),
                  yyvsp[0],
                  list2(sym_go, lab1)); }
break;
case 68:
#line 951 "r2l.y"
{
       int lab1 = genlabel();
       yyval = list5(sym_prog, C_nil, lab1,
                  yyvsp[-2],
                  list3(sym_if, list2(sym_null, yyvsp[0]), list2(sym_go, lab1))); }
break;
case 69:
#line 958 "r2l.y"
{ yyval = list2(sym_return, C_nil); }
break;
case 70:
#line 959 "r2l.y"
{ yyval = list2(sym_return, yyvsp[0]); }
break;
case 71:
#line 962 "r2l.y"
{ yyval = list2(sym_go, yyvsp[0]); }
break;
case 72:
#line 963 "r2l.y"
{ yyval = list2(sym_go, yyvsp[0]); }
break;
case 73:
#line 964 "r2l.y"
{ yyval = list2(sym_go, yyvsp[0]); }
break;
case 74:
#line 967 "r2l.y"
{ yyval = C_nil; }
break;
case 75:
#line 968 "r2l.y"
{ yyval = C_nil; }
break;
case 76:
#line 969 "r2l.y"
{ yyval = cons(yyvsp[-1], yyvsp[0]); }
break;
case 77:
#line 972 "r2l.y"
{ yyval = cons(sym_progn, cons(yyvsp[-1], yyvsp[0])); }
break;
case 78:
#line 975 "r2l.y"
{ yyval = C_nil; }
break;
case 79:
#line 977 "r2l.y"
{ yyval = cons(yyvsp[-1], yyvsp[0]); }
break;
case 80:
#line 979 "r2l.y"
{ yyval = cons(yyvsp[-1], yyvsp[0]); }
break;
case 81:
#line 983 "r2l.y"
{ yyval = cons(yyvsp[-1], yyvsp[0]); }
break;
case 82:
#line 985 "r2l.y"
{ yyval = cons(yyvsp[-1], yyvsp[0]); }
break;
case 84:
#line 990 "r2l.y"
{ yyval = append(yyvsp[-1], yyvsp[0]); }
break;
case 85:
#line 993 "r2l.y"
{ yyval = C_nil; }
break;
case 86:
#line 994 "r2l.y"
{ yyval = cons(yyvsp[-1], C_nil); }
break;
case 87:
#line 995 "r2l.y"
{ yyval = cons(yyvsp[-2], yyvsp[0]); }
break;
case 88:
#line 996 "r2l.y"
{ yyval = cons(yyvsp[-2], yyvsp[0]); }
break;
case 89:
#line 997 "r2l.y"
{ yyval = yyvsp[0]; }
break;
case 90:
#line 1001 "r2l.y"
{ yyval = cons(sym_prog, cons(yyvsp[-1], yyvsp[0])); }
break;
case 91:
#line 1002 "r2l.y"
{ yyval = cons(sym_prog, cons(C_nil, yyvsp[0])); }
break;
case 92:
#line 1005 "r2l.y"
{ yyval = C_nil; }
break;
case 93:
#line 1007 "r2l.y"
{ yyval = cons(yyvsp[-1], yyvsp[0]); }
break;
case 94:
#line 1011 "r2l.y"
{ yyval = list3(sym_lambda, ncons(yyvsp[-2]), yyvsp[-1]); }
break;
case 95:
#line 1013 "r2l.y"
{ yyval = list3(sym_lambda, C_nil, yyvsp[0]); }
break;
case 96:
#line 1015 "r2l.y"
{ yyval = list3(sym_lambda, cons(yyvsp[-3], yyvsp[-2]), yyvsp[0]); }
break;
case 99:
#line 1028 "r2l.y"
{ yyval = make_where(yyvsp[-4], yyvsp[-2], yyvsp[0]); }
break;
case 101:
#line 1033 "r2l.y"
{ yyval = make_where(yyvsp[-4], yyvsp[-2], yyvsp[0]); }
break;
case 103:
#line 1037 "r2l.y"
{ yyval = list3(sym_setq, yyvsp[-2], yyvsp[0]); }
break;
case 105:
#line 1041 "r2l.y"
{ yyval = list3(sym_setq, yyvsp[-2], yyvsp[0]); }
break;
case 107:
#line 1045 "r2l.y"
{ yyval = ncons(yyvsp[0]); }
break;
case 108:
#line 1046 "r2l.y"
{ yyval = cons(yyvsp[-2], yyvsp[0]); }
break;
case 109:
#line 1048 "r2l.y"
{ yyval = cons(sym_or, cons(yyvsp[-2], yyvsp[0])); }
break;
case 111:
#line 1052 "r2l.y"
{ yyval = ncons(yyvsp[0]); }
break;
case 112:
#line 1053 "r2l.y"
{ yyval = cons(yyvsp[-2], yyvsp[0]); }
break;
case 113:
#line 1055 "r2l.y"
{ yyval = cons(sym_or, cons(yyvsp[-2], yyvsp[0])); }
break;
case 115:
#line 1059 "r2l.y"
{ yyval = ncons(yyvsp[0]); }
break;
case 116:
#line 1060 "r2l.y"
{ yyval = cons(yyvsp[-2], yyvsp[0]); }
break;
case 117:
#line 1062 "r2l.y"
{ yyval = cons(sym_and, cons(yyvsp[-2], yyvsp[0])); }
break;
case 119:
#line 1066 "r2l.y"
{ yyval = ncons(yyvsp[0]); }
break;
case 120:
#line 1067 "r2l.y"
{ yyval = cons(yyvsp[-2], yyvsp[0]); }
break;
case 121:
#line 1069 "r2l.y"
{ yyval = cons(sym_and, cons(yyvsp[-2], yyvsp[0])); }
break;
case 123:
#line 1073 "r2l.y"
{ yyval = list2(sym_not, yyvsp[0]); }
break;
case 125:
#line 1077 "r2l.y"
{ yyval = list2(sym_not, yyvsp[0]); }
break;
case 127:
#line 1081 "r2l.y"
{ yyval = list3(sym_member, yyvsp[-2], yyvsp[0]); }
break;
case 128:
#line 1082 "r2l.y"
{ yyval = list3(sym_memq, yyvsp[-2], yyvsp[0]); }
break;
case 129:
#line 1083 "r2l.y"
{ yyval = list3(sym_equal, yyvsp[-2], yyvsp[0]); }
break;
case 130:
#line 1084 "r2l.y"
{ yyval = list3(sym_neq, yyvsp[-2], yyvsp[0]); }
break;
case 131:
#line 1085 "r2l.y"
{ yyval = list3(sym_eq, yyvsp[-2], yyvsp[0]); }
break;
case 132:
#line 1086 "r2l.y"
{ yyval = list3(sym_geq, yyvsp[-2], yyvsp[0]); }
break;
case 133:
#line 1087 "r2l.y"
{ yyval = list3(sym_greaterp, yyvsp[-2], yyvsp[0]); }
break;
case 134:
#line 1088 "r2l.y"
{ yyval = list3(sym_leq, yyvsp[-2], yyvsp[0]); }
break;
case 135:
#line 1089 "r2l.y"
{ yyval = list3(sym_lessp, yyvsp[-2], yyvsp[0]); }
break;
case 136:
#line 1090 "r2l.y"
{ yyval = list3(sym_freeof, yyvsp[-2], yyvsp[0]); }
break;
case 138:
#line 1094 "r2l.y"
{ yyval = list3(sym_member, yyvsp[-2], yyvsp[0]); }
break;
case 139:
#line 1095 "r2l.y"
{ yyval = list3(sym_memq, yyvsp[-2], yyvsp[0]); }
break;
case 140:
#line 1096 "r2l.y"
{ yyval = list3(sym_equal, yyvsp[-2], yyvsp[0]); }
break;
case 141:
#line 1097 "r2l.y"
{ yyval = list3(sym_neq, yyvsp[-2], yyvsp[0]); }
break;
case 142:
#line 1098 "r2l.y"
{ yyval = list3(sym_eq, yyvsp[-2], yyvsp[0]); }
break;
case 143:
#line 1099 "r2l.y"
{ yyval = list3(sym_geq, yyvsp[-2], yyvsp[0]); }
break;
case 144:
#line 1100 "r2l.y"
{ yyval = list3(sym_greaterp, yyvsp[-2], yyvsp[0]); }
break;
case 145:
#line 1101 "r2l.y"
{ yyval = list3(sym_leq, yyvsp[-2], yyvsp[0]); }
break;
case 146:
#line 1102 "r2l.y"
{ yyval = list3(sym_lessp, yyvsp[-2], yyvsp[0]); }
break;
case 147:
#line 1103 "r2l.y"
{ yyval = list3(sym_freeof, yyvsp[-2], yyvsp[0]); }
break;
case 149:
#line 1107 "r2l.y"
{ yyval = list2(sym_not, yyvsp[0]); }
break;
case 151:
#line 1111 "r2l.y"
{ yyval = list2(sym_not, yyvsp[0]); }
break;
case 153:
#line 1115 "r2l.y"
{ yyval = ncons(yyvsp[0]); }
break;
case 154:
#line 1116 "r2l.y"
{ yyval = cons(yyvsp[-2], yyvsp[0]); }
break;
case 155:
#line 1118 "r2l.y"
{ yyval = cons(sym_plus, cons(yyvsp[-2], yyvsp[0])); }
break;
case 157:
#line 1122 "r2l.y"
{ yyval = ncons(yyvsp[0]); }
break;
case 158:
#line 1123 "r2l.y"
{ yyval = cons(yyvsp[-2], yyvsp[0]); }
break;
case 159:
#line 1125 "r2l.y"
{ yyval = cons(sym_plus, cons(yyvsp[-2], yyvsp[0])); }
break;
case 161:
#line 1129 "r2l.y"
{ yyval = list2(sym_not, yyvsp[0]); }
break;
case 163:
#line 1133 "r2l.y"
{ yyval = list3(sym_difference, yyvsp[-2], yyvsp[0]); }
break;
case 165:
#line 1137 "r2l.y"
{ yyval = list2(sym_not, yyvsp[0]); }
break;
case 167:
#line 1141 "r2l.y"
{ yyval = list3(sym_difference, yyvsp[-2], yyvsp[0]); }
break;
case 169:
#line 1145 "r2l.y"
{ yyval = list2(sym_not, yyvsp[0]); }
break;
case 171:
#line 1149 "r2l.y"
{ yyval = yyvsp[0]; }
break;
case 172:
#line 1150 "r2l.y"
{ yyval = list2(sym_minus, yyvsp[0]); }
break;
case 174:
#line 1154 "r2l.y"
{ yyval = list2(sym_not, yyvsp[0]); }
break;
case 176:
#line 1158 "r2l.y"
{ yyval = yyvsp[0]; }
break;
case 177:
#line 1159 "r2l.y"
{ yyval = list2(sym_minus, yyvsp[0]); }
break;
case 179:
#line 1163 "r2l.y"
{ yyval = ncons(yyvsp[0]); }
break;
case 180:
#line 1164 "r2l.y"
{ yyval = cons(yyvsp[-2], yyvsp[0]); }
break;
case 181:
#line 1166 "r2l.y"
{ yyval = cons(sym_times, cons(yyvsp[-2], yyvsp[0])); }
break;
case 183:
#line 1170 "r2l.y"
{ yyval = ncons(yyvsp[0]); }
break;
case 184:
#line 1171 "r2l.y"
{ yyval = cons(yyvsp[-2], yyvsp[0]); }
break;
case 185:
#line 1173 "r2l.y"
{ yyval = cons(sym_times, cons(yyvsp[-2], yyvsp[0])); }
break;
case 187:
#line 1177 "r2l.y"
{ yyval = list2(sym_not, yyvsp[0]); }
break;
case 188:
#line 1178 "r2l.y"
{ yyval = yyvsp[0]; }
break;
case 189:
#line 1179 "r2l.y"
{ yyval = list2(sym_minus, yyvsp[0]); }
break;
case 191:
#line 1183 "r2l.y"
{ yyval = list3(sym_quotient, yyvsp[-2], yyvsp[0]); }
break;
case 193:
#line 1187 "r2l.y"
{ yyval = list2(sym_not, yyvsp[0]); }
break;
case 194:
#line 1188 "r2l.y"
{ yyval = yyvsp[0]; }
break;
case 195:
#line 1189 "r2l.y"
{ yyval = list2(sym_minus, yyvsp[0]); }
break;
case 197:
#line 1193 "r2l.y"
{ yyval = list3(sym_quotient, yyvsp[-2], yyvsp[0]); }
break;
case 199:
#line 1197 "r2l.y"
{ yyval = list2(sym_not, yyvsp[0]); }
break;
case 200:
#line 1198 "r2l.y"
{ yyval = yyvsp[0]; }
break;
case 201:
#line 1199 "r2l.y"
{ yyval = list2(sym_minus, yyvsp[0]); }
break;
case 203:
#line 1203 "r2l.y"
{ yyval = list3(sym_expt, yyvsp[-2], yyvsp[0]); }
break;
case 205:
#line 1207 "r2l.y"
{ yyval = list2(sym_not, yyvsp[0]); }
break;
case 206:
#line 1208 "r2l.y"
{ yyval = yyvsp[0]; }
break;
case 207:
#line 1209 "r2l.y"
{ yyval = list2(sym_minus, yyvsp[0]); }
break;
case 209:
#line 1213 "r2l.y"
{ yyval = list3(sym_expt, yyvsp[-2], yyvsp[0]); }
break;
case 211:
#line 1217 "r2l.y"
{ yyval = list2(sym_not, yyvsp[0]); }
break;
case 212:
#line 1218 "r2l.y"
{ yyval = yyvsp[0]; }
break;
case 213:
#line 1219 "r2l.y"
{ yyval = list2(sym_minus, yyvsp[0]); }
break;
case 215:
#line 1223 "r2l.y"
{ yyval = list3(sym_cons, yyvsp[-2], yyvsp[0]); }
break;
case 224:
#line 1232 "r2l.y"
{ yyval = ncons(yyvsp[0]); }
break;
case 225:
#line 1235 "r2l.y"
{ yyval = list2(sym_not, yyvsp[0]); }
break;
case 226:
#line 1236 "r2l.y"
{ yyval = yyvsp[0]; }
break;
case 227:
#line 1237 "r2l.y"
{ yyval = list2(sym_minus, yyvsp[0]); }
break;
case 229:
#line 1241 "r2l.y"
{ yyval = list3(sym_cons, yyvsp[-2], yyvsp[0]); }
break;
case 231:
#line 1245 "r2l.y"
{ yyval = C_nil; }
break;
case 232:
#line 1246 "r2l.y"
{ yyval = cons(yyvsp[-1], yyvsp[0]); }
break;
case 233:
#line 1249 "r2l.y"
{ yyval = yyvsp[-1]; }
break;
case 234:
#line 1252 "r2l.y"
{ yyval = cons(yyvsp[-3], cons(yyvsp[-1],yyvsp[0])); }
break;
case 235:
#line 1255 "r2l.y"
{ yyval = list3(sym_getv, yyvsp[-3], yyvsp[-1]); }
break;
case 236:
#line 1256 "r2l.y"
{ yyval = cons(yyvsp[-2], C_nil); }
break;
case 237:
#line 1257 "r2l.y"
{ yyval = cons(yyvsp[-1], cons(yyvsp[0], C_nil)); }
break;
case 238:
#line 1258 "r2l.y"
{ yyval = cons(yyvsp[-1], yyvsp[0]); }
break;
case 239:
#line 1259 "r2l.y"
{ yyval = list2(yyvsp[-1], yyvsp[0]); }
break;
case 241:
#line 1263 "r2l.y"
{ yyval = yyvsp[0]; }
break;
case 242:
#line 1264 "r2l.y"
{ yyval = yyvsp[0]; }
break;
case 243:
#line 1265 "r2l.y"
{ yyval = cons(sym_setq, yyvsp[0]); }
break;
case 244:
#line 1266 "r2l.y"
{ yyval = cons(sym_or, yyvsp[0]); }
break;
case 245:
#line 1267 "r2l.y"
{ yyval = cons(sym_and, yyvsp[0]); }
break;
case 246:
#line 1268 "r2l.y"
{ yyval = cons(sym_member, yyvsp[0]); }
break;
case 247:
#line 1269 "r2l.y"
{ yyval = cons(sym_memq, yyvsp[0]); }
break;
case 248:
#line 1270 "r2l.y"
{ yyval = cons(sym_neq, yyvsp[0]); }
break;
case 249:
#line 1271 "r2l.y"
{ yyval = cons(sym_eq, yyvsp[0]); }
break;
case 250:
#line 1272 "r2l.y"
{ yyval = cons(sym_geq, yyvsp[0]); }
break;
case 251:
#line 1273 "r2l.y"
{ yyval = cons(sym_leq, yyvsp[0]); }
break;
case 252:
#line 1274 "r2l.y"
{ yyval = cons(sym_freeof, yyvsp[0]); }
break;
#line 3148 "r2l.c"
    }
    yyssp -= yym;
    yyvsp -= yym;
    yym = yylhs[yyn];
    yystate = *yyssp;
    if (yystate == 0 && yym == 0)
    {
#if YYDEBUG
        if (yydebug)
            printf("yydebug: after reduction, shifting from state 0 to\
 state %d\n", YYFINAL);
#endif
        yystate = YYFINAL;
        *++yyssp = YYFINAL;
        *++yyvsp = yyval;
        if (yychar < 0)
        {
            if ((yychar = yylex()) < 0) yychar = 0;
#if YYDEBUG
            if (yydebug)
            {
                yys = 0;
                if (yychar <= YYMAXTOKEN) yys = yyname[yychar];
                if (!yys) yys = "illegal-symbol";
                printf("yydebug: state %d, reading %d (%s)\n",
                        YYFINAL, yychar, yys);
            }
#endif
        }
        if (yychar == 0) goto yyaccept;
        goto yyloop;
    }
    yyn = yygindex[yym];
	 if (yyn != 0
        && ((yyn += yystate), ((unsigned)yyn <= (unsigned)YYTABLESIZE))
        && yycheck[yyn] == yystate)
        yystate = yytable[yyn];
    else
        yystate = yydgoto[yym];
#if YYDEBUG
    if (yydebug)
        printf("yydebug: after reduction, shifting from state %d \
to state %d\n", *yyssp, yystate);
#endif
    goto yypush;
yyoverflow:
    yyerror("yacc stack overflow");
yyabort:
    return (1);
yyaccept:
    return (0);
}
