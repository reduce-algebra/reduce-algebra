/*
 * sigs.c - External routines to deal with signals
 *
 * Author:    Leigh Stoller
 *         Computer Science Dept.
 *         University of Utah
 * Date:    18-Aug-1986
 *
 *           Modified by Chris Burdorf (2/17/89)
 *          
 */

#include <sys/time.h>
#include <sys/resource.h>
#include <stdio.h>
#include <errno.h>
#include <signal.h>
#include <setjmp.h>


//#include <fptrap.h>

void putto(long long * feld,int n,long long val)
{ feld[n] = val;
}

void dumpo(long long * feld,int n)
{ int i;
  for (i=0;i<n;i++)
    printf("  %lx\n",feld[i]);
}

extern jmp_buf mainenv;

int lisprpv;

void pace()
                                                                                
{ signal(SIGFPE,SIG_IGN);
// printf("pace pace\n");
  signalhaendler(); exit (0);}
                                                                                
void longju(long long x, int y)

 {
// printf("%lx %lx %lx %x longju\n",x,y,mainenv[18],mainenv[21]);
 putto(mainenv,18,x);
// was:  mainenv[36]= x;
 y = &pace;
 mainenv[43] = y ;   
 mainenv[45] = y ;   
//dumpo(mainenv,30);
 longjmp(mainenv,-1);
 exit(0);
 }


struct rlimit rlp;
double mysigstack[500];

extern int  SYMVAL[];


signalhandler(num,dum,scp)

int num,dum;
int * scp;

{ 
/*SYMVAL[ibmrssignumber] = num;
  SYMVAL[ibmrssigcp]     = scp;
  SYMVAL[ibmrssigpc]     = scp[10];
  if ((SYMVAL[kernelmode] & 255) != 0x80) { SYMVAL[bruch]   = -17;
					   return (0);}

  if (num == 2) if (SYMVAL[bruch] != 0) {SYMVAL[bruch]     = -17;
					 return (0); }

  scp[10]   = lisprpv;
  clearerr (stdin); */
  return (0);
  };

/* Tag( sigset )
 */
extern int argumentblock[8];

void fpaction()

{ signal(SIGFPE,SIG_IGN);
//  printf("in fpaction\n");
  argumentblock[0] = -1; }

struct sigaction actio;

void psl_sigset( sig, action )
int action; /*void (*action)();
*/
int sig;
{  int res;
   if (sig == SIGFPE ) { return(0);} // Will do it manually
   if (sig > 200) { signal (SIGFPE,SIG_IGN);
                    longju(action,sig); exit (0); } 

/* if (sig == 2) /* setupoverflow(action); */
  res= setjmp(mainenv);
// printf(" setjmp = %d\n",res);
// old form
  if (sig == SIGFPE ){ fp_set_flags();
                       actio.sa_sigaction = &fpaction;}
  else { actio.sa_sigaction = action; }
  actio.sa_flags = SA_SIGINFO;
  sigaction(sig, &actio, NULL);

  lisprpv = action;

}

#include <architecture/ppc/fp_regs.h>

extern ppc_fp_scr_t  healthy_statusreg ;
ppc_fp_scr_t statusreg;

int fp_set_flags()

{ 
  statusreg =  healthy_statusreg ;

  // statusreg= get_fp_scr();
  statusreg.oe=1;
  statusreg.ze=1;
  statusreg.ue=1;
  set_fp_scr(statusreg);
}

int fp_display_flags()

{
//  statusreg =  healthy_statusreg ;

  statusreg= get_fp_scr();
//  printf("%d %d %d %d flags\n"
//           ,statusreg.ox,statusreg.ux,statusreg.zx,statusreg.xx);

  return(statusreg.ox|statusreg.ux|statusreg.zx);
}
int fp_del_flags()
{
//  statusreg =  healthy_statusreg ;

  // statusreg= get_fp_scr();
  statusreg.ox=0;
  statusreg.ux=0;
  statusreg.zx=0;
  statusreg.xx=0;
  set_fp_scr(statusreg);
}


setupoverflow(action)
void (*action)();
{
    /* this sets the stack overflow limit to be less than
       the initial limit by 8000 bytes
     */
//    struct sigaltstack ss;
    struct sigvec sv;

    /* set up to catch stack overflows */
    getrlimit(RLIMIT_STACK,&rlp);

    /*  we will allocate StackPreserve bytes for overflow purposes */
    rlp.rlim_cur -= 4000;
     printf (" rlimit = %x \n",rlp.rlim_cur);
    /*setrlimit(RLIMIT_STACK,&rlp); */

//    ss.ss_sp = (char *) &mysigstack[450];
//    ss.ss_onstack = 0;
//    printf (" errorstatus from sigstack %d \n",sigaltstack(&ss,0));

    sv.sv_handler = action;
    printf (" action = %x \n",action);
    sv.sv_mask = 0;
//    sv.sv_onstack = 1;
    printf (" errorstatus from sigvec %d %x \n",sigvec(8,&sv,0),17);
}
