#include <inttypes.h>
#include <stdint.h>
#include <stdio.h>

/*
 * This will provide a range of functions with various signatures that
 * can be tried.
 */

static int32_t k = 12345;

/*
 * First a series of functions that illustrate support for the
 * various possible return types. These are int32, in64, double and string.
 */

void vff()
{
    printf("void vff()\n");
}

int32_t i32ff()
{
    printf("int32_t i32ff()\n");
    return k++;
}

int64_t i64ff()
{
    printf("int64_t i64ff()\n");
    return (int64_t)k++ * (int64_t)100000000;
}

double dff()
{
    printf("double dff()\n");
    return (double)k++ + 0.12345;
}

char buffer[100];

char *sff()
{
    printf("double sff()\n");
    sprintf(buffer, "SFF%d!", (int)k++);
    return buffer;
}

/*
 * Now a series that illustrate passing various sorts of argument.
 * Here I will make the function merely print its argument and so I
 * can cope with not having any result.
 */

void vffi32(int32_t a)
{
    printf("vffi32(%d)\n", (int)a);
}

void vffi64(int64_t a)
{
    printf("vffi64(%" PRId64 ")\n", a);
}

void vffd(double a)
{
    printf("vffd(%18.12g)\n", a);
}

void vffs(char *a)
{
    printf("vffs(\"%s\")\n", a);
}

/* End of test loadable module */
