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

symbolic inline procedure scope_row x$
   getv(codmat,maxvar+x)$

symbolic inline procedure scope_free x$
   getv(scope_row x,0)$

symbolic inline procedure scope_wght x$
   getv(scope_row x,1)$

symbolic inline procedure awght x$
   caar(scope_wght x)$

symbolic inline procedure scope_mwght x$
   cdar(scope_wght x)$

symbolic inline procedure scope_hwght x$
   cdr(scope_wght x)$

symbolic inline procedure scope_opval x$
   getv(scope_row x,2)$

symbolic inline procedure scope_farvar x$
   getv(scope_row x,3)$

symbolic inline procedure scope_zstrt x$
   getv(scope_row x,4)$

symbolic inline procedure scope_chrow x$
   getv(scope_row x,5)$

symbolic inline procedure scope_expcof x$
   getv(scope_row x,6)$

symbolic inline procedure scope_hir x$
   getv(scope_row x,7)$

symbolic inline procedure scope_phir x$
   car(scope_hir x)$

symbolic inline procedure scope_nhir x$
   cdr(scope_hir x)$

% ------------------------------------------------------------------- ;
% Assignments in the incidence matrix                                 ;
% ------------------------------------------------------------------- ;

symbolic inline procedure scope_fillrow(x,v)$
   putv(codmat,maxvar+x,v)$

symbolic inline procedure scope_setoccup x$
   putv(scope_row x,0,nil)$

symbolic inline procedure scope_setfree x$
   putv(scope_row x,0,t)$

symbolic inline procedure scope_setwght(x,v)$
   putv(scope_row x,1,v)$


symbolic inline procedure scope_setopval(x,v)$
   putv(scope_row x,2,v)$

symbolic inline procedure scope_setfarvar(x,v)$
   putv(scope_row x,3,v)$

symbolic inline procedure scope_setzstrt(x,v)$
   putv(scope_row x,4,v)$

symbolic inline procedure scope_setchrow(x,v)$
   putv(scope_row x,5,v)$

symbolic inline procedure scope_setexpcof(x,v)$
   putv(scope_row x,6,v)$

symbolic inline procedure scope_sethir(x,v)$
   putv(scope_row x,7,v)$

symbolic inline procedure scope_setphir(x,v)$
   rplaca(scope_hir x,v)$

symbolic inline procedure scope_setnhir(x,v)$
   rplacd(scope_hir x,v)$

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
   getv(scope_row x,8)$

symbolic inline procedure setordr(x,l)$
   putv(scope_row x,8,l)$

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
