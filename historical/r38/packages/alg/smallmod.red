module smallmod; % Small integer modular arithmetic used in factorizer.

% Author: Arthur C. Norman.

% Note: when balanced_mod is on, the results here are not always in 
% range. *modular2f is used to correct this.

fluid '(!*balanced_mod current!-modulus modulus!/2);

global '(largest!-small!-modulus);

symbolic procedure set!-modulus p; set!-general!-modulus p;

symbolic procedure set!-small!-modulus p;
  begin
    scalar previous!-modulus;
    if p>largest!-small!-modulus
      then rerror(alg,9,list("Overlarge modulus",p,"being used"));
    previous!-modulus:=current!-modulus;
    current!-modulus:=p;
    modulus!/2 := p/2;
    return previous!-modulus
  end;


smacro procedure modular!-plus(a,b);
  begin scalar result;
     result:=a #+ b;
     if not(result #< current!-modulus) then
            result:=result #- current!-modulus;
     return result
  end;

smacro procedure modular!-difference(a,b);
  begin scalar result;
     result:=a #- b;
     if iminusp result then result:=result #+ current!-modulus;
     return result
  end;

symbolic procedure modular!-number a;
  begin
     if not atom a then typerr(a,"integer in modular-number");
     a:=remainder(a,current!-modulus);
     if iminusp a then a:=a #+ current!-modulus;
     return a
  end;

smacro procedure modular!-times(a,b);
    remainder(a*b,current!-modulus);

symbolic procedure modular!-reciprocal a;
   if !*balanced_mod and a<0
     then reciprocal!-by!-gcd(current!-modulus,
			      a #+ current!-modulus,0,1)
    else reciprocal!-by!-gcd(current!-modulus,a,0,1);

symbolic procedure reciprocal!-by!-gcd(a,b,x,y);
%On input A and B should be coprime. This routine then
%finds X and Y such that A*X+B*Y=1, and returns the value Y
%on input A > B;
   if b=0 then rerror(alg,10,"Invalid modular division")
   else if b=1 then if iminusp y then y #+ current!-modulus else y
   else begin scalar w;
%N.B. Invalid modular division is either:
% a)  attempt to divide by zero directly
% b)  modulus is not prime, and input is not
%     coprime with it;
     w:= a #/ b; %Truncated integer division;
     return reciprocal!-by!-gcd(b,a #- b #* w,
                                y,x #- y #* w)
   end;

smacro procedure modular!-quotient(a,b);
    modular!-times(a,modular!-reciprocal b);


smacro procedure modular!-minus a;
    if a=0 then a else current!-modulus #- a;

symbolic procedure modular!-expt(a,n);
   % Computes a**n modulo current-modulus.  Uses Fermat's Little
   % Theorem where appropriate for a prime modulus.
    if n=0 then 1
    else if n=1 then a
    else if n>=current!-modulus-1 and primep current!-modulus
     then modular!-expt(a,remainder(n,current!-modulus-1))
    else begin scalar x;
     x:=modular!-expt(a,n/2);
     x:=modular!-times(x,x);
     if not(remainder(n,2)=0) then x:=modular!-times(x,a);
     return x
    end;

symbolic set!-modulus(1) ; % forces everything into a standard state.

endmodule;

end;
