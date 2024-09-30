// canary.c

// To small to warrant license terms! But feel free to do what you like
// with this!

// I compile a binary from this file and place it in a build directory
// then if I encounter that directory when running on a machine that
// supports the architecture concerned that fact will be verified
// if I can execute this tiny program.

#include <stdio.h>

int main()
{   printf("Cheep cheep\n");
    return 0;
}

// end of canary.c
