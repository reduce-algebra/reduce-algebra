% GeoProver test file for Reduce, created on Jan 18 2003
load cali,geoprover;
off nat; on echo;

% The following "in" fails in the test harness that I use at present and
% so I have put the contents of the file that would have been read in-line
% in the test script.

%in "$reduce/packages/geometry/supp.red"$

%###############################################################
%
% FILE:    supp.red
% AUTHOR:  graebe
% CREATED: 2/2002
% PURPOSE: Interface for the extended GEO syntax to Reduce
% VERSION: $Id: supp.red,v 1.1 2002/12/26 16:27:22 compalg Exp $


% Redistribution and use in source and binary forms, with or without
% modification, are permitted provided that the following conditions are met:
%
%    * Redistributions of source code must retain the relevant copyright
%      notice, this list of conditions and the following disclaimer.
%    * Redistributions in binary form must reproduce the above copyright
%      notice, this list of conditions and the following disclaimer in the
%      documentation and/or other materials provided with the distribution.
%
% THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
% AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
% THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
% PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNERS OR
% CONTRIBUTORS
% BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
% CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
% SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
% INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
% CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
% ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
% POSSIBILITY OF SUCH DAMAGE.
%

algebraic procedure geo_simplify u; u;
algebraic procedure geo_normal u; u;
algebraic procedure geo_subs(a,b,c); sub(a=b,c);

algebraic procedure geo_gbasis(polys,vars);
  begin
  setring(vars,{},lex);
  setideal(uhu,polys);
  return gbasis uhu;
  end;

algebraic procedure geo_groebfactor(polys,vars,nondeg);
  begin
  setring(vars,{},lex);
  return groebfactor(polys,nondeg);
  end;

algebraic procedure geo_normalf(p,polys,vars);
  begin
  setring(vars,{},lex);
  return p mod polys;
  end;

algebraic procedure geo_eliminate(polys,vars,elivars);
  begin
  setring(vars,{},lex);
  return eliminate(polys,elivars);
  end;

algebraic procedure geo_solve(polys,vars);
  solve(polys,vars);

algebraic procedure geo_solveconstrained(polys,vars,nondegs);
  begin scalar u;
  setring(vars,{},lex);
  u:=groebfactor(polys,nondegs);
  return for each x in u join solve(x,vars);
  end;

algebraic procedure geo_eval(con,sol);
  for each x in sol collect sub(x,con);

% End of what was in supp.red





% Example Arnon
% 
% The problem:
% Let $ABCD$ be a square and $P$ a point on the line parallel to $BD$
% through $C$ such that $l(BD)=l(BP)$, where $l(BD)$ denotes the
% distance between $B$ and $D$. Let $Q$ be the intersection point of
% $BF$ and $CD$. Show that $l(DP)=l(DQ)$.
% 
% The solution:

vars_:=list(x1, x2, x3);
% Points
a__:=point(0,0); b__:=point(1,0); p__:=point(x1,x2);
% coordinates
d__:=rotate(a__,b__,1/2);
c__:=par_point(d__,a__,b__); 
q__:=varpoint(d__,c__,x3);
% polynomials
polys_:=list(on_line(p__,par_line(c__,pp_line(b__,d__))),
  eq_dist(b__,d__,b__,p__), on_line(q__,pp_line(b__,p__)));
% conclusion
con_:=eq_dist(d__,p__,d__,q__);
% solution
gb_:=geo_gbasis(polys_,vars_);
result_:=geo_normalf(con_,gb_,vars_);


% Example CircumCenter_1
% 
% The problem:
% The intersection point of the midpoint perpendiculars is the
% center of the circumscribed circle.
% 
% The solution:

parameters_:=list(a1, a2, b1, b2, c1, c2);
% Points
a__:=point(a1,a2);
b__:=point(b1,b2);
c__:=point(c1,c2);
% coordinates
m__:=intersection_point(p_bisector(a__,b__),
  p_bisector(b__,c__));
