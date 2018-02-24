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

/* This is expected to be rather similar to the Linux case.
 */

int profil()
{   return 0;
}

int sigrelse(int s)
{   return 0;
}

int pthread_getconcurrency()
{   return 0;
}

int pthread_yield()
{   return 0;
}

typedef void *cpu_set_t;

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

/*
 * And now pretend to be Linux!
 */

#define __linux__

#endif // __CYGWIN__

#ifdef __clang__

/* Foe the Macintosh.
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

/*
 * I have to define the following - at least on some platforms - to get
 * functions defined in header files. These are often obsolete or non-standard
 * names that are used and it may be a good idea to review the code and
 * arrange that mess like this is not required.
 */

/* sigrelse seems to need XOPEN_EXTENDED, and the man page says that it is
 * only provided for programs that make use of the historical System V signal
 * API, and that new applications should use the POSIX versions (ie sigaction
 * and friends).
 */
#define __USE_XOPEN_EXTENDED 1

#define __USE_UNIX98 1

/* pthread_setaffinity is for GNU */
#define __USE_GNU 1

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

/*
 * Sometimes signal is defined using a type sighandler_t, but the
 * typedef is given different names on Linux, BSD and Cygwin, so I write
 * out the underlying type directly here. The function signal is perhaps now
 * obsolete with sighandler now preferred.
 */

void (*_signal(int s, void (*h)(int)))(int)
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

int _pthread_attr_getstack(pthread_attr_t *attr, void **a, size_t *s)
{   return pthread_attr_getstack(attr, a, s);
}

int _pthread_attr_setstack(pthread_attr_t *attr, void *a, size_t s)
{   return pthread_attr_setstack(attr, a, s);
}

int _pthread_attr_getstacksize(const pthread_attr_t *attr, size_t *s)
{   return pthread_attr_getstacksize(attr, s);
}

int _pthread_attr_setstacksize(pthread_attr_t *attr, size_t s)
{   return pthread_attr_setstacksize(attr, s);
}

int _pthread_setschedparam(pthread_t t, int pol, const struct sched_param *p)
{   return pthread_setschedparam(t, pol, p);
}

int _pthread_getschedparam(pthread_t t, int *pol, struct sched_param *p)
{   return pthread_getschedparam(t, pol, p);
}

int _pthread_setschedprio(pthread_t t, int p)
{   return pthread_setschedprio(t, p);
}

int _pthread_getconcurrency()
{   return pthread_getconcurrency();
}

int _pthread_yield()
{   return pthread_yield();
}

int _pthread_setaffinity_np(pthread_t t, size_t n, const cpu_set_t *c)
{   return pthread_setaffinity_np(t, n, c);
}

int _pthread_getaffinity_np(pthread_t t, size_t n, cpu_set_t *c)
{   return pthread_getaffinity_np(t, n, c);
}

int _pthread_once(pthread_once_t *t, void (*i)())
{   return pthread_once(t, i);
}

int _pthread_setcancelstate(int s, int *o)
{   return pthread_setcancelstate(s, o);
}

int _pthread_setcanceltype(int t, int *o)
{   return pthread_setcanceltype(t, o);
}

int _pthread_cancel(pthread_t t)
{   return pthread_cancel(t);
}

void _pthread_testcancel()
{   pthread_testcancel();
}

int _pthread_mutex_init(pthread_mutex_t *m, const pthread_mutexattr_t *a)
{   return pthread_mutex_init(m, a);
}

int _pthread_mutex_destroy(pthread_mutex_t *m)
{   return pthread_mutex_destroy(m);
}

int _pthread_mutex_trylock(pthread_mutex_t *m)
{   return pthread_mutex_trylock(m);
}

int _pthread_mutex_lock(pthread_mutex_t *m)
{   return pthread_mutex_lock(m);
}

int _pthread_mutex_unlock(pthread_mutex_t *m)
{   return pthread_mutex_unlock(m);
}

int _pthread_mutexattr_init(pthread_mutexattr_t *m)
{   return pthread_mutexattr_init(m);
}

int _pthread_mutexattr_destroy(pthread_mutexattr_t *a)
{   return pthread_mutexattr_destroy(a);
}

int _pthread_mutexattr_getpshared(const pthread_mutexattr_t *a, int *p)
{   return pthread_mutexattr_getpshared(a, p);
}

int _pthread_mutexattr_setpshared(pthread_mutexattr_t *a, int p)
{   return pthread_mutexattr_setpshared(a, p);
}

int _pthread_rwlock_unlock(pthread_rwlock_t *r)
{   return pthread_rwlock_unlock(r);
}

int _pthread_rwlockattr_init(pthread_rwlockattr_t *a)
{   return pthread_rwlockattr_init(a);
}

int _pthread_rwlockattr_destroy(pthread_rwlockattr_t *a)
{   return pthread_rwlockattr_destroy(a);
}

int _pthread_rwlockattr_getpshared(const pthread_rwlockattr_t *a, int *p)
{   return pthread_rwlockattr_getpshared(a, p);
}

int _pthread_rwlockattr_setpshared(pthread_rwlockattr_t *a, int p)
{   return pthread_rwlockattr_setpshared(a, p);
}

int _pthread_rwlockattr_getkind_np(const pthread_rwlockattr_t *a, int *p)
{   return pthread_rwlockattr_getkind_np(a, p);
}

int _pthread_rwlockattr_setkind_np(pthread_rwlockattr_t *a, int p)
{   return pthread_rwlockattr_setkind_np(a, p);
}

int _pthread_cond_init(pthread_cond_t *c, const pthread_condattr_t *a)
{   return pthread_cond_init(c, a);
}

int _pthread_cond_destroy(pthread_cond_t *c)
{   return pthread_cond_destroy(c);
}

int _pthread_cond_signal(pthread_cond_t *c)
{   return pthread_cond_signal(c);
}

int _pthread_cond_broadcast(pthread_cond_t *c)
{   return pthread_cond_broadcast(c);
}

int _pthread_cond_wait(pthread_cond_t *c, pthread_mutex_t *m)
{   return pthread_cond_wait(c, m);
}

int _pthread_cond_timedwait(pthread_cond_t *c, pthread_mutex_t *m, const struct timespec *t)
{   return pthread_cond_timedwait(c, m, t);
}

int _pthread_condattr_init(pthread_condattr_t *a)
{   return pthread_condattr_init(a);
}

int _pthread_condattr_destroy(pthread_condattr_t *a)
{   return pthread_condattr_destroy(a);
}

int _pthread_condattr_getpshared(pthread_condattr_t *a, int *s)
{   return pthread_condattr_getpshared(a, s);
}

int _pthread_condattr_setpshared(pthread_condattr_t *a, int s)
{   return pthread_condattr_setpshared(a, s);
}

int _pthread_key_create(pthread_key_t *k, void (*d)(void *))
{   return pthread_key_create(k, d);
}

int _pthread_key_delete(pthread_key_t k)
{   return pthread_key_delete(k);
}

void *_pthread_getspecific(pthread_key_t k)
{   return pthread_getspecific(k);
}

int _pthread_setspecific(pthread_key_t k, const void *p)
{   return pthread_setspecific(k, p);
}

int _pthread_atfork(void (*prep)(), void (*par)(), void (*chi)())
{   return pthread_atfork(prep, par, chi);
}

#endif /* __linux__ */

#ifdef __WIN64__

#endif

/* end of pslstubs.c */

