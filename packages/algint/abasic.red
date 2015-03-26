module abasic;   % Basic definitions for algebraic function integrator.

% Author: James H. Davenport.

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


% Modifications by: Anthony C. Hearn.

fluid '(!*conscount !*noextend);

global '(initl!* list!-of!-medium!-primes sqrts!-mod!-8);

initl!* := append('(!*noextend), initl!*);

!*conscount:=10000; % Default maximum number of conses in certain
                    % operations;

list!-of!-medium!-primes:='(101 103 107 109);   % Used in MODLINEQ

sqrts!-mod!-8:=mkvect 7;

putv(sqrts!-mod!-8,0,t);

putv(sqrts!-mod!-8,1,t);

putv(sqrts!-mod!-8,4,t);

put('nthroot,'simpfn,'simpiden);
% The binary n-th root operator NTHROOT(X,2)=SQRT(X)
% no simplification is used here;
% hope is that pbuild introduces it, and simplog removes it;

symbolic inline procedure !*kk2q a; ((mksp(a,1) .* 1) .+ nil) ./ 1;

symbolic inline procedure divsf(u,v); sqrt2top(u ./ v);

symbolic procedure int!-sqrt u;
   % Integer square root function;
   begin scalar x,y;
      x := sqrt u;
      if fixp x then return x
       else if x = float(y := fix x) then return y else return x
   end;

symbolic inline procedure maninp(u,v,w);
   interr "MANINP called -- not implemented";


% Selectors for the taylor structure:

% ***STORE-HACK-1***;
% remove this macro if more store is available;

symbolic inline procedure tayshorten u;nil;

symbolic inline procedure taylordefn u; car u;

symbolic inline procedure taylornumbers u; cadr u;

symbolic inline procedure taylorfirst u; caadr u;

symbolic inline procedure taylorlast u; cdadr u;

symbolic inline procedure taylorlist u; cddr u;

%function.((first.last computed so far)
%       .assoc list of computed terms);

symbolic inline procedure taylormake(fn,nums,alist); fn.(nums.alist);

endmodule;

end;