% conclusion
result_:=list( eq_dist(m__,a__,m__,b__), eq_dist(m__,a__,m__,c__) );


% Example EulerLine_1
% 
% The problem:
% Euler's line: The center $M$ of the circumscribed circle,
% the orthocenter $H$ and the barycenter $S$ are collinear and $S$
% divides $MH$ with ratio 1:2.
% 
% The solution:

parameters_:=list(a1, a2, b1, b2, c1, c2);
% Points
a__:=point(a1,a2);
b__:=point(b1,b2);
c__:=point(c1,c2);
% coordinates
s__:=intersection_point(median(a__,b__,c__),median(b__,c__,a__));
m__:=intersection_point(p_bisector(a__,b__),
  p_bisector(b__,c__));
h__:=intersection_point(altitude(a__,b__,c__),altitude(b__,c__,a__));
% conclusion
result_:=list(is_collinear(m__,h__,s__), sqrdist(s__,fixedpoint(m__,h__,1/3)));


% Example Brocard_3
% 
% The problem:
% Theorem about the Brocard points:
% Let $\Delta\,ABC$ be a triangle. The circles $c_1$ through $A,B$ and
% tangent to $g(AC)$, $c_2$ through $B,C$ and tangent to $g(AB)$, and
% $c_3$ through $A,C$ and tangent to $g(BC)$ pass through a common
% point.
% 
% The solution:

parameters_:=list(u1, u2);
% Points
a__:=point(0,0);
b__:=point(1,0);
c__:=point(u1,u2);
% coordinates
m_1_:=intersection_point(altitude(a__,a__,c__),p_bisector(a__,b__));
m_2_:=intersection_point(altitude(b__,b__,a__),p_bisector(b__,c__));
m_3_:=intersection_point(altitude(c__,c__,b__),p_bisector(a__,c__));
c1_:=pc_circle(m_1_,a__);
c2_:=pc_circle(m_2_,b__);
c3_:=pc_circle(m_3_,c__);
p__:=other_cc_point(b__,c1_,c2_);
% conclusion
result_:= on_circle(p__,c3_);


% Example Feuerbach_1
% 
% The problem:
% Feuerbach's circle or nine-point circle: The midpoint $N$ of $MH$ is
% the center of a circle that passes through nine special points, the
% three pedal points of the altitudes, the midpoints of the sides of the
% triangle and the midpoints of the upper parts of the three altitudes.
% 
% The solution:

parameters_:=list(u1, u2, u3);
% Points
a__:=point(0,0);
b__:=point(u1,0);
c__:=point(u2,u3);
% coordinates
h__:=intersection_point(altitude(a__,b__,c__),altitude(b__,c__,a__));
d__:=intersection_point(pp_line(a__,b__),pp_line(h__,c__));
m__:=intersection_point(p_bisector(a__,b__),
  p_bisector(b__,c__));
n__:=midpoint(m__,h__);
% conclusion
result_:=list( eq_dist(n__,midpoint(a__,b__),n__,midpoint(b__,c__)),
  eq_dist(n__,midpoint(a__,b__),n__,midpoint(h__,c__)),
  eq_dist(n__,midpoint(a__,b__),n__,d__) );


% Example FeuerbachTangency_1
% 
% The problem:
% For an arbitrary triangle $\Delta\,ABC$ Feuerbach's circle (nine-point
% circle) is tangent to its 4 tangent circles.
% 
% The solution:

vars_:=list(x1, x2);
parameters_:=list(u1, u2);
% Points
a__:=point(0,0);
b__:=point(2,0);
c__:=point(u1,u2);
p__:=point(x1,x2);
% coordinates
m__:=intersection_point(p_bisector(a__,b__), p_bisector(b__,c__));
h__:=intersection_point(altitude(a__,b__,c__),altitude(b__,c__,a__));
n__:=midpoint(m__,h__);
c1_:=pc_circle(n__,midpoint(a__,b__));
q__:=pedalpoint(p__,pp_line(a__,b__));
% polynomials
polys_:=list(on_bisector(p__,a__,b__,c__), on_bisector(p__,b__,c__,a__));
% conclusion
con_:=is_cc_tangent(pc_circle(p__,q__),c1_);
% solution
gb_:=geo_gbasis(polys_,vars_);
result_:=geo_normalf(con_,gb_,vars_);


