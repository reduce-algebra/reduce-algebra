/* doxtract.c                            Copyright (C) 2011 Codemist Ltd */



/**************************************************************************
 * Copyright (C) 2011, Codemist Ltd.                     A C Norman       *
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
/* Signature: 13e37e4d 18-Nov-2011 */


//
// The idea of this is to provide my own grungy approximation to "javadoc"
// sort of stuff to help me get at least some sort of manual for CSL in a
// more or less complete state. At least closer to "more" than the situation
// prior to this! Building this feels to me to be less effort than
// investigating and using some existing tool. Eg the ones I have looked at
// might expect to be documenting the code written, not how it appears
// reflected into another language. I am confident that somewhere there is
// something I could have used instead of this, but if the code here is
// short enough I do not mind.
//
// Usage:
//    doxtract -p product -t tag -o outfile files
//
// The stuff used here will go in C or C++ header and source files, but it
// is NOT describing the C code itself - it is describing the external
// behaviour as Lisp code. There can also be some things implemented in
// either raw Lisp or in Rlisp.
//
// The things that can be documented are
//    prologue
//    general introduction
//    command-line options
//    predefined variables
//    tags used in the lispsystem* variable
//    flags and properties
//    functions and special forms
// and I may need some others that I have not yet thought about.
//
// The syntax used for all these will be one thing in C/C++ code and another
// in Lisp/Rlisp. For C++ I will support
//
//    /*!!! product1 product2 ...
//     * \documentclass{article}
//     * any other TeX prelude to the sections that follow
//     */
// Specifies that this source file is to be processed if you have
// a matching "-p product" on the command line when doxtract is
// invoked. This should occur before any other special comments. The
// reasoning behind this is that one will wish to go
//    doxtract -p product *.c
// and all the C sources files in the directory get scanned - but some
// will relate to other "products".
//
//    /*!! sectionname [alphakey] title
//     * Any initial text that starts off the section before one drops into
//     * subsections, written in LaTeX format.
//     */
// This defines a section and alphakey indicates the order in which sections
// will appear. The resulting LaTeX will read
//          title
//          Any initial ...
//
// Note that I will insist that the lines within the block all start with
// " * ".
//
//    /*! section subsection-title
//     * Arbitrary TeX material to be the body of the explanation.
//     * ... more TeX ...
//     */
// or
//    /*! section [alphakey] subsection-title
//     ... */
// where "section" is a keyword declared somewhere as a section name. All
// the items that are to go within one section are collected and sorted
// based on the subsection title. If this will contain TeX directives that
// could cause confusion the form "/* section [plain text] subsection-title"
// can be used and the plain text is purely used for sorting. The
// resulting LaTeX will be of the form
//          subsection-title
//          Arbitrary TeX material...
//
// At the end of the generated LaTeX the system will automatically place
// "\end{document}". Any tables of contents, index etc etc need to be
// specified directly.
//
// In Lisp or Rlisp code the corresponding idiom for including documentation
// will be
//    %%! section subsection-title
//    %%  TeX
// and the first line (including perhaps an empty line) that does not start
// with two percent signs terminates the entry.
//
// There will be no need to declare sections before adding entries within
// them, but by the end of processing event section that is used must have
// been declared and hence put into sequence.
//
// Both "/*!" and "/*!!" directives can be followed by a qualifier in square
// brackets that causes the corresponding entry to be used only if the
// scanning program was given a "tag" matching it. So e.g. after
//    doxtract -t extensions -t experimental *.h *.c *.cpp *.lsp *.red
// the included text
//    /*! [experimental] functions experimental_function
//     * ...
//     */
// would be processed.
//
// This code is intended for use just with CSL and I do not want to spend
// more effort developing it than is absolutely necessary. Especially until
// I discover how comfortable I feel using it. So I will code things in
// a crude and naive manner! Specifically I may have rigid memory allocation
// and a lack of concern with buffer overflows.
//


