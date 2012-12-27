% File: gauss.tst
% Author: Andreas Seidl
% Date: 25.03.1996
% Last change:

  on pginfosm;  % Show us the system-matrix.
  off pggeneric;  % All solutions.

% no solution:
  pg_gauss({x=1,x=2},{x});  % OK.

  pg_print pg_gauss({a*x**0=b*y+c},{x,y});  %  OK.
  pg_print pg_gauss({a*x=b*y+c},{x,y});  % OK.
  pg_print pg_gauss({a+3*b+5*c+2*d=0,
                           2*b+2*c-2*d+e=0,
                           5*c+5*d-2*e=0},{a,b,c,d,e});  % OK.
  pg_print pg_gauss({1*a+3*b+5*c+2*d+0*e=0,
                           3*a+9*b+(10)*c+1*d+2*e=0,
                           0*a+2*b+7*c+3*d-1*e=0,
                           2*a+8*b+(12)*c+2*d+1*e=0},{a,b,c,d,e});  % OK.

% example 8.1 from sit:
  pg_print pg_gauss({a*x+b*y=u,c*x+d*y=v},{x,y});  % OK.

% example 8.2 (lotka volterra) from sit:
% 13/8/2
% ofsf:  13/8/2
% acfsf: 13/8/2
pg_gauss({1*x+a*y+b*z=1,b*x+1*y+a*z=1,a*x+b*y+1*z=1,1*x+1*y+1*z=1},{x,y,z});

pg_gauss({
1*x+a*y=1,
b*x+1*y=1,
a*x+b*y=1,
1*x+1*y=1},{x,y});

% This is an important small example:
% ofsf:  3/3/1
% acfsf: 3/3/2
pg_gauss({1*x+a*y=1,b*x+1*y=1,a*x+b*y=1},{x,y});

% In this example the inconsistency is already detected by pgspsimpl:
% ofsf: 2/0/0
% (old version: ofsf: 2/2/1)
pg_gauss({(a^2-1)*x=0,0=a+1,0=a-1},{x});

% example 8.3 from sit;

pg_gauss({
0*w+1*x+0*y+2*z=w1,
a*w+b*x+c*y+1*z=w2,
2*w+0*x+1*y+d*z=w3,
0*w+0*x-1*y+a*z=w4,
1*w+0*x+0*y+1*z=w5
},{w,x,y,z});

% example 8.4 from sit;

pg_gauss({
0*w+1*x+0*y+2*z=a-b,
a*w+b*x+c*y+1*z=a+c,
2*w+0*x+1*y+d*z=0,
0*w+0*x-1*y+a*z=a+b,
1*w+0*x+0*y+1*z=a-c+d
},{w,x,y,z});

% this example shows weekness of v1.7
% number of solutions: 2/2/1
pg_gauss({(a^2-1)*x=0,0=a-1,0=a+1},{x});

% here are some standard examples with performance check:
% (the first time is from v1.2, the second from v1.3)

% Time: 70 ms for the following system:

  pg_print pg_gauss({a00*x+a01*y=b0,a10*x+a11*y=b1},{x,y});  % OK.


% Time: 470 ms for the following system:
% Time: 380 ms
% qe: Time: 3700 ms  plus GC time: 1370 ms
           pg_gauss({a00*x+a01*y+a02*z=b0,
	             a10*x+a11*y+a12*z=b1,
	             a20*x+a21*y+a22*z=b2},{x,y,z})$



% Time: 7290 ms  plus GC time: 120 ms for the following system:
% Time: 6730 ms
% simpl: Time: 7470 ms  plus GC time: 870 ms
% qe: heap space low;
           pg_gauss({a00*x+a01*y+a02*z+a03*w=0,
	             a10*x+a11*y+a12*z+a13*w=0,
	             a20*x+a21*y+a22*z+a23*w=0,
	             a30*x+a31*y+a32*z+a33*w=0},{x,y,z,w})$

           pg_gauss({a00*x+a01*y+a02*z+a03*w+a04*u=0,
	             a10*x+a11*y+a12*z+a13*w+a14*u=0,
	             a20*x+a21*y+a22*z+a23*w+a24*u=0,
	             a30*x+a31*y+a32*z+a33*w+a34*u=0,
	             a40*x+a41*y+a42*z+a43*w+a44*u=0},{x,y,z,w,u})$

% with reduce 32m the following system yields
% Time: 33020 ms  plus GC time: 80 ms
% Time: 24450 ms  plus GC time: 170 ms

           pg_gauss({a00*x+a01*y+a02*z+a03*w=b1,
	             a10*x+a11*y+a12*z+a13*w=b2,
	             a20*x+a21*y+a22*z+a23*w=b3,
	             a30*x+a31*y+a32*z+a33*w=b4},{x,y,z,w})$


% with reduce 32m the following system yields
%  unable to allocate 1f5ee50 1f58e50
% ***** Heap space low

% Time: 1200840 ms  plus GC time: 16930 ms

           pg_gauss({a00*x+a01*y+a02*z+a03*w+a04*u=0,
	             a10*x+a11*y+a12*z+a13*w+a14*u=0,
	             a20*x+a21*y+a22*z+a23*w+a24*u=0,
	             a30*x+a31*y+a32*z+a33*w+a34*u=0,
	             a40*x+a41*y+a42*z+a43*w+a44*u=0},{x,y,z,w,u})$

% test for sm_surep, sm_redp, sm_whitep.

sm_surep(nil,cond_0mkuneqt(numr simp 'a)); %ok nil
sm_surep(nil,cond_0mkuneqt(numr simp 1)); %ok t
sm_surep(nil,cond_0mkuneqt(numr simp 0)); %ok nil

sm_surep(nil,cond_0mkeqt(numr simp 'a)); %ok nil
sm_surep(nil,cond_0mkeqt(numr simp 1)); %ok nil
sm_surep(nil,cond_0mkeqt(numr simp 0)); %ok t


sm_redp (nil, numr simp 1); %ok t
sm_greenp (nil, numr simp 1); %ok nil

sm_redp (nil, numr simp 0); %ok nil
sm_greenp (nil, numr simp 0); %ok t

sm_redp (nil, numr simp 'a); %ok nil
sm_greenp (nil, numr simp 'a); %ok nil


% test of cond_inconsistentp

unsat2 := '((equal (((a . 2) . -1) ((a . 1) ((b . 1) . 1) . 1) ((b . 2) . -1) ((b . 1) . 1) . -1) nil) (neq (((a . 1) ((b . 1) . -1)) . 1) nil));
unsat := {cond_0mkeqt(numr simp '(plus a 1)),cond_0mkeqt(numr simp '(plus a (minus 1)))}$
sat := {cond_0mkeqt(numr simp '(plus a 1)),cond_0mkeqt(numr simp '(plus b (minus 1)))}$
cond_prin2l unsat;
cond_prin2l unsat2;
cond_prin2l sat;

on pgspsimpl$
off pgspqe$
cond_inconsistentp nil;
cond_inconsistentp unsat;
cond_inconsistentp unsat2;
cond_inconsistentp sat;

off pgspsimpl$
on pgspqe$
cond_inconsistentp nil;
cond_inconsistentp unsat;
cond_inconsistentp unsat2;
cond_inconsistentp sat;


% test of cond_simpl and cond_qe;

cond_simpl nil;
cond_prin2 cond_simpl sat;
cond_prin2 cond_simpl unsat;
cond_prin2 cond_simpl unsat2;

cond_simpl nil;
cond_prin2 cond_qe sat;
cond_prin2 cond_qe unsat;
cond_prin2 cond_qe unsat2;


end;
