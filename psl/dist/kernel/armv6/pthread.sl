%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
% File:           PXK:pthread.sl
% Title:          Interface to pthreads
% Author:         
% Created:        
% Modified:       
% Status:         Open Source: BSD License
% Mode:           Lisp
% Package:        Kernel
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

%#include <features.h>
%#include <sched.h>
%#include <time.h>

%#define __need_sigset_t
%#include <signal.h>
%#include <bits/pthreadtypes.h>
%#include <bits/setjmp.h>
%#include <bits/wordsize.h>

(compiletime (off r2i))

(external-function pthread_create (newthread attr start_routine arg))

(external-function pthread_exit (retval))

(external-function pthread_join (th thread_return))

(external-function pthread_detach (th))

(external-function pthread_self ())

(external-function pthread_equal (thread1 thread2))

(external-function pthread_attr_init (attr))

(external-function pthread_attr_destroy (attr))

(def_ext pthread_attr_getdetachstate (attr detachstate))

(external-function pthread_attr_setdetachstate (attr detachstate))

(external-function pthread_attr_getguardsize (attr guardsize))

(external-function pthread_attr_setguardsize (attr guardsize))

(external-function pthread_attr_getschedparam (attr param))

(external-function pthread_attr_setschedparam (attr param))

(external-function pthread_attr_getschedpolicy (attr policy))

(external-function pthread_attr_setschedpolicy (attr policy))

(external-function pthread_attr_getinheritsched (attr inherit))

(external-function pthread_attr_setinheritsched (attr inherit))

(external-function pthread_attr_getscope (attr scope))

(external-function pthread_attr_setscope (attr scope))

(external-function pthread_attr_getstack (attr stackaddr stacksize))

(external-function pthread_attr_setstack (attr stackaddr stacksize))

(external-function pthread_attr_getstacksize (attr stacksize))

(external-function pthread_attr_setstacksize (attr stacksize))

% Functions for scheduling control.  */

(external-function pthread_setschedparam (target_thread policy param))

(external-function pthread_getschedparam (target_thread policy param))

(external-function pthread_setschedprio (target_thread prio))

(external-function pthread_getconcurrency (void))

(external-function pthread_yield (void))

(external-function pthread_setaffinity_np (th cpusetsize cpuset))

(external-function pthread_getaffinity_np (th cpusetsize cpuset))

(external-function pthread_once (once_control init_routine))

(external-function pthread_setcancelstate (state oldstate))

(external-function pthread_setcanceltype (type oldtype))

(external-function pthread_cancel (th))

(external-function pthread_testcancel (void))

%/* Mutex handling.  */

/* Initialize a mutex.  */
(external-function pthread_mutex_init (mutex mutexattr))

(external-function pthread_mutex_destroy (mutex))

(external-function pthread_mutex_trylock (mutex))

(external-function pthread_mutex_lock (mutex))

(external-function pthread_mutex_unlock (mutex))

%* Functions for handling mutex attributes.  */

(external-function pthread_mutexattr_init (attr))

(external-function pthread_mutexattr_destroy (attr))

(external-function pthread_mutexattr_getpshared (attr pshared))

(external-function pthread_mutexattr_setpshared (attr pshared))

(external-function pthread_rwlock_unlock (rwlock))

(external-function pthread_rwlockattr_init (attr))

(external-function pthread_rwlockattr_destroy (attr))

(external-function pthread_rwlockattr_getpshared (attr pshared))

(external-function pthread_rwlockattr_setpshared (attr pshared))

(external-function pthread_rwlockattr_getkind_np (attr pref))

(external-function pthread_rwlockattr_setkind_np (attr pref))

(external-function pthread_cond_init (cond t cond_attr))

(external-function pthread_cond_destroy (cond))

(external-function pthread_cond_signal (cond))

(external-function pthread_cond_broadcast (ond))

(external-function pthread_cond_wait (cond mutex))

(external-function pthread_cond_timedwait (cond mutexc abstime))

(external-function pthread_condattr_init (attr))

(external-function pthread_condattr_destroy (attr))

(external-function pthread_condattr_getpshared (attr pshared))

(external-function pthread_condattr_setpshared (attr pshared))

%* Functions for handling thread-specific data.  */

(external-function pthread_key_create (key destr_function))

(external-function pthread_key_delete (key))

(external-function pthread_getspecific (key))

(external-function pthread_setspecific (key pointer))

(external-function pthread_atfork (prepare parent child))

(compiletime (on r2i))
