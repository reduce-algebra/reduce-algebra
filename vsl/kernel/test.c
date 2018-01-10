/*
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
% Description:  test of exception handling.
%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
*/


// These days exception handling is pretty much a nightmare. The official rules
// are that signal() or sigaction() can be used to observe that an exception
// has been raised, but almost the only thing you can do to respond to one
// is to exit the program. Part of the problam is that you might have been
// interrupted while within a system call, and if you attempt to continue
// it is necessary to worry if that can be allowed to complete or can be
// restarted. You might hope that exceptions should never be raised in such
// circumstances, however both asynchronous events (eg ^C, timeouts etc)
// can arise at any time, and with multi-threaded coded one code might be
// making a system call at the time another provokes an exception.
//
// This file is a bit of a test harness to see whether signal() or sigaction()
// gets used to handle a case where a bad memory address is used.

#include <stdio.h>
#include <signal.h>
#include <stdlib.h>

int pace()
{   printf("friede auf Erden\n");
    exit(0);
}

int krach(int *x)
{   return *x;
}

static void raus1(int a1)
{   printf("%d raus1\n", a1);
    signal(11, SIG_ERR);
}

static void raus(int a1, siginfo_t *a2, void *a3)
{   int i;
// The calls to printf() here are officially improper! 
    printf("%d, %p, %p raus\n", a1, a2, a3);
    printf("%lx\n", (long)a2->si_signo);
#ifndef __CYGWIN__
// Cygwin provides a distinctly truncated siginfo_t so almost no
// information is available there.
    printf("%lx\n", (long)a2->si_errno);
#endif
    printf("%lx\n", (long)a2->si_code);
#ifndef __CYGWIN__
    printf("%lx\n", (long)a2->si_pid);
    printf("%lx\n", (long)a2->si_uid);
    printf("%lx\n", (long)a2->si_status);
    printf("%lx\n", (long)a2->si_utime);
    printf("%lx\n", (long)a2->si_stime);
#endif
    printf("%lx\n", (long)a2->si_value.sival_int);
#ifndef __CYGWIN__
    printf("%lx\n", (long)a2->si_int);
    printf("%lx\n", (long)a2->si_ptr);
    printf("%lx\n", (long)a2->si_addr);
    printf("%lx\n", (long)a2->si_band);
    printf("%lx\n", (long)a2->si_fd);
#endif
    exit(0);
}

struct sigaction act;

int main(int argc, char *argv[])
{   double aa; int i;
    act.sa_sigaction = raus;
    act.sa_flags     = SA_SIGINFO;
//  sigaction(11, &act, NULL);
    signal(11, raus1);
    krach((int *)(-300));       // This is expected to generate a fault
    return 0;
}
