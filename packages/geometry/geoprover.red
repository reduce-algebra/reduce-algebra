% GeoProver | Version 1.3a | Jan 20 2003
% Author: H.-G. Graebe, Univ. Leipzig, Germany
% http://www.informatik.uni-leipzig.de/~graebe

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


module geoprover;

COMMENT

GeoProver inline part. Version 1.3

Data structures:

        Point A  :== {a1,a2}       <=> A=(a1,a2)
        Line  a  :== {a1,a2,a3}    <=> a1*x+a2*y+a3 = 0
        Circle c :== {c0,c1,c2,c3} <=> c0*(x^2+y^2)+c1*x+c2*y+c3 = 0

end comment;

put ('geoprover,'name," GeoProver ")$
put ('geoprover,'version," 1.3a ")$
put ('geoprover,'date," December 30, 2002")$

algebraic(write(" Geoprover ", get('geoprover,'version),
        " Last update ",get('geoprover,'date)));

% ============= Handling non degeneracy conditions ===============

algebraic procedure clear_ndg; !*ndg!*:={};
algebraic procedure print_ndg; !*ndg!*;
algebraic procedure add_ndg(d);
  if not member(d,!*ndg!*) then !*ndg!*:=d . !*ndg!*;

clear_ndg();  % Initialization

% ================= elementary geometric constructions ===============

% Generators:

algebraic procedure is_equal(a,b); a-b;
%algebraic procedure Normal(a); a;
algebraic procedure point(a,b); {a,b};
algebraic procedure line(a,b,c); reduce_coords({a,b,c});

algebraic procedure par_point(a,b,c);
  point(part(a,1)-part(b,1)+part(c,1),
  part(a,2)-part(b,2)+part(c,2));

algebraic procedure pp_line(a,b);
% The line through A and B.
  line(part(b,2)-part(a,2),part(a,1)-part(b,1),
        part(a,2)*part(b,1)-part(a,1)*part(b,2));

algebraic procedure intersection_point(a,b);
% The intersection point of the lines a,b.
   begin scalar d,d1,d2;
   d:=part(a,1)*part(b,2)-part(b,1)*part(a,2);
   d1:=part(a,3)*part(b,2)-part(b,3)*part(a,2);
   d2:=part(a,1)*part(b,3)-part(b,1)*part(a,3);
   if d=0 then rederr"Lines are parallel";
   add_ndg(num d);
   return point(-d1/d,-d2/d);
   end;

algebraic procedure ortho_line(p,a);
% The line through P orthogonal to the line a.
  begin scalar u,v; u:=first a; v:=second a;
  return line(v,-u,u*second p-v*first p);
  end;

algebraic procedure par_line(p,a);
% The parallel to line a through P.
  line(part(a,1),part(a,2),
        -(part(a,1)*part(p,1)+part(a,2) *part(p,2)));

algebraic procedure varpoint(b,a,l);
% The point D=l*A+(1-l)*B.
  point(l*part(a,1)+(1-l)*part(b,1),l*part(a,2)+(1-l)*part(b,2));

algebraic procedure line_slider(a,u);
% Slider on the line a using parameter u.
  begin scalar p,d;
  if part(a,2)=0 then
        << p:=point(-part(a,3)/part(a,1),u); d:=part(a,1); >>
  else
        << p:=point(u,-(part(a,3)+part(a,1)*u)/part(a,2));
           d:=part(a,2);
        >>;
  add_ndg(num d);
  return p;
  end;

algebraic procedure circle_slider(m,a,u);
% Slider on the circle with center M and circumfere point A using
% parameter u.
  begin scalar a1,a2,m1,m2,d;
  a1:=part(a,1); a2:=part(a,2); d:= u^2 + 1;
  m1:=part(m,1); m2:=part(m,2);
  add_ndg(num d);
  return point((a1*(u^2-1) + 2*m1 + 2*(m2-a2)*u)/d,
         (a2 + 2*(m1-a1)*u + (2*m2-a2)*u^2)/d);
  end;

algebraic procedure sqrdist(a,b);
% The square of the distance between the points A and B.
  (part(b,1)-part(a,1))^2+(part(b,2)-part(a,2))^2;

% ================= elementary geometric properties ===============

