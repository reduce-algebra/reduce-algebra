module ratalgo;

% rational algorithm for FPS package

algebraic procedure Complexapart(f,x);

    begin scalar !*factor,!*complex;
	on factor,complex;
        x := pf(f,x);
        off factor,complex;
	return x;
   end;

algebraic procedure ratalgo(p,x);
     begin scalar afp,tt,S,ak,d,c,j,ss;
     afp := Complexapart(p,x);

     S:= 0; ak := 0;

     if symbolic !*traceFPS then write " Rational Algorithm applied";

     foreach tt in afp do
	<< if freeof(tt,x) then S := S + tt else
	   << 
	   d := 1/tt;
	   if not polynomq(d,x) then <<
                if symbolic !*traceFPS then write
			 " Rational Algorithm  failed";
                S := -1 >>;
	  if not (S = -1) then 
	  <<
           d := d/lcof(d,x); c := d * tt;
	   J := deg(d,x);
           d := expt(d,1/j);
           if not polynomq(d,x) then <<
		if symbolic !*traceFPS then write
			" Rational Algorithm  failed";
		afp := {}; d :=12;
		S := -1 >>;
	   if d = x then S := S + c/d^j  else
		<<
		ss := lcof(d,x);
		d := d /ss; c := c / ss;
		xk := x -d; c:= c*(-1)^j/xk ^j;
		ak  := ak +
		   c*simplify_factorial(factorial(j + k -1)/
			factorial(k)/factorial(j-1))/xk^k; 
	>> >> >> >>;
        if S = -1 then return (-1);
	return S := S + infsum(ak*x^k,k,0,infinity)
    end;
	   
symbolic procedure fastpart(x,n);
	reval nth( x,n +1);

flag ('(fastpart fastlength),'opfn);

symbolic procedure fastlength(x);
        length (x) -1;

symbolic procedure auxcopy(u);
   if pairp u then cons (auxcopy car u, auxcopy cdr u) else u;

% for XR

if getd 'print_format then
	print_format('(pochhammer u v),'(!( u !) !_ v));

endmodule;

end;



