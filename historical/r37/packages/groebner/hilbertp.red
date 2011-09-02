module hilbertp; % Computing Hilbert Polynomial from the Hilbert series.

comment
Authors: H. Michael Moeller, Fernuniversitaet 
	            Hagen, Germany
                    email: MA105@DHAFEU11.bitnet

         H. Melenk, Konrad-Zuse-Zentrum
		    Berlin, Germany
		    email: melenk@sc.ZIB-Berlin.de
;

symbolic procedure newhilbi (bas,var,vars);
 begin scalar baslt,n,u,grad,h,joa,a,ii,dim0,varx,dmode!*,!*modular;

 % extract leading terms

 Baslt:= for each p in cdr bas  collect
           <<u := Hgspliteval list (p,vars); cadr u>>;

 % replace non atomic elements in the varlist by gensyms
   
 for  each x in cdr vars do
	if (pairp x) then 
	  baslt := cdr subeval list(list('equal,x,gensym()),
				    'list . Baslt);

 % compute the Hilbertseries

 joa := hilbsereval list ('list . baslt,var);

 % get the Hilbert polynomial

 grad := deg(joa,var);
 A:= for i:=0:grad collect coeffn (joa,var,i);
 n:= length cdr vars; 

 %dim0 := (for i:=1:n product (var + i))/( for i:=1:n product i);

 varx := !*a2f var;
 dim0 := 1;
 for i:=1:n do dim0:= multf (addd(i,varx),dim0);
 dim0 := multsq(dim0 ./ 1,1 ./ (for i:=1:n product i));

 H := multsq(car(A) ./ 1,dim0);
 A := cdr(A);
 ii := 0;
 
 while a do
  << dim0 := multsq (dim0, addf(varx,numr simp (minus ii) )
                        ./ addf(varx,numr simp (n -ii)));
     ii := ii + 1;
     if not (car a = 0) then H := addsq (H , multsq(car(A) ./ 1 ,dim0));
     A := cdr(A) >>;
 return mk!*sq H;
 end;

symbolic procedure psnewhilbi (u);
  begin scalar zz,pl,vl;
   pl:=reval car u;
   if cdr u then vl:=listeval(cadr u,nil);
   zz := 'list.groebnervars(cdr pl,vl);
   return  newhilbi(pl,'x,zz)
  end;
   
put ('hilbertpolynomial , 'psopfn ,'psnewhilbi);

symbolic procedure HGspliteval pars;
   % A variant of Gsplit from grinterf.red.
   % Split a polynomial into leading monomial and reductum.
   begin scalar vars,x,u,v,w,oldorder,!*factor,!*exp;
         integer n,pcount!*; !*exp := t;
      n := length pars;
      u := reval car pars;
      v := if n>1 then reval cadr pars else nil;
      u := list('LIST,u);
      w := for each j in groerevlist u
              collect if eqexpr j then !*eqn2a j else j;
      vars :=groebnervars(w,v);
      if not vars then  vdperr 'hilbertpolynomial;
      oldorder := vdpinit vars;
      w := a2vdp car w;
      if vdpzero!? w then x := w else
%     <<x := vdpfmon(vdplbc w,vdpevlmon w);
      <<x := vdpfmon('( 1 . 1),vdpevlmon w);
        w := vdpred w>>;
      w := list('LIST,vdp2a x,vdp2a w);
      setkorder oldorder;
      return w;
   end;

 
% simple Array access method for one- and two-dimensional arrays
% NO check against misusage is done!

% Usage:   Rar:=makeRarray list dim1;  Rar:=makeRarray list(dim1,dim2);
%          val:=getRarray(Rar,ind1);   val:=getrarray(Rar,ind1,ind2);
%          putRarray(Rar,ind1,val);    PutRarray(Rar,in1,ind2,val);

% for two dimensional array access only !

macro procedure functionIndex2(u);
  begin scalar dims,ind1,ind2;
    dims := cadr u;
    ind1 := caddr u;
    ind2 := cadddr u;
    return         %%%% ((ind1 #- 1) #* cadr dims) #+ ind2;
      list ('iplus2,ind2,list('itimes2,list('cadr,dims),
			     list('iplus2,ind1,-1)));
  end;

macro procedure getRarray u;
   begin scalar arry,inds;
     arry := cadr(u);
     inds := cddr u;
     if length(inds) = 1 then
               return  list('getv,list('cdr,arry),car inds)
     else
               return list('getv,list('cdr,arry),
                    'functionIndex2 . list('car,arry) . inds);
   end;

symbolic procedure makeRarray dims;
   begin scalar u,n;
      n := for each i in dims product i;
      u := mkvect n;
      return dims . u;
   end;

macro procedure putRarray u;
   begin scalar arry,inds, val;
     arry := cadr(u);
     inds := cddr u;
     val := nth (u,length u);      % PSL: lastcar u;
     if length(inds) = 2 then
           return  list('putv,list('cdr,arry),car inds,val)
     else
           return  list('putv,list('cdr,arry), 'functionIndex2 .
               list('car,arry).car inds. cadr inds . NIL , val);
   end;

procedure HilbertZeroDimp(nrall, n, rarray);
begin integer i, k, count, vicount;
  count := 0;
  i := 0;
  while ((i:= i+1) <= nrall and count < n) do
  begin vicount := 1;
     for k := 1:n do
       if (getrarray(rarray,i,k) = 0) then vicount := vicount + 1;
     if vicount = n  then count := count + 1;
  end;
  return count = n;
end;
 
symbolic procedure groezerodim!?(F,n);
  begin scalar explist,A;
        integer r;
           %explist:= list( vev(lt(f1)),...,vev(lt(fr)) );
    explist:= for each fi in F collect vdpevlmon fi;
    r:= length(F);
    A := makerarray list(r,n);
    for i:=1 step 1 until r do
      for k:=1 step 1 until n do
        putRarray(A ,i,k, nth(nth(explist,i),k));
    return HilbertZeroDimp (r, n, A);
  end;

symbolic procedure gzerodimeval u;
   begin scalar vl;
      if cdr u then vl:=reval cadr u;
      return gzerodim1(reval car u,vl)
   end;

put('gzerodim!?,'psopfn,'gzerodimeval);

symbolic procedure gzerodim1(u,v);
   begin scalar vars,w,oldorder;
      w := for each j in getrlist u
              collect if eqexpr j then !*eqn2a j else j;
      if null w then rerror(groebnr2,21,
			    "Empty list in HilbertPolynomial");
      vars := groebnervars(w,v);
      oldorder := vdpinit vars;
      w := for each j in w collect f2vdp numr simp j;
      w := groezerodim!? (w,length vars);
      setkorder oldorder;
      return if w then newhilbi(u,'x,'list . v) else nil;
   end;

symbolic procedure gbtest(g);
   % test, if the given set of polynomials is a Groebner basis.
   % only fast to compute plausilbility test.
    begin scalar fredu,g1,r,s;
      g := vdplsort g;
        % make abbreviated version of G
      g1:= for each p in g collect
        << r := vdpred p;
           if vdpzero!? r then p else 
               vdpsum(vdpfmon(vdplbc p,vdpevlmon p), 
                      vdpfmon(vdplbc r,vdpevlmon r))
        >>;
      while g1 do
      <<for each p in cdr g1 do
         if not groebBuchcrit4t(vdpevlmon car g1,vdpevlmon p) then
        <<s := groebSpolynom(car g1,p);
          if not vdpzero!? s and 
                null groebSearchInList (vdpevlmon s,cddr g1)
	   then rerror(groebnr2,22,
	     "****** Not a GROEBNER basis wrt current ordering");
         >>;
        if groebSearchInList(vdpevlmon car g1,cdr g1) then
             fredu := T;
        g1 := cdr g1;
      >>;
      if fredu then
        <<terpri!* t;
        prin2t "WARNING:system is not a fully reduced GROEBNER basis";
        prin2t "with current term ordering";
        >>;
     end;
        
endmodule;

end;
