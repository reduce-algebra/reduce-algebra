% ----------------------------------------------------------------------
% $Id: clbnf.red,v 1.8 1999/04/13 13:10:55 sturm Exp $
% ----------------------------------------------------------------------
% Copyright (c) 1995-1999 Andreas Dolzmann and Thomas Sturm
% ----------------------------------------------------------------------
% $Log: clbnf.red,v $
% Revision 1.8  1999/04/13 13:10:55  sturm
% Updated comments for exported procedures.
%
% Revision 1.7  1999/04/01 11:26:47  dolzmann
% Reformatted one procedure.
%
% Revision 1.6  1999/03/22 17:07:12  dolzmann
% Changed copyright information.
% Reformatted comments.
%
% Revision 1.5  1999/03/21 13:34:06  dolzmann
% Corrected comments.
%
% Revision 1.4  1996/10/07 11:45:47  sturm
% Added fluids for CVS and copyright information.
%
% Revision 1.3  1996/07/13 10:53:07  dolzmann
% Added black box implementations cl_bnfsimpl, cl_sacatlp, and cl_sacat.
%
% Revision 1.2  1996/07/07 14:34:19  sturm
% Turned some cl calls into service calls.
%
% Revision 1.1  1996/03/22 10:31:27  sturm
% Moved and split.
%
% ----------------------------------------------------------------------
lisp <<
   fluid '(cl_bnf_rcsid!* cl_bnf_copyright!*);
   cl_bnf_rcsid!* := "$Id: clbnf.red,v 1.8 1999/04/13 13:10:55 sturm Exp $";
   cl_bnf_copyright!* := "(c) 1995-1996 by A. Dolzmann and T. Sturm"
>>;

module clbnf;
% Common logic boolean normal forms. Submodule of [cl]. This module
% provides CNF and DNF computation.

%DS
% <SG-DNF> ::= <GOR> . <SGCL>
% <SGCL> ::= (<SGCONJ>,...)
% <SGCONJ> ::= <GAND> . <SATOTVL>
% <GOR> ::= ['or] | ['and]
% <GAND> ::= ['and] | ['or] "opposite to <GOR>"
% <SATOTVL> ::= (<TRUTH VALUE>) | (<ATOMIC FORMULA>, ...)

