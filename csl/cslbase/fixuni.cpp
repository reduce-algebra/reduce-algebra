#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{   std::FILE *src = std::fopen("uninames.h", "r");
    std::FILE *dst = std::fopen("uninames.tmp", "w");
    char line[1000];
    int i, c;
    for (;;)
    {   i = 0;
        while ((c = std::getc(src)) != EOF && c != '\n')
        {   line[i++] = c;
            if (i > sizeof(line)-10)
            {   std::printf("Overlong line\n");
                std::exit(1);
            }
        }
        if (i == 0 && c == EOF) break;
        line[i] = 0;
        if (std::strncmp(line, "#define ", 8) != 0) continue;
        char *p = line + 8;
        char *q = p;
        while (*q != ' ')
        {   q++;
            if (q - line > sizeof(line)-10)
            {   std::printf("End of word not found %d %d\n", (int)(p-line), (int)(q-line));
                std::printf("%s\n", line);
                std::exit(1);
            }
        }
        *q++ = 0;
        while (*q == ' ')
        {   q++;
            if (q - line > sizeof(line)-10)
            {   std::printf("Too many blanks\n");
                std::exit(1);
            }
        }
        std::fprintf(dst, "case %8s: return \"%s\";\n", q, p+8);
    }
    std::fclose(src);
    std::fclose(dst);
    return 0;
}
