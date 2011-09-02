module groebres;

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
%  Optimization of h-Polynomials by resultant calculation and
%  factorization .
%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
 
% The resultant is calculated from a h-polynomial and its predecessor
% if both are bivariate in the same variables and if these variables
% are the last ones in vdpvars* .    
 
symbolic procedure groebtestresultant(h1,h2,lv);
     begin scalar v1,hlist;
         v1 := indexcpl(vevsum0(lv,h1),1);
         if groebrescheck!?(2,v1,lv)
            and indexcpl(vevsum0(lv,h2),1)=v1
            then hlist :=
                   reverse vdplsort
                    groebhlistfromresultant
                        (h1,h2,cadr reverse vdpvars!*)
          else
         if groebrescheck1!?(2,v1,lv)
            and indexcpl(vevsum0(lv,h2),1)=v1
            then hlist :=
                   reverse vdplsort
                    groebhlistfromresultant
                        (h1,h2,caddr reverse vdpvars!*);
         if null hlist then return nil;
         return ' resultant .
              for each x in hlist collect {h2,vdpenumerate x} end;

symbolic procedure groebhlistfromresultant(h1,h0,x);
% new h-polynomial calculation: calculate
% the resultant of the two distributive polynomials h1 and h0
% with respect to x.
begin scalar ct00,hh,hh1,hs2;
   ct00:= time();
   hh:= vdpsimpcont groebresultant(h1,h0,x);
   if !*trgroeb  then <<terpri();
                     printb 57;
                     prin2t " *** the resultant from ";
                     vdpprint h1;
                     prin2t "         *** and";
                     vdpprint h0;
                     prin2t "                     *** is";
                     vdpprint hh;
                     printb 57;
                     terprit 4>>;
   hs2:= nil;
   if not vdpzero!? hh then
       << hh1:= vdp2a vdprectoint(hh,vdplcm hh);
          hh1:= fctrf !*q2f simp hh1;
          if cdr hh1 and cddr hh1 then
               hs2:= for each p in cdr hh1 collect a2vdp prepf car p;
          if !*trgroeb and hs2 then
                    <<prin2 " factorization of resultant successful:";
                      terprit 2;
                      for each x in hs2 do vdpprint x;
                      terprit 2;
                      ct00:= time() - ct00;
                      prin2 " time for factorization:"; prin2 ct00;
                      terpri()>>;
           >>;
  return hs2 end;


symbolic procedure groebresultant(p1,p2,x);
begin scalar q1,q2,q;
q1:=vdp2a vdprectoint(p1,vdplcm p1);
q2:=vdp2a vdprectoint(p2,vdplcm p2);
q:=a2vdp prepsq simpresultant {q1,q2,x};
return q end;

symbolic procedure groebrescheck!?(a,h1,vl);
  length h1 = a and car h1 = vl - 1;


symbolic procedure groebrescheck1!?(a,h1,vl);
  length h1 = a and car h1 = vl - 2 and cadr h1 = vl - 1;

endmodule;;end;
