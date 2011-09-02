module poly;  % Header module and low-level support for poly package.

% Author: Anthony C. Hearn.

% Copyright (c) 1991 RAND.  All rights reserved.

create!-package('(poly polrep gcd exptf kernel mksp reord dmode dmodeop
                 rational rnelem gint cpxrn compopr modular
                 facform homog tdconv primfac specfac kronf conj diff
                 polyop decompose interpol subs2q subs3q),
                nil);

fluid '(!*mcd !*nosq wtl!*);

switch nosq;


% Particular infix operators used in standard forms.

newtok '((!. !+) add);

newtok '((!. !*) mult);

newtok '((!. !^) to);

newtok '((!. !* !*) to);

newtok '((!. !/) over);

infix .^,.*,.+,./;


% Constructors and selectors for standard forms.

smacro procedure u.+v; % Standard (polynomial) addition constructor.
   u . v;

smacro procedure lc u;   % Leading coefficient of standard form.
   cdar u;

smacro procedure ldeg u; % Leading degree of standard form.
   cdaar u;

smacro procedure lt u;   % Leading term of standard form.
   car u;

smacro procedure u.*v;  % Standard form multiplication constructor.
   u . v;

smacro procedure mvar u; % Main variable of standard form.
   caaar u;

smacro procedure lpow u; % Leading power of standard form.
   caar u;

smacro procedure pdeg u;
   % Returns the degree of the power U.
   cdr u;

smacro procedure red u; % Reductum of standard form.
   cdr u;

smacro procedure tc u;   % Coefficient of standard term.
   cdr u;

smacro procedure tdeg u; % Degree of standard term.
   cdar u;

smacro procedure tpow u; % Power of standard term.
   car u;

smacro procedure tvar u; % Main variable of a standard term.
   caar u;

smacro procedure numr u; % Numerator of standard quotient.
   car u;

smacro procedure denr u; % Denominator of standard quotient.
   cdr u;

smacro procedure u ./ v; % Constructor for standard quotient.
   u . v;

symbolic smacro procedure domainp u; atom u or atom car u;


% Procedures for converting between parts of standard quotients and
% prefix forms.

symbolic procedure !*a2f u;
   % U is an algebraic expression. Value is the equivalent form
   % or an error if conversion is not possible;
   !*q2f simp!* u;

