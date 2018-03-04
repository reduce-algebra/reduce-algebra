/* fudgedata.c    A C Norman 2018 */

/* BSD licensed */

/*
 * This code is to alter main.s to put read-only data in the
 * data segment.
 *
 *    Input                        Output
 *
 *    <in data mode>                .text
 *    Lab:                          <record that in text mode>
 *     .quad nn                    Lab:        [maybe several labels]
 *    # stuff                       .quad nn
 *                                 # stuff
 *
 *     <in text mode>               .data
 *    Lab:                          <record that in data mode>
 *     .quad ..                    Lab:        [maybe several labels]
 * or  .byte ..                     .quad ..   [or .byte]
 *
 *  Lab:                           Lab:        [unchanged]
 *   other material                 other material
 */

/*
 * I also intend to put in trace calls.
 * If I find "# (*entry NAME expr NARGS)"
 * then just before the next line that is NOT a .globl directive and
 * not a label setting I will insert
 *      call _acn
 *      .asciz "NAME %Q %Q"
 * where the number of instances of %Q will match the number of arguments
 * up to 3.
 * and before any "ret" I will insert
 *      call _acn
 *      .asciz "NAME = %Q"
 *
 * This should call a trace routine for every function in the file. If
 * I do not want to see all of it I will arrange that some of those calls
 * detect that the function involved is not of interest and ignore the
 * call, not printing anything.
 */

/*
 * Strategy:
 *    if in data mode...
 *       read labels
 *       read line - if not .quad then flush and restart
 *       read line - if # then output " .text",  flush and restart
 *       flush all but most recent line and restart analysis with it.
 *
 *    if in text mode
 *       read labels
 *       if next line is .quad or .byte then
 *           output ".text" and flush
 *       flush and keep going
 */


#include <stdio.h>
#include <string.h>

char fname[250];
int nargs = 0;
char line[250];
int entrydone = 0;

char lines[10][250];
int nlines = 0;

int read_line(char *b, FILE *f)
{   int c;
    char *b1 = b;
    while ((c = getc(f)) != EOF && c != '\n') *b++ = c;
    *b = 0;
    if (b1[0] == '#')
    {   if (sscanf(b1, "# (*entry %s expr %d)", fname, &nargs) == 2)
            entrydone = 0;
        else nargs = -1;
    }
    return c != EOF;
}

void write_lines(FILE *f2)
{   int i, j;
    for (i=0; i<nlines; i++)
    {   const char *l = lines[i];
        if (nargs >= 0 && i == nlines-1)
        {   if (strstr(l, " ret") != NULL)
            {   fprintf(f2, " call _acn\n");
                fprintf(f2, " .asciz \"%s = %%Q\"\n", fname);
            }
            else if (nargs >= 0 &&
                     entrydone == 0 &&
                     l[0] != '#' &&
                     strchr(l, ':') == NULL &&
                     strstr(l, ".quad") == NULL &&
                     strstr(l, ".byte") == NULL &&
                     strstr(l, ".globl") == NULL)
            {   fprintf(f2, " call _acn\n");
                fprintf(f2, " .asciz \"%s", fname);
                for (j=0; j<nargs && j<3; j++)
                    fprintf(f2, " %%Q");
                fprintf(f2, "\"\n");
                entrydone = 1;
            }
        }
        fprintf(f2, "%s\n", l);
    }
    nlines = 0;
}

int main(int argc, char *argv[])
{   FILE *f1 = fopen(argv[1], "r");
    FILE *f2 = fopen(argv[2], "w");
    if (f1 == NULL || f2 == NULL)
    {   printf("Failed\n");
        return 1;
    }
    int isdata = 0;
    int eof = 0;
top:
    if (eof) goto finished;
    eof = !read_line(line, f1);
top1:
    if (isdata)
    {   if (strchr(line, ':') != NULL)
        {   strcpy(lines[nlines++], line);
/* Just absorb labels */
            goto top;
        }
        strcpy(lines[nlines++], line);
        if (strstr(line, ".quad") == NULL)
        {
/*
 * If I am in data mode and I see something other than .quad then
 * I will just print it and start scanning again after it.
 */
            write_lines(f2);
            goto top;
        }
/*
 * Here I am in data mode and may have had some labels but I have then
 * definitly got .quad. I need to see if the next line starts with "#".
 */
        if (eof) strcpy(line, "");
        else eof = !read_line(line, f1);
        if (line[0] != '#')
        {
/*
 * If it does not I just print everything out EXCEPT that last line,
 * and go back so I consider that line again. Eg this would arise in
 *   L1:
 *    .quad first
 *    .quad second
 *   # ...
 * where the first .quad had been processed but the second one might be
 * moving me back into text mode.
 */
            write_lines(f2);
            goto top1;
        }
/*
 * Here I switch back into text mode.
 */
        strcpy(lines[nlines++], line);
        fprintf(f2, " .text\n");
        isdata = 0;
        write_lines(f2);
        goto top;
    }
    else
    {   if (strchr(line, ':') != NULL)
        {   strcpy(lines[nlines++], line);
            goto top;
        }
        strcpy(lines[nlines++], line);
/*
 * If I am in text mode and I see .byte (perhaps with some labels
 * ahead of it) I need to slip into data mode.
 */
        if (strstr(line, ".byte") != NULL)
        {   strcpy(lines[nlines++], line);
            fprintf(f2, " .data\n");
            isdata = 1;
            write_lines(f2);
            goto top;
        }
        if (strstr(line, ".quad") == NULL)
        {   write_lines(f2);
            goto top;
        }
/*
 * If I am in text mode and I see .quad I need to look ahead to see if
 * the line after it starts with "#".
 */
        if (eof) strcpy(line, "");
        else eof = !read_line(line, f1);
        if (line[0] != '#')
        {   fprintf(f2, " .data\n");
            isdata = 1;
            write_lines(f2);
            goto top1;
        }
        write_lines(f2);
        goto top1;
    }
/* There may be some pending lines right at the end of the input. */
finished:
    write_lines(f2);
    fclose(f1);
    fclose(f2);
    return 0;
}

/* end of fudgedata.c */
