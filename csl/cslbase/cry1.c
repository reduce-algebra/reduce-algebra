/*
 * cry1.c         Copyright Codemist Ltd.    2002-2008
 *
 * This is an experimental and not properly validated cipher. The idea
 * is that of a feedback shift register. It observes that in any single bit
 * position and for so long as one ignored carries, ADD, SUBTRACT and XOR
 * all behave the same. So it runs a fibonacci-style generator but with the
 * processing written out in-line so it can use these three operations
 * in turn. The pattern of their use was derived from bits of the value
 * of pi or some such and is "random". Next it make output words by combining
 * (again using mixtures of arithmetic and logical operators) fields from
 * within the raw shift register. It discards some values or bits from the
 * main shift register. It then shuffles the resulting output words in
 * 4K word buffer so it will be harder to work out which came from where.
 * This HAS NOT been subject to serious crypto-analysis so should at most
 * be used in places where confusion is enough...
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


/*
 * shift register length = 65
 * tap at position 18
 * shuffle-buffer size = 4096
 */


/* Signature: 1d1b8f18 24-May-2008 */


#ifdef TIME_TEST

#include <stdio.h>
#include <time.h>

#define N       10000000   /* parameters for time test */
#define NSTARTS 4000
#define NTINY   50000000
#define KEY     "Arthurs's sample key"

typedef unsigned int uint32_t;

#endif /* TIME_TEST */

static uint32_t lf[65], mix[4096];

#define R(x) ((x) >> 20)
#define S(x) ((x) >> 9)
#define T(x) ((x) << 13)

static unsigned char byte_order_test[] = {1, 0, 0, 0};

#define CRYPT_BLOCK_SIZE 128

