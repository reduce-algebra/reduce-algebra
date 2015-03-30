COMMENT
        test file for the PHYSOP package;
% load_package physop;  % Load a compiled version of the physop package.
% showtime;
linelength(72)$
% Example 1: Quantum Mechanics of a Dirac particle in an external
%                      electromagnetic field
vecop p,a,k;
scalop m;
noncom p,a;
physindex j,l;
oporder m,k,a,p;

% we have to set off allfac here since otherwise there appear
% spurious negative powers in the printed output
 off allfac;
for all j,l let comm(p(j),a(l))=k(j)*a(l);
h:= commute(p**2/(2*m),e/(4*m**2)*(p dot a));
% showtime;
%assign the corresponding value to the adjoint of H
h!+ := adj h;
% showtime;
% note the ordering of operators in the result!
% enhance the readability of the output
 on allfac;
on contract;
h;
% showtime;
% Example 2: Virasoro Algebra from Conformal Field Theory


operator  del;  % this is just a definition of a delta function
for all n such that numberp n let del(n) =
     if n=0 then 1
     else 0;

scalop l;
noncom l,l;
state bra,ket;
% commutation relation of the operator l;
for all n,m let comm(l(n),l(m)) =
      (m-n)*l(n+m)+c/12*(m**3-m)*del(n+m)*unit; %modified 1.1

for all n let l!+(n) = l(-n);


% relation for the states
for all h let bra!+(h) = ket(h);
for all p,q let bra(q) | ket(p) = del(p-q);

for all r,h such that r < 0 or (r <2 and h=0) let
             l(r) | ket(h) = 0;

for all r,h such that r > 0 or (r  > -2 and h = 0) let
             bra(h) | l(r) = 0;

% define a procedure to calculate V.E.V.
procedure vak(x);
bra(0) | x | ket(0);

% and now some calculations;
ma:= adj(l(3)*l(5))*l(3)*l(5);  %modified 1.1
% showtime;

% here is the VEV of m
vak(ma);
% showtime;
% and now calculate another matrix element

matel := bra(1) | ma  | ket(1);  %modified 1.1
% showtime;
% this evaluation is incomplete so supply the missing relation
for all h let l(0) | ket(h) = h*ket(h);
% and reevaluate matel
matel := matel;
% showtime;


% Example 4: some manipulations with gamma matrices to demonstrate
%            the use of commutators and anticommutators


off allfac;
vecop gammamat,q;
tensop sigma(2);
antisymmetric sigma;
noncom gammamat,gammamat;
noncom sigma,gammamat;
physindex mu,nu;
operator delta;
for all mu,nu let anticomm(gammamat(mu),gammamat(nu))=2*delta(mu,nu)*unit,
                  comm(gammamat(mu),gammamat(nu))=2*i*sigma(mu,nu);

oporder p,q,gammamat,sigma;
off allfac;
on anticom;
(gammamat dot p)*(gammamat dot q);
% showtime;

off anticom;
(gammamat dot p)*(gammamat dot q);
% showtime;

commute((gammamat dot p),(gammamat dot q));
% showtime;
anticommute((gammamat dot p),(gammamat dot q));
on anticom;
anticommute((gammamat dot p),(gammamat dot q));
% showtime;

end;
