module modsqrt; % SQRT n mod p, n integer, p prime.
% Sqrt mod p, p prime.


symbolic procedure modsqrt(a,p);
  <<if not fixp p or p<2 then typerr(p,"modulus for root computation");
    a:=general!-modular!-number a;
      % The break even point between primitive and general algorithm
      % has been evaluated on a 486. For machines without hardware
      % support for integer division, the limit might be set higher.
    if p<50 then modsqrt1(a,p) else modsqrt2(a,p)>>
       where current!-modulus=p;

symbolic procedure modsqrt1(a,p);
  % Primitve but fast algorithm for small p: check all possible values.
   begin integer i,w; scalar r;
     while null r and i<p do
      if w = a then r:=i 
        else
        << w:=w #+ i #+ i #+ 1;
           while w #> p do w:=w #- p;
           i:=i#+1;
         >>; 
    if null r then typerr({'sqrt,a},"expression mod p");
    return r;
   end;
    
symbolic procedure modsqrt2(a,p);
 % General algorithm for arbitrary prime p: 
 % H. Cohen: Computational Algebraic Number theory, 1.5.1
   begin integer a,b,m,r,y,e,p,q,tt,n,p!-1,x,z;
     x:=a; p!-1:=p-1;
     q:=p-1;  
     while evenp q do <<q:=q/2;e:=e+1>>;

 s1: repeat n:=random(p) until legendre!-symbol(n,p)=p!-1;
     z:=general!-modular!-expt(n,q); 

 s2: y:=z; r:=e; x:=general!-modular!-expt(a,(q-1)/2);
     b:=modp(a*x*x,p); x:=modp(a*x,p);

 s3: if modp(b,p)=1 then return x;
     m:=0;
     repeat m:=m+1 until general!-modular!-expt(b,expt(2,m)) = 1 or m=r;
     if m=r then typerr({'sqrt,a},"expression mod p");
 
 s4: tt:= general!-modular!-expt(y,expt(2,r-m-1)); 
     y:= general!-modular!-times(tt,tt); r:=m;
     x:=general!-modular!-times(x,tt); 
     b:=general!-modular!-times(b,y); 
     goto s3;
   end;


symbolic procedure legendre!-symbol(a,p);
   general!-modular!-expt(a,(p-1)/2);

symbolic procedure modsqrt!*(u); 
    %  print {"we got through:", u};
    !*modular2f modsqrt(cdr u,current!-modulus);

put('sqrt,'!:mod!:,'modsqrt!*);

endmodule;

end;
