// casefold.c                                       A C Norman March 2015


/**************************************************************************
 * Copyright (C) 2015, Codemist Ltd.                     A C Norman       *
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

/* $Id: version.h 2688 2014-09-20 16:52:18Z arthurcnorman $ */


// This code is used to scour Reduce source code and normalise case.
// There are some identifiers that ought to remain in upper or mixed case
// and I list them expicitly here. Anybody who believes that my code has
// damaged matters may add their own choice of exceptions here - but on so
// doing I hope that they will check use of the same word in files other
// than their own and avoid conflict.

// I make a plausible attempt to get things right here, but I leave comments
// and the contents of strings untouched, so they may deserve manual
// attention later. I also support rlisp88 "/*" style comments and hope that
// the sequence "/*" does not and will not arise anywhere else in the souces!
//
// Hmm - I will also avoid case-folding within a sequence that goes
//             #alphanumerics;
// I will achieve this by not casefolding anything from a "#" to the next
// non alphanumeric character. A consequence will be that "#IF" and "#If"
// will not be normalised, but I will accept that limitation in the name of
// simplicity.

// Usage:
//    casefold filename
// Perform simple uniform case-folding on all symbolic in the given file and
// write the results back to that file. Leave a copy of the original
// version in "filename.pre-casefold". If you run casefold twice the backup
// will only let you go back one step. Those worsd listed in the array
// MixedCase in the source file end up capitalized as shown there - everything
// else (outside comments, strings and character escapes) goes to lower case.
//
//    casefold + filename [[:] Word]*
// Performs custom folding on the file, putting the adjusted version back
// in place. The only words that are adjusted are those in th list of words
// specifed on the command line. If a word the is preceeded by a ":" that
// capitalisation applies where the word is ued in a context that the
// Reduce "assert" package thinks of as a type-name. So
//    casefold + myfile.red oneWord : OneWord ...
// would map "oneword" and all other initial capitalisations of that
// sequence of letters onto "oneWord" in general contexts and "OneWord" after
// a ":".
// The contexts for type-names are
//   procedure ... : Name ... (; | $)
//   declare   ... : Name ... (; | $)
//   scalar    ... : Name ... (; | $)
//   typedef Name 
//   struct  Name
// Well more pedantically with procedure or scalar after a ":" you are in
// "type" mode up to the next ")" or a "," that is not nested within parens
// brackets or braces.
// Thus one might permit
//   begin scalar fn:SQ->SQ, u:{Integer,SQ,SQ}, a:Atom;
// or some such. It is not the job of thus utility to decide just what
// syntax will be used for type annotations - it just wants to support what
// exists now and what seems plausible by way of extensions to that!
//
// A "typical" use in this mode might be
//   casefold + sourcefile.red sq : SQ
// intended  to force a procedure header into eg the form
//    symbolic procedure hugo(sq:SQ):SQ;
// where the variable name is in lower case and the type-name in upper.


#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

// The following words, when used within the Reduce sources, will end up
// with the upper or mixed case as shown here.

static const char *MixedCase[] =
{
    "!*NoInt",
    "!*TayExp2q",
    "!*TeX",
    "!*TeXbreak",
    "!*TeXindent",
    "*NoInt",
    "*TayExp2q",
    "*TeX",
    "*TeXbreak",
    "*TeXindent",
    "Airy_Ai",
    "Airy_Bi",
    "Airy_Aiprime",
    "Airy_Biprime",
    "BesselI",
    "BesselJ",
    "BesselK",
    "BesselY",
    "ChebyshevT",
    "ChebyshevU",
    "Catalan",
    "COMMENT",
    "Ei",
    "Euler",
    "Euler_gamma",
    "Fact_mat",
    "Fresnel_C",
    "Fresnel_S",
    "GAnu",
    "GegenbauerP",
    "Gram+Schmid",
    "HermiteP",
    "Heaviside",
    "Iri",
    "JacobiP",
    "KernelList",
    "Khinchin",
    "KummerM",
    "KummerU",
    "LaguerreP",
    "LegendreP",
    "LegendreQ",
    "Lerch_phi",
    "Lommel2sq",
    "MeijerG",
    "ODESolve-Exact*",
    "ODESolve-Int",
    "ODESolve-Make-Explicit",
    "ODESolve-NonLinear1",
    "ODESolve-Solns",
    "Pochhammer",
    "RecursionSimplify",
    "SFList",
    "SU_order",
    "Spur_TT",
    "Stieltjes",
    "StruveH",
    "StruveL",
// I think that the "tri" package has good cause to spell its
// prefix "TeX" not "tex".
    "TeX",
    "TeXpri",
    "TeXvarpri",
    "TeXindxpri",
    "TeXgroup",
    "TeXitem",
    "TeXexplode",
    "TeXcollect",
    "TeXexplist",
    "TeXassertset",
    "TeXretractset",
    "TeXstrlen",
    "TeXout",
    "TeXsetbreak",
    "TeXtolerance",
    "TeXpagewidth",
    "TeXlet",
    "TeXdisplay",
    "TeXbreak",
    "TeXexa",
    "TeXindent",
    "TeXsetbreak",
    "TeXaeval",
    "TeXlet",
    "TeXpr1a",
    "Theory",
    "WhittakerM",
    "WhittakerW",
    "bigA",
    "definitionURL",
    "groebPosCancel",
    "printDHMStime",
    NULL                 // termination!
};


