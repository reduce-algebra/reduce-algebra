/*
 * get-computer-modern-widths.c
 *
 * This extracts just enough font information from a bunch of *.tfm
 * files that I can do the processing of the fonts that the DVI format
 * requires.
 *
 * The font metrics used here are for the BaKoMa free fonts, which
 * include the ones I most need for the presentation of mathematics.
 * I have the fonts themselves and the explicit statement of their
 * license terms elsewhere.
 *
 * Note that this is a program that is run basically just once by me on
 * known input data. So I am NOT writing it with proper checks of
 * edge conditions, protection against malformed input etc etc - it is
 * really pretty shoddy. But if it does its job then its status as a
 * quick and dirty hack is not that important.
 *
 *
 *                                      A C Norman.  November 2010
 */


/**************************************************************************
 * Copyright (C) 2010, Codemist Ltd.                     A C Norman       *
 *                                                                        *
 * Redistribution and use in source and binary forms, with or without     *
 * modification, are permitted provided that the following conditions are *
 * met:                                                                   *
 *                                                                        *
 *     * Redistributions of source code must retain the relevant          *
 *       copyright notice, this list of conditions and the following      *
 *       disclaimer.                                                      *
 *     * Redistributions in binary form must reproduce the above          *
 *       copyright notice, this list of conditions and the following      *
 *       disclaimer in the documentation and/or other materials provided  *
 *       with the distribution.                                           *
 *                                                                        *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS    *
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT      *
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS      *
 * FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE         *
 * COPYRIGHT OWNERS OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,   *
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,   *
 * BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS  *
 * OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND *
 * ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR  *
 * TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF     *
 * THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH   *
 * DAMAGE.                                                                *
 *************************************************************************/




/* Signature: 1476b278 12-Nov-2010 */

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

/*
 * This program is really just for MY use so I will build a fixed
 * path in here and let anybody who disagrees with it change the source
 * code and re-compile.
 */
#define FONT_PATH "wxfonts/tfm"



static FILE *out = NULL;

static int32_t read4(FILE *f)
{
    int32_t r = getc(f) & 0xff;
    r = (r << 8) | (getc(f) & 0xff);
    r = (r << 8) | (getc(f) & 0xff);
    r = (r << 8) | (getc(f) & 0xff);
    return r;
}

static int process(char *d, char *s)
{
    char line[1024];
    int i;
    int32_t checksum, w;
    int lenhdr, bc, ec, lenwidths;
    int32_t finfo[65536], lentab[256];
    FILE *f;
    int c;
    int headershown = 0;
    sprintf(line, "%s/%s", FONT_PATH, s);
    f = fopen(line, "r");
    if (f == NULL)
    {   fprintf(stderr, "Failed to read \"%s\"\n", line);
        exit(1);
    }
    w = read4(f);
    lenhdr = (w & 0xffff);
    w = read4(f);
    bc = ((w >> 16) & 0xffff);
    ec = w & 0xffff;
    w = read4(f);
    lenwidths = (w >> 16) & 0xffff;
    read4(f);
    read4(f);
    read4(f);
/* Pre-header read */
    checksum = read4(f);
    for (i=1; i<lenhdr; i++) read4(f);
    for (i=0; i<65536; i++) finfo[i] = 0;
    for (i=bc; i<=ec; i++) finfo[i] = read4(f);
    for (i=0; i<lenwidths; i++)
    {   lentab[i] = read4(f);
#if 0
/* Display the width table while I debug/test this */
        fprintf(out, "/* %d: %d = %o = %f */\n",
            i, lentab[i], lentab[i], (double)lentab[i]/(double)(1<<20));
#endif
    }
    fclose(f);
    fprintf(out, "{\"%s\", %d, { /* %o */\n    ", d, checksum, checksum);
// The TeX fonts only use the first 128 character positions and so I will
// not bother with recording widths for the range 128-255.
    for (c=0; c<127; c++)
    {   w = 0;
        if (c>=bc && c<=ec)
            w = lentab[(finfo[c] >> 24) & 0xff];
        fprintf(out, "%7d,", w);
        if ((c % 8) == 7) fprintf(out, "\n    ");
    }
    w = 0;
    if (127>=bc && 127<=ec)
        w = lentab[(finfo[127] >> 24) & 0xff];
    fprintf(out, "%7d}},\n", w);
}

