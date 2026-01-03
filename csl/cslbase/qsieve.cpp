// qsieve.cpp                  Copyright (C) 2026 Michel Leonard & Codemist

// $Id: version.h 7107 2025-05-05 20:57:42Z arthurcnorman $

// The code here is derived from
//   https://github.com/michel-leonard/C-Quadratic-Sieve
// where the README file includes the comment
// This general-purpose integer factorization software is
// released into the public domain. It is provided "as is"
// without any warranty, express or implied.

// To incorporate it within CSL I want to compile using C++ not
// C, to make it such that I can call it is a subroutine rather than
// use it as a free-standing program, and for these purposes I find it
// easier to use if I merge it all into a single file. I have preserved
// the right to view this one file as in the punlic domain but added the
// opportunity to use it under an explicit BSD license which is the one
// used for the remainder of CSL - so that there is no change of confusion
// about rights there.

// I will also be reducing line lengthe to be more in line with usage
// throughout the rest of CSL.

// To get this accepted by the g++ compiler it has been necessary to insert
// quite a large number of explicit casts in cases such as
//    char* b = malloc(...);
// where C++ will not allow a conversion from void* to char* to happen
// automatically. There were warnings in comparisons between a digit
// (an unsigned type) and the constant -1. g++ also got concerned about
// for loops with no command following them - such usage is legal but
// g++ fusses that the reader could misinterpret things as the next
// genuine statement being under control of the for loop. So I have been
// attempting to make as small changes to get g++ to quieten down as I can.
// One potentially broader issue if choked on is the name "state" where
// it was not happy with a re-use, so I have needed to do a renaming.
// Almost the most joyful thing that I needed to change was where there
// was a variable called "new" and in C++ that is a keyword, so I changed
// that to "New".
//
// For CSL as a whole this adjustment, despite its downsides, feels better
// to me than keeping the code in C rather than C++ - a step which would have
// made my build steps messier - and thie code is not structures so as to be
// built and used as an arm's length library and I have to adjust the driver
// parts of it anyway...
//                     Arthur Norman.  May 2025


/**************************************************************************
 * DUAL LICENSE...                                                        *
 *                                                                        *
 * Copyright (C) 2026                                 Michel Leonard      *
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
 *                                                                        *
 *                                                                        *
 * OR: Public Domain                                                      *
 *                                                                        *
 * This version of the factorization software (all files) is released     *
 * into the public domain. The software is provided "as it" without any   *
 * warranty, express or implied.                                          *
 *                                                                        *
 *************************************************************************/


// The goal of the software is to factor integers (from the command line or
// a file), with no dependency. well the version here is will provide a
// procedural interface rather than it forming a free-standing program!
// The manager performs trial divisions, checks whether numbers are
// perfect powers, tests their primality.
// For large numbers, the Quadratic Sieve is employed, and the output
// will be returned in a way that other parts of CSL can handle.


#include <stdint.h>
#include <stdlib.h>
#include <assert.h>
#include <stdio.h>
#include <stdarg.h>
#include <inttypes.h>
#include <assert.h>
#include <unistd.h>
#include <sys/time.h>
#include <string.h>

#include <iostream>

namespace CSL_LISP
{

// This file is released "as it" into the public domain, without any
// warranty, express or implied.
// AVL tree is a self-balancing binary search tree, AVL stands for
// Adelson-Velskii and Landis.

enum avl_direction
{   AVL_LOW_TO_HIGH, AVL_HIGH_TO_LOW,
};

struct avl_node
{   void *key;
    void *value;
    struct avl_node
        *rel[3]; // [0, 1, 2] = [left child, right child, parent]
    int height;
};

struct avl_manager
{   struct avl_node *root;
    size_t count;
    int affected;
    int search_only;

    int (*comparator)(const void *, const void *);

    struct avl_node *(*inserter)(void *, const void *);

