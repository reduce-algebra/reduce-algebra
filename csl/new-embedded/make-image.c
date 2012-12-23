// Create C source file thay defined a character string called
// reduce_image and an integer that gives its length.

#include <stdio.h>

int main(int argc, char *argv[])
{
    FILE *in = fopen("reduce.img", "rb");
    FILE *out = fopen("image.c", "w");
    int first = 1, c, n=0, k=0;
    fprintf(out, "// Reduce image file data\n\n");
    fprintf(out, "const unsigned char *reduce_image =");
    for (;;)
    {   c = getc(in);
        if (c == EOF) break;
        if ((n & 0xf)==0)
        {   if (!first) fprintf(out, "\"");
            first = 0;
            fprintf(out, "\n   \"");
        }
        n++;
        fprintf(out, "\\x%.2x", c & 0xff);
    }
    fprintf(out, "\";\n\n");
    fprintf(out, "#define REDUCE_IMAGE_SIZE %d\n\n", n);
    fprintf(out, "// End of image file data\n");
    fclose(in);
    fclose(out);
    return 0;
}