module polyop; % Functions for algebraic mode operations on polynomials.

% Author: Anthony C. Hearn.

% Modified by: F. Kako, F.J. Wright.

% Copyright (c) 1995 RAND. All rights reserved.

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


% This code has been modified to be consistent with the rules

%      lterm(f,x) = lcof(f,x)*lpower(f,x)
%      f = lterm(f,x) + reduct(f,x)

fluid '(!*ratarg gdmode!*);

symbolic procedure deg(u,kern);
   <<u := simp!* u; tstpolyarg2(u,kern); numrdeg(numr u,kern)>>
     where dmode!* = gdmode!*;

% totaldeg(u, kernlist) find the total degree of the polynomial u in
% the variables in kernlist. If kernlist is not a list it is treated
% as a simple single variable.
% The denominator of u is ignored, and "degree" here does not may attention
% to fractional powers. Mentions of a kernel within the argument to any
% operator or function (eg sin, cos, log, sqrt) are ignored. Really u is
% expected to be just a polynomial.
%
% Eg:
%   totaldeg(a*x^2+b*x+c, x)  => 2
%   totaldeg(a*x^2+b*x+c, {a,b,c})  => 1
%   totaldeg(a*x^2+b*x+c, {x, a})  => 3
%   totaldeg(a*x^2+b*x+c, {x,b})  => 2
%   totaldeg(a*x^2+b*x+c, {p,q,r})  => 0

symbolic procedure totaldeg(u,kernlist);
  begin
    scalar n;
    u := numr simp!* u;
    kernlist := prepsq simp!* kernlist;
    if eqcar(kernlist, 'list) then kernlist := cdr kernlist
    else kernlist := list kernlist;
    n := totaldeg1(u, kernlist, 0);
    return n;
  end;

symbolic procedure totaldeg1(u, kernlist, above);
  begin
    scalar r;
    r := above;
    while not domainp u do <<
      if member(mvar u, kernlist) then
        r := max2(r, totaldeg1(lc u, kernlist, above+ldeg u))
      else r := max2(r, totaldeg1(lc u, kernlist, above));
      u := red u >>;
    return r
  end;

symbolic procedure tstpolyarg2(u,kern);
 <<for each j in kernels numr u do
      if j neq kern and depends(j,kern)
        then typerr(prepsq u,"polynomial");
   for each j in kernels denr u do
      if depends(j,kern) then typerr(prepsq u,"polynomial")>>;

symbolic procedure numrdeg(u,kern);
   begin scalar x;
      kern := !*a2k kern;
      if domainp u then return 0
       else if mvar u eq kern then return !*f2a ldeg u;
      x := updkorder kern;
      u := reorder u;
      if not(mvar u eq kern) then u := 0 else u := ldeg u;
      setkorder x;
%     return !*f2a u
      return u
   end;

symbolic procedure lcofeval u;
   begin scalar kern,x,y;
      if null u or null cdr u or not null cddr u
        then rerror(poly,280,
                    "LCOF called with wrong number of arguments");
      kern := !*a2k cadr u;
      u := simp!* car u;
      y := denr u;
      tstpolyarg(y,u);
      u := numr u;
%     if domainp u then return if null u then 0 else mk!*sq (u . 1)
      if domainp u then return if null u then 0 else !*ff2a(u,y)
       else if mvar u eq kern then return !*ff2a(lc u,y);
      x := updkorder kern;
      u := reorder u;
      if mvar u eq kern then u := lc u;
      setkorder x;
      return if null u then 0 else !*ff2a(u,y)
   end;

put('lcof,'psopfn,'lcofeval);

% Note. This is an older definition still used by some packages.

symbolic procedure lcof(u,kern);
   begin scalar x,y;
      u := simp!* u;
      y := denr u;
      tstpolyarg(y,u);
      u := numr u;
      kern := !*a2k kern;
      if domainp u then return 0
       else if mvar u eq kern then return !*ff2a(lc u,y);
      x := updkorder kern;
      u := reorder u;
      if mvar u eq kern then u := lc u;
      setkorder x;
      return if null u then 0 else !*ff2a(u,y)
   end;

symbolic procedure lpower(u,kern);
   begin scalar x,y;
      u := simp!* u;
      y := denr u;
      tstpolyarg(y,u);
      u := numr u;
      kern := !*a2k kern;
%     if domainp u then return 1
      if domainp u then return !*ff2a(1,y)
       else if mvar u eq kern then return !*ff2a(lpow u.*1 .+ nil,y);
      x := updkorder kern;
      u := reorder u;
      if mvar u eq kern then u := lpow u.*1 .+ nil else u := 1;
      setkorder x;
      return !*ff2a(u,y)
   end;

symbolic procedure lterm(u,kern);
   begin scalar x,y;
      u := simp!* u;
      y := denr u;
      tstpolyarg(y,u);
      u := numr u;
      kern := !*a2k kern;
%     if domainp u then return if null u then 0 else u
      if domainp u then return if null u then 0 else !*ff2a(u,y)
       else if mvar u eq kern then return !*ff2a(lt u .+ nil,y);
      x := updkorder kern;
      u := reorder u;
%     if mvar u eq kern then u := lt u .+ nil else u := nil;
      if mvar u eq kern then u := lt u .+ nil;
      setkorder x;
      u := reorder u;
      return !*ff2a(u,y)
   end;

% symbolic procedure !*lterm u; lt u .+ nil;

symbolic procedure mainvar u;
   if domainp(u := numr simp!* u) then 0
    else sfchk(u := mvar u);

symbolic procedure sfchk u; if sfp u then prepf u else u;

symbolic procedure reduct(u,kern);
   begin scalar x,y;
      u := simp!* u;
      y := denr u;
      tstpolyarg(y,u);
      u := numr u;
      kern := !*a2k kern;
%     if domainp u then return !*ff2a(u,y)
      if domainp u then return 0
       else if mvar u eq kern then return !*ff2a(cdr u,y);
      x := updkorder kern;
      u := reorder u;
%     if mvar u eq kern then u := cdr u;
      if mvar u eq kern then u := cdr u else u := nil;
      setkorder x;
      u := reorder u;
      return !*ff2a(u,y)
   end;

symbolic procedure tstpolyarg(y,u);
   null !*ratarg and y neq 1 and typerr(prepsq u,"polynomial");

% symbolic operator deg,totaldeg,lpower,lterm,mainvar,reduct;

flag('(deg totaldeg lpower lterm mainvar reduct),'opfn); % This way for booting.

endmodule;

end;
