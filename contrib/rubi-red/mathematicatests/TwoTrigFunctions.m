(* ::Package:: *)

(* ::Title:: *)
(*Integration Problems Involving Two Trig Functions*)


(* ::Subsection::Closed:: *)
(*Integrands of the form Trig[a+b x]^m Trig[a+b x]^n*)


(* ::Subsubsection::Closed:: *)
(*Integrands of the form Cos[a+b x]^m Sin[a+b x]^n*)


(* Integrands of the form Cos[a+b*x]^m*Sin[a+b*x]^n *)
{Cos[a + b*x]*Sin[a + b*x], x, 2, Sin[a + b*x]^2/(2*b)}
{Cos[a + b*x]*Sin[a + b*x]^n, x, 2, Sin[a + b*x]^(1 + n)/(b*(1 + n))}
{Cos[a + b*x]^3*Sin[a + b*x]^n, x, 3, Sin[a + b*x]^(1 + n)/(b*(1 + n)) - Sin[a + b*x]^(3 + n)/(b*(3 + n))}
{Cos[a + b*x]^5*Sin[a + b*x]^n, x, 3, Sin[a + b*x]^(1 + n)/(b*(1 + n)) - (2*Sin[a + b*x]^(3 + n))/(b*(3 + n)) + Sin[a + b*x]^(5 + n)/(b*(5 + n))}

{Cos[a + b*x]^m*Sin[a + b*x], x, 2, -(Cos[a + b*x]^(1 + m)/(b*(1 + m)))}
{Cos[a + b*x]^m*Sin[a + b*x]^3, x, 3, -(Cos[a + b*x]^(1 + m)/(b*(1 + m))) + Cos[a + b*x]^(3 + m)/(b*(3 + m))}
{Cos[a + b*x]^m*Sin[a + b*x]^5, x, 3, -(Cos[a + b*x]^(1 + m)/(b*(1 + m))) + (2*Cos[a + b*x]^(3 + m))/(b*(3 + m)) - Cos[a + b*x]^(5 + m)/(b*(5 + m))}

{Cos[a + b*x]^2*Sin[a + b*x]^2, x, 2, x/8 + (Cos[a + b*x]*Sin[a + b*x])/(8*b) - (Cos[a + b*x]^3*Sin[a + b*x])/(4*b)}
{Cos[a + b*x]^2*Sin[a + b*x]^4, x, 3, x/16 + (Cos[a + b*x]*Sin[a + b*x])/(16*b) - (Cos[a + b*x]^3*Sin[a + b*x])/(8*b) - (Cos[a + b*x]^3*Sin[a + b*x]^3)/(6*b)}
{Cos[a + b*x]^2*Sin[a + b*x]^6, x, 4, (5*x)/128 + (5*Cos[a + b*x]*Sin[a + b*x])/(128*b) - (5*Cos[a + b*x]^3*Sin[a + b*x])/(64*b) - (5*Cos[a + b*x]^3*Sin[a + b*x]^3)/(48*b) - (Cos[a + b*x]^3*Sin[a + b*x]^5)/(8*b)}

{Sin[a + b*x]^3*Cos[a + b*x]^3, x, 3, Sin[a + b*x]^4/(4*b) - Sin[a + b*x]^6/(6*b)}

{Cos[a + b*x]^4*Sin[a + b*x]^2, x, 3, x/16 + (Cos[a + b*x]*Sin[a + b*x])/(16*b) + (Cos[a + b*x]^3*Sin[a + b*x])/(24*b) - (Cos[a + b*x]^5*Sin[a + b*x])/(6*b)}
{Cos[a + b*x]^4*Sin[a + b*x]^4, x, 4, (3*x)/128 + (3*Cos[a + b*x]*Sin[a + b*x])/(128*b) + (Cos[a + b*x]^3*Sin[a + b*x])/(64*b) - (Cos[a + b*x]^5*Sin[a + b*x])/(16*b) - (Cos[a + b*x]^5*Sin[a + b*x]^3)/(8*b)}
{Cos[a + b*x]^4*Sin[a + b*x]^6, x, 5, (3*x)/256 + (3*Cos[a + b*x]*Sin[a + b*x])/(256*b) + (Cos[a + b*x]^3*Sin[a + b*x])/(128*b) - (Cos[a + b*x]^5*Sin[a + b*x])/(32*b) - (Cos[a + b*x]^5*Sin[a + b*x]^3)/(16*b) - (Cos[a + b*x]^5*Sin[a + b*x]^5)/(10*b)}

{Cos[a + b*x]^6*Sin[a + b*x]^2, x, 4, (5*x)/128 + (5*Cos[a + b*x]*Sin[a + b*x])/(128*b) + (5*Cos[a + b*x]^3*Sin[a + b*x])/(192*b) + (Cos[a + b*x]^5*Sin[a + b*x])/(48*b) - (Cos[a + b*x]^7*Sin[a + b*x])/(8*b)}
{Cos[a + b*x]^6*Sin[a + b*x]^4, x, 5, (3*x)/256 + (3*Cos[a + b*x]*Sin[a + b*x])/(256*b) + (Cos[a + b*x]^3*Sin[a + b*x])/(128*b) + (Cos[a + b*x]^5*Sin[a + b*x])/(160*b) - (3*Cos[a + b*x]^7*Sin[a + b*x])/(80*b) - (Cos[a + b*x]^7*Sin[a + b*x]^3)/(10*b)}
{Cos[a + b*x]^6*Sin[a + b*x]^6, x, 6, (5*x)/1024 + (5*Cos[a + b*x]*Sin[a + b*x])/(1024*b) + (5*Cos[a + b*x]^3*Sin[a + b*x])/(1536*b) + (Cos[a + b*x]^5*Sin[a + b*x])/(384*b) - (Cos[a + b*x]^7*Sin[a + b*x])/(64*b) - (Cos[a + b*x]^7*Sin[a + b*x]^3)/(24*b) - (Cos[a + b*x]^7*Sin[a + b*x]^5)/(12*b)}


(* Integrands of the form Csc[a+b*x]^m*Sec[a+b*x]^n where m and n are positive integers *)
{Csc[a + b*x]*Sec[a + b*x], x, 1, Log[Tan[a + b*x]]/b}
{Csc[a + b*x]*Sec[a + b*x]^2, x, 2, -(ArcTanh[Cos[a + b*x]]/b) + Sec[a + b*x]/b}
{Csc[a + b*x]*Sec[a + b*x]^3, x, 3, Log[Tan[a + b*x]]/b + Tan[a + b*x]^2/(2*b)}
{Csc[a + b*x]*Sec[a + b*x]^4, x, 3, -(ArcTanh[Cos[a + b*x]]/b) + Sec[a + b*x]/b + Sec[a + b*x]^3/(3*b)}
{Csc[a + b*x]*Sec[a + b*x]^5, x, 3, Log[Tan[a + b*x]]/b + Tan[a + b*x]^2/b + Tan[a + b*x]^4/(4*b)}

{Csc[a + b*x]^2*Sec[a + b*x], x, 2, ArcTanh[Sin[a + b*x]]/b - Csc[a + b*x]/b}
{Csc[a + b*x]^2*Sec[a + b*x]^2, x, 3, -(Cot[a + b*x]/b) + Tan[a + b*x]/b}
{Csc[a + b*x]^2*Sec[a + b*x]^3, x, 3, (3*ArcTanh[Sin[a + b*x]])/(2*b) - (3*Csc[a + b*x])/(2*b) + (Csc[a + b*x]*Sec[a + b*x]^2)/(2*b)}
{Csc[a + b*x]^2*Sec[a + b*x]^4, x, 3, -(Cot[a + b*x]/b) + (2*Tan[a + b*x])/b + Tan[a + b*x]^3/(3*b)}
{Csc[a + b*x]^2*Sec[a + b*x]^5, x, 4, (15*ArcTanh[Sin[a + b*x]])/(8*b) - (15*Csc[a + b*x])/(8*b) + (5*Csc[a + b*x]*Sec[a + b*x]^2)/(8*b) + (Csc[a + b*x]*Sec[a + b*x]^4)/(4*b)}

{Csc[a + b*x]^3*Sec[a + b*x], x, 3, -(Cot[a + b*x]^2/(2*b)) - Log[Cot[a + b*x]]/b}
{Csc[a + b*x]^3*Sec[a + b*x]^2, x, 3, -((3*ArcTanh[Cos[a + b*x]])/(2*b)) + (3*Sec[a + b*x])/(2*b) - (Csc[a + b*x]^2*Sec[a + b*x])/(2*b)}
{Csc[a + b*x]^3*Sec[a + b*x]^3, x, 3, -(Cot[a + b*x]^2/(2*b)) + (2*Log[Tan[a + b*x]])/b + Tan[a + b*x]^2/(2*b)}
{Csc[a + b*x]^3*Sec[a + b*x]^4, x, 4, -((5*ArcTanh[Cos[a + b*x]])/(2*b)) + (5*Sec[a + b*x])/(2*b) + (5*Sec[a + b*x]^3)/(6*b) - (Csc[a + b*x]^2*Sec[a + b*x]^3)/(2*b)}
{Csc[a + b*x]^3*Sec[a + b*x]^5, x, 3, -(Cot[a + b*x]^2/(2*b)) + (3*Log[Tan[a + b*x]])/b + (3*Tan[a + b*x]^2)/(2*b) + Tan[a + b*x]^4/(4*b)}

{Csc[a + b*x]^4*Sec[a + b*x], x, 3, ArcTanh[Sin[a + b*x]]/b - Csc[a + b*x]/b - Csc[a + b*x]^3/(3*b)}
{Csc[a + b*x]^4*Sec[a + b*x]^2, x, 3, -((2*Cot[a + b*x])/b) - Cot[a + b*x]^3/(3*b) + Tan[a + b*x]/b}
{Csc[a + b*x]^4*Sec[a + b*x]^3, x, 4, (5*ArcTanh[Sin[a + b*x]])/(2*b) - (5*Csc[a + b*x])/(2*b) - (5*Csc[a + b*x]^3)/(6*b) + (Csc[a + b*x]^3*Sec[a + b*x]^2)/(2*b)}
{Csc[a + b*x]^4*Sec[a + b*x]^4, x, 3, -((3*Cot[a + b*x])/b) - Cot[a + b*x]^3/(3*b) + (3*Tan[a + b*x])/b + Tan[a + b*x]^3/(3*b)}
{Csc[a + b*x]^4*Sec[a + b*x]^5, x, 5, (35*ArcTanh[Sin[a + b*x]])/(8*b) - (35*Csc[a + b*x])/(8*b) - (35*Csc[a + b*x]^3)/(24*b) + (7*Csc[a + b*x]^3*Sec[a + b*x]^2)/(8*b) + (Csc[a + b*x]^3*Sec[a + b*x]^4)/(4*b)}

{Csc[a + b*x]^5*Sec[a + b*x], x, 3, -(Cot[a + b*x]^2/b) - Cot[a + b*x]^4/(4*b) - Log[Cot[a + b*x]]/b}
{Csc[a + b*x]^5*Sec[a + b*x]^2, x, 4, -((15*ArcTanh[Cos[a + b*x]])/(8*b)) + (15*Sec[a + b*x])/(8*b) - (5*Csc[a + b*x]^2*Sec[a + b*x])/(8*b) - (Csc[a + b*x]^4*Sec[a + b*x])/(4*b)}
{Csc[a + b*x]^5*Sec[a + b*x]^3, x, 3, -((3*Cot[a + b*x]^2)/(2*b)) - Cot[a + b*x]^4/(4*b) - (3*Log[Cot[a + b*x]])/b + Tan[a + b*x]^2/(2*b)}
{Csc[a + b*x]^5*Sec[a + b*x]^4, x, 5, -((35*ArcTanh[Cos[a + b*x]])/(8*b)) + (35*Sec[a + b*x])/(8*b) + (35*Sec[a + b*x]^3)/(24*b) - (7*Csc[a + b*x]^2*Sec[a + b*x]^3)/(8*b) - (Csc[a + b*x]^4*Sec[a + b*x]^3)/(4*b)}
{Csc[a + b*x]^5*Sec[a + b*x]^5, x, 3, -((2*Cot[a + b*x]^2)/b) - Cot[a + b*x]^4/(4*b) + (6*Log[Tan[a + b*x]])/b + (2*Tan[a + b*x]^2)/b + Tan[a + b*x]^4/(4*b)}


{Sin[x]^(3/2)/Cos[x]^(7/2), x, 1, (2*Sin[x]^(5/2))/(5*Cos[x]^(5/2))}
{Cos[x]^(2/3)/Sin[x]^(8/3), x, 1, (-3*Cos[x]^(5/3))/(5*Sin[x]^(5/3))}
{Sin[x]^(2/3)/Cos[x]^(8/3), x, 1, (3*Sin[x]^(5/3))/(5*Cos[x]^(5/3))}
{Sqrt[Sin[x]]/Sqrt[Cos[x]], x, 6, -(ArcTan[1 - (Sqrt[2]*Sqrt[Sin[x]])/Sqrt[Cos[x]]]/Sqrt[2]) + ArcTan[1 + (Sqrt[2]*Sqrt[Sin[x]])/Sqrt[Cos[x]]]/Sqrt[2] + Log[1 - (Sqrt[2]*Sqrt[Sin[x]])/Sqrt[Cos[x]] + Tan[x]]/(2*Sqrt[2]) - Log[1 + (Sqrt[2]*Sqrt[Sin[x]])/Sqrt[Cos[x]] + Tan[x]]/(2*Sqrt[2])}
{Sin[x]^(5/2)/Sqrt[Cos[x]], x, 7, -((3*ArcTan[1 - (Sqrt[2]*Sqrt[Sin[x]])/Sqrt[Cos[x]]])/(4*Sqrt[2])) + (3*ArcTan[1 + (Sqrt[2]*Sqrt[Sin[x]])/Sqrt[Cos[x]]])/(4*Sqrt[2]) + (3*Log[1 - (Sqrt[2]*Sqrt[Sin[x]])/Sqrt[Cos[x]] + Tan[x]])/(8*Sqrt[2]) - (3*Log[1 + (Sqrt[2]*Sqrt[Sin[x]])/Sqrt[Cos[x]] + Tan[x]])/(8*Sqrt[2]) - (1/2)*Sqrt[Cos[x]]*Sin[x]^(3/2)}


{Sec[x]^(3/2)*Sin[x], x, 2, 2*Sqrt[Sec[x]]}
{Sec[x]^(5/2)*Sin[x], x, 2, (2*Sec[x]^(3/2))/3}
{Sqrt[Cos[3*x]]*Sin[3*x], x, 2, (-2*Cos[3*x]^(3/2))/9}
{Cos[x]^(1/5)*Sin[x], x, 2, (-5*Cos[x]^(6/5))/6}

{Sqrt[Cos[x]]*Sin[x]^3, x, 3, (-(2/3))*Cos[x]^(3/2) + (2/7)*Cos[x]^(7/2)}
{Sin[x]^3/Sqrt[Cos[x]], x, 3, -2*Sqrt[Cos[x]] + (2/5)*Cos[x]^(5/2)}
{Sec[x]^(5/2)*Sin[x]^3, x, 5, 2/Sqrt[Sec[x]] + (2/3)*Sec[x]^(3/2)}
{Sec[x]^(9/2)*Sin[x]^3, x, 5, (-(2/3))*Sec[x]^(3/2) + (2/7)*Sec[x]^(7/2)}

{Cos[2*x]^(3/2)*Sin[2*x]^5, x, 3, (-(1/5))*Cos[2*x]^(5/2) + (2/9)*Cos[2*x]^(9/2) - (1/13)*Cos[2*x]^(13/2)}


{Sqrt[Sin[a + b*x]]/Sqrt[Cos[a + b*x]], x, 6, -(ArcTan[1 - (Sqrt[2]*Sqrt[Sin[a + b*x]])/Sqrt[Cos[a + b*x]]]/(Sqrt[2]*b)) + ArcTan[1 + (Sqrt[2]*Sqrt[Sin[a + b*x]])/Sqrt[Cos[a + b*x]]]/(Sqrt[2]*b) + Log[1 - (Sqrt[2]*Sqrt[Sin[a + b*x]])/Sqrt[Cos[a + b*x]] + Tan[a + b*x]]/(2*Sqrt[2]*b) - Log[1 + (Sqrt[2]*Sqrt[Sin[a + b*x]])/Sqrt[Cos[a + b*x]] + Tan[a + b*x]]/(2*Sqrt[2]*b)}
{Sqrt[Cos[a + b*x]]/Sqrt[Sin[a + b*x]], x, 6, ArcTan[1 - (Sqrt[2]*Sqrt[Cos[a + b*x]])/Sqrt[Sin[a + b*x]]]/(Sqrt[2]*b) - ArcTan[1 + (Sqrt[2]*Sqrt[Cos[a + b*x]])/Sqrt[Sin[a + b*x]]]/(Sqrt[2]*b) - Log[1 + Cot[a + b*x] - (Sqrt[2]*Sqrt[Cos[a + b*x]])/Sqrt[Sin[a + b*x]]]/(2*Sqrt[2]*b) + Log[1 + Cot[a + b*x] + (Sqrt[2]*Sqrt[Cos[a + b*x]])/Sqrt[Sin[a + b*x]]]/(2*Sqrt[2]*b)}

{Sin[a + b*x]^(1/3)/Cos[a + b*x]^(1/3), x, 6, -((Sqrt[3]*ArcTan[(1 - (2*Sin[a + b*x]^(2/3))/Cos[a + b*x]^(2/3))/Sqrt[3]])/(2*b)) - Log[1 + Sin[a + b*x]^(2/3)/Cos[a + b*x]^(2/3)]/(2*b) + Log[1 - Sin[a + b*x]^(2/3)/Cos[a + b*x]^(2/3) + Sin[a + b*x]^(4/3)/Cos[a + b*x]^(4/3)]/(4*b)}
{Cos[a + b*x]^(1/3)/Sin[a + b*x]^(1/3), x, 6, (Sqrt[3]*ArcTan[(1 - (2*Cos[a + b*x]^(2/3))/Sin[a + b*x]^(2/3))/Sqrt[3]])/(2*b) - Log[1 + Cos[a + b*x]^(4/3)/Sin[a + b*x]^(4/3) - Cos[a + b*x]^(2/3)/Sin[a + b*x]^(2/3)]/(4*b) + Log[1 + Cos[a + b*x]^(2/3)/Sin[a + b*x]^(2/3)]/(2*b)}


(* ::Subsubsection::Closed:: *)
(*Integrands of the form Trig[a+b x]^m Tan[a+b x]^n*)


(* Integrands of the form Sin[a+b*x]^m*Tan[a+b*x]^n where m and n are positive integers *)
{Sin[a + b*x]*Tan[a + b*x], x, 2, ArcTanh[Sin[a + b*x]]/b - Sin[a + b*x]/b}
{Sin[a + b*x]*Tan[a + b*x]^2, x, 3, Cos[a + b*x]/b + Sec[a + b*x]/b}
{Sin[a + b*x]*Tan[a + b*x]^3, x, 3, -((3*ArcTanh[Sin[a + b*x]])/(2*b)) + (3*Sin[a + b*x])/(2*b) + (Sin[a + b*x]*Tan[a + b*x]^2)/(2*b)}
{Sin[a + b*x]*Tan[a + b*x]^4, x, 3, -(Cos[a + b*x]/b) - (2*Sec[a + b*x])/b + Sec[a + b*x]^3/(3*b)}

{Sin[a + b*x]^2*Tan[a + b*x], x, 3, Cos[a + b*x]^2/(2*b) - Log[Cos[a + b*x]]/b}
{Sin[a + b*x]^2*Tan[a + b*x]^2, x, 2, -((3*x)/2) + (3*Tan[a + b*x])/(2*b) - (Sin[a + b*x]^2*Tan[a + b*x])/(2*b)}
{Sin[a + b*x]^2*Tan[a + b*x]^3, x, 3, -(Cos[a + b*x]^2/(2*b)) + (2*Log[Cos[a + b*x]])/b + Sec[a + b*x]^2/(2*b)}

{Sin[a + b*x]^3*Tan[a + b*x], x, 3, ArcTanh[Sin[a + b*x]]/b - Sin[a + b*x]/b - Sin[a + b*x]^3/(3*b)}
{Sin[a + b*x]^3*Tan[a + b*x]^2, x, 3, (2*Cos[a + b*x])/b - Cos[a + b*x]^3/(3*b) + Sec[a + b*x]/b}
{Sin[a + b*x]^3*Tan[a + b*x]^3, x, 4, -((5*ArcTanh[Sin[a + b*x]])/(2*b)) + (5*Sin[a + b*x])/(2*b) + (5*Sin[a + b*x]*Tan[a + b*x]^2)/(6*b) - (Sin[a + b*x]^3*Tan[a + b*x]^2)/(3*b)}

{Sin[a + b*x]^4*Tan[a + b*x], x, 3, Cos[a + b*x]^2/b - Cos[a + b*x]^4/(4*b) - Log[Cos[a + b*x]]/b}


(* Integrands of the form Sec[a+b*x]^m*Tan[a+b*x]^n where m and n are positive integers *)
{Sec[a + b*x]*Tan[a + b*x], x, 1, Sec[a + b*x]/b}
{Sec[a + b*x]^2*Tan[a + b*x], x, 1, Sec[a + b*x]^2/(2*b)}
{Sec[a + b*x]^m*Tan[a + b*x], x, 2, Sec[a + b*x]^m/(b*m)}

{Sec[a + b*x]^2*Tan[a + b*x]^2, x, 2, Tan[a + b*x]^3/(3*b)}
{Sec[a + b*x]^2*Tan[a + b*x]^3, x, 2, Tan[a + b*x]^4/(4*b)}
{Sec[a + b*x]^2*Tan[a + b*x]^n, x, 2, Tan[a + b*x]^(1 + n)/(b*(1 + n))}

{Sec[a + b*x]*Tan[a + b*x]^3, x, 2, -(Sec[a + b*x]/b) + Sec[a + b*x]^3/(3*b)}
{Sec[a + b*x]^3*Tan[a + b*x]^3, x, 3, -(Sec[a + b*x]^3/(3*b)) + Sec[a + b*x]^5/(5*b)}
{Sec[a + b*x]^n*Tan[a + b*x]^3, x, 6, -(Sec[a + b*x]^n/(b*n)) + Sec[a + b*x]^(2 + n)/(b*(2 + n))}

{Sec[a + b*x]^4*Tan[a + b*x], x, 1, Sec[a + b*x]^4/(4*b)}
{Sec[a + b*x]^4*Tan[a + b*x]^2, x, 3, Tan[a + b*x]^3/(3*b) + Tan[a + b*x]^5/(5*b)}
{Sec[a + b*x]^4*Tan[a + b*x]^n, x, 3, Tan[a + b*x]^(1 + n)/(b*(1 + n)) + Tan[a + b*x]^(3 + n)/(b*(3 + n))}

{Sec[x]^6*Tan[x], x, 1, Sec[x]^6/6}
{Sec[x]^6*Tan[x]^3, x, 3, (-(1/6))*Sec[x]^6 + Sec[x]^8/8}
{Sec[x]^6*Tan[x]^5, x, 3, Tan[x]^6/6 + Tan[x]^8/4 + Tan[x]^10/10}
{Sec[x]^6*Tan[x]^7, x, 3, Tan[x]^8/8 + Tan[x]^10/5 + Tan[x]^12/12}
{Sec[x]^6*Tan[x]^9, x, 3, Tan[x]^10/10 + Tan[x]^12/6 + Tan[x]^14/14}
{Sec[x]^6*Tan[x]^11, x, 3, Tan[x]^12/12 + Tan[x]^14/7 + Tan[x]^16/16}

{Sec[x]^8*Tan[x], x, 1, Sec[x]^8/8}
{Sec[x]^8*Tan[x]^3, x, 3, (-(1/8))*Sec[x]^8 + Sec[x]^10/10}
{Sec[x]^8*Tan[x]^5, x, 3, Sec[x]^8/8 - Sec[x]^10/5 + Sec[x]^12/12}
{Sec[x]^8*Tan[x]^7, x, 3, Tan[x]^8/8 + (3*Tan[x]^10)/10 + Tan[x]^12/4 + Tan[x]^14/14}
{Sec[x]^8*Tan[x]^9, x, 3, Tan[x]^10/10 + Tan[x]^12/4 + (3*Tan[x]^14)/14 + Tan[x]^16/16}
{Sec[x]^8*Tan[x]^11, x, 3, Tan[x]^12/12 + (3*Tan[x]^14)/14 + (3*Tan[x]^16)/16 + Tan[x]^18/18}

{Sec[a + b*x]*Tan[a + b*x]^2, x, 2, -(ArcTanh[Sin[a + b*x]]/(2*b)) + (Sec[a + b*x]*Tan[a + b*x])/(2*b)}
{Sec[a + b*x]*Tan[a + b*x]^4, x, 3, (3*ArcTanh[Sin[a + b*x]])/(8*b) - (3*Sec[a + b*x]*Tan[a + b*x])/(8*b) + (Sec[a + b*x]*Tan[a + b*x]^3)/(4*b)}

{Sec[a + b*x]^3*Tan[a + b*x]^2, x, 3, -(ArcTanh[Sin[a + b*x]]/(8*b)) + (Sec[a + b*x]*Tan[a + b*x])/(8*b) + (Sec[a + b*x]*Tan[a + b*x]^3)/(4*b)}

{Sec[x]*Tan[x]^3, x, 2, -Sec[x] + Sec[x]^3/3}
{Sec[x]*Tan[x]^5, x, 3, Sec[x] - (2*Sec[x]^3)/3 + Sec[x]^5/5}
{Sec[x/2]^3*Tan[x/2]^2, x, 3, (-(1/4))*ArcTanh[Sin[x/2]] + (1/4)*Sec[x/2]*Tan[x/2] + (1/2)*Sec[x/2]*Tan[x/2]^3}
{Sec[x]^3*Tan[x]^4, x, 4, (1/16)*ArcTanh[Sin[x]] - (1/16)*Sec[x]*Tan[x] + (1/24)*Sec[x]*Tan[x]^3 + (1/6)*Sec[x]*Tan[x]^5}
{Sec[x]^3*Tan[x]^5, x, 3, Sec[x]^3/3 - (2*Sec[x]^5)/5 + Sec[x]^7/7}
{Sec[x]^5*Tan[x]^2, x, 4, (-(1/16))*ArcTanh[Sin[x]] + (1/16)*Sec[x]*Tan[x] + (1/8)*Sec[x]*Tan[x]^3 + (1/6)*Sec[x]^3*Tan[x]^3}
{Sec[x]^7*Tan[x]^5, x, 3, Sec[x]^7/7 - (2*Sec[x]^9)/9 + Sec[x]^11/11}
{Sec[x]^8*Tan[x]^6, x, 3, Tan[x]^7/7 + Tan[x]^9/3 + (3*Tan[x]^11)/11 + Tan[x]^13/13}


{Sin[x]^(5/2)/Tan[x]^(3/2), x, 1, (-2*Sin[x]^(5/2))/(5*Tan[x]^(5/2))}


{Sec[a + b*x]^4*Sqrt[Tan[a + b*x]], x, 3, (2*Tan[a + b*x]^(3/2))/(3*b) + (2*Tan[a + b*x]^(7/2))/(7*b)}


(* ::Subsubsection::Closed:: *)
(*Integrands of the form Trig[a+b x]^m Cot[a+b x]^n*)


(* Integrands of the form Cos[a+b*x]^m*Cot[a+b*x]^n where m and n are positive integers *)
{Cos[a + b*x]*Cot[a + b*x], x, 2, -(ArcTanh[Cos[a + b*x]]/b) + Cos[a + b*x]/b}
{Cos[a + b*x]*Cot[a + b*x]^2, x, 3, -(Csc[a + b*x]/b) - Sin[a + b*x]/b}
{Cos[a + b*x]*Cot[a + b*x]^3, x, 3, (3*ArcTanh[Cos[a + b*x]])/(2*b) - (3*Cos[a + b*x])/(2*b) - (Cos[a + b*x]*Cot[a + b*x]^2)/(2*b)}
{Cos[a + b*x]*Cot[a + b*x]^4, x, 3, (2*Csc[a + b*x])/b - Csc[a + b*x]^3/(3*b) + Sin[a + b*x]/b}

{Cos[a + b*x]^2*Cot[a + b*x], x, 3, Log[Sin[a + b*x]]/b - Sin[a + b*x]^2/(2*b)}
{Cos[a + b*x]^2*Cot[a + b*x]^2, x, 2, -((3*x)/2) - (3*Cot[a + b*x])/(2*b) + (Cos[a + b*x]^2*Cot[a + b*x])/(2*b)}
{Cos[a + b*x]^2*Cot[a + b*x]^3, x, 3, -(Csc[a + b*x]^2/(2*b)) - (2*Log[Sin[a + b*x]])/b + Sin[a + b*x]^2/(2*b)}

{Cos[a + b*x]^3*Cot[a + b*x], x, 3, -(ArcTanh[Cos[a + b*x]]/b) + Cos[a + b*x]/b + Cos[a + b*x]^3/(3*b)}
{Cos[a + b*x]^3*Cot[a + b*x]^2, x, 3, -(Csc[a + b*x]/b) - (2*Sin[a + b*x])/b + Sin[a + b*x]^3/(3*b)}
{Cos[a + b*x]^3*Cot[a + b*x]^3, x, 4, (5*ArcTanh[Cos[a + b*x]])/(2*b) - (5*Cos[a + b*x])/(2*b) - (5*Cos[a + b*x]*Cot[a + b*x]^2)/(6*b) + (Cos[a + b*x]^3*Cot[a + b*x]^2)/(3*b)}

{Cos[a + b*x]^4*Cot[a + b*x], x, 3, Log[Sin[a + b*x]]/b - Sin[a + b*x]^2/b + Sin[a + b*x]^4/(4*b)}


(* Integrands of the form Cot[a+b*x]^m*Csc[a+b*x]^n where m and n are positive integers *)
{Cot[a + b*x]*Csc[a + b*x], x, 1, -(Csc[a + b*x]/b)}
{Cot[a + b*x]*Csc[a + b*x]^2, x, 1, -(Csc[a + b*x]^2/(2*b))}
{Cot[a + b*x]*Csc[a + b*x]^n, x, 2, -Csc[a + b*x]^n/(b*n)}

{Cot[a + b*x]^2*Csc[a + b*x]^2, x, 2, -Cot[a + b*x]^3/(3*b)}
{Cot[a + b*x]^3*Csc[a + b*x]^2, x, 2, -Cot[a + b*x]^4/(4*b)}
{Cot[a + b*x]^n*Csc[a + b*x]^2, x, 2, -Cot[a + b*x]^(1 + n)/(b*(1 + n))}

{Cot[a + b*x]^3*Csc[a + b*x], x, 2, Csc[a + b*x]/b - Csc[a + b*x]^3/(3*b)}
{Cot[a + b*x]^3*Csc[a + b*x]^3, x, 3, Csc[a + b*x]^3/(3*b) - Csc[a + b*x]^5/(5*b)}
{Cot[a + b*x]^3*Csc[a + b*x]^n, x, 6, Csc[a + b*x]^n/(b*n) - Csc[a + b*x]^(2 + n)/(b*(2 + n))}

{Cot[a + b*x]^2*Csc[a + b*x], x, 2, ArcTanh[Cos[a + b*x]]/(2*b) - (Cot[a + b*x]*Csc[a + b*x])/(2*b)}
{Cot[a + b*x]^2*Csc[a + b*x]^3, x, 3, ArcTanh[Cos[a + b*x]]/(8*b) - (Cot[a + b*x]*Csc[a + b*x])/(8*b) - (Cot[a + b*x]^3*Csc[a + b*x])/(4*b)}

{Cot[a + b*x]^4*Csc[a + b*x], x, 3, -((3*ArcTanh[Cos[a + b*x]])/(8*b)) + (3*Cot[a + b*x]*Csc[a + b*x])/(8*b) - (Cot[a + b*x]^3*Csc[a + b*x])/(4*b)}

{Cot[2*x]^3*Csc[2*x]^3, x, 3, (1/6)*Csc[2*x]^3 - (1/10)*Csc[2*x]^5}
{Cot[x]^3*Csc[x]^3, x, 3, Csc[x]^3/3 - Csc[x]^5/5}
{Cot[x]^3*Csc[x]^4, x, 3, (-(1/4))*Cot[x]^4 - Cot[x]^6/6}
{Cot[x]^4*Csc[x]^4, x, 3, (-(1/5))*Cot[x]^5 - Cot[x]^7/7}
{Cot[3*x]^4*Csc[3*x], x, 3, (-(1/8))*ArcTanh[Cos[3*x]] + (1/8)*Cot[3*x]*Csc[3*x] - (1/12)*Cot[3*x]^3*Csc[3*x]}
{Cot[x]^4*Csc[x]^3, x, 4, (-(1/16))*ArcTanh[Cos[x]] + (1/16)*Cot[x]*Csc[x] - (1/24)*Cot[x]^3*Csc[x] - (1/6)*Cot[x]^5*Csc[x]}
{Cot[x]^4*Csc[x]^6, x, 3, (-(1/5))*Cot[x]^5 - (2*Cot[x]^7)/7 - Cot[x]^9/9}
{Cot[6*x]^5*Csc[6*x], x, 3, (-(1/6))*Csc[6*x] + (1/9)*Csc[6*x]^3 - (1/30)*Csc[6*x]^5}


(* ::Subsection::Closed:: *)
(*Integrands of the form Trig[a+b x]^m Trig[2 a+2 b x]^n*)


(* ::Subsubsection::Closed:: *)
(*Integrands of the form Sin[a+b x]^m Sin[2 a+2 b x]^n*)


{Sin[a + b*x]*Sin[2*a + 2*b*x]^5, x, 4, (32*Sin[a + b*x]^7)/(7*b) - (64*Sin[a + b*x]^9)/(9*b) + (32*Sin[a + b*x]^11)/(11*b)}
{Sin[a + b*x]*Sin[2*a + 2*b*x]^4, x, 4, -((16*Cos[a + b*x]^5)/(5*b)) + (32*Cos[a + b*x]^7)/(7*b) - (16*Cos[a + b*x]^9)/(9*b)}
{Sin[a + b*x]*Sin[2*a + 2*b*x]^3, x, 4, (8*Sin[a + b*x]^5)/(5*b) - (8*Sin[a + b*x]^7)/(7*b)}
{Sin[a + b*x]*Sin[2*a + 2*b*x]^2, x, 4, -((4*Cos[a + b*x]^3)/(3*b)) + (4*Cos[a + b*x]^5)/(5*b)}
{Sin[a + b*x]*Sin[2*a + 2*b*x], x, 3, (2*Sin[a + b*x]^3)/(3*b)}
{Sin[a + b*x]/Sin[2*a + 2*b*x], x, 2, ArcTanh[Sin[a + b*x]]/(2*b)}
{Sin[a + b*x]/Sin[2*a + 2*b*x]^2, x, 3, -(ArcTanh[Cos[a + b*x]]/(4*b)) + Sec[a + b*x]/(4*b)}
{Sin[a + b*x]/Sin[2*a + 2*b*x]^3, x, 4, (3*ArcTanh[Sin[a + b*x]])/(16*b) - (3*Csc[a + b*x])/(16*b) + (Csc[a + b*x]*Sec[a + b*x]^2)/(16*b)}
{Sin[a + b*x]/Sin[2*a + 2*b*x]^4, x, 5, -((5*ArcTanh[Cos[a + b*x]])/(32*b)) + (5*Sec[a + b*x])/(32*b) + (5*Sec[a + b*x]^3)/(96*b) - (Csc[a + b*x]^2*Sec[a + b*x]^3)/(32*b)}
{Sin[a + b*x]/Sin[2*a + 2*b*x]^5, x, 6, (35*ArcTanh[Sin[a + b*x]])/(256*b) - (35*Csc[a + b*x])/(256*b) - (35*Csc[a + b*x]^3)/(768*b) + (7*Csc[a + b*x]^3*Sec[a + b*x]^2)/(256*b) + (Csc[a + b*x]^3*Sec[a + b*x]^4)/(128*b)}


{Sin[a + b*x]^2*Sin[2*a + 2*b*x]^5, x, 4, (4*Sin[a + b*x]^8)/b - (32*Sin[a + b*x]^10)/(5*b) + (8*Sin[a + b*x]^12)/(3*b)}
{Sin[a + b*x]^2*Sin[2*a + 2*b*x]^4, x, 5, (3*x)/16 - (3*Cos[2*a + 2*b*x]*Sin[2*a + 2*b*x])/(32*b) - (Cos[2*a + 2*b*x]*Sin[2*a + 2*b*x]^3)/(16*b) - Sin[2*a + 2*b*x]^5/(20*b)}
{Sin[a + b*x]^2*Sin[2*a + 2*b*x]^3, x, 4, (4*Sin[a + b*x]^6)/(3*b) - Sin[a + b*x]^8/b}
{Sin[a + b*x]^2*Sin[2*a + 2*b*x]^2, x, 4, x/4 - (Cos[2*a + 2*b*x]*Sin[2*a + 2*b*x])/(8*b) - Sin[2*a + 2*b*x]^3/(12*b)}
{Sin[a + b*x]^2*Sin[2*a + 2*b*x], x, 3, Sin[a + b*x]^4/(2*b)}
{Sin[a + b*x]^2/Sin[2*a + 2*b*x], x, 2, -(Log[Cos[a + b*x]]/(2*b))}
{Sin[a + b*x]^2/Sin[2*a + 2*b*x]^2, x, 2, Tan[a + b*x]/(4*b)}
{Sin[a + b*x]^2/Sin[2*a + 2*b*x]^3, x, 4, Log[Tan[a + b*x]]/(8*b) + Tan[a + b*x]^2/(16*b)}
{Sin[a + b*x]^2/Sin[2*a + 2*b*x]^4, x, 4, -(Cot[a + b*x]/(16*b)) + Tan[a + b*x]/(8*b) + Tan[a + b*x]^3/(48*b)}
{Sin[a + b*x]^2/Sin[2*a + 2*b*x]^5, x, 4, -(Cot[a + b*x]^2/(64*b)) + (3*Log[Tan[a + b*x]])/(32*b) + (3*Tan[a + b*x]^2)/(64*b) + Tan[a + b*x]^4/(128*b)}


{Sin[a + b*x]^3*Sin[2*a + 2*b*x]^5, x, 4, (32*Sin[a + b*x]^9)/(9*b) - (64*Sin[a + b*x]^11)/(11*b) + (32*Sin[a + b*x]^13)/(13*b)}
{Sin[a + b*x]^3*Sin[2*a + 2*b*x]^4, x, 4, -((16*Cos[a + b*x]^5)/(5*b)) + (48*Cos[a + b*x]^7)/(7*b) - (16*Cos[a + b*x]^9)/(3*b) + (16*Cos[a + b*x]^11)/(11*b)}
{Sin[a + b*x]^3*Sin[2*a + 2*b*x]^3, x, 4, (8*Sin[a + b*x]^7)/(7*b) - (8*Sin[a + b*x]^9)/(9*b)}
{Sin[a + b*x]^3*Sin[2*a + 2*b*x]^2, x, 4, -((4*Cos[a + b*x]^3)/(3*b)) + (8*Cos[a + b*x]^5)/(5*b) - (4*Cos[a + b*x]^7)/(7*b)}
{Sin[a + b*x]^3*Sin[2*a + 2*b*x], x, 3, (2*Sin[a + b*x]^5)/(5*b)}
{Sin[a + b*x]^3/Sin[2*a + 2*b*x], x, 3, ArcTanh[Sin[a + b*x]]/(2*b) - Sin[a + b*x]/(2*b)}
{Sin[a + b*x]^3/Sin[2*a + 2*b*x]^2, x, 2, Sec[a + b*x]/(4*b)}
{Sin[a + b*x]^3/Sin[2*a + 2*b*x]^3, x, 3, ArcTanh[Sin[a + b*x]]/(16*b) + (Sec[a + b*x]*Tan[a + b*x])/(16*b)}
{Sin[a + b*x]^3/Sin[2*a + 2*b*x]^4, x, 4, -(ArcTanh[Cos[a + b*x]]/(16*b)) + Sec[a + b*x]/(16*b) + Sec[a + b*x]^3/(48*b)}
{Sin[a + b*x]^3/Sin[2*a + 2*b*x]^5, x, 5, (15*ArcTanh[Sin[a + b*x]])/(256*b) - (15*Csc[a + b*x])/(256*b) + (5*Csc[a + b*x]*Sec[a + b*x]^2)/(256*b) + (Csc[a + b*x]*Sec[a + b*x]^4)/(128*b)}


{Sin[a + b*x]*Sin[2*a + 2*b*x]^(5/2), x, 4, -((5*ArcSin[Cos[a + b*x] - Sin[a + b*x]])/(32*b)) + (5*Log[Cos[a + b*x] + Sin[a + b*x] + Sqrt[Sin[2*a + 2*b*x]]])/(32*b) - (5*Cos[a + b*x]*Sqrt[Sin[2*a + 2*b*x]])/(16*b) + (5*Sin[a + b*x]*Sin[2*a + 2*b*x]^(3/2))/(24*b) - (Cos[a + b*x]*Sin[2*a + 2*b*x]^(5/2))/(6*b)}
{Sin[a + b*x]*Sin[2*a + 2*b*x]^(3/2), x, 3, -((3*ArcSin[Cos[a + b*x] - Sin[a + b*x]])/(16*b)) - (3*Log[Cos[a + b*x] + Sin[a + b*x] + Sqrt[Sin[2*a + 2*b*x]]])/(16*b) + (3*Sin[a + b*x]*Sqrt[Sin[2*a + 2*b*x]])/(8*b) - (Cos[a + b*x]*Sin[2*a + 2*b*x]^(3/2))/(4*b)}
{Sin[a + b*x]*Sin[2*a + 2*b*x]^(1/2), x, 2, -(ArcSin[Cos[a + b*x] - Sin[a + b*x]]/(4*b)) + Log[Cos[a + b*x] + Sin[a + b*x] + Sqrt[Sin[2*a + 2*b*x]]]/(4*b) - (Cos[a + b*x]*Sqrt[Sin[2*a + 2*b*x]])/(2*b)}
{Sin[a + b*x]/Sin[2*a + 2*b*x]^(1/2), x, 1, -(ArcSin[Cos[a + b*x] - Sin[a + b*x]]/(2*b)) - Log[Cos[a + b*x] + Sin[a + b*x] + Sqrt[Sin[2*a + 2*b*x]]]/(2*b)}
{Sin[a + b*x]/Sin[2*a + 2*b*x]^(3/2), x, 1, Sin[a + b*x]/(b*Sqrt[Sin[2*a + 2*b*x]])}
{Sin[a + b*x]/Sin[2*a + 2*b*x]^(5/2), x, 2, Sin[a + b*x]/(3*b*Sin[2*a + 2*b*x]^(3/2)) - (2*Cos[a + b*x])/(3*b*Sqrt[Sin[2*a + 2*b*x]])}
{Sin[a + b*x]/Sin[2*a + 2*b*x]^(7/2), x, 3, Sin[a + b*x]/(5*b*Sin[2*a + 2*b*x]^(5/2)) - (4*Cos[a + b*x])/(15*b*Sin[2*a + 2*b*x]^(3/2)) + (8*Sin[a + b*x])/(15*b*Sqrt[Sin[2*a + 2*b*x]])}
{Sin[a + b*x]/Sin[2*a + 2*b*x]^(9/2), x, 4, Sin[a + b*x]/(7*b*Sin[2*a + 2*b*x]^(7/2)) - (6*Cos[a + b*x])/(35*b*Sin[2*a + 2*b*x]^(5/2)) + (8*Sin[a + b*x])/(35*b*Sin[2*a + 2*b*x]^(3/2)) - (16*Cos[a + b*x])/(35*b*Sqrt[Sin[2*a + 2*b*x]])}


{Sin[a + b*x]^2*Sin[2*a + 2*b*x]^(5/2), x, 5, (3*EllipticE[a - Pi/4 + b*x, 2])/(10*b) - (Cos[2*a + 2*b*x]*Sin[2*a + 2*b*x]^(3/2))/(10*b) - Sin[2*a + 2*b*x]^(7/2)/(14*b)}
{Sin[a + b*x]^2*Sin[2*a + 2*b*x]^(3/2), x, 5, EllipticF[a - Pi/4 + b*x, 2]/(6*b) - (Cos[2*a + 2*b*x]*Sqrt[Sin[2*a + 2*b*x]])/(6*b) - Sin[2*a + 2*b*x]^(5/2)/(10*b)}
{Sin[a + b*x]^2*Sin[2*a + 2*b*x]^(1/2), x, 4, EllipticE[a - Pi/4 + b*x, 2]/(2*b) - Sin[2*a + 2*b*x]^(3/2)/(6*b)}
{Sin[a + b*x]^2/Sin[2*a + 2*b*x]^(1/2), x, 4, EllipticF[a - Pi/4 + b*x, 2]/(2*b) - Sqrt[Sin[2*a + 2*b*x]]/(2*b)}
{Sin[a + b*x]^2/Sin[2*a + 2*b*x]^(3/2), x, 5, -(EllipticE[a - Pi/4 + b*x, 2]/(2*b)) + 1/(2*b*Sqrt[Sin[2*a + 2*b*x]]) - Cos[2*a + 2*b*x]/(2*b*Sqrt[Sin[2*a + 2*b*x]])}
{Sin[a + b*x]^2/Sin[2*a + 2*b*x]^(5/2), x, 5, EllipticF[a - Pi/4 + b*x, 2]/(6*b) + 1/(6*b*Sin[2*a + 2*b*x]^(3/2)) - Cos[2*a + 2*b*x]/(6*b*Sin[2*a + 2*b*x]^(3/2))}
{Sin[a + b*x]^2/Sin[2*a + 2*b*x]^(7/2), x, 6, -((3*EllipticE[a - Pi/4 + b*x, 2])/(10*b)) + 1/(10*b*Sin[2*a + 2*b*x]^(5/2)) - Cos[2*a + 2*b*x]/(10*b*Sin[2*a + 2*b*x]^(5/2)) - (3*Cos[2*a + 2*b*x])/(10*b*Sqrt[Sin[2*a + 2*b*x]])}
{Sin[a + b*x]^2/Sin[2*a + 2*b*x]^(9/2), x, 6, (5*EllipticF[a - Pi/4 + b*x, 2])/(42*b) + 1/(14*b*Sin[2*a + 2*b*x]^(7/2)) - Cos[2*a + 2*b*x]/(14*b*Sin[2*a + 2*b*x]^(7/2)) - (5*Cos[2*a + 2*b*x])/(42*b*Sin[2*a + 2*b*x]^(3/2))}


(* {Sin[a + b*x]^3*Sin[2*a + 2*b*x]^(5/2), x, 5, 0}
{Sin[a + b*x]^3*Sin[2*a + 2*b*x]^(3/2), x, 5, 0}
{Sin[a + b*x]^3*Sin[2*a + 2*b*x]^(1/2), x, 4, 0}
{Sin[a + b*x]^3/Sin[2*a + 2*b*x]^(1/2), x, 4, 0}
{Sin[a + b*x]^3/Sin[2*a + 2*b*x]^(3/2), x, 5, 0}
{Sin[a + b*x]^3/Sin[2*a + 2*b*x]^(5/2), x, 5, 0}
{Sin[a + b*x]^3/Sin[2*a + 2*b*x]^(7/2), x, 6, 0}
{Sin[a + b*x]^3/Sin[2*a + 2*b*x]^(9/2), x, 6, 0} *)


(* ::Subsubsection::Closed:: *)
(*Integrands of the form Cos[a+b x]^m Sin[2 a+2 b x]^n*)


{Cos[a + b*x]*Sin[2*a + 2*b*x]^5, x, 4, -((32*Cos[a + b*x]^7)/(7*b)) + (64*Cos[a + b*x]^9)/(9*b) - (32*Cos[a + b*x]^11)/(11*b)}
{Cos[a + b*x]*Sin[2*a + 2*b*x]^4, x, 4, (16*Sin[a + b*x]^5)/(5*b) - (32*Sin[a + b*x]^7)/(7*b) + (16*Sin[a + b*x]^9)/(9*b)}
{Cos[a + b*x]*Sin[2*a + 2*b*x]^3, x, 4, -((8*Cos[a + b*x]^5)/(5*b)) + (8*Cos[a + b*x]^7)/(7*b)}
{Cos[a + b*x]*Sin[2*a + 2*b*x]^2, x, 4, (4*Sin[a + b*x]^3)/(3*b) - (4*Sin[a + b*x]^5)/(5*b)}
{Cos[a + b*x]*Sin[2*a + 2*b*x], x, 3, -((2*Cos[a + b*x]^3)/(3*b))}
{Cos[a + b*x]/Sin[2*a + 2*b*x], x, 2, -(ArcTanh[Cos[a + b*x]]/(2*b))}
{Cos[a + b*x]/Sin[2*a + 2*b*x]^2, x, 3, ArcTanh[Sin[a + b*x]]/(4*b) - Csc[a + b*x]/(4*b)}
{Cos[a + b*x]/Sin[2*a + 2*b*x]^3, x, 4, -((3*ArcTanh[Cos[a + b*x]])/(16*b)) + (3*Sec[a + b*x])/(16*b) - (Csc[a + b*x]^2*Sec[a + b*x])/(16*b)}
{Cos[a + b*x]/Sin[2*a + 2*b*x]^4, x, 5, (5*ArcTanh[Sin[a + b*x]])/(32*b) - (5*Csc[a + b*x])/(32*b) - (5*Csc[a + b*x]^3)/(96*b) + (Csc[a + b*x]^3*Sec[a + b*x]^2)/(32*b)}
{Cos[a + b*x]/Sin[2*a + 2*b*x]^5, x, 6, -((35*ArcTanh[Cos[a + b*x]])/(256*b)) + (35*Sec[a + b*x])/(256*b) + (35*Sec[a + b*x]^3)/(768*b) - (7*Csc[a + b*x]^2*Sec[a + b*x]^3)/(256*b) - (Csc[a + b*x]^4*Sec[a + b*x]^3)/(128*b)}


{Cos[a + b*x]^2*Sin[2*a + 2*b*x]^5, x, 4, -((4*Cos[a + b*x]^8)/b) + (32*Cos[a + b*x]^10)/(5*b) - (8*Cos[a + b*x]^12)/(3*b)}
{Cos[a + b*x]^2*Sin[2*a + 2*b*x]^4, x, 5, (3*x)/16 - (3*Cos[2*a + 2*b*x]*Sin[2*a + 2*b*x])/(32*b) - (Cos[2*a + 2*b*x]*Sin[2*a + 2*b*x]^3)/(16*b) + Sin[2*a + 2*b*x]^5/(20*b)}
{Cos[a + b*x]^2*Sin[2*a + 2*b*x]^3, x, 4, -((4*Cos[a + b*x]^6)/(3*b)) + Cos[a + b*x]^8/b}
{Cos[a + b*x]^2*Sin[2*a + 2*b*x]^2, x, 4, x/4 - (Cos[2*a + 2*b*x]*Sin[2*a + 2*b*x])/(8*b) + Sin[2*a + 2*b*x]^3/(12*b)}
{Cos[a + b*x]^2*Sin[2*a + 2*b*x], x, 3, -(Cos[a + b*x]^4/(2*b))}
{Cos[a + b*x]^2/Sin[2*a + 2*b*x], x, 2, Log[Sin[a + b*x]]/(2*b)}
{Cos[a + b*x]^2/Sin[2*a + 2*b*x]^2, x, 2, -(Cot[a + b*x]/(4*b))}
{Cos[a + b*x]^2/Sin[2*a + 2*b*x]^3, x, 4, -(Cot[a + b*x]^2/(16*b)) - Log[Cot[a + b*x]]/(8*b)}
{Cos[a + b*x]^2/Sin[2*a + 2*b*x]^4, x, 4, -(Cot[a + b*x]/(8*b)) - Cot[a + b*x]^3/(48*b) + Tan[a + b*x]/(16*b)}
{Cos[a + b*x]^2/Sin[2*a + 2*b*x]^5, x, 4, -((3*Cot[a + b*x]^2)/(64*b)) - Cot[a + b*x]^4/(128*b) - (3*Log[Cot[a + b*x]])/(32*b) + Tan[a + b*x]^2/(64*b)}


{Cos[a + b*x]^3*Sin[2*a + 2*b*x]^5, x, 4, -((32*Cos[a + b*x]^9)/(9*b)) + (64*Cos[a + b*x]^11)/(11*b) - (32*Cos[a + b*x]^13)/(13*b)}
{Cos[a + b*x]^3*Sin[2*a + 2*b*x]^4, x, 4, (16*Sin[a + b*x]^5)/(5*b) - (48*Sin[a + b*x]^7)/(7*b) + (16*Sin[a + b*x]^9)/(3*b) - (16*Sin[a + b*x]^11)/(11*b)}
{Cos[a + b*x]^3*Sin[2*a + 2*b*x]^3, x, 4, -((8*Cos[a + b*x]^7)/(7*b)) + (8*Cos[a + b*x]^9)/(9*b)}
{Cos[a + b*x]^3*Sin[2*a + 2*b*x]^2, x, 4, (4*Sin[a + b*x]^3)/(3*b) - (8*Sin[a + b*x]^5)/(5*b) + (4*Sin[a + b*x]^7)/(7*b)}
{Cos[a + b*x]^3*Sin[2*a + 2*b*x], x, 3, -((2*Cos[a + b*x]^5)/(5*b))}
{Cos[a + b*x]^3/Sin[2*a + 2*b*x], x, 3, -(ArcTanh[Cos[a + b*x]]/(2*b)) + Cos[a + b*x]/(2*b)}
{Cos[a + b*x]^3/Sin[2*a + 2*b*x]^2, x, 2, -(Csc[a + b*x]/(4*b))}
{Cos[a + b*x]^3/Sin[2*a + 2*b*x]^3, x, 3, -(ArcTanh[Cos[a + b*x]]/(16*b)) - (Cot[a + b*x]*Csc[a + b*x])/(16*b)}
{Cos[a + b*x]^3/Sin[2*a + 2*b*x]^4, x, 4, ArcTanh[Sin[a + b*x]]/(16*b) - Csc[a + b*x]/(16*b) - Csc[a + b*x]^3/(48*b)}
{Cos[a + b*x]^3/Sin[2*a + 2*b*x]^5, x, 5, -((15*ArcTanh[Cos[a + b*x]])/(256*b)) + (15*Sec[a + b*x])/(256*b) - (5*Csc[a + b*x]^2*Sec[a + b*x])/(256*b) - (Csc[a + b*x]^4*Sec[a + b*x])/(128*b)}


{Cos[a + b*x]*Sin[2*a + 2*b*x]^(5/2), x, 4, -((5*ArcSin[Cos[a + b*x] - Sin[a + b*x]])/(32*b)) - (5*Log[Cos[a + b*x] + Sin[a + b*x] + Sqrt[Sin[2*a + 2*b*x]]])/(32*b) + (5*Sin[a + b*x]*Sqrt[Sin[2*a + 2*b*x]])/(16*b) - (5*Cos[a + b*x]*Sin[2*a + 2*b*x]^(3/2))/(24*b) + (Sin[a + b*x]*Sin[2*a + 2*b*x]^(5/2))/(6*b)}
{Cos[a + b*x]*Sin[2*a + 2*b*x]^(3/2), x, 3, -((3*ArcSin[Cos[a + b*x] - Sin[a + b*x]])/(16*b)) + (3*Log[Cos[a + b*x] + Sin[a + b*x] + Sqrt[Sin[2*a + 2*b*x]]])/(16*b) - (3*Cos[a + b*x]*Sqrt[Sin[2*a + 2*b*x]])/(8*b) + (Sin[a + b*x]*Sin[2*a + 2*b*x]^(3/2))/(4*b)}
{Cos[a + b*x]*Sin[2*a + 2*b*x]^(1/2), x, 2, -(ArcSin[Cos[a + b*x] - Sin[a + b*x]]/(4*b)) - Log[Cos[a + b*x] + Sin[a + b*x] + Sqrt[Sin[2*a + 2*b*x]]]/(4*b) + (Sin[a + b*x]*Sqrt[Sin[2*a + 2*b*x]])/(2*b)}
{Cos[a + b*x]/Sin[2*a + 2*b*x]^(1/2), x, 1, -(ArcSin[Cos[a + b*x] - Sin[a + b*x]]/(2*b)) + Log[Cos[a + b*x] + Sin[a + b*x] + Sqrt[Sin[2*a + 2*b*x]]]/(2*b)}
{Cos[a + b*x]/Sin[2*a + 2*b*x]^(3/2), x, 1, -(Cos[a + b*x]/(b*Sqrt[Sin[2*a + 2*b*x]]))}
{Cos[a + b*x]/Sin[2*a + 2*b*x]^(5/2), x, 2, -(Cos[a + b*x]/(3*b*Sin[2*a + 2*b*x]^(3/2))) + (2*Sin[a + b*x])/(3*b*Sqrt[Sin[2*a + 2*b*x]])}
{Cos[a + b*x]/Sin[2*a + 2*b*x]^(7/2), x, 3, -(Cos[a + b*x]/(5*b*Sin[2*a + 2*b*x]^(5/2))) + (4*Sin[a + b*x])/(15*b*Sin[2*a + 2*b*x]^(3/2)) - (8*Cos[a + b*x])/(15*b*Sqrt[Sin[2*a + 2*b*x]])}
{Cos[a + b*x]/Sin[2*a + 2*b*x]^(9/2), x, 4, -(Cos[a + b*x]/(7*b*Sin[2*a + 2*b*x]^(7/2))) + (6*Sin[a + b*x])/(35*b*Sin[2*a + 2*b*x]^(5/2)) - (8*Cos[a + b*x])/(35*b*Sin[2*a + 2*b*x]^(3/2)) + (16*Sin[a + b*x])/(35*b*Sqrt[Sin[2*a + 2*b*x]])}


{Cos[a + b*x]^2*Sin[2*a + 2*b*x]^(5/2), x, 5, (3*EllipticE[a - Pi/4 + b*x, 2])/(10*b) - (Cos[2*a + 2*b*x]*Sin[2*a + 2*b*x]^(3/2))/(10*b) + Sin[2*a + 2*b*x]^(7/2)/(14*b)}
{Cos[a + b*x]^2*Sin[2*a + 2*b*x]^(3/2), x, 5, EllipticF[a - Pi/4 + b*x, 2]/(6*b) - (Cos[2*a + 2*b*x]*Sqrt[Sin[2*a + 2*b*x]])/(6*b) + Sin[2*a + 2*b*x]^(5/2)/(10*b)}
{Cos[a + b*x]^2*Sin[2*a + 2*b*x]^(1/2), x, 4, EllipticE[a - Pi/4 + b*x, 2]/(2*b) + Sin[2*a + 2*b*x]^(3/2)/(6*b)}
{Cos[a + b*x]^2/Sin[2*a + 2*b*x]^(1/2), x, 4, EllipticF[a - Pi/4 + b*x, 2]/(2*b) + Sqrt[Sin[2*a + 2*b*x]]/(2*b)}
{Cos[a + b*x]^2/Sin[2*a + 2*b*x]^(3/2), x, 5, -(EllipticE[a - Pi/4 + b*x, 2]/(2*b)) - 1/(2*b*Sqrt[Sin[2*a + 2*b*x]]) - Cos[2*a + 2*b*x]/(2*b*Sqrt[Sin[2*a + 2*b*x]])}
{Cos[a + b*x]^2/Sin[2*a + 2*b*x]^(5/2), x, 5, EllipticF[a - Pi/4 + b*x, 2]/(6*b) - 1/(6*b*Sin[2*a + 2*b*x]^(3/2)) - Cos[2*a + 2*b*x]/(6*b*Sin[2*a + 2*b*x]^(3/2))}
{Cos[a + b*x]^2/Sin[2*a + 2*b*x]^(7/2), x, 6, -((3*EllipticE[a - Pi/4 + b*x, 2])/(10*b)) - 1/(10*b*Sin[2*a + 2*b*x]^(5/2)) - Cos[2*a + 2*b*x]/(10*b*Sin[2*a + 2*b*x]^(5/2)) - (3*Cos[2*a + 2*b*x])/(10*b*Sqrt[Sin[2*a + 2*b*x]])}
{Cos[a + b*x]^2/Sin[2*a + 2*b*x]^(9/2), x, 6, (5*EllipticF[a - Pi/4 + b*x, 2])/(42*b) - 1/(14*b*Sin[2*a + 2*b*x]^(7/2)) - Cos[2*a + 2*b*x]/(14*b*Sin[2*a + 2*b*x]^(7/2)) - (5*Cos[2*a + 2*b*x])/(42*b*Sin[2*a + 2*b*x]^(3/2))}


(* ::Subsection::Closed:: *)
(*Integrands of the form Trig[a+b x]^m Trig[c+d x]^n*)


(* Integrands of the form Sin[a+b*x]^m*Sin[c+d*x]^n where m and n are positive integers *)
{Sin[a + b*x]*Sin[c + d*x], x, 3, Sin[a - c + (b - d)*x]/(2*(b - d)) - Sin[a + c + (b + d)*x]/(2*(b + d))}
{Sin[a + b*x]*Sin[c + d*x]^2, x, 5, -(Cos[a + b*x]/(2*b)) + Cos[a - 2*c + (b - 2*d)*x]/(4*(b - 2*d)) + Cos[a + 2*c + (b + 2*d)*x]/(4*(b + 2*d))}
{Sin[a + b*x]*Sin[c + d*x]^3, x, 6, -(Sin[a - 3*c + (b - 3*d)*x]/(8*(b - 3*d))) + (3*Sin[a - c + (b - d)*x])/(8*(b - d)) - (3*Sin[a + c + (b + d)*x])/(8*(b + d)) + Sin[a + 3*c + (b + 3*d)*x]/(8*(b + 3*d))}

{Sin[a + b*x]^2*Sin[c + d*x]^2, x, 6, x/4 - Sin[2*a + 2*b*x]/(8*b) + Sin[2*a - 2*c + 2*(b - d)*x]/(16*(b - d)) - Sin[2*c + 2*d*x]/(8*d) + Sin[2*a + 2*c + 2*(b + d)*x]/(16*(b + d))}
{Sin[a + b*x]^2*Sin[c + d*x]^3, x, 8, Cos[2*a - 3*c + (2*b - 3*d)*x]/(16*(2*b - 3*d)) - (3*Cos[2*a - c + (2*b - d)*x])/(16*(2*b - d)) - (3*Cos[c + d*x])/(8*d) + Cos[3*c + 3*d*x]/(24*d) + (3*Cos[2*a + c + (2*b + d)*x])/(16*(2*b + d)) - Cos[2*a + 3*c + (2*b + 3*d)*x]/(16*(2*b + 3*d))}

{Sin[a + b*x]^3*Sin[c + d*x]^3, x, 10, -((3*Sin[a - 3*c + (b - 3*d)*x])/(32*(b - 3*d))) + (9*Sin[a - c + (b - d)*x])/(32*(b - d)) + Sin[3*a - 3*c + 3*(b - d)*x]/(96*(b - d)) - (3*Sin[3*a - c + (3*b - d)*x])/(32*(3*b - d)) - (9*Sin[a + c + (b + d)*x])/(32*(b + d)) - Sin[3*a + 3*c + 3*(b + d)*x]/(96*(b + d)) + (3*Sin[3*a + c + (3*b + d)*x])/(32*(3*b + d)) + (3*Sin[a + 3*c + (b + 3*d)*x])/(32*(b + 3*d))}


(* Integrands of the form Cos[a+b*x]^m*Cos[c+d*x]^n where m and n are positive integers *)
{Cos[a + b*x]*Cos[c + d*x], x, 3, Sin[a - c + (b - d)*x]/(2*(b - d)) + Sin[a + c + (b + d)*x]/(2*(b + d))}
{Cos[a + b*x]*Cos[c + d*x]^2, x, 5, Sin[a + b*x]/(2*b) + Sin[a - 2*c + (b - 2*d)*x]/(4*(b - 2*d)) + Sin[a + 2*c + (b + 2*d)*x]/(4*(b + 2*d))}
{Cos[a + b*x]*Cos[c + d*x]^3, x, 6, Sin[a - 3*c + (b - 3*d)*x]/(8*(b - 3*d)) + (3*Sin[a - c + (b - d)*x])/(8*(b - d)) + (3*Sin[a + c + (b + d)*x])/(8*(b + d)) + Sin[a + 3*c + (b + 3*d)*x]/(8*(b + 3*d))}

{Cos[a + b*x]^2*Cos[c + d*x]^2, x, 6, x/4 + Sin[2*a + 2*b*x]/(8*b) + Sin[2*a - 2*c + 2*(b - d)*x]/(16*(b - d)) + Sin[2*c + 2*d*x]/(8*d) + Sin[2*a + 2*c + 2*(b + d)*x]/(16*(b + d))}
{Cos[a + b*x]^2*Cos[c + d*x]^3, x, 8, Sin[2*a - 3*c + (2*b - 3*d)*x]/(16*(2*b - 3*d)) + (3*Sin[2*a - c + (2*b - d)*x])/(16*(2*b - d)) + (3*Sin[c + d*x])/(8*d) + Sin[3*c + 3*d*x]/(24*d) + (3*Sin[2*a + c + (2*b + d)*x])/(16*(2*b + d)) + Sin[2*a + 3*c + (2*b + 3*d)*x]/(16*(2*b + 3*d))}

{Cos[a + b*x]^3*Cos[c + d*x]^3, x, 10, (3*Sin[a - 3*c + (b - 3*d)*x])/(32*(b - 3*d)) + (9*Sin[a - c + (b - d)*x])/(32*(b - d)) + Sin[3*a - 3*c + 3*(b - d)*x]/(96*(b - d)) + (3*Sin[3*a - c + (3*b - d)*x])/(32*(3*b - d)) + (9*Sin[a + c + (b + d)*x])/(32*(b + d)) + Sin[3*a + 3*c + 3*(b + d)*x]/(96*(b + d)) + (3*Sin[3*a + c + (3*b + d)*x])/(32*(3*b + d)) + (3*Sin[a + 3*c + (b + 3*d)*x])/(32*(b + 3*d))}


(* Integrands of the form Sin[a+b*x]^m*Cos[c+d*x]^n where m and n are positive integers *)
{Sin[a + b*x]*Cos[c + d*x], x, 3, -(Cos[a - c + (b - d)*x]/(2*(b - d))) - Cos[a + c + (b + d)*x]/(2*(b + d))}
{Sin[a + b*x]*Cos[c + d*x]^2, x, 5, -(Cos[a + b*x]/(2*b)) - Cos[a - 2*c + (b - 2*d)*x]/(4*(b - 2*d)) - Cos[a + 2*c + (b + 2*d)*x]/(4*(b + 2*d))}
{Sin[a + b*x]*Cos[c + d*x]^3, x, 6, -(Cos[a - 3*c + (b - 3*d)*x]/(8*(b - 3*d))) - (3*Cos[a - c + (b - d)*x])/(8*(b - d)) - (3*Cos[a + c + (b + d)*x])/(8*(b + d)) - Cos[a + 3*c + (b + 3*d)*x]/(8*(b + 3*d))}

{Sin[a + b*x]^2*Cos[c + d*x], x, 5, -(Sin[2*a - c + (2*b - d)*x]/(4*(2*b - d))) + Sin[c + d*x]/(2*d) - Sin[2*a + c + (2*b + d)*x]/(4*(2*b + d))}
{Sin[a + b*x]^2*Cos[c + d*x]^2, x, 6, x/4 - Sin[2*a + 2*b*x]/(8*b) - Sin[2*a - 2*c + 2*(b - d)*x]/(16*(b - d)) + Sin[2*c + 2*d*x]/(8*d) - Sin[2*a + 2*c + 2*(b + d)*x]/(16*(b + d))}
{Sin[a + b*x]^2*Cos[c + d*x]^3, x, 8, -(Sin[2*a - 3*c + (2*b - 3*d)*x]/(16*(2*b - 3*d))) - (3*Sin[2*a - c + (2*b - d)*x])/(16*(2*b - d)) + (3*Sin[c + d*x])/(8*d) + Sin[3*c + 3*d*x]/(24*d) - (3*Sin[2*a + c + (2*b + d)*x])/(16*(2*b + d)) - Sin[2*a + 3*c + (2*b + 3*d)*x]/(16*(2*b + 3*d))}

{Sin[a + b*x]^3*Cos[c + d*x], x, 6, -((3*Cos[a - c + (b - d)*x])/(8*(b - d))) + Cos[3*a - c + (3*b - d)*x]/(8*(3*b - d)) - (3*Cos[a + c + (b + d)*x])/(8*(b + d)) + Cos[3*a + c + (3*b + d)*x]/(8*(3*b + d))}
{Sin[a + b*x]^3*Cos[c + d*x]^2, x, 8, -((3*Cos[a + b*x])/(8*b)) + Cos[3*a + 3*b*x]/(24*b) - (3*Cos[a - 2*c + (b - 2*d)*x])/(16*(b - 2*d)) + Cos[3*a - 2*c + (3*b - 2*d)*x]/(16*(3*b - 2*d)) - (3*Cos[a + 2*c + (b + 2*d)*x])/(16*(b + 2*d)) + Cos[3*a + 2*c + (3*b + 2*d)*x]/(16*(3*b + 2*d))}
{Sin[a + b*x]^3*Cos[c + d*x]^3, x, 10, -((3*Cos[a - 3*c + (b - 3*d)*x])/(32*(b - 3*d))) - (9*Cos[a - c + (b - d)*x])/(32*(b - d)) + Cos[3*a - 3*c + 3*(b - d)*x]/(96*(b - d)) + (3*Cos[3*a - c + (3*b - d)*x])/(32*(3*b - d)) - (9*Cos[a + c + (b + d)*x])/(32*(b + d)) + Cos[3*a + 3*c + 3*(b + d)*x]/(96*(b + d)) + (3*Cos[3*a + c + (3*b + d)*x])/(32*(3*b + d)) - (3*Cos[a + 3*c + (b + 3*d)*x])/(32*(b + 3*d))}


(* Integrands of the form Sin[a+b*x]*Hyper[c+b*x]^n where n is a positive integer *)
{Sin[a + b*x]*Tan[c + b*x], x, 3, (ArcTanh[Sin[c + b*x]]*Cos[a - c])/b - Sin[a + b*x]/b}
{Sin[a + b*x]*Tan[c + b*x]^2, x, 5, Cos[a + b*x]/b + (Cos[a - c]*Sec[c + b*x])/b + (ArcTanh[Sin[c + b*x]]*Sin[a - c])/b}
{Sin[a + b*x]*Tan[c + b*x]^3, x, 8, -((3*ArcTanh[Sin[c + b*x]]*Cos[a - c])/(2*b)) + (Sec[c + b*x]*Sin[a - c])/b + Sin[a + b*x]/b + (Cos[a - c]*Sec[c + b*x]*Tan[c + b*x])/(2*b)}

{Sin[a + b*x]*Cot[c + b*x], x, 3, -((ArcTanh[Cos[c + b*x]]*Sin[a - c])/b) + Sin[a + b*x]/b}
{Sin[a + b*x]*Cot[c + b*x]^2, x, 5, -((ArcTanh[Cos[c + b*x]]*Cos[a - c])/b) + Cos[a + b*x]/b - (Csc[c + b*x]*Sin[a - c])/b}
{Sin[a + b*x]*Cot[c + b*x]^3, x, 8, -((Cos[a - c]*Csc[c + b*x])/b) + (3*ArcTanh[Cos[c + b*x]]*Sin[a - c])/(2*b) - (Cot[c + b*x]*Csc[c + b*x]*Sin[a - c])/(2*b) - Sin[a + b*x]/b}

{Sin[a + b*x]*Sec[c + b*x], x, 3, -((Cos[a - c]*Log[Cos[c + b*x]])/b) + x*Sin[a - c]}
{Sin[a + b*x]*Sec[c + b*x]^2, x, 3, (Cos[a - c]*Sec[c + b*x])/b + (ArcTanh[Sin[c + b*x]]*Sin[a - c])/b}
{Sin[a + b*x]*Sec[c + b*x]^3, x, 3, (Cos[a - c]*Sec[c + b*x]^2)/(2*b) + (Sin[a - c]*Tan[c + b*x])/b}

{Sin[a + b*x]*Csc[c + b*x], x, 3, x*Cos[a - c] + (Log[Sin[c + b*x]]*Sin[a - c])/b}
{Sin[a + b*x]*Csc[c + b*x]^2, x, 3, -((ArcTanh[Cos[c + b*x]]*Cos[a - c])/b) - (Csc[c + b*x]*Sin[a - c])/b}
{Sin[a + b*x]*Csc[c + b*x]^3, x, 3, -((Cos[a - c]*Cot[c + b*x])/b) - (Csc[c + b*x]^2*Sin[a - c])/(2*b)}


(* Integrands of the form Cos[a+b*x]*Hyper[c+b*x]^n where n is a positive integer *)
{Cos[a + b*x]*Tan[c + b*x], x, 3, -(Cos[a + b*x]/b) - (ArcTanh[Sin[c + b*x]]*Sin[a - c])/b}
{Cos[a + b*x]*Tan[c + b*x]^2, x, 5, (ArcTanh[Sin[c + b*x]]*Cos[a - c])/b - (Sec[c + b*x]*Sin[a - c])/b - Sin[a + b*x]/b}
{Cos[a + b*x]*Tan[c + b*x]^3, x, 8, Cos[a + b*x]/b + (Cos[a - c]*Sec[c + b*x])/b + (3*ArcTanh[Sin[c + b*x]]*Sin[a - c])/(2*b) - (Sec[c + b*x]*Sin[a - c]*Tan[c + b*x])/(2*b)}

{Cos[a + b*x]*Cot[c + b*x], x, 3, -((ArcTanh[Cos[c + b*x]]*Cos[a - c])/b) + Cos[a + b*x]/b}
{Cos[a + b*x]*Cot[c + b*x]^2, x, 5, -((Cos[a - c]*Csc[c + b*x])/b) + (ArcTanh[Cos[c + b*x]]*Sin[a - c])/b - Sin[a + b*x]/b}
{Cos[a + b*x]*Cot[c + b*x]^3, x, 8, (3*ArcTanh[Cos[c + b*x]]*Cos[a - c])/(2*b) - Cos[a + b*x]/b - (Cos[a - c]*Cot[c + b*x]*Csc[c + b*x])/(2*b) + (Csc[c + b*x]*Sin[a - c])/b}

{Cos[a + b*x]*Sec[c + b*x], x, 3, x*Cos[a - c] + (Log[Cos[c + b*x]]*Sin[a - c])/b}
{Cos[a + b*x]*Sec[c + b*x]^2, x, 3, (ArcTanh[Sin[c + b*x]]*Cos[a - c])/b - (Sec[c + b*x]*Sin[a - c])/b}
{Cos[a + b*x]*Sec[c + b*x]^3, x, 3, -((Sec[c + b*x]^2*Sin[a - c])/(2*b)) + (Cos[a - c]*Tan[c + b*x])/b}

{Cos[a + b*x]*Csc[c + b*x], x, 3, (Cos[a - c]*Log[Sin[c + b*x]])/b - x*Sin[a - c]}
{Cos[a + b*x]*Csc[c + b*x]^2, x, 3, -((Cos[a - c]*Csc[c + b*x])/b) + (ArcTanh[Cos[c + b*x]]*Sin[a - c])/b}
{Cos[a + b*x]*Csc[c + b*x]^3, x, 3, -((Cos[a - c]*Csc[c + b*x]^2)/(2*b)) + (Cot[c + b*x]*Sin[a - c])/b}


(* ::Subsection::Closed:: *)
(*Integrands of the form x^m Trig[a+b x]^n Trig[a+ b x]^p*)


(* ::Subsubsection::Closed:: *)
(*Integrands of the form x^m Cos[a+b x]^n Sin[a+b x]^p*)


{Sin[x]*Cos[x]/x, x, 3, (1/2)*SinIntegral[2*x]}
{Sin[x]*Cos[x]/x^2, x, 4, CosIntegral[2*x] - Sin[2*x]/(2*x)}
{Sin[x]*Cos[x]/x^3, x, 5, -(Cos[2*x]/(2*x)) - Sin[2*x]/(4*x^2) - SinIntegral[2*x]}


(* Integrands of the form x^m*Sin[a+b*x]^n*Cos[a+b*x]^p where n and p are integers *)
{x^3*Sin[a + b*x]*Cos[a + b*x], x, 4, (3*x)/(8*b^3) - x^3/(4*b) - (3*Cos[a + b*x]*Sin[a + b*x])/(8*b^4) + (3*x^2*Cos[a + b*x]*Sin[a + b*x])/(4*b^2) - (3*x*Sin[a + b*x]^2)/(4*b^3) + (x^3*Sin[a + b*x]^2)/(2*b)}
{x^2*Sin[a + b*x]*Cos[a + b*x], x, 3, -(x^2/(4*b)) + (x*Cos[a + b*x]*Sin[a + b*x])/(2*b^2) - Sin[a + b*x]^2/(4*b^3) + (x^2*Sin[a + b*x]^2)/(2*b)}
{x*Sin[a + b*x]*Cos[a + b*x], x, 2, -(x/(4*b)) + (Cos[a + b*x]*Sin[a + b*x])/(4*b^2) + (x*Sin[a + b*x]^2)/(2*b)}
{Sin[a + b*x]*Cos[a + b*x]/x, x, 5, (1/2)*CosIntegral[2*b*x]*Sin[2*a] + (1/2)*Cos[2*a]*SinIntegral[2*b*x]}
{Sin[a + b*x]*Cos[a + b*x]/x^2, x, 6, b*Cos[2*a]*CosIntegral[2*b*x] - Sin[2*a + 2*b*x]/(2*x) - b*Sin[2*a]*SinIntegral[2*b*x]}
{Sin[a + b*x]*Cos[a + b*x]/x^3, x, 7, -((b*Cos[2*a + 2*b*x])/(2*x)) - b^2*CosIntegral[2*b*x]*Sin[2*a] - Sin[2*a + 2*b*x]/(4*x^2) - b^2*Cos[2*a]*SinIntegral[2*b*x]}

{x^3*Sin[a + b*x]^2*Cos[a + b*x], x, 7, -((14*Cos[a + b*x])/(9*b^4)) + (2*x^2*Cos[a + b*x])/(3*b^2) + (2*Cos[a + b*x]^3)/(27*b^4) - (4*x*Sin[a + b*x])/(3*b^3) + (x^2*Cos[a + b*x]*Sin[a + b*x]^2)/(3*b^2) - (2*x*Sin[a + b*x]^3)/(9*b^3) + (x^3*Sin[a + b*x]^3)/(3*b)}
{x^2*Sin[a + b*x]^2*Cos[a + b*x], x, 4, (4*x*Cos[a + b*x])/(9*b^2) - (4*Sin[a + b*x])/(9*b^3) + (2*x*Cos[a + b*x]*Sin[a + b*x]^2)/(9*b^2) - (2*Sin[a + b*x]^3)/(27*b^3) + (x^2*Sin[a + b*x]^3)/(3*b)}
{x*Sin[a + b*x]^2*Cos[a + b*x], x, 3, Cos[a + b*x]/(3*b^2) - Cos[a + b*x]^3/(9*b^2) + (x*Sin[a + b*x]^3)/(3*b)}
{Sin[a + b*x]^2*Cos[a + b*x]/x, x, 8, (1/4)*Cos[a]*CosIntegral[b*x] - (1/4)*Cos[3*a]*CosIntegral[3*b*x] - (1/4)*Sin[a]*SinIntegral[b*x] + (1/4)*Sin[3*a]*SinIntegral[3*b*x]}
{Sin[a + b*x]^2*Cos[a + b*x]/x^2, x, 10, -(Cos[a + b*x]/(4*x)) + Cos[3*a + 3*b*x]/(4*x) - (1/4)*b*CosIntegral[b*x]*Sin[a] + (3/4)*b*CosIntegral[3*b*x]*Sin[3*a] - (1/4)*b*Cos[a]*SinIntegral[b*x] + (3/4)*b*Cos[3*a]*SinIntegral[3*b*x]}
{Sin[a + b*x]^2*Cos[a + b*x]/x^3, x, 12, -(Cos[a + b*x]/(8*x^2)) + Cos[3*a + 3*b*x]/(8*x^2) - (1/8)*b^2*Cos[a]*CosIntegral[b*x] + (9/8)*b^2*Cos[3*a]*CosIntegral[3*b*x] + (b*Sin[a + b*x])/(8*x) - (3*b*Sin[3*a + 3*b*x])/(8*x) + (1/8)*b^2*Sin[a]*SinIntegral[b*x] - (9/8)*b^2*Sin[3*a]*SinIntegral[3*b*x]}

{x^3*Sin[a + b*x]*Cos[a + b*x]^2, x, 7, (4*x*Cos[a + b*x])/(3*b^3) + (2*x*Cos[a + b*x]^3)/(9*b^3) - (x^3*Cos[a + b*x]^3)/(3*b) - (14*Sin[a + b*x])/(9*b^4) + (2*x^2*Sin[a + b*x])/(3*b^2) + (x^2*Cos[a + b*x]^2*Sin[a + b*x])/(3*b^2) + (2*Sin[a + b*x]^3)/(27*b^4)}
{x^2*Sin[a + b*x]*Cos[a + b*x]^2, x, 4, (4*Cos[a + b*x])/(9*b^3) + (2*Cos[a + b*x]^3)/(27*b^3) - (x^2*Cos[a + b*x]^3)/(3*b) + (4*x*Sin[a + b*x])/(9*b^2) + (2*x*Cos[a + b*x]^2*Sin[a + b*x])/(9*b^2)}
{x*Sin[a + b*x]*Cos[a + b*x]^2, x, 3, -((x*Cos[a + b*x]^3)/(3*b)) + Sin[a + b*x]/(3*b^2) - Sin[a + b*x]^3/(9*b^2)}
{Sin[a + b*x]*Cos[a + b*x]^2/x, x, 8, (1/4)*CosIntegral[b*x]*Sin[a] + (1/4)*CosIntegral[3*b*x]*Sin[3*a] + (1/4)*Cos[a]*SinIntegral[b*x] + (1/4)*Cos[3*a]*SinIntegral[3*b*x]}
{Sin[a + b*x]*Cos[a + b*x]^2/x^2, x, 10, (1/4)*b*Cos[a]*CosIntegral[b*x] + (3/4)*b*Cos[3*a]*CosIntegral[3*b*x] - Sin[a + b*x]/(4*x) - Sin[3*a + 3*b*x]/(4*x) - (1/4)*b*Sin[a]*SinIntegral[b*x] - (3/4)*b*Sin[3*a]*SinIntegral[3*b*x]}
{Sin[a + b*x]*Cos[a + b*x]^2/x^3, x, 12, -((b*Cos[a + b*x])/(8*x)) - (3*b*Cos[3*a + 3*b*x])/(8*x) - (1/8)*b^2*CosIntegral[b*x]*Sin[a] - (9/8)*b^2*CosIntegral[3*b*x]*Sin[3*a] - Sin[a + b*x]/(8*x^2) - Sin[3*a + 3*b*x]/(8*x^2) - (1/8)*b^2*Cos[a]*SinIntegral[b*x] - (9/8)*b^2*Cos[3*a]*SinIntegral[3*b*x]}

{x^3*Sin[a + b*x]^2*Cos[a + b*x]^2, x, 7, x^4/32 + (3*Cos[4*a + 4*b*x])/(1024*b^4) - (3*x^2*Cos[4*a + 4*b*x])/(128*b^2) + (3*x*Sin[4*a + 4*b*x])/(256*b^3) - (x^3*Sin[4*a + 4*b*x])/(32*b)}
{x^2*Sin[a + b*x]^2*Cos[a + b*x]^2, x, 6, x^3/24 - (x*Cos[4*a + 4*b*x])/(64*b^2) + Sin[4*a + 4*b*x]/(256*b^3) - (x^2*Sin[4*a + 4*b*x])/(32*b)}
{x*Sin[a + b*x]^2*Cos[a + b*x]^2, x, 5, x^2/16 - Cos[4*a + 4*b*x]/(128*b^2) - (x*Sin[4*a + 4*b*x])/(32*b)}
{Sin[a + b*x]^2*Cos[a + b*x]^2/x, x, 6, (-(1/8))*Cos[4*a]*CosIntegral[4*b*x] + Log[x]/8 + (1/8)*Sin[4*a]*SinIntegral[4*b*x]}
{Sin[a + b*x]^2*Cos[a + b*x]^2/x^2, x, 7, -(1/(8*x)) + Cos[4*a + 4*b*x]/(8*x) + (1/2)*b*CosIntegral[4*b*x]*Sin[4*a] + (1/2)*b*Cos[4*a]*SinIntegral[4*b*x]}
{Sin[a + b*x]^2*Cos[a + b*x]^2/x^3, x, 8, -(1/(16*x^2)) + Cos[4*a + 4*b*x]/(16*x^2) + b^2*Cos[4*a]*CosIntegral[4*b*x] - (b*Sin[4*a + 4*b*x])/(4*x) - b^2*Sin[4*a]*SinIntegral[4*b*x]}

{x^3*Sin[a + b*x]^3*Cos[a + b*x]^3, x, 10, (9*x*Cos[2*a + 2*b*x])/(128*b^3) - (3*x^3*Cos[2*a + 2*b*x])/(64*b) - (x*Cos[6*a + 6*b*x])/(1152*b^3) + (x^3*Cos[6*a + 6*b*x])/(192*b) - (9*Sin[2*a + 2*b*x])/(256*b^4) + (9*x^2*Sin[2*a + 2*b*x])/(128*b^2) + Sin[6*a + 6*b*x]/(6912*b^4) - (x^2*Sin[6*a + 6*b*x])/(384*b^2)}
{x^2*Sin[a + b*x]^3*Cos[a + b*x]^3, x, 8, (3*Cos[2*a + 2*b*x])/(128*b^3) - (3*x^2*Cos[2*a + 2*b*x])/(64*b) - Cos[6*a + 6*b*x]/(3456*b^3) + (x^2*Cos[6*a + 6*b*x])/(192*b) + (3*x*Sin[2*a + 2*b*x])/(64*b^2) - (x*Sin[6*a + 6*b*x])/(576*b^2)}
{x*Sin[a + b*x]^3*Cos[a + b*x]^3, x, 6, -((3*x*Cos[2*a + 2*b*x])/(64*b)) + (x*Cos[6*a + 6*b*x])/(192*b) + (3*Sin[2*a + 2*b*x])/(128*b^2) - Sin[6*a + 6*b*x]/(1152*b^2)}
{Sin[a + b*x]^3*Cos[a + b*x]^3/x, x, 8, (3/32)*CosIntegral[2*b*x]*Sin[2*a] - (1/32)*CosIntegral[6*b*x]*Sin[6*a] + (3/32)*Cos[2*a]*SinIntegral[2*b*x] - (1/32)*Cos[6*a]*SinIntegral[6*b*x]}
{Sin[a + b*x]^3*Cos[a + b*x]^3/x^2, x, 10, (3/16)*b*Cos[2*a]*CosIntegral[2*b*x] - (3/16)*b*Cos[6*a]*CosIntegral[6*b*x] - (3*Sin[2*a + 2*b*x])/(32*x) + Sin[6*a + 6*b*x]/(32*x) - (3/16)*b*Sin[2*a]*SinIntegral[2*b*x] + (3/16)*b*Sin[6*a]*SinIntegral[6*b*x]}
{Sin[a + b*x]^3*Cos[a + b*x]^3/x^3, x, 12, -((3*b*Cos[2*a + 2*b*x])/(32*x)) + (3*b*Cos[6*a + 6*b*x])/(32*x) - (3/16)*b^2*CosIntegral[2*b*x]*Sin[2*a] + (9/16)*b^2*CosIntegral[6*b*x]*Sin[6*a] - (3*Sin[2*a + 2*b*x])/(64*x^2) + Sin[6*a + 6*b*x]/(64*x^2) - (3/16)*b^2*Cos[2*a]*SinIntegral[2*b*x] + (9/16)*b^2*Cos[6*a]*SinIntegral[6*b*x]}


(* Integrands of the form x*Sin[a+b*x]*Cos[a+b*x]^n where n is a half-integer *)
{x*Sin[a + b*x]*Cos[a + b*x]^(3/2), x, 3, -((2*x*Cos[a + b*x]^(5/2))/(5*b)) + (12*EllipticE[(1/2)*(a + b*x), 2])/(25*b^2) + (4*Cos[a + b*x]^(3/2)*Sin[a + b*x])/(25*b^2)}
{x*Sin[a + b*x]*Sqrt[Cos[a + b*x]], x, 3, -((2*x*Cos[a + b*x]^(3/2))/(3*b)) + (4*EllipticF[(1/2)*(a + b*x), 2])/(9*b^2) + (4*Sqrt[Cos[a + b*x]]*Sin[a + b*x])/(9*b^2)}
{x*Sin[a + b*x]/Sqrt[Cos[a + b*x]], x, 2, -((2*x*Sqrt[Cos[a + b*x]])/b) + (4*EllipticE[(1/2)*(a + b*x), 2])/b^2}
{x*Sin[a + b*x]/Cos[a + b*x]^(3/2), x, 2, (2*x)/(b*Sqrt[Cos[a + b*x]]) - (4*EllipticF[(1/2)*(a + b*x), 2])/b^2}
{x*Sin[a + b*x]/Cos[a + b*x]^(5/2), x, 3, (2*x)/(3*b*Cos[a + b*x]^(3/2)) + (4*EllipticE[(1/2)*(a + b*x), 2])/(3*b^2) - (4*Sin[a + b*x])/(3*b^2*Sqrt[Cos[a + b*x]])}


(* Integrands of the form x*Cos[a+b*x]*Sin[a+b*x]^n where n is a half-integer *)
{x*Cos[a + b*x]*Sin[a + b*x]^(3/2), x, 3, (12*EllipticE[Pi/4 + (1/2)*(-a - b*x), 2])/(25*b^2) + (4*Cos[a + b*x]*Sin[a + b*x]^(3/2))/(25*b^2) + (2*x*Sin[a + b*x]^(5/2))/(5*b)}
{x*Cos[a + b*x]*Sqrt[Sin[a + b*x]], x, 3, (4*EllipticF[Pi/4 + (1/2)*(-a - b*x), 2])/(9*b^2) + (4*Cos[a + b*x]*Sqrt[Sin[a + b*x]])/(9*b^2) + (2*x*Sin[a + b*x]^(3/2))/(3*b)}
{x*Cos[a + b*x]/Sqrt[Sin[a + b*x]], x, 2, (4*EllipticE[Pi/4 + (1/2)*(-a - b*x), 2])/b^2 + (2*x*Sqrt[Sin[a + b*x]])/b}
{x*Cos[a + b*x]/Sin[a + b*x]^(3/2), x, 2, -((4*EllipticF[Pi/4 + (1/2)*(-a - b*x), 2])/b^2) - (2*x)/(b*Sqrt[Sin[a + b*x]])}
{x*Cos[a + b*x]/Sin[a + b*x]^(5/2), x, 3, (4*EllipticE[Pi/4 + (1/2)*(-a - b*x), 2])/(3*b^2) - (2*x)/(3*b*Sin[a + b*x]^(3/2)) - (4*Cos[a + b*x])/(3*b^2*Sqrt[Sin[a + b*x]])}


(* Integrands of the form x*Sin[a+b*x]*Sec[a+b*x]^n where n is a half-integer *)
{x*Sin[a + b*x]*Sec[a + b*x]^(5/2), x, 4, (4*Sqrt[Cos[a + b*x]]*EllipticE[(1/2)*(a + b*x), 2]*Sqrt[Sec[a + b*x]])/(3*b^2) + (2*x*Sec[a + b*x]^(3/2))/(3*b) - (4*Sqrt[Sec[a + b*x]]*Sin[a + b*x])/(3*b^2)}
{x*Sin[a + b*x]*Sec[a + b*x]^(3/2), x, 3, (2*x*Sqrt[Sec[a + b*x]])/b - (4*Sqrt[Cos[a + b*x]]*EllipticF[(1/2)*(a + b*x), 2]*Sqrt[Sec[a + b*x]])/b^2}
{x*Sin[a + b*x]*Sqrt[Sec[a + b*x]], x, 3, -((2*x)/(b*Sqrt[Sec[a + b*x]])) + (4*Sqrt[Cos[a + b*x]]*EllipticE[(1/2)*(a + b*x), 2]*Sqrt[Sec[a + b*x]])/b^2}
{x*Sin[a + b*x]/Sqrt[Sec[a + b*x]], x, 4, -((2*x)/(3*b*Sec[a + b*x]^(3/2))) + (4*Sqrt[Cos[a + b*x]]*EllipticF[(1/2)*(a + b*x), 2]*Sqrt[Sec[a + b*x]])/(9*b^2) + (4*Sin[a + b*x])/(9*b^2*Sqrt[Sec[a + b*x]])}
{x*Sin[a + b*x]/Sec[a + b*x]^(3/2), x, 4, -((2*x)/(5*b*Sec[a + b*x]^(5/2))) + (12*Sqrt[Cos[a + b*x]]*EllipticE[(1/2)*(a + b*x), 2]*Sqrt[Sec[a + b*x]])/(25*b^2) + (4*Sin[a + b*x])/(25*b^2*Sec[a + b*x]^(3/2))}


(* Integrands of the form x*Cos[a+b*x]*Csc[a+b*x]^n where n is a half-integer *)
{x*Cos[a + b*x]*Csc[a + b*x]^(5/2), x, 4, -((4*Cos[a + b*x]*Sqrt[Csc[a + b*x]])/(3*b^2)) - (2*x*Csc[a + b*x]^(3/2))/(3*b) + (4*Sqrt[Csc[a + b*x]]*EllipticE[Pi/4 + (1/2)*(-a - b*x), 2]*Sqrt[Sin[a + b*x]])/(3*b^2)}
{x*Cos[a + b*x]*Csc[a + b*x]^(3/2), x, 3, -((2*x*Sqrt[Csc[a + b*x]])/b) - (4*Sqrt[Csc[a + b*x]]*EllipticF[Pi/4 + (1/2)*(-a - b*x), 2]*Sqrt[Sin[a + b*x]])/b^2}
{x*Cos[a + b*x]*Sqrt[Csc[a + b*x]], x, 3, (2*x)/(b*Sqrt[Csc[a + b*x]]) + (4*Sqrt[Csc[a + b*x]]*EllipticE[Pi/4 + (1/2)*(-a - b*x), 2]*Sqrt[Sin[a + b*x]])/b^2}
{x*Cos[a + b*x]/Sqrt[Csc[a + b*x]], x, 4, (2*x)/(3*b*Csc[a + b*x]^(3/2)) + (4*Cos[a + b*x])/(9*b^2*Sqrt[Csc[a + b*x]]) + (4*Sqrt[Csc[a + b*x]]*EllipticF[Pi/4 + (1/2)*(-a - b*x), 2]*Sqrt[Sin[a + b*x]])/(9*b^2)}
{x*Cos[a + b*x]/Csc[a + b*x]^(3/2), x, 4, (2*x)/(5*b*Csc[a + b*x]^(5/2)) + (4*Cos[a + b*x])/(25*b^2*Csc[a + b*x]^(3/2)) + (12*Sqrt[Csc[a + b*x]]*EllipticE[Pi/4 + (1/2)*(-a - b*x), 2]*Sqrt[Sin[a + b*x]])/(25*b^2)}


(* ::Subsubsection::Closed:: *)
(*Integrands of the form x^m Trig[a+b x]^n Tan[a+b x]^p*)


(* Integrands of the form x^m*Sec[a+b*x]^n*Tan[a+b*x] where m and n are integers *)
{x*Sec[a + b*x]*Tan[a + b*x], x, 2, -(ArcTanh[Sin[a + b*x]]/b^2) + (x*Sec[a + b*x])/b}
{x^2*Sec[a + b*x]*Tan[a + b*x], x, 5, (4*I*x*ArcTan[E^(I*a + I*b*x)])/b^2 - (2*I*PolyLog[2, (-I)*E^(I*a + I*b*x)])/b^3 + (2*I*PolyLog[2, I*E^(I*a + I*b*x)])/b^3 + (x^2*Sec[a + b*x])/b}
{x^3*Sec[a + b*x]*Tan[a + b*x], x, 7, (6*I*x^2*ArcTan[E^(I*a + I*b*x)])/b^2 - (6*I*x*PolyLog[2, (-I)*E^(I*a + I*b*x)])/b^3 + (6*I*x*PolyLog[2, I*E^(I*a + I*b*x)])/b^3 + (6*PolyLog[3, (-I)*E^(I*a + I*b*x)])/b^4 - (6*PolyLog[3, I*E^(I*a + I*b*x)])/b^4 + (x^3*Sec[a + b*x])/b}
{Sec[a + b*x]*Tan[a + b*x]/x, x, 0, Int[(Sec[a + b*x]*Tan[a + b*x])/x, x]}

{x*Sec[a + b*x]^2*Tan[a + b*x], x, 2, (x*Sec[a + b*x]^2)/(2*b) - Tan[a + b*x]/(2*b^2)}
{x^2*Sec[a + b*x]^2*Tan[a + b*x], x, 3, -(Log[Cos[a + b*x]]/b^3) + (x^2*Sec[a + b*x]^2)/(2*b) - (x*Tan[a + b*x])/b^2}
{x^3*Sec[a + b*x]^2*Tan[a + b*x], x, 6, (3*I*x^2)/(2*b^2) - (3*x*Log[1 + E^(2*I*a + 2*I*b*x)])/b^3 + (3*I*PolyLog[2, -E^(2*I*a + 2*I*b*x)])/(2*b^4) + (x^3*Sec[a + b*x]^2)/(2*b) - (3*x^2*Tan[a + b*x])/(2*b^2)}
{Sec[a + b*x]^2*Tan[a + b*x]/x, x, 0, Int[(Sec[a + b*x]^2*Tan[a + b*x])/x, x]}


(* ::Subsubsection::Closed:: *)
(*Integrands of the form x^m Trig[a+b x]^n Cot[a+b x]^p*)


(* Integrands of the form x^m*Csc[a+b*x]^n*Cot[a+b*x] where m and n are integers *)
{x*Csc[a + b*x]*Cot[a + b*x], x, 2, -(ArcTanh[Cos[a + b*x]]/b^2) - (x*Csc[a + b*x])/b}
{x^2*Csc[a + b*x]*Cot[a + b*x], x, 5, -((4*x*ArcTanh[E^(I*a + I*b*x)])/b^2) - (x^2*Csc[a + b*x])/b + (2*I*PolyLog[2, -E^(I*a + I*b*x)])/b^3 - (2*I*PolyLog[2, E^(I*a + I*b*x)])/b^3}
{x^3*Csc[a + b*x]*Cot[a + b*x], x, 7, -((6*x^2*ArcTanh[E^(I*a + I*b*x)])/b^2) - (x^3*Csc[a + b*x])/b + (6*I*x*PolyLog[2, -E^(I*a + I*b*x)])/b^3 - (6*I*x*PolyLog[2, E^(I*a + I*b*x)])/b^3 - (6*PolyLog[3, -E^(I*a + I*b*x)])/b^4 + (6*PolyLog[3, E^(I*a + I*b*x)])/b^4}
{Csc[a + b*x]*Cot[a + b*x]/x, x, 0, Int[(Cot[a + b*x]*Csc[a + b*x])/x, x]}

{x*Csc[a + b*x]^2*Cot[a + b*x], x, 2, -(Cot[a + b*x]/(2*b^2)) - (x*Csc[a + b*x]^2)/(2*b)}
{x^2*Csc[a + b*x]^2*Cot[a + b*x], x, 3, -((x*Cot[a + b*x])/b^2) - (x^2*Csc[a + b*x]^2)/(2*b) + Log[Sin[a + b*x]]/b^3}
{x^3*Csc[a + b*x]^2*Cot[a + b*x], x, 6, -((3*I*x^2)/(2*b^2)) - (3*x^2*Cot[a + b*x])/(2*b^2) - (x^3*Csc[a + b*x]^2)/(2*b) + (3*x*Log[1 - E^(2*I*a + 2*I*b*x)])/b^3 - (3*I*PolyLog[2, E^(2*I*a + 2*I*b*x)])/(2*b^4)}
{Csc[a + b*x]^2*Cot[a + b*x]/x, x, 0, Int[(Cot[a + b*x]*Csc[a + b*x]^2)/x, x]}


(* ::Subsubsection::Closed:: *)
(*Integrands of the form x^m Csc[a+b x]^n Sec[a+b x]^p*)


{x^3*Csc[a + b*x]*Sec[a + b*x], x, 9, -((2*x^3*ArcTanh[E^(2*I*a + 2*I*b*x)])/b) + (3*I*x^2*PolyLog[2, -E^(2*I*a + 2*I*b*x)])/(2*b^2) - (3*I*x^2*PolyLog[2, E^(2*I*a + 2*I*b*x)])/(2*b^2) - (3*x*PolyLog[3, -E^(2*I*a + 2*I*b*x)])/(2*b^3) + (3*x*PolyLog[3, E^(2*I*a + 2*I*b*x)])/(2*b^3) - (3*I*PolyLog[4, -E^(2*I*a + 2*I*b*x)])/(4*b^4) + (3*I*PolyLog[4, E^(2*I*a + 2*I*b*x)])/(4*b^4)}
{x^2*Csc[a + b*x]*Sec[a + b*x], x, 7, -((2*x^2*ArcTanh[E^(2*I*a + 2*I*b*x)])/b) + (I*x*PolyLog[2, -E^(2*I*a + 2*I*b*x)])/b^2 - (I*x*PolyLog[2, E^(2*I*a + 2*I*b*x)])/b^2 - PolyLog[3, -E^(2*I*a + 2*I*b*x)]/(2*b^3) + PolyLog[3, E^(2*I*a + 2*I*b*x)]/(2*b^3)}
{x^1*Csc[a + b*x]*Sec[a + b*x], x, 5, -((2*x*ArcTanh[E^(2*I*a + 2*I*b*x)])/b) + (I*PolyLog[2, -E^(2*I*a + 2*I*b*x)])/(2*b^2) - (I*PolyLog[2, E^(2*I*a + 2*I*b*x)])/(2*b^2)}
{x^0*Csc[a + b*x]*Sec[a + b*x], x, 1, Log[Tan[a + b*x]]/b}
{Csc[a + b*x]*Sec[a + b*x]/x^1, x, 1, 2*Int[Csc[2*a + 2*b*x]/x, x]}

{x^3*Csc[a + b*x]*Sec[a + b*x]^2, x, 19, (6*I*x^2*ArcTan[E^(I*a + I*b*x)])/b^2 - (2*x^3*ArcTanh[E^(I*a + I*b*x)])/b + (3*I*x^2*PolyLog[2, -E^(I*a + I*b*x)])/b^2 - (6*I*x*PolyLog[2, (-I)*E^(I*a + I*b*x)])/b^3 + (6*I*x*PolyLog[2, I*E^(I*a + I*b*x)])/b^3 - (3*I*x^2*PolyLog[2, E^(I*a + I*b*x)])/b^2 - (6*x*PolyLog[3, -E^(I*a + I*b*x)])/b^3 + (6*PolyLog[3, (-I)*E^(I*a + I*b*x)])/b^4 - (6*PolyLog[3, I*E^(I*a + I*b*x)])/b^4 + (6*x*PolyLog[3, E^(I*a + I*b*x)])/b^3 - (6*I*PolyLog[4, -E^(I*a + I*b*x)])/b^4 + (6*I*PolyLog[4, E^(I*a + I*b*x)])/b^4 + (x^3*Sec[a + b*x])/b}
{x^2*Csc[a + b*x]*Sec[a + b*x]^2, x, 15, (4*I*x*ArcTan[E^(I*a + I*b*x)])/b^2 - (2*x^2*ArcTanh[E^(I*a + I*b*x)])/b + (2*I*x*PolyLog[2, -E^(I*a + I*b*x)])/b^2 - (2*I*PolyLog[2, (-I)*E^(I*a + I*b*x)])/b^3 + (2*I*PolyLog[2, I*E^(I*a + I*b*x)])/b^3 - (2*I*x*PolyLog[2, E^(I*a + I*b*x)])/b^2 - (2*PolyLog[3, -E^(I*a + I*b*x)])/b^3 + (2*PolyLog[3, E^(I*a + I*b*x)])/b^3 + (x^2*Sec[a + b*x])/b}
{x^1*Csc[a + b*x]*Sec[a + b*x]^2, x, 9, -((2*x*ArcTanh[E^(I*a + I*b*x)])/b) - ArcTanh[Sin[a + b*x]]/b^2 + (I*PolyLog[2, -E^(I*a + I*b*x)])/b^2 - (I*PolyLog[2, E^(I*a + I*b*x)])/b^2 + (x*Sec[a + b*x])/b}
{x^0*Csc[a + b*x]*Sec[a + b*x]^2, x, 2, -(ArcTanh[Cos[a + b*x]]/b) + Sec[a + b*x]/b}
{Csc[a + b*x]*Sec[a + b*x]^2/x^1, x, 0, Int[(Csc[a + b*x]*Sec[a + b*x]^2)/x, x]}

{x^3*Csc[a + b*x]*Sec[a + b*x]^3, x, 19, (3*I*x^2)/(2*b^2) - (2*x^3*ArcTanh[E^(2*I*a + 2*I*b*x)])/b - (3*x*Log[1 + E^(2*I*a + 2*I*b*x)])/b^3 + (3*I*(1 + b^2*x^2)*PolyLog[2, -E^(2*I*a + 2*I*b*x)])/(2*b^4) - (3*I*x^2*PolyLog[2, E^(2*I*a + 2*I*b*x)])/(2*b^2) - (3*x*PolyLog[3, -E^(2*I*a + 2*I*b*x)])/(2*b^3) + (3*x*PolyLog[3, E^(2*I*a + 2*I*b*x)])/(2*b^3) - (3*I*PolyLog[4, -E^(2*I*a + 2*I*b*x)])/(4*b^4) + (3*I*PolyLog[4, E^(2*I*a + 2*I*b*x)])/(4*b^4) + (x^3*Sec[a + b*x]^2)/(2*b) - (3*x^2*Tan[a + b*x])/(2*b^2)}
{x^2*Csc[a + b*x]*Sec[a + b*x]^3, x, 14, -((2*x^2*ArcTanh[E^(2*I*a + 2*I*b*x)])/b) - Log[Cos[a + b*x]]/b^3 + (I*x*PolyLog[2, -E^(2*I*a + 2*I*b*x)])/b^2 - (I*x*PolyLog[2, E^(2*I*a + 2*I*b*x)])/b^2 - PolyLog[3, -E^(2*I*a + 2*I*b*x)]/(2*b^3) + PolyLog[3, E^(2*I*a + 2*I*b*x)]/(2*b^3) + (x^2*Sec[a + b*x]^2)/(2*b) - (x*Tan[a + b*x])/b^2}
{x^1*Csc[a + b*x]*Sec[a + b*x]^3, x, 9, -((2*x*ArcTanh[E^(2*I*a + 2*I*b*x)])/b) + (I*PolyLog[2, -E^(2*I*a + 2*I*b*x)])/(2*b^2) - (I*PolyLog[2, E^(2*I*a + 2*I*b*x)])/(2*b^2) + (x*Sec[a + b*x]^2)/(2*b) - Tan[a + b*x]/(2*b^2)}
{x^0*Csc[a + b*x]*Sec[a + b*x]^3, x, 3, Log[Tan[a + b*x]]/b + Tan[a + b*x]^2/(2*b)}
{Csc[a + b*x]*Sec[a + b*x]^3/x^1, x, 0, Int[(Csc[a + b*x]*Sec[a + b*x]^3)/x, x]}


{x^3*Csc[a + b*x]^2*Sec[a + b*x], x, 19, -((2*I*x^3*ArcTan[E^(I*a + I*b*x)])/b) - (6*x^2*ArcTanh[E^(I*a + I*b*x)])/b^2 - (x^3*Csc[a + b*x])/b + (6*I*x*PolyLog[2, -E^(I*a + I*b*x)])/b^3 + (3*I*x^2*PolyLog[2, (-I)*E^(I*a + I*b*x)])/b^2 - (3*I*x^2*PolyLog[2, I*E^(I*a + I*b*x)])/b^2 - (6*I*x*PolyLog[2, E^(I*a + I*b*x)])/b^3 - (6*PolyLog[3, -E^(I*a + I*b*x)])/b^4 - (6*x*PolyLog[3, (-I)*E^(I*a + I*b*x)])/b^3 + (6*x*PolyLog[3, I*E^(I*a + I*b*x)])/b^3 + (6*PolyLog[3, E^(I*a + I*b*x)])/b^4 - (6*I*PolyLog[4, (-I)*E^(I*a + I*b*x)])/b^4 + (6*I*PolyLog[4, I*E^(I*a + I*b*x)])/b^4}
{x^2*Csc[a + b*x]^2*Sec[a + b*x], x, 15, -((2*I*x^2*ArcTan[E^(I*a + I*b*x)])/b) - (4*x*ArcTanh[E^(I*a + I*b*x)])/b^2 - (x^2*Csc[a + b*x])/b + (2*I*PolyLog[2, -E^(I*a + I*b*x)])/b^3 + (2*I*x*PolyLog[2, (-I)*E^(I*a + I*b*x)])/b^2 - (2*I*x*PolyLog[2, I*E^(I*a + I*b*x)])/b^2 - (2*I*PolyLog[2, E^(I*a + I*b*x)])/b^3 - (2*PolyLog[3, (-I)*E^(I*a + I*b*x)])/b^3 + (2*PolyLog[3, I*E^(I*a + I*b*x)])/b^3}
{x^1*Csc[a + b*x]^2*Sec[a + b*x], x, 9, -((2*I*x*ArcTan[E^(I*a + I*b*x)])/b) - ArcTanh[Cos[a + b*x]]/b^2 - (x*Csc[a + b*x])/b + (I*PolyLog[2, (-I)*E^(I*a + I*b*x)])/b^2 - (I*PolyLog[2, I*E^(I*a + I*b*x)])/b^2}
{x^0*Csc[a + b*x]^2*Sec[a + b*x], x, 2, ArcTanh[Sin[a + b*x]]/b - Csc[a + b*x]/b}
{Csc[a + b*x]^2*Sec[a + b*x]/x^1, x, 0, Int[(Csc[a + b*x]^2*Sec[a + b*x])/x, x]}

{x^3*Csc[a + b*x]^2*Sec[a + b*x]^2, x, 7, -((2*I*x^3)/b) - (2*x^3*Cot[2*a + 2*b*x])/b + (3*x^2*Log[1 - E^(4*I*a + 4*I*b*x)])/b^2 - (3*I*x*PolyLog[2, E^(4*I*a + 4*I*b*x)])/(2*b^3) + (3*PolyLog[3, E^(4*I*a + 4*I*b*x)])/(8*b^4)}
{x^2*Csc[a + b*x]^2*Sec[a + b*x]^2, x, 6, -((2*I*x^2)/b) - (2*x^2*Cot[2*a + 2*b*x])/b + (2*x*Log[1 - E^(4*I*a + 4*I*b*x)])/b^2 - (I*PolyLog[2, E^(4*I*a + 4*I*b*x)])/(2*b^3)}
{x^1*Csc[a + b*x]^2*Sec[a + b*x]^2, x, 3, -((2*x*Cot[2*a + 2*b*x])/b) + Log[Sin[2*a + 2*b*x]]/b^2}
{x^0*Csc[a + b*x]^2*Sec[a + b*x]^2, x, 3, -(Cot[a + b*x]/b) + Tan[a + b*x]/b}
{Csc[a + b*x]^2*Sec[a + b*x]^2/x^1, x, 1, 4*Int[Csc[2*a + 2*b*x]^2/x, x]}

{x^3*Csc[a + b*x]^2*Sec[a + b*x]^3, x, 34, -((6*I*x*ArcTan[E^(I*a + I*b*x)])/b^3) - (3*I*x^3*ArcTan[E^(I*a + I*b*x)])/b - (6*x^2*ArcTanh[E^(I*a + I*b*x)])/b^2 + (6*I*x*PolyLog[2, -E^(I*a + I*b*x)])/b^3 + (3*I*(2 + 3*b^2*x^2)*PolyLog[2, (-I)*E^(I*a + I*b*x)])/(2*b^4) - (3*I*(2 + 3*b^2*x^2)*PolyLog[2, I*E^(I*a + I*b*x)])/(2*b^4) - (6*I*x*PolyLog[2, E^(I*a + I*b*x)])/b^3 - (6*PolyLog[3, -E^(I*a + I*b*x)])/b^4 - (9*x*PolyLog[3, (-I)*E^(I*a + I*b*x)])/b^3 + (9*x*PolyLog[3, I*E^(I*a + I*b*x)])/b^3 + (6*PolyLog[3, E^(I*a + I*b*x)])/b^4 - (9*I*PolyLog[4, (-I)*E^(I*a + I*b*x)])/b^4 + (9*I*PolyLog[4, I*E^(I*a + I*b*x)])/b^4 - (3*x^2*Sec[a + b*x])/(2*b^2) - (x^3*Csc[a + b*x]*(3 - Sec[a + b*x]^2))/(2*b)}
{x^2*Csc[a + b*x]^2*Sec[a + b*x]^3, x, 24, -((3*I*x^2*ArcTan[E^(I*a + I*b*x)])/b) - (4*x*ArcTanh[E^(I*a + I*b*x)])/b^2 + ArcTanh[Sin[a + b*x]]/b^3 + (2*I*PolyLog[2, -E^(I*a + I*b*x)])/b^3 + (3*I*x*PolyLog[2, (-I)*E^(I*a + I*b*x)])/b^2 - (3*I*x*PolyLog[2, I*E^(I*a + I*b*x)])/b^2 - (2*I*PolyLog[2, E^(I*a + I*b*x)])/b^3 - (3*PolyLog[3, (-I)*E^(I*a + I*b*x)])/b^3 + (3*PolyLog[3, I*E^(I*a + I*b*x)])/b^3 - (x*Sec[a + b*x])/b^2 - (x^2*Csc[a + b*x]*(3 - Sec[a + b*x]^2))/(2*b)}
{x^1*Csc[a + b*x]^2*Sec[a + b*x]^3, x, 11, -((3*I*x*ArcTan[E^(I*a + I*b*x)])/b) - ArcTanh[Cos[a + b*x]]/b^2 + (3*I*PolyLog[2, (-I)*E^(I*a + I*b*x)])/(2*b^2) - (3*I*PolyLog[2, I*E^(I*a + I*b*x)])/(2*b^2) - Sec[a + b*x]/(2*b^2) - (x*Csc[a + b*x]*(3 - Sec[a + b*x]^2))/(2*b)}
{x^0*Csc[a + b*x]^2*Sec[a + b*x]^3, x, 3, (3*ArcTanh[Sin[a + b*x]])/(2*b) - (3*Csc[a + b*x])/(2*b) + (Csc[a + b*x]*Sec[a + b*x]^2)/(2*b)}
{Csc[a + b*x]^2*Sec[a + b*x]^3/x^1, x, 0, Int[(Csc[a + b*x]^2*Sec[a + b*x]^3)/x, x]}


(* Integrands of the form x^m*Csc[a+b*x]^3*Sec[a+b*x]^p where m and p are integers *)
{x^3*Csc[a + b*x]^3*Sec[a + b*x], x, 19, -((3*I*x^2)/(2*b^2)) - (2*x^3*ArcTanh[E^(2*I*a + 2*I*b*x)])/b - (3*x^2*Cot[a + b*x])/(2*b^2) - (x^3*Csc[a + b*x]^2)/(2*b) + (3*x*Log[1 - E^(2*I*a + 2*I*b*x)])/b^3 + (3*I*x^2*PolyLog[2, -E^(2*I*a + 2*I*b*x)])/(2*b^2) - (3*I*(1 + b^2*x^2)*PolyLog[2, E^(2*I*a + 2*I*b*x)])/(2*b^4) - (3*x*PolyLog[3, -E^(2*I*a + 2*I*b*x)])/(2*b^3) + (3*x*PolyLog[3, E^(2*I*a + 2*I*b*x)])/(2*b^3) - (3*I*PolyLog[4, -E^(2*I*a + 2*I*b*x)])/(4*b^4) + (3*I*PolyLog[4, E^(2*I*a + 2*I*b*x)])/(4*b^4)}
{x^2*Csc[a + b*x]^3*Sec[a + b*x], x, 14, -((2*x^2*ArcTanh[E^(2*I*a + 2*I*b*x)])/b) - (x*Cot[a + b*x])/b^2 - (x^2*Csc[a + b*x]^2)/(2*b) + Log[Sin[a + b*x]]/b^3 + (I*x*PolyLog[2, -E^(2*I*a + 2*I*b*x)])/b^2 - (I*x*PolyLog[2, E^(2*I*a + 2*I*b*x)])/b^2 - PolyLog[3, -E^(2*I*a + 2*I*b*x)]/(2*b^3) + PolyLog[3, E^(2*I*a + 2*I*b*x)]/(2*b^3)}
{x^1*Csc[a + b*x]^3*Sec[a + b*x], x, 9, -((2*x*ArcTanh[E^(2*I*a + 2*I*b*x)])/b) - Cot[a + b*x]/(2*b^2) - (x*Csc[a + b*x]^2)/(2*b) + (I*PolyLog[2, -E^(2*I*a + 2*I*b*x)])/(2*b^2) - (I*PolyLog[2, E^(2*I*a + 2*I*b*x)])/(2*b^2)}
{x^0*Csc[a + b*x]^3*Sec[a + b*x], x, 3, -(Cot[a + b*x]^2/(2*b)) - Log[Cot[a + b*x]]/b}
{Csc[a + b*x]^3*Sec[a + b*x]/x^1, x, 0, Int[(Csc[a + b*x]^3*Sec[a + b*x])/x, x]}

{x^3*Csc[a + b*x]^3*Sec[a + b*x]^2, x, 34, (6*I*x^2*ArcTan[E^(I*a + I*b*x)])/b^2 - (6*x*ArcTanh[E^(I*a + I*b*x)])/b^3 - (3*x^3*ArcTanh[E^(I*a + I*b*x)])/b - (3*x^2*Csc[a + b*x])/(2*b^2) + (3*I*(2 + 3*b^2*x^2)*PolyLog[2, -E^(I*a + I*b*x)])/(2*b^4) - (6*I*x*PolyLog[2, (-I)*E^(I*a + I*b*x)])/b^3 + (6*I*x*PolyLog[2, I*E^(I*a + I*b*x)])/b^3 - (3*I*(2 + 3*b^2*x^2)*PolyLog[2, E^(I*a + I*b*x)])/(2*b^4) - (9*x*PolyLog[3, -E^(I*a + I*b*x)])/b^3 + (6*PolyLog[3, (-I)*E^(I*a + I*b*x)])/b^4 - (6*PolyLog[3, I*E^(I*a + I*b*x)])/b^4 + (9*x*PolyLog[3, E^(I*a + I*b*x)])/b^3 - (9*I*PolyLog[4, -E^(I*a + I*b*x)])/b^4 + (9*I*PolyLog[4, E^(I*a + I*b*x)])/b^4 + (x^3*(3 - Csc[a + b*x]^2)*Sec[a + b*x])/(2*b)}
{x^2*Csc[a + b*x]^3*Sec[a + b*x]^2, x, 24, (4*I*x*ArcTan[E^(I*a + I*b*x)])/b^2 - (3*x^2*ArcTanh[E^(I*a + I*b*x)])/b - ArcTanh[Cos[a + b*x]]/b^3 - (x*Csc[a + b*x])/b^2 + (3*I*x*PolyLog[2, -E^(I*a + I*b*x)])/b^2 - (2*I*PolyLog[2, (-I)*E^(I*a + I*b*x)])/b^3 + (2*I*PolyLog[2, I*E^(I*a + I*b*x)])/b^3 - (3*I*x*PolyLog[2, E^(I*a + I*b*x)])/b^2 - (3*PolyLog[3, -E^(I*a + I*b*x)])/b^3 + (3*PolyLog[3, E^(I*a + I*b*x)])/b^3 + (x^2*(3 - Csc[a + b*x]^2)*Sec[a + b*x])/(2*b)}
{x^1*Csc[a + b*x]^3*Sec[a + b*x]^2, x, 11, -((3*x*ArcTanh[E^(I*a + I*b*x)])/b) - ArcTanh[Sin[a + b*x]]/b^2 - Csc[a + b*x]/(2*b^2) + (3*I*PolyLog[2, -E^(I*a + I*b*x)])/(2*b^2) - (3*I*PolyLog[2, E^(I*a + I*b*x)])/(2*b^2) + (x*(3 - Csc[a + b*x]^2)*Sec[a + b*x])/(2*b)}
{x^0*Csc[a + b*x]^3*Sec[a + b*x]^2, x, 3, -((3*ArcTanh[Cos[a + b*x]])/(2*b)) + (3*Sec[a + b*x])/(2*b) - (Csc[a + b*x]^2*Sec[a + b*x])/(2*b)}
{Csc[a + b*x]^3*Sec[a + b*x]^2/x^1, x, 0, Int[(Csc[a + b*x]^3*Sec[a + b*x]^2)/x, x]}

{x^3*Sec[a + b*x]^3*Csc[a + b*x]^3, x, 14, -((6*x*ArcTanh[E^(2*I*a + 2*I*b*x)])/b^3) - (4*x^3*ArcTanh[E^(2*I*a + 2*I*b*x)])/b - (3*x^2*Csc[2*a + 2*b*x])/b^2 - (2*x^3*Cot[2*a + 2*b*x]*Csc[2*a + 2*b*x])/b + (3*I*(1 + 2*b^2*x^2)*PolyLog[2, -E^(2*I*a + 2*I*b*x)])/(2*b^4) - (3*I*(1 + 2*b^2*x^2)*PolyLog[2, E^(2*I*a + 2*I*b*x)])/(2*b^4) - (3*x*PolyLog[3, -E^(2*I*a + 2*I*b*x)])/b^3 + (3*x*PolyLog[3, E^(2*I*a + 2*I*b*x)])/b^3 - (3*I*PolyLog[4, -E^(2*I*a + 2*I*b*x)])/(2*b^4) + (3*I*PolyLog[4, E^(2*I*a + 2*I*b*x)])/(2*b^4)}
{x^2*Sec[a + b*x]^3*Csc[a + b*x]^3, x, 9, -((4*x^2*ArcTanh[E^(2*I*a + 2*I*b*x)])/b) - ArcTanh[Cos[2*a + 2*b*x]]/b^3 - (2*x*Csc[2*a + 2*b*x])/b^2 - (2*x^2*Cot[2*a + 2*b*x]*Csc[2*a + 2*b*x])/b + (2*I*x*PolyLog[2, -E^(2*I*a + 2*I*b*x)])/b^2 - (2*I*x*PolyLog[2, E^(2*I*a + 2*I*b*x)])/b^2 - PolyLog[3, -E^(2*I*a + 2*I*b*x)]/b^3 + PolyLog[3, E^(2*I*a + 2*I*b*x)]/b^3}
{x^1*Sec[a + b*x]^3*Csc[a + b*x]^3, x, 6, -((4*x*ArcTanh[E^(2*I*a + 2*I*b*x)])/b) - Csc[2*a + 2*b*x]/b^2 - (2*x*Cot[2*a + 2*b*x]*Csc[2*a + 2*b*x])/b + (I*PolyLog[2, -E^(2*I*a + 2*I*b*x)])/b^2 - (I*PolyLog[2, E^(2*I*a + 2*I*b*x)])/b^2}
{x^0*Sec[a + b*x]^3*Csc[a + b*x]^3, x, 3, -(Cot[a + b*x]^2/(2*b)) + (2*Log[Tan[a + b*x]])/b + Tan[a + b*x]^2/(2*b)}
{Sec[a + b*x]^3*Csc[a + b*x]^3/x^1, x, 1, 8*Int[Csc[2*a + 2*b*x]^3/x, x]}


(* ::Subsection::Closed:: *)
(*Integrands of the form Trig[m x]^p Trig[n x]^q*)


(* ::Subsubsection::Closed:: *)
(*Integrands of the form Trig[m x] Sin[n x]*)


(* Integrands of the form Sin[m*x]*Sin[n*x] where m and n are integers *)
{Sin[2*x]*Sin[x],x, 3, (2*Sin[x]^3)/3}
{Sin[3*x]*Sin[x],x, 3, (1/4)*Sin[2*x] - (1/8)*Sin[4*x]}
{Sin[4*x]*Sin[x],x, 3, (1/6)*Sin[3*x] - (1/10)*Sin[5*x]}
{Sin[m*x]*Sin[x],x, 3, Sin[(1 - m)*x]/(2*(1 - m)) - Sin[(1 + m)*x]/(2*(1 + m))}


(* Integrands of the form Cos[m*x]*Sin[n*x] where m and n are integers *)
{Cos[2*x]*Sin[x],x, 4, Cos[x]/2 - (1/6)*Cos[3*x]}
{Cos[3*x]*Sin[x],x, 4, (1/4)*Cos[2*x] - (1/8)*Cos[4*x]}
{Cos[4*x]*Sin[x],x, 4, (1/6)*Cos[3*x] - (1/10)*Cos[5*x]}
{Cos[m*x]*Sin[x],x, 3, -(Cos[(1 - m)*x]/(2*(1 - m))) - Cos[(1 + m)*x]/(2*(1 + m))}


(* Integrands of the form Tan[m*x]*Sin[n*x] where m and n are integers. *)
{Tan[2*x]*Sin[x], x, 5, ArcTanh[Sqrt[2]*Sin[x]]/Sqrt[2] - Sin[x]}
{Tan[3*x]*Sin[x], x, 3, (1/3)*ArcTanh[(3*Sin[x])/(1 + 2*Sin[x]^2)] - Sin[x]}
{Tan[4*x]*Sin[x], x, 5, (1/4)*Sqrt[2 - Sqrt[2]]*ArcTanh[(2*Sin[x])/Sqrt[2 - Sqrt[2]]] + (1/4)*Sqrt[2 + Sqrt[2]]*ArcTanh[(2*Sin[x])/Sqrt[2 + Sqrt[2]]] - Sin[x]}
{Tan[5*x]*Sin[x], x, 8, -(ArcTanh[(1 - 4*Sin[x])/Sqrt[5]]/(2*Sqrt[5])) + (1/5)*ArcTanh[Sin[x]] + ArcTanh[(1 + 4*Sin[x])/Sqrt[5]]/(2*Sqrt[5]) + (1/20)*Log[1 - 2*Sin[x] - 4*Sin[x]^2] - (1/20)*Log[1 + 2*Sin[x] - 4*Sin[x]^2] - Sin[x]}
{Tan[6*x]*Sin[x], x, 7, ArcTanh[Sqrt[2]*Sin[x]]/(3*Sqrt[2]) - (1/12)*(Sqrt[2] + Sqrt[6])*ArcTanh[(Sqrt[2] - Sqrt[6])*Sin[x]] - (1/12)*(Sqrt[2] - Sqrt[6])*ArcTanh[(Sqrt[2] + Sqrt[6])*Sin[x]] - Sin[x]}
(* Before use of TryTrigReduceQ in ExpandExpression, TrigReduce expansion resulted in infinite recursion. *)
{Tan[n*x]*Sin[x], x, 0, Int[Sin[x]*Tan[n*x], x]}


(* Integrands of the form Cot[m*x]*Sin[n*x] where m and n are integers. *)
{Cot[2*x]*Sin[x], x, 4, (-(1/2))*ArcTanh[Sin[x]] + Sin[x]}
{Cot[3*x]*Sin[x], x, 4, -(ArcTanh[(2*Sin[x])/Sqrt[3]]/Sqrt[3]) + Sin[x]}
{Cot[4*x]*Sin[x], x, 5, (-(1/4))*ArcTanh[Sin[x]] - ArcTanh[Sqrt[2]*Sin[x]]/(2*Sqrt[2]) + Sin[x]}
{Cot[5*x]*Sin[x], x, 6, (-(1/10))*Sqrt[10 - 2*Sqrt[5]]*ArcTanh[(4*Sin[x])/Sqrt[10 - 2*Sqrt[5]]] - (1/10)*Sqrt[10 + 2*Sqrt[5]]*ArcTanh[(4*Sin[x])/Sqrt[10 + 2*Sqrt[5]]] + Sin[x]}
{Cot[6*x]*Sin[x], x, 6, (-(1/6))*ArcTanh[Sin[x]] - (1/6)*ArcTanh[2*Sin[x]] - ArcTanh[(2*Sin[x])/Sqrt[3]]/(2*Sqrt[3]) + Sin[x]}


(* Integrands of the form Sec[m*x]*Sin[n*x] where m and n are integers. *)
{Sec[2*x]*Sin[x], x, 2, ArcTanh[Sqrt[2]*Cos[x]]/Sqrt[2]}
{Sec[3*x]*Sin[x], x, 3, (-(1/3))*ArcTanh[1 - (8*Cos[x]^2)/3]}
{Sec[4*x]*Sin[x], x, 4, (-(1/4))*Sqrt[2 + Sqrt[2]]*ArcTanh[(2*Cos[x])/Sqrt[2 - Sqrt[2]]] + (1/4)*Sqrt[2 - Sqrt[2]]*ArcTanh[(2*Cos[x])/Sqrt[2 + Sqrt[2]]]}
{Sec[5*x]*Sin[x], x, 4, -(ArcTanh[(5 - 8*Cos[x]^2)/Sqrt[5]]/(2*Sqrt[5])) - (1/5)*Log[Cos[x]] + (1/20)*Log[5 - 20*Cos[x]^2 + 16*Cos[x]^4]}
{Sec[6*x]*Sin[x], x, 7, -(ArcTanh[Sqrt[2]*Cos[x]]/(3*Sqrt[2])) + (1/12)*(Sqrt[2] - Sqrt[6])*ArcTanh[(Sqrt[2] - Sqrt[6])*Cos[x]] + (1/12)*(Sqrt[2] + Sqrt[6])*ArcTanh[(Sqrt[2] + Sqrt[6])*Cos[x]]}


(* Integrands of the form Csc[m*x]*Sin[n*x] where m and n are integers. *)
{Csc[2*x]*Sin[x], x, 2, (1/2)*ArcTanh[Sin[x]]}
{Csc[3*x]*Sin[x], x, 3, ArcTanh[Sqrt[3]*Cot[x]]/Sqrt[3]}
{Csc[4*x]*Sin[x], x, 4, (-(1/4))*ArcTanh[Sin[x]] + ArcTanh[Sqrt[2]*Sin[x]]/(2*Sqrt[2])}
{Csc[5*x]*Sin[x], x, 8, (1/10)*Sqrt[10 - 2*Sqrt[5]]*ArcTanh[Sqrt[5 - 2*Sqrt[5]]*Cot[x]] - (1/10)*Sqrt[10 + 2*Sqrt[5]]*ArcTanh[Sqrt[5 + 2*Sqrt[5]]*Cot[x]]}
{Csc[6*x]*Sin[x], x, 6, (1/6)*ArcTanh[Sin[x]] + (1/6)*ArcTanh[2*Sin[x]] - ArcTanh[(2*Sin[x])/Sqrt[3]]/(2*Sqrt[3])}

{Csc[x]*Sin[3*x], x, 3, x + 2*Cos[x]*Sin[x]}
{Csc[3*x]*Sin[6*x], x, 2, (2*Sin[3*x])/3}


(* ::Subsubsection::Closed:: *)
(*Integrands of the form Trig[m x] Cos[n x]*)


(* Integrands of the form Sin[m*x]*Cos[n*x] where m and n are integers *)
{Sin[2*x]*Cos[x], x, 3, (-(2/3))*Cos[x]^3}
{Sin[3*x]*Cos[x], x, 3, (-(1/4))*Cos[2*x] - (1/8)*Cos[4*x]}
{Sin[4*x]*Cos[x], x, 3, (-(1/6))*Cos[3*x] - (1/10)*Cos[5*x]}
{Sin[m*x]*Cos[x], x, 4, Cos[(1 - m)*x]/(2*(1 - m)) - Cos[(1 + m)*x]/(2*(1 + m))}


(* Integrands of the form Cos[m*x]*Cos[n*x] where m and n are integers *)
{Cos[2*x]*Cos[x], x, 3, Sin[x]/2 + (1/6)*Sin[3*x]}
{Cos[3*x]*Cos[x], x, 3, (1/4)*Sin[2*x] + (1/8)*Sin[4*x]}
{Cos[4*x]*Cos[x], x, 3, (1/6)*Sin[3*x] + (1/10)*Sin[5*x]}
{Cos[m*x]*Cos[x], x, 3, Sin[(1 - m)*x]/(2*(1 - m)) + Sin[(1 + m)*x]/(2*(1 + m))}


(* Integrands of the form Tan[m*x]*Cos[n*x] where m and n are integers. *)
{Tan[2*x]*Cos[x], x, 5, ArcTanh[Sqrt[2]*Cos[x]]/Sqrt[2] - Cos[x]}
{Tan[3*x]*Cos[x], x, 4, ArcTanh[(2*Cos[x])/Sqrt[3]]/Sqrt[3] - Cos[x]}
{Tan[4*x]*Cos[x], x, 6, (1/4)*Sqrt[2 - Sqrt[2]]*ArcTanh[(2*Cos[x])/Sqrt[2 - Sqrt[2]]] + (1/4)*Sqrt[2 + Sqrt[2]]*ArcTanh[(2*Cos[x])/Sqrt[2 + Sqrt[2]]] - Cos[x]}
{Tan[5*x]*Cos[x], x, 6, (1/10)*Sqrt[10 - 2*Sqrt[5]]*ArcTanh[(4*Cos[x])/Sqrt[10 - 2*Sqrt[5]]] + (1/10)*Sqrt[10 + 2*Sqrt[5]]*ArcTanh[(4*Cos[x])/Sqrt[10 + 2*Sqrt[5]]] - Cos[x]}
{Tan[6*x]*Cos[x], x, 8, ArcTanh[Sqrt[2]*Cos[x]]/(3*Sqrt[2]) - (1/12)*(Sqrt[2] + Sqrt[6])*ArcTanh[(Sqrt[2] - Sqrt[6])*Cos[x]] - (1/12)*(Sqrt[2] - Sqrt[6])*ArcTanh[(Sqrt[2] + Sqrt[6])*Cos[x]] - Cos[x]}


(* Integrands of the form Cot[m*x]*Cos[n*x] where m and n are integers. *)
{Cot[2*x]*Cos[x], x, 5, (-(1/2))*ArcTanh[Cos[x]] + Cos[x]}
{Cot[3*x]*Cos[x], x, 3, (-(1/3))*ArcTanh[(3*Cos[x])/(1 + 2*Cos[x]^2)] + Cos[x]}
{Cot[4*x]*Cos[x], x, 5, (-(1/4))*ArcTanh[Cos[x]] - ArcTanh[Sqrt[2]*Cos[x]]/(2*Sqrt[2]) + Cos[x]}
{Cot[5*x]*Cos[x], x, 8, ArcTanh[(1 - 4*Cos[x])/Sqrt[5]]/(2*Sqrt[5]) - (1/5)*ArcTanh[Cos[x]] - ArcTanh[(1 + 4*Cos[x])/Sqrt[5]]/(2*Sqrt[5]) + Cos[x] - (1/20)*Log[1 - 2*Cos[x] - 4*Cos[x]^2] + (1/20)*Log[1 + 2*Cos[x] - 4*Cos[x]^2]}
{Cot[6*x]*Cos[x], x, 6, (-(1/6))*ArcTanh[Cos[x]] - (1/6)*ArcTanh[2*Cos[x]] - ArcTanh[(2*Cos[x])/Sqrt[3]]/(2*Sqrt[3]) + Cos[x]}
(* Before use of TryTrigReduceQ in ExpandExpression, TrigReduce expansion resulted in infinite recursion. *)
{Cot[n*x]*Cos[x], x, 0, Int[Cos[x]*Cot[n*x], x]}


(* Integrands of the form Sec[m*x]*Cos[n*x] where m and n are integers. *)
{Sec[2*x]*Cos[x], x, 2, ArcTanh[Sqrt[2]*Sin[x]]/Sqrt[2]}
{Sec[3*x]*Cos[x], x, 3, ArcTanh[Sqrt[3]*Tan[x]]/Sqrt[3]}
{Sec[4*x]*Cos[x], x, 4, (1/4)*Sqrt[2 + Sqrt[2]]*ArcTanh[(2*Sin[x])/Sqrt[2 - Sqrt[2]]] - (1/4)*Sqrt[2 - Sqrt[2]]*ArcTanh[(2*Sin[x])/Sqrt[2 + Sqrt[2]]]}
{Sec[5*x]*Cos[x], x, 8, (-(1/10))*Sqrt[10 - 2*Sqrt[5]]*ArcTanh[Sqrt[5 - 2*Sqrt[5]]*Tan[x]] + (1/10)*Sqrt[10 + 2*Sqrt[5]]*ArcTanh[Sqrt[5 + 2*Sqrt[5]]*Tan[x]]}
{Sec[6*x]*Cos[x], x, 7, -(ArcTanh[Sqrt[2]*Sin[x]]/(3*Sqrt[2])) + (1/12)*(Sqrt[2] - Sqrt[6])*ArcTanh[(Sqrt[2] - Sqrt[6])*Sin[x]] + (1/12)*(Sqrt[2] + Sqrt[6])*ArcTanh[(Sqrt[2] + Sqrt[6])*Sin[x]]}

{Sec[x]*Cos[2*x], x, 4, -ArcTanh[Sin[x]] + 2*Sin[x]}
{Sec[2*x]*Cos[4*x], x, 4, -ArcTanh[Sin[2*x]]/2 + Sin[2*x]}


(* Integrands of the form Csc[m*x]*Cos[n*x] where m and n are integers. *)
{Csc[2*x]*Cos[x], x, 2, (-(1/2))*ArcTanh[Cos[x]]}
{Csc[3*x]*Cos[x], x, 2, (-(1/3))*ArcTanh[1 - (8*Sin[x]^2)/3]}
{Csc[4*x]*Cos[x], x, 5, (-(1/4))*ArcTanh[Cos[x]] + ArcTanh[Sqrt[2]*Cos[x]]/(2*Sqrt[2])}
{Csc[5*x]*Cos[x], x, 4, ArcTanh[(5 - 8*Sin[x]^2)/Sqrt[5]]/(2*Sqrt[5]) + (1/5)*Log[Sin[x]] - (1/20)*Log[5 - 20*Sin[x]^2 + 16*Sin[x]^4]}
{Csc[6*x]*Cos[x], x, 6, (-(1/6))*ArcTanh[Cos[x]] - (1/6)*ArcTanh[2*Cos[x]] + ArcTanh[(2*Cos[x])/Sqrt[3]]/(2*Sqrt[3])}


(* ::Subsubsection::Closed:: *)
(*Integrands of the form Trig[m x]^p Trig[n x]^q*)


{Cos[6*x]^3*Sin[x], x, 6, (3*Cos[5*x])/40 - (3*Cos[7*x])/56 + Cos[17*x]/136 - Cos[19*x]/152}
{Cos[6*x]^3*Sin[9*x], x, 6, (-(1/8))*Cos[3*x] + (1/72)*Cos[9*x] - (1/40)*Cos[15*x] - (1/216)*Cos[27*x]}

{Cos[2*x]*Sin[6*x]^2, x, 5, (1/4)*Sin[2*x] - (1/40)*Sin[10*x] - (1/56)*Sin[14*x]}

{Cos[x]*Sin[6*x]^2, x, 5, Sin[x]/2 - (1/44)*Sin[11*x] - (1/52)*Sin[13*x]}
{Cos[x]*Sin[6*x]^3, x, 6, (-3*Cos[5*x])/40 - (3*Cos[7*x])/56 + Cos[17*x]/136 + Cos[19*x]/152}
{Cos[7*x]*Sin[6*x]^3, x, 6, (3*Cos[x])/8 + Cos[11*x]/88 - (3*Cos[13*x])/104 + Cos[25*x]/200}
{Cos[3*x]^2*Sin[2*x]^3, x, 7, (-(3/16))*Cos[2*x] + (3/64)*Cos[4*x] + (1/48)*Cos[6*x] - (3/128)*Cos[8*x] + (1/192)*Cos[12*x]}


(* ::Subsubsection::Closed:: *)
(*Integrands of the form x Trig[m x]^p Trig[n x]^q*)


{x*Csc[x]*Sin[3*x], x, 5, x^2/2 + (1/2)*Cos[2*x] + x*Sin[2*x]}


(* Integrands of the form x*Cos[2*x]*Sec[x]^n where n is an integer *)
{x*Cos[2*x]*Sec[x], x, -1, 2*Cos[x] - x*Log[1 - I*E^(I*x)] + x*Log[1 + I*E^(I*x)] - I*PolyLog[2, (-I)*E^(I*x)] + I*PolyLog[2, I*E^(I*x)] + 2*x*Sin[x]}
{x*Cos[2*x]*Sec[x]^2, x, 7, x^2 - Log[Cos[x]] - x*Tan[x]}
{x*Cos[2*x]*Sec[x]^3, x, -1, -3*I*x*ArcTan[E^(I*x)] + (3/2)*I*PolyLog[2, (-I)*E^(I*x)] - (3/2)*I*PolyLog[2, I*E^(I*x)] + Sec[x]/2 - (1/2)*x*Sec[x]*Tan[x]}


(* ::Subsection::Closed:: *)
(*Integrands of the form (Trig[a+b x] Trig[a+b x])^m*)
(**)


(* Integrands of the form (Sin[x]*Tan[x])^n *)
{(Sin[x]*Tan[x])^(1/2), x, 2, -2*Cot[x]*Sqrt[Sin[x]*Tan[x]]}
{(Sin[x]*Tan[x])^(3/2), x, 3, (2/3)*Csc[x]*(4 - Sin[x]^2)*Sqrt[Sin[x]*Tan[x]]}
{(Sin[x]*Tan[x])^(5/2), x, 4, (2/15)*Cot[x]*Sqrt[Sin[x]*Tan[x]]*(32 + (8 - 3*Sin[x]^2)*Tan[x]^2)}


(* Integrands of the form (Cos[x]*Cot[x])^n *)
{(Cos[x]*Cot[x])^(1/2), x, 2, 2*Sqrt[Cos[x]*Cot[x]]*Tan[x]}
{(Cos[x]*Cot[x])^(3/2), x, 3, (-(2/3))*(4 - Cos[x]^2)*Sqrt[Cos[x]*Cot[x]]*Sec[x]}
{(Cos[x]*Cot[x])^(5/2), x, 4, (-(2/15))*Sqrt[Cos[x]*Cot[x]]*(32 + (8 - 3*Cos[x]^2)*Cot[x]^2)*Tan[x]}


(* ::Subsection::Closed:: *)
(*Integrands of the form Trig[x]^m / (a+b Trig[x])*)


(* ::Subsubsection::Closed:: *)
(*Integrands of the form Trig[x]^m / (a+b Tan[x])*)


(* Integrands of the form Sin[x]^m/(a+b*Tan[x]) where m is a positive integer *)
{Sin[x]/(a + b*Tan[x]), x, 9, (a*b*ArcTanh[(b*Cos[x] - a*Sin[x])/Sqrt[a^2 + b^2]])/(a^2 + b^2)^(3/2) - (a*Cos[x])/(a^2 + b^2) + (b*Sin[x])/(a^2 + b^2), (2*a*b*ArcTanh[(b - a*Tan[x/2])/Sqrt[a^2 + b^2]])/(a^2 + b^2)^(3/2) - (2*a*Cos[x/2]^2)/(a^2 + b^2) + (2*b*Cos[x/2]*Sin[x/2])/(a^2 + b^2)}
{Sin[x]^2/(a + b*Tan[x]), x, 6, (a^3*x)/(a^2 + b^2)^2 - (a*x)/(2*(a^2 + b^2)) + (a^2*b*Log[a*Cos[x] + b*Sin[x]])/(a^2 + b^2)^2 - (a*Cos[x]*Sin[x])/(2*(a^2 + b^2)) + (b*Sin[x]^2)/(2*(a^2 + b^2))}
{Sin[x]^3/(a + b*Tan[x]), x, 28, (a*b*(a^2 - 3*b^2)*ArcTanh[(b - a*Tan[x/2])/Sqrt[a^2 + b^2]])/(2*(a^2 + b^2)^(5/2)) + (3*a*b*ArcTanh[(b - a*Tan[x/2])/Sqrt[a^2 + b^2]])/(2*(a^2 + b^2)^(3/2)) - (3*a*Cos[x/2]^2)/(2*(a^2 + b^2)) + (a*(3*a^2 + 7*b^2)*Cos[x/2]^2)/(2*(a^2 + b^2)^2) - (4*a*Cos[x/2]^4)/(a^2 + b^2) + (8*a*Cos[x/2]^6)/(3*(a^2 + b^2)) - (4*a^2*b*Pi*Mods[x/(2*Pi)])/(a^2 + b^2)^2 - (4*b^3*Pi*Mods[x/(2*Pi)])/(a^2 + b^2)^2 + (4*b*Pi*Mods[x/(2*Pi)])/(a^2 + b^2) + (11*b*Cos[x/2]*Sin[x/2])/(2*(a^2 + b^2)) - (b*(7*a^2 + 11*b^2)*Cos[x/2]*Sin[x/2])/(2*(a^2 + b^2)^2) + (8*b*Cos[x/2]^3*Sin[x/2])/(3*(a^2 + b^2)) - (8*b*Cos[x/2]^5*Sin[x/2])/(3*(a^2 + b^2))}
{Sin[x]^4/(a + b*Tan[x]), x, 10, (a^5*x)/(a^2 + b^2)^3 + (3*a*x)/(8*(a^2 + b^2)) - (a*(2*a^2 + b^2)*x)/(2*(a^2 + b^2)^2) + (b*Cos[x]^4)/(4*(a^2 + b^2)) + (a^4*b*Log[a*Cos[x] + b*Sin[x]])/(a^2 + b^2)^3 + (3*a*Cos[x]*Sin[x])/(8*(a^2 + b^2)) - (a*(2*a^2 + b^2)*Cos[x]*Sin[x])/(2*(a^2 + b^2)^2) + (a*Cos[x]^3*Sin[x])/(4*(a^2 + b^2)) + (b*(2*a^2 + b^2)*Sin[x]^2)/(2*(a^2 + b^2)^2)}

{Sin[x]/(I + Tan[x]), x, 6, (1/3)*I*Cos[x]^3 + Sin[x]^3/3}
{Sin[x]^2/(I + Tan[x]), x, 6, -((I*x)/8) - (1/8)*I*Cos[x]*Sin[x] + (1/4)*I*Cos[x]^3*Sin[x] + Sin[x]^4/4}
{Sin[x]^3/(I + Tan[x]), x, 7, (1/3)*I*Cos[x]^3 - (1/5)*I*Cos[x]^5 + Sin[x]^5/5}
{Sin[x]^4/(I + Tan[x]), x, 7, -((I*x)/16) - (1/16)*I*Cos[x]*Sin[x] + (1/8)*I*Cos[x]^3*Sin[x] + (1/6)*I*Cos[x]^3*Sin[x]^3 + Sin[x]^6/6}


(* Integrands of the form Cos[x]^m/(a+b*Tan[x]) where m is a positive integer *)
{Cos[x]/(a + b*Tan[x]), x, 5, -((2*b^2*ArcTanh[(b - a*Tan[x/2])/Sqrt[a^2 + b^2]])/(a^2 + b^2)^(3/2)) + (b*Cos[x])/(a^2 + b^2) + (a*Sin[x])/(a^2 + b^2)}
{Cos[x]^2/(a + b*Tan[x]), x, 6, (a*b^2*x)/(a^2 + b^2)^2 + (a*x)/(2*(a^2 + b^2)) + (b^3*Log[a*Cos[x] + b*Sin[x]])/(a^2 + b^2)^2 + (a*Cos[x]*Sin[x])/(2*(a^2 + b^2)) - (b*Sin[x]^2)/(2*(a^2 + b^2))}
{Cos[x]^3/(a + b*Tan[x]), x, 10, -((2*b^4*ArcTanh[(b - a*Tan[x/2])/Sqrt[a^2 + b^2]])/(a^2 + b^2)^(5/2)) + (b^3*Cos[x])/(a^2 + b^2)^2 + (b*Cos[x]^3)/(3*(a^2 + b^2)) + (a*b^2*Sin[x])/(a^2 + b^2)^2 + (a*Sin[x])/(a^2 + b^2) - (a*Sin[x]^3)/(3*(a^2 + b^2))}
{Cos[x]^4/(a + b*Tan[x]), x, 11, (a*b^4*x)/(a^2 + b^2)^3 + (a*b^2*x)/(2*(a^2 + b^2)^2) + (3*a*x)/(8*(a^2 + b^2)) + (b*Cos[x]^4)/(4*(a^2 + b^2)) + (b^5*Log[a*Cos[x] + b*Sin[x]])/(a^2 + b^2)^3 + (a*b^2*Cos[x]*Sin[x])/(2*(a^2 + b^2)^2) + (3*a*Cos[x]*Sin[x])/(8*(a^2 + b^2)) + (a*Cos[x]^3*Sin[x])/(4*(a^2 + b^2)) - (b^3*Sin[x]^2)/(2*(a^2 + b^2)^2)}

{Cos[x]/(I + Tan[x]), x, 8, (-(1/3))*Cos[x]^3 - I*Sin[x] + (1/3)*I*Sin[x]^3}
{Cos[x]^2/(I + Tan[x]), x, 8, -((3*I*x)/8) - Cos[x]^4/4 - (3/8)*I*Cos[x]*Sin[x] - (1/4)*I*Cos[x]^3*Sin[x]}
{Cos[x]^3/(I + Tan[x]), x, 8, (-(1/5))*Cos[x]^5 - I*Sin[x] + (2/3)*I*Sin[x]^3 - (1/5)*I*Sin[x]^5}
{Cos[x]^4/(I + Tan[x]), x, 9, -((5*I*x)/16) - Cos[x]^6/6 - (5/16)*I*Cos[x]*Sin[x] - (5/24)*I*Cos[x]^3*Sin[x] - (1/6)*I*Cos[x]^5*Sin[x]}


(* Integrands of the form Tan[x]^m/(a+b*Tan[x]) where m is a positive integer *)
{Tan[x]/(a + b*Tan[x]), x, 2, (b*x)/(a^2 + b^2) - (a*Log[a*Cos[x] + b*Sin[x]])/(a^2 + b^2)}
{Tan[x]^2/(a + b*Tan[x]), x, 4, -((a*x)/(a^2 + b^2)) - Log[Cos[x]]/b + (a^2*Log[a*Cos[x] + b*Sin[x]])/(b*(a^2 + b^2))}
{Tan[x]^3/(a + b*Tan[x]), x, 5, -((b*x)/(a^2 + b^2)) + (a*Log[Cos[x]])/b^2 - (a^3*Log[a*Cos[x] + b*Sin[x]])/(b^2*(a^2 + b^2)) + Tan[x]/b}
{Tan[x]^4/(a + b*Tan[x]), x, 7, (a*x)/(a^2 + b^2) - (a^2*Log[Cos[x]])/b^3 + Log[Cos[x]]/b + (a^4*Log[a*Cos[x] + b*Sin[x]])/(b^3*(a^2 + b^2)) - (a*Tan[x])/b^2 + Tan[x]^2/(2*b)}

{Tan[x]/(I + Tan[x]), x, 2, x/2 - 1/(2*(I + Tan[x]))}
{Tan[x]^2/(I + Tan[x]), x, 4, -((I*x)/2) - Log[Cos[x]] + I/(2*(I + Tan[x]))}
{Tan[x]^3/(I + Tan[x]), x, 5, -((3*x)/2) + I*Log[Cos[x]] + Tan[x] + 1/(2*(I + Tan[x]))}
{Tan[x]^4/(I + Tan[x]), x, 7, (3*I*x)/2 + 2*Log[Cos[x]] - I*Tan[x] + Tan[x]^2/2 - I/(2*(I + Tan[x]))}


(* Integrands of the form Cot[x]^m/(a+b*Tan[x]) where m is a positive integer *)
{Cot[x]/(a + b*Tan[x]), x, 4, -((b*x)/(a^2 + b^2)) + Log[Sin[x]]/a - (b^2*Log[a*Cos[x] + b*Sin[x]])/(a*(a^2 + b^2))}
{Cot[x]^2/(a + b*Tan[x]), x, 5, -((a*x)/(a^2 + b^2)) - Cot[x]/a - (b*Log[Sin[x]])/a^2 + (b^3*Log[a*Cos[x] + b*Sin[x]])/(a^2*(a^2 + b^2))}
{Cot[x]^3/(a + b*Tan[x]), x, 7, (b*x)/(a^2 + b^2) + (b*Cot[x])/a^2 - Cot[x]^2/(2*a) - ((a^2 - b^2)*Log[Sin[x]])/a^3 - (b^4*Log[a*Cos[x] + b*Sin[x]])/(a^3*(a^2 + b^2)), (b*x)/(a^2 + b^2) + (b*Cot[x])/a^2 - Cot[x]^2/(2*a) - Log[Sin[x]]/a + (b^2*Log[Sin[x]])/a^3 - (b^4*Log[a*Cos[x] + b*Sin[x]])/(a^3*(a^2 + b^2))}
{Cot[x]^4/(a + b*Tan[x]), x, 9, (a*x)/(a^2 + b^2) + Cot[x]/a - (b^2*Cot[x])/a^3 + (b*Cot[x]^2)/(2*a^2) - Cot[x]^3/(3*a) + (b*Log[Sin[x]])/a^2 - (b^3*Log[Sin[x]])/a^4 + (b^5*Log[a*Cos[x] + b*Sin[x]])/(a^4*(a^2 + b^2))}

{Cot[x]/(I + Tan[x]), x, 4, x/2 - I*Log[Sin[x]] + 1/(2*(I + Tan[x]))}
{Cot[x]^2/(I + Tan[x]), x, 5, (3*I*x)/2 + I*Cot[x] + Log[Sin[x]] + I/(2*(I + Tan[x]))}
{Cot[x]^3/(I + Tan[x]), x, 7, -((3*x)/2) - Cot[x] + (1/2)*I*Cot[x]^2 + 2*I*Log[Sin[x]] - 1/(2*(I + Tan[x]))}
{Cot[x]^4/(I + Tan[x]), x, 9, -((5*I*x)/2) - 2*I*Cot[x] - Cot[x]^2/2 + (1/3)*I*Cot[x]^3 - 2*Log[Sin[x]] - I/(2*(I + Tan[x]))}


(* Integrands of the form Sec[x]^m/(a+b*Tan[x]) where m is a positive integer *)
{Sec[x]/(a + b*Tan[x]), x, 2, -((2*ArcTanh[(b - a*Tan[x/2])/Sqrt[a^2 + b^2]])/Sqrt[a^2 + b^2])}
{Sec[x]^2/(a + b*Tan[x]), x, 2, Log[a + b*Tan[x]]/b}
{Sec[x]^3/(a + b*Tan[x]), x, 8, -((2*a*ArcTanh[Tan[x/2]])/b^2) - (2*Sqrt[a^2 + b^2]*ArcTanh[(b - a*Tan[x/2])/Sqrt[a^2 + b^2]])/b^2 + 1/(b*(1 - Tan[x/2])) + 1/(b*(1 + Tan[x/2]))}
{Sec[x]^4/(a + b*Tan[x]), x, 5, ((a^2 + b^2)*Log[a + b*Tan[x]])/b^3 - (a*Tan[x])/b^2 + Tan[x]^2/(2*b)}

{Sec[x]/(I + Tan[x]), x, 2, I*(I*Cos[x] - Sin[x])}
{Sec[x]^2/(I + Tan[x]), x, 2, Log[I + Tan[x]]}
{Sec[x]^3/(I + Tan[x]), x, 4, (-I)*ArcTanh[Sin[x]] + Sec[x]}
{Sec[x]^4/(I + Tan[x]), x, 2, (-I)*Tan[x] + Tan[x]^2/2}


(* Integrands of the form Csc[x]^m/(a+b*Tan[x]) where m is a positive integer *)
{Csc[x]/(a + b*Tan[x]), x, 4, -(ArcTanh[Cos[x]]/a) + (2*b*ArcTanh[(b - a*Tan[x/2])/Sqrt[a^2 + b^2]])/(a*Sqrt[a^2 + b^2])}
{Csc[x]^2/(a + b*Tan[x]), x, 4, -(Cot[x]/a) + (b*Log[b + a*Cot[x]])/a^2}
{Csc[x]^3/(a + b*Tan[x]), x, 6, (2*b*Sqrt[a^2 + b^2]*ArcTanh[(b - a*Tan[x/2])/Sqrt[a^2 + b^2]])/a^3 + (b*Cot[x/2])/(2*a^2) - Cot[x/2]^2/(8*a) + ((a^2 + 2*b^2)*Log[Tan[x/2]])/(2*a^3) + (b*Tan[x/2])/(2*a^2) + Tan[x/2]^2/(8*a)}
{Csc[x]^4/(a + b*Tan[x]), x, 5, -(((a^2 + b^2)*Cot[x])/a^3) + (b*Cot[x]^2)/(2*a^2) - Cot[x]^3/(3*a) + (b*(a^2 + b^2)*Log[b + a*Cot[x]])/a^4}

{Csc[x]/(I + Tan[x]), x, 4, I*ArcTanh[Cos[x]]-I*Cos[x]+Sin[x]}
{Csc[x]^2/(I + Tan[x]), x, 4, I*Cot[x] - Log[-I + Cot[x]]}
{Csc[x]^3/(I + Tan[x]), x, 5, (-(1/2))*I*ArcTanh[Cos[x]] - Csc[x] + (1/2)*I*Cot[x]*Csc[x]}
{Csc[x]^4/(I + Tan[x]), x, 2, (-(1/2))*Cot[x]^2 + (1/3)*I*Cot[x]^3}

(* Following hangs Mathematica 6 & 7: *) 
{Csc[x]/(1 + Tan[x]), x, 4, -ArcTanh[Cos[x]] + Sqrt[2]*ArcTanh[(1 - Tan[x/2])/Sqrt[2]]}


(* ::Subsubsection::Closed:: *)
(*Integrands of the form Trig[x]^m / (a+b Cot[x])*)


(* Integrands of the form Sin[x]^m/(a+b*Cot[x]) where m is a positive integer *)
{Sin[x]/(a + b*Cot[x]), x, 5, -((2*b^2*ArcTanh[(a - b*Tan[x/2])/Sqrt[a^2 + b^2]])/(a^2 + b^2)^(3/2)) - (a*Cos[x])/(a^2 + b^2) - (b*Sin[x])/(a^2 + b^2)}
{Sin[x]^2/(a + b*Cot[x]), x, 6, (a*b^2*x)/(a^2 + b^2)^2 + (a*x)/(2*(a^2 + b^2)) - (b^3*Log[b*Cos[x] + a*Sin[x]])/(a^2 + b^2)^2 - (a*Cos[x]*Sin[x])/(2*(a^2 + b^2)) - (b*Sin[x]^2)/(2*(a^2 + b^2))}
{Sin[x]^3/(a + b*Cot[x]), x, 10, -((2*b^4*ArcTanh[(a - b*Tan[x/2])/Sqrt[a^2 + b^2]])/(a^2 + b^2)^(5/2)) - (a*b^2*Cos[x])/(a^2 + b^2)^2 - (a*Cos[x])/(a^2 + b^2) + (a*Cos[x]^3)/(3*(a^2 + b^2)) - (b^3*Sin[x])/(a^2 + b^2)^2 - (b*Sin[x]^3)/(3*(a^2 + b^2))}
{Sin[x]^4/(a + b*Cot[x]), x, 11, (a*b^4*x)/(a^2 + b^2)^3 + (a*b^2*x)/(2*(a^2 + b^2)^2) + (3*a*x)/(8*(a^2 + b^2)) - (b^5*Log[b*Cos[x] + a*Sin[x]])/(a^2 + b^2)^3 - (a*b^2*Cos[x]*Sin[x])/(2*(a^2 + b^2)^2) - (3*a*Cos[x]*Sin[x])/(8*(a^2 + b^2)) - (b^3*Sin[x]^2)/(2*(a^2 + b^2)^2) - (a*Cos[x]*Sin[x]^3)/(4*(a^2 + b^2)) - (b*Sin[x]^4)/(4*(a^2 + b^2))}

{Sin[x]/(I + Cot[x]), x, 8, I*Cos[x] - (1/3)*I*Cos[x]^3 + Sin[x]^3/3}
{Sin[x]^2/(I + Cot[x]), x, 8, -((3*I*x)/8) + (3/8)*I*Cos[x]*Sin[x] + (1/4)*I*Cos[x]*Sin[x]^3 + Sin[x]^4/4}
{Sin[x]^3/(I + Cot[x]), x, 8, I*Cos[x] - (2/3)*I*Cos[x]^3 + (1/5)*I*Cos[x]^5 + Sin[x]^5/5}
{Sin[x]^4/(I + Cot[x]), x, 9, -((5*I*x)/16) + (5/16)*I*Cos[x]*Sin[x] + (5/24)*I*Cos[x]*Sin[x]^3 + (1/6)*I*Cos[x]*Sin[x]^5 + Sin[x]^6/6}


(* Integrands of the form Sin[x]^m/(a+b*Cot[x]) where m is a positive integer *)
{Cos[x]/(a + b*Cot[x]), x, 9, (a*b*ArcTanh[(a*Cos[x] - b*Sin[x])/Sqrt[a^2 + b^2]])/(a^2 + b^2)^(3/2) - (b*Cos[x])/(a^2 + b^2) + (a*Sin[x])/(a^2 + b^2), (2*a*b*ArcTanh[(a - b*Tan[x/2])/Sqrt[a^2 + b^2]])/(a^2 + b^2)^(3/2) - (2*b*Cos[x/2]^2)/(a^2 + b^2) + (2*a*Cos[x/2]*Sin[x/2])/(a^2 + b^2)}
{Cos[x]^2/(a + b*Cot[x]), x, 6, -((a*b^2*x)/(a^2 + b^2)^2) + (a*x)/(2*(a^2 + b^2)) - (a^2*b*Log[b*Cos[x] + a*Sin[x]])/(a^2 + b^2)^2 + (a*Cos[x]*Sin[x])/(2*(a^2 + b^2)) + (b*Sin[x]^2)/(2*(a^2 + b^2))}
{Cos[x]^3/(a + b*Cot[x]), x, 29, (a*b*(a^2 - 3*b^2)*ArcTanh[(a - b*Tan[x/2])/Sqrt[a^2 + b^2]])/(2*(a^2 + b^2)^(5/2)) + (3*a*b*ArcTanh[(a - b*Tan[x/2])/Sqrt[a^2 + b^2]])/(2*(a^2 + b^2)^(3/2)) - (3*b*Cos[x/2]^2)/(2*(a^2 + b^2)) - (b*(5*a^2 + b^2)*Cos[x/2]^2)/(2*(a^2 + b^2)^2) + (4*b*Cos[x/2]^4)/(a^2 + b^2) - (8*b*Cos[x/2]^6)/(3*(a^2 + b^2)) + (4*a^3*Pi*Mods[x/(2*Pi)])/(a^2 + b^2)^2 + (4*a*b^2*Pi*Mods[x/(2*Pi)])/(a^2 + b^2)^2 - (4*a*Pi*Mods[x/(2*Pi)])/(a^2 + b^2) - (5*a*Cos[x/2]*Sin[x/2])/(2*(a^2 + b^2)) + (a*(9*a^2 + 5*b^2)*Cos[x/2]*Sin[x/2])/(2*(a^2 + b^2)^2) - (8*a*Cos[x/2]^3*Sin[x/2])/(3*(a^2 + b^2)) + (8*a*Cos[x/2]^5*Sin[x/2])/(3*(a^2 + b^2))}
{Cos[x]^4/(a + b*Cot[x]), x, 10, -((a^3*b^2*x)/(a^2 + b^2)^3) - (a*b^2*x)/(2*(a^2 + b^2)^2) + (3*a*x)/(8*(a^2 + b^2)) - (b*Cos[x]^4)/(4*(a^2 + b^2)) - (a^4*b*Log[b*Cos[x] + a*Sin[x]])/(a^2 + b^2)^3 - (a*b^2*Cos[x]*Sin[x])/(2*(a^2 + b^2)^2) + (3*a*Cos[x]*Sin[x])/(8*(a^2 + b^2)) + (a*Cos[x]^3*Sin[x])/(4*(a^2 + b^2)) + (a^2*b*Sin[x]^2)/(2*(a^2 + b^2)^2)}

{Cos[x]/(I + Cot[x]), x, 6, (-(1/3))*Cos[x]^3 - (1/3)*I*Sin[x]^3}
{Cos[x]^2/(I + Cot[x]), x, 6, -((I*x)/8) - Cos[x]^4/4 - (1/8)*I*Cos[x]*Sin[x] + (1/4)*I*Cos[x]^3*Sin[x]}
{Cos[x]^3/(I + Cot[x]), x, 7, (-(1/5))*Cos[x]^5 - (1/3)*I*Sin[x]^3 + (1/5)*I*Sin[x]^5}
{Cos[x]^4/(I + Cot[x]), x, 7, -((I*x)/16) - Cos[x]^6/6 - (1/16)*I*Cos[x]*Sin[x] - (1/24)*I*Cos[x]^3*Sin[x] + (1/6)*I*Cos[x]^5*Sin[x]}


(* Integrands of the form Sin[x]^m/(a+b*Cot[x]) where m is a positive integer *)
{Tan[x]/(a + b*Cot[x]), x, 4, -((b*x)/(a^2 + b^2)) - Log[Cos[x]]/a + (b^2*Log[b*Cos[x] + a*Sin[x]])/(a*(a^2 + b^2))}
{Tan[x]^2/(a + b*Cot[x]), x, 5, -((a*x)/(a^2 + b^2)) + (b*Log[Cos[x]])/a^2 - (b^3*Log[b*Cos[x] + a*Sin[x]])/(a^2*(a^2 + b^2)) + Tan[x]/a}
{Tan[x]^3/(a + b*Cot[x]), x, 7, (b*x)/(a^2 + b^2) + Log[Cos[x]]/a - (b^2*Log[Cos[x]])/a^3 + (b^4*Log[b*Cos[x] + a*Sin[x]])/(a^3*(a^2 + b^2)) - (b*Tan[x])/a^2 + Tan[x]^2/(2*a)}
{Tan[x]^4/(a + b*Cot[x]), x, 9, (a*x)/(a^2 + b^2) - (b*Log[Cos[x]])/a^2 + (b^3*Log[Cos[x]])/a^4 - (b^5*Log[b*Cos[x] + a*Sin[x]])/(a^4*(a^2 + b^2)) - Tan[x]/a + (b^2*Tan[x])/a^3 - (b*Tan[x]^2)/(2*a^2) + Tan[x]^3/(3*a)}

{Tan[x]/(I + Cot[x]), x, 4, x/2 + I*Log[Cos[x]] + 1/(2*(I - Tan[x]))}
{Tan[x]^2/(I + Cot[x]), x, 5, (3*I*x)/2 - Log[Cos[x]] + I/(2*(I - Tan[x])) - I*Tan[x]}
{Tan[x]^3/(I + Cot[x]), x, 7, -((3*x)/2) - 2*I*Log[Cos[x]] - 1/(2*(I - Tan[x])) + Tan[x] - (1/2)*I*Tan[x]^2}
{Tan[x]^4/(I + Cot[x]), x, 9, -((5*I*x)/2) + 2*Log[Cos[x]] - I/(2*(I - Tan[x])) + 2*I*Tan[x] + Tan[x]^2/2 - (1/3)*I*Tan[x]^3}


(* Integrands of the form Sin[x]^m/(a+b*Cot[x]) where m is a positive integer *)
{Cot[x]/(a + b*Cot[x]), x, 2, (b*x)/(a^2 + b^2) + (a*Log[b*Cos[x] + a*Sin[x]])/(a^2 + b^2)}
{Cot[x]^2/(a + b*Cot[x]), x, 4, -((a*x)/(a^2 + b^2)) + Log[Sin[x]]/b - (a^2*Log[b*Cos[x] + a*Sin[x]])/(b*(a^2 + b^2))}
{Cot[x]^3/(a + b*Cot[x]), x, 5, -((b*x)/(a^2 + b^2)) - Cot[x]/b - (a*Log[Sin[x]])/b^2 + (a^3*Log[b*Cos[x] + a*Sin[x]])/(b^2*(a^2 + b^2))}
{Cot[x]^4/(a + b*Cot[x]), x, 7, (a*x)/(a^2 + b^2) + (a*Cot[x])/b^2 - Cot[x]^2/(2*b) + (a^2*Log[Sin[x]])/b^3 - Log[Sin[x]]/b - (a^4*Log[b*Cos[x] + a*Sin[x]])/(b^3*(a^2 + b^2))}

{Cot[x]/(I + Cot[x]), x, 2, x/2 + 1/(2*(I + Cot[x]))}
{Cot[x]^2/(I + Cot[x]), x, 4, -((I*x)/2) + Log[Sin[x]] + I/(2*(I - Tan[x]))}
{Cot[x]^3/(I + Cot[x]), x, 5, -((3*x)/2) - Cot[x] - I*Log[Sin[x]] + 1/(2*(I - Tan[x]))}
{Cot[x]^4/(I + Cot[x]), x, 7, (3*I*x)/2 + I*Cot[x] - Cot[x]^2/2 - 2*Log[Sin[x]] - I/(2*(I - Tan[x]))}


(* Integrands of the form Sin[x]^m/(a+b*Cot[x]) where m is a positive integer *)
{Sec[x]/(a + b*Cot[x]), x, 4, ArcTanh[Sin[x]]/a + (2*b*ArcTanh[(a - b*Tan[x/2])/Sqrt[a^2 + b^2]])/(a*Sqrt[a^2 + b^2])}
{Sec[x]^2/(a + b*Cot[x]), x, 4, -((b*Log[b + a*Tan[x]])/a^2) + Tan[x]/a}
{Sec[x]^3/(a + b*Cot[x]), x, 10, ((a^2 + 2*b^2)*ArcTanh[Tan[x/2]])/a^3 + (2*b*Sqrt[a^2 + b^2]*ArcTanh[(a - b*Tan[x/2])/Sqrt[a^2 + b^2]])/a^3 + 1/(2*a*(1 - Tan[x/2])^2) - (a + 2*b)/(2*a^2*(1 - Tan[x/2])) - 1/(2*a*(1 + Tan[x/2])^2) + (a - 2*b)/(2*a^2*(1 + Tan[x/2]))}
{Sec[x]^4/(a + b*Cot[x]), x, 5, -((b*(a^2 + b^2)*Log[b + a*Tan[x]])/a^4) + ((a^2 + b^2)*Tan[x])/a^3 - (b*Tan[x]^2)/(2*a^2) + Tan[x]^3/(3*a)}

{Sec[x]/(I + Cot[x]), x, 4, (-I)*ArcTanh[Sin[x]] - Cos[x] + I*Sin[x]}
{Sec[x]^2/(I + Cot[x]), x, 4, Log[-I + Tan[x]] - I*Tan[x]}
{Sec[x]^3/(I + Cot[x]), x, 5, (1/2)*I*ArcTanh[Sin[x]] + Sec[x] - (1/2)*I*Sec[x]*Tan[x]}
{Sec[x]^4/(I + Cot[x]), x, 2, Tan[x]^2/2 - (1/3)*I*Tan[x]^3}

(* Following hangs Mathematica 6 & 7: *) 
{Sec[x]/(1 + 2*Cot[x]), x, 4, ArcTanh[Sin[x]] + (4*ArcTanh[(1 - 2*Tan[x/2])/Sqrt[5]])/Sqrt[5]}


(* Integrands of the form Sin[x]^m/(a+b*Cot[x]) where m is a positive integer *)
{Csc[x]/(a + b*Cot[x]), x, 2, -((2*ArcTanh[(a - b*Tan[x/2])/Sqrt[a^2 + b^2]])/Sqrt[a^2 + b^2])}
{Csc[x]^2/(a + b*Cot[x]), x, 2, -(Log[a + b*Cot[x]]/b)}
{Csc[x]^3/(a + b*Cot[x]), x, 6, -((2*Sqrt[a^2 + b^2]*ArcTanh[(a - b*Tan[x/2])/Sqrt[a^2 + b^2]])/b^2) - Cot[x/2]/(2*b) - (a*Log[Tan[x/2]])/b^2 - Tan[x/2]/(2*b)}
{Csc[x]^4/(a + b*Cot[x]), x, 5, (a*Cot[x])/b^2 - Cot[x]^2/(2*b) - ((a^2 + b^2)*Log[a + b*Cot[x]])/b^3}

{Csc[x]/(I + Cot[x]), x, 2, I*(Cos[x] - I*Sin[x])}
{Csc[x]^2/(I + Cot[x]), x, 2, -Log[I + Cot[x]]}
{Csc[x]^3/(I + Cot[x]), x, 4, I*ArcTanh[Cos[x]] - Csc[x]}
{Csc[x]^4/(I + Cot[x]), x, 2, I*Cot[x] - Cot[x]^2/2}


(* ::Subsection::Closed:: *)
(*Integrands of the form Trig[x]^m / (a+b Trig[x])^2*)


(* ::Subsubsection::Closed:: *)
(*Integrands of the form Trig[x]^m / (a+b Tan[x])^2*)


{Sec[x]^2/(a + b*Tan[x])^2, x, 2, -(1/(b*(a + b*Tan[x])))}


(* ::Subsubsection::Closed:: *)
(*Integrands of the form Trig[x]^m / (a+b Cot[x])^2*)


{Csc[x]^2/(a + b*Cot[x])^2, x, 2, 1/(b*(a + b*Cot[x]))}


(* ::Subsection::Closed:: *)
(*Integrands of the form Trig[x]^m / (a+b Trig[x]^2)*)


(* ::Subsubsection::Closed:: *)
(*Integrands of the form Trig[x]^m / (a+b Sin[x]^2)*)


(* Integrands of the form Sin[x]^m/(a+b*Sin[x]^2) where m is a positive integer *)
{Sin[x]/(a + b*Sin[x]^2), x, 2, -(ArcTanh[(Sqrt[b]*Cos[x])/Sqrt[a + b]]/(Sqrt[b]*Sqrt[a + b]))}
{Sin[x]^2/(a + b*Sin[x]^2), x, 4, x/b + (Sqrt[a]*ArcTan[(Sqrt[a]*Cot[x])/Sqrt[a + b]])/(b*Sqrt[a + b])}
{Sin[x]^3/(a + b*Sin[x]^2), x, 4, (a*ArcTanh[(Sqrt[b]*Cos[x])/Sqrt[a + b]])/(b^(3/2)*Sqrt[a + b]) - Cos[x]/b}
{Sin[x]^4/(a + b*Sin[x]^2), x, 5, -((a*x)/b^2) + x/(2*b) - (a^(3/2)*ArcTan[(Sqrt[a]*Cot[x])/Sqrt[a + b]])/(b^2*Sqrt[a + b]) - (Cos[x]*Sin[x])/(2*b)}
{Sin[x]^5/(a + b*Sin[x]^2), x, 6, -((a^2*ArcTanh[(Sqrt[b]*Cos[x])/Sqrt[a + b]])/(b^(5/2)*Sqrt[a + b])) + (a*Cos[x])/b^2 - Cos[x]/b + Cos[x]^3/(3*b)}
{Sin[x]^6/(a + b*Sin[x]^2), x, 7, (a^2*x)/b^3 - (a*x)/(2*b^2) + (3*x)/(8*b) + (a^(5/2)*ArcTan[(Sqrt[a]*Cot[x])/Sqrt[a + b]])/(b^3*Sqrt[a + b]) + (a*Cos[x]*Sin[x])/(2*b^2) - (3*Cos[x]*Sin[x])/(8*b) - (Cos[x]*Sin[x]^3)/(4*b)}
{Sin[x]^7/(a + b*Sin[x]^2), x, 10, (a^3*ArcTanh[(Sqrt[b]*Cos[x])/Sqrt[a + b]])/(b^(7/2)*Sqrt[a + b]) - (a^2*Cos[x])/b^3 + (a*Cos[x])/b^2 - Cos[x]/b - (a*Cos[x]^3)/(3*b^2) + (2*Cos[x]^3)/(3*b) - Cos[x]^5/(5*b)}
(* {Sin[x]^8/(a + b*Sin[x]^2), x, 9, -((a^3*x)/b^4) + (a^2*x)/(2*b^3) - (3*a*x)/(8*b^2) + (5*x)/(16*b) + (a^(7/2)*ArcTan[(Sqrt[a + b]*Tan[x])/Sqrt[a]])/(b^4*Sqrt[a + b]) - (a^2*Cos[x]*Sin[x])/(2*b^3) + (3*a*Cos[x]*Sin[x])/(8*b^2) - (5*Cos[x]*Sin[x])/(16*b) + (a*Cos[x]*Sin[x]^3)/(4*b^2) - (5*Cos[x]*Sin[x]^3)/(24*b) - (Cos[x]*Sin[x]^5)/(6*b)} *)


(* Integrands of the form Cos[x]^m/(a+b*Sin[x]^2) where m is a positive integer *)
{Cos[x]/(a + b*Sin[x]^2), x, 2, ArcTan[(Sqrt[b]*Sin[x])/Sqrt[a]]/(Sqrt[a]*Sqrt[b])}
{Cos[x]^2/(a + b*Sin[x]^2), x, 4, -(x/b) - (Sqrt[a + b]*ArcTan[(Sqrt[a]*Cot[x])/Sqrt[a + b]])/(Sqrt[a]*b)}
{Cos[x]^3/(a + b*Sin[x]^2), x, 4, ((a + b)*ArcTan[(Sqrt[b]*Sin[x])/Sqrt[a]])/(Sqrt[a]*b^(3/2)) - Sin[x]/b}
{Cos[x]^4/(a + b*Sin[x]^2), x, 5, -((a*x)/b^2) - (3*x)/(2*b) - ((a + b)^(3/2)*ArcTan[(Sqrt[a]*Cot[x])/Sqrt[a + b]])/(Sqrt[a]*b^2) - (Cos[x]*Sin[x])/(2*b)}
{Cos[x]^5/(a + b*Sin[x]^2), x, 6, ((a + b)^2*ArcTan[(Sqrt[b]*Sin[x])/Sqrt[a]])/(Sqrt[a]*b^(5/2)) - (a*Sin[x])/b^2 - (2*Sin[x])/b + Sin[x]^3/(3*b)}
{Cos[x]^6/(a + b*Sin[x]^2), x, 7, -((a*x)/(2*b^2)) - (7*x)/(8*b) - ((a + b)^2*x)/b^3 - ((a + b)^(5/2)*ArcTan[(Sqrt[a]*Cot[x])/Sqrt[a + b]])/(Sqrt[a]*b^3) - (a*Cos[x]*Sin[x])/(2*b^2) - (7*Cos[x]*Sin[x])/(8*b) - (Cos[x]^3*Sin[x])/(4*b)}
{Cos[x]^7/(a + b*Sin[x]^2), x, 10, ((a + b)^3*ArcTan[(Sqrt[b]*Sin[x])/Sqrt[a]])/(Sqrt[a]*b^(7/2)) - (a*Sin[x])/b^2 - (2*Sin[x])/b - ((a + b)^2*Sin[x])/b^3 + (a*Sin[x]^3)/(3*b^2) + Sin[x]^3/b - Sin[x]^5/(5*b)}
(* {Cos[x]^8/(a + b*Sin[x]^2), x, 9, -((3*a*x)/(8*b^2)) - (11*x)/(16*b) - ((a + b)^2*x)/(2*b^3) - ((a + b)^3*x)/b^4 + ((a + b)^(7/2)*ArcTan[(Sqrt[a + b]*Tan[x])/Sqrt[a]])/(Sqrt[a]*b^4) - (3*a*Cos[x]*Sin[x])/(8*b^2) - (11*Cos[x]*Sin[x])/(16*b) - ((a + b)^2*Cos[x]*Sin[x])/(2*b^3) - (a*Cos[x]^3*Sin[x])/(4*b^2) - (11*Cos[x]^3*Sin[x])/(24*b) - (Cos[x]^5*Sin[x])/(6*b)} *)

{Cos[x]^2/(a - a*Sin[x]^2), x, 2, x/a}
{Cos[x]^3/(a - a*Sin[x]^2), x, 3, Sin[x]/a}
{Cos[x]^4/(a - a*Sin[x]^2), x, 3, x/(2*a) + (Cos[x]*Sin[x])/(2*a)}


{Cot[x]/(1 + Sin[x]^2), x, 2, -ArcTanh[1 + 2*Sin[x]^2]}


(* ::Subsubsection::Closed:: *)
(*Integrands of the form Trig[x]^m / (a+b Cos[x]^2)*)


(* Integrands of the form Sin[x]^m/(a+b*Cos[x]^2) where m is a positive integer *)
{Sin[x]/(a + b*Cos[x]^2), x, 2, -(ArcTan[(Sqrt[b]*Cos[x])/Sqrt[a]]/(Sqrt[a]*Sqrt[b]))}
{Sin[x]^2/(a + b*Cos[x]^2), x, 4, -(x/b) + (Sqrt[a + b]*ArcTan[(Sqrt[a]*Tan[x])/Sqrt[a + b]])/(Sqrt[a]*b)}
{Sin[x]^3/(a + b*Cos[x]^2), x, 4, -(((a + b)*ArcTan[(Sqrt[b]*Cos[x])/Sqrt[a]])/(Sqrt[a]*b^(3/2))) + Cos[x]/b}
{Sin[x]^4/(a + b*Cos[x]^2), x, 5, -((a*x)/b^2) - (3*x)/(2*b) + ((a + b)^(3/2)*ArcTan[(Sqrt[a]*Tan[x])/Sqrt[a + b]])/(Sqrt[a]*b^2) + (Cos[x]*Sin[x])/(2*b)}
{Sin[x]^5/(a + b*Cos[x]^2), x, 6, -(((a + b)^2*ArcTan[(Sqrt[b]*Cos[x])/Sqrt[a]])/(Sqrt[a]*b^(5/2))) + (a*Cos[x])/b^2 + (2*Cos[x])/b - Cos[x]^3/(3*b)}
{Sin[x]^6/(a + b*Cos[x]^2), x, 7, -((a*x)/(2*b^2)) - (7*x)/(8*b) - ((a + b)^2*x)/b^3 + ((a + b)^(5/2)*ArcTan[(Sqrt[a]*Tan[x])/Sqrt[a + b]])/(Sqrt[a]*b^3) + (a*Cos[x]*Sin[x])/(2*b^2) + (7*Cos[x]*Sin[x])/(8*b) + (Cos[x]*Sin[x]^3)/(4*b)}
{Sin[x]^7/(a + b*Cos[x]^2), x, 10, -(((a + b)^3*ArcTan[(Sqrt[b]*Cos[x])/Sqrt[a]])/(Sqrt[a]*b^(7/2))) + (a*Cos[x])/b^2 + (2*Cos[x])/b + ((a + b)^2*Cos[x])/b^3 - (a*Cos[x]^3)/(3*b^2) - Cos[x]^3/b + Cos[x]^5/(5*b)}
(* {Sin[x]^8/(a + b*Cos[x]^2), x, 9, -((3*a*x)/(8*b^2)) - (11*x)/(16*b) - ((a + b)^2*x)/(2*b^3) - ((a + b)^3*x)/b^4 + ((a + b)^(7/2)*ArcTan[(Sqrt[a]*Tan[x])/Sqrt[a + b]])/(Sqrt[a]*b^4) + (3*a*Cos[x]*Sin[x])/(8*b^2) + (11*Cos[x]*Sin[x])/(16*b) + ((a + b)^2*Cos[x]*Sin[x])/(2*b^3) + (a*Cos[x]*Sin[x]^3)/(4*b^2) + (11*Cos[x]*Sin[x]^3)/(24*b) + (Cos[x]*Sin[x]^5)/(6*b)} *)

{Sin[x]^2/(a - a*Cos[x]^2), x, 2, x/a}
{Sin[x]^3/(a - a*Cos[x]^2), x, 3, -(Cos[x]/a)}
{Sin[x]^4/(a - a*Cos[x]^2), x, 3, x/(2*a) - (Cos[x]*Sin[x])/(2*a)}


(* Integrands of the form Cos[x]^m/(a+b*Cos[x]^2) where m is a positive integer *)
{Cos[x]/(a + b*Cos[x]^2), x, 2, ArcTanh[(Sqrt[b]*Sin[x])/Sqrt[a + b]]/(Sqrt[b]*Sqrt[a + b])}
{Cos[x]^2/(a + b*Cos[x]^2), x, 4, x/b - (Sqrt[a]*ArcTan[(Sqrt[a]*Tan[x])/Sqrt[a + b]])/(b*Sqrt[a + b])}
{Cos[x]^3/(a + b*Cos[x]^2), x, 4, -((a*ArcTanh[(Sqrt[b]*Sin[x])/Sqrt[a + b]])/(b^(3/2)*Sqrt[a + b])) + Sin[x]/b}
{Cos[x]^4/(a + b*Cos[x]^2), x, 5, -((a*x)/b^2) + x/(2*b) + (a^(3/2)*ArcTan[(Sqrt[a]*Tan[x])/Sqrt[a + b]])/(b^2*Sqrt[a + b]) + (Cos[x]*Sin[x])/(2*b)}
{Cos[x]^5/(a + b*Cos[x]^2), x, 6, (a^2*ArcTanh[(Sqrt[b]*Sin[x])/Sqrt[a + b]])/(b^(5/2)*Sqrt[a + b]) - (a*Sin[x])/b^2 + Sin[x]/b - Sin[x]^3/(3*b)}
{Cos[x]^6/(a + b*Cos[x]^2), x, 7, (a^2*x)/b^3 - (a*x)/(2*b^2) + (3*x)/(8*b) - (a^(5/2)*ArcTan[(Sqrt[a]*Tan[x])/Sqrt[a + b]])/(b^3*Sqrt[a + b]) - (a*Cos[x]*Sin[x])/(2*b^2) + (3*Cos[x]*Sin[x])/(8*b) + (Cos[x]^3*Sin[x])/(4*b)}
{Cos[x]^7/(a + b*Cos[x]^2), x, 10, -((a^3*ArcTanh[(Sqrt[b]*Sin[x])/Sqrt[a + b]])/(b^(7/2)*Sqrt[a + b])) + (a^2*Sin[x])/b^3 - (a*Sin[x])/b^2 + Sin[x]/b + (a*Sin[x]^3)/(3*b^2) - (2*Sin[x]^3)/(3*b) + Sin[x]^5/(5*b)}
(* {Cos[x]^8/(a + b*Cos[x]^2), x, 9, -((a^3*x)/b^4) + (a^2*x)/(2*b^3) - (3*a*x)/(8*b^2) + (5*x)/(16*b) + (a^(7/2)*ArcTan[(Sqrt[a]*Tan[x])/Sqrt[a + b]])/(b^4*Sqrt[a + b]) + (a^2*Cos[x]*Sin[x])/(2*b^3) - (3*a*Cos[x]*Sin[x])/(8*b^2) + (5*Cos[x]*Sin[x])/(16*b) - (a*Cos[x]^3*Sin[x])/(4*b^2) + (5*Cos[x]^3*Sin[x])/(24*b) + (Cos[x]^5*Sin[x])/(6*b)} *)


{Tan[x]/(1 + Cos[x]^2), x, 2, ArcTanh[1 + 2*Cos[x]^2]}


(* ::Subsubsection::Closed:: *)
(*Integrands of the form x^m Trig[x]^2 / (a+b Tan[x]^2)*)


{Sec[c + d*x]^2/(a + b*Tan[c + d*x]^2), x, 2, ArcTan[(Sqrt[b]*Tan[c + d*x])/Sqrt[a]]/(Sqrt[a]*Sqrt[b]*d)}
{x*Sec[c + d*x]^2/(a + b*Tan[c + d*x]^2), x, 10, -((I*x*Log[1 + ((a - b)*E^(2*I*c + 2*I*d*x))/(a - 2*Sqrt[a]*Sqrt[b] + b)])/(2*Sqrt[a]*Sqrt[b]*d)) + (I*x*Log[1 + ((a - b)*E^(2*I*c + 2*I*d*x))/(a + 2*Sqrt[a]*Sqrt[b] + b)])/(2*Sqrt[a]*Sqrt[b]*d) - PolyLog[2, -(((a - b)*E^(2*I*c + 2*I*d*x))/(a - 2*Sqrt[a]*Sqrt[b] + b))]/(4*Sqrt[a]*Sqrt[b]*d^2) + PolyLog[2, -(((a - b)*E^(2*I*c + 2*I*d*x))/(a + 2*Sqrt[a]*Sqrt[b] + b))]/(4*Sqrt[a]*Sqrt[b]*d^2)}
{x^2*Sec[c + d*x]^2/(a + b*Tan[c + d*x]^2), x, 12, -((I*x^2*Log[1 + ((a - b)*E^(2*I*c + 2*I*d*x))/(a - 2*Sqrt[a]*Sqrt[b] + b)])/(2*Sqrt[a]*Sqrt[b]*d)) + (I*x^2*Log[1 + ((a - b)*E^(2*I*c + 2*I*d*x))/(a + 2*Sqrt[a]*Sqrt[b] + b)])/(2*Sqrt[a]*Sqrt[b]*d) - (x*PolyLog[2, -(((a - b)*E^(2*I*c + 2*I*d*x))/(a - 2*Sqrt[a]*Sqrt[b] + b))])/(2*Sqrt[a]*Sqrt[b]*d^2) + (x*PolyLog[2, -(((a - b)*E^(2*I*c + 2*I*d*x))/(a + 2*Sqrt[a]*Sqrt[b] + b))])/(2*Sqrt[a]*Sqrt[b]*d^2) - (I*PolyLog[3, -(((a - b)*E^(2*I*c + 2*I*d*x))/(a - 2*Sqrt[a]*Sqrt[b] + b))])/(4*Sqrt[a]*Sqrt[b]*d^3) + (I*PolyLog[3, -(((a - b)*E^(2*I*c + 2*I*d*x))/(a + 2*Sqrt[a]*Sqrt[b] + b))])/(4*Sqrt[a]*Sqrt[b]*d^3)}


(* ::Subsection::Closed:: *)
(*Integrands of the form Trig[x]^m / (a+b Trig[x]^n)*)


(* ::Subsubsection::Closed:: *)
(*Integrands of the form Trig[x]^m / (a+b Sin[x]^3)*)


{Cot[x]^3/(a + b*Sin[x]^3), x, 10, (b^(2/3)*ArcTan[(a^(1/3) - 2*b^(1/3)*Sin[x])/(Sqrt[3]*a^(1/3))])/(Sqrt[3]*a^(5/3)) - Csc[x]^2/(2*a) - Log[Sin[x]]/a - (b^(2/3)*Log[a^(1/3) + b^(1/3)*Sin[x]])/(3*a^(5/3)) + (b^(2/3)*Log[a^(2/3) - a^(1/3)*b^(1/3)*Sin[x] + b^(2/3)*Sin[x]^2])/(6*a^(5/3)) + Log[a + b*Sin[x]^3]/(3*a)}


(* ::Subsubsection::Closed:: *)
(*Integrands of the form Trig[x]^m / (a+b Cos[x]^3)*)


{Sin[x]/(4 - 3*Cos[x]^3), x, 6, -(ArcTan[(6^(2/3) + 6*Cos[x])/(3*2^(2/3)*3^(1/6))]/(2*2^(1/3)*3^(5/6))) + Log[6^(2/3) - 3*Cos[x]]/(6*6^(1/3)) - Log[2*6^(1/3) + 6^(2/3)*Cos[x] + 3*Cos[x]^2]/(12*6^(1/3))}


{Tan[x]^3/(a + b*Cos[x]^3), x, 10, -((b^(2/3)*ArcTan[(a^(1/3) - 2*b^(1/3)*Cos[x])/(Sqrt[3]*a^(1/3))])/(Sqrt[3]*a^(5/3))) + Log[Cos[x]]/a + (b^(2/3)*Log[a^(1/3) + b^(1/3)*Cos[x]])/(3*a^(5/3)) - (b^(2/3)*Log[a^(2/3) - a^(1/3)*b^(1/3)*Cos[x] + b^(2/3)*Cos[x]^2])/(6*a^(5/3)) - Log[a + b*Cos[x]^3]/(3*a) + Sec[x]^2/(2*a)}


(* ::Subsection::Closed:: *)
(*Integrands of the form Trig[x]^m (a+b Trig[x])^n*)


(* ::Subsubsection::Closed:: *)
(*Integrands of the form Trig[x]^m (a+b Tan[x])^n*)


(* Integrands of the form Tan[x]^m*(1+Tan[x])^n where m is an integer and n is a half-integer *)
{Tan[x]*(1 + Tan[x])^(3/2), x, 5, (2*I*ArcTanh[Sqrt[1 + Tan[x]]/Sqrt[1 - I]])/Sqrt[1 - I] - (2*I*ArcTanh[Sqrt[1 + Tan[x]]/Sqrt[1 + I]])/Sqrt[1 + I] + 2*Sqrt[1 + Tan[x]] + (2/3)*(1 + Tan[x])^(3/2)}
{Tan[x]*Sqrt[1 + Tan[x]], x, 4, (-Sqrt[1 - I])*ArcTanh[Sqrt[1 + Tan[x]]/Sqrt[1 - I]] - Sqrt[1 + I]*ArcTanh[Sqrt[1 + Tan[x]]/Sqrt[1 + I]] + 2*Sqrt[1 + Tan[x]]}
{Tan[x]/Sqrt[1 + Tan[x]], x, 3, -(ArcTanh[Sqrt[1 + Tan[x]]/Sqrt[1 - I]]/Sqrt[1 - I]) - ArcTanh[Sqrt[1 + Tan[x]]/Sqrt[1 + I]]/Sqrt[1 + I]}
{Tan[x]/(1 + Tan[x])^(3/2), x, 4, -(ArcTanh[Sqrt[1 + Tan[x]]/Sqrt[1 - I]]/(1 - I)^(3/2)) - ArcTanh[Sqrt[1 + Tan[x]]/Sqrt[1 + I]]/(1 + I)^(3/2) + 1/Sqrt[1 + Tan[x]]}

{Tan[x]^2*(1 + Tan[x])^(3/2), x, 8, Sqrt[-1 + Sqrt[2]]*ArcTan[(Sqrt[-2 + 2*Sqrt[2]]*Sqrt[1 + Tan[x]])/(1 - Sqrt[2] + Tan[x])] + Sqrt[1 + Sqrt[2]]*ArcTanh[(Sqrt[2 + 2*Sqrt[2]]*Sqrt[1 + Tan[x]])/(1 + Sqrt[2] + Tan[x])] - 2*Sqrt[1 + Tan[x]] + (2/5)*(1 + Tan[x])^(5/2)}
{Tan[x]^2*Sqrt[1 + Tan[x]], x, 8, (1/2)*Sqrt[2 + 2*Sqrt[2]]*ArcTan[(Sqrt[-2 + 2*Sqrt[2]]*Sqrt[1 + Tan[x]])/(1 - Sqrt[2] + Tan[x])] + (1/2)*Sqrt[-2 + 2*Sqrt[2]]*ArcTanh[(Sqrt[2 + 2*Sqrt[2]]*Sqrt[1 + Tan[x]])/(1 + Sqrt[2] + Tan[x])] + (2/3)*(1 + Tan[x])^(3/2)}
{Tan[x]^2/Sqrt[1 + Tan[x]], x, 7, (1/2)*Sqrt[1 + Sqrt[2]]*ArcTan[(Sqrt[-2 + 2*Sqrt[2]]*Sqrt[1 + Tan[x]])/(1 - Sqrt[2] + Tan[x])] - (1/2)*Sqrt[-1 + Sqrt[2]]*ArcTanh[(Sqrt[2 + 2*Sqrt[2]]*Sqrt[1 + Tan[x]])/(1 + Sqrt[2] + Tan[x])] + 2*Sqrt[1 + Tan[x]]}
{Tan[x]^2/(1 + Tan[x])^(3/2), x, 8, (1/4)*Sqrt[-2 + 2*Sqrt[2]]*ArcTan[(Sqrt[-2 + 2*Sqrt[2]]*Sqrt[1 + Tan[x]])/(1 - Sqrt[2] + Tan[x])] - (1/4)*Sqrt[2 + 2*Sqrt[2]]*ArcTanh[(Sqrt[2 + 2*Sqrt[2]]*Sqrt[1 + Tan[x]])/(1 + Sqrt[2] + Tan[x])] - 1/Sqrt[1 + Tan[x]]}


{Sec[x]^2*(a + b*Tan[x])^n, x, 2, (a + b*Tan[x])^(1 + n)/(b*(1 + n))}


(* ::Subsubsection::Closed:: *)
(*Integrands of the form Trig[x]^m (a+b Cot[x])^n*)


(* Integrands of the form Cot[x]^m*(1+Cot[x])^n where m is an integer and n is a half-integer *)
{Cot[x]*(1 + Cot[x])^(3/2), x, 5, -((2*I*ArcCoth[Sqrt[1 + Cot[x]]/Sqrt[1 - I]])/Sqrt[1 - I]) + (2*I*ArcCoth[Sqrt[1 + Cot[x]]/Sqrt[1 + I]])/Sqrt[1 + I] - 2*Sqrt[1 + Cot[x]] - (2/3)*(1 + Cot[x])^(3/2)}
{Cot[x]*Sqrt[1 + Cot[x]], x, 4, Sqrt[1 - I]*ArcCoth[Sqrt[1 + Cot[x]]/Sqrt[1 - I]] + Sqrt[1 + I]*ArcCoth[Sqrt[1 + Cot[x]]/Sqrt[1 + I]] - 2*Sqrt[1 + Cot[x]]}
{Cot[x]/Sqrt[1 + Cot[x]], x, 3, ArcCoth[Sqrt[1 + Cot[x]]/Sqrt[1 - I]]/Sqrt[1 - I] + ArcCoth[Sqrt[1 + Cot[x]]/Sqrt[1 + I]]/Sqrt[1 + I]}
{Cot[x]/(1 + Cot[x])^(3/2), x, 4, ArcCoth[Sqrt[1 + Cot[x]]/Sqrt[1 - I]]/(1 - I)^(3/2) + ArcCoth[Sqrt[1 + Cot[x]]/Sqrt[1 + I]]/(1 + I)^(3/2) - 1/Sqrt[1 + Cot[x]]}

{Cot[x]^2*(1 + Cot[x])^(3/2), x, 8, (-Sqrt[-1 + Sqrt[2]])*ArcTan[(Sqrt[-2 + 2*Sqrt[2]]*Sqrt[1 + Cot[x]])/(1 - Sqrt[2] + Cot[x])] - Sqrt[1 + Sqrt[2]]*ArcTanh[(Sqrt[2 + 2*Sqrt[2]]*Sqrt[1 + Cot[x]])/(1 + Sqrt[2] + Cot[x])] + 2*Sqrt[1 + Cot[x]] - (2/5)*(1 + Cot[x])^(5/2)}
{Cot[x]^2*Sqrt[1 + Cot[x]], x, 8, (-(1/2))*Sqrt[2 + 2*Sqrt[2]]*ArcTan[(Sqrt[-2 + 2*Sqrt[2]]*Sqrt[1 + Cot[x]])/(1 - Sqrt[2] + Cot[x])] - (1/2)*Sqrt[-2 + 2*Sqrt[2]]*ArcTanh[(Sqrt[2 + 2*Sqrt[2]]*Sqrt[1 + Cot[x]])/(1 + Sqrt[2] + Cot[x])] - (2/3)*(1 + Cot[x])^(3/2)}
{Cot[x]^2/Sqrt[1 + Cot[x]], x, 7, (-(1/2))*Sqrt[1 + Sqrt[2]]*ArcTan[(Sqrt[-2 + 2*Sqrt[2]]*Sqrt[1 + Cot[x]])/(1 - Sqrt[2] + Cot[x])] + (1/2)*Sqrt[-1 + Sqrt[2]]*ArcTanh[(Sqrt[2 + 2*Sqrt[2]]*Sqrt[1 + Cot[x]])/(1 + Sqrt[2] + Cot[x])] - 2*Sqrt[1 + Cot[x]]}
{Cot[x]^2/(1 + Cot[x])^(3/2), x, 8, (-(1/4))*Sqrt[-2 + 2*Sqrt[2]]*ArcTan[(Sqrt[-2 + 2*Sqrt[2]]*Sqrt[1 + Cot[x]])/(1 - Sqrt[2] + Cot[x])] + (1/4)*Sqrt[2 + 2*Sqrt[2]]*ArcTanh[(Sqrt[2 + 2*Sqrt[2]]*Sqrt[1 + Cot[x]])/(1 + Sqrt[2] + Cot[x])] + 1/Sqrt[1 + Cot[x]]}


{Csc[x]^2*(a + b*Cot[x])^n, x, 2, -((a + b*Cot[x])^(1 + n)/(b*(1 + n)))}


(* ::Subsection::Closed:: *)
(*Integrands of the form Trig[x]^m (a+b Trig[x]^2)^n*)


(* ::Subsubsection::Closed:: *)
(*Integrands of the form Trig[x]^m (a+b Sin[x]^2)^n*)


{Cos[x]^1/(a + b*Sin[x]^2)^2, x, 3, ArcTan[(Sqrt[b]*Sin[x])/Sqrt[a]]/(2*a^(3/2)*Sqrt[b]) + Sin[x]/(2*a*(a + b*Sin[x]^2))}
{Cos[x]^2/(a + b*Sin[x]^2)^2, x, 8, ArcTan[((2*a + 2*b)*Tan[x])/(2*Sqrt[a]*Sqrt[a + b])]/(2*a^(3/2)*Sqrt[a + b]) + (Cos[x]*Sin[x])/(2*a*(a + b*Sin[x]^2)), ArcTan[(Sqrt[a]*Cot[x])/Sqrt[a + b]]/(Sqrt[a]*b*Sqrt[a + b]) + ((2*a + b)*ArcTan[(Sqrt[a + b]*Tan[x])/Sqrt[a]])/(2*a^(3/2)*b*Sqrt[a + b]) + Sin[2*x]/(2*a*(2*a + b - b*Cos[2*x]))}
{Cos[x]^3/(a + b*Sin[x]^2)^2, x, 5, -(((a - b)*ArcTan[(Sqrt[b]*Sin[x])/Sqrt[a]])/(2*a^(3/2)*b^(3/2))) + ((a + b)*Sin[x])/(2*a*b*(a + b*Sin[x]^2)), -(((a - b)*ArcTan[(Sqrt[b]*Sin[x])/Sqrt[a]])/(2*a^(3/2)*b^(3/2))) + Sin[x]/(2*a*(a + b*Sin[x]^2)) + Sin[x]/(2*b*(a + b*Sin[x]^2))}
{Cos[x]^4/(a + b*Sin[x]^2)^2, x, 8, x/b^2 - ((2*a - b)*Sqrt[a + b]*ArcTan[((2*a + 2*b)*Tan[x])/(2*Sqrt[a]*Sqrt[a + b])])/(2*a^(3/2)*b^2) + ((a + b)*Cos[x]*Sin[x])/(2*a*b*(a + b*Sin[x]^2)), x/b^2 + (2*Sqrt[a + b]*ArcTan[(Sqrt[a]*Cot[x])/Sqrt[a + b]])/(Sqrt[a]*b^2) + (Sqrt[a + b]*(2*a + b)*ArcTan[(Sqrt[a + b]*Tan[x])/Sqrt[a]])/(2*a^(3/2)*b^2) + ((a + b)*Sin[2*x])/(2*a*b*(2*a + b - b*Cos[2*x]))}


(* Integrands of the form Cot[x]^m/Sqrt[a+b*Sin[x]^2] where m is an integer *)
{Cot[x]^3/Sqrt[a + b*Sin[x]^2], x, 6, ArcTanh[Sqrt[a + b*Sin[x]^2]/Sqrt[a]]/Sqrt[a] + (b*ArcTanh[Sqrt[a + b*Sin[x]^2]/Sqrt[a]])/(2*a^(3/2)) - (Csc[x]^2*Sqrt[a + b*Sin[x]^2])/(2*a)}
{Cot[x]^2/Sqrt[a + b*Sin[x]^2], x, 9, -((Sqrt[a + b]*Sqrt[(b + a*Csc[x]^2)/(a + b)]*EllipticE[ArcSin[(Sqrt[-a]*Cot[x])/Sqrt[a + b]], (a + b)/a])/(Sqrt[-a]*Sqrt[Csc[x]^2]*Sqrt[(b + a*Csc[x]^2)*Sin[x]^2])) - (I*Sqrt[(b + a*Csc[x]^2)/(a + b)]*EllipticF[I*ArcCsch[Tan[x]], a/(a + b)])/(Sqrt[Csc[x]^2]*Sqrt[(b + a*Csc[x]^2)*Sin[x]^2])}
{Cot[x]/Sqrt[a + b*Sin[x]^2], x, 2, -(ArcTanh[Sqrt[a + b*Sin[x]^2]/Sqrt[a]]/Sqrt[a])}
{Tan[x]/Sqrt[a + b*Sin[x]^2], x, 2, ArcTanh[Sqrt[a + b*Sin[x]^2]/Sqrt[a + b]]/Sqrt[a + b]}
{Tan[x]^2/Sqrt[a + b*Sin[x]^2], x, 9, (EllipticE[ArcSin[Sqrt[-(1/a)]*Sqrt[a + b]*Tan[x]], a/(a + b)]*Sqrt[(a + (a + b)*Tan[x]^2)/a])/(Sqrt[-(1/a)]*Sqrt[a + b]*Sqrt[Sec[x]^2]*Sqrt[Cos[x]^2*(a + (a + b)*Tan[x]^2)]) + (I*EllipticF[I*ArcSinh[Tan[x]], (a + b)/a]*Sqrt[(a + (a + b)*Tan[x]^2)/a])/(Sqrt[Sec[x]^2]*Sqrt[Cos[x]^2*(a + (a + b)*Tan[x]^2)])}

{Cot[x]^3/Sqrt[a - a*Sin[x]^2], x, 4, (ArcTanh[Cos[x]]*Cos[x])/(2*Sqrt[a*Cos[x]^2]) - Cot[x]^2/(2*Sqrt[a*Cos[x]^2])}
{Cot[x]^2/Sqrt[a - a*Sin[x]^2], x, 3, -(Cot[x]/Sqrt[a*Cos[x]^2])}
{Cot[x]/Sqrt[a - a*Sin[x]^2], x, 2, -(ArcTanh[Sqrt[a*Cos[x]^2]/Sqrt[a]]/Sqrt[a])}
{Tan[x]/Sqrt[a - a*Sin[x]^2], x, 3, 1/Sqrt[a*Cos[x]^2]}
{Tan[x]^2/Sqrt[a - a*Sin[x]^2], x, 4, -((ArcTanh[Sin[x]]*Cos[x])/(2*Sqrt[a*Cos[x]^2])) + Tan[x]/(2*Sqrt[a*Cos[x]^2])}

(* This causes Mathematica 7 problems: *)
{Cot[x]/Sqrt[1 + Sin[x]^2], x, 2, -ArcTanh[Sqrt[1 + Sin[x]^2]]}
{Cot[x]/Sqrt[1 - Sin[x]^2], x, 2, -ArcTanh[Sqrt[Cos[x]^2]]}


{Cot[x]*Sqrt[1 - Sin[x]^2], x, 3, -ArcTanh[Sqrt[Cos[x]^2]] + Sqrt[Cos[x]^2]}


{Sin[x]/Sqrt[1 + Sin[x]^2], x, 2, -ArcSin[Cos[x]/Sqrt[2]]}
{Sin[x]*Sqrt[1 + Sin[x]^2], x, 3, -ArcSin[Cos[x]/Sqrt[2]] - (Cos[x]*Sqrt[2 - Cos[x]^2])/2}
{Sin[7 + 3*x]/Sqrt[3 + Sin[7 + 3*x]^2], x, 2, -ArcSin[Cos[7 + 3*x]/2]/3}


(* ::Subsubsection::Closed:: *)
(*Integrands of the form Trig[x]^m (a+b Cos[x]^2)^n*)


{Tan[x]/Sqrt[a + b*Cos[x]^2], x, 2, ArcTanh[Sqrt[a + b*Cos[x]^2]/Sqrt[a]]/Sqrt[a]}
{Tan[x]/Sqrt[1 + Cos[x]^2], x, 2, ArcTanh[Sqrt[1 + Cos[x]^2]]}
{Tan[x]/Sqrt[1 - Cos[x]^2], x, 2, ArcTanh[Sqrt[Sin[x]^2]]}


{Tan[x]*Sqrt[1 - Cos[x]^2], x, 3, ArcTanh[Sqrt[Sin[x]^2]] - Sqrt[Sin[x]^2]}


{Cos[x]/Sqrt[1 + Cos[x]^2], x, 2, ArcSin[Sin[x]/Sqrt[2]]}
{Cos[5 + 3*x]/Sqrt[3 + Cos[5 + 3*x]^2], x, 2, ArcSin[Sin[5 + 3*x]/2]/3}
{Cos[x]/Sqrt[4 - Cos[x]^2], x, 2, ArcSinh[Sin[x]/Sqrt[3]]}


(* ::Subsubsection::Closed:: *)
(*Integrands of the form Trig[x]^m (a+b Tan[x]^2)^n*)


(* Integrands of the form Tan[x]^m/Sqrt[a+b*Tan[x]^2] where m is an integer *)
{Tan[x]^3/Sqrt[a + b*Tan[x]^2], x, 6, ArcTanh[Sqrt[a + b*Tan[x]^2]/Sqrt[a - b]]/Sqrt[a - b] + Sqrt[a + b*Tan[x]^2]/b}
{Tan[x]^2/Sqrt[a + b*Tan[x]^2], x, 5, -(ArcTan[(Sqrt[a - b]*Tan[x])/Sqrt[a + b*Tan[x]^2]]/Sqrt[a - b]) + ArcTanh[(Sqrt[b]*Tan[x])/Sqrt[a + b*Tan[x]^2]]/Sqrt[b]}
{Tan[x]/Sqrt[a + b*Tan[x]^2], x, 3, -(ArcTanh[Sqrt[a + b*Tan[x]^2]/Sqrt[a - b]]/Sqrt[a - b])}
{Cot[x]/Sqrt[a + b*Tan[x]^2], x, 7, -(ArcTanh[Sqrt[a + b*Tan[x]^2]/Sqrt[a]]/Sqrt[a]) + ArcTanh[Sqrt[a + b*Tan[x]^2]/Sqrt[a - b]]/Sqrt[a - b]}
{Cot[x]^2/Sqrt[a + b*Tan[x]^2], x, 5, -(ArcTan[(Sqrt[a - b]*Tan[x])/Sqrt[a + b*Tan[x]^2]]/Sqrt[a - b]) - (Cot[x]*Sqrt[a + b*Tan[x]^2])/a}

{Tan[x]^3/Sqrt[a + a*Tan[x]^2], x, 5, (Sec[x]*(Cos[x] + Sec[x]))/Sqrt[a*Sec[x]^2]}
{Tan[x]^2/Sqrt[a + a*Tan[x]^2], x, 4, (Sec[x]*(ArcTanh[Sin[x]] - Sin[x]))/Sqrt[a*Sec[x]^2]}
{Tan[x]/Sqrt[a + a*Tan[x]^2], x, 4, -(1/Sqrt[a*Sec[x]^2])}
{Cot[x]/Sqrt[a + a*Tan[x]^2], x, 4, -(((ArcTanh[Cos[x]] - Cos[x])*Sec[x])/Sqrt[a*Sec[x]^2])}
{Cot[x]^2/Sqrt[a + a*Tan[x]^2], x, 5, -((Sec[x]*(Csc[x] + Sin[x]))/Sqrt[a*Sec[x]^2])}


(* Integrands of the form Tan[x]^m*Sqrt[a+b*Tan[x]^2] where m is an integer *)
{Tan[x]^3*Sqrt[a + b*Tan[x]^2], x, 7, Sqrt[a - b]*ArcTanh[Sqrt[a + b*Tan[x]^2]/Sqrt[a - b]] - Sqrt[a + b*Tan[x]^2] + (a + b*Tan[x]^2)^(3/2)/(3*b)}
{Tan[x]^2*Sqrt[a + b*Tan[x]^2], x, 14, I*Sqrt[a - b]*ArcTanh[(I*Sqrt[b] - Sqrt[b]*Tan[x] - Sqrt[a + b*Tan[x]^2])/Sqrt[a - b]] + I*Sqrt[a - b]*ArcTanh[(I*Sqrt[b] + Sqrt[b]*Tan[x] + Sqrt[a + b*Tan[x]^2])/Sqrt[a - b]] + ((a - 2*b)*Log[Sqrt[b]*Tan[x] + Sqrt[a + b*Tan[x]^2]])/(2*Sqrt[b]) - a^2/(8*Sqrt[b]*(Sqrt[b]*Tan[x] + Sqrt[a + b*Tan[x]^2])^2) + (Sqrt[b]*Tan[x] + Sqrt[a + b*Tan[x]^2])^2/(8*Sqrt[b])}
{Tan[x]*Sqrt[a + b*Tan[x]^2], x, 4, (-Sqrt[a - b])*ArcTanh[Sqrt[a + b*Tan[x]^2]/Sqrt[a - b]] + Sqrt[a + b*Tan[x]^2]}
{Cot[x]*Sqrt[a + b*Tan[x]^2], x, 7, (-Sqrt[a])*ArcTanh[Sqrt[a + b*Tan[x]^2]/Sqrt[a]] + Sqrt[a - b]*ArcTanh[Sqrt[a + b*Tan[x]^2]/Sqrt[a - b]]}
{Cot[x]^2*Sqrt[a + b*Tan[x]^2], x, 18, I*Sqrt[a - b]*ArcTanh[(I*Sqrt[b] - Sqrt[b]*Tan[x] - Sqrt[a + b*Tan[x]^2])/Sqrt[a - b]] + I*Sqrt[a - b]*ArcTanh[(I*Sqrt[b] + Sqrt[b]*Tan[x] + Sqrt[a + b*Tan[x]^2])/Sqrt[a - b]] + (2*a*Sqrt[b])/(a - (Sqrt[b]*Tan[x] + Sqrt[a + b*Tan[x]^2])^2)}


(* Integrands of the form Tan[x]^m*(a+b*Tan[x]^2)^(3/2) where m is an integer *)
{Tan[x]^3*(a + b*Tan[x]^2)^(3/2), x, 7, (a - b)^(3/2)*ArcTanh[Sqrt[a + b*Tan[x]^2]/Sqrt[a - b]] - (a - b)*Sqrt[a + b*Tan[x]^2] - (1/3)*(a + b*Tan[x]^2)^(3/2) + (a + b*Tan[x]^2)^(5/2)/(5*b)}
{Tan[x]^2*(a + b*Tan[x]^2)^(3/2), x, 12, (-(a - b)^(3/2))*ArcTan[(Sqrt[a - b]*Tan[x])/Sqrt[a + b*Tan[x]^2]] + (3*a^2*ArcTanh[(Sqrt[b]*Tan[x])/Sqrt[a + b*Tan[x]^2]])/(8*Sqrt[b]) - (3/2)*a*Sqrt[b]*ArcTanh[(Sqrt[b]*Tan[x])/Sqrt[a + b*Tan[x]^2]] + b^(3/2)*ArcTanh[(Sqrt[b]*Tan[x])/Sqrt[a + b*Tan[x]^2]] + (3/8)*a*Tan[x]*Sqrt[a + b*Tan[x]^2] - (1/2)*b*Tan[x]*Sqrt[a + b*Tan[x]^2] + (1/4)*Tan[x]*(a + b*Tan[x]^2)^(3/2)}
{Tan[x]*(a + b*Tan[x]^2)^(3/2), x, 5, (-(a - b)^(3/2))*ArcTanh[Sqrt[a + b*Tan[x]^2]/Sqrt[a - b]] + (a - b)*Sqrt[a + b*Tan[x]^2] + (1/3)*(a + b*Tan[x]^2)^(3/2)}
{Cot[x]*(a + b*Tan[x]^2)^(3/2), x, 7, (-a^(3/2))*ArcTanh[Sqrt[a + b*Tan[x]^2]/Sqrt[a]] + (a - b)^(3/2)*ArcTanh[Sqrt[a + b*Tan[x]^2]/Sqrt[a - b]] + b*Sqrt[a + b*Tan[x]^2]}
{Cot[x]^2*(a + b*Tan[x]^2)^(3/2), x, 12, (-(a - b)^(3/2))*ArcTan[(Sqrt[a - b]*Tan[x])/Sqrt[a + b*Tan[x]^2]] + b^(3/2)*ArcTanh[(Sqrt[b]*Tan[x])/Sqrt[a + b*Tan[x]^2]] + b*Tan[x]*Sqrt[a + b*Tan[x]^2] - Cot[x]*(a + b*Tan[x]^2)^(3/2)}


(* Integrands of the form Tan[x]^m/(a+b*Tan[x]^2)^(3/2) where m is an integer *)
{Tan[x]^3/(a + b*Tan[x]^2)^(3/2), x, 7, ArcTanh[Sqrt[a + b*Tan[x]^2]/Sqrt[a - b]]/(a - b)^(3/2) - a/((a - b)*b*Sqrt[a + b*Tan[x]^2])}
{Tan[x]^2/(a + b*Tan[x]^2)^(3/2), x, 7, -(ArcTan[(Sqrt[a - b]*Tan[x])/Sqrt[a + b*Tan[x]^2]]/(a - b)^(3/2)) + Tan[x]/((a - b)*Sqrt[a + b*Tan[x]^2])}
{Tan[x]/(a + b*Tan[x]^2)^(3/2), x, 4, -(ArcTanh[Sqrt[a + b*Tan[x]^2]/Sqrt[a - b]]/(a - b)^(3/2)) + 1/((a - b)*Sqrt[a + b*Tan[x]^2])}
{Cot[x]/(a + b*Tan[x]^2)^(3/2), x, 8, -(ArcTanh[Sqrt[a + b*Tan[x]^2]/Sqrt[a]]/a^(3/2)) + ArcTanh[Sqrt[a + b*Tan[x]^2]/Sqrt[a - b]]/(a - b)^(3/2) - b/(a*(a - b)*Sqrt[a + b*Tan[x]^2])}
{Cot[x]^2/(a + b*Tan[x]^2)^(3/2), x, 8, -(ArcTan[(Sqrt[a - b]*Tan[x])/Sqrt[a + b*Tan[x]^2]]/(a - b)^(3/2)) + Cot[x]/(a*Sqrt[a + b*Tan[x]^2]) + (b*Tan[x])/(a*(a - b)*Sqrt[a + b*Tan[x]^2]) - (2*Cot[x]*Sqrt[a + b*Tan[x]^2])/a^2}


(* Integrands of the form Tan[x]^m/(a+b*Tan[x]^2)^(5/2) where m is an integer *)
{Tan[x]^3/(a + b*Tan[x]^2)^(5/2), x, 7, ArcTanh[Sqrt[a + b*Tan[x]^2]/Sqrt[a - b]]/(a - b)^(5/2) - a/(3*(a - b)*b*(a + b*Tan[x]^2)^(3/2)) - 1/((a - b)^2*Sqrt[a + b*Tan[x]^2])}
{Tan[x]^2/(a + b*Tan[x]^2)^(5/2), x, 11, -(ArcTan[(Sqrt[a - b]*Tan[x])/Sqrt[a + b*Tan[x]^2]]/(a - b)^(5/2)) + Tan[x]/(3*(a - b)*(a + b*Tan[x]^2)^(3/2)) + (2*Tan[x])/(3*a*(a - b)*Sqrt[a + b*Tan[x]^2]) + (b*Tan[x])/(a*(a - b)^2*Sqrt[a + b*Tan[x]^2])}
{Tan[x]/(a + b*Tan[x]^2)^(5/2), x, 5, -(ArcTanh[Sqrt[a + b*Tan[x]^2]/Sqrt[a - b]]/(a - b)^(5/2)) + 1/(3*(a - b)*(a + b*Tan[x]^2)^(3/2)) + 1/((a - b)^2*Sqrt[a + b*Tan[x]^2])}
{Cot[x]/(a + b*Tan[x]^2)^(5/2), x, 8, -(ArcTanh[Sqrt[a + b*Tan[x]^2]/Sqrt[a]]/a^(5/2)) + ArcTanh[Sqrt[a + b*Tan[x]^2]/Sqrt[a - b]]/(a - b)^(5/2) - b/(3*a*(a - b)*(a + b*Tan[x]^2)^(3/2)) - ((2*a - b)*b)/(a^2*(a - b)^2*Sqrt[a + b*Tan[x]^2])}
{Cot[x]^2/(a + b*Tan[x]^2)^(5/2), x, 12, -(ArcTan[(Sqrt[a - b]*Tan[x])/Sqrt[a + b*Tan[x]^2]]/(a - b)^(5/2)) + Cot[x]/(3*a*(a + b*Tan[x]^2)^(3/2)) + (b*Tan[x])/(3*a*(a - b)*(a + b*Tan[x]^2)^(3/2)) + (4*Cot[x])/(3*a^2*Sqrt[a + b*Tan[x]^2]) + (b*Tan[x])/(a*(a - b)^2*Sqrt[a + b*Tan[x]^2]) + (2*b*Tan[x])/(3*a^2*(a - b)*Sqrt[a + b*Tan[x]^2]) - (8*Cot[x]*Sqrt[a + b*Tan[x]^2])/(3*a^3)}


(* ::Subsubsection::Closed:: *)
(*Integrands of the form Trig[x]^m (a+b Cot[x]^2)^n*)


(* Integrands of the form Cot[x]^m/Sqrt[a+b*Cot[x]^2] where m is an integer *)
{Cot[x]^3/Sqrt[a + b*Cot[x]^2], x, 6, -(ArcTanh[Sqrt[a + b*Cot[x]^2]/Sqrt[a - b]]/Sqrt[a - b]) - Sqrt[a + b*Cot[x]^2]/b}
{Cot[x]^2/Sqrt[a + b*Cot[x]^2], x, 5, ArcTan[(Sqrt[a - b]*Cot[x])/Sqrt[a + b*Cot[x]^2]]/Sqrt[a - b] - ArcTanh[(Sqrt[b]*Cot[x])/Sqrt[a + b*Cot[x]^2]]/Sqrt[b]}
{Cot[x]/Sqrt[a + b*Cot[x]^2], x, 3, ArcTanh[Sqrt[a + b*Cot[x]^2]/Sqrt[a - b]]/Sqrt[a - b]}
{Tan[x]/Sqrt[a + b*Cot[x]^2], x, 7, ArcTanh[Sqrt[a + b*Cot[x]^2]/Sqrt[a]]/Sqrt[a] - ArcTanh[Sqrt[a + b*Cot[x]^2]/Sqrt[a - b]]/Sqrt[a - b]}
{Tan[x]^2/Sqrt[a + b*Cot[x]^2], x, 5, ArcTan[(Sqrt[a - b]*Cot[x])/Sqrt[a + b*Cot[x]^2]]/Sqrt[a - b] + (Sqrt[a + b*Cot[x]^2]*Tan[x])/a}

{Cot[x]^3/Sqrt[a + a*Cot[x]^2], x, 5, -((Csc[x]*(Csc[x] + Sin[x]))/Sqrt[a*Csc[x]^2])}
{Cot[x]^2/Sqrt[a + a*Cot[x]^2], x, 4, -(((ArcTanh[Cos[x]] - Cos[x])*Csc[x])/Sqrt[a*Csc[x]^2])}
{Cot[x]/Sqrt[a + a*Cot[x]^2], x, 4, 1/Sqrt[a*Csc[x]^2]}
{Tan[x]/Sqrt[a + a*Cot[x]^2], x, 4, (Csc[x]*(ArcTanh[Sin[x]] - Sin[x]))/Sqrt[a*Csc[x]^2]}
{Tan[x]^2/Sqrt[a + a*Cot[x]^2], x, 5, (Csc[x]*(Cos[x] + Sec[x]))/Sqrt[a*Csc[x]^2]}


(* Integrands of the form Cot[x]^m*Sqrt[a+b*Cot[x]^2] where m is an integer *)
{Cot[x]^3*Sqrt[a + b*Cot[x]^2], x, 7, (-Sqrt[a - b])*ArcTanh[Sqrt[a + b*Cot[x]^2]/Sqrt[a - b]] + Sqrt[a + b*Cot[x]^2] - (a + b*Cot[x]^2)^(3/2)/(3*b)}
{Cot[x]^2*Sqrt[a + b*Cot[x]^2], x, 14, (-I)*Sqrt[a - b]*ArcTanh[(I*Sqrt[b] - Sqrt[b]*Cot[x] - Sqrt[a + b*Cot[x]^2])/Sqrt[a - b]] - I*Sqrt[a - b]*ArcTanh[(I*Sqrt[b] + Sqrt[b]*Cot[x] + Sqrt[a + b*Cot[x]^2])/Sqrt[a - b]] + a^2/(8*Sqrt[b]*(Sqrt[b]*Cot[x] + Sqrt[a + b*Cot[x]^2])^2) - (Sqrt[b]*Cot[x] + Sqrt[a + b*Cot[x]^2])^2/(8*Sqrt[b]) - ((a - 2*b)*Log[Sqrt[b]*Cot[x] + Sqrt[a + b*Cot[x]^2]])/(2*Sqrt[b])}
{Cot[x]*Sqrt[a + b*Cot[x]^2], x, 4, Sqrt[a - b]*ArcTanh[Sqrt[a + b*Cot[x]^2]/Sqrt[a - b]] - Sqrt[a + b*Cot[x]^2]}
{Tan[x]*Sqrt[a + b*Cot[x]^2], x, 7, Sqrt[a]*ArcTanh[Sqrt[a + b*Cot[x]^2]/Sqrt[a]] - Sqrt[a - b]*ArcTanh[Sqrt[a + b*Cot[x]^2]/Sqrt[a - b]]}
{Tan[x]^2*Sqrt[a + b*Cot[x]^2], x, 18, (-I)*Sqrt[a - b]*ArcTanh[(I*Sqrt[b] - Sqrt[b]*Cot[x] - Sqrt[a + b*Cot[x]^2])/Sqrt[a - b]] - I*Sqrt[a - b]*ArcTanh[(I*Sqrt[b] + Sqrt[b]*Cot[x] + Sqrt[a + b*Cot[x]^2])/Sqrt[a - b]] - (2*a*Sqrt[b])/(a - (Sqrt[b]*Cot[x] + Sqrt[a + b*Cot[x]^2])^2)}


(* Integrands of the form Cot[x]^m*(a+b*Cot[x]^2)^(3/2) where m is an integer *)
{Cot[x]^3*(a + b*Cot[x]^2)^(3/2), x, 7, (-(a - b)^(3/2))*ArcTanh[Sqrt[a + b*Cot[x]^2]/Sqrt[a - b]] + (a - b)*Sqrt[a + b*Cot[x]^2] + (1/3)*(a + b*Cot[x]^2)^(3/2) - (a + b*Cot[x]^2)^(5/2)/(5*b)}
{Cot[x]^2*(a + b*Cot[x]^2)^(3/2), x, 12, (a - b)^(3/2)*ArcTan[(Sqrt[a - b]*Cot[x])/Sqrt[a + b*Cot[x]^2]] - (3*a^2*ArcTanh[(Sqrt[b]*Cot[x])/Sqrt[a + b*Cot[x]^2]])/(8*Sqrt[b]) + (3/2)*a*Sqrt[b]*ArcTanh[(Sqrt[b]*Cot[x])/Sqrt[a + b*Cot[x]^2]] - b^(3/2)*ArcTanh[(Sqrt[b]*Cot[x])/Sqrt[a + b*Cot[x]^2]] - (3/8)*a*Cot[x]*Sqrt[a + b*Cot[x]^2] + (1/2)*b*Cot[x]*Sqrt[a + b*Cot[x]^2] - (1/4)*Cot[x]*(a + b*Cot[x]^2)^(3/2)}
{Cot[x]*(a + b*Cot[x]^2)^(3/2), x, 5, (a - b)^(3/2)*ArcTanh[Sqrt[a + b*Cot[x]^2]/Sqrt[a - b]] - (a - b)*Sqrt[a + b*Cot[x]^2] - (1/3)*(a + b*Cot[x]^2)^(3/2)}
{Tan[x]*(a + b*Cot[x]^2)^(3/2), x, 7, a^(3/2)*ArcTanh[Sqrt[a + b*Cot[x]^2]/Sqrt[a]] - (a - b)^(3/2)*ArcTanh[Sqrt[a + b*Cot[x]^2]/Sqrt[a - b]] - b*Sqrt[a + b*Cot[x]^2]}
{Tan[x]^2*(a + b*Cot[x]^2)^(3/2), x, 12, (a - b)^(3/2)*ArcTan[(Sqrt[a - b]*Cot[x])/Sqrt[a + b*Cot[x]^2]] - b^(3/2)*ArcTanh[(Sqrt[b]*Cot[x])/Sqrt[a + b*Cot[x]^2]] - b*Cot[x]*Sqrt[a + b*Cot[x]^2] + (a + b*Cot[x]^2)^(3/2)*Tan[x]}


(* Integrands of the form Cot[x]^m/(a+b*Cot[x]^2)^(3/2) where m is an integer *)
{Cot[x]^3/(a + b*Cot[x]^2)^(3/2), x, 7, -(ArcTanh[Sqrt[a + b*Cot[x]^2]/Sqrt[a - b]]/(a - b)^(3/2)) + a/((a - b)*b*Sqrt[a + b*Cot[x]^2])}
{Cot[x]^2/(a + b*Cot[x]^2)^(3/2), x, 7, ArcTan[(Sqrt[a - b]*Cot[x])/Sqrt[a + b*Cot[x]^2]]/(a - b)^(3/2) - Cot[x]/((a - b)*Sqrt[a + b*Cot[x]^2])}
{Cot[x]/(a + b*Cot[x]^2)^(3/2), x, 4, ArcTanh[Sqrt[a + b*Cot[x]^2]/Sqrt[a - b]]/(a - b)^(3/2) - 1/((a - b)*Sqrt[a + b*Cot[x]^2])}
{Tan[x]/(a + b*Cot[x]^2)^(3/2), x, 8, ArcTanh[Sqrt[a + b*Cot[x]^2]/Sqrt[a]]/a^(3/2) - ArcTanh[Sqrt[a + b*Cot[x]^2]/Sqrt[a - b]]/(a - b)^(3/2) + b/(a*(a - b)*Sqrt[a + b*Cot[x]^2])}
{Tan[x]^2/(a + b*Cot[x]^2)^(3/2), x, 8, ArcTan[(Sqrt[a - b]*Cot[x])/Sqrt[a + b*Cot[x]^2]]/(a - b)^(3/2) - (b*Cot[x])/(a*(a - b)*Sqrt[a + b*Cot[x]^2]) - Tan[x]/(a*Sqrt[a + b*Cot[x]^2]) + (2*Sqrt[a + b*Cot[x]^2]*Tan[x])/a^2}


(* Integrands of the form Cot[x]^m/(a+b*Cot[x]^2)^(5/2) where m is an integer *)
{Cot[x]^3/(a + b*Cot[x]^2)^(5/2), x, 7, -(ArcTanh[Sqrt[a + b*Cot[x]^2]/Sqrt[a - b]]/(a - b)^(5/2)) + a/(3*(a - b)*b*(a + b*Cot[x]^2)^(3/2)) + 1/((a - b)^2*Sqrt[a + b*Cot[x]^2])}
{Cot[x]^2/(a + b*Cot[x]^2)^(5/2), x, 11, ArcTan[(Sqrt[a - b]*Cot[x])/Sqrt[a + b*Cot[x]^2]]/(a - b)^(5/2) - Cot[x]/(3*(a - b)*(a + b*Cot[x]^2)^(3/2)) - (2*Cot[x])/(3*a*(a - b)*Sqrt[a + b*Cot[x]^2]) - (b*Cot[x])/(a*(a - b)^2*Sqrt[a + b*Cot[x]^2])}
{Cot[x]/(a + b*Cot[x]^2)^(5/2), x, 5, ArcTanh[Sqrt[a + b*Cot[x]^2]/Sqrt[a - b]]/(a - b)^(5/2) - 1/(3*(a - b)*(a + b*Cot[x]^2)^(3/2)) - 1/((a - b)^2*Sqrt[a + b*Cot[x]^2])}
{Tan[x]/(a + b*Cot[x]^2)^(5/2), x, 8, ArcTanh[Sqrt[a + b*Cot[x]^2]/Sqrt[a]]/a^(5/2) - ArcTanh[Sqrt[a + b*Cot[x]^2]/Sqrt[a - b]]/(a - b)^(5/2) + b/(3*a*(a - b)*(a + b*Cot[x]^2)^(3/2)) + ((2*a - b)*b)/(a^2*(a - b)^2*Sqrt[a + b*Cot[x]^2])}
{Tan[x]^2/(a + b*Cot[x]^2)^(5/2), x, 12, ArcTan[(Sqrt[a - b]*Cot[x])/Sqrt[a + b*Cot[x]^2]]/(a - b)^(5/2) - (b*Cot[x])/(3*a*(a - b)*(a + b*Cot[x]^2)^(3/2)) - (b*Cot[x])/(a*(a - b)^2*Sqrt[a + b*Cot[x]^2]) - (2*b*Cot[x])/(3*a^2*(a - b)*Sqrt[a + b*Cot[x]^2]) - Tan[x]/(3*a*(a + b*Cot[x]^2)^(3/2)) - (4*Tan[x])/(3*a^2*Sqrt[a + b*Cot[x]^2]) + (8*Sqrt[a + b*Cot[x]^2]*Tan[x])/(3*a^3)}


(* ::Subsection::Closed:: *)
(*Integrands of the form Trig[x]^m (a+b Trig[x]^n)^p*)


(* ::Subsubsection::Closed:: *)
(*Integrands of the form Trig[x]^m (a+b Sin[x]^n)^p*)


(* Integrands of the form Cot[x]/Sqrt[a+b*Sin[x]^n] where n is an integer *)
{Cot[x]/Sqrt[a + b*Sin[x]], x, 2, -((2*ArcTanh[Sqrt[a + b*Sin[x]]/Sqrt[a]])/Sqrt[a])}
{Cot[x]/Sqrt[a + b*Sin[x]^2], x, 2, -(ArcTanh[Sqrt[a + b*Sin[x]^2]/Sqrt[a]]/Sqrt[a])}
{Cot[x]/Sqrt[a + b*Sin[x]^3], x, 2, -((2*ArcTanh[Sqrt[a + b*Sin[x]^3]/Sqrt[a]])/(3*Sqrt[a]))}
{Cot[x]/Sqrt[a + b*Sin[x]^4], x, 2, -((2*ArcTanh[Sqrt[a + b*Sin[x]^4]/Sqrt[a]])/(4*Sqrt[a]))}
{Cot[x]/Sqrt[a + b*Sin[x]^n], x, 2, -((2*ArcTanh[Sqrt[a + b*Sin[x]^n]/Sqrt[a]])/(Sqrt[a]*n))}


(* Integrands of the form Cot[x]*Sqrt[a+b*Sin[x]^n] where n is an integer *)
{Cot[x]*Sqrt[a + b*Sin[x]], x, 3, -2*Sqrt[a]*ArcTanh[Sqrt[a + b*Sin[x]]/Sqrt[a]] + 2*Sqrt[a + b*Sin[x]]}
{Cot[x]*Sqrt[a + b*Sin[x]^2], x, 3, (-Sqrt[a])*ArcTanh[Sqrt[a + b*Sin[x]^2]/Sqrt[a]] + Sqrt[a + b*Sin[x]^2]}
{Cot[x]*Sqrt[a + b*Sin[x]^3], x, 3, (-(2/3))*Sqrt[a]*ArcTanh[Sqrt[a + b*Sin[x]^3]/Sqrt[a]] + (2/3)*Sqrt[a + b*Sin[x]^3]}
{Cot[x]*Sqrt[a + b*Sin[x]^4], x, 3, (-(1/2))*Sqrt[a]*ArcTanh[Sqrt[a + b*Sin[x]^4]/Sqrt[a]] + (1/2)*Sqrt[a + b*Sin[x]^4]}
{Cot[x]*Sqrt[a + b*Sin[x]^n], x, 3, -((2*Sqrt[a]*ArcTanh[Sqrt[a + b*Sin[x]^n]/Sqrt[a]])/n) + (2*Sqrt[a + b*Sin[x]^n])/n}


(* ::Subsubsection::Closed:: *)
(*Integrands of the form Trig[x]^m (a+b Cos[x]^n)^p*)


(* Integrands of the form Tan[x]/Sqrt[a+b*Cos[x]^n] where n is an integer *)
{Tan[x]/Sqrt[a + b*Cos[x]], x, 2, (2*ArcTanh[Sqrt[a + b*Cos[x]]/Sqrt[a]])/Sqrt[a]}
{Tan[x]/Sqrt[a + b*Cos[x]^2], x, 2, ArcTanh[Sqrt[a + b*Cos[x]^2]/Sqrt[a]]/Sqrt[a]}
{Tan[x]/Sqrt[a + b*Cos[x]^3], x, 2, (2*ArcTanh[Sqrt[a + b*Cos[x]^3]/Sqrt[a]])/(3*Sqrt[a])}
{Tan[x]/Sqrt[a + b*Cos[x]^4], x, 2, (2*ArcTanh[Sqrt[a + b*Cos[x]^4]/Sqrt[a]])/(4*Sqrt[a])}
{Tan[x]/Sqrt[a + b*Cos[x]^n], x, 2, (2*ArcTanh[Sqrt[a + b*Cos[x]^n]/Sqrt[a]])/(Sqrt[a]*n)}


(* Integrands of the form Tan[x]*Sqrt[a+b*Cos[x]^n] where n is an integer *)
{Tan[x]*Sqrt[a + b*Cos[x]], x, 3, 2*Sqrt[a]*ArcTanh[Sqrt[a + b*Cos[x]]/Sqrt[a]] - 2*Sqrt[a + b*Cos[x]]}
{Tan[x]*Sqrt[a + b*Cos[x]^2], x, 3, Sqrt[a]*ArcTanh[Sqrt[a + b*Cos[x]^2]/Sqrt[a]] - Sqrt[a + b*Cos[x]^2]}
{Tan[x]*Sqrt[a + b*Cos[x]^3], x, 3, (2/3)*Sqrt[a]*ArcTanh[Sqrt[a + b*Cos[x]^3]/Sqrt[a]] - (2/3)*Sqrt[a + b*Cos[x]^3]}
{Tan[x]*Sqrt[a + b*Cos[x]^4], x, 3, (1/2)*Sqrt[a]*ArcTanh[Sqrt[a + b*Cos[x]^4]/Sqrt[a]] - (1/2)*Sqrt[a + b*Cos[x]^4]}
{Tan[x]*Sqrt[a + b*Cos[x]^n], x, 3, (2*Sqrt[a]*ArcTanh[Sqrt[a + b*Cos[x]^n]/Sqrt[a]])/n - (2*Sqrt[a + b*Cos[x]^n])/n}


(* ::Subsubsection::Closed:: *)
(*Integrands of the form Trig[x]^m (a+b Tan[x]^4)^p*)


(* Integrands of the form Tan[x]*(a+b*Tan[x]^4)^m where m is a half-integer *)
(* {Tan[x]*(a + b*Tan[x]^4)^(3/2), x, 8, (-(a + b)^(3/2))*ArcTanh[(Sqrt[b]*Sec[x]^2 + Sqrt[a + b*Tan[x]^4])/Sqrt[a + b]] - (1/4)*Sqrt[b]*(3*a + 2*b)*Log[Sqrt[b]*Tan[x]^2 + Sqrt[a + b*Tan[x]^4]] + a^3/(48*(Sqrt[b]*Tan[x]^2 + Sqrt[a + b*Tan[x]^4])^3) + (a^2*Sqrt[b])/(16*(Sqrt[b]*Tan[x]^2 + Sqrt[a + b*Tan[x]^4])^2) + (a*(5*a + 4*b))/(16*(Sqrt[b]*Tan[x]^2 + Sqrt[a + b*Tan[x]^4])) + (1/16)*(5*a + 4*b)*(Sqrt[b]*Tan[x]^2 + Sqrt[a + b*Tan[x]^4]) - (1/16)*Sqrt[b]*(Sqrt[b]*Tan[x]^2 + Sqrt[a + b*Tan[x]^4])^2 + (1/48)*(Sqrt[b]*Tan[x]^2 + Sqrt[a + b*Tan[x]^4])^3} *)
{Tan[x]*Sqrt[a + b*Tan[x]^4], x, 8, (-Sqrt[a + b])*ArcTanh[(Sqrt[b]*Sec[x]^2 + Sqrt[a + b*Tan[x]^4])/Sqrt[a + b]] - (1/2)*Sqrt[b]*Log[Sqrt[b]*Tan[x]^2 + Sqrt[a + b*Tan[x]^4]] + a/(4*(Sqrt[b]*Tan[x]^2 + Sqrt[a + b*Tan[x]^4])) + (1/4)*(Sqrt[b]*Tan[x]^2 + Sqrt[a + b*Tan[x]^4])}
{Tan[x]/Sqrt[a + b*Tan[x]^4], x, 3, -(ArcTanh[(a - b*Tan[x]^2)/(Sqrt[a + b]*Sqrt[a + b*Tan[x]^4])]/(2*Sqrt[a + b]))}
{Tan[x]/(a + b*Tan[x]^4)^(3/2), x, 11, -(ArcTanh[(Sqrt[b]*Sec[x]^2 + Sqrt[a + b*Tan[x]^4])/Sqrt[a + b]]/(a + b)^(3/2)) - Sqrt[b]/((a + b)*(a + (Sqrt[b]*Tan[x]^2 + Sqrt[a + b*Tan[x]^4])^2)) + (Sqrt[b]*Tan[x]^2 + Sqrt[a + b*Tan[x]^4])/((a + b)*(a + (Sqrt[b]*Tan[x]^2 + Sqrt[a + b*Tan[x]^4])^2))}
(* {Tan[x]/(a + b*Tan[x]^4)^(5/2), x, 20, -(ArcTan[(Sqrt[b]*Tan[x]^2 + Sqrt[a + b*Tan[x]^4])/Sqrt[a]]/(Sqrt[a]*(a + b)^2)) + (2*ArcTan[(Sqrt[b]*Tan[x]^2 + Sqrt[a + b*Tan[x]^4])/Sqrt[a]])/(a^(3/2)*(a + b)) - ((a + 2*b)*ArcTan[(Sqrt[b]*Tan[x]^2 + Sqrt[a + b*Tan[x]^4])/Sqrt[a]])/(a^(3/2)*(a + b)^2) - ArcTanh[(Sqrt[b]*Sec[x]^2 + Sqrt[a + b*Tan[x]^4])/Sqrt[a + b]]/(a + b)^(5/2) + (4*a*Sqrt[b])/(3*(a + b)*(a + (Sqrt[b]*Tan[x]^2 + Sqrt[a + b*Tan[x]^4])^2)^3) - (4*a*(Sqrt[b]*Tan[x]^2 + Sqrt[a + b*Tan[x]^4]))/(3*(a + b)*(a + (Sqrt[b]*Tan[x]^2 + Sqrt[a + b*Tan[x]^4])^2)^3) - (2*Sqrt[b])/((a + b)*(a + (Sqrt[b]*Tan[x]^2 + Sqrt[a + b*Tan[x]^4])^2)^2) + (4*(Sqrt[b]*Tan[x]^2 + Sqrt[a + b*Tan[x]^4]))/(3*(a + b)*(a + (Sqrt[b]*Tan[x]^2 + Sqrt[a + b*Tan[x]^4])^2)^2) - Sqrt[b]/((a + b)^2*(a + (Sqrt[b]*Tan[x]^2 + Sqrt[a + b*Tan[x]^4])^2)) + (2*(Sqrt[b]*Tan[x]^2 + Sqrt[a + b*Tan[x]^4]))/(a*(a + b)*(a + (Sqrt[b]*Tan[x]^2 + Sqrt[a + b*Tan[x]^4])^2)) - ((a + 2*b)*(Sqrt[b]*Tan[x]^2 + Sqrt[a + b*Tan[x]^4]))/(a*(a + b)^2*(a + (Sqrt[b]*Tan[x]^2 + Sqrt[a + b*Tan[x]^4])^2))} *)


(* ::Subsubsection::Closed:: *)
(*Integrands of the form Trig[x]^m (a+b Cot[x]^4)^p*)


(* Integrands of the form Cot[x]*(a+b*Cot[x]^4)^m where m is a half-integer *)
(* {Cot[x]*(a + b*Cot[x]^4)^(3/2), x, 8, (a + b)^(3/2)*ArcTanh[(Sqrt[a + b*Cot[x]^4] + Sqrt[b]*Csc[x]^2)/Sqrt[a + b]] - a^3/(48*(Sqrt[b]*Cot[x]^2 + Sqrt[a + b*Cot[x]^4])^3) - (a^2*Sqrt[b])/(16*(Sqrt[b]*Cot[x]^2 + Sqrt[a + b*Cot[x]^4])^2) - (a*(5*a + 4*b))/(16*(Sqrt[b]*Cot[x]^2 + Sqrt[a + b*Cot[x]^4])) - (1/16)*(5*a + 4*b)*(Sqrt[b]*Cot[x]^2 + Sqrt[a + b*Cot[x]^4]) + (1/16)*Sqrt[b]*(Sqrt[b]*Cot[x]^2 + Sqrt[a + b*Cot[x]^4])^2 - (1/48)*(Sqrt[b]*Cot[x]^2 + Sqrt[a + b*Cot[x]^4])^3 + (1/4)*Sqrt[b]*(3*a + 2*b)*Log[Sqrt[b]*Cot[x]^2 + Sqrt[a + b*Cot[x]^4]]} *)
{Cot[x]*Sqrt[a + b*Cot[x]^4], x, 8, Sqrt[a + b]*ArcTanh[(Sqrt[a + b*Cot[x]^4] + Sqrt[b]*Csc[x]^2)/Sqrt[a + b]] + (1/4)*((-Sqrt[b])*Cot[x]^2 - Sqrt[a + b*Cot[x]^4]) - a/(4*(Sqrt[b]*Cot[x]^2 + Sqrt[a + b*Cot[x]^4])) + (1/2)*Sqrt[b]*Log[Sqrt[b]*Cot[x]^2 + Sqrt[a + b*Cot[x]^4]]}
{Cot[x]/Sqrt[a + b*Cot[x]^4], x, 3, ArcTanh[(a - b*Cot[x]^2)/(Sqrt[a + b]*Sqrt[a + b*Cot[x]^4])]/(2*Sqrt[a + b])}
{Cot[x]/(a + b*Cot[x]^4)^(3/2), x, 11, ArcTanh[(Sqrt[a + b*Cot[x]^4] + Sqrt[b]*Csc[x]^2)/Sqrt[a + b]]/(a + b)^(3/2) + Sqrt[b]/((a + b)*(a + (Sqrt[b]*Cot[x]^2 + Sqrt[a + b*Cot[x]^4])^2)) - (Sqrt[b]*Cot[x]^2 + Sqrt[a + b*Cot[x]^4])/((a + b)*(a + (Sqrt[b]*Cot[x]^2 + Sqrt[a + b*Cot[x]^4])^2))}
(* {Cot[x]/(a + b*Cot[x]^4)^(5/2), x, 20, ArcTan[(Sqrt[b]*Cot[x]^2 + Sqrt[a + b*Cot[x]^4])/Sqrt[a]]/(Sqrt[a]*(a + b)^2) - (2*ArcTan[(Sqrt[b]*Cot[x]^2 + Sqrt[a + b*Cot[x]^4])/Sqrt[a]])/(a^(3/2)*(a + b)) + ((a + 2*b)*ArcTan[(Sqrt[b]*Cot[x]^2 + Sqrt[a + b*Cot[x]^4])/Sqrt[a]])/(a^(3/2)*(a + b)^2) + ArcTanh[(Sqrt[a + b*Cot[x]^4] + Sqrt[b]*Csc[x]^2)/Sqrt[a + b]]/(a + b)^(5/2) - (4*a*Sqrt[b])/(3*(a + b)*(a + (Sqrt[b]*Cot[x]^2 + Sqrt[a + b*Cot[x]^4])^2)^3) + (4*a*(Sqrt[b]*Cot[x]^2 + Sqrt[a + b*Cot[x]^4]))/(3*(a + b)*(a + (Sqrt[b]*Cot[x]^2 + Sqrt[a + b*Cot[x]^4])^2)^3) + (2*Sqrt[b])/((a + b)*(a + (Sqrt[b]*Cot[x]^2 + Sqrt[a + b*Cot[x]^4])^2)^2) - (4*(Sqrt[b]*Cot[x]^2 + Sqrt[a + b*Cot[x]^4]))/(3*(a + b)*(a + (Sqrt[b]*Cot[x]^2 + Sqrt[a + b*Cot[x]^4])^2)^2) + Sqrt[b]/((a + b)^2*(a + (Sqrt[b]*Cot[x]^2 + Sqrt[a + b*Cot[x]^4])^2)) - (2*(Sqrt[b]*Cot[x]^2 + Sqrt[a + b*Cot[x]^4]))/(a*(a + b)*(a + (Sqrt[b]*Cot[x]^2 + Sqrt[a + b*Cot[x]^4])^2)) + ((a + 2*b)*(Sqrt[b]*Cot[x]^2 + Sqrt[a + b*Cot[x]^4]))/(a*(a + b)^2*(a + (Sqrt[b]*Cot[x]^2 + Sqrt[a + b*Cot[x]^4])^2))} *)


(* ::Subsection::Closed:: *)
(*Integrands of the form x^q Trig[x]^m (a+b Trig[x]^n)^p*)
(**)


{x*Cos[x]/(a + b*Sin[x])^2, x, 2, (2*ArcTan[(b + a*Tan[x/2])/Sqrt[a^2 - b^2]])/(b*Sqrt[a^2 - b^2]) - x/(b*(a + b*Sin[x]))}
{x*Cos[x]/(a + b*Sin[x])^3, x, 4, (a*ArcTan[(b + a*Tan[x/2])/Sqrt[a^2 - b^2]])/(b*(a^2 - b^2)^(3/2)) - x/(2*b*(a + b*Sin[x])^2) + Cos[x]/(2*(a^2 - b^2)*(a + b*Sin[x]))}


{x*Sin[x]/(a + b*Cos[x])^2, x, 2, -((2*ArcTan[((a - b)*Tan[x/2])/Sqrt[a^2 - b^2]])/(b*Sqrt[a^2 - b^2])) + x/(b*(a + b*Cos[x]))}
{x*Sin[x]/(a + b*Cos[x])^3, x, 4, -((a*ArcTan[((a - b)*Tan[x/2])/Sqrt[a^2 - b^2]])/(b*(a^2 - b^2)^(3/2))) + x/(2*b*(a + b*Cos[x])^2) + Sin[x]/(2*(a^2 - b^2)*(a + b*Cos[x]))}


{x*Sec[x]^2/(a + b*Tan[x])^2, x, 2, (a*x)/(b*(a^2 + b^2)) + Log[a*Cos[x] + b*Sin[x]]/(a^2 + b^2) - x/(b*(a + b*Tan[x]))}
{x*Csc[x]^2/(a + b*Cot[x])^2, x, 2, -((a*x)/(b*(a^2 + b^2))) + x/(b*(a + b*Cot[x])) + Log[b*Cos[x] + a*Sin[x]]/(a^2 + b^2)}


(* ::Subsection::Closed:: *)
(*Integrands of the form (A+B Trig[x]) (a+b Trig[x])^n*)


{(A + B*Sec[x])*(a + a*Cos[x]), x, 4, a*(A + B)*x + a*B*ArcTanh[Sin[x]] + a*A*Sin[x]}
{(A + B*Sec[x])*(a + a*Cos[x])^2, x, 5, (1/2)*a^2*(3*A + 4*B)*x + a^2*B*ArcTanh[Sin[x]] + a^2*B*Sin[x] + (1/2)*a^2*A*(4 + Cos[x])*Sin[x]}
{(A + B*Sec[x])*(a + a*Cos[x])^3, x, 6, (1/2)*a^3*(5*A + 7*B)*x + a^3*B*ArcTanh[Sin[x]] + (5/2)*a^3*(A + B)*Sin[x] + (1/6)*a^3*(5*A + 3*B)*(1 + Cos[x])*Sin[x] + (1/3)*a^3*A*(1 + Cos[x])^2*Sin[x]}
{(A + B*Sec[x])*(a + a*Cos[x])^4, x, 7, (1/8)*a^4*(35*A + 48*B)*x + a^4*B*ArcTanh[Sin[x]] + (5/8)*a^4*(7*A + 8*B)*Sin[x] + (1/24)*a^4*(35*A + 32*B)*(1 + Cos[x])*Sin[x] + (1/12)*a^4*(7*A + 4*B)*(1 + Cos[x])^2*Sin[x] + (1/4)*a^4*A*(1 + Cos[x])^3*Sin[x]}


{(A + B*Sec[x])/(a + a*Cos[x]), x, 3, (B*ArcTanh[Sin[x]])/a + ((A - B)*Sin[x])/(a*(1 + Cos[x]))}
{(A + B*Sec[x])/(a + a*Cos[x])^2, x, 4, (B*ArcTanh[Sin[x]])/a^2 + ((A - B)*Sin[x])/(3*a^2*(1 + Cos[x])^2) + ((A - 4*B)*Sin[x])/(3*a^2*(1 + Cos[x]))}
{(A + B*Sec[x])/(a + a*Cos[x])^3, x, 5, (B*ArcTanh[Sin[x]])/a^3 + ((A - B)*Sin[x])/(5*a^3*(1 + Cos[x])^3) + ((2*A - 7*B)*Sin[x])/(15*a^3*(1 + Cos[x])^2) + (2*(A - 11*B)*Sin[x])/(15*a^3*(1 + Cos[x]))}
{(A + B*Sec[x])/(a + a*Cos[x])^4, x, 6, (B*ArcTanh[Sin[x]])/a^4 + ((A - B)*Sin[x])/(7*a^4*(1 + Cos[x])^4) + ((3*A - 10*B)*Sin[x])/(35*a^4*(1 + Cos[x])^3) + ((6*A - 55*B)*Sin[x])/(105*a^4*(1 + Cos[x])^2) + (2*(3*A - 80*B)*Sin[x])/(105*a^4*(1 + Cos[x]))}


{(A + B*Sec[x])*(a + a*Cos[x])^(5/2), x, 5, (2*Sqrt[2]*a^3*B*ArcTanh[Sqrt[2]*Sin[x/2]]*Cos[x/2])/Sqrt[a + a*Cos[x]] + (2*a^3*(32*A + 35*B)*Sin[x])/(15*Sqrt[a + a*Cos[x]]) + (2/15)*a^2*(8*A + 5*B)*Sqrt[a + a*Cos[x]]*Sin[x] + (2/5)*a*A*(a + a*Cos[x])^(3/2)*Sin[x]}
{(A + B*Sec[x])*(a + a*Cos[x])^(3/2), x, 4, (2*Sqrt[2]*a^2*B*ArcTanh[Sqrt[2]*Sin[x/2]]*Cos[x/2])/Sqrt[a + a*Cos[x]] + (2*a^2*(4*A + 3*B)*Sin[x])/(3*Sqrt[a + a*Cos[x]]) + (2/3)*a*A*Sqrt[a + a*Cos[x]]*Sin[x]}
{(A + B*Sec[x])*(a + a*Cos[x])^(1/2), x, 3, (2*Sqrt[2]*a*B*ArcTanh[Sqrt[2]*Sin[x/2]]*Cos[x/2])/Sqrt[a + a*Cos[x]] + (2*a*A*Sin[x])/Sqrt[a + a*Cos[x]]}
{(A + B*Sec[x])/(a + a*Cos[x])^(1/2), x, 4, (2*(A - B)*ArcTanh[Sin[x/2]]*Cos[x/2])/Sqrt[a + a*Cos[x]] + (2*Sqrt[2]*B*ArcTanh[Sqrt[2]*Sin[x/2]]*Cos[x/2])/Sqrt[a + a*Cos[x]]}
{(A + B*Sec[x])/(a + a*Cos[x])^(3/2), x, 5, ((A - 5*B)*ArcTanh[Sin[x/2]]*Cos[x/2])/(2*a*Sqrt[a + a*Cos[x]]) + (2*Sqrt[2]*B*ArcTanh[Sqrt[2]*Sin[x/2]]*Cos[x/2])/(a*Sqrt[a + a*Cos[x]]) + ((A - B)*Sin[x])/(2*(a + a*Cos[x])^(3/2))}
{(A + B*Sec[x])/(a + a*Cos[x])^(5/2), x, 6, ((3*A - 43*B)*ArcTanh[Sin[x/2]]*Cos[x/2])/(16*a^2*Sqrt[a + a*Cos[x]]) + (2*Sqrt[2]*B*ArcTanh[Sqrt[2]*Sin[x/2]]*Cos[x/2])/(a^2*Sqrt[a + a*Cos[x]]) + ((A - B)*Sin[x])/(4*(a + a*Cos[x])^(5/2)) + ((3*A - 11*B)*Sin[x])/(16*a*(a + a*Cos[x])^(3/2))}


(* ::Subsection::Closed:: *)
(*Integrands of the form x^m (A+B Trig[x]) (a+b Trig[x])^n*)


{x*((b + a*Sin[x])/(a + b*Sin[x])^2), x, 3, Log[a + b*Sin[x]]/b - (x*Cos[x])/(a + b*Sin[x])}
{x*((b + a*Cos[x])/(a + b*Cos[x])^2), x, 3, Log[a + b*Cos[x]]/b + (x*Sin[x])/(a + b*Cos[x])}


(* ::Subsection::Closed:: *)
(*Integrands of the form (A+B Trig[x]^m)^p / (a+b Trig[x]^n)*)
(**)


{(1 + Sin[x]^2)/(1 - Sin[x]^2), x, 4, -x + 2*Tan[x]}
{(1 - Sin[x]^2)/(1 + Sin[x]^2), x, 5, -x - Sqrt[2]*ArcTan[Cot[x]/Sqrt[2]]}


{(1 + Cos[x]^2)/(1 - Cos[x]^2), x, 4, -x - 2*Cot[x]}
{(1 - Cos[x]^2)/(1 + Cos[x]^2), x, 5, -x + Sqrt[2]*ArcTan[Tan[x]/Sqrt[2]]}


(* Integrands of the form (a+b*Sin[x]^2)/(c+d*Cos[x]^n) where n is an integer *)
{(-1 + c^2/d^2 + Sin[x]^2)/(c + d*Cos[x]), x, 3, (c*x)/d^2 - Sin[x]/d}
{(a + b*Sin[x]^2)/(c + d*Cos[x]), x, 4, (b*c*x)/d^2 + (2*(a*d^2 - b*(c^2 - d^2))*ArcTan[((c - d)*Tan[x/2])/Sqrt[c^2 - d^2]])/(d^2*Sqrt[c^2 - d^2]) - (b*Sin[x])/d}

{(a + b*Sin[x]^2)/(c + c*Cos[x]^2), x, 4, -((b*x)/c) + ((a + 2*b)*ArcTan[Tan[x]/Sqrt[2]])/(Sqrt[2]*c)}
{(a + b*Sin[x]^2)/(c - c*Cos[x]^2), x, 4, (b*x)/c - (a*Cot[x])/c}
{(a + b*Sin[x]^2)/(c + d*Cos[x]^2), x, 4, -((b*x)/d) + ((b*c + (a + b)*d)*ArcTan[(Sqrt[c]*Tan[x])/Sqrt[c + d]])/(Sqrt[c]*d*Sqrt[c + d])}


(* Integrands of the form (a+b*Cos[x]^2)/(c+d*Sin[x]^n) where n is an integer *)
{(-1 + c^2/d^2 + Cos[x]^2)/(c + d*Sin[x]), x, 3, (c*x)/d^2 + Cos[x]/d}
{(a + b*Cos[x]^2)/(c + d*Sin[x]), x, 4, (b*c*x)/d^2 + (2*(a*d^2 - b*(c^2 - d^2))*ArcTan[(d + c*Tan[x/2])/Sqrt[c^2 - d^2]])/(d^2*Sqrt[c^2 - d^2]) + (b*Cos[x])/d}

{(a + b*Cos[x]^2)/(c + c*Sin[x]^2), x, 4, -((b*x)/c) - ((a + 2*b)*ArcTan[Cot[x]/Sqrt[2]])/(Sqrt[2]*c)}
{(a + b*Cos[x]^2)/(c - c*Sin[x]^2), x, 4, (b*x)/c + (a*Tan[x])/c}
{(a + b*Cos[x]^2)/(c + d*Sin[x]^2), x, 4, -((b*x)/d) - ((b*c + (a + b)*d)*ArcTan[(Sqrt[c]*Cot[x])/Sqrt[c + d]])/(Sqrt[c]*d*Sqrt[c + d])}


{(a + b*Sec[x]^2)/(c + d*Cos[x]), x, 5, (2*(a*c^2 + b*d^2)*ArcTan[((c - d)*Tan[x/2])/Sqrt[c^2 - d^2]])/(c^2*Sqrt[c^2 - d^2]) - (b*d*ArcTanh[Sin[x]])/c^2 + (b*Tan[x])/c}
{(a + b*Csc[x]^2)/(c + d*Sin[x]), x, 5, (2*(a*c^2 + b*d^2)*ArcTan[(d + c*Tan[x/2])/Sqrt[c^2 - d^2]])/(c^2*Sqrt[c^2 - d^2]) + (b*d*ArcTanh[Cos[x]])/c^2 - (b*Cot[x])/c}


(* {Sqrt[1 + Sin[x]]/(1 - Tan[x]^2), x, 0, 0} *)


(* ::Subsection::Closed:: *)
(*Integrands of the form (a Trig[c+d x] + b Trig[c+d x])^n*)


(* ::Subsubsection::Closed:: *)
(*Integrands of the form (a Cos[c+d x] + b Sin[c+d x])^n*)


(* Integrands of the form (a*Cos[x]+b*Sin[x])^n where n is an integer *)
{(a*Cos[x] + b*Sin[x])^5, x, 3, (-(a^2 + b^2)^2)*(b*Cos[x] - a*Sin[x]) + (2/3)*(a^2 + b^2)*(b*Cos[x] - a*Sin[x])^3 - (1/5)*(b*Cos[x] - a*Sin[x])^5}
{(a*Cos[x] + b*Sin[x])^4, x, 3, (3/8)*(a^2 + b^2)^2*x - (3/8)*(a^2 + b^2)*(b*Cos[x] - a*Sin[x])*(a*Cos[x] + b*Sin[x]) - (1/4)*(b*Cos[x] - a*Sin[x])*(a*Cos[x] + b*Sin[x])^3}
{(a*Cos[x] + b*Sin[x])^3, x, 2, -((a^2 + b^2)*(b*Cos[x] - a*Sin[x])) + (1/3)*(b*Cos[x] - a*Sin[x])^3}
{(a*Cos[x] + b*Sin[x])^2, x, 2, (1/2)*(a^2 + b^2)*x - (1/2)*(b*Cos[x] - a*Sin[x])*(a*Cos[x] + b*Sin[x])}
{(a*Cos[x] + b*Sin[x]), x, 3, (-b)*Cos[x] + a*Sin[x]}
{1/(a*Cos[x] + b*Sin[x]), x, 1, -((2*ArcTanh[(b - a*Tan[x/2])/Sqrt[a^2 + b^2]])/Sqrt[a^2 + b^2])}
{1/(a*Cos[x] + b*Sin[x])^2, x, 1, Sin[x]/(a*(a*Cos[x] + b*Sin[x]))}
{1/(a*Cos[x] + b*Sin[x])^3, x, 2, -(ArcTanh[(b - a*Tan[x/2])/Sqrt[a^2 + b^2]]/(a^2 + b^2)^(3/2)) - (b*Cos[x] - a*Sin[x])/(2*(a^2 + b^2)*(a*Cos[x] + b*Sin[x])^2)}
{1/(a*Cos[x] + b*Sin[x])^4, x, 2, -((b*Cos[x] - a*Sin[x])/(3*(a^2 + b^2)*(a*Cos[x] + b*Sin[x])^3)) + (2*Sin[x])/(3*a*(a^2 + b^2)*(a*Cos[x] + b*Sin[x]))}
{1/(a*Cos[x] + b*Sin[x])^5, x, 3, -((3*ArcTanh[(b - a*Tan[x/2])/Sqrt[a^2 + b^2]])/(4*(a^2 + b^2)^(5/2))) - (b*Cos[x] - a*Sin[x])/(4*(a^2 + b^2)*(a*Cos[x] + b*Sin[x])^4) - (3*(b*Cos[x] - a*Sin[x]))/(8*(a^2 + b^2)^2*(a*Cos[x] + b*Sin[x])^2)}

{(2*Cos[x] + 3*Sin[x])^(7/2), x, 4, (130/21)*13^(3/4)*EllipticF[(1/2)*(x - ArcTan[3/2]), 2] - (130/21)*(3*Cos[x] - 2*Sin[x])*Sqrt[2*Cos[x] + 3*Sin[x]] - (2/7)*(3*Cos[x] - 2*Sin[x])*(2*Cos[x] + 3*Sin[x])^(5/2)}
{(2*Cos[x] + 3*Sin[x])^(5/2), x, 3, (78/5)*13^(1/4)*EllipticE[(1/2)*(x - ArcTan[3/2]), 2] - (2/5)*(3*Cos[x] - 2*Sin[x])*(2*Cos[x] + 3*Sin[x])^(3/2)}
{(2*Cos[x] + 3*Sin[x])^(3/2), x, 3, (2/3)*13^(3/4)*EllipticF[(1/2)*(x - ArcTan[3/2]), 2] - (2/3)*(3*Cos[x] - 2*Sin[x])*Sqrt[2*Cos[x] + 3*Sin[x]]}
{(2*Cos[x] + 3*Sin[x])^(1/2), x, 2, 2*13^(1/4)*EllipticE[(1/2)*(x - ArcTan[3/2]), 2]}
{1/(2*Cos[x] + 3*Sin[x])^(1/2), x, 2, (2*EllipticF[(1/2)*(x - ArcTan[3/2]), 2])/13^(1/4)}
{1/(2*Cos[x] + 3*Sin[x])^(3/2), x, 3, -((2*EllipticE[(1/2)*(x - ArcTan[3/2]), 2])/13^(3/4)) - (2*(3*Cos[x] - 2*Sin[x]))/(13*Sqrt[2*Cos[x] + 3*Sin[x]])}
{1/(2*Cos[x] + 3*Sin[x])^(5/2), x, 3, (2*EllipticF[(1/2)*(x - ArcTan[3/2]), 2])/(39*13^(1/4)) - (2*(3*Cos[x] - 2*Sin[x]))/(39*(2*Cos[x] + 3*Sin[x])^(3/2))}
{1/(2*Cos[x] + 3*Sin[x])^(7/2), x, 4, -((6*EllipticE[(1/2)*(x - ArcTan[3/2]), 2])/(65*13^(3/4))) - (2*(3*Cos[x] - 2*Sin[x]))/(65*(2*Cos[x] + 3*Sin[x])^(5/2)) - (6*(3*Cos[x] - 2*Sin[x]))/(845*Sqrt[2*Cos[x] + 3*Sin[x]])}

{(a*Cos[x] + b*Sin[x])^(5/2), x, 3, (-(2/5))*(b*Cos[x] - a*Sin[x])*(a*Cos[x] + b*Sin[x])^(3/2) + (6*(a^2 + b^2)*EllipticE[(1/2)*(x - ArcTan[a, b]), 2]*Sqrt[a*Cos[x] + b*Sin[x]])/(5*Sqrt[(a*Cos[x] + b*Sin[x])/Sqrt[a^2 + b^2]])}
{(a*Cos[x] + b*Sin[x])^(3/2), x, 3, (-(2/3))*(b*Cos[x] - a*Sin[x])*Sqrt[a*Cos[x] + b*Sin[x]] + (2*(a^2 + b^2)*EllipticF[(1/2)*(x - ArcTan[a, b]), 2]*Sqrt[(a*Cos[x] + b*Sin[x])/Sqrt[a^2 + b^2]])/(3*Sqrt[a*Cos[x] + b*Sin[x]])}
{(a*Cos[x] + b*Sin[x])^(1/2), x, 2, (2*EllipticE[(1/2)*(x - ArcTan[a, b]), 2]*Sqrt[a*Cos[x] + b*Sin[x]])/Sqrt[(a*Cos[x] + b*Sin[x])/Sqrt[a^2 + b^2]]}
{1/(a*Cos[x] + b*Sin[x])^(1/2), x, 2, (2*EllipticF[(1/2)*(x - ArcTan[a, b]), 2]*Sqrt[(a*Cos[x] + b*Sin[x])/Sqrt[a^2 + b^2]])/Sqrt[a*Cos[x] + b*Sin[x]]}
{1/(a*Cos[x] + b*Sin[x])^(3/2), x, 3, -((2*(b*Cos[x] - a*Sin[x]))/((a^2 + b^2)*Sqrt[a*Cos[x] + b*Sin[x]])) - (2*EllipticE[(1/2)*(x - ArcTan[a, b]), 2]*Sqrt[a*Cos[x] + b*Sin[x]])/((a^2 + b^2)*Sqrt[(a*Cos[x] + b*Sin[x])/Sqrt[a^2 + b^2]])}
{1/(a*Cos[x] + b*Sin[x])^(5/2), x, 3, -((2*(b*Cos[x] - a*Sin[x]))/(3*(a^2 + b^2)*(a*Cos[x] + b*Sin[x])^(3/2))) + (2*EllipticF[(1/2)*(x - ArcTan[a, b]), 2]*Sqrt[(a*Cos[x] + b*Sin[x])/Sqrt[a^2 + b^2]])/(3*(a^2 + b^2)*Sqrt[a*Cos[x] + b*Sin[x]])}


(* Integrands of the form (a*Cos[c+d*x]+I*a*Sin[c+d*x])^n *)
{(a*Cos[c + d*x] + I*a*Sin[c + d*x]), x, 3, -((I*a*Cos[c + d*x])/d) + (a*Sin[c + d*x])/d}
{(a*Cos[c + d*x] + I*a*Sin[c + d*x])^2, x, 1, -((I*a^2*(Cos[c + d*x] + I*Sin[c + d*x])^2)/(2*d))}
{(a*Cos[c + d*x] + I*a*Sin[c + d*x])^3, x, 1, -((I*a^3*(Cos[c + d*x] + I*Sin[c + d*x])^3)/(3*d))}
{(a*Cos[c + d*x] + I*a*Sin[c + d*x])^n, x, 1, -((I*(a*Cos[c + d*x] + I*a*Sin[c + d*x])^n)/(d*n))}

{1/(a*Cos[c + d*x] + I*a*Sin[c + d*x]), x, 1, (I*(Cos[c + d*x] - I*Sin[c + d*x]))/(a*d)}
{1/(a*Cos[c + d*x] + I*a*Sin[c + d*x])^2, x, 1, (I*(Cos[c + d*x] - I*Sin[c + d*x])^2)/(2*a^2*d)}
{1/(a*Cos[c + d*x] + I*a*Sin[c + d*x])^3, x, 1, (I*(Cos[c + d*x] - I*Sin[c + d*x])^3)/(3*a^3*d)}

{Sqrt[a*Cos[c + d*x] + I*a*Sin[c + d*x]], x, 1, -((2*I*Sqrt[a*Cos[c + d*x] + I*a*Sin[c + d*x]])/d)}
{1/Sqrt[a*Cos[c + d*x] + I*a*Sin[c + d*x]], x, 1, (2*I)/(d*Sqrt[a*Cos[c + d*x] + I*a*Sin[c + d*x]])}


(* Integrands of the form (a*Cos[c+d*x]-I*a*Sin[c+d*x])^n *)
{(a*Cos[c + d*x] - I*a*Sin[c + d*x]), x, 3, (I*a*Cos[c + d*x])/d + (a*Sin[c + d*x])/d}
{(a*Cos[c + d*x] - I*a*Sin[c + d*x])^2, x, 1, (I*a^2*(Cos[c + d*x] - I*Sin[c + d*x])^2)/(2*d)}
{(a*Cos[c + d*x] - I*a*Sin[c + d*x])^3, x, 1, (I*a^3*(Cos[c + d*x] - I*Sin[c + d*x])^3)/(3*d)}
{(a*Cos[c + d*x] - I*a*Sin[c + d*x])^n, x, 1, (I*(a*Cos[c + d*x] - I*a*Sin[c + d*x])^n)/(d*n)}

{1/(a*Cos[c + d*x] - I*a*Sin[c + d*x]), x, 1, -((I*(Cos[c + d*x] + I*Sin[c + d*x]))/(a*d))}
{1/(a*Cos[c + d*x] - I*a*Sin[c + d*x])^2, x, 1, -((I*(Cos[c + d*x] + I*Sin[c + d*x])^2)/(2*a^2*d))}
{1/(a*Cos[c + d*x] - I*a*Sin[c + d*x])^3, x, 1, -((I*(Cos[c + d*x] + I*Sin[c + d*x])^3)/(3*a^3*d))}

{Sqrt[a*Cos[c + d*x] - I*a*Sin[c + d*x]], x, 1, (2*I*Sqrt[a*Cos[c + d*x] - I*a*Sin[c + d*x]])/d}
{1/Sqrt[a*Cos[c + d*x] - I*a*Sin[c + d*x]], x, 1, -((2*I)/(d*Sqrt[a*Cos[c + d*x] - I*a*Sin[c + d*x]]))}


(* ::Subsubsection::Closed:: *)
(*Integrands of the form (a Sec[c+d x] + b Tan[c+d x])^n*)


(* Integrands of the form (a*Sec[x]+b*Tan[x])^n where n is an integer *)
{(a*Sec[x] + b*Tan[x]), x, 3, a*ArcTanh[Sin[x]] - b*Log[Cos[x]]}
{(a*Sec[x] + b*Tan[x])^2, x, 5, (-b^2)*x + 2*a*b*Sec[x] + a^2*Tan[x] + b^2*Tan[x]}
{(a*Sec[x] + b*Tan[x])^3, x, 8, (-(1/4))*(a - 2*b)*(a + b)^2*Log[1 - Sin[x]] + (1/4)*(a - b)^2*(a + 2*b)*Log[1 + Sin[x]] + (a + b)^3/(4*(1 - Sin[x])) - (a - b)^3/(4*(1 + Sin[x]))}
{(a*Sec[x] + b*Tan[x])^4, x, 11, b^4*x - 4*a*b^3*Sec[x] + (4/3)*a^3*b*Sec[x]^3 + (4/3)*a*b^3*Sec[x]^3 + a^4*Tan[x] - b^4*Tan[x] + (1/3)*a^4*Tan[x]^3 + 2*a^2*b^2*Tan[x]^3 + (1/3)*b^4*Tan[x]^3}
{(a*Sec[x] + b*Tan[x])^5, x, 11, (-(1/16))*(a + b)^3*(3*a^2 - 9*a*b + 8*b^2)*Log[1 - Sin[x]] + (1/16)*(a - b)^3*(3*a^2 + 9*a*b + 8*b^2)*Log[1 + Sin[x]] + (a + b)^5/(16*(1 - Sin[x])^2) + ((3*a - 7*b)*(a + b)^4)/(16*(1 - Sin[x])) - (a - b)^5/(16*(1 + Sin[x])^2) - ((a - b)^4*(3*a + 7*b))/(16*(1 + Sin[x]))}

{1/(a*Sec[x] + b*Tan[x]), x, 3, Log[a + b*Sin[x]]/b}
{1/(a*Sec[x] + b*Tan[x])^2, x, 7, -(x/b^2) + (2*a*ArcTan[(b + a*Tan[x/2])/Sqrt[a^2 - b^2]])/(b^2*Sqrt[a^2 - b^2]) - Cos[x]/(b*(a + b*Sin[x]))}
{1/(a*Sec[x] + b*Tan[x])^3, x, 7, -(Log[a + b*Sin[x]]/b^3) + (a^2 - b^2)/(2*b^3*(a + b*Sin[x])^2) - (2*a)/(b^3*(a + b*Sin[x]))}
{1/(a*Sec[x] + b*Tan[x])^4, x, 16, x/b^4 + (2*a^3*ArcTan[(b + a*Tan[x/2])/Sqrt[a^2 - b^2]])/(b^4*(a^2 - b^2)^(3/2)) - (a*ArcTan[(b + a*Tan[x/2])/Sqrt[a^2 - b^2]])/(b^2*(a^2 - b^2)^(3/2)) - (4*a*ArcTan[(b + a*Tan[x/2])/Sqrt[a^2 - b^2]])/(b^4*Sqrt[a^2 - b^2]) + ((a^2 - b^2)*Cos[x])/(3*b^3*(a + b*Sin[x])^3) - (7*a*Cos[x])/(6*b^3*(a + b*Sin[x])^2) + (11*a^2*Cos[x])/(6*b^3*(a^2 - b^2)*(a + b*Sin[x])) - (4*Cos[x])/(3*b*(a^2 - b^2)*(a + b*Sin[x]))}
{1/(a*Sec[x] + b*Tan[x])^5, x, 9, Log[a + b*Sin[x]]/b^5 - (a^2 - b^2)^2/(4*b^5*(a + b*Sin[x])^4) + (4*a*(a^2 - b^2))/(3*b^5*(a + b*Sin[x])^3) - (3*a^2 - b^2)/(b^5*(a + b*Sin[x])^2) + (4*a)/(b^5*(a + b*Sin[x]))}


(* Integrands of the form (Sec[x]+Tan[x])^n where n is an integer *)
{(Sec[x] + Tan[x]), x, 3, -2*Log[Cos[(1/4)*(Pi + 2*x)]], ArcTanh[Sin[x]] - Log[Cos[x]]}
{(Sec[x] + Tan[x])^2, x, 2, -x + 2*Tan[Pi/4 + x/2]}
{(Sec[x] + Tan[x])^3, x, 6, Log[1 - Sin[x]] + 2/(1 - Sin[x])}
{(Sec[x] + Tan[x])^4, x, 3, x - 2*Tan[Pi/4 + x/2] + (2/3)*Tan[Pi/4 + x/2]^3}
{(Sec[x] + Tan[x])^5, x, 8, -Log[1 - Sin[x]] + 2/(1 - Sin[x])^2 - 4/(1 - Sin[x])}

{1/(Sec[x] + Tan[x]), x, 3, Log[1 + Sin[x]]}
{1/(Sec[x] + Tan[x])^2, x, 2, -x - 2*Cot[Pi/4 + x/2]}
{1/(Sec[x] + Tan[x])^3, x, 6, -Log[1 + Sin[x]] - 2/(1 + Sin[x])}
{1/(Sec[x] + Tan[x])^4, x, 3, x + 2*Cot[Pi/4 + x/2] - (2/3)*Cot[Pi/4 + x/2]^3}
{1/(Sec[x] + Tan[x])^5, x, 7, Log[1 + Sin[x]] - 2/(1 + Sin[x])^2 + 4/(1 + Sin[x])}


(* Integrands of the form (Sec[x]-Tan[x])^n where n is an integer *)
{(Sec[x] - Tan[x]), x, 3, 2*Log[Sin[(1/4)*(Pi + 2*x)]], ArcTanh[Sin[x]] + Log[Cos[x]]}
{(Sec[x] - Tan[x])^2, x, 2, -x - 2*Tan[Pi/4 - x/2]}
{(Sec[x] - Tan[x])^3, x, 6, -Log[1 + Sin[x]] - 2/(1 + Sin[x])}
{(Sec[x] - Tan[x])^4, x, 3, x + 2*Tan[Pi/4 - x/2] - (2/3)*Tan[Pi/4 - x/2]^3}
{(Sec[x] - Tan[x])^5, x, 7, Log[1 + Sin[x]] - 2/(1 + Sin[x])^2 + 4/(1 + Sin[x])}

{1/(Sec[x] - Tan[x]), x, 3, -Log[1 - Sin[x]]}
{1/(Sec[x] - Tan[x])^2, x, 2, -x + 2*Cot[Pi/4 - x/2]}
{1/(Sec[x] - Tan[x])^3, x, 6, Log[1 - Sin[x]] + 2/(1 - Sin[x])}
{1/(Sec[x] - Tan[x])^4, x, 3, x - 2*Cot[Pi/4 - x/2] + (2/3)*Cot[Pi/4 - x/2]^3}
{1/(Sec[x] - Tan[x])^5, x, 8, -Log[1 - Sin[x]] + 2/(1 - Sin[x])^2 - 4/(1 - Sin[x])}


(* ::Subsubsection::Closed:: *)
(*Integrands of the form (a Cot[c+d x] + b Csc[c+d x])^n*)


(* Integrands of the form (a*Cot[x]+b*Csc[x])^n where n is an integer *)
{(a*Cot[x] + b*Csc[x]), x, 3, (-b)*ArcTanh[Cos[x]] + a*Log[Sin[x]]}
{(a*Cot[x] + b*Csc[x])^2, x, 5, (-a^2)*x - a^2*Cot[x] - b^2*Cot[x] - 2*a*b*Csc[x]}
{(a*Cot[x] + b*Csc[x])^3, x, 8, -((a + b)^3/(4*(1 - Cos[x]))) - (a - b)^3/(4*(1 + Cos[x])) - (1/4)*(2*a - b)*(a + b)^2*Log[1 - Cos[x]] - (1/4)*(a - b)^2*(2*a + b)*Log[1 + Cos[x]]}
{(a*Cot[x] + b*Csc[x])^4, x, 11, a^4*x + a^4*Cot[x] - b^4*Cot[x] - (1/3)*a^4*Cot[x]^3 - 2*a^2*b^2*Cot[x]^3 - (1/3)*b^4*Cot[x]^3 + 4*a^3*b*Csc[x] - (4/3)*a^3*b*Csc[x]^3 - (4/3)*a*b^3*Csc[x]^3}
{(a*Cot[x] + b*Csc[x])^5, x, 11, -((a + b)^5/(16*(1 - Cos[x])^2)) + ((7*a - 3*b)*(a + b)^4)/(16*(1 - Cos[x])) - (a - b)^5/(16*(1 + Cos[x])^2) + ((a - b)^4*(7*a + 3*b))/(16*(1 + Cos[x])) + (1/16)*(a + b)^3*(8*a^2 - 9*a*b + 3*b^2)*Log[1 - Cos[x]] + (1/16)*(a - b)^3*(8*a^2 + 9*a*b + 3*b^2)*Log[1 + Cos[x]]}

{1/(a*Cot[x] + b*Csc[x]), x, 3, -(Log[b + a*Cos[x]]/a)}
{1/(a*Cot[x] + b*Csc[x])^2, x, 7, -(x/a^2) + (2*b*ArcTanh[((a - b)*Tan[x/2])/Sqrt[a^2 - b^2]])/(a^2*Sqrt[a^2 - b^2]) + Sin[x]/(a*(b + a*Cos[x]))}
{1/(a*Cot[x] + b*Csc[x])^3, x, 7, (a^2 - b^2)/(2*a^3*(b + a*Cos[x])^2) + (2*b)/(a^3*(b + a*Cos[x])) + Log[b + a*Cos[x]]/a^3}
{1/(a*Cot[x] + b*Csc[x])^4, x, 16, x/a^4 + (5*b*ArcTanh[((a - b)*Tan[x/2])/Sqrt[a^2 - b^2]])/(a^2*(a^2 - b^2)^(3/2)) - (6*b^3*ArcTanh[((a - b)*Tan[x/2])/Sqrt[a^2 - b^2]])/(a^4*(a^2 - b^2)^(3/2)) - (8*b*ArcTanh[((a - b)*Tan[x/2])/Sqrt[a^2 - b^2]])/(a^4*Sqrt[a^2 - b^2]) + ((a^2 - b^2)*Sin[x])/(3*a^3*(b + a*Cos[x])^3) + (7*b*Sin[x])/(6*a^3*(b + a*Cos[x])^2) - (4*Sin[x])/(3*a*(a^2 - b^2)*(b + a*Cos[x])) + (11*b^2*Sin[x])/(6*a^3*(a^2 - b^2)*(b + a*Cos[x]))}
{1/(a*Cot[x] + b*Csc[x])^5, x, 9, (a^2 - b^2)^2/(4*a^5*(b + a*Cos[x])^4) + (4*b*(a^2 - b^2))/(3*a^5*(b + a*Cos[x])^3) - (a^2 - 3*b^2)/(a^5*(b + a*Cos[x])^2) - (4*b)/(a^5*(b + a*Cos[x])) - Log[b + a*Cos[x]]/a^5}


(* Integrands of the form (Csc[x]+Cot[x])^n where n is an integer *)
{(Csc[x] + Cot[x]), x, 3, -ArcTanh[Cos[x]] + Log[Sin[x]]}
{(Csc[x] + Cot[x])^2, x, 2, -x - 2*Cot[x/2]}
{(Csc[x] + Cot[x])^3, x, 6, -(2/(1 - Cos[x])) - Log[1 - Cos[x]]}
{(Csc[x] + Cot[x])^4, x, 3, x + 2*Cot[x/2] - (2/3)*Cot[x/2]^3}
{(Csc[x] + Cot[x])^5, x, 8, -(2/(1 - Cos[x])^2) + 4/(1 - Cos[x]) + Log[1 - Cos[x]]}

{1/(Csc[x] + Cot[x]), x, 3, -Log[1 + Cos[x]]}
{1/(Csc[x] + Cot[x])^2, x, 2, -x + 2*Tan[x/2]}
{1/(Csc[x] + Cot[x])^3, x, 6, 2/(1 + Cos[x]) + Log[1 + Cos[x]]}
{1/(Csc[x] + Cot[x])^4, x, 3, x - 2*Tan[x/2] + (2/3)*Tan[x/2]^3}
{1/(Csc[x] + Cot[x])^5, x, 7, 2/(1 + Cos[x])^2 - 4/(1 + Cos[x]) - Log[1 + Cos[x]]}


(* Integrands of the form (Csc[x]-Cot[x])^n where n is an integer *)
{(Csc[x] - Cot[x]), x, 3, -ArcTanh[Cos[x]] - Log[Sin[x]]}
{(Csc[x] - Cot[x])^2, x, 2, -x + 2*Tan[x/2]}
{(Csc[x] - Cot[x])^3, x, 6, 2/(1 + Cos[x]) + Log[1 + Cos[x]]}
{(Csc[x] - Cot[x])^4, x, 3, x - 2*Tan[x/2] + (2/3)*Tan[x/2]^3}
{(Csc[x] - Cot[x])^5, x, 7, 2/(1 + Cos[x])^2 - 4/(1 + Cos[x]) - Log[1 + Cos[x]]}

{1/(Csc[x] - Cot[x]), x, 3, Log[1 - Cos[x]]}
{1/(Csc[x] - Cot[x])^2, x, 2, -x - 2*Cot[x/2]}
{1/(Csc[x] - Cot[x])^3, x, 6, -(2/(1 - Cos[x])) - Log[1 - Cos[x]]}
{1/(Csc[x] - Cot[x])^4, x, 3, x + 2*Cot[x/2] - (2/3)*Cot[x/2]^3}
{1/(Csc[x] - Cot[x])^5, x, 8, -(2/(1 - Cos[x])^2) + 4/(1 - Cos[x]) + Log[1 - Cos[x]]}


(* ::Subsubsection::Closed:: *)
(*Integrands of the form (a Csc[c+d x] + b Sin[c+d x])^n*)


(* Integrands of the form (Csc[x]-Sin[x])^n *)
(* Note that Csc[x]-Sin[x] == Cos[x]*Cot[x] *)
{(Csc[x] - Sin[x]), x, 3, -ArcTanh[Cos[x]] + Cos[x]}
{(Csc[x] - Sin[x])^2, x, 3, -((3*x)/2) - (3*Cot[x])/2 + (1/2)*Cos[x]^2*Cot[x]}
{(Csc[x] - Sin[x])^3, x, 5, (5/2)*ArcTanh[Cos[x]] - (5*Cos[x])/2 - (5/6)*Cos[x]*Cot[x]^2 + (1/3)*Cos[x]^3*Cot[x]^2}

{(Csc[x] - Sin[x])^(1/2), x, 3, 2*Sqrt[Cos[x]*Cot[x]]*Tan[x]}
{(Csc[x] - Sin[x])^(3/2), x, 4, (-(2/3))*(4 - Cos[x]^2)*Sqrt[Cos[x]*Cot[x]]*Sec[x]}
{(Csc[x] - Sin[x])^(5/2), x, 5, (-(2/15))*Sqrt[Cos[x]*Cot[x]]*(32 + (8 - 3*Cos[x]^2)*Cot[x]^2)*Tan[x]}


(* ::Subsubsection::Closed:: *)
(*Integrands of the form (a Sec[c+d x] + b Cos[c+d x])^n*)


(* Integrands of the form (Sec[x]-Cos[x])^n *)
(* Note that Sec[x]-Cos[x] == Sin[x]*Tan[x] *)
{(Sec[x] - Cos[x]), x, 3, ArcTanh[Sin[x]] - Sin[x]}
{(Sec[x] - Cos[x])^2, x, 3, -((3*x)/2) + (3*Tan[x])/2 - (1/2)*Sin[x]^2*Tan[x]}
{(Sec[x] - Cos[x])^3, x, 5, (-(5/2))*ArcTanh[Sin[x]] + (5*Sin[x])/2 + (5/6)*Sin[x]*Tan[x]^2 - (1/3)*Sin[x]^3*Tan[x]^2}

{(Sec[x] - Cos[x])^(1/2), x, 3, -2*Cot[x]*Sqrt[Sin[x]*Tan[x]]}
{(Sec[x] - Cos[x])^(3/2), x, 4, (2/3)*Csc[x]*(4 - Sin[x]^2)*Sqrt[Sin[x]*Tan[x]]}
{(Sec[x] - Cos[x])^(5/2), x, 5, (2/15)*Cot[x]*Sqrt[Sin[x]*Tan[x]]*(32 + (8 - 3*Sin[x]^2)*Tan[x]^2)}


(* ::Subsubsection::Closed:: *)
(*Integrands of the form (a Sin[c+d x] + b Tan[c+d x])^n*)


{1/(Sin[x] + Tan[x]), x, 3, (1/2)*Log[Tan[x/2]] - (1/4)*Tan[x/2]^2}
{1/(Sin[x] - Tan[x]), x, 3, (1/4)*Cot[x/2]^2 + (1/2)*Log[Tan[x/2]]}


(* ::Subsection::Closed:: *)
(*Integrands of the form (a Trig[c+d x]^2 + b Trig[c+d x]^2)^n*)


(* Integrands of the form 1/(Cos[x]^2+/-Sin[x]^2)^n where n is an integer *)
{1/(Cos[x]^2 + Sin[x]^2), x, 2, x}
{1/(Cos[x]^2 + Sin[x]^2)^2, x, 2, x}
{1/(Cos[x]^2 + Sin[x]^2)^3, x, 2, x}

{1/(Cos[x]^2 - Sin[x]^2), x, 2, ArcTanh[Tan[x]], (1/2)*ArcTanh[Sin[2*x]]}
{1/(Cos[x]^2 - Sin[x]^2)^2, x, 2, (1/2)*Tan[2*x]}
{1/(Cos[x]^2 - Sin[x]^2)^3, x, 3, (1/4)*ArcTanh[Sin[2*x]] + (1/4)*Sec[2*x]*Tan[2*x]}


(* Integrands of the form 1/(Sec[x]^2+/-Tan[x]^2)^n where n is an integer *)
{1/(Sec[x]^2 + Tan[x]^2), x, 5, -x - Sqrt[2]*ArcTan[Cot[x]/Sqrt[2]]}
{1/(Sec[x]^2 + Tan[x]^2)^2, x, 9, x + ArcTan[Cot[x]/Sqrt[2]]/Sqrt[2] + Cot[x]/(2 + Cot[x]^2), x + (3*x)/Sqrt[2] + 2*Sqrt[2]*ArcTan[Cot[x]/Sqrt[2]] + (3*ArcTan[Sin[2*x]/(3 + 2*Sqrt[2] - Cos[2*x])])/Sqrt[2] + Sin[2*x]/(3 - Cos[2*x])}
{1/(Sec[x]^2 + Tan[x]^2)^3, x, 14, -x + (7*ArcTan[Sqrt[2]*Tan[x]])/(4*Sqrt[2]) + Tan[x]/(2*(1 + 2*Tan[x]^2)^2) - Tan[x]/(4*(1 + 2*Tan[x]^2)), -x - (17*x)/(4*Sqrt[2]) - 3*Sqrt[2]*ArcTan[Cot[x]/Sqrt[2]] - (17*ArcTan[Sin[2*x]/(3 + 2*Sqrt[2] - Cos[2*x])])/(4*Sqrt[2]) + (2*Sin[2*x])/(3 - Cos[2*x])^2 - (3*Sin[2*x])/(4*(3 - Cos[2*x]))}

{1/(Sec[x]^2 - Tan[x]^2), x, 2, x}
{1/(Sec[x]^2 - Tan[x]^2)^2, x, 2, x}
{1/(Sec[x]^2 - Tan[x]^2)^3, x, 2, x}


(* Integrands of the form 1/(Cot[x]^2+/-Csc[x]^2)^n where n is an integer *)
{1/(Cot[x]^2 + Csc[x]^2), x, 5, -x + Sqrt[2]*ArcTan[Tan[x]/Sqrt[2]]}
{1/(Cot[x]^2 + Csc[x]^2)^2, x, 9, x + ArcTan[Sqrt[2]*Cot[x]]/Sqrt[2] - Cot[x]/(1 + 2*Cot[x]^2), x + (3*x)/Sqrt[2] + 2*Sqrt[2]*ArcTan[Sqrt[2]*Cot[x]] - (3*ArcTan[Sin[2*x]/(3 + 2*Sqrt[2] + Cos[2*x])])/Sqrt[2] - Sin[2*x]/(3 + Cos[2*x])}
{1/(Cot[x]^2 + Csc[x]^2)^3, x, 14, -x - (7*ArcTan[Sqrt[2]*Cot[x]])/(4*Sqrt[2]) + (3*Cot[x])/(2*(1 + 2*Cot[x]^2)^2) + (4*Cot[x]^3)/(1 + 2*Cot[x]^2)^2 - (7*Cot[x])/(4*(1 + 2*Cot[x]^2)), -x - (17*x)/(4*Sqrt[2]) - 3*Sqrt[2]*ArcTan[Sqrt[2]*Cot[x]] + (17*ArcTan[Sin[2*x]/(3 + 2*Sqrt[2] + Cos[2*x])])/(4*Sqrt[2]) - (2*Sin[2*x])/(3 + Cos[2*x])^2 + (3*Sin[2*x])/(4*(3 + Cos[2*x]))}

{1/(Cot[x]^2 - Csc[x]^2), x, 2, -x}
{1/(Cot[x]^2 - Csc[x]^2)^2, x, 2, x}
{1/(Cot[x]^2 - Csc[x]^2)^3, x, 2, -x}


{1/(Cos[x]^2 + a^2*Sin[x]^2), x, 3, -(ArcTan[Cot[x]/a]/a)}
{1/(b^2*Cos[x]^2 + Sin[x]^2), x, 3, -(ArcTan[b*Cot[x]]/b)}
{1/(b^2*Cos[x]^2 + a^2*Sin[x]^2), x, 3, -(ArcTan[(b*Cot[x])/a]/(a*b))}
{1/(4*Cos[1 + 2*x]^2 + 3*Sin[1 + 2*x]^2), x, 3, x/(2*Sqrt[3]) - ArcTan[Sin[2 + 4*x]/(7 + 4*Sqrt[3] + Cos[2 + 4*x])]/(4*Sqrt[3])}


(* ::Subsection::Closed:: *)
(*Integrands of the form (a + b Trig[d+e x] + c Trig[d+e x])^n*)
(**)


(* ::Subsubsection::Closed:: *)
(*Integrands of the form (a + b Cos[d+e x] + c Sin[d+e x])^n*)


(* Integrands of the form (a+b*Cos[x]+c*Sin[x])^n where n is an integer *)
{(a + b*Cos[x] + c*Sin[x])^3, x, 15, (1/2)*a*(2*a^2 + 3*b^2)*x + (3/2)*a*c^2*x - c^3*Cos[x] + (1/3)*c^3*Cos[x]^3 - (c*(a + b*Cos[x])^3)/b + (2/3)*b*(4*a^2 + b^2)*Sin[x] + (5/6)*a*b^2*Cos[x]*Sin[x] - (3/2)*a*c^2*Cos[x]*Sin[x] + (1/3)*b*(a + b*Cos[x])^2*Sin[x] + b*c^2*Sin[x]^3}
{(a + b*Cos[x] + c*Sin[x])^2, x, 7, (1/2)*(2*a^2 + b^2)*x + (c^2*x)/2 - 2*a*c*Cos[x] - b*c*Cos[x]^2 + 2*a*b*Sin[x] + (1/2)*b^2*Cos[x]*Sin[x] - (1/2)*c^2*Cos[x]*Sin[x]}
{(a + b*Cos[x] + c*Sin[x]), x, 3, a*x - c*Cos[x] + b*Sin[x]}
{1/(a + b*Cos[x] + c*Sin[x]), x, 1, (2*ArcTan[(c + (a - b)*Tan[x/2])/Sqrt[a^2 - b^2 - c^2]])/Sqrt[a^2 - b^2 - c^2]}
{1/(a + b*Cos[x] + c*Sin[x])^2, x, 2, (2*a*ArcTan[(c + (a - b)*Tan[x/2])/Sqrt[a^2 - b^2 - c^2]])/(a^2 - b^2 - c^2)^(3/2) + (c*Cos[x] - b*Sin[x])/((a^2 - b^2 - c^2)*(a + b*Cos[x] + c*Sin[x]))}
{1/(a + b*Cos[x] + c*Sin[x])^3, x, 3, ((2*a^2 + b^2 + c^2)*ArcTan[(c + (a - b)*Tan[x/2])/Sqrt[a^2 - b^2 - c^2]])/(a^2 - b^2 - c^2)^(5/2) + (c*Cos[x] - b*Sin[x])/(2*(a^2 - b^2 - c^2)*(a + b*Cos[x] + c*Sin[x])^2) + (3*a*(c*Cos[x] - b*Sin[x]))/(2*(a^2 - b^2 - c^2)^2*(a + b*Cos[x] + c*Sin[x]))}
{1/(a + b*Cos[x] + c*Sin[x])^4, x, 4, (a*(2*a^2 + 3*b^2 + 3*c^2)*ArcTan[(c + (a - b)*Tan[x/2])/Sqrt[a^2 - b^2 - c^2]])/(a^2 - b^2 - c^2)^(7/2) + (c*Cos[x] - b*Sin[x])/(3*(a^2 - b^2 - c^2)*(a + b*Cos[x] + c*Sin[x])^3) + (5*a*(c*Cos[x] - b*Sin[x]))/(6*(a^2 - b^2 - c^2)^2*(a + b*Cos[x] + c*Sin[x])^2) + ((11*a^2 + 4*(b^2 + c^2))*(c*Cos[x] - b*Sin[x]))/(6*(a^2 - b^2 - c^2)^3*(a + b*Cos[x] + c*Sin[x]))}

{(a + a*Cos[x] + c*Sin[x])^3, x, 15, (5*a^3*x)/2 + (3/2)*a*c^2*x - c^3*Cos[x] + (1/3)*c^3*Cos[x]^3 - a^2*c*(1 + Cos[x])^3 + (10/3)*a^3*Sin[x] + (5/6)*a^3*Cos[x]*Sin[x] - (3/2)*a*c^2*Cos[x]*Sin[x] + (1/3)*a^3*(1 + Cos[x])^2*Sin[x] + a*c^2*Sin[x]^3}
{(a + a*Cos[x] + c*Sin[x])^2, x, 7, (3*a^2*x)/2 + (c^2*x)/2 - 2*a*c*Cos[x] - a*c*Cos[x]^2 + 2*a^2*Sin[x] + (1/2)*a^2*Cos[x]*Sin[x] - (1/2)*c^2*Cos[x]*Sin[x]}
{(a + a*Cos[x] + c*Sin[x]), x, 3, a*x - c*Cos[x] + a*Sin[x]}
{1/(a + a*Cos[x] + c*Sin[x]), x, 1, Log[a + c*Tan[x/2]]/c}
{1/(a + a*Cos[x] + c*Sin[x])^2, x, 2, -((a*Log[a + c*Tan[x/2]])/c^3) - (c*Cos[x] - a*Sin[x])/(c^2*(a + a*Cos[x] + c*Sin[x]))}
{1/(a + a*Cos[x] + c*Sin[x])^3, x, 3, ((3*a^2 + c^2)*Log[a + c*Tan[x/2]])/(2*c^5) - (c*Cos[x] - a*Sin[x])/(2*c^2*(a + a*Cos[x] + c*Sin[x])^2) + (3*a*(c*Cos[x] - a*Sin[x]))/(2*c^4*(a + a*Cos[x] + c*Sin[x]))}
{1/(a + a*Cos[x] + c*Sin[x])^4, x, 4, -((a*(5*a^2 + 3*c^2)*Log[a + c*Tan[x/2]])/(2*c^7)) - (c*Cos[x] - a*Sin[x])/(3*c^2*(a + a*Cos[x] + c*Sin[x])^3) + (5*a*(c*Cos[x] - a*Sin[x]))/(6*c^4*(a + a*Cos[x] + c*Sin[x])^2) - ((15*a^2 + 4*c^2)*(c*Cos[x] - a*Sin[x]))/(6*c^6*(a + a*Cos[x] + c*Sin[x]))}

{(Sqrt[b^2 + c^2] + b*Cos[x] + c*Sin[x])^4, x, 6, (35/8)*(b^2 + c^2)^2*x - (35/8)*c*(b^2 + c^2)^(3/2)*Cos[x] + (35/8)*b*(b^2 + c^2)^(3/2)*Sin[x] - (35/24)*(b^2 + c^2)*(c*Cos[x] - b*Sin[x])*(Sqrt[b^2 + c^2] + b*Cos[x] + c*Sin[x]) - (7/12)*Sqrt[b^2 + c^2]*(c*Cos[x] - b*Sin[x])*(Sqrt[b^2 + c^2] + b*Cos[x] + c*Sin[x])^2 - (1/4)*(c*Cos[x] - b*Sin[x])*(Sqrt[b^2 + c^2] + b*Cos[x] + c*Sin[x])^3}
{(Sqrt[b^2 + c^2] + b*Cos[x] + c*Sin[x])^3, x, 5, (5/2)*(b^2 + c^2)^(3/2)*x - (5/2)*c*(b^2 + c^2)*Cos[x] + (5/2)*b*(b^2 + c^2)*Sin[x] - (5/6)*Sqrt[b^2 + c^2]*(c*Cos[x] - b*Sin[x])*(Sqrt[b^2 + c^2] + b*Cos[x] + c*Sin[x]) - (1/3)*(c*Cos[x] - b*Sin[x])*(Sqrt[b^2 + c^2] + b*Cos[x] + c*Sin[x])^2}
{(Sqrt[b^2 + c^2] + b*Cos[x] + c*Sin[x])^2, x, 4, (3/2)*(b^2 + c^2)*x - (3/2)*c*Sqrt[b^2 + c^2]*Cos[x] + (3/2)*b*Sqrt[b^2 + c^2]*Sin[x] - (1/2)*(c*Cos[x] - b*Sin[x])*(Sqrt[b^2 + c^2] + b*Cos[x] + c*Sin[x])}
{(Sqrt[b^2 + c^2] + b*Cos[x] + c*Sin[x]), x, 3, Sqrt[b^2 + c^2]*x - c*Cos[x] + b*Sin[x]}
{1/(Sqrt[b^2 + c^2] + b*Cos[x] + c*Sin[x]), x, 1, -((c - Sqrt[b^2 + c^2]*Sin[x])/(c*(c*Cos[x] - b*Sin[x])))}
{1/(Sqrt[b^2 + c^2] + b*Cos[x] + c*Sin[x])^2, x, 2, -((c*Cos[x] - b*Sin[x])/(3*Sqrt[b^2 + c^2]*(Sqrt[b^2 + c^2] + b*Cos[x] + c*Sin[x])^2)) - (c - Sqrt[b^2 + c^2]*Sin[x])/(3*c*Sqrt[b^2 + c^2]*(c*Cos[x] - b*Sin[x]))}
{1/(Sqrt[b^2 + c^2] + b*Cos[x] + c*Sin[x])^3, x, 3, -((c*Cos[x] - b*Sin[x])/(5*Sqrt[b^2 + c^2]*(Sqrt[b^2 + c^2] + b*Cos[x] + c*Sin[x])^3)) - (2*(c*Cos[x] - b*Sin[x]))/(15*(b^2 + c^2)*(Sqrt[b^2 + c^2] + b*Cos[x] + c*Sin[x])^2) - (2*(c - Sqrt[b^2 + c^2]*Sin[x]))/(15*c*(b^2 + c^2)*(c*Cos[x] - b*Sin[x]))}
{1/(Sqrt[b^2 + c^2] + b*Cos[x] + c*Sin[x])^4, x, 4, -((c*Cos[x] - b*Sin[x])/(7*Sqrt[b^2 + c^2]*(Sqrt[b^2 + c^2] + b*Cos[x] + c*Sin[x])^4)) - (3*(c*Cos[x] - b*Sin[x]))/(35*(b^2 + c^2)*(Sqrt[b^2 + c^2] + b*Cos[x] + c*Sin[x])^3) - (2*(c*Cos[x] - b*Sin[x]))/(35*(b^2 + c^2)^(3/2)*(Sqrt[b^2 + c^2] + b*Cos[x] + c*Sin[x])^2) - (2*(c - Sqrt[b^2 + c^2]*Sin[x]))/(35*c*(b^2 + c^2)^(3/2)*(c*Cos[x] - b*Sin[x]))}


(* Integrands of the form (a+b*Cos[x]+c*Sin[x])^n where n is a half-integer *)
{(2 + 3*Cos[x] + 5*Sin[x])^(5/2), x, 7, (796/15)*Sqrt[2 + Sqrt[34]]*EllipticE[(1/2)*(x - ArcTan[5/3]), 34/15 - (2*Sqrt[34])/15] + (64*EllipticF[(1/2)*(x - ArcTan[5/3]), 34/15 - (2*Sqrt[34])/15])/Sqrt[2 + Sqrt[34]] - (32/15)*(5*Cos[x] - 3*Sin[x])*Sqrt[2 + 3*Cos[x] + 5*Sin[x]] - (2/5)*(5*Cos[x] - 3*Sin[x])*(2 + 3*Cos[x] + 5*Sin[x])^(3/2)}
{(2 + 3*Cos[x] + 5*Sin[x])^(3/2), x, 6, (16/3)*Sqrt[2 + Sqrt[34]]*EllipticE[(1/2)*(x - ArcTan[5/3]), 34/15 - (2*Sqrt[34])/15] + (20*EllipticF[(1/2)*(x - ArcTan[5/3]), 34/15 - (2*Sqrt[34])/15])/Sqrt[2 + Sqrt[34]] - (2/3)*(5*Cos[x] - 3*Sin[x])*Sqrt[2 + 3*Cos[x] + 5*Sin[x]]}
{(2 + 3*Cos[x] + 5*Sin[x])^(1/2), x, 2, 2*Sqrt[2 + Sqrt[34]]*EllipticE[(1/2)*(x - ArcTan[5/3]), 34/15 - (2*Sqrt[34])/15]}
{1/(2 + 3*Cos[x] + 5*Sin[x])^(1/2), x, 2, (2*EllipticF[(1/2)*(x - ArcTan[5/3]), 34/15 - (2*Sqrt[34])/15])/Sqrt[2 + Sqrt[34]]}
{1/(2 + 3*Cos[x] + 5*Sin[x])^(3/2), x, 3, (-(1/15))*Sqrt[2 + Sqrt[34]]*EllipticE[(1/2)*(x - ArcTan[5/3]), 34/15 - (2*Sqrt[34])/15] - (5*Cos[x] - 3*Sin[x])/(15*Sqrt[2 + 3*Cos[x] + 5*Sin[x]])}
{1/(2 + 3*Cos[x] + 5*Sin[x])^(5/2), x, 7, (4/675)*Sqrt[2 + Sqrt[34]]*EllipticE[(1/2)*(x - ArcTan[5/3]), 34/15 - (2*Sqrt[34])/15] + EllipticF[(1/2)*(x - ArcTan[5/3]), 34/15 - (2*Sqrt[34])/15]/(45*Sqrt[2 + Sqrt[34]]) - (5*Cos[x] - 3*Sin[x])/(45*(2 + 3*Cos[x] + 5*Sin[x])^(3/2)) + (4*(5*Cos[x] - 3*Sin[x]))/(675*Sqrt[2 + 3*Cos[x] + 5*Sin[x]])}
{1/(2 + 3*Cos[x] + 5*Sin[x])^(7/2), x, 8, -((199*Sqrt[2 + Sqrt[34]]*EllipticE[(1/2)*(x - ArcTan[5/3]), 34/15 - (2*Sqrt[34])/15])/101250) - (8*EllipticF[(1/2)*(x - ArcTan[5/3]), 34/15 - (2*Sqrt[34])/15])/(3375*Sqrt[2 + Sqrt[34]]) - (5*Cos[x] - 3*Sin[x])/(75*(2 + 3*Cos[x] + 5*Sin[x])^(5/2)) + (8*(5*Cos[x] - 3*Sin[x]))/(3375*(2 + 3*Cos[x] + 5*Sin[x])^(3/2)) - (199*(5*Cos[x] - 3*Sin[x]))/(101250*Sqrt[2 + 3*Cos[x] + 5*Sin[x]])}

{(a + b*Cos[x] + c*Sin[x])^(5/2), x, 7, (-(16/15))*a*(c*Cos[x] - b*Sin[x])*Sqrt[a + b*Cos[x] + c*Sin[x]] - (2/5)*(c*Cos[x] - b*Sin[x])*(a + b*Cos[x] + c*Sin[x])^(3/2) + (2*(23*a^2 + 9*(b^2 + c^2))*EllipticE[(1/2)*(x - ArcTan[b, c]), (2*Sqrt[b^2 + c^2])/(a + Sqrt[b^2 + c^2])]*Sqrt[a + b*Cos[x] + c*Sin[x]])/(15*Sqrt[(a + b*Cos[x] + c*Sin[x])/(a + Sqrt[b^2 + c^2])]) - (16*a*(a^2 - b^2 - c^2)*EllipticF[(1/2)*(x - ArcTan[b, c]), (2*Sqrt[b^2 + c^2])/(a + Sqrt[b^2 + c^2])]*Sqrt[(a + b*Cos[x] + c*Sin[x])/(a + Sqrt[b^2 + c^2])])/(15*Sqrt[a + b*Cos[x] + c*Sin[x]])}
{(a + b*Cos[x] + c*Sin[x])^(3/2), x, 6, (-(2/3))*(c*Cos[x] - b*Sin[x])*Sqrt[a + b*Cos[x] + c*Sin[x]] + (8*a*EllipticE[(1/2)*(x - ArcTan[b, c]), (2*Sqrt[b^2 + c^2])/(a + Sqrt[b^2 + c^2])]*Sqrt[a + b*Cos[x] + c*Sin[x]])/(3*Sqrt[(a + b*Cos[x] + c*Sin[x])/(a + Sqrt[b^2 + c^2])]) - (2*(a^2 - b^2 - c^2)*EllipticF[(1/2)*(x - ArcTan[b, c]), (2*Sqrt[b^2 + c^2])/(a + Sqrt[b^2 + c^2])]*Sqrt[(a + b*Cos[x] + c*Sin[x])/(a + Sqrt[b^2 + c^2])])/(3*Sqrt[a + b*Cos[x] + c*Sin[x]])}
{(a + b*Cos[x] + c*Sin[x])^(1/2), x, 2, (2*EllipticE[(1/2)*(x - ArcTan[b, c]), (2*Sqrt[b^2 + c^2])/(a + Sqrt[b^2 + c^2])]*Sqrt[a + b*Cos[x] + c*Sin[x]])/Sqrt[(a + b*Cos[x] + c*Sin[x])/(a + Sqrt[b^2 + c^2])]}
{1/(a + b*Cos[x] + c*Sin[x])^(1/2), x, 2, (2*EllipticF[(1/2)*(x - ArcTan[b, c]), (2*Sqrt[b^2 + c^2])/(a + Sqrt[b^2 + c^2])]*Sqrt[(a + b*Cos[x] + c*Sin[x])/(a + Sqrt[b^2 + c^2])])/Sqrt[a + b*Cos[x] + c*Sin[x]]}
{1/(a + b*Cos[x] + c*Sin[x])^(3/2), x, 3, (2*(c*Cos[x] - b*Sin[x]))/((a^2 - b^2 - c^2)*Sqrt[a + b*Cos[x] + c*Sin[x]]) + (2*EllipticE[(1/2)*(x - ArcTan[b, c]), (2*Sqrt[b^2 + c^2])/(a + Sqrt[b^2 + c^2])]*Sqrt[a + b*Cos[x] + c*Sin[x]])/((a^2 - b^2 - c^2)*Sqrt[(a + b*Cos[x] + c*Sin[x])/(a + Sqrt[b^2 + c^2])])}
{1/(a + b*Cos[x] + c*Sin[x])^(5/2), x, 7, (2*(c*Cos[x] - b*Sin[x]))/(3*(a^2 - b^2 - c^2)*(a + b*Cos[x] + c*Sin[x])^(3/2)) + (8*a*(c*Cos[x] - b*Sin[x]))/(3*(a^2 - b^2 - c^2)^2*Sqrt[a + b*Cos[x] + c*Sin[x]]) + (8*a*EllipticE[(1/2)*(x - ArcTan[b, c]), (2*Sqrt[b^2 + c^2])/(a + Sqrt[b^2 + c^2])]*Sqrt[a + b*Cos[x] + c*Sin[x]])/(3*(a^2 - b^2 - c^2)^2*Sqrt[(a + b*Cos[x] + c*Sin[x])/(a + Sqrt[b^2 + c^2])]) - (2*EllipticF[(1/2)*(x - ArcTan[b, c]), (2*Sqrt[b^2 + c^2])/(a + Sqrt[b^2 + c^2])]*Sqrt[(a + b*Cos[x] + c*Sin[x])/(a + Sqrt[b^2 + c^2])])/(3*(a^2 - b^2 - c^2)*Sqrt[a + b*Cos[x] + c*Sin[x]])}
{1/(a + b*Cos[x] + c*Sin[x])^(7/2), x, 8, (2*(c*Cos[x] - b*Sin[x]))/(5*(a^2 - b^2 - c^2)*(a + b*Cos[x] + c*Sin[x])^(5/2)) + (16*a*(c*Cos[x] - b*Sin[x]))/(15*(a^2 - b^2 - c^2)^2*(a + b*Cos[x] + c*Sin[x])^(3/2)) + (2*(23*a^2 + 9*(b^2 + c^2))*(c*Cos[x] - b*Sin[x]))/(15*(a^2 - b^2 - c^2)^3*Sqrt[a + b*Cos[x] + c*Sin[x]]) + (2*(23*a^2 + 9*(b^2 + c^2))*EllipticE[(1/2)*(x - ArcTan[b, c]), (2*Sqrt[b^2 + c^2])/(a + Sqrt[b^2 + c^2])]*Sqrt[a + b*Cos[x] + c*Sin[x]])/(15*(a^2 - b^2 - c^2)^3*Sqrt[(a + b*Cos[x] + c*Sin[x])/(a + Sqrt[b^2 + c^2])]) - (16*a*EllipticF[(1/2)*(x - ArcTan[b, c]), (2*Sqrt[b^2 + c^2])/(a + Sqrt[b^2 + c^2])]*Sqrt[(a + b*Cos[x] + c*Sin[x])/(a + Sqrt[b^2 + c^2])])/(15*(a^2 - b^2 - c^2)^2*Sqrt[a + b*Cos[x] + c*Sin[x]])}


(* Integrands of the form (a+b*Cos[x]+c*Sin[x])^n where n is a half-integer and a^2=b^2+c^2 *)
{(5 + 4*Cos[x] + 3*Sin[x])^(5/2), x, 3, -((320*(3*Cos[x] - 4*Sin[x]))/(3*Sqrt[5 + 4*Cos[x] + 3*Sin[x]])) - (16/3)*(3*Cos[x] - 4*Sin[x])*Sqrt[5 + 4*Cos[x] + 3*Sin[x]] - (2/5)*(3*Cos[x] - 4*Sin[x])*(5 + 4*Cos[x] + 3*Sin[x])^(3/2)}
{(5 + 4*Cos[x] + 3*Sin[x])^(3/2), x, 2, -((40*(3*Cos[x] - 4*Sin[x]))/(3*Sqrt[5 + 4*Cos[x] + 3*Sin[x]])) - (2/3)*(3*Cos[x] - 4*Sin[x])*Sqrt[5 + 4*Cos[x] + 3*Sin[x]]}
{(5 + 4*Cos[x] + 3*Sin[x])^(1/2), x, 1, -((2*(3*Cos[x] - 4*Sin[x]))/Sqrt[5 + 4*Cos[x] + 3*Sin[x]])}
{1/(5 + 4*Cos[x] + 3*Sin[x])^(1/2), x, 2, (2*ArcTanh[Sin[(1/2)*(x - ArcTan[3/4])]]*Cos[(1/2)*(x - ArcTan[3/4])])/(Sqrt[5]*Sqrt[1 + Cos[x - ArcTan[3/4]]])}
{1/(5 + 4*Cos[x] + 3*Sin[x])^(3/2), x, 3, (ArcTanh[Sin[(1/2)*(x - ArcTan[3/4])]]*Cos[(1/2)*(x - ArcTan[3/4])])/(10*Sqrt[5]*Sqrt[1 + Cos[x - ArcTan[3/4]]]) - (3*Cos[x] - 4*Sin[x])/(10*(5 + 4*Cos[x] + 3*Sin[x])^(3/2))}
{1/(5 + 4*Cos[x] + 3*Sin[x])^(5/2), x, 4, (3*ArcTanh[Sin[(1/2)*(x - ArcTan[3/4])]]*Cos[(1/2)*(x - ArcTan[3/4])])/(400*Sqrt[5]*Sqrt[1 + Cos[x - ArcTan[3/4]]]) - (3*Cos[x] - 4*Sin[x])/(20*(5 + 4*Cos[x] + 3*Sin[x])^(5/2)) - (3*(3*Cos[x] - 4*Sin[x]))/(400*(5 + 4*Cos[x] + 3*Sin[x])^(3/2))}

{(-5 + 4*Cos[x] + 3*Sin[x])^(5/2), x, 3, -((320*(3*Cos[x] - 4*Sin[x]))/(3*Sqrt[-5 + 4*Cos[x] + 3*Sin[x]])) + (16/3)*(3*Cos[x] - 4*Sin[x])*Sqrt[-5 + 4*Cos[x] + 3*Sin[x]] - (2/5)*(3*Cos[x] - 4*Sin[x])*(-5 + 4*Cos[x] + 3*Sin[x])^(3/2)}
{(-5 + 4*Cos[x] + 3*Sin[x])^(3/2), x, 2, (40*(3*Cos[x] - 4*Sin[x]))/(3*Sqrt[-5 + 4*Cos[x] + 3*Sin[x]]) - (2/3)*(3*Cos[x] - 4*Sin[x])*Sqrt[-5 + 4*Cos[x] + 3*Sin[x]]}
{(-5 + 4*Cos[x] + 3*Sin[x])^(1/2), x, 1, -((2*(3*Cos[x] - 4*Sin[x]))/Sqrt[-5 + 4*Cos[x] + 3*Sin[x]])}
{1/(-5 + 4*Cos[x] + 3*Sin[x])^(1/2), x, 3, (Sqrt[2/5]*ArcTanh[(3 + Tan[x/2])/(Sqrt[10]*Sqrt[Sec[x/2]^2])]*(1 - 3*Tan[x/2]))/(Sqrt[Sec[x/2]^2]*Sqrt[(-Cos[x/2]^2)*(1 - 3*Tan[x/2])^2])}
{1/(-5 + 4*Cos[x] + 3*Sin[x])^(3/2), x, 4, (3*Cos[x] - 4*Sin[x])/(10*(-5 + 4*Cos[x] + 3*Sin[x])^(3/2)) - (ArcTanh[(3 + Tan[x/2])/(Sqrt[10]*Sqrt[Sec[x/2]^2])]*(1 - 3*Tan[x/2]))/(10*Sqrt[10]*Sqrt[Sec[x/2]^2]*Sqrt[(-Cos[x/2]^2)*(1 - 3*Tan[x/2])^2])}
{1/(-5 + 4*Cos[x] + 3*Sin[x])^(5/2), x, 5, (3*Cos[x] - 4*Sin[x])/(20*(-5 + 4*Cos[x] + 3*Sin[x])^(5/2)) - (3*(3*Cos[x] - 4*Sin[x]))/(400*(-5 + 4*Cos[x] + 3*Sin[x])^(3/2)) + (3*ArcTanh[(3 + Tan[x/2])/(Sqrt[10]*Sqrt[Sec[x/2]^2])]*(1 - 3*Tan[x/2]))/(400*Sqrt[10]*Sqrt[Sec[x/2]^2]*Sqrt[(-Cos[x/2]^2)*(1 - 3*Tan[x/2])^2])}

{(Sqrt[b^2 + c^2] + b*Cos[x] + c*Sin[x])^(5/2), x, 3, -((64*(b^2 + c^2)*(c*Cos[x] - b*Sin[x]))/(15*Sqrt[Sqrt[b^2 + c^2] + b*Cos[x] + c*Sin[x]])) - (16/15)*Sqrt[b^2 + c^2]*(c*Cos[x] - b*Sin[x])*Sqrt[Sqrt[b^2 + c^2] + b*Cos[x] + c*Sin[x]] - (2/5)*(c*Cos[x] - b*Sin[x])*(Sqrt[b^2 + c^2] + b*Cos[x] + c*Sin[x])^(3/2)}
{(Sqrt[b^2 + c^2] + b*Cos[x] + c*Sin[x])^(3/2), x, 2, -((8*Sqrt[b^2 + c^2]*(c*Cos[x] - b*Sin[x]))/(3*Sqrt[Sqrt[b^2 + c^2] + b*Cos[x] + c*Sin[x]])) - (2/3)*(c*Cos[x] - b*Sin[x])*Sqrt[Sqrt[b^2 + c^2] + b*Cos[x] + c*Sin[x]]}
{(Sqrt[b^2 + c^2] + b*Cos[x] + c*Sin[x])^(1/2), x, 1, -((2*(c*Cos[x] - b*Sin[x]))/Sqrt[Sqrt[b^2 + c^2] + b*Cos[x] + c*Sin[x]])}
{1/(Sqrt[b^2 + c^2] + b*Cos[x] + c*Sin[x])^(1/2), x, 2, (2*ArcTanh[Sin[(1/2)*(x - ArcTan[b, c])]]*Cos[(1/2)*(x - ArcTan[b, c])]*Sqrt[(Sqrt[b^2 + c^2] + b*Cos[x] + c*Sin[x])/Sqrt[b^2 + c^2]])/(Sqrt[1 + Cos[x - ArcTan[b, c]]]*Sqrt[Sqrt[b^2 + c^2] + b*Cos[x] + c*Sin[x]])}
{1/(Sqrt[b^2 + c^2] + b*Cos[x] + c*Sin[x])^(3/2), x, 3, -((c*Cos[x] - b*Sin[x])/(2*Sqrt[b^2 + c^2]*(Sqrt[b^2 + c^2] + b*Cos[x] + c*Sin[x])^(3/2))) + (ArcTanh[Sin[(1/2)*(x - ArcTan[b, c])]]*Cos[(1/2)*(x - ArcTan[b, c])]*Sqrt[(Sqrt[b^2 + c^2] + b*Cos[x] + c*Sin[x])/Sqrt[b^2 + c^2]])/(2*Sqrt[b^2 + c^2]*Sqrt[1 + Cos[x - ArcTan[b, c]]]*Sqrt[Sqrt[b^2 + c^2] + b*Cos[x] + c*Sin[x]])}
{1/(Sqrt[b^2 + c^2] + b*Cos[x] + c*Sin[x])^(5/2), x, 4, -((c*Cos[x] - b*Sin[x])/(4*Sqrt[b^2 + c^2]*(Sqrt[b^2 + c^2] + b*Cos[x] + c*Sin[x])^(5/2))) - (3*(c*Cos[x] - b*Sin[x]))/(16*(b^2 + c^2)*(Sqrt[b^2 + c^2] + b*Cos[x] + c*Sin[x])^(3/2)) + (3*ArcTanh[Sin[(1/2)*(x - ArcTan[b, c])]]*Cos[(1/2)*(x - ArcTan[b, c])]*Sqrt[(Sqrt[b^2 + c^2] + b*Cos[x] + c*Sin[x])/Sqrt[b^2 + c^2]])/(16*(b^2 + c^2)*Sqrt[1 + Cos[x - ArcTan[b, c]]]*Sqrt[Sqrt[b^2 + c^2] + b*Cos[x] + c*Sin[x]])}

{(-Sqrt[b^2 + c^2] + b*Cos[x] + c*Sin[x])^(5/2), x, 3, -((64*(b^2 + c^2)*(c*Cos[x] - b*Sin[x]))/(15*Sqrt[-Sqrt[b^2 + c^2] + b*Cos[x] + c*Sin[x]])) + (16/15)*Sqrt[b^2 + c^2]*(c*Cos[x] - b*Sin[x])*Sqrt[-Sqrt[b^2 + c^2] + b*Cos[x] + c*Sin[x]] - (2/5)*(c*Cos[x] - b*Sin[x])*(-Sqrt[b^2 + c^2] + b*Cos[x] + c*Sin[x])^(3/2)}
{(-Sqrt[b^2 + c^2] + b*Cos[x] + c*Sin[x])^(3/2), x, 2, (8*Sqrt[b^2 + c^2]*(c*Cos[x] - b*Sin[x]))/(3*Sqrt[-Sqrt[b^2 + c^2] + b*Cos[x] + c*Sin[x]]) - (2/3)*(c*Cos[x] - b*Sin[x])*Sqrt[-Sqrt[b^2 + c^2] + b*Cos[x] + c*Sin[x]]}
{(-Sqrt[b^2 + c^2] + b*Cos[x] + c*Sin[x])^(1/2), x, 1, -((2*(c*Cos[x] - b*Sin[x]))/Sqrt[-Sqrt[b^2 + c^2] + b*Cos[x] + c*Sin[x]])}
(* {1/(-Sqrt[b^2 + c^2] + b*Cos[x] + c*Sin[x])^(1/2), x, 0, 0}
{1/(-Sqrt[b^2 + c^2] + b*Cos[x] + c*Sin[x])^(3/2), x, 0, 0}
{1/(-Sqrt[b^2 + c^2] + b*Cos[x] + c*Sin[x])^(5/2), x, 0, 0} *)


(* ::Subsubsection::Closed:: *)
(*Integrands of the form (a + b Tan[d+e x] + c Sec[d+e x])^n*)


{1/(a + b*Tan[x] + c*Sec[x]), x, -9, (a*x)/(a^2 + b^2) + (2*a*c*ArcTanh[(b + (-a + c)*Tan[x/2])/Sqrt[a^2 + b^2 - c^2]])/((a^2 + b^2)*Sqrt[a^2 + b^2 - c^2]) + (b*Log[c + a*Cos[x] + b*Sin[x]])/(a^2 + b^2)}
{1/(a + b*Cot[x] + c*Csc[x]), x, -9, (a*x)/(a^2 + b^2) + (2*a*c*ArcTanh[(a + (-b + c)*Tan[x/2])/Sqrt[a^2 + b^2 - c^2]])/((a^2 + b^2)*Sqrt[a^2 + b^2 - c^2]) - (b*Log[c + b*Cos[x] + a*Sin[x]])/(a^2 + b^2)}


(* ::Subsection::Closed:: *)
(*Integrands of the form x^m (a + b Trig[x]^n + c Trig[x]^n)^p*)


{1/(a + b*Cos[x]^2 + c*Sin[x]^2), x, 3, -(ArcTan[(Sqrt[a + b]*Cot[x])/Sqrt[a + c]]/(Sqrt[a + b]*Sqrt[a + c]))}
{x/(a + b*Cos[x]^2 + c*Sin[x]^2), x, 9, -((I*x*Log[1 + ((b - c)*E^(2*I*x))/(2*a + b + c - 2*Sqrt[a + b]*Sqrt[a + c])])/(2*Sqrt[a + b]*Sqrt[a + c])) + (I*x*Log[1 + ((b - c)*E^(2*I*x))/(2*a + b + c + 2*Sqrt[a + b]*Sqrt[a + c])])/(2*Sqrt[a + b]*Sqrt[a + c]) - PolyLog[2, -(((b - c)*E^(2*I*x))/(2*a + b + c - 2*Sqrt[a + b]*Sqrt[a + c]))]/(4*Sqrt[a + b]*Sqrt[a + c]) + PolyLog[2, -(((b - c)*E^(2*I*x))/(2*a + b + c + 2*Sqrt[a + b]*Sqrt[a + c]))]/(4*Sqrt[a + b]*Sqrt[a + c])}
{x^2/(a + b*Cos[x]^2 + c*Sin[x]^2), x, 11, -((I*x^2*Log[1 + ((b - c)*E^(2*I*x))/(2*a + b + c - 2*Sqrt[a + b]*Sqrt[a + c])])/(2*Sqrt[a + b]*Sqrt[a + c])) + (I*x^2*Log[1 + ((b - c)*E^(2*I*x))/(2*a + b + c + 2*Sqrt[a + b]*Sqrt[a + c])])/(2*Sqrt[a + b]*Sqrt[a + c]) - (x*PolyLog[2, -(((b - c)*E^(2*I*x))/(2*a + b + c - 2*Sqrt[a + b]*Sqrt[a + c]))])/(2*Sqrt[a + b]*Sqrt[a + c]) + (x*PolyLog[2, -(((b - c)*E^(2*I*x))/(2*a + b + c + 2*Sqrt[a + b]*Sqrt[a + c]))])/(2*Sqrt[a + b]*Sqrt[a + c]) - (I*PolyLog[3, -(((b - c)*E^(2*I*x))/(2*a + b + c - 2*Sqrt[a + b]*Sqrt[a + c]))])/(4*Sqrt[a + b]*Sqrt[a + c]) + (I*PolyLog[3, -(((b - c)*E^(2*I*x))/(2*a + b + c + 2*Sqrt[a + b]*Sqrt[a + c]))])/(4*Sqrt[a + b]*Sqrt[a + c])}
(* {x^3/(a + b*Cos[x]^2 + c*Sin[x]^2), x, 13, -((I*x^3*Log[1 + ((b - c)*E^(2*I*x))/(2*a + b + c - 2*Sqrt[a + b]*Sqrt[a + c])])/(2*Sqrt[a + b]*Sqrt[a + c])) + (I*x^3*Log[1 + ((b - c)*E^(2*I*x))/(2*a + b + c + 2*Sqrt[a + b]*Sqrt[a + c])])/(2*Sqrt[a + b]*Sqrt[a + c]) - (3*x^2*PolyLog[2, -(((b - c)*E^(2*I*x))/(2*a + b + c - 2*Sqrt[a + b]*Sqrt[a + c]))])/(4*Sqrt[a + b]*Sqrt[a + c]) + (3*x^2*PolyLog[2, -(((b - c)*E^(2*I*x))/(2*a + b + c + 2*Sqrt[a + b]*Sqrt[a + c]))])/(4*Sqrt[a + b]*Sqrt[a + c]) - (3*I*x*PolyLog[3, -(((b - c)*E^(2*I*x))/(2*a + b + c - 2*Sqrt[a + b]*Sqrt[a + c]))])/(4*Sqrt[a + b]*Sqrt[a + c]) + (3*I*x*PolyLog[3, -(((b - c)*E^(2*I*x))/(2*a + b + c + 2*Sqrt[a + b]*Sqrt[a + c]))])/(4*Sqrt[a + b]*Sqrt[a + c]) + (3*PolyLog[4, -(((b - c)*E^(2*I*x))/(2*a + b + c - 2*Sqrt[a + b]*Sqrt[a + c]))])/(8*Sqrt[a + b]*Sqrt[a + c]) - (3*PolyLog[4, -(((b - c)*E^(2*I*x))/(2*a + b + c + 2*Sqrt[a + b]*Sqrt[a + c]))])/(8*Sqrt[a + b]*Sqrt[a + c])} *)


(* ::Subsection::Closed:: *)
(*Miscellaneous integrands involving two trig functions*)


{1/(a + b*Sin[x]*Cos[x]), x, 2, (2*ArcTan[(b + 2*a*Tan[x])/Sqrt[4*a^2 - b^2]])/Sqrt[4*a^2 - b^2]}
{x/(a + b*Sin[x]*Cos[x]), x, 9, -((I*x*Log[1 - (I*b*E^(2*I*x))/(2*a - Sqrt[4*a^2 - b^2])])/Sqrt[4*a^2 - b^2]) + (I*x*Log[1 - (I*b*E^(2*I*x))/(2*a + Sqrt[4*a^2 - b^2])])/Sqrt[4*a^2 - b^2] - PolyLog[2, (I*b*E^(2*I*x))/(2*a - Sqrt[4*a^2 - b^2])]/(2*Sqrt[4*a^2 - b^2]) + PolyLog[2, (I*b*E^(2*I*x))/(2*a + Sqrt[4*a^2 - b^2])]/(2*Sqrt[4*a^2 - b^2])}
{x^2/(a + b*Sin[x]*Cos[x]), x, 11, -((I*x^2*Log[1 - (I*b*E^(2*I*x))/(2*a - Sqrt[4*a^2 - b^2])])/Sqrt[4*a^2 - b^2]) + (I*x^2*Log[1 - (I*b*E^(2*I*x))/(2*a + Sqrt[4*a^2 - b^2])])/Sqrt[4*a^2 - b^2] - (x*PolyLog[2, (I*b*E^(2*I*x))/(2*a - Sqrt[4*a^2 - b^2])])/Sqrt[4*a^2 - b^2] + (x*PolyLog[2, (I*b*E^(2*I*x))/(2*a + Sqrt[4*a^2 - b^2])])/Sqrt[4*a^2 - b^2] - (I*PolyLog[3, (I*b*E^(2*I*x))/(2*a - Sqrt[4*a^2 - b^2])])/(2*Sqrt[4*a^2 - b^2]) + (I*PolyLog[3, (I*b*E^(2*I*x))/(2*a + Sqrt[4*a^2 - b^2])])/(2*Sqrt[4*a^2 - b^2])}
{x^3/(a + b*Sin[x]*Cos[x]), x, 13, -((I*x^3*Log[1 - (I*b*E^(2*I*x))/(2*a - Sqrt[4*a^2 - b^2])])/Sqrt[4*a^2 - b^2]) + (I*x^3*Log[1 - (I*b*E^(2*I*x))/(2*a + Sqrt[4*a^2 - b^2])])/Sqrt[4*a^2 - b^2] - (3*x^2*PolyLog[2, (I*b*E^(2*I*x))/(2*a - Sqrt[4*a^2 - b^2])])/(2*Sqrt[4*a^2 - b^2]) + (3*x^2*PolyLog[2, (I*b*E^(2*I*x))/(2*a + Sqrt[4*a^2 - b^2])])/(2*Sqrt[4*a^2 - b^2]) - (3*I*x*PolyLog[3, (I*b*E^(2*I*x))/(2*a - Sqrt[4*a^2 - b^2])])/(2*Sqrt[4*a^2 - b^2]) + (3*I*x*PolyLog[3, (I*b*E^(2*I*x))/(2*a + Sqrt[4*a^2 - b^2])])/(2*Sqrt[4*a^2 - b^2]) + (3*PolyLog[4, (I*b*E^(2*I*x))/(2*a - Sqrt[4*a^2 - b^2])])/(4*Sqrt[4*a^2 - b^2]) - (3*PolyLog[4, (I*b*E^(2*I*x))/(2*a + Sqrt[4*a^2 - b^2])])/(4*Sqrt[4*a^2 - b^2])}


{Sqrt[a + b*Sin[x]*Cos[x]], x, 3, -(((2*a + b)*EllipticE[Pi/4 - x, (2*b)/(2*a + b)]*Sqrt[(2*a + b*Sin[2*x])/(2*a + b)])/(Sqrt[2]*Sqrt[2*a + b*Sin[2*x]]))}
{1/Sqrt[a + b*Sin[x]*Cos[x]], x, 3, -((Sqrt[2]*EllipticF[Pi/4 - x, (2*b)/(2*a + b)]*Sqrt[(2*a + b*Sin[2*x])/(2*a + b)])/Sqrt[2*a + b*Sin[2*x]])}


{(Cot[Sqrt[x]]*Csc[Sqrt[x]])/Sqrt[x], x, 2, -2*Csc[Sqrt[x]]}
{(Cos[Sqrt[x]]*Sin[Sqrt[x]])/Sqrt[x], x, 3, Sin[Sqrt[x]]^2}
{(Sec[Sqrt[x]]*Tan[Sqrt[x]])/Sqrt[x], x, 2, 2*Sec[Sqrt[x]]}


{Tan[c+d*x]/Sqrt[a*Sin[c+d*x]^2], x, 2, (ArcTanh[Sin[c + d*x]]*Sin[c + d*x])/(d*Sqrt[a*Sin[c + d*x]^2])}
{Cot[c+d*x]/Sqrt[a*Cos[c+d*x]^2], x, 2, -((ArcTanh[Cos[c + d*x]]*Cos[c + d*x])/(d*Sqrt[a*Cos[c + d*x]^2]))}


{(x*Cos[x^2])/Sqrt[Sin[x^2]], x, 3, Sqrt[Sin[x^2]]}


{Cos[x]/Sqrt[1 - Cos[2*x]], x, 3, (Log[Sin[x]]*Sin[x])/(Sqrt[2]*Sqrt[Sin[x]^2])}


{Sqrt[(1 - Cos[x])/(a - Cos[x])], x, 4, (-Sqrt[2])*ArcTan[(Sqrt[2]*Cos[x/2])/Sqrt[1 + a - 2*Cos[x/2]^2]]*Sqrt[(1 - Cos[x])/(a - Cos[x])]*Sqrt[a - Cos[x]]*Csc[x/2]}


(* Integrands of the form Trig[x]^2/(a+b*Trig[2*x]) *)
{Sin[x]^2/(a + b*Sin[2*x]), x, 5, ArcTan[(b + a*Tan[x])/Sqrt[a^2 - b^2]]/(2*Sqrt[a^2 - b^2]) - Log[a + b*Sin[2*x]]/(4*b)}
{Cos[x]^2/(a + b*Sin[2*x]), x, 5, ArcTan[(b + a*Tan[x])/Sqrt[a^2 - b^2]]/(2*Sqrt[a^2 - b^2]) + Log[a + b*Sin[2*x]]/(4*b)}

{Sin[x]^2/(a + b*Cos[2*x]), x, 5, -(x/(2*b)) - (Sqrt[a + b]*ArcTan[(Sqrt[a + b]*Cot[x])/Sqrt[a - b]])/(2*Sqrt[a - b]*b)}
{Cos[x]^2/(a + b*Cos[2*x]), x, 4, x/(2*b) - (Sqrt[a - b]*ArcTan[(Sqrt[a - b]*Tan[x])/Sqrt[a + b]])/(2*b*Sqrt[a + b])}


(* Integrands involving trig functions of logarithms *)
{Cos[Log[x]]^2*Sin[Log[x]]^2/x, x, 3, Log[x]/8 + (1/8)*Cos[Log[x]]*Sin[Log[x]] - (1/4)*Cos[Log[x]]^3*Sin[Log[x]]}
