% ----------------------------------------------------------------------
% $Id: ofsfbnf.red,v 1.4 1999/03/23 07:41:37 dolzmann Exp $
% ----------------------------------------------------------------------
% Copyright (c) 1995-1999 Andreas Dolzmann and Thomas Sturm
% ----------------------------------------------------------------------
% $Log: ofsfbnf.red,v $
% Revision 1.4  1999/03/23 07:41:37  dolzmann
% Changed copyright information.
%
% Revision 1.3  1999/03/21 13:38:04  dolzmann
% Removed procedure acfsf_bnfsimpl which was identical to cl_bnfsimpl.
%
% Revision 1.2  1996/10/07 12:03:22  sturm
% Added fluids for CVS and copyright information.
%
% Revision 1.1  1996/03/22 12:14:02  sturm
% Moved and split.
%
% ----------------------------------------------------------------------
lisp <<
   fluid '(ofsf_bnf_rcsid!* ofsf_bnf_copyright!*);
   ofsf_bnf_rcsid!* := "$Id: ofsfbnf.red,v 1.4 1999/03/23 07:41:37 dolzmann Exp $";
   ofsf_bnf_copyright!* := "Copyright (c) 1995-1999 by A. Dolzmann and T. Sturm"
>>;

module ofsfbnf;
% Ordered field standard form boolean normal forms. Submodule of [ofsf].

procedure ofsf_dnf(f);
   % Ordered field standard form conjunctive normal form. [f] is a
   % formula. Returns a DNF of [f].
   if !*rlbnfsac then
      (cl_dnf f) where !*rlsiso=T
   else
      cl_dnf f;

procedure ofsf_cnf(f);
   % Ordered field standard form conjunctive normal form. [f] is a
   % formula. Returns a CNF of [f].
   if !*rlbnfsac then
      (cl_cnf f) where !*rlsiso=T
   else
      cl_cnf f;

