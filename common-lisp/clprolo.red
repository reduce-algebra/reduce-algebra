% module clprolo;  % CL dependent code for REDUCE.

% Author: Anthony C. Hearn.
% Modified by FJW for REDUCE on Common Lisp via "sl-on-cl.lisp".
% Time-stamp: <2026-02-20 12:45:55 franc>
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

% endmodule;

end;
