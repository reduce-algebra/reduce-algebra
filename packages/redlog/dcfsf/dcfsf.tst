off rlabout;
rlset dcfsf;

w1 := x^2+x=0 and x-a=0;
w2 := d(x,1)+a=0 and x^2+b=0;
w3 := d(x,1)^2-1=0 and d(x,1)^3-a=0;
w4 := d(x,2)+x=0 and d(x,1)=a*x and a<>0 and d(a,1)=0;
w5 := x*d(x,1)^2+a=0 and d(x,1) <> 0;
w6 := (x+1)*d(x,1)^2+a=0 and d(x,1)-1 <> 0;

off rlenfsimpl;

% on rlenf1twice;

off rlenffac;

rlenf(w1,x);
rlenf(w2,x);
rlenf(w3,x);
rlenf(w4,x);
rlenf(w5,x);
rlenf(w6,x);

rlqe ex(x,w1);
rlqe ex(x,w2);
rlqe ex(x,w3);
rlqe ex(x,w4);
rlqe ex(x,w5);
rlqe ex(x,w6);

on rlenffac;

rlenf(w1,x);
rlenf(w2,x);
rlenf(w3,x);
rlenf(w4,x);
rlenf(w5,x);
rlenf(w6,x);

rlqe ex(x,w1);
rlqe ex(x,w2);
rlqe ex(x,w3);
rlqe ex(x,w4);
rlqe ex(x,w5);
rlqe ex(x,w6);


% Was gatermann.red. gat is Gatermann, bou is Boulier:
gat := d(x1,1) = k21*x1^2*x2+k46-k64*x1-k34*x1+k43 and
   d(x2,1) = -k21*x1^2*x2+k56-k65*x2 and
   d(x3,1) = k34*x1-k43*x3;

thgat := {d(k21,1)=0, d(k46,1)=0, d(k64,1)=0, d(k34,1)=0, d(k43,1)=0,
   d(k56,1)=0, d(k65,1)=0};

bou := d(g,1) = theta*(gamma0-g-g*p^n) and
   d(p,1) = n*alpha*(gamma0-g-g*p^n)+delta*(m-p) and
   d(m,1) = lambda1*g+gamma0*mu-m;

thbou := {d(theta,1)=0, d(gamma0,1)=0, d(alpha,1)=0, d(delta,1)=0,
   d(lambda1,1)=0, d(mu,1)=0};

bou9 := sub(n=9,bou);

end;
