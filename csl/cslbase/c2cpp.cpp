// c2cpp.cpp                            Copyright (C) A C Norman. 2015-2017

// This changes comments from C to C++ style.... with all sorts of odd
// stylistic choices motivated by the CSL source code. The task that
// this file was written for is now done, so it is at most of historical
// interest.

/**************************************************************************
 * Copyright (C) 2017, Codemist.                         A C Norman       *
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

// $Id$


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

FILE *src, *dest;

// I will be lazy and assume all lines are short.
// Note that "wc -L files | sort | tail" will show the length of the longest
// lines in files...

#define MAXLINELENGTH (2000)

char line1[MAXLINELENGTH], line2[MAXLINELENGTH];
char type1[MAXLINELENGTH], type2[MAXLINELENGTH];

int n1, n2;
int context;
int ch;

// Contexts...
#define CONTEXT_NONE       0x0   // Generic
#define CONTEXT_STRING     0x1   // After (")
#define CONTEXT_STRING_ESC 0x2   // After a (\) within a string
#define CONTEXT_CHAR       0x3   // After (')
#define CONTEXT_CHAR_ESC   0x4   // After a (\) within a character literal
#define CONTEXT_BLOCK_C    0x5   // Entering (/*) so within a block comment
#define CONTEXT_BLOCK_C1   0x6   // After (/*) so within a block comment
#define CONTEXT_LINE_C     0x7   // After (//) so within a 1-line comment
#define CONTEXT_NONE1      0x8   // Exiting block comments with (*/)
#define CONTEXT_NONE2      0x9   // After (*/) but only whitespace so far

// Types...
#define typeGENERAL '.'
#define typeSTRING  's'
#define typeCOMMENT 'c'

int opening_block_comment, closing_block_comment;
int star_count, in_block_comment;

int put_comment(int i, int ch2)
{   int j, p=0;
    for (j=0; j<opening_block_comment+2; j++)
        if (line2[j] != ' ') break;
    j = j-2;
    if (j < 0)
    {   int p;
        for (p=strlen(line2); p>=0; p--)
            line2[p-j] = line2[p];
        p = -j;
        j = 0;
    }
    line2[j] = '/';
    line2[j+1] = ch2;
    return i + p;
}

int process_simple_block_comment()
{   int i, j;
    for (i=0; i<n2; i++)
        if (line2[i] == '*' && line2[i+1] == '/') break;
    for (j=i+2; j<n2; j++)
        if (!isspace(line2[j])) break;
    if (i < n2 && j < n2)
    {
// This is the messy case
//     /* xxx
//        yyy */ zzz
// with non-whitspace for zzz. I need to insert (/*) at the start of
// the final line.
        i = put_comment(i, '*');
        in_block_comment = 0;
        context = CONTEXT_NONE;
        return i+2;
    }
    else if (i < n2)
    {
// Here there is nothing after the (*/) so I can afford to delete the
// (*/) but then reinsert a (//)
        line2[i] = line2[i+1] = ' ';
        i = put_comment(10000, '/');
        in_block_comment = 0;
        context = CONTEXT_NONE;
        return strlen(line2);
    }
    else
    {
// This is an intermediate line in a block comment. One style there puts a
// column of stars just below the initial start in the (/*) that opened the
// comment - I will remove that if it is present!
        if (line2[opening_block_comment+1] == '*')
            line2[opening_block_comment+1] = ' ';
        put_comment(10000, '/');
        return strlen(line2);
    }
}

int process_box_block_comment()
{   int i;
    for (i=0; i<n2; i++)
        if (line2[i] == '*' && line2[i+1] == '/') break;
    if (i < n2)
    {   in_block_comment = 0;
        context = CONTEXT_NONE;
        return i+2;
    }
    else return n2;
}

void dumpline(char *s, const char *t)
{   int i = strlen(s)-1;
// Discard trailing whitespace
    while (i>=0 && isspace(s[i])) s[i--] = 0;
    fprintf(dest, "%s\n", s);
// During initial tetsing I will dump the type information too...
//  fprintf(dest, "%s\n", t);
}

