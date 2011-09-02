module exptf; % Functions for raising canonical forms to a power.

% Author: Anthony C. Hearn.

% Copyright (c) 1990 The RAND Corporation.  All rights reserved.

fluid '(!*exp);

symbolic procedure exptsq(u,n);
   begin scalar x;
      if n=1 then return u
       else if n=0
	 then return if null numr u then rerror(poly,4," 0**0 formed")
		      else 1 ./ 1
       else if null numr u then return u
       else if n<0 then return simpexpt list(mk!*sq u,n)
       else if null !*exp
	then return mksfpf(numr u,n) ./ mksfpf(denr u,n)
       else if kernp u then return mksq(mvar numr u,n)
       else if denr u=1 then return exptf(numr u,n) ./ 1
       else if domainp numr u
	then x := multsq(!:expt(numr u,n) ./ 1,1 ./ exptf(denr u,n))
       else <<x := u;
	      % Since U is in lowest terms, then so is U^N.
	      while (n := n-1)>0
		 do x := multf(numr u,numr x) ./ multf(denr u,denr x);
	      % We need canonsq for a:=1+x/2; let x^2=0; a^2;
	      x := canonsq x>>;
      if null cdr x then rerror(poly,101,"Zero divisor");
      return x
   end;

symbolic procedure exptf(u,n);
   if n < 0 then errach {"exptf",u,n}
    else if domainp u then !:expt(u,n)
    else if !*exp or kernlp u then exptf1(u,n)
    else mksfpf(u,n);

symbolic procedure exptf1(u,n);
   % Iterative multiplication seems to be faster than a binary sub-
   % division algorithm, probably because multiplying a small polynomial
   % by a large one is cheaper than multiplying two medium sized ones.
   if n=0 then 1
    else begin scalar x;
         x := u; while (n := n-1)>0 do x := multf(u,x); return x
         end;

symbolic procedure exptf2(u,n);
   % Binary version of EXPTF1, Used with EXP off, since expressions
   % formed in that case tend to be smaller than with EXP on.
   if n=0 then 1
    else begin scalar x; integer m;
         x := 1;
    a:   m := n;
         if m-2*(n := n/2) neq 0 then x := multf(u,x);
         if n=0 then return x;
         u := multf(u,u);
         go to a
      end;

endmodule;

end;
