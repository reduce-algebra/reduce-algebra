module contfr;  % Simultaneous approximation of a real number by a
                % continued fraction and a rational number with optional
                % user controlled precision (upper bound for numerator).

% Author: Herbert Melenk.
% Major changes by : A Barnes, February 2019
% to use integer arithmetic in contfract2. This avoids problems with
% rounding which resulted in a non-canonical continued fraction
% being returned for some rational number arguments.

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

symbolic procedure contfract2(u, inexact, b1, n);
 % compute continued fraction until the numerator exceeds b1
 % or the approximation has reached system precision
 % or the number of terms obtained reaches n.
 % Now uses integer arithmetic throughout
  begin scalar b0, l, a, b, c, g, gg, ggg, h, hh, hhh, count;
    a:= car u; b:= cdr u;
    g:=0; gg:=1; h:=1; hh:=0;
    % precision irrelevant if we have an exact rational
    if (null b1 or b1 = 0) and inexact then
       b0 := (expt(10, precision 0)*b)/abs a;
    if n then count := n;
    c:=divide(a,b);
    if a<0 then c := (car c - 1).(cdr c + b); % need the positive remainder!!
 loop:
    a := car c;
    ggg := a*gg + g;
    hhh := a*hh + h;
    if b1 and b1 > 0 and abs hhh > b1 then goto ret;
    g := gg; gg := ggg; h := hh; hh := hhh;
    if l then l := list('list, 1, a) . l
    else l := a . l;
    if n then <<
       count := count - 1;
       if count leq 0 then goto ret
    >>;
    a := b;
    b:= cdr c;
    % Note gg/hh & ggg/hhh straddle the true value
    % and gg*hhh - ggg*hh = +/-1.
    if b = 0 or b0 and hh*hhh>b0 then goto ret;
    c := divide(a,b);
    goto loop;
ret:    
    return  (gg . hh) . reversip l
end;


symbolic procedure contfract1(u, b, n);
% Usually returns dotted pair (numr w . denr w)
% where w is equal to u if u is a rational number or the best rational 
% approximation to u for the current precision if u is irrational.
% Returns the continued fraction result directly if u is an integer

begin scalar oldmode, v, w;
% check for rational or rounded argument   
   if eqcar(u, '!:rd!:) then goto c;  % rounded prefix form 
   if fixp u then return (u . 1) . {u};
   if eqcar(u,'quotient) and fixp cadr u and fixp caddr u then
      return contfract2((cadr u) . (caddr u), nil, b, n) ;
   if eqcar(u, '!*sq) then <<
      v := cadr u;  % standard quotient
      if domainp(w := car v) then
        if  fixp w and fixp cdr v then
          return contfract2(v, nil, b, n)
	else if eqcar(w, '!:rn!:) and cdr v = 1 then
          return contfract2(cdr w, nil, b, n)
	else if eqcar(w, '!:rd!:) and cdr v = 1 then <<
	   v := w; goto c >>
    >>;
%  change to rounded mode to evaluate argument such as pi, e, sqrt 2 etc.
   oldmode := get(dmode!*,'dname).!*rounded;
   if car oldmode then setdmode(car oldmode,nil);
   setdmode('rounded,t); !*rounded := t;
   v:=reval u;
   setdmode('rounded,nil);
   if car oldmode then setdmode(car oldmode,t);
   !*rounded:=cdr oldmode;
   if eqcar(v,'minus) and (numberp cadr v or eqcar(cadr v,'!:rd!:))
     then v:=!:minus cadr v;
   if fixp v then return (v . 1) . {v};
   if not eqcar(v,'!:rd!:) then typerr(u,"continued fraction argument");
 c:
% convert rounded value to rational dotted pair
  v := rd2rn1 v;     % is this the best choice??
  return contfract2(v, t, b, n);
end;

symbolic procedure simpcf u;
begin scalar arg2;
  arg2 := aeval cadr u;
  u:= list('contfrac, car u, arg2, caddr u);
  return !*k2q u;
end;

put('contfrac, 'simpfn, 'simpiden);

symbolic procedure cont!-fract u;
begin scalar cfr, v;
   v := contfract1(car u, if cdr u then ieval cadr u,
                   if cdr u and cddr u then ieval caddr u);
   cfr := list(car u, list('quotient, caar v, cdar v), 'list . cdr v);
   return cons('contfrac, cfr);
end;

put('cf, 'psopfn, 'cont!-fract);
put('continued_fraction, 'psopfn, 'cont!-fract);

endmodule;

end;
