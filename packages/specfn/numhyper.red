
symbolic procedure evalnumlistp(lst);
   begin scalar res,  len;
%      if car lst neq 'list then rederr "parameter is not a list";
      lst := cdr lst;
      res :=t; len := length lst;
      while len > 0 and res do <<
	 res := evalnumberp car lst;
	 len := len - 1;
	 lst := cdr lst;
      >>;
      return res;
   end;

symbolic smacro procedure mkforms(lst);
   foreach num in  cdr lst collect reval num$

symbolic procedure poch1(n,lst);
   begin scalar prod;
      prod := 1;
      foreach num in lst do  prod := !:times(prod,!:plus(num,n));
      return prod;
   end;

symbolic smacro procedure !:rdabs(u);
   if !:minusp u then !:minus u else u$

symbolic procedure max_negint(lst);
   begin scalar m, num;
      m := 0;
      while pairp lst and !:minusp (num:=car lst) do <<
         if atom num then m := num;
         lst := cdr lst;
      >>;
      return m;
   end;

symbolic procedure remove_duplicates(l1,l2);
begin scalar nl1;
   nl1 := l1;
   foreach n in l1 do
      if member(n, l2) then <<
	 l2 := delete(n, l2);
      	 nl1 := delete(n, nl1);
      >>;
   return nl1 . list l2;
end;

