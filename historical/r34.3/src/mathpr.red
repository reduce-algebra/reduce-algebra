module mathpr;  % Header module for mathpr package.

% Author: Anthony C. Hearn.

create!-package('(mathpr mprint sqprint ratprin dfprin % prend specprin
                  fortpri),
                nil);

endmodule;


module mprint; % Basic output package for symbolic expressions.

% Authors: Anthony C. Hearn and Arthur C. Norman.

% Copyright (c) 1991 RAND.  All rights reserved.

fluid  '(!*fort
         !*list
         !*nat
         !*nosplit
         !*ratpri
         !*revpri
         bool!-functions!*
         obrkp!*
         overflowed!*
         orig!*
         outputhandler!*
         pline!*
         posn!*
         p!*!*
         testing!-width!*
         ycoord!*
         ymax!*
         ymin!*);

global '(!*eraise initl!* nat!*!* spare!*);

switch list,ratpri,revpri,nosplit;

% Global variables initialized in this section.

% SPARE!* should be set in the system dependent code module.

!*eraise := t;
!*nat := nat!*!* := t;
!*nosplit := t;            % Expensive, maybe??
obrkp!* := t;
orig!*:=0;
posn!* := 0;
ycoord!* := 0;
ymax!* := 0;
ymin!* := 0;

