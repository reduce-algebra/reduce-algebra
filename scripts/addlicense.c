#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// % Copyright   ... then blank line

// failing that
// % Author ... then blank line

#define MAXFILE 200000

char buffer[MAXFILE];
char buffer1[MAXFILE];

void printBSD(FILE *out)
{
fprintf(out, "\n");
fprintf(out, "%% Redistribution and use in source and binary forms, with or without\n");
fprintf(out, "%% modification, are permitted provided that the following conditions are met:\n");
fprintf(out, "%%\n");
fprintf(out, "%%    * Redistributions of source code must retain the relevant copyright\n");
fprintf(out, "%%      notice, this list of conditions and the following disclaimer.\n");
fprintf(out, "%%    * Redistributions in binary form must reproduce the above copyright\n");
fprintf(out, "%%      notice, this list of conditions and the following disclaimer in the\n");
fprintf(out, "%%      documentation and/or other materials provided with the distribution.\n");
fprintf(out, "%%\n");
fprintf(out, "%% THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS \"AS IS\"\n");
fprintf(out, "%% AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,\n");
fprintf(out, "%% THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR\n");
fprintf(out, "%% PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNERS OR\n");
fprintf(out, "%% CONTRIBUTORS\n");
fprintf(out, "%% BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR\n");
fprintf(out, "%% CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF\n");
fprintf(out, "%% SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS\n");
fprintf(out, "%% INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN\n");
fprintf(out, "%% CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)\n");
fprintf(out, "%% ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE\n");
fprintf(out, "%% POSSIBILITY OF SUCH DAMAGE.\n");
fprintf(out, "%%\n\n"); 
}

int findexisting(char *s)
{
    int c;
    int n = 0;
    char *line = "\n% Redistribution and use in source and binary forms, with";
    while ((c = *s) != 0)
    {   if (strncmp(s, line, strlen(line)) == 0) return n-1;
        s++;
        n++;
    }        
    return -1;
}

int findafter(char *s, char *b)
{
    int l;
    for (l=strlen(b); l>=0; l--)
    {   if (strncmp(s, b+l, strlen(s)) == 0 ||
            (l==0 && strncmp(s+1, b+l, strlen(s)-1) == 0))
        {   while (b[l+1] != 0 &&
                   (b[l] != '\n' || b[l+1] != '\n')) l++;
            return b[l+1]==0 ? -1 : l;
        }
    }
    return -1;
}

int wheretoinsert(char *buffer)
{
    int l = findafter("% Copyright", buffer);
    if (l == -1) l = findafter("% Author", buffer);
    if (l == -1) l = findafter("\nmodule ", buffer);
    return l;
}

int main(int argc, char *argv[])
{
    if (argc != 2 && argc != 3)
    {   fprintf(stderr, "need 1 or 2 args, had %d\n", argc-1);
        return 1;
    }
// Note that I allowing myself the luxury of a newer standard for C that
// permits this style of comment and allows declarations to follow
// statements.
    char *a1 = argv[1];
    char newname[250];
    FILE *in = fopen(a1, "r");
    FILE *in1 = argc == 2 ? NULL : fopen(argv[2], "r");
    int n = 0, c;
    if (in == NULL)
    {   strcpy(newname, argv[1]);
        char *s = newname + strlen(newname) - 1;
        while (*s != '/' && *s != '\\')
        {   *s = toupper(*s);
            s--;
        }
        in = fopen((a1 = newname), "r");
        if (in == NULL)
        {   fprintf(stderr, "input file %s not found\n", argv[1]);
            exit(1);
        }
    }
    while ((c = getc(in)) != EOF) if (c != '\r') buffer[n++] = c;
    buffer[n] = 0;
    fclose(in);
    int n1 = 0;
    if (in1 != NULL)
        while ((c = getc(in1)) != EOF) if (c != '\r') buffer1[n1++] = c;
    buffer1[n1] = 0;
    if (in1 != NULL) fclose(in1);
    int l = wheretoinsert(buffer);
    int l1 = findexisting(buffer1);
    if (l == -1 && l1 >=0 && memcmp(buffer, buffer1, l1) == 0) l = l1;
    char outname[256];
    sprintf(outname, "%s.fixed", argv[1]);
    FILE *out = fopen(outname, "w");
    int i;
    if (l == -1) printBSD(out);
    for (i=0; i<n; i++)
    {   putc(buffer[i], out);
        if (i == l) printBSD(out);
    }
    fclose(out);
    return 0;
}
