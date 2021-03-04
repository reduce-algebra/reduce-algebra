out "sftheta.rlg";

load_package specfn;

% test of sftheta.red
% Author: Alan Barnes   (Alan.Barnes45678@gmail.com) February 2021

% theta functions
% periodicity, quasi-periodicity and zeroes
elliptictheta1(z+6*pi, tau);
elliptictheta1(z+7*pi, tau);
elliptictheta2(z+7*pi/2, tau);
elliptictheta2(z+9*pi/2, tau);
elliptictheta4(z+9*pi, tau);
elliptictheta4(z+9*pi/2, tau);

elliptictheta1(6*pi+7*pi*tau, tau);
s1:=elliptictheta1(z+5*pi/2+3*pi*tau, tau);
elliptictheta2(6*pi+7*pi*tau, tau);
elliptictheta2(7/2*pi+7*pi*tau, tau);

elliptictheta4(6*pi+7/2*pi*tau, tau);
s2:=elliptictheta4(z+6*pi+7/2*pi*tau, tau);
elliptictheta3(z+6*pi+7/2*pi*tau, tau);
elliptictheta3(7*pi/2+3/2*pi*tau, tau);

elliptictheta1(-z,tau);
elliptictheta3(-z,tau);
elliptictheta3(z,tau+1);
elliptictheta1(z,tau-1);
elliptictheta2(z,-1/tau);

% numerical evaluation and consistency checks
on rounded, complex;
tau := -i*log(0.1)/pi;
elliptictheta1(pi/6,tau);
elliptictheta2(pi/4,tau);
elliptictheta3(pi/3,tau);
elliptictheta4(pi/2,tau);

a := elliptictheta3(0,tau);
b := elliptictheta2(0,tau);
c := elliptictheta4(0,tau);
a^4-b^4-c^4;

tau := -i*log(0.8)/pi;
elliptictheta1(pi/6,tau);
elliptictheta2(pi/4,tau);
elliptictheta3(pi/3,tau);
elliptictheta4(pi/2,tau);

a := elliptictheta3(0,tau);
b := elliptictheta2(0,tau);
c := elliptictheta4(0,tau);
a^4-b^4-c^4;

z := 0.5;
w:=z+5*pi/2+3*pi*tau;
elliptictheta1(w,tau);
s1;

w:= z+6*pi+7/2*pi*tau;
elliptictheta4(w,tau);
s2;

w:=pi/6;

e1:=elliptictheta1(w,tau);
e2:=elliptictheta2(w,tau);
e3:=elliptictheta3(w,tau);
e4:=elliptictheta4(w,tau);

e1^4+e3^4-e2^4-e4^4;

a:=atan(4/3)/pi -i/pi*log 0.75;
elliptictheta1(i*pi/6,a);
elliptictheta1(i*pi/6,a-1);
elliptictheta2((2+i)*pi/4,a);
elliptictheta2((2+i)*pi/4,a-1);
elliptictheta3(i*pi/3,a);
elliptictheta3(i*pi/3,a-1);
elliptictheta4(i*pi/3,a);

d := elliptictheta3(0,a);
b := elliptictheta2(0,a);
c := elliptictheta4(0,a);
d^4-b^4-c^4;

% theta derivatives

theta1d(z,1,tau);
theta2d(z,2,tau);
theta3d(z,3,tau);
theta4d(z,2,tau);

td1:= theta1d(0,1,tau);
td3:= theta1d(0,3,tau);
t2 := elliptictheta2(0,tau);
t3 := elliptictheta3(0,tau);
t4 := elliptictheta4(0,tau);

td1-t2*t3*t4;

t2dd := theta2d(0,2,tau);
t3dd := theta3d(0,2,tau);
t4dd := theta4d(0,2,tau);


td3/td1-(t2dd/t2+t3dd/t3+t4dd/t4);

shut "sftheta.rlg";

;end;

