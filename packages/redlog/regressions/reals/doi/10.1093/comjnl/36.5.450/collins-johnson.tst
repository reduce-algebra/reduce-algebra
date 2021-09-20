% The Collins--Johnson problem:

off rlabout$

rlset r$

a1 := -(1-3*r)*(a**2+b**2)+2*a*r$
a2 := -(2-3*r)*(a**2+b**2)+4*a*r-2*a-r$
coj := ex(r,0<r<1 and a>=1/2 and b>0 and a1<0 and a2>0)$

% Variant by Loos & Weispfenning:

lwcoj := ex(r,0<r<1 and a1<0 and a2>0)$

rlqe lwcoj;

end;
