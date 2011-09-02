module resultnt;

% Author: Eberhard Schruefer.

% Modifications by: Anthony C. Hearn, Winfried Neun.

%**********************************************************************
%                                                                     *
% The resultant function defined here has the following properties:   *
%                                                                     *
%                           degr(p1,x)*degr(p2,x)                     *
%  resultant(p1,p2,x) = (-1)                     *resultant(p2,p1,x)  *
%                                                                     *
%                         degr(p2,x)                                  *
%  resultant(p1,p2,x) = p1             if p1 free of x                *
%                                                                     *
%  resultant(p1,p2,x) = 1  if p1 free of x and p2 free of x           *
%                                                                     *
%**********************************************************************

%exports resultant;

%imports reorder,setkorder,degr,addf,negf,multf,multpf;

load_package polydiv;

fluid '(!*bezout !*exp kord!*);

switch bezout;

put('resultant,'simpfn,'simpresultant);

symbolic procedure simpresultant u;
   if length u neq 3
     then rerror(matrix,19,
		   "Resultant called with wrong number of arguments")
    else resultantsq(simp!* car u,simp!* cadr u,!*a2k caddr u)
	 where !*exp = t;

symbolic procedure resultant(u,v,var);
   % Kept for compatibility with old code.
   if domainp u and domainp v then 1
    else begin scalar x;
       kord!* := var . kord!*;  % updkorder can't be used here.
				% See sum test.
       if null domainp u and null(mvar u eq var) then u := reorder u;
       if null domainp v and null(mvar v eq var) then v := reorder v;
       x := if !*bezout then bezout_resultant(u,v,var)
	     else !*a2f polyresultant(prepf u,prepf v,var);
       setkorder cdr kord!*;
       return x
   end;

symbolic procedure resultantsq(u,v,var);
   if domainp numr u and domainp numr v and denr u = 1 and denr v = 1
     then 1 ./ 1
    else begin scalar x;
       kord!* := var . kord!*;  % updkorder can't be used here.
				% See sum test.
       if null domainp numr u and null(mvar numr u eq var)
	 then u := reordsq u;
       if null domainp numr v and null(mvar numr v eq var)
	 then v := reordsq v;
       x := if !*bezout then !*f2q bezout_resultant(!*q2f u,!*q2f v,var)
	     else simp polyresultant(prepsq u,prepsq v,var);
       setkorder cdr kord!*;
       return x
   end;

algebraic (co_off := { co(0,~x) => x });

% algebraic procedure notunivariatep(uu);
%    for i:=1:length uu sum if fixp part(uu,i) then 0 else 1;
   
algebraic procedure notunivariatep uu;
   for each u in uu sum if fixp u then 0 else 1;

algebraic procedure polyresultant(u,v,var);
   % See Zippel's book p 151, subresultant algorithm --
   % more or less the same.
   begin scalar g,h,delta,beta,temp,uu,vv;
      uu := coeff(u,var); vv := coeff(v,var);
      if length uu<length vv
	then return (-1 * polyresultant(v,u,var))
       else if (notunivariatep(uu) > 0) or (notunivariatep(vv)>0)
	then <<u := for i:=1:length uu sum
			(if fixp part(uu,i) then part(uu,i)
			  else (co(0,part(uu,i))))*var^(i-1);
	       v := for i:=1:length vv sum
			(if fixp part(vv,i) then part(vv,i)
			  else (co(0,part(vv,i))))*var^(i-1)>>;
      % Change to nested domain.
      g := h := 1;
      while not (V=0) do
       <<delta := deg(u,var) - deg(v,var);
	 beta := (-1)^(delta +1) * g * h^delta;
	 h := h*(lcof(v,var)/h)^delta;
	 temp := u;
	 u := v;
	 v := pseudo_remainder(temp,v,var)/beta;
	 g := lcof(u,var)>>;
	 if deg(u,var) = 0 then u := u^delta else return 0;
      let co_off; u := u; clearrules co_off;
      return u
   end;

symbolic procedure lcoff(u,var);
   if domainp u or not(mvar u eq var) then 0 else lc u;

symbolic procedure bezout_resultant(u,v,w);
   % U and v are standard forms. Result is resultant of u and v
   % w.r.t. kernel w. Method is Bezout's determinant using exterior
   % multiplication for its calculation.
   begin integer n,nm; scalar ap,ep,uh,ut,vh,vt;
      if domainp u or null(mvar u eq w)
	then return if not domainp v and mvar v eq w 
                      then exptf(u,ldeg v)
		     else 1
       else if domainp v or null(mvar v eq w)
	then return if mvar u eq w then exptf(v,ldeg u) else 1;
      n := ldeg u - ldeg v;
      ep := 1;
      if n<0 then
          <<for j := (-n-1) step -1 until 1 do
              ep := b!:extmult(!*sf2exb(multpf(w to j,u),w),ep);
	      ep := b!:extmult(!*sf2exb(multd((-1)**(-n*ldeg u),u),
					w),
			       ep)>>
       else if n>0 then
            <<for j := (n-1) step -1 until 1 do
                ep := b!:extmult(!*sf2exb(multpf(w to j,v),w),ep);
              ep := b!:extmult(!*sf2exb(v,w),ep)>>;
     nm := max(ldeg u,ldeg v);
     uh := lc u;
     vh := lc v;
     ut := if n<0 then multpf(w to -n,red u)
	   else red u;
     vt := if n>0 then multpf(w to n,red v)
            else red v;
     ap := addf(multf(uh,vt),negf multf(vh,ut));
     ep := if null ep then !*sf2exb(ap,w)
        else b!:extmult(!*sf2exb(ap,w),ep);
     for j := (nm - 1) step -1 until (abs n + 1) do
        <<if degr(ut,w) = j then
         <<uh := addf(lc ut,multf(!*k2f w,uh));
                   ut := red ut>>
       else    uh := multf(!*k2f w,uh);
          if degr(vt,w) = j then
         <<vh := addf(lc vt,multf(!*k2f w,vh));
                   vt := red vt>>
       else    vh := multf(!*k2f w,vh);
      ep := b!:extmult(!*sf2exb(addf(multf(uh,vt),
                    negf multf(vh,ut)),w),ep)>>;
      return if null ep then nil else lc ep
   end;

symbolic procedure !*sf2exb(u,v);
   %distributes s.f. u with respect to powers in v.
   if degr(u,v)=0 then if null u then nil
                        else list 0 .* u .+ nil
    else list ldeg u .* lc u .+ !*sf2exb(red u,v);

%**** Support for exterior multiplication ****
% Data structure is lpow ::= list of degrees in exterior product
%                   lc   ::= standard form

symbolic procedure b!:extmult(u,v);
   %Special exterior multiplication routine. Degree of form v is
   %arbitrary, u is a one-form.
   if null u or null v then  nil
    else if v = 1 then u
    else (if x then cdr x .* (if car x then negf multf(lc u,lc v)
                   else multf(lc u,lc v))
              .+ b!:extadd(b!:extmult(!*t2f lt u,red v),
                    b!:extmult(red u,v))
       else b!:extadd(b!:extmult(red u,v),
              b!:extmult(!*t2f lt u,red v)))
      where x = b!:ordexn(car lpow u,lpow v);

symbolic procedure b!:extadd(u,v);
   if null u then v
    else if null v then u
    else if lpow u = lpow v then
            (lambda x,y; if null x then y else lpow u .* x .+ y)
        (addf(lc u,lc v),b!:extadd(red u,red v))
    else if b!:ordexp(lpow u,lpow v) then lt u .+ b!:extadd(red u,v)
    else lt v .+ b!:extadd(u,red v);

symbolic procedure b!:ordexp(u,v);
   if null u then t
    else if car u > car v then t
    else if car u = car v then b!:ordexp(cdr u,cdr v)
    else nil;

symbolic procedure b!:ordexn(u,v);
   %u is a single integer, v a list. Returns nil if u is a member
   %of v or a dotted pair of a permutation indicator and the ordered
   %list of u merged into v.
   begin scalar s,x;
     a: if null v then return(s . reverse(u . x))
     else if u = car v then return nil
     else if u and u > car v then
                 return(s . append(reverse(u . x),v))
         else  <<x := car v . x;
                 v := cdr v;
                 s := not s>>;
         go to a
   end;

endmodule;

end;
