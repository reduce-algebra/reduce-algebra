/*
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
% File:         pslstubs.c
% Description:  Code to help with portability across operating systems
% Author:       Arthur Norman
% Created:      February 2018
% Mode:         Text
% Status:       Open Source: BSD License
%
% (c) Copyright 2018 A C Norman.
%
% Redistribution and use in source and binary forms, with or without
% modification, are permitted provided that the following conditions are met:
%
%    * Redistributions of source code must retain the relevant copyright
%      notice, this list of conditions and the following disclaimer.
%    * Redistributions in binary form must reproduce the above copyright
%      notice, this list of conditions and the following disclaimer in the
%      documentation and/or other materials provided with the distribution.
%
% THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
% AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
% THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
% PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNERS OR
% CONTRIBUTORS
% BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
% CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
% SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
% INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
% CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
% ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
% POSSIBILITY OF SUCH DAMAGE.
%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
*/


#ifdef __CYGWIN__

/* At present the code here is not expected to WORK under Cygwin - the
 * definitions here are to let it compile and link. Well because Cygwin
 * provides a world rather like Linux I hope to be able to get it going
 * without very much pain.
 */

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

#endif // __CYGWIN__

#ifdef __clang__

/* At present the code here is not expected to WORK on a Mac - the
 * definitions here are to let it compile and link. But there are
 * alternative files in the PSL distribution that I should be able to
 * merge in stuff from, and anyway at this level the Macintosh is being
 * used as a fairly straightforward variant on BSD, so there is good
 * reason to be hopeful.
 */


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

#endif // __clang__

#ifdef __linux__

/* You might have expected the Linux support to be the easiest one. However
 * in seeking portability of everything I have ended up needing to provide
 * stubs here the link from calls to names with underscores on them to
 * calls without! This may not end up being essential, but I observe that
 * already there are a fair number of system functions that are called
 * via trivial interface code of this sort (eg all the elementary functions)
 * so this does not breach the spirit of the PSL implementation too
 * badly.
 */


void _sigrelse()
{   return sigrelse();
}

void _ctime()
{   return ctime();
}

void _fopen()
{   return fopen();
}

void _fclose()
{   return fclose();
}

void _fread()
{   return fread();
}

void _fputc()
{   return fputc();
}

void _fgetc()
{   return fgetc();
}

void _fgets()
{   return fgets();
}

void _fwrite()
{   return fwrite();
}

void _fflush()
{   return fflush();
}

void _fseek()
{   return fseek();
}

void _clearerr()
{   return clearerr();
}

void _putw()
{   return putw();
}

void _signal()
{   return signal();
}

void _sleep()
{   return sleep();
}

void _setlinebuf()
{   return setlinebuf();
}

void _getpid()
{   return getpid();
}

void _gethostid()
{   return gethostid();
}

void _writesocket()
{   return writesocket();
}

void _fork()
{   return fork();
}

void _wait()
{   return wait();
}

void _popen()
{   return popen();
}

void _pclose()
{   return pclose();
}

void _shmctl()
{   return shmctl();
}

void _shmget()
{   return shmget();
}

void _shmat()
{   return shmat();
}

void _shmdt()
{   return shmdt();
}

void _semctl()
{   return semctl();
}

void _semget()
{   return semget();
}

void _semop()
{   return semop();
}

void _dlopen()
{   return dlopen();
}

void _dlerror()
{   return dlerror();
}

void _dlsym()
{   return dlsym();
}

void _dlclose()
{   return dlclose();
}

void _profil()
{   return profil();
}

void _pthread_create()
{   return pthread_create();
}

void _pthread_exit()
{   return pthread_exit();
}

void _pthread_join()
{   return pthread_join();
}

void _pthread_detach()
{   return pthread_detach();
}

void _pthread_self()
{   return pthread_self();
}

void _pthread_equal()
{   return pthread_equal();
}

void _pthread_attr_init()
{   return pthread_attr_init();
}

void _pthread_attr_destroy()
{   return pthread_attr_destroy();
}

void _pthread_attr_setdetachstate()
{   return pthread_attr_setdetachstate();
}

void _pthread_attr_getguardsize()
{   return pthread_attr_getguardsize();
}

void _pthread_attr_setguardsize()
{   return pthread_attr_setguardsize();
}

void _pthread_attr_getschedparam()
{   return pthread_attr_getschedparam();
}

void _pthread_attr_setschedparam()
{   return pthread_attr_setschedparam();
}

