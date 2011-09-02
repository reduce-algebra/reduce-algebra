module alg!-parse;  % Particular infix operators for algebraic mode.

% Author: Anthony C. Hearn.

% Copyright (c) 1987 The RAND Corporation.  All rights reserved.

newtok '((!. !+) add);

newtok '((!. !*) mult);

newtok '((!. !^) to);

newtok '((!. !* !*) to);

newtok '((!. !/) over);

infix .^,.*,.+,./;

endmodule;


module alg!-form;   % Some particular algebraic mode analysis functions.

% Author: Anthony C. Hearn.

% Copyright (c) 1987 The RAND Corporation.  All rights reserved.

global '(inputbuflis!* resultbuflis!* ws);

symbolic procedure forminput(u,vars,mode);
   begin scalar x;
      u := cadr u;
      if x := assoc(u,inputbuflis!*) then return cadr x
       else rederr list("Entry",u,"not found")
   end;

put('input,'formfn,'forminput);

symbolic procedure formws(u,vars,mode);
   begin scalar x;
      if x := assoc(cadr u,resultbuflis!*) then return mkquote cdr x
       else rederr list("Entry",cadr u,"not found")
   end;

put('ws,'formfn,'formws);

endmodule;


module intro;  % Introductory material for algebraic mode.

% Author: Anthony C. Hearn.

% Copyright (c) 1987 The RAND Corporation.  All rights reserved.

fluid '(!*cref !*exp !*intstr !*lcm !*mcd !*mode !*precise !*rationalize
        !*sub2);

global '(!*factor
         !*fort
         !*ifactor
         !*msg
         !*nat
         !*nero
         !*period
         !*pri
         !*reduced
         !*resubs
         !*val
         !*xdn
         erfg!*
         exlist!*
         initl!*
         nat!*!*
         ofl!*
         posn!*
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
!*xdn := t;             %flag indicating that denominators should be
                        %expanded;
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

% alglist!* := nil;     %association list for previously simplified
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
        if caar z>y then rederr list("Index",caar z,"out of range");
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
   begin scalar nat1,z;
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
        terpri!*(t); % IF NOT Y OR Y EQ 'HOLD THEN TERPRI();
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
        rederr "Please send output and input listing to A. C. Hearn"
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

flag ('(aeval arrayfn cond getel go prog progn prog2 return
        reval setq setk setel varpri !*s2i),'nochange);

flag ('(or and not member memq equal neq eq geq greaterp leq
        fixp lessp numberp ordp),'boolean);

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
    else rederr list("Wrong number of arguments to",v);

symbolic procedure delasc(u,v);
   if null v then nil
    else if atom car v or u neq caar v then car v . delasc(u,cdr v)
    else cdr v;

symbolic procedure eqexpr u;
   % Returns true if U is an equation.
   not atom u
      and car u memq '(eq equal) and cddr u and null cdddr u;

symbolic procedure evenp x; remainder(x,2)=0;

flag('(evenp),'opfn);  % Make a symbolic operator.

symbolic procedure get!*(u,v);
   if numberp u then nil else get(u,v);

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

symbolic procedure lhs u;
   % Returns the left-hand-side of an equation.
   if not eqexpr u then typerr(u,"equation") else cadr u;

symbolic procedure rhs u;
   % Returns the right-hand-side of an equation.
   if not eqexpr u then typerr(u,"equation") else caddr u;

flag('(lhs rhs),'opfn);  % Make symbolic operators.

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
   if null u then rederr "Index out of range"
    else if n=1 then u
    else pnth(cdr u,n-1);

symbolic procedure permp(u,v);
   if null u then t
    else if car u eq car v then permp(cdr u,cdr v)
    else not permp(cdr u,subst(car v,car u,cdr v));

symbolic procedure posintegerp u;
   % True if U is a positive (non-zero) integer.
   numberp u and fixp u and u>0;

symbolic procedure remove(x,n);
   %Returns X with Nth element removed;
   if null x then nil
    else if n=1 then cdr x
    else car x . remove(cdr x,n-1);

symbolic procedure repasc(u,v,w);
   % replaces value of key U by V in association list W.
   if null w then rederr list("key",u,"not found")
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
   if null v then nil
    else if atom v then v memq u
    else if car v eq 'quote then nil
    else smemqlp(u,car v) or smemqlp(u,cdr v);

symbolic procedure spaces n; for i := 1:n do prin2 " ";

symbolic procedure subla(u,v);
   begin scalar x;
        if null u or null v then return v
         else if atom v
                 then return if x:= atsoc(v,u) then cdr x else v
         else return(subla(u,car v) . subla(u,cdr v))
   end;

symbolic procedure xnp(u,v);
   %returns true if the atom lists U and V have at least one common
   %element;
   u and (car u memq v or xnp(cdr u,v));

endmodule;


module sqconsel;   % Constructors and selectors for standard forms.

% Author: Anthony C. Hearn.

% Copyright (c) 1987 The RAND Corporation.  All rights reserved.

smacro procedure u.+v; %standard (polynomial) addition constructor;
   u . v;

smacro procedure lc u;   %leading coefficient of standard form;
   cdar u;

smacro procedure ldeg u; %leading degree of standard form;
   cdaar u;

smacro procedure lt u;   %leading term of standard form;
   car u;

smacro procedure u.*v;  %standard form multiplication constructor;
   u . v;

smacro procedure mvar u; %main variable of standard form;
   caaar u;

smacro procedure lpow u; %leading power of standard form;
   caar u;

smacro procedure pdeg u;
   %returns the degree of the power U;
   cdr u;

smacro procedure red u; %reductum of standard form;
   cdr u;

smacro procedure tc u;   %coefficient of standard term;
   cdr u;

smacro procedure tdeg u; %degree of standard term;
   cdar u;

smacro procedure tpow u; %power of standard term;
   car u;

smacro procedure tvar u; %main variable of a standard term;
   caar u;

smacro procedure numr u; %numerator of standard quotient;
   car u;

smacro procedure denr u; %denominator of standard quotient;
   cdr u;

smacro procedure u ./ v; %constructor for standard quotient;
   u . v;

symbolic smacro procedure domainp u; atom u or atom car u;

endmodule;


module sqconvert;  % Procedures for converting between parts of standard
                   % quotients and prefix forms.

% Author: Anthony C. Hearn.

% Copyright (c) 1987 The RAND Corporation.  All rights reserved.

fluid '(!*mcd);

global '(wtl!*);

symbolic procedure !*a2f u;
   %U is an algebraic expression. Value is the equivalent form
   %or an error if conversion is not possible;
   !*q2f simp!* u;

symbolic procedure !*a2k u;
   %U is an algebraic expression. Value is the equivalent kernel
   %or an error if conversion is not possible.
   %earlier versions used SIMP0;
   begin scalar x;
      if kernp(x := simp!* u) then return mvar numr x
       else typerr(u,'kernel)
   end;

symbolic procedure !*d2q u;
   %converts domain element U into a standard quotient.
   if numberp u
     then if zerop u then nil ./ 1
   %       else if floatp u then mkfloat u ./ 1
           else u ./ 1
    else if eqcar(u,'!:rn!:) and !*mcd then cdr u
    else u ./ 1;

symbolic procedure !*ff2a(u,v);
   % Converts ratio of two forms U and V to a prefix form.
   (if wtl!* then prepsq x else mk!*sq x) where x = cancel( u ./ v);

smacro procedure !*f2a u; prepf u;

smacro procedure !*f2q u;
   %U is a standard form, value is a standard quotient;
   u . 1;

smacro procedure !*k2f u;
   %U is a kernel, value is a standard form;
   list ((u .** 1) . 1);

smacro procedure !*k2q u;
   %U is a kernel, value is a standard quotient;
   list((u .** 1) . 1) . 1;

symbolic procedure !*n2f u;
   %U is a number. Value is a standard form;
   if zerop u then nil else u;

smacro procedure !*p2f u;
   %U is a standard power, value is a standard form;
   list (u . 1);

smacro procedure !*p2q u;
   %U is a standard power, value is a standard quotient;
   list(u . 1) . 1;

symbolic procedure !*q2a u;
   %U is a standard quotient, value is an algebraic expression.
   prepsqxx u;

symbolic procedure !*q2f u;
   %U is a standard quotient, value is a standard form;
   if denr u=1 then numr u else typerr(prepsq u,'polynomial);

symbolic procedure !*q2k u;
   %U is a standard quotient, value is a kernel or an error if
   %conversion not possible;
   if kernp u then mvar numr u else typerr(prepsq u,'kernel);

smacro procedure !*t2f u;
   %U is a standard term, value is a standard form;
   list u;

smacro procedure !*t2q u;
   %U is a standard term, value is a standard quotient;
   list u . 1;

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

% Copyright (c) 1987 The RAND Corporation.  All rights reserved.

fluid '(!*exp !*intstr alglist!* dmode!*);

global '(!*resubs !*sqvar!* !*val);

symbolic procedure reval u;
   reval1(u,t);

symbolic procedure aeval u;
   reval1(u,nil);

symbolic procedure reval1(u,v);
   begin scalar alglist!*,x;
      % We rebind alglist!* to avoid invalid computation in loops.
      if null u then return nil   % this may give trouble
       else if stringp u then return u
       else if numberp u and fixp u
        then return if flagp(dmode!*,'convert) then reval2(u,v) else u
       else if atom u
        then if idp u and (x := get(u,'avalue))
               then return reval1(cadr x,v)
              else nil
       else if not idp car u or car u eq '!*comma!*
        then errpri2(u,t)
       else if car u eq '!*sq
        then return if caddr u
                      then if null v then u else prepsqxx cadr u
                     else reval2(u,v)
       else if flagp(car u,'opfn) then return reval1(opfneval u,v)
       else if x := get(car u,'psopfn) then return apply1(x,cdr u)
          % Note that we assume that the results of such functions are
          % always returned in evaluated form.
       else if arrayp car u then return reval1(getelv u,v);
       return if x := getrtype u then apply2(get(x,'evfn),u,v)
               else reval2(u,v)
   end;

symbolic procedure opfneval u;
   eval(car u . for each j in
                  (if flagp(car u,'noval) then cdr u else revlis cdr u)
                  collect mkquote j);

flag('(reval),'opfn);   % to make it a symbolic operator.

symbolic procedure reval2(u,v);
   (if null v then mk!*sq x else prepsqxx x) where x = simp!* u;

symbolic procedure getrtype u;
   % Returns overall algebraic type of u (or NIL is expression is a
   % scalar). Analysis is incomplete for efficiency reasons.
   % Type conflicts will later be resolved when expression is evaluated.
   begin scalar x,y;
    return
    if atom u
      then if not idp u then nil
            else if flagp(u,'share) then getrtype eval u
            else if x := get(u,'rtype)
                    then if y := get(x,'rtypefn) then apply1(y,nil)
                          else x
                  else nil
     else if not idp car u then nil
     else if (x := get(car u,'rtype)) and (x := get(x,'rtypefn))
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
   % Converts equation U to the difference of its two arguments.
   if null cdr u or null cddr u or cdddr u then typerr(u,"equation")
    else list('difference,cadr u,caddr u);

symbolic procedure getelv u;
   %returns the value of the array element U;
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

symbolic procedure expchk u;
   if !*exp then u else canprod(mkprod!* numr u,mkprod!* denr u);

symbolic procedure lengthreval u;
   begin scalar v,w;
      if length u neq 1
        then rederr "LENGTH called with wrong number of arguments"
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

symbolic procedure equalreval u; 'equal . revlis u;

put('equal,'psopfn,'equalreval);

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
   (lambda x; atom denr x and domainp numr x) simp!* u;

put('numberp,'boolfn,'evalnumberp);

endmodule;


module simp; % Functions to convert prefix forms into canonical forms.

% Author: Anthony C. Hearn.

% Modifications by: F. Kako.

% Copyright (c) 1987 The RAND Corporation.  All rights reserved.

fluid '(!*asymp!* !*exp !*gcd !*keepsqrts !*mcd !*mode !*numval
        !*precise !*rationalize !*sub2 !*uncached alglist!*
        current!-modulus dmode!*);

global '(!*convert
         !*match
         !*reduced
         exptl!*
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

% !*KEEPSQRTS causes SQRT rather than EXPT to be used;

!*convert := t;

put('simpcount!*,'initl,0);

initl!* := union('(simpcount!*),initl!*);

simplimit!* := 1000;

flagop noncom;

symbolic procedure simp!* u;
   begin scalar !*asymp!*,x;
        if eqcar(u,'!*sq) and caddr u then return cadr u;
        x := mul!* . !*sub2;    %save current environment;
        mul!* := nil;
        u:= simp u;
        for each j in mul!* do u:= apply1(j,u);
        mul!* := car x;
        u := subs2 u;
        if !*rationalize then u := rationalizesq u;
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
   begin scalar x;
        if simpcount!*>simplimit!*
         then <<simpcount!* := 0;
                rederr "Simplification recursion too deep">>
         else if eqcar(u,'!*sq) and caddr u then return cadr u
         else if null !*uncached and (x := assoc(u,alglist!*))
          then return <<if cadr x then !*sub2 := t; cddr x>>;
        simpcount!* := simpcount!*+1;
        if atom u then return !*ssave(simpatom u,u)
         else if not idp car u
          then if idp caar u and (x := get(caar u,'name))
                 then return !*ssave(u,u)     %%% not yet correct
                else errpri2(u,t)
         else if flagp(car u,'opfn)
          then if getrtype(x := opfneval u) then typerr(u,"scalar")
                else return !*ssave(simp x,u)
         else if x := get(car u,'psopfn)
          then if getrtype(x := apply1(x,cdr u)) then typerr(u,"scalar")
                else if x=u then return !*ssave(!*k2q x,u)
                else return !*ssave(simp x,u)
         else if x := get(car u,'polyfn)
          then return !*ssave(!*f2q apply(x,
                        for each j in cdr u collect !*q2f simp!* j),
                        u)
         else if get(car u,'opmtch)
                and not(get(car u,'simpfn) eq 'simpiden)
                and (x := opmtch revop1 u)
          then return !*ssave(simp x,u)
         else if x := get(car u,'simpfn)
          then return !*ssave(if flagp(car u,'full) or x eq 'simpiden
                        then apply1(x,u)
                       else apply1(x,cdr u),u)
         else if (x := get(car u,'rtype)) and (x := get(x,'getelemfn))
          then return !*ssave(simp apply1(x,u),u)
         else if flagp(car u,'boolean) or get(car u,'infix)
          then typerr(if x := get(car u,'prtch) then x else car u,
                      "algebraic operator")
         else if flagp(car u,'nochange)
          then return !*ssave(simp eval u,u)
         else if get(car u,'psopfn) then typerr(u,"scalar")
         else <<redmsg(car u,"operator");
                mkop car u;
                return !*ssave(simp u,u)>>;
   end;

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
        then alglist!* := (v . (!*sub2 . u)) . alglist!*;
      simpcount!* := simpcount!*-1;
      return u
   end;

symbolic procedure numlis u;
   null u or (numberp car u and numlis cdr u);

symbolic procedure simpatom u;
   if null u then nil ./ 1
    else if numberp u 
     then if zerop u then nil ./ 1
           else if not fixp u
            then !*d2q int!-equiv!-chk if null dmode!* then mkrat u
                  else if dmode!* eq '!:ft!: then mkfloat u
                  else apply1(get('!:ft!:,dmode!*),mkfloat u)
             % we assume that a non-fixp number is a float.
           else if flagp(dmode!*,'convert)
            then !*d2q int!-equiv!-chk apply1(get(dmode!*,'i2d),u)
           else u ./ 1
%   else if not idp u then typerr(u,"identifier")
    else if flagp(u,'share) then simp eval u
    else begin scalar z;
      if z := get(u,'idvalfn) then return apply1(z,u)
       else if !*numval and dmode!* and flagp(u,'constant)
          and (z := get(u,dmode!*))
          and not errorp(z := errorset(list('apply,mkquote z,nil),
                         nil,nil))
        then return !*d2q int!-equiv!-chk car z
       else if getrtype u then typerr(u,'scalar)
       else return mksq(u,1)
   end;

flag('(e pi),'constant);

symbolic procedure mkrat u;
   begin scalar x;
      x := !*ft2rn mkfloat u;
      msgpri(nil,u,"represented by",
             if atom x then x else list('quotient,cadr x,cddr x),
             nil);
      return x
   end;

symbolic procedure mkop u;
   begin scalar x;
        if null u then typerr("Local variable","operator")
         else if (x := gettype u) eq 'operator
          then lprim list(u,"already defined as operator")
         else if x and not x eq 'procedure then typerr(u,'operator)
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
      for each x in u do
         if not idp x then typerr(x,"id")
          else <<global list x;
                 if y := get(x,'avalue) then set(x,cadr y);
                 flag(list x,'share)>>
   end;

rlistat '(share);

flag('(ws !*mode),'share);


% ***** SIMPLIFICATION FUNCTIONS FOR EXPLICIT OPERATORS *****

symbolic procedure simpabs u;
   (lambda x; absf!* numr x ./ denr x) simpcar u;

put('abs,'simpfn,'simpabs);

symbolic procedure simpexpon u;
   % Exponents must not use non-integer arithmetic unless NUMVAL is on,
   % in which case DOMAINVALCHK must know the mode.
   if !*numval and not(dmode!* eq '!:mod!:) then simp!* u
    else begin scalar dmode!*,alglist!*; return simp!* u; end;

symbolic procedure simpexpt u;
   begin scalar flg,m,n,x,y;
        n := simpexpon carx(cdr u,'expt);
        u := car u;
    a:  if onep u then return 1 ./ 1;
        m := numr n;
        if not domainp m or not domainp denr n then go to nonumexp
         else if null m
          then return if numberp u and zerop u
                        then rederr " 0**0 formed"
                       else 1 ./ 1;
        x := simp u;
           %we could use simp!* here, except that it messes up the
           %handling of gamma matrix expressions;
        if null numr x then return nil ./ 1
         else if atom m and m>0 and denr n=1 and domainp numr x
                 and denr x=1
          then return !*d2q if atom numr x then numr x**m
                             else int!-equiv!-chk !:expt(numr x,m)
         else if y := domainvalchk('expt,list(x,n))
          then return y
         else if not atom m or denr n neq 1 then go to nonumexp
         else if not m<0 then return exptsq(x,m)
         else if !*mcd then return invsq exptsq(x,-m)
         else return expsq(x,m);   %using OFF EXP code here;
                %there may be a pattern matching problem though;
    nonumexp:
        if onep u then return 1 ./ 1
         else if atom u then go to a2
         else if car u eq 'times
          then <<n := prepsq n;
                 x := 1 ./ 1;
                 for each z in cdr u do
                   x := multsq(simpexpt list(z,n),x);
                 return x>>
         else if car u eq 'quotient
          then <<if not flg and !*mcd then go to a2;
                 n := prepsq n;
                 return multsq(simpexpt list(cadr u,n),
                          simpexpt list(caddr u,list('minus,n)))>>
         else if car u eq 'expt
          then <<n := multsq(simp caddr u,n);
                 if !*precise
                    and numberp caddr u and evenp caddr u
                    and numberp numr n and not evenp numr n
                   then u := list('abs,cadr u)
                  else u := cadr u;
                 x := nil;
                 go to a>>
         else if car u eq 'sqrt and not !*keepsqrts
          then <<n := multsq(1 ./ 2,n);
                 u := cadr u;
                 x := nil;
                 go to a>>
         else if car u eq 'minus and numberp m and denr n=1
          then return multsq(simpexpt list(-1,m),
                             simpexpt list(cadr u,m));
    a2: if null flg
          then <<flg := t;
                 u := prepsq if null x then (x := simp!* u) else x;
                 go to nonumexp>>
         else if numberp u and zerop u then return nil ./ 1
         else if not numberp m then m := prepf m;
        n := prepf cdr n;
        if m memq frlis!* and n=1 then return list ((u . m) . 1) . 1;
           %"power" is not unique here;
        if !*mcd or cdr x neq 1 or not numberp m or n neq 1
          or atom u then go to c
   %     else if minusf car x then return multsq(simpexpt list(-1,m),
   %                            simpexpt list(prepf negf car x,m));
         else if car u eq 'plus or not !*mcd and n=1
          then return mksq(u,m); %to make pattern matching work.
    c:% if !*numval and domaintypep u and n=1
      %    and (y := domainvalchk list('expt,u,m))  *** not correct now
      %   then return y else
        return simpx1(u,m,n)
   end;

% symbolic procedure intexpt(u,n);
%    if null current!-modulus or null(dmode!* eq '!:mod!:) then u**n
%         % I'm not sure we need both here.
%     else if n<0
%      then general!-modular!-expt(general!-modular!-recip u,-n)
%     else general!-modular!-expt(u,n);

put('expt,'simpfn,'simpexpt);

symbolic procedure simpx1(u,m,n);
   %U,M and N are prefix expressions;
   %Value is the standard quotient expression for U**(M/N);
        begin scalar flg,x,z;
        if numberp m and numberp n
           or null(smemqlp(frlis!*,m) or smemqlp(frlis!*,n))
          then go to a;
        % exptp!* := t;
        return mksq(list('expt,u,if n=1 then m
                                   else list('quotient,m,n)),1);
    a:  if numberp m then if minusp m then <<m := -m; go to mns>>
                           else if fixp m then go to e
                           else go to b
         else if atom m then go to b
         else if car m eq 'minus then <<m := cadr m; go to mns>>
         else if car m eq 'plus then go to pls
         else if car m eq 'times and numberp cadr m and fixp cadr m
                and numberp n
          then go to tms;
    b:  z := 1;
    c:  if idp u and not flagp(u,'used!*) then flag(list u,'used!*);
        if u = '(minus 1) 
               and n=1
               and null numr simp list('difference,m,'(quotient 1 2))
         then return simp 'i;
        u := list('expt,u,if n=1 then m else list('quotient,m,n));
        if not u member exptl!* then exptl!* := u . exptl!*;
    d:  return mksq(u,if flg then -z else z); %U is already in lowest
        %terms;
    e:  if numberp n and fixp n then go to int;
        z := m;
        m := 1;
        go to c;
    mns: %if numberp m and numberp n and !*rationalizeflag
         %  then return multsq(simpx1(u,n-m,n),invsq simp u) else
        if !*mcd then return invsq simpx1(u,m,n);
        flg := not flg;
        go to a;
    pls: z := 1 ./ 1;
    pl1: m := cdr m;
        if null m then return z;
        z := multsq(simpexpt list(u,
                        list('quotient,if flg then list('minus,car m)
                                        else car m,n)),
                    z);
        go to pl1;
    tms: z := gcdn(n,cadr m);
        n := n/z;
        z := cadr m/z;
        m := retimes cddr m;
        go to c;
    int:z := divide(m,n);
        if cdr z<0 then z:= (car z - 1) . (cdr z+n);
        x := simpexpt list(u,car z);
        if cdr z=0 then return x
         else if n=2 then return multsq(x,simpsqrt list u)
         else return multsq(x,exptsq(simprad(simp!* u,n),cdr z))
   end;

symbolic procedure expsq(u,n);
   % Raises standard quotient u to negative power n with exp off.
   multf(expf(numr u,n),mksfpf(denr u,-n)) ./ 1;

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

symbolic procedure simprad(u,n);
   %simplifies radical expressions;
   begin scalar x,y,z;
      x := radf(numr u,n);
      y := radf(denr u,n);
      z := multsq(car x ./ 1,1 ./ car y);
      z := multsq(multsq(mkrootlsq(cdr x,n),invsq mkrootlsq(cdr y,n)),
                  z);
      return z
   end;

symbolic procedure mkrootlsq(u,n);
   %U is a list of prefix expressions, N an integer.
   %Value is standard quotient for U**(1/N);
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
        then mksq(if n=2 then mksqrt cadr u
                   else list('expt,cadr u,list('quotient,1,n)),caddr u)
       else mksq(if n=2 then mksqrt u
                  else list('expt,u,list('quotient,1,n)),1);


comment The following three procedures return a partitioned root
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

symbolic procedure nrootn(n,x); 
   %N is an integer, X a positive integer. Value is a pair
   %of integers I,J such that I*J**(1/X)=N**(1/X);
   begin scalar i,j,r,signn; 
      r := 1; 
      if n<0 then <<n := -n; if evenp x then signn := t else r := -1>>;
      j := 2**x; 
      while remainder(n,j)=0 do <<n := n/j; r := r*2>>; 
      i := 3; 
      j := 3**x; 
      while j<=n do 
         <<while remainder(n,j)=0 do <<n := n/j; r := r*i>>; 
           if remainder(i,3)=1 then i := i+4 else i := i+2; 
           j := i**x>>; 
      if signn then n := -n; 
      return r . n
   end;

symbolic procedure simpiden u;
   begin scalar bool,fn,x,y,z;
        fn := car u;
        x := for each j in cdr u collect aeval j;
        u := fn . for each j in x collect
                      if eqcar(j,'!*sq) then prepsqxx cadr j
                       else if numberp j then j
                       else <<bool := t; j>>;
        if flagp(fn,'noncom) then ncmp!* := t;
        if null subfg!* then go to c
         else if flagp(fn,'linear) and (z := formlnr u) neq u
          then return simp z
         else if z := opmtch u then return simp z
         else if z := get(car u,'opvalfn) then return apply1(z,u)
         else if null bool and (z := domainvalchk(fn,
                                 for each j in x collect simp j))
          then return z;
    c:  if flagp(fn,'symmetric) then u := fn . ordn cdr u
         else if flagp(fn,'antisymmetric)
          then <<if repeats cdr u then return (nil ./ 1)
                  else if not permp(z:= ordn cdr u,cdr u) then y := t;
                 u := car u . z>>;
        u := mksq(u,1);
        return if y then negsq u else u
   end;

symbolic procedure domainvalchk(opr,args);
   % OPR is an operator, and ARGS its arguments as standard quotients.
   % If OPR . ARGS can be evaluated to a constant, result is the value,
   % otherwise NIL;
   begin scalar v,w,x,y,z;
      v := dmode!*;
      if null v or null !*numval or null(w := get(opr,dmode!*))
        then return nil;
   a: if null args
        then return if errorp(w := errorset(list('apply,
                                        mkquote w,mkquote reversip!* y),
                                       nil,nil))
                       or getd 'complexp and complexp car w
                      then nil
                     else if not domainp car w then car w ./ 1
                     else !*d2q int!-equiv!-chk car w
       else if not domainp(x := numr car args) or denr car args neq 1
        then return nil;
      if atom x
        then z := apply1(get(v,'i2d),if null x then 0 else x)
       else if car x eq v then z := x
       else if not(z := get(car x,v)) then return nil
       else z := apply1(z,x);
      y := z . y;
      args := cdr args;
      go to a
   end;

symbolic procedure simpdiff u;
   addsq(simpcar u,simpminus cdr u);

put('difference,'simpfn,'simpdiff);

symbolic procedure simpminus u;
   negsq simp carx(u,'minus);

put('minus,'simpfn,'simpminus);

symbolic procedure simpplus u;
   begin scalar z;
        z := nil ./ 1;
    a:  if null u then return z;
        z := addsq(simpcar u,z);
        u := cdr u;
        go to a
   end;

put('plus,'simpfn,'simpplus);

symbolic procedure simpquot u;
   multsq(simpcar u,simprecip cdr u);

put('quotient,'simpfn,'simpquot);

symbolic procedure simprecip u;
   if null !*mcd then simpexpt list(carx(u,'recip),-1)
    else invsq simp carx(u,'recip);

put('recip,'simpfn,'simprecip);

symbolic procedure simpset u;
  begin scalar x;
     if not idp (x := !*q2a simp!* car u) or null x
       then typerr(x,"set variable");
     let0 list(list('equal,x,mk!*sq(u := simp!* cadr u)));
     return u
  end;

put ('set, 'simpfn, 'simpset);

symbolic procedure simpsqrt u;
   begin scalar x,y;
      x := xsimp car u;
      return if denr x=1 and domainp numr x and !:minusp numr x
               then if numr x=-1 then simp 'i
                     else multsq(simp 'i,
                                 simpsqrt list prepd !:minus numr x)
              else if y := domainvalchk('expt,
                                        list(x,!*f2q mkfloat 0.5))
               then y
              else simprad(x,2)
   end;

symbolic procedure xsimp u; expchk simp!* u;

symbolic procedure simptimes u;
   begin scalar x,y;
        if tstack!* neq 0 or null mul!* then go to a0;
        y := mul!*;
        mul!* := nil;
    a0: tstack!* := tstack!*+1;
        x := simpcar u;
    a:  u := cdr u;
        if null numr x then go to c
         else if null u then go to b;
        x := multsq(x,simpcar u);
        go to a;
    b:  if null mul!* or tstack!*>1 then go to c;
        x:= apply1(car mul!*,x);
        alglist!* := nil;   % since we may need MUL!* set again;
        mul!*:= cdr mul!*;
        go to b;
    c:  tstack!* := tstack!*-1;
        if tstack!* = 0 then mul!* := y;
        return x;
   end;

put('times,'simpfn,'simptimes);

symbolic procedure resimp u;
   %U is a standard quotient.
   %Value is the resimplified standard quotient;
   quotsq(subf1(numr u,nil),subf1(denr u,nil));

symbolic procedure simp!*sq u;
   if null cadr u then resimp car u else car u;

put('!*sq,'simpfn,'simp!*sq);

endmodule;


module dmode; % Functions for defining and using poly domain modes.

% Author: Anthony C. Hearn;

% Copyright (c) 1987 The RAND Corporation.  All rights reserved.

fluid '(!*complex dmode!*);

global '(!*convert domainlist!*);

switch convert;

symbolic procedure initdmode u;
   % Checks that U is a valid domain mode, and sets up appropriate
   % interfaces to the system.
   begin
      dmodechk u;
      put(u,'simpfg,list(list(t,list('setdmode,mkquote u,t)),
                         list(nil,list('setdmode,mkquote u,nil))))
   end;

symbolic procedure setdmode(u,bool);
   % Sets polynomial domain mode.  If bool is NIL, integers are used,
   % or in the case of complex, set to the lower domain.
   % Otherwise mode is set to u, or derived from it.
   if null get(u,'tag)
     then rederr list("Domain mode error:",u,"is not a domain mode")
    else if u eq 'complex or !*complex then setcmpxmode(u,bool)
    else setdmode1(u,bool);

symbolic procedure setdmode1(u,bool);
   begin scalar x,y;
      x := get(u,'tag);
      y := dmode!*;
      if null bool
        then return if null y then nil
                     else <<rmsubs(); dmode!* := nil; get(y,'dname)>>
       else if x eq y then return x;
      % Now make sure there are no other domain switches left on.
      for each j in domainlist!* do
         if j neq '!:gi!: then
         set(intern compress append(explode '!*,explode get(j,'dname)),
             nil);
      rmsubs();
      y := get(y,'dname);
      if y then lprim list("Domain mode",y,"changed to",u);
      if u := get(u,'module!-name) then load!-module u;
      dmode!* := x;
      return y
   end;

symbolic procedure dmodechk u;
   %checks to see if U has complete specification for a domain mode;
   begin scalar z;
      if not(z := get(u,'tag))
        then rederr list("Domain mode error:","No tag for",z)
       else if not(get(z,'dname) eq u)
        then rederr list("Domain mode error:",
                         "Inconsistent or missing DNAME for",z)
       else if not z memq domainlist!*
        then rederr list("Domain mode error:",
                         z,"not on domain list");
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
             then rederr list("Domain mode error:",
                              x,"is not defined for",u)
   end;

symbolic procedure dmoderr(u,v);
   rederr list("Conversion between",get(u,'dname),
               "and",get(v,'dname),"not defined");

symbolic procedure mkdmoderr(u,v);
   list('lambda,'(!*x!*),list('dmoderr,mkquote u,mkquote v));


comment *** General Support Functions ***;

symbolic procedure fieldp u;
   %U is a domain element. Value is T if U is invertable, NIL
   %otherwise;
   not atom u and flagp(car u,'field);

symbolic procedure !:expt(u,n);
   % Raises domain element U to integer power N.  Value is a domain
   % element;
   if null u then if n=0 then rederr "0/0 formed" else nil
    else if n=0 then 1
    else if n=1 then u
    else if u=1 then 1
    else if n<0
     then !:recip !:expt(if not fieldp u then mkratnum u else u,-n)
    else if atom u then u**n
    else if car u eq '!:mod!:
     then (lambda x; if x=0 then nil else if x=1 then 1 else car u . x)
           general!-modular!-expt(cdr u,n)
    else begin scalar v,w,x;
      v := apply1(get(car u,'i2d),1);   %unit element;
      x := get(car u,'times);
   a: w := divide(n,2);
      if cdr w=1 then v := apply2(x,u,v);
      if car w=0 then return v;
      u := apply2(x,u,u);
      n := car w;
      go to a
   end;

symbolic procedure !:minus u;
   %U is a domain element. Value is -U;
   if atom u then -u else dcombine(u,-1,'times);

symbolic procedure !:minusp u;
   if atom u then minusp u else apply1(get(car u,'minusp),u);

symbolic procedure minuschk u;
   if eqcar(u,'minus)
      and (numberp cadr u
         or not atom cadr u and idp caadr u and get(caadr u,'dname))
     then !:minus cadr u
    else u;

symbolic procedure !:recip u;
   %U is an invertable domain element. Value is 1/U;
   begin
      if numberp u
        then if abs u=1 then return u
       else if null dmode!* then return mkrn(1,u)
       else if dmode!* eq '!:ft!: then return !*rn2ft mkrn(1,u)
       else u := apply1(get(dmode!*,'i2d),u);
      return dcombine(1,u,'quotient)
   end;

symbolic procedure dcombine(u,v,fn);
   %U and V are domain elements, but not both atoms (integers).
   %FN is a binary function on domain elements;
   %Value is the domain element representing FN(U,V);
   int!-equiv!-chk if atom u
        then apply2(get(car v,fn),apply1(get(car v,'i2d),u),v)
       else if atom v
        then apply2(get(car u,fn),u,apply1(get(car u,'i2d),v))
       else if car u eq car v then apply2(get(car u,fn),u,v)
       else begin scalar x;
        if not(x := get(car u,car v))
           then <<v := apply1(get(car v,car u),v);
                  x := get(car u,fn)>>
          else <<u := apply1(x,u); x := get(car v,fn)>>;
         return apply2(x,u,v)
        end;

symbolic procedure int!-equiv!-chk u;
   % U is a domain element. If U can be converted to 0, result is NIL,
   % if U can be converted to 1, result is 1,
   % if *convert is on and U can be converted to an integer, result
   % is that integer. Otherwise, U is returned.
   % In most cases, U will be structured.
   begin scalar x;
      if atom u then return u;
      if apply1(get(car u,'zerop),u) then return nil
       else if apply1(get(car u,'onep),u) then return 1
       else if null !*convert then return u
       else if (x := get(car u,'intequivfn)) and (x := apply1(x,u))
        then return x
       else return u
   end;


comment
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

To facilitate this, all such modes should be listed in the global
variable DOMAINLIST!*.

The following rules should also be followed when introducing new
domains:

Some modes, such as modular arithmetic, require that integers be
converted to domain elements when input or addition or multiplication
of such objects occurs.  Such modes should be flagged "convert".

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

endmodule;


module rational; % *** Tables for rational numbers ***;

% Author: Anthony C. Hearn;

% Copyright (c) 1987 The RAND Corporation.  All rights reserved.

global '(domainlist!*);

switch rational;

domainlist!* := union('(!:rn!:),domainlist!*);
put('rational,'tag,'!:rn!:);
put('!:rn!:,'dname,'rational);
flag('(!:rn!:),'field);
put('!:rn!:,'i2d,'!*i2rn);
put('!:rn!:,'minusp,'rnminusp!:);
put('!:rn!:,'plus,'rnplus!:);
put('!:rn!:,'times,'rntimes!:);
put('!:rn!:,'difference,'rndifference!:);
put('!:rn!:,'quotient,'rnquotient!:);
put('!:rn!:,'zerop,'rnzerop!:);
put('!:rn!:,'onep,'rnonep!:);
put('!:rn!:,'factorfn,'rnfactor!:);
put('!:rn!:,'prepfn,'rnprep!:);
put('!:rn!:,'prifn,'rnprin);
flag('(!:rn!:),'ratmode);

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

symbolic procedure rnminusp!: u; cadr u<0;

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

initdmode 'rational;

endmodule;


module float; % *** Tables for floats ***.

% Author: Anthony C. Hearn.

% Copyright (c) 1987 The RAND Corporation.  All rights reserved.

global '(domainlist!* ft!-tolerance!*);

switch float;

domainlist!* := union('(!:ft!:),domainlist!*);
put('float,'tag,'!:ft!:);
put('!:ft!:,'dname,'float);
flag('(!:ft!:),'field);
put('!:ft!:,'i2d,'!*i2ft);
put('!:ft!:,'!:rn!:,'!*ft2rn);
put('!:ft!:,'minusp,'ftminusp!:);
put('!:ft!:,'plus,'ftplus!:);
put('!:ft!:,'times,'fttimes!:);
put('!:ft!:,'difference,'ftdifference!:);
put('!:ft!:,'quotient,'ftquotient!:);
put('!:ft!:,'zerop,'ftzerop!:);
put('!:ft!:,'onep,'ftonep!:);
put('!:ft!:,'prepfn,'ftprep!:);
put('!:ft!:,'prifn,'floatprn);
put('!:ft!:,'cmpxtype,list '!:gf!:);
put('!:ft!:,'intequivfn,'ftintequiv);

symbolic procedure mkfloat u; '!:ft!: . u;

symbolic procedure !*i2ft u;
   %converts integer U to tagged floating point form;
   '!:ft!: . float u;

symbolic procedure !*ft2rn n;
   % Converts a floating point number N into a rational to the system
   % floating point precision.
   mkrn(car x,cdr x) where x = ft2rn1(cdr n,ft!-tolerance!*);

symbolic procedure ft2rn1(n,prec);
   begin scalar negp,a,p0,p1,q0,q1,w,flagg;
      if zerop n then return 0 . 1
       else if n<0 then <<negp := t; n := -n>>;
 top: a := fix n;
      n := n - float a;
      if not flagg
        then <<flagg := t; p0 := 1; p1 := a; q0 := 0; q1 := 1>>
       else <<w := p0 + a*p1; p0 := p1; p1 := w;
              w := q0 + a*q1; q0 := q1; q1 := w>>;
      if n<prec*a then return if negp then (-p1) . q1 else p1 . q1
       else if p1*q1*prec>1.0
        then return if negp then (-p0) . q0 else p0 . q0;
      n := 1.0/n;
      go to top
   end;

symbolic procedure !*rn2ft u;
   % Converts the (tagged) rational u/v into a (tagged) floating point
   % number to the system precision.
   mkfloat rn2ft1(cadr u,cddr u,ft!-tolerance!*);

symbolic procedure rn2ft1(u,v,prec);
   begin scalar negp,x,y,z;
      if v=0 then rederr "zero denominator"
       else if u=0 then return 0.0
       else if v<0 then <<u := -u; v := -v>>;
      if u<0 then <<negp := t; u := -u>>;
      x := 1.0;
      y := 0;
      z := 0.0;
      repeat
         <<z := y + z; y := divide(u,v); u := 10*cdr y;
           y := x*car y; x := x/10>>
        until u*x < prec*z;
      z := y + z;
      return if negp then -z else z
   end;

symbolic procedure ftminusp!: u; cdr u<0;

symbolic procedure ftplus!:(u,v);
%  car u . (lambda x; if abs x<0.000001*abs cdr u then 0.0 else x)
%           (cdr u+cdr v);
   car u . (cdr u+cdr v);

symbolic procedure fttimes!:(u,v); car u . (cdr u*cdr v);

symbolic procedure ftdifference!:(u,v); car u .(cdr u-cdr v);

symbolic procedure ftquotient!:(u,v); car u . (cdr u/cdr v);

symbolic procedure ftzerop!: u;
   abs cdr u < ft!-tolerance!*;

symbolic procedure ftonep!: u;
   abs(cdr u - 1.0) < ft!-tolerance!*;

symbolic procedure ftprep!: u; cdr u;

symbolic procedure floatprn u; prin2 cdr u;

symbolic procedure ftintequiv u;
   % Converts floating point number U to integer equivalent if within
   % precision of system.
   begin scalar x;
      u := cdr u;
      return if abs(u-(x := fix u)) < ft!-tolerance!* then x else nil
   end;

% The following square root function was written by Mary Ann Moore.

symbolic procedure sqrt n; sqrt!-float float n;

symbolic procedure sqrt!-float n;
% Simple Newton-Raphson floating point square root calculator.
  begin scalar scale,ans;
    if n=0.0 then return 0.0
    else if n<0.0 then rederr "SQRT!-FLOAT given negative argument";
    scale := 1.0; 
    % Detach the exponent by doing a sequence of multiplications
    % and divisions by powers of 2 until the remaining number is in
    % the range 1.0 to 4.0. On a binary machine the scaling should
    % not introduce any error at all;
    while n>256.0 do <<scale := scale*16.0; n := n/256.0>>;
    while n<1.0/256.0 do <<scale := scale/16.0; n := n*256.0>>;
    % Coarse scaled: now finish off the job.
    while n<1.0 do <<scale := scale/2.0; n := n*4.0>>;
    while n>4.0 do <<scale := scale*2.0; n := n/4.0>>;
    % 5 iterations get me as good a result as I can reasonably want
    % and it is cheaper  to do 5 always than to test for stopping
    % criteria.
    ans := 2.0;
    for i:=1:5 do ans := (ans+n/ans)/2.0;
    return ans*scale
  end;

initdmode 'float;


comment *** Entry points for the bigfloat package ***;

put('bigfloat,'simpfg,'((t (setdmode (quote bigfloat) t))
                        (nil (setdmode (quote bigfloat) nil))));

put('bigfloat,'tag,'!:bf!:);

switch bigfloat;

endmodule;


module polrep; % Arithmetic operations on standard forms and quotients.

% Author: Anthony C. Hearn.

% Copyright (c) 1987 The RAND Corporation.  All rights reserved.

fluid '(!*asymp!* !*exp !*gcd !*lcm !*mcd !*sub2 asymplis!* dmode!*);

global '(!*factor !*group ncmp!* powlis!* subfg!* wtl!*);

symbolic smacro procedure subtrsq(u,v); addsq(u,negsq v);

symbolic procedure addsq(u,v);
   %U and V are standard quotients.
   %Value is canonical sum of U and V;
   if null numr u then v
    else if null numr v then u
    else if denr u=1 and denr v=1 then addf(numr u,numr v) ./ 1
    else begin scalar x,y,z;
        if null !*exp then <<u := numr u ./ mkprod!* denr u;
                             v := numr v ./ mkprod!* denr v>>;
        if !*lcm then x := gcdf!*(denr u,denr v)
         else x := gcdf(denr u,denr v);
        z := canonsq(quotf(denr u,x) ./ quotf(denr v,x));
        y := addf(multf(denr z,numr u),multf(numr z,numr v));
        if null y then return nil ./ 1;
        z := multf(denr u,denr z);
        if x=1 then return y ./ z;     % ONEP
        x := gcdf(y,x);
        return if x=1 then y ./ z
                else canonsq(quotf(y,x) ./ quotf(z,x))
    end;

symbolic procedure multsq(u,v);
   %U and V are standard quotients.
   %Value is canonical product of U and V;
   if null numr u or null numr v then nil ./ 1
    else if denr u=1 and denr v=1 then multf(numr u,numr v) ./ 1
    else begin scalar x,y;
        x := gcdf(numr u,denr v);
        y := gcdf(numr v,denr u);
        return canonsq(multf(quotf(numr u,x),quotf(numr v,y))
                ./ multf(quotf(denr u,y),quotf(denr v,x)))
    end;

symbolic procedure negsq u;
   negf numr u ./ denr u;

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
   %U and V are both non-zero domain elements.
   %Value is standard form for U+V;
   if atom u and atom v
     then (lambda x; if null dmode!* or not flagp(dmode!*,'convert)
                       then !*n2f x
                      else int!-equiv!-chk
                              apply1(get(dmode!*,'i2d),x))
           plus2(u,v)
    else dcombine(u,v,'plus);

symbolic procedure domainp u; atom u or atom car u;

symbolic procedure noncomf u;
   if domainp u then nil
    else noncomp mvar u or noncomf lc u or noncomf red u;

symbolic procedure noncomp u; flagpcar(u,'noncom);

symbolic procedure multf(u,v);
   %U and V are standard forms.
   %Value is standard form for U*V;
   begin scalar ncmp,x,y;
    a:  if null u or null v then return nil
         else if u=1 then return v     % ONEP
         else if v=1 then return u     % ONEP
         else if domainp u then return multd(u,v)
         else if domainp v then return multd(v,u)
         else if not(!*exp or ncmp!* or wtl!* or x)
          then <<u := mkprod u; v := mkprod v; x := t; go to a>>;
        x := mvar u;
        y := mvar v;
        if (ncmp := noncomp y) and noncomp x then return multfnc(u,v)
         else if x eq y
          then <<x := mkspm(x,ldeg u+ldeg v);
                 y := addf(multf(red u,v),multf(!*t2f lt u,red v));
                 return if null x or null(u := multf(lc u,lc v))
                    then <<!*asymp!* := t; y>>
                   else if x=1 then addf(u,y)
                   else if null !*mcd then addf(!*t2f(x .* u),y)
                   else x .* u .+ y>>
         else if ordop(x,y) or ncmp and noncomf lc u
          then <<x := multf(lc u,v);
                 y := multf(red u,v);
                 return if null x then y else lpow u .* x .+ y>>;
        x := multf(u,lc v);
        y := multf(u,red v);
        return if null x then y else lpow v .* x .+ y
   end;

symbolic procedure multfnc(u,v);
   %returns canonical product of U and V, with both main vars non-
   %commutative;
   begin scalar x,y;
      x := multf(lc u,!*t2f lt v);
      return addf((if not domainp x and mvar x eq mvar u
                    then addf(if null (y := mkspm(mvar u,ldeg u+ldeg v))
                                then nil
                               else if y = 1 then lc x
                               else !*t2f(y .* lc x),
                            multf(!*p2f lpow u,red x))
                    else !*t2f(lpow u .* x)),
                  addf(multf(red u,v),multf(!*t2f lt u,red v)))
   end;

symbolic procedure multd(u,v);
   %U is a domain element, V a standard form.
   %Value is standard form for U*V;
   if null v then nil
    else if domainp v then multdm(u,v)
    else lpow v .* multd(u,lc v) .+ multd(u,red v);

symbolic procedure multdm(u,v);
   % U and V are both non-zero domain elements.
   % Value is standard form for U*V;
   if atom u and atom v
     then (lambda x; if null dmode!*
                        or not flagp(dmode!*,'convert) then x
                      else int!-equiv!-chk
                              apply1(get(dmode!*,'i2d),x))
           times2(u,v)
    else dcombine(u,v,'times);

smacro procedure multpf(u,v); multf(!*p2f u,v);

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
        % After this point, U is not KERNLP.
        % The check below for *MCD was suggested by James Davenport.
        % Without it, on gcd; off mcd,exp; (x**2+2x+1)/x+1; loops
        % forever.
        if !*mcd and (!*factor or !*gcd) then y := fctrf x
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

symbolic procedure mksp!*(u,n);
   % Returns a standard form for U**N. If U is a kernel product,
   % direct exponentiation is used.  Otherwise, U is first made
   % positive and then converted into a kernel.
   begin scalar b;
      if kernlp u then return exptf(u,n)
       else if minusf u then <<b := t; u := negf u>>;
      u := !*p2f mksp(u,n);
      return if b and not evenp n then negf u else u
   end;

put('!*sq,'lengthfn,'!*sqlength);

symbolic procedure !*sqlength u;
   (if denr car u=1 then x else x+termsf denr car u)
    where x = termsf numr car u;

symbolic procedure terms u;
%  <<lprim "Please use LENGTH instead"; termsf numr simp!* u>>;
   termsf numr simp!* u;

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

symbolic procedure expnd u;
   if domainp u then u
    else addf(if not sfp mvar u or ldeg u<0
                then multpf(lpow u,expnd lc u)
        else multf(exptf(expnd mvar u,ldeg u),expnd lc u),
                        expnd red u);

symbolic procedure mkprod!* u;
   if domainp u then u else mkprod u;

symbolic procedure canprod(p,q);
   %P and Q are kernel product standard forms, value is P/Q;
   begin scalar v,w,x,y,z;
        if domainp q then return cancel(p ./ q);
      while not domainp p or not domainp q do
        if sfpf p then
                <<z := cprod1(mvar p,ldeg p,v,w);
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
      v := numr w;
        if not domainp v and null red v and lc v=1     % ONEP
         and ldeg v=1 and sfp(x := mvar v)
        then v := x;
      return canonsq(v ./ denr w)
   end;

symbolic procedure sfpf u;
   not domainp u and sfp mvar u;

symbolic procedure sfp u;
   %determines if mvar U is a standard form;
   not atom u and not atom car u;

symbolic procedure reprod(u,v);
   %U is a list of powers,V a standard form;
   %value is product of terms in U with V;
   <<while u do <<v := multpf(car u,v); u := cdr u>>; v>>;

symbolic procedure cprod1(p,m,v,w);
   %U is a standard form, which occurs in a kernel raised to power M.
   %V is a list of powers multiplying P**M, W a list dividing it.
   %Value is a dotted pair of lists of powers after all possible kernels
   %have been cancelled;
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

symbolic procedure negf u;
   multd(-1,u);


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
        p := addf(p,multf(if n=0 then q
                               else multpf(y,q),negf x));
        %leading terms of P and Q do not cancel if MCD is off;
        %however, there may be a problem with off exp;
        if p and (domainp p or mvar p neq w) then return nil
         else if n=0 then go to b;
        z := aconc!*(z,y .* x);
        %provided we have a non-zero power of X, terms
        %come out in right order;
        if null p then return if z1 then nconc!*(z,z1) else z;
        go to a;
    b:  if null p then return nconc!*(z,x)
         else if !*mcd then return nil
         else z1 := x;
        go to a
   end
    else if ordop(mvar p,mvar q) then quotk(p,q)
    else nil;

symbolic procedure quotfd(p,q);
   % P is a standard form, Q a domain element.
   % Value is P/Q if exact division is possible, or NIL otherwise.
   begin scalar x;
      return if p=q then 1
              else if flagp(dmode!*,'field) and (x := !:recip q)
               then multd(x,p)
              else if domainp p then quotdd(p,q)
              else quotk(p,q)
   end;

symbolic procedure quotdd(u,v);
   % U and V are domain elements.  Value is U/V if division is exact,
   % NIL otherwise.
   if atom u then if atom v
                    then if remainder(u,v)=0 then u/v else nil
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
   cdr qremf(u,v);

put('remainder,'polyfn,'remf);

symbolic procedure qremf(u,v);
   %returns the quotient and remainder of U divided by V;
   begin integer n; scalar x,y,z;
        if domainp v then return qremd(u,v);
        z := list nil;   %final value;
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
   %U and V are dotted pairs of standard forms;
   addf(car u,car v) . addf(cdr u,cdr v);

symbolic procedure qremd(u,v);
   %Returns a dotted pair of quotient and remainder of form U
   %divided by domain element V;
   if null u then u . u
    else if v=1 then list u
    else if flagp(dmode!*,'field) then list multd(!:recip v,u)
    else if domainp u then qremdd(u,v)
    else begin scalar x;
        x := qremf(lc u,v);
        return praddf(multpf(lpow u,car x) . multpf(lpow u,cdr x),
                        qremd(red u,v))
   end;

symbolic procedure qremdd(u,v);
   %returns a dotted pair of quotient and remainder of non-invertable
   %domain element U divided by non-invertable domain element V;
   if atom u and atom v then dividef(u,v) else dcombine(u,v,'divide);

symbolic procedure dividef(m,n);
   (lambda x; (if car x=0 then nil else car x).
                        if cdr x=0 then nil else cdr x)
   divide(m,n);

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
   % U is a standard quotient.
   % Value is a standard quotient in which the leading power
   % of the denominator has a positive numerical coefficient and the
   % denominator is normalized where possible.
   if denr u=1 then u   % Used to be :ONEP
    else if null numr u then nil ./ 1
    else begin scalar x,y;
       % Check for non-trivial GCD if GCD is off, since an additional
       % factor may have been formed.
       if null !*gcd and (x := gcdf(numr u,denr u)) neq 1
         then u := quotf(numr u,x) ./ quotf(denr u,x);
       % See if we can remove numerical factor from denominator.
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
        if null dmode!* then return u
         else if flagp(dmode!*,'field)
          then <<
       % This section could be better coded if we required conversion
       % from rational to all field domains, but for the time being
       % we'll limit ourselves to floats.
               if atom x
                 then if dmode!* eq '!:ft!:
                        then return if atom numr u and atom denr u
                                 then !*rn2ft mkrn(numr u,denr u) ./ 1
                                else <<y := !*rn2ft mkrn(1,x);
                                       multd(y,numr u) ./
                                         multd(y,denr u)>>
                       else x := apply1(get(dmode!*,'i2d),x);
               y := dcombine(1,x,'quotient);
               if null y then errach list('canonsq,x);
               return multd(y,numr u) ./ multd(y,denr u)>>
         else if numberp x or not (y:= get(dmode!*,'units))
          then return u
         else return canonsq1(u,x,y)
   end;

symbolic procedure canonsq1(u,v,w);
   begin scalar z;
   a: if null w then return u;
      z := quotf1(v,caar w);
      if null z or not fixp z then <<w := cdr w; go to a>>;
      z := multf(denr u,cdar w);
      w := multf(numr u,cdar w);
      if minusf z then <<w := negf w; z := negf z>>;
      return w ./ z
   end;

symbolic procedure lnc u;
   % U is a standard form.  Value is the leading numerical coefficient.
   if null u then 0
    else if domainp u then u
    else lnc lc u;

symbolic procedure invsq u;
   begin
      if null numr u then rederr "Zero denominator"; 
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


module gcdn;   % gcd of integers.

% Author: Anthony C. Hearn

% Copyright (c) 1987 The RAND Corporation.  All rights reserved.

expr procedure gcdn(u,v);
%  { U and v are integers. Value is absolute value of gcd of u and v}
   if v = 0 then abs u else gcdn(v,remainder(u,v));

endmodule;


module gcd; % Greatest common divisor routines.

% Author: Anthony C. Hearn.

% Copyright (c) 1987 The RAND Corporation.  All rights reserved.

fluid '(!*exp !*ezgcd !*gcd !*heugcd dmode!*);

switch ezgcd,heugcd;

symbolic procedure comfac p;
  % P is a non-atomic standard form
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
       else if u=1 or v=1 then return 1   % ONEP
       else if domainp u then return gcdfd(u,v)
       else if domainp v then return gcdfd(v,u)
       else if quotf1(u,v) then return v
       else if quotf1(v,u) then return u;
      w := gcdf2(u,v);
      if !*gcd and u and v
               and (null quotf1(u,w) or null quotf1(v,w))
        then errach list("GCDF FAILED",prepf u,prepf v);
           %this probably implies that integer overflow occurred;
      return w
   end;

symbolic procedure gcdf2(u,v);
   % U and V are both non-trivial forms. Value is their GCD;
   begin scalar w,x,y,z,z1;
      if !*gcd and length(z1 := kernord(u,v))>1
        then <<w := setkorder z1; u := reorder u; v := reorder v>>
       else z1 := nil;
      if mvar u eq mvar v
        then <<x := comfac u;
               y := comfac v;
               z := gcdf1(cdr x,cdr y);
               if !*gcd
                 then z := multf(gcdk(quotf1(u,comfac!-to!-poly x),
                                      quotf1(v,comfac!-to!-poly y)),
                                 z);
               if car x and car y
                 then if pdeg car x>pdeg car y
                        then z := multpf(car y,z)
                       else z := multpf(car x,z)>>
       else if ordop(mvar u,mvar v) then z := gcdf1(cdr comfac u,v)
       else z := gcdf1(cdr comfac v,u);
      if z1 then <<setkorder w; z := reorder z>>;
      return z
   end;

symbolic procedure gcdfd(u,v);
   %U is a domain element, V a form;
   %Value is gcd of U and V;
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
   %U and V are primitive polynomials in the main variable VAR;
   %result is gcd of U and V;
   begin scalar lclst,var,w,x;
        if u=v then return u
         else if domainp u or degr(v,(var := mvar u))=0 then return 1
         else if ldeg u<ldeg v then <<w := u; u := v; v := w>>;
        if quotf1(u,v) then return v
         else if !*heugcd and (x := heu!-gcd(u,v)) then return x
         else if ldeg v=1
           or getd 'modular!-multicheck and modular!-multicheck(u,v,var)
          then return 1;
    a:  w := remk(u,v);
        if null w then return v
         else if degr(w,var)=0 then return 1;
        lclst := addlc(v,lclst);
        if x := quotf1(w,lc w) then w := x
         else for each y in lclst do while (x := quotf1(w,y)) do w := x;
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


module sub; % Functions for substituting in standard forms.

% Author: Anthony C. Hearn.

% Copyright (c) 1987 The RAND Corporation.  All rights reserved.

fluid '(!*nosubs asymplis!* dmode!*);

global '(ncmp!*);

% Simplification interface

symbolic procedure simpsub u;
   begin scalar !*nosubs,w,x,z;
    a:  if null cdr u
          then <<if getrtype car u or eqcar(car u,'equal) 
                   then typerr(car u,"scalar");
                 u := simp!* car u;
                 z := reversip!* z;   % to put replacements in same
                                      % order as input.
                 return quotsq(subf(numr u,z),subf(denr u,z))>>;
        !*nosubs := t;  % We don't want left side of eqns to change.
        w := reval car u;
        !*nosubs := nil;
        if getrtype w eq 'list
          then <<u := append(cdr w,cdr u); go to a>>
         else if not eqexpr w then errpri2(car u,t); 
        x := cadr w;
        if null getrtype x then x := !*a2k x;
        z := (x . caddr w) . z;
        u := cdr u;
        go to a;
   end;

put('sub,'simpfn,'simpsub);

symbolic procedure subsq(u,v); quotsq(subf(numr u,v),subf(denr u,v));

symbolic procedure subf(u,l);
   begin scalar alglist!*,x;
   %domain may have changed, so next line uses simpatom;
      if domainp u then return !*d2q u
       else if ncmp!* and noncomexpf u then return subf1(u,l);
      x := reverse xn(for each y in l collect car y,
                      kernord(u,nil));
      x := setkorder x;
      u := subf1(reorder u,l);
      setkorder x;
      return reorder numr u ./ reorder denr u
   end;

symbolic procedure noncomexpf u;
   not domainp u
      and (noncomp mvar u or noncomexpf lc u or noncomexpf red u);

symbolic procedure subf1(u,l);
   %U is a standard form,
   %L an association list of substitutions of the form
   %(<kernel> . <substitution>).
   %Value is the standard quotient for substituted expression.
   %Algorithm used is essentially the straight method.
   %Procedure depends on explicit data structure for standard form;
   if domainp u
     then if atom u then if null dmode!* then u ./ 1 else simpatom u
          else if dmode!* eq car u then !*d2q u
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
        if (x := getrtype xexp) then typerr(x,"substituted expression");
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
    h:  %Substitution for negative powers;
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
              else if flagp(car v,'subfn) then subsubf(u,v)
              else if get(car v,'dname) then v
              else if car v eq '!*sq then subsublis(u,prepsq cadr v)
              else for each j in v collect subsublis(u,j)
   end;

symbolic procedure subsubf(l,expn);
   %Sets up a formal SUB expression when necessary;
   begin scalar x,y;
      for each j in cddr expn do
         if (x := assoc(j,l)) then <<y := x . y; l := delete(x,l)>>;
      expn := sublis(l,car expn)
                 . for each j in cdr expn collect subsublis(l,j);
        %to ensure only opr and individual args are transformed;
      if null y then return expn;
      expn := aconc!*(for each j in reversip!* y
                     collect list('equal,car j,aeval cdr j),expn);
      return mk!*sq if l then simpsub expn
                     else !*p2q mksp('sub . expn,1)
   end;

flag('(int df),'subfn);

endmodule;


module exptf; % Functions for raising canonical forms to a power.

% Author: Anthony C. Hearn.

% Copyright (c) 1987 The RAND Corporation.  All rights reserved.

fluid '(!*exp);

symbolic procedure exptsq(u,n);
   begin scalar x;
        if n=1 then return u
         else if n=0
           then return if null numr u then rederr " 0**0 formed"
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
        while (n := n-1)>0 do x := multsq(u,x);
        return x
   end;

symbolic procedure exptf(u,n);
   if domainp u then !:expt(u,n)
    else if !*exp or kernlp u then exptf1(u,n)
    else mksfpf(u,n);

symbolic procedure exptf1(u,n);
   %iterative multiplication seems to be faster than a binary sub-
   %division algorithm, probably because multiplying a small polynomial
   %by a large one is cheaper than multiplying two medium sized ones;
   if n=0 then 1
    else begin scalar x;
         x := u;
         while (n := n-1)>0 do x := multf(u,x);
         return x
      end;


endmodule;


module kernel;   % Functions for operations on kernels.

% Author: Anthony C. Hearn.

% Copyright (c) 1987 The RAND Corporation.  All rights reserved.

global '(exlist!* kprops!*);

symbolic procedure fkern u;
   %finds the unique "p-list" reference to the kernel U. The choice of
   %the search and merge used here has a strong influence on some
   %timings. The ordered list used here is also used by Prepsq* to
   %order factors in printed output, so cannot be unilaterally changed;
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

%   else kernels1(red u,kernels1(lc u,ordas(mvar u,v)));
%   else kernels1(lc u,kernels1(red u,ordas(mvar u,v)));

% symbolic procedure ordas(a,l);
%    if null l then list a
%     else if a=car l then l
%     else if ordp(a,car l) then a . l
%     else car l . ordas(a,cdr l);

symbolic procedure kernp u;
   % true if U is standard quotient representation for a kernel.
   denr u=1 and not domainp(u := numr u)
        and null red u and lc u=1 and ldeg u=1;     % ONEP

endmodule;


module mksp; % Functions for making standard powers.

% Author: Anthony C. Hearn.

% Copyright (c) 1987 The RAND Corporation.  All rights reserved.

fluid '(!*nosubs !*sub2 asymplis!*);

global '(!*resubs
         powlis!*
         subfg!*
         wtl!*);

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

symbolic procedure mksfpf(u,n);
   %raises form U to power N with EXP off. Returns a form;
%   if domainp u then !:expt(u,n)
%    else if n>=0 and kernlp u
%     then if null red u and onep lc u then !*p2f mksp(mvar u,ldeg u*n)
%          else exptf1(u,n)
%    else if n=1 or null subfg!* then mksp!*(u,n)
%    else (lambda x; %if x and cdr x<=n then nil else mksp!*(u,n))
%         assoc(u,asymplis!*);
   exptf(mkprod!* u,n);

symbolic procedure mksq(u,n);
    %U is a kernel, N a non-zero integer;
    %Value is a standard quotient of U**N, after making any
    %possible substitutions for U;
   begin scalar x,y,z;
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
           %implements explicit sign matching;
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
    d:  %optimization is possible as shown if all expression
        %dependency is known;
        %if cdr z then return exptsq(cdr z,n); %value already computed;
        if null !*resubs then !*nosubs := t;
        x := simpcar z;
        !*nosubs := nil;
        %rplacd(z,x);           %save simplified value;
        %subl!* := z . subl!*;
        return exptsq(x,n)
   end;

endmodule;


module order; % Functions for internal ordering of expressions.

% Author: Anthony C. Hearn.

% Copyright (c) 1987 The RAND Corporation.  All rights reserved.

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
   %returns TRUE if U ordered ahead or equal to V, NIL otherwise.
   %an expression with more structure at a given level is ordered 
   %ahead of one with less;
   if null u then null v
    else if null v then t
    else if atom u
       then if atom v
                then if numberp u then numberp v and not u<v
                      else if numberp v then t else orderp(u,v)
             else nil
    else if atom v then t
    else if car u=car v then ordp(cdr u,cdr v)
    else ordp(car u,car v);

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


module reord; % Functions for reordering standard forms.

% Author: Anthony C. Hearn.

% Copyright (c) 1987 The RAND Corporation.  All rights reserved.

fluid '(kord!*);

global '(ncmp!*);

symbolic procedure reorder u;
   %reorders a standard form so that current kernel order is used;
   if domainp u then u
    else raddf(rmultpf(lpow u,reorder lc u),reorder red u);

symbolic procedure raddf(u,v);
   %adds reordered forms U and V;
   if null u then v
    else if null v then u
    else if domainp u then addd(u,v)
    else if domainp v then addd(v,u)
    else if peq(lpow u,lpow v)
     then (lpow u .* raddf(lc u,lc v)) .+ raddf(red u,red v)
    else if ordpp(lpow u,lpow v) then lt u . raddf(red u,v)
    else lt v . raddf(u,red v);

symbolic procedure rmultpf(u,v);
  %multiplies power U by reordered form V;
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
   begin scalar v; v := kord!*; kord!* := u; return v end;

endmodule;


module forall; % FOR ALL Command.

% Author: Anthony C. Hearn.

% Copyright (c) 1987 The RAND Corporation.  All rights reserved.

fluid '(!*backtrace !*sub2 alglist!* arbl!* asymplis!*);

global '(!*match
         cursym!*
         erfg!*
         frasc!*
         frlis!*
         letl!*
         mcond!*
         powlis!*
         powlis1!*
         subfg!*
         wtl!*);

letl!* := '(let match clear saveas such);   %special delimiters;

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
      frasc!* := y;
      frlis!* := union(x,frlis!*);
      return eval caddr u
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
%     vars := append(car u,vars);   % semantics are different
      if null cadr u then x := t else x := formbool(cadr u,vars,mode);
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
        then list('list,mkquote 'equal,form1(cadr x,vars,mode),
                                !*s2arg(form1(caddr x,vars,mode),vars))
       else errpri2(x,t);

symbolic procedure !*s2arg(u,vars);
   %makes all NOCHANGE operators into their listed form;
   if atom u then u
    else if not idp car u or not flagp(car u,'nochange)
     then for each j in u collect !*s2arg(j,vars)
    else mkarg(u,vars);

put('let,'formfn,'formlet);

put('clear,'formfn,'formclear);

put('match,'formfn,'formmatch);

symbolic procedure formclear(u,vars,mode);
   list('clear,formclear1(cdr u,vars,mode));

symbolic procedure formclear1(u,vars,mode);
   'list . for each x in u collect form1(x,vars,mode);

symbolic procedure formlet(u,vars,mode);
   list('let,formlet1(cdr u,vars,mode));

symbolic procedure formmatch(u,vars,mode);
   list('match,formlet1(cdr u,vars,mode));

symbolic procedure let u; let0 u;    % to distinguish between operator
                                     % and function.
symbolic procedure let0 u;
   begin
   a: if null u
         or errorp
            errorset(list('let2,mkquote cadar u,mkquote caddar u,nil,t),
                     t,!*backtrace)
        then go to b;
      u := cdr u;
      go to a;
   b: mcond!* := frasc!* := nil
   end;

symbolic procedure let2(u,v,w,b);
   begin scalar flg,x,y,z;
        % FLG is set true if free variables are found;
        x := subla(frasc!*,u);
        if x neq u
          then if atom x then return errpri1 u
                 else <<flg := t; u := x>>;
        x := subla(frasc!*,v);
        if x neq v
          then <<v := x;
                 if eqcar(v,'!*sq!*) then v := prepsq!* cadr v>>;
                 % to ensure no kernels are replaced by uneq copies
                 % during pattern matching process;
        %check for unmatched free variables;
        x := smemql(frlis!*,mcond!*);
        y := smemql(frlis!*,u);
        if (z := setdiff(x,y))
           or (z := setdiff(setdiff(smemql(frlis!*,v),x),
                    setdiff(y,x)))
          then <<lprie ("Unmatched free variable(s)" . z);
                 erfg!* := 'hold;
                 return nil>>
         else if eqcar(u,'getel) then u := eval cadr u;
    a:  x := u;
        if null x then <<u := 0; return errpri1 u>>
         else if numberp x then return errpri1 u
         else if idp x and flagp(x,'reserved)
          then rederr list(x,"is a reserved identifier")
         else if y := getrtype x then return
                 if z := get(y,'typeletfn)
                    then apply(z,list(x,v,y,b,getrtype v))
                  else typelet(x,v,y,b,getrtype v)
         else if y := getrtype v then return
                 if z := get(y,'typeletfn)
                    then apply(z,list(x,v,nil,b,y))
                  else typelet(x,v,nil,b,y)
         else if not atom x
               then if not idp car x then return errpri2(u,'hold)
                     else if car x eq 'df
                      then if null letdf(u,v,w,x,b) then nil
                            else return nil
                     else if getrtype car x
                      then return let2(reval x,v,w,b)
                     else if not get(car x,'simpfn)
                      then <<redmsg(car x,"operator");
                             mkop car x; go to a>>
                     else nil
         else if null b and null w
          then <<if (y := get(x,'rtype)) 
                   then <<remprop(x,'rtype); remprop(x,'rvalue)>>
                  else remprop(x,'avalue);
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
          then letexprn(u,v,w,!*k2q x,b,flg);
           % special case of a non-integer exponent match;
        x := simp0 x;
        return if not domainp numr x then letexprn(u,v,w,x,b,flg)
                else errpri1 u
   end;

symbolic procedure letexprn(u,v,w,x,b,flg);
   %replacement of scalar expressions;
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
                 if null flg
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
                if v=0 and null w and not flg
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
   begin scalar x,y,z;
        y := setkorder frlis!*;
        if eqcar(u,'!*sq) then return simp0 prepsq!* cadr u;
        x := subfg!* . !*sub2;
        subfg!* := nil;
        if atom u
           or idp car u 
              and (flagp(car u,'simp0fn) or get(car u,'rtype))
          then z := simp u
         else z := simpiden u;
        alglist!* := delasc(u,alglist!*);
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
      for each x in u do <<let2(x,nil,nil,nil); let2(x,nil,t,nil)>>;
      mcond!* := frasc!* := nil
   end;

symbolic procedure typelet(u,v,ltype,b,rtype);
   % General function for setting up rules for typed expressions.
   % LTYPE is the type of the left hand side U, RTYPE, that of RHS V.
   % B is a flag that is true if this is an update, nil for a removal.
   begin
        if null rtype then rtype := 'scalar;
        if ltype eq rtype then go to a
         else if null b then go to c
         else if ltype then typerr(list(ltype,u),rtype)
         else if not atom u
          then if arrayp car u then go to a else typerr(u,rtype);
        redmsg(u,rtype);
        put(u,'rtype,rtype);
        ltype := rtype;
    a:  if b and (not atom u or flagp(u,'used!*)) then rmsubs();
    c:  if not atom u
          then if arrayp car u
                 then setelv(u,if b then v else nil)
                else put(car u,'opmtch,xadd!*(cdr u .
                    list(nil . (if mcond!* then mcond!* else t),v,nil),
                        get(car u,'opmtch),b))
         else if null b
          then <<remprop(u,'rvalue);
                 remprop(u,'rtype);
                 if ltype eq 'array then remprop(u,'dimension)>>
         else if get(u,'avalue) then typerr(list("VARIABLE",u),rtype)
         else put(u,'rvalue,v)
   end;

symbolic procedure setk(u,v);
   begin scalar x;
      if not atom u 
         and idp car u
         and (x := get(car u,'rtype))
         and (x := get(x,'setelemfn))
        then apply2(x,u,v)
       else let2(u,v,nil,t);
      return v
   end;

symbolic procedure setk1(u,v,b);
   begin scalar x,y;
        if not atom u then go to c
         else if null b then go to b1
         else if (x := get(u,'avalue))
          then <<x := cdr x; go to a>>;
        x := nil . nil;
        put(u,'avalue,'scalar . x);
    a:  rplacd(rplaca(x,v),nil);
        return v;
    b1: if not get(u,'avalue) then msgpri(nil,u,"not found",nil,nil)
         else remprop(u,'avalue);
        return;
    c:  if not atom car u
          then rederr "Invalid syntax: improper assignment";
        u := car u . revlis cdr u;
        if null b then go to b2
         else if not (y := get(car u,'kvalue)) then go to e
         else if x := assoc(u,y) then go to d;
        x := nil . nil;
        aconc(y,u . x);
        go to a;
    d:  x := cdr x;
        go to a;
    e:  x := nil . nil;
        put(car u,'kvalue,list(u . x));
        go to a;
    b2: if not(y := get(car u,'kvalue)) or not (x := assoc(u,y))
          then msgpri(nil,u,"not found",nil,nil)
         else put(car u,'kvalue,delete(x,y));
        return;
   end;

symbolic procedure klistt u;
   if atom u then nil else caar u . klistt cdr carx(u,'list);

symbolic procedure kernlp u;
   % Returns leading domain coefficient if U is a monomial product 
   % of kernels, NIL otherwise.
   if domainp u then u else if null red u then kernlp lc u else nil;

symbolic procedure xadd(u,v,b);
   %adds replacement U to table V, with new rule at head;
   begin scalar x;
        x := assoc(car u,v);
        if null x
          then if b and not(b eq 'replace) then v := u . v else nil
         else if b
          then <<v := delete(x,v);
                 if not(b eq 'replace) then v := u . v>>
         else if cadr x=cadr u then v := delete(x,v);
        return v
   end;

symbolic procedure xadd!*(u,v,b);
   %adds replacement U to table V, with new rule at head;
   %also checks boolean part for equality;
   begin scalar x;
      x := v;
      while x and not(car u=caar x and cadr u=cadar x) do x := cdr x;
      if x then v := delete(car x,v);
      if b then v := u . v;
      return v
   end;


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
        alglist!* := nil
   end;

endmodule;


module algdcl;  % Various declarations.

% Author: Anthony C. Hearn.

% Copyright (c) 1987 The RAND Corporation.  All rights reserved.

global '(frlis!* preclis!* ws);

symbolic procedure formopr(u,vars,mode);
   if mode eq 'symbolic
     then mkprog(nil,list list('flag,mkquote cdr u,mkquote 'opfn))
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

flag('(den num max min),'opfn);

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


end;
