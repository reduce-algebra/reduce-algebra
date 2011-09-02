%Examples of use of Groebner code.

% Example 1, Linz 85.

groebner({q1,

          q2**2 + q3**2 + q4**2,

          q4*q3*q2,

          q3**2*q2**2 + q4**2*q2**2 + q4**2*q3**2,

          q6**2 + 1/3*q5**2,

          q6**3 - q5**2*q6,

          2*q2**2*q6 - q3**2*q6 - q4**2*q6 + q3**2*q5 - q4**2*q5,

          2*q2**2*q6**2 - q3**2*q6**2 - q4**2*q6**2 - 2*q3**2*q5*q6
          + 2*q4**2*q5*q6 - 2/3*q2**2*q5**2 + 1/3*q3**2*q5**2
          + 1/3*q4**2*q5**2,

          - q3**2*q2**2*q6 - q4**2*q2**2*q6 + 2*q4**2*q3**2*q6 -
          q3**2*q2**2*q5 + q4**2*q2**2*q5,

          - q3**2*q2**2*q6**2 - q4**2*q2**2*q6**2 + 2*q4**2*q3**2*q6**2
          + 2*q3**2*q2**2*q5*q6 - 2*q4**2*q2**2*q5*q6 + 1/3*q3**2*q2**2
          *q5**2 + 1/3*q4**2*q2**2*q5**2 - 2/3*q4**2*q3**2*q5**2,

          - 3*q3**2*q2**4*q5*q6**2 + 3*q4**2*q2**4*q5*q6**2
          + 3*q3**4*q2**2*q5*q6**2 - 3*q4**4*q2**2*q5*q6**2
          - 3*q4**2*q3**4*q5*q6**2 + 3*q4**4*q3**2*q5*q6**2
          + 1/3*q3**2*q2**4*q5**3 - 1/3*q4**2*q2**4*q5**3
          - 1/3*q3**4*q2**2*q5**3 + 1/3*q4**4*q2**2*q5**3 + 1/3*q4**2
            *q3**4*q5**3 - 1/3*q4**4*q3**2*q5**3},

         {q1,q2,q3,q4,q5,q6});


% Example 2. (Little) Trinks problem with 7 polynomials in 6 variables.

polys := {45*p + 35*s - 165*b - 36,

          35*p + 40*z + 25*t - 27*s,

          15*w + 25*p*s + 30*z - 18*t - 165*b**2,

          - 9*w + 15*p*t + 20*z*s,

          w*p + 2*z*t - 11*b**3,

          99*w - 11*s*b + 3*b**2,

          b**2 + 33/50*b + 2673/10000};

vars :=  {w,p,z,t,s,b};
groebner(polys,vars);
groesolve(polys,vars);
 


% Example 3. Hairer, Runge-Kutta 1, 6 polynomials 8 variables.
 
groebnerf({c2 - a21,
 
          c3 - a31 - a32,
 
          b1 + b2 + b3 - 1,
 
          b2*c2 + b3*c3 - 1/2,
 
          b2*c2**2 + b3*c3**2 - 1/3,
 
          b3*a32*c2 - 1/6},
 
         {c2,c3,b3,b2,b1,a21,a32,a31});
 
 

% Example 4.
 
torder gradlex;
 
g4 := 
groebner({b + e + f - 1,
 
         c + d + 2*e - 3,
 
         b + d + 2*f - 1,
 
         a - b - c - d - e - f,
 
         d*e*a**2 - 1569/31250*b*c**3,
 
         c*f - 587/15625*b*d});
 
hilbertpolynomial(g4,gvarslast);

%   gunivar(e,8,g4,gvarslast);

glexconvert(g4,gvarslast,newvars={e},maxdeg=8);

groebnerf({b + e + f - 1, 
  
         c + d + 2*e - 3, 
  
         b + d + 2*f - 1, 
  
         a - b - c - d - e - f, 
  
         d*e*a**2 - 1569/31250*b*c**3, 
  
         c*f - 587/15625*b*d});


% Example 5.
 
groesolve({u0**2 - u0 + 2*u1**2 + 2*u2**2 + 2*u3**2,
 
          2*u0*u1 + 2*u1*u2 + 2*u2*u3 - u1,
 
          2*u0*u2 + u1**2 + 2*u1*u3 - u2,
 
          u0 + 2*u1 + 2*u2 + 2*u3 - 1},
 
         {u0,u2,u3,u1});
 
 

% Example 6. (Big) Trinks problem with 6 polynomials in 6 variables.
 
 torder lex;
 
 groebner({45*p + 35*s - 165*b - 36,
 
           35*p + 40*z + 25*t - 27*s,
 
           15*w + 25*p*s + 30*z - 18*t - 165*b**2,
 
           -9*w + 15*p*t + 20*z*s,
 
           w*p + 2*z*t - 11*b**3,
 
           99*w - 11*b*s + 3*b**2},
 
          {w,p,z,t,s,b});
 
 
hilbertpolynomial(ws,gvarslast);

end;
