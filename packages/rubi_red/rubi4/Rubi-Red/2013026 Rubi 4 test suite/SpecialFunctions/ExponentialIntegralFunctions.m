(* ::Package:: *)

(* ::Title:: *)
(*Integration Problems Involving Exponential Integral Functions*)


(* ::Section:: *)
(*Exponential integral En function*)


(* ::Section:: *)
(*Exponential integral Ei function*)


(* ::Subsection::Closed:: *)
(*Integrands of the form x^m ExpIntegralEi[b x]^n*)


{ExpIntegralEi[b*x]*x^m, x, 3, (x^(1 + m)*ExpIntegralEi[b*x])/(1 + m) - (x^m*Gamma[1 + m, (-b)*x])/(((-b)*x)^m*(b*(1 + m)))}

{ExpIntegralEi[b*x]*x^3, x, 6, (3*E^(b*x))/(2*b^4) - (3*E^(b*x)*x)/(2*b^3) + (3*E^(b*x)*x^2)/(4*b^2) - (E^(b*x)*x^3)/(4*b) + (1/4)*x^4*ExpIntegralEi[b*x]}
{ExpIntegralEi[b*x]*x^2, x, 5, -((2*E^(b*x))/(3*b^3)) + (2*E^(b*x)*x)/(3*b^2) - (E^(b*x)*x^2)/(3*b) + (1/3)*x^3*ExpIntegralEi[b*x]}
{ExpIntegralEi[b*x]*x^1, x, 4, E^(b*x)/(2*b^2) - (E^(b*x)*x)/(2*b) + (1/2)*x^2*ExpIntegralEi[b*x]}
{ExpIntegralEi[b*x]*x^0, x, 1, -(E^(b*x)/b) + ((b*x)*ExpIntegralEi[b*x])/b}
{ExpIntegralEi[b*x]/x^1, x, 0, Int[ExpIntegralEi[b*x]/x, x]}
{ExpIntegralEi[b*x]/x^2, x, 4, -(E^(b*x)/x) + b*ExpIntegralEi[b*x] - ExpIntegralEi[b*x]/x}
{ExpIntegralEi[b*x]/x^3, x, 5, -(E^(b*x)/(4*x^2)) - (b*E^(b*x))/(4*x) + (1/4)*b^2*ExpIntegralEi[b*x] - ExpIntegralEi[b*x]/(2*x^2)}
{ExpIntegralEi[b*x]/x^4, x, 6, -(E^(b*x)/(9*x^3)) - (b*E^(b*x))/(18*x^2) - (b^2*E^(b*x))/(18*x) + (1/18)*b^3*ExpIntegralEi[b*x] - ExpIntegralEi[b*x]/(3*x^3)}


{ExpIntegralEi[b*x]^2*x^m, x, 0, Int[x^m*ExpIntegralEi[b*x]^2, x]}

{ExpIntegralEi[b*x]^2*x^3, x, 16, (2*E^(2*b*x))/b^4 - (E^(2*b*x)*x)/b^3 + (E^(2*b*x)*x^2)/(4*b^2) + (3*E^(b*x)*ExpIntegralEi[b*x])/b^4 - (3*E^(b*x)*x*ExpIntegralEi[b*x])/b^3 + (3*E^(b*x)*x^2*ExpIntegralEi[b*x])/(2*b^2) - (E^(b*x)*x^3*ExpIntegralEi[b*x])/(2*b) + (1/4)*x^4*ExpIntegralEi[b*x]^2 - (3*ExpIntegralEi[2*b*x])/b^4}
{ExpIntegralEi[b*x]^2*x^2, x, 11, -((5*E^(2*b*x))/(6*b^3)) + (E^(2*b*x)*x)/(3*b^2) - (4*E^(b*x)*ExpIntegralEi[b*x])/(3*b^3) + (4*E^(b*x)*x*ExpIntegralEi[b*x])/(3*b^2) - (2*E^(b*x)*x^2*ExpIntegralEi[b*x])/(3*b) + (1/3)*x^3*ExpIntegralEi[b*x]^2 + (4*ExpIntegralEi[2*b*x])/(3*b^3)}
{ExpIntegralEi[b*x]^2*x^1, x, 7, E^(2*b*x)/(2*b^2) + (E^(b*x)*ExpIntegralEi[b*x])/b^2 - (E^(b*x)*x*ExpIntegralEi[b*x])/b + (1/2)*x^2*ExpIntegralEi[b*x]^2 - ExpIntegralEi[2*b*x]/b^2}
{ExpIntegralEi[b*x]^2*x^0, x, 4, -((2*E^(b*x)*ExpIntegralEi[b*x])/b) + x*ExpIntegralEi[b*x]^2 + (2*ExpIntegralEi[2*b*x])/b}
{ExpIntegralEi[b*x]^2/x^1, x, 0, Int[ExpIntegralEi[b*x]^2/x, x]}
{ExpIntegralEi[b*x]^2/x^2, x, 0, Int[ExpIntegralEi[b*x]^2/x^2, x]}
{ExpIntegralEi[b*x]^2/x^3, x, 0, Int[ExpIntegralEi[b*x]^2/x^3, x]}