procedure ofsf_subsumption(l1,l2,gor);
   % Ordered field standard form subsume. [l1] and [l2] are lists of
   % atomic formulas. Returns one of [imp], [rep], [nil].
   if gor eq 'or then (
      if ofsf_subsumep!-and(l1,l2) then
 	 'keep2
      else if ofsf_subsumep!-and(l2,l1) then
	 'keep1
   ) else  % [gor eq 'and]
      if ofsf_subsumep!-or(l1,l2) then
	 'keep1
      else if ofsf_subsumep!-or(l2,l1) then
	 'keep2;

procedure ofsf_subsumep!-and(l1,l2);
   % Ordered field standard form subsume [and] case. [l1] and [l2] are
   % lists of atomic formulas.
   begin scalar a;
      while l2 do <<
	 a := car l2;
	 l2 := cdr l2;
	 if cl_simpl(a,l1,-1) neq 'true then a := l2 := nil
      >>;
      return a
   end;

procedure ofsf_subsumep!-or(l1,l2);
   % Ordered field standard form subsume [or] case. [l1] and [l2] are
   % lists of atomic formulas.
   begin scalar a;
      while l1 do <<
	 a := car l1;
	 l1 := cdr l1;
	 if cl_simpl(rl_smkn('or,l2),{a},-1) neq 'true then a := l1 := nil
      >>;
      return a
   end;

procedure ofsf_sacatlp(a,l);
   % Ordered field standard form subsume and cut atomic formula list
   % predicate. [a] is an atomic formula; [l] is a list of atomic
   % formulas. [T] is returned if a subsumption or cut beween [a] and
   % an element of [l] is possible.
   not ((ofsf_arg2l a neq ofsf_arg2l w) and ordp(ofsf_arg2l a,ofsf_arg2l w))
      where w=car l;

procedure ofsf_sacat(a1,a2,gor);
   % Ordered field standard form subsume and cut atomic formula. [a1]
   % and [a2] are atomic formulas; [gor] is one of [or], [and].
   % Returns [nil], ['keep], ['keep2], ['keep1], ['drop], or an atomic
   % formula. If [nil] is returned then neither a cut nor a
   % subsumption can be applied, if [keep] is returned then the atomic
   % formuas are identical, in the case of [keep1] or [keep2] the
   % respective atomic formula must be kept but the other can be
   % dropped. If an atomic formula $a$ is returned then it is the
   % result of the cut beween [a1] and [a2], if ['drop] is returned, a
   % cut with result ['true] or ['false] can be performed.
   begin scalar w;
      if ofsf_arg2l a1 neq ofsf_arg2l a2 then return nil;
      w := ofsf_sacrel(ofsf_op a1, ofsf_op a2,gor);
      if w memq '(drop keep keep1 keep2) then return w;
      return ofsf_0mk2(w,ofsf_arg2l a1)
   end;

procedure ofsf_sacrel(r1,r2,gor);
   % Ordered field standard form subsume and cut relation. [r1] and
   % [r2] are relations; [gor] is one of [or], [and]. Returns ['keep],
   % ['keep2], ['keep1], ['drop], or a relation. [r1] and [r2] are
   % considered as relations of atomic formulas $[r1](t,0)$ and
   % $[r2](t,0)$. If [keep] is returned then the atomic formulas are
   % identical, in the case of [keep1] or [keep2] the respective
   % atomic formula must be kept but the other can be dropped, if a
   % relation $\rho$ is returned a cut with result $t\rho 0$ can be
   % performed, where $t$ is the left hand side of [a1] and [a2], if
   % ['drop] is returned, a cut with result ['true] or ['false] can be
   % performed.
   if gor eq 'or then
      ofsf_sacrel!-or(r1,r2)
   else
      ofsf_sacrel!-and(r1,r2);

procedure ofsf_sacrel!-or(r1,r2);
   % Ordered field standard form subsume and cut relation or. [r1] and
   % [r2] are relations. ['keep], ['keep2], ['keep1], ['drop], or a
   % relation is returned. [r1] and [r2] are considered as relations
   % of atomic formulas $[r1](t,0)$ and $[r2](t,0)$. If [keep] is
   % returned then the atomic formulas are identical, in the case of
   % [keep1] or [keep2] the respective atomic formula must be kept but
   % the other can be dropped, if a relation $\rho$ is returned a cut
   % with result $t\rho 0$ can be performed, where $t$ is the left
   % hand side of [a1] and [a2], if ['drop] is returned a cut with
   % result ['true] can be performed.
   begin scalar w;
      w:= '( (lessp . ( (lessp . keep) (leq . keep1) (equal . leq)
                        (neq . keep1) (geq . drop) (greaterp . neq)))
	     (leq   . ( (lessp . keep2) (leq . keep) (equal . keep2)
		        (neq . drop) (geq . drop) (greaterp . drop)))
	     (equal . ( (lessp . leq) (leq . keep1) (equal . keep)
		        (neq . drop) (geq . keep1) (greaterp . geq)))
	     (neq   . ( (lessp . keep2) (leq . drop) (equal . drop)
		        (neq . keep) (geq . drop) (greaterp . keep2)))
	     (geq   . ( (lessp . drop) (leq . drop) (equal . keep2)
		        (neq . drop) (geq . keep) (greaterp . keep2)))
	     (greaterp . ( (lessp . neq)  (leq . drop)  (equal . geq)
	             	(neq . keep1) (geq . keep1) (greaterp . keep))));
      return cdr atsoc(r1,cdr atsoc(r2,w));
   end;

procedure ofsf_sacrel!-and(r1,r2);
   % Ordered field standard form subsume and cut relation and. [r1] and
   % [r2] are relations. ['keep], ['keep2], ['keep1], ['drop], or a
   % relation is returned. [r1] and [r2] are considered as relations
   % of atomic formulas $[r1](t,0)$ and $[r2](t,0)$. If [keep] is
   % returned then the atomic formulas are identical, in the case of
   % [keep1] or [keep2] the respective atomic formula must be kept but
   % the other can be dropped, if a relation $\rho$ is returned a cut
   % with result $t\rho 0$ can be performed, where $t$ is the left
   % hand side of [a1] and [a2], if ['drop] is returned a cut with
   % result ['false] can be performed.
   begin scalar w;
      w:= '( (lessp . ( (lessp . keep) (leq . keep2) (equal . drop)
                        (neq . keep2) (geq . drop) (greaterp . drop)))
	     (leq   . ( (lessp . keep1) (leq . keep) (equal . keep1)
		        (neq . lessp) (geq . equal) (greaterp . drop)))
	     (equal . ( (lessp . drop) (leq . keep2) (equal . keep)
		        (neq . drop) (geq . keep2) (greaterp . drop)))
	     (neq   . ( (lessp . keep1) (leq . lessp) (equal . drop)
		        (neq . keep) (geq . greaterp) (greaterp . keep1)))
	     (geq   . ( (lessp . drop) (leq . equal) (equal . keep1)
		        (neq . greaterp) (geq . keep) (greaterp . keep1)))
	     (greaterp . ( (lessp . drop)  (leq . drop)  (equal . drop)
	             	(neq . keep2) (geq . keep2) (greaterp . keep))));
      return cdr atsoc(r1,cdr atsoc(r2,w));
   end;

endmodule;  % [ofsfbnf]

end;  % of file
