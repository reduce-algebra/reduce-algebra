% module clprolo;  % CL dependent code for REDUCE.

% Author: Anthony C. Hearn.
% Modified by FJW for REDUCE on Common Lisp via "sl-on-cl.lisp".
% Time-stamp: <2025-10-08 16:27:59 franc>
% The standard version is "packages/support/pslprolo.red".

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% Redistribution and use in source and binary forms, with or without           %
% modification, are permitted provided that the following conditions are met:  %
%                                                                              %
%    * Redistributions of source code must retain the relevant copyright       %
%      notice, this list of conditions and the following disclaimer.           %
%    * Redistributions in binary form must reproduce the above copyright       %
%      notice, this list of conditions and the following disclaimer in the     %
%      documentation and/or other materials provided with the distribution.    %
%                                                                              %
% THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"  %
% AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE    %
% IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE   %
% ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNERS OR CONTRIBUTORS BE    %
% LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR          %
% CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF         %
% SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS     %
% INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN      %
% CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)      %
% ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE   %
% POSSIBILITY OF SUCH DAMAGE.                                                  %
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

% This file defines functions, variables and declarations needed to
% make REDUCE and the underlying CL system compatible, and which need
% to be input before the system independent REDUCE source is loaded.

fluid '(!*savedef !*gc!-hook!* !*noinlines);

global '(!*psl !*csl);                  % CL is neither
!*psl := t;                             % but pretend to be PSL!

% NB: !*psl is used dynamically and essentially in readch1 in
% "rlisp/tok.red" (and statically in code that is ignored in
% "rlisp/switch.red").

% Support for package creation.

symbolic procedure create!-package(u,v);
   % Make module list u into a package with path v.
   % Second argument is no longer used.
   if null idp car u then typerr(car u,"package name")
   else <<
      put(car u,'package,u);
%     put(car u,'path,if null v then list car u else v);
      car u >>;

% create!-package('(clprolo),nil);

symbolic procedure evload l;
   % Modified from cslprolo.red (which calls load!-module, not load).
   % Written like this because load is defined as a statement in
   % "rlisp/module.red".  Might be better defined in "sl-on-cl.lisp".
   while l do << apply(function load, list car l); l := cdr l >>;

flag('(concat), 'variadic);

% This useful utility function is defined in sl-on-cl:
flag('(eqcar),'lose);

% The SL definition of PRINC is not used in REDUCE since PRINC is
% redefined in rlisp/rsupport.red as
% symbolic procedure princ u; prin2 u;
% so I define it as an alias for PRIN2 in sl-on-cl.lisp:
flag('(princ),'lose);

% These functions are already defined (more or less) in Common Lisp:
flag('(first second third rest lastpair lastcar nth pnth reversip
   evenp oddp symbol!-name),'lose);

% These functions are defined in rlisp/tok.red, but I have
% re-implemented them in sl-on-cl.lisp:
flag('(list2widestring widestring2list
   % The following are only used by the above:
   string!-store1 string!-store2 string!-store3 string!-store4
      moan!-if!-not!-follower moan!-if!-truncated),'lose);

% These small integer (fixnum) operators are defined in
% alg/farith.red, but optimised versions are defined in sl-on-cl:
flag('(iplus2 itimes2 isub1 iadd1 iminus idifference
   iquotient iremainder igreaterp ilessp iminusp iequal),'lose);

% Procedure gcdn is defined in alg/numsup, and procedure lcmn is
% defined in algint/fracdi and taylor/tayutils, but these functions
% are already provided (as gcd and lcm) in Common Lisp:
flag('(gcdn lcmn),'lose);

% The definitions of geq and leq in rlisp/rsupport.red don't work
% correctly with mixed integer and float arguments because (equal 1.0
% 1) is nil in Common Lisp!  (It is also nil according to the Standard
% Lisp Report, but I suspect it is actually true in PSL and CSL!)
% However, Common Lisp provides numerical predicates >= and <= that
% correctly accept mixed-type arguments, to which I alias geq and leq,
% so...
flag('(geq leq),'lose);

% red!-char!-downcase is defined in sl-on-cl, used in rlisp/tok.red
% and redefined in several files:
flag('(red!-char!-downcase),'lose);

% orderp is defined in sl-on-cl and used in rlisp/switch; prevent it
% being redefined as it would be for PSL:
flag('(orderp),'lose);

% endmodule;

end;
