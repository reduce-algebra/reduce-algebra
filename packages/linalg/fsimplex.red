% ----------------------------------------------------------------------
% $Id$
% ----------------------------------------------------------------------
% (c) 2001 Dolzmann, Gilch, Sturm, Tsirou, 2013 T. Sturm
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
%
% Following is the revision history from the old CVS, which I am keeping for
% documentation purposes for now. TS
% ----------------------------------------------------------------------
% Id: simplex.red,v 1.20 2006/06/19 12:06:49 dolzmann Exp
% ----------------------------------------------------------------------
% Copyright (c) 2001 Dolzmann, Gilch, Sturm, Tsirou
% ----------------------------------------------------------------------
% $Log: simplex.red,v $
% Revision 1.20  2006/06/19 12:06:49  dolzmann
% Simplified procedures.
%
% Revision 1.19  2001/07/31 10:46:24  dolzmann
% Removed probably buggy procedure check!-minus!-b.
%
% Revision 1.18  2001/07/31 10:19:11  dolzmann
% Split procedure simplex2.
%
% Revision 1.17  2001/07/30 09:40:16  dolzmann
% Reformatted code.
% Changed simp into sc_simp.
% Removed some quoted S-expressions by calls of simp.
%
% Revision 1.16  2001/07/27 12:09:43  dolzmann
% Added procedure sf_norminput.
%
% Revision 1.15  2001/07/27 11:07:29  dolzmann
% Changed "_" into "!-" except for prefix seperation.
%
% Revision 1.14  2001/07/27 07:59:04  dolzmann
% Reformatted check-in comments.
% Introduced new prefix "fs_".
% Added new interface code originally contained in simplex1.
%
% Revision 1.13  2001/07/24 10:02:33  gilch
% Fixed bugs.
%
% Revision 1.12  2001/07/19 08:37:51  gilch
% Fixed a bug in make_equations_positive
%
% Revision 1.11  2001/07/18 13:30:34  gilch
% Fixed a bug in make_equations_positive. Added procedures my_minus,
% turn.
%
% Revision 1.10  2001/07/09 09:18:35  gilch
% Patched matrix procedures. Added sc_igetv, sc_iputv,
% sc_rowscalarproduct.
%
% Revision 1.9  2001/07/05 09:34:35  gilch
% Replaced putv and getv by iputv and igetv. Patched
% "sc_*"-procedures.
%
% Revision 1.8  2001/06/15 13:07:00  gilch
% Updated internal representation of matrices to vectors of vectors.
% Added copy_vect.
%
% Revision 1.7  2001/06/15 10:08:42  gilch
% Substitution of sc_matrixproduct by sc_multm in rstep3
%
% Revision 1.6  2001/06/08 10:33:14  gilch
% Replaced repeated calls of same procedures with same arguments by
% variables.
%
% Revision 1.5  2001/06/01 10:41:53  gilch
% Changed internal representation of equations and objective function
% to SQ form at the time procedure "initialise" is being entered.
% Matrices in this context represented without 'mat-tag. Updated many
% procedures for calls w.r.t new internal representation. Added
% sc_getvarl, sc_getvar, sc_setmat,sc_getmat, sc_multrow,
% sc_matrixaugment, sc_scalarproduct, sc_transpose, sc_negmatrix,
% sc_geq, sc_matrixproduct.
%
% Revision 1.4  2001/05/11 11:23:04  gilch
% Removed Calls of my_round, added procedures sc_simp, sc_prepsq,
% sc_numr, sc_denr, sc_addsq, sc_negsq, sc_multsq, sc_subtrsq,
% sc_quotsq, sc_null, sc_multm, sc_scalprod, sc_mkmatrix
%
% Revision 1.3  2001/05/09 10:23:04  gilch
% Added my_round, fixed bugs.
%
% Revision 1.2  2001/04/30 12:21:21  gilch
% Put all direct and indirect calls to reval into special procedures.
%
% Revision 1.1  2001/04/30 12:14:39  gilch
% Initial check-in. Version distributed with REDUCE 3.7.
%
% ----------------------------------------------------------------------
module simplex;

fluid '(simplex_id!* simplex_copyright!*);

simplex_id!* := "$Id$";
simplex_copyright!* := "(c) 2001 Dolzmann, Gilch, Sturm, Tsirou, 2013 Sturm";

%**********************************************************************%
%                                                                      %
% Computation of the optimal value of an objective function given a    %
% number of linear inequalities using the SIMPLEX algorithm.           %
%                                                                      %
% Author: Matt Rebbeck, June 1994.                                     %
%                                                                      %
% Many of the ideas were taken from "Linear Programming" by            %
%                                                 M.J.Best & K. Ritter %
%                                                                      %
% Minor changes: Herbert Melenk, Jan 1995                              %
%                                                                      %
%   replacing first, second etc. by car, cadr                          %
%   converted big smacros to ordinary procedures                       %
%                                                                      %
%**********************************************************************%

% The next line causes problems during compilation
% load!-package 'linalg;  % required for get_coeffs (...?)

if not get('leq,'simpfn) then
<<
   algebraic operator <=;
   algebraic operator >=;
>>;

flag('(equal leq geq), 'spaced);