symbolic procedure num_hypergeo(l1,l2,z);
   begin scalar tmp, ml1, ml2;
      z := reval z;
      if z = 0 then return 1;
      l1 := listsort(l1 . '(lessp));
      l2 := listsort(l2 . '(lessp));
      l1 := mkforms l1;
      l2 := mkforms l2;
      tmp :=  remove_duplicates(l1,l2);
      l1 := car tmp;
      l2 := cadr tmp;
      ml1 := max_negint l1;
      ml2 := max_negint l2;
      if (ml1 neq 0) and (ml2 neq 0) then
	 if ml2 > ml1 then
	    rerror(specfn, 3,
	       "Hypergeometric: zero in the denominator of terms in series.")
	 else % polynomial case
	    return simp n_hyper1(l1, l2, z, -ml1);

      ml1 := length l1; ml2 := length l2;
      if ml1=2 and ml2=1 then
	 return simp n_hyper21(car l1,cadr l1, car l2, z);
      
      if ml1 > ml2+1 then
	 rerror(specfn, 4,
	    "Hypergeometric: series diverges for all values of z")
      else if ml2 > ml1 then
	 % convergence may be slow for large |z|
	 return simp n_hyper1(l1,l2,z,0);
      
      % ml1 = ml2 +1
      return simp n_hyper2(l1,l2,z);
   end;

symbolic smacro procedure !:gamma2f(x)$
   numr simp {'gamma, x}$

symbolic procedure n_hyper21(a,b,c,z);
   begin scalar tmp, res, res1, arg, f0;
      tmp := !:difference( '(!:rd!: . 0.5) , !:rdabs z);
      if not !:minusp tmp then
	 % -1/2 <= z <= 1/2  -- Direct series summation
	 return n_hyper1({a,b},{c},z,0);
      tmp :=  !:plus(z, '(!:rd!:  . 0.5));
      if not !:minusp !:plus(z,1) and (!:minusp tmp or !:zerop tmp) then <<
	 % -1 <= z <=-1/2  -- DLMF 15.8.1
	 res := n_hyper1( {a, !:difference(c, b)}, {c},
   	                  !:quotient(z, !:difference(z, 1)),0);
 	 tmp := numr simpexpt {!:difference(1,z), !:minus a};
         return !:times(tmp,res);
      >>;
      if !:minusp z then <<
	 % z < -1   -- DLMF 15.8.2
	 tmp := !:difference(b,a);
	 if atom tmp then << % if difference is an integer (I hope)
	    prin2t("specfn 7 DLMF formula 15.8.2 not valid");
	    % fall back on direct series evaluation 
	    return  n_hyper2({a,b},{c},z);
	 >>;
	 f0 := !:quotient(rdpi!*(),rdsin!* (!:times(rdpi!*(),tmp)));
	 arg := !:recip z;
         res := n_hyper1({a, !:difference(!:plus(a, 1),c)},
	    {!:difference(!:plus(a,1), b)}, arg, 0);
	 tmp := !:times(!:gamma2f !:difference(c , a),
	               !:gamma2f !:difference(!:plus(a,1),b));
	 tmp := !:quotient(!:gamma2f c, !:times(!:gamma2f b, tmp));
	 res := !:times(res, tmp);
	 res := !:times(numr(simpexpt{!:minus arg, a}), res);
	 
         res1 := n_hyper1({b, !:difference(!:plus(b, 1),c)},
	                 {!:difference(!:plus(b,1), a)}, arg, 0);
	 tmp := !:times(!:gamma2f !:difference(c , b),
	    !:gamma2f !:difference(!:plus(b,1),a));
	 tmp := !:quotient(!:gamma2f c, !:times(!:gamma2f a, tmp));
	 res1 := !:times(res1, tmp);
	 res1 := !:minus !:times(numr(simpexpt{!:minus arg, b}), res1);
         return !:times(!:plus(res, res1), f0);
      >>;

        arg := !:difference(1, z);
        if not !:minusp  arg  or !:zerop arg then <<
	 % 1/2 < z <= 1  -- DLMF 15.8.4
	 tmp := !:difference(c,!:plus(a,b));
         if atom tmp then  << % if difference is an integer (I hope)
	    prin2t("specfn 8 DLMF formula 15.8,4 not valid");
	    % fall back on direct series evaluation 
	    return  n_hyper2({a,b},{c},z);
	 >>;
 	 f0 := !:quotient(rdpi!*(),rdsin!* (!:times(rdpi!*(),tmp)));
    	 res := n_hyper1({a, b}, {!:difference(!:plus(a, !:plus(b, 1)), c)},
	                  arg, 0);
	 tmp := !:times(!:gamma2f !:difference(c,a),
	    !:times(!:gamma2f !:difference(c,b),
	    !:gamma2f !:difference(!:plus(a,!:plus(b,1)), c)));
	 tmp:=!:quotient(!:gamma2f c,tmp);
	 res := !:times(res, tmp);
	 res1 := n_hyper1({!:difference(c,a), !:difference(c, b)},
 	                  {!:difference(!:plus(c,1), !:plus(a, b))},
   	                  arg, 0);
 	 tmp := numr simpexpt {arg, !:difference(c, !:plus(a,b))};
         res1:= !:minus !:times(tmp,res1);
	 tmp := !:times(!:times(!:gamma2f a, !:gamma2f b),
	                !:gamma2f !:difference(!:plus(c,1),!:plus(b,a)));
	 tmp:=!:quotient(!:gamma2f c,tmp);
	 res1 := !:times(res1,tmp);
         return !:times(f0, !:plus(res, res1));
      	>>;
	% fall back on direct series evaluation 
	return  n_hyper2({a,b},{c},z);
   end;


symbolic procedure n_hyper1(l1,l2,z,m);
   % z & all members of l1 & l2 are integers or tagged rounded domain elements
   % m>0 for the polynomial case  and zero otherwise
   begin scalar res, numer, denom, done, pow, fac, term, n, tol;
      numer :=1;  denom :=1; res :=1; done := nil;
      pow := 1; n := 0; fac := 1; term := 1; tol := reval (10.0^(-12));
      while (n<m and not done) or !:minusp(!:difference(tol, !:abs term)) do <<
     	 numer := !:times(numer, poch1(n, l1));
	 denom := !:times(denom, poch1(n, l2));
	 pow := !:times(pow, z);
	 n:=n+1;
	 fac := fac*n;
	 term :=  !:quotient(!:times(numer,pow),!:times(denom, fac));
	 res := !:plus(res,term);
	 if n=m then done :=t ;
      >>;
      return res;
   end;

symbolic procedure n_hyper2(l1,l2,z);
   % len(l1) = len(l2) +1
   begin scalar tmp, sl1, sl2, gamq;
      if !:minusp(!:difference(1,!:abs z)) then
	 rerror(specfn, 2,
	    "Hypergeometric: numerical evaluation not yet supported for |z|>1")
      else if !:minusp !:difference(!:abs z,1) then 
	 return  n_hyper1(l1,l2,z,0)
      else <<  % |z|=1
	 tmp := 0;
	 sl2 := foreach n in l2 do (tmp := !:plus(n, tmp));
	 tmp :=0;
	 sl1 := foreach n in l1 do (tmp := !:plus(n, tmp));
	 gamq := !:difference(sl2, sl1);
	 tmp := !:plus(gamq,1);
	 if !:minusp tmp or !:zerop tmp then
	    %  gamq <= -1
	    rerror(specfn, 5,
	       "Hypergeometric: numerical evaluation not yet supported for |z|=1")
	 else if not (!:minusp gamq or !:zerop gamq) % gamq > 0
	    or  %  -1 < gamq <= 0 and z = -1
	       (not !:minusp tmp and !:zerop !:plus(z,1)) then
	       return  n_hyper1(l1,l2,z,0)
	 else
	    rerror(specfn, 6,
	       "Hypergeometric: numerical evaluation not yet supported for z=1");
      >>;
   end;
;end;
   

