/*
 * gencry.c                    Copyright (C) 1998-2008, A C Norman
 *
 * This program generates C code for ACNs encryption thing...
 * For an explanation see comments further down the code.
 *
 * NOTE: This has not been subject to serious cryptoanalysis so should
 * be at best viewed as entertainment or confusion not serious security.
 */

/**************************************************************************
 * Copyright (C) 2008, Codemist Ltd.                     A C Norman       *
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



/* Signature: 3c1848bb 24-May-2008 */


#include <stdio.h>
#include <stdlib.h>

/*
 * This code is capable of generating members of a family of generators.
 * It can cope with 32 or 64-bit arithmetic and with parameterisation
 * of the size of the generator.
 */

#ifndef WORD_LENGTH
/*
 * This may be 32 or 64, depending on the characteristics of the
 * target computer
 */
#  define WORD_LENGTH            32
#endif

#ifndef UNSIGNED_TYPE
/*
 * This must be a C type that will hold an unsigned integer of size
 * as given by WORD_LENGTH. For 64-bits it may sometimes be
 * "unsigned long" but it may "unsigned long long" when using GCC on
 * 32-bit computers. Note that the quotes are needed around the type
 * description.
 */
#  define UNSIGNED_TYPE          "unsigned int"
#endif

#ifndef CRYPT_BLOCK_SIZE
/*
 * The code will generate this many bytes of data for each call. Must be
 * a multiple of the number of bytes in a word.
 */
#  define CRYPT_BLOCK_SIZE       128
#endif

#ifndef SHIFT_REGISTER_LENGTH
/*
 * length on underlying shift register, and must be large enough to cope
 * with the CRYPT_BLOCK_SIZE above. This is tested for during code creation.
 * Rounded up to the next size for a primitive polynomial.
 */
#  define SHIFT_REGISTER_LENGTH  65
#endif

#ifndef SHUFFLE_BUFFER_SIZE
/*
 * A larger shuffle-buffer causes worse cache misses, but would enhance
 * security. Rounded to a power of 2.
 */
#  define SHUFFLE_BUFFER_SIZE    4096
#endif