static const char *regularNames[100];
static const char *typeNames[100];

static int regularNamesCount = 0, typeNamesCount = 0;

// This enum is for "type context" detection.
//
// It corresponds to a state machine:
//
//                   declare
//    GENERAL    ---procedure---> PROCEDURE
//                   scalar
//
//    GENERAL    ----typedef----> TYPEDEF
//                   struct
//
//    GENERAL    -----other-----> GENERAL
//
//    PROCEDURE  -------:-------> ARGTYPE
//    PROCEDURE  -----(;|$)-----> GENERAL
//    PROCEDURE  -----other-----> PROCEDURE
//
//    ARGTYPE    -------,-------> PROCEDURE
//    ARGTYPE    -----(;|$)-----> GENERAL
//    ARGTYPE    ----symbol*----> ARGTYPE
//    ARGTYPE    -----other-----> ARGTYPE
//
//    TYPEDEF    ----symbol*----> GENERAL
//    TYPEDEF    -----other-----> GENERAL
//
// The annotation "symbol*" indicates a symbol that is mapped as a type name
// not as a general word. There are some pathologies with input such as
//   "typedef procedure ..."
// as to whether the word "procedure" is to be treated as a symbopl or as a
// reserved word. I will ignore such concerns since in valid input they
// should not arise.
//

enum
{
   GENERAL,
   PROCEDURE,
   ARGTYPE,
   TYPEDEF
};

// This enum is for string and comment detection.
enum
{
    PLAIN,
    PERCENT,
    COMMENT,
    COMMENT88,
    COMMENT88a,
    COMMENT88b,
    STRING,
    HASHED,
    ESCAPED
};

static FILE *fout;

#define MAX_LINE 1000

static char origline[MAX_LINE], newline[MAX_LINE];
static char outword[MAX_LINE];
static int origlinep = 0, newlinep = 0, owp = 0;
static int simplemode = 1;
static int typecontext = GENERAL;

static void check_endline()
{
    origline[origlinep] = 0;
    newline[newlinep] = 0;
    if (strcmp(origline, newline) != 0)
    {   fprintf(stderr, "Original:  %s", origline);
        fprintf(stderr, "Converted: %s\n", newline);
    }
    origlinep = newlinep = 0;
}

static void flushword()
{
    int i;
    const char *p1, *p2;
// I do a crude linear search here because this is a cheap enough
// task that optimisation is not really needed.
    const char **wordlist = MixedCase;
    if (simplemode == 0)
    {   if (typecontext == ARGTYPE ||
            typecontext == TYPEDEF) wordlist = typeNames;
        else wordlist = regularNames;
    }
    for (i=0; wordlist[i]!=NULL; i++)
    {   p1 = outword;
        p2 = wordlist[i];
        while (*p1!=0 && *p2!=0 &&
               tolower(*p1) == tolower(*p2))
        {   p1++;
            p2++;
        }
        if (*p1==0 && *p2==0) break;
    }
    if (*p1==0 && *p2==0) p1 = wordlist[i];
    else
    {   p1 = outword;
        if (simplemode)
        {   int prevesc = 0;
            char *p3 = outword;
            while (*p3 != 0)
            {   if (!prevesc) *p3 = tolower(*p3);
                prevesc = (*p3 == '!');
                p3++;
            }
        }
    }
    switch (typecontext)
    {
case GENERAL:
// I am aware that strcasecmp is not ANSI C but it is Posix. If needbe I could
// implement my own version.
        if (strcasecmp(p1, "procedure") == 0 ||
            strcasecmp(p1, "declare")   == 0 ||
            strcasecmp(p1, "scalar")    == 0) typecontext = PROCEDURE;
        else if (strcasecmp(p1, "struct")  == 0 ||
                 strcasecmp(p1, "typedef") == 0) typecontext = TYPEDEF;
        else if (typecontext == TYPEDEF) typecontext = GENERAL;
default:
        break;
    }
    while (*p1 != 0)
    {   putc(*p1, fout);
        newline[newlinep++] = *p1;
        if (*p1 == '\n') check_endline();
        p1++;
    }
    owp = 0;
}

// mode is zero if the character is part of a string or comment.
//         1 for a normal character
//         2 for parts of a "!x" escape pair

