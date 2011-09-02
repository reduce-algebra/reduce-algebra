
% Floating point tests.            A C Norman and Codemist Ltd. 1994

%
% The code here is for use by people who have read and
% enjoyed "Software manual for the elementary functions" by
% Cody and Waite (Prentice Hall, 1980).  It attempts to
% measure the accuracy of some of the elementary functions
% in the implementation of REDUCE that it is run on.  Good
% implementations should show maximum errors of only a few
% units in the last place, and errors reasonably evenly
% distributed between +ve and -ve.  Various special cases are
% tested too.  The layout for presenting results from this code
% is somewhat crude at present.
%

% call fptest() to perform complete set of tests;

symbolic;

on comp;

fluid '(ibeta it irnd ngrd machep negep iexp minexp 
        maxexp eps epsneg xmin xmax iy one zero x);

symbolic procedure fptest();
   begin
      scalar ibeta,it,irnd,ngrd,machep,negep,iexp,minexp,
             maxexp,eps,epsneg,xmin,xmax;
      iy:=100001;  % seed for random number gereration;
      machar();
% only expt is left after this lot. hurrah;
      test!-arcsin();
      test!-atan();
      test!-tan();
      test!-sin();
      test!-sqrt();
      test!-log();
      test!-exp();
      princ "fp tests over";
      terpri()
   end;


symbolic procedure machar();
   begin
      scalar one,zero,a,b,beta,betam1,betain,i,k,x,y,z,mx;
      one:=float 1;
      zero:=float 0;
      a:=one;
      repeat a:=a+a until not (((a+one)-a)-one = zero);
      b:=one;
      repeat b:=b+b until not ((a+b)-a = zero);
      ibeta:=fix((a+b)-a);
      princ list("ibeta = ",ibeta); terpri();
      beta:=float ibeta;
      it:=0;
      b:=one;
      repeat << it:=it+1; b:=b*beta >> until not (((b+one)-b)-one = zero);
      irnd:=0;
      betam1:=beta-one;
      if ((a+betam1)-a) neq zero then irnd:=1;
      princ list("it=",it,"irnd=",irnd); terpri();
      negep:=it+3;
      betain:=one/beta;
      a:=one;
      for i:=1:negep do a:=a*betain;
      b:=a;
      while ((one-a)-one) = zero do << a:=a*beta; negep:=negep-1 >>;
      negep:=-negep;
      epsneg:=a;
      if not ((ibeta=2) or (irnd=0)) then <<
         a := (a*(one+a))/(one+one);
         if ((one-a)-one) neq zero then epsneg:=a >>;
      princ list("negep=",negep,"epsneg=",epsneg); terpri();
      machep:=-it-3;
      a:=b;
      while ((one+a)-one) = zero do <<
         a:=a*beta;
         machep:=machep+1 >>;
      eps:=a;
      if not (ibeta=2 or irnd=0) then <<
         a:=(a*(one+a))/(one+one);
         if (one+a)-one neq zero then eps:=a >>;
      princ list("machep=",machep,"eps=",eps); terpri();
      ngrd:=0;
      if irnd=0 and ((one+eps)*one-one) neq zero then ngrd:=1;
      princ list("ngrd=",ngrd); terpri();
      i:=0;
      k:=1;
      z:=betain;
l400: y:=z;
      z:=y*y;
      a:=z*one;
      if (a+a=zero) or (abs z >= y) then go to l410;
      i:=i+1;
      k:=k+k;
      goto l400;
l410: % assume it is not a decimal machine! ;
      iexp:=i+1;
      mx:=k+k;
l450: xmin:=y;
      y:=y*betain;
      a:=y*one;
      if (a+a=zero) or (abs y >= xmin) or
            ((a * (one + eps)) = a) then goto l460;
      k:=k+1;
      goto l450;
