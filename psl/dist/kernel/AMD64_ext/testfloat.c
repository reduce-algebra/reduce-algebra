/*
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
*/

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <fenv.h>

int raus()

{ exit (0);}

fexcept_t flagp;

int main()
{ double aa; int i;
  aa = 10.0;
  for (i=1;i<500;i++){ aa = 10.0*aa;
  fegetexceptflag(&flagp, FE_OVERFLOW | FE_DIVBYZERO);
  if (flagp != 0) {printf("exit1 %d %x\n",i,flagp); break;}}
  printf("was soll das\n");
  aa = 10.0;
  feclearexcept(FE_OVERFLOW | FE_DIVBYZERO);
  for (i=1;i<500;i++){ aa = 10.0*aa;
  fegetexceptflag(&flagp, FE_OVERFLOW | FE_DIVBYZERO);
  if (flagp != 0) {printf("exit2 %d %x\n",i,flagp); break;}}
}