algebraic procedure is_collinear(a,b,c);
% A,B,C are on a common line.
det mat((part(a,1),part(a,2),1),
        (part(b,1),part(b,2),1),
        (part(c,1),part(c,2),1));

algebraic procedure is_concurrent(a,b,c);
% Lines a,b,c have a common point.
det mat((part(a,1),part(a,2),part(a,3)),
        (part(b,1),part(b,2),part(b,3)),
        (part(c,1),part(c,2),part(c,3)));

algebraic procedure is_parallel(a,b);
% 0 <=> the lines a,b are parallel.
  part(a,1)*part(b,2)-part(b,1)*part(a,2);

algebraic procedure is_orthogonal(a,b);
% 0 <=> the lines a,b are orthogonal.
  part(a,1)*part(b,1)+part(a,2)*part(b,2);

algebraic procedure on_line(p,a);
% Substitute point P into the line a.
  part(p,1)*part(a,1)+part(p,2)*part(a,2)+part(a,3);

algebraic procedure eq_dist(a,b,c,d); sqrdist(a,b)-sqrdist(c,d);

%       #########################################
%       #                                       #
%       #      Non linear geometric objects      #
%       #                                       #
%       #########################################


% ===================== angles

algebraic procedure l2_angle(a,b);
% tan of the angle between the lines a and b.
  begin scalar d; d:=(part(a,1)*part(b,1)+part(a,2)*part(b,2));
  add_ndg(num(d));
  return (part(a,2)*part(b,1)-part(b,2)*part(a,1))/d;
  end;

algebraic procedure angle_sum(a,b);
% a=tan(\alpha), b=tan(\beta). Returns tan(\alpha+\beta)
  begin scalar d; d:=(1-a*b); add_ndg(num d);
  return (a+b)/d;
  end;

algebraic procedure eq_angle(a,b,c,d,e,f);
  p3_angle(a,b,c)-p3_angle(d,e,f);

algebraic procedure on_bisector(p,a,b,c);
% P is a point on the bisector of the angle ABC.
% Returns num(u)*den(v)-num(v)*den(u) with
% u:=angle(pp_line(A,B),pp_line(P,B))
% v:=angle(pp_line(P,B),pp_line(C,B))
  begin scalar a1,a2,b1,b2,c1,c2,p1,p2;
        a1:=part(a,1); a2:=part(a,2);
        b1:=part(b,1); b2:=part(b,2);
        c1:=part(c,1); c2:=part(c,2);
        p1:=part(p,1); p2:=part(p,2);
  return ( - a1*b2 + a1*p2 + a2*b1 - a2*p1 - b1*p2 + b2*p1)*(b1^2 -
  b1*c1 - b1*p1 + b2^2 - b2*c2 - b2*p2 + c1*p1 + c2*p2) - (a1*b1 -
  a1*p1 + a2*b2 - a2*p2 - b1^2 + b1*p1 - b2^2 + b2*p2)*(b1*c2 -
  b1*p2 - b2*c1 + b2*p1 + c1*p2 - c2*p1)
  end;

algebraic procedure rotate(c, a, angle);
  begin scalar ac1,ac2;
  ac1:=part(a,1)-part(c,1); ac2:=part(a,2)-part(c,2);
  return point(part(c,1)+ac1*cos(angle*pi)-ac2*sin(angle*pi),
    part(c,2)+ac1*sin(angle*pi)+ac2*cos(angle*pi));
  end;

% ========== symmetric lines and points

algebraic procedure sym_line(a,l);
% The line symmetric to a wrt. the line l.
  begin scalar a1,a2,a3,l1,l2,l3,u;
  a1:=part(a,1); a2:=part(a,2); a3:=part(a,3);
  l1:=part(l,1); l2:=part(l,2); l3:=part(l,3);
  u:=l1^2 - l2^2;
  return line(- a1*u - 2*a2*l1*l2, - 2*a1*l1*l2 + a2*u,
                - 2*(a1*l1 + a2*l2)*l3 + a3*(l1^2 + l2^2));
  end;

% ===================== circles

algebraic procedure circle(c1,c2,c3,c4); reduce_coords({c1,c2,c3,c4});

algebraic procedure pc_circle(m,a);
% Circle with center M and Point A on circumference.
  circle(1, -2*part(m,1), -2*part(m,2),
            part(a,1)*(2*part(m,1)-part(a,1)) +
            part(a,2)*(2*part(m,2)-part(a,2)));