/*
 * This generator starts by using a 55/24 (or other) Lagged Fibonacci
 * generator, except that at each stage I sometimes use XOR, sometimes "+"
 * and sometimes "-". Each of these are much like simple XOR and specifically
 * do just that on the least significant bit (so we still have a period
 * of 2^k-1 there) but they make propagation into higher parts of the
 * word non-linear. I selected the mix of operators based on digits from
 * pi in the expectation that that leaves few systematic patterns.
 * The period of the whole register is clearly some multiple of (2^k-1).
 * It will not be 2^32 as big, but experiments with short registers
 * suggests that it will be an long enough, say over 2^16 times as long. If
 * I take k=65 then this ought to be sufficient.
 *
 * I collect a block of k words from that, and then form output words
 * by combining items from there in various shifted manners so that what
 * comes out mixes bits from high and low in the basic register with the
 * result that that knowledge of one output word does not reveal a single
 * clear value in the shift register. Again I use "^", "+" and "-" for
 * the combining and a manner mixed up using pi. The selection of which
 * of the registers words are combined is also derived from digits of pi
 * rather than being simply sequential. In particular the bottom bit of
 * an word in the shift register is only used after being XORed with a value
 * from 18 bits higher by where the perios ought to be long enough
 * and the mixing sufficient to obscure them. The high order bits (which
 * one might attack since they are used to control the shuffling) are mixed
 * with data from 13 bits lower, and also benefit (sometimes) from carries and
 * borrows in the combining.  In a sixty-four bit register a large number
 * of bits in the middle of the word get formed by combining bits of three
 * raw words. For 32-bit working it is roughly the case that the bottom
 * section of an output word comes from one pair (A,B) say while the top
 * comes from a different pair (A,C).
 *
 * Finally I shuffle in a N (= 4096 perhaps) entry buffer so that answers
 * do not get issued in (easily) predictable order.  Each cycling of the
 * generator produces k words in this manner, but I then only keep 32 of
 * these. Discarding the rest corresponds to throwing away a tolerably
 * confusing subset of the original shift-register output, as well as
 * arranging that output data is out of order.
 *
 * To start things I initially just fill the LFSR with data based upon
 * multiple copies of the key. I then cycle things. After a bit I
 * propagate information from the top half of each word to the bottom,
 * considering that without that the low order bits will not gain information
 * from enough of the key. I also force a low order bit to be "1" at
 * various stages (despite the bias!) to guarantee that my shift register
 * is not stuck in a zero cycle. I extract values form the generator to fill
 * up the shuffling buffer. Once crudely initialised I cycle the generator
 * enough times to refresh most of the values in the shuffle buffer several
 * times. This all makes key establishment pretty slow, but I view that
 * as almost desirable. It would of couse also be possible to fill both
 * shift register and buffer with values derived from the key using
 * a secure hash function.
 *
 * The arrangements here guarantee that the least significant bit of the
 * word-stream that is generated is of period 2^k-1. Each subsequent bit
 * counts as a further maximal-period shift register of length k that is
 * being driven by data injected via the carry chain from less significant
 * bits. I can not prove that there is no bias here, nor that the
 * resulting overall system has a period as long as one would hope for from
 * 32*k bits of state. One notes the analysis of the lagged-fibonacci
 * generator where Knuth reports on ways of distinguishing its output
 * from real randomness. These concerns are why I discard quite a large
 * proportion of the bits that I generate, and why I shuffle the output.
 *
 * We all know that shift-registers when used simply are weak. The
 * steps taken here to improve matters are
 * (a) using mixtures or +, - and ^ for the combining functions;
 * (b) shuffling the output, after the style of Knuth's "Algorithm B";
 * (c) discarding a proportion of the bits generated by the raw shift
 *     register;
 * (d) make each output depend on a combination of several words from
 *     the shift register, with not all words used.
 *
 * A lagged fibonacci generator would give more "1" bits than "0" in
 * various lengths of initial sub-sequence. I complement every other
 * output from the raw generator to mess this up a bit. The shuffling
 * then has to conceal whether I had odd or even items.
 *
 * Lagged fibonacci has trouble with a birthday spacings test, and shuffling
 * would not cure that, but throwing away some of my generated values will
 * help to a significant extent, as will the fact that I output words that
 * are generated as combinations of three items from the register.
 * A number of adjustments to the algorithm as shown here would be
 * obvious and easy to arrange:
 * (a) use a larger shuffle-buffer. At present I use 4096 words, but
 *     increasing it would hardly change the code and would tend to
 *     improve security but at the cost of memory requirement. Once
 *     can redefine a macro here to organise this;
 * (b) use SHA-1 or some other secure hash to initialise both the shift
 *     register and the shuffle buffer from the original key. This
 *     would probably be a good thing to do. I use the scheme itself here
 *     to make this code more self-contained;
 * (c) use a longer shift-register than the 55- or 65-entry one used here,
 *     but still only keep 32 words of output from each full cycle through
 *     it. That would slow things down in direct proportion to the
 *     length of the register, but would enhance security by making more
 *     information discarded as well as by increasing the period. The code
 *     here has a varienty of options that could be enabled;
 * (d) use 64-bit arithmetic but essentially unaltered code to get
 *     32 64-bit words out in the amount of time that this code yields
 *     32 32-bit words. The code makes provision for this;
 * (e) Base the design on a shift register with more taps, with a view
 *     that very few taps (as used here) are a source of weakness. Cost
 *     will grow proportional to the number of taps used.
 *
 * For (c) and (e) suitable tap positions so that the least significant bits
 * still have maximal cycle lengths would be needed.
 *
 * Performance (65/4096) at 32 bits is around
 *       1 millisecond to set up a new key
 *     100 Mbytes per second generation of guff
 *     (this is on a Pentium II at 400 Mhz)
 * and a crude test suggests that the scheme here fills a 128-byte buffer
 * roughly three times as fast as RC4 does (?).
 */


int taps[][2] =
{
/*
 * A pair of numbers {k, t} here represents a primitive polynomial
 *       x^k + x^t + 1
 * mod 2, which should generate sequences of length 2^k-1. I include lots
 * of very small polynomials here since they may be useful when testing this
 * scheme, but at present I default to k=65.
 */
   {2, 1},
   {3, 1},
   {4, 1},
   {5, 2},
   {6, 1},
   {7, 3},
   {9, 4},
   {10, 3},
   {11, 2},
   {15, 1},
   {17, 6},
   {18, 7},
   {20, 3},
   {21,2},
   {22, 1},
   {23, 5},
   {25, 3},
   {28, 3},
   {29, 2},
   {31, 6},
   {33, 13},
   {35, 2},
   {36, 11},
   {39, 4},
   {41, 3},
   {47, 5},
   {49, 9},
   {52, 3},
   {55, 24},
   {57, 7},
   {58, 19},
   {60, 1},
   {63, 1},
   {65, 18},
   {68, 9},
   {71, 6},
   {73, 25},
   {79, 9},
   {81, 4},
   {84, 13},
   {0, 0}
};

