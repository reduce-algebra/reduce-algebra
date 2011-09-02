% ----------------------------------------------------------------------
% $Id: dvfsfsism.red,v 1.2 1999/03/23 08:47:12 dolzmann Exp $
% ----------------------------------------------------------------------
% Copyright (c) 1995-1999 Andreas Dolzmann and Thomas Sturm
% ----------------------------------------------------------------------
% $Log: dvfsfsism.red,v $
% Revision 1.2  1999/03/23 08:47:12  dolzmann
% Changed copyright information.
% Corrected comments for extracting with exc.
%
% Revision 1.1  1999/03/21 13:36:50  dolzmann
% Initial check-in.
% Smart simplification for discretely valued fields based on susi.
%
% ----------------------------------------------------------------------
lisp <<
   fluid '(dvfsf_sism_rcsid!* dvfsf_sism_copyright!*);
   dvfsf_sism_rcsid!* :=
      "$Id: dvfsfsism.red,v 1.2 1999/03/23 08:47:12 dolzmann Exp $";
   dvfsf_sism_copyright!* :=
      "Copyright (c) 1995-1999 by A. Dolzman and T. Sturm"
>>;

module dvfsfsism;
% Discretely valued field standard form smart simplifier. Submodule of [dvfsf].

procedure dvfsf_smupdknowl(op,atl,knowl,n);
   if !*rlsusi then
      cl_susiupdknowl(op,atl,knowl,n)
   else
      cl_smupdknowl(op,atl,knowl,n);

procedure dvfsf_smrmknowl(knowl,v);
   if !*rlsusi then
      dvfsf_susirmknowl(knowl,v)
   else
      cl_smrmknowl(knowl,v);

procedure dvfsf_smcpknowl(knowl);
   if !*rlsusi then
      cl_susicpknowl(knowl)
   else
      cl_smcpknowl(knowl);

procedure dvfsf_smmkatl(op,knowl,newknowl,n);
   if !*rlsusi then
      cl_susimkatl(op,knowl,newknowl,n)
   else
      cl_smmkatl(op,knowl,newknowl,n);

procedure dvfsf_susirmknowl(knowl,v);
   % Discretely valued field susi remove knowledge. [knowl] is a
   % KNOWL; [v] is a variable. Returns a KNOWL. Remove all information
   % about [v] from [knowl].
   for each p in knowl join
      if v memq dvfsf_varlat car p then nil else {p};

procedure dvfsf_susibin(old,new);
   % Discretely valued field standard form susi binary smart simplification.
   % [old] and [new] are LAT's. Returns ['false] or a SUSIPRG. We
   % assume that [old] is a part of a already existence KNOWL and new
   % has to be added to this KNOWL.
   begin scalar oop,olhs,orhs,olev,nop,nlhs,nrhs,nlev,!*rlsiexpl;
      olev := cdr old;
      old := car old;
      oop := dvfsf_op old;
      olhs := dvfsf_arg2l old;
      orhs := dvfsf_arg2r old;
      nlev := cdr new;
      new := car new;
      nop := dvfsf_op new;
      nlhs := dvfsf_arg2l new;
      nrhs := dvfsf_arg2r new;
      if olhs = nlhs and orhs = nrhs then
      	 return dvfsf_susibin1(oop,nop,nlhs,nrhs,nlev);
      if (olhs = nrhs and orhs = nlhs) then
	 % [oop], [noop] cannot be [equal], [neq]
	 return dvfsf_susibin2(oop,nop,nlhs,nrhs,nlev);
      if (oop eq 'equal or oop eq 'neq) and nop neq 'equal and nop neq 'neq and
	 dvfsf_susibin!-eqlhsmatch(nlhs,nrhs,olhs)
      then
	 return dvfsf_susibin1(oop,nop,nlhs,nrhs,nlev);
      if (nop eq 'equal or nop eq 'neq) and oop neq 'equal and oop neq 'neq and
	 dvfsf_susibin!-eqlhsmatch(olhs,orhs,nlhs)
      then
	 return dvfsf_susibin1(oop,nop,olhs,orhs,nlev);
      return nil
   end;