(* ::Subsection::Closed:: *)
(*Integrands of the form x^m ExpIntegralEi[a+b x]^n*)


{x^m*ExpIntegralEi[a + b*x], x, 4, (x^(1 + m)*ExpIntegralEi[a + b*x])/(1 + m) - (E^a*x^m*Gamma[1 + m, (-b)*x])/(((-b)*x)^m*(b*(1 + m))) + (a*Int[(E^(a + b*x)*x^m)/(a + b*x), x])/(1 + m)}

{x^3*ExpIntegralEi[a + b*x], x, 14, (3*E^(a + b*x))/(2*b^4) + (a*E^(a + b*x))/(2*b^4) + (a^2*E^(a + b*x))/(4*b^4) + (a^3*E^(a + b*x))/(4*b^4) - (3*E^(a + b*x)*x)/(2*b^3) - (a*E^(a + b*x)*x)/(2*b^3) - (a^2*E^(a + b*x)*x)/(4*b^3) + (3*E^(a + b*x)*x^2)/(4*b^2) + (a*E^(a + b*x)*x^2)/(4*b^2) - (E^(a + b*x)*x^3)/(4*b) - (a^4*ExpIntegralEi[a + b*x])/(4*b^4) + (1/4)*x^4*ExpIntegralEi[a + b*x]}
{x^2*ExpIntegralEi[a + b*x], x, 10, -((2*E^(a + b*x))/(3*b^3)) - (a*E^(a + b*x))/(3*b^3) - (a^2*E^(a + b*x))/(3*b^3) + (2*E^(a + b*x)*x)/(3*b^2) + (a*E^(a + b*x)*x)/(3*b^2) - (E^(a + b*x)*x^2)/(3*b) + (a^3*ExpIntegralEi[a + b*x])/(3*b^3) + (1/3)*x^3*ExpIntegralEi[a + b*x]}
{x^1*ExpIntegralEi[a + b*x], x, 7, E^(a + b*x)/(2*b^2) + (a*E^(a + b*x))/(2*b^2) - (E^(a + b*x)*x)/(2*b) - (a^2*ExpIntegralEi[a + b*x])/(2*b^2) + (1/2)*x^2*ExpIntegralEi[a + b*x]}
{x^0*ExpIntegralEi[a + b*x], x, 1, -(E^(a + b*x)/b) + ((a + b*x)*ExpIntegralEi[a + b*x])/b}
{ExpIntegralEi[a + b*x]/x^1, x, 0, Int[ExpIntegralEi[a + b*x]/x, x]}
{ExpIntegralEi[a + b*x]/x^2, x, 5, (b*E^a*ExpIntegralEi[b*x])/a - (b*ExpIntegralEi[a + b*x])/a - ExpIntegralEi[a + b*x]/x}
{ExpIntegralEi[a + b*x]/x^3, x, 7, -((b*E^(a + b*x))/(2*a*x)) - (b^2*E^a*ExpIntegralEi[b*x])/(2*a^2) + (b^2*E^a*ExpIntegralEi[b*x])/(2*a) + (b^2*ExpIntegralEi[a + b*x])/(2*a^2) - ExpIntegralEi[a + b*x]/(2*x^2)}


{x^m*ExpIntegralEi[a + b*x]^2, x, 0, Int[x^m*ExpIntegralEi[a + b*x]^2, x]}

