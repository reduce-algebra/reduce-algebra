
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

symbolic  smacro procedure mkforms(lst);
   foreach num in  cdr lst collect numr simp num$

symbolic procedure poch1(n,lst);
   begin scalar prod;
      prod := 1;
      foreach num in lst do  prod := !:times(prod,!:plus(num,n));
      return prod;
   end;

symbolic procedure max_negint(lst);
   begin scalar m, num;
      m := 0;
      while pairp lst  do <<
	 num := car lst;
	 if atom num and num<0 then  % negative integer
	    if m=0 or m<num then m:=num;
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

symbolic procedure n_hyper1(l1,l2,z);
   % z & all members of l1 & l2 are integers or tagged rounded domain elements
   begin scalar res, numer, denom, done, pow, fac, term, n, prec, tol;
      numer :=1;  denom :=1; res :=1; done := nil;
      pow := 1; n := 0; fac := 1; term := 1;
      prec := precision(0);
      tol := reval (10.0^(-prec));
      while not done  do <<
     	 numer := !:times(numer, poch1(n, l1));
	 denom := !:times(denom, poch1(n, l2));
	 pow := !:times(pow, z);
	 n:=n+1;
	 fac := fac*n;
	 term :=  !:quotient(!:times(numer,pow),!:times(denom, fac));
	 res := !:plus(res,term);
	 if  !:minusp !:difference(!:abs !:quotient(term,res), tol) then
	    done :=t ;
      >>;
      return res;
   end;

symbolic procedure num_hypergeo(l1,l2,z);
   begin scalar tmp, ml1, ml2;
      z := numr simp z;
      if z = 0 then return 1;
      l1 := mkforms l1;
      l2 := mkforms l2;
      tmp :=  remove_duplicates(l1,l2);
      l1 := car tmp;
      l2 := cadr tmp;
      ml1 := max_negint l1;
      ml2 := max_negint l2;
      if ml2 neq 0  then
	 if  ml1 = 0 or ml2 > ml1 then
	    rerror(specfn, 3,
	       "Hypergeometric: zero in the denominator of terms in series.")
         else if ml1 > ml2 then
	    % polynomial case
	    return simp n_hyperpoly(l1, l2, z, -ml1);
      if ml1 neq 0 then
      	 % polynomial case
	 return simp n_hyperpoly(l1, l2, z, -ml1);

      ml1 := length l1; ml2 := length l2;
      if ml1=2 and ml2=1 then
	 return simp n_hyper21(car l1, cadr l1, car l2, z);
      
      if ml1 > ml2+1 then
	 rerror(specfn, 4,
	    "Hypergeometric: series diverges for all values of z")
      else if ml2 geq ml1 then
	 % convergence may be slow for large |z|
	 return simp n_hyper1(l1,l2,z);
      
      % ml1 = ml2 +1
      return simp n_hyper2(l1,l2,z);
   end;