/*
 * I provide enought digits of pi for all the shift register configurations
 * listed above.
 */

static char *pi =
    "3141592653589793238462643383279502884197169399375105820974944592"
    "3078164062862089986280348253421170679821480865132823066470938446"
    "0955058223172535940812848111745028410270193852110555964462294895"
    "4930381964428810975665933446128475648233786783165271201909145648"
    "5669234603486104543266482133936072602491412737245870066063155881"
    "7488152092096282925409171536436789259036001133053054882046652138"
    "4146951941511609433057270365759591953092186117381932611793105118"
    "5480744623799627495673518857527248912279381830119491298336733624"
    "4065664308602139494639522473719070217986094370277053921717629317"
    "6752384674818467669405132000568127145263560827785771342757789609"
    "1736371787214684409012249534301465495853710507922796892589235420"
    "1995611212902196086403441815981362977477130996051870721134999999"
    "8372978049951059731732816096318595024459455346908302642522308253"
    "3446850352619311881710100031378387528865875332083814206171776691"
    "4730359825349042875546873115956286388235378759375195778185778053"
    "2171226806613001927876611195909216420198938095257201065485863278";

static char *pip;

/*
 * The next procedure returns "^", "+" or "-", and the selection made
 * depends on digits from pi (as tabulated above). I discard '9' digits
 * and use '0' to '8' to give a pair of three-way choices. The use of pi
 * here is not because it has special magic properties. It is more the
 * opposite: people will not suspect me of having chosen mixes of the
 * operations in any awkward way if I use a natural constant in the choice.
 */

static next_op = -1;

char *op()
{
    int w;
    if (next_op >= 0)
    {   w = next_op;
        next_op = -1;
    }
    else
    {   do
        {   if ((w = *pip++) == 0)
            {   printf("I ran out of pi digits\n");
                exit(1);
            }
            w -= '0';
        } while (w == 9);
        next_op = w % 3;
        w = w / 3;
    }
    switch (w)
    {
default: return "^";
case 1:  return "+";
case 2:  return "-";
    }
}

/*
 * return a value in the range 0 ... n-1 based on digits from pi.
 */

int pirand(int n)
{
    int c, w, t;
    for (;;)
    {   w = 0;
        t = 1;
        while (w < n)
        {   if ((c = *pip++) == 0)
            {   printf("I ran out of pi digits\n");
                exit(1);
            }
            w = 10*w + c - '0';
            t = 10*t;
        }
        c = (t/n)*n;
        if (w < c) return w % n;
/*
 * I sample again if the value pulled from pi is outside a range that is
 * an exact multiple of n.
 */
    }
}

#define BYTES_PER_WORD (WORD_LENGTH/8)

