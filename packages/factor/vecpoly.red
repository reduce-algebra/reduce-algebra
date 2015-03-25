module vecpoly;

% Authors: A. C. Norman and P. M. A. Moore, 1979;

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


fluid '(current!-modulus safe!-flag);


%**********************************************************************;
% Routines for working with modular univariate polynomials
% stored as vectors. Used to avoid unwarranted storage management
% in the mod-p factorization process;


safe!-flag:=carcheck 0;


symbolic procedure copy!-vector(a,da,b);
% Copy A into B;
 << for i:=0:da do
      putv(b,i,getv(a,i));
    da >>;

symbolic procedure times!-in!-vector(a,da,b,db,c);
% Put the product of A and B into C and return its degree.
% C must not overlap with either A or B;
  begin
    scalar dc,ic,w;
    if da#<0 or db#<0 then return minus!-one;
    dc:=da#+db;
    for i:=0:dc do putv(c,i,0);
    for ia:=0:da do <<
      w:=getv(a,ia);
      for ib:=0:db do <<
        ic:=ia#+ib;
        putv(c,ic,modular!-plus(getv(c,ic),
          modular!-times(w,getv(b,ib)))) >> >>;
    return dc
  end;


symbolic procedure quotfail!-in!-vector(a,da,b,db);
% Overwrite A with (A/B) and return degree of result.
% The quotient must be exact;
    if da#<0 then da
    else if db#<0 then errorf "Attempt to divide by zero"
    else if da#<db then errorf "Bad degrees in QUOTFAIL-IN-VECTOR"
    else begin
      scalar dc;
      dc:=da#-db; % Degree of result;
      for i:=dc step -1 until 0 do begin
        scalar q;
        q:=modular!-quotient(getv(a,db#+i),getv(b,db));
        for j:=0:db#-1 do
          putv(a,i#+j,modular!-difference(getv(a,i#+j),
            modular!-times(q,getv(b,j))));
        putv(a,db#+i,q)
      end;
      for i:=0:db#-1 do if getv(a,i) neq 0 then
        errorf "Quotient not exact in QUOTFAIL!-IN!-VECTOR";
      for i:=0:dc do
        putv(a,i,getv(a,db#+i));
      return dc
    end;


symbolic procedure remainder!-in!-vector(a,da,b,db);
% Overwrite the vector A with the remainder when A is
% divided by B, and return the degree of the result;
  begin
    scalar delta,db!-1,recip!-lc!-b,w;
    if db=0 then return minus!-one
    else if db=minus!-one then errorf "Attempt to divide by zero";
    recip!-lc!-b:=modular!-minus modular!-reciprocal getv(b,db);
    db!-1:=db#-1; % Leading coeff of B treated specially, hence this;
    while not((delta:=da#-db) #< 0) do <<
      w:=modular!-times(recip!-lc!-b,getv(a,da));
      for i:=0:db!-1 do
        putv(a,i#+delta,modular!-plus(getv(a,i#+delta),
          modular!-times(getv(b,i),w)));
      da:=da#-1;
      while not(da#<0) and getv(a,da)=0 do da:=da#-1 >>;
    return da
  end;

symbolic procedure evaluate!-in!-vector(a,da,n);
% Evaluate A at N;
  begin
    scalar r;
    r:=getv(a,da);
    for i:=da#-1 step -1 until 0 do
      r:=modular!-plus(getv(a,i),
        modular!-times(r,n));
    return r
  end;

symbolic procedure gcd!-in!-vector(a,da,b,db);
% Overwrite A with the gcd of A and B. On input A and B are
% vectors of coefficients, representing polynomials
% of degrees DA and DB. Return DG, the degree of the gcd;
  begin
    scalar w;
    if da=0 or db=0 then << putv(a,0,1); return 0 >>
    else if da#<0 or db#<0 then errorf "GCD with zero not allowed";
top:
% Reduce the degree of A;
    da:=remainder!-in!-vector(a,da,b,db);
    if da=0 then << putv(a,0,1); return 0 >>
    else if da=minus!-one then <<
      w:=modular!-reciprocal getv(b,db);
      for i:=0:db do putv(a,i,modular!-times(getv(b,i),w));
      return db >>;
% Now reduce degree of B;
    db:=remainder!-in!-vector(b,db,a,da);
    if db=0 then << putv(a,0,1); return 0 >>
    else if db=minus!-one then <<
      w:=modular!-reciprocal getv(a,da);
      if not (w=1) then
        for i:=0:da do putv(a,i,modular!-times(getv(a,i),w));
      return da >>;
    go to top
  end;



carcheck safe!-flag;


endmodule;


end;

