% ----------------------------------------------------------------------
% $Id$
% ----------------------------------------------------------------------
% Copyright (c) 2010 Thomas Sturm
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

lisp <<
   fluid '(cl_sl_rcsid!* cl_sl_copyright!*);
   cl_sl_rcsid!* := "$Id$";
   cl_sl_copyright!* := "Copyright (c) 2010 T. Sturm"
>>;

module clsl;

typedef formula checked by formulap;
typedef slp checked by slpp;
typedef alist checked by alistp;
typedef number checked by numberp;

procedure cl_satnum(slp);
   for each line in slp sum rl_atnum sll_rhs line;

assert cl_satnum: (slp) -> number;

procedure cl_ssimpl(slp);
   begin scalar old;
      repeat <<
      	 old := slp;
      	 slp := cl_ssimpl1 slp
      >> until eqn(length slp,length old);
      return slp
   end;

procedure cl_ssimpl1(slp);
   sl_reduce for each line in slp collect
      sll_mkx(sll_lhs line,rl_simpl(sll_rhs line,nil,-1));

assert cl_ssimpl: (slp) -> slp;

procedure cl_straightify(f);
   % [f] is a formula. Returns an SLPROG. The result is a minimal SLPROG
   % equivalent to [f].
   cl_ssimpl cl_straightify0 {sll_mk cl_totalcopy cl_simpl(f,nil,-1)};

assert cl_straightify: (formula) -> slp;

procedure cl_totalcopy(f);
   % [f] is a formula. Returns a formula equal to [f] but w/o any
   % identities on the formula level.
   begin scalar op;
      op := rl_op f;
      if rl_quap op then
	 return rl_mkq(op,rl_var f,cl_totalcopy rl_mat f);
      if rl_boolp op then
	 return rl_mkn(op,for each s in rl_argn f collect cl_totalcopy s);
      % f is truth value or atomic formula or external.
      return f
   end;

assert cl_totalcopy: (formula) -> formula;

procedure cl_sstraightify(slp);
   cl_ssimpl cl_straightify0 cl_stotalcopy cl_ssimpl slp;

procedure cl_stotalcopy(slp);
   for each l in slp collect
      sll_mkx(sll_lhs l,cl_totalcopy sll_rhs l);

procedure cl_straightify0(slp);
   % [slp] is an SLPROG. Returns an SLPROG.
   begin scalar w;
      w := cl_straightify1 slp;
      while w do <<
	 slp := w;
	 w := cl_straightify1 slp
      >>;
      return slp
   end;

assert cl_straightify0: (slp) -> slp;

procedure cl_straightify1(slp);
   % [slp] is an SLPROG. Returns an SLPROG, where [nil] indicates "no
   % success."
   begin scalar w,cand,candal,found; integer n,j,lb;
      if !*rlverbose then
	 ioto_tprin2t "entering cl_straightify1";
      n := lto_max for each sl in slp collect cl_depth sll_rhs sl;
      lb := if !*slat then 0 else 1;
      for i := n step -1 until lb do
      	 if not found then <<
	    if !*rlverbose then
	       ioto_tprin2 {"i=",i,", "};
      	    candal := cl_dcollect(slp,i);
	    if !*rlverbose then
	       ioto_prin2 {"#candal = ",j := length candal,", "};
	    while not found and candal do <<
	       cand := pop candal;
%% 	       if !*rlverbose then <<
%% 	       	  ioto_prin2 {"[",j,"] "};
%% 		  j := j-1
%% 	       >>;
	       w := cl_ccollect(slp,car cand,i);
	       % w contains at least one element
	       if cdr w then <<
		  if !*rlverbose then
		     ioto_prin2 "[HIT]";
	       	  found := t;
		  slp := cl_straightify2(slp,w)
	       >>
      	    >>
	 >>;
      if !*rlverbose then
	 ioto_tprin2t "leaving cl_straightify1";
      return if found then slp else nil
   end;

assert cl_straightify1: (slp) -> slp;

procedure cl_straightify2(slp,w);
   % [slp] is an SLPROG. [w] is an ALIST of pairs $(f . g)$, where $f$
   % is a formula, and $g$ is a formula or an SL; $g$ is a parent node
   % of $f$. All the $f$ are equal. Returns an SLPROG. The result is a
   % refinement of [slp] identifying the occurrences of $f$ specified in
   % the ALIST.
   begin scalar g;
      g := slv_new();
      for each pr in w do
	 cl_straightify3(car pr,g,cdr pr);
      slp := sll_mkx(g,caar w) . slp;
      return slp
   end;