int main(int argc, char *argv[])
{
    int len, tap, shift, shuffle, i, w;
    int perm1[SHIFT_REGISTER_LENGTH+20],
        perm2[SHIFT_REGISTER_LENGTH+20],
        perm3[SHIFT_REGISTER_LENGTH+20];
/*
 * First I find a primitive polynomial that will support a shift register of
 * the desired length. I allow myself to round the length up by up to 20.
 */
    for (i=0;;i++)
    {   if (taps[i][0] == 0)
        {   printf("Shift register taps not found\n");
            exit(1);
        }
        else if (taps[i][0] >= SHIFT_REGISTER_LENGTH &&
                 taps[i][0] < SHIFT_REGISTER_LENGTH+20) break;
    }
    len = taps[i][0];
    tap = taps[i][1];
/*
 * next I ensure that the shuffle buffer will have a size that is a power of
 * 2, and I calculate the logarithm of its size.
 */
    i = SHUFFLE_BUFFER_SIZE;
    shift = 0;
    while (i > 1)
    {   shift++;
        i = i >> 1;
    }
    shuffle = 1 << shift;
/*
 * Establish three mildly chaotic permutations that will help me use values
 * from the shift register in unhelpful orderings.
 */
    for (i=0; i<len; i++)
        perm1[i] = perm2[i] = perm3[i] = i;
    pip = pi;
    for (i=0; i<len; i++)
    {   int p = pirand(len-i);
        w = perm1[i]; perm1[i] = perm1[i+p]; perm1[i+p] = w;
        p = pirand(len-i);
        w = perm2[i]; perm2[i] = perm2[i+p]; perm2[i+p] = w;
        p = pirand(len-i);
        w = perm3[i]; perm3[i] = perm3[i+p]; perm3[i+p] = w;
    }

    printf("\n/*\n");
    printf(" * word length = %d\n", WORD_LENGTH);
    printf(" * shift register length = %d\n", len);
    printf(" * tap at position %d\n", tap);
    printf(" * shuffle-buffer size = %d\n", shuffle);
    printf(" */\n\n");

    printf("#ifdef TIME_TEST\n\n");

    printf("#include <stdio.h>\n");
    printf("#include <time.h>\n\n");

    printf("#define N       10000000   /* parameters for time test */\n");
    printf("#define NSTARTS 4000\n");
    printf("#define NTINY   50000000\n");
    printf("#define KEY     \"Arthurs's sample key\"\n\n");

    printf("typedef %s unsigned%d;\n\n", UNSIGNED_TYPE, WORD_LENGTH);

    printf("#endif /* TIME_TEST */\n\n");


    printf("static unsigned%d lf[%d], mix[%d];\n\n", WORD_LENGTH, len, shuffle);

    printf("#define R(x) ((x) >> %d)\n", WORD_LENGTH-shift);
    printf("#define S(x) ((x) >> 18)\n");
    printf("#define T(x) ((x) << 13)\n\n");

    printf("static unsigned char byte_order_test[] =\n");
    printf("{1, 0, 0, 0, 0, 0, 0, 0};\n\n");

    printf("#define CRYPT_BLOCK_SIZE %d\n\n", CRYPT_BLOCK_SIZE);

    printf("void crypt_get_block(unsigned char block[CRYPT_BLOCK_SIZE])\n{\n");
    printf("    unsigned%d *b = (unsigned%d *)block;\n",
           WORD_LENGTH, WORD_LENGTH);
    printf("    int n;\n");
    for (i=0; i<len; i++)
    {   int j = (i + tap) % len;
        printf("    lf[%d] %s= lf[%d];", i, op(), j);
        if ((i % 2) == 1) printf("\n");
        else if (i < 10 && j < 10) printf("  ");
        else if (i < 10 || j < 10) printf(" ");
    }
    if ((len % 2) == 1) printf("\n");
    w = -1;
    for (i=0; i<len/4; i++)
    {   char *op1, *op2;
        printf("    n = R(lf[%d]);", 4*i);
        if (++w < CRYPT_BLOCK_SIZE/BYTES_PER_WORD)
            printf(" b[%d] = mix[n];", w);
        op1 = op(); op2 = op();
        printf(" mix[n] = %s(lf[%d] %s S(lf[%d])) %s T(lf[%d]);\n",
            (w&1) ? "~" : "", perm1[4*i], op1, perm2[4*i], op2, perm3[4*i]);
        printf("    n = R(lf[%d]);", 4*i+1);
        if (++w < CRYPT_BLOCK_SIZE/BYTES_PER_WORD)
            printf(" b[%d] = mix[n];", w);
        op1 = op(); op2 = op();
        printf(" mix[n] = %s(lf[%d] %s S(lf[%d])) %s T(lf[%d]);\n",
            (w&1) ? "~" : "", perm1[4*i+1], op1,
            perm2[4*i+1], op2, perm3[4*i+1]);
        printf("    n = R(lf[%d]);", 4*i+2);
        if (++w < CRYPT_BLOCK_SIZE/BYTES_PER_WORD)
            printf(" b[%d] = mix[n];", w);
        op1 = op(); op2 = op();
        printf(" mix[n] = %s(lf[%d] %s S(lf[%d])) %s T(lf[%d]);\n",
            (w&1) ? "~" : "", perm1[4*i+2], op1,
            perm2[4*i+2], op2, perm3[4*i+2]);
    }
    if (w < CRYPT_BLOCK_SIZE/BYTES_PER_WORD)
    {   printf("*** SHIFT_REGISTER_LENGTH (=%d) is too short ***\n",
               SHIFT_REGISTER_LENGTH);
        printf("*** given CRYPT_BLOCK_SIZE = %d ***\n", CRYPT_BLOCK_SIZE);
        exit(1);
    }

    printf("/* The test this way around favours Intel etc byte order */\n");
    printf("    if (((unsigned int *)byte_order_test)[0] != 1)\n");
    printf("    {   int i;\n");
    printf("        for (i=0; i<%d; i++)\n", CRYPT_BLOCK_SIZE/BYTES_PER_WORD);
    printf("        {   unsigned%d w = b[i];\n", WORD_LENGTH);
    printf("            unsigned%d b0, b1, b2, b3;\n", WORD_LENGTH);
    if (WORD_LENGTH == 64)
    printf("            unsigned%d b4, b5, b6, b7;\n", WORD_LENGTH);
    if (WORD_LENGTH == 32)
    {   printf("            b0 = (w >> 24) & 0xffU;\n");
        printf("            b1 = (w >> 8) & 0xff00U;\n");
        printf("            b2 = (w << 8) & 0xff0000U;\n");
        printf("            b3 = (w << 24) & 0xff000000U;\n");
        printf("            b[i] = b0 | b1 | b2 | b3;\n");
    }
    else
    {   char *suffix = "LU";
/*
 * The following line is a messy cop-out, but is mainly here as a WARNING
 * that to support 64-bit arithmetic MIGHT sometimes need non-standard
 * code.
 */
        if (strcmp(UNSIGNED_TYPE, "unsigned long long int") == 0)
            suffix = "LLU";
        printf("            b0 = (w >> 56) & 0xff%s;\n", suffix);
        printf("            b1 = (w >> 40) & 0xff00%s;\n", suffix);
        printf("            b2 = (w >> 24) & 0xff0000%s;\n", suffix);
        printf("            b3 = (w >> 8) & 0xff000000%s;\n", suffix);
        printf("            b4 = (w << 8) & 0xff00000000%s;\n", suffix);
        printf("            b5 = (w << 24) & 0xff0000000000%s;\n", suffix);
        printf("            b6 = (w << 40) & 0xff000000000000%s;\n", suffix);
        printf("            b7 = (w << 56) & 0xff00000000000000%s;\n", suffix);
        printf("            b[i] = b0 | b1 | b2 | b3 | b4 | b5 | b6 | b7;\n");
    }
    printf("        }\n");
    printf("    }\n");

    printf("    return;\n}\n\n");
    printf("void crypt_init(char *key)\n{\n");
    printf("    char *pk = key;\n");
    printf("    unsigned char junk[CRYPT_BLOCK_SIZE];\n");
    printf("    int i, j;\n");
    printf("    unsigned%d w = 0;\n", WORD_LENGTH);
    printf("    for (i=0; i<%d; i++)\n", BYTES_PER_WORD*len);
    printf("    {   int k = *pk++;\n");
    printf("        if (k == 0) pk = key;");
    printf("  /* Cycle key (inc. terminating 0) */\n");
    printf("        w = (w << 8) | (k & 0xff);\n");
    printf("        if ((i %% %d) == %d) lf[i/%d] = w;\n",
                    BYTES_PER_WORD, BYTES_PER_WORD-1, BYTES_PER_WORD);
    printf("    }\n");
    printf("    for (i=0; i<%d; i++) mix[i] = 0;\n", shuffle);
    printf("    for (i=0; i<8; i++)\n");
    printf("    {   for (j=0; j<%d; j++)\n", len);
    printf("            lf[j] = (lf[j] << 10) | (lf[j] >> %d);\n",
                        WORD_LENGTH-10);
    printf("        lf[0] |= 1;\n");
    printf("        for (j=0; j<64; j++)\n");
    printf("            crypt_get_block(junk);\n");
    printf("    }\n");
    printf("    for (i=0; i<%d;)\n", shuffle);
    printf("    {   int j;\n");
    printf("        crypt_get_block(junk);\n");
    printf("        for (j=0; j<%d; j++)\n", CRYPT_BLOCK_SIZE/BYTES_PER_WORD);
    printf("        {   unsigned%d r = junk[%d*j];\n", WORD_LENGTH, BYTES_PER_WORD);
    printf("            r = (r << 8) | junk[%d*j+1];\n", BYTES_PER_WORD);
    printf("            r = (r << 8) | junk[%d*j+2];\n", BYTES_PER_WORD);
    printf("            r = (r << 8) | junk[%d*j+3];\n", BYTES_PER_WORD);
    if (WORD_LENGTH == 64)
    {   printf("            r = (r << 8) | junk[%d*j+4];\n", BYTES_PER_WORD);
        printf("            r = (r << 8) | junk[%d*j+5];\n", BYTES_PER_WORD);
        printf("            r = (r << 8) | junk[%d*j+6];\n", BYTES_PER_WORD);
        printf("            r = (r << 8) | junk[%d*j+7];\n", BYTES_PER_WORD);
    }
    printf("            if (r == 0) continue;\n");
    printf("            mix[i++] ^= junk[j];\n");
    printf("            if (i == %d) break;\n", shuffle);
    printf("        }\n");
    printf("    }\n");
    printf("    for (i=0; i<%d; i++)\n",
                (3*BYTES_PER_WORD*shuffle)/(2*CRYPT_BLOCK_SIZE));
    printf("        crypt_get_block(junk);\n");
    printf("    return;\n");
    printf("}\n\n");
    printf("#ifdef TIME_TEST\n");
    printf("/*\n");
    printf(" * The main program here does not do anything of real interest. It\n");
    printf(" * runs both the key-setup and the main loop lots of times and reports\n");
    printf(" * how long it all takes.\n");
    printf(" *\n");
#if SHIFT_REGISTER_LENGTH==65 && SHUFFLE_BUFFER_SIZE==4096 && WORD_LENGTH==32
    printf(" * Here is some sample output from a Pentium-II 400Mhz system\n");
    printf(" *\n");
    printf(" * [02faf080] 7.60 nanoseconds to do tiny loop\n");
    printf(" * 1.25 milliseconds to startup\n");
    printf(" * rate = 104.86 megabytes per second\n");
    printf(" * 79 a7 e1 52 2e 84 09 ce d0 3d 45 b2 52 2d b6 c7\n");
    printf(" * 9b ee 57 25 68 58 b7 44 42 51 1c c7 de 69 0f 89\n");
    printf(" * 98 6c cd 45 e0 a1 d4 04 a3 be 3d 5f 93 64 c9 d9\n");
    printf(" * b9 47 28 59 d0 99 5a 35 56 fd 89 e6 48 4f a4 88\n");
    printf(" * 7e dd 31 76 2b 8e 96 fa d0 6f d7 30 9c 3c 01 97\n");
    printf(" * 8a 54 93 c0 02 1d 26 df 31 2b 7b 92 56 51 fa 47\n");
    printf(" * 92 13 39 47 45 d2 b5 33 2b f6 cc 62 ec 73 00 40\n");
    printf(" * 66 ab 37 f5 1d 21 3a a9 b8 da 35 ac 04 f1 3b 53\n");
    printf(" *\n");
#endif
    printf(" */\n");
    printf("\n");
    printf("int main(int argc, char *argv[])\n");
    printf("{\n");
    printf("    clock_t c0, c1;\n");
    printf("    unsigned char r[CRYPT_BLOCK_SIZE];\n");
    printf("    int i, j = 0;\n");
    printf("    double rate;\n");
    printf("    c0 = clock();\n");
    printf("    for (i=0; i<(NTINY+1); i++) j ^= i;\n");
    printf("    c1 = clock();\n");
    printf("    printf(\"[%%.8x] %%.2f nanoseconds to do tiny loop\\n\", j,\n");
    printf("       1.0e9*(double)(c1-c0)/((double)CLOCKS_PER_SEC*(double)(NTINY+1)));\n");
    printf("    c0 = clock();\n");
    printf("    for (i=0; i<NSTARTS; i++) crypt_init(KEY);\n");
    printf("    c1 = clock();\n");
    printf("    printf(\"%%.2f milliseconds to startup\\n\",\n");
    printf("       1000.0*(double)(c1-c0)/((double)CLOCKS_PER_SEC*(double)NSTARTS));\n");
    printf("    c0 = clock();\n");
    printf("    for (i=0; i<N; i++) crypt_get_block(r);\n");
    printf("    c1 = clock();\n");
    printf("    rate = (double)N*(double)CRYPT_BLOCK_SIZE*(double)CLOCKS_PER_SEC/\n");
    printf("           ((double)(c1-c0)*1.0e6);\n");
    printf("    printf(\"rate = %%.2f megabytes per second\\n\", rate);\n");
    printf("    for (i=0; i<128; i++)\n");
    printf("    {   printf(\"%%.2x \", r[i]);\n");
    printf("        if ((i %% 16) == 15) printf(\"\\n\");\n");
    printf("    }\n");
    printf("    return 0;\n");
    printf("}\n\n");
    printf("#endif /* TIME_TEST */\n\n");
    printf("#undef R\n");
    printf("#undef S\n");
    printf("#undef T\n\n");
    return 0;
}


/* end of gencry.c */