// Just for my own interest, I note that the CSL source directory has around
// 5 Mbytes of "source stuff" in it and so that gives the magnitude of data
// I am liable to be working with. Amazingly the Reduce "packages" directory
// has only about 13 Mbytes of *.red files in it and so with current computers
// I will not have any problems at all just storing everything in memory.


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

static const char *product = NULL;
static const char *output = "manual.tex";
#define MAX_TAGS 10
static const char *tags[MAX_TAGS];
static int n_tags = 0;
#define MAX_FILES 1000
static const char *files[MAX_FILES];
static int n_files = 0;

static void process_file(const char *fname);
static void dump_tex();

int main(int argc, char *argv[])
{
    int i;
    for (i=1; i<argc; i++)
    {   const char *a = argv[i];
        if (strcmp(a, "--help") == 0)
        {   printf("Usage: %s [-p prod] [-t tag]* file*\n", argv[0]);
            exit(0);
        }
        else if (strcmp(a, "-p") == 0 || strcmp(a, "-P") == 0)
        {   i++;
            if (i < argc) product = argv[i];
        }
        else if (strcmp(a, "-o") == 0 || strcmp(a, "-O") == 0)
        {   i++;
            if (i < argc) output = argv[i];
        }
        else if (strcmp(a, "-t") == 0 || strcmp(a, "-T") == 0)
        {   i++;
            if (i < argc && n_tags < MAX_TAGS) tags[n_tags++] = argv[i];
        }
        else if (n_files < MAX_FILES) files[n_files++] = a;
    }
    for (i=0; i<n_files; i++) process_file(files[i]);
    dump_tex();
    return 0;
}

enum Context
{
   Standard,
   Char,
   CharBackslash,
   String,
   StringBackslash,
   Slash,
   SlashSlash,
   SlashStar,
   SlashStarPlain,
   SlashStarStar,
   SlashStarBang
};

static int context = Standard;
static int active = 0;
static void C_doc_comment(FILE *f, int c);
static void lisp_product_comment(FILE *f);
static void lisp_section_comment(FILE *f);
static void lisp_doc_comment(FILE *f);

#define MAX_LINE 512
static char line[MAX_LINE+1];
int n_line = 0;

static void process_file(const char *file)
{
    FILE *f = fopen(file, "r");
    int c, lisp_mode = 0;
    if (f == NULL)
    {   printf("Input file %s could not be opened\n", file);
        printf("Ignoring it and continuing...\n");
        return;
    }

    c = strlen(file)-4;
    if (strcmp(file+c, ".lsp") == 0 ||
        strcmp(file+c, ".red") == 0) lisp_mode = 1;

    context = Standard;
    active = 0;
    if (lisp_mode)
    {   for (;;)
        {   n_line = 0;
            while ((c = getc(f)) != EOF && c != '\n')
            {   if (c == '\r') continue;
                if (n_line < MAX_LINE) line[n_line++] = c;
            }
            if (c == EOF && n_line == 0) break;
            line[n_line] = 0;
            if (line[0] == '%' &&
                line[1] == '%' &&
                line[2] == '!')
            {   if (line[3] == '!' &&
                    line[4] == '!') lisp_product_comment(f);
                else if (line[3] == '!') lisp_section_comment(f);
                else lisp_doc_comment(f);
            }
        }
    }
    else while ((c = getc(f)) != EOF)
    {   if (c == '\r') continue;
        switch (context)
        {
   case Standard:
            if (c == '\'') context = Char;
            else if (c == '\"') context = String;
            else if (c == '/') context = Slash;
            continue;
   case Char:
            if (c == '\\') context = CharBackslash;
            else if (c == '\'') context = Standard;
            continue;
   case CharBackslash:
/*
 * I just ignore one character after a "\" in a character or string
 * literal. This might be held to be not quite proper as regards say
 * \Xnn \Unnnn for characters specified by a numeric code, but it suffices
 * here since all I am needing to do is to detect where the literal ends.
 */
            context = Char;
            continue;
   case String:
            if (c == '\\') context = StringBackslash;
            else if (c == '\"') context = Standard;
            continue;
   case StringBackslash:
            context = String;
            continue;
   case Slash:
            if (c == '/') context = SlashSlash;
            else if (c == '*') context = SlashStar;
            else context = Standard;
            continue;
   case SlashSlash:
            if (c == '\n' || c == EOF) context = Standard;
            continue;
   case SlashStar:
            if (c == '!') context = SlashStarBang;
            else if (c == '*') context = SlashStarStar;
            else context = SlashStarPlain;
            continue;
   case SlashStarPlain:
            if (c == '*') context = SlashStarStar;
            continue;
   case SlashStarStar:
            if (c == '*') context = SlashStarStar;
            else if (c == '/') context = Standard;
            else context = SlashStarPlain;
            continue;
   case SlashStarBang:
            C_doc_comment(f, c);
            context = Standard;
            continue;
        }
    }
    fclose(f);
}

