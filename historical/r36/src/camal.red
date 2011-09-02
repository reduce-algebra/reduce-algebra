module camal;  % Package for calculations in celestial mechanics.

% Author: John P. Fitch <jpff@maths.bath.ac.uk>

create!-package('(camal fourdom fourplus makefour hsub hdiff),
                '(contrib camal));

%% This section is to define macros and simple functions to handle the
%% data structures for harmonic forms.
%% The structure is a vector:
%% Coeff | FN | Angle | Next
%
%% This version only allows 8 angles.  Consider extending this later.

switch fourier;

%% A vector and counter to record link between angle names and index

global '(next!-angle!* fourier!-name!*);
next!-angle!* := 0;
if vectorp fourier!-name!* then <<
        for i :=0:7 do remprop(getv(fourier!-name!*, i),'fourier!-angle)
>>;
fourier!-name!* := mkvect 7;

%% For non Cambridge LISP add
smacro procedure putv!.unsafe(x,y,z); putv(x,y,z);
smacro procedure getv!.unsafe(x,y); getv(x,y);

%% Data abtraction says that we should define macros for access to
%% the parts of the Fourier structure

smacro procedure fs!:set!-next(f,p); putv!.unsafe(f, 3, p);

smacro procedure fs!:next(f); getv!.unsafe(f,3);

smacro procedure fs!:set!-coeff(f,p); putv!.unsafe(f, 0, p);

smacro procedure fs!:coeff(f); getv!.unsafe(f, 0);

smacro procedure fs!:set!-fn(f,p); putv!.unsafe(f, 1, p);

smacro procedure fs!:fn(f); getv!.unsafe(f, 1);

smacro procedure fs!:set!-angle(f,p); putv!.unsafe(f, 2, p);

smacro procedure fs!:angle(f); getv!.unsafe(f, 2);

%% Some support functions for angle expressions

symbolic procedure fs!:make!-nullangle();
begin scalar ans;
    ans := mkvect 7;
    for i:=0:7 do putv!.unsafe(ans,i,0);
    return ans;
end;

symbolic procedure fs!:null!-angle!: u;
  fs!:null!-angle cdr u;

symbolic procedure fs!:null!-angle u;
begin scalar ans, i, x;
    x := fs!:angle u;
    ans := t;
    i := 0;
top:
    if not(getv!.unsafe(x,i)=0) then return nil;
    i := i+1;
    if (i<8) then go to top;
    return ans;
end;

endmodule;


module fourdom; % Domain definitions for angles and fourier series

% Author: John Fitch 1991.

global '(domainlist!*);

domainlist!*:=union('(!:fs!:),domainlist!*);

put('fourier,'tag,'!:fs!:);
put('!:fs!:,'dname,'fourier);
flag('(!:fs!:),'field); %% Should be ring really
put('!:fs!:,'i2d,'i2fourier);
put('!:fs!:,'minusp,'fs!:minusp!:);
put('!:fs!:,'plus,'fs!:plus!:);
put('!:fs!:,'times,'fs!:times!:);
put('!:fs!:, 'expt,'fs!:expt!:);
put('!:fs!:,'difference,'fs!:difference!:);
put('!:fs!:,'quotient,'fs!:quotient!:);
put('!:fs!:, 'divide, 'fs!:divide!:);
put('!:fs!:, 'gcd, 'fs!:gcd!:);
put('!:fs!:,'zerop,'fs!:zerop!:);
put('!:fs!:,'onep,'fs!:onep!:);
put('!:fs!:,'prepfn,'fs!:prepfn!:);
put('!:fs!:,'specprn,'fs!:prin!:);
put('!:fs!:,'prifn,'fs!:prin!:);
put('!:fs!:,'intequivfn,'fs!:intequiv!:);
flag('(!:fs!:),'ratmode);
% conversion functions

put('!:fs!:,'!:mod!:,mkdmoderr('!:fs!:,'!:mod!:));
% put('!:fs!:,'!:gi!:,mkdmoderr('!:fs!:,'!:gi!:));
% put('!:fs!:,'!:rn!:,mkdmoderr('!:fs!:,'!:rn!:));
put('!:rn!:,'!:fs!:,'!*d2fourier);
put('!:ft!:,'!:fs!:,'cdr);
put('!:gi!:,'!:fs!:,'!*d2fourier);
put('!:gf!:,'!:fs!:,'!*d2fourier);

put('expt, '!:fs!:, 'fs!:expt!:);

% Conversion functions

symbolic procedure i2fourier u;
  if dmode!*='!:fs!: then !*d2fourier u else u;

symbolic procedure !*d2fourier u;
if null u then nil else
begin scalar fourier;
      fourier:=mkvect 3;
      fs!:set!-coeff(fourier,(u . 1));
      fs!:set!-fn(fourier,'cos);
      fs!:set!-angle(fourier,fs!:make!-nullangle());
      fs!:set!-next(fourier,nil);
     return get('fourier,'tag) . fourier
end;

symbolic procedure !*sq2fourier u;
if null car u then nil else
begin scalar fourier;
      fourier:=mkvect 3;
      fs!:set!-coeff(fourier,u);
      fs!:set!-fn(fourier,'cos);
      fs!:set!-angle(fourier,fs!:make!-nullangle());
      fs!:set!-next(fourier,nil);
     return get('fourier,'tag) . fourier
end;

symbolic procedure fs!:minusp!:(x); fs!:minusp cdr x;

symbolic procedure fs!:minusp x;
if null x then nil else
   if null fs!:next x then minusf car fs!:coeff x
   else fs!:minusp fs!:next x;

%% Basic algebraic operations

symbolic procedure fs!:times!:(x,y);
% This function seems to be called with numeric values as well
   if null x then nil else if null y then nil
   else if numberp y
    then get('fourier,'tag) . fs!:timescoeff(y ./ 1, cdr x)
   else if numberp x
    then get('fourier,'tag) . fs!:timescoeff(x ./ 1, cdr y)
   else if not eqcar(x, get('fourier,'tag)) then
        get('fourier,'tag) . fs!:timescoeff(x,cdr y)
   else if not eqcar(y, get('fourier,'tag)) then
        get('fourier,'tag) . fs!:timescoeff(y,cdr x)
   else get('fourier,'tag) . fs!:times(cdr x, cdr y);

symbolic procedure fs!:timescoeff(x, y);
if null y then nil
   else begin scalar ans, coeff;
      coeff := multsq(x,fs!:coeff y);
      if coeff = '(nil . 1) then <<
        print "zero in times";
        return fs!:timescoeff(x, fs!:next y) >>;
      ans := mkvect 3;
      fs!:set!-coeff(ans,coeff);
      fs!:set!-fn(ans,fs!:fn y);
      fs!:set!-angle(ans,fs!:angle y);
      fs!:set!-next(ans, fs!:timescoeff(x, fs!:next y));
      return ans
   end;

symbolic procedure fs!:times(x,y);
if null x then nil else if null y then nil else
begin scalar ans;
        ans := fs!:timesterm(x, y);
        return fs!:plus(ans, fs!:times(fs!:next  x, y));
end;

symbolic procedure fs!:timesterm(x,y);
% Treat x as a term and y as a tree
if null y then nil else if null x then nil else
begin scalar ans;
        ans := fs!:timestermterm(x,y);
        return fs!:plus(ans, fs!:timesterm(x, fs!:next y));
end;

symbolic procedure fs!:timestermterm(x,y);
% x and y are terms.  Generate the two answer terms.
begin scalar sum, diff, ans, xv, yv, coeff;
        sum := mkvect 7;
        xv := fs!:angle x;
        yv := fs!:angle y;
        for i:=0:7 do putv!.unsafe(sum,i,
                                 getv!.unsafe(xv,i)+getv!.unsafe(yv,i));
        diff := mkvect 7;
        for i:=0:7 do putv!.unsafe(diff,i,
                                 getv!.unsafe(xv,i)-getv!.unsafe(yv,i));
        coeff := multsq(fs!:coeff x, fs!:coeff y);
        coeff := multsq(coeff, '(1 . 2));
        if null car coeff then return nil;
        if fs!:fn x = 'sin then
            if fs!:fn y = 'sin then
                % sin x*sin y => [-cos(x+y)+cos(x-y)]/2
                return fs!:plus(make!-term('cos, sum, negsq coeff),
                                make!-term('cos,diff, coeff))
            else % fs!:fn y = 'cos
                % sin x * cos y => [sin(x+y)+sin(x-y)]/2
                return fs!:plus(make!-term('sin, sum, coeff),
                                make!-term('sin, diff,coeff))
        else % fs!:fn x='cos
            if fs!:fn y = 'sin then
                % cos x*sin y => [sin(x+y)-sin(x-y)]/2
                return fs!:plus(make!-term('sin, sum, coeff),
                                make!-term('sin,diff, negsq coeff))
            else % fs!:fn y = 'cos
                % cos x * cos y => [cos(x+y)+cos(x-y)]/2
                return fs!:plus(make!-term('cos, sum, coeff),
                                make!-term('cos, diff,coeff))

end;

symbolic procedure fs!:expt!:(x,n);
begin scalar ans, xx;
    ans := cdr !*d2fourier 1;
    x := cdr x;
    for i:=1:n do ans := fs!:times(ans,x);
    return get('fourier,'tag) . ans;
end;

symbolic procedure make!-term(fn, ang, coeff);
begin scalar fourier, sign, i;
      sign := 0;
      i:=0;
top:  if getv!.unsafe(ang,i)<0 then sign := -1
      else if getv!.unsafe(ang,i)>0 then sign := 1
      else if i=7 then <<
        if fn ='sin then return nil >>
      else << i := i #+ 1; goto top >>;
      fourier:=mkvect 3;
      if sign = 1 or fn = 'cos then fs!:set!-coeff(fourier,coeff)
      else fs!:set!-coeff(fourier, multsq('(-1 . 1), coeff));
      fs!:set!-fn(fourier,fn);
      if sign = -1 then << sign := mkvect 7;
        for i:=0:7 do putv!.unsafe(sign,i,-getv!.unsafe(ang,i));
        ang := sign
      >>;
      fs!:set!-angle(fourier,ang);
      fs!:set!-next(fourier,nil);
     return fourier
end;

symbolic procedure fs!:quotient!:(x,y);
if numberp y then fs!:times!:(x, !*sq2fourier (1 ./ y))
else rerror(fourier, 98, "Unimplemented");

symbolic procedure fs!:divide!:(x,y);
rerror(fourier, 98, "Unimplemented");

symbolic procedure fs!:gcd!:(x,y);
rerror(fourier, 98, "Unimplemented");

symbolic procedure fs!:difference!:(x,y);
   fs!:plus!:(x, fs!:negate!: y);

symbolic procedure fs!:negate!: x;
  get('fourier,'tag) . fs!:negate cdr x;

symbolic procedure fs!:negate x;
   if null x then nil
   else begin scalar ans;
      ans := mkvect 3;
      fs!:set!-coeff(ans,negsq fs!:coeff x);
      fs!:set!-fn(ans,fs!:fn x);
      fs!:set!-angle(ans,fs!:angle x);
      fs!:set!-next(ans, fs!:negate fs!:next x);
      return ans
   end;

symbolic procedure fs!:zerop!:(u);
  null u or
  (not numberp u and
   null cdr u or
   (null fs!:next cdr u and
   ((numberp v and zerop v) where v=fs!:coeff cdr u)));

symbolic procedure fs!:onep!:(u); fs!:onep cdr u;

symbolic procedure fs!:onep u;
  null fs!:next u and
  onep fs!:coeff u and fs!:null!-angle u and fs!:fn(u) = 'cos;

symbolic procedure fs!:prepfn!:(x); x;

symbolic procedure simpfs u; u;

put('!:fs!:,'simpfn,'simpfs);

%% PRINTING FUNCTIONS

%% We have all the usual problems of unit coefficients, and zero angles

smacro procedure zeroterm x; fs!:coeff x = '(nil  . 1);

symbolic procedure fs!:prin!:(x);
  << prin2!* "["; fs!:prin cdr x; prin2!* "]" >>;

symbolic procedure fs!:prin x;
   if null x then prin2!* " 0 " else <<
   while x do <<
     fs!:prin1 x;
     x := fs!:next x;
     if x then prin2!* " + "
   >>
>>;

symbolic procedure fs!:prin1 x;
begin scalar first, u, v;
   first := t;
   if not(fs!:coeff x = '(1 . 1)) then <<
      prin2!* "("; sqprint fs!:coeff x;
      prin2!* ")" >>;
   if not(fs!:null!-angle x) then <<
     prin2!* fs!:fn x;
     prin2!* "[";
     u := fs!:angle x;
     for i:=0:7 do
         if not((v := getv!.unsafe(u,i)) = 0) then <<
            if v<0 then << first := t; prin2!* "-"; v := -v >>;
            if not first then prin2!* "+";
            if not(v=1) then prin2!* v;
            first := nil;
            prin2!* getv!.unsafe(fourier!-name!*, i)
     >>;
     prin2!* "]"
  >>
  else if fs!:coeff x = '(1 . 1) then prin2!* "1"
end;

symbolic procedure fs!:intequiv!:(u);
   null fs!:next x and
   fs!:null!-angle x and
   fs!:fn(x) = 'cos and
   fixp car fs!:coeff x and
   cdr fs!:coeff x = 1
        where x = cdr u;

endmodule;


module fourplus;

%% ARITHMETIC

%% Addition of Fourier expressionsis really a merge operation

symbolic procedure fs!:plus!:(x,y);
 %% Top level addition of two fourier series
    if fs!:zerop!: y then x
    else if fs!:zerop!: x then y
    else get('fourier,'tag)
            . fs!:plus(copy!-tree cdr x, copy!-tree cdr y);

% I cannot rely on the CAMAL selective copy, so I take the coward's way
% out.
symbolic procedure copy!-tree x;
   if null x then nil
   else begin scalar ans;
      ans := mkvect 3;
      fs!:set!-coeff(ans,fs!:coeff x);
      fs!:set!-fn(ans,fs!:fn x);
      fs!:set!-angle(ans,fs!:angle x);
      fs!:set!-next(ans, copy!-tree fs!:next x);
      return ans
   end;

symbolic procedure fs!:plus(x, y);
  %% The real addition.  x is a new tree to which y must be merged.
  if null y then x
  else if null x then y
  else if fs!:fn x = fs!:fn y
     and angles!-equal(fs!:angle x, fs!:angle y) then
        begin scalar coef;
            coef := addsq(fs!:coeff x, fs!:coeff y);
        % Really I should deal with the zero case here
            if null car coef
              then return fs!:plus(fs!:next x, fs!:next y);
            fs!:set!-coeff(x, coef);
            fs!:set!-next(x, fs!:plus(fs!:next x, fs!:next y));
            return x
        end
    else if fs!:angle!-order(x, y) then <<
          fs!:set!-next(x, fs!:plus(fs!:next x, y));
          x >>
    else <<
          fs!:set!-next(y, fs!:plus(fs!:next y,x));
          y >>;

symbolic procedure angles!-equal(x, y);
% Are all angles the same?
begin scalar i;
    i := 0;
top:
    if not(getv!.unsafe(x,i)=getv!.unsafe(y,i)) then return nil;
    i := i+1;
    if (i<8) then go to top;
    return t;
end;

symbolic procedure fs!:angle!-order(x, y);
% Ordering function for angle expressions, also taking account of angle.
begin scalar ans, i, xx, yy;
    i := 0;
    xx := fs!:angle x;
    yy := fs!:angle y;
top:
    ans := (getv!.unsafe(xx,i)-getv!.unsafe(yy,i));
    if not(ans = 0) then return ans>0;
    i := i+1;
    if (i<8) then go to top;
    return
      if fs!:fn x = fs!:fn y then nil
       else if fs!:fn x = 'sin then nil else t;
end;

endmodule;


module makefour;

%% User interface; all rather iffy at present

symbolic procedure harmonicp u; get(u, 'fourier!-angle);

symbolic procedure harmonic u;
<<
    for each x in u do if not(get(x, 'fourier!-angle)) then <<
        if (next!-angle!* > 7) then rerror(fourier,3,"Too many angles");
        put(x, 'fourier!-angle, next!-angle!*);
        putv!.unsafe(fourier!-name!*, next!-angle!*, x);
        next!-angle!* := next!-angle!* #+ 1;
      >>
>>;

put('harmonic, 'stat, 'rlis);

symbolic procedure simpfourier u;
%% Handle the form fourier(...)  with treating sin and cos as special
begin
  if not(length u = 1) then
        rerror(fourier,1,"Argument should be single expression");
  return simpfourier1 prepsq simp!* car u;;
end;

symbolic procedure simpfourier1 u;
begin scalar ff;
  if atom u then <<
        if harmonicp u
          then rerror(fourier,2,"Secular angle not allowed");
        return (!*sq2fourier simp u) . 1;
  >>
  else if eqcar(u, '!:fs!:) then return u
  else if (ff := get(car u, 'simpfour)) then return apply1(ff, cdr u)
  else <<
    rerror(fourier,4,"Unknown function" . car u);
    return (!*sq2fourier u) . 1;
  >>
end;

put('fourier, 'simpfn, 'simpfourier);

symbolic procedure simpfouriersin u;
% Creation of a simple angle expression and function
begin scalar ans, vv;
  u := car u;
  if atom u then
        if harmonicp u then <<
              ans:=mkvect 3;
              fs!:set!-coeff(ans,(1 . 1));
              fs!:set!-fn(ans,'sin);
              vv := mkvect 7;
              for i:=0:7 do putv!.unsafe(vv,i,0);
              putv!.unsafe(vv, get(u, 'fourier!-angle), 1);
              fs!:set!-angle(ans,vv);
              fs!:set!-next(ans,nil);
              return (get('fourier,'tag) . ans) . 1 >>
        else return !*sq2fourier(simp list('sin, u)) . 1;
  if angle!-expression!-p u then <<
      ans:=mkvect 3;
      fs!:set!-coeff(ans,(1 . 1));
      fs!:set!-fn(ans,'sin);
      vv := mkvect 7;
      for i:=0:7 do putv!.unsafe(vv,i,0);
      compile!-angle!-expression(u,vv);
      fs!:set!-angle(ans,vv);
      fs!:set!-next(ans,nil);
      return (get('fourier,'tag) . ans) . 1 >>;
  rerror(fourier,99,"Not finished yet");
end;

put('sin, 'simpfour, 'simpfouriersin);

symbolic procedure simpfouriercos u;
% Creation of a simple angle expression and function
begin scalar ans, vv;
  u := car u;
  if atom u then
        if harmonicp u then <<
              ans:=mkvect 3;
              fs!:set!-coeff(ans,(1 . 1));
              fs!:set!-fn(ans,'cos);
              vv := mkvect 7;
              for i:=0:7 do putv!.unsafe(vv,i,0);
              putv!.unsafe(vv, get(u, 'fourier!-angle), 1);
              fs!:set!-angle(ans,vv);
              fs!:set!-next(ans,nil);
              return (get('fourier,'tag) . ans) . 1 >>
        else return !*sq2fourier(simp list('cos, u)) . 1;
  if angle!-expression!-p u then <<
      ans:=mkvect 3;
      fs!:set!-coeff(ans,(1 . 1));
      fs!:set!-fn(ans,'cos);
      vv := mkvect 7;
      for i:=0:7 do putv!.unsafe(vv,i,0);
      compile!-angle!-expression(u,vv);
      fs!:set!-angle(ans,vv);
      fs!:set!-next(ans,nil);
      return (get('fourier,'tag) . ans) . 1 >>;
  rerror(fourier,99,"Not finished yet");
end;

put('cos, 'simpfour, 'simpfouriercos);

%% Is the prefix expression u a sum of angles??

symbolic procedure angle!-expression!-p u;
if atom u and harmonicp u then t
else if eqcar(u,'plus) or eqcar(u,'difference) then
    angle!-expression!-p cadr u and angle!-expression!-p caddr u
else if eqcar(u,'minus) then angle!-expression!-p cadr u
else if eqcar(u,'times) then
  if numberp cadr u then angle!-expression!-p caddr u
  else angle!-expression!-p cadr u and numberp caddr u
else nil;

%% We know that u is a sum of angles, so create vector of coefficients.

symbolic procedure compile!-angle!-expression(u,v);
if atom u and harmonicp u then
    putv!.unsafe(v, get(u, 'fourier!-angle),
                 1+getv!.unsafe(v, get(u, 'fourier!-angle)))
else if eqcar(u,'plus) then <<
        u := cdr u;
        while u do <<
            compile!-angle!-expression(car u,v);
            u := cdr u
        >>;
        v  >>
else if eqcar(u,'difference) then begin scalar vv;
    compile!-angle!-expression(cadr u,v);
    vv := mkvect 7;
    for i:=0:7 do putv!.unsafe(vv,i,0);
    compile!-angle!-expression(caddr u,vv);
    for i:=0:7 do putv!.unsafe(v,i,getv!.unsafe(v,i)
                                   - getv!.unsafe(vv,i));
    return v
  end
else if eqcar(u,'minus) then
  begin scalar vv;
        vv := mkvect 7;
        for i:=0:7 do putv!.unsafe(vv,i,0);
        compile!-angle!-expression(cadr u,vv);
        for i:=0:7 do putv!.unsafe(v,i,getv!.unsafe(v,i)
                                       - getv!.unsafe(vv,i));
        return v;
  end
else if eqcar(u,'times) then
  if numberp cadr u then begin scalar vv;
      vv := mkvect 7;
      for i:=0:7 do putv!.unsafe(vv,i,0);
      compile!-angle!-expression(caddr u,vv);
      for i:=0:7 do putv!.unsafe(v, i,
                        cadr u*getv!.unsafe(vv, i) + getv!.unsafe(v,i))
  end
  else begin scalar vv;
      vv := mkvect 7;
      for i:=0:7 do putv!.unsafe(vv,i,0);
      compile!-angle!-expression(cadr u,vv);
      for i:=0:7 do putv!.unsafe(v, i,
                      caddr u * getv!.unsafe(vv, i) + getv!.unsafe(v,i))
  end
else nil;

symbolic procedure simpfouriertimes(u);
begin scalar z;
     z := car simpfourier1 car u;
     u := cdr u;
  a: if null u then return z ./ 1;
     z := fs!:times!:(car simpfourier1 car u,z);
     u := cdr u;
     go to a
   end;

put('times, 'simpfour, 'simpfouriertimes);

symbolic procedure simpfourierexpt(u);
  fs!:expt!:(car simpfourier1 car u, cadr u) . 1;

put('expt, 'simpfour, 'simpfourierexpt);

symbolic procedure simpfourierplus(u);
begin scalar z;
     z := car simpfourier1 car u;
     u := cdr u;
  a: if null u then return z ./ 1;
     z := fs!:plus!:(car simpfourier1 car u,z);
     u := cdr u;
     go to a
   end;

put('plus, 'simpfour, 'simpfourierplus);

symbolic procedure simpfourierdifference(u);
  fs!:difference!:(car simpfourier1 car u, car simpfourier1 cadr u)
     ./ 1;

put('difference, 'simpfour, 'simpfourierdifference);

symbolic procedure simpfourierminus(u);
  fs!:negate!:(car simpfourier1 car u) . 1;

put('minus, 'simpfour, 'simpfourierminus);

symbolic procedure simpfourierquot(u);
begin scalar v;
  v := simp!* cadr u;
  v := cdr v . car v;
  return fs!:times!:(car simpfourier1 car u, !*sq2fourier v) ./ 1
end;

put('quotient, 'simpfour, 'simpfourierquot);

symbolic procedure simphsin u;
begin
  if not(length u = 1) then
        rerror(fourier,5,"Argument should be single expression");
  return simpfouriersin list(u := prepsq simp!* car u)
end;

put('hsin, 'simpfn, 'simphsin);

symbolic procedure simphcos u;
begin
  if not(length u = 1) then
        rerror(fourier,6,"Argument should be single expression");
  return simpfouriercos list(u := prepsq simp!* car u)
end;

put('hcos, 'simpfn, 'simphcos);

endmodule;


module hsub;

%% Harmonic substitution: the CAMAL HSUB operation, as well as other
%% substitutions.

fluid '(!*trharm);
switch trham;

symbolic procedure hsub1(x,u,v,a,n);
%% Substitute v+A for u in x to order n
begin scalar ans, c, tmp, fs!:zero!-generated;
%%    fs!:zero!-generated := 0;
    ans := fs!:subang(x, u, v);
%    c := ensure!-fourier A;
    c := car a;
    if c then c := cdr c;
    a := c;
    if !*trham
      then << print "A"; if null a then print 0 else fs!:prin a >>;
    for i:=1:n do <<
        if !*trham then << print "i="; print i >>;
        x := hdiff(x, u);
        if !*trham then << prin2!* "df(x,u,i)="; fs!:prin x; terpri!* t;
                prin2!* "A^i ="; fs!:prin c; terpri!* t >>;
        c := fs!:times(cdr !*sq2fourier (1 ./ i), c);
        if !*trham
          then << prin2!* "A^i/fact(i) ="; fs!:prin c; terpri!* t>>;
        tmp := fs!:times(fs!:subang(x, u, v), c);
        if !*trham then <<
            prin2!* "f'(0)*A^i/fact i = "; fs!:prin tmp; terpri!* t>>;
        ans := fs!:plus(ans, tmp);
        if !*trham
          then << prin2!* "partial sum ="; fs!:prin ans; terpri!* t>>;
        if not(i=n) then c := fs!:times(c,a);
    >>;
    return ans
end;

symbolic procedure fs!:subang(x, u, v);
if null x then nil
else begin scalar vv, n;
    vv := mkvect 7;
    n := getv!.unsafe(fs!:angle x, u);
    for i:=0:7 do if i = u then putv!.unsafe(vv, i, n*getv!.unsafe(v,i))
        else putv!.unsafe(vv, i,
                getv!.unsafe(fs!:angle x,i) + n*getv!.unsafe(v,i));
    return fs!:plus(fs!:subang(fs!:next x, u, v),
                    make!-term(fs!:fn x, vv, fs!:coeff x));
end;

symbolic procedure fs!:sub(x,u);
if null x then nil else
begin scalar ans;
    ans := aeval prepsq fs!:coeff x;
    if not fixp ans then ans := subsq(cadr ans, u)
    else ans := fs!:coeff x;
    if eqcar(numr ans, '!:fs!:) then ans := cdar ans
        else ans := cdr !*sq2fourier ans;
    ans := fs!:times(make!-term(fs!:fn x, fs!:angle x, 1 ./ 1), ans);
    return fs!:plus(fs!:sub(fs!:next x, u), ans);
end;

symbolic procedure simphsub uu;
begin scalar x, u, v, vv, a, n, dmode!*;
    dmode!* := '!:fs!:;
    if (length uu = 5) then <<
        x := car uu; uu := cdr uu;
        u := car uu; uu := cdr uu;
        v := car uu; uu := cdr uu;
        a := car uu; uu := cdr uu;
        n := car uu
    >>
    else if (length uu = 3) then <<
        x := car uu; uu := cdr uu;
        u := car uu; uu := cdr uu;
        v := car uu; uu := cdr uu;
        if not harmonicp u then <<
            a := ( ((get('fourier, 'tag) .
                         fs!:sub(cdar simp x, list(u . v))) ./ 1)
            )  where wtl!*=delasc(u,wtl!*);
            return a;
        >>;
        a := 0;
        n := 0
    >>;
    if not harmonicp u then
        rerror(fourier, 7, "Not an angle in HSUB");
    x := cdar simp x;
    if not angle!-expression!-p v then
        rerror(fourier, 8, "Not an angle expression in HSUB");
    vv := mkvect 7;
    for i:=0:7 do putv!.unsafe(vv,i,0);
    compile!-angle!-expression(v, vv);
    a := simp!* a;
    n := simp!* n;
    if null car n then n := 0 ./ 1
    else if not(fixp car n and cdr n = 1)  then
        rerror(fourier, 9, "Non integer expansion in HSUB");
    n := car n;
    return (get('fourier, 'tag) .
           hsub1(x,get(u,'fourier!-angle),vv,a,n)) ./ 1;
end;

put('hsub, 'simpfn, 'simphsub);

endmodule;


module hdiff;

%% Harmonic differentiation and Integration.

symbolic procedure hdiff(x, u);
if null x then nil
    else fs!:plus(hdiff(fs!:next x,u), hdiffterm(x,u));

symbolic procedure hdiffterm(x, u);
begin scalar n;
   n := getv!.unsafe(fs!:angle x, u);
   if n = 0 then return nil;
   n := multsq( n . 1, fs!:coeff x);
   if fs!:fn x = 'cos then return make!-term('sin, fs!:angle x, negsq n)
   else                    return make!-term('cos, fs!:angle x, n)
end;

symbolic procedure hdiff1(x, u);
if null x then nil
else begin scalar ans, aaa;
        ans := diffsq(fs!:coeff x, u);
        if ans then <<
            aaa := mkvect 3;
            fs!:set!-coeff(aaa, ans);
            fs!:set!-fn(aaa, fs!:fn x);
            fs!:set!-angle(aaa,fs!:angle x);
            fs!:set!-next(aaa, hdiff1(fs!:next x, u));
            return aaa >>
        else return hdiff1(fs!:next x, u)
end;

symbolic procedure simphdiff uu;
begin scalar x, u;
    if not (length uu = 2) then
        rerror(fourier, 10, "Improper number of arguments to HDIFF");
    x := car uu; uu := cdr uu;
    u := car uu;
    x := simp x;
    if not eqcar(car x, '!:fs!:) then x := !*sq2fourier x ./ 1;
    if not harmonicp u then
        return (get('fourier, 'tag) . hdiff1(cdar x, u)) ./ 1;
    x := hdiff(cdar x,get(u,'fourier!-angle));
    if null x then return nil ./ 1;
    return (get('fourier, 'tag) . x) ./ 1
end;

put('hdiff, 'simpfn, 'simphdiff);

symbolic procedure hint(x, u);
if null x then nil
%% Bind fs!:zero!-generated ??
    else fs!:plus(hint(fs!:next x,u), hintterm(x,u));

symbolic procedure hintterm(x, u);
begin scalar n;
   n := getv!.unsafe(fs!:angle x, u);
   if n = 0 then return make!-term(fs!:fn x, fs!:angle x, fs!:coeff x);
   n := multsq( 1 ./ n, fs!:coeff x);
   if fs!:fn x = 'cos then return make!-term('sin, fs!:angle x, n)
   else                    return make!-term('cos, fs!:angle x, negsq n)
end;

symbolic procedure hint1(x , u);
if null x then nil
else begin scalar aaa;
        aaa := mkvect 3;
        fs!:set!-coeff(aaa, simpint list(prepsq fs!:coeff x, u));
        fs!:set!-fn(aaa, fs!:fn x);
        fs!:set!-angle(aaa,fs!:angle x);
        fs!:set!-next(aaa, hint1(fs!:next x, u));
        return aaa
end;

symbolic procedure simphint uu;
begin scalar x, u;
    if not (length uu = 2) then
        rerror(fourier, 11, "Improper number of arguments to HINT");
    x := car uu; uu := cdr uu;
    u := car uu;
    x := simp x;
    if not eqcar(car x, '!:fs!:) then x := !*sq2fourier x ./ 1;
    if not harmonicp u then
        return (get('fourier, 'tag) . hint1(cdar x, u)) ./ 1;
    x := hint(cdar x,get(u,'fourier!-angle));
    if null x then return nil ./ 1;
    return (get('fourier, 'tag) . x) ./ 1
end;

put('hint, 'simpfn, 'simphint);

initdmode 'fourier;

endmodule;


end;
