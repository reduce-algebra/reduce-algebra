#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>

#define LENGTH 50000

uint32_t a[LENGTH], b[LENGTH], c[2*LENGTH+1];

uint32_t r32()
{   uint32_t r = rand();
    r = (r<<11) ^ rand();
    return (r<<11) ^ rand();
}

int main()
{   for (int i=0; i<LENGTH; i++)
    {   a[i] = r32();
        b[i] = r32();
    }
    for (int i=0; i<2*LENGTH+1; i++)
        c[i] = 0;
    for (int i=0; i<LENGTH; i++)
    {   uint32_t carry = 0;
        for (int j=0; j<LENGTH; j++)
        {   int k = i + j;
            uint64_t w = (uint64_t)a[i]*(uint64_t)b[j] + c[k] + carry;
            c[k] = (uint32_t)w;
            carry = (uint32_t)(w >> 32);
        }
        c[i+LENGTH] = carry;
    }            
    uint32_t z = 0;
    for (int i=0; i<2*LENGTH+1; i++) z ^= c[i];
    printf("%.llx\n", (long long)z);
    return 0;
}
