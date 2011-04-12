/*
 * reduce-cm-widths.c
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
 * This file is basically my code as in get-computer-modern-widths.c
 * adapted so as to create a Reduce file not one in C
 *
 *                                      A C Norman.  March 2011
 */


/**************************************************************************
 * Copyright (C) 2011, Codemist Ltd.                     A C Norman       *
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




/* Signature: 4b6b2b53 12-Apr-2011 */

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

static int process(char *d, char *s, int final)
{
    char line[1024];
    int i;
    int32_t checksum, designsize, w;
    int lenhdr, bc, ec, lenwidths;
    int32_t finfo[65536], lentab[256];
    FILE *f;
    int c;
    int headershown = 0;
    double designpoints;
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
    designsize = read4(f); // design size on TeX points of 1/72.27" by 2^20
    designpoints = (double)designsize/(1024.0*1024.0);
    for (i=2; i<lenhdr; i++) read4(f);
    for (i=0; i<65536; i++) finfo[i] = 0;
    for (i=bc; i<=ec; i++) finfo[i] = read4(f);
    for (i=0; i<lenwidths; i++)
    {   lentab[i] = read4(f);
#if 0
/* Display the width table while I debug/test this */
        fprintf(out, "%% %d: %d = %o = %f\n",
            i, lentab[i], lentab[i], (double)lentab[i]/(double)(1<<20));
#endif
    }
    fclose(f);
    fprintf(out, "    %% name checksum design-size (millipoints)\n");
    fprintf(out, "    list(\"%s\", %d, %d, list!-to!-vector '(\n    ",
       d, checksum, (int)((10000LL*(int64_t)designsize+512LL*1024LL)/(1024LL*1024LL)));
// The TeX fonts only use the first 128 character positions and so I will
// not bother with recording widths for the range 128-255.
    for (c=0; c<127; c++)
    {           w = 0;
        if (c>=bc && c<=ec)
            w = lentab[(finfo[c] >> 24) & 0xff];
        w = (int)((10000.0*(double)w)/(1024.0*1024.0));
        fprintf(out, "%7d ", w);
        if ((c % 8) == 7) fprintf(out, "\n    ");
    }
    w = 0;
    if (127>=bc && 127<=ec)
        w = lentab[(finfo[127] >> 24) & 0xff];
    w = (int)((10000.0*(double)w)/(1024.0*1024.0));
    fprintf(out, "%7d))", w);
    if (!final) fprintf(out, ",");
    fprintf(out, "\n");
}

