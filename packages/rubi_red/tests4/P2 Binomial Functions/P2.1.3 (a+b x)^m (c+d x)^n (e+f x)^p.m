(* ::Package:: *)

(* ::Title:: *)
(*Integrands of the form x^m (a+b x)^n (c+d x)^p*)


(* ::Section::Closed:: *)
(*Integrands of the form x^m (a+b x)^n (c+d x)^p*)


(* ::Subsection::Closed:: *)
(*Integrands of the form x^m (a+b x)^1 (c+d x)^n*)


(* ::Subsubsection::Closed:: *)
(*n>0*)


{x^2*(a + b*x)^n*(c + d*x), x, 2, (a^2*(b*c - a*d)*(a + b*x)^(1 + n))/(b^4*(1 + n)) - (a*(2*b*c - 3*a*d)*(a + b*x)^(2 + n))/(b^4*(2 + n)) + ((b*c - 3*a*d)*(a + b*x)^(3 + n))/(b^4*(3 + n)) + (d*(a + b*x)^(4 + n))/(b^4*(4 + n))}
{x*(a + b*x)^n*(c + d*x), x, 2, -((a*(b*c - a*d)*(a + b*x)^(1 + n))/(b^3*(1 + n))) + ((b*c - 2*a*d)*(a + b*x)^(2 + n))/(b^3*(2 + n)) + (d*(a + b*x)^(3 + n))/(b^3*(3 + n))}
{(a + b*x)^n*(c + d*x), x, 2, ((b*c - a*d)*(a + b*x)^(1 + n))/(b^2*(1 + n)) + (d*(a + b*x)^(2 + n))/(b^2*(2 + n))}
{1/x^1*(a + b*x)^n*(c + d*x), x, 2, (d*(a + b*x)^(1 + n))/(b*(1 + n)) - (c*(a + b*x)^(1 + n)*Hypergeometric2F1[1, 1 + n, 2 + n, (a + b*x)/a])/(a*(1 + n))}


{x^m*(a + b*x)*(c + d*x)^5, x, 2, (a*c^5*x^(1 + m))/(1 + m) + (c^4*(b*c + 5*a*d)*x^(2 + m))/(2 + m) + (5*c^3*d*(b*c + 2*a*d)*x^(3 + m))/(3 + m) + (10*c^2*d^2*(b*c + a*d)*x^(4 + m))/(4 + m) + (5*c*d^3*(2*b*c + a*d)*x^(5 + m))/(5 + m) + (d^4*(5*b*c + a*d)*x^(6 + m))/(6 + m) + (b*d^5*x^(7 + m))/(7 + m)}

{x^3*(a + b*x)*(c + d*x)^5, x, 2, (1/4)*a*c^5*x^4 + (1/5)*c^4*(b*c + 5*a*d)*x^5 + (5/6)*c^3*d*(b*c + 2*a*d)*x^6 + (10/7)*c^2*d^2*(b*c + a*d)*x^7 + (5/8)*c*d^3*(2*b*c + a*d)*x^8 + (1/9)*d^4*(5*b*c + a*d)*x^9 + (1/10)*b*d^5*x^10}
{x^2*(a + b*x)*(c + d*x)^5, x, 2, -((c^2*(b*c - a*d)*(c + d*x)^6)/(6*d^4)) + (c*(3*b*c - 2*a*d)*(c + d*x)^7)/(7*d^4) - ((3*b*c - a*d)*(c + d*x)^8)/(8*d^4) + (b*(c + d*x)^9)/(9*d^4)}
{x^1*(a + b*x)*(c + d*x)^5, x, 2, (c*(b*c - a*d)*(c + d*x)^6)/(6*d^3) - ((2*b*c - a*d)*(c + d*x)^7)/(7*d^3) + (b*(c + d*x)^8)/(8*d^3)}
{x^0*(a + b*x)*(c + d*x)^5, x, 2, -(((b*c - a*d)*(c + d*x)^6)/(6*d^2)) + (b*(c + d*x)^7)/(7*d^2)}
{1/x^1*(a + b*x)*(c + d*x)^5, x, 3, 5*a*c^4*d*x + 5*a*c^3*d^2*x^2 + (10/3)*a*c^2*d^3*x^3 + (5/4)*a*c*d^4*x^4 + (1/5)*a*d^5*x^5 + (b*(c + d*x)^6)/(6*d) + a*c^5*Log[x]}
{1/x^2*(a + b*x)*(c + d*x)^5, x, 2, -((a*c^5)/x) + 5*c^3*d*(b*c + 2*a*d)*x + 5*c^2*d^2*(b*c + a*d)*x^2 + (5/3)*c*d^3*(2*b*c + a*d)*x^3 + (1/4)*d^4*(5*b*c + a*d)*x^4 + (1/5)*b*d^5*x^5 + c^4*(b*c + 5*a*d)*Log[x]}
{1/x^3*(a + b*x)*(c + d*x)^5, x, 2, -((a*c^5)/(2*x^2)) - (c^4*(b*c + 5*a*d))/x + 10*c^2*d^2*(b*c + a*d)*x + (5/2)*c*d^3*(2*b*c + a*d)*x^2 + (1/3)*d^4*(5*b*c + a*d)*x^3 + (1/4)*b*d^5*x^4 + 5*c^3*d*(b*c + 2*a*d)*Log[x]}


{x^1*(a + b*x)*(c + d*x)^16, x, 2, (c*(b*c - a*d)*(c + d*x)^17)/(17*d^3) - ((2*b*c - a*d)*(c + d*x)^18)/(18*d^3) + (b*(c + d*x)^19)/(19*d^3)}
{x^2*(a + b*x)*(c + d*x)^16, x, 2, -((c^2*(b*c - a*d)*(c + d*x)^17)/(17*d^4)) + (c*(3*b*c - 2*a*d)*(c + d*x)^18)/(18*d^4) - ((3*b*c - a*d)*(c + d*x)^19)/(19*d^4) + (b*(c + d*x)^20)/(20*d^4)}
{x^3*(a + b*x)*(c + d*x)^16, x, 2, (c^3*(b*c - a*d)*(c + d*x)^17)/(17*d^5) - (c^2*(4*b*c - 3*a*d)*(c + d*x)^18)/(18*d^5) + (3*c*(2*b*c - a*d)*(c + d*x)^19)/(19*d^5) - ((4*b*c - a*d)*(c + d*x)^20)/(20*d^5) + (b*(c + d*x)^21)/(21*d^5)}


{x^2*(2 + x)^5*(2 + 3*x), x, 1, (1/3)*x^3*(2 + x)^6}


(* ::Subsubsection:: *)
(*n<0*)


(* ::Subsection::Closed:: *)
(*Integrands of the form x^m (a+b x)^2 (c+d x)^n*)


(* ::Subsubsection::Closed:: *)
(*n>0*)


{x^2*(a + b*x)^n*(c + d*x)^2, x, 2, (a^2*(b*c - a*d)^2*(a + b*x)^(1 + n))/(b^5*(1 + n)) - (2*a*(b*c - 2*a*d)*(b*c - a*d)*(a + b*x)^(2 + n))/(b^5*(2 + n)) + ((b^2*c^2 - 6*a*b*c*d + 6*a^2*d^2)*(a + b*x)^(3 + n))/(b^5*(3 + n)) + (2*d*(b*c - 2*a*d)*(a + b*x)^(4 + n))/(b^5*(4 + n)) + (d^2*(a + b*x)^(5 + n))/(b^5*(5 + n))}
{x*(a + b*x)^n*(c + d*x)^2, x, 2, -((a*(b*c - a*d)^2*(a + b*x)^(1 + n))/(b^4*(1 + n))) + ((b*c - 3*a*d)*(b*c - a*d)*(a + b*x)^(2 + n))/(b^4*(2 + n)) + (d*(2*b*c - 3*a*d)*(a + b*x)^(3 + n))/(b^4*(3 + n)) + (d^2*(a + b*x)^(4 + n))/(b^4*(4 + n))}
{(a + b*x)^n*(c + d*x)^2, x, 2, ((b*c - a*d)^2*(a + b*x)^(1 + n))/(b^3*(1 + n)) + (2*d*(b*c - a*d)*(a + b*x)^(2 + n))/(b^3*(2 + n)) + (d^2*(a + b*x)^(3 + n))/(b^3*(3 + n))}
{1/x^1*(a + b*x)^n*(c + d*x)^2, x, 3, -((d*(a*d - b*c*(3 + n))*(a + b*x)^(1 + n))/(b^2*(1 + n)*(2 + n))) + (d*(a + b*x)^(1 + n)*(c + d*x))/(b*(2 + n)) - (c^2*(a + b*x)^(1 + n)*Hypergeometric2F1[1, 1 + n, 2 + n, (a + b*x)/a])/(a*(1 + n))}


{x^m*(a + b*x)^2*(c + d*x)^5, x, 2, (a^2*c^5*x^(1 + m))/(1 + m) + (a*c^4*(2*b*c + 5*a*d)*x^(2 + m))/(2 + m) + (c^3*(b^2*c^2 + 10*a*b*c*d + 10*a^2*d^2)*x^(3 + m))/(3 + m) + (5*c^2*d*(b^2*c^2 + 4*a*b*c*d + 2*a^2*d^2)*x^(4 + m))/(4 + m) + (5*c*d^2*(2*b^2*c^2 + 4*a*b*c*d + a^2*d^2)*x^(5 + m))/(5 + m) + (d^3*(10*b^2*c^2 + 10*a*b*c*d + a^2*d^2)*x^(6 + m))/(6 + m) + (b*d^4*(5*b*c + 2*a*d)*x^(7 + m))/(7 + m) + (b^2*d^5*x^(8 + m))/(8 + m)}

{x^3*(a + b*x)^2*(c + d*x)^16, x, 2, -((c^3*(b*c - a*d)^2*(c + d*x)^17)/(17*d^6)) + (c^2*(5*b*c - 3*a*d)*(b*c - a*d)*(c + d*x)^18)/(18*d^6) - (c*(10*b^2*c^2 - 12*a*b*c*d + 3*a^2*d^2)*(c + d*x)^19)/(19*d^6) + ((10*b^2*c^2 - 8*a*b*c*d + a^2*d^2)*(c + d*x)^20)/(20*d^6) - (b*(5*b*c - 2*a*d)*(c + d*x)^21)/(21*d^6) + (b^2*(c + d*x)^22)/(22*d^6)}
{x^2*(a + b*x)^2*(c + d*x)^16, x, 2, (c^2*(b*c - a*d)^2*(c + d*x)^17)/(17*d^5) - (c*(b*c - a*d)*(2*b*c - a*d)*(c + d*x)^18)/(9*d^5) + ((6*b^2*c^2 - 6*a*b*c*d + a^2*d^2)*(c + d*x)^19)/(19*d^5) - (b*(2*b*c - a*d)*(c + d*x)^20)/(10*d^5) + (b^2*(c + d*x)^21)/(21*d^5)}
{x^1*(a + b*x)^2*(c + d*x)^16, x, 2, -((c*(b*c - a*d)^2*(c + d*x)^17)/(17*d^4)) + ((b*c - a*d)*(3*b*c - a*d)*(c + d*x)^18)/(18*d^4) - (b*(3*b*c - 2*a*d)*(c + d*x)^19)/(19*d^4) + (b^2*(c + d*x)^20)/(20*d^4)}


(* ::Subsubsection:: *)
(*n<0*)


(* ::Subsection::Closed:: *)
(*Integrands of the form x^m (a+b x)^3 (c+d x)^n*)


(* ::Subsubsection::Closed:: *)
(*n>0*)


{x^2*(a + b*x)^n*(c + d*x)^3, x, 2, (a^2*(b*c - a*d)^3*(a + b*x)^(1 + n))/(b^6*(1 + n)) - (a*(2*b*c - 5*a*d)*(b*c - a*d)^2*(a + b*x)^(2 + n))/(b^6*(2 + n)) + ((b*c - a*d)*(b^2*c^2 - 8*a*b*c*d + 10*a^2*d^2)*(a + b*x)^(3 + n))/(b^6*(3 + n)) + (d*(3*b^2*c^2 - 12*a*b*c*d + 10*a^2*d^2)*(a + b*x)^(4 + n))/(b^6*(4 + n)) + (d^2*(3*b*c - 5*a*d)*(a + b*x)^(5 + n))/(b^6*(5 + n)) + (d^3*(a + b*x)^(6 + n))/(b^6*(6 + n))}
{x*(a + b*x)^n*(c + d*x)^3, x, 2, -((a*(b*c - a*d)^3*(a + b*x)^(1 + n))/(b^5*(1 + n))) + ((b*c - 4*a*d)*(b*c - a*d)^2*(a + b*x)^(2 + n))/(b^5*(2 + n)) + (3*d*(b*c - 2*a*d)*(b*c - a*d)*(a + b*x)^(3 + n))/(b^5*(3 + n)) + (d^2*(3*b*c - 4*a*d)*(a + b*x)^(4 + n))/(b^5*(4 + n)) + (d^3*(a + b*x)^(5 + n))/(b^5*(5 + n))}
{(a + b*x)^n*(c + d*x)^3, x, 2, ((b*c - a*d)^3*(a + b*x)^(1 + n))/(b^4*(1 + n)) + (3*d*(b*c - a*d)^2*(a + b*x)^(2 + n))/(b^4*(2 + n)) + (3*d^2*(b*c - a*d)*(a + b*x)^(3 + n))/(b^4*(3 + n)) + (d^3*(a + b*x)^(4 + n))/(b^4*(4 + n))}
{1/x^1*(a + b*x)^n*(c + d*x)^3, x, 7, (3*c^2*d*(a + b*x)^(1 + n))/(b*(1 + n)) - (3*a*c*d^2*(a + b*x)^(1 + n))/(b^2*(1 + n)) + (a^2*d^3*(a + b*x)^(1 + n))/(b^3*(1 + n)) + (3*c*d^2*(a + b*x)^(2 + n))/(b^2*(2 + n)) - (2*a*d^3*(a + b*x)^(2 + n))/(b^3*(2 + n)) + (d^3*(a + b*x)^(3 + n))/(b^3*(3 + n)) - (c^3*(a + b*x)^(1 + n)*Hypergeometric2F1[1, 1 + n, 2 + n, (a + b*x)/a])/(a*(1 + n))}


(* ::Subsubsection:: *)
(*n<0*)


(* ::Subsection::Closed:: *)
(*Integrands of the form x^m (c+d x)^n / (a+b x)^1*)


(* ::Subsubsection::Closed:: *)
(*n>0*)


{(x^m*(c + d*x))/(a + b*x), x, 2, (d*x^(1 + m))/(b*(1 + m)) + ((b*c - a*d)*x^(1 + m)*Hypergeometric2F1[1, 1 + m, 2 + m, -((b*x)/a)])/(a*b*(1 + m))}

{(x^4*(c + d*x))/(a + b*x), x, 2, -((a^3*(b*c - a*d)*x)/b^5) + (a^2*(b*c - a*d)*x^2)/(2*b^4) - (a*(b*c - a*d)*x^3)/(3*b^3) + ((b*c - a*d)*x^4)/(4*b^2) + (d*x^5)/(5*b) + (a^4*(b*c - a*d)*Log[a + b*x])/b^6}
{(x^3*(c + d*x))/(a + b*x), x, 2, (a^2*(b*c - a*d)*x)/b^4 - (a*(b*c - a*d)*x^2)/(2*b^3) + ((b*c - a*d)*x^3)/(3*b^2) + (d*x^4)/(4*b) - (a^3*(b*c - a*d)*Log[a + b*x])/b^5}
{(x^2*(c + d*x))/(a + b*x), x, 2, -((a*(b*c - a*d)*x)/b^3) + ((b*c - a*d)*x^2)/(2*b^2) + (d*x^3)/(3*b) + (a^2*(b*c - a*d)*Log[a + b*x])/b^4}
{(x*(c + d*x))/(a + b*x), x, 2, ((b*c - a*d)*x)/b^2 + (d*x^2)/(2*b) - (a*(b*c - a*d)*Log[a + b*x])/b^3}
{(c + d*x)/(a + b*x), x, 2, (d*x)/b + ((b*c - a*d)*Log[a + b*x])/b^2}
{(c + d*x)/(x*(a + b*x)), x, 2, (c*Log[x])/a - ((b*c - a*d)*Log[a + b*x])/(a*b)}
{(c + d*x)/(x^2*(a + b*x)), x, 2, -(c/(a*x)) - ((b*c - a*d)*Log[x])/a^2 + ((b*c - a*d)*Log[a + b*x])/a^2}
{(c + d*x)/(x^3*(a + b*x)), x, 2, -c/(2*a*x^2) + (b*c - a*d)/(a^2*x) + (b*(b*c - a*d)*Log[x])/a^3 - (b*(b*c - a*d)*Log[a + b*x])/a^3}
{(c + d*x)/(x^4*(a + b*x)), x, 2, -c/(3*a*x^3) + (b*c - a*d)/(2*a^2*x^2) - (b*(b*c - a*d))/(a^3*x) - (b^2*(b*c - a*d)*Log[x])/a^4 + (b^2*(b*c - a*d)*Log[a + b*x])/a^4}
{(c + d*x)/(x^5*(a + b*x)), x, 2, -c/(4*a*x^4) + (b*c - a*d)/(3*a^2*x^3) - (b*(b*c - a*d))/(2*a^3*x^2) + (b^2*(b*c - a*d))/(a^4*x) + (b^3*(b*c - a*d)*Log[x])/a^5 - (b^3*(b*c - a*d)*Log[a + b*x])/a^5}


{(x^m*(c + d*x)^2)/(a + b*x), x, 3, -((d*(a*d*(2 + m) - b*c*(3 + m))*x^(1 + m))/(b^2*(1 + m)*(2 + m))) + (d*x^(1 + m)*(c + d*x))/(b*(2 + m)) + ((b*c - a*d)^2*x^(1 + m)*Hypergeometric2F1[1, 1 + m, 2 + m, -((b*x)/a)])/(a*b^2*(1 + m))}

{(x^4*(c + d*x)^2)/(a + b*x), x, 2, -((a^3*(b*c - a*d)^2*x)/b^6) + (a^2*(b*c - a*d)^2*x^2)/(2*b^5) - (a*(b*c - a*d)^2*x^3)/(3*b^4) + ((b*c - a*d)^2*x^4)/(4*b^3) + (d*(2*b*c - a*d)*x^5)/(5*b^2) + (d^2*x^6)/(6*b) + (a^4*(b*c - a*d)^2*Log[a + b*x])/b^7}
{(x^3*(c + d*x)^2)/(a + b*x), x, 2, (a^2*(b*c - a*d)^2*x)/b^5 - (a*(b*c - a*d)^2*x^2)/(2*b^4) + ((b*c - a*d)^2*x^3)/(3*b^3) + (d*(2*b*c - a*d)*x^4)/(4*b^2) + (d^2*x^5)/(5*b) - (a^3*(b*c - a*d)^2*Log[a + b*x])/b^6}
{(x^2*(c + d*x)^2)/(a + b*x), x, 2, -((a*(b*c - a*d)^2*x)/b^4) + ((b*c - a*d)^2*x^2)/(2*b^3) + (d*(2*b*c - a*d)*x^3)/(3*b^2) + (d^2*x^4)/(4*b) + (a^2*(b*c - a*d)^2*Log[a + b*x])/b^5}
{(x*(c + d*x)^2)/(a + b*x), x, 2, ((b*c - a*d)^2*x)/b^3 + (d*(2*b*c - a*d)*x^2)/(2*b^2) + (d^2*x^3)/(3*b) - (a*(b*c - a*d)^2*Log[a + b*x])/b^4}
{(c + d*x)^2/(a + b*x), x, 2, (d*(b*c - a*d)*x)/b^2 + (c + d*x)^2/(2*b) + ((b*c - a*d)^2*Log[a + b*x])/b^3}
{(c + d*x)^2/(x*(a + b*x)), x, 2, (d^2*x)/b + (c^2*Log[x])/a - ((b*c - a*d)^2*Log[a + b*x])/(a*b^2)}
{(c + d*x)^2/(x^2*(a + b*x)), x, 2, -(c^2/(a*x)) - (c*(b*c - 2*a*d)*Log[x])/a^2 + ((b*c - a*d)^2*Log[a + b*x])/(a^2*b)}
{(c + d*x)^2/(x^3*(a + b*x)), x, 2, -c^2/(2*a*x^2) + (c*(b*c - 2*a*d))/(a^2*x) + ((b*c - a*d)^2*Log[x])/a^3 - ((b*c - a*d)^2*Log[a + b*x])/a^3}
{(c + d*x)^2/(x^4*(a + b*x)), x, 2, -c^2/(3*a*x^3) + (c*(b*c - 2*a*d))/(2*a^2*x^2) - (b*c - a*d)^2/(a^3*x) - (b*(b*c - a*d)^2*Log[x])/a^4 + (b*(b*c - a*d)^2*Log[a + b*x])/a^4}
{(c + d*x)^2/(x^5*(a + b*x)), x, 2, -c^2/(4*a*x^4) + (c*(b*c - 2*a*d))/(3*a^2*x^3) - (b*c - a*d)^2/(2*a^3*x^2) + (b*(b*c - a*d)^2)/(a^4*x) + (b^2*(b*c - a*d)^2*Log[x])/a^5 - (b^2*(b*c - a*d)^2*Log[a + b*x])/a^5}
{(c + d*x)^2/(x^6*(a + b*x)), x, 2, -c^2/(5*a*x^5) + (c*(b*c - 2*a*d))/(4*a^2*x^4) - (b*c - a*d)^2/(3*a^3*x^3) + (b*(b*c - a*d)^2)/(2*a^4*x^2) - (b^2*(b*c - a*d)^2)/(a^5*x) - (b^3*(b*c - a*d)^2*Log[x])/a^6 + (b^3*(b*c - a*d)^2*Log[a + b*x])/a^6}


{(x^m*(c + d*x)^3)/(a + b*x), x, 3, (d*(3*b^2*c^2 - 3*a*b*c*d + a^2*d^2)*x^(1 + m))/(b^3*(1 + m)) + (d^2*(3*b*c - a*d)*x^(2 + m))/(b^2*(2 + m)) + (d^3*x^(3 + m))/(b*(3 + m)) + ((b*c - a*d)^3*x^(1 + m)*Hypergeometric2F1[1, 1 + m, 2 + m, -((b*x)/a)])/(a*b^3*(1 + m))}

{(x^4*(c + d*x)^3)/(a + b*x), x, 2, -((a^3*(b*c - a*d)^3*x)/b^7) + (a^2*(b*c - a*d)^3*x^2)/(2*b^6) - (a*(b*c - a*d)^3*x^3)/(3*b^5) + ((b*c - a*d)^3*x^4)/(4*b^4) + (d*(3*b^2*c^2 - 3*a*b*c*d + a^2*d^2)*x^5)/(5*b^3) + (d^2*(3*b*c - a*d)*x^6)/(6*b^2) + (d^3*x^7)/(7*b) + (a^4*(b*c - a*d)^3*Log[a + b*x])/b^8}
{(x^3*(c + d*x)^3)/(a + b*x), x, 2, (a^2*(b*c - a*d)^3*x)/b^6 - (a*(b*c - a*d)^3*x^2)/(2*b^5) + ((b*c - a*d)^3*x^3)/(3*b^4) + (d*(3*b^2*c^2 - 3*a*b*c*d + a^2*d^2)*x^4)/(4*b^3) + (d^2*(3*b*c - a*d)*x^5)/(5*b^2) + (d^3*x^6)/(6*b) - (a^3*(b*c - a*d)^3*Log[a + b*x])/b^7}
{(x^2*(c + d*x)^3)/(a + b*x), x, 2, -((a*(b*c - a*d)^3*x)/b^5) + ((b*c - a*d)^3*x^2)/(2*b^4) + (d*(3*b^2*c^2 - 3*a*b*c*d + a^2*d^2)*x^3)/(3*b^3) + (d^2*(3*b*c - a*d)*x^4)/(4*b^2) + (d^3*x^5)/(5*b) + (a^2*(b*c - a*d)^3*Log[a + b*x])/b^6}
{(x*(c + d*x)^3)/(a + b*x), x, 2, ((b*c - a*d)^3*x)/b^4 + (d*(3*b^2*c^2 - 3*a*b*c*d + a^2*d^2)*x^2)/(2*b^3) + (d^2*(3*b*c - a*d)*x^3)/(3*b^2) + (d^3*x^4)/(4*b) - (a*(b*c - a*d)^3*Log[a + b*x])/b^5}
{(c + d*x)^3/(a + b*x), x, 2, (d*(b*c - a*d)^2*x)/b^3 + ((b*c - a*d)*(c + d*x)^2)/(2*b^2) + (c + d*x)^3/(3*b) + ((b*c - a*d)^3*Log[a + b*x])/b^4}
{(c + d*x)^3/(x*(a + b*x)), x, 2, (d^2*(3*b*c - a*d)*x)/b^2 + (d^3*x^2)/(2*b) + (c^3*Log[x])/a - ((b*c - a*d)^3*Log[a + b*x])/(a*b^3)}
{(c + d*x)^3/(x^2*(a + b*x)), x, 2, -(c^3/(a*x)) + (d^3*x)/b - (c^2*(b*c - 3*a*d)*Log[x])/a^2 + ((b*c - a*d)^3*Log[a + b*x])/(a^2*b^2)}
{(c + d*x)^3/(x^3*(a + b*x)), x, 2, -c^3/(2*a*x^2) + (c^2*(b*c - 3*a*d))/(a^2*x) + (c*(b^2*c^2 - 3*a*b*c*d + 3*a^2*d^2)*Log[x])/a^3 - ((b*c - a*d)^3*Log[a + b*x])/(a^3*b)}
{(c + d*x)^3/(x^4*(a + b*x)), x, 2, -c^3/(3*a*x^3) + (c^2*(b*c - 3*a*d))/(2*a^2*x^2) - (c*(b^2*c^2 - 3*a*b*c*d + 3*a^2*d^2))/(a^3*x) - ((b*c - a*d)^3*Log[x])/a^4 + ((b*c - a*d)^3*Log[a + b*x])/a^4}
{(c + d*x)^3/(x^5*(a + b*x)), x, 2, -c^3/(4*a*x^4) + (c^2*(b*c - 3*a*d))/(3*a^2*x^3) - (c*(b^2*c^2 - 3*a*b*c*d + 3*a^2*d^2))/(2*a^3*x^2) + (b*c - a*d)^3/(a^4*x) + (b*(b*c - a*d)^3*Log[x])/a^5 - (b*(b*c - a*d)^3*Log[a + b*x])/a^5}
{(c + d*x)^3/(x^6*(a + b*x)), x, 2, -c^3/(5*a*x^5) + (c^2*(b*c - 3*a*d))/(4*a^2*x^4) - (c*(b^2*c^2 - 3*a*b*c*d + 3*a^2*d^2))/(3*a^3*x^3) + (b*c - a*d)^3/(2*a^4*x^2) - (b*(b*c - a*d)^3)/(a^5*x) - (b^2*(b*c - a*d)^3*Log[x])/a^6 + (b^2*(b*c - a*d)^3*Log[a + b*x])/a^6}
{(c + d*x)^3/(x^7*(a + b*x)), x, 2, -c^3/(6*a*x^6) + (c^2*(b*c - 3*a*d))/(5*a^2*x^5) - (c*(b^2*c^2 - 3*a*b*c*d + 3*a^2*d^2))/(4*a^3*x^4) + (b*c - a*d)^3/(3*a^4*x^3) - (b*(b*c - a*d)^3)/(2*a^5*x^2) + (b^2*(b*c - a*d)^3)/(a^6*x) + (b^3*(b*c - a*d)^3*Log[x])/a^7 - (b^3*(b*c - a*d)^3*Log[a + b*x])/a^7}


(* ::Subsubsection::Closed:: *)
(*n<0*)


{x^m/((a + b*x)*(c + d*x)), x, 3, (b*x^(1 + m)*Hypergeometric2F1[1, 1 + m, 2 + m, -((b*x)/a)])/(a*(b*c - a*d)*(1 + m)) - (d*x^(1 + m)*Hypergeometric2F1[1, 1 + m, 2 + m, -((d*x)/c)])/(c*(b*c - a*d)*(1 + m))}

{x^5/((a + b*x)*(c + d*x)), x, 2, -(((b*c + a*d)*(b^2*c^2 + a^2*d^2)*x)/(b^4*d^4)) + ((b^2*c^2 + a*b*c*d + a^2*d^2)*x^2)/(2*b^3*d^3) - ((b*c + a*d)*x^3)/(3*b^2*d^2) + x^4/(4*b*d) - (a^5*Log[a + b*x])/(b^5*(b*c - a*d)) + (c^5*Log[c + d*x])/(d^5*(b*c - a*d))}
{x^4/((a + b*x)*(c + d*x)), x, 2, ((b^2*c^2 + a*b*c*d + a^2*d^2)*x)/(b^3*d^3) - ((b*c + a*d)*x^2)/(2*b^2*d^2) + x^3/(3*b*d) + (a^4*Log[a + b*x])/(b^4*(b*c - a*d)) - (c^4*Log[c + d*x])/(d^4*(b*c - a*d))}
{x^3/((a + b*x)*(c + d*x)), x, 2, -(((b*c + a*d)*x)/(b^2*d^2)) + x^2/(2*b*d) - (a^3*Log[a + b*x])/(b^3*(b*c - a*d)) + (c^3*Log[c + d*x])/(d^3*(b*c - a*d))}
{x^2/((a + b*x)*(c + d*x)), x, 2, x/(b*d) + (a^2*Log[a + b*x])/(b^2*(b*c - a*d)) - (c^2*Log[c + d*x])/(d^2*(b*c - a*d))}
{x/((a + b*x)*(c + d*x)), x, 2, -((a*Log[a + b*x])/(b*(b*c - a*d))) + (c*Log[c + d*x])/(d*(b*c - a*d))}
{1/((a + b*x)*(c + d*x)), x, 2, Log[a + b*x]/(b*c - a*d) - Log[c + d*x]/(b*c - a*d)}
{1/(x*(a + b*x)*(c + d*x)), x, 2, Log[x]/(a*c) - (b*Log[a + b*x])/(a*(b*c - a*d)) + (d*Log[c + d*x])/(c*(b*c - a*d))}
{1/(x^2*(a + b*x)*(c + d*x)), x, 2, -(1/(a*c*x)) - ((b*c + a*d)*Log[x])/(a^2*c^2) + (b^2*Log[a + b*x])/(a^2*(b*c - a*d)) - (d^2*Log[c + d*x])/(c^2*(b*c - a*d))}
{1/(x^3*(a + b*x)*(c + d*x)), x, 2, -(1/(2*a*c*x^2)) + (b*c + a*d)/(a^2*c^2*x) + ((b^2*c^2 + a*b*c*d + a^2*d^2)*Log[x])/(a^3*c^3) - (b^3*Log[a + b*x])/(a^3*(b*c - a*d)) + (d^3*Log[c + d*x])/(c^3*(b*c - a*d))}
{1/(x^4*(a + b*x)*(c + d*x)), x, 2, -(1/(3*a*c*x^3)) + (b*c + a*d)/(2*a^2*c^2*x^2) - (b^2*c^2 + a*b*c*d + a^2*d^2)/(a^3*c^3*x) - ((b*c + a*d)*(b^2*c^2 + a^2*d^2)*Log[x])/(a^4*c^4) + (b^4*Log[a + b*x])/(a^4*(b*c - a*d)) - (d^4*Log[c + d*x])/(c^4*(b*c - a*d))}


{x^m/((a + b*x)*(c + d*x)^2), x, 6, -((d*x^(1 + m))/(c*(b*c - a*d)*(c + d*x))) + (b^2*x^(1 + m)*Hypergeometric2F1[1, 1 + m, 2 + m, -((b*x)/a)])/(a*(b*c - a*d)^2*(1 + m)) - (b*d*x^(1 + m)*Hypergeometric2F1[1, 1 + m, 2 + m, -((d*x)/c)])/(c*(b*c - a*d)^2*(1 + m)) + (d*m*x^(1 + m)*Hypergeometric2F1[1, 1 + m, 2 + m, -((d*x)/c)])/(c^2*(b*c - a*d)*(1 + m))}
{x^m/((1 + a*x)*(1 - a*x)^2), x, 6, x^(1 + m)/(2*(1 - a*x)) + (x^(1 + m)*Hypergeometric2F1[1, 1 + m, 2 + m, (-a)*x])/(4*(1 + m)) + (x^(1 + m)*Hypergeometric2F1[1, 1 + m, 2 + m, a*x])/(4*(1 + m)) - (m*x^(1 + m)*Hypergeometric2F1[1, 1 + m, 2 + m, a*x])/(2*(1 + m))}

{x^5/((a + b*x)*(c + d*x)^2), x, 2, ((3*b^2*c^2 + 2*a*b*c*d + a^2*d^2)*x)/(b^3*d^4) - ((2*b*c + a*d)*x^2)/(2*b^2*d^3) + x^3/(3*b*d^2) - c^5/(d^5*(b*c - a*d)*(c + d*x)) - (a^5*Log[a + b*x])/(b^4*(b*c - a*d)^2) - (c^4*(4*b*c - 5*a*d)*Log[c + d*x])/(d^5*(b*c - a*d)^2)}
{x^4/((a + b*x)*(c + d*x)^2), x, 2, -(((2*b*c + a*d)*x)/(b^2*d^3)) + x^2/(2*b*d^2) + c^4/(d^4*(b*c - a*d)*(c + d*x)) + (a^4*Log[a + b*x])/(b^3*(b*c - a*d)^2) + (c^3*(3*b*c - 4*a*d)*Log[c + d*x])/(d^4*(b*c - a*d)^2)}
{x^3/((a + b*x)*(c + d*x)^2), x, 2, x/(b*d^2) - c^3/(d^3*(b*c - a*d)*(c + d*x)) - (a^3*Log[a + b*x])/(b^2*(b*c - a*d)^2) - (c^2*(2*b*c - 3*a*d)*Log[c + d*x])/(d^3*(b*c - a*d)^2)}
{x^2/((a + b*x)*(c + d*x)^2), x, 2, c^2/(d^2*(b*c - a*d)*(c + d*x)) + (a^2*Log[a + b*x])/(b*(b*c - a*d)^2) + (c*(b*c - 2*a*d)*Log[c + d*x])/(d^2*(b*c - a*d)^2)}
{x/((a + b*x)*(c + d*x)^2), x, 2, -(c/(d*(b*c - a*d)*(c + d*x))) - (a*Log[a + b*x])/(b*c - a*d)^2 + (a*Log[c + d*x])/(b*c - a*d)^2}
{1/((a + b*x)*(c + d*x)^2), x, 2, 1/((b*c - a*d)*(c + d*x)) + (b*Log[a + b*x])/(b*c - a*d)^2 - (b*Log[c + d*x])/(b*c - a*d)^2}
{1/(x*(a + b*x)*(c + d*x)^2), x, 2, -(d/(c*(b*c - a*d)*(c + d*x))) + Log[x]/(a*c^2) - (b^2*Log[a + b*x])/(a*(b*c - a*d)^2) + (d*(2*b*c - a*d)*Log[c + d*x])/(c^2*(b*c - a*d)^2)}
{1/(x^2*(a + b*x)*(c + d*x)^2), x, 2, -(1/(a*c^2*x)) + d^2/(c^2*(b*c - a*d)*(c + d*x)) - ((b*c + 2*a*d)*Log[x])/(a^2*c^3) + (b^3*Log[a + b*x])/(a^2*(b*c - a*d)^2) - (d^2*(3*b*c - 2*a*d)*Log[c + d*x])/(c^3*(b*c - a*d)^2)}
{1/(x^3*(a + b*x)*(c + d*x)^2), x, 2, -(1/(2*a*c^2*x^2)) + (b*c + 2*a*d)/(a^2*c^3*x) - d^3/(c^3*(b*c - a*d)*(c + d*x)) + ((b^2*c^2 + 2*a*b*c*d + 3*a^2*d^2)*Log[x])/(a^3*c^4) - (b^4*Log[a + b*x])/(a^3*(b*c - a*d)^2) + (d^3*(4*b*c - 3*a*d)*Log[c + d*x])/(c^4*(b*c - a*d)^2)}


{x^m/((a + b*x)*(c + d*x)^3), x, 9, -((d*x^(1 + m))/(2*c*(b*c - a*d)*(c + d*x)^2)) - (b*d*x^(1 + m))/(c*(b*c - a*d)^2*(c + d*x)) - (d*(1 - m)*x^(1 + m))/(2*c^2*(b*c - a*d)*(c + d*x)) + (b^3*x^(1 + m)*Hypergeometric2F1[1, 1 + m, 2 + m, -((b*x)/a)])/(a*(b*c - a*d)^3*(1 + m)) - (b^2*d*x^(1 + m)*Hypergeometric2F1[1, 1 + m, 2 + m, -((d*x)/c)])/(c*(b*c - a*d)^3*(1 + m)) + (b*d*m*x^(1 + m)*Hypergeometric2F1[1, 1 + m, 2 + m, -((d*x)/c)])/(c^2*(b*c - a*d)^2*(1 + m)) + (d*(1 - m)*m*x^(1 + m)*Hypergeometric2F1[1, 1 + m, 2 + m, -((d*x)/c)])/(2*c^3*(b*c - a*d)*(1 + m))}

{x^6/((a + b*x)*(c + d*x)^3), x, 2, ((6*b^2*c^2 + 3*a*b*c*d + a^2*d^2)*x)/(b^3*d^5) - ((3*b*c + a*d)*x^2)/(2*b^2*d^4) + x^3/(3*b*d^3) + c^6/(2*d^6*(b*c - a*d)*(c + d*x)^2) - (c^5*(5*b*c - 6*a*d))/(d^6*(b*c - a*d)^2*(c + d*x)) + (a^6*Log[a + b*x])/(b^4*(b*c - a*d)^3) - (c^4*(10*b^2*c^2 - 24*a*b*c*d + 15*a^2*d^2)*Log[c + d*x])/(d^6*(b*c - a*d)^3)}
{x^5/((a + b*x)*(c + d*x)^3), x, 2, -(((3*b*c + a*d)*x)/(b^2*d^4)) + x^2/(2*b*d^3) - c^5/(2*d^5*(b*c - a*d)*(c + d*x)^2) + (c^4*(4*b*c - 5*a*d))/(d^5*(b*c - a*d)^2*(c + d*x)) - (a^5*Log[a + b*x])/(b^3*(b*c - a*d)^3) + (c^3*(6*b^2*c^2 - 15*a*b*c*d + 10*a^2*d^2)*Log[c + d*x])/(d^5*(b*c - a*d)^3)}
{x^4/((a + b*x)*(c + d*x)^3), x, 2, x/(b*d^3) + c^4/(2*d^4*(b*c - a*d)*(c + d*x)^2) - (c^3*(3*b*c - 4*a*d))/(d^4*(b*c - a*d)^2*(c + d*x)) + (a^4*Log[a + b*x])/(b^2*(b*c - a*d)^3) - (c^2*(3*b^2*c^2 - 8*a*b*c*d + 6*a^2*d^2)*Log[c + d*x])/(d^4*(b*c - a*d)^3)}
{x^3/((a + b*x)*(c + d*x)^3), x, 2, -(c^3/(2*d^3*(b*c - a*d)*(c + d*x)^2)) + (c^2*(2*b*c - 3*a*d))/(d^3*(b*c - a*d)^2*(c + d*x)) - (a^3*Log[a + b*x])/(b*(b*c - a*d)^3) + (c*(b^2*c^2 - 3*a*b*c*d + 3*a^2*d^2)*Log[c + d*x])/(d^3*(b*c - a*d)^3)}
{x^2/((a + b*x)*(c + d*x)^3), x, 2, c^2/(2*d^2*(b*c - a*d)*(c + d*x)^2) - (c*(b*c - 2*a*d))/(d^2*(b*c - a*d)^2*(c + d*x)) + (a^2*Log[a + b*x])/(b*c - a*d)^3 - (a^2*Log[c + d*x])/(b*c - a*d)^3}
{x/((a + b*x)*(c + d*x)^3), x, 2, -(c/(2*d*(b*c - a*d)*(c + d*x)^2)) - a/((b*c - a*d)^2*(c + d*x)) - (a*b*Log[a + b*x])/(b*c - a*d)^3 + (a*b*Log[c + d*x])/(b*c - a*d)^3}
{1/((a + b*x)*(c + d*x)^3), x, 2, 1/(2*(b*c - a*d)*(c + d*x)^2) + b/((b*c - a*d)^2*(c + d*x)) + (b^2*Log[a + b*x])/(b*c - a*d)^3 - (b^2*Log[c + d*x])/(b*c - a*d)^3}
{1/(x*(a + b*x)*(c + d*x)^3), x, 2, -(d/(2*c*(b*c - a*d)*(c + d*x)^2)) - (d*(2*b*c - a*d))/(c^2*(b*c - a*d)^2*(c + d*x)) + Log[x]/(a*c^3) - (b^3*Log[a + b*x])/(a*(b*c - a*d)^3) + (d*(3*b^2*c^2 - 3*a*b*c*d + a^2*d^2)*Log[c + d*x])/(c^3*(b*c - a*d)^3)}
{1/(x^2*(a + b*x)*(c + d*x)^3), x, 2, -(1/(a*c^3*x)) + d^2/(2*c^2*(b*c - a*d)*(c + d*x)^2) + (d^2*(3*b*c - 2*a*d))/(c^3*(b*c - a*d)^2*(c + d*x)) - ((b*c + 3*a*d)*Log[x])/(a^2*c^4) + (b^4*Log[a + b*x])/(a^2*(b*c - a*d)^3) - (d^2*(6*b^2*c^2 - 8*a*b*c*d + 3*a^2*d^2)*Log[c + d*x])/(c^4*(b*c - a*d)^3)}
{1/(x^3*(a + b*x)*(c + d*x)^3), x, 2, -(1/(2*a*c^3*x^2)) + (b*c + 3*a*d)/(a^2*c^4*x) - d^3/(2*c^3*(b*c - a*d)*(c + d*x)^2) - (d^3*(4*b*c - 3*a*d))/(c^4*(b*c - a*d)^2*(c + d*x)) + ((b^2*c^2 + 3*a*b*c*d + 6*a^2*d^2)*Log[x])/(a^3*c^5) - (b^5*Log[a + b*x])/(a^3*(b*c - a*d)^3) + (d^3*(10*b^2*c^2 - 15*a*b*c*d + 6*a^2*d^2)*Log[c + d*x])/(c^5*(b*c - a*d)^3)}


(* ::Subsection::Closed:: *)
(*Integrands of the form x^m (c+d x)^n / (a+b x)^2*)


(* ::Subsubsection::Closed:: *)
(*n>0*)


{(x^4*(c + d*x)^2)/(a + b*x)^2, x, 2, (a^2*(3*b*c - 5*a*d)*(b*c - a*d)*x)/b^6 - (a*(b*c - 2*a*d)*(b*c - a*d)*x^2)/b^5 + ((b*c - 3*a*d)*(b*c - a*d)*x^3)/(3*b^4) + (d*(b*c - a*d)*x^4)/(2*b^3) + (d^2*x^5)/(5*b^2) - (a^4*(b*c - a*d)^2)/(b^7*(a + b*x)) - (2*a^3*(2*b*c - 3*a*d)*(b*c - a*d)*Log[a + b*x])/b^7}
{(x^3*(c + d*x)^2)/(a + b*x)^2, x, 2, -((2*a*(b*c - 2*a*d)*(b*c - a*d)*x)/b^5) + ((b*c - 3*a*d)*(b*c - a*d)*x^2)/(2*b^4) + (2*d*(b*c - a*d)*x^3)/(3*b^3) + (d^2*x^4)/(4*b^2) + (a^3*(b*c - a*d)^2)/(b^6*(a + b*x)) + (a^2*(3*b*c - 5*a*d)*(b*c - a*d)*Log[a + b*x])/b^6}
{(x^2*(c + d*x)^2)/(a + b*x)^2, x, 2, ((b*c - 3*a*d)*(b*c - a*d)*x)/b^4 + (d*(b*c - a*d)*x^2)/b^3 + (d^2*x^3)/(3*b^2) - (a^2*(b*c - a*d)^2)/(b^5*(a + b*x)) - (2*a*(b*c - 2*a*d)*(b*c - a*d)*Log[a + b*x])/b^5}
{(x*(c + d*x)^2)/(a + b*x)^2, x, 2, (2*d*(b*c - a*d)*x)/b^3 + (d^2*x^2)/(2*b^2) + (a*(b*c - a*d)^2)/(b^4*(a + b*x)) + ((b*c - 3*a*d)*(b*c - a*d)*Log[a + b*x])/b^4}
{(c + d*x)^2/(a + b*x)^2, x, 2, (d^2*x)/b^2 - (b*c - a*d)^2/(b^3*(a + b*x)) + (2*d*(b*c - a*d)*Log[a + b*x])/b^3}
{(c + d*x)^2/(x*(a + b*x)^2), x, 2, (b*c - a*d)^2/(a*b^2*(a + b*x)) + (c^2*Log[x])/a^2 - (c^2/a^2 - d^2/b^2)*Log[a + b*x]}
{(c + d*x)^2/(x^2*(a + b*x)^2), x, 2, -(c^2/(a^2*x)) - (b*c - a*d)^2/(a^2*b*(a + b*x)) - (2*c*(b*c - a*d)*Log[x])/a^3 + (2*c*(b*c - a*d)*Log[a + b*x])/a^3}
{(c + d*x)^2/(x^3*(a + b*x)^2), x, 2, -(c^2/(2*a^2*x^2)) + (2*c*(b*c - a*d))/(a^3*x) + (b*c - a*d)^2/(a^3*(a + b*x)) + ((b*c - a*d)*(3*b*c - a*d)*Log[x])/a^4 - ((b*c - a*d)*(3*b*c - a*d)*Log[a + b*x])/a^4}
{(c + d*x)^2/(x^4*(a + b*x)^2), x, 2, -(c^2/(3*a^2*x^3)) + (c*(b*c - a*d))/(a^3*x^2) - ((b*c - a*d)*(3*b*c - a*d))/(a^4*x) - (b*(b*c - a*d)^2)/(a^4*(a + b*x)) - (2*b*(b*c - a*d)*(2*b*c - a*d)*Log[x])/a^5 + (2*b*(b*c - a*d)*(2*b*c - a*d)*Log[a + b*x])/a^5}
{(c + d*x)^2/(x^5*(a + b*x)^2), x, 2, -(c^2/(4*a^2*x^4)) + (2*c*(b*c - a*d))/(3*a^3*x^3) - ((b*c - a*d)*(3*b*c - a*d))/(2*a^4*x^2) + (2*b*(b*c - a*d)*(2*b*c - a*d))/(a^5*x) + (b^2*(b*c - a*d)^2)/(a^5*(a + b*x)) + (b^2*(5*b*c - 3*a*d)*(b*c - a*d)*Log[x])/a^6 - (b^2*(5*b*c - 3*a*d)*(b*c - a*d)*Log[a + b*x])/a^6}


{(x^4*(c + d*x)^3)/(a + b*x)^2, x, 2, (3*a^2*(b*c - 2*a*d)*(b*c - a*d)^2*x)/b^7 - (a*(2*b*c - 5*a*d)*(b*c - a*d)^2*x^2)/(2*b^6) + ((b*c - 4*a*d)*(b*c - a*d)^2*x^3)/(3*b^5) + (3*d*(b*c - a*d)^2*x^4)/(4*b^4) + (d^2*(3*b*c - 2*a*d)*x^5)/(5*b^3) + (d^3*x^6)/(6*b^2) - (a^4*(b*c - a*d)^3)/(b^8*(a + b*x)) - (a^3*(4*b*c - 7*a*d)*(b*c - a*d)^2*Log[a + b*x])/b^8}
{(x^3*(c + d*x)^3)/(a + b*x)^2, x, 2, -((a*(2*b*c - 5*a*d)*(b*c - a*d)^2*x)/b^6) + ((b*c - 4*a*d)*(b*c - a*d)^2*x^2)/(2*b^5) + (d*(b*c - a*d)^2*x^3)/b^4 + (d^2*(3*b*c - 2*a*d)*x^4)/(4*b^3) + (d^3*x^5)/(5*b^2) + (a^3*(b*c - a*d)^3)/(b^7*(a + b*x)) + (3*a^2*(b*c - 2*a*d)*(b*c - a*d)^2*Log[a + b*x])/b^7}
{(x^2*(c + d*x)^3)/(a + b*x)^2, x, 2, ((b*c - 4*a*d)*(b*c - a*d)^2*x)/b^5 + (3*d*(b*c - a*d)^2*x^2)/(2*b^4) + (d^2*(3*b*c - 2*a*d)*x^3)/(3*b^3) + (d^3*x^4)/(4*b^2) - (a^2*(b*c - a*d)^3)/(b^6*(a + b*x)) - (a*(2*b*c - 5*a*d)*(b*c - a*d)^2*Log[a + b*x])/b^6}
{(x*(c + d*x)^3)/(a + b*x)^2, x, 2, (3*d*(b*c - a*d)^2*x)/b^4 + (d^2*(3*b*c - 2*a*d)*x^2)/(2*b^3) + (d^3*x^3)/(3*b^2) + (a*(b*c - a*d)^3)/(b^5*(a + b*x)) + ((b*c - 4*a*d)*(b*c - a*d)^2*Log[a + b*x])/b^5}
{(c + d*x)^3/(a + b*x)^2, x, 2, (d^2*(3*b*c - 2*a*d)*x)/b^3 + (d^3*x^2)/(2*b^2) - (b*c - a*d)^3/(b^4*(a + b*x)) + (3*d*(b*c - a*d)^2*Log[a + b*x])/b^4}
{(c + d*x)^3/(x*(a + b*x)^2), x, 2, (d^3*x)/b^2 + (b*c - a*d)^3/(a*b^3*(a + b*x)) + (c^3*Log[x])/a^2 - ((b*c - a*d)^2*(b*c + 2*a*d)*Log[a + b*x])/(a^2*b^3)}
{(c + d*x)^3/(x^2*(a + b*x)^2), x, 2, -(c^3/(a^2*x)) - (b*c - a*d)^3/(a^2*b^2*(a + b*x)) - (c^2*(2*b*c - 3*a*d)*Log[x])/a^3 + ((b*c - a*d)^2*(2*b*c + a*d)*Log[a + b*x])/(a^3*b^2)}
{(c + d*x)^3/(x^3*(a + b*x)^2), x, 2, -c^3/(2*a^2*x^2) + (c^2*(2*b*c - 3*a*d))/(a^3*x) + (b*c - a*d)^3/(a^3*b*(a + b*x)) + (3*c*(b*c - a*d)^2*Log[x])/a^4 - (3*c*(b*c - a*d)^2*Log[a + b*x])/a^4}
{(c + d*x)^3/(x^4*(a + b*x)^2), x, 2, -c^3/(3*a^2*x^3) + (c^2*(2*b*c - 3*a*d))/(2*a^3*x^2) - (3*c*(b*c - a*d)^2)/(a^4*x) - (b*c - a*d)^3/(a^4*(a + b*x)) - ((b*c - a*d)^2*(4*b*c - a*d)*Log[x])/a^5 + ((b*c - a*d)^2*(4*b*c - a*d)*Log[a + b*x])/a^5}
{(c + d*x)^3/(x^5*(a + b*x)^2), x, 2, -c^3/(4*a^2*x^4) + (c^2*(2*b*c - 3*a*d))/(3*a^3*x^3) - (3*c*(b*c - a*d)^2)/(2*a^4*x^2) + ((b*c - a*d)^2*(4*b*c - a*d))/(a^5*x) + (b*(b*c - a*d)^3)/(a^5*(a + b*x)) + (b*(5*b*c - 2*a*d)*(b*c - a*d)^2*Log[x])/a^6 - (b*(5*b*c - 2*a*d)*(b*c - a*d)^2*Log[a + b*x])/a^6}
{(c + d*x)^3/(x^6*(a + b*x)^2), x, 2, -c^3/(5*a^2*x^5) + (c^2*(2*b*c - 3*a*d))/(4*a^3*x^4) - (c*(b*c - a*d)^2)/(a^4*x^3) + ((b*c - a*d)^2*(4*b*c - a*d))/(2*a^5*x^2) - (b*(5*b*c - 2*a*d)*(b*c - a*d)^2)/(a^6*x) - (b^2*(b*c - a*d)^3)/(a^6*(a + b*x)) - (3*b^2*(b*c - a*d)^2*(2*b*c - a*d)*Log[x])/a^7 + (3*b^2*(b*c - a*d)^2*(2*b*c - a*d)*Log[a + b*x])/a^7}


{((2 - 3*x)^3*Sqrt[x])/(1 + x)^2, x, 5, -450*Sqrt[x] + 72*x^(3/2) - (54*x^(5/2))/5 - (125*Sqrt[x])/(1 + x) + 575*ArcTan[Sqrt[x]], -((2689*Sqrt[x])/5) - (1/5)*(62 - 513*x)*Sqrt[x] - (21/5)*(2 - 3*x)^2*Sqrt[x] - ((2 - 3*x)^3*Sqrt[x])/(1 + x) + 575*ArcTan[Sqrt[x]]}


(* ::Subsubsection::Closed:: *)
(*n<0*)


{x^6/((a + b*x)^2*(c + d*x)^2), x, 2, ((3*b^2*c^2 + 4*a*b*c*d + 3*a^2*d^2)*x)/(b^4*d^4) - ((b*c + a*d)*x^2)/(b^3*d^3) + x^3/(3*b^2*d^2) - a^6/(b^5*(b*c - a*d)^2*(a + b*x)) - c^6/(d^5*(b*c - a*d)^2*(c + d*x)) - (2*a^5*(3*b*c - 2*a*d)*Log[a + b*x])/(b^5*(b*c - a*d)^3) - (2*c^5*(2*b*c - 3*a*d)*Log[c + d*x])/(d^5*(b*c - a*d)^3)}
{x^5/((a + b*x)^2*(c + d*x)^2), x, 2, -((2*(b*c + a*d)*x)/(b^3*d^3)) + x^2/(2*b^2*d^2) + a^5/(b^4*(b*c - a*d)^2*(a + b*x)) + c^5/(d^4*(b*c - a*d)^2*(c + d*x)) + (a^4*(5*b*c - 3*a*d)*Log[a + b*x])/(b^4*(b*c - a*d)^3) + (c^4*(3*b*c - 5*a*d)*Log[c + d*x])/(d^4*(b*c - a*d)^3)}
{x^4/((a + b*x)^2*(c + d*x)^2), x, 2, x/(b^2*d^2) - a^4/(b^3*(b*c - a*d)^2*(a + b*x)) - c^4/(d^3*(b*c - a*d)^2*(c + d*x)) - (2*a^3*(2*b*c - a*d)*Log[a + b*x])/(b^3*(b*c - a*d)^3) - (2*c^3*(b*c - 2*a*d)*Log[c + d*x])/(d^3*(b*c - a*d)^3)}
{x^3/((a + b*x)^2*(c + d*x)^2), x, 2, a^3/(b^2*(b*c - a*d)^2*(a + b*x)) + c^3/(d^2*(b*c - a*d)^2*(c + d*x)) + (a^2*(3*b*c - a*d)*Log[a + b*x])/(b^2*(b*c - a*d)^3) + (c^2*(b*c - 3*a*d)*Log[c + d*x])/(d^2*(b*c - a*d)^3)}
{x^2/((a + b*x)^2*(c + d*x)^2), x, 2, -(a^2/(b*(b*c - a*d)^2*(a + b*x))) - c^2/(d*(b*c - a*d)^2*(c + d*x)) - (2*a*c*Log[a + b*x])/(b*c - a*d)^3 + (2*a*c*Log[c + d*x])/(b*c - a*d)^3}
{x/((a + b*x)^2*(c + d*x)^2), x, 2, a/((b*c - a*d)^2*(a + b*x)) + c/((b*c - a*d)^2*(c + d*x)) + ((b*c + a*d)*Log[a + b*x])/(b*c - a*d)^3 - ((b*c + a*d)*Log[c + d*x])/(b*c - a*d)^3}
{1/((a + b*x)^2*(c + d*x)^2), x, 2, -(b/((b*c - a*d)^2*(a + b*x))) - d/((b*c - a*d)^2*(c + d*x)) - (2*b*d*Log[a + b*x])/(b*c - a*d)^3 + (2*b*d*Log[c + d*x])/(b*c - a*d)^3}
{1/(x*(a + b*x)^2*(c + d*x)^2), x, 2, b^2/(a*(b*c - a*d)^2*(a + b*x)) + d^2/(c*(b*c - a*d)^2*(c + d*x)) + Log[x]/(a^2*c^2) - (b^2*(b*c - 3*a*d)*Log[a + b*x])/(a^2*(b*c - a*d)^3) - (d^2*(3*b*c - a*d)*Log[c + d*x])/(c^2*(b*c - a*d)^3)}
{1/(x^2*(a + b*x)^2*(c + d*x)^2), x, 2, -(1/(a^2*c^2*x)) - b^3/(a^2*(b*c - a*d)^2*(a + b*x)) - d^3/(c^2*(b*c - a*d)^2*(c + d*x)) - (2*(b*c + a*d)*Log[x])/(a^3*c^3) + (2*b^3*(b*c - 2*a*d)*Log[a + b*x])/(a^3*(b*c - a*d)^3) + (2*d^3*(2*b*c - a*d)*Log[c + d*x])/(c^3*(b*c - a*d)^3)}
{1/(x^3*(a + b*x)^2*(c + d*x)^2), x, 2, -(1/(2*a^2*c^2*x^2)) + (2*(b*c + a*d))/(a^3*c^3*x) + b^4/(a^3*(b*c - a*d)^2*(a + b*x)) + d^4/(c^3*(b*c - a*d)^2*(c + d*x)) + ((3*b^2*c^2 + 4*a*b*c*d + 3*a^2*d^2)*Log[x])/(a^4*c^4) - (b^4*(3*b*c - 5*a*d)*Log[a + b*x])/(a^4*(b*c - a*d)^3) - (d^4*(5*b*c - 3*a*d)*Log[c + d*x])/(c^4*(b*c - a*d)^3)}


{x^7/((a + b*x)^2*(c + d*x)^3), x, 2, (3*(2*b^2*c^2 + 2*a*b*c*d + a^2*d^2)*x)/(b^4*d^5) - ((3*b*c + 2*a*d)*x^2)/(2*b^3*d^4) + x^3/(3*b^2*d^3) + a^7/(b^5*(b*c - a*d)^3*(a + b*x)) + c^7/(2*d^6*(b*c - a*d)^2*(c + d*x)^2) - (c^6*(5*b*c - 7*a*d))/(d^6*(b*c - a*d)^3*(c + d*x)) + (a^6*(7*b*c - 4*a*d)*Log[a + b*x])/(b^5*(b*c - a*d)^4) - (c^5*(10*b^2*c^2 - 28*a*b*c*d + 21*a^2*d^2)*Log[c + d*x])/(d^6*(b*c - a*d)^4)}
{x^6/((a + b*x)^2*(c + d*x)^3), x, 2, -(((3*b*c + 2*a*d)*x)/(b^3*d^4)) + x^2/(2*b^2*d^3) - a^6/(b^4*(b*c - a*d)^3*(a + b*x)) - c^6/(2*d^5*(b*c - a*d)^2*(c + d*x)^2) + (2*c^5*(2*b*c - 3*a*d))/(d^5*(b*c - a*d)^3*(c + d*x)) - (3*a^5*(2*b*c - a*d)*Log[a + b*x])/(b^4*(b*c - a*d)^4) + (3*c^4*(2*b^2*c^2 - 6*a*b*c*d + 5*a^2*d^2)*Log[c + d*x])/(d^5*(b*c - a*d)^4)}
{x^5/((a + b*x)^2*(c + d*x)^3), x, 2, x/(b^2*d^3) + a^5/(b^3*(b*c - a*d)^3*(a + b*x)) + c^5/(2*d^4*(b*c - a*d)^2*(c + d*x)^2) - (c^4*(3*b*c - 5*a*d))/(d^4*(b*c - a*d)^3*(c + d*x)) + (a^4*(5*b*c - 2*a*d)*Log[a + b*x])/(b^3*(b*c - a*d)^4) - (c^3*(3*b^2*c^2 - 10*a*b*c*d + 10*a^2*d^2)*Log[c + d*x])/(d^4*(b*c - a*d)^4)}
{x^4/((a + b*x)^2*(c + d*x)^3), x, 2, -(a^4/(b^2*(b*c - a*d)^3*(a + b*x))) - c^4/(2*d^3*(b*c - a*d)^2*(c + d*x)^2) + (2*c^3*(b*c - 2*a*d))/(d^3*(b*c - a*d)^3*(c + d*x)) - (a^3*(4*b*c - a*d)*Log[a + b*x])/(b^2*(b*c - a*d)^4) + (c^2*(b^2*c^2 - 4*a*b*c*d + 6*a^2*d^2)*Log[c + d*x])/(d^3*(b*c - a*d)^4)}
{x^3/((a + b*x)^2*(c + d*x)^3), x, 2, a^3/(b*(b*c - a*d)^3*(a + b*x)) + c^3/(2*d^2*(b*c - a*d)^2*(c + d*x)^2) - (c^2*(b*c - 3*a*d))/(d^2*(b*c - a*d)^3*(c + d*x)) + (3*a^2*c*Log[a + b*x])/(b*c - a*d)^4 - (3*a^2*c*Log[c + d*x])/(b*c - a*d)^4}
{x^2/((a + b*x)^2*(c + d*x)^3), x, 2, -(a^2/((b*c - a*d)^3*(a + b*x))) - c^2/(2*d*(b*c - a*d)^2*(c + d*x)^2) - (2*a*c)/((b*c - a*d)^3*(c + d*x)) - (a*(2*b*c + a*d)*Log[a + b*x])/(b*c - a*d)^4 + (a*(2*b*c + a*d)*Log[c + d*x])/(b*c - a*d)^4}
{x/((a + b*x)^2*(c + d*x)^3), x, 2, (a*b)/((b*c - a*d)^3*(a + b*x)) + c/(2*(b*c - a*d)^2*(c + d*x)^2) + (b*c + a*d)/((b*c - a*d)^3*(c + d*x)) + (b*(b*c + 2*a*d)*Log[a + b*x])/(b*c - a*d)^4 - (b*(b*c + 2*a*d)*Log[c + d*x])/(b*c - a*d)^4}
{1/((a + b*x)^2*(c + d*x)^3), x, 2, -(b^2/((b*c - a*d)^3*(a + b*x))) - d/(2*(b*c - a*d)^2*(c + d*x)^2) - (2*b*d)/((b*c - a*d)^3*(c + d*x)) - (3*b^2*d*Log[a + b*x])/(b*c - a*d)^4 + (3*b^2*d*Log[c + d*x])/(b*c - a*d)^4}
{1/(x*(a + b*x)^2*(c + d*x)^3), x, 2, b^3/(a*(b*c - a*d)^3*(a + b*x)) + d^2/(2*c*(b*c - a*d)^2*(c + d*x)^2) + (d^2*(3*b*c - a*d))/(c^2*(b*c - a*d)^3*(c + d*x)) + Log[x]/(a^2*c^3) - (b^3*(b*c - 4*a*d)*Log[a + b*x])/(a^2*(b*c - a*d)^4) - (d^2*(6*b^2*c^2 - 4*a*b*c*d + a^2*d^2)*Log[c + d*x])/(c^3*(b*c - a*d)^4)}
{1/(x^2*(a + b*x)^2*(c + d*x)^3), x, 2, -(1/(a^2*c^3*x)) - b^4/(a^2*(b*c - a*d)^3*(a + b*x)) - d^3/(2*c^2*(b*c - a*d)^2*(c + d*x)^2) - (2*d^3*(2*b*c - a*d))/(c^3*(b*c - a*d)^3*(c + d*x)) - ((2*b*c + 3*a*d)*Log[x])/(a^3*c^4) + (b^4*(2*b*c - 5*a*d)*Log[a + b*x])/(a^3*(b*c - a*d)^4) + (d^3*(10*b^2*c^2 - 10*a*b*c*d + 3*a^2*d^2)*Log[c + d*x])/(c^4*(b*c - a*d)^4)}
{1/(x^3*(a + b*x)^2*(c + d*x)^3), x, 2, -(1/(2*a^2*c^3*x^2)) + (2*b*c + 3*a*d)/(a^3*c^4*x) + b^5/(a^3*(b*c - a*d)^3*(a + b*x)) + d^4/(2*c^3*(b*c - a*d)^2*(c + d*x)^2) + (d^4*(5*b*c - 3*a*d))/(c^4*(b*c - a*d)^3*(c + d*x)) + (3*(b^2*c^2 + 2*a*b*c*d + 2*a^2*d^2)*Log[x])/(a^4*c^5) - (3*b^5*(b*c - 2*a*d)*Log[a + b*x])/(a^4*(b*c - a*d)^4) - (3*d^4*(5*b^2*c^2 - 6*a*b*c*d + 2*a^2*d^2)*Log[c + d*x])/(c^5*(b*c - a*d)^4)}


{x^2/((-1 + x)^2*(1 + x)^2), x, 3, 1/(4*(1 - x)) - 1/(4*(1 + x)) - ArcTanh[x]/2}


(* Following integrands are equal: *)
{(b^2*x^m)/(b + a*x^2)^2, x, 3, (b*x^(1 + m))/(2*(b + a*x^2)) + ((1 - m)*x^(1 + m)*Hypergeometric2F1[1, (1 + m)/2, (3 + m)/2, -((a*x^2)/b)])/(2*(1 + m))}
{x^m/((1 - (Sqrt[a]*x)/Sqrt[-b])^2*(1 + (Sqrt[a]*x)/Sqrt[-b])^2), x, 8, (b*x^(1 + m))/(2*(b + a*x^2)) + ((1 - m)*x^(1 + m)*Hypergeometric2F1[1, (1 + m)/2, (3 + m)/2, -((a*x^2)/b)])/(2*(1 + m)), x^(1 + m)/(4*(1 - (Sqrt[a]*x)/Sqrt[-b])) + x^(1 + m)/(4*(1 + (Sqrt[a]*x)/Sqrt[-b])) + (x^(1 + m)*Hypergeometric2F1[1, 1 + m, 2 + m, -((Sqrt[a]*x)/Sqrt[-b])])/(4*(1 + m)) - (m*x^(1 + m)*Hypergeometric2F1[1, 1 + m, 2 + m, -((Sqrt[a]*x)/Sqrt[-b])])/(4*(1 + m)) + (x^(1 + m)*Hypergeometric2F1[1, 1 + m, 2 + m, (Sqrt[a]*x)/Sqrt[-b]])/(4*(1 + m)) - (m*x^(1 + m)*Hypergeometric2F1[1, 1 + m, 2 + m, (Sqrt[a]*x)/Sqrt[-b]])/(4*(1 + m))}


(* ::Subsection::Closed:: *)
(*Integrands of the form x^m (c+d x)^n / (a+b x)^3*)


(* ::Subsubsection::Closed:: *)
(*n>0*)


{(x^3*(c + d*x)^3)/(a + b*x)^3, x, 2, ((b*c - a*d)*(b^2*c^2 - 8*a*b*c*d + 10*a^2*d^2)*x)/b^6 + (3*d*(b*c - 2*a*d)*(b*c - a*d)*x^2)/(2*b^5) + (d^2*(b*c - a*d)*x^3)/b^4 + (d^3*x^4)/(4*b^3) + (a^3*(b*c - a*d)^3)/(2*b^7*(a + b*x)^2) - (3*a^2*(b*c - 2*a*d)*(b*c - a*d)^2)/(b^7*(a + b*x)) - (3*a*(b*c - a*d)*(b^2*c^2 - 5*a*b*c*d + 5*a^2*d^2)*Log[a + b*x])/b^7}
{(x^2*(c + d*x)^3)/(a + b*x)^3, x, 2, (3*d*(b*c - 2*a*d)*(b*c - a*d)*x)/b^5 + (3*d^2*(b*c - a*d)*x^2)/(2*b^4) + (d^3*x^3)/(3*b^3) - (a^2*(b*c - a*d)^3)/(2*b^6*(a + b*x)^2) + (a*(2*b*c - 5*a*d)*(b*c - a*d)^2)/(b^6*(a + b*x)) + ((b*c - a*d)*(b^2*c^2 - 8*a*b*c*d + 10*a^2*d^2)*Log[a + b*x])/b^6}
{(x*(c + d*x)^3)/(a + b*x)^3, x, 2, (3*d^2*(b*c - a*d)*x)/b^4 + (d^3*x^2)/(2*b^3) + (a*(b*c - a*d)^3)/(2*b^5*(a + b*x)^2) - ((b*c - 4*a*d)*(b*c - a*d)^2)/(b^5*(a + b*x)) + (3*d*(b*c - 2*a*d)*(b*c - a*d)*Log[a + b*x])/b^5}
{(c + d*x)^3/(a + b*x)^3, x, 2, (d^3*x)/b^3 - (b*c - a*d)^3/(2*b^4*(a + b*x)^2) - (3*d*(b*c - a*d)^2)/(b^4*(a + b*x)) + (3*d^2*(b*c - a*d)*Log[a + b*x])/b^4}
{(c + d*x)^3/(x*(a + b*x)^3), x, 2, (b*c - a*d)^3/(2*a*b^3*(a + b*x)^2) + ((b*c - a*d)^2*(b*c + 2*a*d))/(a^2*b^3*(a + b*x)) + (c^3*Log[x])/a^3 - (c^3/a^3 - d^3/b^3)*Log[a + b*x]}
{(c + d*x)^3/(x^2*(a + b*x)^3), x, 2, -(c^3/(a^3*x)) - (b*c - a*d)^3/(2*a^2*b^2*(a + b*x)^2) - ((b*c - a*d)^2*(2*b*c + a*d))/(a^3*b^2*(a + b*x)) - (3*c^2*(b*c - a*d)*Log[x])/a^4 + (3*c^2*(b*c - a*d)*Log[a + b*x])/a^4}
{(c + d*x)^3/(x^3*(a + b*x)^3), x, 2, -(c^3/(2*a^3*x^2)) + (3*c^2*(b*c - a*d))/(a^4*x) + (b*c - a*d)^3/(2*a^3*b*(a + b*x)^2) + (3*c*(b*c - a*d)^2)/(a^4*(a + b*x)) + (3*c*(b*c - a*d)*(2*b*c - a*d)*Log[x])/a^5 - (3*c*(b*c - a*d)*(2*b*c - a*d)*Log[a + b*x])/a^5}
{(c + d*x)^3/(x^4*(a + b*x)^3), x, 2, -(c^3/(3*a^3*x^3)) + (3*c^2*(b*c - a*d))/(2*a^4*x^2) - (3*c*(b*c - a*d)*(2*b*c - a*d))/(a^5*x) - (b*c - a*d)^3/(2*a^4*(a + b*x)^2) - ((b*c - a*d)^2*(4*b*c - a*d))/(a^5*(a + b*x)) - ((b*c - a*d)*(10*b^2*c^2 - 8*a*b*c*d + a^2*d^2)*Log[x])/a^6 + ((b*c - a*d)*(10*b^2*c^2 - 8*a*b*c*d + a^2*d^2)*Log[a + b*x])/a^6}


(* ::Subsubsection::Closed:: *)
(*n<0*)


{x^7/((a + b*x)^3*(c + d*x)^3), x, 2, -((3*(b*c + a*d)*x)/(b^4*d^4)) + x^2/(2*b^3*d^3) + a^7/(2*b^5*(b*c - a*d)^3*(a + b*x)^2) - (a^6*(7*b*c - 4*a*d))/(b^5*(b*c - a*d)^4*(a + b*x)) - c^7/(2*d^5*(b*c - a*d)^3*(c + d*x)^2) + (c^6*(4*b*c - 7*a*d))/(d^5*(b*c - a*d)^4*(c + d*x)) - (3*a^5*(7*b^2*c^2 - 7*a*b*c*d + 2*a^2*d^2)*Log[a + b*x])/(b^5*(b*c - a*d)^5) + (3*c^5*(2*b^2*c^2 - 7*a*b*c*d + 7*a^2*d^2)*Log[c + d*x])/(d^5*(b*c - a*d)^5)}
{x^6/((a + b*x)^3*(c + d*x)^3), x, 2, x/(b^3*d^3) - a^6/(2*b^4*(b*c - a*d)^3*(a + b*x)^2) + (3*a^5*(2*b*c - a*d))/(b^4*(b*c - a*d)^4*(a + b*x)) + c^6/(2*d^4*(b*c - a*d)^3*(c + d*x)^2) - (3*c^5*(b*c - 2*a*d))/(d^4*(b*c - a*d)^4*(c + d*x)) + (3*a^4*(5*b^2*c^2 - 4*a*b*c*d + a^2*d^2)*Log[a + b*x])/(b^4*(b*c - a*d)^5) - (3*c^4*(b^2*c^2 - 4*a*b*c*d + 5*a^2*d^2)*Log[c + d*x])/(d^4*(b*c - a*d)^5)}
{x^5/((a + b*x)^3*(c + d*x)^3), x, 2, a^5/(2*b^3*(b*c - a*d)^3*(a + b*x)^2) - (a^4*(5*b*c - 2*a*d))/(b^3*(b*c - a*d)^4*(a + b*x)) - c^5/(2*d^3*(b*c - a*d)^3*(c + d*x)^2) + (c^4*(2*b*c - 5*a*d))/(d^3*(b*c - a*d)^4*(c + d*x)) - (a^3*(10*b^2*c^2 - 5*a*b*c*d + a^2*d^2)*Log[a + b*x])/(b^3*(b*c - a*d)^5) + (c^3*(b^2*c^2 - 5*a*b*c*d + 10*a^2*d^2)*Log[c + d*x])/(d^3*(b*c - a*d)^5)}
{x^4/((a + b*x)^3*(c + d*x)^3), x, 2, -(a^4/(2*b^2*(b*c - a*d)^3*(a + b*x)^2)) + (a^3*(4*b*c - a*d))/(b^2*(b*c - a*d)^4*(a + b*x)) + c^4/(2*d^2*(b*c - a*d)^3*(c + d*x)^2) - (c^3*(b*c - 4*a*d))/(d^2*(b*c - a*d)^4*(c + d*x)) + (6*a^2*c^2*Log[a + b*x])/(b*c - a*d)^5 - (6*a^2*c^2*Log[c + d*x])/(b*c - a*d)^5}
{x^3/((a + b*x)^3*(c + d*x)^3), x, 2, a^3/(2*b*(b*c - a*d)^3*(a + b*x)^2) - (3*a^2*c)/((b*c - a*d)^4*(a + b*x)) - c^3/(2*d*(b*c - a*d)^3*(c + d*x)^2) - (3*a*c^2)/((b*c - a*d)^4*(c + d*x)) - (3*a*c*(b*c + a*d)*Log[a + b*x])/(b*c - a*d)^5 + (3*a*c*(b*c + a*d)*Log[c + d*x])/(b*c - a*d)^5}
{x^2/((a + b*x)^3*(c + d*x)^3), x, 2, -(a^2/(2*(b*c - a*d)^3*(a + b*x)^2)) + (a*(2*b*c + a*d))/((b*c - a*d)^4*(a + b*x)) + c^2/(2*(b*c - a*d)^3*(c + d*x)^2) + (c*(b*c + 2*a*d))/((b*c - a*d)^4*(c + d*x)) + ((b^2*c^2 + 4*a*b*c*d + a^2*d^2)*Log[a + b*x])/(b*c - a*d)^5 - ((b^2*c^2 + 4*a*b*c*d + a^2*d^2)*Log[c + d*x])/(b*c - a*d)^5}
{x/((a + b*x)^3*(c + d*x)^3), x, 2, (a*b)/(2*(b*c - a*d)^3*(a + b*x)^2) - (b*(b*c + 2*a*d))/((b*c - a*d)^4*(a + b*x)) - (c*d)/(2*(b*c - a*d)^3*(c + d*x)^2) - (d*(2*b*c + a*d))/((b*c - a*d)^4*(c + d*x)) - (3*b*d*(b*c + a*d)*Log[a + b*x])/(b*c - a*d)^5 + (3*b*d*(b*c + a*d)*Log[c + d*x])/(b*c - a*d)^5}
{1/((a + b*x)^3*(c + d*x)^3), x, 2, -(b^2/(2*(b*c - a*d)^3*(a + b*x)^2)) + (3*b^2*d)/((b*c - a*d)^4*(a + b*x)) + d^2/(2*(b*c - a*d)^3*(c + d*x)^2) + (3*b*d^2)/((b*c - a*d)^4*(c + d*x)) + (6*b^2*d^2*Log[a + b*x])/(b*c - a*d)^5 - (6*b^2*d^2*Log[c + d*x])/(b*c - a*d)^5}
{1/(x*(a + b*x)^3*(c + d*x)^3), x, 2, b^3/(2*a*(b*c - a*d)^3*(a + b*x)^2) + (b^3*(b*c - 4*a*d))/(a^2*(b*c - a*d)^4*(a + b*x)) - d^3/(2*c*(b*c - a*d)^3*(c + d*x)^2) - (d^3*(4*b*c - a*d))/(c^2*(b*c - a*d)^4*(c + d*x)) + Log[x]/(a^3*c^3) - (b^3*(b^2*c^2 - 5*a*b*c*d + 10*a^2*d^2)*Log[a + b*x])/(a^3*(b*c - a*d)^5) + (d^3*(10*b^2*c^2 - 5*a*b*c*d + a^2*d^2)*Log[c + d*x])/(c^3*(b*c - a*d)^5)}
{1/(x^2*(a + b*x)^3*(c + d*x)^3), x, 2, -(1/(a^3*c^3*x)) - b^4/(2*a^2*(b*c - a*d)^3*(a + b*x)^2) - (b^4*(2*b*c - 5*a*d))/(a^3*(b*c - a*d)^4*(a + b*x)) + d^4/(2*c^2*(b*c - a*d)^3*(c + d*x)^2) + (d^4*(5*b*c - 2*a*d))/(c^3*(b*c - a*d)^4*(c + d*x)) - (3*(b*c + a*d)*Log[x])/(a^4*c^4) + (3*b^4*(b^2*c^2 - 4*a*b*c*d + 5*a^2*d^2)*Log[a + b*x])/(a^4*(b*c - a*d)^5) - (3*d^4*(5*b^2*c^2 - 4*a*b*c*d + a^2*d^2)*Log[c + d*x])/(c^4*(b*c - a*d)^5)}


(* ::Section::Closed:: *)
(*Integrands of the form x^m (a+b x)^n (c+d x)^(p/2)*)


{(a + b*x)^2/(x^2*Sqrt[c + d*x]), x, 3, (2*b^2*Sqrt[c + d*x])/d - (a^2*Sqrt[c + d*x])/(c*x) - (a*(4*b*c - a*d)*ArcTanh[Sqrt[c + d*x]/Sqrt[c]])/c^(3/2)}


{(c + d*x)^(3/2)/(x^2*(a + b*x)^2), x, 5, -((2*(b*c - a*d)*Sqrt[c + d*x])/(a^2*(a + b*x))) - (c + d*x)^(3/2)/(a*x*(a + b*x)) + (Sqrt[c]*(4*b*c - 3*a*d)*ArcTanh[Sqrt[c + d*x]/Sqrt[c]])/a^3 - (Sqrt[b*c - a*d]*(4*b*c - a*d)*ArcTanh[(Sqrt[b]*Sqrt[c + d*x])/Sqrt[b*c - a*d]])/(a^3*Sqrt[b])}
{(c + d*x)^(1/2)/(x^2*(a + b*x)^2), x, 5, -((2*b*Sqrt[c + d*x])/(a^2*(a + b*x))) - Sqrt[c + d*x]/(a*x*(a + b*x)) + ((4*b*c - a*d)*ArcTanh[Sqrt[c + d*x]/Sqrt[c]])/(a^3*Sqrt[c]) - (Sqrt[b]*(4*b*c - 3*a*d)*ArcTanh[(Sqrt[b]*Sqrt[c + d*x])/Sqrt[b*c - a*d]])/(a^3*Sqrt[b*c - a*d])}
{1/(x^2*(a + b*x)^2*(c + d*x)^(1/2)), x, 5, -((b*(2*b*c - a*d)*Sqrt[c + d*x])/(a^2*c*(b*c - a*d)*(a + b*x))) - Sqrt[c + d*x]/(a*c*x*(a + b*x)) + ((4*b*c + a*d)*ArcTanh[Sqrt[c + d*x]/Sqrt[c]])/(a^3*c^(3/2)) - (b^(3/2)*(4*b*c - 5*a*d)*ArcTanh[(Sqrt[b]*Sqrt[c + d*x])/Sqrt[b*c - a*d]])/(a^3*(b*c - a*d)^(3/2))}
{1/(x^2*(a + b*x)^2*(c + d*x)^(3/2)), x, 6, -((d*(2*b^2*c^2 - 2*a*b*c*d + 3*a^2*d^2))/(a^2*c^2*(b*c - a*d)^2*Sqrt[c + d*x])) - (b*(2*b*c - a*d))/(a^2*c*(b*c - a*d)*(a + b*x)*Sqrt[c + d*x]) - 1/(a*c*x*(a + b*x)*Sqrt[c + d*x]) + ((4*b*c + 3*a*d)*ArcTanh[Sqrt[c + d*x]/Sqrt[c]])/(a^3*c^(5/2)) - (b^(5/2)*(4*b*c - 7*a*d)*ArcTanh[(Sqrt[b]*Sqrt[c + d*x])/Sqrt[b*c - a*d]])/(a^3*(b*c - a*d)^(5/2))}
{1/(x^2*(a + b*x)^2*(c + d*x)^(5/2)), x, 7, -((d*(6*b^2*c^2 - 6*a*b*c*d + 5*a^2*d^2))/(3*a^2*c^2*(b*c - a*d)^2*(c + d*x)^(3/2))) - (b*(2*b*c - a*d))/(a^2*c*(b*c - a*d)*(a + b*x)*(c + d*x)^(3/2)) - 1/(a*c*x*(a + b*x)*(c + d*x)^(3/2)) - (d*(2*b*c - a*d)*(b^2*c^2 - a*b*c*d + 5*a^2*d^2))/(a^2*c^3*(b*c - a*d)^3*Sqrt[c + d*x]) + ((4*b*c + 5*a*d)*ArcTanh[Sqrt[c + d*x]/Sqrt[c]])/(a^3*c^(7/2)) - (b^(7/2)*(4*b*c - 9*a*d)*ArcTanh[(Sqrt[b]*Sqrt[c + d*x])/Sqrt[b*c - a*d]])/(a^3*(b*c - a*d)^(7/2))}


(* ::Subsection::Closed:: *)
(*Integrands of the form x^m (a+b x)^n (c+d x)^(5/2)*)


(* ::Subsubsection:: *)
(*n>0*)


(* ::Subsubsection::Closed:: *)
(*n<0*)


{x^3*(c + d*x)^(5/2)/(a + b*x), x, 7, -((2*a^3*(b*c - a*d)^2*Sqrt[c + d*x])/b^6) - (2*a^3*(b*c - a*d)*(c + d*x)^(3/2))/(3*b^5) + (2*(40*b^3*c^3 + 110*a*b^2*c^2*d + 495*a^2*b*c*d^2 - 693*a^3*d^3)*(c + d*x)^(5/2))/(3465*b^4*d^3) - (2*(20*b^2*c^2 + 55*a*b*c*d - 99*a^2*d^2)*x*(c + d*x)^(5/2))/(693*b^3*d^2) + (2*(5*b*c - 11*a*d)*x^2*(c + d*x)^(5/2))/(99*b^2*d) + (2*x^3*(c + d*x)^(5/2))/(11*b) + (2*a^3*(b*c - a*d)^(5/2)*ArcTanh[(Sqrt[b]*Sqrt[c + d*x])/Sqrt[b*c - a*d]])/b^(13/2)}
{x^2*(c + d*x)^(5/2)/(a + b*x), x, 6, (2*a^2*(b*c - a*d)^2*Sqrt[c + d*x])/b^5 + (2*a^2*(b*c - a*d)*(c + d*x)^(3/2))/(3*b^4) + (2*a^2*(c + d*x)^(5/2))/(5*b^3) - (2*(2*b*c + 9*a*d)*(c + d*x)^(7/2))/(63*b^2*d^2) + (2*x*(c + d*x)^(7/2))/(9*b*d) - (2*a^2*(b*c - a*d)^(5/2)*ArcTanh[(Sqrt[b]*Sqrt[c + d*x])/Sqrt[b*c - a*d]])/b^(11/2)}
{x^1*(c + d*x)^(5/2)/(a + b*x), x, 5, -((2*a*(b*c - a*d)^2*Sqrt[c + d*x])/b^4) - (2*a*(b*c - a*d)*(c + d*x)^(3/2))/(3*b^3) - (2*a*(c + d*x)^(5/2))/(5*b^2) + (2*(c + d*x)^(7/2))/(7*b*d) + (2*a*(b*c - a*d)^(5/2)*ArcTanh[(Sqrt[b]*Sqrt[c + d*x])/Sqrt[b*c - a*d]])/b^(9/2)}
{x^0*(c + d*x)^(5/2)/(a + b*x), x, 4, (2*(b*c - a*d)^2*Sqrt[c + d*x])/b^3 + (2*(b*c - a*d)*(c + d*x)^(3/2))/(3*b^2) + (2*(c + d*x)^(5/2))/(5*b) - (2*(b*c - a*d)^(5/2)*ArcTanh[(Sqrt[b]*Sqrt[c + d*x])/Sqrt[b*c - a*d]])/b^(7/2)}
{(c + d*x)^(5/2)/(x^1*(a + b*x)), x, 5, (2*d*(2*b*c - a*d)*Sqrt[c + d*x])/b^2 + (2*d*(c + d*x)^(3/2))/(3*b) - (2*c^(5/2)*ArcTanh[Sqrt[c + d*x]/Sqrt[c]])/a + (2*(b*c - a*d)^(5/2)*ArcTanh[(Sqrt[b]*Sqrt[c + d*x])/Sqrt[b*c - a*d]])/(a*b^(5/2))}
{(c + d*x)^(5/2)/(x^2*(a + b*x)), x, 6, (d*(b*c + 2*a*d)*Sqrt[c + d*x])/(a*b) + (d*(c + d*x)^(3/2))/a - (c + d*x)^(5/2)/(a*x) + (c^(3/2)*(2*b*c - 5*a*d)*ArcTanh[Sqrt[c + d*x]/Sqrt[c]])/a^2 - (2*(b*c - a*d)^(5/2)*ArcTanh[(Sqrt[b]*Sqrt[c + d*x])/Sqrt[b*c - a*d]])/(a^2*b^(3/2))}
{(c + d*x)^(5/2)/(x^3*(a + b*x)), x, 6, -((d*(4*b*c - 7*a*d)*Sqrt[c + d*x])/(4*a^2)) + ((4*b*c - 5*a*d)*(c + d*x)^(3/2))/(4*a^2*x) - (c + d*x)^(5/2)/(2*a*x^2) - (Sqrt[c]*(8*b^2*c^2 - 20*a*b*c*d + 15*a^2*d^2)*ArcTanh[Sqrt[c + d*x]/Sqrt[c]])/(4*a^3) + (2*(b*c - a*d)^(5/2)*ArcTanh[(Sqrt[b]*Sqrt[c + d*x])/Sqrt[b*c - a*d]])/(a^3*Sqrt[b])}
{(c + d*x)^(5/2)/(x^4*(a + b*x)), x, 6, -(((4*b*c - 5*a*d)*(2*b*c - a*d)*Sqrt[c + d*x])/(8*a^3*x)) + ((6*b*c - 5*a*d)*(c + d*x)^(3/2))/(12*a^2*x^2) - (c + d*x)^(5/2)/(3*a*x^3) + ((16*b^3*c^3 - 40*a*b^2*c^2*d + 30*a^2*b*c*d^2 - 5*a^3*d^3)*ArcTanh[Sqrt[c + d*x]/Sqrt[c]])/(8*a^4*Sqrt[c]) - (2*Sqrt[b]*(b*c - a*d)^(5/2)*ArcTanh[(Sqrt[b]*Sqrt[c + d*x])/Sqrt[b*c - a*d]])/a^4}


{x^3*(c + d*x)^(5/2)/(a + b*x)^2, x, 7, (a^2*(6*b*c - 11*a*d)*(b*c - a*d)*Sqrt[c + d*x])/b^6 + (a^2*(6*b*c - 11*a*d)*(c + d*x)^(3/2))/(3*b^5) - ((20*b^2*c^2 + 180*a*b*c*d - 693*a^2*d^2)*(c + d*x)^(5/2))/(315*b^4*d^2) + ((10*b*c - 99*a*d)*x*(c + d*x)^(5/2))/(63*b^3*d) + (11*x^2*(c + d*x)^(5/2))/(9*b^2) - (x^3*(c + d*x)^(5/2))/(b*(a + b*x)) - (a^2*(6*b*c - 11*a*d)*(b*c - a*d)^(3/2)*ArcTanh[(Sqrt[b]*Sqrt[c + d*x])/Sqrt[b*c - a*d]])/b^(13/2)}
{x^2*(c + d*x)^(5/2)/(a + b*x)^2, x, 6, -((a*(4*b*c - 9*a*d)*(b*c - a*d)*Sqrt[c + d*x])/b^5) - (a*(4*b*c - 9*a*d)*(c + d*x)^(3/2))/(3*b^4) - (a*(4*b*c - 9*a*d)*(c + d*x)^(5/2))/(5*b^3*(b*c - a*d)) + (2*(c + d*x)^(7/2))/(7*b^2*d) - (a^2*(c + d*x)^(7/2))/(b^2*(b*c - a*d)*(a + b*x)) + (a*(4*b*c - 9*a*d)*(b*c - a*d)^(3/2)*ArcTanh[(Sqrt[b]*Sqrt[c + d*x])/Sqrt[b*c - a*d]])/b^(11/2)}
{x^1*(c + d*x)^(5/2)/(a + b*x)^2, x, 5, ((2*b*c - 7*a*d)*(b*c - a*d)*Sqrt[c + d*x])/b^4 + ((2*b*c - 7*a*d)*(c + d*x)^(3/2))/(3*b^3) + ((2*b*c - 7*a*d)*(c + d*x)^(5/2))/(5*b^2*(b*c - a*d)) + (a*(c + d*x)^(7/2))/(b*(b*c - a*d)*(a + b*x)) - ((2*b*c - 7*a*d)*(b*c - a*d)^(3/2)*ArcTanh[(Sqrt[b]*Sqrt[c + d*x])/Sqrt[b*c - a*d]])/b^(9/2)}
{x^0*(c + d*x)^(5/2)/(a + b*x)^2, x, 4, (5*d*(b*c - a*d)*Sqrt[c + d*x])/b^3 + (5*d*(c + d*x)^(3/2))/(3*b^2) - (c + d*x)^(5/2)/(b*(a + b*x)) - (5*d*(b*c - a*d)^(3/2)*ArcTanh[(Sqrt[b]*Sqrt[c + d*x])/Sqrt[b*c - a*d]])/b^(7/2)}
{(c + d*x)^(5/2)/(x^1*(a + b*x)^2), x, 6, -((d*(b*c - 3*a*d)*Sqrt[c + d*x])/(a*b^2)) - (d*(c + d*x)^(3/2))/(a*b) + (c + d*x)^(5/2)/(a*(a + b*x)) - (2*c^(5/2)*ArcTanh[Sqrt[c + d*x]/Sqrt[c]])/a^2 + ((b*c - a*d)^(3/2)*(2*b*c + 3*a*d)*ArcTanh[(Sqrt[b]*Sqrt[c + d*x])/Sqrt[b*c - a*d]])/(a^2*b^(5/2))}
{(c + d*x)^(5/2)/(x^2*(a + b*x)^2), x, 6, -((c^2*Sqrt[c + d*x])/(a^2*x)) - ((b*c - a*d)^2*Sqrt[c + d*x])/(a^2*b*(a + b*x)) + (c^(3/2)*(4*b*c - 5*a*d)*ArcTanh[Sqrt[c + d*x]/Sqrt[c]])/a^3 - ((b*c - a*d)^(3/2)*(4*b*c + a*d)*ArcTanh[(Sqrt[b]*Sqrt[c + d*x])/Sqrt[b*c - a*d]])/(a^3*b^(3/2)), (d*(2*b*c - a*d)*Sqrt[c + d*x])/(a^2*b) - (2*(b*c - a*d)*(c + d*x)^(3/2))/(a^2*(a + b*x)) - (c + d*x)^(5/2)/(a*x*(a + b*x)) + (c^(3/2)*(4*b*c - 5*a*d)*ArcTanh[Sqrt[c + d*x]/Sqrt[c]])/a^3 - ((b*c - a*d)^(3/2)*(4*b*c + a*d)*ArcTanh[(Sqrt[b]*Sqrt[c + d*x])/Sqrt[b*c - a*d]])/(a^3*b^(3/2))}
{(c + d*x)^(5/2)/(x^3*(a + b*x)^2), x, 6, ((12*b*c - 11*a*d)*(b*c - a*d)*Sqrt[c + d*x])/(4*a^3*(a + b*x)) + ((6*b*c - 5*a*d)*(c + d*x)^(3/2))/(4*a^2*x*(a + b*x)) - (c + d*x)^(5/2)/(2*a*x^2*(a + b*x)) - (Sqrt[c]*(24*b^2*c^2 - 40*a*b*c*d + 15*a^2*d^2)*ArcTanh[Sqrt[c + d*x]/Sqrt[c]])/(4*a^4) + ((b*c - a*d)^(3/2)*(6*b*c - a*d)*ArcTanh[(Sqrt[b]*Sqrt[c + d*x])/Sqrt[b*c - a*d]])/(a^4*Sqrt[b])}
{(c + d*x)^(5/2)/(x^4*(a + b*x)^2), x, 7, -((b*(32*b^2*c^2 - 52*a*b*c*d + 19*a^2*d^2)*Sqrt[c + d*x])/(8*a^4*(a + b*x))) - ((16*b^2*c^2 - 22*a*b*c*d + 5*a^2*d^2)*Sqrt[c + d*x])/(8*a^3*x*(a + b*x)) + ((8*b*c - 5*a*d)*(c + d*x)^(3/2))/(12*a^2*x^2*(a + b*x)) - (c + d*x)^(5/2)/(3*a*x^3*(a + b*x)) + ((64*b^3*c^3 - 120*a*b^2*c^2*d + 60*a^2*b*c*d^2 - 5*a^3*d^3)*ArcTanh[Sqrt[c + d*x]/Sqrt[c]])/(8*a^5*Sqrt[c]) - (Sqrt[b]*(8*b*c - 3*a*d)*(b*c - a*d)^(3/2)*ArcTanh[(Sqrt[b]*Sqrt[c + d*x])/Sqrt[b*c - a*d]])/a^5}


(* ::Section::Closed:: *)
(*Integrands of the form x^m (a+b x)^(n/2) (c+d x)^(p/2)*)


(* ::Subsection::Closed:: *)
(*Integrands of the form x^m (c+d x)^(n/2) (a+b x)^(1/2)*)


(* ::Subsubsection::Closed:: *)
(*n>0*)


{x^3*Sqrt[a + b*x]*Sqrt[c + d*x], x, 6, ((7*b^4*c^4 + 2*a*b^3*c^3*d - 2*a^3*b*c*d^3 - 7*a^4*d^4)*Sqrt[a + b*x]*Sqrt[c + d*x])/(128*b^4*d^4) - ((105*b^3*c^3 - 5*a*b^2*c^2*d - 17*a^2*b*c*d^2 - 35*a^3*d^3)*Sqrt[a + b*x]*(c + d*x)^(3/2))/(960*b^3*d^4) - ((4*a*c - (35*b*c^2)/d + (7*a^2*d)/b)*x*Sqrt[a + b*x]*(c + d*x)^(3/2))/(240*b*d^2) - ((7*b*c - a*d)*x^2*Sqrt[a + b*x]*(c + d*x)^(3/2))/(40*b*d^2) + (x^3*Sqrt[a + b*x]*(c + d*x)^(3/2))/(5*d) + ((b*c - a*d)^2*(b*c + a*d)*(7*b^2*c^2 + 2*a*b*c*d + 7*a^2*d^2)*ArcTanh[(Sqrt[d]*Sqrt[a + b*x])/(Sqrt[b]*Sqrt[c + d*x])])/(128*b^(9/2)*d^(9/2))}
{x^2*Sqrt[a + b*x]*Sqrt[c + d*x], x, 5, -(((b*c - a*d)*(4*a*b*c*d - 5*(b*c + a*d)^2)*Sqrt[a + b*x]*Sqrt[c + d*x])/(64*b^3*d^3)) - ((4*a*b*c*d - 5*(b*c + a*d)^2)*(a + b*x)^(3/2)*Sqrt[c + d*x])/(32*b^3*d^2) - (5*(b*c + a*d)*(a + b*x)^(3/2)*(c + d*x)^(3/2))/(24*b^2*d^2) + (x*(a + b*x)^(3/2)*(c + d*x)^(3/2))/(4*b*d) + ((b*c - a*d)^2*(4*a*b*c*d - 5*(b*c + a*d)^2)*ArcTanh[(Sqrt[d]*Sqrt[a + b*x])/(Sqrt[b]*Sqrt[c + d*x])])/(64*b^(7/2)*d^(7/2))}
{x*Sqrt[a + b*x]*Sqrt[c + d*x], x, 4, (1/8)*(a^2/b^2 - c^2/d^2)*Sqrt[a + b*x]*Sqrt[c + d*x] - ((b*c + a*d)*(a + b*x)^(3/2)*Sqrt[c + d*x])/(4*b^2*d) + ((a + b*x)^(3/2)*(c + d*x)^(3/2))/(3*b*d) + ((b*c - a*d)^2*(b*c + a*d)*ArcTanh[(Sqrt[d]*Sqrt[a + b*x])/(Sqrt[b]*Sqrt[c + d*x])])/(8*b^(5/2)*d^(5/2))}
{Sqrt[a + b*x]*Sqrt[c + d*x], x, 3, ((b*c - a*d)*Sqrt[a + b*x]*Sqrt[c + d*x])/(4*b*d) + ((a + b*x)^(3/2)*Sqrt[c + d*x])/(2*b) - ((b*c - a*d)^2*ArcTanh[(Sqrt[d]*Sqrt[a + b*x])/(Sqrt[b]*Sqrt[c + d*x])])/(4*b^(3/2)*d^(3/2))}
{(Sqrt[a + b*x]*Sqrt[c + d*x])/x, x, 4, Sqrt[a + b*x]*Sqrt[c + d*x] - 2*Sqrt[a]*Sqrt[c]*ArcTanh[(Sqrt[c]*Sqrt[a + b*x])/(Sqrt[a]*Sqrt[c + d*x])] + ((b*c + a*d)*ArcTanh[(Sqrt[d]*Sqrt[a + b*x])/(Sqrt[b]*Sqrt[c + d*x])])/(Sqrt[b]*Sqrt[d])}
{(Sqrt[a + b*x]*Sqrt[c + d*x])/x^2, x, 4, -((Sqrt[a + b*x]*Sqrt[c + d*x])/x) - ((b*c + a*d)*ArcTanh[(Sqrt[c]*Sqrt[a + b*x])/(Sqrt[a]*Sqrt[c + d*x])])/(Sqrt[a]*Sqrt[c]) + 2*Sqrt[b]*Sqrt[d]*ArcTanh[(Sqrt[d]*Sqrt[a + b*x])/(Sqrt[b]*Sqrt[c + d*x])]}
{(Sqrt[a + b*x]*Sqrt[c + d*x])/x^3, x, 3, -((b*c - a*d)*Sqrt[a + b*x]*Sqrt[c + d*x])/(4*a*c*x) - (Sqrt[a + b*x]*(c + d*x)^(3/2))/(2*c*x^2) + ((b*c - a*d)^2*ArcTanh[(Sqrt[c]*Sqrt[a + b*x])/(Sqrt[a]*Sqrt[c + d*x])])/(4*a^(3/2)*c^(3/2))}
{(Sqrt[a + b*x]*Sqrt[c + d*x])/x^4, x, 5, -(Sqrt[a + b*x]*Sqrt[c + d*x])/(3*x^3) - ((b*c + a*d)*Sqrt[a + b*x]*Sqrt[c + d*x])/(12*a*c*x^2) + ((3*b^2*c^2 - 2*a*b*c*d + 3*a^2*d^2)*Sqrt[a + b*x]*Sqrt[c + d*x])/(24*a^2*c^2*x) - ((b*c - a*d)^2*(b*c + a*d)*ArcTanh[(Sqrt[c]*Sqrt[a + b*x])/(Sqrt[a]*Sqrt[c + d*x])])/(8*a^(5/2)*c^(5/2))}
{(Sqrt[a + b*x]*Sqrt[c + d*x])/x^5, x, 6, -((Sqrt[a + b*x]*Sqrt[c + d*x])/(4*x^4)) - ((b*c + a*d)*Sqrt[a + b*x]*Sqrt[c + d*x])/(24*a*c*x^3) + ((5*b^2*c^2 - 2*a*b*c*d + 5*a^2*d^2)*Sqrt[a + b*x]*Sqrt[c + d*x])/(96*a^2*c^2*x^2) - ((b*c + a*d)*(15*b^2*c^2 - 22*a*b*c*d + 15*a^2*d^2)*Sqrt[a + b*x]*Sqrt[c + d*x])/(192*a^3*c^3*x) + ((b*c - a*d)^2*(5*b^2*c^2 + 6*a*b*c*d + 5*a^2*d^2)*ArcTanh[(Sqrt[c]*Sqrt[a + b*x])/(Sqrt[a]*Sqrt[c + d*x])])/(64*a^(7/2)*c^(7/2))}
{(Sqrt[a + b*x]*Sqrt[c + d*x])/x^6, x, 7, -((Sqrt[a + b*x]*Sqrt[c + d*x])/(5*x^5)) - ((b*c + a*d)*Sqrt[a + b*x]*Sqrt[c + d*x])/(40*a*c*x^4) + ((7*b^2*c^2 - 2*a*b*c*d + 7*a^2*d^2)*Sqrt[a + b*x]*Sqrt[c + d*x])/(240*a^2*c^2*x^3) - ((b*c + a*d)*(35*b^2*c^2 - 46*a*b*c*d + 35*a^2*d^2)*Sqrt[a + b*x]*Sqrt[c + d*x])/(960*a^3*c^3*x^2) + ((105*b^4*c^4 - 40*a*b^3*c^3*d - 34*a^2*b^2*c^2*d^2 - 40*a^3*b*c*d^3 + 105*a^4*d^4)*Sqrt[a + b*x]*Sqrt[c + d*x])/(1920*a^4*c^4*x) - ((b*c - a*d)^2*(b*c + a*d)*(7*b^2*c^2 + 2*a*b*c*d + 7*a^2*d^2)*ArcTanh[(Sqrt[c]*Sqrt[a + b*x])/(Sqrt[a]*Sqrt[c + d*x])])/(128*a^(9/2)*c^(9/2))}


{x^2*Sqrt[a + b*x]*(c + d*x)^(3/2), x, 6, ((b*c - a*d)^2*(3*b^2*c^2 + 6*a*b*c*d + 7*a^2*d^2)*Sqrt[a + b*x]*Sqrt[c + d*x])/(128*b^4*d^3) + ((b*c - a*d)*(3*b^2*c^2 + 6*a*b*c*d + 7*a^2*d^2)*(a + b*x)^(3/2)*Sqrt[c + d*x])/(64*b^4*d^2) + ((3*b^2*c^2 + 6*a*b*c*d + 7*a^2*d^2)*(a + b*x)^(3/2)*(c + d*x)^(3/2))/(48*b^3*d^2) - ((5*b*c + 7*a*d)*(a + b*x)^(3/2)*(c + d*x)^(5/2))/(40*b^2*d^2) + (x*(a + b*x)^(3/2)*(c + d*x)^(5/2))/(5*b*d) - ((b*c - a*d)^3*(3*b^2*c^2 + 6*a*b*c*d + 7*a^2*d^2)*ArcTanh[(Sqrt[d]*Sqrt[a + b*x])/(Sqrt[b]*Sqrt[c + d*x])])/(128*b^(9/2)*d^(7/2))}
{x*Sqrt[a + b*x]*(c + d*x)^(3/2), x, 5, -((b*c - a*d)^2*(3*b*c + 5*a*d)*Sqrt[a + b*x]*Sqrt[c + d*x])/(64*b^3*d^2) - ((b*c - a*d)*(3*b*c + 5*a*d)*(a + b*x)^(3/2)*Sqrt[c + d*x])/(32*b^3*d) - ((3*b*c + 5*a*d)*(a + b*x)^(3/2)*(c + d*x)^(3/2))/(24*b^2*d) + ((a + b*x)^(3/2)*(c + d*x)^(5/2))/(4*b*d) + ((b*c - a*d)^3*(3*b*c + 5*a*d)*ArcTanh[(Sqrt[d]*Sqrt[a + b*x])/(Sqrt[b]*Sqrt[c + d*x])])/(64*b^(7/2)*d^(5/2))}
{Sqrt[a + b*x]*(c + d*x)^(3/2), x, 4, ((b*c - a*d)^2*Sqrt[a + b*x]*Sqrt[c + d*x])/(8*b^2*d) + ((b*c - a*d)*(a + b*x)^(3/2)*Sqrt[c + d*x])/(4*b^2) + ((a + b*x)^(3/2)*(c + d*x)^(3/2))/(3*b) - ((b*c - a*d)^3*ArcTanh[(Sqrt[d]*Sqrt[a + b*x])/(Sqrt[b]*Sqrt[c + d*x])])/(8*b^(5/2)*d^(3/2))}
{(Sqrt[a + b*x]*(c + d*x)^(3/2))/x, x, 5, ((3*b*c + a*d)*Sqrt[a + b*x]*Sqrt[c + d*x])/(4*b) + (Sqrt[a + b*x]*(c + d*x)^(3/2))/2 - 2*Sqrt[a]*c^(3/2)*ArcTanh[(Sqrt[c]*Sqrt[a + b*x])/(Sqrt[a]*Sqrt[c + d*x])] + ((3*b^2*c^2 + 6*a*b*c*d - a^2*d^2)*ArcTanh[(Sqrt[d]*Sqrt[a + b*x])/(Sqrt[b]*Sqrt[c + d*x])])/(4*b^(3/2)*Sqrt[d])}
{(Sqrt[a + b*x]*(c + d*x)^(3/2))/x^2, x, 5, 2*d*Sqrt[a + b*x]*Sqrt[c + d*x] - (Sqrt[a + b*x]*(c + d*x)^(3/2))/x - (Sqrt[c]*(b*c + 3*a*d)*ArcTanh[(Sqrt[c]*Sqrt[a + b*x])/(Sqrt[a]*Sqrt[c + d*x])])/Sqrt[a] + (Sqrt[d]*(3*b*c + a*d)*ArcTanh[(Sqrt[d]*Sqrt[a + b*x])/(Sqrt[b]*Sqrt[c + d*x])])/Sqrt[b]}
{(Sqrt[a + b*x]*(c + d*x)^(3/2))/x^3, x, 5, -((b*c + 3*a*d)*Sqrt[a + b*x]*Sqrt[c + d*x])/(4*a*x) - (Sqrt[a + b*x]*(c + d*x)^(3/2))/(2*x^2) + ((b^2*c^2 - 6*a*b*c*d - 3*a^2*d^2)*ArcTanh[(Sqrt[c]*Sqrt[a + b*x])/(Sqrt[a]*Sqrt[c + d*x])])/(4*a^(3/2)*Sqrt[c]) + 2*Sqrt[b]*d^(3/2)*ArcTanh[(Sqrt[d]*Sqrt[a + b*x])/(Sqrt[b]*Sqrt[c + d*x])]}
{(Sqrt[a + b*x]*(c + d*x)^(3/2))/x^4, x, 4, ((b*c - a*d)^2*Sqrt[a + b*x]*Sqrt[c + d*x])/(8*a^2*c*x) - ((b*c - a*d)*Sqrt[a + b*x]*(c + d*x)^(3/2))/(12*a*c*x^2) - (Sqrt[a + b*x]*(c + d*x)^(5/2))/(3*c*x^3) - ((b*c - a*d)^3*ArcTanh[(Sqrt[c]*Sqrt[a + b*x])/(Sqrt[a]*Sqrt[c + d*x])])/(8*a^(5/2)*c^(3/2))}
{(Sqrt[a + b*x]*(c + d*x)^(3/2))/x^5, x, 6, -(((b*c + 3*a*d)*Sqrt[a + b*x]*Sqrt[c + d*x])/(24*a*x^3)) + (((5*b^2*c)/a - 10*b*d - (3*a*d^2)/c)*Sqrt[a + b*x]*Sqrt[c + d*x])/(96*a*x^2) - ((15*b^3*c^3 - 31*a*b^2*c^2*d + 9*a^2*b*c*d^2 - 9*a^3*d^3)*Sqrt[a + b*x]*Sqrt[c + d*x])/(192*a^3*c^2*x) - (Sqrt[a + b*x]*(c + d*x)^(3/2))/(4*x^4) + ((b*c - a*d)^3*(5*b*c + 3*a*d)*ArcTanh[(Sqrt[c]*Sqrt[a + b*x])/(Sqrt[a]*Sqrt[c + d*x])])/(64*a^(7/2)*c^(5/2))}
{(Sqrt[a + b*x]*(c + d*x)^(3/2))/x^6, x, 7, -(((b*c + 3*a*d)*Sqrt[a + b*x]*Sqrt[c + d*x])/(40*a*x^4)) + (((7*b^2*c)/a - 12*b*d - (3*a*d^2)/c)*Sqrt[a + b*x]*Sqrt[c + d*x])/(240*a*x^3) - ((35*b^3*c^3 - 61*a*b^2*c^2*d + 9*a^2*b*c*d^2 - 15*a^3*d^3)*Sqrt[a + b*x]*Sqrt[c + d*x])/(960*a^3*c^2*x^2) + ((105*b^4*c^4 - 190*a*b^3*c^3*d + 36*a^2*b^2*c^2*d^2 + 30*a^3*b*c*d^3 - 45*a^4*d^4)*Sqrt[a + b*x]*Sqrt[c + d*x])/(1920*a^4*c^3*x) - (Sqrt[a + b*x]*(c + d*x)^(3/2))/(5*x^5) - ((b*c - a*d)^3*(7*b^2*c^2 + 6*a*b*c*d + 3*a^2*d^2)*ArcTanh[(Sqrt[c]*Sqrt[a + b*x])/(Sqrt[a]*Sqrt[c + d*x])])/(128*a^(9/2)*c^(7/2))}


{x^2*Sqrt[a + b*x]*(c + d*x)^(5/2), x, 7, ((b*c - a*d)^3*(5*b^2*c^2 + 14*a*b*c*d + 21*a^2*d^2)*Sqrt[a + b*x]*Sqrt[c + d*x])/(512*b^5*d^3) + ((b*c - a*d)^2*(5*b^2*c^2 + 14*a*b*c*d + 21*a^2*d^2)*(a + b*x)^(3/2)*Sqrt[c + d*x])/(256*b^5*d^2) + ((b*c - a*d)*(5*b^2*c^2 + 14*a*b*c*d + 21*a^2*d^2)*(a + b*x)^(3/2)*(c + d*x)^(3/2))/(192*b^4*d^2) + ((5*b^2*c^2 + 14*a*b*c*d + 21*a^2*d^2)*(a + b*x)^(3/2)*(c + d*x)^(5/2))/(160*b^3*d^2) - ((5*b*c + 9*a*d)*(a + b*x)^(3/2)*(c + d*x)^(7/2))/(60*b^2*d^2) + (x*(a + b*x)^(3/2)*(c + d*x)^(7/2))/(6*b*d) - ((b*c - a*d)^4*(5*b^2*c^2 + 14*a*b*c*d + 21*a^2*d^2)*ArcTanh[(Sqrt[d]*Sqrt[a + b*x])/(Sqrt[b]*Sqrt[c + d*x])])/(512*b^(11/2)*d^(7/2))}
{x^1*Sqrt[a + b*x]*(c + d*x)^(5/2), x, 6, -(((b*c - a*d)^3*(3*b*c + 7*a*d)*Sqrt[a + b*x]*Sqrt[c + d*x])/(128*b^4*d^2)) - ((b*c - a*d)^2*(3*b*c + 7*a*d)*(a + b*x)^(3/2)*Sqrt[c + d*x])/(64*b^4*d) - ((b*c - a*d)*(3*b*c + 7*a*d)*(a + b*x)^(3/2)*(c + d*x)^(3/2))/(48*b^3*d) - ((3*b*c + 7*a*d)*(a + b*x)^(3/2)*(c + d*x)^(5/2))/(40*b^2*d) + ((a + b*x)^(3/2)*(c + d*x)^(7/2))/(5*b*d) + ((b*c - a*d)^4*(3*b*c + 7*a*d)*ArcTanh[(Sqrt[d]*Sqrt[a + b*x])/(Sqrt[b]*Sqrt[c + d*x])])/(128*b^(9/2)*d^(5/2))}
{x^0*Sqrt[a + b*x]*(c + d*x)^(5/2), x, 5, (5*(b*c - a*d)^3*Sqrt[a + b*x]*Sqrt[c + d*x])/(64*b^3*d) + (5*(b*c - a*d)^2*(a + b*x)^(3/2)*Sqrt[c + d*x])/(32*b^3) + (5*(b*c - a*d)*(a + b*x)^(3/2)*(c + d*x)^(3/2))/(24*b^2) + ((a + b*x)^(3/2)*(c + d*x)^(5/2))/(4*b) - (5*(b*c - a*d)^4*ArcTanh[(Sqrt[d]*Sqrt[a + b*x])/(Sqrt[b]*Sqrt[c + d*x])])/(64*b^(7/2)*d^(3/2))}
{Sqrt[a + b*x]*(c + d*x)^(5/2)/x^1, x, 6, ((5*b*c - a*d)*(b*c + a*d)*Sqrt[a + b*x]*Sqrt[c + d*x])/(8*b^2) + ((5*b*c + a*d)*Sqrt[a + b*x]*(c + d*x)^(3/2))/(12*b) + (1/3)*Sqrt[a + b*x]*(c + d*x)^(5/2) - 2*Sqrt[a]*c^(5/2)*ArcTanh[(Sqrt[c]*Sqrt[a + b*x])/(Sqrt[a]*Sqrt[c + d*x])] + ((5*b^3*c^3 + 15*a*b^2*c^2*d - 5*a^2*b*c*d^2 + a^3*d^3)*ArcTanh[(Sqrt[d]*Sqrt[a + b*x])/(Sqrt[b]*Sqrt[c + d*x])])/(8*b^(5/2)*Sqrt[d])}
{Sqrt[a + b*x]*(c + d*x)^(5/2)/x^2, x, 6, (d*(11*b*c + a*d)*Sqrt[a + b*x]*Sqrt[c + d*x])/(4*b) + (3/2)*d*Sqrt[a + b*x]*(c + d*x)^(3/2) - (Sqrt[a + b*x]*(c + d*x)^(5/2))/x - (c^(3/2)*(b*c + 5*a*d)*ArcTanh[(Sqrt[c]*Sqrt[a + b*x])/(Sqrt[a]*Sqrt[c + d*x])])/Sqrt[a] + (Sqrt[d]*(15*b^2*c^2 + 10*a*b*c*d - a^2*d^2)*ArcTanh[(Sqrt[d]*Sqrt[a + b*x])/(Sqrt[b]*Sqrt[c + d*x])])/(4*b^(3/2))}
{Sqrt[a + b*x]*(c + d*x)^(5/2)/x^3, x, 6, (d*(b*c + 11*a*d)*Sqrt[a + b*x]*Sqrt[c + d*x])/(4*a) - ((b*c + 5*a*d)*Sqrt[a + b*x]*(c + d*x)^(3/2))/(4*a*x) - (Sqrt[a + b*x]*(c + d*x)^(5/2))/(2*x^2) + (Sqrt[c]*(b^2*c^2 - 10*a*b*c*d - 15*a^2*d^2)*ArcTanh[(Sqrt[c]*Sqrt[a + b*x])/(Sqrt[a]*Sqrt[c + d*x])])/(4*a^(3/2)) + (d^(3/2)*(5*b*c + a*d)*ArcTanh[(Sqrt[d]*Sqrt[a + b*x])/(Sqrt[b]*Sqrt[c + d*x])])/Sqrt[b]}
{Sqrt[a + b*x]*(c + d*x)^(5/2)/x^4, x, 6, ((b*c - 5*a*d)*(b*c + a*d)*Sqrt[a + b*x]*Sqrt[c + d*x])/(8*a^2*x) - ((b*c + 5*a*d)*Sqrt[a + b*x]*(c + d*x)^(3/2))/(12*a*x^2) - (Sqrt[a + b*x]*(c + d*x)^(5/2))/(3*x^3) - ((b^3*c^3 - 5*a*b^2*c^2*d + 15*a^2*b*c*d^2 + 5*a^3*d^3)*ArcTanh[(Sqrt[c]*Sqrt[a + b*x])/(Sqrt[a]*Sqrt[c + d*x])])/(8*a^(5/2)*Sqrt[c]) + 2*Sqrt[b]*d^(5/2)*ArcTanh[(Sqrt[d]*Sqrt[a + b*x])/(Sqrt[b]*Sqrt[c + d*x])]}
{Sqrt[a + b*x]*(c + d*x)^(5/2)/x^5, x, 5, -((5*(b*c - a*d)^3*Sqrt[a + b*x]*Sqrt[c + d*x])/(64*a^3*c*x)) + (5*(b*c - a*d)^2*Sqrt[a + b*x]*(c + d*x)^(3/2))/(96*a^2*c*x^2) - ((b*c - a*d)*Sqrt[a + b*x]*(c + d*x)^(5/2))/(24*a*c*x^3) - (Sqrt[a + b*x]*(c + d*x)^(7/2))/(4*c*x^4) + (5*(b*c - a*d)^4*ArcTanh[(Sqrt[c]*Sqrt[a + b*x])/(Sqrt[a]*Sqrt[c + d*x])])/(64*a^(7/2)*c^(3/2))}
{Sqrt[a + b*x]*(c + d*x)^(5/2)/x^6, x, 7, ((b*c - 3*a*d)*(7*b*c + 5*a*d)*Sqrt[a + b*x]*Sqrt[c + d*x])/(240*a^2*x^3) - ((35*b^3*c^3 - 111*a*b^2*c^2*d + 109*a^2*b*c*d^2 + 15*a^3*d^3)*Sqrt[a + b*x]*Sqrt[c + d*x])/(960*a^3*c*x^2) + ((105*b^4*c^4 - 340*a*b^3*c^3*d + 346*a^2*b^2*c^2*d^2 - 60*a^3*b*c*d^3 + 45*a^4*d^4)*Sqrt[a + b*x]*Sqrt[c + d*x])/(1920*a^4*c^2*x) - ((b*c + 5*a*d)*Sqrt[a + b*x]*(c + d*x)^(3/2))/(40*a*x^4) - (Sqrt[a + b*x]*(c + d*x)^(5/2))/(5*x^5) - ((b*c - a*d)^4*(7*b*c + 3*a*d)*ArcTanh[(Sqrt[c]*Sqrt[a + b*x])/(Sqrt[a]*Sqrt[c + d*x])])/(128*a^(9/2)*c^(5/2))}
{Sqrt[a + b*x]*(c + d*x)^(5/2)/x^7, x, 8, ((3*b^2*c^2 - 6*a*b*c*d - 5*a^2*d^2)*Sqrt[a + b*x]*Sqrt[c + d*x])/(160*a^2*x^4) - ((21*b^3*c^3 - 61*a*b^2*c^2*d + 51*a^2*b*c*d^2 + 5*a^3*d^3)*Sqrt[a + b*x]*Sqrt[c + d*x])/(960*a^3*c*x^3) + ((105*b^4*c^4 - 308*a*b^3*c^3*d + 262*a^2*b^2*c^2*d^2 - 20*a^3*b*c*d^3 + 25*a^4*d^4)*Sqrt[a + b*x]*Sqrt[c + d*x])/(3840*a^4*c^2*x^2) - ((315*b^5*c^5 - 945*a*b^4*c^4*d + 838*a^2*b^3*c^3*d^2 - 90*a^3*b^2*c^2*d^3 - 65*a^4*b*c*d^4 + 75*a^5*d^5)*Sqrt[a + b*x]*Sqrt[c + d*x])/(7680*a^5*c^3*x) - ((b*c + 5*a*d)*Sqrt[a + b*x]*(c + d*x)^(3/2))/(60*a*x^5) - (Sqrt[a + b*x]*(c + d*x)^(5/2))/(6*x^6) + ((b*c - a*d)^4*(21*b^2*c^2 + 14*a*b*c*d + 5*a^2*d^2)*ArcTanh[(Sqrt[c]*Sqrt[a + b*x])/(Sqrt[a]*Sqrt[c + d*x])])/(512*a^(11/2)*c^(7/2))}


(* ::Subsubsection::Closed:: *)
(*n<0*)


{x^3*Sqrt[a + b*x]/Sqrt[c + d*x], x, 5, -(((105*b^3*c^3 - 25*a*b^2*c^2*d - 17*a^2*b*c*d^2 - 15*a^3*d^3)*Sqrt[a + b*x]*Sqrt[c + d*x])/(192*b^3*d^4)) - ((6*a*c - (35*b*c^2)/d + (5*a^2*d)/b)*x*Sqrt[a + b*x]*Sqrt[c + d*x])/(96*b*d^2) - ((7*b*c - a*d)*x^2*Sqrt[a + b*x]*Sqrt[c + d*x])/(24*b*d^2) + (x^3*Sqrt[a + b*x]*Sqrt[c + d*x])/(4*d) + ((b*c - a*d)*(35*b^3*c^3 + 15*a*b^2*c^2*d + 9*a^2*b*c*d^2 + 5*a^3*d^3)*ArcTanh[(Sqrt[d]*Sqrt[a + b*x])/(Sqrt[b]*Sqrt[c + d*x])])/(64*b^(7/2)*d^(9/2))}
{x^2*Sqrt[a + b*x]/Sqrt[c + d*x], x, 4, ((5*b^2*c^2 + 2*a*b*c*d + a^2*d^2)*Sqrt[a + b*x]*Sqrt[c + d*x])/(8*b^2*d^3) - ((5*b*c + 3*a*d)*(a + b*x)^(3/2)*Sqrt[c + d*x])/(12*b^2*d^2) + (x*(a + b*x)^(3/2)*Sqrt[c + d*x])/(3*b*d) - ((b*c - a*d)*(5*b^2*c^2 + 2*a*b*c*d + a^2*d^2)*ArcTanh[(Sqrt[d]*Sqrt[a + b*x])/(Sqrt[b]*Sqrt[c + d*x])])/(8*b^(5/2)*d^(7/2))}
{x^1*Sqrt[a + b*x]/Sqrt[c + d*x], x, 3, -((3*b*c + a*d)*Sqrt[a + b*x]*Sqrt[c + d*x])/(4*b*d^2) + ((a + b*x)^(3/2)*Sqrt[c + d*x])/(2*b*d) + ((b*c - a*d)*(3*b*c + a*d)*ArcTanh[(Sqrt[d]*Sqrt[a + b*x])/(Sqrt[b]*Sqrt[c + d*x])])/(4*b^(3/2)*d^(5/2))}
{x^0*Sqrt[a + b*x]/Sqrt[c + d*x], x, 2, (Sqrt[a + b*x]*Sqrt[c + d*x])/d - ((b*c - a*d)*ArcTanh[(Sqrt[d]*Sqrt[a + b*x])/(Sqrt[b]*Sqrt[c + d*x])])/(Sqrt[b]*d^(3/2))}
{Sqrt[a + b*x]/(x^1*Sqrt[c + d*x]), x, 3, (-2*Sqrt[a]*ArcTanh[(Sqrt[c]*Sqrt[a + b*x])/(Sqrt[a]*Sqrt[c + d*x])])/Sqrt[c] + (2*Sqrt[b]*ArcTanh[(Sqrt[d]*Sqrt[a + b*x])/(Sqrt[b]*Sqrt[c + d*x])])/Sqrt[d]}
{Sqrt[a + b*x]/(x^2*Sqrt[c + d*x]), x, 2, -((Sqrt[a + b*x]*Sqrt[c + d*x])/(c*x)) - ((b*c - a*d)*ArcTanh[(Sqrt[c]*Sqrt[a + b*x])/(Sqrt[a]*Sqrt[c + d*x])])/(Sqrt[a]*c^(3/2))}
{Sqrt[a + b*x]/(x^3*Sqrt[c + d*x]), x, 4, -((Sqrt[a + b*x]*Sqrt[c + d*x])/(2*c*x^2)) - ((b*c - 3*a*d)*Sqrt[a + b*x]*Sqrt[c + d*x])/(4*a*c^2*x) + ((b*c - a*d)*(b*c + 3*a*d)*ArcTanh[(Sqrt[c]*Sqrt[a + b*x])/(Sqrt[a]*Sqrt[c + d*x])])/(4*a^(3/2)*c^(5/2))}
{Sqrt[a + b*x]/(x^4*Sqrt[c + d*x]), x, 5, -((Sqrt[a + b*x]*Sqrt[c + d*x])/(3*c*x^3)) - ((b*c - 5*a*d)*Sqrt[a + b*x]*Sqrt[c + d*x])/(12*a*c^2*x^2) + ((3*b*c - 5*a*d)*(b*c + 3*a*d)*Sqrt[a + b*x]*Sqrt[c + d*x])/(24*a^2*c^3*x) - ((b*c - a*d)*(b^2*c^2 + 2*a*b*c*d + 5*a^2*d^2)*ArcTanh[(Sqrt[c]*Sqrt[a + b*x])/(Sqrt[a]*Sqrt[c + d*x])])/(8*a^(5/2)*c^(7/2))}
{Sqrt[a + b*x]/(x^5*Sqrt[c + d*x]), x, 6, -((Sqrt[a + b*x]*Sqrt[c + d*x])/(4*c*x^4)) - ((b*c - 7*a*d)*Sqrt[a + b*x]*Sqrt[c + d*x])/(24*a*c^2*x^3) + ((5*b^2*c^2 + 6*a*b*c*d - 35*a^2*d^2)*Sqrt[a + b*x]*Sqrt[c + d*x])/(96*a^2*c^3*x^2) - ((15*b^3*c^3 + 17*a*b^2*c^2*d + 25*a^2*b*c*d^2 - 105*a^3*d^3)*Sqrt[a + b*x]*Sqrt[c + d*x])/(192*a^3*c^4*x) + ((b*c - a*d)*(5*b^3*c^3 + 9*a*b^2*c^2*d + 15*a^2*b*c*d^2 + 35*a^3*d^3)*ArcTanh[(Sqrt[c]*Sqrt[a + b*x])/(Sqrt[a]*Sqrt[c + d*x])])/(64*a^(7/2)*c^(9/2))}


{(x^2*Sqrt[a + b*x])/(c + d*x)^(3/2), x, 4, (2*c^2*(a + b*x)^(3/2))/(d^2*(b*c - a*d)*Sqrt[c + d*x]) + ((6*a*c - (15*b*c^2)/d + (a^2*d)/b)*Sqrt[a + b*x]*Sqrt[c + d*x])/(4*d^2*(b*c - a*d)) + ((a + b*x)^(3/2)*Sqrt[c + d*x])/(2*b*d^2) + ((15*b^2*c^2 - 6*a*b*c*d - a^2*d^2)*ArcTanh[(Sqrt[d]*Sqrt[a + b*x])/(Sqrt[b]*Sqrt[c + d*x])])/(4*b^(3/2)*d^(7/2))}
{(x*Sqrt[a + b*x])/(c + d*x)^(3/2), x, 3, (-2*c*(a + b*x)^(3/2))/(d*(b*c - a*d)*Sqrt[c + d*x]) + ((3*b*c - a*d)*Sqrt[a + b*x]*Sqrt[c + d*x])/(d^2*(b*c - a*d)) - ((3*b*c - a*d)*ArcTanh[(Sqrt[d]*Sqrt[a + b*x])/(Sqrt[b]*Sqrt[c + d*x])])/(Sqrt[b]*d^(5/2))}
{Sqrt[a + b*x]/(c + d*x)^(3/2), x, 2, (-2*Sqrt[a + b*x])/(d*Sqrt[c + d*x]) + (2*Sqrt[b]*ArcTanh[(Sqrt[d]*Sqrt[a + b*x])/(Sqrt[b]*Sqrt[c + d*x])])/d^(3/2)}
{Sqrt[a + b*x]/(x*(c + d*x)^(3/2)), x, 2, (2*Sqrt[a + b*x])/(c*Sqrt[c + d*x]) - (2*Sqrt[a]*ArcTanh[(Sqrt[c]*Sqrt[a + b*x])/(Sqrt[a]*Sqrt[c + d*x])])/c^(3/2)}
{Sqrt[a + b*x]/(x^2*(c + d*x)^(3/2)), x, 4, (-3*d*Sqrt[a + b*x])/(c^2*Sqrt[c + d*x]) - Sqrt[a + b*x]/(c*x*Sqrt[c + d*x]) - ((b*c - 3*a*d)*ArcTanh[(Sqrt[c]*Sqrt[a + b*x])/(Sqrt[a]*Sqrt[c + d*x])])/(Sqrt[a]*c^(5/2))}
{Sqrt[a + b*x]/(x^3*(c + d*x)^(3/2)), x, 5, -(d*(b*c - 15*a*d)*Sqrt[a + b*x])/(4*a*c^3*Sqrt[c + d*x]) - Sqrt[a + b*x]/(2*c*x^2*Sqrt[c + d*x]) - ((b*c - 5*a*d)*Sqrt[a + b*x])/(4*a*c^2*x*Sqrt[c + d*x]) + ((b^2*c^2 + 6*a*b*c*d - 15*a^2*d^2)*ArcTanh[(Sqrt[c]*Sqrt[a + b*x])/(Sqrt[a]*Sqrt[c + d*x])])/(4*a^(3/2)*c^(7/2))}


{(x^3*Sqrt[a + b*x])/(c + d*x)^(5/2), x, 5, -((2*x^3*Sqrt[a + b*x])/(3*d*(c + d*x)^(3/2))) - (2*(7*b*c - 6*a*d)*x^2*Sqrt[a + b*x])/(3*d^2*(b*c - a*d)*Sqrt[c + d*x]) - ((105*b^2*c^2 - 100*a*b*c*d + 3*a^2*d^2)*Sqrt[a + b*x]*Sqrt[c + d*x])/(12*b*d^4*(b*c - a*d)) + ((35*b*c - 31*a*d)*x*Sqrt[a + b*x]*Sqrt[c + d*x])/(6*d^3*(b*c - a*d)) + ((35*b^2*c^2 - 10*a*b*c*d - a^2*d^2)*ArcTanh[(Sqrt[d]*Sqrt[a + b*x])/(Sqrt[b]*Sqrt[c + d*x])])/(4*b^(3/2)*d^(9/2))}
{(x^2*Sqrt[a + b*x])/(c + d*x)^(5/2), x, 4, (2*c^2*(a + b*x)^(3/2))/(3*d^2*(b*c - a*d)*(c + d*x)^(3/2)) - (4*c*(a + b*x)^(3/2))/(d^2*(b*c - a*d)*Sqrt[c + d*x]) + ((5*b*c - a*d)*Sqrt[a + b*x]*Sqrt[c + d*x])/(d^3*(b*c - a*d)) - ((5*b*c - a*d)*ArcTanh[(Sqrt[d]*Sqrt[a + b*x])/(Sqrt[b]*Sqrt[c + d*x])])/(Sqrt[b]*d^(7/2))}
{(x*Sqrt[a + b*x])/(c + d*x)^(5/2), x, 3, (-2*c*(a + b*x)^(3/2))/(3*d*(b*c - a*d)*(c + d*x)^(3/2)) - (2*Sqrt[a + b*x])/(d^2*Sqrt[c + d*x]) + (2*Sqrt[b]*ArcTanh[(Sqrt[d]*Sqrt[a + b*x])/(Sqrt[b]*Sqrt[c + d*x])])/d^(5/2)}
{Sqrt[a + b*x]/(c + d*x)^(5/2), x, 1, (2*(a + b*x)^(3/2))/(3*(b*c - a*d)*(c + d*x)^(3/2))}
{Sqrt[a + b*x]/(x*(c + d*x)^(5/2)), x, 4, (2*Sqrt[a + b*x])/(3*c*(c + d*x)^(3/2)) + (2*(2*b*c - 3*a*d)*Sqrt[a + b*x])/(3*c^2*(b*c - a*d)*Sqrt[c + d*x]) - (2*Sqrt[a]*ArcTanh[(Sqrt[c]*Sqrt[a + b*x])/(Sqrt[a]*Sqrt[c + d*x])])/c^(5/2)}
{Sqrt[a + b*x]/(x^2*(c + d*x)^(5/2)), x, 5, (-5*d*Sqrt[a + b*x])/(3*c^2*(c + d*x)^(3/2)) - Sqrt[a + b*x]/(c*x*(c + d*x)^(3/2)) - (d*(13*b*c - 15*a*d)*Sqrt[a + b*x])/(3*c^3*(b*c - a*d)*Sqrt[c + d*x]) - ((b*c - 5*a*d)*ArcTanh[(Sqrt[c]*Sqrt[a + b*x])/(Sqrt[a]*Sqrt[c + d*x])])/(Sqrt[a]*c^(7/2))}
{Sqrt[a + b*x]/(x^3*(c + d*x)^(5/2)), x, 6, -(d*(3*b*c - 35*a*d)*Sqrt[a + b*x])/(12*a*c^3*(c + d*x)^(3/2)) - Sqrt[a + b*x]/(2*c*x^2*(c + d*x)^(3/2)) - ((b*c - 7*a*d)*Sqrt[a + b*x])/(4*a*c^2*x*(c + d*x)^(3/2)) - (d*(3*b^2*c^2 - 100*a*b*c*d + 105*a^2*d^2)*Sqrt[a + b*x])/(12*a*c^4*(b*c - a*d)*Sqrt[c + d*x]) + ((b^2*c^2 + 10*a*b*c*d - 35*a^2*d^2)*ArcTanh[(Sqrt[c]*Sqrt[a + b*x])/(Sqrt[a]*Sqrt[c + d*x])])/(4*a^(3/2)*c^(9/2))}


(* ::Subsection::Closed:: *)
(*Integrands of the form x^m (c+d x)^(n/2) (a+b x)^(3/2)*)


(* ::Subsubsection::Closed:: *)
(*n>0*)


{x^2*(a + b*x)^(3/2)*Sqrt[c + d*x], x, 6, -(((b*c - a*d)^2*(7*b^2*c^2 + 6*a*b*c*d + 3*a^2*d^2)*Sqrt[a + b*x]*Sqrt[c + d*x])/(128*b^3*d^4)) + ((b*c - a*d)*(7*b^2*c^2 + 6*a*b*c*d + 3*a^2*d^2)*(a + b*x)^(3/2)*Sqrt[c + d*x])/(192*b^3*d^3) + ((7*b^2*c^2 + 6*a*b*c*d + 3*a^2*d^2)*(a + b*x)^(5/2)*Sqrt[c + d*x])/(48*b^3*d^2) - ((7*b*c + 5*a*d)*(a + b*x)^(5/2)*(c + d*x)^(3/2))/(40*b^2*d^2) + (x*(a + b*x)^(5/2)*(c + d*x)^(3/2))/(5*b*d) + ((b*c - a*d)^3*(7*b^2*c^2 + 6*a*b*c*d + 3*a^2*d^2)*ArcTanh[(Sqrt[d]*Sqrt[a + b*x])/(Sqrt[b]*Sqrt[c + d*x])])/(128*b^(7/2)*d^(9/2))}
{x*(a + b*x)^(3/2)*Sqrt[c + d*x], x, 5, ((b*c - a*d)^2*(5*b*c + 3*a*d)*Sqrt[a + b*x]*Sqrt[c + d*x])/(64*b^2*d^3) - ((b*c - a*d)*(5*b*c + 3*a*d)*(a + b*x)^(3/2)*Sqrt[c + d*x])/(96*b^2*d^2) - ((5*b*c + 3*a*d)*(a + b*x)^(5/2)*Sqrt[c + d*x])/(24*b^2*d) + ((a + b*x)^(5/2)*(c + d*x)^(3/2))/(4*b*d) - ((b*c - a*d)^3*(5*b*c + 3*a*d)*ArcTanh[(Sqrt[d]*Sqrt[a + b*x])/(Sqrt[b]*Sqrt[c + d*x])])/(64*b^(5/2)*d^(7/2))}
{(a + b*x)^(3/2)*Sqrt[c + d*x], x, 4, -((b*c - a*d)^2*Sqrt[a + b*x]*Sqrt[c + d*x])/(8*b*d^2) + ((b*c - a*d)*(a + b*x)^(3/2)*Sqrt[c + d*x])/(12*b*d) + ((a + b*x)^(5/2)*Sqrt[c + d*x])/(3*b) + ((b*c - a*d)^3*ArcTanh[(Sqrt[d]*Sqrt[a + b*x])/(Sqrt[b]*Sqrt[c + d*x])])/(8*b^(3/2)*d^(5/2))}
{((a + b*x)^(3/2)*Sqrt[c + d*x])/x, x, 5, ((b*c + 3*a*d)*Sqrt[a + b*x]*Sqrt[c + d*x])/(4*d) + ((a + b*x)^(3/2)*Sqrt[c + d*x])/2 - 2*a^(3/2)*Sqrt[c]*ArcTanh[(Sqrt[c]*Sqrt[a + b*x])/(Sqrt[a]*Sqrt[c + d*x])] - ((b^2*c^2 - 6*a*b*c*d - 3*a^2*d^2)*ArcTanh[(Sqrt[d]*Sqrt[a + b*x])/(Sqrt[b]*Sqrt[c + d*x])])/(4*Sqrt[b]*d^(3/2))}
{((a + b*x)^(3/2)*Sqrt[c + d*x])/x^2, x, 5, 2*b*Sqrt[a + b*x]*Sqrt[c + d*x] - ((a + b*x)^(3/2)*Sqrt[c + d*x])/x - (Sqrt[a]*(3*b*c + a*d)*ArcTanh[(Sqrt[c]*Sqrt[a + b*x])/(Sqrt[a]*Sqrt[c + d*x])])/Sqrt[c] + (Sqrt[b]*(b*c + 3*a*d)*ArcTanh[(Sqrt[d]*Sqrt[a + b*x])/(Sqrt[b]*Sqrt[c + d*x])])/Sqrt[d]}
{((a + b*x)^(3/2)*Sqrt[c + d*x])/x^3, x, 5, -((3*b*c + a*d)*Sqrt[a + b*x]*Sqrt[c + d*x])/(4*c*x) - ((a + b*x)^(3/2)*Sqrt[c + d*x])/(2*x^2) - ((3*b^2*c^2 + 6*a*b*c*d - a^2*d^2)*ArcTanh[(Sqrt[c]*Sqrt[a + b*x])/(Sqrt[a]*Sqrt[c + d*x])])/(4*Sqrt[a]*c^(3/2)) + 2*b^(3/2)*Sqrt[d]*ArcTanh[(Sqrt[d]*Sqrt[a + b*x])/(Sqrt[b]*Sqrt[c + d*x])]}
{((a + b*x)^(3/2)*Sqrt[c + d*x])/x^4, x, 4, -((b*c - a*d)^2*Sqrt[a + b*x]*Sqrt[c + d*x])/(8*a*c^2*x) - ((b*c - a*d)*Sqrt[a + b*x]*(c + d*x)^(3/2))/(4*c^2*x^2) - ((a + b*x)^(3/2)*(c + d*x)^(3/2))/(3*c*x^3) + ((b*c - a*d)^3*ArcTanh[(Sqrt[c]*Sqrt[a + b*x])/(Sqrt[a]*Sqrt[c + d*x])])/(8*a^(3/2)*c^(5/2))}
{((a + b*x)^(3/2)*Sqrt[c + d*x])/x^5, x, 6, -(((3*b*c + a*d)*Sqrt[a + b*x]*Sqrt[c + d*x])/(24*c*x^3)) - (((3*b^2*c)/a + 10*b*d - (5*a*d^2)/c)*Sqrt[a + b*x]*Sqrt[c + d*x])/(96*c*x^2) + ((9*b^3*c^3 - 9*a*b^2*c^2*d + 31*a^2*b*c*d^2 - 15*a^3*d^3)*Sqrt[a + b*x]*Sqrt[c + d*x])/(192*a^2*c^3*x) - ((a + b*x)^(3/2)*Sqrt[c + d*x])/(4*x^4) - ((b*c - a*d)^3*(3*b*c + 5*a*d)*ArcTanh[(Sqrt[c]*Sqrt[a + b*x])/(Sqrt[a]*Sqrt[c + d*x])])/(64*a^(5/2)*c^(7/2))}
{((a + b*x)^(3/2)*Sqrt[c + d*x])/x^6, x, 7, -(((3*b*c + a*d)*Sqrt[a + b*x]*Sqrt[c + d*x])/(40*c*x^4)) - (((3*b^2*c)/a + 12*b*d - (7*a*d^2)/c)*Sqrt[a + b*x]*Sqrt[c + d*x])/(240*c*x^3) + ((15*b^3*c^3 - 9*a*b^2*c^2*d + 61*a^2*b*c*d^2 - 35*a^3*d^3)*Sqrt[a + b*x]*Sqrt[c + d*x])/(960*a^2*c^3*x^2) - ((45*b^4*c^4 - 30*a*b^3*c^3*d - 36*a^2*b^2*c^2*d^2 + 190*a^3*b*c*d^3 - 105*a^4*d^4)*Sqrt[a + b*x]*Sqrt[c + d*x])/(1920*a^3*c^4*x) - ((a + b*x)^(3/2)*Sqrt[c + d*x])/(5*x^5) + ((b*c - a*d)^3*(3*b^2*c^2 + 6*a*b*c*d + 7*a^2*d^2)*ArcTanh[(Sqrt[c]*Sqrt[a + b*x])/(Sqrt[a]*Sqrt[c + d*x])])/(128*a^(7/2)*c^(9/2))}


{x^2*(a + b*x)^(3/2)*(c + d*x)^(3/2), x, 7, ((b*c - a*d)^3*(4*a*b*c*d - 7*(b*c + a*d)^2)*Sqrt[a + b*x]*Sqrt[c + d*x])/(512*b^4*d^4) - ((b*c - a*d)^2*(4*a*b*c*d - 7*(b*c + a*d)^2)*(a + b*x)^(3/2)*Sqrt[c + d*x])/(768*b^4*d^3) - ((b*c - a*d)*(4*a*b*c*d - 7*(b*c + a*d)^2)*(a + b*x)^(5/2)*Sqrt[c + d*x])/(192*b^4*d^2) - ((4*a*b*c*d - 7*(b*c + a*d)^2)*(a + b*x)^(5/2)*(c + d*x)^(3/2))/(96*b^3*d^2) - (7*(b*c + a*d)*(a + b*x)^(5/2)*(c + d*x)^(5/2))/(60*b^2*d^2) + (x*(a + b*x)^(5/2)*(c + d*x)^(5/2))/(6*b*d) - ((b*c - a*d)^4*(4*a*b*c*d - 7*(b*c + a*d)^2)*ArcTanh[(Sqrt[d]*Sqrt[a + b*x])/(Sqrt[b]*Sqrt[c + d*x])])/(512*b^(9/2)*d^(9/2))}
{x*(a + b*x)^(3/2)*(c + d*x)^(3/2), x, 6, (3*(b*c - a*d)^3*(b*c + a*d)*Sqrt[a + b*x]*Sqrt[c + d*x])/(128*b^3*d^3) - ((b*c - a*d)^2*(b*c + a*d)*(a + b*x)^(3/2)*Sqrt[c + d*x])/(64*b^3*d^2) - ((b*c - a*d)*(b*c + a*d)*(a + b*x)^(5/2)*Sqrt[c + d*x])/(16*b^3*d) - ((b*c + a*d)*(a + b*x)^(5/2)*(c + d*x)^(3/2))/(8*b^2*d) + ((a + b*x)^(5/2)*(c + d*x)^(5/2))/(5*b*d) - (3*(b*c - a*d)^4*(b*c + a*d)*ArcTanh[(Sqrt[d]*Sqrt[a + b*x])/(Sqrt[b]*Sqrt[c + d*x])])/(128*b^(7/2)*d^(7/2))}
{(a + b*x)^(3/2)*(c + d*x)^(3/2), x, 5, (-3*(b*c - a*d)^3*Sqrt[a + b*x]*Sqrt[c + d*x])/(64*b^2*d^2) + ((b*c - a*d)^2*(a + b*x)^(3/2)*Sqrt[c + d*x])/(32*b^2*d) + ((b*c - a*d)*(a + b*x)^(5/2)*Sqrt[c + d*x])/(8*b^2) + ((a + b*x)^(5/2)*(c + d*x)^(3/2))/(4*b) + (3*(b*c - a*d)^4*ArcTanh[(Sqrt[d]*Sqrt[a + b*x])/(Sqrt[b]*Sqrt[c + d*x])])/(64*b^(5/2)*d^(5/2))}
{((a + b*x)^(3/2)*(c + d*x)^(3/2))/x, x, 6, (1/8)*(8*a*c - (b*c^2)/d + (a^2*d)/b)*Sqrt[a + b*x]*Sqrt[c + d*x] + ((b*c + a*d)*Sqrt[a + b*x]*(c + d*x)^(3/2))/(4*d) + (1/3)*(a + b*x)^(3/2)*(c + d*x)^(3/2) - 2*a^(3/2)*c^(3/2)*ArcTanh[(Sqrt[c]*Sqrt[a + b*x])/(Sqrt[a]*Sqrt[c + d*x])] - ((b*c + a*d)*(b^2*c^2 - 10*a*b*c*d + a^2*d^2)*ArcTanh[(Sqrt[d]*Sqrt[a + b*x])/(Sqrt[b]*Sqrt[c + d*x])])/(8*b^(3/2)*d^(3/2))}
{((a + b*x)^(3/2)*(c + d*x)^(3/2))/x^2, x, 6, (3*(b*c + 3*a*d)*Sqrt[a + b*x]*Sqrt[c + d*x])/4 + (3*b*Sqrt[a + b*x]*(c + d*x)^(3/2))/2 - ((a + b*x)^(3/2)*(c + d*x)^(3/2))/x - 3*Sqrt[a]*Sqrt[c]*(b*c + a*d)*ArcTanh[(Sqrt[c]*Sqrt[a + b*x])/(Sqrt[a]*Sqrt[c + d*x])] + (3*(b^2*c^2 + 6*a*b*c*d + a^2*d^2)*ArcTanh[(Sqrt[d]*Sqrt[a + b*x])/(Sqrt[b]*Sqrt[c + d*x])])/(4*Sqrt[b]*Sqrt[d])}
{((a + b*x)^(3/2)*(c + d*x)^(3/2))/x^3, x, 6, (3*d*(3*b*c + a*d)*Sqrt[a + b*x]*Sqrt[c + d*x])/(4*c) - (3*(b*c + a*d)*Sqrt[a + b*x]*(c + d*x)^(3/2))/(4*c*x) - ((a + b*x)^(3/2)*(c + d*x)^(3/2))/(2*x^2) - (3*(b^2*c^2 + 6*a*b*c*d + a^2*d^2)*ArcTanh[(Sqrt[c]*Sqrt[a + b*x])/(Sqrt[a]*Sqrt[c + d*x])])/(4*Sqrt[a]*Sqrt[c]) + 3*Sqrt[b]*Sqrt[d]*(b*c + a*d)*ArcTanh[(Sqrt[d]*Sqrt[a + b*x])/(Sqrt[b]*Sqrt[c + d*x])]}
{((a + b*x)^(3/2)*(c + d*x)^(3/2))/x^4, x, 6, -((((b^2*c)/a + 8*b*d - (a*d^2)/c)*Sqrt[a + b*x]*Sqrt[c + d*x])/(8*x)) - ((b*c + a*d)*Sqrt[a + b*x]*(c + d*x)^(3/2))/(4*c*x^2) - ((a + b*x)^(3/2)*(c + d*x)^(3/2))/(3*x^3) + ((b*c + a*d)*(b^2*c^2 - 10*a*b*c*d + a^2*d^2)*ArcTanh[(Sqrt[c]*Sqrt[a + b*x])/(Sqrt[a]*Sqrt[c + d*x])])/(8*a^(3/2)*c^(3/2)) + 2*b^(3/2)*d^(3/2)*ArcTanh[(Sqrt[d]*Sqrt[a + b*x])/(Sqrt[b]*Sqrt[c + d*x])]}
{((a + b*x)^(3/2)*(c + d*x)^(3/2))/x^5, x, 5, (3*(b*c - a*d)^3*Sqrt[a + b*x]*Sqrt[c + d*x])/(64*a^2*c^2*x) - ((b*c - a*d)^2*Sqrt[a + b*x]*(c + d*x)^(3/2))/(32*a*c^2*x^2) - ((b*c - a*d)*Sqrt[a + b*x]*(c + d*x)^(5/2))/(8*c^2*x^3) - ((a + b*x)^(3/2)*(c + d*x)^(5/2))/(4*c*x^4) - (3*(b*c - a*d)^4*ArcTanh[(Sqrt[c]*Sqrt[a + b*x])/(Sqrt[a]*Sqrt[c + d*x])])/(64*a^(5/2)*c^(5/2))}
{((a + b*x)^(3/2)*(c + d*x)^(3/2))/x^6, x, 7, -((((b^2*c)/a + 12*b*d - (5*a*d^2)/c)*Sqrt[a + b*x]*Sqrt[c + d*x])/(80*x^3)) + ((b*c + a*d)*(5*b^2*c^2 - 18*a*b*c*d + 5*a^2*d^2)*Sqrt[a + b*x]*Sqrt[c + d*x])/(320*a^2*c^2*x^2) - ((15*b^4*c^4 - 40*a*b^3*c^3*d + 18*a^2*b^2*c^2*d^2 - 40*a^3*b*c*d^3 + 15*a^4*d^4)*Sqrt[a + b*x]*Sqrt[c + d*x])/(640*a^3*c^3*x) - (3*(b*c + a*d)*Sqrt[a + b*x]*(c + d*x)^(3/2))/(40*c*x^4) - ((a + b*x)^(3/2)*(c + d*x)^(3/2))/(5*x^5) + (3*(b*c - a*d)^4*(b*c + a*d)*ArcTanh[(Sqrt[c]*Sqrt[a + b*x])/(Sqrt[a]*Sqrt[c + d*x])])/(128*a^(7/2)*c^(7/2))}


{x^2*(a + b*x)^(3/2)*(c + d*x)^(5/2), x, 8, -(((b*c - a*d)^4*(5*b^2*c^2 + 10*a*b*c*d + 9*a^2*d^2)*Sqrt[a + b*x]*Sqrt[c + d*x])/(1024*b^5*d^4)) + ((b*c - a*d)^3*(5*b^2*c^2 + 10*a*b*c*d + 9*a^2*d^2)*(a + b*x)^(3/2)*Sqrt[c + d*x])/(1536*b^5*d^3) + ((b*c - a*d)^2*(5*b^2*c^2 + 10*a*b*c*d + 9*a^2*d^2)*(a + b*x)^(5/2)*Sqrt[c + d*x])/(384*b^5*d^2) + ((b*c - a*d)*(5*b^2*c^2 + 10*a*b*c*d + 9*a^2*d^2)*(a + b*x)^(5/2)*(c + d*x)^(3/2))/(192*b^4*d^2) + ((5*b^2*c^2 + 10*a*b*c*d + 9*a^2*d^2)*(a + b*x)^(5/2)*(c + d*x)^(5/2))/(120*b^3*d^2) - ((7*b*c + 9*a*d)*(a + b*x)^(5/2)*(c + d*x)^(7/2))/(84*b^2*d^2) + (x*(a + b*x)^(5/2)*(c + d*x)^(7/2))/(7*b*d) + ((b*c - a*d)^5*(5*b^2*c^2 + 10*a*b*c*d + 9*a^2*d^2)*ArcTanh[(Sqrt[d]*Sqrt[a + b*x])/(Sqrt[b]*Sqrt[c + d*x])])/(1024*b^(11/2)*d^(9/2))}
{x*(a + b*x)^(3/2)*(c + d*x)^(5/2), x, 7, ((b*c - a*d)^4*(5*b*c + 7*a*d)*Sqrt[a + b*x]*Sqrt[c + d*x])/(512*b^4*d^3) - ((b*c - a*d)^3*(5*b*c + 7*a*d)*(a + b*x)^(3/2)*Sqrt[c + d*x])/(768*b^4*d^2) - ((b*c - a*d)^2*(5*b*c + 7*a*d)*(a + b*x)^(5/2)*Sqrt[c + d*x])/(192*b^4*d) - ((b*c - a*d)*(5*b*c + 7*a*d)*(a + b*x)^(5/2)*(c + d*x)^(3/2))/(96*b^3*d) - ((5*b*c + 7*a*d)*(a + b*x)^(5/2)*(c + d*x)^(5/2))/(60*b^2*d) + ((a + b*x)^(5/2)*(c + d*x)^(7/2))/(6*b*d) - ((b*c - a*d)^5*(5*b*c + 7*a*d)*ArcTanh[(Sqrt[d]*Sqrt[a + b*x])/(Sqrt[b]*Sqrt[c + d*x])])/(512*b^(9/2)*d^(7/2))}
{(a + b*x)^(3/2)*(c + d*x)^(5/2), x, 6, (-3*(b*c - a*d)^4*Sqrt[a + b*x]*Sqrt[c + d*x])/(128*b^3*d^2) + ((b*c - a*d)^3*(a + b*x)^(3/2)*Sqrt[c + d*x])/(64*b^3*d) + ((b*c - a*d)^2*(a + b*x)^(5/2)*Sqrt[c + d*x])/(16*b^3) + ((b*c - a*d)*(a + b*x)^(5/2)*(c + d*x)^(3/2))/(8*b^2) + ((a + b*x)^(5/2)*(c + d*x)^(5/2))/(5*b) + (3*(b*c - a*d)^5*ArcTanh[(Sqrt[d]*Sqrt[a + b*x])/(Sqrt[b]*Sqrt[c + d*x])])/(128*b^(7/2)*d^(5/2))}
{((a + b*x)^(3/2)*(c + d*x)^(5/2))/x, x, 7, -(((5*b^3*c^3 - 55*a*b^2*c^2*d - 17*a^2*b*c*d^2 + 3*a^3*d^3)*Sqrt[a + b*x]*Sqrt[c + d*x])/(64*b^2*d)) + (1/96)*(50*a*c - (5*b*c^2)/d + (3*a^2*d)/b)*Sqrt[a + b*x]*(c + d*x)^(3/2) + ((5*b*c + 3*a*d)*Sqrt[a + b*x]*(c + d*x)^(5/2))/(24*d) + (1/4)*(a + b*x)^(3/2)*(c + d*x)^(5/2) - 2*a^(3/2)*c^(5/2)*ArcTanh[(Sqrt[c]*Sqrt[a + b*x])/(Sqrt[a]*Sqrt[c + d*x])] - ((5*b^4*c^4 - 60*a*b^3*c^3*d - 90*a^2*b^2*c^2*d^2 + 20*a^3*b*c*d^3 - 3*a^4*d^4)*ArcTanh[(Sqrt[d]*Sqrt[a + b*x])/(Sqrt[b]*Sqrt[c + d*x])])/(64*b^(5/2)*d^(3/2))}
{((a + b*x)^(3/2)*(c + d*x)^(5/2))/x^2, x, 7, ((5*b^2*c^2 + 26*a*b*c*d + a^2*d^2)*Sqrt[a + b*x]*Sqrt[c + d*x])/(8*b) + ((5*b*c + 19*a*d)*Sqrt[a + b*x]*(c + d*x)^(3/2))/12 + (4*b*Sqrt[a + b*x]*(c + d*x)^(5/2))/3 - ((a + b*x)^(3/2)*(c + d*x)^(5/2))/x - Sqrt[a]*c^(3/2)*(3*b*c + 5*a*d)*ArcTanh[(Sqrt[c]*Sqrt[a + b*x])/(Sqrt[a]*Sqrt[c + d*x])] + ((5*b^3*c^3 + 45*a*b^2*c^2*d + 15*a^2*b*c*d^2 - a^3*d^3)*ArcTanh[(Sqrt[d]*Sqrt[a + b*x])/(Sqrt[b]*Sqrt[c + d*x])])/(8*b^(3/2)*Sqrt[d])}
{((a + b*x)^(3/2)*(c + d*x)^(5/2))/x^3, x, 7, 3*d*(b*c + a*d)*Sqrt[a + b*x]*Sqrt[c + d*x] + (d*(7*b*c + 5*a*d)*Sqrt[a + b*x]*(c + d*x)^(3/2))/(4*c) - ((3*b*c + 5*a*d)*Sqrt[a + b*x]*(c + d*x)^(5/2))/(4*c*x) - ((a + b*x)^(3/2)*(c + d*x)^(5/2))/(2*x^2) - (3*Sqrt[c]*(b^2*c^2 + 10*a*b*c*d + 5*a^2*d^2)*ArcTanh[(Sqrt[c]*Sqrt[a + b*x])/(Sqrt[a]*Sqrt[c + d*x])])/(4*Sqrt[a]) + (3*Sqrt[d]*(5*b^2*c^2 + 10*a*b*c*d + a^2*d^2)*ArcTanh[(Sqrt[d]*Sqrt[a + b*x])/(Sqrt[b]*Sqrt[c + d*x])])/(4*Sqrt[b])}
{((a + b*x)^(3/2)*(c + d*x)^(5/2))/x^4, x, 7, (d*(b^2*c^2 + 26*a*b*c*d + 5*a^2*d^2)*Sqrt[a + b*x]*Sqrt[c + d*x])/(8*a*c) - (((3*b^2*c)/a + 40*b*d + (5*a*d^2)/c)*Sqrt[a + b*x]*(c + d*x)^(3/2))/(24*x) - ((3*b*c + 5*a*d)*Sqrt[a + b*x]*(c + d*x)^(5/2))/(12*c*x^2) - ((a + b*x)^(3/2)*(c + d*x)^(5/2))/(3*x^3) + ((b^3*c^3 - 15*a*b^2*c^2*d - 45*a^2*b*c*d^2 - 5*a^3*d^3)*ArcTanh[(Sqrt[c]*Sqrt[a + b*x])/(Sqrt[a]*Sqrt[c + d*x])])/(8*a^(3/2)*Sqrt[c]) + Sqrt[b]*d^(3/2)*(5*b*c + 3*a*d)*ArcTanh[(Sqrt[d]*Sqrt[a + b*x])/(Sqrt[b]*Sqrt[c + d*x])]}
{((a + b*x)^(3/2)*(c + d*x)^(5/2))/x^5, x, 7, ((3*b^3*c^3 - 17*a*b^2*c^2*d - 55*a^2*b*c*d^2 + 5*a^3*d^3)*Sqrt[a + b*x]*Sqrt[c + d*x])/(64*a^2*c*x) - (((3*b^2*c)/a + 50*b*d - (5*a*d^2)/c)*Sqrt[a + b*x]*(c + d*x)^(3/2))/(96*x^2) - ((3*b*c + 5*a*d)*Sqrt[a + b*x]*(c + d*x)^(5/2))/(24*c*x^3) - ((a + b*x)^(3/2)*(c + d*x)^(5/2))/(4*x^4) - ((3*b^4*c^4 - 20*a*b^3*c^3*d + 90*a^2*b^2*c^2*d^2 + 60*a^3*b*c*d^3 - 5*a^4*d^4)*ArcTanh[(Sqrt[c]*Sqrt[a + b*x])/(Sqrt[a]*Sqrt[c + d*x])])/(64*a^(5/2)*c^(3/2)) + 2*b^(3/2)*d^(5/2)*ArcTanh[(Sqrt[d]*Sqrt[a + b*x])/(Sqrt[b]*Sqrt[c + d*x])]}
{((a + b*x)^(3/2)*(c + d*x)^(5/2))/x^6, x, 6, (-3*(b*c - a*d)^4*Sqrt[a + b*x]*Sqrt[c + d*x])/(128*a^3*c^2*x) + ((b*c - a*d)^3*Sqrt[a + b*x]*(c + d*x)^(3/2))/(64*a^2*c^2*x^2) - ((b*c - a*d)^2*Sqrt[a + b*x]*(c + d*x)^(5/2))/(80*a*c^2*x^3) - (3*(b*c - a*d)*Sqrt[a + b*x]*(c + d*x)^(7/2))/(40*c^2*x^4) - ((a + b*x)^(3/2)*(c + d*x)^(7/2))/(5*c*x^5) + (3*(b*c - a*d)^5*ArcTanh[(Sqrt[c]*Sqrt[a + b*x])/(Sqrt[a]*Sqrt[c + d*x])])/(128*a^(7/2)*c^(5/2))}
{((a + b*x)^(3/2)*(c + d*x)^(5/2))/x^7, x, 8, ((b*c - 5*a*d)*(7*b^2*c^2 + 14*a*b*c*d - 5*a^2*d^2)*Sqrt[a + b*x]*Sqrt[c + d*x])/(960*a^2*c*x^3) - ((35*b^4*c^4 - 136*a*b^3*c^3*d + 174*a^2*b^2*c^2*d^2 + 80*a^3*b*c*d^3 - 25*a^4*d^4)*Sqrt[a + b*x]*Sqrt[c + d*x])/(3840*a^3*c^2*x^2) + ((105*b^5*c^5 - 415*a*b^4*c^4*d + 546*a^2*b^3*c^3*d^2 - 150*a^3*b^2*c^2*d^3 + 245*a^4*b*c*d^4 - 75*a^5*d^5)*Sqrt[a + b*x]*Sqrt[c + d*x])/(7680*a^4*c^3*x) - (((3*b^2*c)/a + 70*b*d - (25*a*d^2)/c)*Sqrt[a + b*x]*(c + d*x)^(3/2))/(480*x^4) - ((3*b*c + 5*a*d)*Sqrt[a + b*x]*(c + d*x)^(5/2))/(60*c*x^5) - ((a + b*x)^(3/2)*(c + d*x)^(5/2))/(6*x^6) - ((b*c - a*d)^5*(7*b*c + 5*a*d)*ArcTanh[(Sqrt[c]*Sqrt[a + b*x])/(Sqrt[a]*Sqrt[c + d*x])])/(512*a^(9/2)*c^(7/2))}


(* ::Subsubsection::Closed:: *)
(*n<0*)


{(x^2*(a + b*x)^(3/2))/Sqrt[c + d*x], x, 5, -(((b*c - a*d)*(35*b^2*c^2 + 10*a*b*c*d + 3*a^2*d^2)*Sqrt[a + b*x]*Sqrt[c + d*x])/(64*b^2*d^4)) + ((35*b^2*c^2 + 10*a*b*c*d + 3*a^2*d^2)*(a + b*x)^(3/2)*Sqrt[c + d*x])/(96*b^2*d^3) - ((7*b*c + 3*a*d)*(a + b*x)^(5/2)*Sqrt[c + d*x])/(24*b^2*d^2) + (x*(a + b*x)^(5/2)*Sqrt[c + d*x])/(4*b*d) + ((b*c - a*d)^2*(35*b^2*c^2 + 10*a*b*c*d + 3*a^2*d^2)*ArcTanh[(Sqrt[d]*Sqrt[a + b*x])/(Sqrt[b]*Sqrt[c + d*x])])/(64*b^(5/2)*d^(9/2))}
{(x*(a + b*x)^(3/2))/Sqrt[c + d*x], x, 4, ((b*c - a*d)*(5*b*c + a*d)*Sqrt[a + b*x]*Sqrt[c + d*x])/(8*b*d^3) - ((5*b*c + a*d)*(a + b*x)^(3/2)*Sqrt[c + d*x])/(12*b*d^2) + ((a + b*x)^(5/2)*Sqrt[c + d*x])/(3*b*d) - ((b*c - a*d)^2*(5*b*c + a*d)*ArcTanh[(Sqrt[d]*Sqrt[a + b*x])/(Sqrt[b]*Sqrt[c + d*x])])/(8*b^(3/2)*d^(7/2))}
{(a + b*x)^(3/2)/Sqrt[c + d*x], x, 3, (-3*(b*c - a*d)*Sqrt[a + b*x]*Sqrt[c + d*x])/(4*d^2) + ((a + b*x)^(3/2)*Sqrt[c + d*x])/(2*d) + (3*(b*c - a*d)^2*ArcTanh[(Sqrt[d]*Sqrt[a + b*x])/(Sqrt[b]*Sqrt[c + d*x])])/(4*Sqrt[b]*d^(5/2))}
{(a + b*x)^(3/2)/(x*Sqrt[c + d*x]), x, 4, (b*Sqrt[a + b*x]*Sqrt[c + d*x])/d - (2*a^(3/2)*ArcTanh[(Sqrt[c]*Sqrt[a + b*x])/(Sqrt[a]*Sqrt[c + d*x])])/Sqrt[c] - (Sqrt[b]*(b*c - 3*a*d)*ArcTanh[(Sqrt[d]*Sqrt[a + b*x])/(Sqrt[b]*Sqrt[c + d*x])])/d^(3/2)}
{(a + b*x)^(3/2)/(x^2*Sqrt[c + d*x]), x, 5, (b*Sqrt[a + b*x]*Sqrt[c + d*x])/c - ((a + b*x)^(3/2)*Sqrt[c + d*x])/(c*x) - (Sqrt[a]*(3*b*c - a*d)*ArcTanh[(Sqrt[c]*Sqrt[a + b*x])/(Sqrt[a]*Sqrt[c + d*x])])/c^(3/2) + (2*b^(3/2)*ArcTanh[(Sqrt[d]*Sqrt[a + b*x])/(Sqrt[b]*Sqrt[c + d*x])])/Sqrt[d]}
{(a + b*x)^(3/2)/(x^3*Sqrt[c + d*x]), x, 3, (-3*(b*c - a*d)*Sqrt[a + b*x]*Sqrt[c + d*x])/(4*c^2*x) - ((a + b*x)^(3/2)*Sqrt[c + d*x])/(2*c*x^2) - (3*(b*c - a*d)^2*ArcTanh[(Sqrt[c]*Sqrt[a + b*x])/(Sqrt[a]*Sqrt[c + d*x])])/(4*Sqrt[a]*c^(5/2))}
{(a + b*x)^(3/2)/(x^4*Sqrt[c + d*x]), x, 5, -(((3*b*c - 5*a*d)*Sqrt[a + b*x]*Sqrt[c + d*x])/(12*c^2*x^2)) - (((3*b^2*c)/a - 22*b*d + (15*a*d^2)/c)*Sqrt[a + b*x]*Sqrt[c + d*x])/(24*c^2*x) - ((a + b*x)^(3/2)*Sqrt[c + d*x])/(3*c*x^3) + ((b*c - a*d)^2*(b*c + 5*a*d)*ArcTanh[(Sqrt[c]*Sqrt[a + b*x])/(Sqrt[a]*Sqrt[c + d*x])])/(8*a^(3/2)*c^(7/2))}
{(a + b*x)^(3/2)/(x^5*Sqrt[c + d*x]), x, 6, -(((3*b*c - 7*a*d)*Sqrt[a + b*x]*Sqrt[c + d*x])/(24*c^2*x^3)) - (((3*b^2*c)/a - 46*b*d + (35*a*d^2)/c)*Sqrt[a + b*x]*Sqrt[c + d*x])/(96*c^2*x^2) + ((9*b^3*c^3 + 15*a*b^2*c^2*d - 145*a^2*b*c*d^2 + 105*a^3*d^3)*Sqrt[a + b*x]*Sqrt[c + d*x])/(192*a^2*c^4*x) - ((a + b*x)^(3/2)*Sqrt[c + d*x])/(4*c*x^4) - ((b*c - a*d)^2*(3*b^2*c^2 + 10*a*b*c*d + 35*a^2*d^2)*ArcTanh[(Sqrt[c]*Sqrt[a + b*x])/(Sqrt[a]*Sqrt[c + d*x])])/(64*a^(5/2)*c^(9/2))}


{(x^2*(a + b*x)^(3/2))/(c + d*x)^(3/2), x, 5, (2*c^2*(a + b*x)^(5/2))/(d^2*(b*c - a*d)*Sqrt[c + d*x]) + ((35*b^2*c^2 - 10*a*b*c*d - a^2*d^2)*Sqrt[a + b*x]*Sqrt[c + d*x])/(8*b*d^4) + ((10*a*c - (35*b*c^2)/d + (a^2*d)/b)*(a + b*x)^(3/2)*Sqrt[c + d*x])/(12*d^2*(b*c - a*d)) + ((a + b*x)^(5/2)*Sqrt[c + d*x])/(3*b*d^2) - ((b*c - a*d)*(35*b^2*c^2 - 10*a*b*c*d - a^2*d^2)*ArcTanh[(Sqrt[d]*Sqrt[a + b*x])/(Sqrt[b]*Sqrt[c + d*x])])/(8*b^(3/2)*d^(9/2))}
{(x*(a + b*x)^(3/2))/(c + d*x)^(3/2), x, 4, (-2*c*(a + b*x)^(5/2))/(d*(b*c - a*d)*Sqrt[c + d*x]) - (3*(5*b*c - a*d)*Sqrt[a + b*x]*Sqrt[c + d*x])/(4*d^3) + ((5*b*c - a*d)*(a + b*x)^(3/2)*Sqrt[c + d*x])/(2*d^2*(b*c - a*d)) + (3*(b*c - a*d)*(5*b*c - a*d)*ArcTanh[(Sqrt[d]*Sqrt[a + b*x])/(Sqrt[b]*Sqrt[c + d*x])])/(4*Sqrt[b]*d^(7/2))}
{(a + b*x)^(3/2)/(c + d*x)^(3/2), x, 3, (-2*(a + b*x)^(3/2))/(d*Sqrt[c + d*x]) + (3*b*Sqrt[a + b*x]*Sqrt[c + d*x])/d^2 - (3*Sqrt[b]*(b*c - a*d)*ArcTanh[(Sqrt[d]*Sqrt[a + b*x])/(Sqrt[b]*Sqrt[c + d*x])])/d^(5/2)}
{(a + b*x)^(3/2)/(x*(c + d*x)^(3/2)), x, 5, (2*(a + b*x)^(3/2))/(c*Sqrt[c + d*x]) - (2*b*Sqrt[a + b*x]*Sqrt[c + d*x])/(c*d) - (2*a^(3/2)*ArcTanh[(Sqrt[c]*Sqrt[a + b*x])/(Sqrt[a]*Sqrt[c + d*x])])/c^(3/2) + (2*b^(3/2)*ArcTanh[(Sqrt[d]*Sqrt[a + b*x])/(Sqrt[b]*Sqrt[c + d*x])])/d^(3/2)}
{(a + b*x)^(3/2)/(x^2*(c + d*x)^(3/2)), x, 3, (3*(b*c - a*d)*Sqrt[a + b*x])/(c^2*Sqrt[c + d*x]) - (a + b*x)^(3/2)/(c*x*Sqrt[c + d*x]) - (3*Sqrt[a]*(b*c - a*d)*ArcTanh[(Sqrt[c]*Sqrt[a + b*x])/(Sqrt[a]*Sqrt[c + d*x])])/c^(5/2)}
{(a + b*x)^(3/2)/(x^3*(c + d*x)^(3/2)), x, 5, -((d*(13*b*c - 15*a*d)*Sqrt[a + b*x])/(4*c^3*Sqrt[c + d*x])) - ((3*b*c - 5*a*d)*Sqrt[a + b*x])/(4*c^2*x*Sqrt[c + d*x]) - (a + b*x)^(3/2)/(2*c*x^2*Sqrt[c + d*x]) - (3*(b*c - 5*a*d)*(b*c - a*d)*ArcTanh[(Sqrt[c]*Sqrt[a + b*x])/(Sqrt[a]*Sqrt[c + d*x])])/(4*Sqrt[a]*c^(7/2))}
{(a + b*x)^(3/2)/(x^4*(c + d*x)^(3/2)), x, 6, -((d*(3*b^2*c^2 - 100*a*b*c*d + 105*a^2*d^2)*Sqrt[a + b*x])/(24*a*c^4*Sqrt[c + d*x])) - ((3*b*c - 7*a*d)*Sqrt[a + b*x])/(12*c^2*x^2*Sqrt[c + d*x]) - ((3*b*c - 35*a*d)*(b*c - a*d)*Sqrt[a + b*x])/(24*a*c^3*x*Sqrt[c + d*x]) - (a + b*x)^(3/2)/(3*c*x^3*Sqrt[c + d*x]) + ((b*c - a*d)*(b^2*c^2 + 10*a*b*c*d - 35*a^2*d^2)*ArcTanh[(Sqrt[c]*Sqrt[a + b*x])/(Sqrt[a]*Sqrt[c + d*x])])/(8*a^(3/2)*c^(9/2))}


{(x^2*(a + b*x)^(3/2))/(c + d*x)^(5/2), x, 5, (2*c^2*(a + b*x)^(5/2))/(3*d^2*(b*c - a*d)*(c + d*x)^(3/2)) - (4*c*(4*b*c - 3*a*d)*(a + b*x)^(5/2))/(3*d^2*(b*c - a*d)^2*Sqrt[c + d*x]) - ((35*b^2*c^2 - 30*a*b*c*d + 3*a^2*d^2)*Sqrt[a + b*x]*Sqrt[c + d*x])/(4*d^4*(b*c - a*d)) + ((35*b^2*c^2 - 30*a*b*c*d + 3*a^2*d^2)*(a + b*x)^(3/2)*Sqrt[c + d*x])/(6*d^3*(b*c - a*d)^2) + ((35*b^2*c^2 - 30*a*b*c*d + 3*a^2*d^2)*ArcTanh[(Sqrt[d]*Sqrt[a + b*x])/(Sqrt[b]*Sqrt[c + d*x])])/(4*Sqrt[b]*d^(9/2))}
{(x*(a + b*x)^(3/2))/(c + d*x)^(5/2), x, 4, (-2*c*(a + b*x)^(5/2))/(3*d*(b*c - a*d)*(c + d*x)^(3/2)) - (2*(5*b*c - 3*a*d)*(a + b*x)^(3/2))/(3*d^2*(b*c - a*d)*Sqrt[c + d*x]) + (b*(5*b*c - 3*a*d)*Sqrt[a + b*x]*Sqrt[c + d*x])/(d^3*(b*c - a*d)) - (Sqrt[b]*(5*b*c - 3*a*d)*ArcTanh[(Sqrt[d]*Sqrt[a + b*x])/(Sqrt[b]*Sqrt[c + d*x])])/d^(7/2)}
{(a + b*x)^(3/2)/(c + d*x)^(5/2), x, 3, (-2*(a + b*x)^(3/2))/(3*d*(c + d*x)^(3/2)) - (2*b*Sqrt[a + b*x])/(d^2*Sqrt[c + d*x]) + (2*b^(3/2)*ArcTanh[(Sqrt[d]*Sqrt[a + b*x])/(Sqrt[b]*Sqrt[c + d*x])])/d^(5/2)}
{(a + b*x)^(3/2)/(x*(c + d*x)^(5/2)), x, 3, (2*(a + b*x)^(3/2))/(3*c*(c + d*x)^(3/2)) + (2*a*Sqrt[a + b*x])/(c^2*Sqrt[c + d*x]) - (2*a^(3/2)*ArcTanh[(Sqrt[c]*Sqrt[a + b*x])/(Sqrt[a]*Sqrt[c + d*x])])/c^(5/2)}
{(a + b*x)^(3/2)/(x^2*(c + d*x)^(5/2)), x, 5, (5*(b*c - a*d)*Sqrt[a + b*x])/(3*c^2*(c + d*x)^(3/2)) - (a + b*x)^(3/2)/(c*x*(c + d*x)^(3/2)) + ((4*b*c - 15*a*d)*Sqrt[a + b*x])/(3*c^3*Sqrt[c + d*x]) - (Sqrt[a]*(3*b*c - 5*a*d)*ArcTanh[(Sqrt[c]*Sqrt[a + b*x])/(Sqrt[a]*Sqrt[c + d*x])])/c^(7/2)}
{(a + b*x)^(3/2)/(x^3*(c + d*x)^(5/2)), x, 6, -(d*(23*b*c - 35*a*d)*Sqrt[a + b*x])/(12*c^3*(c + d*x)^(3/2)) - ((3*b*c - 7*a*d)*Sqrt[a + b*x])/(4*c^2*x*(c + d*x)^(3/2)) - (a + b*x)^(3/2)/(2*c*x^2*(c + d*x)^(3/2)) - (5*d*(11*b*c - 21*a*d)*Sqrt[a + b*x])/(12*c^4*Sqrt[c + d*x]) - ((3*b^2*c^2 - 30*a*b*c*d + 35*a^2*d^2)*ArcTanh[(Sqrt[c]*Sqrt[a + b*x])/(Sqrt[a]*Sqrt[c + d*x])])/(4*Sqrt[a]*c^(9/2))}


(* ::Subsection::Closed:: *)
(*Integrands of the form x^m (c+d x)^(n/2) (a+b x)^(5/2)*)


(* ::Subsubsection::Closed:: *)
(*n>0*)


{x^2*(a + b*x)^(5/2)*Sqrt[c + d*x], x, 7, ((b*c - a*d)^3*(21*b^2*c^2 + 14*a*b*c*d + 5*a^2*d^2)*Sqrt[a + b*x]*Sqrt[c + d*x])/(512*b^3*d^5) - ((b*c - a*d)^2*(21*b^2*c^2 + 14*a*b*c*d + 5*a^2*d^2)*(a + b*x)^(3/2)*Sqrt[c + d*x])/(768*b^3*d^4) + ((b*c - a*d)*(21*b^2*c^2 + 14*a*b*c*d + 5*a^2*d^2)*(a + b*x)^(5/2)*Sqrt[c + d*x])/(960*b^3*d^3) + ((21*b^2*c^2 + 14*a*b*c*d + 5*a^2*d^2)*(a + b*x)^(7/2)*Sqrt[c + d*x])/(160*b^3*d^2) - ((9*b*c + 5*a*d)*(a + b*x)^(7/2)*(c + d*x)^(3/2))/(60*b^2*d^2) + (x*(a + b*x)^(7/2)*(c + d*x)^(3/2))/(6*b*d) - ((b*c - a*d)^4*(21*b^2*c^2 + 14*a*b*c*d + 5*a^2*d^2)*ArcTanh[(Sqrt[d]*Sqrt[a + b*x])/(Sqrt[b]*Sqrt[c + d*x])])/(512*b^(7/2)*d^(11/2))}
{x*(a + b*x)^(5/2)*Sqrt[c + d*x], x, 6, -((b*c - a*d)^3*(7*b*c + 3*a*d)*Sqrt[a + b*x]*Sqrt[c + d*x])/(128*b^2*d^4) + ((b*c - a*d)^2*(7*b*c + 3*a*d)*(a + b*x)^(3/2)*Sqrt[c + d*x])/(192*b^2*d^3) - ((b*c - a*d)*(7*b*c + 3*a*d)*(a + b*x)^(5/2)*Sqrt[c + d*x])/(240*b^2*d^2) - ((7*b*c + 3*a*d)*(a + b*x)^(7/2)*Sqrt[c + d*x])/(40*b^2*d) + ((a + b*x)^(7/2)*(c + d*x)^(3/2))/(5*b*d) + ((b*c - a*d)^4*(7*b*c + 3*a*d)*ArcTanh[(Sqrt[d]*Sqrt[a + b*x])/(Sqrt[b]*Sqrt[c + d*x])])/(128*b^(5/2)*d^(9/2))}
{(a + b*x)^(5/2)*Sqrt[c + d*x], x, 5, (5*(b*c - a*d)^3*Sqrt[a + b*x]*Sqrt[c + d*x])/(64*b*d^3) - (5*(b*c - a*d)^2*(a + b*x)^(3/2)*Sqrt[c + d*x])/(96*b*d^2) + ((b*c - a*d)*(a + b*x)^(5/2)*Sqrt[c + d*x])/(24*b*d) + ((a + b*x)^(7/2)*Sqrt[c + d*x])/(4*b) - (5*(b*c - a*d)^4*ArcTanh[(Sqrt[d]*Sqrt[a + b*x])/(Sqrt[b]*Sqrt[c + d*x])])/(64*b^(3/2)*d^(7/2))}
{((a + b*x)^(5/2)*Sqrt[c + d*x])/x, x, 6, -(((b*c - 5*a*d)*(b*c + a*d)*Sqrt[a + b*x]*Sqrt[c + d*x])/(8*d^2)) + ((b*c + 5*a*d)*(a + b*x)^(3/2)*Sqrt[c + d*x])/(12*d) + (1/3)*(a + b*x)^(5/2)*Sqrt[c + d*x] - 2*a^(5/2)*Sqrt[c]*ArcTanh[(Sqrt[c]*Sqrt[a + b*x])/(Sqrt[a]*Sqrt[c + d*x])] + ((b^3*c^3 - 5*a*b^2*c^2*d + 15*a^2*b*c*d^2 + 5*a^3*d^3)*ArcTanh[(Sqrt[d]*Sqrt[a + b*x])/(Sqrt[b]*Sqrt[c + d*x])])/(8*Sqrt[b]*d^(5/2))}
{((a + b*x)^(5/2)*Sqrt[c + d*x])/x^2, x, 6, (b*(b*c + 11*a*d)*Sqrt[a + b*x]*Sqrt[c + d*x])/(4*d) + (3*b*(a + b*x)^(3/2)*Sqrt[c + d*x])/2 - ((a + b*x)^(5/2)*Sqrt[c + d*x])/x - (a^(3/2)*(5*b*c + a*d)*ArcTanh[(Sqrt[c]*Sqrt[a + b*x])/(Sqrt[a]*Sqrt[c + d*x])])/Sqrt[c] - (Sqrt[b]*(b^2*c^2 - 10*a*b*c*d - 15*a^2*d^2)*ArcTanh[(Sqrt[d]*Sqrt[a + b*x])/(Sqrt[b]*Sqrt[c + d*x])])/(4*d^(3/2))}
{((a + b*x)^(5/2)*Sqrt[c + d*x])/x^3, x, 6, (b*(11*b*c + a*d)*Sqrt[a + b*x]*Sqrt[c + d*x])/(4*c) - ((5*b*c + a*d)*(a + b*x)^(3/2)*Sqrt[c + d*x])/(4*c*x) - ((a + b*x)^(5/2)*Sqrt[c + d*x])/(2*x^2) - (Sqrt[a]*(15*b^2*c^2 + 10*a*b*c*d - a^2*d^2)*ArcTanh[(Sqrt[c]*Sqrt[a + b*x])/(Sqrt[a]*Sqrt[c + d*x])])/(4*c^(3/2)) + (b^(3/2)*(b*c + 5*a*d)*ArcTanh[(Sqrt[d]*Sqrt[a + b*x])/(Sqrt[b]*Sqrt[c + d*x])])/Sqrt[d]}
{((a + b*x)^(5/2)*Sqrt[c + d*x])/x^4, x, 6, -(((5*b*c - a*d)*(b*c + a*d)*Sqrt[a + b*x]*Sqrt[c + d*x])/(8*c^2*x)) - ((5*b*c + a*d)*(a + b*x)^(3/2)*Sqrt[c + d*x])/(12*c*x^2) - ((a + b*x)^(5/2)*Sqrt[c + d*x])/(3*x^3) - ((5*b^3*c^3 + 15*a*b^2*c^2*d - 5*a^2*b*c*d^2 + a^3*d^3)*ArcTanh[(Sqrt[c]*Sqrt[a + b*x])/(Sqrt[a]*Sqrt[c + d*x])])/(8*Sqrt[a]*c^(5/2)) + 2*b^(5/2)*Sqrt[d]*ArcTanh[(Sqrt[d]*Sqrt[a + b*x])/(Sqrt[b]*Sqrt[c + d*x])]}
{((a + b*x)^(5/2)*Sqrt[c + d*x])/x^5, x, 5, (-5*(b*c - a*d)^3*Sqrt[a + b*x]*Sqrt[c + d*x])/(64*a*c^3*x) - (5*(b*c - a*d)^2*Sqrt[a + b*x]*(c + d*x)^(3/2))/(32*c^3*x^2) - (5*(b*c - a*d)*(a + b*x)^(3/2)*(c + d*x)^(3/2))/(24*c^2*x^3) - ((a + b*x)^(5/2)*(c + d*x)^(3/2))/(4*c*x^4) + (5*(b*c - a*d)^4*ArcTanh[(Sqrt[c]*Sqrt[a + b*x])/(Sqrt[a]*Sqrt[c + d*x])])/(64*a^(3/2)*c^(7/2))}
{((a + b*x)^(5/2)*Sqrt[c + d*x])/x^6, x, 7, -(((3*b*c - a*d)*(5*b*c + 7*a*d)*Sqrt[a + b*x]*Sqrt[c + d*x])/(240*c^2*x^3)) - ((15*b^3*c^3 + 109*a*b^2*c^2*d - 111*a^2*b*c*d^2 + 35*a^3*d^3)*Sqrt[a + b*x]*Sqrt[c + d*x])/(960*a*c^3*x^2) + ((45*b^4*c^4 - 60*a*b^3*c^3*d + 346*a^2*b^2*c^2*d^2 - 340*a^3*b*c*d^3 + 105*a^4*d^4)*Sqrt[a + b*x]*Sqrt[c + d*x])/(1920*a^2*c^4*x) - ((5*b*c + a*d)*(a + b*x)^(3/2)*Sqrt[c + d*x])/(40*c*x^4) - ((a + b*x)^(5/2)*Sqrt[c + d*x])/(5*x^5) - ((b*c - a*d)^4*(3*b*c + 7*a*d)*ArcTanh[(Sqrt[c]*Sqrt[a + b*x])/(Sqrt[a]*Sqrt[c + d*x])])/(128*a^(5/2)*c^(9/2))}


{x^2*(a + b*x)^(5/2)*(c + d*x)^(3/2), x, 8, ((b*c - a*d)^4*(9*b^2*c^2 + 10*a*b*c*d + 5*a^2*d^2)*Sqrt[a + b*x]*Sqrt[c + d*x])/(1024*b^4*d^5) - ((b*c - a*d)^3*(9*b^2*c^2 + 10*a*b*c*d + 5*a^2*d^2)*(a + b*x)^(3/2)*Sqrt[c + d*x])/(1536*b^4*d^4) + ((b*c - a*d)^2*(9*b^2*c^2 + 10*a*b*c*d + 5*a^2*d^2)*(a + b*x)^(5/2)*Sqrt[c + d*x])/(1920*b^4*d^3) + ((b*c - a*d)*(9*b^2*c^2 + 10*a*b*c*d + 5*a^2*d^2)*(a + b*x)^(7/2)*Sqrt[c + d*x])/(320*b^4*d^2) + ((9*b^2*c^2 + 10*a*b*c*d + 5*a^2*d^2)*(a + b*x)^(7/2)*(c + d*x)^(3/2))/(120*b^3*d^2) - ((9*b*c + 7*a*d)*(a + b*x)^(7/2)*(c + d*x)^(5/2))/(84*b^2*d^2) + (x*(a + b*x)^(7/2)*(c + d*x)^(5/2))/(7*b*d) - ((b*c - a*d)^5*(9*b^2*c^2 + 10*a*b*c*d + 5*a^2*d^2)*ArcTanh[(Sqrt[d]*Sqrt[a + b*x])/(Sqrt[b]*Sqrt[c + d*x])])/(1024*b^(9/2)*d^(11/2))}
{x*(a + b*x)^(5/2)*(c + d*x)^(3/2), x, 7, -((b*c - a*d)^4*(7*b*c + 5*a*d)*Sqrt[a + b*x]*Sqrt[c + d*x])/(512*b^3*d^4) + ((b*c - a*d)^3*(7*b*c + 5*a*d)*(a + b*x)^(3/2)*Sqrt[c + d*x])/(768*b^3*d^3) - ((b*c - a*d)^2*(7*b*c + 5*a*d)*(a + b*x)^(5/2)*Sqrt[c + d*x])/(960*b^3*d^2) - ((b*c - a*d)*(7*b*c + 5*a*d)*(a + b*x)^(7/2)*Sqrt[c + d*x])/(160*b^3*d) - ((7*b*c + 5*a*d)*(a + b*x)^(7/2)*(c + d*x)^(3/2))/(60*b^2*d) + ((a + b*x)^(7/2)*(c + d*x)^(5/2))/(6*b*d) + ((b*c - a*d)^5*(7*b*c + 5*a*d)*ArcTanh[(Sqrt[d]*Sqrt[a + b*x])/(Sqrt[b]*Sqrt[c + d*x])])/(512*b^(7/2)*d^(9/2))}
{(a + b*x)^(5/2)*(c + d*x)^(3/2), x, 6, (3*(b*c - a*d)^4*Sqrt[a + b*x]*Sqrt[c + d*x])/(128*b^2*d^3) - ((b*c - a*d)^3*(a + b*x)^(3/2)*Sqrt[c + d*x])/(64*b^2*d^2) + ((b*c - a*d)^2*(a + b*x)^(5/2)*Sqrt[c + d*x])/(80*b^2*d) + (3*(b*c - a*d)*(a + b*x)^(7/2)*Sqrt[c + d*x])/(40*b^2) + ((a + b*x)^(7/2)*(c + d*x)^(3/2))/(5*b) - (3*(b*c - a*d)^5*ArcTanh[(Sqrt[d]*Sqrt[a + b*x])/(Sqrt[b]*Sqrt[c + d*x])])/(128*b^(5/2)*d^(7/2))}
{((a + b*x)^(5/2)*(c + d*x)^(3/2))/x, x, 7, ((3*b^3*c^3 - 17*a*b^2*c^2*d + 73*a^2*b*c*d^2 + 5*a^3*d^3)*Sqrt[a + b*x]*Sqrt[c + d*x])/(64*b*d^2) - ((b*c - 5*a*d)*(3*b*c + a*d)*Sqrt[a + b*x]*(c + d*x)^(3/2))/(32*d^2) + ((3*b*c + 5*a*d)*(a + b*x)^(3/2)*(c + d*x)^(3/2))/(24*d) + (1/4)*(a + b*x)^(5/2)*(c + d*x)^(3/2) - 2*a^(5/2)*c^(3/2)*ArcTanh[(Sqrt[c]*Sqrt[a + b*x])/(Sqrt[a]*Sqrt[c + d*x])] + ((3*b^4*c^4 - 20*a*b^3*c^3*d + 90*a^2*b^2*c^2*d^2 + 60*a^3*b*c*d^3 - 5*a^4*d^4)*ArcTanh[(Sqrt[d]*Sqrt[a + b*x])/(Sqrt[b]*Sqrt[c + d*x])])/(64*b^(3/2)*d^(5/2))}
{((a + b*x)^(5/2)*(c + d*x)^(3/2))/x^2, x, 7, -((b^2*c^2 - 14*a*b*c*d - 19*a^2*d^2)*Sqrt[a + b*x]*Sqrt[c + d*x])/(8*d) + (b*(b*c + 7*a*d)*Sqrt[a + b*x]*(c + d*x)^(3/2))/(4*d) + (4*b*(a + b*x)^(3/2)*(c + d*x)^(3/2))/3 - ((a + b*x)^(5/2)*(c + d*x)^(3/2))/x - a^(3/2)*Sqrt[c]*(5*b*c + 3*a*d)*ArcTanh[(Sqrt[c]*Sqrt[a + b*x])/(Sqrt[a]*Sqrt[c + d*x])] - ((b^3*c^3 - 15*a*b^2*c^2*d - 45*a^2*b*c*d^2 - 5*a^3*d^3)*ArcTanh[(Sqrt[d]*Sqrt[a + b*x])/(Sqrt[b]*Sqrt[c + d*x])])/(8*Sqrt[b]*d^(3/2))}
{((a + b*x)^(5/2)*(c + d*x)^(3/2))/x^3, x, 7, (3*(b^2*c^2 + 6*a*b*c*d + a^2*d^2)*Sqrt[a + b*x]*Sqrt[c + d*x])/(4*c) + (3*b*(3*b*c + a*d)*Sqrt[a + b*x]*(c + d*x)^(3/2))/(4*c) - ((5*b*c + 3*a*d)*(a + b*x)^(3/2)*(c + d*x)^(3/2))/(4*c*x) - ((a + b*x)^(5/2)*(c + d*x)^(3/2))/(2*x^2) - (3*Sqrt[a]*(5*b^2*c^2 + 10*a*b*c*d + a^2*d^2)*ArcTanh[(Sqrt[c]*Sqrt[a + b*x])/(Sqrt[a]*Sqrt[c + d*x])])/(4*Sqrt[c]) + (3*Sqrt[b]*(b^2*c^2 + 10*a*b*c*d + 5*a^2*d^2)*ArcTanh[(Sqrt[d]*Sqrt[a + b*x])/(Sqrt[b]*Sqrt[c + d*x])])/(4*Sqrt[d])}
{((a + b*x)^(5/2)*(c + d*x)^(3/2))/x^4, x, 7, (d*(19*b^2*c^2 + 14*a*b*c*d - a^2*d^2)*Sqrt[a + b*x]*Sqrt[c + d*x])/(8*c^2) - ((5*b^2*c^2 + 12*a*b*c*d - a^2*d^2)*Sqrt[a + b*x]*(c + d*x)^(3/2))/(8*c^2*x) - ((5*b*c + 3*a*d)*(a + b*x)^(3/2)*(c + d*x)^(3/2))/(12*c*x^2) - ((a + b*x)^(5/2)*(c + d*x)^(3/2))/(3*x^3) - ((5*b^3*c^3 + 45*a*b^2*c^2*d + 15*a^2*b*c*d^2 - a^3*d^3)*ArcTanh[(Sqrt[c]*Sqrt[a + b*x])/(Sqrt[a]*Sqrt[c + d*x])])/(8*Sqrt[a]*c^(3/2)) + b^(3/2)*Sqrt[d]*(3*b*c + 5*a*d)*ArcTanh[(Sqrt[d]*Sqrt[a + b*x])/(Sqrt[b]*Sqrt[c + d*x])]}
{((a + b*x)^(5/2)*(c + d*x)^(3/2))/x^5, x, 7, -(((5*b^3*c^3 + 73*a*b^2*c^2*d - 17*a^2*b*c*d^2 + 3*a^3*d^3)*Sqrt[a + b*x]*Sqrt[c + d*x])/(64*a*c^2*x)) - ((5*b*c - a*d)*(b*c + 3*a*d)*Sqrt[a + b*x]*(c + d*x)^(3/2))/(32*c^2*x^2) - ((5*b*c + 3*a*d)*(a + b*x)^(3/2)*(c + d*x)^(3/2))/(24*c*x^3) - ((a + b*x)^(5/2)*(c + d*x)^(3/2))/(4*x^4) + ((5*b^4*c^4 - 60*a*b^3*c^3*d - 90*a^2*b^2*c^2*d^2 + 20*a^3*b*c*d^3 - 3*a^4*d^4)*ArcTanh[(Sqrt[c]*Sqrt[a + b*x])/(Sqrt[a]*Sqrt[c + d*x])])/(64*a^(3/2)*c^(5/2)) + 2*b^(5/2)*d^(3/2)*ArcTanh[(Sqrt[d]*Sqrt[a + b*x])/(Sqrt[b]*Sqrt[c + d*x])]}
{((a + b*x)^(5/2)*(c + d*x)^(3/2))/x^6, x, 6, (3*(b*c - a*d)^4*Sqrt[a + b*x]*Sqrt[c + d*x])/(128*a^2*c^3*x) - ((b*c - a*d)^3*Sqrt[a + b*x]*(c + d*x)^(3/2))/(64*a*c^3*x^2) - ((b*c - a*d)^2*Sqrt[a + b*x]*(c + d*x)^(5/2))/(16*c^3*x^3) - ((b*c - a*d)*(a + b*x)^(3/2)*(c + d*x)^(5/2))/(8*c^2*x^4) - ((a + b*x)^(5/2)*(c + d*x)^(5/2))/(5*c*x^5) - (3*(b*c - a*d)^5*ArcTanh[(Sqrt[c]*Sqrt[a + b*x])/(Sqrt[a]*Sqrt[c + d*x])])/(128*a^(5/2)*c^(7/2))}


{x*(a + b*x)^(5/2)*(c + d*x)^(5/2), x, 8, (-5*(b*c - a*d)^5*(b*c + a*d)*Sqrt[a + b*x]*Sqrt[c + d*x])/(1024*b^4*d^4) + (5*(b*c - a*d)^4*(b*c + a*d)*(a + b*x)^(3/2)*Sqrt[c + d*x])/(1536*b^4*d^3) - ((b*c - a*d)^3*(b*c + a*d)*(a + b*x)^(5/2)*Sqrt[c + d*x])/(384*b^4*d^2) - ((b*c - a*d)^2*(b*c + a*d)*(a + b*x)^(7/2)*Sqrt[c + d*x])/(64*b^4*d) - ((b*c - a*d)*(b*c + a*d)*(a + b*x)^(7/2)*(c + d*x)^(3/2))/(24*b^3*d) - ((b*c + a*d)*(a + b*x)^(7/2)*(c + d*x)^(5/2))/(12*b^2*d) + ((a + b*x)^(7/2)*(c + d*x)^(7/2))/(7*b*d) + (5*(b*c - a*d)^6*(b*c + a*d)*ArcTanh[(Sqrt[d]*Sqrt[a + b*x])/(Sqrt[b]*Sqrt[c + d*x])])/(1024*b^(9/2)*d^(9/2))}
{(a + b*x)^(5/2)*(c + d*x)^(5/2), x, 7, (5*(b*c - a*d)^5*Sqrt[a + b*x]*Sqrt[c + d*x])/(512*b^3*d^3) - (5*(b*c - a*d)^4*(a + b*x)^(3/2)*Sqrt[c + d*x])/(768*b^3*d^2) + ((b*c - a*d)^3*(a + b*x)^(5/2)*Sqrt[c + d*x])/(192*b^3*d) + ((b*c - a*d)^2*(a + b*x)^(7/2)*Sqrt[c + d*x])/(32*b^3) + ((b*c - a*d)*(a + b*x)^(7/2)*(c + d*x)^(3/2))/(12*b^2) + ((a + b*x)^(7/2)*(c + d*x)^(5/2))/(6*b) - (5*(b*c - a*d)^6*ArcTanh[(Sqrt[d]*Sqrt[a + b*x])/(Sqrt[b]*Sqrt[c + d*x])])/(512*b^(7/2)*d^(7/2))}
{((a + b*x)^(5/2)*(c + d*x)^(5/2))/x, x, 8, ((3*b^4*c^4 - 22*a*b^3*c^3*d + 128*a^2*b^2*c^2*d^2 + 22*a^3*b*c*d^3 - 3*a^4*d^4)*Sqrt[a + b*x]*Sqrt[c + d*x])/(128*b^2*d^2) + ((3*b^3*c^3 - 19*a*b^2*c^2*d + 109*a^2*b*c*d^2 + 3*a^3*d^3)*Sqrt[a + b*x]*(c + d*x)^(3/2))/(192*b*d^2) - ((3*b^2*c^2 - 16*a*b*c*d - 3*a^2*d^2)*Sqrt[a + b*x]*(c + d*x)^(5/2))/(48*d^2) + ((b*c + a*d)*(a + b*x)^(3/2)*(c + d*x)^(5/2))/(8*d) + (1/5)*(a + b*x)^(5/2)*(c + d*x)^(5/2) - 2*a^(5/2)*c^(5/2)*ArcTanh[(Sqrt[c]*Sqrt[a + b*x])/(Sqrt[a]*Sqrt[c + d*x])] + ((b*c + a*d)*(3*b^4*c^4 - 28*a*b^3*c^3*d + 178*a^2*b^2*c^2*d^2 - 28*a^3*b*c*d^3 + 3*a^4*d^4)*ArcTanh[(Sqrt[d]*Sqrt[a + b*x])/(Sqrt[b]*Sqrt[c + d*x])])/(128*b^(5/2)*d^(5/2))}
{((a + b*x)^(5/2)*(c + d*x)^(5/2))/x^2, x, 8, (-5*(b^3*c^3 - 19*a*b^2*c^2*d - 45*a^2*b*c*d^2 - a^3*d^3)*Sqrt[a + b*x]*Sqrt[c + d*x])/(64*b*d) - (5*(b^2*c^2 - 18*a*b*c*d - 31*a^2*d^2)*Sqrt[a + b*x]*(c + d*x)^(3/2))/(96*d) + (5*b*(b*c + 7*a*d)*Sqrt[a + b*x]*(c + d*x)^(5/2))/(24*d) + (5*b*(a + b*x)^(3/2)*(c + d*x)^(5/2))/4 - ((a + b*x)^(5/2)*(c + d*x)^(5/2))/x - 5*a^(3/2)*c^(3/2)*(b*c + a*d)*ArcTanh[(Sqrt[c]*Sqrt[a + b*x])/(Sqrt[a]*Sqrt[c + d*x])] - (5*(b^4*c^4 - 20*a*b^3*c^3*d - 90*a^2*b^2*c^2*d^2 - 20*a^3*b*c*d^3 + a^4*d^4)*ArcTanh[(Sqrt[d]*Sqrt[a + b*x])/(Sqrt[b]*Sqrt[c + d*x])])/(64*b^(3/2)*d^(3/2))}
{((a + b*x)^(5/2)*(c + d*x)^(5/2))/x^3, x, 8, (5/8)*(b^2*c^2 + 10*a*b*c*d + 5*a^2*d^2)*Sqrt[a + b*x]*Sqrt[c + d*x] + (5*(b^2*c^2 + 8*a*b*c*d + 3*a^2*d^2)*Sqrt[a + b*x]*(c + d*x)^(3/2))/(12*c) + (5*b*(5*b*c + 3*a*d)*Sqrt[a + b*x]*(c + d*x)^(5/2))/(12*c) - (5*(b*c + a*d)*(a + b*x)^(3/2)*(c + d*x)^(5/2))/(4*c*x) - ((a + b*x)^(5/2)*(c + d*x)^(5/2))/(2*x^2) - (5/4)*Sqrt[a]*Sqrt[c]*(3*b*c + a*d)*(b*c + 3*a*d)*ArcTanh[(Sqrt[c]*Sqrt[a + b*x])/(Sqrt[a]*Sqrt[c + d*x])] + (5*(b*c + a*d)*(b^2*c^2 + 14*a*b*c*d + a^2*d^2)*ArcTanh[(Sqrt[d]*Sqrt[a + b*x])/(Sqrt[b]*Sqrt[c + d*x])])/(8*Sqrt[b]*Sqrt[d])}
{((a + b*x)^(5/2)*(c + d*x)^(5/2))/x^4, x, 8, (5*d*(5*b^2*c^2 + 10*a*b*c*d + a^2*d^2)*Sqrt[a + b*x]*Sqrt[c + d*x])/(8*c) + (5*d*(9*b^2*c^2 + 14*a*b*c*d + a^2*d^2)*Sqrt[a + b*x]*(c + d*x)^(3/2))/(24*c^2) - (5*(3*b^2*c^2 + 12*a*b*c*d + a^2*d^2)*Sqrt[a + b*x]*(c + d*x)^(5/2))/(24*c^2*x) - (5*(b*c + a*d)*(a + b*x)^(3/2)*(c + d*x)^(5/2))/(12*c*x^2) - ((a + b*x)^(5/2)*(c + d*x)^(5/2))/(3*x^3) - (5*(b*c + a*d)*(b^2*c^2 + 14*a*b*c*d + a^2*d^2)*ArcTanh[(Sqrt[c]*Sqrt[a + b*x])/(Sqrt[a]*Sqrt[c + d*x])])/(8*Sqrt[a]*Sqrt[c]) + (5/4)*Sqrt[b]*Sqrt[d]*(3*b*c + a*d)*(b*c + 3*a*d)*ArcTanh[(Sqrt[d]*Sqrt[a + b*x])/(Sqrt[b]*Sqrt[c + d*x])]}
{((a + b*x)^(5/2)*(c + d*x)^(5/2))/x^5, x, 8, (5*d*(b^3*c^3 + 45*a*b^2*c^2*d + 19*a^2*b*c*d^2 - a^3*d^3)*Sqrt[a + b*x]*Sqrt[c + d*x])/(64*a*c^2) - (5*(3*b*c + a*d)*(b^2*c^2 + 24*a*b*c*d - a^2*d^2)*Sqrt[a + b*x]*(c + d*x)^(3/2))/(192*a*c^2*x) - (5*(3*b^2*c^2 + 14*a*b*c*d - a^2*d^2)*Sqrt[a + b*x]*(c + d*x)^(5/2))/(96*c^2*x^2) - (5*(b*c + a*d)*(a + b*x)^(3/2)*(c + d*x)^(5/2))/(24*c*x^3) - ((a + b*x)^(5/2)*(c + d*x)^(5/2))/(4*x^4) + (5*(b^4*c^4 - 20*a*b^3*c^3*d - 90*a^2*b^2*c^2*d^2 - 20*a^3*b*c*d^3 + a^4*d^4)*ArcTanh[(Sqrt[c]*Sqrt[a + b*x])/(Sqrt[a]*Sqrt[c + d*x])])/(64*a^(3/2)*c^(3/2)) + 5*b^(3/2)*d^(3/2)*(b*c + a*d)*ArcTanh[(Sqrt[d]*Sqrt[a + b*x])/(Sqrt[b]*Sqrt[c + d*x])]}
{((a + b*x)^(5/2)*(c + d*x)^(5/2))/x^6, x, 8, ((3*b^4*c^4 - 22*a*b^3*c^3*d - 128*a^2*b^2*c^2*d^2 + 22*a^3*b*c*d^3 - 3*a^4*d^4)*Sqrt[a + b*x]*Sqrt[c + d*x])/(128*a^2*c^2*x) - ((3*b^3*c^3 + 109*a*b^2*c^2*d - 19*a^2*b*c*d^2 + 3*a^3*d^3)*Sqrt[a + b*x]*(c + d*x)^(3/2))/(192*a*c^2*x^2) - ((3*b^2*c^2 + 16*a*b*c*d - 3*a^2*d^2)*Sqrt[a + b*x]*(c + d*x)^(5/2))/(48*c^2*x^3) - ((b*c + a*d)*(a + b*x)^(3/2)*(c + d*x)^(5/2))/(8*c*x^4) - ((a + b*x)^(5/2)*(c + d*x)^(5/2))/(5*x^5) - ((b*c + a*d)*(3*b^4*c^4 - 28*a*b^3*c^3*d + 178*a^2*b^2*c^2*d^2 - 28*a^3*b*c*d^3 + 3*a^4*d^4)*ArcTanh[(Sqrt[c]*Sqrt[a + b*x])/(Sqrt[a]*Sqrt[c + d*x])])/(128*a^(5/2)*c^(5/2)) + 2*b^(5/2)*d^(5/2)*ArcTanh[(Sqrt[d]*Sqrt[a + b*x])/(Sqrt[b]*Sqrt[c + d*x])]}
{((a + b*x)^(5/2)*(c + d*x)^(5/2))/x^7, x, 7, (-5*(b*c - a*d)^5*Sqrt[a + b*x]*Sqrt[c + d*x])/(512*a^3*c^3*x) + (5*(b*c - a*d)^4*Sqrt[a + b*x]*(c + d*x)^(3/2))/(768*a^2*c^3*x^2) - ((b*c - a*d)^3*Sqrt[a + b*x]*(c + d*x)^(5/2))/(192*a*c^3*x^3) - ((b*c - a*d)^2*Sqrt[a + b*x]*(c + d*x)^(7/2))/(32*c^3*x^4) - ((b*c - a*d)*(a + b*x)^(3/2)*(c + d*x)^(7/2))/(12*c^2*x^5) - ((a + b*x)^(5/2)*(c + d*x)^(7/2))/(6*c*x^6) + (5*(b*c - a*d)^6*ArcTanh[(Sqrt[c]*Sqrt[a + b*x])/(Sqrt[a]*Sqrt[c + d*x])])/(512*a^(7/2)*c^(7/2))}


(* ::Subsubsection::Closed:: *)
(*n<0*)


{(x^2*(a + b*x)^(5/2))/Sqrt[c + d*x], x, 6, ((b*c - a*d)^2*(63*b^2*c^2 + 14*a*b*c*d + 3*a^2*d^2)*Sqrt[a + b*x]*Sqrt[c + d*x])/(128*b^2*d^5) - ((b*c - a*d)*(63*b^2*c^2 + 14*a*b*c*d + 3*a^2*d^2)*(a + b*x)^(3/2)*Sqrt[c + d*x])/(192*b^2*d^4) + ((63*b^2*c^2 + 14*a*b*c*d + 3*a^2*d^2)*(a + b*x)^(5/2)*Sqrt[c + d*x])/(240*b^2*d^3) - (3*(3*b*c + a*d)*(a + b*x)^(7/2)*Sqrt[c + d*x])/(40*b^2*d^2) + (x*(a + b*x)^(7/2)*Sqrt[c + d*x])/(5*b*d) - ((b*c - a*d)^3*(63*b^2*c^2 + 14*a*b*c*d + 3*a^2*d^2)*ArcTanh[(Sqrt[d]*Sqrt[a + b*x])/(Sqrt[b]*Sqrt[c + d*x])])/(128*b^(5/2)*d^(11/2))}
{(x*(a + b*x)^(5/2))/Sqrt[c + d*x], x, 5, (-5*(b*c - a*d)^2*(7*b*c + a*d)*Sqrt[a + b*x]*Sqrt[c + d*x])/(64*b*d^4) + (5*(b*c - a*d)*(7*b*c + a*d)*(a + b*x)^(3/2)*Sqrt[c + d*x])/(96*b*d^3) - ((7*b*c + a*d)*(a + b*x)^(5/2)*Sqrt[c + d*x])/(24*b*d^2) + ((a + b*x)^(7/2)*Sqrt[c + d*x])/(4*b*d) + (5*(b*c - a*d)^3*(7*b*c + a*d)*ArcTanh[(Sqrt[d]*Sqrt[a + b*x])/(Sqrt[b]*Sqrt[c + d*x])])/(64*b^(3/2)*d^(9/2))}
{(a + b*x)^(5/2)/Sqrt[c + d*x], x, 4, (5*(b*c - a*d)^2*Sqrt[a + b*x]*Sqrt[c + d*x])/(8*d^3) - (5*(b*c - a*d)*(a + b*x)^(3/2)*Sqrt[c + d*x])/(12*d^2) + ((a + b*x)^(5/2)*Sqrt[c + d*x])/(3*d) - (5*(b*c - a*d)^3*ArcTanh[(Sqrt[d]*Sqrt[a + b*x])/(Sqrt[b]*Sqrt[c + d*x])])/(8*Sqrt[b]*d^(7/2))}
{(a + b*x)^(5/2)/(x*Sqrt[c + d*x]), x, 5, -(b*(3*b*c - 7*a*d)*Sqrt[a + b*x]*Sqrt[c + d*x])/(4*d^2) + (b*(a + b*x)^(3/2)*Sqrt[c + d*x])/(2*d) - (2*a^(5/2)*ArcTanh[(Sqrt[c]*Sqrt[a + b*x])/(Sqrt[a]*Sqrt[c + d*x])])/Sqrt[c] + (Sqrt[b]*(3*b^2*c^2 - 10*a*b*c*d + 15*a^2*d^2)*ArcTanh[(Sqrt[d]*Sqrt[a + b*x])/(Sqrt[b]*Sqrt[c + d*x])])/(4*d^(5/2))}
{(a + b*x)^(5/2)/(x^2*Sqrt[c + d*x]), x, 6, (b*(b*c + a*d)*Sqrt[a + b*x]*Sqrt[c + d*x])/(c*d) + (b*(a + b*x)^(3/2)*Sqrt[c + d*x])/c - ((a + b*x)^(5/2)*Sqrt[c + d*x])/(c*x) - (a^(3/2)*(5*b*c - a*d)*ArcTanh[(Sqrt[c]*Sqrt[a + b*x])/(Sqrt[a]*Sqrt[c + d*x])])/c^(3/2) - (b^(3/2)*(b*c - 5*a*d)*ArcTanh[(Sqrt[d]*Sqrt[a + b*x])/(Sqrt[b]*Sqrt[c + d*x])])/d^(3/2)}
{(a + b*x)^(5/2)/(x^3*Sqrt[c + d*x]), x, 6, (b*(7*b*c - 3*a*d)*Sqrt[a + b*x]*Sqrt[c + d*x])/(4*c^2) - ((5*b*c - 3*a*d)*(a + b*x)^(3/2)*Sqrt[c + d*x])/(4*c^2*x) - ((a + b*x)^(5/2)*Sqrt[c + d*x])/(2*c*x^2) - (Sqrt[a]*(15*b^2*c^2 - 10*a*b*c*d + 3*a^2*d^2)*ArcTanh[(Sqrt[c]*Sqrt[a + b*x])/(Sqrt[a]*Sqrt[c + d*x])])/(4*c^(5/2)) + (2*b^(5/2)*ArcTanh[(Sqrt[d]*Sqrt[a + b*x])/(Sqrt[b]*Sqrt[c + d*x])])/Sqrt[d]}
{(a + b*x)^(5/2)/(x^4*Sqrt[c + d*x]), x, 4, (-5*(b*c - a*d)^2*Sqrt[a + b*x]*Sqrt[c + d*x])/(8*c^3*x) - (5*(b*c - a*d)*(a + b*x)^(3/2)*Sqrt[c + d*x])/(12*c^2*x^2) - ((a + b*x)^(5/2)*Sqrt[c + d*x])/(3*c*x^3) - (5*(b*c - a*d)^3*ArcTanh[(Sqrt[c]*Sqrt[a + b*x])/(Sqrt[a]*Sqrt[c + d*x])])/(8*Sqrt[a]*c^(7/2))}
{(a + b*x)^(5/2)/(x^5*Sqrt[c + d*x]), x, 6, -(((15*b^2*c^2 - 58*a*b*c*d + 35*a^2*d^2)*Sqrt[a + b*x]*Sqrt[c + d*x])/(96*c^3*x^2)) - ((15*b^3*c^3 - 191*a*b^2*c^2*d + 265*a^2*b*c*d^2 - 105*a^3*d^3)*Sqrt[a + b*x]*Sqrt[c + d*x])/(192*a*c^4*x) - ((5*b*c - 7*a*d)*(a + b*x)^(3/2)*Sqrt[c + d*x])/(24*c^2*x^3) - ((a + b*x)^(5/2)*Sqrt[c + d*x])/(4*c*x^4) + (5*(b*c - a*d)^3*(b*c + 7*a*d)*ArcTanh[(Sqrt[c]*Sqrt[a + b*x])/(Sqrt[a]*Sqrt[c + d*x])])/(64*a^(3/2)*c^(9/2))}


{(x^2*(a + b*x)^(5/2))/(c + d*x)^(3/2), x, 6, (2*c^2*(a + b*x)^(7/2))/(d^2*(b*c - a*d)*Sqrt[c + d*x]) - (5*(b*c - a*d)*(63*b^2*c^2 - 14*a*b*c*d - a^2*d^2)*Sqrt[a + b*x]*Sqrt[c + d*x])/(64*b*d^5) + (5*(63*b^2*c^2 - 14*a*b*c*d - a^2*d^2)*(a + b*x)^(3/2)*Sqrt[c + d*x])/(96*b*d^4) + ((14*a*c - (63*b*c^2)/d + (a^2*d)/b)*(a + b*x)^(5/2)*Sqrt[c + d*x])/(24*d^2*(b*c - a*d)) + ((a + b*x)^(7/2)*Sqrt[c + d*x])/(4*b*d^2) + (5*(b*c - a*d)^2*(63*b^2*c^2 - 14*a*b*c*d - a^2*d^2)*ArcTanh[(Sqrt[d]*Sqrt[a + b*x])/(Sqrt[b]*Sqrt[c + d*x])])/(64*b^(3/2)*d^(11/2))}
{(x*(a + b*x)^(5/2))/(c + d*x)^(3/2), x, 5, (-2*c*(a + b*x)^(7/2))/(d*(b*c - a*d)*Sqrt[c + d*x]) + (5*(b*c - a*d)*(7*b*c - a*d)*Sqrt[a + b*x]*Sqrt[c + d*x])/(8*d^4) - (5*(7*b*c - a*d)*(a + b*x)^(3/2)*Sqrt[c + d*x])/(12*d^3) + ((7*b*c - a*d)*(a + b*x)^(5/2)*Sqrt[c + d*x])/(3*d^2*(b*c - a*d)) - (5*(b*c - a*d)^2*(7*b*c - a*d)*ArcTanh[(Sqrt[d]*Sqrt[a + b*x])/(Sqrt[b]*Sqrt[c + d*x])])/(8*Sqrt[b]*d^(9/2))}
{(a + b*x)^(5/2)/(c + d*x)^(3/2), x, 4, (-2*(a + b*x)^(5/2))/(d*Sqrt[c + d*x]) - (15*b*(b*c - a*d)*Sqrt[a + b*x]*Sqrt[c + d*x])/(4*d^3) + (5*b*(a + b*x)^(3/2)*Sqrt[c + d*x])/(2*d^2) + (15*Sqrt[b]*(b*c - a*d)^2*ArcTanh[(Sqrt[d]*Sqrt[a + b*x])/(Sqrt[b]*Sqrt[c + d*x])])/(4*d^(7/2))}
{(a + b*x)^(5/2)/(x*(c + d*x)^(3/2)), x, 6, (2*(a + b*x)^(5/2))/(c*Sqrt[c + d*x]) + (b*(3*b*c - 2*a*d)*Sqrt[a + b*x]*Sqrt[c + d*x])/(c*d^2) - (2*b*(a + b*x)^(3/2)*Sqrt[c + d*x])/(c*d) - (2*a^(5/2)*ArcTanh[(Sqrt[c]*Sqrt[a + b*x])/(Sqrt[a]*Sqrt[c + d*x])])/c^(3/2) - (b^(3/2)*(3*b*c - 5*a*d)*ArcTanh[(Sqrt[d]*Sqrt[a + b*x])/(Sqrt[b]*Sqrt[c + d*x])])/d^(5/2)}
{(a + b*x)^(5/2)/(x^2*(c + d*x)^(3/2)), x, 6, (3*(b*c - a*d)*(a + b*x)^(3/2))/(c^2*Sqrt[c + d*x]) - (a + b*x)^(5/2)/(c*x*Sqrt[c + d*x]) - (b*(2*b*c - 3*a*d)*Sqrt[a + b*x]*Sqrt[c + d*x])/(c^2*d) - (a^(3/2)*(5*b*c - 3*a*d)*ArcTanh[(Sqrt[c]*Sqrt[a + b*x])/(Sqrt[a]*Sqrt[c + d*x])])/c^(5/2) + (2*b^(5/2)*ArcTanh[(Sqrt[d]*Sqrt[a + b*x])/(Sqrt[b]*Sqrt[c + d*x])])/d^(3/2)}
{(a + b*x)^(5/2)/(x^3*(c + d*x)^(3/2)), x, 4, (15*(b*c - a*d)^2*Sqrt[a + b*x])/(4*c^3*Sqrt[c + d*x]) - (5*(b*c - a*d)*(a + b*x)^(3/2))/(4*c^2*x*Sqrt[c + d*x]) - (a + b*x)^(5/2)/(2*c*x^2*Sqrt[c + d*x]) - (15*Sqrt[a]*(b*c - a*d)^2*ArcTanh[(Sqrt[c]*Sqrt[a + b*x])/(Sqrt[a]*Sqrt[c + d*x])])/(4*c^(7/2))}
{(a + b*x)^(5/2)/(x^4*(c + d*x)^(3/2)), x, 6, -((d*(81*b^2*c^2 - 190*a*b*c*d + 105*a^2*d^2)*Sqrt[a + b*x])/(24*c^4*Sqrt[c + d*x])) - ((15*b^2*c^2 - 54*a*b*c*d + 35*a^2*d^2)*Sqrt[a + b*x])/(24*c^3*x*Sqrt[c + d*x]) - ((5*b*c - 7*a*d)*(a + b*x)^(3/2))/(12*c^2*x^2*Sqrt[c + d*x]) - (a + b*x)^(5/2)/(3*c*x^3*Sqrt[c + d*x]) - (5*(b*c - 7*a*d)*(b*c - a*d)^2*ArcTanh[(Sqrt[c]*Sqrt[a + b*x])/(Sqrt[a]*Sqrt[c + d*x])])/(8*Sqrt[a]*c^(9/2))}
{(a + b*x)^(5/2)/(x^5*(c + d*x)^(3/2)), x, 7, -((d*(15*b^3*c^3 - 839*a*b^2*c^2*d + 1785*a^2*b*c*d^2 - 945*a^3*d^3)*Sqrt[a + b*x])/(192*a*c^5*Sqrt[c + d*x])) - ((15*b^2*c^2 - 86*a*b*c*d + 63*a^2*d^2)*Sqrt[a + b*x])/(96*c^3*x^2*Sqrt[c + d*x]) - ((b*c - a*d)*(15*b^2*c^2 - 322*a*b*c*d + 315*a^2*d^2)*Sqrt[a + b*x])/(192*a*c^4*x*Sqrt[c + d*x]) - ((5*b*c - 9*a*d)*(a + b*x)^(3/2))/(24*c^2*x^3*Sqrt[c + d*x]) - (a + b*x)^(5/2)/(4*c*x^4*Sqrt[c + d*x]) + (5*(b*c - a*d)^2*(b^2*c^2 + 14*a*b*c*d - 63*a^2*d^2)*ArcTanh[(Sqrt[c]*Sqrt[a + b*x])/(Sqrt[a]*Sqrt[c + d*x])])/(64*a^(3/2)*c^(11/2))}


{(x^3*(a + b*x)^(5/2))/(c + d*x)^(5/2), x, 7, (-2*x^3*(a + b*x)^(5/2))/(3*d*(c + d*x)^(3/2)) - (2*(11*b*c - 6*a*d)*x^2*(a + b*x)^(5/2))/(3*d^2*(b*c - a*d)*Sqrt[c + d*x]) - (5*(231*b^3*c^3 - 189*a*b^2*c^2*d + 21*a^2*b*c*d^2 + a^3*d^3)*Sqrt[a + b*x]*Sqrt[c + d*x])/(64*b*d^6) + (5*(231*b^3*c^3 - 189*a*b^2*c^2*d + 21*a^2*b*c*d^2 + a^3*d^3)*(a + b*x)^(3/2)*Sqrt[c + d*x])/(96*b*d^5*(b*c - a*d)) - ((231*b^2*c^2 - 156*a*b*c*d + 5*a^2*d^2)*(a + b*x)^(5/2)*Sqrt[c + d*x])/(24*b*d^4*(b*c - a*d)) + ((99*b*c - 59*a*d)*x*(a + b*x)^(5/2)*Sqrt[c + d*x])/(12*d^3*(b*c - a*d)) + (5*(b*c - a*d)*(231*b^3*c^3 - 189*a*b^2*c^2*d + 21*a^2*b*c*d^2 + a^3*d^3)*ArcTanh[(Sqrt[d]*Sqrt[a + b*x])/(Sqrt[b]*Sqrt[c + d*x])])/(64*b^(3/2)*d^(13/2))}
{(x^2*(a + b*x)^(5/2))/(c + d*x)^(5/2), x, 6, (2*c^2*(a + b*x)^(7/2))/(3*d^2*(b*c - a*d)*(c + d*x)^(3/2)) - (4*c*(5*b*c - 3*a*d)*(a + b*x)^(7/2))/(3*d^2*(b*c - a*d)^2*Sqrt[c + d*x]) + (5*(21*b^2*c^2 - 14*a*b*c*d + a^2*d^2)*Sqrt[a + b*x]*Sqrt[c + d*x])/(8*d^5) - (5*(21*b^2*c^2 - 14*a*b*c*d + a^2*d^2)*(a + b*x)^(3/2)*Sqrt[c + d*x])/(12*d^4*(b*c - a*d)) + ((21*b^2*c^2 - 14*a*b*c*d + a^2*d^2)*(a + b*x)^(5/2)*Sqrt[c + d*x])/(3*d^3*(b*c - a*d)^2) - (5*(b*c - a*d)*(21*b^2*c^2 - 14*a*b*c*d + a^2*d^2)*ArcTanh[(Sqrt[d]*Sqrt[a + b*x])/(Sqrt[b]*Sqrt[c + d*x])])/(8*Sqrt[b]*d^(11/2))}
{(x*(a + b*x)^(5/2))/(c + d*x)^(5/2), x, 5, (-2*c*(a + b*x)^(7/2))/(3*d*(b*c - a*d)*(c + d*x)^(3/2)) - (2*(7*b*c - 3*a*d)*(a + b*x)^(5/2))/(3*d^2*(b*c - a*d)*Sqrt[c + d*x]) - (5*b*(7*b*c - 3*a*d)*Sqrt[a + b*x]*Sqrt[c + d*x])/(4*d^4) + (5*b*(7*b*c - 3*a*d)*(a + b*x)^(3/2)*Sqrt[c + d*x])/(6*d^3*(b*c - a*d)) + (5*Sqrt[b]*(7*b*c - 3*a*d)*(b*c - a*d)*ArcTanh[(Sqrt[d]*Sqrt[a + b*x])/(Sqrt[b]*Sqrt[c + d*x])])/(4*d^(9/2))}
{(a + b*x)^(5/2)/(c + d*x)^(5/2), x, 4, (-2*(a + b*x)^(5/2))/(3*d*(c + d*x)^(3/2)) - (10*b*(a + b*x)^(3/2))/(3*d^2*Sqrt[c + d*x]) + (5*b^2*Sqrt[a + b*x]*Sqrt[c + d*x])/d^3 - (5*b^(3/2)*(b*c - a*d)*ArcTanh[(Sqrt[d]*Sqrt[a + b*x])/(Sqrt[b]*Sqrt[c + d*x])])/d^(7/2)}
{(a + b*x)^(5/2)/(x*(c + d*x)^(5/2)), x, 6, (2*(a + b*x)^(5/2))/(3*c*(c + d*x)^(3/2)) + (2*(2*b*c + 3*a*d)*(a + b*x)^(3/2))/(3*c^2*d*Sqrt[c + d*x]) - (2*b*(b*c + a*d)*Sqrt[a + b*x]*Sqrt[c + d*x])/(c^2*d^2) - (2*a^(5/2)*ArcTanh[(Sqrt[c]*Sqrt[a + b*x])/(Sqrt[a]*Sqrt[c + d*x])])/c^(5/2) + (2*b^(5/2)*ArcTanh[(Sqrt[d]*Sqrt[a + b*x])/(Sqrt[b]*Sqrt[c + d*x])])/d^(5/2)}
{(a + b*x)^(5/2)/(x^2*(c + d*x)^(5/2)), x, 4, (5*(b*c - a*d)*(a + b*x)^(3/2))/(3*c^2*(c + d*x)^(3/2)) - (a + b*x)^(5/2)/(c*x*(c + d*x)^(3/2)) + (5*a*(b*c - a*d)*Sqrt[a + b*x])/(c^3*Sqrt[c + d*x]) - (5*a^(3/2)*(b*c - a*d)*ArcTanh[(Sqrt[c]*Sqrt[a + b*x])/(Sqrt[a]*Sqrt[c + d*x])])/c^(7/2)}
{(a + b*x)^(5/2)/(x^3*(c + d*x)^(5/2)), x, 6, ((29*b*c - 35*a*d)*(b*c - a*d)*Sqrt[a + b*x])/(12*c^3*(c + d*x)^(3/2)) - ((5*b*c - 7*a*d)*(a + b*x)^(3/2))/(4*c^2*x*(c + d*x)^(3/2)) - (a + b*x)^(5/2)/(2*c*x^2*(c + d*x)^(3/2)) + ((16*b^2*c^2 - 115*a*b*c*d + 105*a^2*d^2)*Sqrt[a + b*x])/(12*c^4*Sqrt[c + d*x]) - (5*Sqrt[a]*(3*b*c - 7*a*d)*(b*c - a*d)*ArcTanh[(Sqrt[c]*Sqrt[a + b*x])/(Sqrt[a]*Sqrt[c + d*x])])/(4*c^(9/2))}
{(a + b*x)^(5/2)/(x^4*(c + d*x)^(5/2)), x, 7, -((7*d*(7*b*c - 15*a*d)*(b*c - a*d)*Sqrt[a + b*x])/(24*c^4*(c + d*x)^(3/2))) - ((5*b*c - 21*a*d)*(b*c - a*d)*Sqrt[a + b*x])/(8*c^3*x*(c + d*x)^(3/2)) - ((5*b*c - 9*a*d)*(a + b*x)^(3/2))/(12*c^2*x^2*(c + d*x)^(3/2)) - (a + b*x)^(5/2)/(3*c*x^3*(c + d*x)^(3/2)) - (d*(113*b^2*c^2 - 420*a*b*c*d + 315*a^2*d^2)*Sqrt[a + b*x])/(24*c^5*Sqrt[c + d*x]) - (5*(b*c - a*d)*(b^2*c^2 - 14*a*b*c*d + 21*a^2*d^2)*ArcTanh[(Sqrt[c]*Sqrt[a + b*x])/(Sqrt[a]*Sqrt[c + d*x])])/(8*Sqrt[a]*c^(11/2))}
{(a + b*x)^(5/2)/(x^5*(c + d*x)^(5/2)), x, 8, -((d*(b*c - a*d)*(5*b^2*c^2 - 238*a*b*c*d + 385*a^2*d^2)*Sqrt[a + b*x])/(64*a*c^5*(c + d*x)^(3/2))) - ((5*b*c - 33*a*d)*(b*c - a*d)*Sqrt[a + b*x])/(32*c^3*x^2*(c + d*x)^(3/2)) - ((b*c - a*d)*(5*b^2*c^2 - 156*a*b*c*d + 231*a^2*d^2)*Sqrt[a + b*x])/(64*a*c^4*x*(c + d*x)^(3/2)) - ((5*b*c - 11*a*d)*(a + b*x)^(3/2))/(24*c^2*x^3*(c + d*x)^(3/2)) - (a + b*x)^(5/2)/(4*c*x^4*(c + d*x)^(3/2)) - (d*(5*b^3*c^3 - 581*a*b^2*c^2*d + 1715*a^2*b*c*d^2 - 1155*a^3*d^3)*Sqrt[a + b*x])/(64*a*c^6*Sqrt[c + d*x]) + (5*(b*c - a*d)*(b^3*c^3 + 21*a*b^2*c^2*d - 189*a^2*b*c*d^2 + 231*a^3*d^3)*ArcTanh[(Sqrt[c]*Sqrt[a + b*x])/(Sqrt[a]*Sqrt[c + d*x])])/(64*a^(3/2)*c^(13/2))}


(* ::Subsection::Closed:: *)
(*Integrands of the form x^m (c+d x)^(n/2) / (a+b x)^(1/2)*)


(* ::Subsubsection::Closed:: *)
(*n>0*)


{(x^2*Sqrt[c + d*x])/Sqrt[a + b*x], x, 4, ((b^2*c^2 + 2*a*b*c*d + 5*a^2*d^2)*Sqrt[a + b*x]*Sqrt[c + d*x])/(8*b^3*d^2) - ((3*b*c + 5*a*d)*Sqrt[a + b*x]*(c + d*x)^(3/2))/(12*b^2*d^2) + (x*Sqrt[a + b*x]*(c + d*x)^(3/2))/(3*b*d) + ((b*c - a*d)*(b^2*c^2 + 2*a*b*c*d + 5*a^2*d^2)*ArcTanh[(Sqrt[d]*Sqrt[a + b*x])/(Sqrt[b]*Sqrt[c + d*x])])/(8*b^(7/2)*d^(5/2))}
{(x*Sqrt[c + d*x])/Sqrt[a + b*x], x, 3, -((b*c + 3*a*d)*Sqrt[a + b*x]*Sqrt[c + d*x])/(4*b^2*d) + (Sqrt[a + b*x]*(c + d*x)^(3/2))/(2*b*d) - ((b*c - a*d)*(b*c + 3*a*d)*ArcTanh[(Sqrt[d]*Sqrt[a + b*x])/(Sqrt[b]*Sqrt[c + d*x])])/(4*b^(5/2)*d^(3/2))}
{Sqrt[c + d*x]/Sqrt[a + b*x], x, 2, (Sqrt[a + b*x]*Sqrt[c + d*x])/b + ((b*c - a*d)*ArcTanh[(Sqrt[d]*Sqrt[a + b*x])/(Sqrt[b]*Sqrt[c + d*x])])/(b^(3/2)*Sqrt[d])}
{Sqrt[c + d*x]/(x*Sqrt[a + b*x]), x, 3, (-2*Sqrt[c]*ArcTanh[(Sqrt[c]*Sqrt[a + b*x])/(Sqrt[a]*Sqrt[c + d*x])])/Sqrt[a] + (2*Sqrt[d]*ArcTanh[(Sqrt[d]*Sqrt[a + b*x])/(Sqrt[b]*Sqrt[c + d*x])])/Sqrt[b]}
{Sqrt[c + d*x]/(x^2*Sqrt[a + b*x]), x, 2, -((Sqrt[a + b*x]*Sqrt[c + d*x])/(a*x)) + ((b*c - a*d)*ArcTanh[(Sqrt[c]*Sqrt[a + b*x])/(Sqrt[a]*Sqrt[c + d*x])])/(a^(3/2)*Sqrt[c])}
{Sqrt[c + d*x]/(x^3*Sqrt[a + b*x]), x, 4, -((Sqrt[a + b*x]*Sqrt[c + d*x])/(2*a*x^2)) + ((3*b*c - a*d)*Sqrt[a + b*x]*Sqrt[c + d*x])/(4*a^2*c*x) - ((b*c - a*d)*(3*b*c + a*d)*ArcTanh[(Sqrt[c]*Sqrt[a + b*x])/(Sqrt[a]*Sqrt[c + d*x])])/(4*a^(5/2)*c^(3/2))}
{Sqrt[c + d*x]/(x^4*Sqrt[a + b*x]), x, 5, -((Sqrt[a + b*x]*Sqrt[c + d*x])/(3*a*x^3)) + ((5*b*c - a*d)*Sqrt[a + b*x]*Sqrt[c + d*x])/(12*a^2*c*x^2) - ((5*b*c - 3*a*d)*(3*b*c + a*d)*Sqrt[a + b*x]*Sqrt[c + d*x])/(24*a^3*c^2*x) + ((b*c - a*d)*(5*b^2*c^2 + 2*a*b*c*d + a^2*d^2)*ArcTanh[(Sqrt[c]*Sqrt[a + b*x])/(Sqrt[a]*Sqrt[c + d*x])])/(8*a^(7/2)*c^(5/2))}


{(x^2*(c + d*x)^(3/2))/Sqrt[a + b*x], x, 5, ((b*c - a*d)*(3*b^2*c^2 + 10*a*b*c*d + 35*a^2*d^2)*Sqrt[a + b*x]*Sqrt[c + d*x])/(64*b^4*d^2) + ((3*b^2*c^2 + 10*a*b*c*d + 35*a^2*d^2)*Sqrt[a + b*x]*(c + d*x)^(3/2))/(96*b^3*d^2) - ((3*b*c + 7*a*d)*Sqrt[a + b*x]*(c + d*x)^(5/2))/(24*b^2*d^2) + (x*Sqrt[a + b*x]*(c + d*x)^(5/2))/(4*b*d) + ((b*c - a*d)^2*(3*b^2*c^2 + 10*a*b*c*d + 35*a^2*d^2)*ArcTanh[(Sqrt[d]*Sqrt[a + b*x])/(Sqrt[b]*Sqrt[c + d*x])])/(64*b^(9/2)*d^(5/2))}
{(x*(c + d*x)^(3/2))/Sqrt[a + b*x], x, 4, -((b*c - a*d)*(b*c + 5*a*d)*Sqrt[a + b*x]*Sqrt[c + d*x])/(8*b^3*d) - ((b*c + 5*a*d)*Sqrt[a + b*x]*(c + d*x)^(3/2))/(12*b^2*d) + (Sqrt[a + b*x]*(c + d*x)^(5/2))/(3*b*d) - ((b*c - a*d)^2*(b*c + 5*a*d)*ArcTanh[(Sqrt[d]*Sqrt[a + b*x])/(Sqrt[b]*Sqrt[c + d*x])])/(8*b^(7/2)*d^(3/2))}
{(c + d*x)^(3/2)/Sqrt[a + b*x], x, 3, (3*(b*c - a*d)*Sqrt[a + b*x]*Sqrt[c + d*x])/(4*b^2) + (Sqrt[a + b*x]*(c + d*x)^(3/2))/(2*b) + (3*(b*c - a*d)^2*ArcTanh[(Sqrt[d]*Sqrt[a + b*x])/(Sqrt[b]*Sqrt[c + d*x])])/(4*b^(5/2)*Sqrt[d])}
{(c + d*x)^(3/2)/(x*Sqrt[a + b*x]), x, 4, (d*Sqrt[a + b*x]*Sqrt[c + d*x])/b - (2*c^(3/2)*ArcTanh[(Sqrt[c]*Sqrt[a + b*x])/(Sqrt[a]*Sqrt[c + d*x])])/Sqrt[a] + (Sqrt[d]*(3*b*c - a*d)*ArcTanh[(Sqrt[d]*Sqrt[a + b*x])/(Sqrt[b]*Sqrt[c + d*x])])/b^(3/2)}
{(c + d*x)^(3/2)/(x^2*Sqrt[a + b*x]), x, 5, (d*Sqrt[a + b*x]*Sqrt[c + d*x])/a - (Sqrt[a + b*x]*(c + d*x)^(3/2))/(a*x) + (Sqrt[c]*(b*c - 3*a*d)*ArcTanh[(Sqrt[c]*Sqrt[a + b*x])/(Sqrt[a]*Sqrt[c + d*x])])/a^(3/2) + (2*d^(3/2)*ArcTanh[(Sqrt[d]*Sqrt[a + b*x])/(Sqrt[b]*Sqrt[c + d*x])])/Sqrt[b]}
{(c + d*x)^(3/2)/(x^3*Sqrt[a + b*x]), x, 3, (3*(b*c - a*d)*Sqrt[a + b*x]*Sqrt[c + d*x])/(4*a^2*x) - (Sqrt[a + b*x]*(c + d*x)^(3/2))/(2*a*x^2) - (3*(b*c - a*d)^2*ArcTanh[(Sqrt[c]*Sqrt[a + b*x])/(Sqrt[a]*Sqrt[c + d*x])])/(4*a^(5/2)*Sqrt[c])}
{(c + d*x)^(3/2)/(x^4*Sqrt[a + b*x]), x, 5, ((5*b*c - 3*a*d)*Sqrt[a + b*x]*Sqrt[c + d*x])/(12*a^2*x^2) - (((15*b^2*c)/a - 22*b*d + (3*a*d^2)/c)*Sqrt[a + b*x]*Sqrt[c + d*x])/(24*a^2*x) - (Sqrt[a + b*x]*(c + d*x)^(3/2))/(3*a*x^3) + ((b*c - a*d)^2*(5*b*c + a*d)*ArcTanh[(Sqrt[c]*Sqrt[a + b*x])/(Sqrt[a]*Sqrt[c + d*x])])/(8*a^(7/2)*c^(3/2))}
{(c + d*x)^(3/2)/(x^5*Sqrt[a + b*x]), x, 6, ((7*b*c - 3*a*d)*Sqrt[a + b*x]*Sqrt[c + d*x])/(24*a^2*x^3) - (((35*b^2*c)/a - 46*b*d + (3*a*d^2)/c)*Sqrt[a + b*x]*Sqrt[c + d*x])/(96*a^2*x^2) + ((105*b^3*c^3 - 145*a*b^2*c^2*d + 15*a^2*b*c*d^2 + 9*a^3*d^3)*Sqrt[a + b*x]*Sqrt[c + d*x])/(192*a^4*c^2*x) - (Sqrt[a + b*x]*(c + d*x)^(3/2))/(4*a*x^4) - ((b*c - a*d)^2*(35*b^2*c^2 + 10*a*b*c*d + 3*a^2*d^2)*ArcTanh[(Sqrt[c]*Sqrt[a + b*x])/(Sqrt[a]*Sqrt[c + d*x])])/(64*a^(9/2)*c^(5/2))}


{(x^2*(c + d*x)^(5/2))/Sqrt[a + b*x], x, 6, ((b*c - a*d)^2*(3*b^2*c^2 + 14*a*b*c*d + 63*a^2*d^2)*Sqrt[a + b*x]*Sqrt[c + d*x])/(128*b^5*d^2) + ((b*c - a*d)*(3*b^2*c^2 + 14*a*b*c*d + 63*a^2*d^2)*Sqrt[a + b*x]*(c + d*x)^(3/2))/(192*b^4*d^2) + ((3*b^2*c^2 + 14*a*b*c*d + 63*a^2*d^2)*Sqrt[a + b*x]*(c + d*x)^(5/2))/(240*b^3*d^2) - (3*(b*c + 3*a*d)*Sqrt[a + b*x]*(c + d*x)^(7/2))/(40*b^2*d^2) + (x*Sqrt[a + b*x]*(c + d*x)^(7/2))/(5*b*d) + ((b*c - a*d)^3*(3*b^2*c^2 + 14*a*b*c*d + 63*a^2*d^2)*ArcTanh[(Sqrt[d]*Sqrt[a + b*x])/(Sqrt[b]*Sqrt[c + d*x])])/(128*b^(11/2)*d^(5/2))}
{(x*(c + d*x)^(5/2))/Sqrt[a + b*x], x, 5, (-5*(b*c - a*d)^2*(b*c + 7*a*d)*Sqrt[a + b*x]*Sqrt[c + d*x])/(64*b^4*d) - (5*(b*c - a*d)*(b*c + 7*a*d)*Sqrt[a + b*x]*(c + d*x)^(3/2))/(96*b^3*d) - ((b*c + 7*a*d)*Sqrt[a + b*x]*(c + d*x)^(5/2))/(24*b^2*d) + (Sqrt[a + b*x]*(c + d*x)^(7/2))/(4*b*d) - (5*(b*c - a*d)^3*(b*c + 7*a*d)*ArcTanh[(Sqrt[d]*Sqrt[a + b*x])/(Sqrt[b]*Sqrt[c + d*x])])/(64*b^(9/2)*d^(3/2))}
{(c + d*x)^(5/2)/Sqrt[a + b*x], x, 4, (5*(b*c - a*d)^2*Sqrt[a + b*x]*Sqrt[c + d*x])/(8*b^3) + (5*(b*c - a*d)*Sqrt[a + b*x]*(c + d*x)^(3/2))/(12*b^2) + (Sqrt[a + b*x]*(c + d*x)^(5/2))/(3*b) + (5*(b*c - a*d)^3*ArcTanh[(Sqrt[d]*Sqrt[a + b*x])/(Sqrt[b]*Sqrt[c + d*x])])/(8*b^(7/2)*Sqrt[d])}
{(c + d*x)^(5/2)/(x*Sqrt[a + b*x]), x, 5, (d*(7*b*c - 3*a*d)*Sqrt[a + b*x]*Sqrt[c + d*x])/(4*b^2) + (d*Sqrt[a + b*x]*(c + d*x)^(3/2))/(2*b) - (2*c^(5/2)*ArcTanh[(Sqrt[c]*Sqrt[a + b*x])/(Sqrt[a]*Sqrt[c + d*x])])/Sqrt[a] + (Sqrt[d]*(15*b^2*c^2 - 10*a*b*c*d + 3*a^2*d^2)*ArcTanh[(Sqrt[d]*Sqrt[a + b*x])/(Sqrt[b]*Sqrt[c + d*x])])/(4*b^(5/2))}
{(c + d*x)^(5/2)/(x^2*Sqrt[a + b*x]), x, 6, (d*(b*c + a*d)*Sqrt[a + b*x]*Sqrt[c + d*x])/(a*b) + (d*Sqrt[a + b*x]*(c + d*x)^(3/2))/a - (Sqrt[a + b*x]*(c + d*x)^(5/2))/(a*x) + (c^(3/2)*(b*c - 5*a*d)*ArcTanh[(Sqrt[c]*Sqrt[a + b*x])/(Sqrt[a]*Sqrt[c + d*x])])/a^(3/2) + (d^(3/2)*(5*b*c - a*d)*ArcTanh[(Sqrt[d]*Sqrt[a + b*x])/(Sqrt[b]*Sqrt[c + d*x])])/b^(3/2)}
{(c + d*x)^(5/2)/(x^3*Sqrt[a + b*x]), x, 6, -(d*(3*b*c - 7*a*d)*Sqrt[a + b*x]*Sqrt[c + d*x])/(4*a^2) + ((3*b*c - 5*a*d)*Sqrt[a + b*x]*(c + d*x)^(3/2))/(4*a^2*x) - (Sqrt[a + b*x]*(c + d*x)^(5/2))/(2*a*x^2) - (Sqrt[c]*(3*b^2*c^2 - 10*a*b*c*d + 15*a^2*d^2)*ArcTanh[(Sqrt[c]*Sqrt[a + b*x])/(Sqrt[a]*Sqrt[c + d*x])])/(4*a^(5/2)) + (2*d^(5/2)*ArcTanh[(Sqrt[d]*Sqrt[a + b*x])/(Sqrt[b]*Sqrt[c + d*x])])/Sqrt[b]}
{(c + d*x)^(5/2)/(x^4*Sqrt[a + b*x]), x, 4, -((5*(b*c - a*d)^2*Sqrt[a + b*x]*Sqrt[c + d*x])/(8*a^3*x)) + (5*(b*c - a*d)*Sqrt[a + b*x]*(c + d*x)^(3/2))/(12*a^2*x^2) - (Sqrt[a + b*x]*(c + d*x)^(5/2))/(3*a*x^3) + (5*(b*c - a*d)^3*ArcTanh[(Sqrt[c]*Sqrt[a + b*x])/(Sqrt[a]*Sqrt[c + d*x])])/(8*a^(7/2)*Sqrt[c])}
{(c + d*x)^(5/2)/(x^5*Sqrt[a + b*x]), x, 6, -(((35*b^2*c^2 - 58*a*b*c*d + 15*a^2*d^2)*Sqrt[a + b*x]*Sqrt[c + d*x])/(96*a^3*x^2)) + ((105*b^3*c^3 - 265*a*b^2*c^2*d + 191*a^2*b*c*d^2 - 15*a^3*d^3)*Sqrt[a + b*x]*Sqrt[c + d*x])/(192*a^4*c*x) + ((7*b*c - 5*a*d)*Sqrt[a + b*x]*(c + d*x)^(3/2))/(24*a^2*x^3) - (Sqrt[a + b*x]*(c + d*x)^(5/2))/(4*a*x^4) - (5*(b*c - a*d)^3*(7*b*c + a*d)*ArcTanh[(Sqrt[c]*Sqrt[a + b*x])/(Sqrt[a]*Sqrt[c + d*x])])/(64*a^(9/2)*c^(3/2))}
{(c + d*x)^(5/2)/(x^6*Sqrt[a + b*x]), x, 7, -(((63*b^2*c^2 - 94*a*b*c*d + 15*a^2*d^2)*Sqrt[a + b*x]*Sqrt[c + d*x])/(240*a^3*x^3)) + ((315*b^3*c^3 - 749*a*b^2*c^2*d + 481*a^2*b*c*d^2 - 15*a^3*d^3)*Sqrt[a + b*x]*Sqrt[c + d*x])/(960*a^4*c*x^2) - ((945*b^4*c^4 - 2310*a*b^3*c^3*d + 1564*a^2*b^2*c^2*d^2 - 90*a^3*b*c*d^3 - 45*a^4*d^4)*Sqrt[a + b*x]*Sqrt[c + d*x])/(1920*a^5*c^2*x) + ((9*b*c - 5*a*d)*Sqrt[a + b*x]*(c + d*x)^(3/2))/(40*a^2*x^4) - (Sqrt[a + b*x]*(c + d*x)^(5/2))/(5*a*x^5) + ((b*c - a*d)^3*(63*b^2*c^2 + 14*a*b*c*d + 3*a^2*d^2)*ArcTanh[(Sqrt[c]*Sqrt[a + b*x])/(Sqrt[a]*Sqrt[c + d*x])])/(128*a^(11/2)*c^(5/2))}


(* ::Subsubsection::Closed:: *)
(*n<0*)


{x^3/(Sqrt[a + b*x]*Sqrt[c + d*x]), x, 4, -(((16*a*b*c*d - 15*(b*c + a*d)^2)*Sqrt[a + b*x]*Sqrt[c + d*x])/(24*b^3*d^3)) - (5*(b*c + a*d)*x*Sqrt[a + b*x]*Sqrt[c + d*x])/(12*b^2*d^2) + (x^2*Sqrt[a + b*x]*Sqrt[c + d*x])/(3*b*d) + ((b*c + a*d)*(12*a*b*c*d - 5*(b*c + a*d)^2)*ArcTanh[(Sqrt[d]*Sqrt[a + b*x])/(Sqrt[b]*Sqrt[c + d*x])])/(8*b^(7/2)*d^(7/2))}
{x^2/(Sqrt[a + b*x]*Sqrt[c + d*x]), x, 3, -((3*(b*c + a*d)*Sqrt[a + b*x]*Sqrt[c + d*x])/(4*b^2*d^2)) + (x*Sqrt[a + b*x]*Sqrt[c + d*x])/(2*b*d) - ((4*a*b*c*d - 3*(b*c + a*d)^2)*ArcTanh[(Sqrt[d]*Sqrt[a + b*x])/(Sqrt[b]*Sqrt[c + d*x])])/(4*b^(5/2)*d^(5/2))}
{x/(Sqrt[a + b*x]*Sqrt[c + d*x]), x, 2, (Sqrt[a + b*x]*Sqrt[c + d*x])/(b*d) - ((b*c + a*d)*ArcTanh[(Sqrt[d]*Sqrt[a + b*x])/(Sqrt[b]*Sqrt[c + d*x])])/(b^(3/2)*d^(3/2))}
{1/(Sqrt[a + b*x]*Sqrt[c + d*x]), x, 1, (2*ArcTanh[(Sqrt[d]*Sqrt[a + b*x])/(Sqrt[b]*Sqrt[c + d*x])])/(Sqrt[b]*Sqrt[d])}
{1/(x*Sqrt[a + b*x]*Sqrt[c + d*x]), x, 1, -((2*ArcTanh[(Sqrt[c]*Sqrt[a + b*x])/(Sqrt[a]*Sqrt[c + d*x])])/(Sqrt[a]*Sqrt[c]))}
{1/(x^2*Sqrt[a + b*x]*Sqrt[c + d*x]), x, 3, -((Sqrt[a + b*x]*Sqrt[c + d*x])/(a*c*x)) + ((b*c + a*d)*ArcTanh[(Sqrt[c]*Sqrt[a + b*x])/(Sqrt[a]*Sqrt[c + d*x])])/(a^(3/2)*c^(3/2))}
{1/(x^3*Sqrt[a + b*x]*Sqrt[c + d*x]), x, 4, -((Sqrt[a + b*x]*Sqrt[c + d*x])/(2*a*c*x^2)) + (3*(b*c + a*d)*Sqrt[a + b*x]*Sqrt[c + d*x])/(4*a^2*c^2*x) - ((3*b^2*c^2 + 2*a*b*c*d + 3*a^2*d^2)*ArcTanh[(Sqrt[c]*Sqrt[a + b*x])/(Sqrt[a]*Sqrt[c + d*x])])/(4*a^(5/2)*c^(5/2))}
{1/(x^4*Sqrt[a + b*x]*Sqrt[c + d*x]), x, 5, -((Sqrt[a + b*x]*Sqrt[c + d*x])/(3*a*c*x^3)) + (5*(b*c + a*d)*Sqrt[a + b*x]*Sqrt[c + d*x])/(12*a^2*c^2*x^2) - ((15*b^2*c^2 + 14*a*b*c*d + 15*a^2*d^2)*Sqrt[a + b*x]*Sqrt[c + d*x])/(24*a^3*c^3*x) + ((b*c + a*d)*(5*b^2*c^2 - 2*a*b*c*d + 5*a^2*d^2)*ArcTanh[(Sqrt[c]*Sqrt[a + b*x])/(Sqrt[a]*Sqrt[c + d*x])])/(8*a^(7/2)*c^(7/2))}


{x^3/(Sqrt[a + b*x]*(c + d*x)^(3/2)), x, 4, (x^2*Sqrt[a + b*x])/(2*b*d*Sqrt[c + d*x]) - ((3*b*c - a*d)*(5*b*c + 3*a*d)*Sqrt[a + b*x]*Sqrt[c + d*x])/(4*b^2*d^3*(b*c - a*d)) + (c*Sqrt[a + b*x]*(4*a*c + (5*b*c + 3*a*d)*x))/(2*b*d^2*(b*c - a*d)*Sqrt[c + d*x]) + (3*(5*b^2*c^2 + 2*a*b*c*d + a^2*d^2)*ArcTanh[(Sqrt[d]*Sqrt[a + b*x])/(Sqrt[b]*Sqrt[c + d*x])])/(4*b^(5/2)*d^(7/2))}
{x^2/(Sqrt[a + b*x]*(c + d*x)^(3/2)), x, 3, (2*c^2*Sqrt[a + b*x])/(d^2*(b*c - a*d)*Sqrt[c + d*x]) + (Sqrt[a + b*x]*Sqrt[c + d*x])/(b*d^2) - ((3*b*c + a*d)*ArcTanh[(Sqrt[d]*Sqrt[a + b*x])/(Sqrt[b]*Sqrt[c + d*x])])/(b^(3/2)*d^(5/2))}
{x/(Sqrt[a + b*x]*(c + d*x)^(3/2)), x, 2, -((2*c*Sqrt[a + b*x])/(d*(b*c - a*d)*Sqrt[c + d*x])) + (2*ArcTanh[(Sqrt[d]*Sqrt[a + b*x])/(Sqrt[b]*Sqrt[c + d*x])])/(Sqrt[b]*d^(3/2))}
{1/(Sqrt[a + b*x]*(c + d*x)^(3/2)), x, 1, (2*Sqrt[a + b*x])/((b*c - a*d)*Sqrt[c + d*x])}
{1/(x*Sqrt[a + b*x]*(c + d*x)^(3/2)), x, 3, -((2*d*Sqrt[a + b*x])/(c*(b*c - a*d)*Sqrt[c + d*x])) - (2*ArcTanh[(Sqrt[c]*Sqrt[a + b*x])/(Sqrt[a]*Sqrt[c + d*x])])/(Sqrt[a]*c^(3/2))}
{1/(x^2*Sqrt[a + b*x]*(c + d*x)^(3/2)), x, 4, -((d*(b*c - 3*a*d)*Sqrt[a + b*x])/(a*c^2*(b*c - a*d)*Sqrt[c + d*x])) - Sqrt[a + b*x]/(a*c*x*Sqrt[c + d*x]) + ((b*c + 3*a*d)*ArcTanh[(Sqrt[c]*Sqrt[a + b*x])/(Sqrt[a]*Sqrt[c + d*x])])/(a^(3/2)*c^(5/2))}
{1/(x^3*Sqrt[a + b*x]*(c + d*x)^(3/2)), x, 5, (d*(3*b*c - 5*a*d)*(b*c + 3*a*d)*Sqrt[a + b*x])/(4*a^2*c^3*(b*c - a*d)*Sqrt[c + d*x]) - Sqrt[a + b*x]/(2*a*c*x^2*Sqrt[c + d*x]) + ((3*b*c + 5*a*d)*Sqrt[a + b*x])/(4*a^2*c^2*x*Sqrt[c + d*x]) - (3*(b^2*c^2 + 2*a*b*c*d + 5*a^2*d^2)*ArcTanh[(Sqrt[c]*Sqrt[a + b*x])/(Sqrt[a]*Sqrt[c + d*x])])/(4*a^(5/2)*c^(7/2))}


{x^4/(Sqrt[a + b*x]*(c + d*x)^(5/2)), x, 5, (c*(7*b*c - 3*a*d)*x^2*Sqrt[a + b*x])/(6*b*d^2*(b*c - a*d)*(c + d*x)^(3/2)) + (x^3*Sqrt[a + b*x])/(2*b*d*(c + d*x)^(3/2)) - ((3*b*c - a*d)*(35*b^2*c^2 - 18*a*b*c*d - 9*a^2*d^2)*Sqrt[a + b*x]*Sqrt[c + d*x])/(12*b^2*d^4*(b*c - a*d)^2) + (c*Sqrt[a + b*x]*(4*a*c*(7*b*c - 3*a*d) + (35*b^2*c^2 - 18*a*b*c*d - 9*a^2*d^2)*x))/(6*b*d^3*(b*c - a*d)^2*Sqrt[c + d*x]) + ((35*b^2*c^2 + 10*a*b*c*d + 3*a^2*d^2)*ArcTanh[(Sqrt[d]*Sqrt[a + b*x])/(Sqrt[b]*Sqrt[c + d*x])])/(4*b^(5/2)*d^(9/2))}
{x^3/(Sqrt[a + b*x]*(c + d*x)^(5/2)), x, 4, (x^2*Sqrt[a + b*x])/(b*d*(c + d*x)^(3/2)) + (c*(5*b*c - 7*a*d)*(3*b*c - a*d)*Sqrt[a + b*x])/(3*b*d^3*(b*c - a*d)^2*Sqrt[c + d*x]) + (c*Sqrt[a + b*x]*(4*a*c + (5*b*c + a*d)*x))/(3*b*d^2*(b*c - a*d)*(c + d*x)^(3/2)) - ((5*b*c + a*d)*ArcTanh[(Sqrt[d]*Sqrt[a + b*x])/(Sqrt[b]*Sqrt[c + d*x])])/(b^(3/2)*d^(7/2))}
{x^2/(Sqrt[a + b*x]*(c + d*x)^(5/2)), x, 3, (2*c^2*Sqrt[a + b*x])/(3*d^2*(b*c - a*d)*(c + d*x)^(3/2)) - (4*c*(2*b*c - 3*a*d)*Sqrt[a + b*x])/(3*d^2*(b*c - a*d)^2*Sqrt[c + d*x]) + (2*ArcTanh[(Sqrt[d]*Sqrt[a + b*x])/(Sqrt[b]*Sqrt[c + d*x])])/(Sqrt[b]*d^(5/2))}
{x/(Sqrt[a + b*x]*(c + d*x)^(5/2)), x, 2, -((2*c*Sqrt[a + b*x])/(3*d*(b*c - a*d)*(c + d*x)^(3/2))) + (2*(b*c - 3*a*d)*Sqrt[a + b*x])/(3*d*(b*c - a*d)^2*Sqrt[c + d*x])}
{1/(Sqrt[a + b*x]*(c + d*x)^(5/2)), x, 2, (2*Sqrt[a + b*x])/(3*(b*c - a*d)*(c + d*x)^(3/2)) + (4*b*Sqrt[a + b*x])/(3*(b*c - a*d)^2*Sqrt[c + d*x])}
{1/(x*Sqrt[a + b*x]*(c + d*x)^(5/2)), x, 4, -((2*d*Sqrt[a + b*x])/(3*c*(b*c - a*d)*(c + d*x)^(3/2))) - (2*d*(5*b*c - 3*a*d)*Sqrt[a + b*x])/(3*c^2*(b*c - a*d)^2*Sqrt[c + d*x]) - (2*ArcTanh[(Sqrt[c]*Sqrt[a + b*x])/(Sqrt[a]*Sqrt[c + d*x])])/(Sqrt[a]*c^(5/2))}
{1/(x^2*Sqrt[a + b*x]*(c + d*x)^(5/2)), x, 5, -((d*(3*b*c - 5*a*d)*Sqrt[a + b*x])/(3*a*c^2*(b*c - a*d)*(c + d*x)^(3/2))) - Sqrt[a + b*x]/(a*c*x*(c + d*x)^(3/2)) - (d*(3*b^2*c^2 - 22*a*b*c*d + 15*a^2*d^2)*Sqrt[a + b*x])/(3*a*c^3*(b*c - a*d)^2*Sqrt[c + d*x]) + ((b*c + 5*a*d)*ArcTanh[(Sqrt[c]*Sqrt[a + b*x])/(Sqrt[a]*Sqrt[c + d*x])])/(a^(3/2)*c^(7/2))}
{1/(x^3*Sqrt[a + b*x]*(c + d*x)^(5/2)), x, 6, (d*(9*b^2*c^2 + 18*a*b*c*d - 35*a^2*d^2)*Sqrt[a + b*x])/(12*a^2*c^3*(b*c - a*d)*(c + d*x)^(3/2)) - Sqrt[a + b*x]/(2*a*c*x^2*(c + d*x)^(3/2)) + ((3*b*c + 7*a*d)*Sqrt[a + b*x])/(4*a^2*c^2*x*(c + d*x)^(3/2)) + (d*(9*b^3*c^3 + 15*a*b^2*c^2*d - 145*a^2*b*c*d^2 + 105*a^3*d^3)*Sqrt[a + b*x])/(12*a^2*c^4*(b*c - a*d)^2*Sqrt[c + d*x]) - ((3*b^2*c^2 + 10*a*b*c*d + 35*a^2*d^2)*ArcTanh[(Sqrt[c]*Sqrt[a + b*x])/(Sqrt[a]*Sqrt[c + d*x])])/(4*a^(5/2)*c^(9/2))}


{1/(x*Sqrt[1 - a - b*x]*Sqrt[1 + a + b*x]), x, 1, -((2*ArcTanh[(Sqrt[1 - a]*Sqrt[1 + a + b*x])/(Sqrt[1 + a]*Sqrt[1 - a - b*x])])/Sqrt[1 - a^2])}


(* ::Subsection::Closed:: *)
(*Integrands of the form x^m (c+d x)^(n/2) / (a+b x)^(3/2)*)


(* ::Subsubsection::Closed:: *)
(*n>0*)


{(x^3*(c + d*x)^(3/2))/(a + b*x)^(3/2), x, 6, (3*(b^3*c^3 + 5*a*b^2*c^2*d + 35*a^2*b*c*d^2 - 105*a^3*d^3)*Sqrt[a + b*x]*Sqrt[c + d*x])/(64*b^5*d^2) - (2*x^3*(c + d*x)^(3/2))/(b*Sqrt[a + b*x]) - ((3*b^2*c^2 + 14*a*b*c*d - 105*a^2*d^2)*Sqrt[a + b*x]*(c + d*x)^(3/2))/(32*b^4*d^2) + ((b*c - 21*a*d)*x*Sqrt[a + b*x]*(c + d*x)^(3/2))/(8*b^3*d) + (9*x^2*Sqrt[a + b*x]*(c + d*x)^(3/2))/(4*b^2) + (3*(b*c - a*d)*(b^3*c^3 + 5*a*b^2*c^2*d + 35*a^2*b*c*d^2 - 105*a^3*d^3)*ArcTanh[(Sqrt[d]*Sqrt[a + b*x])/(Sqrt[b]*Sqrt[c + d*x])])/(64*b^(11/2)*d^(5/2))}
{(x^2*(c + d*x)^(3/2))/(a + b*x)^(3/2), x, 5, -(((b^2*c^2 + 10*a*b*c*d - 35*a^2*d^2)*Sqrt[a + b*x]*Sqrt[c + d*x])/(8*b^4*d)) - ((10*a*c + (b*c^2)/d - (35*a^2*d)/b)*Sqrt[a + b*x]*(c + d*x)^(3/2))/(12*b^2*(b*c - a*d)) - (2*a^2*(c + d*x)^(5/2))/(b^2*(b*c - a*d)*Sqrt[a + b*x]) + (Sqrt[a + b*x]*(c + d*x)^(5/2))/(3*b^2*d) - ((b*c - a*d)*(b^2*c^2 + 10*a*b*c*d - 35*a^2*d^2)*ArcTanh[(Sqrt[d]*Sqrt[a + b*x])/(Sqrt[b]*Sqrt[c + d*x])])/(8*b^(9/2)*d^(3/2))}
{(x*(c + d*x)^(3/2))/(a + b*x)^(3/2), x, 4, (3*(b*c - 5*a*d)*Sqrt[a + b*x]*Sqrt[c + d*x])/(4*b^3) + ((b*c - 5*a*d)*Sqrt[a + b*x]*(c + d*x)^(3/2))/(2*b^2*(b*c - a*d)) + (2*a*(c + d*x)^(5/2))/(b*(b*c - a*d)*Sqrt[a + b*x]) + (3*(b*c - 5*a*d)*(b*c - a*d)*ArcTanh[(Sqrt[d]*Sqrt[a + b*x])/(Sqrt[b]*Sqrt[c + d*x])])/(4*b^(7/2)*Sqrt[d])}
{(c + d*x)^(3/2)/(a + b*x)^(3/2), x, 3, (3*d*Sqrt[a + b*x]*Sqrt[c + d*x])/b^2 - (2*(c + d*x)^(3/2))/(b*Sqrt[a + b*x]) + (3*Sqrt[d]*(b*c - a*d)*ArcTanh[(Sqrt[d]*Sqrt[a + b*x])/(Sqrt[b]*Sqrt[c + d*x])])/b^(5/2)}
{(c + d*x)^(3/2)/(x*(a + b*x)^(3/2)), x, 5, (-2*d*Sqrt[a + b*x]*Sqrt[c + d*x])/(a*b) + (2*(c + d*x)^(3/2))/(a*Sqrt[a + b*x]) - (2*c^(3/2)*ArcTanh[(Sqrt[c]*Sqrt[a + b*x])/(Sqrt[a]*Sqrt[c + d*x])])/a^(3/2) + (2*d^(3/2)*ArcTanh[(Sqrt[d]*Sqrt[a + b*x])/(Sqrt[b]*Sqrt[c + d*x])])/b^(3/2)}
{(c + d*x)^(3/2)/(x^2*(a + b*x)^(3/2)), x, 3, (-3*(b*c - a*d)*Sqrt[c + d*x])/(a^2*Sqrt[a + b*x]) - (c + d*x)^(3/2)/(a*x*Sqrt[a + b*x]) + (3*Sqrt[c]*(b*c - a*d)*ArcTanh[(Sqrt[c]*Sqrt[a + b*x])/(Sqrt[a]*Sqrt[c + d*x])])/a^(5/2)}
{(c + d*x)^(3/2)/(x^3*(a + b*x)^(3/2)), x, 5, (b*(15*b*c - 13*a*d)*Sqrt[c + d*x])/(4*a^3*Sqrt[a + b*x]) + ((5*b*c - 3*a*d)*Sqrt[c + d*x])/(4*a^2*x*Sqrt[a + b*x]) - (c + d*x)^(3/2)/(2*a*x^2*Sqrt[a + b*x]) - (3*(b*c - a*d)*(5*b*c - a*d)*ArcTanh[(Sqrt[c]*Sqrt[a + b*x])/(Sqrt[a]*Sqrt[c + d*x])])/(4*a^(7/2)*Sqrt[c])}
{(c + d*x)^(3/2)/(x^4*(a + b*x)^(3/2)), x, 6, -((b*(105*b^2*c^2 - 100*a*b*c*d + 3*a^2*d^2)*Sqrt[c + d*x])/(24*a^4*c*Sqrt[a + b*x])) + ((7*b*c - 3*a*d)*Sqrt[c + d*x])/(12*a^2*x^2*Sqrt[a + b*x]) - ((35*b*c - 3*a*d)*(b*c - a*d)*Sqrt[c + d*x])/(24*a^3*c*x*Sqrt[a + b*x]) - (c + d*x)^(3/2)/(3*a*x^3*Sqrt[a + b*x]) + ((b*c - a*d)*(35*b^2*c^2 - 10*a*b*c*d - a^2*d^2)*ArcTanh[(Sqrt[c]*Sqrt[a + b*x])/(Sqrt[a]*Sqrt[c + d*x])])/(8*a^(9/2)*c^(3/2))}


{(x^3*(c + d*x)^(5/2))/(a + b*x)^(3/2), x, 7, (3*(b*c - a*d)*(b^3*c^3 + 7*a*b^2*c^2*d + 63*a^2*b*c*d^2 - 231*a^3*d^3)*Sqrt[a + b*x]*Sqrt[c + d*x])/(128*b^6*d^2) + ((b^3*c^3 + 7*a*b^2*c^2*d + 63*a^2*b*c*d^2 - 231*a^3*d^3)*Sqrt[a + b*x]*(c + d*x)^(3/2))/(64*b^5*d^2) - (2*x^3*(c + d*x)^(5/2))/(b*Sqrt[a + b*x]) - ((5*b^2*c^2 + 30*a*b*c*d - 231*a^2*d^2)*Sqrt[a + b*x]*(c + d*x)^(5/2))/(80*b^4*d^2) + ((5*b*c - 99*a*d)*x*Sqrt[a + b*x]*(c + d*x)^(5/2))/(40*b^3*d) + (11*x^2*Sqrt[a + b*x]*(c + d*x)^(5/2))/(5*b^2) + (3*(b*c - a*d)^2*(b^3*c^3 + 7*a*b^2*c^2*d + 63*a^2*b*c*d^2 - 231*a^3*d^3)*ArcTanh[(Sqrt[d]*Sqrt[a + b*x])/(Sqrt[b]*Sqrt[c + d*x])])/(128*b^(13/2)*d^(5/2))}
{(x^2*(c + d*x)^(5/2))/(a + b*x)^(3/2), x, 6, -((5*(b*c - a*d)*(b^2*c^2 + 14*a*b*c*d - 63*a^2*d^2)*Sqrt[a + b*x]*Sqrt[c + d*x])/(64*b^5*d)) - (5*(b^2*c^2 + 14*a*b*c*d - 63*a^2*d^2)*Sqrt[a + b*x]*(c + d*x)^(3/2))/(96*b^4*d) - ((14*a*c + (b*c^2)/d - (63*a^2*d)/b)*Sqrt[a + b*x]*(c + d*x)^(5/2))/(24*b^2*(b*c - a*d)) - (2*a^2*(c + d*x)^(7/2))/(b^2*(b*c - a*d)*Sqrt[a + b*x]) + (Sqrt[a + b*x]*(c + d*x)^(7/2))/(4*b^2*d) - (5*(b*c - a*d)^2*(b^2*c^2 + 14*a*b*c*d - 63*a^2*d^2)*ArcTanh[(Sqrt[d]*Sqrt[a + b*x])/(Sqrt[b]*Sqrt[c + d*x])])/(64*b^(11/2)*d^(3/2))}
{(x*(c + d*x)^(5/2))/(a + b*x)^(3/2), x, 5, (5*(b*c - 7*a*d)*(b*c - a*d)*Sqrt[a + b*x]*Sqrt[c + d*x])/(8*b^4) + (5*(b*c - 7*a*d)*Sqrt[a + b*x]*(c + d*x)^(3/2))/(12*b^3) + ((b*c - 7*a*d)*Sqrt[a + b*x]*(c + d*x)^(5/2))/(3*b^2*(b*c - a*d)) + (2*a*(c + d*x)^(7/2))/(b*(b*c - a*d)*Sqrt[a + b*x]) + (5*(b*c - 7*a*d)*(b*c - a*d)^2*ArcTanh[(Sqrt[d]*Sqrt[a + b*x])/(Sqrt[b]*Sqrt[c + d*x])])/(8*b^(9/2)*Sqrt[d])}
{(c + d*x)^(5/2)/(a + b*x)^(3/2), x, 4, (15*d*(b*c - a*d)*Sqrt[a + b*x]*Sqrt[c + d*x])/(4*b^3) + (5*d*Sqrt[a + b*x]*(c + d*x)^(3/2))/(2*b^2) - (2*(c + d*x)^(5/2))/(b*Sqrt[a + b*x]) + (15*Sqrt[d]*(b*c - a*d)^2*ArcTanh[(Sqrt[d]*Sqrt[a + b*x])/(Sqrt[b]*Sqrt[c + d*x])])/(4*b^(7/2))}
{(c + d*x)^(5/2)/(x*(a + b*x)^(3/2)), x, 6, -((d*(2*b*c - 3*a*d)*Sqrt[a + b*x]*Sqrt[c + d*x])/(a*b^2)) - (2*d*Sqrt[a + b*x]*(c + d*x)^(3/2))/(a*b) + (2*(c + d*x)^(5/2))/(a*Sqrt[a + b*x]) - (2*c^(5/2)*ArcTanh[(Sqrt[c]*Sqrt[a + b*x])/(Sqrt[a]*Sqrt[c + d*x])])/a^(3/2) + (d^(3/2)*(5*b*c - 3*a*d)*ArcTanh[(Sqrt[d]*Sqrt[a + b*x])/(Sqrt[b]*Sqrt[c + d*x])])/b^(5/2)}
{(c + d*x)^(5/2)/(x^2*(a + b*x)^(3/2)), x, 6, (d*(3*b*c - 2*a*d)*Sqrt[a + b*x]*Sqrt[c + d*x])/(a^2*b) - (3*(b*c - a*d)*(c + d*x)^(3/2))/(a^2*Sqrt[a + b*x]) - (c + d*x)^(5/2)/(a*x*Sqrt[a + b*x]) + (c^(3/2)*(3*b*c - 5*a*d)*ArcTanh[(Sqrt[c]*Sqrt[a + b*x])/(Sqrt[a]*Sqrt[c + d*x])])/a^(5/2) + (2*d^(5/2)*ArcTanh[(Sqrt[d]*Sqrt[a + b*x])/(Sqrt[b]*Sqrt[c + d*x])])/b^(3/2)}
{(c + d*x)^(5/2)/(x^3*(a + b*x)^(3/2)), x, 4, (15*(b*c - a*d)^2*Sqrt[c + d*x])/(4*a^3*Sqrt[a + b*x]) + (5*(b*c - a*d)*(c + d*x)^(3/2))/(4*a^2*x*Sqrt[a + b*x]) - (c + d*x)^(5/2)/(2*a*x^2*Sqrt[a + b*x]) - (15*Sqrt[c]*(b*c - a*d)^2*ArcTanh[(Sqrt[c]*Sqrt[a + b*x])/(Sqrt[a]*Sqrt[c + d*x])])/(4*a^(7/2))}
{(c + d*x)^(5/2)/(x^4*(a + b*x)^(3/2)), x, 6, -((b*(105*b^2*c^2 - 190*a*b*c*d + 81*a^2*d^2)*Sqrt[c + d*x])/(24*a^4*Sqrt[a + b*x])) - ((35*b^2*c^2 - 54*a*b*c*d + 15*a^2*d^2)*Sqrt[c + d*x])/(24*a^3*x*Sqrt[a + b*x]) + ((7*b*c - 5*a*d)*(c + d*x)^(3/2))/(12*a^2*x^2*Sqrt[a + b*x]) - (c + d*x)^(5/2)/(3*a*x^3*Sqrt[a + b*x]) + (5*(b*c - a*d)^2*(7*b*c - a*d)*ArcTanh[(Sqrt[c]*Sqrt[a + b*x])/(Sqrt[a]*Sqrt[c + d*x])])/(8*a^(9/2)*Sqrt[c])}
{(c + d*x)^(5/2)/(x^5*(a + b*x)^(3/2)), x, 7, (b*(945*b^3*c^3 - 1785*a*b^2*c^2*d + 839*a^2*b*c*d^2 - 15*a^3*d^3)*Sqrt[c + d*x])/(192*a^5*c*Sqrt[a + b*x]) - ((63*b^2*c^2 - 86*a*b*c*d + 15*a^2*d^2)*Sqrt[c + d*x])/(96*a^3*x^2*Sqrt[a + b*x]) + ((b*c - a*d)*(315*b^2*c^2 - 322*a*b*c*d + 15*a^2*d^2)*Sqrt[c + d*x])/(192*a^4*c*x*Sqrt[a + b*x]) + ((9*b*c - 5*a*d)*(c + d*x)^(3/2))/(24*a^2*x^3*Sqrt[a + b*x]) - (c + d*x)^(5/2)/(4*a*x^4*Sqrt[a + b*x]) - (5*(b*c - a*d)^2*(63*b^2*c^2 - 14*a*b*c*d - a^2*d^2)*ArcTanh[(Sqrt[c]*Sqrt[a + b*x])/(Sqrt[a]*Sqrt[c + d*x])])/(64*a^(11/2)*c^(3/2))}


(* ::Subsubsection::Closed:: *)
(*n<0*)


{x^4/((a + b*x)^(3/2)*(c + d*x)^(3/2)), x, 5, (a*(b*c - 5*a*d)*x^2)/(2*b^2*d*(b*c - a*d)*Sqrt[a + b*x]*Sqrt[c + d*x]) + x^3/(2*b*d*Sqrt[a + b*x]*Sqrt[c + d*x]) - ((3*b*c - a*d)*(5*b^2*c^2 + 2*a*b*c*d - 15*a^2*d^2)*Sqrt[a + b*x]*Sqrt[c + d*x])/(4*b^3*d^3*(b*c - a*d)^2) + (c*Sqrt[a + b*x]*(4*a*c*(b*c - 5*a*d) + (5*b^2*c^2 + 2*a*b*c*d - 15*a^2*d^2)*x))/(2*b^2*d^2*(b*c - a*d)^2*Sqrt[c + d*x]) + (3*(5*b^2*c^2 + 6*a*b*c*d + 5*a^2*d^2)*ArcTanh[(Sqrt[d]*Sqrt[a + b*x])/(Sqrt[b]*Sqrt[c + d*x])])/(4*b^(7/2)*d^(7/2))}
{x^3/((a + b*x)^(3/2)*(c + d*x)^(3/2)), x, 4, x^2/(b*d*Sqrt[a + b*x]*Sqrt[c + d*x]) + (c*(3*b*c - a*d)*(b*c + a*d)*Sqrt[a + b*x])/(b^2*d^2*(b*c - a*d)^2*Sqrt[c + d*x]) - (a*(4*a*c + 3*(b*c + a*d)*x))/(b^2*d*(b*c - a*d)*Sqrt[a + b*x]*Sqrt[c + d*x]) - (3*(b*c + a*d)*ArcTanh[(Sqrt[d]*Sqrt[a + b*x])/(Sqrt[b]*Sqrt[c + d*x])])/(b^(5/2)*d^(5/2))}
{x^2/((a + b*x)^(3/2)*(c + d*x)^(3/2)), x, 3, -((2*a^2)/(b^2*(b*c - a*d)*Sqrt[a + b*x]*Sqrt[c + d*x])) - (2*(b^2*c^2 + a^2*d^2)*Sqrt[a + b*x])/(b^2*d*(b*c - a*d)^2*Sqrt[c + d*x]) + (2*ArcTanh[(Sqrt[d]*Sqrt[a + b*x])/(Sqrt[b]*Sqrt[c + d*x])])/(b^(3/2)*d^(3/2))}
{x/((a + b*x)^(3/2)*(c + d*x)^(3/2)), x, 2, -((2*c)/(d*(b*c - a*d)*Sqrt[a + b*x]*Sqrt[c + d*x])) + (2*(b*c + a*d)*Sqrt[c + d*x])/(d*(b*c - a*d)^2*Sqrt[a + b*x])}
{1/((a + b*x)^(3/2)*(c + d*x)^(3/2)), x, 2, -(2/((b*c - a*d)*Sqrt[a + b*x]*Sqrt[c + d*x])) - (4*d*Sqrt[a + b*x])/((b*c - a*d)^2*Sqrt[c + d*x])}
{1/(x*(a + b*x)^(3/2)*(c + d*x)^(3/2)), x, 4, (2*b)/(a*(b*c - a*d)*Sqrt[a + b*x]*Sqrt[c + d*x]) + (2*d*(b*c + a*d)*Sqrt[a + b*x])/(a*c*(b*c - a*d)^2*Sqrt[c + d*x]) - (2*ArcTanh[(Sqrt[c]*Sqrt[a + b*x])/(Sqrt[a]*Sqrt[c + d*x])])/(a^(3/2)*c^(3/2))}
{1/(x^2*(a + b*x)^(3/2)*(c + d*x)^(3/2)), x, 5, -((b*(3*b*c - a*d))/(a^2*c*(b*c - a*d)*Sqrt[a + b*x]*Sqrt[c + d*x])) - 1/(a*c*x*Sqrt[a + b*x]*Sqrt[c + d*x]) - (d*(3*b^2*c^2 - 2*a*b*c*d + 3*a^2*d^2)*Sqrt[a + b*x])/(a^2*c^2*(b*c - a*d)^2*Sqrt[c + d*x]) + (3*(b*c + a*d)*ArcTanh[(Sqrt[c]*Sqrt[a + b*x])/(Sqrt[a]*Sqrt[c + d*x])])/(a^(5/2)*c^(5/2))}
{1/(x^3*(a + b*x)^(3/2)*(c + d*x)^(3/2)), x, 6, (b*(15*b^2*c^2 - 2*a*b*c*d - 5*a^2*d^2))/(4*a^3*c^2*(b*c - a*d)*Sqrt[a + b*x]*Sqrt[c + d*x]) - 1/(2*a*c*x^2*Sqrt[a + b*x]*Sqrt[c + d*x]) + (5*(b*c + a*d))/(4*a^2*c^2*x*Sqrt[a + b*x]*Sqrt[c + d*x]) + (d*(b*c + a*d)*(15*b^2*c^2 - 22*a*b*c*d + 15*a^2*d^2)*Sqrt[a + b*x])/(4*a^3*c^3*(b*c - a*d)^2*Sqrt[c + d*x]) - (3*(5*b^2*c^2 + 6*a*b*c*d + 5*a^2*d^2)*ArcTanh[(Sqrt[c]*Sqrt[a + b*x])/(Sqrt[a]*Sqrt[c + d*x])])/(4*a^(7/2)*c^(7/2))}


{x^5/((a + b*x)^(3/2)*(c + d*x)^(5/2)), x, 6, (a*(b*c - 5*a*d)*x^3)/(2*b^2*d*(b*c - a*d)*Sqrt[a + b*x]*(c + d*x)^(3/2)) + x^4/(2*b*d*Sqrt[a + b*x]*(c + d*x)^(3/2)) + (c*(7*b^2*c^2 - 6*a*b*c*d + 15*a^2*d^2)*x^2*Sqrt[a + b*x])/(6*b^2*d^2*(b*c - a*d)^2*(c + d*x)^(3/2)) - ((3*b*c - a*d)*(35*b^3*c^3 - 33*a*b^2*c^2*d - 15*a^2*b*c*d^2 + 45*a^3*d^3)*Sqrt[a + b*x]*Sqrt[c + d*x])/(12*b^3*d^4*(b*c - a*d)^3) + (c*Sqrt[a + b*x]*(4*a*c*(7*b^2*c^2 - 6*a*b*c*d + 15*a^2*d^2) + (35*b^3*c^3 - 33*a*b^2*c^2*d - 15*a^2*b*c*d^2 + 45*a^3*d^3)*x))/(6*b^2*d^3*(b*c - a*d)^3*Sqrt[c + d*x]) + (5*(7*b^2*c^2 + 6*a*b*c*d + 3*a^2*d^2)*ArcTanh[(Sqrt[d]*Sqrt[a + b*x])/(Sqrt[b]*Sqrt[c + d*x])])/(4*b^(7/2)*d^(9/2))}
{x^4/((a + b*x)^(3/2)*(c + d*x)^(5/2)), x, 5, (a*(b*c - 3*a*d)*x^2)/(b^2*d*(b*c - a*d)*Sqrt[a + b*x]*(c + d*x)^(3/2)) + x^3/(b*d*Sqrt[a + b*x]*(c + d*x)^(3/2)) + (c*(15*b^3*c^3 - 35*a*b^2*c^2*d + 25*a^2*b*c*d^2 - 21*a^3*d^3)*Sqrt[a + b*x])/(3*b^2*d^3*(b*c - a*d)^3*Sqrt[c + d*x]) + (c*Sqrt[a + b*x]*(4*a*c*(b*c - 3*a*d) + (b*c - a*d)*(5*b*c + 3*a*d)*x))/(3*b^2*d^2*(b*c - a*d)^2*(c + d*x)^(3/2)) - ((5*b*c + 3*a*d)*ArcTanh[(Sqrt[d]*Sqrt[a + b*x])/(Sqrt[b]*Sqrt[c + d*x])])/(b^(5/2)*d^(7/2))}
{x^3/((a + b*x)^(3/2)*(c + d*x)^(5/2)), x, 5, -((2*x^3)/((b*c - a*d)*Sqrt[a + b*x]*(c + d*x)^(3/2))) + (8*c*x^2*Sqrt[a + b*x])/(3*(b*c - a*d)^2*(c + d*x)^(3/2)) - (2*(3*b*c - a*d)*(b*c + 3*a*d)*Sqrt[a + b*x]*Sqrt[c + d*x])/(3*b*d^2*(b*c - a*d)^3) + (4*c*Sqrt[a + b*x]*(8*a*c + (b*c + 3*a*d)*x))/(3*d*(b*c - a*d)^3*Sqrt[c + d*x]) + (2*ArcTanh[(Sqrt[d]*Sqrt[a + b*x])/(Sqrt[b]*Sqrt[c + d*x])])/(b^(3/2)*d^(5/2))}
{x^2/((a + b*x)^(3/2)*(c + d*x)^(5/2)), x, 3, -((2*a^2)/(b^2*(b*c - a*d)*Sqrt[a + b*x]*(c + d*x)^(3/2))) - (2*(b^2*c^2 + 3*a^2*d^2)*Sqrt[a + b*x])/(3*b^2*d*(b*c - a*d)^2*(c + d*x)^(3/2)) + (2*(b^2*c^2 - 6*a*b*c*d - 3*a^2*d^2)*Sqrt[a + b*x])/(3*b*d*(b*c - a*d)^3*Sqrt[c + d*x])}
{x/((a + b*x)^(3/2)*(c + d*x)^(5/2)), x, 3, (2*a)/(b*(b*c - a*d)*Sqrt[a + b*x]*(c + d*x)^(3/2)) + (2*(b*c + 3*a*d)*Sqrt[a + b*x])/(3*b*(b*c - a*d)^2*(c + d*x)^(3/2)) + (4*(b*c + 3*a*d)*Sqrt[a + b*x])/(3*(b*c - a*d)^3*Sqrt[c + d*x])}
{1/((a + b*x)^(3/2)*(c + d*x)^(5/2)), x, 3, -(2/((b*c - a*d)*Sqrt[a + b*x]*(c + d*x)^(3/2))) - (8*d*Sqrt[a + b*x])/(3*(b*c - a*d)^2*(c + d*x)^(3/2)) - (16*b*d*Sqrt[a + b*x])/(3*(b*c - a*d)^3*Sqrt[c + d*x])}
{1/(x*(a + b*x)^(3/2)*(c + d*x)^(5/2)), x, 5, (2*b)/(a*(b*c - a*d)*Sqrt[a + b*x]*(c + d*x)^(3/2)) + (2*d*(3*b*c + a*d)*Sqrt[a + b*x])/(3*a*c*(b*c - a*d)^2*(c + d*x)^(3/2)) + (2*d*(3*b*c - a*d)*(b*c + 3*a*d)*Sqrt[a + b*x])/(3*a*c^2*(b*c - a*d)^3*Sqrt[c + d*x]) - (2*ArcTanh[(Sqrt[c]*Sqrt[a + b*x])/(Sqrt[a]*Sqrt[c + d*x])])/(a^(3/2)*c^(5/2))}
{1/(x^2*(a + b*x)^(3/2)*(c + d*x)^(5/2)), x, 6, -((b*(3*b*c - a*d))/(a^2*c*(b*c - a*d)*Sqrt[a + b*x]*(c + d*x)^(3/2))) - 1/(a*c*x*Sqrt[a + b*x]*(c + d*x)^(3/2)) - (d*(9*b^2*c^2 - 6*a*b*c*d + 5*a^2*d^2)*Sqrt[a + b*x])/(3*a^2*c^2*(b*c - a*d)^2*(c + d*x)^(3/2)) - (d*(9*b^3*c^3 - 9*a*b^2*c^2*d + 31*a^2*b*c*d^2 - 15*a^3*d^3)*Sqrt[a + b*x])/(3*a^2*c^3*(b*c - a*d)^3*Sqrt[c + d*x]) + ((3*b*c + 5*a*d)*ArcTanh[(Sqrt[c]*Sqrt[a + b*x])/(Sqrt[a]*Sqrt[c + d*x])])/(a^(5/2)*c^(7/2))}
{1/(x^3*(a + b*x)^(3/2)*(c + d*x)^(5/2)), x, 7, (b*(15*b^2*c^2 - 7*a^2*d^2))/(4*a^3*c^2*(b*c - a*d)*Sqrt[a + b*x]*(c + d*x)^(3/2)) - 1/(2*a*c*x^2*Sqrt[a + b*x]*(c + d*x)^(3/2)) + (5*b*c + 7*a*d)/(4*a^2*c^2*x*Sqrt[a + b*x]*(c + d*x)^(3/2)) + (d*(45*b^3*c^3 - 15*a*b^2*c^2*d - 33*a^2*b*c*d^2 + 35*a^3*d^3)*Sqrt[a + b*x])/(12*a^3*c^3*(b*c - a*d)^2*(c + d*x)^(3/2)) + (d*(45*b^4*c^4 - 30*a*b^3*c^3*d - 36*a^2*b^2*c^2*d^2 + 190*a^3*b*c*d^3 - 105*a^4*d^4)*Sqrt[a + b*x])/(12*a^3*c^4*(b*c - a*d)^3*Sqrt[c + d*x]) - (5*(3*b^2*c^2 + 6*a*b*c*d + 7*a^2*d^2)*ArcTanh[(Sqrt[c]*Sqrt[a + b*x])/(Sqrt[a]*Sqrt[c + d*x])])/(4*a^(7/2)*c^(9/2))}


(* ::Subsection::Closed:: *)
(*Integrands of the form x^m (c+d x)^(n/2) / (a+b x)^(5/2)*)


(* ::Subsubsection::Closed:: *)
(*n>0*)


{(x^4*(c + d*x)^(5/2))/(a + b*x)^(5/2), x, 8, ((3*b^4*c^4 + 28*a*b^3*c^3*d + 378*a^2*b^2*c^2*d^2 - 2772*a^3*b*c*d^3 + 3003*a^4*d^4)*Sqrt[a + b*x]*Sqrt[c + d*x])/(128*b^7*d^2) + ((3*b^4*c^4 + 28*a*b^3*c^3*d + 378*a^2*b^2*c^2*d^2 - 2772*a^3*b*c*d^3 + 3003*a^4*d^4)*Sqrt[a + b*x]*(c + d*x)^(3/2))/(192*b^6*d^2*(b*c - a*d)) - (2*x^4*(c + d*x)^(5/2))/(3*b*(a + b*x)^(3/2)) - (2*(8*b*c - 13*a*d)*x^3*(c + d*x)^(5/2))/(3*b^2*(b*c - a*d)*Sqrt[a + b*x]) - ((15*b^3*c^3 + 125*a*b^2*c^2*d - 2343*a^2*b*c*d^2 + 3003*a^3*d^3)*Sqrt[a + b*x]*(c + d*x)^(5/2))/(240*b^5*d^2*(b*c - a*d)) + ((15*b^2*c^2 - 902*a*b*c*d + 1287*a^2*d^2)*x*Sqrt[a + b*x]*(c + d*x)^(5/2))/(120*b^4*d*(b*c - a*d)) + ((93*b*c - 143*a*d)*x^2*Sqrt[a + b*x]*(c + d*x)^(5/2))/(15*b^3*(b*c - a*d)) + ((b*c - a*d)*(3*b^4*c^4 + 28*a*b^3*c^3*d + 378*a^2*b^2*c^2*d^2 - 2772*a^3*b*c*d^3 + 3003*a^4*d^4)*ArcTanh[(Sqrt[d]*Sqrt[a + b*x])/(Sqrt[b]*Sqrt[c + d*x])])/(128*b^(15/2)*d^(5/2))}
{(x^3*(c + d*x)^(5/2))/(a + b*x)^(5/2), x, 7, (-5*(b^3*c^3 + 21*a*b^2*c^2*d - 189*a^2*b*c*d^2 + 231*a^3*d^3)*Sqrt[a + b*x]*Sqrt[c + d*x])/(64*b^6*d) - (5*(b^3*c^3 + 21*a*b^2*c^2*d - 189*a^2*b*c*d^2 + 231*a^3*d^3)*Sqrt[a + b*x]*(c + d*x)^(3/2))/(96*b^5*d*(b*c - a*d)) - (2*x^3*(c + d*x)^(5/2))/(3*b*(a + b*x)^(3/2)) - (2*(6*b*c - 11*a*d)*x^2*(c + d*x)^(5/2))/(3*b^2*(b*c - a*d)*Sqrt[a + b*x]) + ((5*b^2*c^2 - 156*a*b*c*d + 231*a^2*d^2)*Sqrt[a + b*x]*(c + d*x)^(5/2))/(24*b^4*d*(b*c - a*d)) + ((59*b*c - 99*a*d)*x*Sqrt[a + b*x]*(c + d*x)^(5/2))/(12*b^3*(b*c - a*d)) - (5*(b*c - a*d)*(b^3*c^3 + 21*a*b^2*c^2*d - 189*a^2*b*c*d^2 + 231*a^3*d^3)*ArcTanh[(Sqrt[d]*Sqrt[a + b*x])/(Sqrt[b]*Sqrt[c + d*x])])/(64*b^(13/2)*d^(3/2))}
{(x^2*(c + d*x)^(5/2))/(a + b*x)^(5/2), x, 6, (5*(b^2*c^2 - 14*a*b*c*d + 21*a^2*d^2)*Sqrt[a + b*x]*Sqrt[c + d*x])/(8*b^5) + (5*(b^2*c^2 - 14*a*b*c*d + 21*a^2*d^2)*Sqrt[a + b*x]*(c + d*x)^(3/2))/(12*b^4*(b*c - a*d)) + ((b^2*c^2 - 14*a*b*c*d + 21*a^2*d^2)*Sqrt[a + b*x]*(c + d*x)^(5/2))/(3*b^3*(b*c - a*d)^2) - (2*a^2*(c + d*x)^(7/2))/(3*b^2*(b*c - a*d)*(a + b*x)^(3/2)) + (4*a*(3*b*c - 5*a*d)*(c + d*x)^(7/2))/(3*b^2*(b*c - a*d)^2*Sqrt[a + b*x]) + (5*(b*c - a*d)*(b^2*c^2 - 14*a*b*c*d + 21*a^2*d^2)*ArcTanh[(Sqrt[d]*Sqrt[a + b*x])/(Sqrt[b]*Sqrt[c + d*x])])/(8*b^(11/2)*Sqrt[d])}
{(x*(c + d*x)^(5/2))/(a + b*x)^(5/2), x, 5, (5*d*(3*b*c - 7*a*d)*Sqrt[a + b*x]*Sqrt[c + d*x])/(4*b^4) + (5*d*(3*b*c - 7*a*d)*Sqrt[a + b*x]*(c + d*x)^(3/2))/(6*b^3*(b*c - a*d)) - (2*(3*b*c - 7*a*d)*(c + d*x)^(5/2))/(3*b^2*(b*c - a*d)*Sqrt[a + b*x]) + (2*a*(c + d*x)^(7/2))/(3*b*(b*c - a*d)*(a + b*x)^(3/2)) + (5*Sqrt[d]*(3*b*c - 7*a*d)*(b*c - a*d)*ArcTanh[(Sqrt[d]*Sqrt[a + b*x])/(Sqrt[b]*Sqrt[c + d*x])])/(4*b^(9/2))}
{(c + d*x)^(5/2)/(a + b*x)^(5/2), x, 4, (5*d^2*Sqrt[a + b*x]*Sqrt[c + d*x])/b^3 - (10*d*(c + d*x)^(3/2))/(3*b^2*Sqrt[a + b*x]) - (2*(c + d*x)^(5/2))/(3*b*(a + b*x)^(3/2)) + (5*d^(3/2)*(b*c - a*d)*ArcTanh[(Sqrt[d]*Sqrt[a + b*x])/(Sqrt[b]*Sqrt[c + d*x])])/b^(7/2)}
{(c + d*x)^(5/2)/(x*(a + b*x)^(5/2)), x, 6, (-2*d*(b*c + a*d)*Sqrt[a + b*x]*Sqrt[c + d*x])/(a^2*b^2) + (2*(3*b*c + 2*a*d)*(c + d*x)^(3/2))/(3*a^2*b*Sqrt[a + b*x]) + (2*(c + d*x)^(5/2))/(3*a*(a + b*x)^(3/2)) - (2*c^(5/2)*ArcTanh[(Sqrt[c]*Sqrt[a + b*x])/(Sqrt[a]*Sqrt[c + d*x])])/a^(5/2) + (2*d^(5/2)*ArcTanh[(Sqrt[d]*Sqrt[a + b*x])/(Sqrt[b]*Sqrt[c + d*x])])/b^(5/2)}
{(c + d*x)^(5/2)/(x^2*(a + b*x)^(5/2)), x, 4, (-5*c*(b*c - a*d)*Sqrt[c + d*x])/(a^3*Sqrt[a + b*x]) - (5*(b*c - a*d)*(c + d*x)^(3/2))/(3*a^2*(a + b*x)^(3/2)) - (c + d*x)^(5/2)/(a*x*(a + b*x)^(3/2)) + (5*c^(3/2)*(b*c - a*d)*ArcTanh[(Sqrt[c]*Sqrt[a + b*x])/(Sqrt[a]*Sqrt[c + d*x])])/a^(7/2)}
{(c + d*x)^(5/2)/(x^3*(a + b*x)^(5/2)), x, 6, ((35*b*c - 29*a*d)*(b*c - a*d)*Sqrt[c + d*x])/(12*a^3*(a + b*x)^(3/2)) + ((105*b^2*c^2 - 115*a*b*c*d + 16*a^2*d^2)*Sqrt[c + d*x])/(12*a^4*Sqrt[a + b*x]) + ((7*b*c - 5*a*d)*(c + d*x)^(3/2))/(4*a^2*x*(a + b*x)^(3/2)) - (c + d*x)^(5/2)/(2*a*x^2*(a + b*x)^(3/2)) - (5*Sqrt[c]*(7*b*c - 3*a*d)*(b*c - a*d)*ArcTanh[(Sqrt[c]*Sqrt[a + b*x])/(Sqrt[a]*Sqrt[c + d*x])])/(4*a^(9/2))}
{(c + d*x)^(5/2)/(x^4*(a + b*x)^(5/2)), x, 7, -((7*b*(15*b*c - 7*a*d)*(b*c - a*d)*Sqrt[c + d*x])/(24*a^4*(a + b*x)^(3/2))) - ((21*b*c - 5*a*d)*(b*c - a*d)*Sqrt[c + d*x])/(8*a^3*x*(a + b*x)^(3/2)) - (b*(315*b^2*c^2 - 420*a*b*c*d + 113*a^2*d^2)*Sqrt[c + d*x])/(24*a^5*Sqrt[a + b*x]) + ((9*b*c - 5*a*d)*(c + d*x)^(3/2))/(12*a^2*x^2*(a + b*x)^(3/2)) - (c + d*x)^(5/2)/(3*a*x^3*(a + b*x)^(3/2)) + (5*(b*c - a*d)*(21*b^2*c^2 - 14*a*b*c*d + a^2*d^2)*ArcTanh[(Sqrt[c]*Sqrt[a + b*x])/(Sqrt[a]*Sqrt[c + d*x])])/(8*a^(11/2)*Sqrt[c])}
{(c + d*x)^(5/2)/(x^5*(a + b*x)^(5/2)), x, 8, (b*(b*c - a*d)*(385*b^2*c^2 - 238*a*b*c*d + 5*a^2*d^2)*Sqrt[c + d*x])/(64*a^5*c*(a + b*x)^(3/2)) - ((33*b*c - 5*a*d)*(b*c - a*d)*Sqrt[c + d*x])/(32*a^3*x^2*(a + b*x)^(3/2)) + ((b*c - a*d)*(231*b^2*c^2 - 156*a*b*c*d + 5*a^2*d^2)*Sqrt[c + d*x])/(64*a^4*c*x*(a + b*x)^(3/2)) + (b*(1155*b^3*c^3 - 1715*a*b^2*c^2*d + 581*a^2*b*c*d^2 - 5*a^3*d^3)*Sqrt[c + d*x])/(64*a^6*c*Sqrt[a + b*x]) + ((11*b*c - 5*a*d)*(c + d*x)^(3/2))/(24*a^2*x^3*(a + b*x)^(3/2)) - (c + d*x)^(5/2)/(4*a*x^4*(a + b*x)^(3/2)) - (5*(b*c - a*d)*(231*b^3*c^3 - 189*a*b^2*c^2*d + 21*a^2*b*c*d^2 + a^3*d^3)*ArcTanh[(Sqrt[c]*Sqrt[a + b*x])/(Sqrt[a]*Sqrt[c + d*x])])/(64*a^(13/2)*c^(3/2))}


(* ::Subsubsection::Closed:: *)
(*n<0*)


{x^2/((a + b*x)^(5/2)*(c + d*x)^(1/2)), x, 3, -((2*a^2*Sqrt[c + d*x])/(3*b^2*(b*c - a*d)*(a + b*x)^(3/2))) + (4*a*(3*b*c - 2*a*d)*Sqrt[c + d*x])/(3*b^2*(b*c - a*d)^2*Sqrt[a + b*x]) + (2*ArcTanh[(Sqrt[d]*Sqrt[a + b*x])/(Sqrt[b]*Sqrt[c + d*x])])/(b^(5/2)*Sqrt[d])}


{x^6/((a + b*x)^(5/2)*(c + d*x)^(5/2)), x, 7, (a*(3*b*c - 7*a*d)*x^4)/(6*b^2*d*(b*c - a*d)*(a + b*x)^(3/2)*(c + d*x)^(3/2)) + x^5/(2*b*d*(a + b*x)^(3/2)*(c + d*x)^(3/2)) + (a*(3*b^2*c^2 - 62*a*b*c*d + 35*a^2*d^2)*x^3)/(6*b^3*d*(b*c - a*d)^2*Sqrt[a + b*x]*(c + d*x)^(3/2)) + (c*(7*b^3*c^3 - 9*a*b^2*c^2*d + 69*a^2*b*c*d^2 - 35*a^3*d^3)*x^2*Sqrt[a + b*x])/(6*b^3*d^2*(b*c - a*d)^3*(c + d*x)^(3/2)) - ((3*b*c - a*d)*(35*b^4*c^4 - 48*a*b^3*c^3*d - 18*a^2*b^2*c^2*d^2 + 200*a^3*b*c*d^3 - 105*a^4*d^4)*Sqrt[a + b*x]*Sqrt[c + d*x])/(12*b^4*d^4*(b*c - a*d)^4) + (c*Sqrt[a + b*x]*(4*a*c*(7*b^3*c^3 - 9*a*b^2*c^2*d + 69*a^2*b*c*d^2 - 35*a^3*d^3) + (35*b^4*c^4 - 48*a*b^3*c^3*d - 18*a^2*b^2*c^2*d^2 + 200*a^3*b*c*d^3 - 105*a^4*d^4)*x))/(6*b^3*d^3*(b*c - a*d)^4*Sqrt[c + d*x]) + (5*(7*b^2*c^2 + 10*a*b*c*d + 7*a^2*d^2)*ArcTanh[(Sqrt[d]*Sqrt[a + b*x])/(Sqrt[b]*Sqrt[c + d*x])])/(4*b^(9/2)*d^(9/2))}
{x^5/((a + b*x)^(5/2)*(c + d*x)^(5/2)), x, 6, (a*(3*b*c - 5*a*d)*x^3)/(3*b^2*d*(b*c - a*d)*(a + b*x)^(3/2)*(c + d*x)^(3/2)) + x^4/(b*d*(a + b*x)^(3/2)*(c + d*x)^(3/2)) + (a*(b^2*c^2 - 10*a*b*c*d + 5*a^2*d^2)*x^2)/(b^3*d*(b*c - a*d)^2*Sqrt[a + b*x]*(c + d*x)^(3/2)) + (c*(15*b^4*c^4 - 44*a*b^3*c^3*d + 62*a^2*b^2*c^2*d^2 - 100*a^3*b*c*d^3 + 35*a^4*d^4)*Sqrt[a + b*x])/(3*b^3*d^3*(b*c - a*d)^4*Sqrt[c + d*x]) + (c*Sqrt[a + b*x]*(4*a*c*(b^2*c^2 - 10*a*b*c*d + 5*a^2*d^2) + 5*(b*c - a*d)^2*(b*c + a*d)*x))/(3*b^3*d^2*(b*c - a*d)^3*(c + d*x)^(3/2)) - (5*(b*c + a*d)*ArcTanh[(Sqrt[d]*Sqrt[a + b*x])/(Sqrt[b]*Sqrt[c + d*x])])/(b^(7/2)*d^(7/2))}
{x^4/((a + b*x)^(5/2)*(c + d*x)^(5/2)), x, 6, -((2*x^4)/(3*(b*c - a*d)*(a + b*x)^(3/2)*(c + d*x)^(3/2))) - (4*(4*b*c - a*d)*x^3)/(3*b*(b*c - a*d)^2*Sqrt[a + b*x]*(c + d*x)^(3/2)) + (4*c*(5*b*c - a*d)*x^2*Sqrt[a + b*x])/(3*b*(b*c - a*d)^3*(c + d*x)^(3/2)) - (2*(3*b*c - a*d)*(b^2*c^2 + 10*a*b*c*d - 3*a^2*d^2)*Sqrt[a + b*x]*Sqrt[c + d*x])/(3*b^2*d^2*(b*c - a*d)^4) + (4*c*Sqrt[a + b*x]*(4*a*c*(5*b*c - a*d) + (b^2*c^2 + 10*a*b*c*d - 3*a^2*d^2)*x))/(3*b*d*(b*c - a*d)^4*Sqrt[c + d*x]) + (2*ArcTanh[(Sqrt[d]*Sqrt[a + b*x])/(Sqrt[b]*Sqrt[c + d*x])])/(b^(5/2)*d^(5/2))}
{x^3/((a + b*x)^(5/2)*(c + d*x)^(5/2)), x, 4, -((2*x^3)/(3*(b*c - a*d)*(a + b*x)^(3/2)*(c + d*x)^(3/2))) - (4*a^2*c)/(b^2*(b*c - a*d)^2*Sqrt[a + b*x]*(c + d*x)^(3/2)) - (4*c*(b^2*c^2 + 3*a^2*d^2)*Sqrt[a + b*x])/(3*b^2*d*(b*c - a*d)^3*(c + d*x)^(3/2)) + (4*c*(b^2*c^2 - 6*a*b*c*d - 3*a^2*d^2)*Sqrt[a + b*x])/(3*b*d*(b*c - a*d)^4*Sqrt[c + d*x])}
{x^2/((a + b*x)^(5/2)*(c + d*x)^(5/2)), x, 4, -((2*a^2)/(3*b^2*(b*c - a*d)*(a + b*x)^(3/2)*(c + d*x)^(3/2))) + (4*a*c)/(b*(b*c - a*d)^2*Sqrt[a + b*x]*(c + d*x)^(3/2)) + (2*(b^2*c^2 + 6*a*b*c*d + a^2*d^2)*Sqrt[a + b*x])/(3*b^2*(b*c - a*d)^3*(c + d*x)^(3/2)) + (4*(b^2*c^2 + 6*a*b*c*d + a^2*d^2)*Sqrt[a + b*x])/(3*b*(b*c - a*d)^4*Sqrt[c + d*x])}
{x^1/((a + b*x)^(5/2)*(c + d*x)^(5/2)), x, 4, -((2*c)/(3*d*(b*c - a*d)*(a + b*x)^(3/2)*(c + d*x)^(3/2))) + (2*(b*c + a*d))/(3*d*(b*c - a*d)^2*(a + b*x)^(3/2)*Sqrt[c + d*x]) - (8*(b*c + a*d))/(3*(b*c - a*d)^3*Sqrt[a + b*x]*Sqrt[c + d*x]) - (16*d*(b*c + a*d)*Sqrt[a + b*x])/(3*(b*c - a*d)^4*Sqrt[c + d*x])}
{x^0/((a + b*x)^(5/2)*(c + d*x)^(5/2)), x, 4, -(2/(3*(b*c - a*d)*(a + b*x)^(3/2)*(c + d*x)^(3/2))) + (4*d)/((b*c - a*d)^2*Sqrt[a + b*x]*(c + d*x)^(3/2)) + (16*d^2*Sqrt[a + b*x])/(3*(b*c - a*d)^3*(c + d*x)^(3/2)) + (32*b*d^2*Sqrt[a + b*x])/(3*(b*c - a*d)^4*Sqrt[c + d*x])}
{1/(x^1*(a + b*x)^(5/2)*(c + d*x)^(5/2)), x, 6, (2*b)/(3*a*(b*c - a*d)*(a + b*x)^(3/2)*(c + d*x)^(3/2)) + (2*b*(b*c - 3*a*d))/(a^2*(b*c - a*d)^2*Sqrt[a + b*x]*(c + d*x)^(3/2)) + (2*d*(3*b^2*c^2 - 10*a*b*c*d - a^2*d^2)*Sqrt[a + b*x])/(3*a^2*c*(b*c - a*d)^3*(c + d*x)^(3/2)) + (2*d*(b*c + a*d)*(3*b^2*c^2 - 14*a*b*c*d + 3*a^2*d^2)*Sqrt[a + b*x])/(3*a^2*c^2*(b*c - a*d)^4*Sqrt[c + d*x]) - (2*ArcTanh[(Sqrt[c]*Sqrt[a + b*x])/(Sqrt[a]*Sqrt[c + d*x])])/(a^(5/2)*c^(5/2))}
{1/(x^2*(a + b*x)^(5/2)*(c + d*x)^(5/2)), x, 7, -((b*(5*b*c - 3*a*d))/(3*a^2*c*(b*c - a*d)*(a + b*x)^(3/2)*(c + d*x)^(3/2))) - 1/(a*c*x*(a + b*x)^(3/2)*(c + d*x)^(3/2)) - (b*(5*b^2*c^2 - 10*a*b*c*d + a^2*d^2))/(a^3*c*(b*c - a*d)^2*Sqrt[a + b*x]*(c + d*x)^(3/2)) - (d*(15*b^3*c^3 - 35*a*b^2*c^2*d + 9*a^2*b*c*d^2 - 5*a^3*d^3)*Sqrt[a + b*x])/(3*a^3*c^2*(b*c - a*d)^3*(c + d*x)^(3/2)) - (d*(15*b^4*c^4 - 40*a*b^3*c^3*d + 18*a^2*b^2*c^2*d^2 - 40*a^3*b*c*d^3 + 15*a^4*d^4)*Sqrt[a + b*x])/(3*a^3*c^3*(b*c - a*d)^4*Sqrt[c + d*x]) + (5*(b*c + a*d)*ArcTanh[(Sqrt[c]*Sqrt[a + b*x])/(Sqrt[a]*Sqrt[c + d*x])])/(a^(7/2)*c^(7/2))}
{1/(x^3*(a + b*x)^(5/2)*(c + d*x)^(5/2)), x, 8, (b*(35*b^2*c^2 - 6*a*b*c*d - 21*a^2*d^2))/(12*a^3*c^2*(b*c - a*d)*(a + b*x)^(3/2)*(c + d*x)^(3/2)) - 1/(2*a*c*x^2*(a + b*x)^(3/2)*(c + d*x)^(3/2)) + (7*(b*c + a*d))/(4*a^2*c^2*x*(a + b*x)^(3/2)*(c + d*x)^(3/2)) + (b*(35*b^3*c^3 - 55*a*b^2*c^2*d - 3*a^2*b*c*d^2 + 7*a^3*d^3))/(4*a^4*c^2*(b*c - a*d)^2*Sqrt[a + b*x]*(c + d*x)^(3/2)) + (d*(105*b^4*c^4 - 200*a*b^3*c^3*d + 18*a^2*b^2*c^2*d^2 + 48*a^3*b*c*d^3 - 35*a^4*d^4)*Sqrt[a + b*x])/(12*a^4*c^3*(b*c - a*d)^3*(c + d*x)^(3/2)) + (d*(b*c + a*d)*(105*b^4*c^4 - 340*a*b^3*c^3*d + 406*a^2*b^2*c^2*d^2 - 340*a^3*b*c*d^3 + 105*a^4*d^4)*Sqrt[a + b*x])/(12*a^4*c^4*(b*c - a*d)^4*Sqrt[c + d*x]) - (5*(7*b^2*c^2 + 10*a*b*c*d + 7*a^2*d^2)*ArcTanh[(Sqrt[c]*Sqrt[a + b*x])/(Sqrt[a]*Sqrt[c + d*x])])/(4*a^(9/2)*c^(9/2))}


(* ::Subsection::Closed:: *)
(*Integrands of the form x^m (c+d x)^(n/2) (a+b x)^(p/2)*)


(* Note that the derivative of (a+b*x)^n/(-a-b*x)^n is zero. *)
{x^2*Sqrt[a + b*x]/Sqrt[-a - b*x], x, 2, (x^3*Sqrt[a + b*x])/(3*Sqrt[-a - b*x])}
{x*Sqrt[a + b*x]/Sqrt[-a - b*x], x, 2, (x^2*Sqrt[a + b*x])/(2*Sqrt[-a - b*x])}
{Sqrt[a + b*x]/Sqrt[-a - b*x], x, 2, (x*Sqrt[a + b*x])/Sqrt[-a - b*x]}
{Sqrt[a + b*x]/(x*Sqrt[-a - b*x]), x, 2, (Sqrt[a + b*x]*Log[x])/Sqrt[-a - b*x]}
{Sqrt[a + b*x]/(x^2*Sqrt[-a - b*x]), x, 2, -(Sqrt[a + b*x]/(x*Sqrt[-a - b*x]))}
{Sqrt[a + b*x]/(x^3*Sqrt[-a - b*x]), x, 2, -(Sqrt[a + b*x]/(2*x^2*Sqrt[-a - b*x]))}
{Sqrt[a + b*x]/(x^m*Sqrt[-a - b*x]), x, 2, (x^(1 - m)*Sqrt[a + b*x])/((1 - m)*Sqrt[-a - b*x])}

{x^2*((a + b*x)^n/(-a - b*x)^n), x, 2, ((1/3)*x^3*(a + b*x)^n)/(-a - b*x)^n}
{x*((a + b*x)^n/(-a - b*x)^n), x, 2, ((1/2)*x^2*(a + b*x)^n)/(-a - b*x)^n}
{((a + b*x)^n/(-a - b*x)^n), x, 2, (x*(a + b*x)^n)/(-a - b*x)^n}
{((a + b*x)^n/(x*(-a - b*x)^n)), x, 2, ((a + b*x)^n*Log[x])/(-a - b*x)^n}
{((a + b*x)^n/(x^2*(-a - b*x)^n)), x, 2, -((a + b*x)^n/((-a - b*x)^n*x))}
{((a + b*x)^n/(x^3*(-a - b*x)^n)), x, 2, -((a + b*x)^n/((-a - b*x)^n*(2*x^2)))}
{((a + b*x)^n/(x^m*(-a - b*x)^n)), x, 2, (x^(1 - m)*(a + b*x)^n)/((-a - b*x)^n*(1 - m))}


{x^3*Sqrt[1 + x]/(1 - x)^(5/2), x, 5, -((6*Sqrt[1 + x])/Sqrt[1 - x]) - 3*Sqrt[1 - x]*Sqrt[1 + x] + (1 + x)^(3/2)/(3*(1 - x)^(3/2)) - (1/2)*x*Sqrt[1 - x^2] + (11*ArcSin[x])/2, (-(13/3))*Sqrt[1 - x]*Sqrt[1 + x] - (13*x^2*Sqrt[1 + x])/(3*Sqrt[1 - x]) + (2*x^3*Sqrt[1 + x])/(3*(1 - x)^(3/2)) - (1/6)*Sqrt[1 - x]*Sqrt[1 + x]*(26 + 33*x) + (11*ArcSin[x])/2}
{x^2*Sqrt[1 + x]/(1 - x)^(5/2), x, 5, -((4*Sqrt[1 + x])/Sqrt[1 - x]) - Sqrt[1 - x]*Sqrt[1 + x] + (1 + x)^(3/2)/(3*(1 - x)^(3/2)) + 3*ArcSin[x], -3*Sqrt[1 - x]*Sqrt[1 + x] + (1 + x)^(3/2)/(3*(1 - x)^(3/2)) - (2*(1 + x)^(3/2))/Sqrt[1 - x] + 3*ArcSin[x]}
{x*Sqrt[1 + x]/(1 - x)^(5/2), x, 3, -((2*Sqrt[1 + x])/Sqrt[1 - x]) + (1 + x)^(3/2)/(3*(1 - x)^(3/2)) + ArcSin[x]}
{Sqrt[1 + x]/(1 - x)^(5/2), x, 1, (1 + x)^(3/2)/(3*(1 - x)^(3/2))}
{Sqrt[1 + x]/(-1 + x)^(5/2), x, 1, -((1 + x)^(3/2)/(3*(-1 + x)^(3/2)))}
{Sqrt[1 + x]/(x*(1 - x)^(5/2)), x, 4, (2*Sqrt[1 + x])/(3*(1 - x)^(3/2)) + (5*Sqrt[1 + x])/(3*Sqrt[1 - x]) - 2*ArcTanh[Sqrt[1 - x]/Sqrt[1 + x]]}
{Sqrt[1 + x]/(x^2*(1 - x)^(5/2)), x, 5, (2*Sqrt[1 + x])/(3*(1 - x)^(3/2)*x) + (3*Sqrt[1 + x])/(Sqrt[1 - x]*x) - (14*Sqrt[1 - x]*Sqrt[1 + x])/(3*x) - 6*ArcTanh[Sqrt[1 - x]/Sqrt[1 + x]]}
{Sqrt[1 + x]/(x^3*(1 - x)^(5/2)), x, 6, (2*Sqrt[1 + x])/(3*(1 - x)^(3/2)*x^2) + (13*Sqrt[1 + x])/(3*Sqrt[1 - x]*x^2) - (11*Sqrt[1 - x]*Sqrt[1 + x])/(2*x^2) - (26*Sqrt[1 - x]*Sqrt[1 + x])/(3*x) - 11*ArcTanh[Sqrt[1 - x]/Sqrt[1 + x]]}


{x^2/(Sqrt[-1 + x]*Sqrt[1 + x]), x, 2, (1/2)*Sqrt[-1 + x]*x*Sqrt[1 + x] + ArcCosh[x]/2}
{x/(Sqrt[-1 + x]*Sqrt[1 + x]), x, 1, Sqrt[-1 + x]*Sqrt[1 + x]}
{1/(Sqrt[-1 + x]*Sqrt[1 + x]), x, 1, ArcCosh[x]}
{1/(x*Sqrt[-1 + x]*Sqrt[1 + x]), x, 1, 2*ArcTan[Sqrt[-1 + x]/Sqrt[1 + x]]}
{1/(x^2*Sqrt[-1 + x]*Sqrt[1 + x]), x, 2, (Sqrt[-1 + x]*Sqrt[1 + x])/x}

{x^2*Sqrt[-1 + x]*Sqrt[1 + x], x, 4, (-(1/8))*Sqrt[-1 + x]*x*Sqrt[1 + x] + (1/4)*Sqrt[-1 + x]*x^3*Sqrt[1 + x] - ArcCosh[x]/8, (1/8)*Sqrt[-1 + x]*Sqrt[1 + x] + (1/8)*(-1 + x)^(3/2)*Sqrt[1 + x] + (1/4)*(-1 + x)^(3/2)*x*(1 + x)^(3/2) - ArcCosh[x]/8}
{x*Sqrt[-1 + x]*Sqrt[1 + x], x, 1, ((-1 + x)^(3/2)*(1 + x)^(3/2))/3}
{Sqrt[-1 + x]*Sqrt[1 + x], x, 3, (1/2)*Sqrt[-1 + x]*x*Sqrt[1 + x] - ArcCosh[x]/2, (1/2)*Sqrt[-1 + x]*Sqrt[1 + x] + (1/2)*(-1 + x)^(3/2)*Sqrt[1 + x] - ArcCosh[x]/2}
{Sqrt[-1 + x]*Sqrt[1 + x]/x, x, 2, Sqrt[-1 + x]*Sqrt[1 + x] - 2*ArcTan[Sqrt[-1 + x]/Sqrt[1 + x]]}
{Sqrt[-1 + x]*Sqrt[1 + x]/x^2, x, 2, -((Sqrt[-1 + x]*Sqrt[1 + x])/x) + ArcCosh[x]}

{1/(Sqrt[1 + 2*x]*Sqrt[3 + 2*x]), x, 1, ArcSinh[Sqrt[1 + 2*x]/Sqrt[2]]}
{1/(x*Sqrt[-2 + 3*x]*Sqrt[3 + 5*x]), x, 1, Sqrt[2/3]*ArcTan[(Sqrt[3/2]*Sqrt[-2 + 3*x])/Sqrt[3 + 5*x]]}

{1/(x*(1 + x)^(3/2)*(-1 + x)^(3/2)), x, 2, -(1/(Sqrt[-1 + x]*Sqrt[1 + x])) - 2*ArcTan[Sqrt[-1 + x]/Sqrt[1 + x]]}

{x*Sqrt[1 - x]*Sqrt[1 + x], x, 1, (-(1/3))*(1 - x)^(3/2)*(1 + x)^(3/2)}

{x^3*(2 + 3*x)^(3/2)*(1 + 4*x)^(1/2), x, 7, (213575*Sqrt[2 + 3*x]*Sqrt[1 + 4*x])/42467328 - (42715*(2 + 3*x)^(3/2)*Sqrt[1 + 4*x])/5308416 + (22357*(2 + 3*x)^(3/2)*(1 + 4*x)^(3/2))/6635520 + ((8 - 403*x)*(2 + 3*x)^(3/2)*(1 + 4*x)^(3/2))/92160 - (1/960)*x^2*(2 + 3*x)^(3/2)*(1 + 4*x)^(3/2) + (1/24)*x^3*(2 + 3*x)^(3/2)*(1 + 4*x)^(3/2) + (1067875*ArcSinh[Sqrt[3/5]*Sqrt[1 + 4*x]])/(84934656*Sqrt[3])}


{1/(Sqrt[-1 + a + b*x]*Sqrt[1 + a + b*x]), x, 1, (2/b)*ArcSinh[Sqrt[-1 + a + b*x]/Sqrt[2]]}


(* ::Section::Closed:: *)
(*Integrands of the form x^m (a+b x)^(n/4) (c+d x)^(p/4)*)


{(1 + x)^(1/4)/(1 - x)^(1/4)*x^2, x, 11, (-(3/8))*(1 - x)^(3/4)*(1 + x)^(1/4) - (1/12)*(1 - x)^(3/4)*(1 + x)^(5/4) - (1/3)*(1 - x)^(3/4)*x*(1 + x)^(5/4) + (3*ArcTan[1 - (Sqrt[2]*(1 - x)^(1/4))/(1 + x)^(1/4)])/(8*Sqrt[2]) - (3*ArcTan[1 + (Sqrt[2]*(1 - x)^(1/4))/(1 + x)^(1/4)])/(8*Sqrt[2]) - (3*Log[1 + Sqrt[1 - x]/Sqrt[1 + x] - (Sqrt[2]*(1 - x)^(1/4))/(1 + x)^(1/4)])/(16*Sqrt[2]) + (3*Log[1 + Sqrt[1 - x]/Sqrt[1 + x] + (Sqrt[2]*(1 - x)^(1/4))/(1 + x)^(1/4)])/(16*Sqrt[2])}
{(1 + x)^(1/4)/(1 - x)^(1/4)*x^1, x, 10, (-(1/4))*(1 - x)^(3/4)*(1 + x)^(1/4) - (1/2)*(1 - x)^(3/4)*(1 + x)^(5/4) + ArcTan[1 - (Sqrt[2]*(1 - x)^(1/4))/(1 + x)^(1/4)]/(4*Sqrt[2]) - ArcTan[1 + (Sqrt[2]*(1 - x)^(1/4))/(1 + x)^(1/4)]/(4*Sqrt[2]) - Log[1 + Sqrt[1 - x]/Sqrt[1 + x] - (Sqrt[2]*(1 - x)^(1/4))/(1 + x)^(1/4)]/(8*Sqrt[2]) + Log[1 + Sqrt[1 - x]/Sqrt[1 + x] + (Sqrt[2]*(1 - x)^(1/4))/(1 + x)^(1/4)]/(8*Sqrt[2])}
{(1 + x)^(1/4)/(1 - x)^(1/4)*x^0, x, 9, (-(1 - x)^(3/4))*(1 + x)^(1/4) + ArcTan[1 - (Sqrt[2]*(1 - x)^(1/4))/(1 + x)^(1/4)]/Sqrt[2] - ArcTan[1 + (Sqrt[2]*(1 - x)^(1/4))/(1 + x)^(1/4)]/Sqrt[2] - Log[1 + Sqrt[1 - x]/Sqrt[1 + x] - (Sqrt[2]*(1 - x)^(1/4))/(1 + x)^(1/4)]/(2*Sqrt[2]) + Log[1 + Sqrt[1 - x]/Sqrt[1 + x] + (Sqrt[2]*(1 - x)^(1/4))/(1 + x)^(1/4)]/(2*Sqrt[2])}
{(1 + x)^(1/4)/(1 - x)^(1/4)/x^1, x, 12, -2*ArcTan[(1 + x)^(1/4)/(1 - x)^(1/4)] - Sqrt[2]*ArcTan[1 - (Sqrt[2]*(1 + x)^(1/4))/(1 - x)^(1/4)] + Sqrt[2]*ArcTan[1 + (Sqrt[2]*(1 + x)^(1/4))/(1 - x)^(1/4)] - 2*ArcTanh[(1 + x)^(1/4)/(1 - x)^(1/4)] - Log[1 - (Sqrt[2]*(1 + x)^(1/4))/(1 - x)^(1/4) + Sqrt[1 + x]/Sqrt[1 - x]]/Sqrt[2] + Log[1 + (Sqrt[2]*(1 + x)^(1/4))/(1 - x)^(1/4) + Sqrt[1 + x]/Sqrt[1 - x]]/Sqrt[2]}
{(1 + x)^(1/4)/(1 - x)^(1/4)/x^2, x, 5, -(((1 - x)^(3/4)*(1 + x)^(1/4))/x) + ArcTan[(1 - x)^(1/4)/(1 + x)^(1/4)] - ArcTanh[(1 - x)^(1/4)/(1 + x)^(1/4)]}
{(1 + x)^(1/4)/(1 - x)^(1/4)/x^3, x, 7, -(((1 - x)^(3/4)*(1 + x)^(1/4))/(2*x^2)) - (3*(1 - x)^(3/4)*(1 + x)^(1/4))/(4*x) + (1/4)*ArcTan[(1 - x)^(1/4)/(1 + x)^(1/4)] - (1/4)*ArcTanh[(1 - x)^(1/4)/(1 + x)^(1/4)]}
{(1 + x)^(1/4)/(1 - x)^(1/4)/x^4, x, 8, -(((1 - x)^(3/4)*(1 + x)^(1/4))/(3*x^3)) - (5*(1 - x)^(3/4)*(1 + x)^(1/4))/(12*x^2) - (11*(1 - x)^(3/4)*(1 + x)^(1/4))/(24*x) + (3/8)*ArcTan[(1 - x)^(1/4)/(1 + x)^(1/4)] - (3/8)*ArcTanh[(1 - x)^(1/4)/(1 + x)^(1/4)]}


{(a + b*x)^(1/4)/(c + d*x)^(1/4)*x^3, x, 8, -(((585*b^3*c^3 - 63*a*b^2*c^2*d - 61*a^2*b*c*d^2 - 77*a^3*d^3)*(a + b*x)^(1/4)*(c + d*x)^(3/4))/(1536*b^3*d^4)) - ((10*a*c - (117*b*c^2)/d + (11*a^2*d)/b)*x*(a + b*x)^(1/4)*(c + d*x)^(3/4))/(384*b*d^2) - ((13*b*c - a*d)*x^2*(a + b*x)^(1/4)*(c + d*x)^(3/4))/(48*b*d^2) + (x^3*(a + b*x)^(1/4)*(c + d*x)^(3/4))/(4*d) + ((b*c - a*d)*(195*b^3*c^3 + 135*a*b^2*c^2*d + 105*a^2*b*c*d^2 + 77*a^3*d^3)*ArcTan[(d^(1/4)*(a + b*x)^(1/4))/(b^(1/4)*(c + d*x)^(1/4))])/(1024*b^(15/4)*d^(17/4)) + ((b*c - a*d)*(195*b^3*c^3 + 135*a*b^2*c^2*d + 105*a^2*b*c*d^2 + 77*a^3*d^3)*ArcTanh[(d^(1/4)*(a + b*x)^(1/4))/(b^(1/4)*(c + d*x)^(1/4))])/(1024*b^(15/4)*d^(17/4))}
{(a + b*x)^(1/4)/(c + d*x)^(1/4)*x^2, x, 7, ((15*b^2*c^2 + 10*a*b*c*d + 7*a^2*d^2)*(a + b*x)^(1/4)*(c + d*x)^(3/4))/(32*b^2*d^3) - ((9*b*c + 7*a*d)*(a + b*x)^(5/4)*(c + d*x)^(3/4))/(24*b^2*d^2) + (x*(a + b*x)^(5/4)*(c + d*x)^(3/4))/(3*b*d) - ((b*c - a*d)*(15*b^2*c^2 + 10*a*b*c*d + 7*a^2*d^2)*ArcTan[(d^(1/4)*(a + b*x)^(1/4))/(b^(1/4)*(c + d*x)^(1/4))])/(64*b^(11/4)*d^(13/4)) - ((b*c - a*d)*(15*b^2*c^2 + 10*a*b*c*d + 7*a^2*d^2)*ArcTanh[(d^(1/4)*(a + b*x)^(1/4))/(b^(1/4)*(c + d*x)^(1/4))])/(64*b^(11/4)*d^(13/4))}
{(a + b*x)^(1/4)/(c + d*x)^(1/4)*x^1, x, 6, -(((5*b*c + 3*a*d)*(a + b*x)^(1/4)*(c + d*x)^(3/4))/(8*b*d^2)) + ((a + b*x)^(5/4)*(c + d*x)^(3/4))/(2*b*d) + ((b*c - a*d)*(5*b*c + 3*a*d)*ArcTan[(d^(1/4)*(a + b*x)^(1/4))/(b^(1/4)*(c + d*x)^(1/4))])/(16*b^(7/4)*d^(9/4)) + ((b*c - a*d)*(5*b*c + 3*a*d)*ArcTanh[(d^(1/4)*(a + b*x)^(1/4))/(b^(1/4)*(c + d*x)^(1/4))])/(16*b^(7/4)*d^(9/4))}
{(a + b*x)^(1/4)/(c + d*x)^(1/4)*x^0, x, 5, ((a + b*x)^(1/4)*(c + d*x)^(3/4))/d - ((b*c - a*d)*ArcTan[(d^(1/4)*(a + b*x)^(1/4))/(b^(1/4)*(c + d*x)^(1/4))])/(2*b^(3/4)*d^(5/4)) - ((b*c - a*d)*ArcTanh[(d^(1/4)*(a + b*x)^(1/4))/(b^(1/4)*(c + d*x)^(1/4))])/(2*b^(3/4)*d^(5/4))}
{(a + b*x)^(1/4)/(c + d*x)^(1/4)/x^1, x, 8, -((2*a^(1/4)*ArcTan[(c^(1/4)*(a + b*x)^(1/4))/(a^(1/4)*(c + d*x)^(1/4))])/c^(1/4)) + (2*b^(1/4)*ArcTan[(d^(1/4)*(a + b*x)^(1/4))/(b^(1/4)*(c + d*x)^(1/4))])/d^(1/4) - (2*a^(1/4)*ArcTanh[(c^(1/4)*(a + b*x)^(1/4))/(a^(1/4)*(c + d*x)^(1/4))])/c^(1/4) + (2*b^(1/4)*ArcTanh[(d^(1/4)*(a + b*x)^(1/4))/(b^(1/4)*(c + d*x)^(1/4))])/d^(1/4)}
{(a + b*x)^(1/4)/(c + d*x)^(1/4)/x^2, x, 5, -(((a + b*x)^(1/4)*(c + d*x)^(3/4))/(c*x)) - ((b*c - a*d)*ArcTan[(c^(1/4)*(a + b*x)^(1/4))/(a^(1/4)*(c + d*x)^(1/4))])/(2*a^(3/4)*c^(5/4)) - ((b*c - a*d)*ArcTanh[(c^(1/4)*(a + b*x)^(1/4))/(a^(1/4)*(c + d*x)^(1/4))])/(2*a^(3/4)*c^(5/4))}
{(a + b*x)^(1/4)/(c + d*x)^(1/4)/x^3, x, 7, -(((a + b*x)^(1/4)*(c + d*x)^(3/4))/(2*c*x^2)) - ((b*c - 5*a*d)*(a + b*x)^(1/4)*(c + d*x)^(3/4))/(8*a*c^2*x) + ((b*c - a*d)*(3*b*c + 5*a*d)*ArcTan[(c^(1/4)*(a + b*x)^(1/4))/(a^(1/4)*(c + d*x)^(1/4))])/(16*a^(7/4)*c^(9/4)) + ((b*c - a*d)*(3*b*c + 5*a*d)*ArcTanh[(c^(1/4)*(a + b*x)^(1/4))/(a^(1/4)*(c + d*x)^(1/4))])/(16*a^(7/4)*c^(9/4))}
{(a + b*x)^(1/4)/(c + d*x)^(1/4)/x^4, x, 8, -(((a + b*x)^(1/4)*(c + d*x)^(3/4))/(3*c*x^3)) - ((b*c - 9*a*d)*(a + b*x)^(1/4)*(c + d*x)^(3/4))/(24*a*c^2*x^2) + ((7*b*c - 15*a*d)*(b*c + 3*a*d)*(a + b*x)^(1/4)*(c + d*x)^(3/4))/(96*a^2*c^3*x) - ((b*c - a*d)*(7*b^2*c^2 + 10*a*b*c*d + 15*a^2*d^2)*ArcTan[(c^(1/4)*(a + b*x)^(1/4))/(a^(1/4)*(c + d*x)^(1/4))])/(64*a^(11/4)*c^(13/4)) - ((b*c - a*d)*(7*b^2*c^2 + 10*a*b*c*d + 15*a^2*d^2)*ArcTanh[(c^(1/4)*(a + b*x)^(1/4))/(a^(1/4)*(c + d*x)^(1/4))])/(64*a^(11/4)*c^(13/4))}
{(a + b*x)^(1/4)/(c + d*x)^(1/4)/x^5, x, 9, -(((a + b*x)^(1/4)*(c + d*x)^(3/4))/(4*c*x^4)) - ((b*c - 13*a*d)*(a + b*x)^(1/4)*(c + d*x)^(3/4))/(48*a*c^2*x^3) + ((11*b^2*c^2 + 10*a*b*c*d - 117*a^2*d^2)*(a + b*x)^(1/4)*(c + d*x)^(3/4))/(384*a^2*c^3*x^2) - ((77*b^3*c^3 + 61*a*b^2*c^2*d + 63*a^2*b*c*d^2 - 585*a^3*d^3)*(a + b*x)^(1/4)*(c + d*x)^(3/4))/(1536*a^3*c^4*x) + ((b*c - a*d)*(77*b^3*c^3 + 105*a*b^2*c^2*d + 135*a^2*b*c*d^2 + 195*a^3*d^3)*ArcTan[(c^(1/4)*(a + b*x)^(1/4))/(a^(1/4)*(c + d*x)^(1/4))])/(1024*a^(15/4)*c^(17/4)) + ((b*c - a*d)*(77*b^3*c^3 + 105*a*b^2*c^2*d + 135*a^2*b*c*d^2 + 195*a^3*d^3)*ArcTanh[(c^(1/4)*(a + b*x)^(1/4))/(a^(1/4)*(c + d*x)^(1/4))])/(1024*a^(15/4)*c^(17/4))}


{x^4/((a + b*x)^(3/4)*(c + d*x)^(1/4)), x, 8, -(((585*b^3*c^3 + 657*a*b^2*c^2*d + 803*a^2*b*c*d^2 + 1155*a^3*d^3)*(a + b*x)^(1/4)*(c + d*x)^(3/4))/(1536*b^4*d^4)) + ((117*b^2*c^2 + 134*a*b*c*d + 165*a^2*d^2)*x*(a + b*x)^(1/4)*(c + d*x)^(3/4))/(384*b^3*d^3) - ((13*b*c + 15*a*d)*x^2*(a + b*x)^(1/4)*(c + d*x)^(3/4))/(48*b^2*d^2) + (x^3*(a + b*x)^(1/4)*(c + d*x)^(3/4))/(4*b*d) + ((195*b^4*c^4 + 180*a*b^3*c^3*d + 210*a^2*b^2*c^2*d^2 + 308*a^3*b*c*d^3 + 1155*a^4*d^4)*ArcTan[(d^(1/4)*(a + b*x)^(1/4))/(b^(1/4)*(c + d*x)^(1/4))])/(1024*b^(19/4)*d^(17/4)) + ((195*b^4*c^4 + 180*a*b^3*c^3*d + 210*a^2*b^2*c^2*d^2 + 308*a^3*b*c*d^3 + 1155*a^4*d^4)*ArcTanh[(d^(1/4)*(a + b*x)^(1/4))/(b^(1/4)*(c + d*x)^(1/4))])/(1024*b^(19/4)*d^(17/4))}
{x^3/((a + b*x)^(3/4)*(c + d*x)^(1/4)), x, 7, ((45*b^2*c^2 + 54*a*b*c*d + 77*a^2*d^2)*(a + b*x)^(1/4)*(c + d*x)^(3/4))/(96*b^3*d^3) - ((9*b*c + 11*a*d)*x*(a + b*x)^(1/4)*(c + d*x)^(3/4))/(24*b^2*d^2) + (x^2*(a + b*x)^(1/4)*(c + d*x)^(3/4))/(3*b*d) - ((15*b^3*c^3 + 15*a*b^2*c^2*d + 21*a^2*b*c*d^2 + 77*a^3*d^3)*ArcTan[(d^(1/4)*(a + b*x)^(1/4))/(b^(1/4)*(c + d*x)^(1/4))])/(64*b^(15/4)*d^(13/4)) - ((15*b^3*c^3 + 15*a*b^2*c^2*d + 21*a^2*b*c*d^2 + 77*a^3*d^3)*ArcTanh[(d^(1/4)*(a + b*x)^(1/4))/(b^(1/4)*(c + d*x)^(1/4))])/(64*b^(15/4)*d^(13/4))}
{x^2/((a + b*x)^(3/4)*(c + d*x)^(1/4)), x, 6, -(((5*b*c + 7*a*d)*(a + b*x)^(1/4)*(c + d*x)^(3/4))/(8*b^2*d^2)) + (x*(a + b*x)^(1/4)*(c + d*x)^(3/4))/(2*b*d) + ((5*b^2*c^2 + 6*a*b*c*d + 21*a^2*d^2)*ArcTan[(d^(1/4)*(a + b*x)^(1/4))/(b^(1/4)*(c + d*x)^(1/4))])/(16*b^(11/4)*d^(9/4)) + ((5*b^2*c^2 + 6*a*b*c*d + 21*a^2*d^2)*ArcTanh[(d^(1/4)*(a + b*x)^(1/4))/(b^(1/4)*(c + d*x)^(1/4))])/(16*b^(11/4)*d^(9/4))}
{x^1/((a + b*x)^(3/4)*(c + d*x)^(1/4)), x, 5, ((a + b*x)^(1/4)*(c + d*x)^(3/4))/(b*d) - ((b*c + 3*a*d)*ArcTan[(d^(1/4)*(a + b*x)^(1/4))/(b^(1/4)*(c + d*x)^(1/4))])/(2*b^(7/4)*d^(5/4)) - ((b*c + 3*a*d)*ArcTanh[(d^(1/4)*(a + b*x)^(1/4))/(b^(1/4)*(c + d*x)^(1/4))])/(2*b^(7/4)*d^(5/4))}
{x^0/((a + b*x)^(3/4)*(c + d*x)^(1/4)), x, 4, (2*ArcTan[(d^(1/4)*(a + b*x)^(1/4))/(b^(1/4)*(c + d*x)^(1/4))])/(b^(3/4)*d^(1/4)) + (2*ArcTanh[(d^(1/4)*(a + b*x)^(1/4))/(b^(1/4)*(c + d*x)^(1/4))])/(b^(3/4)*d^(1/4))}
{1/(x^1*(a + b*x)^(3/4)*(c + d*x)^(1/4)), x, 4, -((2*ArcTan[(c^(1/4)*(a + b*x)^(1/4))/(a^(1/4)*(c + d*x)^(1/4))])/(a^(3/4)*c^(1/4))) - (2*ArcTanh[(c^(1/4)*(a + b*x)^(1/4))/(a^(1/4)*(c + d*x)^(1/4))])/(a^(3/4)*c^(1/4))}
{1/(x^2*(a + b*x)^(3/4)*(c + d*x)^(1/4)), x, 6, -(((a + b*x)^(1/4)*(c + d*x)^(3/4))/(a*c*x)) + ((3*b*c + a*d)*ArcTan[(c^(1/4)*(a + b*x)^(1/4))/(a^(1/4)*(c + d*x)^(1/4))])/(2*a^(7/4)*c^(5/4)) + ((3*b*c + a*d)*ArcTanh[(c^(1/4)*(a + b*x)^(1/4))/(a^(1/4)*(c + d*x)^(1/4))])/(2*a^(7/4)*c^(5/4))}
{1/(x^3*(a + b*x)^(3/4)*(c + d*x)^(1/4)), x, 7, -(((a + b*x)^(1/4)*(c + d*x)^(3/4))/(2*a*c*x^2)) + ((7*b*c + 5*a*d)*(a + b*x)^(1/4)*(c + d*x)^(3/4))/(8*a^2*c^2*x) - ((21*b^2*c^2 + 6*a*b*c*d + 5*a^2*d^2)*ArcTan[(c^(1/4)*(a + b*x)^(1/4))/(a^(1/4)*(c + d*x)^(1/4))])/(16*a^(11/4)*c^(9/4)) - ((21*b^2*c^2 + 6*a*b*c*d + 5*a^2*d^2)*ArcTanh[(c^(1/4)*(a + b*x)^(1/4))/(a^(1/4)*(c + d*x)^(1/4))])/(16*a^(11/4)*c^(9/4))}
{1/(x^4*(a + b*x)^(3/4)*(c + d*x)^(1/4)), x, 8, -(((a + b*x)^(1/4)*(c + d*x)^(3/4))/(3*a*c*x^3)) + ((11*b*c + 9*a*d)*(a + b*x)^(1/4)*(c + d*x)^(3/4))/(24*a^2*c^2*x^2) - ((77*b^2*c^2 + 54*a*b*c*d + 45*a^2*d^2)*(a + b*x)^(1/4)*(c + d*x)^(3/4))/(96*a^3*c^3*x) + ((77*b^3*c^3 + 21*a*b^2*c^2*d + 15*a^2*b*c*d^2 + 15*a^3*d^3)*ArcTan[(c^(1/4)*(a + b*x)^(1/4))/(a^(1/4)*(c + d*x)^(1/4))])/(64*a^(15/4)*c^(13/4)) + ((77*b^3*c^3 + 21*a*b^2*c^2*d + 15*a^2*b*c*d^2 + 15*a^3*d^3)*ArcTanh[(c^(1/4)*(a + b*x)^(1/4))/(a^(1/4)*(c + d*x)^(1/4))])/(64*a^(15/4)*c^(13/4))}


{1/((1 - a*x)^(1/4)*(1 + b*x)^(3/4)), x, 4, -((2*ArcTan[(b^(1/4)*(1 - a*x)^(1/4))/((-a)^(1/4)*(1 + b*x)^(1/4))])/((-a)^(1/4)*b^(3/4))) + (2*ArcTanh[(b^(1/4)*(1 - a*x)^(1/4))/((-a)^(1/4)*(1 + b*x)^(1/4))])/((-a)^(1/4)*b^(3/4))}
{1/((1 - a*x)^(1/4)*(1 + a*x)^(3/4)), x, 8, (Sqrt[2]*ArcTan[1 - (Sqrt[2]*(1 - a*x)^(1/4))/(1 + a*x)^(1/4)])/a - (Sqrt[2]*ArcTan[1 + (Sqrt[2]*(1 - a*x)^(1/4))/(1 + a*x)^(1/4)])/a - Log[1 + Sqrt[1 - a*x]/Sqrt[1 + a*x] - (Sqrt[2]*(1 - a*x)^(1/4))/(1 + a*x)^(1/4)]/(Sqrt[2]*a) + Log[1 + Sqrt[1 - a*x]/Sqrt[1 + a*x] + (Sqrt[2]*(1 - a*x)^(1/4))/(1 + a*x)^(1/4)]/(Sqrt[2]*a)}


(* ::Title:: *)
(*Integrands of the form (a+b x)^m (c+d x)^n (e+f x)^p*)


(* ::Section::Closed:: *)
(*Integrands of the form (a+b x)^m (c+d x)^n (e+f x)^p*)


(* ::Subsection::Closed:: *)
(*Integrands of the form (a+b x)^m (c+d x)^n (e+f x)^1*)


(* ::Subsubsection::Closed:: *)
(*n>0*)


{(1 - 2*x)*(2 + 3*x)^m*(3 + 5*x), x, 2, -((7*(2 + 3*x)^(1 + m))/(27*(1 + m))) + (37*(2 + 3*x)^(2 + m))/(27*(2 + m)) - (10*(2 + 3*x)^(3 + m))/(27*(3 + m))}

{(1 - 2*x)*(2 + 3*x)^8*(3 + 5*x), x, 2, (-7*(2 + 3*x)^9)/243 + (37*(2 + 3*x)^10)/270 - (10*(2 + 3*x)^11)/297}
{(1 - 2*x)*(2 + 3*x)^7*(3 + 5*x), x, 2, (-7*(2 + 3*x)^8)/216 + (37*(2 + 3*x)^9)/243 - (2 + 3*x)^10/27}
{(1 - 2*x)*(2 + 3*x)^6*(3 + 5*x), x, 2, -(2 + 3*x)^7/27 + (37*(2 + 3*x)^8)/216 - (10*(2 + 3*x)^9)/243}
{(1 - 2*x)*(2 + 3*x)^5*(3 + 5*x), x, 2, 96*x + 344*x^2 + (1600*x^3)/3 + 30*x^4 - 1170*x^5 - (3627*x^6)/2 - (8343*x^7)/7 - (1215*x^8)/4}
{(1 - 2*x)*(2 + 3*x)^4*(3 + 5*x), x, 2, 48*x + 136*x^2 + (392*x^3)/3 - 132*x^4 - (2133*x^5)/5 - (747*x^6)/2 - (810*x^7)/7}
{(1 - 2*x)*(2 + 3*x)^3*(3 + 5*x), x, 2, 24*x + 50*x^2 + (46*x^3)/3 - (333*x^4)/4 - (567*x^5)/5 - 45*x^6}
{(1 - 2*x)*(2 + 3*x)^2*(3 + 5*x), x, 2, 12*x + 16*x^2 - (25*x^3)/3 - (129*x^4)/4 - 18*x^5}
{(1 - 2*x)*(2 + 3*x)*(3 + 5*x), x, 2, 6*x + (7*x^2)/2 - (23*x^3)/3 - (15*x^4)/2}
{(1 - 2*x)*(3 + 5*x), x, 2, 3*x - x^2/2 - (10*x^3)/3}
{((1 - 2*x)*(3 + 5*x))/(2 + 3*x), x, 2, (17*x)/9 - (5*x^2)/3 - (7/27)*Log[2 + 3*x]}
{((1 - 2*x)*(3 + 5*x))/(2 + 3*x)^2, x, 2, (-10*x)/9 + 7/(27*(2 + 3*x)) + (37*Log[2 + 3*x])/27}
{((1 - 2*x)*(3 + 5*x))/(2 + 3*x)^3, x, 2, 7/(54*(2 + 3*x)^2) - 37/(27*(2 + 3*x)) - (10*Log[2 + 3*x])/27}
{((1 - 2*x)*(3 + 5*x))/(2 + 3*x)^4, x, 2, 7/(81*(2 + 3*x)^3) - 37/(54*(2 + 3*x)^2) + 10/(27*(2 + 3*x))}
{((1 - 2*x)*(3 + 5*x))/(2 + 3*x)^5, x, 2, 7/(108*(2 + 3*x)^4) - 37/(81*(2 + 3*x)^3) + 5/(27*(2 + 3*x)^2)}
{((1 - 2*x)*(3 + 5*x))/(2 + 3*x)^6, x, 2, 7/(135*(2 + 3*x)^5) - 37/(108*(2 + 3*x)^4) + 10/(81*(2 + 3*x)^3)}


{(1 - 2*x)*(2 + 3*x)^m*(3 + 5*x)^2, x, 2, (7*(2 + 3*x)^(1 + m))/(81*(1 + m)) - (8*(2 + 3*x)^(2 + m))/(9*(2 + m)) + (65*(2 + 3*x)^(3 + m))/(27*(3 + m)) - (50*(2 + 3*x)^(4 + m))/(81*(4 + m))}

{(1 - 2*x)*(2 + 3*x)^8*(3 + 5*x)^2, x, 2, (7*(2 + 3*x)^9)/729 - (4*(2 + 3*x)^10)/45 + (65*(2 + 3*x)^11)/297 - (25*(2 + 3*x)^12)/486}
{(1 - 2*x)*(2 + 3*x)^7*(3 + 5*x)^2, x, 2, (7*(2 + 3*x)^8)/648 - (8*(2 + 3*x)^9)/81 + (13*(2 + 3*x)^10)/54 - (50*(2 + 3*x)^11)/891}
{(1 - 2*x)*(2 + 3*x)^6*(3 + 5*x)^2, x, 2, 576*x + 2976*x^2 + (24112*x^3)/3 + 10360*x^4 - 1764*x^5 - 29106*x^6 - 49221*x^7 - 42039*x^8 - 19035*x^9 - 3645*x^10}
{(1 - 2*x)*(2 + 3*x)^5*(3 + 5*x)^2, x, 2, 288*x + 1272*x^2 + (8240*x^3)/3 + 2090*x^4 - 3390*x^5 - (20631*x^6)/2 - (79434*x^7)/7 - (49005*x^8)/8 - 1350*x^9}
{(1 - 2*x)*(2 + 3*x)^4*(3 + 5*x)^2, x, 2, 144*x + 528*x^2 + (2536*x^3)/3 + 94*x^4 - (9039*x^5)/5 - 2898*x^6 - (13635*x^7)/7 - (2025*x^8)/4}
{(1 - 2*x)*(2 + 3*x)^3*(3 + 5*x)^2, x, 2, 72*x + 210*x^2 + (638*x^3)/3 - (769*x^4)/4 - (3366*x^5)/5 - (1215*x^6)/2 - (1350*x^7)/7}
{(1 - 2*x)*(2 + 3*x)^2*(3 + 5*x)^2, x, 2, 36*x + 78*x^2 + (85*x^3)/3 - 128*x^4 - 183*x^5 - 75*x^6}
{(1 - 2*x)*(2 + 3*x)*(3 + 5*x)^2, x, 2, 18*x + (51*x^2)/2 - (34*x^3)/3 - (205*x^4)/4 - 30*x^5}
{(1 - 2*x)*(3 + 5*x)^2, x, 2, 9*x + 6*x^2 - (35*x^3)/3 - (25*x^4)/2}
{((1 - 2*x)*(3 + 5*x)^2)/(2 + 3*x), x, 2, (118*x)/27 - (5*x^2)/18 - (50*x^3)/9 + (7/81)*Log[2 + 3*x]}
{((1 - 2*x)*(3 + 5*x)^2)/(2 + 3*x)^2, x, 2, (95*x)/27 - (25*x^2)/9 - 7/(81*(2 + 3*x)) - (8*Log[2 + 3*x])/9}
{((1 - 2*x)*(3 + 5*x)^2)/(2 + 3*x)^3, x, 2, (-50*x)/27 - 7/(162*(2 + 3*x)^2) + 8/(9*(2 + 3*x)) + (65*Log[2 + 3*x])/27}
{((1 - 2*x)*(3 + 5*x)^2)/(2 + 3*x)^4, x, 2, -(7/(243*(2 + 3*x)^3)) + 4/(9*(2 + 3*x)^2) - 65/(27*(2 + 3*x)) - (50/81)*Log[2 + 3*x]}
{((1 - 2*x)*(3 + 5*x)^2)/(2 + 3*x)^5, x, 2, (7*(3 + 5*x)^3)/(12*(2 + 3*x)^4) + (3*(3 + 5*x)^3)/(4*(2 + 3*x)^3)}
{((1 - 2*x)*(3 + 5*x)^2)/(2 + 3*x)^6, x, 2, -7/(405*(2 + 3*x)^5) + 2/(9*(2 + 3*x)^4) - 65/(81*(2 + 3*x)^3) + 25/(81*(2 + 3*x)^2)}
{((1 - 2*x)*(3 + 5*x)^2)/(2 + 3*x)^7, x, 2, -7/(486*(2 + 3*x)^6) + 8/(45*(2 + 3*x)^5) - 65/(108*(2 + 3*x)^4) + 50/(243*(2 + 3*x)^3)}
{((1 - 2*x)*(3 + 5*x)^2)/(2 + 3*x)^8, x, 2, -1/(81*(2 + 3*x)^7) + 4/(27*(2 + 3*x)^6) - 13/(27*(2 + 3*x)^5) + 25/(162*(2 + 3*x)^4)}


{(1 - 2*x)*(2 + 3*x)^m*(3 + 5*x)^3, x, 2, -((7*(2 + 3*x)^(1 + m))/(243*(1 + m))) + (107*(2 + 3*x)^(2 + m))/(243*(2 + m)) - (185*(2 + 3*x)^(3 + m))/(81*(3 + m)) + (1025*(2 + 3*x)^(4 + m))/(243*(4 + m)) - (250*(2 + 3*x)^(5 + m))/(243*(5 + m))}

{(1 - 2*x)*(2 + 3*x)^8*(3 + 5*x)^3, x, 2, (-7*(2 + 3*x)^9)/2187 + (107*(2 + 3*x)^10)/2430 - (185*(2 + 3*x)^11)/891 + (1025*(2 + 3*x)^12)/2916 - (250*(2 + 3*x)^13)/3159}
{(1 - 2*x)*(2 + 3*x)^7*(3 + 5*x)^3, x, 2, 3456*x + 23328*x^2 + 88800*x^3 + 199012*x^4 + 219224*x^5 - 98966*x^6 - 788238*x^7 - (11183805*x^8)/8 - 1398447*x^9 - (1703673*x^10)/2 - (3262275*x^11)/11 - (91125*x^12)/2}
{(1 - 2*x)*(2 + 3*x)^6*(3 + 5*x)^3, x, 2, 1728*x + 10368*x^2 + 34032*x^3 + 61220*x^4 + 36148*x^5 - 94668*x^6 - 272403*x^7 - (2731671*x^8)/8 - 243945*x^9 - (193185*x^10)/2 - (182250*x^11)/11}
{(1 - 2*x)*(2 + 3*x)^5*(3 + 5*x)^3, x, 2, 864*x + 4536*x^2 + 12480*x^3 + 16570*x^4 - 1810*x^5 - (90143*x^6)/2 - (547767*x^7)/7 - (544185*x^8)/8 - 31275*x^9 - 6075*x^10}
{(1 - 2*x)*(2 + 3*x)^4*(3 + 5*x)^3, x, 2, 432*x + 1944*x^2 + 4296*x^3 + 3452*x^4 - (25237*x^5)/5 - (32453*x^6)/2 - (127845*x^7)/7 - (80325*x^8)/8 - 2250*x^9}
{(1 - 2*x)*(2 + 3*x)^3*(3 + 5*x)^3, x, 2, 216*x + 810*x^2 + 1338*x^3 + (883*x^4)/4 - (13943*x^5)/5 - (9255*x^6)/2 - (22275*x^7)/7 - (3375*x^8)/4}
{(1 - 2*x)*(2 + 3*x)^2*(3 + 5*x)^3, x, 2, 108*x + 324*x^2 + 345*x^3 - (1111*x^4)/4 - 1061*x^5 - (1975*x^6)/2 - (2250*x^7)/7}
{(1 - 2*x)*(2 + 3*x)*(3 + 5*x)^3, x, 2, 54*x + (243*x^2)/2 + 51*x^3 - (785*x^4)/4 - 295*x^5 - 125*x^6}
{(1 - 2*x)*(3 + 5*x)^3, x, 2, 27*x + (81*x^2)/2 - 15*x^3 - (325*x^4)/4 - 50*x^5}
{((1 - 2*x)*(3 + 5*x)^3)/(2 + 3*x), x, 2, (1097*x)/81 + (545*x^2)/54 - (475*x^3)/27 - (125*x^4)/6 - (7/243)*Log[2 + 3*x]}
{((1 - 2*x)*(3 + 5*x)^3)/(2 + 3*x)^2, x, 2, (55*x)/9 + (25*x^2)/54 - (250*x^3)/27 + 7/(243*(2 + 3*x)) + (107*Log[2 + 3*x])/243}
{((1 - 2*x)*(3 + 5*x)^3)/(2 + 3*x)^3, x, 2, (175*x)/27 - (125*x^2)/27 + 7/(486*(2 + 3*x)^2) - 107/(243*(2 + 3*x)) - (185*Log[2 + 3*x])/81}
{((1 - 2*x)*(3 + 5*x)^3)/(2 + 3*x)^4, x, 2, (-250*x)/81 + 7/(729*(2 + 3*x)^3) - 107/(486*(2 + 3*x)^2) + 185/(81*(2 + 3*x)) + (1025*Log[2 + 3*x])/243}
{((1 - 2*x)*(3 + 5*x)^3)/(2 + 3*x)^5, x, 2, 7/(972*(2 + 3*x)^4) - 107/(729*(2 + 3*x)^3) + 185/(162*(2 + 3*x)^2) - 1025/(243*(2 + 3*x)) - (250/243)*Log[2 + 3*x]}
{((1 - 2*x)*(3 + 5*x)^3)/(2 + 3*x)^6, x, 2, (7*(3 + 5*x)^4)/(15*(2 + 3*x)^5) + (5*(3 + 5*x)^4)/(12*(2 + 3*x)^4)}
{((1 - 2*x)*(3 + 5*x)^3)/(2 + 3*x)^7, x, 3, (7*(3 + 5*x)^4)/(18*(2 + 3*x)^6) + (29*(3 + 5*x)^4)/(45*(2 + 3*x)^5) + (29*(3 + 5*x)^4)/(36*(2 + 3*x)^4)}
{((1 - 2*x)*(3 + 5*x)^3)/(2 + 3*x)^8, x, 2, 1/(243*(2 + 3*x)^7) - 107/(1458*(2 + 3*x)^6) + 37/(81*(2 + 3*x)^5) - 1025/(972*(2 + 3*x)^4) + 250/(729*(2 + 3*x)^3)}


{(5 - 2*x)^6*(2 + 3*x)^3*(-16 + 33*x), x, 1, (-(1/2))*(5 - 2*x)^7*(2 + 3*x)^4}


(* ::Subsubsection::Closed:: *)
(*n<0*)


{((1 - 2*x)*(2 + 3*x)^m)/(3 + 5*x), x, 2, -((2*(2 + 3*x)^(1 + m))/(15*(1 + m))) - (11*(2 + 3*x)^(1 + m)*Hypergeometric2F1[1, 1 + m, 2 + m, 5*(2 + 3*x)])/(5*(1 + m))}

{((1 - 2*x)*(2 + 3*x)^6)/(3 + 5*x), x, 2, (1666663*x)/78125 + (1777779*x^2)/31250 + (152469*x^3)/3125 - (152469*x^4)/2500 - (106677*x^5)/625 - (7047*x^6)/50 - (1458*x^7)/35 + (11*Log[3 + 5*x])/390625}
{((1 - 2*x)*(2 + 3*x)^5)/(3 + 5*x), x, 2, (166663*x)/15625 + (127779*x^2)/6250 + (2469*x^3)/625 - (17469*x^4)/500 - (5427*x^5)/125 - (81*x^6)/5 + (11*Log[3 + 5*x])/78125}
{((1 - 2*x)*(2 + 3*x)^4)/(3 + 5*x), x, 2, (16663*x)/3125 + (7779*x^2)/1250 - (531*x^3)/125 - (1269*x^4)/100 - (162*x^5)/25 + (11*Log[3 + 5*x])/15625}
{((1 - 2*x)*(2 + 3*x)^3)/(3 + 5*x), x, 2, (1663*x)/625 + (279*x^2)/250 - (81*x^3)/25 - (27*x^4)/10 + (11*Log[3 + 5*x])/3125}
{((1 - 2*x)*(2 + 3*x)^2)/(3 + 5*x), x, 2, (163*x)/125 - (21*x^2)/50 - (6*x^3)/5 + (11/625)*Log[3 + 5*x]}
{((1 - 2*x)*(2 + 3*x)^1)/(3 + 5*x), x, 2, (13*x)/25 - (3*x^2)/5 + (11/125)*Log[3 + 5*x]}
{(1 - 2*x)/(3 + 5*x), x, 2, (-2*x)/5 + (11*Log[3 + 5*x])/25}
{(1 - 2*x)/((2 + 3*x)*(3 + 5*x)), x, 2, (-7*Log[2 + 3*x])/3 + (11*Log[3 + 5*x])/5}
{(1 - 2*x)/((2 + 3*x)^2*(3 + 5*x)), x, 2, 7/(3*(2 + 3*x)) - 11*Log[2 + 3*x] + 11*Log[3 + 5*x]}
{(1 - 2*x)/((2 + 3*x)^3*(3 + 5*x)), x, 2, 7/(6*(2 + 3*x)^2) + 11/(2 + 3*x) - 55*Log[2 + 3*x] + 55*Log[3 + 5*x]}
{(1 - 2*x)/((2 + 3*x)^4*(3 + 5*x)), x, 2, 7/(9*(2 + 3*x)^3) + 11/(2*(2 + 3*x)^2) + 55/(2 + 3*x) - 275*Log[2 + 3*x] + 275*Log[3 + 5*x]}
{(1 - 2*x)/((2 + 3*x)^5*(3 + 5*x)), x, 2, 7/(12*(2 + 3*x)^4) + 11/(3*(2 + 3*x)^3) + 55/(2*(2 + 3*x)^2) + 275/(2 + 3*x) - 1375*Log[2 + 3*x] + 1375*Log[3 + 5*x]}
{(1 - 2*x)/((2 + 3*x)^6*(3 + 5*x)), x, 2, 7/(15*(2 + 3*x)^5) + 11/(4*(2 + 3*x)^4) + 55/(3*(2 + 3*x)^3) + 275/(2*(2 + 3*x)^2) + 1375/(2 + 3*x) - 6875*Log[2 + 3*x] + 6875*Log[3 + 5*x]}
{(1 - 2*x)/((2 + 3*x)^7*(3 + 5*x)), x, 2, 7/(18*(2 + 3*x)^6) + 11/(5*(2 + 3*x)^5) + 55/(4*(2 + 3*x)^4) + 275/(3*(2 + 3*x)^3) + 1375/(2*(2 + 3*x)^2) + 6875/(2 + 3*x) - 34375*Log[2 + 3*x] + 34375*Log[3 + 5*x]}


{((1 - 2*x)*(2 + 3*x)^m)/(3 + 5*x)^2, x, 2, -((11*(2 + 3*x)^(1 + m))/(5*(3 + 5*x))) + ((2 - 33*m)*(2 + 3*x)^(1 + m)*Hypergeometric2F1[1, 1 + m, 2 + m, 5*(2 + 3*x)])/(5*(1 + m))}

{((1 - 2*x)*(2 + 3*x)^7)/(3 + 5*x)^2, x, 2, (5555478*x)/390625 + (5740767*x^2)/156250 + (92592*x^3)/3125 - (513783*x^4)/12500 - (336798*x^5)/3125 - (21627*x^6)/250 - (4374*x^7)/175 - 11/(1953125*(3 + 5*x)) + (229*Log[3 + 5*x])/1953125}
{((1 - 2*x)*(2 + 3*x)^6)/(3 + 5*x)^2, x, 2, (555489*x)/78125 + (40743*x^2)/3125 + (5553*x^3)/3125 - (14094*x^4)/625 - (16767*x^5)/625 - (243*x^6)/25 - 11/(390625*(3 + 5*x)) + (196*Log[3 + 5*x])/390625}
{((1 - 2*x)*(2 + 3*x)^5)/(3 + 5*x)^2, x, 2, (444*x)/125 + (24093*x^2)/6250 - (1854*x^3)/625 - (3969*x^4)/500 - (486*x^5)/125 - 11/(78125*(3 + 5*x)) + (163*Log[3 + 5*x])/78125}
{((1 - 2*x)*(2 + 3*x)^4)/(3 + 5*x)^2, x, 2, (5511*x)/3125 + (378*x^2)/625 - (261*x^3)/125 - (81*x^4)/50 - 11/(15625*(3 + 5*x)) + (26*Log[3 + 5*x])/3125}
{((1 - 2*x)*(2 + 3*x)^3)/(3 + 5*x)^2, x, 2, (522*x)/625 - (81*x^2)/250 - (18*x^3)/25 - 11/(3125*(3 + 5*x)) + (97*Log[3 + 5*x])/3125}
{((1 - 2*x)*(2 + 3*x)^2)/(3 + 5*x)^2, x, 2, (33*x)/125 - (9*x^2)/25 - 11/(625*(3 + 5*x)) + (64*Log[3 + 5*x])/625}
{((1 - 2*x)*(2 + 3*x))/(3 + 5*x)^2, x, 2, (-6*x)/25 - 11/(125*(3 + 5*x)) + (31*Log[3 + 5*x])/125}
{(1 - 2*x)/(3 + 5*x)^2, x, 2, -11/(25*(3 + 5*x)) - (2*Log[3 + 5*x])/25}
{(1 - 2*x)/((2 + 3*x)*(3 + 5*x)^2), x, 2, -11/(5*(3 + 5*x)) + 7*Log[2 + 3*x] - 7*Log[3 + 5*x]}
{(1 - 2*x)/((2 + 3*x)^2*(3 + 5*x)^2), x, 2, -7/(2 + 3*x) - 11/(3 + 5*x) + 68*Log[2 + 3*x] - 68*Log[3 + 5*x]}
{(1 - 2*x)/((2 + 3*x)^3*(3 + 5*x)^2), x, 2, -7/(2*(2 + 3*x)^2) - 68/(2 + 3*x) - 55/(3 + 5*x) + 505*Log[2 + 3*x] - 505*Log[3 + 5*x]}
{(1 - 2*x)/((2 + 3*x)^4*(3 + 5*x)^2), x, 2, -7/(3*(2 + 3*x)^3) - 34/(2 + 3*x)^2 - 505/(2 + 3*x) - 275/(3 + 5*x) + 3350*Log[2 + 3*x] - 3350*Log[3 + 5*x]}
{(1 - 2*x)/((2 + 3*x)^5*(3 + 5*x)^2), x, 2, -7/(4*(2 + 3*x)^4) - 68/(3*(2 + 3*x)^3) - 505/(2*(2 + 3*x)^2) - 3350/(2 + 3*x) - 1375/(3 + 5*x) + 20875*Log[2 + 3*x] - 20875*Log[3 + 5*x]}
{(1 - 2*x)/((2 + 3*x)^6*(3 + 5*x)^2), x, 2, -7/(5*(2 + 3*x)^5) - 17/(2 + 3*x)^4 - 505/(3*(2 + 3*x)^3) - 1675/(2 + 3*x)^2 - 20875/(2 + 3*x) - 6875/(3 + 5*x) + 125000*Log[2 + 3*x] - 125000*Log[3 + 5*x]}
{(1 - 2*x)/((2 + 3*x)^7*(3 + 5*x)^2), x, 2, -7/(6*(2 + 3*x)^6) - 68/(5*(2 + 3*x)^5) - 505/(4*(2 + 3*x)^4) - 3350/(3*(2 + 3*x)^3) - 20875/(2*(2 + 3*x)^2) - 125000/(2 + 3*x) - 34375/(3 + 5*x) + 728125*Log[2 + 3*x] - 728125*Log[3 + 5*x]}


{((1 - 2*x)*(2 + 3*x)^m)/(3 + 5*x)^3, x, 3, -((11*(2 + 3*x)^(1 + m))/(10*(3 + 5*x)^2)) + ((37 - 33*m)*(2 + 3*x)^(1 + m))/(10*(3 + 5*x)) + (3*(37 - 33*m)*m*(2 + 3*x)^(1 + m)*Hypergeometric2F1[1, 1 + m, 2 + m, 5*(2 + 3*x)])/(10*(1 + m))}

{((1 - 2*x)*(2 + 3*x)^7)/(3 + 5*x)^3, x, 2, (1851147*x)/390625 + (129654*x^2)/15625 + (2052*x^3)/3125 - (181521*x^4)/12500 - (51759*x^5)/3125 - (729*x^6)/125 - 11/(3906250*(3 + 5*x)^2) - 229/(1953125*(3 + 5*x)) + (2037*Log[3 + 5*x])/1953125}
{((1 - 2*x)*(2 + 3*x)^6)/(3 + 5*x)^3, x, 2, (36936*x)/15625 + (297*x^2)/125 - (6399*x^3)/3125 - (12393*x^4)/2500 - (1458*x^5)/625 - 11/(781250*(3 + 5*x)^2) - 196/(390625*(3 + 5*x)) + (1449*Log[3 + 5*x])/390625}
{((1 - 2*x)*(2 + 3*x)^5)/(3 + 5*x)^3, x, 2, (3636*x)/3125 + (1971*x^2)/6250 - (837*x^3)/625 - (243*x^4)/250 - 11/(156250*(3 + 5*x)^2) - 163/(78125*(3 + 5*x)) + (192*Log[3 + 5*x])/15625}
{((1 - 2*x)*(2 + 3*x)^4)/(3 + 5*x)^3, x, 2, (1647*x)/3125 - (297*x^2)/1250 - (54*x^3)/125 - 11/(31250*(3 + 5*x)^2) - 26/(3125*(3 + 5*x)) + (114*Log[3 + 5*x])/3125}
{((1 - 2*x)*(2 + 3*x)^3)/(3 + 5*x)^3, x, 2, (81*x)/625 - (27*x^2)/125 - 11/(6250*(3 + 5*x)^2) - 97/(3125*(3 + 5*x)) + (279*Log[3 + 5*x])/3125}
{((1 - 2*x)*(2 + 3*x)^2)/(3 + 5*x)^3, x, 2, (-18*x)/125 - 11/(1250*(3 + 5*x)^2) - 64/(625*(3 + 5*x)) + (87*Log[3 + 5*x])/625}
{((1 - 2*x)*(2 + 3*x))/(3 + 5*x)^3, x, 2, -11/(250*(3 + 5*x)^2) - 31/(125*(3 + 5*x)) - (6*Log[3 + 5*x])/125}
{(1 - 2*x)/(3 + 5*x)^3, x, 1, -(1 - 2*x)^2/(22*(3 + 5*x)^2)}
{(1 - 2*x)/((2 + 3*x)*(3 + 5*x)^3), x, 2, -11/(10*(3 + 5*x)^2) + 7/(3 + 5*x) - 21*Log[2 + 3*x] + 21*Log[3 + 5*x]}
{(1 - 2*x)/((2 + 3*x)^2*(3 + 5*x)^3), x, 2, 21/(2 + 3*x) - 11/(2*(3 + 5*x)^2) + 68/(3 + 5*x) - 309*Log[2 + 3*x] + 309*Log[3 + 5*x]}
{(1 - 2*x)/((2 + 3*x)^3*(3 + 5*x)^3), x, 2, 21/(2*(2 + 3*x)^2) + 309/(2 + 3*x) - 55/(2*(3 + 5*x)^2) + 505/(3 + 5*x) - 3060*Log[2 + 3*x] + 3060*Log[3 + 5*x]}
{(1 - 2*x)/((2 + 3*x)^4*(3 + 5*x)^3), x, 2, 7/(2 + 3*x)^3 + 309/(2*(2 + 3*x)^2) + 3060/(2 + 3*x) - 275/(2*(3 + 5*x)^2) + 3350/(3 + 5*x) - 25350*Log[2 + 3*x] + 25350*Log[3 + 5*x]}
{(1 - 2*x)/((2 + 3*x)^5*(3 + 5*x)^3), x, 2, 21/(4*(2 + 3*x)^4) + 103/(2 + 3*x)^3 + 1530/(2 + 3*x)^2 + 25350/(2 + 3*x) - 1375/(2*(3 + 5*x)^2) + 20875/(3 + 5*x) - 189375*Log[2 + 3*x] + 189375*Log[3 + 5*x]}
{(1 - 2*x)/((2 + 3*x)^6*(3 + 5*x)^3), x, 2, 21/(5*(2 + 3*x)^5) + 309/(4*(2 + 3*x)^4) + 1020/(2 + 3*x)^3 + 12675/(2 + 3*x)^2 + 189375/(2 + 3*x) - 6875/(2*(3 + 5*x)^2) + 125000/(3 + 5*x) - 1321875*Log[2 + 3*x] + 1321875*Log[3 + 5*x]}


(* ::Subsection::Closed:: *)
(*Integrands of the form (a+b x)^m (c+d x)^n (e+f x)^2*)


(* ::Subsubsection::Closed:: *)
(*n>0*)


{(1 - 2*x)^2*(2 + 3*x)^8*(3 + 5*x), x, 2, (-49*(2 + 3*x)^9)/729 + (91*(2 + 3*x)^10)/270 - (16*(2 + 3*x)^11)/99 + (5*(2 + 3*x)^12)/243}
{(1 - 2*x)^2*(2 + 3*x)^7*(3 + 5*x), x, 2, (-49*(2 + 3*x)^8)/648 + (91*(2 + 3*x)^9)/243 - (8*(2 + 3*x)^10)/45 + (20*(2 + 3*x)^11)/891}
{(1 - 2*x)^2*(2 + 3*x)^6*(3 + 5*x), x, 2, 192*x + 640*x^2 + (1936*x^3)/3 - 1372*x^4 - 4284*x^5 - 2772*x^6 + 4185*x^7 + (68769*x^8)/8 + 5832*x^9 + 1458*x^10}
{(1 - 2*x)^2*(2 + 3*x)^5*(3 + 5*x), x, 2, 96*x + 248*x^2 + (224*x^3)/3 - 770*x^4 - 1218*x^5 + (273*x^6)/2 + 1917*x^7 + 1782*x^8 + 540*x^9}
{(1 - 2*x)^2*(2 + 3*x)^4*(3 + 5*x), x, 2, 48*x + 88*x^2 - (152*x^3)/3 - 328*x^4 - (1077*x^5)/5 + (675*x^6)/2 + (3672*x^7)/7 + (405*x^8)/2}
{(1 - 2*x)^2*(2 + 3*x)^3*(3 + 5*x), x, 2, 24*x + 26*x^2 - (154*x^3)/3 - (425*x^4)/4 + (99*x^5)/5 + 144*x^6 + (540*x^7)/7}
{(1 - 2*x)^2*(2 + 3*x)^2*(3 + 5*x), x, 2, 12*x + 4*x^2 - (89*x^3)/3 - (79*x^4)/4 + (168*x^5)/5 + 30*x^6}
{(1 - 2*x)^2*(2 + 3*x)*(3 + 5*x), x, 2, 6*x - (5*x^2)/2 - (37*x^3)/3 + 4*x^4 + 12*x^5}
{(1 - 2*x)^2*(3 + 5*x), x, 2, 3*x - (7*x^2)/2 - (8*x^3)/3 + 5*x^4}
{((1 - 2*x)^2*(3 + 5*x))/(2 + 3*x), x, 2, (65*x)/27 - (32*x^2)/9 + (20*x^3)/9 - (49/81)*Log[2 + 3*x]}
{((1 - 2*x)^2*(3 + 5*x))/(2 + 3*x)^2, x, 2, (-104*x)/27 + (10*x^2)/9 + 49/(81*(2 + 3*x)) + (91*Log[2 + 3*x])/27}
{((1 - 2*x)^2*(3 + 5*x))/(2 + 3*x)^3, x, 2, (20*x)/27 + 49/(162*(2 + 3*x)^2) - 91/(27*(2 + 3*x)) - (16*Log[2 + 3*x])/9}
{((1 - 2*x)^2*(3 + 5*x))/(2 + 3*x)^4, x, 2, 49/(243*(2 + 3*x)^3) - 91/(54*(2 + 3*x)^2) + 16/(9*(2 + 3*x)) + (20/81)*Log[2 + 3*x]}
{((1 - 2*x)^2*(3 + 5*x))/(2 + 3*x)^5, x, 2, (1 - 2*x)^3/(84*(2 + 3*x)^4) - (23*(1 - 2*x)^3)/(294*(2 + 3*x)^3)}
{((1 - 2*x)^2*(3 + 5*x))/(2 + 3*x)^6, x, 2, 49/(405*(2 + 3*x)^5) - 91/(108*(2 + 3*x)^4) + 16/(27*(2 + 3*x)^3) - 10/(81*(2 + 3*x)^2)}
{((1 - 2*x)^2*(3 + 5*x))/(2 + 3*x)^7, x, 2, 49/(486*(2 + 3*x)^6) - 91/(135*(2 + 3*x)^5) + 4/(9*(2 + 3*x)^4) - 20/(243*(2 + 3*x)^3)}
{((1 - 2*x)^2*(3 + 5*x))/(2 + 3*x)^8, x, 2, 7/(81*(2 + 3*x)^7) - 91/(162*(2 + 3*x)^6) + 16/(45*(2 + 3*x)^5) - 5/(81*(2 + 3*x)^4)}


{(1 - 2*x)^2*(2 + 3*x)^8*(3 + 5*x)^2, x, 2, (49*(2 + 3*x)^9)/2187 - (259*(2 + 3*x)^10)/1215 + (503*(2 + 3*x)^11)/891 - (185*(2 + 3*x)^12)/729 + (100*(2 + 3*x)^13)/3159}
{(1 - 2*x)^2*(2 + 3*x)^7*(3 + 5*x)^2, x, 2, 1152*x + 5664*x^2 + (38816*x^3)/3 + 5764*x^4 - (203752*x^5)/5 - 98182*x^6 - 65934*x^7 + (719739*x^8)/8 + 228996*x^9 + (2116287*x^10)/10 + (1064340*x^11)/11 + 18225*x^12}
{(1 - 2*x)^2*(2 + 3*x)^6*(3 + 5*x)^2, x, 2, 576*x + 2400*x^2 + (12208*x^3)/3 - 1696*x^4 - 18340*x^5 - 26166*x^6 + 675*x^7 + (176391*x^8)/4 + 55701*x^9 + 30618*x^10 + (72900*x^11)/11}
{(1 - 2*x)^2*(2 + 3*x)^5*(3 + 5*x)^2, x, 2, 288*x + 984*x^2 + (3152*x^3)/3 - 2030*x^4 - 6734*x^5 - (9331*x^6)/2 + 6336*x^7 + (109863*x^8)/8 + 9540*x^9 + 2430*x^10}
{(1 - 2*x)^2*(2 + 3*x)^4*(3 + 5*x)^2, x, 2, 144*x + 384*x^2 + (424*x^3)/3 - 1174*x^4 - (9791*x^5)/5 + 115*x^6 + (21141*x^7)/7 + (5805*x^8)/2 + 900*x^9}
{(1 - 2*x)^2*(2 + 3*x)^3*(3 + 5*x)^2, x, 2, 72*x + 138*x^2 - (202*x^3)/3 - (2045*x^4)/4 - (1828*x^5)/5 + (1029*x^6)/2 + (5940*x^7)/7 + (675*x^8)/2}
{(1 - 2*x)^2*(2 + 3*x)^2*(3 + 5*x)^2, x, 2, 36*x + 42*x^2 - (227*x^3)/3 - (341*x^4)/2 + (109*x^5)/5 + 230*x^6 + (900*x^7)/7}
{(1 - 2*x)^2*(2 + 3*x)*(3 + 5*x)^2, x, 2, 18*x + (15*x^2)/2 - (136*x^3)/3 - (137*x^4)/4 + 52*x^5 + 50*x^6}
{(1 - 2*x)^2*(3 + 5*x)^2, x, 2, 9*x - 3*x^2 - (59*x^3)/3 + 5*x^4 + 20*x^5}
{((1 - 2*x)^2*(3 + 5*x)^2)/(2 + 3*x), x, 2, (340*x)/81 - (251*x^2)/54 - (140*x^3)/27 + (25*x^4)/3 + (49*Log[2 + 3*x])/243}
{((1 - 2*x)^2*(3 + 5*x)^2)/(2 + 3*x)^2, x, 2, (143*x)/27 - (170*x^2)/27 + (100*x^3)/27 - 49/(243*(2 + 3*x)) - (518*Log[2 + 3*x])/243}
{((1 - 2*x)^2*(3 + 5*x)^2)/(2 + 3*x)^3, x, 2, (-20*x)/3 + (50*x^2)/27 - 49/(486*(2 + 3*x)^2) + 518/(243*(2 + 3*x)) + (503*Log[2 + 3*x])/81}
{((1 - 2*x)^2*(3 + 5*x)^2)/(2 + 3*x)^4, x, 2, (100*x)/81 - 49/(729*(2 + 3*x)^3) + 259/(243*(2 + 3*x)^2) - 503/(81*(2 + 3*x)) - (740*Log[2 + 3*x])/243}
{((1 - 2*x)^2*(3 + 5*x)^2)/(2 + 3*x)^5, x, 2, -49/(972*(2 + 3*x)^4) + 518/(729*(2 + 3*x)^3) - 503/(162*(2 + 3*x)^2) + 740/(243*(2 + 3*x)) + (100*Log[2 + 3*x])/243}
{((1 - 2*x)^2*(3 + 5*x)^2)/(2 + 3*x)^6, x, 2, -49/(1215*(2 + 3*x)^5) + 259/(486*(2 + 3*x)^4) - 503/(243*(2 + 3*x)^3) + 370/(243*(2 + 3*x)^2) - 100/(243*(2 + 3*x))}
{((1 - 2*x)^2*(3 + 5*x)^2)/(2 + 3*x)^7, x, 2, -49/(1458*(2 + 3*x)^6) + 518/(1215*(2 + 3*x)^5) - 503/(324*(2 + 3*x)^4) + 740/(729*(2 + 3*x)^3) - 50/(243*(2 + 3*x)^2)}
{((1 - 2*x)^2*(3 + 5*x)^2)/(2 + 3*x)^8, x, 2, -7/(243*(2 + 3*x)^7) + 259/(729*(2 + 3*x)^6) - 503/(405*(2 + 3*x)^5) + 185/(243*(2 + 3*x)^4) - 100/(729*(2 + 3*x)^3)}


{(1 - 2*x)^2*(2 + 3*x)^10*(3 + 5*x)^3, x, 2, -((49*(2 + 3*x)^11)/8019) + (763*(2 + 3*x)^12)/8748 - (4099*(2 + 3*x)^13)/9477 + (8285*(2 + 3*x)^14)/10206 - (760*(2 + 3*x)^15)/2187 + (125*(2 + 3*x)^16)/2916}
{(1 - 2*x)^2*(2 + 3*x)^9*(3 + 5*x)^3, x, 2, -((49*(2 + 3*x)^10)/7290) + (763*(2 + 3*x)^11)/8019 - (4099*(2 + 3*x)^12)/8748 + (8285*(2 + 3*x)^13)/9477 - (1900*(2 + 3*x)^14)/5103 + (100*(2 + 3*x)^15)/2187}
{(1 - 2*x)^2*(2 + 3*x)^8*(3 + 5*x)^3, x, 2, 6912*x + 44928*x^2 + 155136*x^3 + 261440*x^4 - (202208*x^5)/5 - (3530000*x^6)/3 - (17018256*x^7)/7 - 1660896*x^8 + 2124195*x^9 + (62652123*x^10)/10 + (77509953*x^11)/11 + (17759655*x^12)/4 + (20120400*x^13)/13 + (1640250*x^14)/7}
{(1 - 2*x)^2*(2 + 3*x)^7*(3 + 5*x)^3, x, 2, 3456*x + 19872*x^2 + 57696*x^3 + 65812*x^4 - (495976*x^5)/5 - (1393018*x^6)/3 - 618582*x^7 - (148473*x^8)/8 + 1086843*x^9 + (16653681*x^10)/10 + (13774455*x^11)/11 + 498150*x^12 + (1093500*x^13)/13}
{(1 - 2*x)^2*(2 + 3*x)^6*(3 + 5*x)^3, x, 2, 1728*x + 8640*x^2 + 20208*x^3 + 10172*x^4 - 61804*x^5 - (464744*x^6)/3 - 110115*x^7 + (1081971*x^8)/8 + 363093*x^9 + (685017*x^10)/2 + (1749600*x^11)/11 + 30375*x^12}
{(1 - 2*x)^2*(2 + 3*x)^5*(3 + 5*x)^3, x, 2, 864*x + 3672*x^2 + 6432*x^3 - 2150*x^4 - 28322*x^5 - (252329*x^6)/6 - 987*x^7 + (551349*x^8)/8 + 89655*x^9 + 50220*x^10 + (121500*x^11)/11}
{(1 - 2*x)^2*(2 + 3*x)^4*(3 + 5*x)^3, x, 2, 432*x + 1512*x^2 + 1704*x^3 - 2992*x^4 - (52853*x^5)/5 - (46885*x^6)/6 + (66873*x^7)/7 + (175365*x^8)/8 + 15600*x^9 + 4050*x^10}
{(1 - 2*x)^2*(2 + 3*x)^3*(3 + 5*x)^3, x, 2, 216*x + 594*x^2 + 258*x^3 - (7145*x^4)/4 - (15709*x^5)/5 + (121*x^6)/6 + (33255*x^7)/7 + 4725*x^8 + 1500*x^9}
{(1 - 2*x)^2*(2 + 3*x)^2*(3 + 5*x)^3, x, 2, 108*x + 216*x^2 - 87*x^3 - (3181*x^4)/4 - (3083*x^5)/5 + (4685*x^6)/6 + (9600*x^7)/7 + (1125*x^8)/2}
{(1 - 2*x)^2*(2 + 3*x)*(3 + 5*x)^3, x, 2, 54*x + (135*x^2)/2 - 111*x^3 - (1091*x^4)/4 + 19*x^5 + (1100*x^6)/3 + (1500*x^7)/7}
{(1 - 2*x)^2*(3 + 5*x)^3, x, 2, 27*x + (27*x^2)/2 - 69*x^3 - (235*x^4)/4 + 80*x^5 + (250*x^6)/3}
{((1 - 2*x)^2*(3 + 5*x)^3)/(2 + 3*x), x, 2, (3305*x)/243 - (559*x^2)/162 - (2515*x^3)/81 + (50*x^4)/9 + (100*x^5)/3 - (49*Log[2 + 3*x])/729}
{((1 - 2*x)^2*(3 + 5*x)^3)/(2 + 3*x)^2, x, 2, (1271*x)/243 - (305*x^2)/54 - (800*x^3)/81 + (125*x^4)/9 + 49/(729*(2 + 3*x)) + (763*Log[2 + 3*x])/729}
{((1 - 2*x)^2*(3 + 5*x)^3)/(2 + 3*x)^3, x, 2, (895*x)/81 - (100*x^2)/9 + (500*x^3)/81 + 49/(1458*(2 + 3*x)^2) - 763/(729*(2 + 3*x)) - (4099*Log[2 + 3*x])/729}
{((1 - 2*x)^2*(3 + 5*x)^3)/(2 + 3*x)^4, x, 2, (-2800*x)/243 + (250*x^2)/81 + 49/(2187*(2 + 3*x)^3) - 763/(1458*(2 + 3*x)^2) + 4099/(729*(2 + 3*x)) + (8285*Log[2 + 3*x])/729}
{((1 - 2*x)^2*(3 + 5*x)^3)/(2 + 3*x)^5, x, 2, (500*x)/243 + 49/(2916*(2 + 3*x)^4) - 763/(2187*(2 + 3*x)^3) + 4099/(1458*(2 + 3*x)^2) - 8285/(729*(2 + 3*x)) - (3800*Log[2 + 3*x])/729}
{((1 - 2*x)^2*(3 + 5*x)^3)/(2 + 3*x)^6, x, 2, 49/(3645*(2 + 3*x)^5) - 763/(2916*(2 + 3*x)^4) + 4099/(2187*(2 + 3*x)^3) - 8285/(1458*(2 + 3*x)^2) + 3800/(729*(2 + 3*x)) + (500*Log[2 + 3*x])/729}
{((1 - 2*x)^2*(3 + 5*x)^3)/(2 + 3*x)^7, x, 2, 49/(4374*(2 + 3*x)^6) - 763/(3645*(2 + 3*x)^5) + 4099/(2916*(2 + 3*x)^4) - 8285/(2187*(2 + 3*x)^3) + 1900/(729*(2 + 3*x)^2) - 500/(729*(2 + 3*x))}
{((1 - 2*x)^2*(3 + 5*x)^3)/(2 + 3*x)^8, x, 2, 7/(729*(2 + 3*x)^7) - 763/(4374*(2 + 3*x)^6) + 4099/(3645*(2 + 3*x)^5) - 8285/(2916*(2 + 3*x)^4) + 3800/(2187*(2 + 3*x)^3) - 250/(729*(2 + 3*x)^2)}


(* ::Subsubsection::Closed:: *)
(*n<0*)


{((1 - 2*x)^2*(2 + 3*x)^7)/(3 + 5*x), x, 2, (83333293*x)/1953125 + (80555569*x^2)/781250 + (1327159*x^3)/78125 - (20577159*x^4)/62500 - (7315947*x^5)/15625 + (130383*x^6)/1250 + (672867*x^7)/875 + (16767*x^8)/25 + (972*x^9)/5 + (121*Log[3 + 5*x])/9765625}
{((1 - 2*x)^2*(2 + 3*x)^6)/(3 + 5*x), x, 2, (8333293*x)/390625 + (5555569*x^2)/156250 - (422841*x^3)/15625 - (1677159*x^4)/12500 - (228447*x^5)/3125 + (35883*x^6)/250 + (34992*x^7)/175 + (729*x^8)/10 + (121*Log[3 + 5*x])/1953125}
{((1 - 2*x)^2*(2 + 3*x)^5)/(3 + 5*x), x, 2, (833293*x)/78125 + (305569*x^2)/31250 - (72841*x^3)/3125 - (102159*x^4)/2500 + (7803*x^5)/625 + (1404*x^6)/25 + (972*x^7)/35 + (121*Log[3 + 5*x])/390625}
{((1 - 2*x)^2*(2 + 3*x)^4)/(3 + 5*x), x, 2, (83293*x)/15625 + (5569*x^2)/6250 - (7841*x^3)/625 - (3159*x^4)/500 + (1728*x^5)/125 + (54*x^6)/5 + (121*Log[3 + 5*x])/78125}
{((1 - 2*x)^2*(2 + 3*x)^3)/(3 + 5*x), x, 2, (8293*x)/3125 - (1931*x^2)/1250 - (591*x^3)/125 + (54*x^4)/25 + (108*x^5)/25 + (121*Log[3 + 5*x])/15625}
{((1 - 2*x)^2*(2 + 3*x)^2)/(3 + 5*x), x, 2, (793*x)/625 - (431*x^2)/250 - (16*x^3)/25 + (9*x^4)/5 + (121*Log[3 + 5*x])/3125}
{((1 - 2*x)^2*(2 + 3*x)^1)/(3 + 5*x), x, 2, (43*x)/125 - (28*x^2)/25 + (4*x^3)/5 + (121/625)*Log[3 + 5*x]}
{((1 - 2*x)^2*(2 + 3*x)^0)/(3 + 5*x), x, 2, -((32*x)/25) + (2*x^2)/5 + (121/125)*Log[3 + 5*x]}
{(1 - 2*x)^2/((2 + 3*x)*(3 + 5*x)), x, 2, (4*x)/15 - (49*Log[2 + 3*x])/9 + (121*Log[3 + 5*x])/25}
{(1 - 2*x)^2/((2 + 3*x)^2*(3 + 5*x)), x, 2, 49/(9*(2 + 3*x)) - (217*Log[2 + 3*x])/9 + (121*Log[3 + 5*x])/5}
{(1 - 2*x)^2/((2 + 3*x)^3*(3 + 5*x)), x, 2, 49/(18*(2 + 3*x)^2) + 217/(9*(2 + 3*x)) - 121*Log[2 + 3*x] + 121*Log[3 + 5*x]}
{(1 - 2*x)^2/((2 + 3*x)^4*(3 + 5*x)), x, 2, 49/(27*(2 + 3*x)^3) + 217/(18*(2 + 3*x)^2) + 121/(2 + 3*x) - 605*Log[2 + 3*x] + 605*Log[3 + 5*x]}
{(1 - 2*x)^2/((2 + 3*x)^5*(3 + 5*x)), x, 2, 49/(36*(2 + 3*x)^4) + 217/(27*(2 + 3*x)^3) + 121/(2*(2 + 3*x)^2) + 605/(2 + 3*x) - 3025*Log[2 + 3*x] + 3025*Log[3 + 5*x]}
{(1 - 2*x)^2/((2 + 3*x)^6*(3 + 5*x)), x, 2, 49/(45*(2 + 3*x)^5) + 217/(36*(2 + 3*x)^4) + 121/(3*(2 + 3*x)^3) + 605/(2*(2 + 3*x)^2) + 3025/(2 + 3*x) - 15125*Log[2 + 3*x] + 15125*Log[3 + 5*x]}
{(1 - 2*x)^2/((2 + 3*x)^7*(3 + 5*x)), x, 2, 49/(54*(2 + 3*x)^6) + 217/(45*(2 + 3*x)^5) + 121/(4*(2 + 3*x)^4) + 605/(3*(2 + 3*x)^3) + 3025/(2*(2 + 3*x)^2) + 15125/(2 + 3*x) - 75625*Log[2 + 3*x] + 75625*Log[3 + 5*x]}
{(1 - 2*x)^2/((2 + 3*x)^8*(3 + 5*x)), x, 2, 7/(9*(2 + 3*x)^7) + 217/(54*(2 + 3*x)^6) + 121/(5*(2 + 3*x)^5) + 605/(4*(2 + 3*x)^4) + 3025/(3*(2 + 3*x)^3) + 15125/(2*(2 + 3*x)^2) + 75625/(2 + 3*x) - 378125*Log[2 + 3*x] + 378125*Log[3 + 5*x]}


{((1 - 2*x)^2*(2 + 3*x)^7)/(3 + 5*x)^2, x, 2, (27776932*x)/1953125 + (17592879*x^2)/781250 - (1512378*x^3)/78125 - (213867*x^4)/2500 - (656424*x^5)/15625 + (116397*x^6)/1250 + (107892*x^7)/875 + (2187*x^8)/50 - 121/(9765625*(3 + 5*x)) + (2497*Log[3 + 5*x])/9765625}
{((1 - 2*x)^2*(2 + 3*x)^6)/(3 + 5*x)^2, x, 2, (2777053*x)/390625 + (463086*x^2)/78125 - (48771*x^3)/3125 - (157599*x^4)/6250 + (28917*x^5)/3125 + (4374*x^6)/125 + (2916*x^7)/175 - 121/(1953125*(3 + 5*x)) + (2134*Log[3 + 5*x])/1953125}
{((1 - 2*x)^2*(2 + 3*x)^5)/(3 + 5*x)^2, x, 2, (277174*x)/78125 + (1893*x^2)/6250 - (25332*x^3)/3125 - (8721*x^4)/2500 + (5508*x^5)/625 + (162*x^6)/25 - 121/(390625*(3 + 5*x)) + (1771*Log[3 + 5*x])/390625}
{((1 - 2*x)^2*(2 + 3*x)^4)/(3 + 5*x)^2, x, 2, (5459*x)/3125 - (3621*x^2)/3125 - (1809*x^3)/625 + (189*x^4)/125 + (324*x^5)/125 - 121/(78125*(3 + 5*x)) + (1408*Log[3 + 5*x])/78125}
{((1 - 2*x)^2*(2 + 3*x)^3)/(3 + 5*x)^2, x, 2, (2416*x)/3125 - (1449*x^2)/1250 - (36*x^3)/125 + (27*x^4)/25 - 121/(15625*(3 + 5*x)) + (209*Log[3 + 5*x])/3125}
{((1 - 2*x)^2*(2 + 3*x)^2)/(3 + 5*x)^2, x, 2, (37*x)/625 - (78*x^2)/125 + (12*x^3)/25 - 121/(3125*(3 + 5*x)) + (682*Log[3 + 5*x])/3125}
{((1 - 2*x)^2*(2 + 3*x))/(3 + 5*x)^2, x, 2, (-92*x)/125 + (6*x^2)/25 - 121/(625*(3 + 5*x)) + (319*Log[3 + 5*x])/625}
{(1 - 2*x)^2/(3 + 5*x)^2, x, 2, (4*x)/25 - 121/(125*(3 + 5*x)) - (44*Log[3 + 5*x])/125}
{(1 - 2*x)^2/((2 + 3*x)*(3 + 5*x)^2), x, 2, -121/(25*(3 + 5*x)) + (49*Log[2 + 3*x])/3 - (407*Log[3 + 5*x])/25}
{(1 - 2*x)^2/((2 + 3*x)^2*(3 + 5*x)^2), x, 2, -49/(3*(2 + 3*x)) - 121/(5*(3 + 5*x)) + 154*Log[2 + 3*x] - 154*Log[3 + 5*x]}
{(1 - 2*x)^2/((2 + 3*x)^3*(3 + 5*x)^2), x, 2, -49/(6*(2 + 3*x)^2) - 154/(2 + 3*x) - 121/(3 + 5*x) + 1133*Log[2 + 3*x] - 1133*Log[3 + 5*x]}
{(1 - 2*x)^2/((2 + 3*x)^4*(3 + 5*x)^2), x, 2, -49/(9*(2 + 3*x)^3) - 77/(2 + 3*x)^2 - 1133/(2 + 3*x) - 605/(3 + 5*x) + 7480*Log[2 + 3*x] - 7480*Log[3 + 5*x]}
{(1 - 2*x)^2/((2 + 3*x)^5*(3 + 5*x)^2), x, 2, -49/(12*(2 + 3*x)^4) - 154/(3*(2 + 3*x)^3) - 1133/(2*(2 + 3*x)^2) - 7480/(2 + 3*x) - 3025/(3 + 5*x) + 46475*Log[2 + 3*x] - 46475*Log[3 + 5*x]}
{(1 - 2*x)^2/((2 + 3*x)^6*(3 + 5*x)^2), x, 2, -49/(15*(2 + 3*x)^5) - 77/(2*(2 + 3*x)^4) - 1133/(3*(2 + 3*x)^3) - 3740/(2 + 3*x)^2 - 46475/(2 + 3*x) - 15125/(3 + 5*x) + 277750*Log[2 + 3*x] - 277750*Log[3 + 5*x]}
{(1 - 2*x)^2/((2 + 3*x)^7*(3 + 5*x)^2), x, 2, -49/(18*(2 + 3*x)^6) - 154/(5*(2 + 3*x)^5) - 1133/(4*(2 + 3*x)^4) - 7480/(3*(2 + 3*x)^3) - 46475/(2*(2 + 3*x)^2) - 277750/(2 + 3*x) - 75625/(3 + 5*x) + 1615625*Log[2 + 3*x] - 1615625*Log[3 + 5*x]}
{(1 - 2*x)^2/((2 + 3*x)^8*(3 + 5*x)^2), x, 2, -7/(3*(2 + 3*x)^7) - 77/(3*(2 + 3*x)^6) - 1133/(5*(2 + 3*x)^5) - 1870/(2 + 3*x)^4 - 46475/(3*(2 + 3*x)^3) - 138875/(2 + 3*x)^2 - 1615625/(2 + 3*x) - 378125/(3 + 5*x) + 9212500*Log[2 + 3*x] - 9212500*Log[3 + 5*x]}


{((1 - 2*x)^2*(2 + 3*x)^8)/(3 + 5*x)^3, x, 2, (92582457*x)/9765625 + (55559043*x^2)/3906250 - (5350194*x^3)/390625 - (1700919*x^4)/31250 - (74601*x^5)/3125 + (376407*x^6)/6250 + (332424*x^7)/4375 + (6561*x^8)/250 - 121/(97656250*(3 + 5*x)^2) - 572/(9765625*(3 + 5*x)) + (5888*Log[3 + 5*x])/9765625}
{((1 - 2*x)^2*(2 + 3*x)^7)/(3 + 5*x)^3, x, 2, (9251661*x)/1953125 + (1390203*x^2)/390625 - (162612*x^3)/15625 - (193833*x^4)/12500 + (104247*x^5)/15625 + (13608*x^6)/625 + (8748*x^7)/875 - 121/(19531250*(3 + 5*x)^2) - 2497/(9765625*(3 + 5*x)) + (21949*Log[3 + 5*x])/9765625}
{((1 - 2*x)^2*(2 + 3*x)^6)/(3 + 5*x)^3, x, 2, (920502*x)/390625 + (189*x^2)/15625 - (16299*x^3)/3125 - (23571*x^4)/12500 + (17496*x^5)/3125 + (486*x^6)/125 - 121/(3906250*(3 + 5*x)^2) - 2134/(1953125*(3 + 5*x)) + (15547*Log[3 + 5*x])/1953125}
{((1 - 2*x)^2*(2 + 3*x)^5)/(3 + 5*x)^3, x, 2, (17796*x)/15625 - (5301*x^2)/6250 - (5499*x^3)/3125 + (648*x^4)/625 + (972*x^5)/625 - 121/(781250*(3 + 5*x)^2) - 1771/(390625*(3 + 5*x)) + (10234*Log[3 + 5*x])/390625}
{((1 - 2*x)^2*(2 + 3*x)^4)/(3 + 5*x)^3, x, 2, (1419*x)/3125 - (4779*x^2)/6250 - (72*x^3)/625 + (81*x^4)/125 - 121/(156250*(3 + 5*x)^2) - 1408/(78125*(3 + 5*x)) + (1202*Log[3 + 5*x])/15625}
{((1 - 2*x)^2*(2 + 3*x)^3)/(3 + 5*x)^3, x, 2, (-153*x)/3125 - (216*x^2)/625 + (36*x^3)/125 - 121/(31250*(3 + 5*x)^2) - 209/(3125*(3 + 5*x)) + (23*Log[3 + 5*x])/125}
{((1 - 2*x)^2*(2 + 3*x)^2)/(3 + 5*x)^3, x, 2, (-264*x)/625 + (18*x^2)/125 - 121/(6250*(3 + 5*x)^2) - 682/(3125*(3 + 5*x)) + (829*Log[3 + 5*x])/3125}
{((1 - 2*x)^2*(2 + 3*x))/(3 + 5*x)^3, x, 2, (12*x)/125 - 121/(1250*(3 + 5*x)^2) - 319/(625*(3 + 5*x)) - (128*Log[3 + 5*x])/625}
{(1 - 2*x)^2/(3 + 5*x)^3, x, 2, -121/(250*(3 + 5*x)^2) + 44/(125*(3 + 5*x)) + (4*Log[3 + 5*x])/125}
{(1 - 2*x)^2/((2 + 3*x)*(3 + 5*x)^3), x, 2, -121/(50*(3 + 5*x)^2) + 407/(25*(3 + 5*x)) - 49*Log[2 + 3*x] + 49*Log[3 + 5*x]}
{(1 - 2*x)^2/((2 + 3*x)^2*(3 + 5*x)^3), x, 2, 49/(2 + 3*x) - 121/(10*(3 + 5*x)^2) + 154/(3 + 5*x) - 707*Log[2 + 3*x] + 707*Log[3 + 5*x]}
{(1 - 2*x)^2/((2 + 3*x)^3*(3 + 5*x)^3), x, 2, 49/(2*(2 + 3*x)^2) + 707/(2 + 3*x) - 121/(2*(3 + 5*x)^2) + 1133/(3 + 5*x) - 6934*Log[2 + 3*x] + 6934*Log[3 + 5*x]}
{(1 - 2*x)^2/((2 + 3*x)^4*(3 + 5*x)^3), x, 2, 49/(3*(2 + 3*x)^3) + 707/(2*(2 + 3*x)^2) + 6934/(2 + 3*x) - 605/(2*(3 + 5*x)^2) + 7480/(3 + 5*x) - 57110*Log[2 + 3*x] + 57110*Log[3 + 5*x]}
{(1 - 2*x)^2/((2 + 3*x)^5*(3 + 5*x)^3), x, 2, 49/(4*(2 + 3*x)^4) + 707/(3*(2 + 3*x)^3) + 3467/(2 + 3*x)^2 + 57110/(2 + 3*x) - 3025/(2*(3 + 5*x)^2) + 46475/(3 + 5*x) - 424975*Log[2 + 3*x] + 424975*Log[3 + 5*x]}
{(1 - 2*x)^2/((2 + 3*x)^6*(3 + 5*x)^3), x, 2, 49/(5*(2 + 3*x)^5) + 707/(4*(2 + 3*x)^4) + 6934/(3*(2 + 3*x)^3) + 28555/(2 + 3*x)^2 + 424975/(2 + 3*x) - 15125/(2*(3 + 5*x)^2) + 277750/(3 + 5*x) - 2958125*Log[2 + 3*x] + 2958125*Log[3 + 5*x]}
{(1 - 2*x)^2/((2 + 3*x)^7*(3 + 5*x)^3), x, 2, 49/(6*(2 + 3*x)^6) + 707/(5*(2 + 3*x)^5) + 3467/(2*(2 + 3*x)^4) + 57110/(3*(2 + 3*x)^3) + 424975/(2*(2 + 3*x)^2) + 2958125/(2 + 3*x) - 75625/(2*(3 + 5*x)^2) + 1615625/(3 + 5*x) - 19637500*Log[2 + 3*x] + 19637500*Log[3 + 5*x]}
{(1 - 2*x)^2/((2 + 3*x)^8*(3 + 5*x)^3), x, 2, 7/(2 + 3*x)^7 + 707/(6*(2 + 3*x)^6) + 6934/(5*(2 + 3*x)^5) + 28555/(2*(2 + 3*x)^4) + 424975/(3*(2 + 3*x)^3) + 2958125/(2*(2 + 3*x)^2) + 19637500/(2 + 3*x) - 378125/(2*(3 + 5*x)^2) + 9212500/(3 + 5*x) - 125825000*Log[2 + 3*x] + 125825000*Log[3 + 5*x]}


(* ::Subsection::Closed:: *)
(*Integrands of the form (a+b x)^m (c+d x)^n (e+f x)^3*)


(* ::Subsubsection::Closed:: *)
(*n>0*)


{(1 - 2*x)^3*(2 + 3*x)^8*(3 + 5*x), x, 2, (-343*(2 + 3*x)^9)/2187 + (2009*(2 + 3*x)^10)/2430 - (518*(2 + 3*x)^11)/891 + (107*(2 + 3*x)^12)/729 - (40*(2 + 3*x)^13)/3159}
{(1 - 2*x)^3*(2 + 3*x)^7*(3 + 5*x), x, 2, 384*x + 1184*x^2 + 480*x^3 - 5148*x^4 - (48968*x^5)/5 + 3514*x^6 + 29106*x^7 + (208035*x^8)/8 - 15507*x^9 - (217971*x^10)/5 - (329508*x^11)/11 - 7290*x^12}
{(1 - 2*x)^3*(2 + 3*x)^6*(3 + 5*x), x, 2, 192*x + 448*x^2 - 208*x^3 - 2340*x^4 - (10444*x^5)/5 + 4368*x^6 + 8937*x^7 + (10179*x^8)/8 - 9450*x^9 - (45198*x^10)/5 - (29160*x^11)/11}
{(1 - 2*x)^3*(2 + 3*x)^5*(3 + 5*x), x, 2, 96*x + 152*x^2 - 256*x^3 - 882*x^4 + 14*x^5 + (4333*x^6)/2 + 1683*x^7 - (6291*x^8)/4 - 2628*x^9 - 972*x^10}
{(1 - 2*x)^3*(2 + 3*x)^4*(3 + 5*x), x, 2, 48*x + 40*x^2 - 168*x^3 - 252*x^4 + (1547*x^5)/5 + (1393*x^6)/2 - 54*x^7 - (1431*x^8)/2 - 360*x^9}
{(1 - 2*x)^3*(2 + 3*x)^3*(3 + 5*x), x, 2, 24*x + 2*x^2 - 86*x^3 - (117*x^4)/4 + (949*x^5)/5 + 111*x^6 - (1188*x^7)/7 - 135*x^8}
{(1 - 2*x)^3*(2 + 3*x)^2*(3 + 5*x), x, 2, 12*x - 8*x^2 - 35*x^3 + (99*x^4)/4 + (326*x^5)/5 - 26*x^6 - (360*x^7)/7}
{(1 - 2*x)^3*(2 + 3*x)*(3 + 5*x), x, 2, 6*x - (17*x^2)/2 - 9*x^3 + (45*x^4)/2 + (28*x^5)/5 - 20*x^6}
{(1 - 2*x)^3*(3 + 5*x), x, 2, 3*x - (13*x^2)/2 + 2*x^3 + 9*x^4 - 8*x^5}
{((1 - 2*x)^3*(3 + 5*x))/(2 + 3*x), x, 2, (293*x)/81 - (161*x^2)/27 + (188*x^3)/27 - (10*x^4)/3 - (343/243)*Log[2 + 3*x]}
{((1 - 2*x)^3*(3 + 5*x))/(2 + 3*x)^2, x, 2, (-286*x)/27 + (134*x^2)/27 - (40*x^3)/27 + 343/(243*(2 + 3*x)) + (2009*Log[2 + 3*x])/243}
{((1 - 2*x)^3*(3 + 5*x))/(2 + 3*x)^3, x, 2, (116*x)/27 - (20*x^2)/27 + 343/(486*(2 + 3*x)^2) - 2009/(243*(2 + 3*x)) - (518*Log[2 + 3*x])/81}
{((1 - 2*x)^3*(3 + 5*x))/(2 + 3*x)^4, x, 2, (-40*x)/81 + 343/(729*(2 + 3*x)^3) - 2009/(486*(2 + 3*x)^2) + 518/(81*(2 + 3*x)) + (428*Log[2 + 3*x])/243}
{((1 - 2*x)^3*(3 + 5*x))/(2 + 3*x)^5, x, 2, 343/(972*(2 + 3*x)^4) - 2009/(729*(2 + 3*x)^3) + 259/(81*(2 + 3*x)^2) - 428/(243*(2 + 3*x)) - (40/243)*Log[2 + 3*x]}
{((1 - 2*x)^3*(3 + 5*x))/(2 + 3*x)^6, x, 2, (1 - 2*x)^4/(105*(2 + 3*x)^5) - (173*(1 - 2*x)^4)/(2940*(2 + 3*x)^4)}
{((1 - 2*x)^3*(3 + 5*x))/(2 + 3*x)^7, x, 3, (1 - 2*x)^4/(126*(2 + 3*x)^6) - (103*(1 - 2*x)^4)/(2205*(2 + 3*x)^5) - (103*(1 - 2*x)^4)/(30870*(2 + 3*x)^4)}
{((1 - 2*x)^3*(3 + 5*x))/(2 + 3*x)^8, x, 2, 49/(243*(2 + 3*x)^7) - 2009/(1458*(2 + 3*x)^6) + 518/(405*(2 + 3*x)^5) - 107/(243*(2 + 3*x)^4) + 40/(729*(2 + 3*x)^3)}


{(1 - 2*x)^3*(2 + 3*x)^8*(3 + 5*x)^2, x, 2, 2304*x + 10752*x^2 + (59392*x^3)/3 - 15168*x^4 - (663456*x^5)/5 - (556384*x^6)/3 + (888528*x^7)/7 + 679446*x^8 + 685713*x^9 - (1073412*x^10)/5 - (12353391*x^11)/11 - (2220777*x^12)/2 - (6604740*x^13)/13 - (656100*x^14)/7}
{(1 - 2*x)^3*(2 + 3*x)^7*(3 + 5*x)^2, x, 2, 1152*x + 4512*x^2 + (16160*x^3)/3 - 13644*x^4 - (249864*x^5)/5 - (90794*x^6)/3 + 102378*x^7 + (1642815*x^8)/8 + 69054*x^9 - (2005641*x^10)/10 - (3168234*x^11)/11 - 159165*x^12 - (437400*x^13)/13}
{(1 - 2*x)^3*(2 + 3*x)^6*(3 + 5*x)^2, x, 2, 576*x + 1824*x^2 + (2608*x^3)/3 - 7800*x^4 - (78132*x^5)/5 + (13202*x^6)/3 + 45531*x^7 + (85833*x^8)/2 - 22695*x^9 - (348219*x^10)/5 - (539460*x^11)/11 - 12150*x^12}
{(1 - 2*x)^3*(2 + 3*x)^5*(3 + 5*x)^2, x, 2, 288*x + 696*x^2 - (784*x^3)/3 - 3606*x^4 - 3486*x^5 + (39347*x^6)/6 + 14334*x^7 + (21159*x^8)/8 - 14874*x^9 - 14742*x^10 - (48600*x^11)/11}
{(1 - 2*x)^3*(2 + 3*x)^4*(3 + 5*x)^2, x, 2, 144*x + 240*x^2 - (1112*x^3)/3 - 1386*x^4 - (399*x^5)/5 + (10136*x^6)/3 + 2823*x^7 - (9531*x^8)/4 - 4260*x^9 - 1620*x^10}
{(1 - 2*x)^3*(2 + 3*x)^3*(3 + 5*x)^2, x, 2, 72*x + 66*x^2 - (754*x^3)/3 - (1641*x^4)/4 + (2262*x^5)/5 + (6743*x^6)/6 - (234*x^7)/7 - (2295*x^8)/2 - 600*x^9}
{(1 - 2*x)^3*(2 + 3*x)^2*(3 + 5*x)^2, x, 2, 36*x + 6*x^2 - (395*x^3)/3 - 57*x^4 + (1473*x^5)/5 + (581*x^6)/3 - (1860*x^7)/7 - 225*x^8}
{(1 - 2*x)^3*(2 + 3*x)*(3 + 5*x)^2, x, 2, 18*x - (21*x^2)/2 - (166*x^3)/3 + (135*x^4)/4 + (534*x^5)/5 - (110*x^6)/3 - (600*x^7)/7}
{(1 - 2*x)^3*(3 + 5*x)^2, x, 2, 9*x - 12*x^2 - (47*x^3)/3 + (69*x^4)/2 + 12*x^5 - (100*x^6)/3}
{((1 - 2*x)^3*(3 + 5*x)^2)/(2 + 3*x), x, 2, (922*x)/243 - (1433*x^2)/162 + (82*x^3)/81 + (145*x^4)/9 - (40*x^5)/3 + (343*Log[2 + 3*x])/729}
{((1 - 2*x)^3*(3 + 5*x)^2)/(2 + 3*x)^2, x, 2, (2323*x)/243 - (313*x^2)/27 + (980*x^3)/81 - (50*x^4)/9 - 343/(729*(2 + 3*x)) - (3724*Log[2 + 3*x])/729}
{((1 - 2*x)^3*(3 + 5*x)^2)/(2 + 3*x)^3, x, 2, (-1546*x)/81 + (230*x^2)/27 - (200*x^3)/81 - 343/(1458*(2 + 3*x)^2) + 3724/(729*(2 + 3*x)) + (11599*Log[2 + 3*x])/729}
{((1 - 2*x)^3*(3 + 5*x)^2)/(2 + 3*x)^4, x, 2, (1780*x)/243 - (100*x^2)/81 - 343/(2187*(2 + 3*x)^3) + 1862/(729*(2 + 3*x)^2) - 11599/(729*(2 + 3*x)) - (8198*Log[2 + 3*x])/729}
{((1 - 2*x)^3*(3 + 5*x)^2)/(2 + 3*x)^5, x, 2, (-200*x)/243 - 343/(2916*(2 + 3*x)^4) + 3724/(2187*(2 + 3*x)^3) - 11599/(1458*(2 + 3*x)^2) + 8198/(729*(2 + 3*x)) + (2180*Log[2 + 3*x])/729}
{((1 - 2*x)^3*(3 + 5*x)^2)/(2 + 3*x)^6, x, 2, -343/(3645*(2 + 3*x)^5) + 931/(729*(2 + 3*x)^4) - 11599/(2187*(2 + 3*x)^3) + 4099/(729*(2 + 3*x)^2) - 2180/(729*(2 + 3*x)) - (200*Log[2 + 3*x])/729}
{((1 - 2*x)^3*(3 + 5*x)^2)/(2 + 3*x)^7, x, 2, -343/(4374*(2 + 3*x)^6) + 3724/(3645*(2 + 3*x)^5) - 11599/(2916*(2 + 3*x)^4) + 8198/(2187*(2 + 3*x)^3) - 1090/(729*(2 + 3*x)^2) + 200/(729*(2 + 3*x))}
{((1 - 2*x)^3*(3 + 5*x)^2)/(2 + 3*x)^8, x, 2, -49/(729*(2 + 3*x)^7) + 1862/(2187*(2 + 3*x)^6) - 11599/(3645*(2 + 3*x)^5) + 4099/(1458*(2 + 3*x)^4) - 2180/(2187*(2 + 3*x)^3) + 100/(729*(2 + 3*x)^2)}


{(1 - 2*x)^3*(2 + 3*x)^7*(3 + 5*x)^3, x, 2, 3456*x + 16416*x^2 + 31200*x^3 - 20732*x^4 - (1022472*x^5)/5 - 299014*x^6 + (1241998*x^7)/7 + (8511675*x^8)/8 + 1119837*x^9 - (2909493*x^10)/10 - (19532907*x^11)/11 - (3595185*x^12)/2 - (10862100*x^13)/13 - (1093500*x^14)/7}
{(1 - 2*x)^3*(2 + 3*x)^6*(3 + 5*x)^3, x, 2, 1728*x + 6912*x^2 + 8688*x^3 - 20140*x^4 - (390396*x^5)/5 - 51908*x^6 + 155453*x^7 + (2623581*x^8)/8 + 122655*x^9 - (3110589*x^10)/10 - (5100570*x^11)/11 - 261225*x^12 - (729000*x^13)/13}
{(1 - 2*x)^3*(2 + 3*x)^5*(3 + 5*x)^3, x, 2, 864*x + 2808*x^2 + 1536*x^3 - 11798*x^4 - 24882*x^5 + (10297*x^6)/2 + 71107*x^7 + (565167*x^8)/8 - 32867*x^9 - 111159*x^10 - (882900*x^11)/11 - 20250*x^12}
{(1 - 2*x)^3*(2 + 3*x)^4*(3 + 5*x)^3, x, 2, 432*x + 1080*x^2 - 312*x^3 - 5548*x^4 - (28917*x^5)/5 + (19607*x^6)/2 + 22949*x^7 + (41619*x^8)/8 - 23370*x^9 - 24030*x^10 - (81000*x^11)/11}
{(1 - 2*x)^3*(2 + 3*x)^3*(3 + 5*x)^3, x, 2, 216*x + 378*x^2 - 534*x^3 - (8693*x^4)/4 - (1419*x^5)/5 + (10513*x^6)/2 + (33013*x^7)/7 - (14355*x^8)/4 - 6900*x^9 - 2700*x^10}
{(1 - 2*x)^3*(2 + 3*x)^2*(3 + 5*x)^3, x, 2, 108*x + 108*x^2 - 375*x^3 - (2659*x^4)/4 + (3279*x^5)/5 + (3617*x^6)/2 + (230*x^7)/7 - (3675*x^8)/2 - 1000*x^9}
{(1 - 2*x)^3*(2 + 3*x)*(3 + 5*x)^3, x, 2, 54*x + (27*x^2)/2 - 201*x^3 - (425*x^4)/4 + (2277*x^5)/5 + 335*x^6 - (2900*x^7)/7 - 375*x^8}
{(1 - 2*x)^3*(3 + 5*x)^3, x, 2, 27*x - (27*x^2)/2 - 87*x^3 + (179*x^4)/4 + 174*x^5 - 50*x^6 - (1000*x^7)/7}
{((1 - 2*x)^3*(3 + 5*x)^3)/(2 + 3*x), x, 2, (10013*x)/729 - (8287*x^2)/486 - (6427*x^3)/243 + (2815*x^4)/54 + (220*x^5)/9 - (500*x^6)/9 - (343*Log[2 + 3*x])/2187}
{((1 - 2*x)^3*(3 + 5*x)^3)/(2 + 3*x)^2, x, 2, (2287*x)/729 - (5287*x^2)/486 - (190*x^3)/81 + (775*x^4)/27 - (200*x^5)/9 + 343/(2187*(2 + 3*x)) + (1813*Log[2 + 3*x])/729}
{((1 - 2*x)^3*(3 + 5*x)^3)/(2 + 3*x)^3, x, 2, (16253*x)/729 - (1795*x^2)/81 + (1700*x^3)/81 - (250*x^4)/27 + 343/(4374*(2 + 3*x)^2) - 1813/(729*(2 + 3*x)) - (10073*Log[2 + 3*x])/729}
{((1 - 2*x)^3*(3 + 5*x)^3)/(2 + 3*x)^4, x, 2, (-24970*x)/729 + (3550*x^2)/243 - (1000*x^3)/243 + 343/(6561*(2 + 3*x)^3) - 1813/(1458*(2 + 3*x)^2) + 10073/(729*(2 + 3*x)) + (66193*Log[2 + 3*x])/2187}
{((1 - 2*x)^3*(3 + 5*x)^3)/(2 + 3*x)^5, x, 2, (9100*x)/729 - (500*x^2)/243 + 343/(8748*(2 + 3*x)^4) - 1813/(2187*(2 + 3*x)^3) + 10073/(1458*(2 + 3*x)^2) - 66193/(2187*(2 + 3*x)) - (14390*Log[2 + 3*x])/729}
{((1 - 2*x)^3*(3 + 5*x)^3)/(2 + 3*x)^6, x, 2, (-1000*x)/729 + 343/(10935*(2 + 3*x)^5) - 1813/(2916*(2 + 3*x)^4) + 10073/(2187*(2 + 3*x)^3) - 66193/(4374*(2 + 3*x)^2) + 14390/(729*(2 + 3*x)) + (3700*Log[2 + 3*x])/729}
{((1 - 2*x)^3*(3 + 5*x)^3)/(2 + 3*x)^7, x, 2, 343/(13122*(2 + 3*x)^6) - 1813/(3645*(2 + 3*x)^5) + 10073/(2916*(2 + 3*x)^4) - 66193/(6561*(2 + 3*x)^3) + 7195/(729*(2 + 3*x)^2) - 3700/(729*(2 + 3*x)) - (1000*Log[2 + 3*x])/2187}
{((1 - 2*x)^3*(3 + 5*x)^3)/(2 + 3*x)^8, x, 2, 49/(2187*(2 + 3*x)^7) - 1813/(4374*(2 + 3*x)^6) + 10073/(3645*(2 + 3*x)^5) - 66193/(8748*(2 + 3*x)^4) + 14390/(2187*(2 + 3*x)^3) - 1850/(729*(2 + 3*x)^2) + 1000/(2187*(2 + 3*x))}


(* ::Subsubsection::Closed:: *)
(*n<0*)


{((1 - 2*x)^3*(2 + 3*x)^6)/(3 + 5*x), x, 2, (41666223*x)/1953125 + (11111259*x^2)/781250 - (17453753*x^3)/234375 - (5848749*x^4)/62500 + (2212083*x^5)/15625 + (331713*x^6)/1250 - (40338*x^7)/875 - (13851*x^8)/50 - (648*x^9)/5 + (1331*Log[3 + 5*x])/9765625}
{((1 - 2*x)^3*(2 + 3*x)^5)/(3 + 5*x), x, 2, (4166223*x)/390625 - (138741*x^2)/156250 - (1703753*x^3)/46875 - (73749*x^4)/12500 + (243333*x^5)/3125 + (4419*x^6)/125 - (11988*x^7)/175 - (243*x^8)/5 + (1331*Log[3 + 5*x])/1953125}
{((1 - 2*x)^3*(2 + 3*x)^4)/(3 + 5*x), x, 2, (416223*x)/78125 - (138741*x^2)/31250 - (128753*x^3)/9375 + (31251*x^4)/2500 + (14958*x^5)/625 - (306*x^6)/25 - (648*x^7)/35 + (1331*Log[3 + 5*x])/390625}
{((1 - 2*x)^3*(2 + 3*x)^3)/(3 + 5*x), x, 2, (41223*x)/15625 - (26241*x^2)/6250 - (5003*x^3)/1875 + (2313*x^4)/250 + (108*x^5)/125 - (36*x^6)/5 + (1331*Log[3 + 5*x])/78125}
{((1 - 2*x)^3*(2 + 3*x)^2)/(3 + 5*x), x, 2, (3723*x)/3125 - (3741*x^2)/1250 + (622*x^3)/375 + (69*x^4)/25 - (72*x^5)/25 + (1331*Log[3 + 5*x])/15625}
{((1 - 2*x)^3*(2 + 3*x)^1)/(3 + 5*x), x, 2, -((27*x)/625) - (183*x^2)/125 + (172*x^3)/75 - (6*x^4)/5 + (1331*Log[3 + 5*x])/3125}
{(1 - 2*x)^3/(3 + 5*x), x, 2, -((402*x)/125) + (42*x^2)/25 - (8*x^3)/15 + (1331/625)*Log[3 + 5*x]}
{(1 - 2*x)^3/((2 + 3*x)*(3 + 5*x)), x, 2, (332*x)/225 - (4*x^2)/15 - (343*Log[2 + 3*x])/27 + (1331*Log[3 + 5*x])/125}
{(1 - 2*x)^3/((2 + 3*x)^2*(3 + 5*x)), x, 2, (-8*x)/45 + 343/(27*(2 + 3*x)) - (1421*Log[2 + 3*x])/27 + (1331*Log[3 + 5*x])/25}
{(1 - 2*x)^3/((2 + 3*x)^3*(3 + 5*x)), x, 2, 343/(54*(2 + 3*x)^2) + 1421/(27*(2 + 3*x)) - (7189*Log[2 + 3*x])/27 + (1331*Log[3 + 5*x])/5}
{(1 - 2*x)^3/((2 + 3*x)^4*(3 + 5*x)), x, 2, 343/(81*(2 + 3*x)^3) + 1421/(54*(2 + 3*x)^2) + 7189/(27*(2 + 3*x)) - 1331*Log[2 + 3*x] + 1331*Log[3 + 5*x]}
{(1 - 2*x)^3/((2 + 3*x)^5*(3 + 5*x)), x, 2, 343/(108*(2 + 3*x)^4) + 1421/(81*(2 + 3*x)^3) + 7189/(54*(2 + 3*x)^2) + 1331/(2 + 3*x) - 6655*Log[2 + 3*x] + 6655*Log[3 + 5*x]}
{(1 - 2*x)^3/((2 + 3*x)^6*(3 + 5*x)), x, 2, 343/(135*(2 + 3*x)^5) + 1421/(108*(2 + 3*x)^4) + 7189/(81*(2 + 3*x)^3) + 1331/(2*(2 + 3*x)^2) + 6655/(2 + 3*x) - 33275*Log[2 + 3*x] + 33275*Log[3 + 5*x]}
{(1 - 2*x)^3/((2 + 3*x)^7*(3 + 5*x)), x, 2, 343/(162*(2 + 3*x)^6) + 1421/(135*(2 + 3*x)^5) + 7189/(108*(2 + 3*x)^4) + 1331/(3*(2 + 3*x)^3) + 6655/(2*(2 + 3*x)^2) + 33275/(2 + 3*x) - 166375*Log[2 + 3*x] + 166375*Log[3 + 5*x]}
{(1 - 2*x)^3/((2 + 3*x)^8*(3 + 5*x)), x, 2, 49/(27*(2 + 3*x)^7) + 1421/(162*(2 + 3*x)^6) + 7189/(135*(2 + 3*x)^5) + 1331/(4*(2 + 3*x)^4) + 6655/(3*(2 + 3*x)^3) + 33275/(2*(2 + 3*x)^2) + 166375/(2 + 3*x) - 831875*Log[2 + 3*x] + 831875*Log[3 + 5*x]}


{((1 - 2*x)^3*(2 + 3*x)^6)/(3 + 5*x)^2, x, 2, (13880997*x)/1953125 - (461623*x^2)/390625 - (1836723*x^3)/78125 - (5643*x^4)/3125 + (774981*x^5)/15625 + (12231*x^6)/625 - (37908*x^7)/875 - (729*x^8)/25 - 1331/(9765625*(3 + 5*x)) + (23232*Log[3 + 5*x])/9765625}
{((1 - 2*x)^3*(2 + 3*x)^5)/(3 + 5*x)^2, x, 2, (1382328*x)/390625 - (507023*x^2)/156250 - (26594*x^3)/3125 + (108387*x^4)/12500 + (44982*x^5)/3125 - (1026*x^6)/125 - (1944*x^7)/175 - 1331/(1953125*(3 + 5*x)) + (19239*Log[3 + 5*x])/1953125}
{((1 - 2*x)^3*(2 + 3*x)^4)/(3 + 5*x)^2, x, 2, (133659*x)/78125 - (1816*x^2)/625 - (4217*x^3)/3125 + (7317*x^4)/1250 + (108*x^5)/625 - (108*x^6)/25 - 1331/(390625*(3 + 5*x)) + (15246*Log[3 + 5*x])/390625}
{((1 - 2*x)^3*(2 + 3*x)^3)/(3 + 5*x)^2, x, 2, (1998*x)/3125 - (12077*x^2)/6250 + (786*x^3)/625 + (189*x^4)/125 - (216*x^5)/125 - 1331/(78125*(3 + 5*x)) + (11253*Log[3 + 5*x])/78125}
{((1 - 2*x)^3*(2 + 3*x)^2)/(3 + 5*x)^2, x, 2, (-1179*x)/3125 - (427*x^2)/625 + (164*x^3)/125 - (18*x^4)/25 - 1331/(15625*(3 + 5*x)) + (1452*Log[3 + 5*x])/3125}
{((1 - 2*x)^3*(2 + 3*x))/(3 + 5*x)^2, x, 2, (-1098*x)/625 + (122*x^2)/125 - (8*x^3)/25 - 1331/(3125*(3 + 5*x)) + (3267*Log[3 + 5*x])/3125}
{(1 - 2*x)^3/(3 + 5*x)^2, x, 2, (108*x)/125 - (4*x^2)/25 - 1331/(625*(3 + 5*x)) - (726*Log[3 + 5*x])/625}
{(1 - 2*x)^3/((2 + 3*x)*(3 + 5*x)^2), x, 2, (-8*x)/75 - 1331/(125*(3 + 5*x)) + (343*Log[2 + 3*x])/9 - (4719*Log[3 + 5*x])/125}
{(1 - 2*x)^3/((2 + 3*x)^2*(3 + 5*x)^2), x, 2, -343/(9*(2 + 3*x)) - 1331/(25*(3 + 5*x)) + (3136*Log[2 + 3*x])/9 - (8712*Log[3 + 5*x])/25}
{(1 - 2*x)^3/((2 + 3*x)^3*(3 + 5*x)^2), x, 2, -343/(18*(2 + 3*x)^2) - 3136/(9*(2 + 3*x)) - 1331/(5*(3 + 5*x)) + 2541*Log[2 + 3*x] - 2541*Log[3 + 5*x]}
{(1 - 2*x)^3/((2 + 3*x)^4*(3 + 5*x)^2), x, 2, -343/(27*(2 + 3*x)^3) - 1568/(9*(2 + 3*x)^2) - 2541/(2 + 3*x) - 1331/(3 + 5*x) + 16698*Log[2 + 3*x] - 16698*Log[3 + 5*x]}
{(1 - 2*x)^3/((2 + 3*x)^5*(3 + 5*x)^2), x, 2, -343/(36*(2 + 3*x)^4) - 3136/(27*(2 + 3*x)^3) - 2541/(2*(2 + 3*x)^2) - 16698/(2 + 3*x) - 6655/(3 + 5*x) + 103455*Log[2 + 3*x] - 103455*Log[3 + 5*x]}
{(1 - 2*x)^3/((2 + 3*x)^6*(3 + 5*x)^2), x, 2, -343/(45*(2 + 3*x)^5) - 784/(9*(2 + 3*x)^4) - 847/(2 + 3*x)^3 - 8349/(2 + 3*x)^2 - 103455/(2 + 3*x) - 33275/(3 + 5*x) + 617100*Log[2 + 3*x] - 617100*Log[3 + 5*x]}
{(1 - 2*x)^3/((2 + 3*x)^7*(3 + 5*x)^2), x, 2, -343/(54*(2 + 3*x)^6) - 3136/(45*(2 + 3*x)^5) - 2541/(4*(2 + 3*x)^4) - 5566/(2 + 3*x)^3 - 103455/(2*(2 + 3*x)^2) - 617100/(2 + 3*x) - 166375/(3 + 5*x) + 3584625*Log[2 + 3*x] - 3584625*Log[3 + 5*x]}
{(1 - 2*x)^3/((2 + 3*x)^8*(3 + 5*x)^2), x, 2, -49/(9*(2 + 3*x)^7) - 1568/(27*(2 + 3*x)^6) - 2541/(5*(2 + 3*x)^5) - 8349/(2*(2 + 3*x)^4) - 34485/(2 + 3*x)^3 - 308550/(2 + 3*x)^2 - 3584625/(2 + 3*x) - 831875/(3 + 5*x) + 20418750*Log[2 + 3*x] - 20418750*Log[3 + 5*x]}


{((1 - 2*x)^3*(2 + 3*x)^7)/(3 + 5*x)^3, x, 2, (46214407*x)/9765625 - (2300646*x^2)/1953125 - (5918904*x^3)/390625 + (6507*x^4)/62500 + (491913*x^5)/15625 + (33291*x^6)/3125 - (119556*x^7)/4375 - (2187*x^8)/125 - 1331/(97656250*(3 + 5*x)^2) - 1089/(1953125*(3 + 5*x)) + (47289*Log[3 + 5*x])/9765625}
{((1 - 2*x)^3*(2 + 3*x)^6)/(3 + 5*x)^3, x, 2, (4571416*x)/1953125 - (915777*x^2)/390625 - (81747*x^3)/15625 + (74223*x^4)/12500 + (134622*x^5)/15625 - (3402*x^6)/625 - (5832*x^7)/875 - 1331/(19531250*(3 + 5*x)^2) - 23232/(9765625*(3 + 5*x)) + (166749*Log[3 + 5*x])/9765625}
{((1 - 2*x)^3*(2 + 3*x)^5)/(3 + 5*x)^3, x, 2, (424432*x)/390625 - (62097*x^2)/31250 - (393*x^3)/625 + (22977*x^4)/6250 - (324*x^5)/3125 - (324*x^6)/125 - 1331/(3906250*(3 + 5*x)^2) - 19239/(1953125*(3 + 5*x)) + (109032*Log[3 + 5*x])/1953125}
{((1 - 2*x)^3*(2 + 3*x)^4)/(3 + 5*x)^3, x, 2, (4691*x)/15625 - (7617*x^2)/6250 + (2826*x^3)/3125 + (513*x^4)/625 - (648*x^5)/625 - 1331/(781250*(3 + 5*x)^2) - 15246/(390625*(3 + 5*x)) + (63294*Log[3 + 5*x])/390625}
{((1 - 2*x)^3*(2 + 3*x)^3)/(3 + 5*x)^3, x, 2, (-1303*x)/3125 - (927*x^2)/3125 + (468*x^3)/625 - (54*x^4)/125 - 1331/(156250*(3 + 5*x)^2) - 11253/(78125*(3 + 5*x)) + (5907*Log[3 + 5*x])/15625}
{((1 - 2*x)^3*(2 + 3*x)^2)/(3 + 5*x)^3, x, 2, (-2978*x)/3125 + (354*x^2)/625 - (24*x^3)/125 - 1331/(31250*(3 + 5*x)^2) - 1452/(3125*(3 + 5*x)) + (1551*Log[3 + 5*x])/3125}
{((1 - 2*x)^3*(2 + 3*x))/(3 + 5*x)^3, x, 2, (316*x)/625 - (12*x^2)/125 - 1331/(6250*(3 + 5*x)^2) - 3267/(3125*(3 + 5*x)) - (2046*Log[3 + 5*x])/3125}
{(1 - 2*x)^3/(3 + 5*x)^3, x, 2, (-8*x)/125 - 1331/(1250*(3 + 5*x)^2) + 726/(625*(3 + 5*x)) + (132*Log[3 + 5*x])/625}
{(1 - 2*x)^3/((2 + 3*x)*(3 + 5*x)^3), x, 2, -1331/(250*(3 + 5*x)^2) + 4719/(125*(3 + 5*x)) - (343*Log[2 + 3*x])/3 + (14289*Log[3 + 5*x])/125}
{(1 - 2*x)^3/((2 + 3*x)^2*(3 + 5*x)^3), x, 2, 343/(3*(2 + 3*x)) - 1331/(50*(3 + 5*x)^2) + 8712/(25*(3 + 5*x)) - 1617*Log[2 + 3*x] + 1617*Log[3 + 5*x]}
{(1 - 2*x)^3/((2 + 3*x)^3*(3 + 5*x)^3), x, 2, 343/(6*(2 + 3*x)^2) + 1617/(2 + 3*x) - 1331/(10*(3 + 5*x)^2) + 2541/(3 + 5*x) - 15708*Log[2 + 3*x] + 15708*Log[3 + 5*x]}
{(1 - 2*x)^3/((2 + 3*x)^4*(3 + 5*x)^3), x, 2, 343/(9*(2 + 3*x)^3) + 1617/(2*(2 + 3*x)^2) + 15708/(2 + 3*x) - 1331/(2*(3 + 5*x)^2) + 16698/(3 + 5*x) - 128634*Log[2 + 3*x] + 128634*Log[3 + 5*x]}
{(1 - 2*x)^3/((2 + 3*x)^5*(3 + 5*x)^3), x, 2, 343/(12*(2 + 3*x)^4) + 539/(2 + 3*x)^3 + 7854/(2 + 3*x)^2 + 128634/(2 + 3*x) - 6655/(2*(3 + 5*x)^2) + 103455/(3 + 5*x) - 953535*Log[2 + 3*x] + 953535*Log[3 + 5*x]}
{(1 - 2*x)^3/((2 + 3*x)^6*(3 + 5*x)^3), x, 2, 343/(15*(2 + 3*x)^5) + 1617/(4*(2 + 3*x)^4) + 5236/(2 + 3*x)^3 + 64317/(2 + 3*x)^2 + 953535/(2 + 3*x) - 33275/(2*(3 + 5*x)^2) + 617100/(3 + 5*x) - 6618975*Log[2 + 3*x] + 6618975*Log[3 + 5*x]}
{(1 - 2*x)^3/((2 + 3*x)^7*(3 + 5*x)^3), x, 2, 343/(18*(2 + 3*x)^6) + 1617/(5*(2 + 3*x)^5) + 3927/(2 + 3*x)^4 + 42878/(2 + 3*x)^3 + 953535/(2*(2 + 3*x)^2) + 6618975/(2 + 3*x) - 166375/(2*(3 + 5*x)^2) + 3584625/(3 + 5*x) - 43848750*Log[2 + 3*x] + 43848750*Log[3 + 5*x]}
{(1 - 2*x)^3/((2 + 3*x)^8*(3 + 5*x)^3), x, 2, 49/(3*(2 + 3*x)^7) + 539/(2*(2 + 3*x)^6) + 15708/(5*(2 + 3*x)^5) + 64317/(2*(2 + 3*x)^4) + 317845/(2 + 3*x)^3 + 6618975/(2*(2 + 3*x)^2) + 43848750/(2 + 3*x) - 831875/(2*(3 + 5*x)^2) + 20418750/(3 + 5*x) - 280500000*Log[2 + 3*x] + 280500000*Log[3 + 5*x]}


(* ::Subsection::Closed:: *)
(*Integrands of the form (a+b x)^m (c+d x)^n / (e+f x)^1*)


(* ::Subsubsection::Closed:: *)
(*n>0*)


{((2 + 3*x)^m*(3 + 5*x))/(1 - 2*x), x, 2, -((5*(2 + 3*x)^(1 + m))/(6*(1 + m))) + (11*(2 + 3*x)^(1 + m)*Hypergeometric2F1[1, 1 + m, 2 + m, (2/7)*(2 + 3*x)])/(14*(1 + m))}

{((2 + 3*x)^8*(3 + 5*x))/(1 - 2*x), x, 2, -((63019595*x)/512) - (60332619*x^2)/512 - (17391129*x^3)/128 - (37722699*x^4)/256 - (21272139*x^5)/160 - (2929689*x^6)/32 - (353565*x^7)/8 - (422091*x^8)/32 - (3645*x^9)/2 - (63412811*Log[1 - 2*x])/1024}
{((2 + 3*x)^7*(3 + 5*x))/(1 - 2*x), x, 2, -((8960669*x)/256) - (8362653*x^2)/256 - (2257119*x^3)/64 - (4352157*x^4)/128 - (2053917*x^5)/80 - (218943*x^6)/16 - (126117*x^7)/28 - (10935*x^8)/16 - (9058973/512)*Log[1 - 2*x]}
{((2 + 3*x)^6*(3 + 5*x))/(1 - 2*x), x, 2, -((1269563*x)/128) - (1138491*x^2)/128 - (279657*x^3)/32 - (458811*x^4)/64 - (169371*x^5)/40 - (12393*x^6)/8 - (3645*x^7)/14 - (1294139/256)*Log[1 - 2*x]}
{((2 + 3*x)^5*(3 + 5*x))/(1 - 2*x), x, 2, -((178733*x)/64) - (150573*x^2)/64 - (32271*x^3)/16 - (42093*x^4)/32 - (10773*x^5)/20 - (405*x^6)/4 - (184877/128)*Log[1 - 2*x]}
{((2 + 3*x)^4*(3 + 5*x))/(1 - 2*x), x, 2, -((24875*x)/32) - (18987*x^2)/32 - (3321*x^3)/8 - (3051*x^4)/16 - (81*x^5)/2 - (26411/64)*Log[1 - 2*x]}
{((2 + 3*x)^3*(3 + 5*x))/(1 - 2*x), x, 2, -((3389*x)/16) - (2205*x^2)/16 - (279*x^3)/4 - (135*x^4)/8 - (3773/32)*Log[1 - 2*x]}
{((2 + 3*x)^2*(3 + 5*x))/(1 - 2*x), x, 2, -((443*x)/8) - (219*x^2)/8 - (15*x^3)/2 - (539/16)*Log[1 - 2*x]}
{((2 + 3*x)^1*(3 + 5*x))/(1 - 2*x), x, 2, -((53*x)/4) - (15*x^2)/4 - (77/8)*Log[1 - 2*x]}
{(3 + 5*x)/(1 - 2*x), x, 2, (-5*x)/2 - (11*Log[1 - 2*x])/4}
{(3 + 5*x)/((1 - 2*x)*(2 + 3*x)), x, 2, (-11*Log[1 - 2*x])/14 - Log[2 + 3*x]/21}
{(3 + 5*x)/((1 - 2*x)*(2 + 3*x)^2), x, 2, 1/(21*(2 + 3*x)) - (11*Log[1 - 2*x])/49 + (11*Log[2 + 3*x])/49}
{(3 + 5*x)/((1 - 2*x)*(2 + 3*x)^3), x, 2, 1/(42*(2 + 3*x)^2) - 11/(49*(2 + 3*x)) - (22*Log[1 - 2*x])/343 + (22*Log[2 + 3*x])/343}
{(3 + 5*x)/((1 - 2*x)*(2 + 3*x)^4), x, 2, 1/(63*(2 + 3*x)^3) - 11/(98*(2 + 3*x)^2) - 22/(343*(2 + 3*x)) - (44*Log[1 - 2*x])/2401 + (44*Log[2 + 3*x])/2401}
{(3 + 5*x)/((1 - 2*x)*(2 + 3*x)^5), x, 2, 1/(84*(2 + 3*x)^4) - 11/(147*(2 + 3*x)^3) - 11/(343*(2 + 3*x)^2) - 44/(2401*(2 + 3*x)) - (88*Log[1 - 2*x])/16807 + (88*Log[2 + 3*x])/16807}
{(3 + 5*x)/((1 - 2*x)*(2 + 3*x)^6), x, 2, 1/(105*(2 + 3*x)^5) - 11/(196*(2 + 3*x)^4) - 22/(1029*(2 + 3*x)^3) - 22/(2401*(2 + 3*x)^2) - 88/(16807*(2 + 3*x)) - (176*Log[1 - 2*x])/117649 + (176*Log[2 + 3*x])/117649}
{(3 + 5*x)/((1 - 2*x)*(2 + 3*x)^7), x, 2, 1/(126*(2 + 3*x)^6) - 11/(245*(2 + 3*x)^5) - 11/(686*(2 + 3*x)^4) - 44/(7203*(2 + 3*x)^3) - 44/(16807*(2 + 3*x)^2) - 176/(117649*(2 + 3*x)) - (352*Log[1 - 2*x])/823543 + (352*Log[2 + 3*x])/823543}
{(3 + 5*x)/((1 - 2*x)*(2 + 3*x)^8), x, 2, 1/(147*(2 + 3*x)^7) - 11/(294*(2 + 3*x)^6) - 22/(1715*(2 + 3*x)^5) - 11/(2401*(2 + 3*x)^4) - 88/(50421*(2 + 3*x)^3) - 88/(117649*(2 + 3*x)^2) - 352/(823543*(2 + 3*x)) - (704*Log[1 - 2*x])/5764801 + (704*Log[2 + 3*x])/5764801}


{((2 + 3*x)^m*(3 + 5*x)^2)/(1 - 2*x), x, 3, -((5*(64 + 33*m)*(2 + 3*x)^(1 + m))/(36*(1 + m)*(2 + m))) - (5*(2 + 3*x)^(1 + m)*(3 + 5*x))/(6*(2 + m)) + (121*(2 + 3*x)^(1 + m)*Hypergeometric2F1[1, 1 + m, 2 + m, (2/7)*(2 + 3*x)])/(28*(1 + m))}

{((2 + 3*x)^8*(3 + 5*x)^2)/(1 - 2*x), x, 2, (-695181625*x)/1024 - (677093689*x^2)/1024 - (204901139*x^3)/256 - (487203129*x^4)/512 - (316246329*x^5)/320 - (53031699*x^6)/64 - (8399295*x^7)/16 - (14907321*x^8)/64 - (256365*x^9)/4 - (32805*x^10)/4 - (697540921*Log[1 - 2*x])/2048}
{((2 + 3*x)^7*(3 + 5*x)^2)/(1 - 2*x), x, 2, (-99058879*x)/512 - (94979263*x^2)/512 - (27480469*x^3)/128 - (59969727*x^4)/256 - (34084287*x^5)/160 - (4736853*x^6)/32 - (4040847*x^7)/56 - (696195*x^8)/32 - (6075*x^9)/2 - (99648703*Log[1 - 2*x])/1024}
{((2 + 3*x)^6*(3 + 5*x)^2)/(1 - 2*x), x, 2, (-14088073*x)/256 - (13178761*x^2)/256 - (3575427*x^3)/64 - (6947721*x^4)/128 - (3310281*x^5)/80 - (356643*x^6)/16 - (207765*x^7)/28 - (18225*x^8)/16 - (14235529*Log[1 - 2*x])/512}
{((2 + 3*x)^5*(3 + 5*x)^2)/(1 - 2*x), x, 2, (-1996783*x)/128 - (1797103*x^2)/128 - (444581*x^3)/32 - (736623*x^4)/64 - (275103*x^5)/40 - (20385*x^6)/8 - (6075*x^7)/14 - (2033647*Log[1 - 2*x])/256}
{((2 + 3*x)^4*(3 + 5*x)^2)/(1 - 2*x), x, 2, (-281305*x)/64 - (238297*x^2)/64 - (51571*x^3)/16 - (68121*x^4)/32 - (3537*x^5)/4 - (675*x^6)/4 - (290521*Log[1 - 2*x])/128}
{((2 + 3*x)^3*(3 + 5*x)^2)/(1 - 2*x), x, 2, (-39199*x)/32 - (30175*x^2)/32 - (5349*x^3)/8 - (4995*x^4)/16 - (135*x^5)/2 - (41503*Log[1 - 2*x])/64}
{((2 + 3*x)^2*(3 + 5*x)^2)/(1 - 2*x), x, 2, (-5353*x)/16 - (3529*x^2)/16 - (455*x^3)/4 - (225*x^4)/8 - (5929*Log[1 - 2*x])/32}
{((2 + 3*x)^1*(3 + 5*x)^2)/(1 - 2*x), x, 2, -((703*x)/8) - (355*x^2)/8 - (25*x^3)/2 - (847/16)*Log[1 - 2*x]}
{(3 + 5*x)^2/(1 - 2*x), x, 2, -((85*x)/4) - (25*x^2)/4 - (121/8)*Log[1 - 2*x]}
{(3 + 5*x)^2/((1 - 2*x)*(2 + 3*x)), x, 2, (-25*x)/6 - (121*Log[1 - 2*x])/28 + Log[2 + 3*x]/63}
{(3 + 5*x)^2/((1 - 2*x)*(2 + 3*x)^2), x, 2, -1/(63*(2 + 3*x)) - (121*Log[1 - 2*x])/98 - (68*Log[2 + 3*x])/441}
{(3 + 5*x)^2/((1 - 2*x)*(2 + 3*x)^3), x, 2, -1/(126*(2 + 3*x)^2) + 68/(441*(2 + 3*x)) - (121*Log[1 - 2*x])/343 + (121*Log[2 + 3*x])/343}
{(3 + 5*x)^2/((1 - 2*x)*(2 + 3*x)^4), x, 2, -1/(189*(2 + 3*x)^3) + 34/(441*(2 + 3*x)^2) - 121/(343*(2 + 3*x)) - (242*Log[1 - 2*x])/2401 + (242*Log[2 + 3*x])/2401}
{(3 + 5*x)^2/((1 - 2*x)*(2 + 3*x)^5), x, 2, -1/(252*(2 + 3*x)^4) + 68/(1323*(2 + 3*x)^3) - 121/(686*(2 + 3*x)^2) - 242/(2401*(2 + 3*x)) - (484*Log[1 - 2*x])/16807 + (484*Log[2 + 3*x])/16807}
{(3 + 5*x)^2/((1 - 2*x)*(2 + 3*x)^6), x, 2, -1/(315*(2 + 3*x)^5) + 17/(441*(2 + 3*x)^4) - 121/(1029*(2 + 3*x)^3) - 121/(2401*(2 + 3*x)^2) - 484/(16807*(2 + 3*x)) - (968*Log[1 - 2*x])/117649 + (968*Log[2 + 3*x])/117649}
{(3 + 5*x)^2/((1 - 2*x)*(2 + 3*x)^7), x, 2, -1/(378*(2 + 3*x)^6) + 68/(2205*(2 + 3*x)^5) - 121/(1372*(2 + 3*x)^4) - 242/(7203*(2 + 3*x)^3) - 242/(16807*(2 + 3*x)^2) - 968/(117649*(2 + 3*x)) - (1936*Log[1 - 2*x])/823543 + (1936*Log[2 + 3*x])/823543}
{(3 + 5*x)^2/((1 - 2*x)*(2 + 3*x)^8), x, 2, -1/(441*(2 + 3*x)^7) + 34/(1323*(2 + 3*x)^6) - 121/(1715*(2 + 3*x)^5) - 121/(4802*(2 + 3*x)^4) - 484/(50421*(2 + 3*x)^3) - 484/(117649*(2 + 3*x)^2) - 1936/(823543*(2 + 3*x)) - (3872*Log[1 - 2*x])/5764801 + (3872*Log[2 + 3*x])/5764801}


{((2 + 3*x)^m*(3 + 5*x)^3)/(1 - 2*x), x, 7, -((5135*(2 + 3*x)^(1 + m))/(216*(1 + m))) - (725*(2 + 3*x)^(2 + m))/(108*(2 + m)) - (125*(2 + 3*x)^(3 + m))/(54*(3 + m)) + (1331*(2 + 3*x)^(1 + m)*Hypergeometric2F1[1, 1 + m, 2 + m, (2/7)*(2 + 3*x)])/(56*(1 + m))}

{((2 + 3*x)^7*(3 + 5*x)^3)/(1 - 2*x), x, 2, (-1092596789*x)/1024 - (1065169973*x^2)/1024 - (969544757*x^3)/768 - (772025397*x^4)/512 - (504354357*x^5)/320 - (85228263*x^6)/64 - (95297877*x^7)/112 - (24381405*x^8)/64 - (423225*x^9)/4 - (54675*x^10)/4 - (1096135733*Log[1 - 2*x])/2048}
{((2 + 3*x)^6*(3 + 5*x)^3)/(1 - 2*x), x, 2, (-155706083*x)/512 - (149512931*x^2)/512 - (130251491*x^3)/384 - (95317731*x^4)/256 - (54600291*x^5)/160 - (7656993*x^6)/32 - (6596235*x^7)/56 - (1148175*x^8)/32 - (10125*x^9)/2 - (156590819*Log[1 - 2*x])/1024}
{((2 + 3*x)^5*(3 + 5*x)^3)/(1 - 2*x), x, 2, (-22148933*x)/256 - (20766533*x^2)/256 - (16987973*x^3)/192 - (11088453*x^4)/128 - (5333733*x^5)/80 - (580815*x^6)/16 - (342225*x^7)/28 - (30375*x^8)/16 - (22370117*Log[1 - 2*x])/512}
{((2 + 3*x)^4*(3 + 5*x)^3)/(1 - 2*x), x, 2, (-3140435*x)/128 - (2836307*x^2)/128 - (2119763*x^3)/96 - (1182291*x^4)/64 - (89343*x^5)/8 - (33525*x^6)/8 - (10125*x^7)/14 - (3195731*Log[1 - 2*x])/256}
{((2 + 3*x)^3*(3 + 5*x)^3)/(1 - 2*x), x, 2, (-442709*x)/64 - (377045*x^2)/64 - (247157*x^3)/48 - (110205*x^4)/32 - (5805*x^5)/4 - (1125*x^6)/4 - (456533*Log[1 - 2*x])/128}
{((2 + 3*x)^2*(3 + 5*x)^3)/(1 - 2*x), x, 2, (-61763*x)/32 - (47939*x^2)/32 - (25835*x^3)/24 - (8175*x^4)/16 - (225*x^5)/2 - (65219*Log[1 - 2*x])/64}
{((2 + 3*x)^1*(3 + 5*x)^3)/(1 - 2*x), x, 2, -((8453*x)/16) - (5645*x^2)/16 - (2225*x^3)/12 - (375*x^4)/8 - (9317/32)*Log[1 - 2*x]}
{(3 + 5*x)^3/(1 - 2*x), x, 2, -((1115*x)/8) - (575*x^2)/8 - (125*x^3)/6 - (1331/16)*Log[1 - 2*x]}
{(3 + 5*x)^3/((1 - 2*x)*(2 + 3*x)), x, 2, (-1225*x)/36 - (125*x^2)/12 - (1331*Log[1 - 2*x])/56 - Log[2 + 3*x]/189}
{(3 + 5*x)^3/((1 - 2*x)*(2 + 3*x)^2), x, 2, (-125*x)/18 + 1/(189*(2 + 3*x)) - (1331*Log[1 - 2*x])/196 + (103*Log[2 + 3*x])/1323}
{(3 + 5*x)^3/((1 - 2*x)*(2 + 3*x)^3), x, 2, 1/(378*(2 + 3*x)^2) - 103/(1323*(2 + 3*x)) - (1331*Log[1 - 2*x])/686 - (3469*Log[2 + 3*x])/9261}
{(3 + 5*x)^3/((1 - 2*x)*(2 + 3*x)^4), x, 2, 1/(567*(2 + 3*x)^3) - 103/(2646*(2 + 3*x)^2) + 3469/(9261*(2 + 3*x)) - (1331*Log[1 - 2*x])/2401 + (1331*Log[2 + 3*x])/2401}
{(3 + 5*x)^3/((1 - 2*x)*(2 + 3*x)^5), x, 2, 1/(756*(2 + 3*x)^4) - 103/(3969*(2 + 3*x)^3) + 3469/(18522*(2 + 3*x)^2) - 1331/(2401*(2 + 3*x)) - (2662*Log[1 - 2*x])/16807 + (2662*Log[2 + 3*x])/16807}
{(3 + 5*x)^3/((1 - 2*x)*(2 + 3*x)^6), x, 2, 1/(945*(2 + 3*x)^5) - 103/(5292*(2 + 3*x)^4) + 3469/(27783*(2 + 3*x)^3) - 1331/(4802*(2 + 3*x)^2) - 2662/(16807*(2 + 3*x)) - (5324*Log[1 - 2*x])/117649 + (5324*Log[2 + 3*x])/117649}
{(3 + 5*x)^3/((1 - 2*x)*(2 + 3*x)^7), x, 2, 1/(1134*(2 + 3*x)^6) - 103/(6615*(2 + 3*x)^5) + 3469/(37044*(2 + 3*x)^4) - 1331/(7203*(2 + 3*x)^3) - 1331/(16807*(2 + 3*x)^2) - 5324/(117649*(2 + 3*x)) - (10648*Log[1 - 2*x])/823543 + (10648*Log[2 + 3*x])/823543}
{(3 + 5*x)^3/((1 - 2*x)*(2 + 3*x)^8), x, 2, 1/(1323*(2 + 3*x)^7) - 103/(7938*(2 + 3*x)^6) + 3469/(46305*(2 + 3*x)^5) - 1331/(9604*(2 + 3*x)^4) - 2662/(50421*(2 + 3*x)^3) - 2662/(117649*(2 + 3*x)^2) - 10648/(823543*(2 + 3*x)) - (21296*Log[1 - 2*x])/5764801 + (21296*Log[2 + 3*x])/5764801}


(* ::Subsubsection::Closed:: *)
(*n<0*)


{(a + b*x)^3/((c + d*x)*(e + f*x)), x, 2, -((b^2*(b*d*e + b*c*f - 3*a*d*f)*x)/(d^2*f^2)) + (b^3*x^2)/(2*d*f) - ((b*c - a*d)^3*Log[c + d*x])/(d^3*(d*e - c*f)) + ((b*e - a*f)^3*Log[e + f*x])/(f^3*(d*e - c*f))}


{(2 + 3*x)^m/((1 - 2*x)*(3 + 5*x)), x, 3, (2*(2 + 3*x)^(1 + m)*Hypergeometric2F1[1, 1 + m, 2 + m, (2/7)*(2 + 3*x)])/(77*(1 + m)) - (5*(2 + 3*x)^(1 + m)*Hypergeometric2F1[1, 1 + m, 2 + m, 5*(2 + 3*x)])/(11*(1 + m))}

{(2 + 3*x)^8/((1 - 2*x)*(3 + 5*x)), x, 2, (-40089855591*x)/10000000 - (7136193339*x^2)/2000000 - (345533877*x^3)/100000 - (111146499*x^4)/40000 - (8018271*x^5)/5000 - (114453*x^6)/200 - (6561*x^7)/70 - (5764801*Log[1 - 2*x])/2816 + Log[3 + 5*x]/4296875}
{(2 + 3*x)^7/((1 - 2*x)*(3 + 5*x)), x, 2, (-1127138733*x)/1000000 - (187738857*x^2)/200000 - (7889751*x^3)/10000 - (2006937*x^4)/4000 - (99873*x^5)/500 - (729*x^6)/20 - (823543*Log[1 - 2*x])/1408 + Log[3 + 5*x]/859375}
{(2 + 3*x)^6/((1 - 2*x)*(3 + 5*x)), x, 2, (-31289679*x)/100000 - (4693491*x^2)/20000 - (159813*x^3)/1000 - (28431*x^4)/400 - (729*x^5)/50 - (117649*Log[1 - 2*x])/704 + Log[3 + 5*x]/171875}
{(2 + 3*x)^5/((1 - 2*x)*(3 + 5*x)), x, 2, (-848277*x)/10000 - (107433*x^2)/2000 - (2619*x^3)/100 - (243*x^4)/40 - (16807*Log[1 - 2*x])/352 + Log[3 + 5*x]/34375}
{(2 + 3*x)^4/((1 - 2*x)*(3 + 5*x)), x, 2, (-21951*x)/1000 - (2079*x^2)/200 - (27*x^3)/10 - (2401*Log[1 - 2*x])/176 + Log[3 + 5*x]/6875}
{(2 + 3*x)^3/((1 - 2*x)*(3 + 5*x)), x, 2, (-513*x)/100 - (27*x^2)/20 - (343*Log[1 - 2*x])/88 + Log[3 + 5*x]/1375}
{(2 + 3*x)^2/((1 - 2*x)*(3 + 5*x)), x, 2, (-9*x)/10 - (49*Log[1 - 2*x])/44 + Log[3 + 5*x]/275}
{(2 + 3*x)/((1 - 2*x)*(3 + 5*x)), x, 2, (-7*Log[1 - 2*x])/22 + Log[3 + 5*x]/55}
{1/((1 - 2*x)*(3 + 5*x)), x, 2, (-(1/11))*Log[1 - 2*x] + (1/11)*Log[3 + 5*x]}
{1/((1 - 2*x)*(2 + 3*x)*(3 + 5*x)), x, 2, (-2*Log[1 - 2*x])/77 - (3*Log[2 + 3*x])/7 + (5*Log[3 + 5*x])/11}
{1/((1 - 2*x)*(2 + 3*x)^2*(3 + 5*x)), x, 2, 3/(7*(2 + 3*x)) - (4*Log[1 - 2*x])/539 - (111*Log[2 + 3*x])/49 + (25*Log[3 + 5*x])/11}
{1/((1 - 2*x)*(2 + 3*x)^3*(3 + 5*x)), x, 2, 3/(14*(2 + 3*x)^2) + 111/(49*(2 + 3*x)) - (8*Log[1 - 2*x])/3773 - (3897*Log[2 + 3*x])/343 + (125*Log[3 + 5*x])/11}
{1/((1 - 2*x)*(2 + 3*x)^4*(3 + 5*x)), x, 2, 1/(7*(2 + 3*x)^3) + 111/(98*(2 + 3*x)^2) + 3897/(343*(2 + 3*x)) - (16*Log[1 - 2*x])/26411 - (136419*Log[2 + 3*x])/2401 + (625*Log[3 + 5*x])/11}
{1/((1 - 2*x)*(2 + 3*x)^5*(3 + 5*x)), x, 2, 3/(28*(2 + 3*x)^4) + 37/(49*(2 + 3*x)^3) + 3897/(686*(2 + 3*x)^2) + 136419/(2401*(2 + 3*x)) - (32*Log[1 - 2*x])/184877 - (4774713*Log[2 + 3*x])/16807 + (3125*Log[3 + 5*x])/11}
{1/((1 - 2*x)*(2 + 3*x)^6*(3 + 5*x)), x, 2, 3/(35*(2 + 3*x)^5) + 111/(196*(2 + 3*x)^4) + 1299/(343*(2 + 3*x)^3) + 136419/(4802*(2 + 3*x)^2) + 4774713/(16807*(2 + 3*x)) - (64*Log[1 - 2*x])/1294139 - (167115051*Log[2 + 3*x])/117649 + (15625*Log[3 + 5*x])/11}
{1/((1 - 2*x)*(2 + 3*x)^7*(3 + 5*x)), x, 2, 1/(14*(2 + 3*x)^6) + 111/(245*(2 + 3*x)^5) + 3897/(1372*(2 + 3*x)^4) + 45473/(2401*(2 + 3*x)^3) + 4774713/(33614*(2 + 3*x)^2) + 167115051/(117649*(2 + 3*x)) - (128*Log[1 - 2*x])/9058973 - (5849026977*Log[2 + 3*x])/823543 + (78125*Log[3 + 5*x])/11}


{(2 + 3*x)^m/((1 - 2*x)*(3 + 5*x)^2), x, 6, -((5*(2 + 3*x)^(1 + m))/(11*(3 + 5*x))) + (4*(2 + 3*x)^(1 + m)*Hypergeometric2F1[1, 1 + m, 2 + m, (2/7)*(2 + 3*x)])/(847*(1 + m)) - (10*(2 + 3*x)^(1 + m)*Hypergeometric2F1[1, 1 + m, 2 + m, 5*(2 + 3*x)])/(121*(1 + m)) - (15*m*(2 + 3*x)^(1 + m)*Hypergeometric2F1[1, 1 + m, 2 + m, 5*(2 + 3*x)])/(11*(1 + m))}

{(2 + 3*x)^8/((1 - 2*x)*(3 + 5*x)^2), x, 2, (-3579885909*x)/5000000 - (118543581*x^2)/200000 - (24660207*x^3)/50000 - (6194313*x^4)/20000 - (303993*x^5)/2500 - (2187*x^6)/100 - 1/(4296875*(3 + 5*x)) - (5764801*Log[1 - 2*x])/15488 + (266*Log[3 + 5*x])/47265625}
{(2 + 3*x)^7/((1 - 2*x)*(3 + 5*x)^2), x, 2, (-19846971*x)/100000 - (14750667*x^2)/100000 - (495477*x^3)/5000 - (86751*x^4)/2000 - (2187*x^5)/250 - 1/(859375*(3 + 5*x)) - (823543*Log[1 - 2*x])/7744 + (233*Log[3 + 5*x])/9453125}
{(2 + 3*x)^6/((1 - 2*x)*(3 + 5*x)^2), x, 2, (-2682909*x)/50000 - (335097*x^2)/10000 - (8019*x^3)/500 - (729*x^4)/200 - 1/(171875*(3 + 5*x)) - (117649*Log[1 - 2*x])/3872 + (8*Log[3 + 5*x])/75625}
{(2 + 3*x)^5/((1 - 2*x)*(3 + 5*x)^2), x, 2, (-69039*x)/5000 - (6399*x^2)/1000 - (81*x^3)/50 - 1/(34375*(3 + 5*x)) - (16807*Log[1 - 2*x])/1936 + (167*Log[3 + 5*x])/378125}
{(2 + 3*x)^4/((1 - 2*x)*(3 + 5*x)^2), x, 2, (-1593*x)/500 - (81*x^2)/100 - 1/(6875*(3 + 5*x)) - (2401*Log[1 - 2*x])/968 + (134*Log[3 + 5*x])/75625}
{(2 + 3*x)^3/((1 - 2*x)*(3 + 5*x)^2), x, 2, (-27*x)/50 - 1/(1375*(3 + 5*x)) - (343*Log[1 - 2*x])/484 + (101*Log[3 + 5*x])/15125}
{(2 + 3*x)^2/((1 - 2*x)*(3 + 5*x)^2), x, 2, -1/(275*(3 + 5*x)) - (49*Log[1 - 2*x])/242 + (68*Log[3 + 5*x])/3025}
{(2 + 3*x)/((1 - 2*x)*(3 + 5*x)^2), x, 2, -1/(55*(3 + 5*x)) - (7*Log[1 - 2*x])/121 + (7*Log[3 + 5*x])/121}
{1/((1 - 2*x)*(3 + 5*x)^2), x, 2, -1/(11*(3 + 5*x)) - (2*Log[1 - 2*x])/121 + (2*Log[3 + 5*x])/121}
{1/((1 - 2*x)*(2 + 3*x)*(3 + 5*x)^2), x, 2, -5/(11*(3 + 5*x)) - (4*Log[1 - 2*x])/847 + (9*Log[2 + 3*x])/7 - (155*Log[3 + 5*x])/121}
{1/((1 - 2*x)*(2 + 3*x)^2*(3 + 5*x)^2), x, 2, -9/(7*(2 + 3*x)) - 25/(11*(3 + 5*x)) - (8*Log[1 - 2*x])/5929 + (648*Log[2 + 3*x])/49 - (1600*Log[3 + 5*x])/121}
{1/((1 - 2*x)*(2 + 3*x)^3*(3 + 5*x)^2), x, 2, -9/(14*(2 + 3*x)^2) - 648/(49*(2 + 3*x)) - 125/(11*(3 + 5*x)) - (16*Log[1 - 2*x])/41503 + (34371*Log[2 + 3*x])/343 - (12125*Log[3 + 5*x])/121}
{1/((1 - 2*x)*(2 + 3*x)^4*(3 + 5*x)^2), x, 2, -3/(7*(2 + 3*x)^3) - 324/(49*(2 + 3*x)^2) - 34371/(343*(2 + 3*x)) - 625/(11*(3 + 5*x)) - (32*Log[1 - 2*x])/290521 + (1612242*Log[2 + 3*x])/2401 - (81250*Log[3 + 5*x])/121}
{1/((1 - 2*x)*(2 + 3*x)^5*(3 + 5*x)^2), x, 2, -9/(28*(2 + 3*x)^4) - 216/(49*(2 + 3*x)^3) - 34371/(686*(2 + 3*x)^2) - 1612242/(2401*(2 + 3*x)) - 3125/(11*(3 + 5*x)) - (64*Log[1 - 2*x])/2033647 + (70752609*Log[2 + 3*x])/16807 - (509375*Log[3 + 5*x])/121}
{1/((1 - 2*x)*(2 + 3*x)^6*(3 + 5*x)^2), x, 2, -9/(35*(2 + 3*x)^5) - 162/(49*(2 + 3*x)^4) - 11457/(343*(2 + 3*x)^3) - 806121/(2401*(2 + 3*x)^2) - 70752609/(16807*(2 + 3*x)) - 15625/(11*(3 + 5*x)) - (128*Log[1 - 2*x])/14235529 + (2977686468*Log[2 + 3*x])/117649 - (3062500*Log[3 + 5*x])/121}


{(2 + 3*x)^m/((1 - 2*x)*(3 + 5*x)^3), x, 9, -((5*(2 + 3*x)^(1 + m))/(22*(3 + 5*x)^2)) - (10*(2 + 3*x)^(1 + m))/(121*(3 + 5*x)) + (15*(1 - m)*(2 + 3*x)^(1 + m))/(22*(3 + 5*x)) + (8*(2 + 3*x)^(1 + m)*Hypergeometric2F1[1, 1 + m, 2 + m, (2/7)*(2 + 3*x)])/(9317*(1 + m)) - (20*(2 + 3*x)^(1 + m)*Hypergeometric2F1[1, 1 + m, 2 + m, 5*(2 + 3*x)])/(1331*(1 + m)) - (30*m*(2 + 3*x)^(1 + m)*Hypergeometric2F1[1, 1 + m, 2 + m, 5*(2 + 3*x)])/(121*(1 + m)) + (45*(1 - m)*m*(2 + 3*x)^(1 + m)*Hypergeometric2F1[1, 1 + m, 2 + m, 5*(2 + 3*x)])/(22*(1 + m))}

{(2 + 3*x)^8/((1 - 2*x)*(3 + 5*x)^3), x, 2, (-62934003*x)/500000 - (9268263*x^2)/100000 - (1535517*x^3)/25000 - (264627*x^4)/10000 - (6561*x^5)/1250 - 1/(8593750*(3 + 5*x)^2) - 266/(47265625*(3 + 5*x)) - (5764801*Log[1 - 2*x])/85184 + (31024*Log[3 + 5*x])/519921875}
{(2 + 3*x)^7/((1 - 2*x)*(3 + 5*x)^3), x, 2, (-339309*x)/10000 - (1044657*x^2)/50000 - (24543*x^3)/2500 - (2187*x^4)/1000 - 1/(1718750*(3 + 5*x)^2) - 233/(9453125*(3 + 5*x)) - (823543*Log[1 - 2*x])/42592 + (4667*Log[3 + 5*x])/20796875}
{(2 + 3*x)^6/((1 - 2*x)*(3 + 5*x)^3), x, 2, (-216999*x)/25000 - (19683*x^2)/5000 - (243*x^3)/250 - 1/(343750*(3 + 5*x)^2) - 8/(75625*(3 + 5*x)) - (117649*Log[1 - 2*x])/21296 + (3347*Log[3 + 5*x])/4159375}
{(2 + 3*x)^5/((1 - 2*x)*(3 + 5*x)^3), x, 2, (-4941*x)/2500 - (243*x^2)/500 - 1/(68750*(3 + 5*x)^2) - 167/(378125*(3 + 5*x)) - (16807*Log[1 - 2*x])/10648 + (11224*Log[3 + 5*x])/4159375}
{(2 + 3*x)^4/((1 - 2*x)*(3 + 5*x)^3), x, 2, (-81*x)/250 - 1/(13750*(3 + 5*x)^2) - 134/(75625*(3 + 5*x)) - (2401*Log[1 - 2*x])/5324 + (6802*Log[3 + 5*x])/831875}
{(2 + 3*x)^3/((1 - 2*x)*(3 + 5*x)^3), x, 2, -1/(2750*(3 + 5*x)^2) - 101/(15125*(3 + 5*x)) - (343*Log[1 - 2*x])/2662 + (3469*Log[3 + 5*x])/166375}
{(2 + 3*x)^2/((1 - 2*x)*(3 + 5*x)^3), x, 2, -1/(550*(3 + 5*x)^2) - 68/(3025*(3 + 5*x)) - (49*Log[1 - 2*x])/1331 + (49*Log[3 + 5*x])/1331}
{(2 + 3*x)/((1 - 2*x)*(3 + 5*x)^3), x, 2, -1/(110*(3 + 5*x)^2) - 7/(121*(3 + 5*x)) - (14*Log[1 - 2*x])/1331 + (14*Log[3 + 5*x])/1331}
{1/((1 - 2*x)*(3 + 5*x)^3), x, 2, -1/(22*(3 + 5*x)^2) - 2/(121*(3 + 5*x)) - (4*Log[1 - 2*x])/1331 + (4*Log[3 + 5*x])/1331}
{1/((1 - 2*x)*(2 + 3*x)*(3 + 5*x)^3), x, 2, -5/(22*(3 + 5*x)^2) + 155/(121*(3 + 5*x)) - (8*Log[1 - 2*x])/9317 - (27*Log[2 + 3*x])/7 + (5135*Log[3 + 5*x])/1331}
{1/((1 - 2*x)*(2 + 3*x)^2*(3 + 5*x)^3), x, 2, 27/(7*(2 + 3*x)) - 25/(22*(3 + 5*x)^2) + 1600/(121*(3 + 5*x)) - (16*Log[1 - 2*x])/65219 - (2889*Log[2 + 3*x])/49 + (78475*Log[3 + 5*x])/1331}
{1/((1 - 2*x)*(2 + 3*x)^3*(3 + 5*x)^3), x, 2, 27/(14*(2 + 3*x)^2) + 2889/(49*(2 + 3*x)) - 125/(22*(3 + 5*x)^2) + 12125/(121*(3 + 5*x)) - (32*Log[1 - 2*x])/456533 - (204228*Log[2 + 3*x])/343 + (792500*Log[3 + 5*x])/1331}
{1/((1 - 2*x)*(2 + 3*x)^4*(3 + 5*x)^3), x, 2, 9/(7*(2 + 3*x)^3) + 2889/(98*(2 + 3*x)^2) + 204228/(343*(2 + 3*x)) - 625/(22*(3 + 5*x)^2) + 81250/(121*(3 + 5*x)) - (64*Log[1 - 2*x])/3195731 - (11984706*Log[2 + 3*x])/2401 + (6643750*Log[3 + 5*x])/1331}
{1/((1 - 2*x)*(2 + 3*x)^5*(3 + 5*x)^3), x, 2, 27/(28*(2 + 3*x)^4) + 963/(49*(2 + 3*x)^3) + 102114/(343*(2 + 3*x)^2) + 11984706/(2401*(2 + 3*x)) - 3125/(22*(3 + 5*x)^2) + 509375/(121*(3 + 5*x)) - (128*Log[1 - 2*x])/22370117 - (631722537*Log[2 + 3*x])/16807 + (50028125*Log[3 + 5*x])/1331}


(* ::Subsection::Closed:: *)
(*Integrands of the form (a+b x)^m (c+d x)^n / (e+f x)^2*)


(* ::Subsubsection::Closed:: *)
(*n>0*)


{((2 + 3*x)^8*(3 + 5*x))/(1 - 2*x)^2, x, 2, 63412811/(1024*(1 - 2*x)) + (91609881*x)/256 + (122887143*x^2)/512 + (5892813*x^3)/32 + (32991057*x^4)/256 + (5859459*x^5)/80 + (976617*x^6)/32 + (56862*x^7)/7 + (32805*x^8)/32 + (246239357*Log[1 - 2*x])/1024}
{((2 + 3*x)^7*(3 + 5*x))/(1 - 2*x)^2, x, 2, 9058973/(512*(1 - 2*x)) + (22333965*x)/256 + (873207*x^2)/16 + (2399985*x^3)/64 + (1423899*x^4)/64 + (793881*x^5)/80 + (11421*x^6)/4 + (10935*x^7)/28 + (15647317*Log[1 - 2*x])/256}
{((2 + 3*x)^6*(3 + 5*x))/(1 - 2*x)^2, x, 2, 1294139/(256*(1 - 2*x)) + (661617*x)/32 + (1507977*x^2)/128 + (111501*x^3)/16 + (210195*x^4)/64 + (5103*x^5)/5 + (1215*x^6)/8 + (3916031*Log[1 - 2*x])/256}
{((2 + 3*x)^5*(3 + 5*x))/(1 - 2*x)^2, x, 2, 184877/(128*(1 - 2*x)) + (301467*x)/64 + (75447*x^2)/32 + (18027*x^3)/16 + (2997*x^4)/8 + (243*x^5)/4 + (60025*Log[1 - 2*x])/16}
{((2 + 3*x)^4*(3 + 5*x))/(1 - 2*x)^2, x, 2, 26411/(64*(1 - 2*x)) + (16203*x)/16 + (13419*x^2)/32 + 144*x^3 + (405*x^4)/16 + (57281*Log[1 - 2*x])/64}
{((2 + 3*x)^3*(3 + 5*x))/(1 - 2*x)^2, x, 2, 3773/(32*(1 - 2*x)) + (3177*x)/16 + (243*x^2)/4 + (45*x^3)/4 + (3283*Log[1 - 2*x])/16}
{((2 + 3*x)^2*(3 + 5*x))/(1 - 2*x)^2, x, 2, 539/(16*(1 - 2*x)) + 33*x + (45*x^2)/8 + (707*Log[1 - 2*x])/16}
{((2 + 3*x)*(3 + 5*x))/(1 - 2*x)^2, x, 2, 77/(8*(1 - 2*x)) + (15*x)/4 + (17*Log[1 - 2*x])/2}
{(3 + 5*x)/(1 - 2*x)^2, x, 2, 11/(4*(1 - 2*x)) + (5*Log[1 - 2*x])/4}
{(3 + 5*x)/((1 - 2*x)^2*(2 + 3*x)), x, 2, 11/(14*(1 - 2*x)) + Log[1 - 2*x]/49 - Log[2 + 3*x]/49}
{(3 + 5*x)/((1 - 2*x)^2*(2 + 3*x)^2), x, 2, 11/(49*(1 - 2*x)) + 1/(49*(2 + 3*x)) - (31*Log[1 - 2*x])/343 + (31*Log[2 + 3*x])/343}
{(3 + 5*x)/((1 - 2*x)^2*(2 + 3*x)^3), x, 2, 22/(343*(1 - 2*x)) + 1/(98*(2 + 3*x)^2) - 31/(343*(2 + 3*x)) - (128*Log[1 - 2*x])/2401 + (128*Log[2 + 3*x])/2401}
{(3 + 5*x)/((1 - 2*x)^2*(2 + 3*x)^4), x, 2, 44/(2401*(1 - 2*x)) + 1/(147*(2 + 3*x)^3) - 31/(686*(2 + 3*x)^2) - 128/(2401*(2 + 3*x)) - (388*Log[1 - 2*x])/16807 + (388*Log[2 + 3*x])/16807}
{(3 + 5*x)/((1 - 2*x)^2*(2 + 3*x)^5), x, 2, 88/(16807*(1 - 2*x)) + 1/(196*(2 + 3*x)^4) - 31/(1029*(2 + 3*x)^3) - 64/(2401*(2 + 3*x)^2) - 388/(16807*(2 + 3*x)) - (1040*Log[1 - 2*x])/117649 + (1040*Log[2 + 3*x])/117649}
{(3 + 5*x)/((1 - 2*x)^2*(2 + 3*x)^6), x, 2, 176/(117649*(1 - 2*x)) + 1/(245*(2 + 3*x)^5) - 31/(1372*(2 + 3*x)^4) - 128/(7203*(2 + 3*x)^3) - 194/(16807*(2 + 3*x)^2) - 1040/(117649*(2 + 3*x)) - (2608*Log[1 - 2*x])/823543 + (2608*Log[2 + 3*x])/823543}
{(3 + 5*x)/((1 - 2*x)^2*(2 + 3*x)^7), x, 2, 352/(823543*(1 - 2*x)) + 1/(294*(2 + 3*x)^6) - 31/(1715*(2 + 3*x)^5) - 32/(2401*(2 + 3*x)^4) - 388/(50421*(2 + 3*x)^3) - 520/(117649*(2 + 3*x)^2) - 2608/(823543*(2 + 3*x)) - (128*Log[1 - 2*x])/117649 + (128*Log[2 + 3*x])/117649}


{((2 + 3*x)^8*(3 + 5*x)^2)/(1 - 2*x)^2, x, 2, 697540921/(2048*(1 - 2*x)) + (2330515357*x)/1024 + (413355417*x^2)/256 + (346239417*x^3)/256 + (275757561*x^4)/256 + (235268793*x^5)/320 + 396738*x^6 + (17378631*x^7)/112 + (1235655*x^8)/32 + (18225*x^9)/4 + (1512848491*Log[1 - 2*x])/1024}
{((2 + 3*x)^7*(3 + 5*x)^2)/(1 - 2*x)^2, x, 2, 99648703/(1024*(1 - 2*x)) + (9077405*x)/16 + (195497697*x^2)/512 + (18842715*x^3)/64 + (53086563*x^4)/256 + (4750569*x^5)/40 + (1597239*x^6)/32 + (375435*x^7)/28 + (54675*x^8)/32 + (389535839*Log[1 - 2*x])/1024}
{((2 + 3*x)^6*(3 + 5*x)^2)/(1 - 2*x)^2, x, 2, 14235529/(512*(1 - 2*x)) + (35458963*x)/256 + (11140101*x^2)/128 + (3851307*x^3)/64 + (575775*x^4)/16 + (1295919*x^5)/80 + (37665*x^6)/8 + (18225*x^7)/28 + (12386759*Log[1 - 2*x])/128}
{((2 + 3*x)^5*(3 + 5*x)^2)/(1 - 2*x)^2, x, 2, 2033647/(256*(1 - 2*x)) + (2104901*x)/64 + (2412699*x^2)/128 + (89913*x^3)/8 + (342333*x^4)/64 + (6723*x^5)/4 + (2025*x^6)/8 + (6206585*Log[1 - 2*x])/256}
{((2 + 3*x)^4*(3 + 5*x)^2)/(1 - 2*x)^2, x, 2, 290521/(128*(1 - 2*x)) + (480841*x)/64 + (15159*x^2)/4 + (29277*x^3)/16 + (9855*x^4)/16 + (405*x^5)/4 + (381073*Log[1 - 2*x])/64}
{((2 + 3*x)^3*(3 + 5*x)^2)/(1 - 2*x)^2, x, 2, 41503/(64*(1 - 2*x)) + (12973*x)/8 + (21717*x^2)/32 + (945*x^3)/4 + (675*x^4)/16 + (91091*Log[1 - 2*x])/64}
{((2 + 3*x)^2*(3 + 5*x)^2)/(1 - 2*x)^2, x, 2, 5929/(32*(1 - 2*x)) + (5119*x)/16 + (795*x^2)/8 + (75*x^3)/4 + (1309*Log[1 - 2*x])/4}
{((2 + 3*x)*(3 + 5*x)^2)/(1 - 2*x)^2, x, 2, 847/(16*(1 - 2*x)) + (215*x)/4 + (75*x^2)/8 + (1133*Log[1 - 2*x])/16}
{(3 + 5*x)^2/(1 - 2*x)^2, x, 2, 121/(8*(1 - 2*x)) + (25*x)/4 + (55*Log[1 - 2*x])/4}
{(3 + 5*x)^2/((1 - 2*x)^2*(2 + 3*x)), x, 2, 121/(28*(1 - 2*x)) + (407*Log[1 - 2*x])/196 + Log[2 + 3*x]/147}
{(3 + 5*x)^2/((1 - 2*x)^2*(2 + 3*x)^2), x, 2, 121/(98*(1 - 2*x)) - 1/(147*(2 + 3*x)) + (22*Log[1 - 2*x])/343 - (22*Log[2 + 3*x])/343}
{(3 + 5*x)^2/((1 - 2*x)^2*(2 + 3*x)^3), x, 2, 121/(343*(1 - 2*x)) - 1/(294*(2 + 3*x)^2) + 22/(343*(2 + 3*x)) - (319*Log[1 - 2*x])/2401 + (319*Log[2 + 3*x])/2401}
{(3 + 5*x)^2/((1 - 2*x)^2*(2 + 3*x)^4), x, 2, 242/(2401*(1 - 2*x)) - 1/(441*(2 + 3*x)^3) + 11/(343*(2 + 3*x)^2) - 319/(2401*(2 + 3*x)) - (1364*Log[1 - 2*x])/16807 + (1364*Log[2 + 3*x])/16807}
{(3 + 5*x)^2/((1 - 2*x)^2*(2 + 3*x)^5), x, 2, 484/(16807*(1 - 2*x)) - 1/(588*(2 + 3*x)^4) + 22/(1029*(2 + 3*x)^3) - 319/(4802*(2 + 3*x)^2) - 1364/(16807*(2 + 3*x)) - (4180*Log[1 - 2*x])/117649 + (4180*Log[2 + 3*x])/117649}
{(3 + 5*x)^2/((1 - 2*x)^2*(2 + 3*x)^6), x, 2, 968/(117649*(1 - 2*x)) - 1/(735*(2 + 3*x)^5) + 11/(686*(2 + 3*x)^4) - 319/(7203*(2 + 3*x)^3) - 682/(16807*(2 + 3*x)^2) - 4180/(117649*(2 + 3*x)) - (11264*Log[1 - 2*x])/823543 + (11264*Log[2 + 3*x])/823543}
{(3 + 5*x)^2/((1 - 2*x)^2*(2 + 3*x)^7), x, 2, 1936/(823543*(1 - 2*x)) - 1/(882*(2 + 3*x)^6) + 22/(1715*(2 + 3*x)^5) - 319/(9604*(2 + 3*x)^4) - 1364/(50421*(2 + 3*x)^3) - 2090/(117649*(2 + 3*x)^2) - 11264/(823543*(2 + 3*x)) - (4048*Log[1 - 2*x])/823543 + (4048*Log[2 + 3*x])/823543}
{(3 + 5*x)^2/((1 - 2*x)^2*(2 + 3*x)^8), x, 2, 3872/(5764801*(1 - 2*x)) - 1/(1029*(2 + 3*x)^7) + 11/(1029*(2 + 3*x)^6) - 319/(12005*(2 + 3*x)^5) - 341/(16807*(2 + 3*x)^4) - 4180/(352947*(2 + 3*x)^3) - 5632/(823543*(2 + 3*x)^2) - 4048/(823543*(2 + 3*x)) - (68288*Log[1 - 2*x])/40353607 + (68288*Log[2 + 3*x])/40353607}


{((2 + 3*x)^8*(3 + 5*x)^3)/(1 - 2*x)^2, x, 2, 7672950131/(4096*(1 - 2*x)) + (7277894263*x)/512 + (21573106793*x^2)/2048 + (2416569641*x^3)/256 + (8502681987*x^4)/1024 + (260574273*x^5)/40 + (544462047*x^6)/128 + (242570133*x^7)/112 + (101721015*x^8)/128 + (370575*x^9)/2 + (164025*x^10)/8 + (36770371407*Log[1 - 2*x])/4096}
{((2 + 3*x)^7*(3 + 5*x)^3)/(1 - 2*x)^2, x, 2, 1096135733/(2048*(1 - 2*x)) + (3690540955*x)/1024 + (1312685491*x^2)/512 + (551942075*x^3)/256 + (220950207*x^4)/128 + (379446471*x^5)/320 + (20626947*x^6)/32 + (28463805*x^7)/112 + (127575*x^8)/2 + (30375*x^9)/4 + (298946109*Log[1 - 2*x])/128}
{((2 + 3*x)^6*(3 + 5*x)^3)/(1 - 2*x)^2, x, 2, 156590819/(1024*(1 - 2*x)) + (230244479*x)/256 + (310976027*x^2)/512 + (7530189*x^3)/16 + (85406805*x^4)/256 + (15403257*x^5)/80 + (2611845*x^6)/32 + (309825*x^7)/14 + (91125*x^8)/32 + (616195041*Log[1 - 2*x])/1024}
{((2 + 3*x)^5*(3 + 5*x)^3)/(1 - 2*x)^2, x, 2, 22370117/(512*(1 - 2*x)) + (56291737*x)/256 + (8881301*x^2)/64 + (6179077*x^3)/64 + (3724389*x^4)/64 + (423009*x^5)/16 + (15525*x^6)/2 + (30375*x^7)/28 + (39220335*Log[1 - 2*x])/256}
{((2 + 3*x)^4*(3 + 5*x)^3)/(1 - 2*x)^2, x, 2, 3195731/(256*(1 - 2*x)) + (209243*x)/4 + (3859469*x^2)/128 + (289951*x^3)/16 + (557415*x^4)/64 + (5535*x^5)/2 + (3375*x^6)/8 + (9836211*Log[1 - 2*x])/256}
{((2 + 3*x)^3*(3 + 5*x)^3)/(1 - 2*x)^2, x, 2, 456533/(128*(1 - 2*x)) + (766807*x)/64 + (194881*x^2)/32 + (47535*x^3)/16 + (2025*x^4)/2 + (675*x^5)/4 + (302379*Log[1 - 2*x])/32}
{((2 + 3*x)^2*(3 + 5*x)^3)/(1 - 2*x)^2, x, 2, 65219/(64*(1 - 2*x)) + (41537*x)/16 + (35135*x^2)/32 + (775*x^3)/2 + (1125*x^4)/16 + (144837*Log[1 - 2*x])/64}
{((2 + 3*x)*(3 + 5*x)^3)/(1 - 2*x)^2, x, 2, 9317/(32*(1 - 2*x)) + (8245*x)/16 + (325*x^2)/2 + (125*x^3)/4 + (8349*Log[1 - 2*x])/16}
{(3 + 5*x)^3/(1 - 2*x)^2, x, 2, 1331/(16*(1 - 2*x)) + (175*x)/2 + (125*x^2)/8 + (1815*Log[1 - 2*x])/16}
{(3 + 5*x)^3/((1 - 2*x)^2*(2 + 3*x)), x, 2, 1331/(56*(1 - 2*x)) + (125*x)/12 + (1089*Log[1 - 2*x])/49 - Log[2 + 3*x]/441}
{(3 + 5*x)^3/((1 - 2*x)^2*(2 + 3*x)^2), x, 2, 1331/(196*(1 - 2*x)) + 1/(441*(2 + 3*x)) + (4719*Log[1 - 2*x])/1372 + (101*Log[2 + 3*x])/3087}
{(3 + 5*x)^3/((1 - 2*x)^2*(2 + 3*x)^3), x, 2, 1331/(686*(1 - 2*x)) + 1/(882*(2 + 3*x)^2) - 101/(3087*(2 + 3*x)) + (363*Log[1 - 2*x])/2401 - (363*Log[2 + 3*x])/2401}
{(3 + 5*x)^3/((1 - 2*x)^2*(2 + 3*x)^4), x, 2, 1331/(2401*(1 - 2*x)) + 1/(1323*(2 + 3*x)^3) - 101/(6174*(2 + 3*x)^2) + 363/(2401*(2 + 3*x)) - (3267*Log[1 - 2*x])/16807 + (3267*Log[2 + 3*x])/16807}
{(3 + 5*x)^3/((1 - 2*x)^2*(2 + 3*x)^5), x, 2, 2662/(16807*(1 - 2*x)) + 1/(1764*(2 + 3*x)^4) - 101/(9261*(2 + 3*x)^3) + 363/(4802*(2 + 3*x)^2) - 3267/(16807*(2 + 3*x)) - (14520*Log[1 - 2*x])/117649 + (14520*Log[2 + 3*x])/117649}
{(3 + 5*x)^3/((1 - 2*x)^2*(2 + 3*x)^6), x, 2, 5324/(117649*(1 - 2*x)) + 1/(2205*(2 + 3*x)^5) - 101/(12348*(2 + 3*x)^4) + 121/(2401*(2 + 3*x)^3) - 3267/(33614*(2 + 3*x)^2) - 14520/(117649*(2 + 3*x)) - (45012*Log[1 - 2*x])/823543 + (45012*Log[2 + 3*x])/823543}
{(3 + 5*x)^3/((1 - 2*x)^2*(2 + 3*x)^7), x, 2, 10648/(823543*(1 - 2*x)) + 1/(2646*(2 + 3*x)^6) - 101/(15435*(2 + 3*x)^5) + 363/(9604*(2 + 3*x)^4) - 1089/(16807*(2 + 3*x)^3) - 7260/(117649*(2 + 3*x)^2) - 45012/(823543*(2 + 3*x)) - (17424*Log[1 - 2*x])/823543 + (17424*Log[2 + 3*x])/823543}
{(3 + 5*x)^3/((1 - 2*x)^2*(2 + 3*x)^8), x, 2, 21296/(5764801*(1 - 2*x)) + 1/(3087*(2 + 3*x)^7) - 101/(18522*(2 + 3*x)^6) + 363/(12005*(2 + 3*x)^5) - 3267/(67228*(2 + 3*x)^4) - 4840/(117649*(2 + 3*x)^3) - 22506/(823543*(2 + 3*x)^2) - 17424/(823543*(2 + 3*x)) - (307824*Log[1 - 2*x])/40353607 + (307824*Log[2 + 3*x])/40353607}


(* ::Subsubsection::Closed:: *)
(*n<0*)


(* Mathematica 8 cannot get these. *)
{(a + b*x)^m/((c + d*x)^0*(e + f*x)^2), x, 2, (a + b*x)^(1 + m)/((b*e - a*f)*(e + f*x)) - (b*m*(a + b*x)^(1 + m)*Hypergeometric2F1[1, 1 + m, 2 + m, -((f*(a + b*x))/(b*e - a*f))])/((b*e - a*f)^2*(1 + m))}
{(a + b*x)^m/((c + d*x)^1*(e + f*x)^2), x, 6, -((f*(a + b*x)^(1 + m))/((b*e - a*f)*(d*e - c*f)*(e + f*x))) + (d^2*(a + b*x)^(1 + m)*Hypergeometric2F1[1, 1 + m, 2 + m, -((d*(a + b*x))/(b*c - a*d))])/((b*c - a*d)*(d*e - c*f)^2*(1 + m)) - (d*f*(a + b*x)^(1 + m)*Hypergeometric2F1[1, 1 + m, 2 + m, -((f*(a + b*x))/(b*e - a*f))])/((b*e - a*f)*(d*e - c*f)^2*(1 + m)) + (b*f*m*(a + b*x)^(1 + m)*Hypergeometric2F1[1, 1 + m, 2 + m, -((f*(a + b*x))/(b*e - a*f))])/((b*e - a*f)^2*(d*e - c*f)*(1 + m))}
{(a + b*x)^m/((c + d*x)^2*(e + f*x)^2), x, 8, (d^2*(a + b*x)^(1 + m))/((b*c - a*d)*(d*e - c*f)^2*(c + d*x)) + (f^2*(a + b*x)^(1 + m))/((b*e - a*f)*(d*e - c*f)^2*(e + f*x)) - (2*d^2*f*(a + b*x)^(1 + m)*Hypergeometric2F1[1, 1 + m, 2 + m, -((d*(a + b*x))/(b*c - a*d))])/((b*c - a*d)*(d*e - c*f)^3*(1 + m)) - (b*d^2*m*(a + b*x)^(1 + m)*Hypergeometric2F1[1, 1 + m, 2 + m, -((d*(a + b*x))/(b*c - a*d))])/((b*c - a*d)^2*(d*e - c*f)^2*(1 + m)) + (2*d*f^2*(a + b*x)^(1 + m)*Hypergeometric2F1[1, 1 + m, 2 + m, -((f*(a + b*x))/(b*e - a*f))])/((b*e - a*f)*(d*e - c*f)^3*(1 + m)) - (b*f^2*m*(a + b*x)^(1 + m)*Hypergeometric2F1[1, 1 + m, 2 + m, -((f*(a + b*x))/(b*e - a*f))])/((b*e - a*f)^2*(d*e - c*f)^2*(1 + m))}


{(2 + 3*x)^8/((1 - 2*x)^2*(3 + 5*x)), x, 2, 5764801/(2816*(1 - 2*x)) + (2041906293*x)/250000 + (1839811401*x^2)/400000 + (26773659*x^3)/10000 + (9899091*x^4)/8000 + (94041*x^5)/250 + (2187*x^6)/40 + (188591347*Log[1 - 2*x])/30976 + Log[3 + 5*x]/9453125}
{(2 + 3*x)^7/((1 - 2*x)^2*(3 + 5*x)), x, 2, 823543/(1408*(1 - 2*x)) + (370109547*x)/200000 + (18237069*x^2)/20000 + (853659*x^3)/2000 + (13851*x^4)/100 + (2187*x^5)/100 + (5764801*Log[1 - 2*x])/3872 + Log[3 + 5*x]/1890625}
{(2 + 3*x)^6/((1 - 2*x)^2*(3 + 5*x)), x, 2, 117649/(704*(1 - 2*x)) + (3946293*x)/10000 + (639819*x^2)/4000 + (2673*x^3)/50 + (729*x^4)/80 + (2739541*Log[1 - 2*x])/7744 + Log[3 + 5*x]/378125}
{(2 + 3*x)^5/((1 - 2*x)^2*(3 + 5*x)), x, 2, 16807/(352*(1 - 2*x)) + (152793*x)/2000 + (567*x^2)/25 + (81*x^3)/20 + (156065*Log[1 - 2*x])/1936 + Log[3 + 5*x]/75625}
{(2 + 3*x)^4/((1 - 2*x)^2*(3 + 5*x)), x, 2, 2401/(176*(1 - 2*x)) + (621*x)/50 + (81*x^2)/40 + (33271*Log[1 - 2*x])/1936 + Log[3 + 5*x]/15125}
{(2 + 3*x)^3/((1 - 2*x)^2*(3 + 5*x)), x, 2, 343/(88*(1 - 2*x)) + (27*x)/20 + (392*Log[1 - 2*x])/121 + Log[3 + 5*x]/3025}
{(2 + 3*x)^2/((1 - 2*x)^2*(3 + 5*x)), x, 2, 49/(44*(1 - 2*x)) + (217*Log[1 - 2*x])/484 + Log[3 + 5*x]/605}
{(2 + 3*x)/((1 - 2*x)^2*(3 + 5*x)), x, 2, 7/(22*(1 - 2*x)) - Log[1 - 2*x]/121 + Log[3 + 5*x]/121}
{1/((1 - 2*x)^2*(3 + 5*x)), x, 2, 1/(11*(1 - 2*x)) - (5*Log[1 - 2*x])/121 + (5*Log[3 + 5*x])/121}
{1/((1 - 2*x)^2*(2 + 3*x)*(3 + 5*x)), x, 2, 2/(77*(1 - 2*x)) - (136*Log[1 - 2*x])/5929 - (9*Log[2 + 3*x])/49 + (25*Log[3 + 5*x])/121}
{1/((1 - 2*x)^2*(2 + 3*x)^2*(3 + 5*x)), x, 2, 4/(539*(1 - 2*x)) + 9/(49*(2 + 3*x)) - (404*Log[1 - 2*x])/41503 - (351*Log[2 + 3*x])/343 + (125*Log[3 + 5*x])/121}
{1/((1 - 2*x)^2*(2 + 3*x)^3*(3 + 5*x)), x, 2, 8/(3773*(1 - 2*x)) + 9/(98*(2 + 3*x)^2) + 351/(343*(2 + 3*x)) - (1072*Log[1 - 2*x])/290521 - (12393*Log[2 + 3*x])/2401 + (625*Log[3 + 5*x])/121}
{1/((1 - 2*x)^2*(2 + 3*x)^4*(3 + 5*x)), x, 2, 16/(26411*(1 - 2*x)) + 3/(49*(2 + 3*x)^3) + 351/(686*(2 + 3*x)^2) + 12393/(2401*(2 + 3*x)) - (2672*Log[1 - 2*x])/2033647 - (434043*Log[2 + 3*x])/16807 + (3125*Log[3 + 5*x])/121}
{1/((1 - 2*x)^2*(2 + 3*x)^5*(3 + 5*x)), x, 2, 32/(184877*(1 - 2*x)) + 9/(196*(2 + 3*x)^4) + 117/(343*(2 + 3*x)^3) + 12393/(4802*(2 + 3*x)^2) + 434043/(16807*(2 + 3*x)) - (6400*Log[1 - 2*x])/14235529 - (15192225*Log[2 + 3*x])/117649 + (15625*Log[3 + 5*x])/121}
{1/((1 - 2*x)^2*(2 + 3*x)^6*(3 + 5*x)), x, 2, 64/(1294139*(1 - 2*x)) + 9/(245*(2 + 3*x)^5) + 351/(1372*(2 + 3*x)^4) + 4131/(2401*(2 + 3*x)^3) + 434043/(33614*(2 + 3*x)^2) + 15192225/(117649*(2 + 3*x)) - (14912*Log[1 - 2*x])/99648703 - (531729603*Log[2 + 3*x])/823543 + (78125*Log[3 + 5*x])/121}


{(2 + 3*x)^8/((1 - 2*x)^2*(3 + 5*x)^2), x, 2, 5764801/(15488*(1 - 2*x)) + (231915717*x)/200000 + (14171517*x^2)/25000 + (2626101*x^3)/10000 + (168399*x^4)/2000 + (6561*x^5)/500 - 1/(9453125*(3 + 5*x)) + (79883671*Log[1 - 2*x])/85184 + (268*Log[3 + 5*x])/103984375}
{(2 + 3*x)^7/((1 - 2*x)^2*(3 + 5*x)^2), x, 2, 823543/(7744*(1 - 2*x)) + (6156243*x)/25000 + (1974861*x^2)/20000 + (16281*x^3)/500 + (2187*x^4)/400 - 1/(1890625*(3 + 5*x)) + (18941489*Log[1 - 2*x])/85184 + (47*Log[3 + 5*x])/4159375}
{(2 + 3*x)^6/((1 - 2*x)^2*(3 + 5*x)^2), x, 2, 117649/(3872*(1 - 2*x)) + (473607*x)/10000 + (13851*x^2)/1000 + (243*x^3)/100 - 1/(378125*(3 + 5*x)) + (67228*Log[1 - 2*x])/1331 + (202*Log[3 + 5*x])/4159375}
{(2 + 3*x)^5/((1 - 2*x)^2*(3 + 5*x)^2), x, 2, 16807/(1936*(1 - 2*x)) + (3807*x)/500 + (243*x^2)/200 - 1/(75625*(3 + 5*x)) + (228095*Log[1 - 2*x])/21296 + (169*Log[3 + 5*x])/831875}
{(2 + 3*x)^4/((1 - 2*x)^2*(3 + 5*x)^2), x, 2, 2401/(968*(1 - 2*x)) + (81*x)/100 - 1/(15125*(3 + 5*x)) + (10633*Log[1 - 2*x])/5324 + (136*Log[3 + 5*x])/166375}
{(2 + 3*x)^3/((1 - 2*x)^2*(3 + 5*x)^2), x, 2, 343/(484*(1 - 2*x)) - 1/(3025*(3 + 5*x)) + (1421*Log[1 - 2*x])/5324 + (103*Log[3 + 5*x])/33275}
{(2 + 3*x)^2/((1 - 2*x)^2*(3 + 5*x)^2), x, 2, 49/(242*(1 - 2*x)) - 1/(605*(3 + 5*x)) - (14*Log[1 - 2*x])/1331 + (14*Log[3 + 5*x])/1331}
{(2 + 3*x)/((1 - 2*x)^2*(3 + 5*x)^2), x, 2, 7/(121*(1 - 2*x)) - 1/(121*(3 + 5*x)) - (37*Log[1 - 2*x])/1331 + (37*Log[3 + 5*x])/1331}
{1/((1 - 2*x)^2*(3 + 5*x)^2), x, 2, 2/(121*(1 - 2*x)) - 5/(121*(3 + 5*x)) - (20*Log[1 - 2*x])/1331 + (20*Log[3 + 5*x])/1331}
{1/((1 - 2*x)^2*(2 + 3*x)*(3 + 5*x)^2), x, 2, 4/(847*(1 - 2*x)) - 25/(121*(3 + 5*x)) - (412*Log[1 - 2*x])/65219 + (27*Log[2 + 3*x])/49 - (725*Log[3 + 5*x])/1331}
{1/((1 - 2*x)^2*(2 + 3*x)^2*(3 + 5*x)^2), x, 2, 8/(5929*(1 - 2*x)) - 27/(49*(2 + 3*x)) - 125/(121*(3 + 5*x)) - (1088*Log[1 - 2*x])/456533 + (1998*Log[2 + 3*x])/343 - (7750*Log[3 + 5*x])/1331}
{1/((1 - 2*x)^2*(2 + 3*x)^3*(3 + 5*x)^2), x, 2, 16/(41503*(1 - 2*x)) - 27/(98*(2 + 3*x)^2) - 1998/(343*(2 + 3*x)) - 625/(121*(3 + 5*x)) - (2704*Log[1 - 2*x])/3195731 + (107109*Log[2 + 3*x])/2401 - (59375*Log[3 + 5*x])/1331}
{1/((1 - 2*x)^2*(2 + 3*x)^4*(3 + 5*x)^2), x, 2, 32/(290521*(1 - 2*x)) - 9/(49*(2 + 3*x)^3) - 999/(343*(2 + 3*x)^2) - 107109/(2401*(2 + 3*x)) - 3125/(121*(3 + 5*x)) - (6464*Log[1 - 2*x])/22370117 + (5050944*Log[2 + 3*x])/16807 - (400000*Log[3 + 5*x])/1331}
{1/((1 - 2*x)^2*(2 + 3*x)^5*(3 + 5*x)^2), x, 2, 64/(2033647*(1 - 2*x)) - 27/(196*(2 + 3*x)^4) - 666/(343*(2 + 3*x)^3) - 107109/(4802*(2 + 3*x)^2) - 5050944/(16807*(2 + 3*x)) - 15625/(121*(3 + 5*x)) - (15040*Log[1 - 2*x])/156590819 + (222359715*Log[2 + 3*x])/117649 - (2515625*Log[3 + 5*x])/1331}


{(2 + 3*x)^8/((1 - 2*x)^2*(3 + 5*x)^3), x, 2, 5764801/(85184*(1 - 2*x)) + (7680987*x)/50000 + (6093711*x^2)/100000 + (12393*x^3)/625 + (6561*x^4)/2000 - 1/(18906250*(3 + 5*x)^2) - 268/(103984375*(3 + 5*x)) + (130943337*Log[1 - 2*x])/937024 + (6312*Log[3 + 5*x])/228765625}
{(2 + 3*x)^7/((1 - 2*x)^2*(3 + 5*x)^3), x, 2, 823543/(42592*(1 - 2*x)) + (1467477*x)/50000 + (21141*x^2)/2500 + (729*x^3)/500 - 1/(3781250*(3 + 5*x)^2) - 47/(4159375*(3 + 5*x)) + (7411887*Log[1 - 2*x])/234256 + (4761*Log[3 + 5*x])/45753125}
{(2 + 3*x)^6/((1 - 2*x)^2*(3 + 5*x)^3), x, 2, 117649/(21296*(1 - 2*x)) + (2916*x)/625 + (729*x^2)/1000 - 1/(756250*(3 + 5*x)^2) - 202/(4159375*(3 + 5*x)) + (1563051*Log[1 - 2*x])/234256 + (17139*Log[3 + 5*x])/45753125}
{(2 + 3*x)^5/((1 - 2*x)^2*(3 + 5*x)^3), x, 2, 16807/(10648*(1 - 2*x)) + (243*x)/500 - 1/(151250*(3 + 5*x)^2) - 169/(831875*(3 + 5*x)) + (36015*Log[1 - 2*x])/29282 + (11562*Log[3 + 5*x])/9150625}
{(2 + 3*x)^4/((1 - 2*x)^2*(3 + 5*x)^3), x, 2, 2401/(5324*(1 - 2*x)) - 1/(30250*(3 + 5*x)^2) - 136/(166375*(3 + 5*x)) + (9261*Log[1 - 2*x])/58564 + (7074*Log[3 + 5*x])/1830125}
{(2 + 3*x)^3/((1 - 2*x)^2*(3 + 5*x)^3), x, 2, 343/(2662*(1 - 2*x)) - 1/(6050*(3 + 5*x)^2) - 103/(33275*(3 + 5*x)) - (147*Log[1 - 2*x])/14641 + (147*Log[3 + 5*x])/14641}
{(2 + 3*x)^2/((1 - 2*x)^2*(3 + 5*x)^3), x, 2, 49/(1331*(1 - 2*x)) - 1/(1210*(3 + 5*x)^2) - 14/(1331*(3 + 5*x)) - (273*Log[1 - 2*x])/14641 + (273*Log[3 + 5*x])/14641}
{(2 + 3*x)/((1 - 2*x)^2*(3 + 5*x)^3), x, 2, 14/(1331*(1 - 2*x)) - 1/(242*(3 + 5*x)^2) - 37/(1331*(3 + 5*x)) - (144*Log[1 - 2*x])/14641 + (144*Log[3 + 5*x])/14641}
{1/((1 - 2*x)^2*(3 + 5*x)^3), x, 2, 4/(1331*(1 - 2*x)) - 5/(242*(3 + 5*x)^2) - 20/(1331*(3 + 5*x)) - (60*Log[1 - 2*x])/14641 + (60*Log[3 + 5*x])/14641}
{1/((1 - 2*x)^2*(2 + 3*x)*(3 + 5*x)^3), x, 2, 8/(9317*(1 - 2*x)) - 25/(242*(3 + 5*x)^2) + 725/(1331*(3 + 5*x)) - (1104*Log[1 - 2*x])/717409 - (81*Log[2 + 3*x])/49 + (24225*Log[3 + 5*x])/14641}
{1/((1 - 2*x)^2*(2 + 3*x)^2*(3 + 5*x)^3), x, 2, 16/(65219*(1 - 2*x)) + 81/(49*(2 + 3*x)) - 125/(242*(3 + 5*x)^2) + 7750/(1331*(3 + 5*x)) - (2736*Log[1 - 2*x])/5021863 - (8829*Log[2 + 3*x])/343 + (376875*Log[3 + 5*x])/14641}
{1/((1 - 2*x)^2*(2 + 3*x)^3*(3 + 5*x)^3), x, 2, 32/(456533*(1 - 2*x)) + 81/(98*(2 + 3*x)^2) + 8829/(343*(2 + 3*x)) - 625/(242*(3 + 5*x)^2) + 59375/(1331*(3 + 5*x)) - (6528*Log[1 - 2*x])/35153041 - (630342*Log[2 + 3*x])/2401 + (3843750*Log[3 + 5*x])/14641}
{1/((1 - 2*x)^2*(2 + 3*x)^4*(3 + 5*x)^3), x, 2, 64/(3195731*(1 - 2*x)) + 27/(49*(2 + 3*x)^3) + 8829/(686*(2 + 3*x)^2) + 630342/(2401*(2 + 3*x)) - 3125/(242*(3 + 5*x)^2) + 400000/(1331*(3 + 5*x)) - (15168*Log[1 - 2*x])/246071287 - (37214802*Log[2 + 3*x])/16807 + (32418750*Log[3 + 5*x])/14641}


(* ::Subsection::Closed:: *)
(*Integrands of the form (a+b x)^m (c+d x)^n / (e+f x)^3*)


(* ::Subsubsection::Closed:: *)
(*n>0*)


{((2 + 3*x)^8*(3 + 5*x))/(1 - 2*x)^3, x, 2, 63412811/(2048*(1 - 2*x)^2) - 246239357/(1024*(1 - 2*x)) - (120864213*x)/256 - (118841283*x^2)/512 - (16042509*x^3)/128 - (7568235*x^4)/128 - (213597*x^5)/10 - (162567*x^6)/32 - (32805*x^7)/56 - (106237047*Log[1 - 2*x])/256}
{((2 + 3*x)^7*(3 + 5*x))/(1 - 2*x)^3, x, 2, 9058973/(1024*(1 - 2*x)^2) - 15647317/(256*(1 - 2*x)) - (24960933*x)/256 - (10989621*x^2)/256 - (631611*x^3)/32 - (235467*x^4)/32 - (147987*x^5)/80 - (3645*x^6)/16 - (23647449*Log[1 - 2*x])/256}
{((2 + 3*x)^6*(3 + 5*x))/(1 - 2*x)^3, x, 2, 1294139/(512*(1 - 2*x)^2) - 3916031/(256*(1 - 2*x)) - (2431647*x)/128 - (461835*x^2)/64 - (10611*x^3)/4 - (44469*x^4)/64 - (729*x^5)/8 - (5078115*Log[1 - 2*x])/256}
{((2 + 3*x)^5*(3 + 5*x))/(1 - 2*x)^3, x, 2, 184877/(256*(1 - 2*x)^2) - 60025/(16*(1 - 2*x)) - (109089*x)/32 - (16821*x^2)/16 - (4401*x^3)/16 - (1215*x^4)/32 - (519645*Log[1 - 2*x])/128}
{((2 + 3*x)^4*(3 + 5*x))/(1 - 2*x)^3, x, 2, 26411/(128*(1 - 2*x)^2) - 57281/(64*(1 - 2*x)) - 540*x - (3861*x^2)/32 - (135*x^3)/8 - (24843*Log[1 - 2*x])/32}
{((2 + 3*x)^3*(3 + 5*x))/(1 - 2*x)^3, x, 2, 3773/(64*(1 - 2*x)^2) - 3283/(16*(1 - 2*x)) - (1107*x)/16 - (135*x^2)/16 - (1071*Log[1 - 2*x])/8}
{((2 + 3*x)^2*(3 + 5*x))/(1 - 2*x)^3, x, 2, 539/(32*(1 - 2*x)^2) - 707/(16*(1 - 2*x)) - (45*x)/8 - (309*Log[1 - 2*x])/16}
{((2 + 3*x)*(3 + 5*x))/(1 - 2*x)^3, x, 2, 77/(16*(1 - 2*x)^2) - 17/(2*(1 - 2*x)) - (15*Log[1 - 2*x])/8}
{(3 + 5*x)/(1 - 2*x)^3, x, 1, (3 + 5*x)^2/(22*(1 - 2*x)^2)}
{(3 + 5*x)/((1 - 2*x)^3*(2 + 3*x)), x, 2, 11/(28*(1 - 2*x)^2) - 1/(49*(1 - 2*x)) + (3*Log[1 - 2*x])/343 - (3*Log[2 + 3*x])/343}
{(3 + 5*x)/((1 - 2*x)^3*(2 + 3*x)^2), x, 2, 11/(98*(1 - 2*x)^2) + 31/(343*(1 - 2*x)) + 3/(343*(2 + 3*x)) - (87*Log[1 - 2*x])/2401 + (87*Log[2 + 3*x])/2401}
{(3 + 5*x)/((1 - 2*x)^3*(2 + 3*x)^3), x, 2, 11/(343*(1 - 2*x)^2) + 128/(2401*(1 - 2*x)) + 3/(686*(2 + 3*x)^2) - 87/(2401*(2 + 3*x)) - (558*Log[1 - 2*x])/16807 + (558*Log[2 + 3*x])/16807}
{(3 + 5*x)/((1 - 2*x)^3*(2 + 3*x)^4), x, 2, 22/(2401*(1 - 2*x)^2) + 388/(16807*(1 - 2*x)) + 1/(343*(2 + 3*x)^3) - 87/(4802*(2 + 3*x)^2) - 558/(16807*(2 + 3*x)) - (2280*Log[1 - 2*x])/117649 + (2280*Log[2 + 3*x])/117649}
{(3 + 5*x)/((1 - 2*x)^3*(2 + 3*x)^5), x, 2, 44/(16807*(1 - 2*x)^2) + 1040/(117649*(1 - 2*x)) + 3/(1372*(2 + 3*x)^4) - 29/(2401*(2 + 3*x)^3) - 279/(16807*(2 + 3*x)^2) - 2280/(117649*(2 + 3*x)) - (7680*Log[1 - 2*x])/823543 + (7680*Log[2 + 3*x])/823543}
{(3 + 5*x)/((1 - 2*x)^3*(2 + 3*x)^6), x, 2, 88/(117649*(1 - 2*x)^2) + 2608/(823543*(1 - 2*x)) + 3/(1715*(2 + 3*x)^5) - 87/(9604*(2 + 3*x)^4) - 186/(16807*(2 + 3*x)^3) - 1140/(117649*(2 + 3*x)^2) - 7680/(823543*(2 + 3*x)) - (3312*Log[1 - 2*x])/823543 + (3312*Log[2 + 3*x])/823543}


{((2 + 3*x)^7*(3 + 5*x)^2)/(1 - 2*x)^3, x, 2, 99648703/(2048*(1 - 2*x)^2) - 389535839/(1024*(1 - 2*x)) - (48280011*x)/64 - (190742391*x^2)/512 - (25895367*x^3)/128 - (12299769*x^4)/128 - (2798631*x^5)/80 - (268515*x^6)/32 - (54675*x^7)/56 - (84589631*Log[1 - 2*x])/128}
{((2 + 3*x)^6*(3 + 5*x)^2)/(1 - 2*x)^3, x, 2, 14235529/(1024*(1 - 2*x)^2) - 12386759/(128*(1 - 2*x)) - (39980457*x)/256 - (17700255*x^2)/256 - (1024389*x^3)/32 - (770067*x^4)/64 - (48843*x^5)/16 - (6075*x^6)/16 - (18859855*Log[1 - 2*x])/128}
{((2 + 3*x)^5*(3 + 5*x)^2)/(1 - 2*x)^3, x, 2, 2033647/(512*(1 - 2*x)^2) - 6206585/(256*(1 - 2*x)) - (3907293*x)/128 - (747297*x^2)/64 - (69273*x^3)/16 - (73305*x^4)/64 - (1215*x^5)/8 - (8117095*Log[1 - 2*x])/256}
{((2 + 3*x)^4*(3 + 5*x)^2)/(1 - 2*x)^3, x, 2, 290521/(256*(1 - 2*x)^2) - 381073/(64*(1 - 2*x)) - (176055*x)/32 - (54783*x^2)/32 - (7245*x^3)/16 - (2025*x^4)/32 - (832951*Log[1 - 2*x])/128}
{((2 + 3*x)^3*(3 + 5*x)^2)/(1 - 2*x)^3, x, 2, 41503/(128*(1 - 2*x)^2) - 91091/(64*(1 - 2*x)) - (14031*x)/16 - (6345*x^2)/32 - (225*x^3)/8 - (39977*Log[1 - 2*x])/32}
{((2 + 3*x)^2*(3 + 5*x)^2)/(1 - 2*x)^3, x, 2, 5929/(64*(1 - 2*x)^2) - 1309/(4*(1 - 2*x)) - (1815*x)/16 - (225*x^2)/16 - (3467*Log[1 - 2*x])/16}
{((2 + 3*x)*(3 + 5*x)^2)/(1 - 2*x)^3, x, 2, 847/(32*(1 - 2*x)^2) - 1133/(16*(1 - 2*x)) - (75*x)/8 - (505*Log[1 - 2*x])/16}
{(3 + 5*x)^2/(1 - 2*x)^3, x, 2, 121/(16*(1 - 2*x)^2) - 55/(4*(1 - 2*x)) - (25*Log[1 - 2*x])/8}
{(3 + 5*x)^2/((1 - 2*x)^3*(2 + 3*x)), x, 2, 121/(56*(1 - 2*x)^2) - 407/(196*(1 - 2*x)) - Log[1 - 2*x]/343 + Log[2 + 3*x]/343}
{(3 + 5*x)^2/((1 - 2*x)^3*(2 + 3*x)^2), x, 2, 121/(196*(1 - 2*x)^2) - 22/(343*(1 - 2*x)) - 1/(343*(2 + 3*x)) + (64*Log[1 - 2*x])/2401 - (64*Log[2 + 3*x])/2401}
{(3 + 5*x)^2/((1 - 2*x)^3*(2 + 3*x)^3), x, 2, 121/(686*(1 - 2*x)^2) + 319/(2401*(1 - 2*x)) - 1/(686*(2 + 3*x)^2) + 64/(2401*(2 + 3*x)) - (829*Log[1 - 2*x])/16807 + (829*Log[2 + 3*x])/16807}
{(3 + 5*x)^2/((1 - 2*x)^3*(2 + 3*x)^4), x, 2, 121/(2401*(1 - 2*x)^2) + 1364/(16807*(1 - 2*x)) - 1/(1029*(2 + 3*x)^3) + 32/(2401*(2 + 3*x)^2) - 829/(16807*(2 + 3*x)) - (5750*Log[1 - 2*x])/117649 + (5750*Log[2 + 3*x])/117649}
{(3 + 5*x)^2/((1 - 2*x)^3*(2 + 3*x)^5), x, 2, 242/(16807*(1 - 2*x)^2) + 4180/(117649*(1 - 2*x)) - 1/(1372*(2 + 3*x)^4) + 64/(7203*(2 + 3*x)^3) - 829/(33614*(2 + 3*x)^2) - 5750/(117649*(2 + 3*x)) - (24040*Log[1 - 2*x])/823543 + (24040*Log[2 + 3*x])/823543}
{(3 + 5*x)^2/((1 - 2*x)^3*(2 + 3*x)^6), x, 2, 484/(117649*(1 - 2*x)^2) + 11264/(823543*(1 - 2*x)) - 1/(1715*(2 + 3*x)^5) + 16/(2401*(2 + 3*x)^4) - 829/(50421*(2 + 3*x)^3) - 2875/(117649*(2 + 3*x)^2) - 24040/(823543*(2 + 3*x)) - (11696*Log[1 - 2*x])/823543 + (11696*Log[2 + 3*x])/823543}


{((2 + 3*x)^6*(3 + 5*x)^3)/(1 - 2*x)^3, x, 2, 156590819/(2048*(1 - 2*x)^2) - 616195041/(1024*(1 - 2*x)) - (308539921*x)/256 - (306103815*x^2)/512 - (41793093*x^3)/128 - (19986237*x^4)/128 - (229149*x^5)/4 - (443475*x^6)/32 - (91125*x^7)/56 - (33674025*Log[1 - 2*x])/32}
{((2 + 3*x)^5*(3 + 5*x)^3)/(1 - 2*x)^3, x, 2, 22370117/(1024*(1 - 2*x)^2) - 39220335/(256*(1 - 2*x)) - (64029233*x)/256 - (28504029*x^2)/256 - (1661133*x^3)/32 - (629505*x^4)/32 - (80595*x^5)/16 - (10125*x^6)/16 - (60160485*Log[1 - 2*x])/256}
{((2 + 3*x)^4*(3 + 5*x)^3)/(1 - 2*x)^3, x, 2, 3195731/(512*(1 - 2*x)^2) - 9836211/(256*(1 - 2*x)) - (6277415*x)/128 - (1208973*x^2)/64 - 7065*x^3 - (120825*x^4)/64 - (2025*x^5)/8 - (12973191*Log[1 - 2*x])/256}
{((2 + 3*x)^3*(3 + 5*x)^3)/(1 - 2*x)^3, x, 2, 456533/(256*(1 - 2*x)^2) - 302379/(32*(1 - 2*x)) - (284071*x)/32 - (44595*x^2)/16 - (11925*x^3)/16 - (3375*x^4)/32 - (1334949*Log[1 - 2*x])/128}
{((2 + 3*x)^2*(3 + 5*x)^3)/(1 - 2*x)^3, x, 2, 65219/(128*(1 - 2*x)^2) - 144837/(64*(1 - 2*x)) - (5695*x)/4 - (10425*x^2)/32 - (375*x^3)/8 - (64317*Log[1 - 2*x])/32}
{((2 + 3*x)*(3 + 5*x)^3)/(1 - 2*x)^3, x, 2, 9317/(64*(1 - 2*x)^2) - 8349/(16*(1 - 2*x)) - (2975*x)/16 - (375*x^2)/16 - (2805*Log[1 - 2*x])/8}
{(3 + 5*x)^3/(1 - 2*x)^3, x, 2, 1331/(32*(1 - 2*x)^2) - 1815/(16*(1 - 2*x)) - (125*x)/8 - (825*Log[1 - 2*x])/16}
{(3 + 5*x)^3/((1 - 2*x)^3*(2 + 3*x)), x, 2, 1331/(112*(1 - 2*x)^2) - 1089/(49*(1 - 2*x)) - (14289*Log[1 - 2*x])/2744 - Log[2 + 3*x]/1029}
{(3 + 5*x)^3/((1 - 2*x)^3*(2 + 3*x)^2), x, 2, 1331/(392*(1 - 2*x)^2) - 4719/(1372*(1 - 2*x)) + 1/(1029*(2 + 3*x)) - (33*Log[1 - 2*x])/2401 + (33*Log[2 + 3*x])/2401}
{(3 + 5*x)^3/((1 - 2*x)^3*(2 + 3*x)^3), x, 2, 1331/(1372*(1 - 2*x)^2) - 363/(2401*(1 - 2*x)) + 1/(2058*(2 + 3*x)^2) - 33/(2401*(2 + 3*x)) + (1023*Log[1 - 2*x])/16807 - (1023*Log[2 + 3*x])/16807}
{(3 + 5*x)^3/((1 - 2*x)^3*(2 + 3*x)^4), x, 2, 1331/(4802*(1 - 2*x)^2) + 3267/(16807*(1 - 2*x)) + 1/(3087*(2 + 3*x)^3) - 33/(4802*(2 + 3*x)^2) + 1023/(16807*(2 + 3*x)) - (7755*Log[1 - 2*x])/117649 + (7755*Log[2 + 3*x])/117649}
{(3 + 5*x)^3/((1 - 2*x)^3*(2 + 3*x)^5), x, 2, 1331/(16807*(1 - 2*x)^2) + 14520/(117649*(1 - 2*x)) + 1/(4116*(2 + 3*x)^4) - 11/(2401*(2 + 3*x)^3) + 1023/(33614*(2 + 3*x)^2) - 7755/(117649*(2 + 3*x)) - (59070*Log[1 - 2*x])/823543 + (59070*Log[2 + 3*x])/823543}


(* ::Subsubsection::Closed:: *)
(*n<0*)


{(2 + 3*x)^8/((1 - 2*x)^3*(3 + 5*x)), x, 2, 5764801/(5632*(1 - 2*x)^2) - 188591347/(30976*(1 - 2*x)) - (2941619571*x)/400000 - (110180817*x^2)/40000 - (124416*x^3)/125 - (408969*x^4)/1600 - (6561*x^5)/200 - (2644396573*Log[1 - 2*x])/340736 + Log[3 + 5*x]/20796875}
{(2 + 3*x)^7/((1 - 2*x)^3*(3 + 5*x)), x, 2, 823543/(2816*(1 - 2*x)^2) - 5764801/(3872*(1 - 2*x)) - (26161299*x)/20000 - (792423*x^2)/2000 - (40581*x^3)/400 - (2187*x^4)/160 - (269063263*Log[1 - 2*x])/170368 + Log[3 + 5*x]/4159375}
{(2 + 3*x)^6/((1 - 2*x)^3*(3 + 5*x)), x, 2, 117649/(1408*(1 - 2*x)^2) - 2739541/(7744*(1 - 2*x)) - (102303*x)/500 - (35721*x^2)/800 - (243*x^3)/40 - (12761315*Log[1 - 2*x])/42592 + Log[3 + 5*x]/831875}
{(2 + 3*x)^5/((1 - 2*x)^3*(3 + 5*x)), x, 2, 16807/(704*(1 - 2*x)^2) - 156065/(1936*(1 - 2*x)) - (10287*x)/400 - (243*x^2)/80 - (543655*Log[1 - 2*x])/10648 + Log[3 + 5*x]/166375}
{(2 + 3*x)^4/((1 - 2*x)^3*(3 + 5*x)), x, 2, 2401/(352*(1 - 2*x)^2) - 33271/(1936*(1 - 2*x)) - (81*x)/40 - (153811*Log[1 - 2*x])/21296 + Log[3 + 5*x]/33275}
{(2 + 3*x)^3/((1 - 2*x)^3*(3 + 5*x)), x, 2, 343/(176*(1 - 2*x)^2) - 392/(121*(1 - 2*x)) - (7189*Log[1 - 2*x])/10648 + Log[3 + 5*x]/6655}
{(2 + 3*x)^2/((1 - 2*x)^3*(3 + 5*x)), x, 2, 49/(88*(1 - 2*x)^2) - 217/(484*(1 - 2*x)) - Log[1 - 2*x]/1331 + Log[3 + 5*x]/1331}
{(2 + 3*x)/((1 - 2*x)^3*(3 + 5*x)), x, 2, 7/(44*(1 - 2*x)^2) + 1/(121*(1 - 2*x)) - (5*Log[1 - 2*x])/1331 + (5*Log[3 + 5*x])/1331}
{1/((1 - 2*x)^3*(3 + 5*x)), x, 2, 1/(22*(1 - 2*x)^2) + 5/(121*(1 - 2*x)) - (25*Log[1 - 2*x])/1331 + (25*Log[3 + 5*x])/1331}
{1/((1 - 2*x)^3*(2 + 3*x)*(3 + 5*x)), x, 2, 1/(77*(1 - 2*x)^2) + 136/(5929*(1 - 2*x)) - (6938*Log[1 - 2*x])/456533 - (27*Log[2 + 3*x])/343 + (125*Log[3 + 5*x])/1331}
{1/((1 - 2*x)^3*(2 + 3*x)^2*(3 + 5*x)), x, 2, 2/(539*(1 - 2*x)^2) + 404/(41503*(1 - 2*x)) + 27/(343*(2 + 3*x)) - (27208*Log[1 - 2*x])/3195731 - (1107*Log[2 + 3*x])/2401 + (625*Log[3 + 5*x])/1331}
{1/((1 - 2*x)^3*(2 + 3*x)^3*(3 + 5*x)), x, 2, 4/(3773*(1 - 2*x)^2) + 1072/(290521*(1 - 2*x)) + 27/(686*(2 + 3*x)^2) + 1107/(2401*(2 + 3*x)) - (89792*Log[1 - 2*x])/22370117 - (39393*Log[2 + 3*x])/16807 + (3125*Log[3 + 5*x])/1331}
{1/((1 - 2*x)^3*(2 + 3*x)^4*(3 + 5*x)), x, 2, 8/(26411*(1 - 2*x)^2) + 2672/(2033647*(1 - 2*x)) + 9/(343*(2 + 3*x)^3) + 1107/(4802*(2 + 3*x)^2) + 39393/(16807*(2 + 3*x)) - (267760*Log[1 - 2*x])/156590819 - (1380915*Log[2 + 3*x])/117649 + (15625*Log[3 + 5*x])/1331}


{(2 + 3*x)^8/((1 - 2*x)^3*(3 + 5*x)^2), x, 2, 5764801/(30976*(1 - 2*x)^2) - 79883671/(85184*(1 - 2*x)) - (81001863*x)/100000 - (4863159*x^2)/20000 - (123201*x^3)/2000 - (6561*x^4)/800 - 1/(20796875*(3 + 5*x)) - (1845559863*Log[1 - 2*x])/1874048 + (54*Log[3 + 5*x])/45753125}
{(2 + 3*x)^7/((1 - 2*x)^3*(3 + 5*x)^2), x, 2, 823543/(15488*(1 - 2*x)^2) - 18941489/(85184*(1 - 2*x)) - (1258983*x)/10000 - (108621*x^2)/4000 - (729*x^3)/200 - 1/(4159375*(3 + 5*x)) - (87177909*Log[1 - 2*x])/468512 + (237*Log[3 + 5*x])/45753125}
{(2 + 3*x)^6/((1 - 2*x)^3*(3 + 5*x)^2), x, 2, 117649/(7744*(1 - 2*x)^2) - 67228/(1331*(1 - 2*x)) - (31347*x)/2000 - (729*x^2)/400 - 1/(831875*(3 + 5*x)) - (7383075*Log[1 - 2*x])/234256 + (204*Log[3 + 5*x])/9150625}
{(2 + 3*x)^5/((1 - 2*x)^3*(3 + 5*x)^2), x, 2, 16807/(3872*(1 - 2*x)^2) - 228095/(21296*(1 - 2*x)) - (243*x)/200 - 1/(166375*(3 + 5*x)) - (1034145*Log[1 - 2*x])/234256 + (171*Log[3 + 5*x])/1830125}
{(2 + 3*x)^4/((1 - 2*x)^3*(3 + 5*x)^2), x, 2, 2401/(1936*(1 - 2*x)^2) - 10633/(5324*(1 - 2*x)) - 1/(33275*(3 + 5*x)) - (47481*Log[1 - 2*x])/117128 + (138*Log[3 + 5*x])/366025}
{(2 + 3*x)^3/((1 - 2*x)^3*(3 + 5*x)^2), x, 2, 343/(968*(1 - 2*x)^2) - 1421/(5324*(1 - 2*x)) - 1/(6655*(3 + 5*x)) - (21*Log[1 - 2*x])/14641 + (21*Log[3 + 5*x])/14641}
{(2 + 3*x)^2/((1 - 2*x)^3*(3 + 5*x)^2), x, 2, 49/(484*(1 - 2*x)^2) + 14/(1331*(1 - 2*x)) - 1/(1331*(3 + 5*x)) - (72*Log[1 - 2*x])/14641 + (72*Log[3 + 5*x])/14641}
{(2 + 3*x)/((1 - 2*x)^3*(3 + 5*x)^2), x, 2, 7/(242*(1 - 2*x)^2) + 37/(1331*(1 - 2*x)) - 5/(1331*(3 + 5*x)) - (195*Log[1 - 2*x])/14641 + (195*Log[3 + 5*x])/14641}
{1/((1 - 2*x)^3*(3 + 5*x)^2), x, 2, 1/(121*(1 - 2*x)^2) + 20/(1331*(1 - 2*x)) - 25/(1331*(3 + 5*x)) - (150*Log[1 - 2*x])/14641 + (150*Log[3 + 5*x])/14641}
{1/((1 - 2*x)^3*(2 + 3*x)*(3 + 5*x)^2), x, 2, 2/(847*(1 - 2*x)^2) + 412/(65219*(1 - 2*x)) - 125/(1331*(3 + 5*x)) - (28296*Log[1 - 2*x])/5021863 + (81*Log[2 + 3*x])/343 - (3375*Log[3 + 5*x])/14641}
{1/((1 - 2*x)^3*(2 + 3*x)^2*(3 + 5*x)^2), x, 2, 4/(5929*(1 - 2*x)^2) + 1088/(456533*(1 - 2*x)) - 81/(343*(2 + 3*x)) - 625/(1331*(3 + 5*x)) - (92496*Log[1 - 2*x])/35153041 + (6156*Log[2 + 3*x])/2401 - (37500*Log[3 + 5*x])/14641}
{1/((1 - 2*x)^3*(2 + 3*x)^3*(3 + 5*x)^2), x, 2, 8/(41503*(1 - 2*x)^2) + 2704/(3195731*(1 - 2*x)) - 81/(686*(2 + 3*x)^2) - 6156/(2401*(2 + 3*x)) - 3125/(1331*(3 + 5*x)) - (274224*Log[1 - 2*x])/246071287 + (333639*Log[2 + 3*x])/16807 - (290625*Log[3 + 5*x])/14641}
{1/((1 - 2*x)^3*(2 + 3*x)^4*(3 + 5*x)^2), x, 2, 16/(290521*(1 - 2*x)^2) + 6464/(22370117*(1 - 2*x)) - 27/(343*(2 + 3*x)^3) - 3078/(2401*(2 + 3*x)^2) - 333639/(16807*(2 + 3*x)) - 15625/(1331*(3 + 5*x)) - (761760*Log[1 - 2*x])/1722499009 + (15820110*Log[2 + 3*x])/117649 - (1968750*Log[3 + 5*x])/14641}


{(2 + 3*x)^9/((1 - 2*x)^3*(3 + 5*x)^3), x, 2, 40353607/(340736*(1 - 2*x)^2) - 17294403/(29282*(1 - 2*x)) - (50150097*x)/100000 - (7459857*x^2)/50000 - (373977*x^3)/10000 - (19683*x^4)/4000 - 1/(207968750*(3 + 5*x)^2) - 303/(1143828125*(3 + 5*x)) - (12657032367*Log[1 - 2*x])/20614528 + (8202*Log[3 + 5*x])/2516421875}
{(2 + 3*x)^8/((1 - 2*x)^3*(3 + 5*x)^3), x, 2, 5764801/(170368*(1 - 2*x)^2) - 130943337/(937024*(1 - 2*x)) - (242028*x)/3125 - (330237*x^2)/20000 - (2187*x^3)/1000 - 1/(41593750*(3 + 5*x)^2) - 54/(45753125*(3 + 5*x)) - (595421589*Log[1 - 2*x])/5153632 + (1284*Log[3 + 5*x])/100656875}
{(2 + 3*x)^7/((1 - 2*x)^3*(3 + 5*x)^3), x, 2, 823543/(85184*(1 - 2*x)^2) - 7411887/(234256*(1 - 2*x)) - (95499*x)/10000 - (2187*x^2)/2000 - 1/(8318750*(3 + 5*x)^2) - 237/(45753125*(3 + 5*x)) - (25059237*Log[1 - 2*x])/1288408 + (24279*Log[3 + 5*x])/503284375}
{(2 + 3*x)^6/((1 - 2*x)^3*(3 + 5*x)^3), x, 2, 117649/(42592*(1 - 2*x)^2) - 1563051/(234256*(1 - 2*x)) - (729*x)/1000 - 1/(1663750*(3 + 5*x)^2) - 204/(9150625*(3 + 5*x)) - (6950895*Log[1 - 2*x])/2576816 + (17547*Log[3 + 5*x])/100656875}
{(2 + 3*x)^5/((1 - 2*x)^3*(3 + 5*x)^3), x, 2, 16807/(21296*(1 - 2*x)^2) - 36015/(29282*(1 - 2*x)) - 1/(332750*(3 + 5*x)^2) - 171/(1830125*(3 + 5*x)) - (313845*Log[1 - 2*x])/1288408 + (11904*Log[3 + 5*x])/20131375}
{(2 + 3*x)^4/((1 - 2*x)^3*(3 + 5*x)^3), x, 2, 2401/(10648*(1 - 2*x)^2) - 9261/(58564*(1 - 2*x)) - 1/(66550*(3 + 5*x)^2) - 138/(366025*(3 + 5*x)) - (294*Log[1 - 2*x])/161051 + (294*Log[3 + 5*x])/161051}
{(2 + 3*x)^3/((1 - 2*x)^3*(3 + 5*x)^3), x, 2, 343/(5324*(1 - 2*x)^2) + 147/(14641*(1 - 2*x)) - 1/(13310*(3 + 5*x)^2) - 21/(14641*(3 + 5*x)) - (777*Log[1 - 2*x])/161051 + (777*Log[3 + 5*x])/161051}
{(2 + 3*x)^2/((1 - 2*x)^3*(3 + 5*x)^3), x, 2, 49/(2662*(1 - 2*x)^2) + 273/(14641*(1 - 2*x)) - 1/(2662*(3 + 5*x)^2) - 72/(14641*(3 + 5*x)) - (1509*Log[1 - 2*x])/161051 + (1509*Log[3 + 5*x])/161051}
{(2 + 3*x)/((1 - 2*x)^3*(3 + 5*x)^3), x, 2, 7/(1331*(1 - 2*x)^2) + 144/(14641*(1 - 2*x)) - 5/(2662*(3 + 5*x)^2) - 195/(14641*(3 + 5*x)) - (1110*Log[1 - 2*x])/161051 + (1110*Log[3 + 5*x])/161051}
{1/((1 - 2*x)^3*(3 + 5*x)^3), x, 2, 2/(1331*(1 - 2*x)^2) + 60/(14641*(1 - 2*x)) - 25/(2662*(3 + 5*x)^2) - 150/(14641*(3 + 5*x)) - (600*Log[1 - 2*x])/161051 + (600*Log[3 + 5*x])/161051}
{1/((1 - 2*x)^3*(2 + 3*x)*(3 + 5*x)^3), x, 2, 4/(9317*(1 - 2*x)^2) + 1104/(717409*(1 - 2*x)) - 125/(2662*(3 + 5*x)^2) + 3375/(14641*(3 + 5*x)) - (95232*Log[1 - 2*x])/55240493 - (243*Log[2 + 3*x])/343 + (114375*Log[3 + 5*x])/161051}
{1/((1 - 2*x)^3*(2 + 3*x)^2*(3 + 5*x)^3), x, 2, 8/(65219*(1 - 2*x)^2) + 2736/(5021863*(1 - 2*x)) + 243/(343*(2 + 3*x)) - 625/(2662*(3 + 5*x)^2) + 37500/(14641*(3 + 5*x)) - (280752*Log[1 - 2*x])/386683451 - (26973*Log[2 + 3*x])/2401 + (1809375*Log[3 + 5*x])/161051}
{1/((1 - 2*x)^3*(2 + 3*x)^3*(3 + 5*x)^3), x, 2, 16/(456533*(1 - 2*x)^2) + 6528/(35153041*(1 - 2*x)) + 243/(686*(2 + 3*x)^2) + 26973/(2401*(2 + 3*x)) - 3125/(2662*(3 + 5*x)^2) + 290625/(14641*(3 + 5*x)) - (776928*Log[1 - 2*x])/2706784157 - (1944972*Log[2 + 3*x])/16807 + (18637500*Log[3 + 5*x])/161051}
{1/((1 - 2*x)^3*(2 + 3*x)^4*(3 + 5*x)^3), x, 2, 32/(3195731*(1 - 2*x)^2) + 15168/(246071287*(1 - 2*x)) + 81/(343*(2 + 3*x)^3) + 26973/(4802*(2 + 3*x)^2) + 1944972/(16807*(2 + 3*x)) - 15625/(2662*(3 + 5*x)^2) + 1968750/(14641*(3 + 5*x)) - (2054400*Log[1 - 2*x])/18947489099 - (115534350*Log[2 + 3*x])/117649 + (158156250*Log[3 + 5*x])/161051}


(* ::Section::Closed:: *)
(*Integrands of the form (a+b x)^m (c+d x)^n (e+f x)^(p/2)*)


(* ::Subsection::Closed:: *)
(*Integrands of the form (a+b x)^m (c+d x)^n (e+f x)^(1/2)*)


(* ::Subsubsection::Closed:: *)
(*n>0*)


{Sqrt[1 - 2*x]*(2 + 3*x)^6*(3 + 5*x), x, 2, (-1294139*(1 - 2*x)^(3/2))/384 + (3916031*(1 - 2*x)^(5/2))/640 - (725445*(1 - 2*x)^(7/2))/128 + (406455*(1 - 2*x)^(9/2))/128 - (1580985*(1 - 2*x)^(11/2))/1408 + (409941*(1 - 2*x)^(13/2))/1664 - (19683*(1 - 2*x)^(15/2))/640 + (3645*(1 - 2*x)^(17/2))/2176}
{Sqrt[1 - 2*x]*(2 + 3*x)^5*(3 + 5*x), x, 2, (-184877*(1 - 2*x)^(3/2))/192 + (12005*(1 - 2*x)^(5/2))/8 - (74235*(1 - 2*x)^(7/2))/64 + (4165*(1 - 2*x)^(9/2))/8 - (97335*(1 - 2*x)^(11/2))/704 + (81*(1 - 2*x)^(13/2))/4 - (81*(1 - 2*x)^(15/2))/64}
{Sqrt[1 - 2*x]*(2 + 3*x)^4*(3 + 5*x), x, 2, (-26411*(1 - 2*x)^(3/2))/96 + (57281*(1 - 2*x)^(5/2))/160 - (3549*(1 - 2*x)^(7/2))/16 + (1197*(1 - 2*x)^(9/2))/16 - (4671*(1 - 2*x)^(11/2))/352 + (405*(1 - 2*x)^(13/2))/416}
{Sqrt[1 - 2*x]*(2 + 3*x)^3*(3 + 5*x), x, 2, (-3773*(1 - 2*x)^(3/2))/48 + (3283*(1 - 2*x)^(5/2))/40 - (153*(1 - 2*x)^(7/2))/4 + (69*(1 - 2*x)^(9/2))/8 - (135*(1 - 2*x)^(11/2))/176}
{Sqrt[1 - 2*x]*(2 + 3*x)^2*(3 + 5*x), x, 2, (-539*(1 - 2*x)^(3/2))/24 + (707*(1 - 2*x)^(5/2))/40 - (309*(1 - 2*x)^(7/2))/56 + (5*(1 - 2*x)^(9/2))/8}
{Sqrt[1 - 2*x]*(2 + 3*x)*(3 + 5*x), x, 2, (-77*(1 - 2*x)^(3/2))/12 + (17*(1 - 2*x)^(5/2))/5 - (15*(1 - 2*x)^(7/2))/28}
{Sqrt[1 - 2*x]*(3 + 5*x), x, 2, (-11*(1 - 2*x)^(3/2))/6 + (1 - 2*x)^(5/2)/2}
{(Sqrt[1 - 2*x]*(3 + 5*x))/(2 + 3*x), x, 3, (-2*Sqrt[1 - 2*x])/9 - (5*(1 - 2*x)^(3/2))/9 + (2*Sqrt[7/3]*ArcTanh[Sqrt[3/7]*Sqrt[1 - 2*x]])/9}
{(Sqrt[1 - 2*x]*(3 + 5*x))/(2 + 3*x)^2, x, 3, (8*Sqrt[1 - 2*x])/7 + (1 - 2*x)^(3/2)/(21*(2 + 3*x)) - (8*ArcTanh[Sqrt[3/7]*Sqrt[1 - 2*x]])/Sqrt[21]}
{(Sqrt[1 - 2*x]*(3 + 5*x))/(2 + 3*x)^3, x, 3, (1 - 2*x)^(3/2)/(42*(2 + 3*x)^2) - (23*Sqrt[1 - 2*x])/(42*(2 + 3*x)) + (23*ArcTanh[Sqrt[3/7]*Sqrt[1 - 2*x]])/(21*Sqrt[21])}
{(Sqrt[1 - 2*x]*(3 + 5*x))/(2 + 3*x)^4, x, 4, (1 - 2*x)^(3/2)/(63*(2 + 3*x)^3) - (17*Sqrt[1 - 2*x])/(63*(2 + 3*x)^2) + (17*Sqrt[1 - 2*x])/(441*(2 + 3*x)) + (34*ArcTanh[Sqrt[3/7]*Sqrt[1 - 2*x]])/(441*Sqrt[21])}
{(Sqrt[1 - 2*x]*(3 + 5*x))/(2 + 3*x)^5, x, 5, (1 - 2*x)^(3/2)/(84*(2 + 3*x)^4) - (5*Sqrt[1 - 2*x])/(28*(2 + 3*x)^3) + (5*Sqrt[1 - 2*x])/(392*(2 + 3*x)^2) + (15*Sqrt[1 - 2*x])/(2744*(2 + 3*x)) + (5*Sqrt[3/7]*ArcTanh[Sqrt[3/7]*Sqrt[1 - 2*x]])/1372}
{(Sqrt[1 - 2*x]*(3 + 5*x))/(2 + 3*x)^6, x, 6, (1 - 2*x)^(3/2)/(105*(2 + 3*x)^5) - (2*Sqrt[1 - 2*x])/(15*(2 + 3*x)^4) + (2*Sqrt[1 - 2*x])/(315*(2 + 3*x)^3) + Sqrt[1 - 2*x]/(441*(2 + 3*x)^2) + Sqrt[1 - 2*x]/(1029*(2 + 3*x)) + (2*ArcTanh[Sqrt[3/7]*Sqrt[1 - 2*x]])/(1029*Sqrt[21])}


{Sqrt[1 - 2*x]*(2 + 3*x)^4*(3 + 5*x)^2, x, 2, (-(290521/192))*(1 - 2*x)^(3/2) + (381073/160)*(1 - 2*x)^(5/2) - (118993/64)*(1 - 2*x)^(7/2) + (40453/48)*(1 - 2*x)^(9/2) - (159111/704)*(1 - 2*x)^(11/2) + (13905/416)*(1 - 2*x)^(13/2) - (135/64)*(1 - 2*x)^(15/2)}
{Sqrt[1 - 2*x]*(2 + 3*x)^3*(3 + 5*x)^2, x, 2, (-(41503/96))*(1 - 2*x)^(3/2) + (91091/160)*(1 - 2*x)^(5/2) - (5711/16)*(1 - 2*x)^(7/2) + (1949/16)*(1 - 2*x)^(9/2) - (7695/352)*(1 - 2*x)^(11/2) + (675/416)*(1 - 2*x)^(13/2)}
{Sqrt[1 - 2*x]*(2 + 3*x)^2*(3 + 5*x)^2, x, 2, (-(5929/48))*(1 - 2*x)^(3/2) + (1309/10)*(1 - 2*x)^(5/2) - (3467/56)*(1 - 2*x)^(7/2) + (85/6)*(1 - 2*x)^(9/2) - (225/176)*(1 - 2*x)^(11/2)}
{Sqrt[1 - 2*x]*(2 + 3*x)*(3 + 5*x)^2, x, 2, (-847*(1 - 2*x)^(3/2))/24 + (1133*(1 - 2*x)^(5/2))/40 - (505*(1 - 2*x)^(7/2))/56 + (25*(1 - 2*x)^(9/2))/24}
{Sqrt[1 - 2*x]*(3 + 5*x)^2, x, 2, (-121*(1 - 2*x)^(3/2))/12 + (11*(1 - 2*x)^(5/2))/2 - (25*(1 - 2*x)^(7/2))/28}
{(Sqrt[1 - 2*x]*(3 + 5*x)^2)/(2 + 3*x), x, 4, (2/27)*Sqrt[1 - 2*x] - (28/27)*(1 - 2*x)^(3/2) - (1/3)*(1 - 2*x)^(3/2)*(3 + 5*x) - (2/27)*Sqrt[7/3]*ArcTanh[Sqrt[3/7]*Sqrt[1 - 2*x]]}
{(Sqrt[1 - 2*x]*(3 + 5*x)^2)/(2 + 3*x)^2, x, 4, (-(142/189))*Sqrt[1 - 2*x] - (25/27)*(1 - 2*x)^(3/2) - (1 - 2*x)^(3/2)/(63*(2 + 3*x)) + (142*ArcTanh[Sqrt[3/7]*Sqrt[1 - 2*x]])/(27*Sqrt[21])}
{(Sqrt[1 - 2*x]*(3 + 5*x)^2)/(2 + 3*x)^3, x, 4, (863/441)*Sqrt[1 - 2*x] - (1 - 2*x)^(3/2)/(126*(2 + 3*x)^2) + (139*(1 - 2*x)^(3/2))/(882*(2 + 3*x)) - (863*ArcTanh[Sqrt[3/7]*Sqrt[1 - 2*x]])/(63*Sqrt[21])}
{(Sqrt[1 - 2*x]*(3 + 5*x)^2)/(2 + 3*x)^4, x, 4, -((1 - 2*x)^(3/2)/(189*(2 + 3*x)^3)) + (23*(1 - 2*x)^(3/2))/(294*(2 + 3*x)^2) - (2381*Sqrt[1 - 2*x])/(2646*(2 + 3*x)) + (2381*ArcTanh[Sqrt[3/7]*Sqrt[1 - 2*x]])/(1323*Sqrt[21])}
{(Sqrt[1 - 2*x]*(3 + 5*x)^2)/(2 + 3*x)^5, x, 5, -((1 - 2*x)^(3/2)/(252*(2 + 3*x)^4)) + (275*(1 - 2*x)^(3/2))/(5292*(2 + 3*x)^3) - (4625*Sqrt[1 - 2*x])/(10584*(2 + 3*x)^2) + (4625*Sqrt[1 - 2*x])/(74088*(2 + 3*x)) + (4625*ArcTanh[Sqrt[3/7]*Sqrt[1 - 2*x]])/(37044*Sqrt[21])}
{(Sqrt[1 - 2*x]*(3 + 5*x)^2)/(2 + 3*x)^6, x, 6, -((1 - 2*x)^(3/2)/(315*(2 + 3*x)^5)) + (7*(1 - 2*x)^(3/2))/(180*(2 + 3*x)^4) - (31*Sqrt[1 - 2*x])/(108*(2 + 3*x)^3) + (31*Sqrt[1 - 2*x])/(1512*(2 + 3*x)^2) + (31*Sqrt[1 - 2*x])/(3528*(2 + 3*x)) + (31*ArcTanh[Sqrt[3/7]*Sqrt[1 - 2*x]])/(1764*Sqrt[21])}
{(Sqrt[1 - 2*x]*(3 + 5*x)^2)/(2 + 3*x)^7, x, 7, -((1 - 2*x)^(3/2)/(378*(2 + 3*x)^6)) + (137*(1 - 2*x)^(3/2))/(4410*(2 + 3*x)^5) - (1613*Sqrt[1 - 2*x])/(7560*(2 + 3*x)^4) + (1613*Sqrt[1 - 2*x])/(158760*(2 + 3*x)^3) + (1613*Sqrt[1 - 2*x])/(444528*(2 + 3*x)^2) + (1613*Sqrt[1 - 2*x])/(1037232*(2 + 3*x)) + (1613*ArcTanh[Sqrt[3/7]*Sqrt[1 - 2*x]])/(518616*Sqrt[21])}


{Sqrt[1 - 2*x]*(2 + 3*x)^4*(3 + 5*x)^3, x, 2, (-(3195731/384))*(1 - 2*x)^(3/2) + (9836211/640)*(1 - 2*x)^(5/2) - (1853313/128)*(1 - 2*x)^(7/2) + (9504551*(1 - 2*x)^(9/2))/1152 - (4177401*(1 - 2*x)^(11/2))/1408 + (1101465*(1 - 2*x)^(13/2))/1664 - (10755/128)*(1 - 2*x)^(15/2) + (10125*(1 - 2*x)^(17/2))/2176}
{Sqrt[1 - 2*x]*(2 + 3*x)^3*(3 + 5*x)^3, x, 2, (-(456533/192))*(1 - 2*x)^(3/2) + (302379/80)*(1 - 2*x)^(5/2) - (190707/64)*(1 - 2*x)^(7/2) + (98209/72)*(1 - 2*x)^(9/2) - (260055/704)*(1 - 2*x)^(11/2) + (11475/208)*(1 - 2*x)^(13/2) - (225/64)*(1 - 2*x)^(15/2)}
{Sqrt[1 - 2*x]*(2 + 3*x)^2*(3 + 5*x)^3, x, 2, (-(65219/96))*(1 - 2*x)^(3/2) + (144837/160)*(1 - 2*x)^(5/2) - (64317/112)*(1 - 2*x)^(7/2) + (28555/144)*(1 - 2*x)^(9/2) - (12675/352)*(1 - 2*x)^(11/2) + (1125/416)*(1 - 2*x)^(13/2)}
{Sqrt[1 - 2*x]*(2 + 3*x)*(3 + 5*x)^3, x, 2, (-9317*(1 - 2*x)^(3/2))/48 + (8349*(1 - 2*x)^(5/2))/40 - (2805*(1 - 2*x)^(7/2))/28 + (1675*(1 - 2*x)^(9/2))/72 - (375*(1 - 2*x)^(11/2))/176}
{Sqrt[1 - 2*x]*(3 + 5*x)^3, x, 2, (-1331*(1 - 2*x)^(3/2))/24 + (363*(1 - 2*x)^(5/2))/8 - (825*(1 - 2*x)^(7/2))/56 + (125*(1 - 2*x)^(9/2))/72}
{(Sqrt[1 - 2*x]*(3 + 5*x)^3)/(2 + 3*x), x, 5, (-6946*Sqrt[1 - 2*x])/945 - (47*Sqrt[1 - 2*x]*(3 + 5*x)^2)/315 + (2*Sqrt[1 - 2*x]*(3 + 5*x)^3)/21 - (Sqrt[1 - 2*x]*(1333 + 1877*x))/567 + (2*Sqrt[7/3]*ArcTanh[Sqrt[3/7]*Sqrt[1 - 2*x]])/81}
{(Sqrt[1 - 2*x]*(3 + 5*x)^3)/(2 + 3*x)^2, x, 5, (-124*Sqrt[1 - 2*x])/27 + (7*Sqrt[1 - 2*x]*(3 + 5*x)^2)/9 - (Sqrt[1 - 2*x]*(3 + 5*x)^3)/(3*(2 + 3*x)) - (10*Sqrt[1 - 2*x]*(5 + 34*x))/81 - (212*ArcTanh[Sqrt[3/7]*Sqrt[1 - 2*x]])/(81*Sqrt[21])}
{(Sqrt[1 - 2*x]*(3 + 5*x)^3)/(2 + 3*x)^3, x, 5, (115*Sqrt[1 - 2*x])/27 - (5*(643 - 2815*x)*Sqrt[1 - 2*x])/1134 - (53*Sqrt[1 - 2*x]*(3 + 5*x)^2)/(63*(2 + 3*x)) - (Sqrt[1 - 2*x]*(3 + 5*x)^3)/(6*(2 + 3*x)^2) + (7559*ArcTanh[Sqrt[3/7]*Sqrt[1 - 2*x]])/(567*Sqrt[21])}
{(Sqrt[1 - 2*x]*(3 + 5*x)^3)/(2 + 3*x)^4, x, 5, (23710*Sqrt[1 - 2*x])/3969 - (3796*Sqrt[1 - 2*x]*(3 + 5*x))/(3969*(2 + 3*x)) - (53*Sqrt[1 - 2*x]*(3 + 5*x)^2)/(189*(2 + 3*x)^2) - (Sqrt[1 - 2*x]*(3 + 5*x)^3)/(9*(2 + 3*x)^3) - (92996*ArcTanh[Sqrt[3/7]*Sqrt[1 - 2*x]])/(3969*Sqrt[21])}
{(Sqrt[1 - 2*x]*(3 + 5*x)^3)/(2 + 3*x)^5, x, 5, (-48005*Sqrt[1 - 2*x])/(111132*(2 + 3*x)) - (7625*Sqrt[1 - 2*x]*(3 + 5*x))/(31752*(2 + 3*x)^2) - (53*Sqrt[1 - 2*x]*(3 + 5*x)^2)/(378*(2 + 3*x)^3) - (Sqrt[1 - 2*x]*(3 + 5*x)^3)/(12*(2 + 3*x)^4) + (328715*ArcTanh[Sqrt[3/7]*Sqrt[1 - 2*x]])/(111132*Sqrt[21])}
{(Sqrt[1 - 2*x]*(3 + 5*x)^3)/(2 + 3*x)^6, x, 6, (-475*Sqrt[1 - 2*x])/(5292*(2 + 3*x)^2) + (11237*Sqrt[1 - 2*x])/(111132*(2 + 3*x)) - (547*Sqrt[1 - 2*x]*(3 + 5*x))/(5670*(2 + 3*x)^3) - (53*Sqrt[1 - 2*x]*(3 + 5*x)^2)/(630*(2 + 3*x)^4) - (Sqrt[1 - 2*x]*(3 + 5*x)^3)/(15*(2 + 3*x)^5) + (11237*ArcTanh[Sqrt[3/7]*Sqrt[1 - 2*x]])/(55566*Sqrt[21])}
{(Sqrt[1 - 2*x]*(3 + 5*x)^3)/(2 + 3*x)^7, x, 7, (-1861*Sqrt[1 - 2*x])/(59535*(2 + 3*x)^3) + (43957*Sqrt[1 - 2*x])/(1333584*(2 + 3*x)^2) + (43957*Sqrt[1 - 2*x])/(3111696*(2 + 3*x)) - (7691*Sqrt[1 - 2*x]*(3 + 5*x))/(158760*(2 + 3*x)^4) - (53*Sqrt[1 - 2*x]*(3 + 5*x)^2)/(945*(2 + 3*x)^5) - (Sqrt[1 - 2*x]*(3 + 5*x)^3)/(18*(2 + 3*x)^6) + (43957*ArcTanh[Sqrt[3/7]*Sqrt[1 - 2*x]])/(1555848*Sqrt[21])}
{(Sqrt[1 - 2*x]*(3 + 5*x)^3)/(2 + 3*x)^8, x, 8, (-13676*Sqrt[1 - 2*x])/(972405*(2 + 3*x)^4) + (47434*Sqrt[1 - 2*x])/(2917215*(2 + 3*x)^3) + (23717*Sqrt[1 - 2*x])/(4084101*(2 + 3*x)^2) + (23717*Sqrt[1 - 2*x])/(9529569*(2 + 3*x)) - (3862*Sqrt[1 - 2*x]*(3 + 5*x))/(138915*(2 + 3*x)^5) - (53*Sqrt[1 - 2*x]*(3 + 5*x)^2)/(1323*(2 + 3*x)^6) - (Sqrt[1 - 2*x]*(3 + 5*x)^3)/(21*(2 + 3*x)^7) + (47434*ArcTanh[Sqrt[3/7]*Sqrt[1 - 2*x]])/(9529569*Sqrt[21])}


(* ::Subsubsection::Closed:: *)
(*n<0*)


{(Sqrt[1 - 2*x]*(2 + 3*x)^4)/(3 + 5*x), x, 6, (-93922*Sqrt[1 - 2*x])/28125 - (107*Sqrt[1 - 2*x]*(2 + 3*x))/225 - (184*Sqrt[1 - 2*x]*(2 + 3*x)^2)/1875 - (17*Sqrt[1 - 2*x]*(2 + 3*x)^3)/1575 + (2*Sqrt[1 - 2*x]*(2 + 3*x)^4)/45 - (2*Sqrt[11/5]*ArcTanh[Sqrt[5/11]*Sqrt[1 - 2*x]])/3125}
{(Sqrt[1 - 2*x]*(2 + 3*x)^3)/(3 + 5*x), x, 5, (-922*Sqrt[1 - 2*x])/625 - (3*Sqrt[1 - 2*x]*(2 + 3*x)^2)/125 + (2*Sqrt[1 - 2*x]*(2 + 3*x)^3)/35 - (Sqrt[1 - 2*x]*(236 + 375*x))/625 - (2*Sqrt[11/5]*ArcTanh[Sqrt[5/11]*Sqrt[1 - 2*x]])/625}
{(Sqrt[1 - 2*x]*(2 + 3*x)^2)/(3 + 5*x), x, 4, (2/125)*Sqrt[1 - 2*x] - (8/25)*(1 - 2*x)^(3/2) - (3/25)*(1 - 2*x)^(3/2)*(2 + 3*x) - (2/125)*Sqrt[11/5]*ArcTanh[Sqrt[5/11]*Sqrt[1 - 2*x]]}
{(Sqrt[1 - 2*x]*(2 + 3*x))/(3 + 5*x), x, 3, (2*Sqrt[1 - 2*x])/25 - (1 - 2*x)^(3/2)/5 - (2*Sqrt[11/5]*ArcTanh[Sqrt[5/11]*Sqrt[1 - 2*x]])/25}
{Sqrt[1 - 2*x]/(3 + 5*x), x, 2, (2*Sqrt[1 - 2*x])/5 - (2*Sqrt[11/5]*ArcTanh[Sqrt[5/11]*Sqrt[1 - 2*x]])/5}
{Sqrt[1 - 2*x]/((2 + 3*x)*(3 + 5*x)), x, 3, 2*Sqrt[7/3]*ArcTanh[Sqrt[3/7]*Sqrt[1 - 2*x]] - 2*Sqrt[11/5]*ArcTanh[Sqrt[5/11]*Sqrt[1 - 2*x]]}
{Sqrt[1 - 2*x]/((2 + 3*x)^2*(3 + 5*x)), x, 4, Sqrt[1 - 2*x]/(2 + 3*x) + (68*ArcTanh[Sqrt[3/7]*Sqrt[1 - 2*x]])/Sqrt[21] - 2*Sqrt[55]*ArcTanh[Sqrt[5/11]*Sqrt[1 - 2*x]]}
{Sqrt[1 - 2*x]/((2 + 3*x)^3*(3 + 5*x)), x, 5, Sqrt[1 - 2*x]/(2*(2 + 3*x)^2) + (69*Sqrt[1 - 2*x])/(14*(2 + 3*x)) + (793*Sqrt[3/7]*ArcTanh[Sqrt[3/7]*Sqrt[1 - 2*x]])/7 - 10*Sqrt[55]*ArcTanh[Sqrt[5/11]*Sqrt[1 - 2*x]]}
{Sqrt[1 - 2*x]/((2 + 3*x)^4*(3 + 5*x)), x, 6, Sqrt[1 - 2*x]/(3*(2 + 3*x)^3) + (52*Sqrt[1 - 2*x])/(21*(2 + 3*x)^2) + (1207*Sqrt[1 - 2*x])/(49*(2 + 3*x)) + (83264*ArcTanh[Sqrt[3/7]*Sqrt[1 - 2*x]])/(49*Sqrt[21]) - 50*Sqrt[55]*ArcTanh[Sqrt[5/11]*Sqrt[1 - 2*x]]}
{Sqrt[1 - 2*x]/((2 + 3*x)^5*(3 + 5*x)), x, 7, Sqrt[1 - 2*x]/(4*(2 + 3*x)^4) + (139*Sqrt[1 - 2*x])/(84*(2 + 3*x)^3) + (14555*Sqrt[1 - 2*x])/(1176*(2 + 3*x)^2) + (337955*Sqrt[1 - 2*x])/(2744*(2 + 3*x)) + (11656955*ArcTanh[Sqrt[3/7]*Sqrt[1 - 2*x]])/(1372*Sqrt[21]) - 250*Sqrt[55]*ArcTanh[Sqrt[5/11]*Sqrt[1 - 2*x]]}


{(Sqrt[1 - 2*x]*(2 + 3*x)^5)/(3 + 5*x)^2, x, 7, (-35128*Sqrt[1 - 2*x])/15625 - (172*Sqrt[1 - 2*x]*(2 + 3*x)^2)/3125 + (64*Sqrt[1 - 2*x]*(2 + 3*x)^3)/2625 + (11*Sqrt[1 - 2*x]*(2 + 3*x)^4)/75 - (Sqrt[1 - 2*x]*(2 + 3*x)^5)/(5*(3 + 5*x)) - (4*Sqrt[1 - 2*x]*(2216 + 3625*x))/15625 - (328*ArcTanh[Sqrt[5/11]*Sqrt[1 - 2*x]])/(15625*Sqrt[55])}
{(Sqrt[1 - 2*x]*(2 + 3*x)^4)/(3 + 5*x)^2, x, 6, (-3018*Sqrt[1 - 2*x])/3125 - (3*Sqrt[1 - 2*x]*(2 + 3*x))/25 + (12*Sqrt[1 - 2*x]*(2 + 3*x)^2)/625 + (27*Sqrt[1 - 2*x]*(2 + 3*x)^3)/175 - (Sqrt[1 - 2*x]*(2 + 3*x)^4)/(5*(3 + 5*x)) - (262*ArcTanh[Sqrt[5/11]*Sqrt[1 - 2*x]])/(3125*Sqrt[55])}
{(Sqrt[1 - 2*x]*(2 + 3*x)^3)/(3 + 5*x)^2, x, 5, (-294*Sqrt[1 - 2*x])/625 + (21*Sqrt[1 - 2*x]*(2 + 3*x)^2)/125 - (Sqrt[1 - 2*x]*(2 + 3*x)^3)/(5*(3 + 5*x)) - (196*ArcTanh[Sqrt[5/11]*Sqrt[1 - 2*x]])/(625*Sqrt[55])}
{(Sqrt[1 - 2*x]*(2 + 3*x)^2)/(3 + 5*x)^2, x, 4, (26/275)*Sqrt[1 - 2*x] - (3/25)*(1 - 2*x)^(3/2) - (1 - 2*x)^(3/2)/(275*(3 + 5*x)) - (26*ArcTanh[Sqrt[5/11]*Sqrt[1 - 2*x]])/(25*Sqrt[55])}
{(Sqrt[1 - 2*x]*(2 + 3*x))/(3 + 5*x)^2, x, 3, (64*Sqrt[1 - 2*x])/275 - (1 - 2*x)^(3/2)/(55*(3 + 5*x)) - (64*ArcTanh[Sqrt[5/11]*Sqrt[1 - 2*x]])/(25*Sqrt[55])}
{Sqrt[1 - 2*x]/(3 + 5*x)^2, x, 2, -Sqrt[1 - 2*x]/(5*(3 + 5*x)) + (2*ArcTanh[Sqrt[5/11]*Sqrt[1 - 2*x]])/(5*Sqrt[55])}
{Sqrt[1 - 2*x]/((2 + 3*x)*(3 + 5*x)^2), x, 4, -(Sqrt[1 - 2*x]/(3 + 5*x)) - 2*Sqrt[21]*ArcTanh[Sqrt[3/7]*Sqrt[1 - 2*x]] + (68*ArcTanh[Sqrt[5/11]*Sqrt[1 - 2*x]])/Sqrt[55]}
{Sqrt[1 - 2*x]/((2 + 3*x)^2*(3 + 5*x)^2), x, 5, (-10*Sqrt[1 - 2*x])/(3 + 5*x) + Sqrt[1 - 2*x]/((2 + 3*x)*(3 + 5*x)) - 138*Sqrt[3/7]*ArcTanh[Sqrt[3/7]*Sqrt[1 - 2*x]] + 134*Sqrt[5/11]*ArcTanh[Sqrt[5/11]*Sqrt[1 - 2*x]]}
{Sqrt[1 - 2*x]/((2 + 3*x)^3*(3 + 5*x)^2), x, 6, (-1045*Sqrt[1 - 2*x])/(14*(3 + 5*x)) + Sqrt[1 - 2*x]/(2*(2 + 3*x)^2*(3 + 5*x)) + (52*Sqrt[1 - 2*x])/(7*(2 + 3*x)*(3 + 5*x)) - (7209*Sqrt[3/7]*ArcTanh[Sqrt[3/7]*Sqrt[1 - 2*x]])/7 + 1000*Sqrt[5/11]*ArcTanh[Sqrt[5/11]*Sqrt[1 - 2*x]]}
{Sqrt[1 - 2*x]/((2 + 3*x)^4*(3 + 5*x)^2), x, 7, (-48645*Sqrt[1 - 2*x])/(98*(3 + 5*x)) + Sqrt[1 - 2*x]/(3*(2 + 3*x)^3*(3 + 5*x)) + (139*Sqrt[1 - 2*x])/(42*(2 + 3*x)^2*(3 + 5*x)) + (7261*Sqrt[1 - 2*x])/(147*(2 + 3*x)*(3 + 5*x)) - (335579*Sqrt[3/7]*ArcTanh[Sqrt[3/7]*Sqrt[1 - 2*x]])/49 + 6650*Sqrt[5/11]*ArcTanh[Sqrt[5/11]*Sqrt[1 - 2*x]]}


{(Sqrt[1 - 2*x]*(2 + 3*x)^4)/(3 + 5*x)^3, x, 6, (-10017*Sqrt[1 - 2*x])/34375 + (21*Sqrt[1 - 2*x]*(2 + 3*x))/550 + (1428*Sqrt[1 - 2*x]*(2 + 3*x)^2)/6875 - (Sqrt[1 - 2*x]*(2 + 3*x)^4)/(10*(3 + 5*x)^2) - (131*Sqrt[1 - 2*x]*(2 + 3*x)^3)/(550*(3 + 5*x)) - (12803*ArcTanh[Sqrt[5/11]*Sqrt[1 - 2*x]])/(34375*Sqrt[55])}
{(Sqrt[1 - 2*x]*(2 + 3*x)^3)/(3 + 5*x)^3, x, 5, (623*Sqrt[1 - 2*x])/1375 - (7*(46 - 225*x)*Sqrt[1 - 2*x])/2750 - (Sqrt[1 - 2*x]*(2 + 3*x)^3)/(10*(3 + 5*x)^2) - (49*Sqrt[1 - 2*x]*(2 + 3*x)^2)/(275*(3 + 5*x)) - (1267*ArcTanh[Sqrt[5/11]*Sqrt[1 - 2*x]])/(1375*Sqrt[55])}
{(Sqrt[1 - 2*x]*(2 + 3*x)^2)/(3 + 5*x)^3, x, 4, (409*Sqrt[1 - 2*x])/3025 - (1 - 2*x)^(3/2)/(550*(3 + 5*x)^2) - (133*(1 - 2*x)^(3/2))/(6050*(3 + 5*x)) - (409*ArcTanh[Sqrt[5/11]*Sqrt[1 - 2*x]])/(275*Sqrt[55])}
{(Sqrt[1 - 2*x]*(2 + 3*x))/(3 + 5*x)^3, x, 3, -(1 - 2*x)^(3/2)/(110*(3 + 5*x)^2) - (67*Sqrt[1 - 2*x])/(550*(3 + 5*x)) + (67*ArcTanh[Sqrt[5/11]*Sqrt[1 - 2*x]])/(275*Sqrt[55])}
{Sqrt[1 - 2*x]/(3 + 5*x)^3, x, 3, -Sqrt[1 - 2*x]/(10*(3 + 5*x)^2) + Sqrt[1 - 2*x]/(110*(3 + 5*x)) + ArcTanh[Sqrt[5/11]*Sqrt[1 - 2*x]]/(55*Sqrt[55])}
{Sqrt[1 - 2*x]/((2 + 3*x)*(3 + 5*x)^3), x, 5, -Sqrt[1 - 2*x]/(2*(3 + 5*x)^2) + (67*Sqrt[1 - 2*x])/(22*(3 + 5*x)) + 6*Sqrt[21]*ArcTanh[Sqrt[3/7]*Sqrt[1 - 2*x]] - (2243*ArcTanh[Sqrt[5/11]*Sqrt[1 - 2*x]])/(11*Sqrt[55])}
{Sqrt[1 - 2*x]/((2 + 3*x)^2*(3 + 5*x)^3), x, 6, (-15*Sqrt[1 - 2*x])/(2*(3 + 5*x)^2) + Sqrt[1 - 2*x]/((2 + 3*x)*(3 + 5*x)^2) + (995*Sqrt[1 - 2*x])/(22*(3 + 5*x)) + 624*Sqrt[3/7]*ArcTanh[Sqrt[3/7]*Sqrt[1 - 2*x]] - (6665*Sqrt[5/11]*ArcTanh[Sqrt[5/11]*Sqrt[1 - 2*x]])/11}
{Sqrt[1 - 2*x]/((2 + 3*x)^3*(3 + 5*x)^3), x, 7, (-1045*Sqrt[1 - 2*x])/(14*(3 + 5*x)^2) + Sqrt[1 - 2*x]/(2*(2 + 3*x)^2*(3 + 5*x)^2) + (139*Sqrt[1 - 2*x])/(14*(2 + 3*x)*(3 + 5*x)^2) + (34655*Sqrt[1 - 2*x])/(77*(3 + 5*x)) + (43467*Sqrt[3/7]*ArcTanh[Sqrt[3/7]*Sqrt[1 - 2*x]])/7 - (66325*Sqrt[5/11]*ArcTanh[Sqrt[5/11]*Sqrt[1 - 2*x]])/11}
{Sqrt[1 - 2*x]/((2 + 3*x)^4*(3 + 5*x)^3), x, 8, (-182335*Sqrt[1 - 2*x])/(294*(3 + 5*x)^2) + Sqrt[1 - 2*x]/(3*(2 + 3*x)^3*(3 + 5*x)^2) + (29*Sqrt[1 - 2*x])/(7*(2 + 3*x)^2*(3 + 5*x)^2) + (4042*Sqrt[1 - 2*x])/(49*(2 + 3*x)*(3 + 5*x)^2) + (4031135*Sqrt[1 - 2*x])/(1078*(3 + 5*x)) + (2528082*Sqrt[3/7]*ArcTanh[Sqrt[3/7]*Sqrt[1 - 2*x]])/49 - (551075*Sqrt[5/11]*ArcTanh[Sqrt[5/11]*Sqrt[1 - 2*x]])/11}


(* ::Subsection::Closed:: *)
(*Integrands of the form (a+b x)^m (c+d x)^n (e+f x)^(3/2)*)


(* ::Subsubsection::Closed:: *)
(*n>0*)


{(1 - 2*x)^(3/2)*(2 + 3*x)^6*(3 + 5*x), x, 2, (-1294139*(1 - 2*x)^(5/2))/640 + (559433*(1 - 2*x)^(7/2))/128 - (564235*(1 - 2*x)^(9/2))/128 + (3658095*(1 - 2*x)^(11/2))/1408 - (1580985*(1 - 2*x)^(13/2))/1664 + (136647*(1 - 2*x)^(15/2))/640 - (59049*(1 - 2*x)^(17/2))/2176 + (3645*(1 - 2*x)^(19/2))/2432}
{(1 - 2*x)^(3/2)*(2 + 3*x)^5*(3 + 5*x), x, 2, (-184877*(1 - 2*x)^(5/2))/320 + (8575*(1 - 2*x)^(7/2))/8 - (173215*(1 - 2*x)^(9/2))/192 + (37485*(1 - 2*x)^(11/2))/88 - (97335*(1 - 2*x)^(13/2))/832 + (351*(1 - 2*x)^(15/2))/20 - (1215*(1 - 2*x)^(17/2))/1088}
{(1 - 2*x)^(3/2)*(2 + 3*x)^4*(3 + 5*x), x, 2, (-26411*(1 - 2*x)^(5/2))/160 + (8183*(1 - 2*x)^(7/2))/32 - (8281*(1 - 2*x)^(9/2))/48 + (10773*(1 - 2*x)^(11/2))/176 - (4671*(1 - 2*x)^(13/2))/416 + (27*(1 - 2*x)^(15/2))/32}
{(1 - 2*x)^(3/2)*(2 + 3*x)^3*(3 + 5*x), x, 2, (-3773*(1 - 2*x)^(5/2))/80 + (469*(1 - 2*x)^(7/2))/8 - (119*(1 - 2*x)^(9/2))/4 + (621*(1 - 2*x)^(11/2))/88 - (135*(1 - 2*x)^(13/2))/208}
{(1 - 2*x)^(3/2)*(2 + 3*x)^2*(3 + 5*x), x, 2, (-539*(1 - 2*x)^(5/2))/40 + (101*(1 - 2*x)^(7/2))/8 - (103*(1 - 2*x)^(9/2))/24 + (45*(1 - 2*x)^(11/2))/88}
{(1 - 2*x)^(3/2)*(2 + 3*x)*(3 + 5*x), x, 2, (-77*(1 - 2*x)^(5/2))/20 + (17*(1 - 2*x)^(7/2))/7 - (5*(1 - 2*x)^(9/2))/12}
{(1 - 2*x)^(3/2)*(3 + 5*x), x, 2, (-11*(1 - 2*x)^(5/2))/10 + (5*(1 - 2*x)^(7/2))/14}
{((1 - 2*x)^(3/2)*(3 + 5*x))/(2 + 3*x), x, 4, (-14*Sqrt[1 - 2*x])/27 - (2*(1 - 2*x)^(3/2))/27 - (1 - 2*x)^(5/2)/3 + (14*Sqrt[7/3]*ArcTanh[Sqrt[3/7]*Sqrt[1 - 2*x]])/27}
{((1 - 2*x)^(3/2)*(3 + 5*x))/(2 + 3*x)^2, x, 4, (76*Sqrt[1 - 2*x])/27 + (76*(1 - 2*x)^(3/2))/189 + (1 - 2*x)^(5/2)/(21*(2 + 3*x)) - (76*Sqrt[7/3]*ArcTanh[Sqrt[3/7]*Sqrt[1 - 2*x]])/27}
{((1 - 2*x)^(3/2)*(3 + 5*x))/(2 + 3*x)^3, x, 4, (-71*Sqrt[1 - 2*x])/63 + (1 - 2*x)^(5/2)/(42*(2 + 3*x)^2) - (71*(1 - 2*x)^(3/2))/(126*(2 + 3*x)) + (71*ArcTanh[Sqrt[3/7]*Sqrt[1 - 2*x]])/(9*Sqrt[21])}
{((1 - 2*x)^(3/2)*(3 + 5*x))/(2 + 3*x)^4, x, 4, (1 - 2*x)^(5/2)/(63*(2 + 3*x)^3) - (52*(1 - 2*x)^(3/2))/(189*(2 + 3*x)^2) + (52*Sqrt[1 - 2*x])/(189*(2 + 3*x)) - (104*ArcTanh[Sqrt[3/7]*Sqrt[1 - 2*x]])/(189*Sqrt[21])}
{((1 - 2*x)^(3/2)*(3 + 5*x))/(2 + 3*x)^5, x, 5, (1 - 2*x)^(5/2)/(84*(2 + 3*x)^4) - (137*(1 - 2*x)^(3/2))/(756*(2 + 3*x)^3) + (137*Sqrt[1 - 2*x])/(1512*(2 + 3*x)^2) - (137*Sqrt[1 - 2*x])/(10584*(2 + 3*x)) - (137*ArcTanh[Sqrt[3/7]*Sqrt[1 - 2*x]])/(5292*Sqrt[21])}
{((1 - 2*x)^(3/2)*(3 + 5*x))/(2 + 3*x)^6, x, 6, (1 - 2*x)^(5/2)/(105*(2 + 3*x)^5) - (17*(1 - 2*x)^(3/2))/(126*(2 + 3*x)^4) + (17*Sqrt[1 - 2*x])/(378*(2 + 3*x)^3) - (17*Sqrt[1 - 2*x])/(5292*(2 + 3*x)^2) - (17*Sqrt[1 - 2*x])/(12348*(2 + 3*x)) - (17*ArcTanh[Sqrt[3/7]*Sqrt[1 - 2*x]])/(6174*Sqrt[21])}


{(1 - 2*x)^(3/2)*(2 + 3*x)^4*(3 + 5*x)^2, x, 2, (-(290521/320))*(1 - 2*x)^(5/2) + (54439/32)*(1 - 2*x)^(7/2) - (832951/576)*(1 - 2*x)^(9/2) + (121359/176)*(1 - 2*x)^(11/2) - (159111/832)*(1 - 2*x)^(13/2) + (927/32)*(1 - 2*x)^(15/2) - (2025*(1 - 2*x)^(17/2))/1088}
{(1 - 2*x)^(3/2)*(2 + 3*x)^3*(3 + 5*x)^2, x, 2, (-(41503/160))*(1 - 2*x)^(5/2) + (13013/32)*(1 - 2*x)^(7/2) - (39977/144)*(1 - 2*x)^(9/2) + (17541/176)*(1 - 2*x)^(11/2) - (7695/416)*(1 - 2*x)^(13/2) + (45/32)*(1 - 2*x)^(15/2)}
{(1 - 2*x)^(3/2)*(2 + 3*x)^2*(3 + 5*x)^2, x, 2, (-(5929/80))*(1 - 2*x)^(5/2) + (187/2)*(1 - 2*x)^(7/2) - (3467/72)*(1 - 2*x)^(9/2) + (255/22)*(1 - 2*x)^(11/2) - (225/208)*(1 - 2*x)^(13/2)}
{(1 - 2*x)^(3/2)*(2 + 3*x)*(3 + 5*x)^2, x, 2, (-847*(1 - 2*x)^(5/2))/40 + (1133*(1 - 2*x)^(7/2))/56 - (505*(1 - 2*x)^(9/2))/72 + (75*(1 - 2*x)^(11/2))/88}
{(1 - 2*x)^(3/2)*(3 + 5*x)^2, x, 2, (-121*(1 - 2*x)^(5/2))/20 + (55*(1 - 2*x)^(7/2))/14 - (25*(1 - 2*x)^(9/2))/36}
{((1 - 2*x)^(3/2)*(3 + 5*x)^2)/(2 + 3*x), x, 5, (14/81)*Sqrt[1 - 2*x] + (2/81)*(1 - 2*x)^(3/2) - (26/63)*(1 - 2*x)^(5/2) - (5/21)*(1 - 2*x)^(5/2)*(3 + 5*x) - (14/81)*Sqrt[7/3]*ArcTanh[Sqrt[3/7]*Sqrt[1 - 2*x]]}
{((1 - 2*x)^(3/2)*(3 + 5*x)^2)/(2 + 3*x)^2, x, 5, (-(146/81))*Sqrt[1 - 2*x] - (146/567)*(1 - 2*x)^(3/2) - (5/9)*(1 - 2*x)^(5/2) - (1 - 2*x)^(5/2)/(63*(2 + 3*x)) + (146/81)*Sqrt[7/3]*ArcTanh[Sqrt[3/7]*Sqrt[1 - 2*x]]}
{((1 - 2*x)^(3/2)*(3 + 5*x)^2)/(2 + 3*x)^3, x, 5, (2873/567)*Sqrt[1 - 2*x] + (2873*(1 - 2*x)^(3/2))/3969 - (1 - 2*x)^(5/2)/(126*(2 + 3*x)^2) + (47*(1 - 2*x)^(5/2))/(294*(2 + 3*x)) - (2873*ArcTanh[Sqrt[3/7]*Sqrt[1 - 2*x]])/(81*Sqrt[21])}
{((1 - 2*x)^(3/2)*(3 + 5*x)^2)/(2 + 3*x)^4, x, 5, -((7559*Sqrt[1 - 2*x])/3969) - (1 - 2*x)^(5/2)/(189*(2 + 3*x)^3) + (209*(1 - 2*x)^(5/2))/(2646*(2 + 3*x)^2) - (7559*(1 - 2*x)^(3/2))/(7938*(2 + 3*x)) + (7559*ArcTanh[Sqrt[3/7]*Sqrt[1 - 2*x]])/(567*Sqrt[21])}
{((1 - 2*x)^(3/2)*(3 + 5*x)^2)/(2 + 3*x)^5, x, 5, -((1 - 2*x)^(5/2)/(252*(2 + 3*x)^4)) + (277*(1 - 2*x)^(5/2))/(5292*(2 + 3*x)^3) - (14423*(1 - 2*x)^(3/2))/(31752*(2 + 3*x)^2) + (14423*Sqrt[1 - 2*x])/(31752*(2 + 3*x)) - (14423*ArcTanh[Sqrt[3/7]*Sqrt[1 - 2*x]])/(15876*Sqrt[21])}
{((1 - 2*x)^(3/2)*(3 + 5*x)^2)/(2 + 3*x)^6, x, 6, -((1 - 2*x)^(5/2)/(315*(2 + 3*x)^5)) + (23*(1 - 2*x)^(5/2))/(588*(2 + 3*x)^4) - (4693*(1 - 2*x)^(3/2))/(15876*(2 + 3*x)^3) + (4693*Sqrt[1 - 2*x])/(31752*(2 + 3*x)^2) - (4693*Sqrt[1 - 2*x])/(222264*(2 + 3*x)) - (4693*ArcTanh[Sqrt[3/7]*Sqrt[1 - 2*x]])/(111132*Sqrt[21])}
{((1 - 2*x)^(3/2)*(3 + 5*x)^2)/(2 + 3*x)^7, x, 7, -((1 - 2*x)^(5/2)/(378*(2 + 3*x)^6)) + (59*(1 - 2*x)^(5/2))/(1890*(2 + 3*x)^5) - (991*(1 - 2*x)^(3/2))/(4536*(2 + 3*x)^4) + (991*Sqrt[1 - 2*x])/(13608*(2 + 3*x)^3) - (991*Sqrt[1 - 2*x])/(190512*(2 + 3*x)^2) - (991*Sqrt[1 - 2*x])/(444528*(2 + 3*x)) - (991*ArcTanh[Sqrt[3/7]*Sqrt[1 - 2*x]])/(222264*Sqrt[21])}


{(1 - 2*x)^(3/2)*(2 + 3*x)^4*(3 + 5*x)^3, x, 2, (-(3195731/640))*(1 - 2*x)^(5/2) + (1405173/128)*(1 - 2*x)^(7/2) - (4324397/384)*(1 - 2*x)^(9/2) + (9504551*(1 - 2*x)^(11/2))/1408 - (4177401*(1 - 2*x)^(13/2))/1664 + (73431/128)*(1 - 2*x)^(15/2) - (161325*(1 - 2*x)^(17/2))/2176 + (10125*(1 - 2*x)^(19/2))/2432}
{(1 - 2*x)^(3/2)*(2 + 3*x)^3*(3 + 5*x)^3, x, 2, (-(456533/320))*(1 - 2*x)^(5/2) + (43197/16)*(1 - 2*x)^(7/2) - (444983/192)*(1 - 2*x)^(9/2) + (98209/88)*(1 - 2*x)^(11/2) - (260055/832)*(1 - 2*x)^(13/2) + (765/16)*(1 - 2*x)^(15/2) - (3375*(1 - 2*x)^(17/2))/1088}
{(1 - 2*x)^(3/2)*(2 + 3*x)^2*(3 + 5*x)^3, x, 2, (-(65219/160))*(1 - 2*x)^(5/2) + (20691/32)*(1 - 2*x)^(7/2) - (21439/48)*(1 - 2*x)^(9/2) + (28555/176)*(1 - 2*x)^(11/2) - (975/32)*(1 - 2*x)^(13/2) + (75/32)*(1 - 2*x)^(15/2)}
{(1 - 2*x)^(3/2)*(2 + 3*x)*(3 + 5*x)^3, x, 2, (-9317*(1 - 2*x)^(5/2))/80 + (8349*(1 - 2*x)^(7/2))/56 - (935*(1 - 2*x)^(9/2))/12 + (1675*(1 - 2*x)^(11/2))/88 - (375*(1 - 2*x)^(13/2))/208}
{(1 - 2*x)^(3/2)*(3 + 5*x)^3, x, 2, (-1331*(1 - 2*x)^(5/2))/40 + (1815*(1 - 2*x)^(7/2))/56 - (275*(1 - 2*x)^(9/2))/24 + (125*(1 - 2*x)^(11/2))/88}
{((1 - 2*x)^(3/2)*(3 + 5*x)^3)/(2 + 3*x), x, 6, (-72742*Sqrt[1 - 2*x])/14175 - (919*Sqrt[1 - 2*x]*(3 + 5*x)^2)/4725 + (26*Sqrt[1 - 2*x]*(3 + 5*x)^3)/315 + (2*(1 - 2*x)^(3/2)*(3 + 5*x)^3)/27 - (Sqrt[1 - 2*x]*(14711 + 17779*x))/8505 + (14*Sqrt[7/3]*ArcTanh[Sqrt[3/7]*Sqrt[1 - 2*x]])/243}
{((1 - 2*x)^(3/2)*(3 + 5*x)^3)/(2 + 3*x)^2, x, 6, (-1832*Sqrt[1 - 2*x])/315 + (2*(4 - 239*x)*Sqrt[1 - 2*x])/63 + (67*Sqrt[1 - 2*x]*(3 + 5*x)^2)/35 - (2*Sqrt[1 - 2*x]*(3 + 5*x)^3)/7 - ((1 - 2*x)^(3/2)*(3 + 5*x)^3)/(3*(2 + 3*x)) - (8*Sqrt[7/3]*ArcTanh[Sqrt[3/7]*Sqrt[1 - 2*x]])/9}
{((1 - 2*x)^(3/2)*(3 + 5*x)^3)/(2 + 3*x)^3, x, 6, 13*Sqrt[1 - 2*x] - (5*(67 - 343*x)*Sqrt[1 - 2*x])/54 - (31*Sqrt[1 - 2*x]*(3 + 5*x)^2)/3 - ((1 - 2*x)^(3/2)*(3 + 5*x)^3)/(6*(2 + 3*x)^2) + (6*Sqrt[1 - 2*x]*(3 + 5*x)^3)/(2 + 3*x) + (887*ArcTanh[Sqrt[3/7]*Sqrt[1 - 2*x]])/(27*Sqrt[21])}
{((1 - 2*x)^(3/2)*(3 + 5*x)^3)/(2 + 3*x)^4, x, 6, (-830*Sqrt[1 - 2*x])/27 + (5*(1163 - 7265*x)*Sqrt[1 - 2*x])/567 + (251*Sqrt[1 - 2*x]*(3 + 5*x)^2)/(63*(2 + 3*x)) - ((1 - 2*x)^(3/2)*(3 + 5*x)^3)/(9*(2 + 3*x)^3) + (2*Sqrt[1 - 2*x]*(3 + 5*x)^3)/(2 + 3*x)^2 - (36038*ArcTanh[Sqrt[3/7]*Sqrt[1 - 2*x]])/(567*Sqrt[21])}
{((1 - 2*x)^(3/2)*(3 + 5*x)^3)/(2 + 3*x)^5, x, 6, (-5305*Sqrt[1 - 2*x])/588 + (337*Sqrt[1 - 2*x]*(3 + 5*x))/(392*(2 + 3*x)) + (13*Sqrt[1 - 2*x]*(3 + 5*x)^2)/(56*(2 + 3*x)^2) - ((1 - 2*x)^(3/2)*(3 + 5*x)^3)/(12*(2 + 3*x)^4) + (Sqrt[1 - 2*x]*(3 + 5*x)^3)/(2 + 3*x)^3 + (13243*ArcTanh[Sqrt[3/7]*Sqrt[1 - 2*x]])/(588*Sqrt[21])}
{((1 - 2*x)^(3/2)*(3 + 5*x)^3)/(2 + 3*x)^6, x, 6, ((136 - 19*x)*Sqrt[1 - 2*x])/(1323*(2 + 3*x)^2) - (3335*Sqrt[1 - 2*x])/(3087*(2 + 3*x)) - (67*Sqrt[1 - 2*x]*(3 + 5*x)^2)/(315*(2 + 3*x)^3) - ((1 - 2*x)^(3/2)*(3 + 5*x)^3)/(15*(2 + 3*x)^5) + (3*Sqrt[1 - 2*x]*(3 + 5*x)^3)/(5*(2 + 3*x)^4) - (13892*ArcTanh[Sqrt[3/7]*Sqrt[1 - 2*x]])/(9261*Sqrt[21])}
{((1 - 2*x)^(3/2)*(3 + 5*x)^3)/(2 + 3*x)^7, x, 7, ((9323 - 8405*x)*Sqrt[1 - 2*x])/(158760*(2 + 3*x)^3) - (43207*Sqrt[1 - 2*x])/(63504*(2 + 3*x)^2) - (15313*Sqrt[1 - 2*x])/(444528*(2 + 3*x)) - (653*Sqrt[1 - 2*x]*(3 + 5*x)^2)/(2520*(2 + 3*x)^4) - ((1 - 2*x)^(3/2)*(3 + 5*x)^3)/(18*(2 + 3*x)^6) + (2*Sqrt[1 - 2*x]*(3 + 5*x)^3)/(5*(2 + 3*x)^5) - (15313*ArcTanh[Sqrt[3/7]*Sqrt[1 - 2*x]])/(222264*Sqrt[21])}
{((1 - 2*x)^(3/2)*(3 + 5*x)^3)/(2 + 3*x)^8, x, 8, ((2201 - 2675*x)*Sqrt[1 - 2*x])/(61740*(2 + 3*x)^4) - (5471*Sqrt[1 - 2*x])/(13230*(2 + 3*x)^3) - (4369*Sqrt[1 - 2*x])/(518616*(2 + 3*x)^2) - (4369*Sqrt[1 - 2*x])/(1210104*(2 + 3*x)) - (173*Sqrt[1 - 2*x]*(3 + 5*x)^2)/(735*(2 + 3*x)^5) - ((1 - 2*x)^(3/2)*(3 + 5*x)^3)/(21*(2 + 3*x)^7) + (2*Sqrt[1 - 2*x]*(3 + 5*x)^3)/(7*(2 + 3*x)^6) - (4369*ArcTanh[Sqrt[3/7]*Sqrt[1 - 2*x]])/(605052*Sqrt[21])}


(* ::Subsubsection::Closed:: *)
(*n<0*)


{((1 - 2*x)^(3/2)*(2 + 3*x)^6)/(3 + 5*x), x, 9, (-16097737918*Sqrt[1 - 2*x])/1508203125 - (18395813*Sqrt[1 - 2*x]*(2 + 3*x))/12065625 - (32816296*Sqrt[1 - 2*x]*(2 + 3*x)^2)/100546875 - (6469823*Sqrt[1 - 2*x]*(2 + 3*x)^3)/84459375 - (36202*Sqrt[1 - 2*x]*(2 + 3*x)^4)/2413125 + (683*Sqrt[1 - 2*x]*(2 + 3*x)^5)/53625 + (2*Sqrt[1 - 2*x]*(2 + 3*x)^6)/195 + (2*(1 - 2*x)^(3/2)*(2 + 3*x)^6)/75 - (22*Sqrt[11/5]*ArcTanh[Sqrt[5/11]*Sqrt[1 - 2*x]])/390625}
{((1 - 2*x)^(3/2)*(2 + 3*x)^5)/(3 + 5*x), x, 8, (-158985118*Sqrt[1 - 2*x])/33515625 - (2803796*Sqrt[1 - 2*x]*(2 + 3*x)^2)/20109375 - (467323*Sqrt[1 - 2*x]*(2 + 3*x)^3)/16891875 + (6673*Sqrt[1 - 2*x]*(2 + 3*x)^4)/482625 + (158*Sqrt[1 - 2*x]*(2 + 3*x)^5)/10725 + (2*(1 - 2*x)^(3/2)*(2 + 3*x)^5)/65 - (Sqrt[1 - 2*x]*(119316702 + 198601625*x))/100546875 - (22*Sqrt[11/5]*ArcTanh[Sqrt[5/11]*Sqrt[1 - 2*x]])/78125}
{((1 - 2*x)^(3/2)*(2 + 3*x)^4)/(3 + 5*x), x, 7, (-10083686*Sqrt[1 - 2*x])/4640625 - (11401*Sqrt[1 - 2*x]*(2 + 3*x))/37125 - (17792*Sqrt[1 - 2*x]*(2 + 3*x)^2)/309375 + (3629*Sqrt[1 - 2*x]*(2 + 3*x)^3)/259875 + (166*Sqrt[1 - 2*x]*(2 + 3*x)^4)/7425 + (2*(1 - 2*x)^(3/2)*(2 + 3*x)^4)/55 - (22*Sqrt[11/5]*ArcTanh[Sqrt[5/11]*Sqrt[1 - 2*x]])/15625}
{((1 - 2*x)^(3/2)*(2 + 3*x)^3)/(3 + 5*x), x, 6, (-10826*Sqrt[1 - 2*x])/9375 + (53*Sqrt[1 - 2*x]*(2 + 3*x)^2)/5625 + (58*Sqrt[1 - 2*x]*(2 + 3*x)^3)/1575 + (2*(1 - 2*x)^(3/2)*(2 + 3*x)^3)/45 - (Sqrt[1 - 2*x]*(8664 + 12625*x))/28125 - (22*Sqrt[11/5]*ArcTanh[Sqrt[5/11]*Sqrt[1 - 2*x]])/3125}
{((1 - 2*x)^(3/2)*(2 + 3*x)^2)/(3 + 5*x), x, 5, (22/625)*Sqrt[1 - 2*x] + (2/375)*(1 - 2*x)^(3/2) - (18/125)*(1 - 2*x)^(5/2) - (3/35)*(1 - 2*x)^(5/2)*(2 + 3*x) - (22/625)*Sqrt[11/5]*ArcTanh[Sqrt[5/11]*Sqrt[1 - 2*x]]}
{((1 - 2*x)^(3/2)*(2 + 3*x))/(3 + 5*x), x, 4, (22*Sqrt[1 - 2*x])/125 + (2*(1 - 2*x)^(3/2))/75 - (3*(1 - 2*x)^(5/2))/25 - (22*Sqrt[11/5]*ArcTanh[Sqrt[5/11]*Sqrt[1 - 2*x]])/125}
{(1 - 2*x)^(3/2)/(3 + 5*x), x, 3, (22*Sqrt[1 - 2*x])/25 + (2*(1 - 2*x)^(3/2))/15 - (22*Sqrt[11/5]*ArcTanh[Sqrt[5/11]*Sqrt[1 - 2*x]])/25}
{(1 - 2*x)^(3/2)/((2 + 3*x)*(3 + 5*x)), x, 4, (-4*Sqrt[1 - 2*x])/15 + (14*Sqrt[7/3]*ArcTanh[Sqrt[3/7]*Sqrt[1 - 2*x]])/3 - (22*Sqrt[11/5]*ArcTanh[Sqrt[5/11]*Sqrt[1 - 2*x]])/5}
{(1 - 2*x)^(3/2)/((2 + 3*x)^2*(3 + 5*x)), x, 5, (7*Sqrt[1 - 2*x])/(6 + 9*x) + (64*Sqrt[7/3]*ArcTanh[Sqrt[3/7]*Sqrt[1 - 2*x]])/3 - 22*Sqrt[11/5]*ArcTanh[Sqrt[5/11]*Sqrt[1 - 2*x]], (2/3)*Sqrt[1 - 2*x] + (1 - 2*x)^(3/2)/(2 + 3*x) + (64/3)*Sqrt[7/3]*ArcTanh[Sqrt[3/7]*Sqrt[1 - 2*x]] - 22*Sqrt[11/5]*ArcTanh[Sqrt[5/11]*Sqrt[1 - 2*x]]}
{(1 - 2*x)^(3/2)/((2 + 3*x)^3*(3 + 5*x)), x, 5, (1 - 2*x)^(3/2)/(2*(2 + 3*x)^2) + (67*Sqrt[1 - 2*x])/(6*(2 + 3*x)) + (2243*ArcTanh[Sqrt[3/7]*Sqrt[1 - 2*x]])/(3*Sqrt[21]) - 22*Sqrt[55]*ArcTanh[Sqrt[5/11]*Sqrt[1 - 2*x]]}
{(1 - 2*x)^(3/2)/((2 + 3*x)^4*(3 + 5*x)), x, 6, (1 - 2*x)^(3/2)/(3*(2 + 3*x)^3) + (17*Sqrt[1 - 2*x])/(3*(2 + 3*x)^2) + (1138*Sqrt[1 - 2*x])/(21*(2 + 3*x)) + (78506*ArcTanh[Sqrt[3/7]*Sqrt[1 - 2*x]])/(21*Sqrt[21]) - 110*Sqrt[55]*ArcTanh[Sqrt[5/11]*Sqrt[1 - 2*x]]}
{(1 - 2*x)^(3/2)/((2 + 3*x)^5*(3 + 5*x)), x, 7, (1 - 2*x)^(3/2)/(4*(2 + 3*x)^4) + (137*Sqrt[1 - 2*x])/(36*(2 + 3*x)^3) + (13723*Sqrt[1 - 2*x])/(504*(2 + 3*x)^2) + (318643*Sqrt[1 - 2*x])/(1176*(2 + 3*x)) + (10990843*ArcTanh[Sqrt[3/7]*Sqrt[1 - 2*x]])/(588*Sqrt[21]) - 550*Sqrt[55]*ArcTanh[Sqrt[5/11]*Sqrt[1 - 2*x]]}
{(1 - 2*x)^(3/2)/((2 + 3*x)^6*(3 + 5*x)), x, 8, (1 - 2*x)^(3/2)/(5*(2 + 3*x)^5) + (43*Sqrt[1 - 2*x])/(15*(2 + 3*x)^4) + (5732*Sqrt[1 - 2*x])/(315*(2 + 3*x)^3) + (120077*Sqrt[1 - 2*x])/(882*(2 + 3*x)^2) + (2788127*Sqrt[1 - 2*x])/(2058*(2 + 3*x)) + (96169877*ArcTanh[Sqrt[3/7]*Sqrt[1 - 2*x]])/(1029*Sqrt[21]) - 2750*Sqrt[55]*ArcTanh[Sqrt[5/11]*Sqrt[1 - 2*x]]}


{((1 - 2*x)^(3/2)*(2 + 3*x)^5)/(3 + 5*x)^2, x, 8, (-1270604*Sqrt[1 - 2*x])/859375 - (9388*Sqrt[1 - 2*x]*(2 + 3*x)^2)/515625 + (33406*Sqrt[1 - 2*x]*(2 + 3*x)^3)/433125 + (4019*Sqrt[1 - 2*x]*(2 + 3*x)^4)/12375 - (26*Sqrt[1 - 2*x]*(2 + 3*x)^5)/275 - ((1 - 2*x)^(3/2)*(2 + 3*x)^5)/(5*(3 + 5*x)) - (2*Sqrt[1 - 2*x]*(491178 + 769625*x))/2578125 - (324*Sqrt[11/5]*ArcTanh[Sqrt[5/11]*Sqrt[1 - 2*x]])/78125}
{((1 - 2*x)^(3/2)*(2 + 3*x)^4)/(3 + 5*x)^2, x, 7, (-110938*Sqrt[1 - 2*x])/140625 - (83*Sqrt[1 - 2*x]*(2 + 3*x))/1125 + (764*Sqrt[1 - 2*x]*(2 + 3*x)^2)/9375 + (2707*Sqrt[1 - 2*x]*(2 + 3*x)^3)/7875 - (22*Sqrt[1 - 2*x]*(2 + 3*x)^4)/225 - ((1 - 2*x)^(3/2)*(2 + 3*x)^4)/(5*(3 + 5*x)) - (258*Sqrt[11/5]*ArcTanh[Sqrt[5/11]*Sqrt[1 - 2*x]])/15625}
{((1 - 2*x)^(3/2)*(2 + 3*x)^3)/(3 + 5*x)^2, x, 6, (-1418*Sqrt[1 - 2*x])/3125 + (2*Sqrt[1 - 2*x]*(2 + 3*x))/25 + (237*Sqrt[1 - 2*x]*(2 + 3*x)^2)/625 - (18*Sqrt[1 - 2*x]*(2 + 3*x)^3)/175 - ((1 - 2*x)^(3/2)*(2 + 3*x)^3)/(5*(3 + 5*x)) - (192*Sqrt[11/5]*ArcTanh[Sqrt[5/11]*Sqrt[1 - 2*x]])/3125}
{((1 - 2*x)^(3/2)*(2 + 3*x)^2)/(3 + 5*x)^2, x, 5, (126/625)*Sqrt[1 - 2*x] + (42*(1 - 2*x)^(3/2))/1375 - (9/125)*(1 - 2*x)^(5/2) - (1 - 2*x)^(5/2)/(275*(3 + 5*x)) - (126/625)*Sqrt[11/5]*ArcTanh[Sqrt[5/11]*Sqrt[1 - 2*x]]}
{((1 - 2*x)^(3/2)*(2 + 3*x))/(3 + 5*x)^2, x, 4, (12*Sqrt[1 - 2*x])/25 + (4*(1 - 2*x)^(3/2))/55 - (1 - 2*x)^(5/2)/(55*(3 + 5*x)) - (12*Sqrt[11/5]*ArcTanh[Sqrt[5/11]*Sqrt[1 - 2*x]])/25}
{(1 - 2*x)^(3/2)/(3 + 5*x)^2, x, 3, (-6*Sqrt[1 - 2*x])/25 - (1 - 2*x)^(3/2)/(5*(3 + 5*x)) + (6*Sqrt[11/5]*ArcTanh[Sqrt[5/11]*Sqrt[1 - 2*x]])/25}
{(1 - 2*x)^(3/2)/((2 + 3*x)*(3 + 5*x)^2), x, 5, (-2*Sqrt[1 - 2*x])/5 - (1 - 2*x)^(3/2)/(3 + 5*x) - 14*Sqrt[7/3]*ArcTanh[Sqrt[3/7]*Sqrt[1 - 2*x]] + (72*Sqrt[11/5]*ArcTanh[Sqrt[5/11]*Sqrt[1 - 2*x]])/5}
{(1 - 2*x)^(3/2)/((2 + 3*x)^2*(3 + 5*x)^2), x, 5, (-22*Sqrt[1 - 2*x])/(3 + 5*x) + (1 - 2*x)^(3/2)/((2 + 3*x)*(3 + 5*x)) - 134*Sqrt[7/3]*ArcTanh[Sqrt[3/7]*Sqrt[1 - 2*x]] + 138*Sqrt[11/5]*ArcTanh[Sqrt[5/11]*Sqrt[1 - 2*x]]}
{(1 - 2*x)^(3/2)/((2 + 3*x)^3*(3 + 5*x)^2), x, 6, (-335*Sqrt[1 - 2*x])/(2*(3 + 5*x)) + (1 - 2*x)^(3/2)/(2*(2 + 3*x)^2*(3 + 5*x)) + (17*Sqrt[1 - 2*x])/((2 + 3*x)*(3 + 5*x)) - 2311*Sqrt[3/7]*ArcTanh[Sqrt[3/7]*Sqrt[1 - 2*x]] + 204*Sqrt[55]*ArcTanh[Sqrt[5/11]*Sqrt[1 - 2*x]]}
{(1 - 2*x)^(3/2)/((2 + 3*x)^4*(3 + 5*x)^2), x, 7, (-46555*Sqrt[1 - 2*x])/(42*(3 + 5*x)) + (1 - 2*x)^(3/2)/(3*(2 + 3*x)^3*(3 + 5*x)) + (137*Sqrt[1 - 2*x])/(18*(2 + 3*x)^2*(3 + 5*x)) + (6949*Sqrt[1 - 2*x])/(63*(2 + 3*x)*(3 + 5*x)) - (321161*ArcTanh[Sqrt[3/7]*Sqrt[1 - 2*x]])/(7*Sqrt[21]) + 1350*Sqrt[55]*ArcTanh[Sqrt[5/11]*Sqrt[1 - 2*x]]}
{(1 - 2*x)^(3/2)/((2 + 3*x)^5*(3 + 5*x)^2), x, 8, (-8110915*Sqrt[1 - 2*x])/(1176*(3 + 5*x)) + (1 - 2*x)^(3/2)/(4*(2 + 3*x)^4*(3 + 5*x)) + (43*Sqrt[1 - 2*x])/(9*(2 + 3*x)^3*(3 + 5*x)) + (23173*Sqrt[1 - 2*x])/(504*(2 + 3*x)^2*(3 + 5*x)) + (302668*Sqrt[1 - 2*x])/(441*(2 + 3*x)*(3 + 5*x)) - (55953383*ArcTanh[Sqrt[3/7]*Sqrt[1 - 2*x]])/(196*Sqrt[21]) + 8400*Sqrt[55]*ArcTanh[Sqrt[5/11]*Sqrt[1 - 2*x]]}


{((1 - 2*x)^(3/2)*(2 + 3*x)^4)/(3 + 5*x)^3, x, 7, (2571*Sqrt[1 - 2*x])/15625 - (3*(1618 - 4125*x)*Sqrt[1 - 2*x])/31250 + (1404*Sqrt[1 - 2*x]*(2 + 3*x)^2)/3125 + (2643*Sqrt[1 - 2*x]*(2 + 3*x)^3)/1750 - ((1 - 2*x)^(3/2)*(2 + 3*x)^4)/(10*(3 + 5*x)^2) - (129*Sqrt[1 - 2*x]*(2 + 3*x)^4)/(50*(3 + 5*x)) - (12279*ArcTanh[Sqrt[5/11]*Sqrt[1 - 2*x]])/(15625*Sqrt[55])}
{((1 - 2*x)^(3/2)*(2 + 3*x)^3)/(3 + 5*x)^3, x, 6, (273*Sqrt[1 - 2*x])/3125 + (21*Sqrt[1 - 2*x]*(2 + 3*x))/50 + (693*Sqrt[1 - 2*x]*(2 + 3*x)^2)/625 - ((1 - 2*x)^(3/2)*(2 + 3*x)^3)/(10*(3 + 5*x)^2) - (48*Sqrt[1 - 2*x]*(2 + 3*x)^3)/(25*(3 + 5*x)) - (5943*ArcTanh[Sqrt[5/11]*Sqrt[1 - 2*x]])/(3125*Sqrt[55])}
{((1 - 2*x)^(3/2)*(2 + 3*x)^2)/(3 + 5*x)^3, x, 5, (357*Sqrt[1 - 2*x])/1375 + (119*(1 - 2*x)^(3/2))/3025 - (1 - 2*x)^(5/2)/(550*(3 + 5*x)^2) - (131*(1 - 2*x)^(5/2))/(6050*(3 + 5*x)) - (357*ArcTanh[Sqrt[5/11]*Sqrt[1 - 2*x]])/(125*Sqrt[55])}
{((1 - 2*x)^(3/2)*(2 + 3*x))/(3 + 5*x)^3, x, 4, (-39*Sqrt[1 - 2*x])/275 - (1 - 2*x)^(5/2)/(110*(3 + 5*x)^2) - (13*(1 - 2*x)^(3/2))/(110*(3 + 5*x)) + (39*ArcTanh[Sqrt[5/11]*Sqrt[1 - 2*x]])/(25*Sqrt[55])}
{(1 - 2*x)^(3/2)/(3 + 5*x)^3, x, 3, -(1 - 2*x)^(3/2)/(10*(3 + 5*x)^2) + (3*Sqrt[1 - 2*x])/(50*(3 + 5*x)) - (3*ArcTanh[Sqrt[5/11]*Sqrt[1 - 2*x]])/(25*Sqrt[55])}
{(1 - 2*x)^(3/2)/((2 + 3*x)*(3 + 5*x)^3), x, 5, -(1 - 2*x)^(3/2)/(2*(3 + 5*x)^2) + (69*Sqrt[1 - 2*x])/(10*(3 + 5*x)) + 14*Sqrt[21]*ArcTanh[Sqrt[3/7]*Sqrt[1 - 2*x]] - (2379*ArcTanh[Sqrt[5/11]*Sqrt[1 - 2*x]])/(5*Sqrt[55])}
{(1 - 2*x)^(3/2)/((2 + 3*x)^2*(3 + 5*x)^3), x, 6, (-33*Sqrt[1 - 2*x])/(2*(3 + 5*x)^2) + (1 - 2*x)^(3/2)/((2 + 3*x)*(3 + 5*x)^2) + (207*Sqrt[1 - 2*x])/(2*(3 + 5*x)) + 204*Sqrt[21]*ArcTanh[Sqrt[3/7]*Sqrt[1 - 2*x]] - (6933*ArcTanh[Sqrt[5/11]*Sqrt[1 - 2*x]])/Sqrt[55]}
{(1 - 2*x)^(3/2)/((2 + 3*x)^3*(3 + 5*x)^3), x, 7, (-1015*Sqrt[1 - 2*x])/(6*(3 + 5*x)^2) + (1 - 2*x)^(3/2)/(2*(2 + 3*x)^2*(3 + 5*x)^2) + (137*Sqrt[1 - 2*x])/(6*(2 + 3*x)*(3 + 5*x)^2) + (1020*Sqrt[1 - 2*x])/(3 + 5*x) + 14073*Sqrt[3/7]*ArcTanh[Sqrt[3/7]*Sqrt[1 - 2*x]] - 13665*Sqrt[5/11]*ArcTanh[Sqrt[5/11]*Sqrt[1 - 2*x]]}
{(1 - 2*x)^(3/2)/((2 + 3*x)^4*(3 + 5*x)^3), x, 8, (-176065*Sqrt[1 - 2*x])/(126*(3 + 5*x)^2) + (1 - 2*x)^(3/2)/(3*(2 + 3*x)^3*(3 + 5*x)^2) + (86*Sqrt[1 - 2*x])/(9*(2 + 3*x)^2*(3 + 5*x)^2) + (1301*Sqrt[1 - 2*x])/(7*(2 + 3*x)*(3 + 5*x)^2) + (117955*Sqrt[1 - 2*x])/(14*(3 + 5*x)) + (813716*Sqrt[3/7]*ArcTanh[Sqrt[3/7]*Sqrt[1 - 2*x]])/7 - 112875*Sqrt[5/11]*ArcTanh[Sqrt[5/11]*Sqrt[1 - 2*x]]}


(* ::Subsection::Closed:: *)
(*Integrands of the form (a+b x)^m (c+d x)^n (e+f x)^(5/2)*)


(* ::Subsubsection::Closed:: *)
(*n>0*)


{(1 - 2*x)^(5/2)*(2 + 3*x)^6*(3 + 5*x), x, 2, (-184877*(1 - 2*x)^(7/2))/128 + (3916031*(1 - 2*x)^(9/2))/1152 - (5078115*(1 - 2*x)^(11/2))/1408 + (3658095*(1 - 2*x)^(13/2))/1664 - (105399*(1 - 2*x)^(15/2))/128 + (409941*(1 - 2*x)^(17/2))/2176 - (59049*(1 - 2*x)^(19/2))/2432 + (1215*(1 - 2*x)^(21/2))/896}
{(1 - 2*x)^(5/2)*(2 + 3*x)^5*(3 + 5*x), x, 2, (-26411*(1 - 2*x)^(7/2))/64 + (60025*(1 - 2*x)^(9/2))/72 - (519645*(1 - 2*x)^(11/2))/704 + (37485*(1 - 2*x)^(13/2))/104 - (6489*(1 - 2*x)^(15/2))/64 + (1053*(1 - 2*x)^(17/2))/68 - (1215*(1 - 2*x)^(19/2))/1216}
{(1 - 2*x)^(5/2)*(2 + 3*x)^4*(3 + 5*x), x, 2, (-3773*(1 - 2*x)^(7/2))/32 + (57281*(1 - 2*x)^(9/2))/288 - (24843*(1 - 2*x)^(11/2))/176 + (10773*(1 - 2*x)^(13/2))/208 - (1557*(1 - 2*x)^(15/2))/160 + (405*(1 - 2*x)^(17/2))/544}
{(1 - 2*x)^(5/2)*(2 + 3*x)^3*(3 + 5*x), x, 2, (-539*(1 - 2*x)^(7/2))/16 + (3283*(1 - 2*x)^(9/2))/72 - (1071*(1 - 2*x)^(11/2))/44 + (621*(1 - 2*x)^(13/2))/104 - (9*(1 - 2*x)^(15/2))/16}
{(1 - 2*x)^(5/2)*(2 + 3*x)^2*(3 + 5*x), x, 2, (-77*(1 - 2*x)^(7/2))/8 + (707*(1 - 2*x)^(9/2))/72 - (309*(1 - 2*x)^(11/2))/88 + (45*(1 - 2*x)^(13/2))/104}
{(1 - 2*x)^(5/2)*(2 + 3*x)*(3 + 5*x), x, 2, (-11*(1 - 2*x)^(7/2))/4 + (17*(1 - 2*x)^(9/2))/9 - (15*(1 - 2*x)^(11/2))/44}
{(1 - 2*x)^(5/2)*(3 + 5*x), x, 2, (-11*(1 - 2*x)^(7/2))/14 + (5*(1 - 2*x)^(9/2))/18}
{((1 - 2*x)^(5/2)*(3 + 5*x))/(2 + 3*x), x, 5, (-98*Sqrt[1 - 2*x])/81 - (14*(1 - 2*x)^(3/2))/81 - (2*(1 - 2*x)^(5/2))/45 - (5*(1 - 2*x)^(7/2))/21 + (98*Sqrt[7/3]*ArcTanh[Sqrt[3/7]*Sqrt[1 - 2*x]])/81}
{((1 - 2*x)^(5/2)*(3 + 5*x))/(2 + 3*x)^2, x, 5, (560*Sqrt[1 - 2*x])/81 + (80*(1 - 2*x)^(3/2))/81 + (16*(1 - 2*x)^(5/2))/63 + (1 - 2*x)^(7/2)/(21*(2 + 3*x)) - (560*Sqrt[7/3]*ArcTanh[Sqrt[3/7]*Sqrt[1 - 2*x]])/81}
{((1 - 2*x)^(5/2)*(3 + 5*x))/(2 + 3*x)^3, x, 5, (-365*Sqrt[1 - 2*x])/81 - (365*(1 - 2*x)^(3/2))/567 + (1 - 2*x)^(7/2)/(42*(2 + 3*x)^2) - (73*(1 - 2*x)^(5/2))/(126*(2 + 3*x)) + (365*Sqrt[7/3]*ArcTanh[Sqrt[3/7]*Sqrt[1 - 2*x]])/81}
{((1 - 2*x)^(5/2)*(3 + 5*x))/(2 + 3*x)^4, x, 5, (530*Sqrt[1 - 2*x])/567 + (1 - 2*x)^(7/2)/(63*(2 + 3*x)^3) - (53*(1 - 2*x)^(5/2))/(189*(2 + 3*x)^2) + (265*(1 - 2*x)^(3/2))/(567*(2 + 3*x)) - (530*ArcTanh[Sqrt[3/7]*Sqrt[1 - 2*x]])/(81*Sqrt[21])}
{((1 - 2*x)^(5/2)*(3 + 5*x))/(2 + 3*x)^5, x, 5, (1 - 2*x)^(7/2)/(84*(2 + 3*x)^4) - (139*(1 - 2*x)^(5/2))/(756*(2 + 3*x)^3) + (695*(1 - 2*x)^(3/2))/(4536*(2 + 3*x)^2) - (695*Sqrt[1 - 2*x])/(4536*(2 + 3*x)) + (695*ArcTanh[Sqrt[3/7]*Sqrt[1 - 2*x]])/(2268*Sqrt[21])}
{((1 - 2*x)^(5/2)*(3 + 5*x))/(2 + 3*x)^6, x, 6, (1 - 2*x)^(7/2)/(105*(2 + 3*x)^5) - (43*(1 - 2*x)^(5/2))/(315*(2 + 3*x)^4) + (43*(1 - 2*x)^(3/2))/(567*(2 + 3*x)^3) - (43*Sqrt[1 - 2*x])/(1134*(2 + 3*x)^2) + (43*Sqrt[1 - 2*x])/(7938*(2 + 3*x)) + (43*ArcTanh[Sqrt[3/7]*Sqrt[1 - 2*x]])/(3969*Sqrt[21])}
{((1 - 2*x)^(5/2)*(3 + 5*x))/(2 + 3*x)^7, x, 7, (1 - 2*x)^(7/2)/(126*(2 + 3*x)^6) - (41*(1 - 2*x)^(5/2))/(378*(2 + 3*x)^5) + (205*(1 - 2*x)^(3/2))/(4536*(2 + 3*x)^4) - (205*Sqrt[1 - 2*x])/(13608*(2 + 3*x)^3) + (205*Sqrt[1 - 2*x])/(190512*(2 + 3*x)^2) + (205*Sqrt[1 - 2*x])/(444528*(2 + 3*x)) + (205*ArcTanh[Sqrt[3/7]*Sqrt[1 - 2*x]])/(222264*Sqrt[21])}


{(1 - 2*x)^(5/2)*(2 + 3*x)^4*(3 + 5*x)^2, x, 2, (-(41503/64))*(1 - 2*x)^(7/2) + (381073/288)*(1 - 2*x)^(9/2) - (832951/704)*(1 - 2*x)^(11/2) + (121359/208)*(1 - 2*x)^(13/2) - (53037/320)*(1 - 2*x)^(15/2) + (13905/544)*(1 - 2*x)^(17/2) - (2025*(1 - 2*x)^(19/2))/1216}
{(1 - 2*x)^(5/2)*(2 + 3*x)^3*(3 + 5*x)^2, x, 2, (-(5929/32))*(1 - 2*x)^(7/2) + (91091/288)*(1 - 2*x)^(9/2) - (39977/176)*(1 - 2*x)^(11/2) + (17541/208)*(1 - 2*x)^(13/2) - (513/32)*(1 - 2*x)^(15/2) + (675/544)*(1 - 2*x)^(17/2)}
{(1 - 2*x)^(5/2)*(2 + 3*x)^2*(3 + 5*x)^2, x, 2, (-(847/16))*(1 - 2*x)^(7/2) + (1309/18)*(1 - 2*x)^(9/2) - (3467/88)*(1 - 2*x)^(11/2) + (255/26)*(1 - 2*x)^(13/2) - (15/16)*(1 - 2*x)^(15/2)}
{(1 - 2*x)^(5/2)*(2 + 3*x)*(3 + 5*x)^2, x, 2, (-121*(1 - 2*x)^(7/2))/8 + (1133*(1 - 2*x)^(9/2))/72 - (505*(1 - 2*x)^(11/2))/88 + (75*(1 - 2*x)^(13/2))/104}
{(1 - 2*x)^(5/2)*(3 + 5*x)^2, x, 2, (-121*(1 - 2*x)^(7/2))/28 + (55*(1 - 2*x)^(9/2))/18 - (25*(1 - 2*x)^(11/2))/44}
{((1 - 2*x)^(5/2)*(3 + 5*x)^2)/(2 + 3*x), x, 6, (98/243)*Sqrt[1 - 2*x] + (14/243)*(1 - 2*x)^(3/2) + (2/135)*(1 - 2*x)^(5/2) - (40/189)*(1 - 2*x)^(7/2) - (5/27)*(1 - 2*x)^(7/2)*(3 + 5*x) - (98/243)*Sqrt[7/3]*ArcTanh[Sqrt[3/7]*Sqrt[1 - 2*x]]}
{((1 - 2*x)^(5/2)*(3 + 5*x)^2)/(2 + 3*x)^2, x, 6, (-(350/81))*Sqrt[1 - 2*x] - (50/81)*(1 - 2*x)^(3/2) - (10/63)*(1 - 2*x)^(5/2) - (25/63)*(1 - 2*x)^(7/2) - (1 - 2*x)^(7/2)/(63*(2 + 3*x)) + (350/81)*Sqrt[7/3]*ArcTanh[Sqrt[3/7]*Sqrt[1 - 2*x]]}
{((1 - 2*x)^(5/2)*(3 + 5*x)^2)/(2 + 3*x)^3, x, 6, (1055/81)*Sqrt[1 - 2*x] + (1055/567)*(1 - 2*x)^(3/2) + (211/441)*(1 - 2*x)^(5/2) - (1 - 2*x)^(7/2)/(126*(2 + 3*x)^2) + (143*(1 - 2*x)^(7/2))/(882*(2 + 3*x)) - (1055/81)*Sqrt[7/3]*ArcTanh[Sqrt[3/7]*Sqrt[1 - 2*x]]}
{((1 - 2*x)^(5/2)*(3 + 5*x)^2)/(2 + 3*x)^4, x, 6, (-(4435/567))*Sqrt[1 - 2*x] - (4435*(1 - 2*x)^(3/2))/3969 - (1 - 2*x)^(7/2)/(189*(2 + 3*x)^3) + (211*(1 - 2*x)^(7/2))/(2646*(2 + 3*x)^2) - (887*(1 - 2*x)^(5/2))/(882*(2 + 3*x)) + (4435*ArcTanh[Sqrt[3/7]*Sqrt[1 - 2*x]])/(81*Sqrt[21])}
{((1 - 2*x)^(5/2)*(3 + 5*x)^2)/(2 + 3*x)^5, x, 6, (24965*Sqrt[1 - 2*x])/15876 - (1 - 2*x)^(7/2)/(252*(2 + 3*x)^4) + (31*(1 - 2*x)^(7/2))/(588*(2 + 3*x)^3) - (4993*(1 - 2*x)^(5/2))/(10584*(2 + 3*x)^2) + (24965*(1 - 2*x)^(3/2))/(31752*(2 + 3*x)) - (24965*ArcTanh[Sqrt[3/7]*Sqrt[1 - 2*x]])/(2268*Sqrt[21])}
{((1 - 2*x)^(5/2)*(3 + 5*x)^2)/(2 + 3*x)^6, x, 6, -((1 - 2*x)^(7/2)/(315*(2 + 3*x)^5)) + (347*(1 - 2*x)^(7/2))/(8820*(2 + 3*x)^4) - (8051*(1 - 2*x)^(5/2))/(26460*(2 + 3*x)^3) + (8051*(1 - 2*x)^(3/2))/(31752*(2 + 3*x)^2) - (8051*Sqrt[1 - 2*x])/(31752*(2 + 3*x)) + (8051*ArcTanh[Sqrt[3/7]*Sqrt[1 - 2*x]])/(15876*Sqrt[21])}
{((1 - 2*x)^(5/2)*(3 + 5*x)^2)/(2 + 3*x)^7, x, 7, -((1 - 2*x)^(7/2)/(378*(2 + 3*x)^6)) + (83*(1 - 2*x)^(7/2))/(2646*(2 + 3*x)^5) - (263*(1 - 2*x)^(5/2))/(1176*(2 + 3*x)^4) + (1315*(1 - 2*x)^(3/2))/(10584*(2 + 3*x)^3) - (1315*Sqrt[1 - 2*x])/(21168*(2 + 3*x)^2) + (1315*Sqrt[1 - 2*x])/(148176*(2 + 3*x)) + (1315*ArcTanh[Sqrt[3/7]*Sqrt[1 - 2*x]])/(74088*Sqrt[21])}
{((1 - 2*x)^(5/2)*(3 + 5*x)^2)/(2 + 3*x)^8, x, 8, -((1 - 2*x)^(7/2)/(441*(2 + 3*x)^7)) + (23*(1 - 2*x)^(7/2))/(882*(2 + 3*x)^6) - (467*(1 - 2*x)^(5/2))/(2646*(2 + 3*x)^5) + (2335*(1 - 2*x)^(3/2))/(31752*(2 + 3*x)^4) - (2335*Sqrt[1 - 2*x])/(95256*(2 + 3*x)^3) + (2335*Sqrt[1 - 2*x])/(1333584*(2 + 3*x)^2) + (2335*Sqrt[1 - 2*x])/(3111696*(2 + 3*x)) + (2335*ArcTanh[Sqrt[3/7]*Sqrt[1 - 2*x]])/(1555848*Sqrt[21])}


{(1 - 2*x)^(5/2)*(2 + 3*x)^4*(3 + 5*x)^3, x, 2, (-(456533/128))*(1 - 2*x)^(7/2) + (3278737/384)*(1 - 2*x)^(9/2) - (1179381/128)*(1 - 2*x)^(11/2) + (9504551*(1 - 2*x)^(13/2))/1664 - (1392467/640)*(1 - 2*x)^(15/2) + (1101465*(1 - 2*x)^(17/2))/2176 - (161325*(1 - 2*x)^(19/2))/2432 + (3375/896)*(1 - 2*x)^(21/2)}
{(1 - 2*x)^(5/2)*(2 + 3*x)^3*(3 + 5*x)^3, x, 2, (-(65219/64))*(1 - 2*x)^(7/2) + (100793/48)*(1 - 2*x)^(9/2) - (121359/64)*(1 - 2*x)^(11/2) + (98209/104)*(1 - 2*x)^(13/2) - (17337/64)*(1 - 2*x)^(15/2) + (675/16)*(1 - 2*x)^(17/2) - (3375*(1 - 2*x)^(19/2))/1216}
{(1 - 2*x)^(5/2)*(2 + 3*x)^2*(3 + 5*x)^3, x, 2, (-(9317/32))*(1 - 2*x)^(7/2) + (16093/32)*(1 - 2*x)^(9/2) - (5847/16)*(1 - 2*x)^(11/2) + (28555/208)*(1 - 2*x)^(13/2) - (845/32)*(1 - 2*x)^(15/2) + (1125/544)*(1 - 2*x)^(17/2)}
{(1 - 2*x)^(5/2)*(2 + 3*x)*(3 + 5*x)^3, x, 2, (-1331*(1 - 2*x)^(7/2))/16 + (2783*(1 - 2*x)^(9/2))/24 - (255*(1 - 2*x)^(11/2))/4 + (1675*(1 - 2*x)^(13/2))/104 - (25*(1 - 2*x)^(15/2))/16}
{(1 - 2*x)^(5/2)*(3 + 5*x)^3, x, 2, (-1331*(1 - 2*x)^(7/2))/56 + (605*(1 - 2*x)^(9/2))/24 - (75*(1 - 2*x)^(11/2))/8 + (125*(1 - 2*x)^(13/2))/104}
{((1 - 2*x)^(5/2)*(3 + 5*x)^3)/(2 + 3*x), x, 7, (-1012658*Sqrt[1 - 2*x])/212625 - (25631*Sqrt[1 - 2*x]*(3 + 5*x)^2)/70875 + (514*Sqrt[1 - 2*x]*(3 + 5*x)^3)/4725 + (34*(1 - 2*x)^(3/2)*(3 + 5*x)^3)/405 + (2*(1 - 2*x)^(5/2)*(3 + 5*x)^3)/33 - (Sqrt[1 - 2*x]*(227389 + 191021*x))/127575 + (98*Sqrt[7/3]*ArcTanh[Sqrt[3/7]*Sqrt[1 - 2*x]])/729}
{((1 - 2*x)^(5/2)*(3 + 5*x)^3)/(2 + 3*x)^2, x, 8, (138578*Sqrt[1 - 2*x])/127575 - (416152*Sqrt[1 - 2*x]*(3 + 5*x))/127575 + (65153*Sqrt[1 - 2*x]*(3 + 5*x)^2)/14175 - (682*Sqrt[1 - 2*x]*(3 + 5*x)^3)/945 - (22*(1 - 2*x)^(3/2)*(3 + 5*x)^3)/81 - ((1 - 2*x)^(5/2)*(3 + 5*x)^3)/(3*(2 + 3*x)) - (1540*Sqrt[7/3]*ArcTanh[Sqrt[3/7]*Sqrt[1 - 2*x]])/729}
{((1 - 2*x)^(5/2)*(3 + 5*x)^3)/(2 + 3*x)^3, x, 8, (-78947*Sqrt[1 - 2*x])/2835 + (89771*Sqrt[1 - 2*x]*(3 + 5*x))/5670 - (7997*Sqrt[1 - 2*x]*(3 + 5*x)^2)/315 + (88*Sqrt[1 - 2*x]*(3 + 5*x)^3)/21 - ((1 - 2*x)^(5/2)*(3 + 5*x)^3)/(6*(2 + 3*x)^2) + (55*(1 - 2*x)^(3/2)*(3 + 5*x)^3)/(9*(2 + 3*x)) + (935*Sqrt[7/3]*ArcTanh[Sqrt[3/7]*Sqrt[1 - 2*x]])/81}
{((1 - 2*x)^(5/2)*(3 + 5*x)^3)/(2 + 3*x)^4, x, 8, (12166*Sqrt[1 - 2*x])/243 - (8294*Sqrt[1 - 2*x]*(3 + 5*x))/243 + (1441*Sqrt[1 - 2*x]*(3 + 5*x)^2)/27 - ((1 - 2*x)^(5/2)*(3 + 5*x)^3)/(9*(2 + 3*x)^3) + (55*(1 - 2*x)^(3/2)*(3 + 5*x)^3)/(27*(2 + 3*x)^2) - (275*Sqrt[1 - 2*x]*(3 + 5*x)^3)/(9*(2 + 3*x)) - (41360*ArcTanh[Sqrt[3/7]*Sqrt[1 - 2*x]])/(243*Sqrt[21])}
{((1 - 2*x)^(5/2)*(3 + 5*x)^3)/(2 + 3*x)^5, x, 8, (-224675*Sqrt[1 - 2*x])/6804 + (252725*Sqrt[1 - 2*x]*(3 + 5*x))/13608 - (2255*Sqrt[1 - 2*x]*(3 + 5*x)^2)/(378*(2 + 3*x)) - ((1 - 2*x)^(5/2)*(3 + 5*x)^3)/(12*(2 + 3*x)^4) + (55*(1 - 2*x)^(3/2)*(3 + 5*x)^3)/(54*(2 + 3*x)^3) - (55*Sqrt[1 - 2*x]*(3 + 5*x)^3)/(24*(2 + 3*x)^2) + (645865*ArcTanh[Sqrt[3/7]*Sqrt[1 - 2*x]])/(6804*Sqrt[21])}
{((1 - 2*x)^(5/2)*(3 + 5*x)^3)/(2 + 3*x)^6, x, 8, (-715*Sqrt[1 - 2*x])/7938 - (13387*Sqrt[1 - 2*x]*(3 + 5*x))/(15876*(2 + 3*x)) - (209*Sqrt[1 - 2*x]*(3 + 5*x)^2)/(756*(2 + 3*x)^2) - ((1 - 2*x)^(5/2)*(3 + 5*x)^3)/(15*(2 + 3*x)^5) + (11*(1 - 2*x)^(3/2)*(3 + 5*x)^3)/(18*(2 + 3*x)^4) + (11*Sqrt[1 - 2*x]*(3 + 5*x)^3)/(9*(2 + 3*x)^3) - (146971*ArcTanh[Sqrt[3/7]*Sqrt[1 - 2*x]])/(7938*Sqrt[21])}
{((1 - 2*x)^(5/2)*(3 + 5*x)^3)/(2 + 3*x)^7, x, 9, -((121*(1 - 2*x)^(3/2))/(4536*(2 + 3*x)^4)) + (33275*(1 - 2*x)^(3/2))/(95256*(2 + 3*x)^3) - (559625*Sqrt[1 - 2*x])/(190512*(2 + 3*x)^2) + (559625*Sqrt[1 - 2*x])/(1333584*(2 + 3*x)) - ((1 - 2*x)^(5/2)*(3 + 5*x)^3)/(18*(2 + 3*x)^6) + (11*(1 - 2*x)^(3/2)*(3 + 5*x)^3)/(27*(2 + 3*x)^5) + (559625*ArcTanh[Sqrt[3/7]*Sqrt[1 - 2*x]])/(666792*Sqrt[21])}
{((1 - 2*x)^(5/2)*(3 + 5*x)^3)/(2 + 3*x)^8, x, 9, (11*(3833 - 4355*x)*Sqrt[1 - 2*x])/(166698*(2 + 3*x)^3) - (153505*Sqrt[1 - 2*x])/(47628*(2 + 3*x)^2) + (33935*Sqrt[1 - 2*x])/(2333772*(2 + 3*x)) - (3223*Sqrt[1 - 2*x]*(3 + 5*x)^2)/(2646*(2 + 3*x)^4) - ((1 - 2*x)^(5/2)*(3 + 5*x)^3)/(21*(2 + 3*x)^7) + (55*(1 - 2*x)^(3/2)*(3 + 5*x)^3)/(189*(2 + 3*x)^6) + (11*Sqrt[1 - 2*x]*(3 + 5*x)^3)/(7*(2 + 3*x)^5) + (33935*ArcTanh[Sqrt[3/7]*Sqrt[1 - 2*x]])/(1166886*Sqrt[21])}


(* ::Subsubsection::Closed:: *)
(*n<0*)


{((1 - 2*x)^(5/2)*(2 + 3*x)^4)/(3 + 5*x), x, 8, (-601617098*Sqrt[1 - 2*x])/301640625 - (669943*Sqrt[1 - 2*x]*(2 + 3*x))/2413125 - (829256*Sqrt[1 - 2*x]*(2 + 3*x)^2)/20109375 + (861947*Sqrt[1 - 2*x]*(2 + 3*x)^3)/16891875 + (4138*Sqrt[1 - 2*x]*(2 + 3*x)^4)/482625 + (298*(1 - 2*x)^(3/2)*(2 + 3*x)^4)/10725 + (2*(1 - 2*x)^(5/2)*(2 + 3*x)^4)/65 - (242*Sqrt[11/5]*ArcTanh[Sqrt[5/11]*Sqrt[1 - 2*x]])/78125}
{((1 - 2*x)^(5/2)*(2 + 3*x)^3)/(3 + 5*x), x, 7, (-207982*Sqrt[1 - 2*x])/171875 + (6221*Sqrt[1 - 2*x]*(2 + 3*x)^2)/103125 + (706*Sqrt[1 - 2*x]*(2 + 3*x)^3)/28875 + (34*(1 - 2*x)^(3/2)*(2 + 3*x)^3)/825 + (2*(1 - 2*x)^(5/2)*(2 + 3*x)^3)/55 - (Sqrt[1 - 2*x]*(177948 + 223375*x))/515625 - (242*Sqrt[11/5]*ArcTanh[Sqrt[5/11]*Sqrt[1 - 2*x]])/15625}
{((1 - 2*x)^(5/2)*(2 + 3*x)^2)/(3 + 5*x), x, 6, (242*Sqrt[1 - 2*x])/3125 + (22*(1 - 2*x)^(3/2))/1875 + (2/625)*(1 - 2*x)^(5/2) - (44/525)*(1 - 2*x)^(7/2) - (1/15)*(1 - 2*x)^(7/2)*(2 + 3*x) - (242*Sqrt[11/5]*ArcTanh[Sqrt[5/11]*Sqrt[1 - 2*x]])/3125}
{((1 - 2*x)^(5/2)*(2 + 3*x))/(3 + 5*x), x, 5, (242*Sqrt[1 - 2*x])/625 + (22*(1 - 2*x)^(3/2))/375 + (2*(1 - 2*x)^(5/2))/125 - (3*(1 - 2*x)^(7/2))/35 - (242*Sqrt[11/5]*ArcTanh[Sqrt[5/11]*Sqrt[1 - 2*x]])/625}
{(1 - 2*x)^(5/2)/(3 + 5*x), x, 4, (242*Sqrt[1 - 2*x])/125 + (22*(1 - 2*x)^(3/2))/75 + (2*(1 - 2*x)^(5/2))/25 - (242*Sqrt[11/5]*ArcTanh[Sqrt[5/11]*Sqrt[1 - 2*x]])/125}
{(1 - 2*x)^(5/2)/((2 + 3*x)*(3 + 5*x)), x, 5, (-272*Sqrt[1 - 2*x])/225 - (4*(1 - 2*x)^(3/2))/45 + (98*Sqrt[7/3]*ArcTanh[Sqrt[3/7]*Sqrt[1 - 2*x]])/9 - (242*Sqrt[11/5]*ArcTanh[Sqrt[5/11]*Sqrt[1 - 2*x]])/25}
{(1 - 2*x)^(5/2)/((2 + 3*x)^2*(3 + 5*x)), x, 6, (26*Sqrt[1 - 2*x])/15 + (2*(1 - 2*x)^(3/2))/3 + (1 - 2*x)^(5/2)/(2 + 3*x) + (140*Sqrt[7/3]*ArcTanh[Sqrt[3/7]*Sqrt[1 - 2*x]])/3 - (242*Sqrt[11/5]*ArcTanh[Sqrt[5/11]*Sqrt[1 - 2*x]])/5}
{(1 - 2*x)^(5/2)/((2 + 3*x)^3*(3 + 5*x)), x, 6, 7*Sqrt[1 - 2*x] + (1 - 2*x)^(5/2)/(2*(2 + 3*x)^2) + (65*(1 - 2*x)^(3/2))/(6*(2 + 3*x)) + 235*Sqrt[7/3]*ArcTanh[Sqrt[3/7]*Sqrt[1 - 2*x]] - 242*Sqrt[11/5]*ArcTanh[Sqrt[5/11]*Sqrt[1 - 2*x]]}
{(1 - 2*x)^(5/2)/((2 + 3*x)^4*(3 + 5*x)), x, 6, (1 - 2*x)^(5/2)/(3*(2 + 3*x)^3) + (50*(1 - 2*x)^(3/2))/(9*(2 + 3*x)^2) + (1105*Sqrt[1 - 2*x])/(9*(2 + 3*x)) + (74020*ArcTanh[Sqrt[3/7]*Sqrt[1 - 2*x]])/(9*Sqrt[21]) - 242*Sqrt[55]*ArcTanh[Sqrt[5/11]*Sqrt[1 - 2*x]]}
{(1 - 2*x)^(5/2)/((2 + 3*x)^5*(3 + 5*x)), x, 7, (1 - 2*x)^(5/2)/(4*(2 + 3*x)^4) + (15*(1 - 2*x)^(3/2))/(4*(2 + 3*x)^3) + (1495*Sqrt[1 - 2*x])/(24*(2 + 3*x)^2) + (100145*Sqrt[1 - 2*x])/(168*(2 + 3*x)) + (3454265*ArcTanh[Sqrt[3/7]*Sqrt[1 - 2*x]])/(84*Sqrt[21]) - 1210*Sqrt[55]*ArcTanh[Sqrt[5/11]*Sqrt[1 - 2*x]]}
{(1 - 2*x)^(5/2)/((2 + 3*x)^6*(3 + 5*x)), x, 8, (1 - 2*x)^(5/2)/(5*(2 + 3*x)^5) + (17*(1 - 2*x)^(3/2))/(6*(2 + 3*x)^4) + (251*Sqrt[1 - 2*x])/(6*(2 + 3*x)^3) + (25159*Sqrt[1 - 2*x])/(84*(2 + 3*x)^2) + (584179*Sqrt[1 - 2*x])/(196*(2 + 3*x)) + (20149879*ArcTanh[Sqrt[3/7]*Sqrt[1 - 2*x]])/(98*Sqrt[21]) - 6050*Sqrt[55]*ArcTanh[Sqrt[5/11]*Sqrt[1 - 2*x]]}
{(1 - 2*x)^(5/2)/((2 + 3*x)^7*(3 + 5*x)), x, 9, (1 - 2*x)^(5/2)/(6*(2 + 3*x)^6) + (41*(1 - 2*x)^(3/2))/(18*(2 + 3*x)^5) + (2269*Sqrt[1 - 2*x])/(72*(2 + 3*x)^4) + (302651*Sqrt[1 - 2*x])/(1512*(2 + 3*x)^3) + (31700335*Sqrt[1 - 2*x])/(21168*(2 + 3*x)^2) + (736065535*Sqrt[1 - 2*x])/(49392*(2 + 3*x)) + (25388847535*ArcTanh[Sqrt[3/7]*Sqrt[1 - 2*x]])/(24696*Sqrt[21]) - 30250*Sqrt[55]*ArcTanh[Sqrt[5/11]*Sqrt[1 - 2*x]]}


{((1 - 2*x)^(5/2)*(2 + 3*x)^4)/(3 + 5*x)^2, x, 8, (-20103122*Sqrt[1 - 2*x])/23203125 - (7327*Sqrt[1 - 2*x]*(2 + 3*x))/185625 + (312916*Sqrt[1 - 2*x]*(2 + 3*x)^2)/1546875 + (975383*Sqrt[1 - 2*x]*(2 + 3*x)^3)/1299375 - (8318*Sqrt[1 - 2*x]*(2 + 3*x)^4)/37125 - (26*(1 - 2*x)^(3/2)*(2 + 3*x)^4)/275 - ((1 - 2*x)^(5/2)*(2 + 3*x)^4)/(5*(3 + 5*x)) - (2794*Sqrt[11/5]*ArcTanh[Sqrt[5/11]*Sqrt[1 - 2*x]])/78125}
{((1 - 2*x)^(5/2)*(2 + 3*x)^3)/(3 + 5*x)^2, x, 7, (-224794*Sqrt[1 - 2*x])/421875 + (796*Sqrt[1 - 2*x]*(2 + 3*x))/3375 + (23357*Sqrt[1 - 2*x]*(2 + 3*x)^2)/28125 - (1898*Sqrt[1 - 2*x]*(2 + 3*x)^3)/7875 - (22*(1 - 2*x)^(3/2)*(2 + 3*x)^3)/225 - ((1 - 2*x)^(5/2)*(2 + 3*x)^3)/(5*(3 + 5*x)) - (2068*Sqrt[11/5]*ArcTanh[Sqrt[5/11]*Sqrt[1 - 2*x]])/15625}
{((1 - 2*x)^(5/2)*(2 + 3*x)^2)/(3 + 5*x)^2, x, 6, (1342*Sqrt[1 - 2*x])/3125 + (122*(1 - 2*x)^(3/2))/1875 + (122*(1 - 2*x)^(5/2))/6875 - (9/175)*(1 - 2*x)^(7/2) - (1 - 2*x)^(7/2)/(275*(3 + 5*x)) - (1342*Sqrt[11/5]*ArcTanh[Sqrt[5/11]*Sqrt[1 - 2*x]])/3125}
{((1 - 2*x)^(5/2)*(2 + 3*x))/(3 + 5*x)^2, x, 5, (616*Sqrt[1 - 2*x])/625 + (56*(1 - 2*x)^(3/2))/375 + (56*(1 - 2*x)^(5/2))/1375 - (1 - 2*x)^(7/2)/(55*(3 + 5*x)) - (616*Sqrt[11/5]*ArcTanh[Sqrt[5/11]*Sqrt[1 - 2*x]])/625}
{(1 - 2*x)^(5/2)/(3 + 5*x)^2, x, 4, (-22*Sqrt[1 - 2*x])/25 - (2*(1 - 2*x)^(3/2))/15 - (1 - 2*x)^(5/2)/(5*(3 + 5*x)) + (22*Sqrt[11/5]*ArcTanh[Sqrt[5/11]*Sqrt[1 - 2*x]])/25}
{(1 - 2*x)^(5/2)/((2 + 3*x)*(3 + 5*x)^2), x, 6, (-58*Sqrt[1 - 2*x])/75 - (2*(1 - 2*x)^(3/2))/5 - (1 - 2*x)^(5/2)/(3 + 5*x) - (98*Sqrt[7/3]*ArcTanh[Sqrt[3/7]*Sqrt[1 - 2*x]])/3 + (836*Sqrt[11/5]*ArcTanh[Sqrt[5/11]*Sqrt[1 - 2*x]])/25}
{(1 - 2*x)^(5/2)/((2 + 3*x)^2*(3 + 5*x)^2), x, 6, (-136*Sqrt[1 - 2*x])/15 - (22*(1 - 2*x)^(3/2))/(3 + 5*x) + (1 - 2*x)^(5/2)/((2 + 3*x)*(3 + 5*x)) - (910*Sqrt[7/3]*ArcTanh[Sqrt[3/7]*Sqrt[1 - 2*x]])/3 + (1562*Sqrt[11/5]*ArcTanh[Sqrt[5/11]*Sqrt[1 - 2*x]])/5}
{(1 - 2*x)^(5/2)/((2 + 3*x)^3*(3 + 5*x)^2), x, 6, (-2189*Sqrt[1 - 2*x])/(6*(3 + 5*x)) + (1 - 2*x)^(5/2)/(2*(2 + 3*x)^2*(3 + 5*x)) + (50*(1 - 2*x)^(3/2))/(3*(2 + 3*x)*(3 + 5*x)) - (6665*Sqrt[7/3]*ArcTanh[Sqrt[3/7]*Sqrt[1 - 2*x]])/3 + 2288*Sqrt[11/5]*ArcTanh[Sqrt[5/11]*Sqrt[1 - 2*x]]}
{(1 - 2*x)^(5/2)/((2 + 3*x)^4*(3 + 5*x)^2), x, 7, (-44545*Sqrt[1 - 2*x])/(18*(3 + 5*x)) + (1 - 2*x)^(5/2)/(3*(2 + 3*x)^3*(3 + 5*x)) + (15*(1 - 2*x)^(3/2))/(2*(2 + 3*x)^2*(3 + 5*x)) + (2260*Sqrt[1 - 2*x])/(9*(2 + 3*x)*(3 + 5*x)) - (307295*ArcTanh[Sqrt[3/7]*Sqrt[1 - 2*x]])/(3*Sqrt[21]) + 3014*Sqrt[55]*ArcTanh[Sqrt[5/11]*Sqrt[1 - 2*x]]}
{(1 - 2*x)^(5/2)/((2 + 3*x)^5*(3 + 5*x)^2), x, 8, (-7738475*Sqrt[1 - 2*x])/(504*(3 + 5*x)) + (1 - 2*x)^(5/2)/(4*(2 + 3*x)^4*(3 + 5*x)) + (85*(1 - 2*x)^(3/2))/(18*(2 + 3*x)^3*(3 + 5*x)) + (22765*Sqrt[1 - 2*x])/(216*(2 + 3*x)^2*(3 + 5*x)) + (288770*Sqrt[1 - 2*x])/(189*(2 + 3*x)*(3 + 5*x)) - (53384095*ArcTanh[Sqrt[3/7]*Sqrt[1 - 2*x]])/(84*Sqrt[21]) + 18700*Sqrt[55]*ArcTanh[Sqrt[5/11]*Sqrt[1 - 2*x]]}
{(1 - 2*x)^(5/2)/((2 + 3*x)^6*(3 + 5*x)^2), x, 9, (-323422735*Sqrt[1 - 2*x])/(3528*(3 + 5*x)) + (1 - 2*x)^(5/2)/(5*(2 + 3*x)^5*(3 + 5*x)) + (41*(1 - 2*x)^(3/2))/(12*(2 + 3*x)^4*(3 + 5*x)) + (1714*Sqrt[1 - 2*x])/(27*(2 + 3*x)^3*(3 + 5*x)) + (924025*Sqrt[1 - 2*x])/(1512*(2 + 3*x)^2*(3 + 5*x)) + (12068887*Sqrt[1 - 2*x])/(1323*(2 + 3*x)*(3 + 5*x)) - (2231141147*ArcTanh[Sqrt[3/7]*Sqrt[1 - 2*x]])/(588*Sqrt[21]) + 111650*Sqrt[55]*ArcTanh[Sqrt[5/11]*Sqrt[1 - 2*x]]}


{((1 - 2*x)^(5/2)*(2 + 3*x)^4)/(3 + 5*x)^3, x, 8, (50557*Sqrt[1 - 2*x])/78125 - ((118254 - 449875*x)*Sqrt[1 - 2*x])/468750 + (44804*Sqrt[1 - 2*x]*(2 + 3*x)^2)/46875 + (250829*Sqrt[1 - 2*x]*(2 + 3*x)^3)/78750 - (1117*Sqrt[1 - 2*x]*(2 + 3*x)^4)/1125 - ((1 - 2*x)^(5/2)*(2 + 3*x)^4)/(10*(3 + 5*x)^2) - (127*(1 - 2*x)^(3/2)*(2 + 3*x)^4)/(50*(3 + 5*x)) - (11763*Sqrt[11/5]*ArcTanh[Sqrt[5/11]*Sqrt[1 - 2*x]])/78125}
{((1 - 2*x)^(5/2)*(2 + 3*x)^3)/(3 + 5*x)^3, x, 7, (5839*Sqrt[1 - 2*x])/15625 + (223*Sqrt[1 - 2*x]*(2 + 3*x))/250 + (7149*Sqrt[1 - 2*x]*(2 + 3*x)^2)/3125 - (636*Sqrt[1 - 2*x]*(2 + 3*x)^3)/875 - ((1 - 2*x)^(5/2)*(2 + 3*x)^3)/(10*(3 + 5*x)^2) - (47*(1 - 2*x)^(3/2)*(2 + 3*x)^3)/(25*(3 + 5*x)) - (5559*Sqrt[11/5]*ArcTanh[Sqrt[5/11]*Sqrt[1 - 2*x]])/15625}
{((1 - 2*x)^(5/2)*(2 + 3*x)^2)/(3 + 5*x)^3, x, 6, (1533*Sqrt[1 - 2*x])/3125 + (511*(1 - 2*x)^(3/2))/6875 + (1533*(1 - 2*x)^(5/2))/75625 - (1 - 2*x)^(7/2)/(550*(3 + 5*x)^2) - (129*(1 - 2*x)^(7/2))/(6050*(3 + 5*x)) - (1533*Sqrt[11/5]*ArcTanh[Sqrt[5/11]*Sqrt[1 - 2*x]])/3125}
{((1 - 2*x)^(5/2)*(2 + 3*x))/(3 + 5*x)^3, x, 5, (-63*Sqrt[1 - 2*x])/125 - (21*(1 - 2*x)^(3/2))/275 - (1 - 2*x)^(7/2)/(110*(3 + 5*x)^2) - (63*(1 - 2*x)^(5/2))/(550*(3 + 5*x)) + (63*Sqrt[11/5]*ArcTanh[Sqrt[5/11]*Sqrt[1 - 2*x]])/125}
{(1 - 2*x)^(5/2)/(3 + 5*x)^3, x, 4, (3*Sqrt[1 - 2*x])/25 - (1 - 2*x)^(5/2)/(10*(3 + 5*x)^2) + (1 - 2*x)^(3/2)/(10*(3 + 5*x)) - (3*Sqrt[11/5]*ArcTanh[Sqrt[5/11]*Sqrt[1 - 2*x]])/25}
{(1 - 2*x)^(5/2)/((2 + 3*x)*(3 + 5*x)^3), x, 6, (73*Sqrt[1 - 2*x])/25 - (1 - 2*x)^(5/2)/(2*(3 + 5*x)^2) + (71*(1 - 2*x)^(3/2))/(10*(3 + 5*x)) + 98*Sqrt[7/3]*ArcTanh[Sqrt[3/7]*Sqrt[1 - 2*x]] - (2523*Sqrt[11/5]*ArcTanh[Sqrt[5/11]*Sqrt[1 - 2*x]])/25}
{(1 - 2*x)^(5/2)/((2 + 3*x)^2*(3 + 5*x)^3), x, 6, (-33*(1 - 2*x)^(3/2))/(2*(3 + 5*x)^2) + (1 - 2*x)^(5/2)/((2 + 3*x)*(3 + 5*x)^2) + (2299*Sqrt[1 - 2*x])/(10*(3 + 5*x)) + 1400*Sqrt[7/3]*ArcTanh[Sqrt[3/7]*Sqrt[1 - 2*x]] - (7209*Sqrt[11/5]*ArcTanh[Sqrt[5/11]*Sqrt[1 - 2*x]])/5}
{(1 - 2*x)^(5/2)/((2 + 3*x)^3*(3 + 5*x)^3), x, 7, (-737*Sqrt[1 - 2*x])/(2*(3 + 5*x)^2) + (1 - 2*x)^(5/2)/(2*(2 + 3*x)^2*(3 + 5*x)^2) + (45*(1 - 2*x)^(3/2))/(2*(2 + 3*x)*(3 + 5*x)^2) + (2311*Sqrt[1 - 2*x])/(3 + 5*x) + 4555*Sqrt[21]*ArcTanh[Sqrt[3/7]*Sqrt[1 - 2*x]] - 14073*Sqrt[11/5]*ArcTanh[Sqrt[5/11]*Sqrt[1 - 2*x]]}
{(1 - 2*x)^(5/2)/((2 + 3*x)^4*(3 + 5*x)^3), x, 8, (-169975*Sqrt[1 - 2*x])/(54*(3 + 5*x)^2) + (1 - 2*x)^(5/2)/(3*(2 + 3*x)^3*(3 + 5*x)^2) + (85*(1 - 2*x)^(3/2))/(9*(2 + 3*x)^2*(3 + 5*x)^2) + (11470*Sqrt[1 - 2*x])/(27*(2 + 3*x)*(3 + 5*x)^2) + (113875*Sqrt[1 - 2*x])/(6*(3 + 5*x)) + (785570*ArcTanh[Sqrt[3/7]*Sqrt[1 - 2*x]])/Sqrt[21] - 23115*Sqrt[55]*ArcTanh[Sqrt[5/11]*Sqrt[1 - 2*x]]}
{(1 - 2*x)^(5/2)/((2 + 3*x)^5*(3 + 5*x)^3), x, 9, (-8836825*Sqrt[1 - 2*x])/(378*(3 + 5*x)^2) + (1 - 2*x)^(5/2)/(4*(2 + 3*x)^4*(3 + 5*x)^2) + (205*(1 - 2*x)^(3/2))/(36*(2 + 3*x)^3*(3 + 5*x)^2) + (34525*Sqrt[1 - 2*x])/(216*(2 + 3*x)^2*(3 + 5*x)^2) + (522385*Sqrt[1 - 2*x])/(168*(2 + 3*x)*(3 + 5*x)^2) + (23680975*Sqrt[1 - 2*x])/(168*(3 + 5*x)) + (163363895*ArcTanh[Sqrt[3/7]*Sqrt[1 - 2*x]])/(28*Sqrt[21]) - 171675*Sqrt[55]*ArcTanh[Sqrt[5/11]*Sqrt[1 - 2*x]]}


(* ::Subsection::Closed:: *)
(*Integrands of the form (a+b x)^m (c+d x)^n / (e+f x)^(1/2)*)


(* ::Subsubsection::Closed:: *)
(*n>0*)


{((2 + 3*x)^5*(3 + 5*x))/Sqrt[1 - 2*x], x, 2, (-184877*Sqrt[1 - 2*x])/64 + (60025*(1 - 2*x)^(3/2))/24 - (103929*(1 - 2*x)^(5/2))/64 + (5355*(1 - 2*x)^(7/2))/8 - (10815*(1 - 2*x)^(9/2))/64 + (1053*(1 - 2*x)^(11/2))/44 - (1215*(1 - 2*x)^(13/2))/832}
{((2 + 3*x)^4*(3 + 5*x))/Sqrt[1 - 2*x], x, 2, (-26411*Sqrt[1 - 2*x])/32 + (57281*(1 - 2*x)^(3/2))/96 - (24843*(1 - 2*x)^(5/2))/80 + (1539*(1 - 2*x)^(7/2))/16 - (519*(1 - 2*x)^(9/2))/32 + (405*(1 - 2*x)^(11/2))/352}
{((2 + 3*x)^3*(3 + 5*x))/Sqrt[1 - 2*x], x, 2, (-3773*Sqrt[1 - 2*x])/16 + (3283*(1 - 2*x)^(3/2))/24 - (1071*(1 - 2*x)^(5/2))/20 + (621*(1 - 2*x)^(7/2))/56 - (15*(1 - 2*x)^(9/2))/16}
{((2 + 3*x)^2*(3 + 5*x))/Sqrt[1 - 2*x], x, 2, (-539*Sqrt[1 - 2*x])/8 + (707*(1 - 2*x)^(3/2))/24 - (309*(1 - 2*x)^(5/2))/40 + (45*(1 - 2*x)^(7/2))/56}
{((2 + 3*x)*(3 + 5*x))/Sqrt[1 - 2*x], x, 2, (-77*Sqrt[1 - 2*x])/4 + (17*(1 - 2*x)^(3/2))/3 - (3*(1 - 2*x)^(5/2))/4}
{(3 + 5*x)/Sqrt[1 - 2*x], x, 2, (-11*Sqrt[1 - 2*x])/2 + (5*(1 - 2*x)^(3/2))/6}
{(3 + 5*x)/(Sqrt[1 - 2*x]*(2 + 3*x)), x, 2, (-5*Sqrt[1 - 2*x])/3 + (2*ArcTanh[Sqrt[3/7]*Sqrt[1 - 2*x]])/(3*Sqrt[21])}
{(3 + 5*x)/(Sqrt[1 - 2*x]*(2 + 3*x)^2), x, 2, Sqrt[1 - 2*x]/(21*(2 + 3*x)) - (68*ArcTanh[Sqrt[3/7]*Sqrt[1 - 2*x]])/(21*Sqrt[21])}
{(3 + 5*x)/(Sqrt[1 - 2*x]*(2 + 3*x)^3), x, 3, Sqrt[1 - 2*x]/(42*(2 + 3*x)^2) - (67*Sqrt[1 - 2*x])/(294*(2 + 3*x)) - (67*ArcTanh[Sqrt[3/7]*Sqrt[1 - 2*x]])/(147*Sqrt[21])}
{(3 + 5*x)/(Sqrt[1 - 2*x]*(2 + 3*x)^4), x, 4, Sqrt[1 - 2*x]/(63*(2 + 3*x)^3) - (50*Sqrt[1 - 2*x])/(441*(2 + 3*x)^2) - (50*Sqrt[1 - 2*x])/(1029*(2 + 3*x)) - (100*ArcTanh[Sqrt[3/7]*Sqrt[1 - 2*x]])/(1029*Sqrt[21])}
{(3 + 5*x)/(Sqrt[1 - 2*x]*(2 + 3*x)^5), x, 5, Sqrt[1 - 2*x]/(84*(2 + 3*x)^4) - (19*Sqrt[1 - 2*x])/(252*(2 + 3*x)^3) - (95*Sqrt[1 - 2*x])/(3528*(2 + 3*x)^2) - (95*Sqrt[1 - 2*x])/(8232*(2 + 3*x)) - (95*ArcTanh[Sqrt[3/7]*Sqrt[1 - 2*x]])/(4116*Sqrt[21])}


{((2 + 3*x)^5*(3 + 5*x)^2)/Sqrt[1 - 2*x], x, 2, (-(2033647/128))*Sqrt[1 - 2*x] + (6206585/384)*(1 - 2*x)^(3/2) - (1623419/128)*(1 - 2*x)^(5/2) + (842415/128)*(1 - 2*x)^(7/2) - (285565/128)*(1 - 2*x)^(9/2) + (672003*(1 - 2*x)^(11/2))/1408 - (97605*(1 - 2*x)^(13/2))/1664 + (405/128)*(1 - 2*x)^(15/2)}
{((2 + 3*x)^4*(3 + 5*x)^2)/Sqrt[1 - 2*x], x, 2, (-(290521/64))*Sqrt[1 - 2*x] + (381073/96)*(1 - 2*x)^(3/2) - (832951/320)*(1 - 2*x)^(5/2) + (17337/16)*(1 - 2*x)^(7/2) - (17679/64)*(1 - 2*x)^(9/2) + (13905/352)*(1 - 2*x)^(11/2) - (2025/832)*(1 - 2*x)^(13/2)}
{((2 + 3*x)^3*(3 + 5*x)^2)/Sqrt[1 - 2*x], x, 2, (-(41503/32))*Sqrt[1 - 2*x] + (91091/96)*(1 - 2*x)^(3/2) - (39977/80)*(1 - 2*x)^(5/2) + (17541/112)*(1 - 2*x)^(7/2) - (855/32)*(1 - 2*x)^(9/2) + (675/352)*(1 - 2*x)^(11/2)}
{((2 + 3*x)^2*(3 + 5*x)^2)/Sqrt[1 - 2*x], x, 2, (-(5929/16))*Sqrt[1 - 2*x] + (1309/6)*(1 - 2*x)^(3/2) - (3467/40)*(1 - 2*x)^(5/2) + (255/14)*(1 - 2*x)^(7/2) - (25/16)*(1 - 2*x)^(9/2)}
{((2 + 3*x)*(3 + 5*x)^2)/Sqrt[1 - 2*x], x, 2, (-847*Sqrt[1 - 2*x])/8 + (1133*(1 - 2*x)^(3/2))/24 - (101*(1 - 2*x)^(5/2))/8 + (75*(1 - 2*x)^(7/2))/56}
{(3 + 5*x)^2/Sqrt[1 - 2*x], x, 2, (-121*Sqrt[1 - 2*x])/4 + (55*(1 - 2*x)^(3/2))/6 - (5*(1 - 2*x)^(5/2))/4}
{(3 + 5*x)^2/(Sqrt[1 - 2*x]*(2 + 3*x)), x, 3, (-(5/9))*Sqrt[1 - 2*x]*(13 + 5*x) - (2*ArcTanh[Sqrt[3/7]*Sqrt[1 - 2*x]])/(9*Sqrt[21]), (-(50/9))*Sqrt[1 - 2*x] - (5/9)*Sqrt[1 - 2*x]*(3 + 5*x) - (2*ArcTanh[Sqrt[3/7]*Sqrt[1 - 2*x]])/(9*Sqrt[21])}
{(3 + 5*x)^2/(Sqrt[1 - 2*x]*(2 + 3*x)^2), x, 3, (-(25/9))*Sqrt[1 - 2*x] - Sqrt[1 - 2*x]/(63*(2 + 3*x)) + (46*ArcTanh[Sqrt[3/7]*Sqrt[1 - 2*x]])/(21*Sqrt[21])}
{(3 + 5*x)^2/(Sqrt[1 - 2*x]*(2 + 3*x)^3), x, 3, -(Sqrt[1 - 2*x]/(126*(2 + 3*x)^2)) + (137*Sqrt[1 - 2*x])/(882*(2 + 3*x)) - (257*ArcTanh[Sqrt[3/7]*Sqrt[1 - 2*x]])/(49*Sqrt[21])}
{(3 + 5*x)^2/(Sqrt[1 - 2*x]*(2 + 3*x)^4), x, 4, -(Sqrt[1 - 2*x]/(189*(2 + 3*x)^3)) + (205*Sqrt[1 - 2*x])/(2646*(2 + 3*x)^2) - (2245*Sqrt[1 - 2*x])/(6174*(2 + 3*x)) - (2245*ArcTanh[Sqrt[3/7]*Sqrt[1 - 2*x]])/(3087*Sqrt[21])}
{(3 + 5*x)^2/(Sqrt[1 - 2*x]*(2 + 3*x)^5), x, 5, -(Sqrt[1 - 2*x]/(252*(2 + 3*x)^4)) + (13*Sqrt[1 - 2*x])/(252*(2 + 3*x)^3) - (635*Sqrt[1 - 2*x])/(3528*(2 + 3*x)^2) - (635*Sqrt[1 - 2*x])/(8232*(2 + 3*x)) - (635*ArcTanh[Sqrt[3/7]*Sqrt[1 - 2*x]])/(4116*Sqrt[21])}
{(3 + 5*x)^2/(Sqrt[1 - 2*x]*(2 + 3*x)^6), x, 6, -(Sqrt[1 - 2*x]/(315*(2 + 3*x)^5)) + (341*Sqrt[1 - 2*x])/(8820*(2 + 3*x)^4) - (117*Sqrt[1 - 2*x])/(980*(2 + 3*x)^3) - (117*Sqrt[1 - 2*x])/(2744*(2 + 3*x)^2) - (351*Sqrt[1 - 2*x])/(19208*(2 + 3*x)) - (117*Sqrt[3/7]*ArcTanh[Sqrt[3/7]*Sqrt[1 - 2*x]])/9604}


{((2 + 3*x)^4*(3 + 5*x)^3)/Sqrt[1 - 2*x], x, 2, (-(3195731/128))*Sqrt[1 - 2*x] + (3278737/128)*(1 - 2*x)^(3/2) - (12973191/640)*(1 - 2*x)^(5/2) + (1357793/128)*(1 - 2*x)^(7/2) - (1392467/384)*(1 - 2*x)^(9/2) + (1101465*(1 - 2*x)^(11/2))/1408 - (161325*(1 - 2*x)^(13/2))/1664 + (675/128)*(1 - 2*x)^(15/2)}
{((2 + 3*x)^3*(3 + 5*x)^3)/Sqrt[1 - 2*x], x, 2, (-(456533/64))*Sqrt[1 - 2*x] + (100793/16)*(1 - 2*x)^(3/2) - (1334949/320)*(1 - 2*x)^(5/2) + (98209/56)*(1 - 2*x)^(7/2) - (28895/64)*(1 - 2*x)^(9/2) + (11475/176)*(1 - 2*x)^(11/2) - (3375/832)*(1 - 2*x)^(13/2)}
{((2 + 3*x)^2*(3 + 5*x)^3)/Sqrt[1 - 2*x], x, 2, (-(65219/32))*Sqrt[1 - 2*x] + (48279/32)*(1 - 2*x)^(3/2) - (64317/80)*(1 - 2*x)^(5/2) + (28555/112)*(1 - 2*x)^(7/2) - (4225/96)*(1 - 2*x)^(9/2) + (1125/352)*(1 - 2*x)^(11/2)}
{((2 + 3*x)*(3 + 5*x)^3)/Sqrt[1 - 2*x], x, 2, (-9317*Sqrt[1 - 2*x])/16 + (2783*(1 - 2*x)^(3/2))/8 - (561*(1 - 2*x)^(5/2))/4 + (1675*(1 - 2*x)^(7/2))/56 - (125*(1 - 2*x)^(9/2))/48}
{(3 + 5*x)^3/Sqrt[1 - 2*x], x, 2, (-1331*Sqrt[1 - 2*x])/8 + (605*(1 - 2*x)^(3/2))/8 - (165*(1 - 2*x)^(5/2))/8 + (125*(1 - 2*x)^(7/2))/56}
{(3 + 5*x)^3/(Sqrt[1 - 2*x]*(2 + 3*x)), x, 4, (-(218/9))*Sqrt[1 - 2*x] - (1/3)*Sqrt[1 - 2*x]*(3 + 5*x)^2 - (5/27)*Sqrt[1 - 2*x]*(41 + 61*x) + (2*ArcTanh[Sqrt[3/7]*Sqrt[1 - 2*x]])/(27*Sqrt[21])}
{(3 + 5*x)^3/(Sqrt[1 - 2*x]*(2 + 3*x)^2), x, 4, (-1570*Sqrt[1 - 2*x])/189 - (38*Sqrt[1 - 2*x]*(3 + 5*x))/(189*(2 + 3*x)) - (5*Sqrt[1 - 2*x]*(3 + 5*x)^2)/(9*(2 + 3*x)) - (208*ArcTanh[Sqrt[3/7]*Sqrt[1 - 2*x]])/(189*Sqrt[21])}
{(3 + 5*x)^3/(Sqrt[1 - 2*x]*(2 + 3*x)^3), x, 4, ((7 - 25*x)*Sqrt[1 - 2*x])/(126*(2 + 3*x)^2) - (274*Sqrt[1 - 2*x])/(147*(2 + 3*x)) - (5*Sqrt[1 - 2*x]*(3 + 5*x)^2)/(3*(2 + 3*x)^2) + (2381*ArcTanh[Sqrt[3/7]*Sqrt[1 - 2*x]])/(441*Sqrt[21])}
{(3 + 5*x)^3/(Sqrt[1 - 2*x]*(2 + 3*x)^4), x, 5, (10600*Sqrt[1 - 2*x])/9261 - (3385*Sqrt[1 - 2*x]*(3 + 5*x))/(9261*(2 + 3*x)) - (50*Sqrt[1 - 2*x]*(3 + 5*x)^2)/(441*(2 + 3*x)^2) - (Sqrt[1 - 2*x]*(3 + 5*x)^3)/(21*(2 + 3*x)^3) - (78710*ArcTanh[Sqrt[3/7]*Sqrt[1 - 2*x]])/(9261*Sqrt[21])}
{(3 + 5*x)^3/(Sqrt[1 - 2*x]*(2 + 3*x)^5), x, 5, (-3275*Sqrt[1 - 2*x])/(12348*(2 + 3*x)) - (Sqrt[1 - 2*x]*(3 + 5*x)^2)/(18*(2 + 3*x)^3) - (Sqrt[1 - 2*x]*(3 + 5*x)^3)/(28*(2 + 3*x)^4) + (5*Sqrt[1 - 2*x]*(79 + 29*x))/(10584*(2 + 3*x)^2) - (42995*ArcTanh[Sqrt[3/7]*Sqrt[1 - 2*x]])/(37044*Sqrt[21])}
{(3 + 5*x)^3/(Sqrt[1 - 2*x]*(2 + 3*x)^6), x, 6, (-61*Sqrt[1 - 2*x])/(882*(2 + 3*x)^2) - (5293*Sqrt[1 - 2*x])/(43218*(2 + 3*x)) - (8*Sqrt[1 - 2*x]*(3 + 5*x)^2)/(245*(2 + 3*x)^4) - (Sqrt[1 - 2*x]*(3 + 5*x)^3)/(35*(2 + 3*x)^5) + (Sqrt[1 - 2*x]*(353 + 295*x))/(15435*(2 + 3*x)^3) - (5293*ArcTanh[Sqrt[3/7]*Sqrt[1 - 2*x]])/(21609*Sqrt[21])}


(* ::Subsubsection::Closed:: *)
(*n<0*)


{(a + b*x)^2/((c + d*x)^2*Sqrt[e + f*x]), x, 3, (2*b^2*Sqrt[e + f*x])/(d^2*f) - ((b*c - a*d)^2*Sqrt[e + f*x])/(d^2*(d*e - c*f)*(c + d*x)) + ((b*c - a*d)*(4*b*d*e - 3*b*c*f - a*d*f)*ArcTanh[(Sqrt[d]*Sqrt[e + f*x])/Sqrt[d*e - c*f]])/(d^(5/2)*(d*e - c*f)^(3/2))}


{(2 + 3*x)^5/(Sqrt[1 - 2*x]*(3 + 5*x)), x, 6, -((125702*Sqrt[1 - 2*x])/3125) - (748/625)*Sqrt[1 - 2*x]*(2 + 3*x)^2 - (149/525)*Sqrt[1 - 2*x]*(2 + 3*x)^3 - (1/15)*Sqrt[1 - 2*x]*(2 + 3*x)^4 - (Sqrt[1 - 2*x]*(31426 + 52375*x))/3125 - (2*ArcTanh[Sqrt[5/11]*Sqrt[1 - 2*x]])/(3125*Sqrt[55])}
{(2 + 3*x)^4/(Sqrt[1 - 2*x]*(3 + 5*x)), x, 5, (-(7878/625))*Sqrt[1 - 2*x] - (9/5)*Sqrt[1 - 2*x]*(2 + 3*x) - (48/125)*Sqrt[1 - 2*x]*(2 + 3*x)^2 - (3/35)*Sqrt[1 - 2*x]*(2 + 3*x)^3 - (2*ArcTanh[Sqrt[5/11]*Sqrt[1 - 2*x]])/(625*Sqrt[55])}
{(2 + 3*x)^3/(Sqrt[1 - 2*x]*(3 + 5*x)), x, 4, (-(542/125))*Sqrt[1 - 2*x] - (3/25)*Sqrt[1 - 2*x]*(2 + 3*x)^2 - (1/125)*Sqrt[1 - 2*x]*(136 + 225*x) - (2*ArcTanh[Sqrt[5/11]*Sqrt[1 - 2*x]])/(125*Sqrt[55])}
{(2 + 3*x)^2/(Sqrt[1 - 2*x]*(3 + 5*x)), x, 3, (-(38/25))*Sqrt[1 - 2*x] - (1/5)*Sqrt[1 - 2*x]*(2 + 3*x) - (2*ArcTanh[Sqrt[5/11]*Sqrt[1 - 2*x]])/(25*Sqrt[55])}
{(2 + 3*x)/(Sqrt[1 - 2*x]*(3 + 5*x)), x, 2, (-3*Sqrt[1 - 2*x])/5 - (2*ArcTanh[Sqrt[5/11]*Sqrt[1 - 2*x]])/(5*Sqrt[55])}
{1/(Sqrt[1 - 2*x]*(3 + 5*x)), x, 1, (-2*ArcTanh[Sqrt[5/11]*Sqrt[1 - 2*x]])/Sqrt[55]}
{1/(Sqrt[1 - 2*x]*(2 + 3*x)*(3 + 5*x)), x, 3, 2*Sqrt[3/7]*ArcTanh[Sqrt[3/7]*Sqrt[1 - 2*x]] - 2*Sqrt[5/11]*ArcTanh[Sqrt[5/11]*Sqrt[1 - 2*x]]}
{1/(Sqrt[1 - 2*x]*(2 + 3*x)^2*(3 + 5*x)), x, 4, (3*Sqrt[1 - 2*x])/(7*(2 + 3*x)) + (72*Sqrt[3/7]*ArcTanh[Sqrt[3/7]*Sqrt[1 - 2*x]])/7 - 10*Sqrt[5/11]*ArcTanh[Sqrt[5/11]*Sqrt[1 - 2*x]]}
{1/(Sqrt[1 - 2*x]*(2 + 3*x)^3*(3 + 5*x)), x, 5, (3*Sqrt[1 - 2*x])/(14*(2 + 3*x)^2) + (219*Sqrt[1 - 2*x])/(98*(2 + 3*x)) + (2523*Sqrt[3/7]*ArcTanh[Sqrt[3/7]*Sqrt[1 - 2*x]])/49 - 50*Sqrt[5/11]*ArcTanh[Sqrt[5/11]*Sqrt[1 - 2*x]]}
{1/(Sqrt[1 - 2*x]*(2 + 3*x)^4*(3 + 5*x)), x, 6, Sqrt[1 - 2*x]/(7*(2 + 3*x)^3) + (55*Sqrt[1 - 2*x])/(49*(2 + 3*x)^2) + (3840*Sqrt[1 - 2*x])/(343*(2 + 3*x)) + (88310*Sqrt[3/7]*ArcTanh[Sqrt[3/7]*Sqrt[1 - 2*x]])/343 - 250*Sqrt[5/11]*ArcTanh[Sqrt[5/11]*Sqrt[1 - 2*x]]}
{1/(Sqrt[1 - 2*x]*(2 + 3*x)^5*(3 + 5*x)), x, 7, (3*Sqrt[1 - 2*x])/(28*(2 + 3*x)^4) + (3*Sqrt[1 - 2*x])/(4*(2 + 3*x)^3) + (45*Sqrt[1 - 2*x])/(8*(2 + 3*x)^2) + (3135*Sqrt[1 - 2*x])/(56*(2 + 3*x)) + (36045*Sqrt[3/7]*ArcTanh[Sqrt[3/7]*Sqrt[1 - 2*x]])/28 - 1250*Sqrt[5/11]*ArcTanh[Sqrt[5/11]*Sqrt[1 - 2*x]]}


{(2 + 3*x)^6/(Sqrt[1 - 2*x]*(3 + 5*x)^2), x, 7, (-4434698*Sqrt[1 - 2*x])/171875 - (26352*Sqrt[1 - 2*x]*(2 + 3*x)^2)/34375 - (1717*Sqrt[1 - 2*x]*(2 + 3*x)^3)/9625 + (8*Sqrt[1 - 2*x]*(2 + 3*x)^4)/(825*(3 + 5*x)) - (Sqrt[1 - 2*x]*(2 + 3*x)^5)/(15*(3 + 5*x)) - (Sqrt[1 - 2*x]*(1108774 + 1847625*x))/171875 - (398*ArcTanh[Sqrt[5/11]*Sqrt[1 - 2*x]])/(171875*Sqrt[55])}
{(2 + 3*x)^5/(Sqrt[1 - 2*x]*(3 + 5*x)^2), x, 6, (-278748*Sqrt[1 - 2*x])/34375 - (318*Sqrt[1 - 2*x]*(2 + 3*x))/275 - (1668*Sqrt[1 - 2*x]*(2 + 3*x)^2)/6875 + (26*Sqrt[1 - 2*x]*(2 + 3*x)^3)/(1925*(3 + 5*x)) - (3*Sqrt[1 - 2*x]*(2 + 3*x)^4)/(35*(3 + 5*x)) - (332*ArcTanh[Sqrt[5/11]*Sqrt[1 - 2*x]])/(34375*Sqrt[55])}
{(2 + 3*x)^4/(Sqrt[1 - 2*x]*(3 + 5*x)^2), x, 5, (-19166*Sqrt[1 - 2*x])/6875 + (28*Sqrt[1 - 2*x]*(2 + 3*x)^2)/(1375*(3 + 5*x)) - (3*Sqrt[1 - 2*x]*(2 + 3*x)^3)/(25*(3 + 5*x)) - (7*Sqrt[1 - 2*x]*(694 + 1125*x))/6875 - (266*ArcTanh[Sqrt[5/11]*Sqrt[1 - 2*x]])/(6875*Sqrt[55])}
{(2 + 3*x)^3/(Sqrt[1 - 2*x]*(3 + 5*x)^2), x, 4, (-54*Sqrt[1 - 2*x])/55 + (2*Sqrt[1 - 2*x]*(2 + 3*x))/(55*(3 + 5*x)) - (Sqrt[1 - 2*x]*(2 + 3*x)^2)/(5*(3 + 5*x)) - (8*ArcTanh[Sqrt[5/11]*Sqrt[1 - 2*x]])/(55*Sqrt[55])}
{(2 + 3*x)^2/(Sqrt[1 - 2*x]*(3 + 5*x)^2), x, 3, (-(9/25))*Sqrt[1 - 2*x] - Sqrt[1 - 2*x]/(275*(3 + 5*x)) - (134*ArcTanh[Sqrt[5/11]*Sqrt[1 - 2*x]])/(275*Sqrt[55])}
{(2 + 3*x)/(Sqrt[1 - 2*x]*(3 + 5*x)^2), x, 2, -Sqrt[1 - 2*x]/(55*(3 + 5*x)) - (68*ArcTanh[Sqrt[5/11]*Sqrt[1 - 2*x]])/(55*Sqrt[55])}
{1/(Sqrt[1 - 2*x]*(3 + 5*x)^2), x, 2, -Sqrt[1 - 2*x]/(11*(3 + 5*x)) - (2*ArcTanh[Sqrt[5/11]*Sqrt[1 - 2*x]])/(11*Sqrt[55])}
{1/(Sqrt[1 - 2*x]*(2 + 3*x)*(3 + 5*x)^2), x, 4, (-5*Sqrt[1 - 2*x])/(11*(3 + 5*x)) - 6*Sqrt[3/7]*ArcTanh[Sqrt[3/7]*Sqrt[1 - 2*x]] + (64*Sqrt[5/11]*ArcTanh[Sqrt[5/11]*Sqrt[1 - 2*x]])/11}
{1/(Sqrt[1 - 2*x]*(2 + 3*x)^2*(3 + 5*x)^2), x, 5, (-340*Sqrt[1 - 2*x])/(77*(3 + 5*x)) + (3*Sqrt[1 - 2*x])/(7*(2 + 3*x)*(3 + 5*x)) - (426*Sqrt[3/7]*ArcTanh[Sqrt[3/7]*Sqrt[1 - 2*x]])/7 + (650*Sqrt[5/11]*ArcTanh[Sqrt[5/11]*Sqrt[1 - 2*x]])/11}
{1/(Sqrt[1 - 2*x]*(2 + 3*x)^3*(3 + 5*x)^2), x, 6, (-35845*Sqrt[1 - 2*x])/(1078*(3 + 5*x)) + (3*Sqrt[1 - 2*x])/(14*(2 + 3*x)^2*(3 + 5*x)) + (162*Sqrt[1 - 2*x])/(49*(2 + 3*x)*(3 + 5*x)) - (22479*Sqrt[3/7]*ArcTanh[Sqrt[3/7]*Sqrt[1 - 2*x]])/49 + (4900*Sqrt[5/11]*ArcTanh[Sqrt[5/11]*Sqrt[1 - 2*x]])/11}
{1/(Sqrt[1 - 2*x]*(2 + 3*x)^4*(3 + 5*x)^2), x, 7, (-1676975*Sqrt[1 - 2*x])/(7546*(3 + 5*x)) + Sqrt[1 - 2*x]/(7*(2 + 3*x)^3*(3 + 5*x)) + (145*Sqrt[1 - 2*x])/(98*(2 + 3*x)^2*(3 + 5*x)) + (7585*Sqrt[1 - 2*x])/(343*(2 + 3*x)*(3 + 5*x)) - (1051695*Sqrt[3/7]*ArcTanh[Sqrt[3/7]*Sqrt[1 - 2*x]])/343 + (32750*Sqrt[5/11]*ArcTanh[Sqrt[5/11]*Sqrt[1 - 2*x]])/11}


{(2 + 3*x)^6/(Sqrt[1 - 2*x]*(3 + 5*x)^3), x, 7, (-9865791*Sqrt[1 - 2*x])/1890625 - (22437*Sqrt[1 - 2*x]*(2 + 3*x))/30250 - (56556*Sqrt[1 - 2*x]*(2 + 3*x)^2)/378125 + (59*Sqrt[1 - 2*x]*(2 + 3*x)^4)/(3850*(3 + 5*x)^2) - (3*Sqrt[1 - 2*x]*(2 + 3*x)^5)/(35*(3 + 5*x)^2) + (309*Sqrt[1 - 2*x]*(2 + 3*x)^3)/(211750*(3 + 5*x)) - (33069*ArcTanh[Sqrt[5/11]*Sqrt[1 - 2*x]])/(1890625*Sqrt[55])}
{(2 + 3*x)^5/(Sqrt[1 - 2*x]*(3 + 5*x)^3), x, 6, (-674163*Sqrt[1 - 2*x])/378125 + (61*Sqrt[1 - 2*x]*(2 + 3*x)^3)/(2750*(3 + 5*x)^2) - (3*Sqrt[1 - 2*x]*(2 + 3*x)^4)/(25*(3 + 5*x)^2) + (504*Sqrt[1 - 2*x]*(2 + 3*x)^2)/(75625*(3 + 5*x)) - (189*Sqrt[1 - 2*x]*(1842 + 2875*x))/756250 - (22113*ArcTanh[Sqrt[5/11]*Sqrt[1 - 2*x]])/(378125*Sqrt[55])}
{(2 + 3*x)^4/(Sqrt[1 - 2*x]*(3 + 5*x)^3), x, 5, (-9513*Sqrt[1 - 2*x])/15125 + (21*Sqrt[1 - 2*x]*(2 + 3*x)^2)/(550*(3 + 5*x)^2) - (Sqrt[1 - 2*x]*(2 + 3*x)^3)/(5*(3 + 5*x)^2) + (21*Sqrt[1 - 2*x]*(2 + 3*x))/(1210*(3 + 5*x)) - (2667*ArcTanh[Sqrt[5/11]*Sqrt[1 - 2*x]])/(15125*Sqrt[55])}
{(2 + 3*x)^3/(Sqrt[1 - 2*x]*(3 + 5*x)^3), x, 4, (13*Sqrt[1 - 2*x]*(2 + 3*x))/(110*(3 + 5*x)^2) - (3*Sqrt[1 - 2*x]*(2 + 3*x)^2)/(5*(3 + 5*x)^2) + (201*Sqrt[1 - 2*x])/(3025*(3 + 5*x)) - (1347*ArcTanh[Sqrt[5/11]*Sqrt[1 - 2*x]])/(3025*Sqrt[55])}
{(2 + 3*x)^2/(Sqrt[1 - 2*x]*(3 + 5*x)^3), x, 3, -(Sqrt[1 - 2*x]/(550*(3 + 5*x)^2)) - (27*Sqrt[1 - 2*x])/(1210*(3 + 5*x)) - (2313*ArcTanh[Sqrt[5/11]*Sqrt[1 - 2*x]])/(3025*Sqrt[55])}
{(2 + 3*x)/(Sqrt[1 - 2*x]*(3 + 5*x)^3), x, 3, -Sqrt[1 - 2*x]/(110*(3 + 5*x)^2) - (69*Sqrt[1 - 2*x])/(1210*(3 + 5*x)) - (69*ArcTanh[Sqrt[5/11]*Sqrt[1 - 2*x]])/(605*Sqrt[55])}
{1/(Sqrt[1 - 2*x]*(3 + 5*x)^3), x, 3, -Sqrt[1 - 2*x]/(22*(3 + 5*x)^2) - (3*Sqrt[1 - 2*x])/(242*(3 + 5*x)) - (3*ArcTanh[Sqrt[5/11]*Sqrt[1 - 2*x]])/(121*Sqrt[55])}
{1/(Sqrt[1 - 2*x]*(2 + 3*x)*(3 + 5*x)^3), x, 5, (-5*Sqrt[1 - 2*x])/(22*(3 + 5*x)^2) + (315*Sqrt[1 - 2*x])/(242*(3 + 5*x)) + 18*Sqrt[3/7]*ArcTanh[Sqrt[3/7]*Sqrt[1 - 2*x]] - (2115*Sqrt[5/11]*ArcTanh[Sqrt[5/11]*Sqrt[1 - 2*x]])/121}
{1/(Sqrt[1 - 2*x]*(2 + 3*x)^2*(3 + 5*x)^3), x, 6, (-505*Sqrt[1 - 2*x])/(154*(3 + 5*x)^2) + (3*Sqrt[1 - 2*x])/(7*(2 + 3*x)*(3 + 5*x)^2) + (33465*Sqrt[1 - 2*x])/(1694*(3 + 5*x)) + (1908*Sqrt[3/7]*ArcTanh[Sqrt[3/7]*Sqrt[1 - 2*x]])/7 - (32025*Sqrt[5/11]*ArcTanh[Sqrt[5/11]*Sqrt[1 - 2*x]])/121}
{1/(Sqrt[1 - 2*x]*(2 + 3*x)^3*(3 + 5*x)^3), x, 7, (-35495*Sqrt[1 - 2*x])/(1078*(3 + 5*x)^2) + (3*Sqrt[1 - 2*x])/(14*(2 + 3*x)^2*(3 + 5*x)^2) + (429*Sqrt[1 - 2*x])/(98*(2 + 3*x)*(3 + 5*x)^2) + (1177080*Sqrt[1 - 2*x])/(5929*(3 + 5*x)) + (134217*Sqrt[3/7]*ArcTanh[Sqrt[3/7]*Sqrt[1 - 2*x]])/49 - (321825*Sqrt[5/11]*ArcTanh[Sqrt[5/11]*Sqrt[1 - 2*x]])/121}
{1/(Sqrt[1 - 2*x]*(2 + 3*x)^4*(3 + 5*x)^3), x, 8, (-2076675*Sqrt[1 - 2*x])/(7546*(3 + 5*x)^2) + Sqrt[1 - 2*x]/(7*(2 + 3*x)^3*(3 + 5*x)^2) + (90*Sqrt[1 - 2*x])/(49*(2 + 3*x)^2*(3 + 5*x)^2) + (12555*Sqrt[1 - 2*x])/(343*(2 + 3*x)*(3 + 5*x)^2) + (137735775*Sqrt[1 - 2*x])/(83006*(3 + 5*x)) + (7852680*Sqrt[3/7]*ArcTanh[Sqrt[3/7]*Sqrt[1 - 2*x]])/343 - (2689875*Sqrt[5/11]*ArcTanh[Sqrt[5/11]*Sqrt[1 - 2*x]])/121}


(* ::Subsection::Closed:: *)
(*Integrands of the form (a+b x)^m (c+d x)^n / (e+f x)^(3/2)*)


(* ::Subsubsection::Closed:: *)
(*n>0*)


{((2 + 3*x)^7*(3 + 5*x))/(1 - 2*x)^(3/2), x, 2, 9058973/(256*Sqrt[1 - 2*x]) + (15647317*Sqrt[1 - 2*x])/128 - (7882483*(1 - 2*x)^(3/2))/128 + (4084101*(1 - 2*x)^(5/2))/128 - (787185*(1 - 2*x)^(7/2))/64 + (422919*(1 - 2*x)^(9/2))/128 - (821583*(1 - 2*x)^(11/2))/1408 + (101331*(1 - 2*x)^(13/2))/1664 - (729*(1 - 2*x)^(15/2))/256}
{((2 + 3*x)^6*(3 + 5*x))/(1 - 2*x)^(3/2), x, 2, 1294139/(128*Sqrt[1 - 2*x]) + (3916031*Sqrt[1 - 2*x])/128 - (1692705*(1 - 2*x)^(3/2))/128 + (731619*(1 - 2*x)^(5/2))/128 - (225855*(1 - 2*x)^(7/2))/128 + (45549*(1 - 2*x)^(9/2))/128 - (59049*(1 - 2*x)^(11/2))/1408 + (3645*(1 - 2*x)^(13/2))/1664}
{((2 + 3*x)^5*(3 + 5*x))/(1 - 2*x)^(3/2), x, 2, 184877/(64*Sqrt[1 - 2*x]) + (60025*Sqrt[1 - 2*x])/8 - (173215*(1 - 2*x)^(3/2))/64 + (7497*(1 - 2*x)^(5/2))/8 - (13905*(1 - 2*x)^(7/2))/64 + (117*(1 - 2*x)^(9/2))/4 - (1215*(1 - 2*x)^(11/2))/704}
{((2 + 3*x)^4*(3 + 5*x))/(1 - 2*x)^(3/2), x, 2, 26411/(32*Sqrt[1 - 2*x]) + (57281*Sqrt[1 - 2*x])/32 - (8281*(1 - 2*x)^(3/2))/16 + (10773*(1 - 2*x)^(5/2))/80 - (4671*(1 - 2*x)^(7/2))/224 + (45*(1 - 2*x)^(9/2))/32}
{((2 + 3*x)^3*(3 + 5*x))/(1 - 2*x)^(3/2), x, 2, 3773/(16*Sqrt[1 - 2*x]) + (3283*Sqrt[1 - 2*x])/8 - (357*(1 - 2*x)^(3/2))/4 + (621*(1 - 2*x)^(5/2))/40 - (135*(1 - 2*x)^(7/2))/112}
{((2 + 3*x)^2*(3 + 5*x))/(1 - 2*x)^(3/2), x, 2, 539/(8*Sqrt[1 - 2*x]) + (707*Sqrt[1 - 2*x])/8 - (103*(1 - 2*x)^(3/2))/8 + (9*(1 - 2*x)^(5/2))/8}
{((2 + 3*x)*(3 + 5*x))/(1 - 2*x)^(3/2), x, 2, 77/(4*Sqrt[1 - 2*x]) + 17*Sqrt[1 - 2*x] - (5*(1 - 2*x)^(3/2))/4}
{(3 + 5*x)/(1 - 2*x)^(3/2), x, 2, 11/(2*Sqrt[1 - 2*x]) + (5*Sqrt[1 - 2*x])/2}
{(3 + 5*x)/((1 - 2*x)^(3/2)*(2 + 3*x)), x, 2, 11/(7*Sqrt[1 - 2*x]) + (2*ArcTanh[Sqrt[3/7]*Sqrt[1 - 2*x]])/(7*Sqrt[21])}
{(3 + 5*x)/((1 - 2*x)^(3/2)*(2 + 3*x)^2), x, 3, 64/(147*Sqrt[1 - 2*x]) + 1/(21*Sqrt[1 - 2*x]*(2 + 3*x)) - (64*ArcTanh[Sqrt[3/7]*Sqrt[1 - 2*x]])/(49*Sqrt[21])}
{(3 + 5*x)/((1 - 2*x)^(3/2)*(2 + 3*x)^3), x, 4, 1/(42*Sqrt[1 - 2*x]*(2 + 3*x)^2) + 65/(147*Sqrt[1 - 2*x]*(2 + 3*x)) - (195*Sqrt[1 - 2*x])/(686*(2 + 3*x)) - (65*Sqrt[3/7]*ArcTanh[Sqrt[3/7]*Sqrt[1 - 2*x]])/343}
{(3 + 5*x)/((1 - 2*x)^(3/2)*(2 + 3*x)^4), x, 5, 1/(63*Sqrt[1 - 2*x]*(2 + 3*x)^3) + 4/(9*Sqrt[1 - 2*x]*(2 + 3*x)^2) - (5*Sqrt[1 - 2*x])/(21*(2 + 3*x)^2) - (5*Sqrt[1 - 2*x])/(49*(2 + 3*x)) - (10*ArcTanh[Sqrt[3/7]*Sqrt[1 - 2*x]])/(49*Sqrt[21])}
{(3 + 5*x)/((1 - 2*x)^(3/2)*(2 + 3*x)^5), x, 6, 1/(84*Sqrt[1 - 2*x]*(2 + 3*x)^4) + 131/(294*Sqrt[1 - 2*x]*(2 + 3*x)^3) - (131*Sqrt[1 - 2*x])/(588*(2 + 3*x)^3) - (655*Sqrt[1 - 2*x])/(8232*(2 + 3*x)^2) - (655*Sqrt[1 - 2*x])/(19208*(2 + 3*x)) - (655*ArcTanh[Sqrt[3/7]*Sqrt[1 - 2*x]])/(9604*Sqrt[21])}
{(3 + 5*x)/((1 - 2*x)^(3/2)*(2 + 3*x)^6), x, 7, 1/(105*Sqrt[1 - 2*x]*(2 + 3*x)^5) + 328/(735*Sqrt[1 - 2*x]*(2 + 3*x)^4) - (369*Sqrt[1 - 2*x])/(1715*(2 + 3*x)^4) - (123*Sqrt[1 - 2*x])/(1715*(2 + 3*x)^3) - (123*Sqrt[1 - 2*x])/(4802*(2 + 3*x)^2) - (369*Sqrt[1 - 2*x])/(33614*(2 + 3*x)) - (123*Sqrt[3/7]*ArcTanh[Sqrt[3/7]*Sqrt[1 - 2*x]])/16807}


{((2 + 3*x)^5*(3 + 5*x)^2)/(1 - 2*x)^(3/2), x, 2, 2033647/(128*Sqrt[1 - 2*x]) + (6206585/128)*Sqrt[1 - 2*x] - (8117095/384)*(1 - 2*x)^(3/2) + (1179381/128)*(1 - 2*x)^(5/2) - (367155/128)*(1 - 2*x)^(7/2) + (74667/128)*(1 - 2*x)^(9/2) - (97605*(1 - 2*x)^(11/2))/1408 + (6075*(1 - 2*x)^(13/2))/1664}
{((2 + 3*x)^4*(3 + 5*x)^2)/(1 - 2*x)^(3/2), x, 2, 290521/(64*Sqrt[1 - 2*x]) + (381073/32)*Sqrt[1 - 2*x] - (832951/192)*(1 - 2*x)^(3/2) + (121359/80)*(1 - 2*x)^(5/2) - (159111/448)*(1 - 2*x)^(7/2) + (1545/32)*(1 - 2*x)^(9/2) - (2025/704)*(1 - 2*x)^(11/2)}
{((2 + 3*x)^3*(3 + 5*x)^2)/(1 - 2*x)^(3/2), x, 2, 41503/(32*Sqrt[1 - 2*x]) + (91091/32)*Sqrt[1 - 2*x] - (39977/48)*(1 - 2*x)^(3/2) + (17541/80)*(1 - 2*x)^(5/2) - (7695/224)*(1 - 2*x)^(7/2) + (75/32)*(1 - 2*x)^(9/2)}
{((2 + 3*x)^2*(3 + 5*x)^2)/(1 - 2*x)^(3/2), x, 2, 5929/(16*Sqrt[1 - 2*x]) + (1309/2)*Sqrt[1 - 2*x] - (3467/24)*(1 - 2*x)^(3/2) + (51/2)*(1 - 2*x)^(5/2) - (225/112)*(1 - 2*x)^(7/2)}
{((2 + 3*x)*(3 + 5*x)^2)/(1 - 2*x)^(3/2), x, 2, 847/(8*Sqrt[1 - 2*x]) + (1133*Sqrt[1 - 2*x])/8 - (505*(1 - 2*x)^(3/2))/24 + (15*(1 - 2*x)^(5/2))/8}
{(3 + 5*x)^2/(1 - 2*x)^(3/2), x, 2, 121/(4*Sqrt[1 - 2*x]) + (55*Sqrt[1 - 2*x])/2 - (25*(1 - 2*x)^(3/2))/12}
{(3 + 5*x)^2/((1 - 2*x)^(3/2)*(2 + 3*x)), x, 3, 121/(14*Sqrt[1 - 2*x]) + (25/6)*Sqrt[1 - 2*x] - (2*ArcTanh[Sqrt[3/7]*Sqrt[1 - 2*x]])/(21*Sqrt[21])}
{(3 + 5*x)^2/((1 - 2*x)^(3/2)*(2 + 3*x)^2), x, 3, 121/(14*Sqrt[1 - 2*x]*(2 + 3*x)) - (1091*Sqrt[1 - 2*x])/(294*(2 + 3*x)) + (134*ArcTanh[Sqrt[3/7]*Sqrt[1 - 2*x]])/(147*Sqrt[21])}
{(3 + 5*x)^2/((1 - 2*x)^(3/2)*(2 + 3*x)^3), x, 4, 121/(14*Sqrt[1 - 2*x]*(2 + 3*x)^2) - (545*Sqrt[1 - 2*x])/(147*(2 + 3*x)^2) - (2045*Sqrt[1 - 2*x])/(2058*(2 + 3*x)) - (2045*ArcTanh[Sqrt[3/7]*Sqrt[1 - 2*x]])/(1029*Sqrt[21])}
{(3 + 5*x)^2/((1 - 2*x)^(3/2)*(2 + 3*x)^4), x, 5, 121/(14*Sqrt[1 - 2*x]*(2 + 3*x)^3) - (467*Sqrt[1 - 2*x])/(126*(2 + 3*x)^3) - (905*Sqrt[1 - 2*x])/(882*(2 + 3*x)^2) - (905*Sqrt[1 - 2*x])/(2058*(2 + 3*x)) - (905*ArcTanh[Sqrt[3/7]*Sqrt[1 - 2*x]])/(1029*Sqrt[21])}
{(3 + 5*x)^2/((1 - 2*x)^(3/2)*(2 + 3*x)^5), x, 6, 121/(14*Sqrt[1 - 2*x]*(2 + 3*x)^4) - (2179*Sqrt[1 - 2*x])/(588*(2 + 3*x)^4) - (1829*Sqrt[1 - 2*x])/(1764*(2 + 3*x)^3) - (9145*Sqrt[1 - 2*x])/(24696*(2 + 3*x)^2) - (9145*Sqrt[1 - 2*x])/(57624*(2 + 3*x)) - (9145*ArcTanh[Sqrt[3/7]*Sqrt[1 - 2*x]])/(28812*Sqrt[21])}


{((2 + 3*x)^4*(3 + 5*x)^3)/(1 - 2*x)^(3/2), x, 2, 3195731/(128*Sqrt[1 - 2*x]) + (9836211/128)*Sqrt[1 - 2*x] - (4324397/128)*(1 - 2*x)^(3/2) + (9504551/640)*(1 - 2*x)^(5/2) - (4177401/896)*(1 - 2*x)^(7/2) + (122385/128)*(1 - 2*x)^(9/2) - (161325*(1 - 2*x)^(11/2))/1408 + (10125*(1 - 2*x)^(13/2))/1664}
{((2 + 3*x)^3*(3 + 5*x)^3)/(1 - 2*x)^(3/2), x, 2, 456533/(64*Sqrt[1 - 2*x]) + (302379/16)*Sqrt[1 - 2*x] - (444983/64)*(1 - 2*x)^(3/2) + (98209/40)*(1 - 2*x)^(5/2) - (260055/448)*(1 - 2*x)^(7/2) + (1275/16)*(1 - 2*x)^(9/2) - (3375/704)*(1 - 2*x)^(11/2)}
{((2 + 3*x)^2*(3 + 5*x)^3)/(1 - 2*x)^(3/2), x, 2, 65219/(32*Sqrt[1 - 2*x]) + (144837/32)*Sqrt[1 - 2*x] - (21439/16)*(1 - 2*x)^(3/2) + (5711/16)*(1 - 2*x)^(5/2) - (12675/224)*(1 - 2*x)^(7/2) + (125/32)*(1 - 2*x)^(9/2)}
{((2 + 3*x)*(3 + 5*x)^3)/(1 - 2*x)^(3/2), x, 2, 9317/(16*Sqrt[1 - 2*x]) + (8349*Sqrt[1 - 2*x])/8 - (935*(1 - 2*x)^(3/2))/4 + (335*(1 - 2*x)^(5/2))/8 - (375*(1 - 2*x)^(7/2))/112}
{(3 + 5*x)^3/(1 - 2*x)^(3/2), x, 2, 1331/(8*Sqrt[1 - 2*x]) + (1815*Sqrt[1 - 2*x])/8 - (275*(1 - 2*x)^(3/2))/8 + (25*(1 - 2*x)^(5/2))/8}
{(3 + 5*x)^3/((1 - 2*x)^(3/2)*(2 + 3*x)), x, 4, (3680*Sqrt[1 - 2*x])/63 + (737*(3 + 5*x))/(63*Sqrt[1 - 2*x]) - (5*(3 + 5*x)^2)/(9*Sqrt[1 - 2*x]) + (2*ArcTanh[Sqrt[3/7]*Sqrt[1 - 2*x]])/(63*Sqrt[21])}
{(3 + 5*x)^3/((1 - 2*x)^(3/2)*(2 + 3*x)^2), x, 4, (386*Sqrt[1 - 2*x])/(147*(2 + 3*x)) + (374*(3 + 5*x))/(21*Sqrt[1 - 2*x]*(2 + 3*x)) - (5*(3 + 5*x)^2)/(3*Sqrt[1 - 2*x]*(2 + 3*x)) - (68*ArcTanh[Sqrt[3/7]*Sqrt[1 - 2*x]])/(147*Sqrt[21])}
{(3 + 5*x)^3/((1 - 2*x)^(3/2)*(2 + 3*x)^3), x, 5, (650*Sqrt[1 - 2*x])/343 + (5*Sqrt[1 - 2*x]*(3 + 5*x)^2)/(98*(2 + 3*x)^2) + (2*(3 + 5*x)^3)/(7*Sqrt[1 - 2*x]*(2 + 3*x)^2) - (5*Sqrt[1 - 2*x]*(61 + 65*x))/(2058*(2 + 3*x)) + (2245*ArcTanh[Sqrt[3/7]*Sqrt[1 - 2*x]])/(1029*Sqrt[21])}
{(3 + 5*x)^3/((1 - 2*x)^(3/2)*(2 + 3*x)^4), x, 5, (590*Sqrt[1 - 2*x])/(3087*(2 + 3*x)) + (40*Sqrt[1 - 2*x]*(3 + 5*x))/(441*(2 + 3*x)^2) + (Sqrt[1 - 2*x]*(3 + 5*x)^2)/(21*(2 + 3*x)^3) + (2*(3 + 5*x)^3)/(7*Sqrt[1 - 2*x]*(2 + 3*x)^3) - (9320*ArcTanh[Sqrt[3/7]*Sqrt[1 - 2*x]])/(3087*Sqrt[21])}
{(3 + 5*x)^3/((1 - 2*x)^(3/2)*(2 + 3*x)^5), x, 6, (375*Sqrt[1 - 2*x])/(2744*(2 + 3*x)^2) - (39185*Sqrt[1 - 2*x])/(57624*(2 + 3*x)) + (47*Sqrt[1 - 2*x]*(3 + 5*x))/(588*(2 + 3*x)^3) + (9*Sqrt[1 - 2*x]*(3 + 5*x)^2)/(196*(2 + 3*x)^4) + (2*(3 + 5*x)^3)/(7*Sqrt[1 - 2*x]*(2 + 3*x)^4) - (39185*ArcTanh[Sqrt[3/7]*Sqrt[1 - 2*x]])/(28812*Sqrt[21])}


(* ::Subsubsection::Closed:: *)
(*n<0*)


{(2 + 3*x)^6/((1 - 2*x)^(3/2)*(3 + 5*x)), x, 7, (19886122*Sqrt[1 - 2*x])/34375 + (22727*Sqrt[1 - 2*x]*(2 + 3*x))/275 + (121752*Sqrt[1 - 2*x]*(2 + 3*x)^2)/6875 + (8117*Sqrt[1 - 2*x]*(2 + 3*x)^3)/1925 + (406*(2 + 3*x)^4)/(165*Sqrt[1 - 2*x]) - (2 + 3*x)^5/(15*Sqrt[1 - 2*x]) - (2*ArcTanh[Sqrt[5/11]*Sqrt[1 - 2*x]])/(34375*Sqrt[55])}
{(2 + 3*x)^5/((1 - 2*x)^(3/2)*(3 + 5*x)), x, 6, (1050298*Sqrt[1 - 2*x])/6875 + (6252*Sqrt[1 - 2*x]*(2 + 3*x)^2)/1375 + (139*(2 + 3*x)^3)/(55*Sqrt[1 - 2*x]) - (3*(2 + 3*x)^4)/(35*Sqrt[1 - 2*x]) + (Sqrt[1 - 2*x]*(262574 + 437625*x))/6875 - (2*ArcTanh[Sqrt[5/11]*Sqrt[1 - 2*x]])/(6875*Sqrt[55])}
{(2 + 3*x)^4/((1 - 2*x)^(3/2)*(3 + 5*x)), x, 5, (50922*Sqrt[1 - 2*x])/1375 + (291*Sqrt[1 - 2*x]*(2 + 3*x))/55 + (728*(2 + 3*x)^2)/(275*Sqrt[1 - 2*x]) - (3*(2 + 3*x)^3)/(25*Sqrt[1 - 2*x]) - (2*ArcTanh[Sqrt[5/11]*Sqrt[1 - 2*x]])/(1375*Sqrt[55])}
{(2 + 3*x)^3/((1 - 2*x)^(3/2)*(3 + 5*x)), x, 4, (2412*Sqrt[1 - 2*x])/275 + (161*(2 + 3*x))/(55*Sqrt[1 - 2*x]) - (2 + 3*x)^2/(5*Sqrt[1 - 2*x]) - (2*ArcTanh[Sqrt[5/11]*Sqrt[1 - 2*x]])/(275*Sqrt[55])}
{(2 + 3*x)^2/((1 - 2*x)^(3/2)*(3 + 5*x)), x, 3, 49/(22*Sqrt[1 - 2*x]) + (9/10)*Sqrt[1 - 2*x] - (2*ArcTanh[Sqrt[5/11]*Sqrt[1 - 2*x]])/(55*Sqrt[55])}
{(2 + 3*x)/((1 - 2*x)^(3/2)*(3 + 5*x)), x, 2, 7/(11*Sqrt[1 - 2*x]) - (2*ArcTanh[Sqrt[5/11]*Sqrt[1 - 2*x]])/(11*Sqrt[55])}
{1/((1 - 2*x)^(3/2)*(3 + 5*x)), x, 2, 2/(11*Sqrt[1 - 2*x]) - (2*Sqrt[5/11]*ArcTanh[Sqrt[5/11]*Sqrt[1 - 2*x]])/11}
{1/((1 - 2*x)^(3/2)*(2 + 3*x)*(3 + 5*x)), x, 4, 4/(77*Sqrt[1 - 2*x]) + (6*Sqrt[3/7]*ArcTanh[Sqrt[3/7]*Sqrt[1 - 2*x]])/7 - (10*Sqrt[5/11]*ArcTanh[Sqrt[5/11]*Sqrt[1 - 2*x]])/11}
{1/((1 - 2*x)^(3/2)*(2 + 3*x)^2*(3 + 5*x)), x, 5, 4/(77*Sqrt[1 - 2*x]*(2 + 3*x)) + (87*Sqrt[1 - 2*x])/(539*(2 + 3*x)) + (228*Sqrt[3/7]*ArcTanh[Sqrt[3/7]*Sqrt[1 - 2*x]])/49 - (50*Sqrt[5/11]*ArcTanh[Sqrt[5/11]*Sqrt[1 - 2*x]])/11}
{1/((1 - 2*x)^(3/2)*(2 + 3*x)^3*(3 + 5*x)), x, 6, 4/(77*Sqrt[1 - 2*x]*(2 + 3*x)^2) + (75*Sqrt[1 - 2*x])/(1078*(2 + 3*x)^2) + (7575*Sqrt[1 - 2*x])/(7546*(2 + 3*x)) + (8025*Sqrt[3/7]*ArcTanh[Sqrt[3/7]*Sqrt[1 - 2*x]])/343 - (250*Sqrt[5/11]*ArcTanh[Sqrt[5/11]*Sqrt[1 - 2*x]])/11}
{1/((1 - 2*x)^(3/2)*(2 + 3*x)^4*(3 + 5*x)), x, 7, 4/(77*Sqrt[1 - 2*x]*(2 + 3*x)^3) + (3*Sqrt[1 - 2*x])/(77*(2 + 3*x)^3) + (270*Sqrt[1 - 2*x])/(539*(2 + 3*x)^2) + (19185*Sqrt[1 - 2*x])/(3773*(2 + 3*x)) + (40140*Sqrt[3/7]*ArcTanh[Sqrt[3/7]*Sqrt[1 - 2*x]])/343 - (1250*Sqrt[5/11]*ArcTanh[Sqrt[5/11]*Sqrt[1 - 2*x]])/11}


{(2 + 3*x)^6/((1 - 2*x)^(3/2)*(3 + 5*x)^2), x, 7, (36473898*Sqrt[1 - 2*x])/378125 + (217152*Sqrt[1 - 2*x]*(2 + 3*x)^2)/75625 - (4839*Sqrt[1 - 2*x]*(2 + 3*x)^3)/(21175*(3 + 5*x)) + (139*(2 + 3*x)^4)/(55*Sqrt[1 - 2*x]*(3 + 5*x)) - (3*(2 + 3*x)^5)/(35*Sqrt[1 - 2*x]*(3 + 5*x)) + (3*Sqrt[1 - 2*x]*(3039458 + 5065875*x))/378125 - (402*ArcTanh[Sqrt[5/11]*Sqrt[1 - 2*x]])/(378125*Sqrt[55])}
{(2 + 3*x)^5/((1 - 2*x)^(3/2)*(3 + 5*x)^2), x, 6, (1763496*Sqrt[1 - 2*x])/75625 + (2016*Sqrt[1 - 2*x]*(2 + 3*x))/605 - (3612*Sqrt[1 - 2*x]*(2 + 3*x)^2)/(15125*(3 + 5*x)) + (728*(2 + 3*x)^3)/(275*Sqrt[1 - 2*x]*(3 + 5*x)) - (3*(2 + 3*x)^4)/(25*Sqrt[1 - 2*x]*(3 + 5*x)) - (336*ArcTanh[Sqrt[5/11]*Sqrt[1 - 2*x]])/(75625*Sqrt[55])}
{(2 + 3*x)^4/((1 - 2*x)^(3/2)*(3 + 5*x)^2), x, 5, (15648*Sqrt[1 - 2*x])/3025 + (161*(2 + 3*x)^2)/(55*Sqrt[1 - 2*x]*(3 + 5*x)) - (2 + 3*x)^3/(5*Sqrt[1 - 2*x]*(3 + 5*x)) + (3*Sqrt[1 - 2*x]*(436 + 815*x))/(3025*(3 + 5*x)) - (54*ArcTanh[Sqrt[5/11]*Sqrt[1 - 2*x]])/(3025*Sqrt[55])}
{(2 + 3*x)^3/((1 - 2*x)^(3/2)*(3 + 5*x)^2), x, 4, (-1158*Sqrt[1 - 2*x])/(3025*(3 + 5*x)) + (238*(2 + 3*x))/(55*Sqrt[1 - 2*x]*(3 + 5*x)) - (3*(2 + 3*x)^2)/(5*Sqrt[1 - 2*x]*(3 + 5*x)) - (204*ArcTanh[Sqrt[5/11]*Sqrt[1 - 2*x]])/(3025*Sqrt[55])}
{(2 + 3*x)^2/((1 - 2*x)^(3/2)*(3 + 5*x)^2), x, 3, 49/(22*Sqrt[1 - 2*x]*(3 + 5*x)) - (1227*Sqrt[1 - 2*x])/(1210*(3 + 5*x)) - (138*ArcTanh[Sqrt[5/11]*Sqrt[1 - 2*x]])/(605*Sqrt[55])}
{(2 + 3*x)/((1 - 2*x)^(3/2)*(3 + 5*x)^2), x, 3, 72/(605*Sqrt[1 - 2*x]) - 1/(55*Sqrt[1 - 2*x]*(3 + 5*x)) - (72*ArcTanh[Sqrt[5/11]*Sqrt[1 - 2*x]])/(121*Sqrt[55])}
{1/((1 - 2*x)^(3/2)*(3 + 5*x)^2), x, 3, 2/(11*Sqrt[1 - 2*x]*(3 + 5*x)) - (15*Sqrt[1 - 2*x])/(121*(3 + 5*x)) - (6*Sqrt[5/11]*ArcTanh[Sqrt[5/11]*Sqrt[1 - 2*x]])/121}
{1/((1 - 2*x)^(3/2)*(2 + 3*x)*(3 + 5*x)^2), x, 5, 4/(77*Sqrt[1 - 2*x]*(3 + 5*x)) - (195*Sqrt[1 - 2*x])/(847*(3 + 5*x)) - (18*Sqrt[3/7]*ArcTanh[Sqrt[3/7]*Sqrt[1 - 2*x]])/7 + (300*Sqrt[5/11]*ArcTanh[Sqrt[5/11]*Sqrt[1 - 2*x]])/121}
{1/((1 - 2*x)^(3/2)*(2 + 3*x)^2*(3 + 5*x)^2), x, 6, (-11610*Sqrt[1 - 2*x])/(5929*(3 + 5*x)) + 4/(77*Sqrt[1 - 2*x]*(2 + 3*x)*(3 + 5*x)) + (87*Sqrt[1 - 2*x])/(539*(2 + 3*x)*(3 + 5*x)) - (1314*Sqrt[3/7]*ArcTanh[Sqrt[3/7]*Sqrt[1 - 2*x]])/49 + (3150*Sqrt[5/11]*ArcTanh[Sqrt[5/11]*Sqrt[1 - 2*x]])/121}
{1/((1 - 2*x)^(3/2)*(2 + 3*x)^3*(3 + 5*x)^2), x, 7, (-1229325*Sqrt[1 - 2*x])/(83006*(3 + 5*x)) + 4/(77*Sqrt[1 - 2*x]*(2 + 3*x)^2*(3 + 5*x)) + (75*Sqrt[1 - 2*x])/(1078*(2 + 3*x)^2*(3 + 5*x)) + (5520*Sqrt[1 - 2*x])/(3773*(2 + 3*x)*(3 + 5*x)) - (70065*Sqrt[3/7]*ArcTanh[Sqrt[3/7]*Sqrt[1 - 2*x]])/343 + (24000*Sqrt[5/11]*ArcTanh[Sqrt[5/11]*Sqrt[1 - 2*x]])/121}


{(2 + 3*x)^6/((1 - 2*x)^(3/2)*(3 + 5*x)^3), x, 7, (61055253*Sqrt[1 - 2*x])/4159375 + (139671*Sqrt[1 - 2*x]*(2 + 3*x))/66550 - (7219*Sqrt[1 - 2*x]*(2 + 3*x)^3)/(30250*(3 + 5*x)^2) + (728*(2 + 3*x)^4)/(275*Sqrt[1 - 2*x]*(3 + 5*x)^2) - (3*(2 + 3*x)^5)/(25*Sqrt[1 - 2*x]*(3 + 5*x)^2) - (125916*Sqrt[1 - 2*x]*(2 + 3*x)^2)/(831875*(3 + 5*x)) - (33873*ArcTanh[Sqrt[5/11]*Sqrt[1 - 2*x]])/(4159375*Sqrt[55])}
{(2 + 3*x)^5/((1 - 2*x)^(3/2)*(3 + 5*x)^3), x, 6, (538608*Sqrt[1 - 2*x])/166375 - (1589*Sqrt[1 - 2*x]*(2 + 3*x)^2)/(6050*(3 + 5*x)^2) + (161*(2 + 3*x)^3)/(55*Sqrt[1 - 2*x]*(3 + 5*x)^2) - (2 + 3*x)^4/(5*Sqrt[1 - 2*x]*(3 + 5*x)^2) + (147*Sqrt[1 - 2*x]*(612 + 1145*x))/(332750*(3 + 5*x)) - (4557*ArcTanh[Sqrt[5/11]*Sqrt[1 - 2*x]])/(166375*Sqrt[55])}
{(2 + 3*x)^4/((1 - 2*x)^(3/2)*(3 + 5*x)^3), x, 5, -((346 - 195*x)*Sqrt[1 - 2*x])/(6050*(3 + 5*x)^2) + (238*(2 + 3*x)^2)/(55*Sqrt[1 - 2*x]*(3 + 5*x)^2) - (3*(2 + 3*x)^3)/(5*Sqrt[1 - 2*x]*(3 + 5*x)^2) - (15759*Sqrt[1 - 2*x])/(33275*(3 + 5*x)) - (111*ArcTanh[Sqrt[5/11]*Sqrt[1 - 2*x]])/(1331*Sqrt[55])}
{(2 + 3*x)^3/((1 - 2*x)^(3/2)*(3 + 5*x)^3), x, 5, (3408*Sqrt[1 - 2*x])/33275 - (5*Sqrt[1 - 2*x]*(2 + 3*x)^2)/(242*(3 + 5*x)^2) + (2*(2 + 3*x)^3)/(11*Sqrt[1 - 2*x]*(3 + 5*x)^2) + (3*Sqrt[1 - 2*x]*(24 + 71*x))/(13310*(3 + 5*x)) - (7143*ArcTanh[Sqrt[5/11]*Sqrt[1 - 2*x]])/(33275*Sqrt[55])}
{(2 + 3*x)^2/((1 - 2*x)^(3/2)*(3 + 5*x)^3), x, 4, 49/(22*Sqrt[1 - 2*x]*(3 + 5*x)^2) - (613*Sqrt[1 - 2*x])/(605*(3 + 5*x)^2) - (2589*Sqrt[1 - 2*x])/(13310*(3 + 5*x)) - (2589*ArcTanh[Sqrt[5/11]*Sqrt[1 - 2*x]])/(6655*Sqrt[55])}
{(2 + 3*x)/((1 - 2*x)^(3/2)*(3 + 5*x)^3), x, 4, -1/(110*Sqrt[1 - 2*x]*(3 + 5*x)^2) + 71/(605*Sqrt[1 - 2*x]*(3 + 5*x)) - (213*Sqrt[1 - 2*x])/(2662*(3 + 5*x)) - (213*ArcTanh[Sqrt[5/11]*Sqrt[1 - 2*x]])/(1331*Sqrt[55])}
{1/((1 - 2*x)^(3/2)*(3 + 5*x)^3), x, 4, 2/(11*Sqrt[1 - 2*x]*(3 + 5*x)^2) - (25*Sqrt[1 - 2*x])/(242*(3 + 5*x)^2) - (75*Sqrt[1 - 2*x])/(2662*(3 + 5*x)) - (15*Sqrt[5/11]*ArcTanh[Sqrt[5/11]*Sqrt[1 - 2*x]])/1331}
{1/((1 - 2*x)^(3/2)*(2 + 3*x)*(3 + 5*x)^3), x, 6, 4/(77*Sqrt[1 - 2*x]*(3 + 5*x)^2) - (215*Sqrt[1 - 2*x])/(1694*(3 + 5*x)^2) + (10245*Sqrt[1 - 2*x])/(18634*(3 + 5*x)) + (54*Sqrt[3/7]*ArcTanh[Sqrt[3/7]*Sqrt[1 - 2*x]])/7 - (9975*Sqrt[5/11]*ArcTanh[Sqrt[5/11]*Sqrt[1 - 2*x]])/1331}
{1/((1 - 2*x)^(3/2)*(2 + 3*x)^2*(3 + 5*x)^3), x, 7, (-17095*Sqrt[1 - 2*x])/(11858*(3 + 5*x)^2) + 4/(77*Sqrt[1 - 2*x]*(2 + 3*x)*(3 + 5*x)^2) + (87*Sqrt[1 - 2*x])/(539*(2 + 3*x)*(3 + 5*x)^2) + (1124835*Sqrt[1 - 2*x])/(130438*(3 + 5*x)) + (5832*Sqrt[3/7]*ArcTanh[Sqrt[3/7]*Sqrt[1 - 2*x]])/49 - (153825*Sqrt[5/11]*ArcTanh[Sqrt[5/11]*Sqrt[1 - 2*x]])/1331}
{1/((1 - 2*x)^(3/2)*(2 + 3*x)^3*(3 + 5*x)^3), x, 8, (-1205525*Sqrt[1 - 2*x])/(83006*(3 + 5*x)^2) + 4/(77*Sqrt[1 - 2*x]*(2 + 3*x)^2*(3 + 5*x)^2) + (75*Sqrt[1 - 2*x])/(1078*(2 + 3*x)^2*(3 + 5*x)^2) + (14505*Sqrt[1 - 2*x])/(7546*(2 + 3*x)*(3 + 5*x)^2) + (39968475*Sqrt[1 - 2*x])/(456533*(3 + 5*x)) + (414315*Sqrt[3/7]*ArcTanh[Sqrt[3/7]*Sqrt[1 - 2*x]])/343 - (1561125*Sqrt[5/11]*ArcTanh[Sqrt[5/11]*Sqrt[1 - 2*x]])/1331}


(* ::Subsection::Closed:: *)
(*Integrands of the form (a+b x)^m (c+d x)^n / (e+f x)^(5/2)*)


(* ::Subsubsection::Closed:: *)
(*n>0*)


{((2 + 3*x)^5*(3 + 5*x))/(1 - 2*x)^(5/2), x, 2, 184877/(192*(1 - 2*x)^(3/2)) - 60025/(8*Sqrt[1 - 2*x]) - (519645*Sqrt[1 - 2*x])/64 + (12495*(1 - 2*x)^(3/2))/8 - (19467*(1 - 2*x)^(5/2))/64 + (1053*(1 - 2*x)^(7/2))/28 - (135*(1 - 2*x)^(9/2))/64}
{((2 + 3*x)^4*(3 + 5*x))/(1 - 2*x)^(5/2), x, 2, 26411/(96*(1 - 2*x)^(3/2)) - 57281/(32*Sqrt[1 - 2*x]) - (24843*Sqrt[1 - 2*x])/16 + (3591*(1 - 2*x)^(3/2))/16 - (4671*(1 - 2*x)^(5/2))/160 + (405*(1 - 2*x)^(7/2))/224}
{((2 + 3*x)^3*(3 + 5*x))/(1 - 2*x)^(5/2), x, 2, 3773/(48*(1 - 2*x)^(3/2)) - 3283/(8*Sqrt[1 - 2*x]) - (1071*Sqrt[1 - 2*x])/4 + (207*(1 - 2*x)^(3/2))/8 - (27*(1 - 2*x)^(5/2))/16}
{((2 + 3*x)^2*(3 + 5*x))/(1 - 2*x)^(5/2), x, 2, 539/(24*(1 - 2*x)^(3/2)) - 707/(8*Sqrt[1 - 2*x]) - (309*Sqrt[1 - 2*x])/8 + (15*(1 - 2*x)^(3/2))/8}
{((2 + 3*x)*(3 + 5*x))/(1 - 2*x)^(5/2), x, 2, 77/(12*(1 - 2*x)^(3/2)) - 17/Sqrt[1 - 2*x] - (15*Sqrt[1 - 2*x])/4}
{(3 + 5*x)/(1 - 2*x)^(5/2), x, 2, 11/(6*(1 - 2*x)^(3/2)) - 5/(2*Sqrt[1 - 2*x])}
{(3 + 5*x)/((1 - 2*x)^(5/2)*(2 + 3*x)), x, 3, 11/(21*(1 - 2*x)^(3/2)) - 2/(49*Sqrt[1 - 2*x]) + (2*Sqrt[3/7]*ArcTanh[Sqrt[3/7]*Sqrt[1 - 2*x]])/49}
{(3 + 5*x)/((1 - 2*x)^(5/2)*(2 + 3*x)^2), x, 4, 20/(147*(1 - 2*x)^(3/2)) + 60/(343*Sqrt[1 - 2*x]) + 1/(21*(1 - 2*x)^(3/2)*(2 + 3*x)) - (60*Sqrt[3/7]*ArcTanh[Sqrt[3/7]*Sqrt[1 - 2*x]])/343}
{(3 + 5*x)/((1 - 2*x)^(5/2)*(2 + 3*x)^3), x, 5, 5/(49*(1 - 2*x)^(3/2)) + 45/(343*Sqrt[1 - 2*x]) + 1/(42*(1 - 2*x)^(3/2)*(2 + 3*x)^2) - 3/(14*(1 - 2*x)^(3/2)*(2 + 3*x)) - (45*Sqrt[3/7]*ArcTanh[Sqrt[3/7]*Sqrt[1 - 2*x]])/343}
{(3 + 5*x)/((1 - 2*x)^(5/2)*(2 + 3*x)^4), x, 6, 1/(63*(1 - 2*x)^(3/2)*(2 + 3*x)^3) + 64/(441*(1 - 2*x)^(3/2)*(2 + 3*x)^2) + 64/(147*Sqrt[1 - 2*x]*(2 + 3*x)^2) - (80*Sqrt[1 - 2*x])/(343*(2 + 3*x)^2) - (240*Sqrt[1 - 2*x])/(2401*(2 + 3*x)) - (160*Sqrt[3/7]*ArcTanh[Sqrt[3/7]*Sqrt[1 - 2*x]])/2401}
{(3 + 5*x)/((1 - 2*x)^(5/2)*(2 + 3*x)^5), x, 7, 1/(84*(1 - 2*x)^(3/2)*(2 + 3*x)^4) + 43/(294*(1 - 2*x)^(3/2)*(2 + 3*x)^3) + 387/(686*Sqrt[1 - 2*x]*(2 + 3*x)^3) - (387*Sqrt[1 - 2*x])/(1372*(2 + 3*x)^3) - (1935*Sqrt[1 - 2*x])/(19208*(2 + 3*x)^2) - (5805*Sqrt[1 - 2*x])/(134456*(2 + 3*x)) - (1935*Sqrt[3/7]*ArcTanh[Sqrt[3/7]*Sqrt[1 - 2*x]])/67228}


{((2 + 3*x)^5*(3 + 5*x)^2)/(1 - 2*x)^(5/2), x, 2, 2033647/(384*(1 - 2*x)^(3/2)) - 6206585/(128*Sqrt[1 - 2*x]) - (8117095/128)*Sqrt[1 - 2*x] + (1965635/128)*(1 - 2*x)^(3/2) - (514017/128)*(1 - 2*x)^(5/2) + (672003/896)*(1 - 2*x)^(7/2) - (10845/128)*(1 - 2*x)^(9/2) + (6075*(1 - 2*x)^(11/2))/1408}
{((2 + 3*x)^4*(3 + 5*x)^2)/(1 - 2*x)^(5/2), x, 2, 290521/(192*(1 - 2*x)^(3/2)) - 381073/(32*Sqrt[1 - 2*x]) - (832951/64)*Sqrt[1 - 2*x] + (40453/16)*(1 - 2*x)^(3/2) - (159111/320)*(1 - 2*x)^(5/2) + (13905/224)*(1 - 2*x)^(7/2) - (225/64)*(1 - 2*x)^(9/2)}
{((2 + 3*x)^3*(3 + 5*x)^2)/(1 - 2*x)^(5/2), x, 2, 41503/(96*(1 - 2*x)^(3/2)) - 91091/(32*Sqrt[1 - 2*x]) - (39977/16)*Sqrt[1 - 2*x] + (5847/16)*(1 - 2*x)^(3/2) - (1539/32)*(1 - 2*x)^(5/2) + (675/224)*(1 - 2*x)^(7/2)}
{((2 + 3*x)^2*(3 + 5*x)^2)/(1 - 2*x)^(5/2), x, 2, 5929/(48*(1 - 2*x)^(3/2)) - 1309/(2*Sqrt[1 - 2*x]) - (3467/8)*Sqrt[1 - 2*x] + (85/2)*(1 - 2*x)^(3/2) - (45/16)*(1 - 2*x)^(5/2)}
{((2 + 3*x)*(3 + 5*x)^2)/(1 - 2*x)^(5/2), x, 2, 847/(24*(1 - 2*x)^(3/2)) - 1133/(8*Sqrt[1 - 2*x]) - (505*Sqrt[1 - 2*x])/8 + (25*(1 - 2*x)^(3/2))/8}
{(3 + 5*x)^2/(1 - 2*x)^(5/2), x, 2, 121/(12*(1 - 2*x)^(3/2)) - 55/(2*Sqrt[1 - 2*x]) - (25*Sqrt[1 - 2*x])/4}
{(3 + 5*x)^2/((1 - 2*x)^(5/2)*(2 + 3*x)), x, 3, 121/(42*(1 - 2*x)^(3/2)) - 407/(98*Sqrt[1 - 2*x]) - (2*ArcTanh[Sqrt[3/7]*Sqrt[1 - 2*x]])/(49*Sqrt[21])}
{(3 + 5*x)^2/((1 - 2*x)^(5/2)*(2 + 3*x)^2), x, 4, -(130/(1029*Sqrt[1 - 2*x])) + 121/(42*(1 - 2*x)^(3/2)*(2 + 3*x)) - 365/(294*Sqrt[1 - 2*x]*(2 + 3*x)) + (130*ArcTanh[Sqrt[3/7]*Sqrt[1 - 2*x]])/(343*Sqrt[21])}
{(3 + 5*x)^2/((1 - 2*x)^(5/2)*(2 + 3*x)^3), x, 5, 121/(42*(1 - 2*x)^(3/2)*(2 + 3*x)^2) - 26/(21*Sqrt[1 - 2*x]*(2 + 3*x)^2) + 85/(147*Sqrt[1 - 2*x]*(2 + 3*x)) - (255*Sqrt[1 - 2*x])/(686*(2 + 3*x)) - (85/343)*Sqrt[3/7]*ArcTanh[Sqrt[3/7]*Sqrt[1 - 2*x]]}
{(3 + 5*x)^2/((1 - 2*x)^(5/2)*(2 + 3*x)^4), x, 6, 121/(42*(1 - 2*x)^(3/2)*(2 + 3*x)^3) - 1091/(882*Sqrt[1 - 2*x]*(2 + 3*x)^3) + 566/(441*Sqrt[1 - 2*x]*(2 + 3*x)^2) - (1415*Sqrt[1 - 2*x])/(2058*(2 + 3*x)^2) - (1415*Sqrt[1 - 2*x])/(4802*(2 + 3*x)) - (1415*ArcTanh[Sqrt[3/7]*Sqrt[1 - 2*x]])/(2401*Sqrt[21])}
{(3 + 5*x)^2/((1 - 2*x)^(5/2)*(2 + 3*x)^5), x, 7, 121/(42*(1 - 2*x)^(3/2)*(2 + 3*x)^4) - 727/(588*Sqrt[1 - 2*x]*(2 + 3*x)^4) + 4093/(2058*Sqrt[1 - 2*x]*(2 + 3*x)^3) - (4093*Sqrt[1 - 2*x])/(4116*(2 + 3*x)^3) - (20465*Sqrt[1 - 2*x])/(57624*(2 + 3*x)^2) - (20465*Sqrt[1 - 2*x])/(134456*(2 + 3*x)) - (20465*ArcTanh[Sqrt[3/7]*Sqrt[1 - 2*x]])/(67228*Sqrt[21])}


{((2 + 3*x)^5*(3 + 5*x)^3)/(1 - 2*x)^(5/2), x, 2, 22370117/(768*(1 - 2*x)^(3/2)) - 39220335/(128*Sqrt[1 - 2*x]) - (60160485/128)*Sqrt[1 - 2*x] + (52725715/384)*(1 - 2*x)^(3/2) - (2887773/64)*(1 - 2*x)^(5/2) + (10121229/896)*(1 - 2*x)^(7/2) - (246315/128)*(1 - 2*x)^(9/2) + (277425*(1 - 2*x)^(11/2))/1408 - (30375*(1 - 2*x)^(13/2))/3328}
{((2 + 3*x)^4*(3 + 5*x)^3)/(1 - 2*x)^(5/2), x, 2, 3195731/(384*(1 - 2*x)^(3/2)) - 9836211/(128*Sqrt[1 - 2*x]) - (12973191/128)*Sqrt[1 - 2*x] + (9504551/384)*(1 - 2*x)^(3/2) - (4177401/640)*(1 - 2*x)^(5/2) + (1101465/896)*(1 - 2*x)^(7/2) - (17925/128)*(1 - 2*x)^(9/2) + (10125*(1 - 2*x)^(11/2))/1408}
{((2 + 3*x)^3*(3 + 5*x)^3)/(1 - 2*x)^(5/2), x, 2, 456533/(192*(1 - 2*x)^(3/2)) - 302379/(16*Sqrt[1 - 2*x]) - (1334949/64)*Sqrt[1 - 2*x] + (98209/24)*(1 - 2*x)^(3/2) - (52011/64)*(1 - 2*x)^(5/2) + (11475/112)*(1 - 2*x)^(7/2) - (375/64)*(1 - 2*x)^(9/2)}
{((2 + 3*x)^2*(3 + 5*x)^3)/(1 - 2*x)^(5/2), x, 2, 65219/(96*(1 - 2*x)^(3/2)) - 144837/(32*Sqrt[1 - 2*x]) - (64317/16)*Sqrt[1 - 2*x] + (28555/48)*(1 - 2*x)^(3/2) - (2535/32)*(1 - 2*x)^(5/2) + (1125/224)*(1 - 2*x)^(7/2)}
{((2 + 3*x)*(3 + 5*x)^3)/(1 - 2*x)^(5/2), x, 2, 9317/(48*(1 - 2*x)^(3/2)) - 8349/(8*Sqrt[1 - 2*x]) - (2805*Sqrt[1 - 2*x])/4 + (1675*(1 - 2*x)^(3/2))/24 - (75*(1 - 2*x)^(5/2))/16}
{(3 + 5*x)^3/(1 - 2*x)^(5/2), x, 2, 1331/(24*(1 - 2*x)^(3/2)) - 1815/(8*Sqrt[1 - 2*x]) - (825*Sqrt[1 - 2*x])/8 + (125*(1 - 2*x)^(3/2))/24}
{(3 + 5*x)^3/((1 - 2*x)^(5/2)*(2 + 3*x)), x, 4, -2948/(49*Sqrt[1 - 2*x]) + (253*(3 + 5*x))/(21*(1 - 2*x)^(3/2)) - (5*(3 + 5*x)^2)/(3*(1 - 2*x)^(3/2)) + (2*ArcTanh[Sqrt[3/7]*Sqrt[1 - 2*x]])/(147*Sqrt[21])}
{(3 + 5*x)^3/((1 - 2*x)^(5/2)*(2 + 3*x)^2), x, 5, (-750*Sqrt[1 - 2*x])/343 - (50*Sqrt[1 - 2*x]*(3 + 5*x))/(1029*(2 + 3*x)) - (15*(3 + 5*x)^2)/(49*Sqrt[1 - 2*x]*(2 + 3*x)) + (2*(3 + 5*x)^3)/(21*(1 - 2*x)^(3/2)*(2 + 3*x)) - (200*ArcTanh[Sqrt[3/7]*Sqrt[1 - 2*x]])/(1029*Sqrt[21])}
{(3 + 5*x)^3/((1 - 2*x)^(5/2)*(2 + 3*x)^3), x, 5, (-5*Sqrt[1 - 2*x]*(1 + x))/(294*(2 + 3*x)^2) + (50*Sqrt[1 - 2*x])/(1029*(2 + 3*x)) + (3 + 5*x)^2/(7*Sqrt[1 - 2*x]*(2 + 3*x)^2) + (2*(3 + 5*x)^3)/(21*(1 - 2*x)^(3/2)*(2 + 3*x)^2) + (905*ArcTanh[Sqrt[3/7]*Sqrt[1 - 2*x]])/(1029*Sqrt[21])}
{(3 + 5*x)^3/((1 - 2*x)^(5/2)*(2 + 3*x)^4), x, 6, (125*Sqrt[1 - 2*x])/(1029*(2 + 3*x)^2) - (3755*Sqrt[1 - 2*x])/(7203*(2 + 3*x)) + (4*Sqrt[1 - 2*x]*(3 + 5*x))/(49*(2 + 3*x)^3) + (29*(3 + 5*x)^2)/(49*Sqrt[1 - 2*x]*(2 + 3*x)^3) + (2*(3 + 5*x)^3)/(21*(1 - 2*x)^(3/2)*(2 + 3*x)^3) - (7510*ArcTanh[Sqrt[3/7]*Sqrt[1 - 2*x]])/(7203*Sqrt[21])}
{(3 + 5*x)^3/((1 - 2*x)^(5/2)*(2 + 3*x)^5), x, 7, (692*Sqrt[1 - 2*x])/(3087*(2 + 3*x)^3) - (177635*Sqrt[1 - 2*x])/(172872*(2 + 3*x)^2) - (177635*Sqrt[1 - 2*x])/(403368*(2 + 3*x)) + (601*Sqrt[1 - 2*x]*(3 + 5*x))/(4116*(2 + 3*x)^4) + (51*(3 + 5*x)^2)/(49*Sqrt[1 - 2*x]*(2 + 3*x)^4) + (2*(3 + 5*x)^3)/(21*(1 - 2*x)^(3/2)*(2 + 3*x)^4) - (177635*ArcTanh[Sqrt[3/7]*Sqrt[1 - 2*x]])/(201684*Sqrt[21])}
{(3 + 5*x)^3/((1 - 2*x)^(5/2)*(2 + 3*x)^6), x, 8, (3912*Sqrt[1 - 2*x])/(12005*(2 + 3*x)^4) - (163474*Sqrt[1 - 2*x])/(108045*(2 + 3*x)^3) - (81737*Sqrt[1 - 2*x])/(151263*(2 + 3*x)^2) - (81737*Sqrt[1 - 2*x])/(352947*(2 + 3*x)) + (1082*Sqrt[1 - 2*x]*(3 + 5*x))/(5145*(2 + 3*x)^5) + (73*(3 + 5*x)^2)/(49*Sqrt[1 - 2*x]*(2 + 3*x)^5) + (2*(3 + 5*x)^3)/(21*(1 - 2*x)^(3/2)*(2 + 3*x)^5) - (163474*ArcTanh[Sqrt[3/7]*Sqrt[1 - 2*x]])/(352947*Sqrt[21])}


(* ::Subsubsection::Closed:: *)
(*n<0*)


{(2 + 3*x)^6/((1 - 2*x)^(5/2)*(3 + 5*x)), x, 7, (-55573878*Sqrt[1 - 2*x])/75625 - (63513*Sqrt[1 - 2*x]*(2 + 3*x))/605 - (340248*Sqrt[1 - 2*x]*(2 + 3*x)^2)/15125 - (7561*(2 + 3*x)^3)/(605*Sqrt[1 - 2*x]) + (172*(2 + 3*x)^4)/(165*(1 - 2*x)^(3/2)) - (3*(2 + 3*x)^5)/(35*(1 - 2*x)^(3/2)) - (2*ArcTanh[Sqrt[5/11]*Sqrt[1 - 2*x]])/(75625*Sqrt[55])}
{(2 + 3*x)^5/((1 - 2*x)^(5/2)*(3 + 5*x)), x, 6, (-2276102*Sqrt[1 - 2*x])/15125 - (31612*(2 + 3*x)^2)/(3025*Sqrt[1 - 2*x]) + (959*(2 + 3*x)^3)/(825*(1 - 2*x)^(3/2)) - (3*(2 + 3*x)^4)/(25*(1 - 2*x)^(3/2)) - (Sqrt[1 - 2*x]*(569026 + 948375*x))/15125 - (2*ArcTanh[Sqrt[5/11]*Sqrt[1 - 2*x]])/(15125*Sqrt[55])}
{(2 + 3*x)^4/((1 - 2*x)^(5/2)*(3 + 5*x)), x, 5, (-80818*Sqrt[1 - 2*x])/3025 + (238*(2 + 3*x)^2)/(165*(1 - 2*x)^(3/2)) - (2 + 3*x)^3/(5*(1 - 2*x)^(3/2)) - (7*(1426 + 2377*x))/(605*Sqrt[1 - 2*x]) - (2*ArcTanh[Sqrt[5/11]*Sqrt[1 - 2*x]])/(3025*Sqrt[55])}
{(2 + 3*x)^3/((1 - 2*x)^(5/2)*(3 + 5*x)), x, 4, -5152/(605*Sqrt[1 - 2*x]) + (469*(2 + 3*x))/(165*(1 - 2*x)^(3/2)) - (3*(2 + 3*x)^2)/(5*(1 - 2*x)^(3/2)) - (2*ArcTanh[Sqrt[5/11]*Sqrt[1 - 2*x]])/(605*Sqrt[55])}
{(2 + 3*x)^2/((1 - 2*x)^(5/2)*(3 + 5*x)), x, 3, 49/(66*(1 - 2*x)^(3/2)) - 217/(242*Sqrt[1 - 2*x]) - (2*ArcTanh[Sqrt[5/11]*Sqrt[1 - 2*x]])/(121*Sqrt[55])}
{(2 + 3*x)/((1 - 2*x)^(5/2)*(3 + 5*x)), x, 3, 7/(33*(1 - 2*x)^(3/2)) + 2/(121*Sqrt[1 - 2*x]) - (2*Sqrt[5/11]*ArcTanh[Sqrt[5/11]*Sqrt[1 - 2*x]])/121}
{1/((1 - 2*x)^(5/2)*(3 + 5*x)), x, 3, 2/(33*(1 - 2*x)^(3/2)) + 10/(121*Sqrt[1 - 2*x]) - (10*Sqrt[5/11]*ArcTanh[Sqrt[5/11]*Sqrt[1 - 2*x]])/121}
{1/((1 - 2*x)^(5/2)*(2 + 3*x)*(3 + 5*x)), x, 5, 4/(231*(1 - 2*x)^(3/2)) + 272/(5929*Sqrt[1 - 2*x]) + (18*Sqrt[3/7]*ArcTanh[Sqrt[3/7]*Sqrt[1 - 2*x]])/49 - (50*Sqrt[5/11]*ArcTanh[Sqrt[5/11]*Sqrt[1 - 2*x]])/121}
{1/((1 - 2*x)^(5/2)*(2 + 3*x)^2*(3 + 5*x)), x, 6, 4/(231*(1 - 2*x)^(3/2)*(2 + 3*x)) + 360/(5929*Sqrt[1 - 2*x]*(2 + 3*x)) + (2055*Sqrt[1 - 2*x])/(41503*(2 + 3*x)) + (720*Sqrt[3/7]*ArcTanh[Sqrt[3/7]*Sqrt[1 - 2*x]])/343 - (250*Sqrt[5/11]*ArcTanh[Sqrt[5/11]*Sqrt[1 - 2*x]])/121}
{1/((1 - 2*x)^(5/2)*(2 + 3*x)^3*(3 + 5*x)), x, 7, 4/(231*(1 - 2*x)^(3/2)*(2 + 3*x)^2) + 64/(847*Sqrt[1 - 2*x]*(2 + 3*x)^2) + (45*Sqrt[1 - 2*x])/(11858*(2 + 3*x)^2) + (36885*Sqrt[1 - 2*x])/(83006*(2 + 3*x)) + (3645*Sqrt[3/7]*ArcTanh[Sqrt[3/7]*Sqrt[1 - 2*x]])/343 - (1250*Sqrt[5/11]*ArcTanh[Sqrt[5/11]*Sqrt[1 - 2*x]])/121}
{1/((1 - 2*x)^(5/2)*(2 + 3*x)^4*(3 + 5*x)), x, 8, 4/(231*(1 - 2*x)^(3/2)*(2 + 3*x)^3) + 536/(5929*Sqrt[1 - 2*x]*(2 + 3*x)^3) - (93*Sqrt[1 - 2*x])/(5929*(2 + 3*x)^3) + (8955*Sqrt[1 - 2*x])/(41503*(2 + 3*x)^2) + (669990*Sqrt[1 - 2*x])/(290521*(2 + 3*x)) + (127710*Sqrt[3/7]*ArcTanh[Sqrt[3/7]*Sqrt[1 - 2*x]])/2401 - (6250*Sqrt[5/11]*ArcTanh[Sqrt[5/11]*Sqrt[1 - 2*x]])/121}


{(2 + 3*x)^6/((1 - 2*x)^(5/2)*(3 + 5*x)^2), x, 7, (-77849506*Sqrt[1 - 2*x])/831875 + (154448*Sqrt[1 - 2*x]*(2 + 3*x)^2)/(166375*(3 + 5*x)) - (93611*(2 + 3*x)^3)/(9075*Sqrt[1 - 2*x]*(3 + 5*x)) + (959*(2 + 3*x)^4)/(825*(1 - 2*x)^(3/2)*(3 + 5*x)) - (3*(2 + 3*x)^5)/(25*(1 - 2*x)^(3/2)*(3 + 5*x)) - (7*Sqrt[1 - 2*x]*(2780354 + 4633875*x))/831875 - (406*ArcTanh[Sqrt[5/11]*Sqrt[1 - 2*x]])/(831875*Sqrt[55])}
{(2 + 3*x)^5/((1 - 2*x)^(5/2)*(3 + 5*x)^2), x, 6, (-532452*Sqrt[1 - 2*x])/33275 + (1014*Sqrt[1 - 2*x]*(2 + 3*x))/(1331*(3 + 5*x)) - (15442*(2 + 3*x)^2)/(1815*Sqrt[1 - 2*x]*(3 + 5*x)) + (238*(2 + 3*x)^3)/(165*(1 - 2*x)^(3/2)*(3 + 5*x)) - (2 + 3*x)^4/(5*(1 - 2*x)^(3/2)*(3 + 5*x)) - (68*ArcTanh[Sqrt[5/11]*Sqrt[1 - 2*x]])/(33275*Sqrt[55])}
{(2 + 3*x)^4/((1 - 2*x)^(5/2)*(3 + 5*x)^2), x, 5, (-26988*Sqrt[1 - 2*x])/(33275*(3 + 5*x)) + (469*(2 + 3*x)^2)/(165*(1 - 2*x)^(3/2)*(3 + 5*x)) - (3*(2 + 3*x)^3)/(5*(1 - 2*x)^(3/2)*(3 + 5*x)) - (7*(3944 + 7323*x))/(1815*Sqrt[1 - 2*x]*(3 + 5*x)) - (274*ArcTanh[Sqrt[5/11]*Sqrt[1 - 2*x]])/(33275*Sqrt[55])}
{(2 + 3*x)^3/((1 - 2*x)^(5/2)*(3 + 5*x)^2), x, 5, (-942*Sqrt[1 - 2*x])/6655 + (6*Sqrt[1 - 2*x]*(2 + 3*x))/(1331*(3 + 5*x)) - (23*(2 + 3*x)^2)/(363*Sqrt[1 - 2*x]*(3 + 5*x)) + (2*(2 + 3*x)^3)/(33*(1 - 2*x)^(3/2)*(3 + 5*x)) - (208*ArcTanh[Sqrt[5/11]*Sqrt[1 - 2*x]])/(6655*Sqrt[55])}
{(2 + 3*x)^2/((1 - 2*x)^(5/2)*(3 + 5*x)^2), x, 4, 142/(6655*Sqrt[1 - 2*x]) + 49/(66*(1 - 2*x)^(3/2)*(3 + 5*x)) - 1231/(3630*Sqrt[1 - 2*x]*(3 + 5*x)) - (142*ArcTanh[Sqrt[5/11]*Sqrt[1 - 2*x]])/(1331*Sqrt[55])}
{(2 + 3*x)/((1 - 2*x)^(5/2)*(3 + 5*x)^2), x, 4, 76/(1815*(1 - 2*x)^(3/2)) + 76/(1331*Sqrt[1 - 2*x]) - 1/(55*(1 - 2*x)^(3/2)*(3 + 5*x)) - (76*Sqrt[5/11]*ArcTanh[Sqrt[5/11]*Sqrt[1 - 2*x]])/1331}
{1/((1 - 2*x)^(5/2)*(3 + 5*x)^2), x, 4, 10/(363*(1 - 2*x)^(3/2)) + 50/(1331*Sqrt[1 - 2*x]) - 1/(11*(1 - 2*x)^(3/2)*(3 + 5*x)) - (50*Sqrt[5/11]*ArcTanh[Sqrt[5/11]*Sqrt[1 - 2*x]])/1331}
{1/((1 - 2*x)^(5/2)*(2 + 3*x)*(3 + 5*x)^2), x, 6, 4/(231*(1 - 2*x)^(3/2)*(3 + 5*x)) + 1096/(17787*Sqrt[1 - 2*x]*(3 + 5*x)) - (8185*Sqrt[1 - 2*x])/(65219*(3 + 5*x)) - (54*Sqrt[3/7]*ArcTanh[Sqrt[3/7]*Sqrt[1 - 2*x]])/49 + (1400*Sqrt[5/11]*ArcTanh[Sqrt[5/11]*Sqrt[1 - 2*x]])/1331}
{1/((1 - 2*x)^(5/2)*(2 + 3*x)^2*(3 + 5*x)^2), x, 7, (-399500*Sqrt[1 - 2*x])/(456533*(3 + 5*x)) + 4/(231*(1 - 2*x)^(3/2)*(2 + 3*x)*(3 + 5*x)) + 1360/(17787*Sqrt[1 - 2*x]*(2 + 3*x)*(3 + 5*x)) + (1775*Sqrt[1 - 2*x])/(41503*(2 + 3*x)*(3 + 5*x)) - (4050*Sqrt[3/7]*ArcTanh[Sqrt[3/7]*Sqrt[1 - 2*x]])/343 + (15250*Sqrt[5/11]*ArcTanh[Sqrt[5/11]*Sqrt[1 - 2*x]])/1331}
{1/((1 - 2*x)^(5/2)*(2 + 3*x)^3*(3 + 5*x)^2), x, 8, (-860525*Sqrt[1 - 2*x])/(130438*(3 + 5*x)) + 4/(231*(1 - 2*x)^(3/2)*(2 + 3*x)^2*(3 + 5*x)) + 232/(2541*Sqrt[1 - 2*x]*(2 + 3*x)^2*(3 + 5*x)) - (5*Sqrt[1 - 2*x])/(1694*(2 + 3*x)^2*(3 + 5*x)) + (3790*Sqrt[1 - 2*x])/(5929*(2 + 3*x)*(3 + 5*x)) - (4455*Sqrt[3/7]*ArcTanh[Sqrt[3/7]*Sqrt[1 - 2*x]])/49 + (117500*Sqrt[5/11]*ArcTanh[Sqrt[5/11]*Sqrt[1 - 2*x]])/1331}


{(2 + 3*x)^6/((1 - 2*x)^(5/2)*(3 + 5*x)^3), x, 7, (-18063843*Sqrt[1 - 2*x])/1830125 + (149653*Sqrt[1 - 2*x]*(2 + 3*x)^2)/(199650*(3 + 5*x)^2) - (15197*(2 + 3*x)^3)/(1815*Sqrt[1 - 2*x]*(3 + 5*x)^2) + (238*(2 + 3*x)^4)/(165*(1 - 2*x)^(3/2)*(3 + 5*x)^2) - (2 + 3*x)^5/(5*(1 - 2*x)^(3/2)*(3 + 5*x)^2) + (13755*Sqrt[1 - 2*x]*(2 + 3*x))/(29282*(3 + 5*x)) - (6937*ArcTanh[Sqrt[5/11]*Sqrt[1 - 2*x]])/(1830125*Sqrt[55])}
{(2 + 3*x)^5/((1 - 2*x)^(5/2)*(3 + 5*x)^3), x, 6, (29033*Sqrt[1 - 2*x]*(2 + 3*x))/(39930*(3 + 5*x)^2) - (14966*(2 + 3*x)^2)/(1815*Sqrt[1 - 2*x]*(3 + 5*x)^2) + (469*(2 + 3*x)^3)/(165*(1 - 2*x)^(3/2)*(3 + 5*x)^2) - (3*(2 + 3*x)^4)/(5*(1 - 2*x)^(3/2)*(3 + 5*x)^2) + (164309*Sqrt[1 - 2*x])/(366025*(3 + 5*x)) - (4693*ArcTanh[Sqrt[5/11]*Sqrt[1 - 2*x]])/(366025*Sqrt[55])}
{(2 + 3*x)^4/((1 - 2*x)^(5/2)*(3 + 5*x)^3), x, 6, (-29037*Sqrt[1 - 2*x])/366025 + (31*Sqrt[1 - 2*x]*(2 + 3*x)^2)/(7986*(3 + 5*x)^2) - (19*(2 + 3*x)^3)/(363*Sqrt[1 - 2*x]*(3 + 5*x)^2) + (2*(2 + 3*x)^4)/(33*(1 - 2*x)^(3/2)*(3 + 5*x)^2) + (141*Sqrt[1 - 2*x]*(2 + 3*x))/(146410*(3 + 5*x)) - (14423*ArcTanh[Sqrt[5/11]*Sqrt[1 - 2*x]])/(366025*Sqrt[55])}
{(2 + 3*x)^3/((1 - 2*x)^(5/2)*(3 + 5*x)^3), x, 5, (-101*Sqrt[1 - 2*x]*(2 + 3*x))/(7986*(3 + 5*x)^2) + (47*(2 + 3*x)^2)/(363*Sqrt[1 - 2*x]*(3 + 5*x)^2) + (2*(2 + 3*x)^3)/(33*(1 - 2*x)^(3/2)*(3 + 5*x)^2) - (683*Sqrt[1 - 2*x])/(73205*(3 + 5*x)) - (7559*ArcTanh[Sqrt[5/11]*Sqrt[1 - 2*x]])/(73205*Sqrt[55])}
{(2 + 3*x)^2/((1 - 2*x)^(5/2)*(3 + 5*x)^3), x, 5, 49/(66*(1 - 2*x)^(3/2)*(3 + 5*x)^2) - 614/(1815*Sqrt[1 - 2*x]*(3 + 5*x)^2) + 2873/(19965*Sqrt[1 - 2*x]*(3 + 5*x)) - (2873*Sqrt[1 - 2*x])/(29282*(3 + 5*x)) - (2873*ArcTanh[Sqrt[5/11]*Sqrt[1 - 2*x]])/(14641*Sqrt[55])}
{(2 + 3*x)/((1 - 2*x)^(5/2)*(3 + 5*x)^3), x, 5, 73/(3993*(1 - 2*x)^(3/2)) + 365/(14641*Sqrt[1 - 2*x]) - 1/(110*(1 - 2*x)^(3/2)*(3 + 5*x)^2) - 73/(1210*(1 - 2*x)^(3/2)*(3 + 5*x)) - (365*Sqrt[5/11]*ArcTanh[Sqrt[5/11]*Sqrt[1 - 2*x]])/14641}
{1/((1 - 2*x)^(5/2)*(3 + 5*x)^3), x, 5, 2/(33*(1 - 2*x)^(3/2)*(3 + 5*x)^2) + 70/(363*Sqrt[1 - 2*x]*(3 + 5*x)^2) - (875*Sqrt[1 - 2*x])/(7986*(3 + 5*x)^2) - (875*Sqrt[1 - 2*x])/(29282*(3 + 5*x)) - (175*Sqrt[5/11]*ArcTanh[Sqrt[5/11]*Sqrt[1 - 2*x]])/14641}
{1/((1 - 2*x)^(5/2)*(2 + 3*x)*(3 + 5*x)^3), x, 7, 4/(231*(1 - 2*x)^(3/2)*(3 + 5*x)^2) + 1376/(17787*Sqrt[1 - 2*x]*(3 + 5*x)^2) - (33535*Sqrt[1 - 2*x])/(391314*(3 + 5*x)^2) + (325835*Sqrt[1 - 2*x])/(1434818*(3 + 5*x)) + (162*Sqrt[3/7]*ArcTanh[Sqrt[3/7]*Sqrt[1 - 2*x]])/49 - (47075*Sqrt[5/11]*ArcTanh[Sqrt[5/11]*Sqrt[1 - 2*x]])/14641}
{1/((1 - 2*x)^(5/2)*(2 + 3*x)^2*(3 + 5*x)^3), x, 8, (-1759475*Sqrt[1 - 2*x])/(2739198*(3 + 5*x)^2) + 4/(231*(1 - 2*x)^(3/2)*(2 + 3*x)*(3 + 5*x)^2) + 1640/(17787*Sqrt[1 - 2*x]*(2 + 3*x)*(3 + 5*x)^2) + (1495*Sqrt[1 - 2*x])/(41503*(2 + 3*x)*(3 + 5*x)^2) + (37771225*Sqrt[1 - 2*x])/(10043726*(3 + 5*x)) + (17820*Sqrt[3/7]*ArcTanh[Sqrt[3/7]*Sqrt[1 - 2*x]])/343 - (738625*Sqrt[5/11]*ArcTanh[Sqrt[5/11]*Sqrt[1 - 2*x]])/14641}
{1/((1 - 2*x)^(5/2)*(2 + 3*x)^3*(3 + 5*x)^3), x, 9, (-17552275*Sqrt[1 - 2*x])/(2739198*(3 + 5*x)^2) + 4/(231*(1 - 2*x)^(3/2)*(2 + 3*x)^2*(3 + 5*x)^2) + 272/(2541*Sqrt[1 - 2*x]*(2 + 3*x)^2*(3 + 5*x)^2) - (115*Sqrt[1 - 2*x])/(11858*(2 + 3*x)^2*(3 + 5*x)^2) + (69235*Sqrt[1 - 2*x])/(83006*(2 + 3*x)*(3 + 5*x)^2) + (193818700*Sqrt[1 - 2*x])/(5021863*(3 + 5*x)) + (182655*Sqrt[3/7]*ArcTanh[Sqrt[3/7]*Sqrt[1 - 2*x]])/343 - (7570625*Sqrt[5/11]*ArcTanh[Sqrt[5/11]*Sqrt[1 - 2*x]])/14641}


(* ::Section::Closed:: *)
(*Integrands of the form (a+b x)^m (c+d x)^(n/2) (e+f x)^(p/2)*)


(* ::Subsection::Closed:: *)
(*Integrands of the form (a+b x)^m (c+d x)^(n/2) (e+f x)^(1/2)*)


(* ::Subsubsection::Closed:: *)
(*n>0*)


{Sqrt[1 - 2*x]*(2 + 3*x)^4*Sqrt[3 + 5*x], x, 7, (-374762311*Sqrt[1 - 2*x]*Sqrt[3 + 5*x])/51200000 - (32497997*Sqrt[1 - 2*x]*(3 + 5*x)^(3/2))/38400000 - (186473*Sqrt[1 - 2*x]*(2 + 3*x)*(3 + 5*x)^(3/2))/960000 - (3731*Sqrt[1 - 2*x]*(2 + 3*x)^2*(3 + 5*x)^(3/2))/80000 - (17*Sqrt[1 - 2*x]*(2 + 3*x)^3*(3 + 5*x)^(3/2))/3000 + (Sqrt[1 - 2*x]*(2 + 3*x)^4*(3 + 5*x)^(3/2))/30 + (4122385421*ArcSin[Sqrt[2/11]*Sqrt[3 + 5*x]])/(51200000*Sqrt[10])}
{Sqrt[1 - 2*x]*(2 + 3*x)^3*Sqrt[3 + 5*x], x, 6, (-3558401*Sqrt[1 - 2*x]*Sqrt[3 + 5*x])/1280000 - (104377*Sqrt[1 - 2*x]*(3 + 5*x)^(3/2))/320000 - (21*Sqrt[1 - 2*x]*(2 + 3*x)^2*(3 + 5*x)^(3/2))/2000 + (Sqrt[1 - 2*x]*(2 + 3*x)^3*(3 + 5*x)^(3/2))/25 - (7*Sqrt[1 - 2*x]*(3 + 5*x)^(3/2)*(802 + 1245*x))/40000 + (39142411*ArcSin[Sqrt[2/11]*Sqrt[3 + 5*x]])/(1280000*Sqrt[10])}
{Sqrt[1 - 2*x]*(2 + 3*x)^2*Sqrt[3 + 5*x], x, 5, (14443*Sqrt[1 - 2*x]*Sqrt[3 + 5*x])/12800 - (1313*(1 - 2*x)^(3/2)*Sqrt[3 + 5*x])/1280 - (37/160)*(1 - 2*x)^(3/2)*(3 + 5*x)^(3/2) - (3/40)*(1 - 2*x)^(3/2)*(2 + 3*x)*(3 + 5*x)^(3/2) + (158873*ArcSin[Sqrt[2/11]*Sqrt[3 + 5*x]])/(12800*Sqrt[10])}
{Sqrt[1 - 2*x]*(2 + 3*x)*Sqrt[3 + 5*x], x, 4, (407*Sqrt[1 - 2*x]*Sqrt[3 + 5*x])/800 - (37*(1 - 2*x)^(3/2)*Sqrt[3 + 5*x])/80 - ((1 - 2*x)^(3/2)*(3 + 5*x)^(3/2))/10 + (4477*ArcSin[Sqrt[2/11]*Sqrt[3 + 5*x]])/(800*Sqrt[10])}
{Sqrt[1 - 2*x]*Sqrt[3 + 5*x], x, 3, (11*Sqrt[1 - 2*x]*Sqrt[3 + 5*x])/40 - ((1 - 2*x)^(3/2)*Sqrt[3 + 5*x])/4 + (121*ArcSin[Sqrt[2/11]*Sqrt[3 + 5*x]])/(40*Sqrt[10])}
{(Sqrt[1 - 2*x]*Sqrt[3 + 5*x])/(2 + 3*x), x, 4, (Sqrt[1 - 2*x]*Sqrt[3 + 5*x])/3 + (37*ArcSin[Sqrt[2/11]*Sqrt[3 + 5*x]])/(9*Sqrt[10]) - (2*Sqrt[7]*ArcTan[(Sqrt[7]*Sqrt[3 + 5*x])/Sqrt[1 - 2*x]])/9}
{(Sqrt[1 - 2*x]*Sqrt[3 + 5*x])/(2 + 3*x)^2, x, 4, -(Sqrt[1 - 2*x]*Sqrt[3 + 5*x])/(3*(2 + 3*x)) - (2*Sqrt[10]*ArcSin[Sqrt[2/11]*Sqrt[3 + 5*x]])/9 + (37*ArcTan[(Sqrt[7]*Sqrt[3 + 5*x])/Sqrt[1 - 2*x]])/(9*Sqrt[7])}
{(Sqrt[1 - 2*x]*Sqrt[3 + 5*x])/(2 + 3*x)^3, x, 3, (-11*Sqrt[1 - 2*x]*Sqrt[3 + 5*x])/(28*(2 + 3*x)) + (Sqrt[1 - 2*x]*(3 + 5*x)^(3/2))/(2*(2 + 3*x)^2) + (121*ArcTan[(Sqrt[7]*Sqrt[3 + 5*x])/Sqrt[1 - 2*x]])/(28*Sqrt[7])}
{(Sqrt[1 - 2*x]*Sqrt[3 + 5*x])/(2 + 3*x)^4, x, 5, -(Sqrt[1 - 2*x]*Sqrt[3 + 5*x])/(9*(2 + 3*x)^3) + (37*Sqrt[1 - 2*x]*Sqrt[3 + 5*x])/(252*(2 + 3*x)^2) + (3547*Sqrt[1 - 2*x]*Sqrt[3 + 5*x])/(3528*(2 + 3*x)) + (4477*ArcTan[(Sqrt[7]*Sqrt[3 + 5*x])/Sqrt[1 - 2*x]])/(392*Sqrt[7])}
{(Sqrt[1 - 2*x]*Sqrt[3 + 5*x])/(2 + 3*x)^5, x, 6, -(Sqrt[1 - 2*x]*Sqrt[3 + 5*x])/(12*(2 + 3*x)^4) + (37*Sqrt[1 - 2*x]*Sqrt[3 + 5*x])/(504*(2 + 3*x)^3) + (6005*Sqrt[1 - 2*x]*Sqrt[3 + 5*x])/(14112*(2 + 3*x)^2) + (625115*Sqrt[1 - 2*x]*Sqrt[3 + 5*x])/(197568*(2 + 3*x)) + (794365*ArcTan[(Sqrt[7]*Sqrt[3 + 5*x])/Sqrt[1 - 2*x]])/(21952*Sqrt[7])}
{(Sqrt[1 - 2*x]*Sqrt[3 + 5*x])/(2 + 3*x)^6, x, 7, -((Sqrt[1 - 2*x]*Sqrt[3 + 5*x])/(15*(2 + 3*x)^5)) + (37*Sqrt[1 - 2*x]*Sqrt[3 + 5*x])/(840*(2 + 3*x)^4) + (403*Sqrt[1 - 2*x]*Sqrt[3 + 5*x])/(1680*(2 + 3*x)^3) + (14023*Sqrt[1 - 2*x]*Sqrt[3 + 5*x])/(9408*(2 + 3*x)^2) + (1466281*Sqrt[1 - 2*x]*Sqrt[3 + 5*x])/(131712*(2 + 3*x)) + (5591773*ArcTan[(Sqrt[7]*Sqrt[3 + 5*x])/Sqrt[1 - 2*x]])/(43904*Sqrt[7])}
{(Sqrt[1 - 2*x]*Sqrt[3 + 5*x])/(2 + 3*x)^7, x, 8, -((Sqrt[1 - 2*x]*Sqrt[3 + 5*x])/(18*(2 + 3*x)^6)) + (37*Sqrt[1 - 2*x]*Sqrt[3 + 5*x])/(1260*(2 + 3*x)^5) + (10921*Sqrt[1 - 2*x]*Sqrt[3 + 5*x])/(70560*(2 + 3*x)^4) + (126799*Sqrt[1 - 2*x]*Sqrt[3 + 5*x])/(141120*(2 + 3*x)^3) + (4429459*Sqrt[1 - 2*x]*Sqrt[3 + 5*x])/(790272*(2 + 3*x)^2) + (463266973*Sqrt[1 - 2*x]*Sqrt[3 + 5*x])/(11063808*(2 + 3*x)) + (588912203*ArcTan[(Sqrt[7]*Sqrt[3 + 5*x])/Sqrt[1 - 2*x]])/(1229312*Sqrt[7])}


{Sqrt[1 - 2*x]*(2 + 3*x)^4*(3 + 5*x)^(3/2), x, 8, (-6384004649*Sqrt[1 - 2*x]*Sqrt[3 + 5*x])/204800000 - (580364059*Sqrt[1 - 2*x]*(3 + 5*x)^(3/2))/153600000 - (10031801*Sqrt[1 - 2*x]*(3 + 5*x)^(5/2))/19200000 - (8223*Sqrt[1 - 2*x]*(2 + 3*x)*(3 + 5*x)^(5/2))/64000 - (643*Sqrt[1 - 2*x]*(2 + 3*x)^2*(3 + 5*x)^(5/2))/20000 - (17*Sqrt[1 - 2*x]*(2 + 3*x)^3*(3 + 5*x)^(5/2))/4200 + (Sqrt[1 - 2*x]*(2 + 3*x)^4*(3 + 5*x)^(5/2))/35 + (70224051139*ArcSin[Sqrt[2/11]*Sqrt[3 + 5*x]])/(204800000*Sqrt[10])}
{Sqrt[1 - 2*x]*(2 + 3*x)^3*(3 + 5*x)^(3/2), x, 7, (-115431701*Sqrt[1 - 2*x]*Sqrt[3 + 5*x])/10240000 - (10493791*Sqrt[1 - 2*x]*(3 + 5*x)^(3/2))/7680000 - (183701*Sqrt[1 - 2*x]*(3 + 5*x)^(5/2))/960000 - (7*Sqrt[1 - 2*x]*(2 + 3*x)^2*(3 + 5*x)^(5/2))/1000 + (Sqrt[1 - 2*x]*(2 + 3*x)^3*(3 + 5*x)^(5/2))/30 - (49*Sqrt[1 - 2*x]*(3 + 5*x)^(5/2)*(146 + 225*x))/80000 + (1269748711*ArcSin[Sqrt[2/11]*Sqrt[3 + 5*x]])/(10240000*Sqrt[10])}
{Sqrt[1 - 2*x]*(2 + 3*x)^2*(3 + 5*x)^(3/2), x, 6, (1089847*Sqrt[1 - 2*x]*Sqrt[3 + 5*x])/256000 - (99077*(1 - 2*x)^(3/2)*Sqrt[3 + 5*x])/25600 - (9007*(1 - 2*x)^(3/2)*(3 + 5*x)^(3/2))/9600 - (153/800)*(1 - 2*x)^(3/2)*(3 + 5*x)^(5/2) - (3/50)*(1 - 2*x)^(3/2)*(2 + 3*x)*(3 + 5*x)^(5/2) + (11988317*ArcSin[Sqrt[2/11]*Sqrt[3 + 5*x]])/(256000*Sqrt[10])}
{Sqrt[1 - 2*x]*(2 + 3*x)*(3 + 5*x)^(3/2), x, 5, (21901*Sqrt[1 - 2*x]*Sqrt[3 + 5*x])/12800 - (1991*(1 - 2*x)^(3/2)*Sqrt[3 + 5*x])/1280 - (181*(1 - 2*x)^(3/2)*(3 + 5*x)^(3/2))/480 - (3*(1 - 2*x)^(3/2)*(3 + 5*x)^(5/2))/40 + (240911*ArcSin[Sqrt[2/11]*Sqrt[3 + 5*x]])/(12800*Sqrt[10])}
{Sqrt[1 - 2*x]*(3 + 5*x)^(3/2), x, 4, (121*Sqrt[1 - 2*x]*Sqrt[3 + 5*x])/160 - (11*(1 - 2*x)^(3/2)*Sqrt[3 + 5*x])/16 - ((1 - 2*x)^(3/2)*(3 + 5*x)^(3/2))/6 + (1331*ArcSin[Sqrt[2/11]*Sqrt[3 + 5*x]])/(160*Sqrt[10])}
{(Sqrt[1 - 2*x]*(3 + 5*x)^(3/2))/(2 + 3*x), x, 5, (-41*Sqrt[1 - 2*x]*Sqrt[3 + 5*x])/72 + (Sqrt[1 - 2*x]*(3 + 5*x)^(3/2))/6 + (793*ArcSin[Sqrt[2/11]*Sqrt[3 + 5*x]])/(216*Sqrt[10]) + (2*Sqrt[7]*ArcTan[(Sqrt[7]*Sqrt[3 + 5*x])/Sqrt[1 - 2*x]])/27}
{(Sqrt[1 - 2*x]*(3 + 5*x)^(3/2))/(2 + 3*x)^2, x, 5, (10*Sqrt[1 - 2*x]*Sqrt[3 + 5*x])/9 - (Sqrt[1 - 2*x]*(3 + 5*x)^(3/2))/(3*(2 + 3*x)) + (41*Sqrt[5/2]*ArcSin[Sqrt[2/11]*Sqrt[3 + 5*x]])/27 - (107*ArcTan[(Sqrt[7]*Sqrt[3 + 5*x])/Sqrt[1 - 2*x]])/(27*Sqrt[7])}
{(Sqrt[1 - 2*x]*(3 + 5*x)^(3/2))/(2 + 3*x)^3, x, 5, (-107*Sqrt[1 - 2*x]*Sqrt[3 + 5*x])/(252*(2 + 3*x)) - (Sqrt[1 - 2*x]*(3 + 5*x)^(3/2))/(6*(2 + 3*x)^2) - (10*Sqrt[10]*ArcSin[Sqrt[2/11]*Sqrt[3 + 5*x]])/27 + (4091*ArcTan[(Sqrt[7]*Sqrt[3 + 5*x])/Sqrt[1 - 2*x]])/(756*Sqrt[7])}
{(Sqrt[1 - 2*x]*(3 + 5*x)^(3/2))/(2 + 3*x)^4, x, 4, (-121*Sqrt[1 - 2*x]*Sqrt[3 + 5*x])/(392*(2 + 3*x)) - (11*Sqrt[1 - 2*x]*(3 + 5*x)^(3/2))/(84*(2 + 3*x)^2) + (Sqrt[1 - 2*x]*(3 + 5*x)^(5/2))/(3*(2 + 3*x)^3) + (1331*ArcTan[(Sqrt[7]*Sqrt[3 + 5*x])/Sqrt[1 - 2*x]])/(392*Sqrt[7])}
{(Sqrt[1 - 2*x]*(3 + 5*x)^(3/2))/(2 + 3*x)^5, x, 6, (-107*Sqrt[1 - 2*x]*Sqrt[3 + 5*x])/(1512*(2 + 3*x)^3) + (4355*Sqrt[1 - 2*x]*Sqrt[3 + 5*x])/(42336*(2 + 3*x)^2) + (368045*Sqrt[1 - 2*x]*Sqrt[3 + 5*x])/(592704*(2 + 3*x)) - (Sqrt[1 - 2*x]*(3 + 5*x)^(3/2))/(12*(2 + 3*x)^4) + (153065*ArcTan[(Sqrt[7]*Sqrt[3 + 5*x])/Sqrt[1 - 2*x]])/(21952*Sqrt[7])}
{(Sqrt[1 - 2*x]*(3 + 5*x)^(3/2))/(2 + 3*x)^6, x, 7, -((107*Sqrt[1 - 2*x]*Sqrt[3 + 5*x])/(2520*(2 + 3*x)^4)) + (641*Sqrt[1 - 2*x]*Sqrt[3 + 5*x])/(15120*(2 + 3*x)^3) + (17981*Sqrt[1 - 2*x]*Sqrt[3 + 5*x])/(84672*(2 + 3*x)^2) + (1852307*Sqrt[1 - 2*x]*Sqrt[3 + 5*x])/(1185408*(2 + 3*x)) - (Sqrt[1 - 2*x]*(3 + 5*x)^(3/2))/(15*(2 + 3*x)^5) + (783959*ArcTan[(Sqrt[7]*Sqrt[3 + 5*x])/Sqrt[1 - 2*x]])/(43904*Sqrt[7])}
{(Sqrt[1 - 2*x]*(3 + 5*x)^(3/2))/(2 + 3*x)^7, x, 8, -((107*Sqrt[1 - 2*x]*Sqrt[3 + 5*x])/(3780*(2 + 3*x)^5)) + (4619*Sqrt[1 - 2*x]*Sqrt[3 + 5*x])/(211680*(2 + 3*x)^4) + (42461*Sqrt[1 - 2*x]*Sqrt[3 + 5*x])/(423360*(2 + 3*x)^3) + (1460201*Sqrt[1 - 2*x]*Sqrt[3 + 5*x])/(2370816*(2 + 3*x)^2) + (152571047*Sqrt[1 - 2*x]*Sqrt[3 + 5*x])/(33191424*(2 + 3*x)) - (Sqrt[1 - 2*x]*(3 + 5*x)^(3/2))/(18*(2 + 3*x)^6) + (64645339*ArcTan[(Sqrt[7]*Sqrt[3 + 5*x])/Sqrt[1 - 2*x]])/(1229312*Sqrt[7])}


{Sqrt[1 - 2*x]*(2 + 3*x)^4*(3 + 5*x)^(5/2), x, 9, (-180773237579*Sqrt[1 - 2*x]*Sqrt[3 + 5*x])/1310720000 - (16433930689*Sqrt[1 - 2*x]*(3 + 5*x)^(3/2))/983040000 - (1493993699*Sqrt[1 - 2*x]*(3 + 5*x)^(5/2))/614400000 - (18411711*Sqrt[1 - 2*x]*(3 + 5*x)^(7/2))/51200000 - (58671*Sqrt[1 - 2*x]*(2 + 3*x)*(3 + 5*x)^(7/2))/640000 - (753*Sqrt[1 - 2*x]*(2 + 3*x)^2*(3 + 5*x)^(7/2))/32000 - (17*Sqrt[1 - 2*x]*(2 + 3*x)^3*(3 + 5*x)^(7/2))/5600 + (Sqrt[1 - 2*x]*(2 + 3*x)^4*(3 + 5*x)^(7/2))/40 + (1988505613369*ArcSin[Sqrt[2/11]*Sqrt[3 + 5*x]])/(1310720000*Sqrt[10])}
{Sqrt[1 - 2*x]*(2 + 3*x)^3*(3 + 5*x)^(5/2), x, 8, (-394818523*Sqrt[1 - 2*x]*Sqrt[3 + 5*x])/8192000 - (35892593*Sqrt[1 - 2*x]*(3 + 5*x)^(3/2))/6144000 - (3262963*Sqrt[1 - 2*x]*(3 + 5*x)^(5/2))/3840000 - (8131*Sqrt[1 - 2*x]*(3 + 5*x)^(7/2))/64000 - (Sqrt[1 - 2*x]*(2 + 3*x)^2*(3 + 5*x)^(7/2))/200 + (Sqrt[1 - 2*x]*(2 + 3*x)^3*(3 + 5*x)^(7/2))/35 - (3*Sqrt[1 - 2*x]*(3 + 5*x)^(7/2)*(414 + 635*x))/20000 + (4343003753*ArcSin[Sqrt[2/11]*Sqrt[3 + 5*x]])/(8192000*Sqrt[10])}
{Sqrt[1 - 2*x]*(2 + 3*x)^2*(3 + 5*x)^(5/2), x, 7, (1422839*Sqrt[1 - 2*x]*Sqrt[3 + 5*x])/81920 - (129349*(1 - 2*x)^(3/2)*Sqrt[3 + 5*x])/8192 - (11759*(1 - 2*x)^(3/2)*(3 + 5*x)^(3/2))/3072 - (1069*(1 - 2*x)^(3/2)*(3 + 5*x)^(5/2))/1280 - (13/80)*(1 - 2*x)^(3/2)*(3 + 5*x)^(7/2) - (1/20)*(1 - 2*x)^(3/2)*(2 + 3*x)*(3 + 5*x)^(7/2) + (15651229*ArcSin[Sqrt[2/11]*Sqrt[3 + 5*x]])/(81920*Sqrt[10])}
{Sqrt[1 - 2*x]*(2 + 3*x)*(3 + 5*x)^(5/2), x, 6, (334081*Sqrt[1 - 2*x]*Sqrt[3 + 5*x])/51200 - (30371*(1 - 2*x)^(3/2)*Sqrt[3 + 5*x])/5120 - (2761*(1 - 2*x)^(3/2)*(3 + 5*x)^(3/2))/1920 - (251*(1 - 2*x)^(3/2)*(3 + 5*x)^(5/2))/800 - (3*(1 - 2*x)^(3/2)*(3 + 5*x)^(7/2))/50 + (3674891*ArcSin[Sqrt[2/11]*Sqrt[3 + 5*x]])/(51200*Sqrt[10])}
{Sqrt[1 - 2*x]*(3 + 5*x)^(5/2), x, 5, (1331*Sqrt[1 - 2*x]*Sqrt[3 + 5*x])/512 - (605*(1 - 2*x)^(3/2)*Sqrt[3 + 5*x])/256 - (55*(1 - 2*x)^(3/2)*(3 + 5*x)^(3/2))/96 - ((1 - 2*x)^(3/2)*(3 + 5*x)^(5/2))/8 + (14641*ArcSin[Sqrt[2/11]*Sqrt[3 + 5*x]])/(512*Sqrt[10])}
{(Sqrt[1 - 2*x]*(3 + 5*x)^(5/2))/(2 + 3*x), x, 6, (-925*Sqrt[1 - 2*x]*Sqrt[3 + 5*x])/864 - (5*Sqrt[1 - 2*x]*(3 + 5*x)^(3/2))/24 + (Sqrt[1 - 2*x]*(3 + 5*x)^(5/2))/9 + (6553*Sqrt[5/2]*ArcSin[Sqrt[2/11]*Sqrt[3 + 5*x]])/2592 - (2*Sqrt[7]*ArcTan[(Sqrt[7]*Sqrt[3 + 5*x])/Sqrt[1 - 2*x]])/81}
{(Sqrt[1 - 2*x]*(3 + 5*x)^(5/2))/(2 + 3*x)^2, x, 6, (-95*Sqrt[1 - 2*x]*Sqrt[3 + 5*x])/72 + (5*Sqrt[1 - 2*x]*(3 + 5*x)^(3/2))/6 - (Sqrt[1 - 2*x]*(3 + 5*x)^(5/2))/(3*(2 + 3*x)) + (155*Sqrt[5/2]*ArcSin[Sqrt[2/11]*Sqrt[3 + 5*x]])/216 + (59*ArcTan[(Sqrt[7]*Sqrt[3 + 5*x])/Sqrt[1 - 2*x]])/(27*Sqrt[7])}
{(Sqrt[1 - 2*x]*(3 + 5*x)^(5/2))/(2 + 3*x)^3, x, 6, (215*Sqrt[1 - 2*x]*Sqrt[3 + 5*x])/84 - (59*Sqrt[1 - 2*x]*(3 + 5*x)^(3/2))/(84*(2 + 3*x)) - (Sqrt[1 - 2*x]*(3 + 5*x)^(5/2))/(6*(2 + 3*x)^2) + (25*Sqrt[5/2]*ArcSin[Sqrt[2/11]*Sqrt[3 + 5*x]])/9 - (2119*ArcTan[(Sqrt[7]*Sqrt[3 + 5*x])/Sqrt[1 - 2*x]])/(252*Sqrt[7])}
{(Sqrt[1 - 2*x]*(3 + 5*x)^(5/2))/(2 + 3*x)^4, x, 6, (-6401*Sqrt[1 - 2*x]*Sqrt[3 + 5*x])/(10584*(2 + 3*x)) - (59*Sqrt[1 - 2*x]*(3 + 5*x)^(3/2))/(252*(2 + 3*x)^2) - (Sqrt[1 - 2*x]*(3 + 5*x)^(5/2))/(9*(2 + 3*x)^3) - (50*Sqrt[10]*ArcSin[Sqrt[2/11]*Sqrt[3 + 5*x]])/81 + (250433*ArcTan[(Sqrt[7]*Sqrt[3 + 5*x])/Sqrt[1 - 2*x]])/(31752*Sqrt[7])}
{(Sqrt[1 - 2*x]*(3 + 5*x)^(5/2))/(2 + 3*x)^5, x, 5, (-6655*Sqrt[1 - 2*x]*Sqrt[3 + 5*x])/(21952*(2 + 3*x)) - (605*Sqrt[1 - 2*x]*(3 + 5*x)^(3/2))/(4704*(2 + 3*x)^2) - (11*Sqrt[1 - 2*x]*(3 + 5*x)^(5/2))/(168*(2 + 3*x)^3) + (Sqrt[1 - 2*x]*(3 + 5*x)^(7/2))/(4*(2 + 3*x)^4) + (73205*ArcTan[(Sqrt[7]*Sqrt[3 + 5*x])/Sqrt[1 - 2*x]])/(21952*Sqrt[7])}
{(Sqrt[1 - 2*x]*(3 + 5*x)^(5/2))/(2 + 3*x)^6, x, 7, -((103*Sqrt[1 - 2*x]*Sqrt[3 + 5*x])/(1680*(2 + 3*x)^3)) + (947*Sqrt[1 - 2*x]*Sqrt[3 + 5*x])/(9408*(2 + 3*x)^2) + (67709*Sqrt[1 - 2*x]*Sqrt[3 + 5*x])/(131712*(2 + 3*x)) - (59*Sqrt[1 - 2*x]*(3 + 5*x)^(3/2))/(840*(2 + 3*x)^4) - (Sqrt[1 - 2*x]*(3 + 5*x)^(5/2))/(15*(2 + 3*x)^5) + (248897*ArcTan[(Sqrt[7]*Sqrt[3 + 5*x])/Sqrt[1 - 2*x]])/(43904*Sqrt[7])}
{(Sqrt[1 - 2*x]*(3 + 5*x)^(5/2))/(2 + 3*x)^7, x, 8, -((6533*Sqrt[1 - 2*x]*Sqrt[3 + 5*x])/(211680*(2 + 3*x)^4)) + (47279*Sqrt[1 - 2*x]*Sqrt[3 + 5*x])/(1270080*(2 + 3*x)^3) + (1057139*Sqrt[1 - 2*x]*Sqrt[3 + 5*x])/(7112448*(2 + 3*x)^2) + (106751933*Sqrt[1 - 2*x]*Sqrt[3 + 5*x])/(99574272*(2 + 3*x)) - (59*Sqrt[1 - 2*x]*(3 + 5*x)^(3/2))/(1260*(2 + 3*x)^5) - (Sqrt[1 - 2*x]*(3 + 5*x)^(5/2))/(18*(2 + 3*x)^6) + (15036307*ArcTan[(Sqrt[7]*Sqrt[3 + 5*x])/Sqrt[1 - 2*x]])/(1229312*Sqrt[7])}
{(Sqrt[1 - 2*x]*(3 + 5*x)^(5/2))/(2 + 3*x)^8, x, 9, -((6577*Sqrt[1 - 2*x]*Sqrt[3 + 5*x])/(370440*(2 + 3*x)^5)) + (369409*Sqrt[1 - 2*x]*Sqrt[3 + 5*x])/(20744640*(2 + 3*x)^4) + (2524471*Sqrt[1 - 2*x]*Sqrt[3 + 5*x])/(41489280*(2 + 3*x)^3) + (84539611*Sqrt[1 - 2*x]*Sqrt[3 + 5*x])/(232339968*(2 + 3*x)^2) + (8818415317*Sqrt[1 - 2*x]*Sqrt[3 + 5*x])/(3252759552*(2 + 3*x)) - (59*Sqrt[1 - 2*x]*(3 + 5*x)^(3/2))/(1764*(2 + 3*x)^6) - (Sqrt[1 - 2*x]*(3 + 5*x)^(5/2))/(21*(2 + 3*x)^7) + (3735929329*ArcTan[(Sqrt[7]*Sqrt[3 + 5*x])/Sqrt[1 - 2*x]])/(120472576*Sqrt[7])}


(* ::Subsubsection::Closed:: *)
(*n<0*)


{(Sqrt[1 - 2*x]*(2 + 3*x)^3)/Sqrt[3 + 5*x], x, 5, (-46613*Sqrt[1 - 2*x]*Sqrt[3 + 5*x])/64000 - (7*Sqrt[1 - 2*x]*(2 + 3*x)^2*Sqrt[3 + 5*x])/400 + (Sqrt[1 - 2*x]*(2 + 3*x)^3*Sqrt[3 + 5*x])/20 - (21*Sqrt[1 - 2*x]*Sqrt[3 + 5*x]*(194 + 305*x))/16000 + (525371*ArcSin[Sqrt[2/11]*Sqrt[3 + 5*x]])/(64000*Sqrt[10])}
{(Sqrt[1 - 2*x]*(2 + 3*x)^2)/Sqrt[3 + 5*x], x, 4, (277/800)*Sqrt[1 - 2*x]*Sqrt[3 + 5*x] - (23/80)*(1 - 2*x)^(3/2)*Sqrt[3 + 5*x] - (1/10)*(1 - 2*x)^(3/2)*(2 + 3*x)*Sqrt[3 + 5*x] + (3047*ArcSin[Sqrt[2/11]*Sqrt[3 + 5*x]])/(800*Sqrt[10])}
{(Sqrt[1 - 2*x]*(2 + 3*x))/Sqrt[3 + 5*x], x, 3, (41*Sqrt[1 - 2*x]*Sqrt[3 + 5*x])/200 - (3*(1 - 2*x)^(3/2)*Sqrt[3 + 5*x])/20 + (451*ArcSin[Sqrt[2/11]*Sqrt[3 + 5*x]])/(200*Sqrt[10])}
{Sqrt[1 - 2*x]/Sqrt[3 + 5*x], x, 2, (Sqrt[1 - 2*x]*Sqrt[3 + 5*x])/5 + (11*ArcSin[Sqrt[2/11]*Sqrt[3 + 5*x]])/(5*Sqrt[10])}
{Sqrt[1 - 2*x]/((2 + 3*x)*Sqrt[3 + 5*x]), x, 3, (-2*Sqrt[2/5]*ArcSin[Sqrt[2/11]*Sqrt[3 + 5*x]])/3 + (2*Sqrt[7]*ArcTan[(Sqrt[7]*Sqrt[3 + 5*x])/Sqrt[1 - 2*x]])/3}
{Sqrt[1 - 2*x]/((2 + 3*x)^2*Sqrt[3 + 5*x]), x, 2, (Sqrt[1 - 2*x]*Sqrt[3 + 5*x])/(2 + 3*x) + (11*ArcTan[(Sqrt[7]*Sqrt[3 + 5*x])/Sqrt[1 - 2*x]])/Sqrt[7]}
{Sqrt[1 - 2*x]/((2 + 3*x)^3*Sqrt[3 + 5*x]), x, 4, (Sqrt[1 - 2*x]*Sqrt[3 + 5*x])/(2*(2 + 3*x)^2) + (103*Sqrt[1 - 2*x]*Sqrt[3 + 5*x])/(28*(2 + 3*x)) + (1177*ArcTan[(Sqrt[7]*Sqrt[3 + 5*x])/Sqrt[1 - 2*x]])/(28*Sqrt[7])}
{Sqrt[1 - 2*x]/((2 + 3*x)^4*Sqrt[3 + 5*x]), x, 5, (Sqrt[1 - 2*x]*Sqrt[3 + 5*x])/(3*(2 + 3*x)^3) + (173*Sqrt[1 - 2*x]*Sqrt[3 + 5*x])/(84*(2 + 3*x)^2) + (18083*Sqrt[1 - 2*x]*Sqrt[3 + 5*x])/(1176*(2 + 3*x)) + (68959*ArcTan[(Sqrt[7]*Sqrt[3 + 5*x])/Sqrt[1 - 2*x]])/(392*Sqrt[7])}
{Sqrt[1 - 2*x]/((2 + 3*x)^5*Sqrt[3 + 5*x]), x, 6, (Sqrt[1 - 2*x]*Sqrt[3 + 5*x])/(4*(2 + 3*x)^4) + (81*Sqrt[1 - 2*x]*Sqrt[3 + 5*x])/(56*(2 + 3*x)^3) + (14145*Sqrt[1 - 2*x]*Sqrt[3 + 5*x])/(1568*(2 + 3*x)^2) + (1479375*Sqrt[1 - 2*x]*Sqrt[3 + 5*x])/(21952*(2 + 3*x)) + (16925425*ArcTan[(Sqrt[7]*Sqrt[3 + 5*x])/Sqrt[1 - 2*x]])/(21952*Sqrt[7])}


{(Sqrt[1 - 2*x]*(2 + 3*x)^3)/(3 + 5*x)^(3/2), x, 5, (-2*Sqrt[1 - 2*x]*(2 + 3*x)^3)/(5*Sqrt[3 + 5*x]) - (791*Sqrt[1 - 2*x]*Sqrt[3 + 5*x])/4000 + (7*Sqrt[1 - 2*x]*(2 + 3*x)*Sqrt[3 + 5*x])/200 + (7*Sqrt[1 - 2*x]*(2 + 3*x)^2*Sqrt[3 + 5*x])/25 + (10409*ArcSin[Sqrt[2/11]*Sqrt[3 + 5*x]])/(4000*Sqrt[10])}
{(Sqrt[1 - 2*x]*(2 + 3*x)^2)/(3 + 5*x)^(3/2), x, 4, -((2*(1 - 2*x)^(3/2))/(275*Sqrt[3 + 5*x])) + (317*Sqrt[1 - 2*x]*Sqrt[3 + 5*x])/2200 - (9/100)*(1 - 2*x)^(3/2)*Sqrt[3 + 5*x] + (317*ArcSin[Sqrt[2/11]*Sqrt[3 + 5*x]])/(200*Sqrt[10])}
{(Sqrt[1 - 2*x]*(2 + 3*x))/(3 + 5*x)^(3/2), x, 3, (-2*(1 - 2*x)^(3/2))/(55*Sqrt[3 + 5*x]) + (29*Sqrt[1 - 2*x]*Sqrt[3 + 5*x])/275 + (29*ArcSin[Sqrt[2/11]*Sqrt[3 + 5*x]])/(25*Sqrt[10])}
{Sqrt[1 - 2*x]/(3 + 5*x)^(3/2), x, 2, (-2*Sqrt[1 - 2*x])/(5*Sqrt[3 + 5*x]) - (2*Sqrt[2/5]*ArcSin[Sqrt[2/11]*Sqrt[3 + 5*x]])/5}
{Sqrt[1 - 2*x]/((2 + 3*x)*(3 + 5*x)^(3/2)), x, 2, (-2*Sqrt[1 - 2*x])/Sqrt[3 + 5*x] - 2*Sqrt[7]*ArcTan[(Sqrt[7]*Sqrt[3 + 5*x])/Sqrt[1 - 2*x]]}
{Sqrt[1 - 2*x]/((2 + 3*x)^2*(3 + 5*x)^(3/2)), x, 4, (-15*Sqrt[1 - 2*x])/Sqrt[3 + 5*x] + Sqrt[1 - 2*x]/((2 + 3*x)*Sqrt[3 + 5*x]) - (103*ArcTan[(Sqrt[7]*Sqrt[3 + 5*x])/Sqrt[1 - 2*x]])/Sqrt[7]}
{Sqrt[1 - 2*x]/((2 + 3*x)^3*(3 + 5*x)^(3/2)), x, 5, (-2615*Sqrt[1 - 2*x])/(28*Sqrt[3 + 5*x]) + Sqrt[1 - 2*x]/(2*(2 + 3*x)^2*Sqrt[3 + 5*x]) + (173*Sqrt[1 - 2*x])/(28*(2 + 3*x)*Sqrt[3 + 5*x]) - (17951*ArcTan[(Sqrt[7]*Sqrt[3 + 5*x])/Sqrt[1 - 2*x]])/(28*Sqrt[7])}
{Sqrt[1 - 2*x]/((2 + 3*x)^4*(3 + 5*x)^(3/2)), x, 6, (-639565*Sqrt[1 - 2*x])/(1176*Sqrt[3 + 5*x]) + Sqrt[1 - 2*x]/(3*(2 + 3*x)^3*Sqrt[3 + 5*x]) + (81*Sqrt[1 - 2*x])/(28*(2 + 3*x)^2*Sqrt[3 + 5*x]) + (14101*Sqrt[1 - 2*x])/(392*(2 + 3*x)*Sqrt[3 + 5*x]) - (1463447*ArcTan[(Sqrt[7]*Sqrt[3 + 5*x])/Sqrt[1 - 2*x]])/(392*Sqrt[7])}


{(Sqrt[1 - 2*x]*(2 + 3*x)^4)/(3 + 5*x)^(5/2), x, 6, (-2*Sqrt[1 - 2*x]*(2 + 3*x)^4)/(15*(3 + 5*x)^(3/2)) - (524*Sqrt[1 - 2*x]*(2 + 3*x)^3)/(825*Sqrt[3 + 5*x]) - (23779*Sqrt[1 - 2*x]*Sqrt[3 + 5*x])/220000 + (1043*Sqrt[1 - 2*x]*(2 + 3*x)*Sqrt[3 + 5*x])/11000 + (623*Sqrt[1 - 2*x]*(2 + 3*x)^2*Sqrt[3 + 5*x])/1375 + (35511*ArcSin[Sqrt[2/11]*Sqrt[3 + 5*x]])/(20000*Sqrt[10])}
{(Sqrt[1 - 2*x]*(2 + 3*x)^3)/(3 + 5*x)^(5/2), x, 5, (-2*Sqrt[1 - 2*x]*(2 + 3*x)^3)/(15*(3 + 5*x)^(3/2)) - (392*Sqrt[1 - 2*x]*(2 + 3*x)^2)/(825*Sqrt[3 + 5*x]) + (11557*Sqrt[1 - 2*x]*Sqrt[3 + 5*x])/11000 - (21*(34 - 145*x)*Sqrt[1 - 2*x]*Sqrt[3 + 5*x])/2750 + (1071*ArcSin[Sqrt[2/11]*Sqrt[3 + 5*x]])/(1000*Sqrt[10])}
{(Sqrt[1 - 2*x]*(2 + 3*x)^2)/(3 + 5*x)^(5/2), x, 4, -((2*(1 - 2*x)^(3/2))/(825*(3 + 5*x)^(3/2))) - (12*(1 - 2*x)^(3/2))/(275*Sqrt[3 + 5*x]) + (3/55)*Sqrt[1 - 2*x]*Sqrt[3 + 5*x] + (3*ArcSin[Sqrt[2/11]*Sqrt[3 + 5*x]])/(5*Sqrt[10])}
{(Sqrt[1 - 2*x]*(2 + 3*x))/(3 + 5*x)^(5/2), x, 3, (-2*(1 - 2*x)^(3/2))/(165*(3 + 5*x)^(3/2)) - (6*Sqrt[1 - 2*x])/(25*Sqrt[3 + 5*x]) - (6*Sqrt[2/5]*ArcSin[Sqrt[2/11]*Sqrt[3 + 5*x]])/25}
{Sqrt[1 - 2*x]/(3 + 5*x)^(5/2), x, 1, (-2*(1 - 2*x)^(3/2))/(33*(3 + 5*x)^(3/2))}
{Sqrt[1 - 2*x]/((2 + 3*x)*(3 + 5*x)^(5/2)), x, 4, (-2*Sqrt[1 - 2*x])/(3*(3 + 5*x)^(3/2)) + (202*Sqrt[1 - 2*x])/(33*Sqrt[3 + 5*x]) + 6*Sqrt[7]*ArcTan[(Sqrt[7]*Sqrt[3 + 5*x])/Sqrt[1 - 2*x]]}
{Sqrt[1 - 2*x]/((2 + 3*x)^2*(3 + 5*x)^(5/2)), x, 5, (-25*Sqrt[1 - 2*x])/(3*(3 + 5*x)^(3/2)) + Sqrt[1 - 2*x]/((2 + 3*x)*(3 + 5*x)^(3/2)) + (2495*Sqrt[1 - 2*x])/(33*Sqrt[3 + 5*x]) + (519*ArcTan[(Sqrt[7]*Sqrt[3 + 5*x])/Sqrt[1 - 2*x]])/Sqrt[7]}
{Sqrt[1 - 2*x]/((2 + 3*x)^3*(3 + 5*x)^(5/2)), x, 6, (-6095*Sqrt[1 - 2*x])/(84*(3 + 5*x)^(3/2)) + Sqrt[1 - 2*x]/(2*(2 + 3*x)^2*(3 + 5*x)^(3/2)) + (243*Sqrt[1 - 2*x])/(28*(2 + 3*x)*(3 + 5*x)^(3/2)) + (608185*Sqrt[1 - 2*x])/(924*Sqrt[3 + 5*x]) + (126513*ArcTan[(Sqrt[7]*Sqrt[3 + 5*x])/Sqrt[1 - 2*x]])/(28*Sqrt[7])}
{Sqrt[1 - 2*x]/((2 + 3*x)^4*(3 + 5*x)^(5/2)), x, 7, (-638165*Sqrt[1 - 2*x])/(1176*(3 + 5*x)^(3/2)) + Sqrt[1 - 2*x]/(3*(2 + 3*x)^3*(3 + 5*x)^(3/2)) + (313*Sqrt[1 - 2*x])/(84*(2 + 3*x)^2*(3 + 5*x)^(3/2)) + (25441*Sqrt[1 - 2*x])/(392*(2 + 3*x)*(3 + 5*x)^(3/2)) + (63678595*Sqrt[1 - 2*x])/(12936*Sqrt[3 + 5*x]) + (13246251*ArcTan[(Sqrt[7]*Sqrt[3 + 5*x])/Sqrt[1 - 2*x]])/(392*Sqrt[7])}


(* ::Subsection::Closed:: *)
(*Integrands of the form (a+b x)^m (c+d x)^(n/2) (e+f x)^(3/2)*)


(* ::Subsubsection::Closed:: *)
(*n>0*)


{(1 - 2*x)^(3/2)*(2 + 3*x)^3*Sqrt[3 + 5*x], x, 7, (-41137943*Sqrt[1 - 2*x]*Sqrt[3 + 5*x])/25600000 - (3501533*Sqrt[1 - 2*x]*(3 + 5*x)^(3/2))/19200000 + (791*Sqrt[1 - 2*x]*(2 + 3*x)^2*(3 + 5*x)^(3/2))/120000 + (29*Sqrt[1 - 2*x]*(2 + 3*x)^3*(3 + 5*x)^(3/2))/1500 + ((1 - 2*x)^(3/2)*(2 + 3*x)^3*(3 + 5*x)^(3/2))/30 - (7*Sqrt[1 - 2*x]*(3 + 5*x)^(3/2)*(28458 + 41105*x))/2400000 + (452517373*ArcSin[Sqrt[2/11]*Sqrt[3 + 5*x]])/(25600000*Sqrt[10])}
{(1 - 2*x)^(3/2)*(2 + 3*x)^2*Sqrt[3 + 5*x], x, 6, (498883*Sqrt[1 - 2*x]*Sqrt[3 + 5*x])/640000 + (45353*(1 - 2*x)^(3/2)*Sqrt[3 + 5*x])/192000 - (4123*(1 - 2*x)^(5/2)*Sqrt[3 + 5*x])/9600 - (567*(1 - 2*x)^(5/2)*(3 + 5*x)^(3/2))/4000 - (3/50)*(1 - 2*x)^(5/2)*(2 + 3*x)*(3 + 5*x)^(3/2) + (5487713*ArcSin[Sqrt[2/11]*Sqrt[3 + 5*x]])/(640000*Sqrt[10])}
{(1 - 2*x)^(3/2)*(2 + 3*x)*Sqrt[3 + 5*x], x, 5, (2783*Sqrt[1 - 2*x]*Sqrt[3 + 5*x])/6400 + (253*(1 - 2*x)^(3/2)*Sqrt[3 + 5*x])/1920 - (23*(1 - 2*x)^(5/2)*Sqrt[3 + 5*x])/96 - (3*(1 - 2*x)^(5/2)*(3 + 5*x)^(3/2))/40 + (30613*ArcSin[Sqrt[2/11]*Sqrt[3 + 5*x]])/(6400*Sqrt[10])}
{(1 - 2*x)^(3/2)*Sqrt[3 + 5*x], x, 4, (121*Sqrt[1 - 2*x]*Sqrt[3 + 5*x])/400 + (11*(1 - 2*x)^(3/2)*Sqrt[3 + 5*x])/120 - ((1 - 2*x)^(5/2)*Sqrt[3 + 5*x])/6 + (1331*ArcSin[Sqrt[2/11]*Sqrt[3 + 5*x]])/(400*Sqrt[10])}
{((1 - 2*x)^(3/2)*Sqrt[3 + 5*x])/(2 + 3*x), x, 5, (107*Sqrt[1 - 2*x]*Sqrt[3 + 5*x])/180 + ((1 - 2*x)^(3/2)*Sqrt[3 + 5*x])/6 + (4091*ArcSin[Sqrt[2/11]*Sqrt[3 + 5*x]])/(540*Sqrt[10]) - (14*Sqrt[7]*ArcTan[(Sqrt[7]*Sqrt[3 + 5*x])/Sqrt[1 - 2*x]])/27}
{((1 - 2*x)^(3/2)*Sqrt[3 + 5*x])/(2 + 3*x)^2, x, 5, (-4*Sqrt[1 - 2*x]*Sqrt[3 + 5*x])/9 - ((1 - 2*x)^(3/2)*Sqrt[3 + 5*x])/(3*(2 + 3*x)) - (107*Sqrt[2/5]*ArcSin[Sqrt[2/11]*Sqrt[3 + 5*x]])/27 + (41*Sqrt[7]*ArcTan[(Sqrt[7]*Sqrt[3 + 5*x])/Sqrt[1 - 2*x]])/27}
{((1 - 2*x)^(3/2)*Sqrt[3 + 5*x])/(2 + 3*x)^3, x, 5, -((1 - 2*x)^(3/2)*Sqrt[3 + 5*x])/(6*(2 + 3*x)^2) + (41*Sqrt[1 - 2*x]*Sqrt[3 + 5*x])/(36*(2 + 3*x)) + (4*Sqrt[10]*ArcSin[Sqrt[2/11]*Sqrt[3 + 5*x]])/27 + (793*ArcTan[(Sqrt[7]*Sqrt[3 + 5*x])/Sqrt[1 - 2*x]])/(108*Sqrt[7])}
{((1 - 2*x)^(3/2)*Sqrt[3 + 5*x])/(2 + 3*x)^4, x, 4, (-121*Sqrt[1 - 2*x]*Sqrt[3 + 5*x])/(56*(2 + 3*x)) + ((1 - 2*x)^(3/2)*(3 + 5*x)^(3/2))/(3*(2 + 3*x)^3) + (11*Sqrt[1 - 2*x]*(3 + 5*x)^(3/2))/(4*(2 + 3*x)^2) + (1331*ArcTan[(Sqrt[7]*Sqrt[3 + 5*x])/Sqrt[1 - 2*x]])/(56*Sqrt[7])}
{((1 - 2*x)^(3/2)*Sqrt[3 + 5*x])/(2 + 3*x)^5, x, 6, -((1 - 2*x)^(3/2)*Sqrt[3 + 5*x])/(12*(2 + 3*x)^4) + (41*Sqrt[1 - 2*x]*Sqrt[3 + 5*x])/(216*(2 + 3*x)^3) + (5413*Sqrt[1 - 2*x]*Sqrt[3 + 5*x])/(6048*(2 + 3*x)^2) + (568363*Sqrt[1 - 2*x]*Sqrt[3 + 5*x])/(84672*(2 + 3*x)) + (240911*ArcTan[(Sqrt[7]*Sqrt[3 + 5*x])/Sqrt[1 - 2*x]])/(3136*Sqrt[7])}
{((1 - 2*x)^(3/2)*Sqrt[3 + 5*x])/(2 + 3*x)^6, x, 7, -(((1 - 2*x)^(3/2)*Sqrt[3 + 5*x])/(15*(2 + 3*x)^5)) + (41*Sqrt[1 - 2*x]*Sqrt[3 + 5*x])/(360*(2 + 3*x)^4) + (7723*Sqrt[1 - 2*x]*Sqrt[3 + 5*x])/(15120*(2 + 3*x)^3) + (270463*Sqrt[1 - 2*x]*Sqrt[3 + 5*x])/(84672*(2 + 3*x)^2) + (28291441*Sqrt[1 - 2*x]*Sqrt[3 + 5*x])/(1185408*(2 + 3*x)) + (11988317*ArcTan[(Sqrt[7]*Sqrt[3 + 5*x])/Sqrt[1 - 2*x]])/(43904*Sqrt[7])}


{(1 - 2*x)^(3/2)*(2 + 3*x)^3*(3 + 5*x)^(3/2), x, 8, (-565404807*Sqrt[1 - 2*x]*Sqrt[3 + 5*x])/102400000 - (17133479*Sqrt[1 - 2*x]*(3 + 5*x)^(3/2))/25600000 - (870407*Sqrt[1 - 2*x]*(3 + 5*x)^(5/2))/9600000 + (51*Sqrt[1 - 2*x]*(2 + 3*x)^2*(3 + 5*x)^(5/2))/10000 + (29*Sqrt[1 - 2*x]*(2 + 3*x)^3*(3 + 5*x)^(5/2))/2100 + ((1 - 2*x)^(3/2)*(2 + 3*x)^3*(3 + 5*x)^(5/2))/35 - (Sqrt[1 - 2*x]*(3 + 5*x)^(5/2)*(35878 + 51675*x))/800000 + (6219452877*ArcSin[Sqrt[2/11]*Sqrt[3 + 5*x]])/(102400000*Sqrt[10])}
{(1 - 2*x)^(3/2)*(2 + 3*x)^2*(3 + 5*x)^(3/2), x, 7, (12382293*Sqrt[1 - 2*x]*Sqrt[3 + 5*x])/5120000 + (375221*(1 - 2*x)^(3/2)*Sqrt[3 + 5*x])/512000 - (34111*(1 - 2*x)^(5/2)*Sqrt[3 + 5*x])/25600 - (3101*(1 - 2*x)^(5/2)*(3 + 5*x)^(3/2))/6400 - (259*(1 - 2*x)^(5/2)*(3 + 5*x)^(5/2))/2000 - (1/20)*(1 - 2*x)^(5/2)*(2 + 3*x)*(3 + 5*x)^(5/2) + (136205223*ArcSin[Sqrt[2/11]*Sqrt[3 + 5*x]])/(5120000*Sqrt[10])}
{(1 - 2*x)^(3/2)*(2 + 3*x)*(3 + 5*x)^(3/2), x, 6, (147741*Sqrt[1 - 2*x]*Sqrt[3 + 5*x])/128000 + (4477*(1 - 2*x)^(3/2)*Sqrt[3 + 5*x])/12800 - (407*(1 - 2*x)^(5/2)*Sqrt[3 + 5*x])/640 - (37*(1 - 2*x)^(5/2)*(3 + 5*x)^(3/2))/160 - (3*(1 - 2*x)^(5/2)*(3 + 5*x)^(5/2))/50 + (1625151*ArcSin[Sqrt[2/11]*Sqrt[3 + 5*x]])/(128000*Sqrt[10])}
{(1 - 2*x)^(3/2)*(3 + 5*x)^(3/2), x, 5, (3993*Sqrt[1 - 2*x]*Sqrt[3 + 5*x])/6400 + (121*(1 - 2*x)^(3/2)*Sqrt[3 + 5*x])/640 - (11*(1 - 2*x)^(5/2)*Sqrt[3 + 5*x])/32 - ((1 - 2*x)^(5/2)*(3 + 5*x)^(3/2))/8 + (43923*ArcSin[Sqrt[2/11]*Sqrt[3 + 5*x]])/(6400*Sqrt[10])}
{((1 - 2*x)^(3/2)*(3 + 5*x)^(3/2))/(2 + 3*x), x, 6, (-1781*Sqrt[1 - 2*x]*Sqrt[3 + 5*x])/2160 + (37*Sqrt[1 - 2*x]*(3 + 5*x)^(3/2))/180 + ((1 - 2*x)^(3/2)*(3 + 5*x)^(3/2))/9 + (19573*ArcSin[Sqrt[2/11]*Sqrt[3 + 5*x]])/(6480*Sqrt[10]) + (14*Sqrt[7]*ArcTan[(Sqrt[7]*Sqrt[3 + 5*x])/Sqrt[1 - 2*x]])/81}
{((1 - 2*x)^(3/2)*(3 + 5*x)^(3/2))/(2 + 3*x)^2, x, 6, (107*Sqrt[1 - 2*x]*Sqrt[3 + 5*x])/36 - (Sqrt[1 - 2*x]*(3 + 5*x)^(3/2))/3 - ((1 - 2*x)^(3/2)*(3 + 5*x)^(3/2))/(3*(2 + 3*x)) + (1649*ArcSin[Sqrt[2/11]*Sqrt[3 + 5*x]])/(108*Sqrt[10]) - (37*Sqrt[7]*ArcTan[(Sqrt[7]*Sqrt[3 + 5*x])/Sqrt[1 - 2*x]])/27}
{((1 - 2*x)^(3/2)*(3 + 5*x)^(3/2))/(2 + 3*x)^3, x, 6, (-205*Sqrt[1 - 2*x]*Sqrt[3 + 5*x])/36 - ((1 - 2*x)^(3/2)*(3 + 5*x)^(3/2))/(6*(2 + 3*x)^2) + (37*Sqrt[1 - 2*x]*(3 + 5*x)^(3/2))/(12*(2 + 3*x)) - (37*Sqrt[10]*ArcSin[Sqrt[2/11]*Sqrt[3 + 5*x]])/27 + (1649*ArcTan[(Sqrt[7]*Sqrt[3 + 5*x])/Sqrt[1 - 2*x]])/(108*Sqrt[7])}
{((1 - 2*x)^(3/2)*(3 + 5*x)^(3/2))/(2 + 3*x)^4, x, 6, (-661*Sqrt[1 - 2*x]*Sqrt[3 + 5*x])/(1512*(2 + 3*x)) - ((1 - 2*x)^(3/2)*(3 + 5*x)^(3/2))/(9*(2 + 3*x)^3) + (37*Sqrt[1 - 2*x]*(3 + 5*x)^(3/2))/(36*(2 + 3*x)^2) + (20*Sqrt[10]*ArcSin[Sqrt[2/11]*Sqrt[3 + 5*x]])/81 + (19573*ArcTan[(Sqrt[7]*Sqrt[3 + 5*x])/Sqrt[1 - 2*x]])/(4536*Sqrt[7])}
{((1 - 2*x)^(3/2)*(3 + 5*x)^(3/2))/(2 + 3*x)^5, x, 5, (-3993*Sqrt[1 - 2*x]*Sqrt[3 + 5*x])/(3136*(2 + 3*x)) - (121*Sqrt[1 - 2*x]*(3 + 5*x)^(3/2))/(224*(2 + 3*x)^2) + ((1 - 2*x)^(3/2)*(3 + 5*x)^(5/2))/(4*(2 + 3*x)^4) + (11*Sqrt[1 - 2*x]*(3 + 5*x)^(5/2))/(8*(2 + 3*x)^3) + (43923*ArcTan[(Sqrt[7]*Sqrt[3 + 5*x])/Sqrt[1 - 2*x]])/(3136*Sqrt[7])}
{((1 - 2*x)^(3/2)*(3 + 5*x)^(3/2))/(2 + 3*x)^6, x, 7, -((5281*Sqrt[1 - 2*x]*Sqrt[3 + 5*x])/(15120*(2 + 3*x)^3)) + (36149*Sqrt[1 - 2*x]*Sqrt[3 + 5*x])/(84672*(2 + 3*x)^2) + (3831323*Sqrt[1 - 2*x]*Sqrt[3 + 5*x])/(1185408*(2 + 3*x)) - ((1 - 2*x)^(3/2)*(3 + 5*x)^(3/2))/(15*(2 + 3*x)^5) + (37*Sqrt[1 - 2*x]*(3 + 5*x)^(3/2))/(120*(2 + 3*x)^4) + (1625151*ArcTan[(Sqrt[7]*Sqrt[3 + 5*x])/Sqrt[1 - 2*x]])/(43904*Sqrt[7])}
{((1 - 2*x)^(3/2)*(3 + 5*x)^(3/2))/(2 + 3*x)^7, x, 8, -((7591*Sqrt[1 - 2*x]*Sqrt[3 + 5*x])/(30240*(2 + 3*x)^4)) + (37333*Sqrt[1 - 2*x]*Sqrt[3 + 5*x])/(181440*(2 + 3*x)^3) + (1316353*Sqrt[1 - 2*x]*Sqrt[3 + 5*x])/(1016064*(2 + 3*x)^2) + (137752591*Sqrt[1 - 2*x]*Sqrt[3 + 5*x])/(14224896*(2 + 3*x)) - ((1 - 2*x)^(3/2)*(3 + 5*x)^(3/2))/(18*(2 + 3*x)^6) + (37*Sqrt[1 - 2*x]*(3 + 5*x)^(3/2))/(180*(2 + 3*x)^5) + (19457889*ArcTan[(Sqrt[7]*Sqrt[3 + 5*x])/Sqrt[1 - 2*x]])/(175616*Sqrt[7])}
{((1 - 2*x)^(3/2)*(3 + 5*x)^(3/2))/(2 + 3*x)^8, x, 9, -((9901*Sqrt[1 - 2*x]*Sqrt[3 + 5*x])/(52920*(2 + 3*x)^5)) + (341917*Sqrt[1 - 2*x]*Sqrt[3 + 5*x])/(2963520*(2 + 3*x)^4) + (4014523*Sqrt[1 - 2*x]*Sqrt[3 + 5*x])/(5927040*(2 + 3*x)^3) + (140331343*Sqrt[1 - 2*x]*Sqrt[3 + 5*x])/(33191424*(2 + 3*x)^2) + (14677525921*Sqrt[1 - 2*x]*Sqrt[3 + 5*x])/(464679936*(2 + 3*x)) - ((1 - 2*x)^(3/2)*(3 + 5*x)^(3/2))/(21*(2 + 3*x)^7) + (37*Sqrt[1 - 2*x]*(3 + 5*x)^(3/2))/(252*(2 + 3*x)^6) + (6219452877*ArcTan[(Sqrt[7]*Sqrt[3 + 5*x])/Sqrt[1 - 2*x]])/(17210368*Sqrt[7])}


{(1 - 2*x)^(3/2)*(2 + 3*x)^3*(3 + 5*x)^(5/2), x, 9, (-13441711767*Sqrt[1 - 2*x]*Sqrt[3 + 5*x])/655360000 - (407324599*Sqrt[1 - 2*x]*(3 + 5*x)^(3/2))/163840000 - (37029509*Sqrt[1 - 2*x]*(3 + 5*x)^(5/2))/102400000 - (803549*Sqrt[1 - 2*x]*(3 + 5*x)^(7/2))/15360000 + (193*Sqrt[1 - 2*x]*(2 + 3*x)^2*(3 + 5*x)^(7/2))/48000 + (29*Sqrt[1 - 2*x]*(2 + 3*x)^3*(3 + 5*x)^(7/2))/2800 + ((1 - 2*x)^(3/2)*(2 + 3*x)^3*(3 + 5*x)^(7/2))/40 - (Sqrt[1 - 2*x]*(3 + 5*x)^(7/2)*(43298 + 62245*x))/1600000 + (147858829437*ArcSin[Sqrt[2/11]*Sqrt[3 + 5*x]])/(655360000*Sqrt[10])}
{(1 - 2*x)^(3/2)*(2 + 3*x)^2*(3 + 5*x)^(5/2), x, 8, (34391709*Sqrt[1 - 2*x]*Sqrt[3 + 5*x])/4096000 + (1042173*(1 - 2*x)^(3/2)*Sqrt[3 + 5*x])/409600 - (94743*(1 - 2*x)^(5/2)*Sqrt[3 + 5*x])/20480 - (8613*(1 - 2*x)^(5/2)*(3 + 5*x)^(3/2))/5120 - (783*(1 - 2*x)^(5/2)*(3 + 5*x)^(5/2))/1600 - (47/400)*(1 - 2*x)^(5/2)*(3 + 5*x)^(7/2) - (3/70)*(1 - 2*x)^(5/2)*(2 + 3*x)*(3 + 5*x)^(7/2) + (378308799*ArcSin[Sqrt[2/11]*Sqrt[3 + 5*x]])/(4096000*Sqrt[10])}
{(1 - 2*x)^(3/2)*(2 + 3*x)*(3 + 5*x)^(5/2), x, 7, (746691*Sqrt[1 - 2*x]*Sqrt[3 + 5*x])/204800 + (22627*(1 - 2*x)^(3/2)*Sqrt[3 + 5*x])/20480 - (2057*(1 - 2*x)^(5/2)*Sqrt[3 + 5*x])/1024 - (187*(1 - 2*x)^(5/2)*(3 + 5*x)^(3/2))/256 - (17*(1 - 2*x)^(5/2)*(3 + 5*x)^(5/2))/80 - ((1 - 2*x)^(5/2)*(3 + 5*x)^(7/2))/20 + (8213601*ArcSin[Sqrt[2/11]*Sqrt[3 + 5*x]])/(204800*Sqrt[10])}
{(1 - 2*x)^(3/2)*(3 + 5*x)^(5/2), x, 6, (43923*Sqrt[1 - 2*x]*Sqrt[3 + 5*x])/25600 + (1331*(1 - 2*x)^(3/2)*Sqrt[3 + 5*x])/2560 - (121*(1 - 2*x)^(5/2)*Sqrt[3 + 5*x])/128 - (11*(1 - 2*x)^(5/2)*(3 + 5*x)^(3/2))/32 - ((1 - 2*x)^(5/2)*(3 + 5*x)^(5/2))/10 + (483153*ArcSin[Sqrt[2/11]*Sqrt[3 + 5*x]])/(25600*Sqrt[10])}
{((1 - 2*x)^(3/2)*(3 + 5*x)^(5/2))/(2 + 3*x), x, 7, (-15863*Sqrt[1 - 2*x]*Sqrt[3 + 5*x])/20736 - (53*Sqrt[1 - 2*x]*(3 + 5*x)^(3/2))/192 + (23*Sqrt[1 - 2*x]*(3 + 5*x)^(5/2))/216 + ((1 - 2*x)^(3/2)*(3 + 5*x)^(5/2))/12 + (648919*ArcSin[Sqrt[2/11]*Sqrt[3 + 5*x]])/(62208*Sqrt[10]) - (14*Sqrt[7]*ArcTan[(Sqrt[7]*Sqrt[3 + 5*x])/Sqrt[1 - 2*x]])/243}
{((1 - 2*x)^(3/2)*(3 + 5*x)^(5/2))/(2 + 3*x)^2, x, 7, (-3065*Sqrt[1 - 2*x]*Sqrt[3 + 5*x])/1296 + (25*Sqrt[1 - 2*x]*(3 + 5*x)^(3/2))/12 - (8*Sqrt[1 - 2*x]*(3 + 5*x)^(5/2))/27 - ((1 - 2*x)^(3/2)*(3 + 5*x)^(5/2))/(3*(2 + 3*x)) - (43*Sqrt[5/2]*ArcSin[Sqrt[2/11]*Sqrt[3 + 5*x]])/3888 + (181*Sqrt[7]*ArcTan[(Sqrt[7]*Sqrt[3 + 5*x])/Sqrt[1 - 2*x]])/243}
{((1 - 2*x)^(3/2)*(3 + 5*x)^(5/2))/(2 + 3*x)^3, x, 7, (185*Sqrt[1 - 2*x]*Sqrt[3 + 5*x])/27 - (35*Sqrt[1 - 2*x]*(3 + 5*x)^(3/2))/4 - ((1 - 2*x)^(3/2)*(3 + 5*x)^(5/2))/(6*(2 + 3*x)^2) + (181*Sqrt[1 - 2*x]*(3 + 5*x)^(5/2))/(36*(2 + 3*x)) + (1945*Sqrt[5/2]*ArcSin[Sqrt[2/11]*Sqrt[3 + 5*x]])/324 - (6829*ArcTan[(Sqrt[7]*Sqrt[3 + 5*x])/Sqrt[1 - 2*x]])/(324*Sqrt[7])}
{((1 - 2*x)^(3/2)*(3 + 5*x)^(5/2))/(2 + 3*x)^4, x, 7, (-39745*Sqrt[1 - 2*x]*Sqrt[3 + 5*x])/4536 + (331*Sqrt[1 - 2*x]*(3 + 5*x)^(3/2))/(168*(2 + 3*x)) - ((1 - 2*x)^(3/2)*(3 + 5*x)^(5/2))/(9*(2 + 3*x)^3) + (181*Sqrt[1 - 2*x]*(3 + 5*x)^(5/2))/(108*(2 + 3*x)^2) - (575*Sqrt[10]*ArcSin[Sqrt[2/11]*Sqrt[3 + 5*x]])/243 + (326717*ArcTan[(Sqrt[7]*Sqrt[3 + 5*x])/Sqrt[1 - 2*x]])/(13608*Sqrt[7])}
{((1 - 2*x)^(3/2)*(3 + 5*x)^(5/2))/(2 + 3*x)^5, x, 7, (-77269*Sqrt[1 - 2*x]*Sqrt[3 + 5*x])/(254016*(2 + 3*x)) - (871*Sqrt[1 - 2*x]*(3 + 5*x)^(3/2))/(6048*(2 + 3*x)^2) - ((1 - 2*x)^(3/2)*(3 + 5*x)^(5/2))/(12*(2 + 3*x)^4) + (181*Sqrt[1 - 2*x]*(3 + 5*x)^(5/2))/(216*(2 + 3*x)^3) + (100*Sqrt[10]*ArcSin[Sqrt[2/11]*Sqrt[3 + 5*x]])/243 + (1922677*ArcTan[(Sqrt[7]*Sqrt[3 + 5*x])/Sqrt[1 - 2*x]])/(762048*Sqrt[7])}
{((1 - 2*x)^(3/2)*(3 + 5*x)^(5/2))/(2 + 3*x)^6, x, 6, -((43923*Sqrt[1 - 2*x]*Sqrt[3 + 5*x])/(43904*(2 + 3*x))) - (1331*Sqrt[1 - 2*x]*(3 + 5*x)^(3/2))/(3136*(2 + 3*x)^2) - (121*Sqrt[1 - 2*x]*(3 + 5*x)^(5/2))/(560*(2 + 3*x)^3) + ((1 - 2*x)^(3/2)*(3 + 5*x)^(7/2))/(5*(2 + 3*x)^5) + (33*Sqrt[1 - 2*x]*(3 + 5*x)^(7/2))/(40*(2 + 3*x)^4) + (483153*ArcTan[(Sqrt[7]*Sqrt[3 + 5*x])/Sqrt[1 - 2*x]])/(43904*Sqrt[7])}
{((1 - 2*x)^(3/2)*(3 + 5*x)^(5/2))/(2 + 3*x)^7, x, 8, -((126463*Sqrt[1 - 2*x]*Sqrt[3 + 5*x])/(544320*(2 + 3*x)^3)) + (852587*Sqrt[1 - 2*x]*Sqrt[3 + 5*x])/(3048192*(2 + 3*x)^2) + (92126789*Sqrt[1 - 2*x]*Sqrt[3 + 5*x])/(42674688*(2 + 3*x)) - (2857*Sqrt[1 - 2*x]*(3 + 5*x)^(3/2))/(10080*(2 + 3*x)^4) - ((1 - 2*x)^(3/2)*(3 + 5*x)^(5/2))/(18*(2 + 3*x)^6) + (181*Sqrt[1 - 2*x]*(3 + 5*x)^(5/2))/(540*(2 + 3*x)^5) + (4348377*ArcTan[(Sqrt[7]*Sqrt[3 + 5*x])/Sqrt[1 - 2*x]])/(175616*Sqrt[7])}
{((1 - 2*x)^(3/2)*(3 + 5*x)^(5/2))/(2 + 3*x)^8, x, 9, -((1289227*Sqrt[1 - 2*x]*Sqrt[3 + 5*x])/(8890560*(2 + 3*x)^4)) + (6249601*Sqrt[1 - 2*x]*Sqrt[3 + 5*x])/(53343360*(2 + 3*x)^3) + (224018941*Sqrt[1 - 2*x]*Sqrt[3 + 5*x])/(298722816*(2 + 3*x)^2) + (23466191827*Sqrt[1 - 2*x]*Sqrt[3 + 5*x])/(4182119424*(2 + 3*x)) - (12421*Sqrt[1 - 2*x]*(3 + 5*x)^(3/2))/(52920*(2 + 3*x)^5) - ((1 - 2*x)^(3/2)*(3 + 5*x)^(5/2))/(21*(2 + 3*x)^7) + (181*Sqrt[1 - 2*x]*(3 + 5*x)^(5/2))/(756*(2 + 3*x)^6) + (1104970911*ArcTan[(Sqrt[7]*Sqrt[3 + 5*x])/Sqrt[1 - 2*x]])/(17210368*Sqrt[7])}


(* ::Subsubsection::Closed:: *)
(*n<0*)


{((1 - 2*x)^(3/2)*(2 + 3*x)^3)/Sqrt[3 + 5*x], x, 6, (-4802371*Sqrt[1 - 2*x]*Sqrt[3 + 5*x])/9600000 + (511*Sqrt[1 - 2*x]*(2 + 3*x)^2*Sqrt[3 + 5*x])/60000 + (29*Sqrt[1 - 2*x]*(2 + 3*x)^3*Sqrt[3 + 5*x])/1000 + ((1 - 2*x)^(3/2)*(2 + 3*x)^3*Sqrt[3 + 5*x])/25 - (7*Sqrt[1 - 2*x]*Sqrt[3 + 5*x]*(21038 + 30535*x))/800000 + (18648399*ArcSin[Sqrt[2/11]*Sqrt[3 + 5*x]])/(3200000*Sqrt[10])}
{((1 - 2*x)^(3/2)*(2 + 3*x)^2)/Sqrt[3 + 5*x], x, 5, (9933*Sqrt[1 - 2*x]*Sqrt[3 + 5*x])/32000 + (301*(1 - 2*x)^(3/2)*Sqrt[3 + 5*x])/3200 - (119/800)*(1 - 2*x)^(5/2)*Sqrt[3 + 5*x] - (3/40)*(1 - 2*x)^(5/2)*(2 + 3*x)*Sqrt[3 + 5*x] + (109263*ArcSin[Sqrt[2/11]*Sqrt[3 + 5*x]])/(32000*Sqrt[10])}
{((1 - 2*x)^(3/2)*(2 + 3*x))/Sqrt[3 + 5*x], x, 4, (99*Sqrt[1 - 2*x]*Sqrt[3 + 5*x])/400 + (3*(1 - 2*x)^(3/2)*Sqrt[3 + 5*x])/40 - ((1 - 2*x)^(5/2)*Sqrt[3 + 5*x])/10 + (1089*ArcSin[Sqrt[2/11]*Sqrt[3 + 5*x]])/(400*Sqrt[10])}
{(1 - 2*x)^(3/2)/Sqrt[3 + 5*x], x, 3, (33*Sqrt[1 - 2*x]*Sqrt[3 + 5*x])/100 + ((1 - 2*x)^(3/2)*Sqrt[3 + 5*x])/10 + (363*ArcSin[Sqrt[2/11]*Sqrt[3 + 5*x]])/(100*Sqrt[10])}
{(1 - 2*x)^(3/2)/((2 + 3*x)*Sqrt[3 + 5*x]), x, 4, (-2*Sqrt[1 - 2*x]*Sqrt[3 + 5*x])/15 - (103*Sqrt[2/5]*ArcSin[Sqrt[2/11]*Sqrt[3 + 5*x]])/45 + (14*Sqrt[7]*ArcTan[(Sqrt[7]*Sqrt[3 + 5*x])/Sqrt[1 - 2*x]])/9}
{(1 - 2*x)^(3/2)/((2 + 3*x)^2*Sqrt[3 + 5*x]), x, 5, (2*Sqrt[1 - 2*x]*Sqrt[3 + 5*x])/3 + ((1 - 2*x)^(3/2)*Sqrt[3 + 5*x])/(2 + 3*x) + (4*Sqrt[2/5]*ArcSin[Sqrt[2/11]*Sqrt[3 + 5*x]])/9 + (29*Sqrt[7]*ArcTan[(Sqrt[7]*Sqrt[3 + 5*x])/Sqrt[1 - 2*x]])/9}
{(1 - 2*x)^(3/2)/((2 + 3*x)^3*Sqrt[3 + 5*x]), x, 3, ((1 - 2*x)^(3/2)*Sqrt[3 + 5*x])/(2*(2 + 3*x)^2) + (33*Sqrt[1 - 2*x]*Sqrt[3 + 5*x])/(4*(2 + 3*x)) + (363*ArcTan[(Sqrt[7]*Sqrt[3 + 5*x])/Sqrt[1 - 2*x]])/(4*Sqrt[7])}
{(1 - 2*x)^(3/2)/((2 + 3*x)^4*Sqrt[3 + 5*x]), x, 5, ((1 - 2*x)^(3/2)*Sqrt[3 + 5*x])/(3*(2 + 3*x)^3) + (169*Sqrt[1 - 2*x]*Sqrt[3 + 5*x])/(36*(2 + 3*x)^2) + (16847*Sqrt[1 - 2*x]*Sqrt[3 + 5*x])/(504*(2 + 3*x)) + (21417*ArcTan[(Sqrt[7]*Sqrt[3 + 5*x])/Sqrt[1 - 2*x]])/(56*Sqrt[7])}
{(1 - 2*x)^(3/2)/((2 + 3*x)^5*Sqrt[3 + 5*x]), x, 6, ((1 - 2*x)^(3/2)*Sqrt[3 + 5*x])/(4*(2 + 3*x)^4) + (239*Sqrt[1 - 2*x]*Sqrt[3 + 5*x])/(72*(2 + 3*x)^3) + (39667*Sqrt[1 - 2*x]*Sqrt[3 + 5*x])/(2016*(2 + 3*x)^2) + (4148797*Sqrt[1 - 2*x]*Sqrt[3 + 5*x])/(28224*(2 + 3*x)) + (5274027*ArcTan[(Sqrt[7]*Sqrt[3 + 5*x])/Sqrt[1 - 2*x]])/(3136*Sqrt[7])}
{(1 - 2*x)^(3/2)/((2 + 3*x)^6*Sqrt[3 + 5*x]), x, 7, ((1 - 2*x)^(3/2)*Sqrt[3 + 5*x])/(5*(2 + 3*x)^5) + (103*Sqrt[1 - 2*x]*Sqrt[3 + 5*x])/(40*(2 + 3*x)^4) + (23909*Sqrt[1 - 2*x]*Sqrt[3 + 5*x])/(1680*(2 + 3*x)^3) + (835409*Sqrt[1 - 2*x]*Sqrt[3 + 5*x])/(9408*(2 + 3*x)^2) + (87374783*Sqrt[1 - 2*x]*Sqrt[3 + 5*x])/(131712*(2 + 3*x)) + (333216939*ArcTan[(Sqrt[7]*Sqrt[3 + 5*x])/Sqrt[1 - 2*x]])/(43904*Sqrt[7])}


{((1 - 2*x)^(3/2)*(2 + 3*x)^3)/(3 + 5*x)^(3/2), x, 6, (-2*(1 - 2*x)^(3/2)*(2 + 3*x)^3)/(5*Sqrt[3 + 5*x]) - (23779*Sqrt[1 - 2*x]*Sqrt[3 + 5*x])/160000 + (1043*Sqrt[1 - 2*x]*(2 + 3*x)*Sqrt[3 + 5*x])/8000 + (623*Sqrt[1 - 2*x]*(2 + 3*x)^2*Sqrt[3 + 5*x])/1000 - (9*Sqrt[1 - 2*x]*(2 + 3*x)^3*Sqrt[3 + 5*x])/50 + (390621*ArcSin[Sqrt[2/11]*Sqrt[3 + 5*x]])/(160000*Sqrt[10])}
{((1 - 2*x)^(3/2)*(2 + 3*x)^2)/(3 + 5*x)^(3/2), x, 5, -((2*(1 - 2*x)^(5/2))/(275*Sqrt[3 + 5*x])) + (357*Sqrt[1 - 2*x]*Sqrt[3 + 5*x])/2000 + (119*(1 - 2*x)^(3/2)*Sqrt[3 + 5*x])/2200 - (3/50)*(1 - 2*x)^(5/2)*Sqrt[3 + 5*x] + (3927*ArcSin[Sqrt[2/11]*Sqrt[3 + 5*x]])/(2000*Sqrt[10])}
{((1 - 2*x)^(3/2)*(2 + 3*x))/(3 + 5*x)^(3/2), x, 4, (-2*(1 - 2*x)^(5/2))/(55*Sqrt[3 + 5*x]) + (3*Sqrt[1 - 2*x]*Sqrt[3 + 5*x])/20 + ((1 - 2*x)^(3/2)*Sqrt[3 + 5*x])/22 + (33*ArcSin[Sqrt[2/11]*Sqrt[3 + 5*x]])/(20*Sqrt[10])}
{(1 - 2*x)^(3/2)/(3 + 5*x)^(3/2), x, 3, (-2*(1 - 2*x)^(3/2))/(5*Sqrt[3 + 5*x]) - (6*Sqrt[1 - 2*x]*Sqrt[3 + 5*x])/25 - (33*Sqrt[2/5]*ArcSin[Sqrt[2/11]*Sqrt[3 + 5*x]])/25}
{(1 - 2*x)^(3/2)/((2 + 3*x)*(3 + 5*x)^(3/2)), x, 5, (-2*(1 - 2*x)^(3/2))/Sqrt[3 + 5*x] - (4*Sqrt[1 - 2*x]*Sqrt[3 + 5*x])/5 + (4*Sqrt[2/5]*ArcSin[Sqrt[2/11]*Sqrt[3 + 5*x]])/15 - (14*Sqrt[7]*ArcTan[(Sqrt[7]*Sqrt[3 + 5*x])/Sqrt[1 - 2*x]])/3}
{(1 - 2*x)^(3/2)/((2 + 3*x)^2*(3 + 5*x)^(3/2)), x, 3, (-33*Sqrt[1 - 2*x])/Sqrt[3 + 5*x] + (1 - 2*x)^(3/2)/((2 + 3*x)*Sqrt[3 + 5*x]) - 33*Sqrt[7]*ArcTan[(Sqrt[7]*Sqrt[3 + 5*x])/Sqrt[1 - 2*x]]}
{(1 - 2*x)^(3/2)/((2 + 3*x)^3*(3 + 5*x)^(3/2)), x, 5, (-2495*Sqrt[1 - 2*x])/(12*Sqrt[3 + 5*x]) + (1 - 2*x)^(3/2)/(2*(2 + 3*x)^2*Sqrt[3 + 5*x]) + (169*Sqrt[1 - 2*x])/(12*(2 + 3*x)*Sqrt[3 + 5*x]) - (5709*ArcTan[(Sqrt[7]*Sqrt[3 + 5*x])/Sqrt[1 - 2*x]])/(4*Sqrt[7])}
{(1 - 2*x)^(3/2)/((2 + 3*x)^4*(3 + 5*x)^(3/2)), x, 6, (-608185*Sqrt[1 - 2*x])/(504*Sqrt[3 + 5*x]) + (1 - 2*x)^(3/2)/(3*(2 + 3*x)^3*Sqrt[3 + 5*x]) + (239*Sqrt[1 - 2*x])/(36*(2 + 3*x)^2*Sqrt[3 + 5*x]) + (13409*Sqrt[1 - 2*x])/(168*(2 + 3*x)*Sqrt[3 + 5*x]) - (463881*ArcTan[(Sqrt[7]*Sqrt[3 + 5*x])/Sqrt[1 - 2*x]])/(56*Sqrt[7])}
{(1 - 2*x)^(3/2)/((2 + 3*x)^5*(3 + 5*x)^(3/2)), x, 7, (-63678595*Sqrt[1 - 2*x])/(9408*Sqrt[3 + 5*x]) + (1 - 2*x)^(3/2)/(4*(2 + 3*x)^4*Sqrt[3 + 5*x]) + (103*Sqrt[1 - 2*x])/(24*(2 + 3*x)^3*Sqrt[3 + 5*x]) + (8063*Sqrt[1 - 2*x])/(224*(2 + 3*x)^2*Sqrt[3 + 5*x]) + (1403963*Sqrt[1 - 2*x])/(3136*(2 + 3*x)*Sqrt[3 + 5*x]) - (145708761*ArcTan[(Sqrt[7]*Sqrt[3 + 5*x])/Sqrt[1 - 2*x]])/(3136*Sqrt[7])}


{((1 - 2*x)^(3/2)*(2 + 3*x)^3)/(3 + 5*x)^(5/2), x, 6, (-2*(1 - 2*x)^(3/2)*(2 + 3*x)^3)/(15*(3 + 5*x)^(3/2)) - (128*Sqrt[1 - 2*x]*(2 + 3*x)^3)/(25*Sqrt[3 + 5*x]) + (1953*Sqrt[1 - 2*x]*Sqrt[3 + 5*x])/10000 + (399*Sqrt[1 - 2*x]*(2 + 3*x)*Sqrt[3 + 5*x])/500 + (378*Sqrt[1 - 2*x]*(2 + 3*x)^2*Sqrt[3 + 5*x])/125 + (13153*ArcSin[Sqrt[2/11]*Sqrt[3 + 5*x]])/(10000*Sqrt[10])}
{((1 - 2*x)^(3/2)*(2 + 3*x)^2)/(3 + 5*x)^(5/2), x, 5, -((2*(1 - 2*x)^(5/2))/(825*(3 + 5*x)^(3/2))) - (388*(1 - 2*x)^(5/2))/(9075*Sqrt[3 + 5*x]) + (343*Sqrt[1 - 2*x]*Sqrt[3 + 5*x])/5500 + (343*(1 - 2*x)^(3/2)*Sqrt[3 + 5*x])/18150 + (343*ArcSin[Sqrt[2/11]*Sqrt[3 + 5*x]])/(500*Sqrt[10])}
{((1 - 2*x)^(3/2)*(2 + 3*x))/(3 + 5*x)^(5/2), x, 4, (-2*(1 - 2*x)^(5/2))/(165*(3 + 5*x)^(3/2)) - (38*(1 - 2*x)^(3/2))/(165*Sqrt[3 + 5*x]) - (38*Sqrt[1 - 2*x]*Sqrt[3 + 5*x])/275 - (19*Sqrt[2/5]*ArcSin[Sqrt[2/11]*Sqrt[3 + 5*x]])/25}
{(1 - 2*x)^(3/2)/(3 + 5*x)^(5/2), x, 3, (-2*(1 - 2*x)^(3/2))/(15*(3 + 5*x)^(3/2)) + (4*Sqrt[1 - 2*x])/(25*Sqrt[3 + 5*x]) + (4*Sqrt[2/5]*ArcSin[Sqrt[2/11]*Sqrt[3 + 5*x]])/25}
{(1 - 2*x)^(3/2)/((2 + 3*x)*(3 + 5*x)^(5/2)), x, 3, (-2*(1 - 2*x)^(3/2))/(3*(3 + 5*x)^(3/2)) + (14*Sqrt[1 - 2*x])/Sqrt[3 + 5*x] + 14*Sqrt[7]*ArcTan[(Sqrt[7]*Sqrt[3 + 5*x])/Sqrt[1 - 2*x]]}
{(1 - 2*x)^(3/2)/((2 + 3*x)^2*(3 + 5*x)^(5/2)), x, 5, (-55*Sqrt[1 - 2*x])/(3*(3 + 5*x)^(3/2)) + (1 - 2*x)^(3/2)/((2 + 3*x)*(3 + 5*x)^(3/2)) + (517*Sqrt[1 - 2*x])/(3*Sqrt[3 + 5*x]) + 169*Sqrt[7]*ArcTan[(Sqrt[7]*Sqrt[3 + 5*x])/Sqrt[1 - 2*x]]}
{(1 - 2*x)^(3/2)/((2 + 3*x)^3*(3 + 5*x)^(5/2)), x, 6, (-655*Sqrt[1 - 2*x])/(4*(3 + 5*x)^(3/2)) + (1 - 2*x)^(3/2)/(2*(2 + 3*x)^2*(3 + 5*x)^(3/2)) + (239*Sqrt[1 - 2*x])/(12*(2 + 3*x)*(3 + 5*x)^(3/2)) + (17825*Sqrt[1 - 2*x])/(12*Sqrt[3 + 5*x]) + (40787*ArcTan[(Sqrt[7]*Sqrt[3 + 5*x])/Sqrt[1 - 2*x]])/(4*Sqrt[7])}
{(1 - 2*x)^(3/2)/((2 + 3*x)^4*(3 + 5*x)^(5/2)), x, 7, (-204595*Sqrt[1 - 2*x])/(168*(3 + 5*x)^(3/2)) + (1 - 2*x)^(3/2)/(3*(2 + 3*x)^3*(3 + 5*x)^(3/2)) + (103*Sqrt[1 - 2*x])/(12*(2 + 3*x)^2*(3 + 5*x)^(3/2)) + (24469*Sqrt[1 - 2*x])/(168*(2 + 3*x)*(3 + 5*x)^(3/2)) + (618645*Sqrt[1 - 2*x])/(56*Sqrt[3 + 5*x]) + (4246733*ArcTan[(Sqrt[7]*Sqrt[3 + 5*x])/Sqrt[1 - 2*x]])/(56*Sqrt[7])}


(* ::Subsection::Closed:: *)
(*Integrands of the form (a+b x)^m (c+d x)^(n/2) (e+f x)^(5/2)*)


(* ::Subsubsection::Closed:: *)
(*n>0*)


{(1 - 2*x)^(5/2)*(2 + 3*x)^3*Sqrt[3 + 5*x], x, 8, (-339629939*Sqrt[1 - 2*x]*Sqrt[3 + 5*x])/256000000 - (26653009*Sqrt[1 - 2*x]*(3 + 5*x)^(3/2))/192000000 + (35443*Sqrt[1 - 2*x]*(2 + 3*x)^2*(3 + 5*x)^(3/2))/1200000 + (919*Sqrt[1 - 2*x]*(2 + 3*x)^3*(3 + 5*x)^(3/2))/105000 + (17*(1 - 2*x)^(3/2)*(2 + 3*x)^3*(3 + 5*x)^(3/2))/700 + ((1 - 2*x)^(5/2)*(2 + 3*x)^3*(3 + 5*x)^(3/2))/35 - (Sqrt[1 - 2*x]*(3 + 5*x)^(3/2)*(1730238 + 2099155*x))/24000000 + (3735929329*ArcSin[Sqrt[2/11]*Sqrt[3 + 5*x]])/(256000000*Sqrt[10])}
{(1 - 2*x)^(5/2)*(2 + 3*x)^2*Sqrt[3 + 5*x], x, 7, (9568559*Sqrt[1 - 2*x]*Sqrt[3 + 5*x])/12800000 + (869869*(1 - 2*x)^(3/2)*Sqrt[3 + 5*x])/3840000 + (79079*(1 - 2*x)^(5/2)*Sqrt[3 + 5*x])/960000 - (7189*(1 - 2*x)^(7/2)*Sqrt[3 + 5*x])/32000 - (193*(1 - 2*x)^(7/2)*(3 + 5*x)^(3/2))/2000 - (1/20)*(1 - 2*x)^(7/2)*(2 + 3*x)*(3 + 5*x)^(3/2) + (105254149*ArcSin[Sqrt[2/11]*Sqrt[3 + 5*x]])/(12800000*Sqrt[10])}
{(1 - 2*x)^(5/2)*(2 + 3*x)*Sqrt[3 + 5*x], x, 6, (158389*Sqrt[1 - 2*x]*Sqrt[3 + 5*x])/320000 + (14399*(1 - 2*x)^(3/2)*Sqrt[3 + 5*x])/96000 + (1309*(1 - 2*x)^(5/2)*Sqrt[3 + 5*x])/24000 - (119*(1 - 2*x)^(7/2)*Sqrt[3 + 5*x])/800 - (3*(1 - 2*x)^(7/2)*(3 + 5*x)^(3/2))/50 + (1742279*ArcSin[Sqrt[2/11]*Sqrt[3 + 5*x]])/(320000*Sqrt[10])}
{(1 - 2*x)^(5/2)*Sqrt[3 + 5*x], x, 5, (1331*Sqrt[1 - 2*x]*Sqrt[3 + 5*x])/3200 + (121*(1 - 2*x)^(3/2)*Sqrt[3 + 5*x])/960 + (11*(1 - 2*x)^(5/2)*Sqrt[3 + 5*x])/240 - ((1 - 2*x)^(7/2)*Sqrt[3 + 5*x])/8 + (14641*ArcSin[Sqrt[2/11]*Sqrt[3 + 5*x]])/(3200*Sqrt[10])}
{((1 - 2*x)^(5/2)*Sqrt[3 + 5*x])/(2 + 3*x), x, 6, (6401*Sqrt[1 - 2*x]*Sqrt[3 + 5*x])/5400 + (59*(1 - 2*x)^(3/2)*Sqrt[3 + 5*x])/180 + ((1 - 2*x)^(5/2)*Sqrt[3 + 5*x])/9 + (250433*ArcSin[Sqrt[2/11]*Sqrt[3 + 5*x]])/(16200*Sqrt[10]) - (98*Sqrt[7]*ArcTan[(Sqrt[7]*Sqrt[3 + 5*x])/Sqrt[1 - 2*x]])/81}
{((1 - 2*x)^(5/2)*Sqrt[3 + 5*x])/(2 + 3*x)^2, x, 6, (-43*Sqrt[1 - 2*x]*Sqrt[3 + 5*x])/30 - ((1 - 2*x)^(3/2)*Sqrt[3 + 5*x])/3 - ((1 - 2*x)^(5/2)*Sqrt[3 + 5*x])/(3*(2 + 3*x)) - (2119*ArcSin[Sqrt[2/11]*Sqrt[3 + 5*x]])/(90*Sqrt[10]) + (35*Sqrt[7]*ArcTan[(Sqrt[7]*Sqrt[3 + 5*x])/Sqrt[1 - 2*x]])/9}
{((1 - 2*x)^(5/2)*Sqrt[3 + 5*x])/(2 + 3*x)^3, x, 6, (19*Sqrt[1 - 2*x]*Sqrt[3 + 5*x])/18 - ((1 - 2*x)^(5/2)*Sqrt[3 + 5*x])/(6*(2 + 3*x)^2) + (5*(1 - 2*x)^(3/2)*Sqrt[3 + 5*x])/(4*(2 + 3*x)) + (118*Sqrt[2/5]*ArcSin[Sqrt[2/11]*Sqrt[3 + 5*x]])/27 + (155*Sqrt[7]*ArcTan[(Sqrt[7]*Sqrt[3 + 5*x])/Sqrt[1 - 2*x]])/108}
{((1 - 2*x)^(5/2)*Sqrt[3 + 5*x])/(2 + 3*x)^4, x, 6, -((1 - 2*x)^(5/2)*Sqrt[3 + 5*x])/(9*(2 + 3*x)^3) + (5*(1 - 2*x)^(3/2)*Sqrt[3 + 5*x])/(12*(2 + 3*x)^2) + (925*Sqrt[1 - 2*x]*Sqrt[3 + 5*x])/(216*(2 + 3*x)) - (8*Sqrt[10]*ArcSin[Sqrt[2/11]*Sqrt[3 + 5*x]])/81 + (32765*ArcTan[(Sqrt[7]*Sqrt[3 + 5*x])/Sqrt[1 - 2*x]])/(648*Sqrt[7])}
{((1 - 2*x)^(5/2)*Sqrt[3 + 5*x])/(2 + 3*x)^5, x, 5, (-6655*Sqrt[1 - 2*x]*Sqrt[3 + 5*x])/(448*(2 + 3*x)) + ((1 - 2*x)^(5/2)*(3 + 5*x)^(3/2))/(4*(2 + 3*x)^4) + (55*(1 - 2*x)^(3/2)*(3 + 5*x)^(3/2))/(24*(2 + 3*x)^3) + (605*Sqrt[1 - 2*x]*(3 + 5*x)^(3/2))/(32*(2 + 3*x)^2) + (73205*ArcTan[(Sqrt[7]*Sqrt[3 + 5*x])/Sqrt[1 - 2*x]])/(448*Sqrt[7])}
{((1 - 2*x)^(5/2)*Sqrt[3 + 5*x])/(2 + 3*x)^6, x, 7, -(((1 - 2*x)^(5/2)*Sqrt[3 + 5*x])/(15*(2 + 3*x)^5)) + ((1 - 2*x)^(3/2)*Sqrt[3 + 5*x])/(8*(2 + 3*x)^4) + (493*Sqrt[1 - 2*x]*Sqrt[3 + 5*x])/(432*(2 + 3*x)^3) + (82937*Sqrt[1 - 2*x]*Sqrt[3 + 5*x])/(12096*(2 + 3*x)^2) + (8672663*Sqrt[1 - 2*x]*Sqrt[3 + 5*x])/(169344*(2 + 3*x)) + (3674891*ArcTan[(Sqrt[7]*Sqrt[3 + 5*x])/Sqrt[1 - 2*x]])/(6272*Sqrt[7])}
{((1 - 2*x)^(5/2)*Sqrt[3 + 5*x])/(2 + 3*x)^7, x, 8, -(((1 - 2*x)^(5/2)*Sqrt[3 + 5*x])/(18*(2 + 3*x)^6)) + ((1 - 2*x)^(3/2)*Sqrt[3 + 5*x])/(12*(2 + 3*x)^5) + (647*Sqrt[1 - 2*x]*Sqrt[3 + 5*x])/(864*(2 + 3*x)^4) + (151621*Sqrt[1 - 2*x]*Sqrt[3 + 5*x])/(36288*(2 + 3*x)^3) + (26486645*Sqrt[1 - 2*x]*Sqrt[3 + 5*x])/(1016064*(2 + 3*x)^2) + (2770202075*Sqrt[1 - 2*x]*Sqrt[3 + 5*x])/(14224896*(2 + 3*x)) + (391280725*ArcTan[(Sqrt[7]*Sqrt[3 + 5*x])/Sqrt[1 - 2*x]])/(175616*Sqrt[7])}


{(1 - 2*x)^(5/2)*(2 + 3*x)^3*(3 + 5*x)^(3/2), x, 9, (-32302687197*Sqrt[1 - 2*x]*Sqrt[3 + 5*x])/8192000000 - (978869309*Sqrt[1 - 2*x]*(3 + 5*x)^(3/2))/2048000000 - (135322391*Sqrt[1 - 2*x]*(3 + 5*x)^(5/2))/2304000000 + (16321*Sqrt[1 - 2*x]*(2 + 3*x)^2*(3 + 5*x)^(5/2))/800000 + (2477*Sqrt[1 - 2*x]*(2 + 3*x)^3*(3 + 5*x)^(5/2))/504000 + (51*(1 - 2*x)^(3/2)*(2 + 3*x)^3*(3 + 5*x)^(5/2))/2800 + ((1 - 2*x)^(5/2)*(2 + 3*x)^3*(3 + 5*x)^(5/2))/40 - (Sqrt[1 - 2*x]*(3 + 5*x)^(5/2)*(6543814 + 7759275*x))/192000000 + (355329559167*ArcSin[Sqrt[2/11]*Sqrt[3 + 5*x]])/(8192000000*Sqrt[10])}
{(1 - 2*x)^(5/2)*(2 + 3*x)^2*(3 + 5*x)^(3/2), x, 8, (100451901*Sqrt[1 - 2*x]*Sqrt[3 + 5*x])/51200000 + (3043997*(1 - 2*x)^(3/2)*Sqrt[3 + 5*x])/5120000 + (276727*(1 - 2*x)^(5/2)*Sqrt[3 + 5*x])/1280000 - (75471*(1 - 2*x)^(7/2)*Sqrt[3 + 5*x])/128000 - (2287*(1 - 2*x)^(7/2)*(3 + 5*x)^(3/2))/8000 - (263*(1 - 2*x)^(7/2)*(3 + 5*x)^(5/2))/2800 - (3/70)*(1 - 2*x)^(7/2)*(2 + 3*x)*(3 + 5*x)^(5/2) + (1104970911*ArcSin[Sqrt[2/11]*Sqrt[3 + 5*x]])/(51200000*Sqrt[10])}
{(1 - 2*x)^(5/2)*(2 + 3*x)*(3 + 5*x)^(3/2), x, 7, (2767149*Sqrt[1 - 2*x]*Sqrt[3 + 5*x])/2560000 + (83853*(1 - 2*x)^(3/2)*Sqrt[3 + 5*x])/256000 + (7623*(1 - 2*x)^(5/2)*Sqrt[3 + 5*x])/64000 - (2079*(1 - 2*x)^(7/2)*Sqrt[3 + 5*x])/6400 - (63*(1 - 2*x)^(7/2)*(3 + 5*x)^(3/2))/400 - ((1 - 2*x)^(7/2)*(3 + 5*x)^(5/2))/20 + (30438639*ArcSin[Sqrt[2/11]*Sqrt[3 + 5*x]])/(2560000*Sqrt[10])}
{(1 - 2*x)^(5/2)*(3 + 5*x)^(3/2), x, 6, (43923*Sqrt[1 - 2*x]*Sqrt[3 + 5*x])/64000 + (1331*(1 - 2*x)^(3/2)*Sqrt[3 + 5*x])/6400 + (121*(1 - 2*x)^(5/2)*Sqrt[3 + 5*x])/1600 - (33*(1 - 2*x)^(7/2)*Sqrt[3 + 5*x])/160 - ((1 - 2*x)^(7/2)*(3 + 5*x)^(3/2))/10 + (483153*ArcSin[Sqrt[2/11]*Sqrt[3 + 5*x]])/(64000*Sqrt[10])}
{((1 - 2*x)^(5/2)*(3 + 5*x)^(3/2))/(2 + 3*x), x, 7, (-390869*Sqrt[1 - 2*x]*Sqrt[3 + 5*x])/259200 + (7093*Sqrt[1 - 2*x]*(3 + 5*x)^(3/2))/21600 + (181*(1 - 2*x)^(3/2)*(3 + 5*x)^(3/2))/1080 + ((1 - 2*x)^(5/2)*(3 + 5*x)^(3/2))/12 + (1922677*ArcSin[Sqrt[2/11]*Sqrt[3 + 5*x]])/(777600*Sqrt[10]) + (98*Sqrt[7]*ArcTan[(Sqrt[7]*Sqrt[3 + 5*x])/Sqrt[1 - 2*x]])/243}
{((1 - 2*x)^(5/2)*(3 + 5*x)^(3/2))/(2 + 3*x)^2, x, 7, (24251*Sqrt[1 - 2*x]*Sqrt[3 + 5*x])/3240 - (247*Sqrt[1 - 2*x]*(3 + 5*x)^(3/2))/270 - (8*(1 - 2*x)^(3/2)*(3 + 5*x)^(3/2))/27 - ((1 - 2*x)^(5/2)*(3 + 5*x)^(3/2))/(3*(2 + 3*x)) + (326717*ArcSin[Sqrt[2/11]*Sqrt[3 + 5*x]])/(9720*Sqrt[10]) - (805*Sqrt[7]*ArcTan[(Sqrt[7]*Sqrt[3 + 5*x])/Sqrt[1 - 2*x]])/243}
{((1 - 2*x)^(5/2)*(3 + 5*x)^(3/2))/(2 + 3*x)^3, x, 7, (-1649*Sqrt[1 - 2*x]*Sqrt[3 + 5*x])/108 + (41*Sqrt[1 - 2*x]*(3 + 5*x)^(3/2))/18 - ((1 - 2*x)^(5/2)*(3 + 5*x)^(3/2))/(6*(2 + 3*x)^2) + (115*(1 - 2*x)^(3/2)*(3 + 5*x)^(3/2))/(36*(2 + 3*x)) - (6829*ArcSin[Sqrt[2/11]*Sqrt[3 + 5*x]])/(162*Sqrt[10]) + (1945*Sqrt[7]*ArcTan[(Sqrt[7]*Sqrt[3 + 5*x])/Sqrt[1 - 2*x]])/324}
{((1 - 2*x)^(5/2)*(3 + 5*x)^(3/2))/(2 + 3*x)^4, x, 7, (-845*Sqrt[1 - 2*x]*Sqrt[3 + 5*x])/648 - ((1 - 2*x)^(5/2)*(3 + 5*x)^(3/2))/(9*(2 + 3*x)^3) + (115*(1 - 2*x)^(3/2)*(3 + 5*x)^(3/2))/(108*(2 + 3*x)^2) + (365*Sqrt[1 - 2*x]*(3 + 5*x)^(3/2))/(216*(2 + 3*x)) + (362*Sqrt[10]*ArcSin[Sqrt[2/11]*Sqrt[3 + 5*x]])/243 - (215*ArcTan[(Sqrt[7]*Sqrt[3 + 5*x])/Sqrt[1 - 2*x]])/(1944*Sqrt[7])}
{((1 - 2*x)^(5/2)*(3 + 5*x)^(3/2))/(2 + 3*x)^5, x, 7, (-97235*Sqrt[1 - 2*x]*Sqrt[3 + 5*x])/(36288*(2 + 3*x)) - ((1 - 2*x)^(5/2)*(3 + 5*x)^(3/2))/(12*(2 + 3*x)^4) + (115*(1 - 2*x)^(3/2)*(3 + 5*x)^(3/2))/(216*(2 + 3*x)^3) + (2675*Sqrt[1 - 2*x]*(3 + 5*x)^(3/2))/(864*(2 + 3*x)^2) - (40*Sqrt[10]*ArcSin[Sqrt[2/11]*Sqrt[3 + 5*x]])/243 + (3244595*ArcTan[(Sqrt[7]*Sqrt[3 + 5*x])/Sqrt[1 - 2*x]])/(108864*Sqrt[7])}
{((1 - 2*x)^(5/2)*(3 + 5*x)^(3/2))/(2 + 3*x)^6, x, 6, -((43923*Sqrt[1 - 2*x]*Sqrt[3 + 5*x])/(6272*(2 + 3*x))) - (1331*Sqrt[1 - 2*x]*(3 + 5*x)^(3/2))/(448*(2 + 3*x)^2) + ((1 - 2*x)^(5/2)*(3 + 5*x)^(5/2))/(5*(2 + 3*x)^5) + (11*(1 - 2*x)^(3/2)*(3 + 5*x)^(5/2))/(8*(2 + 3*x)^4) + (121*Sqrt[1 - 2*x]*(3 + 5*x)^(5/2))/(16*(2 + 3*x)^3) + (483153*ArcTan[(Sqrt[7]*Sqrt[3 + 5*x])/Sqrt[1 - 2*x]])/(6272*Sqrt[7])}
{((1 - 2*x)^(5/2)*(3 + 5*x)^(3/2))/(2 + 3*x)^7, x, 8, -((241207*Sqrt[1 - 2*x]*Sqrt[3 + 5*x])/(108864*(2 + 3*x)^3)) + (8346895*Sqrt[1 - 2*x]*Sqrt[3 + 5*x])/(3048192*(2 + 3*x)^2) + (872316385*Sqrt[1 - 2*x]*Sqrt[3 + 5*x])/(42674688*(2 + 3*x)) - ((1 - 2*x)^(5/2)*(3 + 5*x)^(3/2))/(18*(2 + 3*x)^6) + (23*(1 - 2*x)^(3/2)*(3 + 5*x)^(3/2))/(108*(2 + 3*x)^5) + (1459*Sqrt[1 - 2*x]*(3 + 5*x)^(3/2))/(864*(2 + 3*x)^4) + (41068005*ArcTan[(Sqrt[7]*Sqrt[3 + 5*x])/Sqrt[1 - 2*x]])/(175616*Sqrt[7])}
{((1 - 2*x)^(5/2)*(3 + 5*x)^(3/2))/(2 + 3*x)^8, x, 9, -((443563*Sqrt[1 - 2*x]*Sqrt[3 + 5*x])/(254016*(2 + 3*x)^4)) + (2199649*Sqrt[1 - 2*x]*Sqrt[3 + 5*x])/(1524096*(2 + 3*x)^3) + (384136145*Sqrt[1 - 2*x]*Sqrt[3 + 5*x])/(42674688*(2 + 3*x)^2) + (40175505215*Sqrt[1 - 2*x]*Sqrt[3 + 5*x])/(597445632*(2 + 3*x)) - ((1 - 2*x)^(5/2)*(3 + 5*x)^(3/2))/(21*(2 + 3*x)^7) + (115*(1 - 2*x)^(3/2)*(3 + 5*x)^(3/2))/(756*(2 + 3*x)^6) + (1921*Sqrt[1 - 2*x]*(3 + 5*x)^(3/2))/(1512*(2 + 3*x)^5) + (1891543995*ArcTan[(Sqrt[7]*Sqrt[3 + 5*x])/Sqrt[1 - 2*x]])/(2458624*Sqrt[7])}


{(1 - 2*x)^(5/2)*(2 + 3*x)^3*(3 + 5*x)^(5/2), x, 10, (-84729414253*Sqrt[1 - 2*x]*Sqrt[3 + 5*x])/6553600000 - (7702674023*Sqrt[1 - 2*x]*(3 + 5*x)^(3/2))/4915200000 - (700243093*Sqrt[1 - 2*x]*(3 + 5*x)^(5/2))/3072000000 - (122147797*Sqrt[1 - 2*x]*(3 + 5*x)^(7/2))/4147200000 + (193049*Sqrt[1 - 2*x]*(2 + 3*x)^2*(3 + 5*x)^(7/2))/12960000 + (2197*Sqrt[1 - 2*x]*(2 + 3*x)^3*(3 + 5*x)^(7/2))/756000 + (17*(1 - 2*x)^(3/2)*(2 + 3*x)^3*(3 + 5*x)^(7/2))/1200 + ((1 - 2*x)^(5/2)*(2 + 3*x)^3*(3 + 5*x)^(7/2))/45 - (Sqrt[1 - 2*x]*(3 + 5*x)^(7/2)*(7919314 + 9176285*x))/432000000 + (932023556783*ArcSin[Sqrt[2/11]*Sqrt[3 + 5*x]])/(6553600000*Sqrt[10])}
{(1 - 2*x)^(5/2)*(2 + 3*x)^2*(3 + 5*x)^(5/2), x, 9, (1939215091*Sqrt[1 - 2*x]*Sqrt[3 + 5*x])/327680000 + (176292281*(1 - 2*x)^(3/2)*Sqrt[3 + 5*x])/98304000 + (16026571*(1 - 2*x)^(5/2)*Sqrt[3 + 5*x])/24576000 - (1456961*(1 - 2*x)^(7/2)*Sqrt[3 + 5*x])/819200 - (132451*(1 - 2*x)^(7/2)*(3 + 5*x)^(3/2))/153600 - (12041*(1 - 2*x)^(7/2)*(3 + 5*x)^(5/2))/38400 - (999*(1 - 2*x)^(7/2)*(3 + 5*x)^(7/2))/11200 - (3/80)*(1 - 2*x)^(7/2)*(2 + 3*x)*(3 + 5*x)^(7/2) + (21331366001*ArcSin[Sqrt[2/11]*Sqrt[3 + 5*x]])/(327680000*Sqrt[10])}
{(1 - 2*x)^(5/2)*(2 + 3*x)*(3 + 5*x)^(5/2), x, 8, (5958887*Sqrt[1 - 2*x]*Sqrt[3 + 5*x])/2048000 + (541717*(1 - 2*x)^(3/2)*Sqrt[3 + 5*x])/614400 + (49247*(1 - 2*x)^(5/2)*Sqrt[3 + 5*x])/153600 - (4477*(1 - 2*x)^(7/2)*Sqrt[3 + 5*x])/5120 - (407*(1 - 2*x)^(7/2)*(3 + 5*x)^(3/2))/960 - (37*(1 - 2*x)^(7/2)*(3 + 5*x)^(5/2))/240 - (3*(1 - 2*x)^(7/2)*(3 + 5*x)^(7/2))/70 + (65547757*ArcSin[Sqrt[2/11]*Sqrt[3 + 5*x]])/(2048000*Sqrt[10])}
{(1 - 2*x)^(5/2)*(3 + 5*x)^(5/2), x, 7, (161051*Sqrt[1 - 2*x]*Sqrt[3 + 5*x])/102400 + (14641*(1 - 2*x)^(3/2)*Sqrt[3 + 5*x])/30720 + (1331*(1 - 2*x)^(5/2)*Sqrt[3 + 5*x])/7680 - (121*(1 - 2*x)^(7/2)*Sqrt[3 + 5*x])/256 - (11*(1 - 2*x)^(7/2)*(3 + 5*x)^(3/2))/48 - ((1 - 2*x)^(7/2)*(3 + 5*x)^(5/2))/12 + (1771561*ArcSin[Sqrt[2/11]*Sqrt[3 + 5*x]])/(102400*Sqrt[10])}
{((1 - 2*x)^(5/2)*(3 + 5*x)^(5/2))/(2 + 3*x), x, 8, (-1994287*Sqrt[1 - 2*x]*Sqrt[3 + 5*x])/3110400 - (14557*Sqrt[1 - 2*x]*(3 + 5*x)^(3/2))/28800 + (4783*Sqrt[1 - 2*x]*(3 + 5*x)^(5/2))/32400 + (37*(1 - 2*x)^(3/2)*(3 + 5*x)^(5/2))/360 + ((1 - 2*x)^(5/2)*(3 + 5*x)^(5/2))/15 + (109715471*ArcSin[Sqrt[2/11]*Sqrt[3 + 5*x]])/(9331200*Sqrt[10]) - (98*Sqrt[7]*ArcTan[(Sqrt[7]*Sqrt[3 + 5*x])/Sqrt[1 - 2*x]])/729}
{((1 - 2*x)^(5/2)*(3 + 5*x)^(5/2))/(2 + 3*x)^2, x, 8, (-155777*Sqrt[1 - 2*x]*Sqrt[3 + 5*x])/31104 + (1453*Sqrt[1 - 2*x]*(3 + 5*x)^(3/2))/288 - (247*Sqrt[1 - 2*x]*(3 + 5*x)^(5/2))/324 - (5*(1 - 2*x)^(3/2)*(3 + 5*x)^(5/2))/18 - ((1 - 2*x)^(5/2)*(3 + 5*x)^(5/2))/(3*(2 + 3*x)) - (660959*ArcSin[Sqrt[2/11]*Sqrt[3 + 5*x]])/(93312*Sqrt[10]) + (1295*Sqrt[7]*ArcTan[(Sqrt[7]*Sqrt[3 + 5*x])/Sqrt[1 - 2*x]])/729}
{((1 - 2*x)^(5/2)*(3 + 5*x)^(5/2))/(2 + 3*x)^3, x, 8, (34145*Sqrt[1 - 2*x]*Sqrt[3 + 5*x])/1944 - (785*Sqrt[1 - 2*x]*(3 + 5*x)^(3/2))/36 + (575*Sqrt[1 - 2*x]*(3 + 5*x)^(5/2))/162 - ((1 - 2*x)^(5/2)*(3 + 5*x)^(5/2))/(6*(2 + 3*x)^2) + (185*(1 - 2*x)^(3/2)*(3 + 5*x)^(5/2))/(36*(2 + 3*x)) + (81733*Sqrt[5/2]*ArcSin[Sqrt[2/11]*Sqrt[3 + 5*x]])/5832 - (21935*Sqrt[7]*ArcTan[(Sqrt[7]*Sqrt[3 + 5*x])/Sqrt[1 - 2*x]])/2916}
{((1 - 2*x)^(5/2)*(3 + 5*x)^(5/2))/(2 + 3*x)^4, x, 8, (-48625*Sqrt[1 - 2*x]*Sqrt[3 + 5*x])/1944 + (2075*Sqrt[1 - 2*x]*(3 + 5*x)^(3/2))/72 - ((1 - 2*x)^(5/2)*(3 + 5*x)^(5/2))/(9*(2 + 3*x)^3) + (185*(1 - 2*x)^(3/2)*(3 + 5*x)^(5/2))/(108*(2 + 3*x)^2) - (10385*Sqrt[1 - 2*x]*(3 + 5*x)^(5/2))/(648*(2 + 3*x)) - (21935*Sqrt[5/2]*ArcSin[Sqrt[2/11]*Sqrt[3 + 5*x]])/1458 + (408665*ArcTan[(Sqrt[7]*Sqrt[3 + 5*x])/Sqrt[1 - 2*x]])/(5832*Sqrt[7])}
{((1 - 2*x)^(5/2)*(3 + 5*x)^(5/2))/(2 + 3*x)^5, x, 8, (249575*Sqrt[1 - 2*x]*Sqrt[3 + 5*x])/108864 - (3485*Sqrt[1 - 2*x]*(3 + 5*x)^(3/2))/(4032*(2 + 3*x)) - ((1 - 2*x)^(5/2)*(3 + 5*x)^(5/2))/(12*(2 + 3*x)^4) + (185*(1 - 2*x)^(3/2)*(3 + 5*x)^(5/2))/(216*(2 + 3*x)^3) + (1165*Sqrt[1 - 2*x]*(3 + 5*x)^(5/2))/(2592*(2 + 3*x)^2) + (1850*Sqrt[10]*ArcSin[Sqrt[2/11]*Sqrt[3 + 5*x]])/729 - (3304795*ArcTan[(Sqrt[7]*Sqrt[3 + 5*x])/Sqrt[1 - 2*x]])/(326592*Sqrt[7])}
{((1 - 2*x)^(5/2)*(3 + 5*x)^(5/2))/(2 + 3*x)^6, x, 8, -((3248687*Sqrt[1 - 2*x]*Sqrt[3 + 5*x])/(1524096*(2 + 3*x))) - (32453*Sqrt[1 - 2*x]*(3 + 5*x)^(3/2))/(36288*(2 + 3*x)^2) - ((1 - 2*x)^(5/2)*(3 + 5*x)^(5/2))/(15*(2 + 3*x)^5) + (37*(1 - 2*x)^(3/2)*(3 + 5*x)^(5/2))/(72*(2 + 3*x)^4) + (2543*Sqrt[1 - 2*x]*(3 + 5*x)^(5/2))/(1296*(2 + 3*x)^3) - (200/729)*Sqrt[10]*ArcSin[Sqrt[2/11]*Sqrt[3 + 5*x]] + (109715471*ArcTan[(Sqrt[7]*Sqrt[3 + 5*x])/Sqrt[1 - 2*x]])/(4572288*Sqrt[7])}
{((1 - 2*x)^(5/2)*(3 + 5*x)^(5/2))/(2 + 3*x)^7, x, 7, -((805255*Sqrt[1 - 2*x]*Sqrt[3 + 5*x])/(175616*(2 + 3*x))) - (73205*Sqrt[1 - 2*x]*(3 + 5*x)^(3/2))/(37632*(2 + 3*x)^2) - (1331*Sqrt[1 - 2*x]*(3 + 5*x)^(5/2))/(1344*(2 + 3*x)^3) + ((1 - 2*x)^(5/2)*(3 + 5*x)^(7/2))/(6*(2 + 3*x)^6) + (11*(1 - 2*x)^(3/2)*(3 + 5*x)^(7/2))/(12*(2 + 3*x)^5) + (121*Sqrt[1 - 2*x]*(3 + 5*x)^(7/2))/(32*(2 + 3*x)^4) + (8857805*ArcTan[(Sqrt[7]*Sqrt[3 + 5*x])/Sqrt[1 - 2*x]])/(175616*Sqrt[7])}
{((1 - 2*x)^(5/2)*(3 + 5*x)^(5/2))/(2 + 3*x)^8, x, 9, -((5777249*Sqrt[1 - 2*x]*Sqrt[3 + 5*x])/(4572288*(2 + 3*x)^3)) + (200146505*Sqrt[1 - 2*x]*Sqrt[3 + 5*x])/(128024064*(2 + 3*x)^2) + (20886641735*Sqrt[1 - 2*x]*Sqrt[3 + 5*x])/(1792336896*(2 + 3*x)) - (129911*Sqrt[1 - 2*x]*(3 + 5*x)^(3/2))/(84672*(2 + 3*x)^4) - ((1 - 2*x)^(5/2)*(3 + 5*x)^(5/2))/(21*(2 + 3*x)^7) + (185*(1 - 2*x)^(3/2)*(3 + 5*x)^(5/2))/(756*(2 + 3*x)^6) + (7163*Sqrt[1 - 2*x]*(3 + 5*x)^(5/2))/(4536*(2 + 3*x)^5) + (327738785*ArcTan[(Sqrt[7]*Sqrt[3 + 5*x])/Sqrt[1 - 2*x]])/(2458624*Sqrt[7])}
{((1 - 2*x)^(5/2)*(3 + 5*x)^(5/2))/(2 + 3*x)^9, x, 10, -((75045071*Sqrt[1 - 2*x]*Sqrt[3 + 5*x])/(85349376*(2 + 3*x)^4)) + (372439373*Sqrt[1 - 2*x]*Sqrt[3 + 5*x])/(512096256*(2 + 3*x)^3) + (64983635965*Sqrt[1 - 2*x]*Sqrt[3 + 5*x])/(14338695168*(2 + 3*x)^2) + (6796051494355*Sqrt[1 - 2*x]*Sqrt[3 + 5*x])/(200741732352*(2 + 3*x)) - (720833*Sqrt[1 - 2*x]*(3 + 5*x)^(3/2))/(508032*(2 + 3*x)^5) - ((1 - 2*x)^(5/2)*(3 + 5*x)^(5/2))/(24*(2 + 3*x)^8) + (185*(1 - 2*x)^(3/2)*(3 + 5*x)^(5/2))/(1008*(2 + 3*x)^7) + (47365*Sqrt[1 - 2*x]*(3 + 5*x)^(5/2))/(36288*(2 + 3*x)^6) + (106656830005*ArcTan[(Sqrt[7]*Sqrt[3 + 5*x])/Sqrt[1 - 2*x]])/(275365888*Sqrt[7])}


(* ::Subsubsection::Closed:: *)
(*n<0*)


{((1 - 2*x)^(5/2)*(2 + 3*x)^4)/Sqrt[3 + 5*x], x, 8, (-29880867787*Sqrt[1 - 2*x]*Sqrt[3 + 5*x])/34560000000 - (280447621*Sqrt[1 - 2*x]*(2 + 3*x)*Sqrt[3 + 5*x])/1728000000 - (5575081*Sqrt[1 - 2*x]*(2 + 3*x)^2*Sqrt[3 + 5*x])/216000000 + (3090401*Sqrt[1 - 2*x]*(2 + 3*x)^3*Sqrt[3 + 5*x])/75600000 + (5647*Sqrt[1 - 2*x]*(2 + 3*x)^4*Sqrt[3 + 5*x])/945000 + (149*(1 - 2*x)^(3/2)*(2 + 3*x)^4*Sqrt[3 + 5*x])/6300 + ((1 - 2*x)^(5/2)*(2 + 3*x)^4*Sqrt[3 + 5*x])/35 + (12679836719*ArcSin[Sqrt[2/11]*Sqrt[3 + 5*x]])/(1280000000*Sqrt[10])}
{((1 - 2*x)^(5/2)*(2 + 3*x)^3)/Sqrt[3 + 5*x], x, 7, (-800452163*Sqrt[1 - 2*x]*Sqrt[3 + 5*x])/1728000000 + (499583*Sqrt[1 - 2*x]*(2 + 3*x)^2*Sqrt[3 + 5*x])/10800000 + (3037*Sqrt[1 - 2*x]*(2 + 3*x)^3*Sqrt[3 + 5*x])/180000 + (17*(1 - 2*x)^(3/2)*(2 + 3*x)^3*Sqrt[3 + 5*x])/500 + ((1 - 2*x)^(5/2)*(2 + 3*x)^3*Sqrt[3 + 5*x])/30 - (7*Sqrt[1 - 2*x]*Sqrt[3 + 5*x]*(3860014 + 4790855*x))/144000000 + (368012183*ArcSin[Sqrt[2/11]*Sqrt[3 + 5*x]])/(64000000*Sqrt[10])}
{((1 - 2*x)^(5/2)*(2 + 3*x)^2)/Sqrt[3 + 5*x], x, 6, (593747*Sqrt[1 - 2*x]*Sqrt[3 + 5*x])/1600000 + (53977*(1 - 2*x)^(3/2)*Sqrt[3 + 5*x])/480000 + (4907*(1 - 2*x)^(5/2)*Sqrt[3 + 5*x])/120000 - (369*(1 - 2*x)^(7/2)*Sqrt[3 + 5*x])/4000 - (3/50)*(1 - 2*x)^(7/2)*(2 + 3*x)*Sqrt[3 + 5*x] + (6531217*ArcSin[Sqrt[2/11]*Sqrt[3 + 5*x]])/(1600000*Sqrt[10])}
{((1 - 2*x)^(5/2)*(2 + 3*x))/Sqrt[3 + 5*x], x, 5, (5929*Sqrt[1 - 2*x]*Sqrt[3 + 5*x])/16000 + (539*(1 - 2*x)^(3/2)*Sqrt[3 + 5*x])/4800 + (49*(1 - 2*x)^(5/2)*Sqrt[3 + 5*x])/1200 - (3*(1 - 2*x)^(7/2)*Sqrt[3 + 5*x])/40 + (65219*ArcSin[Sqrt[2/11]*Sqrt[3 + 5*x]])/(16000*Sqrt[10])}
{(1 - 2*x)^(5/2)/Sqrt[3 + 5*x], x, 4, (121*Sqrt[1 - 2*x]*Sqrt[3 + 5*x])/200 + (11*(1 - 2*x)^(3/2)*Sqrt[3 + 5*x])/60 + ((1 - 2*x)^(5/2)*Sqrt[3 + 5*x])/15 + (1331*ArcSin[Sqrt[2/11]*Sqrt[3 + 5*x]])/(200*Sqrt[10])}
{(1 - 2*x)^(5/2)/((2 + 3*x)*Sqrt[3 + 5*x]), x, 5, (-239*Sqrt[1 - 2*x]*Sqrt[3 + 5*x])/450 - ((1 - 2*x)^(3/2)*Sqrt[3 + 5*x])/15 - (17687*ArcSin[Sqrt[2/11]*Sqrt[3 + 5*x]])/(1350*Sqrt[10]) + (98*Sqrt[7]*ArcTan[(Sqrt[7]*Sqrt[3 + 5*x])/Sqrt[1 - 2*x]])/27}
{(1 - 2*x)^(5/2)/((2 + 3*x)^2*Sqrt[3 + 5*x]), x, 6, (74*Sqrt[1 - 2*x]*Sqrt[3 + 5*x])/45 + (2*(1 - 2*x)^(3/2)*Sqrt[3 + 5*x])/3 + ((1 - 2*x)^(5/2)*Sqrt[3 + 5*x])/(2 + 3*x) + (346*Sqrt[2/5]*ArcSin[Sqrt[2/11]*Sqrt[3 + 5*x]])/135 + (175*Sqrt[7]*ArcTan[(Sqrt[7]*Sqrt[3 + 5*x])/Sqrt[1 - 2*x]])/27}
{(1 - 2*x)^(5/2)/((2 + 3*x)^3*Sqrt[3 + 5*x]), x, 6, (91*Sqrt[1 - 2*x]*Sqrt[3 + 5*x])/18 + ((1 - 2*x)^(5/2)*Sqrt[3 + 5*x])/(2*(2 + 3*x)^2) + (95*(1 - 2*x)^(3/2)*Sqrt[3 + 5*x])/(12*(2 + 3*x)) - (8*Sqrt[2/5]*ArcSin[Sqrt[2/11]*Sqrt[3 + 5*x]])/27 + (3035*Sqrt[7]*ArcTan[(Sqrt[7]*Sqrt[3 + 5*x])/Sqrt[1 - 2*x]])/108}
{(1 - 2*x)^(5/2)/((2 + 3*x)^4*Sqrt[3 + 5*x]), x, 4, ((1 - 2*x)^(5/2)*Sqrt[3 + 5*x])/(3*(2 + 3*x)^3) + (55*(1 - 2*x)^(3/2)*Sqrt[3 + 5*x])/(12*(2 + 3*x)^2) + (605*Sqrt[1 - 2*x]*Sqrt[3 + 5*x])/(8*(2 + 3*x)) + (6655*ArcTan[(Sqrt[7]*Sqrt[3 + 5*x])/Sqrt[1 - 2*x]])/(8*Sqrt[7])}
{(1 - 2*x)^(5/2)/((2 + 3*x)^5*Sqrt[3 + 5*x]), x, 6, ((1 - 2*x)^(5/2)*Sqrt[3 + 5*x])/(4*(2 + 3*x)^4) + (235*(1 - 2*x)^(3/2)*Sqrt[3 + 5*x])/(72*(2 + 3*x)^3) + (38875*Sqrt[1 - 2*x]*Sqrt[3 + 5*x])/(864*(2 + 3*x)^2) + (3879245*Sqrt[1 - 2*x]*Sqrt[3 + 5*x])/(12096*(2 + 3*x)) + (1643785*ArcTan[(Sqrt[7]*Sqrt[3 + 5*x])/Sqrt[1 - 2*x]])/(448*Sqrt[7])}
{(1 - 2*x)^(5/2)/((2 + 3*x)^6*Sqrt[3 + 5*x]), x, 7, ((1 - 2*x)^(5/2)*Sqrt[3 + 5*x])/(5*(2 + 3*x)^5) + (61*(1 - 2*x)^(3/2)*Sqrt[3 + 5*x])/(24*(2 + 3*x)^4) + (14131*Sqrt[1 - 2*x]*Sqrt[3 + 5*x])/(432*(2 + 3*x)^3) + (2347559*Sqrt[1 - 2*x]*Sqrt[3 + 5*x])/(12096*(2 + 3*x)^2) + (245529161*Sqrt[1 - 2*x]*Sqrt[3 + 5*x])/(169344*(2 + 3*x)) + (104040277*ArcTan[(Sqrt[7]*Sqrt[3 + 5*x])/Sqrt[1 - 2*x]])/(6272*Sqrt[7])}
{(1 - 2*x)^(5/2)/((2 + 3*x)^7*Sqrt[3 + 5*x]), x, 8, ((1 - 2*x)^(5/2)*Sqrt[3 + 5*x])/(6*(2 + 3*x)^6) + (25*(1 - 2*x)^(3/2)*Sqrt[3 + 5*x])/(12*(2 + 3*x)^5) + (7445*Sqrt[1 - 2*x]*Sqrt[3 + 5*x])/(288*(2 + 3*x)^4) + (1729615*Sqrt[1 - 2*x]*Sqrt[3 + 5*x])/(12096*(2 + 3*x)^3) + (302171615*Sqrt[1 - 2*x]*Sqrt[3 + 5*x])/(338688*(2 + 3*x)^2) + (31603880465*Sqrt[1 - 2*x]*Sqrt[3 + 5*x])/(4741632*(2 + 3*x)) + (13391796605*ArcTan[(Sqrt[7]*Sqrt[3 + 5*x])/Sqrt[1 - 2*x]])/(175616*Sqrt[7])}


{((1 - 2*x)^(5/2)*(2 + 3*x)^4)/(3 + 5*x)^(3/2), x, 8, (-2*(1 - 2*x)^(5/2)*(2 + 3*x)^4)/(5*Sqrt[3 + 5*x]) - (320899019*Sqrt[1 - 2*x]*Sqrt[3 + 5*x])/2880000000 - (7*(6000382 - 1842385*x)*Sqrt[1 - 2*x]*Sqrt[3 + 5*x])/240000000 + (5421479*Sqrt[1 - 2*x]*(2 + 3*x)^2*Sqrt[3 + 5*x])/18000000 + (1178663*Sqrt[1 - 2*x]*(2 + 3*x)^3*Sqrt[3 + 5*x])/900000 - (4439*Sqrt[1 - 2*x]*(2 + 3*x)^4*Sqrt[3 + 5*x])/11250 - (13*(1 - 2*x)^(3/2)*(2 + 3*x)^4*Sqrt[3 + 5*x])/75 + (1298595837*ArcSin[Sqrt[2/11]*Sqrt[3 + 5*x]])/(320000000*Sqrt[10])}
{((1 - 2*x)^(5/2)*(2 + 3*x)^3)/(3 + 5*x)^(3/2), x, 7, (-2*(1 - 2*x)^(5/2)*(2 + 3*x)^3)/(5*Sqrt[3 + 5*x]) - (2987467*Sqrt[1 - 2*x]*Sqrt[3 + 5*x])/24000000 + (386939*Sqrt[1 - 2*x]*(2 + 3*x)*Sqrt[3 + 5*x])/1200000 + (205079*Sqrt[1 - 2*x]*(2 + 3*x)^2*Sqrt[3 + 5*x])/150000 - (1019*Sqrt[1 - 2*x]*(2 + 3*x)^3*Sqrt[3 + 5*x])/2500 - (22*(1 - 2*x)^(3/2)*(2 + 3*x)^3*Sqrt[3 + 5*x])/125 + (24319911*ArcSin[Sqrt[2/11]*Sqrt[3 + 5*x]])/(8000000*Sqrt[10])}
{((1 - 2*x)^(5/2)*(2 + 3*x)^2)/(3 + 5*x)^(3/2), x, 6, -((2*(1 - 2*x)^(7/2))/(275*Sqrt[3 + 5*x])) + (21483*Sqrt[1 - 2*x]*Sqrt[3 + 5*x])/80000 + (651*(1 - 2*x)^(3/2)*Sqrt[3 + 5*x])/8000 + (651*(1 - 2*x)^(5/2)*Sqrt[3 + 5*x])/22000 - (9/200)*(1 - 2*x)^(7/2)*Sqrt[3 + 5*x] + (236313*ArcSin[Sqrt[2/11]*Sqrt[3 + 5*x]])/(80000*Sqrt[10])}
{((1 - 2*x)^(5/2)*(2 + 3*x))/(3 + 5*x)^(3/2), x, 5, (-2*(1 - 2*x)^(7/2))/(55*Sqrt[3 + 5*x]) + (231*Sqrt[1 - 2*x]*Sqrt[3 + 5*x])/1000 + (7*(1 - 2*x)^(3/2)*Sqrt[3 + 5*x])/100 + (7*(1 - 2*x)^(5/2)*Sqrt[3 + 5*x])/275 + (2541*ArcSin[Sqrt[2/11]*Sqrt[3 + 5*x]])/(1000*Sqrt[10])}
{(1 - 2*x)^(5/2)/(3 + 5*x)^(3/2), x, 4, (-2*(1 - 2*x)^(5/2))/(5*Sqrt[3 + 5*x]) - (33*Sqrt[1 - 2*x]*Sqrt[3 + 5*x])/50 - ((1 - 2*x)^(3/2)*Sqrt[3 + 5*x])/5 - (363*ArcSin[Sqrt[2/11]*Sqrt[3 + 5*x]])/(50*Sqrt[10])}
{(1 - 2*x)^(5/2)/((2 + 3*x)*(3 + 5*x)^(3/2)), x, 6, (-2*(1 - 2*x)^(5/2))/Sqrt[3 + 5*x] - (128*Sqrt[1 - 2*x]*Sqrt[3 + 5*x])/75 - (4*(1 - 2*x)^(3/2)*Sqrt[3 + 5*x])/5 + (338*Sqrt[2/5]*ArcSin[Sqrt[2/11]*Sqrt[3 + 5*x]])/225 - (98*Sqrt[7]*ArcTan[(Sqrt[7]*Sqrt[3 + 5*x])/Sqrt[1 - 2*x]])/9}
{(1 - 2*x)^(5/2)/((2 + 3*x)^2*(3 + 5*x)^(3/2)), x, 6, (-33*(1 - 2*x)^(3/2))/Sqrt[3 + 5*x] + (1 - 2*x)^(5/2)/((2 + 3*x)*Sqrt[3 + 5*x]) - (202*Sqrt[1 - 2*x]*Sqrt[3 + 5*x])/15 - (8*Sqrt[2/5]*ArcSin[Sqrt[2/11]*Sqrt[3 + 5*x]])/45 - (665*Sqrt[7]*ArcTan[(Sqrt[7]*Sqrt[3 + 5*x])/Sqrt[1 - 2*x]])/9}
{(1 - 2*x)^(5/2)/((2 + 3*x)^3*(3 + 5*x)^(3/2)), x, 4, (-1815*Sqrt[1 - 2*x])/(4*Sqrt[3 + 5*x]) + (1 - 2*x)^(5/2)/(2*(2 + 3*x)^2*Sqrt[3 + 5*x]) + (55*(1 - 2*x)^(3/2))/(4*(2 + 3*x)*Sqrt[3 + 5*x]) - (1815*Sqrt[7]*ArcTan[(Sqrt[7]*Sqrt[3 + 5*x])/Sqrt[1 - 2*x]])/4}
{(1 - 2*x)^(5/2)/((2 + 3*x)^4*(3 + 5*x)^(3/2)), x, 6, (-578245*Sqrt[1 - 2*x])/(216*Sqrt[3 + 5*x]) + (1 - 2*x)^(5/2)/(3*(2 + 3*x)^3*Sqrt[3 + 5*x]) + (235*(1 - 2*x)^(3/2))/(36*(2 + 3*x)^2*Sqrt[3 + 5*x]) + (39155*Sqrt[1 - 2*x])/(216*(2 + 3*x)*Sqrt[3 + 5*x]) - (147015*ArcTan[(Sqrt[7]*Sqrt[3 + 5*x])/Sqrt[1 - 2*x]])/(8*Sqrt[7])}
{(1 - 2*x)^(5/2)/((2 + 3*x)^5*(3 + 5*x)^(3/2)), x, 7, (-181304825*Sqrt[1 - 2*x])/(12096*Sqrt[3 + 5*x]) + (1 - 2*x)^(5/2)/(4*(2 + 3*x)^4*Sqrt[3 + 5*x]) + (305*(1 - 2*x)^(3/2))/(72*(2 + 3*x)^3*Sqrt[3 + 5*x]) + (71215*Sqrt[1 - 2*x])/(864*(2 + 3*x)^2*Sqrt[3 + 5*x]) + (3997345*Sqrt[1 - 2*x])/(4032*(2 + 3*x)*Sqrt[3 + 5*x]) - (46095555*ArcTan[(Sqrt[7]*Sqrt[3 + 5*x])/Sqrt[1 - 2*x]])/(448*Sqrt[7])}
{(1 - 2*x)^(5/2)/((2 + 3*x)^6*(3 + 5*x)^(3/2)), x, 8, -((4639661185*Sqrt[1 - 2*x])/(56448*Sqrt[3 + 5*x])) + (1 - 2*x)^(5/2)/(5*(2 + 3*x)^5*Sqrt[3 + 5*x]) + (25*(1 - 2*x)^(3/2))/(8*(2 + 3*x)^4*Sqrt[3 + 5*x]) + (7501*Sqrt[1 - 2*x])/(144*(2 + 3*x)^3*Sqrt[3 + 5*x]) + (587477*Sqrt[1 - 2*x])/(1344*(2 + 3*x)^2*Sqrt[3 + 5*x]) + (102293609*Sqrt[1 - 2*x])/(18816*(2 + 3*x)*Sqrt[3 + 5*x]) - (3538809681*ArcTan[(Sqrt[7]*Sqrt[3 + 5*x])/Sqrt[1 - 2*x]])/(6272*Sqrt[7])}


{((1 - 2*x)^(5/2)*(2 + 3*x)^4)/(3 + 5*x)^(5/2), x, 8, (-2*(1 - 2*x)^(5/2)*(2 + 3*x)^4)/(15*(3 + 5*x)^(3/2)) - (508*(1 - 2*x)^(3/2)*(2 + 3*x)^4)/(75*Sqrt[3 + 5*x]) + (59754401*Sqrt[1 - 2*x]*Sqrt[3 + 5*x])/40000000 - (21*(191622 - 763085*x)*Sqrt[1 - 2*x]*Sqrt[3 + 5*x])/10000000 + (525259*Sqrt[1 - 2*x]*(2 + 3*x)^2*Sqrt[3 + 5*x])/250000 + (109323*Sqrt[1 - 2*x]*(2 + 3*x)^3*Sqrt[3 + 5*x])/12500 - (1676*Sqrt[1 - 2*x]*(2 + 3*x)^4*Sqrt[3 + 5*x])/625 + (88296593*ArcSin[Sqrt[2/11]*Sqrt[3 + 5*x]])/(40000000*Sqrt[10])}
{((1 - 2*x)^(5/2)*(2 + 3*x)^3)/(3 + 5*x)^(5/2), x, 7, (-2*(1 - 2*x)^(5/2)*(2 + 3*x)^3)/(15*(3 + 5*x)^(3/2)) - (376*(1 - 2*x)^(3/2)*(2 + 3*x)^3)/(75*Sqrt[3 + 5*x]) + (195643*Sqrt[1 - 2*x]*Sqrt[3 + 5*x])/400000 + (34069*Sqrt[1 - 2*x]*(2 + 3*x)*Sqrt[3 + 5*x])/20000 + (16009*Sqrt[1 - 2*x]*(2 + 3*x)^2*Sqrt[3 + 5*x])/2500 - (247*Sqrt[1 - 2*x]*(2 + 3*x)^3*Sqrt[3 + 5*x])/125 + (766843*ArcSin[Sqrt[2/11]*Sqrt[3 + 5*x]])/(400000*Sqrt[10])}
{((1 - 2*x)^(5/2)*(2 + 3*x)^2)/(3 + 5*x)^(5/2), x, 6, -((2*(1 - 2*x)^(7/2))/(825*(3 + 5*x)^(3/2))) - (76*(1 - 2*x)^(7/2))/(1815*Sqrt[3 + 5*x]) + (329*Sqrt[1 - 2*x]*Sqrt[3 + 5*x])/5000 + (329*(1 - 2*x)^(3/2)*Sqrt[3 + 5*x])/16500 + (329*(1 - 2*x)^(5/2)*Sqrt[3 + 5*x])/45375 + (3619*ArcSin[Sqrt[2/11]*Sqrt[3 + 5*x]])/(5000*Sqrt[10])}
{((1 - 2*x)^(5/2)*(2 + 3*x))/(3 + 5*x)^(5/2), x, 5, (-2*(1 - 2*x)^(7/2))/(165*(3 + 5*x)^(3/2)) - (182*(1 - 2*x)^(5/2))/(825*Sqrt[3 + 5*x]) - (91*Sqrt[1 - 2*x]*Sqrt[3 + 5*x])/250 - (91*(1 - 2*x)^(3/2)*Sqrt[3 + 5*x])/825 - (1001*ArcSin[Sqrt[2/11]*Sqrt[3 + 5*x]])/(250*Sqrt[10])}
{(1 - 2*x)^(5/2)/(3 + 5*x)^(5/2), x, 4, (-2*(1 - 2*x)^(5/2))/(15*(3 + 5*x)^(3/2)) + (4*(1 - 2*x)^(3/2))/(15*Sqrt[3 + 5*x]) + (4*Sqrt[1 - 2*x]*Sqrt[3 + 5*x])/25 + (22*Sqrt[2/5]*ArcSin[Sqrt[2/11]*Sqrt[3 + 5*x]])/25}
{(1 - 2*x)^(5/2)/((2 + 3*x)*(3 + 5*x)^(5/2)), x, 6, (-2*(1 - 2*x)^(5/2))/(3*(3 + 5*x)^(3/2)) + (218*(1 - 2*x)^(3/2))/(15*Sqrt[3 + 5*x]) + (148*Sqrt[1 - 2*x]*Sqrt[3 + 5*x])/25 - (8*Sqrt[2/5]*ArcSin[Sqrt[2/11]*Sqrt[3 + 5*x]])/75 + (98*Sqrt[7]*ArcTan[(Sqrt[7]*Sqrt[3 + 5*x])/Sqrt[1 - 2*x]])/3}
{(1 - 2*x)^(5/2)/((2 + 3*x)^2*(3 + 5*x)^(5/2)), x, 4, (-55*(1 - 2*x)^(3/2))/(3*(3 + 5*x)^(3/2)) + (1 - 2*x)^(5/2)/((2 + 3*x)*(3 + 5*x)^(3/2)) + (385*Sqrt[1 - 2*x])/Sqrt[3 + 5*x] + 385*Sqrt[7]*ArcTan[(Sqrt[7]*Sqrt[3 + 5*x])/Sqrt[1 - 2*x]]}
{(1 - 2*x)^(5/2)/((2 + 3*x)^3*(3 + 5*x)^(5/2)), x, 6, (-4279*Sqrt[1 - 2*x])/(12*(3 + 5*x)^(3/2)) + (1 - 2*x)^(5/2)/(2*(2 + 3*x)^2*(3 + 5*x)^(3/2)) + (235*(1 - 2*x)^(3/2))/(12*(2 + 3*x)*(3 + 5*x)^(3/2)) + (40213*Sqrt[1 - 2*x])/(12*Sqrt[3 + 5*x]) + (13145*Sqrt[7]*ArcTan[(Sqrt[7]*Sqrt[3 + 5*x])/Sqrt[1 - 2*x]])/4}
{(1 - 2*x)^(5/2)/((2 + 3*x)^4*(3 + 5*x)^(5/2)), x, 7, (-196735*Sqrt[1 - 2*x])/(72*(3 + 5*x)^(3/2)) + (1 - 2*x)^(5/2)/(3*(2 + 3*x)^3*(3 + 5*x)^(3/2)) + (305*(1 - 2*x)^(3/2))/(36*(2 + 3*x)^2*(3 + 5*x)^(3/2)) + (7975*Sqrt[1 - 2*x])/(24*(2 + 3*x)*(3 + 5*x)^(3/2)) + (1784635*Sqrt[1 - 2*x])/(72*Sqrt[3 + 5*x]) + (1361195*ArcTan[(Sqrt[7]*Sqrt[3 + 5*x])/Sqrt[1 - 2*x]])/(8*Sqrt[7])}
{(1 - 2*x)^(5/2)/((2 + 3*x)^5*(3 + 5*x)^(5/2)), x, 8, (-25024175*Sqrt[1 - 2*x])/(1344*(3 + 5*x)^(3/2)) + (1 - 2*x)^(5/2)/(4*(2 + 3*x)^4*(3 + 5*x)^(3/2)) + (125*(1 - 2*x)^(3/2))/(24*(2 + 3*x)^3*(3 + 5*x)^(3/2)) + (12595*Sqrt[1 - 2*x])/(96*(2 + 3*x)^2*(3 + 5*x)^(3/2)) + (2992825*Sqrt[1 - 2*x])/(1344*(2 + 3*x)*(3 + 5*x)^(3/2)) + (227000875*Sqrt[1 - 2*x])/(1344*Sqrt[3 + 5*x]) + (519421265*ArcTan[(Sqrt[7]*Sqrt[3 + 5*x])/Sqrt[1 - 2*x]])/(448*Sqrt[7])}
{(1 - 2*x)^(5/2)/((2 + 3*x)^6*(3 + 5*x)^(5/2)), x, 9, -((754386765*Sqrt[1 - 2*x])/(6272*(3 + 5*x)^(3/2))) + (1 - 2*x)^(5/2)/(5*(2 + 3*x)^5*(3 + 5*x)^(3/2)) + (89*(1 - 2*x)^(3/2))/(24*(2 + 3*x)^4*(3 + 5*x)^(3/2)) + (10945*Sqrt[1 - 2*x])/(144*(2 + 3*x)^3*(3 + 5*x)^(3/2)) + (3329689*Sqrt[1 - 2*x])/(4032*(2 + 3*x)^2*(3 + 5*x)^(3/2)) + (270667969*Sqrt[1 - 2*x])/(18816*(2 + 3*x)*(3 + 5*x)^(3/2)) + (20529722435*Sqrt[1 - 2*x])/(18816*Sqrt[3 + 5*x]) + (46975917593*ArcTan[(Sqrt[7]*Sqrt[3 + 5*x])/Sqrt[1 - 2*x]])/(6272*Sqrt[7])}


(* ::Subsection::Closed:: *)
(*Integrands of the form (a+b x)^m (c+d x)^(n/2) / (e+f x)^(1/2)*)


(* ::Subsubsection::Closed:: *)
(*n>0*)


{((2 + 3*x)^4*Sqrt[3 + 5*x])/Sqrt[1 - 2*x], x, 6, (-96151531*Sqrt[1 - 2*x]*Sqrt[3 + 5*x])/2560000 - (25529*Sqrt[1 - 2*x]*(2 + 3*x)^2*Sqrt[3 + 5*x])/16000 - (313*Sqrt[1 - 2*x]*(2 + 3*x)^3*Sqrt[3 + 5*x])/800 - (Sqrt[1 - 2*x]*(2 + 3*x)^4*Sqrt[3 + 5*x])/10 - (21*Sqrt[1 - 2*x]*Sqrt[3 + 5*x]*(390718 + 637135*x))/640000 + (1067352517*ArcSin[Sqrt[2/11]*Sqrt[3 + 5*x]])/(2560000*Sqrt[10])}
{((2 + 3*x)^3*Sqrt[3 + 5*x])/Sqrt[1 - 2*x], x, 5, (-11835*Sqrt[1 - 2*x]*Sqrt[3 + 5*x])/1024 - (2829*Sqrt[1 - 2*x]*(2 + 3*x)*Sqrt[3 + 5*x])/1280 - (81*Sqrt[1 - 2*x]*(2 + 3*x)^2*Sqrt[3 + 5*x])/160 - (Sqrt[1 - 2*x]*(2 + 3*x)^3*Sqrt[3 + 5*x])/8 + (677017*ArcSin[Sqrt[2/11]*Sqrt[3 + 5*x]])/(5120*Sqrt[10])}
{((2 + 3*x)^2*Sqrt[3 + 5*x])/Sqrt[1 - 2*x], x, 4, -((6269*Sqrt[1 - 2*x]*Sqrt[3 + 5*x])/1600) - (181/400)*Sqrt[1 - 2*x]*(3 + 5*x)^(3/2) - (1/10)*Sqrt[1 - 2*x]*(2 + 3*x)*(3 + 5*x)^(3/2) + (68959*ArcSin[Sqrt[2/11]*Sqrt[3 + 5*x]])/(1600*Sqrt[10])}
{((2 + 3*x)*Sqrt[3 + 5*x])/Sqrt[1 - 2*x], x, 3, (-107*Sqrt[1 - 2*x]*Sqrt[3 + 5*x])/80 - (3*Sqrt[1 - 2*x]*(3 + 5*x)^(3/2))/20 + (1177*ArcSin[Sqrt[2/11]*Sqrt[3 + 5*x]])/(80*Sqrt[10])}
{Sqrt[3 + 5*x]/Sqrt[1 - 2*x], x, 2, -(Sqrt[1 - 2*x]*Sqrt[3 + 5*x])/2 + (11*ArcSin[Sqrt[2/11]*Sqrt[3 + 5*x]])/(2*Sqrt[10])}
{Sqrt[3 + 5*x]/(Sqrt[1 - 2*x]*(2 + 3*x)), x, 3, (Sqrt[10]*ArcSin[Sqrt[2/11]*Sqrt[3 + 5*x]])/3 - (2*ArcTan[(Sqrt[7]*Sqrt[3 + 5*x])/Sqrt[1 - 2*x]])/(3*Sqrt[7])}
{Sqrt[3 + 5*x]/(Sqrt[1 - 2*x]*(2 + 3*x)^2), x, 2, -(Sqrt[1 - 2*x]*Sqrt[3 + 5*x])/(7*(2 + 3*x)) + (11*ArcTan[(Sqrt[7]*Sqrt[3 + 5*x])/Sqrt[1 - 2*x]])/(7*Sqrt[7])}
{Sqrt[3 + 5*x]/(Sqrt[1 - 2*x]*(2 + 3*x)^3), x, 4, -(Sqrt[1 - 2*x]*Sqrt[3 + 5*x])/(14*(2 + 3*x)^2) + (29*Sqrt[1 - 2*x]*Sqrt[3 + 5*x])/(196*(2 + 3*x)) + (451*ArcTan[(Sqrt[7]*Sqrt[3 + 5*x])/Sqrt[1 - 2*x]])/(196*Sqrt[7])}
{Sqrt[3 + 5*x]/(Sqrt[1 - 2*x]*(2 + 3*x)^4), x, 5, -(Sqrt[1 - 2*x]*Sqrt[3 + 5*x])/(21*(2 + 3*x)^3) + (25*Sqrt[1 - 2*x]*Sqrt[3 + 5*x])/(588*(2 + 3*x)^2) + (3895*Sqrt[1 - 2*x]*Sqrt[3 + 5*x])/(8232*(2 + 3*x)) + (15235*ArcTan[(Sqrt[7]*Sqrt[3 + 5*x])/Sqrt[1 - 2*x]])/(2744*Sqrt[7])}
{Sqrt[3 + 5*x]/(Sqrt[1 - 2*x]*(2 + 3*x)^5), x, 6, -(Sqrt[1 - 2*x]*Sqrt[3 + 5*x])/(28*(2 + 3*x)^4) + (Sqrt[1 - 2*x]*Sqrt[3 + 5*x])/(56*(2 + 3*x)^3) + (305*Sqrt[1 - 2*x]*Sqrt[3 + 5*x])/(1568*(2 + 3*x)^2) + (32735*Sqrt[1 - 2*x]*Sqrt[3 + 5*x])/(21952*(2 + 3*x)) + (375265*ArcTan[(Sqrt[7]*Sqrt[3 + 5*x])/Sqrt[1 - 2*x]])/(21952*Sqrt[7])}


{((2 + 3*x)^3*(3 + 5*x)^(3/2))/Sqrt[1 - 2*x], x, 6, (-30292449*Sqrt[1 - 2*x]*Sqrt[3 + 5*x])/512000 - (875641*Sqrt[1 - 2*x]*(3 + 5*x)^(3/2))/128000 - (5029*Sqrt[1 - 2*x]*(2 + 3*x)*(3 + 5*x)^(3/2))/3200 - (309*Sqrt[1 - 2*x]*(2 + 3*x)^2*(3 + 5*x)^(3/2))/800 - (Sqrt[1 - 2*x]*(2 + 3*x)^3*(3 + 5*x)^(3/2))/10 + (333216939*ArcSin[Sqrt[2/11]*Sqrt[3 + 5*x]])/(512000*Sqrt[10])}
{((2 + 3*x)^2*(3 + 5*x)^(3/2))/Sqrt[1 - 2*x], x, 5, -((479457*Sqrt[1 - 2*x]*Sqrt[3 + 5*x])/25600) - (14529*Sqrt[1 - 2*x]*(3 + 5*x)^(3/2))/6400 - (251/800)*Sqrt[1 - 2*x]*(3 + 5*x)^(5/2) - (3/40)*Sqrt[1 - 2*x]*(2 + 3*x)*(3 + 5*x)^(5/2) + (5274027*ArcSin[Sqrt[2/11]*Sqrt[3 + 5*x]])/(25600*Sqrt[10])}
{((2 + 3*x)*(3 + 5*x)^(3/2))/Sqrt[1 - 2*x], x, 4, (-1947*Sqrt[1 - 2*x]*Sqrt[3 + 5*x])/320 - (59*Sqrt[1 - 2*x]*(3 + 5*x)^(3/2))/80 - (Sqrt[1 - 2*x]*(3 + 5*x)^(5/2))/10 + (21417*ArcSin[Sqrt[2/11]*Sqrt[3 + 5*x]])/(320*Sqrt[10])}
{(3 + 5*x)^(3/2)/Sqrt[1 - 2*x], x, 3, (-33*Sqrt[1 - 2*x]*Sqrt[3 + 5*x])/16 - (Sqrt[1 - 2*x]*(3 + 5*x)^(3/2))/4 + (363*ArcSin[Sqrt[2/11]*Sqrt[3 + 5*x]])/(16*Sqrt[10])}
{(3 + 5*x)^(3/2)/(Sqrt[1 - 2*x]*(2 + 3*x)), x, 4, (-5*Sqrt[1 - 2*x]*Sqrt[3 + 5*x])/6 + (29*Sqrt[5/2]*ArcSin[Sqrt[2/11]*Sqrt[3 + 5*x]])/18 + (2*ArcTan[(Sqrt[7]*Sqrt[3 + 5*x])/Sqrt[1 - 2*x]])/(9*Sqrt[7])}
{(3 + 5*x)^(3/2)/(Sqrt[1 - 2*x]*(2 + 3*x)^2), x, 5, (5*Sqrt[1 - 2*x]*Sqrt[3 + 5*x])/21 - (Sqrt[1 - 2*x]*(3 + 5*x)^(3/2))/(7*(2 + 3*x)) + (5*Sqrt[10]*ArcSin[Sqrt[2/11]*Sqrt[3 + 5*x]])/9 - (103*ArcTan[(Sqrt[7]*Sqrt[3 + 5*x])/Sqrt[1 - 2*x]])/(63*Sqrt[7])}
{(3 + 5*x)^(3/2)/(Sqrt[1 - 2*x]*(2 + 3*x)^3), x, 3, (-33*Sqrt[1 - 2*x]*Sqrt[3 + 5*x])/(196*(2 + 3*x)) - (Sqrt[1 - 2*x]*(3 + 5*x)^(3/2))/(14*(2 + 3*x)^2) + (363*ArcTan[(Sqrt[7]*Sqrt[3 + 5*x])/Sqrt[1 - 2*x]])/(196*Sqrt[7])}
{(3 + 5*x)^(3/2)/(Sqrt[1 - 2*x]*(2 + 3*x)^4), x, 5, (-95*Sqrt[1 - 2*x]*Sqrt[3 + 5*x])/(1764*(2 + 3*x)^2) + (2195*Sqrt[1 - 2*x]*Sqrt[3 + 5*x])/(24696*(2 + 3*x)) - (Sqrt[1 - 2*x]*(3 + 5*x)^(3/2))/(21*(2 + 3*x)^3) + (5445*ArcTan[(Sqrt[7]*Sqrt[3 + 5*x])/Sqrt[1 - 2*x]])/(2744*Sqrt[7])}
{(3 + 5*x)^(3/2)/(Sqrt[1 - 2*x]*(2 + 3*x)^5), x, 6, (-13*Sqrt[1 - 2*x]*Sqrt[3 + 5*x])/(504*(2 + 3*x)^3) + (85*Sqrt[1 - 2*x]*Sqrt[3 + 5*x])/(14112*(2 + 3*x)^2) + (57595*Sqrt[1 - 2*x]*Sqrt[3 + 5*x])/(197568*(2 + 3*x)) - (Sqrt[1 - 2*x]*(3 + 5*x)^(3/2))/(28*(2 + 3*x)^4) + (78045*ArcTan[(Sqrt[7]*Sqrt[3 + 5*x])/Sqrt[1 - 2*x]])/(21952*Sqrt[7])}
{(3 + 5*x)^(3/2)/(Sqrt[1 - 2*x]*(2 + 3*x)^6), x, 7, -((29*Sqrt[1 - 2*x]*Sqrt[3 + 5*x])/(1960*(2 + 3*x)^4)) - (73*Sqrt[1 - 2*x]*Sqrt[3 + 5*x])/(11760*(2 + 3*x)^3) + (6107*Sqrt[1 - 2*x]*Sqrt[3 + 5*x])/(65856*(2 + 3*x)^2) + (694229*Sqrt[1 - 2*x]*Sqrt[3 + 5*x])/(921984*(2 + 3*x)) - (Sqrt[1 - 2*x]*(3 + 5*x)^(3/2))/(35*(2 + 3*x)^5) + (2664057*ArcTan[(Sqrt[7]*Sqrt[3 + 5*x])/Sqrt[1 - 2*x]])/(307328*Sqrt[7])}


{((2 + 3*x)^3*(3 + 5*x)^(5/2))/Sqrt[1 - 2*x], x, 7, (-243487211*Sqrt[1 - 2*x]*Sqrt[3 + 5*x])/819200 - (22135201*Sqrt[1 - 2*x]*(3 + 5*x)^(3/2))/614400 - (382619*Sqrt[1 - 2*x]*(3 + 5*x)^(5/2))/76800 - (1569*Sqrt[1 - 2*x]*(2 + 3*x)*(3 + 5*x)^(5/2))/1280 - (5*Sqrt[1 - 2*x]*(2 + 3*x)^2*(3 + 5*x)^(5/2))/16 - (Sqrt[1 - 2*x]*(2 + 3*x)^3*(3 + 5*x)^(5/2))/12 + (2678359321*ArcSin[Sqrt[2/11]*Sqrt[3 + 5*x]])/(819200*Sqrt[10])}
{((2 + 3*x)^2*(3 + 5*x)^(5/2))/Sqrt[1 - 2*x], x, 6, -((9458207*Sqrt[1 - 2*x]*Sqrt[3 + 5*x])/102400) - (859837*Sqrt[1 - 2*x]*(3 + 5*x)^(3/2))/76800 - (78167*Sqrt[1 - 2*x]*(3 + 5*x)^(5/2))/48000 - (963*Sqrt[1 - 2*x]*(3 + 5*x)^(7/2))/4000 - (3/50)*Sqrt[1 - 2*x]*(2 + 3*x)*(3 + 5*x)^(7/2) + (104040277*ArcSin[Sqrt[2/11]*Sqrt[3 + 5*x]])/(102400*Sqrt[10])}
{((2 + 3*x)*(3 + 5*x)^(5/2))/Sqrt[1 - 2*x], x, 5, (-29887*Sqrt[1 - 2*x]*Sqrt[3 + 5*x])/1024 - (2717*Sqrt[1 - 2*x]*(3 + 5*x)^(3/2))/768 - (247*Sqrt[1 - 2*x]*(3 + 5*x)^(5/2))/480 - (3*Sqrt[1 - 2*x]*(3 + 5*x)^(7/2))/40 + (328757*ArcSin[Sqrt[2/11]*Sqrt[3 + 5*x]])/(1024*Sqrt[10])}
{(3 + 5*x)^(5/2)/Sqrt[1 - 2*x], x, 4, (-605*Sqrt[1 - 2*x]*Sqrt[3 + 5*x])/64 - (55*Sqrt[1 - 2*x]*(3 + 5*x)^(3/2))/48 - (Sqrt[1 - 2*x]*(3 + 5*x)^(5/2))/6 + (1331*Sqrt[5/2]*ArcSin[Sqrt[2/11]*Sqrt[3 + 5*x]])/64}
{(3 + 5*x)^(5/2)/(Sqrt[1 - 2*x]*(2 + 3*x)), x, 5, (-455*Sqrt[1 - 2*x]*Sqrt[3 + 5*x])/144 - (5*Sqrt[1 - 2*x]*(3 + 5*x)^(3/2))/12 + (3035*Sqrt[5/2]*ArcSin[Sqrt[2/11]*Sqrt[3 + 5*x]])/432 - (2*ArcTan[(Sqrt[7]*Sqrt[3 + 5*x])/Sqrt[1 - 2*x]])/(27*Sqrt[7])}
{(3 + 5*x)^(5/2)/(Sqrt[1 - 2*x]*(2 + 3*x)^2), x, 6, (-185*Sqrt[1 - 2*x]*Sqrt[3 + 5*x])/126 + (5*Sqrt[1 - 2*x]*(3 + 5*x)^(3/2))/21 - (Sqrt[1 - 2*x]*(3 + 5*x)^(5/2))/(7*(2 + 3*x)) + (125*Sqrt[5/2]*ArcSin[Sqrt[2/11]*Sqrt[3 + 5*x]])/54 + (173*ArcTan[(Sqrt[7]*Sqrt[3 + 5*x])/Sqrt[1 - 2*x]])/(189*Sqrt[7])}
{(3 + 5*x)^(5/2)/(Sqrt[1 - 2*x]*(2 + 3*x)^3), x, 6, (1195*Sqrt[1 - 2*x]*Sqrt[3 + 5*x])/1764 - (169*Sqrt[1 - 2*x]*(3 + 5*x)^(3/2))/(588*(2 + 3*x)) - (Sqrt[1 - 2*x]*(3 + 5*x)^(5/2))/(14*(2 + 3*x)^2) + (25*Sqrt[10]*ArcSin[Sqrt[2/11]*Sqrt[3 + 5*x]])/27 - (17687*ArcTan[(Sqrt[7]*Sqrt[3 + 5*x])/Sqrt[1 - 2*x]])/(5292*Sqrt[7])}
{(3 + 5*x)^(5/2)/(Sqrt[1 - 2*x]*(2 + 3*x)^4), x, 4, (-605*Sqrt[1 - 2*x]*Sqrt[3 + 5*x])/(2744*(2 + 3*x)) - (55*Sqrt[1 - 2*x]*(3 + 5*x)^(3/2))/(588*(2 + 3*x)^2) - (Sqrt[1 - 2*x]*(3 + 5*x)^(5/2))/(21*(2 + 3*x)^3) + (6655*ArcTan[(Sqrt[7]*Sqrt[3 + 5*x])/Sqrt[1 - 2*x]])/(2744*Sqrt[7])}
{(3 + 5*x)^(5/2)/(Sqrt[1 - 2*x]*(2 + 3*x)^5), x, 6, (-295*Sqrt[1 - 2*x]*Sqrt[3 + 5*x])/(6048*(2 + 3*x)^2) + (4315*Sqrt[1 - 2*x]*Sqrt[3 + 5*x])/(84672*(2 + 3*x)) - (23*Sqrt[1 - 2*x]*(3 + 5*x)^(3/2))/(504*(2 + 3*x)^3) - (Sqrt[1 - 2*x]*(3 + 5*x)^(5/2))/(28*(2 + 3*x)^4) + (6655*ArcTan[(Sqrt[7]*Sqrt[3 + 5*x])/Sqrt[1 - 2*x]])/(3136*Sqrt[7])}
{(3 + 5*x)^(5/2)/(Sqrt[1 - 2*x]*(2 + 3*x)^6), x, 7, -((1721*Sqrt[1 - 2*x]*Sqrt[3 + 5*x])/(105840*(2 + 3*x)^3)) - (12371*Sqrt[1 - 2*x]*Sqrt[3 + 5*x])/(592704*(2 + 3*x)^2) + (1948963*Sqrt[1 - 2*x]*Sqrt[3 + 5*x])/(8297856*(2 + 3*x)) - (157*Sqrt[1 - 2*x]*(3 + 5*x)^(3/2))/(5880*(2 + 3*x)^4) - (Sqrt[1 - 2*x]*(3 + 5*x)^(5/2))/(35*(2 + 3*x)^5) + (933031*ArcTan[(Sqrt[7]*Sqrt[3 + 5*x])/Sqrt[1 - 2*x]])/(307328*Sqrt[7])}
{(3 + 5*x)^(5/2)/(Sqrt[1 - 2*x]*(2 + 3*x)^7), x, 8, -((3037*Sqrt[1 - 2*x]*Sqrt[3 + 5*x])/(493920*(2 + 3*x)^4)) - (71369*Sqrt[1 - 2*x]*Sqrt[3 + 5*x])/(2963520*(2 + 3*x)^3) + (958171*Sqrt[1 - 2*x]*Sqrt[3 + 5*x])/(16595712*(2 + 3*x)^2) + (122343637*Sqrt[1 - 2*x]*Sqrt[3 + 5*x])/(232339968*(2 + 3*x)) - (17*Sqrt[1 - 2*x]*(3 + 5*x)^(3/2))/(980*(2 + 3*x)^5) - (Sqrt[1 - 2*x]*(3 + 5*x)^(5/2))/(42*(2 + 3*x)^6) + (52573169*ArcTan[(Sqrt[7]*Sqrt[3 + 5*x])/Sqrt[1 - 2*x]])/(8605184*Sqrt[7])}


(* ::Subsubsection::Closed:: *)
(*n<0*)


{(2 + 3*x)^4/(Sqrt[1 - 2*x]*Sqrt[3 + 5*x]), x, 5, (-949753*Sqrt[1 - 2*x]*Sqrt[3 + 5*x])/128000 - (9079*Sqrt[1 - 2*x]*(2 + 3*x)*Sqrt[3 + 5*x])/6400 - (259*Sqrt[1 - 2*x]*(2 + 3*x)^2*Sqrt[3 + 5*x])/800 - (3*Sqrt[1 - 2*x]*(2 + 3*x)^3*Sqrt[3 + 5*x])/40 + (10866247*ArcSin[Sqrt[2/11]*Sqrt[3 + 5*x]])/(128000*Sqrt[10])}
{(2 + 3*x)^3/(Sqrt[1 - 2*x]*Sqrt[3 + 5*x]), x, 4, (-799*Sqrt[1 - 2*x]*Sqrt[3 + 5*x])/320 - (Sqrt[1 - 2*x]*(2 + 3*x)^2*Sqrt[3 + 5*x])/10 - (3*Sqrt[1 - 2*x]*Sqrt[3 + 5*x]*(114 + 185*x))/400 + (44437*ArcSin[Sqrt[2/11]*Sqrt[3 + 5*x]])/(1600*Sqrt[10])}
{(2 + 3*x)^2/(Sqrt[1 - 2*x]*Sqrt[3 + 5*x]), x, 3, (-333*Sqrt[1 - 2*x]*Sqrt[3 + 5*x])/400 - (3*Sqrt[1 - 2*x]*(2 + 3*x)*Sqrt[3 + 5*x])/20 + (3827*ArcSin[Sqrt[2/11]*Sqrt[3 + 5*x]])/(400*Sqrt[10])}
{(2 + 3*x)/(Sqrt[1 - 2*x]*Sqrt[3 + 5*x]), x, 2, (-3*Sqrt[1 - 2*x]*Sqrt[3 + 5*x])/10 + (37*ArcSin[Sqrt[2/11]*Sqrt[3 + 5*x]])/(10*Sqrt[10])}
{1/(Sqrt[1 - 2*x]*Sqrt[3 + 5*x]), x, 1, Sqrt[2/5]*ArcSin[Sqrt[2/11]*Sqrt[3 + 5*x]]}
{1/(Sqrt[1 - 2*x]*(2 + 3*x)*Sqrt[3 + 5*x]), x, 1, (2*ArcTan[(Sqrt[7]*Sqrt[3 + 5*x])/Sqrt[1 - 2*x]])/Sqrt[7]}
{1/(Sqrt[1 - 2*x]*(2 + 3*x)^2*Sqrt[3 + 5*x]), x, 3, (3*Sqrt[1 - 2*x]*Sqrt[3 + 5*x])/(7*(2 + 3*x)) + (37*ArcTan[(Sqrt[7]*Sqrt[3 + 5*x])/Sqrt[1 - 2*x]])/(7*Sqrt[7])}
{1/(Sqrt[1 - 2*x]*(2 + 3*x)^3*Sqrt[3 + 5*x]), x, 4, (3*Sqrt[1 - 2*x]*Sqrt[3 + 5*x])/(14*(2 + 3*x)^2) + (333*Sqrt[1 - 2*x]*Sqrt[3 + 5*x])/(196*(2 + 3*x)) + (3827*ArcTan[(Sqrt[7]*Sqrt[3 + 5*x])/Sqrt[1 - 2*x]])/(196*Sqrt[7])}
{1/(Sqrt[1 - 2*x]*(2 + 3*x)^4*Sqrt[3 + 5*x]), x, 5, (Sqrt[1 - 2*x]*Sqrt[3 + 5*x])/(7*(2 + 3*x)^3) + (185*Sqrt[1 - 2*x]*Sqrt[3 + 5*x])/(196*(2 + 3*x)^2) + (19415*Sqrt[1 - 2*x]*Sqrt[3 + 5*x])/(2744*(2 + 3*x)) + (222185*ArcTan[(Sqrt[7]*Sqrt[3 + 5*x])/Sqrt[1 - 2*x]])/(2744*Sqrt[7])}


{(2 + 3*x)^4/(Sqrt[1 - 2*x]*(3 + 5*x)^(3/2)), x, 5, (7*Sqrt[1 - 2*x]*(2 + 3*x)^2)/(550*Sqrt[3 + 5*x]) - (Sqrt[1 - 2*x]*(2 + 3*x)^3)/(10*Sqrt[3 + 5*x]) - (139839*Sqrt[1 - 2*x]*Sqrt[3 + 5*x])/88000 - (63*Sqrt[1 - 2*x]*Sqrt[3 + 5*x]*(194 + 305*x))/22000 + (143283*ArcSin[Sqrt[2/11]*Sqrt[3 + 5*x]])/(8000*Sqrt[10])}
{(2 + 3*x)^3/(Sqrt[1 - 2*x]*(3 + 5*x)^(3/2)), x, 4, (Sqrt[1 - 2*x]*(2 + 3*x))/(44*Sqrt[3 + 5*x]) - (3*Sqrt[1 - 2*x]*(2 + 3*x)^2)/(20*Sqrt[3 + 5*x]) - (2337*Sqrt[1 - 2*x]*Sqrt[3 + 5*x])/4400 + (2493*ArcSin[Sqrt[2/11]*Sqrt[3 + 5*x]])/(400*Sqrt[10])}
{(2 + 3*x)^2/(Sqrt[1 - 2*x]*(3 + 5*x)^(3/2)), x, 3, -((2*Sqrt[1 - 2*x])/(275*Sqrt[3 + 5*x])) - (9/50)*Sqrt[1 - 2*x]*Sqrt[3 + 5*x] + (123*ArcSin[Sqrt[2/11]*Sqrt[3 + 5*x]])/(50*Sqrt[10])}
{(2 + 3*x)/(Sqrt[1 - 2*x]*(3 + 5*x)^(3/2)), x, 2, (-2*Sqrt[1 - 2*x])/(55*Sqrt[3 + 5*x]) + (3*Sqrt[2/5]*ArcSin[Sqrt[2/11]*Sqrt[3 + 5*x]])/5}
{1/(Sqrt[1 - 2*x]*(3 + 5*x)^(3/2)), x, 1, (-2*Sqrt[1 - 2*x])/(11*Sqrt[3 + 5*x])}
{1/(Sqrt[1 - 2*x]*(2 + 3*x)*(3 + 5*x)^(3/2)), x, 3, (-10*Sqrt[1 - 2*x])/(11*Sqrt[3 + 5*x]) - (6*ArcTan[(Sqrt[7]*Sqrt[3 + 5*x])/Sqrt[1 - 2*x]])/Sqrt[7]}
{1/(Sqrt[1 - 2*x]*(2 + 3*x)^2*(3 + 5*x)^(3/2)), x, 4, (-515*Sqrt[1 - 2*x])/(77*Sqrt[3 + 5*x]) + (3*Sqrt[1 - 2*x])/(7*(2 + 3*x)*Sqrt[3 + 5*x]) - (321*ArcTan[(Sqrt[7]*Sqrt[3 + 5*x])/Sqrt[1 - 2*x]])/(7*Sqrt[7])}
{1/(Sqrt[1 - 2*x]*(2 + 3*x)^3*(3 + 5*x)^(3/2)), x, 5, (-90415*Sqrt[1 - 2*x])/(2156*Sqrt[3 + 5*x]) + (3*Sqrt[1 - 2*x])/(14*(2 + 3*x)^2*Sqrt[3 + 5*x]) + (543*Sqrt[1 - 2*x])/(196*(2 + 3*x)*Sqrt[3 + 5*x]) - (56421*ArcTan[(Sqrt[7]*Sqrt[3 + 5*x])/Sqrt[1 - 2*x]])/(196*Sqrt[7])}
{1/(Sqrt[1 - 2*x]*(2 + 3*x)^4*(3 + 5*x)^(3/2)), x, 6, (-7396875*Sqrt[1 - 2*x])/(30184*Sqrt[3 + 5*x]) + Sqrt[1 - 2*x]/(7*(2 + 3*x)^3*Sqrt[3 + 5*x]) + (255*Sqrt[1 - 2*x])/(196*(2 + 3*x)^2*Sqrt[3 + 5*x]) + (44475*Sqrt[1 - 2*x])/(2744*(2 + 3*x)*Sqrt[3 + 5*x]) - (4616025*ArcTan[(Sqrt[7]*Sqrt[3 + 5*x])/Sqrt[1 - 2*x]])/(2744*Sqrt[7])}


{(2 + 3*x)^5/(Sqrt[1 - 2*x]*(3 + 5*x)^(5/2)), x, 6, (29*Sqrt[1 - 2*x]*(2 + 3*x)^3)/(1650*(3 + 5*x)^(3/2)) - (Sqrt[1 - 2*x]*(2 + 3*x)^4)/(10*(3 + 5*x)^(3/2)) - (511*Sqrt[1 - 2*x]*(2 + 3*x)^2)/(90750*Sqrt[3 + 5*x]) - (4802371*Sqrt[1 - 2*x]*Sqrt[3 + 5*x])/4840000 - (21*Sqrt[1 - 2*x]*Sqrt[3 + 5*x]*(21038 + 30535*x))/1210000 + (462357*ArcSin[Sqrt[2/11]*Sqrt[3 + 5*x]])/(40000*Sqrt[10])}
{(2 + 3*x)^4/(Sqrt[1 - 2*x]*(3 + 5*x)^(5/2)), x, 5, (91*Sqrt[1 - 2*x]*(2 + 3*x)^2)/(3300*(3 + 5*x)^(3/2)) - (3*Sqrt[1 - 2*x]*(2 + 3*x)^3)/(20*(3 + 5*x)^(3/2)) + (119*Sqrt[1 - 2*x]*(2 + 3*x))/(36300*Sqrt[3 + 5*x]) - (80633*Sqrt[1 - 2*x]*Sqrt[3 + 5*x])/242000 + (8127*ArcSin[Sqrt[2/11]*Sqrt[3 + 5*x]])/(2000*Sqrt[10])}
{(2 + 3*x)^3/(Sqrt[1 - 2*x]*(3 + 5*x)^(5/2)), x, 4, (19*Sqrt[1 - 2*x]*(2 + 3*x))/(330*(3 + 5*x)^(3/2)) - (3*Sqrt[1 - 2*x]*(2 + 3*x)^2)/(10*(3 + 5*x)^(3/2)) + (439*Sqrt[1 - 2*x])/(18150*Sqrt[3 + 5*x]) + (81*ArcSin[Sqrt[2/11]*Sqrt[3 + 5*x]])/(50*Sqrt[10])}
{(2 + 3*x)^2/(Sqrt[1 - 2*x]*(3 + 5*x)^(5/2)), x, 3, -((2*Sqrt[1 - 2*x])/(825*(3 + 5*x)^(3/2))) - (404*Sqrt[1 - 2*x])/(9075*Sqrt[3 + 5*x]) + (9/25)*Sqrt[2/5]*ArcSin[Sqrt[2/11]*Sqrt[3 + 5*x]]}
{(2 + 3*x)/(Sqrt[1 - 2*x]*(3 + 5*x)^(5/2)), x, 2, (-2*Sqrt[1 - 2*x])/(165*(3 + 5*x)^(3/2)) - (206*Sqrt[1 - 2*x])/(1815*Sqrt[3 + 5*x])}
{1/(Sqrt[1 - 2*x]*(3 + 5*x)^(5/2)), x, 2, (-2*Sqrt[1 - 2*x])/(33*(3 + 5*x)^(3/2)) - (8*Sqrt[1 - 2*x])/(363*Sqrt[3 + 5*x])}
{1/(Sqrt[1 - 2*x]*(2 + 3*x)*(3 + 5*x)^(5/2)), x, 4, (-10*Sqrt[1 - 2*x])/(33*(3 + 5*x)^(3/2)) + (950*Sqrt[1 - 2*x])/(363*Sqrt[3 + 5*x]) + (18*ArcTan[(Sqrt[7]*Sqrt[3 + 5*x])/Sqrt[1 - 2*x]])/Sqrt[7]}
{1/(Sqrt[1 - 2*x]*(2 + 3*x)^2*(3 + 5*x)^(5/2)), x, 5, (-845*Sqrt[1 - 2*x])/(231*(3 + 5*x)^(3/2)) + (3*Sqrt[1 - 2*x])/(7*(2 + 3*x)*(3 + 5*x)^(3/2)) + (84235*Sqrt[1 - 2*x])/(2541*Sqrt[3 + 5*x]) + (1593*ArcTan[(Sqrt[7]*Sqrt[3 + 5*x])/Sqrt[1 - 2*x]])/(7*Sqrt[7])}
{1/(Sqrt[1 - 2*x]*(2 + 3*x)^3*(3 + 5*x)^(5/2)), x, 6, (-207895*Sqrt[1 - 2*x])/(6468*(3 + 5*x)^(3/2)) + (3*Sqrt[1 - 2*x])/(14*(2 + 3*x)^2*(3 + 5*x)^(3/2)) + (753*Sqrt[1 - 2*x])/(196*(2 + 3*x)*(3 + 5*x)^(3/2)) + (20743985*Sqrt[1 - 2*x])/(71148*Sqrt[3 + 5*x]) + (392283*ArcTan[(Sqrt[7]*Sqrt[3 + 5*x])/Sqrt[1 - 2*x]])/(196*Sqrt[7])}
{1/(Sqrt[1 - 2*x]*(2 + 3*x)^4*(3 + 5*x)^(5/2)), x, 7, (-21891025*Sqrt[1 - 2*x])/(90552*(3 + 5*x)^(3/2)) + Sqrt[1 - 2*x]/(7*(2 + 3*x)^3*(3 + 5*x)^(3/2)) + (325*Sqrt[1 - 2*x])/(196*(2 + 3*x)^2*(3 + 5*x)^(3/2)) + (79335*Sqrt[1 - 2*x])/(2744*(2 + 3*x)*(3 + 5*x)^(3/2)) + (2184369575*Sqrt[1 - 2*x])/(996072*Sqrt[3 + 5*x]) + (41307885*ArcTan[(Sqrt[7]*Sqrt[3 + 5*x])/Sqrt[1 - 2*x]])/(2744*Sqrt[7])}


(* ::Subsection::Closed:: *)
(*Integrands of the form (a+b x)^m (c+d x)^(n/2) / (e+f x)^(3/2)*)


(* ::Subsubsection::Closed:: *)
(*n>0*)


{((2 + 3*x)^5*Sqrt[3 + 5*x])/(1 - 2*x)^(3/2), x, 7, (3192575743*Sqrt[1 - 2*x]*Sqrt[3 + 5*x])/5120000 + (847637*Sqrt[1 - 2*x]*(2 + 3*x)^2*Sqrt[3 + 5*x])/32000 + (10389*Sqrt[1 - 2*x]*(2 + 3*x)^3*Sqrt[3 + 5*x])/1600 + (33*Sqrt[1 - 2*x]*(2 + 3*x)^4*Sqrt[3 + 5*x])/20 + ((2 + 3*x)^5*Sqrt[3 + 5*x])/Sqrt[1 - 2*x] + (147*Sqrt[1 - 2*x]*Sqrt[3 + 5*x]*(1853322 + 3022165*x))/1280000 - (35439958001*ArcSin[Sqrt[2/11]*Sqrt[3 + 5*x]])/(5120000*Sqrt[10])}
{((2 + 3*x)^4*Sqrt[3 + 5*x])/(1 - 2*x)^(3/2), x, 6, (8050753*Sqrt[1 - 2*x]*Sqrt[3 + 5*x])/51200 + (15395*Sqrt[1 - 2*x]*(2 + 3*x)*Sqrt[3 + 5*x])/512 + (2203*Sqrt[1 - 2*x]*(2 + 3*x)^2*Sqrt[3 + 5*x])/320 + (27*Sqrt[1 - 2*x]*(2 + 3*x)^3*Sqrt[3 + 5*x])/16 + ((2 + 3*x)^4*Sqrt[3 + 5*x])/Sqrt[1 - 2*x] - (92108287*ArcSin[Sqrt[2/11]*Sqrt[3 + 5*x]])/(51200*Sqrt[10])}
{((2 + 3*x)^3*Sqrt[3 + 5*x])/(1 - 2*x)^(3/2), x, 5, (131833*Sqrt[1 - 2*x]*Sqrt[3 + 5*x])/3200 + (7*Sqrt[1 - 2*x]*(2 + 3*x)^2*Sqrt[3 + 5*x])/4 + ((2 + 3*x)^3*Sqrt[3 + 5*x])/Sqrt[1 - 2*x] + (3*Sqrt[1 - 2*x]*Sqrt[3 + 5*x]*(750 + 1223*x))/160 - (1463447*ArcSin[Sqrt[2/11]*Sqrt[3 + 5*x]])/(3200*Sqrt[10])}
{((2 + 3*x)^2*Sqrt[3 + 5*x])/(1 - 2*x)^(3/2), x, 4, (17951*Sqrt[1 - 2*x]*Sqrt[3 + 5*x])/1760 + (49*(3 + 5*x)^(3/2))/(22*Sqrt[1 - 2*x]) + (9/40)*Sqrt[1 - 2*x]*(3 + 5*x)^(3/2) - (17951*ArcSin[Sqrt[2/11]*Sqrt[3 + 5*x]])/(160*Sqrt[10])}
{((2 + 3*x)*Sqrt[3 + 5*x])/(1 - 2*x)^(3/2), x, 3, (103*Sqrt[1 - 2*x]*Sqrt[3 + 5*x])/44 + (7*(3 + 5*x)^(3/2))/(11*Sqrt[1 - 2*x]) - (103*ArcSin[Sqrt[2/11]*Sqrt[3 + 5*x]])/(4*Sqrt[10])}
{Sqrt[3 + 5*x]/(1 - 2*x)^(3/2), x, 2, Sqrt[3 + 5*x]/Sqrt[1 - 2*x] - Sqrt[5/2]*ArcSin[Sqrt[2/11]*Sqrt[3 + 5*x]]}
{Sqrt[3 + 5*x]/((1 - 2*x)^(3/2)*(2 + 3*x)), x, 2, (2*Sqrt[3 + 5*x])/(7*Sqrt[1 - 2*x]) - (2*ArcTan[(Sqrt[7]*Sqrt[3 + 5*x])/Sqrt[1 - 2*x]])/(7*Sqrt[7])}
{Sqrt[3 + 5*x]/((1 - 2*x)^(3/2)*(2 + 3*x)^2), x, 4, (2*Sqrt[3 + 5*x])/(7*Sqrt[1 - 2*x]*(2 + 3*x)) - (9*Sqrt[1 - 2*x]*Sqrt[3 + 5*x])/(49*(2 + 3*x)) + (29*ArcTan[(Sqrt[7]*Sqrt[3 + 5*x])/Sqrt[1 - 2*x]])/(49*Sqrt[7])}
{Sqrt[3 + 5*x]/((1 - 2*x)^(3/2)*(2 + 3*x)^3), x, 5, (2*Sqrt[3 + 5*x])/(7*Sqrt[1 - 2*x]*(2 + 3*x)^2) - (15*Sqrt[1 - 2*x]*Sqrt[3 + 5*x])/(98*(2 + 3*x)^2) + (15*Sqrt[1 - 2*x]*Sqrt[3 + 5*x])/(1372*(2 + 3*x)) + (1585*ArcTan[(Sqrt[7]*Sqrt[3 + 5*x])/Sqrt[1 - 2*x]])/(1372*Sqrt[7])}
{Sqrt[3 + 5*x]/((1 - 2*x)^(3/2)*(2 + 3*x)^4), x, 6, (2*Sqrt[3 + 5*x])/(7*Sqrt[1 - 2*x]*(2 + 3*x)^3) - (Sqrt[1 - 2*x]*Sqrt[3 + 5*x])/(7*(2 + 3*x)^3) - (5*Sqrt[1 - 2*x]*Sqrt[3 + 5*x])/(196*(2 + 3*x)^2) + (565*Sqrt[1 - 2*x]*Sqrt[3 + 5*x])/(2744*(2 + 3*x)) + (7435*ArcTan[(Sqrt[7]*Sqrt[3 + 5*x])/Sqrt[1 - 2*x]])/(2744*Sqrt[7])}
{Sqrt[3 + 5*x]/((1 - 2*x)^(3/2)*(2 + 3*x)^5), x, 7, (2*Sqrt[3 + 5*x])/(7*Sqrt[1 - 2*x]*(2 + 3*x)^4) - (27*Sqrt[1 - 2*x]*Sqrt[3 + 5*x])/(196*(2 + 3*x)^4) - (13*Sqrt[1 - 2*x]*Sqrt[3 + 5*x])/(392*(2 + 3*x)^3) + (835*Sqrt[1 - 2*x]*Sqrt[3 + 5*x])/(10976*(2 + 3*x)^2) + (107245*Sqrt[1 - 2*x]*Sqrt[3 + 5*x])/(153664*(2 + 3*x)) + (1244755*ArcTan[(Sqrt[7]*Sqrt[3 + 5*x])/Sqrt[1 - 2*x]])/(153664*Sqrt[7])}


{((2 + 3*x)^4*(3 + 5*x)^(3/2))/(1 - 2*x)^(3/2), x, 7, (1018114917*Sqrt[1 - 2*x]*Sqrt[3 + 5*x])/1024000 + (29429853*Sqrt[1 - 2*x]*(3 + 5*x)^(3/2))/256000 + (169017*Sqrt[1 - 2*x]*(2 + 3*x)*(3 + 5*x)^(3/2))/6400 + (10377*Sqrt[1 - 2*x]*(2 + 3*x)^2*(3 + 5*x)^(3/2))/1600 + (33*Sqrt[1 - 2*x]*(2 + 3*x)^3*(3 + 5*x)^(3/2))/20 + ((2 + 3*x)^4*(3 + 5*x)^(3/2))/Sqrt[1 - 2*x] - (11199264087*ArcSin[Sqrt[2/11]*Sqrt[3 + 5*x]])/(1024000*Sqrt[10])}
{((2 + 3*x)^3*(3 + 5*x)^(3/2))/(1 - 2*x)^(3/2), x, 6, (13246251*Sqrt[1 - 2*x]*Sqrt[3 + 5*x])/51200 + (392979*Sqrt[1 - 2*x]*(3 + 5*x)^(3/2))/12800 + (27*Sqrt[1 - 2*x]*(2 + 3*x)^2*(3 + 5*x)^(3/2))/16 + ((2 + 3*x)^3*(3 + 5*x)^(3/2))/Sqrt[1 - 2*x] + (3*Sqrt[1 - 2*x]*(3 + 5*x)^(3/2)*(1382 + 2199*x))/320 - (145708761*ArcSin[Sqrt[2/11]*Sqrt[3 + 5*x]])/(51200*Sqrt[10])}
{((2 + 3*x)^2*(3 + 5*x)^(3/2))/(1 - 2*x)^(3/2), x, 5, (42171/640)*Sqrt[1 - 2*x]*Sqrt[3 + 5*x] + (14057*Sqrt[1 - 2*x]*(3 + 5*x)^(3/2))/1760 + (49*(3 + 5*x)^(5/2))/(22*Sqrt[1 - 2*x]) + (3/20)*Sqrt[1 - 2*x]*(3 + 5*x)^(5/2) - (463881*ArcSin[Sqrt[2/11]*Sqrt[3 + 5*x]])/(640*Sqrt[10])}
{((2 + 3*x)*(3 + 5*x)^(3/2))/(1 - 2*x)^(3/2), x, 4, (519*Sqrt[1 - 2*x]*Sqrt[3 + 5*x])/32 + (173*Sqrt[1 - 2*x]*(3 + 5*x)^(3/2))/88 + (7*(3 + 5*x)^(5/2))/(11*Sqrt[1 - 2*x]) - (5709*ArcSin[Sqrt[2/11]*Sqrt[3 + 5*x]])/(32*Sqrt[10])}
{(3 + 5*x)^(3/2)/(1 - 2*x)^(3/2), x, 3, (15*Sqrt[1 - 2*x]*Sqrt[3 + 5*x])/4 + (3 + 5*x)^(3/2)/Sqrt[1 - 2*x] - (33*Sqrt[5/2]*ArcSin[Sqrt[2/11]*Sqrt[3 + 5*x]])/4}
{(3 + 5*x)^(3/2)/((1 - 2*x)^(3/2)*(2 + 3*x)), x, 5, (5*Sqrt[1 - 2*x]*Sqrt[3 + 5*x])/7 + (2*(3 + 5*x)^(3/2))/(7*Sqrt[1 - 2*x]) - (5*Sqrt[5/2]*ArcSin[Sqrt[2/11]*Sqrt[3 + 5*x]])/3 + (2*ArcTan[(Sqrt[7]*Sqrt[3 + 5*x])/Sqrt[1 - 2*x]])/(21*Sqrt[7])}
{(3 + 5*x)^(3/2)/((1 - 2*x)^(3/2)*(2 + 3*x)^2), x, 3, (3*Sqrt[1 - 2*x]*Sqrt[3 + 5*x])/(49*(2 + 3*x)) + (2*(3 + 5*x)^(3/2))/(7*Sqrt[1 - 2*x]*(2 + 3*x)) - (33*ArcTan[(Sqrt[7]*Sqrt[3 + 5*x])/Sqrt[1 - 2*x]])/(49*Sqrt[7])}
{(3 + 5*x)^(3/2)/((1 - 2*x)^(3/2)*(2 + 3*x)^3), x, 5, (5*Sqrt[1 - 2*x]*Sqrt[3 + 5*x])/(98*(2 + 3*x)^2) - (425*Sqrt[1 - 2*x]*Sqrt[3 + 5*x])/(1372*(2 + 3*x)) + (2*(3 + 5*x)^(3/2))/(7*Sqrt[1 - 2*x]*(2 + 3*x)^2) + (825*ArcTan[(Sqrt[7]*Sqrt[3 + 5*x])/Sqrt[1 - 2*x]])/(1372*Sqrt[7])}
{(3 + 5*x)^(3/2)/((1 - 2*x)^(3/2)*(2 + 3*x)^4), x, 6, (Sqrt[1 - 2*x]*Sqrt[3 + 5*x])/(21*(2 + 3*x)^3) - (145*Sqrt[1 - 2*x]*Sqrt[3 + 5*x])/(588*(2 + 3*x)^2) - (415*Sqrt[1 - 2*x]*Sqrt[3 + 5*x])/(8232*(2 + 3*x)) + (2*(3 + 5*x)^(3/2))/(7*Sqrt[1 - 2*x]*(2 + 3*x)^3) + (2805*ArcTan[(Sqrt[7]*Sqrt[3 + 5*x])/Sqrt[1 - 2*x]])/(2744*Sqrt[7])}
{(3 + 5*x)^(3/2)/((1 - 2*x)^(3/2)*(2 + 3*x)^5), x, 7, (9*Sqrt[1 - 2*x]*Sqrt[3 + 5*x])/(196*(2 + 3*x)^4) - (89*Sqrt[1 - 2*x]*Sqrt[3 + 5*x])/(392*(2 + 3*x)^3) - (745*Sqrt[1 - 2*x]*Sqrt[3 + 5*x])/(10976*(2 + 3*x)^2) + (16985*Sqrt[1 - 2*x]*Sqrt[3 + 5*x])/(153664*(2 + 3*x)) + (2*(3 + 5*x)^(3/2))/(7*Sqrt[1 - 2*x]*(2 + 3*x)^4) + (279015*ArcTan[(Sqrt[7]*Sqrt[3 + 5*x])/Sqrt[1 - 2*x]])/(153664*Sqrt[7])}


{((2 + 3*x)^4*(3 + 5*x)^(5/2))/(1 - 2*x)^(3/2), x, 8, (9738340821*Sqrt[1 - 2*x]*Sqrt[3 + 5*x])/1638400 + (295101237*Sqrt[1 - 2*x]*(3 + 5*x)^(3/2))/409600 + (5100983*Sqrt[1 - 2*x]*(3 + 5*x)^(5/2))/51200 + (62751*Sqrt[1 - 2*x]*(2 + 3*x)*(3 + 5*x)^(5/2))/2560 + (999*Sqrt[1 - 2*x]*(2 + 3*x)^2*(3 + 5*x)^(5/2))/160 + (13*Sqrt[1 - 2*x]*(2 + 3*x)^3*(3 + 5*x)^(5/2))/8 + ((2 + 3*x)^4*(3 + 5*x)^(5/2))/Sqrt[1 - 2*x] - (107121749031*ArcSin[Sqrt[2/11]*Sqrt[3 + 5*x]])/(1638400*Sqrt[10])}
{((2 + 3*x)^3*(3 + 5*x)^(5/2))/(1 - 2*x)^(3/2), x, 7, (321709971*Sqrt[1 - 2*x]*Sqrt[3 + 5*x])/204800 + (9748787*Sqrt[1 - 2*x]*(3 + 5*x)^(3/2))/51200 + (172209*Sqrt[1 - 2*x]*(3 + 5*x)^(5/2))/6400 + (33*Sqrt[1 - 2*x]*(2 + 3*x)^2*(3 + 5*x)^(5/2))/20 + ((2 + 3*x)^3*(3 + 5*x)^(5/2))/Sqrt[1 - 2*x] + (3*Sqrt[1 - 2*x]*(3 + 5*x)^(5/2)*(6602 + 10365*x))/1600 - (3538809681*ArcSin[Sqrt[2/11]*Sqrt[3 + 5*x]])/(204800*Sqrt[10])}
{((2 + 3*x)^2*(3 + 5*x)^(5/2))/(1 - 2*x)^(3/2), x, 6, (838101*Sqrt[1 - 2*x]*Sqrt[3 + 5*x])/2048 + (25397/512)*Sqrt[1 - 2*x]*(3 + 5*x)^(3/2) + (25397*Sqrt[1 - 2*x]*(3 + 5*x)^(5/2))/3520 + (49*(3 + 5*x)^(7/2))/(22*Sqrt[1 - 2*x]) + (9/80)*Sqrt[1 - 2*x]*(3 + 5*x)^(7/2) - (9219111*ArcSin[Sqrt[2/11]*Sqrt[3 + 5*x]])/(2048*Sqrt[10])}
{((2 + 3*x)*(3 + 5*x)^(5/2))/(1 - 2*x)^(3/2), x, 5, (13365*Sqrt[1 - 2*x]*Sqrt[3 + 5*x])/128 + (405*Sqrt[1 - 2*x]*(3 + 5*x)^(3/2))/32 + (81*Sqrt[1 - 2*x]*(3 + 5*x)^(5/2))/44 + (7*(3 + 5*x)^(7/2))/(11*Sqrt[1 - 2*x]) - (29403*Sqrt[5/2]*ArcSin[Sqrt[2/11]*Sqrt[3 + 5*x]])/128}
{(3 + 5*x)^(5/2)/(1 - 2*x)^(3/2), x, 4, (825*Sqrt[1 - 2*x]*Sqrt[3 + 5*x])/32 + (25*Sqrt[1 - 2*x]*(3 + 5*x)^(3/2))/8 + (3 + 5*x)^(5/2)/Sqrt[1 - 2*x] - (1815*Sqrt[5/2]*ArcSin[Sqrt[2/11]*Sqrt[3 + 5*x]])/32}
{(3 + 5*x)^(5/2)/((1 - 2*x)^(3/2)*(2 + 3*x)), x, 6, (505*Sqrt[1 - 2*x]*Sqrt[3 + 5*x])/84 + (5*Sqrt[1 - 2*x]*(3 + 5*x)^(3/2))/7 + (2*(3 + 5*x)^(5/2))/(7*Sqrt[1 - 2*x]) - (475*Sqrt[5/2]*ArcSin[Sqrt[2/11]*Sqrt[3 + 5*x]])/36 - (2*ArcTan[(Sqrt[7]*Sqrt[3 + 5*x])/Sqrt[1 - 2*x]])/(63*Sqrt[7])}
{(3 + 5*x)^(5/2)/((1 - 2*x)^(3/2)*(2 + 3*x)^2), x, 6, (160*Sqrt[1 - 2*x]*Sqrt[3 + 5*x])/147 + (3*Sqrt[1 - 2*x]*(3 + 5*x)^(3/2))/(49*(2 + 3*x)) + (2*(3 + 5*x)^(5/2))/(7*Sqrt[1 - 2*x]*(2 + 3*x)) - (25*Sqrt[5/2]*ArcSin[Sqrt[2/11]*Sqrt[3 + 5*x]])/9 + (169*ArcTan[(Sqrt[7]*Sqrt[3 + 5*x])/Sqrt[1 - 2*x]])/(441*Sqrt[7])}
{(3 + 5*x)^(5/2)/((1 - 2*x)^(3/2)*(2 + 3*x)^3), x, 4, (165*Sqrt[1 - 2*x]*Sqrt[3 + 5*x])/(1372*(2 + 3*x)) + (5*Sqrt[1 - 2*x]*(3 + 5*x)^(3/2))/(98*(2 + 3*x)^2) + (2*(3 + 5*x)^(5/2))/(7*Sqrt[1 - 2*x]*(2 + 3*x)^2) - (1815*ArcTan[(Sqrt[7]*Sqrt[3 + 5*x])/Sqrt[1 - 2*x]])/(1372*Sqrt[7])}
{(3 + 5*x)^(5/2)/((1 - 2*x)^(3/2)*(2 + 3*x)^4), x, 6, (155*Sqrt[1 - 2*x]*Sqrt[3 + 5*x])/(1764*(2 + 3*x)^2) - (12335*Sqrt[1 - 2*x]*Sqrt[3 + 5*x])/(24696*(2 + 3*x)) + (Sqrt[1 - 2*x]*(3 + 5*x)^(3/2))/(21*(2 + 3*x)^3) + (2*(3 + 5*x)^(5/2))/(7*Sqrt[1 - 2*x]*(2 + 3*x)^3) + (1815*ArcTan[(Sqrt[7]*Sqrt[3 + 5*x])/Sqrt[1 - 2*x]])/(2744*Sqrt[7])}
{(3 + 5*x)^(5/2)/((1 - 2*x)^(3/2)*(2 + 3*x)^5), x, 7, (277*Sqrt[1 - 2*x]*Sqrt[3 + 5*x])/(3528*(2 + 3*x)^3) - (38365*Sqrt[1 - 2*x]*Sqrt[3 + 5*x])/(98784*(2 + 3*x)^2) - (167155*Sqrt[1 - 2*x]*Sqrt[3 + 5*x])/(1382976*(2 + 3*x)) + (9*Sqrt[1 - 2*x]*(3 + 5*x)^(3/2))/(196*(2 + 3*x)^4) + (2*(3 + 5*x)^(5/2))/(7*Sqrt[1 - 2*x]*(2 + 3*x)^4) + (168795*ArcTan[(Sqrt[7]*Sqrt[3 + 5*x])/Sqrt[1 - 2*x]])/(153664*Sqrt[7])}
{(3 + 5*x)^(5/2)/((1 - 2*x)^(3/2)*(2 + 3*x)^6), x, 8, (1019*Sqrt[1 - 2*x]*Sqrt[3 + 5*x])/(13720*(2 + 3*x)^4) - (29297*Sqrt[1 - 2*x]*Sqrt[3 + 5*x])/(82320*(2 + 3*x)^3) - (55277*Sqrt[1 - 2*x]*Sqrt[3 + 5*x])/(460992*(2 + 3*x)^2) + (426781*Sqrt[1 - 2*x]*Sqrt[3 + 5*x])/(6453888*(2 + 3*x)) + (11*Sqrt[1 - 2*x]*(3 + 5*x)^(3/2))/(245*(2 + 3*x)^5) + (2*(3 + 5*x)^(5/2))/(7*Sqrt[1 - 2*x]*(2 + 3*x)^5) + (3474273*ArcTan[(Sqrt[7]*Sqrt[3 + 5*x])/Sqrt[1 - 2*x]])/(2151296*Sqrt[7])}


(* ::Subsubsection::Closed:: *)
(*n<0*)


{(2 + 3*x)^5/((1 - 2*x)^(3/2)*Sqrt[3 + 5*x]), x, 6, (288454593*Sqrt[1 - 2*x]*Sqrt[3 + 5*x])/2816000 + (76587*Sqrt[1 - 2*x]*(2 + 3*x)^2*Sqrt[3 + 5*x])/17600 + (2191*(2 + 3*x)^3*Sqrt[3 + 5*x])/(880*Sqrt[1 - 2*x]) - (3*(2 + 3*x)^4*Sqrt[3 + 5*x])/(40*Sqrt[1 - 2*x]) + (63*Sqrt[1 - 2*x]*Sqrt[3 + 5*x]*(390718 + 637135*x))/704000 - (291096141*ArcSin[Sqrt[2/11]*Sqrt[3 + 5*x]])/(256000*Sqrt[10])}
{(2 + 3*x)^4/((1 - 2*x)^(3/2)*Sqrt[3 + 5*x]), x, 5, (35505*Sqrt[1 - 2*x]*Sqrt[3 + 5*x])/1408 + (8487*Sqrt[1 - 2*x]*(2 + 3*x)*Sqrt[3 + 5*x])/1760 + (567*(2 + 3*x)^2*Sqrt[3 + 5*x])/(220*Sqrt[1 - 2*x]) - ((2 + 3*x)^3*Sqrt[3 + 5*x])/(10*Sqrt[1 - 2*x]) - (184641*ArcSin[Sqrt[2/11]*Sqrt[3 + 5*x]])/(640*Sqrt[10])}
{(2 + 3*x)^3/((1 - 2*x)^(3/2)*Sqrt[3 + 5*x]), x, 4, (54249*Sqrt[1 - 2*x]*Sqrt[3 + 5*x])/8800 + (1211*(2 + 3*x)*Sqrt[3 + 5*x])/(440*Sqrt[1 - 2*x]) - (3*(2 + 3*x)^2*Sqrt[3 + 5*x])/(20*Sqrt[1 - 2*x]) - (56421*ArcSin[Sqrt[2/11]*Sqrt[3 + 5*x]])/(800*Sqrt[10])}
{(2 + 3*x)^2/((1 - 2*x)^(3/2)*Sqrt[3 + 5*x]), x, 3, (49*Sqrt[3 + 5*x])/(22*Sqrt[1 - 2*x]) + (9/20)*Sqrt[1 - 2*x]*Sqrt[3 + 5*x] - (321*ArcSin[Sqrt[2/11]*Sqrt[3 + 5*x]])/(20*Sqrt[10])}
{(2 + 3*x)/((1 - 2*x)^(3/2)*Sqrt[3 + 5*x]), x, 2, (7*Sqrt[3 + 5*x])/(11*Sqrt[1 - 2*x]) - (3*ArcSin[Sqrt[2/11]*Sqrt[3 + 5*x]])/Sqrt[10]}
{1/((1 - 2*x)^(3/2)*Sqrt[3 + 5*x]), x, 1, (2*Sqrt[3 + 5*x])/(11*Sqrt[1 - 2*x])}
{1/((1 - 2*x)^(3/2)*(2 + 3*x)*Sqrt[3 + 5*x]), x, 3, (4*Sqrt[3 + 5*x])/(77*Sqrt[1 - 2*x]) + (6*ArcTan[(Sqrt[7]*Sqrt[3 + 5*x])/Sqrt[1 - 2*x]])/(7*Sqrt[7])}
{1/((1 - 2*x)^(3/2)*(2 + 3*x)^2*Sqrt[3 + 5*x]), x, 4, (4*Sqrt[3 + 5*x])/(77*Sqrt[1 - 2*x]*(2 + 3*x)) + (87*Sqrt[1 - 2*x]*Sqrt[3 + 5*x])/(539*(2 + 3*x)) + (123*ArcTan[(Sqrt[7]*Sqrt[3 + 5*x])/Sqrt[1 - 2*x]])/(49*Sqrt[7])}
{1/((1 - 2*x)^(3/2)*(2 + 3*x)^3*Sqrt[3 + 5*x]), x, 5, (4*Sqrt[3 + 5*x])/(77*Sqrt[1 - 2*x]*(2 + 3*x)^2) + (75*Sqrt[1 - 2*x]*Sqrt[3 + 5*x])/(1078*(2 + 3*x)^2) + (11685*Sqrt[1 - 2*x]*Sqrt[3 + 5*x])/(15092*(2 + 3*x)) + (12465*ArcTan[(Sqrt[7]*Sqrt[3 + 5*x])/Sqrt[1 - 2*x]])/(1372*Sqrt[7])}
{1/((1 - 2*x)^(3/2)*(2 + 3*x)^4*Sqrt[3 + 5*x]), x, 6, (4*Sqrt[3 + 5*x])/(77*Sqrt[1 - 2*x]*(2 + 3*x)^3) + (3*Sqrt[1 - 2*x]*Sqrt[3 + 5*x])/(77*(2 + 3*x)^3) + (915*Sqrt[1 - 2*x]*Sqrt[3 + 5*x])/(2156*(2 + 3*x)^2) + (98205*Sqrt[1 - 2*x]*Sqrt[3 + 5*x])/(30184*(2 + 3*x)) + (102345*ArcTan[(Sqrt[7]*Sqrt[3 + 5*x])/Sqrt[1 - 2*x]])/(2744*Sqrt[7])}
{1/((1 - 2*x)^(3/2)*(2 + 3*x)^5*Sqrt[3 + 5*x]), x, 7, (4*Sqrt[3 + 5*x])/(77*Sqrt[1 - 2*x]*(2 + 3*x)^4) + (51*Sqrt[1 - 2*x]*Sqrt[3 + 5*x])/(2156*(2 + 3*x)^4) + (1269*Sqrt[1 - 2*x]*Sqrt[3 + 5*x])/(4312*(2 + 3*x)^3) + (228645*Sqrt[1 - 2*x]*Sqrt[3 + 5*x])/(120736*(2 + 3*x)^2) + (23958315*Sqrt[1 - 2*x]*Sqrt[3 + 5*x])/(1690304*(2 + 3*x)) + (24922335*ArcTan[(Sqrt[7]*Sqrt[3 + 5*x])/Sqrt[1 - 2*x]])/(153664*Sqrt[7])}


{(2 + 3*x)^5/((1 - 2*x)^(3/2)*(3 + 5*x)^(3/2)), x, 6, (-2821*Sqrt[1 - 2*x]*(2 + 3*x)^2)/(12100*Sqrt[3 + 5*x]) + (567*(2 + 3*x)^3)/(220*Sqrt[1 - 2*x]*Sqrt[3 + 5*x]) - (2 + 3*x)^4/(10*Sqrt[1 - 2*x]*Sqrt[3 + 5*x]) + (30791901*Sqrt[1 - 2*x]*Sqrt[3 + 5*x])/1936000 + (294483*Sqrt[1 - 2*x]*(2 + 3*x)*Sqrt[3 + 5*x])/96800 - (2911419*ArcSin[Sqrt[2/11]*Sqrt[3 + 5*x]])/(16000*Sqrt[10])}
{(2 + 3*x)^4/((1 - 2*x)^(3/2)*(3 + 5*x)^(3/2)), x, 5, (1211*(2 + 3*x)^2)/(440*Sqrt[1 - 2*x]*Sqrt[3 + 5*x]) - (3*(2 + 3*x)^3)/(20*Sqrt[1 - 2*x]*Sqrt[3 + 5*x]) + (316941*Sqrt[1 - 2*x]*Sqrt[3 + 5*x])/96800 + (Sqrt[1 - 2*x]*(31586 + 54645*x))/(24200*Sqrt[3 + 5*x]) - (35451*ArcSin[Sqrt[2/11]*Sqrt[3 + 5*x]])/(800*Sqrt[10])}
{(2 + 3*x)^3/((1 - 2*x)^(3/2)*(3 + 5*x)^(3/2)), x, 4, (-3547*Sqrt[1 - 2*x])/(12100*Sqrt[3 + 5*x]) + (721*(2 + 3*x))/(220*Sqrt[1 - 2*x]*Sqrt[3 + 5*x]) - (3*(2 + 3*x)^2)/(10*Sqrt[1 - 2*x]*Sqrt[3 + 5*x]) - (999*ArcSin[Sqrt[2/11]*Sqrt[3 + 5*x]])/(100*Sqrt[10])}
{(2 + 3*x)^2/((1 - 2*x)^(3/2)*(3 + 5*x)^(3/2)), x, 3, 49/(22*Sqrt[1 - 2*x]*Sqrt[3 + 5*x]) - (1229*Sqrt[1 - 2*x])/(1210*Sqrt[3 + 5*x]) - (9*ArcSin[Sqrt[2/11]*Sqrt[3 + 5*x]])/(5*Sqrt[10])}
{(2 + 3*x)/((1 - 2*x)^(3/2)*(3 + 5*x)^(3/2)), x, 2, -2/(55*Sqrt[1 - 2*x]*Sqrt[3 + 5*x]) + (74*Sqrt[3 + 5*x])/(605*Sqrt[1 - 2*x])}
{1/((1 - 2*x)^(3/2)*(3 + 5*x)^(3/2)), x, 2, 2/(11*Sqrt[1 - 2*x]*Sqrt[3 + 5*x]) - (20*Sqrt[1 - 2*x])/(121*Sqrt[3 + 5*x])}
{1/((1 - 2*x)^(3/2)*(2 + 3*x)*(3 + 5*x)^(3/2)), x, 4, 4/(77*Sqrt[1 - 2*x]*Sqrt[3 + 5*x]) - (370*Sqrt[1 - 2*x])/(847*Sqrt[3 + 5*x]) - (18*ArcTan[(Sqrt[7]*Sqrt[3 + 5*x])/Sqrt[1 - 2*x]])/(7*Sqrt[7])}
{1/((1 - 2*x)^(3/2)*(2 + 3*x)^2*(3 + 5*x)^(3/2)), x, 5, (-17735*Sqrt[1 - 2*x])/(5929*Sqrt[3 + 5*x]) + 4/(77*Sqrt[1 - 2*x]*(2 + 3*x)*Sqrt[3 + 5*x]) + (87*Sqrt[1 - 2*x])/(539*(2 + 3*x)*Sqrt[3 + 5*x]) - (999*ArcTan[(Sqrt[7]*Sqrt[3 + 5*x])/Sqrt[1 - 2*x]])/(49*Sqrt[7])}
{1/((1 - 2*x)^(3/2)*(2 + 3*x)^3*(3 + 5*x)^(3/2)), x, 6, (-3125575*Sqrt[1 - 2*x])/(166012*Sqrt[3 + 5*x]) + 4/(77*Sqrt[1 - 2*x]*(2 + 3*x)^2*Sqrt[3 + 5*x]) + (75*Sqrt[1 - 2*x])/(1078*(2 + 3*x)^2*Sqrt[3 + 5*x]) + (18615*Sqrt[1 - 2*x])/(15092*(2 + 3*x)*Sqrt[3 + 5*x]) - (177255*ArcTan[(Sqrt[7]*Sqrt[3 + 5*x])/Sqrt[1 - 2*x]])/(1372*Sqrt[7])}
{1/((1 - 2*x)^(3/2)*(2 + 3*x)^4*(3 + 5*x)^(3/2)), x, 7, (-36657025*Sqrt[1 - 2*x])/(332024*Sqrt[3 + 5*x]) + 4/(77*Sqrt[1 - 2*x]*(2 + 3*x)^3*Sqrt[3 + 5*x]) + (3*Sqrt[1 - 2*x])/(77*(2 + 3*x)^3*Sqrt[3 + 5*x]) + (1245*Sqrt[1 - 2*x])/(2156*(2 + 3*x)^2*Sqrt[3 + 5*x]) + (220305*Sqrt[1 - 2*x])/(30184*(2 + 3*x)*Sqrt[3 + 5*x]) - (2079585*ArcTan[(Sqrt[7]*Sqrt[3 + 5*x])/Sqrt[1 - 2*x]])/(2744*Sqrt[7])}


{(2 + 3*x)^5/((1 - 2*x)^(3/2)*(3 + 5*x)^(5/2)), x, 6, (-17983*Sqrt[1 - 2*x]*(2 + 3*x)^2)/(72600*(3 + 5*x)^(3/2)) + (1211*(2 + 3*x)^3)/(440*Sqrt[1 - 2*x]*(3 + 5*x)^(3/2)) - (3*(2 + 3*x)^4)/(20*Sqrt[1 - 2*x]*(3 + 5*x)^(3/2)) + (10952053*Sqrt[1 - 2*x]*Sqrt[3 + 5*x])/5324000 + (7*Sqrt[1 - 2*x]*(467578 + 809265*x))/(3993000*Sqrt[3 + 5*x]) - (111321*ArcSin[Sqrt[2/11]*Sqrt[3 + 5*x]])/(4000*Sqrt[10])}
{(2 + 3*x)^4/((1 - 2*x)^(3/2)*(3 + 5*x)^(5/2)), x, 5, (721*(2 + 3*x)^2)/(220*Sqrt[1 - 2*x]*(3 + 5*x)^(3/2)) - (3*(2 + 3*x)^3)/(10*Sqrt[1 - 2*x]*(3 + 5*x)^(3/2)) - (168781*Sqrt[1 - 2*x])/(399300*Sqrt[3 + 5*x]) + (Sqrt[1 - 2*x]*(4706 + 11385*x))/(36300*(3 + 5*x)^(3/2)) - (621*ArcSin[Sqrt[2/11]*Sqrt[3 + 5*x]])/(100*Sqrt[10])}
{(2 + 3*x)^3/((1 - 2*x)^(3/2)*(3 + 5*x)^(5/2)), x, 5, (-8*Sqrt[1 - 2*x]*(2 + 3*x)^2)/(363*(3 + 5*x)^(3/2)) + (2*(2 + 3*x)^3)/(11*Sqrt[1 - 2*x]*(3 + 5*x)^(3/2)) + (3103*Sqrt[1 - 2*x]*Sqrt[3 + 5*x])/33275 + (4*Sqrt[1 - 2*x]*(158 + 321*x))/(19965*Sqrt[3 + 5*x]) - (27*ArcSin[Sqrt[2/11]*Sqrt[3 + 5*x]])/(25*Sqrt[10])}
{(2 + 3*x)^2/((1 - 2*x)^(3/2)*(3 + 5*x)^(5/2)), x, 3, 49/(22*Sqrt[1 - 2*x]*(3 + 5*x)^(3/2)) - (3679*Sqrt[1 - 2*x])/(3630*(3 + 5*x)^(3/2)) - (4091*Sqrt[1 - 2*x])/(19965*Sqrt[3 + 5*x])}
{(2 + 3*x)/((1 - 2*x)^(3/2)*(3 + 5*x)^(5/2)), x, 3, 7/(11*Sqrt[1 - 2*x]*(3 + 5*x)^(3/2)) - (107*Sqrt[1 - 2*x])/(363*(3 + 5*x)^(3/2)) - (428*Sqrt[1 - 2*x])/(3993*Sqrt[3 + 5*x])}
{1/((1 - 2*x)^(3/2)*(3 + 5*x)^(5/2)), x, 3, 2/(11*Sqrt[1 - 2*x]*(3 + 5*x)^(3/2)) - (40*Sqrt[1 - 2*x])/(363*(3 + 5*x)^(3/2)) - (160*Sqrt[1 - 2*x])/(3993*Sqrt[3 + 5*x])}
{1/((1 - 2*x)^(3/2)*(2 + 3*x)*(3 + 5*x)^(5/2)), x, 5, 4/(77*Sqrt[1 - 2*x]*(3 + 5*x)^(3/2)) - (410*Sqrt[1 - 2*x])/(2541*(3 + 5*x)^(3/2)) + (31030*Sqrt[1 - 2*x])/(27951*Sqrt[3 + 5*x]) + (54*ArcTan[(Sqrt[7]*Sqrt[3 + 5*x])/Sqrt[1 - 2*x]])/(7*Sqrt[7])}
{1/((1 - 2*x)^(3/2)*(2 + 3*x)^2*(3 + 5*x)^(5/2)), x, 6, (-28705*Sqrt[1 - 2*x])/(17787*(3 + 5*x)^(3/2)) + 4/(77*Sqrt[1 - 2*x]*(2 + 3*x)*(3 + 5*x)^(3/2)) + (87*Sqrt[1 - 2*x])/(539*(2 + 3*x)*(3 + 5*x)^(3/2)) + (2841815*Sqrt[1 - 2*x])/(195657*Sqrt[3 + 5*x]) + (4887*ArcTan[(Sqrt[7]*Sqrt[3 + 5*x])/Sqrt[1 - 2*x]])/(49*Sqrt[7])}
{1/((1 - 2*x)^(3/2)*(2 + 3*x)^3*(3 + 5*x)^(5/2)), x, 7, (-7090175*Sqrt[1 - 2*x])/(498036*(3 + 5*x)^(3/2)) + 4/(77*Sqrt[1 - 2*x]*(2 + 3*x)^2*(3 + 5*x)^(3/2)) + (75*Sqrt[1 - 2*x])/(1078*(2 + 3*x)^2*(3 + 5*x)^(3/2)) + (25545*Sqrt[1 - 2*x])/(15092*(2 + 3*x)*(3 + 5*x)^(3/2)) + (707286025*Sqrt[1 - 2*x])/(5478396*Sqrt[3 + 5*x]) + (1215945*ArcTan[(Sqrt[7]*Sqrt[3 + 5*x])/Sqrt[1 - 2*x]])/(1372*Sqrt[7])}


(* ::Subsection::Closed:: *)
(*Integrands of the form (a+b x)^m (c+d x)^(n/2) / (e+f x)^(5/2)*)


(* ::Subsubsection::Closed:: *)
(*n>0*)


{((2 + 3*x)^4*Sqrt[3 + 5*x])/(1 - 2*x)^(5/2), x, 6, (-12735719*Sqrt[1 - 2*x]*Sqrt[3 + 5*x])/70400 - (121769*Sqrt[1 - 2*x]*(2 + 3*x)*Sqrt[3 + 5*x])/3520 - (697*Sqrt[1 - 2*x]*(2 + 3*x)^2*Sqrt[3 + 5*x])/88 - (299*(2 + 3*x)^3*Sqrt[3 + 5*x])/(66*Sqrt[1 - 2*x]) + ((2 + 3*x)^4*Sqrt[3 + 5*x])/(3*(1 - 2*x)^(3/2)) + (13246251*ArcSin[Sqrt[2/11]*Sqrt[3 + 5*x]])/(6400*Sqrt[10])}
{((2 + 3*x)^3*Sqrt[3 + 5*x])/(1 - 2*x)^(5/2), x, 5, (-25073*Sqrt[1 - 2*x]*Sqrt[3 + 5*x])/704 - (233*(2 + 3*x)^2*Sqrt[3 + 5*x])/(66*Sqrt[1 - 2*x]) + ((2 + 3*x)^3*Sqrt[3 + 5*x])/(3*(1 - 2*x)^(3/2)) - (3*Sqrt[1 - 2*x]*Sqrt[3 + 5*x]*(3566 + 5815*x))/880 + (126513*ArcSin[Sqrt[2/11]*Sqrt[3 + 5*x]])/(320*Sqrt[10])}
{((2 + 3*x)^2*Sqrt[3 + 5*x])/(1 - 2*x)^(5/2), x, 4, (-(519/88))*Sqrt[1 - 2*x]*Sqrt[3 + 5*x] + (49*(3 + 5*x)^(3/2))/(66*(1 - 2*x)^(3/2)) - (21*(3 + 5*x)^(3/2))/(11*Sqrt[1 - 2*x]) + (519*ArcSin[Sqrt[2/11]*Sqrt[3 + 5*x]])/(8*Sqrt[10])}
{((2 + 3*x)*Sqrt[3 + 5*x])/(1 - 2*x)^(5/2), x, 3, (-3*Sqrt[3 + 5*x])/(2*Sqrt[1 - 2*x]) + (7*(3 + 5*x)^(3/2))/(33*(1 - 2*x)^(3/2)) + (3*Sqrt[5/2]*ArcSin[Sqrt[2/11]*Sqrt[3 + 5*x]])/2}
{Sqrt[3 + 5*x]/(1 - 2*x)^(5/2), x, 1, (2*(3 + 5*x)^(3/2))/(33*(1 - 2*x)^(3/2))}
{Sqrt[3 + 5*x]/((1 - 2*x)^(5/2)*(2 + 3*x)), x, 4, (2*Sqrt[3 + 5*x])/(21*(1 - 2*x)^(3/2)) + (128*Sqrt[3 + 5*x])/(1617*Sqrt[1 - 2*x]) - (6*ArcTan[(Sqrt[7]*Sqrt[3 + 5*x])/Sqrt[1 - 2*x]])/(49*Sqrt[7])}
{Sqrt[3 + 5*x]/((1 - 2*x)^(5/2)*(2 + 3*x)^2), x, 5, (2*Sqrt[3 + 5*x])/(21*(1 - 2*x)^(3/2)*(2 + 3*x)) + (260*Sqrt[3 + 5*x])/(1617*Sqrt[1 - 2*x]*(2 + 3*x)) - (425*Sqrt[1 - 2*x]*Sqrt[3 + 5*x])/(3773*(2 + 3*x)) + (75*ArcTan[(Sqrt[7]*Sqrt[3 + 5*x])/Sqrt[1 - 2*x]])/(343*Sqrt[7])}
{Sqrt[3 + 5*x]/((1 - 2*x)^(5/2)*(2 + 3*x)^3), x, 6, (2*Sqrt[3 + 5*x])/(21*(1 - 2*x)^(3/2)*(2 + 3*x)^2) + (8*Sqrt[3 + 5*x])/(33*Sqrt[1 - 2*x]*(2 + 3*x)^2) - (145*Sqrt[1 - 2*x]*Sqrt[3 + 5*x])/(1078*(2 + 3*x)^2) - (415*Sqrt[1 - 2*x]*Sqrt[3 + 5*x])/(15092*(2 + 3*x)) + (765*ArcTan[(Sqrt[7]*Sqrt[3 + 5*x])/Sqrt[1 - 2*x]])/(1372*Sqrt[7])}
{Sqrt[3 + 5*x]/((1 - 2*x)^(5/2)*(2 + 3*x)^4), x, 7, (2*Sqrt[3 + 5*x])/(21*(1 - 2*x)^(3/2)*(2 + 3*x)^3) + (524*Sqrt[3 + 5*x])/(1617*Sqrt[1 - 2*x]*(2 + 3*x)^3) - (89*Sqrt[1 - 2*x]*Sqrt[3 + 5*x])/(539*(2 + 3*x)^3) - (745*Sqrt[1 - 2*x]*Sqrt[3 + 5*x])/(15092*(2 + 3*x)^2) + (16985*Sqrt[1 - 2*x]*Sqrt[3 + 5*x])/(211288*(2 + 3*x)) + (25365*ArcTan[(Sqrt[7]*Sqrt[3 + 5*x])/Sqrt[1 - 2*x]])/(19208*Sqrt[7])}


{((2 + 3*x)^4*(3 + 5*x)^(3/2))/(1 - 2*x)^(5/2), x, 7, (-1626211523*Sqrt[1 - 2*x]*Sqrt[3 + 5*x])/1126400 - (47007627*Sqrt[1 - 2*x]*(3 + 5*x)^(3/2))/281600 - (269967*Sqrt[1 - 2*x]*(2 + 3*x)*(3 + 5*x)^(3/2))/7040 - (3315*Sqrt[1 - 2*x]*(2 + 3*x)^2*(3 + 5*x)^(3/2))/352 - (123*(2 + 3*x)^3*(3 + 5*x)^(3/2))/(22*Sqrt[1 - 2*x]) + ((2 + 3*x)^4*(3 + 5*x)^(3/2))/(3*(1 - 2*x)^(3/2)) + (1626211523*ArcSin[Sqrt[2/11]*Sqrt[3 + 5*x]])/(102400*Sqrt[10])}
{((2 + 3*x)^3*(3 + 5*x)^(3/2))/(1 - 2*x)^(5/2), x, 6, (-4246733*Sqrt[1 - 2*x]*Sqrt[3 + 5*x])/14080 - (125989*Sqrt[1 - 2*x]*(3 + 5*x)^(3/2))/3520 - (101*(2 + 3*x)^2*(3 + 5*x)^(3/2))/(22*Sqrt[1 - 2*x]) + ((2 + 3*x)^3*(3 + 5*x)^(3/2))/(3*(1 - 2*x)^(3/2)) - (Sqrt[1 - 2*x]*(3 + 5*x)^(3/2)*(6646 + 10575*x))/440 + (4246733*ArcSin[Sqrt[2/11]*Sqrt[3 + 5*x]])/(1280*Sqrt[10])}
{((2 + 3*x)^2*(3 + 5*x)^(3/2))/(1 - 2*x)^(5/2), x, 5, (-(40787/704))*Sqrt[1 - 2*x]*Sqrt[3 + 5*x] - (40787*Sqrt[1 - 2*x]*(3 + 5*x)^(3/2))/5808 + (49*(3 + 5*x)^(5/2))/(66*(1 - 2*x)^(3/2)) - (938*(3 + 5*x)^(5/2))/(363*Sqrt[1 - 2*x]) + (40787*ArcSin[Sqrt[2/11]*Sqrt[3 + 5*x]])/(64*Sqrt[10])}
{((2 + 3*x)*(3 + 5*x)^(3/2))/(1 - 2*x)^(5/2), x, 4, (-845*Sqrt[1 - 2*x]*Sqrt[3 + 5*x])/88 - (169*(3 + 5*x)^(3/2))/(66*Sqrt[1 - 2*x]) + (7*(3 + 5*x)^(5/2))/(33*(1 - 2*x)^(3/2)) + (169*Sqrt[5/2]*ArcSin[Sqrt[2/11]*Sqrt[3 + 5*x]])/8}
{(3 + 5*x)^(3/2)/(1 - 2*x)^(5/2), x, 3, (-5*Sqrt[3 + 5*x])/(2*Sqrt[1 - 2*x]) + (3 + 5*x)^(3/2)/(3*(1 - 2*x)^(3/2)) + (5*Sqrt[5/2]*ArcSin[Sqrt[2/11]*Sqrt[3 + 5*x]])/2}
{(3 + 5*x)^(3/2)/((1 - 2*x)^(5/2)*(2 + 3*x)), x, 3, (-2*Sqrt[3 + 5*x])/(49*Sqrt[1 - 2*x]) + (2*(3 + 5*x)^(3/2))/(21*(1 - 2*x)^(3/2)) + (2*ArcTan[(Sqrt[7]*Sqrt[3 + 5*x])/Sqrt[1 - 2*x]])/(49*Sqrt[7])}
{(3 + 5*x)^(3/2)/((1 - 2*x)^(5/2)*(2 + 3*x)^2), x, 5, (20*Sqrt[3 + 5*x])/(49*Sqrt[1 - 2*x]*(2 + 3*x)) - (55*Sqrt[1 - 2*x]*Sqrt[3 + 5*x])/(343*(2 + 3*x)) + (2*(3 + 5*x)^(3/2))/(21*(1 - 2*x)^(3/2)*(2 + 3*x)) - (95*ArcTan[(Sqrt[7]*Sqrt[3 + 5*x])/Sqrt[1 - 2*x]])/(343*Sqrt[7])}
{(3 + 5*x)^(3/2)/((1 - 2*x)^(5/2)*(2 + 3*x)^3), x, 6, (6*Sqrt[3 + 5*x])/(7*Sqrt[1 - 2*x]*(2 + 3*x)^2) - (5*Sqrt[1 - 2*x]*Sqrt[3 + 5*x])/(14*(2 + 3*x)^2) - (5*Sqrt[1 - 2*x]*Sqrt[3 + 5*x])/(28*(2 + 3*x)) + (2*(3 + 5*x)^(3/2))/(21*(1 - 2*x)^(3/2)*(2 + 3*x)^2) + (5*ArcTan[(Sqrt[7]*Sqrt[3 + 5*x])/Sqrt[1 - 2*x]])/(28*Sqrt[7])}
{(3 + 5*x)^(3/2)/((1 - 2*x)^(5/2)*(2 + 3*x)^4), x, 7, (64*Sqrt[3 + 5*x])/(49*Sqrt[1 - 2*x]*(2 + 3*x)^3) - (27*Sqrt[1 - 2*x]*Sqrt[3 + 5*x])/(49*(2 + 3*x)^3) - (285*Sqrt[1 - 2*x]*Sqrt[3 + 5*x])/(1372*(2 + 3*x)^2) - (1395*Sqrt[1 - 2*x]*Sqrt[3 + 5*x])/(19208*(2 + 3*x)) + (2*(3 + 5*x)^(3/2))/(21*(1 - 2*x)^(3/2)*(2 + 3*x)^3) + (9395*ArcTan[(Sqrt[7]*Sqrt[3 + 5*x])/Sqrt[1 - 2*x]])/(19208*Sqrt[7])}


{((2 + 3*x)^4*(3 + 5*x)^(5/2))/(1 - 2*x)^(5/2), x, 8, (-4270537963*Sqrt[1 - 2*x]*Sqrt[3 + 5*x])/409600 - (4270537963*Sqrt[1 - 2*x]*(3 + 5*x)^(3/2))/3379200 - (24606179*Sqrt[1 - 2*x]*(3 + 5*x)^(5/2))/140800 - (302699*Sqrt[1 - 2*x]*(2 + 3*x)*(3 + 5*x)^(5/2))/7040 - (4819*Sqrt[1 - 2*x]*(2 + 3*x)^2*(3 + 5*x)^(5/2))/440 - (439*(2 + 3*x)^3*(3 + 5*x)^(5/2))/(66*Sqrt[1 - 2*x]) + ((2 + 3*x)^4*(3 + 5*x)^(5/2))/(3*(1 - 2*x)^(3/2)) + (46975917593*ArcSin[Sqrt[2/11]*Sqrt[3 + 5*x]])/(409600*Sqrt[10])}
{((2 + 3*x)^3*(3 + 5*x)^(5/2))/(1 - 2*x)^(5/2), x, 7, (-9444023*Sqrt[1 - 2*x]*Sqrt[3 + 5*x])/4096 - (9444023*Sqrt[1 - 2*x]*(3 + 5*x)^(3/2))/33792 - (278043*Sqrt[1 - 2*x]*(3 + 5*x)^(5/2))/7040 - (373*(2 + 3*x)^2*(3 + 5*x)^(5/2))/(66*Sqrt[1 - 2*x]) + ((2 + 3*x)^3*(3 + 5*x)^(5/2))/(3*(1 - 2*x)^(3/2)) - (Sqrt[1 - 2*x]*(3 + 5*x)^(5/2)*(31978 + 50205*x))/1760 + (103884253*ArcSin[Sqrt[2/11]*Sqrt[3 + 5*x]])/(4096*Sqrt[10])}
{((2 + 3*x)^2*(3 + 5*x)^(5/2))/(1 - 2*x)^(5/2), x, 6, (-(123745/256))*Sqrt[1 - 2*x]*Sqrt[3 + 5*x] - (123745*Sqrt[1 - 2*x]*(3 + 5*x)^(3/2))/2112 - (24749*Sqrt[1 - 2*x]*(3 + 5*x)^(5/2))/2904 + (49*(3 + 5*x)^(7/2))/(66*(1 - 2*x)^(3/2)) - (1183*(3 + 5*x)^(7/2))/(363*Sqrt[1 - 2*x]) + (272239/256)*Sqrt[5/2]*ArcSin[Sqrt[2/11]*Sqrt[3 + 5*x]]}
{((2 + 3*x)*(3 + 5*x)^(5/2))/(1 - 2*x)^(5/2), x, 5, (-5975*Sqrt[1 - 2*x]*Sqrt[3 + 5*x])/64 - (5975*Sqrt[1 - 2*x]*(3 + 5*x)^(3/2))/528 - (239*(3 + 5*x)^(5/2))/(66*Sqrt[1 - 2*x]) + (7*(3 + 5*x)^(7/2))/(33*(1 - 2*x)^(3/2)) + (13145*Sqrt[5/2]*ArcSin[Sqrt[2/11]*Sqrt[3 + 5*x]])/64}
{(3 + 5*x)^(5/2)/(1 - 2*x)^(5/2), x, 4, (-125*Sqrt[1 - 2*x]*Sqrt[3 + 5*x])/8 - (25*(3 + 5*x)^(3/2))/(6*Sqrt[1 - 2*x]) + (3 + 5*x)^(5/2)/(3*(1 - 2*x)^(3/2)) + (275*Sqrt[5/2]*ArcSin[Sqrt[2/11]*Sqrt[3 + 5*x]])/8}
{(3 + 5*x)^(5/2)/((1 - 2*x)^(5/2)*(2 + 3*x)), x, 6, (-185*Sqrt[1 - 2*x]*Sqrt[3 + 5*x])/98 - (76*(3 + 5*x)^(3/2))/(147*Sqrt[1 - 2*x]) + (2*(3 + 5*x)^(5/2))/(21*(1 - 2*x)^(3/2)) + (25*Sqrt[5/2]*ArcSin[Sqrt[2/11]*Sqrt[3 + 5*x]])/6 - (2*ArcTan[(Sqrt[7]*Sqrt[3 + 5*x])/Sqrt[1 - 2*x]])/(147*Sqrt[7])}
{(3 + 5*x)^(5/2)/((1 - 2*x)^(5/2)*(2 + 3*x)^2), x, 4, (-5*Sqrt[1 - 2*x]*Sqrt[3 + 5*x])/(343*(2 + 3*x)) - (10*(3 + 5*x)^(3/2))/(147*Sqrt[1 - 2*x]*(2 + 3*x)) + (2*(3 + 5*x)^(5/2))/(21*(1 - 2*x)^(3/2)*(2 + 3*x)) + (55*ArcTan[(Sqrt[7]*Sqrt[3 + 5*x])/Sqrt[1 - 2*x]])/(343*Sqrt[7])}
{(3 + 5*x)^(5/2)/((1 - 2*x)^(5/2)*(2 + 3*x)^3), x, 6, (5*Sqrt[1 - 2*x]*Sqrt[3 + 5*x])/(98*(2 + 3*x)^2) - (285*Sqrt[1 - 2*x]*Sqrt[3 + 5*x])/(1372*(2 + 3*x)) + (8*(3 + 5*x)^(3/2))/(21*Sqrt[1 - 2*x]*(2 + 3*x)^2) + (2*(3 + 5*x)^(5/2))/(21*(1 - 2*x)^(3/2)*(2 + 3*x)^2) - (715*ArcTan[(Sqrt[7]*Sqrt[3 + 5*x])/Sqrt[1 - 2*x]])/(1372*Sqrt[7])}
{(3 + 5*x)^(5/2)/((1 - 2*x)^(5/2)*(2 + 3*x)^4), x, 7, (17*Sqrt[1 - 2*x]*Sqrt[3 + 5*x])/(147*(2 + 3*x)^3) - (2165*Sqrt[1 - 2*x]*Sqrt[3 + 5*x])/(4116*(2 + 3*x)^2) - (15755*Sqrt[1 - 2*x]*Sqrt[3 + 5*x])/(57624*(2 + 3*x)) + (122*(3 + 5*x)^(3/2))/(147*Sqrt[1 - 2*x]*(2 + 3*x)^3) + (2*(3 + 5*x)^(5/2))/(21*(1 - 2*x)^(3/2)*(2 + 3*x)^3) + (2585*ArcTan[(Sqrt[7]*Sqrt[3 + 5*x])/Sqrt[1 - 2*x]])/(19208*Sqrt[7])}
{(3 + 5*x)^(5/2)/((1 - 2*x)^(5/2)*(2 + 3*x)^5), x, 8, (247*Sqrt[1 - 2*x]*Sqrt[3 + 5*x])/(1372*(2 + 3*x)^4) - (2287*Sqrt[1 - 2*x]*Sqrt[3 + 5*x])/(2744*(2 + 3*x)^3) - (24335*Sqrt[1 - 2*x]*Sqrt[3 + 5*x])/(76832*(2 + 3*x)^2) - (139745*Sqrt[1 - 2*x]*Sqrt[3 + 5*x])/(1075648*(2 + 3*x)) + (188*(3 + 5*x)^(3/2))/(147*Sqrt[1 - 2*x]*(2 + 3*x)^4) + (2*(3 + 5*x)^(5/2))/(21*(1 - 2*x)^(3/2)*(2 + 3*x)^4) + (547745*ArcTan[(Sqrt[7]*Sqrt[3 + 5*x])/Sqrt[1 - 2*x]])/(1075648*Sqrt[7])}


(* ::Subsubsection::Closed:: *)
(*n<0*)


{(2 + 3*x)^5/((1 - 2*x)^(5/2)*Sqrt[3 + 5*x]), x, 6, (-90052591*Sqrt[1 - 2*x]*Sqrt[3 + 5*x])/774400 - (167363*(2 + 3*x)^2*Sqrt[3 + 5*x])/(14520*Sqrt[1 - 2*x]) + (721*(2 + 3*x)^3*Sqrt[3 + 5*x])/(660*(1 - 2*x)^(3/2)) - ((2 + 3*x)^4*Sqrt[3 + 5*x])/(10*(1 - 2*x)^(3/2)) - (3*Sqrt[1 - 2*x]*Sqrt[3 + 5*x]*(2561546 + 4177045*x))/193600 + (8261577*ArcSin[Sqrt[2/11]*Sqrt[3 + 5*x]])/(6400*Sqrt[10])}
{(2 + 3*x)^4/((1 - 2*x)^(5/2)*Sqrt[3 + 5*x]), x, 5, (-4282637*Sqrt[1 - 2*x]*Sqrt[3 + 5*x])/193600 + (1673*(2 + 3*x)^2*Sqrt[3 + 5*x])/(1320*(1 - 2*x)^(3/2)) - (3*(2 + 3*x)^3*Sqrt[3 + 5*x])/(20*(1 - 2*x)^(3/2)) - (7*Sqrt[3 + 5*x]*(76466 + 124737*x))/(29040*Sqrt[1 - 2*x]) + (392283*ArcSin[Sqrt[2/11]*Sqrt[3 + 5*x]])/(1600*Sqrt[10])}
{(2 + 3*x)^3/((1 - 2*x)^(5/2)*Sqrt[3 + 5*x]), x, 4, (-117929*Sqrt[3 + 5*x])/(14520*Sqrt[1 - 2*x]) + (1183*(2 + 3*x)*Sqrt[3 + 5*x])/(660*(1 - 2*x)^(3/2)) - (3*(2 + 3*x)^2*Sqrt[3 + 5*x])/(10*(1 - 2*x)^(3/2)) + (1593*ArcSin[Sqrt[2/11]*Sqrt[3 + 5*x]])/(40*Sqrt[10])}
{(2 + 3*x)^2/((1 - 2*x)^(5/2)*Sqrt[3 + 5*x]), x, 3, (49*Sqrt[3 + 5*x])/(66*(1 - 2*x)^(3/2)) - (448*Sqrt[3 + 5*x])/(363*Sqrt[1 - 2*x]) + (9*ArcSin[Sqrt[2/11]*Sqrt[3 + 5*x]])/(2*Sqrt[10])}
{(2 + 3*x)/((1 - 2*x)^(5/2)*Sqrt[3 + 5*x]), x, 2, (7*Sqrt[3 + 5*x])/(33*(1 - 2*x)^(3/2)) - (29*Sqrt[3 + 5*x])/(363*Sqrt[1 - 2*x])}
{1/((1 - 2*x)^(5/2)*Sqrt[3 + 5*x]), x, 2, (2*Sqrt[3 + 5*x])/(33*(1 - 2*x)^(3/2)) + (20*Sqrt[3 + 5*x])/(363*Sqrt[1 - 2*x])}
{1/((1 - 2*x)^(5/2)*(2 + 3*x)*Sqrt[3 + 5*x]), x, 4, (4*Sqrt[3 + 5*x])/(231*(1 - 2*x)^(3/2)) + (676*Sqrt[3 + 5*x])/(17787*Sqrt[1 - 2*x]) + (18*ArcTan[(Sqrt[7]*Sqrt[3 + 5*x])/Sqrt[1 - 2*x]])/(49*Sqrt[7])}
{1/((1 - 2*x)^(5/2)*(2 + 3*x)^2*Sqrt[3 + 5*x]), x, 5, (4*Sqrt[3 + 5*x])/(231*(1 - 2*x)^(3/2)*(2 + 3*x)) + (940*Sqrt[3 + 5*x])/(17787*Sqrt[1 - 2*x]*(2 + 3*x)) + (2195*Sqrt[1 - 2*x]*Sqrt[3 + 5*x])/(41503*(2 + 3*x)) + (405*ArcTan[(Sqrt[7]*Sqrt[3 + 5*x])/Sqrt[1 - 2*x]])/(343*Sqrt[7])}
{1/((1 - 2*x)^(5/2)*(2 + 3*x)^3*Sqrt[3 + 5*x]), x, 6, (4*Sqrt[3 + 5*x])/(231*(1 - 2*x)^(3/2)*(2 + 3*x)^2) + (172*Sqrt[3 + 5*x])/(2541*Sqrt[1 - 2*x]*(2 + 3*x)^2) + (85*Sqrt[1 - 2*x]*Sqrt[3 + 5*x])/(11858*(2 + 3*x)^2) + (57595*Sqrt[1 - 2*x]*Sqrt[3 + 5*x])/(166012*(2 + 3*x)) + (5805*ArcTan[(Sqrt[7]*Sqrt[3 + 5*x])/Sqrt[1 - 2*x]])/(1372*Sqrt[7])}
{1/((1 - 2*x)^(5/2)*(2 + 3*x)^4*Sqrt[3 + 5*x]), x, 7, (4*Sqrt[3 + 5*x])/(231*(1 - 2*x)^(3/2)*(2 + 3*x)^3) + (1468*Sqrt[3 + 5*x])/(17787*Sqrt[1 - 2*x]*(2 + 3*x)^3) - (73*Sqrt[1 - 2*x]*Sqrt[3 + 5*x])/(5929*(2 + 3*x)^3) + (30535*Sqrt[1 - 2*x]*Sqrt[3 + 5*x])/(166012*(2 + 3*x)^2) + (3471145*Sqrt[1 - 2*x]*Sqrt[3 + 5*x])/(2324168*(2 + 3*x)) + (330255*ArcTan[(Sqrt[7]*Sqrt[3 + 5*x])/Sqrt[1 - 2*x]])/(19208*Sqrt[7])}


{(2 + 3*x)^5/((1 - 2*x)^(5/2)*(3 + 5*x)^(3/2)), x, 6, (270463*Sqrt[1 - 2*x]*(2 + 3*x))/(319440*Sqrt[3 + 5*x]) - (273749*(2 + 3*x)^2)/(29040*Sqrt[1 - 2*x]*Sqrt[3 + 5*x]) + (1673*(2 + 3*x)^3)/(1320*(1 - 2*x)^(3/2)*Sqrt[3 + 5*x]) - (3*(2 + 3*x)^4)/(20*(1 - 2*x)^(3/2)*Sqrt[3 + 5*x]) - (28291441*Sqrt[1 - 2*x]*Sqrt[3 + 5*x])/2129600 + (243189*ArcSin[Sqrt[2/11]*Sqrt[3 + 5*x]])/(1600*Sqrt[10])}
{(2 + 3*x)^4/((1 - 2*x)^(5/2)*(3 + 5*x)^(3/2)), x, 5, (-212417*Sqrt[1 - 2*x])/(798600*Sqrt[3 + 5*x]) + (1183*(2 + 3*x)^2)/(660*(1 - 2*x)^(3/2)*Sqrt[3 + 5*x]) - (3*(2 + 3*x)^3)/(10*(1 - 2*x)^(3/2)*Sqrt[3 + 5*x]) - (7*(31106 + 53757*x))/(14520*Sqrt[1 - 2*x]*Sqrt[3 + 5*x]) + (4887*ArcSin[Sqrt[2/11]*Sqrt[3 + 5*x]])/(200*Sqrt[10])}
{(2 + 3*x)^3/((1 - 2*x)^(5/2)*(3 + 5*x)^(3/2)), x, 5, (50*Sqrt[1 - 2*x]*(2 + 3*x))/(3993*Sqrt[3 + 5*x]) - (58*(2 + 3*x)^2)/(363*Sqrt[1 - 2*x]*Sqrt[3 + 5*x]) + (2*(2 + 3*x)^3)/(33*(1 - 2*x)^(3/2)*Sqrt[3 + 5*x]) - (3103*Sqrt[1 - 2*x]*Sqrt[3 + 5*x])/13310 + (27*ArcSin[Sqrt[2/11]*Sqrt[3 + 5*x]])/(10*Sqrt[10])}
{(2 + 3*x)^2/((1 - 2*x)^(5/2)*(3 + 5*x)^(3/2)), x, 3, 49/(66*(1 - 2*x)^(3/2)*Sqrt[3 + 5*x]) - 1237/(3630*Sqrt[1 - 2*x]*Sqrt[3 + 5*x]) - (793*Sqrt[3 + 5*x])/(19965*Sqrt[1 - 2*x])}
{(2 + 3*x)/((1 - 2*x)^(5/2)*(3 + 5*x)^(3/2)), x, 3, -2/(55*(1 - 2*x)^(3/2)*Sqrt[3 + 5*x]) + (82*Sqrt[3 + 5*x])/(1815*(1 - 2*x)^(3/2)) + (164*Sqrt[3 + 5*x])/(3993*Sqrt[1 - 2*x])}
{1/((1 - 2*x)^(5/2)*(3 + 5*x)^(3/2)), x, 3, 2/(33*(1 - 2*x)^(3/2)*Sqrt[3 + 5*x]) + 40/(363*Sqrt[1 - 2*x]*Sqrt[3 + 5*x]) - (400*Sqrt[1 - 2*x])/(3993*Sqrt[3 + 5*x])}
{1/((1 - 2*x)^(5/2)*(2 + 3*x)*(3 + 5*x)^(3/2)), x, 5, 4/(231*(1 - 2*x)^(3/2)*Sqrt[3 + 5*x]) + 956/(17787*Sqrt[1 - 2*x]*Sqrt[3 + 5*x]) - (42230*Sqrt[1 - 2*x])/(195657*Sqrt[3 + 5*x]) - (54*ArcTan[(Sqrt[7]*Sqrt[3 + 5*x])/Sqrt[1 - 2*x]])/(49*Sqrt[7])}
{1/((1 - 2*x)^(5/2)*(2 + 3*x)^2*(3 + 5*x)^(3/2)), x, 6, (-1840225*Sqrt[1 - 2*x])/(1369599*Sqrt[3 + 5*x]) + 4/(231*(1 - 2*x)^(3/2)*(2 + 3*x)*Sqrt[3 + 5*x]) + 1220/(17787*Sqrt[1 - 2*x]*(2 + 3*x)*Sqrt[3 + 5*x]) + (1915*Sqrt[1 - 2*x])/(41503*(2 + 3*x)*Sqrt[3 + 5*x]) - (3105*ArcTan[(Sqrt[7]*Sqrt[3 + 5*x])/Sqrt[1 - 2*x]])/(343*Sqrt[7])}
{1/((1 - 2*x)^(5/2)*(2 + 3*x)^3*(3 + 5*x)^(3/2)), x, 7, (-46307675*Sqrt[1 - 2*x])/(5478396*Sqrt[3 + 5*x]) + 4/(231*(1 - 2*x)^(3/2)*(2 + 3*x)^2*Sqrt[3 + 5*x]) + 212/(2541*Sqrt[1 - 2*x]*(2 + 3*x)^2*Sqrt[3 + 5*x]) + (5*Sqrt[1 - 2*x])/(11858*(2 + 3*x)^2*Sqrt[3 + 5*x]) + (89945*Sqrt[1 - 2*x])/(166012*(2 + 3*x)*Sqrt[3 + 5*x]) - (79515*ArcTan[(Sqrt[7]*Sqrt[3 + 5*x])/Sqrt[1 - 2*x]])/(1372*Sqrt[7])}


{(2 + 3*x)^6/((1 - 2*x)^(5/2)*(3 + 5*x)^(5/2)), x, 7, (1332779*Sqrt[1 - 2*x]*(2 + 3*x)^2)/(1597200*(3 + 5*x)^(3/2)) - (89943*(2 + 3*x)^3)/(9680*Sqrt[1 - 2*x]*(3 + 5*x)^(3/2)) + (1673*(2 + 3*x)^4)/(1320*(1 - 2*x)^(3/2)*(3 + 5*x)^(3/2)) - (3*(2 + 3*x)^5)/(20*(1 - 2*x)^(3/2)*(3 + 5*x)^(3/2)) + (9214471*Sqrt[1 - 2*x]*(2 + 3*x))/(17569200*Sqrt[3 + 5*x]) - (964268137*Sqrt[1 - 2*x]*Sqrt[3 + 5*x])/117128000 + (753543*ArcSin[Sqrt[2/11]*Sqrt[3 + 5*x]])/(8000*Sqrt[10])}
{(2 + 3*x)^5/((1 - 2*x)^(5/2)*(3 + 5*x)^(5/2)), x, 6, (111719*Sqrt[1 - 2*x]*(2 + 3*x))/(159720*(3 + 5*x)^(3/2)) - (38003*(2 + 3*x)^2)/(4840*Sqrt[1 - 2*x]*(3 + 5*x)^(3/2)) + (1183*(2 + 3*x)^3)/(660*(1 - 2*x)^(3/2)*(3 + 5*x)^(3/2)) - (3*(2 + 3*x)^4)/(10*(1 - 2*x)^(3/2)*(3 + 5*x)^(3/2)) + (3831323*Sqrt[1 - 2*x])/(8784600*Sqrt[3 + 5*x]) + (2997*ArcSin[Sqrt[2/11]*Sqrt[3 + 5*x]])/(200*Sqrt[10])}
{(2 + 3*x)^4/((1 - 2*x)^(5/2)*(3 + 5*x)^(5/2)), x, 6, (50*Sqrt[1 - 2*x]*(2 + 3*x)^2)/(3993*(3 + 5*x)^(3/2)) - (18*(2 + 3*x)^3)/(121*Sqrt[1 - 2*x]*(3 + 5*x)^(3/2)) + (2*(2 + 3*x)^4)/(33*(1 - 2*x)^(3/2)*(3 + 5*x)^(3/2)) + (1058*Sqrt[1 - 2*x]*(2 + 3*x))/(219615*Sqrt[3 + 5*x]) - (100159*Sqrt[1 - 2*x]*Sqrt[3 + 5*x])/732050 + (81*ArcSin[Sqrt[2/11]*Sqrt[3 + 5*x]])/(50*Sqrt[10])}
{(2 + 3*x)^3/((1 - 2*x)^(5/2)*(3 + 5*x)^(5/2)), x, 4, 49/(121*Sqrt[1 - 2*x]*(3 + 5*x)^(3/2)) - (3679*Sqrt[1 - 2*x])/(19965*(3 + 5*x)^(3/2)) + (2*(2 + 3*x)^3)/(33*(1 - 2*x)^(3/2)*(3 + 5*x)^(3/2)) - (8182*Sqrt[1 - 2*x])/(219615*Sqrt[3 + 5*x])}
{(2 + 3*x)^2/((1 - 2*x)^(5/2)*(3 + 5*x)^(5/2)), x, 4, 49/(66*(1 - 2*x)^(3/2)*(3 + 5*x)^(3/2)) + 14/(121*Sqrt[1 - 2*x]*(3 + 5*x)^(3/2)) - (1649*Sqrt[1 - 2*x])/(7986*(3 + 5*x)^(3/2)) - (3298*Sqrt[1 - 2*x])/(43923*Sqrt[3 + 5*x])}
{(2 + 3*x)/((1 - 2*x)^(5/2)*(3 + 5*x)^(5/2)), x, 4, -2/(165*(1 - 2*x)^(3/2)*(3 + 5*x)^(3/2)) + 74/(1815*(1 - 2*x)^(3/2)*Sqrt[3 + 5*x]) + 296/(3993*Sqrt[1 - 2*x]*Sqrt[3 + 5*x]) - (2960*Sqrt[1 - 2*x])/(43923*Sqrt[3 + 5*x])}
{1/((1 - 2*x)^(5/2)*(3 + 5*x)^(5/2)), x, 4, 2/(33*(1 - 2*x)^(3/2)*(3 + 5*x)^(3/2)) + 20/(121*Sqrt[1 - 2*x]*(3 + 5*x)^(3/2)) - (400*Sqrt[1 - 2*x])/(3993*(3 + 5*x)^(3/2)) - (1600*Sqrt[1 - 2*x])/(43923*Sqrt[3 + 5*x])}
{1/((1 - 2*x)^(5/2)*(2 + 3*x)*(3 + 5*x)^(5/2)), x, 6, 4/(231*(1 - 2*x)^(3/2)*(3 + 5*x)^(3/2)) + 412/(5929*Sqrt[1 - 2*x]*(3 + 5*x)^(3/2)) - (19130*Sqrt[1 - 2*x])/(195657*(3 + 5*x)^(3/2)) + (1001590*Sqrt[1 - 2*x])/(2152227*Sqrt[3 + 5*x]) + (162*ArcTan[(Sqrt[7]*Sqrt[3 + 5*x])/Sqrt[1 - 2*x]])/(49*Sqrt[7])}
{1/((1 - 2*x)^(5/2)*(2 + 3*x)^2*(3 + 5*x)^(5/2)), x, 7, (-985525*Sqrt[1 - 2*x])/(1369599*(3 + 5*x)^(3/2)) + 4/(231*(1 - 2*x)^(3/2)*(2 + 3*x)*(3 + 5*x)^(3/2)) + 500/(5929*Sqrt[1 - 2*x]*(2 + 3*x)*(3 + 5*x)^(3/2)) + (1635*Sqrt[1 - 2*x])/(41503*(2 + 3*x)*(3 + 5*x)^(3/2)) + (95783075*Sqrt[1 - 2*x])/(15065589*Sqrt[3 + 5*x]) + (14985*ArcTan[(Sqrt[7]*Sqrt[3 + 5*x])/Sqrt[1 - 2*x]])/(343*Sqrt[7])}
{1/((1 - 2*x)^(5/2)*(2 + 3*x)^3*(3 + 5*x)^(5/2)), x, 8, (-34551425*Sqrt[1 - 2*x])/(5478396*(3 + 5*x)^(3/2)) + 4/(231*(1 - 2*x)^(3/2)*(2 + 3*x)^2*(3 + 5*x)^(3/2)) + 12/(121*Sqrt[1 - 2*x]*(2 + 3*x)^2*(3 + 5*x)^(3/2)) - (75*Sqrt[1 - 2*x])/(11858*(2 + 3*x)^2*(3 + 5*x)^(3/2)) + (122295*Sqrt[1 - 2*x])/(166012*(2 + 3*x)*(3 + 5*x)^(3/2)) + (3443814775*Sqrt[1 - 2*x])/(60262356*Sqrt[3 + 5*x]) + (538245*ArcTan[(Sqrt[7]*Sqrt[3 + 5*x])/Sqrt[1 - 2*x]])/(1372*Sqrt[7])}


(* ::Section::Closed:: *)
(*Integrands of the form (a+b x)^(m/2) (c+d x)^(n/2) (e+f x)^(p/2)*)


(* ::Subsection::Closed:: *)
(*Integrands of the form (a+b x)^(m/2) (c+d x)^(n/2) (e+f x)^(1/2)*)


(* ::Subsubsection::Closed:: *)
(*n<0*)


{Sqrt[1 - 2*x]*(2 + 3*x)^(5/2)*Sqrt[3 + 5*x], x, 9, (-175111*Sqrt[1 - 2*x]*Sqrt[2 + 3*x]*Sqrt[3 + 5*x])/236250 - (1244*Sqrt[1 - 2*x]*Sqrt[2 + 3*x]*(3 + 5*x)^(3/2))/13125 - (23*Sqrt[1 - 2*x]*(2 + 3*x)^(3/2)*(3 + 5*x)^(3/2))/1575 + (2*Sqrt[1 - 2*x]*(2 + 3*x)^(5/2)*(3 + 5*x)^(3/2))/45 - (2911577*EllipticE[ArcSin[Sqrt[5/11]*Sqrt[1 - 2*x]], 33/35])/(50625*Sqrt[35]) + (167647*EllipticF[ArcSin[Sqrt[3/7]*Sqrt[1 - 2*x]], 35/33])/(101250*Sqrt[33])}
{Sqrt[1 - 2*x]*(2 + 3*x)^(3/2)*Sqrt[3 + 5*x], x, 8, (-823*Sqrt[1 - 2*x]*Sqrt[2 + 3*x]*Sqrt[3 + 5*x])/2625 - (27*Sqrt[1 - 2*x]*Sqrt[2 + 3*x]*(3 + 5*x)^(3/2))/875 + (2*Sqrt[1 - 2*x]*(2 + 3*x)^(3/2)*(3 + 5*x)^(3/2))/35 - (55019*EllipticE[ArcSin[Sqrt[5/11]*Sqrt[1 - 2*x]], 33/35])/(2250*Sqrt[35]) + (796*EllipticF[ArcSin[Sqrt[3/7]*Sqrt[1 - 2*x]], 35/33])/(1125*Sqrt[33])}
{Sqrt[1 - 2*x]*Sqrt[2 + 3*x]*Sqrt[3 + 5*x], x, 7, (-31*Sqrt[1 - 2*x]*Sqrt[2 + 3*x]*Sqrt[3 + 5*x])/225 + (2*Sqrt[1 - 2*x]*Sqrt[2 + 3*x]*(3 + 5*x)^(3/2))/25 - (1159*Sqrt[7/5]*EllipticE[ArcSin[Sqrt[5/11]*Sqrt[1 - 2*x]], 33/35])/675 + (259*EllipticF[ArcSin[Sqrt[3/7]*Sqrt[1 - 2*x]], 35/33])/(675*Sqrt[33])}
{(Sqrt[1 - 2*x]*Sqrt[3 + 5*x])/Sqrt[2 + 3*x], x, 6, (2*Sqrt[1 - 2*x]*Sqrt[2 + 3*x]*Sqrt[3 + 5*x])/9 - (37*Sqrt[7/5]*EllipticE[ArcSin[Sqrt[5/11]*Sqrt[1 - 2*x]], 33/35])/27 + (28*EllipticF[ArcSin[Sqrt[3/7]*Sqrt[1 - 2*x]], 35/33])/(27*Sqrt[33])}
{(Sqrt[1 - 2*x]*Sqrt[3 + 5*x])/(2 + 3*x)^(3/2), x, 6, (-2*Sqrt[1 - 2*x]*Sqrt[3 + 5*x])/(3*Sqrt[2 + 3*x]) + (4*Sqrt[35]*EllipticE[ArcSin[Sqrt[5/11]*Sqrt[1 - 2*x]], 33/35])/9 - (74*EllipticF[ArcSin[Sqrt[3/7]*Sqrt[1 - 2*x]], 35/33])/(9*Sqrt[33])}
{(Sqrt[1 - 2*x]*Sqrt[3 + 5*x])/(2 + 3*x)^(5/2), x, 7, (-2*Sqrt[1 - 2*x]*Sqrt[3 + 5*x])/(9*(2 + 3*x)^(3/2)) + (74*Sqrt[1 - 2*x]*Sqrt[3 + 5*x])/(63*Sqrt[2 + 3*x]) - (74*Sqrt[5/7]*EllipticE[ArcSin[Sqrt[5/11]*Sqrt[1 - 2*x]], 33/35])/27 + (40*EllipticF[ArcSin[Sqrt[3/7]*Sqrt[1 - 2*x]], 35/33])/(27*Sqrt[33])}
{(Sqrt[1 - 2*x]*Sqrt[3 + 5*x])/(2 + 3*x)^(7/2), x, 8, (-2*Sqrt[1 - 2*x]*Sqrt[3 + 5*x])/(15*(2 + 3*x)^(5/2)) + (74*Sqrt[1 - 2*x]*Sqrt[3 + 5*x])/(315*(2 + 3*x)^(3/2)) + (4636*Sqrt[1 - 2*x]*Sqrt[3 + 5*x])/(2205*Sqrt[2 + 3*x]) - (4636*EllipticE[ArcSin[Sqrt[5/11]*Sqrt[1 - 2*x]], 33/35])/(189*Sqrt[35]) + (148*EllipticF[ArcSin[Sqrt[3/7]*Sqrt[1 - 2*x]], 35/33])/(189*Sqrt[33])}
{(Sqrt[1 - 2*x]*Sqrt[3 + 5*x])/(2 + 3*x)^(9/2), x, 9, -((2*Sqrt[1 - 2*x]*Sqrt[3 + 5*x])/(21*(2 + 3*x)^(7/2))) + (74*Sqrt[1 - 2*x]*Sqrt[3 + 5*x])/(735*(2 + 3*x)^(5/2)) + (3184*Sqrt[1 - 2*x]*Sqrt[3 + 5*x])/(5145*(2 + 3*x)^(3/2)) + (220076*Sqrt[1 - 2*x]*Sqrt[3 + 5*x])/(36015*Sqrt[2 + 3*x]) - (220076*EllipticE[ArcSin[Sqrt[5/11]*Sqrt[1 - 2*x]], 33/35])/(3087*Sqrt[35]) + (6368*EllipticF[ArcSin[Sqrt[3/7]*Sqrt[1 - 2*x]], 35/33])/(3087*Sqrt[33])}


{Sqrt[1 - 2*x]*(2 + 3*x)^(5/2)*(3 + 5*x)^(3/2), x, 10, (-11346991*Sqrt[1 - 2*x]*Sqrt[2 + 3*x]*Sqrt[3 + 5*x])/3898125 - (342971*Sqrt[1 - 2*x]*Sqrt[2 + 3*x]*(3 + 5*x)^(3/2))/866250 - (543*Sqrt[1 - 2*x]*Sqrt[2 + 3*x]*(3 + 5*x)^(5/2))/9625 - (23*Sqrt[1 - 2*x]*(2 + 3*x)^(3/2)*(3 + 5*x)^(5/2))/2475 + (2*Sqrt[1 - 2*x]*(2 + 3*x)^(5/2)*(3 + 5*x)^(5/2))/55 - (1508889271*EllipticE[ArcSin[Sqrt[5/11]*Sqrt[1 - 2*x]], 33/35])/(6682500*Sqrt[35]) + (21713939*EllipticF[ArcSin[Sqrt[3/7]*Sqrt[1 - 2*x]], 35/33])/(3341250*Sqrt[33])}
{Sqrt[1 - 2*x]*(2 + 3*x)^(3/2)*(3 + 5*x)^(3/2), x, 9, (-160297*Sqrt[1 - 2*x]*Sqrt[2 + 3*x]*Sqrt[3 + 5*x])/141750 - (1208*Sqrt[1 - 2*x]*Sqrt[2 + 3*x]*(3 + 5*x)^(3/2))/7875 - (3*Sqrt[1 - 2*x]*Sqrt[2 + 3*x]*(3 + 5*x)^(5/2))/175 + (2*Sqrt[1 - 2*x]*(2 + 3*x)^(3/2)*(3 + 5*x)^(5/2))/45 - (5327983*EllipticE[ArcSin[Sqrt[5/11]*Sqrt[1 - 2*x]], 33/35])/(60750*Sqrt[35]) + (153319*EllipticF[ArcSin[Sqrt[3/7]*Sqrt[1 - 2*x]], 35/33])/(60750*Sqrt[33])}
{Sqrt[1 - 2*x]*Sqrt[2 + 3*x]*(3 + 5*x)^(3/2), x, 8, (-2252*Sqrt[1 - 2*x]*Sqrt[2 + 3*x]*Sqrt[3 + 5*x])/4725 - (31*Sqrt[1 - 2*x]*Sqrt[2 + 3*x]*(3 + 5*x)^(3/2))/525 + (2*Sqrt[1 - 2*x]*Sqrt[2 + 3*x]*(3 + 5*x)^(5/2))/35 - (148831*EllipticE[ArcSin[Sqrt[5/11]*Sqrt[1 - 2*x]], 33/35])/(4050*Sqrt[35]) + (2129*EllipticF[ArcSin[Sqrt[3/7]*Sqrt[1 - 2*x]], 35/33])/(2025*Sqrt[33])}
{(Sqrt[1 - 2*x]*(3 + 5*x)^(3/2))/Sqrt[2 + 3*x], x, 7, (-41*Sqrt[1 - 2*x]*Sqrt[2 + 3*x]*Sqrt[3 + 5*x])/135 + (2*Sqrt[1 - 2*x]*Sqrt[2 + 3*x]*(3 + 5*x)^(3/2))/15 - (974*Sqrt[7/5]*EllipticE[ArcSin[Sqrt[5/11]*Sqrt[1 - 2*x]], 33/35])/405 + (119*EllipticF[ArcSin[Sqrt[3/7]*Sqrt[1 - 2*x]], 35/33])/(405*Sqrt[33])}
{(Sqrt[1 - 2*x]*(3 + 5*x)^(3/2))/(2 + 3*x)^(3/2), x, 7, (40*Sqrt[1 - 2*x]*Sqrt[2 + 3*x]*Sqrt[3 + 5*x])/27 - (2*Sqrt[1 - 2*x]*(3 + 5*x)^(3/2))/(3*Sqrt[2 + 3*x]) - (49*Sqrt[35]*EllipticE[ArcSin[Sqrt[5/11]*Sqrt[1 - 2*x]], 33/35])/81 + (362*EllipticF[ArcSin[Sqrt[3/7]*Sqrt[1 - 2*x]], 35/33])/(81*Sqrt[33])}
{(Sqrt[1 - 2*x]*(3 + 5*x)^(3/2))/(2 + 3*x)^(5/2), x, 7, (-214*Sqrt[1 - 2*x]*Sqrt[3 + 5*x])/(189*Sqrt[2 + 3*x]) - (2*Sqrt[1 - 2*x]*(3 + 5*x)^(3/2))/(9*(2 + 3*x)^(3/2)) + (494*Sqrt[5/7]*EllipticE[ArcSin[Sqrt[5/11]*Sqrt[1 - 2*x]], 33/35])/81 - (1150*EllipticF[ArcSin[Sqrt[3/7]*Sqrt[1 - 2*x]], 35/33])/(81*Sqrt[33])}
{(Sqrt[1 - 2*x]*(3 + 5*x)^(3/2))/(2 + 3*x)^(7/2), x, 8, (-214*Sqrt[1 - 2*x]*Sqrt[3 + 5*x])/(945*(2 + 3*x)^(3/2)) + (8314*Sqrt[1 - 2*x]*Sqrt[3 + 5*x])/(6615*Sqrt[2 + 3*x]) - (2*Sqrt[1 - 2*x]*(3 + 5*x)^(3/2))/(15*(2 + 3*x)^(5/2)) - (8314*EllipticE[ArcSin[Sqrt[5/11]*Sqrt[1 - 2*x]], 33/35])/(567*Sqrt[35]) + (1252*EllipticF[ArcSin[Sqrt[3/7]*Sqrt[1 - 2*x]], 35/33])/(567*Sqrt[33])}
{(Sqrt[1 - 2*x]*(3 + 5*x)^(3/2))/(2 + 3*x)^(9/2), x, 9, -((214*Sqrt[1 - 2*x]*Sqrt[3 + 5*x])/(2205*(2 + 3*x)^(5/2))) + (8578*Sqrt[1 - 2*x]*Sqrt[3 + 5*x])/(46305*(2 + 3*x)^(3/2)) + (475592*Sqrt[1 - 2*x]*Sqrt[3 + 5*x])/(324135*Sqrt[2 + 3*x]) - (2*Sqrt[1 - 2*x]*(3 + 5*x)^(3/2))/(21*(2 + 3*x)^(7/2)) - (475592*EllipticE[ArcSin[Sqrt[5/11]*Sqrt[1 - 2*x]], 33/35])/(27783*Sqrt[35]) + (17156*EllipticF[ArcSin[Sqrt[3/7]*Sqrt[1 - 2*x]], 35/33])/(27783*Sqrt[33])}
{(Sqrt[1 - 2*x]*(3 + 5*x)^(3/2))/(2 + 3*x)^(11/2), x, 10, -((214*Sqrt[1 - 2*x]*Sqrt[3 + 5*x])/(3969*(2 + 3*x)^(7/2))) + (8842*Sqrt[1 - 2*x]*Sqrt[3 + 5*x])/(138915*(2 + 3*x)^(5/2)) + (332372*Sqrt[1 - 2*x]*Sqrt[3 + 5*x])/(972405*(2 + 3*x)^(3/2)) + (22738708*Sqrt[1 - 2*x]*Sqrt[3 + 5*x])/(6806835*Sqrt[2 + 3*x]) - (2*Sqrt[1 - 2*x]*(3 + 5*x)^(3/2))/(27*(2 + 3*x)^(9/2)) - (22738708*EllipticE[ArcSin[Sqrt[5/11]*Sqrt[1 - 2*x]], 33/35])/(583443*Sqrt[35]) + (664744*EllipticF[ArcSin[Sqrt[3/7]*Sqrt[1 - 2*x]], 35/33])/(583443*Sqrt[33])}


{Sqrt[1 - 2*x]*(2 + 3*x)^(5/2)*(3 + 5*x)^(5/2), x, 11, (-493825477*Sqrt[1 - 2*x]*Sqrt[2 + 3*x]*Sqrt[3 + 5*x])/40540500 - (1865989*Sqrt[1 - 2*x]*Sqrt[2 + 3*x]*(3 + 5*x)^(3/2))/1126125 - (564731*Sqrt[1 - 2*x]*Sqrt[2 + 3*x]*(3 + 5*x)^(5/2))/2252250 - (2014*Sqrt[1 - 2*x]*Sqrt[2 + 3*x]*(3 + 5*x)^(7/2))/53625 - (23*Sqrt[1 - 2*x]*(2 + 3*x)^(3/2)*(3 + 5*x)^(7/2))/3575 + (2*Sqrt[1 - 2*x]*(2 + 3*x)^(5/2)*(3 + 5*x)^(7/2))/65 - (16416987253*EllipticE[ArcSin[Sqrt[5/11]*Sqrt[1 - 2*x]], 33/35])/(17374500*Sqrt[35]) + (472506679*EllipticF[ArcSin[Sqrt[3/7]*Sqrt[1 - 2*x]], 35/33])/(17374500*Sqrt[33])}
{Sqrt[1 - 2*x]*(2 + 3*x)^(3/2)*(3 + 5*x)^(5/2), x, 10, (-465127*Sqrt[1 - 2*x]*Sqrt[2 + 3*x]*Sqrt[3 + 5*x])/103950 - (7031*Sqrt[1 - 2*x]*Sqrt[2 + 3*x]*(3 + 5*x)^(3/2))/11550 - (177*Sqrt[1 - 2*x]*Sqrt[2 + 3*x]*(3 + 5*x)^(5/2))/1925 - (3*Sqrt[1 - 2*x]*Sqrt[2 + 3*x]*(3 + 5*x)^(7/2))/275 + (2*Sqrt[1 - 2*x]*(2 + 3*x)^(3/2)*(3 + 5*x)^(7/2))/55 - (30926081*EllipticE[ArcSin[Sqrt[5/11]*Sqrt[1 - 2*x]], 33/35])/(89100*Sqrt[35]) + (222527*EllipticF[ArcSin[Sqrt[3/7]*Sqrt[1 - 2*x]], 35/33])/(22275*Sqrt[33])}
{Sqrt[1 - 2*x]*Sqrt[2 + 3*x]*(3 + 5*x)^(5/2), x, 9, (-29357*Sqrt[1 - 2*x]*Sqrt[2 + 3*x]*Sqrt[3 + 5*x])/17010 - (223*Sqrt[1 - 2*x]*Sqrt[2 + 3*x]*(3 + 5*x)^(3/2))/945 - (31*Sqrt[1 - 2*x]*Sqrt[2 + 3*x]*(3 + 5*x)^(5/2))/945 + (2*Sqrt[1 - 2*x]*Sqrt[2 + 3*x]*(3 + 5*x)^(7/2))/45 - (488149*EllipticE[ArcSin[Sqrt[5/11]*Sqrt[1 - 2*x]], 33/35])/(3645*Sqrt[35]) + (28109*EllipticF[ArcSin[Sqrt[3/7]*Sqrt[1 - 2*x]], 35/33])/(7290*Sqrt[33])}
{(Sqrt[1 - 2*x]*(3 + 5*x)^(5/2))/Sqrt[2 + 3*x], x, 8, (-131*Sqrt[1 - 2*x]*Sqrt[2 + 3*x]*Sqrt[3 + 5*x])/189 - (Sqrt[1 - 2*x]*Sqrt[2 + 3*x]*(3 + 5*x)^(3/2))/7 + (2*Sqrt[1 - 2*x]*Sqrt[2 + 3*x]*(3 + 5*x)^(5/2))/21 - (9013*EllipticE[ArcSin[Sqrt[5/11]*Sqrt[1 - 2*x]], 33/35])/(162*Sqrt[35]) + (134*EllipticF[ArcSin[Sqrt[3/7]*Sqrt[1 - 2*x]], 35/33])/(81*Sqrt[33])}
{(Sqrt[1 - 2*x]*(3 + 5*x)^(5/2))/(2 + 3*x)^(3/2), x, 8, -(Sqrt[1 - 2*x]*Sqrt[2 + 3*x]*Sqrt[3 + 5*x]) + (4*Sqrt[1 - 2*x]*Sqrt[2 + 3*x]*(3 + 5*x)^(3/2))/3 - (2*Sqrt[1 - 2*x]*(3 + 5*x)^(5/2))/(3*Sqrt[2 + 3*x]) - 3*Sqrt[7/5]*EllipticE[ArcSin[Sqrt[5/11]*Sqrt[1 - 2*x]], 33/35] - EllipticF[ArcSin[Sqrt[3/7]*Sqrt[1 - 2*x]], 35/33]/Sqrt[33]}
{(Sqrt[1 - 2*x]*(3 + 5*x)^(5/2))/(2 + 3*x)^(5/2), x, 8, (2470*Sqrt[1 - 2*x]*Sqrt[2 + 3*x]*Sqrt[3 + 5*x])/567 - (118*Sqrt[1 - 2*x]*(3 + 5*x)^(3/2))/(63*Sqrt[2 + 3*x]) - (2*Sqrt[1 - 2*x]*(3 + 5*x)^(5/2))/(9*(2 + 3*x)^(3/2)) - (2209*Sqrt[5/7]*EllipticE[ArcSin[Sqrt[5/11]*Sqrt[1 - 2*x]], 33/35])/243 + (2960*EllipticF[ArcSin[Sqrt[3/7]*Sqrt[1 - 2*x]], 35/33])/(243*Sqrt[33])}
{(Sqrt[1 - 2*x]*(3 + 5*x)^(5/2))/(2 + 3*x)^(7/2), x, 8, (-12758*Sqrt[1 - 2*x]*Sqrt[3 + 5*x])/(6615*Sqrt[2 + 3*x]) - (118*Sqrt[1 - 2*x]*(3 + 5*x)^(3/2))/(315*(2 + 3*x)^(3/2)) - (2*Sqrt[1 - 2*x]*(3 + 5*x)^(5/2))/(15*(2 + 3*x)^(5/2)) + (31588*EllipticE[ArcSin[Sqrt[5/11]*Sqrt[1 - 2*x]], 33/35])/(567*Sqrt[35]) - (13834*EllipticF[ArcSin[Sqrt[3/7]*Sqrt[1 - 2*x]], 35/33])/(567*Sqrt[33])}
{(Sqrt[1 - 2*x]*(3 + 5*x)^(5/2))/(2 + 3*x)^(9/2), x, 9, -((4282*Sqrt[1 - 2*x]*Sqrt[3 + 5*x])/(15435*(2 + 3*x)^(3/2))) + (173482*Sqrt[1 - 2*x]*Sqrt[3 + 5*x])/(108045*Sqrt[2 + 3*x]) - (118*Sqrt[1 - 2*x]*(3 + 5*x)^(3/2))/(735*(2 + 3*x)^(5/2)) - (2*Sqrt[1 - 2*x]*(3 + 5*x)^(5/2))/(21*(2 + 3*x)^(7/2)) - (173482*EllipticE[ArcSin[Sqrt[5/11]*Sqrt[1 - 2*x]], 33/35])/(9261*Sqrt[35]) + (32176*EllipticF[ArcSin[Sqrt[3/7]*Sqrt[1 - 2*x]], 35/33])/(9261*Sqrt[33])}
{(Sqrt[1 - 2*x]*(3 + 5*x)^(5/2))/(2 + 3*x)^(11/2), x, 10, -((12934*Sqrt[1 - 2*x]*Sqrt[3 + 5*x])/(138915*(2 + 3*x)^(5/2))) + (568318*Sqrt[1 - 2*x]*Sqrt[3 + 5*x])/(2917215*(2 + 3*x)^(3/2)) + (27198452*Sqrt[1 - 2*x]*Sqrt[3 + 5*x])/(20420505*Sqrt[2 + 3*x]) - (118*Sqrt[1 - 2*x]*(3 + 5*x)^(3/2))/(1323*(2 + 3*x)^(7/2)) - (2*Sqrt[1 - 2*x]*(3 + 5*x)^(5/2))/(27*(2 + 3*x)^(9/2)) - (27198452*EllipticE[ArcSin[Sqrt[5/11]*Sqrt[1 - 2*x]], 33/35])/(1750329*Sqrt[35]) + (1136636*EllipticF[ArcSin[Sqrt[3/7]*Sqrt[1 - 2*x]], 35/33])/(1750329*Sqrt[33])}
{(Sqrt[1 - 2*x]*(3 + 5*x)^(5/2))/(2 + 3*x)^(13/2), x, 11, -((13022*Sqrt[1 - 2*x]*Sqrt[3 + 5*x])/(305613*(2 + 3*x)^(7/2))) + (627806*Sqrt[1 - 2*x]*Sqrt[3 + 5*x])/(10696455*(2 + 3*x)^(5/2)) + (19417096*Sqrt[1 - 2*x]*Sqrt[3 + 5*x])/(74875185*(2 + 3*x)^(3/2)) + (1305025844*Sqrt[1 - 2*x]*Sqrt[3 + 5*x])/(524126295*Sqrt[2 + 3*x]) - (118*Sqrt[1 - 2*x]*(3 + 5*x)^(3/2))/(2079*(2 + 3*x)^(9/2)) - (2*Sqrt[1 - 2*x]*(3 + 5*x)^(5/2))/(33*(2 + 3*x)^(11/2)) - (1305025844*EllipticE[ArcSin[Sqrt[5/11]*Sqrt[1 - 2*x]], 33/35])/(44925111*Sqrt[35]) + (38834192*EllipticF[ArcSin[Sqrt[3/7]*Sqrt[1 - 2*x]], 35/33])/(44925111*Sqrt[33])}


(* ::Subsubsection::Closed:: *)
(*n>0*)


{(a + b*x)^(1/2)/((c + d*x)^(1/2)*(e + f*x)^(1/2)), x, 2, (2*Sqrt[(-d)*e + c*f]*Sqrt[a + b*x]*Sqrt[(d*(e + f*x))/(d*e - c*f)]*EllipticE[ArcSin[(Sqrt[f]*Sqrt[c + d*x])/Sqrt[(-d)*e + c*f]], -((b*(d*e - c*f))/((b*c - a*d)*f))])/(d*Sqrt[f]*Sqrt[-((d*(a + b*x))/(b*c - a*d))]*Sqrt[e + f*x])}
{(a + b*x)^(1/2)/((c + d*x)^(3/2)*(e + f*x)^(1/2)), x, 4, -((2*Sqrt[a + b*x]*Sqrt[e + f*x])/((d*e - c*f)*Sqrt[c + d*x])) + (2*Sqrt[(-b)*c + a*d]*Sqrt[(b*(c + d*x))/(b*c - a*d)]*Sqrt[e + f*x]*EllipticE[ArcSin[(Sqrt[d]*Sqrt[a + b*x])/Sqrt[(-b)*c + a*d]], ((b*c - a*d)*f)/(d*(b*e - a*f))])/(Sqrt[d]*(d*e - c*f)*Sqrt[c + d*x]*Sqrt[(b*(e + f*x))/(b*e - a*f)])}


{(Sqrt[1 - 2*x]*(2 + 3*x)^(5/2))/Sqrt[3 + 5*x], x, 8, (-859*Sqrt[1 - 2*x]*Sqrt[2 + 3*x]*Sqrt[3 + 5*x])/4375 - (23*Sqrt[1 - 2*x]*(2 + 3*x)^(3/2)*Sqrt[3 + 5*x])/875 + (2*Sqrt[1 - 2*x]*(2 + 3*x)^(5/2)*Sqrt[3 + 5*x])/35 - (61151*EllipticE[ArcSin[Sqrt[5/11]*Sqrt[1 - 2*x]], 33/35])/(3750*Sqrt[35]) + (859*EllipticF[ArcSin[Sqrt[3/7]*Sqrt[1 - 2*x]], 35/33])/(1875*Sqrt[33])}
{(Sqrt[1 - 2*x]*(2 + 3*x)^(3/2))/Sqrt[3 + 5*x], x, 7, (-9*Sqrt[1 - 2*x]*Sqrt[2 + 3*x]*Sqrt[3 + 5*x])/125 + (2*Sqrt[1 - 2*x]*(2 + 3*x)^(3/2)*Sqrt[3 + 5*x])/25 - (146*Sqrt[7/5]*EllipticE[ArcSin[Sqrt[5/11]*Sqrt[1 - 2*x]], 33/35])/125 + (7*Sqrt[3/11]*EllipticF[ArcSin[Sqrt[3/7]*Sqrt[1 - 2*x]], 35/33])/125}
{(Sqrt[1 - 2*x]*Sqrt[2 + 3*x])/Sqrt[3 + 5*x], x, 6, (2*Sqrt[1 - 2*x]*Sqrt[2 + 3*x]*Sqrt[3 + 5*x])/15 - (31*Sqrt[7/5]*EllipticE[ArcSin[Sqrt[5/11]*Sqrt[1 - 2*x]], 33/35])/45 - (14*EllipticF[ArcSin[Sqrt[3/7]*Sqrt[1 - 2*x]], 35/33])/(45*Sqrt[33])}
{Sqrt[1 - 2*x]/(Sqrt[2 + 3*x]*Sqrt[3 + 5*x]), x, 2, (2*Sqrt[7/5]*Sqrt[-3 - 5*x]*EllipticE[ArcSin[Sqrt[5]*Sqrt[2 + 3*x]], 2/35])/(3*Sqrt[3 + 5*x])}
{Sqrt[1 - 2*x]/((2 + 3*x)^(3/2)*Sqrt[3 + 5*x]), x, 4, (2*Sqrt[1 - 2*x]*Sqrt[3 + 5*x])/Sqrt[2 + 3*x] - 2*Sqrt[11/3]*EllipticE[ArcSin[Sqrt[3/7]*Sqrt[1 - 2*x]], 35/33]}
{Sqrt[1 - 2*x]/((2 + 3*x)^(5/2)*Sqrt[3 + 5*x]), x, 7, (2*Sqrt[1 - 2*x]*Sqrt[3 + 5*x])/(3*(2 + 3*x)^(3/2)) + (136*Sqrt[1 - 2*x]*Sqrt[3 + 5*x])/(21*Sqrt[2 + 3*x]) - (136*Sqrt[5/7]*EllipticE[ArcSin[Sqrt[5/11]*Sqrt[1 - 2*x]], 33/35])/9 + (20*EllipticF[ArcSin[Sqrt[3/7]*Sqrt[1 - 2*x]], 35/33])/(9*Sqrt[33])}
{Sqrt[1 - 2*x]/((2 + 3*x)^(7/2)*Sqrt[3 + 5*x]), x, 8, (2*Sqrt[1 - 2*x]*Sqrt[3 + 5*x])/(5*(2 + 3*x)^(5/2)) + (92*Sqrt[1 - 2*x]*Sqrt[3 + 5*x])/(35*(2 + 3*x)^(3/2)) + (6388*Sqrt[1 - 2*x]*Sqrt[3 + 5*x])/(245*Sqrt[2 + 3*x]) - (6388*EllipticE[ArcSin[Sqrt[5/11]*Sqrt[1 - 2*x]], 33/35])/(21*Sqrt[35]) + (184*EllipticF[ArcSin[Sqrt[3/7]*Sqrt[1 - 2*x]], 35/33])/(21*Sqrt[33])}


{(Sqrt[1 - 2*x]*(2 + 3*x)^(7/2))/(3 + 5*x)^(3/2), x, 9, (-2*Sqrt[1 - 2*x]*(2 + 3*x)^(7/2))/(5*Sqrt[3 + 5*x]) - (2486*Sqrt[1 - 2*x]*Sqrt[2 + 3*x]*Sqrt[3 + 5*x])/21875 + (183*Sqrt[1 - 2*x]*(2 + 3*x)^(3/2)*Sqrt[3 + 5*x])/4375 + (48*Sqrt[1 - 2*x]*(2 + 3*x)^(5/2)*Sqrt[3 + 5*x])/175 - (203179*EllipticE[ArcSin[Sqrt[5/11]*Sqrt[1 - 2*x]], 33/35])/(18750*Sqrt[35]) + (226*Sqrt[11/3]*EllipticF[ArcSin[Sqrt[3/7]*Sqrt[1 - 2*x]], 35/33])/9375}
{(Sqrt[1 - 2*x]*(2 + 3*x)^(5/2))/(3 + 5*x)^(3/2), x, 8, (-2*Sqrt[1 - 2*x]*(2 + 3*x)^(5/2))/(5*Sqrt[3 + 5*x]) + (13*Sqrt[1 - 2*x]*Sqrt[2 + 3*x]*Sqrt[3 + 5*x])/625 + (36*Sqrt[1 - 2*x]*(2 + 3*x)^(3/2)*Sqrt[3 + 5*x])/125 - (1409*Sqrt[7/5]*EllipticE[ArcSin[Sqrt[5/11]*Sqrt[1 - 2*x]], 33/35])/1875 - (91*EllipticF[ArcSin[Sqrt[3/7]*Sqrt[1 - 2*x]], 35/33])/(1875*Sqrt[33])}
{(Sqrt[1 - 2*x]*(2 + 3*x)^(3/2))/(3 + 5*x)^(3/2), x, 7, (-2*Sqrt[1 - 2*x]*(2 + 3*x)^(3/2))/(5*Sqrt[3 + 5*x]) + (8*Sqrt[1 - 2*x]*Sqrt[2 + 3*x]*Sqrt[3 + 5*x])/25 - (19*Sqrt[7/5]*EllipticE[ArcSin[Sqrt[5/11]*Sqrt[1 - 2*x]], 33/35])/75 - (56*EllipticF[ArcSin[Sqrt[3/7]*Sqrt[1 - 2*x]], 35/33])/(75*Sqrt[33])}
{(Sqrt[1 - 2*x]*Sqrt[2 + 3*x])/(3 + 5*x)^(3/2), x, 6, (-2*Sqrt[1 - 2*x]*Sqrt[2 + 3*x])/(5*Sqrt[3 + 5*x]) + (4*Sqrt[7/5]*EllipticE[ArcSin[Sqrt[5/11]*Sqrt[1 - 2*x]], 33/35])/5 - (14*EllipticF[ArcSin[Sqrt[3/7]*Sqrt[1 - 2*x]], 35/33])/(5*Sqrt[33])}
{Sqrt[1 - 2*x]/(Sqrt[2 + 3*x]*(3 + 5*x)^(3/2)), x, 4, -((2*Sqrt[1 - 2*x]*Sqrt[2 + 3*x])/Sqrt[3 + 5*x]) + 2*Sqrt[7/5]*EllipticE[ArcSin[Sqrt[5/11]*Sqrt[1 - 2*x]], 33/35]}
{Sqrt[1 - 2*x]/((2 + 3*x)^(3/2)*(3 + 5*x)^(3/2)), x, 7, (2*Sqrt[1 - 2*x])/(Sqrt[2 + 3*x]*Sqrt[3 + 5*x]) - (20*Sqrt[1 - 2*x]*Sqrt[2 + 3*x])/Sqrt[3 + 5*x] + 4*Sqrt[35]*EllipticE[ArcSin[Sqrt[5/11]*Sqrt[1 - 2*x]], 33/35] - (4*EllipticF[ArcSin[Sqrt[3/7]*Sqrt[1 - 2*x]], 35/33])/Sqrt[33]}
{Sqrt[1 - 2*x]/((2 + 3*x)^(5/2)*(3 + 5*x)^(3/2)), x, 8, (2*Sqrt[1 - 2*x])/(3*(2 + 3*x)^(3/2)*Sqrt[3 + 5*x]) + (92*Sqrt[1 - 2*x])/(7*Sqrt[2 + 3*x]*Sqrt[3 + 5*x]) - (2780*Sqrt[1 - 2*x]*Sqrt[2 + 3*x])/(21*Sqrt[3 + 5*x]) + (556*Sqrt[5/7]*EllipticE[ArcSin[Sqrt[5/11]*Sqrt[1 - 2*x]], 33/35])/3 - (80*EllipticF[ArcSin[Sqrt[3/7]*Sqrt[1 - 2*x]], 35/33])/(3*Sqrt[33])}
{Sqrt[1 - 2*x]/((2 + 3*x)^(7/2)*(3 + 5*x)^(3/2)), x, 9, (2*Sqrt[1 - 2*x])/(5*(2 + 3*x)^(5/2)*Sqrt[3 + 5*x]) + (416*Sqrt[1 - 2*x])/(105*(2 + 3*x)^(3/2)*Sqrt[3 + 5*x]) + (19268*Sqrt[1 - 2*x])/(245*Sqrt[2 + 3*x]*Sqrt[3 + 5*x]) - (116464*Sqrt[1 - 2*x]*Sqrt[2 + 3*x])/(147*Sqrt[3 + 5*x]) + (116464*EllipticE[ArcSin[Sqrt[5/11]*Sqrt[1 - 2*x]], 33/35])/(21*Sqrt[35]) - (3352*EllipticF[ArcSin[Sqrt[3/7]*Sqrt[1 - 2*x]], 35/33])/(21*Sqrt[33])}


{(Sqrt[1 - 2*x]*(2 + 3*x)^(9/2))/(3 + 5*x)^(5/2), x, 10, -((2*Sqrt[1 - 2*x]*(2 + 3*x)^(9/2))/(15*(3 + 5*x)^(3/2))) - (118*Sqrt[1 - 2*x]*(2 + 3*x)^(7/2))/(165*Sqrt[3 + 5*x]) - (12601*Sqrt[1 - 2*x]*Sqrt[2 + 3*x]*Sqrt[3 + 5*x])/240625 + (5153*Sqrt[1 - 2*x]*(2 + 3*x)^(3/2)*Sqrt[3 + 5*x])/48125 + (958*Sqrt[1 - 2*x]*(2 + 3*x)^(5/2)*Sqrt[3 + 5*x])/1925 - (1473539*EllipticE[ArcSin[Sqrt[5/11]*Sqrt[1 - 2*x]], 33/35])/(206250*Sqrt[35]) + (12601*EllipticF[ArcSin[Sqrt[3/7]*Sqrt[1 - 2*x]], 35/33])/(103125*Sqrt[33])}
{(Sqrt[1 - 2*x]*(2 + 3*x)^(7/2))/(3 + 5*x)^(5/2), x, 9, (-2*Sqrt[1 - 2*x]*(2 + 3*x)^(7/2))/(15*(3 + 5*x)^(3/2)) - (458*Sqrt[1 - 2*x]*(2 + 3*x)^(5/2))/(825*Sqrt[3 + 5*x]) + (2719*Sqrt[1 - 2*x]*Sqrt[2 + 3*x]*Sqrt[3 + 5*x])/34375 + (2818*Sqrt[1 - 2*x]*(2 + 3*x)^(3/2)*Sqrt[3 + 5*x])/6875 - (47342*Sqrt[7/5]*EllipticE[ArcSin[Sqrt[5/11]*Sqrt[1 - 2*x]], 33/35])/103125 - (19033*EllipticF[ArcSin[Sqrt[3/7]*Sqrt[1 - 2*x]], 35/33])/(103125*Sqrt[33])}
{(Sqrt[1 - 2*x]*(2 + 3*x)^(5/2))/(3 + 5*x)^(5/2), x, 8, (-2*Sqrt[1 - 2*x]*(2 + 3*x)^(5/2))/(15*(3 + 5*x)^(3/2)) - (326*Sqrt[1 - 2*x]*(2 + 3*x)^(3/2))/(825*Sqrt[3 + 5*x]) + (458*Sqrt[1 - 2*x]*Sqrt[2 + 3*x]*Sqrt[3 + 5*x])/1375 - (169*Sqrt[7/5]*EllipticE[ArcSin[Sqrt[5/11]*Sqrt[1 - 2*x]], 33/35])/4125 - (3206*EllipticF[ArcSin[Sqrt[3/7]*Sqrt[1 - 2*x]], 35/33])/(4125*Sqrt[33])}
{(Sqrt[1 - 2*x]*(2 + 3*x)^(3/2))/(3 + 5*x)^(5/2), x, 7, (-2*Sqrt[1 - 2*x]*(2 + 3*x)^(3/2))/(15*(3 + 5*x)^(3/2)) - (194*Sqrt[1 - 2*x]*Sqrt[2 + 3*x])/(825*Sqrt[3 + 5*x]) + (458*Sqrt[7/5]*EllipticE[ArcSin[Sqrt[5/11]*Sqrt[1 - 2*x]], 33/35])/825 - (1358*EllipticF[ArcSin[Sqrt[3/7]*Sqrt[1 - 2*x]], 35/33])/(825*Sqrt[33])}
{(Sqrt[1 - 2*x]*Sqrt[2 + 3*x])/(3 + 5*x)^(5/2), x, 7, (-2*Sqrt[1 - 2*x]*Sqrt[2 + 3*x])/(15*(3 + 5*x)^(3/2)) - (62*Sqrt[1 - 2*x]*Sqrt[2 + 3*x])/(165*Sqrt[3 + 5*x]) + (62*Sqrt[7/5]*EllipticE[ArcSin[Sqrt[5/11]*Sqrt[1 - 2*x]], 33/35])/165 + (28*EllipticF[ArcSin[Sqrt[3/7]*Sqrt[1 - 2*x]], 35/33])/(165*Sqrt[33])}
{Sqrt[1 - 2*x]/(Sqrt[2 + 3*x]*(3 + 5*x)^(5/2)), x, 7, (-2*Sqrt[1 - 2*x]*Sqrt[2 + 3*x])/(3*(3 + 5*x)^(3/2)) + (136*Sqrt[1 - 2*x]*Sqrt[2 + 3*x])/(33*Sqrt[3 + 5*x]) - (136*Sqrt[7/5]*EllipticE[ArcSin[Sqrt[5/11]*Sqrt[1 - 2*x]], 33/35])/33 + (28*EllipticF[ArcSin[Sqrt[3/7]*Sqrt[1 - 2*x]], 35/33])/(33*Sqrt[33])}
{Sqrt[1 - 2*x]/((2 + 3*x)^(3/2)*(3 + 5*x)^(5/2)), x, 8, (2*Sqrt[1 - 2*x])/(Sqrt[2 + 3*x]*(3 + 5*x)^(3/2)) - (40*Sqrt[1 - 2*x]*Sqrt[2 + 3*x])/(3*(3 + 5*x)^(3/2)) + (2660*Sqrt[1 - 2*x]*Sqrt[2 + 3*x])/(33*Sqrt[3 + 5*x]) - (532*Sqrt[35]*EllipticE[ArcSin[Sqrt[5/11]*Sqrt[1 - 2*x]], 33/35])/33 + (536*EllipticF[ArcSin[Sqrt[3/7]*Sqrt[1 - 2*x]], 35/33])/(33*Sqrt[33])}
{Sqrt[1 - 2*x]/((2 + 3*x)^(5/2)*(3 + 5*x)^(5/2)), x, 9, (2*Sqrt[1 - 2*x])/(3*(2 + 3*x)^(3/2)*(3 + 5*x)^(3/2)) + (416*Sqrt[1 - 2*x])/(21*Sqrt[2 + 3*x]*(3 + 5*x)^(3/2)) - (2780*Sqrt[1 - 2*x]*Sqrt[2 + 3*x])/(21*(3 + 5*x)^(3/2)) + (184840*Sqrt[1 - 2*x]*Sqrt[2 + 3*x])/(231*Sqrt[3 + 5*x]) - (36968*Sqrt[5/7]*EllipticE[ArcSin[Sqrt[5/11]*Sqrt[1 - 2*x]], 33/35])/33 + (5320*EllipticF[ArcSin[Sqrt[3/7]*Sqrt[1 - 2*x]], 35/33])/(33*Sqrt[33])}
{Sqrt[1 - 2*x]/((2 + 3*x)^(7/2)*(3 + 5*x)^(5/2)), x, 10, (2*Sqrt[1 - 2*x])/(5*(2 + 3*x)^(5/2)*(3 + 5*x)^(3/2)) + (556*Sqrt[1 - 2*x])/(105*(2 + 3*x)^(3/2)*(3 + 5*x)^(3/2)) + (116044*Sqrt[1 - 2*x])/(735*Sqrt[2 + 3*x]*(3 + 5*x)^(3/2)) - (155104*Sqrt[1 - 2*x]*Sqrt[2 + 3*x])/(147*(3 + 5*x)^(3/2)) + (10312712*Sqrt[1 - 2*x]*Sqrt[2 + 3*x])/(1617*Sqrt[3 + 5*x]) - (10312712*EllipticE[ArcSin[Sqrt[5/11]*Sqrt[1 - 2*x]], 33/35])/(231*Sqrt[35]) + (296816*EllipticF[ArcSin[Sqrt[3/7]*Sqrt[1 - 2*x]], 35/33])/(231*Sqrt[33])}


(* ::Subsection::Closed:: *)
(*Integrands of the form (a+b x)^(m/2) (c+d x)^(n/2) (e+f x)^(3/2)*)


(* ::Subsubsection::Closed:: *)
(*n<0*)


{(1 - 2*x)^(3/2)*(2 + 3*x)^(5/2)*Sqrt[3 + 5*x], x, 10, (-18177329*Sqrt[1 - 2*x]*Sqrt[2 + 3*x]*Sqrt[3 + 5*x])/38981250 - (124891*Sqrt[1 - 2*x]*Sqrt[2 + 3*x]*(3 + 5*x)^(3/2))/2165625 + (1103*Sqrt[1 - 2*x]*(2 + 3*x)^(3/2)*(3 + 5*x)^(3/2))/259875 + (178*Sqrt[1 - 2*x]*(2 + 3*x)^(5/2)*(3 + 5*x)^(3/2))/7425 + (2*(1 - 2*x)^(3/2)*(2 + 3*x)^(5/2)*(3 + 5*x)^(3/2))/55 - (604915631*EllipticE[ArcSin[Sqrt[5/11]*Sqrt[1 - 2*x]], 33/35])/(16706250*Sqrt[35]) + (17427983*EllipticF[ArcSin[Sqrt[3/7]*Sqrt[1 - 2*x]], 35/33])/(16706250*Sqrt[33])}
{(1 - 2*x)^(3/2)*(2 + 3*x)^(3/2)*Sqrt[3 + 5*x], x, 9, (-84134*Sqrt[1 - 2*x]*Sqrt[2 + 3*x]*Sqrt[3 + 5*x])/354375 - (347*Sqrt[1 - 2*x]*Sqrt[2 + 3*x]*(3 + 5*x)^(3/2))/39375 + (62*Sqrt[1 - 2*x]*(2 + 3*x)^(3/2)*(3 + 5*x)^(3/2))/1575 + (2*(1 - 2*x)^(3/2)*(2 + 3*x)^(3/2)*(3 + 5*x)^(3/2))/45 - (5684677*EllipticE[ArcSin[Sqrt[5/11]*Sqrt[1 - 2*x]], 33/35])/(303750*Sqrt[35]) + (83093*EllipticF[ArcSin[Sqrt[3/7]*Sqrt[1 - 2*x]], 35/33])/(151875*Sqrt[33])}
{(1 - 2*x)^(3/2)*Sqrt[2 + 3*x]*Sqrt[3 + 5*x], x, 8, (-2657*Sqrt[1 - 2*x]*Sqrt[2 + 3*x]*Sqrt[3 + 5*x])/23625 + (194*Sqrt[1 - 2*x]*Sqrt[2 + 3*x]*(3 + 5*x)^(3/2))/2625 + (2*(1 - 2*x)^(3/2)*Sqrt[2 + 3*x]*(3 + 5*x)^(3/2))/35 - (118898*EllipticE[ArcSin[Sqrt[5/11]*Sqrt[1 - 2*x]], 33/35])/(10125*Sqrt[35]) + (4289*EllipticF[ArcSin[Sqrt[3/7]*Sqrt[1 - 2*x]], 35/33])/(10125*Sqrt[33])}
{((1 - 2*x)^(3/2)*Sqrt[3 + 5*x])/Sqrt[2 + 3*x], x, 7, (214*Sqrt[1 - 2*x]*Sqrt[2 + 3*x]*Sqrt[3 + 5*x])/675 + (2*(1 - 2*x)^(3/2)*Sqrt[2 + 3*x]*Sqrt[3 + 5*x])/15 - (4157*Sqrt[7/5]*EllipticE[ArcSin[Sqrt[5/11]*Sqrt[1 - 2*x]], 33/35])/2025 + (4382*EllipticF[ArcSin[Sqrt[3/7]*Sqrt[1 - 2*x]], 35/33])/(2025*Sqrt[33])}
{((1 - 2*x)^(3/2)*Sqrt[3 + 5*x])/(2 + 3*x)^(3/2), x, 7, (-2*(1 - 2*x)^(3/2)*Sqrt[3 + 5*x])/(3*Sqrt[2 + 3*x]) - (16*Sqrt[1 - 2*x]*Sqrt[2 + 3*x]*Sqrt[3 + 5*x])/27 + (494*Sqrt[7/5]*EllipticE[ArcSin[Sqrt[5/11]*Sqrt[1 - 2*x]], 33/35])/81 - (1610*EllipticF[ArcSin[Sqrt[3/7]*Sqrt[1 - 2*x]], 35/33])/(81*Sqrt[33])}
{((1 - 2*x)^(3/2)*Sqrt[3 + 5*x])/(2 + 3*x)^(5/2), x, 7, (-2*(1 - 2*x)^(3/2)*Sqrt[3 + 5*x])/(9*(2 + 3*x)^(3/2)) + (82*Sqrt[1 - 2*x]*Sqrt[3 + 5*x])/(27*Sqrt[2 + 3*x]) - (98*Sqrt[35]*EllipticE[ArcSin[Sqrt[5/11]*Sqrt[1 - 2*x]], 33/35])/81 + (724*EllipticF[ArcSin[Sqrt[3/7]*Sqrt[1 - 2*x]], 35/33])/(81*Sqrt[33])}
{((1 - 2*x)^(3/2)*Sqrt[3 + 5*x])/(2 + 3*x)^(7/2), x, 8, (-2*(1 - 2*x)^(3/2)*Sqrt[3 + 5*x])/(15*(2 + 3*x)^(5/2)) + (82*Sqrt[1 - 2*x]*Sqrt[3 + 5*x])/(135*(2 + 3*x)^(3/2)) + (3896*Sqrt[1 - 2*x]*Sqrt[3 + 5*x])/(945*Sqrt[2 + 3*x]) - (3896*EllipticE[ArcSin[Sqrt[5/11]*Sqrt[1 - 2*x]], 33/35])/(81*Sqrt[35]) + (68*EllipticF[ArcSin[Sqrt[3/7]*Sqrt[1 - 2*x]], 35/33])/(81*Sqrt[33])}
{((1 - 2*x)^(3/2)*Sqrt[3 + 5*x])/(2 + 3*x)^(9/2), x, 9, -((2*(1 - 2*x)^(3/2)*Sqrt[3 + 5*x])/(21*(2 + 3*x)^(7/2))) + (82*Sqrt[1 - 2*x]*Sqrt[3 + 5*x])/(315*(2 + 3*x)^(5/2)) + (8516*Sqrt[1 - 2*x]*Sqrt[3 + 5*x])/(6615*(2 + 3*x)^(3/2)) + (595324*Sqrt[1 - 2*x]*Sqrt[3 + 5*x])/(46305*Sqrt[2 + 3*x]) - (595324*EllipticE[ArcSin[Sqrt[5/11]*Sqrt[1 - 2*x]], 33/35])/(3969*Sqrt[35]) + (17032*EllipticF[ArcSin[Sqrt[3/7]*Sqrt[1 - 2*x]], 35/33])/(3969*Sqrt[33])}
{((1 - 2*x)^(3/2)*Sqrt[3 + 5*x])/(2 + 3*x)^(11/2), x, 10, -((2*(1 - 2*x)^(3/2)*Sqrt[3 + 5*x])/(27*(2 + 3*x)^(9/2))) + (82*Sqrt[1 - 2*x]*Sqrt[3 + 5*x])/(567*(2 + 3*x)^(7/2)) + (13136*Sqrt[1 - 2*x]*Sqrt[3 + 5*x])/(19845*(2 + 3*x)^(5/2)) + (613276*Sqrt[1 - 2*x]*Sqrt[3 + 5*x])/(138915*(2 + 3*x)^(3/2)) + (42623864*Sqrt[1 - 2*x]*Sqrt[3 + 5*x])/(972405*Sqrt[2 + 3*x]) - (42623864*EllipticE[ArcSin[Sqrt[5/11]*Sqrt[1 - 2*x]], 33/35])/(83349*Sqrt[35]) + (1226552*EllipticF[ArcSin[Sqrt[3/7]*Sqrt[1 - 2*x]], 35/33])/(83349*Sqrt[33])}


{(1 - 2*x)^(3/2)*(2 + 3*x)^(5/2)*(3 + 5*x)^(3/2), x, 11, (-776112041*Sqrt[1 - 2*x]*Sqrt[2 + 3*x]*Sqrt[3 + 5*x])/506756250 - (11725073*Sqrt[1 - 2*x]*Sqrt[2 + 3*x]*(3 + 5*x)^(3/2))/56306250 - (18034*Sqrt[1 - 2*x]*Sqrt[2 + 3*x]*(3 + 5*x)^(5/2))/625625 + (601*Sqrt[1 - 2*x]*(2 + 3*x)^(3/2)*(3 + 5*x)^(5/2))/160875 + (178*Sqrt[1 - 2*x]*(2 + 3*x)^(5/2)*(3 + 5*x)^(5/2))/10725 + (2*(1 - 2*x)^(3/2)*(2 + 3*x)^(5/2)*(3 + 5*x)^(5/2))/65 - (51601293223*EllipticE[ArcSin[Sqrt[5/11]*Sqrt[1 - 2*x]], 33/35])/(434362500*Sqrt[35]) + (371279941*EllipticF[ArcSin[Sqrt[3/7]*Sqrt[1 - 2*x]], 35/33])/(108590625*Sqrt[33])}
{(1 - 2*x)^(3/2)*(2 + 3*x)^(3/2)*(3 + 5*x)^(3/2), x, 10, (-5442127*Sqrt[1 - 2*x]*Sqrt[2 + 3*x]*Sqrt[3 + 5*x])/7796250 - (40703*Sqrt[1 - 2*x]*Sqrt[2 + 3*x]*(3 + 5*x)^(3/2))/433125 - (23*Sqrt[1 - 2*x]*Sqrt[2 + 3*x]*(3 + 5*x)^(5/2))/9625 + (62*Sqrt[1 - 2*x]*(2 + 3*x)^(3/2)*(3 + 5*x)^(5/2))/2475 + (2*(1 - 2*x)^(3/2)*(2 + 3*x)^(3/2)*(3 + 5*x)^(5/2))/55 - (90397364*EllipticE[ArcSin[Sqrt[5/11]*Sqrt[1 - 2*x]], 33/35])/(1670625*Sqrt[35]) + (5199979*EllipticF[ArcSin[Sqrt[3/7]*Sqrt[1 - 2*x]], 35/33])/(3341250*Sqrt[33])}
{(1 - 2*x)^(3/2)*Sqrt[2 + 3*x]*(3 + 5*x)^(3/2), x, 9, (-76163*Sqrt[1 - 2*x]*Sqrt[2 + 3*x]*Sqrt[3 + 5*x])/212625 - (839*Sqrt[1 - 2*x]*Sqrt[2 + 3*x]*(3 + 5*x)^(3/2))/23625 + (194*Sqrt[1 - 2*x]*Sqrt[2 + 3*x]*(3 + 5*x)^(5/2))/4725 + (2*(1 - 2*x)^(3/2)*Sqrt[2 + 3*x]*(3 + 5*x)^(5/2))/45 - (4971289*EllipticE[ArcSin[Sqrt[5/11]*Sqrt[1 - 2*x]], 33/35])/(182250*Sqrt[35]) + (70226*EllipticF[ArcSin[Sqrt[3/7]*Sqrt[1 - 2*x]], 35/33])/(91125*Sqrt[33])}
{((1 - 2*x)^(3/2)*(3 + 5*x)^(3/2))/Sqrt[2 + 3*x], x, 8, (-1847*Sqrt[1 - 2*x]*Sqrt[2 + 3*x]*Sqrt[3 + 5*x])/4725 + (74*Sqrt[1 - 2*x]*Sqrt[2 + 3*x]*(3 + 5*x)^(3/2))/525 + (2*(1 - 2*x)^(3/2)*Sqrt[2 + 3*x]*(3 + 5*x)^(3/2))/21 - (29933*EllipticE[ArcSin[Sqrt[5/11]*Sqrt[1 - 2*x]], 33/35])/(2025*Sqrt[35]) - (31*EllipticF[ArcSin[Sqrt[3/7]*Sqrt[1 - 2*x]], 35/33])/(2025*Sqrt[33])}
{((1 - 2*x)^(3/2)*(3 + 5*x)^(3/2))/(2 + 3*x)^(3/2), x, 8, (494*Sqrt[1 - 2*x]*Sqrt[2 + 3*x]*Sqrt[3 + 5*x])/135 - (2*(1 - 2*x)^(3/2)*(3 + 5*x)^(3/2))/(3*Sqrt[2 + 3*x]) - (8*Sqrt[1 - 2*x]*Sqrt[2 + 3*x]*(3 + 5*x)^(3/2))/15 - (2209*Sqrt[7/5]*EllipticE[ArcSin[Sqrt[5/11]*Sqrt[1 - 2*x]], 33/35])/405 + (4144*EllipticF[ArcSin[Sqrt[3/7]*Sqrt[1 - 2*x]], 35/33])/(405*Sqrt[33])}
{((1 - 2*x)^(3/2)*(3 + 5*x)^(3/2))/(2 + 3*x)^(5/2), x, 8, (-1150*Sqrt[1 - 2*x]*Sqrt[2 + 3*x]*Sqrt[3 + 5*x])/81 - (2*(1 - 2*x)^(3/2)*(3 + 5*x)^(3/2))/(9*(2 + 3*x)^(3/2)) + (74*Sqrt[1 - 2*x]*(3 + 5*x)^(3/2))/(9*Sqrt[2 + 3*x]) + (592*Sqrt[35]*EllipticE[ArcSin[Sqrt[5/11]*Sqrt[1 - 2*x]], 33/35])/243 - (8774*EllipticF[ArcSin[Sqrt[3/7]*Sqrt[1 - 2*x]], 35/33])/(243*Sqrt[33])}
{((1 - 2*x)^(3/2)*(3 + 5*x)^(3/2))/(2 + 3*x)^(7/2), x, 8, (988*Sqrt[1 - 2*x]*Sqrt[3 + 5*x])/(945*Sqrt[2 + 3*x]) - (2*(1 - 2*x)^(3/2)*(3 + 5*x)^(3/2))/(15*(2 + 3*x)^(5/2)) + (74*Sqrt[1 - 2*x]*(3 + 5*x)^(3/2))/(45*(2 + 3*x)^(3/2)) - (4418*EllipticE[ArcSin[Sqrt[5/11]*Sqrt[1 - 2*x]], 33/35])/(81*Sqrt[35]) + (1184*EllipticF[ArcSin[Sqrt[3/7]*Sqrt[1 - 2*x]], 35/33])/(81*Sqrt[33])}
{((1 - 2*x)^(3/2)*(3 + 5*x)^(3/2))/(2 + 3*x)^(9/2), x, 9, -((3632*Sqrt[1 - 2*x]*Sqrt[3 + 5*x])/(6615*(2 + 3*x)^(3/2))) + (119732*Sqrt[1 - 2*x]*Sqrt[3 + 5*x])/(46305*Sqrt[2 + 3*x]) - (2*(1 - 2*x)^(3/2)*(3 + 5*x)^(3/2))/(21*(2 + 3*x)^(7/2)) + (74*Sqrt[1 - 2*x]*(3 + 5*x)^(3/2))/(105*(2 + 3*x)^(5/2)) - (119732*EllipticE[ArcSin[Sqrt[5/11]*Sqrt[1 - 2*x]], 33/35])/(3969*Sqrt[35]) - (124*EllipticF[ArcSin[Sqrt[3/7]*Sqrt[1 - 2*x]], 35/33])/(3969*Sqrt[33])}
{((1 - 2*x)^(3/2)*(3 + 5*x)^(3/2))/(2 + 3*x)^(11/2), x, 10, -((8252*Sqrt[1 - 2*x]*Sqrt[3 + 5*x])/(19845*(2 + 3*x)^(5/2))) + (280904*Sqrt[1 - 2*x]*Sqrt[3 + 5*x])/(416745*(2 + 3*x)^(3/2)) + (19885156*Sqrt[1 - 2*x]*Sqrt[3 + 5*x])/(2917215*Sqrt[2 + 3*x]) - (2*(1 - 2*x)^(3/2)*(3 + 5*x)^(3/2))/(27*(2 + 3*x)^(9/2)) + (74*Sqrt[1 - 2*x]*(3 + 5*x)^(3/2))/(189*(2 + 3*x)^(7/2)) - (19885156*EllipticE[ArcSin[Sqrt[5/11]*Sqrt[1 - 2*x]], 33/35])/(250047*Sqrt[35]) + (561808*EllipticF[ArcSin[Sqrt[3/7]*Sqrt[1 - 2*x]], 35/33])/(250047*Sqrt[33])}
{((1 - 2*x)^(3/2)*(3 + 5*x)^(3/2))/(2 + 3*x)^(13/2), x, 11, -((12872*Sqrt[1 - 2*x]*Sqrt[3 + 5*x])/(43659*(2 + 3*x)^(7/2))) + (442076*Sqrt[1 - 2*x]*Sqrt[3 + 5*x])/(1528065*(2 + 3*x)^(5/2)) + (20799916*Sqrt[1 - 2*x]*Sqrt[3 + 5*x])/(10696455*(2 + 3*x)^(3/2)) + (1446357824*Sqrt[1 - 2*x]*Sqrt[3 + 5*x])/(74875185*Sqrt[2 + 3*x]) - (2*(1 - 2*x)^(3/2)*(3 + 5*x)^(3/2))/(33*(2 + 3*x)^(11/2)) + (74*Sqrt[1 - 2*x]*(3 + 5*x)^(3/2))/(297*(2 + 3*x)^(9/2)) - (1446357824*EllipticE[ArcSin[Sqrt[5/11]*Sqrt[1 - 2*x]], 33/35])/(6417873*Sqrt[35]) + (41599832*EllipticF[ArcSin[Sqrt[3/7]*Sqrt[1 - 2*x]], 35/33])/(6417873*Sqrt[33])}


{(1 - 2*x)^(3/2)*(2 + 3*x)^(5/2)*(3 + 5*x)^(5/2), x, 12, (-50299451003*Sqrt[1 - 2*x]*Sqrt[2 + 3*x]*Sqrt[3 + 5*x])/9121612500 - (380132617*Sqrt[1 - 2*x]*Sqrt[2 + 3*x]*(3 + 5*x)^(3/2))/506756250 - (57509209*Sqrt[1 - 2*x]*Sqrt[2 + 3*x]*(3 + 5*x)^(5/2))/506756250 - (199721*Sqrt[1 - 2*x]*Sqrt[2 + 3*x]*(3 + 5*x)^(7/2))/12065625 + (2503*Sqrt[1 - 2*x]*(2 + 3*x)^(3/2)*(3 + 5*x)^(7/2))/804375 + (178*Sqrt[1 - 2*x]*(2 + 3*x)^(5/2)*(3 + 5*x)^(7/2))/14625 + (2*(1 - 2*x)^(3/2)*(2 + 3*x)^(5/2)*(3 + 5*x)^(7/2))/75 - (836091184171*EllipticE[ArcSin[Sqrt[5/11]*Sqrt[1 - 2*x]], 33/35])/(1954631250*Sqrt[35]) + (48128081531*EllipticF[ArcSin[Sqrt[3/7]*Sqrt[1 - 2*x]], 35/33])/(3909262500*Sqrt[33])}
{(1 - 2*x)^(3/2)*(2 + 3*x)^(3/2)*(3 + 5*x)^(5/2), x, 11, (-70536439*Sqrt[1 - 2*x]*Sqrt[2 + 3*x]*Sqrt[3 + 5*x])/30405375 - (2133359*Sqrt[1 - 2*x]*Sqrt[2 + 3*x]*(3 + 5*x)^(3/2))/6756750 - (160084*Sqrt[1 - 2*x]*Sqrt[2 + 3*x]*(3 + 5*x)^(5/2))/3378375 - (67*Sqrt[1 - 2*x]*Sqrt[2 + 3*x]*(3 + 5*x)^(7/2))/160875 + (62*Sqrt[1 - 2*x]*(2 + 3*x)^(3/2)*(3 + 5*x)^(7/2))/3575 + (2*(1 - 2*x)^(3/2)*(2 + 3*x)^(3/2)*(3 + 5*x)^(7/2))/65 - (9380126059*EllipticE[ArcSin[Sqrt[5/11]*Sqrt[1 - 2*x]], 33/35])/(52123500*Sqrt[35]) + (134992031*EllipticF[ArcSin[Sqrt[3/7]*Sqrt[1 - 2*x]], 35/33])/(26061750*Sqrt[33])}
{(1 - 2*x)^(3/2)*Sqrt[2 + 3*x]*(3 + 5*x)^(5/2), x, 10, (-2930159*Sqrt[1 - 2*x]*Sqrt[2 + 3*x]*Sqrt[3 + 5*x])/2806650 - (22576*Sqrt[1 - 2*x]*Sqrt[2 + 3*x]*(3 + 5*x)^(3/2))/155925 - (2377*Sqrt[1 - 2*x]*Sqrt[2 + 3*x]*(3 + 5*x)^(5/2))/155925 + (194*Sqrt[1 - 2*x]*Sqrt[2 + 3*x]*(3 + 5*x)^(7/2))/7425 + (2*(1 - 2*x)^(3/2)*Sqrt[2 + 3*x]*(3 + 5*x)^(7/2))/55 - (97540001*EllipticE[ArcSin[Sqrt[5/11]*Sqrt[1 - 2*x]], 33/35])/(1202850*Sqrt[35]) + (2810993*EllipticF[ArcSin[Sqrt[3/7]*Sqrt[1 - 2*x]], 35/33])/(1202850*Sqrt[33])}
{((1 - 2*x)^(3/2)*(3 + 5*x)^(5/2))/Sqrt[2 + 3*x], x, 9, (-11908*Sqrt[1 - 2*x]*Sqrt[2 + 3*x]*Sqrt[3 + 5*x])/25515 - (499*Sqrt[1 - 2*x]*Sqrt[2 + 3*x]*(3 + 5*x)^(3/2))/2835 + (46*Sqrt[1 - 2*x]*Sqrt[2 + 3*x]*(3 + 5*x)^(5/2))/567 + (2*(1 - 2*x)^(3/2)*Sqrt[2 + 3*x]*(3 + 5*x)^(5/2))/27 - (886499*EllipticE[ArcSin[Sqrt[5/11]*Sqrt[1 - 2*x]], 33/35])/(21870*Sqrt[35]) + (14101*EllipticF[ArcSin[Sqrt[3/7]*Sqrt[1 - 2*x]], 35/33])/(10935*Sqrt[33])}
{((1 - 2*x)^(3/2)*(3 + 5*x)^(5/2))/(2 + 3*x)^(3/2), x, 9, (-1061*Sqrt[1 - 2*x]*Sqrt[2 + 3*x]*Sqrt[3 + 5*x])/567 + (202*Sqrt[1 - 2*x]*Sqrt[2 + 3*x]*(3 + 5*x)^(3/2))/63 - (2*(1 - 2*x)^(3/2)*(3 + 5*x)^(5/2))/(3*Sqrt[2 + 3*x]) - (32*Sqrt[1 - 2*x]*Sqrt[2 + 3*x]*(3 + 5*x)^(5/2))/63 - (2894*EllipticE[ArcSin[Sqrt[5/11]*Sqrt[1 - 2*x]], 33/35])/(243*Sqrt[35]) - (835*EllipticF[ArcSin[Sqrt[3/7]*Sqrt[1 - 2*x]], 35/33])/(243*Sqrt[33])}
{((1 - 2*x)^(3/2)*(3 + 5*x)^(5/2))/(2 + 3*x)^(5/2), x, 9, (2632*Sqrt[1 - 2*x]*Sqrt[2 + 3*x]*Sqrt[3 + 5*x])/243 - (614*Sqrt[1 - 2*x]*Sqrt[2 + 3*x]*(3 + 5*x)^(3/2))/27 - (2*(1 - 2*x)^(3/2)*(3 + 5*x)^(5/2))/(9*(2 + 3*x)^(3/2)) + (362*Sqrt[1 - 2*x]*(3 + 5*x)^(5/2))/(27*Sqrt[2 + 3*x]) - (9587*Sqrt[7/5]*EllipticE[ArcSin[Sqrt[5/11]*Sqrt[1 - 2*x]], 33/35])/729 + (21206*EllipticF[ArcSin[Sqrt[3/7]*Sqrt[1 - 2*x]], 35/33])/(729*Sqrt[33])}
{((1 - 2*x)^(3/2)*(3 + 5*x)^(5/2))/(2 + 3*x)^(7/2), x, 9, (-43214*Sqrt[1 - 2*x]*Sqrt[2 + 3*x]*Sqrt[3 + 5*x])/1701 + (9808*Sqrt[1 - 2*x]*(3 + 5*x)^(3/2))/(945*Sqrt[2 + 3*x]) - (2*(1 - 2*x)^(3/2)*(3 + 5*x)^(5/2))/(15*(2 + 3*x)^(5/2)) + (362*Sqrt[1 - 2*x]*(3 + 5*x)^(5/2))/(135*(2 + 3*x)^(3/2)) + (116854*EllipticE[ArcSin[Sqrt[5/11]*Sqrt[1 - 2*x]], 33/35])/(729*Sqrt[35]) - (47422*EllipticF[ArcSin[Sqrt[3/7]*Sqrt[1 - 2*x]], 35/33])/(729*Sqrt[33])}
{((1 - 2*x)^(3/2)*(3 + 5*x)^(5/2))/(2 + 3*x)^(9/2), x, 9, (249448*Sqrt[1 - 2*x]*Sqrt[3 + 5*x])/(138915*Sqrt[2 + 3*x]) + (2108*Sqrt[1 - 2*x]*(3 + 5*x)^(3/2))/(6615*(2 + 3*x)^(3/2)) - (2*(1 - 2*x)^(3/2)*(3 + 5*x)^(5/2))/(21*(2 + 3*x)^(7/2)) + (362*Sqrt[1 - 2*x]*(3 + 5*x)^(5/2))/(315*(2 + 3*x)^(5/2)) - (962678*EllipticE[ArcSin[Sqrt[5/11]*Sqrt[1 - 2*x]], 33/35])/(11907*Sqrt[35]) + (290204*EllipticF[ArcSin[Sqrt[3/7]*Sqrt[1 - 2*x]], 35/33])/(11907*Sqrt[33])}
{((1 - 2*x)^(3/2)*(3 + 5*x)^(5/2))/(2 + 3*x)^(11/2), x, 10, -((558524*Sqrt[1 - 2*x]*Sqrt[3 + 5*x])/(1250235*(2 + 3*x)^(3/2))) + (17830424*Sqrt[1 - 2*x]*Sqrt[3 + 5*x])/(8751645*Sqrt[2 + 3*x]) - (1864*Sqrt[1 - 2*x]*(3 + 5*x)^(3/2))/(6615*(2 + 3*x)^(5/2)) - (2*(1 - 2*x)^(3/2)*(3 + 5*x)^(5/2))/(27*(2 + 3*x)^(9/2)) + (362*Sqrt[1 - 2*x]*(3 + 5*x)^(5/2))/(567*(2 + 3*x)^(7/2)) - (17830424*EllipticE[ArcSin[Sqrt[5/11]*Sqrt[1 - 2*x]], 33/35])/(750141*Sqrt[35]) - (600868*EllipticF[ArcSin[Sqrt[3/7]*Sqrt[1 - 2*x]], 35/33])/(750141*Sqrt[33])}
{((1 - 2*x)^(3/2)*(3 + 5*x)^(5/2))/(2 + 3*x)^(13/2), x, 11, -((1366496*Sqrt[1 - 2*x]*Sqrt[3 + 5*x])/(4584195*(2 + 3*x)^(5/2))) + (45748292*Sqrt[1 - 2*x]*Sqrt[3 + 5*x])/(96268095*(2 + 3*x)^(3/2)) + (3316711588*Sqrt[1 - 2*x]*Sqrt[3 + 5*x])/(673876665*Sqrt[2 + 3*x]) - (13292*Sqrt[1 - 2*x]*(3 + 5*x)^(3/2))/(43659*(2 + 3*x)^(7/2)) - (2*(1 - 2*x)^(3/2)*(3 + 5*x)^(5/2))/(33*(2 + 3*x)^(11/2)) + (362*Sqrt[1 - 2*x]*(3 + 5*x)^(5/2))/(891*(2 + 3*x)^(9/2)) - (3316711588*EllipticE[ArcSin[Sqrt[5/11]*Sqrt[1 - 2*x]], 33/35])/(57760857*Sqrt[35]) + (91496584*EllipticF[ArcSin[Sqrt[3/7]*Sqrt[1 - 2*x]], 35/33])/(57760857*Sqrt[33])}
{((1 - 2*x)^(3/2)*(3 + 5*x)^(5/2))/(2 + 3*x)^(15/2), x, 12, -((2174468*Sqrt[1 - 2*x]*Sqrt[3 + 5*x])/(11918907*(2 + 3*x)^(7/2))) + (73596464*Sqrt[1 - 2*x]*Sqrt[3 + 5*x])/(417161745*(2 + 3*x)^(5/2)) + (3523482724*Sqrt[1 - 2*x]*Sqrt[3 + 5*x])/(2920132215*(2 + 3*x)^(3/2)) + (245282464136*Sqrt[1 - 2*x]*Sqrt[3 + 5*x])/(20440925505*Sqrt[2 + 3*x]) - (20992*Sqrt[1 - 2*x]*(3 + 5*x)^(3/2))/(81081*(2 + 3*x)^(9/2)) - (2*(1 - 2*x)^(3/2)*(3 + 5*x)^(5/2))/(39*(2 + 3*x)^(13/2)) + (362*Sqrt[1 - 2*x]*(3 + 5*x)^(5/2))/(1287*(2 + 3*x)^(11/2)) - (245282464136*EllipticE[ArcSin[Sqrt[5/11]*Sqrt[1 - 2*x]], 33/35])/(1752079329*Sqrt[35]) + (7046965448*EllipticF[ArcSin[Sqrt[3/7]*Sqrt[1 - 2*x]], 35/33])/(1752079329*Sqrt[33])}


(* ::Subsubsection::Closed:: *)
(*n>0*)


{((1 - 2*x)^(3/2)*(2 + 3*x)^(5/2))/Sqrt[3 + 5*x], x, 9, (-87476*Sqrt[1 - 2*x]*Sqrt[2 + 3*x]*Sqrt[3 + 5*x])/590625 + (403*Sqrt[1 - 2*x]*(2 + 3*x)^(3/2)*Sqrt[3 + 5*x])/118125 + (178*Sqrt[1 - 2*x]*(2 + 3*x)^(5/2)*Sqrt[3 + 5*x])/4725 + (2*(1 - 2*x)^(3/2)*(2 + 3*x)^(5/2)*Sqrt[3 + 5*x])/45 - (6515539*EllipticE[ArcSin[Sqrt[5/11]*Sqrt[1 - 2*x]], 33/35])/(506250*Sqrt[35]) + (87476*EllipticF[ArcSin[Sqrt[3/7]*Sqrt[1 - 2*x]], 35/33])/(253125*Sqrt[33])}
{((1 - 2*x)^(3/2)*(2 + 3*x)^(3/2))/Sqrt[3 + 5*x], x, 8, (-487*Sqrt[1 - 2*x]*Sqrt[2 + 3*x]*Sqrt[3 + 5*x])/13125 + (62*Sqrt[1 - 2*x]*(2 + 3*x)^(3/2)*Sqrt[3 + 5*x])/875 + (2*(1 - 2*x)^(3/2)*(2 + 3*x)^(3/2)*Sqrt[3 + 5*x])/35 - (46159*EllipticE[ArcSin[Sqrt[5/11]*Sqrt[1 - 2*x]], 33/35])/(5625*Sqrt[35]) + (487*EllipticF[ArcSin[Sqrt[3/7]*Sqrt[1 - 2*x]], 35/33])/(5625*Sqrt[33])}
{((1 - 2*x)^(3/2)*Sqrt[2 + 3*x])/Sqrt[3 + 5*x], x, 7, (194*Sqrt[1 - 2*x]*Sqrt[2 + 3*x]*Sqrt[3 + 5*x])/1125 + (2*(1 - 2*x)^(3/2)*Sqrt[2 + 3*x]*Sqrt[3 + 5*x])/25 - (2797*Sqrt[7/5]*EllipticE[ArcSin[Sqrt[5/11]*Sqrt[1 - 2*x]], 33/35])/3375 - (2828*EllipticF[ArcSin[Sqrt[3/7]*Sqrt[1 - 2*x]], 35/33])/(3375*Sqrt[33])}
{(1 - 2*x)^(3/2)/(Sqrt[2 + 3*x]*Sqrt[3 + 5*x]), x, 6, (-4*Sqrt[1 - 2*x]*Sqrt[2 + 3*x]*Sqrt[3 + 5*x])/45 + (272*Sqrt[7/5]*EllipticE[ArcSin[Sqrt[5/11]*Sqrt[1 - 2*x]], 33/35])/135 - (1442*EllipticF[ArcSin[Sqrt[3/7]*Sqrt[1 - 2*x]], 35/33])/(135*Sqrt[33])}
{(1 - 2*x)^(3/2)/((2 + 3*x)^(3/2)*Sqrt[3 + 5*x]), x, 8, (2*(1 - 2*x)^(3/2)*Sqrt[3 + 5*x])/Sqrt[2 + 3*x] + (4*Sqrt[1 - 2*x]*Sqrt[2 + 3*x]*Sqrt[3 + 5*x])/3 - (74*Sqrt[7/5]*EllipticE[ArcSin[Sqrt[5/11]*Sqrt[1 - 2*x]], 33/35])/9 + (56*EllipticF[ArcSin[Sqrt[3/7]*Sqrt[1 - 2*x]], 35/33])/(9*Sqrt[33])}
{(1 - 2*x)^(3/2)/((2 + 3*x)^(5/2)*Sqrt[3 + 5*x]), x, 7, (2*(1 - 2*x)^(3/2)*Sqrt[3 + 5*x])/(3*(2 + 3*x)^(3/2)) + (128*Sqrt[1 - 2*x]*Sqrt[3 + 5*x])/(9*Sqrt[2 + 3*x]) - (124*Sqrt[35]*EllipticE[ArcSin[Sqrt[5/11]*Sqrt[1 - 2*x]], 33/35])/27 + (116*EllipticF[ArcSin[Sqrt[3/7]*Sqrt[1 - 2*x]], 35/33])/(27*Sqrt[33])}
{(1 - 2*x)^(3/2)/((2 + 3*x)^(7/2)*Sqrt[3 + 5*x]), x, 8, (2*(1 - 2*x)^(3/2)*Sqrt[3 + 5*x])/(5*(2 + 3*x)^(5/2)) + (268*Sqrt[1 - 2*x]*Sqrt[3 + 5*x])/(45*(2 + 3*x)^(3/2)) + (17804*Sqrt[1 - 2*x]*Sqrt[3 + 5*x])/(315*Sqrt[2 + 3*x]) - (17804*EllipticE[ArcSin[Sqrt[5/11]*Sqrt[1 - 2*x]], 33/35])/(27*Sqrt[35]) + (512*EllipticF[ArcSin[Sqrt[3/7]*Sqrt[1 - 2*x]], 35/33])/(27*Sqrt[33])}
{(1 - 2*x)^(3/2)/((2 + 3*x)^(9/2)*Sqrt[3 + 5*x]), x, 9, (2*(1 - 2*x)^(3/2)*Sqrt[3 + 5*x])/(7*(2 + 3*x)^(7/2)) + (136*Sqrt[1 - 2*x]*Sqrt[3 + 5*x])/(35*(2 + 3*x)^(5/2)) + (18068*Sqrt[1 - 2*x]*Sqrt[3 + 5*x])/(735*(2 + 3*x)^(3/2)) + (1255552*Sqrt[1 - 2*x]*Sqrt[3 + 5*x])/(5145*Sqrt[2 + 3*x]) - (1255552*EllipticE[ArcSin[Sqrt[5/11]*Sqrt[1 - 2*x]], 33/35])/(441*Sqrt[35]) + (36136*EllipticF[ArcSin[Sqrt[3/7]*Sqrt[1 - 2*x]], 35/33])/(441*Sqrt[33])}


{((1 - 2*x)^(3/2)*(2 + 3*x)^(7/2))/(3 + 5*x)^(3/2), x, 10, (-2*(1 - 2*x)^(3/2)*(2 + 3*x)^(7/2))/(5*Sqrt[3 + 5*x]) - (12601*Sqrt[1 - 2*x]*Sqrt[2 + 3*x]*Sqrt[3 + 5*x])/196875 + (5153*Sqrt[1 - 2*x]*(2 + 3*x)^(3/2)*Sqrt[3 + 5*x])/39375 + (958*Sqrt[1 - 2*x]*(2 + 3*x)^(5/2)*Sqrt[3 + 5*x])/1575 - (8*Sqrt[1 - 2*x]*(2 + 3*x)^(7/2)*Sqrt[3 + 5*x])/45 - (1473539*EllipticE[ArcSin[Sqrt[5/11]*Sqrt[1 - 2*x]], 33/35])/(168750*Sqrt[35]) + (12601*EllipticF[ArcSin[Sqrt[3/7]*Sqrt[1 - 2*x]], 35/33])/(84375*Sqrt[33])}
{((1 - 2*x)^(3/2)*(2 + 3*x)^(5/2))/(3 + 5*x)^(3/2), x, 9, (-2*(1 - 2*x)^(3/2)*(2 + 3*x)^(5/2))/(5*Sqrt[3 + 5*x]) + (2719*Sqrt[1 - 2*x]*Sqrt[2 + 3*x]*Sqrt[3 + 5*x])/21875 + (2818*Sqrt[1 - 2*x]*(2 + 3*x)^(3/2)*Sqrt[3 + 5*x])/4375 - (32*Sqrt[1 - 2*x]*(2 + 3*x)^(5/2)*Sqrt[3 + 5*x])/175 - (47342*EllipticE[ArcSin[Sqrt[5/11]*Sqrt[1 - 2*x]], 33/35])/(9375*Sqrt[35]) - (2719*EllipticF[ArcSin[Sqrt[3/7]*Sqrt[1 - 2*x]], 35/33])/(9375*Sqrt[33])}
{((1 - 2*x)^(3/2)*(2 + 3*x)^(3/2))/(3 + 5*x)^(3/2), x, 8, (-2*(1 - 2*x)^(3/2)*(2 + 3*x)^(3/2))/(5*Sqrt[3 + 5*x]) + (458*Sqrt[1 - 2*x]*Sqrt[2 + 3*x]*Sqrt[3 + 5*x])/625 - (24*Sqrt[1 - 2*x]*(2 + 3*x)^(3/2)*Sqrt[3 + 5*x])/125 - (169*Sqrt[7/5]*EllipticE[ArcSin[Sqrt[5/11]*Sqrt[1 - 2*x]], 33/35])/1875 - (3206*EllipticF[ArcSin[Sqrt[3/7]*Sqrt[1 - 2*x]], 35/33])/(1875*Sqrt[33])}
{((1 - 2*x)^(3/2)*Sqrt[2 + 3*x])/(3 + 5*x)^(3/2), x, 7, (-2*(1 - 2*x)^(3/2)*Sqrt[2 + 3*x])/(5*Sqrt[3 + 5*x]) - (16*Sqrt[1 - 2*x]*Sqrt[2 + 3*x]*Sqrt[3 + 5*x])/75 + (458*Sqrt[7/5]*EllipticE[ArcSin[Sqrt[5/11]*Sqrt[1 - 2*x]], 33/35])/225 - (1358*EllipticF[ArcSin[Sqrt[3/7]*Sqrt[1 - 2*x]], 35/33])/(225*Sqrt[33])}
{(1 - 2*x)^(3/2)/(Sqrt[2 + 3*x]*(3 + 5*x)^(3/2)), x, 8, (-2*(1 - 2*x)^(3/2)*Sqrt[2 + 3*x])/Sqrt[3 + 5*x] - (4*Sqrt[1 - 2*x]*Sqrt[2 + 3*x]*Sqrt[3 + 5*x])/5 + (62*Sqrt[7/5]*EllipticE[ArcSin[Sqrt[5/11]*Sqrt[1 - 2*x]], 33/35])/15 + (28*EllipticF[ArcSin[Sqrt[3/7]*Sqrt[1 - 2*x]], 35/33])/(15*Sqrt[33])}
{(1 - 2*x)^(3/2)/((2 + 3*x)^(3/2)*(3 + 5*x)^(3/2)), x, 7, (2*(1 - 2*x)^(3/2))/(Sqrt[2 + 3*x]*Sqrt[3 + 5*x]) - (44*Sqrt[1 - 2*x]*Sqrt[2 + 3*x])/Sqrt[3 + 5*x] + (136*Sqrt[7/5]*EllipticE[ArcSin[Sqrt[5/11]*Sqrt[1 - 2*x]], 33/35])/3 - (28*EllipticF[ArcSin[Sqrt[3/7]*Sqrt[1 - 2*x]], 35/33])/(3*Sqrt[33])}
{(1 - 2*x)^(3/2)/((2 + 3*x)^(5/2)*(3 + 5*x)^(3/2)), x, 8, (2*(1 - 2*x)^(3/2))/(3*(2 + 3*x)^(3/2)*Sqrt[3 + 5*x]) + (268*Sqrt[1 - 2*x])/(9*Sqrt[2 + 3*x]*Sqrt[3 + 5*x]) - (2660*Sqrt[1 - 2*x]*Sqrt[2 + 3*x])/(9*Sqrt[3 + 5*x]) + (532*Sqrt[35]*EllipticE[ArcSin[Sqrt[5/11]*Sqrt[1 - 2*x]], 33/35])/9 - (536*EllipticF[ArcSin[Sqrt[3/7]*Sqrt[1 - 2*x]], 35/33])/(9*Sqrt[33])}
{(1 - 2*x)^(3/2)/((2 + 3*x)^(7/2)*(3 + 5*x)^(3/2)), x, 9, (2*(1 - 2*x)^(3/2))/(5*(2 + 3*x)^(5/2)*Sqrt[3 + 5*x]) + (136*Sqrt[1 - 2*x])/(15*(2 + 3*x)^(3/2)*Sqrt[3 + 5*x]) + (6116*Sqrt[1 - 2*x])/(35*Sqrt[2 + 3*x]*Sqrt[3 + 5*x]) - (36968*Sqrt[1 - 2*x]*Sqrt[2 + 3*x])/(21*Sqrt[3 + 5*x]) + (36968*EllipticE[ArcSin[Sqrt[5/11]*Sqrt[1 - 2*x]], 33/35])/(3*Sqrt[35]) - (1064*EllipticF[ArcSin[Sqrt[3/7]*Sqrt[1 - 2*x]], 35/33])/(3*Sqrt[33])}
{(1 - 2*x)^(3/2)/((2 + 3*x)^(9/2)*(3 + 5*x)^(3/2)), x, 10, (2*(1 - 2*x)^(3/2))/(7*(2 + 3*x)^(7/2)*Sqrt[3 + 5*x]) + (548*Sqrt[1 - 2*x])/(105*(2 + 3*x)^(5/2)*Sqrt[3 + 5*x]) + (12276*Sqrt[1 - 2*x])/(245*(2 + 3*x)^(3/2)*Sqrt[3 + 5*x]) + (1706144*Sqrt[1 - 2*x])/(1715*Sqrt[2 + 3*x]*Sqrt[3 + 5*x]) - (10312712*Sqrt[1 - 2*x]*Sqrt[2 + 3*x])/(1029*Sqrt[3 + 5*x]) + (10312712*EllipticE[ArcSin[Sqrt[5/11]*Sqrt[1 - 2*x]], 33/35])/(147*Sqrt[35]) - (296816*EllipticF[ArcSin[Sqrt[3/7]*Sqrt[1 - 2*x]], 35/33])/(147*Sqrt[33])}


{((1 - 2*x)^(3/2)*(2 + 3*x)^(7/2))/(3 + 5*x)^(5/2), x, 10, (-2*(1 - 2*x)^(3/2)*(2 + 3*x)^(7/2))/(15*(3 + 5*x)^(3/2)) - (6*Sqrt[1 - 2*x]*(2 + 3*x)^(7/2))/Sqrt[3 + 5*x] + (4801*Sqrt[1 - 2*x]*Sqrt[2 + 3*x]*Sqrt[3 + 5*x])/21875 + (3872*Sqrt[1 - 2*x]*(2 + 3*x)^(3/2)*Sqrt[3 + 5*x])/4375 + (622*Sqrt[1 - 2*x]*(2 + 3*x)^(5/2)*Sqrt[3 + 5*x])/175 - (25643*EllipticE[ArcSin[Sqrt[5/11]*Sqrt[1 - 2*x]], 33/35])/(9375*Sqrt[35]) - (4801*EllipticF[ArcSin[Sqrt[3/7]*Sqrt[1 - 2*x]], 35/33])/(9375*Sqrt[33])}
{((1 - 2*x)^(3/2)*(2 + 3*x)^(5/2))/(3 + 5*x)^(5/2), x, 9, (-2*(1 - 2*x)^(3/2)*(2 + 3*x)^(5/2))/(15*(3 + 5*x)^(3/2)) - (106*Sqrt[1 - 2*x]*(2 + 3*x)^(5/2))/(25*Sqrt[3 + 5*x]) + (2264*Sqrt[1 - 2*x]*Sqrt[2 + 3*x]*Sqrt[3 + 5*x])/3125 + (1558*Sqrt[1 - 2*x]*(2 + 3*x)^(3/2)*Sqrt[3 + 5*x])/625 + (1973*Sqrt[7/5]*EllipticE[ArcSin[Sqrt[5/11]*Sqrt[1 - 2*x]], 33/35])/9375 - (15848*EllipticF[ArcSin[Sqrt[3/7]*Sqrt[1 - 2*x]], 35/33])/(9375*Sqrt[33])}
{((1 - 2*x)^(3/2)*(2 + 3*x)^(3/2))/(3 + 5*x)^(5/2), x, 8, (-2*(1 - 2*x)^(3/2)*(2 + 3*x)^(3/2))/(15*(3 + 5*x)^(3/2)) - (62*Sqrt[1 - 2*x]*(2 + 3*x)^(3/2))/(25*Sqrt[3 + 5*x]) + (178*Sqrt[1 - 2*x]*Sqrt[2 + 3*x]*Sqrt[3 + 5*x])/125 + (496*Sqrt[7/5]*EllipticE[ArcSin[Sqrt[5/11]*Sqrt[1 - 2*x]], 33/35])/375 - (1246*EllipticF[ArcSin[Sqrt[3/7]*Sqrt[1 - 2*x]], 35/33])/(375*Sqrt[33])}
{((1 - 2*x)^(3/2)*Sqrt[2 + 3*x])/(3 + 5*x)^(5/2), x, 7, (-2*(1 - 2*x)^(3/2)*Sqrt[2 + 3*x])/(15*(3 + 5*x)^(3/2)) - (18*Sqrt[1 - 2*x]*Sqrt[2 + 3*x])/(25*Sqrt[3 + 5*x]) + (38*Sqrt[7/5]*EllipticE[ArcSin[Sqrt[5/11]*Sqrt[1 - 2*x]], 33/35])/75 + (112*EllipticF[ArcSin[Sqrt[3/7]*Sqrt[1 - 2*x]], 35/33])/(75*Sqrt[33])}
{(1 - 2*x)^(3/2)/(Sqrt[2 + 3*x]*(3 + 5*x)^(5/2)), x, 7, (-2*(1 - 2*x)^(3/2)*Sqrt[2 + 3*x])/(3*(3 + 5*x)^(3/2)) + (48*Sqrt[1 - 2*x]*Sqrt[2 + 3*x])/(5*Sqrt[3 + 5*x]) - (148*Sqrt[7/5]*EllipticE[ArcSin[Sqrt[5/11]*Sqrt[1 - 2*x]], 33/35])/15 + (28*EllipticF[ArcSin[Sqrt[3/7]*Sqrt[1 - 2*x]], 35/33])/(15*Sqrt[33])}
{(1 - 2*x)^(3/2)/((2 + 3*x)^(3/2)*(3 + 5*x)^(5/2)), x, 8, (2*(1 - 2*x)^(3/2))/(Sqrt[2 + 3*x]*(3 + 5*x)^(3/2)) - (88*Sqrt[1 - 2*x]*Sqrt[2 + 3*x])/(3*(3 + 5*x)^(3/2)) + (556*Sqrt[1 - 2*x]*Sqrt[2 + 3*x])/(3*Sqrt[3 + 5*x]) - (556*Sqrt[7/5]*EllipticE[ArcSin[Sqrt[5/11]*Sqrt[1 - 2*x]], 33/35])/3 + (112*EllipticF[ArcSin[Sqrt[3/7]*Sqrt[1 - 2*x]], 35/33])/(3*Sqrt[33])}
{(1 - 2*x)^(3/2)/((2 + 3*x)^(5/2)*(3 + 5*x)^(5/2)), x, 9, (2*(1 - 2*x)^(3/2))/(3*(2 + 3*x)^(3/2)*(3 + 5*x)^(3/2)) + (136*Sqrt[1 - 2*x])/(3*Sqrt[2 + 3*x]*(3 + 5*x)^(3/2)) - (300*Sqrt[1 - 2*x]*Sqrt[2 + 3*x])/(3 + 5*x)^(3/2) + (5440*Sqrt[1 - 2*x]*Sqrt[2 + 3*x])/(3*Sqrt[3 + 5*x]) - (1088*Sqrt[35]*EllipticE[ArcSin[Sqrt[5/11]*Sqrt[1 - 2*x]], 33/35])/3 + (1096*EllipticF[ArcSin[Sqrt[3/7]*Sqrt[1 - 2*x]], 35/33])/(3*Sqrt[33])}
{(1 - 2*x)^(3/2)/((2 + 3*x)^(7/2)*(3 + 5*x)^(5/2)), x, 10, (2*(1 - 2*x)^(3/2))/(5*(2 + 3*x)^(5/2)*(3 + 5*x)^(3/2)) + (548*Sqrt[1 - 2*x])/(45*(2 + 3*x)^(3/2)*(3 + 5*x)^(3/2)) + (111884*Sqrt[1 - 2*x])/(315*Sqrt[2 + 3*x]*(3 + 5*x)^(3/2)) - (16616*Sqrt[1 - 2*x]*Sqrt[2 + 3*x])/(7*(3 + 5*x)^(3/2)) + (301304*Sqrt[1 - 2*x]*Sqrt[2 + 3*x])/(21*Sqrt[3 + 5*x]) - (301304*EllipticE[ArcSin[Sqrt[5/11]*Sqrt[1 - 2*x]], 33/35])/(3*Sqrt[35]) + (8672*EllipticF[ArcSin[Sqrt[3/7]*Sqrt[1 - 2*x]], 35/33])/(3*Sqrt[33])}


(* ::Subsection::Closed:: *)
(*Integrands of the form (a+b x)^(m/2) (c+d x)^(n/2) (e+f x)^(5/2)*)


(* ::Subsubsection::Closed:: *)
(*n<0*)


{(1 - 2*x)^(5/2)*(2 + 3*x)^(5/2)*Sqrt[3 + 5*x], x, 11, (-69808931*Sqrt[1 - 2*x]*Sqrt[2 + 3*x]*Sqrt[3 + 5*x])/168918750 - (445024*Sqrt[1 - 2*x]*Sqrt[2 + 3*x]*(3 + 5*x)^(3/2))/9384375 + (32717*Sqrt[1 - 2*x]*(2 + 3*x)^(3/2)*(3 + 5*x)^(3/2))/1126125 + (34*Sqrt[1 - 2*x]*(2 + 3*x)^(5/2)*(3 + 5*x)^(3/2))/2475 + (62*(1 - 2*x)^(3/2)*(2 + 3*x)^(5/2)*(3 + 5*x)^(3/2))/2145 + (2*(1 - 2*x)^(5/2)*(2 + 3*x)^(5/2)*(3 + 5*x)^(3/2))/65 - (1163388067*EllipticE[ArcSin[Sqrt[5/11]*Sqrt[1 - 2*x]], 33/35])/(36196875*Sqrt[35]) + (67138787*EllipticF[ArcSin[Sqrt[3/7]*Sqrt[1 - 2*x]], 35/33])/(72393750*Sqrt[33])}
{(1 - 2*x)^(5/2)*(2 + 3*x)^(3/2)*Sqrt[3 + 5*x], x, 10, (-4738087*Sqrt[1 - 2*x]*Sqrt[2 + 3*x]*Sqrt[3 + 5*x])/19490625 + (38729*Sqrt[1 - 2*x]*Sqrt[2 + 3*x]*(3 + 5*x)^(3/2))/2165625 + (2866*Sqrt[1 - 2*x]*(2 + 3*x)^(3/2)*(3 + 5*x)^(3/2))/86625 + (106*(1 - 2*x)^(3/2)*(2 + 3*x)^(3/2)*(3 + 5*x)^(3/2))/2475 + (2*(1 - 2*x)^(5/2)*(2 + 3*x)^(3/2)*(3 + 5*x)^(3/2))/55 - (326256461*EllipticE[ArcSin[Sqrt[5/11]*Sqrt[1 - 2*x]], 33/35])/(16706250*Sqrt[35]) + (4854274*EllipticF[ArcSin[Sqrt[3/7]*Sqrt[1 - 2*x]], 35/33])/(8353125*Sqrt[33])}
{(1 - 2*x)^(5/2)*Sqrt[2 + 3*x]*Sqrt[3 + 5*x], x, 9, (-110717*Sqrt[1 - 2*x]*Sqrt[2 + 3*x]*Sqrt[3 + 5*x])/1063125 + (10214*Sqrt[1 - 2*x]*Sqrt[2 + 3*x]*(3 + 5*x)^(3/2))/118125 + (326*(1 - 2*x)^(3/2)*Sqrt[2 + 3*x]*(3 + 5*x)^(3/2))/4725 + (2*(1 - 2*x)^(5/2)*Sqrt[2 + 3*x]*(3 + 5*x)^(3/2))/45 - (6799613*EllipticE[ArcSin[Sqrt[5/11]*Sqrt[1 - 2*x]], 33/35])/(455625*Sqrt[35]) + (284159*EllipticF[ArcSin[Sqrt[3/7]*Sqrt[1 - 2*x]], 35/33])/(455625*Sqrt[33])}
{((1 - 2*x)^(5/2)*Sqrt[3 + 5*x])/Sqrt[2 + 3*x], x, 8, (4282*Sqrt[1 - 2*x]*Sqrt[2 + 3*x]*Sqrt[3 + 5*x])/7875 + (118*(1 - 2*x)^(3/2)*Sqrt[2 + 3*x]*Sqrt[3 + 5*x])/525 + (2*(1 - 2*x)^(5/2)*Sqrt[2 + 3*x]*Sqrt[3 + 5*x])/21 - (86741*EllipticE[ArcSin[Sqrt[5/11]*Sqrt[1 - 2*x]], 33/35])/(3375*Sqrt[35]) + (16088*EllipticF[ArcSin[Sqrt[3/7]*Sqrt[1 - 2*x]], 35/33])/(3375*Sqrt[33])}
{((1 - 2*x)^(5/2)*Sqrt[3 + 5*x])/(2 + 3*x)^(3/2), x, 8, (-2*(1 - 2*x)^(5/2)*Sqrt[3 + 5*x])/(3*Sqrt[2 + 3*x]) - (1076*Sqrt[1 - 2*x]*Sqrt[2 + 3*x]*Sqrt[3 + 5*x])/675 - (8*(1 - 2*x)^(3/2)*Sqrt[2 + 3*x]*Sqrt[3 + 5*x])/15 + (31588*Sqrt[7/5]*EllipticE[ArcSin[Sqrt[5/11]*Sqrt[1 - 2*x]], 33/35])/2025 - (96838*EllipticF[ArcSin[Sqrt[3/7]*Sqrt[1 - 2*x]], 35/33])/(2025*Sqrt[33])}
{((1 - 2*x)^(5/2)*Sqrt[3 + 5*x])/(2 + 3*x)^(5/2), x, 8, (-2*(1 - 2*x)^(5/2)*Sqrt[3 + 5*x])/(9*(2 + 3*x)^(3/2)) + (10*(1 - 2*x)^(3/2)*Sqrt[3 + 5*x])/(3*Sqrt[2 + 3*x]) + (196*Sqrt[1 - 2*x]*Sqrt[2 + 3*x]*Sqrt[3 + 5*x])/81 - (4418*Sqrt[7/5]*EllipticE[ArcSin[Sqrt[5/11]*Sqrt[1 - 2*x]], 33/35])/243 + (8288*EllipticF[ArcSin[Sqrt[3/7]*Sqrt[1 - 2*x]], 35/33])/(243*Sqrt[33])}
{((1 - 2*x)^(5/2)*Sqrt[3 + 5*x])/(2 + 3*x)^(7/2), x, 8, (-2*(1 - 2*x)^(5/2)*Sqrt[3 + 5*x])/(15*(2 + 3*x)^(5/2)) + (2*(1 - 2*x)^(3/2)*Sqrt[3 + 5*x])/(3*(2 + 3*x)^(3/2)) + (8*Sqrt[1 - 2*x]*Sqrt[3 + 5*x])/Sqrt[2 + 3*x] - 12*Sqrt[7/5]*EllipticE[ArcSin[Sqrt[5/11]*Sqrt[1 - 2*x]], 33/35] - (4*EllipticF[ArcSin[Sqrt[3/7]*Sqrt[1 - 2*x]], 35/33])/Sqrt[33]}
{((1 - 2*x)^(5/2)*Sqrt[3 + 5*x])/(2 + 3*x)^(9/2), x, 9, -((2*(1 - 2*x)^(5/2)*Sqrt[3 + 5*x])/(21*(2 + 3*x)^(7/2))) + (2*(1 - 2*x)^(3/2)*Sqrt[3 + 5*x])/(7*(2 + 3*x)^(5/2)) + (524*Sqrt[1 - 2*x]*Sqrt[3 + 5*x])/(189*(2 + 3*x)^(3/2)) + (36052*Sqrt[1 - 2*x]*Sqrt[3 + 5*x])/(1323*Sqrt[2 + 3*x]) - (36052/567)*Sqrt[5/7]*EllipticE[ArcSin[Sqrt[5/11]*Sqrt[1 - 2*x]], 33/35] + (5360*EllipticF[ArcSin[Sqrt[3/7]*Sqrt[1 - 2*x]], 35/33])/(567*Sqrt[33])}
{((1 - 2*x)^(5/2)*Sqrt[3 + 5*x])/(2 + 3*x)^(11/2), x, 10, -((2*(1 - 2*x)^(5/2)*Sqrt[3 + 5*x])/(27*(2 + 3*x)^(9/2))) + (10*(1 - 2*x)^(3/2)*Sqrt[3 + 5*x])/(63*(2 + 3*x)^(7/2)) + (832*Sqrt[1 - 2*x]*Sqrt[3 + 5*x])/(567*(2 + 3*x)^(5/2)) + (112436*Sqrt[1 - 2*x]*Sqrt[3 + 5*x])/(11907*(2 + 3*x)^(3/2)) + (7810384*Sqrt[1 - 2*x]*Sqrt[3 + 5*x])/(83349*Sqrt[2 + 3*x]) - (7810384*Sqrt[5/7]*EllipticE[ArcSin[Sqrt[5/11]*Sqrt[1 - 2*x]], 33/35])/35721 + (1124360*EllipticF[ArcSin[Sqrt[3/7]*Sqrt[1 - 2*x]], 35/33])/(35721*Sqrt[33])}
{((1 - 2*x)^(5/2)*Sqrt[3 + 5*x])/(2 + 3*x)^(13/2), x, 11, -((2*(1 - 2*x)^(5/2)*Sqrt[3 + 5*x])/(33*(2 + 3*x)^(11/2))) + (10*(1 - 2*x)^(3/2)*Sqrt[3 + 5*x])/(99*(2 + 3*x)^(9/2)) + (1900*Sqrt[1 - 2*x]*Sqrt[3 + 5*x])/(2079*(2 + 3*x)^(7/2)) + (76492*Sqrt[1 - 2*x]*Sqrt[3 + 5*x])/(14553*(2 + 3*x)^(5/2)) + (3560432*Sqrt[1 - 2*x]*Sqrt[3 + 5*x])/(101871*(2 + 3*x)^(3/2)) + (247408648*Sqrt[1 - 2*x]*Sqrt[3 + 5*x])/(713097*Sqrt[2 + 3*x]) - (247408648*Sqrt[5/7]*EllipticE[ArcSin[Sqrt[5/11]*Sqrt[1 - 2*x]], 33/35])/305613 + (35604320*EllipticF[ArcSin[Sqrt[3/7]*Sqrt[1 - 2*x]], 35/33])/(305613*Sqrt[33])}


{(1 - 2*x)^(5/2)*(2 + 3*x)^(5/2)*(3 + 5*x)^(3/2), x, 12, (-13267820528*Sqrt[1 - 2*x]*Sqrt[2 + 3*x]*Sqrt[3 + 5*x])/11402015625 - (400516993*Sqrt[1 - 2*x]*Sqrt[2 + 3*x]*(3 + 5*x)^(3/2))/2533781250 - (569519*Sqrt[1 - 2*x]*Sqrt[2 + 3*x]*(3 + 5*x)^(5/2))/28153125 + (142391*Sqrt[1 - 2*x]*(2 + 3*x)^(3/2)*(3 + 5*x)^(5/2))/7239375 + (3698*Sqrt[1 - 2*x]*(2 + 3*x)^(5/2)*(3 + 5*x)^(5/2))/482625 + (62*(1 - 2*x)^(3/2)*(2 + 3*x)^(5/2)*(3 + 5*x)^(5/2))/2925 + (2*(1 - 2*x)^(5/2)*(2 + 3*x)^(5/2)*(3 + 5*x)^(5/2))/75 - (1764163292393*EllipticE[ArcSin[Sqrt[5/11]*Sqrt[1 - 2*x]], 33/35])/(19546312500*Sqrt[35]) + (25385346787*EllipticF[ArcSin[Sqrt[3/7]*Sqrt[1 - 2*x]], 35/33])/(9773156250*Sqrt[33])}
{(1 - 2*x)^(5/2)*(2 + 3*x)^(3/2)*(3 + 5*x)^(3/2), x, 11, (-923943703*Sqrt[1 - 2*x]*Sqrt[2 + 3*x]*Sqrt[3 + 5*x])/1520268750 - (6794792*Sqrt[1 - 2*x]*Sqrt[2 + 3*x]*(3 + 5*x)^(3/2))/84459375 + (25603*Sqrt[1 - 2*x]*Sqrt[2 + 3*x]*(3 + 5*x)^(5/2))/1876875 + (8318*Sqrt[1 - 2*x]*(2 + 3*x)^(3/2)*(3 + 5*x)^(5/2))/482625 + (106*(1 - 2*x)^(3/2)*(2 + 3*x)^(3/2)*(3 + 5*x)^(5/2))/3575 + (2*(1 - 2*x)^(5/2)*(2 + 3*x)^(3/2)*(3 + 5*x)^(5/2))/65 - (30660308017*EllipticE[ArcSin[Sqrt[5/11]*Sqrt[1 - 2*x]], 33/35])/(651543750*Sqrt[35]) + (880870681*EllipticF[ArcSin[Sqrt[3/7]*Sqrt[1 - 2*x]], 35/33])/(651543750*Sqrt[33])}
{(1 - 2*x)^(5/2)*Sqrt[2 + 3*x]*(3 + 5*x)^(3/2), x, 10, (-12996374*Sqrt[1 - 2*x]*Sqrt[2 + 3*x]*Sqrt[3 + 5*x])/35083125 - (78797*Sqrt[1 - 2*x]*Sqrt[2 + 3*x]*(3 + 5*x)^(3/2))/3898125 + (30362*Sqrt[1 - 2*x]*Sqrt[2 + 3*x]*(3 + 5*x)^(5/2))/779625 + (326*(1 - 2*x)^(3/2)*Sqrt[2 + 3*x]*(3 + 5*x)^(5/2))/7425 + (2*(1 - 2*x)^(5/2)*Sqrt[2 + 3*x]*(3 + 5*x)^(5/2))/55 - (829177897*EllipticE[ArcSin[Sqrt[5/11]*Sqrt[1 - 2*x]], 33/35])/(30071250*Sqrt[35]) + (11437073*EllipticF[ArcSin[Sqrt[3/7]*Sqrt[1 - 2*x]], 35/33])/(15035625*Sqrt[33])}
{((1 - 2*x)^(5/2)*(3 + 5*x)^(3/2))/Sqrt[2 + 3*x], x, 9, (-429479*Sqrt[1 - 2*x]*Sqrt[2 + 3*x]*Sqrt[3 + 5*x])/637875 + (14318*Sqrt[1 - 2*x]*Sqrt[2 + 3*x]*(3 + 5*x)^(3/2))/70875 + (362*(1 - 2*x)^(3/2)*Sqrt[2 + 3*x]*(3 + 5*x)^(3/2))/2835 + (2*(1 - 2*x)^(5/2)*Sqrt[2 + 3*x]*(3 + 5*x)^(3/2))/27 - (4457606*EllipticE[ArcSin[Sqrt[5/11]*Sqrt[1 - 2*x]], 33/35])/(273375*Sqrt[35]) - (150217*EllipticF[ArcSin[Sqrt[3/7]*Sqrt[1 - 2*x]], 35/33])/(273375*Sqrt[33])}
{((1 - 2*x)^(5/2)*(3 + 5*x)^(3/2))/(2 + 3*x)^(3/2), x, 9, (124724*Sqrt[1 - 2*x]*Sqrt[2 + 3*x]*Sqrt[3 + 5*x])/14175 - (2*(1 - 2*x)^(5/2)*(3 + 5*x)^(3/2))/(3*Sqrt[2 + 3*x]) - (2108*Sqrt[1 - 2*x]*Sqrt[2 + 3*x]*(3 + 5*x)^(3/2))/1575 - (32*(1 - 2*x)^(3/2)*Sqrt[2 + 3*x]*(3 + 5*x)^(3/2))/63 - (481339*EllipticE[ArcSin[Sqrt[5/11]*Sqrt[1 - 2*x]], 33/35])/(6075*Sqrt[35]) + (145102*EllipticF[ArcSin[Sqrt[3/7]*Sqrt[1 - 2*x]], 35/33])/(6075*Sqrt[33])}
{((1 - 2*x)^(5/2)*(3 + 5*x)^(3/2))/(2 + 3*x)^(5/2), x, 9, (-43214*Sqrt[1 - 2*x]*Sqrt[2 + 3*x]*Sqrt[3 + 5*x])/1215 - (2*(1 - 2*x)^(5/2)*(3 + 5*x)^(3/2))/(9*(2 + 3*x)^(3/2)) + (230*(1 - 2*x)^(3/2)*(3 + 5*x)^(3/2))/(27*Sqrt[2 + 3*x]) + (788*Sqrt[1 - 2*x]*Sqrt[2 + 3*x]*(3 + 5*x)^(3/2))/135 + (116854*Sqrt[7/5]*EllipticE[ArcSin[Sqrt[5/11]*Sqrt[1 - 2*x]], 33/35])/3645 - (331954*EllipticF[ArcSin[Sqrt[3/7]*Sqrt[1 - 2*x]], 35/33])/(3645*Sqrt[33])}
{((1 - 2*x)^(5/2)*(3 + 5*x)^(3/2))/(2 + 3*x)^(7/2), x, 9, (5264*Sqrt[1 - 2*x]*Sqrt[2 + 3*x]*Sqrt[3 + 5*x])/243 - (2*(1 - 2*x)^(5/2)*(3 + 5*x)^(3/2))/(15*(2 + 3*x)^(5/2)) + (46*(1 - 2*x)^(3/2)*(3 + 5*x)^(3/2))/(27*(2 + 3*x)^(3/2)) - (316*Sqrt[1 - 2*x]*(3 + 5*x)^(3/2))/(27*Sqrt[2 + 3*x]) - (19174*Sqrt[7/5]*EllipticE[ArcSin[Sqrt[5/11]*Sqrt[1 - 2*x]], 33/35])/729 + (42412*EllipticF[ArcSin[Sqrt[3/7]*Sqrt[1 - 2*x]], 35/33])/(729*Sqrt[33])}
{((1 - 2*x)^(5/2)*(3 + 5*x)^(3/2))/(2 + 3*x)^(9/2), x, 9, -((4244*Sqrt[1 - 2*x]*Sqrt[3 + 5*x])/(3969*Sqrt[2 + 3*x])) - (2*(1 - 2*x)^(5/2)*(3 + 5*x)^(3/2))/(21*(2 + 3*x)^(7/2)) + (46*(1 - 2*x)^(3/2)*(3 + 5*x)^(3/2))/(63*(2 + 3*x)^(5/2)) + (608*Sqrt[1 - 2*x]*(3 + 5*x)^(3/2))/(189*(2 + 3*x)^(3/2)) - (11576*Sqrt[5/7]*EllipticE[ArcSin[Sqrt[5/11]*Sqrt[1 - 2*x]], 33/35])/1701 - (16700*EllipticF[ArcSin[Sqrt[3/7]*Sqrt[1 - 2*x]], 35/33])/(1701*Sqrt[33])}
{((1 - 2*x)^(5/2)*(3 + 5*x)^(3/2))/(2 + 3*x)^(11/2), x, 10, -((104036*Sqrt[1 - 2*x]*Sqrt[3 + 5*x])/(35721*(2 + 3*x)^(3/2))) + (3545996*Sqrt[1 - 2*x]*Sqrt[3 + 5*x])/(250047*Sqrt[2 + 3*x]) - (2*(1 - 2*x)^(5/2)*(3 + 5*x)^(3/2))/(27*(2 + 3*x)^(9/2)) + (230*(1 - 2*x)^(3/2)*(3 + 5*x)^(3/2))/(567*(2 + 3*x)^(7/2)) + (1532*Sqrt[1 - 2*x]*(3 + 5*x)^(3/2))/(567*(2 + 3*x)^(5/2)) - (3545996*Sqrt[5/7]*EllipticE[ArcSin[Sqrt[5/11]*Sqrt[1 - 2*x]], 33/35])/107163 + (564040*EllipticF[ArcSin[Sqrt[3/7]*Sqrt[1 - 2*x]], 35/33])/(107163*Sqrt[33])}
{((1 - 2*x)^(5/2)*(3 + 5*x)^(3/2))/(2 + 3*x)^(13/2), x, 11, -((325796*Sqrt[1 - 2*x]*Sqrt[3 + 5*x])/(130977*(2 + 3*x)^(5/2))) + (11243972*Sqrt[1 - 2*x]*Sqrt[3 + 5*x])/(2750517*(2 + 3*x)^(3/2)) + (780320008*Sqrt[1 - 2*x]*Sqrt[3 + 5*x])/(19253619*Sqrt[2 + 3*x]) - (2*(1 - 2*x)^(5/2)*(3 + 5*x)^(3/2))/(33*(2 + 3*x)^(11/2)) + (230*(1 - 2*x)^(3/2)*(3 + 5*x)^(3/2))/(891*(2 + 3*x)^(9/2)) + (12280*Sqrt[1 - 2*x]*(3 + 5*x)^(3/2))/(6237*(2 + 3*x)^(7/2)) - (780320008*Sqrt[5/7]*EllipticE[ArcSin[Sqrt[5/11]*Sqrt[1 - 2*x]], 33/35])/8251551 + (112439720*EllipticF[ArcSin[Sqrt[3/7]*Sqrt[1 - 2*x]], 35/33])/(8251551*Sqrt[33])}
{((1 - 2*x)^(5/2)*(3 + 5*x)^(3/2))/(2 + 3*x)^(15/2), x, 12, -((3347620*Sqrt[1 - 2*x]*Sqrt[3 + 5*x])/(1702701*(2 + 3*x)^(7/2))) + (23210828*Sqrt[1 - 2*x]*Sqrt[3 + 5*x])/(11918907*(2 + 3*x)^(5/2)) + (1079936248*Sqrt[1 - 2*x]*Sqrt[3 + 5*x])/(83432349*(2 + 3*x)^(3/2)) + (75041008472*Sqrt[1 - 2*x]*Sqrt[3 + 5*x])/(584026443*Sqrt[2 + 3*x]) - (2*(1 - 2*x)^(5/2)*(3 + 5*x)^(3/2))/(39*(2 + 3*x)^(13/2)) + (230*(1 - 2*x)^(3/2)*(3 + 5*x)^(3/2))/(1287*(2 + 3*x)^(11/2)) + (1300*Sqrt[1 - 2*x]*(3 + 5*x)^(3/2))/(891*(2 + 3*x)^(9/2)) - (75041008472*Sqrt[5/7]*EllipticE[ArcSin[Sqrt[5/11]*Sqrt[1 - 2*x]], 33/35])/250297047 + (10799362480*EllipticF[ArcSin[Sqrt[3/7]*Sqrt[1 - 2*x]], 35/33])/(250297047*Sqrt[33])}


{(1 - 2*x)^(5/2)*(2 + 3*x)^(3/2)*(3 + 5*x)^(5/2), x, 12, (-23763809947*Sqrt[1 - 2*x]*Sqrt[2 + 3*x]*Sqrt[3 + 5*x])/13682418750 - (359748241*Sqrt[1 - 2*x]*Sqrt[2 + 3*x]*(3 + 5*x)^(3/2))/1520268750 - (26534891*Sqrt[1 - 2*x]*Sqrt[2 + 3*x]*(3 + 5*x)^(5/2))/760134375 + (364267*Sqrt[1 - 2*x]*Sqrt[2 + 3*x]*(3 + 5*x)^(7/2))/36196875 + (8038*Sqrt[1 - 2*x]*(2 + 3*x)^(3/2)*(3 + 5*x)^(7/2))/804375 + (106*(1 - 2*x)^(3/2)*(2 + 3*x)^(3/2)*(3 + 5*x)^(7/2))/4875 + (2*(1 - 2*x)^(5/2)*(2 + 3*x)^(3/2)*(3 + 5*x)^(7/2))/75 - (1580201444291*EllipticE[ArcSin[Sqrt[5/11]*Sqrt[1 - 2*x]], 33/35])/(11727787500*Sqrt[35]) + (11371367372*EllipticF[ArcSin[Sqrt[3/7]*Sqrt[1 - 2*x]], 35/33])/(2931946875*Sqrt[33])}
{(1 - 2*x)^(5/2)*Sqrt[2 + 3*x]*(3 + 5*x)^(5/2), x, 11, (-486785077*Sqrt[1 - 2*x]*Sqrt[2 + 3*x]*Sqrt[3 + 5*x])/547296750 - (3872003*Sqrt[1 - 2*x]*Sqrt[2 + 3*x]*(3 + 5*x)^(3/2))/30405375 - (121031*Sqrt[1 - 2*x]*Sqrt[2 + 3*x]*(3 + 5*x)^(5/2))/30405375 + (2314*Sqrt[1 - 2*x]*Sqrt[2 + 3*x]*(3 + 5*x)^(7/2))/111375 + (326*(1 - 2*x)^(3/2)*Sqrt[2 + 3*x]*(3 + 5*x)^(7/2))/10725 + (2*(1 - 2*x)^(5/2)*Sqrt[2 + 3*x]*(3 + 5*x)^(7/2))/65 - (8120161139*EllipticE[ArcSin[Sqrt[5/11]*Sqrt[1 - 2*x]], 33/35])/(117277875*Sqrt[35]) + (469049629*EllipticF[ArcSin[Sqrt[3/7]*Sqrt[1 - 2*x]], 35/33])/(234555750*Sqrt[33])}
{((1 - 2*x)^(5/2)*(3 + 5*x)^(5/2))/Sqrt[2 + 3*x], x, 10, (-1654421*Sqrt[1 - 2*x]*Sqrt[2 + 3*x]*Sqrt[3 + 5*x])/4209975 - (146963*Sqrt[1 - 2*x]*Sqrt[2 + 3*x]*(3 + 5*x)^(3/2))/467775 + (9698*Sqrt[1 - 2*x]*Sqrt[2 + 3*x]*(3 + 5*x)^(5/2))/93555 + (74*(1 - 2*x)^(3/2)*Sqrt[2 + 3*x]*(3 + 5*x)^(5/2))/891 + (2*(1 - 2*x)^(5/2)*Sqrt[2 + 3*x]*(3 + 5*x)^(5/2))/33 - (146222113*EllipticE[ArcSin[Sqrt[5/11]*Sqrt[1 - 2*x]], 33/35])/(3608550*Sqrt[35]) + (2617892*EllipticF[ArcSin[Sqrt[3/7]*Sqrt[1 - 2*x]], 35/33])/(1804275*Sqrt[33])}
{((1 - 2*x)^(5/2)*(3 + 5*x)^(5/2))/(2 + 3*x)^(3/2), x, 10, (-310399*Sqrt[1 - 2*x]*Sqrt[2 + 3*x]*Sqrt[3 + 5*x])/76545 + (64628*Sqrt[1 - 2*x]*Sqrt[2 + 3*x]*(3 + 5*x)^(3/2))/8505 - (2*(1 - 2*x)^(5/2)*(3 + 5*x)^(5/2))/(3*Sqrt[2 + 3*x]) - (2108*Sqrt[1 - 2*x]*Sqrt[2 + 3*x]*(3 + 5*x)^(5/2))/1701 - (40*(1 - 2*x)^(3/2)*Sqrt[2 + 3*x]*(3 + 5*x)^(5/2))/81 - (25111*EllipticE[ArcSin[Sqrt[5/11]*Sqrt[1 - 2*x]], 33/35])/(32805*Sqrt[35]) - (291227*EllipticF[ArcSin[Sqrt[3/7]*Sqrt[1 - 2*x]], 35/33])/(32805*Sqrt[33])}
{((1 - 2*x)^(5/2)*(3 + 5*x)^(5/2))/(2 + 3*x)^(5/2), x, 10, (135334*Sqrt[1 - 2*x]*Sqrt[2 + 3*x]*Sqrt[3 + 5*x])/5103 - (31298*Sqrt[1 - 2*x]*Sqrt[2 + 3*x]*(3 + 5*x)^(3/2))/567 - (2*(1 - 2*x)^(5/2)*(3 + 5*x)^(5/2))/(9*(2 + 3*x)^(3/2)) + (370*(1 - 2*x)^(3/2)*(3 + 5*x)^(5/2))/(27*Sqrt[2 + 3*x]) + (5260*Sqrt[1 - 2*x]*Sqrt[2 + 3*x]*(3 + 5*x)^(5/2))/567 - (452399*EllipticE[ArcSin[Sqrt[5/11]*Sqrt[1 - 2*x]], 33/35])/(2187*Sqrt[35]) + (153452*EllipticF[ArcSin[Sqrt[3/7]*Sqrt[1 - 2*x]], 35/33])/(2187*Sqrt[33])}
{((1 - 2*x)^(5/2)*(3 + 5*x)^(5/2))/(2 + 3*x)^(7/2), x, 10, (-48478*Sqrt[1 - 2*x]*Sqrt[2 + 3*x]*Sqrt[3 + 5*x])/729 + (11036*Sqrt[1 - 2*x]*Sqrt[2 + 3*x]*(3 + 5*x)^(3/2))/81 - (2*(1 - 2*x)^(5/2)*(3 + 5*x)^(5/2))/(15*(2 + 3*x)^(5/2)) + (74*(1 - 2*x)^(3/2)*(3 + 5*x)^(5/2))/(27*(2 + 3*x)^(3/2)) - (6464*Sqrt[1 - 2*x]*(3 + 5*x)^(5/2))/(81*Sqrt[2 + 3*x]) + (136028*Sqrt[7/5]*EllipticE[ArcSin[Sqrt[5/11]*Sqrt[1 - 2*x]], 33/35])/2187 - (374366*EllipticF[ArcSin[Sqrt[3/7]*Sqrt[1 - 2*x]], 35/33])/(2187*Sqrt[33])}
{((1 - 2*x)^(5/2)*(3 + 5*x)^(5/2))/(2 + 3*x)^(9/2), x, 10, (1353340*Sqrt[1 - 2*x]*Sqrt[2 + 3*x]*Sqrt[3 + 5*x])/35721 - (62596*Sqrt[1 - 2*x]*(3 + 5*x)^(3/2))/(3969*Sqrt[2 + 3*x]) - (2*(1 - 2*x)^(5/2)*(3 + 5*x)^(5/2))/(21*(2 + 3*x)^(7/2)) + (74*(1 - 2*x)^(3/2)*(3 + 5*x)^(5/2))/(63*(2 + 3*x)^(5/2)) - (1844*Sqrt[1 - 2*x]*(3 + 5*x)^(5/2))/(567*(2 + 3*x)^(3/2)) - (904798*Sqrt[5/7]*EllipticE[ArcSin[Sqrt[5/11]*Sqrt[1 - 2*x]], 33/35])/15309 + (1534520*EllipticF[ArcSin[Sqrt[3/7]*Sqrt[1 - 2*x]], 35/33])/(15309*Sqrt[33])}
{((1 - 2*x)^(5/2)*(3 + 5*x)^(5/2))/(2 + 3*x)^(11/2), x, 10, -((1241596*Sqrt[1 - 2*x]*Sqrt[3 + 5*x])/(750141*Sqrt[2 + 3*x])) - (13316*Sqrt[1 - 2*x]*(3 + 5*x)^(3/2))/(35721*(2 + 3*x)^(3/2)) - (2*(1 - 2*x)^(5/2)*(3 + 5*x)^(5/2))/(27*(2 + 3*x)^(9/2)) + (370*(1 - 2*x)^(3/2)*(3 + 5*x)^(5/2))/(567*(2 + 3*x)^(7/2)) + (2776*Sqrt[1 - 2*x]*(3 + 5*x)^(5/2))/(1701*(2 + 3*x)^(5/2)) - (100444*Sqrt[5/7]*EllipticE[ArcSin[Sqrt[5/11]*Sqrt[1 - 2*x]], 33/35])/321489 - (5824540*EllipticF[ArcSin[Sqrt[3/7]*Sqrt[1 - 2*x]], 35/33])/(321489*Sqrt[33])}
{((1 - 2*x)^(5/2)*(3 + 5*x)^(5/2))/(2 + 3*x)^(13/2), x, 11, -((17089252*Sqrt[1 - 2*x]*Sqrt[3 + 5*x])/(8251551*(2 + 3*x)^(3/2))) + (584888452*Sqrt[1 - 2*x]*Sqrt[3 + 5*x])/(57760857*Sqrt[2 + 3*x]) - (55772*Sqrt[1 - 2*x]*(3 + 5*x)^(3/2))/(43659*(2 + 3*x)^(5/2)) - (2*(1 - 2*x)^(5/2)*(3 + 5*x)^(5/2))/(33*(2 + 3*x)^(11/2)) + (370*(1 - 2*x)^(3/2)*(3 + 5*x)^(5/2))/(891*(2 + 3*x)^(9/2)) + (36980*Sqrt[1 - 2*x]*(3 + 5*x)^(5/2))/(18711*(2 + 3*x)^(7/2)) - (584888452*Sqrt[5/7]*EllipticE[ArcSin[Sqrt[5/11]*Sqrt[1 - 2*x]], 33/35])/24754653 + (104715680*EllipticF[ArcSin[Sqrt[3/7]*Sqrt[1 - 2*x]], 35/33])/(24754653*Sqrt[33])}
{((1 - 2*x)^(5/2)*(3 + 5*x)^(5/2))/(2 + 3*x)^(15/2), x, 12, -((54281308*Sqrt[1 - 2*x]*Sqrt[3 + 5*x])/(35756721*(2 + 3*x)^(5/2))) + (1876198516*Sqrt[1 - 2*x]*Sqrt[3 + 5*x])/(750891141*(2 + 3*x)^(3/2)) + (129922578224*Sqrt[1 - 2*x]*Sqrt[3 + 5*x])/(5256237987*Sqrt[2 + 3*x]) - (2622980*Sqrt[1 - 2*x]*(3 + 5*x)^(3/2))/(1702701*(2 + 3*x)^(7/2)) - (2*(1 - 2*x)^(5/2)*(3 + 5*x)^(5/2))/(39*(2 + 3*x)^(13/2)) + (370*(1 - 2*x)^(3/2)*(3 + 5*x)^(5/2))/(1287*(2 + 3*x)^(11/2)) + (60080*Sqrt[1 - 2*x]*(3 + 5*x)^(5/2))/(34749*(2 + 3*x)^(9/2)) - (129922578224*Sqrt[5/7]*EllipticE[ArcSin[Sqrt[5/11]*Sqrt[1 - 2*x]], 33/35])/2252673423 + (18761985160*EllipticF[ArcSin[Sqrt[3/7]*Sqrt[1 - 2*x]], 35/33])/(2252673423*Sqrt[33])}
{((1 - 2*x)^(5/2)*(3 + 5*x)^(5/2))/(2 + 3*x)^(17/2), x, 13, -((112817764*Sqrt[1 - 2*x]*Sqrt[3 + 5*x])/(107270163*(2 + 3*x)^(7/2))) + (3914701972*Sqrt[1 - 2*x]*Sqrt[3 + 5*x])/(3754455705*(2 + 3*x)^(5/2)) + (181941877952*Sqrt[1 - 2*x]*Sqrt[3 + 5*x])/(26281189935*(2 + 3*x)^(3/2)) + (12641611554328*Sqrt[1 - 2*x]*Sqrt[3 + 5*x])/(183968329545*Sqrt[2 + 3*x]) - (1085156*Sqrt[1 - 2*x]*(3 + 5*x)^(3/2))/(729729*(2 + 3*x)^(9/2)) - (2*(1 - 2*x)^(5/2)*(3 + 5*x)^(5/2))/(45*(2 + 3*x)^(15/2)) + (74*(1 - 2*x)^(3/2)*(3 + 5*x)^(5/2))/(351*(2 + 3*x)^(13/2)) + (16636*Sqrt[1 - 2*x]*(3 + 5*x)^(5/2))/(11583*(2 + 3*x)^(11/2)) - (12641611554328*EllipticE[ArcSin[Sqrt[5/11]*Sqrt[1 - 2*x]], 33/35])/(15768713961*Sqrt[35]) + (363883755904*EllipticF[ArcSin[Sqrt[3/7]*Sqrt[1 - 2*x]], 35/33])/(15768713961*Sqrt[33])}


(* ::Subsubsection::Closed:: *)
(*n>0*)


{((1 - 2*x)^(5/2)*(2 + 3*x)^(5/2))/Sqrt[3 + 5*x], x, 10, (-2865161*Sqrt[1 - 2*x]*Sqrt[2 + 3*x]*Sqrt[3 + 5*x])/19490625 + (181333*Sqrt[1 - 2*x]*(2 + 3*x)^(3/2)*Sqrt[3 + 5*x])/3898125 + (4258*Sqrt[1 - 2*x]*(2 + 3*x)^(5/2)*Sqrt[3 + 5*x])/155925 + (62*(1 - 2*x)^(3/2)*(2 + 3*x)^(5/2)*Sqrt[3 + 5*x])/1485 + (2*(1 - 2*x)^(5/2)*(2 + 3*x)^(5/2)*Sqrt[3 + 5*x])/55 - (231061879*EllipticE[ArcSin[Sqrt[5/11]*Sqrt[1 - 2*x]], 33/35])/(16706250*Sqrt[35]) + (2865161*EllipticF[ArcSin[Sqrt[3/7]*Sqrt[1 - 2*x]], 35/33])/(8353125*Sqrt[33])}
{((1 - 2*x)^(5/2)*(2 + 3*x)^(3/2))/Sqrt[3 + 5*x], x, 9, (21547*Sqrt[1 - 2*x]*Sqrt[2 + 3*x]*Sqrt[3 + 5*x])/1771875 + (8878*Sqrt[1 - 2*x]*(2 + 3*x)^(3/2)*Sqrt[3 + 5*x])/118125 + (106*(1 - 2*x)^(3/2)*(2 + 3*x)^(3/2)*Sqrt[3 + 5*x])/1575 + (2*(1 - 2*x)^(5/2)*(2 + 3*x)^(3/2)*Sqrt[3 + 5*x])/45 - (8024546*EllipticE[ArcSin[Sqrt[5/11]*Sqrt[1 - 2*x]], 33/35])/(759375*Sqrt[35]) - (21547*EllipticF[ArcSin[Sqrt[3/7]*Sqrt[1 - 2*x]], 35/33])/(759375*Sqrt[33])}
{((1 - 2*x)^(5/2)*Sqrt[2 + 3*x])/Sqrt[3 + 5*x], x, 8, (30922*Sqrt[1 - 2*x]*Sqrt[2 + 3*x]*Sqrt[3 + 5*x])/118125 + (326*(1 - 2*x)^(3/2)*Sqrt[2 + 3*x]*Sqrt[3 + 5*x])/2625 + (2*(1 - 2*x)^(5/2)*Sqrt[2 + 3*x]*Sqrt[3 + 5*x])/35 - (408311*EllipticE[ArcSin[Sqrt[5/11]*Sqrt[1 - 2*x]], 33/35])/(50625*Sqrt[35]) - (101902*EllipticF[ArcSin[Sqrt[3/7]*Sqrt[1 - 2*x]], 35/33])/(50625*Sqrt[33])}
{(1 - 2*x)^(5/2)/(Sqrt[2 + 3*x]*Sqrt[3 + 5*x]), x, 7, (-1088*Sqrt[1 - 2*x]*Sqrt[2 + 3*x]*Sqrt[3 + 5*x])/3375 - (4*(1 - 2*x)^(3/2)*Sqrt[2 + 3*x]*Sqrt[3 + 5*x])/75 + (53194*Sqrt[7/5]*EllipticE[ArcSin[Sqrt[5/11]*Sqrt[1 - 2*x]], 33/35])/10125 - (246694*EllipticF[ArcSin[Sqrt[3/7]*Sqrt[1 - 2*x]], 35/33])/(10125*Sqrt[33])}
{(1 - 2*x)^(5/2)/((2 + 3*x)^(3/2)*Sqrt[3 + 5*x]), x, 9, (2*(1 - 2*x)^(5/2)*Sqrt[3 + 5*x])/Sqrt[2 + 3*x] + (428*Sqrt[1 - 2*x]*Sqrt[2 + 3*x]*Sqrt[3 + 5*x])/135 + (4*(1 - 2*x)^(3/2)*Sqrt[2 + 3*x]*Sqrt[3 + 5*x])/3 - (8314*Sqrt[7/5]*EllipticE[ArcSin[Sqrt[5/11]*Sqrt[1 - 2*x]], 33/35])/405 + (8764*EllipticF[ArcSin[Sqrt[3/7]*Sqrt[1 - 2*x]], 35/33])/(405*Sqrt[33])}
{(1 - 2*x)^(5/2)/((2 + 3*x)^(5/2)*Sqrt[3 + 5*x]), x, 8, (2*(1 - 2*x)^(5/2)*Sqrt[3 + 5*x])/(3*(2 + 3*x)^(3/2)) + (40*(1 - 2*x)^(3/2)*Sqrt[3 + 5*x])/(3*Sqrt[2 + 3*x]) + (232*Sqrt[1 - 2*x]*Sqrt[2 + 3*x]*Sqrt[3 + 5*x])/27 - (3896*Sqrt[7/5]*EllipticE[ArcSin[Sqrt[5/11]*Sqrt[1 - 2*x]], 33/35])/81 + (476*EllipticF[ArcSin[Sqrt[3/7]*Sqrt[1 - 2*x]], 35/33])/(81*Sqrt[33])}
{(1 - 2*x)^(5/2)/((2 + 3*x)^(7/2)*Sqrt[3 + 5*x]), x, 8, (2*(1 - 2*x)^(5/2)*Sqrt[3 + 5*x])/(5*(2 + 3*x)^(5/2)) + (52*(1 - 2*x)^(3/2)*Sqrt[3 + 5*x])/(9*(2 + 3*x)^(3/2)) + (3412*Sqrt[1 - 2*x]*Sqrt[3 + 5*x])/(27*Sqrt[2 + 3*x]) - (16564*Sqrt[7/5]*EllipticE[ArcSin[Sqrt[5/11]*Sqrt[1 - 2*x]], 33/35])/81 + (3352*EllipticF[ArcSin[Sqrt[3/7]*Sqrt[1 - 2*x]], 35/33])/(81*Sqrt[33])}
{(1 - 2*x)^(5/2)/((2 + 3*x)^(9/2)*Sqrt[3 + 5*x]), x, 9, (2*(1 - 2*x)^(5/2)*Sqrt[3 + 5*x])/(7*(2 + 3*x)^(7/2)) + (80*(1 - 2*x)^(3/2)*Sqrt[3 + 5*x])/(21*(2 + 3*x)^(5/2)) + (10580*Sqrt[1 - 2*x]*Sqrt[3 + 5*x])/(189*(2 + 3*x)^(3/2)) + (703480*Sqrt[1 - 2*x]*Sqrt[3 + 5*x])/(1323*Sqrt[2 + 3*x]) - (703480/567)*Sqrt[5/7]*EllipticE[ArcSin[Sqrt[5/11]*Sqrt[1 - 2*x]], 33/35] + (101240*EllipticF[ArcSin[Sqrt[3/7]*Sqrt[1 - 2*x]], 35/33])/(567*Sqrt[33])}
{(1 - 2*x)^(5/2)/((2 + 3*x)^(11/2)*Sqrt[3 + 5*x]), x, 10, (2*(1 - 2*x)^(5/2)*Sqrt[3 + 5*x])/(9*(2 + 3*x)^(9/2)) + (20*(1 - 2*x)^(3/2)*Sqrt[3 + 5*x])/(7*(2 + 3*x)^(7/2)) + (7148*Sqrt[1 - 2*x]*Sqrt[3 + 5*x])/(189*(2 + 3*x)^(5/2)) + (950584*Sqrt[1 - 2*x]*Sqrt[3 + 5*x])/(3969*(2 + 3*x)^(3/2)) + (66055016*Sqrt[1 - 2*x]*Sqrt[3 + 5*x])/(27783*Sqrt[2 + 3*x]) - (66055016*Sqrt[5/7]*EllipticE[ArcSin[Sqrt[5/11]*Sqrt[1 - 2*x]], 33/35])/11907 + (9505840*EllipticF[ArcSin[Sqrt[3/7]*Sqrt[1 - 2*x]], 35/33])/(11907*Sqrt[33])}
{(1 - 2*x)^(5/2)/((2 + 3*x)^(13/2)*Sqrt[3 + 5*x]), x, 11, (2*(1 - 2*x)^(5/2)*Sqrt[3 + 5*x])/(11*(2 + 3*x)^(11/2)) + (680*(1 - 2*x)^(3/2)*Sqrt[3 + 5*x])/(297*(2 + 3*x)^(9/2)) + (180020*Sqrt[1 - 2*x]*Sqrt[3 + 5*x])/(6237*(2 + 3*x)^(7/2)) + (7173272*Sqrt[1 - 2*x]*Sqrt[3 + 5*x])/(43659*(2 + 3*x)^(5/2)) + (333930952*Sqrt[1 - 2*x]*Sqrt[3 + 5*x])/(305613*(2 + 3*x)^(3/2)) + (23204503328*Sqrt[1 - 2*x]*Sqrt[3 + 5*x])/(2139291*Sqrt[2 + 3*x]) - (23204503328*Sqrt[5/7]*EllipticE[ArcSin[Sqrt[5/11]*Sqrt[1 - 2*x]], 33/35])/916839 + (3339309520*EllipticF[ArcSin[Sqrt[3/7]*Sqrt[1 - 2*x]], 35/33])/(916839*Sqrt[33])}


{((1 - 2*x)^(5/2)*(2 + 3*x)^(7/2))/(3 + 5*x)^(3/2), x, 11, (-2*(1 - 2*x)^(5/2)*(2 + 3*x)^(7/2))/(5*Sqrt[3 + 5*x]) - (703672*Sqrt[1 - 2*x]*Sqrt[2 + 3*x]*Sqrt[3 + 5*x])/32484375 + (2020841*Sqrt[1 - 2*x]*(2 + 3*x)^(3/2)*Sqrt[3 + 5*x])/6496875 + (346636*Sqrt[1 - 2*x]*(2 + 3*x)^(5/2)*Sqrt[3 + 5*x])/259875 - (2972*Sqrt[1 - 2*x]*(2 + 3*x)^(7/2)*Sqrt[3 + 5*x])/7425 - (48*(1 - 2*x)^(3/2)*(2 + 3*x)^(7/2)*Sqrt[3 + 5*x])/275 - (264260033*EllipticE[ArcSin[Sqrt[5/11]*Sqrt[1 - 2*x]], 33/35])/(27843750*Sqrt[35]) + (703672*EllipticF[ArcSin[Sqrt[3/7]*Sqrt[1 - 2*x]], 35/33])/(13921875*Sqrt[33])}
{((1 - 2*x)^(5/2)*(2 + 3*x)^(5/2))/(3 + 5*x)^(3/2), x, 10, (-2*(1 - 2*x)^(5/2)*(2 + 3*x)^(5/2))/(5*Sqrt[3 + 5*x]) + (196499*Sqrt[1 - 2*x]*Sqrt[2 + 3*x]*Sqrt[3 + 5*x])/590625 + (167228*Sqrt[1 - 2*x]*(2 + 3*x)^(3/2)*Sqrt[3 + 5*x])/118125 - (1972*Sqrt[1 - 2*x]*(2 + 3*x)^(5/2)*Sqrt[3 + 5*x])/4725 - (8*(1 - 2*x)^(3/2)*(2 + 3*x)^(5/2)*Sqrt[3 + 5*x])/45 - (1509007*EllipticE[ArcSin[Sqrt[5/11]*Sqrt[1 - 2*x]], 33/35])/(253125*Sqrt[35]) - (196499*EllipticF[ArcSin[Sqrt[3/7]*Sqrt[1 - 2*x]], 35/33])/(253125*Sqrt[33])}
{((1 - 2*x)^(5/2)*(2 + 3*x)^(3/2))/(3 + 5*x)^(3/2), x, 9, (-2*(1 - 2*x)^(5/2)*(2 + 3*x)^(3/2))/(5*Sqrt[3 + 5*x]) + (106772*Sqrt[1 - 2*x]*Sqrt[2 + 3*x]*Sqrt[3 + 5*x])/65625 - (1972*Sqrt[1 - 2*x]*(2 + 3*x)^(3/2)*Sqrt[3 + 5*x])/4375 - (32*(1 - 2*x)^(3/2)*(2 + 3*x)^(3/2)*Sqrt[3 + 5*x])/175 + (53279*EllipticE[ArcSin[Sqrt[5/11]*Sqrt[1 - 2*x]], 33/35])/(28125*Sqrt[35]) - (106772*EllipticF[ArcSin[Sqrt[3/7]*Sqrt[1 - 2*x]], 35/33])/(28125*Sqrt[33])}
{((1 - 2*x)^(5/2)*Sqrt[2 + 3*x])/(3 + 5*x)^(3/2), x, 8, (-2*(1 - 2*x)^(5/2)*Sqrt[2 + 3*x])/(5*Sqrt[3 + 5*x]) - (3028*Sqrt[1 - 2*x]*Sqrt[2 + 3*x]*Sqrt[3 + 5*x])/5625 - (24*(1 - 2*x)^(3/2)*Sqrt[2 + 3*x]*Sqrt[3 + 5*x])/125 + (81164*Sqrt[7/5]*EllipticE[ArcSin[Sqrt[5/11]*Sqrt[1 - 2*x]], 33/35])/16875 - (218414*EllipticF[ArcSin[Sqrt[3/7]*Sqrt[1 - 2*x]], 35/33])/(16875*Sqrt[33])}
{(1 - 2*x)^(5/2)/(Sqrt[2 + 3*x]*(3 + 5*x)^(3/2)), x, 9, (-2*(1 - 2*x)^(5/2)*Sqrt[2 + 3*x])/Sqrt[3 + 5*x] - (388*Sqrt[1 - 2*x]*Sqrt[2 + 3*x]*Sqrt[3 + 5*x])/225 - (4*(1 - 2*x)^(3/2)*Sqrt[2 + 3*x]*Sqrt[3 + 5*x])/5 + (5594*Sqrt[7/5]*EllipticE[ArcSin[Sqrt[5/11]*Sqrt[1 - 2*x]], 33/35])/675 + (5656*EllipticF[ArcSin[Sqrt[3/7]*Sqrt[1 - 2*x]], 35/33])/(675*Sqrt[33])}
{(1 - 2*x)^(5/2)/((2 + 3*x)^(3/2)*(3 + 5*x)^(3/2)), x, 8, (2*(1 - 2*x)^(5/2))/(Sqrt[2 + 3*x]*Sqrt[3 + 5*x]) - (44*(1 - 2*x)^(3/2)*Sqrt[2 + 3*x])/Sqrt[3 + 5*x] - (272*Sqrt[1 - 2*x]*Sqrt[2 + 3*x]*Sqrt[3 + 5*x])/15 + (4636*Sqrt[7/5]*EllipticE[ArcSin[Sqrt[5/11]*Sqrt[1 - 2*x]], 33/35])/45 - (1036*EllipticF[ArcSin[Sqrt[3/7]*Sqrt[1 - 2*x]], 35/33])/(45*Sqrt[33])}
{(1 - 2*x)^(5/2)/((2 + 3*x)^(5/2)*(3 + 5*x)^(3/2)), x, 8, (2*(1 - 2*x)^(5/2))/(3*(2 + 3*x)^(3/2)*Sqrt[3 + 5*x]) + (260*(1 - 2*x)^(3/2))/(9*Sqrt[2 + 3*x]*Sqrt[3 + 5*x]) - (5764*Sqrt[1 - 2*x]*Sqrt[2 + 3*x])/(9*Sqrt[3 + 5*x]) + (17804*Sqrt[7/5]*EllipticE[ArcSin[Sqrt[5/11]*Sqrt[1 - 2*x]], 33/35])/27 - (3584*EllipticF[ArcSin[Sqrt[3/7]*Sqrt[1 - 2*x]], 35/33])/(27*Sqrt[33])}
{(1 - 2*x)^(5/2)/((2 + 3*x)^(7/2)*(3 + 5*x)^(3/2)), x, 9, (2*(1 - 2*x)^(5/2))/(5*(2 + 3*x)^(5/2)*Sqrt[3 + 5*x]) + (80*(1 - 2*x)^(3/2))/(9*(2 + 3*x)^(3/2)*Sqrt[3 + 5*x]) + (10636*Sqrt[1 - 2*x])/(27*Sqrt[2 + 3*x]*Sqrt[3 + 5*x]) - (105584*Sqrt[1 - 2*x]*Sqrt[2 + 3*x])/(27*Sqrt[3 + 5*x]) + (105584*Sqrt[7/5]*EllipticE[ArcSin[Sqrt[5/11]*Sqrt[1 - 2*x]], 33/35])/27 - (21272*EllipticF[ArcSin[Sqrt[3/7]*Sqrt[1 - 2*x]], 35/33])/(27*Sqrt[33])}
{(1 - 2*x)^(5/2)/((2 + 3*x)^(9/2)*(3 + 5*x)^(3/2)), x, 10, (2*(1 - 2*x)^(5/2))/(7*(2 + 3*x)^(7/2)*Sqrt[3 + 5*x]) + (36*(1 - 2*x)^(3/2))/(7*(2 + 3*x)^(5/2)*Sqrt[3 + 5*x]) + (7204*Sqrt[1 - 2*x])/(63*(2 + 3*x)^(3/2)*Sqrt[3 + 5*x]) + (324104*Sqrt[1 - 2*x])/(147*Sqrt[2 + 3*x]*Sqrt[3 + 5*x]) - (9795160*Sqrt[1 - 2*x]*Sqrt[2 + 3*x])/(441*Sqrt[3 + 5*x]) + (1959032/63)*Sqrt[5/7]*EllipticE[ArcSin[Sqrt[5/11]*Sqrt[1 - 2*x]], 33/35] - (281920*EllipticF[ArcSin[Sqrt[3/7]*Sqrt[1 - 2*x]], 35/33])/(63*Sqrt[33])}
{(1 - 2*x)^(5/2)/((2 + 3*x)^(11/2)*(3 + 5*x)^(3/2)), x, 11, (2*(1 - 2*x)^(5/2))/(9*(2 + 3*x)^(9/2)*Sqrt[3 + 5*x]) + (680*(1 - 2*x)^(3/2))/(189*(2 + 3*x)^(7/2)*Sqrt[3 + 5*x]) + (36284*Sqrt[1 - 2*x])/(567*(2 + 3*x)^(5/2)*Sqrt[3 + 5*x]) + (813208*Sqrt[1 - 2*x])/(1323*(2 + 3*x)^(3/2)*Sqrt[3 + 5*x]) + (113020952*Sqrt[1 - 2*x])/(9261*Sqrt[2 + 3*x]*Sqrt[3 + 5*x]) - (3415750480*Sqrt[1 - 2*x]*Sqrt[2 + 3*x])/(27783*Sqrt[3 + 5*x]) + (683150096*Sqrt[5/7]*EllipticE[ArcSin[Sqrt[5/11]*Sqrt[1 - 2*x]], 33/35])/3969 - (98310640*EllipticF[ArcSin[Sqrt[3/7]*Sqrt[1 - 2*x]], 35/33])/(3969*Sqrt[33])}


{((1 - 2*x)^(5/2)*(2 + 3*x)^(7/2))/(3 + 5*x)^(5/2), x, 11, (-2*(1 - 2*x)^(5/2)*(2 + 3*x)^(7/2))/(15*(3 + 5*x)^(3/2)) - (442*(1 - 2*x)^(3/2)*(2 + 3*x)^(7/2))/(75*Sqrt[3 + 5*x]) + (500501*Sqrt[1 - 2*x]*Sqrt[2 + 3*x]*Sqrt[3 + 5*x])/984375 + (373022*Sqrt[1 - 2*x]*(2 + 3*x)^(3/2)*Sqrt[3 + 5*x])/196875 + (59662*Sqrt[1 - 2*x]*(2 + 3*x)^(5/2)*Sqrt[3 + 5*x])/7875 - (524*Sqrt[1 - 2*x]*(2 + 3*x)^(7/2)*Sqrt[3 + 5*x])/225 - (1065118*EllipticE[ArcSin[Sqrt[5/11]*Sqrt[1 - 2*x]], 33/35])/(421875*Sqrt[35]) - (500501*EllipticF[ArcSin[Sqrt[3/7]*Sqrt[1 - 2*x]], 35/33])/(421875*Sqrt[33])}
{((1 - 2*x)^(5/2)*(2 + 3*x)^(5/2))/(3 + 5*x)^(5/2), x, 10, (-2*(1 - 2*x)^(5/2)*(2 + 3*x)^(5/2))/(15*(3 + 5*x)^(3/2)) - (62*(1 - 2*x)^(3/2)*(2 + 3*x)^(5/2))/(15*Sqrt[3 + 5*x]) + (33778*Sqrt[1 - 2*x]*Sqrt[2 + 3*x]*Sqrt[3 + 5*x])/21875 + (22866*Sqrt[1 - 2*x]*(2 + 3*x)^(3/2)*Sqrt[3 + 5*x])/4375 - (284*Sqrt[1 - 2*x]*(2 + 3*x)^(5/2)*Sqrt[3 + 5*x])/175 + (49321*EllipticE[ArcSin[Sqrt[5/11]*Sqrt[1 - 2*x]], 33/35])/(9375*Sqrt[35]) - (33778*EllipticF[ArcSin[Sqrt[3/7]*Sqrt[1 - 2*x]], 35/33])/(9375*Sqrt[33])}
{((1 - 2*x)^(5/2)*(2 + 3*x)^(3/2))/(3 + 5*x)^(5/2), x, 9, (-2*(1 - 2*x)^(5/2)*(2 + 3*x)^(3/2))/(15*(3 + 5*x)^(3/2)) - (178*(1 - 2*x)^(3/2)*(2 + 3*x)^(3/2))/(75*Sqrt[3 + 5*x]) + (8874*Sqrt[1 - 2*x]*Sqrt[2 + 3*x]*Sqrt[3 + 5*x])/3125 - (572*Sqrt[1 - 2*x]*(2 + 3*x)^(3/2)*Sqrt[3 + 5*x])/625 + (9206*Sqrt[7/5]*EllipticE[ArcSin[Sqrt[5/11]*Sqrt[1 - 2*x]], 33/35])/3125 - (6902*Sqrt[3/11]*EllipticF[ArcSin[Sqrt[3/7]*Sqrt[1 - 2*x]], 35/33])/3125}
{((1 - 2*x)^(5/2)*Sqrt[2 + 3*x])/(3 + 5*x)^(5/2), x, 8, (-2*(1 - 2*x)^(5/2)*Sqrt[2 + 3*x])/(15*(3 + 5*x)^(3/2)) - (46*(1 - 2*x)^(3/2)*Sqrt[2 + 3*x])/(75*Sqrt[3 + 5*x]) - (76*Sqrt[1 - 2*x]*Sqrt[2 + 3*x]*Sqrt[3 + 5*x])/375 + (338*Sqrt[7/5]*EllipticE[ArcSin[Sqrt[5/11]*Sqrt[1 - 2*x]], 33/35])/1125 + (6412*EllipticF[ArcSin[Sqrt[3/7]*Sqrt[1 - 2*x]], 35/33])/(1125*Sqrt[33])}
{(1 - 2*x)^(5/2)/(Sqrt[2 + 3*x]*(3 + 5*x)^(5/2)), x, 8, (-2*(1 - 2*x)^(5/2)*Sqrt[2 + 3*x])/(3*(3 + 5*x)^(3/2)) + (152*(1 - 2*x)^(3/2)*Sqrt[2 + 3*x])/(15*Sqrt[3 + 5*x]) + (104*Sqrt[1 - 2*x]*Sqrt[2 + 3*x]*Sqrt[3 + 5*x])/25 - (584*Sqrt[7/5]*EllipticE[ArcSin[Sqrt[5/11]*Sqrt[1 - 2*x]], 33/35])/25 + (28*Sqrt[3/11]*EllipticF[ArcSin[Sqrt[3/7]*Sqrt[1 - 2*x]], 35/33])/25}
{(1 - 2*x)^(5/2)/((2 + 3*x)^(3/2)*(3 + 5*x)^(5/2)), x, 8, (2*(1 - 2*x)^(5/2))/(Sqrt[2 + 3*x]*(3 + 5*x)^(3/2)) - (88*(1 - 2*x)^(3/2)*Sqrt[2 + 3*x])/(3*(3 + 5*x)^(3/2)) + (2068*Sqrt[1 - 2*x]*Sqrt[2 + 3*x])/(5*Sqrt[3 + 5*x]) - (6388*Sqrt[7/5]*EllipticE[ArcSin[Sqrt[5/11]*Sqrt[1 - 2*x]], 33/35])/15 + (1288*EllipticF[ArcSin[Sqrt[3/7]*Sqrt[1 - 2*x]], 35/33])/(15*Sqrt[33])}
{(1 - 2*x)^(5/2)/((2 + 3*x)^(5/2)*(3 + 5*x)^(5/2)), x, 9, (2*(1 - 2*x)^(5/2))/(3*(2 + 3*x)^(3/2)*(3 + 5*x)^(3/2)) + (400*(1 - 2*x)^(3/2))/(9*Sqrt[2 + 3*x]*(3 + 5*x)^(3/2)) - (5852*Sqrt[1 - 2*x]*Sqrt[2 + 3*x])/(9*(3 + 5*x)^(3/2)) + (36968*Sqrt[1 - 2*x]*Sqrt[2 + 3*x])/(9*Sqrt[3 + 5*x]) - (36968*Sqrt[7/5]*EllipticE[ArcSin[Sqrt[5/11]*Sqrt[1 - 2*x]], 33/35])/9 + (7448*EllipticF[ArcSin[Sqrt[3/7]*Sqrt[1 - 2*x]], 35/33])/(9*Sqrt[33])}
{(1 - 2*x)^(5/2)/((2 + 3*x)^(7/2)*(3 + 5*x)^(5/2)), x, 10, (2*(1 - 2*x)^(5/2))/(5*(2 + 3*x)^(5/2)*(3 + 5*x)^(3/2)) + (12*(1 - 2*x)^(3/2))/((2 + 3*x)^(3/2)*(3 + 5*x)^(3/2)) + (2420*Sqrt[1 - 2*x])/(3*Sqrt[2 + 3*x]*(3 + 5*x)^(3/2)) - (16016*Sqrt[1 - 2*x]*Sqrt[2 + 3*x])/(3*(3 + 5*x)^(3/2)) + (96808*Sqrt[1 - 2*x]*Sqrt[2 + 3*x])/(3*Sqrt[3 + 5*x]) - (96808*Sqrt[7/5]*EllipticE[ArcSin[Sqrt[5/11]*Sqrt[1 - 2*x]], 33/35])/3 + (19504*EllipticF[ArcSin[Sqrt[3/7]*Sqrt[1 - 2*x]], 35/33])/(3*Sqrt[33])}
{(1 - 2*x)^(5/2)/((2 + 3*x)^(9/2)*(3 + 5*x)^(5/2)), x, 11, (2*(1 - 2*x)^(5/2))/(7*(2 + 3*x)^(7/2)*(3 + 5*x)^(3/2)) + (136*(1 - 2*x)^(3/2))/(21*(2 + 3*x)^(5/2)*(3 + 5*x)^(3/2)) + (12188*Sqrt[1 - 2*x])/(63*(2 + 3*x)^(3/2)*(3 + 5*x)^(3/2)) + (2488904*Sqrt[1 - 2*x])/(441*Sqrt[2 + 3*x]*(3 + 5*x)^(3/2)) - (5544440*Sqrt[1 - 2*x]*Sqrt[2 + 3*x])/(147*(3 + 5*x)^(3/2)) + (11171040*Sqrt[1 - 2*x]*Sqrt[2 + 3*x])/(49*Sqrt[3 + 5*x]) - (2234208/7)*Sqrt[5/7]*EllipticE[ArcSin[Sqrt[5/11]*Sqrt[1 - 2*x]], 33/35] + (321520*EllipticF[ArcSin[Sqrt[3/7]*Sqrt[1 - 2*x]], 35/33])/(7*Sqrt[33])}


(* ::Subsection::Closed:: *)
(*Integrands of the form (a+b x)^(m/2) (c+d x)^(n/2) / (e+f x)^(1/2)*)


(* ::Subsubsection::Closed:: *)
(*n<0*)


{((2 + 3*x)^(5/2)*Sqrt[3 + 5*x])/Sqrt[1 - 2*x], x, 8, (-4839*Sqrt[1 - 2*x]*Sqrt[2 + 3*x]*Sqrt[3 + 5*x])/1750 - (104*Sqrt[1 - 2*x]*(2 + 3*x)^(3/2)*Sqrt[3 + 5*x])/175 - (Sqrt[1 - 2*x]*(2 + 3*x)^(5/2)*Sqrt[3 + 5*x])/7 - (56041*EllipticE[ArcSin[Sqrt[5/11]*Sqrt[1 - 2*x]], 33/35])/(250*Sqrt[35]) + (1613*EllipticF[ArcSin[Sqrt[3/7]*Sqrt[1 - 2*x]], 35/33])/(250*Sqrt[33])}
{((2 + 3*x)^(3/2)*Sqrt[3 + 5*x])/Sqrt[1 - 2*x], x, 7, (-23*Sqrt[1 - 2*x]*Sqrt[2 + 3*x]*Sqrt[3 + 5*x])/25 - (Sqrt[1 - 2*x]*(2 + 3*x)^(3/2)*Sqrt[3 + 5*x])/5 - (1597*Sqrt[7/5]*EllipticE[ArcSin[Sqrt[5/11]*Sqrt[1 - 2*x]], 33/35])/150 + (161*EllipticF[ArcSin[Sqrt[3/7]*Sqrt[1 - 2*x]], 35/33])/(75*Sqrt[33])}
{(Sqrt[2 + 3*x]*Sqrt[3 + 5*x])/Sqrt[1 - 2*x], x, 6, -(Sqrt[1 - 2*x]*Sqrt[2 + 3*x]*Sqrt[3 + 5*x])/3 - (34*Sqrt[7/5]*EllipticE[ArcSin[Sqrt[5/11]*Sqrt[1 - 2*x]], 33/35])/9 + (7*EllipticF[ArcSin[Sqrt[3/7]*Sqrt[1 - 2*x]], 35/33])/(9*Sqrt[33])}
{Sqrt[3 + 5*x]/(Sqrt[1 - 2*x]*Sqrt[2 + 3*x]), x, 2, -(Sqrt[11/3]*EllipticE[ArcSin[Sqrt[3/7]*Sqrt[1 - 2*x]], 35/33])}
{Sqrt[3 + 5*x]/(Sqrt[1 - 2*x]*(2 + 3*x)^(3/2)), x, 4, -((2*Sqrt[1 - 2*x]*Sqrt[3 + 5*x])/(7*Sqrt[2 + 3*x])) + (2*Sqrt[5/7]*Sqrt[-3 - 5*x]*EllipticE[ArcSin[Sqrt[5]*Sqrt[2 + 3*x]], 2/35])/(3*Sqrt[3 + 5*x])}
{Sqrt[3 + 5*x]/(Sqrt[1 - 2*x]*(2 + 3*x)^(5/2)), x, 7, (-2*Sqrt[1 - 2*x]*Sqrt[3 + 5*x])/(21*(2 + 3*x)^(3/2)) + (62*Sqrt[1 - 2*x]*Sqrt[3 + 5*x])/(147*Sqrt[2 + 3*x]) - (62*Sqrt[5/7]*EllipticE[ArcSin[Sqrt[5/11]*Sqrt[1 - 2*x]], 33/35])/63 - (20*EllipticF[ArcSin[Sqrt[3/7]*Sqrt[1 - 2*x]], 35/33])/(63*Sqrt[33])}
{Sqrt[3 + 5*x]/(Sqrt[1 - 2*x]*(2 + 3*x)^(7/2)), x, 8, (-2*Sqrt[1 - 2*x]*Sqrt[3 + 5*x])/(35*(2 + 3*x)^(5/2)) + (18*Sqrt[1 - 2*x]*Sqrt[3 + 5*x])/(245*(2 + 3*x)^(3/2)) + (1752*Sqrt[1 - 2*x]*Sqrt[3 + 5*x])/(1715*Sqrt[2 + 3*x]) - (584*EllipticE[ArcSin[Sqrt[5/11]*Sqrt[1 - 2*x]], 33/35])/(49*Sqrt[35]) + (4*Sqrt[3/11]*EllipticF[ArcSin[Sqrt[3/7]*Sqrt[1 - 2*x]], 35/33])/49}


{((2 + 3*x)^(5/2)*(3 + 5*x)^(3/2))/Sqrt[1 - 2*x], x, 9, (-663409*Sqrt[1 - 2*x]*Sqrt[2 + 3*x]*Sqrt[3 + 5*x])/47250 - (9547*Sqrt[1 - 2*x]*Sqrt[2 + 3*x]*(3 + 5*x)^(3/2))/5250 - (137*Sqrt[1 - 2*x]*(2 + 3*x)^(3/2)*(3 + 5*x)^(3/2))/315 - (Sqrt[1 - 2*x]*(2 + 3*x)^(5/2)*(3 + 5*x)^(3/2))/9 - (44109377*EllipticE[ArcSin[Sqrt[5/11]*Sqrt[1 - 2*x]], 33/35])/(40500*Sqrt[35]) + (317384*EllipticF[ArcSin[Sqrt[3/7]*Sqrt[1 - 2*x]], 35/33])/(10125*Sqrt[33])}
{((2 + 3*x)^(3/2)*(3 + 5*x)^(3/2))/Sqrt[1 - 2*x], x, 8, (-4721*Sqrt[1 - 2*x]*Sqrt[2 + 3*x]*Sqrt[3 + 5*x])/1050 - (102*Sqrt[1 - 2*x]*Sqrt[2 + 3*x]*(3 + 5*x)^(3/2))/175 - (Sqrt[1 - 2*x]*(2 + 3*x)^(3/2)*(3 + 5*x)^(3/2))/7 - (78472*EllipticE[ArcSin[Sqrt[5/11]*Sqrt[1 - 2*x]], 33/35])/(225*Sqrt[35]) + (4517*EllipticF[ArcSin[Sqrt[3/7]*Sqrt[1 - 2*x]], 35/33])/(450*Sqrt[33])}
{(Sqrt[2 + 3*x]*(3 + 5*x)^(3/2))/Sqrt[1 - 2*x], x, 7, (-67*Sqrt[1 - 2*x]*Sqrt[2 + 3*x]*Sqrt[3 + 5*x])/45 - (Sqrt[1 - 2*x]*Sqrt[2 + 3*x]*(3 + 5*x)^(3/2))/5 - (4451*Sqrt[7/5]*EllipticE[ArcSin[Sqrt[5/11]*Sqrt[1 - 2*x]], 33/35])/270 + (448*EllipticF[ArcSin[Sqrt[3/7]*Sqrt[1 - 2*x]], 35/33])/(135*Sqrt[33])}
{(3 + 5*x)^(3/2)/(Sqrt[1 - 2*x]*Sqrt[2 + 3*x]), x, 6, (-5*Sqrt[1 - 2*x]*Sqrt[2 + 3*x]*Sqrt[3 + 5*x])/9 - (31*Sqrt[35]*EllipticE[ArcSin[Sqrt[5/11]*Sqrt[1 - 2*x]], 33/35])/27 + (29*EllipticF[ArcSin[Sqrt[3/7]*Sqrt[1 - 2*x]], 35/33])/(27*Sqrt[33])}
{(3 + 5*x)^(3/2)/(Sqrt[1 - 2*x]*(2 + 3*x)^(3/2)), x, 8, (10*Sqrt[1 - 2*x]*Sqrt[2 + 3*x]*Sqrt[3 + 5*x])/21 - (2*Sqrt[1 - 2*x]*(3 + 5*x)^(3/2))/(7*Sqrt[2 + 3*x]) - (37*Sqrt[5/7]*EllipticE[ArcSin[Sqrt[5/11]*Sqrt[1 - 2*x]], 33/35])/9 + (20*EllipticF[ArcSin[Sqrt[3/7]*Sqrt[1 - 2*x]], 35/33])/(9*Sqrt[33])}
{(3 + 5*x)^(3/2)/(Sqrt[1 - 2*x]*(2 + 3*x)^(5/2)), x, 7, (-202*Sqrt[1 - 2*x]*Sqrt[3 + 5*x])/(441*Sqrt[2 + 3*x]) - (2*Sqrt[1 - 2*x]*(3 + 5*x)^(3/2))/(21*(2 + 3*x)^(3/2)) + (272*Sqrt[5/7]*EllipticE[ArcSin[Sqrt[5/11]*Sqrt[1 - 2*x]], 33/35])/189 - (1030*EllipticF[ArcSin[Sqrt[3/7]*Sqrt[1 - 2*x]], 35/33])/(189*Sqrt[33])}
{(3 + 5*x)^(3/2)/(Sqrt[1 - 2*x]*(2 + 3*x)^(7/2)), x, 8, (-194*Sqrt[1 - 2*x]*Sqrt[3 + 5*x])/(2205*(2 + 3*x)^(3/2)) + (5594*Sqrt[1 - 2*x]*Sqrt[3 + 5*x])/(15435*Sqrt[2 + 3*x]) - (2*Sqrt[1 - 2*x]*(3 + 5*x)^(3/2))/(35*(2 + 3*x)^(5/2)) - (5594*EllipticE[ArcSin[Sqrt[5/11]*Sqrt[1 - 2*x]], 33/35])/(1323*Sqrt[35]) - (808*EllipticF[ArcSin[Sqrt[3/7]*Sqrt[1 - 2*x]], 35/33])/(1323*Sqrt[33])}
{(3 + 5*x)^(3/2)/(Sqrt[1 - 2*x]*(2 + 3*x)^(9/2)), x, 9, -((62*Sqrt[1 - 2*x]*Sqrt[3 + 5*x])/(1715*(2 + 3*x)^(5/2))) + (974*Sqrt[1 - 2*x]*Sqrt[3 + 5*x])/(36015*(2 + 3*x)^(3/2)) + (184636*Sqrt[1 - 2*x]*Sqrt[3 + 5*x])/(252105*Sqrt[2 + 3*x]) - (2*Sqrt[1 - 2*x]*(3 + 5*x)^(3/2))/(49*(2 + 3*x)^(7/2)) - (184636*EllipticE[ArcSin[Sqrt[5/11]*Sqrt[1 - 2*x]], 33/35])/(21609*Sqrt[35]) + (1948*EllipticF[ArcSin[Sqrt[3/7]*Sqrt[1 - 2*x]], 35/33])/(21609*Sqrt[33])}


{((2 + 3*x)^(7/2)*(3 + 5*x)^(5/2))/Sqrt[1 - 2*x], x, 11, -((2295970088*Sqrt[1 - 2*x]*Sqrt[2 + 3*x]*Sqrt[3 + 5*x])/10135125) - (138809831*Sqrt[1 - 2*x]*Sqrt[2 + 3*x]*(3 + 5*x)^(3/2))/4504500 - (221673*Sqrt[1 - 2*x]*Sqrt[2 + 3*x]*(3 + 5*x)^(5/2))/50050 - (14303*Sqrt[1 - 2*x]*(2 + 3*x)^(3/2)*(3 + 5*x)^(5/2))/12870 - (41/143)*Sqrt[1 - 2*x]*(2 + 3*x)^(5/2)*(3 + 5*x)^(5/2) - (1/13)*Sqrt[1 - 2*x]*(2 + 3*x)^(7/2)*(3 + 5*x)^(5/2) - (610627101631*EllipticE[ArcSin[Sqrt[5/11]*Sqrt[1 - 2*x]], 33/35])/(34749000*Sqrt[35]) + (8787401429*EllipticF[ArcSin[Sqrt[3/7]*Sqrt[1 - 2*x]], 35/33])/(17374500*Sqrt[33])}
{((2 + 3*x)^(5/2)*(3 + 5*x)^(5/2))/Sqrt[1 - 2*x], x, 10, (-43624697*Sqrt[1 - 2*x]*Sqrt[2 + 3*x]*Sqrt[3 + 5*x])/623700 - (329683*Sqrt[1 - 2*x]*Sqrt[2 + 3*x]*(3 + 5*x)^(3/2))/34650 - (1053*Sqrt[1 - 2*x]*Sqrt[2 + 3*x]*(3 + 5*x)^(5/2))/770 - (34*Sqrt[1 - 2*x]*(2 + 3*x)^(3/2)*(3 + 5*x)^(5/2))/99 - (Sqrt[1 - 2*x]*(2 + 3*x)^(5/2)*(3 + 5*x)^(5/2))/11 - (725140729*EllipticE[ArcSin[Sqrt[5/11]*Sqrt[1 - 2*x]], 33/35])/(133650*Sqrt[35]) + (41741369*EllipticF[ArcSin[Sqrt[3/7]*Sqrt[1 - 2*x]], 35/33])/(267300*Sqrt[33])}
{((2 + 3*x)^(3/2)*(3 + 5*x)^(5/2))/Sqrt[1 - 2*x], x, 9, (-62092*Sqrt[1 - 2*x]*Sqrt[2 + 3*x]*Sqrt[3 + 5*x])/2835 - (1877*Sqrt[1 - 2*x]*Sqrt[2 + 3*x]*(3 + 5*x)^(3/2))/630 - (3*Sqrt[1 - 2*x]*Sqrt[2 + 3*x]*(3 + 5*x)^(5/2))/7 - (Sqrt[1 - 2*x]*(2 + 3*x)^(3/2)*(3 + 5*x)^(5/2))/9 - (8256877*EllipticE[ArcSin[Sqrt[5/11]*Sqrt[1 - 2*x]], 33/35])/(4860*Sqrt[35]) + (118823*EllipticF[ArcSin[Sqrt[3/7]*Sqrt[1 - 2*x]], 35/33])/(2430*Sqrt[33])}
{(Sqrt[2 + 3*x]*(3 + 5*x)^(5/2))/Sqrt[1 - 2*x], x, 8, (-2645*Sqrt[1 - 2*x]*Sqrt[2 + 3*x]*Sqrt[3 + 5*x])/378 - (20*Sqrt[1 - 2*x]*Sqrt[2 + 3*x]*(3 + 5*x)^(3/2))/21 - (Sqrt[1 - 2*x]*Sqrt[2 + 3*x]*(3 + 5*x)^(5/2))/7 - (17587*Sqrt[5/7]*EllipticE[ArcSin[Sqrt[5/11]*Sqrt[1 - 2*x]], 33/35])/162 + (2531*EllipticF[ArcSin[Sqrt[3/7]*Sqrt[1 - 2*x]], 35/33])/(162*Sqrt[33])}
{(3 + 5*x)^(5/2)/(Sqrt[1 - 2*x]*Sqrt[2 + 3*x]), x, 7, (-62*Sqrt[1 - 2*x]*Sqrt[2 + 3*x]*Sqrt[3 + 5*x])/27 - (Sqrt[1 - 2*x]*Sqrt[2 + 3*x]*(3 + 5*x)^(3/2))/3 - (4141*Sqrt[7/5]*EllipticE[ArcSin[Sqrt[5/11]*Sqrt[1 - 2*x]], 33/35])/162 + (419*EllipticF[ArcSin[Sqrt[3/7]*Sqrt[1 - 2*x]], 35/33])/(81*Sqrt[33])}
{(3 + 5*x)^(5/2)/(Sqrt[1 - 2*x]*(2 + 3*x)^(3/2)), x, 9, (-205*Sqrt[1 - 2*x]*Sqrt[2 + 3*x]*Sqrt[3 + 5*x])/189 + (10*Sqrt[1 - 2*x]*Sqrt[2 + 3*x]*(3 + 5*x)^(3/2))/21 - (2*Sqrt[1 - 2*x]*(3 + 5*x)^(5/2))/(7*Sqrt[2 + 3*x]) - (974*Sqrt[5/7]*EllipticE[ArcSin[Sqrt[5/11]*Sqrt[1 - 2*x]], 33/35])/81 + (85*EllipticF[ArcSin[Sqrt[3/7]*Sqrt[1 - 2*x]], 35/33])/(81*Sqrt[33])}
{(3 + 5*x)^(5/2)/(Sqrt[1 - 2*x]*(2 + 3*x)^(5/2)), x, 8, (2060*Sqrt[1 - 2*x]*Sqrt[2 + 3*x]*Sqrt[3 + 5*x])/1323 - (38*Sqrt[1 - 2*x]*(3 + 5*x)^(3/2))/(49*Sqrt[2 + 3*x]) - (2*Sqrt[1 - 2*x]*(3 + 5*x)^(5/2))/(21*(2 + 3*x)^(3/2)) - (4157*Sqrt[5/7]*EllipticE[ArcSin[Sqrt[5/11]*Sqrt[1 - 2*x]], 33/35])/567 + (3130*EllipticF[ArcSin[Sqrt[3/7]*Sqrt[1 - 2*x]], 35/33])/(567*Sqrt[33])}
{(3 + 5*x)^(5/2)/(Sqrt[1 - 2*x]*(2 + 3*x)^(7/2)), x, 8, (-34154*Sqrt[1 - 2*x]*Sqrt[3 + 5*x])/(46305*Sqrt[2 + 3*x]) - (334*Sqrt[1 - 2*x]*(3 + 5*x)^(3/2))/(2205*(2 + 3*x)^(3/2)) - (2*Sqrt[1 - 2*x]*(3 + 5*x)^(5/2))/(35*(2 + 3*x)^(5/2)) + (53194*EllipticE[ArcSin[Sqrt[5/11]*Sqrt[1 - 2*x]], 33/35])/(3969*Sqrt[35]) - (35242*EllipticF[ArcSin[Sqrt[3/7]*Sqrt[1 - 2*x]], 35/33])/(3969*Sqrt[33])}
{(3 + 5*x)^(5/2)/(Sqrt[1 - 2*x]*(2 + 3*x)^(9/2)), x, 9, -((30922*Sqrt[1 - 2*x]*Sqrt[3 + 5*x])/(324135*(2 + 3*x)^(3/2))) + (816622*Sqrt[1 - 2*x]*Sqrt[3 + 5*x])/(2268945*Sqrt[2 + 3*x]) - (326*Sqrt[1 - 2*x]*(3 + 5*x)^(3/2))/(5145*(2 + 3*x)^(5/2)) - (2*Sqrt[1 - 2*x]*(3 + 5*x)^(5/2))/(49*(2 + 3*x)^(7/2)) - (816622*EllipticE[ArcSin[Sqrt[5/11]*Sqrt[1 - 2*x]], 33/35])/(194481*Sqrt[35]) - (203804*EllipticF[ArcSin[Sqrt[3/7]*Sqrt[1 - 2*x]], 35/33])/(194481*Sqrt[33])}
{(3 + 5*x)^(5/2)/(Sqrt[1 - 2*x]*(2 + 3*x)^(11/2)), x, 10, -((8878*Sqrt[1 - 2*x]*Sqrt[3 + 5*x])/(324135*(2 + 3*x)^(5/2))) - (43094*Sqrt[1 - 2*x]*Sqrt[3 + 5*x])/(6806835*(2 + 3*x)^(3/2)) + (32098184*Sqrt[1 - 2*x]*Sqrt[3 + 5*x])/(47647845*Sqrt[2 + 3*x]) - (106*Sqrt[1 - 2*x]*(3 + 5*x)^(3/2))/(3087*(2 + 3*x)^(7/2)) - (2*Sqrt[1 - 2*x]*(3 + 5*x)^(5/2))/(63*(2 + 3*x)^(9/2)) - (32098184*EllipticE[ArcSin[Sqrt[5/11]*Sqrt[1 - 2*x]], 33/35])/(4084101*Sqrt[35]) - (86188*EllipticF[ArcSin[Sqrt[3/7]*Sqrt[1 - 2*x]], 35/33])/(4084101*Sqrt[33])}
{(3 + 5*x)^(5/2)/(Sqrt[1 - 2*x]*(2 + 3*x)^(13/2)), x, 11, -((21290*Sqrt[1 - 2*x]*Sqrt[3 + 5*x])/(2139291*(2 + 3*x)^(7/2))) - (362666*Sqrt[1 - 2*x]*Sqrt[3 + 5*x])/(14975037*(2 + 3*x)^(5/2)) + (11460644*Sqrt[1 - 2*x]*Sqrt[3 + 5*x])/(104825259*(2 + 3*x)^(3/2)) + (924247516*Sqrt[1 - 2*x]*Sqrt[3 + 5*x])/(733776813*Sqrt[2 + 3*x]) - (310*Sqrt[1 - 2*x]*(3 + 5*x)^(3/2))/(14553*(2 + 3*x)^(9/2)) - (2*Sqrt[1 - 2*x]*(3 + 5*x)^(5/2))/(77*(2 + 3*x)^(11/2)) - (924247516*Sqrt[5/7]*EllipticE[ArcSin[Sqrt[5/11]*Sqrt[1 - 2*x]], 33/35])/314475777 + (114606440*EllipticF[ArcSin[Sqrt[3/7]*Sqrt[1 - 2*x]], 35/33])/(314475777*Sqrt[33])}


(* ::Subsubsection::Closed:: *)
(*n>0*)


{(2 + 3*x)^(7/2)/(Sqrt[1 - 2*x]*Sqrt[3 + 5*x]), x, 8, (-15553*Sqrt[1 - 2*x]*Sqrt[2 + 3*x]*Sqrt[3 + 5*x])/8750 - (333*Sqrt[1 - 2*x]*(2 + 3*x)^(3/2)*Sqrt[3 + 5*x])/875 - (3*Sqrt[1 - 2*x]*(2 + 3*x)^(5/2)*Sqrt[3 + 5*x])/35 - (270248*EllipticE[ArcSin[Sqrt[5/11]*Sqrt[1 - 2*x]], 33/35])/(1875*Sqrt[35]) + (15553*EllipticF[ArcSin[Sqrt[3/7]*Sqrt[1 - 2*x]], 35/33])/(3750*Sqrt[33])}
{(2 + 3*x)^(5/2)/(Sqrt[1 - 2*x]*Sqrt[3 + 5*x]), x, 7, (-74*Sqrt[1 - 2*x]*Sqrt[2 + 3*x]*Sqrt[3 + 5*x])/125 - (3*Sqrt[1 - 2*x]*(2 + 3*x)^(3/2)*Sqrt[3 + 5*x])/25 - (5161*Sqrt[7/5]*EllipticE[ArcSin[Sqrt[5/11]*Sqrt[1 - 2*x]], 33/35])/750 + (518*EllipticF[ArcSin[Sqrt[3/7]*Sqrt[1 - 2*x]], 35/33])/(375*Sqrt[33])}
{(2 + 3*x)^(3/2)/(Sqrt[1 - 2*x]*Sqrt[3 + 5*x]), x, 6, -(Sqrt[1 - 2*x]*Sqrt[2 + 3*x]*Sqrt[3 + 5*x])/5 - (37*Sqrt[7/5]*EllipticE[ArcSin[Sqrt[5/11]*Sqrt[1 - 2*x]], 33/35])/15 + (7*EllipticF[ArcSin[Sqrt[3/7]*Sqrt[1 - 2*x]], 35/33])/(15*Sqrt[33])}
{Sqrt[2 + 3*x]/(Sqrt[1 - 2*x]*Sqrt[3 + 5*x]), x, 2, -(Sqrt[7/5]*EllipticE[ArcSin[Sqrt[5/11]*Sqrt[1 - 2*x]], 33/35])}
{1/(Sqrt[1 - 2*x]*Sqrt[2 + 3*x]*Sqrt[3 + 5*x]), x, 2, (-2*EllipticF[ArcSin[Sqrt[3/7]*Sqrt[1 - 2*x]], 35/33])/Sqrt[33]}
{1/(Sqrt[1 - 2*x]*(2 + 3*x)^(3/2)*Sqrt[3 + 5*x]), x, 4, (6*Sqrt[1 - 2*x]*Sqrt[3 + 5*x])/(7*Sqrt[2 + 3*x]) - 2*Sqrt[5/7]*EllipticE[ArcSin[Sqrt[5/11]*Sqrt[1 - 2*x]], 33/35]}
{1/(Sqrt[1 - 2*x]*(2 + 3*x)^(5/2)*Sqrt[3 + 5*x]), x, 7, (2*Sqrt[1 - 2*x]*Sqrt[3 + 5*x])/(7*(2 + 3*x)^(3/2)) + (148*Sqrt[1 - 2*x]*Sqrt[3 + 5*x])/(49*Sqrt[2 + 3*x]) - (148*Sqrt[5/7]*EllipticE[ArcSin[Sqrt[5/11]*Sqrt[1 - 2*x]], 33/35])/21 + (20*EllipticF[ArcSin[Sqrt[3/7]*Sqrt[1 - 2*x]], 35/33])/(21*Sqrt[33])}
{1/(Sqrt[1 - 2*x]*(2 + 3*x)^(7/2)*Sqrt[3 + 5*x]), x, 8, (6*Sqrt[1 - 2*x]*Sqrt[3 + 5*x])/(35*(2 + 3*x)^(5/2)) + (296*Sqrt[1 - 2*x]*Sqrt[3 + 5*x])/(245*(2 + 3*x)^(3/2)) + (20644*Sqrt[1 - 2*x]*Sqrt[3 + 5*x])/(1715*Sqrt[2 + 3*x]) - (20644*EllipticE[ArcSin[Sqrt[5/11]*Sqrt[1 - 2*x]], 33/35])/(147*Sqrt[35]) + (592*EllipticF[ArcSin[Sqrt[3/7]*Sqrt[1 - 2*x]], 35/33])/(147*Sqrt[33])}


{(2 + 3*x)^(7/2)/(Sqrt[1 - 2*x]*(3 + 5*x)^(3/2)), x, 10, (-2*Sqrt[1 - 2*x]*(2 + 3*x)^(7/2))/(11*Sqrt[3 + 5*x]) - (2577*Sqrt[1 - 2*x]*Sqrt[2 + 3*x]*Sqrt[3 + 5*x])/6875 - (69*Sqrt[1 - 2*x]*(2 + 3*x)^(3/2)*Sqrt[3 + 5*x])/1375 + (6*Sqrt[1 - 2*x]*(2 + 3*x)^(5/2)*Sqrt[3 + 5*x])/55 - (61151*Sqrt[7/5]*EllipticE[ArcSin[Sqrt[5/11]*Sqrt[1 - 2*x]], 33/35])/13750 + (6013*EllipticF[ArcSin[Sqrt[3/7]*Sqrt[1 - 2*x]], 35/33])/(6875*Sqrt[33])}
{(2 + 3*x)^(5/2)/(Sqrt[1 - 2*x]*(3 + 5*x)^(3/2)), x, 9, (-2*Sqrt[1 - 2*x]*(2 + 3*x)^(5/2))/(11*Sqrt[3 + 5*x]) - (27*Sqrt[1 - 2*x]*Sqrt[2 + 3*x]*Sqrt[3 + 5*x])/275 + (6*Sqrt[1 - 2*x]*(2 + 3*x)^(3/2)*Sqrt[3 + 5*x])/55 - (438*Sqrt[7/5]*EllipticE[ArcSin[Sqrt[5/11]*Sqrt[1 - 2*x]], 33/35])/275 + (21*Sqrt[3/11]*EllipticF[ArcSin[Sqrt[3/7]*Sqrt[1 - 2*x]], 35/33])/275}
{(2 + 3*x)^(3/2)/(Sqrt[1 - 2*x]*(3 + 5*x)^(3/2)), x, 8, (-2*Sqrt[1 - 2*x]*(2 + 3*x)^(3/2))/(11*Sqrt[3 + 5*x]) + (6*Sqrt[1 - 2*x]*Sqrt[2 + 3*x]*Sqrt[3 + 5*x])/55 - (31*Sqrt[7/5]*EllipticE[ArcSin[Sqrt[5/11]*Sqrt[1 - 2*x]], 33/35])/55 - (14*EllipticF[ArcSin[Sqrt[3/7]*Sqrt[1 - 2*x]], 35/33])/(55*Sqrt[33])}
{Sqrt[2 + 3*x]/(Sqrt[1 - 2*x]*(3 + 5*x)^(3/2)), x, 4, -((2*Sqrt[1 - 2*x]*Sqrt[2 + 3*x])/(11*Sqrt[3 + 5*x])) + (2*Sqrt[7/5]*Sqrt[-3 - 5*x]*EllipticE[ArcSin[Sqrt[5]*Sqrt[2 + 3*x]], 2/35])/(11*Sqrt[3 + 5*x])}
{1/(Sqrt[1 - 2*x]*Sqrt[2 + 3*x]*(3 + 5*x)^(3/2)), x, 4, -((10*Sqrt[1 - 2*x]*Sqrt[2 + 3*x])/(11*Sqrt[3 + 5*x])) + 2*Sqrt[3/11]*EllipticE[ArcSin[Sqrt[3/7]*Sqrt[1 - 2*x]], 35/33]}
{1/(Sqrt[1 - 2*x]*(2 + 3*x)^(3/2)*(3 + 5*x)^(3/2)), x, 7, (6*Sqrt[1 - 2*x])/(7*Sqrt[2 + 3*x]*Sqrt[3 + 5*x]) - (680*Sqrt[1 - 2*x]*Sqrt[2 + 3*x])/(77*Sqrt[3 + 5*x]) + (136*Sqrt[5/7]*EllipticE[ArcSin[Sqrt[5/11]*Sqrt[1 - 2*x]], 33/35])/11 - (20*EllipticF[ArcSin[Sqrt[3/7]*Sqrt[1 - 2*x]], 35/33])/(11*Sqrt[33])}
{1/(Sqrt[1 - 2*x]*(2 + 3*x)^(5/2)*(3 + 5*x)^(3/2)), x, 8, (2*Sqrt[1 - 2*x])/(7*(2 + 3*x)^(3/2)*Sqrt[3 + 5*x]) + (288*Sqrt[1 - 2*x])/(49*Sqrt[2 + 3*x]*Sqrt[3 + 5*x]) - (31940*Sqrt[1 - 2*x]*Sqrt[2 + 3*x])/(539*Sqrt[3 + 5*x]) + (6388*Sqrt[5/7]*EllipticE[ArcSin[Sqrt[5/11]*Sqrt[1 - 2*x]], 33/35])/77 - (920*EllipticF[ArcSin[Sqrt[3/7]*Sqrt[1 - 2*x]], 35/33])/(77*Sqrt[33])}
{1/(Sqrt[1 - 2*x]*(2 + 3*x)^(7/2)*(3 + 5*x)^(3/2)), x, 9, (6*Sqrt[1 - 2*x])/(35*(2 + 3*x)^(5/2)*Sqrt[3 + 5*x]) + (436*Sqrt[1 - 2*x])/(245*(2 + 3*x)^(3/2)*Sqrt[3 + 5*x]) + (60684*Sqrt[1 - 2*x])/(1715*Sqrt[2 + 3*x]*Sqrt[3 + 5*x]) - (1344984*Sqrt[1 - 2*x]*Sqrt[2 + 3*x])/(3773*Sqrt[3 + 5*x]) + (1344984*EllipticE[ArcSin[Sqrt[5/11]*Sqrt[1 - 2*x]], 33/35])/(539*Sqrt[35]) - (12904*Sqrt[3/11]*EllipticF[ArcSin[Sqrt[3/7]*Sqrt[1 - 2*x]], 35/33])/539}


{(2 + 3*x)^(9/2)/(Sqrt[1 - 2*x]*(3 + 5*x)^(5/2)), x, 10, -((2*Sqrt[1 - 2*x]*(2 + 3*x)^(9/2))/(33*(3 + 5*x)^(3/2))) - (602*Sqrt[1 - 2*x]*(2 + 3*x)^(7/2))/(1815*Sqrt[3 + 5*x]) - (87476*Sqrt[1 - 2*x]*Sqrt[2 + 3*x]*Sqrt[3 + 5*x])/378125 + (403*Sqrt[1 - 2*x]*(2 + 3*x)^(3/2)*Sqrt[3 + 5*x])/75625 + (668*Sqrt[1 - 2*x]*(2 + 3*x)^(5/2)*Sqrt[3 + 5*x])/3025 - (6515539*Sqrt[7/5]*EllipticE[ArcSin[Sqrt[5/11]*Sqrt[1 - 2*x]], 33/35])/2268750 + (612332*EllipticF[ArcSin[Sqrt[3/7]*Sqrt[1 - 2*x]], 35/33])/(1134375*Sqrt[33])}
{(2 + 3*x)^(7/2)/(Sqrt[1 - 2*x]*(3 + 5*x)^(5/2)), x, 9, (-2*Sqrt[1 - 2*x]*(2 + 3*x)^(7/2))/(33*(3 + 5*x)^(3/2)) - (94*Sqrt[1 - 2*x]*(2 + 3*x)^(5/2))/(363*Sqrt[3 + 5*x]) - (487*Sqrt[1 - 2*x]*Sqrt[2 + 3*x]*Sqrt[3 + 5*x])/15125 + (536*Sqrt[1 - 2*x]*(2 + 3*x)^(3/2)*Sqrt[3 + 5*x])/3025 - (46159*Sqrt[7/5]*EllipticE[ArcSin[Sqrt[5/11]*Sqrt[1 - 2*x]], 33/35])/45375 + (3409*EllipticF[ArcSin[Sqrt[3/7]*Sqrt[1 - 2*x]], 35/33])/(45375*Sqrt[33])}
{(2 + 3*x)^(5/2)/(Sqrt[1 - 2*x]*(3 + 5*x)^(5/2)), x, 8, (-2*Sqrt[1 - 2*x]*(2 + 3*x)^(5/2))/(33*(3 + 5*x)^(3/2)) - (338*Sqrt[1 - 2*x]*(2 + 3*x)^(3/2))/(1815*Sqrt[3 + 5*x]) + (404*Sqrt[1 - 2*x]*Sqrt[2 + 3*x]*Sqrt[3 + 5*x])/3025 - (2797*Sqrt[7/5]*EllipticE[ArcSin[Sqrt[5/11]*Sqrt[1 - 2*x]], 33/35])/9075 - (2828*EllipticF[ArcSin[Sqrt[3/7]*Sqrt[1 - 2*x]], 35/33])/(9075*Sqrt[33])}
{(2 + 3*x)^(3/2)/(Sqrt[1 - 2*x]*(3 + 5*x)^(5/2)), x, 7, (-2*Sqrt[1 - 2*x]*(2 + 3*x)^(3/2))/(33*(3 + 5*x)^(3/2)) - (206*Sqrt[1 - 2*x]*Sqrt[2 + 3*x])/(1815*Sqrt[3 + 5*x]) + (272*Sqrt[7/5]*EllipticE[ArcSin[Sqrt[5/11]*Sqrt[1 - 2*x]], 33/35])/1815 - (1442*EllipticF[ArcSin[Sqrt[3/7]*Sqrt[1 - 2*x]], 35/33])/(1815*Sqrt[33])}
{Sqrt[2 + 3*x]/(Sqrt[1 - 2*x]*(3 + 5*x)^(5/2)), x, 7, (-2*Sqrt[1 - 2*x]*Sqrt[2 + 3*x])/(33*(3 + 5*x)^(3/2)) - (74*Sqrt[1 - 2*x]*Sqrt[2 + 3*x])/(363*Sqrt[3 + 5*x]) + (74*Sqrt[7/5]*EllipticE[ArcSin[Sqrt[5/11]*Sqrt[1 - 2*x]], 33/35])/363 - (56*EllipticF[ArcSin[Sqrt[3/7]*Sqrt[1 - 2*x]], 35/33])/(363*Sqrt[33])}
{1/(Sqrt[1 - 2*x]*Sqrt[2 + 3*x]*(3 + 5*x)^(5/2)), x, 7, (-10*Sqrt[1 - 2*x]*Sqrt[2 + 3*x])/(33*(3 + 5*x)^(3/2)) + (620*Sqrt[1 - 2*x]*Sqrt[2 + 3*x])/(363*Sqrt[3 + 5*x]) - (124*Sqrt[35]*EllipticE[ArcSin[Sqrt[5/11]*Sqrt[1 - 2*x]], 33/35])/363 + (116*EllipticF[ArcSin[Sqrt[3/7]*Sqrt[1 - 2*x]], 35/33])/(363*Sqrt[33])}
{1/(Sqrt[1 - 2*x]*(2 + 3*x)^(3/2)*(3 + 5*x)^(5/2)), x, 8, (6*Sqrt[1 - 2*x])/(7*Sqrt[2 + 3*x]*(3 + 5*x)^(3/2)) - (1340*Sqrt[1 - 2*x]*Sqrt[2 + 3*x])/(231*(3 + 5*x)^(3/2)) + (89020*Sqrt[1 - 2*x]*Sqrt[2 + 3*x])/(2541*Sqrt[3 + 5*x]) - (17804*Sqrt[5/7]*EllipticE[ArcSin[Sqrt[5/11]*Sqrt[1 - 2*x]], 33/35])/363 + (2560*EllipticF[ArcSin[Sqrt[3/7]*Sqrt[1 - 2*x]], 35/33])/(363*Sqrt[33])}
{1/(Sqrt[1 - 2*x]*(2 + 3*x)^(5/2)*(3 + 5*x)^(5/2)), x, 9, (2*Sqrt[1 - 2*x])/(7*(2 + 3*x)^(3/2)*(3 + 5*x)^(3/2)) + (428*Sqrt[1 - 2*x])/(49*Sqrt[2 + 3*x]*(3 + 5*x)^(3/2)) - (94420*Sqrt[1 - 2*x]*Sqrt[2 + 3*x])/(1617*(3 + 5*x)^(3/2)) + (6277760*Sqrt[1 - 2*x]*Sqrt[2 + 3*x])/(17787*Sqrt[3 + 5*x]) - (1255552*Sqrt[5/7]*EllipticE[ArcSin[Sqrt[5/11]*Sqrt[1 - 2*x]], 33/35])/2541 + (180680*EllipticF[ArcSin[Sqrt[3/7]*Sqrt[1 - 2*x]], 35/33])/(2541*Sqrt[33])}
{1/(Sqrt[1 - 2*x]*(2 + 3*x)^(7/2)*(3 + 5*x)^(5/2)), x, 10, (6*Sqrt[1 - 2*x])/(35*(2 + 3*x)^(5/2)*(3 + 5*x)^(3/2)) + (576*Sqrt[1 - 2*x])/(245*(2 + 3*x)^(3/2)*(3 + 5*x)^(3/2)) + (120324*Sqrt[1 - 2*x])/(1715*Sqrt[2 + 3*x]*(3 + 5*x)^(3/2)) - (5307272*Sqrt[1 - 2*x]*Sqrt[2 + 3*x])/(11319*(3 + 5*x)^(3/2)) + (352875016*Sqrt[1 - 2*x]*Sqrt[2 + 3*x])/(124509*Sqrt[3 + 5*x]) - (352875016*EllipticE[ArcSin[Sqrt[5/11]*Sqrt[1 - 2*x]], 33/35])/(17787*Sqrt[35]) + (10156288*EllipticF[ArcSin[Sqrt[3/7]*Sqrt[1 - 2*x]], 35/33])/(17787*Sqrt[33])}


(* ::Subsection::Closed:: *)
(*Integrands of the form (a+b x)^(m/2) (c+d x)^(n/2) / (e+f x)^(3/2)*)


(* ::Subsubsection::Closed:: *)
(*n<0*)


{((2 + 3*x)^(7/2)*Sqrt[3 + 5*x])/(1 - 2*x)^(3/2), x, 9, (29293*Sqrt[1 - 2*x]*Sqrt[2 + 3*x]*Sqrt[3 + 5*x])/875 + (2517*Sqrt[1 - 2*x]*(2 + 3*x)^(3/2)*Sqrt[3 + 5*x])/350 + (12*Sqrt[1 - 2*x]*(2 + 3*x)^(5/2)*Sqrt[3 + 5*x])/7 + ((2 + 3*x)^(7/2)*Sqrt[3 + 5*x])/Sqrt[1 - 2*x] + (4071079*EllipticE[ArcSin[Sqrt[5/11]*Sqrt[1 - 2*x]], 33/35])/(1500*Sqrt[35]) - (2663*Sqrt[11/3]*EllipticF[ArcSin[Sqrt[3/7]*Sqrt[1 - 2*x]], 35/33])/375}
{((2 + 3*x)^(5/2)*Sqrt[3 + 5*x])/(1 - 2*x)^(3/2), x, 8, (419*Sqrt[1 - 2*x]*Sqrt[2 + 3*x]*Sqrt[3 + 5*x])/50 + (9*Sqrt[1 - 2*x]*(2 + 3*x)^(3/2)*Sqrt[3 + 5*x])/5 + ((2 + 3*x)^(5/2)*Sqrt[3 + 5*x])/Sqrt[1 - 2*x] + (7279*Sqrt[7/5]*EllipticE[ArcSin[Sqrt[5/11]*Sqrt[1 - 2*x]], 33/35])/75 - (2933*EllipticF[ArcSin[Sqrt[3/7]*Sqrt[1 - 2*x]], 35/33])/(150*Sqrt[33])}
{((2 + 3*x)^(3/2)*Sqrt[3 + 5*x])/(1 - 2*x)^(3/2), x, 7, 2*Sqrt[1 - 2*x]*Sqrt[2 + 3*x]*Sqrt[3 + 5*x] + ((2 + 3*x)^(3/2)*Sqrt[3 + 5*x])/Sqrt[1 - 2*x] + (139*Sqrt[7/5]*EllipticE[ArcSin[Sqrt[5/11]*Sqrt[1 - 2*x]], 33/35])/6 - (14*EllipticF[ArcSin[Sqrt[3/7]*Sqrt[1 - 2*x]], 35/33])/(3*Sqrt[33])}
{(Sqrt[2 + 3*x]*Sqrt[3 + 5*x])/(1 - 2*x)^(3/2), x, 6, (Sqrt[2 + 3*x]*Sqrt[3 + 5*x])/Sqrt[1 - 2*x] + Sqrt[35]*EllipticE[ArcSin[Sqrt[5/11]*Sqrt[1 - 2*x]], 33/35] - EllipticF[ArcSin[Sqrt[3/7]*Sqrt[1 - 2*x]], 35/33]/Sqrt[33]}
{Sqrt[3 + 5*x]/((1 - 2*x)^(3/2)*Sqrt[2 + 3*x]), x, 4, (2*Sqrt[2 + 3*x]*Sqrt[3 + 5*x])/(7*Sqrt[1 - 2*x]) + Sqrt[5/7]*EllipticE[ArcSin[Sqrt[5/11]*Sqrt[1 - 2*x]], 33/35]}
{Sqrt[3 + 5*x]/((1 - 2*x)^(3/2)*(2 + 3*x)^(3/2)), x, 7, (2*Sqrt[3 + 5*x])/(7*Sqrt[1 - 2*x]*Sqrt[2 + 3*x]) - (12*Sqrt[1 - 2*x]*Sqrt[3 + 5*x])/(49*Sqrt[2 + 3*x]) + (4*Sqrt[5/7]*EllipticE[ArcSin[Sqrt[5/11]*Sqrt[1 - 2*x]], 33/35])/7 - (10*EllipticF[ArcSin[Sqrt[3/7]*Sqrt[1 - 2*x]], 35/33])/(7*Sqrt[33])}
{Sqrt[3 + 5*x]/((1 - 2*x)^(3/2)*(2 + 3*x)^(5/2)), x, 8, (2*Sqrt[3 + 5*x])/(7*Sqrt[1 - 2*x]*(2 + 3*x)^(3/2)) - (8*Sqrt[1 - 2*x]*Sqrt[3 + 5*x])/(49*(2 + 3*x)^(3/2)) + (38*Sqrt[1 - 2*x]*Sqrt[3 + 5*x])/(343*Sqrt[2 + 3*x]) - (38*Sqrt[5/7]*EllipticE[ArcSin[Sqrt[5/11]*Sqrt[1 - 2*x]], 33/35])/147 - (80*EllipticF[ArcSin[Sqrt[3/7]*Sqrt[1 - 2*x]], 35/33])/(147*Sqrt[33])}
{Sqrt[3 + 5*x]/((1 - 2*x)^(3/2)*(2 + 3*x)^(7/2)), x, 9, (2*Sqrt[3 + 5*x])/(7*Sqrt[1 - 2*x]*(2 + 3*x)^(5/2)) - (36*Sqrt[1 - 2*x]*Sqrt[3 + 5*x])/(245*(2 + 3*x)^(5/2)) - (26*Sqrt[1 - 2*x]*Sqrt[3 + 5*x])/(1715*(2 + 3*x)^(3/2)) + (5636*Sqrt[1 - 2*x]*Sqrt[3 + 5*x])/(12005*Sqrt[2 + 3*x]) - (5636*EllipticE[ArcSin[Sqrt[5/11]*Sqrt[1 - 2*x]], 33/35])/(1029*Sqrt[35]) - (52*EllipticF[ArcSin[Sqrt[3/7]*Sqrt[1 - 2*x]], 35/33])/(1029*Sqrt[33])}


{((2 + 3*x)^(7/2)*(3 + 5*x)^(3/2))/(1 - 2*x)^(3/2), x, 10, (6770629*Sqrt[1 - 2*x]*Sqrt[2 + 3*x]*Sqrt[3 + 5*x])/31500 + (24358*Sqrt[1 - 2*x]*Sqrt[2 + 3*x]*(3 + 5*x)^(3/2))/875 + (1397*Sqrt[1 - 2*x]*(2 + 3*x)^(3/2)*(3 + 5*x)^(3/2))/210 + (5*Sqrt[1 - 2*x]*(2 + 3*x)^(5/2)*(3 + 5*x)^(3/2))/3 + ((2 + 3*x)^(7/2)*(3 + 5*x)^(3/2))/Sqrt[1 - 2*x] + (112543103*EllipticE[ArcSin[Sqrt[5/11]*Sqrt[1 - 2*x]], 33/35])/(6750*Sqrt[35]) - (6478333*EllipticF[ArcSin[Sqrt[3/7]*Sqrt[1 - 2*x]], 35/33])/(13500*Sqrt[33])}
{((2 + 3*x)^(5/2)*(3 + 5*x)^(3/2))/(1 - 2*x)^(3/2), x, 9, (9694*Sqrt[1 - 2*x]*Sqrt[2 + 3*x]*Sqrt[3 + 5*x])/175 + (2511*Sqrt[1 - 2*x]*Sqrt[2 + 3*x]*(3 + 5*x)^(3/2))/350 + (12*Sqrt[1 - 2*x]*(2 + 3*x)^(3/2)*(3 + 5*x)^(3/2))/7 + ((2 + 3*x)^(5/2)*(3 + 5*x)^(3/2))/Sqrt[1 - 2*x] + (1289089*EllipticE[ArcSin[Sqrt[5/11]*Sqrt[1 - 2*x]], 33/35])/(300*Sqrt[35]) - (18551*EllipticF[ArcSin[Sqrt[3/7]*Sqrt[1 - 2*x]], 35/33])/(150*Sqrt[33])}
{((2 + 3*x)^(3/2)*(3 + 5*x)^(3/2))/(1 - 2*x)^(3/2), x, 8, (139*Sqrt[1 - 2*x]*Sqrt[2 + 3*x]*Sqrt[3 + 5*x])/10 + (9*Sqrt[1 - 2*x]*Sqrt[2 + 3*x]*(3 + 5*x)^(3/2))/5 + ((2 + 3*x)^(3/2)*(3 + 5*x)^(3/2))/Sqrt[1 - 2*x] + (4621*Sqrt[7/5]*EllipticE[ArcSin[Sqrt[5/11]*Sqrt[1 - 2*x]], 33/35])/30 - (931*EllipticF[ArcSin[Sqrt[3/7]*Sqrt[1 - 2*x]], 35/33])/(30*Sqrt[33])}
{(Sqrt[2 + 3*x]*(3 + 5*x)^(3/2))/(1 - 2*x)^(3/2), x, 7, (10*Sqrt[1 - 2*x]*Sqrt[2 + 3*x]*Sqrt[3 + 5*x])/3 + (Sqrt[2 + 3*x]*(3 + 5*x)^(3/2))/Sqrt[1 - 2*x] + (133*Sqrt[35]*EllipticE[ArcSin[Sqrt[5/11]*Sqrt[1 - 2*x]], 33/35])/18 - (67*EllipticF[ArcSin[Sqrt[3/7]*Sqrt[1 - 2*x]], 35/33])/(9*Sqrt[33])}
{(3 + 5*x)^(3/2)/((1 - 2*x)^(3/2)*Sqrt[2 + 3*x]), x, 8, (5*Sqrt[1 - 2*x]*Sqrt[2 + 3*x]*Sqrt[3 + 5*x])/7 + (2*Sqrt[2 + 3*x]*(3 + 5*x)^(3/2))/(7*Sqrt[1 - 2*x]) + (34*Sqrt[5/7]*EllipticE[ArcSin[Sqrt[5/11]*Sqrt[1 - 2*x]], 33/35])/3 - (5*EllipticF[ArcSin[Sqrt[3/7]*Sqrt[1 - 2*x]], 35/33])/(3*Sqrt[33])}
{(3 + 5*x)^(3/2)/((1 - 2*x)^(3/2)*(2 + 3*x)^(3/2)), x, 7, (4*Sqrt[1 - 2*x]*Sqrt[3 + 5*x])/(49*Sqrt[2 + 3*x]) + (2*(3 + 5*x)^(3/2))/(7*Sqrt[1 - 2*x]*Sqrt[2 + 3*x]) + (31*Sqrt[5/7]*EllipticE[ArcSin[Sqrt[5/11]*Sqrt[1 - 2*x]], 33/35])/21 + (10*EllipticF[ArcSin[Sqrt[3/7]*Sqrt[1 - 2*x]], 35/33])/(21*Sqrt[33])}
{(3 + 5*x)^(3/2)/((1 - 2*x)^(3/2)*(2 + 3*x)^(5/2)), x, 8, (8*Sqrt[1 - 2*x]*Sqrt[3 + 5*x])/(147*(2 + 3*x)^(3/2)) - (458*Sqrt[1 - 2*x]*Sqrt[3 + 5*x])/(1029*Sqrt[2 + 3*x]) + (2*(3 + 5*x)^(3/2))/(7*Sqrt[1 - 2*x]*(2 + 3*x)^(3/2)) + (458*Sqrt[5/7]*EllipticE[ArcSin[Sqrt[5/11]*Sqrt[1 - 2*x]], 33/35])/441 - (970*EllipticF[ArcSin[Sqrt[3/7]*Sqrt[1 - 2*x]], 35/33])/(441*Sqrt[33])}
{(3 + 5*x)^(3/2)/((1 - 2*x)^(3/2)*(2 + 3*x)^(7/2)), x, 9, (12*Sqrt[1 - 2*x]*Sqrt[3 + 5*x])/(245*(2 + 3*x)^(5/2)) - (458*Sqrt[1 - 2*x]*Sqrt[3 + 5*x])/(1715*(2 + 3*x)^(3/2)) + (338*Sqrt[1 - 2*x]*Sqrt[3 + 5*x])/(12005*Sqrt[2 + 3*x]) + (2*(3 + 5*x)^(3/2))/(7*Sqrt[1 - 2*x]*(2 + 3*x)^(5/2)) - (338*EllipticE[ArcSin[Sqrt[5/11]*Sqrt[1 - 2*x]], 33/35])/(1029*Sqrt[35]) - (916*EllipticF[ArcSin[Sqrt[3/7]*Sqrt[1 - 2*x]], 35/33])/(1029*Sqrt[33])}
{(3 + 5*x)^(3/2)/((1 - 2*x)^(3/2)*(2 + 3*x)^(9/2)), x, 10, (16*Sqrt[1 - 2*x]*Sqrt[3 + 5*x])/(343*(2 + 3*x)^(7/2)) - (2818*Sqrt[1 - 2*x]*Sqrt[3 + 5*x])/(12005*(2 + 3*x)^(5/2)) - (5438*Sqrt[1 - 2*x]*Sqrt[3 + 5*x])/(84035*(2 + 3*x)^(3/2)) + (189368*Sqrt[1 - 2*x]*Sqrt[3 + 5*x])/(588245*Sqrt[2 + 3*x]) + (2*(3 + 5*x)^(3/2))/(7*Sqrt[1 - 2*x]*(2 + 3*x)^(7/2)) - (189368*EllipticE[ArcSin[Sqrt[5/11]*Sqrt[1 - 2*x]], 33/35])/(50421*Sqrt[35]) - (10876*EllipticF[ArcSin[Sqrt[3/7]*Sqrt[1 - 2*x]], 35/33])/(50421*Sqrt[33])}


{((2 + 3*x)^(7/2)*(3 + 5*x)^(5/2))/(1 - 2*x)^(3/2), x, 11, (269045681*Sqrt[1 - 2*x]*Sqrt[2 + 3*x]*Sqrt[3 + 5*x])/207900 + (4066493*Sqrt[1 - 2*x]*Sqrt[2 + 3*x]*(3 + 5*x)^(3/2))/23100 + (9741*Sqrt[1 - 2*x]*Sqrt[2 + 3*x]*(3 + 5*x)^(5/2))/385 + (419*Sqrt[1 - 2*x]*(2 + 3*x)^(3/2)*(3 + 5*x)^(5/2))/66 + (18*Sqrt[1 - 2*x]*(2 + 3*x)^(5/2)*(3 + 5*x)^(5/2))/11 + ((2 + 3*x)^(7/2)*(3 + 5*x)^(5/2))/Sqrt[1 - 2*x] + (17888580643*EllipticE[ArcSin[Sqrt[5/11]*Sqrt[1 - 2*x]], 33/35])/(178200*Sqrt[35]) - (128715331*EllipticF[ArcSin[Sqrt[3/7]*Sqrt[1 - 2*x]], 35/33])/(44550*Sqrt[33])}
{((2 + 3*x)^(5/2)*(3 + 5*x)^(5/2))/(1 - 2*x)^(3/2), x, 10, (1284329*Sqrt[1 - 2*x]*Sqrt[2 + 3*x]*Sqrt[3 + 5*x])/3780 + (4853*Sqrt[1 - 2*x]*Sqrt[2 + 3*x]*(3 + 5*x)^(3/2))/105 + (93*Sqrt[1 - 2*x]*Sqrt[2 + 3*x]*(3 + 5*x)^(5/2))/14 + (5*Sqrt[1 - 2*x]*(2 + 3*x)^(3/2)*(3 + 5*x)^(5/2))/3 + ((2 + 3*x)^(5/2)*(3 + 5*x)^(5/2))/Sqrt[1 - 2*x] + (42696881*EllipticE[ArcSin[Sqrt[5/11]*Sqrt[1 - 2*x]], 33/35])/(1620*Sqrt[35]) - (1228883*EllipticF[ArcSin[Sqrt[3/7]*Sqrt[1 - 2*x]], 35/33])/(1620*Sqrt[33])}
{((2 + 3*x)^(3/2)*(3 + 5*x)^(5/2))/(1 - 2*x)^(3/2), x, 9, (3683*Sqrt[1 - 2*x]*Sqrt[2 + 3*x]*Sqrt[3 + 5*x])/42 + (167*Sqrt[1 - 2*x]*Sqrt[2 + 3*x]*(3 + 5*x)^(3/2))/14 + (12*Sqrt[1 - 2*x]*Sqrt[2 + 3*x]*(3 + 5*x)^(5/2))/7 + ((2 + 3*x)^(3/2)*(3 + 5*x)^(5/2))/Sqrt[1 - 2*x] + (244879*EllipticE[ArcSin[Sqrt[5/11]*Sqrt[1 - 2*x]], 33/35])/(36*Sqrt[35]) - (1762*EllipticF[ArcSin[Sqrt[3/7]*Sqrt[1 - 2*x]], 35/33])/(9*Sqrt[33])}
{(Sqrt[2 + 3*x]*(3 + 5*x)^(5/2))/(1 - 2*x)^(3/2), x, 8, (397*Sqrt[1 - 2*x]*Sqrt[2 + 3*x]*Sqrt[3 + 5*x])/18 + 3*Sqrt[1 - 2*x]*Sqrt[2 + 3*x]*(3 + 5*x)^(3/2) + (Sqrt[2 + 3*x]*(3 + 5*x)^(5/2))/Sqrt[1 - 2*x] + (6599*Sqrt[7/5]*EllipticE[ArcSin[Sqrt[5/11]*Sqrt[1 - 2*x]], 33/35])/27 - (2659*EllipticF[ArcSin[Sqrt[3/7]*Sqrt[1 - 2*x]], 35/33])/(54*Sqrt[33])}
{(3 + 5*x)^(5/2)/((1 - 2*x)^(3/2)*Sqrt[2 + 3*x]), x, 9, (335*Sqrt[1 - 2*x]*Sqrt[2 + 3*x]*Sqrt[3 + 5*x])/63 + (5*Sqrt[1 - 2*x]*Sqrt[2 + 3*x]*(3 + 5*x)^(3/2))/7 + (2*Sqrt[2 + 3*x]*(3 + 5*x)^(5/2))/(7*Sqrt[1 - 2*x]) + (4451*Sqrt[5/7]*EllipticE[ArcSin[Sqrt[5/11]*Sqrt[1 - 2*x]], 33/35])/54 - (320*EllipticF[ArcSin[Sqrt[3/7]*Sqrt[1 - 2*x]], 35/33])/(27*Sqrt[33])}
{(3 + 5*x)^(5/2)/((1 - 2*x)^(3/2)*(2 + 3*x)^(3/2)), x, 8, (155*Sqrt[1 - 2*x]*Sqrt[2 + 3*x]*Sqrt[3 + 5*x])/147 + (4*Sqrt[1 - 2*x]*(3 + 5*x)^(3/2))/(49*Sqrt[2 + 3*x]) + (2*(3 + 5*x)^(5/2))/(7*Sqrt[1 - 2*x]*Sqrt[2 + 3*x]) + (1159*Sqrt[5/7]*EllipticE[ArcSin[Sqrt[5/11]*Sqrt[1 - 2*x]], 33/35])/63 - (185*EllipticF[ArcSin[Sqrt[3/7]*Sqrt[1 - 2*x]], 35/33])/(63*Sqrt[33])}
{(3 + 5*x)^(5/2)/((1 - 2*x)^(3/2)*(2 + 3*x)^(5/2)), x, 8, (598*Sqrt[1 - 2*x]*Sqrt[3 + 5*x])/(3087*Sqrt[2 + 3*x]) + (8*Sqrt[1 - 2*x]*(3 + 5*x)^(3/2))/(147*(2 + 3*x)^(3/2)) + (2*(3 + 5*x)^(5/2))/(7*Sqrt[1 - 2*x]*(2 + 3*x)^(3/2)) + (2797*Sqrt[5/7]*EllipticE[ArcSin[Sqrt[5/11]*Sqrt[1 - 2*x]], 33/35])/1323 + (2020*EllipticF[ArcSin[Sqrt[3/7]*Sqrt[1 - 2*x]], 35/33])/(1323*Sqrt[33])}
{(3 + 5*x)^(5/2)/((1 - 2*x)^(3/2)*(2 + 3*x)^(7/2)), x, 9, (1514*Sqrt[1 - 2*x]*Sqrt[3 + 5*x])/(15435*(2 + 3*x)^(3/2)) - (81164*Sqrt[1 - 2*x]*Sqrt[3 + 5*x])/(108045*Sqrt[2 + 3*x]) + (12*Sqrt[1 - 2*x]*(3 + 5*x)^(3/2))/(245*(2 + 3*x)^(5/2)) + (2*(3 + 5*x)^(5/2))/(7*Sqrt[1 - 2*x]*(2 + 3*x)^(5/2)) + (81164*EllipticE[ArcSin[Sqrt[5/11]*Sqrt[1 - 2*x]], 33/35])/(9261*Sqrt[35]) - (31202*EllipticF[ArcSin[Sqrt[3/7]*Sqrt[1 - 2*x]], 35/33])/(9261*Sqrt[33])}
{(3 + 5*x)^(5/2)/((1 - 2*x)^(3/2)*(2 + 3*x)^(9/2)), x, 10, (986*Sqrt[1 - 2*x]*Sqrt[3 + 5*x])/(12005*(2 + 3*x)^(5/2)) - (106772*Sqrt[1 - 2*x]*Sqrt[3 + 5*x])/(252105*(2 + 3*x)^(3/2)) - (106558*Sqrt[1 - 2*x]*Sqrt[3 + 5*x])/(1764735*Sqrt[2 + 3*x]) + (16*Sqrt[1 - 2*x]*(3 + 5*x)^(3/2))/(343*(2 + 3*x)^(7/2)) + (2*(3 + 5*x)^(5/2))/(7*Sqrt[1 - 2*x]*(2 + 3*x)^(7/2)) + (106558*EllipticE[ArcSin[Sqrt[5/11]*Sqrt[1 - 2*x]], 33/35])/(151263*Sqrt[35]) - (213544*EllipticF[ArcSin[Sqrt[3/7]*Sqrt[1 - 2*x]], 35/33])/(151263*Sqrt[33])}
{(3 + 5*x)^(5/2)/((1 - 2*x)^(3/2)*(2 + 3*x)^(11/2)), x, 11, (4930*Sqrt[1 - 2*x]*Sqrt[3 + 5*x])/(64827*(2 + 3*x)^(7/2)) - (167228*Sqrt[1 - 2*x]*Sqrt[3 + 5*x])/(453789*(2 + 3*x)^(5/2)) - (392998*Sqrt[1 - 2*x]*Sqrt[3 + 5*x])/(3176523*(2 + 3*x)^(3/2)) + (6036028*Sqrt[1 - 2*x]*Sqrt[3 + 5*x])/(22235661*Sqrt[2 + 3*x]) + (20*Sqrt[1 - 2*x]*(3 + 5*x)^(3/2))/(441*(2 + 3*x)^(9/2)) + (2*(3 + 5*x)^(5/2))/(7*Sqrt[1 - 2*x]*(2 + 3*x)^(9/2)) - (6036028*Sqrt[5/7]*EllipticE[ArcSin[Sqrt[5/11]*Sqrt[1 - 2*x]], 33/35])/9529569 - (3929980*EllipticF[ArcSin[Sqrt[3/7]*Sqrt[1 - 2*x]], 35/33])/(9529569*Sqrt[33])}


(* ::Subsubsection::Closed:: *)
(*n>0*)


{(2 + 3*x)^(7/2)/((1 - 2*x)^(3/2)*Sqrt[3 + 5*x]), x, 10, (14517*Sqrt[1 - 2*x]*Sqrt[2 + 3*x]*Sqrt[3 + 5*x])/2750 + (312*Sqrt[1 - 2*x]*(2 + 3*x)^(3/2)*Sqrt[3 + 5*x])/275 + (3*Sqrt[1 - 2*x]*(2 + 3*x)^(5/2)*Sqrt[3 + 5*x])/11 + (2*(2 + 3*x)^(7/2)*Sqrt[3 + 5*x])/(11*Sqrt[1 - 2*x]) + (168123*Sqrt[7/5]*EllipticE[ArcSin[Sqrt[5/11]*Sqrt[1 - 2*x]], 33/35])/2750 - (11291*Sqrt[3/11]*EllipticF[ArcSin[Sqrt[3/7]*Sqrt[1 - 2*x]], 35/33])/2750}
{(2 + 3*x)^(5/2)/((1 - 2*x)^(3/2)*Sqrt[3 + 5*x]), x, 9, (69*Sqrt[1 - 2*x]*Sqrt[2 + 3*x]*Sqrt[3 + 5*x])/55 + (3*Sqrt[1 - 2*x]*(2 + 3*x)^(3/2)*Sqrt[3 + 5*x])/11 + (2*(2 + 3*x)^(5/2)*Sqrt[3 + 5*x])/(11*Sqrt[1 - 2*x]) + (1597*Sqrt[7/5]*EllipticE[ArcSin[Sqrt[5/11]*Sqrt[1 - 2*x]], 33/35])/110 - (161*EllipticF[ArcSin[Sqrt[3/7]*Sqrt[1 - 2*x]], 35/33])/(55*Sqrt[33])}
{(2 + 3*x)^(3/2)/((1 - 2*x)^(3/2)*Sqrt[3 + 5*x]), x, 8, (3*Sqrt[1 - 2*x]*Sqrt[2 + 3*x]*Sqrt[3 + 5*x])/11 + (2*(2 + 3*x)^(3/2)*Sqrt[3 + 5*x])/(11*Sqrt[1 - 2*x]) + (34*Sqrt[7/5]*EllipticE[ArcSin[Sqrt[5/11]*Sqrt[1 - 2*x]], 33/35])/11 - (7*EllipticF[ArcSin[Sqrt[3/7]*Sqrt[1 - 2*x]], 35/33])/(11*Sqrt[33])}
{Sqrt[2 + 3*x]/((1 - 2*x)^(3/2)*Sqrt[3 + 5*x]), x, 4, (2*Sqrt[2 + 3*x]*Sqrt[3 + 5*x])/(11*Sqrt[1 - 2*x]) + Sqrt[3/11]*EllipticE[ArcSin[Sqrt[3/7]*Sqrt[1 - 2*x]], 35/33]}
{1/((1 - 2*x)^(3/2)*Sqrt[2 + 3*x]*Sqrt[3 + 5*x]), x, 4, (4*Sqrt[2 + 3*x]*Sqrt[3 + 5*x])/(77*Sqrt[1 - 2*x]) + (2*Sqrt[5/7]*Sqrt[-3 - 5*x]*EllipticE[ArcSin[Sqrt[5]*Sqrt[2 + 3*x]], 2/35])/(11*Sqrt[3 + 5*x])}
{1/((1 - 2*x)^(3/2)*(2 + 3*x)^(3/2)*Sqrt[3 + 5*x]), x, 7, (4*Sqrt[3 + 5*x])/(77*Sqrt[1 - 2*x]*Sqrt[2 + 3*x]) + (186*Sqrt[1 - 2*x]*Sqrt[3 + 5*x])/(539*Sqrt[2 + 3*x]) - (62*Sqrt[5/7]*EllipticE[ArcSin[Sqrt[5/11]*Sqrt[1 - 2*x]], 33/35])/77 - (20*EllipticF[ArcSin[Sqrt[3/7]*Sqrt[1 - 2*x]], 35/33])/(77*Sqrt[33])}
{1/((1 - 2*x)^(3/2)*(2 + 3*x)^(5/2)*Sqrt[3 + 5*x]), x, 8, (4*Sqrt[3 + 5*x])/(77*Sqrt[1 - 2*x]*(2 + 3*x)^(3/2)) + (54*Sqrt[1 - 2*x]*Sqrt[3 + 5*x])/(539*(2 + 3*x)^(3/2)) + (5256*Sqrt[1 - 2*x]*Sqrt[3 + 5*x])/(3773*Sqrt[2 + 3*x]) - (1752*Sqrt[5/7]*EllipticE[ArcSin[Sqrt[5/11]*Sqrt[1 - 2*x]], 33/35])/539 + (60*Sqrt[3/11]*EllipticF[ArcSin[Sqrt[3/7]*Sqrt[1 - 2*x]], 35/33])/539}
{1/((1 - 2*x)^(3/2)*(2 + 3*x)^(7/2)*Sqrt[3 + 5*x]), x, 9, (4*Sqrt[3 + 5*x])/(77*Sqrt[1 - 2*x]*(2 + 3*x)^(5/2)) + (138*Sqrt[1 - 2*x]*Sqrt[3 + 5*x])/(2695*(2 + 3*x)^(5/2)) + (10308*Sqrt[1 - 2*x]*Sqrt[3 + 5*x])/(18865*(2 + 3*x)^(3/2)) + (733812*Sqrt[1 - 2*x]*Sqrt[3 + 5*x])/(132055*Sqrt[2 + 3*x]) - (244604*EllipticE[ArcSin[Sqrt[5/11]*Sqrt[1 - 2*x]], 33/35])/(3773*Sqrt[35]) + (6872*EllipticF[ArcSin[Sqrt[3/7]*Sqrt[1 - 2*x]], 35/33])/(3773*Sqrt[33])}


{(2 + 3*x)^(9/2)/((1 - 2*x)^(3/2)*(3 + 5*x)^(3/2)), x, 10, -((4*Sqrt[1 - 2*x]*(2 + 3*x)^(7/2))/(121*Sqrt[3 + 5*x])) + (2*(2 + 3*x)^(9/2))/(11*Sqrt[1 - 2*x]*Sqrt[3 + 5*x]) + (502941*Sqrt[1 - 2*x]*Sqrt[2 + 3*x]*Sqrt[3 + 5*x])/151250 + (10851*Sqrt[1 - 2*x]*(2 + 3*x)^(3/2)*Sqrt[3 + 5*x])/15125 + (111/605)*Sqrt[1 - 2*x]*(2 + 3*x)^(5/2)*Sqrt[3 + 5*x] + (2911577*Sqrt[7/5]*EllipticE[ArcSin[Sqrt[5/11]*Sqrt[1 - 2*x]], 33/35])/75625 - (1173529*EllipticF[ArcSin[Sqrt[3/7]*Sqrt[1 - 2*x]], 35/33])/(151250*Sqrt[33])}
{(2 + 3*x)^(7/2)/((1 - 2*x)^(3/2)*(3 + 5*x)^(3/2)), x, 9, (-4*Sqrt[1 - 2*x]*(2 + 3*x)^(5/2))/(121*Sqrt[3 + 5*x]) + (2*(2 + 3*x)^(7/2))/(11*Sqrt[1 - 2*x]*Sqrt[3 + 5*x]) + (2388*Sqrt[1 - 2*x]*Sqrt[2 + 3*x]*Sqrt[3 + 5*x])/3025 + (111*Sqrt[1 - 2*x]*(2 + 3*x)^(3/2)*Sqrt[3 + 5*x])/605 + (55019*Sqrt[7/5]*EllipticE[ArcSin[Sqrt[5/11]*Sqrt[1 - 2*x]], 33/35])/6050 - (5572*EllipticF[ArcSin[Sqrt[3/7]*Sqrt[1 - 2*x]], 35/33])/(3025*Sqrt[33])}
{(2 + 3*x)^(5/2)/((1 - 2*x)^(3/2)*(3 + 5*x)^(3/2)), x, 8, (-4*Sqrt[1 - 2*x]*(2 + 3*x)^(3/2))/(121*Sqrt[3 + 5*x]) + (2*(2 + 3*x)^(5/2))/(11*Sqrt[1 - 2*x]*Sqrt[3 + 5*x]) + (111*Sqrt[1 - 2*x]*Sqrt[2 + 3*x]*Sqrt[3 + 5*x])/605 + (1159*Sqrt[7/5]*EllipticE[ArcSin[Sqrt[5/11]*Sqrt[1 - 2*x]], 33/35])/605 - (259*EllipticF[ArcSin[Sqrt[3/7]*Sqrt[1 - 2*x]], 35/33])/(605*Sqrt[33])}
{(2 + 3*x)^(3/2)/((1 - 2*x)^(3/2)*(3 + 5*x)^(3/2)), x, 7, (-4*Sqrt[1 - 2*x]*Sqrt[2 + 3*x])/(121*Sqrt[3 + 5*x]) + (2*(2 + 3*x)^(3/2))/(11*Sqrt[1 - 2*x]*Sqrt[3 + 5*x]) + (37*Sqrt[7/5]*EllipticE[ArcSin[Sqrt[5/11]*Sqrt[1 - 2*x]], 33/35])/121 - (28*EllipticF[ArcSin[Sqrt[3/7]*Sqrt[1 - 2*x]], 35/33])/(121*Sqrt[33])}
{Sqrt[2 + 3*x]/((1 - 2*x)^(3/2)*(3 + 5*x)^(3/2)), x, 7, (2*Sqrt[2 + 3*x])/(11*Sqrt[1 - 2*x]*Sqrt[3 + 5*x]) - (20*Sqrt[1 - 2*x]*Sqrt[2 + 3*x])/(121*Sqrt[3 + 5*x]) + (4*Sqrt[35]*EllipticE[ArcSin[Sqrt[5/11]*Sqrt[1 - 2*x]], 33/35])/121 - (74*EllipticF[ArcSin[Sqrt[3/7]*Sqrt[1 - 2*x]], 35/33])/(121*Sqrt[33])}
{1/((1 - 2*x)^(3/2)*Sqrt[2 + 3*x]*(3 + 5*x)^(3/2)), x, 7, (4*Sqrt[2 + 3*x])/(77*Sqrt[1 - 2*x]*Sqrt[3 + 5*x]) - (370*Sqrt[1 - 2*x]*Sqrt[2 + 3*x])/(847*Sqrt[3 + 5*x]) + (74*Sqrt[5/7]*EllipticE[ArcSin[Sqrt[5/11]*Sqrt[1 - 2*x]], 33/35])/121 - (40*EllipticF[ArcSin[Sqrt[3/7]*Sqrt[1 - 2*x]], 35/33])/(121*Sqrt[33])}
{1/((1 - 2*x)^(3/2)*(2 + 3*x)^(3/2)*(3 + 5*x)^(3/2)), x, 8, 4/(77*Sqrt[1 - 2*x]*Sqrt[2 + 3*x]*Sqrt[3 + 5*x]) + (186*Sqrt[1 - 2*x])/(539*Sqrt[2 + 3*x]*Sqrt[3 + 5*x]) - (23180*Sqrt[1 - 2*x]*Sqrt[2 + 3*x])/(5929*Sqrt[3 + 5*x]) + (4636*Sqrt[5/7]*EllipticE[ArcSin[Sqrt[5/11]*Sqrt[1 - 2*x]], 33/35])/847 - (740*EllipticF[ArcSin[Sqrt[3/7]*Sqrt[1 - 2*x]], 35/33])/(847*Sqrt[33])}
{1/((1 - 2*x)^(3/2)*(2 + 3*x)^(5/2)*(3 + 5*x)^(3/2)), x, 9, 4/(77*Sqrt[1 - 2*x]*(2 + 3*x)^(3/2)*Sqrt[3 + 5*x]) + (54*Sqrt[1 - 2*x])/(539*(2 + 3*x)^(3/2)*Sqrt[3 + 5*x]) + (9876*Sqrt[1 - 2*x])/(3773*Sqrt[2 + 3*x]*Sqrt[3 + 5*x]) - (1100380*Sqrt[1 - 2*x]*Sqrt[2 + 3*x])/(41503*Sqrt[3 + 5*x]) + (220076*Sqrt[5/7]*EllipticE[ArcSin[Sqrt[5/11]*Sqrt[1 - 2*x]], 33/35])/5929 - (31840*EllipticF[ArcSin[Sqrt[3/7]*Sqrt[1 - 2*x]], 35/33])/(5929*Sqrt[33])}
{1/((1 - 2*x)^(3/2)*(2 + 3*x)^(7/2)*(3 + 5*x)^(3/2)), x, 10, 4/(77*Sqrt[1 - 2*x]*(2 + 3*x)^(5/2)*Sqrt[3 + 5*x]) + (138*Sqrt[1 - 2*x])/(2695*(2 + 3*x)^(5/2)*Sqrt[3 + 5*x]) + (14928*Sqrt[1 - 2*x])/(18865*(2 + 3*x)^(3/2)*Sqrt[3 + 5*x]) + (2101332*Sqrt[1 - 2*x])/(132055*Sqrt[2 + 3*x]*Sqrt[3 + 5*x]) - (46585232*Sqrt[1 - 2*x]*Sqrt[2 + 3*x])/(290521*Sqrt[3 + 5*x]) + (46585232*EllipticE[ArcSin[Sqrt[5/11]*Sqrt[1 - 2*x]], 33/35])/(41503*Sqrt[35]) - (1341176*EllipticF[ArcSin[Sqrt[3/7]*Sqrt[1 - 2*x]], 35/33])/(41503*Sqrt[33])}


{(2 + 3*x)^(11/2)/((1 - 2*x)^(3/2)*(3 + 5*x)^(5/2)), x, 11, -((8*Sqrt[1 - 2*x]*(2 + 3*x)^(9/2))/(363*(3 + 5*x)^(3/2))) + (2*(2 + 3*x)^(11/2))/(11*Sqrt[1 - 2*x]*(3 + 5*x)^(3/2)) - (1022*Sqrt[1 - 2*x]*(2 + 3*x)^(7/2))/(19965*Sqrt[3 + 5*x]) + (17427983*Sqrt[1 - 2*x]*Sqrt[2 + 3*x]*Sqrt[3 + 5*x])/8318750 + (380188*Sqrt[1 - 2*x]*(2 + 3*x)^(3/2)*Sqrt[3 + 5*x])/831875 + (4553*Sqrt[1 - 2*x]*(2 + 3*x)^(5/2)*Sqrt[3 + 5*x])/33275 + (604915631*Sqrt[7/5]*EllipticE[ArcSin[Sqrt[5/11]*Sqrt[1 - 2*x]], 33/35])/24956250 - (121995881*EllipticF[ArcSin[Sqrt[3/7]*Sqrt[1 - 2*x]], 35/33])/(24956250*Sqrt[33])}
{(2 + 3*x)^(9/2)/((1 - 2*x)^(3/2)*(3 + 5*x)^(5/2)), x, 10, -((8*Sqrt[1 - 2*x]*(2 + 3*x)^(7/2))/(363*(3 + 5*x)^(3/2))) + (2*(2 + 3*x)^(9/2))/(11*Sqrt[1 - 2*x]*(3 + 5*x)^(3/2)) - (178*Sqrt[1 - 2*x]*(2 + 3*x)^(5/2))/(3993*Sqrt[3 + 5*x]) + (83093*Sqrt[1 - 2*x]*Sqrt[2 + 3*x]*Sqrt[3 + 5*x])/166375 + (4421*Sqrt[1 - 2*x]*(2 + 3*x)^(3/2)*Sqrt[3 + 5*x])/33275 + (5684677*Sqrt[7/5]*EllipticE[ArcSin[Sqrt[5/11]*Sqrt[1 - 2*x]], 33/35])/998250 - (581651*EllipticF[ArcSin[Sqrt[3/7]*Sqrt[1 - 2*x]], 35/33])/(499125*Sqrt[33])}
{(2 + 3*x)^(7/2)/((1 - 2*x)^(3/2)*(3 + 5*x)^(5/2)), x, 9, (-8*Sqrt[1 - 2*x]*(2 + 3*x)^(5/2))/(363*(3 + 5*x)^(3/2)) + (2*(2 + 3*x)^(7/2))/(11*Sqrt[1 - 2*x]*(3 + 5*x)^(3/2)) - (758*Sqrt[1 - 2*x]*(2 + 3*x)^(3/2))/(19965*Sqrt[3 + 5*x]) + (4289*Sqrt[1 - 2*x]*Sqrt[2 + 3*x]*Sqrt[3 + 5*x])/33275 + (118898*Sqrt[7/5]*EllipticE[ArcSin[Sqrt[5/11]*Sqrt[1 - 2*x]], 33/35])/99825 - (30023*EllipticF[ArcSin[Sqrt[3/7]*Sqrt[1 - 2*x]], 35/33])/(99825*Sqrt[33])}
{(2 + 3*x)^(5/2)/((1 - 2*x)^(3/2)*(3 + 5*x)^(5/2)), x, 8, (-8*Sqrt[1 - 2*x]*(2 + 3*x)^(3/2))/(363*(3 + 5*x)^(3/2)) + (2*(2 + 3*x)^(5/2))/(11*Sqrt[1 - 2*x]*(3 + 5*x)^(3/2)) - (626*Sqrt[1 - 2*x]*Sqrt[2 + 3*x])/(19965*Sqrt[3 + 5*x]) + (4157*Sqrt[7/5]*EllipticE[ArcSin[Sqrt[5/11]*Sqrt[1 - 2*x]], 33/35])/19965 - (4382*EllipticF[ArcSin[Sqrt[3/7]*Sqrt[1 - 2*x]], 35/33])/(19965*Sqrt[33])}
{(2 + 3*x)^(3/2)/((1 - 2*x)^(3/2)*(3 + 5*x)^(5/2)), x, 8, (-8*Sqrt[1 - 2*x]*Sqrt[2 + 3*x])/(363*(3 + 5*x)^(3/2)) + (2*(2 + 3*x)^(3/2))/(11*Sqrt[1 - 2*x]*(3 + 5*x)^(3/2)) - (494*Sqrt[1 - 2*x]*Sqrt[2 + 3*x])/(3993*Sqrt[3 + 5*x]) + (494*Sqrt[7/5]*EllipticE[ArcSin[Sqrt[5/11]*Sqrt[1 - 2*x]], 33/35])/3993 - (1610*EllipticF[ArcSin[Sqrt[3/7]*Sqrt[1 - 2*x]], 35/33])/(3993*Sqrt[33])}
{Sqrt[2 + 3*x]/((1 - 2*x)^(3/2)*(3 + 5*x)^(5/2)), x, 8, (2*Sqrt[2 + 3*x])/(11*Sqrt[1 - 2*x]*(3 + 5*x)^(3/2)) - (40*Sqrt[1 - 2*x]*Sqrt[2 + 3*x])/(363*(3 + 5*x)^(3/2)) - (490*Sqrt[1 - 2*x]*Sqrt[2 + 3*x])/(3993*Sqrt[3 + 5*x]) + (98*Sqrt[35]*EllipticE[ArcSin[Sqrt[5/11]*Sqrt[1 - 2*x]], 33/35])/3993 - (724*EllipticF[ArcSin[Sqrt[3/7]*Sqrt[1 - 2*x]], 35/33])/(3993*Sqrt[33])}
{1/((1 - 2*x)^(3/2)*Sqrt[2 + 3*x]*(3 + 5*x)^(5/2)), x, 8, (4*Sqrt[2 + 3*x])/(77*Sqrt[1 - 2*x]*(3 + 5*x)^(3/2)) - (410*Sqrt[1 - 2*x]*Sqrt[2 + 3*x])/(2541*(3 + 5*x)^(3/2)) + (19480*Sqrt[1 - 2*x]*Sqrt[2 + 3*x])/(27951*Sqrt[3 + 5*x]) - (3896*Sqrt[5/7]*EllipticE[ArcSin[Sqrt[5/11]*Sqrt[1 - 2*x]], 33/35])/3993 + (340*EllipticF[ArcSin[Sqrt[3/7]*Sqrt[1 - 2*x]], 35/33])/(3993*Sqrt[33])}
{1/((1 - 2*x)^(3/2)*(2 + 3*x)^(3/2)*(3 + 5*x)^(5/2)), x, 9, 4/(77*Sqrt[1 - 2*x]*Sqrt[2 + 3*x]*(3 + 5*x)^(3/2)) + (186*Sqrt[1 - 2*x])/(539*Sqrt[2 + 3*x]*(3 + 5*x)^(3/2)) - (45040*Sqrt[1 - 2*x]*Sqrt[2 + 3*x])/(17787*(3 + 5*x)^(3/2)) + (2976620*Sqrt[1 - 2*x]*Sqrt[2 + 3*x])/(195657*Sqrt[3 + 5*x]) - (595324*Sqrt[5/7]*EllipticE[ArcSin[Sqrt[5/11]*Sqrt[1 - 2*x]], 33/35])/27951 + (85160*EllipticF[ArcSin[Sqrt[3/7]*Sqrt[1 - 2*x]], 35/33])/(27951*Sqrt[33])}
{1/((1 - 2*x)^(3/2)*(2 + 3*x)^(5/2)*(3 + 5*x)^(5/2)), x, 10, 4/(77*Sqrt[1 - 2*x]*(2 + 3*x)^(3/2)*(3 + 5*x)^(3/2)) + (54*Sqrt[1 - 2*x])/(539*(2 + 3*x)^(3/2)*(3 + 5*x)^(3/2)) + (14496*Sqrt[1 - 2*x])/(3773*Sqrt[2 + 3*x]*(3 + 5*x)^(3/2)) - (3205940*Sqrt[1 - 2*x]*Sqrt[2 + 3*x])/(124509*(3 + 5*x)^(3/2)) + (213119320*Sqrt[1 - 2*x]*Sqrt[2 + 3*x])/(1369599*Sqrt[3 + 5*x]) - (42623864*Sqrt[5/7]*EllipticE[ArcSin[Sqrt[5/11]*Sqrt[1 - 2*x]], 33/35])/195657 + (6132760*EllipticF[ArcSin[Sqrt[3/7]*Sqrt[1 - 2*x]], 35/33])/(195657*Sqrt[33])}
{1/((1 - 2*x)^(3/2)*(2 + 3*x)^(7/2)*(3 + 5*x)^(5/2)), x, 11, 4/(77*Sqrt[1 - 2*x]*(2 + 3*x)^(5/2)*(3 + 5*x)^(3/2)) + (138*Sqrt[1 - 2*x])/(2695*(2 + 3*x)^(5/2)*(3 + 5*x)^(3/2)) + (19548*Sqrt[1 - 2*x])/(18865*(2 + 3*x)^(3/2)*(3 + 5*x)^(3/2)) + (4115652*Sqrt[1 - 2*x])/(132055*Sqrt[2 + 3*x]*(3 + 5*x)^(3/2)) - (181551856*Sqrt[1 - 2*x]*Sqrt[2 + 3*x])/(871563*(3 + 5*x)^(3/2)) + (12071114168*Sqrt[1 - 2*x]*Sqrt[2 + 3*x])/(9587193*Sqrt[3 + 5*x]) - (12071114168*EllipticE[ArcSin[Sqrt[5/11]*Sqrt[1 - 2*x]], 33/35])/(1369599*Sqrt[35]) + (347423024*EllipticF[ArcSin[Sqrt[3/7]*Sqrt[1 - 2*x]], 35/33])/(1369599*Sqrt[33])}


(* ::Subsection::Closed:: *)
(*Integrands of the form (a+b x)^(m/2) (c+d x)^(n/2) / (e+f x)^(5/2)*)


(* ::Subsubsection::Closed:: *)
(*n<0*)


{((2 + 3*x)^(9/2)*Sqrt[3 + 5*x])/(1 - 2*x)^(5/2), x, 10, -((6478333*Sqrt[1 - 2*x]*Sqrt[2 + 3*x]*Sqrt[3 + 5*x])/38500) - (139163*Sqrt[1 - 2*x]*(2 + 3*x)^(3/2)*Sqrt[3 + 5*x])/3850 - (1327/154)*Sqrt[1 - 2*x]*(2 + 3*x)^(5/2)*Sqrt[3 + 5*x] - (166*(2 + 3*x)^(7/2)*Sqrt[3 + 5*x])/(33*Sqrt[1 - 2*x]) + ((2 + 3*x)^(9/2)*Sqrt[3 + 5*x])/(3*(1 - 2*x)^(3/2)) - (112543103*EllipticE[ArcSin[Sqrt[5/11]*Sqrt[1 - 2*x]], 33/35])/(8250*Sqrt[35]) + (6478333*EllipticF[ArcSin[Sqrt[3/7]*Sqrt[1 - 2*x]], 35/33])/(16500*Sqrt[33])}
{((2 + 3*x)^(7/2)*Sqrt[3 + 5*x])/(1 - 2*x)^(5/2), x, 9, (-18551*Sqrt[1 - 2*x]*Sqrt[2 + 3*x]*Sqrt[3 + 5*x])/550 - (797*Sqrt[1 - 2*x]*(2 + 3*x)^(3/2)*Sqrt[3 + 5*x])/110 - (133*(2 + 3*x)^(5/2)*Sqrt[3 + 5*x])/(33*Sqrt[1 - 2*x]) + ((2 + 3*x)^(7/2)*Sqrt[3 + 5*x])/(3*(1 - 2*x)^(3/2)) - (1289089*Sqrt[7/5]*EllipticE[ArcSin[Sqrt[5/11]*Sqrt[1 - 2*x]], 33/35])/3300 + (129857*EllipticF[ArcSin[Sqrt[3/7]*Sqrt[1 - 2*x]], 35/33])/(1650*Sqrt[33])}
{((2 + 3*x)^(5/2)*Sqrt[3 + 5*x])/(1 - 2*x)^(5/2), x, 8, (-133*Sqrt[1 - 2*x]*Sqrt[2 + 3*x]*Sqrt[3 + 5*x])/22 - (100*(2 + 3*x)^(3/2)*Sqrt[3 + 5*x])/(33*Sqrt[1 - 2*x]) + ((2 + 3*x)^(5/2)*Sqrt[3 + 5*x])/(3*(1 - 2*x)^(3/2)) - (4621*Sqrt[7/5]*EllipticE[ArcSin[Sqrt[5/11]*Sqrt[1 - 2*x]], 33/35])/66 + (931*EllipticF[ArcSin[Sqrt[3/7]*Sqrt[1 - 2*x]], 35/33])/(66*Sqrt[33])}
{((2 + 3*x)^(3/2)*Sqrt[3 + 5*x])/(1 - 2*x)^(5/2), x, 7, (-67*Sqrt[2 + 3*x]*Sqrt[3 + 5*x])/(33*Sqrt[1 - 2*x]) + ((2 + 3*x)^(3/2)*Sqrt[3 + 5*x])/(3*(1 - 2*x)^(3/2)) - (133*Sqrt[35]*EllipticE[ArcSin[Sqrt[5/11]*Sqrt[1 - 2*x]], 33/35])/66 + (67*EllipticF[ArcSin[Sqrt[3/7]*Sqrt[1 - 2*x]], 35/33])/(33*Sqrt[33])}
{(Sqrt[2 + 3*x]*Sqrt[3 + 5*x])/(1 - 2*x)^(5/2), x, 7, (Sqrt[2 + 3*x]*Sqrt[3 + 5*x])/(3*(1 - 2*x)^(3/2)) - (68*Sqrt[2 + 3*x]*Sqrt[3 + 5*x])/(231*Sqrt[1 - 2*x]) - (34*Sqrt[5/7]*EllipticE[ArcSin[Sqrt[5/11]*Sqrt[1 - 2*x]], 33/35])/33 + (5*EllipticF[ArcSin[Sqrt[3/7]*Sqrt[1 - 2*x]], 35/33])/(33*Sqrt[33])}
{Sqrt[3 + 5*x]/((1 - 2*x)^(5/2)*Sqrt[2 + 3*x]), x, 7, (2*Sqrt[2 + 3*x]*Sqrt[3 + 5*x])/(21*(1 - 2*x)^(3/2)) + (62*Sqrt[2 + 3*x]*Sqrt[3 + 5*x])/(1617*Sqrt[1 - 2*x]) + (31*Sqrt[5/7]*EllipticE[ArcSin[Sqrt[5/11]*Sqrt[1 - 2*x]], 33/35])/231 + (10*EllipticF[ArcSin[Sqrt[3/7]*Sqrt[1 - 2*x]], 35/33])/(231*Sqrt[33])}
{Sqrt[3 + 5*x]/((1 - 2*x)^(5/2)*(2 + 3*x)^(3/2)), x, 8, (2*Sqrt[3 + 5*x])/(21*(1 - 2*x)^(3/2)*Sqrt[2 + 3*x]) + (194*Sqrt[3 + 5*x])/(1617*Sqrt[1 - 2*x]*Sqrt[2 + 3*x]) - (458*Sqrt[1 - 2*x]*Sqrt[3 + 5*x])/(3773*Sqrt[2 + 3*x]) + (458*Sqrt[5/7]*EllipticE[ArcSin[Sqrt[5/11]*Sqrt[1 - 2*x]], 33/35])/1617 - (970*EllipticF[ArcSin[Sqrt[3/7]*Sqrt[1 - 2*x]], 35/33])/(1617*Sqrt[33])}
{Sqrt[3 + 5*x]/((1 - 2*x)^(5/2)*(2 + 3*x)^(5/2)), x, 9, (2*Sqrt[3 + 5*x])/(21*(1 - 2*x)^(3/2)*(2 + 3*x)^(3/2)) + (326*Sqrt[3 + 5*x])/(1617*Sqrt[1 - 2*x]*(2 + 3*x)^(3/2)) - (458*Sqrt[1 - 2*x]*Sqrt[3 + 5*x])/(3773*(2 + 3*x)^(3/2)) + (338*Sqrt[1 - 2*x]*Sqrt[3 + 5*x])/(26411*Sqrt[2 + 3*x]) - (338*Sqrt[5/7]*EllipticE[ArcSin[Sqrt[5/11]*Sqrt[1 - 2*x]], 33/35])/11319 - (4580*EllipticF[ArcSin[Sqrt[3/7]*Sqrt[1 - 2*x]], 35/33])/(11319*Sqrt[33])}
{Sqrt[3 + 5*x]/((1 - 2*x)^(5/2)*(2 + 3*x)^(7/2)), x, 10, (2*Sqrt[3 + 5*x])/(21*(1 - 2*x)^(3/2)*(2 + 3*x)^(5/2)) + (458*Sqrt[3 + 5*x])/(1617*Sqrt[1 - 2*x]*(2 + 3*x)^(5/2)) - (2818*Sqrt[1 - 2*x]*Sqrt[3 + 5*x])/(18865*(2 + 3*x)^(5/2)) - (5438*Sqrt[1 - 2*x]*Sqrt[3 + 5*x])/(132055*(2 + 3*x)^(3/2)) + (189368*Sqrt[1 - 2*x]*Sqrt[3 + 5*x])/(924385*Sqrt[2 + 3*x]) - (189368*EllipticE[ArcSin[Sqrt[5/11]*Sqrt[1 - 2*x]], 33/35])/(79233*Sqrt[35]) - (10876*EllipticF[ArcSin[Sqrt[3/7]*Sqrt[1 - 2*x]], 35/33])/(79233*Sqrt[33])}


{((2 + 3*x)^(7/2)*(3 + 5*x)^(3/2))/(1 - 2*x)^(5/2), x, 10, (-2166399*Sqrt[1 - 2*x]*Sqrt[2 + 3*x]*Sqrt[3 + 5*x])/7700 - (140289*Sqrt[1 - 2*x]*Sqrt[2 + 3*x]*(3 + 5*x)^(3/2))/3850 - (1341*Sqrt[1 - 2*x]*(2 + 3*x)^(3/2)*(3 + 5*x)^(3/2))/154 - (56*(2 + 3*x)^(5/2)*(3 + 5*x)^(3/2))/(11*Sqrt[1 - 2*x]) + ((2 + 3*x)^(7/2)*(3 + 5*x)^(3/2))/(3*(1 - 2*x)^(3/2)) - (6547351*EllipticE[ArcSin[Sqrt[5/11]*Sqrt[1 - 2*x]], 33/35])/(300*Sqrt[35]) + (188443*EllipticF[ArcSin[Sqrt[3/7]*Sqrt[1 - 2*x]], 35/33])/(300*Sqrt[33])}
{((2 + 3*x)^(5/2)*(3 + 5*x)^(3/2))/(1 - 2*x)^(5/2), x, 9, (-6231*Sqrt[1 - 2*x]*Sqrt[2 + 3*x]*Sqrt[3 + 5*x])/110 - (807*Sqrt[1 - 2*x]*Sqrt[2 + 3*x]*(3 + 5*x)^(3/2))/110 - (45*(2 + 3*x)^(3/2)*(3 + 5*x)^(3/2))/(11*Sqrt[1 - 2*x]) + ((2 + 3*x)^(5/2)*(3 + 5*x)^(3/2))/(3*(1 - 2*x)^(3/2)) - (37663*Sqrt[7/5]*EllipticE[ArcSin[Sqrt[5/11]*Sqrt[1 - 2*x]], 33/35])/60 + (1897*EllipticF[ArcSin[Sqrt[3/7]*Sqrt[1 - 2*x]], 35/33])/(15*Sqrt[33])}
{((2 + 3*x)^(3/2)*(3 + 5*x)^(3/2))/(1 - 2*x)^(5/2), x, 8, (-225*Sqrt[1 - 2*x]*Sqrt[2 + 3*x]*Sqrt[3 + 5*x])/22 - (34*Sqrt[2 + 3*x]*(3 + 5*x)^(3/2))/(11*Sqrt[1 - 2*x]) + ((2 + 3*x)^(3/2)*(3 + 5*x)^(3/2))/(3*(1 - 2*x)^(3/2)) - (68*Sqrt[35]*EllipticE[ArcSin[Sqrt[5/11]*Sqrt[1 - 2*x]], 33/35])/3 + (137*EllipticF[ArcSin[Sqrt[3/7]*Sqrt[1 - 2*x]], 35/33])/(6*Sqrt[33])}
{(Sqrt[2 + 3*x]*(3 + 5*x)^(3/2))/(1 - 2*x)^(5/2), x, 7, (-23*Sqrt[2 + 3*x]*Sqrt[3 + 5*x])/(7*Sqrt[1 - 2*x]) + (Sqrt[2 + 3*x]*(3 + 5*x)^(3/2))/(3*(1 - 2*x)^(3/2)) - (139*Sqrt[5/7]*EllipticE[ArcSin[Sqrt[5/11]*Sqrt[1 - 2*x]], 33/35])/6 + (10*EllipticF[ArcSin[Sqrt[3/7]*Sqrt[1 - 2*x]], 35/33])/(3*Sqrt[33])}
{(3 + 5*x)^(3/2)/((1 - 2*x)^(5/2)*Sqrt[2 + 3*x]), x, 7, (-13*Sqrt[2 + 3*x]*Sqrt[3 + 5*x])/(49*Sqrt[1 - 2*x]) + (2*Sqrt[2 + 3*x]*(3 + 5*x)^(3/2))/(21*(1 - 2*x)^(3/2)) - (37*Sqrt[5/7]*EllipticE[ArcSin[Sqrt[5/11]*Sqrt[1 - 2*x]], 33/35])/21 + (5*EllipticF[ArcSin[Sqrt[3/7]*Sqrt[1 - 2*x]], 35/33])/(21*Sqrt[33])}
{(3 + 5*x)^(3/2)/((1 - 2*x)^(5/2)*(2 + 3*x)^(3/2)), x, 8, (9*Sqrt[3 + 5*x])/(49*Sqrt[1 - 2*x]*Sqrt[2 + 3*x]) - (19*Sqrt[1 - 2*x]*Sqrt[3 + 5*x])/(343*Sqrt[2 + 3*x]) + (2*(3 + 5*x)^(3/2))/(21*(1 - 2*x)^(3/2)*Sqrt[2 + 3*x]) + (19*Sqrt[5/7]*EllipticE[ArcSin[Sqrt[5/11]*Sqrt[1 - 2*x]], 33/35])/147 + (40*EllipticF[ArcSin[Sqrt[3/7]*Sqrt[1 - 2*x]], 35/33])/(147*Sqrt[33])}
{(3 + 5*x)^(3/2)/((1 - 2*x)^(5/2)*(2 + 3*x)^(5/2)), x, 9, (31*Sqrt[3 + 5*x])/(49*Sqrt[1 - 2*x]*(2 + 3*x)^(3/2)) - (89*Sqrt[1 - 2*x]*Sqrt[3 + 5*x])/(343*(2 + 3*x)^(3/2)) - (496*Sqrt[1 - 2*x]*Sqrt[3 + 5*x])/(2401*Sqrt[2 + 3*x]) + (2*(3 + 5*x)^(3/2))/(21*(1 - 2*x)^(3/2)*(2 + 3*x)^(3/2)) + (496*Sqrt[5/7]*EllipticE[ArcSin[Sqrt[5/11]*Sqrt[1 - 2*x]], 33/35])/1029 - (890*EllipticF[ArcSin[Sqrt[3/7]*Sqrt[1 - 2*x]], 35/33])/(1029*Sqrt[33])}
{(3 + 5*x)^(3/2)/((1 - 2*x)^(5/2)*(2 + 3*x)^(7/2)), x, 10, (53*Sqrt[3 + 5*x])/(49*Sqrt[1 - 2*x]*(2 + 3*x)^(5/2)) - (779*Sqrt[1 - 2*x]*Sqrt[3 + 5*x])/(1715*(2 + 3*x)^(5/2)) - (2264*Sqrt[1 - 2*x]*Sqrt[3 + 5*x])/(12005*(2 + 3*x)^(3/2)) - (3946*Sqrt[1 - 2*x]*Sqrt[3 + 5*x])/(84035*Sqrt[2 + 3*x]) + (2*(3 + 5*x)^(3/2))/(21*(1 - 2*x)^(3/2)*(2 + 3*x)^(5/2)) + (3946*EllipticE[ArcSin[Sqrt[5/11]*Sqrt[1 - 2*x]], 33/35])/(7203*Sqrt[35]) - (4528*EllipticF[ArcSin[Sqrt[3/7]*Sqrt[1 - 2*x]], 35/33])/(7203*Sqrt[33])}


{((2 + 3*x)^(7/2)*(3 + 5*x)^(5/2))/(1 - 2*x)^(5/2), x, 11, (-1313411*Sqrt[1 - 2*x]*Sqrt[2 + 3*x]*Sqrt[3 + 5*x])/630 - (1310203*Sqrt[1 - 2*x]*Sqrt[2 + 3*x]*(3 + 5*x)^(3/2))/4620 - (6277*Sqrt[1 - 2*x]*Sqrt[2 + 3*x]*(3 + 5*x)^(5/2))/154 - (225*Sqrt[1 - 2*x]*(2 + 3*x)^(3/2)*(3 + 5*x)^(5/2))/22 - (203*(2 + 3*x)^(5/2)*(3 + 5*x)^(5/2))/(33*Sqrt[1 - 2*x]) + ((2 + 3*x)^(7/2)*(3 + 5*x)^(5/2))/(3*(1 - 2*x)^(3/2)) - (174654791*EllipticE[ArcSin[Sqrt[5/11]*Sqrt[1 - 2*x]], 33/35])/(1080*Sqrt[35]) + (2513419*EllipticF[ArcSin[Sqrt[3/7]*Sqrt[1 - 2*x]], 35/33])/(540*Sqrt[33])}
{((2 + 3*x)^(5/2)*(3 + 5*x)^(5/2))/(1 - 2*x)^(5/2), x, 10, (-12601*Sqrt[1 - 2*x]*Sqrt[2 + 3*x]*Sqrt[3 + 5*x])/28 - (28283*Sqrt[1 - 2*x]*Sqrt[2 + 3*x]*(3 + 5*x)^(3/2))/462 - (1355*Sqrt[1 - 2*x]*Sqrt[2 + 3*x]*(3 + 5*x)^(5/2))/154 - (170*(2 + 3*x)^(3/2)*(3 + 5*x)^(5/2))/(33*Sqrt[1 - 2*x]) + ((2 + 3*x)^(5/2)*(3 + 5*x)^(5/2))/(3*(1 - 2*x)^(3/2)) - (69819*EllipticE[ArcSin[Sqrt[5/11]*Sqrt[1 - 2*x]], 33/35])/(2*Sqrt[35]) + (4019*EllipticF[ArcSin[Sqrt[3/7]*Sqrt[1 - 2*x]], 35/33])/(4*Sqrt[33])}
{((2 + 3*x)^(3/2)*(3 + 5*x)^(5/2))/(1 - 2*x)^(5/2), x, 9, -91*Sqrt[1 - 2*x]*Sqrt[2 + 3*x]*Sqrt[3 + 5*x] - (817*Sqrt[1 - 2*x]*Sqrt[2 + 3*x]*(3 + 5*x)^(3/2))/66 - (137*Sqrt[2 + 3*x]*(3 + 5*x)^(5/2))/(33*Sqrt[1 - 2*x]) + ((2 + 3*x)^(3/2)*(3 + 5*x)^(5/2))/(3*(1 - 2*x)^(3/2)) - (12101*Sqrt[7/5]*EllipticE[ArcSin[Sqrt[5/11]*Sqrt[1 - 2*x]], 33/35])/12 + (1219*EllipticF[ArcSin[Sqrt[3/7]*Sqrt[1 - 2*x]], 35/33])/(6*Sqrt[33])}
{(Sqrt[2 + 3*x]*(3 + 5*x)^(5/2))/(1 - 2*x)^(5/2), x, 8, (-695*Sqrt[1 - 2*x]*Sqrt[2 + 3*x]*Sqrt[3 + 5*x])/42 - (104*Sqrt[2 + 3*x]*(3 + 5*x)^(3/2))/(21*Sqrt[1 - 2*x]) + (Sqrt[2 + 3*x]*(3 + 5*x)^(5/2))/(3*(1 - 2*x)^(3/2)) - (4621*Sqrt[5/7]*EllipticE[ArcSin[Sqrt[5/11]*Sqrt[1 - 2*x]], 33/35])/18 + (665*EllipticF[ArcSin[Sqrt[3/7]*Sqrt[1 - 2*x]], 35/33])/(18*Sqrt[33])}
{(3 + 5*x)^(5/2)/((1 - 2*x)^(5/2)*Sqrt[2 + 3*x]), x, 8, (-120*Sqrt[1 - 2*x]*Sqrt[2 + 3*x]*Sqrt[3 + 5*x])/49 - (109*Sqrt[2 + 3*x]*(3 + 5*x)^(3/2))/(147*Sqrt[1 - 2*x]) + (2*Sqrt[2 + 3*x]*(3 + 5*x)^(5/2))/(21*(1 - 2*x)^(3/2)) - (1597*Sqrt[5/7]*EllipticE[ArcSin[Sqrt[5/11]*Sqrt[1 - 2*x]], 33/35])/42 + (115*EllipticF[ArcSin[Sqrt[3/7]*Sqrt[1 - 2*x]], 35/33])/(21*Sqrt[33])}
{(3 + 5*x)^(5/2)/((1 - 2*x)^(5/2)*(2 + 3*x)^(3/2)), x, 8, (-17*Sqrt[1 - 2*x]*Sqrt[3 + 5*x])/(343*Sqrt[2 + 3*x]) - (43*(3 + 5*x)^(3/2))/(147*Sqrt[1 - 2*x]*Sqrt[2 + 3*x]) + (2*(3 + 5*x)^(5/2))/(21*(1 - 2*x)^(3/2)*Sqrt[2 + 3*x]) - (146*Sqrt[5/7]*EllipticE[ArcSin[Sqrt[5/11]*Sqrt[1 - 2*x]], 33/35])/49 + (5*Sqrt[3/11]*EllipticF[ArcSin[Sqrt[3/7]*Sqrt[1 - 2*x]], 35/33])/49}
{(3 + 5*x)^(5/2)/((1 - 2*x)^(5/2)*(2 + 3*x)^(5/2)), x, 9, (19*Sqrt[1 - 2*x]*Sqrt[3 + 5*x])/(1029*(2 + 3*x)^(3/2)) - (169*Sqrt[1 - 2*x]*Sqrt[3 + 5*x])/(7203*Sqrt[2 + 3*x]) + (23*(3 + 5*x)^(3/2))/(147*Sqrt[1 - 2*x]*(2 + 3*x)^(3/2)) + (2*(3 + 5*x)^(5/2))/(21*(1 - 2*x)^(3/2)*(2 + 3*x)^(3/2)) + (169*Sqrt[5/7]*EllipticE[ArcSin[Sqrt[5/11]*Sqrt[1 - 2*x]], 33/35])/3087 + (2290*EllipticF[ArcSin[Sqrt[3/7]*Sqrt[1 - 2*x]], 35/33])/(3087*Sqrt[33])}
{(3 + 5*x)^(5/2)/((1 - 2*x)^(5/2)*(2 + 3*x)^(7/2)), x, 10, (143*Sqrt[1 - 2*x]*Sqrt[3 + 5*x])/(1715*(2 + 3*x)^(5/2)) - (4437*Sqrt[1 - 2*x]*Sqrt[3 + 5*x])/(12005*(2 + 3*x)^(3/2)) - (27618*Sqrt[1 - 2*x]*Sqrt[3 + 5*x])/(84035*Sqrt[2 + 3*x]) + (89*(3 + 5*x)^(3/2))/(147*Sqrt[1 - 2*x]*(2 + 3*x)^(5/2)) + (2*(3 + 5*x)^(5/2))/(21*(1 - 2*x)^(3/2)*(2 + 3*x)^(5/2)) + (9206*EllipticE[ArcSin[Sqrt[5/11]*Sqrt[1 - 2*x]], 33/35])/(2401*Sqrt[35]) - (986*Sqrt[3/11]*EllipticF[ArcSin[Sqrt[3/7]*Sqrt[1 - 2*x]], 35/33])/2401}
{(3 + 5*x)^(5/2)/((1 - 2*x)^(5/2)*(2 + 3*x)^(9/2)), x, 11, (355*Sqrt[1 - 2*x]*Sqrt[3 + 5*x])/(2401*(2 + 3*x)^(7/2)) - (11433*Sqrt[1 - 2*x]*Sqrt[3 + 5*x])/(16807*(2 + 3*x)^(5/2)) - (33778*Sqrt[1 - 2*x]*Sqrt[3 + 5*x])/(117649*(2 + 3*x)^(3/2)) - (98642*Sqrt[1 - 2*x]*Sqrt[3 + 5*x])/(823543*Sqrt[2 + 3*x]) + (155*(3 + 5*x)^(3/2))/(147*Sqrt[1 - 2*x]*(2 + 3*x)^(7/2)) + (2*(3 + 5*x)^(5/2))/(21*(1 - 2*x)^(3/2)*(2 + 3*x)^(7/2)) + (98642*Sqrt[5/7]*EllipticE[ArcSin[Sqrt[5/11]*Sqrt[1 - 2*x]], 33/35])/352947 - (337780*EllipticF[ArcSin[Sqrt[3/7]*Sqrt[1 - 2*x]], 35/33])/(352947*Sqrt[33])}


(* ::Subsubsection::Closed:: *)
(*n>0*)


{(2 + 3*x)^(9/2)/((1 - 2*x)^(5/2)*Sqrt[3 + 5*x]), x, 10, -((317384*Sqrt[1 - 2*x]*Sqrt[2 + 3*x]*Sqrt[3 + 5*x])/15125) - (27271*Sqrt[1 - 2*x]*(2 + 3*x)^(3/2)*Sqrt[3 + 5*x])/6050 - (130/121)*Sqrt[1 - 2*x]*(2 + 3*x)^(5/2)*Sqrt[3 + 5*x] - (227*(2 + 3*x)^(7/2)*Sqrt[3 + 5*x])/(363*Sqrt[1 - 2*x]) + (2*(2 + 3*x)^(9/2)*Sqrt[3 + 5*x])/(33*(1 - 2*x)^(3/2)) - (44109377*Sqrt[7/5]*EllipticE[ArcSin[Sqrt[5/11]*Sqrt[1 - 2*x]], 33/35])/181500 + (2221688*EllipticF[ArcSin[Sqrt[3/7]*Sqrt[1 - 2*x]], 35/33])/(45375*Sqrt[33])}
{(2 + 3*x)^(7/2)/((1 - 2*x)^(5/2)*Sqrt[3 + 5*x]), x, 9, (-4517*Sqrt[1 - 2*x]*Sqrt[2 + 3*x]*Sqrt[3 + 5*x])/1210 - (97*Sqrt[1 - 2*x]*(2 + 3*x)^(3/2)*Sqrt[3 + 5*x])/121 - (161*(2 + 3*x)^(5/2)*Sqrt[3 + 5*x])/(363*Sqrt[1 - 2*x]) + (2*(2 + 3*x)^(7/2)*Sqrt[3 + 5*x])/(33*(1 - 2*x)^(3/2)) - (78472*Sqrt[7/5]*EllipticE[ArcSin[Sqrt[5/11]*Sqrt[1 - 2*x]], 33/35])/1815 + (31619*EllipticF[ArcSin[Sqrt[3/7]*Sqrt[1 - 2*x]], 35/33])/(3630*Sqrt[33])}
{(2 + 3*x)^(5/2)/((1 - 2*x)^(5/2)*Sqrt[3 + 5*x]), x, 8, (-64*Sqrt[1 - 2*x]*Sqrt[2 + 3*x]*Sqrt[3 + 5*x])/121 - (95*(2 + 3*x)^(3/2)*Sqrt[3 + 5*x])/(363*Sqrt[1 - 2*x]) + (2*(2 + 3*x)^(5/2)*Sqrt[3 + 5*x])/(33*(1 - 2*x)^(3/2)) - (4451*Sqrt[7/5]*EllipticE[ArcSin[Sqrt[5/11]*Sqrt[1 - 2*x]], 33/35])/726 + (448*EllipticF[ArcSin[Sqrt[3/7]*Sqrt[1 - 2*x]], 35/33])/(363*Sqrt[33])}
{(2 + 3*x)^(3/2)/((1 - 2*x)^(5/2)*Sqrt[3 + 5*x]), x, 7, (-29*Sqrt[2 + 3*x]*Sqrt[3 + 5*x])/(363*Sqrt[1 - 2*x]) + (2*(2 + 3*x)^(3/2)*Sqrt[3 + 5*x])/(33*(1 - 2*x)^(3/2)) - (31*Sqrt[35]*EllipticE[ArcSin[Sqrt[5/11]*Sqrt[1 - 2*x]], 33/35])/363 + (29*EllipticF[ArcSin[Sqrt[3/7]*Sqrt[1 - 2*x]], 35/33])/(363*Sqrt[33])}
{Sqrt[2 + 3*x]/((1 - 2*x)^(5/2)*Sqrt[3 + 5*x]), x, 7, (2*Sqrt[2 + 3*x]*Sqrt[3 + 5*x])/(33*(1 - 2*x)^(3/2)) + (74*Sqrt[2 + 3*x]*Sqrt[3 + 5*x])/(2541*Sqrt[1 - 2*x]) + (37*Sqrt[5/7]*EllipticE[ArcSin[Sqrt[5/11]*Sqrt[1 - 2*x]], 33/35])/363 - (20*EllipticF[ArcSin[Sqrt[3/7]*Sqrt[1 - 2*x]], 35/33])/(363*Sqrt[33])}
{1/((1 - 2*x)^(5/2)*Sqrt[2 + 3*x]*Sqrt[3 + 5*x]), x, 7, (4*Sqrt[2 + 3*x]*Sqrt[3 + 5*x])/(231*(1 - 2*x)^(3/2)) + (544*Sqrt[2 + 3*x]*Sqrt[3 + 5*x])/(17787*Sqrt[1 - 2*x]) + (272*Sqrt[5/7]*EllipticE[ArcSin[Sqrt[5/11]*Sqrt[1 - 2*x]], 33/35])/2541 - (1030*EllipticF[ArcSin[Sqrt[3/7]*Sqrt[1 - 2*x]], 35/33])/(2541*Sqrt[33])}
{1/((1 - 2*x)^(5/2)*(2 + 3*x)^(3/2)*Sqrt[3 + 5*x]), x, 8, (4*Sqrt[3 + 5*x])/(231*(1 - 2*x)^(3/2)*Sqrt[2 + 3*x]) + (808*Sqrt[3 + 5*x])/(17787*Sqrt[1 - 2*x]*Sqrt[2 + 3*x]) + (5594*Sqrt[1 - 2*x]*Sqrt[3 + 5*x])/(41503*Sqrt[2 + 3*x]) - (5594*Sqrt[5/7]*EllipticE[ArcSin[Sqrt[5/11]*Sqrt[1 - 2*x]], 33/35])/17787 - (4040*EllipticF[ArcSin[Sqrt[3/7]*Sqrt[1 - 2*x]], 35/33])/(17787*Sqrt[33])}
{1/((1 - 2*x)^(5/2)*(2 + 3*x)^(5/2)*Sqrt[3 + 5*x]), x, 9, (4*Sqrt[3 + 5*x])/(231*(1 - 2*x)^(3/2)*(2 + 3*x)^(3/2)) + (1072*Sqrt[3 + 5*x])/(17787*Sqrt[1 - 2*x]*(2 + 3*x)^(3/2)) + (974*Sqrt[1 - 2*x]*Sqrt[3 + 5*x])/(41503*(2 + 3*x)^(3/2)) + (184636*Sqrt[1 - 2*x]*Sqrt[3 + 5*x])/(290521*Sqrt[2 + 3*x]) - (184636*Sqrt[5/7]*EllipticE[ArcSin[Sqrt[5/11]*Sqrt[1 - 2*x]], 33/35])/124509 + (9740*EllipticF[ArcSin[Sqrt[3/7]*Sqrt[1 - 2*x]], 35/33])/(124509*Sqrt[33])}
{1/((1 - 2*x)^(5/2)*(2 + 3*x)^(7/2)*Sqrt[3 + 5*x]), x, 10, (4*Sqrt[3 + 5*x])/(231*(1 - 2*x)^(3/2)*(2 + 3*x)^(5/2)) + (1336*Sqrt[3 + 5*x])/(17787*Sqrt[1 - 2*x]*(2 + 3*x)^(5/2)) - (806*Sqrt[1 - 2*x]*Sqrt[3 + 5*x])/(207515*(2 + 3*x)^(5/2)) + (349904*Sqrt[1 - 2*x]*Sqrt[3 + 5*x])/(1452605*(2 + 3*x)^(3/2)) + (26062156*Sqrt[1 - 2*x]*Sqrt[3 + 5*x])/(10168235*Sqrt[2 + 3*x]) - (26062156*EllipticE[ArcSin[Sqrt[5/11]*Sqrt[1 - 2*x]], 33/35])/(871563*Sqrt[35]) + (699808*EllipticF[ArcSin[Sqrt[3/7]*Sqrt[1 - 2*x]], 35/33])/(871563*Sqrt[33])}


{(2 + 3*x)^(11/2)/((1 - 2*x)^(5/2)*(3 + 5*x)^(3/2)), x, 11, (215*Sqrt[1 - 2*x]*(2 + 3*x)^(7/2))/(3993*Sqrt[3 + 5*x]) - (223*(2 + 3*x)^(9/2))/(363*Sqrt[1 - 2*x]*Sqrt[3 + 5*x]) + (2*(2 + 3*x)^(11/2))/(33*(1 - 2*x)^(3/2)*Sqrt[3 + 5*x]) - (21713939*Sqrt[1 - 2*x]*Sqrt[2 + 3*x]*Sqrt[3 + 5*x])/1663750 - (932783*Sqrt[1 - 2*x]*(2 + 3*x)^(3/2)*Sqrt[3 + 5*x])/332750 - (4439*Sqrt[1 - 2*x]*(2 + 3*x)^(5/2)*Sqrt[3 + 5*x])/6655 - (1508889271*Sqrt[7/5]*EllipticE[ArcSin[Sqrt[5/11]*Sqrt[1 - 2*x]], 33/35])/9982500 + (151997573*EllipticF[ArcSin[Sqrt[3/7]*Sqrt[1 - 2*x]], 35/33])/(4991250*Sqrt[33])}
{(2 + 3*x)^(9/2)/((1 - 2*x)^(5/2)*(3 + 5*x)^(3/2)), x, 10, (149*Sqrt[1 - 2*x]*(2 + 3*x)^(5/2))/(3993*Sqrt[3 + 5*x]) - (157*(2 + 3*x)^(7/2))/(363*Sqrt[1 - 2*x]*Sqrt[3 + 5*x]) + (2*(2 + 3*x)^(9/2))/(33*(1 - 2*x)^(3/2)*Sqrt[3 + 5*x]) - (153319*Sqrt[1 - 2*x]*Sqrt[2 + 3*x]*Sqrt[3 + 5*x])/66550 - (3284*Sqrt[1 - 2*x]*(2 + 3*x)^(3/2)*Sqrt[3 + 5*x])/6655 - (5327983*Sqrt[7/5]*EllipticE[ArcSin[Sqrt[5/11]*Sqrt[1 - 2*x]], 33/35])/199650 + (1073233*EllipticF[ArcSin[Sqrt[3/7]*Sqrt[1 - 2*x]], 35/33])/(199650*Sqrt[33])}
{(2 + 3*x)^(7/2)/((1 - 2*x)^(5/2)*(3 + 5*x)^(3/2)), x, 9, (83*Sqrt[1 - 2*x]*(2 + 3*x)^(3/2))/(3993*Sqrt[3 + 5*x]) - (91*(2 + 3*x)^(5/2))/(363*Sqrt[1 - 2*x]*Sqrt[3 + 5*x]) + (2*(2 + 3*x)^(7/2))/(33*(1 - 2*x)^(3/2)*Sqrt[3 + 5*x]) - (2129*Sqrt[1 - 2*x]*Sqrt[2 + 3*x]*Sqrt[3 + 5*x])/6655 - (148831*Sqrt[7/5]*EllipticE[ArcSin[Sqrt[5/11]*Sqrt[1 - 2*x]], 33/35])/39930 + (14903*EllipticF[ArcSin[Sqrt[3/7]*Sqrt[1 - 2*x]], 35/33])/(19965*Sqrt[33])}
{(2 + 3*x)^(5/2)/((1 - 2*x)^(5/2)*(3 + 5*x)^(3/2)), x, 8, (17*Sqrt[1 - 2*x]*Sqrt[2 + 3*x])/(3993*Sqrt[3 + 5*x]) - (25*(2 + 3*x)^(3/2))/(363*Sqrt[1 - 2*x]*Sqrt[3 + 5*x]) + (2*(2 + 3*x)^(5/2))/(33*(1 - 2*x)^(3/2)*Sqrt[3 + 5*x]) - (974*Sqrt[7/5]*EllipticE[ArcSin[Sqrt[5/11]*Sqrt[1 - 2*x]], 33/35])/3993 + (119*EllipticF[ArcSin[Sqrt[3/7]*Sqrt[1 - 2*x]], 35/33])/(3993*Sqrt[33])}
{(2 + 3*x)^(3/2)/((1 - 2*x)^(5/2)*(3 + 5*x)^(3/2)), x, 8, (41*Sqrt[2 + 3*x])/(363*Sqrt[1 - 2*x]*Sqrt[3 + 5*x]) - (245*Sqrt[1 - 2*x]*Sqrt[2 + 3*x])/(3993*Sqrt[3 + 5*x]) + (2*(2 + 3*x)^(3/2))/(33*(1 - 2*x)^(3/2)*Sqrt[3 + 5*x]) + (49*Sqrt[35]*EllipticE[ArcSin[Sqrt[5/11]*Sqrt[1 - 2*x]], 33/35])/3993 - (362*EllipticF[ArcSin[Sqrt[3/7]*Sqrt[1 - 2*x]], 35/33])/(3993*Sqrt[33])}
{Sqrt[2 + 3*x]/((1 - 2*x)^(5/2)*(3 + 5*x)^(3/2)), x, 8, (2*Sqrt[2 + 3*x])/(33*(1 - 2*x)^(3/2)*Sqrt[3 + 5*x]) + (214*Sqrt[2 + 3*x])/(2541*Sqrt[1 - 2*x]*Sqrt[3 + 5*x]) - (2470*Sqrt[1 - 2*x]*Sqrt[2 + 3*x])/(27951*Sqrt[3 + 5*x]) + (494*Sqrt[5/7]*EllipticE[ArcSin[Sqrt[5/11]*Sqrt[1 - 2*x]], 33/35])/3993 - (1150*EllipticF[ArcSin[Sqrt[3/7]*Sqrt[1 - 2*x]], 35/33])/(3993*Sqrt[33])}
{1/((1 - 2*x)^(5/2)*Sqrt[2 + 3*x]*(3 + 5*x)^(3/2)), x, 8, (4*Sqrt[2 + 3*x])/(231*(1 - 2*x)^(3/2)*Sqrt[3 + 5*x]) + (824*Sqrt[2 + 3*x])/(17787*Sqrt[1 - 2*x]*Sqrt[3 + 5*x]) - (41570*Sqrt[1 - 2*x]*Sqrt[2 + 3*x])/(195657*Sqrt[3 + 5*x]) + (8314*Sqrt[5/7]*EllipticE[ArcSin[Sqrt[5/11]*Sqrt[1 - 2*x]], 33/35])/27951 - (6260*EllipticF[ArcSin[Sqrt[3/7]*Sqrt[1 - 2*x]], 35/33])/(27951*Sqrt[33])}
{1/((1 - 2*x)^(5/2)*(2 + 3*x)^(3/2)*(3 + 5*x)^(3/2)), x, 9, 4/(231*(1 - 2*x)^(3/2)*Sqrt[2 + 3*x]*Sqrt[3 + 5*x]) + 1088/(17787*Sqrt[1 - 2*x]*Sqrt[2 + 3*x]*Sqrt[3 + 5*x]) + (5314*Sqrt[1 - 2*x])/(41503*Sqrt[2 + 3*x]*Sqrt[3 + 5*x]) - (2377960*Sqrt[1 - 2*x]*Sqrt[2 + 3*x])/(1369599*Sqrt[3 + 5*x]) + (475592*Sqrt[5/7]*EllipticE[ArcSin[Sqrt[5/11]*Sqrt[1 - 2*x]], 33/35])/195657 - (85780*EllipticF[ArcSin[Sqrt[3/7]*Sqrt[1 - 2*x]], 35/33])/(195657*Sqrt[33])}
{1/((1 - 2*x)^(5/2)*(2 + 3*x)^(5/2)*(3 + 5*x)^(3/2)), x, 10, 4/(231*(1 - 2*x)^(3/2)*(2 + 3*x)^(3/2)*Sqrt[3 + 5*x]) + 1352/(17787*Sqrt[1 - 2*x]*(2 + 3*x)^(3/2)*Sqrt[3 + 5*x]) + (694*Sqrt[1 - 2*x])/(41503*(2 + 3*x)^(3/2)*Sqrt[3 + 5*x]) + (336536*Sqrt[1 - 2*x])/(290521*Sqrt[2 + 3*x]*Sqrt[3 + 5*x]) - (113693540*Sqrt[1 - 2*x]*Sqrt[2 + 3*x])/(9587193*Sqrt[3 + 5*x]) + (22738708*Sqrt[5/7]*EllipticE[ArcSin[Sqrt[5/11]*Sqrt[1 - 2*x]], 33/35])/1369599 - (3323720*EllipticF[ArcSin[Sqrt[3/7]*Sqrt[1 - 2*x]], 35/33])/(1369599*Sqrt[33])}
{1/((1 - 2*x)^(5/2)*(2 + 3*x)^(7/2)*(3 + 5*x)^(3/2)), x, 11, 4/(231*(1 - 2*x)^(3/2)*(2 + 3*x)^(5/2)*Sqrt[3 + 5*x]) + 1616/(17787*Sqrt[1 - 2*x]*(2 + 3*x)^(5/2)*Sqrt[3 + 5*x]) - (2206*Sqrt[1 - 2*x])/(207515*(2 + 3*x)^(5/2)*Sqrt[3 + 5*x]) + (499564*Sqrt[1 - 2*x])/(1452605*(2 + 3*x)^(3/2)*Sqrt[3 + 5*x]) + (72709316*Sqrt[1 - 2*x])/(10168235*Sqrt[2 + 3*x]*Sqrt[3 + 5*x]) - (4839325048*Sqrt[1 - 2*x]*Sqrt[2 + 3*x])/(67110351*Sqrt[3 + 5*x]) + (4839325048*EllipticE[ArcSin[Sqrt[5/11]*Sqrt[1 - 2*x]], 33/35])/(9587193*Sqrt[35]) - (139423864*EllipticF[ArcSin[Sqrt[3/7]*Sqrt[1 - 2*x]], 35/33])/(9587193*Sqrt[33])}


{(2 + 3*x)^(13/2)/((1 - 2*x)^(5/2)*(3 + 5*x)^(5/2)), x, 12, (215*Sqrt[1 - 2*x]*(2 + 3*x)^(9/2))/(3993*(3 + 5*x)^(3/2)) - (73*(2 + 3*x)^(11/2))/(121*Sqrt[1 - 2*x]*(3 + 5*x)^(3/2)) + (2*(2 + 3*x)^(13/2))/(33*(1 - 2*x)^(3/2)*(3 + 5*x)^(3/2)) + (6503*Sqrt[1 - 2*x]*(2 + 3*x)^(7/2))/(219615*Sqrt[3 + 5*x]) - (371279941*Sqrt[1 - 2*x]*Sqrt[2 + 3*x]*Sqrt[3 + 5*x])/45753125 - (31887029*Sqrt[1 - 2*x]*(2 + 3*x)^(3/2)*Sqrt[3 + 5*x])/18301250 - (150812*Sqrt[1 - 2*x]*(2 + 3*x)^(5/2)*Sqrt[3 + 5*x])/366025 - (51601293223*Sqrt[7/5]*EllipticE[ArcSin[Sqrt[5/11]*Sqrt[1 - 2*x]], 33/35])/549037500 + (2598959587*EllipticF[ArcSin[Sqrt[3/7]*Sqrt[1 - 2*x]], 35/33])/(137259375*Sqrt[33])}
{(2 + 3*x)^(11/2)/((1 - 2*x)^(5/2)*(3 + 5*x)^(5/2)), x, 11, (149*Sqrt[1 - 2*x]*(2 + 3*x)^(7/2))/(3993*(3 + 5*x)^(3/2)) - (51*(2 + 3*x)^(9/2))/(121*Sqrt[1 - 2*x]*(3 + 5*x)^(3/2)) + (2*(2 + 3*x)^(11/2))/(33*(1 - 2*x)^(3/2)*(3 + 5*x)^(3/2)) + (865*Sqrt[1 - 2*x]*(2 + 3*x)^(5/2))/(43923*Sqrt[3 + 5*x]) - (5199979*Sqrt[1 - 2*x]*Sqrt[2 + 3*x]*Sqrt[3 + 5*x])/3660250 - (110519*Sqrt[1 - 2*x]*(2 + 3*x)^(3/2)*Sqrt[3 + 5*x])/366025 - (90397364*Sqrt[7/5]*EllipticE[ArcSin[Sqrt[5/11]*Sqrt[1 - 2*x]], 33/35])/5490375 + (36399853*EllipticF[ArcSin[Sqrt[3/7]*Sqrt[1 - 2*x]], 35/33])/(10980750*Sqrt[33])}
{(2 + 3*x)^(9/2)/((1 - 2*x)^(5/2)*(3 + 5*x)^(5/2)), x, 10, (83*Sqrt[1 - 2*x]*(2 + 3*x)^(5/2))/(3993*(3 + 5*x)^(3/2)) - (29*(2 + 3*x)^(7/2))/(121*Sqrt[1 - 2*x]*(3 + 5*x)^(3/2)) + (2*(2 + 3*x)^(9/2))/(33*(1 - 2*x)^(3/2)*(3 + 5*x)^(3/2)) + (2147*Sqrt[1 - 2*x]*(2 + 3*x)^(3/2))/(219615*Sqrt[3 + 5*x]) - (70226*Sqrt[1 - 2*x]*Sqrt[2 + 3*x]*Sqrt[3 + 5*x])/366025 - (4971289*Sqrt[7/5]*EllipticE[ArcSin[Sqrt[5/11]*Sqrt[1 - 2*x]], 33/35])/2196150 + (491582*EllipticF[ArcSin[Sqrt[3/7]*Sqrt[1 - 2*x]], 35/33])/(1098075*Sqrt[33])}
{(2 + 3*x)^(7/2)/((1 - 2*x)^(5/2)*(3 + 5*x)^(5/2)), x, 9, (17*Sqrt[1 - 2*x]*(2 + 3*x)^(3/2))/(3993*(3 + 5*x)^(3/2)) - (7*(2 + 3*x)^(5/2))/(121*Sqrt[1 - 2*x]*(3 + 5*x)^(3/2)) + (2*(2 + 3*x)^(7/2))/(33*(1 - 2*x)^(3/2)*(3 + 5*x)^(3/2)) - (31*Sqrt[1 - 2*x]*Sqrt[2 + 3*x])/(219615*Sqrt[3 + 5*x]) - (29933*Sqrt[7/5]*EllipticE[ArcSin[Sqrt[5/11]*Sqrt[1 - 2*x]], 33/35])/219615 - (217*EllipticF[ArcSin[Sqrt[3/7]*Sqrt[1 - 2*x]], 35/33])/(219615*Sqrt[33])}
{(2 + 3*x)^(5/2)/((1 - 2*x)^(5/2)*(3 + 5*x)^(5/2)), x, 9, (-49*Sqrt[1 - 2*x]*Sqrt[2 + 3*x])/(3993*(3 + 5*x)^(3/2)) + (15*(2 + 3*x)^(3/2))/(121*Sqrt[1 - 2*x]*(3 + 5*x)^(3/2)) + (2*(2 + 3*x)^(5/2))/(33*(1 - 2*x)^(3/2)*(3 + 5*x)^(3/2)) - (2209*Sqrt[1 - 2*x]*Sqrt[2 + 3*x])/(43923*Sqrt[3 + 5*x]) + (2209*Sqrt[7/5]*EllipticE[ArcSin[Sqrt[5/11]*Sqrt[1 - 2*x]], 33/35])/43923 - (4144*EllipticF[ArcSin[Sqrt[3/7]*Sqrt[1 - 2*x]], 35/33])/(43923*Sqrt[33])}
{(2 + 3*x)^(3/2)/((1 - 2*x)^(5/2)*(3 + 5*x)^(5/2)), x, 9, (37*Sqrt[2 + 3*x])/(121*Sqrt[1 - 2*x]*(3 + 5*x)^(3/2)) - (575*Sqrt[1 - 2*x]*Sqrt[2 + 3*x])/(3993*(3 + 5*x)^(3/2)) + (2*(2 + 3*x)^(3/2))/(33*(1 - 2*x)^(3/2)*(3 + 5*x)^(3/2)) - (2960*Sqrt[1 - 2*x]*Sqrt[2 + 3*x])/(43923*Sqrt[3 + 5*x]) + (592*Sqrt[35]*EllipticE[ArcSin[Sqrt[5/11]*Sqrt[1 - 2*x]], 33/35])/43923 - (8774*EllipticF[ArcSin[Sqrt[3/7]*Sqrt[1 - 2*x]], 35/33])/(43923*Sqrt[33])}
{Sqrt[2 + 3*x]/((1 - 2*x)^(5/2)*(3 + 5*x)^(5/2)), x, 9, (2*Sqrt[2 + 3*x])/(33*(1 - 2*x)^(3/2)*(3 + 5*x)^(3/2)) + (118*Sqrt[2 + 3*x])/(847*Sqrt[1 - 2*x]*(3 + 5*x)^(3/2)) - (2470*Sqrt[1 - 2*x]*Sqrt[2 + 3*x])/(27951*(3 + 5*x)^(3/2)) - (22090*Sqrt[1 - 2*x]*Sqrt[2 + 3*x])/(307461*Sqrt[3 + 5*x]) + (4418*Sqrt[5/7]*EllipticE[ArcSin[Sqrt[5/11]*Sqrt[1 - 2*x]], 33/35])/43923 - (5920*EllipticF[ArcSin[Sqrt[3/7]*Sqrt[1 - 2*x]], 35/33])/(43923*Sqrt[33])}
{1/((1 - 2*x)^(5/2)*Sqrt[2 + 3*x]*(3 + 5*x)^(5/2)), x, 9, (4*Sqrt[2 + 3*x])/(231*(1 - 2*x)^(3/2)*(3 + 5*x)^(3/2)) + (368*Sqrt[2 + 3*x])/(5929*Sqrt[1 - 2*x]*(3 + 5*x)^(3/2)) - (18470*Sqrt[1 - 2*x]*Sqrt[2 + 3*x])/(195657*(3 + 5*x)^(3/2)) + (598660*Sqrt[1 - 2*x]*Sqrt[2 + 3*x])/(2152227*Sqrt[3 + 5*x]) - (119732*Sqrt[5/7]*EllipticE[ArcSin[Sqrt[5/11]*Sqrt[1 - 2*x]], 33/35])/307461 - (620*EllipticF[ArcSin[Sqrt[3/7]*Sqrt[1 - 2*x]], 35/33])/(307461*Sqrt[33])}
{1/((1 - 2*x)^(5/2)*(2 + 3*x)^(3/2)*(3 + 5*x)^(5/2)), x, 10, 4/(231*(1 - 2*x)^(3/2)*Sqrt[2 + 3*x]*(3 + 5*x)^(3/2)) + 456/(5929*Sqrt[1 - 2*x]*Sqrt[2 + 3*x]*(3 + 5*x)^(3/2)) + (5034*Sqrt[1 - 2*x])/(41503*Sqrt[2 + 3*x]*(3 + 5*x)^(3/2)) - (1523260*Sqrt[1 - 2*x]*Sqrt[2 + 3*x])/(1369599*(3 + 5*x)^(3/2)) + (99425780*Sqrt[1 - 2*x]*Sqrt[2 + 3*x])/(15065589*Sqrt[3 + 5*x]) - (19885156*Sqrt[5/7]*EllipticE[ArcSin[Sqrt[5/11]*Sqrt[1 - 2*x]], 33/35])/2152227 + (2809040*EllipticF[ArcSin[Sqrt[3/7]*Sqrt[1 - 2*x]], 35/33])/(2152227*Sqrt[33])}
{1/((1 - 2*x)^(5/2)*(2 + 3*x)^(5/2)*(3 + 5*x)^(5/2)), x, 11, 4/(231*(1 - 2*x)^(3/2)*(2 + 3*x)^(3/2)*(3 + 5*x)^(3/2)) + 544/(5929*Sqrt[1 - 2*x]*(2 + 3*x)^(3/2)*(3 + 5*x)^(3/2)) + (414*Sqrt[1 - 2*x])/(41503*(2 + 3*x)^(3/2)*(3 + 5*x)^(3/2)) + (488436*Sqrt[1 - 2*x])/(290521*Sqrt[2 + 3*x]*(3 + 5*x)^(3/2)) - (108842540*Sqrt[1 - 2*x]*Sqrt[2 + 3*x])/(9587193*(3 + 5*x)^(3/2)) + (7231789120*Sqrt[1 - 2*x]*Sqrt[2 + 3*x])/(105459123*Sqrt[3 + 5*x]) - (1446357824*Sqrt[5/7]*EllipticE[ArcSin[Sqrt[5/11]*Sqrt[1 - 2*x]], 33/35])/15065589 + (207999160*EllipticF[ArcSin[Sqrt[3/7]*Sqrt[1 - 2*x]], 35/33])/(15065589*Sqrt[33])}
{1/((1 - 2*x)^(5/2)*(2 + 3*x)^(7/2)*(3 + 5*x)^(5/2)), x, 12, 4/(231*(1 - 2*x)^(3/2)*(2 + 3*x)^(5/2)*(3 + 5*x)^(3/2)) + 632/(5929*Sqrt[1 - 2*x]*(2 + 3*x)^(5/2)*(3 + 5*x)^(3/2)) - (3606*Sqrt[1 - 2*x])/(207515*(2 + 3*x)^(5/2)*(3 + 5*x)^(3/2)) + (649224*Sqrt[1 - 2*x])/(1452605*(2 + 3*x)^(3/2)*(3 + 5*x)^(3/2)) + (140700876*Sqrt[1 - 2*x])/(10168235*Sqrt[2 + 3*x]*(3 + 5*x)^(3/2)) - (6208896328*Sqrt[1 - 2*x]*Sqrt[2 + 3*x])/(67110351*(3 + 5*x)^(3/2)) + (412810345784*Sqrt[1 - 2*x]*Sqrt[2 + 3*x])/(738213861*Sqrt[3 + 5*x]) - (412810345784*EllipticE[ArcSin[Sqrt[5/11]*Sqrt[1 - 2*x]], 33/35])/(105459123*Sqrt[35]) + (11880958112*EllipticF[ArcSin[Sqrt[3/7]*Sqrt[1 - 2*x]], 35/33])/(105459123*Sqrt[33])}


(* ::Title:: *)
(*Integrands of the form x^m (a+b x)^n (c+d x)^p (e+f x)^q*)


(* ::Section::Closed:: *)
(*Integrands of the form x^m (a+b x)^n (c+d x)^p (e+f x)^q*)


{((a + b*x)*(A + B*x)*Sqrt[c + d*x])/x, x, 4, 2*a*A*Sqrt[c + d*x] - (2*(2*b*B*c - 5*A*b*d - 2*a*B*d)*(c + d*x)^(3/2))/(15*d^2) + (2*B*(a + b*x)*(c + d*x)^(3/2))/(5*d) - 2*a*A*Sqrt[c]*ArcTanh[Sqrt[c + d*x]/Sqrt[c]]}
{(Sqrt[a + b*x]*(A + B*x)*(c + d*x))/x, x, 4, 2*A*c*Sqrt[a + b*x] + (2*(5*b*B*c + 2*A*b*d - 2*a*B*d)*(a + b*x)^(3/2))/(15*b^2) + (2*d*(a + b*x)^(3/2)*(A + B*x))/(5*b) - 2*Sqrt[a]*A*c*ArcTanh[Sqrt[a + b*x]/Sqrt[a]]}


{x^3*(1 + a*x)/(Sqrt[a*x]*Sqrt[1 - a*x]), x, 13, -((75*Sqrt[a*x - a^2*x^2])/(64*a^4)) - (25*x*Sqrt[a*x - a^2*x^2])/(32*a^3) - (5*x^2*Sqrt[a*x - a^2*x^2])/(8*a^2) - (x^3*Sqrt[a*x - a^2*x^2])/(4*a) - (75*ArcSin[1 - 2*a*x])/(128*a^4)}
{x^2*(1 + a*x)/(Sqrt[a*x]*Sqrt[1 - a*x]), x, 11, -((11*Sqrt[a*x - a^2*x^2])/(8*a^3)) - (11*x*Sqrt[a*x - a^2*x^2])/(12*a^2) - (x^2*Sqrt[a*x - a^2*x^2])/(3*a) - (11*ArcSin[1 - 2*a*x])/(16*a^3)}
{x^1*(1 + a*x)/(Sqrt[a*x]*Sqrt[1 - a*x]), x, 3, -((5*Sqrt[a*x]*Sqrt[1 - a*x])/(4*a^2)) - (Sqrt[a*x]*Sqrt[1 - a*x]*(1 + a*x))/(2*a^2) - (7*ArcSin[1 - 2*a*x])/(8*a^2)}
{x^0*(1 + a*x)/(Sqrt[a*x]*Sqrt[1 - a*x]), x, 2, -((Sqrt[a*x]*Sqrt[1 - a*x])/a) - (3*ArcSin[1 - 2*a*x])/(2*a)}
{(1 + a*x)/(x^1*Sqrt[a*x]*Sqrt[1 - a*x]), x, 6, -((2*Sqrt[a*x - a^2*x^2])/(a*x)) - ArcSin[1 - 2*a*x]}
{(1 + a*x)/(x^2*Sqrt[a*x]*Sqrt[1 - a*x]), x, 7, -((2*Sqrt[a*x - a^2*x^2])/(3*a*x^2)) - (10*Sqrt[a*x - a^2*x^2])/(3*x)}
{(1 + a*x)/(x^3*Sqrt[a*x]*Sqrt[1 - a*x]), x, 9, -((2*Sqrt[a*x - a^2*x^2])/(5*a*x^3)) - (6*Sqrt[a*x - a^2*x^2])/(5*x^2) - (12*a*Sqrt[a*x - a^2*x^2])/(5*x)}
{(1 + a*x)/(x^4*Sqrt[a*x]*Sqrt[1 - a*x]), x, 11, -((2*Sqrt[a*x - a^2*x^2])/(7*a*x^4)) - (26*Sqrt[a*x - a^2*x^2])/(35*x^3) - (104*a*Sqrt[a*x - a^2*x^2])/(105*x^2) - (208*a^2*Sqrt[a*x - a^2*x^2])/(105*x)}
{(1 + a*x)/(x^5*Sqrt[a*x]*Sqrt[1 - a*x]), x, 13, -((2*Sqrt[a*x - a^2*x^2])/(9*a*x^5)) - (34*Sqrt[a*x - a^2*x^2])/(63*x^4) - (68*a*Sqrt[a*x - a^2*x^2])/(105*x^3) - (272*a^2*Sqrt[a*x - a^2*x^2])/(315*x^2) - (544*a^3*Sqrt[a*x - a^2*x^2])/(315*x)}


(* ::Section::Closed:: *)
(*Integrands of the form x^m (a+b x)^n (c+d x)^p (e+f x)^q with n symbolic*)


{x^m*(e + f*x)^n/((a + b*x)*(c + d*x)), x, 4, (b*x^(1 + m)*(e + f*x)^n*AppellF1[1 + m, 1, -n, 2 + m, -((b*x)/a), -((f*x)/e)])/(((e + f*x)/e)^n*(a*(b*c - a*d)*(1 + m))) - (d*x^(1 + m)*(e + f*x)^n*AppellF1[1 + m, 1, -n, 2 + m, -((d*x)/c), -((f*x)/e)])/(((e + f*x)/e)^n*(c*(b*c - a*d)*(1 + m)))}

{x^4*(e + f*x)^n/((a + b*x)*(c + d*x)), x, 8, (e^2*(e + f*x)^(1 + n))/(b*d*f^3*(1 + n)) + ((b*c + a*d)*e*(e + f*x)^(1 + n))/(b^2*d^2*f^2*(1 + n)) + ((b^2*c^2 + a*b*c*d + a^2*d^2)*(e + f*x)^(1 + n))/(b^3*d^3*f*(1 + n)) - (2*e*(e + f*x)^(2 + n))/(b*d*f^3*(2 + n)) - ((b*c + a*d)*(e + f*x)^(2 + n))/(b^2*d^2*f^2*(2 + n)) + (e + f*x)^(3 + n)/(b*d*f^3*(3 + n)) - (a^4*(e + f*x)^(1 + n)*Hypergeometric2F1[1, 1 + n, 2 + n, (b*(e + f*x))/(b*e - a*f)])/(b^3*(b*c - a*d)*(b*e - a*f)*(1 + n)) + (c^4*(e + f*x)^(1 + n)*Hypergeometric2F1[1, 1 + n, 2 + n, (d*(e + f*x))/(d*e - c*f)])/(d^3*(b*c - a*d)*(d*e - c*f)*(1 + n))}
{x^3*(e + f*x)^n/((a + b*x)*(c + d*x)), x, 6, -((e*(e + f*x)^(1 + n))/(b*d*f^2*(1 + n))) - ((b*c + a*d)*(e + f*x)^(1 + n))/(b^2*d^2*f*(1 + n)) + (e + f*x)^(2 + n)/(b*d*f^2*(2 + n)) + (a^3*(e + f*x)^(1 + n)*Hypergeometric2F1[1, 1 + n, 2 + n, (b*(e + f*x))/(b*e - a*f)])/(b^2*(b*c - a*d)*(b*e - a*f)*(1 + n)) - (c^3*(e + f*x)^(1 + n)*Hypergeometric2F1[1, 1 + n, 2 + n, (d*(e + f*x))/(d*e - c*f)])/(d^2*(b*c - a*d)*(d*e - c*f)*(1 + n))}
{x^2*(e + f*x)^n/((a + b*x)*(c + d*x)), x, 4, (e + f*x)^(1 + n)/(b*d*f*(1 + n)) - (a^2*(e + f*x)^(1 + n)*Hypergeometric2F1[1, 1 + n, 2 + n, (b*(e + f*x))/(b*e - a*f)])/(b*(b*c - a*d)*(b*e - a*f)*(1 + n)) + (c^2*(e + f*x)^(1 + n)*Hypergeometric2F1[1, 1 + n, 2 + n, (d*(e + f*x))/(d*e - c*f)])/(d*(b*c - a*d)*(d*e - c*f)*(1 + n))}
{x^1*(e + f*x)^n/((a + b*x)*(c + d*x)), x, 3, (a*(e + f*x)^(1 + n)*Hypergeometric2F1[1, 1 + n, 2 + n, (b*(e + f*x))/(b*e - a*f)])/((b*c - a*d)*(b*e - a*f)*(1 + n)) - (c*(e + f*x)^(1 + n)*Hypergeometric2F1[1, 1 + n, 2 + n, (d*(e + f*x))/(d*e - c*f)])/((b*c - a*d)*(d*e - c*f)*(1 + n))}
{x^0*(e + f*x)^n/((a + b*x)*(c + d*x)), x, 3, -((b*(e + f*x)^(1 + n)*Hypergeometric2F1[1, 1 + n, 2 + n, (b*(e + f*x))/(b*e - a*f)])/((b*c - a*d)*(b*e - a*f)*(1 + n))) + (d*(e + f*x)^(1 + n)*Hypergeometric2F1[1, 1 + n, 2 + n, (d*(e + f*x))/(d*e - c*f)])/((b*c - a*d)*(d*e - c*f)*(1 + n))}
{(e + f*x)^n/(x^1*(a + b*x)*(c + d*x)), x, 5, -(((e + f*x)^(1 + n)*Hypergeometric2F1[1, 1 + n, 2 + n, (e + f*x)/e])/(a*c*e*(1 + n))) + (b^2*(e + f*x)^(1 + n)*Hypergeometric2F1[1, 1 + n, 2 + n, (b*(e + f*x))/(b*e - a*f)])/(a*(b*c - a*d)*(b*e - a*f)*(1 + n)) - (d^2*(e + f*x)^(1 + n)*Hypergeometric2F1[1, 1 + n, 2 + n, (d*(e + f*x))/(d*e - c*f)])/(c*(b*c - a*d)*(d*e - c*f)*(1 + n))}
{(e + f*x)^n/(x^2*(a + b*x)*(c + d*x)), x, 7, -((e + f*x)^(1 + n)/(a*c*e*x)) + ((b*c + a*d)*(e + f*x)^(1 + n)*Hypergeometric2F1[1, 1 + n, 2 + n, (e + f*x)/e])/(a^2*c^2*e*(1 + n)) - (f*n*(e + f*x)^(1 + n)*Hypergeometric2F1[1, 1 + n, 2 + n, (e + f*x)/e])/(a*c*e^2*(1 + n)) - (b^3*(e + f*x)^(1 + n)*Hypergeometric2F1[1, 1 + n, 2 + n, (b*(e + f*x))/(b*e - a*f)])/(a^2*(b*c - a*d)*(b*e - a*f)*(1 + n)) + (d^3*(e + f*x)^(1 + n)*Hypergeometric2F1[1, 1 + n, 2 + n, (d*(e + f*x))/(d*e - c*f)])/(c^2*(b*c - a*d)*(d*e - c*f)*(1 + n))}


(* ::Title:: *)
(*Integrands of the form (a+b x)^m (c+d x)^n (e+f x)^p (g+h x)^q*)


(* ::Section::Closed:: *)
(*Integrands of the form (a+b x)^m (c+d x)^n (e+f x)^p (g+h x)^q*)


{(a+b*x)*(c+d*x)*(e+f*x)*(g+h*x), x, 2, a*c*e*g*x + (1/2)*(b*c*e*g + a*(d*e*g + c*f*g + c*e*h))*x^2 + (1/3)*(b*(d*e*g + c*f*g + c*e*h) + a*(d*f*g + d*e*h + c*f*h))*x^3 + (1/4)*(a*d*f*h + b*(d*f*g + d*e*h + c*f*h))*x^4 + (1/5)*b*d*f*h*x^5}
{(a+b*x)*(c+d*x)*(e+f*x)/(g+h*x), x, 2, ((b*(d*g - c*h)*(f*g - e*h) - a*h*(d*f*g - d*e*h - c*f*h))*x)/h^3 + ((a*d*f*h - b*(d*f*g - d*e*h - c*f*h))*x^2)/(2*h^2) + (b*d*f*x^3)/(3*h) - ((b*g - a*h)*(d*g - c*h)*(f*g - e*h)*Log[g + h*x])/h^4}
{(a+b*x)*(c+d*x)/((e+f*x)*(g+h*x)), x, 2, (b*d*x)/(f*h) + ((b*e - a*f)*(d*e - c*f)*Log[e + f*x])/(f^2*(f*g - e*h)) - ((b*g - a*h)*(d*g - c*h)*Log[g + h*x])/(h^2*(f*g - e*h))}
{(a+b*x)/((c+d*x)*(e+f*x)*(g+h*x)), x, 2, -(((b*c - a*d)*Log[c + d*x])/((d*e - c*f)*(d*g - c*h))) + ((b*e - a*f)*Log[e + f*x])/((d*e - c*f)*(f*g - e*h)) - ((b*g - a*h)*Log[g + h*x])/((d*g - c*h)*(f*g - e*h))}
{1/((a+b*x)*(c+d*x)*(e+f*x)*(g+h*x)), x, 2, (b^2*Log[a + b*x])/((b*c - a*d)*(b*e - a*f)*(b*g - a*h)) - (d^2*Log[c + d*x])/((b*c - a*d)*(d*e - c*f)*(d*g - c*h)) + (f^2*Log[e + f*x])/((b*e - a*f)*(d*e - c*f)*(f*g - e*h)) - (h^2*Log[g + h*x])/((b*g - a*h)*(d*g - c*h)*(f*g - e*h))}


{(a + b*x)^m*(c + d*x)*(e + f*x)*(g + h*x), x, 2, ((b*c - a*d)*(b*e - a*f)*(b*g - a*h)*(a + b*x)^(1 + m))/(b^4*(1 + m)) + ((3*a^2*d*f*h + b^2*(d*e*g + c*f*g + c*e*h) - 2*a*b*(d*f*g + d*e*h + c*f*h))*(a + b*x)^(2 + m))/(b^4*(2 + m)) - ((3*a*d*f*h - b*(d*f*g + d*e*h + c*f*h))*(a + b*x)^(3 + m))/(b^4*(3 + m)) + (d*f*h*(a + b*x)^(4 + m))/(b^4*(4 + m))}
{(a + b*x)^m*(c + d*x)*(e + f*x)/(g + h*x), x, 3, ((b*d*e*h*(2 + m) + f*(b*c*h - d*(a*h + b*g*(2 + m))))*(a + b*x)^(1 + m))/(b^2*h^2*(1 + m)*(2 + m)) + (f*(a + b*x)^(1 + m)*(c + d*x))/(b*h*(2 + m)) + ((d*g - c*h)*(f*g - e*h)*(a + b*x)^(1 + m)*Hypergeometric2F1[1, 1 + m, 2 + m, -((h*(a + b*x))/(b*g - a*h))])/(h^2*(b*g - a*h)*(1 + m))}
{(a + b*x)^m*(c + d*x)/((e + f*x)*(g + h*x)), x, 3, -(((d*e - c*f)*(a + b*x)^(1 + m)*Hypergeometric2F1[1, 1 + m, 2 + m, -((f*(a + b*x))/(b*e - a*f))])/((b*e - a*f)*(f*g - e*h)*(1 + m))) + ((d*g - c*h)*(a + b*x)^(1 + m)*Hypergeometric2F1[1, 1 + m, 2 + m, -((h*(a + b*x))/(b*g - a*h))])/((b*g - a*h)*(f*g - e*h)*(1 + m))}
{(a + b*x)^m/((c + d*x)*(e + f*x)*(g + h*x)), x, 5, (d^2*(a + b*x)^(1 + m)*Hypergeometric2F1[1, 1 + m, 2 + m, -((d*(a + b*x))/(b*c - a*d))])/((b*c - a*d)*(d*e - c*f)*(d*g - c*h)*(1 + m)) - (f^2*(a + b*x)^(1 + m)*Hypergeometric2F1[1, 1 + m, 2 + m, -((f*(a + b*x))/(b*e - a*f))])/((b*e - a*f)*(d*e - c*f)*(f*g - e*h)*(1 + m)) + (h^2*(a + b*x)^(1 + m)*Hypergeometric2F1[1, 1 + m, 2 + m, -((h*(a + b*x))/(b*g - a*h))])/((b*g - a*h)*(d*g - c*h)*(f*g - e*h)*(1 + m))}


{x/((1 + x)*(2 + x)*(3 + x)), x, 2, (-(1/2))*Log[1 + x] + 2*Log[2 + x] - (3/2)*Log[3 + x]}


{(-x^2 + x^3)/((-6 + x)*(3 + 5*x)^3), x, 3, -(12/(1375*(3 + 5*x)^2)) + 201/(15125*(3 + 5*x)) + (20*Log[6 - x])/3993 + (1493*Log[3 + 5*x])/499125}
