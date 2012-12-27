% ----------------------------------------------------------------------
% $Id$
% ----------------------------------------------------------------------
% (c) 1998 A. Dolzmann, A. Seidl, T. Sturm, 2012 T. Sturm
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
%
% ----------------------------------------------------------------------
% Id: pgauss.red,v 1.9 1998/05/07 12:59:28 seidla Exp
% ----------------------------------------------------------------------
% Copyright (c) 1998
% Andreas Dolzmann, Andreas Seidl, and Thomas Sturm
% ----------------------------------------------------------------------
% Log: pgauss.red,v
% Revision 1.9  1998/05/07 12:59:28  seidla
% A new switch pgnopropzero (no propagation of zero) is available. if it is
% switched on, the information about green entries in the system matrix is
% kept only in the condition list. note that pgspsimpl or pgspqe must be
% switched on for the sake of total correctness of the program.--
% If pginfosol is switched on, the printing of the solutions is enhanced: an
% equivalent formula for \and(cl) is given by rl_simpl and an equivalent
% formula for \ex(\and(cl)) (i.e. the satisfiability of cl) is given by rl_qe,
% where cl is the condition list. If pginfosol is switched on note that the
% value returned to algebraic mode is nil.
%
% Revision 1.8  1998/05/06 09:14:50  seidla
% sm_rightsidesmaybenullp renamed to sm_rightsidesarenotredp. A switch
% pgverbose was introduced. A bug was fixed in pg_nullcase but is was not a
% bug. The new procedure cond_inconsistentp was introduced to be used by
% sm_rightsidesarenotredp. Due to this new procedure, right sides may be
% simultaneously checked. The standard example leading to this improvement
% is pg_gauss({(a^2-1)*x=0,0=a+1,0=a-1},{x});
%
% Revision 1.7  1998/04/29 14:39:13  seidla
% Verbose output comming from redlog is suppressed. If both pgspsimpl and
% pgspqe are enabled then simpl is tried first and in case of failure, eq is
% applied. A bug in sm_surep was fixed.
%
% Revision 1.6  1998/04/29 12:30:30  seidla
% Procedure sm_whitecoefficientp renamed to sm_nongreencoefficientp.
% Procedure sm_greenp introduced. sm_whitep (better: nongereenp) is no longer
% used.
% Procedures pg_nullcase and pg_ccase use sm_greenp.
% The new switches pgspsimpl and pgspqe are available and provide andvanced
% methods from the redlog package for sm_surep.
% pg_switchinfo(); is available in algebraic mode.
%
% Revision 1.5  1998/04/29 08:29:18  seidla
% Procedures sm_whitep, sm_redp and sm_surep added to be used in
% sm_rightsidesmaybenull, sm_redcoefficientp and sm_whitecoefficientp.
% Number of parameters of  sm_rightsidesmaybenull, sm_redcoefficientp and
% sm_whitecoefficientp has changed.
%
% Revision 1.4  1998/04/27 14:21:40  seidla
% Conditions in the algorithm were handled as lisp-prefix forms. Now ofsf are
% used.
% The procedure csm_copy(csm) will copy only the corresponding sm, but not the
% conditions for the sake of performance.
%
% Revision 1.3  1998/04/26 16:38:05  seidla
% Data structure "symbolic-mode solution set" is altered. now the values of
% the indeterminants are handled in an alist. this seems to yield a performance
% improvement of 10%. C.f. the test-file for some examples.
% A new switch "pgsourcedirect" is available. if it is enabled, the solutions
% comming from the algorithm are not rearranged. this means e.g., that the
% generic case is the last entry in the solution list.
% The new algebraic-mode function pg_c(n) gives the number of cases considered
% by the algorithm when given the generic nxn case as input.
%
% Revision 1.2  1998/04/?? ??:??:??  seidla
% Data structure of the main part of the algorithm is altered. now premises
% are given downwards and the full conditions are comming from below.
% Non-constructive operators are used as widely as possible.
% Now the solutions and within the solutions the conditions are in the same
% order as they occur during the execution of the algorithm.
%
% Revision 1.1  1998/04/21 11:25:05  seidla
% Initial check-in.
%
% ----------------------------------------------------------------------
%
lisp <<
   fluid '(pg_rcsid!* pg_copyright!*);
   pg_rcsid!* := "$Id$";
   pg_copyright!* := "(c) 1998 A. Dolzmann, A. Seidl, T. Sturm, 2012 T. Sturm"
