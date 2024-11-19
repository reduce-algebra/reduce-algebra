(* ::Package:: *)

(* ::Title:: *)
(*Integration Problems Involving Fresnel Integral Functions*)


(* ::Section:: *)
(*Integration Problems Involving the Fresnel S Integral Function*)


(* ::Subsection::Closed:: *)
(*Integrands of the form x^m FresnelS[b x]^n*)


{FresnelS[b*x]^2/x^10, x, 0, Int[FresnelS[b*x]^2/x^10, x]}
{FresnelS[b*x]^2/x^9, x, 16, -(b^2/(336*x^6)) + (b^6*Pi^2)/(1680*x^2) + (b^2*Cos[b^2*Pi*x^2])/(336*x^6) - (b^6*Pi^2*Cos[b^2*Pi*x^2])/(336*x^2) - (b^3*Pi*Cos[(1/2)*b^2*Pi*x^2]*FresnelS[b*x])/(140*x^5) + (b^7*Pi^3*Cos[(1/2)*b^2*Pi*x^2]*FresnelS[b*x])/(420*x) + (1/840)*b^8*Pi^4*FresnelS[b*x]^2 - FresnelS[b*x]^2/(8*x^8) - (b*FresnelS[b*x]*Sin[(1/2)*b^2*Pi*x^2])/(28*x^7) + (b^5*Pi^2*FresnelS[b*x]*Sin[(1/2)*b^2*Pi*x^2])/(420*x^3) - (b^4*Pi*Sin[b^2*Pi*x^2])/(420*x^4) - (1/280)*b^8*Pi^3*SinIntegral[b^2*Pi*x^2]}
{FresnelS[b*x]^2/x^8, x, 0, Int[FresnelS[b*x]^2/x^8, x]}
{FresnelS[b*x]^2/x^7, x, 0, Int[FresnelS[b*x]^2/x^7, x]}
{FresnelS[b*x]^2/x^6, x, 0, Int[FresnelS[b*x]^2/x^6, x]}
{FresnelS[b*x]^2/x^5, x, 7, -(b^2/(24*x^2)) + (b^2*Cos[b^2*Pi*x^2])/(24*x^2) - (b^3*Pi*Cos[(1/2)*b^2*Pi*x^2]*FresnelS[b*x])/(6*x) - (1/12)*b^4*Pi^2*FresnelS[b*x]^2 - FresnelS[b*x]^2/(4*x^4) - (b*FresnelS[b*x]*Sin[(1/2)*b^2*Pi*x^2])/(6*x^3) + (1/12)*b^4*Pi*SinIntegral[b^2*Pi*x^2]}
{FresnelS[b*x]^2/x^4, x, 0, Int[FresnelS[b*x]^2/x^4, x]}
{FresnelS[b*x]^2/x^3, x, 0, Int[FresnelS[b*x]^2/x^3, x]}
{FresnelS[b*x]^2/x^2, x, 0, Int[FresnelS[b*x]^2/x^2, x]}
{FresnelS[b*x]^2/x, x, 0, Int[FresnelS[b*x]^2/x, x]}
{FresnelS[b*x]^2, x, 4, (2*Cos[(1/2)*b^2*Pi*x^2]*FresnelS[b*x])/(b*Pi) + x*FresnelS[b*x]^2 - FresnelS[Sqrt[2]*b*x]/(Sqrt[2]*b*Pi)}
{x*FresnelS[b*x]^2, x, 0, Int[x*FresnelS[b*x]^2, x]}
{x^2*FresnelS[b*x]^2, x, 6, (2*x)/(3*b^2*Pi^2) + (x*Cos[b^2*Pi*x^2])/(6*b^2*Pi^2) - (5*FresnelC[Sqrt[2]*b*x])/(6*Sqrt[2]*b^3*Pi^2) + (2*x^2*Cos[(1/2)*b^2*Pi*x^2]*FresnelS[b*x])/(3*b*Pi) + (1/3)*x^3*FresnelS[b*x]^2 - (4*FresnelS[b*x]*Sin[(1/2)*b^2*Pi*x^2])/(3*b^3*Pi^2)}
{x^3*FresnelS[b*x]^2, x, 7, (3*x^2)/(8*b^2*Pi^2) + (x^2*Cos[b^2*Pi*x^2])/(8*b^2*Pi^2) + (x^3*Cos[(1/2)*b^2*Pi*x^2]*FresnelS[b*x])/(2*b*Pi) + (3*FresnelS[b*x]^2)/(4*b^4*Pi^2) + (1/4)*x^4*FresnelS[b*x]^2 - (3*x*FresnelS[b*x]*Sin[(1/2)*b^2*Pi*x^2])/(2*b^3*Pi^2) - Sin[b^2*Pi*x^2]/(2*b^4*Pi^3)}
{x^4*FresnelS[b*x]^2, x, 10, (4*x^3)/(15*b^2*Pi^2) + (x^3*Cos[b^2*Pi*x^2])/(10*b^2*Pi^2) - (16*Cos[(1/2)*b^2*Pi*x^2]*FresnelS[b*x])/(5*b^5*Pi^3) + (2*x^4*Cos[(1/2)*b^2*Pi*x^2]*FresnelS[b*x])/(5*b*Pi) + (1/5)*x^5*FresnelS[b*x]^2 + (43*FresnelS[Sqrt[2]*b*x])/(20*Sqrt[2]*b^5*Pi^3) - (8*x^2*FresnelS[b*x]*Sin[(1/2)*b^2*Pi*x^2])/(5*b^3*Pi^2) - (11*x*Sin[b^2*Pi*x^2])/(20*b^4*Pi^3)}
{x^5*FresnelS[b*x]^2, x, 0, Int[x^5*FresnelS[b*x]^2, x]}
{x^6*FresnelS[b*x]^2, x, 15, -((48*x)/(7*b^6*Pi^4)) + (6*x^5)/(35*b^2*Pi^2) - (21*x*Cos[b^2*Pi*x^2])/(8*b^6*Pi^4) + (x^5*Cos[b^2*Pi*x^2])/(14*b^2*Pi^2) + (531*FresnelC[Sqrt[2]*b*x])/(56*Sqrt[2]*b^7*Pi^4) - (48*x^2*Cos[(1/2)*b^2*Pi*x^2]*FresnelS[b*x])/(7*b^5*Pi^3) + (2*x^6*Cos[(1/2)*b^2*Pi*x^2]*FresnelS[b*x])/(7*b*Pi) + (1/7)*x^7*FresnelS[b*x]^2 + (96*FresnelS[b*x]*Sin[(1/2)*b^2*Pi*x^2])/(7*b^7*Pi^4) - (12*x^4*FresnelS[b*x]*Sin[(1/2)*b^2*Pi*x^2])/(7*b^3*Pi^2) - (17*x^3*Sin[b^2*Pi*x^2])/(28*b^4*Pi^3)}
{x^7*FresnelS[b*x]^2, x, 16, -((105*x^2)/(16*b^6*Pi^4)) + (7*x^6)/(48*b^2*Pi^2) - (55*x^2*Cos[b^2*Pi*x^2])/(16*b^6*Pi^4) + (x^6*Cos[b^2*Pi*x^2])/(16*b^2*Pi^2) - (35*x^3*Cos[(1/2)*b^2*Pi*x^2]*FresnelS[b*x])/(4*b^5*Pi^3) + (x^7*Cos[(1/2)*b^2*Pi*x^2]*FresnelS[b*x])/(4*b*Pi) - (105*FresnelS[b*x]^2)/(8*b^8*Pi^4) + (1/8)*x^8*FresnelS[b*x]^2 + (105*x*FresnelS[b*x]*Sin[(1/2)*b^2*Pi*x^2])/(4*b^7*Pi^4) - (7*x^5*FresnelS[b*x]*Sin[(1/2)*b^2*Pi*x^2])/(4*b^3*Pi^2) + (10*Sin[b^2*Pi*x^2])/(b^8*Pi^5) - (5*x^4*Sin[b^2*Pi*x^2])/(8*b^4*Pi^3)}


