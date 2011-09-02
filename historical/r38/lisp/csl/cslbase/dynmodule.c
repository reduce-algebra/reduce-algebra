/*
 * dynmodule.c
 *
 * This goes with dyndemo.c to form a demonstration of dynamic loading
 * of code. This file must be compiled as a DLL (or whatever it takes
 * to make it a candidate for dynamic loading).
 */

/* Signature: 503dd7c5 23-Jul-2005 */

#include <stdio.h>

extern int variable_in_base;
extern int function_in_base(int x);

int callme(int x)
{
/*
 * Note that on Windows this attempt to use a VARIABLE that is defined in
 * the base application will give nonsense results. It does not fail in
 * the sense that it does not report a linker error, but the location
 * referenced as "variable_in_base" will NOT be the one that I wanted.
 * Or rather expected! Thus to actieve the desired effect it seems
 * necessary to pass a reference to the variable to an initialisation
 * function here, and then store it...
 */
    printf("variable in base = %.8x @ %p\n",
        variable_in_base, &variable_in_base);
    printf("function in base = %p\n",
        function_in_base);
    return 3*function_in_base(x) + 1;
}

/* end of dynmodule.c */