int main(int argc, char *argv[])
{
    FILE *note;
    int ch;
    out = fopen("cmfont-widths.c", "w");
    if (out == NULL)
    {   printf("Failed to open cmfont-widths.c\n");
        return 1;
    }
    fprintf(out, "/*\n * cmfont-widths.c\n");
    fprintf(out, " * Widths for characters in Computer Modern Fonts\n *\n");
    fprintf(out, " * extracted from %s\n *\n", FONT_PATH);
    fprintf(out, " */\n");
    fprintf(out, "\n\n/* Signature: 00000000 06-Nov-2010 */\n\n\n");
    fprintf(out, "#include <stdint.h>\n\n");
    fprintf(out, "typedef struct font_width {\n");
    fprintf(out, "   const char *name;\n");
    fprintf(out, "   int32_t checksum;\n");
    fprintf(out, "   int32_t charwidth[128];\n");
    fprintf(out, "} font_width;\n\n");
    fprintf(out, "static font_width cm_font_width[] = {\n");
//
// There are fonts that actually interest me... Well to be more precise
// they are the BaKoMa free truetype fonts, and at present I extract
// information from all of them even though some (eg cminch) may never end
// up used.
//

    process("cmb10",              "cmb10.tfm");
    process("cmbsy10",            "cmbsy10.tfm");
    process("cmbsy6",             "cmbsy6.tfm");
    process("cmbsy7",             "cmbsy7.tfm");
    process("cmbsy8",             "cmbsy8.tfm");
    process("cmbsy9",             "cmbsy9.tfm");
    process("cmbx10",             "cmbx10.tfm");
    process("cmbx12",             "cmbx12.tfm");
    process("cmbx5",              "cmbx5.tfm");
    process("cmbx6",              "cmbx6.tfm");
    process("cmbx7",              "cmbx7.tfm");
    process("cmbx8",              "cmbx8.tfm");
    process("cmbx9",              "cmbx9.tfm");
    process("cmbxsl10",           "cmbxsl10.tfm");
    process("cmbxti10",           "cmbxti10.tfm");
    process("cmcsc10",            "cmcsc10.tfm");
    process("cmcsc8",             "cmcsc8.tfm");
    process("cmcsc9",             "cmcsc9.tfm");
    process("cmdunh10",           "cmdunh10.tfm");
    process("cmex10",             "cmex10.tfm");
    process("cmex7",              "cmex7.tfm");
    process("cmex8",              "cmex8.tfm");
    process("cmex9",              "cmex9.tfm");
    process("cmff10",             "cmff10.tfm");
    process("cmfi10",             "cmfi10.tfm");
    process("cmfib8",             "cmfib8.tfm");
    process("cminch",             "cminch.tfm");
    process("cmitt10",            "cmitt10.tfm");
    process("cmmi10",             "cmmi10.tfm");
    process("cmmi12",             "cmmi12.tfm");
    process("cmmi5",              "cmmi5.tfm");
    process("cmmi6",              "cmmi6.tfm");
    process("cmmi7",              "cmmi7.tfm");
    process("cmmi8",              "cmmi8.tfm");
    process("cmmi9",              "cmmi9.tfm");
    process("cmmib10",            "cmmib10.tfm");
    process("cmmib6",             "cmmib6.tfm");
    process("cmmib7",             "cmmib7.tfm");
    process("cmmib8",             "cmmib8.tfm");
    process("cmmib9",             "cmmib9.tfm");
    process("cmr10",              "cmr10.tfm");
    process("cmr12",              "cmr12.tfm");
    process("cmr17",              "cmr17.tfm");
    process("cmr5",               "cmr5.tfm");
    process("cmr6",               "cmr6.tfm");
    process("cmr7",               "cmr7.tfm");
    process("cmr8",               "cmr8.tfm");
    process("cmr9",               "cmr9.tfm");
    process("cmsl10",             "cmsl10.tfm");
    process("cmsl12",             "cmsl12.tfm");
    process("cmsl8",              "cmsl8.tfm");
    process("cmsl9",              "cmsl9.tfm");
    process("cmsltt10",           "cmsltt10.tfm");
    process("cmss10",             "cmss10.tfm");
    process("cmss12",             "cmss12.tfm");
    process("cmss17",             "cmss17.tfm");
    process("cmss8",              "cmss8.tfm");
    process("cmss9",              "cmss9.tfm");
    process("cmssbx10",           "cmssbx10.tfm");
    process("cmssdc10",           "cmssdc10.tfm");
    process("cmssi10",            "cmssi10.tfm");
    process("cmssi12",            "cmssi12.tfm");
    process("cmssi17",            "cmssi17.tfm");
    process("cmssi8",             "cmssi8.tfm");
    process("cmssi9",             "cmssi9.tfm");
    process("cmssq8",             "cmssq8.tfm");
    process("cmssqi8",            "cmssqi8.tfm");
    process("cmsy10",             "cmsy10.tfm");
    process("cmsy5",              "cmsy5.tfm");
    process("cmsy6",              "cmsy6.tfm");
    process("cmsy7",              "cmsy7.tfm");
    process("cmsy8",              "cmsy8.tfm");
    process("cmsy9",              "cmsy9.tfm");
    process("cmtcsc10",           "cmtcsc10.tfm");
    process("cmtex10",            "cmtex10.tfm");
    process("cmtex8",             "cmtex8.tfm");
    process("cmtex9",             "cmtex9.tfm");
    process("cmti10",             "cmti10.tfm");
    process("cmti12",             "cmti12.tfm");
    process("cmti7",              "cmti7.tfm");
    process("cmti8",              "cmti8.tfm");
    process("cmti9",              "cmti9.tfm");
    process("cmtt10",             "cmtt10.tfm");
    process("cmtt12",             "cmtt12.tfm");
    process("cmtt8",              "cmtt8.tfm");
    process("cmtt9",              "cmtt9.tfm");
    process("cmu10",              "cmu10.tfm");
    process("cmvtt10",            "cmvtt10.tfm");
    process("euex10",             "euex10.tfm");
    process("euex7",              "euex7.tfm");
    process("euex8",              "euex8.tfm");
    process("euex9",              "euex9.tfm");
    process("eufb10",             "eufb10.tfm");
    process("eufb5",              "eufb5.tfm");
    process("eufb6",              "eufb6.tfm");
    process("eufb7",              "eufb7.tfm");
    process("eufb8",              "eufb8.tfm");
    process("eufb9",              "eufb9.tfm");
    process("eufm10",             "eufm10.tfm");
    process("eufm5",              "eufm5.tfm");
    process("eufm6",              "eufm6.tfm");
    process("eufm7",              "eufm7.tfm");
    process("eufm8",              "eufm8.tfm");
    process("eufm9",              "eufm9.tfm");
    process("eurb10",             "eurb10.tfm");
    process("eurb5",              "eurb5.tfm");
    process("eurb6",              "eurb6.tfm");
    process("eurb7",              "eurb7.tfm");
    process("eurb8",              "eurb8.tfm");
    process("eurb9",              "eurb9.tfm");
    process("eurm10",             "eurm10.tfm");
    process("eurm5",              "eurm5.tfm");
    process("eurm6",              "eurm6.tfm");
    process("eurm7",              "eurm7.tfm");
    process("eurm8",              "eurm8.tfm");
    process("eurm9",              "eurm9.tfm");
    process("eusb10",             "eusb10.tfm");
    process("eusb5",              "eusb5.tfm");
    process("eusb6",              "eusb6.tfm");
    process("eusb7",              "eusb7.tfm");
    process("eusb8",              "eusb8.tfm");
    process("eusb9",              "eusb9.tfm");
    process("eusm10",             "eusm10.tfm");
    process("eusm5",              "eusm5.tfm");
    process("eusm6",              "eusm6.tfm");
    process("eusm7",              "eusm7.tfm");
    process("eusm8",              "eusm8.tfm");
    process("eusm9",              "eusm9.tfm");
    process("msam10",             "msam10.tfm");
    process("msam5",              "msam5.tfm");
    process("msam6",              "msam6.tfm");
    process("msam7",              "msam7.tfm");
    process("msam8",              "msam8.tfm");
    process("msam9",              "msam9.tfm");
    process("msbm10",             "msbm10.tfm");
    process("msbm5",              "msbm5.tfm");
    process("msbm6",              "msbm6.tfm");
    process("msbm7",              "msbm7.tfm");
    process("msbm8",              "msbm8.tfm");
    process("msbm9",              "msbm9.tfm");

    fprintf(out, "    {NULL, 0, {0}}};\n\n\n");
    fprintf(out, "/* End of cmfont-widths.c */\n");
    fclose(out);
    printf("File \"cmfont-widths.c\" created\n");
    return 0;
}

/* end of get-computer-modern-widths.c */

