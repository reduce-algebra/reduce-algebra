module hilberts; % Hilbert series of a set of Monomials.

% Author: Joachim Hollman, Royal Institute for Technology,
%                          Stockholm, Sweden
%                          email:  <joachim@nada.kth.se>

comment
--------------------------------------------------------

A very brief "description" of the method used.


M=k[x,y,z]/(x^2*y,x*z^2,y^2)
 
                    x.
0 --> ker(x.) --> M --> M --> M/x --> 0
 
M/x = k[x,y,z]/(x^2*y,x*z^2,y^2,x) = k[x,y,z]/(x,y^2)
 
ker(x.) = ((x) + (x^2*y,x*z^2,y^2))/(x^2*y,x*z^2,y^2) =
 
        = (x,y^2)/(x^2*y,x*z^2,y^2)
 
 
Hilb(ker(x.)) = Hilb        - Hilb
                    (x,y^2)       (x^2*y,x*z^2,y^2)
 
        = 1/(1-t)^3 - Hilb                -
                          k[x,y,z]/(x,y^2)
 
          - (1/(1-t)^3 - Hilb
                          k[x,y,z]/(x^2*y,x*z^2,y^2)
 
        = Hilb -Hilb
              M     k[x,y,z]/(x,y^2)
 
If you only keep the numerator in Hilb = N(t)/(1-t)^3
                                      M
 
 
then you get
 
 
(1-t)N (t) = N (t)  - t (N (t) - N (t)      )
      I       I+(x)       I       Ann(x) + I
 
i.e.
 
 N (t) = N (t)  + t N (t)               (*)
  I       I+(x)      Ann(x) + I
 
 
Where
      I          = (x^2*y,x*z^2,y^2)
      I + (x)    = (x,y^2)
      I + Ann(x) = (x*y,z^2,y^2)
      N (t) is the numerator polynomial in Hilb
       I                                       k[x,y,z]/I
 
 
Equation (*) is what we use to compute the numerator polynomial, i.e.
we "divide out" one variable at a time until we reach a base case.
(One is not limited to single variables but I don't know of any good
strategy for selecting a monomial.)



Usage: hilb({monomial_1,...,monomial_n} [,variable])

;

fluid '(nvars!*);

% ************** MACROS ETC. **************

smacro procedure term(c,v,e);
    list('times,c,list('expt,v,e));

% -------------- safety check --------------

smacro procedure var!-p(m);
    and(m,atom(m),not(numberp(m)));