int main(int argc, char *argv[])
{
    FILE *note;
    int ch;
    out = fopen("cmfont-widths.red", "w");
    if (out == NULL)
    {   printf("Failed to open cmfont-widths.red\n");
        return 1;
    }
    fprintf(out, "%% cmfont-widths.red\n");
    fprintf(out, "%% Widths for characters in Computer Modern Fonts\n\n");
    fprintf(out, "%% extracted from %s\n\n", FONT_PATH);
    fprintf(out, "%% Widths here are given in units of 1/10000 point\n\n");
    fprintf(out, "fluid '(cm!-widths!*);\n\n");
    fprintf(out, "cm!-widths!* := list(\n");
//
// There are fonts that actually interest me... Well to be more precise
// they are the BaKoMa free truetype fonts, and at present I extract
// information for just cmr10, mmmi10, cmsy10 and cmex10. It would obviously
// be easy to add in more, but for my current purposes those may suffice.
//

//  process("cmb10",              "cmb10.tfm", 0);
//  process("cmbsy10",            "cmbsy10.tfm", 0);
//  process("cmbsy6",             "cmbsy6.tfm", 0);
//  process("cmbsy7",             "cmbsy7.tfm", 0);
//  process("cmbsy8",             "cmbsy8.tfm", 0);
//  process("cmbsy9",             "cmbsy9.tfm", 0);
//  process("cmbx10",             "cmbx10.tfm", 0);
//  process("cmbx12",             "cmbx12.tfm", 0);
//  process("cmbx5",              "cmbx5.tfm", 0);
//  process("cmbx6",              "cmbx6.tfm", 0);
//  process("cmbx7",              "cmbx7.tfm", 0);
//  process("cmbx8",              "cmbx8.tfm", 0);
//  process("cmbx9",              "cmbx9.tfm", 0);
//  process("cmbxsl10",           "cmbxsl10.tfm", 0);
//  process("cmbxti10",           "cmbxti10.tfm", 0);
//  process("cmcsc10",            "cmcsc10.tfm", 0);
//  process("cmcsc8",             "cmcsc8.tfm", 0);
//  process("cmcsc9",             "cmcsc9.tfm", 0);
//  process("cmdunh10",           "cmdunh10.tfm", 0);
    process("cmex10",             "cmex10.tfm", 0);
//  process("cmex7",              "cmex7.tfm", 0);
//  process("cmex8",              "cmex8.tfm", 0);
//  process("cmex9",              "cmex9.tfm", 0);
//  process("cmff10",             "cmff10.tfm", 0);
//  process("cmfi10",             "cmfi10.tfm", 0);
//  process("cmfib8",             "cmfib8.tfm", 0);
//  process("cminch",             "cminch.tfm", 0);
//  process("cmitt10",            "cmitt10.tfm", 0);
    process("cmmi10",             "cmmi10.tfm", 0);
//  process("cmmi12",             "cmmi12.tfm", 0);
//  process("cmmi5",              "cmmi5.tfm", 0);
//  process("cmmi6",              "cmmi6.tfm", 0);
//  process("cmmi7",              "cmmi7.tfm", 0);
//  process("cmmi8",              "cmmi8.tfm", 0);
//  process("cmmi9",              "cmmi9.tfm", 0);
//  process("cmmib10",            "cmmib10.tfm", 0);
//  process("cmmib6",             "cmmib6.tfm", 0);
//  process("cmmib7",             "cmmib7.tfm", 0);
//  process("cmmib8",             "cmmib8.tfm", 0);
//  process("cmmib9",             "cmmib9.tfm", 0);
    process("cmr10",              "cmr10.tfm", 0);
//  process("cmr12",              "cmr12.tfm", 0);
//  process("cmr17",              "cmr17.tfm", 0);
//  process("cmr5",               "cmr5.tfm", 0);
//  process("cmr6",               "cmr6.tfm", 0);
//  process("cmr7",               "cmr7.tfm", 0);
//  process("cmr8",               "cmr8.tfm", 0);
//  process("cmr9",               "cmr9.tfm", 0);
//  process("cmsl10",             "cmsl10.tfm", 0);
//  process("cmsl12",             "cmsl12.tfm", 0);
//  process("cmsl8",              "cmsl8.tfm", 0);
//  process("cmsl9",              "cmsl9.tfm", 0);
//  process("cmsltt10",           "cmsltt10.tfm", 0);
//  process("cmss10",             "cmss10.tfm", 0);
//  process("cmss12",             "cmss12.tfm", 0);
//  process("cmss17",             "cmss17.tfm", 0);
//  process("cmss8",              "cmss8.tfm", 0);
//  process("cmss9",              "cmss9.tfm", 0);
//  process("cmssbx10",           "cmssbx10.tfm", 0);
//  process("cmssdc10",           "cmssdc10.tfm", 0);
//  process("cmssi10",            "cmssi10.tfm", 0);
//  process("cmssi12",            "cmssi12.tfm", 0);
//  process("cmssi17",            "cmssi17.tfm", 0);
//  process("cmssi8",             "cmssi8.tfm", 0);
//  process("cmssi9",             "cmssi9.tfm", 0);
//  process("cmssq8",             "cmssq8.tfm", 0);
//  process("cmssqi8",            "cmssqi8.tfm", 0);
    process("cmsy10",             "cmsy10.tfm", 1);  // LAST item
//  process("cmsy5",              "cmsy5.tfm", 0);
//  process("cmsy6",              "cmsy6.tfm", 0);
//  process("cmsy7",              "cmsy7.tfm", 0);
//  process("cmsy8",              "cmsy8.tfm", 0);
//  process("cmsy9",              "cmsy9.tfm", 0);
//  process("cmtcsc10",           "cmtcsc10.tfm", 0);
//  process("cmtex10",            "cmtex10.tfm", 0);
//  process("cmtex8",             "cmtex8.tfm", 0);
//  process("cmtex9",             "cmtex9.tfm", 0);
//  process("cmti10",             "cmti10.tfm", 0);
//  process("cmti12",             "cmti12.tfm", 0);
//  process("cmti7",              "cmti7.tfm", 0);
//  process("cmti8",              "cmti8.tfm", 0);
//  process("cmti9",              "cmti9.tfm", 0);
//  process("cmtt10",             "cmtt10.tfm", 0);
//  process("cmtt12",             "cmtt12.tfm", 0);
//  process("cmtt8",              "cmtt8.tfm", 0);
//  process("cmtt9",              "cmtt9.tfm", 0);
//  process("cmu10",              "cmu10.tfm", 0);
//  process("cmvtt10",            "cmvtt10.tfm", 0);
//  process("euex10",             "euex10.tfm", 0);
//  process("euex7",              "euex7.tfm", 0);
//  process("euex8",              "euex8.tfm", 0);
//  process("euex9",              "euex9.tfm", 0);
//  process("eufb10",             "eufb10.tfm", 0);
//  process("eufb5",              "eufb5.tfm", 0);
//  process("eufb6",              "eufb6.tfm", 0);
//  process("eufb7",              "eufb7.tfm", 0);
//  process("eufb8",              "eufb8.tfm", 0);
//  process("eufb9",              "eufb9.tfm", 0);
//  process("eufm10",             "eufm10.tfm", 0);
//  process("eufm5",              "eufm5.tfm", 0);
//  process("eufm6",              "eufm6.tfm", 0);
//  process("eufm7",              "eufm7.tfm", 0);
//  process("eufm8",              "eufm8.tfm", 0);
//  process("eufm9",              "eufm9.tfm", 0);
//  process("eurb10",             "eurb10.tfm", 0);
//  process("eurb5",              "eurb5.tfm", 0);
//  process("eurb6",              "eurb6.tfm", 0);
//  process("eurb7",              "eurb7.tfm", 0);
//  process("eurb8",              "eurb8.tfm", 0);
//  process("eurb9",              "eurb9.tfm", 0);
//  process("eurm10",             "eurm10.tfm", 0);
//  process("eurm5",              "eurm5.tfm", 0);
//  process("eurm6",              "eurm6.tfm", 0);
//  process("eurm7",              "eurm7.tfm", 0);
//  process("eurm8",              "eurm8.tfm", 0);
//  process("eurm9",              "eurm9.tfm", 0);
//  process("eusb10",             "eusb10.tfm", 0);
//  process("eusb5",              "eusb5.tfm", 0);
//  process("eusb6",              "eusb6.tfm", 0);
//  process("eusb7",              "eusb7.tfm", 0);
//  process("eusb8",              "eusb8.tfm", 0);
//  process("eusb9",              "eusb9.tfm", 0);
//  process("eusm10",             "eusm10.tfm", 0);
//  process("eusm5",              "eusm5.tfm", 0);
//  process("eusm6",              "eusm6.tfm", 0);
//  process("eusm7",              "eusm7.tfm", 0);
//  process("eusm8",              "eusm8.tfm", 0);
//  process("eusm9",              "eusm9.tfm", 0);
//  process("msam10",             "msam10.tfm", 0);
//  process("msam5",              "msam5.tfm", 0);
//  process("msam6",              "msam6.tfm", 0);
//  process("msam7",              "msam7.tfm", 0);
//  process("msam8",              "msam8.tfm", 0);
//  process("msam9",              "msam9.tfm", 0);
//  process("msbm10",             "msbm10.tfm", 0);
//  process("msbm5",              "msbm5.tfm", 0);
//  process("msbm6",              "msbm6.tfm", 0);
//  process("msbm7",              "msbm7.tfm", 0);
//  process("msbm8",              "msbm8.tfm", 0);
//  process("msbm9",              "msbm9.tfm", 0);

    fprintf(out, "    );\n\n\n", 0);
    fprintf(out, "%% End of cmfont-widths.red\n");
    fclose(out);
    printf("File \"cmfont-widths.red\" created\n");
    return 0;
}

/* end of reduce-get-cm-widths.c */

