#include <stdio.h>
#include <time.h>

main()
{ FILE * f;
  char * d[10];
  char * t[10];

 _strdate(d);
 _strtime(t);

 f = fopen("datetag.c","w");
 fprintf(f,"char * datetag ()\n");
 fprintf(f," { return(\n"); 
 fprintf(f,"\"%s/%s\"\n",d,t);
 fprintf(f,"   ) ; } \n");
 fclose(f);
}

