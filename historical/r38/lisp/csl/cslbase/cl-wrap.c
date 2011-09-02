/* cl-wrap.c                       Copyright (C) 2006-2007 Codemist Ltd */

/*
 * This code may be used and modified, and redistributed in binary
 * or source form, subject to the "CCL Public License", which should
 * accompany it. This license is a variant on the BSD license, and thus
 * permits use of code derived from this in either open and commercial
 * projects: but it does require that updates to this code be made
 * available back to the originators of the package.
 * Before merging other code in with this or linking this code
 * with other packages or libraries please check that the license terms
 * of the other material are compatible with those of this.
 */

/* Signature: 42dde825 13-Aug-2007 */


/*
 * This is a rather trivial wrapper program that maps Unix-style
 * "-o" options to a compiler onto the corresponding forms that
 * Microsoft's compiler wants. As of early 2006 the Microsoft compilers
 * in their SDK still support "-o", but they flag it as deprecated and
 * not liable to be supported in some future versions, so the treatment
 * here is for future-proofing not a matter of immediate urgency.
 *
 * This arises because the GNU "automake" tools insert "-o" at places
 * in their generated Makefile and it is not clear how to make them
 * use some other form.
 */

#include <stdio.h>
#include <stdlib.h>

static char newcommand[1000];
static char newcommand1[2000];
static int ncn = 0;

int main(int argc, char *argv[])
{
    int i, j;
    ncn = 0;
    ncn = sprintf(newcommand+ncn, "cl");
    for (i=1; i<argc; i++)
    {   char *a = argv[i];
/* Have a go at avoiding buffer overflow */
        if (ncn + strlen(a) > sizeof(newcommand)-10)
        {   fprintf(stderr, "command-line too long\n");
            exit(1);
        }
/* If the argument is not "-o" just pass it on */
        if (strcmp(a, "-o") != 0)
        {   ncn += sprintf(newcommand+ncn, " %s", a);
            continue;
        }
/* Check that there is a sensible thing after the "-o" */
        if (i+1==argc)
        {   fprintf(stderr, "-o at end of args\n");
            ncn += sprintf(newcommand+ncn, " -o");
            continue;
        }
        a = argv[++i];
        j = strlen(a);
/* Have a go at avoiding buffer overflow */
        if (ncn + j > sizeof(newcommand)-10)
        {   fprintf(stderr, "command-line too long\n");
            exit(1);
        }
        if (j < 4)
        {   fprintf(stderr, "-o with short arg (%s)\n", a);
            ncn += sprintf(newcommand+ncn, " -o %s", a);
            continue;
        }
/* Map it if that item end if ".exe", ".com" or ".obj" */
        if (strcmp(a+j-4, ".exe")== 0 ||
            strcmp(a+j-4, ".com")==0)
        {   ncn += sprintf(newcommand+ncn, " -Fe%s", a);
            continue;
        }
        else if (strcmp(a+j-4, ".obj")== 0)
        {   ncn += sprintf(newcommand+ncn, " -Fo%s", a);
            continue;
        }
        else
        {   fprintf(stderr, "-o arg with unknown extension (%s)\n", a);
            ncn += sprintf(newcommand+ncn, " -o %s", a);
            continue;
        }
    }
/* Obey the generated command-line */
    newcommand[ncn] = 0;
/* Well since it is passed to bash I need to double backslashes */
    j = 0;
    for (i=0; i<ncn; i++)
    {   int c = newcommand[i];
        newcommand1[j++] = c;
        if (c == '\\') newcommand1[j++] = c;
    }
    newcommand1[j] = 0;
    return system(newcommand1);
}

/* end of cl-wrap.c */
