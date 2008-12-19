
/*
 * Sort from stdin to stdout.
 *
 *    nsort
 *
 * This exists because I have found sort command on various
 * different systems are not consistent!
 */

/* Signature: 3557d199 29-Apr-2008 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define SIZE       12000000
#define MAXLINES    1000000

static int compar(const void *a, const void *b)
{
    return strcmp(*(char **)a, *(char **)b);
}

int main(int argc, char *argv[])
{
    FILE *from=stdin, *to = stdout;
    int i, nchars = 0, nlines = 0, ch;
    char *b = (char *)malloc(SIZE);
    char **lines = (char **)malloc(MAXLINES*sizeof(char *));
    if (b == NULL || lines == NULL)
    {   fprintf(stderr, "\nNot enough free space to run SORT utility\n");
        exit(1);
    }

    ch = getc(from);
    while (ch != EOF)
    {   lines[nlines++] = &b[nchars];
        if (nlines >= MAXLINES)
        {   fprintf(stderr, "\nSource file has too many lines\n");
            exit(1);
        }
        while (ch != EOF && ch != '\n')
        {   b[nchars++] = ch;
            if (nchars >= SIZE)
            {   fprintf(stderr, "\nSource file is too large\n");
                exit(1);
            }
            ch = getc(from);
        }
        b[nchars++] = 0;
        ch = getc(from);
    }
    fclose(from);

    qsort(lines, nlines, sizeof(char *), compar);

    for (i = 0; i<nlines; i++)
    {   char *p = lines[i];
        while ((ch = *p++) != 0) putc(ch, to);
        putc('\n', to);
    }
    fclose(to);
    return 0;
}

/* End of nsort.c */