>>;

% Abschlussaufgabe PMP 1996/97
%
% File: gauss.red
% Author: Andreas Seidl
% Date: 12.03.1997
% Last change: 25.03.1997

module gauss;

bothtimes load!-package 'redlog;
bothtimes rl_set '(ofsf);

exports
  pg_gauss,pg_print,pg_gauss!-sym,pg_print!-sym;

algebraic operator and;
algebraic operator not;
algebraic operator arbcomplex;
symbolic operator pg_gauss;
symbolic operator pg_print;
symbolic operator pg_c;
symbolic operator pg_switchinfo;

switch pggeneric,pginfosm,pginfosol,pgsourcedirect,pgspsimpl,
   pgspqe,pgverbose,pgaftermath,nopropzero;
fluid {'!*pggeneric,'!*pginfosm,'!*pginfosol,'!*pgsourcedirect,'!*pgspsimpl,
   '!*pgspqe,'!*pgverbose,'!*pgaftermath,!*nopropzero};


procedure pg_gauss(eqtl,varl);

% Gauss. eqtl is a list of equations. varl is a list of identifiers.
% Entry point for algebraic mode. Returns an algebraic-mode solution-set.
% An (algebraic-mode) solution-set is a list of two-element-lists {c,v} where
% c is a quantor-free formula and v is a list of equations, all in lisp-
% prefix-form.

begin scalar elvl;
  elvl := pg_a2s(eqtl,varl);
  return pg_s2a pg_gauss!-sym(car elvl, cdr elvl);
end;


procedure pg_a2s(eqtl,varl);

% Algebraic to symbolic. eqtl is a list of equations (coming from algebraic
% mode). varl is a list of identifiers.
% Returns el . vl, where el is a list of equations (for symbolic mode) and
% vl is a list of identifiers.

cdr eqtl . cdr varl;


procedure pg_s2a(solset);

% Symbolic to algebraic. solset is a list of symbolic-mode solutions. (Refer
% pg_gauss!-sym for the definition of symbolic-mode solutions.)
% Returns a list of algebraic-mode solutions.

begin scalar ncond,nvals;
  return 'list . for each s in solset collect
    <<
       ncond := for each c in car s collect
	  rl_prepfof c;
      nvals := for each v in cdr s collect
        eqt_makeeqt(car v,prepsq cdr v);
      {'list,if car s then
               if cdr s then
                 ('and . ncond)
               else ncond
             else 'true,'list . nvals}
    >>
end;


procedure pg_gauss!-sym(el,vl);

% Gauss. el is a list of equations. vl is a list of identifiers.
% Entry point for symbolic mode. Returns a symbolic-mode solution-set.
% A (symbolic-mode) solution-set is a list of dotted pairs conditions . values,
% where conditions is a list of (un-)equations a=b (a<>b), where a and b are
% standard forms and values is an alist containing for each indeterminant x a
% dotted pair x . sq, where sq is a standard quotient.

begin scalar sm,solutions;
  sm := sm_create(el,vl);
  if (!*pginfosm or !*pgverbose) then
    <<
      prin2t "";
      sm_print sm;
    >>;
  solutions := pg_kern csm_create(nil,sm_copy(sm,0,0));
  if not !*pgsourcedirect then solutions := pg_solreversip solutions;
  if !*pginfosol then
    pg_print!-sym solutions;
  return if not (!*pgaftermath or !*pginfosol) then solutions;
end;


procedure pg_solreversip(sl);

   % reverse in place. sl is a list of solutions. brings it in the right
   % order (generic case first).

   <<
      % reverse order of conditions. conditions have to be copied.
      for each s in sl do car s := reverse car s;
      % now reverse order of solutions.
      reversip sl
   >>;

procedure pg_print!-sym(solset);

% Print solutions. sols is a set of symbolic-mode solutions.
% Return-value is uninteresting.

begin scalar tmp; integer i,numoffalse;
  for each sol in solset do
    <<
      prin2t "";
      i := i+1; prin2 "SOLUTION "; prin2t i;
      prin2t "";
      prin2 "Conditions: ";
%      for each c in car sol do
%	  mathprint rl_prepfof c;
      cond_prin2l car sol;
      prin2"simpl: these conditions are equiv. to";
      cond_prin2 cond_simpl car sol;
      prin2"qe: the existentional closure of these conditions is equiv. to";
      cond_prin2 (tmp := cond_qe car sol);
      if tmp eq 'false then numoffalse := numoffalse+1;
      prin2t "";
      prin2 "Values:     ";
      for each val in cdr sol do
        mathprint eqt_makeeqt(car val, prepsq cdr val);
    >>;
  prin2"Number of unsatisfiabel conditions: "; prin2t numoffalse
end;


procedure pg_kern(csm);

% Kernel. (The kernel of the gaussian algorithm).
% csm is a conditioned system-matrix. Returns symbolic-mode solution-set.

begin scalar solutions,csols,lc,case,premises,sm,cond,workcond;
  sm := csm_getsm csm;
  premises := csm_getc csm;
  case := sm_getcase sm;
  if !*pgverbose then <<prin2 "--entering p&b. case: "; prin2t case;>>;
  if lc := sm_redcoefficient(premises,sm) then
    <<
       sm_swap(sm,car lc,cdr lc);
       if !*pgverbose then
          <<prin2t"--p&b, red, have a look at our new system matrix";
	     sm_print sm>>;
      return apply(case,{csm})
    >>
  else
    if not !*pggeneric then
      <<
        while lc := sm_nongreencoefficient(premises,sm) do
          <<
             sm_swap(sm,car lc,cdr lc);
	     if !*pgverbose then
               <<prin2t"--p&b, nongreen, have a look at our new system matrix";
		   sm_print sm>>;
	    % working premise is a00 <> 0
	    workcond := cond_0mkuneqt(numr sm_get(sm,0,0)) .
	       premises;
	    % test here if workcond is consistent
	    if !*pgverbose then prin2t"--p&b: now case is applied";
            csols := apply(case,{csm_create(workcond,sm_copy(sm,0,0))});
            solutions := nconc(csols,solutions);
            premises := cond_0mkeqt(numr sm_get(sm,0,0)) . premises;
            if not !*nopropzero then sm_put(sm,0,0,simp 0)
          >>;
        % Now sm is null under premises
	if !*pgverbose then
	   <<prin2t"--have a look at our poor system matrix";sm_print sm>>;
	% test here if premises is consistent
        csols := pg_nullcase csm_create(premises,sm);;
        solutions := nconc(csols,solutions);
        return solutions
      >>
    else  % switch pggeneric is on
      if lc := sm_nongreencoefficient(premises,sm) then
        <<
           sm_swap(sm,car lc,cdr lc);
	   if !*pgverbose then
              <<prin2t"--have a look at our new system matrix";sm_print sm>>;
	  workcond := cond_0mkuneqt(numr sm_get(sm,0,0)) . csm_getc csm;
	  csols := apply(case,{csm_create(workcond,sm)});
          return csols
        >>
      else
        return pg_nullcase csm
end;


procedure pg_lcase(csm);

   % Lcase. csm is a cond. system-matrix. The coefficient at position (0,0)
   % is not null  by premise. The coeficient-submatrix has only one line.
   % Returns the symbolic-mode solution-set of sm.

begin scalar x0value,ac,tmp,idvalues,sm; integer m,n;
  pg_verbose {"----entering lcase"};
  % here applies no condition testing.
  sm := csm_getsm(csm);
  m := sm_m sm;
  n := sm_n sm;
  tmp := simp 0;
  for c := 1 : n-1 do
    <<
      ac := makearbcomplex() . 1;
      tmp := addsq(tmp,multsq(sm_get(sm,0,c),ac));
      idvalues := (sm_get(sm,1,c) . ac) . idvalues
    >>;
  x0value := quotsq(addsq(negsq tmp,sm_get(sm,0,n)),sm_get(sm,0,0));
  idvalues := (sm_get(sm,1,0) . x0value) . idvalues;
  pg_verbose {"----leaving lcase"};
  return {(csm_getc csm) . idvalues}
end;


procedure pg_ccase(csm);

   % Ccase. csm is a cond. system-matrix. The coefficient at position (0,0)
   % is not null by premise. The coeficient-submatrix has only one column.
   % Returns the symbolic-mode solution-set of sm.

begin scalar newcond,retcond,value,tmp,sm; integer m,n;
   pg_verbose {"[entering ccase"};
   sm := csm_getsm csm;
   if !*pgverbose then sm_print sm;
   m := sm_m sm;
   n := sm_n sm;
   sm_firststep sm;
%   if !*pgverbose then <<prin2t"sm after sm_firststep:";sm_print sm>>;
   if sm_rightsidesarenotredp(csm_getc csm,sm,1) then
   <<
      % as there is no red coeff. in the right side, we may save conditions
      % if there is a green coeff. in the right side:
      newcond := for l := 1 : m-1 join
         if not sm_greenp(csm_getc csm,tmp := numr sm_get(sm,l,n)) then
            {cond_0mkeqt(tmp)};
      retcond := nconc(newcond,csm_getc csm);
      % test here if retcond is consistent
      value := sm_get(sm,m,0) . quotsq(sm_get(sm,0,n),sm_get(sm,0,0));
      pg_verbose {"leaving ccase successfull]"};
      return {retcond . {value}}
   >>
   else
   <<
      pg_verbose {"leaving ccase without success]"};
      return nil;
   >>
end;


procedure pg_rcase(csm);

% Rcase. sm is a system-matrix. The coefficient at position (0,0) is not null
% by premise. The coeficient-submatrix has at least two rows and columns.
% Returns the symbolic-mode solution-set of sm.

begin scalar subsolutions,solutions,tmp,x0value,sm; integer m,n;
  sm := csm_getsm csm;
  m := sm_m sm;
  n := sm_n sm;
  sm_firststep sm;
  if !*pgverbose then <<prin2t"----entered rcase. first coulumn done: ";
     sm_print sm>>;
  subsolutions := pg_kern csm_copy(csm,1,1);
  % here no new solutions will be introduced, but the vals. are expanded
  for each s in subsolutions do
  <<
     % tmp := a01*x1+...+a0*x(n-1)
     tmp := simp 0;
     for c := 1 : n-1 do
	tmp :=
	   addsq(tmp,multsq(sm_get(sm,0,c),cdr(atsoc(sm_get(sm,m,c),cdr s))));
     x0value := quotsq(addsq(negsq tmp,sm_get(sm,0,n)),sm_get(sm,0,0));
     solutions := (car s . (sm_get(sm,m,0) . x0value) . cdr s) . solutions;
  >>;
  pg_verbose {"----leaving rcase. solutions: ",length solutions};
  return reversip solutions
end;


procedure pg_nullcase(csm);

% Nullcase. sm is a cond. system-matrix with all coefficients null.
% Returns the symbolic-mode solution-set of sm.

begin scalar newcond,retcond,values,tmp,sm; integer m,n;
  pg_verbose {"----nullcase"};
  sm := csm_getsm csm;
  m := sm_m sm;
  n := sm_n sm;
  if sm_rightsidesarenotredp(csm_getc csm,sm,0) then
    <<
      newcond := for l := 0 : (m-1) join
        if not sm_greenp(csm_getc csm,tmp := numr sm_get(sm,l,n)) then
           {cond_0mkeqt(tmp)};
      retcond := nconc(newcond,csm_getc csm);
      % test here if retcond is consistent
      values := for c := 0 : (n-1) collect
	 (sm_get(sm,m,c) . makearbcomplex() . 1);
       return {retcond . values}
    >>
end;


procedure pg_print(sols);

% Print solutions. sols is a list of algebraic-mode solutions.
% Return-value is uninteresting

begin integer i;
  prin2t "";
  if sols then
  for each s in cdr sols do
    <<
      i := i+1;
      prin2 "SOLUTION "; prin2t i;
      prin2t ""; prin2t"CONDITION:";
      mathprint cadr s;
      prin2t ""; prin2t"VALUES:";
      for each v in cdaddr s do
        mathprint v
    >>;
  prin2t ""
end;


procedure pg_c2(n,z);
   % complexity. n is a nonzero natural number and  0<=z<=n.
   % returns a natural number.
   if n eq 1 then
      if z eq 0 then 2 else 1
   else
      (n * (for i := z : (n-1) sum pg_c2(n-1,i)) + 1);


procedure pg_c(n);
   % complexity. n is a nonzero natural number. returns the number of
   % cases considered by the algorithm when given the generic nxn case
   % as input.
   pg_c2(n,0);


procedure pg_switchinfo;
   % Switch info. Print the status of all switches.

   <<
      prin2t "SWITCHES";
      prin2 "pggeneric      ";
      if !*pggeneric then prin2t " on" else prin2t "off";
      prin2 "pginfosm       ";
      if !*pginfosm then prin2t " on" else prin2t "off";
      prin2 "pginfosol      ";
      if !*pginfosol then prin2t " on" else prin2t "off";
      prin2 "pgsourcedirect ";
      if !*pgsourcedirect then prin2t "on" else prin2t "off";
      prin2 "pgspsimpl      ";
      if !*pgspsimpl then prin2t " on" else prin2t "off";
      prin2 "pgspqe         ";
      if !*pgspqe then prin2t " on" else prin2t "off";
      prin2 "pgverbose      ";
      if !*pgverbose then prin2t " on" else prin2t "off";
      prin2 "pgaftermath    ";
      if !*pgaftermath then prin2t " on" else prin2t "off";
      prin2 "nopropzero     ";
      if !*nopropzero then prin2t " on" else prin2t "off";
      %prin2 ""; if !* then prin2t " on" else prin2t "off";
      prin2t "";
   >>;


procedure pg_verbose(l);
   % Verbose. l is a list of items to print.
   if !*pgverbose then
   <<
      for each i in l do prin2 i; prin2t ""
   >>;

%module sm;

exports
  sm_create,sm_rightsidesarenotredp,sm_m,sm_n,sm_get,sm_redcoefficient,
  sm_nongreencoefficient,sm_swap,sm_put,sm_copy,sm_firststep,sm_getcase,
  sm_print;

% System-matrix.
% An equation system with m equations and n indeterminants
%
%       a00*x0 + ... +     a0(n-1)*x(n-1) = b0
%          :                      :         :
%          :                      :         :
%   a(m-1)0*x0 + ... + a(m-1)(n-1)*x(n-1) = b(m-1)
%
% is represented by the system-matrix (m+1 lines, n+1 columns):
%
%    a00     ... a0(n-1)     b0
%    :           :           :
%    :           :           :
%    a(m-1)0 ... a(m-1)(n-1) b(m-1)
%    x0          x(n-1)      *
%
% Elements of C := {aij | 0<=i<=(m-1),0<=i<=(n-1)} are called coefficients,
% elements of R := {bi | 0<=i<=(m-1)} are called right sides, and the
% elements of I := {xj | 0<=j<=(n-1)} are called indeterminants.
%
% A coefficient is called red, if it is certainly nonnull (e.g. its
% nummerator is nonnull) it is called white, if he maybe nonnull (e.g. its
% nummerator is a nonnull polynomial with the parameters as indeterminants).


procedure sm_create(el,vl);

% Create system-matrix. el is a nonempty list of equations, vl is a nonempty
% list of identifieres. Returns the corresponding system-matrix.

begin scalar m,n,v,elp,vlp,sm;
  m := length el;
  n := length vl;
  sm := mkvect m;
  elp := el;
  for l := 0 : (m-1) do
    <<
      vlp := vl;
      putv(sm,l,sm_eq2vec(car elp,vlp,n));
      elp := cdr elp
    >>;
  v := mkvect n;
  vlp := vl;
  for c := 0 : (n-1) do
    <<
      putv(v,c,car vlp);
      vlp := cdr vlp
    >>;
  putv(sm,m,v);
  return sm;
end;


procedure sm_eq2vec(eqt,vl,n);

% Equation to vector. eqt is an equation, vl is a list of identifiers
% x0..x(n-1), n is a natural number, the length of vl.
% Returns a vector [a0..a(n-1) b] containing standard quotients, where
% ai is the coefficient of xi (i in 0..n-1) and b is the right side
% of eqt (converted to a SQ).

begin scalar oldorder,v,s,p,q;
  oldorder := setkorder vl;
  v := mkvect n;
  s := addsq(simp eqt_leftside eqt,negsq simp eqt_rightside eqt);
  p := numr s; q := denr s;
  for i := 0 : (n-1) do
    <<
      setkorder vl;
      p := reorder p;
      if not(domainp p) and not(ldeg p eq 1 or mvar p neq car vl) then
        rederr {"sm_eq2vec:",
          "No degrees higher than 1 are allowed for indeterminants."};
      if (not domainp p) and (mvar p eq car vl) then
        <<
          putv(v,i,quotsq(!*f2q lc p,!*f2q q));
          s := addsq(s,negsq(multsq(simp car vl,getv(v,i))));
        >>
      else
        putv(v,i,nil . 1);
      vl := cdr vl;
    >>;

  putv(v,n,negsq s);
  setkorder oldorder;
  return v;
end;


procedure sm_rightsidesarenotredp(cl,sm,sl);

% Right sides may be null. sm is a system-matrix.
% Returns nil if a right side exists that is red (certainly null).
% The test starts with line sl.

begin scalar arenotred,rscond,tmp,tmp2; integer l,m,n;
  arenotred := t;
  m := sm_m sm;
  n := sm_n sm;
  l := sl;
  pg_verbose {"[sm_rightsidesarenotredp entered..."};
  if !*pgverbose then sm_print sm;
  % tmp2 := {b_sl=0,...,b_m-1=0}
  for i := sl : m-1 do
     tmp2 := (cond_0mkeqt numr  sm_get(sm,i,n)) . tmp2;
  tmp2 := nconc(tmp2,cl);
  if !*pgverbose then <<prin2"tmp2: ";prin2t tmp2>>;
  rscond %rightsidescondition
     := rl_smkn('and, tmp2);
  if !*pgverbose then <<prin2"rscond: ";cond_prin2 rscond>>;
  if !*pgverbose then <<prin2"cl: ";cond_prin2l cl>>;
  %
  if !*pgspsimpl or !*pgspqe then
     arenotred := (if cond_inconsistentp(tmp2) then nil else t)
  else
     while (l <= m-1) and arenotred do
	%    if numberp(tmp := numr sm_get(sm,l,n)) and not null tmp then
	%      arenotred := nil
    	if sm_redp(cl,numr sm_get(sm,l,n)) then
      	   arenotred := nil
    	else
       	   l := l+1;
  pg_verbose {"...leaving sm_rightsidesarenotredp ",arenotred,"]"};
  return arenotred
end;


procedure sm_m(sm);

% m. sm is a system-matrix. Returns its m-value.

upbv sm;


procedure sm_n(sm);

% n. sm is a system-matrix. Returns its n-value.

upbv getv(sm,0);


procedure sm_get(sm,l,c);

% Get. sm is a system-matrix, l and c are natural numbers.
% Returns the entry of sm at line l and column n.

getv(getv(sm,l),c);


procedure sm_redcoefficient(cl,sm);

% Is there a red coefficient? sm is a system-matrix. Returns nil,
% if there is no red coefficient, l . c, if there is a red coefficient
% in line l at column c.

begin scalar rcfound,tmp; integer l,c,m,n;
  m := sm_m sm;
  n := sm_n sm;
%  if !*pgverbose then cond_prin2l cl;
  while l <= m-1 and not rcfound do
    <<
      c := 0;
      while c <= n-1 and not rcfound do
%        if numberp(tmp := numr sm_get(sm,l,c)) and not null tmp then
%          rcfound := t
        if sm_redp(cl,numr sm_get(sm,l,c)) then
          rcfound := t
        else
          c := c+1;
      if not rcfound then
        l := l+1
    >>;
  if rcfound then
    <<
       if !*pgverbose then
       <<
	  prin2 "--redcoefficient found: ";
	  mathprint prepsq sm_get(sm,l,c)
       >>;
       return (l . c)
    >>
  else
    return nil
end;


procedure sm_nongreencoefficient(cl,sm);

% Is there a nongreen coefficient? sm is a system-matrix. It is assumed, that
% there are no red coefficients in sm.
% Returns nil, if there is no white coefficient, l . c, if there is a white
% coefficient in line l at column c.

begin scalar wcfound; integer l,c,m,n;
  m := sm_m sm;
  n := sm_n sm;
  while l <= m-1 and not wcfound do
    <<
      c := 0;
      while c <= n-1 and not wcfound do
%        if not null numr sm_get(sm,l,c) then
%           wcfound := t
	 if not sm_greenp(cl,numr sm_get(sm,l,c)) then
	    wcfound := t
        else
          c := c+1;
      if not wcfound then
        l := l+1
    >>;
  if wcfound then
  <<
     if !*pgverbose then
     <<
	prin2 "--nongreencoefficient found: ";
	mathprint prepsq sm_get(sm,l,c)
     >>;
     return l . c
  >>
  else
    return nil
end;


procedure sm_redp(cl,sf);
   % Red predicate.
   % cl is a list of conditions in ofsf. sf is a standard form.
   % Returns t if sf is red wrt. cl.

   sm_surep(cl,cond_0mkuneqt sf);


procedure sm_greenp(cl,sf);
   % Green predicate.
   % cl is a list of conditions in ofsf. sf is a standard form.
   % Returns t if sf is green wrt. cl.

   sm_surep(cl,cond_0mkeqt sf);


procedure sm_surep(cl,c);
   % cl is a list of conditions in ofsf. c is a conditions in ofsf.
   % Returns t if the heuristics say cl |- c, nil otherwise;

   if !*pgspsimpl and !*pgspqe then %lazy
      ((if rl_simpl(c,cl,-1) eq 'true then t) or
	 (if (rl_qe(rl_all(rl_mk2('impl,rl_mkn('and,cl),c),nil),nil)
	    where !*rlverbose = nil) eq 'true	 then t))
   else if !*pgspsimpl then
      (if rl_simpl(c,cl,-1) eq 'true then t)
   else if !*pgspqe then
      (if (rl_qe(rl_all(rl_mk2('impl,rl_mkn('and,cl),c),nil),nil)
	 where !*rlverbose = nil) eq 'true
      then t)
   else if ofsf_op c eq 'equal then %nongreen:
      (if null ofsf_arg2l c then t)
   else %red: t if it is a number <> 0
      if ((domainp ofsf_arg2l c) and (not null ofsf_arg2l c)) then t;


procedure sm_swap(sm,l,c);

% Swap. sm is a system-matrix. l and c are natural numbers.
% Permutes line 0 with line l and coulumn 0 with column c.

begin scalar tmp;
  tmp := getv(sm,0);
  if not(l eq 0) then
    <<
      putv(sm,0,getv(sm,l));
      putv(sm,l,tmp)
    >>;
  if not(c eq 0) then
    for i := 0 : sm_m sm do
      <<
        tmp := sm_get(sm,i,0);
        sm_put(sm,i,0,sm_get(sm,i,c));
        sm_put(sm,i,c,tmp);
      >>
end;


procedure sm_put(sm,l,c,entry);

% Put. sm is a system-matrix, l and c are natural numbers. entry is anything.
% Puts entry at line l and column n in sm. Return-value is uninteresting,
% the argument is changed.

putv(getv(sm,l),c,entry);


procedure sm_copy(sm,sl,sc);

% Copy. sm is a system-matrix. sl and sc are natural numbers.
% Returns a copy of the submatrix (smij | sl<=i<=m,sc<=j<=n).

begin scalar newsm; integer m,n;
  m := sm_m sm;
  n := sm_n sm;
  newsm := mkvect(m-sl);
  for l := sl : m do
    <<
      putv(newsm,l-sl,mkvect(n-sc));
      for c := sc : n do
        sm_put(newsm,l-sl,c-sc,sm_get(sm,l,c))
    >>;
  return newsm
end;


procedure sm_firststep(sm);

% First step. sm is a system-matrix. Brings the first column in gauss-jordan-
% normal-form. Return-value is not interesting, the argument is changed.

for l := 1 : (sm_m sm)-1 do
  sm_addkl1tol2(sm,negsq quotsq(sm_get(sm,l,0),sm_get(sm,0,0)),0,l);


procedure sm_addkl1tol2(sm,k,l1,l2);

% Add k*l1 to l2. sm is a system-matrix. k is a standard quotient.
% l1 and l2 are natural numbers. Return-value is not interesting,
% the argument is changed.

for c := 0 : sm_n sm do
  sm_put(sm,l2,c,addsq(multsq(k,sm_get(sm,l1,c)),sm_get(sm,l2,c)));


procedure sm_getcase(sm);

% Get case. sm is a system-matrix. Returns an identifier.

if sm_m sm eq 1 then
  'pg_lcase
else if sm_n sm eq 1 then
  'pg_ccase
else
  'pg_rcase;


procedure sm_print(sm);

% Print. sm is a system-matrix. Returns nil.

begin integer n,m;
  m := upbv sm;
  n := upbv getv(sm,0);
  for l := 0 : (m-1) do
    <<
      terpri!* nil;
      for c := 0 : n do
        <<
          maprin prepsq sm_get(sm,l,c);
          maprin '!_!_
        >>;
      terpri!* t
    >>;
  for c := 0 : (n-1) do
    <<
      prin2 sm_get(sm,m,c);
      prin2 "   "
    >>;
  terpri();
  return nil
end;


%endmodule; % of sm

%module csm;

% Conditioned system matrix. A csm is a dotted pair c.sm where c is a set of
% conditions an sm is a system matrix.

procedure csm_create(c,sm);
   % Create. c is a list of conditions. sm is a system matrix.
   % Returns the corresponding conditioned system matrix.

   c.sm;

procedure csm_getc(csm);
   % Get conditions. csm is a conditioned system matrix.
   % returns the corresponding list of conditions.

   car csm;

procedure csm_getsm(csm);
   % Get system matrix. csm is a conditioned system matrix.
   % returns the corresponding system matrix.

   cdr csm;

procedure csm_copy(csm,sl,sc);

   % Copy csm. csm is a conditioned system-matrix. sl and sc are natural
   % numbers.
   % Returns a copy of csm consisting of the original conditions and a copy of
   % the submatrix (smij | sl<=i<=m,sc<=j<=n).

   csm_create(csm_getc(csm),sm_copy(csm_getsm(csm),sl,sc));

%endmodule; % of csm


%module eqt;

% Equation. Used to handle equations comming from algebraic mode.

exports
  eqt_eqtp,eqt_leftside,eqt_rightside,eqt_makeeqt,eqt_0mkuneqt;


procedure eqt_eqtp(eqt);

% Equation. eqt is a lisp-prefix form starting with "equal" or "not".
% Tests, if eqt is an equation.

if car eqt eq 'equal then
  t;


procedure eqt_leftside(eqt);

% Left side. eqt is an equation. Returns the left side.

cadr eqt;


procedure eqt_rightside(eqt);

% Right side. eqt is an equation. Returns the right side.

caddr eqt;


procedure eqt_makeeqt(ls,rs);

% Make equation. ls and rs are anything. Returns the equation ls = rs in
% lisp-prefix-form.

'equal . ls . {rs};


procedure eqt_mkuneqt(ls,rs);

% Make unequation. ls anrs are anything. Returns a lisp-prefix-form.

'not . {eqt_makeeqt(ls,rs)};


%endmodule; % of eqt


%module cond;

% Conditions. Conditions occur in a (symbolic-mode) solution set.
% conditions are equations or negated equations in fosf-form.

exports
  cond_eqtp,cond_leftside,cond_rightside,cond_0mkeqt,cond_0mkuneqt;


procedure cond_copy(cl);
   % Copy. cl is a list of conditions. returns a copy of cl.

   cl;

procedure cond_eqtp(eqt);

   % Equation. eqt is a ofsf.
   % Tests, if eqt is an equation.

   if ofsf_op(eqt) eq 'equal then t;



procedure cond_leftside(eqt);

   % Left side. eqt is an equation in ofsf. Returns the left side.

   ofsf_arg2l eqt;


procedure cond_rightside(eqt);

   % Right side. eqt is an equation in ofsf. Returns the right side.

   ofsf_arg2r eqt;


procedure cond_0mkeqt(ls);

   % Make equation with right side zero. ls is a standard form.
   % Returns the equation ls = 0 in ofsf.

   ofsf_0mk2('equal, ls);


procedure cond_0mkuneqt(ls);

   % Make unequation. ls anrs are anything. Returns a lisp-prefix-form.

   ofsf_0mk2('neq, ls);


procedure cond_inconsistentp(cl);
   % Inconsistent predicate. cl is a list of ofsf.
   % Returns t if cl is sure inconsistent, nil otherwise.

   if !*pgspsimpl and !*pgspqe then %lazy
      ((if rl_simpl(rl_smkn('and,cl),nil,-1) eq 'false then t) or
	(if (rl_qe(rl_ex(rl_smkn('and,cl),nil),nil) where !*rlverbose = nil)
	 eq 'false then t))
   else if !*pgspsimpl then
      (if rl_simpl(rl_smkn('and,cl),nil,-1) eq 'false then t)
   else if !*pgspqe then
      (if (rl_qe(rl_ex(rl_smkn('and,cl),nil),nil) where !*rlverbose = nil)
	 eq 'false then t)
   else rederr{"cond_inconsistentp: No simplifier switched on."};


procedure cond_simpl(cl);
   % Simplification. cl is a list of ofsf.
   % Returns a ofsf $c$ that satisfies \forall(\and(cl)<->c)

   rl_simpl(rl_smkn('and,cl),nil,-1);


procedure cond_qe(cl);
   % Quantifier elimination. cl is a list of ofsf.
   % Returns a ofsf $c$ that satisfies \forall(\ex(\and(cl))<->c)

   (rl_qe(rl_ex(rl_smkn('and,cl),nil),nil) where !*rlverbose = nil);
%  (rl_qe(     (rl_smkn('and,cl)    ),nil) where !*rlverbose = nil);


procedure cond_prin2(c);
   % Print.
   mathprint rl_prepfof c;


procedure cond_prin2l(cl);
   % Print list.
   for each c in cl do mathprint rl_prepfof c;


%endmodule; % of cond


endmodule; % of pg


end;
