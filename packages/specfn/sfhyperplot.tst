% Plots of Hypergeometric Functions
% =======================================
% cf. <https://dlmf.nist.gov/15.3>

% Author:  Alan Barnes, November 2026
% ef hyperplot.tst 

% Rough timings are included for each plot.

on rounded;
on time;
% cf. Figure 15.3.1: 
plot(hypergeometric({4/3.0, 9/16.0},{2.8},x),
   x = (-100 .. 1), y = (0 .. 2),
   title = "F(4/3,9/16;14/5;x), -100 <=x<=1");

% Time: 52 ms

pause;

% cf. Figure 15.3.2: 
plot(hypergeometric({5, -10},{1},x),
   x = (-0.023 .. 1), y = (-0.5 .. 3),
   title = "F(5, -10; 1; x), -0.023 <=x<=1");

% Time: 50 ms

pause;
   

% cf. Figure 15.3.3: 
plot(hypergeometric({1, -10},{10},x),
   x = (-3 .. 1), y = (0 .. 150),
   title = "F(1, -10; 10; x), -3 <=x<=1");

% Time: 27 ms
pause;

% cf. Figure 15.3.4
plot(hypergeometric({5, 10},{1},x),
   x = (-1 .. 0.022), y = (-0.5 .. 3),
   title = "F(5,10;1;x), -1 <=x<=0.022");

% Time: 4 ms

plot(hypergeometric({0.5, 0.7},{1.5},x),
      x = (-3 .. 1), y = (0 .. 2.5),
   title = "F(0.5,0.7;1.5;x), -3 <=x<=1");

% Time: 145 ms

plot(hypergeometric({0.5, 0.7},{0.6, 0.8, 1},x),
      x = (-3 .. 3), y = (-0.5 .. 6),
   title = "F(0.5,0.7;0.6,0.8,1;x), -3 <=x<=3");

% Time: 25 ms

;end;

