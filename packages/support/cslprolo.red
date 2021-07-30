% module cslprolo;   % CSL dependent code for REDUCE.

% Author: Anthony C. Hearn.

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

% This file defines functions, variables and declarations needed to
% make REDUCE and the underlying CSL system compatible, and which need
% to be input before the system independent REDUCE source is loaded.

% Support for package creation.

symbolic procedure create!-package(u,v);
   % Make module list u into a package with path v.
   % Second argument is no longer used.
   if null idp car u then typerr(car u,"package name")
   else <<
% If building the bootstrap version report the name of each package.
      if member('cold!-start, lispsystem!*) then <<
          if !*backtrace then << !*echo := t; enable!-errorset(3,3) >>;
          terpri(); princ "+++ Creating a package: "; print car u >>;
      put(car u,'package,u);
      car u >>;

% create!-package('(cslprolo),nil);

symbolic procedure evload l;
  begin
     while l do <<
        load!-module car l;
        l := cdr l >>
  end;

% The following are built into CSL and so any definition found within
% the REDUCE sources should be viewed as "portability" but should be ignored.

% note that the elementary functions within CSL are (almost always)
% implemented using "crlibm" the "correctly rounded mathematical library"
% which is certainly higher quality than the portable code within Reduce
% and often gets more accurate answers that the elementary functions provided
% by vendors. Its use should also ensure that CSL delivers bit-identical
% results on any platform it runs on.

if memq('vsl, lispsystem!*) then
   flag('(atsoc copy eqcar gcdn geq lastpair leq mkquote neq reversip
       rplacw iplus itimes iplus2 itimes2 iadd1 isub1 iminus iminusp
       idifference iquotient iremainder ilessp igreaterp ileq igeq
       izerop ionep apply1 apply2 apply3
% modular!-difference
% modular!-minus modular!-number modular!-plus modular!-quotient
% modular!-reciprocal modular!-times modular!-expt set!-small!-modulus
% acos acosd acosh acot acotd acoth acsc acscd acsch asec asecd
% asech asin asind asinh atan atand atan2 atan2d atanh cbrt
       cos
% cosd cosh cot cotd coth csc cscd csch
       exp expt
% hypot ln
       log
% logb log10 sec secd sech
       sin
% sind sinh
       sqrt
% tan tand tanh
       fix
       ceiling floor round clrhash puthash gethash remhash
% princ!-upcase princ!-downcase
       union intersection
       threevectorp
       lengthc prin2 princ substq),'lose)
else
   flag('(atsoc copy eqcar gcdn geq lastpair leq mkquote neq reversip
       rplacw iplus itimes iplus2 itimes2 iadd1 isub1 iminus iminusp
       idifference iquotient iremainder ilessp igreaterp ileq igeq
       izerop ionep apply1 apply2 apply3 modular!-difference
       modular!-minus modular!-number modular!-plus modular!-quotient
       modular!-reciprocal modular!-times modular!-expt set!-small!-modulus
       acos acosd acosh acot acotd acoth acsc acscd acsch asec asecd
       asech asin asind asinh atan atand atan2 atan2d atanh cbrt cos
       cosd cosh cot cotd coth csc cscd csch exp expt hypot ln log
       logb log10 sec secd sech sin sind sinh sqrt tan tand tanh fix
       ceiling floor round clrhash puthash gethash remhash
       princ!-upcase princ!-downcase union intersection
       threevectorp lengthc prin2 princ substq
       string!-store1 string!-store2 string!-store3 string!-store4), 'lose);


!*argnochk := t;

% At some early stages in the bootstrapping the variable lispsystem!*
% is not available but I want to be able to tell that I am building on
% PSL as distinct from any other Lisp. This global value will help!

global '(!*psl !*csl);
!*psl := nil;
!*csl := t;

% endmodule;

end;
