% QE special issue - Geometric Intersections
% Geometric Intersections by Scott McCallum
% THE Computer Journal 36(5), 432--438, 1993.
% The examples are given on page 436 and 437.

off rlabout;

rlset reals;

% Open unit ball with center at the origin in $R^3$.

b1 := x**2+y**2+z**2<1$

% Open unit ball with center at the point $(1,1,1)$ in $R^3$.
b2 := (x-1)**2+(y-1)**2+(z-1)**2<1$

% Open unit ball with center at the point $(3/2,2,0)$ in $R^3$.
b4 := (x-3/2)**2+(y-2)**2+z**2<1$

mc4 := rlex(b1 and b2 and b4)$

rlcad mc4;

end;
