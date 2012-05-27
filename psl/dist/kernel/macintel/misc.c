/* various UNIX functions which are needed as (long) external references */
/* 17-Nov-89  Herbert Melenk (ZIB Berlin) 				 */
 
#include <stdio.h>

long p_fopen(c,m)
	long m; char * c;
	{return ( (long) fopen(c,m)); }
 
long p_fgets(b,c,fp)
	long c,fp; char*b;
	{return ( (long) fgets(b,c,fp)); }
 

long p_clearerr(fp)
	FILE* fp;
	{clearerr(fp); }
 
long lmul(l1,l2)
	long l1,l2;
	{return (l1 * l2);}
 
long ldiv(l1,l2)
        long l1,l2;
        {return (l1 / l2);}
 
long lrem(l1,l2)
        long l1,l2;
        {return (l1 % l2);}
 
 
#ifndef sun  

setlinebuf() { return(0);}
 
#endif  

