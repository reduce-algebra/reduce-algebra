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
 *
 * Furthermore the little functions here will generally compile into just
 * a simple jump instructions:
 *    _foo: jmp foo@PLT
 * and if the target concerned ends up reasonably close that will end up
 * as a pc-relative jump - while if it is seriously remote it will be a
 * jump via a memory location that contains the long address. This is not
 * a severe burden in any case, because the functions that are called will
 * do enough that their costs swamp that of the extra jump.
 */

#include <stdio.h>
#define __USE_XOPEN_EXTENDED
#define __USE_GNU
#include <signal.h>
#include <sys/types.h>
#include <unistd.h>
#include <wait.h>
#include <pthread.h>
#include <time.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/sem.h>
#include <dlfcn.h>


/* sigrelse is obsolete - use sigaction etc instead... */
int _sigrelse(int s)
{   return sigrelse(s);
}

char *_ctime(const time_t *t)
{   return ctime(t);
}

FILE *_fopen(const char *name, const char *mode)
{   return fopen(name, mode);
}

int _fclose(FILE *s)
{   return fclose(s);
}

size_t _fread(void *p, size_t n, size_t m, FILE *s)
{   return fread(p, n, m, s);
}

int _fputc(int c, FILE *s)
{   return putc(c, s);
}

int _fgetc(FILE *s)
{   return getc(s);
}

char *_fgets(char *s, int n, FILE *f)
{   return fgets(s, n, f);
}

size_t _fwrite(void *p, size_t n, size_t m, FILE *s)
{   return fwrite(p, n, m, s);
}

int _fflush(FILE *f)
{   return fflush(f);
}

int _fseek(FILE *s, long o, int w)
{   return fseek(s, o, w);
}

void _clearerr(FILE *s)
{   clearerr(s);
}

int _putw(int w, FILE *s)
{   return putw(w, s);
}

sighandler_t _signal(int s, sighandler_t h)
{   return signal(s, h);
}

unsigned int _sleep(unsigned int n)
{   return sleep(n);
}

void _setlinebuf(FILE *s)
{   setlinebuf(s);
}

pid_t _getpid()
{   return getpid();
}

long _gethostid()
{   return gethostid();
}

pid_t _fork()
{   return fork();
}

pid_t _wait(int *w)
{   return wait(w);
}

FILE *_popen(const char *s, const char *t)
{   return popen(s, t);
}

int _pclose(FILE *s)
{   return pclose(s);
}

int _shmctl(int id, int c, struct shmid_ds *d)
{   return shmctl(id, c, d);
}

int _shmget(key_t k, size_t n, int f)
{   return shmget(k, n, f);
}

void *_shmat(int id, const void *ad, int f)
{   return shmat(id, ad, f);
}

int _shmdt(const void *ad)
{   return shmdt(ad);
}

int _semctl(int id, int num, int cmd, ...)
{   return semctl(id, num, cmd); /* Extra arg not supported here yet */
}

int _semget(key_t k, int n, int f)
{   return semget(k, n, f);
}

int _semop(int id, struct sembuf *b, size_t n)
{   return semop(id, b, n);
}

void *_dlopen(const char *name, int f)
{   return dlopen(name, f);
}

char *_dlerror()
{   return dlerror();
}

void *_dlsym(void *h, const char *s)
{   return dlsym(h, s);
}

int _dlclose(void *h)
{   return dlclose(h);
}

int _profil(unsigned short *b, size_t n, size_t o, unsigned int s)
{   return profil(b, n, o, s);
}

int _pthread_create(pthread_t *newthr, pthread_attr_t *attrs,
                    void *(*startup)(void *), void *arg)
{   return pthread_create(newthr, attrs, startup, arg);
}

void _pthread_exit(void *retval)
{   pthread_exit(retval);
}

int _pthread_join(pthread_t thr, void **ret)
{   return pthread_join(thr, ret);
}

int _pthread_detach(pthread_t thr)
{   return pthread_detach(thr);
}

pthread_t _pthread_self()
{   return pthread_self();
}

int _pthread_equal(pthread_t t1, pthread_t t2)
{   return pthread_equal(t1, t2);
}

int _pthread_attr_init(pthread_attr_t *atts)
{   return pthread_attr_init(atts);
}

int _pthread_attr_destroy(pthread_attr_t *atts)
{   return pthread_attr_destroy(atts);
}

int _pthread_attr_setdetachstate(pthread_attr_t *atts, int det)
{   return pthread_attr_setdetachstate(atts, det);
}

int _pthread_attr_getguardsize(const pthread_attr_t *atts, size_t *gs)
{   return pthread_attr_getguardsize(atts, gs);
}

int _pthread_attr_setguardsize(pthread_attr_t *atts, size_t gs)
{   return pthread_attr_setguardsize(atts, gs);
}

int _pthread_attr_getschedparam(const pthread_attr_t *atts, struct sched_param *ss)
{   return pthread_attr_getschedparam(atts, ss);
}