(* ::Subsection::Closed:: *)
(*Integrands of the form x^m FresnelS[a+b x]^n*)


{FresnelS[a + b*x]/x, x, 0, Int[FresnelS[a + b*x]/x, x]}
{FresnelS[a + b*x], x, 1, Cos[(1/2)*Pi*(a + b*x)^2]/(b*Pi) + ((a + b*x)*FresnelS[a + b*x])/b}
{x*FresnelS[a + b*x], x, 8, -((a*Cos[(1/2)*Pi*(a + b*x)^2])/(b^2*Pi)) + ((a + b*x)*Cos[(1/2)*Pi*(a + b*x)^2])/(2*b^2*Pi) - FresnelC[a + b*x]/(2*b^2*Pi) - (a^2*FresnelS[a + b*x])/(2*b^2) + (1/2)*x^2*FresnelS[a + b*x]}
{x^2*FresnelS[a + b*x], x, 10, (a^2*Cos[(1/2)*Pi*(a + b*x)^2])/(b^3*Pi) - (a*(a + b*x)*Cos[(1/2)*Pi*(a + b*x)^2])/(b^3*Pi) + ((a + b*x)^2*Cos[(1/2)*Pi*(a + b*x)^2])/(3*b^3*Pi) + (a*FresnelC[a + b*x])/(b^3*Pi) + (a^3*FresnelS[a + b*x])/(3*b^3) + (1/3)*x^3*FresnelS[a + b*x] - (2*Sin[(1/2)*Pi*(a + b*x)^2])/(3*b^3*Pi^2)}
{x^3*FresnelS[a + b*x], x, 13, -((a^3*Cos[(1/2)*Pi*(a + b*x)^2])/(b^4*Pi)) + (3*a^2*(a + b*x)*Cos[(1/2)*Pi*(a + b*x)^2])/(2*b^4*Pi) - (a*(a + b*x)^2*Cos[(1/2)*Pi*(a + b*x)^2])/(b^4*Pi) + ((a + b*x)^3*Cos[(1/2)*Pi*(a + b*x)^2])/(4*b^4*Pi) - (3*a^2*FresnelC[a + b*x])/(2*b^4*Pi) - (a^4*FresnelS[a + b*x])/(4*b^4) + (3*FresnelS[a + b*x])/(4*b^4*Pi^2) + (1/4)*x^4*FresnelS[a + b*x] + (2*a*Sin[(1/2)*Pi*(a + b*x)^2])/(b^4*Pi^2) - (3*(a + b*x)*Sin[(1/2)*Pi*(a + b*x)^2])/(4*b^4*Pi^2)}


{FresnelS[a + b*x]^2/x, x, 0, Int[FresnelS[a + b*x]^2/x, x]}
{FresnelS[a + b*x]^2, x, 4, (2*Cos[(1/2)*Pi*(a + b*x)^2]*FresnelS[a + b*x])/(b*Pi) + ((a + b*x)*FresnelS[a + b*x]^2)/b - FresnelS[Sqrt[2]*(a + b*x)]/(Sqrt[2]*b*Pi)}
{x*FresnelS[a + b*x]^2, x, 0, Int[x*FresnelS[a + b*x]^2, x]}


(* ::Subsection::Closed:: *)
(*Integrands of the form x^m Sin[Pi/2 b^2 x^2] FresnelS[b x]^n*)


