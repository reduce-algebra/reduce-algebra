MODULE FINDMAGC;

% Author: James H. Davenport.

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


fluid '(!*tra magiclist);

symbolic procedure findmagic l;
begin
  scalar p,n,pvec,m,intvec,mcount,temp;
  % L is a list of things which must be made non-zero by means of
%   a suitable choice of values for the variables in MAGICLIST;
  l:=for each u in l collect
     << mapc(magiclist,function (lambda v;
                                 if involvesf(denr u,v)
                                   then interr "Hard findmagic"));
        numr u >>;
  if !*tra then <<
    printc "We must make the following non-zero:";
    mapc(l,function printsf);
    princ "by suitable choice of ";
    printc magiclist >>;
  % Strategy is random choice in a space which has only finitely
%   many singular points;
  p:=0;
  n:=isub1 length magiclist;
  pvec:=mkvect n;
  putv(pvec,0,2);
  for i:=1:n do
    putv(pvec,i,nextprime getv(pvec,isub1 i));
  % Tactics are based on Godel (is this a mistake ??) and let P run
%   through numbers and take the prime factorization of them;
  intvec:=mkvect n;
loop:
  p:=iadd1 p;
  if !*tra then <<
    princ "We try the number ";
    printc p >>;
  m:=p;
  for i:=0:n do <<
    mcount:=0;
    while cdr(temp:=divide(m,getv(pvec,i)))=0 do <<
      mcount:=iadd1 mcount;
      m:=car temp >>;
    putv(intvec,i,mcount) >>;
  if m neq 1
    then go to loop;
  if !*tra then <<
    printc "which corresponds to ";
    superprint intvec >>;
  m:=nil;
  temp:=magiclist;
  for i:=0:n do <<
    m:=((car temp).getv(intvec,i)).m;
    temp:=cdr temp >>;
  % M is the list of substitutions corresponding to this value of P;
  temp:=l;
loop2:
  if null numr algint!-subf(car temp,m)
    then go to loop;
  temp:=cdr temp;
  if temp
    then go to loop2;
  if !*tra then <<
    printc "which corresponds to the values:";
    superprint m >>;
  return m
  end;

endmodule;

end;

