module alg;  % Header module for alg package.

% Author: Anthony C. Hearn.

create!-package('(alg alg!-form intro general farith numsup genmod
                  random smallmod zfactor sort reval algbool simp
                  simplog logsort sub order forall eqn rmsubs algdcl
                  opmtch prep extout depend str coeff weight linop elem
                  maxmin nssimp part),
                nil);

put('alglist!*,'initvalue!*,'(cons nil nil));

endmodule;


module alg!-form;   % Some particular algebraic mode analysis functions.

% Author: Anthony C. Hearn.

% Copyright (c) 1991 RAND.  All rights reserved.

global '(inputbuflis!* resultbuflis!* ws);

symbolic procedure forminput(u,vars,mode);
   begin scalar x;
      u := cadr u;
      if null(x := assoc(u,inputbuflis!*))
        then rerror(alg,1,list("Entry",u,"not found"));
      return caddr x
   end;

put('input,'formfn,'forminput);

symbolic procedure formws(u,vars,mode);
   begin scalar x;
      if x := assoc(cadr u,resultbuflis!*) then return mkquote cdr x
       else rerror(alg,2,list("Entry",cadr u,"not found"))
   end;

put('ws,'formfn,'formws);

endmodule;


module intro;  % Introductory material for algebraic mode.

% Author: Anthony C. Hearn.

% Copyright (c) 1991 RAND.  All rights reserved.

fluid '(!*cref !*exp !*factor !*fort !*ifactor !*intstr !*lcm !*mcd
        !*msg !*mode !*nat !*nero !*period !*precise !*pri
        !*rationalize !*reduced !*sub2 posn!*);

global '(!*resubs
         !*val
         erfg!*
         exlist!*
         initl!*
         nat!*!*
         ofl!*
         simpcount!*
         simplimit!*
         subfg!*
         tstack!*);

% Non-local variables needing top level initialization.

!*exp := t;             %expansion control flag;
!*lcm := t;             %least common multiple computation flag;
!*mcd := t;             %common denominator control flag;
!*mode := 'symbolic;    %current evaluation mode;
!*msg := t;             %flag controlling message printing;
!*nat := t;             %specifies natural printing mode;
!*period := t;          %prints a period after a fixed coefficient
                        %when FORT is on;
!*resubs := t;          %external flag controlling resubstitution;
!*val := t;             %controls operator argument evaluation;
exlist!* := '((!*));    %property list for standard forms used as
                        % kernels;
initl!* := append('(subfg!* !*sub2 tstack!*),initl!*);
simpcount!* := 0;       %depth of recursion within simplifier;
simplimit!* := 2000;    %allowed recursion limit within simplifier;
subfg!* := t;           %flag to indicate whether substitution
                        %is required during evaluation;
tstack!* := 0;          %stack counter in SIMPTIMES;

% Initial values of some global variables in BEGIN1 loops.

put('subfg!*,'initl,t);

put('tstack!*,'initl,0);


% Description of some non-local variables used in algebraic mode.

% alglist!* := nil . nil; %association list for previously simplified
                        %expressions;
% asymplis!* := nil;    %association list of asymptotic replacements;
% cursym!*              current symbol (i. e. identifier, parenthesis,
%                       delimiter, e.t.c,) in input line;
% dmode!* := nil;       %name of current polynomial domain mode if not
                        %integer;
% domainlist!* := nil;  %list of currently supported poly domain modes;
% dsubl!* := nil;       %list of previously calculated derivatives of
                        % expressions;
% exptl!* := nil;       %list of exprs with non-integer exponents;
% frlis!* := nil;       %list of renamed free variables to be found in
                        %substitutions;
% kord!* := nil;        %kernel order in standard forms;
% kprops!* := nil;      %list of active non-atomic kernel plists;
% mchfg!* := nil;       %indicates that a pattern match occurred during
                        %a cycle of the matching routines;
% mul!* := nil;         %list of additional evaluations needed in a
                        %given multiplication;
% nat!*!* := nil;       %temporary variable used in algebraic mode;
% ncmp!* := nil;        %flag indicating non-commutative multiplication
                        %mode;
% ofl!* := nil;         %current output file name;
% posn!* := nil;        %used to store output character position in
                        %printing functions;
% powlis!* := nil;      %association list of replacements for powers;
% powlis1!* := nil;     %association list of conditional replacements
                        %for powers;
% subl!* := nil;        %list of previously evaluated expressions;
% wtl!* := nil;         %tells that a WEIGHT assignment has been made;
% !*ezgcd := nil;       %ezgcd calculation flag;
% !*float := nil;       %floating arithmetic mode flag;
% !*fort := nil;        %specifies FORTRAN output;
% !*gcd := nil;         %greatest common divisor mode flag;
% !*group := nil;       %causes expressions to be grouped when EXP off;
% !*intstr := nil;      %makes expression arguments structured;
% !*int                 indicates interactive system use;
% !*match := nil;       %list of pattern matching rules;
% !*nero := nil;        %flag to suppress printing of zeros;
% !*nosubs := nil;      %internal flag controlling substitution;
% !*numval := nil;      %used to indicate that numerical expressions
                        %should be converted to a real value;
% !*outp := nil;        %holds prefix output form for extended output
                        %package;
% !*pri := nil;         %indicates that fancy output is required;
% !*reduced := nil;     %causes arguments of radicals to be factored.
                        %E.g., sqrt(-x) --> i*sqrt(x);
% !*sub2 := nil;        %indicates need for call of RESIMP;


% ***** UTILITY FUNCTIONS *****.

symbolic procedure mkid(x,y);
  % creates the ID XY from identifier X and (evaluated) object Y.
  if not idp x then typerr(x,"MKID root")
   else if atom y and (idp y or fixp y and not minusp y)
    then intern compress nconc(explode x,explode y)
   else typerr(y,"MKID index");

flag('(mkid),'opfn);

symbolic procedure multiple!-result(z,w);
   % Z is a list of items (n . prefix-form), in ordering in descending
   % order wrt n, which must be non-negative.  W is either an array
   % name, another id, a template for a multi-dimensional array or NIL.
   % Elements of Z are accordingly stored in W if it is non-NIL, or
   % returned as a list otherwise.
   begin scalar x,y;
        if null w then return 'list . reversip!* fillin z;
        x := getrtype w;
        if x and not x eq 'array then typerr(w,"array or id");
        lpriw("*****",
              list(if x eq 'array then "ARRAY" else "ID",
                   "fill no longer supported --- use lists instead"));
        if atom w then (if not arrayp w
           then (if numberp(w := reval w) then typerr(w,'id)))
         else if not arrayp car w then typerr(car w,'array)
         else w := car w . for each x in cdr w
                            collect if x eq 'times then x else reval x;
        x := length z-1;  % don't count zeroth element;
        if not((not atom w and atom car w
                         and (y := dimension car w))
             or ((y := dimension w) and null cdr y))
         then <<y := explode w;
                w := nil;
                for each j in z do
                   <<w := intern compress append(y,explode car j) . w;
                     setk1(car w,cdr j,t)>>;
                lprim if length w=1 then list(car w,"is non zero")
                       else aconc!*(reversip!* w,"are non zero");
                return x>>
         else if atom w
          then <<if caar z neq (car y-1)
                   then <<y := list(caar z+1);
                          put(w,'array,mkarray(y,'algebraic));
                          put(w,'dimension,y)>>;
                 w := list(w,'times)>>;
        y := pair(cdr w,y);
        while y and not smemq('times,caar y) do y := cdr y;
        if null y then errach "MULTIPLE-RESULT";
        y := cdar y-reval subst(0,'times,caar y)-1;
           %-1 needed since DIMENSION gives length, not highest index;
        if caar z>y
          then rerror(alg,3,list("Index",caar z,"out of range"));
        repeat
           if null z or y neq caar z
             then setelv(subst(y,'times,w),0)
            else <<setelv(subst(y,'times,w),cdar z); z := cdr z>>
          until (y := y-1) < 0;
        return x
   end;

symbolic procedure fillin u;
   % fills in missing terms in multiple result argument list u
   % and returns list of coefficients.
   if null u then nil else fillin1(u,caar u);

symbolic procedure fillin1(u,n);
   if n<0 then nil
    else if u and caar u=n then cdar u . fillin1(cdr u,n-1)
    else 0 . fillin1(u,n-1);


% ***** FUNCTIONS FOR PRINTING DIAGNOSTIC AND ERROR MESSAGES *****

symbolic procedure msgpri(u,v,w,x,y);
   begin integer posn!*; scalar nat1,z,pline!*;
        if null y and null !*msg then return;
        nat1 := !*nat;
        !*nat := nil;
        if ofl!* and (!*fort or not nat1) then go to c;
    a:  terpri();
        lpri ((if null y then "***" else "*****")
                 . if u and atom u then list u else u);
        posn!* := posn();
        maprin v;
        prin2 " ";
        lpri if w and atom w then list w else w;
        posn!* := posn();
        maprin x;
        terpri!*(t); % if not y or y eq 'hold then terpri();
        if null z then go to b;
        wrs cdr z;
        go to d;
    b:  if null ofl!* then go to d;
    c:  z := ofl!*;
        wrs nil;
        go to a;
    d:  !*nat := nat1;
        if y then if y eq 'hold then erfg!* := y else error1()
   end;

symbolic procedure errach u;
   begin
        terpri!* t;
        lprie "CATASTROPHIC ERROR *****";
        printty u;
        lpriw(" ",nil);
        rerror(alg,4,
               "Please send output and input listing to A. C. Hearn")
   end;

symbolic procedure errpri1 u;
   msgpri("Substitution for",u,"not allowed",nil,t);  % was 'HOLD

symbolic procedure errpri2(u,v);
   msgpri("Syntax error:",u,"invalid",nil,v);

symbolic procedure redmsg(u,v);
   if null !*msg or v neq "operator" then nil
    else if terminalp() then yesp list("Declare",u,v,"?") or error1()
    else lprim list(u,"declared",v);

symbolic procedure typerr(u,v);
   <<terpri!* t;
     prin2!* "***** ";
     if not atom u and atom car u and cdr u and atom cadr u 
        and null cddr u
       then <<prin2!* car u; prin2!* " "; prin2!* cadr u>>
      else maprin u;
     prin2!* " invalid as "; prin2!* v;
     terpri!* nil; erfg!* := t; error1()>>;


%                 ***** ALGEBRAIC MODE DECLARATIONS *****

flag ('(aeval cond getel go prog progn prog2 return
        reval setq setk setel varpri !*s2i),'nochange);

flag ('(or and not member memq equal neq eq geq greaterp leq
        fixp lessp numberp ordp freeof),'boolean);

flag ('(or and not),'boolargs);

deflist ('((exp ((nil (rmsubs)) (t (rmsubs))))
        (factor ((nil (setq !*exp t) (rmsubs))
                 (t (setq !*exp nil) (rmsubs))))
        (fort ((nil (setq !*nat nat!*!*)) (t (setq !*nat nil))))
        (gcd ((t (rmsubs))))
        (intstr ((nil (rmsubs)) (t (rmsubs))))
        (mcd ((nil (rmsubs)) (t (rmsubs))))
        (nat ((nil (setq nat!*!* nil)) (t (setq nat!*!* t))))
        (numval ((t (rmsubs))))
        (rationalize ((t (rmsubs))))
        (reduced ((t (rmsubs))))
        (val ((t (rmsubs))))),'simpfg);

switch exp,cref,factor,fort,gcd,ifactor,intstr,lcm,mcd,nat,nero,numval,
       period,precise,pri,rationalize,reduced;   % resubs, val.

endmodule;


module general;   % General functions for the support of REDUCE.

% Author: Anthony C. Hearn.

% Copyright (c) 1987 The RAND Corporation.  All rights reserved.

global '(!!arbint);

!!arbint := 0; % Index for arbitrary constants.

symbolic procedure atomlis u;
   null u or (atom car u and atomlis cdr u);

symbolic procedure carx(u,v);
   if null cdr u then car u
    else rerror(alg,5,list("Wrong number of arguments to",v));

symbolic procedure delasc(u,v);
   if null v then nil
    else if atom car v or u neq caar v then car v . delasc(u,cdr v)
    else cdr v;

symbolic procedure eqexpr u;
   % Returns true if U is an equation or similar structure
   % (e.g., a rule).
   not atom u
      and flagp(car u,'equalopr) and cddr u and null cdddr u;

flag('(eq equal),'equalopr);

symbolic procedure evenp x; remainder(x,2)=0;

flag('(evenp),'opfn);  % Make a symbolic operator.

symbolic procedure lengthc u;
   %gives character length of U excluding string and escape chars;
   begin integer n; scalar x;
      n := 0;
      x := explode u;
      if car x eq '!" then return length x-2;
      while x do
        <<if car x eq '!! then x := cdr x;
          n := n+1;
          x := cdr x>>;
      return n
   end;

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

symbolic procedure nth(u,n);
   car pnth(u,n);

symbolic procedure pnth(u,n);
   if null u then rerror(alg,6,"Index out of range")
    else if n=1 then u
    else pnth(cdr u,n-1);

symbolic procedure permp(u,v);
   if null u then t
    else if car u eq car v then permp(cdr u,cdr v)
    else not permp(cdr u,subst(car v,car u,cdr v));

symbolic procedure permutations u;
   %  Returns list of all permutations of the list u.
   if null u then list u
    else for each j in u join mapcons(permutations delete(j,u),j);

symbolic procedure posintegerp u;
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

symbolic procedure repeats x;
   if null x then nil
    else if car x member cdr x then car x . repeats cdr x
    else repeats cdr x;

symbolic procedure revpr u;
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

endmodule;


module farith;  % Operators for fast arithmetic.

% Authors: A. C. Norman and P. M. A. Moore, 1981.

remprop('iplus,'infix);  % To allow for redefinition.

remprop('itimes,'infix);

symbolic macro procedure iplus u; expand(cdr u,'plus2);

symbolic macro procedure itimes u; expand(cdr u,'times2);

symbolic smacro procedure isub1 a; a-1;

symbolic smacro procedure iadd1 a; a+1;

remprop('iminus,'infix);

symbolic smacro procedure iminus a; -a;

symbolic smacro procedure idifference(a,b); a-b;

symbolic smacro procedure iquotient(a,b); a/b;

symbolic smacro procedure iremainder(a,b); remainder(a,b);

symbolic smacro procedure igreaterp(a,b); a>b;

symbolic smacro procedure ilessp(a,b); a<b;

symbolic smacro procedure iminusp a; a<0;

newtok '((!#) hash);
newtok '((!# !+) iplus);
newtok '((!# !-) idifference);
newtok '((!# !*) itimes);
newtok '((!# !/) iquotient);
newtok '((!# !>) igreaterp);
newtok '((!# !<) ilessp);

infix #+,#-,#*,#/,#>,#<;

precedence #+,+;
precedence #-,-;
precedence #*,*;
precedence #/,/;
precedence #>,>;
precedence #<,<;

flag('(iplus itimes),'nary);

deflist('((idifference iminus)),'unary);

deflist('((iminus iplus)), 'alt);

infix iequal;

symbolic smacro procedure u iequal v; eqn(u,v);

endmodule;


module numsup;   % Numerical support for basic algebra package.

% Author: Anthony C. Hearn.

% Copyright (c) 1991 The RAND Corporation.  All rights reserved.

%  Numerical greatest common divisor.

symbolic procedure gcdn(u,v);
%  U and v are integers. Value is absolute value of gcd of u and v.
   if v = 0 then abs u else gcdn(v,remainder(u,v));


% Interface to rounded code.

% Only needed if package ARITH is autoloaded.

% switch rounded;

% put('rounded,'package!-name,'arith);

% put('rounded,'simpfg,
%             '((t (load!-package 'arith) (setdmode 'rounded t))));
    % Enough for now.

endmodule;


module genmod; % Modular arithmetic where the modulus may be any size.

% Authors: A. C. Norman and P. M. A. Moore, 1981.

fluid '(current!-modulus modulus!/2);

symbolic procedure set!-general!-modulus p;
  if not numberp p then current!-modulus
  else begin
    scalar previous!-modulus;
    previous!-modulus:=current!-modulus;
    current!-modulus:=p;
    modulus!/2 := p/2;
    return previous!-modulus
  end;

symbolic procedure general!-modular!-plus(a,b);
  begin scalar result;
     result:=a+b;
     if result >= current!-modulus then result:=result-current!-modulus;
     return result
  end;

symbolic procedure general!-modular!-difference(a,b);
  begin scalar result;
     result:=a-b;
     if result < 0 then result:=result+current!-modulus;
     return result
  end;

symbolic procedure general!-modular!-number a;
  begin
     a:=remainder(a,current!-modulus);
     if a < 0 then a:=a+current!-modulus;
     return a
  end;

symbolic procedure general!-modular!-times(a,b);
  begin scalar result;
     result:=remainder(a*b,current!-modulus);
     if result<0
       then result := result+current!-modulus;  %can this happen?
     return result
  end;

symbolic procedure general!-modular!-reciprocal a;
  begin
    return general!-reciprocal!-by!-gcd(current!-modulus,a,0,1)
  end;

symbolic procedure general!-modular!-quotient(a,b);
    general!-modular!-times(a,general!-modular!-reciprocal b);

symbolic procedure general!-modular!-minus a;
    if a=0 then a else current!-modulus - a;

symbolic procedure general!-reciprocal!-by!-gcd(a,b,x,y);
%On input A and B should be coprime. This routine then
%finds X and Y such that A*X+B*Y=1, and returns the value Y
%on input A > B;
   if b=0 then rerror(alg,8,"Invalid modular division")
   else if b=1 then if y < 0 then y+current!-modulus else y
   else begin scalar w;
%N.B. Invalid modular division is either:
% a)  attempt to divide by zero directly
% b)  modulus is not prime, and input is not
%     coprime with it;
     w:=quotient(a,b); %Truncated integer division;
     return general!-reciprocal!-by!-gcd(b,a-b*w,y,x-y*w)
   end;

%symbolic procedure general!-modular!-expt(x,n);
%   if not fixp n then
%      rederr
%        "ZFACT(general-modular-expt): power is not a small integer"
%   else if n=0 then 1
%   else if n=1 then x
%   else
%     (lambda ans;
%        if evenp n then
%           general!-modular!-times(ans,ans)
%        else general!-modular!-times(general!-modular!-times(ans,x),
%                                     ans))
%      general!-modular!-expt(x,n/2);
 
symbolic procedure general!-modular!-expt(a,n);
   % Computes a**n modulo current-modulus.  Uses Fermat's Little
   % Theorem where appropriate for a prime modulus.
    if n=0 then 1
    else if n=1 then a
    else if n>=current!-modulus-1 and primep current!-modulus
     then general!-modular!-expt(a,remainder(n,current!-modulus-1))
    else begin scalar x;
     x:=general!-modular!-expt(a,n/2);
     x:=general!-modular!-times(x,x);
     if not evenp n then x:=general!-modular!-times(x,a);
     return x
    end;

endmodule;


module random;  % Random Number Generator.

% Author: Unknown.

% Modifications:
% 6.Jan.91 by JHD
%  Change definition of random so that it doesn't call float on
%  enormous numbers. In particular, the original definition (still kept
%  for small numbers) died on very large n, and would only produce
%  randommodulus!* different numbers anyway. The new definition is
%  slightly better in that respect, but could be improved further.

global '(randomseed!* randommodulus!*);

% The declarations below constitute a linear, congruential random number
% generator (see Knuth, "The Art of Computer Programming:  Volume 2:
% Seminumerical Algorithms", pp9-24).  With the given constants it has a
% period of 392931 and potency 6.  To have deterministic behaviour, set
% RANDOMSEED.

% Constants are:        6   2
%    modulus: 392931 = 3 * 7 * 11
%    multiplier: 232 = 3 * 7 * 11 + 1
%    increment: 65537 is prime
%
% Would benefit from being recoded in a SysLisp style, when full word
% integers could be used with "automatic" modular arithmetic (see
% Knuth).  Perhaps we should have a longer period version?

randommodulus!* := 392931;

% randomseed!* := remainder(time(),randommodulus!*);

randomseed!* := 300000;   % To avoid use of time function.

symbolic procedure next!-random!-number;
   % Returns a pseudo-random number between 0 and RandomModulus-1
   % (inclusive).
   randomseed!* := remainder(232*randomseed!* + 65537, randommodulus!*);

symbolic procedure random(n);
% Returns a pseudo-random number uniformly selected from the range
% 0..N-1.
if n < randommodulus!*
   then fix( (float(n) * next!-random!-number()) / randommodulus!*)
    else begin
         scalar sofar;
         sofar:=next!-random!-number();
         while sofar < n do
               sofar:=sofar*randommodulus!*+next!-random!-number();
         return remainder(sofar,n);
         end;

endmodule;


module smallmod; % Small integer modular arithmetic used in factorizer.

% Author: Arthur C. Norman.

fluid '(current!-modulus modulus!/2);

global '(largest!-small!-modulus);

symbolic procedure set!-modulus p;
  if not numberp p or p=0 then current!-modulus
  else begin
    scalar previous!-modulus;
    previous!-modulus:=current!-modulus;
    current!-modulus:=p;
    modulus!/2:=p/2;
    set!-small!-modulus p;
    return previous!-modulus
  end;

symbolic procedure set!-small!-modulus p;
  begin
    scalar previous!-modulus;
    if p>largest!-small!-modulus
      then rerror(alg,9,list("Overlarge modulus",p,"being used"));
    previous!-modulus:=current!-modulus;
    current!-modulus:=p;
    modulus!/2 := p/2;
    return previous!-modulus
  end;


smacro procedure modular!-plus(a,b);
  begin scalar result;
     result:=a #+ b;
     if not result #< current!-modulus then
            result:=result #- current!-modulus;
     return result
  end;

smacro procedure modular!-difference(a,b);
  begin scalar result;
     result:=a #- b;
     if iminusp result then result:=result #+ current!-modulus;
     return result
  end;

symbolic procedure modular!-number a;
  begin
     if not atom a then typerr(a,"integer in modular-number");
     a:=remainder(a,current!-modulus);
     if iminusp a then a:=a #+ current!-modulus;
     return a
  end;

smacro procedure modular!-times(a,b);
    remainder(a*b,current!-modulus);

smacro procedure modular!-reciprocal a;
    reciprocal!-by!-gcd(current!-modulus,a,0,1);

symbolic procedure reciprocal!-by!-gcd(a,b,x,y);
%On input A and B should be coprime. This routine then
%finds X and Y such that A*X+B*Y=1, and returns the value Y
%on input A > B;
   if b=0 then rerror(alg,10,"Invalid modular division")
   else if b=1 then if iminusp y then y #+ current!-modulus else y
   else begin scalar w;
%N.B. Invalid modular division is either:
% a)  attempt to divide by zero directly
% b)  modulus is not prime, and input is not
%     coprime with it;
     w:= a #/ b; %Truncated integer division;
     return reciprocal!-by!-gcd(b,a #- b #* w,
                                y,x #- y #* w)
   end;

smacro procedure modular!-quotient(a,b);
    modular!-times(a,modular!-reciprocal b);


smacro procedure modular!-minus a;
    if a=0 then a else current!-modulus #- a;

symbolic procedure modular!-expt(a,n);
   % Computes a**n modulo current-modulus.  Uses Fermat's Little
   % Theorem where appropriate for a prime modulus.
    if n=0 then 1
    else if n=1 then a
    else if n>=current!-modulus-1 and primep current!-modulus
     then modular!-expt(a,remainder(n,current!-modulus-1))
    else begin scalar x;
     x:=modular!-expt(a,n/2);
     x:=modular!-times(x,x);
     if not (remainder(n,2) = 0) then x:=modular!-times(x,a);
     return x
    end;

symbolic set!-modulus(1) ; % forces everything into a standard state.

endmodule;


module zfactor;  % Integer factorization.
 
% Author: Julian Padget.
% Modifications: Fran Burstall 
% exports nextprime, primep,zfactor;
% nextprime - returns the next prime GREATER than its argument;
% primep - determines whether argument is prime or not;
% zfactor - returns an alist of factors dotted with their multiplicities
%
% imports evenp, gcdn, general-modular-expt, general-modular-times, leq,
% modular-expt, modular-times, neq, prin2t, reversip,
% set-general-modulus, set-small-modulus;
%
% needs bigmod,smallmod;
%
% internal-functions add-factor, general-primep, mcfactor!*,
% internal-primep, mcfactor, small-primep;
 
% Parameters to this module are:
%
%    !*confidence!* - controls the computation in the primality test.
%        Probability that a number is composite when test says it is
%        prime is 1/(2**(2*!*confidence!*)).
%
%    !*maxtrys!* - controls the maximum number of attempts to be made
%        at factorisation (using mcfactor) whilst varying the polynomial
%        used as part of the Monte-Carlo technique.  When !*maxtrys!* is
%        exceeded assumes n is prime (case will most likely occur when
%        primality test fails).
%
%    !*mod!* - controls the modulus of the numbers emitted by the random
%        number generator.  It is important that the number being tested
%        for primality should lie in [0,!*mod!*].
%
% Globals private to this module are:
%
%    !*primelist!* - a list of the first xxx prime numbers used in the
%        first part of the factorization where trial division is
%        employed.
%
%    !*last!-prime!-in!-list!* - the largest prime in the !*primelist!*
 
fluid '(!*maxtrys!* !*confidence!*);
 
!*maxtrys!*:=10; !*confidence!*:=10;
 
global '(!*primelist!* !*last!-prime!-in!-list!*);
 
!*primelist!*:='(
2 3 5 7 11 13 17 19 23 29 31 37 41 43 47 53 59 61 67 71 73 79 83 89 97
101 103 107 109 113 127 131 137 139 149 151 157 163 167 173 179 181 191
193 197 199 211 223 227 229 233 239 241 251 257 263 269 271 277 281 283
293 307 311 313 317 331 337 347 349 353 359 367 373 379 383 389 397 401
409 419 421 431 433 439 443 449 457 461 463 467 479 487 491 499 503 509
521 523 541 547 557 563 569 571 577 587 593 599 601 607 613 617 619 631
641 643 647 653 659 661 673 677 683 691 701 709 719 727 733 739 743 751
757 761 769 773 787 797 809 811 821 823 827 829 839 853 857 859 863 877
881 883 887 907 911 919 929 937 941 947 953 967 971 977 983 991 997 1009
1013 1019 1021 1031 1033 1039 1049 1051 1061 1063 1069 1087 1091 1093
1097 1103 1109 1117 1123 1129 1151 1153 1163 1171 1181 1187 1193 1201
1213 1217 1223 1229 1231 1237 1249 1259 1277 1279 1283 1289 1291 1297
1301 1303 1307 1319 1321 1327 1361 1367 1373 1381 1399 1409 1423 1427
1429 1433 1439 1447 1451 1453 1459 1471 1481 1483 1487 1489 1493 1499
1511 1523 1531 1543 1549 1553 1559 1567 1571 1579 1583 1597 1601 1607
1609 1613 1619 1621 1627 1637 1657 1663 1667 1669 1693 1697 1699 1709
1721 1723 1733 1741 1747 1753 1759 1777 1783 1787 1789 1801 1811 1823
1831 1847 1861 1867 1871 1873 1877 1879 1889 1901 1907 1913 1931 1933
1949 1951 1973 1979 1987 1993 1997 1999 2003 2011 2017 2027 2029 2039
2053 2063 2069 2081 2083 2087 2089 2099 2111 2113 2129 2131 2137 2141
2143 2153 2161 2179 2203 2207 2213 2221 2237 2239 2243 2251 2267 2269
2273 2281 2287 2293 2297 2309 2311 2333 2339 2341 2347 2351 2357 2371
2377 2381 2383 2389 2393 2399 2411 2417 2423 2437 2441 2447 2459 2467
2473 2477 2503 2521 2531 2539 2543 2549 2551 2557 2579 2591 2593 2609
2617 2621 2633 2647 2657 2659 2663 2671 2677 2683 2687 2689 2693 2699
2707 2711 2713 2719 2729 2731 2741 2749 2753 2767 2777 2789 2791 2797
2801 2803 2819 2833 2837 2843 2851 2857 2861 2879 2887 2897 2903 2909
2917 2927 2939 2953 2957 2963 2969 2971 2999 3001 3011 3019 3023 3037
3041 3049 3061 3067 3079 3083 3089 3109 3119 3121 3137 3163 3167 3169
3181 3187 3191 3203 3209 3217 3221 3229 3251 3253 3257 3259 3271 3299
3301 3307 3313 3319 3323 3329 3331 3343 3347 3359 3361 3371 3373 3389
3391 3407 3413 3433 3449 3457 3461 3463 3467 3469 3491 3499 3511 3517
3527 3529 3533 3539 3541 3547 3557 3559 3571 )$

!*last!-prime!-in!-list!* := car reverse !*primelist!*;
 
symbolic procedure add!-factor(n,l);
   (lambda (p); if p then << rplacd(p,add1 cdr p); l>> else (n . 1) . l)
      if pairp l then if n>(caar l) then nil else atsoc(n,l) else nil;
 
symbolic procedure zfactor n;
if n<0 then
   ((-1) . 1) . zfactor(-n)
else if n<4 then
   list (n . 1)
else % trial division then advanced technology if needed
   (lambda (primelist,rootn,factor!-list); <<
      while pairp primelist do
         (lambda aprime; <<
            while remainder(n,aprime)=0 do <<
               n:=n/aprime;
               rootn:=isqrt n;
               factor!-list:=add!-factor(aprime,factor!-list)
            >>;
            if rootn < aprime then <<
               if n neq 1
                then factor!-list:=add!-factor(n,factor!-list);
               primelist:=aprime
            >>
            else
               primelist:=cdr primelist
          >>)
          car primelist;
      if null primelist then mcfactor!*(n,factor!-list)
       else factor!-list
      >>)
    (!*primelist!*,isqrt n,nil);
 
symbolic procedure mcfactor!*(n,factors!-so!-far);
   if internal!-primep n then add!-factor(n,factors!-so!-far)
    else <<n:=(lambda (p,tries); <<
         while (atom p) and (tries<!*maxtrys!*) do <<
            tries:=tries+1;
            p:=mcfactor(n,tries)
         >>;
         if tries>!*maxtrys!* then <<
            prin2 "ZFACTOR(mcfactor!*):Assuming ";
            prin2 n; prin2t " is prime";
            p:=list n
         >>
         else p
       >>)
          (mcfactor(n,1),1);
   if null cdr n then
      add!-factor(n,factors!-so!-far)
   else if (car n)<(cdr n) then
      mcfactor!*(cdr n,mcfactor!*(car n,factors!-so!-far))
   else
      mcfactor!*(car n,mcfactor!*(cdr n,factors!-so!-far))
>>;
 
symbolic procedure mcfactor(n,p);
% Based on "An Improved Monte-Carlo Factorisation Algorithm" by
% R.P.Brent in BIT 20 (1980) pp 176-184.  Argument n is the number to
% factor, p specifies the constant term of the polynomial.  There are
% supposed to be optimal p's for each n, but in general p=1 works well.
begin scalar gg,k,m,q,r,x,y,ys;
   m := 20;
   y:=0; r:=q:=1;
outer:
   x:=y;
   for i:=1:r do y:=remainder(y*y+p,n);
   k:=0;
inner:
   ys:=y;
   for i:=1:(if m<(r-k) then m else r-k) do <<
      y:=remainder(y*y+p,n);
      q:=remainder(q*abs(x-y),n)
   >>;
   gg:=gcdn(q,n);
   k:=k+m;
   if (k<r) and (gg leq 1) then goto inner;
   r:=2*r;
   if gg leq 1 then goto outer;
   if gg=n then begin
   loop:
      ys:=remainder(ys*ys+p,n);
      gg:=gcdn(abs(x-ys),n);
      if gg leq 1 then goto loop
   end;
   return if gg=n then n else gg . (n/gg)
end;
 
symbolic procedure primep n;
   % Returns T if n is prime (an integer that is not zero or a unit).
   if n<0 then primep(-n)
    else if n member !*primelist!* then t
    else if not fixp n
     then <<lprim list("No primep function defined for",n); nil>>
    else if n=1 then nil
    else if isqrt n<!*last!-prime!-in!-list!* then
      begin scalar p;
         p:=!*primelist!*;
      loop:
         if remainder(n,car p)=0 then return nil;
         if null(p:=cdr p) then return t;
         go loop
      end
    else if n>largest!-small!-modulus then general!-primep n
    else small!-primep n;
 
flag('(primep),'boolean);

symbolic procedure internal!-primep n;
   if n>largest!-small!-modulus then
      general!-primep n
   else
      small!-primep n;
 
%This is a version of primep written by FEB for inclusion in zfactor.
%It provides small-primep and general-primep with the following
%corrections of the distribution versions:
%(1) random number zero excluded as a potential witness
%(2) correct range of powers of seed provided
%(3) inspection for -1 replacing gcd's.

symbolic procedure small!-primep n;
% Based on an algorithm of M.Rabin published in the Journal of Number
% Theory Vol 12, pp 128-138 (1980).  This version uses small modular
% arithmetic which can be open coded.
begin scalar i,j,m,l,b2m,result,x,!*mod!*,oldmod;
   m:=n-1;
   l:=0;
   oldmod := set!-small!-modulus n;
      % first a quick check for compositeness
   if modular!-expt(3,m) neq 1 then <<set!-modulus oldmod; return nil>>;
   i:=20;
      % I think the next step is unnecessary
   while (!*mod!*:=2**i)<n do i:=i+4;
      % construct (2**l)*m from n-1
   while evenp m do << m:=m/2; l:=l+1 >>;
   i:=1;
   result:=t;
   b2m:=mkvect l;
   while result and i<=!*confidence!* do <<
         % pick a potential witness (which must be non-zero)
         % make a vector of b**m up to b**((2**(l-1))*m)
      x:=putv(b2m,1,modular!-expt((remainder(random(!*mod!*),n-1)+1),
              m));
      for j:=2:l do x:=putv(b2m,j,modular!-times(x,x));
         % if none of these is n-1 and the first isn't 1
         % we have a composite
         % a witness will lie about composites at most 1 time in 4
      j:=0;
      while ((x:=getv(b2m,l-j))= 1) and j<=l-2 do j:=j+1;
      if (x neq (n-1)) and ( (j neq l-1) or (x neq 1)) then result:=nil;
      i:=i+1
   >>;
   set!-modulus oldmod;
   return result
end;   

symbolic procedure general!-primep n;
% Based on an algorithm of M.Rabin published in the Journal of Number
% Theory Vol 12, pp 128-138 (1980).  This version uses general modular
% arithmetic which is somewhat more expensive than the above routine
begin integer i,j,l,m; scalar b2m,result,x,!*mod!*,oldmod;
   m:=n-1;
   l:=0;
   oldmod := set!-general!-modulus n;
      % first a quick check for compositeness
%   if general!-modular!-expt(3,m) neq 1 then return nil;
%   This check loops, since general!-modular!-expt calls primep
   if general!-modular!-expt(9,m/2) neq 1
    then <<set!-modulus oldmod; return nil>>;
   i:=32;
      %unnecessary?
   while (!*mod!*:=2**i)<n do i:=i+4;
      % construct (2**l)*m from n-1
   while evenp m do << m:=m/2; l:=l+1 >>;
   i:=1;
   result:=t;
   b2m:=mkvect l;
   while result and i<=!*confidence!* do <<
         % pick a potential witness
         % make a vector of b**m up to b**((2**(l-1))*m) 
         % squaring every time
      x:=putv(b2m,1,
              general!-modular!-expt((remainder(random(!*mod!*),n-1)+1),
                                     m));
      for k:=2:l do x:=putv(b2m,k,general!-modular!-times(x,x));
         % if none of these is n-1 and the first
         % isn't 1 we have a composite
         % a witness will lie about composites at most 1 time in 4
      j:=0;
      while ((x:=getv(b2m,l-j))= 1) and j<=l-2 do j:=j+1;
      if (x neq (n-1)) and ( (j neq l-1) or (x neq 1)) then result:=nil;
      i:=i+1
   >>;
   set!-modulus oldmod;
   return result
end;   

% The next function comes from J.H. Davenport.

symbolic procedure nextprime p;
   % Returns the next prime number bigger than p.
   if null p or p=0 or p=1 or p=-1 or p=-2 then 2
    else if p=-3 then -2
    else if not fixp p then typerr(!*f2a p,"integer")
    else begin
       if evenp p then p:=p+1 else p:=p+2;
       while not primep p do p:=p+2;
       return p
   end;

put('nextprime,'polyfn,'nextprime);

endmodule;


module sort;  % A simple sorting routine.

% Author: Arthur C. Norman.
% Modified by: Anthony C. Hearn to use list changing operations for
%              greater efficiency.

expr procedure sort(lst,fn);
   begin scalar tree;
      if null lst or null cdr lst then return lst;
      tree := list(car lst,nil);
      while pairp(lst := cdr lst) do treeadd(car lst,tree,fn);
      return tree2list(tree,nil)
   end;

expr procedure tree2list(tree,lst);
   % { Convert a sorted tree into a list}
   if null tree then lst
    else tree2list(cadr tree,car tree . tree2list(cddr tree,lst));

expr procedure treeadd(item,node,fn);
   % { add item to a node, using fn as an order predicate}
   if apply2(fn,item, car node)
     then if cadr node then treeadd(item,cadr node,fn)
           else rplaca(cdr node,list(item,nil))
    else if cddr node then treeadd(item,cddr node,fn)
    else rplacd(cdr node,list(item,nil));

% expr procedure treeadd(item,tree,fn);
%    % add item to a tree, using fn as an order predicate;
%    if null tree then item . (nil . nil)
%     else if apply2(fn,item,car tree)
%      then car tree . (treeadd(item,cadr tree,fn) . cddr tree)
%     else car tree . (cadr tree . treeadd(item,cddr tree,fn));

symbolic procedure idsort u;
   % lexicographically sort list of ids.
   sort(u,function idcompare);

symbolic procedure idcompare(u,v);
   % compare lexicographical ordering of two ids.
   idcomp1(explode2 u,explode2 v);

symbolic procedure idcomp1(u,v);
   if null u then t
    else if null v then nil
    else if car u eq car v then idcomp1(cdr u,cdr v)
    else orderp(car u,car v);

% Comparison functions and special cases for sorting.

symbolic procedure lesspcar(a,b); car a < car b;

symbolic procedure lesspcdr(a,b); cdr a < cdr b;

symbolic procedure lessppair(a,b);
    if car a = car b then cdr a<cdr b else car a<car b;

symbolic procedure greaterpcdr(a,b); cdr a > cdr b;

symbolic procedure lesspcdadr(a,b); cdadr a < cdadr b;

symbolic procedure lesspdeg(a,b);
   if domainp b then nil else if domainp a then t else ldeg a<ldeg b;

symbolic procedure ordopcar(a,b); ordop(car a,car b);

symbolic procedure orderfactors(a,b);
   if cdr a = cdr b then ordp(car a,car b) else cdr a < cdr b;

endmodule;


module reval; % Functions for algebraic evaluation of prefix forms.

% Author: Anthony C. Hearn.

% Copyright (c) 1991 RAND.  All rights reserved.

fluid '(!*exp !*intstr !*listargs !*resimp alglist!* dmode!*
        varstack!*);

switch listargs;

global '(!*resubs !*sqvar!* !*val);

symbolic procedure reval u;
   reval1(u,t);

symbolic procedure aeval u;
   reval1(u,nil);

symbolic procedure reval1(u,v);
   (begin scalar alglist!*,x,y;
      % We rebind alglist!* to avoid invalid computation in loops.
      if null u then return nil   % this may give trouble
       else if stringp u then return u
       else if fixp u
        then return if flagp(dmode!*,'convert) then reval2(u,v) else u
       else if atom u
        then if idp u and (x := get(u,'avalue))
               then if u memq varstack!* then recursiveerror u
                     else <<varstack!* := u . varstack!*;
                            return if y := get(car x,'evfn)
                                     then apply2(y,u,v)
                                    else reval1(cadr x,v)>>
              else nil
       else if not idp car u % or car u eq '!*comma!*
        then errpri2(u,t)
       else if car u eq '!*sq
        then return if caddr u and null !*resimp
                      then if null v then u else prepsqxx cadr u
                     else reval2(u,v)
       else if flagp(car u,'opfn) then return reval1(opfneval u,v)
       else if x := get(car u,'psopfn)
         then <<u := apply1(x,cdr u);
                if x := get(x,'cleanupfn) then u := apply2(x,u,v);
                return u>>
          % Note that we assume that the results of such functions are
          % always returned in evaluated form.
       else if arrayp car u then return reval1(getelv u,v);
       return if x := getrtype u then
                  if y := get(x,'evfn) then apply2(y,u,v)
                    else rerror(alg,101,
                                list("Missing evaluation for type",x))
               else if not atom u
                     and not atom cdr u
                     and null cddr u      % Don't pass opr to list if
                                          % there is more than one arg.
                     and (y := getrtype cadr u) eq 'list  % Only lists
                     and (x := get(y,'aggregatefn))       % for now.
                     and not !*listargs and not flagp(car u,'listargp)
                then apply2(x,u,v)
               else reval2(u,v)
   end) where varstack!* := varstack!*;

flagop listargp;

symbolic procedure recursiveerror u;
   msgpri(nil,u,"improperly defined in terms of itself",nil,t);

put('quote,'psopfn,'car);    % Since we don't want this evaluated.

symbolic procedure opfneval u;
   lispeval(car u . for each j in
                  (if flagp(car u,'noval) then cdr u else revlis cdr u)
                  collect mkquote j);

flag('(reval),'opfn);   % to make it a symbolic operator.

symbolic procedure reval2(u,v);  !*q2a1(simp!* u,v);

symbolic procedure getrtype u;
   % Returns overall algebraic type of u (or NIL is expression is a
   % scalar). Analysis is incomplete for efficiency reasons.
   % Type conflicts will later be resolved when expression is evaluated.
   begin scalar x,y;
    return
    if null u then nil   % Suggested by P.K.H. Gragert to avoid the
                         % loop caused if NIL has a share flag.
     else if atom u
      then if not idp u then not numberp u and getrtype1 u
            else if flagp(u,'share) % then getrtype lispeval u
             then if (x := eval u) eq u then nil else getrtype x
            else if (x := get(u,'avalue)) and not car x eq 'scalar
                    or (x := get(u,'rtype)) and (x := list x)
                    then if y := get(car x,'rtypefn) then apply1(y,nil)
                          else car x
                  else nil
     else if not idp car u then nil
     else if (x := get(car u,'avalue)) and (x := get(car x,'rtypefn))
      then apply1(x,cdr u)
     else getrtype2 u
   end;

symbolic procedure getrtype1 u;
   % Placeholder for packages that use vectors.
   nil;

symbolic procedure getrtype2 u;
   % Placeholder for packages that key expression type to the operator.
   begin scalar x;
     % Next line is maybe only needed by EXCALC.
      return if (x := get(car u,'rtype)) and (x := get(x,'rtypefn))
               then apply1(x,cdr u)
              else if x := get(car u,'rtypefn) then apply1(x,cdr u)
              else nil
   end;

deflist('
  ((difference getrtypecar)
   (expt getrtypecar)
   (minus getrtypecar)
   (plus getrtypecar)
   (quotient getrtypeor)
   (recip getrtypecar)
   (times getrtypeor)
   (!*sq (lambda (x) nil))
 ),'rtypefn);

symbolic procedure getrtypecar u; getrtype car u;

symbolic procedure getrtypeor u;
   u and (getrtype car u or getrtypeor cdr u);

symbolic procedure !*eqn2a u;
   % If u is an equation a=b, it is converted to an equivalent equation
   % a-b=0, or if a=0, b=0.  Otherwise u is returned converted to true
   % prefix form.
   if not eqexpr u then prepsqyy u
    else if null cdr u or null cddr u or cdddr u
     then typerr(u,"equation")
    else (if rh=0 then lh else if lh=0 then rh else{'difference,lh,rh})
          where lh=prepsqyy cadr u,rh=prepsqyy caddr u;

symbolic procedure prepsqyy u;
   if eqcar(u,'!*sq) then prepsqxx cadr u else u;

symbolic procedure getelv u;
   % Returns the value of the array element U.
   getel(car u . for each x in cdr u collect ieval x);

symbolic procedure setelv(u,v);
   setel(car u . for each x in cdr u collect ieval x,v);

symbolic procedure revlis u; for each j in u collect reval j;

symbolic procedure revop1 u;
   if !*val then car u . revlis cdr u else u;

symbolic procedure mk!*sq u;
   if null numr u then 0
    else if atom numr u and denr u=1 then numr u
    else '!*sq . expchk u . if !*resubs then !*sqvar!* else list nil;

symbolic macro procedure !*sq u;
   % Provide an interface to symbolic mode.
   prepsq cadr u;

symbolic procedure expchk u; if !*exp then u else offexpchk u;

symbolic procedure lengthreval u;
   begin scalar v,w;
      if length u neq 1
        then rerror(alg,11,
                    "LENGTH called with wrong number of arguments")
       else if idp car u and arrayp car u
        then return 'list . get(car u,'dimension);
      v := aeval car u;
      if (w := getrtype v) and (w := get(w,'lengthfn))
        then return apply1(w,v)
       else if atom v then return 1
       else if not idp car v or not(w := get(car v,'lengthfn))
        then typerr(u,"length argument")
       else return apply1(w,cdr v)
   end;

put('length,'psopfn,'lengthreval);


% Code for evaluation of expressions whose type can only be
% infered after partial evaluation.

symbolic procedure yetunknowntypeeval(u,v);
   % Assumes that only psopfn's can produce yet unknown types.
   reval1(eval!-yetunknowntypeexpr(u,v),v);

symbolic procedure eval!-yetunknowntypeexpr(u,v);
   if atom u 
      then ((if w then eval!-yetunknowntypeexpr(cadr w,v)
              else u)
            where w = get(u,'avalue))
    else if car u eq '!*sq then u
    else ((if x and (getrtype u eq 'yetunknowntype)
              then apply1(x,cdr u)
            else car u . for each j in cdr u collect
                             eval!-yetunknowntypeexpr(j,v))
          where x = get(car u,'psopfn));

put('yetunknowntype,'evfn,'yetunknowntypeeval);

endmodule;


module algbool; % Evaluation functions for algebraic boolean operators.

% Author: Anthony C. Hearn.

% Copyright (c) 1987 The RAND Corporation.  All rights reserved.

symbolic procedure evalequal(u,v);
   begin scalar x;
      return if (x := getrtype u) neq getrtype v then nil
              else if null x
               then numberp(x := reval list('difference,u,v))
                       and zerop x
              else u=v
   end;

put('equal,'boolfn,'evalequal);

% symbolic procedure equalreval u; 'equal . revlis u;  % defined in eqn.

% put('equal,'psopfn,'equalreval);

put('equal,'rtypefn,'quoteequation);

symbolic procedure quoteequation u; 'equation;

symbolic procedure evalgreaterp(u,v);
   (lambda x;
    if not atom denr x or not domainp numr x
      then typerr(mk!*sq if minusf numr x then negsq x else x,"number")
     else numr x and !:minusp numr x)
        simp!* list('difference,v,u);

put('greaterp,'boolfn,'evalgreaterp);

symbolic procedure evalgeq(u,v); not evallessp(u,v);

put('geq,'boolfn,'evalgeq);

symbolic procedure evallessp(u,v); evalgreaterp(v,u);

put('lessp,'boolfn,'evallessp);

symbolic procedure evalleq(u,v); not evalgreaterp(u,v);

put('leq,'boolfn,'evalleq);

symbolic procedure evalneq(u,v); not evalequal(u,v);

put('neq,'boolfn,'evalneq);

symbolic procedure evalnumberp u; 
   (if atom x then numberp x
     else if not(car x eq '!*sq) or not atom denr cadr x then nil
     else (atom y or flagp(car y,'numbertag)) where y=numr cadr x)
    where x=aeval u;

put('numberp,'boolfn,'evalnumberp);

% Number tags.

flag('(!:bf!: !:rd!: !:cr!: !:rn!: !:crn!: !:mod!: !:gi!:),'numbertag);

endmodule;


module simp; % Functions to convert prefix forms into canonical forms.

% Author: Anthony C. Hearn.

% Modifications by: J.H. Davenport, F. Kako, S. Kameny and E. Schruefer.

% Copyright (c) 1991 RAND.  All rights reserved.

fluid '(!*asymp!* !*complex !*exp !*gcd !*ifactor !*keepsqrts !*mcd
        !*mode !*notseparate !*numval !*precise !*rationalize !*reduced
        !*resimp !*sub2 !*uncached alglist!* dmd!* dmode!* varstack!*);

fluid '(!*combinelogs);

global '(!*match
         den!*
%        exptl!*   No-one else refers to this variable - just slows us
         frlis!*
         initl!*
         mul!*
         ncmp!*
         powlis1!*
         simpcount!*
         simplimit!*
         subfg!*
         tstack!*
         ws);

switch notseparate;

% !*KEEPSQRTS uses SQRT rather than EXPT for square roots.
% Normally set TRUE in the integrator, false elsewhere.

put('ifactor,'simpfg,'((t (rmsubs))));

put('simpcount!*,'initl,0);

initl!* := union('(simpcount!*),initl!*);

simplimit!* := 1000;

flagop noncom;

symbolic procedure simp!* u;
   begin scalar !*asymp!*,x;
        if eqcar(u,'!*sq) and caddr u and null !*resimp
          then return cadr u;
        x := mul!* . !*sub2;    % Save current environment.
        mul!* := nil;
        u:= simp u;
        for each j in mul!* do u:= apply1(j,u);
        mul!* := car x;
        u := subs2 u;
        if !*combinelogs then u := clogsq!* u;
        % must be here, since clogsq!* can upset girationalizesq!:.
        if dmode!* eq '!:gi!: then u := girationalize!: u
          else if !*rationalize then u := rationalizesq u;
        !*sub2 := cdr x;
        % If any leading terms have cancelled, a gcd check is required.
        if !*asymp!* and !*rationalize then u := gcdchk u;
        return u
   end;

symbolic procedure subs2 u;
   begin scalar xexp,v,w;
    if null subfg!* then return u
     else if !*sub2 or powlis1!* then u := subs2q u;
    if null !*match or null numr u then return u
     else if null !*exp
      then <<xexp:= t; !*exp := t; v := u; w := u := resimp u>>;
    u := subs3q u;
    if xexp then <<!*exp := nil; if u=w then u := v>>;
    return u
   end;

symbolic procedure simp u;
   (begin scalar x;
    % This case is sufficiently common it is done first.
    if fixp u
      then if u=0 then return nil ./ 1
            else if not dmode!* then return u ./ 1
            else nil
     else if u member varstack!* then recursiveerror u;
    varstack!* := u . varstack!*;
 if simpcount!*>simplimit!*
     then <<simpcount!* := 0;
            rerror(alg,12,"Simplification recursion too deep")>>
     else if eqcar(u,'!*sq) and caddr u and null !*resimp
      then return cadr u
     else if null !*uncached and (x := assoc(u,car alglist!*))
      then return <<if cadr x then !*sub2 := t; cddr x>>;
 simpcount!* := simpcount!*+1; % undone by returning through !*SSAVE
    if atom u then return !*ssave(simpatom u,u)
     else if not idp car u
      then if idp caar u and (x := get(caar u,'name))
                 then return !*ssave(u,u)     %%% not yet correct
     else if eqcar(car u,'mat)
             and numlis(x := revlis cdr u) and length x=2
           then return !*ssave(simp nth(nth(cdar u,car x),cadr x),u)
        else errpri2(u,t)
     else if flagp(car u,'opfn)
      then if getrtype(x := opfneval u) then typerr(u,"scalar")
        else return !*ssave(simp x,u)
     else if x := get(car u,'psopfn)
      then if getrtype(x := apply1(x,cdr u)) then typerr(u,"scalar")
        else if x=u then return !*ssave(!*k2q x,u)
        else return !*ssave(simp x,u)
     % Note in above that the psopfn MUST return a *sq form,
     % otherwise an infinite recursion occurs.
     else if x := get(car u,'polyfn)
      then return !*ssave(!*f2q lispapply(x,
            for each j in cdr u collect !*q2f simp!* j),
            u)
     else if get(car u,'opmtch)
        and not(get(car u,'simpfn) eq 'simpiden)
        and (x := opmtch revop1 u)
      then return !*ssave(simp x,u)
     else if x := get(car u,'simpfn)
      then return !*ssave(apply1(x,
                                 if x eq 'simpiden or flagp(car u,'full)
                                   then u
                                 else cdr u),
                          u)
     else if (x := get(car u,'rtype)) and (x := get(x,'getelemfn))
      then return !*ssave(simp apply1(x,u),u)
     else if flagp(car u,'boolean) or get(car u,'infix)
      then typerr(if x := get(car u,'prtch) then x else car u,
              "algebraic operator")
     else if flagp(car u,'nochange)
      then return !*ssave(simp lispeval u,u)
     else if get(car u,'psopfn) or get(car u,'rtypefn)
      then typerr(u,"scalar")
     else <<redmsg(car u,"operator");
        mkop car u;
        varstack!* := delete(u,varstack!*);
        return !*ssave(simp u,u)>>;
   end) where varstack!* = varstack!*;

put('array,'getelemfn,'getelv);

put('array,'setelemfn,'setelv);

symbolic procedure getinfix u;
   %finds infix symbol for U if it exists;
   begin scalar x; return if x := get(u,'prtch) then x else u end;

symbolic procedure !*ssave(u,v);
   % We keep sub2!* as well, since there may be an unsubstituted
   % power in U.
   begin
      if not !*uncached
    then rplaca(alglist!*,(v . (!*sub2 . u)) . car alglist!*);
      simpcount!* := simpcount!*-1;
      return u
   end;

symbolic procedure numlis u;
   null u or (numberp car u and numlis cdr u);

symbolic procedure simpatom u;
%  if null u then typerr("NIL","algebraic identifier")
   if null u then nil ./ 1   % Allow NIL as default 0.
    else if numberp u
     then if u=0 then nil ./ 1
           else if not fixp u then ('!:rd!: . cdr fl2bf u) ./ 1
             % we assume that a non-fixp number is a float.
           else if flagp(dmode!*,'convert) and u neq 1 % Don't convert 1
            then !*d2q apply1(get(dmode!*,'i2d),u)
           else u ./ 1
    else if stringp u then typerr(list("String",u),"identifier")
    else if flagp(u,'share) then
      <<(if x eq u then mksq(u,1) else simp x) where x=lispeval u>>
    else begin scalar z;
      if z := get(u,'idvalfn) then return apply1(z,u)
       else if !*numval and dmode!* and flagp(u,'constant)
          and (z := get(u,dmode!*))
          and not errorp(z := errorset!*(list('lispapply,mkquote z,nil),
                         nil))
        then return !*d2q car z
       else if getrtype u then typerr(u,'scalar)
       else return mksq(u,1) end;

flag('(e pi),'constant);

symbolic procedure mkop u;
   begin scalar x;
    if null u then typerr("Local variable","operator")
     else if (x := gettype u) eq 'operator
      then lprim list(u,"already defined as operator")
     else if x and not(x memq '(fluid global procedure))
      then typerr(u,'operator)
     else if u memq frlis!* then typerr(u,"free variable")
     else put(u,'simpfn,'simpiden)
   end;

symbolic procedure operatorp u;
    gettype u eq 'operator;

symbolic procedure simpcar u;
   simp car u;

put('quote,'simpfn,'simpcar);

symbolic procedure share u;
   begin scalar y;
      for each v in u do
         if not idp v then typerr(v,"id")
         else if flagp(v,'share) then nil
         else if flagp(v,'reserved) then rsverr v
         else if (y := getrtype v) and y neq 'list
            then rerror(alg,13,list(y,v,"cannot be shared"))
         else
          % if algebraic value exists, transfer to symbolic.
         <<if y then remprop(v,'rtype);
           if y := get(v,'avalue)
             then <<setifngfl(v,cadr y); remprop(v,'avalue)>>
          % if no algebraic value but symbolic value, leave unchanged.
            else if not boundp v then setifngfl(v,v);
          % if previously unset, set symbolic self pointer.
           flag(list v,'share)>>
   end;

symbolic procedure boundp u;
   % Determines if the id u has a value.
   % NB:  this function must be redefined in many systems (e.g., CL).
   null errorp errorset!*(u,nil);

symbolic procedure setifngfl(v,y);
   <<if not globalp v then fluid list v; set(v,y)>>;

rlistat '(share);

flag('(ws !*mode),'share);

flag('(share),'eval);


% ***** SIMPLIFICATION FUNCTIONS FOR EXPLICIT OPERATORS - EXP *****

symbolic procedure simpexpon u;
   % Exponents must not use non-integer arithmetic unless NUMVAL is on,
   % in which case DOMAINVALCHK must know the mode.
%   if !*numval and not(dmode!* eq '!:mod!:) then simp!* u
% Above version assumed that all non-modular domains were floating
   if !*numval and (dmode!* eq '!:rd!: or dmode!* eq '!:cr!:) 
    then simp!* u
    else begin scalar dmode!*,alglist!*; return simp!* u; end;

symbolic procedure simpexpt u;
   simpexpt1(car u,simpexpon carx(cdr u,'expt),nil);

symbolic procedure simpexpt1(u,n,flg);
   % FLG indicates whether we have done a PREPSQ SIMP!* U or not: we
   % don't want to do it more than once.
   begin scalar m,x,y;
      if onep u then return 1 ./ 1;
      m := numr n;
      if m=1 and denr n=1 then return simp u;
     % this simplifies e^(n log x) -> x^n  for all n,x.
      if u eq 'e and domainp denr n and not domainp m and ldeg m=1
         and null red m and eqcar(mvar m,'log) then return
            simpexpt1(prepsq simp!* cadr mvar m,lc m ./ denr n,nil);
      if not domainp m or not domainp denr n
        then return simpexpt2(u,n,flg)
       else if null m
        then return if u=0 then rerror(alg,14," 0**0 formed")
                     else 1 ./ 1;
      x := simp u;
      % We could use simp!* here, except it messes up the handling of
      % gamma matrix expressions.
      return if null numr x
               then if m<0 then rerror(alg,15,"Zero divisor")
                     else nil ./ 1
              else if atom m and denr n=1 and domainp numr x
                 and denr x=1
               then if atom numr x and m>0 then !*d2q(numr x**m)
                     else !:expt(numr x,m) ./ 1
              else if y := domainvalchk('expt,list(x,n)) then y
              else if atom m and denr n=1
               then <<if not m<0 then exptsq(x,m)
                       else if !*mcd then invsq exptsq(x,-m)
                       else multf(expf(numr x,m),mksfpf(denr x,-m))
                               ./ 1>>     % This uses OFF EXP option.
                      % There may be a pattern matching problem though.
              else simpexpt2(if flg then u else prepsq x,n,t)
   end;

symbolic procedure simpexpt2(u,n,flg);
   % The "non-numeric exponent" case.  FLG indicates whether we have
   % done a PREPSQ SIMP!* U or not: we don't want to do it more than
   % once.
   begin scalar m,n,x,y;
    if u=1 then return 1 ./ 1
     else if fixp u and u>0 and (u<10000 or !*ifactor)
       and (length(x := zfactor u)>1 or cdar x>1)
      then <<y := 1 ./ 1;
             for each j in x do
                y := multsq(simpexpt list(car j,
                                          prepsq multsq(cdr j ./ 1,n)),
                            y);
             return y>>;
    m:=numr n;
    if pairp u then <<
     if car u eq 'expt
      then <<n:=multsq(m:=simp caddr u,n);
             if !*precise
                and numberp numr m and evenp numr m
%               and numberp numr n and not evenp numr n
               then u := list('abs,cadr u)
              else u := cadr u;
             return simpexpt1(u,n,flg)>>
     else if car u eq 'sqrt and not !*keepsqrts
      then return simpexpt2(cadr u, multsq(1 ./ 2,n),flg)
      else if car u eq 'times
            then <<x := 1 ./ 1;
                   for each z in cdr u do
                      x := multsq(simpexpt1(z,n,flg),x);
                   return x>>
     else if car u eq 'quotient
      then <<if not flg and !*mcd then
                return simpexpt1(prepsq simp!* u,n,t);
             n := prepsq n;
             return multsq(simpexpt list(cadr u,n),
                           simpexpt list(caddr u,list('minus,n)))>>
     % Special case of (-expression)^(1/2).
     else if car u eq 'minus
             and (n = '(1 . 2) or n = '((!:rd!: . 0.5) . 1)
                  or n = '((!:rd!: 5 . 1) . 1)
                  or n = '((!:rn!: 1 . 2) . 1))
      then return simptimes list('i,list('expt,cadr u,prepsq n))>>;
%    else if car u eq 'minus and numberp m and denr n=1
%     then return multsq(simpexpt list(-1,m),
%                simpexpt list(cadr u,m))>>;
    if null flg
      then <<% Don't expand say e and pi, since whole expression is not
             % numerical.
             if null(dmode!* and idp u and get(u,dmode!*))
               then u := prepsq simp!* u;
             return simpexpt1(u,n,t)>>
     else if numberp u and zerop u then return nil ./ 1
     else if not numberp m then m := prepf m;
    n := prepf denr n;
    if m memq frlis!* and n=1 then return list ((u . m) . 1) . 1;
       % "power" is not unique here.
    if !*mcd or not numberp m or n neq 1
      or atom u or denr simp!* u neq 1 then return simpx1(u,m,n)
      else return mksq(u,m)  % To make pattern matching work.
   end;

put('expt,'simpfn,'simpexpt);

symbolic procedure conv2gid(u,d);
   if null u or numberp u or eqcar(u,'!:gi!:) then d
    else if domainp u
     then if eqcar(u,'!:crn!:) then lcm(d,lcm(cdadr u,cdddr u))
           else if eqcar(u,'!:rn!:) then lcm(d,cddr u) else d
    else conv2gid(lc u,conv2gid(red u,d));

symbolic procedure conv2gi2 u;
   if null u then u
   else if numberp u then u * den!*
   else if eqcar(u,'!:gi!:) then '!:gi!:.((den!**cadr u).(den!**cddr u))
   else if eqcar(u,'!:crn!:)
    then <<u := cdr u;
           u:= '!:gi!: . ((den!*/cdar u*caar u).(den!*/cddr u*cadr u))>>
   else if eqcar(u,'!:rn!:) then den!*/cddr u*cadr u
   else if domainp u then rerror(alg,16,list("strange domain",u))
   else lpow u .* conv2gi2(lc u) .+ conv2gi2(red u);

symbolic procedure simpx1(u,m,n);
   % U,M and N are prefix expressions.
   % Value is the standard quotient expression for U**(M/N).
   % FLG is true if we have seen a "-" in M.
    begin scalar flg,x,z;
      % Check for imaginary result.
      if eqcar(u,'minus)
         then if m=1 and fixp n and remainder(n,2)=0
             or n=1 and eqcar(m,'quotient) and cadr m=1 and fixp caddr m
               and remainder(caddr m,2)=0
                 then return multsq(simp list('expt,'i,
                                              list('quotient,'1,n/2)),
                          simpexpt list(cadr u,list('quotient,m,n)))
      % and for negative result.
                else if m=1 and fixp n          % n must now be odd.
                 then return negsq
                          simpexpt list(cadr u,list('quotient,m,n));
    if numberp m and numberp n
       or null(smemqlp(frlis!*,m) or smemqlp(frlis!*,n))
      then go to a;
    % exptp!* := t;
    return mksq(list('expt,u,if n=1 then m
                   else list('quotient,m,n)),1);
    a:
    if numberp m then
        if minusp m then <<m := -m; go to mns>>
           else if fixp m then
                   if fixp n then <<
                      if flg then m := -m;
                      z := m;
                      if !*mcd and (fixp u or null !*notseparate)
                        then <<z := z-n*(m := m/n);
                               if z<0 then <<m := m-1; z := z+n>>>>
                       else m := 0;
                      x := simpexpt list(u,m);
                      if z=0 then return x
                      else if n=2 and !*keepsqrts
                       then return multsq(x,apply1(get('sqrt,'simpfn),
                                                   list u))
      % Note the indirect call: the integrator rebinds this property.
      % JHD understands this interaction - don't change without
      % consulting him.  Note that, since KEEPSQRTS is true, SIMPSQRT
      % won't recurse on SIMPEXPT1.
                      else return
                              multsq(x,exptsq(simprad(simp!* u,n),z))>>
                   else <<z := m; m := 1>>
                else z:=1
     else if atom m then z:=1
     else if car m eq 'minus then <<m := cadr m; go to mns>>
     else if car m eq 'plus then <<
         z := 1 ./ 1;
         for each x in cdr m do
             z := multsq(simpexpt list(u,
                         list('quotient,if flg then list('minus,x)
                                               else x,n)),
                           z);
         return z >>
     else if car m eq 'times and fixp cadr m and numberp n
      then <<
        z := gcdn(n,cadr m);
        n := n/z;
        z := cadr m/z;
        m := retimes cddr m >>
     else if car m eq 'quotient and n=1
      then <<n := caddr m; m := cadr m; go to a>>
     else z := 1;
     if idp u and not flagp(u,'used!*) then flag(list u,'used!*);
        if u = '(minus 1)
               and n=1
               and null numr simp list('difference,m,'(quotient 1 2))
         then <<u := simp 'i; return if flg then negsq u else u>>;
    u := list('expt,u,if n=1 then m else list('quotient,m,n));
    return mksq(u,if flg then -z else z); %U is already in lowest terms;
    mns: %if numberp m and numberp n and !*rationalizeflag
     %  then return multsq(simpx1(u,n-m,n),invsq simp u) else
    if !*mcd then return invsq simpx1(u,m,n);
    flg := not flg;
    go to a;
   end;

symbolic procedure expf(u,n);
   %U is a standard form. Value is standard form of U raised to
   %negative integer power N. MCD is assumed off;
   %what if U is invertable?;
   if null u then nil
    else if u=1 then u
    else if atom u then mkrn(1,u**(-n))
    else if domainp u then !:expt(u,n)
    else if red u then mksp!*(u,n)
    else (lambda x; if x>0 and sfp mvar u
             then multf(exptf(mvar u,x),expf(lc u,n))
            else mvar u .** x .* expf(lc u,n) .+ nil)
     (ldeg u*n);

% ******* The "radical simplifier" section ******

symbolic procedure simprad(u,n);
   % Simplifies radical expressions.
   begin scalar iflag,x,y,z;
   if !*reduced then <<
       % it is legitimate to treat NUM and DEN separately.
       x := radf(numr u,n);
       y := radf(denr u,n);
       z := multsq(if !*precise and evenp n 
                             then mkabsf1 car x 
                           else car x ./ 1,1 ./ car y);
       z := multsq(multsq(mkrootlsq(cdr x,n),invsq mkrootlsq(cdr y,n)),
           z);
       return z >>
     else <<
       if !*rationalize then << % Move all radicands into numerator.
          y:=list(denr u,1); % A partitioned expression.
          u:=multf(numr u, exptf(denr u,n-1)) ./ 1 >>
         else y := radf(denr u,n);
       if 2 = n and minusf numr u then << % Should this be 'evenp n'?
            iflag := t;    
            x := radf(negf numr u,n) >>
          else x := radf(numr u,n);
       z := simp list('quotient,retimes cdr x, retimes cdr y);
       if domainp numr z and domainp denr z
      % This test allows transformations like sqrt(2/3)=>sqrt(2)/sqrt(3)
      % whereas we really don't want to do this for symbolic elements
      % since we can introduce paradoxes that way.
          then z := multsq(mkrootsq(prepf numr z,n),
                         invsq mkrootsq(prepf denr z,n))
          else <<
            if iflag then <<
               iflag := nil; % We must absorb the "i" in square root.
               z := negsq z >>;
            z := mkrootsq(prepsq z,n) >>;
       z := multsq(multsq(if !*precise and evenp n 
                             then mkabsf1 car x 
                           else car x ./ 1, 1 ./ car y), z);
       if iflag then z := multsq(z,mkrootsq(-1,2));
       return z >>
   end;

symbolic procedure mkrootlsq(u,n);
   % U is a list of prefix expressions, N an integer.
   % Value is standard quotient for U**(1/N);
   % NOTE we need the REVAL call so that PREPSQXX is properly called on
   % the argument for consistency with the pattern matcher.  Otherwise
   % for all x,y let sqrt(x)*sqrt(y)=sqrt(x*y); sqrt(30*(l+1))*sqrt 5;
   % goes into an infinite loop.
   if null u then !*d2q 1
    else if null !*reduced then mkrootsq(reval retimes u,n)
    else mkrootlsq1(u,n);

symbolic procedure mkrootlsq1(u,n);
   if null u then !*d2q 1
    else multsq(mkrootsq(car u,n),mkrootlsq1(cdr u,n));


symbolic procedure mkrootsq(u,n);
   %U is a prefix expression, N an integer.
   %Value is a standard quotient for U**(1/N);
   if u=1 then !*d2q 1
    else if n=2 and (u= -1 or u= '(minus 1)) then simp 'i
    else if eqcar(u,'expt) and fixp caddr u
          then exptsq(mkrootsq(cadr u,n),caddr u)
          else begin scalar x,y;
           x := if n=2 then mksqrt u
                 else list('expt,u,list('quotient,1,n));
           if y := opmtch x then return simp y
            else return mksq(x,1)
         end;


Comment The following three procedures return a partitioned root
    expression, which is a dotted pair of integral part (a standard
    form) and radical part (a list of prefix expressions). The whole
    structure represents U**(1/N);

symbolic procedure radf(u,n);
   %U is a standard form, N a positive integer. Value is a partitioned
   %root expression for U**(1/N);
   begin scalar ipart,rpart,x,y,z,!*gcd;
      if null u then return list u;
      !*gcd := t;
      ipart := 1;
      z := 1;
      while not domainp u do
     <<y := comfac u;
       if car y
         then <<x := divide(pdeg car y,n);
            if car x neq 0
              then ipart:=multf(!*p2f if null !*precise
                         or evenp car x
                        then mvar u .** car x
                     else mksp(list('abs,mvar u),
                           car x),
                    ipart);
            if cdr x neq 0
              then rpart :=
               mkexpt(if sfp mvar u then prepf mvar u
                   else mvar u,cdr x) . rpart>>;
       x := quotf1(u,comfac!-to!-poly y);
       u := cdr y;
       if !*reduced and minusf x
         then <<x := negf x; u := negf u>>;
       if flagp(dmode!*,'field) then
          <<y := lnc x;
                if y neq 1 then <<x := quotf1(x,y); z := multd(y,z)>>>>;
       if x neq 1
         then <<x := radf1(sqfrf x,n);
       ipart := multf(car x,ipart);
       rpart := append(rpart,cdr x)>>>>;
      if u neq 1
    then <<x := radd(u,n);
           ipart := multf(car x,ipart);
           rpart := append(cdr x,rpart)>>;
      if z neq 1
    then if !*numval
        and (y := domainvalchk('expt,
                       list(!*f2q z,!*f2q !:recip n)))
           then ipart := multd(!*q2f y,ipart)
          else rpart := prepf z . rpart;  % was aconc(rpart,z)
      return ipart . rpart
   end;

symbolic procedure radf1(u,n);
   %U is a form_power list, N a positive integer. Value is a
   %partitioned root expression for U**(1/N);
   begin scalar ipart,rpart,x;
      ipart := 1;
      for each z in u do
     <<x := divide(cdr z,n);
       if not(car x=0)
            then ipart := multf(exptf(car z,car x),ipart);
          if not(cdr x=0)
            then rpart := mkexpt(prepsq!*(car z ./ 1),cdr x)
                   . rpart>>;
      return ipart . rpart
   end;

symbolic procedure radd(u,n);
   %U is a domain element, N an integer.
   %Value is a partitioned root expression for U**(1/N);
   begin scalar bool,ipart,x;
      if not atom u then return list(1,prepf u);
%      then if x := integer!-equiv u then u := x
%            else return list(1,prepf u);
      if u<0 and evenp n then <<bool := t; u := -u>>;
      x := nrootn(u,n);
      if bool then if !*reduced and n=2
             then <<ipart := multd(car x,!*k2f 'i);
                x := cdr x>>
            else <<ipart := car x; x := -cdr x>>
       else <<ipart := car x; x := cdr x>>;
      return if x=1 then list ipart else list(ipart,x)
   end;

symbolic procedure iroot(m,n);
   %M and N are positive integers.
   %If M**(1/N) is an integer, this value is returned, otherwise NIL;
   begin scalar x,x1,bk;
      if m=0 then return m;
      x := 10**iroot!-ceiling(lengthc m,n);   %first guess;
   a: x1 := x**(n-1);
      bk := x-m/x1;
      if bk<0 then return nil
       else if bk=0 then return if x1*x=m then x else nil;
      x := x - iroot!-ceiling(bk,n);
      go to a
   end;

symbolic procedure iroot!-ceiling(m,n);
   %M and N are positive integers. Value is ceiling of (M/N) (i.e.,
   %least integer greater or equal to M/N);
   (lambda x; if cdr x=0 then car x else car x+1) divide(m,n);

symbolic procedure mkexpt(u,n);
   if n=1 then u else list('expt,u,n);

% The following definition is due to Eberhard Schruefer.

symbolic procedure nrootn(n,x);
   % N is an integer, x a positive integer. Value is a pair
   % of integers r,s such that r*s**(1/x)=n**(1/x).
   begin scalar fl,r,s,m,signn;
     r := 1;
     s := 1;
     if n<0 then <<n := -n; if evenp x then signn := t else r := -1>>;
     fl := zfactor n;
     for each j in fl do
         <<m := divide(cdr j,x);
           r := car j**car m*r;
           s := car j**cdr m*s>>;
     if signn then s := -s;
     return r . s
   end;

% symbolic procedure nrootn(n,x);
%   % N is an integer, X a positive integer. Value is a pair
%   % of integers I,J such that I*J**(1/X)=N**(1/X).
%   begin scalar i,j,r,signn;
%      r := 1;
%      if n<0 then <<n := -n; if evenp x then signn := t else r := -1>>;
%      j := 2**x;
%      while remainder(n,j)=0 do <<n := n/j; r := r*2>>;
%      i := 3;
%      j := 3**x;
%      while j<=n do
%         <<while remainder(n,j)=0 do <<n := n/j; r := r*i>>;
%           if remainder(i,3)=1 then i := i+4 else i := i+2;
%           j := i**x>>;
%      if signn then n := -n;
%      return r . n
%   end;

% ***** simplification functions for other explicit operators *****

symbolic procedure simpiden u;
   % Convert the operator expression U to a standard quotient.
   % Note: we must use PREPSQXX and not PREPSQ* here, since the REVOP1
   % in SUBS3T uses PREPSQXX, and terms must be consistent to prevent a
   % loop in the pattern matcher.
   begin scalar bool,fn,x,y,z;
    fn := car u; u := cdr u;
    % Allow prefix ops with names of symbolic functions.
    if (get(fn,'!:rn!:) or get(fn,'!:rd!:)) and (x := valuechk(fn,u))
      then return x;
    % Keep list arguments in *SQ form.
    if u and eqcar(car u,'list) and null cdr u
      then return mksq(list(fn,aeval car u),1);
    x := for each j in u collect aeval j;
    u := for each j in x collect
              if eqcar(j,'!*sq) then prepsqxx cadr j
               else if numberp j then j
               else <<bool := t; j>>;
    if u and car u=0
       and flagp(fn,'odd) and not flagp(fn,'nonzero)
      then return nil ./ 1;
    u := fn . u;
    if flagp(fn,'noncom) then ncmp!* := t;
    if null subfg!* then go to c
     else if flagp(fn,'linear) and (z := formlnr u) neq u
      then return simp z
     else if z := opmtch u then return simp z
     else if z := get(car u,'opvalfn) then return apply1(z,u);
 %    else if null bool and (z := domainvalchk(fn,
 %                for each j in x collect simp j))
 %     then return z;
    c:  if flagp(fn,'symmetric) then u := fn . ordn cdr u
     else if flagp(fn,'antisymmetric)
      then <<if repeats cdr u then return (nil ./ 1)
          else if not permp(z:= ordn cdr u,cdr u) then y := t;
         % The following patch was contributed by E. Schruefer.
         fn := car u . z;
         if z neq cdr u and (z := opmtch fn)
           then return if y then negsq simp z else simp z;
         u := fn>>;
    if (flagp(fn,'even) or flagp(fn,'odd))
       and x and minusf numr(x := simp car x)
     then <<if flagp(fn,'odd) then y := not y;
        u := fn . prepsqxx negsq x . cddr u;
        if z := opmtch u
          then return if y then negsq simp z else simp z>>;
    u := mksq(u,1);
    return if y then negsq u else u
   end;

flagop even,odd,nonzero;

symbolic procedure domainvalchk(fn,u);
   begin scalar fl;
      u := for each a in u collect
        <<if denr a neq 1 then fl := t; mk!*sq a>>;
      return if fl then nil else valuechk(fn,u) end;

symbolic procedure valuechk(fn,u);
   begin scalar n;
      if (n := get(fn,'number!-of!-args)) and length u neq n
         or not n
            and u and cdr u and (get(fn,'!:rd!:) or get(fn,'!:rn!:))
       then rerror(alg,17,list("Wrong number of arguments to",fn));
      u := opfchk!!(fn . u);
      if u then return znumrnil
        <<if eqcar(u,'!:cr!:) then u := gf2cr!: crrnd crprcd u;
          (if eqcar(u,'list) then list((u . 1) . 1) else u) ./ 1>>
   end;

symbolic procedure znumrnil u; if znumr u then nil ./ 1 else u;

symbolic procedure znumr u;
   null (u := numr u) or numberp u and zerop u
   or not atom u and domainp u and
     (y and apply1(y,u) where y=get(car u,'zerop));

symbolic procedure opfchk!! u;
   begin scalar fn,fn1,sf,sc,int,ce; fn1 := fn := car u; u := cdr u;
     % first save fn and check to see whether fn is defined.
     % Integer functions are defined in !:rn!:,
     % real functions in !:rd!:, and complex functions in !:cr!:.
      fn := if flagp(fn,'integer) then <<int := t; get(fn,'!:rn!:)>>
         else if !*numval and dmode!* memq '(!:rd!: !:cr!:)
            then get(fn,'!:rd!:);
      if not fn then return nil;
      sf := if int then 'simprn
         else if (sf := get(fn,'simparg)) then sf else 'simprd;
     % real function fn is defined.  now check for complex argument.
      if int or not !*complex then go to s; % the simple case.
     % mode is complex, so check for complex argument.
     % list argument causes a slight complication.
      if eqcar(car u,'list)
         then if (sc := simpcr revlis cdar u) and eqcar(sc,nil)
            then go to err else go to s;
      if not (u := simpcr revlis u) then return nil
     % if argument is real, evaluate real function, but if error
     % occurs, then evaluate complex function.
      else if not eqcar(u,nil) then <<ce := cdr u; u := car u; go to s>>
         else u := cdr u;
     % argument is complex or real function failed.
     % now check whether complex fn is defined.
 evc: if fn := get(fn1,'!:cr!:) then go to a;
 err: rerror(alg,18,list(fn1,"is not defined as complex function"));
   s: if not (u := apply1(sf, revlis u)) then return nil;
   a: u := errorset!*(list('apply,mkquote fn,mkquote u),nil);
      if errorp u then
         if ce then <<u := ce; ce := nil; go to evc>> else return nil
       else return if int then intconv car u else car u
   end;

symbolic procedure intconv x;
   if null dmode!* or dmode!* memq '(!:rd!: !:cr!:) then x
   else apply1(get(dmode!*,'i2d),x);

symbolic procedure simpcr x;
 % Returns simprd x if all args are real, else nil . "simpcr" x.
  if atom x then nil else
   <<(<<if not errorp y then z := car y;
        y := simplist x where dmode!* = '!:cr!:;
        if y then z . y else z>>)
   where z=nil,y=errorset!*(list('simprd,mkquote x),nil)>>;

symbolic procedure simprd x;
   % Converts any argument list that can be converted to list of rd's.
   if atom x then nil else <<simplist x where dmode!* = '!:rd!:>>;

symbolic procedure simplist x;
   begin scalar fl,c; c := get(dmode!*,'i2d);
     x := for each a in x collect (not fl and
        <<if null (a := mconv numr b) then a := 0;
          if numberp a then a := apply1(c,a)
             else if not(domainp a and eqcar(a,dmode!*)) then fl := t;
          if not fl and
             (numberp(b := mconv denr b) and (b := apply1(c,b))
             or domainp b and eqcar(b,dmode!*))
                then apply2(get(dmode!*,'quotient),a,b) else fl := t>>
        where b=simp!* a);
    if not fl then return x
   end;

symbolic procedure mconv v; <<dmconv0 dmode!*; mconv1 v>>;

symbolic procedure dmconv0 dmd;
   dmd!* := if null dmd then '!:rn!:
        else if dmd eq '!:gi!: then '!:crn!: else dmd;

symbolic procedure dmconv1 v;
   if null v or eqcar(v,dmd!*) then v
   else if atom v then if flagp(dmd!*,'convert)
      then apply1(get(dmd!*,'i2d),v) else v
   else if domainp v then apply1(get(car v,dmd!*),v)
   else lpow v .* dmconv1(lc v) .+ dmconv1(red v);

symbolic procedure mconv1 v;
   if domainp v then drnconv v
   else lpow v .* mconv1(lc v) .+ mconv1(red v);

symbolic procedure drnconv v;
   if null v or numberp v or eqcar(v,dmd!*) then v else
   <<(if y and atom y then apply1(y,v) else v)
   where y=get(car v,dmd!*)>>;

% Absolute Value Function.

symbolic procedure simpabs u;
   if null u or cdr u then mksq('abs . revlis u, 1)
    else (if null numr x then nil ./ 1
           else quotsq(mkabsf1 absf numr x,mkabsf1 denr x))
         where x = simp!* car u;

symbolic procedure mkabsf1 u;
   if domainp u then mkabsfd u
    else begin scalar x,y,v;
           x := comfac!-to!-poly comfac u;
           u := quotf1(u,x);
           y := split!-comfac!-part x;
           x := cdr y;
           y := car y;
           if positive!-sfp u then <<y := multf(u,y); u := 1>>;
           u := multf(u,x);
           v := lnc y;
           y := quotf1(y,v);
           v := multsq(mkabsfd v,y ./ 1);
           return if u = 1 then v
                   else multsq(v,simpiden list('abs,prepf absf u))
        end;

symbolic procedure mkabsfd u;
   if null get('i,'idvalfn) then absf u ./ 1
    else (simpexpt list(prepsq nrm,'(quotient 1 2))
          where nrm = addsq(multsq(car us,car us),
                             multsq(cdr us,cdr us))
          where us = splitcomplex u);

symbolic procedure positive!-sfp u;
   if domainp u
      then if get('i,'idvalfn)
              then !:zerop impartf u and null !:minusp repartf u
            else null !:minusp u
    else positive!-powp lpow u and positive!-sfp lc u
         and positive!-sfp red u;

symbolic procedure positive!-powp u;
   not atom car u and caar u memq '(abs norm);

% symbolic procedure positive!-powp u;
%    % This definition allows for the testing of positive valued vars.
%    if atom car u then flagp(car u, 'positive)
%     else ((if x then apply2(x,car u,cdr u) else nil)
%           where x = get(caar u,'positivepfn));

symbolic procedure split!-comfac!-part u;
   split!-comfac(u,1,1);

symbolic procedure split!-comfac(u,v,w);
   if domainp u then multd(u,v) . w
    else if red u then
       if positive!-sfp u then multf(u,v) . w
        else v . multf(u,w)
    else if mvar u eq 'i then split!-comfac(lc u,v,w)
    else if positive!-powp lpow u
      then split!-comfac(lc u,multpf(lpow u,v),w)
    else split!-comfac(lc u,v,multpf(lpow u,w));

put('abs,'simpfn,'simpabs);

symbolic procedure simpdiff u;
   <<ckpreci!# u; addsq(simpcar u,simpminus cdr u)>>;

put('difference,'simpfn,'simpdiff);

symbolic procedure simpminus u;
   negsq simp carx(u,'minus);

put('minus,'simpfn,'simpminus);

symbolic procedure simpplus u;
   begin scalar z;
     if length u=2 then ckpreci!# u;
     z := nil ./ 1;
  a: if null u then return z;
     z := addsq(simpcar u,z);
     u := cdr u;
     go to a
   end;

put('plus,'simpfn,'simpplus);

symbolic procedure ckpreci!# u;
   % Screen for complex number input.
   !*complex
      and (if a and not b then ckprec2!#(cdar u,cadr u)
            else if b and not a then ckprec2!#(cdadr u,car u))
            where a=timesip car u,b=timesip cadr u;

symbolic procedure timesip x; eqcar(x,'times) and 'i memq cdr x;

symbolic procedure ckprec2!#(im,rl);
   % Strip im and rl to domains.
   <<im := if car im eq 'i then cadr im else car im;
     if eqcar(im,'minus) then im := cadr im;
     if eqcar(rl,'minus) then rl := cadr rl;
     if domainp im and domainp rl and not(atom im and atom rl)
        then ckprec3!#(!?a2bf im,!?a2bf rl)>>;

symbolic procedure !?a2bf a;
   % Convert decimal or integer to bfloat.
   if atom a then if numberp a then bfloat a else nil
    else if eqcar(a,'!:dn!:) then '!:bf!: . cdr a;

symbolic procedure ckprec3!#(x,y);
  % if inputs are valid, check for precision increase.
   if x and y then
%  precmsg(max(preci!: x+ep!: x,preci!: y+ep!: y)-min(ep!: x,ep!: y));
   precmsg(max(length explode abs cadr x+cddr x,
               length explode abs cadr y+cddr y)
             -min(cddr x,cddr y));

symbolic procedure simpquot q;
   (if null numr u
      then if null numr v then rerror(alg,19,"0/0 formed")
            else rerror(alg,20,"Zero divisor")
     else if dmode!* memq '(!:rd!: !:cr!:) and domainp numr u
        and domainp denr u and domainp denr v
            and !:onep denr u and !:onep denr v
      then (if null numr v then nil else divd(numr v,numr u)) ./ 1 
     else multsq(v,simprecip cdr q))
   where v=simpcar q,u=simp cadr q;

put('quotient,'simpfn,'simpquot);

symbolic procedure simprecip u;
   if null !*mcd then simpexpt list(carx(u,'recip),-1)
    else invsq simp carx(u,'recip);

put('recip,'simpfn,'simprecip);

symbolic procedure simpset u;
  begin scalar x;
     if not idp (x := prepsq simp!* car u) or null x
       then typerr(x,"set variable");
     let0 list(list('equal,x,mk!*sq(u := simp!* cadr u)));
     return u
  end;

put ('set, 'simpfn, 'simpset);

symbolic procedure simpsqrt u;
   if null !*keepsqrts
     then simpexpt1(car u, simpexpon '(quotient 1 2), nil)
    else begin scalar x,y;
       x := xsimp car u;
       return if null numr x then nil ./ 1
               else if denr x=1 and domainp numr x and !:minusp numr x
                then if numr x=-1 then simp 'i
                      else multsq(simp 'i,
                                  simpsqrt list prepd !:minus numr x)
               else if y := domainvalchk('sqrt,list x) then y
               else simprad(x,2)
     end;

symbolic procedure xsimp u; expchk simp!* u;

symbolic procedure simptimes u;
   begin scalar x,y;
    if null u then return 1 ./ 1;
    if tstack!* neq 0 or null mul!* then go to a0;
    y := mul!*;
    mul!* := nil;
    a0: tstack!* := tstack!*+1;
    x := simpcar u;
    a:    u := cdr u;
    if null numr x then go to c
     else if null u then go to b;
    x := multsq(x,simpcar u);
    go to a;
    b:    if null mul!* or tstack!*>1 then go to c;
    x:= apply1(car mul!*,x);
    alglist!* := nil . nil;   % since we may need MUL!* set again.
    mul!*:= cdr mul!*;
    go to b;
    c:    tstack!* := tstack!*-1;
    if tstack!* = 0 then mul!* := y;
    return x;
   end;

put('times,'simpfn,'simptimes);

symbolic procedure resimp u;
   % U is a standard quotient.
   % Value is the resimplified standard quotient.
   resimp1 u where varstack!*=nil;

symbolic procedure resimp1 u;
   quotsq(subf1(numr u,nil),subf1(denr u,nil));

symbolic procedure simp!*sq u;
   if cadr u and null !*resimp then car u else resimp1 car u;

put('!*sq,'simpfn,'simp!*sq);

endmodule;


module simplog;  % Simplify logarithms.

% Authors: Mary Ann Moore and Arthur C. Norman.

fluid '(!*intflag!* !*noneglogs !*simplogs);

global '(domainlist!*);

exports simplog,simplogsq;

imports quotf,prepf,mksp,simp!*,!*multsq,simptimes,addsq,minusf,negf,
        addf,comfac,negsq,mk!*sq,carx;

symbolic procedure simplog u;
   if !*simplogs then simplogi carx(cdr u,'simplog) else simpiden u;

put('log,'simpfn,'simplog);

flag('(log),'full);

symbolic procedure simplogi(sq);
   % Modified to handle domain argument.  Stan Kameny.
   if atom sq then simplogsq simp!* sq
    else if car sq memq domainlist!* then simpiden list('log,sq)
    else if car sq eq 'times
     then simpplus(for each u in cdr sq collect mk!*sq simplogi u)
    else if car sq eq 'quotient
     then addsq(simplogi cadr sq,negsq simplogi caddr sq)
    else if car sq eq 'expt
     then simptimes list(caddr sq,mk!*sq simplogi cadr sq)
    else if car sq eq 'nthroot
     then multsq!*(1 ./ caddr sq,simplogi cadr sq)
    % we had (nthroot of n).
    else if car sq eq 'sqrt then multsq!*(1 ./ 2,simplogi cadr sq)
    else if car sq = '!*sq then simplogsq cadr sq
    else simplogsq simp!* sq;

symbolic procedure multsq!*(u,v);
   if !*intflag!* then !*multsq(u,v) else multsq(u,v);

symbolic procedure simplogsq sq;
   addsq(simplog2 numr sq,negsq simplog2 denr sq);

symbolic procedure simplog2(sf);
 if atom sf
   then if null sf then rerror(alg,21,"Log 0 formed")
     else if numberp sf
       then if sf iequal 1 then nil ./ 1
             else if sf iequal 0 then rerror(alg,22,"Log 0 formed")
             else((mksp(list('log,sf),1) .* 1) .+ nil) ./ 1
             else formlog(sf)
     else begin scalar form;
        form := comfac sf;
        if not null car form
          then return addsq(formlog(form .+ nil),
                            simplog2 quotf(sf,form .+ nil));
        % We have killed common powers.
        form := cdr form;
        if form neq 1
          then return addsq(simplog2 form,simplog2 quotf(sf,form));
        % Remove a common factor from the sf.
        return formlog sf
     end;

symbolic procedure formlogterm(sf);
   begin scalar u;
      u := mvar sf;
      if not atom u and (car u member '(times sqrt expt nthroot))
         then u := addsq(simplog2 lc sf,
                         multsq!*(simplogi u,simp!* ldeg sf))
        else if (lc sf iequal 1) and (ldeg sf iequal 1)
         then u := ((mksp(list('log,u),1) .* 1) .+ nil) ./ 1
        else u := addsq(simptimes list(list('log,u),ldeg sf),
                        simplog2 lc sf);
      return u
   end;

symbolic procedure formlog sf;
   if null red sf then formlogterm sf
    else if minusf sf and null !*noneglogs
     then addf((mksp(list('log,-1),1) .* 1) .+ nil,
               formlog2 negf sf) ./ 1
    else (formlog2 sf) ./ 1;

symbolic procedure formlog2 sf;
   ((mksp(list('log,prepf sf),1) .* 1) .+ nil);

endmodule;


module logsort;  % Combine sums of logs.

% Author:  Stanley L. Kameny.

global '(domainlist!*);

fluid '(!*div factors!* !*combinelogs !*simplogs !*uncached);

switch combinelogs,simplogs;

% !*combinelogs := t;   % Default value is ON.

symbolic procedure clogsq!* x;
   begin scalar !*div,!*combinelogs,!*simplogs;
      !*div := !*simplogs := t;
      x:= simp prepsq x where !*uncached=t; !*simplogs := nil;
      return simp!* comblog prepsq!* x end;

symbolic procedure logsort x; % combines log sums at all levels.
   begin scalar !*div,!*combinelogs,!*simplogs;
      !*div := !*simplogs := t;
      x:= simp x where !*uncached=t; !*simplogs := nil;
      return comblog prepsq!* x end;

% symbolic procedure logsorta a; aeval logsort a;

% symbolic operator logsorta;

symbolic procedure comblog x;
   if atom x or car x memq domainlist!* then x
   else if car x eq 'plus
     or car x eq 'times and
         ((not domainp y and eqcar(mvar y,'log))
           where y=numr simp!* x)
       then prepsq!* clogsq simp!* x
   else (comblog car x) . comblog cdr x;

symbolic procedure clogsq x; clogf numr x ./ clogf denr x;

symbolic procedure clogf x;
   if domainp x then x
   else if eqcar(mvar x,'log) then clogf2 x
   else
      ((if null z then x else
          addf(if atom y then list lt x else numr simp!* comblog y,z))
       where y=prepsq!*(list lt x ./ 1),z=clogf red x);

symbolic procedure clogf2 x; % does actual log combining.
   begin scalar y,z,r,s,g,a,b,c,d,w; integer k;
  st: if domainp x then
         <<w := addf(w,x); go to ret>>;
      if not eqcar(mvar x,'log) or ldeg x neq 1 then
         <<w := addf(w,list lt x); x := red x; go to st>>;
      y := list lt x;
      if not domainp(z := red x) then go to lp;
     % g := coefgcd(c := lc y,0); a := quotf(c,g);
     % y := multf(a,numr simp!* list('log,logarg(cadr mvar y,g)));
      go to ret;
     % in this loop, y is a log term, r is a term, and z the reductum.
  lp: if domainp z then go to ret;
      r := list lt z; z := red z;
      if eqcar(mvar r,'log) and ldeg r=1 then go to a2;
  a1: s := addf(r,s); go to lp;
  a2: b := coefgcd(a := lc r,0); a := quotf(a,b);
      d := coefgcd(c := lc y,0); c := quotf(c,d);
      g := gcdf(a,c); a := quotf(a,g); c := quotf(c,g);
      if not domainp a or not domainp c then go to a1;
      if numberp a and numberp c then go to a3;
      if quotf(a,c)=-1 then
         <<g := a ./ 1;
           a := list('quotient,cadr mvar r,cadr mvar y); go to a4>>;
      go to a1;
  a3: % a := list('times,logarg(cadr mvar r,multf(a,b)),
      %    logarg(cadr mvar y,multf(c,d))); g := g ./ 1;
      b := multf(a,b); d := multf(c,d);
      k := gcdf(k,gcdf(b,d)); b := quotf(b,k); d := quotf(d,k);
      a := list('times,logarg(cadr mvar r,b),
         logarg(cadr mvar y,d)); g := g ./ 1;
  a4: a := prepsq simp!* a;
      y := numr simp!* list('times,k,
         if eqcar(a,'quotient) and cadr a=1
            then list('minus,list('log,caddr a)) else list('log,a),
         prepsq g);
      go to lp;
 ret: return addf(w,addf(y,addf(z,clogf s))) end;

symbolic procedure logarg(a,c);
   if c=1 then a else list('expt,a,c);

symbolic procedure coefgcd(u,g);
   if domainp u then gcdf(u,g) else coefgcd(lc u,coefgcd(red u,g));

endmodule;


module sub; % Functions for substituting in standard forms.

% Author: Anthony C. Hearn.

% Copyright (c) 1991 RAND.  All rights reserved.

fluid '(asymplis!* dmode!* wtl!*);

global '(ncmp!*);

% Evaluation interface.

symbolic procedure subeval u;
   % This is the general evaluator for SUB forms.  All but the last
   % argument are assumed to be substitutions.  These can either be
   % an explicit rule with a lhs and rhs separated by an equal sign,
   % a list of such rules, or something that evaluates to this.
   (begin scalar x,y,z;
   % Separate assignments from expression.
        begin scalar !*evallhseqp,wtl!*;
   % We want here that reval of EQUAL only evaluates rhs, and weights
   % are not used.
           while cdr u do
             <<x := reval car u;
               if getrtype x eq 'list then u := append(cdr x,cdr u)
                else <<if not eqexpr x then errpri2(car u,t);
                       y := cadr x;
                       if null getrtype y then y := !*a2k y;
                       z := (y . caddr x) . z;
                       u := cdr u>>>>
          end;
      for each j in z do wtl!* := delasc(car j,wtl!*);
      return subeval1(z,aeval car u)
   end) where wtl!*= wtl!*;

symbolic procedure subeval1(u,v);
   begin scalar y,z;
        if y := getrtype v
          then if z := get(y,'subfn) then return apply2(z,u,v)
                else rerror(alg,23,
                            list("No substitution defined for type",y))
         else return mk!*sq subs2 subsq(simp v,u) % Convert *SQ x to sq.
   end;

put('sub,'psopfn,'subeval);


% Explicit substitution code for scalar expressions.

symbolic procedure subsq(u,v); quotsq(subf(numr u,v),subf(denr u,v));

symbolic procedure subf(u,l);
   begin scalar alglist!*,x;
   % Domain may have changed, so next line uses simpatom.
      if domainp u then return !*d2q u
       else if ncmp!* and noncomexpf u then return subf1(u,l);
      x := reverse intersection(for each y in l collect car y,
                                kernord(u,nil));
      x := setkorder x;
      u := subf1(reorder u,l);
      setkorder x;
      return reorder numr u ./ reorder denr u
   end;

symbolic procedure noncomexpf u;
   not domainp u
      and (noncomp mvar u or noncomexpf lc u or noncomexpf red u);

%%% SUBF1 changed so that domain elements are resimplified during a call
%%%       to RESIMP even if their tags are the same as dmode*.
%%%       This happens only if the domain is flagged

symbolic procedure subf1(u,l);
   % U is a standard form,
   % L an association list of substitutions of the form
   % (<kernel> . <substitution>).
   % Value is the standard quotient for substituted expression.
   % Algorithm used is essentially the straight method.
   % Procedure depends on explicit data structure for standard form.
   if null u then nil ./ 1
    else if domainp u
     then if atom u then if null dmode!* then u ./ 1 else simpatom u
%          else if dmode!* eq car u then !*d2q u
          else if dmode!* eq car u and
                  not flagp(dmode!*, 'resimplify) then !*d2q u
          else simp prepf u
    else begin integer n; scalar kern,m,w,x,xexp,y,y1,z;
        z := nil ./ 1;
    a0: kern := mvar u;
        if m := assoc(kern,asymplis!*) then m := cdr m;
    a:  if null u or (n := degr(u,kern))=0 then go to b
         else if null m or n<m then y := lt u . y;
        u := red u;
        go to a;
    b:  if not atom kern and not atom car kern then kern := prepf kern;
        if null l then xexp := if kern eq 'k!* then 1 else kern
         else if (xexp := subsublis(l,kern)) = kern
                   and not assoc(kern,asymplis!*)
          then go to f;
    c:  w := 1 ./ 1;
        n := 0;
        if y and cdaar y<0 then go to h;
        if (x := getrtype xexp) eq 'yetunknowntype
          then x:= getrtype(xexp:= eval!-yetunknowntypeexpr(xexp,nil));
        if x and not(x eq 'list)
         then typerr(list(x,xexp),"substituted expression");
        x := simp xexp;
        % SIMP!* here causes problem with HE package;
        x := reorder numr x ./ reorder denr x;
        % needed in case substitution variable is in XEXP;
        if null l and kernp x and mvar numr x eq kern then go to f
         else if null numr x then go to e;   %Substitution of 0;
        for each j in y do
         <<m := cdar j;
           w := multsq(exptsq(x,m-n),w);
           n := m;
           z := addsq(multsq(w,subf1(cdr j,l)),z)>>;
    e:  y := nil;
        if null u then return z
         else if domainp u then return addsq(subf1(u,l),z);
        go to a0;
    f:  sub2chk kern;
        for each j in y do z := addsq(multpq(car j,subf1(cdr j,l)),z);
        go to e;
    h:  % Substitution for negative powers.
        x := simprecip list xexp;
    j:  y1 := car y . y1;
        y := cdr y;
        if y and cdaar y<0 then go to j;
    k:  m := -cdaar y1;
        w := multsq(exptsq(x,m-n),w);
        n := m;
        z := addsq(multsq(w,subf1(cdar y1,l)),z);
        y1 := cdr y1;
        if y1 then go to k else if y then go to c else go to e
     end;

symbolic procedure subsublis(u,v);
   % NOTE: This definition assumes that with the exception of *SQ and
   % domain elements, expressions do not contain dotted pairs.
   begin scalar x;
      return if x := assoc(v,u) then cdr x
              else if atom v then v
              else if not idp car v
               then for each j in v collect subsublis(u,j)
              else if x := get(car v,'subfunc) then apply2(x,u,v)
              else if get(car v,'dname) then v
              else if car v eq '!*sq then subsublis(u,prepsq cadr v)
              else for each j in v collect subsublis(u,j)
   end;

symbolic procedure subsubf(l,expn);
   % Sets up a formal SUB expression when necessary.
   begin scalar x,y;
      for each j in cddr expn do
         if (x := assoc(j,l)) then <<y := x . y; l := delete(x,l)>>;
      expn := sublis(l,car expn)
                 . for each j in cdr expn collect subsublis(l,j);
        %to ensure only opr and individual args are transformed;
      if null y then return expn;
      expn := aconc!*(for each j in reversip!* y
                     collect list('equal,car j,aeval cdr j),expn);
      return if l then subeval expn
              else mk!*sq !*p2q mksp('sub . expn,1)
   end;


% Explicit substitution code for lists.

symbolic procedure listsub(u,v);
   'list . for each x in cdr v collect subeval1(u,x);

put('list,'subfn,'listsub);

put('int,'subfunc,'subsubf);

put('df,'subfunc,'subsubf);

endmodule;


module order; % Functions for internal ordering of expressions.

% Author: Anthony C. Hearn.

% Copyright (c) 1991 RAND.  All rights reserved.

fluid '(kord!*);

symbolic procedure ordad(a,u);
   if null u then list a
    else if ordp(a,car u) then a . u
    else car u . ordad(a,cdr u);

symbolic procedure ordn u;
   if null u then nil
    else if null cdr u then u
    else if null cddr u then ord2(car u,cadr u)
    else ordad(car u,ordn cdr u);

symbolic procedure ord2(u,v);
   if ordp(u,v) then list(u,v) else list(v,u);

symbolic procedure ordp(u,v);
   % Returns TRUE if U ordered ahead or equal to V, NIL otherwise.
   % An expression with more structure at a given level is ordered
   % ahead of one with less.
   if null u then null v
    else if null v then t
    else if vectorp u then if vectorp v then ordpv(u,v) else atom v
    else if atom u
       then if atom v
                then if numberp u then numberp v and not u<v
                      else if idp v then orderp(u,v)
                      else numberp v
             else nil
    else if atom v then t
    else if car u=car v then ordp(cdr u,cdr v)
    else if flagp(car u,'noncom)
     then if flagp(car v,'noncom) then ordp(car u, car v) else t
    else if flagp(car v,'noncom) then nil
    else ordp(car u,car v);

symbolic procedure ordpv(u,v);
   % U and v are vectors. Set up comparison loop.
   ordpv1(u,v,-1,upbv u,upbv v);

symbolic procedure ordpv1(u,v,i,lu,lv);
   if (i:=i#+1)>lu then i>lv
    else (if x=y then ordpv1(u,v,i,lu,lv) else ordp(x,y))
          where x=getv(u,i),y=getv(v,i);

symbolic procedure ordpp(u,v);
   % This used to check (incorrectly) for NCMP!*;
   if car u eq car v then cdr u>cdr v else ordop(car u,car v);

symbolic procedure ordop(u,v);
   begin scalar x;
        x := kord!*;
    a:  if null x then return ordp(u,v)
         else if u eq car x then return t
         else if v eq car x then return;
        x := cdr x;
        go to a
   end;

endmodule;


module forall; % FOR ALL and LET-related commands.

% Author: Anthony C. Hearn.

% Copyright (c) 1991 RAND.  All rights reserved.

fluid '(!*resimp !*sub2 alglist!* arbl!* asymplis!* frasc!* wtl!*);

fluid '(newrule!* oldrules!*);

global '(!*match
         cursym!*
         erfg!*
         frlis!*
         letl!*
         mcond!*
         powlis!*
         powlis1!*
         subfg!*);

letl!* := '(let match clear saveas such);   % Special delimiters.

% Contains two RPLAC references commented out.

remprop('forall,'stat);

remprop('forall,'formfn);

symbolic procedure forallstat;
   begin scalar arbl,conds;
        if cursym!* memq letl!* then symerr('forall,t);
        flag(letl!*,'delim);
        arbl := remcomma xread nil;
        if cursym!* eq 'such then
          <<if not scan() eq 'that then symerr('let,t);
            conds := xread nil>>;
        remflag(letl!*,'delim);
        if not cursym!* memq letl!* then symerr('let,t)
         else return list('forall,arbl,conds,xread1 t)
   end;

symbolic procedure forall u;
   begin scalar x,y;
      x := for each j in car u collect newvar j;
      y := pair(car u,x);
      mcond!* := subla(y,cadr u);
%     mcond!* := formbool(subla(y,eval cadr u),nil,'algebraic);
      frasc!* := y;
      frlis!* := union(x,frlis!*);
      return lispeval caddr u
   end;

symbolic procedure arbstat;
   <<lpriw("*****","ARB no longer supported");
     symerr('if,t)>>;

put('arb,'stat,'arbstat);

symbolic procedure newvar u;
   if not idp u then typerr(u,"free variable")
    else if flagp(u,'reserved)
     then typerr(list("Reserved variable",u),"free variable")
    else intern compress append(explode '!=,explode u);

symbolic procedure formforall(u,vars,mode);
   begin scalar arbl!*,x;
      u := cdr u;
%     vars := append(car u,vars);   % Semantics are different.
      if null cadr u then x := t else x := formbool(cadr u,vars,mode);
%     if null cadr u then x := t else x := form1(cadr u,vars,mode);
      return list('forall,list('list,mkquote union(arbl!*,car u),
                  mkquote x,mkquote form1(caddr u,vars,mode)))
   end;

symbolic procedure def u;
   % Defines a list of operators.
   for each x in u do
      if not eqexpr x or not idlistp cadr x then errpri2(x,t)
       else <<mkop caadr x;
              forall list(cdadr x,t,list('let,mkarg(list x,nil)))>>;

put('def,'stat,'rlis);

deflist('((forall formforall)),'formfn);

deflist('((forall forallstat)),'stat);

flag ('(clear let match),'quote);

symbolic procedure formlet1(u,vars,mode);
   'list . for each x in u collect
      if eqexpr x
        then list('list,mkquote car x,form1(cadr x,vars,mode),
                                !*s2arg(form1(caddr x,vars,mode),vars))
       else form1(x,vars,mode);

symbolic procedure !*s2arg(u,vars);
   %makes all NOCHANGE operators into their listed form;
   if atom u or eq(car u,'quote) then u
    else if not idp car u or not flagp(car u,'nochange)
     then for each j in u collect !*s2arg(j,vars)
    else mkarg(u,vars);

put('let,'formfn,'formlet);

put('clear,'formfn,'formclear);

put('match,'formfn,'formmatch);

symbolic procedure formclear(u,vars,mode);
   list('clear,formclear1(cdr u,vars,mode));

symbolic procedure formclear1(u,vars,mode);
   'list . for each x in u collect
      if flagp(x,'share) then mkquote x else form1(x,vars,mode);

symbolic procedure formlet(u,vars,mode);
   list('let,formlet1(cdr u,vars,mode));

symbolic procedure formmatch(u,vars,mode);
   list('match,formlet1(cdr u,vars,mode));

symbolic procedure let u; let0 u;    % to distinguish between operator
                                     % and function.

symbolic procedure let0 u;
   begin
      u := errorset!*(list('let1,mkquote u),t);
      frasc!* := mcond!* := nil;
      if errorp u then error1() else return car u
   end;

symbolic procedure let1 u;
   begin scalar x;
      while u do
         <<if idp u then typerr(u,"rule list")
            else if eqcar(x :=listeval0 car u,'list)
             then rule!-list(reverse cdr x,t)
            else if idp car u then typerr(u,"rule list")
            else if caar u eq 'replaceby
             then if frasc!*
                    then rerror(alg,100,
                                "=> invalid in FOR ALL statement")
                   else rule!-list(list car u,t)
            else if not(caar u eq 'equal) then typerr(car u,"rule list")
            else if smemq('!~,car u)
             then if frasc!* then typerr(car u,"rule")
                   else rule!-list(list car u,t)
            else let2(cadar u,caddar u,nil,t);
           u := cdr u>>
   end;

symbolic procedure let2(u,v,w,b);
   begin scalar flgg,x,y,z;
        % FLGG is set true if free variables are found.
        x := subla(frasc!*,u);
        if x neq u
          then if atom x then return errpri1 u
                 else <<flgg := t; u := x>>;
        x := subla(frasc!*,v);
        if x neq v
          then <<v := x;
                 if eqcar(v,'!*sq!*) then v := prepsq!* cadr v>>;
                 % to ensure no kernels are replaced by uneq copies
                 % during pattern matching process.
        % Check for unmatched free variables.
        x := smemql(frlis!*,mcond!*);
        y := smemql(frlis!*,u);
        if (z := setdiff(x,y))
           or (z := setdiff(setdiff(smemql(frlis!*,v),x),
                    setdiff(y,x)))
          then <<lprie ("Unmatched free variable(s)" . z);
                 erfg!* := 'hold;
                 return nil>>
         else if atom u then nil
         else if car u eq 'getel then u := lispeval cadr u
         else if flagp(car u,'immediate) then u := reval u;
      return let3(u,v,w,b,flgg)
   end;

symbolic procedure let3(u,v,w,b,flgg);
   % U is left-hand-side of a rule, v the right-hand-side.
   % W is true if a match, NIL otherwise.
   % B is true if the rule is being added, NIL if being removed.
   % Flgg is true if there are free variables in the rule.
   begin scalar x,y,y1,z;
        x := u;
        if null x then <<u := 0; return errpri1 u>>
         else if numberp x then return errpri1 u;
        % Allow redefinition of id's, regardless of type.
       % The next line allows type of LHS to be redefined.
       if b and idp x then <<remprop(x,'rtype); remprop(x,'avalue)>>;
%        else if idp x and flagp(x,'reserved)
%         then rederr list(x,"is a reserved identifier");
        if (y1 := getrtype x)
          then return if z := get(y1,'typeletfn)
                        then lispapply(z,list(x,v,y1,b,getrtype v))
                       else typelet(x,v,y1,b,getrtype v)
         else if (y1 := getrtype v)
          then return if z := get(y1,'typeletfn)
                        then lispapply(z,list(x,v,nil,b,y1))
                       else typelet(x,v,nil,b,y1)
         else letscalar(u,v,w,x,b,flgg)
   end;

symbolic procedure letscalar(u,v,w,x,b,flgg);
   begin
      if not atom x
               then if not idp car x then return errpri2(u,'hold)
                     else if car x eq 'df
                      then if null letdf(u,v,w,x,b) then nil
                            else return nil
                     else if getrtype car x
                      then return let2(reval x,v,w,b)
                     else if not get(car x,'simpfn)
                      then <<redmsg(car x,"operator");
                             mkop car x;
                             return let3(u,v,w,b,flgg)>>
                     else nil
         else if null b and null w
          then <<remprop(x,'avalue);
                 remprop(x,'rtype);    % just in case
                 remflag(list x,'antisymmetric);
                 remprop(x,'infix);
               % remprop(x,'klist);
               % commented out: the relevant objects may still exist.
                 remprop(x,'op);
                 remprop(x,'opmtch);
                 remprop(x,'simpfn);
                 remflag(list x,'symmetric);
                 wtl!* := delasc(x,wtl!*);
                 if flagp(x,'opfn)
                   then <<remflag(list x,'opfn); remd x>>;
                 rmsubs(); % since all kernel lists are gone.
                 return nil>>;
        if eqcar(x,'expt) and caddr x memq frlis!*
          then letexprn(u,v,w,!*k2q x,b,flgg)
           % Special case of a non-integer exponent match.
         else if eqcar(x,'sqrt)
          then let2(list('expt,cadr x,'(quotient 1 2)),v,w,b);
           % Since SQRTs can be converted into EXPTs.
        x := simp0 x;
        return if not domainp numr x then letexprn(u,v,w,x,b,flgg)
                else errpri1 u
   end;

symbolic procedure letexprn(u,v,w,x,b,flgg);
   % Replacement of scalar expressions.
   begin scalar y,z;
        if denr x neq 1
          then return let2(let!-prepf numr x,
                           list('times,let!-prepf denr x,v),w,b)
         else if red(x := numr x)
          then return let2(let!-prepf !*t2f lt x,
                           list('difference,v,let!-prepf red x),w,b)
         else if null (y := kernlp x)
          then <<y := term!-split x;
                 return let2(let!-prepf car y,
                            list('difference,v,let!-prepf cdr y),w,b)>>
         else if y neq 1
          then return let2(let!-prepf quotf!*(x,y),
                           list('quotient,v,let!-prepf y),w,b);
        x := klistt x;
        y := list(w . (if mcond!* then mcond!* else t),v,nil);
        if cdr x
          then return <<rmsubs(); !*match:= xadd!*(x . y,!*match,b)>>
         else if null w and cdar x=1    % ONEP
          then <<x := caar x;
                 if null flgg
                   then <<if atom x
                            then if flagp(x,'used!*) then rmsubs()
                                  else nil
                           else if 'used!* memq cddr fkern x
                            then rmsubs();
                          setk1(x,v,b)>>
                  else if atom x then return errpri1 u
                  else <<if get(car x,'klist) then rmsubs();
                         put(car x,
                             'opmtch,
                           xadd!*(cdr x . y,get(car x,'opmtch),b))>>>>
         else <<rmsubs();
                if v=0 and null w and not flgg
                  then <<asymplis!* := xadd(car x,asymplis!*,b);
                         powlis!*
                      := xadd(caar x . cdar x . y,powlis!*,'replace)>>
                 else if w or not cdar y eq t or frasc!*
                  then powlis1!* := xadd(car x . y,powlis1!*,b)
                 else if null b and (z := assoc(caar x,asymplis!*))
                    and z=car x
                  then asymplis!* := delasc(caar x,asymplis!*)
              else <<powlis!* := xadd(caar x . cdar x . y,powlis!*,b);
                   if b then asymplis!* := delasc(caar x,asymplis!*)>>>>
   end;

rlistat '(clear let match);


% Further support for rule lists and local rule applications.

symbolic procedure clearrules u; rule!-list(u,nil);

% symbolic procedure letrules u; rule!-list(u,t);

rlistat '(clearrules);   % letrules.

symbolic procedure rule!-list(u,type);
   % Type is true if the rule is being added, NIL if being removed.
   begin scalar v,x,y,z;
   a: frasc!* := nil;   % Since free variables must be declared in each
                        % rule.
      if null u then return (mcond!* := nil);
      mcond!* := t;
      v := car u;
      if idp v
        then if (x := get(v,'avalue)) and car x eq 'list
               then <<u := append(reverse cdadr x,cdr u); go to a>>
              else typerr(v,"rule list")
       else if car v eq 'list
          then <<u := append(cdr v,cdr u); go to a>>
       else if not(car v memq '(replaceby equal)) then typerr(v,"rule");
      y := remove!-free!-vars cadr v;
      if eqcar(caddr v,'when)
        then <<mcond!* :=
                  formbool(remove!-free!-vars caddr caddr v,
                           nil,'algebraic);
               z := remove!-free!-vars cadr caddr v>>
       else z := remove!-free!-vars caddr v;
      rule!*(y,z,frasc!*,mcond!*,type);
      u := cdr u;
      go to a
   end;

symbolic procedure rule!*(u,v,frasc,mcond,type);
   % Type is T if a rule is being added, OLD if an old rule is being
   % reinstalled, or NIL if a rule is being removed.
   begin scalar x;
      frasc!* := frasc;
      mcond!* := subla(frasc,mcond);
      if type and type neq 'old
        then <<newrule!* := list(u,v,frasc,mcond);
%              prin2t list("newrule:",newrule!*);
               if idp u
                 then <<remprop(u,'rtype);
                        if x := get(u,'avalue)
                          then <<updoldrules(x,nil);
                                 remprop(u,'avalue)>>>>;
               % Asymptotic case.
               if v=0 and eqcar(u,'expt) and idp cadr u
                  and numberp caddr u
                  and (x := assoc(cadr u,asymplis!*))
                then updoldrules(x,nil)>>;
      return rule(u,v,frasc,if type eq 'old then t else type);
   end;

symbolic procedure rule(u,v,frasc,type);
   begin scalar flg,frlis,x,y,z;
        % FLGG is set true if free variables are found.
        %
        x := subla(frasc,u);
        if x neq u
          then if atom x then return errpri1 u
                 else <<flg := t; u := x>>;
        x := subla(frasc,v);
        if x neq v
          then <<v := x;
                 if eqcar(v,'!*sq!*) then v := prepsq!* cadr v>>;
                 % to ensure no kernels are replaced by uneq copies
                 % during pattern matching process.
        % Check for unmatched free variables.
        frlis := for each j in frasc collect cdr j;
        x := smemql(frlis,mcond!*);
        y := smemql(frlis,u);
        if (z := setdiff(x,y))
           or (z := setdiff(setdiff(smemql(frlis,v),x),
                    setdiff(y,x)))
          then <<lprie ("Unmatched free variable(s)" . z);
                 erfg!* := 'hold;
                 return nil>>
         else if eqcar(u,'getel) then u := lispeval cadr u;
      return let3(u,v,nil,type,flg)
   end;

mkop '!~;               % Declare as algebraic operator.

put('!~,'prifn,'tildepri);

symbolic procedure tildepri u; <<prin2!* car u; prin2!* cadr u>>;

newtok '((!= !>) replaceby);

infix =>;

precedence =>,to;

symbolic procedure equalreplaceby u;
   'replaceby . u;

put('replaceby,'psopfn,'equalreplaceby);

flag('(replaceby),'equalopr);           % Make LHS, RHS etc work.

flag('(replaceby),'spaced);             % Make it print with spaces.

symbolic procedure formreplaceby(u,vars,mode);
   list('list,mkquote car u,form1(cadr u,vars,mode),
                                !*s2arg(form1(caddr u,vars,mode),vars));

put('replaceby,'formfn,'formreplaceby);

infix when;

precedence when,=>;

symbolic procedure formwhen(u,vars,mode);
   list('list,algid('when,vars),form1(cadr u,vars,mode),
%  We exclude formbool in following so that rules print prettily.
%                   mkarg(formbool(caddr u,vars,mode),vars));
                    mkarg(caddr u,vars));

put('when,'formfn,'formwhen);

flag('(letsub whereexp),'listargp);

put('letsub,'simpfn,'simpletsub);

put('whereexp,'psopfn,'evalwhereexp);

symbolic procedure simpletsub u; simp evalletsub1(u,t);

symbolic procedure evalwhereexp u; evalletsub1(u,nil);

symbolic procedure evalletsub1(u,v);
   begin scalar !*resimp,newrule!*,oldrules!*,x,y,z,z1;
      x := car u;
      u := carx(cdr u,'simpletsub);
      if eqcar(x,'list) then x := cdr x else errach 'simpletsub;
      for each j in x do
         if v and eqcar(j,'replaceby) then z := j . z
          else if null v and eqcar(j,'equal)
           then z := ('replaceby . cdr j) . z
          else if (y := validrule j) or (y := validrule reval j)
           then (y:=reverse car y) and <<rule!-list(y,t); z1 := y . z1>>
          else typerr(car x,"rule list");
 %    z := reversip!* z;
      rule!-list(z,t);
      !*resimp := t;   % Since u may contain (*SQ ... T).
      u := errorset!*(list('aeval,mkquote u),nil);
      !*resimp := nil;
      for each j in z . z1 do rule!-list(j,nil);
      % Restore previous environment, if changed.
      for each j in oldrules!*
          do if atom cdar j
               then if idp cdar j
                      then if cdar j eq 'scalar
                             then let3(caar j,cadr j,nil,t,nil)
                            else typelet(caar j,cadr j,nil,t,cdar j)
                     else nil
              else rule!*(car j,cadr j,caddr j,cadddr j,'old);
      if errorp u then rerror(alg,24,"Invalid simplification")
       else return car u
   end;

symbolic procedure resimpcar u; resimp car u;

symbolic procedure validrule u;
   if atom u then nil
    else if car u eq 'list then list cdr u
    else if car u eq 'replaceby then list list u
    else if car u eq 'equal then list list('replaceby . cdr u)
    else nil;

symbolic procedure remove!-free!-vars u;
   begin
      return if atom u then u
          else if car u eq '!~
           then if not atom cdr u and idp cadr u
                  then <<frlis!* := union(list get!-free!-form cadr u,
                                          frlis!*);
                         cadr u>>
                 else typerr(u,"free variable")
          else remove!-free!-vars!-l u
   end;

symbolic procedure remove!-free!-vars!-l u;
   if atom u then u
    else remove!-free!-vars car u . remove!-free!-vars!-l cdr u;

symbolic procedure get!-free!-form u;
   begin scalar x;
      if x := atsoc(u,frasc!*) then return cdr x;
      x := intern compress append('(!! !~),explode u);
      frasc!* := (u . x) . frasc!*;
      return x
   end;


symbolic procedure term!-split u;
   % U is a standard form which is not a kernel list (i.e., kernlp
   % is false). Result is the dotted pair of the leading part of the
    % expression for which kernlp is true, and the remainder;
   begin scalar x;
      while null red u do <<x := lpow u . x; u := lc u>>;
      return tpowadd(x,!*t2f lt u) . tpowadd(x,red u)
   end;

symbolic procedure tpowadd(u,v);
   <<for each j in u do v := !*t2f(j .* v); v>>;

symbolic procedure simp0 u;
   begin scalar !*factor,x,y,z;
        y := setkorder frlis!*;
        if eqcar(u,'!*sq) then return simp0 prepsq!* cadr u;
        x := subfg!* . !*sub2;
        subfg!* := nil;
        if atom u
           or idp car u
              and (flagp(car u,'simp0fn) or get(car u,'rtype))
          then z := simp u
         else z := simpiden u;
        rplaca(alglist!*,delasc(u,car alglist!*));
        % Since we don't want to keep this value.
        subfg!* := car x;
        !*sub2 := cdr x;
        setkorder y;
        return z
   end;

flag('(cons difference eps expt minus plus quotient times),'simp0fn);

symbolic procedure let!-prepf u;
   subla(for each x in frasc!* collect (cdr x . car x),prepf u);

symbolic procedure match u;
   <<for each x in u do let2(cadr x,caddr x,t,t);
     frasc!* := mcond!* := nil>>;

symbolic procedure clear u;
   begin
      rmsubs();
      u := errorset!*(list('clear1,mkquote u),t);
      mcond!* := frasc!* := nil;
      if errorp u then error1() else return car u
   end;

symbolic procedure clear1 u;
   begin scalar x;
      while u do
         <<if flagp(x := car u,'share)
             then if not flagp(x,'reserved) then set(x,x) else rsverr x
            % if argument is an explicit list, clear each element.
            else if eqcar(x,'list)
                   then u := nil . append(cdr x,cdr u)
            % The following two cases allow for rules or the lhs of
            % rules as arguments to CLEAR.
            else if eqcar(x,'replaceby) then rule!-list(list x,nil)
            else if smemq('!~,x)
             then if eqcar(x,'equal) then rule!-list(list x,nil)
                   else rule!-list(list list('replaceby,x,nil),nil)
            else <<let2(x,nil,nil,nil); let2(x,nil,t,nil)>>;
           u := cdr u>>
   end;

symbolic procedure typelet(u,v,ltype,b,rtype);
   % General function for setting up rules for typed expressions.
   % LTYPE is the type of the left hand side U, RTYPE, that of RHS V.
   % B is a flag that is true if this is an update, nil for a removal.
   begin scalar ls;
        if null rtype then rtype := 'scalar;
        if ltype eq rtype then go to a
         else if null b then go to c
         else if ltype
          then if ltype eq 'list and rtype eq 'scalar
                 then <<ls := t; go to l>>
                else typerr(list(ltype,u),rtype)
         else if not atom u
          then if arrayp car u then go to a else typerr(u,rtype);
        redmsg(u,rtype);
    l:  put(u,'rtype,rtype);
        ltype := rtype;
    a:  if b and (not atom u or flagp(u,'used!*)) then rmsubs();
    c:  if not atom u
          then if arrayp car u
                 then setelv(u,if b then v else nil)
                else put(car u,'opmtch,xadd!*(cdr u .
                    list(nil . (if mcond!* then mcond!* else t),v,nil),
                        get(car u,'opmtch),b))
         else if null b
          then <<remprop(u,'avalue);
                 remprop(u,'rtype);
                 if ltype eq 'array then remprop(u,'dimension)>>
         else if ls
          then <<remprop(u,'rtype); put(u,'avalue,list(rtype,v))>>
         else <<if (b := get(u,'avalue))
                  then if not(rtype eq car b)
                          and (not(car b memq(ls := '(scalar list)))
                               or not(rtype memq ls))
                         then typerr(list(car b,u),rtype);
                put(u,'avalue,list(rtype,v))>>
   end;

symbolic procedure setk(u,v);
   begin scalar x;
      if not atom u
         and idp car u
   %Excalc currently needs getrtype to check for free indices.
   %Getrtype *must* be called as first argument in OR below.
         and (x := (getrtype u or get(car u,'rtype)))
         and (x := get(x,'setelemfn))
        then apply2(x,u,v)
       else let2(u,v,nil,t);
      return v
   end;

symbolic procedure setk1(u,v,b);
   begin scalar x,y,z;
      if atom u
        then <<if null b
                 then <<if not get(u,'avalue)
                          then msgpri(nil,u,"not found",nil,nil)
                         else remprop(u,'avalue);
                        return nil>>
                else if (x := get(u,'avalue))
                 then put(u,'avalue,list(car x,v))
                else put(u,'avalue,list('scalar,v));
               return v>>
       else if not atom car u
        then rerror(alg,25,"Invalid syntax: improper assignment");
      u := car u . revlis cdr u;
      if null b
        then <<z:=assoc(u,wtl!*);
               if not(y := get(car u,'kvalue))
                  or not (x := assoc(u,y))
                 then << if null z then 
                            msgpri(nil,u,"not found",nil,nil)>>
                else put(car u,'kvalue,delete(x,y));
                if z then wtl!*:=delasc(u,wtl!*);
               return nil>>
       else if not (y := get(car u,'kvalue))
        then put(car u,'kvalue,list list(u,v))
       else <<updoldrules(u,v);
              if x := assoc(u,y) then y := delasc(car x,y);
              put(car u,'kvalue,aconc(y,list(u,v)))>>;
      return v
     end;

symbolic procedure klistt u;
   if atom u then nil else caar u . klistt cdr carx(u,'list);

symbolic procedure kernlp u;
   % Returns leading domain coefficient if U is a monomial product
   % of kernels, NIL otherwise.
   if domainp u then u else if null red u then kernlp lc u else nil;

symbolic procedure xadd(u,v,b);
   % Adds replacement U to table V, with new rule at head.
   % Note that format of u and v depends on whether a free variable
   % occurs in the expression or asymplis* is being updated!!.
   begin scalar x;
        x := assoc(car u,v);
        if null x
          then if b and not(b eq 'replace) then v := u . v else nil
         else if b
          then <<v := delete(x,v);
                 if not atom cdr x and length x=5 
                   then x := cdr x;  % No free variable.
                 if not atom cdr x   % atom is asymplis update.
                   then updoldrules(caddr x,cdadr x);
                 if not(b eq 'replace) then v := u . v>>
         else if cadr x=cadr u then v := delete(x,v);
        return v
   end;

symbolic procedure updoldrules(v,w);
   (if null u then nil
     else (oldrules!* :=
                 (if not atom v and numberp cdr v   % asymptotic case.
                    then list(list('expt,car v,cdr v),0,nil,t)
                   else if atom car u
                    then list(car u . car v,cadr v,nil,t)
                   else list(car u,rsubla(x,v),x,rsubla(x,w)))
              . oldrules!*)
           where x=caddr u)
    where u= newrule!*;

symbolic procedure xadd!*(u,v,b);
   % Adds replacement U to table V, with new rule at head.
   % Also checks boolean part for equality.
   begin scalar x;
      x := v;
      while x and not(car u=caar x and cadr u=cadar x) do x := cdr x;
      if x then <<v := delete(car x,v);
                 if b then updoldrules(caddar x,cdadar x)>>;
      if b then v := u . v;
      return v
   end;

symbolic procedure rsubla(u,v);
   begin scalar x;
        if null u or null v then return v
         else if atom v
                 then return if x:= rassoc(v,u) then car x else v
         else return(rsubla(u,car v) . rsubla(u,cdr v))
   end;

endmodule;


module eqn;   % Support for equations as top level structures.

% Author: Anthony C. Hearn.

% Copyright (c) 1990 The RAND Corporation.  All rights reserved.

% At the moment "EQUAL" is the tag for such structures.

% Evalequal is defined in alg/algbool.

fluid '(!*evallhseqp);

switch evallhseqp;

symbolic procedure equalreval u;
   if !*evallhseqp then  'equal . revlis u
    else 'equal . car u . list reval cadr u;

put('equal,'psopfn,'equalreval);

put('equal,'rtypefn,'quoteequation);

put('equal,'i2d,'eqnerr);

symbolic procedure eqnerr u; typerr(u,"equation");

% put('equation,'evfn,'evaleqn);

% symbolic procedure evaleqn(u,v);
%    begin scalar op,x;
%       if null cdr u or not eqcar(cadr u,'equal)
%         then rerror(alg,26,"Invalid equation structure");
%      op := car u;
%       if null cddr u
%         then return 'equal . for each j in cdadr u
%          collect if op eq 'eqneval then reval1(j,v) else list(op,j)
%        else if eqcar(caddr u,'equal) or cdddr u
%         then rerror(alg,27,"Invalid equation structure");
%       x := caddr u;
%       return 'equal . for each j in cdadr u collect list(op,j,x)
%   end;

put('eqneval,'rtypefn,'getrtypecar);

% put(equal,'prifn,'equalpri);

% put('equal,'lengthfn,'eqnlength);

symbolic procedure lhs u;
   % Returns the left-hand-side of an equation.
   if not eqexpr u then typerr(u,"equation") else cadr u;

symbolic procedure rhs u;
   % Returns the right-hand-side of an equation.
   if not eqexpr u then typerr(u,"equation") else caddr u;

flag('(lhs rhs),'opfn);  % Make symbolic operators.


% Explicit substitution code for equations.

symbolic procedure eqnsub(u,v);
   'equal . for each x in cdr v collect subeval1(u,x);

put('equation,'subfn,'eqnsub);


endmodule;


module rmsubs;   % Remove system wide standard quotient substitutions.

% Author: Anthony C. Hearn.

% Copyright (c) 1987 The RAND Corporation.  All rights reserved.

fluid '(alglist!*);

global '(!*sqvar!*);

% Contains RPLACA update of *SQVAR*.

!*sqvar!*:= list 't;    %variable used by *SQ expressions to control
                        %resimplification;

symbolic procedure rmsubs;
   begin
        rplaca(!*sqvar!*,nil); !*sqvar!* := list t;
%       while kprops!* do
%          <<remprop(car kprops!*,'klist); %kprops!* := cdr kprops!*>>;
%       exlist!* := list '(!*);
        %This is too dangerous: someone else may have constructed a
        %standard form;
        alglist!* := nil . nil
   end;

endmodule;


module algdcl;  % Various declarations.

% Author: Anthony C. Hearn.

% Copyright (c) 1987 The RAND Corporation.  All rights reserved.

global '(preclis!* ws);

symbolic procedure formopr(u,vars,mode);
   if mode eq 'symbolic
     then list('flag,mkquote cdr u,mkquote 'opfn)
    else list('operator,mkarg(cdr u,vars));

put('operator,'formfn,'formopr);

symbolic procedure operator u; for each j in u do mkop j;

rlistat '(operator);

symbolic procedure remopr u;
   % Remove all operator related properties from id u.
   begin
      remprop(u,'alt);
      remprop(u,'infix);
      remprop(u,'op);
      remprop(u,'prtch);
      remprop(u,'simpfn);
      remprop(u,'unary);
      remflag(list u,'linear);
      remflag(list u,'nary);
      remflag(list u,'opfn);
      remflag(list u,'antisymmetric);
      remflag(list u,'symmetric);
      remflag(list u,'right);
      preclis!* := delete(u,preclis!*)
   end;

flag('(remopr),'eval);

symbolic procedure den u;
   mk!*sq (denr simp!* u ./ 1);

symbolic procedure num u;
   mk!*sq (numr simp!* u ./ 1);

flag('(den num),'opfn);

flag('(den num),'noval);

put('saveas,'formfn,'formsaveas);

symbolic procedure formsaveas(u,vars,mode);
   list('saveas,formclear1(cdr u,vars,mode));

symbolic procedure saveas u;
   let0 list list('equal,car u,
                  if eqcar(ws,'!*sq)
                     and smemql(for each x in frasc!* collect car x,
                                cadr ws)
                    then list('!*sq,cadr ws,nil)
                   else ws);

rlistat '(saveas);

endmodule;


module opmtch; % Functions that apply basic pattern matching rules.

% Author: Anthony C. Hearn.

% Copyright (c) 1987 The RAND Corporation. All rights reserved.

global '(frlis!* subfg!*);

symbolic procedure emtch u;
   if atom u then u else (lambda x; if x then x else u) opmtch u;

symbolic procedure opmtch u;
   begin scalar q,x,y,z;
        if null(x := get(car u,'opmtch)) then return nil
         else if null subfg!* then return nil  % null(!*sub2 := t).
         else if q := assoc(u,cdr alglist!*) then return cdr q;
        z := for each j in cdr u collect emtch j;
    a:  if null x then go to c;
        y := mcharg(z,caar x,car u);
    b:  if null y then <<x := cdr x; go to a>>
         else if lispeval subla(car y,cdadar x)
          then <<q := subla(car y,caddar x); go to c>>;
        y := cdr y;
        go to b;  
    c:  rplacd(alglist!*,(u . q) . cdr alglist!*);
        return q
   end;

symbolic procedure mcharg(u,v,w);
   % Procedure to determine if an argument list matches given template.
   % U is argument list of operator W, V is argument list template being
   % matched against.  If there is no match, value is NIL,
   % otherwise a list of lists of free variable pairings.
   if null u and null v then list nil
    else begin integer m,n;
        m := length u;
        n := length v;
        if flagp(w,'nary) and m>2
          then if m<6 and flagp(w,'symmetric)
                             then return mchcomb(u,v,w)
                else if n=2 then <<u := cdr mkbin(w,u); m := 2>>
                else return nil;   % We cannot handle this case.
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
   % Value is list of all combinations of N elements from the list U.
   begin scalar v; integer m;
        if n=0 then return list nil
         else if (m:=length u-n)<0 then return nil
         else for i := 1:m do
          <<v := nconc!*(v,mapcons(comb(cdr u,n-1),car u));
            u := cdr u>>;
        return u . v
   end;

symbolic procedure mcharg2(u,v,w,x);
   % Matches compatible list U of operator X against template V.
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
   % for all a,b let kp(dx a,kp(dx a,dx b)) = 0; kp(dx 1,dx 2).
   begin scalar x;
      x := get(v,'opmtch);
      remprop(v,'opmtch);
      u := errorset!*(list('reval,mkquote u),t);
      put(v,'opmtch,x);
      if errorp u then error1() else return car u
   end;

symbolic procedure mchk(u,v);
   if u=v then list nil
    else if eqcar(u,'!*sq) then mchk(prepsqxx cadr u,v)
    else if eqcar(v,'!*sq) then mchk(u,prepsqxx cadr v)
    else if atom v
           then if v memq frlis!* then list list (v . u) else nil
    else if atom u      % Special check for negative number match.
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
   %  From ACH: I don't understand why I put in the following reversip,
   %  since it causes the least direct match to come back first.
   reversip!* if mtp v
     then for each j in noncomperm v collect pair(j,u)
    else for each j in noncomperm u join mcharg2(j,v,list nil,w);

symbolic procedure noncomperm u;
   % Find possible permutations when non-commutativity is taken into
   % account.
   if null u then list u
    else for each j in u join
       (if x eq 'failed then nil else mapcons(noncomperm x,j))
        where x=noncomdel(j,u);

symbolic procedure noncomdel(u,v);
   if null noncomp u then delete(u,v) else noncomdel1(u,v);

symbolic procedure noncomdel1(u,v);
   begin scalar z;
   a: if null v then return reversip!* z
       else if u eq car v then return nconc(reversip!* z,cdr v)
       else if noncomp car v then return 'failed;
      z := car v . z;
      v := cdr v;
      go to a
   end;

flagop antisymmetric,symmetric;

flag ('(plus times),'symmetric);

endmodule;


module prep; % Functions for converting canon. forms into prefix forms.

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
   (if null x then 0 else replus x) where x=prepf1(u,nil);

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

% symbolic procedure exchk u;
%    begin scalar z;
%       for each j in u do
%          if cdr j=1
%            then if eqcar(car j,'expt) and caddar j = '(quotient 1 2)
%                    then z := list('sqrt,cadar j) .z
%                   else z := sqchk car j . z
%            else z := list('expt,sqchk car j,cdr j) . z;
%       return z
%   end;

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
%               ((if eqcar(x,'quotient) and caddr x = 2
%                  then if cadr x = 1 then list('sqrt,caar u)
%                        else list('expt,list('sqrt,caar u),cadr x)
                ((if x = '(quotient 1 2) then list('sqrt,caar u)
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
   if null u then 0
    else if atom u then u
    else if null cdr u then car u
    else 'plus . u;

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
    else (if x then apply1(x,u) else if atom car u then u else prepf u)
          where x=get(car u,'prepfn2);

put('!*sq,'prepfn2,'prepcadr);

put('expt,'prepfn2,'prepexpt);

symbolic procedure prepcadr u; prepsq cadr u;

symbolic procedure prepexpt u; if caddr u=1 then cadr u else u;

endmodule;


module extout; % Extended output package for expressions.

% Author: Anthony C. Hearn.

% Copyright (c) 1991 RAND.  All rights reserved.

fluid '(!*allfac !*div !*mcd !*noequiv !*pri !*rat factors!* kord!*
  !*combinelogs wtl!*);

global '(dnl!* ordl!* upl!*);

switch allfac,div,pri,rat;

!*allfac := t;          % factoring option for this package
!*pri := t;             % to activate this package

% dnl!* := nil;         % output control flag: puts powers in denom
% factors!* := nil;     % list of output factors
% ordl!* := nil;        % list of kernels introduced by ORDER statement
% upl!* := nil;         % output control flag: puts denom powers in
                        % numerator
% !*div := nil;         % division option in this package
% !*rat := nil;         % flag indicating rational mode for output.

symbolic procedure factor u;
   factor1(u,t,'factors!*);

symbolic procedure factor1(u,v,w);
   begin scalar x,y;
        y := lispeval w;
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

% rlistat '(up down);  % Omitted since not documented.

symbolic procedure formop u;
   if domainp u then u
    else raddf(multop(lpow u,formop lc u),formop red u);

symbolic procedure multop(u,v);
   if null kord!* then multpf(u,v)
    else if car u eq 'k!* then v
    else rmultpf(u,v);

symbolic smacro procedure lcx u;
   % Returns leading coefficient of a form with zero reductum, or an
   % error otherwise.
   cdr carx(u,'lcx);

symbolic procedure quotof(p,q);
   % P is a standard form, Q a standard form which is either a domain
   % element or has zero reductum.
   % Returns the quotient of P and Q for output purposes.
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
   % P is a form, Q a domain element. Value is quotient of P and Q
   % for output purposes.
   if null p then nil
    else if domainp p then quotodd(p,q)
    else (lpow p .* quotofd(lc p,q)) .+ quotofd(red p,q);

symbolic procedure quotodd(p,q);
   % P and Q are domain elements. Value is domain element for P/Q.
   if atom p and atom q then int!-equiv!-chk mkrn(p,q)
    else lowest!-terms(p,q);

symbolic procedure lowest!-terms(u,v);
   % Reduces compatible domain elements U and V to a ratio in lowest
   % terms.  Value as a rational may contain domain arguments rather
   % just integers.  Modified to use dcombine for field division.
   if u=v then 1
    else if flagp(dmode!*,'field) or not atom u and flagp(car u,'field)
       or not atom v and flagp(car v,'field)
%    then multdm(u,!:recip v)
     then dcombine!*(u,v,'quotient)
     else begin scalar x;
      if atom(x := dcombine!*(u,v,'gcd)) and x neq 1 then
         <<u := dcombine!*(u,x,'quotient);
           v := dcombine!*(v,x,'quotient)>>;
      return if v=1 then u else '!:rn!: . (u . v)
   end;

symbolic procedure dcombine!*(u,v,w);
   if atom u and atom v then apply2(w,u,v) else dcombine(u,v,w);

symbolic procedure ckrn u;
   % Factors out the leading numerical coefficient from field domains.
   if flagp(dmode!*,'field) and not dmode!* memq '(!:rd!: !:cr!:)
     then begin scalar x;
       x := lnc u;
       x := multf(x,ckrn1 quotfd(u,x));
       if null x then x := 1;
          % NULL could be caused by floating point underflow.
       return x
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
   % U and V are domain elements or forms with a zero reductum.
   % Value is the gcd of U and V.
   if null v then u
    else if u=v then u
    else if domainp u
     then if domainp v then
        if flagp(dmode!*,'field)
          or pairp u and flagp(car u,'field)
          or pairp v and flagp(car v,'field) then 1
           else if dmode!* eq '!:gi!: then intgcdd(u,v) else gcddd(u,v)
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

symbolic procedure negf!* u; negf u where !*noequiv = t;

symbolic procedure prepsq!* u;
   begin scalar x,!*combinelogs;
        if null numr u then return 0;
        % The following leads to some ugly output.
%        else if minusf numr u
%         then return list('minus,prepsq!*(negf!* numr u ./ denr u));
        x := setkorder
                  append((for each j in factors!*
                     join if not idp j then nil
                           else for each k in get(j,'klist)
                                     collect car k),
                   append(factors!*,ordl!*));
        if kord!* neq x or wtl!*
          then u := formop numr u . formop denr u;
%       u := if !*rat or (not flagp(dmode!*,'field) and !*div)
        u := if !*rat or !*div
                      or upl!* or dnl!*
               then replus prepsq!*1(numr u,denr u,nil)
              else sqform(u,function prepsq!*2);
        setkorder x;
        return u
   end;

symbolic procedure prepsq!*0(u,v);
   % U is a standard quotient, but not necessarily in lowest terms.
   % V a list of factored powers.
   % Value is equivalent list of prefix expressions (an implicit sum).
   begin scalar x;
      return if null numr u then nil
              else if (x := gcdf(numr u,denr u)) neq 1
        then prepsq!*1(quotf(numr u,x),quotf(denr u,x),v)
       else prepsq!*1(numr u,denr u,v)
   end;

symbolic procedure prepsq!*1(u,v,w);
   % U and V are the numerator and denominator expression resp,
   % in lowest terms.
   % W is a list of powers to be factored from U.
   begin scalar x,y,z;
        % Look for "factors" in the numerator.
        if not domainp u and (mvar u member factors!* or (not
                atom mvar u and car mvar u member factors!*))
          then return nconc!*(
               if v=1 then prepsq!*0(lc u ./ v,lpow u . w)
                else (begin scalar n,v1,z1;
                % See if the same "factor" appears in denominator.
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
        % Now see if there are any remaining "factors" in denominator.
        % (KORD!* contains all potential kernel factors.)
        if not domainp v
         then for each j in kord!* do
           begin integer n; scalar z1;
                n := 0;
                z1 := !*k2f j;
                while z := quotfm(v,z1) do <<n := n-1; v := z>>;
                if n<0 then w := mksp(list('expt,j,n),1) . w
           end;
        % Now all "factors" have been removed.
        if kernlp u then <<u := mkkl(w,u); w := nil>>;
        if dnl!*
          then <<x := if null !*allfac then 1 else ckrn u;
                 z := ckrn!*(x,dnl!*);
                 x := quotof(x,z);
                 u := quotof(u,z);
                 v := quotof(v,z)>>;
        if upl!*
          then <<y := ckrn v;
                 z := ckrn!*(y,upl!*);
                 y := quotof(y,z);
                 u := quotof(u,z);
                 v := quotof(v,z)>>
         else if !*div then y := ckrn v
         else y := 1;
        u := canonsq (u . quotof(v,y));
%       if !*gcd then u := cancel u;
        u := quotof(numr u,y) ./ denr u;
        if !*allfac
          then <<x := ckrn numr u; y := ckrn denr u;
                 if (x neq 1 or y neq 1)
                    and (x neq numr u or y neq denr u)
                  then <<v := quotof(denr u,y);
                         u := quotof(numr u,x);
                         w := prepf mkkl(w,x);
                         x := prepf y;
                         u := addfactors(w,u);
                         v := addfactors(x,v);
                         return if v=1 then rmplus u
                                 else list if eqcar(u,'minus)
                                             then list('minus,
                                               list('quotient,cadr u,v))
                                           else list('quotient,u,v)>>>>;
        return if w then list retimes aconc!*(exchk w,prepsq u)
         else rmplus prepsq u
   end;

symbolic procedure addfactors(u,v);
   % U is a (possible) product of factors, v a standard form.
   % Result is a folded prefix expression.
   if u = 1 then prepf v
    else if v = 1 then u
    else if eqcar(u,'times) then 'times . aconc!*(cdr u,prepf v)
    else retimes list(u,prepf v);

symbolic procedure rmplus u; if eqcar(u,'plus) then cdr u else list u;

symbolic procedure prepsq!*2 u; replus prepsq!*1(u,1,nil);

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

fluid '(depl!*);

% DEPL* is a list of dependencies among kernels.

global '(frlis!*);

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

% Copyright (c) 1991 The RAND Corporation. All rights reserved.

fluid '(!*fort !*nat !*savestructr scountr svar svarlis);

global '(varnam!*);

varnam!* := 'ans;

switch savestructr;

flag('(structr),'intfn);        % To fool the supervisor into printing
                                % results of STRUCTR.

% ***** two essential uses of RPLACD occur in this module.

symbolic procedure structr u;
   begin scalar scountr,fvar,svar,svarlis;
      % SVARLIS is a list of elements of form:
      % (<unreplaced expression> . <newvar> . <replaced exp>);
      scountr :=0;
      fvar := svar := varnam!*;
      if cdr u
        then <<fvar := svar := cadr u; if cddr u then fvar := caddr u>>;
      u := structr1 car u;
      if !*fort then svarlis := reversip!* svarlis
       else if not !*savestructr
        then <<varpri(u,nil,'only);
               if not flagpcar(u,'struct) then terpri();
               if scountr=0 then return nil
                else <<if null !*nat then terpri();
                       prin2t "   where">>>>;
      if !*fort or not !*savestructr
        then for each x in svarlis do
             <<terpri!* t;
               if null !*fort then prin2!* "      ";
               varpri(cddr x,list('setq,cadr x,mkquote cddr x),t)>>;
      if !*fort then varpri(u,list('setq,fvar,mkquote u),t)
       else if !*savestructr
        then return 'list . u .
                        foreach x in svarlis
                           collect list('equal,cadr x,
                                               mkquote cddr x)
   end;

rlistat '(structr);

symbolic procedure structr1 u;
   % This routine considers special case STRUCTR arguments.  At the
   % moment only matrices (with flag STRUCT on MAT) and equations are
   % considered.  It could be easily generalized.
   (if flagpcar(u,'struct)
      then car u .
         (for each j in cdr u collect for each k in j collect
                               struct!*sq k)
     else if eqcar(u,'equal) then list('equal,cadr u,structr1 caddr u)
     else if getrtype u then typerr(u,"STRUCTR argument")
     else struct!*sq u)
   where u = aeval u;

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

% Copyright (c) 1991 RAND.  All rights reserved.

fluid '(!*ratarg wtl!*);

global '(hipow!* lowpow!*);

switch ratarg;

flag ('(hipow!* lowpow!*),'share);

symbolic procedure coeffeval u;
   begin integer n;
      n := length u;
      if n<2 or n>3
        then rerror(alg,28,
                    "COEFF called with wrong number of arguments")
       else return coeff1(car u,cadr u,
                         if null cddr u then nil else caddr u)
      end;

put('coeff,'psopfn,'coeffeval);

symbolic procedure coeff1(u,v,w);
   % Finds the coefficients of V in U and returns results in W;
   begin scalar bool,x,y,z;
        v := !*a2kwoweight v;
        u := simp!* u;
        bool := !*ratarg or freeof(prepf denr u,v);
        if null bool then u := !*q2f u;
        x := updkorder v;
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
      v := !*a2kwoweight v;
      u := simp!* u;
      bool := !*ratarg or freeof(prepf denr u,v);
      if null bool then u := !*q2f u;
      x := updkorder v;
      if null bool then <<y := reorder u; u := 1>>
       else <<y := reorder numr u; u := denr u>>;
      setkorder x;
      if null y then return 0; % changed by JHD for consistency
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

% Copyright (c) 1991 RAND.  All rights reserved.

fluid '(asymplis!* wtl!*);

flag('(k!*),'reserved);

% Asymptotic list and weighted variable association lists.

symbolic procedure weight u;
   begin scalar y,z;
        rmsubs();
        for each x in u do
           if not eqexpr x then errpri2(x,'hold)
            else <<y := !*a2kwoweight cadr x;
                   z := reval caddr x;
                   if not (fixp z and z>0) then typerr(z,"weight");
                   wtl!* :=  (y . z) . delasc(y,wtl!*)>>
   end;

symbolic procedure wtlevel u;
   begin integer n; scalar x;
        n := reval car u;
        if not(fixp n and not n<0) then errpri2(n,'hold);
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

symbolic procedure formlnr u;
   begin scalar x,y,z;
      x := car u;
      if null cdr u or null cddr u
        then rerror(alg,29,list("Linear operator",
                                x,"called with too few arguments"));
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


module elem; % Simplification rules for elementary functions.

% Author: Anthony C. Hearn.

% Copyright (c) 1990 The RAND Corporation. All rights reserved.

fluid '(!*!*sqrt !*keepsqrts);

% No references to RPLAC-based functions in this module.

algebraic;

% Rule for I**2.

remflag('(i),'reserved);

let i**2= -1;

% flag('(e i nil pi t),'reserved);

flag('(nil),'reserved);    % Let's at least protect NIL.

% Logarithms.

let log(e)= 1,
    log(1)= 0;

for all x let log(e**x)=x; % e**log x=x now done by simpexpt.

% The next set of rules are not implemented yet.

%for all x,y let log(x*y) = log x + log y, log(x/y) = log x - log y;

for all x let df(log(x),x) = 1/x;

% Trigonometrical functions.

deflist('((acos simpiden) (asin simpiden) (atan simpiden)
          (acosh simpiden) (asinh simpiden) (atanh simpiden)
          (acot simpiden) (cos simpiden) (sin simpiden) (tan simpiden)
          (sec simpiden) (sech simpiden) (csc simpiden) (csch simpiden)
          (cot simpiden)(acot simpiden)(coth simpiden)(acoth simpiden)
          (cosh simpiden) (sinh simpiden) (tanh simpiden)
   ),'simpfn);

% The following declaration causes the simplifier to pass the full
% expression (including the function) to simpiden.

flag ('(acos asin atan acosh acot asinh atanh cos sin tan cosh sinh
        tanh csc csch sec sech cot acot coth acoth),
      'full);

flag('(asin atan asinh atanh sin tan csc csch sinh tanh cot coth),
      'odd);

flag('(cos sec sech cosh acosh),'even);

flag('(cot coth),'nonzero);

% In the following rules, it is not necessary to let f(0)=0, when f
% is odd, since simpiden already does this.

let cos(0)= 1,
    sec(0)= 1,
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
    sech(0) =1,
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
       (if evenp(n) then -1 else 1)/2;

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
              df(acot(x),x)= -1/(1+x**2),
              df(asinh(x),x)= sqrt(x**2+1)/(x**2+1),
              df(atanh(x),x)= 1/(1-x**2),
              df(cos x,x)= -sin(x),
              df(sin(x),x)= cos(x),
              df(sec(x),x) = sec(x)*tan(x),
              df(tan x,x)=1 + tan x**2,
              df(sinh x,x)=cosh x,
              df(cosh x,x)=sinh x,
              df(sech(x),x) = - sech(x)*tanh(x),
%              df(tanh x,x)=sech x**2,
              df(tanh(x),x)=1-tanh(x)**2,    
              % JPff prefers this one for integration purposes
              df(cot x,x)=-1-cot x**2,
              df(coth x,x)=1-coth x**2;

let   e**(i*pi/2) = i,
      e**(i*pi) = -1,
      e**(3*i*pi/2)=-i;

%for all x let e**log x=x;   % Requires every power to be checked.

for all x,y let df(x**y,x)= y*x**(y-1),
                df(x**y,y)= log x*x**y;

% Square roots.

deflist('((sqrt simpsqrt)),'simpfn);

% for all x let sqrt x**2=x;

% !*!*sqrt:  used to indicate that SQRTs have been used.

% !*keepsqrts:  causes SQRT rather than EXPT to be used.

symbolic procedure mksqrt u;
   if not !*keepsqrts then list('expt,u,list('quotient,1,2))
    else <<if null !*!*sqrt then <<!*!*sqrt := t;
                              algebraic for all x let sqrt x**2=x>>;
      list('sqrt,u)>>;

for all x let df(sqrt x,x)=sqrt x/(2*x);

% Erf, exp, expint and dilog.

operator erf,exp,expint,dilog;

let erf 0=0;

let dilog(0)=pi**2/6;

for all x let erf(-x)=-erf x;

for all x let df(erf x,x)=2*sqrt(pi)*e**(-x**2)/pi;

for all x let exp(x)=e**x;

for all x let df(expint(x),x)=e**x/x;

for all x let df(dilog x,x)=-log x/(x-1);

% Supply missing argument and simplify 1/4 roots of unity.

let   e**(i*pi/2) = i,
      e**(i*pi) = -1,
      e**(3*i*pi/2)=-i;

% Rule for derivative of absolute value.

for all x let df(abs x,x)=abs x/x;

endmodule;


module maxmin;  % Support for generalized MAX and MIN.

% Author: F.J. Wright, QMW, London (fjw@maths.qmw.ac.uk) 7/7/90.

% Provide support for the MAX and MIN functions to allow:-
%     any number domain;
%     any symbolic arguments remain so;
%     nested algebraic-level lists of arguments;
% and to discard redundant nested max and min.
% The Lisp functions max and min are not affected.

put('max, 'simpfn, 'simpmax);

symbolic procedure simpmax u;
   simpmaxmin('max, function evalgreaterp, u);

put('min, 'simpfn, 'simpmin);

symbolic procedure simpmin u;
   simpmaxmin('min, function evallessp, u);

flag('(max min),'listargp);

symbolic procedure simpmaxmin(maxmin, relation, u);
   begin scalar arglist, arglistp, mval, x;
      if null u then return nil ./ 1;   % 0 returned for empty args.
      arglistp := arglist := list nil;  % Dummy car with cdr to rplacd.
      for each val in flattenmaxmin(maxmin, revlis u) do
         if atom denr(x := simp!* val)
            and (atom numr x or car x memq '(!:rd!: !:rn!:))
         % extremize numerical args:
           then (if null mval or apply2(relation,val, mval)
                   then mval := val)
         else
         % successively append symbolic args efficiently:
            << rplacd(arglistp, list val); arglistp := cdr arglistp >>;
      arglist := cdr arglist;  % Discard dummy car
      % Put any numerical extreme value at head of arg list:
      if mval then arglist := mval . arglist;
      % If more than one arg then keep as a max or min:
      if cdr arglist then return !*kk2f(maxmin . !*trim arglist) ./ 1;
      % Otherwise just return the single (extreme) value:
      return simp car arglist
   end;  % simpmaxmin

symbolic procedure !*trim u;
   % Trim repeated elements from u.
   if null u then nil
    else if car u member cdr u then !*trim cdr u
    else car u . !*trim cdr u;

symbolic procedure flattenmaxmin(maxmin, u);
   % Flatten algebraic-mode lists and already recursively simplified
   % calls of max/min as appropriate.
   for each el in u join
      if atom el then list el
      else if car el eq 'list then flattenmaxmin(maxmin, cdr el)
      else if car el eq maxmin then cdr el
      else if car el='mat then for each r in cdr el join r
      else list el;

endmodule;


module nssimp;  % Simplification functions for non-scalar quantities.

% Author: Anthony C. Hearn.

% Copyright (c) 1987 The RAND Corporation. All rights reserved.

fluid '(!*div);

global '(frlis!* subfg!*);

% Several inessential uses of ACONC, NCONC, and MAPping "JOIN". Latter
% not yet changed.

symbolic procedure nssimp(u,v);
   %U is a prefix expression involving non-commuting quantities.
   %V is the type of U.  Result is an expression of the form
   % SUM R(I)*PRODUCT M(I,J) where the R(I) are standard
   %quotients and the M(I,J) non-commuting expressions;
   %N. B: the products in M(I,J) are returned in reverse order
   %(to facilitate, e.g., matrix augmentation);
   begin scalar r,s,w,x,y,z;
        u := dsimp(u,v);
    a:  if null u then return z;
        w := car u;
    c:  if null w then go to d
         else if numberp(r := car w)
                or not(eqcar(r,'!*div) or
                       (if (s := getrtype r) eq 'yetunknowntype
                          then getrtype(r :=
                                        eval!-yetunknowntypeexpr(r,nil))
                         else s) eq v)
          then x := aconc!*(x,r)
         else y := aconc!*(y,r);
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
            else rerror(alg,30,list(y,x,"not set"))
         else if w := get(get(y,'tag),'i2d)
          then <<y := list apply1(w,1); go to e>>
         %to allow a scalar to be a 1 by 1 matrix;
         else msgpri(list("Missing",y,"in"),car x,nil,nil,t);
        put(car x,'rtype,y);
        y := list car x;
        x := cdr x;
        go to e
   end;

symbolic procedure dsimp(u,v);
   %result is a list of lists representing a sum of products;
   %N. B: symbols are in reverse order in product list;
   if numberp u then list list u
    else if atom u
     then (if x and subfg!* then dsimp(cadr x,v)
            else if flagp(u,'share) then dsimp(lispeval u,v)
            else <<flag(list u,'used!*); list list u>>)
      where x= get(u,'avalue)
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
       if not numberp z then errpri2(u,t)
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


module part;  % Access and updates parts of an algebraic expression.

% Author: Anthony C. Hearn.

% Copyright (c) 1991 RAND. All rights reserved.

fluid '(!*intstr);

symbolic procedure revalpart u;
   begin scalar !*intstr,expn,v,z;
      !*intstr := t;   % To make following result in output form.
      expn := if (z := getrtype car u) eq 'list then listeval0 car u
               else reval car u;
      !*intstr := nil;
      v := cdr u;
      while v do
         begin scalar x,y;
           if atom expn then parterr(expn,car v)
            else if not numberp(x := reval car v)
             then msgpri("Invalid argument",car v,"to part",nil,t)
            else if x=0
              then return <<expn :=
                              (if (getrtype w eq 'list) and (z := 'list)
                                 then listeval0 w
                                else if z eq 'list
                                 then <<!*intstr := t; w := reval w;
                                        !*intstr := z := nil; w>>
                                else w) where w = car expn;
                           v := nil>>
            else if x<0 then <<x := -x; y := reverse cdr expn>>
            else y := cdr expn;
           if length y<x then parterr(expn,car v)
            else expn := (if (getrtype w eq 'list) and (z := 'list)
                            then listeval0 w
                           else if z eq 'list
                            then <<!*intstr := t; w := reval w;
                                   !*intstr := z := nil; w>>
                           else w) where w = nth(y,x);
           v := cdr v
        end;
      return expn
   end;

put('part,'psopfn,'revalpart);

symbolic procedure revalsetpart u;
   % Simplifies a SETPART expression.
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

put('part,'rtypefn,'rtypepart);

symbolic procedure rtypepart u;
   if getrtypecar u then 'yetunknowntype else nil;
 
% symbolic procedure rtypepart(u);
%   if null cdr u then getrtypecar u
%    else begin scalar x,n;
%       x := car u;
%       if idp x then <<x := get(car u,'avalue);
%                       if x then x := cadr x>>;
%       if eqcar(x,'list) and numberp (n := aeval cadr u)
%         then return rtypepart(nth(cdr x,n) . cddr u)
%    end;
 
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
