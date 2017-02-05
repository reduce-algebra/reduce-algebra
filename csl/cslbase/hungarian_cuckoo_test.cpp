// hungarian_cuckoo_test.cpp            Copyright (C) A C Norman, 2015-2017

// Check the cuckoo-friendly interface to the implementation of the
// Hungarian algorithm.

/**************************************************************************
 * Copyright (C) 2017, Codemist.                         A C Norman       *
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

// $Id$

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "cuckoo.h"

// So that I can just compile this one file I will include here the
// sources of the components it depends on.

#include "cuckoo.c"

#define PROBSIZE 140
uint32_t keys[PROBSIZE];

#define MAXHASHSIZE 2000
uint32_t hash[MAXHASHSIZE];

int importance(uint32_t key)
{
// I will make around 14% of the keys "important", meaning that they
// have to be accessed in at most two probes. The rest can be allowed
// three probes.
    if ((key % 7) == 3) return CUCKOO_IMPORTANT;
    else return CUCKOO_STANDARD;
}

uint32_t get_key(void *p)
{   return *(uint32_t *)p;
}

void set_key(void *p, uint32_t k)
{   *(uint32_t *)p = k;
}

int main(int argc, char *argv[])
{   int keycount = sizeof(keys)/sizeof(keys[0]);
// SLACK is used here to specify how many vacant slots can be left
// in the hash table.
#define SLACK 13
    int hashsize = keycount+SLACK;
    int i;
    CREATEMUTEX;
    CREATELOGMUTEX;
    logprintf("Test code starting\n");
// I set up some test data to be inserted into the hash table. Just to
// provide something that can be used as an illustration I will use the
// Fibonacci sequence, with values truncated to their low 32 bits..
    {   uint32_t a = 1, b = 2, c;
        for (i=0; i<keycount; i++)
        {   keys[i] = a;
            c = a + b;
            a = b;
            b = c;
        }
    }
// The next call will systematically try all hash options based on
// what I call modulus2 and offset2, and return (if possible) a hash table
// that is filled so as to minimise the number of probes to retrieve data. It
// will view IMPORTANT data as higher priority.
    cuckoo_parameters r = try_all_hash_functions(
                              keys,
                              keycount,
                              importance,
                              hash,
                              sizeof(hash[0]),
                              hashsize,
                              set_key,
                              1);
// It could be that if there is not enough SLACK that a placement is not
// possible, so in that case I will report that and quit.
    if (r.table_size == (uint32_t)(-1))
    {   printf("No solution found\n");
        exit(1);
    }
// Report the success I have had.
    printf("\nOK with size = %u modulus2 = %u offset2 = %u merit = %.3f\n",
           hashsize, r.modulus2, r.offset2, r.merit);
// Display everything every key and indicate which position it has ended up in
    for (i=0; i<keycount; i++)
    {   uint32_t key = keys[i];
        uint32_t h1 = key % hashsize;
// I access the hash table here using get_key to show how that is used
// in general, because although the tash table entried here are simple
// integers one could have structs with bitfield components or other
// messy schemes that need the abstraction of get_key to handle them
// safely.
        int p1 = get_key(sizeof(hash[0])*h1 + (char *)hash) == key;
        uint32_t h2 = key % r.modulus2 + r.offset2;
        int p2 = get_key(sizeof(hash[0])*h2 + (char *)hash) == key;
        uint32_t h3 = (h1 + h2) % hashsize;
        int p3 = get_key(sizeof(hash[0])*h3 + (char *)hash) == key;
// Each key and the three locations that the key could legally be placed.
        printf("%5u: %10u... %3u%s %3u%s %3u%s\n",
               i, key,
               h1, p1 ? "*" : " ",
               h2, p2 ? "*" : " ",
               h3, p3 ? "*" : " ");
        if (!p1 && !p2 && !p3)
        {   printf("No placement found for key %u\n", key);
            exit(1);
        }
    }
    printf("Done\n");
    return 0;
}

// end of hungarian_cuckoo_test.cpp
