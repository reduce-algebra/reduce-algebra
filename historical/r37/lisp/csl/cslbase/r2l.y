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


/* Signature: 0b607589 21-Apr-2002 */


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

%}

%token	 SETQ
%token	 AND
%token	 OR
%token	 NOT
%token	 MEMBER
%token	 MEMQ
%token	 NEQ
%token	 EQ
%token	 GEQ
%token	 LEQ
%token	 FREEOF
%token	 SYMBOLIC
%token	 ALGEBRAIC
%token	 EXPR
%token	 MACRO
%token	 SMACRO
%token	 PROCEDURE
%token	 FOR
%token	 STEP
%token	 UNTIL
%token	 EACH
%token	 FOREACH
%token	 IN
%token	 ON
%token	 DO
%token	 COLLECT
%token	 SUM
%token	 IF
%token	 THEN
%token	 ELSE
%token	 REPEAT
%token	 UNTIL
%token	 WHILE
%token	 BEGIN
%token	 END
%token   ENDFILE
%token	 LSECT
%token	 RSECT
%token	 GO
%token	 TO
%token	 GOTO
%token	 SCALAR
%token	 INTEGER
%token	 LAMBDA
%token	 SYMBOL
%token	 NUMBER
%token	 STRING
%token	 LIST
%token	 RETURN
%token	 WHERE
%token	 RLISTAT
%token	 ENDSTAT
%token   HASHIF
%token   HASHELSE
%token   HASHELIF
%token   HASHENDIF
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

