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
// him for making his code available. I changed the file to include the
// above copyright/license statement and have make the static variable
// thread local. I added the subversion "Id" line too. But the guts of the
// code is just as it originally was.
//
//                                    A C Norman, October 2015.

// $Id$

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include "cuckoo.h"

#define MAXN1  50000   // limit size of first set (A)
#define MAXN2  50000   // limit size of second set (B)
#define MAXM  150000   // limit the number of edges joining A to B.

// ACN has made these variable Thread Local.
static __thread int n1, n2, edges, last[MAXN1], prev[MAXM], head[MAXM];
static __thread int matching[MAXN2], dist[MAXN1], Q[MAXN1];
static __thread int used[MAXN1], vis[MAXN1];

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
    if (DEBUG) logprintf("Hopcroft-Karp with size = %d by %d\n", n1, n2);
    fill(last, last + n1, -1);
}

// Add an edge from vertex u in set A to vertex v in set B.

void addEdge(int u, int v)
{
    head[edges] = v;
    prev[edges] = last[u];
    if (DEBUG) logprintf("addEdge %d from %d to %d\n", edges, u, v);
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

// end of hopkar.c
