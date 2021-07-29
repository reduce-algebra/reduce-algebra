module poly;  % Header module and low-level support for poly package.

% Author: Anthony C. Hearn.

% Copyright (c) 1991 RAND.  All rights reserved.

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

create!-package('(poly polrep polydiv quotf gcd exptf kernel mksp reord dmode
                 dmodeop rational rnelem gint cpxrn compopr modular
                 facform homog tdconv primfac specfac kronf conj diff
                 polyop decompos interpol subs2q subs3q subs4q horner heugcd),
                nil);

flag('(poly),'core_package);

fluid '(!*mcd !*nosq wtl!*);

% switch nosq;


% Particular infix operators used in standard forms.

flag('(newtok infix), 'eval); 

newtok '((!. !+) add);

newtok '((!. !*) mult);

newtok '((!. !^) to);

newtok '((!. !* !*) to);

newtok '((!. !/) over);

infix .^,.*,.+,./;

% Constructors and selectors for standard forms.

% Observe a function definition using infix notation here...

symbolic inline procedure u .+ v; % Standard (polynomial) addition constructor.
   u . v;

accessors lt . red, (lpow . lc) . !_, ((mvar . ldeg) . !_) . !_;

accessors tpow . tc, (tvar . tdeg) . !_;

accessors !_pvar!_ . pdeg;

accessors numr . denr;

symbolic inline procedure u .* v;  % Standard form multiplication constructor.
   u . v;

symbolic inline procedure u ./ v; % Constructor for standard quotient.
   u . v;

symbolic inline procedure domainp u; atom u or atom car u;


% Procedures for converting between parts of standard quotients and
% prefix forms.

symbolic inline procedure !*a2f u;
   % U is an algebraic expression. Value is the equivalent form
   % or an error if conversion is not possible;
   !*q2f simp!* u;

symbolic procedure !*a2k u;
   % U is an algebraic expression. Value is the equivalent kernel
   % or an error if conversion is not possible.
   % Note: earlier versions used SIMP0.
   begin scalar x;
      if kernp(x := simp!* u) then return mvar numr x
       else typerr(if null u then 0 else u,'kernel)
   end;

symbolic procedure !*a2kwoweight u;
   % U is an algebraic expression. Value is the equivalent kernel
   % neglecting any weights, or an error if conversion is not possible.
   (if kernp x then mvar numr x else typerr(u,'kernel))
    where x=simp!* u where !*uncached=t,wtl!*=nil;

symbolic procedure !*d2q u;
   % Converts domain element U into a standard quotient.
   if numberp u
     then if zerop u then nil ./ 1
   %       else if floatp u then mkfloat u ./ 1
           else u ./ 1
   % The following converts a domain rational to a SQ, which may not
   % be desirable.
   % else if eqcar(u,'!:rn!:) and !*mcd then cdr u
    else if !:zerop u then nil ./ 1 else u ./ 1;

symbolic procedure !*ff2a(u,v);
   % Converts ratio of two forms U and V to a prefix form.
   (if wtl!* then prepsq x else mk!*sq x) where x = cancel( u ./ v);

symbolic inline procedure !*f2a u; prepf u;

symbolic inline procedure !*f2q u;
   % U is a standard form, value is a standard quotient.
   u . 1;

symbolic inline procedure !*k2f u;
   % U is a kernel, value is a standard form.
   list((u .** 1) . 1);

symbolic inline procedure !*kk2f u;
   % U is a non-unique kernel, value is a standard form.
   list(mksp(u,1) . 1);

symbolic inline procedure !*kk2q u;
   % U is a non-unique kernel, value is a standard quotient.
   list(mksp(u,1) .* 1) ./ 1;

symbolic inline procedure !*k2q u;
   % U is a kernel, value is a standard quotient.
   list((u .** 1) . 1) . 1;

symbolic inline procedure !*n2f u;
   % U is a number. Value is a standard form.
   if zerop u then nil else u;

symbolic inline procedure !*p2f u;
   % U is a standard power, value is a standard form.
   list(u . 1);

symbolic inline procedure !*p2q u;
   % U is a standard power, value is a standard quotient.
   list(u . 1) . 1;

symbolic inline procedure !*q2a u;
   % U is a standard quotient, value is an algebraic expression.
   !*q2a1(u,!*nosq);

symbolic procedure !*q2a1(u,v);
   if null v then mk!*sq u else prepsqxx u;

symbolic procedure !*q2f u;
   % U is a standard quotient, value is a standard form.
   if denr u=1 then numr u else typerr(prepsq u,'polynomial);

symbolic procedure !*q2k u;
   % U is a standard quotient, value is a kernel or an error if
   % conversion not possible.
   if kernp u then mvar numr u else typerr(prepsq u,'kernel);

symbolic inline procedure !*t2f u;
   % U is a standard term, value is a standard form.
   list u;

symbolic inline procedure !*t2q u;
   % U is a standard term, value is a standard quotient.
   list u . 1;

endmodule;

end;
