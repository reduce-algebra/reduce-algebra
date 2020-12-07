#include <cstdio>


int main(int argc, char *argv[])
{   for (int i=1; i<argc; i++)
    {   FILE *f = fopen(argv[i], "r");
        if (f == nullptr)
        {   printf("File %s could not be opened\n", argv[i]);
            continue;
        }
        int line = 1, col = 0;
        for (;;)
        {   int c = getc(f);
            if (c == EOF) break;
            else if (c != '\n') col++;
            else
            {   if (col > 78)
                {   for (int j=printf("%s:%d", argv[i], line); j<32; j++)
                        putchar(' ');
                    printf("%d\n", col);
                }
                col = 0;
                line++;
            }
        }
        fclose(f);
    }
    return 0;
}

// end of longlines.cpp