static char *heap(const char *s)
{
    char *r = (char *)malloc(strlen(s)+1);
    if (r == NULL)
    {   printf("malloc failure\n");
        exit(1);
    }
    strcpy(r, s);
    return r;
}

static char *C_until_comment_end(FILE *f, int active);
static void C_section_comment(FILE *f);

#define MAX_HEADER MAX_LINE
static char header[MAX_HEADER+1];
static int n_header = 0;

static void read_header(FILE *f, int c, const char *msg);

#define MAX_SECNAME 64
static char secname[MAX_SECNAME+1];
int n_secname = 0;

#define MAX_ALPHAKEY 256
static char alphakey[MAX_ALPHAKEY+1];
int n_alphakey = 0;

#define MAX_SECHDR 256
static char sechdr[MAX_SECHDR+1];
int n_sechdr = 0;

#define MAX_SUBSECHDR 256
static char subsechdr[MAX_SUBSECHDR+1];
int n_subsechdr = 0;

typedef struct subsection
{
    const char *alphakey;
    const char *subsechdr;
    const char *text;
    struct subsection *next;
} subsection;

static subsection *make_subsection(const char *alphakey, const char *subsechdr,
                                   const char *text, subsection *next)
{
    subsection *r = (subsection *)malloc(sizeof(subsection));
    r->alphakey = alphakey;
    r->subsechdr = subsechdr;
    r->text = text;
    r->next = next;
}

typedef struct section
{
    const char *name;
    const char *alphakey;
    const char *sechdr;
    const char *text;
    subsection *parts;
    struct section *next;
} section;

static section *list_of_sections = NULL;

/*
 * This next seeks a section with a given name and if one already exists
 * it returns it. Otherwise it makes one.
 */
static section *find_section(const char *name)
{
    section *r = list_of_sections;
    while (r != NULL)
    {   if (strcmp(name, r->name) == 0) return r;
        r = r->next;
    }
    r = (section *)malloc(sizeof(section));
    r->name = heap(name);
    r->alphakey = "unset alphakey";
    r->sechdr = "unset section header";
    r->text = "";
    r->parts = NULL;
    r->next = list_of_sections;
    list_of_sections = r;
    return r;
}