{Sin[Pi/2*b^2*x^2]*FresnelS[b*x]/x^10, x, 0, Int[(FresnelS[b*x]*Sin[(1/2)*b^2*Pi*x^2])/x^10, x]}
{Sin[Pi/2*b^2*x^2]*FresnelS[b*x]/x^9, x, 0, Int[(FresnelS[b*x]*Sin[(1/2)*b^2*Pi*x^2])/x^9, x]}
{Sin[Pi/2*b^2*x^2]*FresnelS[b*x]/x^8, x, 15, -(b/(84*x^6)) + (b^5*Pi^2)/(420*x^2) + (b*Cos[b^2*Pi*x^2])/(84*x^6) - (b^5*Pi^2*Cos[b^2*Pi*x^2])/(84*x^2) - (b^2*Pi*Cos[(1/2)*b^2*Pi*x^2]*FresnelS[b*x])/(35*x^5) + (b^6*Pi^3*Cos[(1/2)*b^2*Pi*x^2]*FresnelS[b*x])/(105*x) + (1/210)*b^7*Pi^4*FresnelS[b*x]^2 - (FresnelS[b*x]*Sin[(1/2)*b^2*Pi*x^2])/(7*x^7) + (b^4*Pi^2*FresnelS[b*x]*Sin[(1/2)*b^2*Pi*x^2])/(105*x^3) - (b^3*Pi*Sin[b^2*Pi*x^2])/(105*x^4) - (1/70)*b^7*Pi^3*SinIntegral[b^2*Pi*x^2]}
{Sin[Pi/2*b^2*x^2]*FresnelS[b*x]/x^7, x, 0, Int[(FresnelS[b*x]*Sin[(1/2)*b^2*Pi*x^2])/x^7, x]}
{Sin[Pi/2*b^2*x^2]*FresnelS[b*x]/x^6, x, 0, Int[(FresnelS[b*x]*Sin[(1/2)*b^2*Pi*x^2])/x^6, x]}
{Sin[Pi/2*b^2*x^2]*FresnelS[b*x]/x^5, x, 0, Int[(FresnelS[b*x]*Sin[(1/2)*b^2*Pi*x^2])/x^5, x]}
{Sin[Pi/2*b^2*x^2]*FresnelS[b*x]/x^4, x, 6, -(b/(12*x^2)) + (b*Cos[b^2*Pi*x^2])/(12*x^2) - (b^2*Pi*Cos[(1/2)*b^2*Pi*x^2]*FresnelS[b*x])/(3*x) - (1/6)*b^3*Pi^2*FresnelS[b*x]^2 - (FresnelS[b*x]*Sin[(1/2)*b^2*Pi*x^2])/(3*x^3) + (1/6)*b^3*Pi*SinIntegral[b^2*Pi*x^2]}
{Sin[Pi/2*b^2*x^2]*FresnelS[b*x]/x^3, x, 0, Int[(FresnelS[b*x]*Sin[(1/2)*b^2*Pi*x^2])/x^3, x]}
{Sin[Pi/2*b^2*x^2]*FresnelS[b*x]/x^2, x, 0, Int[(FresnelS[b*x]*Sin[(1/2)*b^2*Pi*x^2])/x^2, x]}
{Sin[Pi/2*b^2*x^2]*FresnelS[b*x]/x, x, 0, Int[(FresnelS[b*x]*Sin[(1/2)*b^2*Pi*x^2])/x, x]}
{Sin[Pi/2*b^2*x^2]*FresnelS[b*x], x, 1, FresnelS[b*x]^2/(2*b)}
{x*Sin[Pi/2*b^2*x^2]*FresnelS[b*x], x, 2, -((Cos[(1/2)*b^2*Pi*x^2]*FresnelS[b*x])/(b^2*Pi)) + FresnelS[Sqrt[2]*b*x]/(2*Sqrt[2]*b^2*Pi)}
{x^2*Sin[Pi/2*b^2*x^2]*FresnelS[b*x], x, 0, Int[x^2*FresnelS[b*x]*Sin[(1/2)*b^2*Pi*x^2], x]}
{x^3*Sin[Pi/2*b^2*x^2]*FresnelS[b*x], x, 5, -(x/(b^3*Pi^2)) - (x*Cos[b^2*Pi*x^2])/(4*b^3*Pi^2) + (5*FresnelC[Sqrt[2]*b*x])/(4*Sqrt[2]*b^4*Pi^2) - (x^2*Cos[(1/2)*b^2*Pi*x^2]*FresnelS[b*x])/(b^2*Pi) + (2*FresnelS[b*x]*Sin[(1/2)*b^2*Pi*x^2])/(b^4*Pi^2)}
{x^4*Sin[Pi/2*b^2*x^2]*FresnelS[b*x], x, 6, -((3*x^2)/(4*b^3*Pi^2)) - (x^2*Cos[b^2*Pi*x^2])/(4*b^3*Pi^2) - (x^3*Cos[(1/2)*b^2*Pi*x^2]*FresnelS[b*x])/(b^2*Pi) - (3*FresnelS[b*x]^2)/(2*b^5*Pi^2) + (3*x*FresnelS[b*x]*Sin[(1/2)*b^2*Pi*x^2])/(b^4*Pi^2) + Sin[b^2*Pi*x^2]/(b^5*Pi^3)}
{x^5*Sin[Pi/2*b^2*x^2]*FresnelS[b*x], x, 9, -((2*x^3)/(3*b^3*Pi^2)) - (x^3*Cos[b^2*Pi*x^2])/(4*b^3*Pi^2) + (8*Cos[(1/2)*b^2*Pi*x^2]*FresnelS[b*x])/(b^6*Pi^3) - (x^4*Cos[(1/2)*b^2*Pi*x^2]*FresnelS[b*x])/(b^2*Pi) - (43*FresnelS[Sqrt[2]*b*x])/(8*Sqrt[2]*b^6*Pi^3) + (4*x^2*FresnelS[b*x]*Sin[(1/2)*b^2*Pi*x^2])/(b^4*Pi^2) + (11*x*Sin[b^2*Pi*x^2])/(8*b^5*Pi^3)}
{x^6*Sin[Pi/2*b^2*x^2]*FresnelS[b*x], x, 0, Int[x^6*FresnelS[b*x]*Sin[(1/2)*b^2*Pi*x^2], x]}
{x^7*Sin[Pi/2*b^2*x^2]*FresnelS[b*x], x, 14, (24*x)/(b^7*Pi^4) - (3*x^5)/(5*b^3*Pi^2) + (147*x*Cos[b^2*Pi*x^2])/(16*b^7*Pi^4) - (x^5*Cos[b^2*Pi*x^2])/(4*b^3*Pi^2) - (531*FresnelC[Sqrt[2]*b*x])/(16*Sqrt[2]*b^8*Pi^4) + (24*x^2*Cos[(1/2)*b^2*Pi*x^2]*FresnelS[b*x])/(b^6*Pi^3) - (x^6*Cos[(1/2)*b^2*Pi*x^2]*FresnelS[b*x])/(b^2*Pi) - (48*FresnelS[b*x]*Sin[(1/2)*b^2*Pi*x^2])/(b^8*Pi^4) + (6*x^4*FresnelS[b*x]*Sin[(1/2)*b^2*Pi*x^2])/(b^4*Pi^2) + (17*x^3*Sin[b^2*Pi*x^2])/(8*b^5*Pi^3)}
(* {x^8*Sin[Pi/2*b^2*x^2]*FresnelS[b*x], x, 20, (105*x^2)/(4*b^7*Pi^4) - (7*x^6)/(12*b^3*Pi^2) + (55*x^2*Cos[b^2*Pi*x^2])/(4*b^7*Pi^4) - (x^6*Cos[b^2*Pi*x^2])/(4*b^3*Pi^2) + (105*FresnelS[b*x]^2)/(2*b^9*Pi^4) + (x*FresnelS[b*x]*(b^2*Pi*x^2*(35 - b^4*Pi^2*x^4)*Cos[(1/2)*b^2*Pi*x^2] - 7*(15 - b^4*Pi^2*x^4)*Sin[(1/2)*b^2*Pi*x^2]))/(b^8*Pi^4) - (40*Sin[b^2*Pi*x^2])/(b^9*Pi^5) + (5*x^4*Sin[b^2*Pi*x^2])/(2*b^5*Pi^3)} *)


(* ::Subsection::Closed:: *)
(*Integrands of the form x^m Cos[Pi/2 b^2 x^2] FresnelS[b x]^n*)


