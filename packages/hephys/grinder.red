% grinder.red
% JHEP 03 (2000) 013 [hep-ph/0002266]

%% Copyright (c) A.G.Grozin, 2000-2022
%%
%% Redistribution and use in source and binary forms, with or without
%% modification, are permitted provided that the following conditions are
%% met:
%%
%%     * Redistributions of source code must retain the relevant
%%       copyright notice, this list of conditions and the following
%%       disclaimer.
%%     * Redistributions in binary form must reproduce the above
%%       copyright notice, this list of conditions and the following
%%       disclaimer in the documentation and/or other materials provided
%%       with the distribution.
%%
%% THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
%% "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
%% LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS
%% FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE
%% COPYRIGHT OWNERS OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
%% INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
%% BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS
%% OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
%% ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR
%% TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF
%% THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH
%% DAMAGE.

% $Id: $

algebraic;

off lower,raise$

% Gamma(x+n)/Gamma(x)
procedure G(x,n);
if n>0 then for i:=0:(n-1) product (x+i)
else if n<0 then 1/(for i:=1:(-n) product (x-i))
else 1$

% 1-loop QCD
procedure G1(n1,n2);
if n1<=0 or n2<=0 then 0
else G(-d/2+2,n1+n2-2)*G(d/2-1,1-n1)*G(d/2-1,1-n2)
    /(G(d-2,2-n1-n2)*factorial(n1-1)*factorial(n2-1))$

% G(n1,n2;n,m)/G(1,1)
procedure GG1(n1,n2,n,m);
if n1<=0 or n2<=0 then 0
else G(-d/2+2,n1+n2-m-2)*G(d/2-1,1-n1+n-m)*G(d/2-1,1-n2+m)
    /(G(d-2,2-n1-n2+n)*factorial(n1-1)*factorial(n2-1))$

% G(n1-d/2,n2)/G(2-d/2,1)
procedure G1a(n1,n2);
if n2<=0 then 0
else G(-d+3,n1+n2-3)*G(d-2,2-n1)*G(d/2-1,1-n2)
    /(G(3/2*d-3,3-n1-n2)*G(-d/2+2,n1-2)*factorial(n2-1))$

% 1-loop HQET
procedure I1(n1,n2);
if n1<=0 or n2<=0 then 0
else G(-d+3,n1+2*n2-3)*G(d/2-1,1-n2)/(factorial(n1-1)*factorial(n2-1))$

% I1(n1,n2;n,m)/I1(1,1)
procedure II1(n1,n2,n,m);
if n1<=0 or n2<=0 then 0
else G(-d+3,n1+2*n2-n-3)*G(d/2-1,1-n2+n-m)/(factorial(n1-1)*factorial(n2-1))$

% I(n1-d,n2)/I(3-d,1)
procedure I1a(n1,n2);
if n2<=0 then 0
else G(-2*d+5,n1+2*n2-5)*G(d/2-1,1-n2)/(G(-d+3,n1-3)*factorial(n2-1))$

% I(n1,n2-d/2)/I(1,2-d/2)
procedure I1b(n1,n2);
if n1<=0 then 0
else G(-2*d+5,n1+2*n2-5)*G(d-2,2-n2)/(G(-d/2+2,n2-2)*factorial(n1-1))$

% I(n1-2*d,n2)/I(5-2*d,1)
procedure I1c(n1,n2);
if n2<=0 then 0
else G(-3*d+7,n1+2*n2-7)*G(d/2-1,1-n2)/(G(-2*d+5,n1-5)*factorial(n2-1))$

% I(n1-d,n2-d/2)/I(3-d,2-d/2)
procedure I1d(n1,n2);
G(-3*d+7,n1+2*n2-7)*G(d-2,2-n2)/(G(-d+3,n1-3)*G(-d/2+2,n2-2))$

% I(n1,n2-d)/I(1,3-d)
procedure I1e(n1,n2);
if n1<=0 then 0
else G(-3*d+7,n1+2*n2-7)*G(3/2*d-3,3-n2)/(G(-d+3,n2-3)*factorial(n1-1))$

operator B; % basis
% B(1) = I1^3          I1^2    G1^2
% B(2) = I1*I2         I2      G2
% B(3) = I3
% B(4) = I3*I1^2/I2
% B(5) = I3*G1^2/G2
% B(6) - Fig. 10f
% B(7) - Fig. 10g
% B(8) - Fig. 10h

