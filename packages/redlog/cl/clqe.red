% ----------------------------------------------------------------------
% $Id$
% ----------------------------------------------------------------------
% Copyright (c) 1995-2009 Andreas Dolzmann and Thomas Sturm
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
   fluid '(cl_qe_rcsid!* cl_qe_copyright!*);
   cl_qe_rcsid!* := "$Id$";
   cl_qe_copyright!* := "(c) 1995-2009 by A. Dolzmann and T. Sturm"
>>;

module clqe;
% Common logic quantifier elimination by elimination sets. Submodule
% of [cl]. Currently restricted to quadratic formulas.

%DS
% <CONTAINER ELEMENT> ::=
% (<VARLIST> . <FORMULA>) . (<ANSWER> . <ANSWER TRANSFORMATION>)
% <VARLIST> ::= <VARIABLE LIST> | 'BREAK
% <FORMULA> ::= "quantifier-free formula"
% <ANSWER> ::= (<SUBST_TRIPLET>,...) "[nil] if not ans"
% <SUBST_TRIPLET> ::= (<VARIABLE>, <SUBST_FUNCTION>, <ARGUMENT LIST>, <ATR>)
% <ANSWER TRANSFORMATION> ::= "context dependent, [nil] if not ans"

smacro procedure cl_mkcoel(vl,f,an,atr);
   % Common logic make container element. [vl] is a list of variables;
   % [f] is a quantifier-free formula; [an] is an answer; [atr] is an
   % answer transformation.
   (vl . f) . (an . atr);

smacro procedure cl_covl(x);
   % Common logic container variable list. [x] is a container element.
   % Returns the variable list from [x].
   caar x;

smacro procedure cl_cof(x);
   % Common logic container formula. [x] is a container element.
   % Returns the formula from [x].
   cdar x;

smacro procedure cl_coan(x);
   % Common logic container answer. [x] is a container element.
   % Returns the answer from [x].
   cadr x;

smacro procedure cl_coatr(x);
   % Common logic container answer translation. [x] is a container
   % element. Returns the answer transformation from [x].
   cddr x;

smacro procedure cl_co2j(x);
   % Common logic container to junction. [x] is a container element.
   % Returns the S-expression [cl_cpf(x) . cl_coan(x) . cl_coatr(x)].
   cdar x . cadr x . cddr x;

procedure cl_comember(ce,l);
   % Common logic container memeber. [ce] is a container element; [l]
   % is a list of container elements. Returns non-[nil], if there is
   % an container element $e$ in [l], such that the formula and the
   % variable list of $e$ are equal to the formula and variable list
   % of [ce]. This procedure does not use the access functions!
   if l then car ce = caar l or cl_comember(ce,cdr l);

procedure cl_gqe(f,theo,xbvl);
   % Common logic generic quantifier elimination. [f] is a formula;
   % [theo] is a THEORY; [xbvl] is a list of variables. Returns a pair
   % $\Theta . \phi$. $\Theta$ is a THEORY extending [theo] by
   % assumptions on free variables of [f] that are not in [xbvl];
   % $\phi$ is a formula. We have $\Theta \models [f]
   % \longleftrightarrow \phi$. $\phi$ is obtained from [f] by
   % eliminating as much quantifiers as possible. Accesses the switch
   % [rlqepnf]; if [rlqepnf] is on, then [f] has to be prenex.
   begin scalar w,theo,!*rlqegen,!*rlsipw,!*rlsipo;
      !*rlsipw := !*rlqegen := T;
      w := cl_qe1(f,theo,xbvl);
      theo := rl_thsimpl car w;
      return theo . rl_simpl(cdr w,theo,-1)
   end;

procedure cl_gqea(f,theo,xbvl);
   % Common logic generic quantifier elimination with answer. [f] is a
   % formula; [theo] is a THEORY; [xbvl] is a list of variables.
   % Returns a pair $\Theta . \Phi$. $\Theta$ is a THEORY extending
   % [theo] by assumptions on free variables of [f] that are not in
   % [xbvl]; $\Phi$ is a list $(..., (c_i, A_i), ...)$, where the
   % $c_i$ are quantifier-free formulas, and the $A_i$ are lists of
   % equations. We have $\Theta \models \bigvee_i c_i
   % \longleftrightarrow [f]$. Whenever some $c_i$ holds for an
   % interpretation of the parameters, then [f] holds, and $A_i$
   % describes a satisfying sample point. Accesses the switch
   % [rlqepnf]; if [rlqepnf] is on, then [f] has to be prenex.
   begin scalar w,theo,!*rlqegen,!*rlsipw,!*rlsipo,!*rlqeans;
      !*rlsipw := !*rlqegen := !*rlqeans := T;
      w := cl_qe1(f,theo,xbvl);
      theo := rl_thsimpl car w;
      return theo . cdr w
   end;