void crypt_get_block(unsigned char block[CRYPT_BLOCK_SIZE])
{
    uint32_t *b = (uint32_t *)block;
    int n;
    lf[0] -= lf[18];     lf[1] ^= lf[19];
    lf[2] -= lf[20];     lf[3] += lf[21];
    lf[4] += lf[22];     lf[5] -= lf[23];
    lf[6] ^= lf[24];     lf[7] -= lf[25];
    lf[8] += lf[26];     lf[9] ^= lf[27];
    lf[10] -= lf[28];    lf[11] -= lf[29];
    lf[12] += lf[30];    lf[13] += lf[31];
    lf[14] -= lf[32];    lf[15] ^= lf[33];
    lf[16] -= lf[34];    lf[17] += lf[35];
    lf[18] += lf[36];    lf[19] += lf[37];
    lf[20] -= lf[38];    lf[21] -= lf[39];
    lf[22] ^= lf[40];    lf[23] += lf[41];
    lf[24] -= lf[42];    lf[25] -= lf[43];
    lf[26] += lf[44];    lf[27] += lf[45];
    lf[28] -= lf[46];    lf[29] ^= lf[47];
    lf[30] -= lf[48];    lf[31] += lf[49];
    lf[32] -= lf[50];    lf[33] ^= lf[51];
    lf[34] -= lf[52];    lf[35] ^= lf[53];
    lf[36] += lf[54];    lf[37] += lf[55];
    lf[38] ^= lf[56];    lf[39] ^= lf[57];
    lf[40] += lf[58];    lf[41] -= lf[59];
    lf[42] ^= lf[60];    lf[43] += lf[61];
    lf[44] += lf[62];    lf[45] ^= lf[63];
    lf[46] ^= lf[64];    lf[47] -= lf[0];
    lf[48] ^= lf[1];     lf[49] ^= lf[2];
    lf[50] ^= lf[3];     lf[51] ^= lf[4];
    lf[52] ^= lf[5];     lf[53] ^= lf[6];
    lf[54] += lf[7];     lf[55] -= lf[8];
    lf[56] -= lf[9];     lf[57] ^= lf[10];
    lf[58] -= lf[11];    lf[59] -= lf[12];
    lf[60] ^= lf[13];    lf[61] += lf[14];
    lf[62] ^= lf[15];    lf[63] -= lf[16];
    lf[64] -= lf[17];
    n = R(lf[0]); b[0] = mix[n]; mix[n] = (lf[54] + S(lf[29])) ^ T(lf[5]);
    n = R(lf[1]); b[1] = mix[n]; mix[n] = (lf[39] + S(lf[47])) + T(lf[15]);
    n = R(lf[2]); b[2] = mix[n]; mix[n] = (lf[25] + S(lf[14])) + T(lf[38]);
    n = R(lf[4]); b[3] = mix[n]; mix[n] = (lf[48] - S(lf[40])) ^ T(lf[10]);
    n = R(lf[5]); b[4] = mix[n]; mix[n] = (lf[44] - S(lf[55])) - T(lf[49]);
    n = R(lf[6]); b[5] = mix[n]; mix[n] = (lf[9] ^ S(lf[37])) + T(lf[50]);
    n = R(lf[8]); b[6] = mix[n]; mix[n] = (lf[64] ^ S(lf[51])) + T(lf[8]);
    n = R(lf[9]); b[7] = mix[n]; mix[n] = (lf[11] - S(lf[35])) - T(lf[21]);
    n = R(lf[10]); b[8] = mix[n]; mix[n] = (lf[20] ^ S(lf[21])) ^ T(lf[3]);
    n = R(lf[12]); b[9] = mix[n]; mix[n] = (lf[6] ^ S(lf[31])) - T(lf[61]);
    n = R(lf[13]); b[10] = mix[n]; mix[n] = (lf[3] - S(lf[16])) ^ T(lf[16]);
    n = R(lf[14]); b[11] = mix[n]; mix[n] = (lf[17] - S(lf[53])) - T(lf[2]);
    n = R(lf[16]); b[12] = mix[n]; mix[n] = (lf[27] + S(lf[42])) - T(lf[33]);
    n = R(lf[17]); b[13] = mix[n]; mix[n] = (lf[28] + S(lf[63])) - T(lf[46]);
    n = R(lf[18]); b[14] = mix[n]; mix[n] = (lf[10] - S(lf[46])) + T(lf[35]);
    n = R(lf[20]); b[15] = mix[n]; mix[n] = (lf[53] - S(lf[10])) - T(lf[27]);
    n = R(lf[21]); b[16] = mix[n]; mix[n] = (lf[4] + S(lf[18])) - T(lf[7]);
    n = R(lf[22]); b[17] = mix[n]; mix[n] = (lf[43] + S(lf[64])) ^ T(lf[45]);
    n = R(lf[24]); b[18] = mix[n]; mix[n] = (lf[14] + S(lf[26])) + T(lf[44]);
    n = R(lf[25]); b[19] = mix[n]; mix[n] = (lf[23] ^ S(lf[38])) + T(lf[58]);
    n = R(lf[26]); b[20] = mix[n]; mix[n] = (lf[47] + S(lf[59])) ^ T(lf[47]);
    n = R(lf[28]); b[21] = mix[n]; mix[n] = (lf[63] - S(lf[36])) - T(lf[57]);
    n = R(lf[29]); b[22] = mix[n]; mix[n] = (lf[56] + S(lf[4])) + T(lf[19]);
    n = R(lf[30]); b[23] = mix[n]; mix[n] = (lf[42] - S(lf[52])) - T(lf[56]);
    n = R(lf[32]); b[24] = mix[n]; mix[n] = (lf[37] + S(lf[3])) - T(lf[63]);
    n = R(lf[33]); b[25] = mix[n]; mix[n] = (lf[32] + S(lf[1])) - T(lf[12]);
    n = R(lf[34]); b[26] = mix[n]; mix[n] = (lf[62] - S(lf[39])) - T(lf[31]);
    n = R(lf[36]); b[27] = mix[n]; mix[n] = (lf[2] ^ S(lf[44])) ^ T(lf[18]);
    n = R(lf[37]); b[28] = mix[n]; mix[n] = (lf[24] ^ S(lf[50])) ^ T(lf[55]);
    n = R(lf[38]); b[29] = mix[n]; mix[n] = (lf[22] + S(lf[27])) - T(lf[32]);
    n = R(lf[40]); b[30] = mix[n]; mix[n] = (lf[51] + S(lf[33])) + T(lf[0]);
    n = R(lf[41]); b[31] = mix[n]; mix[n] = (lf[52] ^ S(lf[19])) - T(lf[26]);
    n = R(lf[42]); mix[n] = (lf[5] ^ S(lf[41])) + T(lf[28]);
    n = R(lf[44]); mix[n] = (lf[30] ^ S(lf[15])) - T(lf[30]);
    n = R(lf[45]); mix[n] = (lf[45] + S(lf[24])) ^ T(lf[51]);
    n = R(lf[46]); mix[n] = (lf[13] + S(lf[49])) - T(lf[11]);
    n = R(lf[48]); mix[n] = (lf[16] + S(lf[11])) - T(lf[39]);
    n = R(lf[49]); mix[n] = (lf[57] - S(lf[43])) - T(lf[60]);
    n = R(lf[50]); mix[n] = (lf[49] + S(lf[48])) ^ T(lf[25]);
    n = R(lf[52]); mix[n] = (lf[34] - S(lf[22])) ^ T(lf[23]);
    n = R(lf[53]); mix[n] = (lf[18] + S(lf[6])) + T(lf[1]);
    n = R(lf[54]); mix[n] = (lf[29] + S(lf[61])) - T(lf[64]);
    n = R(lf[56]); mix[n] = (lf[59] ^ S(lf[45])) - T(lf[41]);
    n = R(lf[57]); mix[n] = (lf[36] - S(lf[32])) + T(lf[37]);
    n = R(lf[58]); mix[n] = (lf[40] + S(lf[60])) + T(lf[14]);
    n = R(lf[60]); mix[n] = (lf[1] + S(lf[56])) ^ T(lf[36]);
    n = R(lf[61]); mix[n] = (lf[8] ^ S(lf[5])) ^ T(lf[17]);
    n = R(lf[62]); mix[n] = (lf[31] ^ S(lf[17])) ^ T(lf[52]);
/* The test this way around favours Intel etc byte order */
    if (((uint32_t *)byte_order_test)[0] != 1)
    {   int i;
        for (i=0; i<32; i++)
        {   uint32_t w = b[i];
            uint32_t b0, b1, b2, b3;
            b0 = (w >> 24) & 0xffU;
            b1 = (w >> 8) & 0xff00U;
            b2 = (w << 8) & 0xff0000U;
            b3 = (w << 24) & 0xff000000U;
            b[i] = b0 | b1 | b2 | b3;
        }
    }
    return;
}