% Example GeneralizedFermatPoint_1
% 
% The problem:
% A generalized theorem about Napoleon triangles:
% Let $\Delta\,ABC$ be an arbitrary triangle and $P,Q$ and $R$ the third
% vertex of isosceles triangles with equal base angles erected
% externally on the sides $BC, AC$ and $AB$ of the triangle. Then the
% lines $g(AP), g(BQ)$ and $g(CR)$ pass through a common point.
% 
% The solution:

vars_:=list(x1, x2, x3, x4, x5);
parameters_:=list(u1, u2, u3);
% Points
a__:=point(0,0);
b__:=point(2,0);
c__:=point(u1,u2);
p__:=point(x1,x2);
q__:=point(x3,x4);
r__:=point(x5,u3);
% polynomials
polys_:=list(eq_dist(p__,b__,p__,c__), 
  eq_dist(q__,a__,q__,c__),  
  eq_dist(r__,a__,r__,b__), 
  eq_angle(r__,a__,b__,p__,b__,c__), 
  eq_angle(q__,c__,a__,p__,b__,c__));
% conclusion
con_:=is_concurrent(pp_line(a__,p__), pp_line(b__,q__), pp_line(c__,r__));
% solution
sol_:=geo_solve(polys_,vars_);
result_:=geo_eval(con_,sol_);


% Example TaylorCircle_1
% 
% The problem:
% Let $\Delta\,ABC$ be an arbitrary triangle. Consider the three
% altitude pedal points and the pedal points of the perpendiculars from
% these points onto the the opposite sides of the triangle. Show that
% these 6 points are on a common circle, the {\em Taylor circle}.
% 
% The solution:

parameters_:=list(u1, u2, u3);
% Points
a__:=point(u1,0);
b__:=point(u2,0);
c__:=point(0,u3);
% coordinates
p__:=pedalpoint(a__,pp_line(b__,c__));
q__:=pedalpoint(b__,pp_line(a__,c__));
r__:=pedalpoint(c__,pp_line(a__,b__));
p_1_:=pedalpoint(p__,pp_line(a__,b__));
p_2_:=pedalpoint(p__,pp_line(a__,c__));
q_1_:=pedalpoint(q__,pp_line(a__,b__));
q_2_:=pedalpoint(q__,pp_line(b__,c__));
r_1_:=pedalpoint(r__,pp_line(a__,c__));
r_2_:=pedalpoint(r__,pp_line(b__,c__));
% conclusion
result_:=list( is_concyclic(p_1_,p_2_,q_1_,q_2_), 
  is_concyclic(p_1_,p_2_,q_1_,r_1_),
  is_concyclic(p_1_,p_2_,q_1_,r_2_));


% Example Miquel_1
% 
% The problem:
% Miquels theorem: Let $\Delta\,ABC$ be a triangle. Fix arbitrary points
% $P,Q,R$ on the sides $AB, BC, AC$. Then the three circles through each
% vertex and the chosen points on adjacent sides pass through a common
% point.
% 
% The solution:

parameters_:=list(c1, c2, u1, u2, u3);
% Points
a__:=point(0,0);
b__:=point(1,0);
c__:=point(c1,c2);
% coordinates
p__:=varpoint(a__,b__,u1);
q__:=varpoint(b__,c__,u2);
r__:=varpoint(a__,c__,u3);
x__:=other_cc_point(p__,p3_circle(a__,p__,r__),p3_circle(b__,p__,q__));
% conclusion
result_:=on_circle(x__,p3_circle(c__,q__,r__));


