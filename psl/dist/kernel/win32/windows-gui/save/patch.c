#include <stdio.h>

#define PDATA 0x6164702eL

main(argc,argv)
   int argc; char * argv[];
{
   FILE * exe;
   unsigned long w,ptr;
   long i;
   char * s;
   char c;

   exe = fopen(argv[1],"rb+");
   if (!exe) { printf("cannot open file >%s<\n", argv[1]);}

   i = 0;

  loop1:
   fread(&w, sizeof(w),1,exe);
   if(w == PDATA) goto found;
   if (i++ > 1000) { printf("cannot find .PDATA\n"); exit(1);}
   goto loop1;

  found: 
   fread(&w, sizeof(w),1,exe); // second word
   fread(&w, sizeof(w),1,exe); // phys. adr
   fread(&w, sizeof(w),1,exe); // virt. adr
   fread(&w, sizeof(w),1,exe); // size
   fread(&w, sizeof(w),1,exe); // pointer
   ptr = w;
   printf(".PDATA section starts at %lx\n",ptr);
   fseek(exe,ptr,0);
    // insert the data
   w = 0L;          fwrite(&w, sizeof(w),1,exe);  // start
   w = 0x7fff0000L;  fwrite(&w, sizeof(w),1,exe);  // end
   w = 0;
   s = argv[2];
   while (*s)
     {c = *s++; 
         if ('0' <= c && c <= '9') c = c-'0';
         else   if ('a' <= c && c <= 'f') c = c-'a' +10;
         else   if ('A' <= c && c <= 'F') c = c-'A' +10;
      w = w*16 + c;
     }
   printf("insert handler %lx\n",w);
                     fwrite(&w, sizeof(w),1,exe);  // handler
   w = 0;            fwrite(&w, sizeof(w),1,exe);  // handler data
   w = 0;            fwrite(&w, sizeof(w),1,exe);  // end of prologue
   fclose(exe);
 }
   