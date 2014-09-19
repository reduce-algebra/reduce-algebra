#include <stdio.h>
#include <errno.h>
#include <signal.h>
#include <setjmp.h>


extern jmp_buf mainenv;

void longju(int x, int y)

{
  int i;
 mainenv[18]= x;
 mainenv[21] = y;
 longjmp(mainenv,-1);
 exit(0);
 }

