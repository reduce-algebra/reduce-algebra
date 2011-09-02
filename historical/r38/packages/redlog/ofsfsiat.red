% ----------------------------------------------------------------------
% $Id: ofsfsiat.red,v 1.8 1999/03/23 12:26:33 sturm Exp $
% ----------------------------------------------------------------------
% Copyright (c) 1995-1999 Andreas Dolzmann and Thomas Sturm
% ----------------------------------------------------------------------
% $Log: ofsfsiat.red,v $
% Revision 1.8  1999/03/23 12:26:33  sturm
% Renamed switch rlsisqf to rlsiatadv.
%
% Revision 1.7  1999/03/23 07:41:39  dolzmann
% Changed copyright information.
%
% Revision 1.6  1996/10/08 13:54:37  dolzmann
% Renamed "degree parity decomposition" to "parity decomposition".
% Adapted names of procedures and switches accordingly.
%
% Revision 1.5  1996/10/07 12:03:32  sturm
% Added fluids for CVS and copyright information.
%
% Revision 1.4  1996/09/30 16:56:02  sturm
% Cleaned up the use of several (conditional) negate-relation procedures.
%
% Revision 1.3  1996/09/05 11:16:08  dolzmann
% Fixed a bug in ofsf_simplleq and ofsf_simplgreaterp.
%
% Revision 1.2  1996/05/12 08:27:49  sturm
% Introduced code for splitting of trivial square sums.
%
% Revision 1.1  1996/03/22 12:14:16  sturm
% Moved and split.
%
% ----------------------------------------------------------------------
lisp <<
   fluid '(ofsf_siat_rcsid!* ofsf_siat_copyright!*);
   ofsf_siat_rcsid!* := "$Id: ofsfsiat.red,v 1.8 1999/03/23 12:26:33 sturm Exp $";
   ofsf_siat_copyright!* :=
      "Copyright (c) 1995-1999 by A. Dolzmann and T. Sturm"
>>;

module ofsfsiat;
% Ordered field standard form simplification. Submodule of [ofsf].

