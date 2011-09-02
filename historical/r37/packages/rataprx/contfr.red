module contfr;  % Simultaneous approximation of a real number by a
		% continued fraction and a rational number with optional
		% user controlled precision (upper bound for numerator).

% Author: Herbert Melenk.

symbolic procedure contfract2 (u,b1);
 % compute continued fraction until either numerator exceeds b1
 % or approximation has reached system precision.
  begin scalar b0,l,a,b,g,gg,ggg,h,hh,hhh;
    b:= u; g:=0; gg:=1; h:=1; hh:=0;
    if null b1 then b0:= absf !:times(b,!:expt(10,- precision 0));
  loop:
    a:=rd!-fix b;
    ggg:=a*gg + g;
    hhh:=a*hh + h;
    if b1 and abs hhh > b1 then goto ret;
    g := gg; gg:=ggg; h:=hh; hh:=hhh;
    l:=a.l;
    b:=!:difference(b,a);
    if null b  
      or !:lessp(absf !:difference(!:quotient(i2rd!* gg,i2rd!* hh),u),
		 b0)
	 then go to ret;
    b:=!:quotient(1,b);
    go to loop;
  ret:
    return  (gg . hh) . reversip l
  end;

symbolic procedure !:lessp(u,v); !:minusp !:difference(u,v);

symbolic procedure rd!-fix u;
   if atom cdr u then fix cdr u else ashift(cadr u,cddr u);

symbolic procedure contfract1(u,b);
  begin scalar oldmode,v;
   if eqcar(v:=u,'!:rd!:) then goto c;
   oldmode := get(dmode!*,'dname).!*rounded;
   if car oldmode then setdmode(car oldmode,nil);
   setdmode('rounded,t); !*rounded := t;
   v:=reval u;
   setdmode('rounded,nil);
   if car oldmode then setdmode(car oldmode,t);
   !*rounded:=cdr oldmode;
   if eqcar(v,'minus) and (numberp cadr v or eqcar(cadr v,'!:rd!:))
     then v:=!:minus cadr v;
   if fixp v then return (v . 1).{v};
   if not eqcar(v,'!:rd!:) then
     typerr(u,"continued fraction argument");
 c:
   return contfract2(v,b);
  end;
   
symbolic procedure cont!-fract u;
   <<u:=contfract1(car u,if cdr u then ieval cadr u);
     {'list,{'quotient,caar u,cdar u},'list . cdr u}>>;

put('continued_fraction,'psopfn,'cont!-fract);

endmodule;

end;
