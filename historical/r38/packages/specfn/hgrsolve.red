module hypergeomRsolve;

fluid '(!*tracefps);

algebraic procedure hypergeomRsolve (r,k,a0);

% solves the recurrence equation
%
%  a(k+1) = r(k) * a(k), a(0) = a0
 
  begin scalar Re,NNN,DDD,c,p,q,ak,sols,II;

   P := {}; Q := {};
   C := 1;

   Re := R * (k + 1);

   NNN := old_factorize num Re; DDD := old_factorize den re;
  
   foreach nn in NNN do
   if freeof (nn,k) then c := c * nn
	else if deg(nn,k) =1 then
	<< C:= c*coeffn(nn,k,1);
	    P:= append (p,list(coeffn(nn,k,0)/coeffn(nn,k,1)))>>
	else if deg(nn,k) =2 then
	<< c := c *  lcof(nn,k);
		sols := solve(nn,k);
		for each s in sols do
		   << for i:=1:first multiplicities!* do
			P:= (- rhs s) . p;
		      multiplicities!* := rest multiplicities!*;
		  >>
	>>
	else rederr(" hypergeomRsolve failed");

   foreach dd in DDD do
   if freeof (DD,k) then c := c / dd
        else if deg(DD,k) =1 then
        << C:= C/coeffn(dd,k,1);
            Q:= append (Q,list(coeffn(dd,k,0)/coeffn(dd,k,1)))>>
        else if deg(DD,k) =2 then
             << c := c /  lcof(dd,k);
                sols := solve(dd,k);
                for each s in sols do
                   << for i:=1:first multiplicities!* do
                        Q:= (- rhs s) . Q;
                      multiplicities!* := rest multiplicities!*;
                  >>;
             >>
        else rederr(" hypergeomRsolve failed");

   RSOLVE := infinite;
   for each s in P do if fixp s and s < 0 then RSOLVE := finite;
   if symbolic !*traceFPS then  write "RSOLVE  = ",RSOLVE;

   P := for each s in P product pochhammer(s,k);
   Q := for each s in Q product pochhammer(s,k);

   ak := a0 * (C^k) * P/(q * factorial k);

% Do additional simplification here??

   return ak;
end;

% A special ruleset for powerseries; nn has a special meaning here and 
% should be treated as integer

algebraic <<

hgspec_pochhammer :=

{ Pochhammer(~kk,~nn) => 1 when nn=0,
  Pochhammer(~kk,nn) => 0 when kk = 0,
  Pochhammer(~kk,nn) => (-1)^nn * factorial(-kk)/factorial(-kk-nn)
			when fixp(kk) and kk <=0,
  Pochhammer(~kk,nn) => factorial(kk+nn-1)/factorial(kk-1) when fixp kk,
  Pochhammer(~kk,~w*nn) =>
     factorial(kk+w*nn-1)/factorial(kk-1) when fixp kk}
>>;

endmodule;
end;


