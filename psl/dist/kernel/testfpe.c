#
#	Test file to inspect the structure filled after a floating point
#       error.  When running under a debugger, set a breakpoint in sighand.
#       
##############################################################################
# Redistribution and use in source and binary forms, with or without
# modification, are permitted provided that the following conditions are met:
#
#    * Redistributions of source code must retain the relevant copyright
#      notice, this list of conditions and the following disclaimer.
#    * Redistributions in binary form must reproduce the above copyright
#      notice, this list of conditions and the following disclaimer in the
#      documentation and/or other materials provided with the distribution.
#
# THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
# AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
# THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
# PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNERS OR
# CONTRIBUTORS
# BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
# CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
# SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
# INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
# CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
# ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
# POSSIBILITY OF SUCH DAMAGE.
#
##############################################################################

#include <signal.h>
#include <stdlib.h>
#include <stdio.h>
#define __USE_GNU
#include <fenv.h>

void sighand(int x)
{
        printf("%d\n",x);
}

void main()
{
	int i = 0;
	double f = 0.0;
	struct sigaction act = {0};

	feenableexcept(FE_INVALID   | 
                   FE_DIVBYZERO | 
                   FE_OVERFLOW  | 
                   FE_UNDERFLOW);
    float a = 1., b = 0.;
	act.sa_sigaction = &sighand;
	act.sa_flags = SA_SIGINFO;
	sigaction(8, &act, (void*)0);	

//	idiv(1,i);
	fdiv(1.0,f);

	exit(0);
}


int idiv(int x,int y)
{
	return (x/y);
}

int fdiv(double x, double y)
{
	return (x/y);
}
