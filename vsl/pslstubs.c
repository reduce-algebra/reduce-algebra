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