{Cos[Pi/2*b^2*x^2]*FresnelS[b*x]/x^10, x, 21, (b^3*Pi)/(756*x^6) - (b^7*Pi^3)/(3780*x^2) - (11*b^3*Pi*Cos[b^2*Pi*x^2])/(3024*x^6) + (5*b^7*Pi^3*Cos[b^2*Pi*x^2])/(2016*x^2) - (Cos[(1/2)*b^2*Pi*x^2]*FresnelS[b*x])/(9*x^9) + (b^4*Pi^2*Cos[(1/2)*b^2*Pi*x^2]*FresnelS[b*x])/(315*x^5) - (b^8*Pi^4*Cos[(1/2)*b^2*Pi*x^2]*FresnelS[b*x])/(945*x) - (b^9*Pi^5*FresnelS[b*x]^2)/1890 + (b^2*Pi*FresnelS[b*x]*Sin[(1/2)*b^2*Pi*x^2])/(63*x^7) - (b^6*Pi^3*FresnelS[b*x]*Sin[(1/2)*b^2*Pi*x^2])/(945*x^3) - (b*Sin[b^2*Pi*x^2])/(144*x^8) + (67*b^5*Pi^2*Sin[b^2*Pi*x^2])/(30240*x^4) + (83*b^9*Pi^4*SinIntegral[b^2*Pi*x^2])/30240}
{Cos[Pi/2*b^2*x^2]*FresnelS[b*x]/x^9, x, 0, Int[(Cos[(1/2)*b^2*Pi*x^2]*FresnelS[b*x])/x^9, x]}
{Cos[Pi/2*b^2*x^2]*FresnelS[b*x]/x^8, x, 0, Int[(Cos[(1/2)*b^2*Pi*x^2]*FresnelS[b*x])/x^8, x]}
{Cos[Pi/2*b^2*x^2]*FresnelS[b*x]/x^7, x, 0, Int[(Cos[(1/2)*b^2*Pi*x^2]*FresnelS[b*x])/x^7, x]}
{Cos[Pi/2*b^2*x^2]*FresnelS[b*x]/x^6, x, 10, (b^3*Pi)/(60*x^2) - (b^3*Pi*Cos[b^2*Pi*x^2])/(24*x^2) - (Cos[(1/2)*b^2*Pi*x^2]*FresnelS[b*x])/(5*x^5) + (b^4*Pi^2*Cos[(1/2)*b^2*Pi*x^2]*FresnelS[b*x])/(15*x) + (1/30)*b^5*Pi^3*FresnelS[b*x]^2 + (b^2*Pi*FresnelS[b*x]*Sin[(1/2)*b^2*Pi*x^2])/(15*x^3) - (b*Sin[b^2*Pi*x^2])/(40*x^4) - (7/120)*b^5*Pi^2*SinIntegral[b^2*Pi*x^2]}
{Cos[Pi/2*b^2*x^2]*FresnelS[b*x]/x^5, x, 0, Int[(Cos[(1/2)*b^2*Pi*x^2]*FresnelS[b*x])/x^5, x]}
{Cos[Pi/2*b^2*x^2]*FresnelS[b*x]/x^4, x, 0, Int[(Cos[(1/2)*b^2*Pi*x^2]*FresnelS[b*x])/x^4, x]}
{Cos[Pi/2*b^2*x^2]*FresnelS[b*x]/x^3, x, 0, Int[(Cos[(1/2)*b^2*Pi*x^2]*FresnelS[b*x])/x^3, x]}
{Cos[Pi/2*b^2*x^2]*FresnelS[b*x]/x^2, x, 3, -((Cos[(1/2)*b^2*Pi*x^2]*FresnelS[b*x])/x) - (1/2)*b*Pi*FresnelS[b*x]^2 + (1/4)*b*SinIntegral[b^2*Pi*x^2]}
{Cos[Pi/2*b^2*x^2]*FresnelS[b*x]/x, x, 0, Int[(Cos[(1/2)*b^2*Pi*x^2]*FresnelS[b*x])/x, x]}
{Cos[Pi/2*b^2*x^2]*FresnelS[b*x], x, 0, Int[Cos[(1/2)*b^2*Pi*x^2]*FresnelS[b*x], x]}
{x*Cos[Pi/2*b^2*x^2]*FresnelS[b*x], x, 2, -(x/(2*b*Pi)) + FresnelC[Sqrt[2]*b*x]/(2*Sqrt[2]*b^2*Pi) + (FresnelS[b*x]*Sin[(1/2)*b^2*Pi*x^2])/(b^2*Pi)}
{x^2*Cos[Pi/2*b^2*x^2]*FresnelS[b*x], x, 3, -(x^2/(4*b*Pi)) - FresnelS[b*x]^2/(2*b^3*Pi) + (x*FresnelS[b*x]*Sin[(1/2)*b^2*Pi*x^2])/(b^2*Pi) + Sin[b^2*Pi*x^2]/(4*b^3*Pi^2)}
{x^3*Cos[Pi/2*b^2*x^2]*FresnelS[b*x], x, 5, -(x^3/(6*b*Pi)) + (2*Cos[(1/2)*b^2*Pi*x^2]*FresnelS[b*x])/(b^4*Pi^2) - (5*FresnelS[Sqrt[2]*b*x])/(4*Sqrt[2]*b^4*Pi^2) + (x^2*FresnelS[b*x]*Sin[(1/2)*b^2*Pi*x^2])/(b^2*Pi) + (x*Sin[b^2*Pi*x^2])/(4*b^3*Pi^2)}
{x^4*Cos[Pi/2*b^2*x^2]*FresnelS[b*x], x, 0, Int[x^4*Cos[(1/2)*b^2*Pi*x^2]*FresnelS[b*x], x]}
{x^5*Cos[Pi/2*b^2*x^2]*FresnelS[b*x], x, 9, (4*x)/(b^5*Pi^3) - x^5/(10*b*Pi) + (11*x*Cos[b^2*Pi*x^2])/(8*b^5*Pi^3) - (43*FresnelC[Sqrt[2]*b*x])/(8*Sqrt[2]*b^6*Pi^3) + (4*x^2*Cos[(1/2)*b^2*Pi*x^2]*FresnelS[b*x])/(b^4*Pi^2) - (8*FresnelS[b*x]*Sin[(1/2)*b^2*Pi*x^2])/(b^6*Pi^3) + (x^4*FresnelS[b*x]*Sin[(1/2)*b^2*Pi*x^2])/(b^2*Pi) + (x^3*Sin[b^2*Pi*x^2])/(4*b^3*Pi^2)}
{x^6*Cos[Pi/2*b^2*x^2]*FresnelS[b*x], x, 10, (15*x^2)/(4*b^5*Pi^3) - x^6/(12*b*Pi) + (7*x^2*Cos[b^2*Pi*x^2])/(4*b^5*Pi^3) + (5*x^3*Cos[(1/2)*b^2*Pi*x^2]*FresnelS[b*x])/(b^4*Pi^2) + (15*FresnelS[b*x]^2)/(2*b^7*Pi^3) - (15*x*FresnelS[b*x]*Sin[(1/2)*b^2*Pi*x^2])/(b^6*Pi^3) + (x^5*FresnelS[b*x]*Sin[(1/2)*b^2*Pi*x^2])/(b^2*Pi) - (11*Sin[b^2*Pi*x^2])/(2*b^7*Pi^4) + (x^4*Sin[b^2*Pi*x^2])/(4*b^3*Pi^2)}
{x^7*Cos[Pi/2*b^2*x^2]*FresnelS[b*x], x, 14, (4*x^3)/(b^5*Pi^3) - x^7/(14*b*Pi) + (17*x^3*Cos[b^2*Pi*x^2])/(8*b^5*Pi^3) - (48*Cos[(1/2)*b^2*Pi*x^2]*FresnelS[b*x])/(b^8*Pi^4) + (6*x^4*Cos[(1/2)*b^2*Pi*x^2]*FresnelS[b*x])/(b^4*Pi^2) + (531*FresnelS[Sqrt[2]*b*x])/(16*Sqrt[2]*b^8*Pi^4) - (24*x^2*FresnelS[b*x]*Sin[(1/2)*b^2*Pi*x^2])/(b^6*Pi^3) + (x^6*FresnelS[b*x]*Sin[(1/2)*b^2*Pi*x^2])/(b^2*Pi) - (147*x*Sin[b^2*Pi*x^2])/(16*b^7*Pi^4) + (x^5*Sin[b^2*Pi*x^2])/(4*b^3*Pi^2)}
{x^8*Cos[Pi/2*b^2*x^2]*FresnelS[b*x], x, 0, Int[x^8*Cos[(1/2)*b^2*Pi*x^2]*FresnelS[b*x], x]}


