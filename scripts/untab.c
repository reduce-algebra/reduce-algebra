
/*
 * Expands tabs and (while I am at it) remove trailing white-space.
 * This leaves a tab that follows a "!" or a "\" character alone because
 * those are character-escapes in REDUCE and C,
 *
 * With one arg this fixes things in-place. With 2 args if makes a
 * tab-expanded copy.
 */

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

/* Signature: 558b4d0e 03-Aug-2008 */

int main(int argc, char *argv[])
{
    char tempfile[200], backupfile[200];
    FILE *from, *to;
    int pos = 0;
    int nblanks = 0;
    int ch = '\n', prevch;
    tempfile[0] = 0;
    switch (argc)
    {
default:
        fprintf(stderr, "\nUsage:   untab file [destination]\n");
        fprintf(stderr, "   untab file     updates file in place\n");
        exit(1);
case 3:
        to = fopen(argv[2], "w");
        if (to == NULL)
        {   fprintf(stderr, "\nFile \'%s\' can not be opened\n", argv[2]);
            exit(1);
        }
        break;
case 2:
        sprintf(tempfile, "%s.tmp", argv[1]);
        sprintf(backupfile, "%s.bak", argv[1]);
        to = fopen(tempfile, "w");
        if (to == NULL)
        {   fprintf(stderr, "\nFile \'%s\' can not be opened\n", tempfile);
            exit(1);
        }
        break;
    }

    from = fopen(argv[1], "r");
    if (from == NULL)
    {   fprintf(stderr, "\nFile \'%s\' can not be opened\n", argv[1]);
        fclose(to);
        exit(1);
    }

    while ((prevch = ch, ch = getc(from)) != EOF)
    {   if (ch == '\t' && (prevch != '!' && prevch != '\\'))
        {   do nblanks++, pos++; while ((pos & 7) != 0);
        }
        else if (ch == ' ') nblanks++;
        else
        {   if (ch == '\n') nblanks = pos = 0;
            else
            {   while (nblanks != 0)
                {   putc(' ', to);
                    nblanks--;
                }
                pos++;
            }
            putc(ch, to);
        }
    }

    fclose(from);
    fclose(to);

    if (tempfile[0] != 0)
    {   remove(backupfile);
        rename(argv[1], backupfile);
        rename(tempfile, argv[1]);
    }

    return 0;
}

/* End of untab.c */

