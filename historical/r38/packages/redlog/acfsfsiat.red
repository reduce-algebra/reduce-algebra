% ----------------------------------------------------------------------
% $Id: acfsfsiat.red,v 1.5 1999/05/06 12:18:32 sturm Exp $
% ----------------------------------------------------------------------
% Copyright (c) 1995-1999 Andreas Dolzmann and Thomas Sturm
% ----------------------------------------------------------------------
% $Log: acfsfsiat.red,v $
% Revision 1.5  1999/05/06 12:18:32  sturm
% Updated comments for exported procedures.
%
% Revision 1.4  1999/04/12 09:25:59  sturm
% Updated comments for exported procedures.
%
% Revision 1.3  1999/03/23 12:26:29  sturm
% Renamed switch rlsisqf to rlsiatadv.
%
% Revision 1.2  1999/03/23 07:59:43  dolzmann
% Added missing CVS header.
% Added fluids for the rcsid of the file and for the copyright information.
% Added copyright information.
%
% Revision 1.1  1997/08/22 17:30:42  sturm
% Created an acfsf context based on ofsf.
%
% ----------------------------------------------------------------------
lisp <<
   fluid '(acfsf_siat_rcsid!* acfsf_siat_copyright!*);
   acfsf_siat_rcsid!* := "$Id: acfsfsiat.red,v 1.5 1999/05/06 12:18:32 sturm Exp $";
   acfsf_siat_copyright!* := "Copyright (c) 1995-1999 A. Dolzmann and T. Sturm"
>>;

module acfsfsiat;
% Algebraically closed field standard form simplification for atomic
% formulas. Submodule of [acfsf]. This submodule provides the service
% [rl_simplat1] to [cl_simpl].

procedure acfsf_simplat1(f,sop);
   % Algebraically closed field standard form simplify atomic formula.
   % [f] is an atomic formula; [sop] is the complex formula operator
   % [f] occurs with or [nil]. Accesses switches [rlsiatadv],
   % [rlsifac], [rlsiexpl], and [rlsiexpla]. Returns a quantifier-free
   % formula that is a simplified equivalent of [f].
   begin scalar rel,lhs;
      rel := acfsf_op f;
      if not (rel memq '(equal neq)) then
 	 return nil;
      lhs := acfsf_arg2l f;
      if domainp lhs then
 	 return if acfsf_evalatp(rel,lhs) then 'true else 'false;
      lhs := quotf(lhs,sfto_dcontentf lhs);
      if minusf lhs then
    	 lhs := negf lhs;
      if null !*rlsiatadv then return acfsf_0mk2(rel,lhs);
      if rel eq 'equal then return acfsf_simplequal(lhs,sop);
      if rel eq 'neq then return acfsf_simplneq(lhs,sop)
   end;

procedure acfsf_simplequal(lhs,sop);
   % Algebraically closed field standard form simplify [equal]-atomic
   % formula. [lhs] is a term. Returns a quantifier-free formula.
   begin scalar w,ff,ww;
      ff := sfto_sqfpartf lhs;
      if !*rlsifac and (!*rlsiexpla or !*rlsiexpl and sop = 'or) then
	 return acfsf_facequal ff;
      return acfsf_0mk2('equal,ff)
   end;

procedure acfsf_facequal(f);
   % Left hand side factorization [equal] case.
   rl_smkn('or,for each x in cdr fctrf f collect acfsf_0mk2('equal,car x));

procedure acfsf_simplneq(lhs,sop);
   % Algebraically closed field standard form simplify [neq]-atomic
   % formula. [lhs] is a term. Returns a quantifier-free formula.
   begin scalar w,ff,ww;
      ff := sfto_sqfpartf lhs;
      if !*rlsifac and (!*rlsiexpla or !*rlsiexpl and sop = 'and) then
	 return acfsf_facneq ff;
      return acfsf_0mk2('neq,ff)
   end;

procedure acfsf_facneq(f);
   % Left hand side factorization [neq] case.
   rl_smkn('and,for each x in cdr fctrf f collect acfsf_0mk2('neq,car x));

procedure acfsf_evalatp(rel,lhs);
   % Algebraically closed field standard form evaluate atomic formula.
   % [rel] is a relation; [lhs] is a domain element. Returns a truth
   % value equivalent to $[rel]([lhs],0)$.
   if rel eq 'equal then null lhs
   else if rel eq 'neq then not null lhs
   else rederr {"acfsf_evalatp: unknown operator ",rel};

endmodule;  % [acfsfsiat]

end;  % of file
