module ofsfdpep;

revision('ofsfdpep, "$Id$");

copyright('ofsfdpep, "(c) 1995-2013 A. Dolzmann, T. Sturm");

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

switch rldpepverbose,rldpepiverbose;

on1 'rldpepverbose;
off1 'rldpepiverbose;

fluid '(!*ofsf_expf !*rlpepeval);

procedure ofsf_dpepverbosep();
   % PEP verbose predicate.
   !*rlverbose and !*rldpepverbose;

procedure ofsf_dpepiverbosep();
   % PEP verbose predicate.
   !*rlverbose and !*rldpepiverbose;

procedure ofsf_dpep(ophi,k);
   begin scalar qexp,ophiexp,phi,psiprime,phiprime,k;
        !*ofsf_expf := intern gensym();
        !*rlpepeval := nil;

        % Verify if k positive.
        if minusf k
        then
           rederr "Accuracy value has to be positive.";

        % Verify ophi.
        ofsf_pepcheck(ophi);

        if ofsf_expfree(ophi)
        then
           return ofsf_cad(ophi,nil,nil);

	% Preparation of the original phi
        if ofsf_dpepverbosep() or ofsf_dpepiverbosep()
        then
           ioto_tprin2t "++++ DPEP Preparation Phase";

        % dotted pair (x_1.Q_1), where exp(x_1)
        qexp := rl_var ophi.rl_op ophi;

        % substitute in ophi the exponential function by
        % the variable !*ofsf_expf
        ophiexp := cl_apply2ats1(ophi,
                 function(lambda x,qexp; ofsf_0mk2(ofsf_op x,
                    ofsf_pepsubf(ofsf_arg2l x,{'expt,'e,car qexp},
                                 !*ofsf_expf))),{qexp});

        phi := rl_mat ophiexp; % phi = Q_2 x_2 ... Q_n x_n psi

	% QE of phi (by CAD) if phi is not quantifier-free.
        if cl_qvarl1 phi
        then <<
           if ofsf_dpepverbosep() or ofsf_dpepiverbosep()
           then <<
              ioto_tprin2t "++++ DPEP QE by CAD";
              % QE of phi (by CAD)
	      psiprime := ofsf_cad(phi,nil,nil)
           >> else <<
              if !*rlverbose and !*rlcadverbose
              then <<
                 off1 'rlverbose;
                 off1 'rlcadverbose;
                 % QE of phi (by CAD)
	         psiprime := ofsf_cad(phi,nil,nil);
                 on1 'rlverbose;
	         on1 'rlcadverbose
              >> else
	         % QE of phi (by CAD)
	         psiprime := ofsf_cad(phi,nil,nil);
           >>
        >> else psiprime := phi;

	% Combine Q_1x_1 with q.-free formula psiprime
	phiprime := rl_mkq(cdr qexp,car qexp,psiprime);

        % If QE by CAD fails, i.e. if phiprime is not
        % an univariate poly.-expon. decision problem.
        if null (length cl_qvarl1 phiprime eq 1 or
           rl_mat phiprime eq 'false or
           rl_mat phiprime eq 'true)
        then
           rederr "QE by CAD and decision procedure failed.";

	% Decide univariate polynomial-exponential problem
	return
           (if rl_mat phiprime eq 'false or
               rl_mat phiprime eq 'true
            then
	       cl_simpl(rl_mat phiprime,nil,-1)
	    else
	       ofsf_dupep(phiprime,k))
   end;

procedure ofsf_dupep(phiprime,k);
   % Deciding univariate exponential problem. [phiprime] is a formula
   % in the following form: Qx psi(x) , where psi is a qu.-free formula
   % of the extension of the first-order theory of the real closed field
   % and Qx is a quantifier. See thesis. [k] is an integer, which
   % denotes the accuracy by the computation of the exponential
   % function. Returns the truth value of phiprime.
   begin scalar qexp,ccr,ppr,csb,cbases,contsb,pprtsb,pbases,psb,ilist,
                isol,hatlist,splist,cellstogo,tv;
      % dotted pair (x_1.Q_1), where exp(x_1).
      qexp := rl_var phiprime . rl_op phiprime;

      if ofsf_dpepverbosep() or ofsf_dpepiverbosep()
      then <<
         terpri();
         ioto_prin2t{"++++ Decide UPEP"}
      >>;

      % reordering wrt. !*ofsf_expf,x_1
      setkorder {!*ofsf_expf,car qexp};
      phiprime := cl_apply2ats(phiprime,
         function(lambda(x);ofsf_0mk2(ofsf_op x,reorder ofsf_arg2l x)));

      if ofsf_dpepverbosep() or ofsf_dpepiverbosep()
      then <<
         maprint("P := ",0);
         maprint('list .for each f in cl_terml phiprime collect
                prepf ofsf_pepsubf(f,!*ofsf_expf,{'expt,'e,car qexp}),0);
         terpri!*(nil)
      >>;
      % contents and primitive parts.
      ccr := for each c in cl_terml phiprime collect
                ofsf_contenty(c,!*ofsf_expf);
      ppr := for each p in cl_terml phiprime collect
                ofsf_prparty(p,!*ofsf_expf);

      % squarefree bases.
      csb := for each c in ccr collect sfto_sqfdecf(c);
      psb := for each p in ppr collect sfto_sqfdecf(p);

      % csb, and psb are a list which contain for
      % each c/p in ccr/ppr a list $((q_1 . 1),(q_2 . 2),...,(q_n . n))$
      % such that $\prod q_i^i = c$/ $\prod q_i^i = p$ with the
      % $q_i$ square-free and pairwise relatively prime.
      % Collect the q_i of each list.

      for each c in csb do
         for each i in c do contsb := cons(car i,contsb);

      for each p in psb do
         for each i in p do pprtsb := cons(car i,pprtsb);

      % Eliminate duplicates in contsb and pprtsb.
      while contsb do
         if member(car contsb,cdr contsb)
         then
            contsb := cdr contsb
         else <<
            cbases := cons(car contsb,cbases);
            contsb := cdr contsb
         >>;

      while pprtsb do
         if member(car pprtsb,cdr pprtsb)
         then
            pprtsb := cdr pprtsb
         else <<
            pbases := cons(car pprtsb,pbases);
            pprtsb := cdr pprtsb
         >>;

      if ofsf_dpepverbosep() or ofsf_dpepiverbosep()
      then <<
         maprint("K := ",0);
         maprint('list . for each f in cbases collect
               prepf ofsf_pepsubf(f,!*ofsf_expf,{'expt,'e,car qexp}),0);
         terpri!*(nil);
         maprint("Q := ",0);
         maprint('list . for each f in pbases collect
               prepf ofsf_pepsubf(f,!*ofsf_expf,{'expt,'e,car qexp}),0);
         terpri!*(nil)
      >>;

      % isolation list for each polynomial in K, and Q.
      for each c in cbases do <<
         if ofsf_dpepverbosep() or ofsf_dpepiverbosep()
         then <<
            terpri();
            maprint("+++ ISOL(",0);
            maprint(prepf ofsf_pepsubf(c,!*ofsf_expf,{'expt,'e,car qexp}),0);
            maprint(")",0);
            terpri!*(nil)
         >>;
         ilist := ofsf_pepisolate(c,car qexp,!*ofsf_expf,k);
         % c is aex.
         c := aex_fromsf ofsf_pepsubf(c,!*ofsf_expf,{'expt,'e,car qexp});
         ilist := for each i in ilist join {{'anu,c,i}};
         for each i in ilist do
            isol := cons(i,isol)
      >>;

      for each p in pbases do <<
         if ofsf_dpepverbosep() or ofsf_dpepiverbosep()
         then <<
            terpri();
            maprint("+++ ISOL(",0);
            maprint(prepf ofsf_pepsubf(p,!*ofsf_expf,{'expt,'e,car qexp}),0);
            maprint(")",0);
            terpri!*(nil)
         >>;
         ilist := ofsf_pepisolate(p,car qexp,!*ofsf_expf,k);
         % p is aex.
         p := aex_fromsf ofsf_pepsubf(p,!*ofsf_expf,{'expt,'e,car qexp});
         ilist := for each i in ilist join {{'anu,p,i}};
         for each i in ilist do isol :=
            cons(i,isol)
      >>;
      isol := reverse isol;

      % sort isol by its intervals.
      if isol
      then
         isol := anu_sortlist(isol);

      % Refine the isolating intervals in the list of the ANUs for
      % the zeros of all the p*(x) \in isolc \union isolp such that
      % we obtain an isolation list for the product q^(x) of all p*(x)
      % in the list of ANUs.
      if isol
      then
         hatlist := anu_refinelist(isol,car qexp,k);

      % Construct sample points for all of the cells
      % of the decomposition of the real line.
      % For the representation of sample points see thesis.
      if hatlist
      then
         splist := ofsf_pepsplist(hatlist)
      else
         splist := {{'anu,aex_fromsf nil,iv_mk(negsq rat_1 (),rat_1 ())}};

      if ofsf_dpepverbosep() or ofsf_dpepiverbosep()
      then <<
         terpri();
         ioto_prin2t{"+++ Cell Decomposition: ",length splist," cells"};
         for each sp in splist do
            iv_pepprint(anu_iv sp);
         terpri!*(nil)
      >>;

      % Evaluate the truth value of phiprime by using the sample points.
      if ofsf_dpepverbosep() or ofsf_dpepiverbosep()
      then <<
         terpri();
         ioto_prin2t {"+++ Sign-Evaluation for ",cl_atnum(phiprime),
                      " polynomials in ",length splist," cells"}
      >>;

      !*rlpepeval := t;

      % substitute !*ofsf_expf with '(expt e x_1) in phiprime
      phiprime := cl_apply2ats1(phiprime,
              function (lambda x,qexp; ofsf_0mk2(ofsf_op x,
              ofsf_pepsubf(ofsf_arg2l x,!*ofsf_expf,
                           {'expt,'e,car qexp}))),
              {qexp});

      cellstogo := length splist; % for verbose output
      for each sp in splist do <<
         if ofsf_dpepverbosep() or ofsf_dpepiverbosep()
         then <<
            maprint("[",0);
            maprint(cellstogo,0);
            maprint("sgn(",0)
         >>;
         tv := tv.ofsf_pepevalqff(cl_nnf rl_mat phiprime,sp,car qexp,k);
         cellstogo := cellstogo-1
      >>;

      if tv
      then
         if cdr qexp eq 'all
         then
            if smember('false,tv)
            then
               return cl_simpl('false,nil,-1)
            else
               return cl_simpl('true,nil,-1)
         else
            if smember('true,tv)
            then
               return cl_simpl('true,nil,-1)
            else
               return cl_simpl('false,nil,-1);
      return cl_simpl(phiprime,nil,-1)
   end;

procedure ofsf_pepevalqff(f,sp,id,k);
   % Evaluate quantifier-free formula at sample point. [f] is a
   % quantifier-free OFSF formula; [sp] is a sample point.
   % [k] is an integer, which denotes the accuracy by the
   % computation of the exponential function.Returns
   % ['true] or ['false]. Returns the truth value of
   % $f(id)$ at point [sp].
   begin scalar r;
      r := cl_simpl(cl_apply2ats1(f,
                    function ofsf_pepsubsignat,{sp,id,k}),nil,-1);
      if ofsf_dpepverbosep() or ofsf_dpepiverbosep()
      then
         if r eq 'true
         then
            maprint(") tt]",0)
         else
            maprint(") ff]",0);
      return r
   end;


procedure ofsf_pepsubsignat(at,sp,id,k);
   % Substitute sign in atomic formula. [at] is an OFSF atomic
   % formula; [sp] is a sample point. Returns an OFSF atomic formula.
   % [k] is an integer, which denotes the accuracy by the computation
   % of the exponential function.
   % Returns [at] with the left-hand side $f$ replaced by the sign of
   % $f([sp])$.
   ofsf_0mk2(ofsf_op at,ofsf_pepevalsignf(ofsf_arg2l at,sp,id,k));


procedure ofsf_pepevalsignf(f,sp,id,k);
   % Evaluate sign of standard form at sample point.
   % f is a SF, a polynomial in [id], [sp] is a Samplepoint.
   % [k] is an integer, which denotes the accuracy by the
   % computation of the exponential function. Returns
   % [-1,0,1], the sign of f(sp).
   begin scalar sgnf,sqfdecf,decf,prodf;
      sgnf := rat_1 ();
      prodf := numr simp 1;

      % sp is exceptional point and f(sp)=0.
      if iv_containszero(anu_iv sp) and
         null numr simp rat_sgn
         ofsf_pepsubsq(numr simp prepsq aex_ex anu_dp sp,id,rat_0 (),k)
         and
         null numr simp rat_sgn ofsf_pepsubsq(f,id,rat_0 (),k)
      then <<
         if ofsf_dpepverbosep() or ofsf_dpepiverbosep()
         then
            maprint("0 ",0);
         return numr simp 0
      >>;

      % sp is 1-cell, i.e. a rational point.
      if null numr simp prepsq aex_ex anu_dp sp
      then <<
         sgnf := numr simp rat_sgn ofsf_pepsubsq(f,id,iv_rb anu_iv sp,k);
         if ofsf_dpepverbosep() or ofsf_dpepiverbosep()
         then <<
            maprint(sgnf,0);
            maprint(" ",0)
         >>;
         return sgnf
      >>;

      % square-free decomposition of f := (p_1.1)(p_2.2)...(p_n.n)
      sqfdecf := sfto_sqfdecf(f);
      % decf is a list of all factors of sqfdecf i.e. p_1,p_2,...,p_n
      decf := for each i in sqfdecf collect car i;
      for each i in decf do
         prodf := multf(prodf,i);

      if member(numr simp prepsq aex_ex anu_dp sp,decf) or
         member(multf(negf numr simp 1,
                      numr simp prepsq aex_ex anu_dp sp),decf)
      then <<
         if ofsf_dpepverbosep() or ofsf_dpepiverbosep()
         then
            maprint("0 ",0);
         return numr simp 0
      >> else <<
         decf := for each p in decf collect ofsf_pepevalsgnp(p,sp,id,k);
         for each i in sqfdecf do <<
            sgnf := multsq(sgnf,exptsq(!*f2q car decf,cdr i));
            decf := cdr decf
         >>;
         if minusf quotfx(f,prodf)
         then <<
            sgnf := numr simp prepsq multsq(sgnf,negsq rat_1());
            if ofsf_dpepverbosep() or ofsf_dpepiverbosep()
            then <<
               maprint(sgnf,0);
               maprint(" ",0)
            >>;
            return sgnf
         >> else <<
            sgnf := numr simp prepsq sgnf;
            if ofsf_dpepverbosep() or ofsf_dpepiverbosep()
            then <<
               maprint(sgnf,0);
               maprint(" ",0)
            >>;
            return sgnf
         >>
      >>
   end;

procedure ofsf_pepevalsgnp(f,sp,id,k);
   % Evaluate sign of (exponential) polynomial at sample point.
   % f is a SF, a (exponential) polynomial in [id], [sp] is a
   % Samplepoint. [k] is an integer, which denotes the accuracy
   % by the computation of the exponential function. Returns
   % [-1,0,1], the sign of f(sp).
   begin
      % f is a polynomial in x without exp(x), and sp is algebraic.
      if not member({'expt,'e,id},kernels f) and
         not member({'expt,'e,id},
                    kernels numr simp prepsq aex_ex anu_dp sp)
      then
         return ofsf_evalsignf(f,{sp},{id}); % use cad-evaluation!

      % sp is transcendental.
      if member({'expt,'e,id},kernels numr simp prepsq aex_ex anu_dp sp)
      then
         return ofsf_pepevalsigntrans(f,sp,id,k)
      else % sp is algebraic.
         return ofsf_pepevalsignalg(f,sp,id,k)
   end;

procedure ofsf_pepevalsigntrans(f,sp,id,k);
   begin scalar iv,sqff,ivrefined;
      iv := anu_iv sp;
      if null f
      then
         return numr simp 0;

      % case: f and polynomial of sp are identically.
      if cdr qremf(f,numr simp prepsq aex_ex anu_dp sp) eq nil
      then
         return numr simp 0;

      % case: f and polynomial of sp are relatively prime.
      sqff := ofsf_sqfparty(ofsf_pepsubf(f,{'expt,'e,id},!*ofsf_expf),
                            !*ofsf_expf);
      sqff := ofsf_pepsubf(sqff,!*ofsf_expf,{'expt,'e,id});
      ivrefined := ofsf_peprefine(sqff,
                   numr simp prepsq aex_ex anu_dp sp,id,iv,k);
      return numr simp rat_sgn ofsf_pepsubsq(f,id,iv_rb ivrefined,k)
   end;

procedure ofsf_pepevalsignalg(f,sp,id,k);
   begin scalar iv,sqff,ivrefined,ef;
      iv := anu_iv sp;
      if null f
      then
         return numr simp 0;

      % case:f(sp)=0
      ef := ofsf_pepsubf(f,{'expt,'e,id},!*ofsf_expf);
      setkorder {!*ofsf_expf,id};
      ef := reorder ef;
      if ofsf_pepevalsign0alg(ef,sp,id)
      then
         return numr simp 0;

      % case: f and polynomial of sp are relatively prime.
      sqff := ofsf_sqfparty(ofsf_pepsubf(f,{'expt,'e,id},!*ofsf_expf),
                            !*ofsf_expf);
      sqff := ofsf_pepsubf(sqff,!*ofsf_expf,{'expt,'e,id});
      ivrefined := ofsf_peprefine(sqff,
                                  numr simp prepsq aex_ex anu_dp sp,
                                  id,iv,k);
      return numr simp rat_sgn ofsf_pepsubsq(f,id,iv_rb ivrefined,k)
   end;

procedure ofsf_pepevalsign0alg(f,sp,id);
   % Zero sign of an exponential polynomial at algebraic point.
   % [f] is SF, a polynomial in [id] and [y], represented in y,
   % and where y denotes the exponential function. [sp] is an ANU,
   % the sample point. Returns 'true if f(sp,exp(sp))=0,
   % and otherwise 'false.
   if domainp f or mvar f eq id
   then
      if domainp f
      then
         null f
      else
         null(cdr qremf(f,numr simp prepsq aex_ex anu_dp sp))
   else
      null(cdr qremf(lc f,numr simp prepsq aex_ex anu_dp sp))
      and ofsf_pepsgn0rat(red f,sp,id);

procedure ofsf_pepsplist(anul);
   % Sample point list. [anul] is a list of ANUs, where the
   % intervals are an isolation list for the product q^ of all the
   % polynomials in the ANUs.
   % Returns a list of sample points for all the cells of the
   % decomposition of the real line determined by the zeros of q^.
   begin scalar spl;
      spl := {{'anu,aex_fromsf nil,
               iv_mk(subtrsq(iv_lb anu_iv car anul,rat_1 ()),
               iv_lb anu_iv car anul)}};
      while anul do <<
         % sample point for 0-cell.
         spl := cons(car anul,spl);
         % sample point for 1-cell i.e. between two successive 0-cells.
         if cdr anul
         then
            spl := cons({'anu,aex_fromsf nil,
                   iv_mk(iv_rb anu_iv car anul,iv_lb anu_iv cadr anul)},
                   spl)
         else % last sample point.
            spl := cons({'anu,aex_fromsf nil,
                   iv_mk(iv_rb anu_iv car anul,
                         addsq(iv_rb anu_iv car anul,rat_1 ()))},spl);
         anul := cdr anul
      >>;
      return reverse spl
   end;

procedure ofsf_pepsubsq(f,id,r,k);
   % PEP substitution SQ. [f] is a SF,a polynomial in [id].
   % [id] an identifier (the kernel to be replaced) and [r] is a SQ
   % (the replacement). [k] is an integer, which denotes
   % the accuracy by the computation of the exponential
   % function.Returns a SQ.
   begin scalar ub,lb,ef,ubexpf,lbexpf;
      ef := ofsf_pepsubf(f,{'expt,'e,id},!*ofsf_expf);
      setkorder {!*ofsf_expf,id};
      ef := reorder ef;

      if ofsf_pepsgn0rat(ef,id,r)
      then
         return rat_0 ()
      else <<
         % Bounds for the exponential function.
         ubexpf := ofsf_pepuboundexpf(r,k);
         lbexpf := ofsf_peplboundexpf(r,k);
         % Bounds for the (exponential) polynomial f.
         ub := ofsf_pepuboundepoly(ef,id,r,ubexpf,lbexpf);
         lb := ofsf_peplboundepoly(ef,id,r,ubexpf,lbexpf);
         if rat_sgn ub neq rat_sgn lb
         then <<
            rederr{"Approximation error too high. Accuracy has to be higher than"
                   ,k}>>;
      return ub >>
   end;

procedure ofsf_pepsgn0rat(f,x,v);
   % Zero sign of an exponential polynomial at rational point.
   % [f] is SF, a polynomial in [x] and [y], represented in y,
   % and where y denotes the exponential function. [v] is SQ,
   % rational numbers. Returns 'true if f(v,exp(v))=0,
   % and otherwise 'false.
   if domainp f or mvar f eq x
   then
      if domainp f
      then
         null f
      else
	 null numr ofsf_subf(f,x,v)
   else
      null numr ofsf_subf(lc f,x,v) and
      ofsf_pepsgn0rat(red f,x,v);

procedure ofsf_pepuboundepoly(f,id,r,lbexpf,ubexpf);
   % PEP upper bound exponential polynomial.
   % [f] is SF, a polynomial in [id] and [y], represented in y,
   % and where y denotes the exponential function.[id] an identifier
   % (the kernel to be replaced) and [r] is a SQ (the replacement).
   % [lbexpf]/[ubexpf] the lower/upper bound for exp. Returns SQ, which
   % is the upper bound for f.
   if domainp f or mvar f eq id
   then
      if domainp f
      then
         !*f2q f
      else
	 ofsf_subf(f,id,r)
   else
      begin scalar tmp;
         tmp := ofsf_subf(lc f,id,r);
         if minusf numr simp rat_sgn tmp
         then
            return addsq(multsq(tmp,exptsq(lbexpf,ldeg f)),
                         ofsf_pepuboundepoly(red f,id,r,lbexpf,ubexpf))
         else
            return addsq(multsq(tmp,exptsq(ubexpf,ldeg f)),
                         ofsf_pepuboundepoly(red f,id,r,lbexpf,ubexpf))
      end;

procedure ofsf_peplboundepoly(f,id,r,lbexpf,ubexpf);
   % PEP lower bound exponential polynomial.
   % [f] is SF, a polynomial in [id] and [y], represented in y,
   % and where y denotes the exponential function.[id] an identifier
   % (the kernel to be replaced) and [r] is a SQ (the replacement).
   % [lbexpf]/[ubexpf] the lower/upper bound for exp. Returns SQ, which
   % is the lower bound for f.
   if domainp f or mvar f eq id
   then
      if domainp f
      then
         !*f2q f
      else
	 ofsf_subf(f,id,r)
   else
      begin scalar tmp;
         tmp := ofsf_subf(lc f,id,r);
         if minusf numr simp rat_sgn tmp
         then
            return addsq(multsq(tmp,exptsq(ubexpf,ldeg f)),
                         ofsf_pepuboundepoly(red f,id,r,lbexpf,ubexpf))
         else
            return addsq(multsq(tmp,exptsq(lbexpf,ldeg f)),
                         ofsf_pepuboundepoly(red f,id,r,lbexpf,ubexpf))
      end;


procedure ofsf_pepsubf(f,id,r);
   % PEP substitution. [f] is a SF, [id] an identifier
   % (the kernel to be replaced) and [r] is a variable
   % (the replacement). Returns a SF.
   numr simp prepsq subf(f, {id . r});


procedure ofsf_pepisolate(f,x,y,k);
   % Real root isolation. [f] is SF, a nonzero squarefree
   % polynomial in [x] and [y], represented in y, and where
   % y denotes the exponential function. [k] is an integer,
   % which denotes the accuracy by the computation of the
   % exponential function. Returns an isolation list for
   % f(x)=f(x,y), where y=exp(x).
   begin scalar psdeg,prediff,s,lprime,posb,negb,f0,f1,isol,
                lprefined,ef,es;
      psdeg := ofsf_psdegree(f,x,y);

      %Basis.
      if car psdeg eq 0 and cdr psdeg eq 0
      then <<
         if ofsf_dpepverbosep() or ofsf_dpepiverbosep()
         then <<
            maprint("L(",0);
            maprint(prepf ofsf_pepsubf(f,!*ofsf_expf,{'expt,'e,x}),0);
            maprint(") := ",0);
            maprint("{}",0);
            terpri!*(nil)
         >>;
         return nil
      >>;

      % Recursion.
      prediff := ofsf_diff(f,x,y);
      if cdr psdeg > 0
      then
         s := ofsf_sqfparty(prediff,y)
      else
         s := ofsf_sqfparty(quotf(prediff,numr simp y),y);

      lprime := ofsf_pepisolate(s,x,y,k);

      % Calculate a real root bound.
      if mvar f eq y
      then <<
         posb := !*f2q ofsf_peppositivebound(f,k);
         negb := !*f2q ofsf_pepnegativebound(f,k)
      >> else
         if domainp f
         then
            posb := negb := 0
         else <<
            posb := addsq(aex_cauchybound(aex_fromsf f,mvar f),simp 1);
            negb := negsq posb
         >>;
      if ofsf_dpepiverbosep()
      then <<
         maprint("++ ISOL(",0);
         maprint(prepf ofsf_pepsubf(f,!*ofsf_expf,{'expt,'e,x}),0);
         maprint(")",0);
         terpri!*(nil);
         maprint("+ Real root bounds: ",0);
         maprint(numr simp prepsq negb,0);
         maprint(", ",0);
         maprint(numr simp prepsq posb,0);
         terpri!*(nil)
      >>;

      % Interval refinement.

      % calculate f(0,1).
      f1 := ofsf_pepsubf(f,!*ofsf_expf,1);
      if domainp f1 then f0 := f1
      else f0 := ofsf_pepsubf(f1,mvar f1,0);

      % collect interval which have the exceptional point 0 and
      % for which f(0,1)=0, and refine all other intervals.
      ef := ofsf_pepsubf(f,!*ofsf_expf,{'expt,'e,x});
      es := ofsf_pepsubf(s,!*ofsf_expf,{'expt,'e,x});
      lprefined := for each iv in lprime join
                 if iv_containszero iv and null f0
                 then
                    {iv_mk(-1 ./ 1024, 1 ./ 1024)}
                 else
                    {ofsf_peprefine(ef,es,x,iv,k)};

      % Completion of the induction step.
      isol := reverse ofsf_pepcompletion(ef,x,lprefined,negb,posb,k);

      if ofsf_dpepverbosep() or ofsf_dpepiverbosep()
      then <<
         maprint("L(",0);
         maprint(prepf ofsf_pepsubf(f,!*ofsf_expf,{'expt,'e,x}),0);
         maprint(") := ",0);
         if null isol
         then <<
            maprint("{}",0);
            terpri!*(nil)
         >> else
            for each i in isol do
               iv_pepprint(i);
         terpri!*(nil)
      >>;
      return isol
   end;

procedure iv_pepprint(iv);
   << maprint("]",0);
      rat_pepprint iv_lb iv;
      maprint(",",0);
      rat_pepprint iv_rb iv;
      maprint("[",0)
   >>;

procedure rat_pepprint r;
   if numr r
   then <<
     maprint(numr r,0);
     maprint("/",0);
     maprint(denr r,0)
   >> else
     maprint("0",0);

procedure ofsf_pepcompletion(f,x,ivl,b,a,k);
   % Completion of induction step of algorithm isolate.
   % [f] is SF, an exponential polynomial in [x]. [ivl] is a
   % list of intervals and [b],[a] are integers. [k] is an
   % integer, which denotes the accuracy by the computation
   % of the exponential function.
   begin scalar f0,ivlist,r;
      % compute f(0).
      f0 := numr simp rat_sgn ofsf_pepsubsq(f,x,rat_0 (),k);

      if ivl = nil
      then <<
         if ofsf_pepsgnch(f,x,b,a,k) eq 'true
         then
            ivlist := cons(iv_mk(b,a),ivlist);
         return ivlist
      >>;

      if cdr ivl = nil
      then <<
         if ofsf_pepsgnch(f,x,b,iv_lb car ivl,k) eq 'true
         then
            ivlist := cons(iv_mk(b,iv_lb car ivl),ivlist);
         if iv_containszero car ivl and null f0
         then
            ivlist := cons(iv_mk(iv_lb car ivl,iv_rb car ivl),ivlist);
         if ofsf_pepsgnch(f,x,iv_rb car ivl,a,k) eq 'true
         then
            ivlist := cons(iv_mk(iv_rb car ivl,a),ivlist);
         return ivlist
      >>;

      if ofsf_pepsgnch(f,x,b,iv_lb car ivl,k) eq 'true
      then
         ivlist := cons(iv_mk(b,iv_lb car ivl),ivlist);
      if iv_containszero car ivl and null f0
      then
         ivlist := cons(iv_mk(iv_lb car ivl,iv_rb car ivl),ivlist);

      r := cons(ofsf_pepcompletion(f,x,cdr ivl,iv_rb car ivl,a,k),
                ivlist);
      r := for each i in r join
              if listp i then for each j in i join {j}
              else {i};
      return r
   end;

procedure ofsf_pepsgnch(f,x,v1,v2,k);
   % Sign change. [f] is SF, an exponential polynomial in [x].
   % [v1],[v2] are SQ, rational numbers. [k] is an integer,
   % which denotes the accuracy by the computation of the
   % exponential function.Returns true if f(v1) has another
   % sign than f(v2) (i.e. f(v1)*f(v2)<0 ).
   % Otherwise return false.
   if minusf multf(numr simp rat_sgn ofsf_pepsubsq(f,x,v1,k),
                   numr simp rat_sgn ofsf_pepsubsq(f,x,v2,k))
   then
      'true
   else
      'false;

procedure ofsf_peprefine(f,s,x,iv,k);
   % Interval refinement. [f],[s] are SF, nonzero squarefree
   % exponential polynomials in [x], and s has the same zeros
   % as f. [iv] is an isolating interval for alpha,
   % where alpha neq 0 and f'(alpha)=0. [k] is an integer,
   % which denotes the accuracy by the computation of the
   % exponential function.Returns an interval
   % such that it does not contain any root of f(x).
   begin scalar d,m,ivl,ivr,fivl,fivr,epsilon,diff,delta,
                sgnsm,sgnsivl,sgnss,maxcoeffl;
      if ofsf_dpepiverbosep() and null !*rlpepeval
      then <<
         maprint("+ Interval refinement of ",0);
         iv_pepprint iv;
         terpri!*(nil)
      >>;
      % calculate a list which contains max{|a_i|} of each coefficient
      % p_j(x)=\sum_i^n a_ix^i of the derivation d of the inserted
      % exponential polynomial f(x,exp(x))=\sum_j^m p_j(x)exp(jx).
      d := numr simp prepsq diffsq(!*f2q f,x);
      d := ofsf_pepsubf(d,{'expt,'e,x},!*ofsf_expf);
      setkorder {!*ofsf_expf,x};
      d := reorder d;
      maxcoeffl := ofsf_maxcoefflist(d,x);

      repeat <<
         if ofsf_dpepiverbosep() and null !*rlpepeval
         then
            iv_pepprint iv;

         % bisect the interval.
         m := iv_med(iv);

         % evaluate the sign of s(m),s(left border of iv),
         % and s(m)*s(left border of iv).
         sgnsm := numr simp rat_sgn ofsf_pepsubsq(s,x,m,k);
         sgnsivl := numr simp rat_sgn ofsf_pepsubsq(s,x,iv_lb iv,k);
         sgnss := multf(sgnsivl,sgnsm);

         % set the new borders of the interval.
         if null sgnsm
         then <<
            ivl := addsq(iv_lb iv,quotsq(subtrsq(iv_rb iv,iv_lb iv),
                                         simp 4));
            ivr := addsq(iv_lb iv,quotsq(multsq(simp 3,
                         subtrsq(iv_rb iv,iv_lb iv)),simp 4));
            iv := iv_mk(ivl,ivr)
         >> else
            if minusf sgnss then iv := iv_mk(iv_lb iv,m)
            else iv := iv_mk(m,iv_rb iv);

         % calculate epsilon = min{|f(ivl)|,|f(ivr)|}/2
         fivl := rat_abs ofsf_pepsubsq(f,x,iv_lb iv,k);
         fivr := rat_abs ofsf_pepsubsq(f,x,iv_rb iv,k);
         epsilon := quotsq(rat_min(fivl,fivr),simp 2);

         % calculate the difference of the right border of the
         % new interval and the left border of the new interval.
         % calculate delta = epsilon*moc.
         diff := subtrsq(iv_rb iv,iv_lb iv);
         % calculate delta = epsilon*moc, moc is the linear modulus
         % of continuity.
         delta := multsq(epsilon,ofsf_pepmoc(d,x,iv,maxcoeffl,k))
      >> until rat_leq(diff,delta) and rat_greater(epsilon,rat_0 ());

      if ofsf_dpepiverbosep() and null !*rlpepeval
      then <<
         terpri!*(nil);
         maprint("+ Refined interval: ",0);
         iv_pepprint iv;
         terpri!*(nil)
      >>;
      return iv_mk(iv_lb iv,iv_rb iv)
   end;

procedure ofsf_pepmoc(f,x,iv,cl,k);
   % Linear moc (modulus of continuity). [f] is SF, a
   % polynomial in [x] and [y], represented in y i.e.
   % f(x,y) := f_0(x)+f_1(x)y+...+f_m(x)y^m, and where y
   % denotes the exponential function. [iv] is an interval.
   % [k] is an integer, which denotes the accuracy by the
   % computation of the exponential function. Returns
   % integer which is a linear modulus of continuity
   % for the interval [iv] and for g(x), with g'(x)=f.
   begin scalar m,mbound,bound;
      mbound := ofsf_pepmocbound(f,x,iv,cl);
      if member(!*ofsf_expf,kernels f)
      then <<
         m := !*f2q ldeg f;
         bound := multsq(addsq(m,rat_1 ()),
                  ofsf_pepuboundexpf(multsq(m,iv_rb iv),k));
         bound := multsq(bound,mbound)
      >> else
         bound := mbound;
      return quotsq(rat_1 (),bound)
   end;

procedure ofsf_pepmocbound(f,x,iv,cl);
   % [f] is SF, an exponential polynomial i.e. polynomial
   % in [x] and [y], represented in y i.e.
   % f(x,y) := f_0(x)+f_1(x)y+...+f_m(x)y^m, and where y
   % denotes the exponential function. [iv] is an interval.
   % Returns SQ, which is max_x\in iv{|f(x)|}.
   if domainp f or mvar f eq x
   then
      if domainp f         % case: last coeff of f is a constant.
      then
         rat_abs !*f2q f
      else % case: last coeff of f is a polynomial.
         begin scalar a,c,sum;
            a := !*f2q car cl;
            c := rat_max(rat_abs iv_lb iv,rat_abs iv_rb iv);
            % mocbound = a*(1+c+c^2+...+c^ldeg f).
            sum := rat_1 ();
            for i := 1:ldeg f do
               sum := addsq(sum,exptsq(c,i));
            return multsq(a,sum)
         end
   else
      begin scalar a,c,degree,sum;
         if domainp lc f
         then
            degree := 0
         else
            degree := ldeg lc f;
         a := !*f2q car cl;
         cl := cdr cl;
         c := rat_max(rat_abs iv_lb iv,rat_abs iv_rb iv);
         % mocbound = a*(1+c+c^2+...+c^degree).
         sum := rat_1 ();
         for i := 1:degree do
            sum := addsq(sum,exptsq(c,i));
         return rat_max(multsq(a,sum),ofsf_pepmocbound(red f,x,iv,cl))
      end;

procedure ofsf_maxcoefflist(f,x);
   % Maximal coefficient list. [f] is SF, polynomial in [x], and [y],
   % and represented in y i.e. f(x,y) := f_0(x)+f_1(x)y+...+f_m(x)y^m,
   % and where y denotes the exponential function. Returns a list
   % which contains max{|a_j|} of each f_i(x)=\sum_j^na_jx^j
   % of f(x,y).
   if domainp f or mvar f eq x
   then
      if domainp f
      then
         {absf f}
      else
         {ofsf_maxcoeff(f)}
   else
      append({ofsf_maxcoeff(lc f)},ofsf_maxcoefflist(red f,x));

procedure ofsf_maxcoeff(f);
   % Maximal coefficient. [f] is SF, an univariate integral polynomial.
   % Returns an integer that is the maximum of the coefficients in
   % absolute value.
   if domainp f
   then
      if f eq nil
      then
         0
      else
         absf f
   else
      max(absf lc f,absf ofsf_maxcoeff(red f));


procedure ofsf_peppositivebound(f,k);
   % Positive real root bound for exponential polynomials.
   % [f] is SF, a polynomial in x and y, and represented in y,
   % i.e. f(x,y) := f_0(x)+f_1(x)y+...+f_m(x)y^m, and where
   % y denotes the exponential function. [k] is an integer,
   % which denotes the accuracy by the computation of the
   % exponential function. Returns an integer c such
   % that if alpha > 0 is any positive real root of
   % f(x) := f(x,y), where y = exp(x) then alpha < c.
   begin scalar c1,ac2,a,c2,c3;
      % compute cauchybound c1 for f_m+1 (f_m := leading coeff of f,
      % an univariate polynomial in x) such that
      % for all x>c1, |f_m(x)|>1.
      c1 := ofsf_pepbound1 lc f;
      % compute c2 and a>0 such that for all x>c2,
      % for all 0<=i<m, |f_i(x)|<=x^a/m.
      ac2 := ofsf_pepbound2(red f,!*ofsf_expf,ldeg f);
      a := addf(1,car ac2);
      c2 := cdr ac2;
      % compute c3 such that for x>c3, x^a<exp(x/2).
      c3 := ofsf_pepbound3(a,k);
      return max(c1,max(c2,c3))
   end;

procedure ofsf_pepnegativebound(f,k);
   % Negative real root bound for exponential polynomials.
   % [f] is SF, a polynomial in x and y, and represented in y,
   % i.e. f(x) := f_0(x)+f_1(x)y+...+f_m(x)y^m, and where
   % y denotes the exponential function. [k] is an integer,
   % which denotes the accuracy by the computation of the
   % exponential function. Returns an integer c such
   % that if alpha < 0 is any negative real root of
   % f := f(x,y), where y = exp(x) then alpha > c.
   begin scalar f0,c1,ac2,a,c2,c3;
      f0 := ofsf_peplowestcoeff(f,!*ofsf_expf);
      c1 := ofsf_pepbound1 f0;
      ac2 := ofsf_pepbound2(addf(addf(f,negf f0),1),!*ofsf_expf,ldeg f);
      a := addf(1,car ac2);
      c2 := cdr ac2;
      c3 := ofsf_pepbound3(a,k);
      return negf(max(c1,max(c2,c3)))
   end;

procedure ofsf_peplowestcoeff(f,y);
   % Lowest coefficient. [f] is SF, a polynomial in x and [y],
   % represented in y. Returns the lowest coefficient of f which
   % is an univariate polynomial in x.
   if domainp f or mvar f neq y
   then
      f
   else
      ofsf_peplowestcoeff(red f,y);


procedure ofsf_pepbound1(f);
   % Bound1 for cauchybound for exponential polynomials.
   % [f] is SF, an univariate polynomial. Returns the
   % cauchybound for f+1.
   begin scalar fp1,aefp1,cbp1,fm1,aefm1,cbm1;
      fp1 := addf(f,1);
      aefp1 := aex_fromsf fp1;
      if domainp fp1
      then
         cbp1 := 0
      else
         cbp1 := numr simp prepsq aex_cauchybound(aefp1,mvar fp1);
      fm1 := addf(f,negf 1);
      aefm1 := aex_fromsf fm1;
      if domainp fm1
      then
         cbm1 := 0
      else
         cbm1 := numr simp prepsq aex_cauchybound(aefm1,mvar fm1);
      return min(cbp1,cbm1)
   end;


procedure ofsf_pepbound2(f,y,mdeg);
   % Bound2 for cauchybound for exponential polynomials.
   % [f] is SF, a bivariate polynomial in [y].
   % [mdeg] is an integer. Returns a dotted pair.
   if domainp f or mvar f neq y
   then
      if domainp f
      then <<
         if f eq nil
         then
            f := 0;
         0 . multf(multf(2,mdeg),absf!* f)
      >> else
         ldeg f . multf(multf(2,mdeg),absf!* lc f)
   else
      begin scalar aepm,cb,b,m,pmdeg;
         aepm := aex_fromsf lc f;
         if domainp lc f
         then <<
            cb := 0;
            b := multf(multf(2,mdeg),absf!* lc f);
            pmdeg := 0
         >> else <<
            cb := numr simp prepsq aex_cauchybound(aepm,mvar lc f);
            b := multf(multf(2,mdeg),absf!* lc lc f);
            pmdeg := ldeg lc f
         >>;
         if cb < b
         then
            m:= b
         else
            m := cb;
         return max(pmdeg,car ofsf_pepbound2(red f,y,mdeg)).
                max(m,cdr ofsf_pepbound2(red f,y,mdeg))
      end;

procedure ofsf_pepbound3(a,k);
   % Bound3 for cauchybound for exponential polynomials.
   % [a] is an integer.[k] is an integer, which denotes
   % the accuracy by the computation of the exponential
   % function. Returns an integer b, such that
   % for all x>b, x^a < exp(x/2).
   begin integer b,ba,bexp;
      b := simp 2;
      repeat <<
         b := addsq(b,simp 1);
         ba := exptsq(b,a);
         bexp := ofsf_pepuboundexpf(quotsq(b,simp 2),k)
      >> until rat_max(ba,bexp) eq bexp;
      return numr simp prepsq b
   end;

procedure ofsf_diff(f,x,y);
   % Derivation. [f] is SF, a polynomial in [x] and [y]
   % and represented in [y].
   % f(x,y) = f_0(x)+f_1(x)y+f_2(x)y^2+...+f_m(x)y^m.
   % f'(x,y) = f_0'(x)+(f_1'(x)+f_1(x))y+(f_2'(x)+2f_2(x))y^2+...
   % ...+(f_m'(x)+mf_m(x))f_m(x)y^m.
   % Returns a SF which is the derivative of f := f'(x,y).
   if domainp f or mvar f eq x
   then
      if domainp f
      then
         nil
      else
         diff(f,mvar f)
   else
      begin scalar d,l,k,m;
         if domainp lc f
         then
            d := 0
         else
            d := numr simp prepsq diffsq(!*f2q lc f,mvar lc f);
         l := addf(d,multf(ldeg f,lc f));
	 if mvar f eq y
         then <<
	    k := !*k2f mvar f;
            m := multf(exptf(k, ldeg f), l)
         >> else
            m := l;
	 return addf(m,ofsf_diff(red f,x,y))
      end;

procedure ofsf_psdegree(f,x,y);
   % psdegree. [f] is SF, a polynomial in [x] and [y]
   % and represented in [y]. Returns dotted pair (m.n)
   % where m = deg_y f(x,y) ,and n = deg_x f(x,0).
   if domainp f
   then
      0 . 0
   else
      begin scalar m,n;
	 if mvar f eq y
         then
            m := ldeg f
	 else
            m := 0;
   	 n := ofsf_degx(f,x);
	 return m . n
      end;

procedure ofsf_degx(f,x);
   % Degree wrt. x. [f] is SF, a polynomial in [x] and y
   % and represented in y. Returns deg_x f(x,0).
   if domainp f
   then
      0
   else
      if mvar f eq x
      then
         ldeg f
      else
         ofsf_degx(red f,x);

procedure ofsf_contenty(f,y);
   % Content wrt y. [f] is SF, a bivariate polynomial
   % represented in [y]. Returns a SF which is the
   % content of [f] as an univariate polynomial.
   if domainp f or mvar f neq y
   then
      f
   else
      sfto_gcdf!*(lc f,ofsf_contenty(red f,y));

procedure ofsf_prparty(f,y);
   % Primitive part wrt y. [f] is SF, a bivariate
   % polynomial represented in [y]. Returns a SF which is
   % the primitive part of [f] as a bivariate polynomial.
   quotf(f,ofsf_contenty (f,y));

procedure ofsf_sqfparty(f,y);
   % Squarefree part. [f] is SF, a bivariate polynomial
   % represented in [y]. Returns a SF which is the squarefree
   % part of [f] as a bivariate polynomial.
   begin scalar c,pp,cdec1,cdec2,ppdec1,ppdec2;
      cdec2 := ppdec2 := 1;
      if domainp f
      then
         return 1;
      % compute square-free decomposition of the content
      c := ofsf_contenty(f,y);
      cdec1 := sfto_sqfdecf(c);
      cdec1 := for each c in cdec1 collect car c;
      while cdec1 do <<
         cdec2 := multf(cdec2,car cdec1);
         cdec1 := cdr cdec1 >>;

      % compute square-free decomposition of the primitive part
      pp := ofsf_prparty(f,y);
      ppdec1 := sfto_sqfdecf(pp);
      ppdec1 := for each p in ppdec1 collect car p;
      while ppdec1 do <<
         ppdec2 := multf(ppdec2,car ppdec1);
         ppdec1 := cdr ppdec1 >>;

      return multf(cdec2,ppdec2)
   end;

procedure ofsf_pepcheck(ophi);
   % Check formula. [ophi] is a formula. Returns true if
   % ophi is a prenex sentence Q_1x_1...Q_nx_n psi(x_1,...,x_n)
   % where psi is a quantifier-free formula of the extension of the
   % first-order theory of the real closed field, and Q_ix_i are
   % quantifiers. See thesis.
   begin scalar idexp,psi,kerns;
      if null car cl_splt(ophi)
      then
         rederr "Input is not a prenex sentence";
      idexp := rl_var ophi;
      psi := rl_mat ophi;
      for each term in cl_terml psi do <<
         % Verify if exp occurs in the correct variable.
         kerns := kernels term;
         for each k in kerns do
            if member('expt,k) and member('e,k)
            then
               if idexp neq caddr k then
                  rederr {"Exponential function has to occur in",idexp}
      >>;
      % Verify if input is a prenex sentence.
      if null (length cl_fvarl1 ophi eq 1 and
         smember({'expt,'e,idexp},cl_fvarl1 ophi))
      then
         if null ofsf_expfree(ophi)
         then
            rederr "Input is not a prenex sentence";
      return nil
   end;

procedure ofsf_expfree(f);
   % Exponential free. [f] is a formula. Returns true if
   % the terms of f does not involve the exponential function,
   % and nil otherwise.
   begin scalar esf,expfree;
      expfree := 'true;
      esf := {'expt,'e,rl_var f};
      for each term in cl_terml f do
          if member(esf,kernels term)
          then
             expfree := nil;
      return expfree
   end;

%% Exponential Function Approximation.

procedure ofsf_pepuboundexpf(x,k);
   % Upper bound exponential function. [x] is SQ, [k] is SF.
   % Returns SQ, the upper bound for exp(x) i.e.
   % x>0 : exp(x)<=\sum_i=0^k x^i/i! + 3^(ceiling x)/(k+1)! * x^(k+1).
   % x<0 : 1/(\sum_i=0^k x^i/i!).
   if rat_less(x,rat_0 ())
   then
      quotsq(rat_1 (),ofsf_pepexpf(rat_abs x,k))
   else
      addsq(ofsf_pepexpf(x,k),
            multsq(quotsq(exptsq(simp 3,ofsf_pepceiling rat_abs x),
                          simp ofsf_factsf addf(k,1)),exptsq(x,addf(k,1))));



procedure ofsf_peplboundexpf(x,k);
   % Lower bound exponential function. [x] is SQ, [k] is an
   % integer, which denotes the accuracy by the computation
   % of the exponential function. Returns SQ, the lower bound
   % for exp(x) i.e.
   % x>0 :\sum_i=0^k x^i/i.
   % x<0 :1/(\sum_i=0^k x^i/i! + 3^(ceiling x)/(k+1)! * x^(k+1)).
   if rat_less(x,rat_0 ())
   then
      quotsq(rat_1 (),addsq(ofsf_pepexpf(rat_abs x,k),
             multsq(quotsq(exptsq(simp 3,ofsf_pepceiling rat_abs x),
                           simp ofsf_factsf addf(k,1)),exptsq(x,addf(k,1)))))
   else
      ofsf_pepexpf(x,k);


procedure ofsf_pepexpf(x,k);
   % PEP Exponential function approximation. [x] is SQ.
   % [k] is an integer which denotes with how many summands
   % the Taylor polynomial is computed.
   % Returns a SQ which is exp(x) approximated.
   % Approximate exp(x) by its Taylorpolynomial by
   % using repeated squaring.
   expApproxRed(x,k);

procedure expApproxRed(x,k);
   % [x] is SQ
   begin scalar sr;
      if rat_leq(x,lnApprox(simp 1))
      then
         return expApprox(x,k)
      else <<
         sr := findsr x;
         return multsq(exptsq(simp 2,car sr),expApproxRed(cdr sr,k))
      >>
   end;

procedure findsr(x);
   findsr_helper(x,0);

procedure findsr_helper(x,s);
   % [x] is SQ, [s] is SF. Return SF.SQ.
   if rat_leq(x,lnApprox(simp 1))
   then
      s . x
   else
      findsr_helper(subtrsq(x,lnApprox(simp 1)),addf(s,1));

procedure lnApprox(x);
   % Ln Approximation. [x] is SQ, -1<x<=1. REturns SQ which
   % is ln(x+1) approximated by its power serie.
   begin scalar n,g,sum;
      n := 20;
      g := 0; % bei 0 minus
      sum := x;
      for i := 2:n do
         if g eq 0
         then <<
            sum := subtrsq(sum,quotsq(exptsq(x,i),simp i));g:=1
         >> else <<
            sum := addsq(sum,quotsq(exptsq(x,i),simp i));g:=0
         >>;
      return sum
   end;

procedure expApprox(x,k);
   % Exponential function approximation. [x] is SQ.
   % Returns a SQ which is exp(x) approximated.
   % Approximate exp(x) by its Taylorpolynomial of n-degree.
   begin scalar sum,xi,fi;
      if rat_nullp x then return simp 1;
      sum := simp 1;
      for i := 1:k do <<
         xi := exptsq(rat_abs x,i);
         fi := ofsf_factsf(i);
         sum := addsq(sum,quotsq(xi,simp fi))
      >>;
      if rat_less(x,rat_0 ())
      then
         sum := quotsq(rat_1 (),sum);
      return sum
   end;

procedure ofsf_factsf(x);
   % Factorial Standard Form. [x] is SF.
   % Returns SF which is the factorial of x.
   if x <= 1
   then
      1
   else
      multf(x,ofsf_factsf(addf(x,negf 1)));

procedure ofsf_pepceiling(x);
   % Ceiling. [x] is SQ. Returns a SF, which is the ceiling of x.
   begin
      !*rounded := t;
      setdmode('rounded,t);
      x := numr simp prepsq x;
      if pairp x
      then
         x := ceiling cdr x
      else
         if null x
         then
            x := 0
         else
            x := ceiling x;
      setdmode('rounded,nil);
      !*rounded := nil;
      return x
   end;

%% ANU

procedure anu_refinelist(anul,x,k);
   % Refine list. [anul] is a list of ANUs where
   % the intervals of the ANUs are an isolating interval
   % corresponding to the polynomial in its ANU. [k] is an integer,
   % which denotes the accuracy by the computation of the
   % exponential function. Refines the intervals of ivl such that
   % they have no intersection i.e. the intervals are an isolation
   % list for the product of the polynomials.
   begin scalar canu,a,l;
      canu := car anul;
      l := {canu};
      anul := cdr anul;
      while anul do <<
         if iv_comp(anu_iv canu,anu_iv car anul) eq 0
         then <<
            % if exceptional point then do not refine.
            if not (iv_containszero(anu_iv canu) and
               iv_containszero(anu_iv car anul) and
               null numr simp rat_sgn
               ofsf_pepsubsq(numr simp prepsq aex_ex anu_dp canu,
                             x,rat_0 (),k) and
               null numr simp rat_sgn
               ofsf_pepsubsq(numr simp prepsq aex_ex anu_dp car anul,
                             x,rat_0 (),k))
            then <<
               a := dpep_anu_refine(canu,car anul,x,k);
               l := anu_delete(canu,l);
               % Insert the smaller interval at first.
               if iv_comp(anu_iv car a,anu_iv cdr a) eq -1
               then <<
                  l := cons(car a,l);
                  l := cons(cdr a,l)
               >> else <<
                  l := cons(cdr a,l);
                  l := cons(car a,l)
               >>
            >>
         >> else
            l := cons(car anul,l);
         canu := car l;
         anul := cdr anul
      >>;
      return reverse l
   end;

procedure dpep_anu_refine(anu1,anu2,x,k);
   % Refine. [anu1],[anu2] are two ANUs where their interval
   % are isolation intervals for their polynomial and these
   % intervals intersect. [k] is an integer, which denotes
   % the accuracy by the computation of the exponential function.
   % Refines the intervals of the ANUs such that they have no
   % intersection and remain as isolation
   % intervals. Returns a dotted pair with two intervals.
   begin scalar iv1,iv2,m1,m2,p1,p2,sgnp1m,sgnp2m,sgnp1ivl,
                sgnp2ivl,sgnpp1,sgnpp2,ivl,ivr;
      iv1 := anu_iv anu1;
      iv2 := anu_iv anu2;
      p1 := numr simp prepsq aex_ex anu_dp anu1;
      p2 := numr simp prepsq aex_ex anu_dp anu2;
      repeat <<
         % bisect the intervals.
         m1 := iv_med(iv1);
         m2 := iv_med(iv2);

         % evaluate the signs of p1(m1),p1(left border of iv1),
         % and p1(m1)*p1(left border of iv1).
         sgnp1m := numr simp rat_sgn ofsf_pepsubsq(p1,x,m1,k);
         sgnp1ivl := numr simp rat_sgn ofsf_pepsubsq(p1,x,iv_lb iv1,k);
         sgnpp1 := multf(sgnp1ivl,sgnp1m);

         % evaluate the signs of p2(m2),p2(left border of iv2),
         % and p2(m2)*p2(left border of iv2).
         sgnp2m := numr simp rat_sgn ofsf_pepsubsq(p2,x,m2,k);
         sgnp2ivl := numr simp rat_sgn ofsf_pepsubsq(p2,x,iv_lb iv2,k);
         sgnpp2 := multf(sgnp2ivl,sgnp2m);

         % set the new borders of the first interval.
         if null sgnp1m
         then <<
            ivl := addsq(iv_lb iv1,
                         quotsq(subtrsq(iv_rb iv1,iv_lb iv1),simp 4));
            ivr := addsq(iv_lb iv1,
                         quotsq(multsq(simp 3,subtrsq(iv_rb iv1,
                                iv_lb iv1)),simp 4));
            iv1 := iv_mk(ivl,ivr)
         >> else
            if minusf sgnpp1
            then
               iv1 := iv_mk(iv_lb iv1,m1)
            else
               iv1 := iv_mk(m1,iv_rb iv1);

         % set the new borders of the second interval.
         if null sgnp2m
         then <<
            ivl := addsq(iv_lb iv2,
                         quotsq(subtrsq(iv_rb iv2,iv_lb iv2),simp 4));
            ivr := addsq(iv_lb iv2,
                         quotsq(multsq(simp 3,subtrsq(iv_rb iv2,
                                iv_lb iv2)),simp 4));
            iv2 := iv_mk(ivl,ivr)
         >> else
            if minusf sgnpp2
            then
               iv2 := iv_mk(iv_lb iv2,m2)
            else
               iv2 := iv_mk(m2,iv_rb iv2)
      >> until iv_comp(iv1,iv2) neq 0;
      anu1 := {'anu,aex_ex anu1,iv1};
      anu2 := {'anu,aex_ex anu2,iv2};
      return anu1 . anu2
   end;


procedure anu_sortlist(anul);
   % ANU sortlist. [anul] is a list of ANUs.
   % Returns the a list of ANUs which is anul
   % sorted by the intervals of its ANUs.
   begin scalar anumin,sort;
      while anul do <<
         anumin := anu_min(anul);
         sort := cons(anumin,sort);
         anul := anu_delete(anumin,anul)
      >>;
      sort := reverse(sort);
      return sort
   end;

procedure anu_delete(anu,anul);
   % ANU delete. [anu] is an ANU (the one to delete),
   % [anul] is a list of ANUs. Returns a list of ANUs
   % which is anul without anu.
   <<
      anul := for each i in anul join
                if i neq anu
                then {i};
      anul
   >>;

procedure anu_min(anul);
  % ANU minimum. [anul] is a list of ANUs. Returns
  % an ANU which has the interval with the smallest
  % interval borders.
  begin scalar anumin;
      anumin := car anul;
      anul := cdr anul;
      while anul do <<
         if iv_comp(anu_iv car anul,anu_iv anumin) eq -1
         then
            anumin := car anul;
         if iv_comp(anu_iv car anul,anu_iv anumin) eq 0
         then
            if rat_less(iv_lb anu_iv car anul,iv_lb anu_iv anumin)
            then
               anumin := car anul;
         anul := cdr anul;
      >>;
      return anumin
   end;

endmodule; %[dpep]

end;  % of file
