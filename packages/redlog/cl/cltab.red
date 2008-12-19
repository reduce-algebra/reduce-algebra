% ----------------------------------------------------------------------
% $Id: cltab.red,v 1.9 1999/04/13 13:11:03 sturm Exp $
% ----------------------------------------------------------------------
% Copyright (c) 1995-1999 Andreas Dolzmann and Thomas Sturm
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

% $Log: cltab.red,v $
% Revision 1.9  1999/04/13 13:11:03  sturm
% Updated comments for exported procedures.
%
% Revision 1.8  1999/04/11 10:20:12  sturm
% Added call to rl_nnf in cl_gentheo1 such that non-positive formulas
% are treated as intended by rlgentheo now.
%
% Revision 1.7  1999/03/22 17:08:08  dolzmann
% Changed copyright information.
%
% Revision 1.6  1996/10/07 11:45:58  sturm
% Added fluids for CVS and copyright information.
%
% Revision 1.5  1996/10/01 10:17:26  reiske
% Added verbosity output in cl_atab.
%
% Revision 1.4  1996/09/30 16:57:28  sturm
% Switched to new tableau code.
%
% Revision 1.3  1996/08/01 11:44:59  reiske
% Major changes:
% New implementation of tableau method.
% Added procedure cl_gentheo.
%
% Revision 1.2  1996/07/07 14:34:21  sturm
% Turned some cl calls into service calls.
%
% Revision 1.1  1996/03/22 10:31:34  sturm
% Moved and split.
%
% ----------------------------------------------------------------------
lisp <<
   fluid '(cl_tab_rcsid!* cl_tab_copyright!*);
   cl_tab_rcsid!* := "$Id: cltab.red,v 1.9 1999/04/13 13:11:03 sturm Exp $";
   cl_tab_copyright!* := "(c) 1995-1999 by A. Dolzmann and T. Sturm"
>>;


module cltab;
% Common logic tableau method. Submodule of [cl].

procedure cl_tab(f,cdl);
   % Common logic tableau; simplification. [f] is a formula; [cdl] is
   % a list of atomic formulas. Returns a formula. The result is a
   % case distiction on the atomic formulas in [cdl] in conjunction
   % with corresponding specializations of [f].
   cl_mktf cl_tab1(f,cdl);