static void C_doc_comment(FILE *f, int c)
{
    char *p;
    section *s;
    while (c == '\r') c = getc(f);
    if (c == '!')
    {   C_section_comment(f);
        return;
    }
    read_header(f, c, "subsection");
/* Here I have the case
 *    /*! section subsection-title
 * or /*! section [alphakey] subsection-title
 */
    p = header;
    while (*p == ' ') p++;
    if (*p == 0)
    {   printf("Empty subsection directive\n");
        exit(1);
    }
    n_secname = n_alphakey = n_subsechdr = 0;
    secname[0] = 0;
    alphakey[0] = 0;
    subsechdr[0] = 0;
    for (;;)
    {   c = *p++;
        if (n_secname < MAX_SECNAME) secname[n_secname++] = c;
        if (*p == 0 || *p == ' ') break;
    }
    while (*p == ' ') p++;
    if (*p == '[')
    {   p++;
        while ((c = *p++) != 0 && c != ']')
        {   if (n_alphakey < MAX_ALPHAKEY) alphakey[n_alphakey++] = c;
        }
        if (c == ']') p++;
    }
    while (*p == ' ') p++;
    if (*p != 0)
    {   for (;;)
        {   c = *p++;
            if (n_subsechdr < MAX_SUBSECHDR) subsechdr[n_subsechdr++] = c;
            if (*p == 0) break;
        }
    }
    secname[n_secname] = 0;
    alphakey[n_alphakey] = 0;
    subsechdr[n_subsechdr] = 0;
/* If no alphakey is explicitly given then use the subsection heading */
    if (n_alphakey == 0) strcpy(alphakey, subsechdr);
//  printf("Section: %s\n", secname);
//  printf("AlphaKey: %s\n", alphakey);
//  printf("Sub Heading: %s\n", subsechdr);
    p = C_until_comment_end(f, active);
    s = find_section(secname);
    s->parts = make_subsection(heap(alphakey), heap(subsechdr),
                               heap(p), s->parts);
}

static void read_header(FILE *f, int c, const char *msg)
{
    if (c == '\n' || c == EOF)
    {   printf("Documentation comment with no header information\n");
        exit(1);
    }
    n_header = 0;
    header[n_header++] = c;
    while ((c = getc(f)) != '\n' && c != EOF)
    {   if (c == '\r') continue;
        if (n_header < MAX_HEADER) header[n_header++] = c;
    }
    header[n_header] = 0;
    printf("%s header <%s>\n", msg, header);
}

static void C_product_comment(FILE *f);

static void C_section_comment(FILE *f)
{
    int c = getc(f);
    char *p;
    section *s;
    while (c == '\r') c = getc(f);
    if (c == '!')
    {   C_product_comment(f);
        return;
    }
    read_header(f, c, "section");
/* Here I have the case
 *    /*!! section [alphakey] title
 */
    p = header;
    while (*p == ' ') p++;
    if (*p == 0)
    {   printf("Empty section directive\n");
        exit(1);
    }
    n_secname = n_alphakey = n_sechdr = 0;
    secname[0] = 0;
    alphakey[0] = 0;
    sechdr[0] = 0;
    for (;;)
    {   c = *p++;
        if (n_secname < MAX_SECNAME) secname[n_secname++] = c;
        if (*p == 0 || *p == ' ') break;
    }
    while (*p == ' ') p++;
    if (*p == '[')
    {   p++;
        while ((c = *p++) != 0 && c != ']')
        {   if (n_alphakey < MAX_ALPHAKEY) alphakey[n_alphakey++] = c;
        }
        if (c == ']') p++;
    }
    while (*p == ' ') p++;
    if (*p != 0)
    {   for (;;)
        {   c = *p++;
            if (n_sechdr < MAX_SECHDR) sechdr[n_sechdr++] = c;
            if (*p == 0) break;
        }
    }
    secname[n_secname] = 0;
    alphakey[n_alphakey] = 0;
    sechdr[n_sechdr] = 0;
/* If no alphakey is explicitly given then use the section heading */
    if (n_alphakey == 0) strcpy(alphakey, sechdr);
//  printf("Section: %s\n", secname);
//  printf("AlphaKey: %s\n", alphakey);
//  printf("Heading: %s\n", sechdr);
    p = C_until_comment_end(f, active);
    s = find_section(secname);
    s->alphakey = heap(alphakey);
    s->sechdr = heap(sechdr);
    s->text = heap(p);
}

static const char *top_heading = "";