void crypt_init(char *key)
{
    char *pk = key;
    unsigned char junk[128];
    int i, j;
    uint32_t w = 0;
    for (i=0; i<260; i++)
    {   int k = *pk++;
        if (k == 0) pk = key;  /* Cycle key (inc. terminating 0) */
        w = (w << 8) | (k & 0xff);
        if ((i % 4) == 3) lf[i/4] = w;
    }
    for (i=0; i<4096; i++) mix[i] = 0;
    for (i=0; i<8; i++)
    {   for (j=0; j<65; j++)
            lf[j] = (lf[j] << 10) | (lf[j] >> 22);
        lf[0] |= 1;
        for (j=0; j<64; j++)
            crypt_get_block(junk);
    }
    for (i=0; i<4096;)
    {   int j;
        crypt_get_block(junk);
        for (j=0; j<32; j++)
        {   uint32_t r = junk[4*j];
            r = (r << 8) | junk[4*j+1];
            r = (r << 8) | junk[4*j+2];
            r = (r << 8) | junk[4*j+3];
            if (r == 0) continue;
            mix[i++] ^= junk[j];
            if (i == 4096) break;
        }
    }
    for (i=0; i<192; i++)
        crypt_get_block(junk);
    return;
}

#ifdef TIME_TEST
/*
 * The main program here does not do anything of real interest. It
 * runs both the key-setup and the main loop lots of times and reports
 * how long it all takes.
 *
 * Here is some sample output from a Pentium-II 400Mhz system
 *
 * 1.23 milliseconds to startup
 * rate = 106.43 megabytes per second
 * 9a cb fe 7f 5b 10 0b ce f6 49 89 b2 b7 17 f1 c7
 * 29 39 70 f0 ff 4b ec 8a 98 af 41 38 52 85 c9 88
 * 91 c7 18 46 68 3c 92 04 b2 21 ed 5e 30 6e e0 d9
 * cd ba d9 a6 86 9a 65 35 5c 65 61 e6 45 00 ac 88
 * 41 8a 5e 76 cb 2c 0c fb 62 3b 1b 31 37 cf 1f 97
 * 81 6c 53 73 3a fe 4f df b6 a4 00 45 59 ab 58 48
 * ce e7 08 81 67 17 07 f3 d3 88 34 4b 8a ec 8c 43
 * e9 4e 65 f5 f2 21 1e a9 44 6d a1 ad ac d5 f9 ac
 *
 */

int main(int argc, char *argv[])
{
    clock_t c0, c1;
    unsigned char r[CRYPT_BLOCK_SIZE];
    int i, j = 0;
    double rate;
    c0 = clock();
    for (i=0; i<(NTINY+1); i++) j ^= i;
    c1 = clock();
    printf("[%.8x] %.2f nanoseconds to do tiny loop\n", j,
       1.0e9*(double)(c1-c0)/((double)CLOCKS_PER_SEC*(double)(NTINY+1)));
    c0 = clock();
    for (i=0; i<NSTARTS; i++) crypt_init(KEY);
    c1 = clock();
    printf("%.2f milliseconds to startup\n",
       1000.0*(double)(c1-c0)/((double)CLOCKS_PER_SEC*(double)NSTARTS));
    c0 = clock();
    for (i=0; i<N; i++) crypt_get_block(r);
    c1 = clock();
    rate = (double)N*(double)CRYPT_BLOCK_SIZE*(double)CLOCKS_PER_SEC/
           ((double)(c1-c0)*1.0e6);
    printf("rate = %.2f megabytes per second\n", rate);
    for (i=0; i<128; i++)
    {   printf("%.2x ", r[i]);
        if ((i % 16) == 15) printf("\n");
    }
    return 0;
}

#endif /* TIME_TEST */

#undef R
#undef S
#undef T