int _pthread_attr_setschedparam(pthread_attr_t *atts, const struct sched_param *ss)
{   return pthread_attr_setschedparam(atts, ss);
}

int _pthread_attr_getschedpolicy(const pthread_attr_t *atts, int *rp)
{   return pthread_attr_getschedpolicy(atts, rp);
}

int _pthread_attr_setschedpolicy(pthread_attr_t *atts, int rp)
{   return pthread_attr_setschedpolicy(atts, rp);
}

int _pthread_attr_getinheritsched(const pthread_attr_t *atts, int *ri)
{   return pthread_attr_getinheritsched(atts, ri);
}

int _pthread_attr_setinheritsched(pthread_attr_t *atts, int ri)
{   return pthread_attr_setinheritsched(atts, ri);
}

int _pthread_attr_getscope(const pthread_attr_t *atts, int *rs)
{   return pthread_attr_getscope(atts, rs);
}

int _pthread_attr_setscope(pthread_attr_t *atts, int rs)
{   return pthread_attr_setscope(atts, rs);
}

int _pthread_attr_getstack()
{   return pthread_attr_getstack();
}

int _pthread_attr_setstack()
{   return pthread_attr_setstack();
}

int _pthread_attr_getstacksize()
{   return pthread_attr_getstacksize();
}

int _pthread_attr_setstacksize()
{   return pthread_attr_setstacksize();
}

int _pthread_setschedparam()
{   return pthread_setschedparam();
}

int _pthread_getschedparam()
{   return pthread_getschedparam();
}

int _pthread_setschedprio()
{   return pthread_setschedprio();
}

int _pthread_getconcurrency()
{   return pthread_getconcurrency();
}

int _pthread_yield()
{   return pthread_yield();
}

int _pthread_setaffinity_np()
{   return pthread_setaffinity_np();
}

int _pthread_getaffinity_np()
{   return pthread_getaffinity_np();
}

int _pthread_once()
{   return pthread_once();
}

int _pthread_setcancelstate()
{   return pthread_setcancelstate();
}

int _pthread_setcanceltype()
{   return pthread_setcanceltype();
}

int _pthread_cancel()
{   return pthread_cancel();
}

int _pthread_testcancel()
{   return pthread_testcancel();
}

int _pthread_mutex_init()
{   return pthread_mutex_init();
}

int _pthread_mutex_destroy()
{   return pthread_mutex_destroy();
}

int _pthread_mutex_trylock()
{   return pthread_mutex_trylock();
}

int _pthread_mutex_lock()
{   return pthread_mutex_lock();
}

int _pthread_mutex_unlock()
{   return pthread_mutex_unlock();
}

int _pthread_mutexattr_init()
{   return pthread_mutexattr_init();
}

int _pthread_mutexattr_destroy()
{   return pthread_mutexattr_destroy();
}

int _pthread_mutexattr_getpshared()
{   return pthread_mutexattr_getpshared();
}

int _pthread_mutexattr_setpshared()
{   return pthread_mutexattr_setpshared();
}

int _pthread_rwlock_unlock()
{   return pthread_rwlock_unlock();
}

int _pthread_rwlockattr_init()
{   return pthread_rwlockattr_init();
}

int _pthread_rwlockattr_destroy()
{   return pthread_rwlockattr_destroy();
}

int _pthread_rwlockattr_getpshared()
{   return pthread_rwlockattr_getpshared();
}

int _pthread_rwlockattr_setpshared()
{   return pthread_rwlockattr_setpshared();
}

int _pthread_rwlockattr_getkind_np()
{   return pthread_rwlockattr_getkind_np();
}

int _pthread_rwlockattr_setkind_np()
{   return pthread_rwlockattr_setkind_np();
}

int _pthread_cond_init()
{   return pthread_cond_init();
}

int _pthread_cond_destroy()
{   return pthread_cond_destroy();
}

int _pthread_cond_signal()
{   return pthread_cond_signal();
}

int _pthread_cond_broadcast()
{   return pthread_cond_broadcast();
}

int _pthread_cond_wait()
{   return pthread_cond_wait();
}

int _pthread_cond_timedwait()
{   return pthread_cond_timedwait();
}

int _pthread_condattr_init()
{   return pthread_condattr_init();
}

int _pthread_condattr_destroy()
{   return pthread_condattr_destroy();
}

int _pthread_condattr_getpshared()
{   return pthread_condattr_getpshared();
}

int _pthread_condattr_setpshared()
{   return pthread_condattr_setpshared();
}

int _pthread_key_create()
{   return pthread_key_create();
}

int _pthread_key_delete()
{   return pthread_key_delete();
}

int _pthread_getspecific()
{   return pthread_getspecific();
}

int _pthread_setspecific()
{   return pthread_setspecific();
}

int _pthread_atfork()
{   return pthread_atfork();
}


#endif /* __linux__ */

/* end of pslstubs.c */

