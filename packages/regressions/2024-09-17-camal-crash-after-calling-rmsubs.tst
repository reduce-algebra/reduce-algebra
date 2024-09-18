
% Test for a bug in camal package: run the first lines from the camal test file
%  with "lisp rmsubs();" thrown in. This triggers a lisp error: car/cdr of an atom.

load_package camal;

n := 4;

on rational, rat;
off allfac;

array p(n/2+2);

harmonic u,v,w,x,y,z;

weight e=1, b=1, d=1, a=1;

%% Step1: Solve Kepler equation
bige := fourier 0;
for k:=1:n do <<
  wtlevel k;
  bige:=fourier e * hsub(fourier(sin u), u, u, bige, k);
>>;
write "Kepler Eqn solution:", bige$

%% Ensure we do not calculate things of too high an order
wtlevel n;

%% Step 2: Calculate r/a in terms of e and l
dd:=-e*e; hh:=3/2; j:=1; cc := 1;
for i:=1:n/2 do <<
  j:=i*j; hh:=hh-1; cc:=cc+hh*(dd^i)/j
>>;

bb:=hsub(fourier(1-e*cos u), u, u, bige, n);

lisp rmsubs();

aa:=fourier 1+hdiff(bige,u); 

end;
