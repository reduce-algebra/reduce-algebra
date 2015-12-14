#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{   FILE *src = fopen("uninames.h", "r");
    FILE *dst = fopen("uninames.tmp", "w");
    char line[1000];
    int i, c;
    for (;;)
    {   i = 0;
        while ((c = getc(src)) != EOF && c != '\n')
        {   line[i++] = c;
            if (i > sizeof(line)-10)
            {   printf("Overlong line\n");
                exit(1);
            }
        }
        if (i == 0 && c == EOF) break;
        line[i] = 0;
        if (strncmp(line, "#define ", 8) != 0) continue;
        char *p = line + 8;
        char *q = p;
        while (*q != ' ')
        {   q++;
            if (q - line > sizeof(line)-10)
            {   printf("End of word not found %d %d\n", (int)(p-line), (int)(q-line));
                printf("%s\n", line);
                exit(1);
            }
        }
        *q++ = 0;
        while (*q == ' ')
        {   q++;
            if (q - line > sizeof(line)-10)
            {   printf("Too many blanks\n");
                exit(1);
            }
        }
        fprintf(dst, "case %8s: return \"%s\";\n", q, p+8);
    }
    fclose(src);
    fclose(dst);
    return 0;
}
