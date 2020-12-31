% Test typeset display of special symbols and standard functions.
% Output from Run-REDUCE (https://fjwright.github.io/Run-REDUCE/) is
% provided as "symbols_and_functions.pdf".  Output using other GUIs
% should be comparable but may not be identical.

% $Id:$

% Symbolic constants:
{infinity, pi, Euler_gamma, golden_ratio};

% Greek letters:
{alpha, beta, gamma, delta, epsilon, zeta, eta, theta, iota, kappa, lambda, mu};
{nu, xi, omicron, pi, rho, sigma, tau, upsilon, phi, chi, psi, omega};
{!Alpha, !Beta, !Gamma, !Delta, !Epsilon, !Zeta, !Eta, !Theta, !Iota, !Kappa, !Lambda, !Mu};
{!Nu, !Xi, !Omicron, !Pi, !Rho, !Sigma, !Tau, !Upsilon, !Phi, !Chi, !Psi, !Omega};

% Elementary transcendental functions:
{exp(x), log(x), log10(x), logb(x, b), sqrt(x), factorial(x)};
{sin(x), cos(x), tan(x), csc(x), sec(x), cot(x)};
{sinh(x), cosh(x), tanh(x), csch(x), sech(x), coth(x)};
{asin(x), acos(x), atan(x), atan2(y, x), acsc(x), asec(x), acot(x)};
{asinh(x), acosh(x), atanh(x), acsch(x), asech(x), acoth(x)};

% Complex value functions:
{repart z, impart z, conj z, conj(a+i*b)};
let conj z => z_bar; {conj z, conj z_bar, z*z_bar = abs(z)^2};

% Gamma, Beta and related functions:
{Gamma(z), Beta(a, b), psi(z), polygamma(n, z), iGamma(a, z), m_Gamma(a, z), iBeta(a, b, x),
   dilog(z), Pochhammer(a, n), binomial(m, n), zeta(s), Lambert_W(x)};

load_package specfn;

% Integral functions:
{Ei(x), li(x), Si(z), Ci(z), Shi(z), Chi(z), erf(z), erfc(z), Fresnel_S(z), Fresnel_C(z)};

% Airy, Bessel and related functions:
{Airy_Ai(z), Airy_Bi(z), Airy_AiPrime(z), Airy_BiPrime(z), BesselJ(nu, z), BesselY(nu, z),
   BesselI(nu, z), BesselK(nu, z), Hankel1(nu, z), Hankel2(nu, z)};

% Struve, Lommel, Kummer, Whittaker and spherical harmonic functions:
{StruveH(nu, z), StruveL(nu, z), Lommel1(mu, nu, z), Lommel2(mu, nu, z),
   KummerM(a, b, z), KummerU(a, b, z), WhittakerM(kappa, mu, z), WhittakerW(kappa, mu, z),
   SphericalHarmonicY(3, 2, theta, phi), SolidHarmonicY(3, 2, x, y, z, r2)};

% Classical orthogonal polynomials:
{JacobiP(n, alpha, beta, x), GegenbauerP(n, lambda, x), ChebyshevT(n, x), ChebyshevU(n, x),
   LegendreP(n, x), LegendreP(n, m, x), LaguerreP(n, x), LaguerreP(n, alpha, x), HermiteP(n, x)};

% Other Polynomials and Numbers:
{BernoulliP(n, x), EulerP(n, x), FibonacciP(n, x)};
{Bernoulli(n), Euler(n), Fibonacci(n), Stirling1(n, m), Stirling2(n, m), Motzkin(n)};

;end;
