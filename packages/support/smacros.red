% module 'smacros; % In-line versions of functions from the core.


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

% Function noncomp from module poly




%symbolic smacro procedure noncomp u; !*ncmp and noncomp1 u;



% Function simpcar from module alg




%symbolic smacro procedure simpcar u; simp car u;



% Function reval from module alg




%symbolic smacro procedure reval u; reval1(u,t);



% Function delcp from module rlisp




%symbolic smacro procedure delcp u; flagp(u,'delchar);



% Function terminalp from module rlisp




%symbolic smacro procedure terminalp; !*int and null ifl!*;



% Function eofcheck from module rlisp




%symbolic smacro procedure eofcheck; 
%   program!* eq !$eof!$ and ttype!*=3 and (eof!* := eof!* + 1);



% Function exchk from module alg




%symbolic smacro procedure exchk u; exchk1(u,nil,nil,nil);



% Function negsq from module poly

%
%
%
%symbolic smacro procedure negsq u; negf car u . cdr u;
%


% Function multpq from module poly




%symbolic smacro procedure multpq(u,v); multsq({u . 1} . 1,v);



% Function domainp from module poly

%
%
%
%symbolic smacro procedure domainp u; atom u or atom car u;
%


% Function noncomfp from module poly




%symbolic smacro procedure noncomfp u; !*ncmp and noncomfp1 u;



% Function multpf from module poly




%symbolic smacro procedure multpf(u,v); multf({u . 1},v);



% Function tmsf!* from module poly

%
%
%
%symbolic smacro procedure tmsf!* u;
%   if numberp u and abs fix u=1 then 0 else tmsf u;
%


%!!!!!!! sfpf depends on sfp
%% Function sfpf from module poly
%
%
%
%
%symbolic smacro procedure sfpf u; not (atom u or atom car u) and sfp caaar u;
%


% Function sfp from module poly

%
%
%
%symbolic smacro procedure sfp u; not atom u and not atom car u;
%


% Function quotsq from module poly




%symbolic smacro procedure quotsq(u,v); multsq(u,invsq v);



% Function absf from module poly

%
%
%
%symbolic smacro procedure absf u; if minusf u then negf u else u;
%


% Function emtch from module alg

%
%
%   if atom u then u else (lambda x; if x then x else u) opmtch u;
%
%symbolic smacro procedure emtch u;
%   if atom u then u else (lambda x; if x then x else u) opmtch u;
%


% Function mchkopt from module alg

%
%
%
%symbolic smacro procedure mchkopt(u,v);
%   (lambda o; if o then mchkopt1(u,v,o)) get(car v,'optional);
%


%!!!!!!! mkbin depends on mkbin
% Function mkbin from module alg

%
%
%
%symbolic smacro procedure mkbin(u,v);
%   if null cddr v then u . v else {u,car v,mkbin(u,cdr v)};
%


%!!!!!!! noncomp!* depends on eqcar
% Function noncomp!* from module alg

%
%
%
%symbolic smacro procedure noncomp!* u;
%   !*ncmp and noncomp1 u or eqcar(u,'expt) and (!*ncmp and noncomp1 cadr u);
%


% Function noncomdel from module alg

%
%
%
%symbolic smacro procedure noncomdel(u,v);
%   if null noncomp!* u then delete(u,v) else noncomdel1(u,v);
%
%

% Function eqexpr from module alg

%
%
%
%symbolic smacro procedure eqexpr u;
%   not atom u and flagp(car u,'equalopr) and cddr u and null cdddr u;
%


% Function posintegerp from module alg

%
%
%
%symbolic smacro procedure posintegerp u; fixp u and u>0;
%
%

% Function revpr from module alg

%
%
%
%symbolic smacro procedure revpr u; cdr u . car u;
%
%

% Function aconc from module rlisp




%symbolic smacro procedure aconc(u,v); nconc(u,{v});



% Function arrayp from module rlisp




%symbolic smacro procedure arrayp u; get(u,'rtype) eq 'array;



% Function errorset!* from module rlisp




%symbolic smacro procedure errorset!*(u,v); errorset(u,v,!*backtrace);



% Function errorset2 from module rlisp

%
%
%symbolic smacro procedure errorset2 u;
%   begin scalar !*protfg;
%      declare special !*protfg;
%      !*protfg := t;
%      return errorset(u,nil,nil)
%   end;
%
%

% Function mkprog from module rlisp




%symbolic smacro procedure mkprog(u,v); 'prog . (u . v);



% Function nconc!* from module rlisp




%symbolic smacro procedure nconc!*(u,v); nconc(u,v);



% Function aconc!* from module rlisp




%symbolic smacro procedure aconc!*(u,v); nconc(u,{v});



% Function reversip!* from module rlisp




%symbolic smacro procedure reversip!* u; reversip u;



% Function rplaca!* from module rlisp




%symbolic smacro procedure rplaca!*(u,v); rplaca(u,v);



% Function rplacd!* from module rlisp




%symbolic smacro procedure rplacd!*(u,v); rplacd(u,v);



% Function lispeval from module rlisp




%symbolic smacro procedure lispeval u; eval u;



% Function !*a2f from module poly




%symbolic smacro procedure !*a2f u; !*q2f simp!* u;



% Function !*n2f from module poly

%
%
%
%symbolic smacro procedure !*n2f u; if zerop u then nil else u;
%
%

% Function !*q2a from module poly




%symbolic smacro procedure !*q2a u; !*q2a1(u,!*nosq);



% Function prin2x from module rlisp




%symbolic smacro procedure prin2x u; outl!* := u . outl!*;



end;