command		:  cmnd sep		{ evalorprint($1); 
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

proc_type	:  SYMBOLIC		{ $$ = sym_symbolic; }
		|  ALGEBRAIC		{ $$ = sym_algebraic; }
		;

proc_qual	:  EXPR			{ $$ = sym_de; }
		|  MACRO		{ $$ = sym_dm; }
		|  SMACRO		{ $$ = sym_ds; }
		;

sym_list	:  ')'			{ $$ = C_nil; }
		|  ',' SYMBOL sym_list	{ $$ = cons($2, $3); }
		;
/*
 * RLISP seems to want to be able to write
 *    procedure a >= b; ...
 * with an infix operator being defined!
 */

infix		:  SETQ			{ $$ = sym_setq; }
		|  OR			{ $$ = sym_or; }
		|  AND			{ $$ = sym_and; }
		|  MEMBER		{ $$ = sym_member; }
		|  MEMQ			{ $$ = sym_memq; }
		|  '='			{ $$ = sym_equal; }
		|  NEQ			{ $$ = sym_neq; }
		|  EQ			{ $$ = sym_eq; }
		|  GEQ			{ $$ = sym_geq; }
		|  '>'			{ $$ = sym_greaterp; }
		|  LEQ			{ $$ = sym_leq; }
		|  '<'			{ $$ = sym_lessp; }
		|  FREEOF		{ $$ = sym_freeof; }
		|  '+'			{ $$ = sym_plus; }
		|  '-'			{ $$ = sym_difference; }
		|  '*'			{ $$ = sym_times; }
		|  '/'			{ $$ = sym_quotient; }
		|  '^'			{ $$ = sym_expt; }
		|  '.'			{ $$ = sym_cons; }
		;

prefix		:  NOT			{ $$ = sym_not; }
		|  '+'			{ $$ = sym_plus; }
		|  '-'			{ $$ = sym_minus; }
		;

proc_head	:  SYMBOL		{ $$ = cons($1, C_nil); }
		|  SYMBOL SYMBOL	{ $$ = list2($1, $2); }
		|  SYMBOL '(' ')'	{ $$ = cons($1, C_nil); }
		|  SYMBOL '(' SYMBOL sym_list
					{ $$ = cons($1, cons($3, $4)); }
		|  prefix SYMBOL	{ $$ = list2($1, $2); }
		|  SYMBOL infix SYMBOL	{ $$ = list3($2, $1, $3); }
		;

proc_def	:  PROCEDURE proc_head sep cmnd
					{ $$ = list4(sym_de, qcar($2), qcdr($2), $4); }
		|  proc_type PROCEDURE proc_head sep cmnd
					{ $$ = list4(sym_de, qcar($3), qcdr($3), $5); }
		|  proc_qual PROCEDURE proc_head sep cmnd
					{ $$ = list4($1, qcar($3), qcdr($3), $5); }
		|  proc_type proc_qual PROCEDURE proc_head sep cmnd
					{ $$ = list4($2, qcar($4), qcdr($4), $6); }
		;

rlistat		:  RLISTAT
		|  IN			{ $$ = sym_in; }
		|  ON			{ $$ = sym_on; }
		;

rltail		:  expr			{ $$ = cons($1, C_nil); }
		|  expr ',' rltail	{ $$ = cons($1, $3); }
		;

/*
 * The category "cmnd" really only needs separating out to try to
 * control the comma-lists in RLIS things.
 */

cmnd		:  expr
		|  rlistat rltail	{ $$ = list2($1, cons(sym_list, $2)); }
		;

/*
 * As written here the grammar exhibits the traditional "dangling else"
 * ambiguity.  This must be resolved as SHIFT rather than REDUCE for
 * the proper results to emerge.
 */

if_stmt		:  IF expr THEN cmnd ELSE cmnd
					{ $$ = list4(sym_if, $2, $4, $6); }
		|  IF expr THEN cmnd	{ $$ = list3(sym_if, $2, $4); }
		;

for_update	:  ':' expr		{ $$ = cons(find_symbol("1"), $2); }
		|  STEP expr UNTIL expr	{ $$ = cons($2, $4); }
		;

for_action	:  DO			{ $$ = sym_do; }
		|  SUM			{ $$ = sym_sum; }
		|  COLLECT		{ $$ = sym_collect; }
		;

for_inon	:  IN			{ $$ = sym_in; }
		|  ON			{ $$ = sym_on; }
		;

for_stmt	:  FOR SYMBOL SETQ expr for_update for_action cmnd
					{ $$ = make_for($2, $4, qcar($5), qcdr($5), $6, $7); }
		|  FOR EACH SYMBOL for_inon expr for_action cmnd
					{ $$ = make_foreach($3, $4, $5, $6, $7); }
		|  FOREACH SYMBOL for_inon expr for_action cmnd
					{ $$ = make_foreach($2, $3, $4, $5, $6); }
		;

while_stmt	:  WHILE expr DO cmnd {
       int lab1 = genlabel();
       $$ = list6(sym_prog, C_nil, lab1,
                  list3(sym_if, list2(sym_null, $2), list2(sym_return, C_nil)),
                  $4,
                  list2(sym_go, lab1)); }
		;

repeat_stmt	:  REPEAT cmnd UNTIL expr {
       int lab1 = genlabel();
       $$ = list5(sym_prog, C_nil, lab1,
                  $2,
                  list3(sym_if, list2(sym_null, $4), list2(sym_go, lab1))); }
		;

return_stmt	:  RETURN		{ $$ = list2(sym_return, C_nil); }
		|  RETURN expr		{ $$ = list2(sym_return, $2); }
		;

goto_stmt	:  GOTO SYMBOL		{ $$ = list2(sym_go, $2); }
		|  GO SYMBOL		{ $$ = list2(sym_go, $2); }
		|  GO TO SYMBOL		{ $$ = list2(sym_go, $3); }
		;

group_tail	:  RSECT		{ $$ = C_nil; }
		|  sep RSECT		{ $$ = C_nil; }
		|  sep cmnd group_tail	{ $$ = cons($2, $3); }
		;

group_expr	:  LSECT cmnd group_tail{ $$ = cons(sym_progn, cons($2, $3)); }
		;

scalar_tail	:  sep			{ $$ = C_nil; }
		|  ',' SYMBOL scalar_tail
					{ $$ = cons($2, $3); }
		|  ',' INTEGER scalar_tail
					{ $$ = cons($2, $3); }
		;

scalar_def	:  SCALAR SYMBOL scalar_tail
					{ $$ = cons($2, $3); }
scalar_def	:  INTEGER SYMBOL scalar_tail
					{ $$ = cons($2, $3); }
		;

scalar_defs	:  scalar_def
		|  scalar_defs scalar_def
					{ $$ = append($1, $2); }
		;

block_tail	:  END			{ $$ = C_nil; }
		|  cmnd END		{ $$ = cons($1, C_nil); }
		|  SYMBOL ':' block_tail{ $$ = cons($1, $3); }
		|  cmnd sep block_tail	{ $$ = cons($1, $3); }
		|  sep block_tail	{ $$ = $2; }
		;

block_expr	:  BEGIN scalar_defs block_tail
					{ $$ = cons(sym_prog, cons($2, $3)); }
		|  BEGIN block_tail	{ $$ = cons(sym_prog, cons(C_nil, $2)); }
		;

lambda_vars	:  sep			{ $$ = C_nil; }
		|  ',' SYMBOL lambda_vars
					{ $$ = cons($2, $3); }
		;

lambda_expr	:  LAMBDA SYMBOL lambda_vars cmnd
					{ $$ = list3(sym_lambda, ncons($2), $3); }
		|  LAMBDA '(' ')' sep cmnd
					{ $$ = list3(sym_lambda, C_nil, $5); }
		|  LAMBDA '(' SYMBOL sym_list sep cmnd
					{ $$ = list3(sym_lambda, cons($3, $4), $6); }
		;

/*
 * In what follows rx0 is an expression which MUST end if a key-command,
 * while lx0 is an expression which MUST NOT.
 */

expr		:  rx0
		|  lx0
		;

rx0		:  lx0 WHERE SYMBOL '=' rx1
					{ $$ = make_where($1, $3, $5); }
		|  rx1
		;

lx0		:  lx0 WHERE SYMBOL '=' lx1
					{ $$ = make_where($1, $3, $5); }
		|  lx1
		;

rx1		:  lx2 SETQ rx1		{ $$ = list3(sym_setq, $1, $3); }
		|  rx2
		;

lx1		:  lx2 SETQ lx1		{ $$ = list3(sym_setq, $1, $3); }
		|  lx2
		;

rx2tail		:  rx3			{ $$ = ncons($1); }
		|  lx3 OR rx2tail	{ $$ = cons($1, $3); }

rx2		:  lx3 OR rx2tail	{ $$ = cons(sym_or, cons($1, $3)); }
		|  rx3
		;

lx2tail		:  lx3			{ $$ = ncons($1); }
		|  lx3 OR lx2tail	{ $$ = cons($1, $3); }

lx2		:  lx3 OR lx2tail	{ $$ = cons(sym_or, cons($1, $3)); }
		|  lx3
		;

rx3tail		:  rx4			{ $$ = ncons($1); }
		|  lx4 AND rx3tail	{ $$ = cons($1, $3); }

rx3		:  lx4 AND rx3tail	{ $$ = cons(sym_and, cons($1, $3)); }
		|  rx4
		;

lx3tail		:  lx4			{ $$ = ncons($1); }
		|  lx4 AND lx3tail	{ $$ = cons($1, $3); }

lx3		:  lx4 AND lx3tail	{ $$ = cons(sym_and, cons($1, $3)); }
		|  lx4
		;

rx4		:  NOT rx4		{ $$ = list2(sym_not, $2); }
		|  rx5
		;

lx4		:  NOT lx4		{ $$ = list2(sym_not, $2); }
		|  lx5
		;

rx5		:  lx6 MEMBER ry6	{ $$ = list3(sym_member, $1, $3); }
		|  lx6 MEMQ ry6		{ $$ = list3(sym_memq, $1, $3); }
		|  lx6 '=' ry6		{ $$ = list3(sym_equal, $1, $3); }
		|  lx6 NEQ ry6		{ $$ = list3(sym_neq, $1, $3); }
		|  lx6 EQ ry6		{ $$ = list3(sym_eq, $1, $3); }
		|  lx6 GEQ ry6		{ $$ = list3(sym_geq, $1, $3); }
		|  lx6 '>' ry6		{ $$ = list3(sym_greaterp, $1, $3); }
		|  lx6 LEQ ry6		{ $$ = list3(sym_leq, $1, $3); }
		|  lx6 '<' ry6		{ $$ = list3(sym_lessp, $1, $3); }
		|  lx6 FREEOF ry6	{ $$ = list3(sym_freeof, $1, $3); }
		|  rx6
		;

lx5		:  lx6 MEMBER ly6	{ $$ = list3(sym_member, $1, $3); }
		|  lx6 MEMQ ly6		{ $$ = list3(sym_memq, $1, $3); }
		|  lx6 '=' ly6		{ $$ = list3(sym_equal, $1, $3); }
		|  lx6 NEQ ly6		{ $$ = list3(sym_neq, $1, $3); }
		|  lx6 EQ ly6		{ $$ = list3(sym_eq, $1, $3); }
		|  lx6 GEQ ly6		{ $$ = list3(sym_geq, $1, $3); }
		|  lx6 '>' ly6		{ $$ = list3(sym_greaterp, $1, $3); }
		|  lx6 LEQ ly6		{ $$ = list3(sym_leq, $1, $3); }
		|  lx6 '<' ly6		{ $$ = list3(sym_lessp, $1, $3); }
		|  lx6 FREEOF ly6	{ $$ = list3(sym_freeof, $1, $3); }
		|  lx6
		;

ry6		:  NOT ry6		{ $$ = list2(sym_not, $2); }
		|  rx6
		;

ly6		:  NOT ly6		{ $$ = list2(sym_not, $2); }
		|  lx6
		;

rx6tail		:  ry6a			{ $$ = ncons($1); }
		|  ly6a '+' rx6tail	{ $$ = cons($1, $3); }

rx6		:  lx6a '+' rx6tail	{ $$ = cons(sym_plus, cons($1, $3)); }
		|  rx6a
		;

lx6tail		:  ly6a			{ $$ = ncons($1); }
		|  ly6a '+' lx6tail	{ $$ = cons($1, $3); }

lx6		:  lx6a '+' lx6tail	{ $$ = cons(sym_plus, cons($1, $3)); }
		|  lx6a
		;

ry6a		:  NOT ry6a		{ $$ = list2(sym_not, $2); }
		|  rx6a
		;

rx6a		:  lx6a '-' ry7		{ $$ = list3(sym_difference, $1, $3); }
		|  rx7
		;

ly6a		:  NOT ly6a		{ $$ = list2(sym_not, $2); }
		|  lx6a
		;

lx6a		:  lx6a '-' ly7		{ $$ = list3(sym_difference, $1, $3); }
		|  lx7
		;

ry7		:  NOT ry7		{ $$ = list2(sym_not, $2); }
		|  rx7
		;

rx7		:  '+' ry7		{ $$ = $2; }
		|  '-' ry7		{ $$ = list2(sym_minus, $2); }
		|  rx8
		;

ly7		:  NOT ly7		{ $$ = list2(sym_not, $2); }
		|  lx7
		;

lx7		:  '+' ly7		{ $$ = $2; }
		|  '-' ly7		{ $$ = list2(sym_minus, $2); }
		|  lx8
		;

rx8tail		:  ry9			{ $$ = ncons($1); }
		|  ly9 '*' rx8tail	{ $$ = cons($1, $3); }

rx8		:  lx9 '*' rx8tail	{ $$ = cons(sym_times, cons($1, $3)); }
		|  rx9
		;

lx8tail		:  ly9			{ $$ = ncons($1); }
		|  ly9 '*' lx8tail	{ $$ = cons($1, $3); }

lx8		:  lx9 '*' lx8tail	{ $$ = cons(sym_times, cons($1, $3)); }
		|  lx9
		;

ry9		:  NOT ry9		{ $$ = list2(sym_not, $2); }
		|  '+' ry9              { $$ = $2; }
		|  '-' ry9              { $$ = list2(sym_minus, $2); }
		|  rx9
		;

rx9		:  lx9 '/' ry10		{ $$ = list3(sym_quotient, $1, $3); }
		|  rx10
		;

ly9		:  NOT ly9		{ $$ = list2(sym_not, $2); }
		|  '+' ly9              { $$ = $2; }
		|  '-' ly9              { $$ = list2(sym_minus, $2); }
		|  lx9
		;

lx9		:  lx9 '/' ly10		{ $$ = list3(sym_quotient, $1, $3); }
		|  lx10
		;

ly10		:  NOT ly10		{ $$ = list2(sym_not, $2); }
		|  '+' ly10		{ $$ = $2; }
		|  '-' ly10		{ $$ = list2(sym_minus, $2); }
		|  lx10
		;

lx10		:  lx11 '^' ly10	{ $$ = list3(sym_expt, $1, $3); }
		|  lx11
		;

ry10		:  NOT ry10		{ $$ = list2(sym_not, $2); }
		|  '+' ry10		{ $$ = $2; }
		|  '-' ry10		{ $$ = list2(sym_minus, $2); }
		|  rx10
		;

rx10		:  lx11 '^' ry10	{ $$ = list3(sym_expt, $1, $3); }
		|  rx11
		;

ry11		:  NOT ry11		{ $$ = list2(sym_not, $2); }
		|  '+' ry11		{ $$ = $2; }
		|  '-' ry11		{ $$ = list2(sym_minus, $2); }
		|  rx11
		;

rx11		:  x12 '.' ry11		{ $$ = list3(sym_cons, $1, $3); }
		|  if_stmt
		|  for_stmt
		|  while_stmt
		|  repeat_stmt
		|  return_stmt
		|  goto_stmt
		|  lambda_expr
		|  proc_def
		|  ENDSTAT		{ $$ = ncons($1); }
		;

ly11		:  NOT ly11		{ $$ = list2(sym_not, $2); }
		|  '+' ly11		{ $$ = $2; }
		|  '-' ly11		{ $$ = list2(sym_minus, $2); }
		|  lx11
		;

lx11		:  x12 '.' ly11		{ $$ = list3(sym_cons, $1, $3); }
		|  x12
		;

arg_list	:  ')'			{ $$ = C_nil; }
		|  ',' expr arg_list	{ $$ = cons($2, $3); }
		;

parened         :  '(' expr ')'        { $$ = $2; }
                ;

commaparened    :  '(' expr ',' expr arg_list { $$ = cons($2, cons($4,$5)); }
                ;

x12notparened	:  x13b '[' expr ']'	{ $$ = list3(sym_getv, $1, $3); }
                |  x13b '(' ')'         { $$ = cons($1, C_nil); }
		|  x13b parened    	{ $$ = cons($1, cons($2, C_nil)); }
		|  x13b commaparened   	{ $$ = cons($1, $2); }
		|  x13b x12notparened	{ $$ = list2($1, $2); }
		|  x13b
                ;

x12             :  x12notparened	{ $$ = $1; }
                |  parened		{ $$ = $1; }
                |  SETQ commaparened	{ $$ = cons(sym_setq, $2); }
		|  OR commaparened	{ $$ = cons(sym_or, $2); }
		|  AND commaparened	{ $$ = cons(sym_and, $2); }
		|  MEMBER commaparened	{ $$ = cons(sym_member, $2); }
		|  MEMQ commaparened	{ $$ = cons(sym_memq, $2); }
		|  NEQ commaparened	{ $$ = cons(sym_neq, $2); }
		|  EQ commaparened	{ $$ = cons(sym_eq, $2); }
		|  GEQ commaparened	{ $$ = cons(sym_geq, $2); }
		|  LEQ commaparened	{ $$ = cons(sym_leq, $2); }
		|  FREEOF commaparened	{ $$ = cons(sym_freeof, $2); }
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
