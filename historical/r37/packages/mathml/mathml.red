% REDUCE - MAhathML interface
% written by Luis Alvarez-Sobreviela 
% email:   alvarez@zib.de  (or neun@zib.de)
% University of Bath, in placement at ZIB in Berlin
% 1998-1999

module mathml;

%Declaration of two switches.
%_mathml_ allows all output to be printed in mathml.
%_both_ allows all output to be printed in mathml and in normal reduce
%output.

global '(!*mathml);
switch mathml;
global '(!*both);
switch both;

LISP (FILE!*:=nil);
!*mathml:=nil;
!*both:=nil;

off both;
off mathml;

%Declaration of a series of lists which contain the function to be executed 
%when the token (cadr) is found.

%Tokens to be found between <ci></ci> tags.

fluid '(rdci!* rdlist!*);

RDci!*:='
((!&imaginaryi!; consts 'i) (!&ii!; consts 'i) (!&exponential!; consts 'e)
(!&ee!; consts 'e) (!&differentiald!; const 'd) (!&dd!; consts 'd));

%Tokens to be found between <relation></relation> tags.

fluid '(rdreln!*);

RDreln!*:=
'((tendsto tendstoRD ) (eq!/ relationRD 'eq)
 (neq!/ relationRD 'neq) (lt!/ relationRD 'lt)
 (gt!/ relationRD 'gt) (geq!/ relationRD 'geq)
 (leq!/ relationRD 'leq) (in!/ inRD )
 (notin!/ notinRD ) (subset!/ relationRD 'subset)
 (prsubset!/ relationRD 'prsubset) (notprsubset!/ notprsubsetRD )
 (notsubset!/ notsubsetRD ));

%Tokens to be found between <apply></apply> tags.

RDlist!*:=
'((divide!/ divideRD) (setdiff!/ setdiffRD) (select!/ selectRD)
 (transpose!/  transposeRD) (determinant!/ determinantRD)
 (fn applyfnRD) (union!/ unionRD) (intersection!/ intersectionRD)
 (implies!/ impliesRD) (not!/ notRD) (xor!/ xorRD) (or!/ orRD)
 (and!/ andRD) (mean!/ meanRD) (var!/ varRD) (sdev!/ sdevRD)
 (moment!/ momentRD) (median!/ medianRD) (sin!/ sinRD)
 (sec!/ secRD) (sinh!/  sinhRD) (sech!/  sechRD)
 (arcsin!/  arcsinRD) (cos!/  cosRD) (csc!/  cscRD)
 (cosh!/  coshRD) (csch!/  cschRD) (arccos!/  arccosRD)
 (tan!/  tanRD) (cot!/  cotRD) (tanh!/  tanhRD)
 (coth!/  cothRD) (arctan!/  arctanRD) (abs!/  absRD)
 (ln!/  lnRD) (plus!/  plusRD) (times!/  timesRD)
 (power!/  powerRD) (exp!/  expRD) (factorial!/  factorialRD)
 (quotient!/  quotientRD) (max!/  maxRD) (min!/  minRD)
 (minus!/  minusRD) (rem!/ remRD) (conjugate!/  conjugateRD)
 (root!/  rootRD) (gcd!/  gcdRD) (log!/ logRD) (int!/ intRD)
 (sum!/  sumRD) (limit!/ limitRD) (condition conditionRD)
 (product!/ productRD) (diff!/ diffRD) (partialdiff!/ partialdiffRD));


%The next three functions are the lexer. When called they returns the next
%mathml token in the input stream. 

FLUID '(safe_atts char ch atts count temp space temp2);

symbolic procedure lex();
begin scalar token;
 token:=nil;
 if atts neq nil then safe_atts:=atts;
 atts:=nil;
 if ch neq !$EOF!$ then <<
  if ch=space then while (ch:=readch())=space do
  else
   if ch='!< then char:=get_token()
   else char:=get_content();
   if char neq nil then
   <<  count:=count+1;
       token:=reverse char;
       char:=butes(token);
%By decomenting the following line, the tokens read in are one by one
%printed onto the output stream.
%       print char;
       attributes(char,token)>>
    else lex(); >>
end;

symbolic procedure get_token();
begin scalar d;
 d:=();
 while (ch:=readch()) neq '!> do d:=cons(ch,d);
 return cons('!$,d);
end;

symbolic procedure get_content();
begin scalar d;
 d:=();
 while (ch:=readch()) neq '!< AND ch neq !$EOF!$
do
    if ch neq space AND id2int(ch)>10 then
d:=cons(ch,d);
 if d neq nil then d:=cons('!$,d);
 return d;
end;

%This function will search the list of attributes _att_ for the attribute
%named _key_

symbolic procedure search_att( att, key);
begin scalar l, stop,d;
 l:=nil;
 d:=();
 stop:=0;
 att:= find(att, key);
 if att neq '(stop) then 
 <<
 while (car att='! ) do att:=cdr att;
 if (car att = '!=) then
   <<
     att:=cdr att;
     while (car att='! ) do att:=cdr att;
     if (car att='!") then
      << att:=cdr att;
         while (stop=0) do
          << d:=cons(car att, d);
             att:=cdr att;
             if (car att='!  ) OR (car att='!$) then stop:=1
          >>
      >>
      else
         while (stop=0) do
          << d:=cons(car att, d);
             att:=cdr att;
             if (car att='!  ) OR (car att='!$) then stop:=1
          >>
   >>
 else
 errorML(crunch key,1);
 if car d='!" then d:=cdr d;
 return reverse d
 >>
end;
 
symbolic procedure find(fatt, fkey);
    if fkey= '() then if fatt neq nil then cdr fatt else '(stop)
          else find(member(car fkey, fatt), cdr fkey);
         
symbolic procedure attributes(a,b);
begin scalar l;
 l:=length a;
 for a:=1:l do b:=cdr b;
 while (car b='! ) do b:=cdr b;
 if b neq '(!$) then  atts:=b;         
end;


symbolic procedure butes( str );
%Removes all attributes
begin scalar cha;
cha:=car str;
return if (cha='!  OR cha='!$) then <<'(); >>
        else  cons(car str, butes cdr str);
end;

%This is the MAIN function. It is given the name of a file which contains
%the mathml input. It launches the program by calling parseML().

fluid '(file!*);

symbolic procedure mml(f);
begin scalar f;
 load assist;
 file!* := open(f, 'input);
 f := rds(file!*);
 parseML();
 rds f;
 close file!*;
 FILE!*:=nil; 
end;

%This function starts the parsing mechanism, which is a recursive descent
%parsing.

symbolic procedure parseML();
begin scalar res, vswitch;
 res:=nil;
 vswitch:=nil;
 load matrix;
 space:=int2id(32);
 count:=0;
 ch:=readch();
 lex();
 if char='(m a t h) then
     res:=mathML()
   else errorML("<math>",2);
 lex();
 if char='(!/ m a t h) then
   terpri() 
   else errorML("</math>",19);
if !*mathml=t OR !*both=t then 
 << 
   vswitch:=outputhandler!*;
   outputhandler!*:=nil;
   if !*both=t then 
   << if PAIRP res then
    << if memq(car res,'(!*sq mat list eq)) then mathprint res
       else print res>>
    else print res; 
    terpri()>>;
   math_ml(res);
   outputhandler!*:=vswitch
 >>
else
<<
if PAIRP res then
 <<if memq(car res,'(!*sq mat list eq)) then mathprint res
   else print res>>
else print res
>>;
 terpri();
 return res;
end;

%The two next functions differ in that one of them parses from the next
%token onwards, and the other one from the actual token onwards.


symbolic procedure mathML();
begin scalar a;
 a:=nil;
 lex();
 return sub_math();
end;

symbolic procedure mathML2();
begin scalar a;
 a:=nil;
 return sub_math();
end;

%Parses all tokens which legally follow a mathml token.

symbolic procedure sub_math();
begin scalar a;
 a:=nil;
 if char='(a p p l y) then
    <<a:= applyML();
     if char neq '(!/ a p p l y) then
      errorML("</apply>",3);
      return a>>
 else
  if char='(c n) then
   <<a:=cnML();
     lex();
     if char neq '(!/ c n) then
       errorML("</cn>",2);
     return a>> 
 else 
  if char='(c i) then
   <<a:=ciML();
     lex();
     if char neq '(!/ c i) then
       errorML("</ci>",2);
     return a>> 
 else 
  if char='(r e l a t i o n) then 
   <<a:=relnRD();
     if char neq '(!/ r e l a t i o n) then
       errorML("</relation>",2);
     return a>>
 else 
  if char='(s e t) then 
   <<a:=setRD();
     if char neq '(!/ s e t) then 
       errorML("</set>",2);
     return a>>
 else 
  if char='(f n) then 
   <<a:=fnRD();
     if char neq '(!/ f n) then
       errorML("</fn>",2);
     return a>>
 else 
  if char='(d e c l a r e) then 
   <<a:=declareRD();
     if char neq '(!/ d e c l a r e) then 
       errorML("</declare>",2);
     return a>>
 else   
  if char='(l i s t) then 
   <<a:=listRD();
     if char neq '(!/ l i s t) then 
	errorML("</list>",2);
     return a>>
 else
  if char='(m a t r i x) then 
   <<a:=matrixRD();
     if char neq '(!/ m a t r i x) then 
       errorML("</matrix>",2);
     return a>>
 else
  if char='(v e c t o r) then 
   <<a:=vectorRD();
     if char neq '(!/ v e c t o r) then 
       errorML("</vector>",2);
     return a>>
 else
  if char='(l a m b d a) then 
   <<a:=lambdaRD();
     if char neq '(!/ l a m b d a) then 
       errorML("</lambda>",2);
     return a>>
 else 
  return nil;
end;


%The next two functions parse the <cn> and <ci> tokens and extracts its
%content to be used by the function calling it. It will have different
%behaviours according to the type of the <cn> data.

symbolic procedure cnML();
begin scalar type, sep;
%Must check that what is being returned is an int.
 type:=nil; sep:=nil;
 type:=search_att(atts, '(t y p e));
 lex();
 if IDP crunch char then errorML(crunch char, 16);
 if type=nil then return crunch char;
 if member(type, '((r e a l) (i n t e g e r))) neq nil then 
    return crunch char;
 if member(type, '((r a t i o n a l) (c o m p l e x !- c a r t e s i a n) 
                   (c o m p l e x !- p o l a r))) neq nil then
   << sep:=sepRD();
   if type='(r a t i o n a l) then return alg_quotient(car sep, cadr sep)
else
      if type='(c o m p l e x !- c a r t e s i a n) then 
         return comp2(car sep, cadr sep) else
      if type='(c o m p l e x !- p o l a r) then
        <<sep:= po2ca(sep);
          return  comp2(car sep, cadr sep)>>
   >>;
end;


symbolic procedure ciML();
begin scalar test, type,aa;
 aa:=nil; type:=nil; test:=nil;
 type:=search_att(atts, '(t y p e));
 lex();
 if type='(c o n s t a n t) then 
 <<  
  if (aa:=assoc(intern crunch char, RDci!*)) then 
     return apply(first cdr aa, rest cdr aa) >>
  else
   << test:=crunch char; 
      if NUMBERP test then errorML(test, 4);
      test:=intern test;
      return test>>
end;

%returns the algebraic value of the constant values.

algebraic procedure consts(c);
 if member(c,'(i d e)) then c else nil;

%Constructs a complex number.

algebraic procedure comp2(a,b); 
  a+b*i;

%Returns the two values separated by a <sep/> tag.

symbolic procedure sepRD();
begin scalar p1, p2;
 p1:=nil; p2:=nil;
 p1:=crunch char;
 lex();
 if char neq '(s e p !/) then errorML("<sep/>",2);
 lex();
 p2:=crunch char;
 return list(p1,p2);
end; 

%Creates a vector by using function matrix_row.

symbolic procedure vectorRD();
begin scalar a;
 a:=nil;
 a:=matrixrowRD();
 a:=lisp aeval list('mat, a);
 return a;
end;

%The following functions construct the matrix from the mathml information.

symbolic procedure matrixRD();
begin scalar b1, b2, stop;
 stop:=0;
 b1:='();
 b2:=nil;
 while stop=0 do
 <<
   lex();
   if char='(m a t r i x r o w) then 
    <<b2:=matrixrowRD();
      if b1 neq nil then b1:=append(b1, list b2)
      else b1:=list b2;
      if char neq '(!/ m a t r i x r o w) then 
       errorML("</matrixrow>",2)>>
   else stop:=1
  >>; 
 return aeval cons ('mat ,b1);
end;

symbolic procedure matrixrowRD();
begin scalar a;
 a:=nil;
 a:=mathML();
 return if a=nil then nil
        else cons(a, matrixrowRD());
end;

%returns a lambda function constructed from the information supplied.

symbolic procedure lambdaRD();
begin scalar b1, b2;
 lex();
 b1:=bvarRD();
 b1:=car b1;
 b2:=mathML();
 lex();
 return algebraic( (lambda  b1; b2) b1 );
end;

%returns a set constructed from the information supplied.

symbolic procedure setRD();
begin scalar setvars;
 atts:='(t y p e != s e t !$);
 setvars:= cons('set,stats_getargs());
 setvars:=cons(car setvars, norepeat(cdr setvars));
 return setvars;
end;

%This function will keep one copy only of any repeating elements

symbolic procedure norepeat(args);
begin;
return if args=nil then nil else
 if length args=1 then list car args
 else append(list car args, norepeat(delall(car args, cdr args)));
end;

%This function will delete all occurences of element x in list l

symbolic procedure delall(x,l);
if l=nil then nil 
else if x=car l then delall(x, cdr l)
     else append(list car l ,delall(x, cdr l));

%returns a list constructed from the information supplied.

symbolic procedure listRD();
begin scalar setvars, lorder;
 lorder:=search_att(atts, '(o r d e r));
 atts:='(t y p e != l i s t !$);
 setvars:= cons('list,stats_getargs());
 if lorder='(l e x i c o g r a p h i c) then 
   setvars:=algebraic sortlist (setvars, lexog);
 if lorder='(n u m e r i c) then 
  setvars:=algebraic sortlist (setvars, numer) 
 else
   setvars:=algebraic sortlist (setvars, pred);
 return setvars;
end;
 
%Defines the predicate function used by function _sortlist_. Sortlist comes
%from package assist, and its documentation can be found in assist's
%documentation

%This one will sort all elements in numerical and alphanumerical order

symbolic procedure pred(u,v);
begin;
return if NUMBERP u and NUMBERP v then <<if u<v then t>> else
 if IDP u and IDP v then <<if id2int(u) < id2int(v) then t>> 
 else if NUMBERP u and IDP v then <<if u<id2int(v) then t>> else
if IDP u and NUMBERP v then <<if id2int(u)<v then t>>;
end;

%This one sorts in alphanumerical order

symbolic procedure lexog(u,v);
begin;
 return if IDP u and IDP v then <<if id2int(u) < id2int(v) then t>> 
 else t;
end;

%This one sorts in numerical order

symbolic procedure numer(u,v);
begin;
 return if NUMBERP u and NUMBERP v then <<if u<v then t>> 
 else t;
end;

%Makes the next token in the inputstream an operator.

symbolic procedure fnRD();
begin scalar b1;
 lex();
 if char neq '(c i) then errorML(crunch char,20)
 else b1:= mathML2();
 if ATOM b1 then algebraic operator b1;
 lex();
 return b1;
end;

%Reads the declare construct and sets the value of the given variable to
%the given value.

symbolic procedure declareRD();
begin scalar b1, b2, nargs;
 b1:=mathML();
 clear b1;
 clear reval b1;
 lex();
 if atts neq nil then 
   put(b1, 'type, search_att(atts,'(t y p e)));
 if search_att(atts, '(t y p e)) = '(f n) then 
   nargs:=car search_att(atts, '(n a r g s));
 if char='(!/ d e c l a r e) then return nil;
 b2 :=mathML2();
 if get(b1, 'type)='(f n) then 
  << algebraic operator b1>>;
 algebraic set(b1, b2);
 lex();
 return nil;
end;

%This function will determine if the next token is a valid token following
%an apply token. It then calls the appropriate function if succesful.

symbolic procedure applyML();
begin scalar aa;
 lex();
 if (aa:=assoc(intern crunch char, RDlist!*)) then return apply(first cdr aa, rest cdr aa)
 else
 if char='(i d e n t !/) then return nil else
 if char='(c o m p o s e !/) then return nil else
 if char='(i n v e r s e !/) then return t else
  errorML(crunch char, 17);
end;

%Reads the next two elements and returns their setdifference.

symbolic procedure setdiffRD();
begin scalar b1, b2;
 b1:=mathML();
 b2:=mathML();
 lex();
 if b1=reval b1 and b2=reval b2 then return list('setdiff,b1, b2)
else
 if b1=reval b1 then return list('setdiff, b1, reval b2) else
 if b2=reval b2 then return list('setdiff, reval b1, b2) else
 return append(list('set), setdiff(reval b1, reval b2));
end;

%Reads through a select construct and acts accordingly.

symbolic procedure selectRD();
begin scalar a1, res;
 a1:=stats_getargs();
 if caar a1='mat then res:=mat_select(a1); 
 if caar a1='list then res:=list_select(a1);
 return cons('list,res);
end;

symbolic procedure mat_select(a1);
 if length car a1=2 then  nth(cadar a1, cadr a1)
 else
 if length a1=2 then nth(cdar a1, cadr a1) else
 if length a1=3 then  nth(nth(cdar a1, caddr a1), cadr a1);

symbolic procedure list_select(a1);
  nth(cdar a1, cadr a1);

%Returns the transpose of the element contained in the transpose tags.

symbolic procedure transposeRD();
begin scalar a, res;
 a:=mathML();
 if a=reval a then res:=append(list 'transpose,list a)
 else res:=algebraic(tp a);
 lex();
 return res;
end;

%Returns the determinant of the given element.

symbolic procedure determinantRD();
begin scalar a, res;
 a:=mathML();
 if a=reval a then res:=append(list 'determinant,list a)
 else res:=algebraic det a;
 lex();
 return res;
end;

%Takes the given function name, makes it an operator, and then
%applies it to the arguments specified in the mathml input.

symbolic procedure applyfnRD();
begin scalar b1, b2, c1;
 b1:=nil; b2:=nil; c1:=nil;
 b1:=fnRD();
 b2:=stats_getargs();
 b2:=cons(b1, b2);
 c1:=algebraic b2;
 return  c1;
end;

%Returns the union of the elements specified.

symbolic procedure unionRD();
begin scalar b1;
 b1:=stats_getargs();
 constants(b1);
 temp:=car b1;
 if temp2='stop then 
  <<temp2:=nil; return append(list('union), eval_list_sets(b1))>>
 else return cons('set, delall('list, alg_union(b1)));
end;

symbolic procedure alg_union(args);
begin;
 return if args=nil then reval temp 
 else union(reval car args, alg_union(cdr args));
end;

%Returns the intersection of the elements specified.

symbolic procedure intersectionRD();
begin scalar b1;
 b1:=stats_getargs();
 constants(b1);
 temp:=car b1;
 if temp2='stop then 
  <<temp2:=nil; 
   return append(list('intersection), eval_list_sets(b1))>>
 else return cons('set, cdr intersect(b1));
end;

symbolic procedure intersect(args);
begin;
 return if args=nil then reval temp 
 else intersection(reval car args, intersect(cdr args));
end;

%Takes all the arguments in a list, and evaluates them if they can be
%evaluated.

symbolic procedure eval_list(args);
  if args=nil then nil
   else cons(reval car args, eval_list(cdr args));

%Tkes all the arguments in a list of sets, and evaluates them if they can
%be evaluated.

symbolic procedure eval_list_sets(args);
begin scalar ab;
 return if args=nil then nil
 else <<if PAIRP reval car args then 
    	<<
	  if car reval car args='list then 
             ab:=cons('set, cdr reval car args)>>
        else ab:=reval car args; 
        cons(ab, eval_list_sets(cdr args))>>;
end;

%Sets global variable temp2 to 'stop if an evaluatable element is found in
%list args.

symbolic procedure constants(args);
begin scalar b1;
if args neq nil then b1:=car args;
 return if args=nil then nil
   else <<if b1=reval b1 AND IDP b1 OR PAIRP b1 then temp2:='stop
          else  constants(cdr args)>>; 
end;

%Return boolean values of the arguments given.

symbolic procedure notRD();
begin scalar a;
 a:=mathML();
 lex();
 return not(reval a);
end;

symbolic procedure impliesRD();
begin scalar a1,b1,c1;
 a1:=mathML();
 b1:=mathML();
 if b1='false then b1:=nil;
 if a1='false then a1:=nil;
 if reval a1 AND not reval b1 then c1:=nil 
 else c1:=t;
 lex();
 return c1;
end; 

symbolic procedure andRD();
begin scalar a;
 a:=stats_getargs();
 a:=subst(nil, 'false, a);
 a:=and2RD(a);
 return a;
end;

symbolic procedure and2RD(args);
 if length args=1 then reval car args
    	else and(reval car args, and2RD(cdr args));

symbolic procedure orRD();
begin scalar a;
 a:=stats_getargs();
 a:=subst(nil, 'false, a);
 a:=or2RD(a);
 return a;
end;

symbolic procedure or2RD(args);
 if length args=1 then reval car args
    	else or(reval car args, or2RD(cdr args));

symbolic procedure xorRD();
begin scalar a;
 a:=stats_getargs();
 a:=subst(nil, 'false, a);
 a:=xor2RD(a);
 return a;
end;

symbolic procedure xor2RD(args);
 if args=() then nil
    	else alg_xor(reval car args, xor2RD(cdr args));

symbolic procedure alg_xor(a,b);
begin;
 return and(or(a,b),not(and(a,b)));
end;

%All defined trigonometric functions.

algebraic procedure sinRD();
begin scalar a;
 a:=symbolic mathML();
 symbolic lex();
 return sin(a);
end;

algebraic procedure secRD();
begin scalar a;
 a:=symbolic mathML();
 symbolic lex();
 return sec(a);
end;

algebraic procedure sinhRD();
begin scalar a;
 a:=symbolic mathML();
 symbolic lex();
 return sinh(a);
end;

algebraic procedure sechRD();
begin scalar a;
 a:=symbolic mathML();
 symbolic lex();
 return sech(a);
end;

algebraic procedure arcsinRD();
begin scalar a;
 a:=symbolic mathML();
 symbolic lex();
 return asin(a);
end;

algebraic procedure cosRD();
begin scalar a;
 a:=symbolic mathML();
 symbolic lex();
 return cos(a);
end;

algebraic procedure cscRD();
begin scalar a;
 a:=symbolic mathML();
 symbolic lex();
 return csc(a);
end;

algebraic procedure coshRD();
begin scalar a;
 a:=symbolic mathML();
 symbolic lex();
 return cosh(a);
end;

algebraic procedure cschRD();
begin scalar a;
 a:=symbolic mathML();
 symbolic lex();
 return csch(a);
end;

algebraic procedure arccosRD();
begin scalar a;
 a:=symbolic mathML();
 symbolic lex();
 return acos(a);
end;

algebraic procedure tanRD();
begin scalar a;
 a:=symbolic mathML();
 symbolic lex();
 return tan(a);
end;

algebraic procedure cotRD();
begin scalar a;
 a:=symbolic mathML();
 symbolic lex();
 return cot(a);
end;

algebraic procedure tanhRD();
begin scalar a;
 a:=symbolic mathML();
 symbolic lex();
 return tanh(a);
end;

algebraic procedure cothRD();
begin scalar a;
 a:=symbolic mathML();
 symbolic lex();
 return coth(a);
end;

algebraic procedure arctanRD();
begin scalar a;
 a:=symbolic mathML();
 symbolic lex();
 return atan(a);
end;

%Reads the condition tag.

symbolic procedure conditionRD();
begin scalar a;
 lex();
 if char='(r e l a t i o n) then a:=relnRD()
 else a:=mathML();
 lex();
 return a;
end;

%This function will read all legal tags following the <relation> tag.

symbolic procedure relnRD();
begin scalar a, aa;
 lex();
 if (aa:=assoc(intern crunch char, RDreln!*)) then 
    a:=apply(first cdr aa, rest cdr aa)
 else
  errorML(crunch char, 18);
 return if a=t then t 
        else if a=nil then 'false else a;
end;


symbolic procedure relationRD( type );
begin scalar args,a;
 args:=stats_getargs();
 if type='(quote eq) then <<a:= alg_eq(args)>> else
 if type='(quote neq) then <<a:= alg_neq(args)>> else
 if type='(quote lt) then <<a:= alg_lt(args)>> else
 if type='(quote gt) then <<a:= alg_gt(args)>> else
 if type='(quote subset) then <<a:=subsetRD(args)>> else
 if type='(quote prsubset) then <<a:=prsubsetRD(args)>> else
 if type='(quote geq) then <<a:= alg_geq(args)>> else
 if type='(quote leq) then <<a:= alg_leq(args)>>;
 return if a=t then t 
        else if a=nil then 'false else a;
end;

%The following functions do all the necessay actions in order to evaluate
%what should be by the tags.

symbolic procedure notsubsetRD();
begin scalar b1, b2;
 b1:=mathML();
 b2:=mathML();
 lex();
 if b1=reval b1 AND b2=reval b2 then 
    return list('notsubset, b1, b2);
 if b1= reval b1 then 
    return list('notsubset, b1,cons ('set, cdr reval b2));
 if b2= reval b2 then 
    return list('notsubset, cons('set,cdr reval b1), b2);
 if intersection(cdr reval b1,cdr reval b2)=nil then 
    return t 
 else
    return nil; 
end; 

symbolic procedure notprsubsetRD();
begin scalar b1, b2;
 b1:=mathML();
 b2:=mathML();
 lex();
 if b1=reval b1 AND b2=reval b2 then 
    return list('notprsubset, b1, b2);
 if b1= reval b1 then 
    return list('notprsubset, b1,cons('set, cdr reval b2));
 if b2= reval b2 then 
    return list('notprsubset, cons('set,cdr reval b1), b2);
 if reval b1 = reval b2 then return t;
 if intersection(cdr reval b1,cdr reval b2)=nil then return t else
return nil; 
end;


symbolic procedure subsetRD(sets);
begin scalar args,val;
 args:=sets;
 val:=t;
 while (length args > 1) do 
  << if NUMBERP reval car args then 
       errorML(reval car args,5);
     if car args = reval car args OR cadr args = reval cadr args then
     << args:='();
	val:=cons('subset, eval_list_sets(sets))>>
     else
     << val:=AND(val, alg_subset(reval car args, reval cadr args));
	args:=cdr args >> 
  >>;
 return val;
end;

symbolic procedure alg_subset(a,b);
begin;
  if a=b then return t
  else
  if setdiff(a,b)=nil then return t else return nil;
end;

symbolic procedure prsubsetRD(sets);
begin scalar args, val;
 val:=t;
 while (length args > 1) do 
  << if car args = reval car args OR cadr args = reval cadr args then
     << args:='();
	val:=cons('prsubset, eval_list_sets(sets))>>
     else
     << val:=AND(val, alg_prsubset(reval car args, reval cadr args));
	args:=cdr args >> >>;
 return val;
end;

symbolic procedure alg_prsubset(a,b);
begin;
  if setdiff(a,b)=nil then return t else return nil;
end;

symbolic procedure inRD();
begin scalar b1,b2;
 b1:= mathML();
 b2:= mathML();
 lex();
 if b2 = reval b2 AND ATOM b2 then
 << 
    if b2='n then <<if FIXP b1 then return t else return nil>>;
    if b2='r then <<if NUMBERP b1 then return t else return nil>>;
    return list('in, reval b1, b2)>>;
 if MEMBER(reval b1,reval  b2) neq nil then return t
   else return nil;
end;

symbolic procedure notinRD();
begin scalar b1,b2;
 b1:= mathML();
 b2:= mathML();
 lex();
 if b2 = reval b2 AND ATOM b2 then
 << 
    if b2='N then if FIXP b1 then return nil else return nil;
    if b2='R then if NUMBERP b1 then return nil else return nil;
    return list('notin, reval b1, b2)>>;
 if MEMBER(reval b1,reval  b2) neq nil then return nil
   else return t;
end;

symbolic procedure alg_eq(args);
begin;
 constants(args);
 if temp2='stop then 
 <<temp2:=nil; return append(list 'eq, eval_list(args))>>
 else return alg_eq2(eval_list(args));
end;

symbolic procedure alg_eq2(args);
begin;
 return if length args=1 then t
        else if (reval car args eq reval cadr args) then
		alg_eq2(cdr args);
end;

symbolic procedure alg_neq(args);
begin;
 constants(args);
 if temp2='stop then 
 <<temp2:=nil; return append(list 'neq, eval_list(args))>>
 else return alg_neq2(eval_list(args));
end;

symbolic procedure alg_neq2(args);
begin;
 return if length args=1 then t
        else if (reval car args neq reval cadr args) then
		alg_neq2(cdr args);
end;

symbolic procedure alg_lt(args);
begin;
 constants(args);
 if temp2='stop then 
 <<temp2:=nil; return append(list 'lt, eval_list(args))>>
 else return alg_lt2(eval_list(args));
end;

symbolic procedure alg_lt2(args);
begin;
 return if length args=1 then t
        else 
 if (NUMBERP reval car args AND NUMBERP reval cadr args )then 
   <<if (reval car args < reval cadr args) then 
       alg_lt2(cdr args)
     else nil>>
 else errorML("",6);
end;

symbolic procedure alg_gt(args);
begin;
 constants(args);
 if temp2='stop then 
 <<temp2:=nil; return append(list 'gt, eval_list(args))>>
 else return alg_gt2(eval_list(args));
end;

symbolic procedure alg_gt2(args);
begin;
 return if length args=1 then t
        else 
 if (NUMBERP reval car args AND NUMBERP reval cadr args )then 
   <<if (reval car args > reval cadr args) then 
       alg_gt2(cdr args)
     else nil>>
 else errorML("",6);
end;

symbolic procedure alg_geq(args);
begin;
 constants(args);
 if temp2='stop then 
 <<temp2:=nil; return append(list 'geq, eval_list(args))>>
 else return alg_geq2(eval_list(args));
end;

symbolic procedure alg_geq2(args);
begin;
 return if length args=1 then t
        else 
 if (NUMBERP reval car args AND NUMBERP reval cadr args )then 
   <<if (reval car args >= reval cadr args) then 
       alg_geq2(cdr args)
     else nil>>
 else errorML("",6);
end;

symbolic procedure alg_leq(args);
begin;
 constants(args);
 if temp2='stop then 
 <<temp2:=nil; return append(list 'leq, eval_list(args))>>
 else return alg_leq2(eval_list(args));
end;

symbolic procedure alg_leq2(args);
begin;
 return if length args=1 then t
        else 
 if (NUMBERP reval car args AND NUMBERP reval cadr args )then 
   <<if (reval car args <= reval cadr args) then 
       alg_leq2(cdr args)
     else nil>>
 else errorML("",6);
end;

%Interprets the <tendsto> tag when used in the <limit> tag.

symbolic procedure tendstoRD();
begin scalar attr, arg1 ,arg2;
 if intersection(atts, '(t y p e)) neq nil then 
    attr:=search_att(atts, '(t y p e))
 else attr:=nil;
 arg1:=mathML();
 arg2:=mathML();
 lex();
 return list (attr,arg2);
end;
    
%Returns the limit of the information given. Uses the Reduce package
%LIMITS.

symbolic procedure limitRD();
begin scalar var, condi, low, exp;
 exp:=mathML();
 lex();
 if char='(l o w l i m i t) then
  << low:=lowlimitRD();
     lex()>>
 else if char='(c o n d i t i o n) then 
     <<	condi:=conditionRD();
        if char neq '(!/ c o n d i t i o n) then 
	errorML("</condition>",2);
        lex()>>
      else condi:=nil;
 if char='(b v a r) then
  << var:=bvarRD();
     if (cadr var eq 1) then var:=car var
      else 
	 errorML("<degree>",8);
     lex()>>
 else var:=nil;
 if condi=nil then 
   return alg_limit(exp, var, low, 'norm);
 if low=nil then
   if car condi='(a b o v e) then 
        return alg_limit(exp, var, cadr condi, 'plus)
   else return alg_limit(exp, var, cadr condi, 'min);
end; 

algebraic procedure alg_limit(exp, var, tendto, type);
begin;
 if type='norm then return limit(exp, var, tendto);
 if type='plus then return limit!+(exp,var,tendto);
 if type='min then return limit!-(exp,var,tendto);
end;
 
%Returns the sum.
 
symbolic procedure sumRD();
begin scalar svar, low, upper, express, res;
 svar:=nil; low:=nil; upper:=nil; express:=nil; res:=nil;
 express:=mathML();
 lex();
 if char='(b v a r) then 
      <<svar:=bvarRD(); 
	if (cadr svar eq 1) then svar:=car svar
        else 
	 errorML("<degree>",7);
        lex()>>
 else errorML("<bvar>",9);
 if char='(l o w l i m i t) then
     << low:=lowlimitRD();
        lex();
  	if char='(u p l i m i t) then 
             <<	upper:=upperlimitRD();
        	lex()>>
	else errorML("<uplimit>",10) >>
 else if char='(i n t e r v a l) then
     <<	res:=intervalRD();
	lex();
	low:=car res;
	upper:=cadr res >>
      else errorML("<lowlimit> or <interval>",11);

 res:=1;
 if (low=reval low OR upper=reval upper) AND
     (IDP low OR IDP upper) then
  res:=cons('sum, cons(prepsq cadr express, cons(svar,append(list
reval low,list reval upper))))
 else
   res:=alg_sum(reval low, reval upper,express);
 return res;
end;

algebraic procedure alg_sum( low, upper, formu);
begin scalar temp,var2;
lisp print low;
lisp print upper;
lisp print formu;

 algebraic;
 temp:=0;
 var2:=symbolic svar;
 for tt:=low:upper do 
  << set(var2,tt);
     temp:=temp+formu;
     clear symbolic svar;
     var2:=symbolic svar>>;
 symbolic;    
 return temp;
end;

%Returns the product.

symbolic procedure productRD();
begin scalar pvar, low, upper, pexpress, res;
 pexpress:=mathML();
 lex();
 if char='(b v a r) then 
      <<pvar:=bvarRD(); 
	if (cadr pvar eq 1) then pvar:=car pvar
        else 
	 errorML("<degree>",12);
        lex()>>
 else errorML("<bvar>",9);
 if char='(l o w l i m i t) then
     << low:=lowlimitRD();
        lex();
  	if char='(u p l i m i t) then 
             <<	upper:=upperlimitRD();
        	lex()>>
	else errorML("<uplimit>",10)>>
 else if char='(i n t e r v a l) then
     <<	res:=intervalRD();
	lex();
	low:=car res;
	upper:=cadr res >>
      else errorML("<lowlimit> or <interval>",11);
 

 res:=1;
 if low=reval low OR upper=reval upper then
  res:='product . (prepsq cadr pexpress . 
	 (pvar . append(list reval low,list reval upper)))
 else
   res:=alg_prod(reval low, reval upper,pexpress,pvar);
 return res;
end;

algebraic procedure alg_prod( low, upper, formu,pvar);
begin scalar temp,var2;
 temp:=1;
 var2:=pvar;
 for tt:=low:upper do 
  << set(var2,tt);
     temp:=temp*formu;
     clear pvar;
     var2:=pvar>>;
 return temp;
end;

%Returns the partial derivative.

symbolic procedure partialdiffRD();
begin scalar res, bvar, express;
 express:=mathML();
 lex();
 bvar:=getargsRD();
 res:=differentiate(express, bvar);
 return res;
end;
 
symbolic procedure differentiate(express, bvar);
begin scalar temp,diffed;
return 
  if length bvar eq 0 then express 
   else
    <<temp:=car bvar;
      diffed:=alg_df(express, car temp, cadr temp);
      differentiate(diffed, cdr bvar)>>;
end;


%This function reads through the a series of <bvar> tags and extracts the
%variables.

symbolic procedure getargsRD();
begin scalar a;

%Dont forget. This function leaves the file pointer on 
%the next token after the last bvar. So you need to use mathML2 after.

if char='(b v a r) then 
<<a:=bvarRD();
  lex();
  return cons (a,getargsRD())>>;
end; 

%Returns the derivative.

symbolic procedure diffRD();
begin scalar bvar, degree, express, res;
 express:=mathML();
 lex();
 if char='(b v a r) then 
  <<bvar:=bvarRD(); 
    degree:=cadr bvar; 
    bvar:=car bvar; lex()>>
 else <<bvar:=nil; degree:=nil>>;
 res:=alg_df(express, bvar, degree);
 return res;
end;

algebraic procedure alg_df(a,b,c);
begin;
 return df(a,b,c);
end;

%This function will calculate the integral. Takes in the expression, then
%the bound variable, and finally the limits if they exist.

symbolic procedure intRD();
begin scalar bvar, low, upper, int, exp;
 exp:=mathML();
 lex();
 if char='(b v a r) then 
      <<bvar:=bvarRD(); 
	if (cadr bvar eq 1) then bvar:=car bvar
        else 
	 errorML("",13);
        lex()>>
   else errorML("<bvar>",14);
 if char='(l o w l i m i t) then <<low:=lowlimitRD(); lex()>>
   else low:=nil;
 if char='(u p l i m i t) then <<upper:=upperlimitRD(); lex()>>
   else upper:=nil;
 if char='(i n t e r v a l) then 
   <<int:=intervalRD(); 
     low:=car int;
     upper:=cadr int;
     lex()>>
   else int:=nil;
 return alg_int(exp, bvar, low, upper);
end;

algebraic procedure alg_int(exp, bvar, low, upper);
begin scalar res;
 if (low='nil) AND (upper=nil) then res:= int(exp, bvar)
  else res:= int(exp,bvar,low,upper);
return res;
end;

%Here we parse bound variables. The function reads the variable as well as
%the degree if there is one.

symbolic procedure bvarRD();
begin scalar var, deg;
 lex();
 if char='(d e g r e e) then 
     errorML("<bvar>",15);
 var:=mathML2();
 lex();
 if char='(d e g r e e) then 
   << deg:=mathML();
      lex();
      if char neq '(!/ d e g r e e) then 
	error("</degree>","Syntax ERROR: Missing end tag");
      lex()>>
 else deg:=1;
 if char='(!/ b v a r) then return list(var, deg)
   else errorML("</bvar>", 2);
end;

%Functions used to parse the limits of an integral, sum, or product.

symbolic procedure lowlimitRD();
begin scalar lowlimit;
 lowlimit:=mathML();
 lex();
 if char='(!/ l o w l i m i t) then return lowlimit
   else errorML("</lowlimit>", 2);
end;

symbolic procedure upperlimitRD();
begin scalar upperlimit;
 upperlimit:=mathML();
 lex();
 if char='(!/ u p l i m i t) then return upperlimit 
   else errorML("</uplimit>", 2);
end;

symbolic procedure intervalRD();
begin scalar l,u;
 l:=mathML();
 u:=mathML();
 lex();
 if char='(!/ i n t e r v a l) then return list(l,u) 
   else errorML("</interval>", 2);
end;

%Following functions just evaluate calculus functions. 

symbolic procedure lnRD();
begin scalar a;
 a:=alg_ln(mathML());
 lex();
 return a;
end;

algebraic procedure alg_ln(a);
begin;
  return ln(a);
end;

symbolic procedure logRD();
begin scalar a, a1, base;
 base:=nil;
 a1:=mathML();
 lex();
 if char='(l o g b a s e) then 
    <<base:=logbaseRD();
      a:=alg_log(a1,base);
      lex()>>
  else a:=alg_log(a1, base);
  return a;
end;

algebraic procedure alg_log(a, base);
begin;
 if base=nil then return log(a)
 else
  return logb(a, base);
end;

symbolic procedure logbaseRD();
begin scalar a;
 a:=mathML();
 lex();
 if char='(!/ l o g b a s e) then return a
   else errorML("</logbase>",2);
end;


symbolic procedure conjugateRD();
begin scalar a;
  a:= alg_conj(mathML());
  lex();
  return a;
end;

algebraic procedure alg_conj(a);
  conj(a);

symbolic procedure minusRD();
begin scalar c,b;
  c:=mathML();
  b:=mathML();
  if b=nil then c:=alg_minus(c)
   else <<
	c:=alg_difference(c,b); 
	lex()>>;
  return c;
end;

algebraic procedure alg_minus(a);
  -a;

algebraic procedure alg_difference(a,b);
  difference(a-b);

symbolic procedure absRD();
begin scalar a;
  a:=alg_abs(mathML());
  lex();
  return a;
end;

algebraic procedure alg_abs(a);
  abs(a);

symbolic procedure rootRD();
begin scalar b,c;
  b:=mathML();
  lex();
  if char neq '(!/ a p p l y) then  
   << c:=mathML2();
      lex()>>
  else c:=2;
  return alg_root(b,c);
end;

algebraic procedure alg_root(b,a);
 b**(1/a);

symbolic procedure remRD();
begin scalar a, a1, a2;
  a1:=mathml();
  a2:=mathml();
  a:=alg_remainder(a1, a2);
  lex();
  return a;
end;

algebraic procedure alg_remainder(a,b);
begin;
  return remainder(a,b);
end;

symbolic procedure factorialRD();
begin scalar a;
  a:=alg_factorial(mathML());
  lex();
  return a;
end;  

algebraic procedure alg_factorial(a);
   factorial(a);

symbolic procedure expRD();
begin scalar a;
  a:= alg_exp(mathML());
  lex();
  return a;
end;

algebraic procedure alg_exp(a);
   exp(a);

symbolic procedure quotientRD();
begin scalar a, a1, a2;
  a1:=mathML();
  a2:=mathML();
  if IDP reval a1 OR IDP reval a2 then a:=alg_quotient(a1,a2)
  else
  a:= (reval a1)/(reval a2);
  lex();
  return a;
end;

algebraic procedure alg_quotient(a,b);
  a/b;

symbolic procedure divideRD();
begin scalar a, a1, a2;
  a1:=mathML();
  a2:=mathML();
  a:=alg_divide(a1,a2);
  lex();
  return a;
end;

algebraic procedure alg_divide(a,b);
   quotient(a,b);

symbolic procedure gcdRD();
begin scalar c1;
 c1:=stats_getargs();
 constants(c1);
 if temp2='stop then 
   << temp2:=nil;
      return cons('gcd, eval_list(c1))>>
 else return gcdRD2(c1);
end;

symbolic procedure gcdRD2(args);
begin scalar a;
a:=reval car args;
return if length args=1 then  car args
	else alg_gcd2(a, gcdRD2(cdr args));
end;

algebraic procedure alg_gcd2(a , b);
 gcd(a,b);

symbolic procedure minRD();
begin scalar a;
a:=mathML();
return if a=nil then nil
         else alg_min(a,minRD());
end;

algebraic procedure alg_min(a,b);
 min(b,a);

symbolic procedure maxRD();
begin scalar a;
a:=mathML();
return if a=nil then nil
         else alg_max(a,maxRD());
end;

algebraic procedure alg_max(a,b);
  max(a,b);
    
lisp operator plusRD;

symbolic procedure plusRD();
begin scalar abc1;
abc1:=mathML();
return if abc1 = nil then 0 else alg_plus(abc1, plusRD());
end;

algebraic procedure alg_plus(acb1,b);
 acb1+b;

symbolic procedure timesRD();
begin scalar a;
a:=mathML();
return if a=nil then 1 else alg_times(a, timesRD());
end;

algebraic procedure alg_times(a,b);
if b=i then a*i else a*b;

symbolic procedure powerRD();
begin scalar var,power;
 var:=mathML();
 power:=mathML(); 
 lex();
 return alg_expt(var,power);
end;

algebraic procedure alg_expt(a,b);
 expt(a,b);

%The following function is in charge of providing the correct error message
%as well as closing the input/output stream, and exiting the program
%correctly. 
   
symbolic procedure errorML( str, msg );
begin;
 princ "***** Error in token number ";
 princ count;
 princ " (<";
 princ crunch char;
 princ ">)";
 terpri();
 if msg=1 then 
  << princ "Needed attribute";
     princ str;
     princ " and none was found.">> else
 if msg=2 then 
  << princ "Missing tag: "; princ str >> else
 if msg=3 then 
  << princ "Undefined error!";
     princ " Token number "; princ sub1 count;
     princ " probably mispelled or an";
     princ "ambiguous or erroneous use of <apply></apply>.">> else
 if msg=4 then 
  << princ "Numerical constant "; princ str;
     princ " was enclosed between <ci></ci> tags.";
     terpri();
     princ "Correct syntax: <cn>"; princ str;
     princ "</cn>.">> else
 if msg=5 then 
  << princ "All arguments must be sets";
     terpri();
     princ str;
     princ " does not represent a set.">> else
 if msg=6 then 
  << princ "Non-numeric argument in arithmetic.">> else
 if msg=7 then 
  << princ "The degree quantifier is of no use in the sumation";
     princ "operator.">> else
 if msg=8 then 
  << princ "The degree quantifier is of no use in the limit";
     princ " operator.">> else
 if msg=9 then 
  << princ "The index of sumation has not been specified.";
     terpri();
     princ "Please use <bvar></bvar> tags to specify an index.">>
 else
 if msg=10 then 
  << princ "Upperlimit not specified.">> else
 if msg=11 then 
  << princ "Upper and lower limits have not been specified.">> else
 if msg=12 then 
  << princ "The degree quantifier is of no use in the product";
     princ " operator.">> else
 if msg=13 then 
  << princ "The degree quantifier is not allowed in the integral";
     princ " operator.">> else
 if msg=14 then
  << princ "Variable of integration not specified.";
     princ "Please use <bvar></bvar> tags to specify variable.">>
 else
 if msg=15 then 
  << princ "Incorrect use of <bvar></bvar> tags.";
     princ "Correct use:"; terpri(); 
     princ
"<bvar>bound_var</bvar>[<degree>degree</degree>]</bvar>">> else
 if msg=16 then
  << princ "Symbolic constant "; princ str;
     princ " was enclosed between <cn></cn> tags.";
     terpri();
     princ "Correct syntax: <ci>"; princ str; princ "</ci>">> else
 if msg=17 then 
  << princ "Unknown tag: <";
     princ str;princ ">.";
     terpri();
     princ "Token not allowed within <apply></apply> tags.";  
     terpri();
     princ "Might be: <"; princ str; princ "/>.">> else
 if msg=18 then 
  << princ "Unknown tag: <";
     princ str;princ ">.";
     terpri();
     princ "Not allowed within <relation></relation> tags.">> else
 if msg=19 then 
  << princ "Undefined error!";
     princ " Token "; princ sub1 count;
     princ " is probably mispelled";
     terpri();
     princ "or unknown, ";
     princ "or the </math> tag is missing">> else
 if msg=20 then
  << princ "Function ";
     princ str;
     princ "()";
     princ " was not enclosed in <ci></ci> tags.";
     terpri();
     princ "Correct syntax: <fn><ci>";
     princ str;
     princ "</ci></fn>.">>;  
  
 terpri();
 if FILE!* then << rds in!*; close file!*>>;
 FILE!*:=nil;
 error("", "");
 terpri();
end;

%Following function are in charge of parsing statistics related mathml.

symbolic procedure meanRD();
begin scalar b, size, args;
 args:=stats_getargs();
 b:=0;
 size:=length( args );
    while (args neq ()) do
	<< b:=alg_plus(b, car args);
	   args:= cdr args >>;
 return alg_quotient(b,size);
end;

symbolic procedure sdevRD(  );
begin scalar mean, b, size, args;
 args:=stats_getargs();
 mean:=alg_mean( args );
 size:=length(args);
 while(args neq ()) do
   << b:=alg_plus(b, alg_expt(alg_difference(car args, mean),2));
      args:=cdr args; >>;
 return b;
end;

symbolic procedure varRD( );
begin scalar args;
 args:=stats_getargs();
 return alg_expt(sdev( args ), 2);
end;

symbolic procedure medianRD( );
begin scalar siz, si, args;
 args:=stats_getargs();
 args:=cons('list, args);
 args:=sortl(args);
 args:=cdr args;
 si:=length args;
 siz:=si/2;
 if remainder(si,2)=0 then 
return alg_quotient(alg_plus(nth(args,siz),nth(args,(siz+1))),2)
 else return nth(args, siz);
end;

algebraic procedure sortl(args);
begin scalar rr;
 rr:=sortlist(args, pred);
 if rr=nil then return sortnumlist(args)
 else return rr;
end;

symbolic procedure momentRD( );
begin scalar size, d,i, args;
 args:=stats_getargs();
if char='(d e g r e e) then 
 <<i:=mathML();
   lex();
   if char='(!/ d e g r e e) then lex()
   else errorML("</degree>",2)>>
else i:=1;
 d:=();
 size:=length args;
 while args neq () do 
  << d:=alg_expt(car args, i) . d;
     args:=cdr args>>;
 return alg_mean(d);
end;

symbolic procedure alg_mean ( args );
begin scalar b, size, args;
 b:=0;
 size:=length( args );
    while (args neq ()) do
	<< b:=alg_plus(b, car args);
	   args:= cdr args >>;
 return alg_quotient(b,size);
end;

symbolic procedure sdev( args );
begin scalar mean, b , size;
 mean:=alg_mean( args );
 size:=length(args);
 while(args neq ()) do
   << b:=alg_plus(b, alg_expt(alg_difference(car args, mean),2));
      args:=cdr args; >>;
 return b;
end;

%The following function gets all arguments of a particular function from
%the mathml input.

symbolic procedure stats_getargs();
begin scalar ww;
  ww:=nil;
  ww:=mathML();
  if ww neq nil then <<
  return cons (ww,stats_getargs())>>;
end; 

%Transforms polar-complex to cartesian-complex.

symbolic procedure po2ca(p);
begin scalar r,theta,x,y;
      r:=car p;
      theta:=rad(cadr p);
      x:=r*cos(theta);
      y:=r*sin(theta);
      return(list(x,y))
end;

symbolic procedure rad(mu);        %note approx. pi
      mu*3.141529/180;

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%Here start the functions in charge of parsing reduce's output and printing%
%it out in mathml.			  				   %
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

%This the mathml printer which reads reduce output and translates it to
%mathml.

FLUID '(indent flag,found_int found_compl consts_compl consts_int);
FLUID '(found_mat_int found_mat_compl consts_mat_int consts_mat_compl);

symbolic procedure math_ml_printer (mode,u);
<< 
if !*both=t then 
(<< maprin(u); terpri!* nil>>) where outputhandler!* := nil;
if mode neq 'terpri then
  << found_mat_int=0$;
     found_mat_compl=0$;
     indent:=0$
     consts_compl:=()$
     consts_mat_compl:=()$
     consts_int:=()$
     consts_mat_int:=()$
     found_int:=0$
     found_compl:=0$
     flag:=0$
     if (PAIRP u) then <<
        printout("<math>");
 	indent:=3;

        if ((car u)='setq) then 
          <<if (PAIRP caddr u) then 
	      if (issq(caddr u)=1) then arbitrary_c( PREPSQ cadr caddr u ) 
		 else
	            if (caaddr u='mat) then arbitrary_c(caddr u) 
		    else  
	              if (caaddr u='list) then arbitrary_c( !*a2k caddr u);
	     setqML( u )>>
	else 
           if ((car u)='list) then 
	     << arbitrary_c( !*a2k u );    
	  	listML(cdr u)>>
	   else 
    	      if ((car u)='mat) then 
	        << arbitrary_c( u );
	  	   matrixML(cdr u)>>
	      else
    	         if ((car u)='!*sq) then 
  	 	   << arbitrary_c(PREPSQ (cadr u));
         	      expression(PREPSQ (cadr u))>>
	         else expression(u); 

             indent:=indent-3;
	     close_forall();
	     indent:=0;
	     printout( "</math>" );
             terpri() 
	>> 
     else 
	if (ATOM u) then << 
           printout( "<math>" ); indent:=3; expression( u );
	   indent:=0; printout( "</math>" ); terpri() >>
  else ; >> >>;
      
%Prints out vectors.

symbolic procedure vectorML( elem );
<< printout("<vector>"); indent:=indent+3;
   multi_elem(car elem); indent:=indent-3;
   printout("</vector>")
>>;

%Following functions print out matrices.

symbolic procedure matrixML( elem );
  if length elem=1 then vectorML( elem )
  else 
  << printout("<matrix>"); indent:=indent+3;
     matrix_rows(elem); indent:=indent-3;
     printout("</matrix>")
  >>;

symbolic procedure matrix_rows( elem );
  if (elem neq()) then 
     <<	printout("<matrixrow>"); indent:=indent+3;
	row(car elem); 	indent:=indent-3;
	printout("</matrixrow>");           
	matrix_rows( cdr elem ) >>;

symbolic procedure row( elem );
  if (elem neq()) then << expression(car elem); row(cdr elem)>>;

%This function searches for arbitrary integers, or complex in the reduce
%output. If so, it declares these variables in a forall statement.

symbolic procedure arbitrary_c( elem );
begin;
found_int:=nil;
found_mat_int:=nil;
found_compl:=nil;
found_mat_compl:=nil;

if (PAIRP elem) then <<
   if (car elem='mat) then 
     << isarb_mat_compl(cdr elem);
	isarb_mat_int(cdr elem)>>
   else  
     <<	isarb_compl(elem); isarb_int(elem)>>;

  if ((found_compl=1) OR (found_int=1)) then 
   << flag:=1;
      printout( "<apply><forall/>" );
      indent:=indent+3;
      print_arb_compl(elem);
      print_arb_int(elem);
      printout( "<condition>");
      indent:=indent+3;
      if ((found_compl=1) AND (found_int=1)) then 
        << printout( "<apply><and/>" ); 
           indent:=indent+3>>
      else 
        if ((length consts_compl) > 1) then 
          <<  printout( "<apply><and/>" ); indent:=indent+3>> 
        else
           if ((length consts_int) > 1) then 
             << printout( "<apply><and/>" ); indent:=indent+3>>;

      if (found_compl=1) then in_complexML( consts_compl );
      if (found_int=1) then in_integerML( consts_int );

      if ((found_compl=1) AND (found_int=1)) then 
         << indent:=indent-3; printout( "</apply>" )>>
      else 
          if ((length consts_compl) > 1) then 
            << indent:=indent-3; printout( "</apply>" )>> 
          else
              if ((length consts_int) > 1) then 
                << indent:=indent-3; printout( "</apply>" )>>;

      indent:=indent-3;
      printout( "</condition>" )>>;

  if ((found_mat_compl=1) OR (found_mat_int=1)) then 
    << flag:=1;
       printout( "<apply><forall/>" );
       indent:=indent+3;
       printarb_mat_compl(cdr elem);
       printarb_mat_int(cdr elem);
       printout( "<condition>");
       indent:=indent+3;

       if ((found_mat_compl=1) AND (found_mat_int=1)) then 
         << printout( "<apply><and/>" ); 
           indent:=indent+3>>
       else 
          if ((length consts_mat_compl) > 1) then 
            << printout( "<apply><and/>" ); 
               indent:=indent+3>> 
          else
             if ((length consts_mat_int) > 1) then 
               << printout( "<apply><and/>" ); 
                  indent:=indent+3>>;

       if (found_mat_compl=1) then 
          in_complexML( consts_mat_compl );
       if (found_mat_int=1) then 
          in_integerML( consts_mat_int );

       if ((found_mat_compl=1) AND (found_mat_int=1)) then 
         << indent:=indent-3;
            printout( "</apply>" )>>
       else 
     	  if ((length consts_mat_compl) > 1) then 
            << indent:=indent-3;
               printout( "</apply>" )>> 
          else
     	    if ((length consts_mat_int) > 1) then 
              << indent:=indent-3;
                 printout( "</apply>" )>>;

     indent:=indent-3;
     printout( "</condition>" )>>; 
  >>
end;

symbolic procedure in_complexML( elem );
begin;
  if (elem neq ()) then <<
    printout("<reln><in/>");
    indent:=indent+3;
    printsub2( car elem, 'compl );
    printout("<ci type= set> C </ci>");
    indent:=indent-3;
    printout("</reln>");   
    in_complexML( cdr elem )>>;	
end;

symbolic procedure in_integerML( elem );
begin;
  if (elem neq ()) then <<
    printout("<reln><in/>");
    indent:=indent+3;
    printsub2( car elem, 'int );
    printout("<ci type= set> N </ci>");
    indent:=indent-3;
    printout("</reln>");   
    in_integerML( cdr elem )>>;	
end;

symbolic procedure close_forall();
begin;
  if (flag=1) then printout("</apply>");
end;

%Prints out setq statements as <declare> statements.

symbolic procedure setqML( elem );
<< printout( "<declare>" ); indent:=indent+3;
  expression(cadr elem); expression( caddr elem ); indent:=indent-3;
  printout( "</declare>" );
>>;

%Prints out lists.

symbolic procedure listML( elem );
<< printout( "<list>" );  indent:=indent+3;
  multilists( elem ); indent:=indent-3;
  printout( "</list>" )
>>;

symbolic procedure multilists( elem );
 if elem then 
  if ((LENGTH elem)=1) then expression (car elem)
    else <<expression(car elem); multilists(cdr elem)>>;  

%This function takes in a reduce expression, and parses it. It also takes
%expressions created by the above program.

symbolic procedure expression( elem );
begin;
if (ATOM elem) then f4( elem ) else
if car elem='!:RD!: then <<printout elem>> else
 <<
  if ((car elem)= 'determinant) then unary(cdr elem, 'determinant) else
  if ((car elem)= 'transpose) then unary(cdr elem, 'transpose) else
  if ((car elem)= 'sum) then sum_prodML(cdr elem, 'sum) else
  if ((car elem)= 'product) then sum_prodML(cdr elem, 'product) else
  if ((car elem)= 'df) then dfML(cdr elem) else
  if ((car elem)= 'impart) then complpart(cdr elem, 'impart) else
  if ((car elem)= 'repart) then complpart(cdr elem, 'repart) else
  if ((car elem)= 'abs) then unary(cdr elem, 'abs) else
  if ((car elem)= 'gcd) then n_nary(cdr elem, 'gcd) else
  if ((car elem)= 'set) then setML(cdr elem) else 
  if ((car elem)= '!*sq)  then expression (PREPSQ (cadr elem)) else 
  if ((car elem)= 'factorial) then unary(cdr elem, 'factorial) else
  if ((car elem)= 'max)   then n_nary(cdr elem, 'max) else
  if ((car elem)= 'min)   then n_nary(cdr elem, 'min) else
  if ((car elem)= 'cos)   then unary(cdr elem, 'cos) else
  if ((car elem)= 'sin)   then unary(cdr elem, 'sin) else
  if ((car elem)= 'sec)   then unary(cdr elem, 'sec) else
  if ((car elem)= 'cosh)  then unary(cdr elem, 'cosh) else
  if ((car elem)= 'cot)   then unary(cdr elem, 'cot) else
  if ((car elem)= 'coth)  then unary(cdr elem, 'coth) else
  if ((car elem)= 'csch)  then unary(cdr elem, 'csch) else
  if ((car elem)= 'acos)  then trigML(cdr elem, 'acos) else
  if ((car elem)= 'asin)  then trigML(cdr elem, 'asin) else
  if ((car elem)= 'atan)  then trigML(cdr elem, 'atan) else
  if ((car elem)= 'sech)  then unary(cdr elem, 'sech) else
  if ((car elem)= 'sinh)  then unary(cdr elem, 'sinh) else
  if ((car elem)= 'tan)   then unary(cdr elem, 'tan) else
  if ((car elem)= 'tanh)  then unary(cdr elem, 'tanh) else
  if ((car elem)= 'csc)   then unary(cdr elem, 'csc) else
  if ((car elem)= 'mat)   then matrixML(cdr elem) else
  if ((car elem)= 'quotient) then quotientML(cdr elem) else
  if ((car elem)= 'plus)  then n_nary(cdr elem, car elem) else
  if ((car elem)= 'times) then n_nary(cdr elem, car elem) else
  if ((car elem)= 'expt)  then n_nary(cdr elem, 'power) else
  if ((car elem)= 'minus) then minusML(cdr elem) else
  if ((car elem)= 'int)   then integralML(cdr elem) else
  if ((car elem)= 'sqrt)  then sqrtML(cdr elem) else
  if ((car elem)= 'equal) then equalML(cdr elem) else
  if ((car elem)= 'list)  then listML(cdr elem) else
  if ((car elem)= 'arbcomplex) then printsub2(cadr elem, 'compl) else
  if ((car elem)= 'arbint) then printsub2(cadr elem, 'int) else
  if ((car elem)= 'log)   then unary(cdr elem, 'log) else
  if ((car elem)= 'logb)  then log_baseML(cdr elem, 'logb) else
  if ((car elem)= 'log10) then log_baseML(cdr elem, 'log10) else
  if ((car elem)= 'ln)    then unary(cdr elem, 'ln) else 
  if ((car elem)= 'eq)    then reln(cdr elem, 'eq) else 
  if ((car elem)= 'neq)    then reln(cdr elem, 'neq) else 
  if ((car elem)= 'gt)    then reln(cdr elem, 'gt) else 
  if ((car elem)= 'lt)    then reln(cdr elem, 'lt) else 
  if ((car elem)= 'geq)    then reln(cdr elem, 'geq) else 
  if ((car elem)= 'leq)    then reln(cdr elem, 'leq) else 
  if ((car elem)= 'union)    then sets(cdr elem, 'union) else 
  if ((car elem)= 'intersection) then sets(cdr elem, 'intersection) else 
  if ((car elem)= 'in) then reln(cdr elem, 'in) else
  if ((car elem)= 'notin) then reln(cdr elem, 'notin) else
  if ((car elem)= 'subset) then reln(cdr elem, 'subset) else
  if ((car elem)= 'prsubset) then reln(cdr elem, 'prsubset) else
  if ((car elem)= 'notsubset) then reln(cdr elem, 'notsubset) else
  if ((car elem)= 'notprsubset) then reln(cdr elem, 'notprsubset) else
  if ((car elem)= 'setdiff) then sets(cdr elem, 'setdiff) else
  operator_fn(elem);>>;
end;

%Prints out sum, or products.

symbolic procedure sum_prodML( elem, tty );
begin;
 printout("<apply>"); princ "<";princ tty; princ "/>";
 indent:=indent+3; expression car elem; printout("<bvar>");
 indent:=indent+3; expression( cadr elem );
 indent:=indent-3; printout("</bvar>"); printout("<lowlimit>");
 indent:=indent+3; expression( caddr elem );
 indent:=indent-3; printout("</lowlimit>"); printout("<uplimit>");
 indent:=indent+3; expression( cadddr elem );
 indent:=indent-3; printout("</uplimit>");
 indent:=indent-3; printout("</apply>");
end;  

%Prints out derivatives.

symbolic procedure dfml( elem );
begin scalar test;
 test:=cdr elem;
 if length test=1 OR (length test=2 AND NUMBERP cadr test) then
    printout("<apply><diff/>")
 else  
    printout("<apply><partialdiff/>");
 indent:=indent+3;
 expression(car elem);
 dfargs(cdr elem);
 indent:=indent-3;
 printout("</apply>"); 
end;

symbolic procedure dfargs( elem );
begin; 
 if elem neq nil then 
   << if length elem>1 then 
      <<  if NUMBERP cadr elem then 
          <<printout("<bvar>"); indent:=indent+3; expression car elem;
            degreeML(cadr elem); indent:=indent-3; printout("</bvar>");
            dfargs(cddr elem)>>
          else 
          <<printout("<bvar>"); indent:=indent+3; expression car elem;
	    indent:=indent-3; printout("</bvar>"); dfargs(cdr elem)>>; >>
      else 
        << printout("<bvar>"); indent:=indent+3; expression car elem;
 	   indent:=indent-3; printout("</bvar>"); dfargs(cdr elem)>> >>;
end;

%Prints out degree statements.

symbolic procedure degreeML( elem );
begin;
 printout("<degree>");
 indent:=indent+3;
 expression( elem );
 indent:=indent-3;
 printout("</degree>");
end;

symbolic procedure complpart( elem, tty);
begin;
 printout("<apply><fn><");
 princ tty;
 princ "></fn>";
 indent:=indent+3;
 expression(car elem);
 indent:=indent-3;
 printout("<apply>");
end; 

%Prints out set theory related functions.

symbolic procedure sets(elem, tty);
begin;
 printout("<apply>");
 princ "<"; princ tty; princ "/>"; 
 indent:=indent+3;
 multi_elem( elem );
 indent:=indent-3;
 printout("</apply>");
end; 

%Prints out relations.

symbolic procedure reln(elem, tty);
begin;
 printout("<relation>");
 princ "<"; princ tty; princ "/>"; 
 indent:=indent+3;
 multi_elem( elem );
 indent:=indent-3;
 printout("</relation>");
end; 

%Prints out a set.

symbolic procedure setML( elem );
begin;
  printout("<set>");
  indent:=indent+3;
  multi_elem( elem );
  indent:=indent-3;
  printout("</set>");
end;

%Prints out unknown functions as a function. It prints out all variables
%declared a soperators.

symbolic procedure operator_fn( elem );
begin;
  printout("<apply><fn><ci>");
  princ car elem;
  princ "</ci></fn>";
  indent:=indent+3;
  multi_args(cdr elem);
  indent:=indent-3;
  printout("</apply>");
end;

%Reads through a list and prints out each component. 

symbolic procedure multi_args( elem );
begin;
  if  (elem neq ()) then <<expression(car elem); multi_args( cdr elem );>> 
end;

%Prints out all trigonometric functions which have not the same tag name,
%as reduce function.

symbolic procedure trigML(elem, type);
begin;
  printout("<apply>");
  if ((type='acos) OR (type='asin) OR (type='atan)) then 
    << if (type='acos) then princ "<arccos/>";
       if (type='asin) then princ "<arcsin/>"; 
       if (type='atan) then princ "<arctan/>">>;
  indent:=indent+3;
  expression(car elem);
  indent:=indent-3;
  printout("</apply>");
end;

%Prints out all unary functions such as log, or many trig functions.

symbolic procedure unary( elem, type );
begin;
  printout("<apply>");
  princ "<";
  princ type;
  princ "/>";
  indent:=indent+3;
  expression(car elem );
  indent:=indent-3;
  printout("</apply>");
end;

%Prints out logs with a base.

symbolic procedure log_baseML(elem, type);
begin;
  printout("<apply><log/>");
  indent:=indent+3;
  printout("<logbase>");
  indent:=indent+3;
  if (type='logb) then expression(cadr elem);
  if (type='log10) then f4(10);
  indent:=indent-3;
  printout("</logbase>");
  expression(car elem);
  indent:=indent-3;
  printout("<apply>");
end; 

%Prints out equal relations.

symbolic procedure equalML( elem );
begin;
  printout( "<relation><eq/>" );
  indent:=indent+3;
  expression(car elem);
  expression(cadr elem);
  indent:=indent-3;
  printout( "</relation>" );
end;

%Prints out square roots.

symbolic procedure sqrtML( elem );
begin;
  printout( "<apply><root>" );
  indent:=indent+3;
  expression( car elem );
  printout( "<cn> 2 </cn>" );
  indent:=indent-3;
  printout( "</apply>" );
end;

%Prints out integrals.

symbolic procedure integralML( elem );
begin;
  printout( "<apply><int>" );
  indent:=indent+3;
  printout( "<bvar>" );
  indent:=indent+3;
  expression (cadr elem);
  indent:=indent-3;
  printout( "</bvar>" );
  if (length cdr elem >1) then 
     << printout("<lowlimit>");
        indent:=indent+3;
     	expression( caddr elem );
   	indent:=indent-3;
     	printout("</lowlimit>");
     	printout("<uplimit>");
     	indent:=indent+3;
     	expression( cadddr elem );
     	indent:=indent-3;
     	printout("</uplimit>")>>;
  expression( car elem );
  indent:=indent-3;
  printout( "</apply>" );
end;

%Prints out quotients.

symbolic procedure quotientML( elem );
begin;
  if (NUMBERP car elem) AND (NUMBERP cadr elem) then <<
     printout("<cn type=""rational""> ");
     princ car elem;
     princ " <sep/> ";
     princ cadr elem;
     princ " </cn>">> 
  else <<     
     printout( "<apply><divide>" );
     indent:=indent+3;
     expression( car elem );
     expression( cadr elem );
     indent:=indent-3;
     printout( "</apply>" )>>;
end;

%Prints out all n_nary functions.

symbolic procedure n_nary( elem, type );
begin;
  printout( "<apply>" );
  princ "<";
  princ type;
  princ "/>";
  indent:=indent+3;
  multi_elem( elem );
  indent:=indent-3;
  printout( "</apply>" );
end;

symbolic procedure multi_elem( elem );
begin;
   if ((length elem)=1) then expression( car elem )
       else <<expression( car elem ); multi_elem( cdr elem );>>
end;

symbolic procedure minusML( elem );
begin;
  printout( "<apply><minus/>" );
  indent:=indent+3;
  multiminus( elem );
  indent:=indent-3;
  printout( "</apply>" );
end;  

symbolic procedure multiminus( elem );
begin;
  expression(car elem);
  if ((length elem)=2) then expression (cadr elem);
end;

%Prints out all pieces of data: i.e terminal symbols.
%They can be numbers, identifiers, or constants.

symbolic procedure f4(exp);
begin;
if (exp='e) then 
  << printout("<ci type=""constant"">"); 
     princ "&ExponentialE;"; 
     princ "</ci>">>
else << 
   if (exp='i) then 
    << printout("<ci type=""constant"">"); 
       princ "&ImaginaryI;"; 
       princ "</ci>">>
   else <<
      if (NUMBERP exp) then 
		      << printout "<cn";
      		         if (FLOATP exp) then princ " type=""real"">" 
 			   else
		              if (FIXP exp) then princ " type=""integer"">" 
				else princ ">";
                         princ exp;
                         princ "</cn>">>;
         if (IDP exp) then  
		     <<  printout "<ci";
		         if (listp exp) then princ " type=""list"">" 
			   else
		              if (vectorp exp) then princ " type=""vector"">" 
				else princ ">";
                         princ exp;
                         princ "</ci>">>; 
         >> 
      >>
end;

%Functions used to print out variables with a subscript.

symbolic procedure printsub( subscript, type );
begin;
  printout("<bvar>");
  indent:=indent+3;
  printout("<ci>");
  indent:=indent+3;
  printout( "<msub>" );
  indent:=indent+3;
  if (type='compl) then printout( "<mi>c</mi>" );
  if (type='int) then printout( "<mi>d</mi>" );
  printout( "<mn>" );
  princ subscript;
  princ "</mn>"; 
  indent:=indent-3;
  printout( "</msub>" );
  indent:=indent-3;
  printout("</ci>");
  indent:=indent-3;
  printout("</bvar>");
end;

symbolic procedure printsub2( subscript, type );
begin;
  printout("<ci>");
  indent:=indent+3;
  printout( "<msub>" );
  indent:=indent+3;
  if (type='compl) then  printout( "<mi>c</mi>" );
  if (type='int) then  printout( "<mi>d</mi>" );
  printout( "<mn>" );
  princ subscript;
  princ "</mn>"; 
  indent:=indent-3;
  printout( "</msub>" );
  indent:=indent-3;
  printout("</ci>");
end;

%Prints out expressions in math form. Plagiarised from reduce code of
%mathprint

symbolic procedure ma_print l;
begin scalar temp;
   temp:=outputhandler!*;
   outputhandler!*:=nil;
   terpri!* nil;
   maprin "<cn type=""real"">";
   maprin l;
   maprin "</cn>";
   terpri!* nil;
   outputhandler!*:=temp;
end;

%Function in charge of doing all printing in order to make sure the
%indentation is always correct.

symbolic procedure printout( str );
begin;
   terpri();
   for i := 1:indent
      do << princ " " >>;
   if PAIRP str then
    <<if car str='!:rd!: OR car str='!:rn!: then ma_print str     
    else princ str>>
   else princ str;
end;

%Following functions are quite obscure. They find arbitrary constants in
%expressions and matrices. Then record them, and everytime they appear, are
%replaced with a fancy subscripts C, or D.

symbolic procedure issq( elem );
begin scalar value;
 value:=0;
        if (ATOM elem) then value:=0
	   else <<if ((car elem)='!*sq) then value:=1
                  else value:=0>>; 
  return value;
end;

symbolic procedure isarb_compl( elem );
begin;
if (PAIRP elem) then <<
  if ((car elem)= 'arbcomplex) then found_compl:=1
     else  multi_isarb_compl(cdr elem);>> 
end;

symbolic procedure multi_isarb_compl( elem );
begin;
if (PAIRP elem) then <<
   if (elem=()) then 
      else <<isarb_compl(car elem); multi_isarb_compl( cdr elem);>> >>
end;

symbolic procedure isarb_int( elem );
begin;
if (PAIRP elem) then <<
  if ((car elem)= 'arbint) then found_int:=1
     else  multi_isarb_int(cdr elem);>> 
end;

symbolic procedure multi_isarb_int( elem );
begin;
if (PAIRP elem) then <<
   if (elem=()) then 
      else <<isarb_int(car elem); multi_isarb_int( cdr elem);>> >>
end;

symbolic procedure print_arb_compl( elem );
begin;
if (PAIRP elem) then <<
  if ((car elem)= 'arbcomplex) then 
     << if (xnp(list (cadr elem),consts_compl) eq nil) then 
	  << printsub(cadr elem, 'compl); 
	     consts_compl:=cons(cadr elem, consts_compl)>> >>
  else  multi_compl(cdr elem);>>
end;

symbolic procedure multi_compl( elem );
begin;
   if (elem=()) then 
      else <<print_arb_compl(car elem); multi_compl( cdr elem);>>
end;


symbolic procedure print_arb_int( elem );
begin;
if (PAIRP elem) then <<
  if ((car elem)= 'arbint) then 
     << if (xnp(list (cadr elem),consts_int) eq nil) then 
	  << printsub(cadr elem, 'int); 
	     consts_int:=cons(cadr elem, consts_int)>> >>
  else  multi_int(cdr elem);>>
end;

symbolic procedure multi_int( elem );
begin;
   if (elem=()) then 
      else <<print_arb_int(car elem); multi_int( cdr elem);>>
end;

symbolic procedure isarb_mat_int( elem );
begin;
  if (elem neq()) then  
    << isarb_row_int(car elem); 	
       isarb_mat_int( cdr elem ); >>
end;

symbolic procedure isarb_row_int( elem );
begin;
  if (elem neq()) then 
 	<< if (issq(car elem)=1) then 
		if (PAIRP (PREPSQ cadr (car elem))) then
		   if (car (PREPSQ cadr (car elem))='arbint) then  
 			found_mat_int:=1;
	   isarb_row_int(cdr elem);>>
end;


symbolic procedure isarb_mat_compl( elem );
begin;
  if (elem neq()) then 
	<< 
	isarb_row_compl(car elem); 	
	isarb_mat_compl( cdr elem ); >>
end;

symbolic procedure isarb_row_compl( elem );
begin;
  if (elem neq()) then 
 	<< if (issq(car elem)=1) then
		if (PAIRP (PREPSQ cadr (car elem))) then
		   if (car (PREPSQ cadr (car elem))='arbcomplex) then  
 			found_mat_compl:=1; 
	   isarb_row_compl(cdr elem);>>
end;

symbolic procedure printarb_mat_compl( elem );
begin;
  if (elem neq()) then 
    << printarb_row_compl(car elem); 	
       printarb_mat_compl( cdr elem ); >>
end;

symbolic procedure printarb_row_compl( elem );
begin scalar value;
  if (elem neq()) then 
 	<< if (issq(car elem)=1) then 
	      if (PAIRP (PREPSQ cadr (car elem))) then 
	        << value:=cadr PREPSQ cadr car elem;
       	           if (car (PREPSQ cadr (car elem)))='arbcomplex then 
 	              if (xnp(list (value), consts_mat_compl) eq nil) then
		        << printsub(value, 'compl);
 		           consts_mat_compl:=cons(value, consts_mat_compl)>> >>; 
	   printarb_row_compl(cdr elem);>>
end;


symbolic procedure printarb_mat_int( elem );
begin;
  if (elem neq()) then 
	<< 
	printarb_row_int(car elem); 	
	printarb_mat_int( cdr elem ); >>
end;

symbolic procedure printarb_row_int( elem );
begin scalar value;
  if (elem neq()) then 
 	<< if (issq(car elem)=1) then 
	      if (PAIRP (PREPSQ cadr (car elem))) then 
 	        << value:=cadr PREPSQ cadr car elem;
       	           if (car (PREPSQ cadr (car elem)))='arbint then 
 	              if (xnp(list (value), consts_mat_int) eq nil) then
		        << printsub(value, 'int);
 		           consts_mat_int:=cons(value, consts_mat_int)>> >>; 
	   printarb_row_int(cdr elem);>>
end;

%Following function is the same as math_ml_printer, just that it prints out
%input given from mml, which reads from files, and not form the reduce
%normal output stream.
 
FLUID '(indent flag found_int found_compl consts_compl consts_int mathprint);
FLUID '(found_mat_int found_mat_compl consts_mat_int consts_mat_compl);

symbolic procedure math_ml (u);
   << mathprint:=0;
     found_mat_int=0$;
     found_mat_compl=0$;
     indent:=0$
     consts_compl:=()$
     consts_mat_compl:=()$
     consts_int:=()$
     consts_mat_int:=()$
     found_int:=0$
     found_compl:=0$
     flag:=0$
     if (PAIRP u) then <<
        printout("<math>");
 	indent:=3;

        if ((car u)='setq) then 
          <<if (PAIRP caddr u) then 
	      if (issq(caddr u)=1) then arbitrary_c( PREPSQ cadr caddr u ) 
		 else
	            if (caaddr u='mat) then arbitrary_c(caddr u) 
		    else  
	              if (caaddr u='list) then arbitrary_c( !*a2k caddr u);
	     setqML( u )>>
	else 
           if ((car u)='list) then 
	     << arbitrary_c( !*a2k u ); listML(cdr u)>>
	   else 
    	      if ((car u)='mat) then 
	        << arbitrary_c( u );
	  	   matrixML(cdr u)>>
	      else
    	         if ((car u)='!*sq) then 
  	 	   << arbitrary_c(PREPSQ (cadr u));
         	      expression(PREPSQ (cadr u))>>
	         else expression(u); 

             indent:=indent-3;
	     close_forall();
	     indent:=0;
	     printout( "</math>" ) 
	>> 
     else 
	if (ATOM u) then << printout( "<math>" ); indent:=3;
	 	expression( u ); indent:=0; printout( "</math>" )>>
  else ; >>;
      

%This function executes certain commands when switches state are changed.
%It will change the outputhandler!* when mathml is set to on or both is set
%to on. And then modify it accroding to the switches states.

symbolic procedure onoff(u,bool);
   begin scalar x,y;
      if not idp u then typerr(u,"switch")
       else if not flagp(u,'switch)
               then rerror(rlisp,25,list(u,"not defined as switch"));
      x := intern crunch append(explode '!*,explode u);
      if !*switchcheck and lispeval x eq bool then return nil
       else if y := atsoc(bool,get(u,'simpfg))
        then lispeval('progn . append(cdr y,list nil));
      if bool and x eq '!*!r!a!i!s!e then x := '!*raise; % Special case.
   if x='!*mathml AND bool=t then 
      outputhandler!*:='math_ml_printer;
   if x='!*mathml AND bool=nil then
      if !*both=nil then  
        outputhandler!*:=nil;
   if x='!*both AND bool=t then 
      outputhandler!*:='math_ml_printer;
   if x='!*both AND bool=nil then 
      if !*mathml=nil then    
        outputhandler!*:=nil
      else outputhandler!*:='math_ml_printer;

       set(x,bool);
   end;

lisp operator mml;
lisp operator parseml;

symbolic procedure crunch(l);
begin scalar tmp;
  tmp := reverse l;
  return if car tmp = '!/ then
     compress reverse append ('(!/ !!), cdr tmp)
  else compress l;
end;

endmodule;

end;