(* ::Section:: *)
(*Integration Problems Involving the Fresnel C Integral Function*)


(* ::Subsection::Closed:: *)
(*Integrands of the form x^m FresnelC[b x]^n*)


{FresnelC[b*x]^2/x^10, x, 0, Int[FresnelC[b*x]^2/x^10, x]}
{FresnelC[b*x]^2/x^9, x, 16, -(b^2/(336*x^6)) + (b^6*Pi^2)/(1680*x^2) - (b^2*Cos[b^2*Pi*x^2])/(336*x^6) + (b^6*Pi^2*Cos[b^2*Pi*x^2])/(336*x^2) - (b*Cos[(1/2)*b^2*Pi*x^2]*FresnelC[b*x])/(28*x^7) + (b^5*Pi^2*Cos[(1/2)*b^2*Pi*x^2]*FresnelC[b*x])/(420*x^3) + (1/840)*b^8*Pi^4*FresnelC[b*x]^2 - FresnelC[b*x]^2/(8*x^8) + (b^3*Pi*FresnelC[b*x]*Sin[(1/2)*b^2*Pi*x^2])/(140*x^5) - (b^7*Pi^3*FresnelC[b*x]*Sin[(1/2)*b^2*Pi*x^2])/(420*x) + (b^4*Pi*Sin[b^2*Pi*x^2])/(420*x^4) + (1/280)*b^8*Pi^3*SinIntegral[b^2*Pi*x^2]}
{FresnelC[b*x]^2/x^8, x, 0, Int[FresnelC[b*x]^2/x^8, x]}
{FresnelC[b*x]^2/x^7, x, 0, Int[FresnelC[b*x]^2/x^7, x]}
{FresnelC[b*x]^2/x^6, x, 0, Int[FresnelC[b*x]^2/x^6, x]}
{FresnelC[b*x]^2/x^5, x, 7, -(b^2/(24*x^2)) - (b^2*Cos[b^2*Pi*x^2])/(24*x^2) - (b*Cos[(1/2)*b^2*Pi*x^2]*FresnelC[b*x])/(6*x^3) - (1/12)*b^4*Pi^2*FresnelC[b*x]^2 - FresnelC[b*x]^2/(4*x^4) + (b^3*Pi*FresnelC[b*x]*Sin[(1/2)*b^2*Pi*x^2])/(6*x) - (1/12)*b^4*Pi*SinIntegral[b^2*Pi*x^2]}
{FresnelC[b*x]^2/x^4, x, 0, Int[FresnelC[b*x]^2/x^4, x]}
{FresnelC[b*x]^2/x^3, x, 0, Int[FresnelC[b*x]^2/x^3, x]}
{FresnelC[b*x]^2/x^2, x, 0, Int[FresnelC[b*x]^2/x^2, x]}
{FresnelC[b*x]^2/x, x, 0, Int[FresnelC[b*x]^2/x, x]}
{FresnelC[b*x]^2, x, 4, x*FresnelC[b*x]^2 + FresnelS[Sqrt[2]*b*x]/(Sqrt[2]*b*Pi) - (2*FresnelC[b*x]*Sin[(1/2)*b^2*Pi*x^2])/(b*Pi)}
{x*FresnelC[b*x]^2, x, 0, Int[x*FresnelC[b*x]^2, x]}
{x^2*FresnelC[b*x]^2, x, 6, (2*x)/(3*b^2*Pi^2) - (x*Cos[b^2*Pi*x^2])/(6*b^2*Pi^2) - (4*Cos[(1/2)*b^2*Pi*x^2]*FresnelC[b*x])/(3*b^3*Pi^2) + (1/3)*x^3*FresnelC[b*x]^2 + (5*FresnelC[Sqrt[2]*b*x])/(6*Sqrt[2]*b^3*Pi^2) - (2*x^2*FresnelC[b*x]*Sin[(1/2)*b^2*Pi*x^2])/(3*b*Pi)}
{x^3*FresnelC[b*x]^2, x, 7, (3*x^2)/(8*b^2*Pi^2) - (x^2*Cos[b^2*Pi*x^2])/(8*b^2*Pi^2) - (3*x*Cos[(1/2)*b^2*Pi*x^2]*FresnelC[b*x])/(2*b^3*Pi^2) + (3*FresnelC[b*x]^2)/(4*b^4*Pi^2) + (1/4)*x^4*FresnelC[b*x]^2 - (x^3*FresnelC[b*x]*Sin[(1/2)*b^2*Pi*x^2])/(2*b*Pi) + Sin[b^2*Pi*x^2]/(2*b^4*Pi^3)}
{x^4*FresnelC[b*x]^2, x, 10, (4*x^3)/(15*b^2*Pi^2) - (x^3*Cos[b^2*Pi*x^2])/(10*b^2*Pi^2) - (8*x^2*Cos[(1/2)*b^2*Pi*x^2]*FresnelC[b*x])/(5*b^3*Pi^2) + (1/5)*x^5*FresnelC[b*x]^2 - (43*FresnelS[Sqrt[2]*b*x])/(20*Sqrt[2]*b^5*Pi^3) + (16*FresnelC[b*x]*Sin[(1/2)*b^2*Pi*x^2])/(5*b^5*Pi^3) - (2*x^4*FresnelC[b*x]*Sin[(1/2)*b^2*Pi*x^2])/(5*b*Pi) + (11*x*Sin[b^2*Pi*x^2])/(20*b^4*Pi^3)}
{x^5*FresnelC[b*x]^2, x, 0, Int[x^5*FresnelC[b*x]^2, x]}
{x^6*FresnelC[b*x]^2, x, 15, -((48*x)/(7*b^6*Pi^4)) + (6*x^5)/(35*b^2*Pi^2) + (21*x*Cos[b^2*Pi*x^2])/(8*b^6*Pi^4) - (x^5*Cos[b^2*Pi*x^2])/(14*b^2*Pi^2) + (96*Cos[(1/2)*b^2*Pi*x^2]*FresnelC[b*x])/(7*b^7*Pi^4) - (12*x^4*Cos[(1/2)*b^2*Pi*x^2]*FresnelC[b*x])/(7*b^3*Pi^2) + (1/7)*x^7*FresnelC[b*x]^2 - (531*FresnelC[Sqrt[2]*b*x])/(56*Sqrt[2]*b^7*Pi^4) + (48*x^2*FresnelC[b*x]*Sin[(1/2)*b^2*Pi*x^2])/(7*b^5*Pi^3) - (2*x^6*FresnelC[b*x]*Sin[(1/2)*b^2*Pi*x^2])/(7*b*Pi) + (17*x^3*Sin[b^2*Pi*x^2])/(28*b^4*Pi^3)}
{x^7*FresnelC[b*x]^2, x, 16, -((105*x^2)/(16*b^6*Pi^4)) + (7*x^6)/(48*b^2*Pi^2) + (55*x^2*Cos[b^2*Pi*x^2])/(16*b^6*Pi^4) - (x^6*Cos[b^2*Pi*x^2])/(16*b^2*Pi^2) + (105*x*Cos[(1/2)*b^2*Pi*x^2]*FresnelC[b*x])/(4*b^7*Pi^4) - (7*x^5*Cos[(1/2)*b^2*Pi*x^2]*FresnelC[b*x])/(4*b^3*Pi^2) - (105*FresnelC[b*x]^2)/(8*b^8*Pi^4) + (1/8)*x^8*FresnelC[b*x]^2 + (35*x^3*FresnelC[b*x]*Sin[(1/2)*b^2*Pi*x^2])/(4*b^5*Pi^3) - (x^7*FresnelC[b*x]*Sin[(1/2)*b^2*Pi*x^2])/(4*b*Pi) - (10*Sin[b^2*Pi*x^2])/(b^8*Pi^5) + (5*x^4*Sin[b^2*Pi*x^2])/(8*b^4*Pi^3)}


