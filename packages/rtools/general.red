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
% for printing but not necessarily further computation.

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

#if (memq 'psl lispsystem!*)

symbolic procedure prinhex a;
  begin
    scalar outputbase!* := 16;
    prin1 a;
  end;

#endif

flag('(prinhex), 'opfn);

% hex64 is rather like prinhex except that it displays the hex
% representation of a number with an inital "0x" and then with underscores
% every 16 places. This should be suitable for re-input to Reduce. I make
% it produce each chunk as exactly 16 digits.

% split64 takes a (big) integer and returns a list that has split the
% number into 64-bit "digits".

symbolic procedure split64 n;
  begin
    scalar base := 2^64, r;
    while n >= base or n < -1 do <<
      r := land(n, base-1) . r;
      n := (n-car r)/base >>;
    return n . r
  end;

symbolic procedure hex64 n;
  begin
    scalar w := split64 n;
    if car w = -1 then <<
      prin2 "0x-f";
      w := cdr w >>
    else prin2 "0x0";
    for each d in w do <<
      prin2 "_";
      if posn()+18 >= linelength nil then terpri();
      for i := 1:16 do
        prinhex land(lshift(d, 4*i-64), 15) >>;
    prin2 "$";
  end; 

symbolic procedure hex64t n;
 << if posn() neq 0 then terpri();
    hex64 n;
    terpri() >>;

% leafcount is intended to apply to prefix forms and counts the
% number of atoms including those that are operator-names. It will
% cope happily with very long structures, but could give stack overflow
% on very deep ones. It will also fail if handed cyclic structures.

symbolic procedure leafcount u;
  begin
    scalar n := 0;
    while not atom u do <<
      n := n + leafcount car u;
      u := cdr u >>;
    if null u then return n
    else return n + 1
  end;

symbolic operator leafcount;


% Here I scan an arbitrary Lisp datastructure. I use a stack implemented
% as a list so that even very deep structures will not lead to overflow
% of the system stack. I use a hashtable (keyed on on EQ) so that any
% places where the structure is reentrant are noticed and handled properly.
% This descends through hash tables and vectors, and makes a guess about
% the size of bignums. Its result is an assessment of the space used by
% the structure in "lisp units" which are rather vague in their definition
% but which are within an modest factor of the size of cons cells.

!*hash!-table!-p := getd 'hash!-table!-p;

symbolic procedure treesize u;
  begin
    scalar stack:=list u, seen:=mkhash(32, 0), n:=0;
    while stack do <<
      u := car stack;
      stack := cdr stack;
      if not gethash(u, seen) then <<
        puthash(u, seen, t);
        if !*hash!-table!-p and hash!-table!-p u then
          stack := hashcontents u . stack
        else if vectorp u then <<
          for i := 0:upbv u do stack := getv(u, i) . stack;
          n := n + upbv u + 1 >>
        else if fixp u then
          n := n + (msd (if u<0 then -u else u))/64 + 1
        else if atom u then n := n+1
        else <<
          stack := cdr u . stack;
          stack := car u . stack;
          u := car u;
          n := n + 1 >> >> >>;
    return n
  end;

% Maintain a sorted association list of lenth at most count where the
% sorting keeps the higest value keys at the front.

symbolic procedure keeptopfew(key, val, ll, count); 
  if count=0 then nil
  else if ll = nil then list (key.val)
  else if key < caar ll then car ll . keeptopfew(key, val, cdr ll, count-1)
  else (key.val) . firstfew(count-1, ll);

symbolic procedure firstfew(count, ll);
  if count=0 or null ll then nil
  else car ll . firstfew(count-1, cdr ll);

#if (null (getd 'symbol!-value))

symbolic procedure symbol!-value a;
 << a := errorset(a, nil, nil);
    if atom a then 'unbound_variable
    else car a >>;

#endif

% Scan all symbols and find the space used by their (global) value plus
% space on their property list. Print a table showing the 10 largest
% users.

symbolic procedure findspaceusers();
  begin
    scalar biggest, n, unit;
    if memq('sixty!-four, lispsystem!*) then unit := 16 else unit = 8;
    for each a in oblist() do <<
% On CSL this function MUST be compiled because otherwise when symbol!-value
% is used on something that does not have a value it returns something that
% gets viewed as an error.
      n := treesize symbol!-value a +
           treesize prop a;
      biggest := keeptopfew(n, a, biggest, 10) >>;
    optterpri();
    for each p in biggest do <<
      prin cdr p;
      princ ": ";
      ttab 20;
% Display in what will be APPROXIMATELY kilobytes.
      prin (unit*car p/1000.0);
      printc '!K >>
  end;

% Find the bulk of data stored in a hash table.

symbolic procedure hashsize h;
   treesize hashcontents h;

% The following are the persistent hash tables that Reduce uses:

fluid '(alglist!* !$hash);
global '(kernhash);

!$hash := mkhash(200,3,nil);  % See matrix/det.red


% Here I have something usable from algebraic mode that displays some
% indication of the amount of material saved in hash tables. The numbers
% displayed scale as bytes but should not be seen as at all precise. Also
% if the same data is stored multiple times (maybe under one key a sub-
% structure of something else is saved) there will be double counting an
% the numbers displayed here could be serious over-estimates. But still
% they may be informative!

% Note that for alglist!* items are saved and a count is maintained of
% how many are used - when a limit is exceeded the table is empties. That
% is the inwardness if alglist_count!* and alglist_limit!*. The periodic
% discarding of that data is intended to avoid stale and unwanted material
% building up in memort and clogging things up.

symbolic procedure hashsizes();
  begin
    scalar unit;
    if memq('sixty!-four, lispsystem!*) then unit := 8 else unit = 4;
    terpri();
    prin2 "alglist_count* = "; print alglist_count!*;
    prin2 "alglist_limit* = "; print alglist_limit!*;
    prin2 "alglist*:"; ttab 20;
      print (unit*treesize alglist_contents(car alglist!*));
    prin2 "kernhash:"; ttab 20;
      print (unit*hashsize kernhash);
% !*prinl_visited_nodes!* is always cleared after use.
    prin2 "$hash (for det):"; ttab 20;
      print (unit*hashsize !$hash);
    printc "Symbol values and properties:";
    findspaceusers()
  end;

symbolic operator hashsizes;

endmodule;

end;
