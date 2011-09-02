/* makeheaders.c                    Copyright (C) 2005-2007 Codemist Ltd */


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

/* Signature: 07b413e8 26-Jun-2007 */


/*
 * Transcribes some header files, stripping comments etc
 */

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*
 *     \    if not in comment next char not special
 *          (I might not worry about the sequence "... \/* ...")
 *     '    if not in comment go into char mode
 *     "    if not in comments go into string mode
 *     /    if not in string or char or comment check next char...
 *     / then *   go into comment mode
 *     *          in comment, check next char...
 *     * then /   end comment
 *
 */

/*
 * In some cases I may end up passing a file-name of the form
 *     /cygdrive/d/path.../leaf
 * here. For things to behave I need to map that onto
 *     d:/...path/leaf
 */

static FILE *myfopen(char *name, char *mode)
{
    char newname[256];
    if (strncmp(name, "/cygdrive/", 10) != 0)
        return fopen(name, mode);
    newname[0] = name[10];
    newname[1] = ':';
    strcpy(&newname[2], &name[11]);
    return fopen(newname, mode);
}

int main(int argc, char *argv[])
{
    int i;
    printf("char *config_header[] = {\n");
    for (i=1; i<argc; i++)
    {   FILE *f = myfopen(argv[i], "r");
        int ch, incomment = 0, instring = 0, linestart = 1;
        if (f == NULL)
        {   fprintf(stderr, "unable to read \"%s\"\n", argv[i]);
            exit(1);
        }
        for (;;)
        {   ch = getc(f);  /* first char of the next line */
            if (ch == '\n' || ch == '\r') continue;
            if (ch == EOF) break;
            while (ch != '\n' && ch != '\r' && ch != EOF)
            {   if (incomment == 0)
                {   if (ch == '/') incomment = 1;
                }
                else if (incomment == 1)
                {   if (ch == '*') incomment = 2;
                    else if (ch == '/')
                    {   putchar('/');
                        incomment = 1;
                    }
                    else
                    {   putchar('/');
                        incomment = 0;
                    }
                }
                else if (incomment == 2 && ch == '*') incomment = 3;
                else if (incomment == 3)
                {   if (ch == '/') 
                    {   incomment = 0;
                        ch = getc(f);
                        continue;
                    }
                    else if (ch == '*') incomment = 3;
                    else incomment = 2;
                }
                if (incomment == 0)
                {   if (linestart)
                    {   printf("   \"");
                        linestart = 0;
                    }
                    if (ch == '\\' || ch == '\"') putchar('\\');
                    if (ch != '\r') putchar(ch);
                }
                ch = getc(f);
            }
            if (!linestart) printf("\",\n");
            linestart = 1;
            if (ch == EOF) break;
        }
        fclose(f);
        if (i == 1)
        {   printf("    NULL\n};\n\nchar *csl_headers[] = {\n");
        }
    }
    printf("    NULL\n};\n\n/* end of machineid.d */\n\n");
    return 0;
}

/* end of makeheaders.c */