void readline()
{   int i, j, scanfrom=0;
    if (n1 >= 0) dumpline(line1, type1);
    n1 = n2;
    memcpy(line1, line2, sizeof(line1));
    memcpy(type1, type2, sizeof(type1));
    n2 = 0;
    line2[0] = type2[0] = 0;
    while ((ch = getc(src)) != '\n' && ch != EOF)
    {   type2[n2] = 0;
        line2[n2++] = ch;
    }
    line2[n2] = 0;
    if (in_block_comment < 0)
        scanfrom = process_simple_block_comment();
    else if (in_block_comment > 0)
        scanfrom = process_box_block_comment();
    for (i=scanfrom; line2[i]!=0; i++)
    {   int c = line2[i],
                c1 = line2[i+1];
        switch (context)
        {   case CONTEXT_NONE:
// This is the generic case at the start of a file and well away from
// strings, comments etc. If you see ("), ('), (/*) or (//) you switch
// into a different context, and if it was (/*) you record the column in
// which the (/) fell.
                if (c == '"') context = CONTEXT_STRING;
                else if (c == '\'') context = CONTEXT_CHAR;
                else if (c == '/' && c1 == '*')
                {   opening_block_comment = i;
                    closing_block_comment = -1;
                    star_count = 0;
                    context = CONTEXT_BLOCK_C;
                }
                else if (c == '/' && c1 == '/') context = CONTEXT_LINE_C;
                break;
// Following (") you are in a string until you find a second ("),
// except that (\) causes the character after it to be treated
// specially.
            case CONTEXT_STRING:
                if (c == '"') context = CONTEXT_NONE;
                else if (c == '\\') context = CONTEXT_STRING_ESC;
                break;
// Here I am in a string and I had just seen a (\), so I do not test
// the character at all, but drop back to regular string status.
            case CONTEXT_STRING_ESC:
                context = CONTEXT_STRING;
                break;
// Character literals are treated just liek string ones. This lets me
// have several characters within single quotes.
            case CONTEXT_CHAR:
                if (c == '\'') context = CONTEXT_NONE;
                else if (c == '\\') context = CONTEXT_CHAR_ESC;
                break;
            case CONTEXT_CHAR_ESC:
                context = CONTEXT_CHAR;
                break;
// When the (/) of a (/*) sequence has been processed I get here, and the
// character has to be a (*). I just pass by it and continue into the body
// of the block comment. I have to have this intermediate state so that
// in a sequence (/*/) the (*) does not get interpreted as the start of
// a (*/) to terminate the comment.
            case CONTEXT_BLOCK_C:
                context = CONTEXT_BLOCK_C1;
                if (c1 == '!') star_count = 4; // (/*!) to be treated magically.
                break;
// Here is the main place where I skip the contents of a block comment.
// Almost just for fun I will detect and warn about nested (/*) sequences.
            case CONTEXT_BLOCK_C1:
                if (c == '*' && c1 == '/')
                {   closing_block_comment = i;
                    context = CONTEXT_NONE1;
                    break;
                }
                if (c == '/' && c1 == '*')
                {   printf("\"/*\" sequence found within comment\n");
                    printf("%s\n", line2);
                }
                if (c == '*' && star_count >= 0) star_count++;
                else if (star_count < 4) star_count = -1;
                break;
// As the end of a block comment, as at the start, I need a special state
// that is passed through as the second of the two character sequence is
// passed by. So this is for the (/) of the (*/) and is so that a
// sequence (*/*) does not simultaneously end one comment and start
// another.
            case CONTEXT_NONE1:
                context = CONTEXT_NONE2;
                break;
// After a comment block (/* ... */) there could be further genuine
// material or there might be only whitespace up until the end of the
// line. In the former case I must leave the comment untouched, while in
// the latter I may change it into one starting with (//). So the state
// here is just like CONTEXT_NONE except that I remain here until I find
// something that is not whitespace.
            case CONTEXT_NONE2:
                if (c == '"') context = CONTEXT_STRING;
                else if (c == '\'') context = CONTEXT_CHAR;
                else if (c == '/' && c1 == '*')
                {   opening_block_comment = i;
                    closing_block_comment = -1;
                    star_count = 0;
                    context = CONTEXT_BLOCK_C;
                }
                else if (c == '/' && c1 == '/') context = CONTEXT_LINE_C;
                else if (c != ' ' && c != '\t') context = CONTEXT_NONE;
                break;
// Comments introduced by (//) just skip everything until they reach
// the end of the line.
            case CONTEXT_LINE_C:
                break;
        }
// The following tags each character in terms of whether it is in a
// string (or character literal) or comment. It leaves the final (") that
// terminates a string markes as "general", but the true contents of a string
// are marked. The purpose of this is that transformations made on the code
// ought not to apply within comments or strings. Well sometimes they should
// within comments, but that is a tougher issue and I will not mechanise it.
        switch (context)
        {   case CONTEXT_NONE:
                type2[i] = typeGENERAL;
                break;
            case CONTEXT_STRING:
            case CONTEXT_STRING_ESC:
            case CONTEXT_CHAR:
            case CONTEXT_CHAR_ESC:
                type2[i] = typeSTRING;
                break;
            default:
                type2[i] = typeCOMMENT;
        }
        type2[i+1] = 0;
        continue;
    }
    switch (context)
    {
// At end of line if you had been in a (//) comment you drop back to
// the base state.
        case CONTEXT_LINE_C:
            context = CONTEXT_NONE;
            break;
// If you had has (/* ... */) followed by at most whitespace then the
// comment can be reworked. However if there were a lof of stars as
// in (/****...*/) I will leave things alone.
        case CONTEXT_NONE2:
            if (star_count >= 4) break;
            line2[opening_block_comment+1] = '/'; // Turn (/*) into (//)
            line2[closing_block_comment] = 0;     // discard (*/)
            while (isspace(line2[--closing_block_comment]))
                line2[closing_block_comment] = 0; // lose trailing white space
            context = CONTEXT_NONE;
            break;
        case CONTEXT_BLOCK_C1:
// If my line ended up with (/**** ...) then I will set in_block_comment
// to 1 and as a consquence the whole comment block will be left as one
// introduced by (/*). If the line ended with (/* xxx) where xxx does not
// begin with a run of stars then I will map the comment marker to (//) and
// set in_block_comment to -1. The next lines will then need to be
// re-worked to keep them as comments!
            if (in_block_comment == 0)
            {
// I only want to set in_block_comment if it is not already set!
                if (star_count < 4)
                {   in_block_comment = -1;
                    line2[opening_block_comment+1] = '/';
                }
                else in_block_comment = 1;
            }
            break;
    }
// Here the line has been messed with a bit, but each character has been
// marked in type2 to characterise whether it is general, part of a string
// (or character literal) or part of a comment.
// So now I can perform transformations on it, with the first one that
// I wish to do being a change of Lisp_Object to LispObject.
    for (i=0; line2[i] != 0; i++)
    {   const char *target = "Lisp_Object";
        int j = i;
        while (*target != 0 &&
               type2[j] == typeGENERAL &&
               line2[j] == *target)
        {   j++;
            target++;
        }
        if (*target != 0) continue;
// Here there is an instance of my target word starting at position i.
        for (j = i+4; line2[j+1] != 0 && type2[j+1] != typeCOMMENT; j++)
        {   line2[j] = line2[j+1];
            type2[j] = type2[j+1];
        }
        if (line2[j+1] == 0) line2[j] = 0;
        else line2[j] = ' ';
    }
}

void convert()
{   n1 = n2 = -1;
    context = CONTEXT_NONE;
    opening_block_comment = -1;
    star_count = -1;
    in_block_comment = 0;
    readline();
    while (ch != EOF)
    {   readline();
    }
    if (line1[0] != 0 || line2[0] != 0) dumpline(line1, type1);
    if (line2[0] != 0) dumpline(line2, type2);
}

int main(int argc, char *argv[])
{   char *srcfile = argv[1];  // eg file.c
    char destfile[100];
    if (argc < 1)
    {   printf("c2cpp file.c [file.cpp]\n");
        return 0;
    }
    if (argc < 2) sprintf(destfile, "%spp", srcfile);
    else strcpy(destfile, argv[2]);
    printf("Convert from %s to %s\n", srcfile, destfile);
    src = fopen(srcfile, "r");
    dest = fopen(destfile, "w");
    if (src != NULL && dest != NULL) convert();
    if (src != NULL) fclose(src);
    if (dest != NULL) fclose(dest);
    return 0;
}

// end of c2cpp.cpp
