module idepend;  % Routines for considering dependency among variables.

% Authors: Mary Ann Moore and Arthur C. Norman.

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


fluid '(taylorvariable);

exports dependspl,dependsp,involvesq,involvsf;

imports domainp;

symbolic procedure dependsp(x,v);
   if null v then t
    else if depends(x,v) then x
    else if atom x then if x eq v then x else nil
    else if car x = '!*sq then involvesq(cadr x,v)
    else if taylorp x
     then if v eq taylorvariable then taylorvariable else nil
    else begin scalar w;
       if x=v then return v;
       % Check if a prefix form expression depends on the variable v.
       % Note this assumes the form x is in normal prefix notation;
       w := x; % preserve the dependency;
       x := cdr x; % ready to recursively check arguments;
 scan: if null x then return nil; % no dependency found;
       if dependsp(car x,v) then return w;
       x:=cdr x;
       go to scan
    end;

symbolic procedure involvesq(sq,term);
   involvesf(numr sq,term) or involvesf(denr sq,term);

symbolic procedure involvesf(sf,term);
   if domainp sf or null sf then nil
    else dependsp(mvar sf,term)
       or involvesf(lc sf,term)
       or involvesf(red sf,term);

symbolic procedure dependspl(dep!-list,var);
   % True if any member of deplist (a list of prefix forms) depends on
   % var.
   dep!-list
      and (dependsp(car dep!-list,var) or dependspl(cdr dep!-list,var));

symbolic inline procedure taylorfunction u; caar u;

symbolic procedure taylorp exxpr;
   % Sees if a random entity is a taylor expression.
   not atom exxpr
       and not atom car exxpr
       and flagp(taylorfunction exxpr,'taylor);

endmodule;

end;

