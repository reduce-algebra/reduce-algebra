% Plots of Weierstrass Elliptic Functions
% =======================================
% cf. <https://dlmf.nist.gov/23.4>

% Author: Francis Wright, March 2025

% Rough timings are included for each plot.

on rounded;

% Real Variables
% --------------

% cf. Figure 23.4.1: ℘⁡(x;g_2⁡,0) for 0≤x≤9, g_2⁡ = 0.1, 0.2, 0.5, 0.8.
% (Lemniscatic case.)
plot(foreach g2 in {0.1, 0.2, 0.5, 0.8} collect Weierstrass1(x, g2, 0),
   x = (0 .. 9), y = (0 .. 2),
   title = "Weierstrass p(x; g_2, 0)", ylabel = "p(x; g_2, 0)");
% Time: 12s

% cf. Figure 23.4.2: ℘⁡(x;0,g_3⁡) for 0≤x≤9, g_3⁡ = 0.1, 0.2, 0.5, 0.8.
% (Equianharmonic case.)
plot(foreach g3 in {0.1, 0.2, 0.5, 0.8} collect Weierstrass1(x, 0, g3),
   x = (0 .. 9), y = (0 .. 2),
   title = "Weierstrass p(x; 0, g_3)", ylabel = "p(x; 0, g_3)");
% Time: 52s  SLOW!

% cf. Figure 23.4.3: ζ⁡(x;g_2⁡,0) for 0≤x≤8, g_2⁡ = 0.1, 0.2, 0.5, 0.8.
% (Lemniscatic case.)
plot(foreach g2 in {0.1, 0.2, 0.5, 0.8} collect Weierstrasszeta1(x, g2, 0),
   x = (0 .. 8), y = (-4 .. 4),
   title = "Weierstrass zeta(x; g_2, 0)", ylabel = "zeta(x; g_2, 0)");
% Time: 28s

% cf. Figure 23.4.4: ζ⁡(x;0,g_3⁡) for 0≤x≤8, g_3⁡ = 0.1, 0.2, 0.5, 0.8.
% (Equianharmonic case.)
plot(foreach g3 in {0.1, 0.2, 0.5, 0.8} collect Weierstrasszeta1(x, 0, g3),
   x = (0 .. 8), y = (-4 .. 4),
   title = "Weierstrass zeta(x; 0, g_3)", ylabel = "zeta(x; 0, g_3)");
% Time: 7s

% cf. Figure 23.4.5: σ⁡(x;g_2⁡,0) for −5≤x≤5, g_2⁡ = 0.1, 0.2, 0.5, 0.8.
% (Lemniscatic case.)
plot(foreach g2 in {0.1, 0.2, 0.5, 0.8} collect Weierstrass_sigma0(x, g2, 0),
   x = (-5 .. 5), y = (-4 .. 4),
   title = "Weierstrass sigma(x; g_2, 0)", ylabel = "sigma(x; g_2, 0)");
% Time: 1s

% cf. Figure 23.4.6: σ⁡(x;0,g_3⁡) for −5≤x≤5, g_3⁡ = 0.1, 0.2, 0.5, 0.8.
% (Equianharmonic case.)
plot(foreach g3 in {0.1, 0.2, 0.5, 0.8} collect Weierstrass_sigma0(x, 0, g3),
   x = (-5 .. 5), y = (-4 .. 4),
   title = "Weierstrass sigma(x; 0, g_3)", ylabel = "sigma(x; 0, g_3)");
% Time: 2s

on complex;

% cf. Figure 23.4.7: ℘⁡(x) with ω_1=K⁡(k), ω_3=i⁢K′⁡(k) for 0≤x≤9,
% k^2 = 0.2, 0.8, 0.95, 0.99. (Lemniscatic case.)
plot(foreach k in {sqrt 0.2, sqrt 0.8, sqrt 0.95, sqrt 0.99} collect
   Weierstrass(x, EllipticK(k), i*EllipticK!'(k)), x = (0 .. 9), y = (0 .. 2),
   title = "Weierstrass(x, K(k), iK'(k))", ylabel = "p(x, K(k), iK'(k))");
% Time: 67s  SLOW!


% Complex Variables
% -----------------
% Only absolute values are plotted, not phases.

% cf. Figure 23.4.8: ℘⁡(x+i⁢y) with ω_1=K⁡(k), ω_3=i⁢K′⁡(k) for
% −2⁢K⁡(k)≤x≤2⁢K⁡(k), 0≤y≤6⁢K′⁡(k), k^2=0.9.
begin scalar k := sqrt 0.9, KK := EllipticK(k), KK!' := EllipticK!'(k);
   plot(abs Weierstrass(x+i*y, KK, i*KK!'),
      x = (-2KK .. 2KK), y = (0 .. 6KK!'), z = (0 .. 6),
      title = "z = |Weierstrass p(x+iy, K(k), iK'(k))|",
      points = 30, hidden3d)
end;
% Time: 11s

% cf. Figure 23.4.9: ℘⁡(x+i⁢y;1,4⁢i) for −3.8≤x≤3.8, −3.8≤y≤3.8.
plot(abs Weierstrass1(x+i*y, 1, 4i), x = (-3.8 .. 3.8), y = (-3.8 .. 3.8),
   z = (0 .. 4), title = "z = |Weierstrass p(x+iy; 1, 4i)|",
   points = 30, hidden3d);
% Time: 42s

% cf. Figure 23.4.10: ζ⁡(x+i⁢y;1,0) for −5≤x≤5, −5≤y≤5.
plot(abs Weierstrasszeta1(x+i*y, 1, 0), x = (-5 .. 5), y = (-5 .. 5),
   z = (0 .. 12), title = "z = |Weierstrass zeta(x+iy; 1, 0)|",
   points = 30, hidden3d);
% Time: 39s

% cf. Figure 23.4.11: σ⁡(x+i⁢y;1,i) for −2.5≤x≤2.5, −2.5≤y≤2.5.
plot(abs Weierstrass_sigma0(x+i*y, 1, i), x = (-2.5 .. 2.5), y = (-2.5 .. 2.5),
   title = "z = |Weierstrass sigma(x+iy; 1, i)|", hidden3d);
% Time: 17s

% cf. Figure 23.4.12: ℘⁡(3.7;a+i⁢b,0) for −5≤a≤3, −4≤b≤4. There is a
% double zero at a=b=0 and double poles on the real axis.
% plot(abs Weierstrass1(3.7, a+i*b, 0), a = (-5 .. 3), b = (-4 .. 4),
%    z = (0 .. 40), title = "z = |Weierstrass p(3.7; a+ib, 0)|", hidden3d);
% PLOT IGNORES Z RANGE!  TO BE FIXED.
% Ugly work-around:
plot(abs Weierstrass1(3.7, x+i*y, 0), x = (-5 .. 3), y = (-4 .. 4),
   z = (0 .. 40), title = "z = |Weierstrass p(3.7; a+ib, 0)|", hidden3d,
   xlabel = "a", ylabel = "b");
% Time: 25s

;end;
