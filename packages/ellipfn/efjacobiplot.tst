% Plots of Jacobi Elliptic Functions
% =======================================
% cf. <https://dlmf.nist.gov/22.3>

% Author:  Alan Barnes, March 2025
% efjacobiplot.tst 

% Rough timings are included for each plot.

on rounded;
on time;
k:=0.4; !K:=ellipticK(k);

% cf. Figure 22.3.1: sn(x,k), cn(x,k), dn(x,k) & nd(x,k) for -3K ≤x≤ 3K, k=0.4
plot({jacobisn(x,k), jacobicn(x,k), jacobidn(x,k), jacobind(x,k)},
   x = (-3!K .. 3!K), y = (-1.5 .. 2),
   title = "sn(x,k), cn(x,k), dn(x,k) & nd(x,k) for k=0.4");

% Time: 3119 ms

pause;
k:=0.7; !K:=ellipticK(k);

% cf. Figure 22.3.2: sn(x,k), cn(x,k), dn(x,k) & nd(x,k) for -3K ≤x≤ 3K, k=0.7
plot({jacobisn(x,k), jacobicn(x,k), jacobidn(x,k), jacobind(x,k)},
   x = (-3!K .. 3!K), y = (-1.5 .. 2),
   title = "sn(x,k), cn(x,k), dn(x,k) & nd(x,k) for k=0.7");

% Time: 3448 ms 

pause;
k:=0.99; !K:=ellipticK(k);

% cf. Figure 22.3.3: sn(x,k), cn(x,k), dn(x,k) & nd(x,k) for -3K ≤x≤ 3K, k=0.99
plot({jacobisn(x,0.99), jacobicn(x,0.99), jacobidn(x,0.99), jacobind(x,0.99)},
   x = (-3!K .. 3!K), y = (-1.5 .. 2),
   title = "sn(x,k), cn(x,k), dn(x,k) & nd(x,k) for k=0.99");

% Time: 5220 ms 

pause;
k:=0.999999; !K:=ellipticK(k);

% cf. Figure 22.3.4: sn(x,k), cn(x,k), dn(x,k) & nd(x,k) for -3K ≤x≤ 3K, k=0.999999
plot({jacobisn(x,0.999999), jacobicn(x,0.999999), jacobidn(x,0.999999), jacobind(x,0.999999)},
   x = (-3!K .. 3!K), y = (-1.5 .. 2),
   title = "sn(x,k), cn(x,k), dn(x,k) & nd(x,k) for k=0.999999");

% Time: 11682 ms 

pause;
k:=0.4; !K:=ellipticK(k);

% cf. Figure 22.3.5: sd(x,k), cd(x,k), ds(x,k) & dc(x,k) for -2K ≤x≤ 2K, k=0.4
plot({jacobisd(x,k), jacobicd(x,k), jacobids(x,k), jacobidc(x,k)},
   x = (-2!K .. 2!K), y = (-5 .. 5),
   title = "sd(x,k), cd(x,k), ds(x,k) & dc(x,k) for k=0.4");

% Time: 1703 ms

pause;
k:=0.7; !K:=ellipticK(k);

% cf. Figure 22.3.6: sd(x,k), cd(x,k), ds(x,k) & dc(x,k) for -2K ≤x≤ 2K, k=0.7
plot({jacobisd(x,k), jacobicd(x,k), jacobids(x,k), jacobidc(x,k)},
   x = (-2!K .. 2!K), y = (-5 .. 5),
   title = "sd(x,k), cd(x,k), ds(x,k) & dc(x,k) for k=0.7");

% Time: 1946 ms 

pause;
k:=0.99; !K:=ellipticK(k);

% cf. Figure 22.3.7: sd(x,k), cd(x,k), ds(x,k) & dc(x,k) for -2K ≤x≤ 2K, k=0.99
plot({jacobisd(x,k), jacobicd(x,k), jacobids(x,k), jacobidc(x,k)},
   x = (-2!K .. 2!K), y = (-5 .. 5),
   title = "sd(x,k), cd(x,k), ds(x,k) & dc(x,k) for k=0.99");

% Time: 3577 ms

pause;
k:=0.999999; !K:=ellipticK(k);

% cf. Figure 22.3.8: sd(x,k), cd(x,k), ds(x,k) & dc(x,k) for -2K ≤x≤ 2K, k=0.999999
plot({jacobisd(x,k), jacobicd(x,k), jacobids(x,k), jacobidc(x,k)},
   x = (-2!K .. 2!K), y = (-5 .. 5),
   title = "sd(x,k), cd(x,k), ds(x,k) & dc(x,k) for k=0.999999");

% Time: 7270 ms  

pause;
k:=0.4; !K:=ellipticK(k);

% cf. Figure 22.3.9: sc(x,k), cs(x,k), ns(x,k) & nc(x,k) for -2K ≤x≤ 2K, k=0.4
plot({jacobisc(x,k), jacobics(x,k), jacobins(x,k), jacobinc(x,k)},
   x = (-2!K .. 2!K), y = (-5 .. 5),
   title = "sc(x,k), cs(x,k), ns(x,k) & nc(x,k) for k=0.4");

% Time: 2814 ms

pause;
k:=0.4; !K:=ellipticK(k);

% cf. Figure 22.3.10: sc(x,k), cs(x,k), ns(x,k) & nc(x,k) for -2K ≤x≤ 2K, k=0.7
plot({jacobisc(x,k), jacobics(x,k), jacobins(x,k), jacobinc(x,k)},
   x = (-2!K .. 2!K), y = (-5 .. 5),
   title = "sc(x,k), cs(x,k), ns(x,k) & nc(x,k) for k=0.7");

% Time: 2693 ms

pause;
k:=0.99; !K:=ellipticK(k);

% cf. Figure 22.3.11: sc(x,k), cs(x,k), ns(x,k) & nc(x,k) for -2K ≤x≤ 2K, k=0.99
plot({jacobisc(x,k), jacobics(x,k), jacobins(x,k), jacobinc(x,k)},
   x = (-2!K .. 2!K), y = (-5 .. 5),
   title = "sc(x,k), cs(x,k), ns(x,k) & nc(x,k) for k=0.99");

% Time: 3671 ms

pause;
k:=0.999999; !K:=ellipticK(k);

% cf. Figure 22.3.12: sc(x,k), cs(x,k), ns(x,k) & nc(x,k) for -2K ≤x≤ 2K, k=0.999999
plot({jacobisc(x,k), jacobics(x,k), jacobins(x,k), jacobinc(x,k)},
   x = (-2!K .. 2!K), y = (-5 .. 5),
   title = "sc(x,k), cs(x,k), ns(x,k) & nc(x,k) for k=0.999999");

% Time: 8657 ms


;end;