algebraic procedure circle_center c;
% The center of the circle c.
  begin add_ndg(num part(c,1));
  return point(-part(c,2)/2/part(c,1) ,-part(c,3)/(2*part(c,1)));
  end;

algebraic procedure circle_sqradius c;
% The squared radius of the circle c.
  begin add_ndg(num part(c,1));
  return
   ((part(c,2)^2+part(c,3)^2) - 4*part(c,4)*part(c,1)) /
        (2*part(c,1))^2;
  end;

algebraic procedure p3_circle(a,b,c);
% The circle through three given points
  begin scalar a1,a2,a3,b1,b2,b3,c1,c2,c3;
  a1:=part(a,1); a2:=part(a,2); a3:=a1^2+a2^2;
  b1:=part(b,1); b2:=part(b,2); b3:=b1^2+b2^2;
  c1:=part(c,1); c2:=part(c,2); c3:=c1^2+c2^2;
  return circle(a1*(b2-c2) + (a2-b2)*c1 + b1*(c2-a2),
    a3*(c2-b2) + (a2-c2)*b3 + (b2-a2)*c3,
    a3*(b1-c1) + (c1-a1)*b3 + (a1-b1)*c3,
    a3*(b2*c1-b1*c2) + (a1*c2-a2*c1)*b3 + (a2*b1-a1*b2)*c3)
  end;

algebraic procedure on_circle(p,c);
  begin scalar p1,p2; p1:=part(p,1); p2:=part(p,2);
  return part(c,1)*(p1^2+p2^2)+part(c,2)*p1+part(c,3)*p2+part(c,4);
  end;

% Intersecting with circles

algebraic procedure other_cl_point(p,c,l);
% circle c and line l intersect at P. The procedure returns their
% second intersection point.
  if on_line(p,l) neq 0 then rederr "Point not on the line"
  else if on_circle(p,c) neq 0 then
        rederr "Point not on the circle"
  else begin scalar c1,c2,c3,l1,l2,d,d1,p1,p2;
  c1:=part(c,1); c2:=part(c,2); c3:=part(c,3);
  l1:=part(l,1); l2:=part(l,2); p1:=part(p,1); p2:=part(p,2);
  d:=c1*(l1^2 + l2^2); add_ndg(num d); d1:=c1*(l1^2-l2^2);
  return {(d1*p1+((2*c1*p2 + c3)*l1-c2*l2)*l2)/d,
        (- d1*p2+((2*c1*p1 + c2)*l2-c3*l1)*l1)/d};
  end;

algebraic procedure radical_axis(c1,c2);
% Radical axis of the circles c1 and c2, i.e. the line through the
% intersection points of the two circles if they intersect.
  for i:=2:4 collect
        (part(c1,1)*part(c2,i)-part(c1,i)*part(c2,1));

algebraic procedure other_cc_point(p,c1,c2);
% Circles c1 and c2 intersect at P. The procedure returns their
% second intersection point.
  other_cl_point(p,c1,radical_axis(c1,c2));

algebraic procedure is_cl_tangent(c,l);
% Line l is tangent to the circle c.
  begin scalar c1,c2,c3,c4,l1,l2,l3;
  c1:=part(c,1); c2:=part(c,2); c3:=part(c,3); c4:=part(c,4);
  l1:=part(l,1); l2:=part(l,2); l3:=part(l,3);
  return - 4*c1^2*l3^2 + 4*c1*c2*l1*l3 + 4*c1*c3*l2*l3 -
        4*c1*c4*l1^2 - 4*c1*c4*l2^2 + c2^2*l2^2 - 2*c2*c3*l1*l2 +
        c3^2*l1^2
  end;

algebraic procedure is_cc_tangent(c,d);
% Two circles c,d are tangent.
  begin scalar c1,c2,c3,c4,d1,d2,d3,d4;
  c1:=part(c,1); c2:=part(c,2); c3:=part(c,3); c4:=part(c,4);
  d1:=part(d,1); d2:=part(d,2); d3:=part(d,3); d4:=part(d,4);
  return