void _pthread_attr_getschedpolicy()
{   return pthread_attr_getschedpolicy();
}

void _pthread_attr_setschedpolicy()
{   return pthread_attr_setschedpolicy();
}

void _pthread_attr_getinheritsched()
{   return pthread_attr_getinheritsched();
}

void _pthread_attr_setinheritsched()
{   return pthread_attr_setinheritsched();
}

void _pthread_attr_getscope()
{   return pthread_attr_getscope();
}

void _pthread_attr_setscope()
{   return pthread_attr_setscope();
}

void _pthread_attr_getstack()
{   return pthread_attr_getstack();
}

void _pthread_attr_setstack()
{   return pthread_attr_setstack();
}

void _pthread_attr_getstacksize()
{   return pthread_attr_getstacksize();
}

void _pthread_attr_setstacksize()
{   return pthread_attr_setstacksize();
}

void _pthread_setschedparam()
{   return pthread_setschedparam();
}

void _pthread_getschedparam()
{   return pthread_getschedparam();
}

void _pthread_setschedprio()
{   return pthread_setschedprio();
}

void _pthread_getconcurrency()
{   return pthread_getconcurrency();
}

void _pthread_yield()
{   return pthread_yield();
}

void _pthread_setaffinity_np()
{   return pthread_setaffinity_np();
}

void _pthread_getaffinity_np()
{   return pthread_getaffinity_np();
}

void _pthread_once()
{   return pthread_once();
}

void _pthread_setcancelstate()
{   return pthread_setcancelstate();
}

void _pthread_setcanceltype()
{   return pthread_setcanceltype();
}

void _pthread_cancel()
{   return pthread_cancel();
}

void _pthread_testcancel()
{   return pthread_testcancel();
}

void _pthread_mutex_init()
{   return pthread_mutex_init();
}

void _pthread_mutex_destroy()
{   return pthread_mutex_destroy();
}

void _pthread_mutex_trylock()
{   return pthread_mutex_trylock();
}

void _pthread_mutex_lock()
{   return pthread_mutex_lock();
}

void _pthread_mutex_unlock()
{   return pthread_mutex_unlock();
}

void _pthread_mutexattr_init()
{   return pthread_mutexattr_init();
}

void _pthread_mutexattr_destroy()
{   return pthread_mutexattr_destroy();
}

void _pthread_mutexattr_getpshared()
{   return pthread_mutexattr_getpshared();
}

void _pthread_mutexattr_setpshared()
{   return pthread_mutexattr_setpshared();
}

void _pthread_rwlock_unlock()
{   return pthread_rwlock_unlock();
}

void _pthread_rwlockattr_init()
{   return pthread_rwlockattr_init();
}

void _pthread_rwlockattr_destroy()
{   return pthread_rwlockattr_destroy();
}

void _pthread_rwlockattr_getpshared()
{   return pthread_rwlockattr_getpshared();
}

void _pthread_rwlockattr_setpshared()
{   return pthread_rwlockattr_setpshared();
}

void _pthread_rwlockattr_getkind_np()
{   return pthread_rwlockattr_getkind_np();
}

void _pthread_rwlockattr_setkind_np()
{   return pthread_rwlockattr_setkind_np();
}

void _pthread_cond_init()
{   return pthread_cond_init();
}

void _pthread_cond_destroy()
{   return pthread_cond_destroy();
}

void _pthread_cond_signal()
{   return pthread_cond_signal();
}

void _pthread_cond_broadcast()
{   return pthread_cond_broadcast();
}

void _pthread_cond_wait()
{   return pthread_cond_wait();
}

void _pthread_cond_timedwait()
{   return pthread_cond_timedwait();
}

void _pthread_condattr_init()
{   return pthread_condattr_init();
}

void _pthread_condattr_destroy()
{   return pthread_condattr_destroy();
}

void _pthread_condattr_getpshared()
{   return pthread_condattr_getpshared();
}

void _pthread_condattr_setpshared()
{   return pthread_condattr_setpshared();
}

void _pthread_key_create()
{   return pthread_key_create();
}

void _pthread_key_delete()
{   return pthread_key_delete();
}

void _pthread_getspecific()
{   return pthread_getspecific();
}

void _pthread_setspecific()
{   return pthread_setspecific();
}

void _pthread_atfork()
{   return pthread_atfork();
}


#endif /* __linux__ */

/* end of pslstubs.c */