assert cl_straightify1: (slp,alist) -> slp;

procedure cl_straightify3(hit,g,parent);
   % [hit] is a formula, [g] is an SL variable, and [parent] is a
   % formula or an SL; [parent] is a parent node of [hit]. Returns
   % [parent] with [hit] replaced by [g] in-place.
   begin scalar w;
      repeat <<
	 w := parent;
	 parent := cdr parent
      >> until eqcar(parent,hit);
      cdr w := g . cdr parent
   end;

assert cl_straightify3: (formula,id,any) -> any;

procedure cl_dcollect(slp,n);
   % Depth collect. [slp] is an SLPROG, [n] is a (positive) number.
   % Returns an ALIST of pairs $(f . g)$. The $f$ are all subformulas of
   % depth [n] ocurring in [slp]; the $g$ are either formulas or SL,
   % which are the respective parent nodes of the $f$. REMARK: The
   % parents are not really necessary here(?)
   for each sl in slp join
      cl_dcollect1(sl,n);

assert cl_dcollect: (slp,number) -> alist;

procedure cl_dcollect1(sth,n);
   % Recursive subroutine of cl_dcollect for one single SL. [sth] is a
   % formula or an SL.
   begin scalar d;
      d := cl_slldepth sth;
      if eqn(d,n+1) then
      	 return for each sub in cdr sth join
	    if eqn(cl_slldepth sub,n) then
	       {sub . sth};
      if d > n+1 then
	 return for each sub in cdr sth join
	    cl_dcollect1(sub,n);
      % There is implicitly {} returned when d becomes < n+1.
   end;

assert cl_dcollect1: (any,number) -> alist;

procedure cl_slldepth(sth);
   % Wrapper for cl_depth, which can handle also SLLs and modifies the
   % depth of truth values from 0 to -1.
   if eqcar(sth,'sll) then
      cl_depth caddr sth + 1
   else if idp sth and not rl_tvalp sth then
      -1
   else
      cl_depth sth;

assert cl_slldepth: (any) -> number;

procedure cl_ccollect(slp,cand,cd);
   % Candidate collect. [slp] is an SLPROG; [cand] is a formula. Returns
   % an ALIST of pairs [(cand . parent)] containing all occurrences of
   % [cand] in [slp] with their respective parent nodes.
   for each line in slp join
      cl_ccollect1(line,cand,cd);

assert cl_ccollect: (slp,formula) -> alist;

procedure cl_ccollect1(sth,cand,cd);
   % Recursive subroutine of cl_ccollect for one single SL. [sth] is a
   % formula or an SL.
   begin integer sd,argl;
      if eqcar(sth,'sll) or rl_boolp rl_op sth then
      	 return for each sub in sth_argl sth join <<
%      	    sd := cl_slldepth sub;
%	    if eqn(sd,cd) and sub = cand then
	    if sub = cand then
	       {sub . sth}
	    else %if sd >= cd then
	       cl_ccollect1(sub,cand,cd)
      	 >>
      else if rl_quap rl_op sth then
	 return if rl_mat sth = cand then
	    {rl_mat sth . sth}
	 else
	    cl_ccollect1(rl_mat sth,cand,cd)
      % sth is an atomic formula, which is not a  _parent_ to be considered
   end;

assert cl_ccollect: (any,formula) -> alist;

procedure sth_argl(sth);
   if eqcar(sth,'sll) then cdr sth else rl_argn sth;

procedure cl_spnf(slp);
   begin scalar tslp,lst;
      tslp := for each l in slp collect
	 sll_mkx(sll_lhs l,cl_pnf sll_rhs l);
      tslp := sl_unstraightify1(tslp,function(lambda x; rl_quap rl_op x));
      tslp := reversip tslp;
      lst := car tslp;
      tslp := cdr tslp;
      lst := sll_mkx(sll_lhs lst,cl_pnf sll_rhs lst);
      tslp := lst . tslp;
      return reversip tslp
   end;

endmodule;

end;  % of file
