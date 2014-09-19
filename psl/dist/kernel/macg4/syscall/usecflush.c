#include <stdio.h>
char buffer[2048];

main(int argc, char **argv)
{
  int j;
  j = mycflush(buffer, sizeof(buffer));
  printf("result= %lx\n", j);
}

