module with;   % Support for local switch settings.

% Author: Francis Wright, December 2024

% Redistribution and use in source and binary forms, with or without
% modification, are permitted provided that the following conditions
% are met:
%
%  * Redistributions of source code must retain the relevant copyright
%    notice, this list of conditions and the following disclaimer.
%
%  * Redistributions in binary form must reproduce the relevant
%    copyright notice, this list of conditions and the following
%    disclaimer in the documentation and/or other materials provided
%    with the distribution.
%
% THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
% "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
% LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS
% FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE
% COPYRIGHT OWNERS OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
% INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
% BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
% LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
% CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
% LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN
% ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
% POSSIBILITY OF SUCH DAMAGE.

% $Id$

% Define an infix operator `with' that implements the syntax

%    expression with on/off switches, on/off switches, ...

% where `on/off' is on or off and `switches' is a single switch name
% or a comma-separated sequence of switch names (as for the on and off
% commands).  The `with' operator returns the expression specified as
% its left operand evaluated and displayed subject to the switch
% settings specified as its right operand, applied locally.

% Simple test examples:

%    pi with on rounded;
%    (a+b)^2/2 with off exp, on div;

% This code is modelled on that for `where'.  See rlisp/switch.red,
% rlisp/where.red and alg/forall.red.

create!-package('(with), nil);

% With autoload in "support/entry.red":
% global '(fixedpreclis!*);
% % Set precedence immediately above setq:
% fixedpreclis!* := append(fixedpreclis!*, 'with . nil);
% mkprec();
% put('with, 'formfn, 'formwith);

symbolic procedure formwith(u,vars,mode);
   % Input: a with on b, c, d, off e, f, g;
   % u = (with a (on b c d (off e f g)))
   % vars = nil
   % mode = algebraic
   if mode eq 'symbolic then
      rederr("The WITH operator is invalid in symbolic mode.")
   else begin scalar expn, onlist, offlist, switches;
      expn := cadr u;
      u := caddr u;
      % u = (on b c d (off e f g)) etc.
      % The switches parse like this because on and off are rlistats.
      % Split this recursively nested structure into two flat lists.
      if not atom u then
         while u do <<
            if car u eq 'on then <<
               while (u := cdr u) and atom car u do
                  onlist := car u . onlist;
            >> else if car u eq 'off then <<
               while (u := cdr u) and atom car u do
                  offlist := car u . offlist;
            >> else typerr(car u, "ON/OFF in right operand of WITH");
            if u then u := car u;
         >>;
      if u then typerr(u, "right operand of WITH");
      % Construct one algebraic list containing the on and off lists:
      switches := {'list, reverse onlist, reverse offlist};
      return form1({'withexp, expn, switches}, vars, mode);
   end;

put('withexp, 'psopfn, 'evalwithexp);

fluid '(semic!*);

symbolic procedure evalwithexp u;
   % Input: a with on b, c, d, off e, f, g;
   % u = (a (list (b c d) (e f g)))
   begin scalar onlist, offlist, i;
      onlist := cadr cadr u;
      offlist := caddr cadr u;
      if i := intersection(onlist, offlist) then
         rederr {"Attempt to turn switches", i, "on and off."};
      %%write "Requested onlist = ", onlist, ", offlist = ", offlist;  terpri();
      % Check and process switches, ignoring any already set as requested:
      onlist := with!-set!-switches(onlist, t);
      offlist := with!-set!-switches(offlist, nil);
      %%write "Applied onlist = ", onlist, ", offlist = ", offlist;  terpri();
      u := mk!*sq simp!* car u;

      % Some switches affect only output display, so ensure output
      % happens here only:
      if not (semic!* eq '!$) then mathprint u;  semic!* := '!$;
      % *** THIS DOESN'T DISPLAY ASSIGNMENTS, ONLY THEIR VALUES! ***

      % Reset switches.  On and off are "rlistats", so use apply:
      apply1('off, onlist);  apply1('on, offlist);
      return u
   end;

symbolic procedure with!-set!-switches(switchlist, onoff);
   % Ensure switches in SWITCHLIST are unique and valid, ignore
   % switches currently set to ONOFF, set the remaining switches to
   % ONOFF and return a list of them.
   begin scalar s, newlist;
      while switchlist do <<
         s := car switchlist;  switchlist := cdr switchlist;
         if not flagp(s, 'switch) then typerr(s, "switch");
         if not memq(s, switchlist) and
            not (lispeval intern list2string ('!* . explode2 s) eq onoff) then
               << onoff(s, onoff);  newlist := s . newlist >>;
      >>;
      return reversip newlist
   end;

endmodule;

end;
