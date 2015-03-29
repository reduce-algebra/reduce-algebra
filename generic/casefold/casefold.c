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
    "printDHMStime"
};


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

static char outword[200];
static int owp = 0;

static void flushword()
{
    int i;
    const char *p1, *p2;
// I do a crude linear search here because this is a cheap enough
// task that optimisation is not really needed.
    for (i=0; i<sizeof(MixedCase)/sizeof(MixedCase[0]); i++)
    {   p1 = outword;
        p2 = MixedCase[i];
        while (*p1!=0 && *p2!=0 &&
               *p1 == tolower(*p2))
        {   p1++;
            p2++;
        }
        if (*p1==0 && *p2==0) break;
    }
    if (*p1==0 && *p2==0) fprintf(fout, "%s", MixedCase[i]);
    else fprintf(fout, "%s", outword);
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
        return;
case 1: if (!isalnum(c) && c!='_')
        {   if (owp != 0) flushword();
            putc(c, fout);
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
    char prev[12];
    const char *fname = NULL;
    int i, c = '\n', c1;
    FILE *fin = stdin;
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
    memset(prev, ' ', sizeof(prev));
    prev[8] = 0;
    while ((c1 = c, (c = getc(fin)) != EOF))
    {   switch (context)
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
            outch(tolower(c), c=='!' ? 2 : 1);
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
        rename(fname, "old-file");
        rename("tempfile.tmp", fname);
        fprintf(stderr, "Replaced original file\n");
    }
    return 0;
}

// end of casefold.c
