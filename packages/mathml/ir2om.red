%  Description: This module defines all functions necessary to pass from the
%               intermediate representation to OpenMath. They print out the
%               OpenMath expression on the screen.
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

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% The following tables are used by the functions in this file       %
% in order to map properly intermediate representation tokens   %
% to OpenMath elements and symbols.                          %
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

mmltypes!*:=
'((complex_cartesian . (complex_cartesian_type))
(complex_polar . (complex_polar_type))
(constant . (constant_type))
(integer . (integer_type))
(list . (list_type))
(matrix . (matrix_type))
(rational . (rational_type))
(real . (real_type))
(set . (set_type)));

% Maps MathML <interval> attribute values
% to OpenMath symbols

interval!*:=
'((open . (interval_oo))
(closed . (interval_cc))
(open!-closed . (interval_oc))
(closed!-open . (interval_co)));

% Maps MathML constants to OpenMath constant symbols
% and their CDs.

constantsom!*:=
'((!&imaginaryi!; . (nums1 i))
(!&exponentiale!; . (nums1 e))
(!&pi!; . (nums1 pi))
(!&notanumber!; . (nums1 nan))
(!&gamma!; . (nums1 gamma))
(!&infin!; . (nums1 infinity))
(!&false!; . (logic1 false))
(!&true!; . (logic1 true)));


%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% The function ir2om starts the process of translating intermediate  %
% representation into OpenMath         IR->OpenMath              %
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%


symbolic procedure ir2om( elem );
begin;
   ind:=2;
   indent:=0;
   printout("<OMOBJ>");
   indent!* t;
   objectom( elem );
   indent!* nil;
   printout("</OMOBJ>");
end;

symbolic procedure objectom(elem);
begin scalar aa;;
   if pairp elem then <<
    if (aa:=assoc(car elem, ir2mml!*)) then <<
      apply(cadddr aa, list elem)
     >>
    else fnom(elem);
   >>
   else basicom(elem);
end;

symbolic procedure strom(elem);
begin;
  printout "<OMSTR> ";princ cadr elem; princ " </OMSTR>";
end;

% Recieves an element which is not a list
% and prints out OpenMath accordingly.

symbolic procedure basicom(elem);
begin;
  if numberp elem then <<
    if fixp elem then integerom(elem);
    if floatp elem then floatom(elem)
  >>
  else
    if idp elem then variableom(elem);
end;

% Prints out integers

symbolic procedure integerom(elem);
begin;
   printout("<OMI> ");
   princ elem;
   princ " </OMI>"
end;

% Prints out decimal floats