(* ::Subsection::Closed:: *)
(*Integrands of the form x^m FresnelC[a+b x]^n*)


{FresnelC[a + b*x]/x, x, 0, Int[FresnelC[a + b*x]/x, x]}
{FresnelC[a + b*x], x, 1, ((a + b*x)*FresnelC[a + b*x])/b - Sin[(1/2)*Pi*(a + b*x)^2]/(b*Pi)}
{x*FresnelC[a + b*x], x, 8, -((a^2*FresnelC[a + b*x])/(2*b^2)) + (1/2)*x^2*FresnelC[a + b*x] + FresnelS[a + b*x]/(2*b^2*Pi) + (a*Sin[(1/2)*Pi*(a + b*x)^2])/(b^2*Pi) - ((a + b*x)*Sin[(1/2)*Pi*(a + b*x)^2])/(2*b^2*Pi)}
{x^2*FresnelC[a + b*x], x, 10, -((2*Cos[(1/2)*Pi*(a + b*x)^2])/(3*b^3*Pi^2)) + (a^3*FresnelC[a + b*x])/(3*b^3) + (1/3)*x^3*FresnelC[a + b*x] - (a*FresnelS[a + b*x])/(b^3*Pi) - (a^2*Sin[(1/2)*Pi*(a + b*x)^2])/(b^3*Pi) + (a*(a + b*x)*Sin[(1/2)*Pi*(a + b*x)^2])/(b^3*Pi) - ((a + b*x)^2*Sin[(1/2)*Pi*(a + b*x)^2])/(3*b^3*Pi)}
{x^3*FresnelC[a + b*x], x, 13, (2*a*Cos[(1/2)*Pi*(a + b*x)^2])/(b^4*Pi^2) - (3*(a + b*x)*Cos[(1/2)*Pi*(a + b*x)^2])/(4*b^4*Pi^2) - (a^4*FresnelC[a + b*x])/(4*b^4) + (3*FresnelC[a + b*x])/(4*b^4*Pi^2) + (1/4)*x^4*FresnelC[a + b*x] + (3*a^2*FresnelS[a + b*x])/(2*b^4*Pi) + (a^3*Sin[(1/2)*Pi*(a + b*x)^2])/(b^4*Pi) - (3*a^2*(a + b*x)*Sin[(1/2)*Pi*(a + b*x)^2])/(2*b^4*Pi) + (a*(a + b*x)^2*Sin[(1/2)*Pi*(a + b*x)^2])/(b^4*Pi) - ((a + b*x)^3*Sin[(1/2)*Pi*(a + b*x)^2])/(4*b^4*Pi)}


{FresnelC[a + b*x]^2/x, x, 0, Int[FresnelC[a + b*x]^2/x, x]}
{FresnelC[a + b*x]^2, x, 4, ((a + b*x)*FresnelC[a + b*x]^2)/b + FresnelS[Sqrt[2]*(a + b*x)]/(Sqrt[2]*b*Pi) - (2*FresnelC[a + b*x]*Sin[(1/2)*Pi*(a + b*x)^2])/(b*Pi)}
{x*FresnelC[a + b*x]^2, x, 0, Int[x*FresnelC[a + b*x]^2, x]}


(* ::Subsection::Closed:: *)
(*Integrands of the form x^m Sin[Pi/2 b^2 x^2] FresnelC[b x]^n*)


