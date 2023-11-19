module general;   % General functions for the support of REDUCE.

% Author: Anthony C. Hearn.

% Copyright (c) 1999 Anthony C. Hearn.  All rights reserved.

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

% $Id$
global '(!!arbint);

!!arbint := 0; % Index for arbitrary constants.

symbolic procedure atomlis u;
   null u or (atom car u and atomlis cdr u);

flag('(eq equal),'equalopr);

symbolic procedure makearbcomplex;
   begin scalar ans;
      !!arbint := !!arbint+1;
      ans := car(simp!*(list('arbcomplex, !!arbint)));
      % This CAR is NUMR, which is not yet defined.
      return ans
   end;

symbolic inline procedure nth(u,n);
   car pnth(u,n);

symbolic procedure pnth(u,n);
   if null u then rerror(alg,6,"Index out of range")
    else if n=1 then u
    else pnth(cdr u,n-1);

symbolic procedure permp(u,v);
   % This used to use EQ.  However, SUBST use requires =.
   if null u then t
    else if car u=car v then permp(cdr u,cdr v)
    else not permp(cdr u,subst(car v,car u,cdr v));

symbolic procedure permutations u;
   %  Returns list of all permutations of the list u.
   if null u then list u
    else for each j in u join mapcons(permutations delete(j,u),j);

symbolic inline procedure posintegerp u;
   % True if U is a positive (non-zero) integer.
   fixp u and u>0;

symbolic procedure remove(x,n);
   % Returns X with Nth element removed;
   if null x then nil
    else if n=1 then cdr x
    else car x . remove(cdr x,n-1);

symbolic procedure repasc(u,v,w);
   % Replaces value of key U by V in association list W.
   if null w then rerror(alg,7,list("key",u,"not found"))
    else if u = caar w then (u . v) . cdr w
    else car w . repasc(u,v,cdr w);

symbolic procedure repascq(u,v,w);
   % Replaces value of key U by V in association list W with EQ test.
   if null w then rerror(alg,7,list("key",u,"not found"))
    else if u eq caar w then (u . v) . cdr w
    else car w . repascq(u,v,cdr w);

symbolic procedure spaces n; for i := 1:n do prin2 " ";

symbolic procedure subla(u,v);
   % Substitutes the atom u in v. Retains previous structure where
   % possible.
   if null u or null v then v
    else if atom v then (if x then cdr x else v) where x=atsoc(v,u)
    else (if y=v then v else y) where y=subla(u,car v) . subla(u,cdr v);

symbolic procedure xnp(u,v);
   %returns true if the atom lists U and V have at least one common
   %element;
   u and (car u memq v or xnp(cdr u,v));

fluid '(ints!-as!-symbols!*);
ints!-as!-symbols!* := mkvect 15;
for i := 0:15 do putv(ints!-as!-symbols!*, i,
                      intern compress ('!! . explode i));

% Make a symbols whose name is the sequence of digits from the
% number u. This (!*num2id 37) will give !37.
 
symbolic inline procedure !*num2id u;
   if u <= 15 and u >= 0 then getv(ints!-as!-symbols!*, u)
   else intern list2string explode u;

symbolic procedure alistp l;
   null l or (pairp l and pairp car l and alistp cdr l);

symbolic inline procedure greaterpcar(u, v);
  car u > car v;

symbolic inline procedure lesspcar(u, v);
  car u < car v;

symbolic inline procedure greaterpcdr(a, b);
  cdr a > cdr b;

symbolic inline procedure lesspcdr(u, v);
  cdr u < cdr v;

symbolic inline procedure identity!-function x;
  x;

symbolic inline procedure ordpcar(u, v);
  ordp(car u, car v);

symbolic inline procedure ordpcadr(u, v);
  ordp(cadr u, cadr v);

symbolic inline procedure ordopcadr(u, v);
  ordop(cadr u, cadr v);

symbolic inline procedure arg1of2(u, v); u;

symbolic inline procedure arg2of2(u, v); v;

% Round a floating point number so that it has at most n significant bits.

algebraic procedure fpmaxbits(ff, n);
  if ff = 0.0 then ff
  else if ff < 0.0 then -fpmaxbits(-ff, n)
  else
    begin
      scalar x := 0, k := 2^(n-1);
      while ff >= k do << x := x+1; ff := 0.5*ff >>;
      while ff < k do << x := x-1; ff := 2.0*ff >>;
      k := fix ff;
      if (ff - k) = 0.5 then <<
        if remainder(b, 2) = 1 then k := k+1 >>
      else if (ff - k) >= 0.5 then k := k+1;
      return k*2.0^x
    end;

% floatp1 is in internal function here that finds a native floating point
% value even if it is wrapped in any of the structures that Reduce uses.

symbolic procedure floatp1 u;
  if floatp u then u
  else if eqcar(u, '!:rd!:) and floatp cdr u then cdr u
  else if eqcar(u, '!*sq) and denr cadr u = 1 then floatp1 numr cadr u
  else nil;

symbolic procedure bfloatp1 u;
  if eqcar(u, '!:rd!:) and not atom cdr u then cdr u
  else if eqcar(u, '!*sq) and denr cadr u = 1 then bfloatp1 numr cadr u
  else nil;

symbolic procedure hexfloat u;
  begin
    scalar r, neg, bx := 0, hi := 2.0^53, lo := 2.0^52;
    if u = 0.0 then return "0.0"
    else if u < 0 then << neg := t; u := -u >>;
    while u < lo do <<
      u := 2.0*u;
      bx := bx-1 >>;
    while u >= hi do <<
      u := u/2;
      bx := bx+1 >>;
    r := '!p . append(explode2 bx, '(!"));
    r := '!0 . '!x . append(explode2 hex fix u, r);
    if neg then r := '!- . r;
    return compress ('!" . r)
  end;

symbolic procedure hexbfloat u;
  begin
    scalar m:=car u, x:=cdr u, neg, r;
    if m = 0 then return "0.0"
    else if m < 0 then << neg := t; m := -m >>;
    r := '!p . append(explode2 x, '(!"));
    r := '!0 . '!x . append(explode2 hex m, r);
    if neg then r := '!- . r;
    return compress ('!" . r)
  end;

% hex() is intended for use within a "write" statement. If its argument is
% an integer it is rendered as a string. Negative integers are shown with
% their first two characters "~f" where the "~" can be though of as an
% infinite stream of leading "f" digits.
% Floats are displayed in the way that C++ presents binary floats.
% There may be an initial "-", then "0x" and a sequence of hex digits
% for the mantissa, then a "p" followed by the decimal rendering of
% an exponent (which is the power of 2 that the mantissa must be
% multiplied by).
% In each case the result is returned as a string, and so it is useful
% for pprinting but not necessarily further computation.

symbolic procedure hex n;
  begin
    scalar r := '(!"), w := nil;
    if fixp n then <<
      if n < 0 then <<
        w := 16;
        while w+n <= 0 do w := 16*w;
        n := w + n >>;
      repeat <<
        r := nth('(!0 !1 !2 !3 !4 !5 !6 !7
                   !8 !9 !a !b !c !d !e !f), add1 remainder(n, 16)) . r;
        n := n/16 >> until zerop n;
      if w then <<
        if not eqcar(r, '!f) then r := '!f . r;
        r := '!~ . r >>;
      return compress ('!" . r) >>
    else if (w := floatp1 n) then return hexfloat w
    else if (w := bfloatp1 n) then return hexbfloat w;
    return n
  end;

flag('(hex), 'opfn);

% As an alternative way to go, prinhex is a function that prints its
% argument with integers shown in hex. 

!#if (memq 'psl lispsystem!*)

symbolic procedure prinhex a;
  begin
    scalar outputbase!* := 16;
    prin1 a;
  end;

!#endif

flag('(prinhex), 'opfn);

% hex64 is rather like prinhex except that it displays the hex
% representation of a number with an inital "0x" and then with underscores
% every 16 places. This should be suitable for re-input to Reduce.

symbolic procedure hex64 n;
  begin
    scalar w, b:=2**64;
    if n < 0 then <<
      prin2 "-";
      n := -n >>;
    while n >= b do <<
      w := remainder(n, b) . w;
      n := n/b >>;
    w := n . w;
    prin2 "0x0";
    for each d in w do <<
      prin2 "_";
      if posn()+18 >= linelength nil then terpri();
      prinhex d >>;
    prin2 "$";
  end; 

symbolic procedure hex64t n;
 << if posn() neq 0 then terpri();
    hex64 n;
    terpri() >>;

endmodule;

end;
