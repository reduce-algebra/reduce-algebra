% Classification of IIIrd order homogeneous HO
% through the Monge metrics inside Segre's classification
% which fulfills Gennady Potemin's nonlinear condition.

% This file contains the splittings of the 5 nontrivial metrics
% that we found in 3-c case, according with the formula:
% g_{ij} = phi^{ab} psi_{ia}psi_{jb}
% In matrix notation: G = AHA^t
% NOTE: variables are {b1,b2,b3}.

% This is an official version, checked 2015.01.30.
% Metrics are the same as the paper FPV in JGP (2014).

% Type 1: a metric of Segre type [111111], in the subclass [111(111)]
% with the additional condition that equal eigenvalues must be
% the average of other eigenvalues.
g_1:=
mat(
(b2**2 + mu, - (b1*b2 + b3),2*b2),
( - (b1*b2 + b3),b1**2 + mu*b3**2, - (mu*b2*b3 + b1)),
(2*b2, - (mu*b2*b3 + b1),mu*b2**2 + 1)
)$

phi_1:=
mat(
(1,0,0),
(0,(mu - 1)/2,0),
(0,0,(mu + 1)/2)
)$

psi_1:=
mat((b2,-1,-1),( - b1, - b3,b3),(1,b2, - b2))$

% Type 2: a metric of Segre type [11112], in the subclass [1(111)2]
% with the additional condition that equal eigenvalues must be
% the average (with multiplicity!) of other eigenvalues.

g_2:=
mat((b2**2 + 1, - (b1*b2 + b3),2*b2),( - (b1*b2 + b3),b1**2,
- b1),(2*b2, - b1,1))$

psi_2:=
mat((1,0,b2),(0,b3, - b1),(0, - b2,1))$

phi_2:=
mat((1,-1,0),(-1,0,0),(0,0,1))$

% Type 3: a metric of Segre type [11112], in the subclass [11(112)]
% with the additional condition that equal eigenvalues must be
% the average of other eigenvalues.

g_3:=
mat((b2**2 + 1, - b1*b2, 0),( - b1*b2,b1**2,0),(0,0,1))$

psi_3:=mat((1,0,b2),(0,0, - b1),(0,1,0))$

phi_3:=mat((1,0,0),(0,1,0),(0,0,1))$

% Type 4: a metric of Segre type [114], in the subclass [(114)].

g_4:=
mat((-2*b2,b1,0),(b1,0,0),(0,0,1)
)$

psi_4:=
  mat((b2,0,-1),( - b1,0,0),(0,1,0))$

phi_4:=
mat(
(0,0,1),
(0,1,0),
(1,0,0)
)$

% Type 5: a metric of Segre type [123], in the subclass [(123)].
% The metric is in the FGMN form:

g_5:=
mat(( - 2*b2,b1,1),(b1,1,0),(1,0,0)
)$

psi_5:=
mat(
(b2,0,-1),
(-b1,1,0),
(-1,0,0)
)$

phi_5:=
mat((0,0,1),(0,1,0),(1,0,0))$

% Type 6: the constant metric, in [222]:

g_6:=
mat((1,0,0),(0,1,0),(0,0,1)
)$

psi_6:=
mat((1,0,0),(0,1,0),(0,0,1)
)$

phi_6:=
mat((1,0,0),(0,1,0),(0,0,1)
)$

;end;


Local Variables:
mode:reduce
End:
