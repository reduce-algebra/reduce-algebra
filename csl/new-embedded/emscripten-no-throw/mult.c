#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>

#define LENGTH 50000

uint64_t a[LENGTH], b[LENGTH], c[2*LENGTH+1];

uint64_t seed = 1;

#define A 6364136223846793005ULL
#define B 1442695040888963407ULL

uint64_t r64()
{   seed = A*seed + B;
    return seed;
}

int main()
{   for (int i=0; i<LENGTH; i++)
    {   a[i] = r64();
        b[i] = r64();
    }
    for (int i=0; i<2*LENGTH+1; i++)
        c[i] = 0;
    for (int i=0; i<LENGTH; i++)
    {   uint64_t carry = 0;
        for (int j=0; j<LENGTH; j++)
        {   int k = i + j;
            __uint128_t w = (__uint128_t)a[i]*(__uint128_t)b[j] + c[k] + carry;
            c[k] = (uint64_t)w;
            carry = (uint64_t)(w >> 64);
        }
        c[i+LENGTH] = carry;
    }            
    uint64_t z = 0;
    for (int i=0; i<2*LENGTH+1; i++) z ^= c[i];
    printf("%.llx\n", z);
    return 0;
}