static void C_product_comment(FILE *f)
{
    const char *p;
    int c = getc(f);
    while (c == '\r') c = getc(f);
    read_header(f, c, "document");
/* Here I have the case
 *    /*!!! product ...
 */
    active = 1;
/*
 * Now if the user had specified "-P product" on the command line I will
 * only enable processing for the rest of this file if the product specified
 * is mentioned as a word on the line.
 */
    if (product != NULL)
    {   const char *l = header , *s;
        int n = strlen(product);
        while ((s = strstr(l, product)) != NULL)
        {   if ((s == header|| isspace(*(s-1))) &&
                (s[n] == 0 || isspace(s[n]))) break;
            l = s+1;
        }
        if (s == NULL) active = 0;
        else printf("Found product tag %s\n", product);
    }
    p = C_until_comment_end(f, active);
    if (p!=NULL && strlen(p) > strlen(top_heading)) top_heading = p;
}

/*
 * MAX_TEXT sets a limit on the largest amount of text that can be
 * placed in a single documentation comment. I rather expect that in
 * any usage I make the actual limit I use will be a kilobyte or so, but
 * I put a limit here that is intended to allow major chapters to be
 * included all within one section. I note that in the Reduce tree the
 * biggest single .tex file is doc/util/reduce.tex - a complete manual in
 * one file - and that is around 300K.
 */
#define MAX_TEXT 400000
static char text[MAX_TEXT+1];
static int n_text;

static char *C_until_comment_end(FILE *f, int active)
{
    int c;
    int first = 1;
    n_text = 0;
    text[n_text] = 0;
/*
 * In the text that I read here I will spot an end of comment as a star
 * followed by a slash, and discard any spaces before that. Also if a line
 * starts with " *" I will discard the "*".
 */
    while ((c = getc(f)) != EOF)
    {   if (c == '\r') continue;
        if (c == '\n') first = 1;
        if (n_text < MAX_TEXT)
        {   text[n_text++] = c;
            text[n_text] = 0; /* keep neatly terminated at all times */
        }
        if (n_text>=2 && strcmp(&text[n_text-2], "*/") == 0)
        {   n_text -= 2;
            while (n_text>= 1 && text[n_text-1]==' ') n_text--;
            break;
        }
        else if (n_text>=4 && strcmp(&text[n_text-4], "\n *\n") == 0 ||
                 n_text>=4 && strcmp(&text[n_text-4], "\n * ") == 0 ||
                 n_text==3 && strcmp(&text[n_text-3], " *\n") == 0 ||
                 n_text==3 && strcmp(&text[n_text-3], " * ") == 0)
           text[n_text-2] = ' ';
        if (first && strncmp(&text[n_text-3], "   ", 3) == 0)
        {   first = 0;
            n_text -= 3;
        }
    }
    if (c == EOF)
    {   printf("Documentation comment not properly terminated\n");
    }
    text[n_text++] = 0;
    if (!active)
    {   printf("Ignoring section because processing is inactive\n");
        return NULL;
    }
//  printf("Found text: <<<<<<<<\n%s\n>>>>>>>>\n", text);
    return heap(text);
}

static void lisp_header(const char *msg);
static char *lisp_until_comment_end(FILE *f, int active);

