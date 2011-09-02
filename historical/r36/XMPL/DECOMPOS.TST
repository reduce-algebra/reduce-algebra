% Test for the univariate and multivariate polynomial decomposition.

% Herbert Melenk, ZIB Berlin, 1990.

procedure testdecompose u;
   begin scalar r,p,val,nextvar;
       write "decomposition of ",u;
       r := decompose u;
       if length r = 1 then rederr "decomposition failed";
       write " leads to ",r;
         % test if the result is algebraically correct.
       r := reverse r;
       nextvar := lhs first r; val := rhs first r;
       r := rest r;
       while not(r={}) do
       << p := first r; r := rest r;
          if 'equal = part(p,0) then
          <<val := sub(nextvar=val,rhs p); nextvar := lhs p>>
              else
            val := sub(nextvar=val,p);     
       >>;
       if val = u then write "     O.K.  "
          else
         <<write "**** reconstructed polynomial: ";
           write val; 
           rederr "reconstruction leads to different polynomial";
         >>;
    end;


    % univariate decompositions
testdecompose(x**4+x**2+1); 
testdecompose(x**6+9x**5+52x**4+177x**3+435x**2+630x+593); 
testdecompose(x**6+6x**4+x**3+9x**2+3x-5); 
testdecompose(x**8-88*x**7+2924*x**6-43912*x**5+263431*x**4-218900*x**3+ 
           65690*x**2-7700*x+234);

    % multivariate cases
testdecompose(u**2+v**2+2u*v+1); 
testdecompose(x**4+2x**3*y + 3x**2*y**2 + 2x*y**3 + y**4 + 2x**2*y  
         +2x*y**2 + 2y**3 + 5 x**2 + 5*x*y + 6*y**2 + 5y + 9);
testdecompose  sub(u=(2 x**2 + 17 x+y + y**3),u**2+2 u + 1);
testdecompose  sub(u=(2 x**2 *y + 17 x+y + y**3),u**2+2 u + 1);

    % some cases which require a special (internal) mapping
testdecompose  ( (x + y)**2);
testdecompose ((x + y**2)**2);
testdecompose  ( (x**2 + y)**2);
testdecompose  ( (u + v)**2 +10 );

    % the decomposition is not unique and might generate quite
    % different images:
testdecompose  ( (u + v + 10)**2 -100 );

    % some special (difficult) cases
testdecompose (X**4 + 88*X**3*Y + 2904*X**2*Y**2 - 10*X**2 
           + 42592*X*Y**3 - 440*X*Y + 234256*Y**4 - 4840*Y**2);

    % a polynomial with complex coefficients
on complex;
testdecompose(X**4 + (88*I)*X**3*Y - 2904*X**2*Y**2 - 10*X**2 - 
              (42592*I)*X*Y**3 - (440*I)*X*Y + 234256*Y**4 + 4840*Y**2);
off complex;


    % Examples given by J. Gutierrez and J.M. Olazabal.

 f1:=x**6-2x**5+x**4-3x**3+3x**2+5$
 testdecompose(f1);

 f2:=x**32-1$
 testdecompose(f2);

 f3:=x**4-(2/3)*x**3-(26/9)*x**2+x+3$
 testdecompose(f3);

 f4:=sub(x=x**4-x**3-2x+1,x**3-x**2-1)$
 testdecompose(f4);

 f5:=sub(x=f4,x**5-5)$
 testdecompose(f5);

 clear f1,f2,f3,f4,f5;

end;