l460: minexp:=-k;
      princ list("iexp=",iexp,"minexp=",minexp,"xmin=",xmin); terpri();
      if not (mx>k+k-3 or ibeta=10) then <<
         mx:=mx+mx;
         iexp:=iexp+1 >>;
      maxexp:=mx+minexp;
      maxexp:=maxexp-2;  % allow for 2 reserved exponents in ieee format;
      i:=maxexp+minexp;
      if (ibeta=2) and (i=0) then maxexp:=maxexp-1;
      if i>20 then maxexp:=maxexp-1;
      if a neq y then maxexp:=maxexp-2;
      princ list("maxexp=",maxexp); terpri();
      xmax:=one-epsneg;
      if xmax*one neq xmax then xmax:=one-beta*epsneg;
      xmax:=xmax/(beta*beta*beta*xmin);
      i:=maxexp+minexp+3;
      if i>0 then <<
         for j:=1:i do
            if ibeta=2 then xmax:=xmax+xmax else xmax:=xmax*beta >>;
      princ list("xmax=",xmax); terpri();
      princ "end of machar"; terpri()
   end;

symbolic procedure rnd();
% random floating point number in range 0 to 1;
   begin
      iy:=iy*125;
      iy:=remainder(iy,2796203);
      return float(iy)/2796203.0
   end;

symbolic procedure randl(x);
   exp(x*rnd());

symbolic procedure tab_to_column n;
  while posn() < n do princ " ";

symbolic procedure heading(name,trials,from,to);
 << terpri();
    princ name;
    tab_to_column 20; princ trials; princ " trials";
    tab_to_column 40; princ "from "; princ from;
    princ " to "; princ to; terpri()
 >>;

symbolic procedure errsigns(k1,k2,k3);
 << princ "+ve: "; princ k1;
    tab_to_column 20; princ "zero: "; princ k2;
    tab_to_column 40; princ "-ve: "; princ k3; terpri()
 >>;

symbolic procedure maxrel(w,x1,d);
 << princ "mre was "; princ w;
    princ " at "; princ x1;
    princ "     lost "; princ d; princ " digits"; terpri();
 >>;

symbolic procedure rmserr(w,d);
 << princ "rms was "; princ w;
    princ "     lost "; princ d; princ " digits"; terpri()
 >>;
   
symbolic procedure specials(a,b,c);
 << princ a;
    princ b;
    princ "  ";
    princ c; terpri()
 >>;

symbolic procedure errortest u;
  begin
    scalar w;
    w := errorset(u, t, t);
    if atom w then <<
      princ "Evaluation of "; prin1 u; princ " failed"; terpri() >>
    else <<
      prin1 u; princ " = "; print car w >>;
  end;

