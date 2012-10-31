#include <stdio.h>

long pos=0;
long start;

FILE * fin;

unsigned long zahl()
{
   unsigned long z;
   fread(&z,4,1,fin);
   pos = pos+4;
   return(z);
}


main(int argc,char * argv[])
{
    
    char dword[10];
    unsigned long z;
    int i;

    fin = fopen(argv[1],"rb");
    if(fin == NULL)
     { printf("input file not found >%s<\n",argv[1]); exit(1);}
  
    dword[8] = 0;

initloop:
    fread(dword,8,1,fin);
    pos = pos + 8;
    if(0 == strcmp(dword,".pdata")) goto pdata;
    goto initloop;

pdata:   
    printf("virt size %lx\n",zahl());
    printf("RVA       %lx\n",zahl());
    printf("phys size %lx\n",zahl());
    printf("phys offs %lx\n",start=zahl());

while (pos < start) zahl();
    for(i=0; i<20; i++) 
        printf("   %lx\n",zahl());

    fclose(fin);
}
