% Plots of Theta Functions
% =======================================
% cf. <https://dlmf.nist.gov/20.3>   Real Argument and Nome

% Author:  Alan Barnes, March 2025
% efthetaplot.tst 

% Rough timings are included for each plot.

on rounded;
on time;

% cf. DLMF  Figure 20.3.1
plot({elliptictheta1(pi*x,0.15),elliptictheta2(pi*x,0.15),elliptictheta3(pi*x,0.15),elliptictheta4(pi*x,0.15)},
   x = (0 .. 2), y = (-2 .. 2),
   title = "theta1(pi*x,q), theta2(pi*x,q), theta3(pi*x,q), theta4(pi*x,q) for q=0.15");

% Time: 624 ms

pause;

% cf. Figure 20.3.2: theta1(pi*x,q) for 0≤x≤2, q = 0.05, 0.5, 0.7, 0.9.
plot(foreach q in {0.05, 0.5, 0.7, 0.9} collect elliptictheta1(pi*x,q),
   x = (0 .. 2), y = (-6 .. 6),
   title = "theta1(pi*x,q) for q = 0.05, 0.5, 0.7, 0.9");
   
% Time: 795 ms

pause;

% cf. Figure 20.3.3: theta2(pi*x,q) for 0≤x≤2, q = 0.05, 0.5, 0.7, 0.9.
plot(foreach q in {0.05, 0.5, 0.7, 0.9} collect elliptictheta2(pi*x,q),
   x = (0 .. 2), y = (-6 .. 6),
   title = "theta2(pi*x, q) for q = 0.05, 0.5, 0.7, 0.9");
   
% Time: 989 ms

pause;

% cf. Figure 20.3.4: theta3(pi*x,q) for 0≤x≤2, q = 0.05, 0.5, 0.7, 0.9.
plot(foreach q in {0.05, 0.5, 0.7, 0.9} collect elliptictheta3(pi*x,q),
   x = (0 .. 2), y = (0 .. 6),
   title = "theta3(pi*x, q) for q = 0.05, 0.5, 0.7, 0.9");
   
 % Time: 1485 ms

pause;

% cf. Figure 20.3.5: theta4(pi*x,q) for 0≤x≤2, q = 0.05, 0.5, 0.7, 0.9.
plot(foreach q in {0.05, 0.5, 0.7, 0.9} collect elliptictheta4(pi*x,q),
   x = (0 .. 2), y = (0 .. 6),
   title = "theta4(pi*x, q) for q = 0.05, 0.5, 0.7, 0.9");
   
% Time: 1649 ms

pause;

% cf. Figure 20.3.6: theta1(x,q) for 0≤q≤1, x = 0, 0.4, 5, 10, 40.
plot(foreach x in {0, 0.4, 5, 10, 40} collect elliptictheta1(x,q),
   q = (0 .. 1), y = (-3 .. 2),
   title = "theta1(x, q) for x = 0, 0.4, 5, 10, 40");
   
% Time: 938 ms

pause;

% cf. Figure 20.3.7: theta2(x,q) for 0≤q≤1, x = 0, 0.4, 5, 10, 40.
plot(foreach x in {0, 0.4, 5, 10, 40} collect elliptictheta2(x,q),
   q = (0 .. 1), y = (-2 .. 3),
   title = "theta2(x, q) for x = 0, 0.4, 5, 10, 40");
   
% Time: 1148 ms

pause;

% cf. Figure 20.3.8: theta3(x,q) for 0≤q≤1, x = 0, 0.4, 5, 10, 40.
plot(foreach x in {0, 0.4, 5, 10, 40} collect elliptictheta3(x,q),
   q = (0 .. 1), y = (0 .. 3),
   title = "theta3(x, q) for x = 0, 0.4, 5, 10, 40");
   
% Time: 564 ms

pause;

% cf. Figure 20.3.9: theta4(x,q) for 0≤q≤1, x = 0, 0.4, 5, 10, 40.
plot(foreach x in {0, 0.4, 5, 10, 40} collect elliptictheta4(x,q),
   q = (0 .. 1), y = (0 .. 3),
   title = "theta4(x, q) for x = 0, 0.4, 5, 10, 40");
   
% Time: 527 ms

pause;


;end;