% Example PappusPoint_1
% 
% The problem:
% Let $A,B,C$ and $P,Q,R$ be two triples of collinear points. Then by
% the Theorem of Pappus the intersection points $g(AQ)\wedge g(BP),
% g(AR)\wedge g(CP)$ and $g(BR)\wedge g(CQ)$ are collinear. 
% 
% Permuting $P,Q,R$ we get six such {\em Pappus lines}.  Those
% corresponding to even resp. odd permutations are concurrent.
% 
% The solution:

parameters_:=list(u1, u2, u3, u4, u5, u6, u7, u8);
% Points
a__:=point(u1,0);
b__:=point(u2,0);
p__:=point(u4,u5);
q__:=point(u6,u7);
% coordinates
c__:=varpoint(a__,b__,u3);
r__:=varpoint(p__,q__,u8);
% conclusion
result_:=is_concurrent(pappus_line(a__,b__,c__,p__,q__,r__),
  pappus_line(a__,b__,c__,q__,r__,p__), 
  pappus_line(a__,b__,c__,r__,p__,q__));


% Example IMO/36_1
% 
% The problem:
% Let $A,B,C,D$ be four distinct points on a line, in that order. The
% circles with diameters $AC$ and $BD$ intersect at the points $X$ and
% $Y$. The line $XY$ meets $BC$ at the point $Z$. Let $P$ be a point on
% the line $XY$ different from $Z$. The line $CP$ intersects the circle
% with diameter $AC$ at the points $C$ and $M$, and the line $BP$
% intersects the circle with diameter $BD$ at the points $B$ and
% $N$. Prove that the lines $AM, DN$ and $XY$ are concurrent.
% 
% The solution:

vars_:=list(x1, x2, x3, x4, x5, x6);
parameters_:=list(u1, u2, u3);
% Points
x__:=point(0,1);
y__:=point(0,-1);
m__:=point(x1,x2);
n__:=point(x3,x4);
% coordinates
p__:=varpoint(x__,y__,u3);
z__:=midpoint(x__,y__);
l_:=p_bisector(x__,y__);
b__:=line_slider(l_,u1);
c__:=line_slider(l_,u2);
a__:=line_slider(l_,x5);
d__:=line_slider(l_,x6);
% polynomials
polys_:=list(is_concyclic(x__,y__,b__,n__), is_concyclic(x__,y__,c__,m__),
  is_concyclic(x__,y__,b__,d__), is_concyclic(x__,y__,c__,a__),
  is_collinear(b__,p__,n__), is_collinear(c__,p__,m__));
% constraints
nondeg_:=list(x5-u2,x1-u2,x6-u1,x3-u1);
% conclusion
con_:=is_concurrent(pp_line(a__,m__),pp_line(d__,n__),pp_line(x__,y__));
% solution
sol_:=geo_solveconstrained(polys_,vars_,nondeg_);
result_:=geo_eval(con_,sol_);


% Example IMO/43_2
% 
% The problem:
% 
% No verbal problem description available
% 
% The solution:

vars_:=list(x1, x2);
parameters_:=list(u1);
% Points
b__:=point(-1,0);
c__:=point(1,0);
% coordinates
o__:=midpoint(b__,c__);
gamma_:=pc_circle(o__,b__);
d__:=circle_slider(o__,b__,u1);
e__:=circle_slider(o__,b__,x1);
f__:=circle_slider(o__,b__,x2);
a__:=sym_point(b__,pp_line(o__,d__));
j__:=intersection_point(pp_line(a__,c__), par_line(o__, pp_line(a__,d__)));
m_:=p_bisector(o__,a__);
p_1_:=pedalpoint(j__,m_);
p_2_:=pedalpoint(j__,pp_line(c__,e__));
p_3_:=pedalpoint(j__,pp_line(c__,f__));
% polynomials
polys_:=list(on_line(e__,m_), on_line(f__,m_));
% constraints
nondegs_:=list(x1-x2);
% conclusion
con_:=list(eq_dist(j__,p_1_,j__,p_2_), eq_dist(j__,p_1_,j__,p_3_));
% solution
sol_:=geo_solveconstrained(polys_,vars_,nondegs_); 
result_:=geo_simplify(geo_eval(con_,sol_));

showtime;

end;
