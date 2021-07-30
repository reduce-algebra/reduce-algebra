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

symbolic procedure carx(u,v);
   if not null u and null cdr u then car u
    else rerror(alg,5,list("Wrong number of arguments to",v));

symbolic procedure eqexpr u;
   % Returns true if U is an equation or similar structure
   % (e.g., a rule).
   not atom u
      and flagp(car u,'equalopr) and cddr u and null cdddr u;

flag('(eq equal),'equalopr);

symbolic inline procedure evenp x; remainder(x,2)=0;

flag('(evenp),'opfn);  % Make a symbolic operator.

symbolic procedure makearbcomplex;
   begin scalar ans;
      !!arbint := !!arbint+1;
      ans := car(simp!*(list('arbcomplex, !!arbint)));
      % This CAR is NUMR, which is not yet defined.
      return ans
   end;

symbolic procedure mapcons(u,v);
   for each j in u collect v . j;

symbolic procedure mappend(u,v);
   for each j in u collect append(v,j);

symbolic procedure nlist(u,n);
   if n=0 then nil else u . nlist(u,n-1);

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

symbolic procedure repeats x;
   if null x then nil
    else if car x member cdr x then car x . repeats cdr x
    else repeats cdr x;

symbolic inline procedure revpr u;
   cdr u . car u;

symbolic procedure smember(u,v);
   %determines if S-expression U is a member of V at any level;
   if u=v then t
    else if atom v then nil
    else smember(u,car v) or smember(u,cdr v);

symbolic procedure smemql(u,v);
   %Returns those members of id list U contained in V at any
   %level (excluding quoted expressions);
   if null u then nil
    else if smemq(car u,v) then car u . smemql(cdr u,v)
    else smemql(cdr u,v);

symbolic procedure smemqlp(u,v);
   %True if any member of id list U is contained at any level
   %in V (exclusive of quoted expressions);
   if null v or numberp v then nil
    else if atom v then v memq u
    else if car v eq 'quote then nil
    else smemqlp(u,car v) or smemqlp(u,cdr v);

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

% In earlier versions of Reduce there were various functions where the
% definition were replicated in several places. When these are pure
% duplicates it seems good to lift the definitions to here so that they
% are included just once. So some of the functions defined here may be
% a little specialist and not used in very many places.

symbolic inline procedure !*k2pf u;
   u .* (1 ./ 1) .+ nil;

symbolic inline procedure negpf u;
   multpfsq(u,(-1) ./ 1);

symbolic inline procedure lowerind u;
   list('minus,u);

% The next two are from excalc.

symbolic inline procedure get!*fdeg u;
   (if x then car x else nil) where x = get(u,'fdegree);

symbolic inline procedure get!*ifdeg u;
   (if x then cdr x else nil)
    where x = assoc(length cdr u,get(car u,'ifdegree));

% The next is from fmprint.red/tmprint.red. I rather suspect that fmprint.red
% should be discarded in favour of tmprint.red since they are really the same
% code... but until that happens I will try a little tidy-up job here.

symbolic macro procedure fancy!-level u;
 % unwind-protect for special output functions.
  {'prog,'(pos tpos fl w),
      '(setq pos fancy!-pos!*),
      '(setq tpos fancy!-texpos),
      '(setq fl fancy!-line!*),
      {'setq,'w,cadr u},
      '(cond ((eq w 'failed)
              (setq fancy!-line!* fl)
              (setq fancy!-texpos tpos)
              (setq fancy!-pos!* pos))),
       '(return w)};

fluid '(ints!-as!-symbols!*);
ints!-as!-symbols!* := mkvect 15;
for i := 0:15 do putv(ints!-as!-symbols!*, i,
                      intern compress ('!! . explode i));

% Make a symbols whose name is the sequence of digits from the
% number u. This (!*num2id 37) will give !37.
 
symbolic inline procedure !*num2id u;
   if u <= 15 and u >= 0 then getv(ints!-as!-symbols!*, u)
   else intern list2string explode u;

symbolic inline procedure add!+vector!+to!+list(vector1, vectorlist);
% returns a list of vectors consisting of vectorlist with vector1
% added at the end. Used in symmetry and linalg packages.
   append(vectorlist, list vector1);

symbolic procedure adomainp u;
 % numberp test in an algebraic form.
   numberp u or (pairp u and idp car u and get(car u,'dname))
             or eqcar(u,'minus) and adomainp cadr u;

symbolic procedure adomainpx(u,num);
  % extended algebraic domainp test:
  % num = t: u is a domain element;
  % num = inf: u is a domain element or inf or (minus inf)
  % num = nil: u is arbitrary.
    null num or adomainp u or num='infinity
                and member(u,'(infinity (minus infinity)));

symbolic procedure revalnuminterval(u,num);
 % Evaluate u as interval; numeric bounds required if num=T.
  begin scalar l;
    if not eqcar(u,'!*interval!*) then typerr(u,"interval");
    l:={reval cadr u,reval caddr u};
    if adomainpx(car l,num) and adomainpx(cadr l,num) then return l;
    typerr(u,"numeric interval");
  end;

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

endmodule;

end;