static void lisp_doc_comment(FILE *f)
{
    int c;
    char *p;
    section *s;
/* Here I have the case
 *    %%! section subsection-title
 * or %%! section [alphakey] subsection-title
 */
    p = line+3;
    while (*p == ' ') p++;
    if (*p == 0)
    {   printf("Empty subsection directive\n");
        exit(1);
    }
    n_secname = n_alphakey = n_subsechdr = 0;
    secname[0] = 0;
    alphakey[0] = 0;
    subsechdr[0] = 0;
    for (;;)
    {   c = *p++;
        if (n_secname < MAX_SECNAME) secname[n_secname++] = c;
        if (*p == 0 || *p == ' ') break;
    }
    while (*p == ' ') p++;
    if (*p == '[')
    {   p++;
        while ((c = *p++) != 0 && c != ']')
        {   if (n_alphakey < MAX_ALPHAKEY) alphakey[n_alphakey++] = c;
        }
        if (c == ']') p++;
    }
    while (*p == ' ') p++;
    if (*p != 0)
    {   for (;;)
        {   c = *p++;
            if (n_subsechdr < MAX_SUBSECHDR) subsechdr[n_subsechdr++] = c;
            if (*p == 0) break;
        }
    }
    secname[n_secname] = 0;
    alphakey[n_alphakey] = 0;
    subsechdr[n_subsechdr] = 0;
/* If no alphakey is explicitly given then use the subsection heading */
    if (n_alphakey == 0) strcpy(alphakey, subsechdr);
//  printf("Section: %s\n", secname);
//  printf("AlphaKey: %s\n", alphakey);
//  printf("Sub Heading: %s\n", subsechdr);
    p = lisp_until_comment_end(f, active);
    s = find_section(secname);
    s->parts = make_subsection(heap(alphakey), heap(subsechdr),
                               heap(p), s->parts);
}

static void lisp_section_comment(FILE *f)
{
/* Here I have the case
 *    /*!! section [alphakey] title
 */
    int c;
    char *p = line+4;
    section *s;
    while (*p == ' ') p++;
    if (*p == 0)
    {   printf("Empty section directive\n");
        exit(1);
    }
    n_secname = n_alphakey = n_sechdr = 0;
    secname[0] = 0;
    alphakey[0] = 0;
    sechdr[0] = 0;
    for (;;)
    {   c = *p++;
        if (n_secname < MAX_SECNAME) secname[n_secname++] = c;
        if (*p == 0 || *p == ' ') break;
    }
    while (*p == ' ') p++;
    if (*p == '[')
    {   p++;
        while ((c = *p++) != 0 && c != ']')
        {   if (n_alphakey < MAX_ALPHAKEY) alphakey[n_alphakey++] = c;
        }
        if (c == ']') p++;
    }
    while (*p == ' ') p++;
    if (*p != 0)
    {   for (;;)
        {   c = *p++;
            if (n_sechdr < MAX_SECHDR) sechdr[n_sechdr++] = c;
            if (*p == 0) break;
        }
    }
    secname[n_secname] = 0;
    alphakey[n_alphakey] = 0;
    sechdr[n_sechdr] = 0;
/* If no alphakey is explicitly given then use the section heading */
    if (n_alphakey == 0) strcpy(alphakey, sechdr);
//  printf("Section: %s\n", secname);
//  printf("AlphaKey: %s\n", alphakey);
//  printf("Heading: %s\n", sechdr);
    p = lisp_until_comment_end(f, active);
    s = find_section(secname);
    s->alphakey = heap(alphakey);
    s->sechdr = heap(sechdr);
    s->text = heap(p);
}

static void lisp_product_comment(FILE *f)
{
    const char *p;
/* Here I have the case
 *    /*!!! product ...
 */
    active = 1;
/*
 * Now if the user had specified "-P product" on the command line I will
 * only enable processing for the rest of this file if the product specified
 * is mentioned as a word on the line.
 */
    if (product != NULL)
    {   const char *l = line+5 , *s;
        int n = strlen(product);
        while ((s = strstr(l, product)) != NULL)
        {   if ((s == header|| isspace(*(s-1))) &&
                (s[n] == 0 || isspace(s[n]))) break;
            l = s+1;
        }
        if (s == NULL) active = 0;
        else printf("Found product tag %s\n", product);
    }
    p = lisp_until_comment_end(f, active);
    if (p != NULL && strlen(p) > strlen(top_heading)) top_heading = p;
}

