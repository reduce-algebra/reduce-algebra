% ----------------------------------------------------------------------
% $Id$
% ----------------------------------------------------------------------
% (c) 2016 T. Sturm
% ----------------------------------------------------------------------
% Redistribution and use in source and binary forms, with or without
% modification, are permitted provided that the following conditions
% are met:
%
%    * Redistributions of source code must retain the relevant
%      copyright notice, this list of conditions and the following
%      disclaimer.
%    * Redistributions in binary form must reproduce the above
%      copyright notice, this list of conditions and the following
%      disclaimer in the documentation and/or other materials provided
%      with the distribution.
%
% THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
% "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
% LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
% A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
% OWNERS OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
% SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
% LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
% DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
% THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
% (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
% OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
%

module rltypes;

rl_type {name = Integer, a2s = rl_a2sInteger, s2a = rl_s2aInteger};

procedure rl_a2sInteger(n);
   % Algebraic to symbolic number.
   begin
      n := reval n;
      if not numberp n then typerr(n,"number");
      return n
   end;

procedure rl_s2aInteger(n);
   n;

rl_type {name = Switch, a2s = rl_a2sSwitch};

asserted procedure rl_a2sSwitch(u: Any): Boolean;
   % We expect certain keywords, which are not evaluated. In particular, the
   % only way to bind the Switch to the corresponding global switch is currently
   % not to specify anything and use the default value. This is something to
   % think about at some point.
   if u memq '(on yes true t) then
      t
   else if u memq '(off no false nil) then
      nil
   else
      rederr {"bad value", u, "for Switch; use one of on/yes/true or off/no/false"};

rl_type {name = Formula, a2s = rl_simp, s2a = rl_mk!*fof, equational};

rl_type {name = VarList, a2s = rl_a2sVarList};

procedure rl_a2sVarList(u);
   begin scalar w;
      w := reval u;
      if not eqcar(w,'list) then
         typerr(w,"list");
      w := cdr w;
      for each x in w do
	 if not kernelp x then
	    typerr(x,"variable");
      return w
   end;

asserted procedure rl_s2aVarList(l: List): List;
   'list . l;

rl_type {name = PolyList, a2s = rl_a2sPolyList};

asserted procedure rl_a2sPolyList(u: Any): SF;
   begin scalar w;
      w := reval u;
      if not eqcar(w,'list) then
         typerr(w,"list");
      w := for each x in cdr w collect numr simp x;
      return w
   end;

rl_type {name = Theory, a2s = rl_a2sAtList, s2a = rl_s2aFormulaList};

procedure rl_a2sAtList(l);
   % Algebraic to symbolic atomic formula list.
   begin scalar w,!*rlsimpl;
      l := reval l;
      if not eqcar(l,'list) then
 	 typerr(l,"list");
      return for each x in cdr l collect <<
	 if rl_cxp rl_op (w := rl_simp x) then
	    typerr(x,"atomic formula");
      	 w
      >>
   end;

procedure rl_s2aFormulaList(l);
   'list . for each x in l collect rl_mk!*fof x;

% Temporary, used with the old scheduler:
copyd('rl_a2s!-atl, 'rl_a2sAtList);
copyd('rl_s2a!-fl, 'rl_s2aFormulaList);
copyd('rl_s2a!-atl, 'rl_s2aFormulaList);
copyd('rl_a2s!-number, 'rl_a2sInteger);
copyd('rl_a2s!-sflist, 'rl_a2sPolyList);
copyd('rl_s2a!-idlist, 'rl_s2aVarList);
copyd('rl_a2s!-idlist, 'rl_a2sVarList);

endmodule;

end;
