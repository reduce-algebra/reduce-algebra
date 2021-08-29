module ofsfsism;  % Ordered field standard form smart simplification.

revision('ofsfsism, "$Id$");

copyright('ofsfsism, "(c) 1995-2009 A. Dolzmann, T. Sturm");

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

procedure ofsf_smwupdknowl(op,atl,knowl,n);
   % Ordered field standard form smart simplification wrapper update
   % knowledge.
   if !*rlsusi then
      cl_susiupdknowl(op,atl,knowl,n)
   else
      ofsf_smupdknowl(op,atl,knowl,n);

procedure ofsf_smwrmknowl(knowl,v);
   if !*rlsusi then
      ofsf_susirmknowl(knowl,v)
   else
      ofsf_smrmknowl(knowl,v);

procedure ofsf_smwcpknowl(knowl);
   if !*rlsusi then
      cl_susicpknowl(knowl)
   else
      ofsf_smcpknowl(knowl);

procedure ofsf_smwmkatl(op,knowl,newknowl,n);
   if !*rlsusi then
      cl_susimkatl(op,knowl,newknowl,n)
   else
      ofsf_smmkatl(op,knowl,newknowl,n);

% The black boxes are rl_smsimpl!-impl and rl_smsimpl!-equiv1 are set
% correctly for both the regular smart simplifier and for susi.

%DS
% <irl> ::= (<ir>,...)
% <ir> ::= <para> . <db>
% <db> ::= (<le>,...)
% <le> ::= <label> . <entry>
% <label> ::= <integer>
% <entry> ::= <of relation> . <standard quotient>

procedure ofsf_smrmknowl(knowl,v);
   % Ordered field standard form remove from knowledge. [knowl] is an
   % IRL; [v] is a variable. Returns an IRL. Destructively removes any
   % information about [v] from [knowl].
   if null knowl then
      nil
   else if v member kernels caar knowl then
      ofsf_smrmknowl(cdr knowl,v)
   else <<
      cdr knowl := ofsf_smrmknowl(cdr knowl,v);
      knowl
   >>;

procedure ofsf_smcpknowl(knowl);
   for each ir in knowl collect
      car ir . append(cdr ir,nil);

procedure ofsf_smupdknowl(op,atl,knowl,n);
   % Ordered field standard form update knowledge. [op] is one of
   % [and], [or]; [atl] is a list of (simplified) atomic formulas;
   % [knowl] is a conjunctive IRL; [n] is the current level. Returns
   % an IRL. Destructively updates [knowl] wrt. the [atl] information.
   begin scalar w,ir,a;
      while atl do <<
         a := if op eq 'and then car atl else ofsf_negateat car atl;
         atl := cdr atl;
         ir := ofsf_at2ir(a,n);
         if w := assoc(car ir,knowl) then <<
            cdr w := ofsf_sminsert(cadr ir,cdr w);
            if cdr w eq 'false then <<
               atl := nil;
               knowl := 'false
            >>  % else [ofsf_sminsert] has updated [cdr w] destructively.
         >> else
            knowl := ir . knowl
      >>;
      return knowl
   end;

switch rlsippatl, rlsippsubst, rlsippsignchk;
on1 'rlsippatl;
on1 'rlsippsubst;
on1 'rlsippsignchk;

procedure ofsf_smmkatl(op,oldknowl,newknowl,n);
   if !*rlsippatl then
      ofsf_sippatl(op,ofsf_smmkatl1(op,oldknowl,newknowl,n),newknowl)
   else
      ofsf_smmkatl1(op,oldknowl,newknowl,n);

procedure ofsf_smmkatl1(op,oldknowl,newknowl,n);
   % Ordered field standard form make atomic formula list. [op] is one
   % of [and], [or]; [oldknowl] and [newknowl] are IRL's; [n] is an
   % integer. Returns a list of atomic formulas. Depends on switch
   % [rlsipw].
   if op eq 'and then
      ofsf_smmkatl!-and(oldknowl,newknowl,n)
   else  % [op eq 'or]
      ofsf_smmkatl!-or(oldknowl,newknowl,n);

procedure ofsf_smmkatl!-and(oldknowl,newknowl,n);
   begin scalar w;
      if not !*rlsipw and !*rlsipo then
         return ofsf_irl2atl('and,newknowl,n);
      return for each ir in newknowl join <<
         w := atsoc(car ir,oldknowl);
         if null w then ofsf_ir2atl('and,ir,n) else ofsf_smmkatl!-and1(w,ir,n)
      >>;
   end;

procedure ofsf_smmkatl!-and1(oir,nir,n);
   begin scalar w,parasq;
      parasq := !*f2q car nir;
      return for each le in cdr nir join
      if car le = n then <<
         if cadr le memq '(lessp greaterp) and
            (w := ofsf_smmkat!-and2(cdr oir,cdr le,parasq))
         then
            {w}
         else
            {ofsf_entry2at('and,cdr le,parasq)}
      >>
   end;

procedure ofsf_smmkat!-and2(odb,ne,parasq);
   % Ordered field standard form smart simplify make atomic formula.
   % [odb] is a DB; [ne] is an entry with its relation being one of
   % [lessp], [greaterp]; [parasq] is a numerical SQ. Returns an
   % atomic formula.
   begin scalar w;
      w := ofsf_smdbgetrel(cdr ne,odb);
      if w eq 'neq then
         (if !*rlsipw then <<
            if car ne eq 'lessp then
               return ofsf_entry2at('and,'leq . cdr ne,parasq);
            % We know [car ne eq 'greaterp].
            return ofsf_entry2at('and,'geq . cdr ne,parasq)
         >>)
      else if w memq '(leq geq) then
         if not !*rlsipo then
            return ofsf_entry2at('and,'neq . cdr ne,parasq)
   end;

procedure ofsf_smmkatl!-or(oldknowl,newknowl,n);
   begin scalar w;
      return for each ir in newknowl join <<
         w := atsoc(car ir,oldknowl);
         if null w then ofsf_ir2atl('or,ir,n) else ofsf_smmkatl!-or1(w,ir,n)
      >>;
   end;

procedure ofsf_smmkatl!-or1(oir,nir,n);
   begin scalar w,parasq;
      parasq := !*f2q car nir;
      return for each le in cdr nir join
      if car le = n then <<
         if cadr le memq '(lessp greaterp equal) and
            (w := ofsf_smmkat!-or2(cdr oir,cdr le,parasq))
         then
            {w}
         else
            {ofsf_entry2at('or,cdr le,parasq)}
      >>
   end;

procedure ofsf_smmkat!-or2(odb,ne,parasq);
   begin scalar w;
      w := ofsf_smdbgetrel(cdr ne,odb);
      if w eq 'neq then
         (if not !*rlsipw then <<
            if car ne eq 'lessp then
               return ofsf_entry2at('or,'leq . cdr ne,parasq);
            % We know [car ne eq 'greaterp]!
            return ofsf_entry2at('or,'geq . cdr ne,parasq)
         >>)
      else if w memq '(leq geq) then <<
         if car ne memq '(lessp greaterp) then
            return ofsf_entry2at('or,'neq . cdr ne,parasq);
         % We know [car ne eq 'equal].
         if !*rlsipo then
            return ofsf_entry2at('or,ofsf_anegrel w . cdr ne,parasq)
      >>
   end;

procedure ofsf_sippatl(op,atl,newknowl);
   begin scalar gtrue, gfalse, gequal, subal, zvl, posvl, negvl, geqvl, leqvl,
         neqvl, at, natl;
      gtrue := cl_cflip('true, op eq 'and);
      gfalse := cl_cflip('false, op eq 'and);
      gequal := ofsf_clnegrel('equal, op eq 'and);
      {subal, zvl, posvl, negvl, geqvl, leqvl, neqvl} :=
         ofsf_exploitKnowl newknowl;
      while atl do <<
         at := pop atl;
         if !*rlsippsubst and not ofsf_vareqnp(gequal, at) then <<
            at := ofsf_sippsubst(at, subal);
            at := ofsf_simplat1(at,op) where !*rlsiatadv=nil
         >>;
         if not rl_tvalp at then
            if !*rlsippsignchk and not sfto_varIsNumP ofsf_arg2l at then
               at := ofsf_sippsignchk(at, zvl, posvl, negvl, geqvl, leqvl, neqvl);
         if at eq gfalse then <<
            natl := gfalse;
            atl := nil
         >> else if at neq gtrue then
            natl := lto_insert(at, natl)
      >>;
      return natl
   end;

procedure ofsf_vareqnp(gequal, at);
   % The original idea here was to check also that [ofsf_op at] is [gequal] but
   % this is not compatible with [on !*rlsipo] in disjunctions. One
   % counterexample is [b >= 0 and a - 1 >= 0 and (b = 0 or a - 1 > 0)].
   sfto_varIsNumP ofsf_arg2l at;

procedure ofsf_sippsignchk(at, zvl, posvl, negvl, geqvl, leqvl, neqvl);
   begin scalar op, sign;
      op := ofsf_op at;
      sign := ofsf_sippsignchkf(
         ofsf_arg2l at, zvl, posvl, negvl, geqvl, leqvl, neqvl);
      if op eq sign then
         return 'true;
      if op eq 'equal then
         return if sign memq '(neq lessp greaterp) then 'false else at;
      if op eq 'greaterp then
         return if sign memq '(equal lessp leq) then 'false else at;
      if op eq 'lessp then
         return if sign memq '(equal greaterp geq) then 'false else at;
      if op eq 'geq then
         return if sign memq '(equal greaterp) then
            'true
         else if sign eq 'lessp then
            'false
         else
            at;
      if op eq 'leq then
         return if sign memq '(equal lessp) then
            'true
         else if sign eq 'greaterp then
            'false
         else
            at;
      if op eq 'neq then
         return if sign memq '(lessp greaterp) then
            'true
         else if sign eq 'equal then
            'false
         else
            at;
      return at
   end;

procedure ofsf_sippsignchkf(f, zvl, posvl, negvl, geqvl, leqvl, neqvl);
   begin scalar slc, sred, slt, slm;
      if domainp f then
         return ofsf_updSignDom f;
      slt := ofsf_updSignVar(mvar f, zvl, posvl, negvl, geqvl, leqvl, neqvl);
      if slt eq 'unknown then
         return 'unknown;
      slc := ofsf_sippsignchkf(lc f, zvl, posvl, negvl, geqvl, leqvl, neqvl);
      if slc eq 'unknown then
         return 'unknown;
      sred := ofsf_sippsignchkf(red f, zvl, posvl, negvl, geqvl, leqvl, neqvl);
      if sred eq 'unknown then
         return 'unknown;
      slt := ofsf_updSignPow(slt, ldeg f);
      slm := ofsf_updSignMult(slc, slt);
      if slm eq 'unknown then
         return 'unknown;
      return ofsf_updSignAdd(slm, sred)
   end;

procedure ofsf_updSignDom(d);
   if null d then
      'equal
   else if d > 0 then
      'greaterp
   else if d < 0 then
      'lessp
   else
      rederr {"something wrong in ofsf_updSignDom:", d};

procedure ofsf_updSignVar(v, zvl, posvl, negvl, geqvl, leqvl, neqvl);
   if v memq zvl then
      'equal
   else if v memq posvl then
      'greaterp
   else if v memq negvl then
      'lessp
   else if v memq geqvl then
      'geq
   else if v memq leqvl then
      'leq
   else if v memq neqvl then
      'neq
   else
      'unknown;

procedure ofsf_updSignPow(sign, deg);
   if sign memq '(equal greaterp geq neq) then
      sign
   else if sign memq '(lessp leq) then
      ofsf_canegrel(sign, not evenp deg)
   else
      'unknown;

inline procedure ofsf_prEq(a1,a2,b1,b2);
   a1 eq b1 and a2 eq b2 or a1 eq b2 and a2 eq b1;

procedure ofsf_updSignAdd(old,new);
   % rels := {'equal, 'leq, 'geq, 'lessp, 'greaterp, 'neq};
   % for each r1 in rels do for each r2 in rels do
   %    ioto_tprin2t {r1," + ",r2," = ",ofsf_updSignAdd(r1,r2)};
   if not old or old eq 'equal then
      new
   else if new eq 'equal then
      old
   else if old eq new and old neq 'neq then
      old
   else if ofsf_prEq(old, new, 'leq, 'lessp) then
      'lessp
   else if ofsf_prEq(old, new, 'geq, 'greaterp) then
      'greaterp
   else
      'unknown;

procedure ofsf_updSignMult(old,new);
   % rels := {'equal, 'leq, 'geq, 'lessp, 'greaterp, 'neq};
   % for each r1 in rels do for each r2 in rels do
   %    ioto_tprin2t {r1," * ",r2," = ",ofsf_updSignMult(r1,r2)};
   if not old or old eq 'greaterp then
      new
   else if new eq 'greaterp then
      old
   else if old eq 'lessp then
      ofsf_anegrel new
   else if new eq 'lessp then
      ofsf_anegrel old
   else if old eq 'geq and new eq 'geq or old eq 'leq and new eq 'leq then
      'geq
   else if old eq 'leq and new eq 'geq or old eq 'geq and new eq 'leq then
      'leq
   else if old eq 'equal or new eq 'equal then
      'equal
   else if old eq 'neq and new eq 'neq then
      'neq
   else
      'unknown;

procedure ofsf_exploitKnowl(knowl);
   begin
      scalar subal, zvl, posvl, negvl, geqvl, leqvl, neqvl, v, rel, a;
      integer n;
      for each ir in knowl do
         if (v := sfto_varp car ir) then
            for each le in cdr ir do <<
               rel . a := cdr le;
               a := negsq a;
               n := numr a or 0;
               if rel eq 'equal then
                  if !*rlsippsubst then
                     subal := (v . a) . subal
                  else
                     (if n > 0 then
                        posvl := lto_insertq(v, posvl)
                     else if n < 0 then
                        negvl := lto_insertq(v, negvl)
                     else if eqn(n,0) then
                        zvl := lto_insertq(v, zvl))
               else if rel eq 'greaterp then
                  (if n >= 0 then
                     posvl := lto_insertq(v, posvl))
               else if rel eq 'geq then
                  (if n > 0 then
                     posvl := lto_insertq(v, posvl)
                  else if eqn(n,0) then
                     geqvl := lto_insertq(v, geqvl))
               else if rel eq 'lessp then
                  (if n <= 0 then
                     negvl := lto_insertq(v, negvl))
               else if rel eq 'leq then
                  (if n < 0 then
                     negvl := lto_insertq(v, negvl)
                  else if eqn(n,0) then
                     leqvl := lto_insertq(v, leqvl))
               else if rel eq 'neq then
                  (if eqn(n,0) then
                     neqvl := lto_insertq(v, neqvl))
            >>;
      return {subal, zvl, posvl, negvl, geqvl, leqvl, neqvl}
   end;

procedure ofsf_sippsubst(f,al);
   if al then ofsf_sippsubst1(f,al) else f;

procedure ofsf_sippsubst1(f,al);
   ofsf_0mk2(rl_op f, numr ofsf_siatsubf(ofsf_arg2l f,al));

procedure ofsf_siatsubf(f,al);
   begin scalar nred, nlc, w;
      if domainp f then
         return !*f2q f;
      nred := ofsf_siatsubf(red f,al);
      nlc := ofsf_siatsubf(lc f,al);
      if (w := atsoc(mvar f, al)) then
         return addsq(multsq(nlc,exptsq(cdr w,ldeg f)),nred);
      return addsq(multsq(nlc,ofsf_pow2q(mvar f,ldeg f)),nred)
   end;

procedure ofsf_smdbgetrel(abssq,db);
   if abssq = cddar db then
      cadar db
   else if cdr db then
      ofsf_smdbgetrel(abssq,cdr db);

procedure ofsf_at2ir(atf,n);
   % Ordered field standard form atomic formula to IR. [atf] is an
   % atomic formula; [n] is an integer. Returns the IR representing
   % [atf] on level [n].
   begin scalar op,par,abs,c;
      op := ofsf_op atf;
      abs := par := ofsf_arg2l atf;
      while not domainp abs do abs := red abs;
      par := addf(par,negf abs);
      c := sfto_dcontentf(par);
      par := quotf(par,c);
      abs := quotsq(!*f2q abs,!*f2q c);
      return par . {n . (op . abs)}
   end;

procedure ofsf_irl2atl(op,irl,n);
   % Ordered field standard form IRL to atomic formula list. [irl] is
   % an IRL; [n] is an integer. Returns a list of atomic formulas
   % containing the level-[n] atforms encoded in IRL.
   for each ir in irl join ofsf_ir2atl(op,ir,n);

procedure ofsf_ir2atl(op,ir,n);
   (for each le in cdr ir join
      if car le = n then {ofsf_entry2at(op,cdr le,a)}) where a=!*f2q car ir;

procedure ofsf_entry2at(op,entry,parasq);
   if !*rlidentify then
      cl_identifyat ofsf_entry2at1(op,entry,parasq)
   else
      ofsf_entry2at1(op,entry,parasq);

procedure ofsf_entry2at1(op,entry,parasq);
   ofsf_0mk2(ofsf_clnegrel(car entry,op eq 'and),numr addsq(parasq,cdr entry));

procedure ofsf_sminsert(le,db);
   % Ordered field standard form smart simplify insert. [le] is a
   % marked entry; [db] is a database. Returns a database.
   % Destructively inserts [le] into [db].
   begin scalar a,w,scdb,oscdb;
      repeat <<
         w := ofsf_sminsert1(cadr car db,cddr car db,cadr le,cddr le,car le);
         if w and not idp w then <<  % identifiers [false] and [true] possible.
            db := cdr db;
            le := w
         >>
      >> until null w or idp w or null db;
      if w eq 'false then return 'false;
      if w eq 'true then return db;
      if null db then return {le};
      oscdb := db;
      scdb := cdr db;
      while scdb do <<
         a := car scdb;
         scdb := cdr scdb;
         w := ofsf_sminsert1(cadr a,cddr a,cadr le,cddr le,car le);
         if w eq 'true then <<
            scdb := nil;
            a := 'true
         >> else if w eq 'false then <<
            scdb := nil;
            a := 'false
         >> else if w then <<
            cdr oscdb := scdb;
            le := w
         >> else
            oscdb := cdr oscdb
      >>;
      if a eq 'false then return 'false;
      if a eq 'true then return db;
      return le . db
   end;

procedure ofsf_sminsert1(r1,a,r2,b,n);
   % Ordered field standard form smart simplify insert. [r1], [r2] are
   % relations, [a], [b] are absolute summands in SQ representation;
   % [n] is the current level. Returns [nil], [false], [true], or a
   % marked entry. Simplification of $\alpha=[r2](f+b,0)$ under the
   % condition $\gamma=[r1](f+a,0)$ is considered: [nil] means there
   % is no simplification posssible; [true] means that $\gamma$
   % implies $\alpha$; [false] means that $\alpha$ contradicts
   % $\gamma$; the atomic formula encoded by a resulting marked entry
   % wrt. $f$ is equivalent to $\alpha$ under $\gamma$.
   begin scalar w,diff,n;
      diff := numr subtrsq(a,b);
      if null diff then <<
         w := ofsf_smeqtable(r1,r2);
         if w eq 'false then return 'false;
         if r1 eq w then return 'true;
         return n . (w . a)
      >>;
      if minusf diff then <<
         w := ofsf_smordtable(r1,r2);
         if atom w then return w;
         if eqcar(w,r1) and cdr w then return 'true;
         return n . (car w . if cdr w then a else b)
      >>;
      w := ofsf_smordtable(r2,r1);
      if atom w then return w;
      if eqcar(w,r1) and null cdr w then return 'true;
      return n . (car w . if cdr w then b else a)
   end;

procedure ofsf_smeqtable(r1,r2);
   % Ordered field standard form smart simplify equal absolute
   % summands table. [r1], [r2] are relations. Returns [false] or a
   % relation $R$ such that $R(f+a,0)$ is equivalent to $[r1](f+a,0)
   % \land [r2](f+a,0)$.
   begin scalar al;
      al := '((equal . ((equal . equal) (neq . false) (geq . equal)
           (leq . equal) (greaterp . false) (lessp . false)))
        (neq . ((neq . neq) (geq . greaterp) (leq . lessp)
           (greaterp . greaterp) (lessp . lessp)))
        (geq . ((geq . geq) (leq . equal) (greaterp . greaterp)
           (lessp . false)))
        (leq . ((leq . leq) (greaterp . false) (lessp . lessp)))
        (greaterp . ((greaterp . greaterp) (lessp . false)))
        (lessp . ((lessp . lessp))));
      return cdr (atsoc(r2,atsoc(r1,al)) or atsoc(r1,atsoc(r2,al)))
   end;

procedure ofsf_smordtable(r1,r2);
   % Ordered field standard form smart simplify ordered absolute
   % summands table. [r1], [r2] are relations. Returns [nil], which
   % means that no simplification is possible, [false] or a pair $R .
   % s$ where $R$ is a relation and $s$ is one of [T], [nil]. For
   % absolute summands $a<b$ we have $[r1](f+a,0) \land [r2](f+b,0)$
   % equivalent to $R(f+a,0)$ in case $[s]=[T]$ or to $R(f+b,0)$ in
   % case $[s]=[nil]$.
   begin scalar al;
      al := '((equal . ((equal . false) (neq . (equal . t)) (geq . (equal .t))
            (leq . false) (greaterp . (equal . t)) (lessp . false)))
         (neq . ((equal . (equal . nil)) (neq . nil) (geq . nil)
            (leq . (leq . nil)) (greaterp . nil) (lessp . (lessp . nil))))
         (geq . ((equal . false) (neq . (geq . t)) (geq . (geq . t))
            (leq . false) (greaterp . (geq . t)) (lessp . false)))
         (leq . ((equal . (equal . nil)) (neq . nil) (geq . nil)
            (leq . (leq . nil)) (greaterp . nil) (lessp . (lessp . nil))))
         (greaterp . ((equal . false) (neq . (greaterp . t))
            (geq . (greaterp . t)) (leq . false) (greaterp . (greaterp . t))
            (lessp . false)))
         (lessp . ((equal . (equal . nil)) (neq . nil) (geq . nil)
            (leq . (leq . nil)) (greaterp . nil) (lessp . (lessp . nil)))));
      return cdr atsoc(r2,atsoc(r1,al))
   end;

endmodule;  % [ofsfsism]

end;  % of file
