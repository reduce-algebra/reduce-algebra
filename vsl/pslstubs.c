/* Stubs for functions not provided on various operating systems */


#ifdef __CYGWIN__

int profil()
{   return 0;
}

int pthread_setaffinity_np()
{   return 0;
}

int pthread_getaffinity_np()
{   return 0;
}

int pthread_rwlockattr_getkind_np()
{   return 0;
}

int pthread_rwlockattr_setkind_np()
{   return 0;
}

#endif

#ifdef __clang__

/* This is intended to be for Macintosh */

int profil()
{   return 0;
}

int pthread_yield()
{   return 0;
}

int pthread_setaffinity_np()
{   return 0;
}

int pthread_getaffinity_np()
{   return 0;
}

int pthread_rwlockattr_getkind_np()
{   return 0;
}

int pthread_rwlockattr_setkind_np()
{   return 0;
}

int pthread_setschedprio()
{   return 0;
}

#include <stdio.h>

FILE * unixstdin, * unixstdout, * unixstderr, * unixtty;

int unixnull[2], unixeof[2];

#endif

