/* fudgedata.c    A C Norman 2018 */

/* BSD licensed */

/*
 * This code is to alter main.s to put read-only data in the
 * data segment
 */


#include <stdio.h>
#include <string.h>

char line1[250];
char line2[250];

int read_line(char *b, FILE *f)
{   int c;
    while ((c = getc(f)) != EOF && c != '\n') *b++ = c;
    *b = 0;
    return c != EOF;
}

int main(int argc, char *argv[])
{   FILE *f1 = fopen(argv[1], "r");
    FILE *f2 = fopen(argv[2], "w");
    int isdata = 0;
    if (f1 == NULL || f2 == NULL)
    {   printf("Failed\n");
        return 1;
    }
    read_line(line1, f1);
    while (read_line(line2, f1))
    {   if (line2[0] == '#')
        {   if (isdata) fprintf(f2, " .text\n");
            isdata = 0;
        }
        else if (strncmp(line1, " .quad", 6) == 0 ||
                 strncmp(line1, " .byte", 6) == 0)
        {   if (!isdata) fprintf(f2, " .data\n");
            isdata = 1;
        }
        fprintf(f2, "%s\n", line1);
        strcpy(line1, line2);
    }
    fprintf(f2, "%s\n", line1);
    fclose(f1);
    fclose(f2);
    return 0;
}

/* end of fudgedata.c */