procedure dvfsf_susibin!-eqlhsmatch(lhs,rhs,eqlhs);
   % Discretely valued field standard form super simplifier binary
   % smart simplification equal left hand side match. Check if
   % $[lhs]-[rhs]=[eqlhs]$.
   begin scalar w;
      w := dvfsf_simplat1(dvfsf_0mk2('equal,addf(lhs,negf rhs)),nil);
      if not rl_tvalp w then
	 return dvfsf_arg2l w = eqlhs;
      return nil
   end;

procedure dvfsf_susibin1(rold,rnew,lhs,rhs,nlev);
   if rold eq rnew then
      '((delete . t))
   else if rold eq 'neq then
      if rnew eq 'equal then
	 'false
      else if rnew eq 'sdiv or rnew eq 'nassoc then
	 '((delete . nil))
      else
	 nil
   else if rold eq 'sdiv then
      if rnew eq 'neq or rnew eq 'div or rnew eq 'nassoc then
	 '((delete . t))
      else  % [rnew memq '(assoc equal)]
	 'false
   else if rold eq 'div then
      if rnew eq 'sdiv or rnew eq 'assoc or rnew eq 'equal then
	 '((delete . nil))
      else if rnew eq 'nassoc then
	 {'(delete . nil),'(delete . t),
	    'add . (dvfsf_mk2('sdiv,lhs,rhs) . nlev)}
      else
	 nil
   else if rold eq 'assoc then
      if rnew eq 'sdiv or rnew eq 'nassoc then
	 'false
      else if rnew eq 'div then
	 '((delete . t))
      else if rnew eq 'equal then
	 '((delete . nil))
      else  % [rnew eq 'neq]
	 nil
   else if rold eq 'equal then
      if rnew eq 'neq or rnew eq 'sdiv or rnew eq 'nassoc then
	 'false
      else  % [rnew memq '(div, assoc)]
	 '((delete . t))
   else if rold eq 'nassoc then
      if rnew eq 'sdiv then
	 '((delete . nil))
      else if rnew eq 'assoc or rnew eq 'equal then
	 'false
      else if rnew eq 'div then
	 {'(delete . nil),'(delete . t),
	    'add . (dvfsf_mk2('sdiv,lhs,rhs) . nlev)}
      else  % [rnew eq 'neq]
	 '((delete . t))
   else
      rederr {"BUG IN dvfsf_susibin1(",rold,",",rnew,")"};

procedure dvfsf_susibin2(rold,rnew,nlhs,nrhs,nlev);
   % Smart simplification with crossed sides. Assumed to be called
   % with valuation relations only, and also not with two of the
   % symmetric relations [assoc], [nassoc].
   if rold eq 'div then
      if rnew eq 'sdiv then
	 'false
      else if rnew eq 'div then
	 {'(delete . nil),'(delete . t),
	    'add . (dvfsf_simplat1(dvfsf_mk2('assoc,nlhs,nrhs),nil) . nlev)}
      else if rnew eq 'assoc then
	 '((delete . nil))
      else if rnew eq 'nassoc then
	 {'(delete . nil),'(delete . t),
	    'add . (dvfsf_mk2('sdiv,nrhs,nlhs) . nlev)}
      else
	 nil
   else if rold eq 'sdiv then
      if rnew eq 'div or rnew eq 'sdiv or rnew eq 'assoc then
	 'false
      else if rnew eq 'nassoc then
	 '((delete . t))
      else
	 nil
   else if rold eq 'nassoc then
      if rnew eq 'sdiv then
	 '((delete . nil))
      else if rnew eq 'div then
	 {'(delete . nil),'(delete . t),
	    'add . (dvfsf_mk2('sdiv,nlhs,nrhs) . nlev)}
      else
	 nil
   else if rold eq 'assoc then
      if rnew eq 'sdiv then
	 'false
      else if rnew eq 'div then
	 '((delete . t))
      else
	 nil
   else
      nil;

procedure dvfsf_susipost(atl,knowl);
   % Discretely valued field standad form susi post simplification. [atl] is a
   % list of atomic formulas. [knowl] is a KNOWL. Returns a list
   % $\lambda$ of atomic formulas, such that
   % $\bigwedge[knowl]\land\bigwedge\lambda$ is equivalent to
   % $\bigwedge[knowl]\land\bigwedge[atl]$
   atl;

procedure dvfsf_susitf(at,knowl);
   % Discretely valued field standard form susi transform. [at] is an
   % atomic formula, [knowl] is a knowledge. Returns an atomic formula
   % $\alpha$ such that $\alpha\land\bigwedge[knowl]$ is equivalent to
   % $[at]\land\bigwedge[knowl]$. $\alpha$ has possibly a more
   % convenient relation than [at].
   at;

endmodule;  % [dvfsfsism]

end;  % of file