initl!* := append('(orig!* pline!*),initl!*);

put('orig!*,'initl,0);

flag('(linelength),'opfn);  %to make it a symbolic operator;

symbolic procedure mathprint l;
   << terpri!* t;
      maprin l;
      terpri!* t >>;

symbolic procedure maprin u;
   if outputhandler!* then apply2(outputhandler!*,'maprin,u)
    else if not overflowed!* then maprint(u,0);

symbolic procedure maprint(l,p!*!*);
   % Print expression l at bracket level p!*!* without terminating
   % print line.  Special cases are handled by:
   %    pprifn: a print function that includes bracket level as 2nd arg.
   %     prifn: a print function with one argument.
   begin scalar p,x,y;
        p := p!*!*;     % p!*!* needed for (expt a (quotient ...)) case.
        if null l then return nil
         else if atom l
          then <<if not numberp l or (not l<0 or p<=get('minus,'infix))
                   then prin2!* l
                  else <<prin2!* "("; prin2!* l; prin2!* ")">>;
                 return l >>
         else if not atom car l then maprint(car l,p)
         else if ((x := get(car l,'pprifn)) and
                   not(apply2(x,l,p) eq 'failed)) or
                 ((x := get(car l,'prifn)) and
                   not(apply1(x,l) eq 'failed))
          then return l
         else if x := get(car l,'infix) then <<
           p := not x>p;
           if p then <<
             y := orig!*;
             prin2!* "(";
             orig!* := if posn!*<18 then posn!* else orig!*+3 >>;
% (expt a b) was dealt with using a pprifn sometime earlier than this
           inprint(car l,x,cdr l);
           if p then <<
              prin2!* ")";
              orig!* := y >>;
           return l >>
         else prin2!* car l;
        prin2!* "(";
        obrkp!* := nil;
        y := orig!*;
        orig!* := if posn!*<18 then posn!* else orig!*+3;
        if cdr l then inprint('!*comma!*,0,cdr l);
        obrkp!* := t;
        orig!* := y;
        prin2!* ")";
        return l
    end;

symbolic procedure exptpri(l,p);
% Prints expression in an exponent notation.
   begin scalar !*list,x,pp,q,w1,w2;
      if not !*nat or !*fort then return 'failed;
      pp := not((q:=get('expt,'infix))>p);  % Need to parenthesize
      w1 := cadr l;
      w2 := caddr l;
      if !*eraise and not atom w1 and
         (x := get(car w1, 'prifn)) and
         get(x, 'expt) = 'inbrackets then
% Special treatment here to avoid muddle between exponents and
% raised indices
            w1 := layout!-formula(w1, 0, 'inbrackets)
% Very special treatment for things that will be displayed with
% subscripts
       else if x = 'indexprin and not (indexpower(w1, w2)='failed)
         then return nil
       else w1 := layout!-formula(w1, q, nil);
      if null w1 then return 'failed;
      begin scalar !*ratpri;
% I do not display fractions with fraction bars in exponent
% expressions, since it usually seems excessive. Also (-p)/q gets
% turned into -(p/q) for printing here
         if eqcar(w2,'quotient) and eqcar(cadr w2,'minus)
          then w2 := list('minus,list(car w2,cadadr w2,caddr w2))
          else w2 := negnumberchk w2;
         w2 := layout!-formula(w2, if !*eraise then 0 else q, nil)
      end;
      if null w2 then return 'failed;
      l := cdar w1 + cdar w2;
      if pp then l := l + 2;
      if l > linelength nil - spare!* - orig!* then return 'failed;
      if l > linelength nil - spare!* - posn!* then terpri!* t;
      if pp then prin2!* "(";
      putpline w1;
      if !*eraise then l := 1 - cadr w2
       else << oprin 'expt; l := 0 >>;
      putpline ((update!-pline(0, l, caar w2) . cdar w2) .
                ((cadr w2 + l) . (cddr w2 + l)));
      if pp then prin2!* ")"
   end;

put('expt,'pprifn,'exptpri);

symbolic procedure inprint(op,p,l);
   begin scalar x,y;
        if op eq 'plus and !*revpri then l := reverse l;
           % print sum arguments in reverse order.
        if not get(op,'alt) then <<
          if op eq 'setq and not atom (x := car reverse l)
             and idp car x and (y := getrtype x)
             and (y := get(get(y,'tag),'setprifn))
            then return apply2(y,car l,x);
          if null atom car l and idp caar l
              and !*nat and
              ((x := get(caar l,'prifn)) or (x := get(caar l,'pprifn)))
              and (get(x,op) eq 'inbrackets)
            % to avoid mix up of indices and exponents.
            then<<prin2!* "("; maprint(car l,p); prin2!* ")">>
           else if !*nosplit and not testing!-width!* then
                prinfit(car l, p, nil)
           else maprint(car l, p);
          l := cdr l >>;
        if !*nosplit and not testing!-width!* then
% The code here goes to a certain amount of trouble to try to arrange
% that terms are never split across lines. This will slow
% printing down a bit, but I hope the improvement in formatting will
% be worth that.
              for each v in l do
               if atom v or not(op eq get(car v,'alt))
                then <<
% It seems to me that it looks nicer to put +, - etc on the second
% line, but := and comma usually look better on the first one when I
% need to split things.
                   if op memq '(setq !*comma!*) then <<
                      oprin op;
                      prinfit(negnumberchk v, p, nil) >>
                    else prinfit(negnumberchk v, p, op) >>
                else prinfit(v, p, nil)
         else for each v in l do <<
               if atom v or not(op eq get(car v,'alt))
                then <<oprin op; maprint(negnumberchk v,p)>>
              % difficult problem of negative numbers needing to be in
              % prefix form for pattern matching.
               else maprint(v,p) >>
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
           then if testing!-width!* then overflowed!* := t
                 else <<terpri!* t; prin2!* x>>
          else if flagp(op,'spaced)
           then <<prin2!* " "; prin2!* x; prin2!* " ">>
          else prin2!* x)
   get(op,'prtch);

symbolic procedure prin2!* u;
   begin integer m,n;
        if overflowed!* then return 'overflowed
        else if !*fort then return fprin2 u
        else if !*nat then <<
          if u = 'pi then u := symbol '!.pi
           else if u = 'infinity then u := symbol 'infinity >>;
        n := lengthc u;
        if n<=(linelength nil-spare!*) then <<
           m := posn!*+n;
        % I somewhat dislike having the side-effect of a call to
        % terpri!* in the condition tested here, but that is maybe what
        % the problem calls for.
           if m<=(linelength nil-spare!*) or
              (not testing!-width!* and
                 << terpri!* t;
                    (m := posn!*+n)<=(linelength nil-spare!*) >>)
             then <<if not !*nat then  %fjw%  prin2 u
                    % output should be REDUCE-readable  %% begin{fjw}
                       if stringp u or get(u,'switch!*) or digit u
                          or get(car explode2 u,'switch!*) then prin2 u
                        else prin1 u                        %% end{fjw}
                     else pline!* := (((posn!* . m) . ycoord!*) . u)
                                        .  pline!*;
                    return (posn!* := m)>>>>;
        %identifier longer than one line;
        if testing!-width!* then <<
            overflowed!* := t;
            return 'overflowed >>
        else if !*fort
         then rerror(mathpr,1,list(u,"too long for FORTRAN"));
        % Let LISP print the atom.
        terpri!* nil;
        prin2t u;
%       if !*clisp then m := posn() else
        % I think this is what is really wanted.
        m := remainder(n,(linelength nil-spare!*));
        return (posn!* := m)
   end;

symbolic procedure terpri!* u;
   begin integer n;
        if outputhandler!* then return apply2(outputhandler!*,'terpri,u)
         else if testing!-width!* then return overflowed!* := t
         else if !*fort then return fterpri(u)
         else if !*nat and pline!*
          then <<
           pline!* := reverse pline!*;
           for n := ymax!* step -1 until ymin!* do <<
             scprint(pline!*,n);
             terpri() >>;
           pline!* := nil >>;
        if u then terpri();
        posn!* := orig!*;
        ycoord!* := ymax!* := ymin!* := 0
   end;

symbolic procedure scprint(u,n);
   begin scalar m;
        posn!* := 0;
        for each v in u do <<
           if cdar v=n then <<
             if not((m:= caaar v-posn!*)<0) then spaces m;
             prin2 cdr v;
             posn!* := cdaar v >> >>
   end;

% Definition of some symbols and their access function.

symbolic procedure symbol s;
   get(s,'symbol!-character);

put('!.pi, 'symbol!-character, 'pi);
put('bar, 'symbol!-character, '!-);
put('int!-top, 'symbol!-character, '!/);
put('int!-mid, 'symbol!-character, '!|);
put('int!-low, 'symbol!-character, '!/);
put('d, 'symbol!-character, '!d);       % This MUST be lower case
%%put('sqrt, 'symbol!-character, 'sqrt);% No useful fallback here
put('vbar, 'symbol!-character, '!|);
put('sum!-top, 'symbol!-character, "---");
put('sum!-mid, 'symbol!-character, ">  ");
put('sum!-low, 'symbol!-character, "---");
put('prod!-top, 'symbol!-character, "---");
put('prod!-mid, 'symbol!-character, "| |");
put('prod!-low, 'symbol!-character, "| |");
put('infinity, 'symbol!-character, 'infinity);
    % In effect nothing special

put('mat!-top!-l, 'symbol!-character, '![);
put('mat!-top!-r, 'symbol!-character, '!]);
put('mat!-low!-l, 'symbol!-character, '![);
put('mat!-low!-r, 'symbol!-character, '!]);


% The following definitions allow for more natural printing of
% conditional expressions within rule lists.

bool!-functions!* :=
  for each x in {'equal,'greaterp,'lessp,'geq,'leq,'neq,'numberp}
      collect get(x,'boolfn) . x;

symbolic procedure condpri(u,p);
   <<if p>0 then prin2!* "(";
     while (u := cdr u) do
        <<if not(caar u eq 't)
            then <<prin2!* 'if; prin2!* " ";
                   maprin sublis(bool!-functions!*,caar u);
                   prin2!* " "; prin2!* 'then; prin2!* " ">>;
          maprin cadar u;
          if cdr u then <<prin2!* " "; prin2!* 'else; prin2!* " ">>>>;
     if p>0 then prin2!* ")">>;

put('cond,'pprifn,'condpri);

symbolic procedure revalpri u;
   maprin eval cadr u;

put('aeval,'prifn,'revalpri);

put('reval,'prifn,'revalpri);

symbolic procedure boolvalpri u;
   maprin cadr u;

put('boolvalue!*,'prifn,'boolvalpri);

endmodule;


module sqprint;   % Routines for printing standard forms and quotients.

% Author: Anthony C. Hearn.

% Copyright (c) 1991 RAND.  All rights reserved.

% Modified by A. C. Norman, 1987.

fluid  '(!*fort
         !*nat
         !*nero
         !*pri
         !*prin!#
         overflowed!*
         orig!*
         outputhandler!*
         posn!*
         testing!-width!*
         ycoord!*
         ymax!*
         ymin!*
         wtl!*);

testing!-width!* := overflowed!* := nil;

global '(!*eraise !*horner);

% When nat is enabled I use some programmable characters to
% draw pi, fraction bars and integral signs. (symbol 's) returns
% a character-object, and I use
%   .pi         pi
%   bar         solid horizontal bar                    -
%   int-top     top hook of integral sign               /
%   int-mid     vertical mid-stroke of integral sign    |
%   int-low     lower hook of integral sign             /
%   d           curly-d for use with integral display   d
%   sqrt        square root sign                        sqrt
%   sum-top     ---
%   sum-mid     >              for summation
%   sum-low     ---
%   prod-top             ---
%   prod-mid             | |   for products
%   prod-low             | |
%   infinity    infinity sign
%   mat!-top!-l     /          for display of matrices
%   mat!-top!-r     \
%   mat!-low!-l     \
%   mat!-low!-r     /
%   vbar            |


symbolic procedure !*sqprint u;
   sqprint cadr u;

put('!*sq, 'prifn, '!*sqprint);

symbolic procedure printsq u;
   << terpri!* t;
      sqprint u;
      terpri!* u;
      u >>;

symbolic procedure sqprint u;
   %mathprints the standard quotient U;
   begin scalar flg,w,z,!*prin!#;
        !*prin!# := t;
        z := orig!*;
        if !*nat and posn!*<20 then orig!* := posn!*;
        if !*pri or wtl!* then <<
          w := prepsq!* u;
          if !*horner
             and not errorp(u:=errorset!*(list('horner,mkquote w),nil))
            then w := car u;
          maprin w >>
         else if cdr u neq 1 then <<
           flg := not domainp numr u and red numr u;
           if flg then prin2!* "(";
           xprinf(car u,nil,nil);
           if flg then prin2!* ")";
           prin2!* " / ";
           flg:= not domainp denr u and (red denr u or lc denr u neq 1);
%          flg:= not domainp denr u and red denr u;
           if flg then prin2!* "(";
           xprinf(cdr u,nil,nil);
           if flg then prin2!* ")" >>
         else xprinf(car u,nil,nil);
        return (orig!* := z)
   end;

symbolic procedure printsf u;
   << prinsf u;
      terpri!* nil;
     u >>;

symbolic procedure prinsf u;
   if null u then prin2!* 0 else xprinf(u,nil,nil);

symbolic procedure xprinf(u,v,w);
   %U is a standard form.
   %V is a flag which is true if a term has preceded current form.
   %W is a flag which is true if form is part of a standard term;
   %Procedure prints the form and returns NIL;
   <<  while not domainp u do <<
          xprint(lt u,v);
          u := red u;
          v := t >>;
       if not null u then xprid(u,v,w)
       else nil >>;

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
        if flg then <<
           if v then oprin 'plus;
           prin2!* "(" >>;
        xprinf(tc u,if flg then nil else v,not flg);
        if flg then prin2!* ")";
        if not atom tc u or not abs tc u=1 then oprin 'times;
        w := tpow u;
        if atom car w then prin2!* car w
         else if not atom caar w or caar w eq '!*sq then <<
            prin2!* "(";
            if not atom caar w then xprinf(car w,nil,nil)
             else sqprint cadar w;
            prin2!* ")" >>
         else if caar w eq 'plus then maprint(car w,100)
         else maprin car w;
        if not (cdr w=1) then <<
          if !*nat and !*eraise
            then <<ycoord!* := ycoord!*+1;
                   if ycoord!*>ymax!* then ymax!* := ycoord!*>>
           else prin2!* get('expt,'prtch);
          prin2!* if numberp cdr w and minusp cdr w then list cdr w
                   else cdr w;
          if !*nat and !*eraise
            then <<ycoord!* := ycoord!*-1;
                   if ymin!*>ycoord!* then ymin!* := ycoord!*>> >>
   end;

symbolic procedure varpri(u,v,w);
   begin scalar x;
   %U is expression being printed
   %V is the original form that was evaluated.
   %W is an id that indicates if U is the first, only or last element
   %  in the current set (or NIL otherwise).
    testing!-width!* := overflowed!* := nil;
    if null u then u := 0;
    if !*nero and u=0 then return nil;
    v := setvars v;
    if (x := getrtype u) and flagp(x,'sprifn) and null outputhandler!*
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
     then lispeval cadr u . setvars caddr u
    else if car u eq 'setq then cadr u . setvars caddr u
    else nil;

endmodule;


module ratprin;   % Printing standard quotients.

% Author: Eberhard Schruefer.

% Modifications by: Anthony C. Hearn & A. C. Norman.

fluid  '(!*fort
         !*list
         !*mcd
         !*nat
         !*ratpri
         dmode!*
         ycoord!*
         ymin!*
         ymax!*
         orig!*
         pline!*
         posn!*
         p!*!*);

global '(spare!*);

switch ratpri;

!*ratpri := t;   % default value if this module is loaded.

put('quotient,'prifn,'quotpri);
put('quotpri, 'expt, 'inbrackets);

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
   begin scalar x,y,ch,pln,pld;
         integer heightnum,heightden,orgnum,orgden,fl,w;
     spare!* := spare!* + 2;
     if (pln := layout!-formula(cadr u, 0, nil)) and
        (pld := layout!-formula(caddr u, 0, nil)) then <<
         spare!* := spare!* - 2;
         fl := 2 + max(cdar pln, cdar pld);
         if fl>(linelength nil - spare!* - posn!*) then terpri!* t;
         w := (cdar pln - cdar pld);   % Width difference num vs. den
         if w > 0 then << orgnum := 0; orgden := w / 2 >>
          else << orgnum := (-w) / 2; orgden := 0 >>;
         heightnum := cddr pln - cadr pln + 1;
         heightden := cddr pld - cadr pld + 1;
         pline!* :=
            append(
               update!-pline(orgnum + posn!* + 1 - orig!*,
                             1 - cadr pln + ycoord!*,
                             caar pln),
               append(update!-pline(orgden + posn!* + 1 - orig!*,
                                    ycoord!* - cddr pld - 1,
                                    caar pld),
                      pline!*));
         ymin!* := min(ymin!*, ycoord!* - heightden);
         ymax!* := max(ymax!*, ycoord!* + heightnum);
         ch := symbol 'bar;
         for j := 1:fl do prin2!* ch >>
      else <<
         % Here the miserable thing will not fit on one line
         spare!* := spare!* - 2;    % Restore
         u :=  cdr u;
         x := get('quotient,'infix);
         if p!*!* then y := p!*!*>x else y := nil;
         if y then prin2!* "(";
         maprint(car u,x);
         oprin 'quotient;
         maprint(negnumberchk cadr u,x);
         if y then prin2!* ")">>
    end;

symbolic procedure layout!-formula(u, p, op);
% This procedure forms a pline!* structure for an expression that
% will fit upon a single line. It returns the pline* together with
% height, depth and width information. If the line would not fit
% it returns nil. Note funny treatment of orig!* and width here.
% If op is non-nil oprin it too - if it is 'inbrackets do that.
   begin
      scalar ycoord!*, ymin!*, ymax!*, posn!*, pline!*,
             testing!-width!*, overflowed!*;
      pline!* := overflowed!* := nil;
      ycoord!* := ymin!* := ymax!* := 0;
      posn!* := orig!*;
      testing!-width!* := t;
      if op then <<
         if op = 'inbrackets then prin2!* "("
          else oprin op >>;
      maprint(u, p);
      if op = 'inbrackets then prin2!* ")";
      if overflowed!* then return nil
       else return (pline!* . (posn!* - orig!*)) . (ymin!* . ymax!*)
   end;

symbolic procedure update!-pline(x,y,pline);
   % Adjusts origin of expression in pline by (x,y).
   if x=0 and y=0 then pline
    else for each j in pline collect
            (((caaar j #+ x) . (cdaar j #+ x)) . (cdar j #+ y)) . cdr j;

symbolic procedure prinfit(u, p, op);
% Display u (as with maprint) with op in front of it, but starting
% a new line before it if there would be overflow otherwise.
   begin
      scalar w;
      if not !*nat or testing!-width!* then <<
         if op then oprin op;
         return maprint(u, p) >>;
      w := layout!-formula(u, p, op);
      if w = nil then <<
         if op then oprin op;
         return maprint(u, p) >>;
      putpline w
   end;

symbolic procedure putpline w;
   begin
      if posn!* #+ cdar w > linelength nil #- spare!* then terpri!* t;
      pline!* :=
         append(update!-pline(posn!* #- orig!*, ycoord!*, caar w),
                pline!*);
      posn!* := posn!* #+ cdar w;
      ymin!* := min(ymin!*, cadr w #+ ycoord!*);
      ymax!* := max(ymax!*, cddr w #+ ycoord!*)
  end;

endmodule;


module dfprin;     % Printing for derivatives plus other options
                   % suggested by the Twente group

% Author: A. C. Norman,  reconstructing ideas from Ben Hulshof,
%                      Pim van den Heuvel and Hans van Hulzen.

fluid '(!*fort !*nat depl!* posn!*);

global '(!*dfprint
         !*noarg
         farglist!*);

switch dfprint,noarg;

!*dfprint := nil;  % This is OFF by default because switching it on
                   % changes Reduce output in a way that might upset
                   % customers who have not found out about this switch.
                   % Perhaps in later releases of the code (and when the
                   % manual reflects this upgrade) it will be possible
                   % to make 'on dfprint' the default. Some sites may of
                   % course wish to arrange things otherwise...

!*noarg := t;      % If dfprint is enabled I am happy for noarg to be
                   % the expected option.

farglist!* := nil;

symbolic procedure dfprintfn u;
% Display derivatives - if suitable flags are set this uses
% subscripts to denote differentiation and loses the arguments to
% functions.
   if not !*nat or !*fort or not !*dfprint then 'failed
   else begin
      scalar w;
      w := layout!-formula('!!df!! . cdr u, 0, nil);
      if w = nil then return 'failed
      else putpline w
   end;

put('df, 'prifn, 'dfprintfn);

symbolic procedure dflayout u;
% This is a prifn for !!df!!, which is used internally when I am
% formatting derivatives, but which should only ever be seen in
% testing!-width!* mode and never at all by the end-user.
   begin
      scalar op, args, w;
      w := car (u := cdr u);
      u := cdr u;
      if !*noarg then <<
         if atom w then <<
            op := w;
            args := assoc(op, depl!*);         % Implicit args
            if args then args := cdr args >>
         else <<
            op := car w;
            args := cdr w >>;                  % Explicit args
         remember!-args(op, args);
         w := op >>;
      maprin w;
      if u then <<
         u := layout!-formula('!!dfsub!! . u, 0, nil); % subscript line
         if null u then return 'failed;
         w := 1 + cddr u;
         putpline((update!-pline(0, -w, caar u) . cdar u) .
                  ((cadr u - w) . (cddr u - w))) >>
   end;

symbolic procedure dfsublayout u;
% This is a prifn for !!dfsub!!, which is used internally when I am
% formatting derivatives, but which should only ever be seen in
% testing!-width!* mode and never at all by the end-user.
   begin
      scalar dfcase, firstflag, w;
% This is used as a prifn for both df and other things with
% subscripts - dfcase remembers which.
      dfcase := (car u = '!!dfsub!!);
      u := cdr u;
      firstflag := t;
      while u do <<
         w := car u;
         u := cdr u;
         if firstflag then firstflag := nil
          else prin2!* ",";
         if dfcase and u and numberp car u then <<
            prin2!* car u;
            u := cdr u >>;
         maprin w >>
   end;

put('!!df!!, 'prifn, 'dflayout);
put('!!dfsub!!, 'prifn, 'dfsublayout);

symbolic procedure remember!-args(op, args);
% This records information that can be displayed by the user
% issuing the command 'FARG'.
   begin
      scalar w;
      w := assoc(op, farglist!*);
      if null w then farglist!* := (op . args) . farglist!*
   end;

symbolic procedure farg;
% Implementation of FARG: display implicit argument data
   begin
      scalar newname;
      prin2!* "The operators have the following ";
      prin2!* "arguments or dependencies";
      terpri!* t;
      for each p in farglist!* do <<
         prin2!* car p;
         prin2!* "=";
% To avoid clever pieces of code getting rid of argument displays
% here I convert the name of the function into a string so that
% maprin produces a simple but complete display. Since I expect
% farg to be called but rarely this does not seem overexpensive
         newname := compress ('!" . append(explodec car p, '(!")));
         maprin(newname . cdr p);
         terpri!* t >>
   end;

put('farg, 'stat, 'endstat);

symbolic procedure clfarg;
% Clear record of implicit args
   farglist!* := nil;

put('clfarg, 'stat, 'endstat);

symbolic procedure setprifn(u, fn);
% Establish (or clear) prifn property for a list of symbols
   for each n in u do
      if idp n then <<
% Things listed here will be declared operators now if they have
% not been so declared earlier.
         if not operatorp n then mkop n;
         if fn then put(n, 'prifn, fn)
          else remprop(n, 'prifn) >>
       else lprim list(n, "not an identifier");

symbolic procedure indexprin u;
% Print helper-function when integer-valued arguments are to be shown as
% subscripts
   if not !*nat or !*fort then 'failed
   else begin
      scalar w;
      w := layout!-formula('!!index!! . u, 0, nil);
      if w = nil then return 'failed
      else putpline w
   end;

symbolic procedure indexpower(u, n);
% Print helper-function when integer-valued arguments are to be shown as
% subscripts with exponent n
    begin
      scalar w;
      w := layout!-formula('!!indexpower!! . n . u, 0, nil);
      if w = nil then return 'failed
      else putpline w
   end;

symbolic procedure indexlayout u;
% This is a prifn for !!index!!, which is used internally when I am
% formatting index forms, but which should only ever be seen in
% testing!-width!* mode and never at all by the end-user.
   begin
      scalar w;
      w := car (u := cdr u);
      u := cdr u;
      maprin w;
      if u then <<
         u := layout!-formula('!!indexsub!! . u, 0, nil);
            % subscript line
         if null u then return 'failed;
         w := 1 + cddr u;
         putpline((update!-pline(0, -w, caar u) . cdar u) .
                  ((cadr u - w) . (cddr u - w))) >>
   end;

symbolic procedure indexpowerlayout u;
% Format a subscripted object raised to some power.
   begin
      scalar n, w, pos, maxpos;
      n := car (u := cdr u);  % The exponent
      w := car (u := cdr u);
      u := cdr u;
      maprin w;
      w := layout!-formula(n, 0, nil);
      pos := posn!*;
      putpline((update!-pline(0, 1 - cadr w, caar w) . cdar w) .
               (1 . (1 + cddr w - cadr w)));
      maxpos := posn!*;
      posn!* := pos;
      if u then <<
         u := layout!-formula('!!indexsub!! . u, 0,nil);
             % subscript line
         if null u then return 'failed;
         w := 1 + cddr u;
         putpline((update!-pline(0, -w, caar u) . cdar u) .
                  ((cadr u - w) . (cddr u - w))) >>;
      posn!* := max(posn!*, maxpos)
   end;

put('!!index!!, 'prifn, 'indexlayout);
put('!!indexpower!!, 'prifn, 'indexpowerlayout);
put('!!indexsub!!, 'prifn, 'dfsublayout);

symbolic procedure noargsprin u;
% Print helper-function when arguments for a function are to be hidden,
% but remembered for display via farg
   if not !*nat or !*fort then 'failed
    else <<
       remember!-args(car u, cdr u);
       maprin car u >>;

symbolic procedure doindex u;
% Establish some function names to have args treated as index values
   setprifn(u, 'indexprin);

symbolic procedure offindex u;
% Clear effect of doindex
   setprifn(u, nil);

symbolic procedure donoargs u;
% Identify functions where args are to be hidden
   setprifn(u, 'noargsprin);

symbolic procedure offnoargs u;
% Clear effect of donoargs
   setprifn(u, nil);

put('doindex, 'stat, 'rlis);
put('offindex, 'stat, 'rlis);
put('donoargs, 'stat, 'rlis);
put('offnoargs, 'stat, 'rlis);

endmodule;


module fortpri; % FORTRAN output package for expressions.

% Author: Anthony C. Hearn.

% Modified by: James Davenport after Francoise Richard, April 1988.

% Copyright (c) 1991 RAND.  All rights reserved.

fluid  '(!*fort
         !*period
         scountr
         explis
         fbrkt
         fvar
         nchars
         svar
         posn!*);

global '(cardno!*
         fortwidth!*
         spare!*
         varnam!*);

%Global variables initialized in this section;

% SPARE!* should be set in the system dependent code module.

cardno!*:=20;
fortwidth!* := 70;
posn!* := 0;
varnam!* := 'ans;

flag ('(cardno!* fortwidth!*),'share);

symbolic procedure varname u;
   % Sets the default variable assignment name.
   if not idp car u then typerr(car u,"identifier")
    else varnam!* := car u;

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
         else if atom l then <<
           if l eq 'e then return fprin2 "EXP(1.0)";
           if not numberp l or
              not l<0 then return fprin2 l;
           fprin2 "(";
           fbrkt := nil . fbrkt;
           fprin2 l;
           fprin2 ")";
           return fbrkt := cdr fbrkt >>
         else if stringp l then return fprin2 l
         else if not atom car l then fmprint(car l,p)
%        else if x := get(car l,'specprn)
%         then return apply1(x,cdr l)
         else if ((x := get(car l,'pprifn))
             and not((x := apply2(x,l,p)) eq 'failed)) or
                 ((x := get(car l,'prifn))
             and not((x := apply1(x,l)) eq 'failed))
          then return x
         else if x := get(car l,'infix) then <<
            p := not x>p;
            if p then <<fprin2 "("; fbrkt := nil . fbrkt>>;
            fnprint(car l,x,cdr l);
            if p then <<fprin2 ")"; fbrkt := cdr fbrkt>>;
            return >>
         else fprin2 car l;
        fprin2 "(";
        fbrkt := nil . fbrkt;
        x := !*period;
        % Assume no period printing for non-operators (e.g., matrices).
        if gettype car l neq 'operator then !*period := nil;
        if cdr l then fnprint('!*comma!*,0,cdr l);
        !*period := x;
        fprin2 ")";
        return fbrkt := cdr fbrkt
   end;

symbolic procedure fnprint(op,p,l);
   begin
        if op eq 'expt then return fexppri(p,l)
         else if not get(op,'alt) then <<
           fmprint(car l,p);
           l := cdr l >>;
        for each v in l do <<
          if atom v or not (op eq get(car v,'alt)) then foprin op;
          fmprint(v,p) >>
   end;

symbolic procedure fexppri(p,l);
   % Next line added by James Davenport after Francoise Richard.
   if car l eq 'e then fmprint('exp . cdr l,p)
    else begin scalar pperiod;
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
      if eqcar(xexp,'list)
        then <<posn!* := 0;
               fprin2 "C ***** INVALID FORTRAN CONSTRUCT (";
               fprin2 car xexp;
               return fprin2 ") NOT PRINTED">>;
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

% If we are in a comment, we want to continue to stay in one,
% Even if there's a formula. That's the purpose of this flag
% Added by James Davenport after Francoise Richard.

global '(Comment!*);

symbolic procedure fprin2 u;
   % FORTRAN output of U;
   begin integer m,n;
        if posn!*=0 then Comment!*:=
                stringp u and cadr(explode u) eq 'C;
        n := flatsizec u;
        m := posn!*+n;
        if fixp u and !*period then m := m+1;
        if m<(linelength nil-spare!*) then posn!* := m
         else <<terpri();
                if Comment!* then << prin2 "C"; spaces 4 >>
                             else spaces 5;
                prin2 ". "; posn!* := n+7>>;
        prin2 u;
        if fixp u and !*period then prin2 "."
   end;

symbolic procedure fterpri(u);
   <<if not posn!*=0 and u then terpri();
     posn!* := 0>>;

symbolic procedure genvar;
   intern compress append(explode svar,explode(scountr := scountr + 1));

endmodule;


end;
