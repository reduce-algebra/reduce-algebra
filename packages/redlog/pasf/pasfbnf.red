% ----------------------------------------------------------------------
% $Id: pasfbnf.red,v 1.7 2005/08/04 11:03:57 lasaruk Exp $
% ----------------------------------------------------------------------
% Copyright (c) 2002 A. Dolzmann, A. Seidl, and T. Sturm
% ----------------------------------------------------------------------
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

% $Log: pasfbnf.red,v $
% Revision 1.7  2005/08/04 11:03:57  lasaruk
% Uniform comments
%
% Revision 1.6  2005/07/17 16:34:08  lasaruk
% DNF and CNF methodes moved in. Comments rewritten.
%
% Revision 1.5  2005/01/24 16:02:07  lasaruk
% Uniform Presburger Arithmetic is now implemented. Elimination code rewritten,
% so no elimination normal form is explicitly computed.
%
% Revision 1.4  2004/08/11 15:17:07  lasaruk
% New comments done. Now automatic procedure documentation possible. 
% Some code rewritten.
%
% Revision 1.3  2003/11/05 13:27:14  lasaruk
% Some major redlog programming rules applied to the code.
% Formulas are made positive acc. to the current kernel order.
%
% Revision 1.2  2003/10/16 16:17:38  lasaruk
% Compiler error messages partially removed. All others are due
% to the noncompleteness of packet.
%
% Revision 1.1  2003/05/22 22:00:58  lasaruk
% DNF added.
% ----------------------------------------------------------------------


lisp <<
   fluid '(pasf_bnf_rcsid!* pasf_bnf_copyright!*);
   pasf_bnf_rcsid!* := "$Id: pasfbnf.red,v 1.7 2005/08/04 11:03:57 lasaruk Exp $";
   pasf_bnf_copyright!* :=
      "Copyright (c) 1995-2002 by A. Dolzmann, A. Seidl, and T. Sturm"
>>;

module pasfbnf;
% Methods for DNF and CNF computation. For now pseudo- DNF and CNF are
% computed. A pseudo DNF (CNF) is a formula in PNF with matrix in DNF (CNF).

procedure pasf_sacat(a1,a2,gor);
   % Presburger arithmetic standard form subsume and cut atomic formula. [a1]
   % is an atomic formula; [a2] is an atomic formula; [gor] is one of 'or,
   % 'and. Returns for the first trivially nil.
   nil;

procedure pasf_dnf(phi);
   % Presburger arithmetic standard form disjunctive normal form. [phi] is a
   % quantifier free frmula. Returns a pseudo DNF of [phi].
   pasf_pbnf(pasf_pnf phi,'dnf);

procedure pasf_cnf(phi);
   % Presburger arithmetic standard form conjunctive normal form. [phi] is a
   % quantifier free formula. Returns a pseudo DNF of [phi].
   pasf_pbnf(pasf_pnf phi,'cnf);

procedure pasf_pbnf(phi,flag);
   % Presburger arithmetic standard form pseudo boolean normal form
   % computation. [phi] is a formula in PNF; [flag] is one of 'dnf or
   % 'cnf. Returns a pseudo boolean normal form of [phi] according to flag.
   begin
      if rl_bquap rl_op phi then
	 return rl_mkbq(rl_op phi,rl_var phi,rl_b phi,
	    pasf_pbnf(rl_mat phi,flag));
      if rl_quap rl_op phi then
	 return  rl_mkq(rl_op phi,rl_var phi,
	    pasf_pbnf(rl_mat phi,flag));
      % Now assuming that the formula is in PNF the formula is strong
      % quantifier free
      return if flag eq 'dnf then cl_dnf phi else cl_cnf phi
   end;

endmodule; % pasfbnf

end; % of file