procedure cl_lqe(f,theo,pt);
   % Common logic local quantifier elimination. [f] is a formula;
   % [theo] is a THEORY; [pt] is a list of equations $v=z$, where $v$
   % is a variable and $z$ is an INTEGER, namely the suggested value
   % for the local parameter $v$. Returns a pair $\Theta . \phi$.
   % $\Theta$ is a THEORY extending [theo]; $\phi$ is a formula. We
   % have $\Theta \models [f] \longleftrightarrow \phi$. $\phi$ is
   % obtained from [f] by eliminating as much quantifiers as possible.
   % Accesses the switch [rlqepnf]; if [rlqepnf] is on, then [f] has
   % to be prenex. Accesses the fluids [cl_pal!*], [cl_lps!*], and
   % [cl_theo!*]. [cl_lps!*] is the list of local parameters; [cl_pal]
   % is a ALIST containing the suggested values for the local
   % parameters; and [cl_theo!*] is the theory generated by the local
   % quantifier elimination.  
   begin scalar w,theo,!*rlqelocal,!*rlsipw,!*rlsipo,cl_pal!*,cl_lps!*,
      	 cl_theo!*;
      !*rlsipw := !*rlqelocal := T;
      cl_pal!* := pt;
      cl_lps!* := for each x in pt collect car x;
      cl_theo!* := nil;
      w := for each x in theo collect rl_subat(cl_pal!*,x);
      w := rl_simpl(rl_smkn('and,w),nil,-1);
      if w eq 'false then
	 rederr "rllqe: inconsistent theory";
      w := cl_qe1(f,theo,nil);
      theo := nconc(cl_theo!*,theo);
      w := cdr w;
      cl_pal!* := cl_lps!* := cl_theo!* := nil;      
      return rl_lthsimpl(theo) . rl_simpl(w,theo,-1)
   end;

procedure cl_qe(f,theo);
   % Common logic quantifier elimination. [f] is a formula; [theo] is
   % a THEORY. Returns a formula $\phi$. We have $[theo] \models [f]
   % \longleftrightarrow \phi$. $\phi$ is obtained from [f] by
   % eliminating as much quantifiers as possible. Accesses the switch
   % [rlqepnf]; if [rlqepnf] is on, then [f] has to be prenex.
   begin scalar !*rlsipw,!*rlsipo;
      !*rlsipw := !*rlsipo := T;
      return cl_qe1(f,theo,nil)
   end;

procedure cl_qea(f,theo);
   % Common logic quantifier elimination with answer. [f] is a
   % formula; [theo] is a THEORY. Returns a list of pairs $(..., (c_i,
   % A_i), ...)$. The $c_i$ are quantifier-free formulas, and the
   % $A_i$ are lists of equations. We have $[theo] \models \bigvee_i
   % c_i \longleftrightarrow [f]$. Whenever some $c_i$ holds for an
   % interpretation of the parameters, [f] holds, and $A_i$ describes
   % a satisfying sample point. Accesses the switch [rlqepnf]; if
   % [rlqepnf] is on, then [f] has to be prenex.
   begin scalar !*rlsipw,!*rlsipo,!*rlqeans;
      !*rlsipw := !*rlsipo := !*rlqeans := T;
      return cl_qe1(f,theo,nil)
   end;

procedure cl_qe1(f,theo,xbvl);
   % Common logic quantifier elimination. [f] is a linear formula
   % which is prenex if the switch [rlqepnf] is off; [theo] is a list
   % of atomic formulas, which serve as background theory. If the
   % switch [rlqeans] and [rlqegen] is off a quantifier-free
   % equivalent of [f] is returned. With [rlqeans] on, a list
   % $(...(c_i,a_i)...)$ is returned, where the $c_i$ are
   % quantifier-free formulas, and the $a_i$ are lists of equations.
   % With [rlqegen] on, a pair $(\theta . \phi)$ is returned, such
   % that $\Theta \models [f] \longleftrightarrow \phi$.
   begin scalar svrlidentify,q,op,ql,varl,varll,delvarl,answer,result,
	 scvarll,xx,xxv,w,svrlqeprecise,svrlqeaprecise; integer n;
      if !*rlqepnf then f := rl_pnf f;
      f := rl_simpl(f,theo,-1);
      if f eq 'inctheo then return 'inctheo;
      if not rl_quap rl_op f then <<
	 result := if !*rlqeans then {{f,nil}} else f;
	 if !*rlqegen or !*rlqelocal then
	    result := theo . result;
	 return result
      >>;
      % Split [f] into its matrix, a quantifier list, a list of
      % variable lists, and a list off all quantified variables.
      q := op := rl_op f;
      repeat <<
	 if op neq q then <<
	    ql := q . ql;
	    varll := varl . varll;
	    q := op;
	    varl := nil
	 >>;
	 varl := rl_var f . varl;
	 delvarl := rl_var f . delvarl;
	 f := rl_mat f
      >> until not rl_quap(op := rl_op f);
      ql := q . ql;
      varll := varl . varll;
      % Remove atomic formulas containing quantified variables from
      % the theory
      theo := for each atf in theo join
	 if null intersection(rl_varlat atf,delvarl) then {atf};
      % Iteratively apply [cl_qeblock] to the quantifier blocks.
      svrlidentify := !*rlidentify;
      answer := nil . nil;
      while null car answer and ql do <<
	 on1 'rlidentify;
      	 q := car ql;
      	 ql := cdr ql;
      	 varl := car varll;
      	 varll := cdr varll;
      	 if !*rlverbose then
      	    ioto_tprin2 {"---- ",(q . reverse varl)};
	 svrlqeprecise := !*rlqeprecise;
	 svrlqeaprecise := !*rlqeaprecise;
	 if ql then <<
	    off1 'rlqeprecise;
	    off1 'rlqeaprecise
	 >>;
      	 answer := cl_qeblock(
	    f,q,varl,theo,!*rlqeans and null ql,union(delvarl,xbvl));
	 onoff('rlqeprecise,svrlqeprecise);
	 onoff('rlqeaprecise,svrlqeaprecise);
	 theo := cdr answer;
	 answer := car answer;
      	 f := cdr answer;
	 off1 'rlidentify
      >>;
      onoff('rlidentify,svrlidentify);
      % Requantify with the variables that could not be eliminated.
      if car answer then <<
	 if !*rlverbose then
 	    ioto_tprin2 "+++ Requantification ... ";
      	 if !*rlqeans and null ql then <<
 	    %% rederr "cl_qe: requantification impossible";
	    f := for each x in f collect <<
	       xx := car x;
	       xxv := cl_fvarl xx;
	       for each v in car answer do
		  if v memq xxv then
 		     xx := rl_mkq(q,v,xx);
	       scvarll := varll;
	       for each q in ql do <<
      	       	  varl := car scvarll;
      	       	  scvarll := cdr scvarll;
      	       	  for each v in varl do
		     if v memq xxv then
			xx := rl_mkq(q,v,xx)
      	       >>;
	       xx . cdr x
	    >>
	 >> else <<
      	    for each v in car answer do f := rl_mkq(q,v,f);
      	    for each q in ql do <<
      	       varl := car varll;
      	       varll := cdr varll;
      	       for each v in varl do f := rl_mkq(q,v,f)
      	    >>
	 >>;
	 if !*rlverbose then
 	    ioto_prin2t "done"
      >>;
      if !*rlqeans and null ql then <<
	 if !*rlverbose then <<
	    ioto_tprin2 "+++ Postprocessing answer:";
	    n := length f
	 >>;
 	 result := for each x in f collect <<
	    if !*rlverbose then ioto_prin2 {" [",n:=n-1};
 	    w := {car x,rl_qemkans(cadr x,cddr x)};
	    if !*rlverbose then ioto_prin2 {"]"};
	    w
	 >>;
      >> else <<
	 if !*rlverbose then
	    ioto_tprin2 {"+++ Final simplification ... ",cl_atnum f," -> "};
	 f := rl_simpl(f,theo,-1);
	 if !*rlverbose then
 	    ioto_prin2t cl_atnum f;
	 if !*rlqefb and car answer then <<
	    if not rl_quap rl_op f then <<
	       if !*rlverbose then
 		  ioto_tprin2 "++++ No more quantifiers after simplification";
	       result := f
	    >> else <<
	       if !*rlverbose then
		  ioto_tprin2 {"++++ Entering fallback QE: "};
	       result := rl_fbqe f
	    >>
	 >> else
	    result := f
      >>;
      if !*rlqegen or !*rlqelocal then
	 result := theo . result;
      return result
   end;

procedure cl_qeblock(f,q,varl,theo,ans,bvl);
   % Common logic quabtifier eliminate block. [f] is a quantifier-free
   % formula; [q] is a quantifier; [varl] is a variable list; [theo]
   % is the current theory; [ans] is Boolean.
   begin scalar w;
      if q eq 'ex then
 	 return cl_qeblock1(rl_simpl(f,theo,-1),varl,theo,ans,bvl);
      % [q eq 'all]
      w := cl_qeblock1(rl_simpl(rl_nnfnot f,theo,-1),varl,theo,ans,bvl);
      theo := cdr w;
      w := car w;
      if ans then
 	 return (car w . for each x in cdr w collect
 	    rl_nnfnot car x . cdr x) . theo;
      return (car w . rl_nnfnot cdr w) . theo
   end;

procedure cl_qeblock1(f,varl,theo,ans,bvl);
   % Common logic quantifier eliminate block 1.
   if !*rlqeheu then
      cl_qeblock2(f,varl,theo,ans,bvl)
   else
      cl_qeblock3(f,varl,theo,ans,bvl);

procedure cl_qeblock2(f,varl,theo,ans,bvl);
   % Common logic quantifier eliminate block 2. [f] is a
   % quantifier-free formula; [varl] is a list of variables; [theo] is
   % a list of atomic formulas; [ans] is bool. With [rlqeheu] on,
   % check for decision problem.
   begin scalar !*rlqedfs,atl;
      atl := cl_atl1 f;
      !*rlqedfs := T;
      while atl do
	 if setdiff(rl_varlat car atl,varl) then
	    !*rlqedfs := atl := nil
	 else
	    atl := cdr atl;
      return cl_qeblock3(f,varl,theo,ans,bvl)
   end;

procedure cl_qeblock3(f,varl,theo,ans,bvl);
   % Common logic quantifier eliminate block 3. [f] is a
   % quantifier-free formula; [varl] is a list of variables; [theo] is
   % a list of atomic formulas; [ans] is bool.
   begin scalar w,co,remvl,newj,cvl,coe; integer c,vlv,dpth,count,delc,oldcol;
      if !*rlverbose then <<
	 dpth := length varl;
      	 if !*rlqedfs then <<
	    vlv :=  dpth / 4;
	    ioto_prin2t {" [DFS: depth ",dpth,", watching ",dpth - vlv,"]"}
      	 >> else
	    ioto_prin2t {" [BFS: depth ",dpth,"]"}
      >>;
      cvl := varl;
      if !*rlqegsd then f := rl_gsd(f,theo);
      if rl_op f = 'or then
	 for each x in rl_argn f do
	    co := cl_save(co,{cl_mkcoel(cvl,x,nil,nil)})
      else
      	 co := cl_save(co,{cl_mkcoel(cvl,f,nil,nil)});
      while co do <<
	 on1 'rlidentify;
	 w := cl_get(co);
 	 co := cdr w;
	 coe := car w;
    	 cvl := cl_covl coe;
	 count := count+1;
         if !*rlverbose then
   	    if !*rlqedfs then <<
	       if vlv = length cvl then
	       	  ioto_tprin2t {"-- crossing: ",dpth - vlv};
	       ioto_prin2 {"[",dpth - length cvl}
	    >> else <<
	       if c=0 then <<
	       	  ioto_tprin2t {"-- left: ",length cvl};
		  c := cl_colength(co) + 1
	       >>;
	       ioto_nterpri(length explode c + 4);
	       ioto_prin2 {"[",c};
	       c := c - 1
	    >>;
	 w := cl_qevar(
	    cl_cof coe,cl_covl coe,cl_coan coe,cl_coatr coe,theo,ans,bvl);
	 theo := cdr w;
	 w := car w;
	 if car w then <<  % We have found a suitable variable.
	    w := cdr w;
	    if w then
	       if cl_covl car w eq 'break then <<
	       	  co := nil;
	       	  newj := {cl_co2j car w}
	       >> else if cdr cvl then <<
		  if !*rlverbose then oldcol := cl_colength(co);
	       	  co := cl_save(co,w);
 		  if !*rlverbose then
		     delc := delc + oldcol + length w - cl_colength(co)
	       >> else
   		  for each x in w do newj := lto_insert(cl_co2j x,newj)
	 >> else <<  % There is no eliminable variable.
	    % Invalidate this entry, and save its variables for later
	    % requantification.
%	    if !*rlverbose then ioto_prtmsg("+++" . cdr w);
	    if !*rlverbose then ioto_prin2("FAILURE:" . cdr w);
	    remvl := union(cvl,remvl);
	    newj := lto_insert(cl_co2j coe,newj)
	 >>;
	 if !*rlverbose then <<
	    ioto_prin2 "] ";
	    if !*rlqedfs and null cvl then ioto_prin2 ". "
	 >>
      >>;
      if !*rlverbose then ioto_prin2{"[DEL:",delc,"/",count,"]"};
      if ans then return (remvl . newj) . theo;
      return (remvl . rl_smkn('or,for each x in newj collect car x)) . theo
   end;

procedure cl_qevar(f,vl,an,atr,theo,ans,bvl);
   % Quantifier eliminate one variable. [f] is a quantifier-free
   % formula; [vl] is a non-empty list of variables; [an] is an
   % answer; [theo] is a list of atomic formulas; [ans] is Boolean.
   % Returns a pair $a . p$. Either $a=[T]$ and $p$ is a pair of a
   % list of container elements and a theory or $a=[nil]$ and $p$ is
   % an error message. If there is a container element with ['break]
   % as varlist, this is the only one.
   begin scalar w,candvl,v,alp,hit,ww,status; integer len;
      for each vv in vl do
	 if cdr (w := rl_transform(f,vv)) then <<
	    hit := T;
	    f := car w;
	    atr := rl_updatr(atr,cdr w)
	 >>;
      if hit then f := rl_simpl(f,theo,-1);
      w := rl_trygauss(f,vl,theo,ans,bvl);
      if w neq 'failed then <<
	 theo := cdr w;
	 w := car w;
      	 if !*rlverbose then ioto_prin2 "g";
	 vl := delq(car w,vl);
	 ww := cl_esetsubst(f,car w,cdr w,vl,an,atr,theo,ans,bvl);
	 if !*rlqelocal then
	    return (T . car ww) . cl_theo!*
	 else
	    return (T . car ww) . cdr ww
      >>;
      w := rl_specelim(f,vl,theo,ans,bvl);
      if w neq 'failed then
	 return w;
      % elimination set method
      if null cdr vl then
	 candvl := vl
      else if !*rlqevarsel then
      	 candvl := rl_varsel(f,vl,theo)
      else
	 candvl := {car vl};
      if !*rlverbose and (len:=length candvl) > 1 then
 	 ioto_prin2 {"{",len,":"};
      w := nil;
      while candvl do <<
	 v := car candvl;
	 candvl := cdr candvl;
      	 alp := cl_qeatal(f,v,theo,ans);
      	 if alp = '(nil . nil) then <<  % [v] does not occur in [f].
      	    if !*rlverbose then ioto_prin2 "*";
      	    w := {cl_mkcoel(delq(v,vl),f,ans and an,ans and atr)};
	    status := 'nonocc;
	    candvl := nil
      	 >> else if car alp = 'failed then
	    (if null w then <<
	       w := cdr alp;
	       status := 'failed
	    >>)
	 else <<
      	    if !*rlverbose then ioto_prin2 "e";
      	    ww := cl_esetsubst(f,v,rl_elimset(v,alp),delq(v,vl),an,atr,
	       theo,ans,bvl);
	    if !*rlqelocal then <<
	       candvl := nil;
	       w := ww;
	       status := 'local
	    >> else if rl_betterp(ww,w) then <<
	       w := ww;
	       status := 'elim
	    >>
      	 >>
      >>;
      if !*rlverbose and len>1 then ioto_prin2 {"}"};
      if status eq 'nonocc then
	 return (t . w) . theo;
      if status eq 'failed then
	 return (nil . w) . theo;
      if status eq 'local then
      	 return (t . car w) . cl_theo!*;
      if status eq 'elim then
	 return (t . car w) . cdr w;
      rederr {"cl_qevar: bad status",status}
   end;

procedure cl_esetsubst(f,v,eset,vl,an,atr,theo,ans,bvl);
   % Common logic elimination set substitution. [f] is a
   % quantifier-free formula; [v] is a kernel; [eset] is an
   % elimination set; [an] is an answer; [atr] in an answer
   % translation; [theo] is the current theory; [ans] is Boolean.
   % Returns a pair $l . \Theta$, where $\Theta$ is the new theory and
   % $l$ is a list of container elements. If there is a container
   % element with ['break] as varlist, this is the only one.
   begin scalar a,d,u,elimres,junct,bvl,w;
      while eset do <<
	 a := caar eset;
	 d := cdar eset;
	 eset := cdr eset;
	 while d do <<
	    u := car d;
	    d := cdr d;
	    w := apply(a,bvl . theo . f . v . u);
	    theo := union(theo,car w);
	    elimres := rl_simpl(cdr w,theo,-1);
	    if !*rlqegsd then
	       elimres := rl_gsd(elimres,theo);
	    if elimres eq 'true then <<
	       junct := {cl_mkcoel('break,elimres,
		  cl_updans(v,a,u,an,atr,ans),ans and atr)};
	       eset := d := nil
	    >> else if elimres neq 'false then
	       if rl_op elimres eq 'or then
		  for each subf in rl_argn elimres do
		     junct := cl_mkcoel(vl,subf,
			cl_updans(v,a,u,an,atr,ans),ans and atr) . junct
	       else
		  junct := cl_mkcoel(vl,elimres,
		     cl_updans(v,a,u,an,atr,ans),ans and atr) . junct;
      	 >>
      >>;
      return junct . theo
   end;

procedure cl_updans(v,a,u,an,atr,ans);
   ans and {v,a,u,atr} . an;

procedure cl_qeatal(f,v,theo,ans);
   % Common logic quantifier elimination atomic formula list. [f] is a
   % formula; [v] is avariable; [theo] is the current theory, [ans] is
   % Boolean. Returns an ALP.
   cl_qeatal1(f,v,theo,T,ans);

procedure cl_qeatal1(f,v,theo,flg,ans);
   % Common logic quantifier elimination ataomic formula list. [f] is
   % aformula; [v] is avariable; [theo] is the current theory, [flg]
   % and [ans] are Boolean. Returns an ALP. If [flg] is non-[nil] [f]
   % has to be considered negated.
   begin scalar op,w,ww;
      op := rl_op f;
      w := if rl_tvalp op then
	 {nil . nil}
      else if op eq 'not then
      	 {cl_qeatal1(rl_arg1 f,v,theo,not flg,ans)}
      else if rl_junctp op then
      	 for each subf in rl_argn f collect
      	    cl_qeatal1(subf,v,theo,flg,ans)
      else if op eq 'impl then
      	 {cl_qeatal1(rl_arg2l f,v,theo,not flg,ans),
	    cl_qeatal1(rl_arg2r f,v,theo,flg,ans)}
      else if op eq 'repl then
	 {cl_qeatal1(rl_arg2l f,v,theo,flg,ans),
	    cl_qeatal1(rl_arg2r f,v,theo,not flg,ans)}
      else if op eq 'equiv then
	 {cl_qeatal1(rl_arg2l f,v,theo,not flg,ans),
	    cl_qeatal1(rl_arg2r f,v,theo,flg,ans),
            cl_qeatal1(rl_arg2l f,v,theo,flg,ans),
	    cl_qeatal1(rl_arg2r f,v,theo,not flg,ans)}
      else if rl_quap op then
	 rederr "argument formula not prenex"
      else  % [f] is an atomic formula.
      	 {rl_translat(f,v,theo,flg,ans)};
      if (ww := atsoc('failed,w)) then return ww;
      return cl_alpunion w
   end;

procedure cl_alpunion(pl);
   % Common logic ALP union. [pl] is a list of ALP's. Returns the
   % union of all ALP's in [pl].
   begin scalar uall,pall;
      for each pair in pl do <<
	 uall := car pair . uall;
	 pall := cdr pair . pall
      >>;
      return lto_alunion(uall) . lto_almerge(pall,'plus2)
   end;

procedure cl_save(co,dol);
   % Common logic save into container. [co] is a container; [dol] is a
   % list of container elements. Returns a container.
   if !*rlqedfs then cl_push(co,dol) else cl_enqueue(co,dol);

procedure cl_push(co,dol);
   % Common logic push into container. [co] is a container; [dol] is a
   % list of container elements. Returns a container.
   <<
      for each x in dol do co := cl_coinsert(co,x);
      co
   >>;

procedure cl_coinsert(co,ce);
   % Common logic insert into container. [co] is a container; [ce] is
   % a container element. Returns a container.
   if cl_comember(ce,co) then co else ce . co;

procedure cl_enqueue(co,dol);
   % Common logic enqueue into container. [co] is a container; [dol]
   % is a list of container elements. Returns a container.
   <<
      if null co and dol then <<
	 co := {nil,car dol};
	 car co := cdr co;
	 dol := cdr dol
      >>;
      for each x in dol do
	 if not cl_comember(x,cdr co) then
	    car co := (cdar co := {x});
      co
   >>;

procedure cl_get(co);
   % Common logic get from container. [co] is a container. Returns a
   % pair $(e . c)$ where $e$ is a container element and $c$ is the
   % container [co] without the entry $e$.
   if !*rlqedfs then cl_pop(co) else cl_dequeue(co);

procedure cl_pop(co);
   % Common logic pop from container. [co] is a container. Returns a
   % pair $(e . c)$ where $e$ is a container element and $c$ is the
   % container [co] without the entry $e$.
   co;

procedure cl_dequeue(co);
   % Common logic dequeue from container. [co] is a container. Returns
   % a pair $(e . c)$ where $e$ is a container element and $c$ is the
   % container [co] without the entry $e$.
   if co then cadr co . if cddr co then (car co . cddr co);

procedure cl_colength(co);
   % Common logic container length. [co] is a container. Returns the
   % number of elements in [co].
   if !*rlqedfs or null co then length co else length co - 1;

procedure cl_betterp(new,old);
   begin integer atn;
      atn := cl_betterp!-count car new;
      if !*rlverbose then ioto_prin2 {"(",atn,")"};
      return null old or atn < cl_betterp!-count car old
   end;

procedure cl_betterp!-count(coell);
   % [coell] is a list of container elements.
   for each x in coell sum rl_atnum cl_cof x;

procedure cl_qeipo(f,theo);
   % Common logic quantifier elimination in position. [f] is a
   % positive formula; [theo] is a THEORY. Returns a quantifier-free
   % formula equivalent to [f] wrt. [theo] by recursively making [f]
   % anti-prenex and eliminating the quantifiers.
   begin scalar w,!*rlqeans;
      repeat <<
	 w := cl_qeipo1(cl_apnf rl_simpl(f,theo,-1),theo);
	 f := cdr w
      >> until not car w;
      return f
   end;

procedure cl_qeipo1(f,theo);
   % Quantifier eliminate in position subroutine.
   begin scalar op,nf,a,argl,ntheo;
      op := rl_op f;
      if rl_quap op then <<
	 for each subf in theo do
	    if not(rl_var f memq rl_varlat subf) then
 	       ntheo := subf . ntheo;
	 nf := cl_qeipo1(rl_mat f,ntheo);
	 if car nf then
	    return T . rl_mkq(op,rl_var f,cdr nf);
	 a := rl_qe(rl_mkq(op,rl_var f,cdr nf),ntheo);
	 if rl_quap rl_op a then
	    rederr "cl_qeipo1: Could not eliminate quantifier";
	 return T . a
      >>;
      if rl_junctp op then <<
      	 argl := rl_argn f;
	 if op eq 'and then
	    for each subf in argl do
	       if cl_atfp subf then theo := subf . theo;
	 if op eq 'or then
	    for each subf in argl do
	       if cl_atfp subf then theo := rl_negateat subf . theo;
	 while argl do <<
	    a := cl_qeipo1(car argl,theo);
	    nf := cdr a . nf;
	    argl := cdr argl;
	    if car a then <<
	       nf := nconc(reversip nf,argl);
	       argl := nil
	    >>
	 >>;
	 return
	    if car a then
	       T . rl_mkn(op,nf)
	    else
 	       nil . rl_mkn(op,reversip nf)
      >>;
      % f is atomic.
      return nil . f
   end;

procedure cl_qews(f,theo);
   % Common logic quantifier elimination with selection. [f] is a
   % formula; [theo] is a THEORY. Returns a quantifier-free formula
   % equivalent to [f] wrt. [theo] by selecting a quantifier from the
   % innermost block, moving it inside as far as possible and
   % eliminating it. Accesses the switch [rlqepnf]; if [rlqepnf] is
   % on, then [f] has to be prenex.
   begin scalar q,op,ql,varl,varll,!*rlqeans;
      if !*rlqepnf then
	 f := rl_pnf f;
      f := rl_simpl(f,theo,-1);
      if not rl_quap rl_op f then
	 return f;
      % Split [f] into its matrix, a quantifier list, and a list of
      % variable lists.
      q := rl_op f;
      while rl_quap(op:=rl_op f) do <<
	 if op neq q then <<
	    ql := q . ql;
	    varll := varl . varll;
	    q := op;
	    varl := nil
	 >>;
	 varl := rl_var f . varl;
	 f := rl_mat f;
      >>;
      ql := q . ql;
      varll := varl . varll;
      while ql do <<
	 q := car ql;
	 ql := cdr ql;
	 varl := car varll;
	 varll := cdr varll;
	 if q eq 'ex then
	    f := cl_qews1(varl,f,theo)
	 else
	    f := rl_nnfnot cl_qews1(varl,rl_nnfnot f,theo)
      >>;
      return f
   end;

procedure cl_qews1(varl,mat,theo);
   % Common logic quantifier eliminate with selection subroutine.
   % [varl] is a list of variables; [mat] is a quantifier-free
   % formula; [theo] is a list of atomic formulas. Returns a formula,
   % where all existentially quantified variables from [varl] are
   % eliminated.
   begin scalar v,w;
      while varl do <<
	 w := rl_trygauss(mat,varl,theo,nil,nil);
	 if w eq 'failed then <<
	    v := rl_varsel(mat,varl,theo);
 	    mat := cl_qeipo(rl_mkq('ex,v,mat),theo)
	 >> else <<
	    v := caar w;
	    mat := rl_qe(rl_mkq('ex,v,mat),theo)
	 >>;
	 varl := delete(v,varl)
      >>;
      return mat
   end;

%DS
% <GRV> ::= ['failed] | (<KERNEL> . <ELIMINATION SET>) . <THEORY>
% <IGRV> ::= (['failed] . [nil]) |
%    ['gignore] . ([nil] . <THEORY SUPPLEMENT>) |
%    <GAUSS TYPE IDENTIFICATION> . (<ELIMINATION SET> . <THEORY SUPPLEMENT>)
% <GAUSS TYPE IDENTIFICATION> ::= ("verbose output", <DATA>,...)

procedure cl_trygauss(f,vl,theo,ans,bvl);
   % Common logic try Gauss elimination. [f] is a quantifier-free
   % formula; [vl] is a list of variables existentially quantified in
   % the current block; [theo] a THEORY; [ans] is bool; [bvl] is a
   % list of variables. Returns a GRV, where no assumption on the
   % variables in [bvl] are made.
   begin scalar w;
      w := cl_trygauss1(f,vl,theo,ans,bvl);
      if w eq 'failed then return 'failed;
      return car w . union(cdr w,theo)
   end;

procedure cl_trygauss1(f,vl,theo,ans,bvl);
   % Try deep Gauss elimination. [f] is a quantifier-free formula; [vl] is
   % the current existential variable block; [theo] is a list of
   % atomic formulas, the current theory; [ans] is Boolean; [bvl] is a
   % list of variables that are considered non-parametric. Returns
   % a GRV.
   begin scalar w,v,csol,ev;
      csol := '(failed . nil);
      if null !*rlqevarsel then
	 vl := {car vl};
      while vl do <<
	 v := car vl;
	 vl := cdr vl;
	 w := cl_trygaussvar(f,v,theo,ans,bvl);
	 if car w neq 'gignore and rl_bettergaussp(w,csol) then <<
	    csol := w;
	    ev := v;
	    if rl_bestgaussp(csol) then
	       vl := nil;
	 >>;
      >>;
      if car csol eq 'failed then return 'failed;
      if !*rlverbose then
	 ioto_prin2 caar csol;
      return (ev . cadr csol) . cddr csol;
   end;

procedure cl_trygaussvar(f,v,theo,ans,bvl);
   % Try Gauss elimination wrt. one variable. [f] is a formula; [v]
   % is a kernel; [theo] is a theory; [ans] is Boolean; [bvl] is a
   % list of kernels. Returns a IGRV.
   <<
      if cl_atfp f then
	 rl_qefsolset(f,v,theo,ans,bvl)
      else if rl_op f eq 'and then
	 cl_gaussand(rl_argn f,v,theo,ans,bvl)
      else if rl_op f eq 'or then
	 cl_gaussor(rl_argn f,v,theo,ans,bvl)
      else % TODO: Gauss elimination for formulas with extended Boolean op's
	 '(failed . nil)
   >>;

procedure cl_gaussand(fl,v,theo,ans,bvl);
   begin scalar w, curr;
      curr := cl_trygaussvar(car fl,v,theo,ans,bvl);
      fl := cdr fl;
      while fl and not(rl_bestgaussp curr) do <<
      	 w := cl_trygaussvar(car fl,v,theo,ans,bvl);
	 curr := cl_gaussintersection(w,curr);
	 fl := cdr fl
      >>;
      return curr
   end;

procedure cl_gaussor(fl,v,theo,ans,bvl);
   begin scalar w,curr;
      curr := cl_trygaussvar(car fl,v,theo,ans,bvl);
      fl := cdr fl;
      while fl and (car curr neq 'failed) do <<
	 w := cl_trygaussvar(car fl,v,theo,ans,bvl);
	 fl := cdr fl;
	 curr := cl_gaussunion(curr,w)
      >>;
      return curr
   end;

procedure cl_gaussunion(grv1,grv2);
   begin scalar tag,eset,theo;
      if car grv1 eq 'failed or car grv2 eq 'failed then
	 return '(failed . nil);
      tag := if car grv1 eq 'gignore then
	 car grv2
      else if car grv2 eq 'gignore then
	 car grv1
      else if rl_bettergaussp(grv1,grv2) then
	 car grv2
      else
	 car grv1;
      eset := rl_esetunion(cadr grv1,cadr grv2);
      theo := union(cddr grv1,cddr grv2);
      return tag . ( eset . theo )
   end;

procedure cl_gaussintersection(grv1,grv2);
   if car grv1 eq 'gignore and car grv2 eq 'gignore then
      if length cddr grv1 < length cddr grv2 then grv1 else grv2
   else if car grv1 eq 'gignore then grv2
   else if car grv2 eq 'gignore then grv1
   else if rl_bettergaussp(grv1,grv2) then grv1 else grv2;

procedure cl_specelim(f,vl,theo,ans,bvl);
   % Common logic special elimination. [f] is a quantifier-free
   % formula; [vl] is a list of variables existentially quantified in
   % the current block; [theo] a THEORY; [ans] is bool; [bvl] is a
   % list of variables. Returns a GRV.
   'failed;

procedure cl_fbqe(f);
   % Common logic fallback quantifier elimination. [f] is a formula.
   % returns a formula equivalent to [f].
   <<
      if !*rlverbose then
	 ioto_tprin2t "+++ no fallback QE specified";
      f
   >>;
   
endmodule;  % [clqe]

end;  % of file
