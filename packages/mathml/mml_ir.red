%  Description: This module contains both functions for passing MathML to the Intermediate
%               representation and from the intermediate representation to MathML.
%               Both main functions are: mml2ir() and ir2mml().
%
%  Date: 2 May 2000
%
%  Author: Luis Alvarez Sobreviela
%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%


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

% $Id: $

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%  Here start the functions in charge of parsing MathML and printing                   %
%  it out in REDUCE intermediate representation.       MathML->REDUCE IR        %
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

% WN global '(f);
% WN changed name of parameter of mml f -> fi

fluid '(constructors!* !*f!*);

% This is the function for reading from a file. It is given the name of a file which contains
% the mathml input. It launches the program by calling mml2ir().

symbolic procedure mml(fi);
begin;
 file!*:=t;
 !*f!*:= open(fi, 'input);
 !*f!*:= rds(!*f!*);
 mml2ir();
 close rds !*f!*;
 file!*:=nil;
end;

% This function starts the parsing mechanism, which is a recursive descent
% parsing. Begins at the <math> token.


symbolic procedure mml2ir();
begin scalar res;
 res:=nil;
 mmlatts:=nil;
 space:='! ;
 count:=0;
 ch:=readch();
 temp2:=nil;
 lex();
 if char='(m a t h) then
     res:=mathml()
   else errorml("<math>",2);
 lex();
 if char='(!/ m a t h) then
   terpri()
   else errorml("</math>",19);

 return res;
end;

% The two next functions differ in that one of them parses from the next
% token onwards, and the other one from the actual token onwards.
% It is necessary to have both since some functions end their task one
% token ahead (eg getargs()).

symbolic procedure mathml();
begin scalar a;
 a:=nil;
 lex();
 return sub_math();
end;

symbolic procedure mathml2();
begin scalar a;
 a:=nil;
 return sub_math();
end;

% Parses all tokens which legally follow a <math> token.
% These tokens have to be constructors.

symbolic procedure sub_math();
begin scalar a, aa;
 a:=nil;

 if char='(i d e n t !/) then return list 'ident;

 % The reason why we perform an individual test to see if we are dealing with a vector tag
 % is because REDUCE changes vector in the list to ~vector when compressing (v e c t o r)
 % and then it doesnt work anymore...

  if char='(v e c t o r) then
   <<a:=vectorrd();
     if char neq '(!/ v e c t o r) then
       errorml("</vector>",2);
     return a>>;

 if (aa:=assoc(compress!* char, constructors!*)) then <<
    a:=apply(cadr aa, nil );
    if pairp a then if car a = 'csymbol then a:=cddr a;
    if pairp a then if car a = 'fn then a:=cddr a;
    if compress!* char neq third aa then
      errorml(third cdr aa, 2);
    return a>>;

  return nil;
end;


% The next two functions parse the <cn> and <ci> tokens and extract its
% content to be used by the function calling it. It will have different
% behaviours according to the attributes contained.

symbolic procedure cnrd();
begin scalar type, sep, tt, base;
% Must check that what is being returned is an int.
 type:=nil;
 sep:=nil;
 type:=intern find(atts, 'type);
 base:=find(atts, 'base);
 lex();
 tt := char;

 lex();

 if type='constant then return compress!* tt;

 if type=nil then return compress!* tt;

 if member(type, '(real integer)) neq nil then <<
   if base eq nil then return compress!* tt
   else return 'based_integer . nil . base . list ('string . list compress!* tt)
 >>;

 if member(intern type, '(rational complex!-cartesian complex!-polar)) neq nil then
   << sep:=seprd();
      if type='rational then <<
        lex();
        return rational(compress!* tt, sep)
      >>
      else
       if type='complex!-cartesian then
         << lex();return 'complex_cartesian . nil . compress!* tt . list sep >>
       else
        if type='complex!-polar then
         << lex();return 'complex_polar . nil . compress!* tt . list sep >>
   >>;
end;


symbolic procedure cird();
begin scalar test, type,aa, tt, ats;
 aa:=nil; type:=nil; test:=nil;
 ats:=retattributes(atts, '(type));
 lex();
 tt := char;
 lex();
  << test:=compress tt;
     if numberp test then errorml(test, 4);
     test := compress!* tt;
     if ats = nil then return test;
     return list('ci, ats, test)>>
end;

% returns the value of the constant values.
% !!!!!!!!!! USELESS
%symbolic procedure consts(c);
%begin;
% if c='(quote i) then return 'i;
% if c='(quote d) then return 'd;
% if c='(quote e) then return 'e;
% if c='(quote p) then return 'pi;
% if c='(quote infinity) then return 'infinity;
% if c='(quote gamma) then return 'gamma;
%end;

% Constructs a rational number in intermediate representation

symbolic procedure rational(a,b);
begin;
 return 'rational . nil . a . list b;
end;

% Reads through values seperated by <sep/> tags and
% returns them in a list

symbolic procedure seprd();
begin scalar p1, p2;
 p1:=nil; p2:=nil;
 if char neq '(s e p !/) then errorml("<sep/>",2);
 lex();
 p2:=compress!* char;
 return p2;
end;

% Creates a vector by using function matrix_row.

symbolic procedure vectorrd();
begin scalar a, ats;
 ats:=retattributes(atts, '(type other));
 a:=nil;
 a:=matrixrowrd();
 a:=cons('vectorml,cons(ats, a));
 return a;
end;

% The following functions constructs the matrix from the mathml information.

symbolic procedure matrixrd();
begin scalar b1, stop, ats, b2;
 ats:=retattributes(atts, '(type));
 stop:=0;
 b1:='();
 b2:=nil;
 while stop=0 do
 <<
   lex();
   if char='(m a t r i x r o w) then
    <<b2:=matrixrowrd();
      if b1 neq nil then b1:=append(b1, list b2)
      else b1:=list b2;
      if char neq '(!/ m a t r i x r o w) then
       errorml("</matrixrow>",2)>>
   else stop:=1
  >>;
 return cons('matrix, cons(ats,cons('matrixrow, list b1)));
end;

symbolic procedure matrixrowrd();
begin scalar a;
 a:=nil;
 a:=mathml();
 return if a=nil then nil
        else cons(a, matrixrowrd());
end;

% returns a lambda function constructed from the information supplied.

symbolic procedure lambdard();
begin scalar b1, b2, ats;
 ats:=retattributes(atts, '(type definitionURL encoding));
 lex();
 b1:=getargsrd();
 b2:=mathml2();
 lex();
 return cons('lambda, cons(ats, append (b1, list b2)));
end;

% returns a set constructed from the information supplied.

symbolic procedure setrd();
begin scalar setvars, ats;
 ats:=retattributes(atts, '(type));
 setvars:= cons('set, cons(ats, stats_getargs()));
 return setvars;
end;

% returns a list constructed from the information supplied.

symbolic procedure listrd();
begin scalar ats;
 ats:=retattributes(atts, '(order));
 return cons('list, cons(ats , stats_getargs()));
end;



symbolic procedure fnrd();
begin scalar b1;
 lex();
 if char neq '(c i) then errorml(compress char,20)
 else b1:= mathml2();
 lex();
 return b1;
end;

% Reads the declare construct and sets the value of the given variable to
% the given value.

symbolic procedure declarerd();
begin scalar b1, b2, ats;
 ats:=retattributes(atts, '(type nargs occurence scope definitionURL));
 lex();
 if char='(c i) then
  << b1:=cird()>>
 else errorml("<ci>", 8);
 lex();
 if char neq '(!/ d e c l a r e) then <<b2 :=mathml2(); lex()>>;

 return cons('declare, list(ats, b1, b2));
end;

% This function will determine if the next token is a valid token following
% an apply token. It then calls the appropriate function if succesful.

symbolic procedure applyrd();
begin scalar aa, fun;
 lex();
 % This following _if_ statement relates the mathml tag to its entry in functions!*
 % It then returns a list starting with the name of the function followed by its
 % arguments: eg: (plus 1 2 3).
 % It uses the table in functions!* to find the function name (the third entry) and
 % the arguments to send the RD function.

 mmlatts:=retattributes(atts, '(type definitionURL encoding));

 if (aa:=assoc(compress!* char, functions!*)) then <<
   fun:=apply(cadr aa, nil);
   fun:=mmlatts . fun;
   mmlatts:=nil;
   return cons(cadr rest aa, fun);
 >>;
 errorml(compress char, 17);
end;


%  Reads through a select construct and acts accordingly.

symbolic procedure selectrd();
begin scalar a1, b2, b3;
 a1:=mathml();

 if car a1 = 'matrix then <<
   b2:=mathml();
   lex();
   if char neq '(!/ a p p l y) then <<b3:=mathml2(); lex()>>;
   return cons(a1, list(b2, b3))
 >>;

 if car a1 = 'list or car a1 = 'vectorml then <<
   b2:=mathml();
   lex();
   return cons(a1, list b2)
 >>;

end;

% Returns the transpose of the element contained in the transpose tags.

symbolic procedure transposerd();
begin scalar a;
 a:=mathml();
 lex();
 return list a;
end;

% Returns the determinant of the given element.

symbolic procedure determinantrd();
begin scalar a;
 a:=mathml();
 lex();
 return list a;
end;

% Takes the given function name, makes it an operator, and then
% applies it to the arguments specified in the mathml input.

symbolic procedure applyfnrd();
begin scalar b1, b2, c1;
 b1:=nil; b2:=nil; c1:=nil;
 b1:=fnrd();
 b2:=stats_getargs();
 return b1 . nil . b2;
end;

% Introduces the new csymbol element of MathML 2.0

symbolic procedure csymbolrd();
begin scalar b1, b2, c1;
 b1:=nil; b2:=nil; c1:=nil;
 b1:=fnrd();
 b2:=stats_getargs();
 return b1 . nil . b2;
end;

% Reads the condition tag.

symbolic procedure conditionrd();
begin scalar a;
 a:=mathml();
 lex();
 if char neq '(!/ c o n d i t i o n) then errorml("</condition>", 2);
 return cons('condition, list a);
end;

% This function will read all legal tags following the <reln> tag.

fluid '(relations!*);

symbolic procedure relnrd();
begin scalar aa, ats;
 lex();
 ats:=retattributes(atts, '(type definitionURL));
 if (aa:=assoc(compress!* char, relations!*)) then return cons(cadr rest aa, cons(ats, apply(cadr aa, nil)));
end;

symbolic procedure relationrd( type );
begin scalar args;
 args:=stats_getargs();
 return cons(cadr type, args);
end;

%!!!!!!!! PROBABLY USELESS FUNCTION!!!!!
symbolic procedure binaryrelationrd( type );
begin scalar arg1, arg2;
 arg1 := mathml();
 arg2 := mathml();
 lex();
 return cons(type, list (arg1, arg2));
end;

% The following functions do all the necessay actions in order to evaluate
% what should be by the tags.


symbolic procedure subsetrd();
begin scalar abc1;
abc1:=nil;
abc1:=mathml();
return if abc1 = nil then '()
        else cons(abc1, subsetrd());
end;

symbolic procedure prsubsetrd();
begin scalar abc1;
abc1:=nil;
abc1:=mathml();
return if abc1 = nil then '()
        else cons(abc1, prsubsetrd());
end;

% These functions parse through most MathML elements,
% since many fall in the unary, binary and nary categories.

symbolic procedure unaryrd();
begin scalar a;
  a:= mathml();
  lex();
  return list a;
end;

symbolic procedure binaryrd();
begin scalar a1, a2;
  a1:=mathml();
  a2:=mathml();
  lex();
  return cons(a1, list a2);
end;

symbolic procedure naryrd();
begin scalar a;
a:=mathml();
return if a = nil then '()
        else cons(a, naryrd());
end;

symbolic procedure setfuncsnaryrd();
begin scalar a;
a:=mathml();
if pairp a then <<if cadr a neq nil then if intern cadr car cadr a = 'multiset then mmlatts:='multiset;>>;
return if a = nil then '()
        else cons(a, setfuncsnaryrd());
end;

symbolic procedure setfuncsbinrd();
begin scalar flag,a1,a2;
  flag:=nil;
  a1:=mathml();
  if pairp a1 then <<if cadr a1 neq nil then if intern cadr car cadr a1 = 'multiset then flag:=t;>>;
  a2:=mathml();
  if pairp a2 then <<if cadr a2 neq nil then if intern cadr car cadr a2 = 'multiset then flag:=t else flag:=nil;>>;
  lex();
  if flag=t then mmlatts:='multiset;
  return cons(a1, list a2);
end;


% Encodes information given in a <limit/> tag.

symbolic procedure limitrd();
begin scalar var, condi, low, exp, ats;
 ats:=retattributes(atts, '(definitionURL));
 low:=nil;
 lex();
 if char='(b v a r) then
  << var:=bvarrd();
     if (caddr var neq 1) then errorml("<degree>",8);
     lex()>>
 else var:=nil;

 if char='(l o w l i m i t) then
  << low:=lowlimitrd();
     >>
 else if char='(c o n d i t i o n) then
     <<      condi:=conditionrd()
        >>
      else condi:=nil;

 exp:=mathml();
 lex();

 if condi=nil then
   return list(var, low, exp);

 if low=nil then
        return list(var, condi, exp);
end;

% Returns the partial derivative.

symbolic procedure partialdiffrd();
begin scalar res, bvar, express;
 lex();
 bvar:=getargsrd();
 express:=mathml2();
 lex();
% res:=cons(express, bvar);
 res:=append(bvar, list express);
 return res;
end;

% Returns the derivative.

symbolic procedure diffrd();
begin scalar bvar, express;
 lex();
 if char='(b v a r) then
  <<bvar:=bvarrd();
    lex()>>
 else bvar:=nil;
 express:=mathml2();
 lex();
 return diff2 list(bvar, express);
end;

% This function restructures the IR when we are differentiating
% more than degree 1 so the translation is possible to OM

symbolic procedure diff2(elem);
begin scalar fun, res, deg, var;
  deg:=caddr car elem;
  var:=cadr car elem;
  if deg=1 then return elem;
  fun:=car reverse elem;
  res:='diff . nil . ('bvar . var .list  1) . list fun;
  deg:=deg-1;
  while deg > 0 do <<
  res:='diff . nil . ('bvar . var .list  1) . list res;
  deg:=deg-1;
  >>;
  return cddr res;
end;


% This function reads through the a series of <bvar> tags and extracts the
% variables.

symbolic procedure getargsrd();
begin scalar a;

% Dont forget. This function leaves the file pointer on
% the next token after the last bvar. So you need to use mathML2 after.

if char='(b v a r) then
<<a:=bvarrd();
  lex();
  return cons (a,getargsrd())>>;
end;

% Parses through MathML quantifiers

symbolic procedure quantifierrd();
begin scalar bvars, condi, exp;
  lex();
  bvars:=getargsrd();
  if char='(c o n d i t i o n) then
     condi:=conditionrd()
  else condi:=nil;

  if condi neq nil then exp:=mathml()
  else exp:=mathml2();
  lex();
  return append(bvars, list(condi, exp));
end;

% This function will parse through the sum, product and int tags. Takes in the expression, then
% the bound variable, and finally the limits, conditions or intervals if they exist.

symbolic procedure symbolsrd();
begin scalar bvar, low, upper, int, exp, result, cond;
 low:=nil;
 upper:=nil;
 int:=nil;
 exp:=nil;
 result:=nil;
 cond:=nil;
 lex();
 if char='(b v a r) then
      <<bvar:=bvarrd();
        if (caddr bvar eq 1) then bvar:=bvar
        else
         errorml("",13);
        lex()>>
   else errorml("<bvar>",14);


 if char='(l o w l i m i t) then <<low:=lowupperlimitrd(); lex()>>
   else low:=nil;

 if char='(i n t e r v a l) then
   <<int:=intervalrd();
     lex()>>
   else int:=nil;

 if char='(c o n d i t i o n) then
   <<cond:=conditionrd();
     lex()>>
   else cond:=nil;

 exp:=mathml2();
 lex();
 if (low neq nil) then return list(bvar, low, exp);
 if (int neq nil) then return list(bvar, int, exp);
 if (cond neq nil) then return list(bvar, cond, exp);
 return list(bvar, nil, exp);
end;

% Here we parse bound variables. The function reads the variable as well as
% the degree if there is one.

symbolic procedure bvarrd();
begin scalar var, deg;
 lex();
 if char='(d e g r e e) then
     errorml("<bvar>",15);
 var:=mathml2();
 lex();
 if char='(d e g r e e) then
   << deg:=mathml();
      lex();
      if char neq '(!/ d e g r e e) then
        error("</degree>",2);
      lex()>>
 else deg:=1;

 if char='(!/ b v a r) then return cons('bvar , list(var, deg))
   else errorml("</bvar>", 2);
end;

% Functions used to parse the limits of an integral, sum, or product.

symbolic procedure lowupperlimitrd();
begin scalar lowlimit,  upperlimit;
 lowlimit:=mathml();
 lex();
 if char='(!/ l o w l i m i t) then upperlimit:=upperlimitrd()
   else errorml("</lowlimit>", 2);
 return cons('lowupperlimit, list (lowlimit, upperlimit))
end;

symbolic procedure lowlimitrd();
begin scalar lowlimit;
 lowlimit:=mathml();
 lex();
 if char neq '(!/ l o w l i m i t) then errorml("</lowlimit>", 2);
 return cons('lowlimit, list lowlimit);
end;

symbolic procedure upperlimitrd();
begin scalar upperlimit;
 lex();
 if char neq '(u p l i m i t) then errorml("<uplimit>", 10);
 upperlimit:=mathml();
 lex();
 if char='(!/ u p l i m i t) then return upperlimit
   else errorml("</uplimit>", 2);
end;

symbolic procedure intervalrd();
begin scalar l,u, ats;
 ats:=retattributes(atts, '(closure));
 l:=mathml();
 u:=mathml();
 lex();
 if char='(!/ i n t e r v a l) then return cons('interval, list(ats, l,u))
   else errorml("</interval>", 2);
end;

% Following functions just evaluate calculus functions.

symbolic procedure logrd();
begin scalar a1, base;
 base:=nil;
 lex();
 if char='(l o g b a s e) then
    <<base:=logbaserd();
      lex()>>;
  a1:=mathml2();
  lex();
   return cons(base, list a1);
end;

symbolic procedure logbaserd();
begin scalar a;
 a:=mathml();
 lex();
 if char='(!/ l o g b a s e) then return a
   else errorml("</logbase>",2);
end;


% % Work on here. Make sure you can have either one or two arguments...
symbolic procedure minusrd();
begin scalar c,b;
  c:=mathml();
  b:=mathml();
  if b=nil then c:= cons(c,'())
   else <<
        c:=cons(c, cons(b, '()));
        lex()>>;
  return c;
end;


symbolic procedure rootrd();
begin scalar b,deg;
  lex();
  if char='(d e g r e e) then
  << deg:=mathml();
     lex();
     if char neq '(!/ d e g r e e) then
       error("</degree>","Syntax ERROR: Missing end tag");
     lex()>>
  else deg:=2;

  b:=mathml2();
  lex();
  return list(cons('degree, list deg), b);
end;



symbolic procedure minmaxrd();
begin scalar a, bvar, cond, flag;
 lex();
 flag:=0;
 if char = '(b v a r) then <<bvar:=bvarrd(); flag:=1; lex();>> else bvar:=nil;
 if char = '(c o n d i t i o n) then <<cond:=conditionrd()>>
 else <<
   a:=mathml2();
   a:=cons(a, stats_getargs());
   cond:=nil
 >>;

 if flag=1 then << a:=mathml2(); lex()>>;
 if bvar neq nil then return cons(bvar, append(list cond, list a));
 if cond neq nil then return list(cond);
 return a;
end;


% Following function are in charge of parsing statistics related mathml.

symbolic procedure momentrd( );
begin scalar  deg, child;
 lex();
 if char='(d e g r e e) then
   << deg:=mathml();
      lex();
      if char neq '(!/ d e g r e e) then
        error("</degree>",2);
      lex()>>
 else deg:=nil;

 child:=mathml2();
 lex();

 return list(cons('degree, list deg), child);
end;

% The following function gets all arguments from the mathml input.

symbolic procedure stats_getargs();
begin scalar ww;
  ww:=nil;
  ww:=mathml();
  if ww neq nil then <<
  return cons (ww,stats_getargs())>>;
end;


%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%   Here start the functions in charge of parsing reduce's output and printing %
%   it out in MathML.                 REDUCE->MathML                          %
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%


% The following function takes an IR expression and produces a MathML equivalent

symbolic procedure ir2mml( u );
begin;
     fluid '(indent);
     ind:=3;
     indent:=0$
     printout("<math>");
     indent!* t;
     expression u;
     indent!* nil;
     printout( "</math>" );
end;

% Prints out vectors.

symbolic procedure vectorml( elem );
begin;
   printout("<vector");
   attributesml(car elem, "");
   indent!* t;
   multi_elem(cdr elem);
   indent!* nil;
   printout("</vector>");
end;

% Following functions print out matrices.

symbolic procedure matrixml( elem );
begin;
   printout("<matrix");
   attributesml(car elem, "");
   indent!* t;
   if cadr elem = 'matrixrow then matrix_rows(caddr elem)
   else matrix_rows(cols2rows caddr elem);
   indent!* nil;
   printout("</matrix>")
end;

symbolic procedure matrix_rows( elem );
begin;
  if (elem neq()) then
     <<      printout("<matrixrow>");
        indent!* t;
        row(car elem);
          indent!* nil;
        printout("</matrixrow>");
        matrix_rows( cdr elem ); >>
end;

symbolic procedure row( elem );
begin;
  if (elem neq()) then
         << expression(car elem); row(cdr elem);>>
end;


symbolic procedure identml(elem);
begin;
  printout( "<ident/>" );
end;

% This function takes in an intermediate representation expression, parses it and prints it
% in MathML.

fluid '(ir2mml!*);

symbolic procedure expression( elem );
begin scalar aa;;
if elem neq nil then
if (atom elem) then constsml( elem ) else
 <<
  if (aa:=assoc(car elem, ir2mml!*)) then <<
     if caddr aa = nil then
       apply(cadr aa, list cdr elem)
     else
       apply(cadr aa, list(cdr elem, car elem))
  >>
  else
    if ((car elem)= '!*sq)  then expression (prepsq (cadr elem))
    else operator_fn(elem);>>;
end;

symbolic procedure tendstoml( elem );
begin;
   printout("<apply><tendsto");
   attributesml(car elem, "/");
   indent!* t;
   expression(cadr elem);
   expression(caddr elem);
   indent!* nil;
   printout("</apply>");
end;


% Prints out derivatives.

symbolic procedure dfml( elem );
begin scalar test;
 test:=cdr elem;
 if length test=1 or (length test=2 and numberp
cadr test) then
    printout("<apply><diff/>")
 else
    printout("<apply><partialdiff/>");
 indent!* t;
 dfargs(cdr elem);
 expression(car elem);
 indent!* nil;
 printout("</apply>");
end;

symbolic procedure dfargs( elem );
begin;
 if elem neq nil then
   << if length elem>1 then
      <<  if numberp cadr elem then
          <<printout("<bvar>");
            indent!* t;
            expression car elem;
            degreeml(cadr elem);
            indent!* nil;
            printout("</bvar>");
            dfargs(cddr elem)>>
          else
          <<printout("<bvar>");
            indent!* t;
           expression car elem;
            indent!* nil;
            printout("</bvar>");
            dfargs(cdr elem)>>; >>
      else
        << printout("<bvar>");
           indent!* t;
           expression car elem;
           indent!* nil;
           printout("</bvar>");
           dfargs(cdr elem)>> >>;
end;


% Prints out degree statements.

symbolic procedure degreeml( elem );
begin;
 if car elem neq nil then <<
   printout("<degree>");
   indent!* t;
   expression( car elem );
   indent!* nil;
   printout("</degree>") >>;
end;


symbolic procedure rationalml(elem);
begin scalar a, b;
 a:=cadr elem;
 b:=caddr elem;
 printout("<cn type=""rational"">");
 princ a; princ "<sep/>"; princ b; princ "</cn>";
end;


% Prints out relns.

symbolic procedure reln(elem, tty);
begin;
 printout("<apply>");
 princ "<"; princ tty;
 attributesml(car elem, "/");
 indent!* t;
 multi_elem( cdr elem );
 indent!* nil;
 printout("</apply>");
end;

% Prints out a set.

symbolic procedure containerml( elem, tty );
begin;
  if tty = 'integer_interval then tty:='interval;
  printout("<"); princ tty;
  attributesml(car elem, "");
  indent!* t;
  multi_elem( cdr elem );
  indent!* nil;
  printout("</"); princ tty; princ ">";
end;

% Prints out set theory related functions.

symbolic procedure sets(elem, tty);
begin;
 printout("<apply>");
 princ "<"; princ tty;
 attributesml(car elem, "/");
 indent!* t;
 multi_elem( cdr elem );
 indent!* nil;
 printout("</apply>");
end;

symbolic procedure listml( elem );
begin;
  printout( "<list" );
  attributesml(car elem,"");
  indent!* t;
  multilists( cdr elem );
  indent!* nil;
  printout( "</list>" );
end;

symbolic procedure multilists( elem );
begin;
 if elem neq nil then
  if ((length elem)=1) then expression (car elem)
    else <<expression(car elem); multilists(cdr elem);>>
end;

% Prints out unknown functions as a function. It prints out all variables
% declared as operators.

symbolic procedure csymbol_fn( elem );
begin;
  printout("<apply>");
  indent!* t;
  printout("<csymbol");
  if car elem neq nil then attributesml(car elem, "")
  else princ ">";
  indent!* t;
  printout("<ci>");
  princ cadr elem;
  princ "</ci>";
  indent!* nil;
  printout("</csymbol>");
  multi_args(cddr elem);
  indent!* nil;
  printout("</apply>");
end;

symbolic procedure operator_fn( elem );
begin;
  printout("<apply>");
  indent!* t;
  printout("<csymbol>");
  indent!* t;
  printout("<ci>");
  princ car elem;
  princ "</ci>";
  indent!* nil;
  printout("</csymbol>");
  multi_args(cdr elem);
  indent!* nil;
  printout("</apply>");
end;

% Reads through a list and prints out each component.

symbolic procedure multi_args( elem );
begin;
  if  (elem neq ()) then <<expression(car elem); multi_args( cdr elem );>>
end;


% Prints out logs with a base.

symbolic procedure log_baseml(elem, type);
begin;
  printout("<apply><log");
  attributesml(car elem, "/");
  indent!* t;
  if car reverse elem neq nil then <<
    printout("<logbase>");
    indent!* t;
    expression(cadr elem);
    indent!* nil;
    printout("</logbase>")>>;
    expression(caddr elem);
    indent!* nil;
    printout("<apply>");
end;


% Prints out equal relns.

symbolic procedure equalml( elem );
begin;
  printout( "<reln><eq/>" );
  indent!* t;
  expression(car elem);
  expression(cadr elem);
  indent!* nil;
  printout( "</reln>" );
end;

% Prints out square roots and moments.

symbolic procedure degreetoksml( elem, tty );
begin;
  printout( "<apply><" ); princ tty;
  attributesml(car elem, "/");
  indent!* t;
  degreeml(cdadr elem);
  expression( caddr elem );
  indent!* nil;
  printout( "</apply>" );
end;

symbolic procedure bvarml(elem);
begin;
  printout("<bvar>");
  indent!* t;
  expression(car elem);
  if cadr elem neq 1 then <<
    degreeml(list cadr elem);
  >>;
  indent!* nil;
  printout("</bvar>")
end;

% This function prints a series of bvar statements

symbolic procedure xbvarml(elem);
begin;
  if elem neq nil then <<bvarml cdar elem; xbvarml cdr elem>>;
end;

symbolic procedure conditionml( elem );
begin;
  printout("<condition>");
  indent!* t;
  expression(car elem);
  indent!* nil;
  printout("</condition>")
end;

symbolic procedure lambdaml( elem );
begin;
  printout("<lambda");
  attributesml(car elem, "");
  indent!* t;
  multi_elem(cdr elem);
  indent!* nil;
  printout("</lambda>")
end;

symbolic procedure attributesml( a, s );
begin;
  if a eq nil then <<princ s; princ ">">>
  else <<
     princ " ";
     princ caar a;
     princ "=""";
     if caar a neq 'definitionURL then <<
        if cadar a = 'vectorml then princ "vector"
        else princ cadar a;
     >>
     else mathml_list2string(cadar a);
     princ"""";
     attributesml(cdr a, s);
  >>;
end;

symbolic procedure mathml_list2string(a);
begin;
  if a neq nil then <<princ car a; mathml_list2string(cdr a)>>;
end;

symbolic procedure declareml( elem );
begin;
  printout("<declare");
  attributesml(car elem, "");
  indent!* t;
  multi_elem(cdr elem);
  indent!* nil;
  printout("</declare>")
end;

symbolic procedure lowupperlimitml( elem );
begin;
  printout("<lowlimit>");
  indent!* t;
  expression(cadr elem);
  indent!* nil;
  printout("</lowlimit>");
  printout("<uplimit>");
  indent!* t;
  expression(caddr elem);
  indent!* nil;
  printout("</uplimit>");
end;

symbolic procedure lowlimitml( elem );
begin;
  printout("<lowlimit>");
  indent!* t;
  expression(car elem);
  indent!* nil;
  printout("</lowlimit>");
end;


% Prints out quotients.

symbolic procedure quotientml( elem , tty);
begin;
  if (numberp car elem) and (numberp cadr elem) then <<
     if !*web=nil then printout("<cn type=""rational""> ")
     else printout("<cn type=&quot;rational&quot;> ");
     princ car elem;
     princ " <sep/> ";
     princ cadr elem;
     princ " </cn>">>
  else <<
     printout( "<apply>" );
     princ "<"; princ tty; princ "/>";
     indent!* t;
     expression( cadr elem );
     expression( caddr elem );
     indent!* nil;
     printout( "</apply>" )>>;
end;

% Prints out all nary functions.

symbolic procedure nary( elem, type );
begin;
  if car elem = 'e and type = 'power then unary(cdr elem, 'exp)
  else <<
    printout( "<apply>" );
    princ "<";
    princ type;
    attributesml(car elem, "/");
    indent!* t;
    multi_elem( cdr elem );
    indent!* nil;
    printout( "</apply>" )>>
end;

symbolic procedure multi_elem( elem );
begin;
   if ((length elem)=1) then expression( car elem )
       else <<expression car elem ; multi_elem( cdr elem );>>
end;


symbolic procedure minusml( elem );
begin;
  printout( "<apply><minus/>" );
  indent!* t;
  multiminus( cdr elem );
  indent!* nil;
  printout( "</apply>" );
end;

symbolic procedure multiminus( elem );
begin;
  expression(car elem);
  if ((length elem)=2) then expression cadr elem;
end;

symbolic procedure ciml(elem);
begin;
  printout("<ci");
  attributesml(car elem, "");
  princ(cadr elem);
  princ("</ci>");
end;

symbolic procedure cnml(elem);
begin;
  printout("<cn");
  attributesml(car elem, "");
  princ(cadr elem);
  princ("</cn>");
end;

symbolic procedure semanticml(elem);
begin;
  if length elem > 1 then <<
    printout("<apply>");
    indent!* t;
    printout("<fn>");
    indent!* t;
  >>;
  printout("<semantic>");
  indent!* t;
  printout("<ci><mo>"); princ caar elem; princ "</mo></ci>";
  printout("<annotation-xml encoding=""OpenMath"">");
  indent!* t;
  printout"<"; mathml_list2string cadar elem; princ ">";
  indent!* nil;
  printout("</annotation-xml>");
  indent!* nil;
  printout("</semantic>");
  if length elem > 1 then <<
     indent!* nil;
     printout("</fn>");
     multi_elem(cdr elem);
     indent!* nil;
     printout("</apply>");
  >>;
end;

symbolic procedure numml(elem, type);
begin;
   if type='based_integer then <<
     printout "<cn type=""integer"" base="""; princ cadr elem; princ """> "; princ cadr caddr elem; princ " </cn>";
   >>;
   if type='complex_cartesian then <<
     printout "<cn type=""complex-cartesian""> "; princ cadr elem; princ " <sep/> "; princ caddr elem; princ " </cn>";
   >>;
   if type='complex_polar then <<
     printout "<cn type=""complex-polar""> "; princ cadr elem; princ " <sep/> "; princ caddr elem; princ " </cn>";
   >>;


end;

% Prints out all pieces of data: i.e terminal symbols.
% They can be numbers, identifiers, or constants.

symbolic procedure constsml(exp);
begin;
      if (numberp exp) then
                      << printout "<cn";
                               if (floatp exp) then  princ " type=""real""> "
                            else
                              if (fixp exp) then princ " type=""integer""> "
                                else princ "> ";
                         princ exp;
                         princ " </cn>">>;
         if (idp exp) then
                     <<
                        if member(intern exp, constants!*) neq nil then
%                            <<printout "<cn type=""constant""> "; princ exp; princ " </cn>"; return nil>>
                            <<printout "<cn type=""constant""> "; princ exp; princ " </cn>">>
                        else << printout "<ci";
                         if (listp exp) then princ " type=""list""> "
                           else
                              if (vectorp exp) then princ " type=""vector""> "
                                else princ "> ";
                         princ exp;
                         princ " </ci>">>; >>;
end;

% Functions used to print out variables with a subscript.

% Prints out expressions in math form. Plagiarised from reduce code of
% mathprint

symbolic procedure ma_print l;
begin scalar temp;
   temp:=outputhandler!*;
   outputhandler!*:=nil;
   terpri!* nil;
   if !*web=nil then maprin "<cn type=""real"">"
   else maprin "<cn type=&quot;real&quot;>";
   maprin l;
   maprin "</cn>";
   terpri!* nil;
   outputhandler!*:=temp;
end;

% Function in charge of doing all printing in order to make sure the
% indentation is always correct.

symbolic procedure printout( str );
begin;
   if !*web = nil then terpri();
   if !*web = nil then for i := 1:indent
      do << princ " " >>;
   if pairp str then
    <<if car str='!:rd!: or car str='!:rn!: then ma_print str
    else princ str>>
   else princ str;
end;

lisp operator mml;
lisp operator mml2ir;
algebraic operator g_eq;
algebraic operator l_eq;
algebraic operator gt;
algebraic operator lt;
lisp operator plusrd;

symbolic procedure test();
begin scalar a;
  a:=mml2ir();
  terpri!* t;
  princ "Intermediate representation: ";
  terpri!* t;
  print a;
  ir2mml a;
end;


end;