%     -----       D1 = -k1^2
%  3 /  |  \ 4    D2 = -k2^2
%   /   |   \     D3 = -(k1+p)^2
% --   5|    --   D4 = -(k2+p)^2
%   \   |   /     D5 = -(k1-k2)^2
%  1 \  |  / 2
%     -----
%
% Limiting cases
% G2(n1,n2,n3,n4,0) = G1(n1,n3) G1(n2,n4)
% G2(0,n2,n3,n4,n5) = G1(n3,n5) G1(n2,n4+n3+n5-d/2)
% G2(n1,0,n3,n4,n5) = G1(n4,n5) G1(n1,n3+n4+n5-d/2)
% G2(n1,n2,0,n4,n5) = G1(n1,n5) G1(n4,n2+n1+n5-d/2)
% G2(n1,n2,n3,0,n5) = G1(n2,n5) G1(n3,n1+n2+n5-d/2)
%
% Recurrence relations
% d1.k1      (1) d-n3-n5-2n1 + n3 3+ (1  - 1-) + n5 5+ (2- - 1-) = 0
%           (1') d-n4-n5-2n2 + n4 4+ (1  - 2-) + n5 5+ (1- - 2-) = 0
%          (1'') d-n1-n5-2n3 + n1 1+ (1  - 3-) + n5 5+ (4- - 3-) = 0
%         (1''') d-n2-n5-2n4 + n2 2+ (1  - 4-) + n5 5+ (3- - 4-) = 0
% d1.(k1-k2) (2) d-n1-n3-2n5 + n1 1+ (2- - 5-) + n3 3+ (4- - 5-) = 0
%           (2') d-n2-n4-2n5 + n2 2+ (1- - 5-) + n4 4+ (3- - 5-) = 0
% Larin's relation d/dp.(k2+p)
%    (3) d/2+n4-n1-n2-n5 + (3d/2-n1-n2-n3-n4-n5) (4- - 2-) + n3 3+ (4- - 5-) = 0
%   (3') d/2+n1-n3-n4-n5 + (3d/2-n1-n2-n3-n4-n5) (1- - 3-) + n2 2+ (1- - 5-) = 0
%  (3'') d/2+n2-n3-n4-n5 + (3d/2-n1-n2-n3-n4-n5) (2- - 4-) + n1 1+ (2- - 5-) = 0
% (3''') d/2+n3-n1-n2-n5 + (3d/2-n1-n2-n3-n4-n5) (3- - 1-) + n4 4+ (3- - 5-) = 0

% 2-loop QCD
procedure G2(n1,n2,n3,n4,n5);
if max(n1,n2)<=0 or max(n1,n3)<=0 or max(n1,n5)<=0 or max(n2,n4)<=0
    or max(n2,n5)<=0 or max(n3,n4)<=0 or max(n3,n5)<=0 or max(n4,n5)<=0
then 0
else if n5=0 then G1(n1,n3)*G1(n2,n4)*B(1)
else if n1=0 then G1(n3,n5)*G1a(n4+n3+n5,n2)*B(2)
else if n2=0 then G1(n4,n5)*G1a(n3+n4+n5,n1)*B(2)
else if n3=0 then G1(n1,n5)*G1a(n2+n1+n5,n4)*B(2)
else if n4=0 then G1(n2,n5)*G1a(n1+n2+n5,n3)*B(2)
else if n5<0 then
    if      n1>1 then G2r5(n1,n2,n3,n4,n5)
    else if n2>1 then G2r5(n2,n1,n4,n3,n5)
    else if n3>1 then G2r5(n3,n4,n1,n2,n5)
    else if n4>1 then G2r5(n4,n3,n2,n1,n5)
    else              G2r(n5)
else if n1<0 then
    if n4<0 and n4>n1 then G2r1(n4,n3,n2,n1,n5)
    else                   G2r1(n1,n2,n3,n4,n5)
else if n4<0 then G2r1(n4,n3,n2,n1,n5)
else if n2<0 then
    if n3<0 and n3>n2 then G2r1(n3,n4,n1,n2,n5)
    else                   G2r1(n2,n1,n4,n3,n5)
else if n3<0 then G2r1(n3,n4,n1,n2,n5)
else if max(n1,n3)<max(n2,n4) then G2l(n2,n1,n4,n3,n5)
else G2l(n1,n2,n3,n4,n5)$

remember G2;

% lower n2, n4, n5: (2)
procedure G2l(n1,n2,n3,n4,n5);
(n1*(G2(n1+1,n2,n3,n4,n5-1)-G2(n1+1,n2-1,n3,n4,n5))
    +n3*(G2(n1,n2,n3+1,n4,n5-1)-G2(n1,n2,n3+1,n4-1,n5)))
/(d-n1-n3-2*n5)$

% raise n5 at n1>1: 1- 5+ (3'')
procedure G2r5(n1,n2,n3,n4,n5);
G2(n1,n2-1,n3,n4,n5+1)
+((d/2+n2-n3-n4-n5-1)*G2(n1-1,n2,n3,n4,n5+1)
    +(3/2*d-n1-n2-n3-n4-n5)*(G2(n1-1,n2-1,n3,n4,n5+1)-G2(n1-1,n2,n3,n4-1,n5+1)))
/(n1-1)$

% raise n5 at n1=n2=n3=n4
procedure G2r(n5);
-(d/2-n5-2)/(d-n5-3)*G2(1,1,1,1,n5+1)$

% raise n1: 1+ (3''')
procedure G2r1(n1,n2,n3,n4,n5);
G2(n1+1,n2,n3-1,n4,n5)
+((d/2+n3-n1-n2-n5-1)*G2(n1+1,n2,n3,n4,n5)
    +n4*(G2(n1+1,n2,n3-1,n4+1,n5)-G2(n1+1,n2,n3,n4+1,n5-1)))
/(3/2*d-n1-n2-n3-n4-n5-1)$

%      /|\        D1 = (k1+p).v   D3 = -k1^2
%   3 / | \ 4     D2 = (k2+p).v   D4 = -k2^2
%    / 5|  \                      D5 = -(k1-k2)^2
%   /   |   \
% =============
%    1     2
%
% Limiting cases
% I(n1,n2,n3,n4,0) = I(n1,n3) I(n2,n4)
% I(0,n2,n3,n4,n5) = G(n3,n5) I(n2,n4+n3+n5-d/2)
% I(n1,0,n3,n4,n5) = G(n4,n5) I(n1,n3+n4+n5-d/2)
% I(n1,n2,0,n4,n5) = I(n1,n5) I(n2+n1+2*n5-d,n4)
% I(n1,n2,n3,0,n5) = I(n2,n5) I(n1+n2+2*n5-d,n3)
%
% Recurrence relations:
% d1.v       (1) - 2 n1 1+ + n3 3+ (1- - 1) + n5 5+ (1- - 2-) = 0
%           (1') - 2 n2 2+ + n4 4+ (2- - 1) + n5 5+ (2- - 1-) = 0
% d1.k1      (2) d-n1-n5-2n3 + n1 1+ + n5 5+ (4- - 3-) = 0
%           (2') d-n2-n5-2n4 + n2 2+ + n5 5+ (3- - 4-) = 0
% d1.(k1-k2) (3) d-n1-n3-2n5 + n1 1+ 2- + n3 3+ (4- - 5-) = 0
%           (3') d-n2-n4-2n5 + n2 2+ 1- + n4 4+ (3- - 5-) = 0
% hom        (0) 2(d-n3-n4-n5)-n1-n2 + n1 1+ + n2 2+ = 0
% David's combination (3) - 2- (0)
%  (4) d-n1-n2-n3-2n5+1 - [2(d-n3-n4-n5)-n1-n2+1] 2- + n3 3+ (4- - 5-) = 0
% (4') d-n1-n2-n4-2n5+1 - [2(d-n3-n4-n5)-n1-n2+1] 1- + n4 4+ (3- - 5-) = 0

% 2-loop HQET
procedure I2(n1,n2,n3,n4,n5);
if max(n1,n2)<=0 or max(n1,n3)<=0 or max(n1,n5)<=0 or max(n2,n4)<=0
    or max(n2,n5)<=0 or max(n3,n4)<=0 or max(n3,n5)<=0 or max(n4,n5)<=0
then 0
else if n5=0 then I1(n1,n3)*I1(n2,n4)*B(1)
else if n1=0 then G1(n3,n5)*I1b(n2,n4+n3+n5)*B(2)
else if n2=0 then G1(n4,n5)*I1b(n1,n3+n4+n5)*B(2)
else if n3=0 then I1(n1,n5)*I1a(n2+n1+2*n5,n4)*B(2)
else if n4=0 then I1(n2,n5)*I1a(n1+n2+2*n5,n3)*B(2)
else if n1<0 then I2r1(n1,n2,n3,n4,n5)
else if n2<0 then I2r1(n2,n1,n4,n3,n5)
else if n3<0 then I2r3(n1,n2,n3,n4,n5)
else if n4<0 then I2r3(n2,n1,n4,n3,n5)
else if n5<0 then
    if      n3>1 then I2r53(n1,n2,n3,n4,n5)
    else if n4>1 then I2r53(n2,n1,n4,n3,n5)
    else if n1>1 then I2r51(n1,n2,n5)
    else if n2>1 then I2r51(n2,n1,n5)
    else              I2r5(n5)
else if max(n1,n3)<max(n2,n4) then I2l(n2,n1,n4,n3,n5)
else I2l(n1,n2,n3,n4,n5)$

remember I2;

% lower n2, n4, n5: (4)
procedure I2l(n1,n2,n3,n4,n5);
((2*(d-n3-n4-n5)-n1-n2+1)*I2(n1,n2-1,n3,n4,n5)
    +n3*(I2(n1,n2,n3+1,n4,n5-1)-I2(n1,n2,n3+1,n4-1,n5)))
/(d-n1-n2-n3-2*n5+1)$

% raise n1: 1+ (4')
procedure I2r1(n1,n2,n3,n4,n5);
((d-n1-n2-n4-2*n5)*I2(n1+1,n2,n3,n4,n5)
    +n4*(I2(n1+1,n2,n3-1,n4+1,n5)-I2(n1+1,n2,n3,n4+1,n5-1)))
/(2*(d-n3-n4-n5)-n1-n2)$

% raise n3: (4)
procedure I2r3(n1,n2,n3,n4,n5);
((2*(d-n3-n4-n5)-n1-n2+1)*I2(n1,n2-1,n3,n4,n5)
    +n3*(I2(n1,n2,n3+1,n4,n5-1)-I2(n1,n2,n3+1,n4-1,n5)))
/(d-n1-n2-n3-2*n5+1)$

% raise n5 at n3>1: 3+ 5- (4)
procedure I2r53(n1,n2,n3,n4,n5);
I2(n1,n2,n3,n4-1,n5+1)
+((d-n1-n2-n3-2*n5)*I2(n1,n2,n3-1,n4,n5+1)
    -(2*(d-n3-n4-n5)-n1-n2+1)*I2(n1,n2-1,n3-1,n4,n5+1))
/(n3-1)$

% raise n5 or lower n1 at n1>1, n3=n4=1: 1- (2)
procedure I2r51(n1,n2,n5);
(n5*(I2(n1-1,n2,0,1,n5+1)-I2(n1-1,n2,1,0,n5+1))
    -(d-n1-n5-1)*I2(n1-1,n2,1,1,n5))
/(n1-1)$

% raise n5 at n1=n2=n3=n4=n5:
procedure I2r5(n5);
(d-2*n5-4)/(2*(d-n5-3))*I2(1,1,1,1,n5+1)$

% I2(n1,n2,n3-d/2,n4,n5)
procedure I2a(n1,n2,n3,n4,n5);
if max(n1,n2)<=0 or max(n1,n5)<=0 or max(n2,n4)<=0 or max(n2,n5)<=0 or max(n4,n5)<=0
then 0
else if n5=0 then I1b(n1,n3)*I1(n2,n4)*B(2)
else if n1=0 then G1a(n3,n5)*I1e(n2,n4+n3+n5)*B(3)
else if n2=0 then G1(n4,n5)*I1e(n1,n3+n4+n5)*B(5)
else if n4=0 then I1(n2,n5)*I1d(n1+n2+2*n5,n3)*B(3)
else if n5<0 then I2ar5(n1,n2,n3,n4,n5)
else if n2<0 then I2ar2(n1,n2,n3,n4,n5)
else if n1<0 then I2ar1(n1,n2,n3,n4,n5)
else if n4<0 then I2ar4(n1,n2,n3,n4,n5)
else I2al(n1,n2,n3,n4,n5)$

remember I2a;

% lower n2, n4, n5: (4)
procedure I2al(n1,n2,n3,n4,n5);
((-d/2+n3)*(I2a(n1,n2,n3+1,n4,n5-1)-I2a(n1,n2,n3+1,n4-1,n5))
    +(3*d-2*(n3+n4+n5)-n1-n2+1)*I2a(n1,n2-1,n3,n4,n5))
/(3/2*d-n1-n2-n3-2*n5+1)$

% raise n5: 3- 5+ (4)
procedure I2ar5(n1,n2,n3,n4,n5);
I2a(n1,n2,n3,n4-1,n5+1)
+((3/2*d-n1-n2-n3-2*n5)*I2a(n1,n2,n3-1,n4,n5+1)
    -(3*d-2*(n3+n4+n5)-n1-n2+1)*I2a(n1,n2-1,n3-1,n4,n5+1))
/(-d/2+n3-1)$

% raise n2: 2+ (4)
procedure I2ar2(n1,n2,n3,n4,n5);
((3/2*d-n1-n2-n3-2*n5)*I2a(n1,n2+1,n3,n4,n5)
    +(-d/2+n3)*(I2a(n1,n2+1,n3+1,n4-1,n5)-I2a(n1,n2+1,n3+1,n4,n5-1)))
/(3*d-2*(n3+n4+n5)-n1-n2)$

%- raise n1: 1+ (4')
procedure I2ar1(n1,n2,n3,n4,n5);
((d-n1-n2-n4-2*n5)*I2a(n1+1,n2,n3,n4,n5)
    +n4*(I2a(n1+1,n2,n3-1,n4+1,n5)-I2a(n1+1,n2,n3,n4+1,n5-1)))
/(3*d-2*(n3+n4+n5)-n1-n2)$

% raise n4: 3- 4+ (4)
procedure I2ar4(n1,n2,n3,n4,n5);
I2a(n1,n2,n3,n4+1,n5-1)
+((3*d-2*(n3+n4+n5)-n1-n2+1)*I2a(n1,n2-1,n3-1,n4+1,n5)
    -(3/2*d-n1-n2-n3-2*n5+2)*I2a(n1,n2,n3-1,n4+1,n5))
/(-d/2+n3-1)$

% I2(n1-d,n2,n3,n4,n5)
procedure I2b(n1,n2,n3,n4,n5);
if max(n2,n4)<=0 or max(n2,n5)<=0 or max(n3,n4)<=0 or max(n3,n5)<=0 or max(n4,n5)<=0
then 0
else if n5=0 then I1a(n1,n3)*I1(n2,n4)*B(2)
else if n2=0 then G1(n4,n5)*I1d(n1,n3+n4+n5)*B(3)
else if n3=0 then I1a(n1,n5)*I1c(n2+n1+2*n5,n4)*B(3)
else if n4=0 then I1(n2,n5)*I1c(n1+n2+2*n5,n3)*B(4)
else if n5<0 then
    if      n3>1 then I2br53(n1,n2,n3,n4,n5)
    else if n4>1 then I2br54(n1,n2,n3,n4,n5)
    else if n2>1 then I2br52(n1,n2,n5)
    else              I2br5(n1,n5)
else if n2<0 then I2br2(n1,n2,n3,n4,n5)
else if n3<0 then
    if      n4>1 then I2br34(n1,n2,n3,n4,n5)
    else if n5>1 then I2br35(n1,n2,n3,n4,n5)
    else if n2>1 then I2br32(n1,n2,n3)
    else              I2br3(n1,n3)
else if n4<0 then
    if n3>1 then I2br43(n1,n2,n3,n4,n5)
    else if n5>1 then I2br45(n1,n2,n3,n4,n5)
    else if n2>1 then I2br42(n1,n2,n4)
    else              I2br4(n1,n4)
else I2bl(n1,n2,n3,n4,n5)$

remember I2b;

% lower n2, n4, n5: (4)
procedure I2bl(n1,n2,n3,n4,n5);
(n3*(I2b(n1,n2,n3+1,n4,n5-1)-I2b(n1,n2,n3+1,n4-1,n5))
    +(3*d-2*(n3+n4+n5)-n1-n2+1)*I2b(n1,n2-1,n3,n4,n5))
/(2*d-n1-n2-n3-2*n5+1)$

% raise n5 at n3>1: 3- 5+ (4)
procedure I2br53(n1,n2,n3,n4,n5);
I2b(n1,n2,n3,n4-1,n5+1)
+((2*d-n1-n2-n3-2*n5)*I2b(n1,n2,n3-1,n4,n5+1)
    -(3*d-2*(n3+n4+n5)-n1-n2+1)*I2b(n1,n2-1,n3-1,n4,n5+1))
/(n3-1)$

% raise n5 at n4>1: 4- 5+ (4')
procedure I2br54(n1,n2,n3,n4,n5);
I2b(n1,n2,n3-1,n4,n5+1)
+((2*d-n1-n2-n4-2*n5)*I2b(n1,n2,n3,n4-1,n5+1)
    -(3*d-2*(n3+n4+n5)-n1-n2+1)*I2b(n1-1,n2,n3,n4-1,n5+1))
/(n4-1)$

% lower n2 at n5<0, n2>1, n3=n4=1: 2- (2')
procedure I2br52(n1,n2,n5);
-(d-n2-n5-1)/(n2-1)*I2b(n1,n2-1,1,1,n5)$

% raise n5 or n4 at n2=n3=n4=1: 2 (2') + (1')
procedure I2br5(n1,n5);
(I2b(n1,1,1,2,n5)+n5*I2b(n1-1,1,1,1,n5+1))/(2*(d-n5-3))$

% raise n2: 2+ (4)
procedure I2br2(n1,n2,n3,n4,n5);
((2*d-n1-n2-n3-2*n5)*I2b(n1,n2+1,n3,n4,n5)
    +n3*(I2b(n1,n2+1,n3+1,n4-1,n5)-I2b(n1,n2+1,n3+1,n4,n5-1)))
/(3*d-2*(n3+n4+n5)-n1-n2)$

% raise n3 at n4>1: 3+ 4- (4')
procedure I2br34(n1,n2,n3,n4,n5);
I2b(n1,n2,n3+1,n4,n5-1)
+((3*d-2*(n3+n4+n5)-n1-n2+1)*I2b(n1-1,n2,n3+1,n4-1,n5)
    -(2*d-n1-n2-n4-2*n5+2)*I2b(n1,n2,n3+1,n4-1,n5))
/(n4-1)$

% raise n3 at n5>1: 3+ 5- (2)
procedure I2br35(n1,n2,n3,n4,n5);
I2b(n1,n2,n3+1,n4-1,n5)
+((2*d-n1-n5-2*n3-1)*I2b(n1,n2,n3+1,n4,n5-1)
    +(-d+n1)*I2b(n1+1,n2,n3+1,n4,n5-1))
/(n5-1)$

% lower n2 at n3<0, n2>1, n4=n5=1: 2- (0)
procedure I2br32(n1,n2,n3);
-((3*d-n1-n2-2*n3-3)*I2b(n1,n2-1,n3,1,1)
    +(-d+n1)*I2b(n1+1,n2-1,n3,1,1))
/(n2-1)$

% get trivial term n2=0 at n3<0, n2=n4=n5=1: (4)
procedure I2br3(n1,n3);
(3*d-n1-2*n3-4)/(2*d-n1-n3-2)*I2b(n1,0,n3,1,1)$

% raise n4 at n3>1: 3- 4+ (4)
procedure I2br43(n1,n2,n3,n4,n5);
I2b(n1,n2,n3,n4+1,n5-1)
+((3*d-2*(n3+n4+n5)-n1-n2+1)*I2b(n1,n2-1,n3-1,n4+1,n5)
    -(2*d-n1-n2-n3-2*n5+2)*I2b(n1,n2,n3-1,n4+1,n5))
/(n3-1)$

% raise n4 at n5>1: 4+ 5- (2)
procedure I2br45(n1,n2,n3,n4,n5);
I2b(n1,n2,n3-1,n4+1,n5)
-((2*d-n1-n5-2*n3+1)*I2b(n1,n2,n3,n4+1,n5-1)
    +(-d+n1)*I2b(n1+1,n2,n3,n4+1,n5-1))
/(n5-1)$

% lower n2 at n4<0, n3=n5=1: 2- (0)
procedure I2br42(n1,n2,n4);
-((3*d-n1-n2-2*n4-3)*I2b(n1,n2-1,1,n4,1)
    +(-d+n1)*I2b(n1+1,n2-1,1,n4,1))
/(n2-1)$

% raise n3 or n5 at n4<0, n2=n3=n5=1: 1- (1)
procedure I2br4(n1,n4);
(I2b(n1-2,1,2,n4,1)-I2b(n1-1,1,2,n4,1)+I2b(n1-2,1,1,n4,2))
/(2*(-d+n1-1))$

% I2(n1,n2,n3,n4,n5-d/2)
procedure I2c(n1,n2,n3,n4,n5);
if max(n1,n2)<=0 or max(n1,n3)<=0 or max(n2,n4)<=0 or max(n3,n4)<=0
then 0
else if n1=0 then G1a(n5,n3)*I1e(n2,n4+n3+n5)*B(3)
else if n2=0 then G1a(n5,n4)*I1e(n1,n3+n4+n5)*B(3)
else if n3=0 then I1b(n1,n5)*I1c(n2+n1+2*n5,n4)*B(3)
else if n4=0 then I1b(n2,n5)*I1c(n1+n2+2*n5,n3)*B(3)
else if n1<0 then I2cr1(n1,n2,n3,n4,n5)
else if n2<0 then I2cr1(n2,n1,n4,n3,n5)
else if n3<0 then I2cr3(n1,n2,n3,n4,n5)
else if n4<0 then I2cr3(n2,n1,n4,n3,n5)
else if n1>1 then I2cl1(n1,n2,n3,n4,n5)
else if n2>1 then I2cl1(n2,n1,n4,n3,n5)
else if n3>1 then I2cl3(n3,n4,n5)
else if n4>1 then I2cl3(n4,n3,n5)
else if n5=2 then B(6)
else if n5>2 then I2cl5(n5)
else I2cr5(n5)$

remember I2c;

% raise n1: 1+ (4')
procedure I2cr1(n1,n2,n3,n4,n5);
((2*d-n1-n2-n4-2*n5)*I2c(n1+1,n2,n3,n4,n5)
    +n4*(I2c(n1+1,n2,n3-1,n4+1,n5)-I2c(n1+1,n2,n3,n4+1,n5-1)))
/(3*d-2*(n3+n4+n5)-n1-n2)$

% raise n3: 3+ 5- (2)
procedure I2cr3(n1,n2,n3,n4,n5);
I2c(n1,n2,n3+1,n4-1,n5)
+((3/2*d-n1-n5-2*n3-1)*I2c(n1,n2,n3+1,n4,n5-1)
    +n1*I2c(n1+1,n2,n3+1,n4,n5-1))
/(-d/2+n5-1)$

% lower n1: 1- (2)
procedure I2cl1(n1,n2,n3,n4,n5);
((-d/2+n5)*(I2c(n1-1,n2,n3-1,n4,n5+1)-I2c(n1-1,n2,n3,n4-1,n5+1))
    -(3/2*d-n1-n5-2*n3+1)*I2c(n1-1,n2,n3,n4,n5))
/(n1-1)$

% lower n3 at n1=n2=1: 3- (1)
procedure I2cl3(n3,n4,n5);
I2c(0,1,n3,n4,n5)
+((-d/2+n5)*(I2c(0,1,n3-1,n4,n5+1)-I2c(1,0,n3-1,n4,n5+1))
    -2*I2c(2,1,n3-1,n4,n5))
/(n3-1)$

% lower n5 at n1=n2=n3=n4=1
procedure I2cl5(n5);
((3*d-2*n5-4)*I2c(1,1,1,1,n5-1)+(3*d-2*n5-5)*I2c(1,0,1,1,n5)
    +I2c(0,1,2,1,n5-1)-I2c(1,1,2,0,n5))
/(2*(d-n5-1))$

% raise n5 at n1=n2=n3=n4=1
procedure I2cr5(n5);
(2*(d-n5-2)*I2c(1,1,1,1,n5+1)-(3*d-2*n5-7)*I2c(1,0,1,1,n5+1)
    +I2c(1,1,2,0,n5+1)-I2c(0,1,2,1,n5))
/(3*d-2*n5-6)$

%     4          D1 = (k1+p).v      D4 = -k1^2
%    ---         D2 = (k2+p).v      D5 = -k2^2
%   /   \        D3 = (k1+k2+p).v
%  /   3 \ 2
% ============
%   1 \     /
%      \   /
%       ---
%        5
%
% Limiting cases
% J(n1,n2,0,n4,n5) = I(n1,n4) I(n2,n5)
% J(0,n2,n3,n4,n5) = I(n3,n4) I(n2+n3+2n4-d,n5)
% J(n1,0,n3,n4,n5) = I(n3,n5) I(n1+n3+2n5-d,n4)
%
% Recurrence relations
%       (0) 1 - 1- - 2- + 3- = 0
% d1.v  (1) - 2 n1 1+ - 2 n3 3+ + n4 4+ (1- - 1) = 0
%      (1') - 2 n2 2+ - 2 n3 3+ + n5 5+ (2- - 1) = 0
% d1.k1 (2) d-n1-n3-2n4 + n1 1+ + n3 3+ 2- = 0
%      (2') d-n2-n3-2n5 + n2 2+ + n3 3+ 1- = 0

% 2-loop J
procedure J2(n1,n2,n3,n4,n5);
if n4<=0 or n5<=0 or max(n1,n3)<=0 or max(n2,n3)<=0 then 0
else if n3=0 then I1(n1,n4)*I1(n2,n5)*B(1)
else if n1=0 then I1(n3,n4)*I1a(n2+n3+2*n4,n5)*B(2)
else if n2=0 then I1(n3,n5)*I1a(n1+n3+2*n5,n4)*B(2)
else if n3<0 then J2(n1-1,n2,n3+1,n4,n5)+J2(n1,n2-1,n3+1,n4,n5)-J2(n1,n2,n3+1,n4,n5)
else if n1<0 and not (n2<0 and n2>n1)
then J2(n1+1,n2,n3,n4,n5)-J2(n1+1,n2-1,n3,n4,n5)+J2(n1+1,n2,n3-1,n4,n5)
else if n2<0 then J2(n1,n2+1,n3,n4,n5)-J2(n1-1,n2+1,n3,n4,n5)+J2(n1,n2+1,n3-1,n4,n5)
else J2(n1-1,n2,n3,n4,n5)+J2(n1,n2-1,n3,n4,n5)-J2(n1,n2,n3-1,n4,n5)$

remember J2;

% J2(n1,n2,n3,n4-d/2,n5)
procedure J2a(n1,n2,n3,n4,n5);
if n5<=0 or max(n1,n3)<=0 or max(n2,n3)<=0 then 0
else if n3=0 then I1b(n1,n4)*I1(n2,n5)*B(2)
else if n1=0 then I1b(n3,n4)*I1c(n2+n3+2*n4,n5)*B(3)
else if n2=0 then I1(n3,n5)*I1d(n1+n3+2*n5,n4)*B(3)
else if n3<0 then J2a(n1-1,n2,n3+1,n4,n5)+J2a(n1,n2-1,n3+1,n4,n5)-J2a(n1,n2,n3+1,n4,n5)
else if n1<0 and not (n2<0 and n2>n1)
then J2a(n1+1,n2,n3,n4,n5)-J2a(n1+1,n2-1,n3,n4,n5)+J2a(n1+1,n2,n3-1,n4,n5)
else if n2<0 then J2a(n1,n2+1,n3,n4,n5)-J2a(n1-1,n2+1,n3,n4,n5)+J2a(n1,n2+1,n3-1,n4,n5)
else J2a(n1-1,n2,n3,n4,n5)+J2a(n1,n2-1,n3,n4,n5)-J2a(n1,n2,n3-1,n4,n5)$

remember J2a;

% J2(n1-d,n2,n3,n4,n5)
procedure J2b(n1,n2,n3,n4,n5);
if n4<=0 or n5<=0 or max(n2,n3)<=0 then 0
else if n3=0 then I1a(n1,n4)*I1(n2,n5)*B(2)
else if n2=0 then I1(n3,n5)*I1c(n1+n3+2*n5,n4)*B(4)
else if n3<0 then J2b(n1-1,n2,n3+1,n4,n5)+J2b(n1,n2-1,n3+1,n4,n5)-J2b(n1,n2,n3+1,n4,n5)
else if n2<0 then J2b(n1,n2+1,n3,n4,n5)-J2b(n1-1,n2+1,n3,n4,n5)+J2b(n1,n2+1,n3-1,n4,n5)
else % (2) - n1 1+ (0)
    ((-d+n1)*(J2b(n1+1,n2,n3-1,n4,n5)-J2b(n1+1,n2-1,n3,n4,n5))
        -n3*J2b(n1,n2-1,n3+1,n4,n5))
    /(d-n3-2*n4)$

remember J2b;

% J2(n1,n2,n3-d,n4,n5)
procedure J2c(n1,n2,n3,n4,n5);
if n4<=0 or n5<=0 then 0
else if n1=0 then I1a(n3,n4)*I1c(n2+n3+2*n4,n5)*B(3)
else if n2=0 then I1a(n3,n5)*I1c(n1+n3+2*n5,n4)*B(3)
else if n1<0 and not (n2<0 and n2>n1)
then J2c(n1+1,n2,n3,n4,n5)-J2c(n1+1,n2-1,n3,n4,n5)+J2c(n1+1,n2,n3-1,n4,n5)
else if n2<0 then J2c(n1,n2+1,n3,n4,n5)-J2c(n1-1,n2+1,n3,n4,n5)+J2c(n1,n2+1,n3-1,n4,n5)
else if n4>1 then J2cl4(n1,n2,n3,n4,n5)
else if n5>1 then J2cl4(n2,n1,n3,n5,n4)
else if n1>1 then J2cl1(n1,n2,n3)
else if n2>1 then J2cl1(n2,n1,n3)
else if n3=3 then B(7)
else if n3>3 then 2*J2c(0,1,n3,1,1)-J2c(1,1,n3-1,1,1)
else 2*J2c(0,1,n3+1,1,1)-J2c(1,1,n3+1,1,1)$

remember J2c;

% lower n4 or n1: 4- (1)
procedure J2cl4(n1,n2,n3,n4,n5);
J2c(n1-1,n2,n3,n4,n5)
-2*(n1*J2c(n1+1,n2,n3,n4-1,n5)+(-d+n3)*J2c(n1,n2,n3+1,n4-1,n5))/(n4-1)$

% lower n1 at n4=n5=1: 1- (2)
procedure J2cl1(n1,n2,n3);
-((2*d-n1-n3-1)*J2c(n1-1,n2,n3,1,1)+(-d+n3)*J2c(n1-1,n2-1,n3+1,1,1))/(n1-1)$

% J2 with numerator
procedure JJ2(n1,n2,n3,n4,n5,n0);
if n4<=0 or n5<=0 or max(n1,n3)<=0 or max(n2,n3)<=0 then 0
else if n0=0 then J2(n1,n2,n3,n4,n5)
else if n3=0 then JJ23(n1,n2,n4,n5,n0)
else if n1=0 then JJ21(n2,n3,n4,n5,n0)
else if n2=0 then JJ21(n1,n3,n5,n4,n0)
else if n3<0 then JJ2(n1-1,n2,n3+1,n4,n5,n0)+JJ2(n1,n2-1,n3+1,n4,n5,n0)-JJ2(n1,n2,n3+1,n4,n5,n0)
else if n1<0 and not (n2<0 and n2>n1)
then JJ2(n1+1,n2,n3,n4,n5,n0)-JJ2(n1+1,n2-1,n3,n4,n5,n0)+JJ2(n1+1,n2,n3-1,n4,n5,n0)
else if n2<0 then JJ2(n1,n2+1,n3,n4,n5,n0)-JJ2(n1-1,n2+1,n3,n4,n5,n0)+JJ2(n1,n2+1,n3-1,n4,n5,n0)
else JJ2(n1-1,n2,n3,n4,n5,n0)+JJ2(n1,n2-1,n3,n4,n5,n0)-JJ2(n1,n2,n3-1,n4,n5,n0)$

remember JJ2;

procedure JJ23(n1,n2,n4,n5,n0);
begin scalar p;
    p:=(!!5-!!3-!!4)^n0*(!!3*!!4*!!5)^2;
    for all m3,m4,m5 match !!3^m3*!!4^m4*!!5^m5=I2(n1,n2,n4+2-m3,n5+2-m4,2-m5);
    p:=p;
    for all m3,m4,m5 clear !!3^m3*!!4^m4*!!5^m5;
    return p
end$

procedure JJ21(n2,n3,n4,n5,n0);
begin scalar p;
    p:=(!!4-!!3+!!5)^n0*(!!3*!!4*!!5)^2;
    for all m3,m4,m5 match !!3^m3*!!4^m4*!!5^m5=I2(n3,n2,2-m3,n5+2-m4,n4+2-m5);
    p:=p;
    for all m3,m4,m5 clear !!3^m3*!!4^m4*!!5^m5;
    return p
end$

% Ia
%
%         6           D1 = (k1+p).v   D3 = -k1^2
%      /-----\        D2 = (k2+p).v   D4 = -k2^2
%     / \   / \                       D5 = -(k1-k2)^2
%    /  7\ /8  \                      D6 = -k3^2
%  3/     |     \4                    D7 = -(k1+k3)^2
%  /      |5     \                    D8 = -(k2+k3)^2
% =================
%     1       2
%
% Limiting cases
% I3a(0,n2,n3,n4,n5,n6,n7,n8) = G2(n3,n6,n5,n8,n7) I1(n2,n4+n3+n5+n6+n8+n7-d)
% I3a(n1,0,n3,n4,n5,n6,n7,n8) = G2(n4,n6,n5,n7,n8) I1(n1,n3+n4+n5+n6+n7+n8-d)
% I3a(n1,n2,n3,n4,n5,0,n7,n8) = G1(n7,n8) I2c(n1,n2,n3,n4,n5+n7+n8-d/2)
% I3a(n1,n2,n3,n4,n5,n6,0,n8) = G1(n6,n8) I2a(n2,n1,n4+n6+n8-d/2,n3,n5)
% I3a(n1,n2,n3,n4,n5,n6,n7,0) = G1(n6,n7) I2a(n1,n2,n3+n6+n7-d/2,n4,n5)
%
% Recurrence relations
% d3.k3      (1) d-n7-n8-2n6 + n7 7+ (3- - 6-) + n8 8+ (4- - 6-) = 0
% d3.(k3+k1) (2) d-n6-n8-2n7 + n6 6+ (3- - 7-) + n8 8+ (5- - 7-) = 0
%           (2') d-n6-n7-2n8 + n6 6+ (4- - 8-) + n7 7+ (5- - 8-) = 0
% d1.k1      (3) d-n1-n5-n7-2n3 + n1 1+ + n5 5+ (4- - 3-) + n7 7+ (6- - 3-) = 0
%           (3') d-n2-n5-n8-2n4 + n2 2+ + n5 5+ (3- - 4-) + n8 8+ (6- - 4-) = 0
% d1.(k1-k2) (4) d-n1-n3-n7-2n5 + n1 1+ 2- + n3 3+ (4- - 5-) + n7 7+ (8- - 5-) = 0
%           (4') d-n2-n4-n8-2n5 + n2 2+ 1- + n4 4+ (3- - 5-) + n8 8+ (7- - 5-) = 0
% hom        (0) 3d-n1-n2-2(n3+n4+n5+n6+n7+n8) + n1 1+ + n2 2+ = 0
% (d3-d1-d2).k1 + (0)
%  (5) 2(d-n5-n7-n8)-n2-n4-n6 + n2 2+ 1- + n4 4+ (3- - 5-) + n6 6+ (3- - 7-) = 0
% (5') 2(d-n5-n7-n8)-n1-n3-n6 + n1 1+ 2- + n3 3+ (4- - 5-) + n6 6+ (4- - 8-) = 0

procedure I3a(n1,n2,n3,n4,n5,n6,n7,n8);
if max(n1,n2)<=0 or max(n6,n7)<=0 or max(n6,n8)<=0 or max(n7,n8)<=0
    or max(n3,n7,n5)<=0 or max(n4,n8,n5)<=0 or max(n3,n6,n4)<=0
    or max(n1,n3,n7)<=0 or max(n1,n5,n7)<=0 or max(n3,n1,n5)<=0
    or max(n2,n4,n8)<=0 or max(n2,n5,n8)<=0 or max(n4,n2,n5)<=0
then 0
else if n1=0 then I1e(n2,n4+n3+n5+n6+n8+n7)*sub(B(1)=B(5),B(2)=B(3),G2(n3,n6,n5,n8,n7))
else if n2=0 then I1e(n1,n3+n4+n5+n6+n7+n8)*sub(B(1)=B(5),B(2)=B(3),G2(n4,n6,n5,n7,n8))
else if n6=0 then G1(n7,n8)*I2c(n1,n2,n3,n4,n5+n7+n8)
else if n7=0 then G1(n6,n8)*I2a(n2,n1,n4+n6+n8,n3,n5)
else if n8=0 then G1(n6,n7)*I2a(n1,n2,n3+n6+n7,n4,n5)
else if n1<0 then I3ar1(n1,n2,n3,n4,n5,n6,n7,n8)
else if n2<0 then I3ar1(n2,n1,n4,n3,n5,n6,n8,n7)
else if n6<0 then
    if      n7>1 then I3ar67(n1,n2,n3,n4,n5,n6,n7,n8)
    else if n8>1 then I3ar67(n2,n1,n4,n3,n5,n6,n8,n7)
    else              I3ar6(n1,n2,n3,n4,n5,n6)
else if n7<0 then I3ar7(n1,n2,n3,n4,n5,n6,n7,n8)
else if n8<0 then I3ar7(n2,n1,n4,n3,n5,n6,n8,n7)
else if n3=0 then J3a(n1,n2,n4,n5,n6,n7,n8)
else if n4=0 then J3a(n2,n1,n3,n5,n6,n8,n7)
else if n3<0 then I3ar3(n1,n2,n3,n4,n5,n6,n7,n8)
else if n4<0 then I3ar3(n2,n1,n4,n3,n5,n6,n8,n7)
else if n5=0 then J3b(n1,n2,n3,n4,n6,n7,n8)
else if n5<0 then
    if      n7>1 then I3ar57(n1,n2,n3,n4,n5,n6,n7,n8)
    else if n8>1 then I3ar57(n2,n1,n4,n3,n5,n6,n8,n7)
    else              I3ar5(n1,n2,n3,n4,n5,n6)
else if n6<=max(n5,n7,n8) then I3al6(n1,n2,n3,n4,n5,n6,n7,n8)
else if max(n3,n7)<=max(n4,n8) then I3al(n1,n2,n3,n4,n5,n6,n7,n8)
else I3al(n2,n1,n4,n3,n5,n6,n8,n7)$

remember I3a;

% lower n3, n4, n6: (1)
procedure I3al6(n1,n2,n3,n4,n5,n6,n7,n8);
(n7*(I3a(n1,n2,n3,n4,n5,n6-1,n7+1,n8)-I3a(n1,n2,n3-1,n4,n5,n6,n7+1,n8))
    +n8*(I3a(n1,n2,n3,n4,n5,n6-1,n7,n8+1)-I3a(n1,n2,n3,n4-1,n5,n6,n7,n8+1)))
/(d-n7-n8-2*n6)$

% lower n3, n5, n7: (2)
procedure I3al(n1,n2,n3,n4,n5,n6,n7,n8);
(n6*(I3a(n1,n2,n3,n4,n5,n6+1,n7-1,n8)-I3a(n1,n2,n3-1,n4,n5,n6+1,n7,n8))
    +n8*(I3a(n1,n2,n3,n4,n5,n6,n7-1,n8+1)-I3a(n1,n2,n3,n4,n5-1,n6,n7,n8+1)))
/(d-n6-n8-2*n7)$

% raise n1: (0) - 1+ (4')
procedure I3ar1(n1,n2,n3,n4,n5,n6,n7,n8);
((d-n1-n2-n4-n8-2*n5)*I3a(n1+1,n2,n3,n4,n5,n6,n7,n8)
    +n4*(I3a(n1+1,n2,n3-1,n4+1,n5,n6,n7,n8)-I3a(n1+1,n2,n3,n4+1,n5-1,n6,n7,n8))
    +n8*(I3a(n1+1,n2,n3,n4,n5,n6,n7-1,n8+1)-I3a(n1+1,n2,n3,n4,n5-1,n6,n7,n8+1)))
/(3*d-n1-n2-2*(n3+n4+n5+n6+n7+n8))$

% raise n6 at n7>1: 6+ 7- (3)
procedure I3ar67(n1,n2,n3,n4,n5,n6,n7,n8);
I3a(n1,n2,n3-1,n4,n5,n6+1,n7,n8)
+(n5*(I3a(n1,n2,n3-1,n4,n5+1,n6+1,n7-1,n8)-I3a(n1,n2,n3,n4-1,n5+1,n6+1,n7-1,n8))
    -n1*I3a(n1+1,n2,n3,n4,n5,n6+1,n7-1,n8)
    -(d-n1-n5-n7-2*n3+1)*I3a(n1,n2,n3,n4,n5,n6+1,n7-1,n8))
/(n7-1)$

% raise n6 or n8 at n7=n8=1: (2)
procedure I3ar6(n1,n2,n3,n4,n5,n6);
(n6*(I3a(n1,n2,n3,n4,n5,n6+1,0,1)-I3a(n1,n2,n3-1,n4,n5,n6+1,1,1))
    +I3a(n1,n2,n3,n4,n5,n6,0,2)-I3a(n1,n2,n3,n4,n5-1,n6,1,2))
/(d-n6-3)$

% raise n7
procedure I3ar7(n1,n2,n3,n4,n5,n6,n7,n8);
if      n8>1 then I3ar78(n1,n2,n3,n4,n5,n6,n7,n8)
else if n6>1 then I3ar76(n1,n2,n3,n4,n5,n6,n7,n8)
else              I3ar768(n1,n2,n3,n4,n5,n7)$

% raise n7 at n8>1: 7+ 8- (4')
procedure I3ar78(n1,n2,n3,n4,n5,n6,n7,n8);
I3a(n1,n2,n3,n4,n5-1,n6,n7+1,n8)
+(n4*(I3a(n1,n2,n3,n4+1,n5-1,n6,n7+1,n8-1)-I3a(n1,n2,n3-1,n4+1,n5,n6,n7+1,n8-1))
    -n2*I3a(n1-1,n2+1,n3,n4,n5,n6,n7+1,n8-1)
    -(d-n2-n4-n8-2*n5+1)*I3a(n1,n2,n3,n4,n5,n6,n7+1,n8-1))
/(n8-1)$

% raise n7 at n6>1: 7+ 6- (5)
procedure I3ar76(n1,n2,n3,n4,n5,n6,n7,n8);
I3a(n1,n2,n3-1,n4,n5,n6,n7+1,n8)
+(n4*(I3a(n1,n2,n3-1,n4+1,n5,n6-1,n7+1,n8)-I3a(n1,n2,n3,n4+1,n5-1,n6-1,n7+1,n8))
    +n2*I3a(n1-1,n2+1,n3,n4,n5,n6-1,n7+1,n8)
    +(2*(d-n5-n7-n8)-n2-n4-n6-1)*I3a(n1,n2,n3,n4,n5,n6-1,n7+1,n8))
/(n6-1)$

% raise n7 or n6 at n6=n8=1: (2')
procedure I3ar768(n1,n2,n3,n4,n5,n7);
(I3a(n1,n2,n3,n4,n5,2,n7,0)-I3a(n1,n2,n3,n4-1,n5,2,n7,1)
    +n7*(I3a(n1,n2,n3,n4,n5,1,n7+1,0)-I3a(n1,n2,n3,n4,n5-1,1,n7+1,1)))
/(d-n7-3)$

% raise n3
procedure I3ar3(n1,n2,n3,n4,n5,n6,n7,n8);
if      n6>1 then I3ar36(n1,n2,n3,n4,n5,n6,n7,n8)
else if n7>1 then I3ar37(n1,n2,n3,n4,n5,n6,n7,n8)
else              I3ar367(n1,n2,n3,n4,n5,n8)$

% raise n3 at n6>1: 3+ 6- (2)
procedure I3ar36(n1,n2,n3,n4,n5,n6,n7,n8);
I3a(n1,n2,n3+1,n4,n5,n6,n7-1,n8)
+(n8*(I3a(n1,n2,n3+1,n4,n5,n6-1,n7-1,n8+1)-I3a(n1,n2,n3+1,n4,n5-1,n6-1,n7,n8+1))
    -(d-n6-n8-2*n7+1)*I3a(n1,n2,n3+1,n4,n5,n6-1,n7,n8))
/(n6-1)$

% raise n3 at n7>1: 3+ 7- (1)
procedure I3ar37(n1,n2,n3,n4,n5,n6,n7,n8);
I3a(n1,n2,n3+1,n4,n5,n6-1,n7,n8)
+(n8*(I3a(n1,n2,n3+1,n4,n5,n6-1,n7-1,n8+1)-I3a(n1,n2,n3+1,n4-1,n5,n6,n7-1,n8+1))
    -(d-n7-n8-2*n6+1)*I3a(n1,n2,n3+1,n4,n5,n6,n7-1,n8))
/(n7-1)$

% raise n6 or n7 at n3<0, n6=n7=1: (2')
procedure I3ar367(n1,n2,n3,n4,n5,n8);
(I3a(n1,n2,n3,n4,n5,2,1,n8-1)-I3a(n1,n2,n3,n4-1,n5,2,1,n8)
    +I3a(n1,n2,n3,n4,n5,1,2,n8-1)-I3a(n1,n2,n3,n4,n5-1,1,2,n8))
/(d-2*n8-2)$

% raise n5 at n7>1: 5+ 7- (2')
procedure I3ar57(n1,n2,n3,n4,n5,n6,n7,n8);
I3a(n1,n2,n3,n4,n5+1,n6,n7,n8-1)
+(n6*(I3a(n1,n2,n3,n4,n5+1,n6+1,n7-1,n8-1)-I3a(n1,n2,n3,n4-1,n5+1,n6+1,n7-1,n8))
    -(d-n6-n7-2*n8+1)*I3a(n1,n2,n3,n4,n5+1,n6,n7-1,n8))
/(n7-1)$

% raise n7 or n8 at n5<0, n7=n8=1: (1)
procedure I3ar5(n1,n2,n3,n4,n5,n6);
(I3a(n1,n2,n3,n4,n5,n6-1,2,1)-I3a(n1,n2,n3-1,n4,n5,n6,2,1)
    +I3a(n1,n2,n3,n4,n5,n6-1,1,2)-I3a(n1,n2,n3,n4-1,n5,n6,1,2))
/(d-2*n6-2)$

% Ja                 n3=0
%
%        /|\
%       / | \
%      /  |8 \
%    6/  -|   \4
%    /  / |    \
%   / -7  |5    \
%  //     |      \
% =================
%      1     2
%
% Recurrence relations
% d1.(k1-k2) (1) d-n1-n7-2n5 + n1 1+ 2- + n7 7+ (8- - 5-) = 0
% (d3-d1-d2).k2 + (0)
%            (2) 2(d-n5-n7-n8)-n1-n6 + n1 1+ 2- + n6 6+ (4- - 8-) = 0
% d3.(k3+k2) (3) d-n6-n7-2n8 + n6 6+ (4- - 8-) + n7 7+ (5- - 8-) = 0
% hom        (0) 3d-n1-n2-2(n4+n5+n6+n7+n8) + n1 1+ + n2 2+ = 0

procedure J3a(n1,n2,n4,n5,n6,n7,n8);
if max(n1,n2)<=0 or max(n1,n5)<=0 or max(n1,n7)<=0 or max(n4,n6)<=0
    or max(n5,n7)<=0 or max(n6,n7)<=0 or max(n6,n8)<=0 or max(n7,n8)<=0
    or max(n4,n8,n5)<=0 or max(n2,n4,n8)<=0 or max(n2,n5,n8)<=0 or max(n4,n2,n5)<=0
then 0
else if n1=0 then G1(n5,n7)*G1a(n8+n5+n7,n6)*I1e(n2,n4+n5+n6+n7+n8)*B(3)
else if n6=0 then G1(n7,n8)*I1b(n1,n5+n7+n8)*I1c(n2+n1+2*(n5+n7+n8),n4)*B(3)
else if n7=0 then G1(n6,n8)*I1(n1,n5)*I1d(n2+n1+2*n5,n4+n6+n8)*B(3)
else if n2=0 then I1e(n1,n4+n5+n6+n7+n8)*sub(B(1)=B(5),B(2)=B(3),G2(n4,n6,n5,n7,n8))
else if n4=0 then I1c(n1+n2+2*(n7+n8+n5),n6)*sub(B(1)=B(4),B(2)=B(3),I2(n1,n2,n7,n8,n5))
else if n5=0 then I1(n1,n7)*I2b(n1+2*n7,n2,n6,n4,n8)
else if n8=0 then G1(n6,n7)*I2a(n1,n2,n6+n7,n4,n5)
else if n1<0 or n2<0 or n6<0 or n7<0 or n8<0 then I3a(n1,n2,0,n4,n5,n6,n7,n8)
else if n4>0 and not (n5>0 and n5<n4) then J3al4(n1,n2,n4,n5,n6,n7,n8)
else if n5>0 then J3al5(n1,n2,n4,n5,n6,n7,n8)
else if n6>1 then J3ar4(n1,n2,n4,n5,n6,n7,n8)
else if n7>1 then J3ar5(n1,n2,n4,n5,n6,n7,n8)
else if n2>1 then J3al2(n1,n2,n4,n5,n8)
else J3an(-n5,-n4,n1,n8)*B(4)$

remember J3a;

% lower n2, n4, n8: (2)
procedure J3al4(n1,n2,n4,n5,n6,n7,n8);
(n6*(J3a(n1,n2,n4,n5,n6+1,n7,n8-1)-J3a(n1,n2,n4-1,n5,n6+1,n7,n8))
    -n1*J3a(n1+1,n2-1,n4,n5,n6,n7,n8))
/(2*(d-n5-n7-n8)-n1-n6)$

% lower n2, n5, n8: (1)
procedure J3al5(n1,n2,n4,n5,n6,n7,n8);
(n7*(J3a(n1,n2,n4,n5-1,n6,n7+1,n8)-J3a(n1,n2,n4,n5,n6,n7+1,n8-1))
    -n1*J3a(n1+1,n2-1,n4,n5,n6,n7,n8))
/(d-n1-n7-2*n5)$

% raise n4 at n6>1: 4+ 6- (2)
procedure J3ar4(n1,n2,n4,n5,n6,n7,n8);
J3a(n1,n2,n4+1,n5,n6,n7,n8-1)
-((2*(d-n5-n7-n8)-n1-n6+1)*J3a(n1,n2,n4+1,n5,n6-1,n7,n8)
    +n1*J3a(n1+1,n2-1,n4+1,n5,n6-1,n7,n8))
/(n6-1)$

% raise n5 at n7>1: 5+ 7- (1)
procedure J3ar5(n1,n2,n4,n5,n6,n7,n8);
J3a(n1,n2,n4,n5+1,n6,n7,n8-1)
+((d-n1-n7-2*n5-1)*J3a(n1,n2,n4,n5+1,n6,n7-1,n8)
    +n1*J3a(n1+1,n2-1,n4,n5+1,n6,n7-1,n8))
/(n7-1)$

% lower n2 at n6=n7=1: 2- (0)
procedure J3al2(n1,n2,n4,n5,n8);
-((3*d-2*(n4+n5+n8)-n1-n2-3)*J3a(n1,n2-1,n4,n5,1,1,n8)
    +n1*J3a(n1+1,n2-1,n4,n5,1,1,n8))
/(n2-1)$

% J3a(n3,1,-n2,-n1,1,1,n4)
procedure J3an(n1,n2,n3,n4);
begin scalar s,c1,c2,c3,c4,l1,m,l2,l3;
    s:=0; l1:=0;
    c1:=(-1)^n1*II1(n3,1,n1,0)*II1(1,n4,n2,0)*I1c(2*(n4-n1)+n3-n2+3,1);
    repeat
    <<  c2:=c1; m:=0;
        repeat
        <<  c3:=c2; l2:=0;
            repeat
            <<  c4:=c3; l3:=0;
                repeat
                <<  s:=s+c4;
                    c4:=-c4*(n2-l2-l3)/(l3+1)*(2*(d-n4+n1-1)-n3+n2+l2+l3)
                        /(3*d-2*(n4-n1)-n3+n2+l2+l3-4);
                    l3:=l3+1;
                >>
                until c4=0;
                c3:=-c3*(n2-l2)*(n4-l1-m-l2-1)/(l2+1)*(2*(d-n4+n1-1)-n3+n2+l2)
                    /((3*d-2*(n4-n1)-n3+n2+l2-4)*(d-2*(n4-l1-m)+n2+l2));
                l2:=l2+1;
            >>
            until c3=0;
            c2:=c2*(n1-l1-2*m)*(n1-l1-2*m-1)*(n4-l1-m-1)/(m+1)*(d+2*(-n4+l1+m+n2))
                /((d+2*(n1-l1-m-2))*(d+2*(-n4+l1+m)+n2+1)*(d+2*(-n4+l1+m)+n2));
            m:=m+1;
        >>
        until c2=0;
        c1:=c1*(n1-l1)*(n4-l1-1)/(l1+1)*(d-n3+n1-l1-2)*(d+2*(-n4+l1+n2))
            /((d+2*(n1-l1-2))*(d+2*(-n4+l1)+n2+1)*(d+2*(-n4+l1)+n2));
        l1:=l1+1;
    >>
    until c1=0;
    return s
end$

%% J3a(n3,1,-n2,-n1,1,1,n4)
%procedure J3an(n1,n2,n3,n4);
%for l1:=0:n1 sum for m:=0:floor((n1-l1)/2) sum for l2:=0:n2 sum for l3:=0:n2-l2 sum
%    (-1)^(n1+l1+l3)*factorial(n1)*factorial(n2)/(factorial(l1)*factorial(m)
%        *factorial(n1-l1-2*m)*factorial(l2)*factorial(l3)*factorial(n2-l2-l3))
%    *II1(n3,1,n1-l1,m)*II1(1,n4-l1-m-l2,n2-l2,0)
%    *I1c(2*(n4-n1)+n3-n2-l2-l3+3,1)$

% Jb              n5=0
%
%       6
%     ------
%    /\    /\
%  3/ 7\  /8 \4
%  /    \/    \
% ==============
%    1      2
%
% Recurrence relations
% d1.k1 (1) d-n1-n7-2n3 + n1 1+ + n7 7+ (6- - 3-) = 0
%      (1') d-n2-n8-2n4 + n2 2+ + n8 8+ (6- - 4-) = 0
% d3.k3 (2) d-n7-n8-2n6 + n7 7+ (3- - 6-) + n8 8+ (4- - 6-) = 0
% hom   (0) 3d-n1-n2-2(n3+n4+n6+n7+n8) + n1 1+ + n2 2+ = 0

procedure J3b(n1,n2,n3,n4,n6,n7,n8);
if max(n1,n2)<=0 or max(n1,n3)<=0 or max(n1,n7)<=0 or max(n2,n4)<=0 or max(n2,n8)<=0
    or max(n3,n7)<=0 or max(n4,n8)<=0 or max(n6,n7)<=0 or max(n6,n8)<=0 or max(n7,n8)<=0
    or max(n3,n6,n4)<=0
then 0
else if n1=0 then G1(n3,n7)*G1a(n6+n3+n7,n8)*I1e(n2,n4+n8+n6+n3+n7)*B(3)
else if n2=0 then G1(n4,n8)*G1a(n6+n4+n8,n7)*I1e(n1,n3+n7+n6+n4+n8)*B(3)
else if n7=0 then G1(n6,n8)*I1(n1,n3)*I1b(n2,n4+n6+n8)*B(2)
else if n8=0 then G1(n6,n7)*I1(n2,n4)*I1b(n1,n3+n6+n7)*B(2)
else if n3=0 then I1(n1,n7)*I2b(n1+2*n7,n2,n6,n4,n8)
else if n4=0 then I1(n2,n8)*I2b(n2+2*n8,n1,n6,n3,n7)
else if n6=0 then G1(n7,n8)*I2c(n1,n2,n3,n4,n7+n8)
else if n1<0 or n2<0 or n6<0 or n7<0 or n8<0 or n3<0 or n4<0 then I3a(n1,n2,n3,n4,0,n6,n7,n8)
else J3bl(n1,n2,n3,n4,n6,n7,n8)$

remember J3b;

% lower n3, n4, n6: (2)
procedure J3bl(n1,n2,n3,n4,n6,n7,n8);
(n7*(J3b(n1,n2,n3,n4,n6-1,n7+1,n8)-J3b(n1,n2,n3-1,n4,n6,n7+1,n8))
    +n8*(J3b(n1,n2,n3,n4,n6-1,n7,n8+1)-J3b(n1,n2,n3,n4-1,n6,n7,n8+1)))
/(d-n7-n8-2*n6)$

% I3a with numerator N^n0   N=k3.v   (n0>=0)
% d1.v       (1) - 2 n1 1+ + n3 3+ (1- - 1) + n5 5+ (1- - 2-) + n7 7+ (1- - 1 + 0+) = 0
%           (1') - 2 n2 2+ + n4 4+ (2- - 1) + n5 5+ (2- - 1-) + n8 8+ (2- - 1 + 0+) = 0
% (d1+d2-d3).v + 2 (0)
% (2) 2(3d+n0-n1-n2-2(n3+n4+n5+n6+n7+n8)) + n3 3+ (1- - 1) + n4 4+ (2- - 1) - n6 6+ 0+ - 2n0 0- = 0
% d1.(k1+k3) (3) d-n1-n3-n5-2n7 + n1 1+ (1 - 0+) + n3 3+ (6- - 7-) + n5 5+ (8- - 7-) = 0
%           (3') d-n2-n4-n5-2n8 + n2 2+ (1 - 0+) + n4 4+ (6- - 8-) + n5 5+ (7- - 8-) = 0
% d3.(k3+k1) (4) d+n0-n6-n8-2n7 + n0 0- (1- - 1) + n6 6+ (3- - 7-) + n8 8+ (5- - 7-) = 0
%           (4') d+n0-n6-n7-2n8 + n0 0- (2- - 1) + n6 6+ (4- - 8-) + n7 7+ (5- - 8-) = 0
% hom        (0) 3d+n0-n1-n2-2(n3+n4+n5+n6+n7+n8) + n1 1+ + n2 2+ = 0

procedure II3a(n1,n2,n3,n4,n5,n6,n7,n8,n0);
if max(n1,n2)<=0 or max(n6,n7)<=0 or max(n6,n8)<=0 or max(n7,n8)<=0
    or max(n3,n7,n5)<=0 or max(n4,n8,n5)<=0 or max(n3,n6,n4)<=0
    or max(n1,n3,n7)<=0 or max(n1,n5,n7)<=0 or max(n3,n1,n5)<=0
    or max(n2,n4,n8)<=0 or max(n2,n5,n8)<=0 or max(n4,n2,n5)<=0
then 0
else if n0=0 then I3a(n1,n2,n3,n4,n5,n6,n7,n8)
else if n6 neq 1 then II3al6(n1,n2,n3,n4,n5,n6,n7,n8,n0)
else if n7 neq 1 then II3al7(n1,n2,n3,n4,n5,n7,n8,n0)
else if n8 neq 1 then II3al7(n2,n1,n4,n3,n5,n8,n7,n0)
else if n1 neq 1 then II3al1(n1,n2,n3,n4,n5,n0)
else if n2 neq 1 then II3al1(n2,n1,n4,n3,n5,n0)
else II3ar68(n3,n4,n5,n0)$

remember II3a;

% lower n0 at n6 neq 1: 6- 0- (2)
procedure II3al6(n1,n2,n3,n4,n5,n6,n7,n8,n0);
(2*(3*d+n0-n1-n2-2*(n3+n4+n5+n6+n7+n8)+1)*II3a(n1,n2,n3,n4,n5,n6-1,n7,n8,n0-1)
    +n3*(II3a(n1-1,n2,n3+1,n4,n5,n6-1,n7,n8,n0-1)-II3a(n1,n2,n3+1,n4,n5,n6-1,n7,n8,n0-1))
    +n4*(II3a(n1,n2-1,n3,n4+1,n5,n6-1,n7,n8,n0-1)-II3a(n1,n2,n3,n4+1,n5,n6-1,n7,n8,n0-1))
    -2*(n0-1)*II3a(n1,n2,n3,n4,n5,n6-1,n7,n8,n0-2))
/(n6-1)$

% lower n0 at n7 neq 1, n6=1: 7- 0- (1)
procedure II3al7(n1,n2,n3,n4,n5,n7,n8,n0);
II3a(n1,n2,n3,n4,n5,1,n7,n8,n0-1)-II3a(n1-1,n2,n3,n4,n5,1,n7,n8,n0-1)
+(n5*(II3a(n1,n2-1,n3,n4,n5+1,1,n7-1,n8,n0-1)-II3a(n1-1,n2,n3,n4,n5+1,1,n7-1,n8,n0-1))
    +n3*(II3a(n1,n2,n3+1,n4,n5,1,n7-1,n8,n0-1)-II3a(n1-1,n2,n3+1,n4,n5,1,n7-1,n8,n0-1))
    +2*n1*II3a(n1+1,n2,n3,n4,n5,1,n7-1,n8,n0-1))
/(n7-1)$

% lower n0 at n1 neq 1, n6=n7=n8=1: 1- 0- (3)
procedure II3al1(n1,n2,n3,n4,n5,n0);
II3a(n1,n2,n3,n4,n5,1,1,1,n0-1)
+(n3*(II3a(n1-1,n2,n3+1,n4,n5,0,1,1,n0-1)-II3a(n1-1,n2,n3+1,n4,n5,1,0,1,n0-1))
    +n5*(II3a(n1-1,n2,n3,n4,n5+1,1,1,0,n0-1)-II3a(n1-1,n2,n3,n4,n5+1,1,0,1,n0-1))
    +(d-n1-n3-n5-1)*II3a(n1-1,n2,n3,n4,n5,1,1,1,n0-1))
/(n1-1)$

% lower n0 or raise n6 or n8 at n1=n2=n6=n7=n8=1: (4)
procedure II3ar68(n3,n4,n5,n0);
(n0*(II3a(1,1,n3,n4,n5,1,1,1,n0-1)-II3a(0,1,n3,n4,n5,1,1,1,n0-1))
    +II3a(1,1,n3,n4,n5,2,0,1,n0)-II3a(1,1,n3-1,n4,n5,2,1,1,n0)
    +II3a(1,1,n3,n4,n5,1,0,2,n0)-II3a(1,1,n3,n4,n5-1,1,1,2,n0))
/(d+n0-4)$

% Ib
%
%       /|\         D1 = (k1+p).v   D4 = -k1^2
%      / | \        D2 = (k2+p).v   D5 = -k2^2
%     /  |8 \       D3 = (k3+p).v   D6 = -(k1-k3)^2
%   4/   |   \5                     D7 = -(k2-k3)^2
%   /  6/ \7  \                     D8 = -(k1-k2)^2
%  /   /   \   \
% ===============
%   1    3    2
%
% Limiting cases
% I3b(n1,n2,0,n4,n5,n6,n7,n8) = G1(n6,n7) I2c(n1,n2,n4,n5,n8+n6+n7-d/2)
% I3b(n1,n2,n3,0,n5,n6,n7,n8) = I2(n1,n3,n8,n7,n6) I1(n1+n2+n3+2(n6+n7+n8-d),n5)
% I3b(n1,n2,n3,n4,0,n6,n7,n8) = I2(n2,n3,n8,n6,n7) I1(n1+n2+n3+2(n6+n7+n8-d),n4)
% I3a(n1,n2,n3,n4,n5,0,n7,n8) = I1(n3,n7) I2b(n2+n3+2n7-d,n1,n5,n4,n8)
% I3a(n1,n2,n3,n4,n5,n6,0,n8) = I1(n3,n6) I2b(n1+n3+2n6-d,n2,n4,n5,n8)
%
% Recurrence relations
% d3.v       (1) - 2 n3 3+ + n6 6+ (3- - 1-) + n7 7+ (3- - 2-) = 0
% d1.v       (2) - 2 n1 1+ + n4 4+ (1- - 1) + n6 6+ (1- - 3-) + n8 8+ (1- - 2-) = 0
%           (2') - 2 n2 2+ + n5 5+ (2- - 1) + n7 7+ (2- - 3-) + n8 8+ (2- - 1-) = 0
% d3.(k3-k1) (3) d-n3-n7-2n6 + n3 3+ 1- + n7 7+ (8- - 6-) = 0
%           (3') d-n3-n6-2n7 + n3 3+ 2- + n6 6+ (8- - 7-) = 0
% d1.(k1-k2) (4) d-n1-n4-n6-2n8 + n1 1+ 2- + n4 4+ (5- - 8-) + n6 6+ (7- - 8-) = 0
%           (4') d-n2-n5-n7-2n8 + n2 2+ 1- + n5 5+ (4- - 8-) + n7 7+ (6- - 8-) = 0
% hom        (0) 3d-n1-n2-n3-2(n4+n5+n6+n7+n8) + n1 1+ + n2 2+ + n3 3+ = 0
% (0) - (d1+d2+d3).k1
%  (5) 2(d-n6-n7-n8)-n2-n3-n5 + (n2 2+ + n3 3+) 1- + n5 5+ (4- - 8-) = 0
% (5') 2(d-n6-n7-n8)-n1-n3-n4 + (n1 1+ + n3 3+) 2- + n4 4+ (5- - 8-) = 0
% (1) + (2) + (2') + 2(0)
%  (6) 2(3d-n1-n2-n3-2(n4+n5+n6+n7+n8)) + n4 4+ (1- - 1) + n5 5+ (2- - 1) = 0

procedure I3b(n1,n2,n3,n4,n5,n6,n7,n8);
if max(n3,n6)<=0 or max(n3,n7)<=0 or max(n6,n7)<=0 or max(n1,n2,n3)<=0
    or max(n1,n4,n8)<=0 or max(n1,n6,n8)<=0 or max(n4,n1,n6)<=0 or max(n4,n8,n6)<=0
    or max(n2,n5,n8)<=0 or max(n2,n7,n8)<=0 or max(n5,n2,n7)<=0 or max(n5,n8,n7)<=0
then 0
else if n3=0 then G1(n6,n7)*I2c(n1,n2,n4,n5,n8+n6+n7)
else if n4=0 then sub(B(1)=B(4),B(2)=B(3),I2(n1,n3,n8,n7,n6))*I1c(n1+n2+n3+2*(n6+n7+n8),n5)
else if n5=0 then sub(B(1)=B(4),B(2)=B(3),I2(n2,n3,n8,n6,n7))*I1c(n1+n2+n3+2*(n6+n7+n8),n4)
else if n6=0 then I1(n3,n7)*I2b(n2+n3+2*n7,n1,n5,n4,n8)
else if n7=0 then I1(n3,n6)*I2b(n1+n3+2*n6,n2,n4,n5,n8)
else if n3<0 then
    if      n6 neq 1 then I3br36(n1,n2,n3,n4,n5,n6,n7,n8)
    else if n7 neq 1 then I3br36(n2,n1,n3,n5,n4,n7,n6,n8)
    else                  I3br3(n1,n2,n3,n4,n5,n8)
else if n4<0 then I3br4(n1,n2,n3,n4,n5,n6,n7,n8)
else if n5<0 then I3br4(n2,n1,n3,n5,n4,n7,n6,n8)
else if n6<0 then I3br6(n1,n2,n3,n4,n5,n6,n7,n8)
else if n7<0 then I3br6(n2,n1,n3,n5,n4,n7,n6,n8)
else if n1=0 then J3a(n3,n2,n5,n7,n4,n6,n8)
else if n2=0 then J3a(n3,n1,n4,n6,n5,n7,n8)
else if n1<0 then I3br1(n1,n2,n3,n4,n5,n6,n7,n8)
else if n2<0 then I3br1(n2,n1,n3,n5,n4,n7,n6,n8)
else if n8=0 then J3c(n1,n2,n3,n4,n5,n6,n7)
else if n8<0 then
    if      n6 neq 1 then I3br86(n1,n2,n3,n4,n5,n6,n7,n8)
    else if n7 neq 1 then I3br86(n2,n1,n3,n5,n4,n7,n6,n8)
    else if n4 neq 1 then I3br84(n1,n2,n3,n4,n5,n8)
    else if n5 neq 1 then I3br84(n2,n1,n3,n5,n4,n8)
    else if n1 neq 1 then I3br81(n1,n2,n3,n8)
    else if n2 neq 1 then I3br81(n2,n1,n3,n8)
    else if n3 neq 1 then I3br83(n3,n8)
    else                  I3br8(n8)
else if max(n1,n6)<=max(n2,n7) then I3bl(n1,n2,n3,n4,n5,n6,n7,n8)
else I3bl(n2,n1,n3,n5,n4,n7,n6,n8)$

remember I3b;

% lower n1, n6, n8: (3)
procedure I3bl(n1,n2,n3,n4,n5,n6,n7,n8);
(n7*(I3b(n1,n2,n3,n4,n5,n6-1,n7+1,n8)-I3b(n1,n2,n3,n4,n5,n6,n7+1,n8-1))
    -n3*I3b(n1-1,n2,n3+1,n4,n5,n6,n7,n8))
/(d-n3-n7-2*n6)$

% raise n3 at n6 neq 1: 3+ 6- (2)
procedure I3br36(n1,n2,n3,n4,n5,n6,n7,n8);
I3b(n1-1,n2,n3+1,n4,n5,n6,n7,n8)
+(n8*(I3b(n1-1,n2,n3+1,n4,n5,n6-1,n7,n8+1)-I3b(n1,n2-1,n3+1,n4,n5,n6-1,n7,n8+1))
    +n4*(I3b(n1-1,n2,n3+1,n4+1,n5,n6-1,n7,n8)-I3b(n1,n2,n3+1,n4+1,n5,n6-1,n7,n8))
    -2*n1*I3b(n1+1,n2,n3+1,n4,n5,n6-1,n7,n8))
/(n6-1)$

% raise n3 or n7 at n6=n7=1: (3)
procedure I3br3(n1,n2,n3,n4,n5,n8);
(I3b(n1,n2,n3,n4,n5,0,2,n8)-I3b(n1,n2,n3,n4,n5,1,2,n8-1)
    -n3*I3b(n1-1,n2,n3+1,n4,n5,1,1,n8))
/(d-n3-3)$

% raise n4
procedure I3br4(n1,n2,n3,n4,n5,n6,n7,n8);
if n5 neq 1 then I3br45(n1,n2,n3,n4,n5,n6,n7,n8)
else I3br4a(n1,n2,n3,n4,n6,n7,n8)$

% raise n4 at n5 neq 1: 4+ 5- (4')
procedure I3br45(n1,n2,n3,n4,n5,n6,n7,n8);
I3b(n1,n2,n3,n4+1,n5,n6,n7,n8-1)
+(n7*(I3b(n1,n2,n3,n4+1,n5-1,n6,n7+1,n8-1)-I3b(n1,n2,n3,n4+1,n5-1,n6-1,n7+1,n8))
    -n2*I3b(n1-1,n2+1,n3,n4+1,n5-1,n6,n7,n8)
    -(d-n2-n5-n7-2*n8+1)*I3b(n1,n2,n3,n4+1,n5-1,n6,n7,n8))
/(n5-1)$

% raise n4 or n5 at n5=1: (6)
procedure I3br4a(n1,n2,n3,n4,n6,n7,n8);
(n4*(I3b(n1,n2,n3,n4+1,1,n6,n7,n8)-I3b(n1-1,n2,n3,n4+1,1,n6,n7,n8))
    +I3b(n1,n2,n3,n4,2,n6,n7,n8)-I3b(n1,n2-1,n3,n4,2,n6,n7,n8))
/(2*(3*d-n1-n2-n3-2*(n4+n6+n7+n8+1)))$

% raise n6
procedure I3br6(n1,n2,n3,n4,n5,n6,n7,n8);
if      n7 neq 1 then I3br67(n1,n2,n3,n4,n5,n6,n7,n8)
else if n3 neq 1 then I3br63(n1,n2,n3,n4,n5,n6,n8)
else                  I3br6a(n1,n2,n4,n5,n6,n8)$

% raise n6 at n7 neq 1: 6+ 7- (3)
procedure I3br67(n1,n2,n3,n4,n5,n6,n7,n8);
I3b(n1,n2,n3,n4,n5,n6+1,n7,n8-1)
+((d-n3-n7-2*n6-1)*I3b(n1,n2,n3,n4,n5,n6+1,n7-1,n8)
    +n3*I3b(n1-1,n2,n3+1,n4,n5,n6+1,n7-1,n8))
/(n7-1)$

% raise n6 or n7 at n3 neq 1, n7=1: 3- (1)
procedure I3br63(n1,n2,n3,n4,n5,n6,n8);
(n6*(I3b(n1,n2,n3-2,n4,n5,n6+1,1,n8)-I3b(n1-1,n2,n3-1,n4,n5,n6+1,1,n8))
    +I3b(n1,n2,n3-2,n4,n5,n6,2,n8)-I3b(n1,n2-1,n3-1,n4,n5,n6,2,n8))
/(2*(n3-1))$

% raise n6 or n3 at n3=n7=1: (3')
procedure I3br6a(n1,n2,n4,n5,n6,n8);
(n6*(I3b(n1,n2,1,n4,n5,n6+1,0,n8)-I3b(n1,n2,1,n4,n5,n6+1,1,n8-1))
    -I3b(n1,n2-1,2,n4,n5,n6,1,n8))
/(d-n6-3)$

% raise n1
procedure I3br1(n1,n2,n3,n4,n5,n6,n7,n8);
if      n8 neq 1 then I3br18(n1,n2,n3,n4,n5,n6,n7,n8)
else if n6 neq 1 then I3br16(n1,n2,n3,n4,n5,n6,n7)
else if n4 neq 1 then I3br14(n1,n2,n3,n4,n5,n7)
else if n2 neq 1 then I3br12(n1,n2,n3,n5,n7)
else if n3 neq 1 then I3br13(n1,n3,n5,n7)
else                  I3br1a(n1,n5,n7)$

% raise n1 at n8 neq 1: 1+ 8- (2')
procedure I3br18(n1,n2,n3,n4,n5,n6,n7,n8);
I3b(n1+1,n2-1,n3,n4,n5,n6,n7,n8)
+(n5*(I3b(n1+1,n2-1,n3,n4,n5+1,n6,n7,n8-1)-I3b(n1+1,n2,n3,n4,n5+1,n6,n7,n8-1))
    +n7*(I3b(n1+1,n2-1,n3,n4,n5,n6,n7+1,n8-1)-I3b(n1+1,n2,n3-1,n4,n5,n6,n7+1,n8-1))
    -2*n2*I3b(n1+1,n2+1,n3,n4,n5,n6,n7,n8-1))
/(n8-1)$

% raise n1 at n6 neq 1, n8=1: 1+ 6- (1)
procedure I3br16(n1,n2,n3,n4,n5,n6,n7);
I3b(n1+1,n2,n3-1,n4,n5,n6,n7,1)
+(n7*(I3b(n1+1,n2,n3-1,n4,n5,n6-1,n7+1,1)-I3b(n1+1,n2-1,n3,n4,n5,n6-1,n7+1,1))
    -2*n3*I3b(n1+1,n2,n3+1,n4,n5,n6-1,n7,1))
/(n6-1)$

% raise n1 at n4 neq 1, n6=n8=1: 1+ 4- (6)
procedure I3br14(n1,n2,n3,n4,n5,n7);
I3b(n1+1,n2,n3,n4,n5,1,n7,1)
+(n5*(I3b(n1+1,n2,n3,n4-1,n5+1,1,n7,1)-I3b(n1+1,n2-1,n3,n4-1,n5+1,1,n7,1))
    -2*(3*d-n1-n2-n3-2*(n4+n5+n7)-3)*I3b(n1+1,n2,n3,n4-1,n5,1,n7,1))
/(n4-1)$

% raise n1 at n2 neq 1, n4=n6=n8=1: 1+ 2- (4')
procedure I3br12(n1,n2,n3,n5,n7);
(n5*(I3b(n1+1,n2-1,n3,1,n5+1,1,n7,0)-I3b(n1+1,n2-1,n3,0,n5+1,1,n7,1))
    +n7*(I3b(n1+1,n2-1,n3,1,n5,1,n7+1,0)-I3b(n1+1,n2-1,n3,1,n5,0,n7+1,1))
    -(d-n2-n5-n7-1)*I3b(n1+1,n2-1,n3,1,n5,1,n7,1))
/(n2-1)$

% raise n1 at n3 neq 1, n2=n4=n6=n8=1: 1+ 3- (3)
procedure I3br13(n1,n3,n5,n7);
(n7*(I3b(n1+1,1,n3-1,1,n5,0,n7+1,1)-I3b(n1+1,1,n3-1,1,n5,1,n7+1,0))
    -(d-n3-n7-1)*I3b(n1+1,1,n3-1,1,n5,1,n7,1))
/(n3-1)$

% raise n1, n2 or n3 at n2=n3=n4=n6=n8=1: (0)
procedure I3br1a(n1,n5,n7);
-(n1*I3b(n1+1,1,1,1,n5,1,n7,1)+I3b(n1,2,1,1,n5,1,n7,1)+I3b(n1,1,2,1,n5,1,n7,1))
/(3*d-n1-2*(n5+n7)-8)$

% raise n8 at n6 neq 1: 8+ 6- (3')
procedure I3br86(n1,n2,n3,n4,n5,n6,n7,n8);
I3b(n1,n2,n3,n4,n5,n6,n7-1,n8+1)
-(n3*I3b(n1,n2-1,n3+1,n4,n5,n6-1,n7,n8+1)
    +(d-n3-n6-2*n7+1)*I3b(n1,n2,n3,n4,n5,n6-1,n7,n8+1))
/(n6-1)$

% raise n8 at n4 neq 1, n6=n7=1: 8+ 4- (5')
procedure I3br84(n1,n2,n3,n4,n5,n8);
I3b(n1,n2,n3,n4,n5-1,1,1,n8+1)
+(n1*I3b(n1+1,n2-1,n3,n4-1,n5,1,1,n8+1)+n3*I3b(n1,n2-1,n3+1,n4-1,n5,1,1,n8+1)
    +(2*(d-n8)-n1-n3-n4-5)*I3b(n1,n2,n3,n4-1,n5,1,1,n8+1))
/(n4-1)$

% raise n8 or n4 or n6 at n1 neq 1, n4=n5=n6=n7=1: 1- (2)
procedure I3br81(n1,n2,n3,n8);
(I3b(n1-2,n2,n3,2,1,1,1,n8)-I3b(n1-1,n2,n3,2,1,1,1,n8)
    +I3b(n1-2,n2,n3,1,1,2,1,n8)-I3b(n1-1,n2,n3-1,1,1,2,1,n8)
    +n8*(I3b(n1-2,n2,n3,1,1,1,1,n8+1)-I3b(n1-1,n2-1,n3,1,1,1,1,n8+1)))
/(2*(n1-1))$

% raise n6 or n7 at n3 neq 1, n1=n2=n4=n5=n6=n7=1: 3- (1)
procedure I3br83(n3,n8);
(I3b(1,1,n3-2,1,1,2,1,n8)-I3b(0,1,n3-1,1,1,2,1,n8)
    +I3b(1,1,n3-2,1,1,1,2,n8)-I3b(1,0,n3-1,1,1,1,2,n8))
/(2*(n3-1))$

% raise n1 or n2 or n3 at n1=n2=n3=n4=n5=n6=n7=1: (0)
procedure I3br8(n8);
-(I3b(2,1,1,1,1,1,1,n8)+I3b(1,2,1,1,1,1,1,n8)+I3b(1,1,2,1,1,1,1,n8))
/(3*d-2*n8-11)$

% Jc               n8=0
%
%       /|\
%      // \\
%     / | | \
%    / /   \ \
%  4/ 6|   |7 \5
%  /  /     \  \
% ===============
%   1    3    2
%
% Recurrence relations
% d1.v (1) - 2 n1 1+ + n4 4+ (1- - 1) + n6 6+ (1- - 3-) = 0
%     (1') - 2 n2 2+ + n5 5+ (2- - 1) + n7 7+ (2- - 3-) = 0
% d3.v (2) - 2 n3 3+ + n6 6+ (3- - 1-) + n7 7+ (3- - 2-) = 0
% hom  (0) 3d-n1-n2-n3-2(n4+n5+n6+n7) + n1 1+ + n2 2+ + n3 3+ = 0
% (1) + (1') + (2) + 2(0)                           (3)
% 2(3d-n1-n2-n3-2(n4+n5+n6+n7)) + n4 4+ (1- - 1) + n5 5+ (2- - 1) = 0
% n1=n2=n3=1:
% (n4-1) 6- d1.k1 - (n6-1) 4- d1.(k1-k3)            (4)
% (n4-1) (2(d-2n4-1) - n4 4+ (1 - 1-)) 6- - 2 (n6-1) (d-2n6-1 + 1+3-) 4-
%     + (n4-1) (n6-1) (1- - 3-) = 0
% (n6-1) 7- d3.(k3-k1) - (n7-1) 6- d3.(k3-k2)       (5)
% (n6-1) (d-2n6-1 + 3+ 1-) 7- - (n7-1) (d-2n7-1 + 3+ 2-) 6- = 0
% (n4-1) 5- (d1+d2+d3).k1 - (n5-1) 4- (d1+d2+d3).k2 (6)
% (n4-1) (2(d-n5-n6-n7) + (2+ + 3+) 1-) 5- - (n5-1) (2(d-n4-n6-n7) + (1+ + 3+) 2-) 4- = 0
% (n5-1) 6- d3.(k3-k2) - (n6-1) 5- (d1+d2+d3).k1    (7)
% (n5-1) (d-n6-2n7 + 3+ 2-) 6- + (n6-1) (2(d-n6-n7)-n5-1 + (2+ + 3+) 1-) 5-
%     + (n5-1) (n6-1) (4- - 7-) = 0
% (n4-1) 6- d3.(k3-k2) - (n6-1) 4- (d1+d2+d3).k2    (8)
% (n4-1) (d-n6-2n7 + 3+ 2-) 6- + (n6-1) (2(d-n6-n7)-n4-1 + (1+ + 3+) 2-) 4-
%     + (n4-1) (n6-1) (5- - 7-) = 0
% (n4-1) 7- (d1+d3).k1 - (n7-1) 4- (d1+d3).(k3-k2)  (9)
% (n4-1) (2(d-2n4-1 - 3+ 1-) - n4 4+ (1 - 1-) + (n7-1) 6+ (3- - 2-)) 7-
%     - 2 (n7-1) (d-2n7-1 - 1+ 3- + (1+ + 3+) 2-) 4- = 0

procedure J3c(n1,n2,n3,n4,n5,n6,n7);
if max(n3,n6)<=0 or max(n3,n7)<=0 or max(n6,n7)<=0
    or max(n1,n4)<=0 or max(n1,n6)<=0 or max(n4,n6)<=0
    or max(n2,n5)<=0 or max(n2,n7)<=0 or max(n5,n7)<=0
    or max(n4,n5)<=0 or max(n4,n7)<=0 or max(n5,n6)<=0 or max(n1,n2,n3)<=0
then 0
else if n1=0 then G1(n4,n6)*I2a(n3,n2,n4+n6,n5,n7)
else if n2=0 then G1(n5,n7)*I2a(n3,n1,n5+n7,n4,n6)
else if n3=0 then G1(n6,n7)*I2c(n1,n2,n4,n5,n6+n7)
else if n4=0 then I1(n1,n6)*I1a(n3+n1+2*n6,n7)*I1c(n2+n3+n1+2*(n7+n6),n5)*B(3)
else if n5=0 then I1(n2,n7)*I1a(n3+n2+2*n7,n6)*I1c(n1+n3+n2+2*(n6+n7),n4)*B(3)
else if n6=0 then I1(n1,n4)*I1(n3,n7)*I1a(n2+n3+2*n7,n5)*B(2)
else if n7=0 then I1(n2,n5)*I1(n3,n6)*I1a(n1+n3+2*n6,n4)*B(2)
else if n1<0 or n2<0 or n3<0 or n4<0 or n5<0 or n6<0 or n7<0 then I3b(n1,n2,n3,n4,n5,n6,n7,0)
else if n1>1 then J3cl1(n1,n2,n3,n4,n5,n6,n7)
else if n2>1 then J3cl1(n2,n1,n3,n5,n4,n7,n6)
else if n3>1 then J3cl3(n3,n4,n5,n6,n7)
else if n6>1 then J3cl6(n4,n5,n6,n7)
else if n7>1 then J3cl6(n5,n4,n7,n6)
else if n4>1 then J3cl4(n4,n5)
else if n5>1 then J3cl4(n5,n4)
else B(8)$

remember J3c;

% lower n1 at n1>1: 1- (1)
procedure J3cl1(n1,n2,n3,n4,n5,n6,n7);
(n4*(J3c(n1-2,n2,n3,n4+1,n5,n6,n7)-J3c(n1-1,n2,n3,n4+1,n5,n6,n7))
    +n6*(J3c(n1-2,n2,n3,n4,n5,n6+1,n7)-J3c(n1-1,n2,n3-1,n4,n5,n6+1,n7)))
/(2*(n1-1))$

% lower n3 at n3>1, n1=n2=1: 3- (2)
procedure J3cl3(n3,n4,n5,n6,n7);
(n6*(J3c(1,1,n3-2,n4,n5,n6+1,n7)-J3c(0,1,n3-1,n4,n5,n6+1,n7))
    +n7*(J3c(1,1,n3-2,n4,n5,n6,n7+1)-J3c(1,0,n3-1,n4,n5,n6,n7+1)))
/(2*(n3-1))$

% lower n6 at n6>1, n1=n2=n3=1: 4+ (4)
procedure J3cl6(n4,n5,n6,n7);
(n4/2/(n6-1)*((n4+1)*(J3c(0,1,1,n4+2,n5,n6-1,n7)-J3c(1,1,1,n4+2,n5,n6-1,n7))
        +2*(d-2*n4-3)*J3c(1,1,1,n4+1,n5,n6-1,n7))
    -n4/2*(J3c(1,1,0,n4+1,n5,n6,n7)-J3c(0,1,1,n4+1,n5,n6,n7))-J3c(2,1,0,n4,n5,n6,n7))
/(d-2*n6-1)$

% lower n4 at n4>1, n1=n2=n3=n6=n7=1: 4- (3), 5+ (6)
procedure J3cl4(n4,n5);
((4*(d-n4-2)*(3*d-2*(n4+n5)-5)*J3c(1,1,1,n4-1,n5,1,1)
        +n5*(J3c(2,0,1,n4-1,n5+1,1,1)+J3c(1,0,2,n4-1,n5+1,1,1)
            +2*(d-n4-2)*J3c(1,0,1,n4-1,n5+1,1,1)))/(n4-1)
    -J3c(0,2,1,n4,n5,1,1)-J3c(0,1,2,n4,n5,1,1)+2*(d-n4-2)*J3c(0,1,1,n4,n5,1,1))
/(2*(2*d-n4-n5-5))$

% I3b with numerator N^n0   N=-k3^2   (n0>=0)
% d1.(k1-k3) (1) d-n1-n4-n8-2n6 + n1 1+ 3- + n4 4+ (0+ - 6-) + n8 8+ (7- - 6-) = 0
%           (1') d-n2-n5-n8-2n7 + n2 2+ 3- + n5 5+ (0+ - 7-) + n8 8+ (6- - 7-) = 0
% d1.k1      (2) d-n1-n6-n8-2n4 + n1 1+ + n6 6+ (0+ - 4-) + n8 8+ (5- - 4-) = 0
%           (2') d-n2-n7-n8-2n5 + n2 2+ + n7 7+ (0+ - 5-) + n8 8+ (4- - 5-) = 0
% d3.v       (3) - n0 0- (3- - 1) - 2 n3 3+ + n6 6+ (3- - 1-) + n7 7+ (3- - 2-) = 0
% d3.(k3-k1) (4) d+n0-n3-n7-2n6 + n0 0- (6- - 4-) + n3 3+ 1- + n7 7+ (8- - 6-) = 0

procedure II3b(n1,n2,n3,n4,n5,n6,n7,n8,n0);
if max(n3,n6)<=0 or max(n3,n7)<=0 or max(n6,n7)<=0 or max(n1,n2,n3)<=0
    or max(n1,n4,n8)<=0 or max(n1,n6,n8)<=0 or max(n4,n1,n6)<=0 or max(n4,n8,n6)<=0
    or max(n2,n5,n8)<=0 or max(n2,n7,n8)<=0 or max(n5,n2,n7)<=0 or max(n5,n8,n7)<=0
then 0
else if n0=0 then I3b(n1,n2,n3,n4,n5,n6,n7,n8)
else if n4 neq 1 then II3bl04(n1,n2,n3,n4,n5,n6,n7,n8,n0)
else if n5 neq 1 then II3bl04(n2,n1,n3,n5,n4,n7,n6,n8,n0)
else if n6 neq 1 then II3bl06(n1,n2,n3,n6,n7,n8,n0)
else if n7 neq 1 then II3bl06(n2,n1,n3,n7,n6,n8,n0)
else if n3 neq 1 then II3bl03(n1,n2,n3,n8,n0)
else II3bl0(n1,n2,n8,n0)$

% lower n0 at n4 neq 1: 0- 4- (1)
procedure II3bl04(n1,n2,n3,n4,n5,n6,n7,n8,n0);
II3b(n1,n2,n3,n4,n5,n6-1,n7,n8,n0-1)
+(n8*(II3b(n1,n2,n3,n4-1,n5,n6-1,n7,n8+1,n0-1)-II3b(n1,n2,n3,n4-1,n5,n6,n7-1,n8+1,n0-1))
    -n1*II3b(n1+1,n2,n3-1,n4-1,n5,n6,n7,n8,n0-1)
    -(d-n1-n4-n8-2*n6+1)*II3b(n1,n2,n3,n4-1,n5,n6,n7,n8,n0-1))
/(n4-1)$

% lower n0 at n6 neq 1, n4=n5=1: 0- 6- (2)
procedure II3bl06(n1,n2,n3,n6,n7,n8,n0);
II3b(n1,n2,n3,0,1,n6,n7,n8,n0-1)
+(n8*(II3b(n1,n2,n3,0,1,n6-1,n7,n8+1,n0-1)-II3b(n1,n2,n3,1,0,n6-1,n7,n8+1,n0-1))
    -n1*II3b(n1+1,n2,n3,1,1,n6-1,n7,n8,n0-1)
    -(d-n1-n6-n8-1)*II3b(n1,n2,n3,1,1,n6-1,n7,n8,n0-1))
/(n6-1)$

% lower n0 or raise n6 or n7 at n3 neq 1, n4=n5=n6=n7=1: 3- (3)
procedure II3bl03(n1,n2,n3,n8,n0);
(n0*(II3b(n1,n2,n3-1,1,1,1,1,n8,n0-1)-II3b(n1,n2,n3-2,1,1,1,1,n8,n0-1))
    +II3b(n1,n2,n3-2,1,1,2,1,n8,n0)-II3b(n1-1,n2,n3-1,1,1,2,1,n8,n0)
    +II3b(n1,n2,n3-2,1,1,1,2,n8,n0)-II3b(n1,n2-1,n3-1,1,1,1,2,n8,n0))
/(2*(n3-1))$

% lower n0 or raise n3 or n7 at n3=n4=n5=n6=n7=1: (4)
procedure II3bl0(n1,n2,n8,n0);
(n0*(II3b(n1,n2,1,0,1,1,1,n8,n0-1)-II3b(n1,n2,1,1,1,0,1,n8,n0-1))
    +II3b(n1,n2,1,1,1,0,2,n8,n0)-II3b(n1,n2,1,1,1,1,2,n8-1,n0)
    -II3b(n1-1,n2,2,1,1,1,1,n8,n0))
/(d+n0-4)$

% Ic
%
%        8          D1 = (k1+p).v   D4 = -k1^2
%     /-----\       D2 = (k2+p).v   D5 = -k2^2
%    / |   | \      D3 = (k3+p).v   D6 = -(k1-k3)^2
%  4/  |6 7|  \5                    D7 = -(k2-k3)^2
%  /   |   |   \                    D8 = -k3^2
% ===============
%    1   3   2
%
% Limiting cases
% I3c(0,n2,n3,n4,n5,n6,n7,n8) = G1(n4,n6) I2a(n3,n2,n8+n4+n6-d/2,n5,n7)
% I3c(n1,0,n3,n4,n5,n6,n7,n8) = G1(n5,n7) I2a(n3,n1,n8+n5+n7-d/2,n4,n6)
% I3c(n1,n2,n3,0,n5,n6,n7,n8) = I1(n1,n6) I2b(n3+n1+2n6-d,n2,n8,n5,n7)
% I3c(n1,n2,n3,n4,0,n6,n7,n8) = I1(n2,n7) I2b(n3+n2+2n7-d,n1,n8,n4,n6)
% I3c(n1,n2,n3,n4,n5,0,n7,n8) = I1(n1,n4) I2(n3,n2,n8,n5,n7)
% I3c(n1,n2,n3,n4,n5,n6,0,n8) = I1(n2,n5) I2(n3,n1,n8,n4,n6)
%
% Recurrence relations
% d1.v       (1) - 2 n1 1+ + n4 4+ (1- - 1) + n6 6+ (1- - 3-) = 0
%           (1') - 2 n2 2+ + n5 5+ (2- - 1) + n7 7+ (2- - 3-) = 0
% d3.v       (2) - 2 n3 3+ + n6 6+ (3- - 1-) + n7 7+ (3- - 2-) + n8 8+ (3- - 1) = 0
% d1.k1      (3) d-n1-n6-2n4 + n1 1+ + n6 6+ (8- - 4-) = 0
%           (3') d-n2-n7-2n5 + n2 2+ + n7 7+ (8- - 5-) = 0
% d1.(k1-k3) (4) d-n1-n4-2n6 + n1 1+ 3- + n4 4+ (8- - 6-) = 0
%           (4') d-n2-n5-2n7 + n2 2+ 3- + n5 5+ (8- - 7-) = 0
% d3.k3      (5) d-n3-n6-n7-2n8 + n3 3+ + n6 6+ (4- - 8-) + n7 7+ (5- - 8-) = 0
% hom        (0) 3d-n1-n2-n3-2(n4+n5+n6+n7+n8) + n1 1+ + n2 2+ + n3 3+ = 0
% (1)+(1')+(2)+2(0)
% (6) 2(3d-n1-n2-n3-2(n4+n5+n6+n7+n8)) + n4 4+ (1- - 1) + n5 5+ (2- - 1) + n8 8+ (3- - 1) = 0

procedure I3c(n1,n2,n3,n4,n5,n6,n7,n8);
if max(n1,n4)<=0 or max(n1,n6)<=0 or max(n4,n6)<=0
    or max(n2,n5)<=0 or max(n2,n7)<=0 or max(n5,n7)<=0
    or max(n1,n3,n2)<=0 or max(n6,n3,n7)<=0 or max(n3,n6,n8)<=0 or max(n3,n7,n8)<=0
    or max(n6,n8,n7)<=0 or max(n4,n8,n5)<=0 or max(n4,n8,n7)<=0 or max(n5,n8,n6)<=0
then 0
else if n1=0 then G1(n4,n6)*I2a(n3,n2,n8+n4+n6,n5,n7)
else if n2=0 then G1(n5,n7)*I2a(n3,n1,n8+n5+n7,n4,n6)
else if n4=0 then I1(n1,n6)*I2b(n3+n1+2*n6,n2,n8,n5,n7)
else if n5=0 then I1(n2,n7)*I2b(n3+n2+2*n7,n1,n8,n4,n6)
else if n6=0 then I1(n1,n4)*I2(n3,n2,n8,n5,n7)
else if n7=0 then I1(n2,n5)*I2(n3,n1,n8,n4,n6)
else if n1<0 then I3cr1(n1,n2,n3,n4,n5,n6,n7,n8)
else if n2<0 then I3cr1(n2,n1,n3,n5,n4,n7,n6,n8)
else if n4<0 then I3cr4(n1,n2,n3,n4,n5,n6,n7,n8)
else if n5<0 then I3cr4(n2,n1,n3,n5,n4,n7,n6,n8)
else if n6<0 then I3cr6(n1,n2,n3,n4,n5,n6,n7,n8)
else if n7<0 then I3cr6(n2,n1,n3,n5,n4,n7,n6,n8)
else if n3=0 then J3b(n1,n2,n4,n5,n8,n6,n7)
else if n3<0 then
    if      n1 neq 1 then I3cr31(n1,n2,n3,n4,n5,n6,n7,n8)
    else if n2 neq 1 then I3cr31(n2,n1,n3,n5,n4,n7,n6,n8)
    else if n6 neq 1 then I3cr36(n3,n4,n5,n6,n7,n8)
    else if n7 neq 1 then I3cr36(n3,n5,n4,n7,n6,n8)
    else if n8 neq 1 then I3cr38(n3,n4,n5,n8)
    else                  I3cr3(n3,n4,n5)
else if n8=0 then J3c(n1,n2,n3,n4,n5,n6,n7)
else if n8<0 then
    if      n6 neq 1 then I3cr86(n1,n2,n3,n4,n5,n6,n7,n8)
    else if n7 neq 1 then I3cr86(n2,n1,n3,n5,n4,n7,n6,n8)
    else if n4 neq 1 then I3cr84(n1,n2,n3,n4,n5,n8)
    else if n5 neq 1 then I3cr84(n2,n1,n3,n5,n4,n8)
    else if n3 neq 1 then I3cr83(n1,n2,n3,n8)
    else if n1 neq 1 then I3cr81(n1,n2,n8)
    else if n2 neq 1 then I3cr81(n2,n1,n8)
    else                  I3cr8(n8)
else if n7<n6 then I3cl(n2,n1,n3,n5,n4,n7,n6,n8)
else I3cl(n1,n2,n3,n4,n5,n6,n7,n8)$

remember I3c;

% lower n3 or n6 or n8: (4)
procedure I3cl(n1,n2,n3,n4,n5,n6,n7,n8);
(n4*(I3c(n1,n2,n3,n4+1,n5,n6-1,n7,n8)-I3c(n1,n2,n3,n4+1,n5,n6,n7,n8-1))
    -n1*I3c(n1+1,n2,n3-1,n4,n5,n6,n7,n8))
/(d-n1-n4-2*n6)$

% raise n1
procedure I3cr1(n1,n2,n3,n4,n5,n6,n7,n8);
if      n6 neq 1 then I3cr16(n1,n2,n3,n4,n5,n6,n7,n8)
else if n4 neq 1 then I3cr14(n1,n2,n3,n4,n5,n7,n8)
else                  I3cr1a(n1,n2,n3,n5,n7,n8)$

% raise n1 at n6 neq 1: 1+ 6- (2)
procedure I3cr16(n1,n2,n3,n4,n5,n6,n7,n8);
I3c(n1+1,n2,n3-1,n4,n5,n6,n7,n8)
+(n7*(I3c(n1+1,n2,n3-1,n4,n5,n6-1,n7+1,n8)-I3c(n1+1,n2-1,n3,n4,n5,n6-1,n7+1,n8))
    +n8*(I3c(n1+1,n2,n3-1,n4,n5,n6-1,n7,n8+1)-I3c(n1+1,n2,n3,n4,n5,n6-1,n7,n8+1))
    -2*n3*I3c(n1+1,n2,n3+1,n4,n5,n6-1,n7,n8))
/(n6-1)$

% raise n1 at n4 neq 1, n6=1: 1+ 4- [(1)+(2)]
procedure I3cr14(n1,n2,n3,n4,n5,n7,n8);
I3c(n1+1,n2,n3,n4,n5,1,n7,n8)
-(n7*(I3c(n1+1,n2,n3-1,n4-1,n5,1,n7+1,n8)-I3c(n1+1,n2-1,n3,n4-1,n5,1,n7+1,n8))
    +n8*(I3c(n1+1,n2,n3-1,n4-1,n5,1,n7,n8+1)-I3c(n1+1,n2,n3,n4-1,n5,1,n7,n8+1))
    -2*n3*I3c(n1+1,n2,n3+1,n4-1,n5,1,n7,n8)
    -2*(n1+1)*I3c(n1+2,n2,n3,n4-1,n5,1,n7,n8))
/(n4-1)$

% raise n1 or n6 at n4=n6=1: (3)
procedure I3cr1a(n1,n2,n3,n5,n7,n8);
(I3c(n1,n2,n3,0,n5,2,n7,n8)-I3c(n1,n2,n3,1,n5,2,n7,n8-1)
    -n1*I3c(n1+1,n2,n3,1,n5,1,n7,n8))
/(d-n1-3)$

% raise n4
procedure I3cr4(n1,n2,n3,n4,n5,n6,n7,n8);
if      n6 neq 1 then I3cr46(n1,n2,n3,n4,n5,n6,n7,n8)
else if n1 neq 1 then I3cr41(n1,n2,n3,n4,n5,n7,n8)
else                  I3cr4a(n2,n3,n4,n5,n7,n8)$

% raise n4 at n6 neq 1: 4+ 6- (3)
procedure I3cr46(n1,n2,n3,n4,n5,n6,n7,n8);
I3c(n1,n2,n3,n4+1,n5,n6,n7,n8-1)
+((d-n1-n6-2*n4-1)*I3c(n1,n2,n3,n4+1,n5,n6-1,n7,n8)
    +n1*I3c(n1+1,n2,n3,n4+1,n5,n6-1,n7,n8))
/(n6-1)$

% raise n4 or n6 at n1 neq 1, n6=1: 1- (1)
procedure I3cr41(n1,n2,n3,n4,n5,n7,n8);
(n4*(I3c(n1-2,n2,n3,n4+1,n5,1,n7,n8)-I3c(n1-1,n2,n3,n4+1,n5,1,n7,n8))
    +I3c(n1-2,n2,n3,n4,n5,2,n7,n8)-I3c(n1-1,n2,n3-1,n4,n5,2,n7,n8))
/(2*(n1-1))$

% raise n4 or n1 at n1=n6=1: (4)
procedure I3cr4a(n2,n3,n4,n5,n7,n8);
(n4*(I3c(1,n2,n3,n4+1,n5,0,n7,n8)-I3c(1,n2,n3,n4+1,n5,1,n7,n8-1))
    -I3c(2,n2,n3-1,n4,n5,1,n7,n8))
/(d-n4-3)$

% raise n6
procedure I3cr6(n1,n2,n3,n4,n5,n6,n7,n8);
if      n4 neq 1 then I3cr64(n1,n2,n3,n4,n5,n6,n7,n8)
else if n1 neq 1 then I3cr61(n1,n2,n3,n5,n6,n7,n8)
else                  I3cr6a(n2,n3,n5,n6,n7,n8)$

% raise n6 at n4 neq 1: 6+ 4- (4)
procedure I3cr64(n1,n2,n3,n4,n5,n6,n7,n8);
I3c(n1,n2,n3,n4,n5,n6+1,n7,n8-1)
+((d-n1-n4-2*n6-1)*I3c(n1,n2,n3,n4-1,n5,n6+1,n7,n8)
    +n1*I3c(n1+1,n2,n3-1,n4-1,n5,n6+1,n7,n8))
/(n4-1)$

% raise n6 or n4 at n1 neq 1, n4=1: 1- (1)
procedure I3cr61(n1,n2,n3,n5,n6,n7,n8);
(I3c(n1-2,n2,n3,2,n5,n6,n7,n8)-I3c(n1-1,n2,n3,2,n5,n6,n7,n8)
    +n6*(I3c(n1-2,n2,n3,1,n5,n6+1,n7,n8)-I3c(n1-1,n2,n3-1,1,n5,n6+1,n7,n8)))
/(2*(n1-1))$

% raise n6 or n1 at n1=n4=1: (3)
procedure I3cr6a(n2,n3,n5,n6,n7,n8);
(n6*(I3c(1,n2,n3,0,n5,n6+1,n7,n8)-I3c(1,n2,n3,1,n5,n6+1,n7,n8-1))
    -I3c(2,n2,n3,1,n5,n6,n7,n8))
/(d-n6-3)$

% raise n3 at n1 neq 1: 3+ 1- (4)
procedure I3cr31(n1,n2,n3,n4,n5,n6,n7,n8);
(n4*(I3c(n1-1,n2,n3+1,n4+1,n5,n6-1,n7,n8)-I3c(n1-1,n2,n3+1,n4+1,n5,n6,n7,n8-1))
    -(d-n1-n4-2*n6+1)*I3c(n1-1,n2,n3+1,n4,n5,n6,n7,n8))
/(n1-1)$

% raise n3 at n6 neq 1, n1=n2=1: 3+ 6- (1)
procedure I3cr36(n3,n4,n5,n6,n7,n8);
I3c(0,1,n3+1,n4,n5,n6,n7,n8)
+(n4*(I3c(0,1,n3+1,n4+1,n5,n6-1,n7,n8)-I3c(1,1,n3+1,n4+1,n5,n6-1,n7,n8))
    -2*I3c(2,1,n3+1,n4,n5,n6-1,n7,n8))
/(n6-1)$

% raise n3 at n8 neq 1, n1=n2=n6=n7=1: 3+ 8- [(1)+(1')+(2)+2(0)]
procedure I3cr38(n3,n4,n5,n8);
I3c(1,1,n3+1,n4,n5,1,1,n8)
+(n4*(I3c(1,1,n3+1,n4+1,n5,1,1,n8-1)-I3c(0,1,n3+1,n4+1,n5,1,1,n8-1))
    +n5*(I3c(1,1,n3+1,n4,n5+1,1,1,n8-1)-I3c(1,0,n3+1,n4,n5+1,1,1,n8-1))
    -2*(3*d-n3-2*(n4+n5+n8)-5)*I3c(1,1,n3+1,n4,n5,1,1,n8-1))
/(n8-1)$

% raise n3 or n1 or n2 at n1=n2=n6=n7=n8=1: (0)
procedure I3cr3(n3,n4,n5);
-(I3c(2,1,n3,n4,n5,1,1,1)+I3c(1,2,n3,n4,n5,1,1,1)+n3*I3c(1,1,n3+1,n4,n5,1,1,1))
/(3*d-n3-2*(n4+n5)-8)$

% raise n8 at n6 neq 1: 8+ 6- (3)
procedure I3cr86(n1,n2,n3,n4,n5,n6,n7,n8);
I3c(n1,n2,n3,n4-1,n5,n6,n7,n8+1)
-((d-n1-n6-2*n4+1)*I3c(n1,n2,n3,n4,n5,n6-1,n7,n8+1)
    +n1*I3c(n1+1,n2,n3,n4,n5,n6-1,n7,n8+1))
/(n6-1)$

% raise n8 at n4 neq 1, n6=n7=1: 8+ 4- (4)
procedure I3cr84(n1,n2,n3,n4,n5,n8);
I3c(n1,n2,n3,n4,n5,0,1,n8+1)
-((d-n1-n4-1)*I3c(n1,n2,n3,n4-1,n5,1,1,n8+1)
    +n1*I3c(n1+1,n2,n3-1,n4-1,n5,1,1,n8+1))
/(n4-1)$

% raise n8 or n6 or n7 at n3 neq 1, n4=n5=n6=n7=1: 3- (2)
procedure I3cr83(n1,n2,n3,n8);
(I3c(n1,n2,n3-2,1,1,2,1,n8)-I3c(n1-1,n2,n3-1,1,1,2,1,n8)
    +I3c(n1,n2,n3-2,1,1,1,2,n8)-I3c(n1,n2-1,n3-1,1,1,1,2,n8)
    +n8*(I3c(n1,n2,n3-2,1,1,1,1,n8+1)-I3c(n1,n2,n3-1,1,1,1,1,n8+1)))
/(2*(n3-1))$

% raise n4 or n6 at n1 neq 1, n3=n4=n5=n6=n7=1: 1- (1)
procedure I3cr81(n1,n2,n8);
(I3c(n1-2,n2,1,2,1,1,1,n8)-I3c(n1-1,n2,1,2,1,1,1,n8)
    +I3c(n1-2,n2,1,1,1,2,1,n8)-I3c(n1-1,n2,0,1,1,2,1,n8))
/(2*(n1-1))$

% raise n1 or n2 or n3 at n1=n2=n3=n4=n5=n6=n7=1: (0)
procedure I3cr8(n8);
-(I3c(2,1,1,1,1,1,1,n8)+I3c(1,2,1,1,1,1,1,n8)+I3c(1,1,2,1,1,1,1,n8))
/(3*d-2*n8-11)$

% I3c with numerator N^n0   N = 2 k1.k2   (n0>=0)
% d3.(k3-k1) (1) d-n3-n7-n8-2n6 + n3 3+ 1- + n7 7+ (0+ + 4- + 5- - 6-) + n8 8+ (4- - 6-) = 0
% d1.v       (2) - 2 n1 1+ + n0 0- (2- - 1) + n4 4+ (1- - 1) + n6 6+ (1- - 3-) = 0
% d1.k1      (3) d+n0-n1-n6-2n4 + n1 1+ + n6 6+ (8- - 4-) = 0
% hom        (0) 3d-n1-n2-n3-2(n4+n5+n6+n7+n8-n0) + n1 1+ + n2 2+ + n3 3+ = 0
% (d1+d2+d3).k1 - (0): (4)
% 2(d-n5-n6-n7)+n0-n2-n3-n8 + 2 n0 0- 4- + (n2 2+ + n3 3+) 1- - n5 5+ 0+ + n8 8+ (4- - 6-) = 0

procedure II3c(n1,n2,n3,n4,n5,n6,n7,n8,n0);
if max(n1,n4)<=0 or max(n1,n6)<=0 or max(n4,n6)<=0
    or max(n2,n5)<=0 or max(n2,n7)<=0 or max(n5,n7)<=0
    or max(n1,n3,n2)<=0 or max(n6,n3,n7)<=0 or max(n3,n6,n8)<=0 or max(n3,n7,n8)<=0
    or max(n6,n8,n7)<=0 or max(n4,n8,n5)<=0 or max(n4,n8,n7)<=0 or max(n5,n8,n6)<=0
then 0
else if n0=0 then I3c(n1,n2,n3,n4,n5,n6,n7,n8)
else if n4 neq 1 then II3cl05(n2,n1,n3,n5,n4,n7,n6,n8,n0)
else if n5 neq 1 then II3cl05(n1,n2,n3,n4,n5,n6,n7,n8,n0)
else if n6 neq 1 then II3cl07(n2,n1,n3,n7,n6,n8,n0)
else if n7 neq 1 then II3cl07(n1,n2,n3,n6,n7,n8,n0)
else if n1 neq 1 then II3cl01(n1,n2,n3,n8,n0)
else if n2 neq 1 then II3cl01(n2,n1,n3,n8,n0)
else II3cl0(n3,n8,n0)$

% lower n0 at n5 neq 1: 0- 5- (4)
procedure II3cl05(n1,n2,n3,n4,n5,n6,n7,n8,n0);
((2*(d-n5-n6-n7)+n0-n2-n3-n8+1)*II3c(n1,n2,n3,n4,n5-1,n6,n7,n8,n0-1)
    +2*(n0-1)*II3c(n1,n2,n3,n4-1,n5-1,n6,n7,n8,n0-2)
    +n2*II3c(n1-1,n2+1,n3,n4,n5-1,n6,n7,n8,n0-1)
    +n3*II3c(n1-1,n2,n3+1,n4,n5-1,n6,n7,n8,n0-1)
    +n8*(II3c(n1,n2,n3,n4-1,n5-1,n6,n7,n8+1,n0-1)-II3c(n1,n2,n3,n4,n5-1,n6-1,n7,n8+1,n0-1)))
/(n5-1)$

% lower n0 at n7 neq 1, n4=n5=1: 0- 7- (1)
procedure II3cl07(n1,n2,n3,n6,n7,n8,n0);
II3c(n1,n2,n3,1,1,n6-1,n7,n8,n0-1)
-II3c(n1,n2,n3,0,1,n6,n7,n8,n0-1)-II3c(n1,n2,n3,1,0,n6,n7,n8,n0-1)
+(n8*(II3c(n1,n2,n3,1,1,n6-1,n7-1,n8+1,n0-1)-II3c(n1,n2,n3,0,1,n6,n7-1,n8+1,n0-1))
    -n3*II3c(n1-1,n2,n3+1,1,1,n6,n7-1,n8,n0-1)
    -(d-n3-n7-n8-2*n6+1)*II3c(n1,n2,n3,1,1,n6,n7-1,n8,n0-1))
/(n7-1)$

% lower n0 or raise n4 or n6 at n1 neq 1, n4=n5=n6=n7=1: 1- (2)
procedure II3cl01(n1,n2,n3,n8,n0);
(n0*(II3c(n1-1,n2-1,n3,1,1,1,1,n8,n0-1)-II3c(n1-1,n2,n3,1,1,1,1,n8,n0-1))
    +II3c(n1-2,n2,n3,2,1,1,1,n8,n0)-II3c(n1-1,n2,n3,2,1,1,1,n8,n0)
    +II3c(n1-2,n2,n3,1,1,2,1,n8,n0)-II3c(n1-1,n2,n3-1,1,1,2,1,n8,n0))
/(2*(n1-1))$

% raise n1 or n6 at n1=n2=n4=n5=n6=n7=1: (3)
procedure II3cl0(n3,n8,n0);
(II3c(1,1,n3,0,1,2,1,n8,n0)-II3c(2,1,n3,1,1,1,1,n8,n0)-II3c(1,1,n3,1,1,2,1,n8-1,n0))
/(d+n0-4)$

% Id
%
%        8          D1 = (k1+p).v         D4 = -k1^2
%      /---\        D2 = (k2+p).v         D5 = -k2^2
%     / \ / \       D3 = (k1+k2-k3+p).v   D6 = -(k1-k3)^2
%   4/   /   \5                           D7 = -(k2-k3)^2
%   /  7/ \6  \                           D8 = -k3^2
%  /   /   \   \
% ===============
%   1    3    2
%
% Recurrence relations
% -d1.v (1) - 2 n1 1+ - 2 n3 3+ + n4 4+ (1- - 1) + n6 6+ (3- - 2-) = 0
%      (1') - 2 n2 2+ - 2 n3 3+ + n5 5+ (2- - 1) + n7 7+ (3- - 1-) = 0
%  d3.v (2) - 2 n3 3+ + n6 6+ (3- - 2-) + n7 7+ (3- - 1-) + n8 8+ (1 + 3- - 1- - 2-) = 0
% (1)-(2) (3) - 2 n1 1+ + n4 4+ (1- - 1) + n7 7+ (1- - 3-) + n8 8+ (1- + 2- - 3- - 1) = 0
%        (3') - 2 n2 2+ + n5 5+ (2- - 1) + n6 6+ (2- - 3-) + n8 8+ (1- + 2- - 3- - 1) = 0
% (1)+2(0) (4) 2(3d-n1-n2-n3-2(n4+n5+n6+n7+n8)) + 2 n2 2+ + n4 4+ (1- - 1) + n6 6+ (3- - 2-) = 0
%         (4') 2(3d-n1-n2-n3-2(n4+n5+n6+n7+n8)) + 2 n1 1+ + n5 5+ (2- - 1) + n7 7+ (3- - 1-) = 0
% (1)+(1')-(2)+2(0): (5)
% 2(3d-n1-n2-n3-2(n4+n5+n6+n7+n8)) + n4 4+ (1- - 1) + n5 5+ (2- - 1) + n8 8+ (1- + 2- - 3- - 1) = 0
% d1.k1      (6) d-n1-n6-2n4 + n1 1+ + n3 3+ (1 - 1-) + n6 6+ (8- - 4-) = 0
%           (6') d-n2-n7-2n5 + n2 2+ + n3 3+ (1 - 2-) + n7 7+ (8- - 5-) = 0
% d1.(k1-k3) (7) d-n3-n4-2n6 + n1 1+ (2- - 3-) + n3 3+ 2- + n4 4+ (8- - 6-)
%           (7') d-n3-n5-2n7 + n2 2+ (1- - 3-) + n3 3+ 1- + n5 5+ (8- - 7-)
% (0) - (6)
%  (8) 2(d-n5-n7-n8)-n2-n3-n6 + n2 2+ + n3 3+ 1- + n6 6+ (4- - 8-) = 0
% (8') 2(d-n4-n6-n8)-n1-n3-n7 + n1 1+ + n3 3+ 2- + n7 7+ (5- - 8-) = 0
% 2 (6) + (2) + (3)
%  (*) 2(d-n1-n6-2n4) - 2 n3 3+ 1- + n4 4+ (1- - 1) + n6 6+ [2(8- - 4-) + 3- - 2-] = 0
% (*') 2(d-n2-n7-2n5) - 2 n3 3+ 2- + n5 5+ (2- - 1) + n7 7+ [2(8- - 5-) + 3- - 1-] = 0
% (0) - 2+ (7)
%  (9) 3d-n1-n2-n3-2(n4+n5+n6+n7+n8) - [d-n2-n3-n4-2n6 - n1 1+ 3- + n4 4+ (8- - 6-)] 2+ = 0
% (9') 3d-n1-n2-n3-2(n4+n5+n6+n7+n8) - [d-n1-n3-n5-2n7 - n2 2+ 3- + n5 5+ (8- - 7-)] 1+ = 0
% d3.k3 (10) d-n3-n6-n7-2n8 + n3 3+ (1- + 2- - 1) + n6 6+ (4- - 8-) + n7 7+ (5- - 8-) = 0
% (d1+d3).k3 (11) d-n1-n4-n7-2n8 + n1 1+ (1 + 3- - 2-) + n4 4+ (6- - 8-) + n7 7+ (5- - 8-) = 0
%           (11') d-n2-n5-n6-2n8 + n2 2+ (1 + 3- - 1-) + n5 5+ (7- - 8-) + n6 6+ (4- - 8-) = 0
% hom (0) 3d-n1-n2-n3-2(n4+n5+n6+n7+n8) + n1 1+ + n2 2+ + n3 3+ = 0

procedure I3d(n1,n2,n3,n4,n5,n6,n7,n8);
if max(n4,n6)<=0 or max(n5,n7)<=0 or max(n1,n3,n2)<=0 or max(n4,n8,n5)<=0
    or max(n4,n8,n7)<=0 or max(n5,n8,n6)<=0 or max(n6,n8,n7)<=0
    or max(n3,n1,n4)<=0 or max(n1,n3,n6)<=0 or max(n3,n2,n5)<=0 or max(n2,n3,n7)<=0
    or max(n1,n4,n8)<=0 or max(n1,n7,n8)<=0 or max(n2,n5,n8)<=0 or max(n2,n6,n8)<=0
    or max(n4,n1,n7)<=0 or max(n5,n2,n6)<=0 or max(n6,n3,n7)<=0
    or max(n3,n6,n8)<=0 or max(n3,n7,n8)<=0
then 0
else if n1=0 then J3a(n3,n2,n5,n6,n7,n4,n8)
else if n2=0 then J3a(n3,n1,n4,n7,n6,n5,n8)
else if n3=0 then J3b(n1,n2,n4,n5,n8,n6,n7)
else if n4=0 then J3e(n1,n2,n3,n5,n6,n7,n8)
else if n5=0 then J3e(n2,n1,n3,n4,n7,n6,n8)
else if n6=0 then J3d(n1,n2,n3,n4,n5,n7,n8)
else if n7=0 then J3d(n2,n1,n3,n5,n4,n6,n8)
else if n8=0 then J3c(n1,n2,n3,n4,n5,n7,n6)
else if n1<0 then I3dr1(n1,n2,n3,n4,n5,n6,n7,n8)
else if n2<0 then I3dr1(n2,n1,n3,n5,n4,n7,n6,n8)
else if n3<0 then
    if      n1 neq 1 then I3dr31(n1,n2,n3,n4,n5,n6,n7,n8)
    else if n2 neq 1 then I3dr31(n2,n1,n3,n5,n4,n7,n6,n8)
    else if n6 neq 1 then I3dr36(n3,n4,n5,n6,n7,n8)
    else if n7 neq 1 then I3dr36(n3,n5,n4,n7,n6,n8)
    else if n8 neq 1 then I3dr38(n3,n4,n5,n8)
    else I3dr3(n3,n4,n5)
else if n1>1 then I3dl1(n1,n2,n3,n4,n5,n6,n7,n8)
else if n2>1 then I3dl1(n2,n1,n3,n5,n4,n7,n6,n8)
else if n3>1 then I3dl3(n3,n4,n5,n6,n7,n8)
else if n4<0 then I3dr4(n4,n5,n6,n7,n8)
else if n5<0 then I3dr4(n5,n4,n7,n6,n8)
else if n6<0 then I3dr6(n4,n5,n6,n7,n8)
else if n7<0 then I3dr6(n5,n4,n7,n6,n8)
else if n8<0 then
    if      n4 neq 1 then I3dr84(n4,n5,n6,n7,n8)
    else if n5 neq 1 then I3dr84(n5,n4,n7,n6,n8)
    else if n6 neq 1 then I3dr86(n6,n7,n8)
    else if n7 neq 1 then I3dr86(n7,n6,n8)
    else I3dr8(n8)
else if n7<n6 then I3dl(n5,n4,n7,n6,n8)
else I3dl(n4,n5,n6,n7,n8)$

remember I3d;

% lower n6 or n8 at n1=n2=n3=1: (7)
procedure I3dl(n4,n5,n6,n7,n8);
(n4*(I3d(1,1,1,n4+1,n5,n6-1,n7,n8)-I3d(1,1,1,n4+1,n5,n6,n7,n8-1))
    +I3d(2,1,0,n4,n5,n6,n7,n8)-I3d(2,0,1,n4,n5,n6,n7,n8)-I3d(1,0,2,n4,n5,n6,n7,n8))
/(d-n4-2*n6-1)$

% raise n1: (9')
procedure I3dr1(n1,n2,n3,n4,n5,n6,n7,n8);
((d-n1-n3-n5-2*n7)*I3d(n1+1,n2,n3,n4,n5,n6,n7,n8)
    -n2*I3d(n1+1,n2+1,n3-1,n4,n5,n6,n7,n8)
    +n5*(I3d(n1+1,n2,n3,n4,n5+1,n6,n7,n8-1)-I3d(n1+1,n2,n3,n4,n5+1,n6,n7-1,n8)))
/(3*d-n1-n2-n3-2*(n4+n5+n6+n7+n8))$

% raise n3 at n1 neq 1: 3+ 1- (7)
procedure I3dr31(n1,n2,n3,n4,n5,n6,n7,n8);
I3d(n1,n2-1,n3+1,n4,n5,n6,n7,n8)
+((d-n3-n4-2*n6-1)*I3d(n1-1,n2,n3+1,n4,n5,n6,n7,n8)
    +n4*(I3d(n1-1,n2,n3+1,n4+1,n5,n6,n7,n8-1)-I3d(n1-1,n2,n3+1,n4+1,n5,n6-1,n7,n8))
    +(n3+1)*I3d(n1-1,n2-1,n3+2,n4,n5,n6,n7,n8))
/(n1-1)$

% raise n3 at n6 neq 1, n1=n2=1: 3+ 6- (1)
procedure I3dr36(n3,n4,n5,n6,n7,n8);
I3d(1,0,n3+1,n4,n5,n6,n7,n8)
+(n4*(I3d(1,1,n3+1,n4+1,n5,n6-1,n7,n8)-I3d(0,1,n3+1,n4+1,n5,n6-1,n7,n8))
    +2*I3d(2,1,n3+1,n4,n5,n6-1,n7,n8)
    +2*(n3+1)*I3d(1,1,n3+2,n4,n5,n6-1,n7,n8))
/(n6-1)$

% raise n3 at n8 neq 1, n1=n2=n6=n7=1: 3+ 8- (5)
procedure I3dr38(n3,n4,n5,n8);
I3d(0,1,n3+1,n4,n5,1,1,n8)+I3d(1,0,n3+1,n4,n5,1,1,n8)-I3d(1,1,n3+1,n4,n5,1,1,n8)
+(2*(3*d-n3-2*(n4+n5+n8)-5)*I3d(1,1,n3+1,n4,n5,1,1,n8-1)
    +n4*(I3d(0,1,n3+1,n4+1,n5,1,1,n8-1)-I3d(1,1,n3+1,n4+1,n5,1,1,n8-1))
    +n5*(I3d(1,0,n3+1,n4,n5+1,1,1,n8-1)-I3d(1,1,n3+1,n4,n5+1,1,1,n8-1)))
/(n8-1)$

% raise n3 or n1 or n2 at n1=n2=n6=n7=n8=1: (0)
procedure I3dr3(n3,n4,n5);
-(I3d(2,1,n3,n4,n5,1,1,1)+I3d(1,2,n3,n4,n5,1,1,1)+n3*I3d(1,1,n3+1,n4,n5,1,1,1))
/(3*d-n3-2*(n4+n5)-8)$

% lower n1: 1- (4')
procedure I3dl1(n1,n2,n3,n4,n5,n6,n7,n8);
(-2*(3*d-n1-n2-n3-2*(n4+n5+n6+n7+n8)+1)*I3d(n1-1,n2,n3,n4,n5,n6,n7,n8)
    +n5*(I3d(n1-1,n2,n3,n4,n5+1,n6,n7,n8)-I3d(n1-1,n2-1,n3,n4,n5+1,n6,n7,n8))
    +n7*(I3d(n1-2,n2,n3,n4,n5,n6,n7+1,n8)-I3d(n1-1,n2,n3-1,n4,n5,n6,n7+1,n8)))
/(2*(n1-1))$

% lower n3 at n1=n2=1: 3- (2)
procedure I3dl3(n3,n4,n5,n6,n7,n8);
(n6*(I3d(1,1,n3-2,n4,n5,n6+1,n7,n8)-I3d(1,0,n3-1,n4,n5,n6+1,n7,n8))
    +n7*(I3d(1,1,n3-2,n4,n5,n6,n7+1,n8)-I3d(0,1,n3-1,n4,n5,n6,n7+1,n8))
    +n8*(I3d(1,1,n3-1,n4,n5,n6,n7,n8+1)+I3d(1,1,n3-2,n4,n5,n6,n7,n8+1)
        -I3d(0,1,n3-1,n4,n5,n6,n7,n8+1)-I3d(1,0,n3-1,n4,n5,n6,n7,n8+1)))
/(2*(n3-1))$

% raise n4 at n1=n2=n3=1: (7)
procedure I3dr4(n4,n5,n6,n7,n8);
(n4*(I3d(1,1,1,n4+1,n5,n6-1,n7,n8)-I3d(1,1,1,n4+1,n5,n6,n7,n8-1))
    +I3d(2,1,0,n4,n5,n6,n7,n8)-I3d(2,0,1,n4,n5,n6,n7,n8)-I3d(1,0,2,n4,n5,n6,n7,n8))
/(d-n4-2*n6-1)$

% raise n6 at n1=n2=n3
procedure I3dr6(n4,n5,n6,n7,n8);
if n4 neq 1 then I3dr64(n4,n5,n6,n7,n8)
else I3dr6a(n5,n6,n7,n8)$

% raise n6 at n4 neq 1, n1=n2=n3=1: 6+ 4- (7)
procedure I3dr64(n4,n5,n6,n7,n8);
I3d(1,1,1,n4,n5,n6+1,n7,n8-1)
+((d-n4-2*n6-2)*I3d(1,1,1,n4-1,n5,n6+1,n7,n8)
    +I3d(1,0,2,n4-1,n5,n6+1,n7,n8)+I3d(2,0,1,n4-1,n5,n6+1,n7,n8)
    -I3d(2,1,0,n4-1,n5,n6+1,n7,n8))
/(n4-1)$

% raise n6 or n4 at n1=n2=n3=n4=1: (*)
procedure I3dr6a(n5,n6,n7,n8);
(n6*(2*(I3d(1,1,1,0,n5,n6+1,n7,n8)-I3d(1,1,1,1,n5,n6+1,n7,n8-1))
        +I3d(1,0,1,1,n5,n6+1,n7,n8)-I3d(1,1,0,1,n5,n6+1,n7,n8))
    +2*I3d(0,1,2,1,n5,n6,n7,n8)
    +I3d(1,1,1,2,n5,n6,n7,n8)-I3d(0,1,1,2,n5,n6,n7,n8))
/(2*(d-n6-3))$

% raise n8 at n4 neq 1, n1=n2=n3=1: 8+ 4- (7)
procedure I3dr84(n4,n5,n6,n7,n8);
I3d(1,1,1,n4,n5,n6-1,n7,n8+1)
-((d-n4-2*n6)*I3d(1,1,1,n4-1,n5,n6,n7,n8+1)
    +I3d(1,0,2,n4-1,n5,n6,n7,n8+1)+I3d(2,0,1,n4-1,n5,n6,n7,n8+1)
    -I3d(2,1,0,n4 - 1,n5,n6,n7,n8 + 1))
/(n4-1)$

% raise n8 at n6 neq 1, n1=n2=n3=n4=n5=1: 8+ 6- (*)
procedure I3dr86(n6,n7,n8);
I3d(1,1,1,0,1,n6,n7,n8+1)
+(I3d(1,0,1,1,1,n6,n7,n8+1)-I3d(1,1,0,1,1,n6,n7,n8+1))/2
-(2*(d-n6-2)*I3d(1,1,1,1,1,n6-1,n7,n8+1)
    -2*I3d(0,1,2,1,1,n6-1,n7,n8+1)
    +I3d(0,1,1,2,1,n6-1,n7,n8+1)-I3d(1,1,1,2,1,n6-1,n7,n8+1))
/(2*(n6-1))$

% raise n8 or n4 or n5 at n1=n2=n3=n4=n5=n6=n7=1: (5)
procedure I3dr8(n8);
(I3d(1,1,1,2,1,1,1,n8)+I3d(1,1,1,1,2,1,1,n8)
    -I3d(1,0,1,1,2,1,1,n8)-I3d(0,1,1,2,1,1,1,n8)
    +n8*(I3d(1,1,1,1,1,1,1,n8+1)+I3d(1,1,0,1,1,1,1,n8+1)
        -I3d(1,0,1,1,1,1,1,n8+1)-I3d(0,1,1,1,1,1,1,n8+1)))
/(2*(3*d-2*n8-11))$

% Jd              n6=0
%
%       /|\
%     7/ | \5
%     /  |8 \
%  1 / 3 |   \
% =============
%  \    /  2
%   \--/
%    4
%
% Recurrence relations:
% (d2+d3).k2 (12) d-n2-n8-2n5 + n2 2+ + n8 8+ (7- - 5-) = 0
% d3.(k3-k2) (13) d-n3-n8-2n7 + n3 3+ 1- + n8 8+ (5- - 7-) = 0

procedure J3d(n1,n2,n3,n4,n5,n7,n8);
if n4<=0 or max(n1,n3)<=0 or max(n2,n3)<=0 or max(n5,n7)<=0 or max(n5,n8)<=0
    or max(n7,n8)<=0 or max(n3,n7)<=0 or max(n3,n8)<=0 or max(n2,n5)<=0 or max(n2,n8)<=0
then 0
else if n3=0 then I1(n1,n4)*G1(n7,n8)*I1b(n2,n5+n7+n8)*B(2)
else if n8=0 then I1(n2,n5)*I1(n3,n7)*I1a(n1+n3+2*n7,n4)*B(2)
else if n2=0 then G1(n5,n8)*I1b(n3,n7+n5+n8)*I1c(n1+n3+2*(n7+n5+n8),n4)*B(3)
else if n1=0 then I1(n3,n4)*I2b(n3+2*n4,n2,n7,n5,n8)
else if n5=0 then I1(n2,n8)*J2b(n2+2*n8,n1,n3,n7,n4)
else if n7=0 then I1(n3,n8)*J2c(n1,n2,n3+2*n8,n4,n5)
else if n3<0 then
    if      n2 neq 1 then J3dr32(n1,n2,n3,n4,n5,n7,n8)
    else if n7 neq 1 then J3dr37(n1,n3,n4,n5,n7,n8)
    else if n8 neq 1 then J3dr38(n1,n3,n4,n5,n8)
    else J3dr3(n1,n2,n3,n4,n5,n7)
else if n2<0 then
    if      n3 neq 1 then J3dr23(n1,n2,n3,n4,n5,n7,n8)
    else if n5 neq 1 then J3dr25(n1,n2,n4,n5,n7,n8)
    else if n8 neq 1 then J3dr28(n1,n2,n4,n7,n8)
    else J3dr3(n1,n2,n3,n4,n5,n7)
else if n8<0 then
    if      n7 neq 1 then J3dr87(n1,n2,n3,n4,n5,n7,n8)
    else if n5 neq 1 then J3dr85(n1,n2,n3,n4,n5,n8)
    else if n3 neq 1 then J3dr83(n1,n2,n3,n4,n7,n8)
    else if n2 neq 1 then J3dr82(n1,n2,n3,n4,n5,n8)
    else J3dr8(n1,n4,n8)
else if n1<0 then
    if      n3 neq 1 then J3dr13(n1,n2,n3,n4,n5,n7,n8)
    else if n4 neq 1 then J3dr14(n1,n2,n4,n5,n7,n8)
    else if n2 neq 1 then J3dr12(n1,n2,n5,n7,n8)
    else if n7 neq 1 then J3dr17(n1,n5,n7,n8)
    else if n8 neq 1 then J3dr18(n1,n5,n8)
    else J3dr1(n1,n5)
else if n5<0 then
    if      n8 neq 1 then J3dr58(n1,n2,n3,n4,n5,n7,n8)
    else if n7 neq 1 then J3dr57(n1,n2,n3,n4,n5,n7)
    else if n2 neq 1 then J3dr82(n1,n2,n3,n4,n5,n8)
    else J3dr5(n1,n3,n4,n5)
else if n7<0 then
    if      n8 neq 1 then J3dr78(n1,n2,n3,n4,n5,n7,n8)
    else if n5 neq 1 then J3dr75(n1,n2,n3,n4,n5,n7)
    else if n3 neq 1 then J3dr83(n1,n2,n3,n4,n7,n8)
    else J3dr7(n1,n2,n4,n7)
else J3dl(n1,n2,n3,n4,n5,n7,n8)$

remember J3d;

% lower n1 or n5 or n7: (13)
procedure J3dl(n1,n2,n3,n4,n5,n7,n8);
(-n3*J3d(n1-1,n2,n3+1,n4,n5,n7,n8)
    +n8*(J3d(n1,n2,n3,n4,n5,n7-1,n8+1)-J3d(n1,n2,n3,n4,n5-1,n7,n8+1)))
/(d-n3-n8-2*n7)$

% raise n3 at n2 neq 1: 3+ 2- (11')
procedure J3dr32(n1,n2,n3,n4,n5,n7,n8);
J3d(n1-1,n2,n3+1,n4,n5,n7,n8)-J3d(n1,n2,n3+1,n4,n5,n7,n8)
+(-(d-n2-n5-2*n8+1)*J3d(n1,n2-1,n3+1,n4,n5,n7,n8)
    +n5*(J3d(n1,n2-1,n3+1,n4,n5+1,n7,n8-1)-J3d(n1,n2-1,n3+1,n4,n5+1,n7-1,n8)))
/(n2-1)$

% raise n3 at n7 neq 1, n2=1: 3+ 7- (4')
procedure J3dr37(n1,n3,n4,n5,n7,n8);
J3d(n1-1,1,n3+1,n4,n5,n7,n8)
+(-2*(3*d-n1-n3-2*(n4+n5+n7+n8))*J3d(n1,1,n3+1,n4,n5,n7-1,n8)
    -2*n1*J3d(n1+1,1,n3+1,n4,n5,n7-1,n8)
    +n5*(J3d(n1,1,n3+1,n4,n5+1,n7-1,n8)-J3d(n1,0,n3+1,n4,n5+1,n7-1,n8)))
/(n7-1)$

% raise n3 at n8 neq 1, n2=n7=1: 3+ 8- (3')
procedure J3dr38(n1,n3,n4,n5,n8);
J3d(n1-1,1,n3+1,n4,n5,1,n8)+J3d(n1,0,n3+1,n4,n5,1,n8)-J3d(n1,1,n3+1,n4,n5,1,n8)
+(-2*J3d(n1,2,n3+1,n4,n5,1,n8-1)
    +n5*(J3d(n1,0,n3+1,n4,n5+1,1,n8-1)-J3d(n1,1,n3+1,n4,n5+1,1,n8-1)))
/(n8-1)$

% raise n3 or n2 at n8=1: (8)
procedure J3dr3(n1,n2,n3,n4,n5,n7);
-(n2*J3d(n1,n2+1,n3,n4,n5,n7,1)+n3*J3d(n1-1,n2,n3+1,n4,n5,n7,1))
/(2*(d-n5-n7-1)-n2-n3)$

% raise n2 at n3 neq 1: 2+ 3- (10)
procedure J3dr23(n1,n2,n3,n4,n5,n7,n8);
J3d(n1,n2+1,n3,n4,n5,n7,n8)-J3d(n1-1,n2+1,n3,n4,n5,n7,n8)
+(-(d-n3-n7-2*n8+1)*J3d(n1,n2+1,n3-1,n4,n5,n7,n8)
    +n7*(J3d(n1,n2+1,n3-1,n4,n5,n7+1,n8-1)-J3d(n1,n2+1,n3-1,n4,n5-1,n7+1,n8)))
/(n3-1)$

% raise n2 at n5 neq 1, n3=1: 2+ 5- (4')
procedure J3dr25(n1,n2,n4,n5,n7,n8);
J3d(n1,n2+1,1,n4,n5,n7,n8)
+(-2*(3*d-n1-n2-2*(n4+n5+n7+n8))*J3d(n1,n2+1,1,n4,n5-1,n7,n8)
    -2*n1*J3d(n1+1,n2+1,1,n4,n5-1,n7,n8)
    +n7*(J3d(n1-1,n2+1,1,n4,n5-1,n7+1,n8)-J3d(n1,n2+1,0,n4,n5-1,n7+1,n8)))
/(n5-1)$

% raise n2 at n8 neq 1, n3=n5=1: 2+ 8- (2)
procedure J3dr28(n1,n2,n4,n7,n8);
J3d(n1,n2+1,1,n4,1,n7,n8)+J3d(n1,n2+1,0,n4,1,n7,n8)-J3d(n1 - 1,n2 + 1,1,n4,1,n7,n8)
+(-2*J3d(n1,n2+1,2,n4,1,n7,n8-1)
    +n7*(J3d(n1,n2+1,0,n4,1,n7+1,n8-1)-J3d(n1-1,n2+1,1,n4,1,n7+1,n8-1)))
/(n8-1)$

% raise n8 at n7 neq 1: 8+ 7- (10)
procedure J3dr87(n1,n2,n3,n4,n5,n7,n8);
J3d(n1,n2,n3,n4,n5-1,n7,n8+1)
+((d-n3-n7-2*n8-1)*J3d(n1,n2,n3,n4,n5,n7-1,n8+1)
    +n3*(J3d(n1-1,n2,n3+1,n4,n5,n7-1,n8 + 1)+J3d(n1,n2-1,n3+1,n4,n5,n7-1,n8+1)
        -J3d(n1,n2,n3+1,n4,n5,n7-1,n8+1)))
/(n7-1)$

% raise n8 at n5 neq 1, n7=1: 8+ 5- (11')
procedure J3dr85(n1,n2,n3,n4,n5,n8);
J3d(n1,n2,n3,n4,n5,0,n8+1)
+((d-n2-n5-2*n8-1)*J3d(n1,n2,n3,n4,n5-1,1,n8+1)
    +n2*(J3d(n1,n2+1,n3-1,n4,n5-1,1,n8+1)+J3d(n1,n2+1,n3,n4,n5-1,1,n8+1)
        -J3d(n1-1,n2+1,n3,n4,n5-1,1,n8+1)))
/(n5-1)$

% raise n8 or n7 at n3 neq 1, n5=1: 3- (2)
procedure J3dr83(n1,n2,n3,n4,n7,n8);
(n7*(J3d(n1,n2,n3-2,n4,1,n7+1,n8)-J3d(n1-1,n2,n3-1,n4,1,n7+1,n8))
    +n8*(J3d(n1,n2,n3-2,n4,1,n7,n8+1)+J3d(n1,n2,n3-1,n4,1,n7,n8+1)
        -J3d(n1-1,n2,n3-1,n4,1,n7,n8+1)-J3d(n1,n2-1,n3-1,n4,1,n7,n8+1)))
/(2*(n3-1))$

% raise n8 or n5 at n2 neq 1, n7=1: 2- (3')
procedure J3dr82(n1,n2,n3,n4,n5,n8);
(n5*(J3d(n1,n2-2,n3,n4,n5+1,1,n8)-J3d(n1,n2-1,n3,n4,n5+1,1,n8))
    +n8*(J3d(n1-1,n2-1,n3,n4,n5,1,n8+1)+J3d(n1,n2-2,n3,n4,n5,1,n8+1)
        -J3d(n1,n2-1,n3-1,n4,n5,1,n8+1)-J3d(n1,n2-1,n3,n4,n5,1,n8+1)))
/(2*(n2-1))$

% raise n8 or n2 at n2=n3=n5=n7=1: (12)
procedure J3dr8(n1,n4,n8);
(-J3d(n1,2,1,n4,1,1,n8)+n8*(J3d(n1,1,1,n4,0,1,n8+1)-J3d(n1,1,1,n4,1,0,n8+1)))
/(d-n8-3)$

% raise n1 at n3 neq 1: 1+ 3- (8)
procedure J3dr13(n1,n2,n3,n4,n5,n7,n8);
-((2*(d-n5-n7-n8)-n2-n3+1)*J3d(n1+1,n2,n3-1,n4,n5,n7,n8)
    +n2*J3d(n1+1,n2+1,n3-1,n4,n5,n7,n8))
/(n3-1)$

% raise n1 at n4 neq 1, n3=1: 1+ 4- (1)
procedure J3dr14(n1,n2,n4,n5,n7,n8);
J3d(n1+1,n2,1,n4,n5,n7,n8)
+2*((n1+1)*J3d(n1+2,n2,1,n4-1,n5,n7,n8)+J3d(n1+1,n2,2,n4-1,n5,n7,n8))
/(n4-1)$

% raise n1 at n2 neq 1, n3=n4=1: 1+ 2- (11')
procedure J3dr12(n1,n2,n5,n7,n8);
J3d(n1+1,n2,1,1,n5,n7,n8)+J3d(n1+1,n2,0,1,n5,n7,n8)
+((d-n2-n5-2*n8+1)*J3d(n1+1,n2-1,1,1,n5,n7,n8)
    +n5*(J3d(n1+1,n2-1,1,1,n5+1,n7-1,n8)-J3d(n1+1,n2-1,1,1,n5+1,n7,n8-1)))
/(n2-1)$

% raise n1 at n7 neq 1, n2=n3=n4=1: 1+ 7- (4')
procedure J3dr17(n1,n5,n7,n8);
J3d(n1+1,1,0,1,n5,n7,n8)
+(2*(3*d-n1-2*(n5+n7+n8)-3)*J3d(n1+1,1,1,1,n5,n7-1,n8)
    +2*(n1+1)*J3d(n1+2,1,1,1,n5,n7-1,n8)
    +n5*(J3d(n1+1,0,1,1,n5+1,n7-1,n8)-J3d(n1+1,1,1,1,n5+1,n7-1,n8)))
/(n7-1)$

% raise n1 at n8 neq 1, n2=n3=n4=n7=1: 1+ 8- (3')
procedure J3dr18(n1,n5,n8);
J3d(n1+1,1,1,1,n5,1,n8)+J3d(n1+1,1,0,1,n5,1,n8)-J3d(n1+1,0,1,1,n5,1,n8)
+(2*J3d(n1+1,2,1,1,n5,1,n8-1)
    +n5*(J3d(n1+1,1,1,1,n5+1,1,n8-1)-J3d(n1+1,0,1,1,n5+1,1,n8-1)))
/(n8-1)$

% raise n1 or n2 or n3 at n2=n3=n4=n7=n8=1: (0)
procedure J3dr1(n1,n5);
-(n1*J3d(n1+1,1,1,1,n5,1,1)+J3d(n1,2,1,1,n5,1,1)+J3d(n1,1,2,1,n5,1,1))
/(3*d-n1-2*n5-8)$

% raise n5 at n8 neq 1: 5+ 8- (13)
procedure J3dr58(n1,n2,n3,n4,n5,n7,n8);
J3d(n1,n2,n3,n4,n5+1,n7-1,n8)
-((d-n3-n8-2*n7+1)*J3d(n1,n2,n3,n4,n5+1,n7,n8-1)
    +n3*J3d(n1-1,n2,n3+1,n4,n5+1,n7,n8-1))
/(n8-1)$

% raise n5 at n7 neq 1, n8=1: 5+ 7- (10)
procedure J3dr57(n1,n2,n3,n4,n5,n7);
J3d(n1,n2,n3,n4,n5+1,n7,0)
-((d-n3-n7-1)*J3d(n1,n2,n3,n4,n5+1,n7-1,1)
    +n3*(J3d(n1-1,n2,n3+1,n4,n5+1,n7-1,1)+J3d(n1,n2-1,n3+1,n4,n5+1,n7-1,1)
        -J3d(n1,n2,n3+1,n4,n5+1,n7-1,1)))
/(n7-1)$

% raise n5 or n2 at n2=n7=n8=1: (11')
procedure J3dr5(n1,n3,n4,n5);
(J3d(n1-1,2,n3,n4,n5,1,1)-J3d(n1,2,n3-1,n4,n5,1,1)-J3d(n1,2,n3,n4,n5,1,1)
    +n5*(J3d(n1,1,n3,n4,n5+1,1,0)-J3d(n1,1,n3,n4,n5+1,0,1)))
/(d-n5-3)$

% raise n7 at n8 neq 1: 7+ 8- (13)
procedure J3dr78(n1,n2,n3,n4,n5,n7,n8);
J3d(n1,n2,n3,n4,n5 - 1,n7 + 1,n8)
+((d-n3-n8-2*n7-1)*J3d(n1,n2,n3,n4,n5,n7+1,n8-1)
    +n3*J3d(n1-1,n2,n3+1,n4,n5,n7+1,n8-1))
/(n8-1)$

% raise n7 at n5 neq 1, n8=1: 7+ 5- (11')
procedure J3dr75(n1,n2,n3,n4,n5,n7);
J3d(n1,n2,n3,n4,n5,n7+1,0)
-((d-n2-n5-1)*J3d(n1,n2,n3,n4,n5-1,n7+1,1)
    +n2*(J3d(n1,n2+1,n3,n4,n5-1,n7+1,1)+J3d(n1,n2+1,n3-1,n4,n5-1,n7+1,1)
        -J3d(n1-1,n2+1,n3,n4,n5-1,n7+1,1)))
/(n5-1)$

% raise n7 or n3 at n3=n5=n8=1: (10)
procedure J3dr7(n1,n2,n4,n7);
(J3d(n1,n2,2,n4,1,n7,1)-J3d(n1-1,n2,2,n4,1,n7,1)-J3d(n1,n2-1,2,n4,1,n7,1)
    +n7*(J3d(n1,n2,1,n4,1,n7+1,0)-J3d(n1,n2,1,n4,0,n7+1,1)))
/(d-n7-3)$

% Je            n4=0
%
%     /|\
%   8/ | \5
%   / 7|  \
%  /   |   \
% ===========
%  \ 1  3/ 2
%   \---/
%     6
%
% Recurrence relation
% (d1+d3).(k3-k2) (14) d-n1-n8-2n7 + n1 1+ 3- + n8 8+ (5- - 7-) = 0

procedure J3e(n1,n2,n3,n5,n6,n7,n8);
if n6<=0 or max(n1,n3)<=0 or max(n1,n8)<=0 or max(n1,n7)<=0 or max(n5,n8)<=0
    or max(n7,n8)<=0 or max(n5,n7)<=0 or max(n3,n2,n5)<=0 or max(n2,n3,n7)<=0
then 0
else if n1=0 then G1(n7,n8)*I1(n3,n6)*I1d(n2+n3+2*n6,n5+n7+n8)*B(3)
else if n8=0 then I1(n1,n7)*I1a(n3+n1+2*n7,n6)*I1c(n2+n3+n1+2*(n6+n7),n5)*B(3)
else if n5=0 then I1c(n1+n2+n3+2*(n6+n7),n8)*sub(B(1)=B(4),B(2)=B(3),J2(n1,n2,n3,n6,n7))
else if n2=0 then I1c(n1+n3+2*(n5+n7+n8),n6)*sub(B(1)=B(4),B(2)=B(3),I2(n1,n3,n8,n5,n7))
else if n3=0 then I1(n1,n6)*I2b(n1+2*n6,n2,n8,n5,n7)
else if n7=0 then I1(n1,n8)*J2b(n1+2*n8,n2,n3,n6,n5)
else if n1<0 then J3er1(n1,n2,n3,n5,n6,n7,n8)
else if n2<0 then J3er2(n1,n2,n3,n5,n6,n7,n8)
else if n3<0 then
    if      n1 neq 1 then J3er31(n1,n2,n3,n5,n6,n7,n8)
    else if n6 neq 1 then J3er36(n2,n3,n5,n6,n7,n8)
    else if n2 neq 1 then J3er32(n2,n3,n5,n7,n8)
    else if n7 neq 1 then J3er37(n3,n5,n7,n8)
    else if n8 neq 1 then J3er38(n3,n5,n8)
    else J3er3(n3,n5)
else if n8<0 then
    if      n7 neq 1 then J3er87(n1,n2,n3,n5,n6,n7,n8)
    else if n5 neq 1 then J3er85(n1,n2,n3,n5,n6,n8)
    else if n1 neq 1 then J3er81(n1,n2,n3,n5,n6,n7,n8)
    else J3er8(n2,n3,n6,n8)
else if n5<0 then
    if      n8 neq 1 then J3er58(n1,n2,n3,n5,n6,n7,n8)
    else if n7 neq 1 then J3er57(n1,n2,n3,n5,n6,n7)
    else if n1 neq 1 then J3er81(n1,n2,n3,n5,n6,n7,n8)
    else J3er5(n2,n3,n5,n6)
else if n7<0 then
    if      n8 neq 1 then J3er78(n1,n2,n3,n5,n6,n7,n8)
    else if n5 neq 1 then J3er75(n1,n2,n3,n5,n6,n7)
    else if n1 neq 1 then J3er81(n1,n2,n3,n5,n6,n7,n8)
    else J3er7(n2,n3,n6,n7)
else J3el(n1,n2,n3,n5,n6,n7,n8)$

remember J3e;

% lower n3 or n5 or n7: (14)
procedure J3el(n1,n2,n3,n5,n6,n7,n8);
(-n1*J3e(n1+1,n2,n3-1,n5,n6,n7,n8)
    +n8*(J3e(n1,n2,n3,n5,n6,n7-1,n8+1)-J3e(n1,n2,n3,n5-1,n6,n7,n8+1)))
/(d-n1-n8-2*n7)$

% raise n1: (9')
procedure J3er1(n1,n2,n3,n5,n6,n7,n8);
((d-n1-n3-n5-2*n7)*J3e(n1+1,n2,n3,n5,n6,n7,n8)
    -n2*J3e(n1+1,n2+1,n3-1,n5,n6,n7,n8)
    +n5*(J3e(n1+1,n2,n3,n5+1,n6,n7,n8-1)-J3e(n1+1,n2,n3,n5+1,n6,n7-1,n8)))
/(3*d-n1-n2-n3-2*(n5+n6+n7+n8))$

% raise n2: (9)
procedure J3er2(n1,n2,n3,n5,n6,n7,n8);
((d-n2-n3-2*n6)*J3e(n1,n2+1,n3,n5,n6,n7,n8)
    -n1*J3e(n1+1,n2+1,n3-1,n5,n6,n7,n8))
/(3*d-n1-n2-n3-2*(n5+n6+n7+n8))$

% raise n3 at n1 neq 1: 3+ 1- (7)
procedure J3er31(n1,n2,n3,n5,n6,n7,n8);
J3e(n1,n2-1,n3+1,n5,n6,n7,n8)
+((d-n3-2*n6-1)*J3e(n1-1,n2,n3+1,n5,n6,n7,n8)
    +(n3+1)*J3e(n1-1,n2-1,n3+2,n5,n6,n7,n8))
/(n1-1)$

% raise n3 at n6 neq 1, n1=1: 3+ 6- (1)
procedure J3er36(n2,n3,n5,n6,n7,n8);
J3e(1,n2-1,n3+1,n5,n6,n7,n8)
+2*(J3e(2,n2,n3+1,n5,n6-1,n7,n8)
    +(n3+1)*J3e(1,n2,n3+2,n5,n6-1,n7,n8))
/(n6-1)$

% raise n3 at n2 neq 1, n1=n6=1: 3+ 2- (7')
procedure J3er32(n2,n3,n5,n7,n8);
J3e(0,n2,n3+1,n5,1,n7,n8)
+((d-n3-n5-2*n7-1)*J3e(1,n2-1,n3+1,n5,1,n7,n8)
    +n5*(J3e(1,n2-1,n3+1,n5+1,1,n7,n8-1)-J3e(1,n2-1,n3+1,n5+1,1,n7-1,n8))
    +(n3+1)*J3e(0,n2-1,n3+2,n5,1,n7,n8))
/(n2-1)$

% raise n3 at n7 neq 1, n1=n2=n6=1: 3+ 7- (1')
procedure J3er37(n3,n5,n7,n8);
J3e(0,1,n3+1,n5,1,n7,n8)
+(2*J3e(1,2,n3+1,n5,1,n7-1,n8)
    +n5*(J3e(1,1,n3+1,n5+1,1,n7-1,n8)-J3e(1,0,n3+1,n5+1,1,n7-1,n8))
    +2*(n3+1)*J3e(1,1,n3+2,n5,1,n7-1,n8))
/(n7-1)$

% raise n3 at n8 neq 1, n1=n2=n6=n7=1: 3+ 8- (5)
procedure J3er38(n3,n5,n8);
J3e(1,0,n3+1,n5,1,1,n8)+J3e(0,1,n3+1,n5,1,1,n8)
-J3e(1,1,n3+1,n5,1,1,n8)
+(2*(3*d-n3-2*(n5+n8)-5)*J3e(1,1,n3+1,n5,1,1,n8-1)
    +n5*(J3e(1,0,n3+1,n5+1,1,1,n8-1)-J3e(1,1,n3+1,n5+1,1,1,n8-1)))
/(n8-1)$

% raise n3 or n1 or n2 at n1=n2=n6=n7=n8=1: (0)
procedure J3er3(n3,n5);
-(J3e(2,1,n3,n5,1,1,1)+J3e(1,2,n3,n5,1,1,1)+n3*J3e(1,1,n3+1,n5,1,1,1))
/(3*d-n3-2*n5-8)$

% raise n8 at n7 neq 1: 8+ 7- (11)
procedure J3er87(n1,n2,n3,n5,n6,n7,n8);
J3e(n1,n2,n3,n5-1,n6,n7,n8+1)
+((d-n1-n7-2*n8-1)*J3e(n1,n2,n3,n5,n6,n7-1,n8+1)
    +n1*(J3e(n1+1,n2,n3-1,n5,n6,n7-1,n8+1)+J3e(n1+1,n2,n3,n5,n6,n7-1,n8+1)
        -J3e(n1+1,n2-1,n3,n5,n6,n7-1,n8+1)))
/(n7-1)$

% raise n8 at n5 neq 1, n7=1: 8+ 5- (7')
procedure J3er85(n1,n2,n3,n5,n6,n8);
J3e(n1,n2,n3,n5,n6,0,n8+1)
+(-(d-n3-n5-1)*J3e(n1,n2,n3,n5-1,n6,1,n8+1)
    +n2*(J3e(n1,n2+1,n3-1,n5-1,n6,1,n8+1)-J3e(n1-1,n2+1,n3,n5-1,n6,1,n8+1))
    -n3*J3e(n1-1,n2,n3+1,n5-1,n6,1,n8+1))
/(n5-1)$

% raise n8 or n7 at n1 neq 1: 1- (3)
procedure J3er81(n1,n2,n3,n5,n6,n7,n8);
(n7*(J3e(n1-2,n2,n3,n5,n6,n7+1,n8)-J3e(n1-1,n2,n3-1,n5,n6,n7+1,n8))
    +n8*(J3e(n1-2,n2,n3,n5,n6,n7,n8+1)+J3e(n1-1,n2-1,n3,n5,n6,n7,n8+1)
        -J3e(n1-1,n2,n3-1,n5,n6,n7,n8+1)-J3e(n1-1,n2,n3,n5,n6,n7,n8+1)))
/(2*(n1-1))$

% raise n8 or n1 at n1=n5=1: (14)
procedure J3er8(n2,n3,n6,n8);
(-J3e(2,n2,n3-1,1,n6,1,n8)
    +n8*(J3e(1,n2,n3,1,n6,0,n8+1)-J3e(1,n2,n3,0,n6,1,n8+1)))
/(d-n8-3)$

% raise n5 at n8 neq 1: 5+ 8- (14)
procedure J3er58(n1,n2,n3,n5,n6,n7,n8);
J3e(n1,n2,n3,n5+1,n6,n7-1,n8)
-((d-n1-n8-2*n7+1)*J3e(n1,n2,n3,n5+1,n6,n7,n8-1)
    +n1*J3e(n1+1,n2,n3-1,n5+1,n6,n7,n8-1))
/(n8-1)$

% raise n5 at n7 neq 1, n8=1: 5+ 7- (8')
procedure J3er57(n1,n2,n3,n5,n6,n7);
J3e(n1,n2,n3,n5+1,n6,n7,0)
-((2*(d-n6)-n1-n3-n7-1)*J3e(n1,n2,n3,n5+1,n6,n7-1,1)
    +n1*J3e(n1+1,n2,n3,n5+1,n6,n7-1,1)
    +n3*J3e(n1,n2-1,n3+1,n5+1,n6,n7-1,1))
/(n7-1)$

% raise n5 or n7 or n1 at n1=n7=n8=1: (4')
procedure J3er5(n2,n3,n5,n6);
(J3e(0,n2,n3,n5,n6,2,1)-J3e(1,n2,n3-1,n5,n6,2,1)-2*J3e(2,n2,n3,n5,n6,1,1)
    +n5*(J3e(1,n2,n3,n5+1,n6,1,1)-J3e(1,n2-1,n3,n5+1,n6,1,1)))
/(2*(3*d-n2-n3-2*(n5+n6)-5))$

% raise n7 at n8 neq 1: 7+ 8- (14)
procedure J3er78(n1,n2,n3,n5,n6,n7,n8);
J3e(n1,n2,n3,n5-1,n6,n7+1,n8)
+((d-n1-n8-2*n7-1)*J3e(n1,n2,n3,n5,n6,n7+1,n8-1)
    +n1*J3e(n1+1,n2,n3-1,n5,n6,n7+1,n8-1))
/(n8-1)$

% raise n7 at n5 neq 1, n8=1: 7+ 5- (7')
procedure J3er75(n1,n2,n3,n5,n6,n7);
J3e(n1,n2,n3,n5,n6,n7+1,0)
+((d-n3-n5-2*n7-1)*J3e(n1,n2,n3,n5-1,n6,n7+1,1)
    +n2*(J3e(n1-1,n2+1,n3,n5-1,n6,n7+1,1)-J3e(n1,n2+1,n3-1,n5-1,n6,n7+1,1))
    +n3*J3e(n1-1,n2,n3+1,n5-1,n6,n7+1,1))
/(n5-1)$

% raise n7 or n1 at n1=n5=n8=1: (11)
procedure J3er7(n2,n3,n6,n7);
(J3e(2,n2-1,n3,1,n6,n7,1)-J3e(2,n2,n3-1,1,n6,n7,1)-J3e(2,n2,n3,1,n6,n7,1)
    +n7*(J3e(1,n2,n3,1,n6,n7+1,0)-J3e(1,n2,n3,0,n6,n7+1,1)))
/(d-n7-3)$

% I3d with numerator N^n0   N = 2 k1.k2   (n0>=0)
% -(d1+d3).v     (1) n0 0- (2- - 1) - 2 n1 1+ + n4 4+ (1- - 1) + n7 7+ (1- - 3-)
%     + n8 8+ (1- + 2- - 3- - 1) = 0
% -d2.v + 2 (0): (2) 2(3d-n1-n2-n3-2(n4+n5+n6+n7+n8-n0)) + n0 0- (1- - 1) + 2 n1 1+
%     + n5 5+ (2- - 1) + n7 7+ (3- - 1-) = 0
% d3.v           (3) - 2 n3 3+ + n6 6+ (3- - 2-) + n7 7+ (3- - 1-) + n8 8+ (1 + 3- - 1- - 2-) = 0
% - (d1+d2+d3).k2 + (0) - 2- (0): (5)
% 2(d-n4-n6-n7)+n0-n1-n2-n3-n8+1 - (3d-n1-n2-n3-2(n4+n5+n6+n7+n8-n0)+1) 2-
%     + 2 n0 0- 5- - n4 4+ 0+ + n8 8+ (5- - 7-) = 0
% d3.(k3-k2)     (6) d-n3-n6-n8-2n7 + n3 3+ 1- + n6 6+ (4- + 5- - 7- + 0+) + n8 8+ (5- - 7-) = 0
% d1.(k1-k3)     (7) d+n0-n3-n4-2n6 + n0 0- (5- - 7- + 8-) + n1 1+ (2- - 3-) + n3 3+ 2-
%     + n4 4+ (8- - 6-) = 0
% hom            (0) 3d-n1-n2-n3-2(n4+n5+n6+n7+n8-n0) + n1 1+ + n2 2+ + n3 3+ = 0

procedure II3d(n1,n2,n3,n4,n5,n6,n7,n8,n0);
if max(n4,n6)<=0 or max(n5,n7)<=0 or max(n1,n3,n2)<=0 or max(n4,n8,n5)<=0
    or max(n4,n8,n7)<=0 or max(n5,n8,n6)<=0 or max(n6,n8,n7)<=0
    or max(n3,n1,n4)<=0 or max(n1,n3,n6)<=0 or max(n3,n2,n5)<=0 or max(n2,n3,n7)<=0
    or max(n1,n4,n8)<=0 or max(n1,n7,n8)<=0 or max(n2,n5,n8)<=0 or max(n2,n6,n8)<=0
    or max(n4,n1,n7)<=0 or max(n5,n2,n6)<=0 or max(n6,n3,n7)<=0
    or max(n3,n6,n8)<=0 or max(n3,n7,n8)<=0
then 0
else if n0=0 then I3d(n1,n2,n3,n4,n5,n6,n7,n8)
else if n1<=0 then II3d1(-n1,n2,n3,n4,n5,n6,n7,n8,n0)
else if n2<=0 then II3d1(-n2,n1,n3,n5,n4,n7,n6,n8,n0)
else if n3<=0 then II3d3(n1,n2,-n3,n4,n5,n6,n7,n8,n0)
else if n1>1 then II3dl1(n1,n2,n3,n4,n5,n6,n7,n8,n0)
else if n2>1 then II3dl1(n2,n1,n3,n5,n4,n7,n6,n8,n0)
else if n3>1 then II3dl3(n3,n4,n5,n6,n7,n8,n0)
else if n4 neq 1 then II3dl04(n4,n5,n6,n7,n8,n0)
else if n5 neq 1 then II3dl04(n5,n4,n7,n6,n8,n0)
else if n6 neq 1 then II3dl06(n6,n7,n8,n0)
else if n7 neq 1 then II3dl06(n7,n6,n8,n0)
else II3dl0(n8,n0)$

remember II3d;

% (0+ + 1-)^n1 (5- + 6- - 3- - 8-)^n0 I3a(n3,n2,0,n5,n6,n7,n4,n8)
procedure II3d1(n1,n2,n3,n4,n5,n6,n7,n8,n0);
begin scalar p;
    p:=(!!0+!!1)^n1*(!!5+!!6-!!3-!!8)^n0*(!!0*!!1*!!3*!!5*!!6*!!8)^2;
    for all m0,m1,m3,m5,m6,m8 match !!0^m0*!!1^m1*!!3^m3*!!5^m5*!!6^m6*!!8^m8=
        II3a(n3+2-m1,n2,2-m3,n5,n6+2-m5,n7+2-m6,n4,n8+2-m8,m0-2);
    p:=p;
    for all m0,m1,m3,m5,m6,m8 clear !!0^m0*!!1^m1*!!3^m3*!!5^m5*!!6^m6*!!8^m8;
    return p
end$

% (0+ + 1- + 2- - 1)^n3 (5- - 3- - 4-)^n0 I3a(n1,n2,n4,n5,0,n8,n6,n7)
procedure II3d3(n1,n2,n3,n4,n5,n6,n7,n8,n0);
begin scalar p;
    p:=(!!0+!!1+!!2-1)^n3*(!!5-!!3-!!4)^n0*(!!0*!!1*!!2*!!3*!!4*!!5)^2;
    for all m0,m1,m2,m3,m4,m5 match !!0^m0*!!1^m1*!!2^m2*!!3^m3*!!4^m4*!!5^m5=
        II3a(n1+2-m1,n2+2-m2,n4+2-m3,n5+2-m4,2-m5,n8,n6,n7,m0-2);
    p:=p;
    for all m0,m1,m2,m3,m4,m5 clear !!0^m0*!!1^m1*!!2^m2*!!3^m3*!!4^m4*!!5^m5;
    return p
end$

% lower n1: 1- (2)
procedure II3dl1(n1,n2,n3,n4,n5,n6,n7,n8,n0);
(-2*(3*d-n1-n2-n3-2*(n4+n5+n6+n7+n8-n0)+1)*II3d(n1-1,n2,n3,n4,n5,n6,n7,n8,n0)
    +n5*(II3d(n1-1,n2,n3,n4,n5+1,n6,n7,n8,n0)-II3d(n1-1,n2-1,n3,n4,n5+1,n6,n7,n8,n0))
    +n7*(II3d(n1-2,n2,n3,n4,n5,n6,n7+1,n8,n0)-II3d(n1-1,n2,n3-1,n4,n5,n6,n7+1,n8,n0))
    +n0*(II3d(n1-1,n2,n3,n4,n5,n6,n7,n8,n0-1)-II3d(n1-2,n2,n3,n4,n5,n6,n7,n8,n0-1)))
/(2*(n1-1))$

% lower n3 at n1=n2=1: 3- (3)
procedure II3dl3(n3,n4,n5,n6,n7,n8,n0);
(n6*(II3d(1,1,n3-2,n4,n5,n6+1,n7,n8,n0)-II3d(1,0,n3-1,n4,n5,n6+1,n7,n8,n0))
    +n7*(II3d(1,1,n3-2,n4,n5,n6,n7+1,n8,n0)-II3d(0,1,n3-1,n4,n5,n6,n7+1,n8,n0))
    +n8*(II3d(1,1,n3-2,n4,n5,n6,n7,n8+1,n0)+II3d(1,1,n3-1,n4,n5,n6,n7,n8+1,n0)
        -II3d(0,1,n3-1,n4,n5,n6,n7,n8+1,n0)-II3d(1,0,n3-1,n4,n5,n6,n7,n8+1,n0)))
/(2*(n3-1))$

% lower n0 at n4 neq 1, n1=n2=n3=1: 0- 4- (5)
procedure II3dl04(n4,n5,n6,n7,n8,n0);
((2*(d-n4-n6-n7)+n0-n8-1)*II3d(1,1,1,n4-1,n5,n6,n7,n8,n0-1)
    -(3*d-2*(n4+n5+n6+n7+n8-n0+1))*II3d(1,0,1,n4-1,n5,n6,n7,n8,n0-1)
    +n8*(II3d(1,1,1,n4-1,n5-1,n6,n7,n8+1,n0-1)-II3d(1,1,1,n4-1,n5,n6,n7-1,n8+1,n0-1))
    +2*(n0-1)*II3d(1,1,1,n4-1,n5-1,n6,n7,n8,n0-2))
/(n4-1)$

% lower n0 at n6 neq 1, n1=n2=n3=n4=n5=1: 0- 6- (6)
procedure II3dl06(n6,n7,n8,n0);
II3d(1,1,1,1,1,n6,n7-1,n8,n0-1)
-II3d(1,1,1,1,0,n6,n7,n8,n0-1) - II3d(1,1,1,0,1,n6,n7,n8,n0-1)
-((d-n6-n8-2*n7)*II3d(1,1,1,1,1,n6-1,n7,n8,n0-1)
    +n8*(II3d(1,1,1,1,0,n6-1,n7,n8+1,n0-1)-II3d(1,1,1,1,1,n6-1,n7-1,n8+1,n0-1))
    +II3d(0,1,2,1,1,n6-1,n7,n8,n0-1))
/(n6-1)$

% lower n0 or raise n4 at n1=n2=n3=n4=n5=n6=n7=1: (7)
procedure II3dl0(n8,n0);
(II3d(2,1,0,1,1,1,1,n8,n0)-II3d(2,0,1,1,1,1,1,n8,n0)
    -II3d(1,1,1,2,1,1,1,n8-1,n0)+II3d(1,1,1,2,1,0,1,n8,n0)
    -II3d(1,0,2,1,1,1,1,n8,n0)
    +n0*(II3d(1,1,1,1,1,1,0,n8,n0-1)-II3d(1,1,1,1,1,1,1,n8-1,n0-1)
        -II3d(1,1,1,1,0,1,1,n8,n0-1)))
/(d+n0-4)$

% Ie
%
%        /|\        D1 = (k3+p).v      D5 = -k3^2
%       / | \       D2 = (k1+k3+p).v   D6 = -k1^2
%     6/  |8 \7     D3 = (k1+p).v      D7 = -k2^2
%     /   |   \     D4 = (k2+p).v      D8 = -(k1-k2)^2
%  1 /2  3| 4  \
% ===============
%  \   /
%   \-/
%    5
%
% Limiting cases
% I3e(0,n2,n3,n4,n5,n6,n7,n8) = I1(n2,n5) I2b(n3+n2+2n5-d,n4,n6,n7,n8)
% I3e(n1,0,n3,n4,n5,n6,n7,n8) = I1(n1,n5) I2(n3,n4,n6,n7,n8)
% I3e(n1,n2,n3,0,n5,n6,n7,n8) = G1(n7,n8) J2a(n3,n1,n2,n6+n7+n8-d/2,n5)
% I3e(n1,n2,n3,n4,n5,n6,0,n8) = I1(n4,n8) J2b(n3+n4+2n8-d,n1,n2,n6,n5)
% I3e(n1,n2,n3,n4,n5,n6,n7,0) = I1(n4,n7) J2(n1,n3,n2,n5,n6)
%
% Recurrence relation
% 1 - 1- + 2- - 3- = 0

procedure I3e(n1,n2,n3,n4,n5,n6,n7,n8);
if n5<=0 or max(n1,n2)<=0 or max(n6,n7)<=0 or max(n6,n8)<=0 or max(n7,n8)<=0
    or max(n4,n7)<=0 or max(n4,n8)<=0 or max(n2,n3,n4)<=0 or max(n2,n3,n6)<=0
    or max(n2,n3,n8)<=0
then 0
else if n1=0 then I1(n2,n5)*I2b(n3+n2+2*n5,n4,n6,n7,n8)
else if n2=0 then I1(n1,n5)*I2(n3,n4,n6,n7,n8)
else if n4=0 then G1(n7,n8)*J2a(n3,n1,n2,n6+n7+n8,n5)
else if n7=0 then I1(n4,n8)*J2b(n3+n4+2*n8,n1,n2,n6,n5)
else if n8=0 then I1(n4,n7)*J2(n1,n3,n2,n5,n6)
else if n3=0 then J3d(n1,n4,n2,n5,n7,n6,n8)
else if n1<0 then I3e(n1+1,n2,n3,n4,n5,n6,n7,n8)
    +I3e(n1+1,n2-1,n3,n4,n5,n6,n7,n8)-I3e(n1+1,n2,n3-1,n4,n5,n6,n7,n8)
else if n2<0 then I3e(n1-1,n2+1,n3,n4,n5,n6,n7,n8)
    +I3e(n1,n2+1,n3-1,n4,n5,n6,n7,n8)-I3e(n1,n2+1,n3,n4,n5,n6,n7,n8)
else if n3<0 then I3e(n1,n2,n3+1,n4,n5,n6,n7,n8)
    -I3e(n1-1,n2,n3+1,n4,n5,n6,n7,n8)+I3e(n1,n2-1,n3+1,n4,n5,n6,n7,n8)
else I3e(n1-1,n2,n3,n4,n5,n6,n7,n8)
    -I3e(n1,n2-1,n3,n4,n5,n6,n7,n8)+I3e(n1,n2,n3-1,n4,n5,n6,n7,n8)$

remember I3e;

% I3e with numerators N13^n13*N23^n23   N13 = 2 k1.k3   N23 = 2 k2.k3
procedure II3e(n1,n2,n3,n4,n5,n6,n7,n8,n13,n23);
if n5<=0 or max(n1,n2)<=0 or max(n6,n7)<=0 or max(n6,n8)<=0 or max(n7,n8)<=0
    or max(n4,n7)<=0 or max(n4,n8)<=0 or max(n2,n3,n4)<=0 or max(n2,n3,n6)<=0
    or max(n2,n3,n8)<=0
then 0
else if n13=0 and n23=0 then I3e(n1,n2,n3,n4,n5,n6,n7,n8)
else if n1<=0 then II3e1(-n1,n2,n3,n4,n5,n6,n7,n8,n13,n23)
else if n2<=0 then II3e2(n1,-n2,n3,n4,n5,n6,n7,n8,n13,n23)
else if n3<=0 then II3e3(n1,n2,-n3,n4,n5,n6,n7,n8,n13,n23)
else II3e(n1-1,n2,n3,n4,n5,n6,n7,n8,n13,n23)
    -II3e(n1,n2-1,n3,n4,n5,n6,n7,n8,n13,n23)+II3e(n1,n2,n3-1,n4,n5,n6,n7,n8,n13,n23)$

remember II3e;

% (1 + 1- - 3-)^n1 (6- + 8- - 4-)^n13 (5- - 7- + 8- + 0+)^n23
%     Ic(n2,n4,n3,0,n7,n5,n8,n6)
procedure II3e1(n1,n2,n3,n4,n5,n6,n7,n8,n13,n23);
begin scalar p;
    p:=(1+!!1-!!3)^n1*(!!6-!!4+!!8)^n13*(!!5-!!7+!!8+!!0)^n23
        *(!!0*!!1*!!3*!!4*!!5*!!6*!!7*!!8)^2;
    for all m0,m1,m3,m4,m5,m6,m7,m8 match
        !!0^m0*!!1^m1*!!3^m3*!!4^m4*!!5^m5*!!6^m6*!!7^m7*!!8^m8=
        II3c(n2+2-m1,n4,n3+2-m3,2-m4,n7+2-m5,n5+2-m6,n8+2-m7,n6+2-m8,m0-2);
    p:=p;
    for all m0,m1,m3,m4,m5,m6,m7,m8 clear
        !!0^m0*!!1^m1*!!3^m3*!!4^m4*!!5^m5*!!6^m6*!!7^m7*!!8^m8;
    return p
end$

% (1- + 3- - 1)^n2 (6- - 4- - 8-)^n13 (0+)^n23 Ic(n1,n4,n3,n5,n7,0,n8,n6)
procedure II3e2(n1,n2,n3,n4,n5,n6,n7,n8,n13,n23);
begin scalar p;
    p:=(!!1+!!3-1)^n2*(!!6-!!4-!!8)^n13*(!!0)^n23*(!!0*!!1*!!3*!!4*!!6*!!8)^2;
    for all m0,m1,m3,m4,m6,m8 match !!0^m0*!!1^m1*!!3^m3*!!4^m4*!!6^m6*!!8^m8=
        II3c(n1+2-m1,n4,n3+2-m3,n5+2-m4,n7,2-m6,n8,n6+2-m8,m0-2);
    p:=p;
    for all m0,m1,m3,m4,m6,m8 clear !!0^m0*!!1^m1*!!3^m3*!!4^m4*!!6^m6*!!8^m8;
    return p
end$

% (1 - 1- + 3-)^n3 (4- - 6- + 8- + 0+)^n13 (0+)^n23 Id(n1,n4,n2,n5,n7,0,n6,n8)
procedure II3e3(n1,n2,n3,n4,n5,n6,n7,n8,n13,n23);
begin scalar p;
    p:=(1-!!1+!!3)^n3*(!!4-!!6+!!8+!!0)^n13*(!!0)^n23*(!!0*!!1*!!3*!!4*!!6*!!8)^2;
    for all m0,m1,m3,m4,m6,m8 match !!0^m0*!!1^m1*!!3^m3*!!4^m4*!!6^m6*!!8^m8=
        II3d(n1+2-m1,n4,n2+2-m3,n5+2-m4,n7,2-m6,n6,n8+2-m8,m0-2);
    p:=p;
    for all m0,m1,m3,m4,m6,m8 clear !!0^m0*!!1^m1*!!3^m3*!!4^m4*!!6^m6*!!8^m8;
    return p
end$

% If
%
%      /|\        D1 = (k1+p).v      D5 = -k3^2
%     / | \       D2 = (k1+k3+p).v   D6 = -k1^2
%   6/  |8 \7     D3 = (k2+k3+p).v   D7 = -k2^2
%   /   |   \     D4 = (k2+p).v      D8 = -(k1-k2)^2
%  /  2 | 3  \
% =============
%   1 \   / 4
%      \-/
%       5
%
% Limiting cases
% I3f(n1,0,n3,n4,n5,n6,n7,n8) = I1(n3,n5) I2b(n4+n3+2n5-d,n1,n7,n6,n8)
% I3f(n1,n2,0,n4,n5,n6,n7,n8) = I1(n2,n5) I2b(n1+n2+2n5-d,n4,n6,n7,n8)
% I3f(n1,n2,n3,n4,n5,0,n7,n8) = J2(n1,n3,n2,n8,n5) I1(n1+n2+n3+n4+2(n5+n8-d),n7)
% I3f(n1,n2,n3,n4,n5,n6,0,n8) = J2(n4,n2,n3,n8,n5) I1(n1+n2+n3+n4+2(n5+n8-d),n6)
%
% Recurrence relation
% 1- - 2- + 3- - 4- = 0

procedure I3f(n1,n2,n3,n4,n5,n6,n7,n8);
if n5<=0 or max(n2,n3)<=0 or max(n6,n7)<=0 or max(n6,n8)<=0 or max(n7,n8)<=0
    or max(n1,n2,n6)<=0 or max(n1,n2,n8)<=0 or max(n3,n4,n7)<=0 or max(n3,n4,n8)<=0
then 0
else if n2=0 then I1(n3,n5)*I2b(n4+n3+2*n5,n1,n7,n6,n8)
else if n3=0 then I1(n2,n5)*I2b(n1+n2+2*n5,n4,n6,n7,n8)
else if n6=0 then sub(B(1)=B(4),B(2)=B(3),J2(n1,n3,n2,n8,n5))*I1c(n1+n2+n3+n4+2*(n5+n8),n7)
else if n7=0 then sub(B(1)=B(4),B(2)=B(3),J2(n4,n2,n3,n8,n5))*I1c(n1+n2+n3+n4+2*(n5+n8),n6)
else if n1=0 then J3e(n2,n4,n3,n7,n5,n8,n6)
else if n4=0 then J3e(n3,n1,n2,n6,n5,n8,n7)
else if n2<0 then I3f(n1-1,n2+1,n3,n4,n5,n6,n7,n8)
    +I3f(n1,n2+1,n3-1,n4,n5,n6,n7,n8)-I3f(n1,n2+1,n3,n4-1,n5,n6,n7,n8)
else if n3<0 then I3f(n1,n2-1,n3+1,n4,n5,n6,n7,n8)
    +I3f(n1,n2,n3+1,n4-1,n5,n6,n7,n8)-I3f(n1-1,n2,n3+1,n4,n5,n6,n7,n8)
else if n1<0 then I3f(n1+1,n2-1,n3,n4,n5,n6,n7,n8)
    -I3f(n1+1,n2,n3-1,n4,n5,n6,n7,n8)+I3f(n1+1,n2,n3,n4-1,n5,n6,n7,n8)
else if n4<0 then I3f(n1-1,n2,n3,n4+1,n5,n6,n7,n8)
    -I3f(n1,n2-1,n3,n4+1,n5,n6,n7,n8)+I3f(n1,n2,n3-1,n4+1,n5,n6,n7,n8)
else if n1<n4 then I3f(n1-1,n2,n3,n4+1,n5,n6,n7,n8)
    -I3f(n1,n2-1,n3,n4+1,n5,n6,n7,n8)+I3f(n1,n2,n3-1,n4+1,n5,n6,n7,n8)
else I3f(n1+1,n2-1,n3,n4,n5,n6,n7,n8)
    -I3f(n1+1,n2,n3-1,n4,n5,n6,n7,n8)+I3f(n1+1,n2,n3,n4-1,n5,n6,n7,n8)$

remember I3f;

% I3f with numerators N13^n13*N23^n23   N13 = 2 k1.k3   N23 = 2 k2.k3
procedure II3f(n1,n2,n3,n4,n5,n6,n7,n8,n13,n23);
if n5<=0 or max(n2,n3)<=0 or max(n6,n7)<=0 or max(n6,n8)<=0 or max(n7,n8)<=0
    or max(n1,n2,n6)<=0 or max(n1,n2,n8)<=0 or max(n3,n4,n7)<=0 or max(n3,n4,n8)<=0
then 0
else if n13=0 and n23=0 then I3f(n1,n2,n3,n4,n5,n6,n7,n8)
else if n2<=0 then II3f2(n1,-n2,n3,n4,n5,n6,n7,n8,n13,n23)
else if n3<=0 then II3f2(n4,-n3,n2,n1,n5,n7,n6,n8,n23,n13)
else if n1<=0 then II3f1(-n1,n2,n3,n4,n5,n6,n7,n8,n13,n23)
else if n4<=0 then II3f1(-n4,n3,n2,n1,n5,n7,n6,n8,n23,n13)
else if n1<n4 then II3f(n1-1,n2,n3,n4+1,n5,n6,n7,n8,n13,n23)
    -II3f(n1,n2-1,n3,n4+1,n5,n6,n7,n8,n13,n23)+II3f(n1,n2,n3-1,n4+1,n5,n6,n7,n8,n13,n23)
else II3f(n1+1,n2-1,n3,n4,n5,n6,n7,n8,n13,n23)
    -II3f(n1+1,n2,n3-1,n4,n5,n6,n7,n8,n13,n23)+II3f(n1+1,n2,n3,n4-1,n5,n6,n7,n8,n13,n23)$

remember II3f;

% (1- + 2- - 3-)^n2 (4- - 6- + 8- + 0+)^n13 (7- + 8- - 5-)^n23
%     Ic(n1,n3,n4,n6,0,n8,n5,n7)
procedure II3f2(n1,n2,n3,n4,n5,n6,n7,n8,n13,n23);
begin scalar p;
    p:=(!!1+!!2-!!3)^n2*(!!4-!!6+!!8+!!0)^n13*(!!7+!!8-!!5)^n23
        *(!!0*!!1*!!2*!!3*!!4*!!5*!!6*!!7*!!8)^2;
    for all m0,m1,m2,m3,m4,m5,m6,m7,m8 match
        !!0^m0*!!1^m1*!!2^m2*!!3^m3*!!4^m4*!!5^m5*!!6^m6*!!7^m7*!!8^m8=
        II3c(n1+2-m1,n3+2-m2,n4+2-m3,n6+2-m4,2-m5,n8+2-m6,n5+2-m7,n7+2-m8,m0-2);
    p:=p;
    for all m0,m1,m2,m3,m4,m5,m6,m7,m8 clear
        !!0^m0*!!1^m1*!!2^m2*!!3^m3*!!4^m4*!!5^m5*!!6^m6*!!7^m7*!!8^m8;
    return p
end$

% (1- + 2- - 3-)^n1 (6- - 4- + 8-)^n13 (5- - 7- + 8- + 0+)^n23
%     Id(n2,n4,n3,0,n7,n5,n8,n6)
procedure II3f1(n1,n2,n3,n4,n5,n6,n7,n8,n13,n23);
begin scalar p;
    p:=(!!1+!!2-!!3)^n1*(!!6-!!4+!!8)^n13*(!!5-!!7+!!8+!!0)^n23
        *(!!0*!!1*!!2*!!3*!!4*!!5*!!6*!!7*!!8)^2;
    for all m0,m1,m2,m3,m4,m5,m6,m7,m8 match
        !!0^m0*!!1^m1*!!2^m2*!!3^m3*!!4^m4*!!5^m5*!!6^m6*!!7^m7*!!8^m8=
        II3d(n2+2-m1,n4+2-m2,n3+2-m3,2-m4,n7+2-m5,n5+2-m6,n8+2-m7,n6+2-m8,m0-2);
    p:=p;
    for all m0,m1,m2,m3,m4,m5,m6,m7,m8 clear
        !!0^m0*!!1^m1*!!2^m2*!!3^m3*!!4^m4*!!5^m5*!!6^m6*!!7^m7*!!8^m8;
    return p
end$

% Ig
%
%        /|\        D1 = (k3+p).v      D5 = -k3^2
%       / | \       D2 = (k1+k3+p).v   D6 = -k1^2
%     6/  |8 \7     D3 = (k2+k3+p).v   D7 = -k2^2
%     /   |   \     D4 = (k2+p).v      D8 = -(k1-k2)^2
%  1 / 2  |3   \
% ===============
%  \        / 4
%   \------/
%      5
%
% Limiting cases
% I3g(n1,0,n3,n4,n5,n6,n7,n8) = G1(n6,n8) J2a(n4,n1,n3,n7+n6+n8-d/2,n5)
% I3g(n1,n2,n3,0,n5,n6,n7,n8) = I2(n2,n3,n6,n7,n8) I1(n1+n2+n3+2(n6+n7+n8-d),n5)
% I3g(n1,n2,n3,n4,n5,0,n7,n8) = I1(n2,n8) J2c(n1,n4,n3+n2+2n8-d,n5,n7)
%
% Recurrence relation
% 1 - 1- + 3- - 4- = 0

procedure I3g(n1,n2,n3,n4,n5,n6,n7,n8);
if n5<=0 or max(n6,n7)<=0 or max(n6,n8)<=0 or max(n7,n8)<=0 or max(n2,n6)<=0
    or max(n2,n8)<=0 or max(n1,n2,n3)<=0 or max(n2,n3,n4)<=0 or max(n3,n4,n7)<=0
    or max(n3,n4,n8)<=0
then 0
else if n2=0 then G1(n6,n8)*J2a(n4,n1,n3,n7+n6+n8,n5)
else if n4=0 then sub(B(1)=B(4),B(2)=B(3),I2(n2,n3,n6,n7,n8))*I1c(n1+n2+n3+2*(n6+n7+n8),n5)
else if n6=0 then I1(n2,n8)*J2c(n1,n4,n3+n2+2*n8,n5,n7)
else if n1=0 then J3e(n2,n4,n3,n7,n5,n8,n6)
else if n3=0 then J3d(n1,n4,n2,n5,n7,n6,n8)
else if n4<0 then I3g(n1,n2,n3,n4+1,n5,n6,n7,n8)
    -I3g(n1-1,n2,n3,n4+1,n5,n6,n7,n8)+I3g(n1,n2,n3-1,n4+1,n5,n6,n7,n8)
else if n1<0 then I3g(n1+1,n2,n3,n4,n5,n6,n7,n8)
    -I3g(n1+1,n2,n3,n4-1,n5,n6,n7,n8)+I3g(n1+1,n2,n3-1,n4,n5,n6,n7,n8)
else if n3<0 then I3g(n1,n2,n3+1,n4-1,n5,n6,n7,n8)
    -I3g(n1,n2,n3+1,n4,n5,n6,n7,n8)+I3g(n1-1,n2,n3+1,n4,n5,n6,n7,n8)
else I3g(n1-1,n2,n3,n4,n5,n6,n7,n8)
    -I3g(n1,n2,n3-1,n4,n5,n6,n7,n8)+I3g(n1,n2,n3,n4-1,n5,n6,n7,n8)$

remember I3g;

% I3g with numerators N13^n13*N23^n23   N13 = 2 k1.k3   N23 = 2 k2.k3
procedure II3g(n1,n2,n3,n4,n5,n6,n7,n8,n13,n23);
if n5<=0 or max(n6,n7)<=0 or max(n6,n8)<=0 or max(n7,n8)<=0 or max(n2,n6)<=0
    or max(n2,n8)<=0 or max(n1,n2,n3)<=0 or max(n2,n3,n4)<=0 or max(n3,n4,n7)<=0
    or max(n3,n4,n8)<=0
then 0
else if n13=0 and n23=0 then I3g(n1,n2,n3,n4,n5,n6,n7,n8)
else if n1<=0 then II3g1(-n1,n2,n3,n4,n5,n6,n7,n8,n13,n23)
else if n3<=0 then II3g3(n1,n2,-n3,n4,n5,n6,n7,n8,n13,n23)
else if n4<=0 then II3g4(n1,n2,n3,-n4,n5,n6,n7,n8,n13,n23)
else II3g(n1-1,n2,n3,n4,n5,n6,n7,n8,n13,n23)
    -II3g(n1,n2,n3-1,n4,n5,n6,n7,n8,n13,n23)+II3g(n1,n2,n3,n4-1,n5,n6,n7,n8,n13,n23)$

remember II3g;

% (1 - 2- + 3-)^n1 (6- - 4- + 8-)^n13 (5- - 7- + 8- + 0+)^n23
%     Id(n2,n4,n3,0,n7,n5,n8,n6)
procedure II3g1(n1,n2,n3,n4,n5,n6,n7,n8,n13,n23);
begin scalar p;
    p:=(1-!!2+!!3)^n1*(!!6-!!4+!!8)^n13*(!!5-!!7+!!8+!!0)^n23
        *(!!0*!!2*!!3*!!4*!!5*!!6*!!7*!!8)^2;
    for all m0,m2,m3,m4,m5,m6,m7,m8 match
        !!0^m0*!!2^m2*!!3^m3*!!4^m4*!!5^m5*!!6^m6*!!7^m7*!!8^m8=
        II3d(n2,n4+2-m2,n3+2-m3,2-m4,n7+2-m5,n5+2-m6,n8+2-m7,n6+2-m8,m0-2);
    p:=p;
    for all m0,m2,m3,m4,m5,m6,m7,m8 clear
        !!0^m0*!!2^m2*!!3^m3*!!4^m4*!!5^m5*!!6^m6*!!7^m7*!!8^m8;
    return p
end$

% (1- + 2- - 1)^n3 (4- - 6- + 8- + 0+)^n13 (0+)^n23 Id(n1,n4,n2,n5,n7,0,n6,n8)
procedure II3g3(n1,n2,n3,n4,n5,n6,n7,n8,n13,n23);
begin scalar p;
    p:=(!!1+!!2-1)^n3*(!!4-!!6+!!8+!!0)^n13*!!0^n23*(!!0*!!1*!!2*!!4*!!6*!!8)^2;
    for all m0,m1,m2,m4,m6,m8 match !!0^m0*!!1^m1*!!2^m2*!!4^m4*!!6^m6*!!8^m8=
        II3d(n1+2-m1,n4+2-m2,n2,n5+2-m4,n7,2-m6,n6,n8+2-m8,m0-2);
    p:=p;
    for all m0,m1,m2,m4,m6,m8 clear !!0^m0*!!1^m1*!!2^m2*!!4^m4*!!6^m6*!!8^m8;
    return p
end$

% (1 - 1- + 2-)^n4 (4- + 6- - 0+)^n13 (4- - 5- + 8-)^n23
%     Ib(n1,n3,n2,n5,0,n6,n8,n7)
procedure II3g4(n1,n2,n3,n4,n5,n6,n7,n8,n13,n23);
begin scalar p;
    p:=(1-!!1+!!2)^n4*(!!4+!!6-!!0)^n13*(!!4-!!5+!!8)^n23*(!!0*!!1*!!2*!!4*!!5*!!6*!!8)^2;
    for all m0,m1,m2,m4,m5,m6,m8 match !!0^m0*!!1^m1*!!2^m2*!!4^m4*!!5^m5*!!6^m6*!!8^m8=
        II3b(n1+2-m1,n3+2-m2,n2,n5+2-m4,2-m5,n6+2-m6,n8,n7+2-m8,m0-2);
    p:=p;
    for all m0,m1,m2,m4,m5,m6,m8 clear !!0^m0*!!1^m1*!!2^m2*!!4^m4*!!5^m5*!!6^m6*!!8^m8;
    return p
end$

% Ih
%
%          8            D1 = (k2+p).v      D6 = -k2^2
%       /-----\         D2 = (k1+k2+p).v   D7 = -k3^2
%      /       \        D3 = (k1+p).v      D8 = -k1^2
%   1 / 2  3  4 \ 5     D4 = (k1+k3+p).v
% ===================   D5 = (k3+p).v
%  \     /   \     /
%   \---/     \---/
%     6         7
%
% Limiting cases
% I3h(0,n2,n3,n4,n5,n6,n7,n8) = I1(n2,n6) J2b(n3+n2+2n6-d,n5,n4,n8,n7)
% I3h(n1,n2,n3,n4,0,n6,n7,n8) = I1(n4,n7) J2b(n3+n4+2n7-d,n1,n2,n8,n6)
% I3h(n1,0,n3,n4,n5,n6,n7,n8) = I1(n1,n6) J2(n3,n5,n4,n8,n7)
% I3h(n1,n2,n3,0,n5,n6,n7,n8) = I1(n5,n7) J2(n1,n3,n2,n6,n8)
%
% Recurrence relations
% 1 - 1- + 2- - 3- = 0
% 1 - 3- + 4- - 5- = 0

procedure I3h(n1,n2,n3,n4,n5,n6,n7,n8);
if n6<=0 or n7<=0 or n8<=0 or max(n1,n2)<=0 or max(n4,n5)<=0 or max(n2,n3,n4)<=0
then 0
else if n2=0 then I1(n1,n6)*J2(n3,n5,n4,n8,n7)
else if n4=0 then I1(n5,n7)*J2(n1,n3,n2,n6,n8)
else if n1=0 then I1(n2,n6)*J2b(n3+n2+2*n6,n5,n4,n8,n7)
else if n5=0 then I1(n4,n7)*J2b(n3+n4+2*n7,n1,n2,n8,n6)
else if n3=0 then J3f(n1,n2,n4,n5,n6,n7,n8)
else if n2<0 then I3h(n1-1,n2+1,n3,n4,n5,n6,n7,n8)
    +I3h(n1,n2+1,n3-1,n4,n5,n6,n7,n8)-I3h(n1,n2+1,n3,n4,n5,n6,n7,n8)
else if n4<0 then I3h(n1,n2,n3-1,n4+1,n5,n6,n7,n8)
    +I3h(n1,n2,n3,n4+1,n5-1,n6,n7,n8)-I3h(n1,n2,n3,n4+1,n5,n6,n7,n8)
else if n1<0 then I3h(n1+1,n2,n3,n4,n5,n6,n7,n8)
    +I3h(n1+1,n2-1,n3,n4,n5,n6,n7,n8)-I3h(n1+1,n2,n3-1,n4,n5,n6,n7,n8)
else if n5<0 then I3h(n1,n2,n3,n4,n5+1,n6,n7,n8)
    +I3h(n1,n2,n3,n4-1,n5+1,n6,n7,n8)-I3h(n1,n2,n3-1,n4,n5+1,n6,n7,n8)
else if n3<0 then
    if max(n4,n5)<max(n1,n2)
    then I3h(n1,n2,n3+1,n4,n5,n6,n7,n8)
        +I3h(n1,n2,n3+1,n4-1,n5,n6,n7,n8)-I3h(n1,n2,n3+1,n4,n5-1,n6,n7,n8)
    else I3h(n1,n2,n3+1,n4,n5,n6,n7,n8)
        +I3h(n1,n2-1,n3+1,n4,n5,n6,n7,n8)-I3h(n1-1,n2,n3+1,n4,n5,n6,n7,n8)
else if max(n4,n5)<max(n1,n2) then I3h(n1,n2,n3-1,n4,n5,n6,n7,n8)
    +I3h(n1,n2,n3,n4,n5-1,n6,n7,n8)-I3h(n1,n2,n3,n4-1,n5,n6,n7,n8)
else I3h(n1,n2,n3-1,n4,n5,n6,n7,n8)
    +I3h(n1-1,n2,n3,n4,n5,n6,n7,n8)-I3h(n1,n2-1,n3,n4,n5,n6,n7,n8)$

remember I3h;

% I3h(n1,n2,0,n4,n5,n6,n7,n8)
procedure J3f(n1,n2,n4,n5,n6,n7,n8);
if n6<=0 or n7<=0 or n8<=0 or max(n1,n2)<=0 or max(n2,n4)<=0 or max(n4,n5)<=0
then 0
else if n2=0 then I1(n1,n6)*I1(n4,n8)*I1a(n5+n4+2*n8,n7)*B(2)
else if n4=0 then I1(n5,n7)*I1(n2,n8)*I1a(n1+n2+2*n8,n6)*B(2)
else if n1=0 then I1(n2,n6)*J2b(n2+2*n6,n5,n4,n8,n7)
else if n5=0 then I1(n4,n7)*J2b(n4+2*n7,n1,n2,n8,n6)
else if n2<0 then J3f(n1-1,n2+1,n4,n5,n6,n7,n8)
    +J3f(n1,n2+1,n4-1,n5,n6,n7,n8)-J3f(n1,n2+1,n4,n5-1,n6,n7,n8)
else if n4<0 then J3f(n1,n2-1,n4+1,n5,n6,n7,n8)
    +J3f(n1,n2,n4+1,n5-1,n6,n7,n8)-J3f(n1-1,n2,n4+1,n5,n6,n7,n8)
else if n1<0 then J3f(n1+1,n2-1,n4,n5,n6,n7,n8)
    +J3f(n1+1,n2,n4,n5-1,n6,n7,n8)-J3f(n1+1,n2,n4-1,n5,n6,n7,n8)
else if n5<0 then J3f(n1-1,n2,n4,n5+1,n6,n7,n8)
    +J3f(n1,n2,n4-1,n5+1,n6,n7,n8)-J3f(n1,n2-1,n4,n5+1,n6,n7,n8)
else if n5<n1 then J3f(n1+1,n2-1,n4,n5,n6,n7,n8)
    +J3f(n1+1,n2,n4,n5-1,n6,n7,n8)-J3f(n1+1,n2,n4-1,n5,n6,n7,n8)
else J3f(n1-1,n2,n4,n5+1,n6,n7,n8)
    +J3f(n1,n2,n4-1,n5+1,n6,n7,n8)-J3f(n1,n2-1,n4,n5+1,n6,n7,n8)$

% I3h with numerators N12^n12*N13^n13*N23^n23
procedure II3h(n1,n2,n3,n4,n5,n6,n7,n8,n12,n13,n23);
if n6<=0 or n7<=0 or n8<=0 or max(n1,n2)<=0 or max(n4,n5)<=0 or max(n2,n3,n4)<=0
then 0
else if n12=0 and n13=0 and n23=0 then I3h(n1,n2,n3,n4,n5,n6,n7,n8)
else if n2<=0 and n4<=0 then K3a(n1,n5,n3,n6,n7,n8,-n2,-n4,n23,n12,n13)
else if n2<=0 and n5<=0 then K3b(n1,n4,n3,n6,n7,n8,-n2,-n5,0,0,n12,n13,n23)
else if n4<=0 and n1<=0 then K3b(n5,n2,n3,n7,n6,n8,-n4,-n1,0,0,n13,n12,n23)
else if n2<=0 and n3<=0 then K3b(n1,n4,n5,n6,n8,n7,0,-n3,0,-n2,n23,n13,n12)
else if n4<=0 and n3<=0 then K3b(n5,n2,n1,n7,n8,n6,0,-n3,0,-n4,n23,n12,n13)
else if n1<=0 and n5<=0 then K3c(n2,n4,n3,n6,n7,n8,-n1,-n5,0,n12,n13,n23)
else if n1<=0 and n3<=0 then K3e(n2,n5,n4,n7,n8,n6,-n1,0,-n3,n12,n23,n13)
else if n5<=0 and n3<=0 then K3e(n4,n1,n2,n6,n8,n7,-n5,0,-n3,n13,n23,n12)
else if n3<=0 then JJ3f(n1,n2,n3,n4,n5,n6,n7,n8,n12,n13,n23)
else if n1<=0 or n2<=0 or (n4>0 and n5>0 and max(n4,n5)<=max(n1,n2))
then II3h(n1,n2,n3-1,n4,n5,n6,n7,n8,n12,n13,n23)
    -II3h(n1,n2,n3,n4-1,n5,n6,n7,n8,n12,n13,n23)
    +II3h(n1,n2,n3,n4,n5-1,n6,n7,n8,n12,n13,n23)
else II3h(n1-1,n2,n3,n4,n5,n6,n7,n8,n12,n13,n23)
    -II3h(n1,n2-1,n3,n4,n5,n6,n7,n8,n12,n13,n23)
    +II3h(n1,n2,n3-1,n4,n5,n6,n7,n8,n12,n13,n23)$

remember II3h;

% II3h(n1,n2,-n3,n4,n5,n6,n7,n8,n12,n13,n23)
procedure JJ3f(n1,n2,n3,n4,n5,n6,n7,n8,n12,n13,n23);
if n6<=0 or n7<=0 or n8<=0 or max(n1,n2)<=0 or max(n4,n5)<=0 or max(n2,n4)<=0
then 0
else if n2<=0 then K3b(n1,n4,n5,n6,n8,n7,0,-n3,0,-n2,n23,n13,n12)
else if n4<=0 then K3b(n5,n2,n1,n7,n8,n6,0,-n3,0,-n4,n23,n12,n13)
else if n1<=0 then K3e(n2,n5,n4,n7,n8,n6,-n1,0,-n3,n12,n23,n13)
else if n5<=0 then K3e(n4,n1,n2,n6,n8,n7,-n5,0,-n3,n13,n23,n12)
else if max(n4,n5)<=max(n1,n2)
then
    if n2<=n1
    then JJ3f(n1+1,n2-1,n3,n4,n5,n6,n7,n8,n12,n13,n23)
        -JJ3f(n1+1,n2,n3,n4-1,n5,n6,n7,n8,n12,n13,n23)
        +JJ3f(n1+1,n2,n3,n4,n5-1,n6,n7,n8,n12,n13,n23)
    else JJ3f(n1-1,n2+1,n3,n4,n5,n6,n7,n8,n12,n13,n23)
        -JJ3f(n1,n2+1,n3,n4,n5-1,n6,n7,n8,n12,n13,n23)
        +JJ3f(n1,n2+1,n3,n4-1,n5,n6,n7,n8,n12,n13,n23)
else
    if n4<=n5
    then JJ3f(n1-1,n2,n3,n4,n5+1,n6,n7,n8,n12,n13,n23)
        -JJ3f(n1,n2-1,n3,n4,n5+1,n6,n7,n8,n12,n13,n23)
        +JJ3f(n1,n2,n3,n4-1,n5+1,n6,n7,n8,n12,n13,n23)
    else JJ3f(n1,n2-1,n3,n4+1,n5,n6,n7,n8,n12,n13,n23)
        -JJ3f(n1-1,n2,n3,n4+1,n5,n6,n7,n8,n12,n13,n23)
        +JJ3f(n1,n2,n3,n4+1,n5-1,n6,n7,n8,n12,n13,n23)$

% Ii
%
%          7
%        /---\        D1 = (k1+p).v         D6 = -k1^2
%       /  8  \       D2 = (k1+k2+p).v      D7 = -k2^2
%      /  /-\  \      D3 = (k1+k2+k3+p).v   D8 = -k3^2
%   1 /  /3  \  \     D4 = (k2+k3+p).v
% =================   D5 = (k2+p).v
%  \   2  / 4  5    
%   \----/         
%      6         
%
% Limiting cases
% I3i(0,n2,n3,n4,n5,n6,n7,n8) = J(n2,n4,n3,n6,n8) I1(n5+n2+n3+n4+2(n6+n8-d),n7)
% I3i(n1,n2,0,n4,n5,n6,n7,n8) = I1(n4,n8) J2b(n5+n4+2n8-d,n1,n2,n7,n6)
% I3i(n1,n2,n3,0,n5,n6,n7,n8) = I1(n3,n8) J2c(n1,n5,n2+n3+2n8-d,n6,n7)
%
% Recurrence relations
% 1 - 1- + 2- - 5- = 0
% 1 - 1- + 3- - 4- = 0

procedure I3i(n1,n2,n3,n4,n5,n6,n7,n8);
if n6<=0 or n7<=0 or n8<=0 or max(n3,n4)<=0 or max(n1,n2,n3)<=0
then 0
else if n1=0 then I1c(n5+n2+n3+n4+2*(n6+n8),n7)*sub(B(1)=B(4),B(2)=B(3),J2(n2,n4,n3,n6,n8))
else if n3=0 then I1(n4,n8)*J2b(n5+n4+2*n8,n1,n2,n7,n6)
else if n4=0 then I1(n3,n8)*J2c(n1,n5,n2+n3+2*n8,n6,n7)
else if n1<0 then I3i(n1+1,n2,n3,n4,n5,n6,n7,n8)
    +I3i(n1+1,n2,n3-1,n4,n5,n6,n7,n8)-I3i(n1+1,n2,n3,n4-1,n5,n6,n7,n8)
else if n3<0 then I3i(n1-1,n2,n3+1,n4,n5,n6,n7,n8)
    +I3i(n1,n2,n3+1,n4-1,n5,n6,n7,n8)-I3i(n1,n2,n3+1,n4,n5,n6,n7,n8)
else if n4<0 then I3i(n1,n2,n3,n4+1,n5,n6,n7,n8)
    +I3i(n1,n2,n3-1,n4+1,n5,n6,n7,n8)-I3i(n1-1,n2,n3,n4+1,n5,n6,n7,n8)
else I3i(n1-1,n2,n3,n4,n5,n6,n7,n8)
    +I3i(n1,n2,n3,n4-1,n5,n6,n7,n8)-I3i(n1,n2,n3-1,n4,n5,n6,n7,n8)$

remember I3i;

% I3i with numerators N12^n12*N13^n13*N23^n23
procedure II3i(n1,n2,n3,n4,n5,n6,n7,n8,n12,n13,n23);
if n6<=0 or n7<=0 or n8<=0 or max(n3,n4)<=0 or max(n1,n2,n3)<=0
then 0
else if n12=0 and n13=0 and n23=0 then I3i(n1,n2,n3,n4,n5,n6,n7,n8)
else if n2<=0 and n3<=0 then K3b(n1,n4,n5,n6,n8,n7,-n2,0,-n3,0,n12,n23,n13)
else if n1<=0 and n3<=0 then K3c(n2,n4,n5,n6,n8,n7,-n1,0,-n3,n12,n23,n13)
else if n1<=0 and n2<=0 then K3d(n3,n5,n4,n7,n6,n8,-n1,0,0,-n2,n23,n12,n13)
else if n1<=0 and n4<=0 then K3d(n3,n5,n2,n7,n8,n6,0,-n1,0,-n4,n12,n23,n13)
else if n4<=0 and n5<=0 then K3d(n3,n1,n2,n6,n8,n7,0,-n5,-n4,0,n12,n13,n23)
else if n3<=0 and n5<=0 then K3e(n4,n1,n2,n6,n7,n8,0,-n3,-n5,n23,n13,n12)
else if n2<=0 and n4<=0 then K3f(n1,n5,n3,n6,n7,n8,-n2,0,-n4,n13,n23,n12)
else if n1<=0 and n5<=0 then K3g(n2,n4,n3,n6,n8,n7,-n5,-n1,0,n12,n23,n13)
else if n1<=0
then
    if max(n2,n3,n4)<=n5
    then II3i(n1,n2-1,n3,n4,n5+1,n6,n7,n8,n12,n13,n23)
        -II3i(n1,n2,n3-1,n4,n5+1,n6,n7,n8,n12,n13,n23)
        +II3i(n1,n2,n3,n4-1,n5+1,n6,n7,n8,n12,n13,n23)
    else if max(n2,n3,n5)<=n4
    then II3i(n1,n2,n3-1,n4+1,n5,n6,n7,n8,n12,n13,n23)
        -II3i(n1,n2-1,n3,n4+1,n5,n6,n7,n8,n12,n13,n23)
        +II3i(n1,n2,n3,n4+1,n5-1,n6,n7,n8,n12,n13,n23)
    else if max(n2,n4,n5)<=n3
    then II3i(n1,n2-1,n3+1,n4,n5,n6,n7,n8,n12,n13,n23)
        -II3i(n1,n2,n3+1,n4,n5-1,n6,n7,n8,n12,n13,n23)
        +II3i(n1,n2,n3+1,n4-1,n5,n6,n7,n8,n12,n13,n23)
    else II3i(n1,n2+1,n3-1,n4,n5,n6,n7,n8,n12,n13,n23)
        -II3i(n1,n2+1,n3,n4-1,n5,n6,n7,n8,n12,n13,n23)
        +II3i(n1,n2+1,n3,n4,n5-1,n6,n7,n8,n12,n13,n23)
else if n2<=0 or n5<=0 or (n3>0 and n4>0 and max(n3,n4)<=max(n2,n5))
then II3i(n1-1,n2,n3,n4,n5,n6,n7,n8,n12,n13,n23)
    -II3i(n1,n2,n3-1,n4,n5,n6,n7,n8,n12,n13,n23)
    +II3i(n1,n2,n3,n4-1,n5,n6,n7,n8,n12,n13,n23)
else II3i(n1-1,n2,n3,n4,n5,n6,n7,n8,n12,n13,n23)
    -II3i(n1,n2-1,n3,n4,n5,n6,n7,n8,n12,n13,n23)
    +II3i(n1,n2,n3,n4,n5-1,n6,n7,n8,n12,n13,n23)$

remember II3i;

% Ij
%
%       6   7   8         D1 = (k1+p).v         D6 = -k1^2
%      /-\ /-\ /-\        D2 = (k1+k2+p).v      D7 = -k2^2
%     /   /   /   \       D3 = (k1+k2+k3+p).v   D8 = -k3^2
%    /   / \ / \   \      D4 = (k2+k3+p).v
%   /   /   /   \   \     D5 = (k3+p).v
%  /   /   / \   \   \
% =====================
%   1   2   3   4   5
%
% Limiting cases
% I3j(n1,n2,n3,n4,0,n6,n7,n8) = I3i(n1,n2,n3,n4,0,n6,n7,n8)
% I3j(0,n2,n3,n4,n5,n6,n7,n8) = I3i(n5,n4,n3,n2,0,n8,n7,n6)
% I3j(n1,0,n3,n4,n5,n6,n7,n8) = I3i(n1,0,n3,n4,n5,n6,n8,n7)
% I3j(n1,n2,n3,0,n5,n6,n7,n8) = I3i(n5,0,n3,n2,n1,n8,n6,n7)
% I3j(n1,n2,0,n4,n5,n6,n7,n8) = I3h(n1,n2,0,n4,n5,n6,n8,n7)
%
% Recurrence relations
% 1 - 2- + 3- - 5- = 0
% 1 - 1- + 3- - 4- = 0

procedure I3j(n1,n2,n3,n4,n5,n6,n7,n8);
if n6<=0 or n7<=0 or n8<=0 or max(n1,n2,n3)<=0 or max(n2,n3,n4)<=0 or max(n3,n4,n5)<=0
then 0
else if n1=0 then I3i(n5,n4,n3,n2,0,n8,n7,n6)
else if n5=0 then I3i(n1,n2,n3,n4,0,n6,n7,n8)
else if n2=0 then I3i(n1,0,n3,n4,n5,n6,n8,n7)
else if n4=0 then I3i(n5,0,n3,n2,n1,n8,n6,n7)
else if n3=0 then I3h(n1,n2,0,n4,n5,n6,n8,n7)
else if n1<0 then I3j(n1+1,n2,n3,n4,n5,n6,n7,n8)
    +I3j(n1+1,n2,n3-1,n4,n5,n6,n7,n8)-I3j(n1+1,n2,n3,n4-1,n5,n6,n7,n8)
else if n5<0 then I3j(n1,n2,n3,n4,n5+1,n6,n7,n8)
    +I3j(n1,n2,n3-1,n4,n5+1,n6,n7,n8)-I3j(n1,n2-1,n3,n4,n5+1,n6,n7,n8)
else if n2<0 then I3j(n1,n2+1,n3,n4,n5,n6,n7,n8)
    +I3j(n1,n2+1,n3-1,n4,n5,n6,n7,n8)-I3j(n1,n2+1,n3,n4,n5-1,n6,n7,n8)
else if n4<0 then I3j(n1,n2,n3,n4+1,n5,n6,n7,n8)
    +I3j(n1,n2,n3-1,n4+1,n5,n6,n7,n8)-I3j(n1-1,n2,n3,n4+1,n5,n6,n7,n8)
else if n3<0 then
    if max(n2,n5)<max(n1,n4)
    then I3j(n1,n2-1,n3+1,n4,n5,n6,n7,n8)
        +I3j(n1,n2,n3+1,n4,n5-1,n6,n7,n8)-I3j(n1,n2,n3+1,n4,n5,n6,n7,n8)
    else I3j(n1-1,n2,n3+1,n4,n5,n6,n7,n8)
        +I3j(n1,n2,n3+1,n4-1,n5,n6,n7,n8)-I3j(n1,n2,n3+1,n4,n5,n6,n7,n8)
else if max(n2,n5)<max(n1,n4) then I3j(n1,n2-1,n3,n4,n5,n6,n7,n8)
    +I3j(n1,n2,n3,n4,n5-1,n6,n7,n8)-I3j(n1,n2,n3-1,n4,n5,n6,n7,n8)
else I3j(n1-1,n2,n3,n4,n5,n6,n7,n8)
    +I3j(n1,n2,n3,n4-1,n5,n6,n7,n8)-I3j(n1,n2,n3-1,n4,n5,n6,n7,n8)$

remember I3j;

% I3j with numerators N12^n12*N13^n13*N23^n23
procedure II3j(n1,n2,n3,n4,n5,n6,n7,n8,n12,n13,n23);
if n6<=0 or n7<=0 or n8<=0 or max(n1,n2,n3)<=0 or max(n2,n3,n4)<=0 or max(n3,n4,n5)<=0
then 0
else if n12=0 and n13=0 and n23=0 then I3j(n1,n2,n3,n4,n5,n6,n7,n8)
else if n2<=0 and n3<=0 then K3b(n1,n4,n5,n6,n7,n8,0,0,-n3,-n2,n13,n23,n12)
else if n4<=0 and n3<=0 then K3b(n5,n2,n1,n8,n7,n6,0,0,-n3,-n4,n13,n12,n23)
else if n1<=0 and n2<=0 then K3d(n3,n5,n4,n8,n6,n7,-n1,0,-n2,0,n23,n13,n12)
else if n5<=0 and n4<=0 then K3d(n3,n1,n2,n6,n8,n7,-n5,0,-n4,0,n12,n13,n23)
else if n1<=0 and n3<=0 then K3e(n2,n5,n4,n8,n7,n6,-n1,-n3,0,n12,n13,n23)
else if n5<=0 and n3<=0 then K3e(n4,n1,n2,n6,n7,n8,-n5,-n3,0,n23,n13,n12)
else if n2<=0 and n4<=0 then K3f(n1,n5,n3,n6,n8,n7,0,-n2,-n4,n12,n23,n13)
else if n1<=0 and n5<=0 then K3g(n2,n4,n3,n6,n8,n7,0,-n1,-n5,n12,n23,n13)
else if n3<=0
then
    if max(n1,n2,n4)<=n5
    then II3j(n1-1,n2,n3,n4,n5+1,n6,n7,n8,n12,n13,n23)
        -II3j(n1,n2-1,n3,n4,n5+1,n6,n7,n8,n12,n13,n23)
        +II3j(n1,n2,n3,n4-1,n5+1,n6,n7,n8,n12,n13,n23)
    else if max(n5,n4,n2)<=n1
    then II3j(n1+1,n2-1,n3,n4,n5,n6,n7,n8,n12,n13,n23)
        -II3j(n1+1,n2,n3,n4-1,n5,n6,n7,n8,n12,n13,n23)
        +II3j(n1+1,n2,n3,n4,n5-1,n6,n7,n8,n12,n13,n23)
    else if max(n1,n2,n5)<=n4
    then II3j(n1,n2-1,n3,n4+1,n5,n6,n7,n8,n12,n13,n23)
        -II3j(n1-1,n2,n3,n4+1,n5,n6,n7,n8,n12,n13,n23)
        +II3j(n1,n2,n3,n4+1,n5-1,n6,n7,n8,n12,n13,n23)
    else II3j(n1-1,n2+1,n3,n4,n5,n6,n7,n8,n12,n13,n23)
        -II3j(n1,n2+1,n3,n4,n5-1,n6,n7,n8,n12,n13,n23)
        +II3j(n1,n2+1,n3,n4-1,n5,n6,n7,n8,n12,n13,n23)
else if n1<=0 or n4<=0 or (n2>0 and n5>0 and max(n2,n5)<=max(n1,n4))
then II3j(n1,n2-1,n3,n4,n5,n6,n7,n8,n12,n13,n23)
    -II3j(n1,n2,n3-1,n4,n5,n6,n7,n8,n12,n13,n23)
    +II3j(n1,n2,n3,n4,n5-1,n6,n7,n8,n12,n13,n23)
else II3j(n1-1,n2,n3,n4,n5,n6,n7,n8,n12,n13,n23)
    -II3j(n1,n2,n3-1,n4,n5,n6,n7,n8,n12,n13,n23)
    +II3j(n1,n2,n3,n4-1,n5,n6,n7,n8,n12,n13,n23)$

remember II3j;

% Ic   n6=n7=0   with numerators
%
%     4      8      5       N9  = (k1+k3+p).v = D1 + D3 - 1
%    ---    ---    ---      N10 = (k2+k3+p).v = D2 + D3 - 1
%   /k1 \  /k3 \  /k2 \     N45 = 2 k1.k2     = N
%  /     \/     \/     \    N48 = 2 k1.k3     = - D4 + D6 - D8
% =======================   N58 = 2 k2.k3     = - D5 + D7 - D8
%     1      3      2

procedure K3a(n1,n2,n3,n4,n5,n8,n9,n10,n45,n48,n58);
begin scalar p;
    p:=(!!1+!!3-1)^n9*(!!2+!!3-1)^n10*!!0^n45*(!!6-!!4-!!8)^n48*(!!7-!!5-!!8)^n58
        *(!!0*!!1*!!2*!!3*!!4*!!5*!!6*!!7*!!8)^2;
    for all m0,m1,m2,m3,m4,m5,m6,m7,m8 match
        !!0^m0*!!1^m1*!!2^m2*!!3^m3*!!4^m4*!!5^m5*!!6^m6*!!7^m7*!!8^m8=
        II3c(n1+2-m1,n2+2-m2,n3+2-m3,n4+2-m4,n5+2-m5,2-m6,2-m7,n8+2-m8,m0-2);
    p:=p;
    for all m0,m1,m2,m3,m4,m5,m6,m7,m8 clear
        !!0^m0*!!1^m1*!!2^m2*!!3^m3*!!4^m4*!!5^m5*!!6^m6*!!7^m7*!!8^m8;
    return p
end$

% Ic   n5=n6=0   with numerators
%
%     4         8           N9  = (k1+k3+p).v    = D1 + D3 - 1
%    ---    ----------      N10 = (k2-k3+p).v    = D2 - D3 + 1
%   /k1 \  /    k3    \     N11 = (k1+k2+p).v    = D1 + D2 - 1
%  /     \/            \    N12 = (k1+k2-k3+p).v = D1 + D2 - D3
% =======================   N48 = 2 k1.k3        = - D4 + D6 - D8
%     1   \   2   /  3      N78 = 2 k3.(k2-k3)   = - D5 + D7 + D8
%          \k2-k3/          N47 = 2 k1.(k2-k3)   = D4 - D6 + D8 + N
%           ----
%            7

procedure K3b(n1,n2,n3,n4,n7,n8,n9,n10,n11,n12,n48,n78,n47);
begin scalar p;
    p:=(!!1+!!3-1)^n9*(!!2-!!3+1)^n10*(!!1+!!2-1)^n11*(!!1+!!2-!!3)^n12
        *(!!6-!!4-!!8)^n48*(!!7-!!5+!!8)^n78*(!!4-!!6+!!8+!!0)^n47
        *(!!0*!!1*!!2*!!3*!!4*!!5*!!6*!!7*!!8)^2;
    for all m0,m1,m2,m3,m4,m5,m6,m7,m8 match
        !!0^m0*!!1^m1*!!2^m2*!!3^m3*!!4^m4*!!5^m5*!!6^m6*!!7^m7*!!8^m8=
        II3c(n1+2-m1,n2+2-m2,n3+2-m3,n4+2-m4,2-m5,2-m6,n7+2-m7,n8+2-m8,m0-2);
    p:=p;
    for all m0,m1,m2,m3,m4,m5,m6,m7,m8 clear
        !!0^m0*!!1^m1*!!2^m2*!!3^m3*!!4^m4*!!5^m5*!!6^m6*!!7^m7*!!8^m8;
    return p
end$

% Ic   n4=n5=0   with numerators
%
%            8              N9  = (k1-k3+p).v       = D1 - D3 + 1
%    -----------------      N10 = (k2-k3+p).v       = D2 - D3 + 1
%   /        k3       \     N11 = (k1+k2-k3+p).v    = D1 + D2 - D3
%  /   1     3     2   \    N68 = 2 k3.(k1-k3)      = - D4 + D6 + D8
% =======================   N78 = 2 k3.(k2-k3)      = - D5 + D7 + D8
%  \       /   \       /    N67 = 2 (k1-k3).(k2-k3) = D4 + D5 - D6 - D7 + N
%   \k1-k3/     \k2-k3/
%    -----       -----
%      6           7

procedure K3c(n1,n2,n3,n6,n7,n8,n9,n10,n11,n68,n78,n67);
begin scalar p;
    p:=(!!1-!!3+1)^n9*(!!2-!!3+1)^n10*(!!1+!!2-!!3)^n11
        *(!!6-!!4+!!8)^n68*(!!7-!!5+!!8)^n78*(!!4+!!5-!!6-!!7+!!0)^n67
        *(!!0*!!1*!!2*!!3*!!4*!!5*!!6*!!7*!!8)^2;
    for all m0,m1,m2,m3,m4,m5,m6,m7,m8 match
        !!0^m0*!!1^m1*!!2^m2*!!3^m3*!!4^m4*!!5^m5*!!6^m6*!!7^m7*!!8^m8=
        II3c(n1+2-m1,n2+2-m2,n3+2-m3,2-m4,2-m5,n6+2-m6,n7+2-m7,n8+2-m8,m0-2);
    p:=p;
    for all m0,m1,m2,m3,m4,m5,m6,m7,m8 clear
        !!0^m0*!!1^m1*!!2^m2*!!3^m3*!!4^m4*!!5^m5*!!6^m6*!!7^m7*!!8^m8;
    return p
end$

% Ic   n4=n8=0   with numerators
%
%          5                  N9  = (k1-k3+p).v       = D1 - D3 + 1
%     -----------             N10 = (k3-k2+p).v       = - D2 + D3 + 1
%    /  6  k2    \            N11 = (k1-k2+p).v       = D1 - D2 + 1
%   / -----       \           N12 = (k1+k2-k3+p).v    = D1 + D2 - D3
%  | /k1-k3\       \          N57 = 2 k2.(k3-k2)      = D5 + D7 - D8
%  |/   1   \  3  2 \         N56 = 2 k2.(k1-k3)      = D5 - D7 + D8 + N
% =========================   N67 = 2 (k1-k3).(k3-k2) = - D4 - D5 + D6 + D7 - N
%  \           /
%   \  k3-k2  /
%    ---------
%        7

procedure K3d(n1,n2,n3,n5,n6,n7,n9,n10,n11,n12,n57,n56,n67);
begin scalar p;
    p:=(!!1-!!3+1)^n9*(!!3-!!2+1)^n10*(!!1-!!2+1)^n11*(!!1+!!2-!!3)^n12
        *(!!5+!!7-!!8)^n57*(!!5-!!7+!!8+!!0)^n56*(!!6+!!7-!!4-!!5-!!0)^n67
        *(!!0*!!1*!!2*!!3*!!4*!!5*!!6*!!7*!!8)^2;
    for all m0,m1,m2,m3,m4,m5,m6,m7,m8 match
        !!0^m0*!!1^m1*!!2^m2*!!3^m3*!!4^m4*!!5^m5*!!6^m6*!!7^m7*!!8^m8=
        II3c(n1+2-m1,n2+2-m2,n3+2-m3,2-m4,n5+2-m5,n6+2-m6,n7+2-m7,2-m8,m0-2);
    p:=p;
    for all m0,m1,m2,m3,m4,m5,m6,m7,m8 clear
        !!0^m0*!!1^m1*!!2^m2*!!3^m3*!!4^m4*!!5^m5*!!6^m6*!!7^m7*!!8^m8;
    return p
end$

% Id   n4=n7=0   with numerators
%
%       6              N9  = (k3+p).v     = D1 + D2 - D3
%    -------           N10 = (k1+k2+p).v  = D1 + D2 - 1
%   / k1-k3 \          N11 = (k1-k3+p).v  = - D2 + D3 + 1
%  /  1    3 \  2      N68 = 2 k3.(k1-k3) = - D4 + D6 + D8
% ==================   N58 = 2 k2.k3      = - D5 + D7 - D8
%  \     /\       /    N56 = 2 k2.(k1-k3) = D5 - D7 + D8 + N
%   \ k3/  \  k2 /
%    ---    -----
%     8       5

procedure K3e(n1,n2,n3,n5,n6,n8,n9,n10,n11,n68,n58,n56);
begin scalar p;
    p:=(!!1+!!2-!!3)^n9*(!!1+!!2-1)^n10*(!!3-!!2+1)^n11
        *(!!6-!!4+!!8)^n68*(!!7-!!5-!!8)^n58*(!!5-!!7+!!8+!!0)^n56
        *(!!0*!!1*!!2*!!3*!!4*!!5*!!6*!!7*!!8)^2;
    for all m0,m1,m2,m3,m4,m5,m6,m7,m8 match
        !!0^m0*!!1^m1*!!2^m2*!!3^m3*!!4^m4*!!5^m5*!!6^m6*!!7^m7*!!8^m8=
        II3d(n1+2-m1,n2+2-m2,n3+2-m3,2-m4,n5+2-m5,n6+2-m6,2-m7,n8+2-m8,m0-2);
    p:=p;
    for all m0,m1,m2,m3,m4,m5,m6,m7,m8 clear
        !!0^m0*!!1^m1*!!2^m2*!!3^m3*!!4^m4*!!5^m5*!!6^m6*!!7^m7*!!8^m8;
    return p
end$

% Id   n6=n7=0   with numerators
%
%        4            N9  = (k1+k2+p).v = D1 + D2 - 1
%      -----          N10 = (k1-k3+p).v = - D2 + D3 + 1
%     / k1 8\         N11 = (k2-k3+p).v = - D1 + D3 + 1
%    /   --- \        N48 = - 2 k1.k3   = D4 - D6 + D8
%   /   /-k3\ |       N58 = - 2 k2.k3   = D5 - D7 + D8
%  /   /     \|       N45 = 2 k1.k2     = N
% =================
%   1  \  3    2 /
%       \   k2  /
%        -------
%           5

procedure K3f(n1,n2,n3,n4,n5,n8,n9,n10,n11,n48,n58,n45);
begin scalar p;
    p:=(!!1+!!2-1)^n9*(!!3-!!2+1)^n10*(!!3-!!1+1)^n11
        *(!!4-!!6+!!8)^n48*(!!5-!!7+!!8)^n58*!!0^n45
        *(!!0*!!1*!!2*!!3*!!4*!!5*!!6*!!7*!!8)^2;
    for all m0,m1,m2,m3,m4,m5,m6,m7,m8 match
        !!0^m0*!!1^m1*!!2^m2*!!3^m3*!!4^m4*!!5^m5*!!6^m6*!!7^m7*!!8^m8=
        II3d(n1+2-m1,n2+2-m2,n3+2-m3,n4+2-m4,n5+2-m5,2-m6,2-m7,n8+2-m8,m0-2);
    p:=p;
    for all m0,m1,m2,m3,m4,m5,m6,m7,m8 clear
        !!0^m0*!!1^m1*!!2^m2*!!3^m3*!!4^m4*!!5^m5*!!6^m6*!!7^m7*!!8^m8;
    return p
end$

% Id   n4=n5=0   with numerators
%
%         8          N9  = (k3+p).v          = D1 + D2 - D3
%     --------       N10 = (k1-k3+p).v       = - D2 + D3 + 1
%    /  6 k3  \      N11 = (k2-k3+p).v       = - D1 + D3 + 1
%   / -----    \     N68 = 2 k3.(k1-k3)      = - D4 + D6 + D8
%  | /k1-k3\    |    N78 = 2 k3.(k2-k3)      = - D5 + D7 + D8
%  |/       \   |    N67 = 2 (k1-k3).(k2-k3) = D4 + D5 - D6 - D7 + N
% ================
%    1 \  3   2/
%       \k2-k3/
%        -----
%          7

procedure K3g(n1,n2,n3,n6,n7,n8,n9,n10,n11,n68,n78,n67);
begin scalar p;
    p:=(!!1+!!2-!!3)^n9*(!!3-!!2+1)^n10*(!!3-!!1+1)^n11
        *(!!6-!!4+!!8)^n68*(!!7-!!5+!!8)^n78*(!!4+!!5-!!6-!!7+!!0)^n67
        *(!!0*!!1*!!2*!!3*!!4*!!5*!!6*!!7*!!8)^2;
    for all m0,m1,m2,m3,m4,m5,m6,m7,m8 match
        !!0^m0*!!1^m1*!!2^m2*!!3^m3*!!4^m4*!!5^m5*!!6^m6*!!7^m7*!!8^m8=
        II3d(n1+2-m1,n2+2-m2,n3+2-m3,2-m4,2-m5,n6+2-m6,n7+2-m7,n8+2-m8,m0-2);
    p:=p;
    for all m0,m1,m2,m3,m4,m5,m6,m7,m8 clear
        !!0^m0*!!1^m1*!!2^m2*!!3^m3*!!4^m4*!!5^m5*!!6^m6*!!7^m7*!!8^m8;
    return p
end$

symbolic <<!*lower := !*raise := nil>>;

end;

% K3b, K3c, K3d via II3b

% (1- + 2- - 1)^n9 (3- - 2- + 1)^n10 (1- + 3- - 1)^n11 (1- - 2- + 3-)^n12
%     (8- - 4- - 5-)^n48 (5- + 7- - 0+)^n78 (5- + 6- - 8- - 0+)^n47
%     Ib(n1,n3,n2,n4,n8,0,n7,0)
procedure K3bb(n1,n2,n3,n4,n7,n8,n9,n10,n11,n12,n48,n78,n47);
begin scalar p;
    p:=(!!1+!!2-1)^n9*(!!3-!!2+1)^n10*(!!1+!!3-1)^n11*(!!1-!!2+!!3)^n12
        *(!!8-!!4-!!5)^n48*(!!5+!!7-!!0)^n78*(!!5+!!6-!!8-!!0)^n47
        *(!!0*!!1*!!2*!!3*!!4*!!5*!!6*!!7*!!8)^2;
    for all m0,m1,m2,m3,m4,m5,m6,m7,m8 match
        !!0^m0*!!1^m1*!!2^m2*!!3^m3*!!4^m4*!!5^m5*!!6^m6*!!7^m7*!!8^m8=
        II3b(n1+2-m1,n3+2-m2,n2+2-m3,n4+2-m4,n8+2-m5,2-m6,n7+2-m7,2-m8,m0-2);
    p:=p;
    for all m0,m1,m2,m3,m4,m5,m6,m7,m8 clear
        !!0^m0*!!1^m1*!!2^m2*!!3^m3*!!4^m4*!!5^m5*!!6^m6*!!7^m7*!!8^m8;
    return p
end$

% (1- - 2- + 1)^n9 (3- - 2- + 1)^n10 (1- - 2- + 3-)^n11
%     (5- - 4- + 8-)^n68 (5- + 7- - 0+)^n78 (6- - 7- - 8-)^n67
%     Ib(n1,n3,n2,0,n8,0,n7,n6)
procedure K3bc(n1,n2,n3,n6,n7,n8,n9,n10,n11,n68,n78,n67);
begin scalar p;
    p:=(!!1-!!2+1)^n9*(!!3-!!2+1)^n10*(!!1-!!2+!!3)^n11
        *(!!5-!!4+!!8)^n68*(!!5+!!7-!!0)^n78*(!!6-!!7-!!8)^n67
        *(!!0*!!1*!!2*!!3*!!4*!!5*!!6*!!7*!!8)^2;
    for all m0,m1,m2,m3,m4,m5,m6,m7,m8 match
        !!0^m0*!!1^m1*!!2^m2*!!3^m3*!!4^m4*!!5^m5*!!6^m6*!!7^m7*!!8^m8=
        II3b(n1+2-m1,n3+2-m2,n2+2-m3,2-m4,n8+2-m5,2-m6,n7+2-m7,n6+2-m8,m0-2);
    p:=p;
    for all m0,m1,m2,m3,m4,m5,m6,m7,m8 clear
        !!0^m0*!!1^m1*!!2^m2*!!3^m3*!!4^m4*!!5^m5*!!6^m6*!!7^m7*!!8^m8;
    return p
end$

% (1- - 3- + 1)^n9 (3- - 2- + 1)^n10 (1- - 2- + 1)^n11 (1- + 2- - 3-)^n12
%     (5- + 7- - 0+)^n57 (8- - 4- - 7- + 0+)^n56 (6- + 7- - 8-)^n67
%     Ib(n1,n2,n3,0,n5,n6,n7,0)
procedure K3bd(n1,n2,n3,n5,n6,n7,n9,n10,n11,n12,n57,n56,n67);
begin scalar p;
    p:=(!!1-!!3+1)^n9*(!!3-!!2+1)^n10*(!!1-!!2+1)^n11*(!!1+!!2-!!3)^n12
        *(!!5+!!7-!!0)^n57*(!!8-!!4-!!7+!!0)^n56*(!!6+!!7-!!8)^n67
        *(!!0*!!1*!!2*!!3*!!4*!!5*!!6*!!7*!!8)^2;
    for all m0,m1,m2,m3,m4,m5,m6,m7,m8 match
        !!0^m0*!!1^m1*!!2^m2*!!3^m3*!!4^m4*!!5^m5*!!6^m6*!!7^m7*!!8^m8=
        II3b(n1+2-m1,n2+2-m2,n3+2-m3,2-m4,n5+2-m5,n6+2-m6,n7+2-m7,2-m8,m0-2);
    p:=p;
    for all m0,m1,m2,m3,m4,m5,m6,m7,m8 clear
        !!0^m0*!!1^m1*!!2^m2*!!3^m3*!!4^m4*!!5^m5*!!6^m6*!!7^m7*!!8^m8;
    return p
end$

end;
