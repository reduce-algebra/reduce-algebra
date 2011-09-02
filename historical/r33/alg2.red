module opmtch; % Functions that apply basic pattern matching rules.

% Author: Anthony C. Hearn.

% Copyright (c) 1987 The RAND Corporation. All rights reserved.

global '(frlis!* subfg!*);

symbolic procedure emtch u;
   if atom u then u else (lambda x; if x then x else u) opmtch u;

symbolic procedure opmtch u;
   begin scalar x,y,z;
        x := get(car u,'opmtch);
        if null x then return nil
         else if null subfg!* then return nil;  %null(!*sub2 := t);
        z := for each j in cdr u collect emtch j;
    a:  if null x then return nil;
        y := mcharg(z,caar x,car u);
    b:  if null y then go to c
         else if eval subla(car y,cdadar x)
          then return subla(car y,caddar x);
        y := cdr y;
        go to b;
    c:  x := cdr x;
        go to a
   end;

symbolic procedure mcharg(u,v,w);
   %procedure to determine if an argument list matches given template;
   %U is argument list of operator W;
   %V is argument list template being matched against;
   %if there is no match, value is NIL,
   %otherwise a list of lists of free variable pairings;
   if null u and null v then list nil
    else begin integer m,n;
        m := length u;
        n := length v;
        if flagp(w,'nary) and m>2
          then if m<6 and flagp(w,'symmetric)
                             then return mchcomb(u,v,w)
                else if n=2 then <<u := cdr mkbin(w,u); m := 2>>
                else return nil;   %we cannot handle this case;
        return if m neq n then nil
                else if flagp(w,'symmetric) then mchsarg(u,v,w)
                else if mtp v then list pair(v,u)
                else mcharg2(u,v,list nil,w)
   end;

symbolic procedure mchcomb(u,v,op);
   begin integer n;
      n := length u - length v +1;
      if n<1 then return nil
       else if n=1 then return mchsarg(u,v,op)
       else if not smemqlp(frlis!*,v) then return nil;
      return for each x in comb(u,n) join
        mchsarg((op . x) . setdiff(u,x),v,op)
   end;

symbolic procedure comb(u,n);
   %value is list of all combinations of N elements from the list U;
   begin scalar v; integer m;
        if n=0 then return list nil
         else if (m:=length u-n)<0 then return nil
         else for i := 1:m do
          <<v := nconc!*(v,mapcons(comb(cdr u,n-1),car u));
            u := cdr u>>;
        return u . v
   end;

symbolic procedure mcharg2(u,v,w,x);
   %matches compatible list U of operator X against template V.
   begin scalar y;
        if null u then return w;
        y := mchk(car u,car v);
        u := cdr u;
        v := cdr v;
        return for each j in y
           join mcharg2(u,updtemplate(j,v,x),msappend(w,j),x)
   end;

symbolic procedure msappend(u,v);
   % Mappend u and v with substitution.
   for each j in u collect append(v,sublis(v,j));

symbolic procedure updtemplate(u,v,w);
   begin scalar x,y;
      return for each j in v collect
        if (x := subla(u,j)) = j then j
         else if (y := reval!-without(x,w)) neq x then y
         else x
   end;

symbolic procedure reval!-without(u,v);
   % Evaluate U without rules for operator V.  This avoids infinite
   % recursion with statements like
   % for all a,b let kp(dx a,kp(dx a,dx b)) = 0; kp(dx 1,dx 2);
   begin scalar x;
      x := get(v,'opmtch);
      remprop(v,'opmtch);
      u := errorset(list('reval,mkquote u),t,t);
      put(v,'opmtch,x);
      if errorp u then error1() else return car u
   end;

symbolic procedure mchk(u,v);
   if u=v then list nil
    else if atom v
           then if v memq frlis!* then list list (v . u) else nil
    else if atom u      %special check for negative number match;
     then if numberp u and u<0 then mchk(list('minus,-u),v)
           else nil
    else if car u eq car v then mcharg(cdr u,cdr v,car u)
    else nil;

symbolic procedure mkbin(u,v);
   if null cddr v then u . v else list(u,car v,mkbin(u,cdr v));

symbolic procedure mtp v;
   null v or (car v memq frlis!* and not car v member cdr v
       and mtp cdr v);

symbolic procedure mchsarg(u,v,w);
   reversip!* if mtp v
     then for each j in permutations v collect pair(j,u)
    else for each j in permutations u join mcharg2(j,v,list nil,w);

symbolic procedure permutations u;
   if null u then list u
    else for each j in u join mapcons(permutations delete(j,u),j);

flagop antisymmetric,symmetric;

flag ('(plus times cons),'symmetric);

endmodule;


module prep; %Functions for converting canonical forms into prefix forms

% Author: Anthony C. Hearn.

% Copyright (c) 1987 The RAND Corporation. All rights reserved.

fluid '(!*intstr);

symbolic procedure prepsqxx u;
   % This is a top level conversion function.  It is not clear if we
   % need prepsqxx, prepsqx, prepsq!* and prepsq, but we keep them all
   % for the time being.
   negnumberchk prepsqx u;

symbolic procedure negnumberchk u;
   if eqcar(u,'minus) and numberp cadr u then - cadr u else u;

symbolic procedure prepsqx u;
   if !*intstr then prepsq!* u else prepsq u;

symbolic procedure prepsq u;
   if null numr u then 0 else sqform(u,function prepf);

symbolic procedure sqform(u,v);
   (lambda (x,y); if y=1 then x else list('quotient,x,y))
      (apply1(v,numr u),apply1(v,denr u));

symbolic procedure prepf u;
   replus prepf1(u,nil);

symbolic procedure prepf1(u,v);
   if null u then nil
    else if domainp u then list retimes(prepd u . exchk v)
    else nconc!*(prepf1(lc u,if mvar u eq 'k!* then v else lpow u . v),
                 prepf1(red u,v));

symbolic procedure prepd u;
   if atom u then if u<0 then list('minus,-u) else u
    else if apply1(get(car u,'minusp),u)
%    then list('minus,prepd1 !:minus u)
     then (if null x then 0 else list('minus,x))
          where x=prepd1 !:minus u
%   else if !:onep u then 1
    else apply1(get(car u,'prepfn),u);

symbolic procedure prepd1 u;
   if atom u then u else apply1(get(car u,'prepfn),u);

symbolic procedure exchk u; exchk1(u,nil,nil,nil);

symbolic procedure exchk1(u,v,w,x);
   % checks forms for kernels in EXPT. U is list of powers.  V is used
   % to build up the final answer. W is an association list of
   % previous non-constant (non foldable) EXPT's, X is an association
   % list of constant (foldable) EXPT arguments.
   if null u then exchk2(append(x,w),v)
    else if eqcar(caar u,'expt)
     then begin scalar y,z;
            y := simpexpon list('times,cdar u,caddar car u);
            if numberp cadaar u   % constant argument
              then <<z := assoc2(y,x);
                     if z then rplaca(z,car z*cadaar u) 
                      else x := (cadaar u . y) . x>>
             else <<z := assoc(cadaar u,w);
                    if z then rplacd(z,addsq(y,cdr z))
                     else w := (cadaar u . y) . w>>;
            return exchk1(cdr u,v,w,x)
        end
    else if cdar u=1 then exchk1(cdr u,sqchk caar u . v,w,x)
    else exchk1(cdr u,list('expt,sqchk caar u,cdar u) . v,w,x);

symbolic procedure exchk2(u,v);
   if null u then v
    else exchk2(cdr u,
                ((if eqcar(x,'quotient) and caddr x = 2
                   then if cadr x = 1 then list('sqrt,caar u)
                         else list('expt,list('sqrt,caar u),cadr x)
                  else if x=0.5 then list('sqrt,caar u)
                  else if x=1 then caar u
                  else list('expt,caar u,x)) where x = prepsqx cdar u)
                . v);

symbolic procedure assoc2(u,v);
   % Finds key U in second position of terms of V, or returns NIL.
   if null v then nil
    else if u = cdar v then car v
    else assoc2(u,cdr v);

symbolic procedure replus u;
   if atom u then u else if null cdr u then car u else 'plus . u;

symbolic procedure retimes u;
   % U is a list of prefix expressions. Value is prefix form for the
   % product of these;
   begin scalar bool,x;
      for each j in u do
         <<if j=1 then nil     % ONEP
            else if eqcar(j,'minus)
             then <<bool := not bool;
                    if cadr j neq 1 then x := cadr j . x>>     % ONEP
            else if numberp j and minusp j
             then <<bool := not bool;
                    if j neq -1 then x := (-j) . x>>
            else x := j . x>>;
        x := if null x then 1
                else if cdr x then 'times . reverse x else car x;
        return if bool then list('minus,x) else x
   end;

symbolic procedure sqchk u;
   if atom u then u
    else if car u eq '!*sq then prepsq cadr u
    else if car u eq 'expt and caddr u=1 then cadr u
    else if atom car u then u else prepf u;

endmodule;


module sqprint;   % Routines for printing standard forms and quotients.

% Author: Anthony C. Hearn.

% Copyright (c) 1987 The RAND Corporation. All rights reserved.

global '(!*eraise
         !*fort
         !*horner
         !*nat
         !*nero
         !*outp
         !*pri
         orig!*
         posn!*
         wtl!*
         ycoord!*
         ymax!*
         ymin!*);

deflist ('((!*sq !*sqprint)),'prifn);

symbolic procedure !*sqprint u; sqprint cadr u;

symbolic procedure printsq u;
   begin terpri!* t; sqprint u; terpri!* u; return u end;

symbolic procedure sqprint u;
   %mathprints the standard quotient U;
   begin scalar flg,z;
        z := orig!*;
        if !*nat and posn!*<20 then orig!* := posn!*;
        if !*pri or wtl!* then go to c
         else if cdr u neq 1 then go to b
         else xprinf(car u,nil,nil);
    a:  return (orig!* := z);
    b:  flg := not domainp numr u and red numr u;
        if flg then prin2!* "(";
        xprinf(car u,nil,nil);
        if flg then prin2!* ")";
        prin2!* " / ";
        flg := not domainp denr u and red denr u;
        if flg then prin2!* "(";
        xprinf(cdr u,nil,nil);
        if flg then prin2!* ")";
        go to a;
    c:  if null !*horner
           or errorp(!*outp:=errorset(list('horner,mkquote u),nil,nil))
          then !*outp := prepsq!* u
         else !*outp := prepsq car !*outp;
        maprin !*outp;
        go to a
   end;

symbolic procedure printsf u;
   begin prinsf u; terpri!* nil; return u end;

symbolic procedure prinsf u;
   if null u then prin2!* 0 else xprinf(u,nil,nil);

symbolic procedure xprinf(u,v,w);
   %U is a standard form.
   %V is a flag which is true if a term has preceded current form.
   %W is a flag which is true if form is part of a standard term;
   %Procedure prints the form and returns NIL;
   begin
    a:  if null u then return nil
         else if domainp u then return xprid(u,v,w);
        xprint(lt u,v);
        u := red u;
        v := t;
        go to a
   end;

symbolic procedure xprid(u,v,w);
   %U is a domain element.
   %V is a flag which is true if a term has preceded element.
   %W is a flag which is true if U is part of a standard term.
   %Procedure prints element and returns NIL;
   begin
        if minusf u then <<oprin 'minus; u := !:minus u>>
         else if v then oprin 'plus;
        if not w or u neq 1
          then if atom u then prin2!* u else maprin u
   end;

symbolic procedure xprint(u,v);
   %U is a standard term.
   %V is a flag which is true if a term has preceded this term.
   %Procedure prints the term and returns NIL;
   begin scalar flg,w;
        flg := not domainp tc u and red tc u;
        if not flg then go to a else if v then oprin 'plus;
        prin2!* "(";
    a:  xprinf(tc u,if flg then nil else v,not flg);
        if flg then prin2!* ")";
        if not atom tc u or not abs tc u=1 then oprin 'times;
        w := tpow u;
        if atom car w then prin2!* car w
         else if not atom caar w or caar w eq '!*sq then go to c
         else if caar w eq 'plus then maprint(car w,100)
         else maprin car w;
    b:  if cdr w=1 then return;
        if !*nat and !*eraise
          then <<ycoord!* := ycoord!*+1;
                 if ycoord!*>ymax!* then ymax!* := ycoord!*>>
         else prin2!* get('expt,'prtch);
        prin2!* if numberp cdr w and minusp cdr w then list cdr w 
                 else cdr w;
        if !*nat and !*eraise
          then <<ycoord!* := ycoord!*-1;
                 if ymin!*>ycoord!* then ymin!* := ycoord!*>>;
        return;
    c:  prin2!* "(";
        if not atom caar w then xprinf(car w,nil,nil)
         else sqprint cadar w;
        prin2!* ")";
        go to b
   end;

symbolic procedure varpri(u,v,w);
   begin scalar x;
   %U is expression being printed
   %V is the original form that was evaluated.
   %W is an id that indicates if U is the first, only or last element
   %  in the current set (or NIL otherwise).
    if null u then u := 0; 
    if !*nero and u=0 then return nil;
    v := setvars v;
    if (x := getrtype u) and flagp(x,'sprifn)
      then return if null v then apply1(get(get(x,'tag),'prifn),u)
               else maprin list('setq,car v,u);
    if w memq '(first only) then terpri!* t;
    if !*fort then return fvarpri(u,v,w);
    if v then u := 'setq . aconc(v,u);
    maprin u;
    if null w or w eq 'first then return nil
     else if not !*nat then prin2!* "$";
    terpri!*(not !*nat);
    return nil
   end;

symbolic procedure setvars u;
   if atom u then nil
    else if car u memq '(setel setk)
     then eval cadr u . setvars caddr u
    else if car u eq 'setq then cadr u . setvars caddr u
    else nil;

endmodule;


module mprint; % Basic output package for symbolic expressions.

% Author: Anthony C. Hearn.

% Copyright (c) 1987 The RAND Corporation. All rights reserved.

fluid '(!*list !*ratpri);

global '(!*eraise
         !*fort
         !*nat
         !*nero
         !*outp
         !*period
         !*pri
         !*revpri
         cardno!*
         fortwidth!*
         initl!*
         nat!*!*
         obrkp!*
         orig!*
         pline!*
         posn!*
         spare!*
         varnam!*
         wtl!*
         ycoord!*
         ymax!*
         ymin!*);

switch list,ratpri,revpri;

%Global variables initialized in this section;

% SPARE!* should be set in the system dependent code module.

!*eraise := t;
!*nat := nat!*!* := t;
cardno!*:=20;
fortwidth!* := 70;
obrkp!* := t;
orig!*:=0;
posn!* := 0;
varnam!* := 'ans;
ycoord!* := 0;
ymax!* := 0;
ymin!* := 0;

flag ('(cardno!* fortwidth!*),'share);

initl!* := append('(orig!* pline!*),initl!*);

put('orig!*,'initl,0);

flag('(linelength),'opfn);  %to make it a symbolic operator;

symbolic procedure mathprint l;
   begin terpri!* t; maprin l; terpri!* t end;

symbolic procedure maprin u;
   maprint(u,0);

symbolic procedure maprint(l,p);
   begin scalar x,y;
        if null l then return nil
         else if atom l then go to b
         else if stringp l then return prin2!* l
         else if not atom car l then maprint(car l,p)
%        else if x := get(car l,'specprn)
%         then return apply1(x,if flagp(x,'full) then l else cdr l)
         else if (x := get(car l,'prifn))
                 and not(apply1(x,l) eq 'failed)
          then return l
         else if x := get(car l,'infix) then go to a
         else prin2!* car l;
        prin2!* "(";
        obrkp!* := nil;
        if cdr l then inprint('!*comma!*,0,cdr l);
        obrkp!* := t;
    e:  prin2!* ")";
        return l;
    b:  if numberp l then go to d;
    c:  return prin2!* l;
    d:  if not l<0 or p<get('minus,'infix) then go to c;
        prin2!* "(";
        prin2!* l;
        go to e;
    a:  p := not x>p;
        if not p then go to g;
        y := orig!*;
        prin2!* "(";
        orig!* := if posn!*<18 then posn!* else orig!*+3;
    g:  if car l eq 'expt then exptpri(x,cdr l)
         else inprint(car l,x,cdr l);
        if not p then return l;
        prin2!* ")";
        orig!* := y;
        return l
   end;

symbolic procedure exptpri(p,l);
   % Prints expression in an exponent notation.
   begin scalar !*list,bool,x;
      bool := !*nat and !*eraise;
      if flatsizec car l+flatsizec cadr l
        >(linelength nil-spare!*)-posn!*
    then terpri!* t;   % to avoid breaking exponent over line.
     if bool and null atom car l and idp caar l
         and (x := get(caar l,'prifn))
         and (get(x,'expt) eq 'inbrackets)
       % to avoid mix up of indices and exponents.
       then<<prin2!* "("; maprint(car l,p); prin2!* ")">>
      else maprint(car l,p);
      if bool
    then <<ycoord!* := ycoord!*+1;
           if ycoord!*>ymax!* then ymax!* := ycoord!*>>
       else prin2!* get('expt,'prtch);
      % If you want brackets around exponents, replace 0 by p in next
      % line.
      begin scalar !*ratpri;
     l := cadr l;
     if eqcar(l,'quotient) and eqcar(cadr l,'minus)
       then l := list('minus,list(car l,cadadr l,caddr l))
      else l := negnumberchk l;
     maprint(l,if bool then 0 else p)
    end;
      if bool
    then <<ycoord!* := ycoord!*-1;
           if ymin!*>ycoord!* then ymin!* := ycoord!*>>
   end;

symbolic procedure inprint(op,p,l);
   begin scalar x,y;
        if op eq 'plus and !*revpri then l := reverse l;
           % print sum arguments in reverse order.
        if get(op,'alt) then go to a
         else if op eq 'setq and not atom (x := car reverse l)
            and idp car x and (y := getrtype x)
            and (y := get(get(y,'tag),'setprifn))
           then return apply2(y,car l,x);
         if null atom car l and idp caar l
             and !*nat and (x := get(caar l,'prifn))
             and (get(x,op) eq 'inbrackets)
           % to avoid mix up of indices and exponents.
           then<<prin2!* "("; maprint(car l,p); prin2!* ")">>
          else maprint(car l,p);
    a0: l := cdr l;
    a:  if null l then return nil
         else if atom car l or not(op eq get!*(caar l,'alt))
          then <<oprin op; maprint(negnumberchk car l,p)>>
        % difficult problem of negative numbers needing to be in
        % prefix form for pattern matching.
         else maprint(car l,p);
        go to a0
   end;

symbolic procedure flatsizec u;
   if null u then 0
    else if atom u then lengthc u
    else flatsizec car u + flatsizec cdr u + 1;

symbolic procedure oprin op;
   (lambda x;
         if null x then <<prin2!* " "; prin2!* op; prin2!* " ">>
          else if !*fort then prin2!* x
          else if !*list and obrkp!* and op memq '(plus minus)
           then <<terpri!* t; prin2!* x>>
          else if flagp(op,'spaced)
           then <<prin2!* " "; prin2!* x; prin2!* " ">>
          else prin2!* x)
   get(op,'prtch);

symbolic procedure prin2!* u;
   begin integer m,n;
        if !*fort then return fprin2 u;
        n := lengthc u;
        if n>(linelength nil-spare!*) then go to d;
        m := posn!*+n;
    a:  if m>(linelength nil-spare!*) then go to c
         else if not !*nat then prin2 u
         else pline!* := (((posn!* . m) . ycoord!*) . u) . pline!*;
    b:  return (posn!* := m);
    c:  terpri!* t;
        if (m := posn!*+n)<=(linelength nil-spare!*) then go to a;
    d:  %identifier longer than one line;
        if !*fort then rederr list(u,"too long for FORTRAN");
        %let LISP print the atom;
        terpri!* nil;
        prin2t u;
        m := remainder(n,(linelength nil-spare!*));
        go to b
   end;

symbolic procedure terpri!* u;
   begin integer n;
        if !*fort then return fterpri(u)
         else if not !*nat 
          then <<if u then terpri(); return nil>>
         else if not pline!* then go to b;
        n := ymax!*;
        pline!* := reverse pline!*;
    a:  scprint(pline!*,n);
        terpri();
        if n= ymin!* then go to b;
        n := n-1;
        go to a;
    b:  if u then terpri();
    c:  pline!* := nil;
        posn!* := orig!*;
        ycoord!* := ymax!* := ymin!* := 0
   end;

symbolic procedure scprint(u,n);
   begin scalar m;
        posn!* := 0;
    a:  if null u then return nil
         else if not(cdaar u=n) then go to b
         else if not((m:= caaaar u-posn!*)<0) then spaces m;
        prin2 cdar u;
        posn!* := cdaaar u;
    b:  u := cdr u;
        go to a
   end;

endmodule;


module ratprin;   % Printing standard quotients.

% Author: Eberhard Schruefer.

% Modifications by: Anthony C. Hearn.

fluid '(!*list !*mcd !*ratpri dmode!*);

global '(!*fort !*nat ycoord!* ymin!* ymax!* posn!* orig!* pline!*
         spare!*);

switch ratpri;

!*ratpri := t;   % default value if this module is loaded.

put('quotient,'prifn,'quotpri);

symbolic procedure quotpri u;
   % *mcd is included here since it uses rational domain elements.
   begin scalar dmode;
      if null !*ratpri or null !*nat or !*fort or !*list or null !*mcd
           then return 'failed
       else if flagp(dmode!*,'ratmode)
    then <<dmode := dmode!*; dmode!* := nil>>;
      u := ratfunpri1 u;
      if dmode then dmode!* := dmode;
      return u
   end;

symbolic procedure ratfunpri1 u;
   begin scalar pline,npline,dpline,x,y;
         integer ycoord,ymin,ymax,orig,posn,lenden,lennum,
                 hightnum,hightden,orgnum,orgden,offsnum,ll;
       ll := linelength nil - spare!* - 2;
       if ((x := chk!-printlength(cadr u,orig!*,ll)) eq 'failed)
          or ((y := chk!-printlength(caddr u,orig!*,ll)) eq 'failed)
          then go to doesntfit     %It does also not fit on a new line
        else if x>(ll-posn!*)
                or y>(ll-posn!*) then terpri!* t; %It fits on a new line
       ycoord := ycoord!*;
       ymin   := ymin!*;
       ymax   := ymax!*;
       posn   := posn!*;
       orig   := orig!*;
       pline  := pline!*;
       pline!* := nil;
       ycoord!* := ymin!* := ymax!* := posn!* := orig!* := 0;
       maprin cadr u;
       npline   := pline!*;
       lennum   := posn!*;
       offsnum  := 1 - ymin!*;
       hightnum := ymax!* - ymin!* + 1;
       pline!* := nil;
       ycoord!* := ymin!* := ymax!* := posn!* := orig!* := 0;
       maprin caddr u;
       dpline   := pline!*;
       lenden   := posn!*;
       hightden := ymax!* - ymin!* + 1;
       pline!* := nil;
       if lenden > lennum then
          orgnum := (lenden - lennum)/2
        else
          orgden := (lennum - lenden)/2;
       pline!* := append(update!-pline(orgnum + posn + 1,
                       offsnum + ycoord,npline),
                  append(update!-pline(orgden + posn + 1,
                        ycoord - ymax!* - 1,
                          dpline),pline));
       ymin!* := ycoord - hightden;
       ymax!* := ycoord + hightnum;
       if ymin!* > ymin then ymin!* := ymin;
       if ymax!* < ymax then ymax!* := ymax;
       ycoord!* := ycoord;
       posn!* := posn;
       orig!* := orig;
       for j := 1:(max(lenden,lennum)+2) do prin2!* "-";
       return;
       doesntfit:
            u :=  cdr u;
            maprint(car u,get('quotient,'infix));
            oprin 'quotient;
            maprint(negnumberchk cadr u,get('quotient,'infix))
         end;

symbolic procedure update!-pline(x,y,pline);
   for each j in pline collect
       (((caaar j + x) . (cdaar j + x)) . (cdar j + y)) . cdr j;

symbolic procedure chk!-printlength(u,m,n);
   %This one should better be table driven.
   begin scalar l;
     return
       if atom u then
          if (l := lengthc u + m) > n then 'failed
           else l
        else if car u eq 'expt
           then if null((l := chk!-printlength(cadr u,m,n))
                        eq 'failed) and l<n
                   then chk!-printlength(caddr u,l,n)
                 else 'failed
        else if car u eq 'minus
           then if atom cadr u then
                   if (l := 3 + lengthc cadr u + m) > n
                      then 'failed
                    else l
                 else chk!-printlength(cadr u,m+5,n)
      else if car u eq 'plus
           then begin u := cdr u;
                  if (l := chk!-printlength(car u,m,n))
                      eq 'failed
                     then return 'failed;
                  a: if null cdr(u := cdr u)
                       then
                        return chk!-printlength(
                            if eqcar(car u,'minus)
                               then cadar u else car u,3+l,n);
                     if ((l := chk!-printlength(
                            if eqcar(car u,'minus)
                               then cadar u else car u,3+l,n))
                         eq 'failed)
                       then return 'failed
                      else go to a
                  end
      else if car u eq 'times
           then begin u := cdr u;
                  if (l := chk!-printlength(car u,
                                     m+if eqcar(car u,'plus)
                                           then 2 else 0,n))
                      eq 'failed then return 'failed;
                  a: if null cdr(u := cdr u)
                        then return chk!-printlength(car u,
                                     l+if eqcar(car u,'plus)
                                            then 3 else 1,n);
                     if ((l := chk!-printlength(car u,
                                     l+if eqcar(car u,'plus)
                                            then 3 else 1,n))
                         eq 'failed)
                          then return 'failed
                            else go to a
                    end
      else if car u eq 'quotient
           then begin scalar ld;
                  u := cdr u;
                   if (l := chk!-printlength(car u,m+2,n))
                     eq 'failed then return 'failed
                   else if (ld := chk!-printlength(cadr u,m+2,n))
                     eq 'failed then return 'failed;
                   return max(l,ld)
                end
      else if car u eq 'difference
           then begin u := cdr u;
                  if (l := chk!-printlength(car u,m+3,n))
                      eq 'failed then return 'failed
                   else return chk!-printlength(cadr u,m+l,n)
                 end
      else if get(car u,'klist)
            then begin  l := lengthc car u+2;
                  u := cdr u;
                  if (l := chk!-printlength(car u,m+l,n))
                      eq 'failed
                     then return 'failed
                   else if null cdr u then return l;
                  a: if null cdr(u := cdr u)
                       then
                        return chk!-printlength(car u,1+l,n);
                     if ((l := chk!-printlength(car u,1+l,n))
                         eq 'failed)
                       then return 'failed
                      else go to a
                  end
      else if ((l := flatsizec u + m)) > n then 'failed else l
   end;

endmodule;


module fortpri; % FORTRAN output package for expressions.

% Author: Anthony C. Hearn.

% Copyright (c) 1987 The RAND Corporation. All rights reserved.

fluid '(scountr explis fbrkt fvar nchars svar);

global '(!*fort
         !*nat
         !*nero
         !*outp
         !*period
         !*pri
         cardno!*
         fortwidth!*
         initl!*
         nat!*!*
         obrkp!*
         orig!*
         pline!*
         posn!*
         spare!*
         varnam!*
         wtl!*
         ycoord!*
         ymax!*
         ymin!*);

%Global variables initialized in this section;

% SPARE!* should be set in the system dependent code module.

!*nat := nat!*!* := t;
cardno!*:=20;
fortwidth!* := 70;
obrkp!* := t;
orig!*:=0;
posn!* := 0;
varnam!* := 'ans;
ycoord!* := 0;
ymax!* := 0;
ymin!* := 0;

flag ('(cardno!* fortwidth!*),'share);

initl!* := append('(orig!* pline!*),initl!*);

put('orig!*,'initl,0);

symbolic procedure varname u;
   %sets the default variable assignment name;
   varnam!* := car u;

rlistat '(varname);

symbolic procedure flength(u,chars);
   if chars<0 then chars
    else if atom u
     then chars-if numberp u then if fixp u then flatsizec u+1
                                   else flatsizec u
                 else flatsizec((lambda x; if x then x else u)
                                   get(u,'prtch))
    else flength(car u,flenlis(cdr u,chars)-2);

symbolic procedure flenlis(u,chars);
   if null u then chars
    else if chars<0 then chars
    else if atom u then flength(u,chars)
    else flenlis(cdr u,flength(car u,chars));

symbolic procedure fmprint(l,p);
   begin scalar x;
        if null l then return nil
         else if atom l then go to b
         else if stringp l then return fprin2 l
         else if not atom car l then fmprint(car l,p)
%        else if x := get(car l,'specprn)
%         then return apply1(x,cdr l)
         else if (x := get(car l,'prifn))
            and not((x := apply1(x,l)) eq 'failed)
          then return x
         else if x := get(car l,'infix) then go to a
         else fprin2 car l;
        fprin2 "(";
        fbrkt := nil . fbrkt;
%       x := !*period; !*period := nil; % Turn off . inside an op exp
        if cdr l then fnprint('!*comma!*,0,cdr l);
%       !*period := x;
    e:  fprin2 ")";
        return fbrkt := cdr fbrkt;
    b:  if numberp l then go to d;
    c:  return fprin2 l;
    d:  if not l<0 then go to c;
        fprin2 "(";
        fbrkt := nil . fbrkt;
        fprin2 l;
        go to e;
    a:  p := not x>p;
        if p then <<fprin2 "("; fbrkt := nil . fbrkt>>;
        fnprint(car l,x,cdr l);
        if p then <<fprin2 ")"; fbrkt := cdr fbrkt>>
   end;

symbolic procedure fnprint(op,p,l);
   begin
        if op eq 'expt then return fexppri(p,l)
         else if get(op,'alt) then go to a;
        fmprint(car l,p);
    a0: l := cdr l;
    a:  if null l then return nil
         else if not atom car l and op eq get!*(caar l,'alt)
          then go to b;
        foprin op;
    b:  fmprint(car l,p);
        go to a0
   end;

symbolic procedure fexppri(p,l);
   begin scalar pperiod;
      fmprint(car l,p);
      foprin 'expt;
      pperiod := !*period;
      if numberp cadr l then !*period := nil else !*period := t;
      fmprint(cadr l,p);
      !*period := pperiod
   end;

symbolic procedure foprin op;
   (lambda x; if null x then fprin2 op else fprin2 x) get(op,'prtch);

symbolic procedure fvarpri(u,v,w);
   %prints an assignment in FORTRAN notation;
   begin integer scountr,llength,nchars; scalar explis,fvar,svar;
        llength := linelength nil;
        if not posintegerp cardno!*
          then typerr(cardno!*,"FORTRAN card number");
        if not posintegerp fortwidth!*
          then typerr(fortwidth!*,"FORTRAN line width");
        linelength fortwidth!*;
        if stringp u
          then return <<fprin2 u; 
                        if w eq 'only then fterpri(t);
                        linelength llength>>;
        if eqcar(u,'!*sq) then u := prepsq!* cadr u;
        scountr := 0;
        nchars := ((linelength nil-spare!*)-12)*cardno!*;
           %12 is to allow for indentation and end of line effects;
        svar := varnam!*;
        fvar := if null v then svar else car v;
        if posn!*=0 and w then fortpri(fvar,u,w)
         else fortpri(nil,u,w);
                % should mean expression preceded by a string.
        linelength llength
   end;

symbolic procedure fortpri(fvar,xexp,w);
   begin scalar fbrkt;
        if flength(xexp,nchars)<0
          then xexp := car xexp . fout(cdr xexp,car xexp,w);
        if fvar 
          then <<posn!* := 0;
                 fprin2 "      ";
                 fmprint(fvar,0);
                 fprin2 "=">>;
        fmprint(xexp,0);
        if w then fterpri(w)
   end;

symbolic procedure fout(args,op,w);
   begin integer ncharsl; scalar distop,x,z;
        ncharsl := nchars;
        if op memq '(plus times) then distop := op;
        while args do
         <<x := car args;
           if atom x and (ncharsl := flength(x,ncharsl))
              or (null cdr args or distop)
                and (ncharsl := flength(x,ncharsl))>0
             then z := x . z
            else if distop and flength(x,nchars)>0
             then <<z := fout1(distop . args,w) . z;
                    args := list nil>>
            else <<z := fout1(x,w) . z;
                   ncharsl := flength(op,ncharsl)>>;
           ncharsl := flength(op,ncharsl);
           args := cdr args>>;
        return reversip!* z
   end;

symbolic procedure fout1(xexp,w);
   begin scalar fvar;
      fvar := genvar();
      explis := (xexp . fvar) . explis;
      fortpri(fvar,xexp,w);
      return fvar
   end;

symbolic procedure fprin2 u;
   % FORTRAN output of U;
   begin integer m,n;
        n := flatsizec u;
        m := posn!*+n;
        if numberp u and fixp u and !*period then m := m+1;
        if m<(linelength nil-spare!*) then posn!* := m
         else <<terpri(); spaces 5; prin2 ". "; posn!* := n+7>>;
        prin2 u;
        if numberp u and fixp u and !*period then prin2 "."
   end;

symbolic procedure fterpri(u);
   <<if not posn!*=0 and u then terpri();
     posn!* := 0>>;

symbolic procedure genvar;
   intern compress append(explode svar,explode(scountr := scountr + 1));

endmodule;


module gint;  % Support for gaussian integers (complex numbers).

% Author: Eberhard Schruefer.

global '(domainlist!*);

fluid '(!*complex);

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
              else if dmode!* eq '!:gi!: then return nil
              else if not (y := get(dmode!*,'cmpxtype))
               then dmoderr(dmode!*,x)
              else <<put('i,'idval,get(car y,'ivalue));
                     return setdmode1(get(car y,'dname),bool)>>
       else if null bool
        then <<put('i,'idvalfn,'mkdgi);
               return setdmode1('complex,t)>>
       else <<u := get(u,'tag);
              y := get(u,'cmpxtype);
              if null y then dmoderr(u,'!:gi!:);
              put('i,'idvalfn,get(car y,'ivalue));
              return setdmode1(get(car y,'dname),bool)>>
   end;

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
put('!:gi!:,'rationalizefn,'girationalize!:);
put('!:gi!:,'prepfn,'giprep!:);
put('!:gi!:,'intequivfn,'gintequiv!:);
put('!:gi!:,'specprn,'giprn!:);
put('!:gi!:,'prifn,'giprn!:);
put('!:gi!:,'cmpxfn,'mkgi);

put('!:gi!:,'units,'(((!:gi!: 0 . 1) . (!:gi!: 0 . -1))
                     ((!:gi!: 0 . -1) . (!:gi!: 0 . 1))));

symbolic procedure !*i2gi u; '!:gi!: . (u . 0);

symbolic procedure giminusp!: u;
   %*** this is rather a test for u being in a canonical form! ***;
   if cddr u = 0 then minusp cadr u else minusp cddr u;

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
   % B. Trager's algorithm.
   begin scalar x,y,norm,aftrs,ifctr,ftrs,mvu,dmode!*,!*exp,w,z;
     !*exp := t;
     ifctr := factorf fd2f u;
     dmode!* := '!:gi!:;
     w := car ifctr;
     if null(ifctr := cdr ifctr) then return list w;
     for each f in ifctr do
       begin integer s; %calculate a square free norm;
             scalar l;
         go to b;
         a: l := list(mvu . prepf addf(!*k2f mvu,multd(s,!*k2f 'i)));
         b: y := numr subf1(car f,l);
            if domainp y then <<w := multd(y,w); return>>;
            mvu := mvar y;
            if realp y then <<s := s-1; go to a>>;
            norm := multf(y,conj y);
            if not sqfrp norm then <<s := s-1; go to a>>;
            dmode!* := nil;
            ftrs := factorf norm;
            dmode!* := '!:gi!:;
            l := if s=0 then nil
                  else list(mvu . prepf addf(!*k2f mvu,
                                             negf multd(s,!*k2f 'i)));
            for each j in cdr ftrs do
              <<x := gcdf!*(car j,y);
                y := quotf!*(y,x);
                z := if l then numr subf1(x,l) else x;
                aftrs := (z . cdr f) . aftrs>>
         end;
         return multd(car ftrs,w) . aftrs
       end;

symbolic procedure gaussfactorize u;
   begin scalar ftrs,x,y,!*exp; integer n;
     !*exp := t;
     x := gifactor!: expnd !*a2f car u;
     y := if null cdr u then 'gfactor else cadr u;
     ftrs := (0 . car x) . nil;
     for each j in cdr x do
       for k := 1:cdr j do
         ftrs := ((n:=n+1) . mk!*sq(car j ./ 1)) . ftrs;
     return multiple!-result(ftrs,y)
   end;

put('gfactorize,'simpfn,'gaussfactorize);

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


symbolic procedure sqfrp u;
   domainp gcdf!*(u,diff(u,mvar u));

symbolic procedure giprep!: u;  %giprep1 cdr u;
   prepsq!* addsq(!*n2f cadr u ./ 1,
                  multsq(!*n2f cddr u ./ 1, !*k2q 'i));

symbolic procedure giprep1 u;  %not used now;
   if cdr u=0 then car u
    else if car u=0 then retimes list(cdr u,'i)
    else begin scalar gn;
           gn := gcdn(car u,cdr u);
           return retimes list(gn,
                       replus list(car u/gn,retimes list(cdr u/gn,'i)))
         end;

symbolic procedure giprn!: v;
   (lambda u;
    if atom u or (car u eq 'times) then maprin u
     else <<prin2!* "("; maprin u; prin2!* ")" >>) giprep!: v;

symbolic procedure girationalize!: u;
   %Rationalizes standard quotient u over the gaussian integers.
   begin scalar x,y,z;
      y := denr u;
      z := conj y;
      if y=z then return u;
      x := multf(numr u,z);
      y := multf(y,z);
      return x ./ y
   end;


%*** some utility functions ***;

symbolic procedure repart u;
   begin scalar x;
      return if atom u then u
              else if domainp u and (x := get(car u,'cmpxfn))
               then apply2(x,cadr u,0)
              else addf(multpf(lpow u,repart lc u),repart red u)
   end;

symbolic procedure impart u;
   begin scalar x;
      return if atom u then nil
              else if domainp u and (x := get(car u,'cmpxfn))
               then apply2(x,cddr u,0)
              else addf(multpf(lpow u,impart lc u),impart red u)
   end;

symbolic procedure conj u;
   begin scalar x;
      return if atom u then u
              else if domainp u and (x := get(car u,'cmpxfn))
               then apply2(x,cadr u,!:minus cddr u)
              else addf(multpf(lpow u,conj lc u),conj red u)
   end;

deflist('((repart repart) (impart impart) (conj conj)),'polyfn);

initdmode 'complex;

endmodule;


module gfloat; % Support for gaussian floats.

% Authors: Barbara Gates and Eberhard Schruefer.

global '(domainlist!* e!-value!* pi!-value!*);

fluid '(!*complex!_float);

% This module needs gint to be loaded too.

domainlist!*:=union('(!:gf!:),domainlist!*);

put('complex!_float,'tag,'!:gf!:);
put('!:gf!:,'dname,'complex!_float);
put('!:gf!:,'i2d,'!*i2gf);
put('!:gf!:,'minusp,'gfminusp!:);
put('!:gf!:,'zerop,'gfzerop!:);
put('!:gf!:,'onep,'gfonep!:);
put('!:gf!:,'plus,'gfplus!:);
put('!:gf!:,'difference,'gfdifference!:);
put('!:gf!:,'times,'gftimes!:);
put('!:gf!:,'quotient,'gfquotient!:);
put('!:gf!:,'prepfn,'gfprep!:);
put('!:gf!:,'prifn,'gfprn!:);
put('!:gf!:,'rationalizefn,'girationalize!:);
put('!:rn!:,'!:gf!:,'rn2gf);
put('!:ft!:,'!:gf!:,'ft2gf);
put('!:gf!:,'!:ft!:,'gf2f);
put('!:gf!:,'cmpxfn,'mkgf);
put('!:gf!:,'ivalue,'mkdgf);
put('!:gf!:,'realtype,'!:ft!:);
flag('(!:gf!:),'field);

symbolic procedure mkdgf u;
   ('!:gf!: . (0.0 . 1.0)) ./ 1;

smacro procedure mkgf(rp,ip);
   '!:gf!: . (rp . ip);

symbolic procedure !*i2gf u;
   '!:gf!: . (float u .  0.0);

symbolic procedure rn2gf u; mkgf(cdr !*rn2ft u,0.0);

symbolic procedure ft2gf u; mkgf(cdr u,0.0);

symbolic procedure gf2f u;
%  if cddr u=0.0 then '!:ft!: . cadr u else
   if zerop cddr u then '!:ft!: . cadr u else
    rederr "Conversion to float requires zero imaginary part";

symbolic procedure gfminusp!: u;
   % This doesn't make much sense.
%  if abs cddr u<0.000001 then cadr u<0.0 else cddr u<0.0;
   if abs cddr u<0.000001 then minusp cadr u else minusp cddr u;

symbolic procedure gfzerop!: u;
%  cadr u=0.0 and cddr u=0.0;
   zerop cadr u and zerop cddr u;

symbolic procedure gfonep!: u;
%cddr u =0.0 and ftonep!:('!:ft!: . cadr u); %this is too restrictive;
   ftonep!:('!:ft!: . (cadr u+cddr u)) and
   ftonep!:('!:ft!: . cadr u);

symbolic procedure gfplus!:(u,v);
   mkgf(cadr u+cadr v,cddr u+cddr v);

symbolic procedure gfdifference!:(u,v);
   mkgf(cadr u-cadr v,cddr u-cddr v);

symbolic procedure gftimes!:(u,v);
   begin scalar r1,i1,r2,i2,rr,ii;
     r1 := cadr u; i1 := cddr u;
     r2 := cadr v; i2 := cddr v;
     rr := r1*r2-i1*i2;
     ii := r1*i2+r2*i1;
     return mkgf(rr,ii)
   end;

symbolic procedure gfquotient!:(u,v);
   begin scalar r1,i1,r2,i2,rr,ii,d;
     r1 := cadr u; i1 := cddr u;
     r2 := cadr v; i2 := cddr v;
     d := r2*r2+i2*i2;
     rr := r1*r2+i1*i2;
     ii := i1*r2-i2*r1;
     return mkgf(rr/d,ii/d)
   end;

symbolic procedure gfprep!: u; gfprep1 cdr u;
%begin scalar dmode!*;
%dmode!*:='!:ft!:;
%return
%prepsq!* addsq(('!:ft!: . cadr u) ./ 1,
%               multsq(('!:ft!: . cddr u) ./ 1,!*k2q 'i))
%end;

symbolic procedure gfprep1 u;
%  if cdr u=0.0 then car u
   if zerop cdr u then car u
%   else if car u=0.0 then if ftonep!:('!:ft!: . cdr u) then 'i
    else if zerop car u then if ftonep!:('!:ft!: . cdr u) then 'i
                            else list('times,cdr u,'i)
    else list('plus,car u,if ftonep!:('!:ft!: . cdr u) then 'i
                           else list('times,cdr u,'i));

symbolic procedure gfprn!: u;
(lambda v; if atom v or car v eq 'times
           or car v memq domainlist!* then maprin v
     else <<prin2!* "("; maprin v; prin2!* ")">>) gfprep1 cdr u;


% *** Elementary functions.

deflist('((e egf!*) (pi pigf!*)),'!:gf!:);

symbolic procedure egf!*; mkgf(e!-value!*,0.0);

symbolic procedure pigf!*; mkgf(pi!-value!*,0.0);

deflist('((expt gfexpt) (sin gfsin) (cos gfcos) (tan gftan)
          (asin gfasin) (acos gfacos) (atan gfatan)
          (log gflog)),'!:gf!:);


symbolic procedure gfexpt(u,v);
   begin scalar re1,im1,re2,im2,norm,ang,angr;
     re1 := cadr u; im1 := cddr u;
     re2 := cadr v; im2 := cddr v;
     norm := sqrt(re1*re1+im1*im1);
     ang := ftarg!: u;
     angr := im2*log norm+re2*ang;
     norm := exp(log norm*re2-im2*ang);
     return mkgf(norm*cos angr,norm*sin angr)
   end;


symbolic procedure ftarg!: u;
%Returns ftarg u in the range (-pi,+pi);
% (lambda x,y; if y=0.0 then if x<0.0 then pi!-value!*
 (lambda x,y; if zerop y then if minusp x then pi!-value!*
                                    else 0.0 else
%            if x=0.0 then if y<0.0 then -pi!-value!*/2 else
             if zerop x then if minusp y then -pi!-value!*/2 else
                                          pi!-value!*/2 else
%            if x<0.0 and y<0.0 then atan(y/x)-pi!-value!*
             if minusp x and minusp y then atan(y/x)-pi!-value!*
%               else if x<0.0 and not(y<0.0) then
                else if minusp x and not minusp y then
                                     atan(y/x)+pi!-value!*
              else atan(y/x)) (cadr u,cddr u);

put('ftarg!:,'!:gf!:,'ftarg!:);

symbolic procedure gfsin u;
   mkgf(sin cadr u*cosh cddr u,cos cadr u*sinh cddr u);

symbolic procedure gfcos u;
   mkgf(cos cadr u*cosh cddr u,-sin cadr u*sinh cddr u);

symbolic procedure gftan u;
   begin scalar v;
     v := cos(2.0*cadr u)+cosh(2.0*cddr u);
     return mkgf(sin(2.0*cadr u)/v,sinh(2.0*cddr u)/v)
   end;

symbolic procedure gfasin u;
   begin scalar a,b,c;
     a := 0.5*sqrt(expt(cadr u+1.0,2)+cddr u*cddr u);
     b := 0.5*sqrt(expt(cadr u-1.0,2)+cddr u*cddr u);
     c := a+b;
     b := a-b;
     a := c;
     c := a+sqrt(a*a-1.0);
     return mkgf(asin b,log c)
   end;

symbolic procedure gfacos u;
   begin scalar a,b,c;
     a := 0.5*sqrt(expt(cadr u+1.0,2)+cddr u*cddr u);
     b := 0.5*sqrt(expt(cadr u-1.0,2)+cddr u*cddr u);
     c := a+b;
     b := a-b;
     a := c;
     c := a+sqrt(a*a-1.0);
     return mkgf(acos b,-1.0*log c)
   end;

symbolic procedure gfatan u;
   gftimes!:(gflog(gfquotient!:(
                   gfplus!:(!*i2gf 1,gftimes!:(mkgf(0.0,-1.0),u)),
                   gfplus!:(!*i2gf 1,gftimes!:(mkgf(0.0,1.0),u)))),
             mkgf(0.0,0.5));


symbolic procedure gflog u;
   begin scalar norm;
     norm := sqrt(cadr u*cadr u+cddr u*cddr u);
     return mkgf(log norm,ftarg!: u)
   end;

symbolic procedure sinh u; 0.5*(exp u-exp(-u));

symbolic procedure cosh u; 0.5*(exp u+exp(-u));

initdmode 'complex!_float;

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
put('!:mod!:,'prepfn,'modprep!:);
put('!:mod!:,'prifn,'prin2);

symbolic procedure !*i2mod u;
   %converts integer U to modular form;
%  if (u := general!-modular!-number u)=0 then nil else '!:mod!: . u;
   '!:mod!: . general!-modular!-number u;

symbolic procedure modcnv u;
   rederr list("Conversion between modular integers and",
                get(car u,'dname),"not defined");

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
      u := reval u;  % dmode* is NIL, so this won't be reduced wrt
                     % current modulus.
      if fixp u and u>0
        then <<if primep u then flag('(!:mod!:),'field)
                else remflag('(!:mod!:),'field);
               return set!-general!-modulus u>>
      else if u=0 or null u then return current!-modulus
       else typerr(u,"modulus")
   end;

flag('(setmod),'opfn);   %to make it a symbolic operator;

flag('(setmod),'noval);

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

% Copyright (c) 1987 The RAND Corporation. All rights reserved.

fluid '(!*gcd dmode!*);

global '(!*factor);

comment In this module, we consider the manipulation of factored forms.
        These have the structure
        
           <monomial> . <form-power-list>

        where the monomial is itself a standard form (satisfying the
        KERNLP test) and a form-power is a dotted pair whose car is a 
        standard form and cdr an integer>0. We have thus represented the
        form as a product of a monomial and powers of non-monomial
        factors;

symbolic smacro procedure facmerge(u,v);
   %Returns the merge of the form_power_lists U and V;
   append(u,v);

symbolic procedure fctrf u;
   %U is a standard form. Value is a standard factored form;
   %The function FACTORF is an assumed entry point to a more complete
   %factorization module which itself returns a form power list;
   begin scalar mv,x,y,!*gcd;
      !*gcd := t;
      if domainp u then return list u
       else if !*factor
        then return if dmode!* and (x := get(dmode!*,'factorfn))
                      then apply1(x,u)
                     else factorf u;
      mv := mvar u;
      x := comfac u;
      u := quotf(u,comfac!-to!-poly x);
      y := fctrf cdr x;   % factor the content.
      if car x then y := multpf(car x,car y) . cdr y; % merge monomials
      if domainp u then return multf(u,car y) . cdr y
       else if not(mvar u eq mv)
        then return car y . facmerge(fctrf1 u,cdr y)
       else if minusf u
        then <<u := negf u; y := negf car y . cdr y>>;
      return car y . facmerge(factor!-prim!-f u,cdr y);
   end;

symbolic procedure fctrf1 u; 1 . factor!-prim!-f u;

symbolic procedure factor!-prim!-f u;
   %U is a non-trivial form which is primitive in all its variables
   %and has a positive leading numerical coefficient. Result is a
   %form power list.
   (for each x in v conc factor!-prim!-sqfree!-f(car x,cdr x))
      where v = sqfrf u;

symbolic procedure factor!-prim!-sqfree!-f(u,n);
   for each x in prsqfrfacf u collect (x . n);

symbolic procedure sqfrf u;
   %U is a non-trivial form which is primitive in all its variables
   %and has a positive leading numerical coefficient.
   %SQFRF performs square free factorization on U and returns a 
   %form power list;
   begin integer k,n; scalar !*gcd,v,w,x,y,z;
      n := 1;
      x := mvar u;
      !*gcd := t;
   a: v := gcdf(u,diff(u,x));
      k := degr(v,x);
      if k>0 then <<u := quotf(u,v);
                    if flagp(dmode!*,'field) and ((y := lnc u) neq 1)
                     then <<u := multd(!:recip y,u);
                            v := multd(y,v)>>>>;
      if w
        then <<if u neq w
                 then z := facmerge(list(quotf(w,u) . n),z);
               n := n+1>>;
      if k=0 then return facmerge(list(u . n),z);
      w := u;
      u := v;
      go to a
   end;

symbolic procedure diff(u,v);
   %a polynomial differentation routine which does not check
   %indeterminate dependences;
   if domainp u then nil
    else addf(addf(multpf(lpow u,diff(lc u,v)),
                multf(lc u,diffp1(lpow u,v))),
              diff(red u,v));

symbolic procedure diffp1(u,v);
   if not car u eq v then nil
    else if cdr u=1 then 1
    else multd(cdr u,!*p2f(car u .** (cdr u-1)));

endmodule;


module primfac;   % Primitive square free polynomial factorization.

% Author: Anthony C. Hearn.

% Copyright (c) 1987 The RAND Corporation. All rights reserved.

fluid '(dmode!* kernlist!*);

symbolic procedure prsqfrfacf u;
   %U is a non-trivial form which is primitive in all its variables,
   %is square free, and has a positive leading numerical coefficient. 
   % Result is a list of factors of u.
   % We order kernels in increasing powers unless kernlist!* has a
   % non-NIL value in which case we use that order (needed by SOLVE).
   % NOTE: For the time being, we bypass this code if the coefficient
   % domain is other than integer.
   begin scalar b,bool,v,w;
      if dmode!* then return list u;
      v := if kernlist!* then kernlist!* 
            else reverse kernord!-sort powers u;
      % order highest power first.
      if cdr v
       then <<w := setkorder v;
              b := t;
              u := reorder u;
              if minusf u then <<bool := t; u := negf u>>>>;
      u := factor!-ordered!-sqfree!-prim!-f u; 
      if b then <<setkorder w;
                  u := for each x in u collect
                          begin
                             v := reorder x;
                             if bool and minusf v
                               then <<v := negf v; bool := nil>>;
                             return v
                          end>>;
      if bool then errach list("factor confusion",u);
      return u
   end;

symbolic procedure factor!-ordered!-sqfree!-prim!-f pol;
   % U is a non-trivial form which is primitive in all its variables,
   % is square free, has a positive leading numerical coefficient,
   % and has a main variable of lowest degree in the form.
   % Result is a form power list.
   begin integer n; scalar q,res,w;
      if ldeg pol = 1 then return list factor!-coeffs pol
       else if univariatep pol
        then <<while car(q := linfacf pol) do 
                <<res := car q . res; pol := cdr q>>;
               while car(q := quadfacf pol) do 
                <<res := car q . res; pol := cdr q>>>>;
      if null pol then return res
       else if length(w := special!-case!-factor pol)>1
        then return nconc!*(res,
                            for each x in w conc 
                               factor!-ordered!-sqfree!-prim!-f x)
       else if ldeg pol < 4 or (n := degreegcd pol) = 1 
          then return pol . res;
      w := cdr sort(dfactors n,function lessp);
      % 1 is always first factor.
   a: if null w then return pol . res
       else if length (q := factor!-ordered!-sqfree!-prim!-f 
                               downpower(pol,car w))>1
        then return nconc!*(res,for each x in q 
                                  conc factor!-ordered!-sqfree!-prim!-f
                                           uppower(x,car w));
      w := cdr w;
      go to a
   end;

symbolic procedure downpower(pol,n);
    % Reduce the power of each term in pol wrt main variable by factor
    %n.
   downpower1(pol,mvar pol,n);

symbolic procedure downpower1(pol,mv,n);
   if domainp pol or not(mvar pol eq mv) then pol
    else (mv .** (ldeg pol/n)) .* lc pol .+ downpower1(red pol,mv,n);

symbolic procedure uppower(pol,n);
    % Raise the power of each term in pol wrt main variable by factor
    %n.
   uppower1(pol,mvar pol,n);

symbolic procedure uppower1(pol,mv,n);
   if domainp pol or not(mvar pol eq mv) then pol
    else (mv .** (ldeg pol*n)) .* lc pol .+ downpower1(red pol,mv,n);

symbolic procedure univariatep pol;
   % True if pol is not a domain element and is univariate with respect 
   % to its main variable.
   not domainp pol and univariatep1(pol,mvar pol);

symbolic procedure univariatep1(pol,mv);
   domainp pol 
      or mvar pol eq mv and domainp lc pol and univariatep1(red pol,mv);

symbolic procedure special!-case!-factor pol;
   (if degree = 2 then quadraticf pol
     else if degree= 3 then cubicf pol
       else if degree = 4 then quarticf pol
       else list pol) 
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
   u;

endmodule;


module specfac;   % splitting of low degree polynomials.

% Author: Anthony C. Hearn.

% Copyright (c) 1987 The RAND Corporation. All rights reserved.

exports cubicf,quadraticf,quarticf;

symbolic procedure coeffs pol;
% extract coefficients of polynomial wrt its main variable and leading 
% degree. Result is a list of coefficients.
    begin integer degree,deg1; scalar cofs,mv;
      mv := mvar pol;
      degree := ldeg pol;
      while not domainp pol and mvar pol eq mv do
       <<deg1 := ldeg pol;
         for i:= 1:(degree-deg1-1) do cofs := 0 . cofs;
         cofs := lc pol . cofs;
         pol := red pol;
         degree := deg1>>;
      for i:=1:degree-1 do cofs := 0 . cofs;
      if null pol then pol := 0;
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

symbolic procedure quadraticf pol;
% Finds factors of square free quadratic polynomial pol (if they exist).
% Does not assume pol is univariate.
%   quadraticf2(car w,cadr w,caddr w,mvar pol) where w = coeffs pol;
   (if x eq 'failed then list pol
    else list(y .* car x .+ cadr x,y .* caddr x .+ cadddr x)
       where y = (mvar pol .** 1))
    where x = quadraticf1(car w,cadr w,caddr w) where w = coeffs pol;

symbolic procedure quadraticf1(a,b,c);
   begin scalar a1,denom,discrim,w;
      if b=0 then b := nil;
      discrim := addf(exptf(b,2),multd(-4,multf(a,c)));
      if null discrim then errach "discrim=0 in quadratic"
       else if minusf discrim then return 'failed;
      discrim:=rootxf(discrim,2);
      if discrim='failed then return discrim;
      denom := multd(4,a);
      a := multd(2,a);
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
      if denom neq 1 then errach "denominator not 1 in quadratic";
      return list(a1,b,a,c)
    end;

symbolic procedure rootxf(u,n);
   % find polynomial nth root of u or return "failed".
   begin scalar x,y,z;
      if domainp u 
        then return if fixp u and (y := irootn(u,n))**n=u then y
                     else 'failed;
      x := comfac u;
      u := quotf(u,comfac!-to!-poly x);
      z := 1;
      if car x then if cdr(y := divide(cdar x,n)) = 0 
        then z := multpf(caar x .** car y,z)
       else return 'failed;
      x := cdr x;
      if domainp x then if fixp x and (y := irootn(x,n))**n=x
        then z := multd(y,z)
            else return 'failed
       else if (y := rootxf(x,n)) eq 'failed then return y
       else z := multf(y,z);
      if u=1 then return z;
      x := sqfrf u;
   c: if null x then return z
       else if cdr(y := divide(cdar x,n)) = 0 
        then <<z := multf(exptf(caar x,car y),z); x := cdr x>>
       else return 'failed;
      go to c
   end;

symbolic procedure cubicf pol;
% split the cubic pol if a change of origin puts it in the form 
% (x-a)**3-b=0.
    begin scalar a,a0,b,neg,pol1;
       pol1 := shift!-pol pol;
       a := coeffs car pol1;
%      if cadr a neq 0 then rederr list(pol,"not correctly shifted")
       % cadr a neq 0 probably means there are some surds in the
       % coefficients that don't reduce to 0.
       if cadr a neq 0 then return list pol
        else if caddr a neq 0 then return list pol;  
       % factorization not possible by this method
       a0 := cadddr a;     
       a := car a;
       if minusf a0 
         then <<neg := t; a0 := negf a0>>;
       if (a := rootxf(a,3)) eq 'failed
          or (a0 := rootxf(a0,3)) eq 'failed
         then return list pol;
       if neg then a0 := negf a0;
       %now numr (a*(mv+shift)+a0) is a factor of pol;
       a := numr addsq(multsq(!*f2q a,addsq(!*k2q mvar pol,caddr pol1)),
                       !*f2q a0);
       if null(b := quotf(pol,a)) 
         then errach list(pol,"doesn't factor properly"); 
       return a . quadraticf b
    end;

symbolic procedure quarticf pol;
%splits quartics that can be written in the form (x-a)**4+b*(x-a)**2+c.
   begin scalar a,a2,a0,b,pol1,x;
      pol1 := shift!-pol pol;     
      a := coeffs car pol1;
      if cadr a neq 0 then rederr list(pol,"not correctly shifted")
        else if cadddr a neq 0 then return list pol;  
       % factorization not possible by this method
      a2 := cddr a;
      a0 := caddr a2;
      a2 := car a2;
      a := car a; 
      x := quadraticf1(a,a2,a0);
      if x eq 'failed then return list pol;
      a := exptsq(addsq(!*k2q mvar pol,caddr pol1),2);  % (x+shift)**2
      b := numr quotsq(addsq(multsq(!*f2q car x,a),!*f2q cadr x),
                       !*f2q cadr pol1);
           % should be one factor;
      a := quotf(pol,b);
      if null a then errach list(pol,"doesn't factor properly"); 
      return append(quadraticf a,quadraticf b)
   end;

endmodule;


module kronf;   % Kronecker factorization of univariate forms.

% Author: Anthony C. Hearn.

% Based on code first written by Mary Ann Moore and Arthur C. Norman.

% Copyright (c) 1987 The RAND Corporation. All rights reserved.

exports linfacf,quadfacf;

imports zfactor;

% Note that only linear and quadratic factors are found here.

symbolic procedure linfacf u; trykrf(u,'(0 1));

symbolic procedure quadfacf u; trykrf(u,'(-1 0 1));

symbolic procedure trykrf(u,points);
   % Look for factor of u by evaluation at points and interpolation.
   % Return (fac . cofac), with fac = nil if none found,
   % and cofac = nil if nothing worthwhile is left.
   begin scalar attempt,mv,values;
      if null u then return nil . nil
       else if length points > ldeg u then return u . nil;
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
   % produces a list of all (positive) factors of the domain element n.
   begin scalar x;
      if n=0 then return list 0
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

fluid '(!*rationalize dmode!* kord!*);

put('rationalize,'simpfg,'((t (rmsubs)) (nil (rmsubs))));

symbolic smacro procedure subtrf(u,v);
   % Returns u - v for standard forms u and v.
   addf(u,negf v);

symbolic procedure rationalizesq u;
   % Rationalize the standard quotient u.
   begin scalar x;
      if x := get(dmode!*,'rationalizefn) then u := subs2 apply1(x,u);
      % We need the subs2 to get rid of surd powers.
      return if domainp denr u then u
             else if (x := rationalizef denr u) neq 1
              then rationalizesq subs2q(multf(numr u,x)
                                          ./ multf(denr u,x))
             else u
   end;

symbolic procedure rationalizef u;
   % Look for I and sqrts, cbrts, quartics at present.
   begin scalar x,y;
      x := kernels u;
   a: if null x then return 1;
      y := car x;
      if y eq 'i or eqcar(y,'expt) and caddr y = '(quotient 1 2)
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

% Copyright (c) 1987 The RAND Corporation. All rights reserved.

global '(frlis!* mcond!* powlis!* subfg!* wtl!*);

% Contains a reference to RPLACD (a table update), commented out.

symbolic procedure simpdf u;
   %U is a list of forms, the first an expression and the remainder
   %kernels and numbers.
   %Value is derivative of first form wrt rest of list;
   begin scalar v,x,y;
        if null subfg!* then return mksq('df . u,1);
        v := cdr u;
        u := simp!* car u;
    a:  if null v or null numr u then return u;
        x := if null y or y=0 then simp!* car v else y;
        if null kernp x then typerr(prepsq x,"kernel");
        x := caaaar x;
        v := cdr v;
        if null v then go to c;
        y := simp!* car v;
        if null numr y then <<v := cdr v; y := nil; go to a>>
         else if not denr y=1 or not numberp numr y then go to c;
        v := cdr v;
    b:  for i:=1:car y do u := diffsq(u,x);
        y := nil;
        go to a;
    c:  u := diffsq(u,x);
        go to a
   end;

put('df,'simpfn,'simpdf);

symbolic procedure diffsq(u,v);
   %U is a standard quotient, V a kernel.
   %Value is the standard quotient derivative of U wrt V.
   %Algorithm: df(x/y,z)= (x'-(x/y)*y')/y;
   multsq(addsq(difff(numr u,v),negsq multsq(u,difff(denr u,v))),
          1 ./ denr u);

symbolic procedure difff(u,v);
   %U is a standard form, V a kernel.
   %Value is the standard quotient derivative of U wrt V;
   if domainp u then nil ./ 1
    else addsq(addsq(multpq(lpow u,difff(lc u,v)),
                        multsq(diffp(lpow u,v),lc u ./ 1)),
               difff(red u,v));

symbolic procedure diffp(u,v);
   %U is a standard power, V a kernel.
   %Value is the standard quotient derivative of U wrt V;
   begin scalar n,w,x,y,z; integer m;
        n := cdr u;     %integer power;
        u := car u;     %main variable;
        if u eq v and (w := 1 ./ 1) then go to e
         else if atom u then go to f
         %else if (x := assoc(u,dsubl!*)) and (x := atsoc(v,cdr x))
%               and (w := cdr x) then go to e   %deriv known;
             %DSUBL!* not used for now;
         else if (not atom car u and (w:= difff(u,v)))
                  or (car u eq '!*sq and (w:= diffsq(cadr u,v)))
          then go to c  %extended kernel found;
         else if (x:= get!*(car u,'dfn)) then nil
         else if car u eq 'plus and (w:=diffsq(simp u,v))
          then go to c
         else go to h;  %unknown derivative;
        y := x;
        z := cdr u;
    a:  w := diffsq(simp car z,v) . w;
        if caar w and null car y then go to h;  %unknown deriv;
        y := cdr y;
        z := cdr z;
        if z and y then go to a
         else if z or y then go to h;  %arguments do not match;
        y := reverse w;
        z := cdr u;
        w := nil ./ 1;
    b:  %computation of kernel derivative;
        if caar y
          then w := addsq(multsq(car y,simp subla(pair(caar x,z),
                                                   cdar x)),
                          w);
        x := cdr x;
        y := cdr y;
        if y then go to b;
    c:  %save calculated deriv in case it is used again;
        %if x := atsoc(u,dsubl!*) then go to d
        %else x := u . nil;
        %dsubl!* := x . dsubl!*;
    d:  %rplacd(x,xadd(v . w,cdr x,t));
    e:  %allowance for power;
        %first check to see if kernel has weight;
        if (x := atsoc(u,wtl!*))
          then w := multpq('k!* .** (-cdr x),w);
        m := n-1;
        return if n=1 then w
                else if flagp(dmode!*,'convert)
                     and null(n := int!-equiv!-chk
                                           apply1(get(dmode!*,'i2d),n))
                 then nil ./ 1
                else multsq(!*t2q((u .** m) .* n),w);
    f:  %check for possible unused substitution rule;
        if not depends(u,v)
           and (not (x:= atsoc(u,powlis!*))
                 or not car diffsq(simp cadddr x,v))
          then return nil ./ 1;
        w := list('df,u,v);
        go to j;
    h:  %final check for possible kernel deriv;
        if car u eq 'df
          then if depends(cadr u,v)
                 then if assoc(w := list('df,cadr u,v),
                               get('df,'kvalue))
                          then <<w := mksq(w,1);
                                 x := cddr u;
                                 while x do
                                   <<if cdr x and numberp cadr x
                                         then <<for i := 1:cadr x do
                                                   w := diffsq(w,car x);
                                                x := cdr x>>
                                       else w := diffsq(w,car x);
                                      x := cdr x>>;
                                 go to e>>
                       else w := 'df . cadr u . derad(v,cddr u)
                else return nil ./ 1
         else if depends(u,v) then w := list('df,u,v)
         else return nil ./ 1;
    j:  w := if x := opmtch w then simp x else mksq(w,1);
        go to e
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
          then rederr list("Incompatible DF rule argument length for",
                           caadr x);
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


module subs2q;  % Routines for substituting for powers.

% Author: Anthony C. Hearn.

% Copyright (c) 1987 The RAND Corporation. All rights reserved.

fluid '(!*mcd !*structure !*sub2 alglist!* dmode!*);

global '(!*resubs frlis!* powlis!* powlis1!* simpcount!*
         simplimit!*);

comment If STRUCTURE is ON, then expressions like (a**(b/2))**2 are not
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
                rederr "Simplification recursion too deep">>;
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
         else if eval subla(car x,bool) then go to b;
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
   begin scalar x;
        if u=v then return list nil
         else if not (x:= mchk!*(car u,car v)) then return nil
         else if cdr v memq frlis!*
          then if cdr u=1 then return nil
             % do not match a free power to 1
                else return mapcons(x,cdr v . cdr u)
         else if (flg and not cdr u=cdr v)
                or (if !*mcd then cdr u<cdr v
                     else (cdr u*cdr v)<0 or
                        %implements explicit sign matching;
                            abs cdr u<abs cdr v)
          then return nil
         else return x
   end;

symbolic procedure mchk!*(u,v);
   begin scalar x;
      if x := mchk(u,v) then return x
       else if !*mcd or not (sfp u and sfp v) then return nil
       else return mchk(prepf u,prepf v)
   end;

endmodule;


module subs3q; % Routines for matching products.

% Author: Anthony C. Hearn.

% Copyright (c) 1987 The RAND Corporation. All rights reserved.

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
        w:= if atom caar x or sfp caar x then caar x else revop1 caar x;
        % In the non-commutative case we have to be very careful about
        % order of terms in a product. Introducing negative powers
        % solves this problem.
        if noncomp w or not !*mcd then bool := t;
        z := list(mksp(w,if null bool then cdar x else -cdar x) . z);
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
         else if eval subla(car x,cdadr v1) then return list y;
        x := cdr x;
        go to b;
    c:  if null flg then <<w := cdr w; go to a>>
         else if cadddr v1 and nocp w then go to e;
    d:  z := append(z,list v1);
    e:  v := cdr v;
        go to a0
   end;

symbolic procedure nocp u;
   null u or (noncomp caar u and nocp cdr u);

endmodule;


module extout; % Extended output package for expressions.

% Author: Anthony C. Hearn.

% Copyright (c) 1987 The RAND Corporation. All rights reserved.

fluid '(!*mcd kord!*);

global '(!*allfac
         !*div
         !*pri
         !*rat
         dnl!*
         factors!*
         ordl!*
         upl!*
         wtl!*);

switch allfac,div,pri,rat;

!*allfac := t;          %factoring option for this package;
!*pri := t;             %to activate this package;

% dnl!* := nil;         %output control flag: puts powers in denom;
% factors!* := nil;     %list of output factors;
% ordl!* := nil;        %list of kernels introduced by ORDER statement;
% upl!* := nil;         %output control flag: puts denom powers in
                        %numerator;
% !*div := nil;         %division option in this package;
% !*rat := nil;         %flag indicating rational mode for output;


symbolic procedure factor u;
   factor1(u,t,'factors!*);

symbolic procedure factor1(u,v,w);
   begin scalar x,y;
        y := eval w;
        for each j in u do
         <<x := !*a2k j;
           if v then y := aconc!*(delete(x,y),x)
            else if not x member y
             then msgpri(nil,j,"not found",nil,nil)
            else y := delete(x,y)>>;
        set(w,y)
   end;

symbolic procedure remfac u;
   factor1(u,nil,'factors!*);

rlistat '(factor remfac);

symbolic procedure order u;
   <<rmsubs();   % Since order of terms in an operator argument can
                 % affect simplification.
     if u and null car u and null cdr u then (ordl!* := nil)
      else for each x in u do
        <<if (x := !*a2k x) member ordl!*
            then ordl!* := delete(x,ordl!*);
          ordl!* := aconc!*(ordl!*,x)>>>>;

rlistat '(order);

symbolic procedure up u;
   factor1(u,t,'upl!*);

symbolic procedure down u;
   factor1(u,t,'dnl!*);

% RLISTAT '(UP DOWN);  % omitted since not documented;

symbolic procedure formop u;
   if domainp u then u
    else raddf(multop(lpow u,formop lc u),formop red u);

symbolic procedure multop(u,v);
   if null kord!* then multpf(u,v)
    else if car u eq 'k!* then v
    else rmultpf(u,v);

symbolic smacro procedure lcx u;
   %returns leading coefficient of a form with zero reductum, or an
   %error otherwise;
   cdr carx(u,'lcx);

symbolic procedure quotof(p,q);
   %P is a standard form, Q a standard form which is either a domain
   %element or has zero reductum.
   %returns the quotient of P and Q for output purposes;
   if null p then nil
    else if p=q then 1
    else if q=1 then p
    else if domainp q then quotofd(p,q)
    else if domainp p
     then mksp(mvar q,-ldeg q) .* quotof(p,lcx q) .+ nil
    else (lambda (x,y);
          if car x eq car y
              then (lambda (n,w,z);
                 if n=0 then raddf(w,z)
                  else ((car y .** n) .* w) .+ z)
              (cdr x-cdr y,quotof(lc p,lcx q),quotof(red p,q))
           else if ordop(car x,car y)
              then (x .* quotof(lc p,q)) .+ quotof(red p,q)
           else mksp(car y,- cdr y) .* quotof(p,lcx q) .+ nil)
       (lpow p,lpow q);

symbolic procedure quotofd(p,q);
   %P is a form, Q a domain element. Value is quotient of P and Q
   %for output purposes;
   if null p then nil
    else if domainp p then quotodd(p,q)
    else (lpow p .* quotofd(lc p,q)) .+ quotofd(red p,q);

symbolic procedure quotodd(p,q);
   %P and Q are domain elements. Value is domain element for P/Q;
   if atom p and atom q then mkrn(p,q) else lowest!-terms(p,q);

symbolic procedure lowest!-terms(u,v);
   %reduces compatible domain elements U and V to a ratio in lowest
   %terms.  Value as a rational may contain domain arguments rather than
   %just integers;
   if u=v then 1
    else if flagp(dmode!*,'field) or not atom u and flagp(car u,'field)
       or not atom v and flagp(car v,'field)
     then multdm(u,!:recip v)
     else begin scalar x;
      x := dcombine!*(u,v,'gcd);
      u := dcombine!*(u,x,'quotient);
      v := dcombine!*(v,x,'quotient);
      return if v=1 then u else '!:rn!: . (u . v)    % :ONEP
   end;

symbolic procedure dcombine!*(u,v,w);
   if atom u and atom v then apply2(w,u,v) else dcombine(u,v,w);

symbolic procedure ckrn u;
   if flagp(dmode!*,'field)
     then begin scalar x;
       x := lnc u;
       return multf(x,ckrn1 quotfd(u,x))
      end
    else ckrn1 u;

symbolic procedure ckrn1 u;
   begin scalar x;
        if domainp u then return u;
    a:  x := gck2(ckrn1 cdar u,x);
        if null cdr u
          then return if noncomp mvar u then x else list(caar u . x)
         else if domainp cdr u or not caaar u eq caaadr u
          then return gck2(ckrn1 cdr u,x);
        u := cdr u;
        go to a
   end;

symbolic procedure gck2(u,v);
   %U and V are domain elements or forms with a zero reductum.
   %Value is the gcd of U and V;
   if null v then u
    else if u=v then u
    else if domainp u
     then if domainp v then if flagp(dmode!*,'field) then 1
                             else gcddd(u,v)
        else gck2(u,cdarx v)
    else if domainp v then gck2(cdarx u,v)
    else (lambda (x,y);
        if car x eq car y
          then list((if cdr x>cdr y then y else x) .
                    gck2(cdarx u,cdarx v))
         else if ordop(car x,car y) then gck2(cdarx u,v)
         else gck2(u,cdarx v))
    (caar u,caar v);

symbolic procedure cdarx u;
   cdr carx(u,'cdar);

symbolic procedure prepsq!* u;
   begin scalar x;
        if null numr u then return 0
         else if minusf numr u
          then return list('minus,prepsq!*(negf numr u ./ denr u));
        x := kord!*;
        kord!* := append((for each j in factors!*
                     join if not idp j then nil
                           else for each k in get(j,'klist)
                                     collect car k),
                   append(factors!*,ordl!*));
        if kord!* neq x or wtl!*
          then u := formop numr u . formop denr u;
        u := if !*rat or (not flagp(dmode!*,'field) and !*div)
                      or upl!* or dnl!*
               then replus prepsq!*1(numr u,denr u,nil)
              else sqform(u,function(lambda j;
                            replus prepsq!*1(j,1,nil)));
        kord!* := x;
        return u
   end;

symbolic procedure prepsq!*0(u,v);
   %U is a standard quotient, but not necessarily in lowest terms.
   %V a list of factored powers;
   %Value is equivalent list of prefix expressions (an implicit sum);
   begin scalar x;
      return if null numr u then nil
              else if (x := gcdf(numr u,denr u)) neq 1
        then prepsq!*1(quotf(numr u,x),quotf(denr u,x),v)
       else prepsq!*1(numr u,denr u,v)
   end;

symbolic procedure prepsq!*1(u,v,w);
   %U and V are the numerator and denominator expression resp,
   %in lowest terms.
   %W is a list of powers to be factored from U;
   begin scalar x,y,z;
        %look for "factors" in the numerator;
        if not domainp u and (mvar u member factors!* or (not
                atom mvar u and car mvar u member factors!*))
          then return nconc!*(
               if v=1 then prepsq!*0(lc u ./ v,lpow u . w)
                else (begin scalar n,v1,z1;
                %see if the same "factor" appears in denominator;
                n := ldeg u;
                v1 := v;
                z1 := !*k2f mvar u;
                while (z := quotfm(v1,z1)) do <<v1 := z; n := n-1>>;
                return
                  prepsq!*0(lc u ./ v1,
                            if n>0 then (mvar u .** n) . w
                             else if n<0
                              then mksp(list('expt,mvar u,n),1) . w
                             else w)
                   end),
                        prepsq!*0(red u ./ v,w));
        %now see if there are any remaining "factors" in denominator
        %(KORD!* contains all potential kernel factors);
        if not domainp v
         then for each j in kord!* do
           begin integer n; scalar z1;
                n := 0;
                z1 := !*k2f j;
                while z := quotfm(v,z1) do <<n := n-1; v := z>>;
                if n<0 then w := mksp(list('expt,j,n),1) . w
           end;
        %now all "factors" have been removed;
        if kernlp u then <<u := mkkl(w,u); w := nil>>;
        if dnl!*
          then <<x := if null !*allfac then 1 else ckrn u;
                 z := ckrn!*(x,dnl!*);
                 x := quotof(x,z);
                 u := quotof(u,z);
                 v := quotof(v,z)>>;
        y := ckrn v;
        if upl!*
          then <<z := ckrn!*(y,upl!*);
                 y := quotof(y,z);
                 u := quotof(u,z);
                 v := quotof(v,z)>>;
        if null !*div then y := 1;
        u := canonsq (u . quotof(v,y));
%       if !*gcd then u := cancel u;
        u := quotof(numr u,y) ./ denr u;
        if null !*allfac then x := 1 else x := ckrn numr u;
        if null x then x := 1;
        % Probably means a large float whose inverse appears as 0.
        if !*allfac and x neq car u then go to b
         else if w then <<w := exchk w; go to c>>;
    d:  u := prepsq u;
        return if eqcar(u,'plus) then cdr u else list u;
    b:  if x=1 and null w then go to d;   % ONEP
        u := quotof(numr u,x) ./ denr u;
        w := prepf mkkl(w,x);
        if u = (1 ./ 1) then return list w
         else if eqcar(w,'times) then w := cdr w
         else w := list w;
    c:  return list retimes aconc!*(w,prepsq u)
   end;

symbolic procedure ckrn!*(u,v);
   if null u then errach 'ckrn!*
    else if domainp u then 1
    else if caaar u member v
       then list (caar u . ckrn!*(cdr carx(u,'ckrn),v))
    else ckrn!*(cdr carx(u,'ckrn),v);

symbolic procedure mkkl(u,v);
   if null u then v else mkkl(cdr u,list (car u . v));

symbolic procedure quotfm(u,v);
   begin scalar !*mcd; !*mcd := t; return quotf(u,v) end;

endmodule;


module depend; % Defining and checking expression dependency.

% Author: Anthony C. Hearn.

% Copyright (c) 1987 The RAND Corporation. All rights reserved.

global '(depl!* frlis!*);

% DEPL* is a list of dependencies among kernels;

symbolic procedure depend u;
   for each x in cdr u do depend1(car u,x,t);

symbolic procedure nodepend u;
   <<rmsubs(); for each x in cdr u do depend1(car u,x,nil)>>;

rlistat '(depend nodepend);

symbolic procedure depend1(u,v,bool);
   begin scalar y,z;
      u := !*a2k u;
      v := !*a2k v;
      if u eq v then return nil;
      y := assoc(u,depl!*);
%     if y then if bool then rplacd(y,union(list v,cdr y))
%                else if (z := delete(v,cdr y)) then rplacd(y,z)
      if y then if bool
                 then depl!*:= repasc(car y,union(list v,cdr y),depl!*)
                 else if (z := delete(v,cdr y))
                  then depl!* := repasc(car y,z,depl!*)
                 else depl!* := delete(y,depl!*)
       else if null bool
         then lprim list(u,"has no prior dependence on",v)
       else depl!* := list(u,v) . depl!*
   end;

symbolic procedure depends(u,v);
   if null u or numberp u or numberp v then nil
    else if u=v then u
    else if atom u and u memq frlis!* then t
      %to allow the most general pattern matching to occur;
    else if (lambda x; x and ldepends(cdr x,v)) assoc(u,depl!*)
     then t
    else if not atom u and idp car u and get(car u,'dname) then nil
    else if not atom u
      and (ldepends(cdr u,v) or depends(car u,v)) then t
    else if atom v or idp car v and get(car v,'dname) then nil
    % else dependsl(u,cdr v);
    else nil;

symbolic procedure ldepends(u,v);
   % Allow for the possibility that U is an atom.
   if null u then nil
    else if atom u then depends(u,v)
    else depends(car u,v) or ldepends(cdr u,v);

symbolic procedure dependsl(u,v);
   v and (depends(u,car v) or dependsl(u,cdr v));

symbolic procedure freeof(u,v);
   not(smember(v,u) or v member assoc(u,depl!*));

symbolic operator freeof;

flag('(freeof),'boolean);

% infix freeof;

% precedence freeof,lessp;   %put it above all boolean operators;

endmodule;


module str;  % Routines for structuring expressions.

% Author: Anthony C. Hearn.

% Copyright (c) 1987 The RAND Corporation. All rights reserved.

fluid '(scountr svar svarlis);

global '(!*fort !*nat !*savestructr varnam!*);

switch savestructr;

% ***** two essential uses of RPLACD occur in this module.

symbolic procedure structr u;
   begin scalar scountr,fvar,svar,svarlis;
      %SVARLIS is a list of elements of form:
      %(<unreplaced expression> . <newvar> . <replaced exp>);
      scountr :=0;
      fvar := svar := varnam!*;
      if cdr u
        then <<fvar := svar := cadr u; if cddr u then fvar := caddr u>>;
      u := aeval car u;
      if flagpcar(u,'struct)
        then u := car u .
           (for each j in cdr u collect for each k in j collect
                                 struct!*sq k)
       else if getrtype u then typerr(u,"STRUCTR argument")
       else u := struct!*sq u;
      if null !*fort
        then <<varpri(u,nil,'only);
               if not flagpcar(u,'struct) then terpri();
               if scountr=0 then return nil
                else <<if null !*nat then terpri();
                       prin2t "   where">>>>
       else svarlis := reversip!* svarlis;
      for each x in svarlis do
         <<terpri!* t;
           if null !*fort then prin2!* "      ";
             varpri(cddr x,list('setq,cadr x,mkquote cddr x),t)>>;
      if !*fort then fvarpri(u,list fvar,t);
      if !*savestructr
        then <<if arrayp svar
                 then <<put(svar,'array,
                            mkarray(list(scountr+1),'algebraic));
                        put(svar,'dimension,list(scountr+1))>>;
               for each x in svarlis do
                  setk2(cadr x,mk!*sq !*k2q car x)>>
   end;

rlistat '(structr);

symbolic procedure setk2(u,v);
   if atom u then setk1(u,v,t) else setelv(u,v);

symbolic procedure struct!*sq u;
   if eqcar(u,'!*sq)
     then mk!*sq(structf numr cadr u ./ structf denr cadr u)
    else u;

symbolic procedure structf u;
   if null u then nil
    else if domainp u then u
    else begin scalar x,y;
        x := mvar u;
        if sfp x then if y := assoc(x,svarlis) then x := cadr y
                else x := structk(prepsq!*(structf x ./ 1),
                                  structvar(),x)
         else if not atom x and not atomlis cdr x
          then if y := assoc(x,svarlis) then x := cadr y
                else x := structk(x,structvar(),x);
        return x .** ldeg u .* structf lc u .+ structf red u
     end;

symbolic procedure structk(u,id,v);
   begin scalar x;
      if x := subchk1(u,svarlis,id)
        then rplacd(x,(v . id . u) . cdr x)
       else if x := subchk2(u,svarlis)
        then svarlis := (v . id . x) . svarlis
       else svarlis := (v . id . u) . svarlis;
      return id
   end;

symbolic procedure subchk1(u,v,id);
   begin scalar w;
      while v do
       <<smember(u,cddar v)
            and <<w := v; rplacd(cdar v,subst(id,u,cddar v))>>;
         v := cdr v>>;
      return w
   end;

symbolic procedure subchk2(u,v);
   begin scalar bool;
      for each x in v do
       smember(cddr x,u)
          and <<bool := t; u := subst(cadr x,cddr x,u)>>;
      if bool then return u else return nil
   end;

symbolic procedure structvar;
   begin
      scountr := scountr + 1;
      return if arrayp svar then list(svar,scountr)
       else intern compress append(explode svar,explode scountr)
   end;

endmodule;


module coeff;  % Routines for finding coefficients of forms.

% Author: Anthony C. Hearn.

% Modifications by: F. Kako (including introduction of COEFFN).

% Copyright (c) 1987 The RAND Corporation. All rights reserved.

global '(!*ratarg hipow!* lowpow!* wtl!*);

switch ratarg;

flag ('(hipow!* lowpow!*),'share);

symbolic procedure coeffeval u;
   begin integer n;
      n := length u;
      if n<2 or n>3
        then rederr "COEFF called with wrong number of arguments"
       else return coeff1(car u,cadr u,
                         if null cddr u then nil else caddr u)
      end;

put('coeff,'psopfn,'coeffeval);

symbolic procedure coeff1(u,v,w);
   % Finds the coefficients of V in U and returns results in W;
   begin scalar bool,x,y,z;
        v := !*a2k v;
        u := simp!* u;
        bool := !*ratarg or freeof(prepf denr u,v);
        if null bool then u := !*q2f u;
        x := setkorder list v;
        if null bool then <<y := reorder u; u := 1>>
         else <<y := reorder numr u; u := denr u>>;
        setkorder x;
        if null y then go to a;
        while not domainp y and mvar y=v
           do <<z := (ldeg y . !*ff2a(lc y,u)) . z; y := red y>>;
        if null y then go to b;
    a:  z := (0 . !*ff2a(y,u)) . z;
    b:  lowpow!* := caar z;
        z := reverse z;
        hipow!* := caar z;
        z := multiple!-result(z,w);
        return if null w then z else hipow!*
   end;

symbolic procedure coeffn(u,v,n);
   % Returns n-th coefficient of U.
   begin scalar bool,x,y;
      n := reval n;
      if not fixp n or minusp n then typerr(n,"COEFFN index");
      v := !*a2k v;
      u := simp!* u;
      bool := !*ratarg or freeof(prepf denr u,v);
      if null bool then u := !*q2f u;
      x := setkorder list v;
      if null bool then <<y := reorder u; u := 1>>
       else <<y := reorder numr u; u := denr u>>;
      setkorder x;
      if null y then return nil;
   b: if domainp y or mvar y neq v
        then return if n=0 then !*ff2a(y,u) else 0
       else if n=ldeg y then return !*ff2a(lc y,u)
       else if n>ldeg y then return 0
       else <<y := red y; go to b>>
   end;

flag('(coeffn),'opfn);

flag('(coeffn),'noval);

endmodule;


module weight; % Asymptotic command package.

% Author: Anthony C. Hearn.

% Copyright (c) 1987 The RAND Corporation. All rights reserved.

fluid '(asymplis!*);

global '(wtl!*);

flag('(k!*),'reserved);

% Asymptotic list and weighted variable association lists.

symbolic procedure weight u;
   begin scalar y,z;
        rmsubs();
        for each x in u do
           if not eqexpr x then errpri2(x,'hold)
            else <<y := !*a2k cadr x;
                   z := reval caddr x;
                   if not (numberp z and fixp z and z>0)
                     then typerr(z,"weight");
                   wtl!* :=  (y . z) . delasc(y,wtl!*)>>
   end;

symbolic procedure wtlevel u;
   begin integer n; scalar x;
        n := reval car u;
        if not(numberp n and fixp n and not n<0)
          then errpri2(n,'hold);
        n := n+1;
        x := atsoc('k!*,asymplis!*);
        if n=cdr x then return nil else if n<=cdr x then rmsubs();
        asymplis!* := ('k!* . n) . delasc('k!*,asymplis!*)
   end;

rlistat '(weight wtlevel);

algebraic let k!***2=0;

endmodule;


module linop; % Linear operator package.

% Author: Anthony C. Hearn.

% Copyright (c) 1987 The RAND Corporation. All rights reserved.

fluid '(!*intstr);

symbolic procedure linear u;
   for each x in u do
    if not idp x then typerr(x,'operator) else flag(list x,'linear);

rlistat '(linear);

put('linear,'simpfg,'((rmsubs)));

symbolic procedure formlnr u;
   begin scalar x,y,z;
      x := car u;
      if null cdr u or null cddr u
        then rederr list("Linear operator",
                         x,"called with too few arguments");
      y := cadr u;
      z := !*a2k caddr u . cdddr u;
      return if y = 1 then u
       else if not depends(y,car z)
        then list('times,y,x . 1 . z)
       else if atom y then u
       else if car y eq 'plus
        then 'plus . for each j in cdr y collect formlnr(x . j. z)
       else if car y eq 'minus
        then list('minus,formlnr(x . cadr y . z))
       else if car y eq 'difference
        then list('difference,formlnr(x . cadr y . z),
                              formlnr(x . caddr y . z))
       else if car y eq 'times then formlntms(x,cdr y,z,u)
       else if car y eq 'quotient then formlnquot(x,cdr y,z,u)
       else if car y eq 'recip and not depends(cadr y,car z)
        then list('quotient,x . 1 . z,cadr y)
       else if y := expt!-separate(y,car z)
        then list('times,car y,x . cdr y . z)
       else u
   end;

symbolic procedure formseparate(u,v);
   %separates U into two parts, and returns a dotted pair of them: those
   %which are not commutative and do not depend on V, and the remainder;
   begin scalar w,x,y;
      for each z in u do
        if not noncomp z and not depends(z,v) then x := z . x
         else if (w := expt!-separate(z,v))
        then <<x := car w . x; y := cdr w . y>>
         else y := z . y;
      return reversip!* x . reversip!* y
   end;

symbolic procedure expt!-separate(u,v);
   %determines if U is an expression in EXPT that can be separated into
   %two parts, one that does not depend on V and one that does,
   %except if there is no non-dependent part, NIL is returned;
   if not eqcar(u,'expt) or depends(cadr u,v)
           or not eqcar(caddr u,'plus)
     then nil
    else expt!-separate1(cdaddr u,cadr u,v);

symbolic procedure expt!-separate1(u,v,w);
   begin scalar x;
      x := formseparate(u,w);
      return if null car x then nil
              else list('expt,v,replus car x) .
                   if null cdr x then 1 else list('expt,v,replus cdr x)
   end;

symbolic procedure formlntms(u,v,w,x);
   %U is a linear operator, V its first argument with TIMES removed,
   %W the rest of the arguments and X the whole expression.
   %Value is the transformed expression;
   begin scalar y;
      y := formseparate(v,car w);
      return if null car y then x
              else 'times . aconc!*(car y,
                if null cddr y then formlnr(u . cadr y . w)
                      else u . ('times . cdr y) . w)
   end;

symbolic procedure formlnquot(fn,quotargs,rest,whole);
   %FN is a linear operator, QUOTARGS its first argument with QUOTIENT
   %removed, REST the remaining arguments, WHOLE the whole expression.
   %Value is the transformed expression;
   begin scalar x;
      return if not depends(cadr quotargs,car rest)
         then list('quotient,formlnr(fn . car quotargs . rest),
                   cadr quotargs)
        else if not depends(car quotargs,car rest)
               and car quotargs neq 1
         then list('times,car quotargs,
                   formlnr(fn . list('recip,cadr quotargs) . rest))
        else if eqcar(car quotargs,'plus)
         then 'plus . for each j in cdar quotargs
                collect formlnr(fn . ('quotient . j . cdr quotargs)
                                 . rest)
        else if eqcar(car quotargs,'minus)
         then list('minus,formlnr(fn .
                        ('quotient . cadar quotargs . cdr quotargs)
                            . rest))
        else if eqcar(car quotargs,'times)
                and car(x := formseparate(cdar quotargs,car rest))
         then 'times . aconc!*(car x,
                formlnr(fn . list('quotient,mktimes cdr x,
                             cadr quotargs) . rest))
        else if eqcar(cadr quotargs,'times)
                and car(x := formseparate(cdadr quotargs,car rest))
         then list('times,list('recip,mktimes car x),
                formlnr(fn . list('quotient,car quotargs,mktimes cdr x)
                         . rest))
        else if x := expt!-separate(car quotargs,car rest)
         then list('times,car x,formlnr(fn . list('quotient,cdr x,cadr
                                                     quotargs) . rest))
        else if x := expt!-separate(cadr quotargs,car rest)
         then list('times,list('recip,car x),
                   formlnr(fn . list('quotient,car quotargs,cdr x)
                              . rest))
        else if (x := reval!* cadr quotargs) neq cadr quotargs
         then formlnquot(fn,list(car quotargs,x),rest,whole)
        else whole
   end;

symbolic procedure mktimes u;
   if null cdr u then car u else 'times . u;

symbolic procedure reval!* u;
   %like REVAL, except INTSTR is always ON;
   begin scalar !*intstr;
      !*intstr := t;
      return reval u
   end;

endmodule;


module polyop; % Functions for algebraic mode operations on polynomials.

% Author: Anthony C. Hearn.

% Modified by: F. Kako.

% Copyright (c) 1987 The RAND Corporation. All rights reserved.

global '(!*ratarg);

symbolic procedure deg(u,kern);
   begin scalar x,y;
      u := simp!* u;
      y := denr u;
      tstpolyarg(y,u);
      u := numr u;
      kern := !*a2k kern;
      if domainp u then return 0
       else if mvar u eq kern then return !*f2a ldeg u;
      x := setkorder list kern;
      u := reorder u;
      if not(mvar u eq kern) then u := nil else u := ldeg u;
      setkorder x;
      return !*f2a u
   end;

symbolic procedure lcof(u,kern);
   begin scalar x,y;
      u := simp!* u;
      y := denr u;
      tstpolyarg(y,u);
      u := numr u;
      kern := !*a2k kern;
      if domainp u then return u
       else if mvar u eq kern
        then return !*ff2a(lc u,y);
      x := setkorder list kern;
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
      if domainp u then return nil
       else if mvar u eq kern
        then return !*ff2a(lt u .+ nil,y);
      x := setkorder list kern;
      u := reorder u;
      if not(mvar u eq kern) then u := nil
       else u := lt u .+ nil;
      setkorder x;
      u := reorder u;
      return if null u then 0 else !*ff2a(u,y)
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
      x := setkorder list kern;
      u := reorder u;
      if mvar u eq kern then u := cdr u else u := nil;
      setkorder x;
      u := reorder u;
      return !*ff2a(u,y)
   end;

symbolic procedure tstpolyarg(y,u);
   null !*ratarg and y neq 1 and typerr(prepsq u,"polynomial");

symbolic operator deg,lcof,lterm,mainvar,reduct;

endmodule;


module elem; % Simplification rules for elementary functions.

% Author: Anthony C. Hearn.

% Copyright (c) 1987 The RAND Corporation. All rights reserved.

fluid '(!*!*sqrt !*keepsqrts);

global '(e!-value!* pi!-value!* subfg!*);

% No references to RPLAC-based functions in this module.

algebraic;

comment RULE FOR I**2;

remflag('(i),'reserved);

let i**2= -1;

flag('(e i nil pi t),'reserved);

comment LOGARITHMS;

operator log;

let log(e)= 1,
    log(1)= 0;

for all x let log(e**x)=x;

% The next set of rules are not implemented yet.

%for all x,y let log(x*y) = log x + log y, log(x/y) = log x - log y;

for all x let df(log(x),x) = 1/x;

comment TRIGONOMETRICAL FUNCTIONS;

symbolic procedure simptrig u;
   % This is a basic simplification function for trigonometrical
   % functions. The prefix expression U is of the form (<trig-function>
   %  <argument>). It is assumed that the trig-function is either even
   % or odd, with even the default (and the odd case a flag "odd").
   % The value is a standard quotient for the simplified expression.
   % Note: we must use PREPSQXX and not PREPSQ* here, since the REVOP1
   % in SUBS3T uses PREPSQXX, and terms must be consistent to prevent a
   % loop in the pattern matcher.
   begin scalar bool,fn,x,z;
      fn := car u;
      u := cdr u;
      if null u or cdr u
        then rederr list("Wrong number of arguments to",fn);
      u := simp!* car u;
      if null numr u and flagp(fn,'odd) and not flagp(fn,'nonzero)
        then return nil ./ 1;
      x := list(fn,prepsqxx u);
      if subfg!* and (z := opmtch x) then return simp z
       else if minusf numr u
          and (flagp(fn,'odd) and (bool := t)
               or flagp(fn,'even))
        then <<x := list(fn,prepsqxx(u := (negf numr u ./ denr u)));
               if subfg!* and (z := opmtch x)
                 then <<x := simp z;
                        return if bool then negsq x else x>>>>;
      if z := domainvalchk(fn,list u) then x := z
       else x := mksq(x,1);
      return if bool then negsq x else x
   end;

deflist('((acos simptrig) (asin simptrig) (atan simptrig)
          (acosh simptrig) (asinh simptrig) (atanh simptrig)
          (cos simptrig) (sin simptrig) (tan simptrig)
          (sec simptrig) (csc simptrig)
          (cot simptrig)(acot simptrig)(coth simptrig)(acoth simptrig)
          (cosh simptrig) (sinh simptrig) (tanh simptrig)
   ),'simpfn);

% The following declaration causes the simplifier to pass the full
% expression (including the function) to SIMPTRIG.

flag ('(acos asin atan acosh asinh atanh cos sin tan cosh sinh tanh
        csc sec cot acot coth acoth),
      'full);

flag('(asin atan asinh atanh sin tan csc sinh tanh cot coth),
      'odd);

flag('(cos sec cosh acosh),'even);

flag('(cot coth),'nonzero);

%flag('(asin atan asinh atanh sin tan sinh tanh cot acot coth acoth),
%      'odd);

%flag('(cos sec),'even);

%flag('(cot),'nonzero);

% In the following rules, it is not necessary to let f(0)=0, when f
% is odd, since SIMPTRIG already does this.

let cos(0)= 1,
    cos(pi/6)=sqrt 3/2,
    sin(pi/6)= 1/2,
    cos(pi/4)=sqrt 2/2,
    sin(pi/4)=sqrt 2/2,
    cos(pi/3) = 1/2,
    sin(pi/3) = sqrt(3)/2,
    cos(pi/2)= 0,
    sin(pi/2)= 1,
    sin(pi)= 0,
    cos(pi)=-1,
    cosh 0=1,
    acos(0)= pi/2,
    acos(1)=0;

for all x let cos acos x=x, sin asin x=x, tan atan x=x,
           cosh acosh x=x, sinh asinh x=x, tanh atanh x=x,
           cot acot x=x, coth acoth x=x;

for all x let acos(-x)=pi-acos(x);

for all n such that numberp n and fixp n
    let sin(n*pi)=0,
        cos(n*pi) = (-1)**n;

for all n such that numberp n and fixp n let cos((n*pi)/2)= 0;

for all n such that numberp n and fixp n
   let sin((n*pi)/2) = if remainder(abs n,4)<2 then 1 else -1;

for all n such that numberp n and fixp n
   let cos((n*pi)/3)= 
       (if n=4 or remainder(abs n+2,6)>3 then -1 else 1)/2;

for all n such that numberp n and fixp n
   let sin((n*pi)/3)=
        (if remainder(abs n,6)<3 then 1 else -1)*sqrt(3)/2;

for all n such that numberp n and fixp n
   let cos((n*pi)/4)=
       (if remainder(abs n+2,8)<4 then 1 else -1)*sqrt(2)/2;

for all n such that numberp n and fixp n
   let sin((n*pi)/4)=
        (if remainder(abs n,8)<4 then 1 else -1)*sqrt(2)/2;

for all n such that numberp n and fixp n
   let cos((n*pi)/6)=
        (if remainder(abs n+2,12)<6 then 1 else -1)*sqrt(3)/2;

for all n such that numberp n and fixp n
   let sin((n*pi)/6)=
        (if remainder(abs n,12)<6 then 1 else -1)/2;

% ***** Differentiation rules *****.

for all x let df(acos(x),x)= -sqrt(1-x**2)/(1-x**2),
              df(asin(x),x)= sqrt(1-x**2)/(1-x**2),
              df(atan(x),x)= 1/(1+x**2),
              df(acosh(x),x)= sqrt(x**2-1)/(x**2-1),
              df(asinh(x),x)= sqrt(x**2+1)/(x**2+1),
              df(atanh(x),x)= 1/(1-x**2),
              df(cos x,x)= -sin(x),
              df(sin(x),x)= cos(x),
              df(tan x,x)=1+tan x**2,
              df(sinh x,x)=cosh x,
              df(cosh x,x)=sinh x,
              df(tanh x,x)=1-tanh x**2,
              df(cot x,x)=-1-cot x**2,
              df(coth x,x)=1-coth x**2;

let   e**(i*pi/2) = i,
      e**(i*pi) = -1,
      e**(3*i*pi/2)=-i;

%for all x let e**log x=x;   % Requires every power to be checked.

for all x,y let df(x**y,x)= y*x**(y-1),
                df(x**y,y)= log x*x**y;

comment SQUARE ROOTS;

deflist('((sqrt simpsqrt)),'simpfn);

%for all x let sqrt x**2=x;

% !*!*sqrt:  used to indicate that SQRTs have been used.

% !*keepsqrts:  causes SQRT rather than EXPT to be used.

symbolic procedure mksqrt u;
   if not !*keepsqrts then list('expt,u,list('quotient,1,2))
    else <<if null !*!*sqrt then <<!*!*sqrt := t;
                              algebraic for all x let sqrt x**2=x>>;
      list('sqrt,u)>>;

for all x let df(sqrt x,x)=sqrt x/(2*x);

comment ERF, EXP, EXPINT AND DILOG;

operator erf,exp,expint,dilog;

let erf 0=0;

let dilog(0)=pi**2/6;

for all x let erf(-x)=-erf x;

for all x let df(erf x,x)=2*sqrt(pi)*e**(-x**2)/pi;

for all x let exp(x)=e**x;

for all x let df(expint(x),x)=e**x/x;

for all x let df(dilog x,x)=-log x/(x-1);

comment Supply missing argument and simplify 1/4 roots of unity;

let   e**(i*pi/2) = i,
      e**(i*pi) = -1,
      e**(3*i*pi/2)=-i;

symbolic;

% Floating point interface for elementary functions.
% Perhaps this belongs in the floating point module.        

deflist('((exp !*exp!*) (expt !*expt!*) (log !*log!*) (sin !*sin!*)
          (cos !*cos!*) (tan !*tan!*) (asin !*asin!*) (acos !*acos!*)
          (atan !*atan!*) (sqrt !*sqrt!*) (e !*e!*) (pi !*pi!*)),
        '!:ft!:);

symbolic procedure !*acos!* u; mkfloat acos cdr u;

symbolic procedure !*asin!* u; mkfloat asin cdr u;

symbolic procedure !*atan!* u; mkfloat atan cdr u;

symbolic procedure !*cos!* u; mkfloat cos cdr u;

symbolic procedure !*exp!* u; mkfloat exp cdr u;

symbolic procedure !*expt!*(u,v);
   mkfloat if fixp v then expt(u,v) else exp(cdr v*log cdr u);

symbolic procedure !*log!* u; mkfloat log cdr u;

symbolic procedure !*sin!* u; mkfloat sin cdr u;

symbolic procedure !*tan!* u; mkfloat tan cdr u;

symbolic procedure !*e!*; mkfloat e!-value!*;

symbolic procedure !*pi!*; mkfloat pi!-value!*;

endmodule;


module nssimp;  % Simplification functions for non-scalar quantities.

% Author: Anthony C. Hearn.

% Copyright (c) 1987 The RAND Corporation. All rights reserved.

global '(!*div frlis!* subfg!*);

% Several inessential uses of ACONC, NCONC, and MAPping "JOIN". Latter
% not yet changed.

symbolic procedure nssimp(u,v);
   %U is a prefix expression involving non-commuting quantities.
   %V is the type of U.  Result is an expression of the form
   % SUM R(I)*PRODUCT M(I,J) where the R(I) are standard
   %quotients and the M(I,J) non-commuting expressions;
   %N. B: the products in M(I,J) are returned in reverse order
   %(to facilitate, e.g., matrix augmentation);
   begin scalar w,x,y,z;
        u := dsimp(u,v);
    a:  if null u then return z;
        w := car u;
    c:  if null w then go to d
         else if numberp car w
                or not(eqcar(car w,'!*div) or getrtype car w eq v)
          then x := aconc!*(x,car w)
         else y := aconc!*(y,car w);
        w := cdr w;
        go to c;
    d:  if null y then go to er;
    e:  z := addns(((if null x then 1 ./ 1 else simptimes x) . y),z);
        u := cdr u;
        x := y:= nil;
        go to a;
    er: y := v;
        if idp car x
          then if not flagp(car x,get(y,'fn)) then redmsg(car x,y)
            else rederr list(y,x,"not set")
         else if w := get(get(y,'tag),'i2d)
          then <<y := list apply1(w,1); go to e>>
         %to allow a scalar to be a 1 by 1 matrix;
         else msgpri(list("Missing",y,"in"),car x,nil,nil,t);
        put(car x,y,y);
        y := list car x;
        x := cdr x;
        go to e
   end;

symbolic procedure dsimp(u,v);
   %result is a list of lists representing a sum of products;
   %N. B: symbols are in reverse order in product list;
   if numberp u then list list u
    else if atom u
     then (if x and subfg!* then dsimp(x,v)
            else if flagp(u,'share) then dsimp(eval u,v)
            else <<flag(list u,'used!*); list list u>>)
      where x= get(u,'rvalue)
    else if car u eq 'plus
     then for each j in cdr u join dsimp(j,v)
    else if car u eq 'difference
     then nconc!*(dsimp(cadr u,v),
                dsimp('minus . cddr u,v))
    else if car u eq 'minus
     then dsimptimes(list(-1,carx(cdr u,'dsimp)),v)
    else if car u eq 'times then dsimptimes(cdr u,v)
    else if car u eq 'quotient
     then dsimptimes(list(cadr u,list('recip,carx(cddr u,'dsimp))),v)
    else if not getrtype u eq v then list list u
    else if car u eq 'recip
     then list list list('!*div,carx(cdr u,'dsimp))
    else if car u eq 'expt then (lambda z;
       if not numberp z or not fixp z then errpri2(u,t)
        else if z<0
         then list list list('!*div,'times . nlist(cadr u,-z))
         else if z=0 then list list list('!*div,cadr u,1)
        else dsimptimes(nlist(cadr u,z),v))
      reval caddr u
    else if flagp!*!*(car u,'noncommuting) then list list u
    else if arrayp car u
       then dsimp(getelv u,v)
    else (lambda x; if x then dsimp(x,v)
                     else (lambda y; if y then dsimp(y,v)
                                          else list list u)
                                opmtch revop1 u)
        opmtch u;

symbolic procedure dsimptimes(u,v);
   if null u then errach 'dsimptimes
    else if null cdr u then dsimp(car u,v)
    else (lambda j;
          for each k in dsimptimes(cdr u,v) join mappend(j,k))
       dsimp(car u,v);

symbolic procedure addns(u,v);
   if null v then list u
    else if cdr u=cdar v
       then (lambda x; % if null car x then cdr v else;
                         (x . cdr u) . cdr v)
       addsq(car u,caar v)
    else if ordp(cdr u,cdar v) then u . v
    else car v . addns(u,cdr v);

symbolic procedure getelx u;
   %to take care of free variables in LET statements;
   if smemqlp(frlis!*,cdr u) then nil
    else if null(u := getelv u) then 0
    else reval u;

endmodule;


module camlsp; % Definitions needed to run Cambridge LISP modules
               % supported in REDUCE under Standard LISP.

% Author: Anthony C. Hearn.

% Copyright (c) 1987 The RAND Corporation. All rights reserved.

% remprop('error,'newnam);

% putd('!%error,'expr,cdr getd 'error);

% symbolic macro procedure !%error u;
%   if null cddr u then list('error,50,cadr u) else 'error . cdr u;

% put('error,'newnam,'!%error);

% remprop('errorset,'newnam);

% putd('!%errorset,'expr,cdr getd 'errorset);

% symbolic macro procedure !%errorset u;
%    if null cdddr u then list('errorset,cadr u,caddr u,'!*backtrace)
%     else 'errorset . cdr u;

% put('errorset,'newnam,'!%errorset);

smacro procedure gcd(u,v); gcdn(u,v);

% symbolic smacro procedure gensym1 u; gensym();

symbolic smacro procedure iadd1 u; add1 u;

infix iequal;

symbolic smacro procedure u iequal v; eqn(u,v);

infix irem;

symbolic smacro procedure u irem v; remainder(u,v);

symbolic smacro procedure isub1 u; sub1 u;

symbolic procedure printc u; prin2t u;
   % Cannot be smacro because of FUNCTION PRINTC in INTBASISREDUCTION
   % and NORMALBASIS in full integrator.

symbolic smacro procedure readclock; time();

symbolic smacro procedure reversewoc u; reversip u;

symbolic smacro procedure princ u; prin2 u;

symbolic procedure superprint u; prettyprint u;
   % Cannot be smacro because of FUNCTION SUPERPRINT in COATESMATRIX
   % and JHDSOLVE.

symbolic smacro procedure unglobal u; nil;

comment The following three smacros can be used if there is a reason
for not using actual vectors;

%smacro procedure mkvect n; %mknill(n+1);

%smacro procedure putv(u,n,v); %car rplaca(pnth(u,n+1),v);

%smacro procedure getv(u,n); %nth(u,n+1);

endmodule;


module part;  % Access and updates parts of an algebraic expression.

% Author: Anthony C. Hearn.

% Copyright (c) 1987 The RAND Corporation. All rights reserved.

symbolic procedure revalpart u;
   begin scalar !*intstr,expn,v;
      !*intstr := t;   % To make following result in output form.
      expn := reval car u;
      !*intstr := nil;
      v := cdr u;
      while v do
         begin scalar x,y;
           if atom expn then parterr(expn,car v)
            else if not numberp(x := reval car v)
             then msgpri("Invalid argument",car v,"to part",nil,t)
            else if x=0
             then return <<expn := car expn; v := nil>>
            else if x<0 then <<x := -x; y := reverse cdr expn>>
            else y := cdr expn;
           if length y<x then parterr(expn,car v)
            else expn := nth(y,x);
       v := cdr v
     end;
      return expn
   end;

put('part,'psopfn,'revalpart);

symbolic procedure revalsetpart u;
   %Simplifies a SETPART expression;
   begin scalar !*intstr,x,y;
      x := reverse cdr u;
      !*intstr := t;
      y := reval car u;
      !*intstr := nil;
      return  revalsetp1(y,reverse cdr x,reval car x)
   end;

symbolic procedure revalsetp1(expn,ptlist,rep);
   if null ptlist then rep
    else if atom expn
             then msgpri("Expression",expn,
                         "does not have part",car ptlist,t)
    else begin scalar x;
      if not numberp(x := reval car ptlist)
             then msgpri("Invalid argument",car ptlist,"to part",nil,t)
       else return 
        if x=0 then rep . cdr expn
         else if x<0
          then car expn . 
                reverse ssl(reverse cdr expn,
                            -x,cdr ptlist,rep,expn . car ptlist)
         else car expn . ssl(cdr expn,x,cdr ptlist,
                             rep,expn . car ptlist)
   end;

symbolic procedure ssl(expn,indx,ptlist,rep,rest);
   if null expn
     then msgpri("Expression",car rest,"does not have part",cdr rest,t)
    else if indx=1 then revalsetp1(car expn,ptlist,rep) . cdr expn
    else car expn . ssl(cdr expn,indx-1,ptlist,rep,rest);

put('part,'setqfn,'setpart!*);

put('setpart!*,'psopfn,'revalsetpart);

symbolic procedure arglength u;
   begin scalar !*intstr,x;
      if null u then return 0;
      !*intstr := t;
      x := reval u;
      return if atom x then -1 else length cdr x
   end;

flag('(arglength),'opfn);

flag('(arglength),'noval);

endmodule;


end;