symbolic procedure !*a2k u;
   % U is an algebraic expression. Value is the equivalent kernel
   % or an error if conversion is not possible.
   %earlier versions used SIMP0;
   begin scalar x;
      if kernp(x := simp!* u) then return mvar numr x
       else typerr(u,'kernel)
   end;

symbolic procedure !*a2kwoweight u;
   % U is an algebraic expression. Value is the equivalent kernel
   % neglecting any weights, or an error if conversion is not possible.
   begin scalar x,wtl!*;
      if kernp(x := simp!* u) then return mvar numr x
       else typerr(u,'kernel)
   end;

symbolic procedure !*d2q u;
   % Converts domain element U into a standard quotient.
   if numberp u
     then if zerop u then nil ./ 1
   %       else if floatp u then mkfloat u ./ 1
           else u ./ 1
   % The following converts a domain rational to a SQ, which may not
   % be desirable.
   % else if eqcar(u,'!:rn!:) and !*mcd then cdr u
    else if !:zerop u then nil ./ 1 else u ./ 1;

symbolic procedure !*ff2a(u,v);
   % Converts ratio of two forms U and V to a prefix form.
   (if wtl!* then prepsq x else mk!*sq x) where x = cancel( u ./ v);

smacro procedure !*f2a u; prepf u;

smacro procedure !*f2q u;
   % U is a standard form, value is a standard quotient.
   u . 1;

smacro procedure !*k2f u;
   % U is a kernel, value is a standard form.
   list((u .** 1) . 1);

symbolic smacro procedure !*kk2f u;
   % U is a non-unique kernel, value is a standard form.
   list(mksp(u,1) . 1);

symbolic smacro procedure !*kk2q u;
   % U is a non-unique kernel, value is a standard quotient.
   list(mksp(u,1) .* 1) ./ 1;

smacro procedure !*k2q u;
   % U is a kernel, value is a standard quotient.
   list((u .** 1) . 1) . 1;

symbolic procedure !*n2f u;
   % U is a number. Value is a standard form.
   if zerop u then nil else u;

smacro procedure !*p2f u;
   % U is a standard power, value is a standard form.
   list(u . 1);

smacro procedure !*p2q u;
   % U is a standard power, value is a standard quotient.
   list(u . 1) . 1;

symbolic procedure !*q2a u;
   % U is a standard quotient, value is an algebraic expression.
   !*q2a1(u,!*nosq);

symbolic procedure !*q2a1(u,v);
   if null v then mk!*sq u else prepsqxx u;

symbolic procedure !*q2f u;
   % U is a standard quotient, value is a standard form.
   if denr u=1 then numr u else typerr(prepsq u,'polynomial);

symbolic procedure !*q2k u;
   % U is a standard quotient, value is a kernel or an error if
   % conversion not possible.
   if kernp u then mvar numr u else typerr(prepsq u,'kernel);

smacro procedure !*t2f u;
   % U is a standard term, value is a standard form.
   list u;

smacro procedure !*t2q u;
   % U is a standard term, value is a standard quotient.
   list u . 1;

symbolic smacro procedure tvar a; caar a;

endmodule;


module polrep; % Arithmetic operations on standard forms and quotients.

% Author: Anthony C. Hearn.

% Copyright (c) 1991 RAND.  All rights reserved.

fluid '(!*asymp!* !*exp !*factor !*gcd !*lcm !*mcd !*rationalize
        !*roundall !*rounded !*sqfree !*sub2 asymplis!* dmode!* wtl!*);

global '(!*group frlis!* ncmp!* powlis!* subfg!*);

global '(rd!-tolerance!* cr!-tolerance!*);

put('roundall,'simpfg,'((t (rmsubs))));

switch roundall;

!*roundall := t;   % Default is on.

symbolic smacro procedure subtrsq(u,v); addsq(u,negsq v);

symbolic procedure addsq(u,v);
   % U and V are standard quotients.
   % Value is canonical sum of U and V.
   if null numr u then v
    else if null numr v then u
    else if denr u=1 and denr v=1 then addf(numr u,numr v) ./ 1
    else begin scalar x,y,z;
        if null !*exp then <<u := numr u ./ mkprod denr u;
                             v := numr v ./ mkprod denr v>>;
        if !*lcm then x := gcdf!*(denr u,denr v)
         else x := gcdf(denr u,denr v);
        z := canonsq(quotf(denr u,x) ./ quotf(denr v,x));
        y := addf(multf(denr z,numr u),multf(numr z,numr v));
        if null y then return nil ./ 1;
        z := multf(denr u,denr z);
        return if x=1 or (x := gcdf(y,x))=1 then y ./ z
                else canonsq(quotf(y,x) ./ quotf(z,x))
    end;

symbolic procedure multsq(u,v);
   % U and V are standard quotients.
   % Value is canonical product of U and V.
   if null numr u or null numr v then nil ./ 1
    else if denr u=1 and denr v=1 then multf(numr u,numr v) ./ 1
    else begin scalar x,y,z;
        x := gcdf(numr u,denr v);
        y := gcdf(numr v,denr u);
        z := multf(quotf(numr u,x),quotf(numr v,y));
        x := multf(quotf(denr u,y),quotf(denr v,x));
        return canonsq(z ./ x)
    end;

symbolic procedure negsq u; negf numr u ./ denr u;

smacro procedure multpq(u,v);
   multsq(!*p2q u,v);

symbolic procedure cancel u;
   %returns canonical form of non-canonical standard form U;
   if !*mcd or denr u=1 then multsq(numr u ./ 1,1 ./ denr u)
    else multsq(numr u ./ 1,simpexpt list(mk!*sq(denr u ./ 1),-1));


% ***** FUNCTIONS FOR ADDING AND MULTIPLYING STANDARD FORMS *****

symbolic smacro procedure peq(u,v);
   %tests for equality of powers U and V;
   u = v;

symbolic procedure addf(u,v);
   %U and V are standard forms. Value is standard form for U+V;
   if null u then v
    else if null v then u
    else if domainp u then addd(u,v)
    else if domainp v then addd(v,u)
    else if peq(lpow u,lpow v)
       then (lambda (x,y); if null x then y else lpow u .* x .+ y)
                (addf(lc u,lc v),addf(red u,red v))
    else if ordpp(lpow u,lpow v) then lt u .+ addf(red u,v)
    else lt v .+ addf(u,red v);

symbolic procedure addd(u,v);
   %U is a domain element, V a standard form.
   %Value is a standard form for U+V;
   if null v then u
    else if domainp v then adddm(u,v)
    else lt v .+ addd(u,red v);

symbolic procedure adddm(u,v);
   % U and V are both non-zero domain elements.
   % Value is standard form for U+V.
   % The int-equiv-chk is needed to convert say (:MOD: . 0) to NIL.
   % A simpler function might therefore be possible and more efficient.
   if atom u and atom v
     then (if null dmode!* or not flagp(dmode!*,'convert) then !*n2f x
            else int!-equiv!-chk apply1(get(dmode!*,'i2d),x))
          where x=plus2(u,v)
    else dcombine(u,v,'plus);

symbolic procedure domainp u; atom u or atom car u;

% symbolic procedure noncomf u;
%    if domainp u then nil
%     else noncomp mvar u or noncomf lc u or noncomf red u;

symbolic procedure noncomp u; flagpcar(u,'noncom);

symbolic procedure multf(u,v);
   %U and V are standard forms.
   %Value is standard form for U*V;
   begin scalar x,y;
    a:  if null u or null v then return nil
         else if u=1 then return v     % ONEP
         else if v=1 then return u     % ONEP
         else if domainp u then return multd(u,v)
         else if domainp v then return multd(v,u)
         else if not(!*exp or ncmp!* or wtl!* or x)
          then <<u := mkprod u; v := mkprod v; x := t; go to a>>;
        x := mvar u;
        y := mvar v;
        if noncomp x and noncomp y then return multfnc(u,v)
         else if x eq y
          then <<x := mkspm(x,ldeg u+ldeg v);
                 % The order in the next line is IMPORTANT. See analysis
                 % by J.H. Davenport et al. for details.
                 y := addf(multf(red u,v),multf(!*t2f lt u,red v));
                 return if null x or null(u := multf(lc u,lc v))
                    then <<!*asymp!* := t; y>>
                   else if x=1 then addf(u,y)
                   else if null !*mcd then addf(!*t2f(x .* u),y)
                   else x .* u .+ y>>
         else if ordop(x,y) % or noncomp y and noncomf lc u
          then <<x := multf(lc u,v);
                 y := multf(red u,v);
                 return if null x then y else lpow u .* x .+ y>>;
        x := multf(u,lc v);
        y := multf(u,red v);
        return if null x then y else lpow v .* x .+ y
   end;

symbolic procedure multfnc(u,v);
   % Returns canonical product of U and V, with both main vars non-
   % commutative.
   begin scalar x,y;
      x := multf(lc u,!*t2f lt v);
      if null x then nil
       else if not domainp x and mvar x eq mvar u
        then x := addf(if null (y := mkspm(mvar u,ldeg u+ldeg x))
                         then nil
                        else if y = 1 then lc x
                        else !*t2f(y .* lc x),
                       multf(!*p2f lpow u,red x))
       else x := !*t2f(lpow u .* x);
      return addf(x,addf(multf(red u,v),multf(!*t2f lt u,red v)))
   end;

symbolic procedure multd(u,v);
   %U is a domain element, V a standard form.
   %Value is standard form for U*V;
   if null v then nil
    else if v=1 then u      % Common enough to be tested.
    else if domainp v then multdm(u,v)
    else lpow v .* multd(u,lc v) .+ multd(u,red v);

symbolic procedure multdm(u,v);
   % U and V are both non-zero domain elements.
   % Value is standard form for U*V;
   if atom u and atom v
     then (lambda x; if null dmode!*
                        or not flagp(dmode!*,'convert) then x
                      else % int!-equiv!-chk
                              apply1(get(dmode!*,'i2d),x))
           times2(u,v)
    else dcombine(u,v,'times);

smacro procedure multpf(u,v); multf(!*p2f u,v);

symbolic procedure negf u;
   if null u then nil
    else if domainp u then !:minus u
    else lpow u .* negf lc u .+ negf red u;

put('!*sq,'lengthfn,'!*sqlength);

symbolic procedure !*sqlength u;
   (if denr car u=1 then x else x+termsf denr car u)
    where x = termsf numr car u;

symbolic procedure terms u;
   <<lprim "Please use LENGTH instead"; termsf numr simp!* u>>;

flag('(terms),'opfn);

flag('(terms),'noval);

symbolic procedure termsf u;
   % U is a standard form.
   % Value is number of terms in U (excluding kernel structure).
   begin integer n;
      while not domainp u do <<n := n + termsf lc u; u := red u>>;
      return if null u then n else n+1
   end;

symbolic procedure tmsf u;
   % U is a standard form.
   % Value is number of terms in U (including kernel structure).
   begin integer n; scalar x;
    % Integer declaration initializes N to 0.
      while not domainp u do
       <<n := n+(if sfp(x := mvar u) then tmsf x else 1)+tmsf!* lc u;
         if ldeg u neq 1 then if ldeg u=2 then n := n+1 else n := n+2;
         u := red u>>;   % Previously, if U was non-zero, we used to add
                         % one more here.
      return if null u then n else n+1
   end;

symbolic procedure tmsf!* u;
   if numberp u and abs fix u=1 then 0 else tmsf u; % Was tmsf u+1.

symbolic procedure tms u; tmsf numr simp!* u;

flag('(tms),'opfn);

flag('(tms),'noval);


% ***** FUNCTIONS FOR WORKING WITH STRUCTURED FORMS *****

symbolic procedure offexpchk u;
   % Return structured form for standard quotient u.
   % The freevar check is required to correctly evaluate rules like
   % for all n let f(a^n-b^n)=c when exp is off and gcd on.
   if frlis!* and freevarinexptchk numr u or freevarinexptchk denr u
     then u
    else canprod(mkprod numr u,mkprod denr u);

symbolic procedure freevarinexptchk u;
   not domainp u and(not numberp ldeg u or freevarinexptchk lc u
                                   or freevarinexptchk red u);

symbolic procedure mkprod u;
   begin scalar w,x,y,z,!*exp,!*sub2;
        if null u or kernlp u then return u;
        %first make sure there are no further simplifications;
        !*sub2 := t;
        if denr(x := subs2(u ./ 1)) = 1 and numr x neq u
          then <<u := numr x; if null u or kernlp u then return u>>;
        !*exp := t;
        w := ckrn u;
        u := quotf(u,w);
        x := expnd u;
        if null x or kernlp x then return multf(w,x);
        % After this point, X is not KERNLP.
        % The check below for *MCD was suggested by James Davenport.
        % Without it, on gcd; off mcd,exp; (x**2+2x+1)/x+1; loops
        % forever.
        if !*mcd and (!*sqfree or !*factor or !*gcd)
          then y := fctrf x
         else <<y := ckrn x; x := quotf(x,y); y := list(y,x . 1)>>;
        if cdadr y>1 or cddr y
          then <<z := car y;
                 for each j in cdr y do
                    z := multf(mksp!*(car j,cdr j),z)>>
         else if not !*group and tmsf u>tmsf caadr y
          then z := multf(mksp!*(caadr y,cdadr y),car y)
         else z := mksp!*(u,1);
        return multf(w,z)
   end;

symbolic procedure expnd u;
   begin scalar !*sub2,v;
      u := expnd1 u;
      return if !*sub2 and denr(v := subs2f u) = 1 then numr v
              else u
   end;

symbolic procedure expnd1 u;
   if domainp u then u
    else addf(if not sfp mvar u or ldeg u<0
                then multpf(lpow u,expnd1 lc u)
        else multf(exptf(expnd1 mvar u,ldeg u),expnd1 lc u),
                        expnd1 red u);

symbolic procedure canprod(p,q);
   % P and Q are kernel product standard forms, value is P/Q in
   % which a  top level standard form kernel by itself has been
   % unwound.
   begin scalar v,w,x,y,z;
      if domainp q or red q or (not domainp p and red p)
        then return cancel(p ./ q);
      % Look for possible cancellations.
      while not domainp p or not domainp q do
      if sfpf p then <<z := cprod1(mvar p,ldeg p,v,w);
                       v := car z; w := cdr z; p := lc p>>
       else if sfpf q then <<z := cprod1(mvar q,ldeg q,w,v);
                             w := car z; v := cdr z; q := lc q>>
       else if domainp p then <<y := lpow q . y; q := lc q>>
       else if domainp q then <<x := lpow p . x; p := lc p>>
       else <<x := lpow p . x; y := lpow q . y;
              p := lc p; q := lc q>>;
      v := reprod(v,reprod(x,p));
      w := reprod(w,reprod(y,q));
      if minusf w then <<v := negf v; w := negf w>>;
      w := cancel(v ./ w);
      % Final check for unnecessary structure.
      v := numr w;
      if not domainp v and null red v and lc v=1
         and ldeg v=1 and sfp(x := mvar v)
        then v := x;
      w := denr w;
      if not domainp w and null red w and lc w=1
         and ldeg w=1 and sfp(x := mvar w)
        then w := x;
      return canonsq(v ./ w)
   end;

symbolic procedure sfpf u;
   not domainp u and sfp mvar u;

symbolic procedure sfp u;
   % True if mvar U is a standard form.
   not atom u and not atom car u;

symbolic procedure reprod(u,v);
   % U is a list of powers, V a standard form.
   % Value is product of terms in U with V.
   <<while u do <<v := multpf(car u,v); u := cdr u>>; v>>;

symbolic procedure cprod1(p,m,v,w);
   % U is a standard form, which occurs in a kernel raised to power M.
   % V is a list of powers multiplying P**M, W a list dividing it.
   % Value is a dotted pair of lists of powers after all possible
   % kernels have been cancelled.
   begin scalar z;
      z := cprod2(p,m,w,nil);
      w := cadr z;
      v := append(cddr z,v);
      z := cprod2(car z,m,v,t);
      v := cadr z;
      w := append(cddr z,w);
      if car z neq 1 then v := mksp(car z,m) . v;
      return v . w
   end;

symbolic procedure cprod2(p,m,u,b);
   %P and M are as in CPROD1. U is a list of powers. B is true if P**M
   %multiplies U, false if it divides.
   %Value has three parts: the first is the part of P which does not
   %have any common factors with U, the second a list of powers (plus
   %U) which multiply U, and the third a list of powers which divide U;
   %it is implicit here that the kernel standard forms are positive;
   begin scalar n,v,w,y,z;
      while u and p neq 1 do
        <<if (z := gcdf(p,caar u)) neq 1
            then
           <<p := quotf(p,z);
             y := quotf(caar u,z);
             if y neq 1 then v := mksp(y,cdar u) . v;
             if b then v := mksp(z,m+cdar u) . v
              else if (n := m-cdar u)>0 then w := mksp(z,n) . w
              else if n<0 then v := mksp(z,-n) . v>>
            else v := car u . v;
           u := cdr u>>;
      return (p . nconc!*(u,v) . w)
   end;

symbolic procedure mkspm(u,p);
   %U is a unique kernel, P an integer;
   %value is 1 if P=0, NIL if U**P is 0, else standard power of U**P;
   % should we add a check for NOT(U EQ K!*) in first line?
   if p=0 then 1
    else begin scalar x;
        if subfg!* and (x:= atsoc(u,asymplis!*)) and cdr x<=p
          then return nil;
        sub2chk u;
        return u .** p
   end;

symbolic procedure sub2chk u;
   %determines if kernel U is such that a power substitution is
   %necessary;
   if subfg!*
      and(atsoc(u,powlis!*) or not atom u and car u memq '(expt sqrt))
     then !*sub2 := t;


% ***** FUNCTIONS FOR DIVIDING STANDARD FORMS *****

symbolic procedure quotsq(u,v);
   multsq(u,invsq v);

symbolic procedure quotf!*(u,v);
   if null u then nil
    else (lambda x; if null x then errach list("DIVISION FAILED",u,v)
                         else x)
          quotf(u,v);

symbolic procedure quotf(u,v);
   begin scalar xexp;
        xexp := !*exp;
        !*exp := t;
        u := quotf1(u,v);
        !*exp := xexp;
        return u
   end;

symbolic procedure quotf1(p,q);
   %P and Q are standard forms
   %Value is the quotient of P and Q if it exists or NIL;
   if null p then nil
    else if p=q then 1
    else if q=1 then p
    else if domainp q then quotfd(p,q)
    else if domainp p then nil
    else if mvar p eq mvar q
     then begin scalar u,v,w,x,y,z,z1; integer n;
    a:if idp(u := rank p) or idp(v := rank q) or u<v then return nil;
        %the above IDP test is because of the possibility of a free
        %variable in the degree position from LET statements;
        u := lt!* p;
        v := lt!* q;
        w := mvar q;
        x := quotf1(tc u,tc v);
        if null x then return nil;
        n := tdeg u-tdeg v;
        if n neq 0 then y := w .** n;
%       p := addf2zro(p,multf(if n=0 then q
        p := addf(p,multf(if n=0 then q else multpf(y,q),negf x));
        %leading terms of P and Q do not cancel if MCD is off;
        %however, there may be a problem with off exp;
        if p and (domainp p or not(mvar p eq w)) then return nil
         else if n=0 then go to b;
        z := aconc!*(z,y .* x);
        %provided we have a non-zero power of X, terms
        %come out in right order;
        if null p then return if z1 then rnconc(z,z1) else z;
        go to a;
    b:  if null p then return rnconc(z,x)
         else if !*mcd then return nil
         else z1 := x;
        go to a
   end
    else if ordop(mvar p,mvar q) then quotk(p,q)
    else nil;

% symbolic procedure addf2zro(p,q);
%    <<q := addf(p,q);
%      if not dmode!* memq '(!:rd!: !:cr!:)
%         or null q or null (p := quotf(q,p)) then q
%      else if domainp p then
%         if eqcar(p,'!:rd!:)
%            and lessp!:(abs!: bfloat round!* p,rd!-tolerance!*)
%         or eqcar(p,'!:cr!:)
%        and (lessp!:(plus!:(times!:(x,x),times!:(y,y)),cr!-tolerance!*)
%               where x=bfloat round!* tagrl p,y=bfloat round!* tagim p)
%        then nil else q>>;

symbolic procedure rnconc(u,v);
   % This is a "Reduce" version of nconc that doesn't assume that
   % its second argument is a list.  It can be replaced by nconc
   % (or append) in systems that don't have such a requirement.
   if null u then v
    else begin scalar w;
            w := u;
            while cdr w do <<w := cdr w>>;
            rplacd(w,v);
            return u
         end;

symbolic procedure quotfd(p,q);
   % P is a standard form, Q a domain element.
   % Value is P/Q if exact division is possible, or NIL otherwise.
   if p=q then 1
   else if flagp(dmode!*,'field) then divd(p,q)
   else if domainp p then quotdd(p,q)
   else quotk(p,q);

symbolic procedure divd(v,u);
   % U is a domain element, V a standard form.
   % Value is standard form for V/U.
   if null u
     then if null v then rerror(poly,1,"0/0 formed")
           else rerror(poly,2,"Zero divisor")
    else if null v then nil
    else if domainp v then divdm(v,u)
    else lpow v .* divd(lc v,u) .+ divd(red v,u);

symbolic procedure divdm(v,u);
   % U and V are both non-zero domain elements.
   % Value is standard form for V/U.
   if atom v and atom u
     then if remainder(v,u)=0 then v/u
           else !:rn2rd mkrn(v,u)
    else y % (if null dmode!* then y else int!-equiv!-chk y)
          where y=dcombine(v,u,'quotient);

symbolic procedure quotdd(u,v);
   % U and V are domain elements.  Value is U/V if division is exact,
   % NIL otherwise.
   if atom u then if atom v
         %          then if remainder(u,v)=0 then u/v else nil
                    then (if cdr div = 0 then car div else nil)
                                   where div = divide(u,v)
                   else quotdd(apply1(get(car v,'i2d),u),v)
    else if atom v then quotdd(u,apply1(get(car u,'i2d),v))
    else dcombine(u,v,'quotient);

symbolic procedure quotk(p,q);
   (lambda w;
      if w then if null red p then list (lpow p .* w)
                 else (lambda y;if y then lpow p .* w .+ y else nil)
                          quotf1(red p,q)
         else nil)
      quotf1(lc p,q);

symbolic procedure rank p;
   %P is a standard form
   %Value is the rank of P;
   if !*mcd then ldeg p
    else begin integer m,n; scalar y;
        n := ldeg p;
        y := mvar p;
    a:  m := ldeg p;
        if null red p then return n-m;
        p := red p;
        if degr(p,y)=0 then return if m<0 then if n<0 then -m
                else n-m else n;
        go to a
    end;

symbolic procedure lt!* p;
   %Returns true leading term of polynomial P;
   if !*mcd or ldeg p>0 then car p
    else begin scalar x,y;
        x := lt p;
        y := mvar p;
    a:  p := red p;
        if null p then return x
         else if degr(p,y)=0 then return (y . 0) .* p;
        go to a
   end;

symbolic procedure remf(u,v);
   %returns the remainder of U divided by V;
   if null v then rerror(poly,201,"Zero divisor") else cdr qremf(u,v);

put('remainder,'polyfn,'remf);

symbolic procedure qremf(u,v);
   % Returns the quotient and remainder of U divided by V.
   begin integer n; scalar x,y,z;
        if domainp v then return qremd(u,v);
        z := list nil;   % Final value.
    a:  if domainp u then return praddf(z,nil . u)
         else if mvar u eq mvar v
          then if (n := ldeg u-ldeg v)<0 then return praddf(z,nil . u)
                else <<x := qremf(lc u,lc v);
                y := multpf(lpow u,cdr x);
                z := praddf(z,(if n=0 then car x
                                else multpf(mvar u .** n,car x))
                                . y);
                u := if null car x then red u
                        else addf(addf(u,multf(if n=0 then v
                                        else multpf(mvar u .** n,v),
                                        negf car x)), negf y);
                go to a>>
         else if not ordop(mvar u,mvar v)
          then return praddf(z,nil . u);
        x := qremf(lc u,v);
        z := praddf(z,multpf(lpow u,car x) . multpf(lpow u,cdr x));
        u := red u;
        go to a
   end;

symbolic procedure praddf(u,v);
   % U and V are dotted pairs of standard forms.
   addf(car u,car v) . addf(cdr u,cdr v);

symbolic procedure qremd(u,v);
   % Returns a dotted pair of quotient and remainder of form U
   % divided by domain element V.
   if null u then u . u
    else if v=1 then list u
    else if flagp(dmode!*,'field) then list multd(!:recip v,u)
    else if domainp u then !:divide(u,v)
    else begin scalar x;
        x := qremf(lc u,v);
        return praddf(multpf(lpow u,car x) . multpf(lpow u,cdr x),
                        qremd(red u,v))
   end;

symbolic procedure lqremf(u,v);
   %returns a list of coeffs of powers of V in U, constant term first;
   begin scalar x,y;
      y := list u;
      while car(x := qremf(car y,v)) do y := car x . cdr x . cdr y;
      return reversip!* y
   end;

symbolic procedure minusf u;
   %U is a non-zero standard form.
   %Value is T if U has a negative leading numerical coeff,
   %NIL otherwise;
   if null u then nil
    else if domainp u
           then if atom u then u<0 else apply1(get(car u,'minusp),u)
    else minusf lc u;

symbolic procedure absf!* u;
   % Returns representation for absolute value of standard form U.
   (if domainp u then x else !*p2f mksp(list('abs,prepf x),1))
    where x = absf u;

symbolic procedure absf u;
   if minusf u then negf u else u;

symbolic procedure canonsq u;
   % U is a standard quotient.  Value is a standard quotient in which
   % the leading power of the denominator has a positive numerical
   % coefficient and the denominator is normalized where possible.
   if denr u=1 then u
    else if null numr u then nil ./ 1
    else begin scalar x,y;
       % In previous versions, it was possible for a non-trivial gcd to
       % occur here.  Until an example of this is found, we shall
       % suppress this calculation.
%      if null !*gcd and (x := gcdf(numr u,denr u)) neq 1
%        then u := quotf(numr u,x) ./ quotf(denr u,x);
       % Now adjust for a positive leading numerical coeff in denr.
        x := lnc denr u;
        if x=1 then return u
         else if atom x then if minusp x
                               then <<u := negf numr u ./ negf denr u;
                                      x := -x>>
                              else nil
         else if apply1(get(car x,'minusp),x)
                               then <<u := negf numr u ./ negf denr u;
                                      x:= apply2(get(car x,'difference),
                                              apply1(get(car x,'i2d),0),
                                                     x)>>;
        % Now check for a global field mode, a leading domain coeff
        % with field properties or "unit" properties so we can adjust
        % numr and denr.  The tests are done in the following order
        % since the other order will give wrong results with some
        % polynomials with decimal coefficients in dmode :gi:.
      return if not numberp x and (y := get(dmode!*,'unitsfn))
            then apply2(y,u,x)
         else if flagp(dmode!*,'field)
            or not atom x and flagp(car x,'field) then fieldconv(x,u)
         else u
   end;

symbolic procedure fieldconv(x,u);
   % U is a standard quotient and x the leading numerical coefficient
   % of the denominator.  Returns inverse(x)*numr u/denr u.
   % X is a domain, but d may not be; dmode!* or x is field.
   begin scalar n,d,y; n := numr u; d := denr u;
      if null dmode!* then
         <<if not eqcar(x,'!:rn!:)
             then if (y := get(car x,'!:rn!:)) and atom y
                    then x := apply1(y,x)
                   else if get(car x,'quotient)
                    then <<x := dcombine(1,x,'quotient);
                           return multd(x,numr u) ./ multd(x,denr u)>>
                   else errach list("field conversion",x);
           x := (car x) . (cddr x) . cadr x;
           return simpgd if domainp d then multd(x,n) ./ 1
                          else multd(x,n) ./ multd(x,d)>>;
      return if domainp d then divd(n,d) ./ 1
              else divd(n,x) ./ divd(d,x)
   end;

symbolic procedure simpgd u;
   if null flagp(dmode!*,'field) then u
   else begin scalar x;
           if (x := gcdf(numr u,denr u)) neq 1
             then u := quotf(numr u,x) ./ quotf(denr u,x);
           return u
        end;

symbolic procedure lnc u;
   % U is a standard form.  Value is the leading numerical coefficient.
   if null u then 0
    else if domainp u then u
    else lnc lc u;

symbolic procedure invsq u;
   begin
      if null numr u then rerror(poly,3,"Zero divisor");
      u := revpr u;
      if !*rationalize then u := gcdchk u;
      % Since result may not be in lowest terms.
      return canonsq u
   end;

symbolic procedure gcdchk u;
   % Makes sure standard quotient u is in lowest terms.
   (if x neq 1 then quotf(numr u,x) ./ quotf(denr u,x) else u)
   where x = gcdf(numr u,denr u);

endmodule;


module gcd; % Greatest common divisor routines.

% Author: Anthony C. Hearn.

% Copyright (c) 1987 The RAND Corporation.  All rights reserved.

fluid '(!*exp !*ezgcd !*gcd !*heugcd !*mcd asymplis!* dmode!*);

switch ezgcd,heugcd;

symbolic procedure comfac p;
  % P is a non-atomic standard form.
  % CAR of result is lowest common power of leading kernel in
  % every term in P (or NIL). CDR is gcd of all coefficients of
  % powers of leading kernel.
  % If field elements are involved, lnc is normalized to 1.
  % We need GCDF here since the same function is used by EZGCD.
   begin scalar x,y;
        if flagp(dmode!*,'field) and ((x := lnc p) neq 1)
          then p := multd(!:recip x,p);
        if null red p then return lt p;
        x := lc p;
        y := mvar p;
    a:  p := red p;
        if degr(p,y)=0 then return nil . gcdf(x,p)
         else if null red p then return lpow p . gcdf(x,lc p)
         else x := gcdf(lc p,x);
        go to a
   end;

symbolic procedure degr(u,var);
   if domainp u or not mvar u eq var then 0 else ldeg u;

put('gcd,'polyfn,'gcdf!*);

symbolic procedure gcdf!*(u,v);
   begin scalar !*gcd; !*gcd := t; return gcdf(u,v) end;

symbolic procedure gcdf(u,v);
   %U and V are standard forms.
   %Value is the gcd of U and V, complete only if *GCD is true;
   begin scalar !*exp;
      !*exp := t;
      u := if domainp u or domainp v or not !*ezgcd then gcdf1(u,v)
            else ezgcdf(u,v);
      return if minusf u then negf u else u
   end;

symbolic procedure gcdf1(u,v);
   begin scalar w;
      if null u then return v
       else if null v then return u
       else if u=1 or v=1 then return 1
       else if domainp u then return gcdfd(u,v)
       else if domainp v then return gcdfd(v,u)
       else if quotf1(u,v) then return v
       else if quotf1(v,u) then return u;
      w := gcdf2(u,v);
      if !*gcd and not(dmode!* memq '(!:rd!: !:cr!:))
          and (null quotf1(u,w) or null quotf1(v,w))
        then errach list("gcdf failed",prepf u,prepf v);
           % This probably implies that integer overflow occurred.
      return w
   end;

symbolic procedure gcdf2(u,v);
   % U and V are both non-trivial forms. Value is their GCD.
   % We need to rebind asymplis!* to avoid setting higher powers to 0.
   begin scalar asymplis!*,w,z;
      if !*gcd and length(w := kernord(u,v))>1
        then <<w := list setkorder w;   % List used to make sure non-NIL
               u := reorder u;
               v := reorder v>>
       else w := nil;
      if mvar u eq mvar v
        then begin scalar x,y;
                x := comfac u;
                y := comfac v;
                z := gcdf1(cdr x,cdr y);
                if noncomp mvar u then return nil; % We can't handle
                                                   % noncoms further.
                u := quotf1(u,comfac!-to!-poly x);
                v := quotf1(v,comfac!-to!-poly y);
                if !*gcd then z := multf(gcdk(u,v),z)
                 else if v and quotf1(u,v) then z := multf(v,z)
                 else if u and quotf1(v,u) then z := multf(u,z);
                if car x and car y
                  then if pdeg car x>pdeg car y
                         then z := multpf(car y,z)
                        else z := multpf(car x,z)
             end
       else if ordop(mvar u,mvar v) then z := gcdf1(cdr comfac u,v)
       else z := gcdf1(cdr comfac v,u);
      if w then <<setkorder car w; z := reorder z>>;
      return z
   end;

symbolic procedure gcdfd(u,v);
   % U is a domain element, V a form.
   % Value is gcd of U and V.
%  if not atom u and flagp(car u,'field) then 1 else gcdfd1(u,v);
   if flagp(dmode!*,'field) then 1 else gcdfd1(u,v);

symbolic procedure gcdfd1(u,v);
   if null v then u
    else if domainp v then gcddd(u,v)
    else gcdfd1(gcdfd1(u,lc v),red v);

symbolic procedure gcddd(u,v);
   %U and V are domain elements.  If they are invertable, value is 1
   %otherwise the gcd of U and V as a domain element;
   if u=1 or v=1 then 1
%   else if atom u and atom v then gcdn(u,v)
    else if atom u then if atom v then gcdn(u,v)
                         else if fieldp v then 1
                         else dcombine(u,v,'gcd)
    else if atom v
     then if flagp(car u,'field) then 1 else dcombine(u,v,'gcd)
    else if flagp(car u,'field) or flagp(car v,'field) then 1
    else dcombine(u,v,'gcd);

symbolic procedure gcdk(u,v);
   % U and V are primitive polynomials in the main variable VAR.
   % Result is gcd of U and V.
   begin scalar lclst,var,w,x;
        if u=v then return u
         else if domainp u or degr(v,(var := mvar u))=0 then return 1
         else if ldeg u<ldeg v then <<w := u; u := v; v := w>>;
        if quotf1(u,v) then return v
         else if !*heugcd and (x := heu!-gcd(u,v)) then return x
         else if ldeg v=1
           or getd 'modular!-multicheck and modular!-multicheck(u,v,var)
           or not !*mcd
          then return 1;
    a:  w := remk(u,v);
        if null w then return v
         else if degr(w,var)=0 then return 1;
        lclst := addlc(v,lclst);
        if x := quotf1(w,lc w) then w := x
         else for each y in lclst do
            if atom y or not   % prevent endless loop in !:gi!: dmode.
               (domainp y and (x := get(car y,'units))
                and y member (for each z in x collect car z))
            then while (x := quotf1(w,y)) do w := x;
        u := v; v := prim!-part w;
        if degr(v,var)=0 then return 1 else go to a
   end;

symbolic procedure addlc(u,v);
   if u=1 then v
    else (lambda x;
      if x=1 or x=-1 or not atom x and flagp(car x,'field) then v
       else x . v)
     lc u;

symbolic procedure delall(u,v);
   if null v then nil
    else if u eq caar v then delall(u,cdr v)
    else car v . delall(u,cdr v);

symbolic procedure kernord(u,v);
   <<u := kernord!-split(u,v);
     append(kernord!-sort car u,kernord!-sort cdr u)>>;

symbolic procedure kernord!-split(u,v);
   % splits U and V into a set of powers of those kernels occurring in
   % one form and not the other, and those occurring in both;
   begin scalar x,y;
      u := powers u;
      v := powers v;
      for each j in u do
          if assoc(car j,v) then y := j . y else x := j . x;
      for each j in v do
          if assoc(car j,u) then y := j . y else x := j . x;
      return reversip x . reversip y
   end;

symbolic procedure kernord!-sort u;
   % returns list of kernels ordered so that kernel with lowest maximum
   % power in U (a list of powers) is first, and so on;
   begin scalar x,y;
      while u do
       <<x := maxdeg(cdr u,car u);
         u := delall(car x,u);
         y := car x . y>>;
      return y
   end;

symbolic procedure maxdeg(u,v);
   if null u then v
    else if cdar u>cdr v then maxdeg(cdr u,car u)
    else maxdeg(cdr u,v);

symbolic procedure powers form;
   % returns a list of the maximum powers of each kernel in FORM.
   % order tends to be opposite to original order.
   powers0(form,nil);

symbolic procedure powers0(form,powlst);
   if null form or domainp form then powlst
    else begin scalar x;
        if (x := atsoc(mvar form,powlst))
%         then ldeg form>cdr x and rplacd(x,ldeg form)
          then (if ldeg form>cdr x
                  then powlst := repasc(mvar form,ldeg form,powlst))
         else powlst := (mvar form . ldeg form) . powlst;
        return powers0(red form,powers0(lc form,powlst))
     end;

put('lcm,'polyfn,'lcm!*);

symbolic procedure lcm!*(u,v);
   begin scalar !*gcd; !*gcd := t; return lcm(u,v) end;

symbolic procedure lcm(u,v);
   %U and V are standard forms. Value is lcm of U and V;
   if null u or null v then nil
    else if u=1 then v     % ONEP
    else if v=1 then u     % ONEP
    else multf(u,quotf(v,gcdf(u,v)));

symbolic procedure remk(u,v);
   %modified pseudo-remainder algorithm
   %U and V are polynomials, value is modified prem of U and V;
   begin scalar f1,var,x; integer k,n;
        f1 := lc v;
        var := mvar v;
        n := ldeg v;
        while (k := degr(u,var)-n)>=0 do
         <<x := negf multf(lc u,red v);
           if k>0 then x := multpf(var .** k,x);
           u := addf(multf(f1,red u),x)>>;
        return u
   end;

symbolic procedure prim!-part u;
   %returns the primitive part of the polynomial U wrt leading var;
   quotf1(u,comfac!-to!-poly comfac u);

symbolic procedure comfac!-to!-poly u;
   if null car u then cdr u else list u;

endmodule;


module exptf; % Functions for raising canonical forms to a power.

% Author: Anthony C. Hearn.

% Copyright (c) 1990 The RAND Corporation.  All rights reserved.

fluid '(!*exp);

symbolic procedure exptsq(u,n);
   begin scalar x;
        if n=1 then return u
         else if n=0
           then return if null numr u
                         then rerror(poly,4," 0**0 formed")
                        else 1 ./ 1
         else if null numr u then return u
         else if n<0 then return simpexpt list(mk!*sq u,n)
         else if null !*exp
          then return mksfpf(numr u,n) ./ mksfpf(denr u,n)
         else if kernp u then return mksq(mvar numr u,n)
         else if domainp numr u
          then return multsq(!:expt(numr u,n) ./ 1,
                             1 ./ exptf(denr u,n))
         else if denr u=1 then return exptf(numr u,n) ./ 1;
        x := u;
%       while (n := n-1)>0 do x := multsq(u,x);
        % Since U is in lowest terms, then so is U^N.
        while (n := n-1)>0
           do x := multf(numr u,numr x) ./ multf(denr u,denr x);
        return x
   end;

symbolic procedure exptf(u,n);
   if domainp u then !:expt(u,n)
    else if !*exp or kernlp u then exptf1(u,n)
    else mksfpf(u,n);

symbolic procedure exptf1(u,n);
   % Iterative multiplication seems to be faster than a binary sub-
   % division algorithm, probably because multiplying a small polynomial
   % by a large one is cheaper than multiplying two medium sized ones.
   if n=0 then 1
    else begin scalar x;
         x := u; while (n := n-1)>0 do x := multf(u,x); return x
         end;

symbolic procedure exptf2(u,n);
   % Binary version of EXPTF1, Used with EXP off, since expressions
   % formed in that case tend to be smaller than with EXP on.
   if n=0 then 1
    else begin scalar x; integer m;
         x := 1;
    a:   m := n;
         if m-2*(n := n/2) neq 0 then x := multf(u,x);
         if n=0 then return x;
         u := multf(u,u);
         go to a
      end;

endmodule;


module kernel;   % Functions for operations on kernels.

% Author: Anthony C. Hearn.

% Copyright (c) 1990 The RAND Corporation.  All rights reserved.

global '(exlist!* kprops!*);

symbolic procedure fkern u;
   % Finds the unique "p-list" reference to the kernel U.  The choice of
   % the search and merge used here has a strong influence on some
   % timings.  The ordered list used here is also used by prepsq* to
   % order factors in printed output, so cannot be unilaterally changed.
   begin scalar x,y;
        if atom u then return list(u,nil);
        y := if atom car u then get(car u,'klist) else exlist!*;
        if not (x := assoc(u,y))
          then <<x := list(u,nil);
                 y := ordad(x,y);
                 if atom car u
                   then <<kprops!* := union(list car u,kprops!*);
                          put(car u,'klist,y)>>
                  else exlist!* := y>>;
        return x
   end;

symbolic procedure kernels u;
   % Returns list of kernels in standard form u.
   kernels1(u,nil);

symbolic procedure kernels1(u,v);
   % We append to end of list to put kernels in the right order, even
   % though a cons on the front of the list would be faster.
   if domainp u then v
    else kernels1(lc u,
                  kernels1(red u,
                           if x memq v then v else append(v,list x)))
         where x=mvar u;

symbolic procedure kernp u;
   % True if U is standard quotient representation for a kernel.
   denr u=1 and not domainp(u := numr u)
        and null red u and lc u=1 and ldeg u=1;     % onep

endmodule;


module mksp; % Functions for making standard powers.

% Author: Anthony C. Hearn.

% Copyright (c) 1991 RAND.  All rights reserved.

% This module has a non-trivial use of ACONC.

fluid '(!*nosubs !*sub2 asymplis!* wtl!*);

% fluid '(varstack!*);

global '(!*resubs
         powlis!*
         subfg!*);

% exports mksfpf,mksp,mksq,to;

% imports !*p2f,aconc,eqcar,exptf,exptsq,leq,mkprod!*,module,multsq,
%       ordad,over,simpcar,union;

symbolic procedure getpower(u,n);
   %U is a list (<kernel> . <properties>), N a positive integer.
   %Value is the standard power of U**N;
   <<if eqcar(car u,'expt) and n>1 then !*sub2 := t; car u . n>>;
%   begin scalar v;
%       v := cadr u;
%       if null v then return caar rplaca(cdr u,list (car u . n));
%    a: if n=cdar v then return car v
%        else if n<cdar v
%           then return car rplacw(v,(caar v . n) . (car v . cdr v))
%        else if null cdr v
%           then return cadr rplacd(v,list (caar v . n));
%       v := cdr v;
%       go to a
%   end;

symbolic procedure mksp(u,p);
   %U is a (non-unique) kernel and P a non-zero integer
   %Value is the standard power for U**P;
   getpower(fkern u,p);

symbolic procedure u to p;
   %U is a (unique) kernel and P a non-zero integer;
   %Value is the standard power of U**P;
   u . p;
%   getpower(fkern u,p);

symbolic procedure mksp!*(u,n);
   % Returns a standard form for U**N. If U is a kernel product,
   % direct exponentiation is used.  Otherwise, U is first made
   % positive and then converted into a kernel.
   begin scalar b;
      if null u or kernlp u then return exptf(u,n)
       else if minusf u then <<b := t; u := negf u>>;
      u := !*p2f mksp(u,n);
      return if b and not evenp n then negf u else u
   end;

symbolic procedure mksfpf(u,n);
   % Raises form U to power N with EXP off. Returns a form.
   % If we assume that MKPROD returns a kernlp form, check for red x
   % is redundant.
   (if n=1 then x
     else if domainp x then !:expt(x,n)
     else if n>=0 and onep lc x and null red x
      then !*p2f mksp(mvar x,ldeg x*n)
     else exptf2(x,n))
    where x=mkprod u;

symbolic procedure mksq(u,n);
    % U is a kernel, N a non-zero integer.
    % Value is a standard quotient of U**N, after making any
    % possible substitutions for U.
   begin scalar x,y,z;
%  (begin scalar x,y,z;
        if null subfg!* then go to a1
         else if (y := assoc(u,wtl!*))
                and null car(y := mksq('k!*,n*cdr y)) then return y
         else if not atom u then go to b
         else if null !*nosubs and (z:= get(u,'avalue)) then go to c;
        if idp u then flag(list u,'used!*);
        %tell system U used as algebraic var (unless it's a string);
    a:  if !*nosubs or n=1 then go to a1
         else if (z:= assoc(u,asymplis!*)) and cdr z<=n
          then return nil ./ 1
         else if ((z:= assoc(u,powlis!*))
                or not atom u and car u memq '(expt sqrt)
                and (z := assoc(cadr u,powlis!*)))
             and not(n*cadr z)<0
           % Implements explicit sign matching.
          then !*sub2 := t;
    a1: if null x then x := fkern u;
        x := !*p2f getpower(x,n) ./ 1;
        return if y then multsq(y,x) else x;
    b:  if null !*nosubs and atom car u
           and (z:= assoc(u,get(car u,'kvalue)))
          then go to c
         else if not('used!* memq cddr (x := fkern u))
          then aconc(x,'used!*);
        go to a;
    c:  z := cdr z;
%       varstack!* := u . varstack!*;   % I don't think this is needed.
        %optimization is possible as shown if all expression
        %dependency is known;
        %if cdr z then return exptsq(cdr z,n); % Value already computed.
        if null !*resubs then !*nosubs := t;
        x := simpcar z;
        !*nosubs := nil;
        %rplacd(z,x);           % Save simplified value.
        %subl!* := z . subl!*;
        return exptsq(x,n)
   end;
%  end) where varstack!* := varstack!*; % I don't think this is needed.

endmodule;


module reord; % Functions for reordering standard forms.

% Author: Anthony C. Hearn.

% Copyright (c) 1990 The RAND Corporation.  All rights reserved.

fluid '(alglist!* kord!*);

global '(ncmp!*);

alglist!* := nil . nil;         % This is first module that uses this.

symbolic procedure reordsq u;
   % Reorders a standard quotient so that current kernel order is used.
   reorder numr u ./ reorder denr u;

symbolic procedure reorder u;
   % Reorders a standard form so that current kernel order is used.
   if domainp u then u
    else raddf(rmultpf(lpow u,reorder lc u),reorder red u);

symbolic procedure raddf(u,v);
   % Adds reordered forms U and V.
   if null u then v
    else if null v then u
    else if domainp u then addd(u,v)
    else if domainp v then addd(v,u)
    else if peq(lpow u,lpow v)
     then (lpow u .* raddf(lc u,lc v)) .+ raddf(red u,red v)
    else if ordpp(lpow u,lpow v) then lt u . raddf(red u,v)
    else lt v . raddf(u,red v);

symbolic procedure rmultpf(u,v);
  % Multiplies power U by reordered form V.
   if null v then nil
    else if domainp v or reordop(car u,mvar v) then !*t2f(u .* v)
    else (lpow v .* rmultpf(u,lc v)) .+ rmultpf(u,red v);

symbolic procedure reordop(u,v);
   if ncmp!* and noncomp u and noncomp v then t else ordop(u,v);

symbolic procedure korder u;
   <<kord!* := if u = '(nil) then nil
                else for each x in u collect !*a2k x;
     rmsubs()>>;

rlistat '(korder);

symbolic procedure setkorder u;
   begin scalar v;
      v := kord!*;
      if u=v then return v;
      kord!* := u;
      alglist!* := nil . nil;        % Since kernel order has changed.
      return v
   end;

symbolic procedure updkorder u;
   % U is a kernel.  Value is previous kernel order.
   % This function is used when it is necessary to give one kernel
   % highest precedence (e.g., when extracting coefficients), but not
   % change the order of the other kernels.
   begin scalar v,w;
      v := kord!*;
      w := u . delete(u,v);
      if v=w then return v;
      kord!* := w;
      alglist!* := nil . nil;        % Since kernel order has changed.
      return v
   end;

endmodule;


module dmode; % Functions for defining and using poly domain modes.

% Author: Anthony C. Hearn.
% Modifications by: Stanley L. Kameny.

% Copyright (c) 1992 RAND.  All rights reserved.

Comment
   *** Description of Definition Requirements for Domain arithmetics ***

Syntactically, such elements have the following form:

<domain element>:=NIL|integer|<structured domain element>

<structured domain element> ::=
        (<domain identifier>.<domain structure>),

where NIL represents the domain element zero.

To introduce a new domain, we need to define:

1) A conversion function from integer to the given mode, stored under
   the attribute I2D.

2) A conversion function from new mode to or from every other mode.

3) Particular instances of the binary operations +,- and * for this
   mode.

4) Particular instances of ZEROP, ONEP and MINUSP for this mode.
   Although ONEP could be defined in terms of ZEROP, we believe it is
   more efficient to have both functions (though this has not been
   thoroughly tested).

5) If domain is a field, a quotient must be defined.  If domain is a
   ring, a gcd and divide must be defined, and also a quotient
   function which returns NIL if the division fails.

6) A printing function for this mode that can print the object in a
   linear form. The printing function is associated with the attribute
   PRIFN.  This printing function should enclose the printed expression
   in parentheses if its top level operator has a precedence greater
   than +.

7) A function to convert structure to an appropriate prefix form.

8) A reading function for this mode.

9) A DNAME property for the tag, and a TAG property for the DNAME

10) Optionally, an exponentiation function. If this is not provided,
    repeated squaring is used (cf !:expt in dmodeop.red)

To facilitate this, all such modes should be listed in the global
variable DOMAINLIST!*.

The following rules should also be followed when introducing new
domains:

Some modes, such as modular arithmetic, require that integers be
converted to domain elements when input or addition or multiplication
of such objects occurs.  Such modes should be flagged "convert".

A domain which holds mutable internal state should be flagged
"resimplify" (no Reduce domains are currently so flagged) which means
that attempts to simplify domain elements will actually do so, rather
than just thinking "domain elements are always simplified".

In ALL cases it is assumed that any domain element that tests true to
the zero test can be converted into an explicit 0 (represented by NIL),
and any that tests true to the onep test can be converted into an
explicit 1.  If the domain allows for the conversion of other elements
into equivalent integers, a function under the optional attribute
INTEQUIVFN may also be defined to effect this conversion.

The result of an arithmetic (as opposed to a boolean) operation on
structured domain elements with the same tag must be another structured
domain element with the same tag.  In particular, a domain zero must be
returned as a tagged zero in that domain.

In some cases, it is possible to map functions on domain elements to
domain elements.  To provide for this capability in the complete
system, one can give such functions the domain tag as an indicator.
The results of this evaluation must be a tagged domain element (or an
integer?), but not necessarily an element from the same domain, or the
evaluation should abort with an error.  The error number associated
with this should be in the range 100-150;

fluid '(!*complex dmode!*);

global '(domainlist!*);

symbolic procedure initdmode u;
   % Checks that U is a valid domain mode, and sets up appropriate
   % interfaces to the system.
   begin
      dmodechk u;
      put(u,'simpfg,list(list(t,list('setdmode,mkquote u,t)),
                         list(nil,list('setdmode,mkquote u,nil))))
   end;

switch complex!-rational,complex!-rounded;

symbolic procedure setdmode(u,bool);
   % Sets polynomial domain mode.  If bool is NIL, integers are used,
   % or in the case of complex, set to the lower domain.
   % Otherwise mode is set to u, or derived from it.
   begin scalar x;
      if u eq 'complex!-rational then
        <<if (x := dmode!*) then x := get(x,'dname);
          onoff('complex,bool); onoff('rational,bool);
          return x>>
        else if u eq 'complex!-rounded then
          <<if (x := dmode!*) then x := get(x,'dname);
            onoff('complex,bool); onoff('rounded,bool);
            return x>>;
      if null get(u,'tag)
        then rerror(poly,5,
                   list("Domain mode error:",u,"is not a domain mode"));
      if x := get(u,'package!-name) then load!-package x;
      return if u eq 'complex or !*complex then setcmpxmode(u,bool)
              else setdmode1(u,bool)
   end;

symbolic procedure setdmode1(u,bool);
   begin scalar x,y,z;
      x := get(u,'tag);
      y := dmode!*;
      if null bool
        then return if null y then nil
                     else if u eq (y := get(y,'dname))
                      then <<rmsubs(); dmode!* := nil; y>>
                     else offmoderr(u,y)
        else <<if u memq '(rounded complex!-rounded) then !!mfefix();
               if x eq y then return x>>;
      % Now make sure there are no other domain switches left on.
      if not (z := get(x,'realtype)) then z := x;
      for each j in domainlist!* do
         if j neq '!:gi!: and not(j eq z)
           then set(intern compress
                       append(explode '!*,explode get(j,'dname)),
                    nil);
      rmsubs();
      y := get(y,'dname);
      if y then lprim list("Domain mode",y,"changed to",u);
      dmode!* := x;
      return y
   end;

symbolic procedure offmoderr(u,y);
   lpriw("***",list("Failed attempt to turn off",u,"when",y,"is on"));

symbolic procedure dmodechk u;
   % Checks to see if U has complete specification for a domain mode.
   begin scalar z;
      if not(z := get(u,'tag))
        then rerror(poly,6,list("Domain mode error:","No tag for",u))
       else if not(get(z,'dname) eq u)
        then rerror(poly,7,list("Domain mode error:",
                                 "Inconsistent or missing DNAME for",z))
       else if not z memq domainlist!*
        then rerror(poly,8,list("Domain mode error:",
                                 z,"not on domain list"));
      u := z;
      for each x in domainlist!*
        do if u=x then nil
            else <<if not get(u,x) then put(u,x,mkdmoderr(u,x));
                   if not get(x,u) then put(x,u,mkdmoderr(x,u))>>;
%            then rederr list("Domain mode error:",
%                          "No conversion defined between",U,"and",X);
      z := '(plus difference times quotient i2d prepfn prifn
             minusp onep zerop);
      if not flagp(u,'field) then z := 'divide . 'gcd . z;
      for each x in z do if not get(u,x)
             then rerror(poly,9,list("Domain mode error:",
                                      x,"is not defined for",u))
   end;

symbolic procedure dmoderr(u,v);
   rerror(poly,10,list("Conversion between",get(u,'dname),
                       "and",get(v,'dname),"not defined"));

symbolic procedure mkdmoderr(u,v);
   list('lambda,'(!*x!*),list('dmoderr,mkquote u,mkquote v));

endmodule;


module dmodeop;  % Generic operators for domain arithmetic.

% Author: Anthony C. Hearn.

% Copyright (c) 1991 The RAND Corporation.  All rights reserved.

% internal dividef;

fluid '(!*noequiv);    % !*convert

% switch convert;

% !*convert := t;

symbolic procedure !:difference(u,v);
   if null u then !:minus v else if null v then u
    else if u=v then nil
    else if atom u and atom v then u-v
    else dcombine(u,v,'difference);

symbolic procedure !:divide(u,v);
   % Returns a dotted pair of quotient and remainder of non-invertable
   % domain element U divided by non-invertable domain element V.
   % Note that a zero is returned as NIL.
   if null u then nil . nil
    else if null v then rerror(poly,202,"zero divisor")
    else if atom u and atom v then dividef(u,v)
    else dcombine(u,v,'divide);

symbolic procedure dividef(m,n);
   ((if car x=0 then nil else car x) . if cdr x=0 then nil else cdr x)
   where x=divide(m,n);

symbolic procedure !:expt(u,n);
   % Raises domain element U to integer power N.  Value is a domain
   % element.
   if null u then if n=0 then rerror(poly,11,"0/0 formed") else nil
    else if n=0 then 1
    else if n=1 then u
    else if u=1 then 1
    else if n<0
     then !:recip !:expt(if not fieldp u then mkratnum u else u,-n)
    else if atom u then u**n
%    Moved into the exponentiation method of !:mod!:
%    else if car u eq '!:mod!:
%     then (lambda x; if x=0 then nil else if x=1 then 1 else car u . x)
%          general!-modular!-expt(cdr u,n)
    else begin scalar v,w,x;
      if x := get(car u,'expt)
         then return apply2(x,u,n);
         % There was a special exponentiation method.
      v := apply1(get(car u,'i2d),1);   % unit element.
      x := get(car u,'times);
   a: w := n;
      if w-2*(n := n/2) neq 0 then v := apply2(x,u,v);
      if n=0 then return v;
      u := apply2(x,u,u);
      go to a
   end;

symbolic procedure !:gcd(u,v);
  if null u then v else if null v then u
   else if atom u and atom v then gcdn(u,v)
   else if fieldp u or fieldp v then 1
   else dcombine(u,v,'gcd);

% symbolic procedure !:i2d u;

symbolic procedure !:minus u;
   % U is a domain element. Value is -U.
   if null u then nil
    else if atom u then -u
    else (if x then apply1(x,u) else dcombine(u,-1,'times))
         where x=get(car u,'minus);

symbolic procedure !:minusp u;
   if atom u then minusp u else apply1(get(car u,'minusp),u);

symbolic procedure !:onep u;
   if atom u then onep u else apply1(get(car u,'onep),u);

symbolic procedure !:plus(u,v);
   if null u then v else if null v then u
    else if atom u and atom v
     then (if w=0 then nil else w) where w=u+v
    else dcombine(u,v,'plus);

% symbolic procedure !:prep u;

% symbolic procedure !:print u;

symbolic procedure !:quotient(u,v);
   if null u or u=0 then nil
    else if null v or v=0 then rerror(poly,12,"Zero divisor")
    else if atom u and atom v
     % We might also check that remainder is zero in integer case.
     then if null dmode!* then u/v else dcombine(u,!:recip v,'times)
    else dcombine(u,v,'quotient);

symbolic procedure !:recip u;
   % U is an invertable domain element. Value is 1/U.
   begin
      if numberp u
        then if abs u=1 then return u
       else if null dmode!* or dmode!* memq '(!:rd!: !:cr!:)
          then return !:rn2rd mkrn(1,u)
       else u := apply1(get(dmode!*,'i2d),u);
      return (if car u='!:rn!: then !:rn2rd x else x)
         where x=dcombine(1,u,'quotient)
   end;

symbolic procedure !:rn2rd x;
   % Convert rn to rd in dmodes rd and cr if roundall is on.
   if !*roundall and !*rounded then !*rn2rd x else x;

symbolic procedure !:times(u,v);
   % We assume neither u nor v can be 0.
   if null u or null v then nil
    else if atom u and atom v then u*v
    else dcombine(u,v,'times);

symbolic procedure !:zerop u;
   if null u or u=0 then t
    else if atom u then nil
    else apply1(get(car u,'zerop),u);

symbolic procedure fieldp u;
   % U is a domain element. Value is T if U is invertable, NIL
   % otherwise.
   not atom u and flagp(car u,'field);

symbolic procedure gettransferfn(u,v);
   % This may be unnecessary.  If dmodechk has been called, then all
   % transfer functions should be defined.
   (if x then x else dmoderr(u,v)) where x=get(u,v);

symbolic procedure dcombine(u,v,fn);
   %U and V are domain elements, but not both atoms (integers).
   % FN is a binary function on domain elements;
   % Value is the domain element representing FN(U,V).
   % If dmode!* is other than rd or cr, output mode eq dmode!*.
     int!-equiv!-chk if atom u
        then apply2(get(car v,fn),apply1(get(car v,'i2d),u),v)
       else if atom v
        then apply2(get(car u,fn),u,apply1(get(car u,'i2d),v))
       else if car u eq car v then apply2(get(car u,fn),u,v) else
      % convert real to complex, never the reverse;
      % also convert rn or crn to rd or cr but not the reverse:
      % hence crn or gi plus rd requires that *both* convert to cr.
      (<<if not(x and atom x) or get(du,'cmpxfn) and not get(dv,'cmpxfn)
            or du memq dl and not dv memq dl then
            % convert v -> u but may first have to convert u.
            <<if du memq dml and dv eq '!:rd!:
                 or du eq '!:rd!: and dv memq dml then
                 <<u := apply1(get(du,'!:cr!:),u); du := '!:cr!:>>
              else if du eq '!:rn!: and dv eq '!:gi!:
                 or du eq '!:gi!: and dv eq '!:rn!: then
                 <<u := apply1(get(du,'!:crn!:),u); du := '!:crn!:>>;
              v := apply1(get(dv,du),v); x := get(du,fn)>>
            else <<u := apply1(x,u); x := get(dv,fn)>>;
         apply2(x,u,v)>>
       where du=car u,dv=car v,x=get(car u,car v),
             dml='(!:crn!: !:gi!:),dl='(!:rd!: !:cr!:));

symbolic procedure int!-equiv!-chk u;
   % U is a domain element. If U can be converted to 0, result is NIL,
   % if U can be converted to 1, result is 1,
   % if U is a rational or a complex rational and can be converted to
   % an integer, result is that integer,
   % if *convert is on and U can be converted to an integer, result
   % is that integer. Otherwise, U is returned.
   % In most cases, U will be structured.
   if !*noequiv then u
    else begin scalar x;
           if atom u then return if u=0 then nil else u
            else if apply1(get(car u,'zerop),u) then return nil
            else if apply1(get(car u,'onep),u) then return 1
%           else if null !*convert then return u
            else if (x := get(car u,'intequivfn)) and (x := apply1(x,u))
             then return if x=0 then nil else x
            else return u
      end;

% symbolic procedure minuschk u;
%    if eqcar(u,'minus)
%       and (numberp cadr u
%          or not atom cadr u and idp caadr u and get(caadr u,'dname))
%      then !:minus cadr u
%     else u;

endmodule;


module rational; % *** Tables for rational numbers ***.

% Author: Anthony C. Hearn.

% Copyright (c) 1987 The RAND Corporation.  All rights reserved.

global '(domainlist!*);

switch rational;

domainlist!* := union('(!:rn!:),domainlist!*);
put('rational,'tag,'!:rn!:);
put('!:rn!:,'dname,'rational);
flag('(!:rn!:),'field);
put('!:rn!:,'i2d,'!*i2rn);
put('!:rn!:,'!:ft!:,'!*rn2ft);
put('!:rn!:,'minus,'rnminus!:);
put('!:rn!:,'minusp,'rnminusp!:);
put('!:rn!:,'plus,'rnplus!:);
put('!:rn!:,'times,'rntimes!:);
put('!:rn!:,'difference,'rndifference!:);
put('!:rn!:,'quotient,'rnquotient!:);
put('!:rn!:,'zerop,'rnzerop!:);
put('!:rn!:,'onep,'rnonep!:);
put('!:rn!:,'factorfn,'rnfactor!:);
put('!:rn!:,'expt,'rnexpt!:);
put('!:rn!:,'prepfn,'rnprep!:);
put('!:rn!:,'prifn,'rnprin);
put('!:rn!:,'intequivfn,'rnequiv);
flag('(!:rn!:),'ratmode);

symbolic procedure rnexpt!:(u,n);
  % U is a tagged rational number, n an integer.
  begin scalar v;
     if n=0 then return 1;
     v:=cdr u;
     if (n<0) then <<
        n:=-n;
        if (car v < 0) then
           v:= (- cdr v) . (- car v)
           else v:= (cdr v) . (car v) >>;
     if (n=1) then return (car u) . v;
     return (car u) . ((car v ** n) . (cdr v ** n));
     % No more cancellation can take place in this exponentiation.
  end;

symbolic procedure mkratnum u;
   %U is a domain element. Value is equivalent rational number;
   if atom u then !*i2rn u else apply1(get(car u,'!:rn!:),u);

symbolic procedure mkrn(u,v);
   %converts two integers U and V into a rational number, an integer
   %or NIL;
   if v<0 then mkrn(-u,-v)
    else (lambda m; '!:rn!: . ((u/m) . (v/m))) gcdn(u,v);

symbolic procedure !*i2rn u;
   %converts integer U to rational number;
   '!:rn!: . (u . 1);

symbolic procedure rnminus!: u;
   % We must allow for a rational with structured arguments, since
   % lowest-terms can produce such objects.
   car u . !:minus cadr u . cddr u;

symbolic procedure rnminusp!: u;
   % We must allow for a rational with structured arguments, since
   % lowest-terms can produce such objects.
   if atom (u := cadr u) then u < 0 else apply1(get(car u,'minusp),u);

symbolic procedure rnplus!:(u,v);
   mkrn(cadr u*cddr v+cddr u*cadr v,cddr u*cddr v);

symbolic procedure rntimes!:(u,v);
   mkrn(cadr u*cadr v,cddr u*cddr v);

symbolic procedure rndifference!:(u,v);
   mkrn(cadr u*cddr v-cddr u*cadr v,cddr u*cddr v);

symbolic procedure rnquotient!:(u,v);
   mkrn(cadr u*cddr v,cddr u*cadr v);

symbolic procedure rnzerop!: u; cadr u=0;

symbolic procedure rnonep!: u; cadr u=1 and cddr u=1;

symbolic procedure rnfactor!: u;
   begin scalar x,y,dmode!*; integer m,n;
     x := subf(u,nil);
     y := factorf numr x;
     n := car y;
     dmode!* := '!:rn!:;
     y := for each j in cdr y collect
           <<n := n*(m := (lnc ckrn car j)**cdr j);
             quotfd(car j,m) . cdr j>>;
     return int!-equiv!-chk mkrn(n,denr x) . y
   end;

symbolic procedure rnprep!: u;
   % PREPF is called on arguments, since the LOWEST-TERMS code in extout
   % can create rational objects with structured arguments.
   (if cddr u=1 then x else list('quotient,x,prepf cddr u))
    where x = prepf cadr u;

symbolic procedure rnprin u;
   <<prin2!* cadr u; prin2!* "/"; prin2!* cddr u>>;

symbolic procedure rnequiv u;
   % Returns an equivalent integer if possible.
   if cdr(u := cdr u)=1 then car u else nil;

initdmode 'rational;

endmodule;


module rnelem;

% This module adds 10 integer functions to mode rational.

deflist('((fix rnfix!*) (sgn rnsgn!*) (round rnround!*)
  (ceiling rnceiling!*) (floor rnfloor!*) (isqrt rnisqrt!*)
  (icbrt rnicbrt!*) (irootn rnirootn!*) (ilog2 rnilog2!*)
  (factorial rnfactorial!*) (perm rnperm!*) (choose rnchoose!*))
  ,'!:rn!:);

for each c in '(fix sgn round ceiling floor isqrt icbrt irootn ilog2
 factorial perm choose) do put(c,'simpfn,'simpiden);

flag('(fix sgn floor ceiling round isqrt icbrt irootn ilog2 factorial
 perm choose) ,'integer);

deflist('((perm 2) (choose 2)),'number!-of!-args);

symbolic procedure rnfix!* x; quotient(cadr x,cddr x);

symbolic procedure rnfixchk x;
   (if cdr y=0 then car y
    else error(0,list(prepf x,"is not an integer equivalent")))
   where y=divide(cadr x,cddr x);

symbolic procedure rnsgn!* x; sgn cadr x;

symbolic procedure rnfloor!* x;
   if cdr(x := divide(cadr x,cddr x))<0 then car x-1 else car x;

symbolic procedure rnceiling!* x;
   if cdr(x := divide(cadr x,cddr x))>0 then car x+1 else car x;

symbolic procedure rnround!* x;
   (if cadr rndifference!:(x,!*i2rn y)=0 then y
    else if rnminusp!: x then -rnround!*('!:rn!: . ((-cadr x) . cddr x))
    else rnfloor!*(rnplus!:(x,'!:rn!: . (1 . 2)))) where y=rnfix!* x;

symbolic procedure rnisqrt!* x; isqrt rnfix!* x;

symbolic procedure rnilog2!* x; ilog2 rnfix!* x;

symbolic procedure rnfactorial!* x;
   (if fixp y and not(y<0) then nfactorial y
    else !*p2f mksp(list('factorial,y),1))
    where y=rnfixchk x;

symbolic procedure rnperm!*(x,n); perm(rnfixchk x,rnfixchk n);

symbolic procedure perm(x,n);
   if not fixp x or not fixp n or x<1 or x>n
      then terrlst(list(x,n),'perm) else for j := n-x+1:n product j;

symbolic procedure rnchoose!*(x,n); choose(rnfixchk x,rnfixchk n);

symbolic procedure choose(x,n); perm(x,n)/factorial x;

symbolic procedure simprn x;
   begin scalar dmode!*; dmode!* := '!:rn!:;
   return for each a in simplist x collect
      if atom a then !*i2rn a else a end;

symbolic procedure rnicbrt!* x; icbrt rnfix!* x;

symbolic procedure rnirootn!*(x,n); irootn(rnfix!* x,rnfixchk n);


endmodule;


module gint;  % Support for gaussian integers (complex numbers).

% Author: Eberhard Schruefer.

global '(domainlist!*);

fluid '(!*complex !*gcd);

switch complex;

domainlist!* := union('(!:gi!:),domainlist!*);

symbolic procedure setcmpxmode(u,bool);
   % Sets polynomial domain mode in complex case.
   begin scalar x,y;
      x := get(u,'tag);
      if u eq 'complex
        then if null dmode!*
               then return if null bool then nil
                else <<put('i,'idvalfn,'mkdgi);
                       setdmode1('complex,bool)>>
         else if null bool
                then return if null !*complex then nil
                else if get(dmode!*,'dname) eq 'complex
                      then <<remprop('i,'idvalfn);
                             setdmode1('complex,nil)>>
                     else <<remprop('i,'idvalfn);
                           setdmode1(get(get(dmode!*,'realtype),'dname),
                                       t)>>
         else if dmode!* eq '!:gi!: or get(dmode!*,'realtype)
            then return nil
         else if not (y := get(dmode!*,'cmpxtype))
               then dmoderr(dmode!*,x)
         else <<put('i,'idvalfn,get(y,'ivalue));
                     return setdmode1(get(y,'dname),bool)>>
      else if null bool then
         if u eq (y := get(get(dmode!*,'realtype),'dname)) then
            <<put('i,'idvalfn,'mkdgi); return setdmode1('complex,t)>>
            else offmoderr(u,y)
      else <<u := get(u,'tag);
             y := get(u,'cmpxtype);
             if null y then dmoderr(u,'!:gi!:);
             put('i,'idvalfn,get(y,'ivalue));
             return setdmode1(get(y,'dname),bool)>>
   end;

% Used by gcdk.

symbolic procedure intgcdd(u,v);
   if null u then v
   else if atom u then
      if atom v then gcdn(u,v) else gcdn(cadr v,gcdn(cddr v,u))
   else if atom v then intgcdd(v,u)
      else intgcdd(cadr u,intgcdd(cddr u,v));

put('complex,'tag,'!:gi!:);
put('!:gi!:,'dname,'complex);
put('!:gi!:,'i2d,'!*i2gi);
put('!:gi!:,'minusp,'giminusp!:);
put('!:gi!:,'zerop,'gizerop!:);
put('!:gi!:,'onep,'gionep!:);
put('!:gi!:,'plus,'giplus!:);
put('!:gi!:,'difference,'gidifference!:);
put('!:gi!:,'times,'gitimes!:);
put('!:gi!:,'quotient,'giquotient!:);
put('!:gi!:,'divide,'gidivide!:);
put('!:gi!:,'gcd,'gigcd!:);
put('!:gi!:,'factorfn,'gifactor!:);
% put('!:gi!:,'rationalizefn,'girationalize!:);
put('!:gi!:,'prepfn,'giprep!:);
put('!:gi!:,'intequivfn,'gintequiv!:);
put('!:gi!:,'specprn,'giprn!:);
put('!:gi!:,'prifn,'giprn!:);
put('!:gi!:,'cmpxfn,'mkgi);

put('!:gi!:,'unitsfn,'!:gi!:unitconv);

symbolic procedure !:gi!:unitconv(u,v);
   unitconv(u,v,get('!:gi!:,'units));

put('!:gi!:,'units,'(((!:gi!: 0 . 1) . (!:gi!: 0 . -1))
             ((!:gi!: 0 . -1) . (!:gi!: 0 . 1))));

symbolic procedure unitconv(u,v,w);
   begin scalar z;
   a: if null w then return u;
      z := quotf1(v,caar w);
      if null z or not fixp z then <<w := cdr w; go to a>>;
      z := multf(denr u,cdar w);
      w := multf(numr u,cdar w);
      if minusf z then <<w := negf w; z := negf z>>;
      return w ./ z
   end;

symbolic procedure !*i2gi u; '!:gi!: . (u . 0);

symbolic procedure giminusp!: u;
   %*** this is rather a test for u being in a canonical form! ***;
   if cadr u = 0 then minusp cddr u else minusp cadr u;

symbolic procedure gizerop!: u;
   cadr u = 0 and cddr u = 0;

symbolic procedure gionep!: u;
   cadr u=1 and cddr u=0;

symbolic procedure gintequiv!: u;
   if cddr u=0 then cadr u else nil;

symbolic procedure mkdgi u;
   ('!:gi!: . (0 . 1)) ./ 1;

symbolic procedure mkgi(re,im);
   '!:gi!: . (re . im);

symbolic procedure giplus!:(u,v);
   mkgi(cadr u+cadr v,cddr u+cddr v);

symbolic procedure gidifference!:(u,v);
   mkgi(cadr u-cadr v,cddr u-cddr v);

symbolic procedure gitimes!:(u,v);
   (lambda r1,i1,r2,i2;
       mkgi(r1*r2-i1*i2,r1*i2+r2*i1))
    (cadr u,cddr u,cadr v,cddr v);

symbolic procedure giquotient!:(u,v);
   begin integer r1,i1,r2,i2,d; scalar rr,ii;
     r1 := cadr u; i1 := cddr u;
     r2 := cadr v; i2 := cddr v;
     d := r2*r2+i2*i2;
     rr := divide(r1*r2+i1*i2,d);
     ii := divide(i1*r2-i2*r1,d);
     return if cdr ii=0 and cdr rr=0 then mkgi(car rr,car ii)
             else '!:gi!: . (0 . 0)
   end;

symbolic procedure gidivide!:(u,v);
   begin integer r1,i1,r2,i2,d,rr,ir,rq,iq;
     r1 := cadr u; i1 := cddr u;
     r2 := cadr v; i2 := cddr v;
     d := r2*r2+i2*i2;
     rq := r1*r2+i1*i2;
     iq := i1*r2-i2*r1;
     rq := car divide(2*rq+if rq<0 then -d else d,2*d);
     iq := car divide(2*iq+if iq<0 then -d else d,2*d);
     rr := r1-(rq*r2-iq*i2);
     ir := i1-(iq*r2+rq*i2);
     return mkgi(rq,iq) . mkgi(rr,ir)
   end;

symbolic procedure giremainder(u,v);
   begin integer r1,i1,r2,i2,d,rr,ir,rq,iq;
     r1 := cadr u; i1 := cddr u;
     r2 := cadr v; i2 := cddr v;
     d := r2*r2+i2*i2;
     rq := r1*r2+i1*i2;
     iq := i1*r2-i2*r1;
     rq := car divide(2*rq+if rq<0 then -d else d,2*d);
     iq := car divide(2*iq+if iq<0 then -d else d,2*d);
     rr := r1-(rq*r2-iq*i2);
     ir := i1-(iq*r2+rq*i2);
     return '!:gi!: . (rr . ir)
   end;

symbolic procedure gigcd!:(u,v);
   % Straightforward Euclidean algorithm.
   if gizerop!: v then fqa u else gigcd!:(v,giremainder(u,v));

symbolic procedure fqa u;
   %calculates the unique first-quadrant associate of u;
   if cddr u=0 then abs cadr u
    else if cadr u=0 then '!:gi!: . (0 . abs cddr u)
    else if (cadr u*cddr u)>0 then
            '!:gi!: . (abs cadr u . abs cddr u)
    else '!:gi!: . (abs cddr u . abs cadr u);

symbolic procedure gifactor!: u;
   % Trager's modified version of Van der Waerdens algorithm.
   begin scalar x,y,norm,aftrs,ftrs,mvu,dmode!*,!*exp,w,z,l,bool;
         integer s;
     !*exp := t;
     if realp u
        then u := cdr factorf u
      else u := list(u . 1);
     w := 1;
     for each f in u do begin
     u := car f;
     dmode!* := '!:gi!:;
     mvu := power!-sort powers u;
     bool := contains!-oddpower mvu;
     if realp u and bool
        then <<u := normalize!-lcgi u;
               w := multd(car u,w);
               aftrs := (cdr u . 1) . aftrs;
               return>>;
     mvu := caar mvu;
     y := u;
     go to b;
     a: l := list(mvu . prepf addf(!*k2f mvu,multd(s,!*k2f 'i)));
        u := numr subf1(y,l);
     b: if realp u
           then if bool
                   then <<y := normalize!-lcgi y;
                          w := multd(car y,w);
                          aftrs := (cdr y . 1) . aftrs;
                          return>>
                 else <<s := s-1; go to a>>;
        norm := multf(u,conjgd u);
        if not sqfrp norm then <<s := s-1; go to a>>;
     dmode!* := nil;
     ftrs := factorf norm;
     dmode!* := '!:gi!:;
     if null cddr ftrs then <<y := normalize!-lcgi y;
                              w := multd(car y,w);
                              aftrs := (cdr y . 1) . aftrs;
                              return>>;
     w := car ftrs;
     l := if s=0 then nil
           else list(mvu . prepf addf(!*k2f mvu,
                                      negf multd(s,!*k2f 'i)));
     for each j in cdr ftrs do
         <<x := gcdf!*(car j,u);
           u := quotf!*(u,x);
           z := if l then numr subf1(x,l) else x;
           z := normalize!-lcgi z;
           w := multd(car z,w);
           aftrs := (cdr z . 1) . aftrs>>;
     w := multf(u,w) end;
     return w . aftrs
   end;

symbolic procedure normalize!-lcgi u;
   % Normalize lnc by using units as canonsq would do it.
   begin scalar l,x,y;
     l := lnc u;
     if numberp l then return if minusp l then (-1) . negf u
                               else 1 . u;
     x := get('!:gi!:,'units);
     a: if null x then return 1 . u;
        y := quotf1(l,caar x);
        if null y or null fixp y then <<x := cdr x; go to a>>;
        u := multd(cdar x,u);
        return if minusf u then negf caar x . negf u
                else caar x . u
   end;

symbolic procedure contains!-oddpower u;
   if null u then nil
    else if evenp cdar u then contains!-oddpower cdr u
    else t;

symbolic procedure power!-sort u;
   begin scalar x,y;
     while u do
       <<x := maxdeg(cdr u,car u);
         u := delall(car x,u);
         y := x . y>>;
     return y
   end;

symbolic procedure sqfrp u;
   % Squarefree test for poly u over the integers. It gives the user
   % control over which gcd to use, i.e. 'on ezgcd' has an effect.
   % Still needs changes to gcd and facform modules before to work.
   begin scalar dmode!*;
     return domainp gcdf!*(u,diff(u,mvar u))
   end;

symbolic procedure realp u;
   if domainp u
     then atom u
        or not get(car u,'cmpxfn)
        or cddr u = cddr apply1(get(car u,'i2d),1)
    else realp lc u and realp red u;

symbolic procedure fd2f u;
   if atom u then u
    else if car u eq '!:gi!:
        then addf(!*n2f cadr u,multf(!*k2f 'i,!*n2f cddr u))
    else addf(multf(!*p2f lpow u,fd2f lc u),fd2f red u);


% symbolic procedure giprep!: u;  %giprep1 cdr u;
%   prepsq!* addsq(!*n2f cadr u ./ 1,
%                  multsq(!*n2f cddr u ./ 1, !*k2q 'i));

% symbolic procedure giprep1 u;  %not used now;
%    if cdr u=0 then car u
%     else if car u=0 then retimes list(cdr u,'i)
%     else begin scalar gn;
%            gn := gcdn(car u,cdr u);
%            return retimes list(gn,
%                       replus list(car u/gn,retimes list(cdr u/gn,'i)))
%          end;

symbolic procedure giprep!: u;
   <<if im=0 then rl else if rl=0 then giprim im
     else if im<0 then list('difference,rl,giprim(minus im))
     else list('plus,rl,giprim im)>>
   where rl=cadr u,im=cddr u;

symbolic procedure giprim im; if im=1 then 'i else list('times,im,'i);

symbolic procedure giprn!: v;
   (lambda u;
    if atom u or (car u eq 'times) then maprin u
     else <<prin2!* "("; maprin u; prin2!* ")" >>) giprep!: v;

% symbolic procedure girationalize!: u;
%    %Rationalizes standard quotient u over the gaussian integers.
%    begin scalar x,y,z;
%       y := denr u;
%       z := conjgd y;
%       if y=z then return u;
%       x := multf(numr u,z);
%       y := multf(y,z);
%       return x ./ y
%    end;

symbolic procedure girationalize!: u;
   % Rationalizes standard quotient u over the gaussian integers.
   begin scalar y,z,!*gcd;
      !*gcd := t;
      if y=(z := conjgd(y := denr u)) then return u;
      % Remove from z any real polynomial factors of y and z.
      z := quotf(z,quotf(
         gcdf(addf(y,z),multf(addf(z,negf y),'!:gi!: . (0 . 1))),2));
      return gigcdsq(multf(numr u,z),multf(y,z))
   end;

symbolic procedure gigcdsq(x,y); % remove integer common factor.
   <<if x then
        (<<if d neq 1 and (d := giintgcd(x,d)) neq 1 then
              <<x := quotf(x,d); y := quotf(y,d)>> >>
         where d=giintgcd(y,0)); x ./ y >>;

symbolic procedure giintgcd(u,d);
   if d=1 then 1 else if null u then d else if atom u then gcdn(u,d)
   else if eqcar(u,'!:gi!:) then gcdn(cadr u,gcdn(cddr u,d))
   else giintgcd(lc u,giintgcd(red u,d));

symbolic procedure conjgd u;
   begin scalar x;
      return if atom u then u
              else if domainp u and (x := get(car u,'cmpxfn))
               then apply2(x,cadr u,!:minus cddr u)
              else if domainp u then u   % Should be a real number now.
              else addf(multpf(lpow u,conjgd lc u),conjgd red u)
   end;

initdmode 'complex;

endmodule;


module cpxrn; % *** Support for Complex Rationals.

% Authors: Anthony C. Hearn and Stanley L. Kameny.

% Copyright (c) 1989 The RAND Corporation.  All rights reserved.

Comment this module defines a complex rational as:

      (<tag>. (<structure> . <structure>>).

The <tag> is '!:crn!: and the <structure> is (n . d) where n and d are
integers;

fluid '(!:prec!:);

global '(bfone!* epsqrt!*);

fluid '(dmode!* !*bfspace !*numval);

switch bfspace,numval; !*bfspace := !*numval := t;

global '(domainlist!*);

domainlist!* := union('(!:crn!:),domainlist!*);

fluid '(!*complex!-rational);

put('complex!-rational,'tag,'!:crn!:);
put('!:crn!:,'dname,'complex!-rational);
flag('(!:crn!:),'field);
put('!:crn!:,'i2d,'i2crn!*);
put('!:crn!:,'plus,'crn!:plus);
put('!:crn!:,'times,'crn!:times);
put('!:crn!:,'difference,'crn!:differ);
put('!:crn!:,'quotient,'crn!:quotient);
put('!:crn!:,'zerop,'crn!:zerop);
put('!:crn!:,'onep,'crn!:onep);
put('!:crn!:,'prepfn,'crn!:prep);
put('!:crn!:,'prifn,'crn!:prin);
put('!:crn!:,'minus,'crn!:minus);
put('!:crn!:,'factorfn,'crn!:factor);
put('!:crn!:,'rationalizefn,'girationalize!:);
put('!:crn!:,'!:rn!:,'!*crn2rn);
put('!:rn!:,'!:crn!:,'!*rn2crn);
put('!:rd!:,'!:crn!:,'!*rd2crn);
put('!:crn!:,'!:rd!:,'!*crn2rd);
put('!:bf!:,'!:crn!:,'!*bf2crn);
put('!:gi!:,'!:crn!:,'!*gi2crn);
put('!:crn!:,'cmpxfn,'mkcrn);
put('!:crn!:,'ivalue,'mkdcrn);
put('!:crn!:,'intequivfn,'crnequiv);
put('!:crn!:,'realtype,'!:rn!:);
put('!:rn!:,'cmpxtype,'!:crn!:);

put('!:crn!:,'minusp,'crn!:minusp);

symbolic procedure crn!:minusp u; caddr u=0 and minusp caadr u;

symbolic procedure mkcrn(u,v); '!:crn!: . u . v;

symbolic smacro procedure crntag x; '!:crn!: . x;

symbolic smacro procedure rntag x; '!:rn!: . x;

symbolic smacro procedure crnrl x; cadr x;

symbolic smacro procedure crnim x; cddr x;

symbolic procedure crn!:simp u; (crntag u) ./ 1;

put('!:crn!:,'simpfn,'crn!:simp);

symbolic procedure mkdcrn u;
   ('!:crn!: . ((0 . 1) . (1 . 1))) ./ 1;

symbolic procedure i2crn!* u; mkcrn(u . 1,0 . 1);
   %converts integer U to tagged crn form.

symbolic procedure !*crn2rn n;
   % Converts a crn number n into a rational if possible.
   if not car crnim n=0 then cr2rderr() else '!:rn!: . crnrl n;

symbolic procedure !*rn2crn u; mkcrn(cdr u,0 . 1);
   % Converts the (tagged) rational u/v into a (tagged) crn.

symbolic procedure !*crn2rd n;
   if not car crnim n=0 then cr2rderr() else
     mkround chkrn!* r2bf crnrl n;

symbolic procedure !*rd2crn u; mkcrn(realrat x,0 . 1) where x=round!* u;

symbolic procedure !*gi2crn u; mkcrn((cadr u) . 1,(cddr u) . 1);

symbolic procedure crn!:plus(u,v);
   mkcrn(cdr rnplus!:(rntag crnrl u,rntag crnrl v),
         cdr rnplus!:(rntag crnim u,rntag crnim v));

symbolic procedure crn!:differ(u,v);
   mkcrn(cdr rndifference!:(rntag crnrl u,rntag crnrl v),
         cdr rndifference!:(rntag crnim u,rntag crnim v));

symbolic procedure crn!:times(u,v);
   mkcrn(cdr rndifference!:(rntimes!:(ru,rv),rntimes!:(iu,iv)),
         cdr rnplus!:(rntimes!:(ru,iv),rntimes!:(rv,iu)))
   where ru=rntag crnrl u,iu=rntag crnim u,
         rv=rntag crnrl v,iv=rntag crnim v;

symbolic procedure crn!:quotient(u,v);
 <<v := rnplus!:(rntimes!:(rv,rv),rntimes!:(iv,iv));
  mkcrn(cdr rnquotient!:(rnplus!:(rntimes!:(ru,rv),rntimes!:(iu,iv)),v),
cdr rnquotient!:(rndifference!:(rntimes!:(iu,rv),rntimes!:(ru,iv)),v))>>
  where ru=rntag crnrl u,iu=rntag crnim u,
        rv=rntag crnrl v,iv=rntag crnim v;

symbolic procedure crn!:minus u;
   mkcrn((-car ru) . cdr ru,(-car iu) . cdr iu)
   where ru=crnrl u,iu=crnim u;

symbolic procedure crn!:zerop u; car crnrl u=0 and car crnim u=0;

symbolic procedure crn!:onep u;  car crnim u=0 and crnrl u='(1 . 1);

symbolic procedure crn!:prep u;
   crnprep1((rntag crnrl u) . rntag crnim u);

symbolic procedure crn!:factor u;
   (begin scalar m,n,p,x,y;
     setdmode('rational,nil) where !*msg = nil;
     x := subf(u,nil);
     y := fctrf numr x;
     n := car y;
     setdmode('rational,t) where !*msg = nil;
     y := for each j in cdr y collect
           <<p := numr subf(car j,nil);
             n := multd(n,m := exptf(lnc ckrn p,cdr j));
             quotfd(p,m) . cdr j>>;
     return int!-equiv!-chk quotfd(n,denr x) . y
   end) where dmode!*=dmode!*;

symbolic procedure crnprimp u;
   if rnonep!: u then 'i
   else if rnonep!: rnminus!: u then list('minus,'i)
   else list('times,rnprep!: u,'i);

symbolic procedure crnprep1 u;
   if rnzerop!: cdr u then rnprep!: car u
   else if rnzerop!: car u then crnprimp cdr u
   else if rnminusp!: cdr u
      then list('difference,rnprep!: car u,crnprimp rnminus!: cdr u)
   else list('plus,rnprep!: car u,crnprimp cdr u);

symbolic procedure crn!:prin u;
   (if atom v or car v eq 'times or car v memq domainlist!*
      then maprin v
    else <<prin2!* "("; maprin v; prin2!* ")">>) where v=crn!:prep u;

symbolic procedure crnequiv u;
   % Returns an equivalent integer if possible.
   if cadr(u := cdr u) = 0 and cdar u = 1 then caar u else nil;

initdmode 'complex!-rational;

endmodule;


module compopr;   % Operators on Complex Expressions.

% Author: Eberhard Schruefer.
% Modifications by:  Francis Wright.

put('repart,'simpfn,'simprepart);

symbolic procedure simprepart u;
   repartsq simp!* car u;

symbolic procedure repartsq u;
   multsq(addsq(multsq(repartnum,repartden),
                multsq(impartnum,impartden)),
          invsq addsq(multsq(repartden,repartden),
                      multsq(impartden,impartden)))
   where repartnum = car reimnum, impartnum = cdr reimnum,
         repartden = car reimden, impartden = cdr reimden
   where reimnum = splitcomplex numr u,
         reimden = splitcomplex denr u;

put('impart,'simpfn,'simpimpart);

symbolic procedure simpimpart u;
   impartsq simp!* car u;

symbolic procedure impartsq u;
   multsq(addsq(multsq(impartnum,repartden),
                negsq multsq(repartnum,impartden)),
          invsq addsq(multsq(repartden,repartden),
                      multsq(impartden,impartden)))
   where repartnum = car reimnum, impartnum = cdr reimnum,
         repartden = car reimden, impartden = cdr reimden
   where reimnum = splitcomplex numr u,
         reimden = splitcomplex denr u;

put('conj,'simpfn,'simpconj);

symbolic procedure simpconj u;
   conjsq simp!* car u;

symbolic procedure conjsq u;
   addsq(repartsq u,negsq multsq(simp 'i,impartsq u));

smacro procedure idomainp; get('i,'idvalfn);
  % Tests if 'i' is transformed to a domain structure.

symbolic procedure splitcomplex u;
   (begin scalar v;
      v := if idomainp() then expand!-imrepart u
            else <<setkorder('i . kord!*);
                   subs2 expand!-imrepart reorder u>>;
      return take!-realpart v . take!-impart v
    end) where kord!* = kord!*;

symbolic procedure expand!-imrepart u;
   if domainp u then u ./ 1
    else addsq(multsq(expand!-imrepartpow lpow u,
                      expand!-imrepart lc u),
               expand!-imrepart red u);

symbolic procedure expand!-imrepartpow u;
   % This needs to treat kernels that are standard forms smarter.
   % At the moment, we expand to get the required result.
   begin scalar !*exp,cmpxsplitfn;
     !*exp := t;
     cmpxsplitfn := null idp car u and
                    get(car car u,'cmpxsplitfn);
     return
       exptsq(if null cmpxsplitfn
                 then if car u eq 'i then !*k2q 'i
                       else addsq(mkrepart car u,
                                  multsq(simp 'i,
                                         mkimpart car u))
               else apply1(cmpxsplitfn,car u),cdr u)
    end;

symbolic procedure mkrepart u;
   if realvaluedp u then !*k2q u
    else if sfp u then repartsq(u ./ 1)
    else mksq(list('repart, u),1);

symbolic procedure mkimpart u;
   if realvaluedp u then nil ./ 1
    else if sfp u then impartsq(u ./ 1)
    else mksq(list('impart, u),1);

symbolic procedure take!-realpart u;
   repartf numr u ./ denr u;

symbolic procedure repartf u;
   if domainp u
      then if atom u then u
            else if get(car u,'cmpxfn)
            % We now know u is of form (<tag> <re> . <im>).
              then int!-equiv!-chk(car u . cadr u .
                        cadr apply1(get(car u,'i2d),0))
        % Otherwise we assume it is real
       else u
    else if mvar u eq 'i then repartf red u
    else if null dmode!* then addf(!*t2f lt u,repartf red u)
    else addf(multpf(lpow u,repartf lc u),repartf red u);

symbolic procedure take!-impart u;
   impartf numr u ./ denr u;

symbolic procedure impartf u;
   if domainp u
     then if atom u then nil
           else if get(car u,'cmpxfn)
            % We now know u is of form (<tag> <re> . <im>).
             then int!-equiv!-chk(car u . cddr u .
                                  cadr apply1(get(car u,'i2d),0))
        % Otherwise we assume it is real
       else nil
    else if mvar u eq 'i then addf(lc u,impartf red u)
    else if null dmode!* then impartf red u
    else addf(multpf(lpow u,impartf lc u),impartf red u);

% The following code attempts to improve the way that the complex
% operators CONJ, REPART and IMPART handle values that are implicitly
% real, namely composed "reality-preserving" functions of explicitly
% real numbers, implicitly real symbolic constants and variables that
% the user has declared using the REALVALUED command defined below.

% All arithmetic operations, direct trig functions and the exponential
% function are "reality-preserving", but inverse trig functions and the
% logarithm are "reality-preserving" only for real arguments in a
% restricted range.  This relates to piecewise-defined functions!  This
% code is believed to make the right decision about implicit reality in
% straightforward cases, and otherwise errs on the side of caution and
% makes no assumption at all, as does the standard REDUCE 3.4 code.  It
% performs only very limited numerical evaluation, which should be very
% fast.  It never performs any approximate numerical evaluation, or any
% sophisticated analysis, both of which would be much slower and/or
% complicated.  The current strategy is believed to represent a
% reasonable compromise, and will normally give the user what they
% expect without undue overhead.

rlistat '(realvalued notrealvalued);   % Make user operators.

symbolic procedure realvalued u;
   % Command to allow the user to declare functions or variables to be
   % implicitly real valued.
   <<rmsubs();  % So that an expression can be re-evaluated.
     for each v in u do
        if not idp v then typerr(v,"id")
         else flag(list v,'realvalued)>>;

symbolic procedure notrealvalued u;
   % Undo realvalued declaration.
   % Cannot recover "complexity", so no need for rmsubs().
   for each v in u do
      if not idp v then typerr(v,"id")
       else remflag(list v, 'realvalued);

flag('(realvaluedp),'boolean); % Make realvaluedp available in
                               % algebraic mode.

symbolic procedure realvaluedp u;
   % True if the true prefix kernel form u is explicitly or implicitly
   % real-valued.
   if atom u then numberp u or flagp(u, 'realvalued)
   else begin scalar caru, cnd;
     return
      flagp((caru := car u), 'alwaysrealvalued)
         % real-valued for all possible argument values
      or (flagp(caru, 'realvalued) and realvaluedlist cdr u)
         % real-valued function if arguments are real-valued,
         % an important common special case of condrealvalued.
%%      or ((cnd := get(caru, 'condrealvalued)) and apply(cnd, cdr u))
         % real-valued function if arguments satisfy conditions
         % that depend on the function
      or caru eq '!:rd!:;  % rounded number - least likely?
   end;

symbolic procedure realvaluedlist u;
   % True if every element of the list u of true prefix kernel forms
   % is real-valued.
   realvaluedp car u and (null cdr u or realvaluedlist cdr u);

% Define the real valued properties
% ---------------------------------

% Only operators that can remain symbolic need be considered,
% e.g. NOT nextprime, num, den, deg, det.

% A very small number of functions are real-valued for ALL arguments:

flag('(repart impart abs ceiling floor fix round factorial max min),
     'alwaysrealvalued);

% Symbolic constants:

flag('(pi e infinity),'realvalued);

% Some functions are real-valued if all their arguments are
% real-valued, without further constraints:

% Arithmetic operators:

flag('(plus minus times quotient), 'realvalued);

% Elementary transcendental functions, etc:

flag('(exp cbrt hypot sin cos tan csc sec cot sind cosd tand cscd secd
       cotd sinh cosh tanh csch sech coth atan atand atan2 atan2d acot
       acotd asinh acsch),
     'realvalued);

% Additional such variables and functions can be declared by the user
% with the REALVALUED command defined above.


put('sin,'cmpxsplitfn,'reimsin);

symbolic procedure reimsin u;
   addsq(multsq(simp list('sin,rearg),
                simp list('cosh,imarg)),
         multsq(simp 'i,
                multsq(simp list('cos,rearg),
                       simp list('sinh,imarg))))
   where rearg = prepsq simprepart cdr u,
         imarg = prepsq simpimpart cdr u;

put('cos,'cmpxsplitfn,'reimcos);

symbolic procedure reimcos u;
   addsq(multsq(simp list('cos,rearg),
                simp list('cosh,imarg)),
         multsq(simp 'i,negsq
                multsq(simp list('sin,rearg),
                       simp list('sinh,imarg))))
   where rearg = prepsq simprepart cdr u,
         imarg = prepsq simpimpart cdr u;

put('expt,'cmpxsplitfn,'reimexpt);

symbolic procedure reimexpt u;
   if cadr u eq 'e
     then addsq(reimcos list('cos,reval list('times,'i,caddr u)),
                multsq(simp list('minus,'i),
                    reimsin list('sin,reval list('times,'i,caddr u))))
    else if fixp cadr u and cadr u > 0
              and eqcar(caddr u,'quotient)
              and fixp cadr caddr u
              and fixp caddr caddr u
     then mksq(u,1)
    else addsq(mkrepart u,multsq(simp 'i,mkimpart u));

endmodule;


module modular; % *** Tables for modular integers ***.

% Author: Anthony C. Hearn.

% Copyright (c) 1987 The RAND Corporation. All rights reserved.

global '(domainlist!*);

fluid '(!*modular current!-modulus alglist!* dmode!*);

switch modular;

domainlist!* := union('(!:mod!:),domainlist!*);

put('modular,'tag,'!:mod!:);
put('!:mod!:,'dname,'modular);
flag('(!:mod!:),'field);
flag('(!:mod!:),'convert);
put('!:mod!:,'i2d,'!*i2mod);
put('!:mod!:,'!:bf!:,'modcnv);
put('!:mod!:,'!:ft!:,'modcnv);
put('!:mod!:,'!:rn!:,'modcnv);
put('!:mod!:,'minusp,'modminusp!:);
put('!:mod!:,'plus,'modplus!:);
put('!:mod!:,'times,'modtimes!:);
put('!:mod!:,'difference,'moddifference!:);
put('!:mod!:,'quotient,'modquotient!:);
put('!:mod!:,'divide,'moddivide!:);
put('!:mod!:,'gcd,'modgcd!:);
put('!:mod!:,'zerop,'modzerop!:);
put('!:mod!:,'onep,'modonep!:);
put('!:mod!:,'factorfn,'factormod!:);
put('!:mod!:,'sqfrfactorfn,'factormod!:);
put('!:mod!:,'expt,'exptmod!:);
put('!:mod!:,'prepfn,'modprep!:);
put('!:mod!:,'prifn,'prin2);

put('!:mod!:,'unitsfn,'!:mod!:unitconv);

symbolic procedure exptmod!:(u,n);
(lambda x; if x=0 then nil else if x=1 then 1 else car u . x)
           general!-modular!-expt(cdr u,n);
% This procedure will check for cdr u > n-1 if n prime.

symbolic procedure !:mod!:unitconv(u,v);
   (if x neq 0 then multd('!:mod!: . x,numr u) ./
                    multd('!:mod!: . x,denr u)
     else u)
    where x = !:mod!:units(current!-modulus,cdr v,0,1);

symbolic procedure !:mod!:units(a,b,x,y);
   % Same procedure as in genmod without error call.
   if b=0 then 0
    else if b=1 then if y < 0 then y+current!-modulus else y
    else begin scalar w;
           w := a/b;
           return !:mod!:units(b,a-b*w,y,x-y*w)
         end;

symbolic procedure !*i2mod u;
   % Converts integer U to modular form.
%  if (u := general!-modular!-number u)=0 then nil else '!:mod!: . u;
   '!:mod!: . general!-modular!-number u;

symbolic procedure modcnv u;
   rerror(poly,13,list("Conversion between modular integers and",
                       get(car u,'dname),"not defined"));

symbolic procedure modminusp!: u; nil;   %what else can one do?;

symbolic procedure !*modular2f u;
%  if u=0 then nil else if u=1 then 1 else '!:mod!: . u;
   '!:mod!: . u;

symbolic procedure modplus!:(u,v);
   !*modular2f general!-modular!-plus(cdr u,cdr v);

symbolic procedure modtimes!:(u,v);
   !*modular2f general!-modular!-times(cdr u,cdr v);

symbolic procedure moddifference!:(u,v);
   !*modular2f general!-modular!-difference(cdr u,cdr v);

symbolic procedure moddivide!:(u,v); !*i2mod 0 . u;

symbolic procedure modgcd!:(u,v); !*i2mod 1;

symbolic procedure modquotient!:(u,v);
   !*modular2f general!-modular!-times(cdr u,
                                   general!-modular!-reciprocal cdr v);

symbolic procedure modzerop!: u; cdr u=0;

symbolic procedure modonep!: u; cdr u=1;

symbolic procedure factormod!: u;
   begin scalar alglist!*,dmode!*;
      % 1 is needed since factorize expects first factor to be a number.
      return pfactor(!*q2f resimp(u ./ 1),current!-modulus)
   end;

symbolic procedure modprep!: u; cdr u;

initdmode 'modular;


% Modular routines are defined in the GENMOD module with the exception
% of the following:

symbolic procedure setmod u;
   % Returns value of CURRENT!-MODULUS on entry unless an error
   % occurs.  It crudely distinguishes between prime moduli, for which
   % division is possible, and others, for which it possibly is not.
   % The code should really distinguish prime powers and composites as
   % well.
   begin scalar dmode!*;
      if not atom u then u := car u;   % Since setmod is a psopfn.
      u := reval u;  % dmode* is NIL, so this won't be reduced wrt
                     % current modulus.
      if fixp u and u>0
        then <<if primep u then flag('(!:mod!:),'field)
                else remflag('(!:mod!:),'field);
               return set!-general!-modulus u>>
      else if u=0 or null u then return current!-modulus
       else typerr(u,"modulus")
   end;

put('setmod, 'psopfn, 'setmod);

%A more general definition of general-modular-number.

%symbolic procedure general!-modular!-number m;
   %returns normalized M;
%   (lambda n; %if n<0 then n+current!-modulus else n)
%   if atom m then remainder(m,current!-modulus)
%    else begin scalar x;
%       x := dcombine(m,current!-modulus,'divide);
%        return cdr x
%     end;

endmodule;


module facform;  % Factored form representation for standard form polys.

% Author: Anthony C. Hearn.

% Copyright (c) 1990 The RAND Corporation. All rights reserved.

% INTEGER FACTORS?

% SHOULDN'T SYMMETRIC TESTS ETC BE RUN RECURSIVELY?

fluid '(!*exp !*ezgcd !*factor !*force!-prime !*gcd !*ifactor
        !*kernreverse !*limitedfactors !*sqfree !*trfac current!-modulus
        dmode!* m!-image!-variable);

switch limitedfactors;

switch sqfree;

put('sqfree,'simpfg,'((t (rmsubs) (setq !*exp nil))
                      (nil (rmsubs) (setq !*exp t))));

Comment In this module, we consider the manipulation of factored forms.
    These have the structure

       <monomial> . <form-power-list>

        where the monomial is a standard form (with numerator and
        denominator satisfying the KERNLP test) and a form-power is a
        dotted pair whose car is a standard form and cdr an integer>0.
        We have thus represented the form as a product of a monomial
        quotient and powers of non-monomial factors;

symbolic procedure fac!-merge(u,v);
   % Returns the merge of the factored forms U and V.
   multf(car u,car v) . append(cdr u,cdr v);

symbolic procedure factorize u;
   % Factorize the polynomial u, returning the factors found.
   (begin scalar x,y;
      x := simp!* u;
      y := denr x;
      if not domainp y then typerr(u,"polynomial");
      u := numr x;
      if u = 1 then return list('list,1)
       else if fixp u then !*ifactor := t;   % Factor an integer.
      if !*force!-prime and not primep !*force!-prime
        then typerr(!*force!-prime,"prime");
      u := if dmode!*
         then if get(dmode!*,'factorfn)
                 then begin scalar !*factor;
                        !*factor := t;
                         return fctrf u
                      end
           else rerror(poly,14,
                       list("Factorization not supported over domain",
                       get(dmode!*,'dname)))
       else fctrf u;
      return facform2list(u,y)
   end) where !*ifactor = !*ifactor;

symbolic procedure facform2list(x,y);
   begin scalar factor!-count,w,z;
      % Note that car x is expected to be a number.
      z:= (0 . car x) . nil;
      x := reversip!* cdr x;  % This puts factors in better order.
      factor!-count:=0;
      for each fff in x do
      for i:=1:cdr fff do
          z := ((factor!-count:=factor!-count+1) .
                    mk!*sq(car fff ./ 1)) . z;
      z := multiple!-result(z,w);
      if atom z then typerr(z,"factor form")  % old style input
       else if numberp cadr z and cadr z<0 and cddr z
        then z := car z .
                      (- cadr z) . mk!*sq negsq simp caddr z . cdddr z;
      % make numerical coefficient positive.
      z := cdr z;
      if car z = 1 then z := cdr z
       else if not fixp car z then z := prepd car z . cdr z
       else if !*ifactor
        then z := append(pairlist2list reversip zfactor car z,cdr z);
      if y neq 1 then z := list('recip,prepd y) . z;
      return 'list . z
  end;

flag('(factorize),'opfn);

symbolic procedure pairlist2list u;
   for each x in u conc nlist(car x,cdr x);

symbolic procedure fctrf u;
   % U is a standard form. Value is a factored form.
   % The function FACTORF is an assumed entry point to a more complete
   % factorization module.  It returns a form power list.
   (begin scalar !*ezgcd,!*gcd,x,y;
      if domainp u then return list u;
      !*gcd := t;
      if null !*limitedfactors and null dmode!* then !*ezgcd := t;
      if null !*mcd
        then rerror(poly,15,"Factorization invalid with MCD off")
       else if null !*exp
        then <<!*exp := t; u := !*q2f resimp !*f2q u>>;
      % Check for homogeneous polynomials.
      x := sf2ss u;
      if homogp x
        then <<if !*trfac
                 then prin2t
                    "This polynomial is homogeneous - variables scaled";
               y := caaar x . listsum caaadr x;
               x := fctrf1 ss2sf(car(x) . (reverse subs0 cadr x . 1));
               return rconst(y,x)>>;
      return fctrf1 u
   end) where !*exp := !*exp;

symbolic procedure fctrf1 u;
   begin scalar x,y;
      if domainp u then return list u;  % Do this again just in case.
      x := comfac u;
      u := quotf(u,comfac!-to!-poly x);
      y := fctrf1 cdr x;   % factor the content.
      if car x then y := car y . (!*k2f caar x . cdar x) . cdr y;
           % Selectors on powers should have been used here.
      if domainp u then return multf(u,car y) . cdr y
       else if minusf u
        then <<u := negf u; y := negf car y . cdr y>>;
      return fac!-merge(factor!-prim!-f u,y)
   end;

symbolic procedure factorize!-form!-recursion u;
   fctrf1 u;

symbolic procedure factor!-prim!-f u;
   % U is a non-trivial form which is primitive in all its variables
   % and has a positive leading numerical coefficient. Result is a
   % form power list.
   begin scalar v,w,x;
      if dmode!* and (x := get(dmode!*,'sqfrfactorfn))
        then if !*factor then v := apply1(x,u) else v := list(1,u . 1)
       else if flagp(dmode!*,'field) and ((w := lnc u) neq 1)
        then v := w . sqfrf multd(!:recip w,u)
       else v := 1 . sqfrf u;
      if x and (x eq get(dmode!*,'factorfn))
        then return v;   % No point in re-factorizing.
      w := list car v;
      for each x in cdr v
         do w := fac!-merge(factor!-prim!-sqfree!-f x,w);
      return w
   end;

symbolic procedure factor!-prim!-sqfree!-f u;
   % U is of the form <square free poly> . <power>. Result is a factored
   % form.
   % Modified to work properly in rounded (real or complex) modes. SLK.
   begin scalar x,y,!*msg,r;
      if (r := !*rounded) then
         <<on rational; u := numr resimp !*f2q car u . cdr u>>;
      if null !*limitedfactors
        then <<if null dmode!* then y := 'factorf
                else <<x := get(dmode!*,'sqfrfactorfn);
                       y := get(dmode!*,'factorfn);
                       if x and not(x eq y) then y := 'factorf>>;
               if y
                 then <<y := apply1(y,car u);
                        u := (car y . for each j in cdr y
                                           collect(car j . cdr u));
                        go to ret>>>>;
      u := factor!-prim!-sqfree!-f!-1(car u,cdr u);
 ret: if r then
      <<on rounded;
        u := car u . for each j in cdr u collect
           (numr resimp !*f2q car j . cdr j)>>;
      return u
   end;

symbolic procedure distribute!.multiplicity(factorlist,n);
   % Factorlist is a simple list of factors of a square free primitive
   % multivariate poly and n is their multiplicity in a square free
   % decomposition of another polynomial. result is a list of form:
   %  ((f1 . n),(f2 . n),...) where fi are the factors.
   for each w in factorlist collect (w . n);

symbolic procedure factorf u;
   % NOTE: This is not an entry point to be used by novice programmers.
   % Please used FCTRF instead.
   % There is an inefficiency in this procedure relating to ordering.
   % There is a final reordering done at every recursive level in order
   % to make sure final result has the right order.  However, this only
   % need be done once at the top level, probably in fctrf.  Since some
   % programmers still use this function however, it's safer for it to
   % return results in the correct order.
  (begin scalar m!-image!-variable,new!-korder,old!-korder,sign,v;
      if domainp u then return list u;
      new!-korder:=kernord(u,nil);
      if !*kernreverse then new!-korder:=reverse new!-korder;
      old!-korder:=setkorder new!-korder;
      u := reorder u; % Make var of lowest degree the main one.
      if minusf u then <<sign := not sign; u := negf u>>;
      v := comfac u;   % Since new order may reveal more factors.
      u := quotf1(u,cdr v);
      if domainp u or car v
        then errach list("Improper factors in factorf");
      v := fctrf1 cdr v;
      m!-image!-variable := mvar u;
      u :=
        distribute!.multiplicity(factorize!-primitive!-polynomial u,1);
      setkorder old!-korder;
      if sign then u := (negf caar u . cdar u) . cdr u;
      u := fac!-merge(v,1 . u);
      return car u . for each w in cdr u collect (reorder car w . cdr w)
   end) where current!-modulus = current!-modulus;

symbolic procedure factor!-prim!-sqfree!-f!-1(u,n);
   (exptf(car x,n) . for each j in cdr x collect (j . n))
      where x = prsqfrfacf u;

symbolic procedure sqfrf u;
   % U is a non-trivial form which is primitive in all its variables
   % and has a positive leading numerical coefficient which should be 1.
   % SQFRF performs square free factorization on U and returns a
   % form power list.
   % Modified to work properly in rounded (real or complex) modes. SLK.
   begin integer n; scalar !*gcd,v,w,x,y,z,!*msg,r;
      !*gcd := t;
      if (r := !*rounded) then
         <<on rational; u := numr resimp !*f2q u>>;
      n := 1;
      x := mvar u;
      v := gcdf(u,diff(u,x));
      u := quotf(u,v);
      % If domain is a field, v can have a spurious numerical factor.
      if flagp(dmode!*,'field) and ((y := lnc u) neq 1)
        then <<u := multd(!:recip y,u); v := multd(y,v)>>;
      while degr(v,x)>0 do
       <<w := gcdf(v,u);
         if u neq w then z := (quotf(u,w) . n) . z;
              % Don't add units to z.
         v := quotf(v,w);
         u := w;
         n := n + 1>>;
         if r then
            <<on rounded;
              u := numr resimp !*f2q u;  z := numr resimp !*f2q z>>;
      return (u . n) . z
   end;

symbolic procedure diff(u,v);
   % A polynomial differentation routine which does not check
   % indeterminate dependencies.
   if domainp u then nil
    else addf(addf(multpf(lpow u,diff(lc u,v)),
        multf(lc u,diffp1(lpow u,v))),
          diff(red u,v));

symbolic procedure diffp1(u,v);
   if not car u eq v then nil
    else if cdr u=1 then 1
    else multd(cdr u,!*p2f(car u .** (cdr u-1)));

endmodule;


module homog; % Procedures for factorization of homogeneous polynomials.

% Authors: Shuichi Moritsugu <y31046@tansei.cc.u-tokyo.ac.jp>
%          and Eiichi Goto.

symbolic procedure homogp s;
   % Confirmation of homogeneous polynomials.
      if domainp s or domainp car s then nil
        else if null cdadr s then nil
        else if domainp cdr lastnondomain cadr s then nil
        else if listsum caaadr s=listsum caar lastnondomain cadr s
         then t
        else nil;

symbolic procedure subs0 nm;
   %Substitution of 0 into exponent list.
      if null nm then nil
        else ((0 . cdaar nm) . cdar nm) . subs0 cdr nm;

symbolic procedure varss(v,d);
   % Ss of single variable.
      ((v . nil) . 1) . ((((d . nil) . 1) . nil) . 1);

symbolic procedure rconstnm(nm,nv,td);
   % Reconstruction of numerator.
      if null nm then nil
        else if domainp nm then ((td . mkzl(nv+1)) . nm) . nil
        else (((td-listsum caar nm) . caar nm) . cdar nm)
             . rconstnm(cdr nm,nv,td);

symbolic procedure rconst1(s,v,td);
   % Reconstruction of one factor.
      if homogp s then s
        else ((v . caar s) . (cdar s+1))
             . (reverse rconstnm(cadr s,cdar s,td) . cddr s);

symbolic procedure rconst(p,fctrlis);
   % Reconstruction of factors.
   begin scalar v,d,td,fs,fcf,ffl,x;
      v := car p; d := cdr p; fcf := car fctrlis;
      for i:=2:length fctrlis do
          <<x := nth(fctrlis,i);
            fs := sf2ss car x; td := listsum caaadr fs;
            fs := rconst1(fs,v,td);
            d := d-cdr x*td;
            ffl := aconc(ffl,ss2sf fs . cdr x)>>;
      ffl := fcf . ffl;
      if d>0 then ffl := aconc(ffl,ss2sf varss(v,1) . d);
      return ffl;
   end;

endmodule;


module tdconv; % Procedures for conversion of internal & external
               % expressions defined with total degree ordering.

% Authors: Shuichi Moritsugu <y31046@tansei.cc.u-tokyo.ac.jp>
%          and Eiichi Goto.

symbolic procedure setunion(l1,l2);
   % Union of two sets.
      if null l2 then l1
        else if member(car l2,l1) then setunion(l1,cdr l2)
        else setunion(append(l1,car l2 . nil),cdr l2);

symbolic procedure searchtm term;
   % Search for variables in a term.
      if domainp term then nil
        else caar term . searchpl cdr term;

symbolic procedure searchpl poly;
   % Search for variables in a polynomial.
      if domainp poly then nil
        else setunion(searchtm car poly,searchpl cdr poly);

symbolic procedure qsort l;
   % Quick sort of variables with lexicographic ordering.
      begin scalar a,l1,l2,ll;
            if null l then return nil;
            a:=car l; ll:=cdr l;
            loop : if null ll then go to exit;
   % We need ORDOP rather than ORDERP in next line to be consistent
   % with the way that REDUCE orders expressions.
                   if ordop(a,car ll) then l2:=car ll . l2
                                       else l1:=car ll . l1;
                   ll:=cdr ll; go to loop;
            exit : return append(qsort l1,a . qsort l2);
      end;

symbolic procedure mapins(ep,cfl);
   % Insert of exponent into coefficient list.
      if null cfl then nil
        else ((ep . caar cfl) . cdar cfl) . mapins(ep,cdr cfl);

symbolic procedure mkzl n;
   % Making of zero-list (length = n-1).
      if n=1 then nil else 0 . mkzl(n-1);

symbolic procedure sq2sstm(sqtm,vd);
   % Transformation of term from sq to ss.
      begin scalar ep,cf,cfl;
            if caar sqtm=caar vd
              then <<cf:=cdr sqtm; ep:=cdar sqtm;
                     if domainp cf
                       then return ((ep . mkzl cdr vd) . cf) . nil
                       else cfl:=sq2sscfpl(cf,cdar vd . sub1 cdr vd)>>
              else <<cfl:=sq2sscfpl(sqtm . nil,cdar vd . sub1 cdr vd);
                     ep:=0>>;
            return mapins(ep,cfl);
      end;

symbolic procedure sq2sscfpl(cfpl,vd);
   % Transformation of coefficient polynomial from sq to ss.
      if null cfpl then nil
        else if domainp cfpl then (mkzl(cdr vd+1) . cfpl) . nil
        else append(sq2sstm(car cfpl,vd),sq2sscfpl(cdr cfpl,vd));

symbolic procedure sq2sspl(sqpl,vd);
   % Transformation of polynomial from sq to ss.
      if domainp sqpl then sqpl
        else append(sq2sstm(car sqpl,vd),sq2sspl(cdr sqpl,vd));

symbolic procedure sdlist nm;
   % Classification of ss by the degree of main variable.
      begin scalar anslist,partlist,n,rnm;
            rnm:=nm;
            init : n:=caaar rnm; partlist:= car rnm . nil;
            loop : rnm:=cdr rnm;
                   if null rnm
                     then <<anslist:=append(anslist,partlist . nil);
                            go to exit>>;
                   if domainp rnm
                     then <<anslist:=append(append(anslist,
                                                   partlist . nil),
                                            rnm);
                            go to exit>>;
                   if n=caaar rnm
                     then <<partlist:=append(partlist,car rnm . nil);
                            go to loop>>
                     else <<anslist:=append(anslist,partlist . nil);
                            go to init>>;
            exit : return anslist;
      end;

symbolic procedure univsdl2sq(var,sdl);
   % Transformation from univariate ss to sq.
      if domainp sdl then sdl
        else if zerop caaaar sdl then cdaar sdl
        else ((var . caaaar sdl) . cdaar sdl) . univsdl2sq(var,cdr sdl);

symbolic procedure mapdel sdl;
   % Deletion of the exponent of main variable from ss.
      if null sdl then nil
        else (cdaar sdl . cdar sdl) . mapdel cdr sdl;

symbolic procedure mulvsdl2sq(vd,sdl);
   % Transformation from multivariate ss to sq.
      if domainp sdl then sdl
        else if zerop caaaar sdl
               then if domainp cdr sdl and cdr sdl
                      then append(sdl2sq(cdar vd . sub1 cdr vd,
                                         sdlist mapdel car sdl),
                                  cdr sdl)
                      else sdl2sq(cdar vd . sub1 cdr vd,
                                  sdlist mapdel car sdl)
               else ((caar vd . caaaar sdl)
                      . sdl2sq(cdar vd . sub1 cdr vd,
                               sdlist mapdel car sdl))
                    . mulvsdl2sq(vd,cdr sdl);

symbolic procedure sdl2sq(vd,sdl);
   % Transformation from classified ss to sq.
      if cdr vd=1 then univsdl2sq(caar vd,sdl)
                   else mulvsdl2sq(vd,sdl);

symbolic procedure termorder1(term1,term2);
   % Comparison of ordering between two terms (purely lexicographic
   % ordering).
      if null term1 then 0
        else if zerop term1 and zerop term2 then 0
        else if zerop term1 then -1
        else if zerop term2 then 1
        else if car term1<car term2 then -1
        else if car term1>car term2 then 1
        else termorder1(cdr term1,cdr term2);

symbolic procedure listsum l;
   % Total degree.
      if null l then 0 else car l+listsum cdr l;

symbolic procedure termorder(term1,term2);
   % Comparison of ordering between two terms (total degree and
   % lexicographic ordering).
      begin scalar s1,s2;
            if null term1 then 0
              else if zerop term1 and zerop term2 then 0
              else if zerop term1 then -1
              else if zerop term2 then 1;
              s1:=listsum term1; s2:=listsum term2;
              return if s1=s2 then termorder1(term1,term2)
                       else if s1<s2 then -1 else 1;
      end;

symbolic procedure xxsort l;
   %Sort of terms with present ordering.
      begin scalar a,l1,l2,ll;
            if null l then return nil;
            a:=car l; ll:=cdr l;
            loop : if null ll then go to exit;
                   if termorder(car a,caar ll)<0
                     then l1:=car ll . l1
                     else l2:=car ll . l2;
                   ll:=cdr ll; go to loop;
            exit : return append(xxsort l1,a . xxsort l2);
      end;

symbolic procedure lxsort l;
   % Sort of terms with purely lexicographic ordering.
      begin scalar a,l1,l2,ll;
            if null l then return nil;
            a:=car l; ll:=cdr l;
            loop : if null ll then go to exit;
                   if termorder1(car a,caar ll)<0
                     then l1:=car ll . l1
                     else l2:=car ll . l2;
                   ll:=cdr ll; go to loop;
            exit : return append(lxsort l1,a . lxsort l2);
      end;

symbolic procedure delet(a,l);
   %Deletion from list.
      if null a then l
        else if null l or a=l then nil
        else if a=car l then cdr l
        else car l . delet(a,cdr l);

symbolic procedure lx2xx ss;
   % Transformation from lex. to another normal ordering.
      begin scalar nm,ct;
            if domainp ss or domainp car ss then return ss;
            nm:=cadr ss; ct:=cdr lastnondomain nm;
            return car ss . (append(xxsort delet(ct,nm),ct) . cddr ss);
      end;

symbolic procedure lastnondomain u;
   % Return the last non-domain pair of the list u.
   if domainp u then errach list("non-domain",u)
    else if domainp cdr u then u
    else lastnondomain cdr u;

symbolic procedure xx2lx ss;
   % Transformation from normal ordering to lex.
      begin scalar nm,ct;
            if domainp ss or domainp car ss then return ss;
            nm:=cadr ss; ct:=cdr lastnondomain nm;
            return car ss . (append(lxsort delet(ct,nm),ct) . cddr ss);
      end;

symbolic procedure sf2ss f;
   % Transformation from sf to ss (with denominator 1).
      begin scalar vl,vd;
            if domainp f then return f;
            vl:=searchpl f; vd:=qsort vl . length vl;
            return lx2xx(vd . (sq2sspl(f,vd) . 1));
      end;

symbolic procedure ss2sf s;
   % Transformation from ss to sf (neglecting the denominator).
      if domainp s then s
        else sdl2sq(car s , sdlist cadr xx2lx s );

endmodule;


module primfac;   % Primitive square free polynomial factorization.

% Author: Anthony C. Hearn.

% Copyright (c) 1987 The RAND Corporation. All rights reserved.

fluid '(!*intfac !*surds dmode!* kernlist!* knowndiscrimsign); %clogflag

symbolic procedure prsqfrfacf u;
   % U is a non-trivial form which is primitive in all its variables,
   % is square free, and has a positive leading numerical coefficient.
   % Result is a list of factors of u, the first a monomial.
   % We order kernels in increasing powers unless kernlist!* has a
   % non-NIL value in which case we use that order (needed by SOLVE).
   % NOTE: For the time being, we bypass this code if the coefficient
   % domain is other than integer.
   begin scalar bool,knowndiscrimsign,v,w;
      if dmode!* then return list(1,u);
      v := if kernlist!* then kernlist!*
            else reverse kernord!-sort powers u;
      % order highest power first.
      w := setkorder v;
      u := reorder u;
      if minusf u then <<bool := t; u := negf u>>;
      u := factor!-ordered!-sqfree!-prim!-f u;
      setkorder w;
%     w := resimp car u;
      u := for each x in u collect
              begin
                 v := reorder x;
                 if bool and minusf v
                   then <<v := negf v; bool := nil>>;
                 return v
              end;
      if bool then u := negf car u . cdr u;
      % We couldn't fold the minus sign.
      return u
   end;

symbolic procedure factor!-ordered!-sqfree!-prim!-f pol;
   % U is a non-trivial form which is primitive in all its variables,
   % is square free, has a positive leading numerical coefficient,
   % and has a main variable of lowest degree in the form.
   % Result is a list of factors of u, the first a monomial.
   begin integer n; scalar q,res,w;
      if ldeg pol = 1 then return factor!-coeffs pol
       else if univariatep pol
        then <<while car(q := linfacf pol) do
                <<res := car q . res; pol := cdr q>>;
               while car(q := quadfacf pol) do
                <<res := car q . res; pol := cdr q>>>>;
      if null pol then return 1 . res
       else if length(w := special!-case!-factor pol)>2
        then <<res := car w . res;   % constant.
               for each j in cdr w
                  do res:=fac!-merge(factor!-ordered!-sqfree!-prim!-f j,
                                     res);
               return res>>
       else if ldeg pol < 4 or (n := degreegcd pol) = 1
          then return 1 . pol . res;
      w := cdr sort(dfactors n,function lessp);
      % 1 is always first factor.
      knowndiscrimsign := 'negative;
   a: if null w then <<knowndiscrimsign := nil;
                       return 1 . pol . res>>
       else if length (q := factor!-ordered!-sqfree!-prim!-f
                               downpower(pol,car w))>2
        then <<res := car q . res;
               for each j in cdr q
                  do res := fac!-merge(factor!-ordered!-sqfree!-prim!-f
                                        uppower(j,mvar pol,car w),
                                     res);
               knowndiscrimsign := nil;
               return res>>;
      w := cdr w;
      go to a
   end;

symbolic procedure downpower(pol,n);
    % Reduce the power of each term in pol wrt main variable by factor
    % n.
   downpower1(pol,mvar pol,n);

symbolic procedure downpower1(pol,mv,n);
   if domainp pol or not(mvar pol eq mv) then pol
    else (mv .** (ldeg pol/n)) .* lc pol .+ downpower1(red pol,mv,n);

symbolic procedure uppower(pol,var,n);
    % Raise the power of each term in pol wrt var by factor n.
   if mvar pol = var then uppower1(pol,var,n) else uppower2(pol,var,n);

symbolic procedure uppower1(pol,mv,n);
   if domainp pol or not(mvar pol eq mv) then pol
    else (mv .** (ldeg pol*n)) .* lc pol .+ uppower1(red pol,mv,n);

symbolic procedure uppower2(pol,var,n);
   if domainp pol then pol
    else if mvar pol = var
     then (mvar pol .** (ldeg pol*n)) .* lc pol
                .+ uppower2(red pol,var,n)
    else lpow pol .* uppower2(lc pol,var,n) .+ uppower2(red pol,var,n);

symbolic procedure univariatep pol;
   % True if pol is not a domain element and is univariate with respect 
   % to its main variable.
   not domainp pol and univariatep1(pol,mvar pol);

symbolic procedure univariatep1(pol,mv);
   domainp pol
      or mvar pol eq mv and domainp lc pol and univariatep1(red pol,mv);

symbolic procedure special!-case!-factor pol;
   % When integrator calls this, it doesn't want to use the quadratic
   % code.
%  (if degree = 2 and (null !*surds or clogflag) then quadraticf pol
   (if degree = 2 and null !*intfac then quadraticf pol
     else if degree= 3 then cubicf pol
       else if degree = 4 then quarticf pol
       else list(1,pol))
    where degree = ldeg pol;

symbolic procedure degreegcd pol;
   % Returns gcd of degrees of pol with respect to main variable.
   begin integer n; scalar mv;
      mv := mvar pol;
      n := ldeg pol;
      while n>1 and not domainp(pol := red pol) and mvar pol eq mv
         do n := gcdn(n,ldeg pol);
      return n
   end;

symbolic procedure factor!-coeffs u;
   % factor the primitive, square free polynomial U wrt main variable.
   % dummy for now.
   list(1,u);

endmodule;


module specfac;   % Splitting of low degree polynomials.

% Author: Anthony C. Hearn.

% Copyright (c) 1991 RAND. All rights reserved.

fluid '(!*keepsqrts !*sub2 !*surds knowndiscrimsign kord!* zlist);

switch surds;

exports cubicf,quadraticf,quarticf;

symbolic procedure coeffs pol;
% Extract coefficients of polynomial wrt its main variable and leading
% degree. Result is a list of coefficients.
    begin integer degree,deg1; scalar cofs,mv;
      mv := mvar pol;
      degree := ldeg pol;
      while not domainp pol and mvar pol eq mv do
       <<deg1 := ldeg pol;
         for i:= 1:(degree-deg1-1) do cofs := nil . cofs;
         cofs := lc pol . cofs;
         pol := red pol;
         degree := deg1>>;
      for i:=1:degree-1 do cofs := nil . cofs;
      return reversip(pol . cofs)
   end;

symbolic procedure shift!-pol pol;
% Shifts main variable, mv, of square free nth degree polynomial pol so 
% that coefficient of mv**(n-1) is zero.
% Does not assume pol is univariate.
   begin scalar lc1,ld,mv,pol1,redp,shift,x;
      mv := mvar pol;
      ld := ldeg pol;
      redp := red pol;
      if domainp redp or not(mvar redp eq mv) or ldeg redp<(ld-1)
        then return list(pol,1,nil ./ 1);
      lc1 := lc pol;
      x := lc redp;
      shift := quotsq(!*f2q x,!*f2q multd(ld,lc1));
      pol1 := subf1(pol,list(mv . mk!*sq addsq(!*k2q mv,negsq shift)));
      return list(numr pol1,denr pol1,shift)
   end;

symbolic procedure quadraticf!*(pol,var);
   if domainp pol then errach "invalid quadratic to factr"
    else if mvar pol = var then quadraticf pol
    else begin scalar kord,w;
        kord := kord!*;
        kord!* := list var;
        w := coeffs !*q2f resimp(pol ./ 1);
        kord!* := kord;
        w := quadraticf1(car w,cadr w,caddr w);
        if w eq 'failed then return list(1,pol);
        var := !*k2f var;
        return list(if car w neq 1 then mkrn(1,car w) else 1,
                    addf(multf(var,cadr w),caddr w),
                         addf(multf(var,cadddr w),car cddddr w))
     end;

symbolic procedure quadraticf pol;
   % Finds factors of square free quadratic polynomial pol (if they
   % exist).  Does not assume pol is univariate.
   (if x eq 'failed then list(1,pol)
    else if not domainp car x then list(1,pol)
            % Answer would be rational.
    else list(if car x neq 1 then mkrn(1,car x) else 1,
              y .* cadr x .+ caddr x,y .* cadddr x .+ car cddddr x)
       where y = (mvar pol .** 1))
    where x = quadraticf1(car w,cadr w,caddr w) where w = coeffs pol;

symbolic procedure quadraticf1(a,b,c);
   begin scalar a1,denom,discrim,w;
      if null b and minusf c and not minusf a
       then <<a := rootxf(a,2);
              c := rootxf(negf c,2);
              return if a eq 'failed or c eq 'failed then 'failed
                      else list(1,a,c,a,negf c)>>;
      discrim := powsubsf addf(exptf(b,2),multd(-4,multf(a,c)));
      if null discrim then errach "discrim=0 in quadratic"
       else if knowndiscrimsign
        then <<if knowndiscrimsign eq 'negative then return 'failed>>
%      else if not clogflag and minusf discrim then return 'failed;
       else if minusf discrim then return 'failed;
      discrim:=rootxf(discrim,2);
      if discrim='failed then return discrim;
      denom := multd(4,a);
      a := a1 := multd(2,a);
      w := addf(b,discrim);
      c := addf(b,negf discrim);
      b := w;
      if (w := gcdf(a,b)) neq 1
        then <<a1 := quotf(a,w); b := quotf(b,w);
               denom := quotf(denom,w)>>;
      if (w := gcdf(a,denom)) neq 1 and (w := gcdf(c,denom))
        then <<a := quotf(a,w);
               c := quotf(c,w);
               denom := quotf(denom,w)>>;
      return list(denom,a1,b,a,c)
    end;

symbolic procedure rootxf(u,n);
   % Return either polynomial nth root of u or "failed".
   begin scalar x,y,z;
      if domainp u
        then return if minusf u then 'failed
                     else if fixp u and (y := irootn(u,n))**n=u then y
                     else if !*surds and not(u member zlist)
                      then nrootn!*(u,n)
                     else 'failed;
      x := comfac u;
      u := quotf(u,comfac!-to!-poly x);
      z := 1;
      if car x then if cdr(y := divide(cdar x,n)) = 0
        then z := multpf(caar x .** car y,z)
       else if !*surds
        then <<z := multf(mkrootf(caar x,n,cdr y),z);
               if car y neq 0 then z := multpf(caar x .** car y,z)>>
       else return 'failed;
      x := cdr x;
      if domainp x
        then if minusf x then return 'failed
       else if fixp x and (y := irootn(x,n))**n=x
               then z := multd(y,z)
              else if !*surds and fixp x
               then z := multf(nrootn!*(x,n),z)
              else return 'failed
       else if (y := rootxf(x,n)) eq 'failed then return y
       else z := multf(y,z);
      if u=1 then return z;
      x := sqfrf u;
   c: if null x then return z
       else if cdr(y := divide(cdar x,n)) = 0
        then <<z := multf(exptf(caar x,car y),z); x := cdr x>>
       else if !*surds
        then <<z := multf(mkrootf(prepf caar x,n,cdar x),z);
               x := cdr x>>
       else return 'failed;
      go to c
   end;

symbolic procedure mkrootf(u,m,n);
   if m neq 2 or null !*keepsqrts
     then !*p2f mksp(list('expt,u,list('quotient,1,m)),n)
    else if n neq 1 then errach 'mkrootf
    else !*q2f simpsqrt list u;

symbolic procedure nrootn!*(u,n);
   % Returns a standard form representation of the nth root of u.
   begin scalar x;
      if null u then return nil;
      u := nrootn(u,n);
      x := cdr u;         % surd part.
      u := car u;         % rational part.
      if x=1 then return x;
      x := mkrootf(prepf x,n,1);
      return powsubsf multf(u,x)
   end;

symbolic procedure cubicf pol;
   % Split the cubic pol if a change of origin puts it in the form
   % (x-a)**3-b=0.
   begin scalar a,a0,a1,b,neg,p;
      p := shift!-pol pol;
      a := coeffs car p;
      if cadr a then return list(1,pol)
      % Cadr a non nil probably means there are some surds in the
      % coefficients that don't reduce to 0.
       else if caddr a then return list(1,pol);
      % Factorization not possible by this method.
      a0 := cadddr a;
      a := car a;
      if minusf a0 then <<neg := t; a0 := negf a0>>;
      if (a := rootxf(a,3)) eq 'failed
         or (a0 := rootxf(a0,3)) eq 'failed
        then return list(1,pol);
      if neg then a0 := negf a0;
      a := !*f2q a;
      a0 := !*f2q a0;
      p := addsq(!*k2q mvar pol,caddr p);
      % Now numr (a*(mv+shift)+a0) is a factor of pol.
      a1 := numr addsq(multsq(a,p),a0);
      % quotf(pol,a) is quadratic factor. However, the surd division may
      % not work properly, so we calculate factor directly.
      b := multsq(a0,a0);
      b := addsq(b,multsq(negsq multsq(a,a0),p));
      b := numr addsq(b,multsq(multsq(a,a),exptsq(p,2)));
      return aconc!*(quadraticf b,a1)
   end;

symbolic procedure powsubsf u;
   % We believe that the result of this operation must be a polynomial.
   % If subs2q returns a rational, it must be because there are
   % unsimplified surds.  Hopefully rationalizesq can fix those.
   begin scalar !*sub2;
      u := subs2q !*f2q u;
      if denr u neq 1
        then <<u := rationalizesq u;
               if denr u neq 1 then errach list('powsubsf,u)>>;
      return numr u
   end;

symbolic procedure quarticf pol;
  % Splits quartics that can be written in the form
  % (x-a)**4+b*(x-a)**2+c.
   begin scalar !*sub2,a,a2,a0,b,dsc,p,p1,p2,q,shift,var;
      var := mvar pol;
      p := shift!-pol pol;
      a := coeffs car p;
      shift := caddr p;
      if cadr a then rerror(poly,16,list(pol,"not correctly shifted"))
        else if cadddr a then return list(1,pol);
       % Factorization not possible by this method.
      a2 := cddr a;
      a0 := caddr a2;
      a2 := car a2;
      a := car a;
      q := quadraticf1(a,a2,a0);
      if not(q eq 'failed)
        then <<a2 := car q; q := cdr q;
               a := exptsq(addsq(!*k2q mvar pol,shift),2);
               b := numr subs2q quotsq(addsq(multsq(!*f2q car q,a),
                                             !*f2q cadr q),
                                       !*f2q cadr p);
               a := numr subs2q quotsq(addsq(multsq(!*f2q caddr q,a),
                                             !*f2q cadddr q),
                                       !*f2q cadr p);
               a := quadraticf!*(a,var);
               b := quadraticf!*(b,var);
               return multf(a2,multf(car a,car b))
                         . nconc!*(cdr a,cdr b)>>
       else if null !*surds or denr shift neq 1
        then return list(1,pol);
       % Factorization not possible by this method.
      shift := numr shift;
      if knowndiscrimsign eq 'negative then go to complex;
      dsc := powsubsf addf(exptf(a2,2),multd(-4,multf(a,a0)));
      p2 := minusf a0;
      if not p2 and minusf dsc then go to complex;
      p1 := not a2 or minusf a2;
      if not p1 then if p2 then p1 := t else p2 := t;
      p1 := if p1 then 'positive else 'negative;
      p2 := if p2 then 'negative else 'positive;
      a := rootxf(a,2);
      dsc := rootxf(dsc,2);
      p := invsq !*f2q addf(a,a);
      q := multsq(!*f2q addf(a2,negf dsc),p);
      p := multsq(!*f2q addf(a2,dsc),p);
      b := multf(a,exptf(addf(!*k2f mvar pol,shift),2));
      a := powsubsf addf(b,q);
      b := powsubsf addf(b,p);
      knowndiscrimsign := p1;
      a := quadraticf!*(a,var);
      knowndiscrimsign := p2;
      b := quadraticf!*(b,var);
      knowndiscrimsign := nil;
      return multf(car a,car b) . nconc!*(cdr a,cdr b);
      % Complex case.
   complex:
      a := rootxf(a,2);
      a0 := rootxf(a0,2);
      a2 := powsubsf addf(multf(2,multf(a,a0)),negf a2);
      a2 := rootxf(a2,2);
      % Now a*(x+shift)**2 (+/-) b*(x+shift) + c is a factor.
      p := addf(!*k2f mvar pol,shift);
      q := addf(multf(a,exptf(p,2)),a0);
      p := multf(a2,p);
      a := powsubsf addf(q,p);
      b := powsubsf addf(q,negf p);
      knowndiscrimsign := 'negative;
      a := quadraticf!*(a,var);
      b := quadraticf!*(b,var);
      knowndiscrimsign := nil;
      return multf(car a,car b) . nconc!*(cdr a,cdr b)
   end;

endmodule;


module kronf;   % Kronecker factorization of univariate forms.

% Author: Anthony C. Hearn.

% Based on code first written by Mary Ann Moore and Arthur C. Norman.

% Copyright (c) 1987 The RAND Corporation. All rights reserved.

% exports linfacf,quadfacf;

% imports zfactor;

% Note that only linear and quadratic factors are found here.

symbolic procedure linfacf u; trykrf(u,'(0 1));

symbolic procedure quadfacf u; trykrf(u,'(-1 0 1));

symbolic procedure trykrf(u,points);
   % Look for factor of u by evaluation at points and interpolation.
   % Return (fac . cofac), with fac = nil if none found,
   % and cofac = nil if nothing worthwhile is left.
   begin scalar attempt,mv,values;
      if null u then return nil . nil
       else if length points > ldeg u then return nil . u;
      % Degree is too small to find factors.
      mv := mvar u;
      values := for each j in points collect subuf(j,u);
      if 0 member values
        then <<attempt := ((mv .** 1) .* 1) . -1;   % mv - 1
               return attempt . quotf(u,attempt)>>;
      values := for each j in values collect dfactors j;
      values := for each j in values
                   collect append(j,for each k in j collect !:minus k);
      attempt := search4facf(u,values,nil);
      if null attempt then attempt := nil . u;
      return attempt
   end;

symbolic procedure subuf(u,v);
   % Substitute integer u for main variable in univariate polynomial v.
   % Return an integer or a structured domain element.
   begin scalar z;
      if u=0 then u := nil;
      z := nil;
      while v do
         if domainp v then <<z := adddm!*(v,z); v := nil>>
          else <<if u then z := adddm!*(multdm!*(u**ldeg v,lc v),z);
                 % we should do better here.
                 v := red v>>;
      return if null z then 0 else z
   end;

symbolic procedure adddm!*(u,v);
   % Adds two domain elements u and v, returning a standard form.
   if null u then v else if null v then u else adddm(u,v);

symbolic procedure multdm!*(u,v);
   % Multiplies two domain elements u and v, returning a standard form.
   if null u or null v then nil else multdm(u,v);

symbolic procedure dfactors n;
   % Produces a list of all (positive) factors of the domain element n.
   begin scalar x;
      if n=0 then return list 0
       else if n=1 then return list 1
       else if !:minusp n then n := !:minus n;
      return if not atom n
        then if (x := get(car n,'factorfn))
               then combinationtimes apply1(x,n)
              else list n
       else combinationtimes zfactor n
   end;

symbolic procedure combinationtimes fl;
   if null fl then list 1
    else begin scalar n,c,res,pr;
        n := caar fl;
        c := cdar fl;
        pr := combinationtimes cdr fl;
        while c>=0 do <<res := putin(expt(n,c),pr,res); c := c-1>>;
        return res
    end;

symbolic procedure putin(n,l,w);
   if null l then w else putin(n,cdr l,(n*car l) . w);

symbolic procedure search4facf(u,values,cv);
   % combinatorial search for factors. cv gets current value set.
   if null values then tryfactorf(u,cv)
    else begin scalar q,w;
      w := car values;
 loop: if null w then return nil;   % no factor found
      q := search4facf(u,cdr values,car w . cv);
      if null q then <<w := cdr w; go to loop>>;
      return q
    end;

symbolic procedure tryfactorf(u,cv);
   % Tests if cv represents a factor of u.
   % For the time being, does not work on structured domain elements.
   begin scalar w;
      if null atomlis cv then return nil;
      if null cddr cv then w := linethroughf(cadr cv,car cv,mvar u)
       else w := quadthroughf(caddr cv,cadr cv,car cv,mvar u);
      if w eq 'failed or null (u := quotf(u,w)) then return nil
       else return w . u
   end;

symbolic procedure linethroughf(y0,y1,mv);
   begin scalar x;
      x := y1-y0;
      if x=0 then return 'failed
       else if x<0 then <<x:= -x; y0 := -y0>>;
       return if y0 = 0 or gcdn(x,y0) neq 1 then 'failed
               else (mv .** 1) .* x .+ y0
   end;

symbolic procedure quadthroughf(ym1,y0,y1,mv);
   begin scalar x,y,z;
      x := divide(ym1+y1,2);
      if cdr x=0 then x := car x-y0 else return 'failed;
      if x=0 then return 'failed;
      z := y0;
      y := divide(y1-ym1,2);
      if cdr y=0 then y := car y else return 'failed;
      if gcdn(x,gcdn(y,z)) neq 1 then return 'failed;
      if x<0 then <<x := -x; y := -y; z := -z>>;
      if z=0 then return 'failed
       else if y=0 then return ((mv .** 2) .* x) .+ z
       else return ((mv .** 2) .* x) .+ (((mv .** 1) .* y) .+ z)
   end;

endmodule;


module conj;  % Rationalize denoms of standard quotients by conjugate
              % computation.

% Author: Anthony C. Hearn.

% Modifications by: Eberhard Schruefer.

% Copyright (c) 1987 The RAND Corporation. All rights reserved.

fluid '(!*rationalize !*structure dmode!* kord!*);

put('rationalize,'simpfg,'((t (rmsubs)) (nil (rmsubs))));

symbolic smacro procedure subtrf(u,v);
   % Returns u - v for standard forms u and v.
   addf(u,negf v);

symbolic procedure rationalizesq u;
   % Rationalize the standard quotient u.
   begin scalar !*structure,!*sub2,x;   % Modified by R. Liska.
      % We need structure off to form rationalized denominator properly
      % in subs2f1.
      if x := get(dmode!*,'rationalizefn) then u := apply1(x,u);
      u := subs2q u;
      % We need the subs2 to get rid of surd powers.
      return if domainp denr u then u
             else if (x := rationalizef denr u) neq 1
              then rationalizesq (multf(numr u,x) ./ multf(denr u,x))
             else u
   end;

symbolic procedure powdiv(u,v);
   if null u then nil
    else if atom car u or cdar u = v then powdiv(cdr u,v)
    else if caar u eq 'expt and cadar u = car v
       and eqcar(caddar u,'quotient)
       and cadr caddar u = cadr cadr v
       and cdr divide(caddr caddar u,caddr cadr v) = 0
     then car u
    else powdiv(cdr u,v);

symbolic procedure rationalizef u;
   % Look for I and sqrts, cbrts, quartics at present.
   % I'm not sure I in the presence of (-1)^(1/4) say is handled
   % properly.
   begin scalar x,y,z;
      x := z := kernels u;
   a: if null x then return 1;
      y := car x;
      if eqcar(y,'expt) and eqcar(caddr y,'quotient)
          and powdiv(z,cdr y)
        then nil
       else if y eq 'i or eqcar(y,'expt) and caddr y = '(quotient 1 2)
          or eqcar(y,'sqrt)
        then return conjquadratic(mkmain(u,y),y)
       else if eqcar(y,'expt) and caddr y = '(quotient 1 3)
        then return conjcubic(mkmain(u,y),y)
       else if eqcar(y,'expt) and caddr y = '(quotient 1 4)
        then return conjquartic(mkmain(u,y),y);
      x := cdr x;
      go to a
   end;

symbolic procedure conjquadratic(u,v);
   if ldeg u = 1
      then subtrf(multf(!*k2f v,reorder lc u),reorder red u)
    else errach list(ldeg u,"invalid power in rationalizef");

symbolic procedure conjcubic(u,v);
   begin scalar c1,c2,c3;
     if ldeg u = 2 then <<c1 := reorder lc u;
                           if degr(red u,v) = 1
                              then <<c2 := reorder lc red u;
                                     c3 := reorder red red u>>
                            else c3 := reorder red u>>
      else <<c2 := reorder lc u;
             c3 := reorder red u>>;
     return addf(multf(exptf(!*k2f v,2),
                       subtrf(exptf(c2,2),multf(c1,c3))),
                 addf(multf(!*k2f v,subtrf(multf(!*q2f simp cadr v,
                                                 exptf(c1,2)),
                                           multf(c2,c3))),
                      subtrf(exptf(c3,2),multf(!*q2f simp cadr v,
                                               multf(c1,c2)))))
  end;

symbolic procedure conjquartic(u,v);
   begin scalar c1,c3,c4,q1,q2,q3,q4;
     if ldeg u = 3
        then <<c1 := reorder lc u;
               if degr(red u,v) = 1
                  then <<c3 := reorder lc red u;
                         c4 := reorder red red u>>
                else c4 := reorder red u>>
      else if ldeg u = 1
              then <<c3 := reorder lc u;
                     c4 := reorder red u>>;
     q1 := subtrf(addf(exptf(c3,3),multf(c1,exptf(c4,2))),
                  multf(!*q2f simp cadr v,multf(c3,exptf(c1,2))));
     q2 := negf addf(multf(!*q2f simp cadr v,multf(c4,exptf(c1,2))),
                     multf(exptf(c3,2),c4));
     q3 := addf(multf(c3,exptf(c4,2)),
                subtrf(multf(exptf(!*q2f simp cadr v,2),exptf(c1,3)),
                       multf(!*q2f simp cadr v,multf(c1,exptf(c3,2)))));
     q4 := subtrf(multf(!*q2f simp cadr v,
                        multf(multd(2,c1),multf(c3,c4))),
                  exptf(c4,3));
     return addf(multf(exptf(!*k2f v,3),q1),
                 addf(multf(exptf(!*k2f v,2),q2),
                      addf(multf(!*k2f v,q3),q4)))
    end;

symbolic procedure mkmain(u,var);
   % Make kernel var the main variable of u.
   begin scalar kord!*; kord!* := list var; return reorder u end;

endmodule;


module diff; % Differentiation package.

% Author: Anthony C. Hearn.

% Copyright (c) 1991 RAND.  All rights reserved.

fluid '(wtl!*);

global '(frlis!* mcond!* powlis!* subfg!*);

% Contains a reference to RPLACD (a table update), commented out.

symbolic procedure simpdf u;
   % U is a list of forms, the first an expression and the remainder
   % kernels and numbers.
   % Value is derivative of first form wrt rest of list.
   begin scalar v,x,y;
      if null subfg!* then return mksq('df . u,1);
      v := cdr u;
      u := simp!* car u;
  a:  if null v or null numr u then return u;
      x := if null y or y=0 then simp!* car v else y;
      if denr x neq 1 or atom numr x then typerr(prepsq x,"kernel")
       else (if domainp z
               then if get(car z,'domain!-diff!-fn)
                       then begin scalar dmode!*,alglist!*;
                              x := prepf z;
                              if null prekernp x
                                then typerr(x,"kernel")
                            end
                     else typerr(prepf z,"kernel")
              else if null red z and lc z = 1 and ldeg z = 1
                      then x := mvar z
              else typerr(prepf z,"kernel")) where z = numr x;
      v := cdr v;
      if null v then <<u := diffsq(u,x); go to a>>;
      y := simp!* car v;
      if null numr y then <<v := cdr v; y := nil; go to a>>
       else if not denr y=1 or not numberp numr y
        then <<u := diffsq(u,x); go to a>>;
      v := cdr v;
      for i:=1:car y do u := diffsq(u,x);
      y := nil;
      go to a
   end;

put('df,'simpfn,'simpdf);

symbolic procedure prekernp u;
   if atom u then idp u
    else idp car u
         and null((car u memq '(plus minus times quotient recip))
                   or ((car u eq 'expt) and fixp caddr u));

symbolic procedure diffsq(u,v);
   % U is a standard quotient, V a kernel.
   % Value is the standard quotient derivative of U wrt V.
   % Algorithm: df(x/y,z)= (x'-(x/y)*y')/y.
   multsq(addsq(difff(numr u,v),negsq multsq(u,difff(denr u,v))),
          1 ./ denr u);

symbolic procedure difff(u,v);
   %U is a standard form, V a kernel.
   %Value is the standard quotient derivative of U wrt V.
   % Allow for differentiable domains.
   if atom u then nil ./ 1
    else if atom car u
     then (if diff!-fn then apply2(diff!-fn,u,v) else nil ./ 1)
        where (diff!-fn =  get(car u,'domain!-diff!-fn))
    else addsq(addsq(multpq(lpow u,difff(lc u,v)),
                        multsq(diffp(lpow u,v),lc u ./ 1)),
               difff(red u,v));

symbolic procedure diffp(u,v);
   % U is a standard power, V a kernel.
   % Value is the standard quotient derivative of U wrt V.
   begin scalar n,w,x,y,z; integer m;
        n := cdr u;     % integer power.
        u := car u;     % main variable.
        if u eq v and (w := 1 ./ 1) then go to e
         else if atom u then go to f
         %else if (x := assoc(u,dsubl!*)) and (x := atsoc(v,cdr x))
%               and (w := cdr x) then go to e   % deriv known.
             % DSUBL!* not used for now.
         else if (not atom car u and (w:= difff(u,v)))
                  or (car u eq '!*sq and (w:= diffsq(cadr u,v)))
          then go to c  % extended kernel found.
         else if x := get(car u,'dfform) then return apply3(x,u,v,n)
         else if x:= get(car u,'dfn) then nil
         else if car u eq 'plus and (w := diffsq(simp u,v))
          then go to c
         else go to h;  % unknown derivative.
        y := x;
        z := cdr u;
    a:  w := diffsq(simp car z,v) . w;
        if caar w and null car y then go to h;  % unknown deriv.
        y := cdr y;
        z := cdr z;
        if z and y then go to a
         else if z or y then go to h;  % arguments do not match.
        y := reverse w;
        z := cdr u;
        w := nil ./ 1;
    b:  % computation of kernel derivative.
        if caar y
          then w := addsq(multsq(car y,simp subla(pair(caar x,z),
                                                   cdar x)),
                          w);
        x := cdr x;
        y := cdr y;
        if y then go to b;
    c:  % save calculated deriv in case it is used again.
        % if x := atsoc(u,dsubl!*) then go to d
        %  else x := u . nil;
        % dsubl!* := x . dsubl!*;
  % d:   rplacd(x,xadd(v . w,cdr x,t));
    e:  % allowance for power.
        % first check to see if kernel has weight.
        if (x := atsoc(u,wtl!*))
          then w := multpq('k!* .** (-cdr x),w);
        m := n-1;
        % Evaluation is far more efficient if results are rationalized.
        return rationalizesq if n=1 then w
                else if flagp(dmode!*,'convert)
                     and null(n := int!-equiv!-chk
                                           apply1(get(dmode!*,'i2d),n))
                 then nil ./ 1
                else multsq(!*t2q((u .** m) .* n),w);
    f:  % Check for possible unused substitution rule.
        if not depends(u,v)
           and (not (x:= atsoc(u,powlis!*))
                 or not depends(cadddr x,v))
          then return nil ./ 1;
        w := list('df,u,v);
        go to j;
    h:  % Final check for possible kernel deriv.
        if car u eq 'df
          then if depends(cadr u,v)
                 then if (x := find_sub_df(w:= cadr u . derad(v,cddr u),
                                           get('df,'kvalue)))
                          then <<w := simp car x;
                                 for each el in cdr x do
                                    for i := 1:cdr el do
                                        w := diffsq(w,car el);
                                 go to e>>
                       else w := 'df . w
                else return nil ./ 1
         else if depends(u,v) then w := list('df,u,v)
         else return nil ./ 1;
    j:  w := if x := opmtch w then simp x else mksq(w,1);
        go to e
   end;

% The following three functions, and the hooks to this code above, were
% suggested by Gerhard Post and Marcel Roelofs.

symbolic procedure find_sub_df(df_args,df_values);
   df_values and
      (is_sub_df(df_args,car df_values) or
       find_sub_df(df_args,cdr df_values));

symbolic procedure is_sub_df(df_args,df_value);
   begin scalar df_set,kernel,n,entry;
     if car(df_args) neq cadar(df_value) then return nil;  % check fns.
     df_args := dot_df_args cdr df_args;
     df_set  := cddar df_value;
     while df_set and df_args do              % Check differentiations.
       <<kernel := car df_set;
         if cdr df_set and fixp(n := cadr df_set)
           then df_set := cdr df_set else n := 1;
         if (entry := atsoc(kernel,df_args))
                 and (n := cdr entry-n) geq 0
           then rplacd(entry,n) else df_args:=nil;
         df_set := cdr df_set>>;
     return if df_args then (cadr(df_value) . df_args);
   end;

symbolic procedure dot_df_args l;
   begin scalar kernel,n,df_args;
     while l do
       <<kernel := car l;
         if cdr l and fixp(n := cadr l) then l := cdr l else n := 1;
         df_args := (kernel . n) . df_args;
         l := cdr l>>;
     return df_args;
   end;

symbolic procedure derad(u,v);
   if null v then list u
    else if numberp car v then car v . derad(u,cdr v)
    else if u=car v then if cdr v and numberp cadr v
                           then u . (cadr v + 1) . cddr v
                          else u . 2 . cdr v
    else if ordp(u,car v) then u . v
    else car v . derad(u,cdr v);

symbolic procedure letdf(u,v,w,x,b);
   begin scalar y,z;
        if atom cadr x then go to b
         else if not idp caadr x then typerr(caadr x,"operator")
         else if not get(caadr x,'simpfn)
          then <<redmsg(caadr x,"operator"); mkop caadr x>>;
        rmsubs();
        if not mcond!* eq 't
                or not frlp cdadr x
                or null cddr x
                or cdddr x
                or not frlp cddr x
                or not idlistp cdadr x
                or repeats cdadr x
                or not caddr x member cdadr x
         then go to b;
        z := lpos(caddr x,cdadr x);
        if not get(caadr x,'dfn)
            then put(caadr x,
                     'dfn,
                     nlist(nil,length cdadr x));
        w := get(caadr x,'dfn);
        if length w neq length cdadr x
          then rerror(poly,17,
                      list("Incompatible DF rule argument length for",
                            caadr x));
   a:   if null w or z=0 then return errpri1 u
         else if z neq 1
          then <<y := car w . y; w := cdr w; z := z-1; go to a>>
         else if null b then y := append(reverse y,nil . cdr w)
         else y := append(reverse y,(cdadr x . v) . cdr w);
        return put(caadr x,'dfn,y);
   b:   %check for dependency;
        if caddr x memq frlis!* then return nil
         else if idp cadr x and not(cadr x memq frlis!*)
           then depend1(cadr x,caddr x,t)
         else if not atom cadr x and idp caadr x and frlp cdadr x
          then depend1(caadr x,caddr x,t);
        return nil
   end;

symbolic procedure frlp u;
   null u or (car u memq frlis!* and frlp cdr u);

symbolic procedure lpos(u,v);
   if u eq car v then 1 else lpos(u,cdr v)+1;


endmodule;


module polyop; % Functions for algebraic mode operations on polynomials.

% Author: Anthony C. Hearn.

% Modified by: F. Kako, F.J. Wright.

% Copyright (c) 1991 RAND. All rights reserved.

fluid '(!*ratarg);

symbolic procedure deg(u,kern);
   <<u := simp!* u; tstpolyarg(denr u,u); numrdeg(numr u,kern)>>;

symbolic procedure numrdeg(u,kern);
   begin scalar x;
      kern := !*a2k kern;
      if domainp u then return 0
       else if mvar u eq kern then return !*f2a ldeg u;
      x := updkorder kern;
      u := reorder u;
      if not(mvar u eq kern) then u := 0 else u := ldeg u;
      setkorder x;
%     return !*f2a u
      return u
   end;

% In the following, it is assumed that lcof and lterm are non-zero only
% when the expression is at least linear in kern.

symbolic procedure lcof(u,kern);
   begin scalar x,y;
      u := simp!* u;
      y := denr u;
      tstpolyarg(y,u);
      u := numr u;
      kern := !*a2k kern;
      if domainp u then return 0
       else if mvar u eq kern
        then return !*ff2a(lc u,y);
      x := updkorder kern;
      u := reorder u;
      if mvar u eq kern then u := lc u;
      setkorder x;
      return if null u then 0 else !*ff2a(u,y)
   end;

symbolic procedure lterm(u,kern);
   begin scalar x,y;
      u := simp!* u;
      y := denr u;
      tstpolyarg(y,u);
      u := numr u;
      kern := !*a2k kern;
      if domainp u then return 0
       else if mvar u eq kern
        then return !*ff2a(lt u .+ nil,y);
      x := updkorder kern;
      u := reorder u;
      if mvar u eq kern then u := lt u .+ nil else u := nil;
      setkorder x;
      u := reorder u;
      return !*ff2a(u,y)
   end;

symbolic procedure !*lterm u; lt u .+ nil;

symbolic procedure mainvar u;
   if domainp(u := numr simp!* u) then 0
    else if sfp(u := mvar u) then prepf u
    else u;

symbolic procedure reduct(u,kern);
   begin scalar x,y;
      u := simp!* u;
      y := denr u;
      tstpolyarg(y,u);
      u := numr u;
      kern := !*a2k kern;
      if domainp u then return !*ff2a(u,y)
       else if mvar u eq kern
        then return !*ff2a(cdr u,y);
      x := updkorder kern;
      u := reorder u;
      if mvar u eq kern then u := cdr u;
      setkorder x;
      u := reorder u;
      return !*ff2a(u,y)
   end;

symbolic procedure tstpolyarg(y,u);
   null !*ratarg and y neq 1 and typerr(prepsq u,"polynomial");

% symbolic operator deg,lcof,lterm,mainvar,reduct;

flag('(deg lcof lterm mainvar reduct),'opfn);  % This way for booting.

endmodule;


module decompose; % Decomposition of polynomials f(x) = g(h(x)).

% Author: Herbert Melenk <melenk@sc.zib-berlin.de>.

% Algorithms: 1. univariate case:
%            V.S. Alagar, M.Tanh: Fast Polynomial Decomposition
%            Algorithms, EUROCAL 1985, pp 150-153 (Springer).
%
%             2. multivariate lifting:
%            J. von zur Gathen: Functional Decomposition of Polynomials:
%            the Tame Case, J. Symbolic Computation (1990) 9, 281-299.

% Copyright (c) 1990 ZIB.

put('decompose,'psopfn,'decomposesf);

symbolic procedure decomposesf f;
  'list . reverse decomposef2(simp reval car f,t)
        where !*factor=nil,!*exp=t;

symbolic procedure decomposef1(f,msg);
    decomposef2(f ./ 1 ,msg);

symbolic procedure decomposef2(f,msg);
   begin scalar hvars,r,rr,x,y,u,vars,newvars,d;
      vars := decomposesfvars(numr f,nil);
      newvars := for each x in vars collect gensym();
      d := denr f;
      if not domainp d
        then rerror(poly,18,typerr(prepsq f,"polynomial"));
      f := numr subf(numr f,pair(vars,newvars));
      if length vars = 1 then r := decomposesfuni0 f
       else r := decomposesfmulti(f,newvars);
      hvars := '(u v w a b c d e);
      for each x in vars do hvars := delete (x,hvars);
      while r do
       <<if cdr r
           then <<y := x; x := nil;
                  while null x do
                     if hvars then <<x := car hvars; hvars := cdr hvars;
                                     if not x=reval x then x:=nil>>
                      else x:=gensym();
                  u := prepsq subsq(car r,list(mvar numr car r . x));
                  if d neq 1 then<<u:=list('quotient,u,prepf d);d:=1>>;
                  rr := (if y then list('equal,y,u) else u) . rr>>
          else <<u := prepsq car r;
                 y := x;
                 rr := (if y then list('equal,y,u) else u) . rr>>;
         r := cdr r>>;
      rr := subla(pair(newvars,vars),car rr) . cdr rr;
      return rr
   end;

symbolic procedure decomposesfvars(f,v);
    % Select the kernels from a standard form.
      if domainp f then v else
        decomposesfvars(red f,
            decomposesfvars(lc f,
                if not member(mvar f,v)
                 then append(v,list mvar f) else v));

symbolic procedure decomposesfuni0 f;
    for each p in decomposesfuni f collect (p ./ 1);

symbolic procedure decomposesfuni f;
    % Univariate variant.
   begin scalar x,y,res,ddfl,h,testf;
      integer n,m;
     n := ldeg f;
     if primep n then return list f;
     x := mvar f; y := gensym();
     ddfl := decomposefctrf decomposedf(f,x);
    if length ddfl > 1 then
     for each d in ddfl do
      if null res and quotf (n , (ldeg d + 1)) then
      <<h := numr decomposeint(d,x);
          if null testf then
               testf := addf(f,negf numr subf(f,list(x . y)));
          if quotf (testf,
                    addf(h,negf numr subf(h,list(x . y)))) then
          res := list(decomposebacksubstuni(f,h,x),h);
      >>;
      if null res then return list f else
          return for each u in res join decomposesfuni u
   end;

symbolic procedure decomposefctrf f;
    % Generate all factors of f by combining the prime factors.
   begin scalar u,w,q;
       q := fctrf f; u:= cdr q;
       if length u = 1 and cdar u=1 then return list f;
          % eliminate the two trivial factors.
       w := delete(quotf(f,car q),decomposefctrf1 u);
       w := delete(1,w);
       return w;
   end;

symbolic procedure decomposefctrf1 v;
    % Collect all possible crossproducts from v.
    if null v then '(1) else
    begin scalar r,c,q;
     c:=car v;
     r:=decomposefctrf1 cdr v;
     q:=for i:=1:cdr c collect exptf(car c,i);
     return
      append(r,
       for each u in q join
         for each p in r collect
             multf(u,p)  );
    end;

symbolic procedure decomposebacksubstuni(f,h,x);
  begin scalar c,g,n,p,pars,ansatz,eqs;
     p := 1; n := ldeg f/ldeg h;
     for i:=0:n do
     <<c := mkid('coeff,i);
       pars := c . pars;
       ansatz := addf(multf(numr simp c,p) , ansatz);
       p := multf(p,h);
     >>;
     pars := reverse pars;
     ansatz := addf(f , negf ansatz);
     eqs := decomposecoeff(ansatz,list x);
     eqs := solveeval list('list . for each u in eqs collect prepf u,
                       'list . pars);
     eqs := cdr cadr eqs; % select the only solution.
     for i:= 0:n do
       g := addf(g,numr simp list('times,list('expt,x,i),
                                  caddr nth(eqs,i+1)));
     return g
   end;

symbolic procedure decomposedf(f,x);
   % Differentiate a polynomial wrt top-level variable x.
   % Returns a standard form.
    if domainp f or not(mvar f = x) then nil else
    if ldeg f = 1 then lc f else
    mvar f .** (ldeg f - 1) .* multf(lc f,ldeg f)
           .+ decomposedf(red f,x);

symbolic procedure decomposeint(f,x);
   % Integrate a polynomial (standard form) wrt the (main-)variable x.
   % Returns a standard quotient.
    if null f then nil ./ 1 else
    if domainp f then (x .** 1 .* f .+ nil) ./ 1 else
    addsq(multsq((x .** (ldeg f + 1) .* 1 .+ nil)./ 1 ,
                 multsq(lc f./1,1 ./ldeg f+1))
          ,  decomposeint(red f,x));

symbolic procedure decomposecoeff(f,vars);
   % Select the coefficients of f wrt vars.
     begin scalar o;
       o := setkorder vars;
       f := reorder f;
       setkorder o;
       return decomposecoeff1(f,vars)
     end;

symbolic procedure decomposecoeff1(f,vars);
     if domainp f then nil else
     if not member(mvar f,vars) then list f else
     nconc(decomposecoeff1(lc f,vars),decomposecoeff1(red f,vars));

symbolic procedure decomposetdg f;
    % calculate total degree
    if domainp f then 0 else
    max(ldeg f + decomposetdg lc f, decomposetdg red f);

symbolic procedure  decomposedegr(f,vl);
   if domainp f then vl else
   <<if ldeg f > cdr v then cdr v := ldeg f;
     decomposedegr(lc f,vl);
     decomposedegr(red f,vl);
     vl>> where v = assoc(mvar f,vl);

symbolic procedure compose (u,v);
    % Calculate f(x)=u(v(x)) for standard forms u,v.
    if domainp u then u else
         numr subf(u,list(mvar u . prepf v));

% Multivariate polynomial decomposition.
%
% Technique: 
%    select a field as domain (rational),
%      map f to a strongly monic polynomial by variable transform,
%        map f to a univariate image,
%            decompose the univariate polynomial,
%        lift decomposition to multivariate,
%      convert back to original variables,
%    transform back to original domain (if possible).

symbolic procedure decomposesfmulti(f,vars);
   % Multivariant case: map to field (rationals).
    begin scalar dm,ft,r,rr,a,q,c,p1,p2;
      if null dmode!* or not flagp(dmode!*,'field) then
     <<setdmode('rational,t) where !*msg=nil; dm := t;
       ft := !*q2f resimp !*f2q f>> else ft := f;
     r := decomposesfmulti1(ft,vars);
     if dm then setdmode('rational,nil) where !*msg=nil;
     if null cdr r then return list(f./1);
     if null dm then return
        for each p in r collect (p ./ 1);
       % Convert back to integer polynomials.
     rr := for each p in reverse r collect simp prepf p;
     r := nil;
     while rr and cdr rr do
     <<p1 := car rr; p2 := cadr rr;
          % Propagate absolute term and content from p1 to p2.
       q := denr p1; a := numr p1;
       while not domainp a do a := red a;
       p1 := addf(numr p1,negf a);
       c := decomposecont p1;
       p1 := multsq(p1 ./ 1, 1 ./ c);
       p2 := subsq(p2,list(mvar numr p2 .
              list('quotient,
                   list('plus,list('times,gensym(),prepf c),
                              prepf a),
                     prepf q)));
       r := p1 . r; rr := p2 . cddr rr>>;
     return car rr . r;
   end;

symbolic procedure decomposesfmulti1(f,vars);
  % Multivariate case: map to strongly monic polynomial.
    begin scalar lvars,ft,rt,x1,a0,kord,u,sigma;
     integer n,m;
       % get the variable with highest degree as main variable.
     u :=  decomposedegr(f,for each x in vars collect (x. 0));
     n := -1;
     for each x in u do
       if n<cdr x then <<n:=cdr x; x1 := car x>>;
     if n<2 then return list f;
     vars := x1 . delete(x1,vars);
     kord := setkorder vars;
     f := reorder f;
       % Convert f to a strongly monic polynomial.
     n := decomposetdg f;
     x1 := car vars;
     lvars := for each x in cdr vars collect (x . gensym());
    again:
     if m>10 then << rt := list f; goto ret>>;
       % construct transformation sigma
     sigma := for each x in lvars collect x . random 1000;
     ft := numr subf(f,for each x in sigma collect
           (caar x . list('plus,cdar x,list('times,x1,cdr x))));
     if not domainp lc ft then <<m:=m+1; goto again>>;
     a0 := lc ft; ft := quotf(ft,a0);
     rt := decomposesfmnorm(ft,n,sublis(lvars,vars));
     if cdr rt then
      % Transform result back.
     <<rt := reverse rt;
       rt := numr subf(car rt,for each x in sigma collect
           (cdar x . list('difference,caar x,list('times,cdr x,x1))))
           . multf(a0,cadr rt) . cddr rt;
     >> else rt := list f;
   ret:
     setkorder kord;
     rt := for each p in rt collect reorder p;
        % try further decomposition of central polynomial.
     return if cdr rt and decomposetdg car rt>1 then
         append(reverse cdr rt,decomposesfmulti1(car rt,vars))
           else reverse rt;
   end;

symbolic procedure decomposelmon f;
   % Extract the variables of the leading monomial.
     if domainp f then nil else
     mvar f . decomposelmon lc f;

symbolic procedure decomposecont f;
   % Calculate the integer content of f.
      if domainp f then f else
      gcdf(decomposecont lc f, decomposecont red f);

symbolic procedure decomposesfmnorm(f,n,vars);
   % Multivariate case: map strongly monic polynomial to univariate
   % and lift result.
   begin scalar x,x1,f0,g,u,abort,h,k,tt,q,v;
      integer r,s;
     x1 := car vars;
    % Step 1.
     f0 := numr subf(f,for each y in cdr vars collect (y . 0));
     u := decomposesfuni f0;
        % For multivariate we accept degree=1 polynomials as nontrivial
        % but inhibit recursion.
     if null cdr u then <<u:=append(u,list !*k2f x1)>>;
     x := gensym();
     g := numr subf(car u,list (x1 . x));
     r := ldeg g;
     h := cadr u; u := cddr u;
     while u do
     <<v := car u; u:= cdr u; h := numr subf(h,list(x1 . x));
       h := compose(h,v); >>;
      % Step 2.
     s := divide(n,r);
     if not(cdr s=0) then goto fail else s := car s;
     k := h;
     tt := compose(decomposedf(g,x),h);
      % Step 3: Hensel lifting in degree steps.
     for i:=1:s do
       if not abort then
        % Step 4: loop step.
       <<u := decomposehomog(addf(f,negf compose(g,k)),x1,i);
         q := quotf(u,tt);
         if u and null q then abort:=t else<<h:=q; k:=addf(k,h)>>
       >>;
      if abort then goto fail;
      % Step 5: test result and loop for lower part.
      h := k;
      if f = compose(g,h) then return list(g,h);
  fail:  % Exit: no decomposition found.
     return list f;
   end;

symbolic procedure decomposehomog(f,x,d);
   % F is a polynomial (standard form) in x and some other 
   % variables. Select that part of f, where the coefficients
   % of x are monomials in total degree d.
   % Result is the sum (standard form) of these monomials.
   begin scalar u,v;
      u := decomposehomog1(f,x,d);
      for each m in u do v := addf(v,m);
      return v;
  end;

symbolic procedure decomposehomog1(f,x,d);
   % Select the monomials.
   if d<0 or null f then nil else
   if domainp f then (if d=0 then list f else nil)
   else begin scalar u1,u2;
     u1:= decomposehomog1(lc f,x,if mvar f = x then d
                                  else d-ldeg f);
     u2:= decomposehomog1(red f,x,d);
     return
        nconc(
         for each v in u1 collect
              multf(mvar f .** ldeg f .*1 .+ nil , v),
           u2);
  end;

endmodule;


module interpol; % polynomial interpolation (Aitken & Neville).

% Author: Herbert Melenk <melenk@sc.zib-berlin.de>.

symbolic procedure interpol(fc,x,pts);
   % find a polynomial f(x) such that holds:
   %   f(part(pts,i)) = part(fc,i)  for all i <= lenth pts.
   % The Aitken-Neville schema is used; it is stable for
   % symbolic and numeric values.
 begin scalar d,q,s,p1,p2,x1,x2,f1,f2,fnew;
    if not eqcar(fc,'list) or not eqcar(pts,'list)
       or not(length fc=length pts)
      then rerror(poly,19,"Illegal parameters for interpol");
   s:=for each p in pair(cdr fc,cdr pts) collect
       simp car p . simp cdr p . simp cdr p;
   x:= simp x;
       % outer loop as long as there is more than 1 element.
   while cdr s do
   <<q:= nil;
       % inner loop for all adjacent pairs of polynomials.
     while cdr s do
     <<p1:=car s; s:=cdr s; p2:=car s;
       f1:=car p1; f2:=car p2; x1:=cadr p1; x2:=cddr p2;
       d:=subtrsq(x1,x2);
       if null numr d then rerror(poly,20,
         "Interpolation impossible if two points are equal");
       fnew:=
         quotsq(
          subtrsq(multsq(subtrsq(x,x2),f1),
                  multsq(subtrsq(x,x1),f2)),
          d);
       q:=(fnew.x1.x2).q;
     >>;
      s:=reversip q;
   >>;
   return prepsq caar s;
 end;

% We can't do following for bootstrapping reasons.

% symbolic operator interpol;

flag('(interpol),'opfn);

endmodule;


module subs2q;  % Routines for substituting for powers.

% Author: Anthony C. Hearn.

% Copyright (c) 1991 The RAND Corporation. All rights reserved.

fluid '(!*mcd !*structure !*sub2 alglist!* dmode!*);

global '(!*resubs frlis!* powlis!* powlis1!* simpcount!*
         simplimit!*);

Comment If STRUCTURE is ON, then expressions like (a**(b/2))**2 are not
simplified, to allow some attempt at a structure theorem use, especially
in the integrator;

symbolic procedure subs2q u;
   % Perform power substitutions on u. Check whether substitions
   % on numerator and denominator change these before doing   
   % quotient (to avoid undoing rationalization of denominator).
   ((if denr x=1 and denr y=1 and numr x=v and numr y=w then u
      else quotsq(x,y))
     where x=subs2f v, y=subs2f w)
    where v=numr u, w=denr u;

symbolic procedure subs2f u;
   begin scalar x;
        if simpcount!*>simplimit!*
         then <<simpcount!* := 0;
                rerror(poly,21,"Simplification recursion too deep")>>;
        simpcount!* := simpcount!*+1;
        !*sub2 := nil;
        x := subs2f1 u;
        if (!*sub2 or powlis1!*) and !*resubs
           then if numr x=u and denr x=1 then !*sub2 := nil
                else x := subs2q x;
        simpcount!* := simpcount!*-1;
        return x
   end;

symbolic procedure subs2f1 u;
   if domainp u then !*d2q u
    else begin scalar kern,v,w,x,y,z;
        kern := mvar u;
        z := nil ./ 1;
    a:  if null u or degr(u,kern)=0 then go to a1;
        y := lt u .+ y;
        u := red u;
        go to a;
    a1: x := powlis!*;
    a2: if null x then go to b
         else if caaar y = caar x
          then <<w := subs2p(caar y,cadar x,cadddr car x); go to e1>>
%        else if eqcar(kern,'sqrt) and cadr kern = caar x
%         then <<w := raddsq(subs2p(cadr kern . cdaar y,
%                            cadar x,cadddr car x),2);% go to e1>>;
         else if eqcar(kern,'expt)
                and cadr kern = caar x
                and eqcar(caddr kern,'quotient)
                and cadr caddr kern = 1
                and numberp caddr caddr kern
          then <<v := divide(cdaar y,caddr caddr kern);
%       if car v neq 0 then w := mksq(cadr kern,car v)
        % Use simp/exptsq to make sure I converted in complex mode.
        if car v neq 0 then w := exptsq(simp cadr kern,car v)
                  else w := 1 ./ 1;
                 if cdr v neq 0
                   then <<begin scalar alglist!*,dmode!*;
                          % We must do exponent arithmetic in integer
                          % mode.
                             v := cancel(cdr v.caddr caddr kern)
                          end;
                         w := multsq(raddsq(subs2p(cadr kern . car v,
                                        cadar x,cadddr car x),
                                cdr v),w)>>;
                 go to e1>>;
        x := cdr x;
        go to a2;
    b:  x := powlis1!*;
    l2: if null x then go to l3
         else if w:= mtchp(caar y,caar x,caddar x,caadar x,cdadar x)
          then go to e1;
        x := cdr x;
        go to l2;
    l3: if eqcar(kern,'expt) and not !*structure then go to l1;
        z := addsq(multpq(caar y,subs2f1 cdar y),z);
    c:  y := cdr y;
        if y then go to a1;
    d:  return addsq(z,subs2f1 u);
    e1: z := addsq(multsq(w,subs2f1 cdar y),z);
        go to c;
    l1: if cdaar y=1 and not eqcar(cadr kern,'expt)     % ONEP
          then w := mksq(kern,1)
         else w := simpexpt list(cadr kern,
                                 list('times,caddr kern,cdaar y));
        z := addsq(multsq(w,subs2f1 cdar y),z);
        y := cdr y;
        if y then go to l1 else go to d;
    end;

symbolic procedure subs2p(u,v,w);
   %U is a power, V an integer, and W an algebraic expression, such
   %that CAR U**V=W. Value is standard quotient for U with this
   %substitution;
   begin
      v := divide(cdr u,v);
      if car v=0 then return !*p2q u;
      w := exptsq(simp w,car v);
      return if cdr v=0 then w else multpq(car u .** cdr v,w)
   end;

symbolic procedure raddsq(u,n);
   %U is a standard quotient, N and integer. Value is sq for U**(1/N);
   simpexpt list(mk!*sq u,list('quotient,1,n));

symbolic procedure mtchp(u,v,w,flg,bool);
   %U is a standard power, V a power to be matched against.
   %W is the replacement expression.
   %FLG is a flag which is T if an exact power match required.
   %BOOL is a boolean expression to be satisfied for substitution.
   %Value is the substitution standard quotient if a match found,
   %NIL otherwise;
   begin scalar x;
        x := mtchp1(u,v,flg,bool);
    a:  if null x then return nil
         else if lispeval subla(car x,bool) then go to b;
        x := cdr x;
        go to a;
    b:  v := divide(cdr u,subla(car x,cdr v));
        w := exptsq(simp subla(car x,w),car v);
        if cdr v neq 0 then w := multpq(car u .** cdr v,w);
        return w
   end;

symbolic procedure mtchp1(u,v,flg,bool);
   %U is a standard power, V a power to be matched against.
   %FLG is a flag which is T if an exact power match required.
   %BOOL is a boolean expression to be satisfied for substitution.
   %Value is a list of possible free variable pairings which
   %match conditions;
   begin scalar x,y;
        if u=v then return list nil
         else if not (x:= mchk!*(car u,car v)) then return nil
         else if cdr v memq frlis!*
             % do not match a free power to 1 or a conflicting match.
          then if cdr u=1 or not(x:= powmtch(cdr v,x,cdr u))
                 then return nil
                else return mapcons(x,cdr v . cdr u)
         else if (flg and not cdr u=cdr v)
                or (if !*mcd then cdr u<cdr v
                     else (cdr u*cdr v)<0 or
                        %implements explicit sign matching;
                            abs cdr u<abs cdr v)
          then return nil
         else return x
   end;

symbolic procedure powmtch(u,v,w);
   % Match a free power u against list of pairings v for value w.
   % Note from ACH:  I have not yet found a case where this process
   % results in a match, even if a non-NIL value is returned.  An
   % example with this procedure being necessary would be appreciated.
   if null v then nil
    else (if null x or cdr x=w then car v . powmtch(u,cdr v,w)
           else powmtch(u,cdr v,w))
        where x=atsoc(u,car v);

symbolic procedure mchk!*(u,v);
   begin scalar x;
      if x := mchk(u,v) then return x
       else if !*mcd or not (sfp u and sfp v) then return nil
       else return mchk(prepf u,prepf v)
   end;

endmodule;


module subs3q; % Routines for matching products.

% Author: Anthony C. Hearn.

% Copyright (c) 1992 RAND.  All rights reserved.

fluid '(!*mcd !*sub2);

global '(!*match !*resubs mchfg!* powlis1!*);

symbolic procedure subs3q u;
   %U is a standard quotient.
   %Value is a standard quotient with all product substitutions made;
   begin scalar x;
        x := mchfg!*;   %save value in case we are in inner loop;
        mchfg!* := nil;
        u := quotsq(subs3f numr u,subs3f denr u);
        mchfg!* := x;
        return u
   end;

symbolic procedure subs3f u;
   %U is a standard form.
   %Value is a standard quotient with all product substitutions made;
   subs3f1(u,!*match,t);

symbolic procedure subs3f1(u,l,bool);
   %U is a standard form.
   %L is a list of possible matches.
   %BOOL is a boolean variable which is true if we are at top level.
   %Value is a standard quotient with all product substitutions made;
   begin scalar x,z;
        z := nil ./ 1;
    a:  if null u then return z
         else if domainp u then return addsq(z,u ./ 1)
         else if bool and domainp lc u then go to c;
        x := subs3t(lt u,l);
        if not bool                             %not top level;
         or not mchfg!* then go to b;           %no replacement made;
        mchfg!* := nil;
        if numr x = u and denr x = 1 then <<x := u ./ 1; go to b>>
         % also shows no replacement made (sometimes true with non
         % commuting expressions)
         else if null !*resubs then go to b
         else if !*sub2 or powlis1!* then x := subs2q x;
           %make another pass;
        x := subs3q x;
    b:  z := addsq(z,x);
        u := cdr u;
        go to a;
    c:  x := list lt u ./ 1;
        go to b
   end;

symbolic procedure subs3t(u,v);
   % U is a standard term, V a list of matching templates.
   % Value is a standard quotient for the substituted term.
   begin scalar bool,w,x,y,z;
        x := mtchk(car u,if domainp cdr u then sizchk(v,1) else v);
        if null x then go to a                  %lpow doesn't match;
         else if null caar x then go to b;      %complete match found;
        y := subs3f1(cdr u,x,nil);              %check tc for match;
        if mchfg!* then return multpq(car u,y);
    a:  return list u . 1;                      %no match;
    b:  x := cddar x;           %list(<subst value>,<denoms>);
        z := caadr x;           %leading denom;
        mchfg!* := nil;         %initialize for tc check;
        y := subs3f1(cdr u,!*match,nil);
        mchfg!* := t;
        if car z neq caar u then go to e
         else if z neq car u    %powers don't match;
          then y := multpq(caar u .** (cdar u-cdr z),y);
    b1: y := multsq(simpcar x,y);
        x := cdadr x;
        if null x then return y;
        z := 1;                 %unwind remaining denoms;
    c:  if null x then go to d;
        w:= if atom caar x or sfp caar x then caar x else
             ((lambda ww;
                if kernp ww and eqcar(ww := mvar numr ww,car caar x)
                  then ww
                 else revop1 caar x)
               simp0 caar x);
        % In the non-commutative case we have to be very careful about
        % order of terms in a product. Introducing negative powers
        % solves this problem.
        if noncomp w or not !*mcd then bool := t;
%       z := multpf(mksp(w,if null bool then cdar x else -cdar x),z);
%       original line
        z := multf(z,!*p2f mksp(w,
                                if null bool then cdar x else -cdar x));
        % kernel CAAR X is not unique here. Earlier versions used just
        % CAAR X, but this leads to sums of terms in the wrong order.
        % The code here is probably still not correct in all cases, and
        % may lead to unbounded calculations. Maybe SIMP should be used
        % instead of REVOP1, with appropriate adjustments in the code
        % to construct Z.
        x := cdr x;
        go to c;
    d:  return if not bool then car y . multf(z,cdr y)
                else multf(z,car y) . cdr y;
    e:  if simp car z neq simp caar u then errach list('subs3t,u,x,z);
        %maybe arguments were in different order, otherwise it's fatal;
        if cdr z neq cdar u
          then y:= multpq(caar u .** (cdar u-cdr z),y);
        go to b1
   end;

symbolic procedure sizchk(u,n);
   if null u then nil
    else if length caar u>n then sizchk(cdr u,n)
    else car u . sizchk(cdr u,n);

symbolic procedure mtchk(u,v);
   %U is a standard power, V a list of matching templates.
   %If a match is made, value is of the form:
   %list list(NIL,<boolean form>,<subst value>,<denoms>),
   %otherwise value is an updated list of templates;
   begin scalar flg,v1,w,x,y,z;
        flg := noncomp car u;
    a0: if null v then return z;
        v1 := car v;
        w := car v1;
    a:  if null w then go to d;
        x := mtchp1(u,car w,caadr v1,cdadr v1);
    b:  if null x then go to c
         else if car (y := subla(car x,delete(car w,car v1))
                                . list(subla(car x,cadr v1),
                                      subla(car x,caddr v1),
                                      subla(car x,car w)
                                          . cadddr v1))
          then z := y . z
         else if lispeval subla(car x,cdadr v1) then return list y;
        x := cdr x;
        go to b;
    c:  if null flg then <<w := cdr w; go to a>>
         else if cadddr v1 and nocp w then go to e;
    d:  z :=aconc(z,v1);   % Could also be append(z,list v1).
    e:  v := cdr v;
        go to a0
   end;

symbolic procedure nocp u;
   null u or (noncomp caar u and nocp cdr u);

endmodule;


end;