procedure cl_dnf(f);
   % Common logic disjunctive normal form. [f] is a formula. Returns a
   % DNF of [f].
   rl_simpl(cl_gdnf(f,'or),nil,-1);

procedure cl_cnf(f);
   % Common logic conjunctive normal form. [f] is a formula. Returns a
   % CNF of [f].
   rl_simpl(cl_gdnf(f,'and),nil,-1);

procedure cl_gdnf(f,gor);
   % Common logic generic disjunctive normal form. [f] is a formula;
   % [gor] is one of [and], [or]. Returns a G-DNF of [f].
   begin scalar strictgdnf,gdnf,svrlsiexpla;
      f := rl_simpl(rl_nnf f,nil,-1);
      svrlsiexpla := !*rlsiexpla;
      !*rlsiexpla := nil;
      (strictgdnf := cl_strict!-gdnf(f,gor)) where !*rlbnfsm=nil;
      if !*rlbnfsm then
	 strictgdnf := gor . cl_subsume(rl_argn strictgdnf,gor);
      !*rlsiexpla := svrlsiexpla;
      gdnf := cl_unstrict(strictgdnf,gor);
      return gdnf
   end;

procedure cl_strict!-gdnf(f,gor);
   % Common logic strict generic disjunctive normal form. [f] is a
   % formula; [gor] is one of [and], [or]. Returns a strict g-DNF,
   % i.e. a formula upto unary [and]'s and [or]'s, which is in g-DNF.
   begin scalar w;
      w := cl_mkstrict(rl_simpl(cl_strict!-gdnf1(f,gor),nil,-1),gor);
      return rl_bnfsimpl(w,gor)
   end;

procedure cl_subsume(gcl,gor);
   % Common logic subsume. [gcl] is a generic conjunction list; [gor]
   % is one of [and], [or]. Returns a generic conjunction list
   % equivalent to [gcl]. Performs simplification by subsumption.
   begin scalar w;
      if null gcl or null cdr gcl then return gcl;
      w := cl_subsume1(gcl,gor);
      if car w then <<
	 cddr w := cl_subsume(cddr w,gor);
	 return cdr w
      >>;
      return cl_subsume(cdr w,gor)
   end;

procedure cl_subsume1(gcl,gor);
   % Common logic subsume 1. [gcl] is a generic conjunction list;
   % [gor] is one of [and], [or]. A pair $(c,l)$ is returned, where
   % $c$ is [nil] or a list of atomic formulas and $l$ is a generic
   % conjunction list. [gcl] is modified. The subsumption relation
   % beween [car gcl] and all elements of [cdr gcl] is tested. If $c$
   % is nil, [car gcl] was suberflous. $l$ is the modified [gcl] in
   % which all superflous conjunctions are deleted. If $c$ is non-nil,
   % it is [car gcl] and [car gcl] cannot be dropped. If [cl_setrel]
   % is used this requires, that [!*rlsiso] and [!*rlidentify] are on.
   begin scalar a,w,x,scgcl,oscgcl;
      x := cdar gcl;
      oscgcl := gcl;
      scgcl := cdr gcl;
      while scgcl do <<
	 a := car scgcl; scgcl := cdr scgcl;
	 w := if !*rlbnfsm then
 	    rl_subsumption(x,cdr a,gor)
 	 else
 	    cl_setrel(x,cdr a,gor);
	 if w eq 'keep1 then
	    cdr oscgcl := scgcl
	 else if w eq 'keep2 then
	    x := scgcl := nil
	 else
	    oscgcl := cdr oscgcl
      >>;
      if null x then gcl := cdr gcl;
      return x . gcl
   end;

procedure cl_setrel(l1,l2,gor);
   % Common logic set relation. [l1] and [l2] are list of atomic
   % formulas. [gor] is one of [and], [or]. Returns [nil], [keep1], or
   % [keep2]. If [l1] is a subset of [l2] [keep1] is returned; if [l2]
   % is a subset of [l1] [keep2] is returned otherwise [nil] is
   % returned.
   begin scalar state,a1,hlp;
      while l1 and l2 and car l1 eq car l2 do <<
	 l1 := cdr l1;
	 l2 := cdr l2
      >>;
      if null (l1 and l2) then <<
      	 if null (l1 or l2) then return 'keep1;  % both equal.
       	 return l2 and 'keep1 or 'keep2
      >>;
      state := 'keep1;
      if rl_ordatp(car l1,car l2) then <<
	 hlp := l1; l1 := l2; l2 := hlp;
	 state := 'keep2
      >>;
      repeat <<
	 a1 := car l1; l1 := cdr l1;
	 l2 := memq(a1,l2);
	 if null l2 then a1 := l1 := nil
      >> until null l1;
      return a1 and state
   end;

procedure cl_strict!-gdnf1(f,gor);
   % Common logic disjunctive normal form in strict representation.
   % [f] is a formula containing no first-order operators but $\land$
   % and $\lor$; [gor] is one of ['and], ['or]. Returns a strict g-DNF
   % of [f], i.e. a g-disjunction of g-conjunctions of atomic formulas
   % including unary $\lor$ and $\land$ if necessary.
   begin scalar gand,op,subgdnfl,noop,noopgdnf;
      gand := if gor eq 'or then 'and else 'or;
      op := rl_op f;
      if op eq gor then
	 return rl_mkn(gor,for each subf in rl_argn(f) join
	    rl_argn(cl_strict!-gdnf(subf,gor)));
      if op eq gand then <<
	 subgdnfl := for each subf in rl_argn(f) collect
	    cl_strict!-gdnf(subf,gor);
	 % Switch to noop form.
	 noop := for each subf in subgdnfl collect
	    for each gconj in rl_argn subf collect rl_argn gconj;
	 % Computing the cartesian product of the conjunctive lists is
	 % now equivalent to an application of the law of
	 % distributivity, though the result is not flat yet.
	 noopgdnf := cl_bnf!-cartprod noop;
	 % Switch back to our normal representation.
	 return rl_mkn(gor,for each gconj in noopgdnf collect
	    rl_mkn(gand,for each x in gconj join append(x,nil)))
      >>;
      if rl_cxp op and not rl_tvalp op then
      	 rederr {"cl_strict!-gdnf: illegal operator",op,"in BNF computation"};
      return rl_mkn(gor,{rl_mkn(gand,{f})})
   end;

procedure cl_mkstrict(f,gor);
   % Common logic make strict. [f] is a g-DNF. Returns a strict g-DNF,
   % possibly including one truth value.
   begin scalar op,gand;
      gand := cl_flip gor;
      op := rl_op f;
      if not rl_cxp op or rl_tvalp op then
 	 return rl_mkn(gor,{rl_mkn(gand,{f})});
      if op eq gand then
 	 return rl_mkn(gor,{f});
      if op neq gor then
 	 rederr {"BUG IN cl_mkstrict"};
      return rl_mkn(gor,for each subf in rl_argn f collect
	 if rl_op subf eq gand then subf else rl_mkn(gand,{subf}))
   end;

procedure cl_unstrict(sgdnf,gor);
   % Common logic unstrict, [sdnf] is a sg-DNF; [gor] is one of [and],
   % [or]. Returns a g-DNF.
   rl_smkn(gor,for each conj in rl_argn sgdnf collect
      % A unary g-and does not have a cddr, ignore it.
      if cdr rl_argn conj then conj else car rl_argn conj);


procedure cl_bnf!-cartprod(s);
   % Common logic boolean normal form cartesian product. [s] is a list
   % $(s_1,...,s_n)$ of lists. Returns $s_1 \times ... \times s_n$ as
   % a list of $n$-element lists. The empty set and singletons are
   % their own cartesian product.
   if null s or null cdr s then s else cl_bnf!-cartprod1 s;

procedure cl_bnf!-cartprod1(s);
   % Common logic boolean normal form cartesian product. [s] is a list
   % $(s_1,...,s_n)$ of lists with $n \geq 2$. Returns $s_1 \times ...
   % \times s_n$ as a list of $n$-element lists.
   begin scalar w;
      if null cdr s then
      	 return for each m in car s collect {m};
      w := cl_bnf!-cartprod1 cdr s;
      return for each m in car s join
      	 for each y in w collect m . y
   end;

procedure cl_sac(sgdnf,gor);
   % Common logic subsumption and cut. [sgdnf] is a sg-DNF; [gor] is
   % one of [or], [and]. Returns a sg-DNF equivalent to [sgdnf]. This
   % procedures performs simplifications based on order theoretical
   % subsumption and cut. There are no possible applications of order
   % theoretical subsumption and cut between subformulas of the
   % returned sg-DNF.
   begin scalar w,gand;
      if rl_tvalp car rl_argn car rl_argn sgdnf then return sgdnf;
      gand := cl_flip(gor);
      % switch to noop form
      w := for each x in rl_argn sgdnf collect
	 rl_argn x;
      w := cl_applysac(w,gor);
      if w eq 'break then
	 return rl_mkn(gor,{rl_mkn(gand,{cl_cflip('true,gor eq 'or)})});
      w := for each x in w join
	 if x then
	    {rl_mkn(gand,x)}
	 else
	    nil;
      if null w then
	 return rl_mkn(gor,{rl_mkn(gand,{cl_cflip('true,gor eq 'or)})});
      return gor . w
   end;

procedure cl_applysac(l,gor);
   % Common logic apply subsumption and cut. [l] is a list of lists of
   % atomic formulas; [gor] is one of [or], [and]. Returns ['break] or
   % a list $k$ of list of atomic formulas. If ['break] is returned
   % [l] is as a g-DNF equivalent to ['true] in case of ['gor eq 'or]
   % and equivalent to ['false] in case ['gor eq 'and]. The lists are
   % considered as generic disjunctive normal forms and are in this
   % sense equivalent. There is no possible application of order
   % theoretical subsumption or cut between elements of $k$.
   begin scalar w,ll,res;
      ll := l;
      while ll do <<
	 w := cl_applysac1(car ll,res,gor);
	 if w eq 'break then <<
	    ll := nil;
	    res := 'break
	 >> else <<
	    ll := cdr ll;
	    if car w then
	       res := cdar w . cdr w
	    else
	       res := cdr w
	 >>
      >>;
      return res
   end;

procedure cl_applysac1(c,l,gor);
   % Common logic apply subsumption and cut 1. [c] is a list of atomic
   % formulas; [l] is a list of list of atomic formulas; [gor] is one
   % of [or], [and]. Returns ['break] or a pair $(c' . \lambda)$. If
   % ['break] is returned [l] is as a g-DNF equivalent to ['true] in
   % case of ['gor eq 'or] and equivalent to ['false] in case ['gor eq
   % 'and]. $c'$ is either [nil] or a pair $(\tau . \gamma)$, where
   % $\tau$ is one of [T] and [nil] and $\gamma$ is a list of atomic
   % formulas. $\lambda$ is a list of list of atomic formulas. If $c'$
   % is [nil] then the conjunction over [c] is implied by a
   % conjunction over an element in [l]. If $\tau$ is [T] then
   % $\gamma$ is equal to $c$, otherwise $\gamma$ is the result of a
   % cut between $c$ and an element of $l$. In all cases there is no
   % possible application of subsumption or cut between $\gamma$ and
   % an arbitrary element of $\lambda$. [l] is modified.
   begin scalar w,flg;
      flg:=T;
      repeat <<
	 w := cl_applysac2(c,l,gor);
	 if w eq 'break then <<
	    w := '(nil);  % leave the loop
	    flg := 'break
	 >>;
	 if car w and null caar w then <<
	    flg:=nil;
	    c := cdar w;
	    l := cdr w
	 >>;
      >> until null car w or caar w;
      if flg eq 'break then
	 return 'break;
      if null car w then
	 return w;
      return (flg . cdar w) . cdr w
   end;

procedure cl_applysac2(c,l,gor);
   % Common logic apply subsumption and cut 1. [c] is a list of atomic
   % formulas; [l] is a list of list of atomic formulas; [gor] is one
   % of [or], [and]. Returns ['break] or a pair ($c'$ . $\lambda$). If
   % ['break] is returned [l] is as a g-DNF equivalent to ['true] in
   % case of ['gor eq 'or] and equivalent to ['false] in case ['gor eq
   % 'and]. $c'$ is either [nil] or a pair $(\tau . \gamma)$, where
   % $\tau$ is one of [T] and [nil] and $\gamma$ is a list of atomic
   % formulas. $\lambda$ is a list of list of atomic formulas. If $c'$
   % is [nil] then the conjunction over [c] is implied by a
   % conjunction over an element in [l]. If $\tau$ is [T] then
   % $\gamma$ is equal to $c$, otherwise $\gamma$ is the result of a
   % cut between $c$ and an element of $l$. [l] is modified. If
   % ['break] is returned then the formula $['gor]([c],\phi)$ is
   % equivalent to ['true] in the case ['gor eq 'or] or to ['false] in
   % the case ['gor eq 'and].
   begin scalar w,ll;
      if null l then return ( (T . c) . nil);
      ll := l;
      while ll and ((w := cl_subandcut(c, car ll,gor)) eq 'keep1) do
	 ll := cdr ll;
      if null w then return 'break;
      if null ll then return ((T . c) . nil);
      if w eq 'keep2 then return (nil . ll);
      if w neq 'failed then  % [w] is the result of the cut
	                     % between [c] and [car ll].
	 return (nil . w) . cdr ll;
      % We know, that there is no interaction between [c] and [car ll]
      w := cl_applysac2(c,cdr ll,gor);
      if w eq 'break then
	 return 'break;
      cdr ll := cdr w;
      return car w . ll;
   end;

procedure cl_subandcut(l1,l2,gor);
   % Common logic subsumption and cut. [l1] and [l2] are sorted lists
   % of atomic formulas; [gor] is one of ['or], ['and]. Returns
   % ['failed], ['keep1], ['keep2] or a list of atomic formulas. Both
   % [l1] and [l2] are considered as conjunctions. ['keep1] is
   % returned if [l2] subsumes [l1]; ['keep2] is returned if [l1]
   % subsumes [l2]. If a list [l] of atomic formulas is returned then
   % [l] is the result of a cut between [l1] and [l2]. Both
   % subsumption and cut means order theoretical generalizations of
   % the respective notions of the propositional calculus.
   begin scalar state,w,x; integer c;
      x := l1;  % Save one of [l1] and [l2] for computing a cut.
      % Determing the maximal common prefix of [l1] and [l2] and its length.
      while l1 and l2 and (car l1 equal car l2) do <<
	 c := c+1;
	 l1 := cdr l1; l2 := cdr l2
      >>;
      if null (l1 and l2) then <<  % on of [l1] and [l2] are empty
      	 if null (l1 or l2) then return 'keep1;  % both equal.
	 % [l1] is a ``subset'' of [l2] or vice versa.
       	 return (l2 and 'keep1) or 'keep2
      >>;
      % We have [l1 and l2] and [car l1 neq car l2].
      state := 'keep1;
      w := rl_sacat(car l1,car l2,gor);  % [w neq 'keep]
      if w eq 'keep2 then <<
	 state := 'keep2;
	 % swap [l1] and [l2] upto the first element.
	 w := cdr l1; l1 := cdr l2; l2 := w
      >> else if w eq 'keep1 then <<
	 l1 := cdr l1; l2 := cdr l2
      >> else if w then
	 return cl_trycut(x,c,w,cdr l1,cdr l2)
      else if rl_ordatp(car l1,car l2) then <<  % [car l1 neq car l2]
	 state := 'keep2;
	 w := l1; l1 := l2; l2 := w
      >>;
      % Now [l1] is ``shorter'' than [l2]; no cuts are possible.
      while l1 do <<
	 w := cl_sacatl(car l1, l2,gor);
      	 l2 := cdr w; w := car w;
	 l1 := cdr l1;
	 if w neq 'keep1 then
	    l1 := nil  % Leave the loop.
      >>;
      if w eq 'keep1 then return state;
      return 'failed
   end;

procedure cl_trycut(l,c,at,l1,l2);
   % Common logic try cut. [l], [l1], and [l2] are lists of atomic
   % formulas; [c] is an integer; [at] is an atomic formula or
   % ['drop]. Returns ['failed] or a sorted list $\lambda$ of atomic
   % formulas. If a cut beween [l1] and [l2] are possible then a list
   % of atomic formulas is returned, otherwise [nil] is returned. [l]
   % is a list $(a_1,...,a_n)$, [l1] is a list $(c_1,...,c_m)$.
   % $lambda$ is a list $(a_1,...,a_c,b,c_1,...,c_m)$, where $b$ is
   % the atomic formula [at] if [at] is not [drop], otherwise $b$ is
   % ommitted.
   begin scalar a;
      if null l1 and null l2 then <<
	 l := for i := 1 : c collect <<
	    a := car l; l := cdr l; a
	 >>;
	 if at eq 'drop then
	    return sort(l,'rl_ordatp);
	 return sort(at . l,'rl_ordatp)
      >>;
      if l1 neq l2 then return 'failed;
      % [l1] and [l2] are equal.
      for i:=1:c do << l1 := car l . l1; l := cdr l >>;
      if at neq 'drop then
	 l1 := at . l1;
      return sort(l1,'rl_ordatp)
   end;

procedure cl_sacatl(a,l,gor);
   % Common logic subsume and cut atomic formula list. [a] is an
   % atomic formula; [l] is a sorted list of atomic formulas; [gor] is
   % one of [or], [and]. Returns a pair $(\alpha . \lambda)$ where
   % $\alpha$ is a relation, ['keep1], or [nil]; [l] is a possibly
   % empty list of atomic formulas. $\alpha$ is [T] if [a] is implied
   % by an atomic formula from [l]; if $\alpha$ is [nil] then neither
   % [a] is implied by an atomic formula from [l] nor a cut between
   % [a] and an atomic formula from [l] is possible, otherwise
   % $\alpha$ is the result of such a cut. $\lambda$ is the rest of
   % [l] not involved in the computation of $\alpha$.
   begin scalar w;
      if null l then
      	 return '(nil . nil);
      if not rl_sacatlp(a,l) then
      	 return (nil . l);
      w := rl_sacat(a,car l,gor);
      if not w then
      	 return cl_sacatl(a,cdr l,gor);
      if w memq '(keep1 keep) then
      	 return ('keep1 . cdr l);
      if w eq 'keep2 then
      	 return (nil . cdr l);
      return (w . cdr l)  % [w] is a relation or [drop]
   end;

procedure cl_bnfsimpl(sgdnf,gor);
   % Common logic boolean normal form simplification. [sgdnf] is an
   % SG-DNF; [gor] is one of the operators [and], [or]. Returns an
   % SG-DNF equivalent to [sgdnf]. Performs simplification of [gcl].
   % Accesses switch [rlbnfsac].
   if !*rlbnfsac then cl_sac(sgdnf,gor) else sgdnf;

procedure cl_sacatlp(a,l);
   % Common logic subsumption and cut atomic formula list predicate.
   % [a] is an atomic formula; [l] is a list of atomic formulas.
   % Returns [T] a subsumption or cut beween [a] and an element of [l]
   % is possible.
   T;

procedure cl_sacat(a1,a2,gor);
   % Common logic subsumption and cut atomic formula. [a1] and [a2]
   % are atomic formulas; [gor] is one of the operators [or], [and].
   % Returns [nil], one of the identifiers [keep], [keep1], [keep2],
   % [drop], or an atomic formula. The return value [nil] indicates
   % that neither a cut nor a subsumption can be applied. If [keep] is
   % returned, then the atomic formulas are identical. In the case of
   % [keep1] or [keep2] the corresponding atomic formula can be kept,
   % and the other one can be dropped. If an atomic formula $a$ is
   % returned, then this atomic formula is the result of the cut
   % beween [a1] and [a2]. If [drop] is returned, then a cut with
   % result [true] or [false] can be performed.
   if a1 = a2 then 'keep else nil;

endmodule;  % [clbnf]

end;