4*c1^2*d4^2 - 4*c1*c2*d2*d4 - 4*c1*c3*d3*d4 - 8*c1*c4*d1*d4 +
4*c1*c4*d2^2 + 4*c1*c4*d3^2 + 4*c2^2*d1*d4 - c2^2*d3^2 + 2*c2*c3*d2*d3
- 4*c2*c4*d1*d2 + 4*c3^2*d1*d4 - c3^2*d2^2 - 4*c3*c4*d1*d3 +
4*c4^2*d1^2
  end;

% ============= some additional tools ===============

symbolic operator list2mat;
symbolic procedure list2mat u;
  'mat. for each x in cdr reval u collect cdr x;

algebraic procedure extractmat(polys,vars);
% extract the coefficient matrix from the linear system polys.
  begin
  if length polys neq length vars then
        rederr"Number of variables doesn't match";
  for each p in polys do for each x in vars do
        if deg(p,x)>1 then rederr"Equations not of linear type";
  return list2mat
        for each x in vars collect
        for each p in polys collect coeffn(p,x,1);
end;

algebraic procedure reduce_coords u;
% Divide out the content of homogeneous coordinates.
  begin scalar l,g;
  l:=den first u; g:=num first u;
  for each x in rest u do <<l:=lcm(l,den x); g:=gcd(g,num x) >>;
  add_ndg(g);
  return for each x in u collect (x*l/g);
  end;

% ================ new

algebraic procedure circle_inverse(m,r,p);
% compute the inverse of P wrt. the circle pc_circle(M,R)
  begin scalar m1,m2,r1,r2,p1,p2,d;
  m1:=part(m,1); m2:=part(m,2);
  r1:=part(r,1); r2:=part(r,2);
  p1:=part(p,1); p2:=part(p,2);
  d:=(m1-p1)^2+(m2-p2)^2;
  add_ndg(d);
  return ((m1-p1)^2+(m2-p2)^2+(m1-r1)^2+(m2-r2)^2)/d;
  end;

% GeoProver code generated from database

algebraic procedure altitude(a__,b__,c__);
        ortho_line(a__,pp_line(b__,c__));

algebraic procedure centroid(a__,b__,c__);
        intersection_point(median(a__,b__,c__),median(b__,c__,a__));

algebraic procedure circumcenter(a__,b__,c__);
        intersection_point(p_bisector(a__,b__), p_bisector(b__,c__));

algebraic procedure csym_point(p__,q__);
        varpoint(q__,p__,-1);

algebraic procedure fixedpoint(a__,b__,u_);
        varpoint(a__,b__,u_);

algebraic procedure is_concyclic(a__,b__,c__,d__);
        on_circle(d__,p3_circle(a__,b__,c__));

algebraic procedure median(a__,b__,c__);
        pp_line(a__,midpoint(b__,c__));

algebraic procedure midpoint(a__,b__);
        fixedpoint(a__,b__,1/2);

algebraic procedure orthocenter(a__,b__,c__);
        intersection_point(altitude(a__,b__,c__),altitude(b__,c__,a__));

algebraic procedure other_incenter(m__,a__,b__);
        intersection_point(ortho_line(a__,pp_line(m__,a__)),
ortho_line(b__,pp_line(m__,b__)));

algebraic procedure p3_angle(a__,b__,c__);
        l2_angle(pp_line(b__,a__),pp_line(b__,c__));

algebraic procedure p9_center(a__,b__,c__);
        circle_center(p9_circle(a__,b__,c__));

algebraic procedure p9_circle(a__,b__,c__);
        p3_circle(midpoint(a__,b__),midpoint(a__,c__),midpoint(b__,c__));

algebraic procedure p_bisector(b__,c__);
        ortho_line(midpoint(b__,c__),pp_line(b__,c__));

algebraic procedure pappus_line(a__,b__,c__,d__,e__,f__);
        pp_line(intersection_point(pp_line(a__,e__),pp_line(b__,d__)),
        intersection_point(pp_line(a__,f__),pp_line(c__,d__)));

algebraic procedure pedalpoint(p__,a_);
        intersection_point(ortho_line(p__,a_),a_);

algebraic procedure sqrdist_pl(a__,l_);
        sqrdist(a__,pedalpoint(a__,l_));

algebraic procedure sym_point(p__,l_);
        fixedpoint(p__,pedalpoint(p__,l_),2);

algebraic procedure triangle_area(a__,b__,c__);
        1/2*is_collinear(a__,b__,c__);

endmodule; % GeoProver

end;