smacro procedure check!-expt(m);
    and(eqcar(m,'expt),var!-p(cadr(m)),numberp(caddr(m)));

smacro procedure check!-single!-var(m);
    if var!-p(m) then t 
    else check!-expt(m);

smacro procedure check!-mon(m);
    if check!-single!-var(m) then t
    else if eqcar(m,'times) then check!-times(cdr(m))
    else nil;

smacro procedure check!-args(monl,var);
    and(listp monl,eqcar(monl,'list),var!-p(var), check!-monl(monl));

symbolic procedure make!-vector (n,pat);
    begin scalar v;
    v:=mkvect n;
    for i:=1:n do putv(v,i,pat);
    return v;
    end;

% -------------- monomials --------------

smacro procedure alloc!-mon(n);
    make!-vector(n,0);
    
smacro procedure get!-nth!-exp(mon,n);
    getv(mon,n);

smacro procedure set!-nth!-exp(mon,n,d);
    putv(mon,n,d);

smacro procedure get!-tdeg(mon);
    getv(mon,0);
    
smacro procedure set!-tdeg(mon,d);
    putv(mon,0,d);

% -------------- ideals --------------

smacro procedure the!-empty!-ideal();
    list(nil,nil);

smacro procedure get!-next!-mon(ideal);
    <<x:=caadr ideal;
      if cdadr ideal then ideal:=list(car ideal,cdadr ideal)
      else ideal:=the!-empty!-ideal();
      x>>;

smacro procedure not!-empty!-ideal(ideal);
    cadr ideal;

smacro procedure first!-mon(ideal);
    caadr ideal;

smacro procedure append!-ideals(ideal1,ideal2);
    list(car ideal2,append(cadr ideal1,cadr ideal2));
    
symbolic procedure insert!-var(var,ideal);
% inserts variable var as last generator of ideal
begin
    scalar last;
    last:=list(make!-one!-var!-mon(var));
    return(list(last,append(cadr ideal,last)));
end;

symbolic procedure add!-to!-ideal(mon,ideal); 
% add mon as generator to the ideal
begin
    scalar last;
    last := list(mon);
    if ideal = the!-empty!-ideal() then
	rplaca(cdr(ideal),last) 
    else
        rplacd(car(ideal),last);
    rplaca(ideal,last); 
end;

% ************** END OF MACROS ETC. **************

% ************** INTERFACE TO ALGEBRAIC MODE **************

symbolic procedure HilbSerEval(u);
begin
    scalar l,monl,var;
    l:=length(u);
    if l < 1 or l > 2 then 
	rerror(groebnr2,17,
	       "Usage: hilb({monomial_1,...,monomial_n} [,variable])")
    else if l = 1 then
    <<
    	monl:= reval car u;
	var:= 'x;
    >>
    else
    <<
    	monl:=  reval car u;
	var:= reval cadr u;
    >>;
    monl :=  'list . for each aa in (cdr monl) collect reval aa;
    if not check!-args(monl,var) then
	 rerror(groebnr2,18,
		"Usage: hilb({monomial_1,...,monomial_n} [,variable])");
%    return(aeval 
%   	    	list('QUOTIENT,
%    	    	    coefflist2prefix(NPol(gltb2arrideal(monl)), var),
%                   list('EXPT,list('PLUS,1,list('TIMES,-1,var)),
%                        nvars!*)));
    return(aeval 
    	    	    coefflist2prefix(NPol(gltb2arrideal(monl)), var));
end;    

% define "hilb" to be the algebraic mode function
put('hilb,'psopfn,'HilbSerEval);

symbolic procedure check!-monl(monl);
begin
    scalar flag,tmp;
    flag:=t;
    monl:=gltb!-fix(monl);
    while monl and flag do
    <<
    	tmp:=car monl;
    	flag:=check!-mon(tmp);
	monl:=cdr monl;
    >>;
    return(flag);
end;

symbolic procedure check!-times(m);
begin
    scalar flag,tmp;
    flag:=t;
    while m and flag do
    <<
    	tmp:= car m;
    	flag:=check!-single!-var(tmp);
    	m:=cdr m;
    >>;
    return(flag);
end;

symbolic procedure coefflist2prefix(cl,var);
begin
    scalar i,poly;
    i:=0;
    for each c in cl do
    <<
    	poly:= cons(term(c,var,i),poly);
	i:=i+1;
    >>;
    return (cons('plus,poly));
end;

symbolic procedure indets(l);
% "indets"  returns a list containing all the 
% indeterminates of l.
% l is supposed to have a form similar to the variable
% GLTB in the Groebner basis package.
% (LIST (EXPT Z 2) (EXPT X 2) Y)
begin
    scalar varlist;
    for each m in l do
    	if m neq 'list then
	    if atom(m) then varlist:=union(list(m),varlist)
	    else if eqcar(m,'expt)
	     then varlist:=union(list(cadr(m)),varlist)
	    else varlist:=union(indets(cdr(m)),varlist);
    return(varlist);
end;	

symbolic procedure build!-assoc(l);
% Given a list of indeterminates (x1 x2 ...xn) we produce 
% an a-list of the form ((x1.1) (x2.2)... (xn.n))
begin
    scalar i;
    i:=0;
    return(for each var in l collect progn(i:=i+1,cons(var,i)));
end;    	

symbolic procedure mons(l);
% rewrite the leading monomials (i.e. GLTB).
% the result is a list of monomials of the form: 
% (variable . exponent) or ((variable1 . exponent1) ...
%     (variablen . exponentn))
%
% mons('(LIST (EXPT Z 2) (EXPT X 2) (TIMES Y (EXPT X 3))));
% (((Y . 1) (X . 3)) (X . 2) (Z . 2))
begin
    scalar monlist;
    for each m in l do
    	if m neq 'list then monlist:=
	    if atom(m) then cons(cons(m,1),monlist)
	    else if eqcar(m,'expt)
	     then cons(cons(cadr(m),caddr(m)),monlist)
	    else (for each x in cdr(m) collect mons!-aux(x)) . monlist;

    return(monlist);
end;	

symbolic procedure mons!-aux(m);
if atom(m) then cons(m,1) 
else if eqcar(m,'expt) then cons(cadr(m),caddr(m));

symbolic procedure lmon2arrmon(m);
% list-monomial to array-monomial
% a list-monomial has the form: (variable_number . exponent)
% or is a list with entries of this form.
% "variable_number" is the number associated with the variable,
% see build!-assoc()
begin
    scalar tdeg,mon;
    mon:=alloc!-mon(nvars!*);
    tdeg:=0;
    if listp m then 
    	for each varnodotexp in m do
	<<
	    set!-nth!-exp(mon,car varnodotexp, cdr varnodotexp);
    	    tdeg:=tdeg+cdr varnodotexp;
    	>>
    else
    <<
    	set!-nth!-exp(mon,car m, cdr m);
    	tdeg:=tdeg+cdr m;
    >>;
    set!-tdeg(mon,tdeg);
    return(mon);
end;    

symbolic procedure gltb!-fix(l);
% sometimes GLTB has the form (list (list...))
% instead of (list ...)
if and(listp cadr l,caadr(l) = 'list) then cadr l else l;
    	
symbolic procedure ge(m1,m2);
if get!-tdeg(m1) >= get!-tdeg(m2) then t else nil;

symbolic procedure get!-end!-ptr(l);
begin
    scalar ptr;
    while l do
    <<
    	ptr:=l;
    	l:=cdr l;
    >>;
    return(ptr);
end;

symbolic procedure gltb2arrideal(xgltb);
% Convert the monomial ideal given by GLTB (in list form)
% to a list of vectors where each vector represents a monomial.
begin
    scalar l;
    l:=indets(gltb!-fix(xgltb));
    nvars!* := length(l);
    l:= sublis(build!-assoc(l),mons(gltb!-fix(xgltb)));
    l:=for each m in l collect lmon2arrmon(m);
    l:=sort(l,'ge);
    return(list(get!-end!-ptr(l),l));
end;    

    	
% ************** END OF INTERFACE TO ALGEBRAIC MODE **************
    


%************** PROCEDURES **************

symbolic procedure npol(ideal);
% recursively computes the numerator of the Hilbert series
begin
    scalar v,si;
    v:=next!-var(ideal);
    if not v then return(base!-case!-pol(ideal));
    si:=split!-ideal(ideal,v);
    return(shift!-add(npol(car si),npol(cadr si)));
end;
   
symbolic procedure divides!-by!-var(var,mon); 
begin
    scalar div;
    if get!-nth!-exp(mon,var) = 0 then return(nil);
    div:=alloc!-mon(nvars!*);
    for i:=1 : nvars!* do set!-nth!-exp(div,i,get!-nth!-exp(mon,i));
    set!-nth!-exp(div,var,get!-nth!-exp(mon,var)-1);
    set!-tdeg(div,get!-tdeg(mon)-1);
    return(div);
end;
    
symbolic procedure divides(m1,m2); 
% does m1 divide m2?
% m1 and m2 are monomials
% result: either nil (when m1 does not divide m2) or m2/m1
begin
    scalar m,d,i;
    i:=1;
    m:=alloc!-mon(nvars!*);
    set!-tdeg(m,d:=get!-tdeg(m2)-get!-tdeg(m1));
    while d >= 0 and i <= nvars!* do
    <<
    	set!-nth!-exp(m,i,d:=get!-nth!-exp(m2,i) - get!-nth!-exp(m1,i));
    	i:= i+1;
    >>;

    if d < 0 then
    	return (nil)
    else
    	return(m);
end;

symbolic procedure shift!-add(p1,p2);
% p1+z*p2
% p1 and p2 are polynomials (nonempty coefficient lists)
begin
    scalar p,pptr;
    pptr:=p:=cons(car p1,nil);
    p1:=cdr p1;
    while p1 and p2 do
    <<
     	rplacd(pptr,cons(car p1 + car p2,nil));
    	p1:=cdr p1;
	p2:=cdr p2;
	pptr:=cdr pptr;
    >>;
    if p1 then
    	rplacd(pptr,p1)
    else
    	rplacd(pptr,p2);
    return(p);
end;
 
symbolic procedure rem!-mult(ipp1,ipp2); 
% the union of two ideals with redundancy of generators eliminated
begin
    scalar fmon,inew,isearch,primeflag,x;
       % fix; x is used in the macro...
    inew := the!-empty!-ideal();
    while not!-empty!-ideal(ipp1) and not!-empty!-ideal(ipp2) do
    begin
	if get!-tdeg(first!-mon(ipp2)) < get!-tdeg(first!-mon (ipp1))
	  then <<
	    fmon:=get!-next!-mon(ipp1);
            isearch:=ipp2;
        >>
	else
	<<
	    fmon:=get!-next!-mon(ipp2);
            isearch:=ipp1;
	>>;
	primeflag:=T;
	while primeflag and not!-empty!-ideal(isearch) do
	   if divides(get!-next!-mon(isearch),fmon) then primeflag:=nil;
	if primeflag then add!-to!-ideal(fmon,inew);
    end;
    if not!-empty!-ideal(ipp1) then return(append!-ideals(inew,ipp1))
    else return(append!-ideals(inew,ipp2)); 
end;

symbolic procedure next!-var(ideal); 
% extracts a variable in the ideal suitable for division
begin
    scalar x,m,var;
    repeat
    <<	m:=get!-next!-mon(ideal);
	var:=get!-var!-if!-not!-single(m);
    >> until var or ideal = the!-empty!-ideal();
    return(var); 
end;

symbolic procedure get!-var!-if!-not!-single(mon); 
% returns nil if the monomial is in a single variable, 
% otherwise the index of the second variable of the monomial
begin
    scalar i,foundvarflag,exp;
    i := 0;
    foundvarflag:=nil;
    while not foundvarflag do
    <<
	i:=i+1;
	exp:=get!-nth!-exp(mon,i);
	if exp > 0 then foundvarflag:=T;
    >>;
    foundvarflag:=nil;
    while i < nvars!* and not foundvarflag do
    <<
	i:=i+1;
	exp:=get!-nth!-exp(mon,i);
	if exp > 0 then foundvarflag:=T;
    >>;
    if foundvarflag then return(i)
    else return(nil);
end;

symbolic procedure make!-one!-var!-mon(vindex);
% returns the monomial consisting of the single variable vindex
begin
    scalar mon;
    mon := alloc!-mon(nvars!*);
    for i := 1:nvars!* do set!-nth!-exp(mon,i,0);
    set!-nth!-exp(mon,vindex,1);
    set!-tdeg(mon,1);
    return(mon);
end;

symbolic procedure split!-ideal(ideal,var);
% splits the ideal into two simpler ideals
begin
    scalar div,ideal1,ideal2,m,x;
    ideal1 := the!-empty!-ideal();
    ideal2 := the!-empty!-ideal();
    while not!-empty!-ideal(ideal) do
    <<
    	m:=get!-next!-mon(ideal);
    	if div:=divides!-by!-var(var,m) then
	    add!-to!-ideal(div,ideal2)
    	else
	    add!-to!-ideal(m,ideal1);
    >>;
    ideal2:=rem!-mult(ideal1,ideal2);
    ideal1:=insert!-var(var,ideal1);
    return(list(ideal1,ideal2));
end;

symbolic procedure base!-case!-pol(ideal);
% in the base case every monomial is of the form Xi^ei
% result : the numerator polynomial of the Hilbert series
%          i.e. (1-z^e1)*(1-z^e2)*...
begin
    scalar p,degsofar,e,tdeg;
    tdeg:=0;
    for each mon in cadr ideal do tdeg:=tdeg + get!-tdeg(mon);
    p:=make!-vector(tdeg,0);
    putv(p,0,1);
    degsofar:=0;

    for each mon in cadr ideal do
    <<
    	e:=get!-tdeg(mon);
	for j:= degsofar step -1 until 0 do
	    putv(p,j+e,getv(p,j+e)-getv(p,j));
        degsofar:=degsofar+e;
    >>;
    return(vector2list(p));
end;

symbolic procedure vector2list v;
   % Convert a vector v to a list.  No type checking is done.
   begin scalar u;
      for i:= upbv v step -1 until 0 do u := getv(v,i) . u;
      return u;
   end;

endmodule;

end;
