module finitise;

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


fluid '(!*tra intvar);

exports finitise;
imports newplace,getsqrtsfromplaces,interr,completeplaces2,sqrtsign;
imports mkilist,extenplace;


symbolic procedure finitise(places,mults);
begin
  scalar placesmisc,multsmisc,m,n,sqrts;
  scalar places0,mults0,placesinf,multsinf;
  newplace list (intvar.intvar);
    % fix the disaster with 1/sqrt(x**2-1)
    % (but with no other 1/sqrt(x**2-k).
  sqrts:=getsqrtsfromplaces places;
  placesmisc:=places;
  multsmisc:=mults;
  n:=0;
  while placesmisc do <<
    if eqcar(rfirstsubs car placesmisc,'quotient)
        and (n > car multsmisc)
      then <<
        n:=car multsmisc;
        m:=multiplicity!-factor car placesmisc >>;
    placesmisc:=cdr placesmisc;
    multsmisc:=cdr multsmisc >>;
  if n = 0
    then interr "Why did we call finitise ??";
  % N must be corrected to allow for our representation of
  % multiplicities at places where X is not the local parameter.
  n:=divide(n,m);
  if cdr n neq 0 and !*tra
    then printc
     "Cannot get the poles moved precisely because of ramification";
   if (cdr n) < 0
     then n:=(-1) + car n
     else n:=car n;
        % The above 3 lines (as a replacement for the line below)
        % inserted JHD 06 SEPT 80.
%  n:=car n;
% ***** not true jhd 06 sept 80 *****;
    % This works because, e.g., DIVIDE(-1,2) is -1 remainder 1.
    % Note that N is actually negative.
  % We now wish to divide by X**N, thus increasing
  % the degrees of all infinite places by N and
  % decreasing the degrees of all places lying over 0.
  while places do <<
    if atom rfirstsubs car places
      then <<
        places0:=(car places).places0;
        mults0:=(car mults).mults0 >>
      else if car rfirstsubs car places eq 'quotient
        then <<
          placesinf:=(car places).placesinf;
          multsinf:=(car mults).multsinf >>
        else <<
          placesmisc:=(car places).placesmisc;
          multsmisc:=(car mults).multsmisc >>;
    places:=cdr places;
    mults:=cdr mults >>;
  if places0
    then <<
      places0:=completeplaces2(places0,mults0,sqrts);
      mults0:=cdr places0;
      places0:=car places0;
      m:=multiplicity!-factor car places0;
      mults0:=for each u in mults0 collect u+n*m >>
    else <<
      places0:=for each u in sqrtsign(sqrts,intvar)
                 collect (intvar.intvar).u;
      mults0:=mkilist(places0,n * (multiplicity!-factor car places0))>>;
  placesinf:=completeplaces2(placesinf,
                             multsinf,
                             for each u in extenplace car placesinf
                               collect lsubs u);
  multsinf:=cdr placesinf;
  placesinf:=car placesinf;
  while placesinf do <<
    m:=multiplicity!-factor car placesinf;
    if (car multsinf) neq n*m
      then <<
        placesmisc:=(car placesinf).placesmisc;
        multsmisc:=(car multsinf -n*m).multsmisc >>;
      % This test ensures that we do not add places
      % with a multiplicity of zero.
    placesinf:=cdr placesinf;
    multsinf:=cdr multsinf >>;
  return list(nconc(places0,placesmisc),
              nconc(mults0,multsmisc),
              -n)
  end;


symbolic procedure multiplicity!-factor place;
begin
  scalar n;
  n:=1;
  for each u in place do
    if (lsubs u eq intvar) and
        eqcar(rsubs u,'expt)
      then n:=n*(caddr rsubs u);
  return n
  end;

endmodule;

end;