{Sin[Pi/2*b^2*x^2]*FresnelC[b*x]/x^10, x, 21, -((b^3*Pi)/(756*x^6)) + (b^7*Pi^3)/(3780*x^2) - (11*b^3*Pi*Cos[b^2*Pi*x^2])/(3024*x^6) + (5*b^7*Pi^3*Cos[b^2*Pi*x^2])/(2016*x^2) - (b^2*Pi*Cos[(1/2)*b^2*Pi*x^2]*FresnelC[b*x])/(63*x^7) + (b^6*Pi^3*Cos[(1/2)*b^2*Pi*x^2]*FresnelC[b*x])/(945*x^3) + (b^9*Pi^5*FresnelC[b*x]^2)/1890 - (FresnelC[b*x]*Sin[(1/2)*b^2*Pi*x^2])/(9*x^9) + (b^4*Pi^2*FresnelC[b*x]*Sin[(1/2)*b^2*Pi*x^2])/(315*x^5) - (b^8*Pi^4*FresnelC[b*x]*Sin[(1/2)*b^2*Pi*x^2])/(945*x) - (b*Sin[b^2*Pi*x^2])/(144*x^8) + (67*b^5*Pi^2*Sin[b^2*Pi*x^2])/(30240*x^4) + (83*b^9*Pi^4*SinIntegral[b^2*Pi*x^2])/30240}
{Sin[Pi/2*b^2*x^2]*FresnelC[b*x]/x^9, x, 0, Int[(FresnelC[b*x]*Sin[(1/2)*b^2*Pi*x^2])/x^9, x]}
{Sin[Pi/2*b^2*x^2]*FresnelC[b*x]/x^8, x, 0, Int[(FresnelC[b*x]*Sin[(1/2)*b^2*Pi*x^2])/x^8, x]}
{Sin[Pi/2*b^2*x^2]*FresnelC[b*x]/x^7, x, 0, Int[(FresnelC[b*x]*Sin[(1/2)*b^2*Pi*x^2])/x^7, x]}
{Sin[Pi/2*b^2*x^2]*FresnelC[b*x]/x^6, x, 10, -((b^3*Pi)/(60*x^2)) - (b^3*Pi*Cos[b^2*Pi*x^2])/(24*x^2) - (b^2*Pi*Cos[(1/2)*b^2*Pi*x^2]*FresnelC[b*x])/(15*x^3) - (1/30)*b^5*Pi^3*FresnelC[b*x]^2 - (FresnelC[b*x]*Sin[(1/2)*b^2*Pi*x^2])/(5*x^5) + (b^4*Pi^2*FresnelC[b*x]*Sin[(1/2)*b^2*Pi*x^2])/(15*x) - (b*Sin[b^2*Pi*x^2])/(40*x^4) - (7/120)*b^5*Pi^2*SinIntegral[b^2*Pi*x^2]}
{Sin[Pi/2*b^2*x^2]*FresnelC[b*x]/x^5, x, 0, Int[(FresnelC[b*x]*Sin[(1/2)*b^2*Pi*x^2])/x^5, x]}
{Sin[Pi/2*b^2*x^2]*FresnelC[b*x]/x^4, x, 0, Int[(FresnelC[b*x]*Sin[(1/2)*b^2*Pi*x^2])/x^4, x]}
{Sin[Pi/2*b^2*x^2]*FresnelC[b*x]/x^3, x, 0, Int[(FresnelC[b*x]*Sin[(1/2)*b^2*Pi*x^2])/x^3, x]}
{Sin[Pi/2*b^2*x^2]*FresnelC[b*x]/x^2, x, 3, (1/2)*b*Pi*FresnelC[b*x]^2 - (FresnelC[b*x]*Sin[(1/2)*b^2*Pi*x^2])/x + (1/4)*b*SinIntegral[b^2*Pi*x^2]}
{Sin[Pi/2*b^2*x^2]*FresnelC[b*x]/x, x, 0, Int[(FresnelC[b*x]*Sin[(1/2)*b^2*Pi*x^2])/x, x]}
{Sin[Pi/2*b^2*x^2]*FresnelC[b*x], x, 0, Int[FresnelC[b*x]*Sin[(1/2)*b^2*Pi*x^2], x]}
{x*Sin[Pi/2*b^2*x^2]*FresnelC[b*x], x, 2, x/(2*b*Pi) - (Cos[(1/2)*b^2*Pi*x^2]*FresnelC[b*x])/(b^2*Pi) + FresnelC[Sqrt[2]*b*x]/(2*Sqrt[2]*b^2*Pi)}
{x^2*Sin[Pi/2*b^2*x^2]*FresnelC[b*x], x, 3, x^2/(4*b*Pi) - (x*Cos[(1/2)*b^2*Pi*x^2]*FresnelC[b*x])/(b^2*Pi) + FresnelC[b*x]^2/(2*b^3*Pi) + Sin[b^2*Pi*x^2]/(4*b^3*Pi^2)}
{x^3*Sin[Pi/2*b^2*x^2]*FresnelC[b*x], x, 5, x^3/(6*b*Pi) - (x^2*Cos[(1/2)*b^2*Pi*x^2]*FresnelC[b*x])/(b^2*Pi) - (5*FresnelS[Sqrt[2]*b*x])/(4*Sqrt[2]*b^4*Pi^2) + (2*FresnelC[b*x]*Sin[(1/2)*b^2*Pi*x^2])/(b^4*Pi^2) + (x*Sin[b^2*Pi*x^2])/(4*b^3*Pi^2)}
{x^4*Sin[Pi/2*b^2*x^2]*FresnelC[b*x], x, 0, Int[x^4*FresnelC[b*x]*Sin[(1/2)*b^2*Pi*x^2], x]}
{x^5*Sin[Pi/2*b^2*x^2]*FresnelC[b*x], x, 9, -((4*x)/(b^5*Pi^3)) + x^5/(10*b*Pi) + (11*x*Cos[b^2*Pi*x^2])/(8*b^5*Pi^3) + (8*Cos[(1/2)*b^2*Pi*x^2]*FresnelC[b*x])/(b^6*Pi^3) - (x^4*Cos[(1/2)*b^2*Pi*x^2]*FresnelC[b*x])/(b^2*Pi) - (43*FresnelC[Sqrt[2]*b*x])/(8*Sqrt[2]*b^6*Pi^3) + (4*x^2*FresnelC[b*x]*Sin[(1/2)*b^2*Pi*x^2])/(b^4*Pi^2) + (x^3*Sin[b^2*Pi*x^2])/(4*b^3*Pi^2)}
{x^6*Sin[Pi/2*b^2*x^2]*FresnelC[b*x], x, 10, -((15*x^2)/(4*b^5*Pi^3)) + x^6/(12*b*Pi) + (7*x^2*Cos[b^2*Pi*x^2])/(4*b^5*Pi^3) + (15*x*Cos[(1/2)*b^2*Pi*x^2]*FresnelC[b*x])/(b^6*Pi^3) - (x^5*Cos[(1/2)*b^2*Pi*x^2]*FresnelC[b*x])/(b^2*Pi) - (15*FresnelC[b*x]^2)/(2*b^7*Pi^3) + (5*x^3*FresnelC[b*x]*Sin[(1/2)*b^2*Pi*x^2])/(b^4*Pi^2) - (11*Sin[b^2*Pi*x^2])/(2*b^7*Pi^4) + (x^4*Sin[b^2*Pi*x^2])/(4*b^3*Pi^2)}
{x^7*Sin[Pi/2*b^2*x^2]*FresnelC[b*x], x, 14, -((4*x^3)/(b^5*Pi^3)) + x^7/(14*b*Pi) + (17*x^3*Cos[b^2*Pi*x^2])/(8*b^5*Pi^3) + (24*x^2*Cos[(1/2)*b^2*Pi*x^2]*FresnelC[b*x])/(b^6*Pi^3) - (x^6*Cos[(1/2)*b^2*Pi*x^2]*FresnelC[b*x])/(b^2*Pi) + (531*FresnelS[Sqrt[2]*b*x])/(16*Sqrt[2]*b^8*Pi^4) - (48*FresnelC[b*x]*Sin[(1/2)*b^2*Pi*x^2])/(b^8*Pi^4) + (6*x^4*FresnelC[b*x]*Sin[(1/2)*b^2*Pi*x^2])/(b^4*Pi^2) - (147*x*Sin[b^2*Pi*x^2])/(16*b^7*Pi^4) + (x^5*Sin[b^2*Pi*x^2])/(4*b^3*Pi^2)}
{x^8*Sin[Pi/2*b^2*x^2]*FresnelC[b*x], x, 0, Int[x^8*FresnelC[b*x]*Sin[(1/2)*b^2*Pi*x^2], x]}


(* ::Subsection::Closed:: *)
(*Integrands of the form x^m Cos[Pi/2 b^2 x^2] FresnelC[b x]^n*)