(* {x^3*ExpIntegralEi[a + b*x]^2, x, 51, (2*E^(2*a + 2*b*x))/b^4 + (3*a*E^(2*a + 2*b*x))/(2*b^4) + (3*a^2*E^(2*a + 2*b*x))/(4*b^4) - (E^(2*a + 2*b*x)*x)/b^3 - (a*E^(2*a + 2*b*x)*x)/(2*b^3) + (E^(2*a + 2*b*x)*x^2)/(4*b^2) + (3*E^(a + b*x)*ExpIntegralEi[a + b*x])/b^4 + (a*E^(a + b*x)*ExpIntegralEi[a + b*x])/b^4 + (a^2*E^(a + b*x)*ExpIntegralEi[a + b*x])/(2*b^4) + (a^3*E^(a + b*x)*ExpIntegralEi[a + b*x])/(2*b^4) - (3*E^(a + b*x)*x*ExpIntegralEi[a + b*x])/b^3 - (a*E^(a + b*x)*x*ExpIntegralEi[a + b*x])/b^3 - (a^2*E^(a + b*x)*x*ExpIntegralEi[a + b*x])/(2*b^3) + (3*E^(a + b*x)*x^2*ExpIntegralEi[a + b*x])/(2*b^2) + (a*E^(a + b*x)*x^2*ExpIntegralEi[a + b*x])/(2*b^2) - (E^(a + b*x)*x^3*ExpIntegralEi[a + b*x])/(2*b) + (a^3*x*ExpIntegralEi[a + b*x]^2)/(4*b^3) + (1/4)*x^4*ExpIntegralEi[a + b*x]^2 - (a^3*(a + b*x)*ExpIntegralEi[a + b*x]^2)/(4*b^4) - (3*ExpIntegralEi[2*a + 2*b*x])/b^4 - (4*a*ExpIntegralEi[2*a + 2*b*x])/b^4 - (3*a^2*ExpIntegralEi[2*a + 2*b*x])/b^4 - (2*a^3*ExpIntegralEi[2*a + 2*b*x])/b^4} *)
{x^2*ExpIntegralEi[a + b*x]^2, x, 26, -((5*E^(2*a + 2*b*x))/(6*b^3)) - (2*a*E^(2*a + 2*b*x))/(3*b^3) + (E^(2*a + 2*b*x)*x)/(3*b^2) - (4*E^(a + b*x)*ExpIntegralEi[a + b*x])/(3*b^3) - (2*a*E^(a + b*x)*ExpIntegralEi[a + b*x])/(3*b^3) - (2*a^2*E^(a + b*x)*ExpIntegralEi[a + b*x])/(3*b^3) + (4*E^(a + b*x)*x*ExpIntegralEi[a + b*x])/(3*b^2) + (2*a*E^(a + b*x)*x*ExpIntegralEi[a + b*x])/(3*b^2) - (2*E^(a + b*x)*x^2*ExpIntegralEi[a + b*x])/(3*b) - (a^2*x*ExpIntegralEi[a + b*x]^2)/(3*b^2) + (1/3)*x^3*ExpIntegralEi[a + b*x]^2 + (a^2*(a + b*x)*ExpIntegralEi[a + b*x]^2)/(3*b^3) + (4*ExpIntegralEi[2*(a + b*x)])/(3*b^3) + (2*a*ExpIntegralEi[2*(a + b*x)])/b^3 + (2*a^2*ExpIntegralEi[2*(a + b*x)])/b^3}
{x^1*ExpIntegralEi[a + b*x]^2, x, 11, E^(2*a + 2*b*x)/(2*b^2) + (E^(a + b*x)*ExpIntegralEi[a + b*x])/b^2 + (a*E^(a + b*x)*ExpIntegralEi[a + b*x])/b^2 - (E^(a + b*x)*x*ExpIntegralEi[a + b*x])/b + (a*x*ExpIntegralEi[a + b*x]^2)/(2*b) + (1/2)*x^2*ExpIntegralEi[a + b*x]^2 - (a*(a + b*x)*ExpIntegralEi[a + b*x]^2)/(2*b^2) - ExpIntegralEi[2*(a + b*x)]/b^2 - (2*a*ExpIntegralEi[2*(a + b*x)])/b^2}
{x^0*ExpIntegralEi[a + b*x]^2, x, 3, -((2*E^(a + b*x)*ExpIntegralEi[a + b*x])/b) + ((a + b*x)*ExpIntegralEi[a + b*x]^2)/b + (2*ExpIntegralEi[2*(a + b*x)])/b}
{ExpIntegralEi[a + b*x]^2/x^1, x, 0, Int[ExpIntegralEi[a + b*x]^2/x, x]}
{ExpIntegralEi[a + b*x]^2/x^2, x, 0, Int[ExpIntegralEi[a + b*x]^2/x^2, x]}
{ExpIntegralEi[a + b*x]^2/x^3, x, 0, Int[ExpIntegralEi[a + b*x]^2/x^3, x]}


{x^m*ExpIntegralEi[a + b*x]^3, x, 0, Int[x^m*ExpIntegralEi[a + b*x]^3, x]}

