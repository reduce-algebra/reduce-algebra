module scope;  % Header module for SCOPE package.

% ------------------------------------------------------------------- ;
% Copyright : J.A. van Hulzen, Twente University, Dept. of Computer   ;
%             Science, P.O.Box 217, 7500 AE Enschede, the Netherlands.;
% Authors :   J.A. van Hulzen, B.J.A. Hulshof, W.N. Borst, M.C.       ;
%             van Heerwaarden, J.B. van Veelen.                       ;
% ------------------------------------------------------------------- ;

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


create!-package('(scope codctl restore minlngth codmat codopt codad1
                  codad2 coddec codpri codgen codhrn codstr coddom),
                % ghorner
                '(contrib scope));

% Smacro definitions for access functions.

% ------------------------------------------------------------------- ;
% Access functions for the incidence matrix                           ;
% ------------------------------------------------------------------- ;

global '(codmat maxvar)$

define lenrow=8,lencol=4;
% ------------------------------------------------------------------- ;
% Length of the rows and the columns                                  ;
% ------------------------------------------------------------------- ;

symbolic inline procedure row x$
   getv(codmat,maxvar+x)$

symbolic inline procedure free x$
   getv(row x,0)$

symbolic inline procedure wght x$
   getv(row x,1)$

symbolic inline procedure awght x$
   caar(wght x)$

symbolic inline procedure mwght x$
   cdar(wght x)$

symbolic inline procedure hwght x$
   cdr(wght x)$

symbolic inline procedure opval x$
   getv(row x,2)$

symbolic inline procedure farvar x$
   getv(row x,3)$

symbolic inline procedure zstrt x$
   getv(row x,4)$

symbolic inline procedure chrow x$
   getv(row x,5)$

symbolic inline procedure expcof x$
   getv(row x,6)$

symbolic inline procedure hir x$
   getv(row x,7)$

symbolic inline procedure phir x$
   car(hir x)$

symbolic inline procedure nhir x$
   cdr(hir x)$

% ------------------------------------------------------------------- ;
% Assignments in the incidence matrix                                 ;
% ------------------------------------------------------------------- ;

symbolic inline procedure fillrow(x,v)$
   putv(codmat,maxvar+x,v)$

symbolic inline procedure setoccup x$
   putv(row x,0,nil)$

symbolic inline procedure setfree x$
   putv(row x,0,t)$

symbolic inline procedure setwght(x,v)$
   putv(row x,1,v)$


symbolic inline procedure setopval(x,v)$
   putv(row x,2,v)$

symbolic inline procedure setfarvar(x,v)$
   putv(row x,3,v)$

symbolic inline procedure setzstrt(x,v)$
   putv(row x,4,v)$

symbolic inline procedure setchrow(x,v)$
   putv(row x,5,v)$

symbolic inline procedure setexpcof(x,v)$
   putv(row x,6,v)$

symbolic inline procedure sethir(x,v)$
   putv(row x,7,v)$

symbolic inline procedure setphir(x,v)$
   rplaca(hir x,v)$

symbolic inline procedure setnhir(x,v)$
   rplacd(hir x,v)$

% ------------------------------------------------------------------- ;
% Access functions for Z elements                                     ;
% ------------------------------------------------------------------- ;

symbolic inline procedure xind z$
   car z$

symbolic inline procedure yind z$
   car z$

symbolic inline procedure val z$
   cdr z$

symbolic inline procedure ival z$
   car val z$

symbolic inline procedure bval z$
   cdr val z$

% ------------------------------------------------------------------- ;
% Assignment functions for Z elements                                 ;
% ------------------------------------------------------------------- ;

symbolic inline procedure setival(z,v)$
   rplaca(val z,v)$

symbolic inline procedure setbval(z,v)$
   rplacd(val z,v)$

symbolic inline procedure mkzel(n,iv);
   if idp(iv) or constp(iv) then n.(iv.nil) else n.iv$
    % --------------------------------------------------------------- ;
    % Distinguish between atom and non atom for IVAL and BVAL.        ;
    % --------------------------------------------------------------- ;

% ------------------------------------------------------------------- ;
% Access functions for ordening subexpressions                        ;
% ------------------------------------------------------------------- ;

symbolic inline procedure ordr x$
   getv(row x,8)$

symbolic inline procedure setordr(x,l)$
   putv(row x,8,l)$

% ------------------------------------------------------------------- ;
% Access functions for Histogram                                      ;
% ------------------------------------------------------------------- ;

global '(codhisto)$

codhisto:=nil;

define histolen=200$

symbolic inline procedure histo x$
   getv(codhisto,x)$

symbolic inline procedure sethisto(x,v)$
   putv(codhisto,x,v)$

endmodule;

end$