procedure ofsf_simplat1(f,sop);
   % Ordered field standard form simplify atomic formula. [f] is an
   % atomic formula; [sop] is the boolean operator [f] occurs with or
   % [nil]. Accesses switches [rlsiatadv], [rlsipd], [rlsiexpl], and
   % [rlsiexpla]. Returns a quantifier-free formula that is a
   % simplified equivalent of [f].
   begin scalar rel,lhs;
      rel := ofsf_op f;
      if not (rel memq '(equal neq leq geq lessp greaterp)) then
 	 return nil;
      lhs := ofsf_arg2l f;
      if domainp lhs then
 	 return if ofsf_evalatp(rel,lhs) then 'true else 'false;
      lhs := quotf(lhs,sfto_dcontentf lhs);
      if minusf lhs then <<
    	 lhs := negf lhs;
    	 rel := ofsf_anegrel rel
      >>;
      if null !*rlsiatadv then return ofsf_0mk2(rel,lhs);
      if rel eq 'equal then return ofsf_simplequal(lhs,sop);
      if rel eq 'neq then return ofsf_simplneq(lhs,sop);
      if rel eq 'leq then return ofsf_simplleq(lhs,sop);
      if rel eq 'geq then return ofsf_simplgeq(lhs,sop);
      if rel eq 'lessp then return ofsf_simpllessp(lhs,sop);
      if rel eq 'greaterp then return ofsf_simplgreaterp(lhs,sop)
   end;

procedure ofsf_simplequal(lhs,sop);
   % Ordered field standard form simplify [equal]-atomic formula.
   % [lhs] is a term. Returns a quantifier-free formula.
   begin scalar w,ff,ww;
      w := sfto_tsqsumf lhs;
      if w eq 'stsq then return 'false;
      ff := sfto_sqfpartf lhs;
      ww := sfto_tsqsumf ff;
      if ww eq 'stsq then return 'false;
      if !*rlsitsqspl and (!*rlsiexpla or !*rlsiexpl and sop = 'and) then <<
	 if ww eq 'tsq then return ofsf_tsqsplequal ff;
	 if w eq 'tsq then return ofsf_tsqsplequal lhs
      >>;
      if !*rlsifac and (!*rlsiexpla or !*rlsiexpl and sop = 'or) then
	 return ofsf_facequal ff;
      return ofsf_0mk2('equal,ff)
   end;

procedure ofsf_tsqsplequal(f);
   % Trivial square sum split [equal] case.
   begin scalar w;
      w := ofsf_getsqsummons(f);
      if !*rlsifac and (!*rlsiexpla or !*rlsiexpl and null cdr w) then
	 return rl_smkn('and,for each m in w collect
	    rl_smkn('or,for each v in m collect ofsf_0mk2('equal,v)));
      return rl_smkn('and,for each m in w collect
 	 ofsf_0mk2('equal,ofsf_lmultf m))
   end;

procedure ofsf_facequal(f);
   % Left hand side factorization [equal] case.
   rl_smkn('or,for each x in cdr fctrf f collect ofsf_0mk2('equal,car x));

procedure ofsf_simplneq(lhs,sop);
   % Ordered field standard form simplify [neq]-atomic formula.
   % [lhs] is a term. Returns a quantifier-free formula.
   begin scalar w,ff,ww;
      w := sfto_tsqsumf lhs;
      if w eq 'stsq then return 'true;
      ff := sfto_sqfpartf lhs;
      ww := sfto_tsqsumf ff;
      if ww eq 'stsq then return 'true;
      if !*rlsitsqspl and (!*rlsiexpla or !*rlsiexpl and sop = 'or) then <<
	 if ww eq 'tsq then return ofsf_tsqsplneq ff;
	 if w eq 'tsq then return ofsf_tsqsplneq lhs
      >>;
      if !*rlsifac and (!*rlsiexpla or !*rlsiexpl and sop = 'and) then
	 return ofsf_facneq ff;
      return ofsf_0mk2('neq,ff)
   end;

procedure ofsf_tsqsplneq(f);
   % Trivial square sum split [neq] case.
   begin scalar w;
      w := ofsf_getsqsummons(f);
      if !*rlsifac and (!*rlsiexpla or !*rlsiexpl and null cdr w) then
	 return rl_smkn('or,for each m in w collect
	    rl_smkn('and,for each v in m collect ofsf_0mk2('neq,v)));
      return rl_smkn('or,for each m in w collect
 	 ofsf_0mk2('neq,ofsf_lmultf m))
   end;

procedure ofsf_facneq(f);
   % Left hand side factorization [neq] case.
   rl_smkn('and,for each x in cdr fctrf f collect ofsf_0mk2('neq,car x));

procedure ofsf_lmultf fl;
   if null fl then
      1
   else if null cdr fl then
      car fl
   else
      multf(car fl,ofsf_lmultf cdr fl);

procedure ofsf_getsqsummons(f);
   begin scalar v,w;
      if null f then return nil;
      if domainp f then return {nil};  % i.e. {1}
      w := ofsf_getsqsummons(red f);
      v := !*k2f mvar f;
      for each x in ofsf_getsqsummons lc f do
	 w := (v . x) . w;
      return w
   end;

procedure ofsf_simplleq(lhs,sop);
   % Ordered field standard form simplify [leq]-atomic formula. [lhs]
   % is a term, [sop] is a boolean operator or [nil]. Accesses
   % switches [rlsipd], [rlexpl], and [rlexpla]. Returns a
   % quantifier-free formula.
   begin scalar s1,s2,w,x;
      if (s1 := sfto_tsqsumf lhs) eq 'stsq then  % necessary?
 	 return 'false;
      w := sfto_sqfpartf lhs;
      if (s2 := sfto_tsqsumf w) eq 'stsq then
 	 return 'false;
      if !*rlsitsqspl and (!*rlsiexpla or !*rlsiexpl and sop = 'and) then <<
	 if s2 then return ofsf_tsqsplequal w;
	 if s1 then return ofsf_tsqsplequal lhs
      >>;
      if s1 or s2 then
 	 return ofsf_0mk2('equal,w);
      if null !*rlsipd then
 	 return ofsf_0mk2('leq,lhs);
      x := sfto_pdecf lhs;
      if sfto_tsqsumf car x then  % in particular, 1 is an stsq.
	 return ofsf_0mk2('equal,w);
      if cdr x = 1 then
	 return ofsf_0mk2('leq,car x);
      if !*rlsiexpla or (!*rlsiexpl and (sop eq 'or)) then
	 return rl_mkn('or,{
	    ofsf_0mk2('leq,car x),ofsf_0mk2('equal,cdr x)});
      return ofsf_0mk2('leq,multf(car x,exptf(cdr x,2)))
   end;

procedure ofsf_simplgeq(lhs,sop);
   % Ordered field standard form simplify [geq]-atomic formula. [lhs]
   % is a term, [sop] is a boolean operator or [nil]. Accesses
   % switches [rlsipd], [rlexpl], and [rlexpla]. Returns a
   % quantifier-free formula.
   begin scalar w;
      if sfto_tsqsumf lhs or sfto_tsqsumf sfto_sqfpartf lhs then
 	 return 'true;
      if null !*rlsipd then
      	 return ofsf_0mk2('geq,lhs);
      w := sfto_pdecf lhs;
      if sfto_tsqsumf car w then
	 return 'true;
      if cdr w = 1 then
	 return ofsf_0mk2('geq,car w);
      if !*rlsiexpla or (!*rlsiexpl and (sop eq 'or)) then
	 return rl_mkn('or,{
	    ofsf_0mk2('geq,car w),ofsf_0mk2('equal,cdr w)});
      return ofsf_0mk2('geq,multf(car w,exptf(cdr w,2)))
   end;

procedure ofsf_simpllessp(lhs,sop);
   % Ordered field standard form simplify [lessp]-atomic formula.
   % [lhs] is a term, [sop] is a boolean operator or [nil]. Accesses
   % switches [rlsipd], [rlexpl], and [rlexpla]. Returns a
   % quantifier-free formula.
   begin scalar w;
      if sfto_tsqsumf lhs or sfto_tsqsumf sfto_sqfpartf lhs then
 	 return 'false;
      if null !*rlsipd then
      	 return ofsf_0mk2('lessp,lhs);
      w := sfto_pdecf lhs;
      if sfto_tsqsumf car w then
	 return 'false;
      if cdr w = 1 then
	 return ofsf_0mk2('lessp,car w);
      if !*rlsiexpla or (!*rlsiexpl and (sop eq 'and)) then
	 return rl_mkn('and,{
	    ofsf_0mk2('lessp,car w),ofsf_0mk2('neq,cdr w)});
      return ofsf_0mk2('lessp,multf(car w,exptf(cdr w,2)))
   end;

procedure ofsf_simplgreaterp(lhs,sop);
   % Ordered field standard form simplify [greaterp]-atomic formula.
   % [lhs] is a term, [sop] is a boolean operator or [nil]. Accesses
   % switches [rlsipd], [rlexpl], and [rlexpla]. Returns a
   % quantifier-free formula.
   begin scalar s1,s2,w,x;
      if (s1 := sfto_tsqsumf lhs) eq 'stsq then  % necessary?
 	 return 'true;
      w := sfto_sqfpartf lhs;
      if (s2 := sfto_tsqsumf w) eq 'stsq then
 	 return 'true;
      if !*rlsitsqspl and (!*rlsiexpla or !*rlsiexpl and sop = 'or) then <<
	 if s2 then return ofsf_tsqsplneq w;
	 if s1 then return ofsf_tsqsplneq lhs
      >>;
      if s1 or s2 then return
 	 ofsf_0mk2('neq,w);
      if null !*rlsipd then
 	 return ofsf_0mk2('greaterp,lhs);
      x := sfto_pdecf lhs;
      if sfto_tsqsumf car x then
	 return ofsf_0mk2('neq,w);
      if cdr x = 1 then
 	 return ofsf_0mk2('greaterp,car x);
      if !*rlsiexpla or (!*rlsiexpl and (sop eq 'and)) then
	 return rl_mkn('and,{
	    ofsf_0mk2('greaterp,car x),ofsf_0mk2('neq,cdr x)});
      return ofsf_0mk2('greaterp,multf(car x,exptf(cdr x,2)))
   end;

procedure ofsf_evalatp(rel,lhs);
   % Ordered field standard form evaluate atomic formula. [rel] is a
   % relation; [lhs] is a domain element. Returns a truth value
   % equivalent to $[rel]([lhs],0)$.
   if rel eq 'equal then null lhs
   else if rel eq 'neq then not null lhs
   else if rel eq 'leq then minusf lhs or null lhs
   else if rel eq 'geq then not minusf lhs
   else if rel eq 'lessp then minusf lhs
   else if rel eq 'greaterp then not (minusf lhs or null lhs)
   else rederr {"ofsf_evalatp: unknown operator ",rel};

endmodule;  % [ofsfsiat]

end;  % of file