{x^3*ExpIntegralEi[a + b*x]^3, x, 0, Int[x^3*ExpIntegralEi[a + b*x]^3, x]}
{x^2*ExpIntegralEi[a + b*x]^3, x, 0, Int[x^2*ExpIntegralEi[a + b*x]^3, x]}
{x^1*ExpIntegralEi[a + b*x]^3, x, 0, Int[x*ExpIntegralEi[a + b*x]^3, x]}
{x^0*ExpIntegralEi[a + b*x]^3, x, 1, Subst[Int[ExpIntegralEi[x]^3, x], x, a + b*x]/b}
{ExpIntegralEi[a + b*x]^3/x^1, x, 0, Int[ExpIntegralEi[a + b*x]^3/x, x]}
{ExpIntegralEi[a + b*x]^3/x^2, x, 0, Int[ExpIntegralEi[a + b*x]^3/x^2, x]}
{ExpIntegralEi[a + b*x]^3/x^3, x, 0, Int[ExpIntegralEi[a + b*x]^3/x^3, x]}


(* ::Subsection::Closed:: *)
(*Integrands of the form x^m E^(b x) ExpIntegralEi[b x]^n*)


(* Integrands of x^m*E^(b*x)*ExpIntegralEi[b*x] where m is an integer *)
{E^(b*x)*ExpIntegralEi[b*x]/x^3, x, 10, -(E^(2*b*x)/(4*x^2)) - (b*E^(2*b*x))/x - (E^(b*x)*ExpIntegralEi[b*x])/(2*x^2) - (b*E^(b*x)*ExpIntegralEi[b*x])/(2*x) + (1/4)*b^2*ExpIntegralEi[b*x]^2 + 2*b^2*ExpIntegralEi[2*b*x]}
{E^(b*x)*ExpIntegralEi[b*x]/x^2, x, 5, -(E^(2*b*x)/x) - (E^(b*x)*ExpIntegralEi[b*x])/x + (1/2)*b*ExpIntegralEi[b*x]^2 + 2*b*ExpIntegralEi[2*b*x]}
{E^(b*x)*ExpIntegralEi[b*x]/x, x, 1, (1/2)*ExpIntegralEi[b*x]^2}
{E^(b*x)*ExpIntegralEi[b*x], x, 3, (E^(b*x)*ExpIntegralEi[b*x])/b - ExpIntegralEi[2*b*x]/b}
{x*E^(b*x)*ExpIntegralEi[b*x], x, 6, -(E^(2*b*x)/(2*b^2)) - (E^(b*x)*ExpIntegralEi[b*x])/b^2 + (E^(b*x)*x*ExpIntegralEi[b*x])/b + ExpIntegralEi[2*b*x]/b^2}
{x^2*E^(b*x)*ExpIntegralEi[b*x], x, 10, (5*E^(2*b*x))/(4*b^3) - (E^(2*b*x)*x)/(2*b^2) + (2*E^(b*x)*ExpIntegralEi[b*x])/b^3 - (2*E^(b*x)*x*ExpIntegralEi[b*x])/b^2 + (E^(b*x)*x^2*ExpIntegralEi[b*x])/b - (2*ExpIntegralEi[2*b*x])/b^3}
{x^3*E^(b*x)*ExpIntegralEi[b*x], x, 15, -((4*E^(2*b*x))/b^4) + (2*E^(2*b*x)*x)/b^3 - (E^(2*b*x)*x^2)/(2*b^2) - (6*E^(b*x)*ExpIntegralEi[b*x])/b^4 + (6*E^(b*x)*x*ExpIntegralEi[b*x])/b^3 - (3*E^(b*x)*x^2*ExpIntegralEi[b*x])/b^2 + (E^(b*x)*x^3*ExpIntegralEi[b*x])/b + (6*ExpIntegralEi[2*b*x])/b^4}


(* ::Subsection::Closed:: *)
(*Integrands of the form x^m E^(a+b x) ExpIntegralEi[c+d x]^n*)


