
// bitmaps.cpp                                  Copyright (C) 2023 Codemist

// $Id$


/**************************************************************************
 * Copyright (C) 2023, Codemist.                         A C Norman       *
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


// A little bit of test/demonstration code for bitmaps.h
// This is not exactly comprehensive and it does not automate testing
// but its output lets me do some checks by hand.

#include <cstdio>

#include "bitmaps.h"

static int N, M;

// This displays a 64-bit value in binary, using I and O rather than 1 and 0
// for the first bit. It displays least significant bit first, and splits
// its output every 10 characters.

void print64(uint64_t a)
{   for (int i=0; i<64; i++)
    {   if (i == 0) std::printf("%c", "OI"[(a>>i) & 1]);
        else std::printf("%c", '0'+ (int)((a>>i) & 1));
        N++;
        if ((N%50) == 0) std::printf("\n");
        else if ((N%10) == 0) std::printf(" ");
    }
}

int main()
{   uint64_t map[] = {
        0x0000000000000000,
        0x0000000000000000,
        0x0000000000000000,
        0x0000000000000000
    };
    setBit(map, 50);
    setBits(map, 60, 71);
    clearBits(map, 90, 21);
    setBit(map, 191);
    setBit(map, 192);
    N = 0;
    print64(map[0]);
    print64(map[1]);
    print64(map[2]);
    print64(map[3]);
    std::printf("\n");
    M = 0;
    size_t p = 0;
    printf("Find Ones forward\n");
    while ((p = nextOneBit(map, 8*sizeof(map), p)) != SIZE_MAX)
    {   std::printf("%4d", (int)p);
        M++;
        if ((M%20) == 0) std::printf("\n");
        p++;
    }
    std::printf("\n");
    M = 0;
    p = 0;
    printf("Find Zeros forward\n");
    while ((p = nextZeroBit(map, 8*sizeof(map), p)) != SIZE_MAX)
    {   std::printf("%4d", (int)p);
        M++;
        if ((M%20) == 0) std::printf("\n");
        p++;
    }
    std::printf("\n");
    M = 0;
    p = 8*sizeof(map)-1;
    printf("Find Ones backward\n");
    while ((p = previousOneBit(map, p)) != SIZE_MAX)
    {   std::printf("%4d", (int)p);
        M++;
        if ((M%20) == 0) std::printf("\n");
        p--;
    }
    std::printf("\n");
    M = 0;
    p = 8*sizeof(map)-1;
    printf("Find Zeros backward\n");
    while ((p = previousZeroBit(map, p)) != SIZE_MAX)
    {   std::printf("%4d", (int)p);
        M++;
        if ((M%20) == 0) std::printf("\n");
        p--;
    }
    std::printf("\n");
    return 0;
}

// end of bitmaps.cpp