procedure cl_tab1(f,cdl);
   % Common logic tableau subroutine. [f] is a formula; [cdl] is a
   % list of atomic formulas. Returns a list of consed pairs of $(...,
   % (\phi_i . c_i), ...)$, where $c_i$ is in [cdl] and $\phi_i$ is a
   % specialization of [f] wrt. $c_i$.
   begin scalar w,ff,resl;
      for each atf in cdl do <<
	 ff := rl_simpl(f,{atf},-1);
	 if ff neq 'inctheo and ff neq 'false then
	    if (w := assoc(ff,resl)) then
	       cdr w := rl_simpl(rl_mkn('or,{atf,cdr w}),nil,-1)
	    else
	       resl := (ff . atf) . resl
      >>;
      return resl
   end;

procedure cl_mktf(resl);
   % Common logic make tableau formula. [resl] is a list of consed
   % pairs. Returns a formula. Uses a heuristic approach whether to
   % use the simplifier or not. Depends on the facilities of
   % [rl_simpl].
   begin scalar w,flg;
      w := resl;
      while w do
	 if (rl_tvalp caar w) or (cl_atfp caar w) then <<
	    w := nil;
	    flg := T
	 >> else
	    w := cdr w;
      return
	 if flg then
	    rl_simpl(rl_mkn('or,for each x in resl collect
      	       rl_mkn('and,{cdr x,car x})),nil,-1)
      	 else
	    rl_mkn('or,for each x in resl collect
      	       rl_mkn('and,{cdr x,car x}));
   end;

procedure cl_atab(f);
   % Common logic automatic tableau; simplification. [f] is a formula.
   % Returns a simplified equivalent of [f] or [f] itself. The result
   % is obtained by trying [cl_tab] with case distictions on the signs
   % of terms in [f] as [cdl].
   begin scalar w;
      w := cl_atab1 f;
      return if w then
	 cl_mktf w
      else
	 f  
   end;

procedure cl_atab1(f);
   % Common logic new automatic tableau subroutine. [f] is a formula.
   % Returns [nil] or a resl.
   begin scalar cdl,cdll,atnum,atnumold,atnumnf,nresl,resl,dpth;
      atnum := cl_atnum f;
      atnumold := atnum;
      cdll:= rl_a2cdl cl_atml f;
      if !*rlverbose then <<
	 ioto_tprin2t {atnum," = 100%"};
	 dpth := length cdll
      >>;
      while cdll do <<
 	 cdl := car cdll;
 	 cdll := cdr cdll;
	 nresl := cl_tab1(f,cdl);
 	 atnumnf := cl_atnum cl_mktf nresl;
      	 if !*rlverbose then <<
	    ioto_prin2 {"[",dpth,": ",atnumnf,"] "};
	    dpth := dpth - 1
	 >>;
	 if atnumnf < atnum then <<
    	    resl := nresl;
    	    atnum := atnumnf
	 >>
      >>;
      if !*rlverbose then
	 if atnum < atnumold then
	    ioto_tprin2t {"Success: ",atnumold," -> ",atnum}
      	 else
	    ioto_tprin2t {"No success, returning the original formula"};
      return resl
   end;

procedure cl_itab(f);
   % Common logic iterative tableau; simplification. [f] is a formula.
   % Returns a simplified equivalent of [f] or [f] itself. The result
   % is obtained by iterative application of [cl_atab]. Depends on the
   % switch [rltabib]. With [rltabib] on, the iteration is not
   % performed on the entire formula but on the single sepcialization
   % branches.
   if !*rltabib then cl_itab2 f else cl_itab1 f;

procedure cl_itab1(f);
   % Common logic iterative tableau subroutine. [f] is a formula.
   % The switch [rltabib] is off. Returns a formula.
   begin scalar w,res;
      w := cl_atab1 f;
      while w do <<
	 res := cl_mktf w;
      	 if !*rlverbose then
	    ioto_tprin2t {"Recomputing tableau."};
	 w:= cl_atab1 res
      >>;
      return res or f
   end;

procedure cl_itab2(f);
   % Common logic iterative tableau subroutine. [f] is a formula.
   % Iterate branchwise. Returns a formula.
   begin scalar w;
      w := cl_atab1 f;
      return if w then
	 cl_mktf for each res in w collect (cl_itab2 car res) . cdr res
      else
	 f
   end;

procedure cl_gentheo(theo,f,bvl);
   % Common logic generate theory. [theo] is THEORY; [f] is a
   % quantifier-free formula; [bvl] is a list of variables. Returns a
   % pair $(\Theta . \phi)$, where $\Theta$ is a THEORY extending
   % [theo] by inequalities, and $\phi$ is a formula such that $\Theta
   % \models \phi \longleftrightarrow [f]$. The additional assumptions
   % in $\Theta$ do not involve variables in [bvl].
   begin scalar w;
      w := cl_gentheo0(f,bvl);
      return rl_thsimpl(union(theo,car w)) . cdr w
   end;

procedure cl_gentheo0(f,bvl);
   % Generate theory. [f] is a quantifier-free formula; [bvl] is a
   % list of variables. Returns a pair $\theta . \phi$ where $\theta$
   % is a list of inequations not containing variables from [bvl], and
   % $\phi$ is a quantifier-free formula such that $\bigwedge \theta
   % \longrightarrow ([f] \longleftrightarrow \phi)$.
   begin scalar w,res,theo;
      while car (w:=cl_gentheo1(f,bvl)) do <<
	 res := cdr w;
	 theo := cdr res . theo;
	 f := car res
      >>;
      return theo . f
   end;

procedure cl_gentheo1(f,bvl);
   % Generate theory subroutine. [f] is a formula; [bvl] is a list of
   % variables. Returns a consed pair (flag . res).
   begin scalar cdl,result,nres,flag,theo;
      result := f;
      cdl := rl_getineq(rl_nnf f,bvl);
      for each ineq in cdl do <<
	 nres := rl_simpl(f,{ineq},-1) . ineq;
 	 if not cl_cmpfp(result,car nres) then <<
    	    result := car nres;
	    theo := cdr nres;
	    flag := T
 	 >>
      >>;
      return flag . (result . theo)
   end;

procedure cl_cmpfp(f,nf);
   % Generate theory compare formulas predicate. [f] and [nf] are
   % quantifier-free formulas. Returns a Boolean.
   cl_atnum f < cl_atnum nf;

endmodule;  % [cltab]

end;  % of file
