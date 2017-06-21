module order; % Functions for internal ordering of expressions.

% Author: Anthony C. Hearn.

% Copyright (c) 1999 Anthony C. Hearn.  All rights reserved.

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


fluid '(kord!*);
global '(!*physop!-loaded);

% symbolic procedure ordad(a,u);
%   if null u then list a
%    else if ordp(a,car u) then a . u
%    else car u . ordad(a,cdr u);

% This definition, due to A.C. Norman, avoids recursion.

symbolic procedure ordad(a,u);
   begin scalar r;
      while u and not ordp(a,car u) do <<r := car u . r; u := cdr u>>;
      u := a . u;
      while r do <<a := cdr r; rplacd(r,u); u := r; r := a>>;
      return u
   end;

symbolic procedure ordn u;
   if null u then nil
    else if null cdr u then u
    else if null cddr u then ord2(car u,cadr u)
    else ordad(car u,ordn cdr u);

symbolic procedure ord2(u,v);
   if ordp(u,v) then list(u,v) else list(v,u);



#if (not (memq 'csl lispsystem!*))

% A version of ordp is provided built-in to CSL and the version there
% is intended to behave just the way that this does. Now until recently I
% had used a LOSE flag to make that the version that got used. However both
% helphy/noncom2 and spde/spde redefine ordp - and if I use a LOSE flag
% then their redefinitions get discarded as well as this one. Hence I am
% moving to the ugly and somwhat unsatisfactory use of #if. A better
% resolution will be to arrange that neither hephys nor spde redefine
% this function! But doing that might require that the version within
% CSL be updated to include the changes that they want.

% I will put a copy of the version from hephys/noncom2.red first, but
% commented out. This is to encourage a merge operation! I suspect that
% the regular and the hephys versions could be merged with a bit of thought.

%hephys% symbolic procedure ordp(u,v); % modified
%hephys%    %returns true if u ordered ahead or equal to v, nil otherwise.
%hephys%    %an expression with more structure at a given level is ordered
%hephys%    % behind (and not ahead) of one with less;
%hephys%    % ordering of numbers is left as default
%hephys%    if null u then t
%hephys%    else if null v then nil
%hephys%    else if vectorp u then if vectorp v then ordpv(u,v) else atom v
%hephys%    else if atom u then
%hephys%            if atom v then
%hephys%               if numberp u then
%hephys%                   if numberp v then not(u < v)
%hephys%                   else t
%hephys%               else if numberp v then nil
%hephys%                    else orderp(u,v)
%hephys%            else t
%hephys%     else if atom v then nil
%hephys%     else if car u=car v then ordpl(cdr u,cdr v)
%hephys%     else if flagp(car u,'noncom)
%hephys%      then if flagp(car v,'noncom) then ordp(car u, car v) else t
%hephys%     else if flagp(car v,'noncom) then nil
%hephys%     else ordp(car u,car v);

% The variant from spde seems to be amazingly different and specialized,
% and it looks to me as if I would be a lot harder to merge with it.
% Issues of the general "setkorder" mechanism and its interaction with
% spde would need to be considered too! Note that loading spde will
% have an impact on any attempt to use non-commuting quantities.

%spde% remflag('(ordp ordpa),'lose);   % We must use these definitions.
%spde%
%spde% symbolic procedure ordp(u,v)$
%spde% %Modified ordering function which orders kernels with CAR parts;
%spde% %DF, ETA, XI and C ahead of anything else;
%spde% if null u then null v else if null v then t else
%spde% if eq(u,'df) or eq(u,'eta) and not eq(v,'df)
%spde% or eq(u,'xi) and not(eq(v,'df) or eq(v,'eta))
%spde% or eq(u,'c) and not(eq(v,'df) or eq(v,'eta) or eq(v,'xi)) then t else
%spde% if eq(u,'eta) and eq(v,'df)
%spde% or eq(u,'xi) and (eq(v,'df) or eq(v,'eta))
%spde% or eq(u,'c) and (eq(v,'df) or eq(v,'eta) or eq(v,'xi))
%spde% or eq(v,'df) or eq(v,'eta) or eq(v,'xi) or eq(v,'c) then nil else
%spde% if atom u then if atom v then
%spde% if numberp u then numberp v and not(u<v) else
%spde% if numberp v then t else orderp(u,v) else nil else
%spde% if atom v then t else
%spde% if car u=car v then ordp(cdr u,cdr v) else ordp(car u,car v)$
%spde%
%spde% symbolic procedure ordpa(u,v); ordp(u,v);



symbolic procedure ordp(u,v);
   % Returns TRUE if U ordered ahead or equal to V, NIL otherwise.
   % An expression with more structure at a given level is ordered
   % ahead of one with less.
   if null u then null v
    else if null v then t
    else if vectorp u then if vectorp v then ordpv(u,v) else atom v
    else if atom u
       then if atom v
                then if numberp u then numberp v and not(u<v)
                      else if idp v then orderp(u,v)
                      else numberp v
             else nil
    else if atom v then t
    else if car u=car v then ordpl(cdr u,cdr v)
    else if flagp(car u,'noncom)
     then if flagp(car v,'noncom) then ordp(car u, car v) else t
    else if flagp(car v,'noncom) then nil
    else ordp(car u,car v);

#endif

symbolic procedure ordpl(u,v);
   % Returns TRUE if list U ordered ahead or equal to V, NIL otherwise.
   % We also allow for a dotted pair.
   if atom u then ordp(u,v)
    else if atom v then t
    else if car u=car v then ordpl(cdr u,cdr v)
    else ordp(car u,car v);

symbolic procedure ordpv(u,v);
   % U and v are vectors. Set up comparison loop.
   ordpv1(u,v,-1,upbv u,upbv v);

symbolic procedure ordpv1(u,v,i,lu,lv);
   if (i:=i#+1)>lu then i>lv
    else (if x=y then ordpv1(u,v,i,lu,lv) else ordp(x,y))
          where x=getv(u,i),y=getv(v,i);

symbolic procedure ordop(u,v);
   if !*physop!-loaded then physop!-ordop(u,v)
   else begin scalar x;
        x := kord!*;
    a:  if null x then return ordp(u,v)
         else if u eq car x then return t
         else if v eq car x then return;
        x := cdr x;
        go to a
   end;

symbolic procedure ordpp(u,v);
   % This version is used for addition, where NONCOM properties aren't
   % relevant.
   begin scalar x;
        if car u eq car v then return cdr u>cdr v;
        x := kord!*;
        u := car u;
        v := car v;
    a:  if null x then return ordpa(u,v)
         else if u eq car x then return t
         else if v eq car x then return nil;
        x := cdr x;
        go to a
   end;

symbolic procedure ordpa(u,v);
   % Returns TRUE if U ordered ahead or equal to V, NIL otherwise.
   % An expression with more structure at a given level is ordered
   % ahead of one with less.
   if null u then null v
    else if null v then t
    else if vectorp u then if vectorp v then ordpv(u,v) else atom v
    else if atom u
       then if atom v
                then if numberp u then numberp v and not(u<v)
                      else if idp v then orderp(u,v)
                      else numberp v
             else nil
    else if atom v then t
    else if car u=car v then ordpa(cdr u,cdr v)
    else ordpa(car u,car v);

endmodule;

end;
