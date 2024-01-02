module newtok;  % Functions for introducing infix tokens to the system.

% Author: Anthony C. Hearn.

% Copyright (c) 1987 The RAND Corporation.  All rights reserved.

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

fluid '(!*msg !*redeflg!*);

global '(preclis!* fixedpreclis!*);

% Several operators in REDUCE are used in an infix form (e.g., +,- ).
% The internal alphanumeric names associated with these operators are
% introduced by the function NEWTOK defined below.  This association,
% and the precedence of each infix operator, is initialized in this
% section.  We also associate printing characters with each internal
% alphanumeric name as well.

fixedpreclis!* := '(where !*comma!* setq);

preclis!*:= '(or and member memq equal neq eq geq greaterp leq   % not
              lessp freeof plus difference times quotient expt cons);

deflist ('(
%  (not not)
   (plus plus)
   (difference minus)
   (minus minus)
   (times times)
   (quotient recip)
   (recip recip)
 ), 'unary);

flag ('(and or !*comma!* plus times),'nary);

flag ('(cons setq plus times),'right);

deflist ('((minus plus) (recip times)),'alt);

symbolic procedure mkprec;
   begin scalar x,y,z;
        x := append(fixedpreclis!*,preclis!*);
        y := 1;
    a:  if null x then return nil;
        put(car x,'infix,y);
        put(car x,'op,list list(y,y));   % for RPRINT.
        if z := get(car x,'unary) then put(z,'infix,y);
        if and(z,null flagp(z,'nary)) then put(z,'op,list(nil,y));
        x := cdr x;
        y := add1 y;
        go to a
   end;

mkprec();
% From here onwards the precedences of infix operators are established.

symbolic procedure newtok u;
   begin scalar !*redeflg!*,x,y;
      if atom u or atom car u or null idp caar u
        then typerr(u,"NEWTOK argument");
      % set up SWITCH* property.
      put(caar u,'switch!*,
          cdr newtok1(car u,cadr u,get(caar u,'switch!*)));
      % set up PRTCH property.
      y := intern list2string car u;
% A redefinition that does not seem to be changing anything does not
% need to be warned about.
      if not (get(cadr u, 'prtch) = y) and
          !*redeflg!* then lprim list(y,"redefined");
      put(cadr u,'prtch,y);
      if x := get(cadr u,'unary) then put(x,'prtch,y)
   end;

symbolic procedure newtok1(charlist,name,propy);
      if null propy then lstchr(charlist,name)
       else if null cdr charlist
        then begin
                if cdr propy and !*msg then !*redeflg!* := t;
                return list(car charlist,car propy,name)
             end
       else car charlist . newtok2(cdr charlist,name,car propy)
                         . cdr propy;

symbolic procedure newtok2(charlist,name,assoclist);
   if null assoclist then list lstchr(charlist,name)
    else if car charlist eq caar assoclist
     then newtok1(charlist,name,cdar assoclist) . cdr assoclist
    else car assoclist . newtok2(charlist,name,cdr assoclist);

symbolic procedure consescc u;
   if null u then nil else '!! . car u . consescc cdr u;

symbolic procedure lstchr(u,v);
   if null cdr u then list(car u,nil,v)
    else list(car u,list lstchr(cdr u,v));

newtok '((!$) !*semicol!*);
newtok '((!;) !*semicol!*);
newtok '((!+) plus);
newtok '((!-) difference);
newtok '((!*) times);
newtok '((!^) expt);
newtok '((!* !*) expt);
newtok '((!/) quotient);
newtok '((!=) equal);
newtok '((!,) !*comma!*);
newtok '((!() !*lpar!*);
newtok '((!)) !*rpar!*);
newtok '((!:) !*colon!*);
newtok '((!: !=) setq);
newtok '((!.) cons);
newtok '((!<) lessp);
newtok '((!< !=) leq);
newtok '((![) !*lsqbkt!*);      % Strange to have both of these the same!
newtok '((!< !<) !*lsqbkt!*);   %
newtok '((!>) greaterp);
newtok '((!> !=) geq);
newtok '((!]) !*rsqbkt!*);      % Strange to have both of these the same!
newtok '((!> !>) !*rsqbkt!*);   %
newtok '((!/ !*) !*comment!*);


% The following is the collection of all uses of newtok from modules
% throughout Reduce. I have prefixed with "%   " where there seem to be
% clashes or potential clashes. I have left the "newtok" statements that
% these are copies of in place elsewhere. Also note that at present
% "[" and "<<" ars synonyms, as are "]" and ">>". It would perhaps be
% nice to be able to re-use "[" and "]" for other purposes, and I hope
% that few if any people use "[...]" for a progn-style block of code.
%
% As well as some of the definitions here clashing as between modules
% some can clash with things other than "newtok" and cause compilation
% to fail!

newtok '((!- !- !>) repd);
%   newtok '((!- !>) rep);
%   newtok '((!- !>) mapped_to); % For now. Should only be active inside the stat.
%   newtok '((!- !>) rightarrow);
newtok '((!#) hash);
newtok '((!# !-) idifference);
newtok '((!# !*) itimes2);
newtok '((!# !/) iquotient);
newtok '((!# !+) iplus2);
newtok '((!# !<) ilessp);
newtok '((!# !=) iequal);
newtok '((!# !>) igreaterp);
%   newtok '((!&) hornand);           % also makes pm.red fail to build
%   newtok '((!& !&), and);
%   newtok '((!-) formoutminus);
%   newtok '((!-) vectordifference);
newtok '((!* !* !*) lpdotimes);
newtok '((!* !.) ldot);
%   newtok '((!*) vectortimes);
newtok '((!. !* !*) to);
newtok '((!. !* !.) crossprod);
newtok '((!. !*) mult);
newtok '((!. !. !=) myequal);
%   newtok '((!. !.) !*interval!*)
%   newtok '((!. !.) isgr);
newtok '((!. !/) over);
newtok '((!. !:) id!-quotient);
newtok '((!. !^) to);
newtok '((!. !~ !*) int_mult);
newtok '((!. !~ !+) int_add);
newtok '((!. !+) add);
newtok '((!. !=) id!-equal);
newtok '((!/ !/) slash);
newtok '((!/ !\), wedge);
%   newtok '((!/) vectorquotient);
%   newtok '((!: !-) rset);
%   newtok '((!: !-) hornrepl);
newtok '((!: !: !-) rsetd);
newtok '((!: !: != !:) lrsetq);
newtok '((!: !: !=) lsetq);
newtok '((!: !:) range);
newtok '((!: != !:) rsetq);
newtok '((!@) partdf);
newtok '((![) !*lsqb!*);
%   newtok '((!\) setdiff);
%   newtok '((!\) backslash);
newtok '((!]) !*rsqb!*);
newtok '((!^ !^) super_product);
%   newtok '((!^) vectorexpt);
%   newtok '((!^) wedge);
%   newtok '((!^) cross);
%   newtok '((!_) lnth);
%   newtok '((!_) prop!-alg);
%   newtok '((!_) vectorcomponent);
%   newtok '((!_ !|) innerprod);
%   newtok '((!_ !=) such!-that);
newtok '((!{) !*lcbkt!*);
newtok '((!}) !*rcbkt!*);
%   newtok '((!| !_) liedf);
%   newtok '((!| !|), or);
%   newtok '((!|) dotprod);       % Some of these upset pm.red
%   newtok '((!|) opapply);
%   newtok '((!+) formoutplus);   % clash with main versin of "+"
%   newtok '((!+) vectoradd);
%   newtok '((!< !>) doublearrow);% clashing values
%   newtok '((!< !>) neq);
%   newtok '((!= !=) setvalue ! !=!=!);
newtok '((!= !>) replaceby);
newtok '((!> !<) vectorcross);

% The notation #bullet; (which includes the terminating semicolon) stands
% for U+2022 and #times; is U+d7. See rtools/charname.red, and the conversion
% is arranged in rlisp/tok.red on lines near 530. So users who have Unicode
% input capability might be able to use some extended characters and the
% Reduce sources can include mention of them by name so that the source
% code remains using a limited character set.
%::
% HOWEVER note well that the "#name;" notation is not available until tok.red
% has been read - and newtok.red is processed before that. So if these two
% are to be activated that has to be in a different file that is scanned
% a bit later!
%
%   newtok '((#bullet;) dotprod);    % "#" notation not yet available
%   newtok '((#times;) crossprod);   % "#" notation not yet available
%   newtok '((|) opapply);           % upsets pm.red   In physop.red
%   newtok '((d o t) dot);           % upsets int.red? In physop.red

% ... and from here on the full set of infix operators may be used with
% their standard notation. So the ONLY files where (eg) "+" may not be used
% will be support/build.red, support/XXXprolo.red, rlisp/rlisp.red
% rlisp/module.red and this file.

put('expt,'prtch,'!*!*);   % To ensure that FORTRAN output is correct.

flag('(difference minus plus setq),'spaced);

flag('(newtok),'eval);

endmodule;

end;
