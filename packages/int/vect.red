module vect;  % Vector support routines.

% Authors: Mary Ann Moore and Arthur C. Norman.
% Modified by: James H. Davenport.

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


exports mkuniquevect,mkvec,mkvecf2q,mkidenm,copyvec,vecsort,swap,
        non!-null!-vec,mkvect2;

symbolic procedure mkuniquevect v;
begin scalar u,n;
  n:=upbv v;
  for i:=0:n do begin
    scalar uu;
    uu:=getv(v,i);
    if not (uu member u)
      then u:=uu.u
    end;
  return mkvec u
  end;

symbolic procedure mkvec(l);
begin scalar v,i;
  v:=mkvect(isub1 length l);
  i:=0;
  while l do <<putv(v,i,car l); i:=iadd1 i; l:=cdr l>>;
  return v
  end;

symbolic procedure mkvecf2q(l);
begin
  scalar v,i,ll;
  v:=mkvect(isub1 length l);
  i:=0;
  while l do <<
    ll:=car l;
    if ll = 0 then ll:=nil;
    putv(v,i,!*f2q ll);
    i:=iadd1 i;
    l:=cdr l >>;
  return v
  end;

symbolic procedure mkidenm n;
begin
  scalar ans,u;
  scalar c0,c1;
  c0:=nil ./ 1;
  c1:= 1 ./ 1;
  % constants.
  ans:=mkvect(n);
  for i:=0 step 1 until n do <<
    u:=mkvect n;
    for j:=0 step 1 until n do
      if i iequal j
        then putv(u,j,c1)
        else putv(u,j,c0);
    putv(ans,i,u) >>;
  return ans
  end;

symbolic procedure copyvec(v,n);
   begin scalar new;
    new:=mkvect(n);
    for i:=0:n do putv(new,i,getv(v,i));
    return neW
   end;

symbolic procedure vecsort(u,l);
% Sorts vector v of numbers into decreasing order.
% Performs same interchanges of all vectors in the list l.
begin
  scalar j,k,n,v,w;
  n:=upbv u;% elements 0...n exist.
  % algorithm used is a bubble sort.
  for i:=1:n do begin
    v:=getv(u,i);
    k:=i;
  loop:
    j:=k;
    k:=isub1 k;
    w:=getv(u,k);
    if v<=w
      then goto ordered;
    putv(u,k,v);
    putv(u,j,w);
    mapc(l,function (lambda u;swap(u,j,k)));
    if k>0
      then goto loop;
  ordered:
    end;
  return nil
  end;

symbolic procedure swap(u,j,k);
if null u
  then nil
  else begin
    scalar v;
    %swaps elements i,j of vector u.
    v:=getv(u,j);
    putv(u,j,getv(u,k));
    putv(u,k,v)
    end;

symbolic procedure non!-null!-vec v;
begin
  scalar cnt;
  cnt := 0;
  for i:=0:upbv v do
    if getv(v,i)
      then cnt:=iadd1 cnt;
  return cnt
  end;

symbolic procedure mkvect2(n,initial);
begin
  scalar u;
  u:=mkvect n;
  for i:=0:n do
    putv(u,i,initial);
  return u
  end;

endmodule;

end;