symbolic procedure floatom(elem);
begin;
   printout("<OMF ");
   princ "dec="""; princ elem; princ """/>";
end;

% Prints out OpenMath variables

symbolic procedure variableom(elem);
begin scalar aa;
 aa:=assoc(intern elem, constantsom!*);
 if aa neq nil then <<
    printout("<OMS ");
    princ "cd=""";
    princ cadr aa;
    princ """ ";
    princ "name=""";
    princ caddr aa;
    princ """/>";
   >>
   else <<
     if elem neq nil then <<
       printout("<OMV ");
       princ "name="""; princ elem; princ """/>";
    >>
  >>;
end;



% Prints out all OpenMath symbols of 1, 2, or more arguments
% constructed by application.

symbolic procedure naryom(elem);
begin scalar cd, name;
  name:=car elem;
  if name='var then name:='variance;
  cd := assoc(name, valid_om!*);
  if cd neq nil then cd:=cadr cd;
  if cadr elem neq nil then <<
    if cadr elem = 'multiset then cd:=cadr elem;
  >>;
  printout "<OMA>";
  indent:=indent+2;
  printout "<OMS cd="""; princ cd; princ """ name="""; princ name; princ """>";
  multiom(cddr elem);
  indent:=indent-2;
  printout "</OMA>";
end;

symbolic procedure multiom(elem);
begin;
   if ((length elem)=1) then objectom( car elem )
       else <<objectom car elem ; multiom( cdr elem );>>
end;

% Prints out the OpenMath matrix_selector or
% vector_selector symbols

symbolic procedure selectom(elem);
begin scalar name;
  if caaddr elem ='matrix then name:='matrix_selector
  else name:='vector_selector;
  printout "<OMA>";
  indent:=indent+2;
  printout "<OMS cd=""linalg3"" name="""; princ name;
  princ """/>";
  multiom(cdddr elem);
  objectom caddr elem;
  indent:=indent-2;
  printout "</OMA>";
end;

% Prints out elements which are
% containers in MathML.

symbolic procedure containerom(elem);
begin scalar cd, att, name;
  att:=cadr elem;
  name:=car elem;
  printout "<OMA>";
  indent!* t;
  if name = 'vectorml then name:= 'vector;
  cd := cadr assoc(name, valid_om!*);
  if car elem = 'set and pairp att then <<
    if intern cadr car att='multiset then cd:='multiset1;
  >>;

  if car elem = 'vectorml then name:= "vector";
  if car elem = 'vectorml then elem:= 'vector . cdr elem;
  printout "<OMS cd="""; princ cd; princ """ name="""; princ name; princ """/>";
  multiom(cddr elem);
  indent!* nil;
  printout "</OMA>";
end;

% Prints out OpenMath intervals

symbolic procedure intervalom(elem);
begin scalar aa, att, name, cd;
  att:=cadr elem;
  name:=car elem;

  if name = 'lowupperlimit then <<name:='integer_interval; att:=nil; elem:=car elem . nil . cdr elem>>;

  cd := cadr assoc(name, valid_om!*);

  if att neq nil then <<
     aa:=assoc(intern cadr car att, interval!*);
     name:=cadr aa;
  >>;

  printout "<OMA>";
  indent!* t;
  printout "<OMS cd="""; princ cd; princ """ name="""; princ name; princ """/>";
  multiom(cddr elem);
  indent!* nil;
  printout "</OMA>";

end;

% Prints matrices according to the definition
% in CD linalg1

symbolic procedure matrixom(elem);
begin;
  printout "<OMA>";
  indent!* t;
  printout "<OMS cd=""linalg1"" name=""matrix""/>";
  matrixrowom(cadddr elem);
  indent!* nil;
  printout "</OMA>";
end;

symbolic procedure matrixrowom(elem);
begin;
  if elem neq nil then <<
    printout "<OMA>";
    indent!* t;
    printout "<OMS cd=""linalg1"" name=""matrixrow""/>";
    multiom(car elem);
    indent!* nil;
    printout "</OMA>";
    matrixrowom cdr elem;
  >>;
end;

% Prints out variables which posses
% an attribute

symbolic procedure ciom(elem);
begin;
  printout "<OMATTR>";
  indent!* t;
  printout "<OMATP>";
  indent!* t;
  printout "<OMS cd=""typmml"" name=""type"">";
  printout "<OMS cd=""typmml"" name=""";
  princ assoc(intern cadr car cadr elem, mmltypes!*);
  princ cadr assoc(intern cadr car cadr elem, mmltypes!*);
  princ """>";
  indent!* nil;
  printout "</OMATP>";
  objectom(caddr elem);
  indent!* nil;
  printout "</OMATTR>";
end;

% Prints out constants such as pi, gamma etc...

symbolic procedure numom(elem);
begin;
  printout "<OMA>";
  indent!* t;
  printout "<OMS cd=""nums1"" name="""; princ car elem; princ """/>";
  objectom cadr elem;
  if car elem='based_integer then strom cadr caddr elem
  else objectom caddr elem;
  indent!* nil;
  printout "</OMA>";
end;

symbolic procedure fnom(elem);
begin;
  printout "<OMA>";
  indent!* t;
  printout "<OMATTR>";
  indent!* t;
  printout "<OMATP>";
  indent!* t;
  printout "<OMS cd=""typmml"" name=""type""/>";

  printout "<OMS cd=""typmml"" name="""; princ "fn_type"; princ """/>";
  indent!* nil;
  printout "</OMATP>";
  objectom car elem;
  indent!* nil;
  printout "</OMATTR>";
  multiom(cddr elem);
  indent!* nil;
  printout "</OMA>";
end;

% Prints out partial differentiation expressions

symbolic procedure partialdiffom(elem);
begin scalar cd, var, fun, name;
  cd := assoc(car elem, valid_om!*);
  if cd neq nil then cd:=cadr cd;
  name:=car elem;
  var:=cdr reverse cddr elem;
  fun:=car reverse elem;

  if length var = 1 then symbolsom('diff . cdr elem);
end;

% Prints out elements such as sum, prod, diff and int.

symbolic procedure symbolsom(elem);
begin scalar cd, var, fun, int, name;
  cd := assoc(car elem, valid_om!*);
  if cd neq nil then cd:=cadr cd;
  name:=car elem;
  var:=caddr elem;
  fun:=car reverse elem;
  if name neq 'diff then int:=cadddr elem;

  % This error states that a <sum> will not be translated to MathML
  if int neq nil then if car int = 'condition then errorml("<condition> tag not supported in MathML", 1);

  printout "<OMA>";
  indent!* t;
  if int neq nil and name='int then name:='defint;
  printout "<OMS cd="""; princ cd; princ """ name="""; princ name; princ """/>";
  if int neq nil then objectom int;
  lambdaom ('lambda . nil . var . list fun);
  indent!* nil;
  printout "</OMA>";
end;

% Prints out lambda expressions

symbolic procedure lambdaom(elem);
begin scalar var, fun;
  var:= cadr caddr elem;
  fun:=car reverse elem;
  printout "<OMBIND>";
  indent!* t;
  printout "<OMS cd=""fns1"" name=""lambda""/>";
  printout "<OMBVAR>";
  indent!* t;
  objectom var;
  indent!* nil;
  printout "</OMBVAR>";
  objectom fun;
  indent!* nil;
  printout "</OMBIND>";
end;

% Does not work...

symbolic procedure semanticom(elem);
begin scalar sem;
  printout "<OMA>";
  indent!* t;
  sem:=cadr cadr elem;
  mathml_list2string sem;
  multiom cddr elem;
  indent!* nil;
  printout "</OMA>";
end;

% Prints out limit expressions

symbolic procedure limitom(elem);
begin scalar limit, fun, var, tendsto;
  var:=caddr elem;
  limit:=cadddr elem;
  fun:=car reverse elem;

  printout "<OMA>";
  indent!* t;
  printout "<OMS cd=""limit1"" name=""limit""/>";
  if car limit = 'lowlimit then <<
    objectom cadr limit;
    printout "<OMS cd=""limit1"" name=""null""/>"
  >>;
  if car limit = 'condition then <<
    objectom car reverse cadr limit;
    tendsto:=  cadr car cadr cadr limit;
    printout "<OMS cd=""limit1"" name="""; princ tendsto; princ """/>"
  >>;
  lambdaom ('limit . nil . var . list fun);
  indent!* nil;
  printout "</OMA>";
end;

% Prints out OpenMath quantifiers

symbolic procedure quantom(elem);
begin;
  if cadr reverse elem neq nil then errorml("condition tag not supported in MathML ", 2);
  printout "<OMBIND>";
  indent!* t;
  printout "<OMS cd=""quant1"" name="""; princ car elem; princ """/>";
  printout "<OMBVAR>";
  indent!* t;
  bvarom cddr elem;
  indent!* nil;
  printout "</OMBVAR>";
  objectom car reverse elem;
  indent!* nil;
  printout "</OMBIND>";
end;

symbolic procedure bvarom(elem);
begin;
  if pairp car elem then
  if car car elem = 'bvar then <<objectom cadr car elem; bvarom cdr elem>>;
end;

symbolic procedure printout( str );
begin;
   terpri!* t;
   for i := 1:indent do << princ " " >>;
   princ str;
end;

% This is the function the user types to
% translate MathML to OpenMath

symbolic procedure mml2om();
begin scalar a;;
  a:=mml2ir();
  terpri!* t;
  princ "Intermediate representation: "; terpri!* t; print a;
  ir2om a;
end;

lisp operator mml2om;

end;