static char *lisp_until_comment_end(FILE *f, int active)
{
    int c;
    n_text = 0;
    text[n_text] = 0;
/*
 * In the text that I read here I will spot an end of comment as any line
 * NOT starting "%% ". Since that can not be the start of a new document
 * comment I can of course merely disard it.
 */
    for (;;)
    {   char *p;
        n_line = 0;
        while ((c = getc(f)) != EOF && c != '\n')
        {   if (c == '\r') continue;
            if (n_line < MAX_LINE)
            {   line[n_line++] = c;
                line[n_line] = 0; /* keep neatly terminated at all times */
            }
        }
        line[n_line] = 0;
        if (line[0] != '%' ||
            line[1] != '%' ||
            line[2] != ' ') break;
        p = line+3;
        while (*p != 0) text[n_text++] = *p++;
        text[n_text++] = '\n';
        text[n_text] = 0;
    }
    if (c == EOF)
    {   printf("Documentation comment not properly terminated\n");
    }
    text[n_text++] = 0;
    if (!active)
    {   printf("Ignoring section because processing is inactive\n");
        return NULL;
    }
//  printf("Found text: <<<<<<<<\n%s\n>>>>>>>>\n", text);
    return heap(text);
}

static int compare_sections(const void *a1, const void *a2)
{
    section *s1 = *(section **)a1;
    section *s2 = *(section **)a2;
    return strcmp(s1->alphakey, s2->alphakey);
}

static section *sort_sections(section *s)
{
    section *s1;
    int i = 0;
    section **v;
    for (s1=s; s1!=NULL; s1=s1->next) i++;
    v = (section **)malloc(i*sizeof(section *));
    if (v == NULL)
    {   printf("malloc failure\n");
        exit(1);
    }
    i = 0;
    for (s1=s; s1!=NULL; s1=s1->next) v[i++] = s1;
    qsort(v, i, sizeof(v[0]), compare_sections);
    s1 = NULL;
    while (i > 0)
    {   s = v[--i];
        s->next = s1;
        s1 = s;
    }
    free(v);
    return s1;
}

static int compare_subsections(const void *a1, const void *a2)
{
    subsection *s1 = *(subsection **)a1;
    subsection *s2 = *(subsection **)a2;
    return strcmp(s1->alphakey, s2->alphakey);
}

static subsection *sort_subsections(subsection *s)
{
    subsection *s1;
    int i = 0;
    subsection **v;
    for (s1=s; s1!=NULL; s1=s1->next) i++;
    v = (subsection **)malloc(i*sizeof(subsection *));
    if (v == NULL)
    {   printf("malloc failure\n");
        exit(1);
    }
    i = 0;
    for (s1=s; s1!=NULL; s1=s1->next) v[i++] = s1;
    qsort(v, i, sizeof(v[0]), compare_subsections);
    s1 = NULL;
    while (i > 0)
    {   s = v[--i];
        s->next = s1;
        s1 = s;
    }
    free(v);
    return s1;
}


static void dump_tex()
{
    FILE *f = fopen(output, "w");
    section *s;
    time_t t;
    if (f == NULL)
    {   printf("Destination file %s could not be opened\n", output);
        exit(1);
    }
    printf("Writing output to %s\n", output);
    time(&t);
    fprintf(f, "%% Generated using doxtract %s", ctime(&t));
    fprintf(f, "%s", top_heading);
/*
 * I need to sort sections by their alphakey and then subsections within
 * each section ditto.
 */
    for (s=sort_sections(list_of_sections); s!=NULL; s=s->next)
    {   subsection *ss;
        if (s->sechdr == NULL)
        {   printf("Section without a name?\n");
            s->sechdr = "Unknown";
        }
        if (s->text == NULL) s->text = "";
        fprintf(f, "%s\n%s\n", s->sechdr, s->text);
        for (ss=sort_subsections(s->parts); ss!=NULL; ss=ss->next)
        {   fprintf(f, "%s\n%s\n",
                    ss->subsechdr, ss->text);
        }
    }
    fprintf(f, "\\end{document}\n");
    fclose(f);
}

/* end of doxtract.c */