procedure fs_simplex1(input);
  %
  % The simplex problem is:
  %
  % min {c'x | Ax = b, x>=0},
  %
  % where Ax = b describes the linear equations and c is the function
  % that is to be optimised.
  %
  % This code implements the basic phaseI-phaseII revised simplex
  % algorithm. (phaseI checks for feasibility and phaseII finds the
  % optimal solution).
  %
  % A general idea of tha algorithm is as follows:
  %
  % 1: create phase 1 data.
  %
  %    Add slack and artificial variables to equations to create matrix
  %    A1. The initial basis (ib) consists of the numbers of the columns
  %    relating to the artificial variables. The basic feasible solution
  %    (xb) (if one exists) is  B^(-1)*b where b is the r.h.s. of the
  %    equations. Throughout, cb denotes the columns of the objective
  %    matrix corresponding to ib.
  %    This data goes to the revised simplex algorithm(2).
  %
  % 2: revised simplex:
  %
  %    step 1: Computation of search direction sb.
  %
  %    Compute u = -(B^(-1))'*cb, the smallest index k, and vk s.t.
  %
  %               vk = min{c(i) + A(i)'u | i not elt of ib}.
  %
  %    If vk>=0, stop with optimal solution xb = B^(-1)*b.
  %    If vk<0, set sb = B^(-1)*A(k) and go to step 2.
  %
  %    step 2: Computation of maximum feasible step size Ob.
  %
  %    If sb<=0 then rederr "Problem unbounded from below".
  %    If (sb)(i) >0 for at least one i, compute Ob and the smallest
  %      index l s.t.
  %
  %              (xb)(l)       { (xb)(i) |                      }
  %         Ob = ------- = min { ------  | all i with (sb)(i)>0 },
  %              (sb)(l)       { (sb)(i) |                      }
  %
  %    and go to step 3.
  %
  %    step3: Update.
  %
  %    Replace B^(-1) with [phiprm((B^(-1)',A(k),l)]', xb with B^(-1)*b
  %    and the l'th elt in ib with k. Compute cb'xb and go to step 1.
  %
  % 3: If we get this far (ie: we are feasible) then apply revised
  %    simplex to A (equations with slacks added), and the new xb,
  %    Binv, and ib.
  %
  %
  % Further details and far more advanced algorithms can be found
  % in almost any linear programming book. The above was adapted from
  % "Linear Programming"  M.J.Best and K. Ritter. To date, the code
  % contains no anti_cycling algorithm.
  %
  begin scalar max!-or!-min,objective,equation!-list,boundl,w;
     {max!-or!-min, objective, equation!-list, boundl} := fs_a2s!-simplex input;
     w := fs_simplex2(max!-or!-min, objective, equation!-list, boundl);
     if w eq 'infeasible then
	rederr "Error in simplex: Problem has no feasible solution.";
     return fs_s2a!-simplex w
  end;

procedure fs_a2s!-simplex(input);
   begin scalar max!-or!-min,objective,equation!-list,boundal;
      if null input then
	 rederr "simplex called with 0 arguments instead of 3-4";
      max!-or!-min := fs_a2s!-maxmin car input;
      input := cdr input;
      if null input then
	 rederr "simplex called with 1 arguments instead of 3-4";
      objective := fs_a2s!-obj car input;
      input := cdr input;
      if null input then
	 rederr "simplex called with 2 arguments instead of 3-4";
      equation!-list := fs_a2s!-cl car input;
      input := cdr input;
      if null input then
	 return {max!-or!-min,objective,equation!-list,boundal};
      boundal := fs_a2s!-boundl car input;
      input := cdr input;
      if input then
	 rederr "simplex called with more than 4 arguments";
      return {max!-or!-min,objective,equation!-list,boundal}
   end;

procedure fs_a2s!-maxmin(a);
   % algebraic to symbolic mode maxmin.
   begin scalar w;
      w := reval a;
      if (w neq 'max) and (w neq 'min) then
	 rederr "Error in simplex(first argument): must be either max or min";
      return w
   end;

procedure fs_a2s!-obj(a);
   % algebraic to symbolic mode objective function.
   sc_simp reval a;

procedure fs_a2s!-cl(a);
   % algebraic to symbolic mode constraint list.
   begin scalar w;
      w := reval a;
      if pairp w and car w = 'list then
	 w := cdr w
      else
	 rederr "Error in simplex(third argument): must be a list";
      return w
   end;

procedure fs_a2s!-boundl(a);
   begin scalar w;
      w := reval a;
      if pairp w and car w = 'list then
	 w := cdr w
      else
	 rederr "simplex: Fourth argument must be a list";
      return fs_read!-bounds w
   end;

procedure fs_read!-bounds(boundl);
   begin scalar w, boundal, ub, lb, v;
      for each item in boundl do <<
	 if eqcar(item, 'and) then <<  % Redlog has resolved a chain of leq
	    rederr "simplex: not yet compatible with Redlog";
	 >> else if not eqcar(item, 'leq) then
	    rederr {"simplex: bad bound", item}
	 else <<
	    w := cadr item;
	    if eqcar(w, 'leq) then <<  % chain
	       lb := cadr w;
	       v := caddr w;
	       ub := caddr item;
	       if not (fs_lboundp lb and idp v and fs_uboundp ub) then
	    	  rederr {"simplex: bad bound", item};
	       boundal := fs_setlb(boundal, v, lb);
	       boundal := fs_setub(boundal, v, ub)
	    >> else <<
	       if idp cadr item then <<
		  v := cadr item;
		  ub := caddr item;
	       	  if not (idp v and fs_uboundp ub) then
	    	     rederr {"simplex: bad bound", item};
	       	  boundal := fs_setub(boundal, v, ub)
	       >> else <<
		  lb := cadr item;
	       	  v := caddr item;
		  if not (fs_lboundp lb and idp v) then
		     rederr {"simplex: bad bound", item};
	       	  boundal := fs_setlb(boundal, v, lb)
	       >>
	    >>
	 >>
      >>;
      for each pr in boundal do
	 if cadr pr eq 'default then cadr pr := 0;
      return boundal
   end;

procedure fs_lboundp(x);
   numberp x or x = '(minus infinity);

procedure fs_uboundp(x);
   numberp x or x eq 'infinity;

procedure fs_setlb(boundal, v, lb);
   begin scalar w;
      w  := atsoc(v, boundal);
      if null w then
	 return (v . {lb, 'infinity}) . boundal;
      if cadr w eq 'default or cadr w = '(minus infinity) or domainp lb and cadr w < lb then
	 cadr w := lb;
      return boundal
   end;

procedure fs_setub(boundal, v, ub);
   begin scalar w;
      w  := atsoc(v, boundal);
      if null w then
	 return (v . {'default, ub}) . boundal;
      if caddr w eq 'infinity or domainp ub and ub < caddr w then
	 caddr w := ub;
      return boundal
   end;

procedure fs_s2a!-simplex(w);
   {'list,sc_prepsq car w,'list . cdr w};

procedure fs_simplex2(max!-or!-min, objective, equation!-list, boundal);
   begin scalar a, b, obj!-mat, x, ib, xb, binv, ph1optval, ansl, optval,
 	 subal, addcl, splal, gensyml;
      integer no!-coeffs,no!-variables;
      {addcl, subal, splal, gensyml} := fs_analyze!-bounds boundal;
      {objective, equation!-list} :=
	 fs_preproc!-bounds(objective, equation!-list, addcl, subal, splal);
      equation!-list := fs_norminput(objective, equation!-list);
      {a, b, obj!-mat, x, no!-variables} :=
	 fs_init(max!-or!-min, objective, equation!-list);
      no!-coeffs := fast!-column!-dim a;
      {ph1optval, xb, ib, binv} := fs_phase1(a, b);
      if not sc_null ph1optval then
	 return 'infeasible;
      {optval, xb, ib} := fs_phase2(obj!-mat, a, b, ib, binv, xb);
      ansl := fs_make!-answer!-list(xb, ib, no!-coeffs, x, no!-variables);
      if max!-or!-min = 'max then
       	 optval := sc_negsq optval;
      ansl := fs_postproc!-bounds(ansl, subal, splal, gensyml);
      return optval . ansl
   end;

procedure fs_analyze!-bounds(boundal);
   begin scalar v, lb, ub, subal, addcl, splal, v1, v2, gensyml;
      for each bound in boundal do <<
	 {v, lb, ub} := bound;
	 if lb eq 'default or numberp lb then <<
	    if not (lb eq 'default or eqn(lb, 0)) then
	       subal := (v . {'difference, v, lb}) . subal;
	    if numberp ub then
	       addcl := {'leq, v, ub - lb} . addcl
	 >> else <<  % lb = -infinity
	    v1 := gensym();
	    v2 := gensym();
	    splal := (v . {'difference, v1, v2}) . splal;
	    gensyml := v1 . v2 . gensyml;
	    if numberp ub then
	       addcl := {'leq, v, ub} . addcl
	 >>
      >>;
      return {addcl, subal, splal, gensyml}
   end;

procedure fs_preproc!-bounds(objective, equation!-list, addcl, subal, splal);
   {subsq(subsq(objective, subal), splal),
      for each c in append(addcl, equation!-list) collect
	 {car c, prepsq subsq(subsq(simp cadr c, subal), splal), caddr c}};

procedure fs_postproc!-bounds(ansl, subal, splal, gensyml);
   begin scalar w, ansal, ransl;
      for each equ in ansl do <<
	 w := atsoc(cadr equ, subal);
	 if w then
	    % Here I am turning differences into sums. This is not really a
	    % clean solution. TS
 	    ransl := {'equal, cadr equ, reval {'plus, caddr equ, caddr cdr w}} . ransl
	 else if cadr equ memq gensyml then
      	    ansal := (cadr equ . caddr equ) . ansal
	 else
	    ransl := equ . ransl
      >>;
      for each pr in splal do
	 ransl := {'equal, car pr, prepsq subsq(simp cdr pr, ansal)} . ransl;
      ransl := sort(ransl, function(lambda (x, y); ordop(cadr x, cadr y)));
      return ransl
   end;

procedure fs_norminput(objective,eql);
   begin scalar w,vars;
      eql := fs_mkpos eql;
      w := fs_mkunique eql;
      eql := car w;
      vars := cdr w;
      eql := fs_add!-constraints(objective,eql,vars);
      eql := for each equation in eql collect
	 {car equation, sc_simp cadr equation, sc_simp caddr equation};
      return eql
   end;

procedure fs_mkunique(eql);
   % Removes repititions in input. [eql] is a list of equations.
   % Returns a pair of equations and coeffecients in equation list.
   begin scalar ueql,coeffl;
      for each equation in eql do <<
       	 if not member(equation,ueql) then <<
	    ueql := equation . ueql;
            coeffl := union(coeffl,get_coeffs cadr equation)
         >>
      >>;
      return (ueql . coeffl)
   end;

procedure fs_mkpos(equation!-list);
   % [equation!-list] is a list of equations. Returns a list of equations.
   % If r.h.s. of inequality is <0 then mult. both sides by
   % -1 and turn inequality symbol.
   %
   for each equation in equation!-list collect
      if minusf(numr simp(caddr equation)) then
	 {fs_turn(car equation),
	    fs_minus(cadr equation),fs_minus(caddr equation)}
      else
	 equation;

procedure fs_add!-constraints(obj,eql,eqvs);
   % [obj] is a SC; [eql] is a list of lists, [eqvs] is a list. Returns a list.
   % If variables in the objective have not been defined in the
   % inequalities(equation!-list) then add them. They are added as variable >=
   % 0.
   begin scalar ovs;
      ovs := sc_kernels obj;
      if length ovs = length eqvs then
       	 return eql;
      for each v in ovs do <<
       	 if not member(v,eqvs) then <<
            prin2 "*** Warning: variable ";
            prin2 v;
            prin2t " not defined in input. Has been defined as >=0.";
       	    eql := append(eql,{{'geq,v,0}})
      	 >>
      >>;
      return eql
   end;

procedure fs_init(max!-or!-min,objective,eql);
   % Initialize. [max!-or!-min] is one of ['max], ['min]; [objective]
   % is a SQ, the objective function; [eql] is a list of constraints.
   % Returns the list [{A,b,obj!-mat,X,nonslacks}]. Creates [A] (with
   % slack variables included), [b] (r.h.s. of equations), the
   % objective matrix [obj!-mat] and [X] s.t. $[A][X]=[b]$ and
   % $[obj!-mat] * [X] = [objective]$. Also returns the number
   % [nonslacks] of variables in the [eql] so we know where to stop
   % making answers in fs_make!-answer!-list.
   begin
      scalar a,b,obj!-mat,x,vl,nonslacks,w,slackeqs,a,b,x;
      if max!-or!-min = 'max then
       	 objective := sc_negsq objective;
      vl := fs_eqlvarl eql;
      nonslacks := length vl;
      w := fs_add!-slacks!-to!-equations eql;
      slackeqs := car w;
      b := cadr w;
      vl := union(vl,caddr w);
      w := fs_get!-x!-and!-obj!-mat(objective,vl);
      x := car w;
      obj!-mat := cadr w;
      a := fs_simp!-get!-a(slackeqs,vl);
      return {a,b,obj!-mat,x,nonslacks}
   end;

procedure fs_phase1(a,b);
   begin scalar w,a1,ib,xb,binv,phase1!-obj;
      w := fs_create!-phase1!-a1!-and!-obj!-and!-ib a;
      a1 := car w;
      phase1!-obj := cadr w;
      ib := caddr w;
      xb := b;
      binv := fast!-make!-identity fast!-row!-dim a;
      return fs_simplex!-calculation(phase1!-obj,a1,b,ib,binv,xb)
   end;

procedure fs_phase2(obj!-mat,a,b,ib,binv,xb);
   begin scalar big,k,stop,i,sum,abs!-sum,work;
      integer m,n;
      m := fast!-row!-dim a;
      n := fast!-column!-dim a;
      for ell := 1:m do
	 if nth(ib,ell) > n then <<
      	    big := sc_simp(-1);
      	    k := 0;
      	    stop := nil;
      	    i := 1;
      	    while i<=n and not stop do <<
               sum := sc_scalarproduct(fast!-stack!-rows(binv,ell),
	       	  fast!-augment!-columns(a,i));
	       abs!-sum := sc_abs sum;
               if sc_geq(big,abs!-sum) then
	       	  stop := t
               else <<
               	  big := abs!-sum;
               	  k := i
	       >>;
               i := i+1
      	    >>;
      	    if sc_minussq big then
	       rederr {"Error in simplex: Constraint",k," is redundant."};
      	    work := fast!-augment!-columns(a,k);
      	    binv := fs_phiprm(binv,work,ell);
      	    nth(ib,ell) := k
      	 >>;
      return fs_simplex!-calculation(obj!-mat,a,b,ib,binv,xb)
   end;

procedure fs_create!-phase1!-a1!-and!-obj!-and!-ib(a);
   begin scalar phase1!-obj,a1,ib;
      integer column!-dim!-a1,column!-dim!-a,i;
      column!-dim!-a := fast!-column!-dim a;
      % Add artificials to A.
      a1 := sc_matrixaugment(a,fast!-make!-identity(fast!-row!-dim a));
      column!-dim!-a1 := fast!-column!-dim a1;
      phase1!-obj := sc_mkmatrix(1,column!-dim!-a1);
      for i := column!-dim!-a+1:column!-dim!-a1 do
       	 sc_setmat(phase1!-obj,1,i,sc_simp 1);
      ib := for i := column!-dim!-a+1:column!-dim!-a1 collect i;
      return {a1,phase1!-obj,ib}
   end;

procedure fs_simplex!-calculation(obj!-mat,a,b,ib,binv,xb);
   % Applies the revised simplex algorithm. See above for details.
   begin scalar rs1,sb,rs2,rs3,u,continue,obj!-value;
      integer k,iter,ell;
      obj!-value := fs_compute!-objective(fs_get!-cb(obj!-mat,ib),xb);
      while continue neq 'optimal do <<
      	 rs1 := fs_rstep1(a,obj!-mat,binv,ib);
      	 sb := car rs1;
      	 k := cadr rs1;
      	 u := caddr rs1;
      	 continue := cadddr rs1;
      	 if continue neq 'optimal then <<
            rs2 := fs_rstep2(xb,sb);
            ell := cadr rs2;
            rs3 := fs_rstep3(xb,obj!-mat,b,binv,a,ib,k,ell);
            iter := iter + 1;
            binv := car rs3;
            obj!-value := cadr rs3;
            xb := caddr rs3
      	 >>
      >>;
      return {obj!-value,xb,ib,binv}
   end;

procedure fs_eqlvarl(eql);
   % equation list varoiable list. [eql] is a list of equtions.
   % Returns the list of all variables included in the equations and
   % inequalities contained in [eql].
   begin scalar vl;
      for each equation in eql do
       	 vl := union(vl,sc_kernels cadr equation);
      return vl;
   end;

procedure fs_add!-slacks!-to!-equations(equation!-list);
   % Takes list of equations (=, <=, >=) and adds required slack
   % variables. Also returns all the rhs integers in a column matrix,
   % and a list of the added slack variables.
   begin scalar slack!-list,rhs!-mat,slack!-variable,slack!-variable!-list,
     	 b!-in!-eq;
      integer i,row;
      rhs!-mat := sc_mkmatrix(length equation!-list,1);
      row := 1;
      for each equation in equation!-list do <<
       	 b!-in!-eq := caaddr equation;
       	 if (not numberp b!-in!-eq and b!-in!-eq neq nil)
	    and (pairp b!-in!-eq and car b!-in!-eq neq '!:rd!:)
	 then
	    rederr "Error in simplex: Right hand side of inequalities must be numbers."
	 else
	    sc_setmat(rhs!-mat,row,1,caddr equation);
       	 row := row+1;
       	 % Put in slack/surplus variables where required.
       	 if car equation = 'geq then <<
            i := i+1;
            slack!-variable := mkid('sl!-var,i);
            equation := sc_addsq(sc_negsq(sc_simp mkid('sl!-var,i)),
	       cadr equation);
            slack!-variable!-list := append(slack!-variable!-list,
	       {slack!-variable})
	 >> else if car equation = 'leq then <<
            i := i+1;
            slack!-variable := mkid('sl!-var,i);
            equation := sc_addsq(sc_simp mkid('sl!-var,i),cadr equation);
            slack!-variable!-list := append(slack!-variable!-list,
	       {slack!-variable})
	 >> else if car equation = 'equal then
	    equation := cadr equation
       	 else
            rederr "Error in simplex: Inequalities must contain either >=, <=, or =.";
       	 slack!-list := append(slack!-list,{equation})
      >>;
      return {slack!-list,rhs!-mat,slack!-variable!-list}
   end;

flag('(add!-slacks!-to!-list),'opfn);

procedure fs_simp!-get!-a(slack!-equations,variable!-list);
   % Extracts the A matrix from the slack equations.
   begin scalar a,slack!-elt,var!-elt;
      integer length!-slack!-equations,length!-variable!-list;
      length!-slack!-equations := length slack!-equations;
      length!-variable!-list := length variable!-list;
      a := sc_mkmatrix(length!-slack!-equations,length!-variable!-list);
      for row := 1:length!-slack!-equations do <<
       	 for col := 1:length!-variable!-list do <<
            slack!-elt := nth(slack!-equations,row);
            var!-elt := nth(variable!-list,col);
            sc_setmat(a,row,col,   % TODO
	       sc_simp algebraic coeffn(lisp sc_prepsq slack!-elt,var!-elt,1))
	 >>
      >>;
      return a
   end;

procedure fs_get!-x!-and!-obj!-mat(objective,variable!-list);
   % Converts the variable list into a matrix and creates the objective
   % matrix. This is the matrix s.t. obj!-mat * X = objective function.
   begin scalar x,obj!-mat;
      integer length!-variable!-list,tmp;
      length!-variable!-list := length variable!-list;
      x := sc_mkmatrix(length!-variable!-list,1);
      obj!-mat :=sc_mkmatrix(1,length!-variable!-list);
      for i := 1:length!-variable!-list do <<
       	 sc_setmat(x,i,1,nth(variable!-list,i));
       	 tmp := nth(variable!-list,i);
       	 sc_setmat(obj!-mat,1,i,sc_simp algebraic     % TODO
	    coeffn(lisp sc_prepsq objective,tmp,1))
      >>;
      return {x,obj!-mat}
   end;

procedure fs_get!-cb(obj!-mat,ib);
   % Gets hold of the columns of the objective matrix that are pointed
   % at in ib.
   fast!-augment!-columns(obj!-mat,ib);

procedure fs_compute!-objective(cb,xb);
   % Objective value := cb * xb (both are matrices)
   sc_scalarproduct(cb,xb);

procedure fs_rstep1(a,obj!-mat,binv,ib);
  % Implements step 1 of the revised simplex algorithm.
  % ie: Computation of search direction sb.
  begin scalar u,sb,sum,i!-in!-ib;
     integer i,j,m,n,k,vkmin;
     m := fast!-row!-dim a;
     n := fast!-column!-dim a;
     u := sc_mkmatrix(m,1);
     sb := sc_mkmatrix(m,1);
     u := sc_matrixproduct(sc_negtranspose(binv),
	sc_transpose(fs_get!-cb(obj!-mat,ib)));
     k := 0;
     vkmin := sc_simp '(expt 10 10);
     i := 1;
     for i:=1:n do <<
       	i!-in!-ib := nil;
       	% Check if i is in ib.
       	for j:=1:m do
           if i = nth(ib,j) then
	      i!-in!-ib := t;
       	if not i!-in!-ib then <<
           sum := sc_addsq(sc_getmat(obj!-mat,1,i),
	      sc_columnscalarproduct(fast!-augment!-columns(a,i),u));
           if not sc_geq(sum,vkmin) then <<
              vkmin := sum;
              k := i
	   >>
	>>
     >>;
     % Do we need a tolerance here?
     if sc_minussq(vkmin) then <<
      	for i := 1:m do <<  % Form sb.
           sum := sc_simp 0;
           for j := 1:m do
	      sum := sc_addsq(sum,
		 sc_multsq(sc_getmat(binv,i,j),sc_getmat(a,j,k)));
           sc_setmat(sb,i,1,sum)
	>>;
      	return {sb,k,u,nil}
     >> else
	return {sb,k,u,'optimal}
  end;

procedure fs_rstep2(xb,sb);
  % step 2: Computation of maximum feasible step size Ob.
  begin scalar ratio,sb!-elem;
     integer ell,sigb;
     sigb := sc_simp '(expt 10 30);
     for i := 1:fast!-row!-dim sb do <<
       	sb!-elem := sc_getmat(sb,i,1);
       	if not sc_minussq sb!-elem  and not sc_null sb!-elem then <<
           ratio := sc_quotsq(sc_getmat(xb,i,1),sb!-elem);
           if not sc_geq(ratio,sigb) then <<
              sigb := ratio;
              ell := i
	   >>
	>>
     >>;
     if ell = 0 then
       	rederr "Error in simplex: The problem is unbounded.";
     return {sigb,ell}
  end;

procedure fs_rstep3(xb,obj!-mat,b,binv,a,ib,k,ell);
  % step3: Update.
  begin scalar work,binv;
     work := fast!-augment!-columns(a,k);
     binv := fs_phiprm(binv,work,ell);
     xb := sc_matrixproduct(binv,b);
     nth(ib,ell) := k;
     obj!-mat := fs_compute!-objective(fs_get!-cb(obj!-mat,ib),xb);
     return {binv,obj!-mat,xb}
  end;

procedure fs_phiprm(binv,d,ell);
   % Replaces B^(-1) with [phi((B^(-1)',A(k),l)]'.
   begin scalar sum,temp;
      integer m;
      m := fast!-column!-dim binv;
      sum := sc_scalarproduct(fast!-stack!-rows(binv,ell),d);
      if not sc_null sum then
       	 sum := sc_quotsq(sc_simp 1,sum);
      binv := fast!-mult!-rows(binv,ell,sum);
      for j := 1:m do <<
       	 if j neq ell then <<
            temp := sc_scalarproduct(fast!-stack!-rows(binv,j),d);
            binv := fast!-add!-rows(binv,ell,j,sc_negsq temp)
	 >>
      >>;
      return binv
   end;

procedure fs_make!-answer!-list(xb,ib,no!-coeffs,x,no!-variables);
   % Creates a list of the values of the variables at the optimal
   % solution.
   begin scalar x!-mat,ansl,xb!-elem;
      integer i;
      x!-mat := sc_mkmatrix(1,no!-coeffs);
      i := 1;
      for each elt in ib do <<
       	 xb!-elem := sc_getmat(xb,i,1);
       	 if not sc_null(xb!-elem) then
            sc_setmat(x!-mat,1,elt,xb!-elem);
	 i := i+1
      >>;
      ansl := for i:=1:no!-variables collect
	 {'equal,sc_getmat(x,i,1),sc_prepsq(sc_getmat(x!-mat,1,i))};
      return ansl
   end;

% New Procedures

procedure sc_simp(a);
  % Converts an algebraic form to SQ
  simp a;

procedure sc_prepsq(a);
  % Converts SQ to algebraic form
  prepsq a;

procedure sc_numr(a);
  % Selects the numerator part of a SQ
  numr a;

procedure sc_denr(a);
  % Selects the denominator part of a SQ
  denr a;

procedure sc_kernels(u);
   kernels numr u;

procedure sc_addsq(a,b);
   % Adds SQs
   addsq(a,b);

procedure sc_negsq(a);
   % Multiplies SQ with -1
   negsq a;

procedure sc_subtrsq(a,b);
   % Subtracts b from a
   subtrsq(a,b);

procedure sc_multsq(a,b);
   % Multiplies two SQs
   multsq(a,b);

procedure sc_quotsq(a,b);
   % Computes quotient of two SQs
  quotsq(a,b);

procedure sc_null(a);
   % Tests, if SQ equals 0.
   null numr a;

procedure sc_minussq(s);
   % Tests, if s < 0
   minusf numr s;

procedure sc_getvar(s);
   % Gets variables from SQ
   kernels numr s;

procedure sc_geq(a,b);
   % Tests if a >= b
   not sc_minussq(sc_subtrsq(a,b));


procedure sc_abs(u);
   if sc_minussq u then
      sc_negsq u
   else
      u;

procedure fast!-row!-dim(in!-mat);
   % Finds row dimension of a matrix with no error checking.
   (upbv in!-mat)+1;

procedure fast!-column!-dim(in!-mat);
   % Finds column dimension of a matrix with no error checking.
   (upbv igetv(in!-mat,0))+1;

procedure fast!-stack!-rows(in!-mat,row!-list);
   % row!-list is always an integer in simplex.
   begin scalar v;
      v := mkvect 0;
      iputv(v,0,igetv(in!-mat,row!-list-1));
      return v
   end;

procedure fast!-add!-rows(in!-mat,r1,r2,mult1);
   % Replaces row2 (r2) by mult1*r1 + r2 without messing around.
   begin scalar fast!-getmatel,row1,row2;
      integer coldim;
      coldim := fast!-column!-dim in!-mat;
      row1 := sc_igetv(in!-mat,r1-1);
      row2 := sc_igetv(in!-mat,r2-1);
      if sc_null(mult1) then
	 return in!-mat;
      for i := 1:coldim do <<
       	 if not sc_null(fast!-getmatel := sc_igetv(row1,i-1)) then
	    sc_iputv(row2,i-1,
	       sc_addsq(sc_multsq(mult1,fast!-getmatel),sc_igetv(row2,i-1)))
      >>;
      return in!-mat
   end;

procedure fast!-augment!-columns(in!-mat,col!-list);
   % Quickly augments columns of in!-mat specified in col!-list.
   begin scalar v,rowdim,new!-row,length!-col!-list,actual;
      rowdim := fast!-row!-dim(in!-mat);
      length!-col!-list := length col!-list;
      v := mkvect (rowdim-1);
      if atom col!-list then
	 for i:=0:(rowdim-1) do <<
       	    new!-row := mkvect 0;
       	    sc_iputv(new!-row,0,sc_getmat(in!-mat,i+1,col!-list));
       	    sc_iputv(v,i,new!-row)
     	 >>
      else
	 for i := 0:(rowdim-1) do <<
	    new!-row := mkvect(length!-col!-list-1);
 	    for j := 0:(length!-col!-list-1) do <<
	       actual := sc_getrow(in!-mat,i+1);
	       sc_iputv(new!-row,j,sc_igetv(actual,nth(col!-list,j+1)-1))
	    >>;
	    sc_iputv(v,i,new!-row)
    	 >>;
      return v
   end;

procedure fast!-mult!-rows(in!-mat,row!-list,mult1);
   % In simplex row!-list is always an integer.
   begin scalar new!-row,rowdim,coldim,v,row;
      integer row!-no;
      row!-no := 1;
      rowdim := fast!-row!-dim in!-mat;
      coldim := fast!-column!-dim in!-mat;
      v := mkvect(rowdim-1);
      for i:=0:rowdim-1 do <<
	 if row!-no neq row!-list then
	    sc_iputv(v,i,sc_igetv(in!-mat,i))
	 else <<
	    row := sc_getrow(in!-mat,row!-no);
	    new!-row := mkvect(coldim-1);
	    for j := 0:coldim-1 do
	       sc_iputv(new!-row,j,sc_multsq(mult1,sc_igetv(row,j)));
	    sc_iputv(v,i,new!-row)
	 >>;
	 row!-no := row!-no+1
      >>;
      return v
   end;

procedure fast!-make!-identity(sq!-size);
   % Creates identity matrix.
   begin scalar id!-mat;
      id!-mat := sc_mkmatrix(sq!-size,sq!-size);
      for i := 0:sq!-size-1 do
	 for j := 0:(sq!-size-1) do
	    if i=j then
	       sc_iputv(sc_igetv(id!-mat,i),i,sc_simp 1);
      return id!-mat
   end;

procedure sc_mkmatrix(n,m);
   % Updated for vectors
   % Creates nXm matrix without 'mat-Tag. Matrices are vectors of vectors.
   begin scalar matr,new!-row;
      matr := mkvect(n-1);
      for i := 0:n-1 do <<
	 new!-row := mkvect (m-1);
	 for j:=0:m-1 do
	    sc_iputv(new!-row,j, sc_simp 0);
	 sc_iputv(matr,i,new!-row);
      >>;
      return matr
   end;

procedure sc_setmat(matr,i,j,val);
   % Sets matrix element matr(i,j)
   % Sets matrix(i,j) to val
   iputv(igetv(matr,i-1),j-1,val);

procedure sc_getmat(m,i,j);
   % Gets matrix element m(i,j)
   % Gets matrix element (i,j) from m
   igetv(igetv(m,i-1),j-1);

procedure sc_multrow(m,i,multi);
   % Multiplies row i in matrix m with multi
   fast!-mult!-rows(m,i,multi);

procedure sc_matrixaugment(mat1,mat2);
   % Builds new matrix (mat1 | mat2)
   begin scalar v,rowdim,coldim1,coldim2,actualrow1,actualrow2;
      rowdim := fast!-row!-dim mat1;
      coldim1 := fast!-column!-dim mat1;
      coldim2 := fast!-column!-dim mat2;
      v := sc_mkmatrix(rowdim,coldim1+coldim2);
      for i:=1:rowdim do <<
	 actualrow1 := sc_getrow(mat1,i);
	 actualrow2 := sc_getrow(mat2,i);
	 for j:=1:coldim1 do
	    sc_setmat(v,i,j,sc_igetv(actualrow1,j-1));
	 for j:=1:coldim2 do
	    sc_setmat(v,i,coldim1+j,sc_igetv(actualrow2,j-1))
      >>;
      return v
   end;

procedure sc_scalarproduct(row,col);
   % Computes row * col
   begin scalar res;
      res := sc_simp 0;
      for i := 1:fast!-row!-dim(col) do
	 res := sc_addsq(res,sc_multsq(sc_getmat(row,1,i),sc_getmat(col,i,1)));
      return res
   end;

procedure sc_transpose(matr);
   % Computes Transpose
   begin scalar mat1,coldim,rowdim;
      rowdim := fast!-row!-dim matr;
      coldim := fast!-column!-dim matr;
      mat1 := sc_mkmatrix(coldim,rowdim);
      for i := 1:coldim do
	 for j := 1:rowdim do
	    sc_setmat(mat1,i,j,sc_getmat(matr,j,i));
      return mat1
   end;

procedure sc_negtranspose(matr);
   % Computes Transpose with each element multiplied by -1
   begin scalar mat1,coldim,rowdim;
      rowdim := fast!-row!-dim matr;
      coldim := fast!-column!-dim matr;
      mat1 := sc_mkmatrix(coldim,rowdim);
      for i := 1:coldim do
	 for j := 1:rowdim do
	    sc_setmat(mat1,i,j,sc_negsq sc_getmat(matr,j,i));
      return mat1
   end;

procedure sc_negmatrix(matr);
   % Multiplies each entry of matr with -1
   begin scalar v,rowdim,coldim;
      rowdim := fast!-row!-dim matr;
      coldim := fast!-column!-dim matr;
      v := sc_mkmatrix(rowdim,coldim);
      for i := 1:rowdim do
	 for j := 1:coldim do
	    sc_setmat(v,i,j,sc_negsq sc_getmat(matr,i,j));
      return v
   end;

procedure sc_matrixproduct(a,b);
   % Computes product of two Matrices
   begin scalar mat1,coldimb,rowdima,newrow1,newrow2,transposeb;
      rowdima := fast!-row!-dim a;
      coldimb := fast!-column!-dim b;
      mat1 := sc_mkmatrix(rowdima,coldimb);
      transposeb := sc_transpose(b);
      for i := 1:rowdima do
	 for j := 1:coldimb do <<
	    newrow1 := mkvect 0;
	    sc_iputv(newrow1,0,sc_igetv(a,i-1));
	    newrow2 := mkvect 0;
	    sc_iputv(newrow2,0,sc_igetv(transposeb,j-1));
	    sc_setmat(mat1,i,j,sc_rowscalarproduct(newrow1,newrow2))
	 >>;
      return mat1
   end;

procedure sc_rowscalarproduct(row1,row2);
   % Computes row1 * (row2)^t
   begin scalar res;
      res := sc_simp 0;
      for i := 1:fast!-column!-dim row1 do
	 res := sc_addsq(res,
	    sc_multsq(sc_getmat(row1,1,i),sc_getmat(row2,1,i)));
      return res
   end;

procedure sc_columnscalarproduct(col1,col2);
   % Computes (col1)^T * col2
   begin scalar res;
      res := sc_simp 0;
      for i := 1:fast!-row!-dim col1 do
       	 res := sc_addsq(res,
	    sc_multsq(sc_getmat(col1,i,1),sc_getmat(col2,i,1)));
      return res
   end;

procedure sc_getrow(matr,i);
   % Gets i-th row from matrix matr
   sc_igetv(matr,i-1);

procedure sc_igetv(v,i);
   igetv(v,i);

procedure sc_iputv(v,i,val);
   iputv(v,i,val);

procedure fs_minus(u);
   % my minus. [u] is a Lisp-prefix-form. Returns a lisp prefix form.
   % Efficiently performs reval({'minus,u}).
   if eqcar(u, 'minus) then
      cadr u
   else
      {'minus,u};

procedure fs_turn(a);
   % turn. [a] is one of the relations ['leq], ['geq], or ['equal].
   % Returns a relation $R such that $l [a] r$ is equivalent to $-l R
   % -r$.
   if a eq 'leq then
      'geq
   else if a eq 'geq then
      'leq
   else
      a;

endmodule;  % simplex.

end;  % of file
