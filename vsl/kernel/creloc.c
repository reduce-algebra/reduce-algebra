
/* A simple modifier/relocation for PSL items
 * after a Savesystem.
 * Heaplowerbound can be very far away then.*/

int creloc (long long array[], long len, long long diff, long long lowb)

{  long i;
   long skip;
   long tag;
   long long inf;

   for (i=0;i< len; i += skip)
       {  tag = (array[i] >> 56) ;
          if (tag < 0) { tag += 256;}
          inf = (array[i] << 8) >> 8;
          skip = 1;
          if ( tag == 0 ) continue;  // posint
          if ( tag > 250 ) continue; // negint - forward
     // printf(" %d vorher %d %lx",tag,i,array[i]);
          if ( tag < 31  && (inf > lowb ))
                  {array[i] += diff;}
          if (tag == 247)
                  { skip = (inf +9) /8  +1 ;} //strpack
             else if (tag==249) { skip = inf + 2;}
             else if (tag==250) { skip = 1;} // work on the vect contents
     // printf(" %d nachher %lx\n",skip, array[i]);
       } 
}
