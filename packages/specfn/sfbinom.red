module sfbinom;   % Procedures for computing Binomial coefficients
                  % Stirling numbers and such
%
% Author: Winfried Neun, Feb 1993, Sep 1993

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

% $Id: $

% The next 2 declarations enable better checking of number of arguments
% by simpiden

flag('(Motzin Stirling1 Stirling2 Binomial), 'specfn);

deflist('((Motzin 1) (Stirling1 2) (Stirling2 2) (Binomial 2)
	 ), 'number!-of!-args);

% algebraic operator binomial;  % Now in entry.red.
deflist('((binomial simpiden)),'simpfn);

symbolic procedure !:compute!-binomial(n,k);
  begin scalar nn,dd,r;
    nn := for l:=0:(k-1) product (n-l);
    dd := rnfactorial!* !*i2rn k;
    r := quotdd(nn,dd);
    if null r then errach list("Exact division failed in binomial computation:",nn,dd);
    return r;
  end;

symbolic operator !:compute!-binomial;

algebraic <<
 let { binomial (~n,~k) => !:compute!-binomial(n,k)
                        when fixp n and fixp k and  k >=0,
       binomial (~n,~k) => 1
                when fixp n and fixp k and n >= k and k=0,
       binomial (~n,~k) => 0
                when fixp n and fixp k and n<k and n >=0,
       binomial (~n,~k) => 0
                when fixp n and fixp k and k < 0,
       binomial (~n,~k) => gamma(n+1) / gamma (k+1) / gamma(n-k+1)
                when numberp n and  numberp k and not(fixp (n - k) and
                (n-k) < 0),
       df(binomial(~c,~k),c) => binomial(c,k)*(psi(1+c)-psi(1+c-k))
     } >>;

% Some rules for quotients of binomials are still missing

algebraic operator stirling1, stirling2;

algebraic
 let {stirling1(~n,~n) => 1,
      stirling1(~n,0)  => 0 when not(n=0),
      stirling1(~n,~n-1) => - binomial(n,2),
      stirling1(~n,~m) => 0 when fixp n and fixp m and n < m,
      stirling1(~n,~m) => (for k:=0:(n-m) sum
                        ( (-1)^k * binomial(n-1+k,n-m+k) *
                          binomial(2*n-m,n-m-k) * stirling2(n-m+k,k)))
                when fixp n and fixp m and n > m,
% This rather naive implementation will cause problem
% when m - n is large !
      stirling2(~n,~n) => 1,
      stirling2(~n,0)  => 0 when not(n=0),
      stirling2(~n,~n-1) => binomial(n,2),
      stirling2(~n,~m) => 0 when fixp n and fixp m and n < m,
      stirling2(~n,~m) => calc!:stirling2(n,m)
                        when fixp n and fixp m and n >m };

algebraic procedure calc!:stirling2 (n,m);

begin scalar bin_row;
bin_row := binomial_row(m);
return
((for k:=0:m sum ( (-1)^(m-k)
  * part(bin_row,k+1)*k^n))/factorial(m));
end;

put('stirling1, 'prifn, 'plain!-symbol);
put('stirling2, 'prifn, 'plain!-symbol);
put('stirling1, 'plain!-functionsymbol, '!s);
put('stirling2, 'plain!-functionsymbol, '!S);
% put('stirling1, 'fancy!-functionsymbol, "\mathrm{s}");
% put('stirling2, 'fancy!-functionsymbol, "\mathrm{S}");
% fancy print stuff for Stirling now in module fancy_specfn in tmprint.red

symbolic procedure binomial_row (n);

        % computes nth row of the Pascal triangle

begin scalar list_of_bincoeff, newlist, old, curr;

if (not fixp n) or (n < 0) then return nil;

list_of_bincoeff := { 1 };

while n > 0 do
     << old := 0;
        newlist := {};
        while not(list_of_bincoeff = {}) do
            <<  curr := car list_of_bincoeff;
                newlist := (old + curr) . newlist;
                old := curr;
                list_of_bincoeff := rest list_of_bincoeff;
            >>;
        list_of_bincoeff := 1 . newlist;
        n := n -1
     >>;
return 'list . list_of_bincoeff;

end;

flag('(binomial_row),'opfn);

symbolic procedure motzkin(n);

if (n:= reval n)=0 then 1 else if n=1 then 1 else
% ((3*n-3)*Motzkin(n-2) + (2*n+1)* Motzkin(n-1))/(n+2);
if not fixp n or n <0 then
         mk!*sq !*kk2q list('motzkin,n)
   else begin scalar vsop,oldv,newv;
    newv := oldv :=1;
    for i:=2:n do <<
       vsop := oldv;
       oldv := newv;
       newv:= ((3*i-3) * vsop + (2*i +1)*oldv)/(i+2);
       >>;
    return newv;
end;

flag('(motzkin),'opfn);

endmodule;

end;



