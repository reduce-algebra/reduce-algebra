% Steiner--Lehmus Theorem
rlset reals;

h1 := u2>=0 and x1>=0$
h2 := r^2=1+x1^2=u1^2+(u2-x1)^2$
h3 := x2<=0 and r^2=(x2-x1)^2$
h4 := u1*x2+u2*x3-x2*x3=0$
h5 := x4<=1 and (x4-1)^2=(u1-1)^2+u2^2$
h6 := (x4-x5)^2+x6^2=(u1-x5)^2+(u2-x6)^2 and u1*x6-u2*x5-u2+x6=0$
h7 := (-1-u1)^2+u2^2<2^2$

h := h1 and h2 and h3 and h4 and h5 and h6 and h7$

g := (u1-x3)^2+u2^2<(x5-1)^2+x6^2$

sl9 := all({x6,x5,x4,x3,x2,x1,r},h impl g)$

rlgqe sl9;

end;
