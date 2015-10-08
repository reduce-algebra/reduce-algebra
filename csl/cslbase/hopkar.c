// Hopcroft-Karp algorithm for maximum matchings.

// This code is based on
// https://github.com/indy256/codelibrary/blob/master/cpp/MaxMatching.cpp
// which has the following statement regarding its licensing terms:
// 
//@ This is free and unencumbered software released into the public domain.
//@
//@ Anyone is free to copy, modify, publish, use, compile, sell, or
//@ distribute this software, either in source code form or as a compiled
//@ binary, for any purpose, commercial or non-commercial, and by any
//@ means.
//@
//@ In jurisdictions that recognize copyright laws, the author or authors
//@ of this software dedicate any and all copyright interest in the
//@ software to the public domain. We make this dedication for the benefit
//@ of the public at large and to the detriment of our heirs and
//@ successors. We intend this dedication to be an overt act of
//@ relinquishment in perpetuity of all present and future rights to this
//@ software under copyright law.
//@
//@ THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
//@ EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
//@ MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
//@ IN NO EVENT SHALL THE AUTHORS BE LIABLE FOR ANY CLAIM, DAMAGES OR
//@ OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE,
//@ ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
//@ OTHER DEALINGS IN THE SOFTWARE.
//@
//@ For more information, please refer to <http://unlicense.org>
//
// "indy256" is otherwise Andrey Naumenko, and this comment is to thank
// him for making his code available.   A C Norman, October 2015.

// $Id$

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include "cuckoo.h"

#define MAXN1  50000   // limit size of first set (A)
#define MAXN2  50000   // limit size of second set (B)
#define MAXM  150000   // limit the number of edges joining A to B.

static int n1, n2, edges, last[MAXN1], prev[MAXM], head[MAXM];
static int matching[MAXN2], dist[MAXN1], Q[MAXN1];
static int used[MAXN1], vis[MAXN1];

// A trivial library routine. In the C++ code thas was provided by the STL.
static void fill(int *p, int *q, int val)
{
    while (p != q) *p++ = val;
}

// Specify the size of the sets A and B, and arrange that there are no
// edges present at this stage.

void init(int _n1, int _n2)
{
    n1 = _n1;
    n2 = _n2;
    edges = 0;
    fill(last, last + n1, -1);
}

// Add an edge from vertex u in set A to vertex v in set B.

void addEdge(int u, int v)
{
    head[edges] = v;
    prev[edges] = last[u];
    last[u] = edges++;
}

// Breadth-first search to partition the graph into layers.

void bfs()
{
    fill(dist, dist + n1, -1);
    int sizeQ = 0, u, i, e;
    for (u = 0; u < n1; ++u)
    {   if (!used[u])
        {   Q[sizeQ++] = u;
            dist[u] = 0;
        }
    }
    for (i = 0; i < sizeQ; i++)
    {   int u1 = Q[i];
        for (e = last[u1]; e >= 0; e = prev[e])
        {   int u2 = matching[head[e]];
            if (u2 >= 0 && dist[u2] < 0)
            {   dist[u2] = dist[u1] + 1;
                Q[sizeQ++] = u2;
            }
        }
    }
}

// Depth-first search to find vertex-disjoint augmenting paths.

int dfs(int u1)
{
    int e;
    vis[u1] = 1;
    for (e = last[u1]; e >= 0; e = prev[e])
    {   int v = head[e];
        int u2 = matching[v];
        if (u2 < 0 || !vis[u2] && dist[u2] == dist[u1] + 1 && dfs(u2))
        {   matching[v] = u1;
            used[u1] = 1;
            return 1;
        }
    }
    return 0;
}

// Driver code which alternates use of the breadth-first and depth-first
// searches to end up with a maximum matching by augmenting whatever was
// there at the start. Returns the number of edges present in that matching.

int maxMatching()
{
    int res, u;
    fill(used, used + n1, 0);
    fill(matching, matching + n2, -1);
    for (res = 0;;)
    {   bfs();
        fill(vis, vis + n1, 0);
        int f = 0;
        for (u = 0; u < n1; ++u)
            if (!used[u] && dfs(u)) ++f;
        if (!f) return res;
        res += f;
    }
}

// Now an adapter that takes my hashing problem and maps it onto the
// calls needed here. The input is a set of keys, a table size and two
// parameters that control details of the hashing. It then has the hash
// table it is tryng to create, which it fills in if it can find a perfect
// way to do so.

// This tries to insert all the keys in "items" into the hash-table "table"
// and it returns a non-zero result if it succeeds.