{Cos[Pi/2*b^2*x^2]*FresnelC[b*x]/x^10, x, 0, Int[(Cos[(1/2)*b^2*Pi*x^2]*FresnelC[b*x])/x^10, x]}
{Cos[Pi/2*b^2*x^2]*FresnelC[b*x]/x^9, x, 0, Int[(Cos[(1/2)*b^2*Pi*x^2]*FresnelC[b*x])/x^9, x]}
{Cos[Pi/2*b^2*x^2]*FresnelC[b*x]/x^8, x, 15, -(b/(84*x^6)) + (b^5*Pi^2)/(420*x^2) - (b*Cos[b^2*Pi*x^2])/(84*x^6) + (b^5*Pi^2*Cos[b^2*Pi*x^2])/(84*x^2) - (Cos[(1/2)*b^2*Pi*x^2]*FresnelC[b*x])/(7*x^7) + (b^4*Pi^2*Cos[(1/2)*b^2*Pi*x^2]*FresnelC[b*x])/(105*x^3) + (1/210)*b^7*Pi^4*FresnelC[b*x]^2 + (b^2*Pi*FresnelC[b*x]*Sin[(1/2)*b^2*Pi*x^2])/(35*x^5) - (b^6*Pi^3*FresnelC[b*x]*Sin[(1/2)*b^2*Pi*x^2])/(105*x) + (b^3*Pi*Sin[b^2*Pi*x^2])/(105*x^4) + (1/70)*b^7*Pi^3*SinIntegral[b^2*Pi*x^2]}
{Cos[Pi/2*b^2*x^2]*FresnelC[b*x]/x^7, x, 0, Int[(Cos[(1/2)*b^2*Pi*x^2]*FresnelC[b*x])/x^7, x]}
{Cos[Pi/2*b^2*x^2]*FresnelC[b*x]/x^6, x, 0, Int[(Cos[(1/2)*b^2*Pi*x^2]*FresnelC[b*x])/x^6, x]}
{Cos[Pi/2*b^2*x^2]*FresnelC[b*x]/x^5, x, 0, Int[(Cos[(1/2)*b^2*Pi*x^2]*FresnelC[b*x])/x^5, x]}
{Cos[Pi/2*b^2*x^2]*FresnelC[b*x]/x^4, x, 6, -(b/(12*x^2)) - (b*Cos[b^2*Pi*x^2])/(12*x^2) - (Cos[(1/2)*b^2*Pi*x^2]*FresnelC[b*x])/(3*x^3) - (1/6)*b^3*Pi^2*FresnelC[b*x]^2 + (b^2*Pi*FresnelC[b*x]*Sin[(1/2)*b^2*Pi*x^2])/(3*x) - (1/6)*b^3*Pi*SinIntegral[b^2*Pi*x^2]}
{Cos[Pi/2*b^2*x^2]*FresnelC[b*x]/x^3, x, 0, Int[(Cos[(1/2)*b^2*Pi*x^2]*FresnelC[b*x])/x^3, x]}
{Cos[Pi/2*b^2*x^2]*FresnelC[b*x]/x^2, x, 0, Int[(Cos[(1/2)*b^2*Pi*x^2]*FresnelC[b*x])/x^2, x]}
{Cos[Pi/2*b^2*x^2]*FresnelC[b*x]/x, x, 0, Int[(Cos[(1/2)*b^2*Pi*x^2]*FresnelC[b*x])/x, x]}
{Cos[Pi/2*b^2*x^2]*FresnelC[b*x], x, 1, FresnelC[b*x]^2/(2*b)}
{x*Cos[Pi/2*b^2*x^2]*FresnelC[b*x], x, 2, -(FresnelS[Sqrt[2]*b*x]/(2*Sqrt[2]*b^2*Pi)) + (FresnelC[b*x]*Sin[(1/2)*b^2*Pi*x^2])/(b^2*Pi)}
{x^2*Cos[Pi/2*b^2*x^2]*FresnelC[b*x], x, 0, Int[x^2*Cos[(1/2)*b^2*Pi*x^2]*FresnelC[b*x], x]}
{x^3*Cos[Pi/2*b^2*x^2]*FresnelC[b*x], x, 5, -(x/(b^3*Pi^2)) + (x*Cos[b^2*Pi*x^2])/(4*b^3*Pi^2) + (2*Cos[(1/2)*b^2*Pi*x^2]*FresnelC[b*x])/(b^4*Pi^2) - (5*FresnelC[Sqrt[2]*b*x])/(4*Sqrt[2]*b^4*Pi^2) + (x^2*FresnelC[b*x]*Sin[(1/2)*b^2*Pi*x^2])/(b^2*Pi)}
{x^4*Cos[Pi/2*b^2*x^2]*FresnelC[b*x], x, 6, -((3*x^2)/(4*b^3*Pi^2)) + (x^2*Cos[b^2*Pi*x^2])/(4*b^3*Pi^2) + (3*x*Cos[(1/2)*b^2*Pi*x^2]*FresnelC[b*x])/(b^4*Pi^2) - (3*FresnelC[b*x]^2)/(2*b^5*Pi^2) + (x^3*FresnelC[b*x]*Sin[(1/2)*b^2*Pi*x^2])/(b^2*Pi) - Sin[b^2*Pi*x^2]/(b^5*Pi^3)}
{x^5*Cos[Pi/2*b^2*x^2]*FresnelC[b*x], x, 9, -((2*x^3)/(3*b^3*Pi^2)) + (x^3*Cos[b^2*Pi*x^2])/(4*b^3*Pi^2) + (4*x^2*Cos[(1/2)*b^2*Pi*x^2]*FresnelC[b*x])/(b^4*Pi^2) + (43*FresnelS[Sqrt[2]*b*x])/(8*Sqrt[2]*b^6*Pi^3) - (8*FresnelC[b*x]*Sin[(1/2)*b^2*Pi*x^2])/(b^6*Pi^3) + (x^4*FresnelC[b*x]*Sin[(1/2)*b^2*Pi*x^2])/(b^2*Pi) - (11*x*Sin[b^2*Pi*x^2])/(8*b^5*Pi^3)}
{x^6*Cos[Pi/2*b^2*x^2]*FresnelC[b*x], x, 0, Int[x^6*Cos[(1/2)*b^2*Pi*x^2]*FresnelC[b*x], x]}
{x^7*Cos[Pi/2*b^2*x^2]*FresnelC[b*x], x, 14, (24*x)/(b^7*Pi^4) - (3*x^5)/(5*b^3*Pi^2) - (147*x*Cos[b^2*Pi*x^2])/(16*b^7*Pi^4) + (x^5*Cos[b^2*Pi*x^2])/(4*b^3*Pi^2) - (48*Cos[(1/2)*b^2*Pi*x^2]*FresnelC[b*x])/(b^8*Pi^4) + (6*x^4*Cos[(1/2)*b^2*Pi*x^2]*FresnelC[b*x])/(b^4*Pi^2) + (531*FresnelC[Sqrt[2]*b*x])/(16*Sqrt[2]*b^8*Pi^4) - (24*x^2*FresnelC[b*x]*Sin[(1/2)*b^2*Pi*x^2])/(b^6*Pi^3) + (x^6*FresnelC[b*x]*Sin[(1/2)*b^2*Pi*x^2])/(b^2*Pi) - (17*x^3*Sin[b^2*Pi*x^2])/(8*b^5*Pi^3)}
(* {x^8*Cos[Pi/2*b^2*x^2]*FresnelC[b*x], x, 20, (105*x^2)/(4*b^7*Pi^4) - (7*x^6)/(12*b^3*Pi^2) - (55*x^2*Cos[b^2*Pi*x^2])/(4*b^7*Pi^4) + (x^6*Cos[b^2*Pi*x^2])/(4*b^3*Pi^2) + (105*FresnelC[b*x]^2)/(2*b^9*Pi^4) - (x*FresnelC[b*x]*(7*(15 - b^4*Pi^2*x^4)*Cos[(1/2)*b^2*Pi*x^2] + b^2*Pi*x^2*(35 - b^4*Pi^2*x^4)*Sin[(1/2)*b^2*Pi*x^2]))/(b^8*Pi^4) + (40*Sin[b^2*Pi*x^2])/(b^9*Pi^5) - (5*x^4*Sin[b^2*Pi*x^2])/(2*b^5*Pi^3)} *)