static void outch(int c, int mode)
{
    switch (mode)
    {
case 0: if (owp != 0) flushword();
        putc(c, fout);
        newline[newlinep++] = c;
        if (c == '\n') check_endline();
        return;
case 1: if (!isalnum(c) && c!='_')
        {   if (owp != 0) flushword();
            putc(c, fout);
            switch (typecontext)
            {
        case PROCEDURE:
                if (c == ':') typecontext = ARGTYPE;
                else if (c == ';' || c == '$') typecontext = GENERAL;
                break;
        case ARGTYPE:
                if (c == ',') typecontext = PROCEDURE;
                else if (c == ';' || c == '$') typecontext = GENERAL;
                break;
        default:
                break;
            }
            newline[newlinep++] = c;
            if (c == '\n') check_endline();
            return;
        }
        // drop through
case 2: outword[owp++] = c;
        outword[owp] = 0;
        if (owp >= sizeof(outword)-1)
        {   fprintf(stderr, "Word too long\n%s\n", outword);
            exit(1);
        }
        return;
    }    
}

int main(int argc, char *argv[])
{
// Leave characters alone in the following contexts...
//     % ... EOL
//     COMMENT ... ; or $
//     " ... "
//     !<char>
//     # <alphanumerics> ;
    int context = PLAIN;
    char prev[12], old_filename[300];
    const char *fname = NULL;
    int i, c = '\n', c1;
    FILE *fin = stdin;
// Detect an initial argument that is "+" and flag it and so a "shift"
// operation.
    simplemode = 1;
    if (argc > 1 && strcmp(argv[1], "+") == 0)
    {   simplemode = 0;
        argc--;
        argv++;
    }
    if (argc > 1) fin = fopen(fname = argv[1], "r");
    if (fin == NULL)
    {   fprintf(stderr, "Unable to read input file\n");
        exit(1);
    }
    if (fname == NULL) fout = stdout;
    else fout = fopen("tempfile.tmp", "w");
    if (fout == NULL)
    {   fprintf(stderr, "Unable to write to output file\n");
        exit(1);
    }
// In complicated mode grab the rest of the arguments.
    if (!simplemode)
    {   int j;
        int typecase = 0;
// Note that argv[1] is the file name so exception info starts at argv[2]
        for (j=2; j<argc; j++)
        {   if (strcmp(argv[j], ":") == 0)
            {   typecase = 1;
                continue;
            }
            if (typecase) typeNames[typeNamesCount++] = argv[j];
            else regularNames[regularNamesCount++] = argv[j];
            typecase = 0;
        }
        typeNames[typeNamesCount] = NULL;
        regularNames[regularNamesCount] = NULL;
        for (j=0; j<regularNamesCount; j++)
            printf("R%d] %s\n", j, regularNames[j]);
        for (j=0; j<typeNamesCount; j++)
            printf("T%d] %s\n", j, typeNames[j]);
    }
    memset(prev, ' ', sizeof(prev));
    prev[8] = 0;
    while ((c1 = c, (c = getc(fin)) != EOF))
    {   origline[origlinep++] = c;
        if (origlinep > MAX_LINE-2)
        {   fprintf(stderr, "\n+++ Overlong input line\n");
            exit(1);
        }
        switch (context)
        {
    case COMMENT88:
// Here I just has a "/" in PLAIN context and I need to check for a "*";
            if (c == '*')
            {   outch('/', 0);
                outch(c, 0);
                context = COMMENT88a;
                continue;
            }
            context = PLAIN;
            outch('/', 0);
            // drop through
    case PLAIN:
            if (c == '/')
            {   context = COMMENT88;
                continue;
            }
            outch(c, c=='!' ? 2 : 1);
            if (c == '%') context = PERCENT;
            else if (c == '#') context = HASHED;
            else if (c == '"') context = STRING;
            else if (c == '!') context = ESCAPED;
            if (!isalnum(c) &&
                !isalnum(prev[0]) &&
                strcmp(&prev[1], "comment") == 0) context = COMMENT;
            for (i=0; i<7; i++) prev[i] = prev[i+1];
            prev[7] = tolower(c);
            continue;
    case COMMENT88a:
// I will not permit "/*" comments to nest...
            if (c == '*') context = COMMENT88b;
            outch(c, 0);
            continue;
    case COMMENT88b:
            if (c == '/') context = PLAIN;
            else if (c == '*') context = COMMENT88b;
            else context = COMMENT88a;
            outch(c, 0);
            continue;
    case HASHED:
            if (!isalnum(c) && c != '_') context = PLAIN;
            outch(c, 0);
            continue;
    case PERCENT:
            if (c == '\n') context = PLAIN;
            outch(c, 0);
            continue;
    case COMMENT:
            if (c == ';' || c == '$') context = PLAIN;
            outch(c, 0);
            continue;
    case STRING:
            if (c == '"') context = PLAIN;
            outch(c, 0);
            continue;
    case ESCAPED:
            context = PLAIN;
            outch(c, 2);
            continue;
        }
    }
    if (c1 != '\n') outch('\n', 1);
    fclose(fin);  
    if (fname != NULL)
    {   fclose(fout);
        sprintf(old_filename, "%s.pre-casefold", fname);
        remove(old_filename);
        rename(fname, old_filename);
        rename("tempfile.tmp", fname);
        fprintf(stderr, "Replaced original file\n");
    }
    return 0;
}

// end of casefold.c