{x^3*E^(a + b*x)*ExpIntegralEi[c + d*x], x, 28, -((2*E^(a + c + (b + d)*x))/(b*(b + d)^3)) - (3*E^(a + c + (b + d)*x))/(b^2*(b + d)^2) - (c*E^(a + c + (b + d)*x))/(b*d*(b + d)^2) - (6*E^(a + c + (b + d)*x))/(b^3*(b + d)) - (c^2*E^(a + c + (b + d)*x))/(b*d^2*(b + d)) - (3*c*E^(a + c + (b + d)*x))/(b^2*d*(b + d)) + (2*E^(a + c + (b + d)*x)*x)/(b*(b + d)^2) + (3*E^(a + c + (b + d)*x)*x)/(b^2*(b + d)) + (c*E^(a + c + (b + d)*x)*x)/(b*d*(b + d)) - (E^(a + c + (b + d)*x)*x^2)/(b*(b + d)) - (6*E^(a + b*x)*ExpIntegralEi[c + d*x])/b^4 + (6*E^(a + b*x)*x*ExpIntegralEi[c + d*x])/b^3 - (3*E^(a + b*x)*x^2*ExpIntegralEi[c + d*x])/b^2 + (E^(a + b*x)*x^3*ExpIntegralEi[c + d*x])/b + (6*E^(a - (b*c)/d)*ExpIntegralEi[((b + d)*(c + d*x))/d])/b^4 + (c^3*E^(a - (b*c)/d)*ExpIntegralEi[((b + d)*(c + d*x))/d])/(b*d^3) + (3*c^2*E^(a - (b*c)/d)*ExpIntegralEi[((b + d)*(c + d*x))/d])/(b^2*d^2) + (6*c*E^(a - (b*c)/d)*ExpIntegralEi[((b + d)*(c + d*x))/d])/(b^3*d)}
{x^2*E^(a + b*x)*ExpIntegralEi[c + d*x], x, 17, E^(a + c + (b + d)*x)/(b*(b + d)^2) + (2*E^(a + c + (b + d)*x))/(b^2*(b + d)) + (c*E^(a + c + (b + d)*x))/(b*d*(b + d)) - (E^(a + c + (b + d)*x)*x)/(b*(b + d)) + (2*E^(a + b*x)*ExpIntegralEi[c + d*x])/b^3 - (2*E^(a + b*x)*x*ExpIntegralEi[c + d*x])/b^2 + (E^(a + b*x)*x^2*ExpIntegralEi[c + d*x])/b - (2*E^(a - (b*c)/d)*ExpIntegralEi[((b + d)*(c + d*x))/d])/b^3 - (c^2*E^(a - (b*c)/d)*ExpIntegralEi[((b + d)*(c + d*x))/d])/(b*d^2) - (2*c*E^(a - (b*c)/d)*ExpIntegralEi[((b + d)*(c + d*x))/d])/(b^2*d)}
{x^1*E^(a + b*x)*ExpIntegralEi[c + d*x], x, 9, -(E^(a + c + (b + d)*x)/(b*(b + d))) - (E^(a + b*x)*ExpIntegralEi[c + d*x])/b^2 + (E^(a + b*x)*x*ExpIntegralEi[c + d*x])/b + (E^(a - (b*c)/d)*ExpIntegralEi[((b + d)*(c + d*x))/d])/b^2 + (c*E^(a - (b*c)/d)*ExpIntegralEi[((b + d)*(c + d*x))/d])/(b*d)}
{x^0*E^(a + b*x)*ExpIntegralEi[c + d*x], x, 3, (E^(a + b*x)*ExpIntegralEi[c + d*x])/b - (E^(a - (b*c)/d)*ExpIntegralEi[((b + d)*(c + d*x))/d])/b}
{E^(a + b*x)*ExpIntegralEi[c + d*x]/x^1, x, 0, Int[(E^(a + b*x)*ExpIntegralEi[c + d*x])/x, x]}
{E^(a + b*x)*ExpIntegralEi[c + d*x]/x^2, x, 6, (d*E^(a + c)*ExpIntegralEi[(b + d)*x])/c - (E^(a + b*x)*ExpIntegralEi[c + d*x])/x - (d*E^(a - (b*c)/d)*ExpIntegralEi[((b + d)*(c + d*x))/d])/c + b*Int[(E^(a + b*x)*ExpIntegralEi[c + d*x])/x, x]}
{E^(a + b*x)*ExpIntegralEi[c + d*x]/x^3, x, 14, -((d*E^(a + c + (b + d)*x))/(2*c*x)) + (b*d*E^(a + c)*ExpIntegralEi[(b + d)*x])/(2*c) - (d^2*E^(a + c)*ExpIntegralEi[(b + d)*x])/(2*c^2) + (d*(b + d)*E^(a + c)*ExpIntegralEi[(b + d)*x])/(2*c) - (E^(a + b*x)*ExpIntegralEi[c + d*x])/(2*x^2) - (b*E^(a + b*x)*ExpIntegralEi[c + d*x])/(2*x) - (b*d*E^(a - (b*c)/d)*ExpIntegralEi[((b + d)*(c + d*x))/d])/(2*c) + (d^2*E^(a - (b*c)/d)*ExpIntegralEi[((b + d)*(c + d*x))/d])/(2*c^2) + (1/2)*b^2*Int[(E^(a + b*x)*ExpIntegralEi[c + d*x])/x, x]}