    void *inserter_argument;
};

#define avl_left rel[0]
#define avl_right rel[1]
#define avl_parent rel[2]

// h_ prefixed functions are intended for internal usage only.
// Thanks to the rotations, the heights of your BSTs are always lesser than 1.44 * log2(number of keys).
static inline void h_avl_rotate(struct avl_node *a, const int rel_a,
                                struct avl_node *b, const int rel_b)
{   if ((b->rel[rel_b] = a->rel[rel_a]))
    {   a->rel[rel_a]->avl_parent = b;
    }
    else
    {   b->rel[rel_b] = a->rel[rel_a];
    }
    b->avl_parent = a;
    a->rel[rel_a] = b;
}

static inline void h_avl_swap(struct avl_node **root,
                              const struct avl_node *a, struct avl_node *b)
{   if (a->avl_parent)
    {   a->avl_parent->rel[a->avl_parent->avl_right == a] = b;
    }
    else
    {   *root = b;
    }
    b->avl_parent = a->avl_parent;
}

static inline int h_avl_height(const struct avl_node *node)
{   if (node->avl_right)
    {   if (node->avl_left)
        {   return 1 + node->rel[node->avl_right->height >
                                                         node->avl_left->height]->height;
        }
        else
        {   if (node->avl_right)
            {   return 1 + node->avl_right->height;
            }
            else
            {   return 1;
            }
        }
    }
    else
    {   if (node->avl_left)
        {   return 1 + node->avl_left->height;
        }
        else
        {   if (node->avl_right)
            {   return 1 + node->avl_right->height;
            }
            else
            {   return 1;
            }
        }
    }
}

static inline char h_avl_op_kind(const struct avl_node *node)
{   if (node->avl_left)
    {   if (node->avl_right)
        {   if (node->avl_left->height > node->avl_right->height)
            {   return 'L';
            }
            else
            {   return 'R';
            }
        }
        else
        {   return 'L';
        }
    }
    else
    {   return 'R';
    }
}

static inline char h_avl_has_op(const struct avl_node *node)
{   switch ((node->avl_left ? node->avl_left->height : 0) -
            (node->avl_right ? node->avl_right->height : 0))
    {   case 2 :
            return 'L';
        case -2 :
            return 'R';
    }
    return 0;
}

// Used after an insertion to execute at most 1 rotation.
static inline void h_avl_rebalance(struct avl_node **root,
                                   struct avl_node *top)
{   struct avl_node *middle, *bottom;
    char op[3];
    int i;
    // Maybe "top" is now too tall.
    while (top)
    {   i = top->height;
        top->height = h_avl_height(top);
        if (i == top->height)   // Height not change ?
        {   break; // Retracing can stop.
        }
        *op = h_avl_has_op(top);
        if (*op)
        {   middle = top->rel[*op == 'R'];
            op[1] = h_avl_op_kind(middle);
            i = op[1] == 'R';
            bottom = middle->rel[i];
            top->height = bottom->height;
            if (op[0] == op[1])
            {   h_avl_swap(root, top, middle);
                h_avl_rotate(middle, !i, top, i); // LL or RR done.
            }
            else
            {   h_avl_swap(root, top, bottom);
                h_avl_rotate(bottom, !i, middle, i);
                h_avl_rotate(bottom, i, top, !i); // LR or RL done.
                middle->height = bottom->height++; // The 3 height has changed.
            }
            // Rebalanced out, nobody above would notice.
            break;
        }
        top = top->avl_parent;
    }
}

struct avl_node *avl_at(struct avl_manager *const manager,
                        const void *key)
{   // retrieves a node from an AVL tree based on a specified key.
    struct avl_node *curr, *new_node;
    int i;
    if (manager->root)
    {   curr = manager->root;
        for (;;)
        {   const int cmp = manager->comparator(key, curr->key);
            if (cmp > 0)
            {   if (curr->avl_right)
                {   curr = curr->avl_right;
                }
                else
                {   if (manager->search_only)
                    {   return 0;
                    }
                    i = 1;
                    break;
                }
            }
            else if (cmp == 0)
            {   manager->affected = 0;
                return curr;
            }
            else
            {   if (curr->avl_left)
                {   curr = curr->avl_left;
                }
                else
                {   if (manager->search_only)
                    {   return 0;
                    }
                    i = 0;
                    break;
                }
            }
        }
    }
    else if (manager->search_only)
    {   return 0;
    }
    else
    {   curr = 0;
        i = -1;
    }
    // This may replace root.
    new_node = *(i >= 0 ? &curr->rel[i] : &manager->root) =
                   manager->inserter(manager->inserter_argument, key);
    new_node->height = 1;
    new_node->avl_parent = curr;
    h_avl_rebalance(&manager->root, curr);
    ++manager->count;
    manager->affected = 1;
    return new_node;
}

__attribute__((unused)) void avl_walk(const struct avl_manager *manager,
                            void(*fn)(const struct avl_node *, void *),
                            void *args,
                            const enum avl_direction direction)
{   struct avl_node *stack[64], *curr;
    int index = 0;
    const int opposite = !direction;
    if (manager->root)
    {   curr = manager->root;
        do
        {   while (curr)
            {   stack[index++] = curr;
                curr = curr->rel[direction];
            }
            if (index)
            {   curr = stack[--index];
                fn(curr, args);
                curr = curr->rel[opposite];
            }
        }
        while (index || curr);
    }
}

/*
 Every AVL tree can be colored such that it obeys all the properties
 of a red-black tree.
 Read more : https://www.math.toronto.edu/askold/2014-UMN-4-e-Adelson-.pdf
*/

// The tiny Big Integer Library (released "as is", into the public domain,
// without any warranty, express or implied) is provided for handling
// large integers. It includes basic and advanced mathematical functions
// to support calculations.
// This library does not use global variables but computation
// sheets, so it is stateless and thread-safe.

// memory is supposed provided by the system, allocations are passed
// to "assert".
// cint use "computation sheets" instead of global vars, it's thread-safe.

// the functions name that terminates by "i" means immediate, in place.
// the functions name that begin by "h_" means intended for internal usage.

typedef int64_t h_cint_t; // worked with short, int, long, etc.

static const h_cint_t cint_exponent = 4 * sizeof(h_cint_t) - 1;
static const h_cint_t cint_base = (h_cint_t) 1 << (4 * sizeof(h_cint_t) - 1);
static const h_cint_t cint_mask = cint_base - 1;
// Alphabet used for input and output strings in base from 2 to 62.
static const char *cint_alpha =
    "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";

typedef struct
{   h_cint_t *mem;  // Where the lowest bits of the number are stored
                    //  (little-endian format)
    h_cint_t *end;  // Where the highest bits of the number are stored
                    // (at end - 1)
                    // The only number having mem == end is zero
    h_cint_t nat;   // -1 = negative, +1 = positive, (zero is a positive)
    size_t size;    // The allocated size (greater than or equal to end - mem)
} cint;

typedef struct
{   cint temp[10];
} cint_sheet;

static cint_sheet *cint_new_sheet(const size_t bits)
{   // a computation sheet is required by function needing temporary vars.
    cint_sheet *sheet = (cint_sheet*)calloc(1, sizeof(cint_sheet));
    assert(sheet);
    const size_t x = bits / cint_exponent, num_size = x + 8 - x % 4;
    for (size_t i = 0; i < sizeof(sheet->temp) / sizeof(*sheet->temp);
         ++i)
    {   sheet->temp[i].nat = 1;
        sheet->temp[i].mem = sheet->temp[i].end =
            (h_cint_t*)calloc(num_size, sizeof(h_cint_t));
        assert(sheet->temp[i].mem);
        sheet->temp[i].size = num_size;
    }
    return sheet;
}

static void cint_clear_sheet(cint_sheet *sheet)
{   for (size_t i = 0; i < sizeof(sheet->temp) / sizeof(*sheet->temp);
         ++i)
        free(sheet->temp[i].mem);
    free(sheet);
}

__attribute__((unused)) static uint64_t cint_checksum(
    const cint *num)
{   uint64_t sum = (0xc6a4a7935bd1e995ULL * num->nat ^
                    (num->end - num->mem)) * 0xff51afd7ed558ccdULL;
    for (h_cint_t *p = num->mem; p < num->end;
         ++p) // Apply a XorShift process.
        sum ^= *p,
        sum ^= sum >> 33,
        sum *= 0xff51afd7ed558ccdULL,
        sum ^= sum >> 33,
        sum *= 0xc4ceb9fe1a85ec53ULL,
        sum ^= sum >> 33;
    return sum;
}

__attribute__((unused)) static inline long long int cint_to_int(
    cint *num)
{   long long int res = 0;
    for (h_cint_t *p = num->end - 1; p >= num->mem; --p)
        res = (res << cint_exponent) + (long long int) *p;
    return res * num->nat;
}

__attribute__((unused)) static inline void cint_negate(cint *num)
{   num->nat *= 1 - ((num->mem != num->end) << 1);
}

static size_t cint_count_bits(const cint *num)
{   size_t res = 0;
    if (num->end != num->mem)
    {   for (;
             *(num->end - 1) >> ++res;
            ) (void)nullptr;
        res += (num->end - num->mem - 1) * cint_exponent;
    }
    return res;
}

static size_t cint_count_zeros(const cint *num)
{   // examine the binary representation of the number to count trailing zeros.
    size_t res = 0, i;
    h_cint_t *ptr;
    for (ptr = num->mem; ptr < num->end &&
         !*ptr; ++ptr, res += cint_exponent);
    for (i = 0; !(*ptr >> i & 1); ++i);
    return res + i;
}

static inline int cint_compare_char(const cint *lhs, const char rhs)
{   // compare a cint with a simple number between -128 and 127
    const h_cint_t res = lhs->end <= lhs->mem + 1 ? *lhs->mem * lhs->nat
                         - (h_cint_t)rhs : lhs->nat ;
    return (0 < res) - (res < 0);
}

static inline int h_cint_compare(const cint *lhs, const cint *rhs)
{   h_cint_t res = (h_cint_t) ((lhs->end - lhs->mem) -
                               (rhs->end - rhs->mem));
    if (res == 0 && rhs->end != rhs->mem)
        for (const h_cint_t *l = lhs->end, *r = rhs->end;
             !(res = *--l - *--r) && l != lhs->mem;);
    return (0 < res) - (res < 0);
}

static inline int cint_compare(const cint *lhs, const cint *rhs)
{   // compare the sign first, then the data
    int res = (int) (lhs->nat - rhs->nat);
    if (res == 0) res = (int) lhs->nat * h_cint_compare(lhs, rhs);
    return res;
}

static void cint_init(cint *num, size_t bits, long long int val)
{   num->size = bits / cint_exponent;
    num->size += 8 - num->size % 4;
    num->end = num->mem = (h_cint_t*)calloc(num->size, sizeof(*num->mem));
    assert(num->mem);
    if ((num->nat = 1 - ((val < 0) << 1)) < 0) val = -val;
    for (; val;
         *num->end++ = (h_cint_t) (val % cint_base),
         val /= cint_base);
}

static inline void cint_erase(cint *num)
{   num->nat = 1,
    num->end = (h_cint_t*)memset(
        num->mem,
        0,
// With at least some C++ compilers if I make this argument of type size_t
// I seem to get a complaint that the value might be out of range. I will
// use unsigned int and hope that make things quiet!
        (unsigned int)((num->end - num->mem) * sizeof(h_cint_t)));
}

static void cint_reinit(cint *num, long long int val)
{   // it's like an initialization, but there is no memory allocation here
    if (cint_erase(num), val < 0)
        num->nat = -1, val = -val;
    for (; val;
         *num->end = (h_cint_t) (val % cint_base), val /= cint_base,
         ++num->end);
}

static void cint_reinit_by_string(cint *num, const char *str, const int base)
{   cint_erase(num);
    for (; *str &&
         memchr(cint_alpha, *str, base) == 0;
         num->nat *= 1 - ((*str++ == '-') << 1));
    for (h_cint_t *p;
         *str;
         *num->mem += (h_cint_t)
            ((char *)memchr(cint_alpha, *str++, base) - cint_alpha),
         num->end += *num->end != 0)
        for (p = num->end; --p >= num->mem;
             *(p + 1) += (*p *= base) >> cint_exponent, *p &= cint_mask);
    for (h_cint_t *p = num->mem; p < num->end;
         *(p + 1) += *p >> cint_exponent, *p++ &= cint_mask);
    num->end += *num->end != 0, num->mem != num->end || (num->nat = 1);
}

__attribute__((unused)) static inline void cint_init_by_string(
    cint *num, const size_t bits, const char *str, const int base)
{   cint_init(num, bits, 0), cint_reinit_by_string(num, str, base);
}

static void cint_reinit_by_double(cint *num, const double value)
{   // sometimes tested against Microsoft STL, it worked.
    cint_erase(num);
    uint64_t memory;
    memcpy(&memory, &value, sizeof(value));
    uint64_t ex = (memory << 1 >> 53) - 1023, m_1 = 1ULL << 52;
    if (ex < 1024)
    {   h_cint_t m_2 = 1 << ex % cint_exponent;
        num->nat *= (value > 0) - (value < 0);
        num->end = 1 + num->mem + ex / cint_exponent;
        h_cint_t *n = num->end;
        for (*(n - 1) |= m_2; --n >= num->mem; m_2 = cint_base)
            for (; m_2 >>= 1;)
                if (m_1 >>= 1)
                    *n |= m_2 * ((memory & m_1) != 0);
                else return;
    }
}

__attribute__((unused)) static double cint_to_double(const cint *num)
{   // sometimes tested, it worked.
    uint64_t memory = cint_count_bits(num) + 1022, m_write = 1ULL << 52,
             m_read = 1 << memory % cint_exponent;
    double res = 0;
    memory <<= 52;
    for (h_cint_t *n = num->end; --n >= num->mem;
         m_read = 1LL << cint_exponent)
        for (; m_read >>= 1;)
            if (m_write >>= 1)
                memory |= m_write * ((*n & m_read) != 0);
            else
                n = num->mem, m_read = 0;
    memcpy(&res, &memory, sizeof(memory));
    return (double) num->nat * res;
}

__attribute__((unused)) static inline void cint_init_by_double(
    cint *num, const size_t size, const double value)
{   cint_init(num, size, 0), cint_reinit_by_double(num, value);
}

static void cint_dup(cint *to, const cint *from)
{   // duplicate number (no verification about overlapping or available memory, caller must check)
    const size_t b = from->end - from->mem, a = to->end - to->mem;
    memcpy(to->mem, from->mem, b * sizeof(h_cint_t));
    to->end = to->mem + b;
    to->nat = from->nat;
    if (b < a) memset(to->end, 0, (size_t) (a - b) * sizeof(h_cint_t));
}

static void cint_rescale(cint *num, const size_t bits)
{   // rarely tested, it should allow to resize a number transparently.
    size_t new_size = 1 + bits / cint_exponent;
    new_size = new_size + 8 - new_size % 8;
    const size_t curr_length = num->end - num->mem;
    if (num->size < new_size)
    {   num->mem = (h_cint_t*)realloc(num->mem, new_size * sizeof(h_cint_t));
        assert(num->mem);
        memset(num->mem + num->size, 0,
               (size_t) (new_size - num->size) * sizeof(h_cint_t));
        num->end = num->mem + curr_length;
        num->size = new_size;
    }
    else if (curr_length >= new_size)
    {   cint_erase( num);
        // can't keep the number when reducing its size under
        // the minimal size it needs.
        num->end = num->mem =
            (h_cint_t*)realloc(num->mem,
                               (num->size = new_size) * sizeof(h_cint_t));
        assert(num->mem); // realloc can fail on trimming.
    }
}

static inline cint *h_cint_tmp(cint_sheet *sheet, const int id,
                               const cint *least)
{   // request at least the double of "least" to allow
    // performing multiplication then modulo...
    const size_t needed_size = (1 + least->end - least->mem) << 1;
    if (sheet->temp[id].size < needed_size)
        cint_rescale(&sheet->temp[id],
                     (1 + (cint_count_bits(least) >> 4)) << 5);
    return &sheet->temp[id];
}

static void h_cint_addi(cint *lhs, const cint *rhs)
{   // perform an addition (without caring of the sign)
    h_cint_t *l = lhs->mem;
    for (const h_cint_t *r = rhs->mem; r < rhs->end;)
        *l += *r++, *(l + 1) += *l >> cint_exponent, *l++ &= cint_mask;
    for (; *l & cint_base;
         *(l + 1) += *l >> cint_exponent, *l++ &= cint_mask);
    if (rhs->end - rhs->mem > lhs->end - lhs->mem)
        lhs->end = lhs->mem + (rhs->end - rhs->mem);
    lhs->end += *lhs->end != 0;
}

static void h_cint_subi(cint *lhs, const cint *rhs)
{   // perform a subtraction (without caring about the sign,
    // it performs high subtract low)
    h_cint_t a = 0, cmp, *l, *r, *e, *o;
    if (lhs->mem == lhs->end)
        cint_dup(lhs, rhs);
    else if (rhs->mem != rhs->end)
    {   cmp = h_cint_compare(lhs, rhs);
        if (cmp)
        {   if (cmp < 0) l = lhs->mem, r = rhs->mem, e = rhs->end,
                                 lhs->nat = -lhs->nat;
            else l = rhs->mem, r = lhs->mem, e = lhs->end;
            for (o = lhs->mem;
                 r < e;
                 *o = *r++ - *l++ - a,
                 a = (*o & cint_base) != 0,
                 *o++ &= cint_mask);
            for (*o &= cint_mask, o += a; --o > lhs->mem && !*o;);
            lhs->end = 1 + o;
        }
        else cint_erase(lhs);
    }
}

// regular functions, they care of the input sign
static inline void cint_addi(cint *lhs, const cint *rhs)
{   lhs->nat == rhs->nat ? h_cint_addi(lhs, rhs) : h_cint_subi(lhs, rhs);
}

static inline void cint_subi(cint *lhs, const cint *rhs)
{   lhs->nat == rhs->nat ?
        lhs->nat = -lhs->nat,
        h_cint_subi(lhs, rhs),
        lhs->mem == lhs->end || (lhs->nat = -lhs->nat),
        (void) 0 :
     h_cint_addi(lhs, rhs);
}

static void cint_left_shifti(cint *num, const size_t bits)
{   // execute a left shift immediately over the input,
    // for any amount of bits (no verification about available memory)
    if (num->end != num->mem)
    {   const size_t a = bits / cint_exponent, b = bits % cint_exponent,
                         c = cint_exponent - b;
        if (a)
        {   memmove(num->mem + a, num->mem,
                    (size_t) (num->end - num->mem + 1) * sizeof(h_cint_t));
            memset(num->mem, 0, a * sizeof(h_cint_t));
            num->end += a;
        }
        if (b) for (h_cint_t *l = num->end, *e = num->mem + a; --l >= e;
                        *(l + 1) |= *l >> c, *l = *l << b & cint_mask);
        num->end += *(num->end) != 0;
    }
}

static void cint_right_shifti(cint *num, const size_t bits)
{   const size_t a = bits / cint_exponent, b = bits % cint_exponent,
                     c = cint_exponent - b;
    if (num->mem + a < num->end)
    {   if (a)
        {   memmove(num->mem, num->mem + a,
                    (size_t) (num->end - num->mem - a) * sizeof(h_cint_t));
            memset(num->end -= a, 0, a * sizeof(h_cint_t));
        }
        if (b) for (h_cint_t *l = num->mem; l < num->end;
                        *l = (*l >> b | *(l + 1) << c) & cint_mask, ++l);
        if (num->mem < num->end)
            num->end -= *(num->end - 1) == 0,
            num->end == num->mem && (num->nat = 1);
    }
    else cint_erase(num);
}

static void cint_mul(const cint *lhs, const cint *rhs, cint *res)
{   // the multiplication (longhand method)
    h_cint_t *l, *r, *o, *p;
    cint_erase(res);
    if (lhs->mem != lhs->end && rhs->mem != rhs->end)
    {   res->nat = lhs->nat * rhs->nat,
                 res->end += (lhs->end - lhs->mem) + (rhs->end - rhs->mem) - 1;
        for (l = lhs->mem, p = res->mem; l < lhs->end; ++l)
            for (r = rhs->mem, o = p++; r < rhs->end;
                 *(o + 1) += (*o += *l * *r++) >> cint_exponent, *o++ &= cint_mask);
        res->end += *res->end != 0;
    }
}

static void cint_powi(cint_sheet *sheet, cint *n, const cint *exp)
{   // read the exponent bit by bit to perform the "fast" exponentiation in place.
    if (n->mem != n->end)
    {   size_t bits = cint_count_bits(exp);
        switch (bits)
        {   case 0 : cint_reinit(n, n->mem != n->end); break;
            case 1 : break;
            default:;
                cint *a = h_cint_tmp(sheet, 0, n);
                cint *b = h_cint_tmp(sheet, 1, n), *res = n, *tmp;
                cint_erase(a), *a->end++ = 1;
                h_cint_t mask = 1;
                for (const h_cint_t *ptr = exp->mem;;)
                {   if (*ptr & mask)
                        cint_mul(a, n, b), tmp = a, a = b, b = tmp;
                    if (--bits)
                    {   cint_mul(n, n, b), tmp = n, n = b, b = tmp;
                        mask <<= 1;
                        if (mask == cint_base) mask = 1, ++ptr;
                    }
                    else break;
                }
                if (res != a) cint_dup(res, a);
        }
    }
}

static inline void cint_pow(cint_sheet *sheet, const cint *n,
                            const cint *exp, cint *res)
{   cint_dup(res, n);
    cint_powi(sheet, res, exp);
}

__attribute__((unused)) static void cint_binary_div(const cint *lhs,
        const cint *rhs, cint *q, cint *r)
{   // the original division algorithm, it doesn't take any temporary variable.
    cint_erase(r);
    if (rhs->end == rhs->mem)
        for (q->nat = lhs->nat * rhs->nat, q->end = q->mem;
             q->end < q->mem + q->size; *q->end++ = cint_mask); // DBZ
    else
    {   h_cint_t a = h_cint_compare(lhs, rhs);
        if (a)
        {   cint_erase(q);
            if (a > 0)
            {   h_cint_t *l = lhs->end, *k, *qq = q->mem + (lhs->end - lhs->mem);
                for (; --qq, --l >= lhs->mem;)
                    for (a = cint_base; a >>= 1;)
                    {   for (k = r->end;
                             --k >= r->mem;
                             *(k + 1) |= (*k <<= 1) >> cint_exponent,
                             *k &= cint_mask) (void)nullptr;
                        *r->mem += (a & *l) != 0, r->end += *r->end != 0;
                        h_cint_compare(r, rhs) >= 0 ? h_cint_subi(r, rhs), *qq |= a : 0;
                    }
                q->end += (lhs->end - lhs->mem) - (rhs->end - rhs->mem),
                          q->end += *q->end != 0;
                q->nat = rhs->nat * lhs->nat, (r->end == r->mem) ||
                         (r->nat = lhs->nat); // lhs = q * rhs + r
            }
            else cint_dup(r, lhs);
        }
        else cint_reinit(q, rhs->nat * lhs->nat);
    }
}

static void h_cint_div_approx(const cint *lhs, const cint *rhs,
                              cint *res)
{   // the division approximation algorithm (answer isn't always exact)
    h_cint_t x, bits = h_cint_compare(lhs, rhs), *o = rhs->end, *p;
    if (bits == 0)
        cint_erase(res), *res->end++ = 1, res->nat = lhs->nat * rhs->nat;
    else if (bits < 0)
        cint_erase(res);
    else
    {   cint_dup(res, lhs);
        res->nat *= rhs->nat;
        x = *--o, --o < rhs->mem || (x = x << cint_exponent | *o);
        for (bits = 0; cint_mask < x; x >>= 1, ++bits);
        cint_right_shifti(res,
                          (rhs->end - rhs->mem - 1) * cint_exponent + (bits > 0) *
                          (bits - cint_exponent));
        p = res->end - 3 > res->mem ? res->end - 3 : res->mem;
        for (o = res->end; --o > p;
             *(o - 1) += (*o % x) << cint_exponent, *o /= x);
        *o /= x;
        res->end -= *(res->end - 1) == 0;
    }
}

static void cint_div(cint_sheet *sheet, const cint *lhs,
                     const cint *rhs, cint *q, cint *r)
{   // The combined division algorithm, it uses the approximation algorithm, "fast" with small inputs.
    // When the function terminates, it must guarantee: lhs = rhs * q + r.
    assert(rhs->mem != rhs->end);
    cint_erase(q);
    const int cmp = h_cint_compare(lhs, rhs);
    if (cmp < 0)
        cint_dup(r, lhs);
    else if (cmp)
    {   if (lhs->end < lhs->mem + 3 && rhs->end < rhs->mem + 3)
        {   // System native division.
            cint_erase(r);
            const h_cint_t a = *lhs->mem | *(lhs->mem + 1) << cint_exponent,
                           b = *rhs->mem | *(rhs->mem + 1) << cint_exponent;
            *q->mem = a / b, *r->mem = a % b;
            if (*q->mem & ~cint_mask)
            {   *++q->end = *q->mem >> cint_exponent, *q->mem &= cint_mask;
            }
            q->end += *q->end != 0;
            if (*r->mem & ~cint_mask)
            {   *++r->end = *r->mem >> cint_exponent, *r->mem &= cint_mask;
            }
            r->end += *r->end != 0;
        }
        else if (rhs->end == rhs->mem + 1)
        {   // Special cased "divide by a single word".
            cint_erase(r);
            h_cint_t *x = q->end = q->mem + (lhs->end - lhs->mem);
            for(h_cint_t * p = lhs->end - 1; p >= lhs->mem; --p)
            {   h_cint_t combined = *r->mem << cint_exponent | *p ;
                *--x = combined / *rhs->mem ;
                *r->mem = combined % *rhs->mem ;
            }
            q->end -= !*(q->end - 1);
            r->end += *r->mem != 0 ;
        }
        else
        {   // Regular division for larger numbers.
            cint *a = h_cint_tmp(sheet, 0, lhs), *b = h_cint_tmp(sheet, 1, lhs);
            cint_dup(r, lhs);
            for (; h_cint_div_approx(r, rhs, b), b->mem != b->end;)
                cint_addi(q, b), cint_mul(b, rhs, a), h_cint_subi(r, a);
            if (r->end != r->mem && r->nat != lhs->nat) // lhs = q * rhs + r
                cint_reinit(b, q->nat), h_cint_subi(q, b), h_cint_subi(r, rhs);
        }
    }
    else cint_erase(r), *q->end++ = 1;
    if (lhs->nat != rhs->nat && q->mem != q->end)
        q->nat = -1; // Sign of the quotient.
    if (r->mem != r->end)
        r->nat = lhs->nat; // Sign of the remainder.
}

static inline size_t cint_approx_bits_from_digits(const size_t digits,
        const int base)
{   // approximate the number of bits for a given number of digits
    static const unsigned char logs[] = {252, 200, 172, 154, 142, 133, 126, 120, 115, 111, 108, 105, 102, 100, 97, 95, 94, 92, 91, 89, 88, 87, 86, 85, 84, 83, 82, 81, 80, 80, 79, 78, 77, 77, 76, 76, 75, 75, 74, 74, 73, 73, 72, 72, 72, 71, 71, 70, 70, 70, 69, 69, 69, 68, 68, 68, 67, 67, 67, 67};
    return base == 2 ? digits : 1 + digits * 400 / logs[base - 3];
}

static inline size_t cint_approx_digits_from_bits(const size_t bits,
        const int base)
{   // approximate the number of digits for a given number of bits (suitable to malloc)
    static const unsigned char logs[] = {40, 63, 80, 92, 103, 112, 120, 126, 132, 138, 143, 148, 152, 156, 160, 163, 166, 169, 172, 175, 178, 180, 183, 185, 188, 190, 192, 194, 196, 198, 200, 201, 203, 205, 206, 208, 209, 211, 212, 214, 215, 217, 218, 219, 220, 222, 223, 224, 225, 226, 228, 229, 230, 231, 232, 233, 234, 235, 236, 237, 238};
    return 3 + bits * 40 / logs[base -
                                     2]; // including a byte for the sign.
}

static char *cint_to_string_buffer(const cint *num, char * buf,
                                   const int base)
{   // write the string representation of the given number into a provided buffer.
    assert(buf);
    h_cint_t a, b, *c = num->end;
    size_t d, e = 1;
    char *s = buf;
    if (num->nat < 0)
        *s++ = '-';
    *s++ = '0';
    for (*s-- = 0; --c >= num->mem;)
    {   for (a = *c, d = e; d;)
        {   b = (h_cint_t)((char *)memchr(cint_alpha, s[--d], base) -
                                          cint_alpha),
            b = b * cint_base + a;
            s[d] = cint_alpha[b % base];
            a = b / base;
        }
        for (; a; memmove(s + 1, s, ++e), *s = cint_alpha[a % base],
             a /= base);
    }
    return buf;
}

__attribute__((unused)) static inline char *cint_to_string(
    const cint *num, const int base)
{   char *mem =
        (char*)malloc(
            cint_approx_digits_from_bits(cint_count_bits(num), base));
    assert(mem); // Allocate a string to represent the number in the given base.
    return cint_to_string_buffer(num, mem, base);
}

__attribute__((unused)) static char *cint_to_string_buffer_alt(
    cint_sheet *sheet, const cint *num, char * buf, const int base)
{   // designed for verifications, the two methods that output a number (negative, zero or positive)
    // to a string are independent and must always provide the same output for bases 2 to 62.
    assert(buf);
    if (num->mem == num->end)
        *buf = '0', *(buf + 1) = 0;
    else
    {   cint *A = h_cint_tmp(sheet, 3, num), *B = h_cint_tmp(sheet, 4,
                  num), *C = h_cint_tmp(sheet, 5, num), *D = h_cint_tmp(sheet, 6, num),
                         *TMP;
        cint_dup(A, num);
        cint_reinit(B, base);
        char * end = buf ;
        while (A->mem != A->end)
        {   cint_div(sheet, A, B, C, D);
            *end++ = cint_alpha[*D->mem];
            TMP = A, A = C, C = TMP;
        }
        if (num->nat < 0)
            *end++ = '-';
        *end = 0;
        for (char t, *z = buf; z < --end; t = *z, *z++ = *end, *end = t);
    }
    return buf;
}

__attribute__((unused)) static inline char *cint_to_string_alt(
    cint_sheet *sheet, const cint *num, const int base)
{   char *mem =
        (char*)malloc(
            cint_approx_digits_from_bits(cint_count_bits(num), base));
    assert(mem); // Allocate a string to represent the number in the given base.
    return cint_to_string_buffer_alt(sheet, num, mem, base);
}

__attribute__((unused)) static inline void cint_mul_mod(
    cint_sheet *sheet, const cint *lhs, const cint *rhs, const cint *mod,
    cint *res)
{   cint *a = h_cint_tmp(sheet, 2, res), *b = h_cint_tmp(sheet, 3,
              res);
    cint_mul(lhs, rhs, a);
    cint_div(sheet, a, mod, b, res);
}

static inline void cint_mul_modi(cint_sheet *sheet, cint *lhs,
                                 const cint *rhs, const cint *mod)
{   cint *a = h_cint_tmp(sheet, 2, lhs), *b = h_cint_tmp(sheet, 3,
              lhs);
    cint_mul(lhs, rhs, a);
    cint_div(sheet, a, mod, b, lhs);
}

static inline void cint_pow_modi(cint_sheet *sheet, cint *n,
                                 const cint *exp, const cint *mod)
{   // same as "power" algorithm, difference is that it take the modulo as soon as possible.
    if (n->mem != n->end)
    {   size_t bits = cint_count_bits(exp);
        switch (bits)
        {   case 0 :
                cint_reinit(n, n->mem != n->end);
                break;
            case 1 :
                break;
            default:;
                cint *a = h_cint_tmp(sheet, 2, n);
                cint *b = h_cint_tmp(sheet, 3, n);
                cint *c = h_cint_tmp(sheet, 4, n);
                cint_erase(a), *a->end++ = 1;
                h_cint_t mask = 1;
                for (const h_cint_t *ptr = exp->mem;;)
                {   if (*ptr & mask)
                        cint_mul(a, n, b), cint_div(sheet, b, mod, c, a);
                    if (--bits)
                    {   cint_mul(n, n, b), cint_div(sheet, b, mod, c, n);
                        mask <<= 1;
                        if (mask == cint_base) mask = 1, ++ptr;
                    }
                    else break;
                }
                cint_dup(n, a);
        }
    }
}

__attribute__((unused)) static void cint_pow_mod(cint_sheet *sheet,
        const cint *n, const cint *exp, const cint *mod, cint *res)
{   cint_dup(res, n);
    cint_pow_modi(sheet, res, exp, mod);
}

static void cint_gcd(cint_sheet *sheet, const cint *lhs,
                     const cint *rhs, cint *gcd)
{   // the basic GCD algorithm, by frontal divisions.
    if (rhs->mem == rhs->end)
        cint_dup(gcd, lhs), gcd->nat = 1;
    else
    {   cint *A = h_cint_tmp(sheet, 2, lhs),
                  *B = h_cint_tmp(sheet, 3, lhs),
                   *C = h_cint_tmp(sheet, 4, lhs),
                    *TMP, *RES = gcd;
        cint_dup(gcd, lhs);
        cint_dup(A, rhs);
        gcd->nat = A->nat = 1;
        for (; A->mem != A->end;)
        {   cint_div(sheet, gcd, A, B, C);
            TMP = gcd, gcd = A, A = C, C = TMP;
        }
        gcd->nat = 1;
        if (RES != gcd) cint_dup(RES, gcd);
    }

}

__attribute__((unused)) static void cint_binary_gcd(cint_sheet *sheet,
        const cint *lhs, const cint *rhs, cint *gcd)
{   // a binary GCD algorithm.
    if (lhs->mem == lhs->end) cint_dup(gcd, rhs);
    else if (rhs->mem == rhs->end) cint_dup(gcd, lhs);
    else
    {   cint *tmp = h_cint_tmp(sheet, 0, lhs),
                  *swap, *res = gcd;
        cint_dup(gcd, lhs), gcd->nat = 1;
        cint_dup(tmp, rhs), tmp->nat = 1;
        const size_t a = cint_count_zeros(lhs), b = cint_count_zeros(rhs);
        for (size_t c = a > b ? b : a;;
             cint_right_shifti(tmp, cint_count_zeros(tmp)))
        {   if (h_cint_compare(gcd, tmp) > 0)
                swap = gcd, gcd = tmp, tmp = swap;
            h_cint_subi(tmp, gcd);
            if (tmp->mem == tmp->end)
            {   if (res != gcd)
                    cint_dup(res, gcd);
                cint_left_shifti(res, c);
                break;
            }
        }
    }
}

static unsigned cint_remove(cint_sheet *sheet, cint *N,
                            const cint *F)
{   // remove all occurrences of the factor from the input, and return the count.
    size_t res = 0;
    if (N->end != N->mem && F->end != F->mem)
        switch ((*N->mem == 1 && N->end == N->mem + 1) | (*F->mem == 1 &&
                F->end == F->mem + 1) << 1)
        {   case 1 :
                break; // it asks remove other than [-1, 1] but N is [-1, 1].
            case 2 : // it asks remove [-1, 1], so remove one occurrence if N != 0.
            case 3 :
                res = N->mem != N->end;
                if (res) N->nat *= F->nat;
                break;
            default:;
                cint *A = h_cint_tmp(sheet, 2, N), *B = h_cint_tmp(sheet, 3, N);
                // divides N by the factor until there is a remainder
                for (cint *tmp; cint_div(sheet, N, F, A, B), B->mem == B->end;
                     tmp = N, N = A, A = tmp, ++res);
                if (res & 1) cint_dup(A, N);
        }
    return res;
}

static void cint_sqrt(cint_sheet *sheet, const cint *num, cint *res,
                      cint *rem)
{   // original square root algorithm.
    cint_erase(res), cint_dup(rem, num); // answer ** 2 + rem = num
    if (num->nat > 0 && num->end != num->mem)
    {   cint *a = h_cint_tmp(sheet, 0, num), *b = h_cint_tmp(sheet, 1,
                  num);
        cint_erase(a), *a->end++ = 1;
        cint_left_shifti(a, cint_count_bits(num) & ~1);
        for (; a->mem != a->end;)
        {   cint_dup(b, res);
            h_cint_addi(b, a);
            cint_right_shifti(res, 1);
            if (h_cint_compare(rem, b) >= 0)
                h_cint_subi(rem, b), h_cint_addi(res, a);
            cint_right_shifti(a, 2);
        }
    }
}

static void cint_cbrt(cint_sheet *sheet, const cint *num, cint *res,
                      cint *rem)
{   // original cube root algorithm.
    cint_erase(res), cint_dup(rem, num); // answer ** 3 + rem = num
    if (num->mem != num->end)
    {   cint *a = h_cint_tmp(sheet, 0, num), *b = h_cint_tmp(sheet, 1,
                  num);
        for (size_t c = cint_count_bits(num) / 3 * 3; c < -1U; c -= 3)
        {   cint_left_shifti(res, 1);
            cint_dup(a, res);
            cint_left_shifti(a, 1);
            h_cint_addi(a, res);
            cint_mul(a, res, b);
            ++*b->mem; // "b" isn't "normalized", it should work for an addition.
            h_cint_addi(b, a);
            cint_dup(a, rem);
            cint_right_shifti(a, c);
            if (h_cint_compare(a, b) >= 0)
                cint_left_shifti(b, c), h_cint_subi(rem, b), cint_erase(b),
                                 *b->end++ = 1, h_cint_addi(res, b);
        }
        res->nat = num->nat;
    }
}

static void cint_nth_root(cint_sheet *sheet, const cint *num,
                          const unsigned nth, cint *res)
{   // original nth-root algorithm, it does not try to decompose "nth" into prime factors.
    switch (nth)
    {   case 0 : cint_reinit(res, num->end == num->mem + 1 &&
                                 *num->mem == 1); break;
        case 1 : cint_dup(res, num); break;
        case 2 : cint_sqrt(sheet, num, res, h_cint_tmp(sheet, 2, num)); break;
        case 3 : cint_cbrt(sheet, num, res, h_cint_tmp(sheet, 2, num)); break;
        default:
            if (num->end > num->mem + 1 || *num->mem > 1)
            {   cint *a = h_cint_tmp(sheet, 2, num),
                          *b = h_cint_tmp(sheet, 3, num),
                           *c = h_cint_tmp(sheet, 4, num),
                            *d = h_cint_tmp(sheet, 5, num),
                             *e = h_cint_tmp(sheet, 6, num), *r = res, *tmp;
                cint_erase(a), *a->end++ = 1, cint_erase(d), *d->end++ = 1;
                cint_left_shifti(a, (cint_count_bits(num) + nth - 1) / nth);
                h_cint_addi(r, d), cint_reinit(d, nth - 1), cint_reinit(e, nth);
                do
                {   tmp = a, a = r, r = tmp, cint_dup(a, num);
                    for (unsigned count = nth; --count &&
                         (cint_div(sheet, a, r, b, c), tmp = a, a = b, b = tmp,
                          a->mem != a->end););
                    cint_mul(r, d, b);
                    h_cint_addi(b, a);
                    cint_div(sheet, b, e, a, c);
                }
                while (h_cint_compare(a, r) < 0);
                r == res ? (void) 0 : cint_dup(res, tmp == a ? a : r);
                res->nat = nth & 1 ? num->nat : 1;
            }
            else cint_dup(res, num);
    }
}

static void cint_nth_root_remainder(cint_sheet *sheet,
                                    const cint *num, const unsigned nth, cint *res, cint *rem)
{   // nth-root algorithm don't provide the remainder, so here it computes the remainder.
    if (nth == 2) cint_sqrt(sheet, num, res, rem);
    else if (nth == 3) cint_cbrt(sheet, num, res, rem);
    else
    {   cint_nth_root(sheet, num, nth, res);
        cint *a = h_cint_tmp(sheet, 2, num);
        cint_reinit(a, nth);
        cint_pow(sheet, res, a, rem);
        cint_subi(rem, num);
    }
}

static void cint_random_bits(cint *num, size_t bits, uint64_t * seed)
{   // provide a positive random number having exactly the requested number of bits.
    // the pseudorandom number generator (PRNG) seed is updated at every call.
    cint_erase(num);
    uint64_t *r = *seed ? seed : (*seed = 0x2236b69a7d223bd, seed);
    for (const size_t exp = cint_exponent; exp < bits; bits -= exp)
        *num->end++ = (h_cint_t) ((*r ^= *r << 13, *r ^= *r >> 7,
                                   *r ^= *r << 17) & cint_mask);
    if (bits)
    {   *r ^= *r << 3, *r ^= *r >> 1, *r ^= *r << 11;
        *num->end++ |= 1 << (bits - 1) | (h_cint_t) (*r & cint_mask) >>
                       (cint_exponent - bits);
    }
}

static void cint_modular_inverse(cint_sheet *sheet, const cint *lhs,
                                 const cint *rhs, cint *res)
{   // original modular inverse algorithm, answer is also called "u1" in extended Euclidean algorithm context.
    if (*rhs->mem > 1 || rhs->end > rhs->mem + 1)
    {   cint *a = h_cint_tmp(sheet, 2, rhs),
                  *b = h_cint_tmp(sheet, 3, rhs),
                   *c = h_cint_tmp(sheet, 4, rhs),
                    *d = h_cint_tmp(sheet, 5, rhs),
                     *e = h_cint_tmp(sheet, 6, rhs),
                      *f = h_cint_tmp(sheet, 7, rhs), *tmp, *out = res;
        cint_dup(a, lhs), cint_dup(b, rhs), cint_erase(res), *res->end++ = 1,
        cint_erase(e);
        a->nat = b->nat = 1;
        int i = 0;
        do
        {   cint_div(sheet, a, b, c, d);
            cint_mul(c, e, f);
            cint_dup(c, res);
            cint_subi(c, f);
            tmp = a, a = b, b = d, d = tmp;
            tmp = res, res = e, e = c, c = tmp;
        }
        while (++i, (d->mem == d->end) == (b->mem == b->end));
        if (a->end == a->mem + 1 && *a->mem == 1)
        {   if (i & 1) cint_addi(res, e);
        }
        else cint_erase(res);
        if (out != res) cint_dup(out, res);
    }
    else cint_erase(res);
}

int cint_is_prime(cint_sheet *sheet, const cint *N, int iterations,
                  uint64_t * seed)
{   // is N is considered as a prime number ? the function returns 0 or 1.
    // when the number of Miller-Rabin iterations is zero, it's automatic.
    int res;
    if (0 < N->nat && *N->mem < 961 && N->mem + 1 >= N->end)
    {   int n = (int)
                *N->mem; // Small numbers for which Miller-Rabin is not used.
        res = (n > 1) & ((n < 6) * 42 + 0x208A2882) >> n % 30 && (n < 49 ||
                (n % 7 && n % 11 && n % 13 && n % 17 && n % 19 && n % 23 && n % 29));
    }
    else if (res = 0 < N->nat && (*N->mem & 1) != 0, res)
    {   cint *A = h_cint_tmp(sheet, 5, N),
                  *B = h_cint_tmp(sheet, 6, N),
                   *C = h_cint_tmp(sheet, 7, N);
        size_t a, b, bits = cint_count_bits(N), rand_mod = bits - 3;
        if (iterations <= 0)
            // decides the number of Miller-Rabin iterations for the caller ...
            iterations = bits < 150 ? 24 : bits < 200 ? 18 : bits < 250 ? 16 :
                         bits < 300 ? 13 : bits < 350 ? 10 : bits < 400 ? 9 : bits < 450 ? 8 :
                         bits < 550 ? 7 : bits < 650 ? 6 : bits < 850 ? 5 : bits < 1300 ? 4 : 3
                         ;
        cint_dup(A, N);
        cint_erase(B), *B->end++ = 1;
        cint_subi(A, B);
        cint_dup(C, A); // C = (N - 1)
        cint_right_shifti(C, a = cint_count_zeros(
                                     C)); // divides C by 2 until C is odd
        for (bits = 2; iterations-- && res;)
        {   cint_random_bits(B, bits, seed); // take a number
            bits = 3 + *B->mem % rand_mod;
            cint_pow_modi(sheet, B, C, N); // raise to the power C mod N
            if (*B->mem != 1 || B->end != B->mem + 1)
            {   for (b = a; b-- && (res = h_cint_compare(A, B));)
                    cint_mul_modi(sheet, B, B, N);
                res = !res;
            } // only a prime number can hold (res = 1) forever
        }
    }
    return res;
}



// Quadratic sieve integers.
typedef uint32_t qs_sm; // small size, like a factor base prime number (32-bit)
typedef uint64_t qs_md; // medium size, like a factor base prime number squared (64-bit)
typedef int64_t qs_tmp; // signed type to perform intermediates computations

// 64-bit factorization integers.
typedef uint64_t u64;

// 64-bit factorization structure

typedef struct
{   u64 prime;
    int power;
} fac64_row;

// Factorization manager's structure

typedef struct Xstate
{   struct Xstate1
    {   int tty ;
        int verbose;
        qs_md force;
        qs_md help;
        struct Xstate2
        {   uint64_t seed;
            uint64_t custom;
        } rand;
        qs_md demand[3];
        qs_md timeout;
        const char *input_file;
        const char *output_file;
        char output_format;
        qs_md qs_multiplier;
        qs_md qs_base_size;
        qs_md qs_sieve;
        qs_md qs_error_bits;
        qs_md qs_threshold;
        qs_md qs_alloc_mb;
        qs_md qs_large_prime;
        qs_md qs_poly;
        qs_md qs_laziness;
        //
        qs_md qs_sieve_cutoff; // not documented (see the source code)
        qs_md qs_tick_end; // not documented (see the source code)
    } params;
    qs_md duration_ms ;
    FILE *in;
    FILE *out;
    int code;
    struct Xstate3
    {   size_t row_idx;
        size_t total_rows;
        size_t max_factors;
        size_t max_digits;
        size_t max_bits;
    } scale;
    struct Xstate4
    {   cint num;
        cint tmp[10];
        cint_sheet *sheet;
        qs_md duration_ms;
        uint64_t *seed;
        qs_sm trial_start;
        int power;
        const char *input_string;
        char *output_string;
        struct Xstate5
        {   cint num;
            int power;
            int prime;
        } *res;
        struct Xstate6
        {   void *base;
            void *now;
        } mem;
    } session;
} state;

// Quadratic sieve structures

struct qs_relation
{   qs_sm id; // smooth relations have a non-zero id.
    cint *X;
    struct
    {   qs_sm *data;
        qs_sm length;
    } Y;
    union
    {   struct
        {   qs_sm *data;
            qs_sm length;
        } Z;
        struct qs_relation *next;
    } axis;
    // axis :
    // - "Z" field is used by smooth relations.
    // - "next" is used by partial relations sharing the same variation, grouped within a linked list.
};

typedef struct XSheet
{

    // computation sheet
    cint_sheet *sheet;

    // numbers that are updated
    struct XSheet1
    {   cint N;
        cint FACTOR;
        cint X;
        cint KEY;
        cint VALUE;
        cint CYCLE;
        cint TEMP[5];
    } vars;

    // polynomial vars
    struct XSheet2
    {   cint A;
        cint B;
        cint C;
        cint D;
        qs_sm d_bits;
        qs_sm offset;
        struct XSheet3
        {   qs_sm x_1;
            qs_sm half ;
            qs_sm x_2 ;
            qs_sm x_3 ;
        } span;
        qs_sm gray_max;
        qs_sm curves;
    } poly;

    // constants
    struct XSheet4
    {   cint kN;
        cint ONE;
        cint TOO_LARGE_PRIME;
        cint MULTIPLIER;
        cint M_HALF;
    } constants;

    // system
    struct XSheet5
    {   qs_sm bytes_allocated;
        void *base;
        void *now;
    } mem;

    // parameters and miscellaneous vars
    struct XSheet6
    {   qs_md start;
        qs_md end;
        qs_md now;
        qs_sm tick;
        double prev_pct ;
    } time;
    uint64_t * seed;
    qs_md adjustor;
    qs_sm multiplier;
    qs_sm n_bits;
    qs_sm kn_bits;
    struct XSheet7
    {   uint8_t **positions[2];
        uint8_t *sieve;
        uint8_t *flags;
        qs_sm length;
        qs_sm length_half;
        qs_sm cache_size;
    } m;
    qs_sm iterative_list[5];
    qs_sm error_bits;
    struct XSheet8
    {   qs_sm value;
    } threshold;
    qs_sm sieve_again_perms;

    // useful data sharing same length
    struct XSheet9
    {   struct XSheet10
        {   qs_sm num;
            qs_sm size;
            qs_sm sqrt_kN_mod_prime;
            qs_sm root[2];
        } *data;
        qs_sm largest;
        qs_sm length;
    } base;

    // useful data sharing same length
    struct XSheet11
    {   qs_sm *A_indexes;
        struct XSheet12
        {   cint B_terms;
            qs_sm *A_inv_double_value_B_terms;
            qs_sm A_over_prime_mod_prime;
            qs_sm prime_index;
            qs_md prime_squared;
        } *data;
        struct XSheet13
        {   qs_sm defined;
            qs_sm subtract_one;
            qs_sm double_value;
        } values;
    } s;

    qs_sm *buffer[2]; // proportional to "length of factor base" (medium or large)

    // uniqueness trees : [ relations, cycle finder, divisors of N, ]
    struct avl_manager uniqueness[3];

    // data collection made by algorithm
    struct XSheet14
    {   struct qs_relation **data;
        struct XSheet15
        {   qs_sm prev;
            qs_sm now;
            qs_sm peak;
            qs_sm needs;
            qs_sm capacity;
            qs_sm by_partial;
        } length;
        qs_md too_large_prime;
    } relations;

    // pointers to the divisors of N are kept in a flat array
    struct XSheet15
    {   qs_sm total_primes;
        qs_sm length;
        cint **data;
    } divisors;

    // Lanczos has its own struct
    struct XSheet16
    {   qs_sm n_iterations;
        qs_sm safe_length;
        struct XSheet17
        {   struct qs_relation *relation;
            qs_sm y_length;
        } *snapshot;
    } lanczos;

    state *qs_state;

} qs_sheet;

// Factorization manager, file i/o utilities, misc utilities.
static void print_help(const char *);
static qs_md get_num(const char *);
static int cli_param_match(const char *, const char *, const char *);
static int read_key_and_3_values(const char **, state *);
static int read_key_and_2_values(const char **, state *);
static int read_key_value(const char **, state *);
static int read_flags(const char **, state *);
static void simple_rand(cint_sheet *, uint64_t *, cint *, char *, int,
                        int);
static void generate_input_file(state *);
static char *simple_cint_string(state *, const cint *);
static inline void simple_inline_cint(cint *, size_t, void **);
static void simple_dup_cint(cint *, const cint *, void **);
static inline void simple_int_to_cint(cint *, qs_md);
static qs_md simple_cint_to_int(const cint *);
static struct avl_node *avl_cint_inserter(void *, const void *);
static void *mem_aligned(void *);
static uint64_t get_time_ms(void);
static void debug_print(const state *, int, const char *, ...);
static void display_progress(const char *, double);
static void manager_add_factor(state *, const cint *, int, int);
static void manager_add_simple_factor(state *, qs_md, int, int);
static void factorization_64_bits(state *);
static int factorization_trial_division(state *, int, int);
static int factorization_any_root_checker(state *, const cint *,
        cint *, cint *);
static int factorization_perfect_power_checker(state *, int);
static int factorization_prime_number_checker(state *, int) ;
static int factorization_give_up(state *, int);
static int factor(state *);
static int validate_input_file(state *);
static size_t prepare_file_descriptors(state *);
static int validate_string_number(const char *, state *);
static void output_csv(state *, int, int, int);
static void output_json(state *, int, int, int);
static void output_default(state *, int, int, int);
static void output(state *, int);
static void prepare_sessions(state *);
static void erase_session(state *);
static void clear_sessions(state *);
static void process_single(state *);
static void process_multi(int, const char **, state *);

// Math functions and system utilities.
static inline qs_md xor_random(qs_md *);
static inline qs_md xor_rand(qs_md *, qs_md, qs_md);
static int is_prime_4669913(qs_sm);
static double log_computation(double);
static inline qs_sm multiplication_modulo(qs_md, qs_md, qs_sm);
static inline qs_sm power_modulo(qs_md, qs_md, qs_sm);
static int kronecker_symbol(qs_sm, qs_sm);
static qs_sm tonelli_shanks(qs_sm, qs_sm);
static qs_sm modular_inverse(qs_sm, qs_sm);

// 64-bit factorization.
static int bit_size(u64);
static u64 mul_mod(u64, u64, u64);
static u64 pow_mod(u64, u64, u64);
static int is_prime_64_bits(u64);
static u64 pollard_rho(u64, uint64_t *);
static u64 nth_root(u64, u64);
static u64 square_extraction(u64 *, int *);
static void fac_64_worker(state *, u64, fac64_row *);

// Quadratic sieve.
static int factorization_quadratic_sieve(state *, int);
static int inner_continuation_condition(qs_sheet *);
static int outer_continuation_condition(qs_sheet *);
static void qs_parametrize(qs_sheet *);
static qs_sm linear_param_resolution(const double [][2], qs_sm);
static void preparation_part_1(qs_sheet *, state *, int);
static void preparation_part_2(qs_sheet *);
static void preparation_part_3(qs_sheet *);
static void preparation_part_3_default_proposition(qs_sheet *,
        qs_sm *, size_t);
static void preparation_part_3_alternative_proposition(qs_sheet *,
        qs_sm *, size_t);
static void preparation_part_4(qs_sheet *);
static void preparation_part_5(qs_sheet *);
static void preparation_part_6(qs_sheet *);
static void get_started_iteration(qs_sheet *);
static void iteration_part_1(qs_sheet *, const cint *, cint *);
static void iteration_part_2(qs_sheet *, const cint *, cint *);
static void iteration_part_3(qs_sheet *, const cint *, const cint *);
static qs_sm iteration_part_4(const qs_sheet *, qs_sm, qs_sm **,
                              cint *);
static void iteration_part_5(qs_sheet *, const cint *, const cint *);
static void iteration_part_6(qs_sheet *, const cint *, const cint *,
                             const cint *, cint *);
static void iteration_part_7(qs_sheet *, qs_sm,
                             const qs_sm *restrict);
static void iteration_part_8(qs_sheet *, qs_sm, const qs_sm *);
static cint * qs_divisors_uniqueness_helper(qs_sheet *, const cint *);
static int qs_register_divisor(qs_sheet *);
static void register_relations(qs_sheet *, const cint *, const cint *,
                               const cint *);
static void register_regular_relation(qs_sheet *, const cint *,
                                      const qs_sm *const restrict[4]);
static void register_partial_relation(qs_sheet *, const cint *,
                                      const cint *, const qs_sm *const restrict[4]);
static void finalization_part_1(qs_sheet *, const uint64_t *restrict);
static int finalization_part_2(qs_sheet *);

// Linear algebra with Block Lanczos algorithm.
static void lanczos_mul_MxN_Nx64(const qs_sheet *, const uint64_t *,
                                 qs_sm, uint64_t *);
static void lanczos_mul_trans_MxN_Nx64(const qs_sheet *,
                                       const uint64_t *, uint64_t *);
static void lanczos_mul_64xN_Nx64(const qs_sheet *, const uint64_t *,
                                  const uint64_t *, uint64_t *, uint64_t *);
static uint64_t lanczos_find_non_singular_sub(const uint64_t *,
        const uint64_t *, uint64_t *, uint64_t, uint64_t *);
static void lanczos_mul_Nx64_64x64_acc(qs_sheet *, const uint64_t *,
                                       const uint64_t *, uint64_t *, uint64_t *);
static void lanczos_mul_64x64_64x64(const uint64_t *,
                                    const uint64_t *, uint64_t *);
static void lanczos_transpose_vector(qs_sheet *, const uint64_t *,
                                     uint64_t **);
static void lanczos_combine_cols(qs_sheet *, uint64_t *, uint64_t *,
                                 uint64_t *, uint64_t *);
static void lanczos_build_array(qs_sheet *, uint64_t **, size_t,
                                size_t);
static uint64_t *lanczos_block_worker(qs_sheet *);
static void lanczos_reduce_matrix(qs_sheet *);
static uint64_t *block_lanczos(qs_sheet *);

// Beyond this limit, the "--force" option is required to run a Quadratic Sieve.

#define DEFAULT_BIT_LIMIT_QS 220

// Verbose level 0: just factorization, no other messages (default when there is no terminal).
// Verbose level 1: also show task progress in percentage (default when there is a terminal).
// Verbose level 2: also displays final status and duration.
// Verbose level 3: also show maintenance messages.
// Verbose level 4: also show Quadratic Sieve detailed information.

#define DEBUG_LEVEL_2(fmt, ...) debug_print(qs->qs_state, 2, fmt, __VA_ARGS__)
#define DEBUG_LEVEL_3(fmt, ...) debug_print(qs->qs_state, 3, fmt, __VA_ARGS__)
#define DEBUG_LEVEL_4(fmt, ...) debug_print(qs->qs_state, 4, fmt, __VA_ARGS__)

void print_help(const char *path)
{   puts("=== Factorization software v2.0.0 using Quadratic Sieve ===\n");
    puts("This software is released \"as it is\" into the public domain, without any warranty, express or implied.\n");
    puts("DESCRIPTION:");
    puts("  This software supports factoring numbers through a Self-Initializing Quadratic Sieve (SIQS).");
    puts("  The Factorization Manager reads numbers to be factored from either a file or the command line.\n");
    puts("USAGE:");
    printf("  %s [options] [numbers]\n\n", path);
    puts("OPTIONS:");
    puts("  -i, --input-file <FILE>      Factor all numbers from the specified input file.");
    puts("  -o, --output-file <FILE>     Write results to the specified output file.");
    puts("  -t, --timeout <SECONDS>      Set a timeout in seconds to interrupt the Quadratic Sieve.");
    puts("  -r, --rand-seed <NUMBER>     Use another set of random numbers that depend on <NUMBER>, 0 for the Unix timestamp.");
    puts("  -v, --verbose <VALUE>        Between 0 and 4, displays more or less information.");
    printf("  -f, --force                  Override default limits (8191 digits for numbers and %u-bit for the Quadratic Sieve).\n",
           DEFAULT_BIT_LIMIT_QS);
    puts("  -h, --help                   Show this help message and exit.\n");
    puts("OUTPUT FORMATS:");
    puts("  -j, --output-json            Format the results in JSON.");
    puts("  -J, --output-json-extended   Format the results in JSON with details.");
    puts("  -c, --output-csv             Format the results in CSV.");
    puts("  -C, --output-csv-extended    Format the results in CSV with details.\n");
    puts("QUADRATIC SIEVE OPTIONS:");
    puts("  --qs-multiplier <value>      Usually from 1 to 150");
    puts("  --qs-base-size <value>       Usually from 1000 to 50000");
    puts("  --qs-large-prime <value>     Usually from 300000 to 30000000");
    puts("  --qs-alloc-mb <value>        Usually from 1 to a few hundred");
    puts("  --qs-sieve <value>           Usually close to a multiple of 31744");
    puts("  --qs-threshold <value>       Usually from 60 to 110");
    puts("  --qs-error-bits <value>      Usually from 15 to 35");
    puts("  --qs-laziness <value>        Usually from 80 to 120 (in percentage)\n");
    puts("  Navigate through the source code to see their default value and usage.\n");
    puts("EXAMPLES:");
    puts("  -i input.txt -o output.txt --output-csv    # Factor all numbers from \"input.txt\" to \"output.txt\" in CSV.");
    puts("  27333597444727959277 36190584594536893817  # Factor the numbers.\n");
    puts("REPORTING BUGS:");
    puts("  Read the full documentation and report issues to the \"github.com/michel-leonard/C-Quadratic-Sieve\" repository.\n");
    puts("TESTING:");
    puts("  --demand -r 123        # provide a 'demand.txt' file that depends on the seed 123, suitable as input file.");
    puts("  -d 150                 # provide a 'demand.txt' file containing a single 150-bit sample number.");
    puts("  -d 60 150              # provide a 'demand.txt' file containing sample numbers ranging from 60-bit to 150-bit.");
    puts("  -d 150 150 100         # provide a 'demand.txt' file containing 100 sample numbers of 150-bit.");
    puts("  -i demand.txt -C -v 2  # Factor the 'demand.txt' file and display a status message.\n");
    puts("EXIT STATUS:");
    puts("  0  All numbers were successfully fully factored.");
    puts("  1  At least one number among the results is not fully factored.\n");
}

qs_md get_num(const char *s)
{   char *end = 0;
    const qs_md res = strtoull(s + (*s == '-'), &end, 10);
    return end != s && !*end ? *s == '-' ? -res : res : 0;
}

int cli_param_match(const char *str, const char *long_name,
                    const char *short_name)
{   return (short_name && !strcmp(str, short_name)) ||
           !strcmp(str, long_name);
}

int read_key_and_3_values(const char **argv, state *state)
{
#define FILL(name_1, shortcut, name_2) \
    if (cli_param_match(*argv, "--" #name_1, "-" #shortcut) && \
        (n_1 = get_num(*(argv + 1))) && \
        (n_2 = get_num(*(argv + 2))) && \
        (n_3 = get_num(*(argv + 3)))) { \
        state->params.name_2[0] = n_1; \
        state->params.name_2[1] = n_2; \
        state->params.name_2[2] = n_3; \
    }
    qs_md n_1, n_2, n_3;
    FILL(demand, d, demand)
    else
        return 0;
    *argv = *(argv + 1) = *(argv + 2) = *(argv + 3) = 0;
    return 1;
}

int read_key_and_2_values(const char **argv, state *state)
{
#define FETCH ((n_1 = get_num(val_1)) && (n_2 = get_num(val_2)))
    const char *key = *argv, *val_1 = *(argv + 1), *val_2 = *(argv + 2);
    qs_md n_1, n_2;
    if (cli_param_match(key, "--demand", "-d") && FETCH)
        state->params.demand[0] = n_1, state->params.demand[1] = n_2;
    else
        return 0;
    *argv = *(argv + 1) = *(argv + 2) = 0;
    return 1;
#undef FETCH
}

int read_key_value(const char **argv, state *state)
{   const char *key = *argv, *value = *(argv + 1);
    if (cli_param_match(key, "--verbose", "-v") && *value >= '0' &&
        *value <= '9' && !*(value + 1))
        state->params.verbose = *value - '0';
    else if (cli_param_match(key, "--input-file", "-i"))
        state->params.input_file = value;
    else if (cli_param_match(key, "--output-file", "-o"))
        state->params.output_file = value;
    else if (cli_param_match(key, "--timeout", "-t"))
        state->params.timeout = get_num(value);
    else if (cli_param_match(key, "--rand-seed", "-r"))
        state->params.rand.seed ^= state->params.rand.custom = *value == '0'
                                   && *(value + 1) == 0 ? get_time_ms() : get_num(value);
    else if (cli_param_match(key, "--demand", "-d") && get_num(value))
        state->params.demand[0] = get_num(value);
    // Quadratic Sieve specific parameters.
#define QS_PARAM(name_1, name_2) \
    else if (cli_param_match(key, "--qs-" #name_1, 0)) \
        state->params.qs_##name_2 = get_num(value);
    QS_PARAM(multiplier, multiplier)
    QS_PARAM(base-size, base_size)
    QS_PARAM(large-prime, large_prime)
    QS_PARAM(alloc-mb, alloc_mb)
    QS_PARAM(sieve, sieve)
    QS_PARAM(sieve-cutoff, sieve_cutoff)
    QS_PARAM(threshold, threshold)
    QS_PARAM(error-bits, error_bits)
    QS_PARAM(laziness, laziness)
    QS_PARAM(tick-end, tick_end)
    else
        return 0;
#undef QS_PARAM
    *argv = *(argv + 1) = 0;
    return 1;
}

int read_flags(const char **argv, state *state)
{   const char *key = *argv;
    if (cli_param_match(key, "--verbose", "-v"))
        state->params.verbose = 2;
    else if (cli_param_match(key, "--output-json-extended", "-J"))
        state->params.output_format = 'J';
    else if (cli_param_match(key, "--output-json", "-j"))
        state->params.output_format = 'j';
    else if (cli_param_match(key, "--output-csv-extended", "-C"))
        state->params.output_format = 'C';
    else if (cli_param_match(key, "--output-csv", "-c"))
        state->params.output_format = 'c';
    else if (cli_param_match(key, "--force", "-f"))
        state->params.force = 1;
    else if (cli_param_match(key, "--demand", "-d"))
        state->params.demand[0] = -1;
    else if (cli_param_match(key, "--help", "-h"))
        state->params.help = 1;
    else
        return 0;
    *argv = 0;
    return 1;
}

void simple_rand(cint_sheet *sheet, uint64_t *seed, cint *nums,
                 char *comment, const int factors_needed, const int bits_needed)
{
// Produces a random composite number based on the seed, number of bits, and factors.
// Fill in the comment if the resulting number intentionally contains a power, empty it otherwise.
begin :;
    cint *N = nums, *P = N + 1, *A = N + 2, *TMP;
    int bits_generated = 0, i = 0, remaining_factors = factors_needed,
        sym = 'A';
    char *message = comment ;
    *message = 0 ;
    cint_reinit(N, 1);
    do
    {   const int factor_bits = (bits_needed - bits_generated) /
                                remaining_factors;
    retry :;
        if (factor_bits < 3)
            goto begin;
        cint_random_bits(P, factor_bits + i, seed);
        *P->mem |= 1;
        if (!cint_is_prime(sheet, P, -1, seed))
            goto retry;
        i = !i;
        if (2 < remaining_factors && !xor_rand(seed, 0, 24))
        {   // Occasionally raise this prime number to a power.
            int pow = (int) xor_rand(seed, 2, remaining_factors - 1);
            remaining_factors += 1 - pow;
            message += sprintf(message, " %s %c^%d", sym == 'A' ? "and" : "*",
                               sym, pow);
            ++sym;
            do
            {   cint_mul(N, P, A);
                if (--pow)
                    TMP = A, A = N, N = TMP;
            }
            while (pow);
        }
        else
            cint_mul(N, P, A);
        const int old_bits = bits_generated;
        bits_generated = (int) cint_count_bits(A);
        if (remaining_factors == 1 && bits_generated != bits_needed)
        {   bits_generated = old_bits;
            goto retry;
        }
        TMP = A, A = N, N = TMP;
    }
    while (--remaining_factors);
    if (N != nums)
        cint_dup(nums, N);
}

void generate_input_file(state *state)
{   // Simulate a factorization demand based on the "-d <min-bits> <max-bits> <count>" command line option.
    // For example "--demand 130 140 1000" provide 1000 non-trivial numbers between 130 and 140 bits.
    // The generated "demand.txt" file is suitable as an input file and consistent across platforms.
    // The contents of the file may depend on the "--rand-seed" command line option.
    const char *path = state->params.output_file;
    FILE *fp = fopen(path ? path : "demand.txt", "wb");
    if (fp)
    {   uint64_t seed = state->params.rand.seed;
        qs_md *g = state->params.demand,
              min = g[0],
              max = g[1],
              count = g[2],
              tmp, i;
        if (min == (qs_md)(-1)) // No params specified.
            min = 6, max = DEFAULT_BIT_LIMIT_QS ;
        assert(!(min >> 12) && !(max >> 12));
        min = min < 6 ? 6 : 1300 < min ? 1300 : min;
        if (max)
        {   max = max < 6 ? 6 : 1300 < max ? 1300 : max;
            if (max < min)
                tmp = min, min = max, max = tmp;
        }
        else
            max = min;
        count += !count;
        tmp = max - min + 1;
        if (count < tmp)
            count = tmp;
        if (count * (max + 12) >> 24)
            count = (1 << 24) / (max + 12) ; // ~8MB per file.
        double bits = min, step = (double) tmp / (double) count;
        cint_sheet *sheet = cint_new_sheet(max << 1);
        cint nums[3];
        for (i = 0; i < 3; ++i)
            cint_init(nums + i, max << 1, 1);
// max_len here is not constexpr so buff is being set up as a dynamically
// sized array!
        const int their_max_len = cint_approx_digits_from_bits(max, 10);
        constexpr int max_len = 4096;
        if (their_max_len > max_len)
        {   std::cout << "\n+++ Attempt to use qsieve on overlarge number\n";
            std::abort();
        } 
        char buf[max_len + 255], *title = buf + max_len,
                                  *comment = title + 127, *str = title ;
        str += sprintf(str, "Generated %d sample number%s ", (int) count,
                       1 < count ? "s" : "");
        if (min == max)
            str += sprintf(str, "of %d-bit", (int) min);
        else
            str += sprintf(str, "ranging from %d-bit to %d-bit", (int) min,
                           (int) max);
        if (state->params.rand.custom)
            sprintf(str, " using seed %" PRIu64, state->params.rand.custom);
        fprintf(fp, "# %s.\n# Use \"--demand", title);
        for(int j = 0; j < 3 && g[j] && g[j] != (qs_md)(-1); ++j)
            fprintf(fp, " %d", (int)g[j]);
        if (state->params.rand.custom)
            fprintf(fp, " --rand-seed %" PRIu64, state->params.rand.custom);
        fprintf(fp, "\" to retrieve this file.\n\n");
        i = 0;
        do
        {   // DEVELOPMENT : decrease 24 and 17 in the next line to test the trial division.
            const int n_factors_max = (int)bits / (65.0 <= bits ? 24 : 34.0 <=
                                                   bits ? 17 : 3);
            const int n_factors = xor_rand(&seed, 2, xor_rand(&seed, 2,
                                           n_factors_max));
            simple_rand(sheet, &seed, nums, comment, n_factors, bits);
            cint_to_string_buffer(nums, buf, 10);
            fprintf(fp, "%-*s # %d bits with %d factors%s\n", max_len, buf,
                    (int) bits, n_factors, comment);
            fflush(fp);
            if (state->params.tty && state->params.verbose)
                display_progress("Factorization file preparation",
                                 (double) i * 100.0 / (double) count);
        }
        while (bits += step, ++i < count);
        if (state->params.tty && state->params.verbose)
            display_progress(0, 100);
        fclose(fp);
        for (i = 0; i < 3; ++i)
            free(nums[i].mem);
        cint_clear_sheet(sheet);
        if (state->params.verbose)
            fprintf(stdout, "%s in file '%s'.\n", title,
                    path ? path : "demand.txt");
    }
    else
        perror("Factorization program generator");
}

// cint shortcuts
char *simple_cint_string(state *state, const cint *N)
{   char *s = cint_to_string_buffer(N, state->session.output_string,
                                    10);
    if (0)    // Add a thousand separator in debug for large number (as desired).
        for (int len = (int) strlen(s), i = len - 3, j = *s == '-'; j < i;
             i -= 3)
            memmove(s + i + 1, s + i, ++len - i), s[i] = ',';
    return s;
}

void simple_inline_cint(cint *N, const size_t size, void **mem)
{   // Fixed size cint is inlined, given mem is updated accordingly.
    N->mem = N->end = (h_cint_t *) *mem;
    *mem = N->mem + (N->size = size + 1);
}

void simple_dup_cint(cint *A, const cint *B, void **mem)
{   // Duplicates cint using the given memory, which is updated accordingly.
    // It uses the minimal size, the duplicate is not resizable.
    A->mem = A->end = (h_cint_t *) *mem;
    cint_dup(A, B);
    A->size = A->end - A->mem + 1;
    *mem = A->mem + A->size;
}

void simple_int_to_cint(cint *num, qs_md value)
{   // Pass the given 64-bit number into the given cint (positive only).
    for (cint_erase(num); value;
         *num->end++ = (h_cint_t) (value & cint_mask),
         value >>= cint_exponent);
}

qs_md simple_cint_to_int(const cint *num)
{   // Return the value of a cint as a 64-bit integer (sign is ignored).
    qs_md res = 0;
    for (h_cint_t *ptr = num->end; ptr > num->mem;
         res = (qs_md) (res * cint_base + *--ptr));
    return res;
}

// Avl
struct avl_node *avl_cint_inserter(void *args, const void *key_to_save)
{   // it expects as result a new node containing the given constant key.
    void *mem = *(void **) args;
    struct avl_node *res = (avl_node*)mem;
    res->key = (cint *) (res + 1);
    mem = (cint *) res->key + 1;
    simple_dup_cint((cint*)res->key, (const cint*)key_to_save, &mem);
    assert(res->value == 0);
    *(void **) args = mem;
    return res;
}

// System
void *mem_aligned(void *ptr)
{   // Default alignment of the return value is 64.
    char *res __attribute__((aligned(64)));
    res = (char *) ptr + (64 - (uintptr_t) ptr) % 64;
    return res;
}

uint64_t get_time_ms(void)
{   // returns the current Unix timestamp with milliseconds.
    struct timeval time;
    gettimeofday(&time, NULL);
    return (uint64_t) time.tv_sec * 1000 + (uint64_t) time.tv_usec / 1000;
}

void debug_print(const state *state, int level, const char *format,
                 ...)
{   if (level <= state->params.verbose)
    {   va_list args;
        va_start(args, format);
        vfprintf(stderr, format, args);
        va_end(args);
        fflush(stderr);
    }
}

void display_progress(const char *name, double percentage)
{   static int chars = 0;
    if (percentage < 100.)
        // Print a progression percentage.
        chars = printf("\r- %s at %.02f %% ...\r", name, percentage);
    else
        // Clear the progression line.
        chars = !printf("\r%*s\r", chars, "");
    fflush(stdout);
}

// Factorization
void manager_add_factor(state *state, const cint *num, int pow,
                        int is_prime)
{   assert(0 < pow);
    int i = 0;
    while (state->session.res[i].power &&
           h_cint_compare(&state->session.res[i].num, num))
        ++i;
    simple_inline_cint(&state->session.res[i].num, num->end - num->mem,
                       &state->session.mem.now);
    cint_dup(&state->session.res[i].num, num);
    state->session.res[i].power = state->session.power * pow;
    if (0 < is_prime &&
        !cint_is_prime(state->session.sheet, num, -1, state->session.seed))
    {   debug_print(state, 3,
                    "[x] Maintenance challenges %s's primality test.\n",
                    simple_cint_string(state, num));
        is_prime = -1
                   ; // [MATH INSURANCE] Re-factor this number due to conflicting Miller-Rabin tests.
    }
    state->session.res[i].prime =
        is_prime; // Possible values are: -1 (must factorize), 0 (not prime), and 1 (prime).
    //
}

void manager_add_simple_factor(state *state, qs_md num, int pow,
                               int is_prime)
{   assert(0 < pow);
    simple_int_to_cint(state->session.tmp, num);
    manager_add_factor(state, state->session.tmp, pow, is_prime);
}

void factorization_64_bits(state *state)
{   fac64_row res[16];
    u64 num = simple_cint_to_int(&state->session.num);
    fac_64_worker(state, num, res);
    for (fac64_row *r = res; (*r).power; ++r)
        manager_add_simple_factor(state, (*r).prime, (*r).power,
                                  (*r).prime != 1);
    cint_reinit(&state->session.num, 1);
}

int factorization_trial_division(state *state, int stage, int bits)
{   assert(64 < bits);
    const int calc = stage == 2 ? (1 << 20) - 23250 * bits + 127 * bits *
                     bits : 4669914;
    const qs_sm trial_upto = stage == 1 ? 524 : calc < 65522 ? 65522 :
                             4669914 < calc ? 4669914 : calc;
    cint *a = state->session.tmp, *b = a + 1, *c = a + 2, *tmp;
    cint *n = &state->session.num;
    cint_sheet *sheet = state->session.sheet;
    cint_reinit(a, 1);
    qs_sm trial = state->session.trial_start;
    for (; trial < trial_upto; trial += 2)
        if (is_prime_4669913(trial))
        {   a->mem[0] = (h_cint_t) trial;
            cint_div(sheet, n, a, b, c);
            if (c->mem == c->end)
            {   int pow = 0;
                do
                {   ++pow;
                    tmp = n, n = b, b = tmp;
                    cint_div(sheet, n, a, b, c);
                }
                while (c->mem == c->end);
                manager_add_simple_factor(state, trial, pow, 1);
                if (n != &state->session.num)
                    cint_dup(&state->session.num, n);
                state->session.trial_start = trial + 2;
                return 1;
            }
        }
    state->session.trial_start = trial + 2;
    return 0;
}

int factorization_any_root_checker(state *state, const cint *n,
                                   cint *root, cint *rem)
{   // Returns the lowest power when the number is a perfect power, 0 otherwise.
    // The function takes into account the trial divisions already performed.
    int res = 0;
    cint_sheet *sheet = state->session.sheet;
    cint *max = state->session.tmp;
    cint_reinit(max, (int) state->session.trial_start - 2);
    const int max_root = (int) cint_count_bits(n);
    for (int nth = 2; nth < max_root; nth += 1 + (nth != 2))
        if (is_prime_4669913((qs_sm)nth))
        {   cint_nth_root_remainder(sheet, n, nth, root, rem);
            if (rem->mem == rem->end)
            {   res = nth;
                break;
            }
            if (h_cint_compare(root, max) <= 0)
                break;
        }
    return res;
}

int factorization_perfect_power_checker(state *state, int bits)
{   assert(64 < bits);
    cint *root = state->session.tmp + 1, *rem = root + 1;
    int pow = factorization_any_root_checker(state, &state->session.num,
              root, rem);
    if (pow)
    {   manager_add_factor(state, root, pow, -1);
        cint_reinit(&state->session.num, 1);
    }
    return pow;
}

int factorization_prime_number_checker(state *state, int bits)
{   assert(64 < bits);
    cint_sheet *sheet = state->session.sheet;
    const int is_prime = cint_is_prime(sheet, &state->session.num, -1,
                                       state->session.seed) != 0;
    if (is_prime)
    {   manager_add_factor(state, &state->session.num, 1, 1);
        cint_reinit(&state->session.num, 1);
    }
    return is_prime;
}

int factorization_give_up(state *state, int bits)
{   assert(64 < bits);
    manager_add_factor(state, &state->session.num, 1, 0);
    cint_reinit(&state->session.num, 1);
    return 1;
}

int factor(state *state)
{   state->session.duration_ms = get_time_ms();
    state->session.trial_start = 3;
    state->session.power = 1;
    int start_idx = 0, end_idx = 0;
    cint_dup(state->session.tmp + 9, &state->session.num);
    if (state->session.num.nat < 0)
    {   // Add -1 as factor for a negative number.
        cint_reinit(state->session.tmp, -1);
        manager_add_factor(state, state->session.tmp, 1, 0);
        state->session.num.nat = 1;
        ++start_idx;
    }
    int bits = (int) cint_count_zeros(&state->session.num);
    if (bits)
    {   // Remove the powers of two from the number.
        manager_add_simple_factor(state, 2, bits, 1);
        cint_right_shifti(&state->session.num, bits);
        // The number is odd.
        ++start_idx;
    }
    if (cint_compare_char(&state->session.num, 1) == 0)
    {   if (start_idx == 0)
        {   manager_add_simple_factor(state, 1, 1, 0);
            ++start_idx;
        }
    }
    else
{   start :;
        bits = (int) cint_count_bits(&state->session.num);
        if (state->params.tty && state->params.verbose)
            display_progress(0, 100);
        if (bits < 65)
        {   // 64-bit simple Pollard's Rho.
            if (1 < bits || start_idx == 0)
                factorization_64_bits(state);
        }
        else
        {   const int res = factorization_trial_division(state, 1, bits)
                            || factorization_prime_number_checker(state, bits)
                            || factorization_trial_division(state, 2, bits)
                            || factorization_perfect_power_checker(state, bits)
                            || factorization_quadratic_sieve(state, bits)
                            || factorization_trial_division(state, 3, bits)
                            || factorization_give_up(state, bits);
            assert(res);
            if (cint_compare_char(&state->session.num, 1))
                manager_add_factor(state, &state->session.num, 1, -1);
        }
        end_idx = start_idx;
        for (int i = (int) state->scale.max_factors - 1; start_idx <= i; --i)
            if (state->session.res[i].prime == -1)
            {   // Continue with a recursive-like approach to decompose non-prime factors.
                cint_dup(&state->session.num, &state->session.res[i].num);
                state->session.power = state->session.res[i].power;
                cint_erase(&state->session.res[i].num);
                if (end_idx == start_idx)
                    state->session.mem.now = state->session.res[i].num.mem;
                state->session.res[i].power = state->session.res[i].prime = 0;
                goto start;
            }
            else if (end_idx == start_idx && state->session.res[i].power)
                end_idx = 1 + i;
    }

    // Sort the results (they start with a cint) using the unsigned cint comparator.
    if (end_idx)
        qsort(state->session.res + start_idx, end_idx - start_idx,
              sizeof(*state->session.res), (int (*)(const void *,
                                            const void *)) h_cint_compare);

    // [MATH INSURANCE] Verify the correctness of all factorizations.
    // Exit code 0 will mean that the product of all factors is equal to the input number.
    cint *A = state->session.tmp, *B = A + 1, *PRODUCT_OF_FACTORS = A + 2,
          *INPUT_NUMBER = A + 9, *TMP;
    cint_reinit(PRODUCT_OF_FACTORS, 1);
    for (int i = 0; state->session.res[i].power; ++i)
    {   cint_reinit(B, state->session.res[i].power);
        cint_pow(state->session.sheet, &state->session.res[i].num, B, A);
        cint_mul(PRODUCT_OF_FACTORS, A, B), TMP = PRODUCT_OF_FACTORS,
                                            PRODUCT_OF_FACTORS = B, B = TMP;
    }

    if (cint_compare(INPUT_NUMBER, PRODUCT_OF_FACTORS) != 0)
    {   fprintf(stderr, "Input: %s\n", state->session.input_string);
        assert(!"[x] Maintenance points to a fatal mathematical error.");
    }

    // [MATH INSURANCE] Verify the completeness of all factorizations.
    // Exit code 0 will mean that the software has fully factored all numbers.
    int status = 0 ;
    for (int i = start_idx; state->session.res[i].power; ++i)
        state->code |= status |= !state->session.res[i].prime;

    state->session.duration_ms = get_time_ms() -
                                 state->session.duration_ms;
    return status ;
}

// Manager
int validate_input_file(state *state)
{   FILE *fp = state->in;
    while (!feof(fp))
    {   int c = fgetc(fp);
        if (!feof(fp) && (c == '+' || c == '-'))
            c = fgetc(fp);
        if (c >= '1' && c <= '9')
        {   size_t digits = 1;
            while (!feof(fp) && (c = fgetc(fp)) >= '0' && c <= '9')
                ++digits;
            ++state->scale.total_rows;
            if (state->scale.max_digits < digits)
                state->scale.max_digits = digits;
        }
        else if (c != '\n')
            while (!feof(fp) && fgetc(fp) != '\n');
    }
    fseek(fp, 0, SEEK_SET);
    return state->scale.max_digits != 0;
}

size_t prepare_file_descriptors(state *state)
{   if (state->params.output_file)
    {   state->out = fopen(state->params.output_file, "wb");
        if (!state->out)
            return perror("Factorization program output"), 0;
    }
    else
        state->out = stdout; // Standard output.

    if (state->params.input_file)
    {   state->in = fopen(state->params.input_file, "rb");
        if (!state->in)
        {   perror("Factorization program input");
            if (state->out != stdout)
                fclose(state->out);
            return 0;
        }
        else if (!validate_input_file(state))
        {   if (state->out != stdout)
                fclose(state->out);
            fclose(state->in);
            return 0;
        }
    }
    // Set a limit for numbers that are too large.
    if (state->scale.max_digits >> 13 && !state->params.force)
        return !fprintf(stderr,
                        "A number of %" PRIu64
                        " digits when \x1b[37;40;1moption -f\033[0m isn't set is too large for the %d limit.\n",
                        (uint64_t)state->scale.max_digits, 1 << 13);
    return state->scale.total_rows;
}

int validate_string_number(const char *s, state *state)
{   // Ensure that the string (number to factor) is well-formed, count the
    // total of submitted numbers, and note the size (decimal digits) of the largest.
    size_t digits;
    s += *s == '-' || *s == '+';
    if (*s >= '1' && *s <= '9' &&
        !s[digits = 1 + strspn(s + 1, "0123456789")])
    {   if (state->scale.max_digits < digits)
            state->scale.max_digits = digits;
        return ++state->scale.total_rows, 1;
    }
    return 0;
}

void output_csv(state *state, int has_prev, int has_next, int status)
{   if (has_prev == 0)
        fprintf(state->out, "Input,Factors%s\n",
                state->params.output_format == 'C' ? ",Duration (s),Status" : "");
    fprintf(state->out, "%s,", state->session.input_string);
    for (int i = 0, pow; (pow = state->session.res[i].power); ++i)
    {   const char *s = cint_to_string_buffer(&state->session.res[i].num,
                                              state->session.output_string, 10);
        for (int j = 0; j < pow; ++j)
            fprintf(state->out, !i && !j ? "%s" : ";%s", s);
    }
    if (state->params.output_format == 'C')
        fprintf(state->out, ",%.02f,%s",
                (double)state->session.duration_ms / 1000.0,
                status ? "Incomplete" : "Complete");
    fprintf(state->out, "\n");
}

void output_json(state *state, int has_prev, int has_next,
                 int status)
{   fprintf(state->out, has_prev ? "    {" : "[\n    {");
    fprintf(state->out,
            "\n        \"input\": \"%s\",\n        \"factors\": [",
            state->session.input_string);
    for (int i = 0, pow; (pow = state->session.res[i].power); ++i)
    {   const char *s = cint_to_string_buffer(&state->session.res[i].num,
                                              state->session.output_string, 10);
        const char *c = i ? "," : "",
                    *p = state->session.res[i].prime ? "true" : "false";
        fprintf(state->out,
                "%s\n            {\n                \"num\": \"%s\",\n                \"power\": %d,\n                \"prime\": %s\n            }",
                c, s, pow, p);
    }
    fprintf(state->out, "%s]", "\n        ");
    if (state->params.output_format == 'J')
        fprintf(state->out, ",\n        \"duration\": %" PRIu64
                ",\n        \"complete\": %s", state->session.duration_ms,
                status ? "false" : "true");
    fprintf(state->out, has_next ? "%s},\n" : "%s}\n]\n", "\n    ");
}

#ifdef ORIGINAL
void output_default(state *state, int has_prev, int has_next, int status)
{   fprintf(state->out, "Number: %s\nFactors: ",
            state->session.input_string);
    for (int i = 0, pow; (pow = state->session.res[i].power); ++i)
    {   const char *s = cint_to_string_buffer(&state->session.res[i].num,
                                              state->session.output_string, 10);
        const char *c = i ? ", " : "";
        if (pow == 1)
            fprintf(state->out, "%s%s (%s)", c, s,
                    state->session.res[i].prime ? "prime" : "not prime");
        else
            fprintf(state->out, "%s%s^%d", c, s, pow);
    }
    if (2 < state->params.verbose)
        fprintf(state->out, "\nStatus: %s factored in %.02f s",
                status ? "incompletely" : "fully",
                (double)state->session.duration_ms / 1000.0);
    fprintf(state->out, has_next ? "\n\n" : "\n");
}

#else // ORIGINAL

// This version is for use within CSL.

extern void string_to_csl(const char* s);

void output_default(state *state, int has_prev, int has_next, int status)
{   for (int i = 0, pow; (pow = state->session.res[i].power); ++i)
    {   const char *s = cint_to_string_buffer(&state->session.res[i].num,
                                              state->session.output_string, 10);
        for (int i=0; i<pow; i++) string_to_csl(s);
    }
    if (2 < state->params.verbose)
        fprintf(state->out, "\nStatus: %s factored in %.02f s",
                status ? "incompletely" : "fully",
                (double)state->session.duration_ms / 1000.0);
}

#endif // ORIGINAL

void output(state *state, int status)
{   const int has_prev = state->scale.row_idx != 0,
                  has_next = state->scale.row_idx + 1 != state->scale.total_rows;
    if (state->params.tty && state->params.verbose)
        display_progress(0, 100);
    switch (state->params.output_format)
    {   case 'c' : case 'C' : output_csv(state, has_prev, has_next,
                                             status); break;
        case 'J' : case 'j' : output_json(state, has_prev, has_next, status);
            break;
        default : output_default(state, has_prev, has_next, status); break;
    }
    ++state->scale.row_idx; // Update the index after each factorization.
    if (state->params.tty && state->params.verbose)
        display_progress("Overall Progress",
                         (double) state->scale.row_idx / (double) state->scale.total_rows *
                         100.0);
    fflush(state->out);
}

void prepare_sessions(state *state)
{   // Prepare a session containing enough memory to handle the largest (in terms of digits) number.
    state->scale.max_factors = 1;
    state->scale.max_bits = cint_approx_bits_from_digits(
                                state->scale.max_digits, 10);
    for (int i = 3, bits = (int) state->scale.max_bits; 0 < bits; i += 2)
        if (is_prime_4669913(i))
            for (int j = (++state->scale.max_factors, i); j >>= 1; --bits);
    state->session.output_string =
        (char*)malloc(state->scale.max_bits + 32 -
                      state->scale.max_bits % 16);
    assert(state->session.output_string); // String buffer to store any number represented in any base.
    const size_t bits = (2 + (state->scale.max_bits >> 4)) << 5;
    cint_init(&state->session.num, bits, 1); // The number to be factored.
    const size_t el_count = sizeof(state->session.tmp) / sizeof(
                                *state->session.tmp);
    const size_t el_size = state->session.num.size * sizeof(
                               *state->session.num.mem);
    cint *T = state->session.tmp;
    T[0].mem = T[0].end = (h_cint_t*)calloc(el_count, el_size);
    assert(T[0].mem); // Temporary variables.
    T[0].size = state->session.num.size;
    for (size_t i = 1; i < el_count; ++i)
        T[i].mem = T[i].end = T[i - 1].mem + (T[i].size = T[i - 1].size);
    state->session.sheet = cint_new_sheet(bits);
    assert(state->session.sheet); // A computation sheet.
    state->session.mem.base =
        (h_cint_t*)calloc(1, state->scale.max_factors *
                             (sizeof(*state->session.res) +
                             sizeof(*state->session.num.mem)) +
                             (el_size << 1));
    assert(state->session.mem.base);
    state->session.res = (Xstate::Xstate4::Xstate5*)state->session.mem.base;
    state->session.mem.now = state->session.res +
                             state->scale.max_factors;
}

void erase_session(state *state)
{   // Erase the session (clear variables, number, and results).
    for (size_t i = 0;
         i < sizeof(state->session.tmp) / sizeof(*state->session.tmp); ++i)
        if (state->session.tmp[i].mem != state->session.tmp[i].end)
            cint_erase(&state->session.tmp[i]);
    cint_erase(&state->session.num);
    memset(state->session.mem.base, 0,
           (char *) state->session.mem.now - (char *) state->session.mem.base);
    state->session.mem.now = state->session.res +
                             state->scale.max_factors;
}

void clear_sessions(state *state)
{   // Free all memory, close all descriptors.
    free(state->session.output_string);
    free(state->session.tmp[0].mem);
    free(state->session.num.mem);
    cint_clear_sheet(state->session.sheet);
    free(state->session.mem.base);
    if (state->in)
        fclose(state->in);
    if (state->out != stdout)
        fclose(state->out);
}

void process_single(state *state)
{   cint_reinit_by_string(&state->session.num,
                          state->session.input_string, 10);
    uint64_t seed = state->params.rand.seed ;
    state->session.seed = &seed
                          ; // Each number is factored with the seed.
    const int status = factor(state);
    output(state, status);
    state->duration_ms += state->session.duration_ms;
    if (state->scale.row_idx != state->scale.total_rows)
        erase_session(state); // Get ready for the next request.
}

void process_multi(int argc, const char **argv, state *state)
{   prepare_sessions(state);
    if (state->in)
    {   // Process request(s) incoming from a file.
        const size_t buf_size = state->scale.max_digits + 4096;
        char *s = (char*)malloc(buf_size);
        assert(s);
        state->session.input_string = s ;
        while (fgets(s, buf_size, state->in))
            if ((*s >= '1' && *s <= '9') || ((*s == '+' || *s == '-') &&
                                             *(s + 1) >= '1' && *(s + 1) <= '9'))
            {   s[strspn(s, "+-0123456789")] = 0;
                process_single(state);
            }
        free(s);
    }
    else
        // Process request(s) incoming from the command line.
        for (int i = 1; i < argc; ++i)
            if (argv[i])
            {   state->session.input_string = argv[i];
                process_single(state);
            }
    if (1 < state->params.verbose)
        fprintf(stderr, "\n%s result%s %s in %.02f s.\n",
                state->code ? "[x] Maintenance reports that the" : "The",
                state->scale.row_idx == 1 ? " is" : "s are",
                state->code ? "correct but lacks accuracy" :
                "completely accurate and verified",
                (double) state->duration_ms * 0.001) ;
    // Clear all memory used to process the requests.
    clear_sessions(state);
}
qs_md xor_random(qs_md *s)
{   // A shift-register generator has a reproducible behavior across platforms.
    return *s ^= *s << 13, *s ^= *s >> 7, *s ^= *s << 17 ;
}

qs_md xor_rand(qs_md *seed, qs_md min, qs_md max)
{   // Return a random number within the specified range.
    return min + xor_random(seed) % (max - min + 1);
}

int is_prime_4669913(const qs_sm n)
{   // Used to iterate through the first 326,983 prime numbers, up to 4,669,913 (the next one is not identified as prime).
    return ((n > 1) & ((n < 6) * 42 + 0x208A2882) >> n % 30 && (n < 49 ||
            (n % 7 && n % 11 && n % 13 && n % 17 && n % 19 && n % 23 && n % 29 &&
             (n < 961 || (n % 31 && n % 37 && n % 41 && n % 43 && n % 47 &&
                          n % 53 && n % 59 && n % 61 && n % 67 && (n < 5041 || (n % 71 &&
                                  n % 73 && n % 79 && n % 83 && n % 89 && n % 97 && n % 101 &&
                                  n % 103 && n % 107 && (n < 11881 || (n % 109 && n % 113 && n % 127 &&
                                          n % 131 && n % 137 && n % 139 && n % 149 && n % 151 && n % 157 &&
                                          (n < 26569 || (n % 163 && n % 167 && n % 173 && n % 179 && n % 181 &&
                                                  n % 191 && n % 193 && n % 197 && n % 199 && (n < 44521 || (n % 211 &&
                                                          n % 223 && n % 227 && n % 229 && n % 233 && n % 239 && n % 241 &&
                                                          n % 251 && n % 257 && (n < 69169 || (n % 263 && n % 269 && n % 271 &&
                                                                  n % 277 && n % 281 && n % 283 && n % 293 && n % 307 && n % 311 &&
                                                                  (n < 97969 || (n % 313 && n % 317 && n % 331 && n % 337 && n % 347 &&
                                                                          n % 349 && n % 353 && n % 359 && n % 367 && (n < 139129 || (n % 373 &&
                                                                                  n % 379 && n % 383 && n % 389 && n % 397 && n % 401 && n % 409 &&
                                                                                  n % 419 && n % 421 && (n < 185761 || (n % 431 && n % 433 && n % 439 &&
                                                                                          n % 443 && n % 449 && n % 457 && n % 461 && n % 463 && n % 467 &&
                                                                                          (n < 229441 || (n % 479 && n % 487 && n % 491 && n % 499 && n % 503 &&
                                                                                                  n % 509 && n % 521 && n % 523 && n % 541 && (n < 299209 || (n % 547 &&
                                                                                                          n % 557 && n % 563 && n % 569 && n % 571 && n % 577 && n % 587 &&
                                                                                                          n % 593 && n % 599 && (n < 361201 || (n % 601 && n % 607 && n % 613 &&
                                                                                                                  n % 617 && n % 619 && n % 631 && n % 641 && n % 643 && n % 647 &&
                                                                                                                  (n < 426409 || (n % 653 && n % 659 && n % 661 && n % 673 && n % 677 &&
                                                                                                                          n % 683 && n % 691 && n % 701 && n % 709 && (n < 516961 || (n % 719 &&
                                                                                                                                  n % 727 && n % 733 && n % 739 && n % 743 && n % 751 && n % 757 &&
                                                                                                                                  n % 761 && n % 769 && (n < 597529 || (n % 773 && n % 787 && n % 797 &&
                                                                                                                                          n % 809 && n % 811 && n % 821 && n % 823 && n % 827 && n % 829 &&
                                                                                                                                          (n < 703921 || (n % 839 && n % 853 && n % 857 && n % 859 && n % 863 &&
                                                                                                                                                  n % 877 && n % 881 && n % 883 && n % 887 && (n < 822649 || (n % 907 &&
                                                                                                                                                          n % 911 && n % 919 && n % 929 && n % 937 && n % 941 && n % 947 &&
                                                                                                                                                          n % 953 && n % 967 && (n < 942841 || (n % 971 && n % 977 && n % 983 &&
                                                                                                                                                                  n % 991 && n % 997 && n % 1009 && n % 1013 && n % 1019 && n % 1021 &&
                                                                                                                                                                  (n < 1062961 || (n % 1031 && n % 1033 && n % 1039 && n % 1049 &&
                                                                                                                                                                          n % 1051 && n % 1061 && n % 1063 && n % 1069 && n % 1087 &&
                                                                                                                                                                          (n < 1190281 || (n % 1091 && n % 1093 && n % 1097 && n % 1103 &&
                                                                                                                                                                                  n % 1109 && n % 1117 && n % 1123 && n % 1129 && n % 1151 &&
                                                                                                                                                                                  (n < 1329409 || (n % 1153 && n % 1163 && n % 1171 && n % 1181 &&
                                                                                                                                                                                          n % 1187 && n % 1193 && n % 1201 && n % 1213 && n % 1217 &&
                                                                                                                                                                                          (n < 1495729 || (n % 1223 && n % 1229 && n % 1231 && n % 1237 &&
                                                                                                                                                                                                  n % 1249 && n % 1259 && n % 1277 && n % 1279 && n % 1283 &&
                                                                                                                                                                                                  (n < 1661521 || (n % 1289 && n % 1291 && n % 1297 && n % 1301 &&
                                                                                                                                                                                                          n % 1303 && n % 1307 && n % 1319 && n % 1321 && n % 1327 &&
                                                                                                                                                                                                          (n < 1852321 || (n % 1361 && n % 1367 && n % 1373 && n % 1381 &&
                                                                                                                                                                                                                  n % 1399 && n % 1409 && n % 1423 && n % 1427 && n % 1429 &&
                                                                                                                                                                                                                  (n < 2053489 || (n % 1433 && n % 1439 && n % 1447 && n % 1451 &&
                                                                                                                                                                                                                          n % 1453 && n % 1459 && n % 1471 && n % 1481 && n % 1483 &&
                                                                                                                                                                                                                          (n < 2211169 || (n % 1487 && n % 1489 && n % 1493 && n % 1499 &&
                                                                                                                                                                                                                                  n % 1511 && n % 1523 && n % 1531 && n % 1543 && n % 1549 &&
                                                                                                                                                                                                                                  (n < 2411809 || (n % 1553 && n % 1559 && n % 1567 && n % 1571 &&
                                                                                                                                                                                                                                          n % 1579 && n % 1583 && n % 1597 && n % 1601 && n % 1607 &&
                                                                                                                                                                                                                                          (n < 2588881 || (n % 1609 && n % 1613 && n % 1619 && n % 1621 &&
                                                                                                                                                                                                                                                  n % 1627 && n % 1637 && n % 1657 && n % 1663 && n % 1667 &&
                                                                                                                                                                                                                                                  (n < 2785561 || (n % 1669 && n % 1693 && n % 1697 && n % 1699 &&
                                                                                                                                                                                                                                                          n % 1709 && n % 1721 && n % 1723 && n % 1733 && n % 1741 &&
                                                                                                                                                                                                                                                          (n < 3052009 || (n % 1747 && n % 1753 && n % 1759 && n % 1777 &&
                                                                                                                                                                                                                                                                  n % 1783 && n % 1787 && n % 1789 && n % 1801 && n % 1811 &&
                                                                                                                                                                                                                                                                  (n < 3323329 || (n % 1823 && n % 1831 && n % 1847 && n % 1861 &&
                                                                                                                                                                                                                                                                          n % 1867 && n % 1871 && n % 1873 && n % 1877 && n % 1879 &&
                                                                                                                                                                                                                                                                          (n < 3568321 || (n % 1889 && n % 1901 && n % 1907 && n % 1913 &&
                                                                                                                                                                                                                                                                                  n % 1931 && n % 1933 && n % 1949 && n % 1951 && n % 1973 &&
                                                                                                                                                                                                                                                                                  (n < 3916441 || (n % 1979 && n % 1987 && n % 1993 && n % 1997 &&
                                                                                                                                                                                                                                                                                          n % 1999 && n % 2003 && n % 2011 && n % 2017 && n % 2027 &&
                                                                                                                                                                                                                                                                                          (n < 4116841 || (n % 2029 && n % 2039 && n % 2053 && n % 2063 &&
                                                                                                                                                                                                                                                                                                  n % 2069 && n % 2081 && n % 2083 && n % 2087 && n % 2089 &&
                                                                                                                                                                                                                                                                                                  (n < 4405801 || (n % 2099 && n % 2111 && n % 2113 && n % 2129 &&
                                                                                                                                                                                                                                                                                                          n % 2131 && n % 2137 && n % 2141 && n % 2143 &&
                                                                                                                                                                                                                                                                                                          n % 2153)))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))));
}

double log_computation(const double n)
{   // Basic logarithm calculation, so <math.h> isn't needed.
    static const double euler_constant = 2.718281828459045;
    unsigned a = 0, d;
    double b, c, e, f;
    if (n > 0)
    {   for (c = n < 1 ? 1 / n : n;
             (c /= euler_constant) > 1;
             ++a) (void)nullptr;
        c = 1 / (c * euler_constant - 1),
        c = c + c + 1,
        f = c * c, b = 0;
        for (d = 1, c /= 2;
             e = b, b += 1 / (d * c), b - e > 0.00001
             ;)
        {   d += 2, c *= f;
        }
    }
    else b = (n == 0) / 0.;
    return n < 1 ? -(a + b) : a + b;
}

qs_sm multiplication_modulo(qs_md a, qs_md b, const qs_sm mod)
{   if (a < 0x100000000 && b < 0x100000000)
        return a * b % mod ;
// the implementation is designed for beginners, so there aren't many preprocessing "tricks".
#ifdef __SIZEOF_INT128__
    return (qs_sm) ((__int128_t) a * (__int128_t) b % (__int128_t) mod);
#else
    // Return (a * b) % mod, avoiding overflow errors while doing modular multiplication.
    qs_md res = 0, tmp;
    for (b %= mod; a;
         a & 1 ? b >= mod - res ? res -= mod : 0, res += b : 0, a >>= 1,
         (tmp = b) >= mod - b ? tmp -= mod : 0, b += tmp);
    return (qs_sm)(res % mod);
#endif
}

qs_sm power_modulo(qs_md n, qs_md exp, const qs_sm mod)
{   // Return (n ^ exp) % mod
    qs_sm res = 1;
    for (n %= mod; exp;
         exp & 1 ? res = multiplication_modulo(res, n, mod) : 0,
         n = multiplication_modulo(n, n, mod), exp >>= 1);
    return res;
}

int kronecker_symbol(qs_sm a, qs_sm b)
{   static const int s[8] = {0, 1, 0, -1, 0, -1, 0, 1};
    qs_sm c;
    int res = (int) (a | b);
    if (a && b)
        if (res & 1)
        {   for (c = 0; !(b & 1); ++c, b >>= 1) (void)nullptr;
            // When B is odd Jacobi and Kronecker symbols are identical, in factorization algorithms B is often the prime number.
            // When B is an odd prime number, Jacobi symbol is equal to the Legendre symbol.
            for (res = c & 1 ? s[a & 7] : 1; a;
                 c & 1 ? res *= s[b & 7] : 0, a & b & 2 ? res = -res : 0, c = b % a,
                 b = a, a = c)
                for (c = 0; !(a & 1); ++c, a >>= 1) (void)nullptr;
            res = b == 1 ? res : 0;
        }
        else res = 0;
    else res = res == 1;
    return res;
}

qs_sm tonelli_shanks(const qs_sm n, const qs_sm mod)
{   // return root such that (root * root) % mod congruent to n % mod.
    // return 0 if no solution to the congruence exists.
    // mod is assumed odd prime, if mod = 2 then res is (n & 7 == 1 || n & 7 == 7).
    const qs_sm a = (qs_sm) (n % mod);
    qs_sm res = kronecker_symbol(a, mod) == 1, b, c, d, e, f, g, h;
    if (res)
        switch (mod & 7)
        {   case 3 :
            case 7 :
                res = power_modulo(a, (mod + 1) >> 2, mod);
                break;
            case 5 :
                res = power_modulo(a, (mod + 3) >> 3, mod);
                if (multiplication_modulo(res, res, mod) != a)
                {   b = power_modulo(2, (mod - 1) >> 2, mod);
                    res = multiplication_modulo(res, b, mod);
                }
                break;
            default :
                if (a == 1)
                    res = 1;
                else
                {   for (c = mod - 1, d = 2;
                         d < mod && power_modulo(d, c >> 1, mod) != c;
                         ++d) (void)nullptr;
                    for (e = 0; !(c & 1); ++e, c >>= 1);
                    f = power_modulo(a, c, mod);
                    b = power_modulo(d, c, mod);
                    for (h = 0, g = 0; h < e; h++)
                    {   d = power_modulo(b, g, mod);
                        d = multiplication_modulo(d, f, mod);
                        d = power_modulo(d, 1 << (e - h - 1), mod);
                        if (d == mod - 1)
                            g += 1 << h;
                    }
                    f = power_modulo(a, (c + 1) >> 1, mod);
                    b = power_modulo(b, g >> 1, mod);
                    res = multiplication_modulo(f, b, mod);
                }
        }
    return res;
}

qs_sm modular_inverse(qs_sm ra, qs_sm rb)
{   // Return a modular multiplicative inverse of N with respect to the modulus.
    // Return 0 if the linear congruence has no solutions.
    // The answer is also called "u1" in the context of extended Euclidean algorithm.
    qs_sm rc, sa = 1, sb = 0, sc, i = 0;
    if (rb > 1)
        do
        {   rc = ra % rb;
            sc = sa - (ra / rb) * sb;
            sa = sb, sb = sc;
            ra = rb, rb = rc;
        }
        while (++i, rc);
    sa *= (i *= ra == 1) != 0;
    sa += (i & 1) * sb;
    return sa;
}
// 64-bit integer factorization algorithm released "as it" into the public domain, without any warranty, express or implied.

// The "worker" algorithm uses the Pollard Rho method when trial division isn't enough
// to fully factor the number, and Miller-Rabin identifies that the number is not prime.

int bit_size(u64 n)
{   int size = n != 0;
    while (n >>= 1)
        ++size;
    return size;
}

u64 mul_mod(u64 a, u64 b, const u64 mod)
{   u64 res = 0,
            c; // return (a * b) % mod, avoiding overflow errors while doing modular multiplication.
    for (b %= mod; a;
         a & 1 ? b >= mod - res ? res -= mod : 0, res += b : 0, a >>= 1,
         (c = b) >= mod - b ? c -= mod : 0, b += c);
    return res % mod;
}

u64 pow_mod(u64 n, u64 exp, const u64 mod)
{   u64 res = 1; // return (n ^ exp) % mod.
    for (n %= mod; exp;
         exp & 1 ? res = mul_mod(res, n, mod) : 0, n = mul_mod(n, n, mod),
         exp >>= 1);
    return res;
}

int is_prime_64_bits(u64 n)
{   // Perform a Miller-Rabin test, it should be a deterministic version.
    static const u64 bases[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37};
    static const int n_bases = (int) sizeof(*bases);
    for (int i = 0; i < n_bases; ++i)
        if (n % bases[i] == 0)
            return n == bases[i];
    if (n < bases[n_bases - 1] * bases[n_bases - 1])
        return 1 < n;
    // Depending on the size of the number, we don't need to test all the bases.
    const int lim = n < 2152302898747 ? n < 25326001 ? n < 2047 ? 1 : n <
                    1373653 ? 2 : 3 : n < 3215031751 ? 4 : 5 : n < 341550071728321 ? n <
                    3474749660383 ? 6 : 7 : n < 3825123056546413051 ? 9 : 12;
    int res = 1, a = 0;
    u64 b, c;
    for (b = n - 1; ~b & 1; b >>= 1, ++a);
    for (int i = 0; i < lim && res; ++i)
        if (c = pow_mod(bases[i], b, n), c != 1)
        {   for (int d = a; d-- && (res = c + 1 != n);)
                c = mul_mod(c, c, n);
            res = !res;
        }
    return res;
}

u64 pollard_rho(const u64 n, uint64_t *seed)
{   // Factorize N using the given seed to explore different sequences.
    u64 divisor = 1, a, b, c, i = 0, j = 1, x = 1, y = xor_rand(seed, 1,
                                         n - 1);
    for (; divisor == 1; ++i)
    {   if (i == j)
        {   if (j >>
                18) // Adjust the timeout with (j >> 18) for 20 ms .......... (j >> 17) for 10 ms.
                break;
            j <<= 1;
            x = y;
        }
        a = y, b = y;
        for (y = 0; a;
             a & 1 ? b >= n - y ? y -= n : 0, y += b : 0, a >>= 1,
             (c = b) >= n - b ? c -= n : 0, b += c);
        y = (1 + y) % n;
        for (a = x < y ? y - x : x - y, b = n; (a %= b) && (b %= a););
        divisor = a | b;
    }
    return divisor;
}

u64 nth_root(const u64 n, const u64 nth)
{   // Use an iterative approach for finding the nth-roots.
    u64 a = n, b, c, r = nth ? n + (n > 1) : n == 1 ;
    for (; a < r; b = a + (nth - 1) * r, a = b / nth)
        for (r = a, a = n, c = nth - 1; c && (a /= r); --c);
    return r;
}

u64 square_extraction(u64 *n, int *pow)
{   u64 root = 1;
    if (3 < *n)
        while (root = nth_root(*n, 2), *n == root * root)
            *n = root, *pow <<= 1;
    return 65522U * 65522U < *n ? 65522U : root + 1;
}

void fac_64_worker(state *state, u64 n, fac64_row *rows)
{   if (3 < n)
    {   int pow = 1;
        if (~n & 1)
        {   // Powers of two are removed.
            *rows = (fac64_row)
            {   2, 0
            };
            do
            {   ++(*rows).power;
                n >>= 1;
            }
            while (~n & 1);
            ++rows;
        }
        if (8 < n)
        {   // The number is odd.
            u64 limit = square_extraction(&n, &pow);
            // Ensure the number has no 16-bit factor by trial division.
            for (u64 prime = 3; prime < limit; prime += 2)
                if (n % prime == 0)
                {   int p = 0;
                    do ++p, n /= prime;
                    while (n % prime == 0);
                    *rows++ = (fac64_row)
                    {   prime, p * pow
                    };
                    limit = square_extraction(&n, &pow);
                }
            if (n >> 32)
            {   int i = 0, j = 0;
                fac64_row tasks[8]; // Stack-based approach for the remainder (greater than 16-bit).
                tasks[i++] = (fac64_row)
                {   n, pow
                };
                do
                {   u64 x;
                    n = tasks[--i].prime;
                    pow = tasks[i].power;
                    if (n == 1)
                        continue;
                    if (!(n >> 32) || is_prime_64_bits(n))
                    {   for (int k = !(x = 1); k < i; ++k)
                            while (tasks[k].prime % n == 0)
                                tasks[k].prime /= n, x += tasks[k].power;
                        *rows++ = (fac64_row)
                        {   n, (int) x * pow
                        };
                    }
                    else if (x = nth_root(n, 2), n == x * x)
                    {   debug_print(state, 4,
                                    "- %" PRIu64 " is the square of %" PRIu64 ".\n", n, x);
                        tasks[i++] = (fac64_row)
                        {   x, 2 * pow
                        };
                    }
                    else if (x = nth_root(n, 3), n == x * x * x)
                    {   debug_print(state, 4,
                                    "- %" PRIu64 " is the cube of %" PRIu64 ".\n", n, x);
                        tasks[i++] = (fac64_row)
                        {   x, 3 * pow
                        };
                    }
                    else
                    {   debug_print(state, 4,
                                    "%sPollard's Rho on %" PRIu64 " (%d-bit).\n",
                                    ++j == 1 ? "" : "- Recursively applying ", n, bit_size(n));
                        while (x = pollard_rho(n, state->session.seed), x == 1 || x == n);
                        tasks[i++] = (fac64_row)
                        {   x * x < n ? x : n / x, pow
                        };
                        tasks[i++] = (fac64_row)
                        {   x * x < n ? n / x : x, pow
                        };
                    }
                }
                while (i);
            }
            else if(n != 1)
                *rows++ = (fac64_row)
            {   n, pow
            };
        }
        else
            *rows++ = (fac64_row)
        {   n, 1
        };
    }
    else if (n)
        *rows++ = (fac64_row)
    {   n, 1
    };
    *rows = (fac64_row)
    {   0
    };
}
//  Enjoy the Classic Self-Initializing Quadratic Sieve (SIQS) written in C,
//  released "as it" into the public domain, without any warranty, express or implied.

int factorization_quadratic_sieve(state * state, int bits)
{   // The state contains a number N from the factorization manager and the Quadratic Sieve must :
    // - use resources present in the state (temporary variables + parameters)
    // - register prime (as possible) factors of N using the state
    // - maintain the value of N consistent with the removed factors
    // - return a non-zero value if the factorization has progressed

    if (bits < 65 || (DEFAULT_BIT_LIMIT_QS < bits &&
                      !state->params.force))
        return 0; // For every additional 10 bits, the factorization duration roughly doubles.

    // In 2025 on Michel Leonardb s test machine : 260 bits took 12 minutes, 270-bit took 24 minutes, 310-bit took 5 hours.

    qs_sheet qs = {0};
    preparation_part_1(&qs, state, bits);
    preparation_part_2(&qs);
    preparation_part_3(&qs);
    qs_parametrize(&qs);
    preparation_part_4(&qs);
    preparation_part_5(&qs);
    preparation_part_6(&qs);
    do
    {   do
        {   // Keep randomly trying various polynomials.
            get_started_iteration(&qs);
            iteration_part_1(&qs, &qs.poly.D, &qs.poly.A);
            iteration_part_2(&qs, &qs.poly.A, &qs.poly.B);
            iteration_part_3(&qs, &qs.poly.A, &qs.poly.B);
            for (qs_sm i = 0, addi, *corr; i < qs.poly.gray_max &&
                 qs.n_bits != 1; ++i, ++qs.poly.curves)
            {   addi = iteration_part_4(&qs, i, &corr, &qs.poly.B);
                iteration_part_5(&qs, &qs.constants.kN, &qs.poly.B);
                iteration_part_6(&qs, &qs.constants.kN, &qs.poly.A, &qs.poly.B,
                                 &qs.poly.C);
                iteration_part_7(&qs, addi, corr);
                iteration_part_8(&qs, addi, corr);
                register_relations(&qs, &qs.poly.A, &qs.poly.B, &qs.poly.C);
            }
        }
        while (inner_continuation_condition(&qs));
        // Analyzes all observations made by the algorithm.
        finalization_part_1(&qs, block_lanczos(&qs));
    }
    while (outer_continuation_condition(&qs));
    const int res = finalization_part_2(&qs);
    free(qs.mem.base);
    return res;
}

// Quadratic sieve main condition 1 (often) :
// - Returns 1 : to produce more polynomials and relations.
// - Returns 0 : to start linear algebra with Block Lanczos.
int inner_continuation_condition(qs_sheet *qs)
{   int answer = 1 ;
    if ((qs->time.end || 2 < qs->qs_state->params.verbose) &&
        qs->time.tick % 16 == 1)
        qs->time.now = get_time_ms();
    answer &= qs->n_bits != 1 ; // the bit count of N may have changed.
    answer &= (qs->relations.length.peak = qs->relations.length.now) <
              qs->relations.length.needs; // the condition.
    answer &= !qs->time.end || qs->time.tick % 16 == 1 ||
              qs->time.now < qs->time.end ;
    answer &= qs->time.tick != qs->qs_state->params.qs_tick_end ;
    const double pct = .01 * (10000 * qs->relations.length.now /
                              qs->relations.length.needs) ;
    if (pct != qs->time.prev_pct)
    {   if (qs->qs_state->params.tty && qs->qs_state->params.verbose)
            display_progress("Quadratic Sieve", pct); // progress isn't linear.
        else if (DEFAULT_BIT_LIMIT_QS < qs->n_bits &&
                 (qs_sm)qs->time.prev_pct != (qs_sm)pct)
            DEBUG_LEVEL_4("%s", answer && !(qs->time.prev_pct < 50. &&
                                            50. <= pct) ? "." : ".\n");
        qs->time.prev_pct = pct;
    }
    return answer;
}

// Quadratic sieve main condition 2. Block Lanczos linear algebra has been completed :
// - Returns 1 : to get a new attempt at linear algebra with more relations.
// - Returns 0 : when N = 1 (meaning it is fully factored) or to give up.
int outer_continuation_condition(qs_sheet *qs)
{   int answer = 1 ;
    answer &= qs->n_bits != 1 ; // the bit count of N isn't 1.
    answer &= qs->sieve_again_perms-- != 0 ; // avoid infinite loop.
    answer &= qs->divisors.total_primes == 0 ; // search prime factors.
    answer &= !qs->time.end || get_time_ms() < qs->time.end ;
    answer &= qs->time.tick != qs->qs_state->params.qs_tick_end ;
    if (answer)
    {   qs_sm new_needs = qs->relations.length.needs;
        new_needs += new_needs >> (2 + qs->sieve_again_perms);
        DEBUG_LEVEL_3("[x] Maintenance re-evaluates the needs for %u additional relations.\n",
                      new_needs - qs->relations.length.needs);
        qs->relations.length.needs = new_needs ;
    }
    return answer;
}

void qs_parametrize(qs_sheet *qs)
{

    const qs_sm bits = qs->kn_bits; // N adjusted has at least 115-bit.
    qs->kn_bits = (qs_sm) cint_count_bits(
                      qs->qs_state->session.tmp); // kN may be slight larger.

    DEBUG_LEVEL_4("N is a %u-bit number, and kN is a %u-bit number using %u words.\n",
                  (qs_sm) cint_count_bits(&qs->qs_state->session.num), qs->kn_bits,
                  (unsigned)(qs->qs_state->session.tmp->end -
                             qs->qs_state->session.tmp->mem));

    qs_md tmp ;
    // params as { bits, value } take the extremal value if bits exceed.
    static const double param_base_size [][2]= { {135, 1300}, {165, 4200}, {200, 10000}, {260, 20000}, {330, 55000}, {0} };
    qs->base.length = (tmp = qs->qs_state->params.qs_base_size) ? tmp :
                      linear_param_resolution(param_base_size, bits);

    static const double param_laziness [][2]= {{150, 95}, {220, 100}, {0} };
    // collecting more/fewer relations than recommended (in percentage).
    qs->relations.length.needs = qs->base.length * ((
                                     tmp = qs->qs_state->params.qs_laziness) ? tmp : linear_param_resolution(
                                     param_laziness, bits)) / 100;
    DEBUG_LEVEL_4("The algorithm use the seed %" PRIu64
                  " and targets %u relations.\n", qs->qs_state->params.rand.custom,
                  qs->relations.length.needs);

    static const double param_m_value [][2]= { {120, 1}, {330, 6}, {0} };
    qs->m.length = (qs->m.length_half = (qs->qs_state->params.qs_sieve ?
                                         qs->qs_state->params.qs_sieve : 31744) * linear_param_resolution(
                                            param_m_value, bits)) << 1;

    qs->m.cache_size = 95232
                       ; // algorithm reaches "M length" by steps of "cache size".

    static const double param_error [][2]= { {120, 15}, {330, 35}, {0} };
    // Logarithms of primes are rounded and errors accumulate; this specifies the magnitude of the error.
    qs->error_bits = (tmp = qs->qs_state->params.qs_error_bits) ? tmp :
                     linear_param_resolution(param_error, bits);

    static const double param_threshold [][2]= { {120, 60}, {330, 110}, {0} };
    // The threshold that the sieve value must exceed to be considered smooth.
    qs->threshold.value = (tmp = qs->qs_state->params.qs_threshold) ? tmp :
                          linear_param_resolution(param_threshold, bits);

    // A good multiplier reduces memory usage up to twice.
    static const double param_alloc [][2]= { {130, 992}, {140, 1280}, {150, 2176}, {160, 3584}, {170, 7168}, {180, 12288}, {190, 14336}, {190, 14336}, {200, 24576}, {210, 30720}, {220, 40960}, {230, 49152}, {240, 57344}, {250, 67584}, {260, 81920}, {270, 98304}, {280, 114688}, {290, 122880}, {300, 139264}, {310, 163840}, {320, 196608}, {330, 229376}, {0} };
    qs->mem.bytes_allocated = (tmp = qs->qs_state->params.qs_alloc_mb) ? tmp
                              << 20 : linear_param_resolution(param_alloc, qs->kn_bits) << 10;

    qs->sieve_again_perms =
        3; // Sieve again up to 3 times before giving up

    // Iterative list
    qs->iterative_list[0] = 1; // one
    static const double param_first_prime [][2] = { {170, 8}, {210, 12}, {320, 40}, {0} };
    qs->iterative_list[1] = linear_param_resolution(param_first_prime,
                            bits); // first
    tmp = qs->qs_state->params.qs_sieve_cutoff ?
          qs->qs_state->params.qs_sieve_cutoff : 5120 ;
    const qs_sm large_base = tmp < qs->base.length ? tmp :
                             qs->base.length;
    qs->iterative_list[2] = large_base >> 2; // medium
    qs->iterative_list[3] = large_base >> 1; // mid
    qs->iterative_list[4] = large_base; // sec

    DEBUG_LEVEL_4("The iterative list contains %u, %u, %u and %u.\n",
                  qs->iterative_list[1], qs->iterative_list[2], qs->iterative_list[3],
                  qs->iterative_list[4]);

    const qs_md last_prime_in_base = (qs_md) (qs->base.length * 2.5 *
                                     log_computation(qs->base.length));
    qs->relations.too_large_prime = (tmp =
                                         qs->qs_state->params.qs_large_prime) ? tmp : last_prime_in_base << 4;

    if (155 < qs->kn_bits)
        DEBUG_LEVEL_4("The single large-prime variation is being processed under %"
                      PRIu64 ".\n", qs->relations.too_large_prime);

    qs->s.values.double_value = (qs->s.values.defined =
                                     (qs->s.values.subtract_one = bits / 28) + 1) << 1;
    qs->poly.gray_max = 1 << (qs->s.values.defined -
                              3); // computing the roots of f(x) once for all these polynomials.

    DEBUG_LEVEL_4("Other params include sieve=%u, error_bits=%u, threshold=%u and s=%u.\n",
                  qs->m.length_half, qs->error_bits, qs->threshold.value,
                  qs->s.values.defined);

    // The algorithm itself completes its configuration during the last preparation part.
    assert(qs->s.values.defined >= 3);

}

// Quadratic sieve utility function for parameter extrapolation.
qs_sm linear_param_resolution(const double v[][2], const qs_sm point)
{   qs_sm res, i, j ;
    if (v[1][0] == 0)
        res = (qs_sm) v[0][1];
    else
    {   for (j = 1; v[j + 1][0] && point > v[j][0]; ++j) (void)nullptr;
        i = j - 1;
        if (v[i][0] > point) res = (qs_sm) v[i][1];
        else if (v[j][0] < point) res = (qs_sm) v[j][1];
        else
        {   const double a = (v[j][1] - v[i][1]) / (v[j][0] - v[i][0]);
            const double b = v[i][1] - a * v[i][0];
            res = (qs_sm) (a * point + b);
        }
    }
    return res + (res > 512) * (16 - res % 16) ;
}

// Quadratic sieve source (algorithm)
void preparation_part_1(qs_sheet *qs, state *state, int bits)
{   // initializing (until kN is computed) with manager resources.
    qs->qs_state = state;
    DEBUG_LEVEL_4("\nQuadratic Sieve on %s.\n", simple_cint_string(state,
                  &state->session.num));
    qs->sheet = state->session.sheet;
    qs->seed = state->session.seed;
    qs->n_bits = qs->kn_bits = bits;
    if (2 < state->params.verbose || state->params.timeout)
    {   qs->time.start = get_time_ms() ;
        if (state->params.timeout)
            qs->time.end = qs->time.start + 1000 * qs->qs_state->params.timeout;
    }
}

void preparation_part_2(qs_sheet *qs)
{   // The algorithm is suitable for numbers larger than 115-bit,
    // and may adjust kN by a prime number to reach this size.
    cint * N = &qs->qs_state->session.num, * kN = qs->qs_state->session.tmp,
           *ADJUSTOR = kN + 1 ;
    static const unsigned char prime_generator[] =
    {   9, 7, 5, 3, 17, 27, 3, 1, 29, 3, 21, 7, 17, 15,
        9, 43, 35, 15, 29, 3, 11, 3, 11, 15, 17, 25, 53,
        31, 9, 7, 23, 15, 27, 15, 29, 7, 59, 15, 5, 21,
        69, 55, 21, 21, 5, 159, 3, 81, 9, 69, 131, 33, 15
    };
    const qs_sm bits = (qs_sm) qs->n_bits;
    if (bits < 115)
    {   qs->adjustor = (1LLU << (124 - bits)) + prime_generator[115 -
                           bits] ;
        simple_int_to_cint(ADJUSTOR, qs->adjustor);
        cint_mul(N, ADJUSTOR, kN);
        qs->kn_bits = (qs_sm) cint_count_bits(kN);
        DEBUG_LEVEL_4("Input (%u bits) is multiplied by %" PRIu64
                      " to reach %u bits.\n", bits, qs->adjustor, qs->kn_bits);
    }
    else
        qs->adjustor = 1, cint_dup(kN, N);
}

void preparation_part_3(qs_sheet *qs)
{   // Frequently select a small multiplier (under 8-bit) that will save time and memory.
    // After it, the algorithm will factor kN instead of N, where k is a constant named "multiplier".
    const qs_sm mul = (qs_sm) qs->qs_state->params.qs_multiplier ;
    if (mul)
    {   DEBUG_LEVEL_4("The multiplier is %u.\n", mul);
        qs->multiplier = mul ;
    }
    else
    {   const size_t total_best = 7;
        qs_sm best[total_best];
        for (int i = qs->qs_state->params.verbose < 2; i < 2; ++i)
        {   if (i)
                preparation_part_3_default_proposition(qs, best, total_best);
            else
                preparation_part_3_alternative_proposition(qs, best, total_best);
            DEBUG_LEVEL_4("%s", "Suggested multipliers are [");
            for (size_t j = 0; j < total_best - 1; ++j)
                DEBUG_LEVEL_4("%u, ", best[j]);
            DEBUG_LEVEL_4("%u]%s", best[total_best - 1], i ? "" : ".\n");
        }
        qs->multiplier = *best;
        DEBUG_LEVEL_4(", so use %u.\n", *best);
    }
    if (1 < qs->multiplier)
    {   cint *kN = qs->qs_state->session.tmp, *MUL = kN + 1, *N = kN + 2 ;
        simple_int_to_cint(MUL, qs->multiplier);
        cint_dup(N, kN);
        cint_mul(MUL, N, kN);
    }
}

void preparation_part_3_default_proposition(qs_sheet *qs,
        qs_sm *caller_res, const size_t caller_res_len)
{   // Choose a multiplier that make the input more favorable for smoothness
    // over the future factor base, and lead to faster relation gathering.
    struct
    {   qs_sm mul;
        double score;
    } res[128] ; // 127 is the greatest multiplier.

    cint *N = qs->qs_state->session.tmp, *PRIME = N + 1, *Q = N + 2,
          *R = N + 3;
    const double log_2 = 0.6931471805599453;
    const size_t len = sizeof(res) / sizeof(*res) - 1;
    for (qs_sm i = 0; i < len ; ++i)
    {   res[i].mul = i + 1;
        res[i].score = -0.5 * log_computation(res[i].mul);
        switch (*N->mem * res[i].mul % 8)
        {   // Special case against 2, the first prime number.
            case 3 : case 7 : res[i].score += 0.5 * log_2; break;
            case 5 : res[i].score += 1.0 * log_2; break;
            case 1 : res[i].score += 3.0 * log_2; break;
        }
    }

    const int limit = qs->n_bits * qs->n_bits >> 5 ;
    for (qs_sm prime = 3; prime < (qs_sm)limit; prime += 2)
        if (is_prime_4669913(prime))
        {   // Normal case against the odd primes.
            simple_int_to_cint(PRIME, prime);
            cint_div(qs->sheet, N, PRIME, Q, R);
            const qs_sm n_mod_prime = (qs_sm) simple_cint_to_int(R);
            const double intake = 2.0 / (prime - 1) * log_computation(prime);
            const int kronecker = kronecker_symbol(n_mod_prime, prime);
            for (qs_sm i = 0; i < len; ++i)
                if (kronecker * kronecker_symbol(res[i].mul, prime) == 1)
                    res[i].score += intake;
        }

    // Sort the results.
    for (int i = 0; i < (int)len; ++i)
        for (int j = 1 + i; j < (int)len; ++j)
            if (res[i].score < res[j].score)
                res[len] = res[i], res[i] = res[j], res[j] = res[len];

    for(int i = 0; i < (int)caller_res_len; ++i)
        caller_res[i] = res[i].mul ;
}

void preparation_part_3_alternative_proposition(qs_sheet *qs,
        qs_sm *caller_res, const size_t caller_res_len)
{   // Choose a multiplier that make the input more favorable for smoothness
    // over the future factor base, and lead to faster relation gathering.
    struct
    {   qs_sm mul;
        double score;
    } res[] = {{1, 0}, {2, 0}, {3, 0}, {5, 0}, {6, 0}, {7, 0}, {10, 0}, {11, 0}, {13, 0}, {14, 0}, {15, 0}, {17, 0}, {19, 0}, {21, 0}, {22, 0}, {23, 0}, {26, 0}, {29, 0}, {30, 0}, {31, 0}, {33, 0}, {34, 0}, {35, 0}, {37, 0}, {38, 0}, {39, 0}, {41, 0}, {42, 0}, {43, 0}, {46, 0}, {47, 0}, {51, 0}, {53, 0}, {55, 0}, {57, 0}, {58, 0}, {59, 0}, {61, 0}, {62, 0}, {65, 0}, {66, 0}, {67, 0}, {69, 0}, {70, 0}, {71, 0}, {73, 0}, {79, 0}, {83, 0}, {89, 0}, {97, 0}, {101, 0}, {103, 0}, {107, 0}, {109, 0}, {0, 0}};

    cint *N = qs->qs_state->session.tmp, *TMP = N + 1, *Q = N + 2,
          *R = N + 3;
    const double log_2 = 0.6931471805599453;
    const size_t len = sizeof(res) / sizeof(*res) - 1;
    for (qs_sm i = 0; i < len; ++i)
    {   res[i].score = -0.5 * log_computation(res[i].mul);
        switch (*N->mem * res[i].mul % 8)
        {   // Special case against 2, the first prime number.
            case 3 : case 7 : res[i].score += 0.5 * log_2; break;
            case 5 : res[i].score += 1.0 * log_2; break;
            case 1 : res[i].score += 3.0 * log_2; break;
        }
    }

    for (qs_sm prime = 3; prime < 504; prime += 2)
        if (is_prime_4669913(prime))
        {   // Normal case against the odd primes.
            simple_int_to_cint(TMP, prime);
            cint_div(qs->sheet, N, TMP, Q, R);
            const qs_sm n_mod_prime = (qs_sm) simple_cint_to_int(R);
            const double intake = log_computation(prime) / (prime - 1);
            for (qs_sm i = 0; i < len; ++i)
            {   const qs_sm kn_mod_prime = n_mod_prime * res[i].mul % prime;
                if (kn_mod_prime == 0)
                    res[i].score += intake;
                else if (kronecker_symbol(kn_mod_prime, prime) == 1)
                    res[i].score += 2.0 * intake;
            }
        }

    // Sort the results.
    for (int i = 0; i < (int)len; ++i)
        for (int j = 1 + i; j < (int)len; ++j)
            if (res[i].score < res[j].score)
                res[len] = res[i], res[i] = res[j], res[j] = res[len];

    for(int i = 0; i < (int)caller_res_len; ++i)
        caller_res[i] = res[i].mul ;
}

void preparation_part_4(qs_sheet *qs)
{   void *mem;
    mem = qs->mem.base = (h_cint_t*)calloc(1, qs->mem.bytes_allocated);
    assert(mem);

    // kN has been prepared in the manager memory, now the QS has been parameterized and allocated.
    const size_t kn_size = qs->qs_state->session.tmp[0].end -
                           qs->qs_state->session.tmp[0].mem + 1 ;
    // the Quadratic Sieve variables can store at most kN ^ 2 in terms of bits
    const size_t vars_size = kn_size << 1 ;

    DEBUG_LEVEL_4("The underlying calculations use %u-bit variables.\n",
                  (unsigned)(vars_size * cint_exponent));

    const size_t buffers_size = qs->base.length + (qs->iterative_list[1]
                                << 1);
    // more relation pointers than "guessed" are available (sieve again feature).
    const size_t relations_size = (qs->base.length <
                                   qs->relations.length.needs ? qs->relations.length.needs :
                                   qs->base.length) * 7 / 4 ;

    {   // list of the numbers used by the algorithm
        cint * const n[] =
        {   &qs->vars.N,
            // polynomial
            &qs->poly.A,
            &qs->poly.B,
            &qs->poly.C,
            &qs->poly.D,
            // temporary
            &qs->vars.TEMP[0],
            &qs->vars.TEMP[1],
            &qs->vars.TEMP[2],
            &qs->vars.TEMP[3],
            &qs->vars.TEMP[4],
            // relations finder
            &qs->vars.X,
            &qs->vars.KEY,
            &qs->vars.VALUE,
            &qs->vars.CYCLE,
            // a factor of N
            &qs->vars.FACTOR,
            // constants
            &qs->constants.kN,
            &qs->constants.ONE,
            &qs->constants.M_HALF,
            &qs->constants.TOO_LARGE_PRIME,
            &qs->constants.MULTIPLIER,
            0,
        };
        for (int i = 0; n[i]; ++i)
        {   n[i]->mem = n[i]->end = (h_cint_t*)mem_aligned(mem) ;
            mem = n[i]->mem + (n[i]->size = vars_size);
        }
    }

    cint_dup(&qs->vars.N, &qs->qs_state->session.num);
    cint_dup(&qs->constants.kN, qs->qs_state->session.tmp);

    simple_int_to_cint(&qs->constants.ONE, 1);
    simple_int_to_cint(&qs->constants.M_HALF, qs->m.length_half);
    simple_int_to_cint(&qs->constants.TOO_LARGE_PRIME,
                       qs->relations.too_large_prime);
    simple_int_to_cint(&qs->constants.MULTIPLIER, qs->multiplier);

    // Allocates "s" rows
    qs->s.data = (XSheet::XSheet11::XSheet12*)mem_aligned(mem);
    mem = mem_aligned(qs->s.data + qs->s.values.defined);
    for (qs_sm i = 0; i < qs->s.values.defined; ++i)
    {   simple_inline_cint(&qs->s.data[i].B_terms, kn_size,
                           &mem); // also "s" more cint
        qs->s.data[i].A_inv_double_value_B_terms = (qs_sm*)mem;
        mem = mem_aligned(qs->s.data[i].A_inv_double_value_B_terms +
                          qs->base.length);
    }
    qs->s.A_indexes = // the indexes of the prime numbers that compose A.
        (qs_sm*)mem_aligned(mem);

    // Allocates "base length" rows
    qs->base.data = (XSheet::XSheet9::XSheet10*)mem_aligned(qs->s.A_indexes +
                                        qs->s.values.double_value);
    qs->m.positions[0] = (uint8_t**)mem_aligned(qs->base.data + qs->base.length);
    qs->m.positions[1] = (uint8_t**)mem_aligned(qs->m.positions[0] +
                                                qs->base.length);
    qs->m.sieve = (uint8_t*)mem_aligned(qs->m.positions[1] + qs->base.length);
    qs->m.sieve[qs->m.length] = 0xFF
                                ; // the end of the sieve evaluates to "true" under any "truthy" mask.
    qs->m.flags = (uint8_t*)mem_aligned(qs->m.sieve + qs->m.length + sizeof(
                                  uint64_t));
    // Usage: buffer[0] is zeroed after use, buffer[1] isn't supposed zeroed after use.
    qs->buffer[0] = (qs_sm*)mem_aligned(qs->m.flags + qs->base.length);
    qs->buffer[1] = (qs_sm*)mem_aligned(qs->buffer[0] + buffers_size);

    // Other allocations
    qs->relations.length.capacity = (qs_sm) relations_size ;
    // Block Lanczos has a part of memory, it takes a "lite" snapshot before throwing relations.
    qs->lanczos.snapshot = (XSheet::XSheet16::XSheet17*)mem_aligned(qs->buffer[1] + buffers_size) ;
    qs->relations.data = (qs_relation**)mem_aligned(qs->lanczos.snapshot +
                                     relations_size);
    qs->divisors.data = (cint**)mem_aligned(qs->relations.data + relations_size);
    // A lot of divisors isn't needed because the algorithm calculate their GCD to reduce N.
    qs->mem.now = mem_aligned(qs->divisors.data + (qs->n_bits * qs->n_bits
                              >> 8));

    const qs_sm n_trees = (qs_sm) (sizeof(qs->uniqueness) / sizeof(
                                       struct avl_manager));
    for (qs_sm i = 0; i < n_trees; ++i)
    {   // the trees are used to identify duplicates (relations, partials, divisors of N)
        qs->uniqueness[i].inserter_argument = &qs->mem.now;
        qs->uniqueness[i].inserter = &avl_cint_inserter;
        qs->uniqueness[i].comparator = (int (*)(const void *,
                                                const void *)) &h_cint_compare;
        // they use default sign-less comparator.
    }
    avl_at(&qs->uniqueness[2],
           &qs->constants.ONE); // Ignore 1 as a divisor of N.
    DEBUG_LEVEL_4("Allocated %u MB of memory with a %u KB structure.\n",
                  qs->mem.bytes_allocated >> 20,
                  (unsigned)((char*)qs->mem.now - (char*)qs->mem.base) >> 10);
}

void preparation_part_5(qs_sheet *qs)
{   // Prepare the factor base (a set of small prime numbers used to find smooth numbers).
    static const double inv_ln_2 = 1.4426950408889634;
    cint *A = qs->vars.TEMP, *B = A + 1, *C = A + 2;
    qs_sm i = 0, prime;

    // the factor base contain the multiplier if different from 2.
    if (qs->multiplier != 2)
        qs->base.data[i].size = (qs_sm) (.35 + inv_ln_2 * log_computation(
                                             qs->base.data[i].num = qs->multiplier)), ++i;

    // then it contains the number 2.
    qs->base.data[i].num = 2, qs->base.data[i].size = 1;
    qs->base.data[i].sqrt_kN_mod_prime = *qs->constants.kN.mem % 8 == 1 ||
                                         *qs->constants.kN.mem % 8 == 7, ++i;

    // then the prime numbers for which kN is a quadratic residue modulo.
    for (prime = 3; i < qs->base.length; prime += 2)
        if (is_prime_4669913(prime))
        {   simple_int_to_cint(A, prime);
            cint_div(qs->sheet, &qs->constants.kN, A, B, C);
            const qs_sm kn_mod_prime = (qs_sm) simple_cint_to_int(C);
            qs->base.data[i].sqrt_kN_mod_prime = tonelli_shanks(kn_mod_prime,
                                                 prime);
            if (qs->base.data[i].sqrt_kN_mod_prime)
            {   qs->base.data[i].num = prime;
                qs->base.data[i].size = (qs_sm) (.35 + inv_ln_2 * log_computation(
                                                     prime)), ++i;
            }
        }
    // 2.5 * (base size) * ln(base size) is close to the largest prime number in factor base.
    qs->base.largest = qs->base.data[i - 1].num ;

    DEBUG_LEVEL_4("The factor base of %u suitable primes ends with %u.\n",
                  qs->base.length, qs->base.largest);
}

void preparation_part_6(qs_sheet *qs)
{   // completes the configuration by the algorithm itself.
    // computes D : a template (optimal value of hypercube) for the A polynomial coefficient.
    qs_sm i, min, span;
    const qs_sm s = qs->s.values.defined ;
    qs->poly.span.half = (span = qs->base.length / (s * (s + s))) >> 1;
    cint *kN = qs->vars.TEMP, *TMP = kN + 1, *R = kN + 2;
    cint_dup(kN, &qs->constants.kN);
    cint_left_shifti(kN, 1);
    cint_sqrt(qs->sheet, kN, TMP, R);
    cint_div(qs->sheet, TMP, &qs->constants.M_HALF, &qs->poly.D, R);
    qs->poly.d_bits = (qs_sm) cint_count_bits(&qs->poly.D);
    cint_nth_root(qs->sheet, &qs->poly.D, s,
                  R); // use the s-th root of D.
    const qs_sm root = (qs_sm) simple_cint_to_int(R) ;
    for (i = 1; qs->base.data[i].num <= root;
         ++i, assert(i < qs->base.length));
    if (i < span)
    {   DEBUG_LEVEL_3("[x] Maintenance adjusts the span value from %u to %u.\n",
                      span, i);
        span = i; // Avoids a rare case of failure when factoring small numbers (graceful degradation).
    }
    assert(i >= span);
    for (min = i - qs->poly.span.half, i *= i; i / min < span + min;
         --min);
    qs->poly.span.x_1 = min ;
    qs->poly.span.x_2 = min + qs->poly.span.half ;
    qs->poly.span.x_3 = qs->poly.span.x_2 * qs->poly.span.x_2 ;
    assert(qs->poly.span.x_2 < qs->base.length);
}

void get_started_iteration(qs_sheet *qs)
{   if (qs->lanczos.snapshot[0].relation)
    {   // the operation is fast, it shouldn't happen in average case.
        // it restores the relations reduced by the linear algebra step that failed.
        qs_sm i ;
        for(i = 0; qs->lanczos.snapshot[i].relation; ++i)
        {   qs->relations.data[i] = qs->lanczos.snapshot[i].relation;
            qs->relations.data[i]->Y.length = qs->lanczos.snapshot[i].y_length;
            qs->lanczos.snapshot[i].relation = 0 ;
        }
        assert(qs->relations.length.prev == i) ;
        qs->relations.length.now = i;
        DEBUG_LEVEL_4("[x] Maintenance restores the relations to a size of %u.\n",
                      i);
    }
    //  Increase the tick value in each iteration of the algorithm.
    if (++qs->time.tick % 32 == 0)
    {   if (qs->relations.length.prev == qs->relations.length.now)
        {   // The algorithm notices that no relations accumulates, and reacts to unblock the situation.
            DEBUG_LEVEL_3("[x] Maintenance randomizes D because the relation counter remains at %u.\n",
                          qs->relations.length.now);
            cint_random_bits(&qs->poly.D, qs->poly.d_bits, qs->seed);
            *qs->poly.D.mem |=
                1; // Shouldn't happen, D becomes a randomized odd number.
        }
        qs->relations.length.prev = qs->relations.length.now;
    }
}

void iteration_part_1(qs_sheet * qs, const cint * D, cint * A)
{   qs_sm n_tries = 0 ; // several attempts may rarely be necessary.
retry:;
    // A is a "random" product of "s" distinct prime numbers from the factor base.
    cint * X = qs->vars.TEMP, * Y = X + 1, *TMP, *_A = A ;
    qs_sm a, b, i = 0, j;
    if (qs->s.values.defined & 1) TMP = A, A = X, X = TMP ;
    // swap pointers so the last multiplication completes inside the A variable.
    simple_int_to_cint(A, 1);
    for (a = 0, b = qs->poly.span.x_3; a < qs->s.values.subtract_one;
         ++a)
    {   if (a & 1) i = b / (i + qs->poly.span.x_1) - (qs_sm) xor_rand(
                               qs->seed, 0, 9);
        else i = qs->poly.span.x_2 + (qs_sm) xor_rand(qs->seed, 0,
                     qs->poly.span.half);
        for (j = 0; j < a;
             j = i == qs->s.data[j].prime_index ? ++i, 0 : j + 1);
        qs->s.data[a].prime_index =
            i; // the selected divisor of A wasn't already present in the product.
        simple_int_to_cint(Y, qs->base.data[i].num);
        cint_mul(A, Y, X), TMP = A, A = X, X = TMP;
    }
    // a prime number from the factor base completes A, which must be close to D.
    cint_div(qs->sheet, D, A, X, Y);
    const qs_sm d_over_a = (qs_sm) simple_cint_to_int(X);
    for (i = qs->base.data[0].num != 2 ; qs->base.data[i].num <= d_over_a;
         ++i);
    for (j = 0; j < qs->s.values.subtract_one;
         j = i == qs->s.data[j].prime_index ? ++i, 0 : j + 1);
    if (qs->base.length <= i)
    {   const char *ord = n_tries == 0 ? "st" : n_tries == 1 ? "nd" :
                          n_tries == 2 ? "rd" : "th" ;
        DEBUG_LEVEL_3("[x] Maintenance discards A=%s on %u%s attempt.\n",
                      simple_cint_string(qs->qs_state, A), n_tries + 1, ord);
        assert(++n_tries <=
               16); // clearly shouldn't happen 16 times, review the algorithm parameters otherwise.
        A = _A ;
        goto retry;
    }
    qs->s.data[qs->s.values.subtract_one].prime_index = i ;
    simple_int_to_cint(Y, qs->base.data[i].num);
    cint_mul(A, Y,
             X); // generated A values should always be distinct, A no longer change.
    assert(X == &qs->poly.A);
}

void iteration_part_2(qs_sheet * qs, const cint * A, cint * B)
{   cint *X = qs->vars.TEMP, *PRIME = X + 1, *Y = X + 2, *R = X + 3;
    qs_sm i, *pen = qs->s.A_indexes;
    cint_erase(B);
    for (i = 0; i < qs->s.values.defined; ++i)
    {   const qs_sm idx = qs->s.data[i].prime_index,
                        prime = qs->base.data[idx].num;
        if (idx >= qs->iterative_list[3])
            qs->iterative_list[3] = 8 + idx - idx % 8 ;
        // write [index of prime number, power] of the A factors into buffer.
        *pen++ = qs->s.data[i].prime_index, *pen++ = 1;
        qs->s.data[i].prime_squared = (qs_md)prime * (qs_md)prime ;
        simple_int_to_cint(PRIME, prime);
        cint_div(qs->sheet, A, PRIME, X, R),
                 assert(R->mem == R->end); // div exact.
        cint_div(qs->sheet, X, PRIME, Y, R);
        qs->s.data[i].A_over_prime_mod_prime = (qs_sm) simple_cint_to_int(R);
        qs_md x = modular_inverse(qs->s.data[i].A_over_prime_mod_prime,
                                  prime);
        x = x * qs->base.data[qs->s.data[i].prime_index].sqrt_kN_mod_prime %
            prime;
        simple_int_to_cint(X, x > prime >> 1 ? prime - x : x);
        cint_mul(A, X, Y);
        cint_div(qs->sheet, Y, PRIME, &qs->s.data[i].B_terms, R),
                 assert(R->mem == R->end); // div exact.
        cint_addi(B, &qs->s.data[i].B_terms);
    }
}

void iteration_part_3(qs_sheet * qs, const cint * A, const cint * B)
{   cint *Q = qs->vars.TEMP, *R = Q + 1, *PRIME = Q + 2;
    qs_md i, j, x, y;
    for (i = 0; i < qs->base.length; ++i)
    {   // prepare the "roots" and "A_inv_double_value_B_terms". The algorithm will
        // fill 2 ** (s - 3) sieves by using these values and adding "prime sizes".
        const qs_sm prime = qs->base.data[i].num;
        simple_int_to_cint(PRIME, prime);
        cint_div(qs->sheet, A, PRIME, Q, R);
        const qs_sm a_mod_prime = (qs_sm) simple_cint_to_int(R) ;
        cint_div(qs->sheet, B, PRIME, Q, R) ;
        const qs_sm b_mod_prime = (qs_sm) simple_cint_to_int(R) ;
        const qs_sm a_inv_double_value = modular_inverse(a_mod_prime,
                                         prime) << 1 ;
        // Arithmetic shifts "<<" and ">>" performs multiplication or division by powers of two.
        x = y = prime;
        x += qs->base.data[i].sqrt_kN_mod_prime;
        y -= qs->base.data[i].sqrt_kN_mod_prime;
        x -= b_mod_prime;
        x *= a_inv_double_value >> 1;
        y *= a_inv_double_value ;
        x += qs->m.length_half ;
        x %= prime ;
        y += x ;
        y %= prime ;
        qs->base.data[i].root[0] = (qs_sm) x
                                   ; // First root of the polynomial mod prime.
        qs->base.data[i].root[1] = (qs_sm) y
                                   ; // Second root of the polynomial mod prime.
        for (j = 0; j < qs->s.values.defined; ++j)
        {   // compute the roots update value for all "s".
            cint_div(qs->sheet, &qs->s.data[j].B_terms, PRIME, Q, R);
            const qs_md b_term = simple_cint_to_int(R);
            qs->s.data[j].A_inv_double_value_B_terms[i] = (qs_sm)(
                        a_inv_double_value * b_term % prime);
        }
    }
    // The next function operates over "B_terms" multiplied by 2.
    for (i = 0; i < qs->s.values.defined;
         cint_left_shifti(&qs->s.data[i++].B_terms, 1));
}

qs_sm iteration_part_4(const qs_sheet * qs, const qs_sm nth_curve,
                       qs_sm ** corr, cint *B)
{   qs_sm i,
    gray_act; // the Gray code in "nth_curve" indicates which "B_term" to consider.
    for (i = 0; nth_curve >> i & 1; ++i);
    if (gray_act = (nth_curve >> i & 2) != 0, gray_act)
        cint_addi(B, &qs->s.data[i].B_terms) ;
    else // and which action to perform.
        cint_subi(B, &qs->s.data[i].B_terms) ;
    *corr = qs->s.data[i].A_inv_double_value_B_terms;
    return gray_act; // B values generated here should always be distinct.
}

void iteration_part_5(qs_sheet *  qs, const cint * kN,
                      const cint * B)
{   cint *P = qs->vars.TEMP, *Q = P + 1, *R_kN = P + 2, *R_B = P + 3,
              *TMP = P + 4;
    for (qs_sm a = 0; a < qs->s.values.defined; ++a)
    {   const qs_sm i = qs->s.data[a].prime_index;
        const qs_tmp prime = qs->base.data[i].num ;
        simple_int_to_cint(P, qs->s.data[a].prime_squared);
        cint_div(qs->sheet, B, P, Q, R_B);
        cint_div(qs->sheet, kN, P, Q, R_kN);
        if (B->nat < 0) cint_addi(R_B, P); // if B is negative.
        const qs_tmp rem_b = (qs_tmp) simple_cint_to_int(R_B);
        const qs_tmp rem_kn = (qs_tmp) simple_cint_to_int(R_kN);
        qs_tmp s ; // both remainders are modulo the prime number squared.
        if (rem_b < 0xb504f334)
        {   // the multiplication is straightforward.
            s = rem_b * rem_b - rem_kn;
            s /= prime ;
        }
        else
        {   // the common multiplication would overflow.
            cint_mul(R_B, R_B, TMP);
            cint_subi(TMP, R_kN);
            simple_int_to_cint(P, (qs_md) prime);
            cint_div(qs->sheet, TMP, P, Q, R_B);
            s = (qs_tmp) simple_cint_to_int(Q);
            if (Q->nat < 0) s = -s ;
        }
        //
        qs_tmp bezout = (rem_b % prime) * (qs_tmp)
                        qs->s.data[a].A_over_prime_mod_prime ;
        bezout = (qs_tmp) modular_inverse((qs_sm) (bezout % prime),
                                          (qs_sm) prime);
        //
        s = (qs_tmp) qs->m.length_half - s * bezout ;
        s %= prime ;
        s += (s < 0) * prime ;
        qs->base.data[i].root[0] = (qs_sm) s;
        qs->base.data[i].root[1] = (qs_sm)
                                   -1; // Zero out roots corresponding to the factors of A.
    }
}

void iteration_part_6(qs_sheet *qs, const cint *kN, const cint *A,
                      const cint *B, cint *C)
{   cint *TMP = qs->vars.TEMP, *R = TMP + 1;
    cint_mul(B, B, TMP); // (B * B) % A = kN % A
    cint_subi(TMP, kN); // C = (B * B - kN) / A
    cint_div(qs->sheet, TMP, A, C, R),
             assert(R->mem == R->end); // div exact.
}

void iteration_part_7(qs_sheet* qs, const qs_sm gray_addi, const qs_sm* corr)
{   // Sieve for larger prime numbers.
    memset(qs->m.sieve, 0, qs->m.length * sizeof(*qs->m.sieve));
    memset(qs->m.flags, 0, qs->base.length * sizeof(*qs->m.flags));
    uint8_t *end = qs->m.sieve + qs->m.length, *p_0, *p_1;
    for(qs_sm i = qs->iterative_list[3], j = qs->iterative_list[4]; i < j;
        ++i)
    {   const qs_sm prime = qs->base.data[i].num,
                        size = qs->base.data[i].size,
                        co = gray_addi ? prime - corr[i] : corr[i];
        qs->base.data[i].root[0] += co;
        if (qs->base.data[i].root[0] >= prime) qs->base.data[i].root[0] -=
                prime;
        qs->base.data[i].root[1] += co;
        if (qs->base.data[i].root[1] >= prime) qs->base.data[i].root[1] -=
                prime;
        p_0 = qs->m.sieve + qs->base.data[i].root[0];
        p_1 = qs->m.sieve + qs->base.data[i].root[1];
        for (; end > p_0 && end > p_1;)
            *p_0 += size, p_0 += prime, *p_1 += size, p_1 += prime;
        *p_0 += (end > p_0) * size, *p_1 += (end > p_1) * size;
    }
    for(qs_sm i = qs->iterative_list[4], j = qs->base.length; i < j; ++i)
    {   const qs_sm prime = qs->base.data[i].num,
                        size = qs->base.data[i].size,
                        co = gray_addi ? prime - corr[i] : corr[i] ;
        qs->base.data[i].root[0] += co;
        if (qs->base.data[i].root[0] >= prime) qs->base.data[i].root[0] -=
                prime;
        qs->base.data[i].root[1] += co;
        if (qs->base.data[i].root[1] >= prime) qs->base.data[i].root[1] -=
                prime;
        for(p_0 = qs->m.sieve + qs->base.data[i].root[0]; end > p_0;
            qs->m.flags[i] |= 1 << ((p_0 - qs->m.sieve) & 7), *p_0 += size,
            p_0 += prime);
        for(p_1 = qs->m.sieve + qs->base.data[i].root[1]; end > p_1;
            qs->m.flags[i] |= 1 << ((p_1 - qs->m.sieve) & 7), *p_1 += size,
            p_1 += prime);
    }
}

void iteration_part_8(qs_sheet * qs, const qs_sm gray_addi,
                      const qs_sm *  corr)
{   // Sieving means taking an interval [bM/2, +M/2] and determining for
    // which X in [bM/2, +M/2] a given prime number divides AX^2 + 2BX + C.
    uint8_t * chunk_begin = qs->m.sieve, *chunk_end = chunk_begin;
    uint8_t * sieve_end = chunk_begin + qs->m.length ;
    qs_sm *buffer = qs->buffer[0], walk_idx, * walk = buffer;
    // Since the previous function, the check is performed for the prime numbers of the factor base.
    for(qs_sm i = 0; i < qs->iterative_list[3]; ++i)
        if (qs->base.data[i].root[1] != (qs_sm) -1)
        {   *walk++ = i ; // the current prime number isn't a factor of A.
            const qs_sm prime = qs->base.data[i].num,
                        co = gray_addi ? prime - corr[i] : corr[i] ;
            qs->base.data[i].root[0] += co;
            if (qs->base.data[i].root[0] >= prime) qs->base.data[i].root[0] -=
                    prime;
            qs->base.data[i].root[1] += co;
            if (qs->base.data[i].root[1] >= prime) qs->base.data[i].root[1] -=
                    prime;
            qs->m.positions[0][i] = chunk_begin + qs->base.data[i].root[0];
            qs->m.positions[1][i] = chunk_begin + qs->base.data[i].root[1];
        }
    for(walk_idx = 0; buffer[walk_idx] < qs->iterative_list[1];
        ++walk_idx);
    do  // iterates step by step until the entire sieve is filled.
    {   walk = buffer + walk_idx ;
        chunk_end = chunk_end + qs->m.cache_size < sieve_end ? chunk_end +
                    qs->m.cache_size : sieve_end;
        do
        {   const qs_sm size = qs->base.data[*walk].size,
                            prime = qs->base.data[*walk].num,
                            times = 4 >> (*walk > qs->iterative_list[2]) ;
            uint8_t ** const p_0 = qs->m.positions[0] + *walk,
                             ** const p_1 = qs->m.positions[1] + *walk;
            const qs_tmp diff = *p_1 - *p_0 ;
            for(const uint8_t * const bound = chunk_end - prime * times;
                bound > *p_0;)
                for(qs_sm i = 0; i < times; ++i)
                    **p_0 += size, *(*p_0 + diff) += size, *p_0 += prime;
            for(; *p_0 < chunk_end && *p_0 + diff < chunk_end;)
                **p_0 += size, *(*p_0 + diff) += size, *p_0 += prime;
            *p_1 = *p_0 + diff ;
            if (*p_0 < chunk_end) **p_0 += size, *p_0 += prime;
            if (*p_1 < chunk_end) **p_1 += size, *p_1 += prime;
        }
        while(*++walk);
    }
    while(chunk_begin = chunk_end, chunk_begin < sieve_end);
    memset(qs->buffer[0], 0, (walk - qs->buffer[0]) * sizeof(*walk));
}

cint * qs_divisors_uniqueness_helper(qs_sheet * qs, const cint * num)
{   // Helper for uniqueness within the divisors of N.
    struct avl_node *node;
    node = avl_at(&qs->uniqueness[2], num) ;
    return (cint*)(qs->uniqueness[2].affected ? node->key : 0);
}

int qs_register_divisor(qs_sheet *qs)
{   // Register a divisor of N, combine them with GCD and identify the perfect powers.
    // Returns 0 when the factorization is completed, 1 otherwise.
#define IN_RANGE(F) (h_cint_compare(&qs->constants.ONE, F) < 0 && h_cint_compare(F, &qs->vars.N) < 0)
    cint *F = &qs->vars.FACTOR, *tmp;
    F->nat = 1 ; // Absolute value.
    if (!(IN_RANGE(F) && (tmp = qs_divisors_uniqueness_helper(qs, F))))
        return 1; // Duplicates are ignored.
    struct task
    {   cint * num ;
        char origin ;
    } tasks[63] ; // Implements a stack-based recursion.
    cint *curr, **divisors = qs->divisors.data, *Q = qs->vars.TEMP + 3,
                  *R = Q + 1;
    int i = 0, pow;
    tasks[i++] = (struct task)
    {   tmp, 0
    };
    DEBUG_LEVEL_4("- New divisor %s shown.\n",
                  simple_cint_string(qs->qs_state, tmp));
    do
    {   curr = tasks[--i].num; // Retrieve the top element.
        if (cint_is_prime(qs->sheet, curr, -1, qs->seed))
        {   pow = (int) cint_remove(qs->sheet, &qs->vars.N, curr);
            assert(pow); // Prime factors are removed from N.
            ++qs->divisors.total_primes;
            qs->n_bits = (qs_sm) cint_count_bits(&qs->vars.N);
            // Register this prime factor in the manager's routine.
            manager_add_factor(qs->qs_state, curr, pow, 1);
            if (tasks[i].origin)
            {   const char * msg = 0
                             ; // Explain succinctly how this prime factor was found.
                switch(tasks[i].origin)
                {   case 1 : msg = "And allows us for N"; break;
                    case 2 : msg = "Prunes the divisors"; break;
                    case 3 : msg = "Divides N"; break;
                    case 4 : msg = "Notes a perfect power"; break;
                    case 5 : msg = "Performs GCD within the divisors"; break;
                }
                DEBUG_LEVEL_4("%*s- %s to get %s.\n", (i + 1) << 1, "", msg,
                              simple_cint_string(qs->qs_state, curr));
            }
            if (qs->n_bits != 1)
            {   DEBUG_LEVEL_4("%*s- This prime factor reduces N to %d-bit.\n",
                              (i + 1) << 1, "", qs->n_bits);
                if ((tmp = qs_divisors_uniqueness_helper(qs, &qs->vars.N)))
                    tasks[i++] = (struct task)
                {   tmp, 1
                }; // 1. And allows us.
                for (qs_sm j = 0; j < qs->divisors.length; ++j)
                {   cint_dup(F, divisors[j]);
                    pow = cint_remove(qs->sheet, F, curr);
                    if (pow)
                    {   divisors[j--] = divisors[--qs->divisors.length];
                        if ((tmp = qs_divisors_uniqueness_helper(qs, F)) && IN_RANGE(tmp))
                            tasks[i++] = (struct task)
                        {   tmp, 2
                        }; // 2. Prunes the divisors.
                    }
                }
            }
            else
                DEBUG_LEVEL_4("%*s- The factorization is complete since it's a prime.\n",
                              (i + 1) << 1, "");
        }
        else
        {   cint_div(qs->sheet, &qs->vars.N, curr, Q, R) ;
            if (R->mem == R->end && IN_RANGE(Q) &&
                (tmp = qs_divisors_uniqueness_helper(qs, Q)))
                tasks[i++] = (struct task)
            {   tmp, 3
            }; // 3. Divides N.
            pow = factorization_any_root_checker(qs->qs_state, curr, Q, R) ;
            if (pow && IN_RANGE(Q) &&
                (tmp = qs_divisors_uniqueness_helper(qs, Q)))
                tasks[i++] = (struct task)
            {   tmp, 4
            }; // 4. Notes a perfect power.
            for (qs_sm j = 0; j < qs->divisors.length; ++j)
            {   cint_gcd(qs->sheet, curr, divisors[j], Q);
                if (IN_RANGE(Q) && (tmp = qs_divisors_uniqueness_helper(qs, Q)))
                    tasks[i++] = (struct task)
                {   tmp, 5
                }; // 5. Performs GCD within the divisors.
            }
            divisors[qs->divisors.length++] = curr;
        }
    }
    while (i && qs->n_bits != 1);
    return qs->n_bits != 1;
#undef IN_RANGE
}

void register_relations(qs_sheet * qs, const cint * A, const cint * B,
                        const cint * C)
{   cint *  TMP = qs->vars.TEMP, * K = &qs->vars.KEY,
                * V = &qs->vars.VALUE ;
    qs_sm m_idx, idx, mod;
    // iterates the values of X in [-M/2, +M/2].
    for (m_idx = 0; m_idx < qs->m.length; ++m_idx)
        if (qs->m.sieve[m_idx] >= qs->threshold.value)
        {   // over the threshold, compute f(X) and check candidate for smoothness.
            simple_int_to_cint(&qs->vars.X, m_idx);
            cint_subi(&qs->vars.X,
                      &qs->constants.M_HALF); // X = "current index" - M/2
            cint_mul(A, &qs->vars.X, TMP); // TMP = AX
            cint_addi(TMP, B); // TMP = AX + B
            cint_dup(K, TMP); // Key = copy of AX + B
            cint_addi(TMP, B); // TMP = AX + 2B
            cint_mul(TMP, &qs->vars.X, V); // V = AX^2 + 2BX
            cint_addi(V, C); // Value = f(X) = AX^2 + 2BX + C
            // We can inject X in the equation A * C + kN = B * B
            // So it should hold that (A * X + B)^2 - kN = A * f(X)
            V->nat = 1 ; // absolute value
            qs_sm target_bits = (qs_sm) cint_count_bits(V) - qs->error_bits;
            qs_sm removed_bits = 0, *pen = qs->buffer[1];
            //  writes the pairs [index of the prime number, power found in V].
            if (qs->base.data[0].num != 1)
            {   simple_int_to_cint(TMP, qs->base.data[0].num);
                *pen++ = 0; // remove powers of the multiplier.
                *pen = (qs_sm) cint_remove(qs->sheet, V, TMP);
                if (*pen) removed_bits += *pen++ * qs->base.data[0].size;
                else --pen;
            }
            for (idx = 1; idx < qs->iterative_list[1]; ++idx)
                if (qs->base.data[idx].root[1] == (qs_sm) -1 ||
                    (mod = m_idx % qs->base.data[idx].num,
                     mod == qs->base.data[idx].root[0] ||
                     mod == qs->base.data[idx].root[1]))
                {   simple_int_to_cint(TMP, qs->base.data[idx].num);
                    // for a given prime number of the factor base, "remove" returns
                    // the numbers of powers that was present in V, and V is updated.
                    *pen++ = idx;
                    *pen = (qs_sm) cint_remove(qs->sheet, V, TMP);
                    if (*pen) removed_bits += *pen++ * qs->base.data[idx].size;
                    else --pen;
                }
            if (removed_bits + qs->m.sieve[m_idx] >= target_bits)
            {   // there is a chance to register a new relation.
                for (removed_bits = 0, target_bits = qs->m.sieve[m_idx];
                     idx < qs->iterative_list[4] && removed_bits < target_bits; ++idx)
                    if (qs->base.data[idx].root[1] == (qs_sm) -1 ||
                        (mod = m_idx % qs->base.data[idx].num,
                         mod == qs->base.data[idx].root[0] ||
                         mod == qs->base.data[idx].root[1]))
                    {   simple_int_to_cint(TMP, qs->base.data[idx].num);
                        *pen++ = idx;
                        *pen = (qs_sm) cint_remove(qs->sheet, V, TMP);
                        if (*pen) removed_bits += *pen++ * qs->base.data[idx].size;
                        else --pen;
                    }
                for (const uint8_t mask = 1 << (m_idx & 7); idx < qs->base.length &&
                     removed_bits < target_bits; ++idx)
                    if (qs->m.flags[idx] & mask)
                        if (mod = m_idx % qs->base.data[idx].num,
                            mod == qs->base.data[idx].root[0] ||
                            mod == qs->base.data[idx].root[1])
                        {   simple_int_to_cint(TMP, qs->base.data[idx].num);
                            *pen++ = idx;
                            *pen = (qs_sm) cint_remove(qs->sheet, V, TMP);
                            if (*pen) removed_bits += *pen++ * qs->base.data[idx].size;
                            else --pen;
                        }
                const qs_sm* const prime_indexes_and_powers[4] =
                {   qs->s.A_indexes, // really factoring A * f(X), commit outstanding A factors.
                    qs->s.A_indexes + qs->s.values.double_value,
                    qs->buffer[1],
                    pen,
                };
                if (h_cint_compare(V, &qs->constants.ONE) == 0)
                    register_regular_relation(qs, K, prime_indexes_and_powers);
                else if (155 < qs->kn_bits &&
                         h_cint_compare(V, &qs->constants.TOO_LARGE_PRIME) < 0)
                    //  Store it until another partial share the same variation (also called large prime, cofactor).
                    register_partial_relation(qs, K, V, prime_indexes_and_powers);
            }
        }
}

void register_regular_relation(qs_sheet * qs, const cint * KEY,
                               const qs_sm * const args[4])
{   struct avl_node *node = avl_at(&qs->uniqueness[0], KEY);
    if (node->value)
        return; // duplicates at this stage are ignored.
    struct qs_relation * rel = (qs_relation*)qs->mem.now;
    qs_sm i, j ;
    qs->mem.now = rel + 1
                  ; // a relation must be swappable for Block Lanczos reducing.
    rel->X = (cint*)node->key; // constant X is stored by the node key.
    rel->Y.data = (qs_sm*)qs->mem.now; // Y data length only decreases.
    const size_t y_length = (args[1] - args[0] + args[3] - args[2]) >> 1 ;
    rel->axis.Z.data = rel->Y.data + y_length; // writes Z ahead.
    for (i = 0; i < 4;)
    {   // processes the given column arrays.
        const qs_sm * idx = args[i++],
                               * const end_index = args[i++];
        for (; idx < end_index; idx += 2)
        {   const qs_sm power = *(idx + 1) ;
            if (power & 1)
            {   // remove from Y the indexes of the prime numbers that are already listed (factors of A).
                for (j = 0; j < rel->Y.length && rel->Y.data[j] != *idx; ++j);
                if (j == rel->Y.length) // add, the index wasn't present.
                    rel->Y.data[rel->Y.length++] = *idx;
                else // or remove.
                    memmove(rel->Y.data + j, rel->Y.data + j + 1,
                            (--rel->Y.length - j) * sizeof(*rel->Y.data));
            }
            for (j = 0; j < power; ++j)
                rel->axis.Z.data[rel->axis.Z.length++] = *idx;
        }
    }
    qs->mem.now = rel->axis.Z.data +
                  rel->axis.Z.length; // Z length is known.
    int verified = 0 ;
    if (rel->Y.length > qs->s.values.defined)
    {   // it often passes.
        cint *A = qs->vars.TEMP, *B = A + 1;
        simple_int_to_cint(A, 1);
        for (j = 0; j < rel->axis.Z.length; ++j)
        {   simple_int_to_cint(B, qs->base.data[rel->axis.Z.data[j]].num);
            cint_mul_modi(qs->sheet, A, B, &qs->constants.kN);
        }
        cint_mul_mod(qs->sheet, rel->X, rel->X, &qs->constants.kN, B);
        verified = !cint_compare(A, B) ||
                   (cint_addi(A, B), !cint_compare(A, &qs->constants.kN));
    }
    if (verified)
    {   node->value = qs->relations.data[qs->relations.length.now] = rel;
        qs->mem.now = rel->axis.Z.data + rel->axis.Z.length;
        rel->id = ++qs->relations.length.now; // Keep the relation.
    }
    else
    {   DEBUG_LEVEL_3("[x] Maintenance discards the relation at index %u.\n",
                      qs->relations.length.now);
        char* open = (char*)rel;
        char* close = (char*)qs->mem.now ;
        qs->mem.now = memset(open, 0, close - open); // Throw.
    }
}

void register_partial_relation(qs_sheet * qs, const cint * KEY,
                               const cint * VALUE, const qs_sm* const args[4])
{   // Process the single large-prime variation.
    // Searches 2 different KEY sharing the same VALUE.
    struct avl_node *node = avl_at(&qs->uniqueness[1], VALUE);
    struct qs_relation *old, *New;
    cint * BEZOUT = 0;
    old = (qs_relation*)node->value;
    if (old)
    {   if (old->X == 0)
            return; // the value is already marked as "ignored".
        if (old->axis.next)
            return; // accepting all "next" without caring compromise the linear algebra.
        for (; old && h_cint_compare(KEY, old->X); old = old->axis.next);
        if (old) return; // same KEY already registered.
        old = (qs_relation*)node->value;
        if (old->axis.next == 0)
        {   // there is an "old" using the same VALUE, and it has no "next" yet.
            cint *A = qs->vars.TEMP, *B = A + 1;
            if (qs->multiplier != 1)
                if (cint_gcd(qs->sheet, VALUE, &qs->constants.MULTIPLIER, A),
                    cint_compare_char(A, 1))
                {   old->X =
                        0; // VALUE shouldn't be related so close to the multiplier.
                    return;
                }
            // so compute BEZOUT.
            cint_modular_inverse(qs->sheet, VALUE, &qs->constants.kN, A);
            if (A->mem == A->end)
            {   old->X = 0; // no solution to the linear congruence.
                cint_gcd(qs->sheet, VALUE, &qs->constants.kN, &qs->vars.FACTOR);
                cint_div(qs->sheet, &qs->vars.N, &qs->vars.FACTOR, A, B);
                if (B->mem == B->end) // found a small factor of N ?
                    qs_register_divisor(qs);
                return; // nothing.
            }
            else
                BEZOUT = A;
        }
    }

    New = (qs_relation*)mem_aligned(qs->mem.now);
    qs->mem.now = New + 1;
    New->X = (cint*)qs->mem.now;

    if (BEZOUT)
    {   // BEZOUT is stored directly after the New X, like in an array.
        qs->mem.now = New->X + 2;
        simple_dup_cint(New->X, KEY, &qs->mem.now);
        simple_dup_cint(New->X + 1, BEZOUT, &qs->mem.now);
        // The 2nd newcomer become the root of the linked list.
        New->axis.next = old, node->value = New = old = New;
    }
    else
    {   // All but the 2nd have no special treatment.
        qs->mem.now = New->X + 1; // they come at the end of the linked list.
        simple_dup_cint(New->X, KEY, &qs->mem.now);
        if (old)
        {   for (;
                 old->axis.next;
                 old = old->axis.next) (void)nullptr;
            old->axis.next = New, old = (qs_relation*)node->value;
        }
        else node->value = New;
    }

    // data buffered isn't persistent, it may be needed, so it's copied.
    qs_sm * data = New->Y.data = (qs_sm*)mem_aligned(qs->mem.now);
    New->Y.length = (qs_sm) (args[1] - args[0]);
    memcpy(data, args[0], New->Y.length * sizeof(*data));
    memcpy(data + New->Y.length, args[2],
           (args[3] - args[2]) * sizeof(*data));
    New->Y.length += (qs_sm) (args[3] - args[2]);
    qs->mem.now = New->Y.data + New->Y.length;

    if (old)
    {   BEZOUT = old->X + 1 ; // the modular inverse was stored here.
        cint_mul_mod(qs->sheet, New->X, BEZOUT, &qs->constants.kN,
                     &qs->vars.CYCLE);
        do
        {   if (old != New)
            {   // combines, it registers a smooth relation using the 2 buffers.
                cint_mul_mod(qs->sheet, &qs->vars.CYCLE, old->X, &qs->constants.kN,
                             &qs->vars.KEY);
                qs_sm* begin = qs->buffer[0];
                qs_sm* pen = begin;
                data = (qs_sm*)memset(qs->buffer[1], 0, qs->base.length * sizeof(*data));
                for (qs_sm i = 0; i < New->Y.length; i += 2)
                    data[New->Y.data[i]] += New->Y.data[i + 1];
                for (qs_sm i = 0; i < old->Y.length; i += 2)
                    data[old->Y.data[i]] += old->Y.data[i + 1];
                for (qs_sm i = 0; i < qs->base.length; ++i)
                    if (data[i]) // writes [index of the prime number, power]
                        *pen++ = i, *pen++ = data[i];
                qs_sm* newargs[4] = {begin, pen, 0, 0};
                register_regular_relation(qs, &qs->vars.KEY, newargs);
                ++qs->relations.length.by_partial;
                memset(begin, 0, (char *) pen - (char *) begin); // zeroed.
            }
        }
        while ((old = old->axis.next));
        // the linked list can handle 2+ entries, but their more complex combinations isn't implemented.
    }
}

void finalization_part_1(qs_sheet * qs,
                         const uint64_t * const lanczos_answer)
{   // Block Lanczos linear algebra answer is simply "mask followed by null_rows", with read-only.
    if (*lanczos_answer == 0)
        return;
    const uint64_t mask = *lanczos_answer,
                   * null_rows = lanczos_answer + 1;
    cint *X = &qs->vars.X, *Y = qs->vars.TEMP, *TMP = Y + 1, *POW = Y + 2;
    qs_sm *  power_of_primes;
    for(qs_sm row = 0; row < 64 && qs->n_bits != 1; ++row)
        if (mask >> row & 1)
        {   // use the Fermat's (1607 - 1665) method to compute a factorization of N.
            simple_int_to_cint(X, 1), simple_int_to_cint(TMP, 1),
                               simple_int_to_cint(Y, 1);
            power_of_primes = (qs_sm*)memset(qs->buffer[1], 0,
                                     qs->base.length * sizeof(*power_of_primes));
            for (qs_sm i = 0; i < qs->relations.length.now; ++i)
                if (null_rows[i] >> row & 1)
                {   const struct qs_relation * const rel =
                            qs->relations.data[i];
                    // The algorithm must retrieve the X and Z relation fields
                    // related to the Y field initially submitted to Block Lanczos.
                    cint_mul_modi(qs->sheet, X, rel->X, &qs->vars.N);
                    for (qs_sm j = 0; j < rel->axis.Z.length; ++j)
                        ++power_of_primes[rel->axis.Z.data[j]];
                }
            for (qs_sm i = 0; i < qs->base.length; ++i)
                if (power_of_primes[i])
                {   // powers are even ... square root ...
                    simple_int_to_cint(TMP, qs->base.data[i].num);
                    simple_int_to_cint(POW, power_of_primes[i] >> 1);
                    cint_pow_modi(qs->sheet, TMP, POW, &qs->vars.N);
                    cint_mul_modi(qs->sheet, Y, TMP, &qs->vars.N);
                }
            h_cint_subi(Y, X);
            if (Y->mem != Y->end)
            {   cint_gcd(qs->sheet, &qs->vars.N, Y, &qs->vars.FACTOR);
                // 100 digits RSA number has been factored by the software in 2022.
                if (qs_register_divisor(qs) == 0)
                    break;
            }
        }
}

int finalization_part_2(qs_sheet *qs)
{   if (qs->n_bits != 1 && qs->divisors.length)
    {   // In rare cases N must be partially factored.
        // Registers a divisor encountered by the algorithm in the manager routine.
        cint **divisors = qs->divisors.data, *tmp;
        for (qs_sm i = 0; i < qs->divisors.length; ++i)
        {   for (qs_sm j = 1 + i; j < qs->divisors.length; ++j)
                if (h_cint_compare(divisors[j], divisors[i]) < 0)
                    tmp = divisors[i], divisors[i] = divisors[j],
                                                     divisors[j] = tmp; // Apply a selection sort.
            if (h_cint_compare(&qs->constants.ONE, divisors[i]) < 0 &&
                h_cint_compare(divisors[i], &qs->vars.N) < 0)
            {   const int power = (int) cint_remove(qs->sheet, &qs->vars.N,
                                                    divisors[i]);
                if (power)
                {   DEBUG_LEVEL_4("Quadratic Sieve submits the composite divisor %s as a result.\n",
                                  simple_cint_string(qs->qs_state, divisors[i]));
                    manager_add_factor(qs->qs_state, divisors[i], power,
                                       -1); // -1 marks this divisor as composite for recursive factorization.
                    qs->n_bits = (qs_sm) cint_count_bits(&qs->vars.N);
                }
            }
            else
                break; // No need to sort more.
        }
        // Recursively running the Quadratic Sieve will allow faster factorization than this oversized instance.
        DEBUG_LEVEL_3("[x] Maintenance is to forward the remainder %s.\n",
                      simple_cint_string(qs->qs_state, &qs->vars.N));
    }

    if (qs->uniqueness[1].count)
        DEBUG_LEVEL_4("The sieve reported %u partials which added %u smooth relations.\n",
                      (unsigned) qs->uniqueness[1].count, qs->relations.length.by_partial);
    DEBUG_LEVEL_4("The algorithm completed with %u polynomials and %u relations.\n",
                  qs->poly.curves, qs->relations.length.peak);
    DEBUG_LEVEL_4("Used %u MB of memory during %.02f second(s).\n",
                  (unsigned) ((char *) qs->mem.now - (char *) qs->mem.base) >> 20,
                  0.001 * (get_time_ms() - qs->time.start));

    // Tells the factorization manager whether its task has progressed using the Quadratic Sieve.
    const int has_fully_factored = qs->n_bits == 1,
              has_partially_factored = qs->divisors.length != 0 ;
    const int res = has_fully_factored || has_partially_factored ;
    if (res) // Updates the input number accordingly, since the algorithm worked on a copy of it.
        cint_dup(&qs->qs_state->session.num, &qs->vars.N);

    return res ;
}

// Compiling with "gcc -Wall -pedantic -O2 -std=c99 main.c -o factor" can speed up by a factor 2 or 3.
// Block Lanczos algorithm released "as it" into the public domain, without any warranty, express or implied.
// Results of operations are last AND non-const arguments.

// KornC)l LC!nczos (1893 - 1974) was a Hungarian-American and later Hungarian-Irish mathematician and physicist.

void lanczos_mul_MxN_Nx64(const qs_sheet *qs, const uint64_t *X,
                          const qs_sm max_size, uint64_t *Y)
{   assert(Y != X);
    memset(Y, 0, max_size * sizeof(uint64_t));
    for (qs_sm a = 0, b; a < qs->relations.length.now; ++a)
    {   struct qs_relation *const rel = qs->relations.data[a];
        for (b = 0; b < rel->Y.length; ++b)
            Y[rel->Y.data[b]] ^= X[a];
    }
}

void lanczos_mul_trans_MxN_Nx64(const qs_sheet *qs, const uint64_t *X,
                                uint64_t *Y)
{   assert(Y != X);
    for (qs_sm a = 0, b; a < qs->relations.length.now; ++a)
    {   struct qs_relation *const rel = qs->relations.data[a];
        for (Y[a] = 0, b = 0; b < rel->Y.length; ++b)
            Y[a] ^= X[rel->Y.data[b]];
    }
}

void lanczos_mul_64xN_Nx64(const qs_sheet *qs, const uint64_t *X,
                           const uint64_t *Y, uint64_t *Z, uint64_t *T)
{   assert(X != Z && Y != Z);
    qs_sm a, b, c, d;
    memset(Z, 0, 256 * 8 * sizeof(*Z));
    memset(T, 0, 64 * sizeof(*T));
    for (a = 0; a < qs->relations.length.now; ++a)
    {   const uint64_t tmp = X[a]; // read while writing ?!
        for (b = 0, c = 0; c < 64; c += 8, b += 256)
            Z[b + (tmp >> c & 0xff)] ^= Y[a];
    }
    for (a = 0; a < 8; ++a, ++T)
    {   uint64_t tmp[8] = {0};
        for (b = 0; b < 256; ++b)
            if (b >> a & 1)
                for (c = d = 0; c < 8; ++c, d += 256)
                    tmp[c] ^= Z[b + d];
        for (b = 0, c = 0; b < 8; ++b, c += 8)
            T[c] = tmp[b];
    }
}

uint64_t lanczos_find_non_singular_sub(const uint64_t *t,
                                       const uint64_t *last_s, uint64_t *s, uint64_t last_dim, uint64_t *w)
{   uint64_t i, j, dim, cols[64];
    uint64_t M[64][2], mask, *row_i, *row_j, m_0, m_1;
    for (i = 0; i < 64; ++i)
        M[i][0] = t[i], M[i][1] = (uint64_t) 1 << i;
    mask = 0;
    for (i = 0; i < last_dim; ++i)
        mask |= (uint64_t) 1 << (cols[63 - i] = last_s[i]);
    for (i = j = 0; i < 64; ++i)
        if (!(mask & ((uint64_t) 1 << i)))
            cols[j++] = i;
    for (i = dim = 0; i < 64; ++i)
    {   mask = (uint64_t) 1 << (cols[i]);
        row_i = M[cols[i]];
        for (j = i; j < 64; ++j)
        {   row_j = M[cols[j]];
            if (row_j[0] & mask)
            {   m_0 = row_j[0];
                m_1 = row_j[1];
                row_j[0] = row_i[0];
                row_j[1] = row_i[1];
                row_i[0] = m_0;
                row_i[1] = m_1;
                break;
            }
        }
        if (j < 64)
        {   for (j = 0; j < 64; ++j)
            {   row_j = M[cols[j]];
                if (row_i != row_j && (row_j[0] & mask))
                    row_j[0] ^= row_i[0], row_j[1] ^= row_i[1];
            }
            s[dim++] = cols[i];
            continue;
        }
        for (j = i; j < 64; ++j)
        {   row_j = M[cols[j]];
            if (row_j[1] & mask)
            {   m_0 = row_j[0];
                m_1 = row_j[1];
                row_j[0] = row_i[0];
                row_j[1] = row_i[1];
                row_i[0] = m_0;
                row_i[1] = m_1;
                break;
            }
        }
        if (j == 64) return 0; // sub-matrix is not invertible

        for (j = 0; j < 64; ++j)
        {   row_j = M[cols[j]];
            if (row_i != row_j && (row_j[1] & mask))
                row_j[0] ^= row_i[0], row_j[1] ^= row_i[1];
        }

        row_i[0] = row_i[1] = 0;
    }
    for (i = 0; i < 64; ++i)
        w[i] = M[i][1];
    mask = 0;
    for (i = 0; i < dim; ++i)
        mask |= (uint64_t) 1 << s[i];
    for (i = 0; i < last_dim; ++i)
        mask |= (uint64_t) 1 << last_s[i];
    dim *= mask == -(uint64_t) 1;
    return dim;
}

void lanczos_mul_Nx64_64x64_acc(qs_sheet *qs, const uint64_t *X,
                                const uint64_t *Y, uint64_t *Z, uint64_t *T)
{   qs_sm a;
    uint64_t b, c, d, e;
    for (b = 0; b < 8; Y += 8, Z += 256, ++b)
        for (c = 0; c < 256; ++c)
            for (d = Z[c] = 0, e = c; e; e >>= 1, ++d)
                Z[c] ^= (e & 1) * Y[d];
    for (a = 0, Z -= 2048; a < qs->relations.length.now; ++a)
        for (c = d = 0; c < 64; c += 8, d += 256)
        {   const uint64_t w = X[a];
            T[a] ^= Z[d + (w >> c & 0xff)];
        }
}

void lanczos_mul_64x64_64x64(const uint64_t *X, const uint64_t *Y,
                             uint64_t *Z)
{   uint64_t a, b, c, d, tmp[64];
    for (a = 0; a < 64; tmp[a++] = c)
    {   for (b = 0, c = 0, d = X[a]; d; d >>= 1, ++b)
            c ^= (d & 1) * Y[b];
    }
    memcpy(Z, tmp, sizeof(tmp));
}

void lanczos_transpose_vector(qs_sheet *qs, const uint64_t *X,
                              uint64_t **Y)
{   qs_sm a; // Z will be zeroed automatically by the loop.
    uint64_t b, c, d, *Z;
    Z = (uint64_t*)memcpy(qs->mem.now, X, qs->relations.length.now * sizeof(*X));
    for (a = 0; a < qs->relations.length.now; ++a)
        for (b = 0, c = a >> 6, d = (uint64_t) 1 << (a % 64); Z[a];
             Z[a] >>= 1, ++b)
            Y[b][c] |= (Z[a] & 1) * d;
}

void lanczos_combine_cols(qs_sheet *qs, uint64_t *x, uint64_t *v,
                          uint64_t *ax, uint64_t *av)
{   // Use Gaussian elimination on the columns of [ax | av] to find all linearly dependent columns.
    qs_sm i, j, bit_pos, num_deps;
    uint64_t k, col, col_words;
    uint64_t mask, *mat_1[128], *mat_2[128], *tmp;
    num_deps = 64 << (v && av);
    col_words = (qs->relations.length.now + 63) / 64;
    for (i = 0; i < num_deps; ++i)
    {   mat_1[i] = (uint64_t*)qs->mem.now;
        mat_2[i] = mat_1[i] + col_words;
        qs->mem.now = mat_2[i] + col_words;
    }
    lanczos_transpose_vector(qs, x, mat_1);
    lanczos_transpose_vector(qs, ax, mat_2);
    if (num_deps == 128)
    {   lanczos_transpose_vector(qs, v, mat_1 + 64);
        lanczos_transpose_vector(qs, av, mat_2 + 64);
    }
    for (i = bit_pos = 0; i < num_deps &&
         bit_pos < qs->relations.length.now; ++bit_pos)
    {   mask = (uint64_t) 1 << (bit_pos % 64);
        col = bit_pos / 64;
        for (j = i; j < num_deps; ++j)
            if (mat_2[j][col] & mask)
            {   tmp = mat_1[i];
                mat_1[i] = mat_1[j];
                mat_1[j] = tmp;
                tmp = mat_2[i];
                mat_2[i] = mat_2[j];
                mat_2[j] = tmp;
                break;
            }
        if (j == num_deps)
            continue;
        for (++j; j < num_deps; ++j)
            if (mat_2[j][col] & mask)
                for (k = 0; k < col_words; ++k)
                {   mat_2[j][k] ^= mat_2[i][k];
                    mat_1[j][k] ^= mat_1[i][k];
                }
        ++i;
    }

    for (j = 0; j < qs->relations.length.now; ++j)
    {   uint64_t word = 0;
        col = j / 64;
        mask = (uint64_t) 1 << (j % 64);
        for (k = i; k < 64; ++k)
            if (mat_1[k][col] & mask)
                word |= (uint64_t) 1 << k;
        x[j] = word;
    }
    char *open = (char *)mat_1[0];
    char *close = (char*)qs->mem.now;
    qs->mem.now = memset(open, 0, close - open);
}

void lanczos_build_array(qs_sheet *qs, uint64_t **target,
                         const size_t quantity, const size_t size)
{   // ensure it remains memory for linear algebra
    const char *mem_needs = (char *) qs->mem.now + quantity * size *
                            sizeof(uint64_t);
    const char *mem_ends = (char *) qs->mem.now + qs->mem.bytes_allocated;
    assert(mem_needs < mem_ends);
    for (size_t i = 0; i < quantity; ++i)
        target[i] = (uint64_t*)qs->mem.now,
        qs->mem.now = (uint64_t*)mem_aligned(target[i] + size);
}

uint64_t *lanczos_block_worker(qs_sheet *qs)
{   const qs_sm n_cols = qs->relations.length.now,
                    v_size = n_cols > qs->base.length ? n_cols : qs->base.length;
    const uint64_t safe_size = qs->lanczos.safe_length;
    uint64_t *md[6], *xl[2], *sm[13], *tmp, *res, mask_0, mask_1;
    qs_sm i, dim_0, dim_1;
    qs->mem.now = mem_aligned((uint64_t *) qs->mem.now +
                              1); // keep some padding.
    lanczos_build_array(qs, md, 6, safe_size);
    lanczos_build_array(qs, sm, 13, 64);
    lanczos_build_array(qs, xl, 2, safe_size < 2048 ? 2048 : safe_size);
    res = (*md) - 1; // simple "trick" to return mask + null_rows
    for (i = 0; i < 64; ++i)
        sm[12][i] = i;
    dim_0 = 0;
    dim_1 = 64;
    mask_1 = (uint64_t) -1;
    for (i = 0; i < qs->relations.length.now; ++i)
        md[1][i] = xor_random(qs->seed);
    memcpy(md[0], md[1], v_size * sizeof(uint64_t));
    lanczos_mul_MxN_Nx64(qs, md[1], v_size, xl[1]);
    lanczos_mul_trans_MxN_Nx64(qs, xl[1], md[1]);
    memcpy(xl[0], md[1], v_size * sizeof(uint64_t));
    qs->lanczos.n_iterations = 0 ;
    do
    {   lanczos_mul_MxN_Nx64(qs, md[1], v_size, xl[1]);
        lanczos_mul_trans_MxN_Nx64(qs, xl[1], md[4]);
        lanczos_mul_64xN_Nx64(qs, md[1], md[4], xl[1], sm[3]);
        lanczos_mul_64xN_Nx64(qs, md[4], md[4], xl[1], sm[5]);
        for (i = 0; i < 64 && !(sm[3][i]); ++i);
        if (i != 64)
        {   dim_0 = (qs_sm) lanczos_find_non_singular_sub(sm[3], sm[12],
                    sm[11], dim_1, sm[0]);
            if (dim_0)
            {   mask_0 = 0;
                for (i = 0; i < dim_0; ++i)
                    mask_0 |= (uint64_t) 1 << sm[11][i];
                for (i = 0; i < 64; ++i)
                    sm[7][i] = (sm[5][i] & mask_0) ^ sm[3][i];
                lanczos_mul_64x64_64x64(sm[0], sm[7], sm[7]);
                for (i = 0; i < 64; ++i)
                    sm[7][i] ^= (uint64_t) 1 << i;
                lanczos_mul_64x64_64x64(sm[1], sm[3], sm[8]);
                for (i = 0; i < 64; ++i)
                    sm[8][i] &= mask_0;
                lanczos_mul_64x64_64x64(sm[4], sm[1], sm[9]);
                for (i = 0; i < 64; ++i)
                    sm[9][i] ^= (uint64_t) 1 << i;
                lanczos_mul_64x64_64x64(sm[2], sm[9], sm[9]);
                for (i = 0; i < 64; ++i)
                    sm[10][i] = ((sm[6][i] & mask_1) ^ sm[4][i]) & mask_0;
                lanczos_mul_64x64_64x64(sm[9], sm[10], sm[9]);
                for (i = 0; i < qs->relations.length.now; ++i)
                    md[4][i] &= mask_0;
                lanczos_mul_Nx64_64x64_acc(qs, md[1], sm[7], xl[1], md[4]);
                lanczos_mul_Nx64_64x64_acc(qs, md[3], sm[8], xl[1], md[4]);
                lanczos_mul_Nx64_64x64_acc(qs, md[2], sm[9], xl[1], md[4]);
                lanczos_mul_64xN_Nx64(qs, md[1], xl[0], xl[1], sm[7]);
                lanczos_mul_64x64_64x64(sm[0], sm[7], sm[7]);
                lanczos_mul_Nx64_64x64_acc(qs, md[1], sm[7], xl[1], md[0]);
                tmp = md[2], md[2] = md[3], md[3] = md[1], md[1] = md[4], md[4] = tmp;
                tmp = sm[2], sm[2] = sm[1], sm[1] = sm[0], sm[0] = tmp;
                tmp = sm[4], sm[4] = sm[3], sm[3] = tmp;
                tmp = sm[6], sm[6] = sm[5], sm[5] = tmp;
                memcpy(sm[12], sm[11], 64 * sizeof(uint64_t));
                mask_1 = mask_0;
                dim_1 = dim_0;
            }
        }
    }
    while (++qs->lanczos.n_iterations < 2048 && dim_0 && i != 64);

    // it sometimes succeeds at 700+ iterations during the tests.

    // ===== answer finalization =====
    // result will be a simple array of the form [mask, null_rows...]
    // it's assumed that a null mask means "miss, no answer"

    *res = 0; // mask

    if (qs->lanczos.n_iterations < 2048)
    {   lanczos_mul_MxN_Nx64(qs, md[0], v_size, md[3]);
        lanczos_mul_MxN_Nx64(qs, md[1], v_size, md[2]);
        lanczos_combine_cols(qs, md[0], md[1], md[3], md[2]);
        lanczos_mul_MxN_Nx64(qs, md[0], v_size, md[1]);
        if (*md[1] == 0) // should hold (the buffer must contain only zero)
            if (memcmp(md[1], md[1] + 1, (v_size - 1) * sizeof(uint64_t)) == 0)
                for (i = 0; i < n_cols; *res |= (*md)[i++]);
    }

    // if no mask found : clears everything, otherwise leave [mask + null rows]
    char *open = (char *) md[*res != 0];
    char *close = (char *) qs->mem.now;
    qs->mem.now = memset(open, 0, close - open);

    return res;
}

void lanczos_reduce_matrix(qs_sheet *qs)
{   // a filtering is not always necessary to make "lanczos_block_worker" succeed :
    // - it writes to the relations [ Y lengths, relation counter ] will change
    qs_sm a, b, c, row, col, reduced_rows = qs->base.length, *counts;
    counts = (qs_sm*)memset(qs->buffer[1], 0,
                    qs->base.length * sizeof(*qs->buffer[1]));
    if (qs->sieve_again_perms)
        for (a = 0; a < qs->relations.length.now; ++a)
        {   // "snapshot" pointers, so they can be restored if "sieve again" is fired.
            qs->lanczos.snapshot[a].relation = qs->relations.data[a];
            qs->lanczos.snapshot[a].y_length = qs->relations.data[a]->Y.length;
        }
    for (a = 0; a < qs->relations.length.now; ++a)
        for (b = 0; b < qs->relations.data[a]->Y.length; ++b)
            ++counts[qs->relations.data[a]->Y.data[b]];
    // the counter of relations will change, store the original counter for debug purpose.
    qs->relations.length.prev = qs->relations.length.now;
    //
    do
    {   row = reduced_rows;
        do
        {   col = qs->relations.length.now;
            for (a = b = 0; a < qs->relations.length.now; ++a)
            {   struct qs_relation * const rel = qs->relations.data[a];
                for (c = 0; c < rel->Y.length && counts[rel->Y.data[c]] > 1; ++c);
                if (c < rel->Y.length)
                    for (; rel->Y.length;)
                        --counts[rel->Y.data[--rel->Y.length]];
                else
                    qs->relations.data[b++] =
                        qs->relations.data[a]; // relation is thrown.
            }
        }
        while (qs->relations.length.now = b, b != col);
        for (a = reduced_rows = 0; a < qs->base.length;
             reduced_rows += counts[a++] != 0);
        if (b = reduced_rows + 64,
            qs->relations.length.now > b)   // 64 extra rows
        {   for (a = b; a < qs->relations.length.now; ++a)
                for (struct qs_relation * const rel = qs->relations.data[a];
                     rel->Y.length;)
                    --counts[rel->Y.data[--rel->Y.length]];
            qs->relations.length.now = b;
        }
    }
    while (row != reduced_rows);
    DEBUG_LEVEL_4("[x] Maintenance of linear algebra reduces the relations from %u to %u.\n",
                  qs->relations.length.prev, qs->relations.length.now);
}

uint64_t *block_lanczos(qs_sheet *qs)
{   // the worker algorithm is probabilistic with high success rate.
    // it is interested in the Y field of the relations (to build its matrix).
    // it receives as input the relations (reduced or not, depending on the settings).

    if (qs->time.tick == qs->qs_state->params.qs_tick_end)
        return (uint64_t*)qs->mem.now ; // used for testing during the development.

    if (qs->lanczos.safe_length < qs->relations.length.now)
        qs->lanczos.safe_length = qs->relations.length.now;
    if (qs->lanczos.safe_length < qs->base.length)
        qs->lanczos.safe_length = qs->base.length;
    qs->lanczos.safe_length += 64 - qs->lanczos.safe_length % 64;
    //
    const qs_sm tries = 5, reduce_at = 3;
    uint64_t *res;
    //
    for(qs_sm i = 0; i < tries; ++i)
    {   if (i == reduce_at && !qs->lanczos.snapshot[0].relation)
            lanczos_reduce_matrix(qs);
        // This algorithm is likely to quickly report the success of the Quadratic Sieve,
        // just having to find in its smooth relations a subset of all the exponent vectors
        // such that the sum of their exponent vectors is the zero vector ...
        res = lanczos_block_worker(qs);
        if(*res)
        {   const char *ord = i == 0 ? "st" : i == 1 ? "nd" : i == 2 ? "rd" :
                              "th" ;
            DEBUG_LEVEL_4("Linear algebra passed on %u%s attempt after %u iterations.\n",
                          i + 1, ord, qs->lanczos.n_iterations);
            break;
        }
    }
    // When N is not completely factored by this result, another call to this
    // function will provide another result which can sometimes finish the job.
    return res; // This can be due (rarely) to a less favorable PRNG sequence.
}

int Xmain(int argc, const char *argv[])
{

    // Default state (the integer factorization software don't use global variables).
    state state = {{0}};

    // Random number generator consistent across platforms.
    state.params.rand.seed = 0x2236b69a7d223bd;

    // The software is silent when there is no terminal.
    state.params.tty = isatty(STDOUT_FILENO) != 0 ;
    state.params.verbose = state.params.tty;

    // Read the command line arguments.
    for (int i = 1; i < argc; ++i)
        if (!(i + 3 < argc && read_key_and_3_values(argv + i, &state) &&
              (i += 3)))
            if (!(i + 2 < argc && read_key_and_2_values(argv + i, &state) &&
                  (i += 2)))
                if (!(i + 1 < argc && read_key_value(argv + i, &state) && ++i))
                    if (!(validate_string_number(argv[i], &state) ||
                          read_flags(argv + i, &state)))
                        fprintf(stderr, "%s: Unknown argument '%s'.\n", argv[0],
                                (state.code = 2, argv[i]));

    state.params.rand.seed += !state.params.rand.seed; // Optional.

    if (state.params.help)
        print_help(argv[0]); // Option --help or -h was found.
    else if (state.code == 0 && *state.params.demand)
        generate_input_file(&state); // Generate a factorization demand.
    else if (state.code == 0 && prepare_file_descriptors(&state))
        process_multi(argc, argv, &state); // Process the request(s).
    else
        fprintf(stderr,
                "Use '--help' for more information about Factorization Software v2.0.0, released February 1, 2025.\n");

    return state.code;
}

} // end namespace

#include "headers.h"

namespace CSL_LISP
{

static LispObject* raddr = nullptr;

// I am happy to make the interface here rather inefficient because the
// time that will be spent factorizing will dominate - so SIMPLE code here
// will suffice.

void string_to_csl(const char* s)
{   LispObject r = make_string(s);
    r = Lexplodec(nil, r);
    r = Lcompress(nil, r);    // Should now be a number!
    *raddr = cons(r, *raddr);
}


LispObject Lsieve_factor(LispObject env, LispObject n)
{   SingleValued fn;
    char value[500];
    n = Lexploden(nil, n);
    size_t i = 0;
    while (is_cons(n) && i<sizeof(value)-1)
    {   value[i++] = int_of_fixnum(car(n));
        n = cdr(n);
    }
    value[i] = 0;
    if (is_cons(n)) return aerror("input value too large for sieve-factor");
    const char* args[] =
    {   "factor",
        "-v",
        "0",
        "-f",
        value        
    };
    LispObject r = nil;
    raddr = &r;
    Xmain(sizeof(args)/sizeof(args[0]), args);
    return Lreverse(nil, r);
}

} // end namespace

// end of qsieve.cpp