int cuckoo_insert_all(
    uint32_t *items,
    int item_count,
    cuckoo_importance *importance,
    void *table,
    int hash_item_size,
    int table_size,
    cuckoo_get_key *get_key,
    cuckoo_set_key *set_key,
    uint32_t modulus2,
    uint32_t offset2)
{
    int i;
    init(item_count, table_size);
    for (i=0; i<item_count; i++)
    {   uint32_t key = items[i];
        uint32_t h1 = key % table_size;
        uint32_t h2 = key % modulus2 + offset2;
        uint32_t h3 = (h1 + h2) % table_size;
        int imp = (*importance)(key);
        switch (imp)
        {
    default:
            addEdge(i, (int)h3);
            // drop through
    case CUCKOO_IMPORTANT:
            addEdge(i, (int)h2);
            // drop through
    case CUCKOO_VITAL:
            addEdge(i, (int)h1);
            break;
        }
    }
    i = maxMatching();
//  printf("Found matching of size %d (wanted %d) m = %d o = %d\n",
//         i, item_count, (int)modulus2, (int)offset2);
    if (i != item_count) return 0;
//
// Extract details of the matching and put into the hash table
    memset(table, 0, hash_item_size*table_size);
    fill(used, used + n1, 0);
    for (i=0; i<n2; i++)
    {   int j = matching[i], k;
        if (j == -1) continue;
        if (j >= n1)
        {   printf("internal failure, j > %d\n", n1);
            exit(1);
        }
        used[j] = 1;
        k = items[j];
//      printf("Set hash table entry %d to %d/%x\n", j, k, k);
        set_key((char *)table + hash_item_size*i, k);
    }
#if DEBUG
// Now in a spirit of neurosis I will check whether everything can be
// looked up happily...
    for (i=0; i<item_count; i++)
    {   uint32_t key = items[i];
        uint32_t h1 = key % table_size;
        uint32_t h2 = key % modulus2 + offset2;
        uint32_t h3 = (h1 + h2) % table_size;
        uint32_t k1;
        if (used[i] &&
            (key == get_key((char *)table + hash_item_size*h1) ||
             key == get_key((char *)table + hash_item_size*h2) ||
             key == get_key((char *)table + hash_item_size*h3))) continue;
        printf("Key %d/%x not found in table\n");
        printf("%d %d %d\n", table_size, modulus2, offset2);
        for (i=0; i<table_size; i++)
            printf("%d: %d\n", i, get_key((char *)table + hash_item_size*i));
        exit(1);
    }
#endif
    return 1;
}

#ifdef TEST

// The code here can be compiled with "TEST" predefined and that will
// set up a small test of its behaviour... and the code for the test can
// also serve as an illustration of how it could be used.

uint32_t keys[] =
{
    1,
    3,
    9,
    27,
    81,
    243,
    729,
    2187,
    6561,
    19683,
    59049
};

uint32_t hash[1000];

int importance(uint32_t key)
{
    return CUCKOO_STANDARD;
}

uint32_t get_key(void *p)
{
    return *(uint32_t *)p;
}

void set_key(void *p, uint32_t k)
{
    *(uint32_t *)p = k;
}

int main(int argc, char *argv[])
{
    int keycount = sizeof(keys)/sizeof(keys[0]);
    int hashsize = keycount+7;
    int i;
    int modulus2, offset2;
    for (modulus2 = 3; modulus2 < hashsize; modulus2++)
        for (offset2 = 0; modulus2+offset2<hashsize; offset2++)
            if (cuckoo_insert_all(
                keys,
                keycount,
                importance,
                hash,
                sizeof(hash[0]),
                hashsize,
                get_key,
                set_key,
                modulus2,
                offset2) != 0) goto found;
    printf("No solution found\n");
    exit(0);
found:
    printf("OK with modulus2 = %d offset2 = %d\n", modulus2, offset2);
// Display everything...
    for (i=0; i<keycount; i++)
    {   uint32_t key = keys[i];
        uint32_t h1 = key % hashsize;
        uint32_t h2 = key % modulus2 + offset2;
        uint32_t h3 = (h1 + h2) % hashsize;
// Each key and the three locations that the key could legally be placed.
        printf("%d: %d... %d %d %d\n", i, key, h1, h2, h3);
    }
// The internal tables left behind by the code that found a match.
    for (i=0; i<n1; i++)
        printf("%d: last:%d dist:%d Q:%d used:%d vis:%d\n",
            i, last[i], dist[i], Q[i], used[i], vis[i]);
    for (i=0; i<n2; i++)
        printf("%d: matching:%d\n", i, matching[i]);
    for (i=0; i<edges; i++)
        printf("%d: head:%d prev:%d\n", i, head[i], prev[i]);
    printf("Done\n");
    return 0;
}

#endif // TEST

// end of hopkar.c