symbolic smacro procedure !:abs(u)$
   numr simp {'abs, u}$

   
symbolic smacro procedure !:arg(u)$
   numr simp {'arg, u} where !*complex = t$

symbolic smacro procedure !:gamma2f(x)$
   numr simp {'gamma, x}$

symbolic smacro procedure !:sin2f(x)$
   numr simp {'sin, x}$

symbolic procedure minarg(z);
   % decide which variable change to use in DLMF 15.8.1-5
   begin scalar lst, pos, n, min;
      n := 0; pos := 0; min := !:abs z;
      lst := foreach ex in
	 {!:quotient(z, !:difference(z,1)), !:recip z,
	 !:recip !:difference(1,z), !:difference(1,z),
	 !:difference(1, !:recip z)} collect !:abs ex;
      foreach num in lst do <<
	 n := n+1;
	 if !:minusp !:difference(num, min) then <<
	    pos := n; min := num;
	 >>;
      >>;
      return {pos, min};
   end;

symbolic procedure n_hyper21(a,b,c,z);
   begin scalar tmp, pos;
      tmp := !:difference(c,!:plus(a,b));
      if z=1 then
	 if !:minusp !:minus !:repart tmp then
	    % Gauss's summation formula
	    return !:quotient(!:times(!:gamma2f(c), !:gamma2f(tmp)),
	       !:times(!:gamma2f !:difference(c,a),
	       !:gamma2f !:difference(c,b)))
	 else rerror(specfn, 10, "Series diverges");

      if !:zerop !:impart z then <<
      	 tmp := !:difference( '(!:rd!: . 0.5) , !:abs z);
      	 if not !:minusp tmp then
	    % -1/2 <= z <= 1/2  -- Direct series summation
	    return n_hyper1({a,b},{c},z);
      
      tmp :=  !:plus(z, '(!:rd!:  . 0.5));
      if not !:minusp !:plus(z,1) and (!:minusp tmp or !:zerop tmp) then
	 % -1 <= z <=-1/2  -- DLMF 15.8.1
	 return n_hyper1581(a,b,c,z);

      if !:minusp z then
	 % z < -1   -- DLMF 15.8.2
	 return n_hyper1582(a,b,c,z);

      tmp := !:difference(1, z);
      if not !:minusp  tmp  or !:zerop tmp then
	 % 1/2 < z <= 1  -- DLMF 15.8.4
	 return n_hyper1584(a,b,c,z);

      tmp :=!:difference(z,3);
      if not !:minusp tmp then
	 % z >= 3
	 %  -- DLMF 15.8.3   ??   seems to work
	 return n_hyper1583(a,b,c,z);
      
      if !:minusp !:difference(1,z) and !:minusp !:difference(z,3) then
	 % 1 < z < 3
	 %  -- DLMF 15.8.5   ?? seems to work
	 return n_hyper1585(a,b,c,z);
      >>;
      
       % z is now complex
      tmp := minarg z;
      pos := car tmp;
 
      if pos = 0 then  
	 return n_hyper1({a,b},{c},z);

      if pos = 1 and not
	 !:zerop !:difference(rdpi!*(), !:abs !:arg !:difference(1,z)) then
         return n_hyper1581(a,b,c,z);
 
      if pos = 2 and not
	  !:zerop !:difference(!:abs !:arg !:minus z, rdpi!*()) then 
	 return n_hyper1582(a,b,c,z);
	 
      if pos = 3 and not
 	   !:zerop !:difference(!:abs !:arg !:minus z, rdpi!*()) then 
    	 %  -- DLMF 15.8.3
	 return n_hyper1583(a,b,c,z);
	
       if pos = 4 and not
	  !:zerop !:difference(rdpi!*(),!:abs !:arg !:difference(1,z)) then
     	 %  -- DLMF 15.8.4
 	 return n_hyper1584(a,b,c,z);

       if pos = 5 and not
       	  !:zerop !:difference(rdpi!*(),!:abs !:arg !:difference(1,z)) then
    	 %  -- DLMF 15.8.5
	 return n_hyper1585(a,b,c,z);


       % fall back on direct series evaluation 
	return  n_hyper2({a,b},{c},z);
   end;


symbolic procedure n_hyperpoly(l1,l2,z,m);
   % z & all members of l1 & l2 are integers or tagged  domain elements
   % m>0 is the order of the polynomial.
   begin scalar res, numer, denom, pow, fac, term, n;
      numer :=1;  denom :=1; res :=1; 
      pow := 1; n := 0; fac := 1; term := 1;
      while n<m  do <<
     	 numer := !:times(numer, poch1(n, l1));
	 denom := !:times(denom, poch1(n, l2));
	 pow := !:times(pow, z);
	 n:=n+1;
	 fac := fac*n;
	 term :=  !:quotient(!:times(numer,pow),!:times(denom, fac));
	 res := !:plus(res,term);
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
	 return  n_hyper1(l1,l2,z)
      else <<  % |z|=1
	 tmp := 0;
	 sl2 := foreach n in l2 do (tmp := !:plus(n, tmp));
	 tmp :=0;
	 sl1 := foreach n in l1 do (tmp := !:plus(n, tmp));
	 gamq := !:repart !:difference(sl2, sl1);
	 tmp := !:plus(gamq,1);
	 if !:minusp tmp or !:zerop tmp then
	    %  gamq <= -1
	    rerror(specfn, 5,
	       "Hypergeometric: numerical evaluation not yet supported for |z|=1")
	 else if not (!:minusp gamq or !:zerop gamq) % gamq > 0
	    or  %  -1 < gamq <= 0 and z = -1
	       (not !:minusp tmp and not !:zerop  !:difference(z,1)) then
	       return  n_hyper1(l1,l2,z)
	 else
	    rerror(specfn, 6,
	       "Hypergeometric: numerical evaluation not yet supported for z=1");
      >>;
   end;

symbolic procedure n_hyper1581(a,b,c,z);
   % DLMF 15.8.1
   begin scalar tmp, res, arg;
      arg := !:quotient(z, !:difference(z, 1));
      res := n_hyper1( {a, !:difference(c, b)}, {c},arg);
      tmp := numr simpexpt {!:difference(1,z), !:minus a};
      return !:times(tmp,res);
   end;

symbolic procedure n_hyper1582(a,b,c,z);
   % DLMF 15.8.2
   begin scalar tmp, res, f0, res1, arg;
      tmp := !:difference(b,a);
      if atom tmp then
 	 % if difference is an integer
	 % DLMF formula 15.8.2 not valid"
	 % fall back on direct series evaluation
	 return  n_hyper2({a,b},{c},z);

      arg := !:recip z;
      f0 := !:quotient(rdpi!*(), !:sin2f(!:times(rdpi!*(),tmp)));
      res := n_hyper1({a, !:difference(!:plus(a, 1),c)},
	 {!:difference(!:plus(a,1), b)}, arg);
      tmp := !:times(!:gamma2f !:difference(c, a),
	 !:gamma2f !:difference(!:plus(a,1),b));
      tmp := !:quotient(!:gamma2f c, !:times(!:gamma2f b, tmp));
      res := !:times(res, tmp);
      res := !:times(numr(simpexpt{!:minus z, !:minus a}), res);

      res1 := n_hyper1({b, !:difference(!:plus(b, 1),c)},
	 {!:difference(!:plus(b,1), a)}, arg);
      tmp := !:times(!:gamma2f !:difference(c, b),
	 !:gamma2f !:difference(!:plus(b,1),a));
      tmp := !:quotient(!:gamma2f c, !:times(!:gamma2f a, tmp));
      res1 := !:times(res1, tmp);
      res1 := !:minus !:times(numr(simpexpt{!:minus z, !:minus b}), res1);
      return !:times(!:plus(res, res1), f0);
   end;

symbolic procedure n_hyper1583(a,b,c,z);
   % DLMF 15.8.3
   begin scalar tmp, arg, res, f0, res1;
	 tmp := !:difference(b,a);
	 if atom tmp then 
	    % if difference is an integer
	    % DLMF formula 15.8.3 not valid
	    % fall back on direct series evaluation 
	    return  n_hyper2({a,b},{c},z);

	 arg := !:difference(1, z);
         f0 := !:quotient(rdpi!*(), !:sin2f(!:times(rdpi!*(), tmp)));
    	 res := n_hyper1({a, !:difference(c,b)},
	    {!:difference(!:plus(a, 1), b)}, !:recip arg);
	 tmp := numr simpexpt {arg, !:minus a};
	 res := !:times(tmp,res);
 	 tmp := !:times(!:gamma2f !:difference(c,a),
	    !:times(!:gamma2f b, !:gamma2f(!:difference(!:plus(a,1),b))));
	 tmp := !:quotient(!:gamma2f c, tmp);
	 res := !:times(res, tmp);
	 
	 res1 := n_hyper1({b, !:difference(c, a)},
 	                  {!:difference(!:plus(b,1), a)}, !:recip arg);
 	 tmp := numr simpexpt {arg, !:minus b};
         res1:= !:minus !:times(tmp,res1);
	 tmp := !:times(!:times(!:gamma2f a, !:gamma2f !:difference(c,b)),
	                !:gamma2f !:difference(!:plus(b,1), a));
	 tmp := !:quotient(!:gamma2f c,tmp);
	 res1 := !:times(res1,tmp);
         return !:times(f0, !:plus(res, res1));
   end;

symbolic procedure n_hyper1584(a,b,c,z);
   % DLMF 15.8.4
   begin scalar tmp, res, f0, res1, arg;
      tmp := !:difference(c,!:plus(a,b));
      if atom tmp then 
	 % if difference is an integer
	 % DLMF formula 15.8,4 not valid
	 % fall back on direct series evaluation 
	 return  n_hyper2({a,b},{c},z);
      
      f0 := !:quotient(rdpi!*(), !:sin2f(!:times(rdpi!*(),tmp)));
      arg := !:difference(1,z);
    	 res := n_hyper1({a, b}, {!:difference(!:plus(a, !:plus(b, 1)), c)},
	                  arg);
 	 tmp := !:times(!:gamma2f !:difference(c,a),
	    !:times(!:gamma2f !:difference(c,b),
	    !:gamma2f !:difference(!:plus(a,!:plus(b,1)), c)));
	 tmp:=!:quotient(!:gamma2f c,tmp);
	 res := !:times(res, tmp);
	 
	 res1 := n_hyper1({!:difference(c,a), !:difference(c, b)},
 	                  {!:difference(!:plus(c,1), !:plus(a, b))},
   	                  arg);
 	 tmp := numr simpexpt {arg, !:difference(c, !:plus(a,b))};
         res1:= !:minus !:times(tmp,res1);
	 tmp := !:times(!:times(!:gamma2f a, !:gamma2f b),
	                !:gamma2f !:difference(!:plus(c,1),!:plus(b,a)));
	 tmp:=!:quotient(!:gamma2f c,tmp);
	 res1 := !:times(res1,tmp);
         return !:times(f0, !:plus(res, res1));
   end;

symbolic procedure n_hyper1585(a,b,c,z);
   % DLMF 15.8.5
   begin scalar tmp, res, f0, res1, arg;
	 tmp := !:difference(c,!:plus(a,b));
	 if atom tmp then 
	    % if difference is an integer
	    % DLMF formula 15.8.5 not valid
	    % fall back on direct series evaluation 
	    return  n_hyper2({a,b},{c},z);
      
	 f0 := !:quotient(rdpi!*(),
	            !:sin2f(!:times(rdpi!*(),!:difference(c,!:plus(a,b)))));
	 arg :=!:difference(1,!:recip z);
    	 res := n_hyper1({a, !:difference(!:plus(a,1),c)},
	    {!:difference(!:plus(a, !:plus(b, 1)), c)}, arg);
	 tmp := numr simpexpt {z, !:minus a};
	 res := !:quotient(res, tmp);
 	 tmp := !:times(!:gamma2f !:difference(c,a),
	    !:times(!:gamma2f !:difference(c,b),
	    !:gamma2f !:difference(!:plus(a,!:plus(b,1)), c)));
	 tmp:=!:quotient(!:gamma2f c,tmp);
	 res := !:times(res, tmp);
	 
	 res1 := n_hyper1({!:difference(c,a), !:difference(1,a)},
 	                  {!:difference(!:plus(c,1), !:plus(a, b))}, arg);
 	 tmp := numr simpexpt
	    {!:difference(1, z), !:difference(c, !:plus(a,b))};
	 tmp := !:times(tmp, numr simpexpt {z, !:difference(a, c)});
         res1:= !:minus !:times(tmp,res1);
	 tmp := !:times(!:times(!:gamma2f a, !:gamma2f b),
	                !:gamma2f !:difference(!:plus(c,1),!:plus(b,a)));
	 tmp:=!:quotient(!:gamma2f c,tmp);
	 res1 := !:times(res1,tmp);
         return !:times(f0, !:plus(res, res1));
   end;

algebraic procedure discont(a,b,c,z);
   % calculates the discontinuity of 2F1 across the cut from 1 .. infty
   % see DLMF 15.2.3.  z must be real and >1
   begin scalar tmp, tmp1;
      tmp := hypergeometric({c-a, c-b},{c-a-b+1},1-z);
      tmp1 :=2*pi*i*gamma(c)*(z-1)^(c-a-b)/(gamma(a)*gamma(b)*gamma(c-a-b+1));
      return tmp1*tmp;
   end;

;end;
   