symbolic procedure test!-arcsin();
   begin
      scalar a,ait,albeta,b,beta,betap,c1,c2,del,half,pi,r6,r7,one,xsq,two,l,
             k,em,ob32,w,x,xl,xn,x1,y,z,zero,zz,i,i1,j,k1,k2,k3,n,expon,zsum,
             ysq,xm,s;
      beta:=float ibeta;
      albeta:=log beta;
      ait:=float it;
      zero:=float 0;
      one:=float 1;
      half:=0.5;
      two:=float 2;
      k:=fix(log10(beta**it))+1;
      c1:=201.0/128.0;
      c2:=4.8382679489661923132e-4;
      a:=-0.125;
      b:=-a;
      n:=2000;
      xn:=float n;
      i1:=0;
      l:=-1;
      for j:=1:5 do <<
         princ list("start of test ",j," of arcsin/arccos"); terpri();
         k1:=0;
         k3:=0;
         l:=-l;
         x1:=zero;
         r6:=zero;
         r7:=zero;
         del:=(b-a)/xn;
         xl:=a;
         for i:=1:n do <<
            x:=del*rnd()+xl;
            if j>2 then <<
               ysq := half - half*abs x;
               x:=(half-(ysq+ysq)) + half;
               if j=5 then x:=-x;
               y:=sqrt(ysq);
               y:=y+y >>
            else << y:=x; ysq:=y*y >>;
            zsum:=zero;
            xm:=float(k+k+1);
            if l>0 then z:=asin x else z:=acos x;
            for m:=1:k do <<
               zsum:=ysq*(zsum+1.0/xm);
               xm:=xm-2.0;
               zsum:=zsum*(xm/(xm+1.0)) >>;
            zsum:=zsum*y;
            if j=1 or j=4 then <<
               zz:=y+zsum;
               zsum:=(y-zz)+zsum;
               if irnd neq 1 then zz:=zz + (zsum+zsum) >>
            else <<
               s:=c1+c2;
               zsum:=((c1-s) + c2) - zsum;
               zz:=s+zsum;
               zsum:=((s-zz)+zsum)-y;
               s:=zz;
               zz:=s+zsum;
               zsum:=(s-zz)+zsum;
               if irnd neq 1 then zz:=zz+(zsum+zsum)>>;
            w:=1.0;
            if z neq zero then w:=(z-zz)/z;
            if w>zero then k1:=k1+1;
            if w<zero then k3:=k3+1;
            w:=abs w;
            if w>r6 then << r6:=w; x1:=x >>;
            r7:=r7+w*w;
            xl:=xl+del >>;
         k2:=n-k1-k3;
         r7:=sqrt(r7/xn);
         heading("arcsin/arccos",n,a,b);
         errsigns(k1,k2,k3);
         w:=-999.0;
         if r6 neq zero then w:=log abs r6/albeta;
         maxrel(w,x1,max(ait+w,zero));
         w:=-999.0;
         if r7 neq zero then w:=log abs r7/albeta;
         rmserr(w,max(ait+w,zero));
         if j=2 then << a:=0.75; b:=1.0 >>
         else if j=4 then << b:=-a; a:=-1.0; c1:=c1+c1; c2:=c2+c2; l:=-l >> >>;
      for i:=1:5 do <<
         x:=rnd()*a;
         z:=asin x + asin(-x);
         specials("asin(x)+asin(-x)  ",x,z) >>;
      betap:=beta**it;
      x:=rnd()/betap;
      for i:=1:5 do <<
         z:=x-asin x;
         specials("small args to asin ",x,z);
         x := x/beta >>;
      expon:=float minexp * 0.75;
      x:=beta**expon;
      y:=asin x;
      specials("tiny arg ",x,y);
      x:=1.2;
      errortest list('asin, x);
      princ "end of test on arcsin/arccos"; terpri()
   end;


symbolic procedure test!-atan();
   begin
      scalar a,ait,albeta,b,beta,betap,c1,c2,del,half,pi,r6,r7,one,xsq,two,
             em,ob32,w,x,xl,xn,x1,y,z,zero,zz,i,i1,j,k1,k2,k3,n,expon,zsum;
      beta:=float ibeta;
      albeta:=log beta;
      ait:=float it;
      zero:=float 0;
      one:=float 1;
      half:=0.5;
      two:=float 2;
      a:=-0.0625;
      b:=-a;
      ob32:=b*half;
      n:=2000;
      xn:=float n;
      i1:=0;
      for j:=1:4 do <<
         princ list("start of test ",j," of atan"); terpri();
         k1:=0;
         k3:=0;
         x1:=zero;
         r6:=zero;
         r7:=zero;
         del:=(b-a)/xn;
         xl:=a;
         for i:=1:n do <<
            x:=del*rnd()+xl;
            if j=2 then x:=((one+x*a)-one)*16.0;
            z:=atan x;
            if j=1 then <<
               xsq:=x*x;
               em:=17.0;
               zsum:=xsq/em;
               for i1:=1:7 do <<
                 em := em-two;
                 zsum:=(one/em - zsum)*xsq >>;
               zsum:=-x*zsum;
               zz:=x+zsum;
               zsum:=(x-zz)+zsum;
               if irnd=0 then zz:=zz+(zsum+zsum) >>
            else if j=2 then <<
               y:=x-0.0625;
               y:=y/(one+x*a);
               zz:=(atan y - 8.1190004042651526021/100000.0)+ob32;
               zz:=zz+ob32 >>
            else <<
               z:=z+z;
               y:=x/((half+x*half)*((half-x)+half));
               zz := atan y >>;
            w:=1.0;
            if z neq zero then w:=(z-zz)/z;
            if w>zero then k1:=k1+1;
            if w<zero then k3:=k3+1;
            w:=abs w;
            if w>r6 then << r6:=w; x1:=x >>;
            r7:=r7+w*w;
            xl:=xl+del >>;
         k2:=n-k1-k3;
         r7:=sqrt(r7/xn);
         heading("atan",n,a,b);
         errsigns(k1,k2,k3);
         w:=-999.0;
         if r6 neq zero then w:=log abs r6/albeta;
         maxrel(w,x1,max(ait+w,zero));
         w:=-999.0;
         if r7 neq zero then w:=log abs r7/albeta;
         rmserr(w,max(ait+w,zero));
         a:=b;
         if j=1 then b:=two-sqrt(3.0);
         if j=2 then b:=sqrt(two)-one;
         if j=3 then b:=one >>;
      a:=5.0;
      for i:=1:5 do <<
         x:=rnd()*a;
         z:=atan x + atan(-x);
         specials("atan(x)+atan(-x)  ",x,z) >>;
      betap:=beta**it;
      x:=rnd()/betap;
      for i:=1:5 do <<
         z:=x-atan x;
         specials("small args to atan ",x,z);
         x := x/beta >>;
      a:=-two;
      b:=4.0;
      for i:=1:5 do <<
         x:=rnd()*b+a;
         y:=rnd();
         w:=-y;
         z:=atan(x/y) - atan2(x,y);
         zz:=atan(x/w) - atan2(x,w);
         princ list("atan vs atan2  ",x,y,w,"  ",z,zz); terpri() >>;
      expon:=float minexp * 0.75;
      x:=beta**expon;
      y:=atan x;
      specials("tiny arg ",x,y);
      specials("xmax     ",xmax,atan xmax);
      specials("atan(xmax,xmin) ",xmax,atan2(xmax,xmin));
      princ "end of test on atan"; terpri();
   end;


symbolic procedure test!-sqrt();
   begin
      scalar beta,sqbeta,albeta,ait,one,zero,n,xn,c,k1,k2,k3,
             x1,r6,r7,a,b,x,y,z,w,w1;
      princ "start of tests on sqrt"; terpri();
      beta:=float(ibeta);
      sqbeta:=sqrt(beta);
      albeta:=log(beta);
      ait:=float(it);
      one:=float(1);
      zero:=float(0);
      a:=one/sqbeta;
      b:=one;
      n:=2000;
      xn:=float(n);
      for j:=1:2 do <<
         c:=log(b/a);
         k1:=0;
         k3:=0;
         x1:=zero;
         r6:=zero;
         r7:=zero;
         for i:=1:n do <<
            x:=a*randl(c);
            y:=x*x;
            z:=sqrt(y);
            w:=(z-x)/x;
            if w>zero then k1:=k1+1;
            if w<zero then k3:=k3+1;
            w:=abs w;
            if w>=r6 then << r6:=w; x1:=x >>;
            r7:=r7+w*w >>;
         k2:=n-k1-k3;
         heading("sqrt",n,a,b);
         errsigns(k1,k2,k3);
         r7:=sqrt(r7/xn);
         w:=-999.0;
         if r6 neq zero then w:=log(abs r6)/albeta;
         maxrel(w,x1,max(ait+w,zero));
         w:=-999.0;
         if r7 neq zero then w:=log(r7)/albeta;
         rmserr(w,max(ait+w,zero));
         a:=one;
         b:=sqbeta >>;
      specials("sqrt(xmin)",xmin,sqrt(xmin));
      specials("1-epsneg  ",one-epsneg,sqrt(one-epsneg));
      specials("1         ",one,sqrt(one));
      specials("1+eps     ",one+eps,sqrt(one+eps));
      specials("xmax      ",xmax,sqrt(xmax));
      specials("zero      ",zero,sqrt(zero));
      errortest list('sqrt, - one);
   end;

symbolic procedure sign(a,b);
   if minusp b then if minusp a then a else -a
   else if minusp a then -a else a;

symbolic procedure test!-log();
   begin
      scalar a,ait,albeta,b,beta,c,del,eight,half,one,
             r6,r7,tenth,w,x,xl,xn,x1,y,z,zero,zz,i,i1,j,k1,k2,k3,n;
      princ "start of tests on log"; terpri();
      beta:=float ibeta;
      albeta:=log beta;
      ait:=float it;
      j:=it/3;
      zero:=float 0;
      one:=float 1;
      eight:=float 8;
      half:=one/float 2;
      tenth:=one/float 10;
      c:=one;
      for i:=1:j do c:=c/beta;
      b:=one+c;
      a:=one-c;
      n:=2000;
      xn:=float n;
      i1:=0;
      for j:=1:4 do <<
         princ list("start of test ",j); terpri();
         k1:=0;
         k3:=0;
         x1:=zero;
         r6:=zero;
         r7:=zero;
         del:=(b-a)/xn;
         xl:=a;
         for i:=1:n do <<
            x:=del*rnd()+xl;
            if j=1 then <<
               y:=(x-half)-half;
               zz:=log x;
               z:=one/3.0;
               z:=y*(z-y/4.0);
               z:=(z-half)*y*y+y >>
            else if j=2 then <<
               x:=(x+eight)-eight;
               y:=x+x/16.0;
               z:=log x;
               zz:=log y - 7.7746816434842581/100000.0;
               zz:=zz-31.0/512.0 >>
            else if j=3 then <<
               x:=(x+eight)-eight;
               y:=x+x*tenth;
               z:=log10 x;
               zz:=log10 y-3.7706015822504075/10000.0;
               zz:=zz-21.0/512.0 >>
            else <<
               z:=log(x*x);
               zz:=log x;
               zz:=zz+zz >>;
            w:=one;
            if z neq zero then w:=(z-zz)/z;
            z:=sign(w,z);
            if z>zero then k1:=k1+1;
            if z<zero then k3:=k3+1;
            w:=abs w;
            if w>=r6 then << r6:=w; x1:=x >>;
            r7:=r7+w*w;
            xl:=xl+del >>;
         k2:=n-k1-k3;
         r7:=sqrt(r7/xn);
         if j=1 then princ "log vs taylor expansion"
         else if j=2 then princ "log vs 17/16 on"
         else if j=3 then princ "log10 vs 11/10 on"
         else princ "log vs squared arg";
         terpri();
         if not (j=1) then heading("log",n,a,b)
         else << princ list("c=",c); terpri() >>;
         errsigns(k1,k2,k3);
         w:=-999.0;
         if r6 neq zero then w:=log(abs r6)/albeta;
         maxrel(w,x1,max(ait+w,zero));
         w:=-999.0;
         if r7 neq zero then w:=log(abs r7)/albeta;
         rmserr(w,max(ait+w,zero));
         if j=1 then << a:=sqrt(half); b:=15.0/16.0 >>
         else if j=2 then << a:=sqrt(tenth); b:=0.9 >>
         else << a:=16.0; b:=240.0 >> >>;
      for i:=1:5 do <<
         x:=rnd();
         x:=x+x+15.0;
         y:=one/x;
         z:=log x+log y;
         specials("log(1/x)+log(x)   ",x,z) >>;
      specials(   "log(1)            ",one,log(one));
      specials(   "xmin              ",xmin,log(xmin));
      specials(   "xmax              ",xmax,log(xmax));
      errortest list('log, -2.0);
      errortest list('log, zero);
      princ "end of tests on log"; terpri()
   end;

symbolic procedure test!-exp();
   begin
      scalar a,ait,albeta,b,beta,d,del,one,r6,r7,two,ten,v,w,
             x,xl,xn,x1,y,z,zero,zz,i1,j,k1,k2,k3,n;
      beta:=float ibeta;
      albeta:=log beta;
      ait:=float it;
      one:=float 1;
      two:=float 2;
      ten:=float 10;
      zero:=float 0;
      v:=0.0625;
      a:=two;
      b:=log(a)*0.5;
      a:=-b+v;
      d:=log(0.9*xmax);
      n:=2000;
      xn:=float n;
      i1:=0;
      for j:=1:3 do <<
         k1:=0;
         k3:=0;
         x1:=zero;
         r6:=zero;
         r7:=zero;
         del:=(b-a)/xn;
         xl:=a;
         for i:=1:n do <<
            x:=del*rnd()+xl;
            y:=x-v;
            if y<zero then x:=y+v;
            z:=exp x;
            zz:=exp y;
            if j neq 1 then
               z:=z*0.0625 - z*2.4453321046920570389/1000.0
            else z:=z-z*6.058693718652421388/100.0;
            w:=one;
            if zz neq zero then w:=(z-zz)/zz;
            if w < zero then k1:=k1+1;
            if w>zero then k3:=k3+1;
            w:=abs w;
            if w>r6 then << r6:=w; x1:=x >>;
            r7:=r7+w*w;
            xl:=xl+del >>;
         k2:=n-k1-k3;
         r7:=sqrt(r7/xn);
         princ list("exp with v=",v); terpri();
         heading("exp",n,a,b);
         errsigns(k1,k2,k3);
         w:=-999.0;
         if r6 neq zero then w:=log abs r6/albeta;
         maxrel(w,x1,max(ait+w,zero));
         w:=-999.0;
         if r7 neq zero then w:=log abs r7/albeta;
         rmserr(w,max(ait+w,zero));
         if j neq 2 then <<
            v:=45.0 / 16.0;
            a:=-10*b;
            b:=4.0 * xmin * (beta**it);
            b:=log b >>
         else << a:=-two * a;
                 b:=ten * a;
                 if b<d then b:=d >> >>;
      for i:=1:5 do <<
         x:=rnd()*beta;
         y:=-x;
         z:=exp x * exp y - one;
         specials("exp(x)*exp(-x)-1  ",x,z) >>;
      specials("exp(0)-1   ",zero,exp(zero)-one);
      x:=float fix log xmin;
      specials("xmin       ",x,exp(x));
      x:=float fix log xmax;
      specials("xmax       ",x,exp x);
      x:=x / two;
      v:=x/two;
      y:=exp x;
      z:=exp v;
      z:=z*z;
      princ list(x,y,v,z); terpri();
      x:=-one/sqrt(xmin);
      errortest list('exp, x);
      x:=-x;
      errortest list('exp, x);
      princ "end of test on exp"; terpri()
   end;

symbolic procedure test!-sin();
   begin
      scalar a,ait,albeta,b,beta,betap,c,del,one,r6,r7,three,w,
             x,xl,xn,x1,y,z,zero,zz,expon,i1,j,k1,k2,k3,n;
      beta:=float ibeta;
      albeta:=log beta;
      ait:=float it;
      one:=float 1;
      three:=float 3;
      zero:=float 0;
      a:=zero;
      b:=1.570796327;
      c:=b;
      n:=2000;
      xn:=float n;
      i1:=0;
      for j:=1:3 do <<
         princ list("start of test ",j," of sin/cos"); terpri();
         k1:=0;
         k3:=0;
         x1:=zero;
         r6:=zero;
         r7:=zero;
         del:=(b-a)/xn;
         xl:=a;
         for i:=1:n do <<
            x:=del*rnd()+xl;
            y:=x/three;
            y:=(x+y)-x;
            x:=three*y;
            if j neq 3 then <<
               z:=sin x;
               zz:=sin y;
               w:=one;
               if z neq zero then w:=(z-zz*(three-4.0*zz*zz))/z >>
            else <<
               z:=cos x;
               zz:=cos y;
               w:=one;
               if z neq zero then w:=(z+zz*(three-4.0*zz*zz))/z >>;
            if w < zero then k1:=k1+1;
            if w>zero then k3:=k3+1;
            w:=abs w;
            if w>r6 then << r6:=w; x1:=x >>;
            r7:=r7+w*w;
            xl:=xl+del >>;
         k2:=n-k1-k3;
         r7:=sqrt(r7/xn);
         heading("sin/cos",n,a,b);
         errsigns(k1,k2,k3);
         w:=-999.0;
         if r6 neq zero then w:=log abs r6/albeta;
         maxrel(w,x1,max(ait+w,zero));
         w:=-999.0;
         if r7 neq zero then w:=log abs r7/albeta;
         rmserr(w,max(ait+w,zero));
         a:=18.84955592;
         if j=2 then a:=b+c;
         b:=a+c >>;
      c:=one/beta**(it/2);
      z:=(sin(a+c)-sin(a-c))/(c+c);
      princ list("this should be about 1.0   ",z); terpri();
      for i:=1:5 do <<
         x:=rnd()*a;
         z:=sin x + sin(-x);
         specials("sin(x)+sin(-x)  ",x,z) >>;
      betap:=beta**it;
      x:=rnd()/betap;
      for i:=1:5 do <<
         z:=x-sin x;
         specials("small args to sin ",x,z);
         x := x/beta >>;
      for i:=1:5 do <<
         x:=rnd()*a;
         z:=cos(x)-cos(-x);
         specials("cos(x)-cos(-x) ",x,z) >>;
      expon:=float minexp * 0.75;
      x:=beta**expon;
      y:=sin x;
      specials("tiny arg ",x,y);
%--      z:=sqrt betap;
%--      x:=z*(one-epsneg);
%--      y:=sin x;
%--      specials("??  ",x,y);
%--      y:=sin z;
%--      specials("??+ ",z,y);
%--      x:=z*(one+eps);
%--      y:=sin x;
%--      specials("??++",x,y);
      x:=betap;
      errortest list('sin, x);
      princ "end of test on sin/cos"; terpri()
   end;


symbolic procedure test!-tan();
   begin
      scalar a,ait,albeta,b,beta,betap,c1,c2,del,half,pi,r6,r7,
             w,x,xl,xn,x1,y,z,zero,zz,i,i1,j,k1,k2,k3,n,expon;
      beta:=float ibeta;
      albeta:=log beta;
      ait:=float it;
      zero:=float 0;
      half:=0.5;
      pi:=3.1415926;
      a:=zero;
      b:=pi*0.25;
      n:=2000;
      xn:=float n;
      i1:=0;
      for j:=1:4 do <<
         princ list("start of test ",j," of tan/cot"); terpri();
         k1:=0;
         k3:=0;
         x1:=zero;
         r6:=zero;
         r7:=zero;
         del:=(b-a)/xn;
         xl:=a;
         for i:=1:n do <<
            x:=del*rnd()+xl;
            y:=x*half;
            x:=y+y;
            if not (j=4) then <<
               z:=tan x;
               zz:=tan y;
               w:=1.0;
               if z neq zero then <<
                  w:=((half-zz)+half)*((half+zz)+half);
                  w:=(z-(zz+zz)/w)/z >> >>
            else <<
               z:=cot x;
               zz:=cot y;
               w:=1.0;
               if z neq zero then <<
                  w:=((half-zz)+half)*((half+zz)+half);
                  w:=(z+(w/(zz+zz)))/z >> >>;
            if w>zero then k1:=k1+1;
            if w<zero then k3:=k3+1;
            w:=abs w;
            if w>r6 then << r6:=w; x1:=x >>;
            r7:=r7+w*w;
            xl:=xl+del >>;
         k2:=n-k1-k3;
         r7:=sqrt(r7/xn);
         heading("tan/cot",n,a,b);
         errsigns(k1,k2,k3);
         w:=-999.0;
         if r6 neq zero then w:=log abs r6/albeta;
         maxrel(w,x1,max(ait+w,zero));
         w:=-999.0;
         if r7 neq zero then w:=log abs r7/albeta;
         rmserr(w,max(ait+w,zero));
         if j=1 then <<
            a:=pi*0.875;
            b:=pi*1.125 >>
         else <<
            a:=6.0*pi;
            b:=a+pi*0.25 >> >>;
      for i:=1:5 do <<
         x:=rnd()*a;
         z:=tan x + tan(-x);
         specials("tan(x)+tan(-x)  ",x,z) >>;
      betap:=beta**it;
      x:=rnd()/betap;
      for i:=1:5 do <<
         z:=x-tan x;
         specials("small args to tan ",x,z);
         x := x/beta >>;
      expon:=float minexp * 0.75;
      x:=beta**expon;
      y:=tan x;
      specials("tiny arg ",x,y);
      c1:=-225.0;
      c2:=-0.950846454195142026;
      x:=11.0;
      y:=tan x;
      w:=((c1-y)+c2)/(c1+c2);
      z:=log abs w/albeta;
      princ list("the relative error in tan 11 is ",z,max(ait+z,zero));
      terpri();
      x:=beta**(it/2);
      errortest list('tan, x);
      x:=betap;
      errortest list('tan, x);
      princ "end of test on tan/cot"; terpri()
   end;



on echo, time;

out "fptest.log";
fptest();
out t;

end;

