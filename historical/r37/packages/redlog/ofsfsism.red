% ----------------------------------------------------------------------
% $Id: ofsfsism.red,v 1.6 1999/03/23 07:41:39 dolzmann Exp $
% ----------------------------------------------------------------------
% Copyright (c) 1995-1999 Andreas Dolzmann and Thomas Sturm
% ----------------------------------------------------------------------
% $Log: ofsfsism.red,v $
% Revision 1.6  1999/03/23 07:41:39  dolzmann
% Changed copyright information.
%
% Revision 1.5  1996/10/07 12:03:33  sturm
% Added fluids for CVS and copyright information.
%
% Revision 1.4  1996/09/30 16:56:12  sturm
% Cleaned up the use of several (conditional) negate-relation procedures.
%
% Revision 1.3  1996/07/15 13:29:10  sturm
% Modified data structure descriptions for automatic processing.
%
% Revision 1.2  1996/07/13 11:20:35  dolzmann
% Added black box implementation ofsf_smcpknowl.
% Removed black box implementations ofsf_smsimpl!-impl and
% ofsf_smsimpl!-equiv1.
%
% Revision 1.1  1996/03/22 12:14:17  sturm
% Moved and split.
%
% ----------------------------------------------------------------------
lisp <<
   fluid '(ofsf_sism_rcsid!* ofsf_sism_copyright!*);
   ofsf_sism_rcsid!* := "$Id: ofsfsism.red,v 1.6 1999/03/23 07:41:39 dolzmann Exp $";
   ofsf_sism_copyright!* :=
      "Copyright (c) 1995-1999 by A. Dolzmann and T. Sturm"
>>;

module ofsfsism;
% Ordered field standard form smart simplification. Submodule of [ofsf].

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

procedure ofsf_smmkatl(op,oldknowl,newknowl,n);
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
      al := '((equal . ((equal . false) (neq . (equal . T)) (geq . (equal .T))
            (leq . false) (greaterp . (equal . T)) (lessp . false)))
         (neq . ((equal . (equal . nil)) (neq . nil) (geq . nil)
            (leq . (leq . nil)) (greaterp . nil) (lessp . (lessp . nil))))
         (geq . ((equal . false) (neq . (geq . T)) (geq . (geq . T))
            (leq . false) (greaterp . (geq . T)) (lessp . false)))
         (leq . ((equal . (equal . nil)) (neq . nil) (geq . nil)
            (leq . (leq . nil)) (greaterp . nil) (lessp . (lessp . nil))))
         (greaterp . ((equal . false) (neq . (greaterp . T))
            (geq . (greaterp . T)) (leq . false) (greaterp . (greaterp . T))
            (lessp . false)))
         (lessp . ((equal . (equal . nil)) (neq . nil) (geq . nil)
            (leq . (leq . nil)) (greaterp . nil) (lessp . (lessp . nil)))));
      return cdr atsoc(r2,atsoc(r1,al))
   end;

endmodule;  % [ofsfsism]

end;  % of file
