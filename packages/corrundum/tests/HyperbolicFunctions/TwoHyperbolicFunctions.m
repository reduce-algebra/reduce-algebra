(* ::Package:: *)

(* ::Title:: *)
(*Integration Problems Involving Two Hyperbolic Functions*)


(* ::Subsection::Closed:: *)
(*Integrands of the form Hyper[a+b x]^m Hyper[a+b x]^n*)


(* ::Subsubsection::Closed:: *)
(*Integrands of the form Cosh[a+b x]^m Sinh[a+b x]^n*)


(* Integrands of the form Cosh[a+b*x]^m*Sinh[a+b*x]^n where m and n are positive integers *)
{Cosh[a + b*x]*Sinh[a + b*x], x, 2, Sinh[a + b*x]^2/(2*b)}
{Cosh[a + b*x]*Sinh[a + b*x]^n, x, 2, Sinh[a + b*x]^(1 + n)/(b*(1 + n))}
{Cosh[a + b*x]^3*Sinh[a + b*x]^n, x, 3, Sinh[a + b*x]^(1 + n)/(b*(1 + n)) + Sinh[a + b*x]^(3 + n)/(b*(3 + n))}
{Cosh[a + b*x]^5*Sinh[a + b*x]^n, x, 3, Sinh[a + b*x]^(1 + n)/(b*(1 + n)) + (2*Sinh[a + b*x]^(3 + n))/(b*(3 + n)) + Sinh[a + b*x]^(5 + n)/(b*(5 + n))}

{Cosh[a + b*x]^m*Sinh[a + b*x], x, 2, Cosh[a + b*x]^(1 + m)/(b*(1 + m))}
{Cosh[a + b*x]^m*Sinh[a + b*x]^3, x, 3, -(Cosh[a + b*x]^(1 + m)/(b*(1 + m))) + Cosh[a + b*x]^(3 + m)/(b*(3 + m))}
{Cosh[a + b*x]^m*Sinh[a + b*x]^5, x, 3, Cosh[a + b*x]^(1 + m)/(b*(1 + m)) - (2*Cosh[a + b*x]^(3 + m))/(b*(3 + m)) + Cosh[a + b*x]^(5 + m)/(b*(5 + m))}

{Cosh[a + b*x]^2*Sinh[a + b*x]^2, x, 2, -(x/8) - (Cosh[a + b*x]*Sinh[a + b*x])/(8*b) + (Cosh[a + b*x]^3*Sinh[a + b*x])/(4*b)}
{Cosh[a + b*x]^2*Sinh[a + b*x]^4, x, 3, x/16 + (Cosh[a + b*x]*Sinh[a + b*x])/(16*b) - (Cosh[a + b*x]^3*Sinh[a + b*x])/(8*b) + (Cosh[a + b*x]^3*Sinh[a + b*x]^3)/(6*b)}
{Cosh[a + b*x]^2*Sinh[a + b*x]^6, x, 4, -((5*x)/128) - (5*Cosh[a + b*x]*Sinh[a + b*x])/(128*b) + (5*Cosh[a + b*x]^3*Sinh[a + b*x])/(64*b) - (5*Cosh[a + b*x]^3*Sinh[a + b*x]^3)/(48*b) + (Cosh[a + b*x]^3*Sinh[a + b*x]^5)/(8*b)}

{Cosh[a + b*x]^4*Sinh[a + b*x]^2, x, 3, -(x/16) - (Cosh[a + b*x]*Sinh[a + b*x])/(16*b) - (Cosh[a + b*x]^3*Sinh[a + b*x])/(24*b) + (Cosh[a + b*x]^5*Sinh[a + b*x])/(6*b)}
{Cosh[a + b*x]^4*Sinh[a + b*x]^4, x, 4, (3*x)/128 + (3*Cosh[a + b*x]*Sinh[a + b*x])/(128*b) + (Cosh[a + b*x]^3*Sinh[a + b*x])/(64*b) - (Cosh[a + b*x]^5*Sinh[a + b*x])/(16*b) + (Cosh[a + b*x]^5*Sinh[a + b*x]^3)/(8*b)}
{Cosh[a + b*x]^4*Sinh[a + b*x]^6, x, 5, -((3*x)/256) - (3*Cosh[a + b*x]*Sinh[a + b*x])/(256*b) - (Cosh[a + b*x]^3*Sinh[a + b*x])/(128*b) + (Cosh[a + b*x]^5*Sinh[a + b*x])/(32*b) - (Cosh[a + b*x]^5*Sinh[a + b*x]^3)/(16*b) + (Cosh[a + b*x]^5*Sinh[a + b*x]^5)/(10*b)}

{Cosh[a + b*x]^6*Sinh[a + b*x]^2, x, 4, -((5*x)/128) - (5*Cosh[a + b*x]*Sinh[a + b*x])/(128*b) - (5*Cosh[a + b*x]^3*Sinh[a + b*x])/(192*b) - (Cosh[a + b*x]^5*Sinh[a + b*x])/(48*b) + (Cosh[a + b*x]^7*Sinh[a + b*x])/(8*b)}
{Cosh[a + b*x]^6*Sinh[a + b*x]^4, x, 5, (3*x)/256 + (3*Cosh[a + b*x]*Sinh[a + b*x])/(256*b) + (Cosh[a + b*x]^3*Sinh[a + b*x])/(128*b) + (Cosh[a + b*x]^5*Sinh[a + b*x])/(160*b) - (3*Cosh[a + b*x]^7*Sinh[a + b*x])/(80*b) + (Cosh[a + b*x]^7*Sinh[a + b*x]^3)/(10*b)}
{Cosh[a + b*x]^6*Sinh[a + b*x]^6, x, 6, -((5*x)/1024) - (5*Cosh[a + b*x]*Sinh[a + b*x])/(1024*b) - (5*Cosh[a + b*x]^3*Sinh[a + b*x])/(1536*b) - (Cosh[a + b*x]^5*Sinh[a + b*x])/(384*b) + (Cosh[a + b*x]^7*Sinh[a + b*x])/(64*b) - (Cosh[a + b*x]^7*Sinh[a + b*x]^3)/(24*b) + (Cosh[a + b*x]^7*Sinh[a + b*x]^5)/(12*b)}


(* Integrands of the form Csch[a+b*x]^m*Sech[a+b*x]^n where m and n are positive integers *)
{Csch[a + b*x]*Sech[a + b*x], x, 1, Log[Tanh[a + b*x]]/b}
{Csch[a + b*x]*Sech[a + b*x]^2, x, 2, -(ArcCoth[Cosh[a + b*x]]/b) + Sech[a + b*x]/b}
{Csch[a + b*x]*Sech[a + b*x]^3, x, 3, Log[Tanh[a + b*x]]/b - Tanh[a + b*x]^2/(2*b)}
{Csch[a + b*x]*Sech[a + b*x]^4, x, 3, -(ArcCoth[Cosh[a + b*x]]/b) + Sech[a + b*x]/b + Sech[a + b*x]^3/(3*b)}
{Csch[a + b*x]*Sech[a + b*x]^5, x, 3, Log[Tanh[a + b*x]]/b - Tanh[a + b*x]^2/b + Tanh[a + b*x]^4/(4*b)}

{Csch[a + b*x]^2*Sech[a + b*x], x, 2, -(ArcTan[Sinh[a + b*x]]/b) - Csch[a + b*x]/b}
{Csch[a + b*x]^2*Sech[a + b*x]^2, x, 3, -(Coth[a + b*x]/b) - Tanh[a + b*x]/b}
{Csch[a + b*x]^2*Sech[a + b*x]^3, x, 3, -((3*ArcTan[Sinh[a + b*x]])/(2*b)) - (3*Csch[a + b*x])/(2*b) + (Csch[a + b*x]*Sech[a + b*x]^2)/(2*b)}
{Csch[a + b*x]^2*Sech[a + b*x]^4, x, 3, -(Coth[a + b*x]/b) - (2*Tanh[a + b*x])/b + Tanh[a + b*x]^3/(3*b)}
{Csch[a + b*x]^2*Sech[a + b*x]^5, x, 4, -((15*ArcTan[Sinh[a + b*x]])/(8*b)) - (15*Csch[a + b*x])/(8*b) + (5*Csch[a + b*x]*Sech[a + b*x]^2)/(8*b) + (Csch[a + b*x]*Sech[a + b*x]^4)/(4*b)}

{Csch[a + b*x]^3*Sech[a + b*x], x, 3, -(Coth[a + b*x]^2/(2*b)) + Log[Coth[a + b*x]]/b}
{Csch[a + b*x]^3*Sech[a + b*x]^2, x, 3, (3*ArcCoth[Cosh[a + b*x]])/(2*b) - (3*Sech[a + b*x])/(2*b) - (Csch[a + b*x]^2*Sech[a + b*x])/(2*b)}
{Csch[a + b*x]^3*Sech[a + b*x]^3, x, 3, -(Coth[a + b*x]^2/(2*b)) - (2*Log[Tanh[a + b*x]])/b + Tanh[a + b*x]^2/(2*b)}
{Csch[a + b*x]^3*Sech[a + b*x]^4, x, 4, (5*ArcCoth[Cosh[a + b*x]])/(2*b) - (5*Sech[a + b*x])/(2*b) - (5*Sech[a + b*x]^3)/(6*b) - (Csch[a + b*x]^2*Sech[a + b*x]^3)/(2*b)}
{Csch[a + b*x]^3*Sech[a + b*x]^5, x, 3, -(Coth[a + b*x]^2/(2*b)) - (3*Log[Tanh[a + b*x]])/b + (3*Tanh[a + b*x]^2)/(2*b) - Tanh[a + b*x]^4/(4*b)}

{Csch[a + b*x]^4*Sech[a + b*x], x, 3, ArcTan[Sinh[a + b*x]]/b + Csch[a + b*x]/b - Csch[a + b*x]^3/(3*b)}
{Csch[a + b*x]^4*Sech[a + b*x]^2, x, 3, (2*Coth[a + b*x])/b - Coth[a + b*x]^3/(3*b) + Tanh[a + b*x]/b}
{Csch[a + b*x]^4*Sech[a + b*x]^3, x, 4, (5*ArcTan[Sinh[a + b*x]])/(2*b) + (5*Csch[a + b*x])/(2*b) - (5*Csch[a + b*x]^3)/(6*b) + (Csch[a + b*x]^3*Sech[a + b*x]^2)/(2*b)}
{Csch[a + b*x]^4*Sech[a + b*x]^4, x, 3, (3*Coth[a + b*x])/b - Coth[a + b*x]^3/(3*b) + (3*Tanh[a + b*x])/b - Tanh[a + b*x]^3/(3*b)}
{Csch[a + b*x]^4*Sech[a + b*x]^5, x, 5, (35*ArcTan[Sinh[a + b*x]])/(8*b) + (35*Csch[a + b*x])/(8*b) - (35*Csch[a + b*x]^3)/(24*b) + (7*Csch[a + b*x]^3*Sech[a + b*x]^2)/(8*b) + (Csch[a + b*x]^3*Sech[a + b*x]^4)/(4*b)}

{Csch[a + b*x]^5*Sech[a + b*x], x, 3, Coth[a + b*x]^2/b - Coth[a + b*x]^4/(4*b) - Log[Coth[a + b*x]]/b}
{Csch[a + b*x]^5*Sech[a + b*x]^2, x, 4, -((15*ArcCoth[Cosh[a + b*x]])/(8*b)) + (15*Sech[a + b*x])/(8*b) + (5*Csch[a + b*x]^2*Sech[a + b*x])/(8*b) - (Csch[a + b*x]^4*Sech[a + b*x])/(4*b)}
{Csch[a + b*x]^5*Sech[a + b*x]^3, x, 3, (3*Coth[a + b*x]^2)/(2*b) - Coth[a + b*x]^4/(4*b) - (3*Log[Coth[a + b*x]])/b - Tanh[a + b*x]^2/(2*b)}
{Csch[a + b*x]^5*Sech[a + b*x]^4, x, 5, -((35*ArcCoth[Cosh[a + b*x]])/(8*b)) + (35*Sech[a + b*x])/(8*b) + (35*Sech[a + b*x]^3)/(24*b) + (7*Csch[a + b*x]^2*Sech[a + b*x]^3)/(8*b) - (Csch[a + b*x]^4*Sech[a + b*x]^3)/(4*b)}
{Csch[a + b*x]^5*Sech[a + b*x]^5, x, 3, (2*Coth[a + b*x]^2)/b - Coth[a + b*x]^4/(4*b) + (6*Log[Tanh[a + b*x]])/b - (2*Tanh[a + b*x]^2)/b + Tanh[a + b*x]^4/(4*b)}


{Sqrt[Sinh[a + b*x]]/Sqrt[Cosh[a + b*x]], x, 4, -(ArcTan[Sqrt[Sinh[a + b*x]]/Sqrt[Cosh[a + b*x]]]/b) + ArcTanh[Sqrt[Sinh[a + b*x]]/Sqrt[Cosh[a + b*x]]]/b}
{Sqrt[Cosh[a + b*x]]/Sqrt[Sinh[a + b*x]], x, 4, -(ArcTan[Sqrt[Cosh[a + b*x]]/Sqrt[Sinh[a + b*x]]]/b) + ArcTanh[Sqrt[Cosh[a + b*x]]/Sqrt[Sinh[a + b*x]]]/b}

{Sinh[a + b*x]^(1/3)/Cosh[a + b*x]^(1/3), x, 6, -((Sqrt[3]*ArcTan[(1 + (2*Sinh[a + b*x]^(2/3))/Cosh[a + b*x]^(2/3))/Sqrt[3]])/(2*b)) - Log[1 - Sinh[a + b*x]^(2/3)/Cosh[a + b*x]^(2/3)]/(2*b) + Log[1 + Sinh[a + b*x]^(2/3)/Cosh[a + b*x]^(2/3) + Sinh[a + b*x]^(4/3)/Cosh[a + b*x]^(4/3)]/(4*b)}
{Cosh[a + b*x]^(1/3)/Sinh[a + b*x]^(1/3), x, 6, -((Sqrt[3]*ArcTan[(1 + (2*Cosh[a + b*x]^(2/3))/Sinh[a + b*x]^(2/3))/Sqrt[3]])/(2*b)) - Log[1 - Cosh[a + b*x]^(2/3)/Sinh[a + b*x]^(2/3)]/(2*b) + Log[1 + Cosh[a + b*x]^(4/3)/Sinh[a + b*x]^(4/3) + Cosh[a + b*x]^(2/3)/Sinh[a + b*x]^(2/3)]/(4*b)}

{Cosh[x]^(2/3)/Sinh[x]^(8/3), x, 1, -((3*Cosh[x]^(5/3))/(5*Sinh[x]^(5/3)))}
{Sinh[x]^(2/3)/Cosh[x]^(8/3), x, 1, (3*Sinh[x]^(5/3))/(5*Cosh[x]^(5/3))}

{Cosh[x]*Csch[x]^(7/3), x, 2, (-3*Csch[x]^(4/3))/4}


(* ::Subsubsection::Closed:: *)
(*Integrands of the form Hyper[a+b x]^m Tanh[a+b x]^n*)


(* Integrands of the form Sinh[a+b*x]^m*Tanh[a+b*x]^n where m and n are positive integers *)
{Sinh[a + b*x]*Tanh[a + b*x], x, 2, -(ArcTan[Sinh[a + b*x]]/b) + Sinh[a + b*x]/b}
{Sinh[a + b*x]*Tanh[a + b*x]^2, x, 3, Cosh[a + b*x]/b + Sech[a + b*x]/b}
{Sinh[a + b*x]*Tanh[a + b*x]^3, x, 3, -((3*ArcTan[Sinh[a + b*x]])/(2*b)) + (3*Sinh[a + b*x])/(2*b) - (Sinh[a + b*x]*Tanh[a + b*x]^2)/(2*b)}
{Sinh[a + b*x]*Tanh[a + b*x]^4, x, 3, Cosh[a + b*x]/b + (2*Sech[a + b*x])/b - Sech[a + b*x]^3/(3*b)}

{Sinh[a + b*x]^2*Tanh[a + b*x], x, 3, Cosh[a + b*x]^2/(2*b) - Log[Cosh[a + b*x]]/b}
{Sinh[a + b*x]^2*Tanh[a + b*x]^2, x, 2, -((3*x)/2) + (3*Tanh[a + b*x])/(2*b) + (Sinh[a + b*x]^2*Tanh[a + b*x])/(2*b)}
{Sinh[a + b*x]^2*Tanh[a + b*x]^3, x, 3, Cosh[a + b*x]^2/(2*b) - (2*Log[Cosh[a + b*x]])/b - Sech[a + b*x]^2/(2*b)}

{Sinh[a + b*x]^3*Tanh[a + b*x], x, 3, ArcTan[Sinh[a + b*x]]/b - Sinh[a + b*x]/b + Sinh[a + b*x]^3/(3*b)}
{Sinh[a + b*x]^3*Tanh[a + b*x]^2, x, 3, -((2*Cosh[a + b*x])/b) + Cosh[a + b*x]^3/(3*b) - Sech[a + b*x]/b}
{Sinh[a + b*x]^3*Tanh[a + b*x]^3, x, 4, (5*ArcTan[Sinh[a + b*x]])/(2*b) - (5*Sinh[a + b*x])/(2*b) + (5*Sinh[a + b*x]*Tanh[a + b*x]^2)/(6*b) + (Sinh[a + b*x]^3*Tanh[a + b*x]^2)/(3*b)}

{Sinh[a + b*x]^4*Tanh[a + b*x], x, 3, -(Cosh[a + b*x]^2/b) + Cosh[a + b*x]^4/(4*b) + Log[Cosh[a + b*x]]/b}


(* Integrands of the form Sech[a+b*x]^m*Tanh[a+b*x]^n where m and n are positive integers *)
{Sech[a + b*x]*Tanh[a + b*x], x, 1, -Sech[a + b*x]/b}
{Sech[a + b*x]^2*Tanh[a + b*x], x, 1, -Sech[a + b*x]^2/(2*b)}
{Sech[a + b*x]^n*Tanh[a + b*x], x, 2, -Sech[a + b*x]^n/(b*n)}

{Sech[a + b*x]^2*Tanh[a + b*x]^2, x, 2, Tanh[a + b*x]^3/(3*b)}
{Sech[a + b*x]^2*Tanh[a + b*x]^3, x, 2, Tanh[a + b*x]^4/(4*b)}
{Sech[a + b*x]^2*Tanh[a + b*x]^n, x, 2, Tanh[a + b*x]^(1 + n)/(b*(1 + n))}

{Sech[a + b*x]*Tanh[a + b*x]^3, x, 2, -(Sech[a + b*x]/b) + Sech[a + b*x]^3/(3*b)}
{Sech[a + b*x]^3*Tanh[a + b*x]^3, x, 3, -(Sech[a + b*x]^3/(3*b)) + Sech[a + b*x]^5/(5*b)}
{Sech[a + b*x]^n*Tanh[a + b*x]^3, x, 5, -(Sech[a + b*x]^n/(b*n)) + Sech[a + b*x]^(2 + n)/(b*(2 + n))}

{Sech[a + b*x]^4*Tanh[a + b*x]^2, x, 3, Tanh[a + b*x]^3/(3*b) - Tanh[a + b*x]^5/(5*b)}
{Sech[a + b*x]^4*Sqrt[Tanh[a + b*x]], x, 3, (2*Tanh[a + b*x]^(3/2))/(3*b) - (2*Tanh[a + b*x]^(7/2))/(7*b)}
{Sech[a + b*x]^4*Tanh[a + b*x]^n, x, 3, Tanh[a + b*x]^(1 + n)/(b*(1 + n)) - Tanh[a + b*x]^(3 + n)/(b*(3 + n))}

{Sech[a + b*x]*Tanh[a + b*x]^2, x, 2, ArcTan[Sinh[a + b*x]]/(2*b) - (Sech[a + b*x]*Tanh[a + b*x])/(2*b)}
{Sech[a + b*x]*Tanh[a + b*x]^4, x, 3, (3*ArcTan[Sinh[a + b*x]])/(8*b) - (3*Sech[a + b*x]*Tanh[a + b*x])/(8*b) - (Sech[a + b*x]*Tanh[a + b*x]^3)/(4*b)}

{Sech[a + b*x]^3*Tanh[a + b*x]^2, x, 3, ArcTan[Sinh[a + b*x]]/(8*b) - (Sech[a + b*x]*Tanh[a + b*x])/(8*b) + (Sech[a + b*x]*Tanh[a + b*x]^3)/(4*b)}

{Sech[x]*Tanh[x]^5, x, 3, -Sech[x] + (2*Sech[x]^3)/3 - Sech[x]^5/5}
{Sech[x]^7*Tanh[x]^5, x, 3, (-(1/7))*Sech[x]^7 + (2*Sech[x]^9)/9 - Sech[x]^11/11}
{Sech[x]^3*Tanh[x]^4, x, 4, (1/16)*ArcTan[Sinh[x]] - (1/16)*Sech[x]*Tanh[x] - (1/24)*Sech[x]*Tanh[x]^3 + (1/6)*Sech[x]*Tanh[x]^5}
{Sech[x]^5*Tanh[x]^2, x, 4, (1/16)*ArcTan[Sinh[x]] - (1/16)*Sech[x]*Tanh[x] + (1/8)*Sech[x]*Tanh[x]^3 + (1/6)*Sech[x]^3*Tanh[x]^3}
{Sech[x]^8*Tanh[x]^6, x, 3, Tanh[x]^7/7 - Tanh[x]^9/3 + (3*Tanh[x]^11)/11 - Tanh[x]^13/13}


(* ::Subsubsection::Closed:: *)
(*Integrands of the form Hyper[a+b x]^m Coth[a+b x]^n*)


(* Integrands of the form Cosh[a+b*x]^m*Coth[a+b*x]^n where m and n are positive integers *)
{Cosh[a + b*x]*Coth[a + b*x], x, 2, -(ArcCoth[Cosh[a + b*x]]/b) + Cosh[a + b*x]/b}
{Cosh[a + b*x]*Coth[a + b*x]^2, x, 3, -(Csch[a + b*x]/b) + Sinh[a + b*x]/b}
{Cosh[a + b*x]*Coth[a + b*x]^3, x, 3, -((3*ArcCoth[Cosh[a + b*x]])/(2*b)) + (3*Cosh[a + b*x])/(2*b) - (Cosh[a + b*x]*Coth[a + b*x]^2)/(2*b)}
{Cosh[a + b*x]*Coth[a + b*x]^4, x, 3, -((2*Csch[a + b*x])/b) - Csch[a + b*x]^3/(3*b) + Sinh[a + b*x]/b}

{Cosh[a + b*x]^2*Coth[a + b*x], x, 3, Log[Sinh[a + b*x]]/b + Sinh[a + b*x]^2/(2*b)}
{Cosh[a + b*x]^2*Coth[a + b*x]^2, x, 2, (3*x)/2 - (3*Coth[a + b*x])/(2*b) + (Cosh[a + b*x]^2*Coth[a + b*x])/(2*b)}
{Cosh[a + b*x]^2*Coth[a + b*x]^3, x, 3, -(Csch[a + b*x]^2/(2*b)) + (2*Log[Sinh[a + b*x]])/b + Sinh[a + b*x]^2/(2*b)}

{Cosh[a + b*x]^3*Coth[a + b*x], x, 3, -(ArcCoth[Cosh[a + b*x]]/b) + Cosh[a + b*x]/b + Cosh[a + b*x]^3/(3*b)}
{Cosh[a + b*x]^3*Coth[a + b*x]^2, x, 3, -(Csch[a + b*x]/b) + (2*Sinh[a + b*x])/b + Sinh[a + b*x]^3/(3*b)}
{Cosh[a + b*x]^3*Coth[a + b*x]^3, x, 4, -((5*ArcCoth[Cosh[a + b*x]])/(2*b)) + (5*Cosh[a + b*x])/(2*b) - (5*Cosh[a + b*x]*Coth[a + b*x]^2)/(6*b) + (Cosh[a + b*x]^3*Coth[a + b*x]^2)/(3*b)}

{Cosh[a + b*x]^4*Coth[a + b*x], x, 3, Log[Sinh[a + b*x]]/b + Sinh[a + b*x]^2/b + Sinh[a + b*x]^4/(4*b)}


(* Integrands of the form Coth[a+b*x]^m*Csch[a+b*x]^n where m and n are positive integers *)
{Coth[a + b*x]*Csch[a + b*x], x, 1, -(Csch[a + b*x]/b)}
{Coth[a + b*x]*Csch[a + b*x]^2, x, 1, -Csch[a + b*x]^2/(2*b)}
{Coth[a + b*x]*Csch[a + b*x]^n, x, 2, -Csch[a + b*x]^n/(b*n)}

{Coth[a + b*x]^2*Csch[a + b*x]^2, x, 2, -Coth[a + b*x]^3/(3*b)}
{Coth[a + b*x]^3*Csch[a + b*x]^2, x, 2, -Coth[a + b*x]^4/(4*b)}
{Coth[a + b*x]^n*Csch[a + b*x]^2, x, 2, -Coth[a + b*x]^(1 + n)/(b*(1 + n))}

{Coth[a + b*x]^3*Csch[a + b*x], x, 2, -(Csch[a + b*x]/b) - Csch[a + b*x]^3/(3*b)}
{Coth[a + b*x]^3*Csch[a + b*x]^3, x, 3, -(Csch[a + b*x]^3/(3*b)) - Csch[a + b*x]^5/(5*b)}
{Coth[a + b*x]^3*Csch[a + b*x]^n, x, 5, -(Csch[a + b*x]^n/(b*n)) - Csch[a + b*x]^(2 + n)/(b*(2 + n))}

{Coth[a + b*x]^2*Csch[a + b*x], x, 2, -(ArcCoth[Cosh[a + b*x]]/(2*b)) - (Coth[a + b*x]*Csch[a + b*x])/(2*b)}
{Coth[a + b*x]^2*Csch[a + b*x]^3, x, 3, ArcCoth[Cosh[a + b*x]]/(8*b) + (Coth[a + b*x]*Csch[a + b*x])/(8*b) - (Coth[a + b*x]^3*Csch[a + b*x])/(4*b)}

{Coth[a + b*x]^4*Csch[a + b*x], x, 3, -((3*ArcCoth[Cosh[a + b*x]])/(8*b)) - (3*Coth[a + b*x]*Csch[a + b*x])/(8*b) - (Coth[a + b*x]^3*Csch[a + b*x])/(4*b)}

{Coth[x]^2*Csch[x]^4, x, 3, Coth[x]^3/3 - Coth[x]^5/5}
{Coth[x]^3*Csch[x]^4, x, 3, Coth[x]^4/4 - Coth[x]^6/6}
{Coth[x]^n*Csch[x]^4, x, 3, Coth[x]^(1 + n)/(1 + n) - Coth[x]^(3 + n)/(3 + n)}

{Coth[x]^4*Csch[x]^3, x, 4, (1/16)*ArcCoth[Cosh[x]] + (1/16)*Coth[x]*Csch[x] + (1/24)*Coth[x]^3*Csch[x] - (1/6)*Coth[x]^5*Csch[x]}
{Coth[x]^4*Csch[x]^6, x, 3, (-(1/5))*Coth[x]^5 + (2*Coth[x]^7)/7 - Coth[x]^9/9}
{Coth[6*x]^5*Csch[6*x], x, 3, (-(1/6))*Csch[6*x] - (1/9)*Csch[6*x]^3 - (1/30)*Csch[6*x]^5}
{Coth[x]^7*Csch[x]^3, x, 3, (-(1/3))*Csch[x]^3 - (3*Csch[x]^5)/5 - (3*Csch[x]^7)/7 - Csch[x]^9/9}


(* ::Subsection::Closed:: *)
(*Integrands of the form Hyper[a+b x]^m Hyper[c+d x]^n*)


(* Integrands of the form Sinh[a+b*x]^m*Sinh[c+d*x]^n where m and n are positive integers *)
{Sinh[a + b*x]*Sinh[c + d*x], x, 3, -(Sinh[a - c + (b - d)*x]/(2*(b - d))) + Sinh[a + c + (b + d)*x]/(2*(b + d))}
{Sinh[a + b*x]*Sinh[c + d*x]^2, x, 5, -(Cosh[a + b*x]/(2*b)) + Cosh[a - 2*c + (b - 2*d)*x]/(4*(b - 2*d)) + Cosh[a + 2*c + (b + 2*d)*x]/(4*(b + 2*d))}
{Sinh[a + b*x]*Sinh[c + d*x]^3, x, 6, -(Sinh[a - 3*c + (b - 3*d)*x]/(8*(b - 3*d))) + (3*Sinh[a - c + (b - d)*x])/(8*(b - d)) - (3*Sinh[a + c + (b + d)*x])/(8*(b + d)) + Sinh[a + 3*c + (b + 3*d)*x]/(8*(b + 3*d))}

{Sinh[a + b*x]^2*Sinh[c + d*x]^2, x, 6, x/4 - Sinh[2*a + 2*b*x]/(8*b) + Sinh[2*a - 2*c + 2*(b - d)*x]/(16*(b - d)) - Sinh[2*c + 2*d*x]/(8*d) + Sinh[2*a + 2*c + 2*(b + d)*x]/(16*(b + d))}
{Sinh[a + b*x]^2*Sinh[c + d*x]^3, x, 8, -(Cosh[2*a - 3*c + (2*b - 3*d)*x]/(16*(2*b - 3*d))) + (3*Cosh[2*a - c + (2*b - d)*x])/(16*(2*b - d)) + (3*Cosh[c + d*x])/(8*d) - Cosh[3*c + 3*d*x]/(24*d) - (3*Cosh[2*a + c + (2*b + d)*x])/(16*(2*b + d)) + Cosh[2*a + 3*c + (2*b + 3*d)*x]/(16*(2*b + 3*d))}

{Sinh[a + b*x]^3*Sinh[c + d*x]^3, x, 10, (3*Sinh[a - 3*c + (b - 3*d)*x])/(32*(b - 3*d)) - (9*Sinh[a - c + (b - d)*x])/(32*(b - d)) - Sinh[3*a - 3*c + 3*(b - d)*x]/(96*(b - d)) + (3*Sinh[3*a - c + (3*b - d)*x])/(32*(3*b - d)) + (9*Sinh[a + c + (b + d)*x])/(32*(b + d)) + Sinh[3*a + 3*c + 3*(b + d)*x]/(96*(b + d)) - (3*Sinh[3*a + c + (3*b + d)*x])/(32*(3*b + d)) - (3*Sinh[a + 3*c + (b + 3*d)*x])/(32*(b + 3*d))}


(* Integrands of the form Cosh[a+b*x]^m*Cosh[c+d*x]^n where m and n are positive integers *)
{Cosh[a + b*x]*Cosh[c + d*x], x, 3, Sinh[a - c + (b - d)*x]/(2*(b - d)) + Sinh[a + c + (b + d)*x]/(2*(b + d))}
{Cosh[a + b*x]*Cosh[c + d*x]^2, x, 5, Sinh[a + b*x]/(2*b) + Sinh[a - 2*c + (b - 2*d)*x]/(4*(b - 2*d)) + Sinh[a + 2*c + (b + 2*d)*x]/(4*(b + 2*d))}
{Cosh[a + b*x]*Cosh[c + d*x]^3, x, 6, Sinh[a - 3*c + (b - 3*d)*x]/(8*(b - 3*d)) + (3*Sinh[a - c + (b - d)*x])/(8*(b - d)) + (3*Sinh[a + c + (b + d)*x])/(8*(b + d)) + Sinh[a + 3*c + (b + 3*d)*x]/(8*(b + 3*d))}

{Cosh[a + b*x]^2*Cosh[c + d*x]^2, x, 6, x/4 + Sinh[2*a + 2*b*x]/(8*b) + Sinh[2*a - 2*c + 2*(b - d)*x]/(16*(b - d)) + Sinh[2*c + 2*d*x]/(8*d) + Sinh[2*a + 2*c + 2*(b + d)*x]/(16*(b + d))}
{Cosh[a + b*x]^2*Cosh[c + d*x]^3, x, 8, Sinh[2*a - 3*c + (2*b - 3*d)*x]/(16*(2*b - 3*d)) + (3*Sinh[2*a - c + (2*b - d)*x])/(16*(2*b - d)) + (3*Sinh[c + d*x])/(8*d) + Sinh[3*c + 3*d*x]/(24*d) + (3*Sinh[2*a + c + (2*b + d)*x])/(16*(2*b + d)) + Sinh[2*a + 3*c + (2*b + 3*d)*x]/(16*(2*b + 3*d))}

{Cosh[a + b*x]^3*Cosh[c + d*x]^3, x, 10, (3*Sinh[a - 3*c + (b - 3*d)*x])/(32*(b - 3*d)) + (9*Sinh[a - c + (b - d)*x])/(32*(b - d)) + Sinh[3*a - 3*c + 3*(b - d)*x]/(96*(b - d)) + (3*Sinh[3*a - c + (3*b - d)*x])/(32*(3*b - d)) + (9*Sinh[a + c + (b + d)*x])/(32*(b + d)) + Sinh[3*a + 3*c + 3*(b + d)*x]/(96*(b + d)) + (3*Sinh[3*a + c + (3*b + d)*x])/(32*(3*b + d)) + (3*Sinh[a + 3*c + (b + 3*d)*x])/(32*(b + 3*d))}


(* Integrands of the form Sinh[a+b*x]^m*Cosh[c+d*x]^n where m and n are positive integers *)
{Sinh[a + b*x]*Cosh[c + d*x], x, 3, Cosh[a - c + (b - d)*x]/(2*(b - d)) + Cosh[a + c + (b + d)*x]/(2*(b + d))}
{Sinh[a + b*x]*Cosh[c + d*x]^2, x, 5, Cosh[a + b*x]/(2*b) + Cosh[a - 2*c + (b - 2*d)*x]/(4*(b - 2*d)) + Cosh[a + 2*c + (b + 2*d)*x]/(4*(b + 2*d))}
{Sinh[a + b*x]*Cosh[c + d*x]^3, x, 6, Cosh[a - 3*c + (b - 3*d)*x]/(8*(b - 3*d)) + (3*Cosh[a - c + (b - d)*x])/(8*(b - d)) + (3*Cosh[a + c + (b + d)*x])/(8*(b + d)) + Cosh[a + 3*c + (b + 3*d)*x]/(8*(b + 3*d))}

{Sinh[a + b*x]^2*Cosh[c + d*x], x, 5, Sinh[2*a - c + (2*b - d)*x]/(4*(2*b - d)) - Sinh[c + d*x]/(2*d) + Sinh[2*a + c + (2*b + d)*x]/(4*(2*b + d))}
{Sinh[a + b*x]^2*Cosh[c + d*x]^2, x, 6, -(x/4) + Sinh[2*a + 2*b*x]/(8*b) + Sinh[2*a - 2*c + 2*(b - d)*x]/(16*(b - d)) - Sinh[2*c + 2*d*x]/(8*d) + Sinh[2*a + 2*c + 2*(b + d)*x]/(16*(b + d))}
{Sinh[a + b*x]^2*Cosh[c + d*x]^3, x, 8, Sinh[2*a - 3*c + (2*b - 3*d)*x]/(16*(2*b - 3*d)) + (3*Sinh[2*a - c + (2*b - d)*x])/(16*(2*b - d)) - (3*Sinh[c + d*x])/(8*d) - Sinh[3*c + 3*d*x]/(24*d) + (3*Sinh[2*a + c + (2*b + d)*x])/(16*(2*b + d)) + Sinh[2*a + 3*c + (2*b + 3*d)*x]/(16*(2*b + 3*d))}

{Sinh[a + b*x]^3*Cosh[c + d*x], x, 6, -((3*Cosh[a - c + (b - d)*x])/(8*(b - d))) + Cosh[3*a - c + (3*b - d)*x]/(8*(3*b - d)) - (3*Cosh[a + c + (b + d)*x])/(8*(b + d)) + Cosh[3*a + c + (3*b + d)*x]/(8*(3*b + d))}
{Sinh[a + b*x]^3*Cosh[c + d*x]^2, x, 8, -((3*Cosh[a + b*x])/(8*b)) + Cosh[3*a + 3*b*x]/(24*b) - (3*Cosh[a - 2*c + (b - 2*d)*x])/(16*(b - 2*d)) + Cosh[3*a - 2*c + (3*b - 2*d)*x]/(16*(3*b - 2*d)) - (3*Cosh[a + 2*c + (b + 2*d)*x])/(16*(b + 2*d)) + Cosh[3*a + 2*c + (3*b + 2*d)*x]/(16*(3*b + 2*d))}
{Sinh[a + b*x]^3*Cosh[c + d*x]^3, x, 10, -((3*Cosh[a - 3*c + (b - 3*d)*x])/(32*(b - 3*d))) - (9*Cosh[a - c + (b - d)*x])/(32*(b - d)) + Cosh[3*a - 3*c + 3*(b - d)*x]/(96*(b - d)) + (3*Cosh[3*a - c + (3*b - d)*x])/(32*(3*b - d)) - (9*Cosh[a + c + (b + d)*x])/(32*(b + d)) + Cosh[3*a + 3*c + 3*(b + d)*x]/(96*(b + d)) + (3*Cosh[3*a + c + (3*b + d)*x])/(32*(3*b + d)) - (3*Cosh[a + 3*c + (b + 3*d)*x])/(32*(b + 3*d))}


(* Integrands of the form Sinh[a+b*x]*Hyper[c+b*x]^n where n is a positive integer *)
{Sinh[a + b*x]*Tanh[c + b*x], x, 3, -((ArcTan[Sinh[c + b*x]]*Cosh[a - c])/b) + Sinh[a + b*x]/b}
{Sinh[a + b*x]*Tanh[c + b*x]^2, x, 5, Cosh[a + b*x]/b + (Cosh[a - c]*Sech[c + b*x])/b - (ArcTan[Sinh[c + b*x]]*Sinh[a - c])/b}
{Sinh[a + b*x]*Tanh[c + b*x]^3, x, 8, -((3*ArcTan[Sinh[c + b*x]]*Cosh[a - c])/(2*b)) + (Sech[c + b*x]*Sinh[a - c])/b + Sinh[a + b*x]/b + (Cosh[a - c]*Sech[c + b*x]*Tanh[c + b*x])/(2*b)}

{Sinh[a + b*x]*Coth[c + b*x], x, 3, -((ArcCoth[Cosh[c + b*x]]*Sinh[a - c])/b) + Sinh[a + b*x]/b}
{Sinh[a + b*x]*Coth[c + b*x]^2, x, 5, -((ArcCoth[Cosh[c + b*x]]*Cosh[a - c])/b) + Cosh[a + b*x]/b - (Csch[c + b*x]*Sinh[a - c])/b}
{Sinh[a + b*x]*Coth[c + b*x]^3, x, 8, -((Cosh[a - c]*Csch[c + b*x])/b) - (3*ArcCoth[Cosh[c + b*x]]*Sinh[a - c])/(2*b) - (Coth[c + b*x]*Csch[c + b*x]*Sinh[a - c])/(2*b) + Sinh[a + b*x]/b}

{Sinh[a + b*x]*Sech[c + b*x], x, 3, (Cosh[a - c]*Log[Cosh[c + b*x]])/b + x*Sinh[a - c]}
{Sinh[a + b*x]*Sech[c + b*x]^2, x, 3, -((Cosh[a - c]*Sech[c + b*x])/b) + (ArcTan[Sinh[c + b*x]]*Sinh[a - c])/b}
{Sinh[a + b*x]*Sech[c + b*x]^3, x, 3, -((Cosh[a - c]*Sech[c + b*x]^2)/(2*b)) + (Sinh[a - c]*Tanh[c + b*x])/b}

{Sinh[a + b*x]*Csch[c + b*x], x, 3, x*Cosh[a - c] + (Log[Sinh[c + b*x]]*Sinh[a - c])/b}
{Sinh[a + b*x]*Csch[c + b*x]^2, x, 3, -((ArcCoth[Cosh[c + b*x]]*Cosh[a - c])/b) - (Csch[c + b*x]*Sinh[a - c])/b}
{Sinh[a + b*x]*Csch[c + b*x]^3, x, 3, -((Cosh[a - c]*Coth[c + b*x])/b) - (Csch[c + b*x]^2*Sinh[a - c])/(2*b)}


(* Integrands of the form Cosh[a+b*x]*Hyper[c+b*x]^n where n is a positive integer *)
{Cosh[a + b*x]*Tanh[c + b*x], x, 3, Cosh[a + b*x]/b - (ArcTan[Sinh[c + b*x]]*Sinh[a - c])/b}
{Cosh[a + b*x]*Tanh[c + b*x]^2, x, 5, -((ArcTan[Sinh[c + b*x]]*Cosh[a - c])/b) + (Sech[c + b*x]*Sinh[a - c])/b + Sinh[a + b*x]/b}
{Cosh[a + b*x]*Tanh[c + b*x]^3, x, 8, Cosh[a + b*x]/b + (Cosh[a - c]*Sech[c + b*x])/b - (3*ArcTan[Sinh[c + b*x]]*Sinh[a - c])/(2*b) + (Sech[c + b*x]*Sinh[a - c]*Tanh[c + b*x])/(2*b)}

{Cosh[a + b*x]*Coth[c + b*x], x, 3, -((ArcCoth[Cosh[c + b*x]]*Cosh[a - c])/b) + Cosh[a + b*x]/b}
{Cosh[a + b*x]*Coth[c + b*x]^2, x, 5, -((Cosh[a - c]*Csch[c + b*x])/b) - (ArcCoth[Cosh[c + b*x]]*Sinh[a - c])/b + Sinh[a + b*x]/b}
{Cosh[a + b*x]*Coth[c + b*x]^3, x, 8, -((3*ArcCoth[Cosh[c + b*x]]*Cosh[a - c])/(2*b)) + Cosh[a + b*x]/b - (Cosh[a - c]*Coth[c + b*x]*Csch[c + b*x])/(2*b) - (Csch[c + b*x]*Sinh[a - c])/b}

{Cosh[a + b*x]*Sech[c + b*x], x, 3, x*Cosh[a - c] + (Log[Cosh[c + b*x]]*Sinh[a - c])/b}
{Cosh[a + b*x]*Sech[c + b*x]^2, x, 3, (ArcTan[Sinh[c + b*x]]*Cosh[a - c])/b - (Sech[c + b*x]*Sinh[a - c])/b}
{Cosh[a + b*x]*Sech[c + b*x]^3, x, 3, -((Sech[c + b*x]^2*Sinh[a - c])/(2*b)) + (Cosh[a - c]*Tanh[c + b*x])/b}

{Cosh[a + b*x]*Csch[c + b*x], x, 3, (Cosh[a - c]*Log[Sinh[c + b*x]])/b + x*Sinh[a - c]}
{Cosh[a + b*x]*Csch[c + b*x]^2, x, 3, -((Cosh[a - c]*Csch[c + b*x])/b) - (ArcCoth[Cosh[c + b*x]]*Sinh[a - c])/b}
{Cosh[a + b*x]*Csch[c + b*x]^3, x, 3, -((Cosh[a - c]*Csch[c + b*x]^2)/(2*b)) - (Coth[c + b*x]*Sinh[a - c])/b}


(* ::Subsection::Closed:: *)
(*Integrands of the form x^m Hyper[a+b x]^n Hyper[a+ b x]^p*)


(* ::Subsubsection::Closed:: *)
(*Integrands of the form x^m Cosh[a+b x]^n Sinh[a+b x]^p*)


{Sinh[x]*Cosh[x]/x, x, 3, (1/2)*SinhIntegral[2*x]}
{Sinh[x]*Cosh[x]/x^2, x, 4, CoshIntegral[2*x] - Sinh[2*x]/(2*x)}
{Sinh[x]*Cosh[x]/x^3, x, 5, -(Cosh[2*x]/(2*x)) - Sinh[2*x]/(4*x^2) + SinhIntegral[2*x]}


(* Integrands of the form x^m*Sinh[a+b*x]^n*Cosh[a+b*x]^p where m, n and p are integers *)
{x*Sinh[a + b*x]*Cosh[a + b*x], x, 2, x/(4*b) - (Cosh[a + b*x]*Sinh[a + b*x])/(4*b^2) + (x*Sinh[a + b*x]^2)/(2*b)}
{x^2*Sinh[a + b*x]*Cosh[a + b*x], x, 3, x^2/(4*b) - (x*Cosh[a + b*x]*Sinh[a + b*x])/(2*b^2) + Sinh[a + b*x]^2/(4*b^3) + (x^2*Sinh[a + b*x]^2)/(2*b)}
{x^3*Sinh[a + b*x]*Cosh[a + b*x], x, 4, (3*x)/(8*b^3) + x^3/(4*b) - (3*Cosh[a + b*x]*Sinh[a + b*x])/(8*b^4) - (3*x^2*Cosh[a + b*x]*Sinh[a + b*x])/(4*b^2) + (3*x*Sinh[a + b*x]^2)/(4*b^3) + (x^3*Sinh[a + b*x]^2)/(2*b)}
{Sinh[a + b*x]*Cosh[a + b*x]/x, x, 5, (1/2)*CoshIntegral[2*b*x]*Sinh[2*a] + (1/2)*Cosh[2*a]*SinhIntegral[2*b*x]}
{Sinh[a + b*x]*Cosh[a + b*x]/x^2, x, 6, b*Cosh[2*a]*CoshIntegral[2*b*x] - Sinh[2*a + 2*b*x]/(2*x) + b*Sinh[2*a]*SinhIntegral[2*b*x]}
{Sinh[a + b*x]*Cosh[a + b*x]/x^3, x, 7, -((b*Cosh[2*a + 2*b*x])/(2*x)) + b^2*CoshIntegral[2*b*x]*Sinh[2*a] - Sinh[2*a + 2*b*x]/(4*x^2) + b^2*Cosh[2*a]*SinhIntegral[2*b*x]}

{x*Sinh[a + b*x]^2*Cosh[a + b*x], x, 3, Cosh[a + b*x]/(3*b^2) - Cosh[a + b*x]^3/(9*b^2) + (x*Sinh[a + b*x]^3)/(3*b)}
{x^2*Sinh[a + b*x]^2*Cosh[a + b*x], x, 4, (4*x*Cosh[a + b*x])/(9*b^2) - (4*Sinh[a + b*x])/(9*b^3) - (2*x*Cosh[a + b*x]*Sinh[a + b*x]^2)/(9*b^2) + (2*Sinh[a + b*x]^3)/(27*b^3) + (x^2*Sinh[a + b*x]^3)/(3*b)}
{x^3*Sinh[a + b*x]^2*Cosh[a + b*x], x, 7, (14*Cosh[a + b*x])/(9*b^4) + (2*x^2*Cosh[a + b*x])/(3*b^2) - (2*Cosh[a + b*x]^3)/(27*b^4) - (4*x*Sinh[a + b*x])/(3*b^3) - (x^2*Cosh[a + b*x]*Sinh[a + b*x]^2)/(3*b^2) + (2*x*Sinh[a + b*x]^3)/(9*b^3) + (x^3*Sinh[a + b*x]^3)/(3*b)}
{Sinh[a + b*x]^2*Cosh[a + b*x]/x, x, 8, (-(1/4))*Cosh[a]*CoshIntegral[b*x] + (1/4)*Cosh[3*a]*CoshIntegral[3*b*x] - (1/4)*Sinh[a]*SinhIntegral[b*x] + (1/4)*Sinh[3*a]*SinhIntegral[3*b*x]}
{Sinh[a + b*x]^2*Cosh[a + b*x]/x^2, x, 10, Cosh[a + b*x]/(4*x) - Cosh[3*a + 3*b*x]/(4*x) - (1/4)*b*CoshIntegral[b*x]*Sinh[a] + (3/4)*b*CoshIntegral[3*b*x]*Sinh[3*a] - (1/4)*b*Cosh[a]*SinhIntegral[b*x] + (3/4)*b*Cosh[3*a]*SinhIntegral[3*b*x]}
{Sinh[a + b*x]^2*Cosh[a + b*x]/x^3, x, 12, Cosh[a + b*x]/(8*x^2) - Cosh[3*a + 3*b*x]/(8*x^2) - (1/8)*b^2*Cosh[a]*CoshIntegral[b*x] + (9/8)*b^2*Cosh[3*a]*CoshIntegral[3*b*x] + (b*Sinh[a + b*x])/(8*x) - (3*b*Sinh[3*a + 3*b*x])/(8*x) - (1/8)*b^2*Sinh[a]*SinhIntegral[b*x] + (9/8)*b^2*Sinh[3*a]*SinhIntegral[3*b*x]}

{x*Sinh[a + b*x]*Cosh[a + b*x]^2, x, 3, (x*Cosh[a + b*x]^3)/(3*b) - Sinh[a + b*x]/(3*b^2) - Sinh[a + b*x]^3/(9*b^2)}
{x^2*Sinh[a + b*x]*Cosh[a + b*x]^2, x, 4, (4*Cosh[a + b*x])/(9*b^3) + (2*Cosh[a + b*x]^3)/(27*b^3) + (x^2*Cosh[a + b*x]^3)/(3*b) - (4*x*Sinh[a + b*x])/(9*b^2) - (2*x*Cosh[a + b*x]^2*Sinh[a + b*x])/(9*b^2)}
{x^3*Sinh[a + b*x]*Cosh[a + b*x]^2, x, 7, (4*x*Cosh[a + b*x])/(3*b^3) + (2*x*Cosh[a + b*x]^3)/(9*b^3) + (x^3*Cosh[a + b*x]^3)/(3*b) - (14*Sinh[a + b*x])/(9*b^4) - (2*x^2*Sinh[a + b*x])/(3*b^2) - (x^2*Cosh[a + b*x]^2*Sinh[a + b*x])/(3*b^2) - (2*Sinh[a + b*x]^3)/(27*b^4)}
{Sinh[a + b*x]*Cosh[a + b*x]^2/x, x, 8, (1/4)*CoshIntegral[b*x]*Sinh[a] + (1/4)*CoshIntegral[3*b*x]*Sinh[3*a] + (1/4)*Cosh[a]*SinhIntegral[b*x] + (1/4)*Cosh[3*a]*SinhIntegral[3*b*x]}
{Sinh[a + b*x]*Cosh[a + b*x]^2/x^2, x, 10, (1/4)*b*Cosh[a]*CoshIntegral[b*x] + (3/4)*b*Cosh[3*a]*CoshIntegral[3*b*x] - Sinh[a + b*x]/(4*x) - Sinh[3*a + 3*b*x]/(4*x) + (1/4)*b*Sinh[a]*SinhIntegral[b*x] + (3/4)*b*Sinh[3*a]*SinhIntegral[3*b*x]}
{Sinh[a + b*x]*Cosh[a + b*x]^2/x^3, x, 12, -((b*Cosh[a + b*x])/(8*x)) - (3*b*Cosh[3*a + 3*b*x])/(8*x) + (1/8)*b^2*CoshIntegral[b*x]*Sinh[a] + (9/8)*b^2*CoshIntegral[3*b*x]*Sinh[3*a] - Sinh[a + b*x]/(8*x^2) - Sinh[3*a + 3*b*x]/(8*x^2) + (1/8)*b^2*Cosh[a]*SinhIntegral[b*x] + (9/8)*b^2*Cosh[3*a]*SinhIntegral[3*b*x]}

{x*Sinh[a + b*x]^2*Cosh[a + b*x]^2, x, 5, -(x^2/16) - Cosh[4*a + 4*b*x]/(128*b^2) + (x*Sinh[4*a + 4*b*x])/(32*b)}
{x^2*Sinh[a + b*x]^2*Cosh[a + b*x]^2, x, 6, -(x^3/24) - (x*Cosh[4*a + 4*b*x])/(64*b^2) + Sinh[4*a + 4*b*x]/(256*b^3) + (x^2*Sinh[4*a + 4*b*x])/(32*b)}
{x^3*Sinh[a + b*x]^2*Cosh[a + b*x]^2, x, 7, -(x^4/32) - (3*Cosh[4*a + 4*b*x])/(1024*b^4) - (3*x^2*Cosh[4*a + 4*b*x])/(128*b^2) + (3*x*Sinh[4*a + 4*b*x])/(256*b^3) + (x^3*Sinh[4*a + 4*b*x])/(32*b)}
{Sinh[a + b*x]^2*Cosh[a + b*x]^2/x, x, 6, (1/8)*Cosh[4*a]*CoshIntegral[4*b*x] - Log[x]/8 + (1/8)*Sinh[4*a]*SinhIntegral[4*b*x]}
{Sinh[a + b*x]^2*Cosh[a + b*x]^2/x^2, x, 7, 1/(8*x) - Cosh[4*a + 4*b*x]/(8*x) + (1/2)*b*CoshIntegral[4*b*x]*Sinh[4*a] + (1/2)*b*Cosh[4*a]*SinhIntegral[4*b*x]}
{Sinh[a + b*x]^2*Cosh[a + b*x]^2/x^3, x, 8, 1/(16*x^2) - Cosh[4*a + 4*b*x]/(16*x^2) + b^2*Cosh[4*a]*CoshIntegral[4*b*x] - (b*Sinh[4*a + 4*b*x])/(4*x) + b^2*Sinh[4*a]*SinhIntegral[4*b*x]}


(* Integrands of the form x*Sinh[a+b*x]*Cosh[a+b*x]^n where n is a half-integer *)
{x*Sinh[a + b*x]*Cosh[a + b*x]^(3/2), x, 3, (2*x*Cosh[a + b*x]^(5/2))/(5*b) + (12*I*EllipticE[(1/2)*I*(a + b*x), 2])/(25*b^2) - (4*Cosh[a + b*x]^(3/2)*Sinh[a + b*x])/(25*b^2)}
{x*Sinh[a + b*x]*Sqrt[Cosh[a + b*x]], x, 3, (2*x*Cosh[a + b*x]^(3/2))/(3*b) + (4*I*EllipticF[(1/2)*I*(a + b*x), 2])/(9*b^2) - (4*Sqrt[Cosh[a + b*x]]*Sinh[a + b*x])/(9*b^2)}
{x*Sinh[a + b*x]/Sqrt[Cosh[a + b*x]], x, 2, (2*x*Sqrt[Cosh[a + b*x]])/b + (4*I*EllipticE[(1/2)*I*(a + b*x), 2])/b^2}
{x*Sinh[a + b*x]/Cosh[a + b*x]^(3/2), x, 2, -((2*x)/(b*Sqrt[Cosh[a + b*x]])) - (4*I*EllipticF[(1/2)*I*(a + b*x), 2])/b^2}
{x*Sinh[a + b*x]/Cosh[a + b*x]^(5/2), x, 3, -((2*x)/(3*b*Cosh[a + b*x]^(3/2))) + (4*I*EllipticE[(1/2)*I*(a + b*x), 2])/(3*b^2) + (4*Sinh[a + b*x])/(3*b^2*Sqrt[Cosh[a + b*x]])}


(* Integrands of the form x*Cosh[a+b*x]*Sinh[a+b*x]^n where n is a half-integer *)
{x*Cosh[a + b*x]*Sinh[a + b*x]^(3/2), x, 4, (12*I*EllipticE[Pi/4 - (1/2)*I*(a + b*x), 2]*Sqrt[Sinh[a + b*x]])/(25*b^2*Sqrt[I*Sinh[a + b*x]]) - (4*Cosh[a + b*x]*Sinh[a + b*x]^(3/2))/(25*b^2) + (2*x*Sinh[a + b*x]^(5/2))/(5*b)}
{x*Cosh[a + b*x]*Sqrt[Sinh[a + b*x]], x, 4, (4*I*EllipticF[Pi/4 - (1/2)*I*(a + b*x), 2]*Sqrt[I*Sinh[a + b*x]])/(9*b^2*Sqrt[Sinh[a + b*x]]) - (4*Cosh[a + b*x]*Sqrt[Sinh[a + b*x]])/(9*b^2) + (2*x*Sinh[a + b*x]^(3/2))/(3*b)}
{x*Cosh[a + b*x]/Sqrt[Sinh[a + b*x]], x, 3, (2*x*Sqrt[Sinh[a + b*x]])/b - (4*I*EllipticE[Pi/4 - (1/2)*I*(a + b*x), 2]*Sqrt[Sinh[a + b*x]])/(b^2*Sqrt[I*Sinh[a + b*x]])}
{x*Cosh[a + b*x]/Sinh[a + b*x]^(3/2), x, 3, -((2*x)/(b*Sqrt[Sinh[a + b*x]])) + (4*I*EllipticF[Pi/4 - (1/2)*I*(a + b*x), 2]*Sqrt[I*Sinh[a + b*x]])/(b^2*Sqrt[Sinh[a + b*x]])}
{x*Cosh[a + b*x]/Sinh[a + b*x]^(5/2), x, 4, -((2*x)/(3*b*Sinh[a + b*x]^(3/2))) - (4*Cosh[a + b*x])/(3*b^2*Sqrt[Sinh[a + b*x]]) + (4*I*EllipticE[Pi/4 - (1/2)*I*(a + b*x), 2]*Sqrt[Sinh[a + b*x]])/(3*b^2*Sqrt[I*Sinh[a + b*x]])}


(* ::Subsubsection::Closed:: *)
(*Integrands of the form x^m Sech[a+b x]^n Sinh[a+b x]^p*)


{x*Sinh[a + b*x]*Sech[a + b*x]^(9/2), x, 5, (12*I*Sqrt[Cosh[a + b*x]]*EllipticE[(1/2)*I*(a + b*x), 2]*Sqrt[Sech[a + b*x]])/(35*b^2) - (2*x*Sech[a + b*x]^(7/2))/(7*b) + (12*Sqrt[Sech[a + b*x]]*Sinh[a + b*x])/(35*b^2) + (4*Sech[a + b*x]^(5/2)*Sinh[a + b*x])/(35*b^2)}
{x*Sinh[a + b*x]*Sech[a + b*x]^(7/2), x, 4, -((4*I*Sqrt[Cosh[a + b*x]]*EllipticF[(1/2)*I*(a + b*x), 2]*Sqrt[Sech[a + b*x]])/(15*b^2)) - (2*x*Sech[a + b*x]^(5/2))/(5*b) + (4*Sech[a + b*x]^(3/2)*Sinh[a + b*x])/(15*b^2)}
{x*Sinh[a + b*x]*Sech[a + b*x]^(5/2), x, 4, (4*I*Sqrt[Cosh[a + b*x]]*EllipticE[(1/2)*I*(a + b*x), 2]*Sqrt[Sech[a + b*x]])/(3*b^2) - (2*x*Sech[a + b*x]^(3/2))/(3*b) + (4*Sqrt[Sech[a + b*x]]*Sinh[a + b*x])/(3*b^2)}
{x*Sinh[a + b*x]*Sech[a + b*x]^(3/2), x, 3, -((2*x*Sqrt[Sech[a + b*x]])/b) - (4*I*Sqrt[Cosh[a + b*x]]*EllipticF[(1/2)*I*(a + b*x), 2]*Sqrt[Sech[a + b*x]])/b^2}
{x*Sinh[a + b*x]*Sech[a + b*x]^(1/2), x, 3, (2*x)/(b*Sqrt[Sech[a + b*x]]) + (4*I*Sqrt[Cosh[a + b*x]]*EllipticE[(1/2)*I*(a + b*x), 2]*Sqrt[Sech[a + b*x]])/b^2}
{x*Sinh[a + b*x]/Sech[a + b*x]^(1/2), x, 4, (2*x)/(3*b*Sech[a + b*x]^(3/2)) + (4*I*Sqrt[Cosh[a + b*x]]*EllipticF[(1/2)*I*(a + b*x), 2]*Sqrt[Sech[a + b*x]])/(9*b^2) - (4*Sinh[a + b*x])/(9*b^2*Sqrt[Sech[a + b*x]])}
{x*Sinh[a + b*x]/Sech[a + b*x]^(3/2), x, 4, (2*x)/(5*b*Sech[a + b*x]^(5/2)) + (12*I*Sqrt[Cosh[a + b*x]]*EllipticE[(1/2)*I*(a + b*x), 2]*Sqrt[Sech[a + b*x]])/(25*b^2) - (4*Sinh[a + b*x])/(25*b^2*Sech[a + b*x]^(3/2))}
{x*Sinh[a + b*x]/Sech[a + b*x]^(5/2), x, 5, (2*x)/(7*b*Sech[a + b*x]^(7/2)) + (20*I*Sqrt[Cosh[a + b*x]]*EllipticF[(1/2)*I*(a + b*x), 2]*Sqrt[Sech[a + b*x]])/(147*b^2) - (4*Sinh[a + b*x])/(49*b^2*Sech[a + b*x]^(5/2)) - (20*Sinh[a + b*x])/(147*b^2*Sqrt[Sech[a + b*x]])}


(* ::Subsubsection::Closed:: *)
(*Integrands of the form x^m Cosh[a+b x]^n Csch[a+b x]^p*)


{x*Cosh[a + b*x]*Csch[a + b*x]^(9/2), x, 6, (12*Cosh[a + b*x]*Sqrt[Csch[a + b*x]])/(35*b^2) - (4*Cosh[a + b*x]*Csch[a + b*x]^(5/2))/(35*b^2) - (2*x*Csch[a + b*x]^(7/2))/(7*b) - (12*I*EllipticE[Pi/4 - (1/2)*I*(a + b*x), 2])/(35*b^2*Sqrt[Csch[a + b*x]]*Sqrt[I*Sinh[a + b*x]])}
{x*Cosh[a + b*x]*Csch[a + b*x]^(7/2), x, 5, -((4*Cosh[a + b*x]*Csch[a + b*x]^(3/2))/(15*b^2)) - (2*x*Csch[a + b*x]^(5/2))/(5*b) - (4*I*Sqrt[Csch[a + b*x]]*EllipticF[Pi/4 - (1/2)*I*(a + b*x), 2]*Sqrt[I*Sinh[a + b*x]])/(15*b^2)}
{x*Cosh[a + b*x]*Csch[a + b*x]^(5/2), x, 5, -((4*Cosh[a + b*x]*Sqrt[Csch[a + b*x]])/(3*b^2)) - (2*x*Csch[a + b*x]^(3/2))/(3*b) + (4*I*EllipticE[Pi/4 - (1/2)*I*(a + b*x), 2])/(3*b^2*Sqrt[Csch[a + b*x]]*Sqrt[I*Sinh[a + b*x]])}
{x*Cosh[a + b*x]*Csch[a + b*x]^(3/2), x, 4, -((2*x*Sqrt[Csch[a + b*x]])/b) + (4*I*Sqrt[Csch[a + b*x]]*EllipticF[Pi/4 - (1/2)*I*(a + b*x), 2]*Sqrt[I*Sinh[a + b*x]])/b^2}
{x*Cosh[a + b*x]*Csch[a + b*x]^(1/2), x, 4, (2*x)/(b*Sqrt[Csch[a + b*x]]) - (4*I*EllipticE[Pi/4 - (1/2)*I*(a + b*x), 2])/(b^2*Sqrt[Csch[a + b*x]]*Sqrt[I*Sinh[a + b*x]])}
{x*Cosh[a + b*x]/Csch[a + b*x]^(1/2), x, 5, (2*x)/(3*b*Csch[a + b*x]^(3/2)) - (4*Cosh[a + b*x])/(9*b^2*Sqrt[Csch[a + b*x]]) + (4*I*Sqrt[Csch[a + b*x]]*EllipticF[Pi/4 - (1/2)*I*(a + b*x), 2]*Sqrt[I*Sinh[a + b*x]])/(9*b^2)}
{x*Cosh[a + b*x]/Csch[a + b*x]^(3/2), x, 5, (2*x)/(5*b*Csch[a + b*x]^(5/2)) - (4*Cosh[a + b*x])/(25*b^2*Csch[a + b*x]^(3/2)) + (12*I*EllipticE[Pi/4 - (1/2)*I*(a + b*x), 2])/(25*b^2*Sqrt[Csch[a + b*x]]*Sqrt[I*Sinh[a + b*x]])}
{x*Cosh[a + b*x]/Csch[a + b*x]^(5/2), x, 6, (2*x)/(7*b*Csch[a + b*x]^(7/2)) - (4*Cosh[a + b*x])/(49*b^2*Csch[a + b*x]^(5/2)) + (20*Cosh[a + b*x])/(147*b^2*Sqrt[Csch[a + b*x]]) - (20*I*Sqrt[Csch[a + b*x]]*EllipticF[Pi/4 - (1/2)*I*(a + b*x), 2]*Sqrt[I*Sinh[a + b*x]])/(147*b^2)}


(* ::Subsubsection::Closed:: *)
(*Integrands of the form x^m Sech[a+b x]^n Tanh[a+b x]^p*)


(* Integrands of the form x^m*Sech[a+b*x]^n*Tanh[a+b*x] where m and n are integers *)
{x*Sech[a + b*x]*Tanh[a + b*x], x, 2, ArcTan[Sinh[a + b*x]]/b^2 - (x*Sech[a + b*x])/b}
{x^2*Sech[a + b*x]*Tanh[a + b*x], x, 5, (4*x*ArcTan[E^(a + b*x)])/b^2 - (2*I*PolyLog[2, (-I)*E^(a + b*x)])/b^3 + (2*I*PolyLog[2, I*E^(a + b*x)])/b^3 - (x^2*Sech[a + b*x])/b}
{x^3*Sech[a + b*x]*Tanh[a + b*x], x, 7, (6*x^2*ArcTan[E^(a + b*x)])/b^2 - (6*I*x*PolyLog[2, (-I)*E^(a + b*x)])/b^3 + (6*I*x*PolyLog[2, I*E^(a + b*x)])/b^3 + (6*I*PolyLog[3, (-I)*E^(a + b*x)])/b^4 - (6*I*PolyLog[3, I*E^(a + b*x)])/b^4 - (x^3*Sech[a + b*x])/b}
{Sech[a + b*x]*Tanh[a + b*x]/x, x, 0, Int[(Sech[a + b*x]*Tanh[a + b*x])/x, x]}

{x*Sech[a + b*x]^2*Tanh[a + b*x], x, 2, -((x*Sech[a + b*x]^2)/(2*b)) + Tanh[a + b*x]/(2*b^2)}
{x^2*Sech[a + b*x]^2*Tanh[a + b*x], x, 3, -(Log[Cosh[a + b*x]]/b^3) - (x^2*Sech[a + b*x]^2)/(2*b) + (x*Tanh[a + b*x])/b^2}
{x^3*Sech[a + b*x]^2*Tanh[a + b*x], x, 6, (3*x^2)/(2*b^2) - (3*x*Log[1 + E^(2*a + 2*b*x)])/b^3 - (3*PolyLog[2, -E^(2*a + 2*b*x)])/(2*b^4) - (x^3*Sech[a + b*x]^2)/(2*b) + (3*x^2*Tanh[a + b*x])/(2*b^2)}
{Sech[a + b*x]^2*Tanh[a + b*x]/x, x, 0, Int[(Sech[a + b*x]^2*Tanh[a + b*x])/x, x]}


(* ::Subsubsection::Closed:: *)
(*Integrands of the form x^m Csch[a+b x]^n Coth[a+b x]^p*)


(* Integrands of the form x^m*Csch[a+b*x]^n*Coth[a+b*x] where m and n are integers *)
{x^3*Csch[a + b*x]*Coth[a + b*x], x, 7, -((6*x^2*ArcTanh[E^(a + b*x)])/b^2) - (x^3*Csch[a + b*x])/b - (6*x*PolyLog[2, -E^(a + b*x)])/b^3 + (6*x*PolyLog[2, E^(a + b*x)])/b^3 + (6*PolyLog[3, -E^(a + b*x)])/b^4 - (6*PolyLog[3, E^(a + b*x)])/b^4}
{x^2*Csch[a + b*x]*Coth[a + b*x], x, 5, -((4*x*ArcTanh[E^(a + b*x)])/b^2) - (x^2*Csch[a + b*x])/b - (2*PolyLog[2, -E^(a + b*x)])/b^3 + (2*PolyLog[2, E^(a + b*x)])/b^3}
{x^1*Csch[a + b*x]*Coth[a + b*x], x, 2, -(ArcCoth[Cosh[a + b*x]]/b^2) - (x*Csch[a + b*x])/b}
{Csch[a + b*x]*Coth[a + b*x]/x^1, x, 0, Int[(Coth[a + b*x]*Csch[a + b*x])/x, x]}


{x^3*Csch[a + b*x]^2*Coth[a + b*x], x, 6, -((3*x^2)/(2*b^2)) - (3*x^2*Coth[a + b*x])/(2*b^2) - (x^3*Csch[a + b*x]^2)/(2*b) + (3*x*Log[1 - E^(2*a + 2*b*x)])/b^3 + (3*PolyLog[2, E^(2*a + 2*b*x)])/(2*b^4)}
{x^2*Csch[a + b*x]^2*Coth[a + b*x], x, 3, -((x*Coth[a + b*x])/b^2) - (x^2*Csch[a + b*x]^2)/(2*b) + Log[Sinh[a + b*x]]/b^3}
{x^1*Csch[a + b*x]^2*Coth[a + b*x], x, 2, -(Coth[a + b*x]/(2*b^2)) - (x*Csch[a + b*x]^2)/(2*b)}
{Csch[a + b*x]^2*Coth[a + b*x]/x^1, x, 0, Int[(Coth[a + b*x]*Csch[a + b*x]^2)/x, x]}


(* ::Subsubsection::Closed:: *)
(*Integrands of the form x^m Cosh[a+b x]^n Coth[a+b x]^p*)


(* Integrands of the form x^m*Cosh[x]^2*Coth[x]^m where m and n are integers *)
{x^1*Cosh[x]^2*Coth[x], x, 14, -(x^2/2) + (1/4)*x*Cosh[2*x] + x*Log[1 - E^(2*x)] + (1/2)*PolyLog[2, E^(2*x)] - (1/8)*Sinh[2*x]}
{x^2*Cosh[x]^2*Coth[x], x, 17, -(x^3/3) + (1/8)*Cosh[2*x] + (1/4)*x^2*Cosh[2*x] + x^2*Log[1 - E^(2*x)] + x*PolyLog[2, E^(2*x)] - (1/2)*PolyLog[3, E^(2*x)] - (1/4)*x*Sinh[2*x]}
{x^3*Cosh[x]^2*Coth[x], x, 20, -(x^4/4) + (3/8)*x*Cosh[2*x] + (1/4)*x^3*Cosh[2*x] + x^3*Log[1 - E^(2*x)] + (3/2)*x^2*PolyLog[2, E^(2*x)] - (3/2)*x*PolyLog[3, E^(2*x)] + (3/4)*PolyLog[4, E^(2*x)] - (3/16)*Sinh[2*x] - (3/8)*x^2*Sinh[2*x]}

{x^1*Cosh[x]^2*Coth[x]^2, x, 19, (3*x^2)/4 - (1/8)*Cosh[2*x] - x*Coth[x] + Log[Sinh[x]] + (1/4)*x*Sinh[2*x]}
{x^2*Cosh[x]^2*Coth[x]^2, x, 29, -x^2 + x^3/2 - (1/4)*x*Cosh[2*x] - x^2*Coth[x] + 2*x*Log[1 - E^(2*x)] + PolyLog[2, E^(2*x)] + (1/8)*Sinh[2*x] + (1/4)*x^2*Sinh[2*x]}
{x^3*Cosh[x]^2*Coth[x]^2, x, 33, -x^3 + (3*x^4)/8 - (3/16)*Cosh[2*x] - (3/8)*x^2*Cosh[2*x] - x^3*Coth[x] + 3*x^2*Log[1 - E^(2*x)] + 3*x*PolyLog[2, E^(2*x)] - (3/2)*PolyLog[3, E^(2*x)] + (3/8)*x*Sinh[2*x] + (1/4)*x^3*Sinh[2*x]}

{x^1*Cosh[x]^2*Coth[x]^3, x, 22, -x^2 + (1/4)*x*Cosh[2*x] - Coth[x]/2 - (1/2)*x*Csch[x]^2 + 2*x*Log[1 - E^(2*x)] + PolyLog[2, E^(2*x)] - (1/8)*Sinh[2*x]}
{x^2*Cosh[x]^2*Coth[x]^3, x, 28, -((2*x^3)/3) + (1/8)*Cosh[2*x] + (1/4)*x^2*Cosh[2*x] - x*Coth[x] - (1/2)*x^2*Csch[x]^2 + 2*x^2*Log[1 - E^(2*x)] + Log[Sinh[x]] + 2*x*PolyLog[2, E^(2*x)] - PolyLog[3, E^(2*x)] - (1/4)*x*Sinh[2*x]}
{x^3*Cosh[x]^2*Coth[x]^3, x, 40, -((3*x^2)/2) - x^4/2 + (3/8)*x*Cosh[2*x] + (1/4)*x^3*Cosh[2*x] - (3/2)*x^2*Coth[x] - (1/2)*x^3*Csch[x]^2 + 3*x*Log[1 - E^(2*x)] + 2*x^3*Log[1 - E^(2*x)] + (3/2)*(1 + 2*x^2)*PolyLog[2, E^(2*x)] - 3*x*PolyLog[3, E^(2*x)] + (3/2)*PolyLog[4, E^(2*x)] - (3/16)*Sinh[2*x] - (3/8)*x^2*Sinh[2*x]}


(* ::Subsubsection::Closed:: *)
(*Integrands of the form x^m Csch[a+b x]^n Sech[a+b x]^p*)


{x^3*Csch[a + b*x]*Sech[a + b*x], x, 9, -((2*x^3*ArcTanh[E^(2*a + 2*b*x)])/b) - (3*x^2*PolyLog[2, -E^(2*a + 2*b*x)])/(2*b^2) + (3*x^2*PolyLog[2, E^(2*a + 2*b*x)])/(2*b^2) + (3*x*PolyLog[3, -E^(2*a + 2*b*x)])/(2*b^3) - (3*x*PolyLog[3, E^(2*a + 2*b*x)])/(2*b^3) - (3*PolyLog[4, -E^(2*a + 2*b*x)])/(4*b^4) + (3*PolyLog[4, E^(2*a + 2*b*x)])/(4*b^4)}
{x^2*Csch[a + b*x]*Sech[a + b*x], x, 7, -((2*x^2*ArcTanh[E^(2*a + 2*b*x)])/b) - (x*PolyLog[2, -E^(2*a + 2*b*x)])/b^2 + (x*PolyLog[2, E^(2*a + 2*b*x)])/b^2 + PolyLog[3, -E^(2*a + 2*b*x)]/(2*b^3) - PolyLog[3, E^(2*a + 2*b*x)]/(2*b^3)}
{x^1*Csch[a + b*x]*Sech[a + b*x], x, 5, -((2*x*ArcTanh[E^(2*a + 2*b*x)])/b) - PolyLog[2, -E^(2*a + 2*b*x)]/(2*b^2) + PolyLog[2, E^(2*a + 2*b*x)]/(2*b^2)}
{x^0*Csch[a + b*x]*Sech[a + b*x], x, 1, Log[Tanh[a + b*x]]/b}
{Csch[a + b*x]*Sech[a + b*x]/x^1, x, 1, 2*Int[Csch[2*a + 2*b*x]/x, x]}

{x^3*Csch[a + b*x]*Sech[a + b*x]^2, x, 19, -((6*x^2*ArcTan[E^(a + b*x)])/b^2) - (2*x^3*ArcTanh[E^(a + b*x)])/b - (3*x^2*PolyLog[2, -E^(a + b*x)])/b^2 + (6*I*x*PolyLog[2, (-I)*E^(a + b*x)])/b^3 - (6*I*x*PolyLog[2, I*E^(a + b*x)])/b^3 + (3*x^2*PolyLog[2, E^(a + b*x)])/b^2 + (6*x*PolyLog[3, -E^(a + b*x)])/b^3 - (6*I*PolyLog[3, (-I)*E^(a + b*x)])/b^4 + (6*I*PolyLog[3, I*E^(a + b*x)])/b^4 - (6*x*PolyLog[3, E^(a + b*x)])/b^3 - (6*PolyLog[4, -E^(a + b*x)])/b^4 + (6*PolyLog[4, E^(a + b*x)])/b^4 + (x^3*Sech[a + b*x])/b}
{x^2*Csch[a + b*x]*Sech[a + b*x]^2, x, 15, -((4*x*ArcTan[E^(a + b*x)])/b^2) - (2*x^2*ArcTanh[E^(a + b*x)])/b - (2*x*PolyLog[2, -E^(a + b*x)])/b^2 + (2*I*PolyLog[2, (-I)*E^(a + b*x)])/b^3 - (2*I*PolyLog[2, I*E^(a + b*x)])/b^3 + (2*x*PolyLog[2, E^(a + b*x)])/b^2 + (2*PolyLog[3, -E^(a + b*x)])/b^3 - (2*PolyLog[3, E^(a + b*x)])/b^3 + (x^2*Sech[a + b*x])/b}
{x^1*Csch[a + b*x]*Sech[a + b*x]^2, x, 9, -(ArcTan[Sinh[a + b*x]]/b^2) - (2*x*ArcTanh[E^(a + b*x)])/b - PolyLog[2, -E^(a + b*x)]/b^2 + PolyLog[2, E^(a + b*x)]/b^2 + (x*Sech[a + b*x])/b}
{x^0*Csch[a + b*x]*Sech[a + b*x]^2, x, 2, -(ArcCoth[Cosh[a + b*x]]/b) + Sech[a + b*x]/b}
{Csch[a + b*x]*Sech[a + b*x]^2/x^1, x, 0, Int[(Csch[a + b*x]*Sech[a + b*x]^2)/x, x]}

{x^3*Csch[a + b*x]*Sech[a + b*x]^3, x, 19, -((3*x^2)/(2*b^2)) - (2*x^3*ArcTanh[E^(2*a + 2*b*x)])/b + (3*x*Log[1 + E^(2*a + 2*b*x)])/b^3 + (3*(1 - b^2*x^2)*PolyLog[2, -E^(2*a + 2*b*x)])/(2*b^4) + (3*x^2*PolyLog[2, E^(2*a + 2*b*x)])/(2*b^2) + (3*x*PolyLog[3, -E^(2*a + 2*b*x)])/(2*b^3) - (3*x*PolyLog[3, E^(2*a + 2*b*x)])/(2*b^3) - (3*PolyLog[4, -E^(2*a + 2*b*x)])/(4*b^4) + (3*PolyLog[4, E^(2*a + 2*b*x)])/(4*b^4) + (x^3*Sech[a + b*x]^2)/(2*b) - (3*x^2*Tanh[a + b*x])/(2*b^2)}
{x^2*Csch[a + b*x]*Sech[a + b*x]^3, x, 14, -((2*x^2*ArcTanh[E^(2*a + 2*b*x)])/b) + Log[Cosh[a + b*x]]/b^3 - (x*PolyLog[2, -E^(2*a + 2*b*x)])/b^2 + (x*PolyLog[2, E^(2*a + 2*b*x)])/b^2 + PolyLog[3, -E^(2*a + 2*b*x)]/(2*b^3) - PolyLog[3, E^(2*a + 2*b*x)]/(2*b^3) + (x^2*Sech[a + b*x]^2)/(2*b) - (x*Tanh[a + b*x])/b^2}
{x^1*Csch[a + b*x]*Sech[a + b*x]^3, x, 9, -((2*x*ArcTanh[E^(2*a + 2*b*x)])/b) - PolyLog[2, -E^(2*a + 2*b*x)]/(2*b^2) + PolyLog[2, E^(2*a + 2*b*x)]/(2*b^2) + (x*Sech[a + b*x]^2)/(2*b) - Tanh[a + b*x]/(2*b^2)}
{x^0*Csch[a + b*x]*Sech[a + b*x]^3, x, 3, Log[Tanh[a + b*x]]/b - Tanh[a + b*x]^2/(2*b)}
{Csch[a + b*x]*Sech[a + b*x]^3/x^1, x, 0, Int[(Csch[a + b*x]*Sech[a + b*x]^3)/x, x]}


{x^3*Csch[a + b*x]^2*Sech[a + b*x], x, 19, -((2*x^3*ArcTan[E^(a + b*x)])/b) - (6*x^2*ArcTanh[E^(a + b*x)])/b^2 - (x^3*Csch[a + b*x])/b - (6*x*PolyLog[2, -E^(a + b*x)])/b^3 + (3*I*x^2*PolyLog[2, (-I)*E^(a + b*x)])/b^2 - (3*I*x^2*PolyLog[2, I*E^(a + b*x)])/b^2 + (6*x*PolyLog[2, E^(a + b*x)])/b^3 + (6*PolyLog[3, -E^(a + b*x)])/b^4 - (6*I*x*PolyLog[3, (-I)*E^(a + b*x)])/b^3 + (6*I*x*PolyLog[3, I*E^(a + b*x)])/b^3 - (6*PolyLog[3, E^(a + b*x)])/b^4 + (6*I*PolyLog[4, (-I)*E^(a + b*x)])/b^4 - (6*I*PolyLog[4, I*E^(a + b*x)])/b^4}
{x^2*Csch[a + b*x]^2*Sech[a + b*x], x, 15, -((2*x^2*ArcTan[E^(a + b*x)])/b) - (4*x*ArcTanh[E^(a + b*x)])/b^2 - (x^2*Csch[a + b*x])/b - (2*PolyLog[2, -E^(a + b*x)])/b^3 + (2*I*x*PolyLog[2, (-I)*E^(a + b*x)])/b^2 - (2*I*x*PolyLog[2, I*E^(a + b*x)])/b^2 + (2*PolyLog[2, E^(a + b*x)])/b^3 - (2*I*PolyLog[3, (-I)*E^(a + b*x)])/b^3 + (2*I*PolyLog[3, I*E^(a + b*x)])/b^3}
{x^1*Csch[a + b*x]^2*Sech[a + b*x], x, 9, -(ArcCoth[Cosh[a + b*x]]/b^2) - (2*x*ArcTan[E^(a + b*x)])/b - (x*Csch[a + b*x])/b + (I*PolyLog[2, (-I)*E^(a + b*x)])/b^2 - (I*PolyLog[2, I*E^(a + b*x)])/b^2}
{x^0*Csch[a + b*x]^2*Sech[a + b*x], x, 2, -(ArcTan[Sinh[a + b*x]]/b) - Csch[a + b*x]/b}
{Csch[a + b*x]^2*Sech[a + b*x]/x^1, x, 0, Int[(Csch[a + b*x]^2*Sech[a + b*x])/x, x]}

{x^3*Csch[a + b*x]^2*Sech[a + b*x]^2, x, 7, -((2*x^3)/b) - (2*x^3*Coth[2*a + 2*b*x])/b + (3*x^2*Log[1 - E^(4*a + 4*b*x)])/b^2 + (3*x*PolyLog[2, E^(4*a + 4*b*x)])/(2*b^3) - (3*PolyLog[3, E^(4*a + 4*b*x)])/(8*b^4)}
{x^2*Csch[a + b*x]^2*Sech[a + b*x]^2, x, 6, -((2*x^2)/b) - (2*x^2*Coth[2*a + 2*b*x])/b + (2*x*Log[1 - E^(4*a + 4*b*x)])/b^2 + PolyLog[2, E^(4*a + 4*b*x)]/(2*b^3)}
{x^1*Csch[a + b*x]^2*Sech[a + b*x]^2, x, 3, -((2*x*Coth[2*a + 2*b*x])/b) + Log[Sinh[2*a + 2*b*x]]/b^2}
{x^0*Csch[a + b*x]^2*Sech[a + b*x]^2, x, 3, -(Coth[a + b*x]/b) - Tanh[a + b*x]/b}
{Csch[a + b*x]^2*Sech[a + b*x]^2/x^1, x, 1, 4*Int[Csch[2*a + 2*b*x]^2/x, x]}

{x^3*Csch[a + b*x]^2*Sech[a + b*x]^3, x, 34, (6*x*ArcTan[E^(a + b*x)])/b^3 - (3*x^3*ArcTan[E^(a + b*x)])/b - (6*x^2*ArcTanh[E^(a + b*x)])/b^2 - (6*x*PolyLog[2, -E^(a + b*x)])/b^3 - (3*I*(2 - 3*b^2*x^2)*PolyLog[2, (-I)*E^(a + b*x)])/(2*b^4) + (3*I*(2 - 3*b^2*x^2)*PolyLog[2, I*E^(a + b*x)])/(2*b^4) + (6*x*PolyLog[2, E^(a + b*x)])/b^3 + (6*PolyLog[3, -E^(a + b*x)])/b^4 - (9*I*x*PolyLog[3, (-I)*E^(a + b*x)])/b^3 + (9*I*x*PolyLog[3, I*E^(a + b*x)])/b^3 - (6*PolyLog[3, E^(a + b*x)])/b^4 + (9*I*PolyLog[4, (-I)*E^(a + b*x)])/b^4 - (9*I*PolyLog[4, I*E^(a + b*x)])/b^4 - (3*x^2*Sech[a + b*x])/(2*b^2) - (x^3*Csch[a + b*x]*(3 - Sech[a + b*x]^2))/(2*b)}
{x^2*Csch[a + b*x]^2*Sech[a + b*x]^3, x, 24, -((3*x^2*ArcTan[E^(a + b*x)])/b) + ArcTan[Sinh[a + b*x]]/b^3 - (4*x*ArcTanh[E^(a + b*x)])/b^2 - (2*PolyLog[2, -E^(a + b*x)])/b^3 + (3*I*x*PolyLog[2, (-I)*E^(a + b*x)])/b^2 - (3*I*x*PolyLog[2, I*E^(a + b*x)])/b^2 + (2*PolyLog[2, E^(a + b*x)])/b^3 - (3*I*PolyLog[3, (-I)*E^(a + b*x)])/b^3 + (3*I*PolyLog[3, I*E^(a + b*x)])/b^3 - (x*Sech[a + b*x])/b^2 - (x^2*Csch[a + b*x]*(3 - Sech[a + b*x]^2))/(2*b)}
{x^1*Csch[a + b*x]^2*Sech[a + b*x]^3, x, 11, -(ArcCoth[Cosh[a + b*x]]/b^2) - (3*x*ArcTan[E^(a + b*x)])/b + (3*I*PolyLog[2, (-I)*E^(a + b*x)])/(2*b^2) - (3*I*PolyLog[2, I*E^(a + b*x)])/(2*b^2) - Sech[a + b*x]/(2*b^2) - (x*Csch[a + b*x]*(3 - Sech[a + b*x]^2))/(2*b)}
{x^0*Csch[a + b*x]^2*Sech[a + b*x]^3, x, 3, -((3*ArcTan[Sinh[a + b*x]])/(2*b)) - (3*Csch[a + b*x])/(2*b) + (Csch[a + b*x]*Sech[a + b*x]^2)/(2*b)}
{Csch[a + b*x]^2*Sech[a + b*x]^3/x^1, x, 0, Int[(Csch[a + b*x]^2*Sech[a + b*x]^3)/x, x]}


{x^3*Csch[a + b*x]^3*Sech[a + b*x], x, 19, -((3*x^2)/(2*b^2)) + (2*x^3*ArcTanh[E^(2*a + 2*b*x)])/b - (3*x^2*Coth[a + b*x])/(2*b^2) - (x^3*Csch[a + b*x]^2)/(2*b) + (3*x*Log[1 - E^(2*a + 2*b*x)])/b^3 + (3*x^2*PolyLog[2, -E^(2*a + 2*b*x)])/(2*b^2) + (3*(1 - b^2*x^2)*PolyLog[2, E^(2*a + 2*b*x)])/(2*b^4) - (3*x*PolyLog[3, -E^(2*a + 2*b*x)])/(2*b^3) + (3*x*PolyLog[3, E^(2*a + 2*b*x)])/(2*b^3) + (3*PolyLog[4, -E^(2*a + 2*b*x)])/(4*b^4) - (3*PolyLog[4, E^(2*a + 2*b*x)])/(4*b^4)}
{x^2*Csch[a + b*x]^3*Sech[a + b*x], x, 14, (2*x^2*ArcTanh[E^(2*a + 2*b*x)])/b - (x*Coth[a + b*x])/b^2 - (x^2*Csch[a + b*x]^2)/(2*b) + Log[Sinh[a + b*x]]/b^3 + (x*PolyLog[2, -E^(2*a + 2*b*x)])/b^2 - (x*PolyLog[2, E^(2*a + 2*b*x)])/b^2 - PolyLog[3, -E^(2*a + 2*b*x)]/(2*b^3) + PolyLog[3, E^(2*a + 2*b*x)]/(2*b^3)}
{x^1*Csch[a + b*x]^3*Sech[a + b*x], x, 9, (2*x*ArcTanh[E^(2*a + 2*b*x)])/b - Coth[a + b*x]/(2*b^2) - (x*Csch[a + b*x]^2)/(2*b) + PolyLog[2, -E^(2*a + 2*b*x)]/(2*b^2) - PolyLog[2, E^(2*a + 2*b*x)]/(2*b^2)}
{x^0*Csch[a + b*x]^3*Sech[a + b*x], x, 3, -(Coth[a + b*x]^2/(2*b)) + Log[Coth[a + b*x]]/b}
{Csch[a + b*x]^3*Sech[a + b*x]/x^1, x, 0, Int[(Csch[a + b*x]^3*Sech[a + b*x])/x, x]}

{x^3*Csch[a + b*x]^3*Sech[a + b*x]^2, x, 34, (6*x^2*ArcTan[E^(a + b*x)])/b^2 - (6*x*ArcTanh[E^(a + b*x)])/b^3 + (3*x^3*ArcTanh[E^(a + b*x)])/b - (3*x^2*Csch[a + b*x])/(2*b^2) - (3*(2 - 3*b^2*x^2)*PolyLog[2, -E^(a + b*x)])/(2*b^4) - (6*I*x*PolyLog[2, (-I)*E^(a + b*x)])/b^3 + (6*I*x*PolyLog[2, I*E^(a + b*x)])/b^3 + (3*(2 - 3*b^2*x^2)*PolyLog[2, E^(a + b*x)])/(2*b^4) - (9*x*PolyLog[3, -E^(a + b*x)])/b^3 + (6*I*PolyLog[3, (-I)*E^(a + b*x)])/b^4 - (6*I*PolyLog[3, I*E^(a + b*x)])/b^4 + (9*x*PolyLog[3, E^(a + b*x)])/b^3 + (9*PolyLog[4, -E^(a + b*x)])/b^4 - (9*PolyLog[4, E^(a + b*x)])/b^4 - (x^3*(3 + Csch[a + b*x]^2)*Sech[a + b*x])/(2*b)}
{x^2*Csch[a + b*x]^3*Sech[a + b*x]^2, x, 24, -(ArcCoth[Cosh[a + b*x]]/b^3) + (4*x*ArcTan[E^(a + b*x)])/b^2 + (3*x^2*ArcTanh[E^(a + b*x)])/b - (x*Csch[a + b*x])/b^2 + (3*x*PolyLog[2, -E^(a + b*x)])/b^2 - (2*I*PolyLog[2, (-I)*E^(a + b*x)])/b^3 + (2*I*PolyLog[2, I*E^(a + b*x)])/b^3 - (3*x*PolyLog[2, E^(a + b*x)])/b^2 - (3*PolyLog[3, -E^(a + b*x)])/b^3 + (3*PolyLog[3, E^(a + b*x)])/b^3 - (x^2*(3 + Csch[a + b*x]^2)*Sech[a + b*x])/(2*b)}
{x^1*Csch[a + b*x]^3*Sech[a + b*x]^2, x, 11, ArcTan[Sinh[a + b*x]]/b^2 + (3*x*ArcTanh[E^(a + b*x)])/b - Csch[a + b*x]/(2*b^2) + (3*PolyLog[2, -E^(a + b*x)])/(2*b^2) - (3*PolyLog[2, E^(a + b*x)])/(2*b^2) - (x*(3 + Csch[a + b*x]^2)*Sech[a + b*x])/(2*b)}
{x^0*Csch[a + b*x]^3*Sech[a + b*x]^2, x, 3, (3*ArcCoth[Cosh[a + b*x]])/(2*b) - (3*Sech[a + b*x])/(2*b) - (Csch[a + b*x]^2*Sech[a + b*x])/(2*b)}
{Csch[a + b*x]^3*Sech[a + b*x]^2/x^1, x, 0, Int[(Csch[a + b*x]^3*Sech[a + b*x]^2)/x, x]}

{x^3*Sech[a + b*x]^3*Csch[a + b*x]^3, x, 14, -((6*x*ArcTanh[E^(2*a + 2*b*x)])/b^3) + (4*x^3*ArcTanh[E^(2*a + 2*b*x)])/b - (3*x^2*Csch[2*a + 2*b*x])/b^2 - (2*x^3*Coth[2*a + 2*b*x]*Csch[2*a + 2*b*x])/b - (3*(1 - 2*b^2*x^2)*PolyLog[2, -E^(2*a + 2*b*x)])/(2*b^4) + (3*(1 - 2*b^2*x^2)*PolyLog[2, E^(2*a + 2*b*x)])/(2*b^4) - (3*x*PolyLog[3, -E^(2*a + 2*b*x)])/b^3 + (3*x*PolyLog[3, E^(2*a + 2*b*x)])/b^3 + (3*PolyLog[4, -E^(2*a + 2*b*x)])/(2*b^4) - (3*PolyLog[4, E^(2*a + 2*b*x)])/(2*b^4)}
{x^2*Sech[a + b*x]^3*Csch[a + b*x]^3, x, 9, -(ArcCoth[Cosh[2*a + 2*b*x]]/b^3) + (4*x^2*ArcTanh[E^(2*a + 2*b*x)])/b - (2*x*Csch[2*a + 2*b*x])/b^2 - (2*x^2*Coth[2*a + 2*b*x]*Csch[2*a + 2*b*x])/b + (2*x*PolyLog[2, -E^(2*a + 2*b*x)])/b^2 - (2*x*PolyLog[2, E^(2*a + 2*b*x)])/b^2 - PolyLog[3, -E^(2*a + 2*b*x)]/b^3 + PolyLog[3, E^(2*a + 2*b*x)]/b^3}
{x^1*Sech[a + b*x]^3*Csch[a + b*x]^3, x, 6, (4*x*ArcTanh[E^(2*a + 2*b*x)])/b - Csch[2*a + 2*b*x]/b^2 - (2*x*Coth[2*a + 2*b*x]*Csch[2*a + 2*b*x])/b + PolyLog[2, -E^(2*a + 2*b*x)]/b^2 - PolyLog[2, E^(2*a + 2*b*x)]/b^2}
{x^0*Sech[a + b*x]^3*Csch[a + b*x]^3, x, 3, -(Coth[a + b*x]^2/(2*b)) - (2*Log[Tanh[a + b*x]])/b + Tanh[a + b*x]^2/(2*b)}
{Sech[a + b*x]^3*Csch[a + b*x]^3/x^1, x, 1, 8*Int[Csch[2*a + 2*b*x]^3/x, x]}


(* ::Subsection::Closed:: *)
(*Integrands of the form Hyper[m x] Hyper[n x]*)


(* ::Subsubsection::Closed:: *)
(*Integrands of the form Hyper[m x] Sinh[n x]*)


(* Integrands of the form Sinh[m*x]*Sinh[x] where n is an integer *)
{Sinh[2*x]*Sinh[x], x, 3, (2*Sinh[x]^3)/3}
{Sinh[3*x]*Sinh[x], x, 3, (-(1/4))*Sinh[2*x] + (1/8)*Sinh[4*x]}
{Sinh[4*x]*Sinh[x], x, 3, (-(1/6))*Sinh[3*x] + (1/10)*Sinh[5*x]}
{Sinh[m*x]*Sinh[x], x, 3, -(Sinh[(1 - m)*x]/(2*(1 - m))) + Sinh[(1 + m)*x]/(2*(1 + m))}


(* Integrands of the form Cosh[m*x]*Sinh[x] where n is an integer *)
{Cosh[2*x]*Sinh[x], x, 4, -(Cosh[x]/2) + (1/6)*Cosh[3*x]}
{Cosh[3*x]*Sinh[x], x, 4, (-(1/4))*Cosh[2*x] + (1/8)*Cosh[4*x]}
{Cosh[4*x]*Sinh[x], x, 4, (-(1/6))*Cosh[3*x] + (1/10)*Cosh[5*x]}
{Cosh[m*x]*Sinh[x], x, 3, Cosh[(1 - m)*x]/(2*(1 - m)) + Cosh[(1 + m)*x]/(2*(1 + m))}


(* Integrands of the form Tanh[m*x]*Sinh[x] where n is an integer *)
{Tanh[2*x]*Sinh[x], x, 5, -(ArcTan[Sqrt[2]*Sinh[x]]/Sqrt[2]) + Sinh[x]}
{Tanh[3*x]*Sinh[x], x, 3, (-(1/3))*ArcTan[(3*Sinh[x])/(1 - 2*Sinh[x]^2)] + Sinh[x]}
{Tanh[4*x]*Sinh[x], x, 6, (-(1/4))*Sqrt[2 - Sqrt[2]]*ArcTan[(2*Sinh[x])/Sqrt[2 - Sqrt[2]]] - (1/4)*Sqrt[2 + Sqrt[2]]*ArcTan[(2*Sinh[x])/Sqrt[2 + Sqrt[2]]] + Sinh[x]}
{Tanh[5*x]*Sinh[x], x, 7, (-(1/5))*ArcTan[Sinh[x]] + (1/10)*(1 + Sqrt[5])*ArcTan[(1 - Sqrt[5])*Sinh[x]] + (1/10)*(1 - Sqrt[5])*ArcTan[(1 + Sqrt[5])*Sinh[x]] + Sinh[x]}
{Tanh[6*x]*Sinh[x], x, 7, -(ArcTan[Sqrt[2]*Sinh[x]]/(3*Sqrt[2])) + (1/12)*(Sqrt[2] + Sqrt[6])*ArcTan[(Sqrt[2] - Sqrt[6])*Sinh[x]] + (1/12)*(Sqrt[2] - Sqrt[6])*ArcTan[(Sqrt[2] + Sqrt[6])*Sinh[x]] + Sinh[x]}
(* Before use of TryTrigReduceQ in ExpandExpression, TrigReduce expansion resulted in infinite recursion. *)
{Tanh[n*x]*Sinh[x], x, 0, Int[Sinh[x]*Tanh[n*x], x]}


(* Integrands of the form Coth[m*x]*Sinh[x] where n is an integer *)
{Coth[2*x]*Sinh[x], x, 4, (-(1/2))*ArcTan[Sinh[x]] + Sinh[x]}
{Coth[3*x]*Sinh[x], x, 4, -(ArcTan[(2*Sinh[x])/Sqrt[3]]/Sqrt[3]) + Sinh[x]}
{Coth[4*x]*Sinh[x], x, 5, (-(1/4))*ArcTan[Sinh[x]] - ArcTan[Sqrt[2]*Sinh[x]]/(2*Sqrt[2]) + Sinh[x]}
{Coth[5*x]*Sinh[x], x, 6, (-(1/10))*Sqrt[10 - 2*Sqrt[5]]*ArcTan[(4*Sinh[x])/Sqrt[10 - 2*Sqrt[5]]] - (1/10)*Sqrt[10 + 2*Sqrt[5]]*ArcTan[(4*Sinh[x])/Sqrt[10 + 2*Sqrt[5]]] + Sinh[x]}
{Coth[6*x]*Sinh[x], x, 6, (-(1/6))*ArcTan[Sinh[x]] - (1/6)*ArcTan[2*Sinh[x]] - ArcTan[(2*Sinh[x])/Sqrt[3]]/(2*Sqrt[3]) + Sinh[x]}


(* Integrands of the form Sech[m*x]*Sinh[x] where n is an integer *)
{Sech[2*x]*Sinh[x], x, 2, -(ArcTanh[Sqrt[2]*Cosh[x]]/Sqrt[2])}
{Sech[3*x]*Sinh[x], x, 3, (1/3)*ArcTanh[1 - (8*Cosh[x]^2)/3]}
{Sech[4*x]*Sinh[x], x, 4, (1/4)*Sqrt[2 + Sqrt[2]]*ArcTanh[(2*Cosh[x])/Sqrt[2 - Sqrt[2]]] - (1/4)*Sqrt[2 - Sqrt[2]]*ArcTanh[(2*Cosh[x])/Sqrt[2 + Sqrt[2]]]}
{Sech[5*x]*Sinh[x], x, 4, ArcTanh[(5 - 8*Cosh[x]^2)/Sqrt[5]]/(2*Sqrt[5]) + (1/5)*Log[Cosh[x]] - (1/20)*Log[5 - 20*Cosh[x]^2 + 16*Cosh[x]^4]}
{Sech[6*x]*Sinh[x], x, 7, ArcTanh[Sqrt[2]*Cosh[x]]/(3*Sqrt[2]) - (1/12)*(Sqrt[2] - Sqrt[6])*ArcTanh[(Sqrt[2] - Sqrt[6])*Cosh[x]] - (1/12)*(Sqrt[2] + Sqrt[6])*ArcTanh[(Sqrt[2] + Sqrt[6])*Cosh[x]]}


(* Integrands of the form Csch[m*x]*Sinh[x] where n is an integer *)
{Csch[2*x]*Sinh[x], x, 3, (1/2)*ArcTan[Sinh[x]]}
{Csch[3*x]*Sinh[x], x, 3, -(ArcTan[Sqrt[3]*Coth[x]]/Sqrt[3])}
{Csch[4*x]*Sinh[x], x, 4, (-(1/4))*ArcTan[Sinh[x]] + ArcTan[Sqrt[2]*Sinh[x]]/(2*Sqrt[2])}
{Csch[5*x]*Sinh[x], x, 8, (-(1/10))*Sqrt[10 - 2*Sqrt[5]]*ArcTan[Sqrt[5 - 2*Sqrt[5]]*Coth[x]] + (1/10)*Sqrt[10 + 2*Sqrt[5]]*ArcTan[Sqrt[5 + 2*Sqrt[5]]*Coth[x]]}
{Csch[6*x]*Sinh[x], x, 6, (1/6)*ArcTan[Sinh[x]] + (1/6)*ArcTan[2*Sinh[x]] - ArcTan[(2*Sinh[x])/Sqrt[3]]/(2*Sqrt[3])}


(* ::Subsubsection::Closed:: *)
(*Integrands of the form Hyper[m x] Cosh[n x]*)


(* Integrands of the form Sinh[m*x]*Cosh[x] where n is an integer *)
{Sinh[2*x]*Cosh[x], x, 3, (2*Cosh[x]^3)/3}
{Sinh[3*x]*Cosh[x], x, 3, (1/4)*Cosh[2*x] + (1/8)*Cosh[4*x]}
{Sinh[4*x]*Cosh[x], x, 3, (1/6)*Cosh[3*x] + (1/10)*Cosh[5*x]}
{Sinh[m*x]*Cosh[x], x, 4, -(Cosh[(1 - m)*x]/(2*(1 - m))) + Cosh[(1 + m)*x]/(2*(1 + m))}


(* Integrands of the form Cosh[m*x]*Cosh[x] where n is an integer *)
{Cosh[2*x]*Cosh[x], x, 3, Sinh[x]/2 + (1/6)*Sinh[3*x]}
{Cosh[3*x]*Cosh[x], x, 3, (1/4)*Sinh[2*x] + (1/8)*Sinh[4*x]}
{Cosh[4*x]*Cosh[x], x, 3, (1/6)*Sinh[3*x] + (1/10)*Sinh[5*x]}
{Cosh[m*x]*Cosh[x], x, 3, Sinh[(1 - m)*x]/(2*(1 - m)) + Sinh[(1 + m)*x]/(2*(1 + m))}


(* Integrands of the form Tanh[m*x]*Cosh[x] where n is an integer *)
{Tanh[2*x]*Cosh[x], x, 5, -(ArcTanh[Sqrt[2]*Cosh[x]]/Sqrt[2]) + Cosh[x]}
{Tanh[3*x]*Cosh[x], x, 4, -(ArcTanh[(2*Cosh[x])/Sqrt[3]]/Sqrt[3]) + Cosh[x]}
{Tanh[4*x]*Cosh[x], x, 6, (-(1/4))*Sqrt[2 - Sqrt[2]]*ArcTanh[(2*Cosh[x])/Sqrt[2 - Sqrt[2]]] - (1/4)*Sqrt[2 + Sqrt[2]]*ArcTanh[(2*Cosh[x])/Sqrt[2 + Sqrt[2]]] + Cosh[x]}
{Tanh[5*x]*Cosh[x], x, 6, (-(1/10))*Sqrt[10 - 2*Sqrt[5]]*ArcTanh[(4*Cosh[x])/Sqrt[10 - 2*Sqrt[5]]] - (1/10)*Sqrt[10 + 2*Sqrt[5]]*ArcTanh[(4*Cosh[x])/Sqrt[10 + 2*Sqrt[5]]] + Cosh[x]}
{Tanh[6*x]*Cosh[x], x, 8, -(ArcTanh[Sqrt[2]*Cosh[x]]/(3*Sqrt[2])) + (1/12)*(Sqrt[2] + Sqrt[6])*ArcTanh[(Sqrt[2] - Sqrt[6])*Cosh[x]] + (1/12)*(Sqrt[2] - Sqrt[6])*ArcTanh[(Sqrt[2] + Sqrt[6])*Cosh[x]] + Cosh[x]}


(* Integrands of the form Coth[m*x]*Cosh[x] where n is an integer *)
{Coth[2*x]*Cosh[x], x, 4, (-(1/2))*ArcTanh[Cosh[x]] + Cosh[x]}
{Coth[3*x]*Cosh[x], x, 3, (-(1/3))*ArcTanh[(3*Cosh[x])/(1 + 2*Cosh[x]^2)] + Cosh[x]}
{Coth[4*x]*Cosh[x], x, 5, (-(1/4))*ArcTanh[Cosh[x]] - ArcTanh[Sqrt[2]*Cosh[x]]/(2*Sqrt[2]) + Cosh[x]}
{Coth[5*x]*Cosh[x], x, 8, ArcTanh[(1 - 4*Cosh[x])/Sqrt[5]]/(2*Sqrt[5]) - (1/5)*ArcTanh[Cosh[x]] - ArcTanh[(1 + 4*Cosh[x])/Sqrt[5]]/(2*Sqrt[5]) + Cosh[x] - (1/20)*Log[1 - 2*Cosh[x] - 4*Cosh[x]^2] + (1/20)*Log[1 + 2*Cosh[x] - 4*Cosh[x]^2]}
{Coth[6*x]*Cosh[x], x, 6, (-(1/6))*ArcTanh[Cosh[x]] - (1/6)*ArcTanh[2*Cosh[x]] - ArcTanh[(2*Cosh[x])/Sqrt[3]]/(2*Sqrt[3]) + Cosh[x]}


(* Integrands of the form Sech[m*x]*Cosh[x] where n is an integer *)
{Sech[2*x]*Cosh[x], x, 2, ArcTan[Sqrt[2]*Sinh[x]]/Sqrt[2]}
{Sech[3*x]*Cosh[x], x, 3, ArcTan[Sqrt[3]*Tanh[x]]/Sqrt[3]}
{Sech[4*x]*Cosh[x], x, 4, (1/4)*Sqrt[2 + Sqrt[2]]*ArcTan[(2*Sinh[x])/Sqrt[2 - Sqrt[2]]] - (1/4)*Sqrt[2 - Sqrt[2]]*ArcTan[(2*Sinh[x])/Sqrt[2 + Sqrt[2]]]}
{Sech[5*x]*Cosh[x], x, 8, (-(1/10))*Sqrt[10 - 2*Sqrt[5]]*ArcTan[Sqrt[5 - 2*Sqrt[5]]*Tanh[x]] + (1/10)*Sqrt[10 + 2*Sqrt[5]]*ArcTan[Sqrt[5 + 2*Sqrt[5]]*Tanh[x]]}
{Sech[6*x]*Cosh[x], x, 7, -(ArcTan[Sqrt[2]*Sinh[x]]/(3*Sqrt[2])) + (1/12)*(Sqrt[2] - Sqrt[6])*ArcTan[(Sqrt[2] - Sqrt[6])*Sinh[x]] + (1/12)*(Sqrt[2] + Sqrt[6])*ArcTan[(Sqrt[2] + Sqrt[6])*Sinh[x]]}


(* Integrands of the form Csch[m*x]*Cosh[x] where n is an integer *)
{Csch[2*x]*Cosh[x], x, 3, (-(1/2))*ArcTanh[Cosh[x]]}
{Csch[3*x]*Cosh[x], x, 2, (-(1/3))*ArcTanh[1 + (8*Sinh[x]^2)/3]}
{Csch[4*x]*Cosh[x], x, 4, (-(1/4))*ArcTanh[Cosh[x]] + ArcTanh[Sqrt[2]*Cosh[x]]/(2*Sqrt[2])}
{Csch[5*x]*Cosh[x], x, 4, ArcTanh[(5 + 8*Sinh[x]^2)/Sqrt[5]]/(2*Sqrt[5]) + (1/5)*Log[Sinh[x]] - (1/20)*Log[5 + 20*Sinh[x]^2 + 16*Sinh[x]^4]}
{Csch[6*x]*Cosh[x], x, 6, (-(1/6))*ArcTanh[Cosh[x]] - (1/6)*ArcTanh[2*Cosh[x]] + ArcTanh[(2*Cosh[x])/Sqrt[3]]/(2*Sqrt[3])}
(* Before use of TryTrigReduceQ in ExpandExpression, TrigReduce expansion resulted in infinite recursion. *)
{Coth[n*x]*Cosh[x], x, 0, Int[Cosh[x]*Coth[n*x], x]}


(* ::Subsection::Closed:: *)
(*Integrands of the form (Hyper[a+b x] Hyper[a+b x])^m*)
(**)


(* Integrands of the form (Sinh[x]*Tanh[x])^m where m is a half-integer *)
{(Sinh[x]*Tanh[x])^(1/2), x, 2, 2*Coth[x]*Sqrt[Sinh[x]*Tanh[x]]}
{(Sinh[x]*Tanh[x])^(3/2), x, 3, (2/3)*Csch[x]*(4 + Sinh[x]^2)*Sqrt[Sinh[x]*Tanh[x]]}
{(Sinh[x]*Tanh[x])^(5/2), x, 4, (-(2/15))*Coth[x]*Sqrt[Sinh[x]*Tanh[x]]*(32 - (8 + 3*Sinh[x]^2)*Tanh[x]^2)}


(* Integrands of the form (Cosh[x]*Coth[x])^m where m is a half-integer *)
{(Cosh[x]*Coth[x])^(1/2), x, 2, 2*Sqrt[Cosh[x]*Coth[x]]*Tanh[x]}
{(Cosh[x]*Coth[x])^(3/2), x, 3, (-(2/3))*(4 - Cosh[x]^2)*Sqrt[Cosh[x]*Coth[x]]*Sech[x]}
{(Cosh[x]*Coth[x])^(5/2), x, 4, (2/15)*Sqrt[Cosh[x]*Coth[x]]*(32 - (8 - 3*Cosh[x]^2)*Coth[x]^2)*Tanh[x]}


(* ::Subsection::Closed:: *)
(*Integrands of the form Hyper[x]^m / (a+b Hyper[x])*)


(* ::Subsubsection::Closed:: *)
(*Integrands of the form Hyper[x]^m / (a+b Sinh[x])*)


(* Integrands of the form Sinh[x]^m/(a+b*Sinh[x]) where m is a positive integer *)
{Sinh[x]/(a + b*Sinh[x]), x, 2, x/b + (2*a*ArcTanh[(b - a*Tanh[x/2])/Sqrt[a^2 + b^2]])/(b*Sqrt[a^2 + b^2])}
{Sinh[x]^2/(a + b*Sinh[x]), x, 4, -((a*x)/b^2) - (2*a^2*ArcTanh[(b - a*Tanh[x/2])/Sqrt[a^2 + b^2]])/(b^2*Sqrt[a^2 + b^2]) + Cosh[x]/b}
{Sinh[x]^3/(a + b*Sinh[x]), x, 5, (a^2*x)/b^3 - x/(2*b) + (2*a^3*ArcTanh[(b - a*Tanh[x/2])/Sqrt[a^2 + b^2]])/(b^3*Sqrt[a^2 + b^2]) - (a*Cosh[x])/b^2 + (Cosh[x]*Sinh[x])/(2*b)}
{Sinh[x]^4/(a + b*Sinh[x]), x, 7, -((a^3*x)/b^4) + (a*x)/(2*b^2) - (2*a^4*ArcTanh[(b - a*Tanh[x/2])/Sqrt[a^2 + b^2]])/(b^4*Sqrt[a^2 + b^2]) + (a^2*Cosh[x])/b^3 - Cosh[x]/b + Cosh[x]^3/(3*b) - (a*Cosh[x]*Sinh[x])/(2*b^2)}

{Sinh[x]/(I + Sinh[x]), x, 2, x + (I*Cosh[x])/(1 - I*Sinh[x])}
{Sinh[x]^2/(I + Sinh[x]), x, 4, (-I)*x + Cosh[x] + Cosh[x]/(1 - I*Sinh[x])}
{Sinh[x]^3/(I + Sinh[x]), x, 5, -((3*x)/2) - I*Cosh[x] - (I*Cosh[x])/(1 - I*Sinh[x]) + (1/2)*Cosh[x]*Sinh[x]}
{Sinh[x]^4/(I + Sinh[x]), x, 7, (3*I*x)/2 - 2*Cosh[x] + Cosh[x]^3/3 - Cosh[x]/(1 - I*Sinh[x]) - (1/2)*I*Cosh[x]*Sinh[x]}


(* Integrands of the form Cosh[x]^m/(a+b*Sinh[x]) where m is a positive integer *)
{Cosh[x]/(a + b*Sinh[x]), x, 2, Log[a + b*Sinh[x]]/b}
{Cosh[x]^2/(a + b*Sinh[x]), x, 4, -((a*x)/b^2) - (2*Sqrt[a^2 + b^2]*ArcTanh[(b - a*Tanh[x/2])/Sqrt[a^2 + b^2]])/b^2 + Cosh[x]/b}
{Cosh[x]^3/(a + b*Sinh[x]), x, 5, ((a^2 + b^2)*Log[a + b*Sinh[x]])/b^3 - (a*Sinh[x])/b^2 + Sinh[x]^2/(2*b)}
{Cosh[x]^4/(a + b*Sinh[x]), x, 7, -((a^3*x)/b^4) - (3*a*x)/(2*b^2) - (2*(a^2 + b^2)^(3/2)*ArcTanh[(b - a*Tanh[x/2])/Sqrt[a^2 + b^2]])/b^4 + (a^2*Cosh[x])/b^3 + Cosh[x]/b + Cosh[x]^3/(3*b) - (a*Cosh[x]*Sinh[x])/(2*b^2)}

{Cosh[x]/(I + Sinh[x]), x, 2, Log[I + Sinh[x]]}
{Cosh[x]^2/(I + Sinh[x]), x, 3, (-I)*x + Cosh[x]}
{Cosh[x]^3/(I + Sinh[x]), x, 2, (-I)*Sinh[x] + Sinh[x]^2/2}
{Cosh[x]^4/(I + Sinh[x]), x, 6, -((I*x)/2) + Cosh[x]^3/3 - (1/2)*I*Cosh[x]*Sinh[x]}


(* Integrands of the form Tanh[x]^m/(a+b*Sinh[x]) where m is a positive integer *)
{Tanh[x]/(a + b*Sinh[x]), x, 7, (b*ArcTan[Sinh[x]])/(a^2 + b^2) + (a*Log[Cosh[x]^2])/(2*(a^2 + b^2)) - (a*Log[a + b*Sinh[x]])/(a^2 + b^2)}
{Tanh[x]^2/(a + b*Sinh[x]), x, 5, -((2*a^2*ArcTanh[(b - a*Tanh[x/2])/Sqrt[a^2 + b^2]])/(a^2 + b^2)^(3/2)) - (b*Sech[x])/(a^2 + b^2) - (a*Tanh[x])/(a^2 + b^2)}
{Tanh[x]^3/(a + b*Sinh[x]), x, 10, -((b*ArcTan[Sinh[x]])/(2*(a^2 + b^2))) + (b*(2*a^2 + b^2)*ArcTan[Sinh[x]])/(a^2 + b^2)^2 + (a^3*Log[Cosh[x]^2])/(2*(a^2 + b^2)^2) - (a^3*Log[a + b*Sinh[x]])/(a^2 + b^2)^2 + (a*Sech[x]^2)/(2*(a^2 + b^2)) - (b*Sech[x]*Tanh[x])/(2*(a^2 + b^2))}
{Tanh[x]^4/(a + b*Sinh[x]), x, 8, -((2*a^4*ArcTanh[(b - a*Tanh[x/2])/Sqrt[a^2 + b^2]])/(a^2 + b^2)^(5/2)) - (b*(2*a^2 + b^2)*Sech[x])/(a^2 + b^2)^2 + (b*Sech[x]^3)/(3*(a^2 + b^2)) + (a*Tanh[x])/(a^2 + b^2) - (a*(2*a^2 + b^2)*Tanh[x])/(a^2 + b^2)^2 - (a*Tanh[x]^3)/(3*(a^2 + b^2))}

{Tanh[x]/(I + Sinh[x]), x, 5, (1/2)*ArcTan[Sinh[x]] - 1/(2*(I + Sinh[x]))}
{Tanh[x]^2/(I + Sinh[x]), x, 6, -((7*Cosh[x])/(12*(1 - I*Sinh[x]))) - Cosh[x]/(4*(1 + I*Sinh[x])) - Cosh[x]/(6*(I + Sinh[x])^2)}
{Tanh[x]^3/(I + Sinh[x]), x, 7, (3/8)*ArcTan[Sinh[x]] + 1/(8*(I - Sinh[x])) + I/(8*(I + Sinh[x])^2) - 1/(2*(I + Sinh[x]))}
{Tanh[x]^4/(I + Sinh[x]), x, 11, -(Cosh[x]/(24*(I - Sinh[x])^2)) - (113*Cosh[x])/(240*(1 - I*Sinh[x])) - (13*Cosh[x])/(48*(1 + I*Sinh[x])) + (I*Cosh[x])/(20*(I + Sinh[x])^3) - (13*Cosh[x])/(60*(I + Sinh[x])^2)}


(* Integrands of the form Coth[x]^m/(a+b*Sinh[x]) where m is a positive integer *)
{Coth[x]/(a + b*Sinh[x]), x, 2, Log[Sinh[x]]/a - Log[a + b*Sinh[x]]/a}
{Coth[x]^2/(a + b*Sinh[x]), x, 5, (b*ArcCoth[Cosh[x]])/a^2 - (2*Sqrt[a^2 + b^2]*ArcTanh[(b - a*Tanh[x/2])/Sqrt[a^2 + b^2]])/a^2 - Coth[x]/a}
{Coth[x]^3/(a + b*Sinh[x]), x, 5, (b*Csch[x])/a^2 - Csch[x]^2/(2*a) + ((a^2 + b^2)*Log[Sinh[x]])/a^3 - ((a^2 + b^2)*Log[a + b*Sinh[x]])/a^3}
{Coth[x]^4/(a + b*Sinh[x]), x, 9, (3*b*ArcCoth[Cosh[x]])/(2*a^2) + (b^3*ArcCoth[Cosh[x]])/a^4 - (2*(a^2 + b^2)^(3/2)*ArcTanh[(b - a*Tanh[x/2])/Sqrt[a^2 + b^2]])/a^4 - Coth[x]/a - (b^2*Coth[x])/a^3 - Coth[x]^3/(3*a) + (b*Coth[x]*Csch[x])/(2*a^2)}

{Coth[x]/(I + Sinh[x]), x, 2, (-I)*Log[Sinh[x]] + I*Log[I + Sinh[x]]}
{Coth[x]^2/(I + Sinh[x]), x, 4, -ArcCoth[Cosh[x]] + I*Coth[x]}
{Coth[x]^3/(I + Sinh[x]), x, 3, -Csch[x] + (1/2)*I*Csch[x]^2}
{Coth[x]^4/(I + Sinh[x]), x, 8, (-(1/2))*ArcCoth[Cosh[x]] + (1/3)*I*Coth[x]^3 - (1/2)*Coth[x]*Csch[x]}


(* Integrands of the form Sech[x]^m/(a+b*Sinh[x]) where m is a positive integer *)
{Sech[x]/(a + b*Sinh[x]), x, 7, (a*ArcTan[Sinh[x]])/(a^2 + b^2) - (b*Log[Cosh[x]^2])/(2*(a^2 + b^2)) + (b*Log[a + b*Sinh[x]])/(a^2 + b^2)}
{Sech[x]^2/(a + b*Sinh[x]), x, 5, -((2*b^2*ArcTanh[(b - a*Tanh[x/2])/Sqrt[a^2 + b^2]])/(a^2 + b^2)^(3/2)) + (b*Sech[x])/(a^2 + b^2) + (a*Tanh[x])/(a^2 + b^2)}
{Sech[x]^3/(a + b*Sinh[x]), x, 10, (a*b^2*ArcTan[Sinh[x]])/(a^2 + b^2)^2 + (a*ArcTan[Sinh[x]])/(2*(a^2 + b^2)) - (b^3*Log[Cosh[x]^2])/(2*(a^2 + b^2)^2) + (b^3*Log[a + b*Sinh[x]])/(a^2 + b^2)^2 + (b*Sech[x]^2)/(2*(a^2 + b^2)) + (a*Sech[x]*Tanh[x])/(2*(a^2 + b^2))}
{Sech[x]^4/(a + b*Sinh[x]), x, 8, -((2*b^4*ArcTanh[(b - a*Tanh[x/2])/Sqrt[a^2 + b^2]])/(a^2 + b^2)^(5/2)) + (b^3*Sech[x])/(a^2 + b^2)^2 + (b*Sech[x]^3)/(3*(a^2 + b^2)) + (a*b^2*Tanh[x])/(a^2 + b^2)^2 + (a*Tanh[x])/(a^2 + b^2) - (a*Tanh[x]^3)/(3*(a^2 + b^2))}

{Sech[x]/(I + Sinh[x]), x, 6, (-(1/2))*I*ArcTan[Sinh[x]] - I/(2*(I + Sinh[x]))}
{Sech[x]^2/(I + Sinh[x]), x, 6, -((5*Cosh[x])/(12*(1 - I*Sinh[x]))) + Cosh[x]/(4*(1 + I*Sinh[x])) + Cosh[x]/(6*(I + Sinh[x])^2)}
{Sech[x]^3/(I + Sinh[x]), x, 8, (-(3/8))*I*ArcTan[Sinh[x]] + I/(8*(I - Sinh[x])) + 1/(8*(I + Sinh[x])^2) - I/(4*(I + Sinh[x]))}
{Sech[x]^4/(I + Sinh[x]), x, 11, -(Cosh[x]/(24*(I - Sinh[x])^2)) - (73*Cosh[x])/(240*(1 - I*Sinh[x])) + (11*Cosh[x])/(48*(1 + I*Sinh[x])) + (I*Cosh[x])/(20*(I + Sinh[x])^3) + (7*Cosh[x])/(60*(I + Sinh[x])^2)}


(* Integrands of the form Csch[x]^m/(a+b*Sinh[x]) where m is a positive integer *)
{Csch[x]/(a + b*Sinh[x]), x, 4, -(ArcCoth[Cosh[x]]/a) + (2*b*ArcTanh[(b - a*Tanh[x/2])/Sqrt[a^2 + b^2]])/(a*Sqrt[a^2 + b^2])}
{Csch[x]^2/(a + b*Sinh[x]), x, 5, (b*ArcCoth[Cosh[x]])/a^2 - (2*b^2*ArcTanh[(b - a*Tanh[x/2])/Sqrt[a^2 + b^2]])/(a^2*Sqrt[a^2 + b^2]) - Coth[x]/a}
{Csch[x]^3/(a + b*Sinh[x]), x, 7, ArcCoth[Cosh[x]]/(2*a) - (b^2*ArcCoth[Cosh[x]])/a^3 + (2*b^3*ArcTanh[(b - a*Tanh[x/2])/Sqrt[a^2 + b^2]])/(a^3*Sqrt[a^2 + b^2]) + (b*Coth[x])/a^2 - (Coth[x]*Csch[x])/(2*a)}
{Csch[x]^4/(a + b*Sinh[x]), x, 9, -((b*ArcCoth[Cosh[x]])/(2*a^2)) + (b^3*ArcCoth[Cosh[x]])/a^4 - (2*b^4*ArcTanh[(b - a*Tanh[x/2])/Sqrt[a^2 + b^2]])/(a^4*Sqrt[a^2 + b^2]) + Coth[x]/a - (b^2*Coth[x])/a^3 - Coth[x]^3/(3*a) + (b*Coth[x]*Csch[x])/(2*a^2)}

{Csch[x]/(I + Sinh[x]), x, 4, I*ArcCoth[Cosh[x]] - (I*Cosh[x])/(1 - I*Sinh[x])}
{Csch[x]^2/(I + Sinh[x]), x, 5, -ArcCoth[Cosh[x]] + I*Coth[x] + Cosh[x]/(1 - I*Sinh[x])}
{Csch[x]^3/(I + Sinh[x]), x, 7, (-(3/2))*I*ArcCoth[Cosh[x]] - Coth[x] + (1/2)*I*Coth[x]*Csch[x] + (I*Cosh[x])/(1 - I*Sinh[x])}
{Csch[x]^4/(I + Sinh[x]), x, 9, (3/2)*ArcCoth[Cosh[x]] - 2*I*Coth[x] + (1/3)*I*Coth[x]^3 - (1/2)*Coth[x]*Csch[x] - Cosh[x]/(1 - I*Sinh[x])}


(* ::Subsubsection::Closed:: *)
(*Integrands of the form Hyper[x]^m / (a+b Cosh[x])*)


(* Integrands of the form Sinh[x]^m/(a+b*Cosh[x]) where m is a positive integer *)
{Sinh[x]/(a + b*Cosh[x]), x, 2, Log[a + b*Cosh[x]]/b}
{Sinh[x]^2/(a + b*Cosh[x]), x, 4, -((a*x)/b^2) + (2*Sqrt[a^2 - b^2]*ArcTanh[((a - b)*Tanh[x/2])/Sqrt[a^2 - b^2]])/b^2 + Sinh[x]/b}
{Sinh[x]^3/(a + b*Cosh[x]), x, 5, -((a*Cosh[x])/b^2) + Cosh[x]^2/(2*b) + ((a^2 - b^2)*Log[a + b*Cosh[x]])/b^3}
{Sinh[x]^4/(a + b*Cosh[x]), x, 7, -((a^3*x)/b^4) + (3*a*x)/(2*b^2) + (2*(a^2 - b^2)^(3/2)*ArcTanh[((a - b)*Tanh[x/2])/Sqrt[a^2 - b^2]])/b^4 + (a^2*Sinh[x])/b^3 - Sinh[x]/b - (a*Cosh[x]*Sinh[x])/(2*b^2) + Sinh[x]^3/(3*b)}

{Sinh[x]/(a + a*Cosh[x]), x, 3, Log[1 + Cosh[x]]/a}
{Sinh[x]^2/(a + a*Cosh[x]), x, 3, -(x/a) + Sinh[x]/a}
{Sinh[x]^3/(a + a*Cosh[x]), x, 2, -(Cosh[x]/a) + Cosh[x]^2/(2*a)}
{Sinh[x]^4/(a + a*Cosh[x]), x, 6, x/(2*a) - (Cosh[x]*Sinh[x])/(2*a) + Sinh[x]^3/(3*a)}


(* Integrands of the form Cosh[x]^m/(a+b*Cosh[x]) where m is a positive integer *)
{Cosh[x]/(a + b*Cosh[x]), x, 2, x/b - (2*a*ArcTanh[((a - b)*Tanh[x/2])/Sqrt[a^2 - b^2]])/(b*Sqrt[a^2 - b^2])}
{Cosh[x]^2/(a + b*Cosh[x]), x, 4, -((a*x)/b^2) + (2*a^2*ArcTanh[((a - b)*Tanh[x/2])/Sqrt[a^2 - b^2]])/(b^2*Sqrt[a^2 - b^2]) + Sinh[x]/b}
{Cosh[x]^3/(a + b*Cosh[x]), x, 5, (a^2*x)/b^3 + x/(2*b) - (2*a^3*ArcTanh[((a - b)*Tanh[x/2])/Sqrt[a^2 - b^2]])/(b^3*Sqrt[a^2 - b^2]) - (a*Sinh[x])/b^2 + (Cosh[x]*Sinh[x])/(2*b)}
{Cosh[x]^4/(a + b*Cosh[x]), x, 7, -((a^3*x)/b^4) - (a*x)/(2*b^2) + (2*a^4*ArcTanh[((a - b)*Tanh[x/2])/Sqrt[a^2 - b^2]])/(b^4*Sqrt[a^2 - b^2]) + (a^2*Sinh[x])/b^3 + Sinh[x]/b - (a*Cosh[x]*Sinh[x])/(2*b^2) + Sinh[x]^3/(3*b)}

{Cosh[x]/(a + a*Cosh[x]), x, 2, x/a - Sinh[x]/(a*(1 + Cosh[x]))}
{Cosh[x]^2/(a + a*Cosh[x]), x, 4, -(x/a) + Sinh[x]/a + Sinh[x]/(a*(1 + Cosh[x]))}
{Cosh[x]^3/(a + a*Cosh[x]), x, 5, (3*x)/(2*a) - Sinh[x]/a + (Cosh[x]*Sinh[x])/(2*a) - Sinh[x]/(a*(1 + Cosh[x]))}
{Cosh[x]^4/(a + a*Cosh[x]), x, 7, -((3*x)/(2*a)) + (2*Sinh[x])/a - (Cosh[x]*Sinh[x])/(2*a) + Sinh[x]/(a*(1 + Cosh[x])) + Sinh[x]^3/(3*a)}


(* Integrands of the form Tanh[x]^m/(a+b*Cosh[x]) where m is a positive integer *)
{Tanh[x]/(a + b*Cosh[x]), x, 2, Log[Cosh[x]]/a - Log[a + b*Cosh[x]]/a}
{Tanh[x]^2/(a + b*Cosh[x]), x, 5, (b*ArcTan[Sinh[x]])/a^2 + (2*Sqrt[a^2 - b^2]*ArcTanh[((a - b)*Tanh[x/2])/Sqrt[a^2 - b^2]])/a^2 - Tanh[x]/a}
{Tanh[x]^3/(a + b*Cosh[x]), x, 5, ((a^2 - b^2)*Log[Cosh[x]])/a^3 - ((a^2 - b^2)*Log[a + b*Cosh[x]])/a^3 - (b*Sech[x])/a^2 + Sech[x]^2/(2*a)}
{Tanh[x]^4/(a + b*Cosh[x]), x, 9, (3*b*ArcTan[Sinh[x]])/(2*a^2) - (b^3*ArcTan[Sinh[x]])/a^4 + (2*(a^2 - b^2)^(3/2)*ArcTanh[((a - b)*Tanh[x/2])/Sqrt[a^2 - b^2]])/a^4 - Tanh[x]/a + (b^2*Tanh[x])/a^3 - (b*Sech[x]*Tanh[x])/(2*a^2) - Tanh[x]^3/(3*a)}

{Tanh[x]/(a + a*Cosh[x]), x, 3, -((2*ArcTanh[1 + 2*Cosh[x]])/a)}
{Tanh[x]^2/(a + a*Cosh[x]), x, 4, ArcTan[Sinh[x]]/a - Tanh[x]/a}
{Tanh[x]^3/(a + a*Cosh[x]), x, 3, -(Sech[x]/a) + Sech[x]^2/(2*a)}
{Tanh[x]^4/(a + a*Cosh[x]), x, 8, ArcTan[Sinh[x]]/(2*a) - (Sech[x]*Tanh[x])/(2*a) - Tanh[x]^3/(3*a)}


(* Integrands of the form Coth[x]^m/(a+b*Cosh[x]) where m is a positive integer *)
{Coth[x]/(a + b*Cosh[x]), x, 6, Log[1 - Cosh[x]]/(2*(a + b)) + Log[1 + Cosh[x]]/(2*(a - b)) - (a*Log[a + b*Cosh[x]])/(a^2 - b^2)}
{Coth[x]^2/(a + b*Cosh[x]), x, 5, (2*a^2*ArcTanh[((a - b)*Tanh[x/2])/Sqrt[a^2 - b^2]])/(a^2 - b^2)^(3/2) + Sinh[x]/(2*(a + b)*(1 - Cosh[x])) - Sinh[x]/(2*(a - b)*(1 + Cosh[x]))}
{Coth[x]^3/(a + b*Cosh[x]), x, 8, 1/(4*(a + b)*(1 - Cosh[x])) + 1/(4*(a - b)*(1 + Cosh[x])) + ((2*a + b)*Log[1 - Cosh[x]])/(4*(a + b)^2) + ((2*a - b)*Log[1 + Cosh[x]])/(4*(a - b)^2) - (a^3*Log[a + b*Cosh[x]])/(a^2 - b^2)^2}
{Coth[x]^4/(a + b*Cosh[x]), x, 9, (2*a^4*ArcTanh[((a - b)*Tanh[x/2])/Sqrt[a^2 - b^2]])/(a^2 - b^2)^(5/2) - Sinh[x]/(12*(a + b)*(1 - Cosh[x])^2) - Sinh[x]/(12*(a + b)*(1 - Cosh[x])) + ((3*a + 2*b)*Sinh[x])/(4*(a + b)^2*(1 - Cosh[x])) + Sinh[x]/(12*(a - b)*(1 + Cosh[x])^2) - ((3*a - 2*b)*Sinh[x])/(4*(a - b)^2*(1 + Cosh[x])) + Sinh[x]/(12*(a - b)*(1 + Cosh[x]))}

{Coth[x]/(a + a*Cosh[x]), x, 6, -(ArcTanh[Cosh[x]]/(2*a)) - 1/(2*a*(1 + Cosh[x]))}
{Coth[x]^2/(a + a*Cosh[x]), x, 6, Sinh[x]/(4*a*(1 - Cosh[x])) - Sinh[x]/(6*a*(1 + Cosh[x])^2) + (7*Sinh[x])/(12*a*(1 + Cosh[x]))}
{Coth[x]^3/(a + a*Cosh[x]), x, 8, -((3*ArcTanh[Cosh[x]])/(8*a)) + 1/(8*a*(1 - Cosh[x])) + 1/(8*a*(1 + Cosh[x])^2) - 1/(2*a*(1 + Cosh[x]))}
{Coth[x]^4/(a + a*Cosh[x]), x, 11, -(Sinh[x]/(24*a*(1 - Cosh[x])^2)) + (13*Sinh[x])/(48*a*(1 - Cosh[x])) + Sinh[x]/(20*a*(1 + Cosh[x])^3) - (13*Sinh[x])/(60*a*(1 + Cosh[x])^2) + (113*Sinh[x])/(240*a*(1 + Cosh[x]))}


(* Integrands of the form Sech[x]^m/(a+b*Cosh[x]) where m is a positive integer *)
{Sech[x]/(a + b*Cosh[x]), x, 4, ArcTan[Sinh[x]]/a - (2*b*ArcTanh[((a - b)*Tanh[x/2])/Sqrt[a^2 - b^2]])/(a*Sqrt[a^2 - b^2])}
{Sech[x]^2/(a + b*Cosh[x]), x, 5, -((b*ArcTan[Sinh[x]])/a^2) + (2*b^2*ArcTanh[((a - b)*Tanh[x/2])/Sqrt[a^2 - b^2]])/(a^2*Sqrt[a^2 - b^2]) + Tanh[x]/a}
{Sech[x]^3/(a + b*Cosh[x]), x, 7, ArcTan[Sinh[x]]/(2*a) + (b^2*ArcTan[Sinh[x]])/a^3 - (2*b^3*ArcTanh[((a - b)*Tanh[x/2])/Sqrt[a^2 - b^2]])/(a^3*Sqrt[a^2 - b^2]) - (b*Tanh[x])/a^2 + (Sech[x]*Tanh[x])/(2*a)}
{Sech[x]^4/(a + b*Cosh[x]), x, 9, -((b*ArcTan[Sinh[x]])/(2*a^2)) - (b^3*ArcTan[Sinh[x]])/a^4 + (2*b^4*ArcTanh[((a - b)*Tanh[x/2])/Sqrt[a^2 - b^2]])/(a^4*Sqrt[a^2 - b^2]) + Tanh[x]/a + (b^2*Tanh[x])/a^3 - (b*Sech[x]*Tanh[x])/(2*a^2) - Tanh[x]^3/(3*a)}

{Sech[x]/(a + a*Cosh[x]), x, 4, ArcTan[Sinh[x]]/a - Sinh[x]/(a*(1 + Cosh[x]))}
{Sech[x]^2/(a + a*Cosh[x]), x, 5, -(ArcTan[Sinh[x]]/a) + Sinh[x]/(a*(1 + Cosh[x])) + Tanh[x]/a}
{Sech[x]^3/(a + a*Cosh[x]), x, 7, (3*ArcTan[Sinh[x]])/(2*a) - Sinh[x]/(a*(1 + Cosh[x])) - Tanh[x]/a + (Sech[x]*Tanh[x])/(2*a)}
{Sech[x]^4/(a + a*Cosh[x]), x, 9, -((3*ArcTan[Sinh[x]])/(2*a)) + Sinh[x]/(a*(1 + Cosh[x])) + (2*Tanh[x])/a - (Sech[x]*Tanh[x])/(2*a) - Tanh[x]^3/(3*a)}


(* Integrands of the form Csch[x]^m/(a+b*Cosh[x]) where m is a positive integer *)
{Csch[x]/(a + b*Cosh[x]), x, 6, Log[1 - Cosh[x]]/(2*(a + b)) - Log[1 + Cosh[x]]/(2*(a - b)) + (b*Log[a + b*Cosh[x]])/(a^2 - b^2)}
{Csch[x]^2/(a + b*Cosh[x]), x, 5, (2*b^2*ArcTanh[((a - b)*Tanh[x/2])/Sqrt[a^2 - b^2]])/(a^2 - b^2)^(3/2) + Sinh[x]/(2*(a + b)*(1 - Cosh[x])) - Sinh[x]/(2*(a - b)*(1 + Cosh[x]))}
{Csch[x]^3/(a + b*Cosh[x]), x, 8, 1/(4*(a + b)*(1 - Cosh[x])) - 1/(4*(a - b)*(1 + Cosh[x])) - ((a + 2*b)*Log[1 - Cosh[x]])/(4*(a + b)^2) + ((a - 2*b)*Log[1 + Cosh[x]])/(4*(a - b)^2) + (b^3*Log[a + b*Cosh[x]])/(a^2 - b^2)^2}
{Csch[x]^4/(a + b*Cosh[x]), x, 9, (2*b^4*ArcTanh[((a - b)*Tanh[x/2])/Sqrt[a^2 - b^2]])/(a^2 - b^2)^(5/2) - Sinh[x]/(12*(a + b)*(1 - Cosh[x])^2) - Sinh[x]/(12*(a + b)*(1 - Cosh[x])) - ((a + 2*b)*Sinh[x])/(4*(a + b)^2*(1 - Cosh[x])) + Sinh[x]/(12*(a - b)*(1 + Cosh[x])^2) + ((a - 2*b)*Sinh[x])/(4*(a - b)^2*(1 + Cosh[x])) + Sinh[x]/(12*(a - b)*(1 + Cosh[x]))}

{Csch[x]/(a + a*Cosh[x]), x, 6, -(ArcTanh[Cosh[x]]/(2*a)) + 1/(2*a*(1 + Cosh[x]))}
{Csch[x]^2/(a + a*Cosh[x]), x, 6, Sinh[x]/(4*a*(1 - Cosh[x])) - Sinh[x]/(6*a*(1 + Cosh[x])^2) - (5*Sinh[x])/(12*a*(1 + Cosh[x]))}
{Csch[x]^3/(a + a*Cosh[x]), x, 8, (3*ArcTanh[Cosh[x]])/(8*a) + 1/(8*a*(1 - Cosh[x])) - 1/(8*a*(1 + Cosh[x])^2) - 1/(4*a*(1 + Cosh[x]))}
{Csch[x]^4/(a + a*Cosh[x]), x, 11, -(Sinh[x]/(24*a*(1 - Cosh[x])^2)) - (11*Sinh[x])/(48*a*(1 - Cosh[x])) + Sinh[x]/(20*a*(1 + Cosh[x])^3) + (7*Sinh[x])/(60*a*(1 + Cosh[x])^2) + (73*Sinh[x])/(240*a*(1 + Cosh[x]))}


(* ::Subsubsection::Closed:: *)
(*Integrands of the form Hyper[x]^m / (a+b Tanh[x])*)


(* Integrands of the form Sinh[x]^m/(a+b*Tanh[x]) where m is a positive integer *)
{Sinh[x]/(a + b*Tanh[x]), x, 7, (a*b*ArcTan[(b*Cosh[x] + a*Sinh[x])/Sqrt[a^2 - b^2]])/(a^2 - b^2)^(3/2) + (a*Cosh[x])/(a^2 - b^2) - (b*Sinh[x])/(a^2 - b^2), (2*a*b*ArcTan[(b + a*Tanh[x/2])/Sqrt[a^2 - b^2]])/(a^2 - b^2)^(3/2) + 1/((a + b)*(1 - Tanh[x/2])) + 1/((a - b)*(1 + Tanh[x/2]))}
{Sinh[x]^2/(a + b*Tanh[x]), x, 5, x/(4*(a - b)) + x/(4*(a + b)) - (a^3*x)/(a^2 - b^2)^2 + (a^2*b*Log[a*Cosh[x] + b*Sinh[x]])/(a^2 - b^2)^2 + 1/(4*(a + b)*(1 - Tanh[x])) - 1/(4*(a - b)*(1 + Tanh[x]))}
{Sinh[x]^3/(a + b*Tanh[x]), x, 20, -((3*a*b*ArcTan[(b + a*Tanh[x/2])/Sqrt[a^2 - b^2]])/(2*(a^2 - b^2)^(3/2))) - (a*b*(a^2 + 3*b^2)*ArcTan[(b + a*Tanh[x/2])/Sqrt[a^2 - b^2]])/(2*(a^2 - b^2)^(5/2)) + 1/(3*(a + b)*(1 - Tanh[x/2])^3) - 1/(2*(a + b)*(1 - Tanh[x/2])^2) - 3/(4*(a + b)*(1 - Tanh[x/2])) + (a + 3*b)/(4*(a + b)^2*(1 - Tanh[x/2])) + 1/(3*(a - b)*(1 + Tanh[x/2])^3) - 1/(2*(a - b)*(1 + Tanh[x/2])^2) + (a - 3*b)/(4*(a - b)^2*(1 + Tanh[x/2])) - 3/(4*(a - b)*(1 + Tanh[x/2]))}
{Sinh[x]^4/(a + b*Tanh[x]), x, 9, -(((3*a - 2*b)*x)/(8*(a - b)^2)) + x/(16*(a - b)) + x/(16*(a + b)) - ((3*a + 2*b)*x)/(8*(a + b)^2) + (a^5*x)/(a^2 - b^2)^3 - (a^4*b*Log[a*Cosh[x] + b*Sinh[x]])/(a^2 - b^2)^3 + 1/(16*(a + b)*(1 - Tanh[x])^2) + 1/(16*(a + b)*(1 - Tanh[x])) - (3*a + 2*b)/(8*(a + b)^2*(1 - Tanh[x])) - 1/(16*(a - b)*(1 + Tanh[x])^2) + (3*a - 2*b)/(8*(a - b)^2*(1 + Tanh[x])) - 1/(16*(a - b)*(1 + Tanh[x]))}

{Sinh[x]/(1 + Tanh[x]), x, 6, Cosh[x]^3/3 - Sinh[x]^3/3}
{Sinh[x]^2/(1 + Tanh[x]), x, 6, -(x/8) - (1/8)*Cosh[x]*Sinh[x] + (1/4)*Cosh[x]^3*Sinh[x] - Sinh[x]^4/4}
{Sinh[x]^3/(1 + Tanh[x]), x, 7, (-(1/3))*Cosh[x]^3 + Cosh[x]^5/5 - Sinh[x]^5/5}
{Sinh[x]^4/(1 + Tanh[x]), x, 7, x/16 + (1/16)*Cosh[x]*Sinh[x] - (1/8)*Cosh[x]^3*Sinh[x] + (1/6)*Cosh[x]^3*Sinh[x]^3 - Sinh[x]^6/6}


(* Integrands of the form Cosh[x]^m/(a+b*Tanh[x]) where m is a positive integer *)
{Cosh[x]/(a + b*Tanh[x]), x, 5, -((2*b^2*ArcTan[(b + a*Tanh[x/2])/Sqrt[a^2 - b^2]])/(a^2 - b^2)^(3/2)) - (b*Cosh[x])/(a^2 - b^2) + (a*Sinh[x])/(a^2 - b^2)}
{Cosh[x]^2/(a + b*Tanh[x]), x, 6, -((a*b^2*x)/(a^2 - b^2)^2) + (a*x)/(2*(a^2 - b^2)) + (b^3*Log[a*Cosh[x] + b*Sinh[x]])/(a^2 - b^2)^2 + (a*Cosh[x]*Sinh[x])/(2*(a^2 - b^2)) - (b*Sinh[x]^2)/(2*(a^2 - b^2))}
{Cosh[x]^3/(a + b*Tanh[x]), x, 10, (2*b^4*ArcTan[(b + a*Tanh[x/2])/Sqrt[a^2 - b^2]])/(a^2 - b^2)^(5/2) + (b^3*Cosh[x])/(a^2 - b^2)^2 - (b*Cosh[x]^3)/(3*(a^2 - b^2)) - (a*b^2*Sinh[x])/(a^2 - b^2)^2 + (a*Sinh[x])/(a^2 - b^2) + (a*Sinh[x]^3)/(3*(a^2 - b^2))}
{Cosh[x]^4/(a + b*Tanh[x]), x, 11, (a*b^4*x)/(a^2 - b^2)^3 - (a*b^2*x)/(2*(a^2 - b^2)^2) + (3*a*x)/(8*(a^2 - b^2)) - (b*Cosh[x]^4)/(4*(a^2 - b^2)) - (b^5*Log[a*Cosh[x] + b*Sinh[x]])/(a^2 - b^2)^3 - (a*b^2*Cosh[x]*Sinh[x])/(2*(a^2 - b^2)^2) + (3*a*Cosh[x]*Sinh[x])/(8*(a^2 - b^2)) + (a*Cosh[x]^3*Sinh[x])/(4*(a^2 - b^2)) + (b^3*Sinh[x]^2)/(2*(a^2 - b^2)^2)}

{Cosh[x]/(1 + Tanh[x]), x, 8, (-(1/3))*Cosh[x]^3 + Sinh[x] + Sinh[x]^3/3}
{Cosh[x]^2/(1 + Tanh[x]), x, 8, (3*x)/8 - Cosh[x]^4/4 + (3/8)*Cosh[x]*Sinh[x] + (1/4)*Cosh[x]^3*Sinh[x]}
{Cosh[x]^3/(1 + Tanh[x]), x, 8, (-(1/5))*Cosh[x]^5 + Sinh[x] + (2*Sinh[x]^3)/3 + Sinh[x]^5/5}
{Cosh[x]^4/(1 + Tanh[x]), x, 9, (5*x)/16 - Cosh[x]^6/6 + (5/16)*Cosh[x]*Sinh[x] + (5/24)*Cosh[x]^3*Sinh[x] + (1/6)*Cosh[x]^5*Sinh[x]}


(* Integrands of the form Tanh[x]^m/(a+b*Tanh[x]) where m is a positive integer *)
{Tanh[x]/(a + b*Tanh[x]), x, 2, -((b*x)/(a^2 - b^2)) + (a*Log[a*Cosh[x] + b*Sinh[x]])/(a^2 - b^2)}
{Tanh[x]^2/(a + b*Tanh[x]), x, 4, (a*x)/(a^2 - b^2) + Log[Cosh[x]]/b - (a^2*Log[a*Cosh[x] + b*Sinh[x]])/(b*(a^2 - b^2))}
{Tanh[x]^3/(a + b*Tanh[x]), x, 5, -((b*x)/(a^2 - b^2)) - (a*Log[Cosh[x]])/b^2 + (a^3*Log[a*Cosh[x] + b*Sinh[x]])/(b^2*(a^2 - b^2)) - Tanh[x]/b}
{Tanh[x]^4/(a + b*Tanh[x]), x, 7, (a*x)/(a^2 - b^2) + (a^2*Log[Cosh[x]])/b^3 + Log[Cosh[x]]/b - (a^4*Log[a*Cosh[x] + b*Sinh[x]])/(b^3*(a^2 - b^2)) + (a*Tanh[x])/b^2 - Tanh[x]^2/(2*b)}

{Tanh[x]/(1 + Tanh[x]), x, 2, x/2 + 1/(2*(1 + Tanh[x]))}
{Tanh[x]^2/(1 + Tanh[x]), x, 4, -(x/2) + Log[Cosh[x]] - 1/(2*(1 + Tanh[x]))}
{Tanh[x]^3/(1 + Tanh[x]), x, 5, (3*x)/2 - Log[Cosh[x]] - Tanh[x] + 1/(2*(1 + Tanh[x]))}
{Tanh[x]^4/(1 + Tanh[x]), x, 7, -((3*x)/2) + 2*Log[Cosh[x]] + Tanh[x] - Tanh[x]^2/2 - 1/(2*(1 + Tanh[x]))}


(* Integrands of the form Coth[x]^m/(a+b*Tanh[x]) where m is a positive integer *)
{Coth[x]/(a + b*Tanh[x]), x, 4, -((b*x)/(a^2 - b^2)) + Log[Sinh[x]]/a + (b^2*Log[a*Cosh[x] + b*Sinh[x]])/(a*(a^2 - b^2))}
{Coth[x]^2/(a + b*Tanh[x]), x, 5, (a*x)/(a^2 - b^2) - Coth[x]/a - (b*Log[Sinh[x]])/a^2 - (b^3*Log[a*Cosh[x] + b*Sinh[x]])/(a^2*(a^2 - b^2))}
{Coth[x]^3/(a + b*Tanh[x]), x, 7, -((b*x)/(a^2 - b^2)) + (b*Coth[x])/a^2 - Coth[x]^2/(2*a) + Log[Sinh[x]]/a + (b^2*Log[Sinh[x]])/a^3 + (b^4*Log[a*Cosh[x] + b*Sinh[x]])/(a^3*(a^2 - b^2))}
{Coth[x]^4/(a + b*Tanh[x]), x, 9, (a*x)/(a^2 - b^2) - Coth[x]/a - (b^2*Coth[x])/a^3 + (b*Coth[x]^2)/(2*a^2) - Coth[x]^3/(3*a) - (b*Log[Sinh[x]])/a^2 - (b^3*Log[Sinh[x]])/a^4 - (b^5*Log[a*Cosh[x] + b*Sinh[x]])/(a^4*(a^2 - b^2))}

{Coth[x]/(1 + Tanh[x]), x, 4, -(x/2) + Log[Sinh[x]] + 1/(2*(1 + Tanh[x]))}
{Coth[x]^2/(1 + Tanh[x]), x, 5, (3*x)/2 - Coth[x] - Log[Sinh[x]] - 1/(2*(1 + Tanh[x]))}
{Coth[x]^3/(1 + Tanh[x]), x, 7, -((3*x)/2) + Coth[x] - Coth[x]^2/2 + 2*Log[Sinh[x]] + 1/(2*(1 + Tanh[x]))}
{Coth[x]^4/(1 + Tanh[x]), x, 9, (5*x)/2 - 2*Coth[x] + Coth[x]^2/2 - Coth[x]^3/3 - 2*Log[Sinh[x]] - 1/(2*(1 + Tanh[x]))}


(* Integrands of the form Sech[x]^m/(a+b*Tanh[x]) where m is a positive integer *)
{Sech[x]/(a + b*Tanh[x]), x, 2, (2*ArcTan[(b + a*Tanh[x/2])/Sqrt[a^2 - b^2]])/Sqrt[a^2 - b^2]}
{Sech[x]^2/(a + b*Tanh[x]), x, 2, Log[a + b*Tanh[x]]/b}
{Sech[x]^3/(a + b*Tanh[x]), x, 7, (2*a*ArcTan[Tanh[x/2]])/b^2 - (2*Sqrt[a^2 - b^2]*ArcTan[(b + a*Tanh[x/2])/Sqrt[a^2 - b^2]])/b^2 + 2/(b*(1 + Tanh[x/2]^2))}
{Sech[x]^4/(a + b*Tanh[x]), x, 5, -(((a^2 - b^2)*Log[a + b*Tanh[x]])/b^3) + (a*Tanh[x])/b^2 - Tanh[x]^2/(2*b)}

{Sech[x]/(1 + Tanh[x]), x, 2, -Cosh[x] + Sinh[x]}
{Sech[x]^2/(1 + Tanh[x]), x, 2, Log[1 + Tanh[x]]}
{Sech[x]^3/(1 + Tanh[x]), x, 4, ArcTan[Sinh[x]] + Sech[x]}
{Sech[x]^4/(1 + Tanh[x]), x, 2, Tanh[x] - Tanh[x]^2/2}


(* Integrands of the form Csch[x]^m/(a+b*Tanh[x]) where m is a positive integer *)
{Csch[x]/(a + b*Tanh[x]), x, 4, -(ArcCoth[Cosh[x]]/a) - (2*b*ArcTan[(b + a*Tanh[x/2])/Sqrt[a^2 - b^2]])/(a*Sqrt[a^2 - b^2])}
{Csch[x]^2/(a + b*Tanh[x]), x, 4, -(Coth[x]/a) + (b*Log[b + a*Coth[x]])/a^2}
{Csch[x]^3/(a + b*Tanh[x]), x, 6, (2*b*Sqrt[a^2 - b^2]*ArcTan[(b + a*Tanh[x/2])/Sqrt[a^2 - b^2]])/a^3 + (b*Coth[x/2])/(2*a^2) - Coth[x/2]^2/(8*a) - ((a^2 - 2*b^2)*Log[Tanh[x/2]])/(2*a^3) - (b*Tanh[x/2])/(2*a^2) + Tanh[x/2]^2/(8*a)}
{Csch[x]^4/(a + b*Tanh[x]), x, 5, ((a^2 - b^2)*Coth[x])/a^3 + (b*Coth[x]^2)/(2*a^2) - Coth[x]^3/(3*a) - (b*(a^2 - b^2)*Log[b + a*Coth[x]])/a^4}

{Csch[x]/(1 + Tanh[x]), x, 4, -ArcCoth[Cosh[x]] + Cosh[x] - Sinh[x]}
{Csch[x]^2/(1 + Tanh[x]), x, 4, -Coth[x] + Log[1 + Coth[x]]}
{Csch[x]^3/(1 + Tanh[x]), x, 5, (-(1/2))*ArcCoth[Cosh[x]] + Csch[x] - (1/2)*Coth[x]*Csch[x]}
{Csch[x]^4/(1 + Tanh[x]), x, 2, Coth[x]^2/2 - Coth[x]^3/3}

(* Following hangs Mathematica 6 & 7: *) 
{Csch[x]/(I + Tanh[x]), x, 4, I*ArcCoth[Cosh[x]] - I*Sqrt[2]*ArcTanh[(1 + I*Tanh[x/2])/Sqrt[2]]}


(* ::Subsubsection::Closed:: *)
(*Integrands of the form Hyper[x]^m / (a+b Coth[x])*)


(* Integrands of the form Sinh[x]^m/(a+b*Coth[x]) where m is a positive integer *)
{Sinh[x]/(a + b*Coth[x]), x, 5, -((2*b^2*ArcTanh[(a + b*Tanh[x/2])/Sqrt[a^2 - b^2]])/(a^2 - b^2)^(3/2)) + (a*Cosh[x])/(a^2 - b^2) - (b*Sinh[x])/(a^2 - b^2)}
{Sinh[x]^2/(a + b*Coth[x]), x, 6, (a*b^2*x)/(a^2 - b^2)^2 - (a*x)/(2*(a^2 - b^2)) - (b^3*Log[b*Cosh[x] + a*Sinh[x]])/(a^2 - b^2)^2 + (a*Cosh[x]*Sinh[x])/(2*(a^2 - b^2)) - (b*Sinh[x]^2)/(2*(a^2 - b^2))}
{Sinh[x]^3/(a + b*Coth[x]), x, 10, -((2*b^4*ArcTanh[(a + b*Tanh[x/2])/Sqrt[a^2 - b^2]])/(a^2 - b^2)^(5/2)) + (a*b^2*Cosh[x])/(a^2 - b^2)^2 - (a*Cosh[x])/(a^2 - b^2) + (a*Cosh[x]^3)/(3*(a^2 - b^2)) - (b^3*Sinh[x])/(a^2 - b^2)^2 - (b*Sinh[x]^3)/(3*(a^2 - b^2))}
{Sinh[x]^4/(a + b*Coth[x]), x, 11, (a*b^4*x)/(a^2 - b^2)^3 - (a*b^2*x)/(2*(a^2 - b^2)^2) + (3*a*x)/(8*(a^2 - b^2)) - (b^5*Log[b*Cosh[x] + a*Sinh[x]])/(a^2 - b^2)^3 + (a*b^2*Cosh[x]*Sinh[x])/(2*(a^2 - b^2)^2) - (3*a*Cosh[x]*Sinh[x])/(8*(a^2 - b^2)) - (b^3*Sinh[x]^2)/(2*(a^2 - b^2)^2) + (a*Cosh[x]*Sinh[x]^3)/(4*(a^2 - b^2)) - (b*Sinh[x]^4)/(4*(a^2 - b^2))}

{Sinh[x]/(1 + Coth[x]), x, 8, Cosh[x] - Cosh[x]^3/3 + Sinh[x]^3/3}
{Sinh[x]^2/(1 + Coth[x]), x, 8, -((3*x)/8) + (3/8)*Cosh[x]*Sinh[x] - (1/4)*Cosh[x]*Sinh[x]^3 + Sinh[x]^4/4}
{Sinh[x]^3/(1 + Coth[x]), x, 8, -Cosh[x] + (2*Cosh[x]^3)/3 - Cosh[x]^5/5 + Sinh[x]^5/5}
{Sinh[x]^4/(1 + Coth[x]), x, 9, (5*x)/16 - (5/16)*Cosh[x]*Sinh[x] + (5/24)*Cosh[x]*Sinh[x]^3 - (1/6)*Cosh[x]*Sinh[x]^5 + Sinh[x]^6/6}


(* Integrands of the form Cosh[x]^m/(a+b*Coth[x]) where m is a positive integer *)
{Cosh[x]/(a + b*Coth[x]), x, 7, (2*a*b*ArcTanh[(a + b*Tanh[x/2])/Sqrt[a^2 - b^2]])/(a^2 - b^2)^(3/2) - (b*Cosh[x])/(a^2 - b^2) + (a*Sinh[x])/(a^2 - b^2), (2*a*b*ArcTanh[(a + b*Tanh[x/2])/Sqrt[a^2 - b^2]])/(a^2 - b^2)^(3/2) + 1/((a + b)*(1 - Tanh[x/2])) - 1/((a - b)*(1 + Tanh[x/2]))}
{Cosh[x]^2/(a + b*Coth[x]), x, 5, x/(4*(a - b)) + x/(4*(a + b)) + (a*b^2*x)/(a^2 - b^2)^2 - (a^2*b*Log[b*Cosh[x] + a*Sinh[x]])/(a^2 - b^2)^2 + 1/(4*(a + b)*(1 - Tanh[x])) - 1/(4*(a - b)*(1 + Tanh[x]))}
{Cosh[x]^3/(a + b*Coth[x]), x, 20, (3*a*b*ArcTanh[(a + b*Tanh[x/2])/Sqrt[a^2 - b^2]])/(2*(a^2 - b^2)^(3/2)) + (a*b*(a^2 + 3*b^2)*ArcTanh[(a + b*Tanh[x/2])/Sqrt[a^2 - b^2]])/(2*(a^2 - b^2)^(5/2)) + 1/(3*(a + b)*(1 - Tanh[x/2])^3) - 1/(2*(a + b)*(1 - Tanh[x/2])^2) + (a - b)/(4*(a + b)^2*(1 - Tanh[x/2])) + 3/(4*(a + b)*(1 - Tanh[x/2])) - 1/(3*(a - b)*(1 + Tanh[x/2])^3) + 1/(2*(a - b)*(1 + Tanh[x/2])^2) - 3/(4*(a - b)*(1 + Tanh[x/2])) - (a + b)/(4*(a - b)^2*(1 + Tanh[x/2]))}
{Cosh[x]^4/(a + b*Coth[x]), x, 9, (a*x)/(8*(a - b)^2) + x/(16*(a - b)) + (a*x)/(8*(a + b)^2) + x/(16*(a + b)) + (a^3*b^2*x)/(a^2 - b^2)^3 - (a^4*b*Log[b*Cosh[x] + a*Sinh[x]])/(a^2 - b^2)^3 + 1/(16*(a + b)*(1 - Tanh[x])^2) + a/(8*(a + b)^2*(1 - Tanh[x])) + 1/(16*(a + b)*(1 - Tanh[x])) - 1/(16*(a - b)*(1 + Tanh[x])^2) - a/(8*(a - b)^2*(1 + Tanh[x])) - 1/(16*(a - b)*(1 + Tanh[x]))}

{Cosh[x]/(1 + Coth[x]), x, 6, Cosh[x]^3/3 - Sinh[x]^3/3}
{Cosh[x]^2/(1 + Coth[x]), x, 6, x/8 + Cosh[x]^4/4 + (1/8)*Cosh[x]*Sinh[x] - (1/4)*Cosh[x]^3*Sinh[x]}
{Cosh[x]^3/(1 + Coth[x]), x, 7, Cosh[x]^5/5 - Sinh[x]^3/3 - Sinh[x]^5/5}
{Cosh[x]^4/(1 + Coth[x]), x, 7, x/16 + Cosh[x]^6/6 + (1/16)*Cosh[x]*Sinh[x] + (1/24)*Cosh[x]^3*Sinh[x] - (1/6)*Cosh[x]^5*Sinh[x]}


(* Integrands of the form Tanh[x]^m/(a+b*Coth[x]) where m is a positive integer *)
{Tanh[x]/(a + b*Coth[x]), x, 4, -((b*x)/(a^2 - b^2)) + Log[Cosh[x]]/a + (b^2*Log[b*Cosh[x] + a*Sinh[x]])/(a*(a^2 - b^2))}
{Tanh[x]^2/(a + b*Coth[x]), x, 5, (a*x)/(a^2 - b^2) - (b*Log[Cosh[x]])/a^2 - (b^3*Log[b*Cosh[x] + a*Sinh[x]])/(a^2*(a^2 - b^2)) - Tanh[x]/a}
{Tanh[x]^3/(a + b*Coth[x]), x, 7, -((b*x)/(a^2 - b^2)) + Log[Cosh[x]]/a + (b^2*Log[Cosh[x]])/a^3 + (b^4*Log[b*Cosh[x] + a*Sinh[x]])/(a^3*(a^2 - b^2)) + (b*Tanh[x])/a^2 - Tanh[x]^2/(2*a)}
{Tanh[x]^4/(a + b*Coth[x]), x, 9, (a*x)/(a^2 - b^2) - (b*Log[Cosh[x]])/a^2 - (b^3*Log[Cosh[x]])/a^4 - (b^5*Log[b*Cosh[x] + a*Sinh[x]])/(a^4*(a^2 - b^2)) - Tanh[x]/a - (b^2*Tanh[x])/a^3 + (b*Tanh[x]^2)/(2*a^2) - Tanh[x]^3/(3*a)}

{Tanh[x]/(1 + Coth[x]), x, 4, -(x/2) + Log[Cosh[x]] - 1/(2*(1 + Tanh[x]))}
{Tanh[x]^2/(1 + Coth[x]), x, 5, (3*x)/2 - Log[Cosh[x]] - Tanh[x] + 1/(2*(1 + Tanh[x]))}
{Tanh[x]^3/(1 + Coth[x]), x, 7, -((3*x)/2) + 2*Log[Cosh[x]] + Tanh[x] - Tanh[x]^2/2 - 1/(2*(1 + Tanh[x]))}
{Tanh[x]^4/(1 + Coth[x]), x, 9, (5*x)/2 - 2*Log[Cosh[x]] - 2*Tanh[x] + Tanh[x]^2/2 - Tanh[x]^3/3 + 1/(2*(1 + Tanh[x]))}


(* Integrands of the form Coth[x]^m/(a+b*Coth[x]) where m is a positive integer *)
{Coth[x]/(a + b*Coth[x]), x, 2, -((b*x)/(a^2 - b^2)) + (a*Log[b*Cosh[x] + a*Sinh[x]])/(a^2 - b^2)}
{Coth[x]^2/(a + b*Coth[x]), x, 4, (a*x)/(a^2 - b^2) + Log[Sinh[x]]/b - (a^2*Log[b*Cosh[x] + a*Sinh[x]])/(b*(a^2 - b^2))}
{Coth[x]^3/(a + b*Coth[x]), x, 5, -((b*x)/(a^2 - b^2)) - Coth[x]/b - (a*Log[Sinh[x]])/b^2 + (a^3*Log[b*Cosh[x] + a*Sinh[x]])/(b^2*(a^2 - b^2))}
{Coth[x]^4/(a + b*Coth[x]), x, 7, (a*x)/(a^2 - b^2) + (a*Coth[x])/b^2 - Coth[x]^2/(2*b) + (a^2*Log[Sinh[x]])/b^3 + Log[Sinh[x]]/b - (a^4*Log[b*Cosh[x] + a*Sinh[x]])/(b^3*(a^2 - b^2))}

{Coth[x]/(1 + Coth[x]), x, 2, x/2 + 1/(2*(1 + Coth[x]))}
{Coth[x]^2/(1 + Coth[x]), x, 4, -(x/2) + Log[Sinh[x]] + 1/(2*(1 + Tanh[x]))}
{Coth[x]^3/(1 + Coth[x]), x, 5, (3*x)/2 - Coth[x] - Log[Sinh[x]] - 1/(2*(1 + Tanh[x]))}
{Coth[x]^4/(1 + Coth[x]), x, 7, -((3*x)/2) + Coth[x] - Coth[x]^2/2 + 2*Log[Sinh[x]] + 1/(2*(1 + Tanh[x]))}


(* Integrands of the form Sech[x]^m/(a+b*Coth[x]) where m is a positive integer *)
{Sech[x]/(a + b*Coth[x]), x, 4, ArcTan[Sinh[x]]/a + (2*b*ArcTanh[(a + b*Tanh[x/2])/Sqrt[a^2 - b^2]])/(a*Sqrt[a^2 - b^2])}
{Sech[x]^2/(a + b*Coth[x]), x, 4, -((b*Log[b + a*Tanh[x]])/a^2) + Tanh[x]/a}
{Sech[x]^3/(a + b*Coth[x]), x, 12, ArcTan[Tanh[x/2]]/a - (2*b^2*ArcTan[Tanh[x/2]])/a^3 + (2*b*Sqrt[a^2 - b^2]*ArcTanh[(a + b*Tanh[x/2])/Sqrt[a^2 - b^2]])/a^3 + (2*Tanh[x/2])/(a*(1 + Tanh[x/2]^2)^2) - (2*b)/(a^2*(1 + Tanh[x/2]^2)) - Tanh[x/2]/(a*(1 + Tanh[x/2]^2))}
{Sech[x]^4/(a + b*Coth[x]), x, 5, -((b*(a^2 - b^2)*Log[b + a*Tanh[x]])/a^4) + ((a^2 - b^2)*Tanh[x])/a^3 + (b*Tanh[x]^2)/(2*a^2) - Tanh[x]^3/(3*a)}

{Sech[x]/(1 + Coth[x]), x, 4, ArcTan[Sinh[x]] + Cosh[x] - Sinh[x]}
{Sech[x]^2/(1 + Coth[x]), x, 4, -Log[1 + Tanh[x]] + Tanh[x]}
{Sech[x]^3/(1 + Coth[x]), x, 5, (-(1/2))*ArcTan[Sinh[x]] - Sech[x] + (1/2)*Sech[x]*Tanh[x]}
{Sech[x]^4/(1 + Coth[x]), x, 2, Tanh[x]^2/2 - Tanh[x]^3/3}

(* Following hangs Mathematica: *) 
{Sech[x]/(I + 2*Coth[x]), x, 4, (-I)*ArcTan[Sinh[x]] + (4*I*ArcTan[(I + 2*Tanh[x/2])/Sqrt[5]])/Sqrt[5]}


(* Integrands of the form Csch[x]^m/(a+b*Coth[x]) where m is a positive integer *)
{Csch[x]/(a + b*Coth[x]), x, 2, -((2*ArcTanh[(a + b*Tanh[x/2])/Sqrt[a^2 - b^2]])/Sqrt[a^2 - b^2])}
{Csch[x]^2/(a + b*Coth[x]), x, 2, -(Log[a + b*Coth[x]]/b)}
{Csch[x]^3/(a + b*Coth[x]), x, 6, -((2*Sqrt[a^2 - b^2]*ArcTanh[(a + b*Tanh[x/2])/Sqrt[a^2 - b^2]])/b^2) - Coth[x/2]/(2*b) - (a*Log[Tanh[x/2]])/b^2 + Tanh[x/2]/(2*b)}
{Csch[x]^4/(a + b*Coth[x]), x, 5, (a*Coth[x])/b^2 - Coth[x]^2/(2*b) - ((a^2 - b^2)*Log[a + b*Coth[x]])/b^3}

{Csch[x]/(1 + Coth[x]), x, 2, -Cosh[x] + Sinh[x]}
{Csch[x]^2/(1 + Coth[x]), x, 2, -Log[1 + Coth[x]]}
{Csch[x]^3/(1 + Coth[x]), x, 4, ArcCoth[Cosh[x]] - Csch[x]}
{Csch[x]^4/(1 + Coth[x]), x, 2, Coth[x] - Coth[x]^2/2}


(* ::Subsubsection::Closed:: *)
(*Integrands of the form Hyper[x]^m / (a+b Sech[x])*)


(* Integrands of the form Sinh[x]^m/(a+b*Sech[x]) where m is a positive integer *)
{Sinh[x]/(a + b*Sech[x]), x, 4, Cosh[x]/a - (b*Log[b + a*Cosh[x]])/a^2}
{Sinh[x]^2/(a + b*Sech[x]), x, 5, -(x/(2*a)) + (b^2*x)/a^3 + (2*b*Sqrt[a^2 - b^2]*ArcTan[((a - b)*Tanh[x/2])/Sqrt[a^2 - b^2]])/a^3 - (b*Sinh[x])/a^2 + (Cosh[x]*Sinh[x])/(2*a)}
{Sinh[x]^3/(a + b*Sech[x]), x, 5, -(((a^2 - b^2)*Cosh[x])/a^3) - (b*Cosh[x]^2)/(2*a^2) + Cosh[x]^3/(3*a) + (b*(a^2 - b^2)*Log[b + a*Cosh[x]])/a^4}
{Sinh[x]^4/(a + b*Sech[x]), x, 9, -((5*x)/(8*a)) + (b^2*x)/(2*a^3) + ((a^2 - b^2)^2*x)/a^5 - (2*b*(a^2 - b^2)^(3/2)*ArcTan[((a - b)*Tanh[x/2])/Sqrt[a^2 - b^2]])/a^5 + (b*Sinh[x])/a^2 - (b^3*Sinh[x])/a^4 - (5*Cosh[x]*Sinh[x])/(8*a) + (b^2*Cosh[x]*Sinh[x])/(2*a^3) + (Cosh[x]^3*Sinh[x])/(4*a) - (b*Sinh[x]^3)/(3*a^2)}

{Sinh[x]/(a + a*Sech[x]), x, 4, Cosh[x]/a - Log[1 + Cosh[x]]/a}
{Sinh[x]^2/(a + a*Sech[x]), x, 4, x/(2*a) - Sinh[x]/a + (Cosh[x]*Sinh[x])/(2*a)}
{Sinh[x]^3/(a + a*Sech[x]), x, 2, -(Cosh[x]^2/(2*a)) + Cosh[x]^3/(3*a)}
{Sinh[x]^4/(a + a*Sech[x]), x, 8, -(x/(8*a)) - (Cosh[x]*Sinh[x])/(8*a) + (Cosh[x]^3*Sinh[x])/(4*a) - Sinh[x]^3/(3*a)}


(* Integrands of the form Cosh[x]^m/(a+b*Sech[x]) where m is a positive integer *)
{Cosh[x]/(a + b*Sech[x]), x, 5, -((b*x)/a^2) + (2*b^2*ArcTan[((a - b)*Tanh[x/2])/Sqrt[a^2 - b^2]])/(a^2*Sqrt[a^2 - b^2]) + Sinh[x]/a}
{Cosh[x]^2/(a + b*Sech[x]), x, 6, x/(2*a) + (b^2*x)/a^3 - (2*b^3*ArcTan[((a - b)*Tanh[x/2])/Sqrt[a^2 - b^2]])/(a^3*Sqrt[a^2 - b^2]) - (b*Sinh[x])/a^2 + (Cosh[x]*Sinh[x])/(2*a)}
{Cosh[x]^3/(a + b*Sech[x]), x, 8, -((b*x)/(2*a^2)) - (b^3*x)/a^4 + (2*b^4*ArcTan[((a - b)*Tanh[x/2])/Sqrt[a^2 - b^2]])/(a^4*Sqrt[a^2 - b^2]) + Sinh[x]/a + (b^2*Sinh[x])/a^3 - (b*Cosh[x]*Sinh[x])/(2*a^2) + Sinh[x]^3/(3*a)}
{Cosh[x]^4/(a + b*Sech[x]), x, 10, (3*x)/(8*a) + (b^2*x)/(2*a^3) + (b^4*x)/a^5 - (2*b^5*ArcTan[((a - b)*Tanh[x/2])/Sqrt[a^2 - b^2]])/(a^5*Sqrt[a^2 - b^2]) - (b*Sinh[x])/a^2 - (b^3*Sinh[x])/a^4 + (3*Cosh[x]*Sinh[x])/(8*a) + (b^2*Cosh[x]*Sinh[x])/(2*a^3) + (Cosh[x]^3*Sinh[x])/(4*a) - (b*Sinh[x]^3)/(3*a^2)}

{Cosh[x]/(a + a*Sech[x]), x, 5, -(x/a) + Sinh[x]/a + Sinh[x]/(a*(1 + Cosh[x]))}
{Cosh[x]^2/(a + a*Sech[x]), x, 6, (3*x)/(2*a) - Sinh[x]/a + (Cosh[x]*Sinh[x])/(2*a) - Sinh[x]/(a*(1 + Cosh[x]))}
{Cosh[x]^3/(a + a*Sech[x]), x, 8, -((3*x)/(2*a)) + (2*Sinh[x])/a - (Cosh[x]*Sinh[x])/(2*a) + Sinh[x]/(a*(1 + Cosh[x])) + Sinh[x]^3/(3*a)}
{Cosh[x]^4/(a + a*Sech[x]), x, 10, (15*x)/(8*a) - (2*Sinh[x])/a + (7*Cosh[x]*Sinh[x])/(8*a) + (Cosh[x]^3*Sinh[x])/(4*a) - Sinh[x]/(a*(1 + Cosh[x])) - Sinh[x]^3/(3*a)}


(* Integrands of the form Tanh[x]^m/(a+b*Sech[x]) where m is a positive integer *)
{Tanh[x]/(a + b*Sech[x]), x, 2, Log[b + a*Cosh[x]]/a}
{Tanh[x]^2/(a + b*Sech[x]), x, 4, x/a - ArcTan[Sinh[x]]/b + (2*Sqrt[a^2 - b^2]*ArcTan[((a - b)*Tanh[x/2])/Sqrt[a^2 - b^2]])/(a*b)}
{Tanh[x]^3/(a + b*Sech[x]), x, 5, (a*Log[Cosh[x]])/b^2 - ((a^2 - b^2)*Log[b + a*Cosh[x]])/(a*b^2) + Sech[x]/b}
{Tanh[x]^4/(a + b*Sech[x]), x, 7, x/a + (a^2*ArcTan[Sinh[x]])/b^3 - (3*ArcTan[Sinh[x]])/(2*b) - (2*(a^2 - b^2)^(3/2)*ArcTan[((a - b)*Tanh[x/2])/Sqrt[a^2 - b^2]])/(a*b^3) - (a*Tanh[x])/b^2 + (Sech[x]*Tanh[x])/(2*b)}

{Tanh[x]/(a + a*Sech[x]), x, 3, Log[1 + Cosh[x]]/a}
{Tanh[x]^2/(a + a*Sech[x]), x, 3, x/a - ArcTan[Sinh[x]]/a}
{Tanh[x]^3/(a + a*Sech[x]), x, 3, Log[Cosh[x]]/a + Sech[x]/a}
{Tanh[x]^4/(a + a*Sech[x]), x, 6, x/a - ArcTan[Sinh[x]]/(2*a) - Tanh[x]/a + (Sech[x]*Tanh[x])/(2*a)}


(* Integrands of the form Coth[x]^m/(a+b*Sech[x]) where m is a positive integer *)
{Coth[x]/(a + b*Sech[x]), x, 6, Log[1 - Cosh[x]]/(2*(a + b)) + Log[1 + Cosh[x]]/(2*(a - b)) - (b^2*Log[b + a*Cosh[x]])/(a*(a^2 - b^2))}
{Coth[x]^2/(a + b*Sech[x]), x, 5, x/a + (2*b^3*ArcTan[((a - b)*Tanh[x/2])/Sqrt[a^2 - b^2]])/(a*(a^2 - b^2)^(3/2)) + Sinh[x]/(2*(a + b)*(1 - Cosh[x])) - Sinh[x]/(2*(a - b)*(1 + Cosh[x]))}
{Coth[x]^3/(a + b*Sech[x]), x, 8, 1/(4*(a + b)*(1 - Cosh[x])) + 1/(4*(a - b)*(1 + Cosh[x])) + ((2*a + 3*b)*Log[1 - Cosh[x]])/(4*(a + b)^2) + ((2*a - 3*b)*Log[1 + Cosh[x]])/(4*(a - b)^2) + (b^4*Log[b + a*Cosh[x]])/(a*(a^2 - b^2)^2)}
{Coth[x]^4/(a + b*Sech[x]), x, 9, x/a - (2*b^5*ArcTan[((a - b)*Tanh[x/2])/Sqrt[a^2 - b^2]])/(a*(a^2 - b^2)^(5/2)) - Sinh[x]/(12*(a + b)*(1 - Cosh[x])^2) - Sinh[x]/(12*(a + b)*(1 - Cosh[x])) + ((3*a + 4*b)*Sinh[x])/(4*(a + b)^2*(1 - Cosh[x])) + Sinh[x]/(12*(a - b)*(1 + Cosh[x])^2) - ((3*a - 4*b)*Sinh[x])/(4*(a - b)^2*(1 + Cosh[x])) + Sinh[x]/(12*(a - b)*(1 + Cosh[x]))}

{Coth[x]/(a + a*Sech[x]), x, 7, 1/(2*a*(1 + Cosh[x])) + Log[1 - Cosh[x]]/(4*a) + (3*Log[1 + Cosh[x]])/(4*a)}
{Coth[x]^2/(a + a*Sech[x]), x, 6, x/a + Sinh[x]/(4*a*(1 - Cosh[x])) + Sinh[x]/(6*a*(1 + Cosh[x])^2) - (13*Sinh[x])/(12*a*(1 + Cosh[x]))}
{Coth[x]^3/(a + a*Sech[x]), x, 9, 1/(8*a*(1 - Cosh[x])) - 1/(8*a*(1 + Cosh[x])^2) + 3/(4*a*(1 + Cosh[x])) + (5*Log[1 - Cosh[x]])/(16*a) + (11*Log[1 + Cosh[x]])/(16*a)}
{Coth[x]^4/(a + a*Sech[x]), x, 11, x/a - Sinh[x]/(24*a*(1 - Cosh[x])^2) + (19*Sinh[x])/(48*a*(1 - Cosh[x])) - Sinh[x]/(20*a*(1 + Cosh[x])^3) + (3*Sinh[x])/(10*a*(1 + Cosh[x])^2) - (91*Sinh[x])/(80*a*(1 + Cosh[x]))}


(* Integrands of the form Sech[x]^m/(a+b*Sech[x]) where m is a positive integer *)
{Sech[x]/(a + b*Sech[x]), x, 2, (2*ArcTan[((a - b)*Tanh[x/2])/Sqrt[a^2 - b^2]])/Sqrt[a^2 - b^2]}
{Sech[x]^2/(a + b*Sech[x]), x, 6, ArcTan[Sinh[x]]/b - (2*a*ArcTan[((a - b)*Tanh[x/2])/Sqrt[a^2 - b^2]])/(b*Sqrt[a^2 - b^2])}
{Sech[x]^3/(a + b*Sech[x]), x, 7, -((a*ArcTan[Sinh[x]])/b^2) + (2*a^2*ArcTan[((a - b)*Tanh[x/2])/Sqrt[a^2 - b^2]])/(b^2*Sqrt[a^2 - b^2]) + Tanh[x]/b}
{Sech[x]^4/(a + b*Sech[x]), x, 9, (a^2*ArcTan[Sinh[x]])/b^3 + ArcTan[Sinh[x]]/(2*b) - (2*a^3*ArcTan[((a - b)*Tanh[x/2])/Sqrt[a^2 - b^2]])/(b^3*Sqrt[a^2 - b^2]) - (a*Tanh[x])/b^2 + (Sech[x]*Tanh[x])/(2*b)}

{Sech[x]/(a + a*Sech[x]), x, 2, Sinh[x]/(a*(1 + Cosh[x]))}
{Sech[x]^2/(a + a*Sech[x]), x, 6, ArcTan[Sinh[x]]/a - Sinh[x]/(a*(1 + Cosh[x]))}
{Sech[x]^3/(a + a*Sech[x]), x, 7, -(ArcTan[Sinh[x]]/a) + Sinh[x]/(a*(1 + Cosh[x])) + Tanh[x]/a}
{Sech[x]^4/(a + a*Sech[x]), x, 9, (3*ArcTan[Sinh[x]])/(2*a) - Sinh[x]/(a*(1 + Cosh[x])) - Tanh[x]/a + (Sech[x]*Tanh[x])/(2*a)}


(* Integrands of the form Csch[x]^m/(a+b*Sech[x]) where m is a positive integer *)
{Csch[x]/(a + b*Sech[x]), x, 6, Log[1 - Cosh[x]]/(2*(a + b)) - Log[1 + Cosh[x]]/(2*(a - b)) + (b*Log[b + a*Cosh[x]])/(a^2 - b^2)}
{Csch[x]^2/(a + b*Sech[x]), x, 5, (2*a*b*ArcTan[((a - b)*Tanh[x/2])/Sqrt[a^2 - b^2]])/(a^2 - b^2)^(3/2) + Sinh[x]/(2*(a + b)*(1 - Cosh[x])) - Sinh[x]/(2*(a - b)*(1 + Cosh[x]))}
{Csch[x]^3/(a + b*Sech[x]), x, 8, 1/(4*(a + b)*(1 - Cosh[x])) - 1/(4*(a - b)*(1 + Cosh[x])) - (a*Log[1 - Cosh[x]])/(4*(a + b)^2) + (a*Log[1 + Cosh[x]])/(4*(a - b)^2) - (a^2*b*Log[b + a*Cosh[x]])/(a^2 - b^2)^2}
{Csch[x]^4/(a + b*Sech[x]), x, 9, -((2*a^3*b*ArcTan[((a - b)*Tanh[x/2])/Sqrt[a^2 - b^2]])/(a^2 - b^2)^(5/2)) - Sinh[x]/(12*(a + b)*(1 - Cosh[x])^2) - (a*Sinh[x])/(4*(a + b)^2*(1 - Cosh[x])) - Sinh[x]/(12*(a + b)*(1 - Cosh[x])) + Sinh[x]/(12*(a - b)*(1 + Cosh[x])^2) + (a*Sinh[x])/(4*(a - b)^2*(1 + Cosh[x])) + Sinh[x]/(12*(a - b)*(1 + Cosh[x]))}

{Csch[x]/(a + a*Sech[x]), x, 6, -(ArcTanh[Cosh[x]]/(2*a)) - 1/(2*a*(1 + Cosh[x]))}
{Csch[x]^2/(a + a*Sech[x]), x, 6, Sinh[x]/(4*a*(1 - Cosh[x])) + Sinh[x]/(6*a*(1 + Cosh[x])^2) - Sinh[x]/(12*a*(1 + Cosh[x]))}
{Csch[x]^3/(a + a*Sech[x]), x, 7, ArcTanh[Cosh[x]]/(8*a) + 1/(8*a*(1 - Cosh[x])) + 1/(8*a*(1 + Cosh[x])^2)}
{Csch[x]^4/(a + a*Sech[x]), x, 9, -(Sinh[x]/(24*a*(1 - Cosh[x])^2)) - (5*Sinh[x])/(48*a*(1 - Cosh[x])) - Sinh[x]/(20*a*(1 + Cosh[x])^3) - Sinh[x]/(30*a*(1 + Cosh[x])^2) + (7*Sinh[x])/(240*a*(1 + Cosh[x]))}


(* ::Subsubsection::Closed:: *)
(*Integrands of the form Hyper[x]^m / (a+b Csch[x])*)


(* Integrands of the form Sinh[x]^m/(a+b*Csch[x]) where m is a positive integer *)
{Sinh[x]/(a + b*Csch[x]), x, 5, -((b*x)/a^2) - (2*b^2*ArcTanh[(a - b*Tanh[x/2])/Sqrt[a^2 + b^2]])/(a^2*Sqrt[a^2 + b^2]) + Cosh[x]/a}
{Sinh[x]^2/(a + b*Csch[x]), x, 6, -(x/(2*a)) + (b^2*x)/a^3 + (2*b^3*ArcTanh[(a - b*Tanh[x/2])/Sqrt[a^2 + b^2]])/(a^3*Sqrt[a^2 + b^2]) - (b*Cosh[x])/a^2 + (Cosh[x]*Sinh[x])/(2*a)}
{Sinh[x]^3/(a + b*Csch[x]), x, 8, (b*x)/(2*a^2) - (b^3*x)/a^4 - (2*b^4*ArcTanh[(a - b*Tanh[x/2])/Sqrt[a^2 + b^2]])/(a^4*Sqrt[a^2 + b^2]) - Cosh[x]/a + (b^2*Cosh[x])/a^3 + Cosh[x]^3/(3*a) - (b*Cosh[x]*Sinh[x])/(2*a^2)}
{Sinh[x]^4/(a + b*Csch[x]), x, 10, (3*x)/(8*a) - (b^2*x)/(2*a^3) + (b^4*x)/a^5 + (2*b^5*ArcTanh[(a - b*Tanh[x/2])/Sqrt[a^2 + b^2]])/(a^5*Sqrt[a^2 + b^2]) + (b*Cosh[x])/a^2 - (b^3*Cosh[x])/a^4 - (b*Cosh[x]^3)/(3*a^2) - (3*Cosh[x]*Sinh[x])/(8*a) + (b^2*Cosh[x]*Sinh[x])/(2*a^3) + (Cosh[x]*Sinh[x]^3)/(4*a)}

{Sinh[x]/(I + Csch[x]), x, 5, x - I*Cosh[x] - (I*Cosh[x])/(1 + I*Sinh[x])}
{Sinh[x]^2/(I + Csch[x]), x, 6, (3*I*x)/2 + Cosh[x] + Cosh[x]/(1 + I*Sinh[x]) - (1/2)*I*Cosh[x]*Sinh[x]}
{Sinh[x]^3/(I + Csch[x]), x, 8, -((3*x)/2) + 2*I*Cosh[x] - (1/3)*I*Cosh[x]^3 + (I*Cosh[x])/(1 + I*Sinh[x]) + (1/2)*Cosh[x]*Sinh[x]}
{Sinh[x]^4/(I + Csch[x]), x, 10, -((15*I*x)/8) - 2*Cosh[x] + Cosh[x]^3/3 - Cosh[x]/(1 + I*Sinh[x]) + (7/8)*I*Cosh[x]*Sinh[x] - (1/4)*I*Cosh[x]*Sinh[x]^3}


(* Integrands of the form Cosh[x]^m/(a+b*Csch[x]) where m is a positive integer *)
{Cosh[x]/(a + b*Csch[x]), x, 4, -((b*Log[b + a*Sinh[x]])/a^2) + Sinh[x]/a}
{Cosh[x]^2/(a + b*Csch[x]), x, 5, x/(2*a) + (b^2*x)/a^3 + (2*b*Sqrt[a^2 + b^2]*ArcTanh[(a - b*Tanh[x/2])/Sqrt[a^2 + b^2]])/a^3 - (b*Cosh[x])/a^2 + (Cosh[x]*Sinh[x])/(2*a)}
{Cosh[x]^3/(a + b*Csch[x]), x, 5, -((b*(a^2 + b^2)*Log[b + a*Sinh[x]])/a^4) + ((a^2 + b^2)*Sinh[x])/a^3 - (b*Sinh[x]^2)/(2*a^2) + Sinh[x]^3/(3*a)}
{Cosh[x]^4/(a + b*Csch[x]), x, 9, -((5*x)/(8*a)) - (b^2*x)/(2*a^3) + ((a^2 + b^2)^2*x)/a^5 + (2*b*(a^2 + b^2)^(3/2)*ArcTanh[(a - b*Tanh[x/2])/Sqrt[a^2 + b^2]])/a^5 - (b*Cosh[x])/a^2 - (b^3*Cosh[x])/a^4 - (b*Cosh[x]^3)/(3*a^2) + (5*Cosh[x]*Sinh[x])/(8*a) + (b^2*Cosh[x]*Sinh[x])/(2*a^3) + (Cosh[x]*Sinh[x]^3)/(4*a)}

{Cosh[x]/(I + Csch[x]), x, 4, Log[-I + Sinh[x]] - I*Sinh[x]}
{Cosh[x]^2/(I + Csch[x]), x, 4, (I*x)/2 + Cosh[x] - (1/2)*I*Cosh[x]*Sinh[x]}
{Cosh[x]^3/(I + Csch[x]), x, 2, Sinh[x]^2/2 - (1/3)*I*Sinh[x]^3}
{Cosh[x]^4/(I + Csch[x]), x, 8, (I*x)/8 + Cosh[x]^3/3 - (1/8)*I*Cosh[x]*Sinh[x] - (1/4)*I*Cosh[x]*Sinh[x]^3}


(* Integrands of the form Tanh[x]^m/(a+b*Csch[x]) where m is a positive integer *)
{Tanh[x]/(a + b*Csch[x]), x, 7, -((b*ArcTan[Sinh[x]])/(a^2 + b^2)) + (a*Log[Cosh[x]^2])/(2*(a^2 + b^2)) + (b^2*Log[b + a*Sinh[x]])/(a*(a^2 + b^2))}
{Tanh[x]^2/(a + b*Csch[x]), x, 5, x/a + (2*b^3*ArcTanh[(a - b*Tanh[x/2])/Sqrt[a^2 + b^2]])/(a*(a^2 + b^2)^(3/2)) + (b*Sech[x])/(a^2 + b^2) - (a*Tanh[x])/(a^2 + b^2)}
{Tanh[x]^3/(a + b*Csch[x]), x, 10, (b*ArcTan[Sinh[x]])/(2*(a^2 + b^2)) - (b*(a^2 + 2*b^2)*ArcTan[Sinh[x]])/(a^2 + b^2)^2 + (a*(a^2 + 2*b^2)*Log[Cosh[x]^2])/(2*(a^2 + b^2)^2) + (b^4*Log[b + a*Sinh[x]])/(a*(a^2 + b^2)^2) + (a*Sech[x]^2)/(2*(a^2 + b^2)) + (b*Sech[x]*Tanh[x])/(2*(a^2 + b^2))}
{Tanh[x]^4/(a + b*Csch[x]), x, 8, x/a + (2*b^5*ArcTanh[(a - b*Tanh[x/2])/Sqrt[a^2 + b^2]])/(a*(a^2 + b^2)^(5/2)) + (b*(a^2 + 2*b^2)*Sech[x])/(a^2 + b^2)^2 - (b*Sech[x]^3)/(3*(a^2 + b^2)) + (a*Tanh[x])/(a^2 + b^2) - (a*(2*a^2 + 3*b^2)*Tanh[x])/(a^2 + b^2)^2 - (a*Tanh[x]^3)/(3*(a^2 + b^2))}

{Tanh[x]/(I + Csch[x]), x, 6, (-(3/4))*I*Log[-I + Sinh[x]] - (1/4)*I*Log[I + Sinh[x]] + 1/(2*(I - Sinh[x]))}
{Tanh[x]^2/(I + Csch[x]), x, 6, (-I)*x - Cosh[x]/(6*(I - Sinh[x])^2) + Cosh[x]/(4*(1 - I*Sinh[x])) - (13*Cosh[x])/(12*(1 + I*Sinh[x]))}
{Tanh[x]^3/(I + Csch[x]), x, 8, (-(11/16))*I*Log[-I + Sinh[x]] - (5/16)*I*Log[I + Sinh[x]] - I/(8*(I - Sinh[x])^2) + 3/(4*(I - Sinh[x])) + 1/(8*(I + Sinh[x]))}
{Tanh[x]^4/(I + Csch[x]), x, 11, (-I)*x + (I*Cosh[x])/(20*(I - Sinh[x])^3) - (3*Cosh[x])/(10*(I - Sinh[x])^2) + (19*Cosh[x])/(48*(1 - I*Sinh[x])) - (91*Cosh[x])/(80*(1 + I*Sinh[x])) + Cosh[x]/(24*(I + Sinh[x])^2)}


(* Integrands of the form Coth[x]^m/(a+b*Csch[x]) where m is a positive integer *)
{Coth[x]/(a + b*Csch[x]), x, 2, Log[b + a*Sinh[x]]/a}
{Coth[x]^2/(a + b*Csch[x]), x, 4, x/a - ArcCoth[Cosh[x]]/b + (2*Sqrt[a^2 + b^2]*ArcTanh[(a - b*Tanh[x/2])/Sqrt[a^2 + b^2]])/(a*b)}
{Coth[x]^3/(a + b*Csch[x]), x, 5, -(Csch[x]/b) - (a*Log[Sinh[x]])/b^2 + ((a^2 + b^2)*Log[b + a*Sinh[x]])/(a*b^2)}
{Coth[x]^4/(a + b*Csch[x]), x, 7, x/a - (a^2*ArcCoth[Cosh[x]])/b^3 - (3*ArcCoth[Cosh[x]])/(2*b) + (2*(a^2 + b^2)^(3/2)*ArcTanh[(a - b*Tanh[x/2])/Sqrt[a^2 + b^2]])/(a*b^3) + (a*Coth[x])/b^2 - (Coth[x]*Csch[x])/(2*b)}

{Coth[x]/(I + Csch[x]), x, 3, (-I)*Log[-I + Sinh[x]]}
{Coth[x]^2/(I + Csch[x]), x, 3, (-I)*x - ArcCoth[Cosh[x]]}
{Coth[x]^3/(I + Csch[x]), x, 3, -Csch[x] - I*Log[Sinh[x]]}
{Coth[x]^4/(I + Csch[x]), x, 6, (-I)*x - (1/2)*ArcCoth[Cosh[x]] + I*Coth[x] - (1/2)*Coth[x]*Csch[x]}


(* Integrands of the form Sech[x]^m/(a+b*Csch[x]) where m is a positive integer *)
{Sech[x]/(a + b*Csch[x]), x, 7, (a*ArcTan[Sinh[x]])/(a^2 + b^2) + (b*Log[Cosh[x]^2])/(2*(a^2 + b^2)) - (b*Log[b + a*Sinh[x]])/(a^2 + b^2)}
{Sech[x]^2/(a + b*Csch[x]), x, 5, (2*a*b*ArcTanh[(a - b*Tanh[x/2])/Sqrt[a^2 + b^2]])/(a^2 + b^2)^(3/2) - (b*Sech[x])/(a^2 + b^2) + (a*Tanh[x])/(a^2 + b^2)}
{Sech[x]^3/(a + b*Csch[x]), x, 10, -((a*b^2*ArcTan[Sinh[x]])/(a^2 + b^2)^2) + (a*ArcTan[Sinh[x]])/(2*(a^2 + b^2)) + (a^2*b*Log[Cosh[x]^2])/(2*(a^2 + b^2)^2) - (a^2*b*Log[b + a*Sinh[x]])/(a^2 + b^2)^2 - (b*Sech[x]^2)/(2*(a^2 + b^2)) + (a*Sech[x]*Tanh[x])/(2*(a^2 + b^2))}
{Sech[x]^4/(a + b*Csch[x]), x, 8, (2*a^3*b*ArcTanh[(a - b*Tanh[x/2])/Sqrt[a^2 + b^2]])/(a^2 + b^2)^(5/2) - (a^2*b*Sech[x])/(a^2 + b^2)^2 - (b*Sech[x]^3)/(3*(a^2 + b^2)) - (a*b^2*Tanh[x])/(a^2 + b^2)^2 + (a*Tanh[x])/(a^2 + b^2) - (a*Tanh[x]^3)/(3*(a^2 + b^2))}

{Sech[x]/(I + Csch[x]), x, 5, (-(1/2))*I*ArcTan[Sinh[x]] - I/(2*(I - Sinh[x]))}
{Sech[x]^2/(I + Csch[x]), x, 6, Cosh[x]/(6*(I - Sinh[x])^2) - Cosh[x]/(4*(1 - I*Sinh[x])) + Cosh[x]/(12*(1 + I*Sinh[x]))}
{Sech[x]^3/(I + Csch[x]), x, 6, (-(1/8))*I*ArcTan[Sinh[x]] + 1/(8*(I - Sinh[x])^2) - I/(8*(I + Sinh[x]))}
{Sech[x]^4/(I + Csch[x]), x, 9, (I*Cosh[x])/(20*(I - Sinh[x])^3) + Cosh[x]/(30*(I - Sinh[x])^2) - (5*Cosh[x])/(48*(1 - I*Sinh[x])) + (7*Cosh[x])/(240*(1 + I*Sinh[x])) + Cosh[x]/(24*(I + Sinh[x])^2)}


(* Integrands of the form Csch[x]^m/(a+b*Csch[x]) where m is a positive integer *)
{Csch[x]/(a + b*Csch[x]), x, 2, -((2*ArcTanh[(a - b*Tanh[x/2])/Sqrt[a^2 + b^2]])/Sqrt[a^2 + b^2])}
{Csch[x]^2/(a + b*Csch[x]), x, 6, -(ArcCoth[Cosh[x]]/b) + (2*a*ArcTanh[(a - b*Tanh[x/2])/Sqrt[a^2 + b^2]])/(b*Sqrt[a^2 + b^2])}
{Csch[x]^3/(a + b*Csch[x]), x, 7, (a*ArcCoth[Cosh[x]])/b^2 - (2*a^2*ArcTanh[(a - b*Tanh[x/2])/Sqrt[a^2 + b^2]])/(b^2*Sqrt[a^2 + b^2]) - Coth[x]/b}
{Csch[x]^4/(a + b*Csch[x]), x, 9, -((a^2*ArcCoth[Cosh[x]])/b^3) + ArcCoth[Cosh[x]]/(2*b) + (2*a^3*ArcTanh[(a - b*Tanh[x/2])/Sqrt[a^2 + b^2]])/(b^3*Sqrt[a^2 + b^2]) + (a*Coth[x])/b^2 - (Coth[x]*Csch[x])/(2*b)}

{Csch[x]/(I + Csch[x]), x, 2, -(Cosh[x]/(I - Sinh[x]))}
{Csch[x]^2/(I + Csch[x]), x, 6, -ArcCoth[Cosh[x]] + (I*Cosh[x])/(I - Sinh[x])}
{Csch[x]^3/(I + Csch[x]), x, 7, I*ArcCoth[Cosh[x]] - Coth[x] + Cosh[x]/(I - Sinh[x])}
{Csch[x]^4/(I + Csch[x]), x, 9, (3/2)*ArcCoth[Cosh[x]] + I*Coth[x] - (1/2)*Coth[x]*Csch[x] - (I*Cosh[x])/(I - Sinh[x])}


(* ::Subsection::Closed:: *)
(*Integrands of the form Hyper[x]^m / (a+b Hyper[x])^2*)


(* ::Subsubsection::Closed:: *)
(*Integrands of the form Hyper[x]^m / (a+b Sinh[x])^2*)


(* Integrands of the form Sinh[x]^m/(a+b*Sinh[x])^2 where m is a positive integer *)
{Sinh[x]/(a + b*Sinh[x])^2, x, 2, -((2*b*ArcTanh[(b - a*Tanh[x/2])/Sqrt[a^2 + b^2]])/(a^2 + b^2)^(3/2)) + (a*Cosh[x])/((a^2 + b^2)*(a + b*Sinh[x]))}
{Sinh[x]^2/(a + b*Sinh[x])^2, x, 5, x/b^2 - (2*a^3*ArcTanh[(b - a*Tanh[x/2])/Sqrt[a^2 + b^2]])/(b^2*(a^2 + b^2)^(3/2)) + (4*a*ArcTanh[(b - a*Tanh[x/2])/Sqrt[a^2 + b^2]])/(b^2*Sqrt[a^2 + b^2]) - (a^2*Cosh[x])/(b*(a^2 + b^2)*(a + b*Sinh[x]))}
{Sinh[x]^3/(a + b*Sinh[x])^2, x, 6, -((2*a*x)/b^3) + (2*a^4*ArcTanh[(b - a*Tanh[x/2])/Sqrt[a^2 + b^2]])/(b^3*(a^2 + b^2)^(3/2)) - (6*a^2*ArcTanh[(b - a*Tanh[x/2])/Sqrt[a^2 + b^2]])/(b^3*Sqrt[a^2 + b^2]) + Cosh[x]/b^2 + (a^3*Cosh[x])/(b^2*(a^2 + b^2)*(a + b*Sinh[x]))}
{Sinh[x]^4/(a + b*Sinh[x])^2, x, 7, (3*a^2*x)/b^4 - x/(2*b^2) - (2*a^5*ArcTanh[(b - a*Tanh[x/2])/Sqrt[a^2 + b^2]])/(b^4*(a^2 + b^2)^(3/2)) + (8*a^3*ArcTanh[(b - a*Tanh[x/2])/Sqrt[a^2 + b^2]])/(b^4*Sqrt[a^2 + b^2]) - (2*a*Cosh[x])/b^3 + (Cosh[x]*Sinh[x])/(2*b^2) - (a^4*Cosh[x])/(b^3*(a^2 + b^2)*(a + b*Sinh[x]))}

{Sinh[x]/(I + Sinh[x])^2, x, 4, -((2*Cosh[x])/(3*(1 - I*Sinh[x]))) - Cosh[x]/(3*(I + Sinh[x])^2)}
{Sinh[x]^2/(I + Sinh[x])^2, x, 5, x + (5*I*Cosh[x])/(3*(1 - I*Sinh[x])) + (I*Cosh[x])/(3*(I + Sinh[x])^2)}
{Sinh[x]^3/(I + Sinh[x])^2, x, 6, -2*I*x + Cosh[x] + (8*Cosh[x])/(3*(1 - I*Sinh[x])) + Cosh[x]/(3*(I + Sinh[x])^2)}
{Sinh[x]^4/(I + Sinh[x])^2, x, 7, -((7*x)/2) - 2*I*Cosh[x] - (11*I*Cosh[x])/(3*(1 - I*Sinh[x])) + (1/2)*Cosh[x]*Sinh[x] - (I*Cosh[x])/(3*(I + Sinh[x])^2)}


(* Integrands of the form Cosh[x]^m/(a+b*Sinh[x])^2 where m is a positive integer *)
{Cosh[x]/(a + b*Sinh[x])^2, x, 2, -(1/(b*(a + b*Sinh[x])))}
{Cosh[x]^2/(a + b*Sinh[x])^2, x, 5, x/b^2 + (2*a*ArcTanh[(b - a*Tanh[x/2])/Sqrt[a^2 + b^2]])/(b^2*Sqrt[a^2 + b^2]) - Cosh[x]/(b*(a + b*Sinh[x]))}
{Cosh[x]^3/(a + b*Sinh[x])^2, x, 5, -((2*a*Log[a + b*Sinh[x]])/b^3) + Sinh[x]/b^2 - (a^2 + b^2)/(b^3*(a + b*Sinh[x]))}
{Cosh[x]^4/(a + b*Sinh[x])^2, x, 7, (3*a^2*x)/b^4 + (3*x)/(2*b^2) + (6*a*Sqrt[a^2 + b^2]*ArcTanh[(b - a*Tanh[x/2])/Sqrt[a^2 + b^2]])/b^4 - (2*a*Cosh[x])/b^3 + (Cosh[x]*Sinh[x])/(2*b^2) - ((a^2 + b^2)*Cosh[x])/(b^3*(a + b*Sinh[x]))}

{Cosh[x]/(I + Sinh[x])^2, x, 2, -(1/(I + Sinh[x]))}
{Cosh[x]^2/(I + Sinh[x])^2, x, 3, x + (2*I*Cosh[x])/(1 - I*Sinh[x])}
{Cosh[x]^3/(I + Sinh[x])^2, x, 4, -2*I*Log[I + Sinh[x]] + Sinh[x]}
{Cosh[x]^4/(I + Sinh[x])^2, x, 4, -((3*x)/2) - 2*I*Cosh[x] + (1/2)*Cosh[x]*Sinh[x]}


(* Integrands of the form Tanh[x]^m/(a+b*Sinh[x])^2 where m is a positive integer *)
{Tanh[x]/(a + b*Sinh[x])^2, x, 8, (2*a*b*ArcTan[Sinh[x]])/(a^2 + b^2)^2 + ((a^2 - b^2)*Log[Cosh[x]^2])/(2*(a^2 + b^2)^2) - ((a^2 - b^2)*Log[a + b*Sinh[x]])/(a^2 + b^2)^2 + a/((a^2 + b^2)*(a + b*Sinh[x]))}
{Tanh[x]^2/(a + b*Sinh[x])^2, x, 7, -((2*a^3*ArcTanh[(b - a*Tanh[x/2])/Sqrt[a^2 + b^2]])/(a^2 + b^2)^(5/2)) + (4*a*b^2*ArcTanh[(b - a*Tanh[x/2])/Sqrt[a^2 + b^2]])/(a^2 + b^2)^(5/2) - (2*a*b*Sech[x])/(a^2 + b^2)^2 - (a^2*b*Cosh[x])/((a^2 + b^2)^2*(a + b*Sinh[x])) - ((a^2 - b^2)*Tanh[x])/(a^2 + b^2)^2}
{Tanh[x]^3/(a + b*Sinh[x])^2, x, 11, (4*a^3*b*ArcTan[Sinh[x]])/(a^2 + b^2)^3 - (a*b*ArcTan[Sinh[x]])/(a^2 + b^2)^2 + (a^2*(a^2 - 3*b^2)*Log[Cosh[x]^2])/(2*(a^2 + b^2)^3) - (a^2*(a^2 - 3*b^2)*Log[a + b*Sinh[x]])/(a^2 + b^2)^3 + ((a^2 - b^2)*Sech[x]^2)/(2*(a^2 + b^2)^2) + a^3/((a^2 + b^2)^2*(a + b*Sinh[x])) - (a*b*Sech[x]*Tanh[x])/(a^2 + b^2)^2}
(* {Tanh[x]^4/(a + b*Sinh[x])^2, x, 12, -((2*a^5*ArcTanh[(b - a*Tanh[x/2])/Sqrt[a^2 + b^2]])/(a^2 + b^2)^(7/2)) + (8*a^3*b^2*ArcTanh[(b - a*Tanh[x/2])/Sqrt[a^2 + b^2]])/(a^2 + b^2)^(7/2) - (4*a^3*b*Sech[x])/(a^2 + b^2)^3 + (2*a*b*Sech[x]^3)/(3*(a^2 + b^2)^2) - (a^4*b*Cosh[x])/((a^2 + b^2)^3*(a + b*Sinh[x])) + (a^2*Tanh[x])/(a^2 + b^2)^2 - (b^2*Tanh[x])/(a^2 + b^2)^2 - ((2*a^4 - 3*a^2*b^2 - b^4)*Tanh[x])/(a^2 + b^2)^3 - (a^2*Tanh[x]^3)/(3*(a^2 + b^2)^2) + (b^2*Tanh[x]^3)/(3*(a^2 + b^2)^2)} *)

{Tanh[x]/(I + Sinh[x])^2, x, 6, (-(1/4))*I*ArcTan[Sinh[x]] - 1/(4*(I + Sinh[x])^2) - I/(4*(I + Sinh[x]))}
{Tanh[x]^2/(I + Sinh[x])^2, x, 9, (7*I*Cosh[x])/(120*(1 - I*Sinh[x])) + (I*Cosh[x])/(8*(1 + I*Sinh[x])) - Cosh[x]/(10*(I + Sinh[x])^3) - (11*I*Cosh[x])/(60*(I + Sinh[x])^2)}
{Tanh[x]^3/(I + Sinh[x])^2, x, 8, (-(1/8))*I*ArcTan[Sinh[x]] - I/(16*(I - Sinh[x])) + I/(12*(I + Sinh[x])^3) - 1/(4*(I + Sinh[x])^2) - (3*I)/(16*(I + Sinh[x]))}
(* {Tanh[x]^4/(I + Sinh[x])^2, x, 14, (I*Cosh[x])/(48*(I - Sinh[x])^2) + (241*I*Cosh[x])/(1680*(1 - I*Sinh[x])) - (I*Cosh[x])/(48*(1 + I*Sinh[x])) + (I*Cosh[x])/(28*(I + Sinh[x])^4) - (9*Cosh[x])/(70*(I + Sinh[x])^3) - (241*I*Cosh[x])/(1680*(I + Sinh[x])^2) + Tanh[x]/4} *)


(* Integrands of the form Coth[x]^m/(a+b*Sinh[x])^2 where m is a positive integer *)
{Coth[x]/(a + b*Sinh[x])^2, x, 5, Log[Sinh[x]]/a^2 - Log[a + b*Sinh[x]]/a^2 + 1/(a*(a + b*Sinh[x]))}
{Coth[x]^2/(a + b*Sinh[x])^2, x, 7, (2*b*ArcCoth[Cosh[x]])/a^3 - (2*ArcTanh[(b - a*Tanh[x/2])/Sqrt[a^2 + b^2]])/(a*Sqrt[a^2 + b^2]) - (4*b^2*ArcTanh[(b - a*Tanh[x/2])/Sqrt[a^2 + b^2]])/(a^3*Sqrt[a^2 + b^2]) - Coth[x]/a^2 - (b*Cosh[x])/(a^2*(a + b*Sinh[x]))}
{Coth[x]^3/(a + b*Sinh[x])^2, x, 6, (2*b*Csch[x])/a^3 - Csch[x]^2/(2*a^2) + ((a^2 + 3*b^2)*Log[Sinh[x]])/a^4 - ((a^2 + 3*b^2)*Log[a + b*Sinh[x]])/a^4 + (a^2 + b^2)/(a^3*(a + b*Sinh[x]))}
(* {Coth[x]^4/(a + b*Sinh[x])^2, x, 11, (3*b*ArcCoth[Cosh[x]])/a^3 + (4*b^3*ArcCoth[Cosh[x]])/a^5 - (2*Sqrt[a^2 + b^2]*ArcTanh[(b - a*Tanh[x/2])/Sqrt[a^2 + b^2]])/a^3 - (8*b^2*Sqrt[a^2 + b^2]*ArcTanh[(b - a*Tanh[x/2])/Sqrt[a^2 + b^2]])/a^5 - Coth[x]/a^2 - (3*b^2*Coth[x])/a^4 - Coth[x]^3/(3*a^2) + (b*Coth[x]*Csch[x])/a^3 - (b*(a^2 + b^2)*Cosh[x])/(a^4*(a + b*Sinh[x]))} *)

{Coth[x]/(I + Sinh[x])^2, x, 5, -Log[Sinh[x]] + Log[I + Sinh[x]] - I/(I + Sinh[x])}
{Coth[x]^2/(I + Sinh[x])^2, x, 5, 2*I*ArcCoth[Cosh[x]] + Coth[x] - (2*I*Cosh[x])/(1 - I*Sinh[x])}
{Coth[x]^3/(I + Sinh[x])^2, x, 5, 2*I*Csch[x] + Csch[x]^2/2 + 2*Log[Sinh[x]] - 2*Log[I + Sinh[x]]}
(* {Coth[x]^4/(I + Sinh[x])^2, x, 7, (-I)*ArcCoth[Cosh[x]] - 2*Coth[x] + Coth[x]^3/3 + I*Coth[x]*Csch[x]} *)


(* Integrands of the form Sech[x]^m/(a+b*Sinh[x])^2 where m is a positive integer *)
{Sech[x]/(a + b*Sinh[x])^2, x, 8, ((a^2 - b^2)*ArcTan[Sinh[x]])/(a^2 + b^2)^2 - (a*b*Log[Cosh[x]^2])/(a^2 + b^2)^2 + (2*a*b*Log[a + b*Sinh[x]])/(a^2 + b^2)^2 - b/((a^2 + b^2)*(a + b*Sinh[x]))}
{Sech[x]^2/(a + b*Sinh[x])^2, x, 7, -((6*a*b^2*ArcTanh[(b - a*Tanh[x/2])/Sqrt[a^2 + b^2]])/(a^2 + b^2)^(5/2)) + (2*a*b*Sech[x])/(a^2 + b^2)^2 - (b^3*Cosh[x])/((a^2 + b^2)^2*(a + b*Sinh[x])) + ((a^2 - b^2)*Tanh[x])/(a^2 + b^2)^2}
{Sech[x]^3/(a + b*Sinh[x])^2, x, 11, (b^2*(3*a^2 - b^2)*ArcTan[Sinh[x]])/(a^2 + b^2)^3 + ((a^2 - b^2)*ArcTan[Sinh[x]])/(2*(a^2 + b^2)^2) - (2*a*b^3*Log[Cosh[x]^2])/(a^2 + b^2)^3 + (4*a*b^3*Log[a + b*Sinh[x]])/(a^2 + b^2)^3 + (a*b*Sech[x]^2)/(a^2 + b^2)^2 - b^3/((a^2 + b^2)^2*(a + b*Sinh[x])) + ((a^2 - b^2)*Sech[x]*Tanh[x])/(2*(a^2 + b^2)^2)}
(* {Sech[x]^4/(a + b*Sinh[x])^2, x, 12, -((10*a*b^4*ArcTanh[(b - a*Tanh[x/2])/Sqrt[a^2 + b^2]])/(a^2 + b^2)^(7/2)) + (4*a*b^3*Sech[x])/(a^2 + b^2)^3 + (2*a*b*Sech[x]^3)/(3*(a^2 + b^2)^2) - (b^5*Cosh[x])/((a^2 + b^2)^3*(a + b*Sinh[x])) + (b^2*(3*a^2 - b^2)*Tanh[x])/(a^2 + b^2)^3 + (a^2*Tanh[x])/(a^2 + b^2)^2 - (b^2*Tanh[x])/(a^2 + b^2)^2 - (a^2*Tanh[x]^3)/(3*(a^2 + b^2)^2) + (b^2*Tanh[x]^3)/(3*(a^2 + b^2)^2)} *)

{Sech[x]/(I + Sinh[x])^2, x, 7, (-(1/4))*ArcTan[Sinh[x]] - I/(4*(I + Sinh[x])^2) - 1/(4*(I + Sinh[x]))}
{Sech[x]^2/(I + Sinh[x])^2, x, 9, (11*I*Cosh[x])/(40*(1 - I*Sinh[x])) - (I*Cosh[x])/(8*(1 + I*Sinh[x])) + Cosh[x]/(10*(I + Sinh[x])^3) - (3*I*Cosh[x])/(20*(I + Sinh[x])^2)}
{Sech[x]^3/(I + Sinh[x])^2, x, 9, (-(1/4))*ArcTan[Sinh[x]] + 1/(16*(I - Sinh[x])) + 1/(12*(I + Sinh[x])^3) - I/(8*(I + Sinh[x])^2) - 3/(16*(I + Sinh[x]))}
(* {Sech[x]^4/(I + Sinh[x])^2, x, 14, (I*Cosh[x])/(48*(I - Sinh[x])^2) + (37*I*Cosh[x])/(336*(1 - I*Sinh[x])) - (I*Cosh[x])/(48*(1 + I*Sinh[x])) + (I*Cosh[x])/(28*(I + Sinh[x])^4) + Cosh[x]/(14*(I + Sinh[x])^3) - (37*I*Cosh[x])/(336*(I + Sinh[x])^2) - Tanh[x]/4} *)


(* Integrands of the form Csch[x]^m/(a+b*Sinh[x])^2 where m is a positive integer *)
{Csch[x]/(a + b*Sinh[x])^2, x, 6, -(ArcCoth[Cosh[x]]/a^2) + (2*b*ArcTanh[(b - a*Tanh[x/2])/Sqrt[a^2 + b^2]])/(a^2 + b^2)^(3/2) + (2*b*ArcTanh[(b - a*Tanh[x/2])/Sqrt[a^2 + b^2]])/(a^2*Sqrt[a^2 + b^2]) + (b^2*Cosh[x])/(a*(a^2 + b^2)*(a + b*Sinh[x]))}
{Csch[x]^2/(a + b*Sinh[x])^2, x, 7, (2*b*ArcCoth[Cosh[x]])/a^3 - (2*b^2*ArcTanh[(b - a*Tanh[x/2])/Sqrt[a^2 + b^2]])/(a*(a^2 + b^2)^(3/2)) - (4*b^2*ArcTanh[(b - a*Tanh[x/2])/Sqrt[a^2 + b^2]])/(a^3*Sqrt[a^2 + b^2]) - Coth[x]/a^2 - (b^3*Cosh[x])/(a^2*(a^2 + b^2)*(a + b*Sinh[x]))}
{Csch[x]^3/(a + b*Sinh[x])^2, x, 9, ArcCoth[Cosh[x]]/(2*a^2) - (3*b^2*ArcCoth[Cosh[x]])/a^4 + (2*b^3*ArcTanh[(b - a*Tanh[x/2])/Sqrt[a^2 + b^2]])/(a^2*(a^2 + b^2)^(3/2)) + (6*b^3*ArcTanh[(b - a*Tanh[x/2])/Sqrt[a^2 + b^2]])/(a^4*Sqrt[a^2 + b^2]) + (2*b*Coth[x])/a^3 - (Coth[x]*Csch[x])/(2*a^2) + (b^4*Cosh[x])/(a^3*(a^2 + b^2)*(a + b*Sinh[x]))}
(* {Csch[x]^4/(a + b*Sinh[x])^2, x, 11, -((b*ArcCoth[Cosh[x]])/a^3) + (4*b^3*ArcCoth[Cosh[x]])/a^5 - (2*b^4*ArcTanh[(b - a*Tanh[x/2])/Sqrt[a^2 + b^2]])/(a^3*(a^2 + b^2)^(3/2)) - (8*b^4*ArcTanh[(b - a*Tanh[x/2])/Sqrt[a^2 + b^2]])/(a^5*Sqrt[a^2 + b^2]) + Coth[x]/a^2 - (3*b^2*Coth[x])/a^4 - Coth[x]^3/(3*a^2) + (b*Coth[x]*Csch[x])/a^3 - (b^5*Cosh[x])/(a^4*(a^2 + b^2)*(a + b*Sinh[x]))} *)

{Csch[x]/(I + Sinh[x])^2, x, 6, ArcCoth[Cosh[x]] - (4*Cosh[x])/(3*(1 - I*Sinh[x])) + Cosh[x]/(3*(I + Sinh[x])^2)}
{Csch[x]^2/(I + Sinh[x])^2, x, 7, 2*I*ArcCoth[Cosh[x]] + Coth[x] - (7*I*Cosh[x])/(3*(1 - I*Sinh[x])) + (I*Cosh[x])/(3*(I + Sinh[x])^2)}
{Csch[x]^3/(I + Sinh[x])^2, x, 9, (-(7/2))*ArcCoth[Cosh[x]] + 2*I*Coth[x] + (1/2)*Coth[x]*Csch[x] + (10*Cosh[x])/(3*(1 - I*Sinh[x])) - Cosh[x]/(3*(I + Sinh[x])^2)}
(* {Csch[x]^4/(I + Sinh[x])^2, x, 11, -5*I*ArcCoth[Cosh[x]] - 4*Coth[x] + Coth[x]^3/3 + I*Coth[x]*Csch[x] + (13*I*Cosh[x])/(3*(1 - I*Sinh[x])) - (I*Cosh[x])/(3*(I + Sinh[x])^2)} *)


(* ::Subsubsection::Closed:: *)
(*Integrands of the form Hyper[x]^m / (a+b Cosh[x])^2*)


{Sinh[x]^2/(a + b*Cosh[x])^2, x, 5, x/b^2 - (2*a*ArcTanh[((a - b)*Tanh[x/2])/Sqrt[a^2 - b^2]])/(b^2*Sqrt[a^2 - b^2]) - Sinh[x]/(b*(a + b*Cosh[x]))}


(* Integrands of the form Sinh[x]^m/(1+/-Cosh[x])^n *)
{Sinh[x]/(1 + Cosh[x])^2, x, 2, -(1/(1 + Cosh[x]))}
{Sinh[x]/(1 - Cosh[x])^2, x, 2, 1/(1 - Cosh[x])}
{Sinh[x]^2/(1 + Cosh[x])^2, x, 2, x - 2*Tanh[x/2]}
{Sinh[x]^2/(1 - Cosh[x])^2, x, 2, x - 2*Coth[x/2]}
{Sinh[x]^3/(1 + Cosh[x])^2, x, 4, Cosh[x] - 2*Log[1 + Cosh[x]]}
{Sinh[x]^3/(1 - Cosh[x])^2, x, 4, Cosh[x] + 2*Log[1 - Cosh[x]]}


(* ::Subsection::Closed:: *)
(*Integrands of the form Hyper[x]^m / (a+b Hyper[x])^3*)


(* ::Subsubsection::Closed:: *)
(*Integrands of the form Hyper[x]^m / (a+b Sinh[x])^3*)


{Cosh[x]/(1 + I*Sinh[x])^3, x, 2, I/(2*(1 + I*Sinh[x])^2)}
{Cosh[x]/(1 - I*Sinh[x])^3, x, 2, -(I/(2*(1 - I*Sinh[x])^2))}
{Cosh[x]^2/(1 + I*Sinh[x])^3, x, 5, -((2*I*Cosh[x])/(3*(I - Sinh[x])^2)) - (I*Cosh[x])/(3*(1 + I*Sinh[x]))}
{Cosh[x]^2/(1 - I*Sinh[x])^3, x, 5, (I*Cosh[x])/(3*(1 - I*Sinh[x])) + (2*I*Cosh[x])/(3*(I + Sinh[x])^2)}
{Cosh[x]^3/(1 + I*Sinh[x])^3, x, 6, I*Log[-I + Sinh[x]] - 2/(I - Sinh[x])}
{Cosh[x]^3/(1 - I*Sinh[x])^3, x, 6, (-I)*Log[I + Sinh[x]] + 2/(I + Sinh[x])}


(* ::Subsubsection::Closed:: *)
(*Integrands of the form Hyper[x]^m / (a+b Cosh[x])^3*)


{Sinh[x]/(1 + Cosh[x])^3, x, 2, -(1/(2*(1 + Cosh[x])^2))}
{Sinh[x]/(1 - Cosh[x])^3, x, 2, 1/(2*(1 - Cosh[x])^2)}
{Sinh[x]^2/(1 + Cosh[x])^3, x, 5, -((2*Sinh[x])/(3*(1 + Cosh[x])^2)) + Sinh[x]/(3*(1 + Cosh[x]))}
{Sinh[x]^2/(1 - Cosh[x])^3, x, 5, (2*Sinh[x])/(3*(1 - Cosh[x])^2) - Sinh[x]/(3*(1 - Cosh[x]))}
{Sinh[x]^3/(1 + Cosh[x])^3, x, 5, 2/(1 + Cosh[x]) + Log[1 + Cosh[x]]}
{Sinh[x]^3/(1 - Cosh[x])^3, x, 6, -(2/(1 - Cosh[x])) - Log[1 - Cosh[x]]}


(* ::Subsection::Closed:: *)
(*Integrands of the form Hyper[x]^m / (a+b Hyper[x]^2)*)


(* ::Subsubsection::Closed:: *)
(*Integrands of the form Hyper[x]^m / (a+b Sinh[x]^2)*)


(* Integrands of the form Sinh[x]^m/(a+b*Sinh[x]^2) where m is a positive integer *)
{Sinh[x]/(a + b*Sinh[x]^2), x, 2, ArcTan[(Sqrt[b]*Cosh[x])/Sqrt[a - b]]/(Sqrt[a - b]*Sqrt[b])}
{Sinh[x]^2/(a + b*Sinh[x]^2), x, 4, x/b - (Sqrt[a]*ArcTanh[(Sqrt[a]*Coth[x])/Sqrt[a - b]])/(Sqrt[a - b]*b)}
{Sinh[x]^3/(a + b*Sinh[x]^2), x, 4, -((a*ArcTan[(Sqrt[b]*Cosh[x])/Sqrt[a - b]])/(Sqrt[a - b]*b^(3/2))) + Cosh[x]/b}
{Sinh[x]^4/(a + b*Sinh[x]^2), x, 5, -((a*x)/b^2) - x/(2*b) + (a^(3/2)*ArcTanh[(Sqrt[a]*Coth[x])/Sqrt[a - b]])/(Sqrt[a - b]*b^2) + (Cosh[x]*Sinh[x])/(2*b)}
{Sinh[x]^5/(a + b*Sinh[x]^2), x, 6, (a^2*ArcTan[(Sqrt[b]*Cosh[x])/Sqrt[a - b]])/(Sqrt[a - b]*b^(5/2)) - (a*Cosh[x])/b^2 - Cosh[x]/b + Cosh[x]^3/(3*b)}
{Sinh[x]^6/(a + b*Sinh[x]^2), x, 7, (a^2*x)/b^3 + (a*x)/(2*b^2) + (3*x)/(8*b) - (a^(5/2)*ArcTanh[(Sqrt[a]*Coth[x])/Sqrt[a - b]])/(Sqrt[a - b]*b^3) - (a*Cosh[x]*Sinh[x])/(2*b^2) - (3*Cosh[x]*Sinh[x])/(8*b) + (Cosh[x]*Sinh[x]^3)/(4*b)}
{Sinh[x]^7/(a + b*Sinh[x]^2), x, 9, -((a^3*ArcTan[(Sqrt[b]*Cosh[x])/Sqrt[a - b]])/(Sqrt[a - b]*b^(7/2))) + (a^2*Cosh[x])/b^3 + (a*Cosh[x])/b^2 + Cosh[x]/b - (a*Cosh[x]^3)/(3*b^2) - (2*Cosh[x]^3)/(3*b) + Cosh[x]^5/(5*b)}
(* {Sinh[x]^8/(a + b*Sinh[x]^2), x, 9, -((a^3*x)/b^4) - (a^2*x)/(2*b^3) - (3*a*x)/(8*b^2) - (5*x)/(16*b) + (a^(7/2)*ArcTanh[(Sqrt[a - b]*Tanh[x])/Sqrt[a]])/(Sqrt[a - b]*b^4) + (a^2*Cosh[x]*Sinh[x])/(2*b^3) + (3*a*Cosh[x]*Sinh[x])/(8*b^2) + (5*Cosh[x]*Sinh[x])/(16*b) - (a*Cosh[x]*Sinh[x]^3)/(4*b^2) - (5*Cosh[x]*Sinh[x]^3)/(24*b) + (Cosh[x]*Sinh[x]^5)/(6*b)} *)


(* Integrands of the form Cosh[x]^m/(a+b*Sinh[x]^2) where m is a positive integer *)
{Cosh[x]/(a + b*Sinh[x]^2), x, 2, ArcTan[(Sqrt[b]*Sinh[x])/Sqrt[a]]/(Sqrt[a]*Sqrt[b])}
{Cosh[x]^2/(a + b*Sinh[x]^2), x, 4, x/b - (Sqrt[a - b]*ArcTanh[(Sqrt[a]*Coth[x])/Sqrt[a - b]])/(Sqrt[a]*b)}
{Cosh[x]^3/(a + b*Sinh[x]^2), x, 4, -(((a - b)*ArcTan[(Sqrt[b]*Sinh[x])/Sqrt[a]])/(Sqrt[a]*b^(3/2))) + Sinh[x]/b}
{Cosh[x]^4/(a + b*Sinh[x]^2), x, 5, -((a*x)/b^2) + (3*x)/(2*b) + ((a - b)^(3/2)*ArcTanh[(Sqrt[a]*Coth[x])/Sqrt[a - b]])/(Sqrt[a]*b^2) + (Cosh[x]*Sinh[x])/(2*b)}
{Cosh[x]^5/(a + b*Sinh[x]^2), x, 6, ((a - b)^2*ArcTan[(Sqrt[b]*Sinh[x])/Sqrt[a]])/(Sqrt[a]*b^(5/2)) - (a*Sinh[x])/b^2 + (2*Sinh[x])/b + Sinh[x]^3/(3*b)}
{Cosh[x]^6/(a + b*Sinh[x]^2), x, 7, ((a - b)^2*x)/b^3 - (a*x)/(2*b^2) + (7*x)/(8*b) - ((a - b)^(5/2)*ArcTanh[(Sqrt[a]*Coth[x])/Sqrt[a - b]])/(Sqrt[a]*b^3) - (a*Cosh[x]*Sinh[x])/(2*b^2) + (7*Cosh[x]*Sinh[x])/(8*b) + (Cosh[x]^3*Sinh[x])/(4*b)}
{Cosh[x]^7/(a + b*Sinh[x]^2), x, 9, -(((a - b)^3*ArcTan[(Sqrt[b]*Sinh[x])/Sqrt[a]])/(Sqrt[a]*b^(7/2))) + ((a - b)^2*Sinh[x])/b^3 - (a*Sinh[x])/b^2 + (2*Sinh[x])/b - (a*Sinh[x]^3)/(3*b^2) + Sinh[x]^3/b + Sinh[x]^5/(5*b)}
(* {Cosh[x]^8/(a + b*Sinh[x]^2), x, 9, -(((a - b)^3*x)/b^4) + ((a - b)^2*x)/(2*b^3) - (3*a*x)/(8*b^2) + (11*x)/(16*b) + ((a - b)^(7/2)*ArcTanh[(Sqrt[a - b]*Tanh[x])/Sqrt[a]])/(Sqrt[a]*b^4) + ((a - b)^2*Cosh[x]*Sinh[x])/(2*b^3) - (3*a*Cosh[x]*Sinh[x])/(8*b^2) + (11*Cosh[x]*Sinh[x])/(16*b) - (a*Cosh[x]^3*Sinh[x])/(4*b^2) + (11*Cosh[x]^3*Sinh[x])/(24*b) + (Cosh[x]^5*Sinh[x])/(6*b)} *)


(* Integrands of the form Cosh[x]^m/(a+b*Sinh[x]^n) where m and n are integers *)
{Cosh[x]^2/(a + a*Sinh[x]^2), x, 2, x/a}
{Cosh[x]^3/(a + a*Sinh[x]^2), x, 3, Sinh[x]/a}
{Cosh[x]^4/(a + a*Sinh[x]^2), x, 3, x/(2*a) + (Cosh[x]*Sinh[x])/(2*a)}

{Cosh[x]^2/(1 - Sinh[x]^2), x, 4, -x + Sqrt[2]*ArcTanh[Coth[x]/Sqrt[2]]}
{Cosh[x]^3/(1 - Sinh[x]^2), x, 4, 2*ArcTanh[Sinh[x]] - Sinh[x]}
{Cosh[x]^4/(1 - Sinh[x]^2), x, 5, -((5*x)/2) + 2*Sqrt[2]*ArcTanh[Coth[x]/Sqrt[2]] - (1/2)*Cosh[x]*Sinh[x]}


{Coth[x]/(1 - Sinh[x]^2), x, 2, -ArcTanh[1 - 2*Sinh[x]^2]}


(* ::Subsubsection::Closed:: *)
(*Integrands of the form Hyper[x]^m / (a+b Cosh[x]^2)*)


(* Integrands of the form Sinh[x]^m/(a+b*Cosh[x]^2) where m is a positive integer *)
{Sinh[x]/(a + b*Cosh[x]^2), x, 2, ArcTan[(Sqrt[b]*Cosh[x])/Sqrt[a]]/(Sqrt[a]*Sqrt[b])}
{Sinh[x]^2/(a + b*Cosh[x]^2), x, 4, x/b - (Sqrt[a + b]*ArcTanh[(Sqrt[a]*Tanh[x])/Sqrt[a + b]])/(Sqrt[a]*b)}
{Sinh[x]^3/(a + b*Cosh[x]^2), x, 4, -(((a + b)*ArcTan[(Sqrt[b]*Cosh[x])/Sqrt[a]])/(Sqrt[a]*b^(3/2))) + Cosh[x]/b}
{Sinh[x]^4/(a + b*Cosh[x]^2), x, 5, -((a*x)/b^2) - (3*x)/(2*b) + ((a + b)^(3/2)*ArcTanh[(Sqrt[a]*Tanh[x])/Sqrt[a + b]])/(Sqrt[a]*b^2) + (Cosh[x]*Sinh[x])/(2*b)}
{Sinh[x]^5/(a + b*Cosh[x]^2), x, 6, ((a + b)^2*ArcTan[(Sqrt[b]*Cosh[x])/Sqrt[a]])/(Sqrt[a]*b^(5/2)) - (a*Cosh[x])/b^2 - (2*Cosh[x])/b + Cosh[x]^3/(3*b)}
{Sinh[x]^6/(a + b*Cosh[x]^2), x, 7, (a*x)/(2*b^2) + (7*x)/(8*b) + ((a + b)^2*x)/b^3 - ((a + b)^(5/2)*ArcTanh[(Sqrt[a]*Tanh[x])/Sqrt[a + b]])/(Sqrt[a]*b^3) - (a*Cosh[x]*Sinh[x])/(2*b^2) - (7*Cosh[x]*Sinh[x])/(8*b) + (Cosh[x]*Sinh[x]^3)/(4*b)}
{Sinh[x]^7/(a + b*Cosh[x]^2), x, 9, -(((a + b)^3*ArcTan[(Sqrt[b]*Cosh[x])/Sqrt[a]])/(Sqrt[a]*b^(7/2))) + (a*Cosh[x])/b^2 + (2*Cosh[x])/b + ((a + b)^2*Cosh[x])/b^3 - (a*Cosh[x]^3)/(3*b^2) - Cosh[x]^3/b + Cosh[x]^5/(5*b)}
(* {Sinh[x]^8/(a + b*Cosh[x]^2), x, 9, -((3*a*x)/(8*b^2)) - (11*x)/(16*b) - ((a + b)^2*x)/(2*b^3) - ((a + b)^3*x)/b^4 + ((a + b)^(7/2)*ArcTanh[(Sqrt[a]*Tanh[x])/Sqrt[a + b]])/(Sqrt[a]*b^4) + (3*a*Cosh[x]*Sinh[x])/(8*b^2) + (11*Cosh[x]*Sinh[x])/(16*b) + ((a + b)^2*Cosh[x]*Sinh[x])/(2*b^3) - (a*Cosh[x]*Sinh[x]^3)/(4*b^2) - (11*Cosh[x]*Sinh[x]^3)/(24*b) + (Cosh[x]*Sinh[x]^5)/(6*b)} *)


(* Integrands of the form Cosh[x]^m/(a+b*Cosh[x]^2) where m is a positive integer *)
{Cosh[x]/(a + b*Cosh[x]^2), x, 2, ArcTan[(Sqrt[b]*Sinh[x])/Sqrt[a + b]]/(Sqrt[b]*Sqrt[a + b])}
{Cosh[x]^2/(a + b*Cosh[x]^2), x, 4, x/b - (Sqrt[a]*ArcTanh[(Sqrt[a]*Tanh[x])/Sqrt[a + b]])/(b*Sqrt[a + b])}
{Cosh[x]^3/(a + b*Cosh[x]^2), x, 4, -((a*ArcTan[(Sqrt[b]*Sinh[x])/Sqrt[a + b]])/(b^(3/2)*Sqrt[a + b])) + Sinh[x]/b}
{Cosh[x]^4/(a + b*Cosh[x]^2), x, 5, -((a*x)/b^2) + x/(2*b) + (a^(3/2)*ArcTanh[(Sqrt[a]*Tanh[x])/Sqrt[a + b]])/(b^2*Sqrt[a + b]) + (Cosh[x]*Sinh[x])/(2*b)}
{Cosh[x]^5/(a + b*Cosh[x]^2), x, 6, (a^2*ArcTan[(Sqrt[b]*Sinh[x])/Sqrt[a + b]])/(b^(5/2)*Sqrt[a + b]) - (a*Sinh[x])/b^2 + Sinh[x]/b + Sinh[x]^3/(3*b)}
{Cosh[x]^6/(a + b*Cosh[x]^2), x, 7, (a^2*x)/b^3 - (a*x)/(2*b^2) + (3*x)/(8*b) - (a^(5/2)*ArcTanh[(Sqrt[a]*Tanh[x])/Sqrt[a + b]])/(b^3*Sqrt[a + b]) - (a*Cosh[x]*Sinh[x])/(2*b^2) + (3*Cosh[x]*Sinh[x])/(8*b) + (Cosh[x]^3*Sinh[x])/(4*b)}
{Cosh[x]^7/(a + b*Cosh[x]^2), x, 9, -((a^3*ArcTan[(Sqrt[b]*Sinh[x])/Sqrt[a + b]])/(b^(7/2)*Sqrt[a + b])) + (a^2*Sinh[x])/b^3 - (a*Sinh[x])/b^2 + Sinh[x]/b - (a*Sinh[x]^3)/(3*b^2) + (2*Sinh[x]^3)/(3*b) + Sinh[x]^5/(5*b)}
(* {Cosh[x]^8/(a + b*Cosh[x]^2), x, 9, -((a^3*x)/b^4) + (a^2*x)/(2*b^3) - (3*a*x)/(8*b^2) + (5*x)/(16*b) + (a^(7/2)*ArcTanh[(Sqrt[a]*Tanh[x])/Sqrt[a + b]])/(b^4*Sqrt[a + b]) + (a^2*Cosh[x]*Sinh[x])/(2*b^3) - (3*a*Cosh[x]*Sinh[x])/(8*b^2) + (5*Cosh[x]*Sinh[x])/(16*b) - (a*Cosh[x]^3*Sinh[x])/(4*b^2) + (5*Cosh[x]^3*Sinh[x])/(24*b) + (Cosh[x]^5*Sinh[x])/(6*b)} *)


(* Integrands of the form Sinh[x]^m/(a+b*Cosh[x]^2) where a^2==b^2 and m is an integer *)
{Sinh[x]^2/(a - a*Cosh[x]^2), x, 2, -x/a}
{Sinh[x]^3/(a - a*Cosh[x]^2), x, 3, -(Cosh[x]/a)}
{Sinh[x]^4/(a - a*Cosh[x]^2), x, 3, x/(2*a) - (Cosh[x]*Sinh[x])/(2*a)}


{Tanh[x]/(1 + Cosh[x]^2), x, 2, -ArcTanh[1 + 2*Cosh[x]^2]}


(* ::Subsubsection::Closed:: *)
(*Integrands of the form x^m Hyper[x]^2 / (a+b Tanh[x]^2)*)


{Sech[c + d*x]^2/(a + b*Tanh[c + d*x]^2), x, 2, ArcTan[(Sqrt[b]*Tanh[c + d*x])/Sqrt[a]]/(Sqrt[a]*Sqrt[b]*d)}
{x*Sech[c + d*x]^2/(a + b*Tanh[c + d*x]^2), x, 10, (x*Log[1 + ((a + b)*E^(2*c + 2*d*x))/(a - 2*Sqrt[-a]*Sqrt[b] - b)])/(2*Sqrt[-a]*Sqrt[b]*d) - (x*Log[1 + ((a + b)*E^(2*c + 2*d*x))/(a + 2*Sqrt[-a]*Sqrt[b] - b)])/(2*Sqrt[-a]*Sqrt[b]*d) + PolyLog[2, -(((a + b)*E^(2*c + 2*d*x))/(a - 2*Sqrt[-a]*Sqrt[b] - b))]/(4*Sqrt[-a]*Sqrt[b]*d^2) - PolyLog[2, -(((a + b)*E^(2*c + 2*d*x))/(a + 2*Sqrt[-a]*Sqrt[b] - b))]/(4*Sqrt[-a]*Sqrt[b]*d^2)}
{x^2*Sech[c + d*x]^2/(a + b*Tanh[c + d*x]^2), x, 12, (x^2*Log[1 + ((a + b)*E^(2*c + 2*d*x))/(a - 2*Sqrt[-a]*Sqrt[b] - b)])/(2*Sqrt[-a]*Sqrt[b]*d) - (x^2*Log[1 + ((a + b)*E^(2*c + 2*d*x))/(a + 2*Sqrt[-a]*Sqrt[b] - b)])/(2*Sqrt[-a]*Sqrt[b]*d) + (x*PolyLog[2, -(((a + b)*E^(2*c + 2*d*x))/(a - 2*Sqrt[-a]*Sqrt[b] - b))])/(2*Sqrt[-a]*Sqrt[b]*d^2) - (x*PolyLog[2, -(((a + b)*E^(2*c + 2*d*x))/(a + 2*Sqrt[-a]*Sqrt[b] - b))])/(2*Sqrt[-a]*Sqrt[b]*d^2) - PolyLog[3, -(((a + b)*E^(2*c + 2*d*x))/(a - 2*Sqrt[-a]*Sqrt[b] - b))]/(4*Sqrt[-a]*Sqrt[b]*d^3) + PolyLog[3, -(((a + b)*E^(2*c + 2*d*x))/(a + 2*Sqrt[-a]*Sqrt[b] - b))]/(4*Sqrt[-a]*Sqrt[b]*d^3)}


(* ::Subsection::Closed:: *)
(*Integrands of the form Hyper[x]^m / (a+b Hyper[x]^n)*)


(* ::Subsubsection::Closed:: *)
(*Integrands of the form Hyper[x]^m / (a+b Sinh[x]^3)*)


{Coth[x]^3/(a + b*Sinh[x]^3), x, 10, (b^(2/3)*ArcTan[(a^(1/3) - 2*b^(1/3)*Sinh[x])/(Sqrt[3]*a^(1/3))])/(Sqrt[3]*a^(5/3)) - Csch[x]^2/(2*a) + Log[Sinh[x]]/a - (b^(2/3)*Log[a^(1/3) + b^(1/3)*Sinh[x]])/(3*a^(5/3)) + (b^(2/3)*Log[a^(2/3) - a^(1/3)*b^(1/3)*Sinh[x] + b^(2/3)*Sinh[x]^2])/(6*a^(5/3)) - Log[a + b*Sinh[x]^3]/(3*a)}


(* ::Subsubsection::Closed:: *)
(*Integrands of the form Hyper[x]^m / (a+b Cosh[x]^3)*)


{Sinh[x]/(4 - 3*Cosh[x]^3), x, 6, ArcTan[(6^(2/3) + 6*Cosh[x])/(3*2^(2/3)*3^(1/6))]/(2*2^(1/3)*3^(5/6)) - Log[6^(2/3) - 3*Cosh[x]]/(6*6^(1/3)) + Log[2*6^(1/3) + 6^(2/3)*Cosh[x] + 3*Cosh[x]^2]/(12*6^(1/3))}


{Tanh[x]^3/(a + b*Cosh[x]^3), x, 10, -((b^(2/3)*ArcTan[(a^(1/3) - 2*b^(1/3)*Cosh[x])/(Sqrt[3]*a^(1/3))])/(Sqrt[3]*a^(5/3))) + Log[Cosh[x]]/a + (b^(2/3)*Log[a^(1/3) + b^(1/3)*Cosh[x]])/(3*a^(5/3)) - (b^(2/3)*Log[a^(2/3) - a^(1/3)*b^(1/3)*Cosh[x] + b^(2/3)*Cosh[x]^2])/(6*a^(5/3)) - Log[a + b*Cosh[x]^3]/(3*a) + Sech[x]^2/(2*a)}


(* ::Subsection::Closed:: *)
(*Integrands of the form Hyper[x]^m (a+b Hyper[x])^n*)


(* ::Subsubsection::Closed:: *)
(*Integrands of the form Hyper[x]^m (a+b Sinh[x])^n*)


{Sinh[x]/Sqrt[a + a*I*Sinh[x]], x, 3, -((2*ArcTanh[Sin[Pi/4 - (I*x)/2]]*Cos[Pi/4 - (I*x)/2])/Sqrt[a + I*a*Sinh[x]]) + (2*Cosh[x])/Sqrt[a + I*a*Sinh[x]]}
{Sinh[x]/Sqrt[a - a*I*Sinh[x]], x, 3, (2*Cosh[x])/Sqrt[a - I*a*Sinh[x]] - (2*ArcTanh[Cos[Pi/4 - (I*x)/2]]*Sin[Pi/4 - (I*x)/2])/Sqrt[a - I*a*Sinh[x]]}
{Sinh[x]/Sqrt[a + b*Sinh[x]], x, 5, (2*I*EllipticE[Pi/4 - (I*x)/2, -((2*I*b)/(a - I*b))]*Sqrt[a + b*Sinh[x]])/(b*Sqrt[(a + b*Sinh[x])/(a - I*b)]) - (2*I*a*EllipticF[Pi/4 - (I*x)/2, -((2*I*b)/(a - I*b))]*Sqrt[(a + b*Sinh[x])/(a - I*b)])/(b*Sqrt[a + b*Sinh[x]])}


(* ::Subsubsection::Closed:: *)
(*Integrands of the form Hyper[x]^m (a+b Cosh[x])^n*)


{Cosh[x]/Sqrt[a + a*Cosh[x]], x, 3, -((2*ArcTan[Sinh[x/2]]*Cosh[x/2])/Sqrt[a + a*Cosh[x]]) + (2*Sinh[x])/Sqrt[a + a*Cosh[x]]}
{Cosh[x]/Sqrt[a - a*Cosh[x]], x, 3, -((2*ArcTanh[Cosh[x/2]]*Sinh[x/2])/Sqrt[a - a*Cosh[x]]) + (2*Sinh[x])/Sqrt[a - a*Cosh[x]]}
{Cosh[x]/Sqrt[a + b*Cosh[x]], x, 5, -((2*I*Sqrt[a + b*Cosh[x]]*EllipticE[(I*x)/2, (2*b)/(a + b)])/(b*Sqrt[(a + b*Cosh[x])/(a + b)])) + (2*I*a*Sqrt[(a + b*Cosh[x])/(a + b)]*EllipticF[(I*x)/2, (2*b)/(a + b)])/(b*Sqrt[a + b*Cosh[x]])}


(* ::Subsubsection::Closed:: *)
(*Integrands of the form Hyper[x]^m (a+b Tanh[x])^n*)


(* Integrands of the form Tanh[x]^m*(1+Tanh[x])^n where m is an integer and n is a half-integer *)
{Tanh[x]*(1 + Tanh[x])^(3/2), x, 3, 2*Sqrt[2]*ArcTanh[Sqrt[1 + Tanh[x]]/Sqrt[2]] - 2*Sqrt[1 + Tanh[x]] - (2/3)*(1 + Tanh[x])^(3/2)}
{Tanh[x]*Sqrt[1 + Tanh[x]], x, 2, Sqrt[2]*ArcTanh[Sqrt[1 + Tanh[x]]/Sqrt[2]] - 2*Sqrt[1 + Tanh[x]]}
{Tanh[x]/Sqrt[1 + Tanh[x]], x, 6, ArcTanh[Sqrt[1 + Tanh[x]]/Sqrt[2]]/Sqrt[2] + 1/Sqrt[1 + Tanh[x]]}
{Tanh[x]/(1 + Tanh[x])^(3/2), x, 6, ArcTanh[Sqrt[1 + Tanh[x]]/Sqrt[2]]/(2*Sqrt[2]) + 1/(3*(1 + Tanh[x])^(3/2)) - 1/(2*Sqrt[1 + Tanh[x]])}

{Tanh[x]^2*(1 + Tanh[x])^(3/2), x, 6, 2*Sqrt[2]*ArcTanh[Sqrt[1 + Tanh[x]]/Sqrt[2]] - 2*Sqrt[1 + Tanh[x]] - (2/5)*(1 + Tanh[x])^(5/2)}
{Tanh[x]^2*Sqrt[1 + Tanh[x]], x, 7, Sqrt[2]*ArcTanh[Sqrt[1 + Tanh[x]]/Sqrt[2]] - (2/3)*(1 + Tanh[x])^(3/2)}
{Tanh[x]^2/Sqrt[1 + Tanh[x]], x, 6, ArcTanh[Sqrt[1 + Tanh[x]]/Sqrt[2]]/Sqrt[2] - 1/Sqrt[1 + Tanh[x]] - 2*Sqrt[1 + Tanh[x]]}
{Tanh[x]^2/(1 + Tanh[x])^(3/2), x, 6, ArcTanh[Sqrt[1 + Tanh[x]]/Sqrt[2]]/(2*Sqrt[2]) - 1/(3*(1 + Tanh[x])^(3/2)) + 3/(2*Sqrt[1 + Tanh[x]])}


(* ::Subsubsection::Closed:: *)
(*Integrands of the form Hyper[x]^m (a+b Coth[x])^n*)


(* Integrands of the form Coth[x]^m*(1+Coth[x])^n where m is an integer and n is a half-integer *)
{Coth[x]*(1 + Coth[x])^(3/2), x, 3, 2*Sqrt[2]*ArcCoth[Sqrt[1 + Coth[x]]/Sqrt[2]] - 2*Sqrt[1 + Coth[x]] - (2/3)*(1 + Coth[x])^(3/2)}
{Coth[x]*Sqrt[1 + Coth[x]], x, 2, Sqrt[2]*ArcCoth[Sqrt[1 + Coth[x]]/Sqrt[2]] - 2*Sqrt[1 + Coth[x]]}
{Coth[x]/Sqrt[1 + Coth[x]], x, 6, ArcTanh[Sqrt[1 + Coth[x]]/Sqrt[2]]/Sqrt[2] + 1/Sqrt[1 + Coth[x]]}
{Coth[x]/(1 + Coth[x])^(3/2), x, 6, ArcTanh[Sqrt[1 + Coth[x]]/Sqrt[2]]/(2*Sqrt[2]) + 1/(3*(1 + Coth[x])^(3/2)) - 1/(2*Sqrt[1 + Coth[x]])}

{Coth[x]^2*(1 + Coth[x])^(3/2), x, 6, 2*Sqrt[2]*ArcTanh[Sqrt[1 + Coth[x]]/Sqrt[2]] - 2*Sqrt[1 + Coth[x]] - (2/5)*(1 + Coth[x])^(5/2)}
{Coth[x]^2*Sqrt[1 + Coth[x]], x, 7, Sqrt[2]*ArcTanh[Sqrt[1 + Coth[x]]/Sqrt[2]] - (2/3)*(1 + Coth[x])^(3/2)}
{Coth[x]^2/Sqrt[1 + Coth[x]], x, 6, ArcTanh[Sqrt[1 + Coth[x]]/Sqrt[2]]/Sqrt[2] - 1/Sqrt[1 + Coth[x]] - 2*Sqrt[1 + Coth[x]]}
{Coth[x]^2/(1 + Coth[x])^(3/2), x, 6, ArcTanh[Sqrt[1 + Coth[x]]/Sqrt[2]]/(2*Sqrt[2]) - 1/(3*(1 + Coth[x])^(3/2)) + 3/(2*Sqrt[1 + Coth[x]])}


{Sqrt[1 + Coth[x]]*Sech[x]^2, x, 4, ArcTanh[Sqrt[1 + Coth[x]]] + Sqrt[1 + Coth[x]]*Tanh[x]}


(* ::Subsection::Closed:: *)
(*Integrands of the form Hyper[x]^m (a+b Hyper[x]^2)^n*)


(* ::Subsubsection::Closed:: *)
(*Integrands of the form Hyper[x]^m (a+b Sinh[x]^2)^n*)


{Cosh[x]^1/(a + b*Sinh[x]^2)^2, x, 3, ArcTan[(Sqrt[b]*Sinh[x])/Sqrt[a]]/(2*a^(3/2)*Sqrt[b]) + Sinh[x]/(2*a*(a + b*Sinh[x]^2))}
{Cosh[x]^2/(a + b*Sinh[x]^2)^2, x, 7, ArcTanh[(Sqrt[a - b]*Tanh[x])/Sqrt[a]]/(2*a^(3/2)*Sqrt[a - b]) + (Cosh[x]*Sinh[x])/(2*a*(a + b*Sinh[x]^2)), ArcTanh[(Sqrt[a]*Coth[x])/Sqrt[a - b]]/(Sqrt[a]*Sqrt[a - b]*b) - ((2*a - b)*ArcTanh[(Sqrt[a - b]*Tanh[x])/Sqrt[a]])/(2*a^(3/2)*Sqrt[a - b]*b) + Sinh[2*x]/(2*a*(2*a - b + b*Cosh[2*x]))}
{Cosh[x]^3/(a + b*Sinh[x]^2)^2, x, 5, ((a + b)*ArcTan[(Sqrt[b]*Sinh[x])/Sqrt[a]])/(2*a^(3/2)*b^(3/2)) - ((a - b)*Sinh[x])/(2*a*b*(a + b*Sinh[x]^2)), ((a + b)*ArcTan[(Sqrt[b]*Sinh[x])/Sqrt[a]])/(2*a^(3/2)*b^(3/2)) + Sinh[x]/(2*a*(a + b*Sinh[x]^2)) - Sinh[x]/(2*b*(a + b*Sinh[x]^2))}
{Cosh[x]^4/(a + b*Sinh[x]^2)^2, x, 7, x/b^2 + ((-2*a^2 + a*b + b^2)*ArcTanh[((2*a - 2*b)*Tanh[x])/(2*Sqrt[a]*Sqrt[a - b])])/(2*a^(3/2)*Sqrt[a - b]*b^2) - ((a - b)*Cosh[x]*Sinh[x])/(2*a*b*(a + b*Sinh[x]^2)), x/b^2 - (2*Sqrt[a - b]*ArcTanh[(Sqrt[a]*Coth[x])/Sqrt[a - b]])/(Sqrt[a]*b^2) + (Sqrt[a - b]*(2*a - b)*ArcTanh[(Sqrt[a - b]*Tanh[x])/Sqrt[a]])/(2*a^(3/2)*b^2) - ((a - b)*Sinh[2*x])/(2*a*b*(2*a - b + b*Cosh[2*x]))}


{Coth[x]/Sqrt[a + b*Sinh[x]^2], x, 2, -(ArcTanh[Sqrt[a + b*Sinh[x]^2]/Sqrt[a]]/Sqrt[a])}
{Coth[x]/Sqrt[1 + Sinh[x]^2], x, 2, -ArcTanh[Sqrt[Cosh[x]^2]]}
{Coth[x]/Sqrt[1 - Sinh[x]^2], x, 2, -ArcTanh[Sqrt[1 - Sinh[x]^2]]}


(* ::Subsubsection::Closed:: *)
(*Integrands of the form Hyper[x]^m (a+b Cosh[x]^2)^n*)


{Tanh[x]/Sqrt[a + b*Cosh[x]^2], x, 2, -(ArcTanh[Sqrt[a + b*Cosh[x]^2]/Sqrt[a]]/Sqrt[a])}
{Tanh[x]/Sqrt[1 + Cosh[x]^2], x, 2, -ArcTanh[Sqrt[1 + Cosh[x]^2]]}
{Tanh[x]/Sqrt[1 - Cosh[x]^2], x, 2, -ArcTanh[Sqrt[-Sinh[x]^2]]}


(* ::Subsubsection::Closed:: *)
(*Integrands of the form Hyper[x]^m (a+b Tanh[x]^2)^n*)


(* Integrands of the form Tanh[x]^m/Sqrt[a+b*Tanh[x]^2] where m is an integer *)
{Tanh[x]^3/Sqrt[a + b*Tanh[x]^2], x, 6, ArcTanh[Sqrt[a + b*Tanh[x]^2]/Sqrt[a + b]]/Sqrt[a + b] - Sqrt[a + b*Tanh[x]^2]/b}
{Tanh[x]^2/Sqrt[a + b*Tanh[x]^2], x, 5, -(ArcTanh[(Sqrt[b]*Tanh[x])/Sqrt[a + b*Tanh[x]^2]]/Sqrt[b]) + ArcTanh[(Sqrt[a + b]*Tanh[x])/Sqrt[a + b*Tanh[x]^2]]/Sqrt[a + b]}
{Tanh[x]/Sqrt[a + b*Tanh[x]^2], x, 3, ArcTanh[Sqrt[a + b*Tanh[x]^2]/Sqrt[a + b]]/Sqrt[a + b]}
{Coth[x]/Sqrt[a + b*Tanh[x]^2], x, 7, -(ArcTanh[Sqrt[a + b*Tanh[x]^2]/Sqrt[a]]/Sqrt[a]) + ArcTanh[Sqrt[a + b*Tanh[x]^2]/Sqrt[a + b]]/Sqrt[a + b]}
{Coth[x]^2/Sqrt[a + b*Tanh[x]^2], x, 5, ArcTanh[(Sqrt[a + b]*Tanh[x])/Sqrt[a + b*Tanh[x]^2]]/Sqrt[a + b] - (Coth[x]*Sqrt[a + b*Tanh[x]^2])/a}


(* Integrands of the form Tanh[x]^m*Sqrt[a+b*Tanh[x]^2] where m is an integer *)
{Tanh[x]^3*Sqrt[a + b*Tanh[x]^2], x, 7, Sqrt[a + b]*ArcTanh[Sqrt[a + b*Tanh[x]^2]/Sqrt[a + b]] - Sqrt[a + b*Tanh[x]^2] - (a + b*Tanh[x]^2)^(3/2)/(3*b)}
{Tanh[x]^2*Sqrt[a + b*Tanh[x]^2], x, 14, (-Sqrt[a + b])*ArcTanh[(Sqrt[b] - Sqrt[b]*Tanh[x] - Sqrt[a + b*Tanh[x]^2])/Sqrt[a + b]] - Sqrt[a + b]*ArcTanh[(Sqrt[b] + Sqrt[b]*Tanh[x] + Sqrt[a + b*Tanh[x]^2])/Sqrt[a + b]] - ((a + 2*b)*Log[Sqrt[b]*Tanh[x] + Sqrt[a + b*Tanh[x]^2]])/(2*Sqrt[b]) + a^2/(8*Sqrt[b]*(Sqrt[b]*Tanh[x] + Sqrt[a + b*Tanh[x]^2])^2) - (Sqrt[b]*Tanh[x] + Sqrt[a + b*Tanh[x]^2])^2/(8*Sqrt[b])}
{Tanh[x]*Sqrt[a + b*Tanh[x]^2], x, 4, Sqrt[a + b]*ArcTanh[Sqrt[a + b*Tanh[x]^2]/Sqrt[a + b]] - Sqrt[a + b*Tanh[x]^2]}
{Coth[x]*Sqrt[a + b*Tanh[x]^2], x, 7, (-Sqrt[a])*ArcTanh[Sqrt[a + b*Tanh[x]^2]/Sqrt[a]] + Sqrt[a + b]*ArcTanh[Sqrt[a + b*Tanh[x]^2]/Sqrt[a + b]]}
{Coth[x]^2*Sqrt[a + b*Tanh[x]^2], x, 18, (-Sqrt[a + b])*ArcTanh[(Sqrt[b] - Sqrt[b]*Tanh[x] - Sqrt[a + b*Tanh[x]^2])/Sqrt[a + b]] - Sqrt[a + b]*ArcTanh[(Sqrt[b] + Sqrt[b]*Tanh[x] + Sqrt[a + b*Tanh[x]^2])/Sqrt[a + b]] + (2*a*Sqrt[b])/(a - (Sqrt[b]*Tanh[x] + Sqrt[a + b*Tanh[x]^2])^2)}


(* Integrands of the form Tanh[x]^m*(a+b*Tanh[x]^2)^(3/2) where m is an integer *)
{Tanh[x]^3*(a + b*Tanh[x]^2)^(3/2), x, 8, (a + b)^(3/2)*ArcTanh[Sqrt[a + b*Tanh[x]^2]/Sqrt[a + b]] - (a + b)*Sqrt[a + b*Tanh[x]^2] - (1/3)*(a + b*Tanh[x]^2)^(3/2) - (a + b*Tanh[x]^2)^(5/2)/(5*b)}
{Tanh[x]^2*(a + b*Tanh[x]^2)^(3/2), x, 13, -((3*a^2*ArcTanh[(Sqrt[b]*Tanh[x])/Sqrt[a + b*Tanh[x]^2]])/(8*Sqrt[b])) - (3/2)*a*Sqrt[b]*ArcTanh[(Sqrt[b]*Tanh[x])/Sqrt[a + b*Tanh[x]^2]] - b^(3/2)*ArcTanh[(Sqrt[b]*Tanh[x])/Sqrt[a + b*Tanh[x]^2]] + (a + b)^(3/2)*ArcTanh[(Sqrt[a + b]*Tanh[x])/Sqrt[a + b*Tanh[x]^2]] - (3/8)*a*Tanh[x]*Sqrt[a + b*Tanh[x]^2] - (1/2)*b*Tanh[x]*Sqrt[a + b*Tanh[x]^2] - (1/4)*Tanh[x]*(a + b*Tanh[x]^2)^(3/2)}
{Tanh[x]*(a + b*Tanh[x]^2)^(3/2), x, 6, (a + b)^(3/2)*ArcTanh[Sqrt[a + b*Tanh[x]^2]/Sqrt[a + b]] - (a + b)*Sqrt[a + b*Tanh[x]^2] - (1/3)*(a + b*Tanh[x]^2)^(3/2)}
{Coth[x]*(a + b*Tanh[x]^2)^(3/2), x, 8, (-a^(3/2))*ArcTanh[Sqrt[a + b*Tanh[x]^2]/Sqrt[a]] + (a + b)^(3/2)*ArcTanh[Sqrt[a + b*Tanh[x]^2]/Sqrt[a + b]] - b*Sqrt[a + b*Tanh[x]^2]}
{Coth[x]^2*(a + b*Tanh[x]^2)^(3/2), x, 13, (-b^(3/2))*ArcTanh[(Sqrt[b]*Tanh[x])/Sqrt[a + b*Tanh[x]^2]] + (a + b)^(3/2)*ArcTanh[(Sqrt[a + b]*Tanh[x])/Sqrt[a + b*Tanh[x]^2]] + b*Tanh[x]*Sqrt[a + b*Tanh[x]^2] - Coth[x]*(a + b*Tanh[x]^2)^(3/2)}


(* Integrands of the form Tanh[x]^m/(a+b*Tanh[x]^2)^(3/2) where m is an integer *)
{Tanh[x]^3/(a + b*Tanh[x]^2)^(3/2), x, 7, ArcTanh[Sqrt[a + b*Tanh[x]^2]/Sqrt[a + b]]/(a + b)^(3/2) + a/(b*(a + b)*Sqrt[a + b*Tanh[x]^2])}
{Tanh[x]^2/(a + b*Tanh[x]^2)^(3/2), x, 7, ArcTanh[(Sqrt[a + b]*Tanh[x])/Sqrt[a + b*Tanh[x]^2]]/(a + b)^(3/2) - Tanh[x]/((a + b)*Sqrt[a + b*Tanh[x]^2])}
{Tanh[x]/(a + b*Tanh[x]^2)^(3/2), x, 4, ArcTanh[Sqrt[a + b*Tanh[x]^2]/Sqrt[a + b]]/(a + b)^(3/2) - 1/((a + b)*Sqrt[a + b*Tanh[x]^2])}
{Coth[x]/(a + b*Tanh[x]^2)^(3/2), x, 8, -(ArcTanh[Sqrt[a + b*Tanh[x]^2]/Sqrt[a]]/a^(3/2)) + ArcTanh[Sqrt[a + b*Tanh[x]^2]/Sqrt[a + b]]/(a + b)^(3/2) + b/(a*(a + b)*Sqrt[a + b*Tanh[x]^2])}
{Coth[x]^2/(a + b*Tanh[x]^2)^(3/2), x, 8, ArcTanh[(Sqrt[a + b]*Tanh[x])/Sqrt[a + b*Tanh[x]^2]]/(a + b)^(3/2) + Coth[x]/(a*Sqrt[a + b*Tanh[x]^2]) + (b*Tanh[x])/(a*(a + b)*Sqrt[a + b*Tanh[x]^2]) - (2*Coth[x]*Sqrt[a + b*Tanh[x]^2])/a^2}


(* Integrands of the form Tanh[x]^m/(a+b*Tanh[x]^2)^(5/2) where m is an integer *)
{Tanh[x]^3/(a + b*Tanh[x]^2)^(5/2), x, 7, ArcTanh[Sqrt[a + b*Tanh[x]^2]/Sqrt[a + b]]/(a + b)^(5/2) + a/(3*b*(a + b)*(a + b*Tanh[x]^2)^(3/2)) - 1/((a + b)^2*Sqrt[a + b*Tanh[x]^2])}
{Tanh[x]^2/(a + b*Tanh[x]^2)^(5/2), x, 11, ArcTanh[(Sqrt[a + b]*Tanh[x])/Sqrt[a + b*Tanh[x]^2]]/(a + b)^(5/2) - Tanh[x]/(3*(a + b)*(a + b*Tanh[x]^2)^(3/2)) + (b*Tanh[x])/(a*(a + b)^2*Sqrt[a + b*Tanh[x]^2]) - (2*Tanh[x])/(3*a*(a + b)*Sqrt[a + b*Tanh[x]^2])}
{Tanh[x]/(a + b*Tanh[x]^2)^(5/2), x, 5, ArcTanh[Sqrt[a + b*Tanh[x]^2]/Sqrt[a + b]]/(a + b)^(5/2) - 1/(3*(a + b)*(a + b*Tanh[x]^2)^(3/2)) - 1/((a + b)^2*Sqrt[a + b*Tanh[x]^2])}
{Coth[x]/(a + b*Tanh[x]^2)^(5/2), x, 8, -(ArcTanh[Sqrt[a + b*Tanh[x]^2]/Sqrt[a]]/a^(5/2)) + ArcTanh[Sqrt[a + b*Tanh[x]^2]/Sqrt[a + b]]/(a + b)^(5/2) + b/(3*a*(a + b)*(a + b*Tanh[x]^2)^(3/2)) + (b*(2*a + b))/(a^2*(a + b)^2*Sqrt[a + b*Tanh[x]^2])}
{Coth[x]^2/(a + b*Tanh[x]^2)^(5/2), x, 12, ArcTanh[(Sqrt[a + b]*Tanh[x])/Sqrt[a + b*Tanh[x]^2]]/(a + b)^(5/2) + Coth[x]/(3*a*(a + b*Tanh[x]^2)^(3/2)) + (b*Tanh[x])/(3*a*(a + b)*(a + b*Tanh[x]^2)^(3/2)) + (4*Coth[x])/(3*a^2*Sqrt[a + b*Tanh[x]^2]) + (b*Tanh[x])/(a*(a + b)^2*Sqrt[a + b*Tanh[x]^2]) + (2*b*Tanh[x])/(3*a^2*(a + b)*Sqrt[a + b*Tanh[x]^2]) - (8*Coth[x]*Sqrt[a + b*Tanh[x]^2])/(3*a^3)}


(* ::Subsubsection::Closed:: *)
(*Integrands of the form Hyper[x]^m (a+b Coth[x]^2)^n*)


(* Integrands of the form Coth[x]^m/Sqrt[a+b*Coth[x]^2] where m is an integer *)
{Coth[x]^3/Sqrt[a + b*Coth[x]^2], x, 6, ArcTanh[Sqrt[a + b*Coth[x]^2]/Sqrt[a + b]]/Sqrt[a + b] - Sqrt[a + b*Coth[x]^2]/b}
{Coth[x]^2/Sqrt[a + b*Coth[x]^2], x, 5, -(ArcTanh[(Sqrt[b]*Coth[x])/Sqrt[a + b*Coth[x]^2]]/Sqrt[b]) + ArcTanh[(Sqrt[a + b]*Coth[x])/Sqrt[a + b*Coth[x]^2]]/Sqrt[a + b]}
{Coth[x]/Sqrt[a + b*Coth[x]^2], x, 3, ArcTanh[Sqrt[a + b*Coth[x]^2]/Sqrt[a + b]]/Sqrt[a + b]}
{Tanh[x]/Sqrt[a + b*Coth[x]^2], x, 7, -(ArcTanh[Sqrt[a + b*Coth[x]^2]/Sqrt[a]]/Sqrt[a]) + ArcTanh[Sqrt[a + b*Coth[x]^2]/Sqrt[a + b]]/Sqrt[a + b]}
{Tanh[x]^2/Sqrt[a + b*Coth[x]^2], x, 5, ArcTanh[(Sqrt[a + b]*Coth[x])/Sqrt[a + b*Coth[x]^2]]/Sqrt[a + b] - (Sqrt[a + b*Coth[x]^2]*Tanh[x])/a}


(* Integrands of the form Coth[x]^m*Sqrt[a+b*Coth[x]^2] where m is an integer *)
{Coth[x]^3*Sqrt[a + b*Coth[x]^2], x, 7, Sqrt[a + b]*ArcTanh[Sqrt[a + b*Coth[x]^2]/Sqrt[a + b]] - Sqrt[a + b*Coth[x]^2] - (a + b*Coth[x]^2)^(3/2)/(3*b)}
{Coth[x]^2*Sqrt[a + b*Coth[x]^2], x, 14, (-Sqrt[a + b])*ArcTanh[(Sqrt[b] - Sqrt[b]*Coth[x] - Sqrt[a + b*Coth[x]^2])/Sqrt[a + b]] - Sqrt[a + b]*ArcTanh[(Sqrt[b] + Sqrt[b]*Coth[x] + Sqrt[a + b*Coth[x]^2])/Sqrt[a + b]] + a^2/(8*Sqrt[b]*(Sqrt[b]*Coth[x] + Sqrt[a + b*Coth[x]^2])^2) - (Sqrt[b]*Coth[x] + Sqrt[a + b*Coth[x]^2])^2/(8*Sqrt[b]) - ((a + 2*b)*Log[Sqrt[b]*Coth[x] + Sqrt[a + b*Coth[x]^2]])/(2*Sqrt[b])}
{Coth[x]*Sqrt[a + b*Coth[x]^2], x, 4, Sqrt[a + b]*ArcTanh[Sqrt[a + b*Coth[x]^2]/Sqrt[a + b]] - Sqrt[a + b*Coth[x]^2]}
{Tanh[x]*Sqrt[a + b*Coth[x]^2], x, 7, (-Sqrt[a])*ArcTanh[Sqrt[a + b*Coth[x]^2]/Sqrt[a]] + Sqrt[a + b]*ArcTanh[Sqrt[a + b*Coth[x]^2]/Sqrt[a + b]]}
{Tanh[x]^2*Sqrt[a + b*Coth[x]^2], x, 18, (-Sqrt[a + b])*ArcTanh[(Sqrt[b] - Sqrt[b]*Coth[x] - Sqrt[a + b*Coth[x]^2])/Sqrt[a + b]] - Sqrt[a + b]*ArcTanh[(Sqrt[b] + Sqrt[b]*Coth[x] + Sqrt[a + b*Coth[x]^2])/Sqrt[a + b]] + (2*a*Sqrt[b])/(a - (Sqrt[b]*Coth[x] + Sqrt[a + b*Coth[x]^2])^2)}


(* Integrands of the form Coth[x]^m*(a+b*Coth[x]^2)^(3/2) where m is an integer *)
{Coth[x]^3*(a + b*Coth[x]^2)^(3/2), x, 8, (a + b)^(3/2)*ArcTanh[Sqrt[a + b*Coth[x]^2]/Sqrt[a + b]] - (a + b)*Sqrt[a + b*Coth[x]^2] - (1/3)*(a + b*Coth[x]^2)^(3/2) - (a + b*Coth[x]^2)^(5/2)/(5*b)}
{Coth[x]^2*(a + b*Coth[x]^2)^(3/2), x, 13, -((3*a^2*ArcTanh[(Sqrt[b]*Coth[x])/Sqrt[a + b*Coth[x]^2]])/(8*Sqrt[b])) - (3/2)*a*Sqrt[b]*ArcTanh[(Sqrt[b]*Coth[x])/Sqrt[a + b*Coth[x]^2]] - b^(3/2)*ArcTanh[(Sqrt[b]*Coth[x])/Sqrt[a + b*Coth[x]^2]] + (a + b)^(3/2)*ArcTanh[(Sqrt[a + b]*Coth[x])/Sqrt[a + b*Coth[x]^2]] - (3/8)*a*Coth[x]*Sqrt[a + b*Coth[x]^2] - (1/2)*b*Coth[x]*Sqrt[a + b*Coth[x]^2] - (1/4)*Coth[x]*(a + b*Coth[x]^2)^(3/2)}
{Coth[x]*(a + b*Coth[x]^2)^(3/2), x, 6, (a + b)^(3/2)*ArcTanh[Sqrt[a + b*Coth[x]^2]/Sqrt[a + b]] - (a + b)*Sqrt[a + b*Coth[x]^2] - (1/3)*(a + b*Coth[x]^2)^(3/2)}
{Tanh[x]*(a + b*Coth[x]^2)^(3/2), x, 8, (-a^(3/2))*ArcTanh[Sqrt[a + b*Coth[x]^2]/Sqrt[a]] + (a + b)^(3/2)*ArcTanh[Sqrt[a + b*Coth[x]^2]/Sqrt[a + b]] - b*Sqrt[a + b*Coth[x]^2]}
{Tanh[x]^2*(a + b*Coth[x]^2)^(3/2), x, 13, (-b^(3/2))*ArcTanh[(Sqrt[b]*Coth[x])/Sqrt[a + b*Coth[x]^2]] + (a + b)^(3/2)*ArcTanh[(Sqrt[a + b]*Coth[x])/Sqrt[a + b*Coth[x]^2]] + b*Coth[x]*Sqrt[a + b*Coth[x]^2] - (a + b*Coth[x]^2)^(3/2)*Tanh[x]}


(* Integrands of the form Coth[x]^m/(a+b*Coth[x]^2)^(3/2) where m is an integer *)
{Coth[x]^3/(a + b*Coth[x]^2)^(3/2), x, 7, ArcTanh[Sqrt[a + b*Coth[x]^2]/Sqrt[a + b]]/(a + b)^(3/2) + a/(b*(a + b)*Sqrt[a + b*Coth[x]^2])}
{Coth[x]^2/(a + b*Coth[x]^2)^(3/2), x, 7, ArcTanh[(Sqrt[a + b]*Coth[x])/Sqrt[a + b*Coth[x]^2]]/(a + b)^(3/2) - Coth[x]/((a + b)*Sqrt[a + b*Coth[x]^2])}
{Coth[x]/(a + b*Coth[x]^2)^(3/2), x, 4, ArcTanh[Sqrt[a + b*Coth[x]^2]/Sqrt[a + b]]/(a + b)^(3/2) - 1/((a + b)*Sqrt[a + b*Coth[x]^2])}
{Tanh[x]/(a + b*Coth[x]^2)^(3/2), x, 8, -(ArcTanh[Sqrt[a + b*Coth[x]^2]/Sqrt[a]]/a^(3/2)) + ArcTanh[Sqrt[a + b*Coth[x]^2]/Sqrt[a + b]]/(a + b)^(3/2) + b/(a*(a + b)*Sqrt[a + b*Coth[x]^2])}
{Tanh[x]^2/(a + b*Coth[x]^2)^(3/2), x, 8, ArcTanh[(Sqrt[a + b]*Coth[x])/Sqrt[a + b*Coth[x]^2]]/(a + b)^(3/2) + (b*Coth[x])/(a*(a + b)*Sqrt[a + b*Coth[x]^2]) + Tanh[x]/(a*Sqrt[a + b*Coth[x]^2]) - (2*Sqrt[a + b*Coth[x]^2]*Tanh[x])/a^2}


(* Integrands of the form Coth[x]^m/(a+b*Coth[x]^2)^(5/2) where m is an integer *)
{Coth[x]^3/(a + b*Coth[x]^2)^(5/2), x, 7, ArcTanh[Sqrt[a + b*Coth[x]^2]/Sqrt[a + b]]/(a + b)^(5/2) + a/(3*b*(a + b)*(a + b*Coth[x]^2)^(3/2)) - 1/((a + b)^2*Sqrt[a + b*Coth[x]^2])}
{Coth[x]^2/(a + b*Coth[x]^2)^(5/2), x, 11, ArcTanh[(Sqrt[a + b]*Coth[x])/Sqrt[a + b*Coth[x]^2]]/(a + b)^(5/2) - Coth[x]/(3*(a + b)*(a + b*Coth[x]^2)^(3/2)) + (b*Coth[x])/(a*(a + b)^2*Sqrt[a + b*Coth[x]^2]) - (2*Coth[x])/(3*a*(a + b)*Sqrt[a + b*Coth[x]^2])}
{Coth[x]/(a + b*Coth[x]^2)^(5/2), x, 5, ArcTanh[Sqrt[a + b*Coth[x]^2]/Sqrt[a + b]]/(a + b)^(5/2) - 1/(3*(a + b)*(a + b*Coth[x]^2)^(3/2)) - 1/((a + b)^2*Sqrt[a + b*Coth[x]^2])}
{Tanh[x]/(a + b*Coth[x]^2)^(5/2), x, 8, -(ArcTanh[Sqrt[a + b*Coth[x]^2]/Sqrt[a]]/a^(5/2)) + ArcTanh[Sqrt[a + b*Coth[x]^2]/Sqrt[a + b]]/(a + b)^(5/2) + b/(3*a*(a + b)*(a + b*Coth[x]^2)^(3/2)) + (b*(2*a + b))/(a^2*(a + b)^2*Sqrt[a + b*Coth[x]^2])}
{Tanh[x]^2/(a + b*Coth[x]^2)^(5/2), x, 12, ArcTanh[(Sqrt[a + b]*Coth[x])/Sqrt[a + b*Coth[x]^2]]/(a + b)^(5/2) + (b*Coth[x])/(3*a*(a + b)*(a + b*Coth[x]^2)^(3/2)) + (b*Coth[x])/(a*(a + b)^2*Sqrt[a + b*Coth[x]^2]) + (2*b*Coth[x])/(3*a^2*(a + b)*Sqrt[a + b*Coth[x]^2]) + Tanh[x]/(3*a*(a + b*Coth[x]^2)^(3/2)) + (4*Tanh[x])/(3*a^2*Sqrt[a + b*Coth[x]^2]) - (8*Sqrt[a + b*Coth[x]^2]*Tanh[x])/(3*a^3)}


(* ::Subsection::Closed:: *)
(*Integrands of the form Hyper[x]^m (a+b Hyper[x]^n)^p*)


(* ::Subsubsection::Closed:: *)
(*Integrands of the form Coth[x] (a+b Sinh[x]^n)^p*)


(* Integrands of the form Coth[x]/Sqrt[a+b*Sinh[x]^n] where n is an integer *)
{Coth[x]/Sqrt[a + b*Sinh[x]], x, 2, -((2*ArcTanh[Sqrt[a + b*Sinh[x]]/Sqrt[a]])/Sqrt[a])}
{Coth[x]/Sqrt[a + b*Sinh[x]^2], x, 2, -(ArcTanh[Sqrt[a + b*Sinh[x]^2]/Sqrt[a]]/Sqrt[a])}
{Coth[x]/Sqrt[a + b*Sinh[x]^3], x, 2, -((2*ArcTanh[Sqrt[a + b*Sinh[x]^3]/Sqrt[a]])/(3*Sqrt[a]))}
{Coth[x]/Sqrt[a + b*Sinh[x]^4], x, 2, -((2*ArcTanh[Sqrt[a + b*Sinh[x]^4]/Sqrt[a]])/(4*Sqrt[a]))}
{Coth[x]/Sqrt[a + b*Sinh[x]^n], x, 2, -((2*ArcTanh[Sqrt[a + b*Sinh[x]^n]/Sqrt[a]])/(Sqrt[a]*n))}


(* Integrands of the form Coth[x]*Sqrt[a+b*Sinh[x]^n] where n is an integer *)
{Coth[x]*Sqrt[a + b*Sinh[x]], x, 3, -2*Sqrt[a]*ArcTanh[Sqrt[a + b*Sinh[x]]/Sqrt[a]] + 2*Sqrt[a + b*Sinh[x]]}
{Coth[x]*Sqrt[a + b*Sinh[x]^2], x, 3, (-Sqrt[a])*ArcTanh[Sqrt[a + b*Sinh[x]^2]/Sqrt[a]] + Sqrt[a + b*Sinh[x]^2]}
{Coth[x]*Sqrt[a + b*Sinh[x]^3], x, 3, (-(2/3))*Sqrt[a]*ArcTanh[Sqrt[a + b*Sinh[x]^3]/Sqrt[a]] + (2/3)*Sqrt[a + b*Sinh[x]^3]}
{Coth[x]*Sqrt[a + b*Sinh[x]^4], x, 3, (-(1/2))*Sqrt[a]*ArcTanh[Sqrt[a + b*Sinh[x]^4]/Sqrt[a]] + (1/2)*Sqrt[a + b*Sinh[x]^4]}
{Coth[x]*Sqrt[a + b*Sinh[x]^n], x, 3, -((2*Sqrt[a]*ArcTanh[Sqrt[a + b*Sinh[x]^n]/Sqrt[a]])/n) + (2*Sqrt[a + b*Sinh[x]^n])/n}


(* ::Subsubsection::Closed:: *)
(*Integrands of the form Tanh[x] (a+b Cosh[x]^n)^p*)


(* Integrands of the form Tanh[x]/Sqrt[a+b*Cosh[x]^n] where n is an integer *)
{Tanh[x]/Sqrt[a + b*Cosh[x]], x, 2, -((2*ArcTanh[Sqrt[a + b*Cosh[x]]/Sqrt[a]])/Sqrt[a])}
{Tanh[x]/Sqrt[a + b*Cosh[x]^2], x, 2, -(ArcTanh[Sqrt[a + b*Cosh[x]^2]/Sqrt[a]]/Sqrt[a])}
{Tanh[x]/Sqrt[a + b*Cosh[x]^3], x, 2, -((2*ArcTanh[Sqrt[a + b*Cosh[x]^3]/Sqrt[a]])/(3*Sqrt[a]))}
{Tanh[x]/Sqrt[a + b*Cosh[x]^4], x, 2, -(ArcTanh[Sqrt[a + b*Cosh[x]^4]/Sqrt[a]]/(2*Sqrt[a]))}
{Tanh[x]/Sqrt[a + b*Cosh[x]^n], x, 2, -((2*ArcTanh[Sqrt[a + b*Cosh[x]^n]/Sqrt[a]])/(Sqrt[a]*n))}


(* Integrands of the form Tanh[x]*Sqrt[a+b*Cosh[x]^n] where n is an integer *)
{Tanh[x]*Sqrt[a + b*Cosh[x]], x, 3, -2*Sqrt[a]*ArcTanh[Sqrt[a + b*Cosh[x]]/Sqrt[a]] + 2*Sqrt[a + b*Cosh[x]]}
{Tanh[x]*Sqrt[a + b*Cosh[x]^2], x, 3, (-Sqrt[a])*ArcTanh[Sqrt[a + b*Cosh[x]^2]/Sqrt[a]] + Sqrt[a + b*Cosh[x]^2]}
{Tanh[x]*Sqrt[a + b*Cosh[x]^3], x, 3, (-(2/3))*Sqrt[a]*ArcTanh[Sqrt[a + b*Cosh[x]^3]/Sqrt[a]] + (2/3)*Sqrt[a + b*Cosh[x]^3]}
{Tanh[x]*Sqrt[a + b*Cosh[x]^4], x, 3, (-(1/2))*Sqrt[a]*ArcTanh[Sqrt[a + b*Cosh[x]^4]/Sqrt[a]] + (1/2)*Sqrt[a + b*Cosh[x]^4]}
{Tanh[x]*Sqrt[a + b*Cosh[x]^n], x, 3, -((2*Sqrt[a]*ArcTanh[Sqrt[a + b*Cosh[x]^n]/Sqrt[a]])/n) + (2*Sqrt[a + b*Cosh[x]^n])/n}


(* ::Subsubsection::Closed:: *)
(*Integrands of the form Tanh[x] (a+b Tanh[x]^n)^p*)


(* Integrands of the form Tanh[x]*(a+b*Tanh[x]^4)^m where m is a half-integer *)
{Tanh[x]*Sqrt[a + b*Tanh[x]^4], x, 8, (-Sqrt[a + b])*ArcTanh[(Sqrt[b]*Sech[x]^2 - Sqrt[a + b*Tanh[x]^4])/Sqrt[a + b]] - (1/2)*Sqrt[b]*Log[Sqrt[b]*Tanh[x]^2 + Sqrt[a + b*Tanh[x]^4]] + (1/4)*((-Sqrt[b])*Tanh[x]^2 - Sqrt[a + b*Tanh[x]^4]) - a/(4*(Sqrt[b]*Tanh[x]^2 + Sqrt[a + b*Tanh[x]^4]))}
{Tanh[x]/Sqrt[a + b*Tanh[x]^4], x, 3, ArcTanh[(a + b*Tanh[x]^2)/(Sqrt[a + b]*Sqrt[a + b*Tanh[x]^4])]/(2*Sqrt[a + b])}
{Tanh[x]/(a + b*Tanh[x]^4)^(3/2), x, 11, -(ArcTanh[(Sqrt[b]*Sech[x]^2 - Sqrt[a + b*Tanh[x]^4])/Sqrt[a + b]]/(a + b)^(3/2)) - Sqrt[b]/((a + b)*(a + (Sqrt[b]*Tanh[x]^2 + Sqrt[a + b*Tanh[x]^4])^2)) - (Sqrt[b]*Tanh[x]^2 + Sqrt[a + b*Tanh[x]^4])/((a + b)*(a + (Sqrt[b]*Tanh[x]^2 + Sqrt[a + b*Tanh[x]^4])^2))}


(* ::Subsubsection::Closed:: *)
(*Integrands of the form Coth[x] (a+b Coth[x]^n)^p*)


(* Integrands of the form Coth[x]*(a+b*Coth[x]^4)^m where m is a half-integer *)
{Coth[x]*Sqrt[a + b*Coth[x]^4], x, 8, Sqrt[a + b]*ArcTanh[(Sqrt[a + b*Coth[x]^4] + Sqrt[b]*Csch[x]^2)/Sqrt[a + b]] + (1/4)*((-Sqrt[b])*Coth[x]^2 - Sqrt[a + b*Coth[x]^4]) - a/(4*(Sqrt[b]*Coth[x]^2 + Sqrt[a + b*Coth[x]^4])) - (1/2)*Sqrt[b]*Log[Sqrt[b]*Coth[x]^2 + Sqrt[a + b*Coth[x]^4]]}
{Coth[x]/Sqrt[a + b*Coth[x]^4], x, 3, ArcTanh[(a + b*Coth[x]^2)/(Sqrt[a + b]*Sqrt[a + b*Coth[x]^4])]/(2*Sqrt[a + b])}
{Coth[x]/(a + b*Coth[x]^4)^(3/2), x, 11, ArcTanh[(Sqrt[a + b*Coth[x]^4] + Sqrt[b]*Csch[x]^2)/Sqrt[a + b]]/(a + b)^(3/2) - Sqrt[b]/((a + b)*(a + (Sqrt[b]*Coth[x]^2 + Sqrt[a + b*Coth[x]^4])^2)) - (Sqrt[b]*Coth[x]^2 + Sqrt[a + b*Coth[x]^4])/((a + b)*(a + (Sqrt[b]*Coth[x]^2 + Sqrt[a + b*Coth[x]^4])^2))}


(* ::Subsection::Closed:: *)
(*Integrands of the form x^q Hyper[x]^m (a+b Hyper[x]^n)^p*)
(**)


{x*Cosh[x]/(a + b*Sinh[x])^2, x, 2, -((2*ArcTanh[(b - a*Tanh[x/2])/Sqrt[a^2 + b^2]])/(b*Sqrt[a^2 + b^2])) - x/(b*(a + b*Sinh[x]))}
{x*Cosh[x]/(a + b*Sinh[x])^3, x, 3, -((a*ArcTanh[(b - a*Tanh[x/2])/Sqrt[a^2 + b^2]])/(b*(a^2 + b^2)^(3/2))) - x/(2*b*(a + b*Sinh[x])^2) - Cosh[x]/(2*(a^2 + b^2)*(a + b*Sinh[x]))}


{x*Sinh[x]/(a + b*Cosh[x])^2, x, 2, (2*ArcTanh[((a - b)*Tanh[x/2])/Sqrt[a^2 - b^2]])/(b*Sqrt[a^2 - b^2]) - x/(b*(a + b*Cosh[x]))}
{x*Sinh[x]/(a + b*Cosh[x])^3, x, 3, (a*ArcTanh[((a - b)*Tanh[x/2])/Sqrt[a^2 - b^2]])/(b*(a^2 - b^2)^(3/2)) - x/(2*b*(a + b*Cosh[x])^2) - Sinh[x]/(2*(a^2 - b^2)*(a + b*Cosh[x]))}


{x*Sech[x]^2/(a + b*Tanh[x])^2, x, 2, (a*x)/(b*(a^2 - b^2)) - Log[a*Cosh[x] + b*Sinh[x]]/(a^2 - b^2) - x/(b*(a + b*Tanh[x]))}
{x*Csch[x]^2/(a + b*Coth[x])^2, x, 2, -((a*x)/(b*(a^2 - b^2))) + x/(b*(a + b*Coth[x])) + Log[b*Cosh[x] + a*Sinh[x]]/(a^2 - b^2)}


{(Cosh[a + b*x]*(-2 + Sinh[a + b*x]^2))/x, x, 13, (-(9/4))*Cosh[a]*CoshIntegral[b*x] + (1/4)*Cosh[3*a]*CoshIntegral[3*b*x] - (9/4)*Sinh[a]*SinhIntegral[b*x] + (1/4)*Sinh[3*a]*SinhIntegral[3*b*x]}
{((2 + Cosh[a + b*x]^2)*Sinh[a + b*x])/x, x, 13, (9/4)*CoshIntegral[b*x]*Sinh[a] + (1/4)*CoshIntegral[3*b*x]*Sinh[3*a] + (9/4)*Cosh[a]*SinhIntegral[b*x] + (1/4)*Cosh[3*a]*SinhIntegral[3*b*x]}


(* ::Subsection::Closed:: *)
(*Integrands of the form (A+B Hyper[x]) (a+b Hyper[x])^n*)


(* ::Subsubsection::Closed:: *)
(*Integrands of the form (A+B Hyper[x]) (a+b Sinh[x])^n*)


(* Integrands of the form (A+B*Sinh[x])*(a+b*Sinh[x])^n where n is an integer *)
{(A + B*Sinh[x])/(a + b*Sinh[x]), x, 2, (B*x)/b - (2*(A*b - a*B)*ArcTanh[(b - a*Tanh[x/2])/Sqrt[a^2 + b^2]])/(b*Sqrt[a^2 + b^2])}
{(A + B*Sinh[x])/(a + b*Sinh[x])^2, x, 2, -((2*(a*A + b*B)*ArcTanh[(b - a*Tanh[x/2])/Sqrt[a^2 + b^2]])/(a^2 + b^2)^(3/2)) - ((A*b - a*B)*Cosh[x])/((a^2 + b^2)*(a + b*Sinh[x]))}
{(A + B*Sinh[x])/(a + b*Sinh[x])^3, x, 3, -(((2*a^2*A - b*(A*b - 3*a*B))*ArcTanh[(b - a*Tanh[x/2])/Sqrt[a^2 + b^2]])/(a^2 + b^2)^(5/2)) - ((A*b - a*B)*Cosh[x])/(2*(a^2 + b^2)*(a + b*Sinh[x])^2) - ((2*b^2*B + a*(3*A*b - a*B))*Cosh[x])/(2*(a^2 + b^2)^2*(a + b*Sinh[x]))}
{(A + B*Sinh[x])/(a + b*Sinh[x])^4, x, 4, -(((b*(2*a^2*B - b*(5*a*A + 3*b*B)) - 2*a*(2*A*b^2 - a*(3*a*A + 5*b*B)))*ArcTanh[(b - a*Tanh[x/2])/Sqrt[a^2 + b^2]])/(3*(a^2 + b^2)^(7/2))) - ((A*b - a*B)*Cosh[x])/(3*(a^2 + b^2)*(a + b*Sinh[x])^3) + ((2*a^2*B - b*(5*a*A + 3*b*B))*Cosh[x])/(6*(a^2 + b^2)^2*(a + b*Sinh[x])^2) + ((a*(2*a^2*B - b*(5*a*A + 3*b*B)) + 2*b*(2*A*b^2 - a*(3*a*A + 5*b*B)))*Cosh[x])/(6*(a^2 + b^2)^3*(a + b*Sinh[x]))}

{(A + B*Sinh[x])/(I + Sinh[x]), x, 2, B*x - ((A - I*B)*Cosh[x])/(1 - I*Sinh[x])}
{(A + B*Sinh[x])/(I + Sinh[x])^2, x, 4, (I*A*Cosh[x])/(3*(1 - I*Sinh[x])) - (2*B*Cosh[x])/(3*(1 - I*Sinh[x])) - (I*(A - I*B)*Cosh[x])/(3*(I + Sinh[x])^2)}
{(A + B*Sinh[x])/(I + Sinh[x])^3, x, 6, (2*A*Cosh[x])/(15*(1 - I*Sinh[x])) + (I*B*Cosh[x])/(5*(1 - I*Sinh[x])) - (I*(A - I*B)*Cosh[x])/(5*(I + Sinh[x])^3) - (2*A*Cosh[x])/(15*(I + Sinh[x])^2) - (I*B*Cosh[x])/(5*(I + Sinh[x])^2)}
{(A + B*Sinh[x])/(I + Sinh[x])^4, x, 8, -((2*I*A*Cosh[x])/(35*(1 - I*Sinh[x]))) + (8*B*Cosh[x])/(105*(1 - I*Sinh[x])) - (I*(A - I*B)*Cosh[x])/(7*(I + Sinh[x])^4) - (3*A*Cosh[x])/(35*(I + Sinh[x])^3) - (4*I*B*Cosh[x])/(35*(I + Sinh[x])^3) + (2*I*A*Cosh[x])/(35*(I + Sinh[x])^2) - (8*B*Cosh[x])/(105*(I + Sinh[x])^2)}

{(A + B*Sinh[x])/(I - Sinh[x]), x, 2, (-B)*x + ((A + I*B)*Cosh[x])/(1 + I*Sinh[x])}
{(A + B*Sinh[x])/(I - Sinh[x])^2, x, 4, (I*(A + I*B)*Cosh[x])/(3*(I - Sinh[x])^2) - (I*A*Cosh[x])/(3*(1 + I*Sinh[x])) - (2*B*Cosh[x])/(3*(1 + I*Sinh[x]))}
{(A + B*Sinh[x])/(I - Sinh[x])^3, x, 6, (I*(A + I*B)*Cosh[x])/(5*(I - Sinh[x])^3) + (2*A*Cosh[x])/(15*(I - Sinh[x])^2) - (I*B*Cosh[x])/(5*(I - Sinh[x])^2) - (2*A*Cosh[x])/(15*(1 + I*Sinh[x])) + (I*B*Cosh[x])/(5*(1 + I*Sinh[x]))}
{(A + B*Sinh[x])/(I - Sinh[x])^4, x, 8, (I*(A + I*B)*Cosh[x])/(7*(I - Sinh[x])^4) + (3*A*Cosh[x])/(35*(I - Sinh[x])^3) - (4*I*B*Cosh[x])/(35*(I - Sinh[x])^3) - (2*I*A*Cosh[x])/(35*(I - Sinh[x])^2) - (8*B*Cosh[x])/(105*(I - Sinh[x])^2) + (2*I*A*Cosh[x])/(35*(1 + I*Sinh[x])) + (8*B*Cosh[x])/(105*(1 + I*Sinh[x]))}

{(b*B/a + B*Sinh[x])/(a + b*Sinh[x]), x, 2, (B*x)/b + (2*(a - b^2/a)*B*ArcTanh[(b - a*Tanh[x/2])/Sqrt[a^2 + b^2]])/(b*Sqrt[a^2 + b^2])}
{(a*B/b + B*Sinh[x])/(a + b*Sinh[x]), x, 2, (B*x)/b}

{(a - b*Sinh[x])/(b + a*Sinh[x])^2, x, 1, -(Cosh[x]/(b + a*Sinh[x]))}
{(2 - Sinh[x])/(2 + Sinh[x]), x, 2, -x - (8*ArcTanh[(1 - 2*Tanh[x/2])/Sqrt[5]])/Sqrt[5]}


(* Integrands of the form (A+B*Sinh[x])*(a+b*Sinh[x])^n where n is a half-integer *)
{(A + B*Sinh[x])*(a + b*Sinh[x])^(5/2), x, 8, (2/105)*(15*a^2*B + b*(56*a*A - 25*b*B))*Cosh[x]*Sqrt[a + b*Sinh[x]] + (2/35)*(7*A*b + 5*a*B)*Cosh[x]*(a + b*Sinh[x])^(3/2) + (2/7)*B*Cosh[x]*(a + b*Sinh[x])^(5/2) + (2*I*(a*(15*a^2*B + b*(56*a*A - 25*b*B)) - 3*b*(21*A*b^2 - 5*a*(7*a*A - 8*b*B)))*EllipticE[Pi/4 - (I*x)/2, -((2*I*b)/(a - I*b))]*Sqrt[a + b*Sinh[x]])/(105*b*Sqrt[(a + b*Sinh[x])/(a - I*b)]) - (2*I*(a^2 + b^2)*(15*a^2*B + b*(56*a*A - 25*b*B))*EllipticF[Pi/4 - (I*x)/2, -((2*I*b)/(a - I*b))]*Sqrt[(a + b*Sinh[x])/(a - I*b)])/(105*b*Sqrt[a + b*Sinh[x]])}
{(A + B*Sinh[x])*(a + b*Sinh[x])^(3/2), x, 7, (2/15)*(5*A*b + 3*a*B)*Cosh[x]*Sqrt[a + b*Sinh[x]] + (2/5)*B*Cosh[x]*(a + b*Sinh[x])^(3/2) - (2*I*(9*b^2*B - a*(20*A*b + 3*a*B))*EllipticE[Pi/4 - (I*x)/2, -((2*I*b)/(a - I*b))]*Sqrt[a + b*Sinh[x]])/(15*b*Sqrt[(a + b*Sinh[x])/(a - I*b)]) + (2*I*(a*(9*b^2*B - a*(20*A*b + 3*a*B)) + b*(15*a^2*A - b*(5*A*b + 12*a*B)))*EllipticF[Pi/4 - (I*x)/2, -((2*I*b)/(a - I*b))]*Sqrt[(a + b*Sinh[x])/(a - I*b)])/(15*b*Sqrt[a + b*Sinh[x]])}
{(A + B*Sinh[x])*(a + b*Sinh[x])^(1/2), x, 6, (2/3)*B*Cosh[x]*Sqrt[a + b*Sinh[x]] + (2*I*(3*A*b + a*B)*EllipticE[Pi/4 - (I*x)/2, -((2*I*b)/(a - I*b))]*Sqrt[a + b*Sinh[x]])/(3*b*Sqrt[(a + b*Sinh[x])/(a - I*b)]) - (2*I*(a^2 + b^2)*B*EllipticF[Pi/4 - (I*x)/2, -((2*I*b)/(a - I*b))]*Sqrt[(a + b*Sinh[x])/(a - I*b)])/(3*b*Sqrt[a + b*Sinh[x]])}
{(A + B*Sinh[x])/(a + b*Sinh[x])^(1/2), x, 5, (2*I*B*EllipticE[Pi/4 - (I*x)/2, -((2*I*b)/(a - I*b))]*Sqrt[a + b*Sinh[x]])/(b*Sqrt[(a + b*Sinh[x])/(a - I*b)]) + (2*I*(A*b - a*B)*EllipticF[Pi/4 - (I*x)/2, -((2*I*b)/(a - I*b))]*Sqrt[(a + b*Sinh[x])/(a - I*b)])/(b*Sqrt[a + b*Sinh[x]])}
{(A + B*Sinh[x])/(a + b*Sinh[x])^(3/2), x, 6, -((2*(A*b - a*B)*Cosh[x])/((a^2 + b^2)*Sqrt[a + b*Sinh[x]])) + (2*I*(A*b - a*B)*EllipticE[Pi/4 - (I*x)/2, -((2*I*b)/(a - I*b))]*Sqrt[a + b*Sinh[x]])/(b*(a^2 + b^2)*Sqrt[(a + b*Sinh[x])/(a - I*b)]) + (2*I*B*EllipticF[Pi/4 - (I*x)/2, -((2*I*b)/(a - I*b))]*Sqrt[(a + b*Sinh[x])/(a - I*b)])/(b*Sqrt[a + b*Sinh[x]])}
{(A + B*Sinh[x])/(a + b*Sinh[x])^(5/2), x, 7, -((2*(A*b - a*B)*Cosh[x])/(3*(a^2 + b^2)*(a + b*Sinh[x])^(3/2))) - (2*(3*b^2*B + a*(4*A*b - a*B))*Cosh[x])/(3*(a^2 + b^2)^2*Sqrt[a + b*Sinh[x]]) + (2*I*(3*b^2*B + a*(4*A*b - a*B))*EllipticE[Pi/4 - (I*x)/2, -((2*I*b)/(a - I*b))]*Sqrt[a + b*Sinh[x]])/(3*b*(a^2 + b^2)^2*Sqrt[(a + b*Sinh[x])/(a - I*b)]) + (2*I*(b*(3*a^2*A - b*(A*b - 4*a*B)) - a*(3*b^2*B + a*(4*A*b - a*B)))*EllipticF[Pi/4 - (I*x)/2, -((2*I*b)/(a - I*b))]*Sqrt[(a + b*Sinh[x])/(a - I*b)])/(3*b*(a^2 + b^2)^2*Sqrt[a + b*Sinh[x]])}

{(A + B*Sinh[x])*(a + a*I*Sinh[x])^(5/2), x, 8, (64*I*a^3*A*Cosh[x])/(15*Sqrt[a + I*a*Sinh[x]]) + (64*a^3*B*Cosh[x])/(21*Sqrt[a + I*a*Sinh[x]]) + (16/15)*I*a^2*A*Cosh[x]*Sqrt[a + I*a*Sinh[x]] + (16/21)*a^2*B*Cosh[x]*Sqrt[a + I*a*Sinh[x]] + (2/5)*I*a*A*Cosh[x]*(a + I*a*Sinh[x])^(3/2) + (2/7)*a*B*Cosh[x]*(a + I*a*Sinh[x])^(3/2) + (2/7)*B*Cosh[x]*(a + I*a*Sinh[x])^(5/2)}
{(A + B*Sinh[x])*(a + a*I*Sinh[x])^(3/2), x, 6, (8*I*a^2*A*Cosh[x])/(3*Sqrt[a + I*a*Sinh[x]]) + (8*a^2*B*Cosh[x])/(5*Sqrt[a + I*a*Sinh[x]]) + (2/3)*I*a*A*Cosh[x]*Sqrt[a + I*a*Sinh[x]] + (2/5)*a*B*Cosh[x]*Sqrt[a + I*a*Sinh[x]] + (2/5)*B*Cosh[x]*(a + I*a*Sinh[x])^(3/2)}
{(A + B*Sinh[x])*(a + a*I*Sinh[x])^(1/2), x, 4, (2*I*a*A*Cosh[x])/Sqrt[a + I*a*Sinh[x]] + (2*a*B*Cosh[x])/(3*Sqrt[a + I*a*Sinh[x]]) + (2/3)*B*Cosh[x]*Sqrt[a + I*a*Sinh[x]]}
{(A + B*Sinh[x])/(a + a*I*Sinh[x])^(1/2), x, 3, (2*(I*A - B)*ArcTanh[Sin[Pi/4 - (I*x)/2]]*Cos[Pi/4 - (I*x)/2])/Sqrt[a + I*a*Sinh[x]] + (2*B*Cosh[x])/Sqrt[a + I*a*Sinh[x]]}
{(A + B*Sinh[x])/(a + a*I*Sinh[x])^(3/2), x, 4, ((I*A - B)*Cosh[x])/(2*(a + I*a*Sinh[x])^(3/2)) + (I*A*ArcTanh[Sin[Pi/4 - (I*x)/2]]*Cos[Pi/4 - (I*x)/2])/(2*a*Sqrt[a + I*a*Sinh[x]]) + (3*B*ArcTanh[Sin[Pi/4 - (I*x)/2]]*Cos[Pi/4 - (I*x)/2])/(2*a*Sqrt[a + I*a*Sinh[x]])}
{(A + B*Sinh[x])/(a + a*I*Sinh[x])^(5/2), x, 6, ((I*A - B)*Cosh[x])/(4*(a + I*a*Sinh[x])^(5/2)) + (3*I*A*Cosh[x])/(16*a*(a + I*a*Sinh[x])^(3/2)) + (5*B*Cosh[x])/(16*a*(a + I*a*Sinh[x])^(3/2)) + (3*I*A*ArcTanh[Sin[Pi/4 - (I*x)/2]]*Cos[Pi/4 - (I*x)/2])/(16*a^2*Sqrt[a + I*a*Sinh[x]]) + (5*B*ArcTanh[Sin[Pi/4 - (I*x)/2]]*Cos[Pi/4 - (I*x)/2])/(16*a^2*Sqrt[a + I*a*Sinh[x]])}


(* Integrands of the form (A+B*Cosh[x])*(a+b*Sinh[x])^n where n is an integer *)
{(A + B*Cosh[x])/(a + b*Sinh[x]), x, 5, -((2*A*ArcTanh[(b - a*Tanh[x/2])/Sqrt[a^2 + b^2]])/Sqrt[a^2 + b^2]) + (B*Log[a + b*Sinh[x]])/b}

{(A + B*Cosh[x])/(I + Sinh[x]), x, 5, B*Log[I + Sinh[x]] - (A*Cosh[x])/(1 - I*Sinh[x])}
{(A + B*Cosh[x])/(I - Sinh[x]), x, 5, (-B)*Log[I - Sinh[x]] + (A*Cosh[x])/(1 + I*Sinh[x])}


{(A + B*Tanh[x])/(a + b*Sinh[x]), x, 10, (b*B*ArcTan[Sinh[x]])/(a^2 + b^2) - (2*A*ArcTanh[(b - a*Tanh[x/2])/Sqrt[a^2 + b^2]])/Sqrt[a^2 + b^2] + (a*B*Log[Cosh[x]^2])/(2*(a^2 + b^2)) - (a*B*Log[a + b*Sinh[x]])/(a^2 + b^2)}
{(A + B*Coth[x])/(a + b*Sinh[x]), x, 5, -((2*A*ArcTanh[(b - a*Tanh[x/2])/Sqrt[a^2 + b^2]])/Sqrt[a^2 + b^2]) + (B*Log[Sinh[x]])/a - (B*Log[a + b*Sinh[x]])/a}
{(A + B*Sech[x])/(a + b*Sinh[x]), x, 10, (a*B*ArcTan[Sinh[x]])/(a^2 + b^2) - (2*A*ArcTanh[(b - a*Tanh[x/2])/Sqrt[a^2 + b^2]])/Sqrt[a^2 + b^2] - (b*B*Log[Cosh[x]^2])/(2*(a^2 + b^2)) + (b*B*Log[a + b*Sinh[x]])/(a^2 + b^2)}
{(A + B*Csch[x])/(a + b*Sinh[x]), x, 4, -((B*ArcCoth[Cosh[x]])/a) - (2*(a*A - b*B)*ArcTanh[(b - a*Tanh[x/2])/Sqrt[a^2 + b^2]])/(a*Sqrt[a^2 + b^2])}


(* ::Subsubsection::Closed:: *)
(*Integrands of the form (A+B Hyper[x]) (a+b Cosh[x])^n*)


(* Integrands of the form (A+B*Cosh[x])*(a+b*Cosh[x])^n where n is an integer *)
{(A + B*Cosh[x])/(a + b*Cosh[x]), x, 2, (B*x)/b + (2*(A*b - a*B)*ArcTanh[((a - b)*Tanh[x/2])/Sqrt[a^2 - b^2]])/(b*Sqrt[a^2 - b^2])}
{(A + B*Cosh[x])/(a + b*Cosh[x])^2, x, 2, (2*(a*A - b*B)*ArcTanh[((a - b)*Tanh[x/2])/Sqrt[a^2 - b^2]])/(a^2 - b^2)^(3/2) - ((A*b - a*B)*Sinh[x])/((a^2 - b^2)*(a + b*Cosh[x]))}
{(A + B*Cosh[x])/(a + b*Cosh[x])^3, x, 3, ((2*a^2*A + b*(A*b - 3*a*B))*ArcTanh[((a - b)*Tanh[x/2])/Sqrt[a^2 - b^2]])/(a^2 - b^2)^(5/2) - ((A*b - a*B)*Sinh[x])/(2*(a^2 - b^2)*(a + b*Cosh[x])^2) + ((2*b^2*B - a*(3*A*b - a*B))*Sinh[x])/(2*(a^2 - b^2)^2*(a + b*Cosh[x]))}
{(A + B*Cosh[x])/(a + b*Cosh[x])^4, x, 4, ((2*a*(2*A*b^2 + a*(3*a*A - 5*b*B)) - b*(2*a^2*B - b*(5*a*A - 3*b*B)))*ArcTanh[((a - b)*Tanh[x/2])/Sqrt[a^2 - b^2]])/(3*(a^2 - b^2)^(7/2)) - ((A*b - a*B)*Sinh[x])/(3*(a^2 - b^2)*(a + b*Cosh[x])^3) + ((2*a^2*B - b*(5*a*A - 3*b*B))*Sinh[x])/(6*(a^2 - b^2)^2*(a + b*Cosh[x])^2) - ((2*b*(2*A*b^2 + a*(3*a*A - 5*b*B)) - a*(2*a^2*B - b*(5*a*A - 3*b*B)))*Sinh[x])/(6*(a^2 - b^2)^3*(a + b*Cosh[x]))}

{(A + B*Cosh[x])/(1 + Cosh[x]), x, 2, B*x + ((A - B)*Sinh[x])/(1 + Cosh[x])}
{(A + B*Cosh[x])/(1 + Cosh[x])^2, x, 4, ((A - B)*Sinh[x])/(3*(1 + Cosh[x])^2) + (A*Sinh[x])/(3*(1 + Cosh[x])) + (2*B*Sinh[x])/(3*(1 + Cosh[x]))}
{(A + B*Cosh[x])/(1 + Cosh[x])^3, x, 6, ((A - B)*Sinh[x])/(5*(1 + Cosh[x])^3) + (2*A*Sinh[x])/(15*(1 + Cosh[x])^2) + (B*Sinh[x])/(5*(1 + Cosh[x])^2) + (2*A*Sinh[x])/(15*(1 + Cosh[x])) + (B*Sinh[x])/(5*(1 + Cosh[x]))}
{(A + B*Cosh[x])/(1 + Cosh[x])^4, x, 8, ((A - B)*Sinh[x])/(7*(1 + Cosh[x])^4) + (3*A*Sinh[x])/(35*(1 + Cosh[x])^3) + (4*B*Sinh[x])/(35*(1 + Cosh[x])^3) + (2*A*Sinh[x])/(35*(1 + Cosh[x])^2) + (8*B*Sinh[x])/(105*(1 + Cosh[x])^2) + (2*A*Sinh[x])/(35*(1 + Cosh[x])) + (8*B*Sinh[x])/(105*(1 + Cosh[x]))}

{(A + B*Cosh[x])/(1 - Cosh[x]), x, 2, (-B)*x - ((A + B)*Sinh[x])/(1 - Cosh[x])}
{(A + B*Cosh[x])/(1 - Cosh[x])^2, x, 4, -(((A + B)*Sinh[x])/(3*(1 - Cosh[x])^2)) - (A*Sinh[x])/(3*(1 - Cosh[x])) + (2*B*Sinh[x])/(3*(1 - Cosh[x]))}
{(A + B*Cosh[x])/(1 - Cosh[x])^3, x, 6, -(((A + B)*Sinh[x])/(5*(1 - Cosh[x])^3)) - (2*A*Sinh[x])/(15*(1 - Cosh[x])^2) + (B*Sinh[x])/(5*(1 - Cosh[x])^2) - (2*A*Sinh[x])/(15*(1 - Cosh[x])) + (B*Sinh[x])/(5*(1 - Cosh[x]))}
{(A + B*Cosh[x])/(1 - Cosh[x])^4, x, 8, -(((A + B)*Sinh[x])/(7*(1 - Cosh[x])^4)) - (3*A*Sinh[x])/(35*(1 - Cosh[x])^3) + (4*B*Sinh[x])/(35*(1 - Cosh[x])^3) - (2*A*Sinh[x])/(35*(1 - Cosh[x])^2) + (8*B*Sinh[x])/(105*(1 - Cosh[x])^2) - (2*A*Sinh[x])/(35*(1 - Cosh[x])) + (8*B*Sinh[x])/(105*(1 - Cosh[x]))}

{(b*B/a + B*Cosh[x])/(a + b*Cosh[x]), x, 2, (B*x)/b - (2*Sqrt[a^2 - b^2]*B*ArcTanh[((a - b)*Tanh[x/2])/Sqrt[a^2 - b^2]])/(a*b)}
{(a*B/b + B*Cosh[x])/(a + b*Cosh[x]), x, 2, (B*x)/b}

{(a + b*Cosh[x])/(b + a*Cosh[x])^2, x, 1, Sinh[x]/(b + a*Cosh[x])}
{(3 + Cosh[x])/(2 - Cosh[x]), x, 2, -x + (10*ArcTanh[Sqrt[3]*Tanh[x/2]])/Sqrt[3]}


(* Integrands of the form (A+B*Cosh[x])*(a+b*Cosh[x])^n where n is a half-integer *)
{(A + B*Cosh[x])*(a + b*Cosh[x])^(5/2), x, 8, -((2*I*(3*b*(21*A*b^2 + 5*a*(7*a*A + 8*b*B)) + a*(15*a^2*B + b*(56*a*A + 25*b*B)))*Sqrt[a + b*Cosh[x]]*EllipticE[(I*x)/2, (2*b)/(a + b)])/(105*b*Sqrt[(a + b*Cosh[x])/(a + b)])) + (2*I*(a^2 - b^2)*(15*a^2*B + b*(56*a*A + 25*b*B))*Sqrt[(a + b*Cosh[x])/(a + b)]*EllipticF[(I*x)/2, (2*b)/(a + b)])/(105*b*Sqrt[a + b*Cosh[x]]) + (2/105)*(15*a^2*B + b*(56*a*A + 25*b*B))*Sqrt[a + b*Cosh[x]]*Sinh[x] + (2/35)*(7*A*b + 5*a*B)*(a + b*Cosh[x])^(3/2)*Sinh[x] + (2/7)*B*(a + b*Cosh[x])^(5/2)*Sinh[x]}
{(A + B*Cosh[x])*(a + b*Cosh[x])^(3/2), x, 7, -((2*I*(9*b^2*B + a*(20*A*b + 3*a*B))*Sqrt[a + b*Cosh[x]]*EllipticE[(I*x)/2, (2*b)/(a + b)])/(15*b*Sqrt[(a + b*Cosh[x])/(a + b)])) + (2*I*(a*(9*b^2*B + a*(20*A*b + 3*a*B)) - b*(15*a^2*A + b*(5*A*b + 12*a*B)))*Sqrt[(a + b*Cosh[x])/(a + b)]*EllipticF[(I*x)/2, (2*b)/(a + b)])/(15*b*Sqrt[a + b*Cosh[x]]) + (2/15)*(5*A*b + 3*a*B)*Sqrt[a + b*Cosh[x]]*Sinh[x] + (2/5)*B*(a + b*Cosh[x])^(3/2)*Sinh[x]}
{(A + B*Cosh[x])*(a + b*Cosh[x])^(1/2), x, 6, -((2*I*(3*A*b + a*B)*Sqrt[a + b*Cosh[x]]*EllipticE[(I*x)/2, (2*b)/(a + b)])/(3*b*Sqrt[(a + b*Cosh[x])/(a + b)])) + (2*I*(a^2 - b^2)*B*Sqrt[(a + b*Cosh[x])/(a + b)]*EllipticF[(I*x)/2, (2*b)/(a + b)])/(3*b*Sqrt[a + b*Cosh[x]]) + (2/3)*B*Sqrt[a + b*Cosh[x]]*Sinh[x]}
{(A + B*Cosh[x])/(a + b*Cosh[x])^(1/2), x, 5, -((2*I*B*Sqrt[a + b*Cosh[x]]*EllipticE[(I*x)/2, (2*b)/(a + b)])/(b*Sqrt[(a + b*Cosh[x])/(a + b)])) - (2*I*(A*b - a*B)*Sqrt[(a + b*Cosh[x])/(a + b)]*EllipticF[(I*x)/2, (2*b)/(a + b)])/(b*Sqrt[a + b*Cosh[x]])}
{(A + B*Cosh[x])/(a + b*Cosh[x])^(3/2), x, 6, -((2*I*(A*b - a*B)*Sqrt[a + b*Cosh[x]]*EllipticE[(I*x)/2, (2*b)/(a + b)])/(b*(a^2 - b^2)*Sqrt[(a + b*Cosh[x])/(a + b)])) - (2*I*B*Sqrt[(a + b*Cosh[x])/(a + b)]*EllipticF[(I*x)/2, (2*b)/(a + b)])/(b*Sqrt[a + b*Cosh[x]]) - (2*(A*b - a*B)*Sinh[x])/((a^2 - b^2)*Sqrt[a + b*Cosh[x]])}
{(A + B*Cosh[x])/(a + b*Cosh[x])^(5/2), x, 7, (2*I*(3*b^2*B - a*(4*A*b - a*B))*Sqrt[a + b*Cosh[x]]*EllipticE[(I*x)/2, (2*b)/(a + b)])/(3*b*(a^2 - b^2)^2*Sqrt[(a + b*Cosh[x])/(a + b)]) - (2*I*(b*(3*a^2*A + b*(A*b - 4*a*B)) + a*(3*b^2*B - a*(4*A*b - a*B)))*Sqrt[(a + b*Cosh[x])/(a + b)]*EllipticF[(I*x)/2, (2*b)/(a + b)])/(3*b*(a^2 - b^2)^2*Sqrt[a + b*Cosh[x]]) - (2*(A*b - a*B)*Sinh[x])/(3*(a^2 - b^2)*(a + b*Cosh[x])^(3/2)) + (2*(3*b^2*B - a*(4*A*b - a*B))*Sinh[x])/(3*(a^2 - b^2)^2*Sqrt[a + b*Cosh[x]])}

{(A + B*Cosh[x])*(a + a*Cosh[x])^(5/2), x, 8, (64*a^3*A*Sinh[x])/(15*Sqrt[a + a*Cosh[x]]) + (64*a^3*B*Sinh[x])/(21*Sqrt[a + a*Cosh[x]]) + (16/15)*a^2*A*Sqrt[a + a*Cosh[x]]*Sinh[x] + (16/21)*a^2*B*Sqrt[a + a*Cosh[x]]*Sinh[x] + (2/5)*a*A*(a + a*Cosh[x])^(3/2)*Sinh[x] + (2/7)*a*B*(a + a*Cosh[x])^(3/2)*Sinh[x] + (2/7)*B*(a + a*Cosh[x])^(5/2)*Sinh[x]}
{(A + B*Cosh[x])*(a + a*Cosh[x])^(3/2), x, 6, (8*a^2*A*Sinh[x])/(3*Sqrt[a + a*Cosh[x]]) + (8*a^2*B*Sinh[x])/(5*Sqrt[a + a*Cosh[x]]) + (2/3)*a*A*Sqrt[a + a*Cosh[x]]*Sinh[x] + (2/5)*a*B*Sqrt[a + a*Cosh[x]]*Sinh[x] + (2/5)*B*(a + a*Cosh[x])^(3/2)*Sinh[x]}
{(A + B*Cosh[x])*(a + a*Cosh[x])^(1/2), x, 4, (2*a*A*Sinh[x])/Sqrt[a + a*Cosh[x]] + (2*a*B*Sinh[x])/(3*Sqrt[a + a*Cosh[x]]) + (2/3)*B*Sqrt[a + a*Cosh[x]]*Sinh[x]}
{(A + B*Cosh[x])/(a + a*Cosh[x])^(1/2), x, 3, (2*(A - B)*ArcTan[Sinh[x/2]]*Cosh[x/2])/Sqrt[a + a*Cosh[x]] + (2*B*Sinh[x])/Sqrt[a + a*Cosh[x]]}
{(A + B*Cosh[x])/(a + a*Cosh[x])^(3/2), x, 4, (A*ArcTan[Sinh[x/2]]*Cosh[x/2])/(2*a*Sqrt[a + a*Cosh[x]]) + (3*B*ArcTan[Sinh[x/2]]*Cosh[x/2])/(2*a*Sqrt[a + a*Cosh[x]]) + ((A - B)*Sinh[x])/(2*(a + a*Cosh[x])^(3/2))}
{(A + B*Cosh[x])/(a + a*Cosh[x])^(5/2), x, 6, (3*A*ArcTan[Sinh[x/2]]*Cosh[x/2])/(16*a^2*Sqrt[a + a*Cosh[x]]) + (5*B*ArcTan[Sinh[x/2]]*Cosh[x/2])/(16*a^2*Sqrt[a + a*Cosh[x]]) + ((A - B)*Sinh[x])/(4*(a + a*Cosh[x])^(5/2)) + (3*A*Sinh[x])/(16*a*(a + a*Cosh[x])^(3/2)) + (5*B*Sinh[x])/(16*a*(a + a*Cosh[x])^(3/2))}

{(A + B*Cosh[x])*(a - a*Cosh[x])^(5/2), x, 8, -((64*a^3*A*Sinh[x])/(15*Sqrt[a - a*Cosh[x]])) + (64*a^3*B*Sinh[x])/(21*Sqrt[a - a*Cosh[x]]) - (16/15)*a^2*A*Sqrt[a - a*Cosh[x]]*Sinh[x] + (16/21)*a^2*B*Sqrt[a - a*Cosh[x]]*Sinh[x] - (2/5)*a*A*(a - a*Cosh[x])^(3/2)*Sinh[x] + (2/7)*a*B*(a - a*Cosh[x])^(3/2)*Sinh[x] + (2/7)*B*(a - a*Cosh[x])^(5/2)*Sinh[x]}
{(A + B*Cosh[x])*(a - a*Cosh[x])^(3/2), x, 6, -((8*a^2*A*Sinh[x])/(3*Sqrt[a - a*Cosh[x]])) + (8*a^2*B*Sinh[x])/(5*Sqrt[a - a*Cosh[x]]) - (2/3)*a*A*Sqrt[a - a*Cosh[x]]*Sinh[x] + (2/5)*a*B*Sqrt[a - a*Cosh[x]]*Sinh[x] + (2/5)*B*(a - a*Cosh[x])^(3/2)*Sinh[x]}
{(A + B*Cosh[x])*(a - a*Cosh[x])^(1/2), x, 4, -((2*a*A*Sinh[x])/Sqrt[a - a*Cosh[x]]) + (2*a*B*Sinh[x])/(3*Sqrt[a - a*Cosh[x]]) + (2/3)*B*Sqrt[a - a*Cosh[x]]*Sinh[x]}
{(A + B*Cosh[x])/(a - a*Cosh[x])^(1/2), x, 3, -((2*(A + B)*ArcTanh[Cosh[x/2]]*Sinh[x/2])/Sqrt[a - a*Cosh[x]]) + (2*B*Sinh[x])/Sqrt[a - a*Cosh[x]]}
{(A + B*Cosh[x])/(a - a*Cosh[x])^(3/2), x, 4, -((A*ArcTanh[Cosh[x/2]]*Sinh[x/2])/(2*a*Sqrt[a - a*Cosh[x]])) + (3*B*ArcTanh[Cosh[x/2]]*Sinh[x/2])/(2*a*Sqrt[a - a*Cosh[x]]) - ((A + B)*Sinh[x])/(2*(a - a*Cosh[x])^(3/2))}
{(A + B*Cosh[x])/(a - a*Cosh[x])^(5/2), x, 6, -((3*A*ArcTanh[Cosh[x/2]]*Sinh[x/2])/(16*a^2*Sqrt[a - a*Cosh[x]])) + (5*B*ArcTanh[Cosh[x/2]]*Sinh[x/2])/(16*a^2*Sqrt[a - a*Cosh[x]]) - ((A + B)*Sinh[x])/(4*(a - a*Cosh[x])^(5/2)) - (3*A*Sinh[x])/(16*a*(a - a*Cosh[x])^(3/2)) + (5*B*Sinh[x])/(16*a*(a - a*Cosh[x])^(3/2))}


(* Integrands of the form (A+B*Sinh[x])*(a+b*Cosh[x])^n where n is an integer *)
{(A + B*Sinh[x])/(a + b*Cosh[x]), x, 5, (2*A*ArcTanh[((a - b)*Tanh[x/2])/Sqrt[a^2 - b^2]])/Sqrt[a^2 - b^2] + (B*Log[a + b*Cosh[x]])/b}

{(A + B*Sinh[x])/(1 + Cosh[x]), x, 4, B*Log[1 + Cosh[x]] + (A*Sinh[x])/(1 + Cosh[x]), 2*B*Log[Cosh[x/2]] + (A*Sinh[x])/(1 + Cosh[x])}
{(A + B*Sinh[x])/(1 - Cosh[x]), x, 4, (-B)*Log[1 - Cosh[x]] - (A*Sinh[x])/(1 - Cosh[x]), -2*B*Log[Sinh[x/2]] - (A*Sinh[x])/(1 - Cosh[x])}


{(A + B*Tanh[x])/(a + b*Cosh[x]), x, 5, (2*A*ArcTanh[((a - b)*Tanh[x/2])/Sqrt[a^2 - b^2]])/Sqrt[a^2 - b^2] + (B*Log[Cosh[x]])/a - (B*Log[a + b*Cosh[x]])/a}
{(A + B*Coth[x])/(a + b*Cosh[x]), x, 9, (2*A*ArcTanh[((a - b)*Tanh[x/2])/Sqrt[a^2 - b^2]])/Sqrt[a^2 - b^2] + (B*Log[1 - Cosh[x]])/(2*(a + b)) + (B*Log[1 + Cosh[x]])/(2*(a - b)) - (a*B*Log[a + b*Cosh[x]])/(a^2 - b^2)}
{(A + B*Sech[x])/(a + b*Cosh[x]), x, 4, (B*ArcTan[Sinh[x]])/a + (2*(a*A - b*B)*ArcTanh[((a - b)*Tanh[x/2])/Sqrt[a^2 - b^2]])/(a*Sqrt[a^2 - b^2])}
{(A + B*Csch[x])/(a + b*Cosh[x]), x, 9, (2*A*ArcTanh[((a - b)*Tanh[x/2])/Sqrt[a^2 - b^2]])/Sqrt[a^2 - b^2] + (B*Log[1 - Cosh[x]])/(2*(a + b)) - (B*Log[1 + Cosh[x]])/(2*(a - b)) + (b*B*Log[a + b*Cosh[x]])/(a^2 - b^2)}


(* ::Subsection::Closed:: *)
(*Integrands of the form x^m (A+B Hyper[x]) (a+b Hyper[x])^n*)


{x*((b - a*Sinh[x])/(a + b*Sinh[x])^2), x, 3, Log[a + b*Sinh[x]]/b - (x*Cosh[x])/(a + b*Sinh[x])}
{x*((b + a*Cosh[x])/(a + b*Cosh[x])^2), x, 3, -(Log[a + b*Cosh[x]]/b) + (x*Sinh[x])/(a + b*Cosh[x])}


(* ::Subsection::Closed:: *)
(*Integrands of the form (A+B Hyper[x]^m) / (a+b Hyper[x]^n)*)
(**)


{(1 + Sinh[x]^2)/(1 - Sinh[x]^2), x, 5, -x + Sqrt[2]*ArcTanh[Coth[x]/Sqrt[2]]}
{(1 - Sinh[x]^2)/(1 + Sinh[x]^2), x, 4, -x + 2*Tanh[x]}


{(1 + Cosh[x]^2)/(1 - Cosh[x]^2), x, 5, -x + 2*Coth[x]}
{(1 - Cosh[x]^2)/(1 + Cosh[x]^2), x, 6, -x + Sqrt[2]*ArcTanh[Tanh[x]/Sqrt[2]]}


{(a + b*Sech[x])/(c + d*Cosh[x]), x, 4, (b*ArcTan[Sinh[x]])/c + (2*(a*c - b*d)*ArcTanh[((c - d)*Tanh[x/2])/Sqrt[c^2 - d^2]])/(c*Sqrt[c^2 - d^2])}
{(a + b*Csch[x])/(c + d*Sinh[x]), x, 4, -((b*ArcCoth[Cosh[x]])/c) - (2*(a*c - b*d)*ArcTanh[(d - c*Tanh[x/2])/Sqrt[c^2 + d^2]])/(c*Sqrt[c^2 + d^2])}
{(a + b*Sech[x]^2)/(c + d*Cosh[x]), x, 5, -((b*d*ArcTan[Sinh[x]])/c^2) + (2*(a*c^2 + b*d^2)*ArcTanh[((c - d)*Tanh[x/2])/Sqrt[c^2 - d^2]])/(c^2*Sqrt[c^2 - d^2]) + (b*Tanh[x])/c}
{(a + b*Csch[x]^2)/(c + d*Sinh[x]), x, 5, (b*d*ArcCoth[Cosh[x]])/c^2 - (2*(a*c^2 + b*d^2)*ArcTanh[(d - c*Tanh[x/2])/Sqrt[c^2 + d^2]])/(c^2*Sqrt[c^2 + d^2]) - (b*Coth[x])/c}


(* ::Subsection::Closed:: *)
(*Integrands of the form (a Hyper[c+d x] + b Hyper[c+d x])^n*)


(* ::Subsubsection::Closed:: *)
(*Integrands of the form (a Cosh[c+d x] + b Sinh[c+d x])^n*)


(* Integrands of the form (a*Cosh[c+d*x]+b*Sinh[c+d*x])^n *)
{(a*Cosh[x] + b*Sinh[x]), x, 3, b*Cosh[x] + a*Sinh[x]}
{(a*Cosh[x] + b*Sinh[x])^2, x, 2, (1/2)*(a^2 - b^2)*x + (1/2)*(b*Cosh[x] + a*Sinh[x])*(a*Cosh[x] + b*Sinh[x])}
{(a*Cosh[x] + b*Sinh[x])^3, x, 2, (a^2 - b^2)*(b*Cosh[x] + a*Sinh[x]) + (1/3)*(b*Cosh[x] + a*Sinh[x])^3}
{(a*Cosh[x] + b*Sinh[x])^4, x, 3, (3/8)*(a^2 - b^2)^2*x + (3/8)*(a^2 - b^2)*(b*Cosh[x] + a*Sinh[x])*(a*Cosh[x] + b*Sinh[x]) + (1/4)*(b*Cosh[x] + a*Sinh[x])*(a*Cosh[x] + b*Sinh[x])^3}
{(a*Cosh[x] + b*Sinh[x])^5, x, 3, (a^2 - b^2)^2*(b*Cosh[x] + a*Sinh[x]) + (2/3)*(a^2 - b^2)*(b*Cosh[x] + a*Sinh[x])^3 + (1/5)*(b*Cosh[x] + a*Sinh[x])^5}

{1/(a*Cosh[x] + b*Sinh[x]), x, 1, (2*ArcTan[(b + a*Tanh[x/2])/Sqrt[a^2 - b^2]])/Sqrt[a^2 - b^2]}
{1/(a*Cosh[x] + b*Sinh[x])^2, x, 1, Sinh[x]/(a*(a*Cosh[x] + b*Sinh[x]))}
{1/(a*Cosh[x] + b*Sinh[x])^3, x, 2, ArcTan[(b + a*Tanh[x/2])/Sqrt[a^2 - b^2]]/(a^2 - b^2)^(3/2) + (b*Cosh[x] + a*Sinh[x])/(2*(a^2 - b^2)*(a*Cosh[x] + b*Sinh[x])^2)}
{1/(a*Cosh[x] + b*Sinh[x])^4, x, 2, (b*Cosh[x] + a*Sinh[x])/(3*(a^2 - b^2)*(a*Cosh[x] + b*Sinh[x])^3) + (2*Sinh[x])/(3*a*(a^2 - b^2)*(a*Cosh[x] + b*Sinh[x]))}
{1/(a*Cosh[x] + b*Sinh[x])^5, x, 3, (3*ArcTan[(b + a*Tanh[x/2])/Sqrt[a^2 - b^2]])/(4*(a^2 - b^2)^(5/2)) + (b*Cosh[x] + a*Sinh[x])/(4*(a^2 - b^2)*(a*Cosh[x] + b*Sinh[x])^4) + (3*(b*Cosh[x] + a*Sinh[x]))/(8*(a^2 - b^2)^2*(a*Cosh[x] + b*Sinh[x])^2)}

{(a*Cosh[x] + b*Sinh[x])^(1/2), x, 1, (2*I*EllipticE[(1/4)*(Pi - 2*I*(x + I*ArcTan[I*b, a])), 2]*Sqrt[a*Cosh[x] + b*Sinh[x]])/Sqrt[-((a*Cosh[x] + b*Sinh[x])/Sqrt[a^2 - b^2])]}
{(a*Cosh[x] + b*Sinh[x])^(3/2), x, 2, (2/3)*(b*Cosh[x] + a*Sinh[x])*Sqrt[a*Cosh[x] + b*Sinh[x]] + (2*I*(a^2 - b^2)*EllipticF[(1/4)*(Pi - 2*I*(x + I*ArcTan[I*b, a])), 2]*Sqrt[-((a*Cosh[x] + b*Sinh[x])/Sqrt[a^2 - b^2])])/(3*Sqrt[a*Cosh[x] + b*Sinh[x]])}
{(a*Cosh[x] + b*Sinh[x])^(5/2), x, 2, (2/5)*(b*Cosh[x] + a*Sinh[x])*(a*Cosh[x] + b*Sinh[x])^(3/2) + (6*I*(a^2 - b^2)*EllipticE[(1/4)*(Pi - 2*I*(x + I*ArcTan[I*b, a])), 2]*Sqrt[a*Cosh[x] + b*Sinh[x]])/(5*Sqrt[-((a*Cosh[x] + b*Sinh[x])/Sqrt[a^2 - b^2])])}

{1/(a*Cosh[x] + b*Sinh[x])^(1/2), x, 1, (2*I*EllipticF[(1/4)*(Pi - 2*I*(x + I*ArcTan[I*b, a])), 2]*Sqrt[-((a*Cosh[x] + b*Sinh[x])/Sqrt[a^2 - b^2])])/Sqrt[a*Cosh[x] + b*Sinh[x]]}
{1/(a*Cosh[x] + b*Sinh[x])^(3/2), x, 2, (2*(b*Cosh[x] + a*Sinh[x]))/((a^2 - b^2)*Sqrt[a*Cosh[x] + b*Sinh[x]]) - (2*I*EllipticE[(1/4)*(Pi - 2*I*(x + I*ArcTan[I*b, a])), 2]*Sqrt[a*Cosh[x] + b*Sinh[x]])/((a^2 - b^2)*Sqrt[-((a*Cosh[x] + b*Sinh[x])/Sqrt[a^2 - b^2])])}
{1/(a*Cosh[x] + b*Sinh[x])^(5/2), x, 2, (2*(b*Cosh[x] + a*Sinh[x]))/(3*(a^2 - b^2)*(a*Cosh[x] + b*Sinh[x])^(3/2)) + (2*I*EllipticF[(1/4)*(Pi - 2*I*(x + I*ArcTan[I*b, a])), 2]*Sqrt[-((a*Cosh[x] + b*Sinh[x])/Sqrt[a^2 - b^2])])/(3*(a^2 - b^2)*Sqrt[a*Cosh[x] + b*Sinh[x]])}


(* Integrands of the form (a*Cosh[c+d*x]+a*Sinh[c+d*x])^n *)
{(a*Cosh[c + d*x] + a*Sinh[c + d*x]), x, 3, (a*Cosh[c + d*x])/d + (a*Sinh[c + d*x])/d}
{(a*Cosh[c + d*x] + a*Sinh[c + d*x])^2, x, 1, (a^2*(Cosh[c + d*x] + Sinh[c + d*x])^2)/(2*d)}
{(a*Cosh[c + d*x] + a*Sinh[c + d*x])^3, x, 1, (a^3*(Cosh[c + d*x] + Sinh[c + d*x])^3)/(3*d)}
{(a*Cosh[c + d*x] + a*Sinh[c + d*x])^n, x, 1, (a*Cosh[c + d*x] + a*Sinh[c + d*x])^n/(d*n)}

{1/(a*Cosh[c + d*x] + a*Sinh[c + d*x]), x, 1, -((Cosh[c + d*x] - Sinh[c + d*x])/(a*d))}
{1/(a*Cosh[c + d*x] + a*Sinh[c + d*x])^2, x, 1, -((Cosh[c + d*x] - Sinh[c + d*x])^2/(2*a^2*d))}
{1/(a*Cosh[c + d*x] + a*Sinh[c + d*x])^3, x, 1, -((Cosh[c + d*x] - Sinh[c + d*x])^3/(3*a^3*d))}

{Sqrt[a*Cosh[c + d*x] + a*Sinh[c + d*x]], x, 1, (2*Sqrt[a*Cosh[c + d*x] + a*Sinh[c + d*x]])/d}
{1/Sqrt[a*Cosh[c + d*x] + a*Sinh[c + d*x]], x, 1, -(2/(d*Sqrt[a*Cosh[c + d*x] + a*Sinh[c + d*x]]))}


(* Integrands of the form (a*Cosh[c+d*x]-a*Sinh[c+d*x])^n *)
{(a*Cosh[c + d*x] - a*Sinh[c + d*x]), x, 3, -((a*Cosh[c + d*x])/d) + (a*Sinh[c + d*x])/d}
{(a*Cosh[c + d*x] - a*Sinh[c + d*x])^2, x, 1, -((a^2*(Cosh[c + d*x] - Sinh[c + d*x])^2)/(2*d))}
{(a*Cosh[c + d*x] - a*Sinh[c + d*x])^3, x, 1, -((a^3*(Cosh[c + d*x] - Sinh[c + d*x])^3)/(3*d))}
{(a*Cosh[c + d*x] - a*Sinh[c + d*x])^n, x, 1, -((a*Cosh[c + d*x] - a*Sinh[c + d*x])^n/(d*n))}

{1/(a*Cosh[c + d*x] - a*Sinh[c + d*x]), x, 1, (Cosh[c + d*x] + Sinh[c + d*x])/(a*d)}
{1/(a*Cosh[c + d*x] - a*Sinh[c + d*x])^2, x, 1, (Cosh[c + d*x] + Sinh[c + d*x])^2/(2*a^2*d)}
{1/(a*Cosh[c + d*x] - a*Sinh[c + d*x])^3, x, 1, (Cosh[c + d*x] + Sinh[c + d*x])^3/(3*a^3*d)}

{Sqrt[a*Cosh[c + d*x] - a*Sinh[c + d*x]], x, 1, -((2*Sqrt[a*Cosh[c + d*x] - a*Sinh[c + d*x]])/d)}
{1/Sqrt[a*Cosh[c + d*x] - a*Sinh[c + d*x]], x, 1, 2/(d*Sqrt[a*Cosh[c + d*x] - a*Sinh[c + d*x]])}


(* ::Subsubsection::Closed:: *)
(*Integrands of the form (a Sech[c+d x] + b Tanh[c+d x])^n*)


(* Integrands of the form (a*Sech[x]+b*Tanh[x])^n where n is an integer *)
{(a*Sech[x] + b*Tanh[x])^5, x, 14, (5/4)*a^3*b^2*ArcTan[Sinh[x]] + (3/8)*a*(a^4 + 5*b^4)*ArcTan[Sinh[x]] + (1/2)*b^5*Log[Cosh[x]^2] - b^3*(5*a^2 - b^2)*Sech[x]^2 - (1/4)*b*(5*a^4 - 10*a^2*b^2 + b^4)*Sech[x]^4 + (3/8)*a^5*Sech[x]*Tanh[x] + 5*a*b^2*(a^2/4 - (5*b^2)/8)*Sech[x]*Tanh[x] + (1/4)*a*(a^4 - 10*a^2*b^2 + 5*b^4)*Sech[x]^3*Tanh[x]}
{(a*Sech[x] + b*Tanh[x])^4, x, 11, b^4*x - 4*a*b^3*Sech[x] - (4/3)*a^3*b*Sech[x]^3 + (4/3)*a*b^3*Sech[x]^3 + a^4*Tanh[x] - b^4*Tanh[x] - (1/3)*a^4*Tanh[x]^3 + 2*a^2*b^2*Tanh[x]^3 - (1/3)*b^4*Tanh[x]^3}
{(a*Sech[x] + b*Tanh[x])^3, x, 10, (1/2)*a^3*ArcTan[Sinh[x]] + (3/2)*a*b^2*ArcTan[Sinh[x]] + (1/2)*b^3*Log[Cosh[x]^2] - (1/2)*b*(3*a^2 - b^2)*Sech[x]^2 + (1/2)*a*(a^2 - 3*b^2)*Sech[x]*Tanh[x]}
{(a*Sech[x] + b*Tanh[x])^2, x, 5, b^2*x - 2*a*b*Sech[x] + a^2*Tanh[x] - b^2*Tanh[x]}
{(a*Sech[x] + b*Tanh[x]), x, 3, a*ArcTan[Sinh[x]] + b*Log[Cosh[x]]}
{1/(a*Sech[x] + b*Tanh[x]), x, 3, Log[a + b*Sinh[x]]/b}
{1/(a*Sech[x] + b*Tanh[x])^2, x, 6, x/b^2 + (2*a*ArcTanh[(b - a*Tanh[x/2])/Sqrt[a^2 + b^2]])/(b^2*Sqrt[a^2 + b^2]) - Cosh[x]/(b*(a + b*Sinh[x]))}
{1/(a*Sech[x] + b*Tanh[x])^3, x, 7, Log[a + b*Sinh[x]]/b^3 - (a^2 + b^2)/(2*b^3*(a + b*Sinh[x])^2) + (2*a)/(b^3*(a + b*Sinh[x]))}
{1/(a*Sech[x] + b*Tanh[x])^4, x, 13, x/b^4 - (6*a^3*ArcTanh[(b - a*Tanh[x/2])/Sqrt[a^2 + b^2]])/(b^4*(a^2 + b^2)^(3/2)) - (5*a*ArcTanh[(b - a*Tanh[x/2])/Sqrt[a^2 + b^2]])/(b^2*(a^2 + b^2)^(3/2)) + (8*a*ArcTanh[(b - a*Tanh[x/2])/Sqrt[a^2 + b^2]])/(b^4*Sqrt[a^2 + b^2]) - ((a^2 + b^2)*Cosh[x])/(3*b^3*(a + b*Sinh[x])^3) + (7*a*Cosh[x])/(6*b^3*(a + b*Sinh[x])^2) - (11*a^2*Cosh[x])/(6*b^3*(a^2 + b^2)*(a + b*Sinh[x])) - (4*Cosh[x])/(3*b*(a^2 + b^2)*(a + b*Sinh[x]))}
{1/(a*Sech[x] + b*Tanh[x])^5, x, 9, Log[a + b*Sinh[x]]/b^5 - (a^2 + b^2)^2/(4*b^5*(a + b*Sinh[x])^4) + (4*a*(a^2 + b^2))/(3*b^5*(a + b*Sinh[x])^3) - (3*a^2 + b^2)/(b^5*(a + b*Sinh[x])^2) + (4*a)/(b^5*(a + b*Sinh[x]))}


(* Integrands of the form (Sech[x]+I*Tanh[x])^n where n is an integer *)
{(Sech[x] + I*Tanh[x])^5, x, 8, I*Log[1 - I*Sinh[x]] - (2*I)/(1 - I*Sinh[x])^2 + (4*I)/(1 - I*Sinh[x])}
{(Sech[x] + I*Tanh[x])^4, x, 3, x + 2*I*Tan[Pi/4 + (I*x)/2] - (2/3)*I*Tan[Pi/4 + (I*x)/2]^3}
{(Sech[x] + I*Tanh[x])^3, x, 7, (-I)*Log[I + Sinh[x]] + 2/(I + Sinh[x])}
{(Sech[x] + I*Tanh[x])^2, x, 3, -x - 2*I*Tan[Pi/4 + (I*x)/2]}
{(Sech[x] + I*Tanh[x]), x, 3, ArcTan[Sinh[x]] + I*Log[Cosh[x]]}
{1/(Sech[x] + I*Tanh[x]), x, 3, (-I)*Log[1 + I*Sinh[x]]}
{1/(Sech[x] + I*Tanh[x])^2, x, 3, -x + 2*I*Cot[Pi/4 + (I*x)/2]}
{1/(Sech[x] + I*Tanh[x])^3, x, 7, I*Log[-I + Sinh[x]] - 2/(I - Sinh[x])}
{1/(Sech[x] + I*Tanh[x])^4, x, 3, x - 2*I*Cot[Pi/4 + (I*x)/2] + (2/3)*I*Cot[Pi/4 + (I*x)/2]^3}
{1/(Sech[x] + I*Tanh[x])^5, x, 8, (-I)*Log[1 + I*Sinh[x]] + (2*I)/(1 + I*Sinh[x])^2 - (4*I)/(1 + I*Sinh[x])}


(* Integrands of the form (Sech[x]-I*Tanh[x])^n where n is an integer *)
{(Sech[x] - I*Tanh[x])^5, x, 8, (-I)*Log[1 + I*Sinh[x]] + (2*I)/(1 + I*Sinh[x])^2 - (4*I)/(1 + I*Sinh[x])}
{(Sech[x] - I*Tanh[x])^4, x, 3, x - 2*I*Tan[Pi/4 - (I*x)/2] + (2/3)*I*Tan[Pi/4 - (I*x)/2]^3}
{(Sech[x] - I*Tanh[x])^3, x, 7, I*Log[-I + Sinh[x]] - 2/(I - Sinh[x])}
{(Sech[x] - I*Tanh[x])^2, x, 3, -x + 2*I*Tan[Pi/4 - (I*x)/2]}
{(Sech[x] - I*Tanh[x]), x, 3, ArcTan[Sinh[x]] - I*Log[Cosh[x]]}
{1/(Sech[x] - I*Tanh[x]), x, 3, I*Log[1 - I*Sinh[x]]}
{1/(Sech[x] - I*Tanh[x])^2, x, 3, -x - 2*I*Cot[Pi/4 - (I*x)/2]}
{1/(Sech[x] - I*Tanh[x])^3, x, 7, (-I)*Log[I + Sinh[x]] + 2/(I + Sinh[x])}
{1/(Sech[x] - I*Tanh[x])^4, x, 3, x + 2*I*Cot[Pi/4 - (I*x)/2] - (2/3)*I*Cot[Pi/4 - (I*x)/2]^3}
{1/(Sech[x] - I*Tanh[x])^5, x, 8, I*Log[1 - I*Sinh[x]] - (2*I)/(1 - I*Sinh[x])^2 + (4*I)/(1 - I*Sinh[x])}


(* ::Subsubsection::Closed:: *)
(*Integrands of the form (a Coth[c+d x] + b Csch[c+d x])^n*)


(* Integrands of the form (a*Coth[x]+b*Csch[x])^n where n is an integer *)
{(a*Coth[x] + b*Csch[x]), x, 3, (-b)*ArcCoth[Cosh[x]] + a*Log[Sinh[x]]}
{(a*Coth[x] + b*Csch[x])^2, x, 5, a^2*x - a^2*Coth[x] - b^2*Coth[x] - 2*a*b*Csch[x]}
{(a*Coth[x] + b*Csch[x])^3, x, 8, (a + b)^3/(4*(1 - Cosh[x])) + (a - b)^3/(4*(1 + Cosh[x])) + (1/4)*(2*a - b)*(a + b)^2*Log[1 - Cosh[x]] + (1/4)*(a - b)^2*(2*a + b)*Log[1 + Cosh[x]]}
{(a*Coth[x] + b*Csch[x])^4, x, 11, a^4*x - a^4*Coth[x] + b^4*Coth[x] - (1/3)*a^4*Coth[x]^3 - 2*a^2*b^2*Coth[x]^3 - (1/3)*b^4*Coth[x]^3 - 4*a^3*b*Csch[x] - (4/3)*a^3*b*Csch[x]^3 - (4/3)*a*b^3*Csch[x]^3}
{(a*Coth[x] + b*Csch[x])^5, x, 10, -((a + b)^5/(16*(1 - Cosh[x])^2)) + ((7*a - 3*b)*(a + b)^4)/(16*(1 - Cosh[x])) - (a - b)^5/(16*(1 + Cosh[x])^2) + ((a - b)^4*(7*a + 3*b))/(16*(1 + Cosh[x])) + (1/16)*(a + b)^3*(8*a^2 - 9*a*b + 3*b^2)*Log[1 - Cosh[x]] + (1/16)*(a - b)^3*(8*a^2 + 9*a*b + 3*b^2)*Log[1 + Cosh[x]]}

{1/(a*Coth[x] + b*Csch[x]), x, 3, Log[b + a*Cosh[x]]/a}
{1/(a*Coth[x] + b*Csch[x])^2, x, 6, x/a^2 - (2*b*ArcTan[((a - b)*Tanh[x/2])/Sqrt[a^2 - b^2]])/(a^2*Sqrt[a^2 - b^2]) - Sinh[x]/(a*(b + a*Cosh[x]))}
{1/(a*Coth[x] + b*Csch[x])^3, x, 7, (a^2 - b^2)/(2*a^3*(b + a*Cosh[x])^2) + (2*b)/(a^3*(b + a*Cosh[x])) + Log[b + a*Cosh[x]]/a^3}
{1/(a*Coth[x] + b*Csch[x])^4, x, 13, x/a^4 + (5*b*ArcTan[((a - b)*Tanh[x/2])/Sqrt[a^2 - b^2]])/(a^2*(a^2 - b^2)^(3/2)) - (6*b^3*ArcTan[((a - b)*Tanh[x/2])/Sqrt[a^2 - b^2]])/(a^4*(a^2 - b^2)^(3/2)) - (8*b*ArcTan[((a - b)*Tanh[x/2])/Sqrt[a^2 - b^2]])/(a^4*Sqrt[a^2 - b^2]) + ((a^2 - b^2)*Sinh[x])/(3*a^3*(b + a*Cosh[x])^3) + (7*b*Sinh[x])/(6*a^3*(b + a*Cosh[x])^2) - (4*Sinh[x])/(3*a*(a^2 - b^2)*(b + a*Cosh[x])) + (11*b^2*Sinh[x])/(6*a^3*(a^2 - b^2)*(b + a*Cosh[x]))}
{1/(a*Coth[x] + b*Csch[x])^5, x, 9, -((a^2 - b^2)^2/(4*a^5*(b + a*Cosh[x])^4)) - (4*b*(a^2 - b^2))/(3*a^5*(b + a*Cosh[x])^3) + (a^2 - 3*b^2)/(a^5*(b + a*Cosh[x])^2) + (4*b)/(a^5*(b + a*Cosh[x])) + Log[b + a*Cosh[x]]/a^5}


(* Integrands of the form (Csch[x]+Coth[x])^n where n is an integer *)
{(Coth[x] + Csch[x]), x, 3, 2*Log[Sinh[x/2]], -ArcCoth[Cosh[x]] + Log[Sinh[x]]}
{(Coth[x] + Csch[x])^2, x, 2, x - 2*Coth[x/2]}
{(Coth[x] + Csch[x])^3, x, 6, 2/(1 - Cosh[x]) + Log[1 - Cosh[x]]}
{(Coth[x] + Csch[x])^4, x, 3, x - 2*Coth[x/2] - (2/3)*Coth[x/2]^3}
{(Coth[x] + Csch[x])^5, x, 7, -(2/(1 - Cosh[x])^2) + 4/(1 - Cosh[x]) + Log[1 - Cosh[x]]}

{1/(Coth[x] + Csch[x]), x, 3, Log[1 + Cosh[x]]}
{1/(Coth[x] + Csch[x])^2, x, 2, x - 2*Tanh[x/2]}
{1/(Coth[x] + Csch[x])^3, x, 6, 2/(1 + Cosh[x]) + Log[1 + Cosh[x]]}
{1/(Coth[x] + Csch[x])^4, x, 3, x - 2*Tanh[x/2] - (2/3)*Tanh[x/2]^3}
{1/(Coth[x] + Csch[x])^5, x, 7, -(2/(1 + Cosh[x])^2) + 4/(1 + Cosh[x]) + Log[1 + Cosh[x]]}


(* Integrands of the form (Csch[x]-Coth[x])^n where n is an integer *)
{(-Coth[x] + Csch[x]), x, 3, -2*Log[Cosh[x/2]], -ArcCoth[Cosh[x]] - Log[Sinh[x]]}
{(-Coth[x] + Csch[x])^2, x, 2, x - 2*Tanh[x/2]}
{(-Coth[x] + Csch[x])^3, x, 6, -(2/(1 + Cosh[x])) - Log[1 + Cosh[x]]}
{(-Coth[x] + Csch[x])^4, x, 3, x - 2*Tanh[x/2] - (2/3)*Tanh[x/2]^3}
{(-Coth[x] + Csch[x])^5, x, 8, 2/(1 + Cosh[x])^2 - 4/(1 + Cosh[x]) - Log[1 + Cosh[x]]}

{1/(-Coth[x] + Csch[x]), x, 3, -Log[1 - Cosh[x]]}
{1/(-Coth[x] + Csch[x])^2, x, 2, x - 2*Coth[x/2]}
{1/(-Coth[x] + Csch[x])^3, x, 7, -(2/(1 - Cosh[x])) - Log[1 - Cosh[x]]}
{1/(-Coth[x] + Csch[x])^4, x, 3, x - 2*Coth[x/2] - (2/3)*Coth[x/2]^3}
{1/(-Coth[x] + Csch[x])^5, x, 8, 2/(1 - Cosh[x])^2 - 4/(1 - Cosh[x]) - Log[1 - Cosh[x]]}


(* ::Subsubsection::Closed:: *)
(*Integrands of the form (a Csch[c+d x] + b Sinh[c+d x])^n*)


(* Integrands of the form (Csch[x]-Sinh[x])^n *)
(* Note that Csch[x]+Sinh[x] == Cosh[x]*Coth[x] *)
{(Csch[x] + Sinh[x]), x, 3, -ArcCoth[Cosh[x]] + Cosh[x]}
{(Csch[x] + Sinh[x])^2, x, 3, (3*x)/2 - (3*Coth[x])/2 + (1/2)*Cosh[x]^2*Coth[x]}
{(Csch[x] + Sinh[x])^3, x, 5, (-(5/2))*ArcCoth[Cosh[x]] + (5*Cosh[x])/2 - (5/6)*Cosh[x]*Coth[x]^2 + (1/3)*Cosh[x]^3*Coth[x]^2}

{(Csch[x] + Sinh[x])^(1/2), x, 3, 2*Sqrt[Cosh[x]*Coth[x]]*Tanh[x]}
{(Csch[x] + Sinh[x])^(3/2), x, 4, (-(2/3))*(4 - Cosh[x]^2)*Sqrt[Cosh[x]*Coth[x]]*Sech[x]}
{(Csch[x] + Sinh[x])^(5/2), x, 5, (2/15)*Sqrt[Cosh[x]*Coth[x]]*(32 - (8 - 3*Cosh[x]^2)*Coth[x]^2)*Tanh[x]}


(* ::Subsubsection::Closed:: *)
(*Integrands of the form (a Sech[c+d x] + b Cosh[c+d x])^n*)


(* Integrands of the form (Sech[x]-Cosh[x])^n *)
(* Note that Sech[x]-Cosh[x] == -Sinh[x]*Tanh[x] *)
{(Sech[x] - Cosh[x]), x, 3, ArcTan[Sinh[x]] - Sinh[x]}
{(Sech[x] - Cosh[x])^2, x, 3, -((3*x)/2) + (3*Tanh[x])/2 + (1/2)*Sinh[x]^2*Tanh[x]}
{(Sech[x] - Cosh[x])^3, x, 6, (-(5/2))*ArcTan[Sinh[x]] + (5*Sinh[x])/2 - (5/6)*Sinh[x]*Tanh[x]^2 - (1/3)*Sinh[x]^3*Tanh[x]^2}

{(Sech[x] - Cosh[x])^(1/2), x, 3, 2*Coth[x]*Sqrt[(-Sinh[x])*Tanh[x]]}
{(Sech[x] - Cosh[x])^(3/2), x, 4, (-(2/3))*Csch[x]*(4 + Sinh[x]^2)*Sqrt[(-Sinh[x])*Tanh[x]]}
{(Sech[x] - Cosh[x])^(5/2), x, 5, (-(2/15))*Coth[x]*Sqrt[(-Sinh[x])*Tanh[x]]*(32 - (8 + 3*Sinh[x]^2)*Tanh[x]^2)}


(* ::Subsubsection::Closed:: *)
(*Integrands of the form (a Sinh[c+d x] + b Tanh[c+d x])^n*)


{1/(Sinh[x] + Tanh[x]), x, 3, (1/2)*Log[Tanh[x/2]] + (1/4)*Tanh[x/2]^2}
{1/(Sinh[x] - Tanh[x]), x, 3, (-(1/4))*Coth[x/2]^2 + (1/2)*Log[Tanh[x/2]]}


(* ::Subsection::Closed:: *)
(*Integrands of the form (a Hyper[c+d x]^2 + b Hyper[c+d x]^2)^n*)


(* Integrands of the form 1/(Cosh[x]^2+/-Sinh[x]^2)^n where n is an integer *)
{1/(Cosh[x]^2 + Sinh[x]^2), x, 2, ArcTan[Tanh[x]], (1/2)*ArcTan[Sinh[2*x]]}
{1/(Cosh[x]^2 + Sinh[x]^2)^2, x, 2, (1/2)*Tanh[2*x]}
{1/(Cosh[x]^2 + Sinh[x]^2)^3, x, 3, (1/4)*ArcTan[Sinh[2*x]] + (1/4)*Sech[2*x]*Tanh[2*x]}

{1/(Cosh[x]^2 - Sinh[x]^2), x, 2, x}
{1/(Cosh[x]^2 - Sinh[x]^2)^2, x, 2, x}
{1/(Cosh[x]^2 - Sinh[x]^2)^3, x, 2, x}


(* Integrands of the form 1/(Sech[x]^2+/-Tanh[x]^2)^n where n is an integer *)
{1/(Sech[x]^2 + Tanh[x]^2), x, 2, x}
{1/(Sech[x]^2 + Tanh[x]^2)^2, x, 2, x}
{1/(Sech[x]^2 + Tanh[x]^2)^3, x, 2, x}

{1/(Sech[x]^2 - Tanh[x]^2), x, 5, -x + Sqrt[2]*ArcTanh[Coth[x]/Sqrt[2]]}
{1/(Sech[x]^2 - Tanh[x]^2)^2, x, 8, x - ArcTanh[Coth[x]/Sqrt[2]]/Sqrt[2] - Coth[x]/(2 - Coth[x]^2), x - 2*Sqrt[2]*ArcTanh[Coth[x]/Sqrt[2]] + (3*ArcTanh[Sqrt[2]*Tanh[x]])/Sqrt[2] + Sinh[2*x]/(3 - Cosh[2*x])}
{1/(Sech[x]^2 - Tanh[x]^2)^3, x, 12, -x + (7*ArcTanh[Coth[x]/Sqrt[2]])/(4*Sqrt[2]) - (15*Coth[x])/(2 - Coth[x]^2)^2 + (8*Coth[x]^3)/(2 - Coth[x]^2)^2 + (31*Coth[x])/(4*(2 - Coth[x]^2)), -x + 3*Sqrt[2]*ArcTanh[Coth[x]/Sqrt[2]] - (17*ArcTanh[Sqrt[2]*Tanh[x]])/(4*Sqrt[2]) + (2*Sinh[2*x])/(3 - Cosh[2*x])^2 - (3*Sinh[2*x])/(4*(3 - Cosh[2*x]))}


(* Integrands of the form 1/(Coth[x]^2+/-Csch[x]^2)^n where n is an integer *)
{1/(Coth[x]^2 + Csch[x]^2), x, 5, x - Sqrt[2]*ArcTanh[Tanh[x]/Sqrt[2]]}
{1/(Coth[x]^2 + Csch[x]^2)^2, x, 8, x - ArcTanh[Sqrt[2]*Coth[x]]/Sqrt[2] + Coth[x]/(1 - 2*Coth[x]^2), x - 2*Sqrt[2]*ArcTanh[Sqrt[2]*Coth[x]] + (3*ArcTanh[Tanh[x]/Sqrt[2]])/Sqrt[2] - Sinh[2*x]/(3 + Cosh[2*x])}
{1/(Coth[x]^2 + Csch[x]^2)^3, x, 12, x - (7*ArcTanh[Tanh[x]/Sqrt[2]])/(4*Sqrt[2]) - Tanh[x]/(2 - Tanh[x]^2)^2 + Tanh[x]/(4*(2 - Tanh[x]^2)), x - 3*Sqrt[2]*ArcTanh[Sqrt[2]*Coth[x]] + (17*ArcTanh[Tanh[x]/Sqrt[2]])/(4*Sqrt[2]) + (2*Sinh[2*x])/(3 + Cosh[2*x])^2 - (3*Sinh[2*x])/(4*(3 + Cosh[2*x]))}

{1/(Coth[x]^2 - Csch[x]^2), x, 2, x}
{1/(Coth[x]^2 - Csch[x]^2)^2, x, 2, x}
{1/(Coth[x]^2 - Csch[x]^2)^3, x, 2, x}


(* ::Subsection::Closed:: *)
(*Integrands of the form (a + b Hyper[d+e x] + c Hyper[d+e x])^n*)
(**)


(* ::Subsubsection::Closed:: *)
(*Integrands of the form (a + b Cosh[d+e x] + c Sinh[d+e x])^n*)


(* Integrands of the form (a+b*Cosh[x]+c*Sinh[x])^n where n is an integer *)
{(a + b*Cosh[x] + c*Sinh[x])^3, x, 8, a^3*x + (3/2)*a*b^2*x - (3/2)*a*c^2*x + (2/3)*c*(4*a^2 + b^2 - c^2)*Cosh[x] + (5/3)*a*b*c*Cosh[x]^2 + (2/3)*b*(4*a^2 + b^2 - c^2)*Sinh[x] + (5/6)*a*b^2*Cosh[x]*Sinh[x] + (5/6)*a*c^2*Cosh[x]*Sinh[x] + (1/3)*(c*Cosh[x] + b*Sinh[x])*(a + b*Cosh[x] + c*Sinh[x])^2}
{(a + b*Cosh[x] + c*Sinh[x])^2, x, 4, a^2*x + (b^2*x)/2 - (c^2*x)/2 + (3/2)*a*c*Cosh[x] + (3/2)*a*b*Sinh[x] + (1/2)*(c*Cosh[x] + b*Sinh[x])*(a + b*Cosh[x] + c*Sinh[x])}
{(a + b*Cosh[x] + c*Sinh[x]), x, 3, a*x + c*Cosh[x] + b*Sinh[x]}
{1/(a + b*Cosh[x] + c*Sinh[x]), x, 1, -((2*ArcTanh[(c - (a - b)*Tanh[x/2])/Sqrt[a^2 - b^2 + c^2]])/Sqrt[a^2 - b^2 + c^2])}
{1/(a + b*Cosh[x] + c*Sinh[x])^2, x, 2, -((2*a*ArcTanh[(c - (a - b)*Tanh[x/2])/Sqrt[a^2 - b^2 + c^2]])/(a^2 - b^2 + c^2)^(3/2)) - (c*Cosh[x] + b*Sinh[x])/((a^2 - b^2 + c^2)*(a + b*Cosh[x] + c*Sinh[x]))}
{1/(a + b*Cosh[x] + c*Sinh[x])^3, x, 3, -((c*Cosh[x] + b*Sinh[x])/(2*(a^2 - b^2 + c^2)*(a + b*Cosh[x] + c*Sinh[x])^2)) - (-((2*(-2*a^2 - b^2 + c^2)*ArcTanh[(c - (a - b)*Tanh[x/2])/Sqrt[a^2 - b^2 + c^2]])/(a^2 - b^2 + c^2)^(3/2)) - (-3*a*c*Cosh[x] - 3*a*b*Sinh[x])/((a^2 - b^2 + c^2)*(a + b*Cosh[x] + c*Sinh[x])))/(2*(a^2 - b^2 + c^2))}
{1/(a + b*Cosh[x] + c*Sinh[x])^4, x, 4, -((c*Cosh[x] + b*Sinh[x])/(3*(a^2 - b^2 + c^2)*(a + b*Cosh[x] + c*Sinh[x])^3)) - (6*a*(2*a^2 + 3*b^2 - 3*c^2)*ArcTanh[(c - (a - b)*Tanh[x/2])/Sqrt[a^2 - b^2 + c^2]] + (Sqrt[a^2 - b^2 + c^2]*(c*Cosh[x] + b*Sinh[x])*(5*a*(a^2 - b^2 + c^2) + (11*a^2 + 4*(b^2 - c^2))*(a + b*Cosh[x] + c*Sinh[x])))/(a + b*Cosh[x] + c*Sinh[x])^2)/(6*(a^2 - b^2 + c^2)^(7/2))}

{(a + a*Cosh[x] + c*Sinh[x])^3, x, 10, (5*a^3*x)/2 - (3/2)*a*c^2*x + (2/3)*c*(5*a^2 - c^2)*Cosh[x] + (5/3)*a^2*c*Cosh[x]^2 + (2/3)*a*(5*a^2 - c^2)*Sinh[x] + (5/6)*a^3*Cosh[x]*Sinh[x] + (5/6)*a*c^2*Cosh[x]*Sinh[x] + (1/3)*(c*Cosh[x] + a*Sinh[x])*(a + a*Cosh[x] + c*Sinh[x])^2}
{(a + a*Cosh[x] + c*Sinh[x])^2, x, 4, (3*a^2*x)/2 - (c^2*x)/2 + (3/2)*a*c*Cosh[x] + (3/2)*a^2*Sinh[x] + (1/2)*(c*Cosh[x] + a*Sinh[x])*(a + a*Cosh[x] + c*Sinh[x])}
{(a + a*Cosh[x] + c*Sinh[x]), x, 3, a*x + c*Cosh[x] + a*Sinh[x]}
{1/(a + a*Cosh[x] + c*Sinh[x]), x, 1, Log[a + c*Tanh[x/2]]/c}
{1/(a + a*Cosh[x] + c*Sinh[x])^2, x, 2, (a*Log[a + c*Tanh[x/2]])/c^3 - (c*Cosh[x] + a*Sinh[x])/(c^2*(a + a*Cosh[x] + c*Sinh[x]))}
{1/(a + a*Cosh[x] + c*Sinh[x])^3, x, 3, -((c*Cosh[x] + a*Sinh[x])/(2*c^2*(a + a*Cosh[x] + c*Sinh[x])^2)) + ((3*a^2 - c^2)*Log[a + c*Tanh[x/2]] - (3*a*c*(c*Cosh[x] + a*Sinh[x]))/(a + a*Cosh[x] + c*Sinh[x]))/(2*c^5)}
{1/(a + a*Cosh[x] + c*Sinh[x])^4, x, 4, -((c*Cosh[x] + a*Sinh[x])/(3*c^2*(a + a*Cosh[x] + c*Sinh[x])^3)) + (3*a*(5*a^2 - 3*c^2)*Log[a + c*Tanh[x/2]] - (c*(c*Cosh[x] + a*Sinh[x])*(5*a*c^2 + (15*a^2 - 4*c^2)*(a + a*Cosh[x] + c*Sinh[x])))/(a + a*Cosh[x] + c*Sinh[x])^2)/(6*c^7)}

{(Sqrt[b^2 - c^2]+b*Cosh[x]+c*Sinh[x])^4, x, 6, (35/8)*(b^2 - c^2)^2*x + (35/8)*c*(b^2 - c^2)^(3/2)*Cosh[x] + (35/8)*b*(b^2 - c^2)^(3/2)*Sinh[x] + (35/24)*(b^2 - c^2)*(c*Cosh[x] + b*Sinh[x])*(Sqrt[b^2 - c^2] + b*Cosh[x] + c*Sinh[x]) + (7/12)*Sqrt[b^2 - c^2]*(c*Cosh[x] + b*Sinh[x])*(Sqrt[b^2 - c^2] + b*Cosh[x] + c*Sinh[x])^2 + (1/4)*(c*Cosh[x] + b*Sinh[x])*(Sqrt[b^2 - c^2] + b*Cosh[x] + c*Sinh[x])^3}
{(Sqrt[b^2 - c^2]+b*Cosh[x]+c*Sinh[x])^3, x, 5, (5/2)*(b^2 - c^2)^(3/2)*x + (5/2)*c*(b^2 - c^2)*Cosh[x] + (5/2)*b*(b^2 - c^2)*Sinh[x] + (5/6)*Sqrt[b^2 - c^2]*(c*Cosh[x] + b*Sinh[x])*(Sqrt[b^2 - c^2] + b*Cosh[x] + c*Sinh[x]) + (1/3)*(c*Cosh[x] + b*Sinh[x])*(Sqrt[b^2 - c^2] + b*Cosh[x] + c*Sinh[x])^2}
{(Sqrt[b^2 - c^2]+b*Cosh[x]+c*Sinh[x])^2, x, 4, (3/2)*(b^2 - c^2)*x + (3/2)*c*Sqrt[b^2 - c^2]*Cosh[x] + (3/2)*b*Sqrt[b^2 - c^2]*Sinh[x] + (1/2)*(c*Cosh[x] + b*Sinh[x])*(Sqrt[b^2 - c^2] + b*Cosh[x] + c*Sinh[x])}
{(Sqrt[b^2 - c^2]+b*Cosh[x]+c*Sinh[x]), x, 3, Sqrt[b^2 - c^2]*x + c*Cosh[x] + b*Sinh[x]}
{1/(Sqrt[b^2 - c^2]+b*Cosh[x]+c*Sinh[x]), x, 1, -((c + Sqrt[b^2 - c^2]*Sinh[x])/(c*(c*Cosh[x] + b*Sinh[x])))}
{1/(Sqrt[b^2 - c^2]+b*Cosh[x]+c*Sinh[x])^2, x, 2, (c*Cosh[x] + b*Sinh[x])/(3*Sqrt[b^2 - c^2]*(Sqrt[b^2 - c^2] + b*Cosh[x] + c*Sinh[x])^2) - (c + Sqrt[b^2 - c^2]*Sinh[x])/(3*c*Sqrt[b^2 - c^2]*(c*Cosh[x] + b*Sinh[x]))}
{1/(Sqrt[b^2 - c^2]+b*Cosh[x]+c*Sinh[x])^3, x, 3, (c*Cosh[x] + b*Sinh[x])/(5*Sqrt[b^2 - c^2]*(Sqrt[b^2 - c^2] + b*Cosh[x] + c*Sinh[x])^3) + (2*(c*Cosh[x] + b*Sinh[x]))/(15*(b^2 - c^2)*(Sqrt[b^2 - c^2] + b*Cosh[x] + c*Sinh[x])^2) - (2*(c + Sqrt[b^2 - c^2]*Sinh[x]))/(15*c*(b^2 - c^2)*(c*Cosh[x] + b*Sinh[x]))}
{1/(Sqrt[b^2 - c^2]+b*Cosh[x]+c*Sinh[x])^4, x, 4, (c*Cosh[x] + b*Sinh[x])/(7*Sqrt[b^2 - c^2]*(Sqrt[b^2 - c^2] + b*Cosh[x] + c*Sinh[x])^4) + (3*(c*Cosh[x] + b*Sinh[x]))/(35*(b^2 - c^2)*(Sqrt[b^2 - c^2] + b*Cosh[x] + c*Sinh[x])^3) + (2*(c*Cosh[x] + b*Sinh[x]))/(35*(b^2 - c^2)^(3/2)*(Sqrt[b^2 - c^2] + b*Cosh[x] + c*Sinh[x])^2) - (2*(c + Sqrt[b^2 - c^2]*Sinh[x]))/(35*c*(b^2 - c^2)^(3/2)*(c*Cosh[x] + b*Sinh[x]))}


(* Integrands of the form (a+b*Cosh[x]+c*Sinh[x])^n where n is a half-integer *)
{(a + b*Cosh[x] + c*Sinh[x])^(5/2), x, 5, (16/15)*a*(c*Cosh[x] + b*Sinh[x])*Sqrt[a + b*Cosh[x] + c*Sinh[x]] + (2/5)*(c*Cosh[x] + b*Sinh[x])*(a + b*Cosh[x] + c*Sinh[x])^(3/2) + (2*I*(23*a^2 + 9*(b^2 - c^2))*EllipticE[(1/4)*(Pi - 2*I*(x + I*ArcTan[I*c, b])), 2/(1 - a/Sqrt[b^2 - c^2])]*Sqrt[a + b*Cosh[x] + c*Sinh[x]])/(15*Sqrt[(a + b*Cosh[x] + c*Sinh[x])/(a - Sqrt[b^2 - c^2])]) - (16*I*a*(a^2 - b^2 + c^2)*EllipticF[(1/4)*(Pi - 2*I*(x + I*ArcTan[I*c, b])), 2/(1 - a/Sqrt[b^2 - c^2])]*Sqrt[(a + b*Cosh[x] + c*Sinh[x])/(a - Sqrt[b^2 - c^2])])/(15*Sqrt[a + b*Cosh[x] + c*Sinh[x]])}
{(a + b*Cosh[x] + c*Sinh[x])^(3/2), x, 4, (2/3)*(c*Cosh[x] + b*Sinh[x])*Sqrt[a + b*Cosh[x] + c*Sinh[x]] + (8*I*a*EllipticE[(1/4)*(Pi - 2*I*(x + I*ArcTan[I*c, b])), 2/(1 - a/Sqrt[b^2 - c^2])]*Sqrt[a + b*Cosh[x] + c*Sinh[x]])/(3*Sqrt[(a + b*Cosh[x] + c*Sinh[x])/(a - Sqrt[b^2 - c^2])]) - (2*I*(a^2 - b^2 + c^2)*EllipticF[(1/4)*(Pi - 2*I*(x + I*ArcTan[I*c, b])), 2/(1 - a/Sqrt[b^2 - c^2])]*Sqrt[(a + b*Cosh[x] + c*Sinh[x])/(a - Sqrt[b^2 - c^2])])/(3*Sqrt[a + b*Cosh[x] + c*Sinh[x]])}
{(a + b*Cosh[x] + c*Sinh[x])^(1/2), x, 1, (2*I*EllipticE[(1/4)*(Pi - 2*I*(x + I*ArcTan[I*c, b])), 2/(1 - a/Sqrt[b^2 - c^2])]*Sqrt[a + b*Cosh[x] + c*Sinh[x]])/Sqrt[(a + b*Cosh[x] + c*Sinh[x])/(a - Sqrt[b^2 - c^2])]}
{1/(a + b*Cosh[x] + c*Sinh[x])^(1/2), x, 1, (2*I*EllipticF[(1/4)*(Pi - 2*I*(x + I*ArcTan[I*c, b])), 2/(1 - a/Sqrt[b^2 - c^2])]*Sqrt[(a + b*Cosh[x] + c*Sinh[x])/(a - Sqrt[b^2 - c^2])])/Sqrt[a + b*Cosh[x] + c*Sinh[x]]}
{1/(a + b*Cosh[x] + c*Sinh[x])^(3/2), x, 2, -((2*(c*Cosh[x] + b*Sinh[x]))/((a^2 - b^2 + c^2)*Sqrt[a + b*Cosh[x] + c*Sinh[x]])) + (2*I*EllipticE[(1/4)*(Pi - 2*I*(x + I*ArcTan[I*c, b])), 2/(1 - a/Sqrt[b^2 - c^2])]*Sqrt[a + b*Cosh[x] + c*Sinh[x]])/((a^2 - b^2 + c^2)*Sqrt[(a + b*Cosh[x] + c*Sinh[x])/(a - Sqrt[b^2 - c^2])])}
{1/(a + b*Cosh[x] + c*Sinh[x])^(5/2), x, 5, -((2*(c*Cosh[x] + b*Sinh[x]))/(3*(a^2 - b^2 + c^2)*(a + b*Cosh[x] + c*Sinh[x])^(3/2))) - (1/(3*(a^2 - b^2 + c^2)))*(2*((2*(-2*a*c*Cosh[x] - 2*a*b*Sinh[x]))/((-a^2 + b^2 - c^2)*Sqrt[a + b*Cosh[x] + c*Sinh[x]]) + (4*I*a*EllipticE[(1/2)*(Pi/2 - I*(x + I*ArcTan[I*c, b])), 2/(1 - a/Sqrt[b^2 - c^2])]*Sqrt[a + b*Cosh[x] + c*Sinh[x]])/((-a^2 + b^2 - c^2)*Sqrt[(a + b*Cosh[x] + c*Sinh[x])/(a - Sqrt[b^2 - c^2])]) + (4*I*((-a^2)*b + (1/2)*b*((3*a^2)/2 + b^2/2 - c^2/2))*EllipticF[(1/2)*(Pi/2 - I*(x + I*ArcTan[I*c, b])), 2/(1 - a/Sqrt[b^2 - c^2])]*Sqrt[(a + b*Cosh[x] + c*Sinh[x])/(a - Sqrt[b^2 - c^2])])/(b*(-a^2 + b^2 - c^2)*Sqrt[a + b*Cosh[x] + c*Sinh[x]])))}
(* {1/(a + b*Cosh[x] + c*Sinh[x])^(7/2), x, 6, -((2*(c*Cosh[x] + b*Sinh[x]))/(5*(a^2 - b^2 + c^2)*(a + b*Cosh[x] + c*Sinh[x])^(5/2))) - (1/(5*(a^2 - b^2 + c^2)))*(2*(-((2*(-4*a*c*Cosh[x] - 4*a*b*Sinh[x]))/(3*(a^2 - b^2 + c^2)*(a + b*Cosh[x] + c*Sinh[x])^(3/2))) - (4*I*(-2*a^2*b + (3/2)*b*(-((5*a^2)/2) - (3*b^2)/2 + (3*c^2)/2))*EllipticE[(1/2)*(Pi/2 - I*(x + I*ArcTan[I*c, b])), 2/(1 - a/Sqrt[b^2 - c^2])]*Sqrt[a + b*Cosh[x] + c*Sinh[x]])/(3*b*(-a^2 + b^2 - c^2)*(a^2 - b^2 + c^2)*Sqrt[(a + b*Cosh[x] + c*Sinh[x])/(a - Sqrt[b^2 - c^2])]) - (8*I*((1/2)*b*(-2*a*b^2 + 2*a*c^2 + (3/2)*a*(-((5*a^2)/2) - (3*b^2)/2 + (3*c^2)/2)) - (1/2)*a*(-2*a^2*b + (3/2)*b*(-((5*a^2)/2) - (3*b^2)/2 + (3*c^2)/2)))*EllipticF[(1/2)*(Pi/2 - I*(x + I*ArcTan[I*c, b])), 2/(1 - a/Sqrt[b^2 - c^2])]*Sqrt[(a + b*Cosh[x] + c*Sinh[x])/(a - Sqrt[b^2 - c^2])])/(3*b*(-a^2 + b^2 - c^2)*(a^2 - b^2 + c^2)*Sqrt[a + b*Cosh[x] + c*Sinh[x]]) - (4*((-(-2*a^2*c + (3/2)*c*(-((5*a^2)/2) - (3*b^2)/2 + (3*c^2)/2)))*Cosh[x] + (2*a^2*b - (3/2)*b*(-((5*a^2)/2) - (3*b^2)/2 + (3*c^2)/2))*Sinh[x]))/(3*(-a^2 + b^2 - c^2)*(a^2 - b^2 + c^2)*Sqrt[a + b*Cosh[x] + c*Sinh[x]])))} *)


(* Integrands of the form (a+b*Cosh[x]+c*Sinh[x])^n where n is a half-integer and a^2=b^2-c^2 *)
{(Sqrt[b^2 - c^2] + b*Cosh[x] + c*Sinh[x])^(5/2), x, 3, (64*(b^2 - c^2)*(c*Cosh[x] + b*Sinh[x]))/(15*Sqrt[Sqrt[b^2 - c^2] + b*Cosh[x] + c*Sinh[x]]) + (16/15)*Sqrt[b^2 - c^2]*(c*Cosh[x] + b*Sinh[x])*Sqrt[Sqrt[b^2 - c^2] + b*Cosh[x] + c*Sinh[x]] + (2/5)*(c*Cosh[x] + b*Sinh[x])*(Sqrt[b^2 - c^2] + b*Cosh[x] + c*Sinh[x])^(3/2)}
{(Sqrt[b^2 - c^2] + b*Cosh[x] + c*Sinh[x])^(3/2), x, 2, (8*Sqrt[b^2 - c^2]*(c*Cosh[x] + b*Sinh[x]))/(3*Sqrt[Sqrt[b^2 - c^2] + b*Cosh[x] + c*Sinh[x]]) + (2/3)*(c*Cosh[x] + b*Sinh[x])*Sqrt[Sqrt[b^2 - c^2] + b*Cosh[x] + c*Sinh[x]]}
{(Sqrt[b^2 - c^2] + b*Cosh[x] + c*Sinh[x])^(1/2), x, 1, (2*(c*Cosh[x] + b*Sinh[x]))/Sqrt[Sqrt[b^2 - c^2] + b*Cosh[x] + c*Sinh[x]]}
(* {1/(Sqrt[b^2 - c^2] + b*Cosh[x] + c*Sinh[x])^(1/2), x, 0, 0}
{1/(Sqrt[b^2 - c^2] + b*Cosh[x] + c*Sinh[x])^(3/2), x, 0, 0}
{1/(Sqrt[b^2 - c^2] + b*Cosh[x] + c*Sinh[x])^(5/2), x, 0, 0} *)

{(-Sqrt[b^2 - c^2] + b*Cosh[x] + c*Sinh[x])^(5/2), x, 3, (64*(b^2 - c^2)*(c*Cosh[x] + b*Sinh[x]))/(15*Sqrt[-Sqrt[b^2 - c^2] + b*Cosh[x] + c*Sinh[x]]) - (16/15)*Sqrt[b^2 - c^2]*(c*Cosh[x] + b*Sinh[x])*Sqrt[-Sqrt[b^2 - c^2] + b*Cosh[x] + c*Sinh[x]] + (2/5)*(c*Cosh[x] + b*Sinh[x])*(-Sqrt[b^2 - c^2] + b*Cosh[x] + c*Sinh[x])^(3/2)}
{(-Sqrt[b^2 - c^2] + b*Cosh[x] + c*Sinh[x])^(3/2), x, 2, -((8*Sqrt[b^2 - c^2]*(c*Cosh[x] + b*Sinh[x]))/(3*Sqrt[-Sqrt[b^2 - c^2] + b*Cosh[x] + c*Sinh[x]])) + (2/3)*(c*Cosh[x] + b*Sinh[x])*Sqrt[-Sqrt[b^2 - c^2] + b*Cosh[x] + c*Sinh[x]]}
{(-Sqrt[b^2 - c^2] + b*Cosh[x] + c*Sinh[x])^(1/2), x, 1, (2*(c*Cosh[x] + b*Sinh[x]))/Sqrt[-Sqrt[b^2 - c^2] + b*Cosh[x] + c*Sinh[x]]}
{1/(-Sqrt[b^2 - c^2] + b*Cosh[x] + c*Sinh[x])^(1/2), x, 1, (I*Sqrt[2]*EllipticF[(1/4)*(Pi - 2*I*(x + I*ArcTan[I*c, b])), 1]*Sqrt[(Sqrt[b^2 - c^2] - b*Cosh[x] - c*Sinh[x])/Sqrt[b^2 - c^2]])/Sqrt[-Sqrt[b^2 - c^2] + b*Cosh[x] + c*Sinh[x]]}
{1/(-Sqrt[b^2 - c^2] + b*Cosh[x] + c*Sinh[x])^(3/2), x, 2, -((c*Cosh[x] + b*Sinh[x])/(2*Sqrt[b^2 - c^2]*(-Sqrt[b^2 - c^2] + b*Cosh[x] + c*Sinh[x])^(3/2))) - (I*EllipticF[(1/4)*(Pi - 2*I*(x + I*ArcTan[I*c, b])), 1]*Sqrt[(Sqrt[b^2 - c^2] - b*Cosh[x] - c*Sinh[x])/Sqrt[b^2 - c^2]])/(2*Sqrt[2]*Sqrt[b^2 - c^2]*Sqrt[-Sqrt[b^2 - c^2] + b*Cosh[x] + c*Sinh[x]])}
{1/(-Sqrt[b^2 - c^2] + b*Cosh[x] + c*Sinh[x])^(5/2), x, 3, -((c*Cosh[x] + b*Sinh[x])/(4*Sqrt[b^2 - c^2]*(-Sqrt[b^2 - c^2] + b*Cosh[x] + c*Sinh[x])^(5/2))) + (3*(c*Cosh[x] + b*Sinh[x]))/(16*(b^2 - c^2)*(-Sqrt[b^2 - c^2] + b*Cosh[x] + c*Sinh[x])^(3/2)) + (3*I*EllipticF[(1/4)*(Pi - 2*I*(x + I*ArcTan[I*c, b])), 1]*Sqrt[(Sqrt[b^2 - c^2] - b*Cosh[x] - c*Sinh[x])/Sqrt[b^2 - c^2]])/(16*Sqrt[2]*(b^2 - c^2)*Sqrt[-Sqrt[b^2 - c^2] + b*Cosh[x] + c*Sinh[x]])}


(* ::Subsubsection::Closed:: *)
(*Integrands of the form (a + b Tanh[d+e x] + c Sech[d+e x])^n*)


{1/(a + b*Tanh[x] + c*Sech[x]), x, -8, (a*x)/(a^2 - b^2) - (2*a*c*ArcTan[(b + (a - c)*Tanh[x/2])/Sqrt[a^2 - b^2 - c^2]])/((a^2 - b^2)*Sqrt[a^2 - b^2 - c^2]) - (b*Log[c + a*Cosh[x] + b*Sinh[x]])/(a^2 - b^2)}
{1/(a + b*Coth[x] + c*Csch[x]), x, -8, (a*x)/(a^2 - b^2) - (2*a*c*ArcTan[(a + (b - c)*Tanh[x/2])/Sqrt[-a^2 + b^2 - c^2]])/((a^2 - b^2)*Sqrt[-a^2 + b^2 - c^2]) - (b*Log[c + b*Cosh[x] + a*Sinh[x]])/(a^2 - b^2)}


(* ::Subsection::Closed:: *)
(*Miscellaneous integrands involving two hyperbolic functions*)


{1/(a + b*Sinh[x]*Cosh[x]), x, 2, -((2*ArcTanh[(b - 2*a*Tanh[x])/Sqrt[4*a^2 + b^2]])/Sqrt[4*a^2 + b^2])}
{x/(a + b*Sinh[x]*Cosh[x]), x, 9, (x*Log[1 + (b*E^(2*x))/(2*a - Sqrt[4*a^2 + b^2])])/Sqrt[4*a^2 + b^2] - (x*Log[1 + (b*E^(2*x))/(2*a + Sqrt[4*a^2 + b^2])])/Sqrt[4*a^2 + b^2] + PolyLog[2, -((b*E^(2*x))/(2*a - Sqrt[4*a^2 + b^2]))]/(2*Sqrt[4*a^2 + b^2]) - PolyLog[2, -((b*E^(2*x))/(2*a + Sqrt[4*a^2 + b^2]))]/(2*Sqrt[4*a^2 + b^2])}
{x^2/(a + b*Sinh[x]*Cosh[x]), x, 11, (x^2*Log[1 + (b*E^(2*x))/(2*a - Sqrt[4*a^2 + b^2])])/Sqrt[4*a^2 + b^2] - (x^2*Log[1 + (b*E^(2*x))/(2*a + Sqrt[4*a^2 + b^2])])/Sqrt[4*a^2 + b^2] + (x*PolyLog[2, -((b*E^(2*x))/(2*a - Sqrt[4*a^2 + b^2]))])/Sqrt[4*a^2 + b^2] - (x*PolyLog[2, -((b*E^(2*x))/(2*a + Sqrt[4*a^2 + b^2]))])/Sqrt[4*a^2 + b^2] - PolyLog[3, -((b*E^(2*x))/(2*a - Sqrt[4*a^2 + b^2]))]/(2*Sqrt[4*a^2 + b^2]) + PolyLog[3, -((b*E^(2*x))/(2*a + Sqrt[4*a^2 + b^2]))]/(2*Sqrt[4*a^2 + b^2])}
{x^3/(a + b*Sinh[x]*Cosh[x]), x, 13, (x^3*Log[1 + (b*E^(2*x))/(2*a - Sqrt[4*a^2 + b^2])])/Sqrt[4*a^2 + b^2] - (x^3*Log[1 + (b*E^(2*x))/(2*a + Sqrt[4*a^2 + b^2])])/Sqrt[4*a^2 + b^2] + (3*x^2*PolyLog[2, -((b*E^(2*x))/(2*a - Sqrt[4*a^2 + b^2]))])/(2*Sqrt[4*a^2 + b^2]) - (3*x^2*PolyLog[2, -((b*E^(2*x))/(2*a + Sqrt[4*a^2 + b^2]))])/(2*Sqrt[4*a^2 + b^2]) - (3*x*PolyLog[3, -((b*E^(2*x))/(2*a - Sqrt[4*a^2 + b^2]))])/(2*Sqrt[4*a^2 + b^2]) + (3*x*PolyLog[3, -((b*E^(2*x))/(2*a + Sqrt[4*a^2 + b^2]))])/(2*Sqrt[4*a^2 + b^2]) + (3*PolyLog[4, -((b*E^(2*x))/(2*a - Sqrt[4*a^2 + b^2]))])/(4*Sqrt[4*a^2 + b^2]) - (3*PolyLog[4, -((b*E^(2*x))/(2*a + Sqrt[4*a^2 + b^2]))])/(4*Sqrt[4*a^2 + b^2])}


{Sqrt[a + b*Sinh[x]*Cosh[x]], x, 3, (I*EllipticE[Pi/4 - I*x, -((2*I*b)/(2*a - I*b))]*Sqrt[2*a + b*Sinh[2*x]])/(Sqrt[2]*Sqrt[(2*a + b*Sinh[2*x])/(2*a - I*b)])}
{1/Sqrt[a + b*Sinh[x]*Cosh[x]], x, 3, (I*Sqrt[2]*EllipticF[Pi/4 - I*x, -((2*I*b)/(2*a - I*b))]*Sqrt[(2*a + b*Sinh[2*x])/(2*a - I*b)])/Sqrt[2*a + b*Sinh[2*x]]}


(* Integrands of the form x*Cosh[2*x]*Sech[x]^n where n is an integer *)
{x*Cosh[2*x]*Sech[x], x, -1, -2*Cosh[x] + I*x*Log[1 - I/E^x] - I*x*Log[1 + I/E^x] + I*PolyLog[2, -I/E^x] - I*PolyLog[2, I/E^x] + 2*x*Sinh[x]}
{x*Cosh[2*x]*Sech[x]^2, x, 7, x^2+Log[Cosh[x]]-x*Tanh[x]}
{x*Cosh[2*x]*Sech[x]^3, x, -1, 3*x*ArcTan[E^x] - (3/2)*I*PolyLog[2, (-I)*E^x] + (3/2)*I*PolyLog[2, I*E^x] - Sech[x]/2 - (1/2)*x*Sech[x]*Tanh[x]}


(* Integrands of the form Hyper[x]^2/(a+b*Hyper[2*x]) *)
{Sinh[x]^2/(a + b*Sinh[2*x]), x, 4, ArcTanh[(b - a*Tanh[x])/Sqrt[a^2 + b^2]]/(2*Sqrt[a^2 + b^2]) + Log[a + b*Sinh[2*x]]/(4*b)}
{Cosh[x]^2/(a + b*Sinh[2*x]), x, 4, -(ArcTanh[(b - a*Tanh[x])/Sqrt[a^2 + b^2]]/(2*Sqrt[a^2 + b^2])) + Log[a + b*Sinh[2*x]]/(4*b)}

{Sinh[x]^2/(a + b*Cosh[2*x]), x, 4, x/(2*b) - ArcTanh[((a - b)*Tanh[x])/Sqrt[a^2 - b^2]]/(2*Sqrt[a^2 - b^2]) - (a*ArcTanh[((a - b)*Tanh[x])/Sqrt[a^2 - b^2]])/(2*b*Sqrt[a^2 - b^2])}
{Cosh[x]^2/(a + b*Cosh[2*x]), x, 4, x/(2*b) + ArcTanh[((a - b)*Tanh[x])/Sqrt[a^2 - b^2]]/(2*Sqrt[a^2 - b^2]) - (a*ArcTanh[((a - b)*Tanh[x])/Sqrt[a^2 - b^2]])/(2*b*Sqrt[a^2 - b^2])}


{Tanh[c+d*x]/Sqrt[a*Sinh[c+d*x]^2], x, 2, (ArcTan[Sinh[c + d*x]]*Sinh[c + d*x])/(d*Sqrt[a*Sinh[c + d*x]^2])}
{Coth[c+d*x]/Sqrt[a*Cosh[c+d*x]^2], x, 2, -((ArcCoth[Cosh[c + d*x]]*Cosh[c + d*x])/(d*Sqrt[a*Cosh[c + d*x]^2]))}


{(Sech[Sqrt[x]]*Tanh[Sqrt[x]])/Sqrt[x], x, 2, -2*Sech[Sqrt[x]]}


{Sqrt[Csch[x]]*(x*Cosh[x] - 4*Sech[x]*Tanh[x]), x, 10, (2*x)/Sqrt[Csch[x]] - (4*Sech[x])/Csch[x]^(3/2)}
