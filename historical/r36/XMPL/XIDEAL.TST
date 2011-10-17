% Test file for XIDEAL package (Groebner bases for exterior algebra)

% Just make sure excalc has been loaded

load_package excalc$

% Declare exterior form variables

pform x=0,y=0,z=0,t=0,u=1,v=1,w=1,f(i)=1,h=0,hx=0,ht=0;

% Set switches for reduced Groebner bases in graded ideals

on xfullreduce;

% Reductions with xmodulo (all should be zero)

d x^d y     xmodulo {d x - d y};
d x^d y^d z xmodulo {d x^d y - d z^d t};
d x^d z^d t xmodulo {d x^d y - d z^d t};
v^d x^d y   xmodulo {d t^u - v^w,
                     w^u - d x^d y};
d t^u^d z   xmodulo {d t^u - v^w,
                     u^d z - d x^d y,
                     d t^d y - d x^v};
f(3)^f(4)^f(5)^f(6)
            xmodulo {f(1)^f(2) + f(3)^f(4) + f(5)^f(6)};
f(1)^f(4)^f(5)^f(6)
           xmodulo {f(1)^f(2) + f(2)^f(3) + f(3)^f(4) + f(4)^f(5) + f(5)^f(6)};

% Exterior system for heat equation on 1st jet bundle

S := {d h - ht*d t - hx*d x,
      d ht^d t + d hx^d x,
      d hx^d t - ht*d x^d t};

% Check that it's closed.

dS := (for each a in S collect d a) xmodulo S;

% Some Groebner bases (0-forms generate the trivial ideal)

gb := xideal {x, d y};
gb := xideal {f(1)^f(2) + f(3)^f(4)};
gb := xideal {f(1)^f(2), f(1)^f(3)+f(2)^f(4)+f(5)^f(6)};

% The same again, but not reduced

off xfullreduce;
gb := xideal {x, d y};
gb := xideal {f(1)^f(2) + f(3)^f(4)};
gb := xideal {f(1)^f(2), f(1)^f(3)+f(2)^f(4)+f(5)^f(6)};

% Reductions with a ready Groebner basis (not all zero)

on xfullreduce;
gb := xideal {f(1)^f(2) + f(3)^f(4) + f(5)^f(6)};
f(1)^f(3)^f(4) xmodulop gb;
f(3)^f(4)^f(5)^f(6) xmodulop gb;

% Non-graded ideals

on xfullreduce;

% Left and right ideals are no longer the same
 
d t^(d z+d x^d y) xmodulo {d z+d x^d y};
(d z+d x^d y)^d t xmodulo {d z+d x^d y};

% Higher order forms can now reduce lower order ones

d x xmodulo {d y^d z + d x,d x^d y + d z};

% Anything with a 0-form term generates the trivial ideal!!

gb := xideal {x + d y};
gb := xideal {1 + f(1) + f(1)^f(2) + f(2)^f(3)^f(4) + f(3)^f(4)^f(5)^f(6)};

end;
