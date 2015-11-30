module fastmod; % fast computation with modular numbers.

% Author: Herbert Melenk <melenk@sc.zib-berlin.de>.

% Redistribution and use in source and binary forms, with or without
% modification, are permitted provided that the following conditions are met:
%
%    * Redistributions of source code must retain the relevant copyright
%      notice, this list of conditions and the following disclaimer.
%    * Redistributions in binary form must reproduce the above copyright
%      notice, this list of conditions and the following disclaimer in the
%      documentation and/or other materials provided with the distribution.
%
% THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
% AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
% THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
% PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNERS OR
% CONTRIBUTORS
% BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
% CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
% SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
% INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
% CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
% ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
% POSSIBILITY OF SUCH DAMAGE.
%


%
%    ( a * b ) mod current!-modulus
%
% in one call with double length intermediate result, avoiding
% conversion to bignums. Significant speedup for e.g. factorizer.

remflag('(modular!-times general!-modular!-times),'lose);

compiletime
<<
  if memq('nbig30a,options!*) or
     memq('nbig0,options!*) then load muls else load muls32;
  slow_wquotientdouble := memq('mips,lispsystem!*) or
                          memq('ultrasparc,lispsystem!*);
>>;

fluid '(!*second!-value!* current!-modulus);

remflag('(modular!-times general!-modular!-times),'lose);

% Routines from smallmod.red and genmod.red

compiletime if slow_wquotientdouble then
     flag('(modular!-times),'lose);

symbolic procedure modular!-times(a,b);
   begin scalar q;
    q:=wtimesdouble(a,b); % upper part in second value.
    wquotientdouble(!*second!-value!*,q,current!-modulus);
                          % remainder in second value.
    return !*second!-value!*;
   end;

compiletime if slow_wquotientdouble then
     remflag('(modular!-times),'lose)
       else
     flag('(modular!-times),'lose);

symbolic procedure modular!-times(a,b);
 % for systems where single divide is substantially faster than
 % double divide.
   begin scalar q;
    q:=wtimesdouble(a,b); % upper part in second value.
    if weq(!*second!-value!*,0) and wgreaterp(q,0) then
        return wremainder(q,current!-modulus);
    wquotientdouble(!*second!-value!*,q,current!-modulus);
                          % remainder in second value.
    return !*second!-value!*;
   end;

compiletime if not memq('ultrasparc,lispsystem!*) then
               flag('(modular!-times),'lose);

symbolic procedure modular!-times(a,b);
  begin scalar q;
     q:=times2(a,b);
     return remainder(q,current!-modulus);
  end;

compiletime remflag('(modular!-times),'lose);


symbolic procedure general!-modular!-times(a,b);
  % Use fast function if all operands are inums.
   if weq(0,iplus2(tag a,iplus2(tag b,tag current!-modulus)))
      then modular!-times(a,b) else general!-modular!-times!*(a,b);

symbolic procedure general!-modular!-times!*(a,b);
  begin scalar result;
     result:=remainder(a*b,current!-modulus);
     if result<0
       then result := result+current!-modulus;  %can this happen?
     return result
  end;

flag ('(modular!-times general!-modular!-times),'lose);

% Routines from factor/VECPOLY.red.
% Smallmod arithmetic never allocates heap space such
% that vector base addresses remain valid and subsequent
% vector access can be transformed into index incremental.

remflag('(times!-in!-vector remainder!-in!-vector),'lose);

symbolic procedure times!-in!-vector(a,da,b,db,c);
% Put the product of A and B into C and return its degree.
% C must not overlap with either A or B;
  begin
    scalar dc,ic,w,lc,lb;
    if ilessp(da,0) or ilessp(db,0) then return minus!-one;
    dc:=iplus2(da,db);
    for i:=0:dc do putv(c,i,0);
    for ia:=0:da do <<
      w:=getv(a,ia);
      lb := loc igetv(b,0);
      lc := loc igetv(c,ia);
      for ib:=0:db do <<
        ic:=iplus2(ia,ib);

     %  putv(c,ic,modular!-plus(getv(c,ic),
     %    modular!-times(w,getv(b,ib))))

        putmem(lc,modular!-plus(getmem lc,
          modular!-times(w,getmem lb)));
        lb := iplus2(lb,addressingunitsperitem);
        lc := iplus2(lc,addressingunitsperitem);

      >> >>;
    return dc
  end;

symbolic procedure remainder!-in!-vector(a,da,b,db);
% Overwrite the vector A with the remainder when A is
% divided by B, and return the degree of the result;
  begin
    scalar delta,db!-1,recip!-lc!-b,w,la,lb;
    if db=0 then return minus!-one
    else if db=minus!-one then errorf "attempt to divide by zero";
    recip!-lc!-b:=modular!-minus modular!-reciprocal getv(b,db);
    db!-1:=isub1 db; % Leading coeff of B treated specially, hence this;
    while not ilessp(delta:=idifference(da,db),0) do <<
      w:=modular!-times(recip!-lc!-b,getv(a,da));
      la := loc(igetv(a,delta)); lb:= loc(igetv(b,0));
      for i:=0:db!-1 do

       %putv(a,i#+delta,modular!-plus(getv(a,i#+delta),
       %  modular!-times(getv(b,i),w)));

       <<putmem(la,modular!-plus(getmem la,
          modular!-times(getmem lb,w)));
         la := iplus2(la,addressingunitsperitem);
         lb := iplus2(lb,addressingunitsperitem);
       >>;

      da:=isub1 da;
      while not ilessp(da,0) and getv(a,da)=0 do da:=isub1 da >>;
    return da
  end;

flag('(times!-in!-vector remainder!-in!-vector),'lose);

endmodule;

end;

