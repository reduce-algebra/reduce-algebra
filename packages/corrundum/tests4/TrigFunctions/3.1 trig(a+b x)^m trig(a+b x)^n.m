(* ::Package:: *)

(* ::Title:: *)
(*Problems for integrands of the form trig(a+b x)^m trig(a+b x)^n*)


(* ::Section:: *)
(*Integrands of the form Sin[a+b x]^m Cos[a+b x]^n*)


(* ::Subsection::Closed:: *)
(*Integrands of the form Sin[a+b x]^m Cos[a+b x]^n*)


(* ::Subsubsection::Closed:: *)
(*m>0*)


{Cos[a + b*x]^n*Sin[a + b*x], x, 1, -(Cos[a + b*x]^(1 + n)/(b*(1 + n)))}

{Cos[a + b*x]^3*Sin[a + b*x], x, 1, -(Cos[a + b*x]^4/(4*b))}
{Cos[a + b*x]^2*Sin[a + b*x], x, 1, -(Cos[a + b*x]^3/(3*b))}
{Cos[a + b*x]^1*Sin[a + b*x], x, 1, Sin[a + b*x]^2/(2*b)}
{Cos[a + b*x]^0*Sin[a + b*x], x, 1, -(Cos[a + b*x]/b)}
{Sec[a + b*x]^1*Sin[a + b*x], x, 1, -(Log[Cos[a + b*x]]/b)}
{Sec[a + b*x]^2*Sin[a + b*x], x, 1, Sec[a + b*x]/b}
{Sec[a + b*x]^3*Sin[a + b*x], x, 1, Sec[a + b*x]^2/(2*b)}
{Sec[a + b*x]^4*Sin[a + b*x], x, 1, Sec[a + b*x]^3/(3*b)}


{Cos[a + b*x]^n*Sin[a + b*x]^2, x, 2, -((Cos[a + b*x]^(1 + n)*Sin[a + b*x])/(b*(2 + n))) + (Cos[a + b*x]^(1 + n)*(Cos[a + b*x]^2)^((1/2)*(-1 - n))*Hypergeometric2F1[1/2, (1 - n)/2, 3/2, Sin[a + b*x]^2]*Sin[a + b*x])/(b*(2 + n))}

{Cos[a + b*x]^7*Sin[a + b*x]^2, x, 3, Sin[a + b*x]^3/(3*b) - (3*Sin[a + b*x]^5)/(5*b) + (3*Sin[a + b*x]^7)/(7*b) - Sin[a + b*x]^9/(9*b)}
{Cos[a + b*x]^6*Sin[a + b*x]^2, x, 4, (5*x)/128 + (5*Cos[a + b*x]*Sin[a + b*x])/(128*b) + (5*Cos[a + b*x]^3*Sin[a + b*x])/(192*b) + (Cos[a + b*x]^5*Sin[a + b*x])/(48*b) - (Cos[a + b*x]^7*Sin[a + b*x])/(8*b)}
{Cos[a + b*x]^5*Sin[a + b*x]^2, x, 3, Sin[a + b*x]^3/(3*b) - (2*Sin[a + b*x]^5)/(5*b) + Sin[a + b*x]^7/(7*b)}
{Cos[a + b*x]^4*Sin[a + b*x]^2, x, 3, x/16 + (Cos[a + b*x]*Sin[a + b*x])/(16*b) + (Cos[a + b*x]^3*Sin[a + b*x])/(24*b) - (Cos[a + b*x]^5*Sin[a + b*x])/(6*b)}
{Cos[a + b*x]^3*Sin[a + b*x]^2, x, 3, Sin[a + b*x]^3/(3*b) - Sin[a + b*x]^5/(5*b)}
{Cos[a + b*x]^2*Sin[a + b*x]^2, x, 2, x/8 + (Cos[a + b*x]*Sin[a + b*x])/(8*b) - (Cos[a + b*x]^3*Sin[a + b*x])/(4*b)}
{Cos[a + b*x]^1*Sin[a + b*x]^2, x, 1, Sin[a + b*x]^3/(3*b)}
{Cos[a + b*x]^0*Sin[a + b*x]^2, x, 1, x/2 - (Cos[a + b*x]*Sin[a + b*x])/(2*b)}
{Sec[a + b*x]^1*Sin[a + b*x]^2, x, 2, ArcTanh[Sin[a + b*x]]/b - Sin[a + b*x]/b}
{Sec[a + b*x]^2*Sin[a + b*x]^2, x, 2, -x + Tan[a + b*x]/b}
{Sec[a + b*x]^3*Sin[a + b*x]^2, x, 2, -(ArcTanh[Sin[a + b*x]]/(2*b)) + (Sec[a + b*x]*Tan[a + b*x])/(2*b)}
{Sec[a + b*x]^4*Sin[a + b*x]^2, x, 2, Tan[a + b*x]^3/(3*b)}
{Sec[a + b*x]^5*Sin[a + b*x]^2, x, 3, -(ArcTanh[Sin[a + b*x]]/(8*b)) + (Sec[a + b*x]*Tan[a + b*x])/(8*b) + (Sec[a + b*x]*Tan[a + b*x]^3)/(4*b)}
{Sec[a + b*x]^6*Sin[a + b*x]^2, x, 3, Tan[a + b*x]^3/(3*b) + Tan[a + b*x]^5/(5*b)}
{Sec[a + b*x]^7*Sin[a + b*x]^2, x, 4, -(ArcTanh[Sin[a + b*x]]/(16*b)) + (Sec[a + b*x]*Tan[a + b*x])/(16*b) + (Sec[a + b*x]*Tan[a + b*x]^3)/(8*b) + (Sec[a + b*x]^3*Tan[a + b*x]^3)/(6*b)}


{Cos[a + b*x]^n*Sin[a + b*x]^3, x, 3, -(Cos[a + b*x]^(1 + n)/(b*(1 + n))) + Cos[a + b*x]^(3 + n)/(b*(3 + n))}

{Cos[a + b*x]^5*Sin[a + b*x]^3, x, 3, -(Cos[a + b*x]^6/(6*b)) + Cos[a + b*x]^8/(8*b)}
{Cos[a + b*x]^4*Sin[a + b*x]^3, x, 3, -(Cos[a + b*x]^5/(5*b)) + Cos[a + b*x]^7/(7*b)}
{Cos[a + b*x]^3*Sin[a + b*x]^3, x, 3, Sin[a + b*x]^4/(4*b) - Sin[a + b*x]^6/(6*b)}
{Cos[a + b*x]^2*Sin[a + b*x]^3, x, 3, -(Cos[a + b*x]^3/(3*b)) + Cos[a + b*x]^5/(5*b)}
{Cos[a + b*x]^1*Sin[a + b*x]^3, x, 1, Sin[a + b*x]^4/(4*b)}
{Cos[a + b*x]^0*Sin[a + b*x]^3, x, 2, -(Cos[a + b*x]/b) + Cos[a + b*x]^3/(3*b)}
{Sec[a + b*x]^1*Sin[a + b*x]^3, x, 3, Cos[a + b*x]^2/(2*b) - Log[Cos[a + b*x]]/b}
{Sec[a + b*x]^2*Sin[a + b*x]^3, x, 3, Cos[a + b*x]/b + Sec[a + b*x]/b}
{Sec[a + b*x]^3*Sin[a + b*x]^3, x, 2, Log[Cos[a + b*x]]/b + Tan[a + b*x]^2/(2*b)}
{Sec[a + b*x]^4*Sin[a + b*x]^3, x, 2, -(Sec[a + b*x]/b) + Sec[a + b*x]^3/(3*b)}
{Sec[a + b*x]^5*Sin[a + b*x]^3, x, 2, Tan[a + b*x]^4/(4*b)}
{Sec[a + b*x]^6*Sin[a + b*x]^3, x, 3, -(Sec[a + b*x]^3/(3*b)) + Sec[a + b*x]^5/(5*b)}
{Sec[a + b*x]^7*Sin[a + b*x]^3, x, 3, Tan[a + b*x]^4/(4*b) + Tan[a + b*x]^6/(6*b)}
{Sec[a + b*x]^8*Sin[a + b*x]^3, x, 3, -(Sec[a + b*x]^5/(5*b)) + Sec[a + b*x]^7/(7*b)}
{Sec[a + b*x]^9*Sin[a + b*x]^3, x, 3, -(Sec[a + b*x]^6/(6*b)) + Sec[a + b*x]^8/(8*b)}


{Cos[a + b*x]^n*Sin[a + b*x]^4, x, 3, -((3*Cos[a + b*x]^(1 + n)*Sin[a + b*x])/(b*(8 + 6*n + n^2))) + (3*Cos[a + b*x]^(1 + n)*(Cos[a + b*x]^2)^((1/2)*(-1 - n))*Hypergeometric2F1[1/2, (1 - n)/2, 3/2, Sin[a + b*x]^2]*Sin[a + b*x])/(b*(8 + 6*n + n^2)) - (Cos[a + b*x]^(1 + n)*Sin[a + b*x]^3)/(b*(4 + n))}

{Cos[a + b*x]^7*Sin[a + b*x]^4, x, 3, Sin[a + b*x]^5/(5*b) - (3*Sin[a + b*x]^7)/(7*b) + Sin[a + b*x]^9/(3*b) - Sin[a + b*x]^11/(11*b)}
{Cos[a + b*x]^6*Sin[a + b*x]^4, x, 5, (3*x)/256 + (3*Cos[a + b*x]*Sin[a + b*x])/(256*b) + (Cos[a + b*x]^3*Sin[a + b*x])/(128*b) + (Cos[a + b*x]^5*Sin[a + b*x])/(160*b) - (3*Cos[a + b*x]^7*Sin[a + b*x])/(80*b) - (Cos[a + b*x]^7*Sin[a + b*x]^3)/(10*b)}
{Cos[a + b*x]^5*Sin[a + b*x]^4, x, 3, Sin[a + b*x]^5/(5*b) - (2*Sin[a + b*x]^7)/(7*b) + Sin[a + b*x]^9/(9*b)}
{Cos[a + b*x]^4*Sin[a + b*x]^4, x, 4, (3*x)/128 + (3*Cos[a + b*x]*Sin[a + b*x])/(128*b) + (Cos[a + b*x]^3*Sin[a + b*x])/(64*b) - (Cos[a + b*x]^5*Sin[a + b*x])/(16*b) - (Cos[a + b*x]^5*Sin[a + b*x]^3)/(8*b)}
{Cos[a + b*x]^3*Sin[a + b*x]^4, x, 3, Sin[a + b*x]^5/(5*b) - Sin[a + b*x]^7/(7*b)}
{Cos[a + b*x]^2*Sin[a + b*x]^4, x, 3, x/16 + (Cos[a + b*x]*Sin[a + b*x])/(16*b) - (Cos[a + b*x]^3*Sin[a + b*x])/(8*b) - (Cos[a + b*x]^3*Sin[a + b*x]^3)/(6*b)}
{Cos[a + b*x]^1*Sin[a + b*x]^4, x, 1, Sin[a + b*x]^5/(5*b)}
{Cos[a + b*x]^0*Sin[a + b*x]^4, x, 2, (3*x)/8 - (3*Cos[a + b*x]*Sin[a + b*x])/(8*b) - (Cos[a + b*x]*Sin[a + b*x]^3)/(4*b)}
{Sec[a + b*x]^1*Sin[a + b*x]^4, x, 3, ArcTanh[Sin[a + b*x]]/b - Sin[a + b*x]/b - Sin[a + b*x]^3/(3*b)}
{Sec[a + b*x]^2*Sin[a + b*x]^4, x, 3, -((3*x)/2) + (3*Tan[a + b*x])/(2*b) - (Sin[a + b*x]^2*Tan[a + b*x])/(2*b)}
{Sec[a + b*x]^3*Sin[a + b*x]^4, x, 3, -((3*ArcTanh[Sin[a + b*x]])/(2*b)) + (3*Sin[a + b*x])/(2*b) + (Sin[a + b*x]*Tan[a + b*x]^2)/(2*b)}
{Sec[a + b*x]^4*Sin[a + b*x]^4, x, 3, x - Tan[a + b*x]/b + Tan[a + b*x]^3/(3*b)}
{Sec[a + b*x]^5*Sin[a + b*x]^4, x, 3, (3*ArcTanh[Sin[a + b*x]])/(8*b) - (3*Sec[a + b*x]*Tan[a + b*x])/(8*b) + (Sec[a + b*x]*Tan[a + b*x]^3)/(4*b)}
{Sec[a + b*x]^6*Sin[a + b*x]^4, x, 2, Tan[a + b*x]^5/(5*b)}
{Sec[a + b*x]^7*Sin[a + b*x]^4, x, 4, ArcTanh[Sin[a + b*x]]/(16*b) - (Sec[a + b*x]*Tan[a + b*x])/(16*b) + (Sec[a + b*x]*Tan[a + b*x]^3)/(24*b) + (Sec[a + b*x]*Tan[a + b*x]^5)/(6*b)}
{Sec[a + b*x]^8*Sin[a + b*x]^4, x, 3, Tan[a + b*x]^5/(5*b) + Tan[a + b*x]^7/(7*b)}


{Cos[a + b*x]^n*Sin[a + b*x]^5, x, 3, -(Cos[a + b*x]^(1 + n)/(b*(1 + n))) + (2*Cos[a + b*x]^(3 + n))/(b*(3 + n)) - Cos[a + b*x]^(5 + n)/(b*(5 + n))}

{Cos[a + b*x]^7*Sin[a + b*x]^5, x, 4, -(Cos[a + b*x]^8/(8*b)) + Cos[a + b*x]^10/(5*b) - Cos[a + b*x]^12/(12*b)}
{Cos[a + b*x]^6*Sin[a + b*x]^5, x, 3, -(Cos[a + b*x]^7/(7*b)) + (2*Cos[a + b*x]^9)/(9*b) - Cos[a + b*x]^11/(11*b)}
{Cos[a + b*x]^5*Sin[a + b*x]^5, x, 4, Sin[a + b*x]^6/(6*b) - Sin[a + b*x]^8/(4*b) + Sin[a + b*x]^10/(10*b)}
{Cos[a + b*x]^4*Sin[a + b*x]^5, x, 3, -(Cos[a + b*x]^5/(5*b)) + (2*Cos[a + b*x]^7)/(7*b) - Cos[a + b*x]^9/(9*b)}
{Cos[a + b*x]^3*Sin[a + b*x]^5, x, 3, Sin[a + b*x]^6/(6*b) - Sin[a + b*x]^8/(8*b)}
{Cos[a + b*x]^2*Sin[a + b*x]^5, x, 3, -(Cos[a + b*x]^3/(3*b)) + (2*Cos[a + b*x]^5)/(5*b) - Cos[a + b*x]^7/(7*b)}
{Cos[a + b*x]^1*Sin[a + b*x]^5, x, 1, Sin[a + b*x]^6/(6*b)}
{Cos[a + b*x]^0*Sin[a + b*x]^5, x, 2, -(Cos[a + b*x]/b) + (2*Cos[a + b*x]^3)/(3*b) - Cos[a + b*x]^5/(5*b)}
{Sec[a + b*x]^1*Sin[a + b*x]^5, x, 3, Cos[a + b*x]^2/b - Cos[a + b*x]^4/(4*b) - Log[Cos[a + b*x]]/b}
{Sec[a + b*x]^2*Sin[a + b*x]^5, x, 3, (2*Cos[a + b*x])/b - Cos[a + b*x]^3/(3*b) + Sec[a + b*x]/b}
{Sec[a + b*x]^3*Sin[a + b*x]^5, x, 3, -(Cos[a + b*x]^2/(2*b)) + (2*Log[Cos[a + b*x]])/b + Sec[a + b*x]^2/(2*b)}
{Sec[a + b*x]^4*Sin[a + b*x]^5, x, 3, -(Cos[a + b*x]/b) - (2*Sec[a + b*x])/b + Sec[a + b*x]^3/(3*b)}
{Sec[a + b*x]^5*Sin[a + b*x]^5, x, 3, -(Log[Cos[a + b*x]]/b) - Tan[a + b*x]^2/(2*b) + Tan[a + b*x]^4/(4*b)}
{Sec[a + b*x]^6*Sin[a + b*x]^5, x, 3, Sec[a + b*x]/b - (2*Sec[a + b*x]^3)/(3*b) + Sec[a + b*x]^5/(5*b)}
{Sec[a + b*x]^7*Sin[a + b*x]^5, x, 2, Tan[a + b*x]^6/(6*b)}
{Sec[a + b*x]^8*Sin[a + b*x]^5, x, 3, Sec[a + b*x]^3/(3*b) - (2*Sec[a + b*x]^5)/(5*b) + Sec[a + b*x]^7/(7*b)}
{Sec[a + b*x]^9*Sin[a + b*x]^5, x, 3, Tan[a + b*x]^6/(6*b) + Tan[a + b*x]^8/(8*b)}
{Sec[a + b*x]^10*Sin[a + b*x]^5, x, 3, Sec[a + b*x]^5/(5*b) - (2*Sec[a + b*x]^7)/(7*b) + Sec[a + b*x]^9/(9*b)}
{Sec[a + b*x]^11*Sin[a + b*x]^5, x, 4, Tan[a + b*x]^6/(6*b) + Tan[a + b*x]^8/(4*b) + Tan[a + b*x]^10/(10*b)}
{Sec[a + b*x]^12*Sin[a + b*x]^5, x, 3, Sec[a + b*x]^7/(7*b) - (2*Sec[a + b*x]^9)/(9*b) + Sec[a + b*x]^11/(11*b)}
{Sec[a + b*x]^13*Sin[a + b*x]^5, x, 4, Sec[a + b*x]^8/(8*b) - Sec[a + b*x]^10/(5*b) + Sec[a + b*x]^12/(12*b)}


(* ::Subsubsection::Closed:: *)
(*m<0*)


{Cos[a + b*x]^n/Sin[a + b*x], x, 2, -((Cos[a + b*x]^(1 + n)*Hypergeometric2F1[1, (1 + n)/2, (3 + n)/2, Cos[a + b*x]^2])/(b*(1 + n)))}

{Cos[a + b*x]^6/Sin[a + b*x], x, 4, -(ArcTanh[Cos[a + b*x]]/b) + Cos[a + b*x]/b + Cos[a + b*x]^3/(3*b) + Cos[a + b*x]^5/(5*b)}
{Cos[a + b*x]^5/Sin[a + b*x], x, 3, Log[Sin[a + b*x]]/b - Sin[a + b*x]^2/b + Sin[a + b*x]^4/(4*b)}
{Cos[a + b*x]^4/Sin[a + b*x], x, 3, -(ArcTanh[Cos[a + b*x]]/b) + Cos[a + b*x]/b + Cos[a + b*x]^3/(3*b)}
{Cos[a + b*x]^3/Sin[a + b*x], x, 3, Log[Sin[a + b*x]]/b - Sin[a + b*x]^2/(2*b)}
{Cos[a + b*x]^2/Sin[a + b*x], x, 2, -(ArcTanh[Cos[a + b*x]]/b) + Cos[a + b*x]/b}
{Cos[a + b*x]^1/Sin[a + b*x], x, 1, Log[Sin[a + b*x]]/b}
{Cos[a + b*x]^0/Sin[a + b*x], x, 1, -(ArcTanh[Cos[a + b*x]]/b)}
{Sec[a + b*x]^1/Sin[a + b*x], x, 2, Log[Tan[a + b*x]]/b}
{Sec[a + b*x]^2/Sin[a + b*x], x, 2, -(ArcTanh[Cos[a + b*x]]/b) + Sec[a + b*x]/b}
{Sec[a + b*x]^3/Sin[a + b*x], x, 3, Log[Tan[a + b*x]]/b + Tan[a + b*x]^2/(2*b)}
{Sec[a + b*x]^4/Sin[a + b*x], x, 3, -(ArcTanh[Cos[a + b*x]]/b) + Sec[a + b*x]/b + Sec[a + b*x]^3/(3*b)}
{Sec[a + b*x]^5/Sin[a + b*x], x, 3, Log[Tan[a + b*x]]/b + Tan[a + b*x]^2/b + Tan[a + b*x]^4/(4*b)}


{Cos[a + b*x]^n/Sin[a + b*x]^2, x, 2, -((Cos[a + b*x]^(1 + n)*Csc[a + b*x])/b) - (n*Cos[a + b*x]^(1 + n)*(Cos[a + b*x]^2)^((1/2)*(-1 - n))*Hypergeometric2F1[1/2, (1 - n)/2, 3/2, Sin[a + b*x]^2]*Sin[a + b*x])/b}

{Cos[a + b*x]^7/Sin[a + b*x]^2, x, 3, -(Csc[a + b*x]/b) - (3*Sin[a + b*x])/b + Sin[a + b*x]^3/b - Sin[a + b*x]^5/(5*b)}
{Cos[a + b*x]^6/Sin[a + b*x]^2, x, 4, -((15*x)/8) - (15*Cot[a + b*x])/(8*b) + (5*Cos[a + b*x]^2*Cot[a + b*x])/(8*b) + (Cos[a + b*x]^4*Cot[a + b*x])/(4*b)}
{Cos[a + b*x]^5/Sin[a + b*x]^2, x, 3, -(Csc[a + b*x]/b) - (2*Sin[a + b*x])/b + Sin[a + b*x]^3/(3*b)}
{Cos[a + b*x]^4/Sin[a + b*x]^2, x, 3, -((3*x)/2) - (3*Cot[a + b*x])/(2*b) + (Cos[a + b*x]^2*Cot[a + b*x])/(2*b)}
{Cos[a + b*x]^3/Sin[a + b*x]^2, x, 3, -(Csc[a + b*x]/b) - Sin[a + b*x]/b}
{Cos[a + b*x]^2/Sin[a + b*x]^2, x, 2, -x - Cot[a + b*x]/b}
{Cos[a + b*x]^1/Sin[a + b*x]^2, x, 1, -(Csc[a + b*x]/b)}
{Cos[a + b*x]^0/Sin[a + b*x]^2, x, 1, -(Cot[a + b*x]/b)}
{Sec[a + b*x]^1/Sin[a + b*x]^2, x, 2, ArcTanh[Sin[a + b*x]]/b - Csc[a + b*x]/b}
{Sec[a + b*x]^2/Sin[a + b*x]^2, x, 3, -(Cot[a + b*x]/b) + Tan[a + b*x]/b}
{Sec[a + b*x]^3/Sin[a + b*x]^2, x, 3, (3*ArcTanh[Sin[a + b*x]])/(2*b) - (3*Csc[a + b*x])/(2*b) + (Csc[a + b*x]*Sec[a + b*x]^2)/(2*b)}
{Sec[a + b*x]^4/Sin[a + b*x]^2, x, 3, -(Cot[a + b*x]/b) + (2*Tan[a + b*x])/b + Tan[a + b*x]^3/(3*b)}
{Sec[a + b*x]^5/Sin[a + b*x]^2, x, 4, (15*ArcTanh[Sin[a + b*x]])/(8*b) - (15*Csc[a + b*x])/(8*b) + (5*Csc[a + b*x]*Sec[a + b*x]^2)/(8*b) + (Csc[a + b*x]*Sec[a + b*x]^4)/(4*b)}


{Cos[a + b*x]^n/Sin[a + b*x]^3, x, 3, -(Cos[a + b*x]^(1 + n)/(2*b*(1 - Cos[a + b*x]^2))) - ((1 - n)*Cos[a + b*x]^(1 + n)*Hypergeometric2F1[1, (1 + n)/2, (3 + n)/2, Cos[a + b*x]^2])/(2*b*(1 + n))}

{Cos[a + b*x]^7/Sin[a + b*x]^3, x, 3, -(Csc[a + b*x]^2/(2*b)) - (3*Log[Sin[a + b*x]])/b + (3*Sin[a + b*x]^2)/(2*b) - Sin[a + b*x]^4/(4*b)}
{Cos[a + b*x]^6/Sin[a + b*x]^3, x, 4, (5*ArcTanh[Cos[a + b*x]])/(2*b) - (5*Cos[a + b*x])/(2*b) - (5*Cos[a + b*x]*Cot[a + b*x]^2)/(6*b) + (Cos[a + b*x]^3*Cot[a + b*x]^2)/(3*b)}
{Cos[a + b*x]^5/Sin[a + b*x]^3, x, 3, -(Csc[a + b*x]^2/(2*b)) - (2*Log[Sin[a + b*x]])/b + Sin[a + b*x]^2/(2*b)}
{Cos[a + b*x]^4/Sin[a + b*x]^3, x, 3, (3*ArcTanh[Cos[a + b*x]])/(2*b) - (3*Cos[a + b*x])/(2*b) - (Cos[a + b*x]*Cot[a + b*x]^2)/(2*b)}
{Cos[a + b*x]^3/Sin[a + b*x]^3, x, 2, -(Cot[a + b*x]^2/(2*b)) - Log[Sin[a + b*x]]/b}
{Cos[a + b*x]^2/Sin[a + b*x]^3, x, 2, ArcTanh[Cos[a + b*x]]/(2*b) - (Cot[a + b*x]*Csc[a + b*x])/(2*b)}
{Cos[a + b*x]^1/Sin[a + b*x]^3, x, 1, -(Csc[a + b*x]^2/(2*b))}
{Cos[a + b*x]^0/Sin[a + b*x]^3, x, 2, -(ArcTanh[Cos[a + b*x]]/(2*b)) - (Cot[a + b*x]*Csc[a + b*x])/(2*b)}
{Sec[a + b*x]^1/Sin[a + b*x]^3, x, 3, -(Cot[a + b*x]^2/(2*b)) + Log[Tan[a + b*x]]/b}
{Sec[a + b*x]^2/Sin[a + b*x]^3, x, 3, -((3*ArcTanh[Cos[a + b*x]])/(2*b)) + (3*Sec[a + b*x])/(2*b) - (Csc[a + b*x]^2*Sec[a + b*x])/(2*b)}
{Sec[a + b*x]^3/Sin[a + b*x]^3, x, 3, -(Cot[a + b*x]^2/(2*b)) + (2*Log[Tan[a + b*x]])/b + Tan[a + b*x]^2/(2*b)}
{Sec[a + b*x]^4/Sin[a + b*x]^3, x, 4, -((5*ArcTanh[Cos[a + b*x]])/(2*b)) + (5*Sec[a + b*x])/(2*b) + (5*Sec[a + b*x]^3)/(6*b) - (Csc[a + b*x]^2*Sec[a + b*x]^3)/(2*b)}
{Sec[a + b*x]^5/Sin[a + b*x]^3, x, 3, -(Cot[a + b*x]^2/(2*b)) + (3*Log[Tan[a + b*x]])/b + (3*Tan[a + b*x]^2)/(2*b) + Tan[a + b*x]^4/(4*b)}


{Cos[a + b*x]^n/Sin[a + b*x]^4, x, 3, -(((2 - n)*Cos[a + b*x]^(1 + n)*Csc[a + b*x])/(3*b)) - (Cos[a + b*x]^(1 + n)*Csc[a + b*x]^3)/(3*b) - ((2 - n)*n*Cos[a + b*x]^(1 + n)*(Cos[a + b*x]^2)^((1/2)*(-1 - n))*Hypergeometric2F1[1/2, (1 - n)/2, 3/2, Sin[a + b*x]^2]*Sin[a + b*x])/(3*b)}

{Cos[a + b*x]^9/Sin[a + b*x]^4, x, 3, (4*Csc[a + b*x])/b - Csc[a + b*x]^3/(3*b) + (6*Sin[a + b*x])/b - (4*Sin[a + b*x]^3)/(3*b) + Sin[a + b*x]^5/(5*b)}
{Cos[a + b*x]^8/Sin[a + b*x]^4, x, 5, (35*x)/8 + (35*Cot[a + b*x])/(8*b) - (35*Cot[a + b*x]^3)/(24*b) + (7*Cos[a + b*x]^2*Cot[a + b*x]^3)/(8*b) + (Cos[a + b*x]^4*Cot[a + b*x]^3)/(4*b)}
{Cos[a + b*x]^7/Sin[a + b*x]^4, x, 3, (3*Csc[a + b*x])/b - Csc[a + b*x]^3/(3*b) + (3*Sin[a + b*x])/b - Sin[a + b*x]^3/(3*b)}
{Cos[a + b*x]^6/Sin[a + b*x]^4, x, 4, (5*x)/2 + (5*Cot[a + b*x])/(2*b) - (5*Cot[a + b*x]^3)/(6*b) + (Cos[a + b*x]^2*Cot[a + b*x]^3)/(2*b)}
{Cos[a + b*x]^5/Sin[a + b*x]^4, x, 3, (2*Csc[a + b*x])/b - Csc[a + b*x]^3/(3*b) + Sin[a + b*x]/b}
{Cos[a + b*x]^4/Sin[a + b*x]^4, x, 3, x + Cot[a + b*x]/b - Cot[a + b*x]^3/(3*b)}
{Cos[a + b*x]^3/Sin[a + b*x]^4, x, 2, Csc[a + b*x]/b - Csc[a + b*x]^3/(3*b)}
{Cos[a + b*x]^2/Sin[a + b*x]^4, x, 2, -(Cot[a + b*x]^3/(3*b))}
{Cos[a + b*x]^1/Sin[a + b*x]^4, x, 1, -(Csc[a + b*x]^3/(3*b))}
{Cos[a + b*x]^0/Sin[a + b*x]^4, x, 2, -(Cot[a + b*x]/b) - Cot[a + b*x]^3/(3*b)}
{Sec[a + b*x]^1/Sin[a + b*x]^4, x, 3, ArcTanh[Sin[a + b*x]]/b - Csc[a + b*x]/b - Csc[a + b*x]^3/(3*b)}
{Sec[a + b*x]^2/Sin[a + b*x]^4, x, 3, -((2*Cot[a + b*x])/b) - Cot[a + b*x]^3/(3*b) + Tan[a + b*x]/b}
{Sec[a + b*x]^3/Sin[a + b*x]^4, x, 4, (5*ArcTanh[Sin[a + b*x]])/(2*b) - (5*Csc[a + b*x])/(2*b) - (5*Csc[a + b*x]^3)/(6*b) + (Csc[a + b*x]^3*Sec[a + b*x]^2)/(2*b)}
{Sec[a + b*x]^4/Sin[a + b*x]^4, x, 3, -((3*Cot[a + b*x])/b) - Cot[a + b*x]^3/(3*b) + (3*Tan[a + b*x])/b + Tan[a + b*x]^3/(3*b)}
{Sec[a + b*x]^5/Sin[a + b*x]^4, x, 5, (35*ArcTanh[Sin[a + b*x]])/(8*b) - (35*Csc[a + b*x])/(8*b) - (35*Csc[a + b*x]^3)/(24*b) + (7*Csc[a + b*x]^3*Sec[a + b*x]^2)/(8*b) + (Csc[a + b*x]^3*Sec[a + b*x]^4)/(4*b)}


{Cos[a + b*x]^n/Sin[a + b*x]^5, x, 4, -(Cos[a + b*x]^(1 + n)/(4*b*(1 - Cos[a + b*x]^2)^2)) - ((3 - n)*Cos[a + b*x]^(1 + n))/(8*b*(1 - Cos[a + b*x]^2)) - ((1 - n)*(3 - n)*Cos[a + b*x]^(1 + n)*Hypergeometric2F1[1, (1 + n)/2, (3 + n)/2, Cos[a + b*x]^2])/(8*b*(1 + n))}

{Cos[a + b*x]^9/Sin[a + b*x]^5, x, 3, (2*Csc[a + b*x]^2)/b - Csc[a + b*x]^4/(4*b) + (6*Log[Sin[a + b*x]])/b - (2*Sin[a + b*x]^2)/b + Sin[a + b*x]^4/(4*b)}
{Cos[a + b*x]^8/Sin[a + b*x]^5, x, 5, -((35*ArcTanh[Cos[a + b*x]])/(8*b)) + (35*Cos[a + b*x])/(8*b) + (35*Cos[a + b*x]*Cot[a + b*x]^2)/(24*b) - (7*Cos[a + b*x]*Cot[a + b*x]^4)/(12*b) + (Cos[a + b*x]^3*Cot[a + b*x]^4)/(3*b)}
{Cos[a + b*x]^7/Sin[a + b*x]^5, x, 3, (3*Csc[a + b*x]^2)/(2*b) - Csc[a + b*x]^4/(4*b) + (3*Log[Sin[a + b*x]])/b - Sin[a + b*x]^2/(2*b)}
{Cos[a + b*x]^6/Sin[a + b*x]^5, x, 4, -((15*ArcTanh[Cos[a + b*x]])/(8*b)) + (15*Cos[a + b*x])/(8*b) + (5*Cos[a + b*x]*Cot[a + b*x]^2)/(8*b) - (Cos[a + b*x]*Cot[a + b*x]^4)/(4*b)}
{Cos[a + b*x]^5/Sin[a + b*x]^5, x, 3, Cot[a + b*x]^2/(2*b) - Cot[a + b*x]^4/(4*b) + Log[Sin[a + b*x]]/b}
{Cos[a + b*x]^4/Sin[a + b*x]^5, x, 3, -((3*ArcTanh[Cos[a + b*x]])/(8*b)) + (3*Cot[a + b*x]*Csc[a + b*x])/(8*b) - (Cot[a + b*x]^3*Csc[a + b*x])/(4*b)}
{Cos[a + b*x]^3/Sin[a + b*x]^5, x, 2, -(Cot[a + b*x]^4/(4*b))}
{Cos[a + b*x]^2/Sin[a + b*x]^5, x, 3, ArcTanh[Cos[a + b*x]]/(8*b) - (Cot[a + b*x]*Csc[a + b*x])/(8*b) - (Cot[a + b*x]^3*Csc[a + b*x])/(4*b)}
{Cos[a + b*x]^1/Sin[a + b*x]^5, x, 1, -(Csc[a + b*x]^4/(4*b))}
{Cos[a + b*x]^0/Sin[a + b*x]^5, x, 3, -((3*ArcTanh[Cos[a + b*x]])/(8*b)) - (3*Cot[a + b*x]*Csc[a + b*x])/(8*b) - (Cot[a + b*x]*Csc[a + b*x]^3)/(4*b)}
{Sec[a + b*x]^1/Sin[a + b*x]^5, x, 3, -(Cot[a + b*x]^2/b) - Cot[a + b*x]^4/(4*b) + Log[Tan[a + b*x]]/b}
{Sec[a + b*x]^2/Sin[a + b*x]^5, x, 4, -((15*ArcTanh[Cos[a + b*x]])/(8*b)) + (15*Sec[a + b*x])/(8*b) - (5*Csc[a + b*x]^2*Sec[a + b*x])/(8*b) - (Csc[a + b*x]^4*Sec[a + b*x])/(4*b)}
{Sec[a + b*x]^3/Sin[a + b*x]^5, x, 3, -((3*Cot[a + b*x]^2)/(2*b)) - Cot[a + b*x]^4/(4*b) + (3*Log[Tan[a + b*x]])/b + Tan[a + b*x]^2/(2*b)}
{Sec[a + b*x]^4/Sin[a + b*x]^5, x, 5, -((35*ArcTanh[Cos[a + b*x]])/(8*b)) + (35*Sec[a + b*x])/(8*b) + (35*Sec[a + b*x]^3)/(24*b) - (7*Csc[a + b*x]^2*Sec[a + b*x]^3)/(8*b) - (Csc[a + b*x]^4*Sec[a + b*x]^3)/(4*b)}
{Sec[a + b*x]^5/Sin[a + b*x]^5, x, 3, -((2*Cot[a + b*x]^2)/b) - Cot[a + b*x]^4/(4*b) + (6*Log[Tan[a + b*x]])/b + (2*Tan[a + b*x]^2)/b + Tan[a + b*x]^4/(4*b)}


(* ::Subsubsection::Closed:: *)
(*m symbolic*)


{Cos[a + b*x]^n*Sin[a + b*x]^m, x, 1, -((Cos[a + b*x]^(1 + n)*Hypergeometric2F1[(1 - m)/2, (1 + n)/2, (3 + n)/2, Cos[a + b*x]^2]*Sin[a + b*x]^(1 + m)*(Sin[a + b*x]^2)^((1/2)*(-1 - m)))/(b*(1 + n)))}

{Cos[a + b*x]^5*Sin[a + b*x]^m, x, 3, Sin[a + b*x]^(1 + m)/(b*(1 + m)) - (2*Sin[a + b*x]^(3 + m))/(b*(3 + m)) + Sin[a + b*x]^(5 + m)/(b*(5 + m))}
{Cos[a + b*x]^4*Sin[a + b*x]^m, x, 3, (3*Cos[a + b*x]*Sin[a + b*x]^(1 + m))/(b*(8 + 6*m + m^2)) + (Cos[a + b*x]^3*Sin[a + b*x]^(1 + m))/(b*(4 + m)) - (3*Cos[a + b*x]*Hypergeometric2F1[1/2, (1 - m)/2, 3/2, Cos[a + b*x]^2]*Sin[a + b*x]^(1 + m)*(Sin[a + b*x]^2)^((1/2)*(-1 - m)))/(b*(8 + 6*m + m^2))}
{Cos[a + b*x]^3*Sin[a + b*x]^m, x, 3, Sin[a + b*x]^(1 + m)/(b*(1 + m)) - Sin[a + b*x]^(3 + m)/(b*(3 + m))}
{Cos[a + b*x]^2*Sin[a + b*x]^m, x, 2, (Cos[a + b*x]*Sin[a + b*x]^(1 + m))/(b*(2 + m)) - (Cos[a + b*x]*Hypergeometric2F1[1/2, (1 - m)/2, 3/2, Cos[a + b*x]^2]*Sin[a + b*x]^(1 + m)*(Sin[a + b*x]^2)^((1/2)*(-1 - m)))/(b*(2 + m))}
{Cos[a + b*x]^1*Sin[a + b*x]^m, x, 1, Sin[a + b*x]^(1 + m)/(b*(1 + m))}
{Cos[a + b*x]^0*Sin[a + b*x]^m, x, 1, -((Cos[a + b*x]*Hypergeometric2F1[1/2, (1 - m)/2, 3/2, Cos[a + b*x]^2]*Sin[a + b*x]^(1 + m)*(Sin[a + b*x]^2)^((1/2)*(-1 - m)))/b)}
{Sec[a + b*x]^1*Sin[a + b*x]^m, x, 2, (Hypergeometric2F1[1, (1 + m)/2, (3 + m)/2, Sin[a + b*x]^2]*Sin[a + b*x]^(1 + m))/(b*(1 + m))}
{Sec[a + b*x]^2*Sin[a + b*x]^m, x, 2, (Sec[a + b*x]*Sin[a + b*x]^(1 + m))/b + (m*Cos[a + b*x]*Hypergeometric2F1[1/2, (1 - m)/2, 3/2, Cos[a + b*x]^2]*Sin[a + b*x]^(1 + m)*(Sin[a + b*x]^2)^((1/2)*(-1 - m)))/b}
{Sec[a + b*x]^3*Sin[a + b*x]^m, x, 3, ((1 - m)*Hypergeometric2F1[1, (1 + m)/2, (3 + m)/2, Sin[a + b*x]^2]*Sin[a + b*x]^(1 + m))/(2*b*(1 + m)) + Sin[a + b*x]^(1 + m)/(2*b*(1 - Sin[a + b*x]^2))}
{Sec[a + b*x]^4*Sin[a + b*x]^m, x, 3, ((2 - m)*Sec[a + b*x]*Sin[a + b*x]^(1 + m))/(3*b) + (Sec[a + b*x]^3*Sin[a + b*x]^(1 + m))/(3*b) + ((2 - m)*m*Cos[a + b*x]*Hypergeometric2F1[1/2, (1 - m)/2, 3/2, Cos[a + b*x]^2]*Sin[a + b*x]^(1 + m)*(Sin[a + b*x]^2)^((1/2)*(-1 - m)))/(3*b)}


(* ::Subsection::Closed:: *)
(*Integrands of the form Sin[a+b x]^(m/2) Cos[a+b x]^n*)


{Sec[a + b*x]^4*Sqrt[Tan[a + b*x]], x, 3, (2*Tan[a + b*x]^(3/2))/(3*b) + (2*Tan[a + b*x]^(7/2))/(7*b)}


(* ::Subsection::Closed:: *)
(*Integrands of the form Sin[a+b x]^m Cos[a+b x]^(n/2)*)


{Sec[x]^(3/2)*Sin[x], x, 1, 2*Sqrt[Sec[x]]}
{Sec[x]^(5/2)*Sin[x], x, 1, (2*Sec[x]^(3/2))/3}
{Sqrt[Cos[3*x]]*Sin[3*x], x, 1, (-2*Cos[3*x]^(3/2))/9}
{Cos[x]^(1/5)*Sin[x], x, 1, (-5*Cos[x]^(6/5))/6}


{Sqrt[Cos[x]]*Sin[x]^3, x, 3, (-(2/3))*Cos[x]^(3/2) + (2/7)*Cos[x]^(7/2)}
{Sin[x]^3/Sqrt[Cos[x]], x, 3, -2*Sqrt[Cos[x]] + (2/5)*Cos[x]^(5/2)}
{Sec[x]^(5/2)*Sin[x]^3, x, 4, 2/Sqrt[Sec[x]] + (2/3)*Sec[x]^(3/2)}
{Sec[x]^(9/2)*Sin[x]^3, x, 4, (-(2/3))*Sec[x]^(3/2) + (2/7)*Sec[x]^(7/2)}


{Cos[2*x]^(3/2)*Sin[2*x]^5, x, 3, (-(1/5))*Cos[2*x]^(5/2) + (2/9)*Cos[2*x]^(9/2) - (1/13)*Cos[2*x]^(13/2)}


(* ::Subsection::Closed:: *)
(*Integrands of the form Sin[a+b x]^(m/2) Cos[a+b x]^(n/2)*)
(**)


{Sin[a + b*x]^(7/2)/Cos[a + b*x]^(7/2), x, 10, ArcTan[1 - (Sqrt[2]*Sqrt[Cos[a + b*x]])/Sqrt[Sin[a + b*x]]]/(Sqrt[2]*b) - ArcTan[1 + (Sqrt[2]*Sqrt[Cos[a + b*x]])/Sqrt[Sin[a + b*x]]]/(Sqrt[2]*b) - Log[1 + Cot[a + b*x] - (Sqrt[2]*Sqrt[Cos[a + b*x]])/Sqrt[Sin[a + b*x]]]/(2*Sqrt[2]*b) + Log[1 + Cot[a + b*x] + (Sqrt[2]*Sqrt[Cos[a + b*x]])/Sqrt[Sin[a + b*x]]]/(2*Sqrt[2]*b) - (2*Sqrt[Sin[a + b*x]])/(b*Sqrt[Cos[a + b*x]]) + (2*Sin[a + b*x]^(5/2))/(5*b*Cos[a + b*x]^(5/2))}
{Sin[a + b*x]^(5/2)/Cos[a + b*x]^(5/2), x, 9, ArcTan[1 - (Sqrt[2]*Sqrt[Sin[a + b*x]])/Sqrt[Cos[a + b*x]]]/(Sqrt[2]*b) - ArcTan[1 + (Sqrt[2]*Sqrt[Sin[a + b*x]])/Sqrt[Cos[a + b*x]]]/(Sqrt[2]*b) - Log[1 - (Sqrt[2]*Sqrt[Sin[a + b*x]])/Sqrt[Cos[a + b*x]] + Tan[a + b*x]]/(2*Sqrt[2]*b) + Log[1 + (Sqrt[2]*Sqrt[Sin[a + b*x]])/Sqrt[Cos[a + b*x]] + Tan[a + b*x]]/(2*Sqrt[2]*b) + (2*Sin[a + b*x]^(3/2))/(3*b*Cos[a + b*x]^(3/2))}
{Sin[a + b*x]^(3/2)/Cos[a + b*x]^(3/2), x, 9, -(ArcTan[1 - (Sqrt[2]*Sqrt[Cos[a + b*x]])/Sqrt[Sin[a + b*x]]]/(Sqrt[2]*b)) + ArcTan[1 + (Sqrt[2]*Sqrt[Cos[a + b*x]])/Sqrt[Sin[a + b*x]]]/(Sqrt[2]*b) + Log[1 + Cot[a + b*x] - (Sqrt[2]*Sqrt[Cos[a + b*x]])/Sqrt[Sin[a + b*x]]]/(2*Sqrt[2]*b) - Log[1 + Cot[a + b*x] + (Sqrt[2]*Sqrt[Cos[a + b*x]])/Sqrt[Sin[a + b*x]]]/(2*Sqrt[2]*b) + (2*Sqrt[Sin[a + b*x]])/(b*Sqrt[Cos[a + b*x]])}
{Sin[a + b*x]^(1/2)/Cos[a + b*x]^(1/2), x, 8, -(ArcTan[1 - (Sqrt[2]*Sqrt[Sin[a + b*x]])/Sqrt[Cos[a + b*x]]]/(Sqrt[2]*b)) + ArcTan[1 + (Sqrt[2]*Sqrt[Sin[a + b*x]])/Sqrt[Cos[a + b*x]]]/(Sqrt[2]*b) + Log[1 - (Sqrt[2]*Sqrt[Sin[a + b*x]])/Sqrt[Cos[a + b*x]] + Tan[a + b*x]]/(2*Sqrt[2]*b) - Log[1 + (Sqrt[2]*Sqrt[Sin[a + b*x]])/Sqrt[Cos[a + b*x]] + Tan[a + b*x]]/(2*Sqrt[2]*b)}
{Cos[a + b*x]^(1/2)/Sin[a + b*x]^(1/2), x, 8, ArcTan[1 - (Sqrt[2]*Sqrt[Cos[a + b*x]])/Sqrt[Sin[a + b*x]]]/(Sqrt[2]*b) - ArcTan[1 + (Sqrt[2]*Sqrt[Cos[a + b*x]])/Sqrt[Sin[a + b*x]]]/(Sqrt[2]*b) - Log[1 + Cot[a + b*x] - (Sqrt[2]*Sqrt[Cos[a + b*x]])/Sqrt[Sin[a + b*x]]]/(2*Sqrt[2]*b) + Log[1 + Cot[a + b*x] + (Sqrt[2]*Sqrt[Cos[a + b*x]])/Sqrt[Sin[a + b*x]]]/(2*Sqrt[2]*b)}
{Cos[a + b*x]^(3/2)/Sin[a + b*x]^(3/2), x, 9, ArcTan[1 - (Sqrt[2]*Sqrt[Sin[a + b*x]])/Sqrt[Cos[a + b*x]]]/(Sqrt[2]*b) - ArcTan[1 + (Sqrt[2]*Sqrt[Sin[a + b*x]])/Sqrt[Cos[a + b*x]]]/(Sqrt[2]*b) - Log[1 - (Sqrt[2]*Sqrt[Sin[a + b*x]])/Sqrt[Cos[a + b*x]] + Tan[a + b*x]]/(2*Sqrt[2]*b) + Log[1 + (Sqrt[2]*Sqrt[Sin[a + b*x]])/Sqrt[Cos[a + b*x]] + Tan[a + b*x]]/(2*Sqrt[2]*b) - (2*Sqrt[Cos[a + b*x]])/(b*Sqrt[Sin[a + b*x]])}
{Cos[a + b*x]^(5/2)/Sin[a + b*x]^(5/2), x, 9, -(ArcTan[1 - (Sqrt[2]*Sqrt[Cos[a + b*x]])/Sqrt[Sin[a + b*x]]]/(Sqrt[2]*b)) + ArcTan[1 + (Sqrt[2]*Sqrt[Cos[a + b*x]])/Sqrt[Sin[a + b*x]]]/(Sqrt[2]*b) + Log[1 + Cot[a + b*x] - (Sqrt[2]*Sqrt[Cos[a + b*x]])/Sqrt[Sin[a + b*x]]]/(2*Sqrt[2]*b) - Log[1 + Cot[a + b*x] + (Sqrt[2]*Sqrt[Cos[a + b*x]])/Sqrt[Sin[a + b*x]]]/(2*Sqrt[2]*b) - (2*Cos[a + b*x]^(3/2))/(3*b*Sin[a + b*x]^(3/2))}
{Cos[a + b*x]^(7/2)/Sin[a + b*x]^(7/2), x, 10, -(ArcTan[1 - (Sqrt[2]*Sqrt[Sin[a + b*x]])/Sqrt[Cos[a + b*x]]]/(Sqrt[2]*b)) + ArcTan[1 + (Sqrt[2]*Sqrt[Sin[a + b*x]])/Sqrt[Cos[a + b*x]]]/(Sqrt[2]*b) + Log[1 - (Sqrt[2]*Sqrt[Sin[a + b*x]])/Sqrt[Cos[a + b*x]] + Tan[a + b*x]]/(2*Sqrt[2]*b) - Log[1 + (Sqrt[2]*Sqrt[Sin[a + b*x]])/Sqrt[Cos[a + b*x]] + Tan[a + b*x]]/(2*Sqrt[2]*b) - (2*Cos[a + b*x]^(5/2))/(5*b*Sin[a + b*x]^(5/2)) + (2*Sqrt[Cos[a + b*x]])/(b*Sqrt[Sin[a + b*x]])}


{Sin[a + b*x]^(7/3)/Cos[a + b*x]^(7/3), x, 8, (Sqrt[3]*ArcTan[(1 - (2*Sin[a + b*x]^(2/3))/Cos[a + b*x]^(2/3))/Sqrt[3]])/(2*b) + Log[1 + Sin[a + b*x]^(2/3)/Cos[a + b*x]^(2/3)]/(2*b) - Log[1 - Sin[a + b*x]^(2/3)/Cos[a + b*x]^(2/3) + Sin[a + b*x]^(4/3)/Cos[a + b*x]^(4/3)]/(4*b) + (3*Sin[a + b*x]^(4/3))/(4*b*Cos[a + b*x]^(4/3))}
{Sin[a + b*x]^(5/3)/Cos[a + b*x]^(5/3), x, 8, -((Sqrt[3]*ArcTan[(1 - (2*Cos[a + b*x]^(2/3))/Sin[a + b*x]^(2/3))/Sqrt[3]])/(2*b)) + Log[1 + Cos[a + b*x]^(4/3)/Sin[a + b*x]^(4/3) - Cos[a + b*x]^(2/3)/Sin[a + b*x]^(2/3)]/(4*b) - Log[1 + Cos[a + b*x]^(2/3)/Sin[a + b*x]^(2/3)]/(2*b) + (3*Sin[a + b*x]^(2/3))/(2*b*Cos[a + b*x]^(2/3))}
{Sin[a + b*x]^(4/3)/Cos[a + b*x]^(4/3), x, 9, -(ArcTan[Sqrt[3] - (2*Cos[a + b*x]^(1/3))/Sin[a + b*x]^(1/3)]/(2*b)) + ArcTan[Sqrt[3] + (2*Cos[a + b*x]^(1/3))/Sin[a + b*x]^(1/3)]/(2*b) + ArcTan[Cos[a + b*x]^(1/3)/Sin[a + b*x]^(1/3)]/b - (Sqrt[3]*ArcTanh[(Sqrt[3]*Cos[a + b*x]^(1/3))/((1 + Cos[a + b*x]^(2/3)/Sin[a + b*x]^(2/3))*Sin[a + b*x]^(1/3))])/(2*b) + (3*Sin[a + b*x]^(1/3))/(b*Cos[a + b*x]^(1/3))}
{Sin[a + b*x]^(2/3)/Cos[a + b*x]^(2/3), x, 8, -(ArcTan[Sqrt[3] - (2*Sin[a + b*x]^(1/3))/Cos[a + b*x]^(1/3)]/(2*b)) + ArcTan[Sqrt[3] + (2*Sin[a + b*x]^(1/3))/Cos[a + b*x]^(1/3)]/(2*b) + ArcTan[Sin[a + b*x]^(1/3)/Cos[a + b*x]^(1/3)]/b - (Sqrt[3]*ArcTanh[(Sqrt[3]*Sin[a + b*x]^(1/3))/(Cos[a + b*x]^(1/3)*(1 + Sin[a + b*x]^(2/3)/Cos[a + b*x]^(2/3)))])/(2*b)}
{Sin[a + b*x]^(1/3)/Cos[a + b*x]^(1/3), x, 7, -((Sqrt[3]*ArcTan[(1 - (2*Sin[a + b*x]^(2/3))/Cos[a + b*x]^(2/3))/Sqrt[3]])/(2*b)) - Log[1 + Sin[a + b*x]^(2/3)/Cos[a + b*x]^(2/3)]/(2*b) + Log[1 - Sin[a + b*x]^(2/3)/Cos[a + b*x]^(2/3) + Sin[a + b*x]^(4/3)/Cos[a + b*x]^(4/3)]/(4*b)}
{Cos[a + b*x]^(1/3)/Sin[a + b*x]^(1/3), x, 7, (Sqrt[3]*ArcTan[(1 - (2*Cos[a + b*x]^(2/3))/Sin[a + b*x]^(2/3))/Sqrt[3]])/(2*b) - Log[1 + Cos[a + b*x]^(4/3)/Sin[a + b*x]^(4/3) - Cos[a + b*x]^(2/3)/Sin[a + b*x]^(2/3)]/(4*b) + Log[1 + Cos[a + b*x]^(2/3)/Sin[a + b*x]^(2/3)]/(2*b)}
{Cos[a + b*x]^(2/3)/Sin[a + b*x]^(2/3), x, 8, ArcTan[Sqrt[3] - (2*Cos[a + b*x]^(1/3))/Sin[a + b*x]^(1/3)]/(2*b) - ArcTan[Sqrt[3] + (2*Cos[a + b*x]^(1/3))/Sin[a + b*x]^(1/3)]/(2*b) - ArcTan[Cos[a + b*x]^(1/3)/Sin[a + b*x]^(1/3)]/b + (Sqrt[3]*ArcTanh[(Sqrt[3]*Cos[a + b*x]^(1/3))/((1 + Cos[a + b*x]^(2/3)/Sin[a + b*x]^(2/3))*Sin[a + b*x]^(1/3))])/(2*b)}
{Cos[a + b*x]^(4/3)/Sin[a + b*x]^(4/3), x, 9, ArcTan[Sqrt[3] - (2*Sin[a + b*x]^(1/3))/Cos[a + b*x]^(1/3)]/(2*b) - ArcTan[Sqrt[3] + (2*Sin[a + b*x]^(1/3))/Cos[a + b*x]^(1/3)]/(2*b) - ArcTan[Sin[a + b*x]^(1/3)/Cos[a + b*x]^(1/3)]/b + (Sqrt[3]*ArcTanh[(Sqrt[3]*Sin[a + b*x]^(1/3))/(Cos[a + b*x]^(1/3)*(1 + Sin[a + b*x]^(2/3)/Cos[a + b*x]^(2/3)))])/(2*b) - (3*Cos[a + b*x]^(1/3))/(b*Sin[a + b*x]^(1/3))}
{Cos[a + b*x]^(5/3)/Sin[a + b*x]^(5/3), x, 8, (Sqrt[3]*ArcTan[(1 - (2*Sin[a + b*x]^(2/3))/Cos[a + b*x]^(2/3))/Sqrt[3]])/(2*b) + Log[1 + Sin[a + b*x]^(2/3)/Cos[a + b*x]^(2/3)]/(2*b) - Log[1 - Sin[a + b*x]^(2/3)/Cos[a + b*x]^(2/3) + Sin[a + b*x]^(4/3)/Cos[a + b*x]^(4/3)]/(4*b) - (3*Cos[a + b*x]^(2/3))/(2*b*Sin[a + b*x]^(2/3))}
{Cos[a + b*x]^(7/3)/Sin[a + b*x]^(7/3), x, 8, -((Sqrt[3]*ArcTan[(1 - (2*Cos[a + b*x]^(2/3))/Sin[a + b*x]^(2/3))/Sqrt[3]])/(2*b)) + Log[1 + Cos[a + b*x]^(4/3)/Sin[a + b*x]^(4/3) - Cos[a + b*x]^(2/3)/Sin[a + b*x]^(2/3)]/(4*b) - Log[1 + Cos[a + b*x]^(2/3)/Sin[a + b*x]^(2/3)]/(2*b) - (3*Cos[a + b*x]^(4/3))/(4*b*Sin[a + b*x]^(4/3))}


{Sin[x]^(3/2)/Cos[x]^(7/2), x, 1, (2*Sin[x]^(5/2))/(5*Cos[x]^(5/2))}
{Sqrt[Sin[x]]/Sqrt[Cos[x]], x, 8, -(ArcTan[1 - (Sqrt[2]*Sqrt[Sin[x]])/Sqrt[Cos[x]]]/Sqrt[2]) + ArcTan[1 + (Sqrt[2]*Sqrt[Sin[x]])/Sqrt[Cos[x]]]/Sqrt[2] + Log[1 - (Sqrt[2]*Sqrt[Sin[x]])/Sqrt[Cos[x]] + Tan[x]]/(2*Sqrt[2]) - Log[1 + (Sqrt[2]*Sqrt[Sin[x]])/Sqrt[Cos[x]] + Tan[x]]/(2*Sqrt[2])}
{Sin[x]^(5/2)/Sqrt[Cos[x]], x, 9, -((3*ArcTan[1 - (Sqrt[2]*Sqrt[Sin[x]])/Sqrt[Cos[x]]])/(4*Sqrt[2])) + (3*ArcTan[1 + (Sqrt[2]*Sqrt[Sin[x]])/Sqrt[Cos[x]]])/(4*Sqrt[2]) + (3*Log[1 - (Sqrt[2]*Sqrt[Sin[x]])/Sqrt[Cos[x]] + Tan[x]])/(8*Sqrt[2]) - (3*Log[1 + (Sqrt[2]*Sqrt[Sin[x]])/Sqrt[Cos[x]] + Tan[x]])/(8*Sqrt[2]) - (1/2)*Sqrt[Cos[x]]*Sin[x]^(3/2)}


{Cos[x]^(2/3)/Sin[x]^(8/3), x, 1, (-3*Cos[x]^(5/3))/(5*Sin[x]^(5/3))}
{Sin[x]^(2/3)/Cos[x]^(8/3), x, 1, (3*Sin[x]^(5/3))/(5*Cos[x]^(5/3))}


{Sin[x]^(5/2)/Tan[x]^(3/2), x, 1, (-2*Sin[x]^(5/2))/(5*Tan[x]^(5/2))}


(* ::Subsection:: *)
(*Integrands of the form Sec[a+b x]^(m/2) Sin[a+b x]^n*)


(* ::Subsection::Closed:: *)
(*Integrands of the form Cos[a+b x]^m Csc[a+b x]^(n/2)*)


(* ::Subsubsection::Closed:: *)
(*n>0*)


{Cos[a + b*x]^4*Csc[a + b*x]^(1/2), x, 4, (4*Cos[a + b*x])/(7*b*Sqrt[Csc[a + b*x]]) + (2*Cos[a + b*x]^3)/(7*b*Sqrt[Csc[a + b*x]]) - (8*Sqrt[Csc[a + b*x]]*EllipticF[Pi/4 + (1/2)*(-a - b*x), 2]*Sqrt[Sin[a + b*x]])/(7*b)}
{Cos[a + b*x]^3*Csc[a + b*x]^(1/2), x, 4, -(2/(5*b*Csc[a + b*x]^(5/2))) + 2/(b*Sqrt[Csc[a + b*x]])}
{Cos[a + b*x]^2*Csc[a + b*x]^(1/2), x, 3, (2*Cos[a + b*x])/(3*b*Sqrt[Csc[a + b*x]]) - (4*Sqrt[Csc[a + b*x]]*EllipticF[Pi/4 + (1/2)*(-a - b*x), 2]*Sqrt[Sin[a + b*x]])/(3*b)}
{Cos[a + b*x]^1*Csc[a + b*x]^(1/2), x, 1, 2/(b*Sqrt[Csc[a + b*x]])}
{Sec[a + b*x]^1*Csc[a + b*x]^(1/2), x, 6, (ArcTan[Sqrt[Sin[a + b*x]]]*Sqrt[Csc[a + b*x]]*Sqrt[Sin[a + b*x]])/b + (ArcTanh[Sqrt[Sin[a + b*x]]]*Sqrt[Csc[a + b*x]]*Sqrt[Sin[a + b*x]])/b}
{Sec[a + b*x]^2*Csc[a + b*x]^(1/2), x, 3, Sec[a + b*x]/(b*Sqrt[Csc[a + b*x]]) - (Sqrt[Csc[a + b*x]]*EllipticF[Pi/4 + (1/2)*(-a - b*x), 2]*Sqrt[Sin[a + b*x]])/b}
{Sec[a + b*x]^3*Csc[a + b*x]^(1/2), x, 7, Sec[a + b*x]^2/(2*b*Sqrt[Csc[a + b*x]]) + (3*ArcTan[Sqrt[Sin[a + b*x]]]*Sqrt[Csc[a + b*x]]*Sqrt[Sin[a + b*x]])/(4*b) + (3*ArcTanh[Sqrt[Sin[a + b*x]]]*Sqrt[Csc[a + b*x]]*Sqrt[Sin[a + b*x]])/(4*b)}
{Sec[a + b*x]^4*Csc[a + b*x]^(1/2), x, 4, (5*Sec[a + b*x])/(6*b*Sqrt[Csc[a + b*x]]) + Sec[a + b*x]^3/(3*b*Sqrt[Csc[a + b*x]]) - (5*Sqrt[Csc[a + b*x]]*EllipticF[Pi/4 + (1/2)*(-a - b*x), 2]*Sqrt[Sin[a + b*x]])/(6*b)}


(* ::Subsubsection::Closed:: *)
(*n<0*)


{Cos[a + b*x]^4/Csc[a + b*x]^(1/2), x, 4, (4*Cos[a + b*x])/(15*b*Csc[a + b*x]^(3/2)) + (2*Cos[a + b*x]^3)/(9*b*Csc[a + b*x]^(3/2)) - (8*Sqrt[Csc[a + b*x]]*EllipticE[Pi/4 + (1/2)*(-a - b*x), 2]*Sqrt[Sin[a + b*x]])/(15*b)}
{Cos[a + b*x]^3/Csc[a + b*x]^(1/2), x, 4, -(2/(7*b*Csc[a + b*x]^(7/2))) + 2/(3*b*Csc[a + b*x]^(3/2))}
{Cos[a + b*x]^2/Csc[a + b*x]^(1/2), x, 3, (2*Cos[a + b*x])/(5*b*Csc[a + b*x]^(3/2)) - (4*Sqrt[Csc[a + b*x]]*EllipticE[Pi/4 + (1/2)*(-a - b*x), 2]*Sqrt[Sin[a + b*x]])/(5*b)}
{Cos[a + b*x]^1/Csc[a + b*x]^(1/2), x, 1, 2/(3*b*Csc[a + b*x]^(3/2))}
{Sec[a + b*x]^1/Csc[a + b*x]^(1/2), x, 6, -((ArcTan[Sqrt[Sin[a + b*x]]]*Sqrt[Csc[a + b*x]]*Sqrt[Sin[a + b*x]])/b) + (ArcTanh[Sqrt[Sin[a + b*x]]]*Sqrt[Csc[a + b*x]]*Sqrt[Sin[a + b*x]])/b}
{Sec[a + b*x]^2/Csc[a + b*x]^(1/2), x, 3, Sec[a + b*x]/(b*Csc[a + b*x]^(3/2)) + (Sqrt[Csc[a + b*x]]*EllipticE[Pi/4 + (1/2)*(-a - b*x), 2]*Sqrt[Sin[a + b*x]])/b}
{Sec[a + b*x]^3/Csc[a + b*x]^(1/2), x, 7, Sec[a + b*x]^2/(2*b*Csc[a + b*x]^(3/2)) - (ArcTan[Sqrt[Sin[a + b*x]]]*Sqrt[Csc[a + b*x]]*Sqrt[Sin[a + b*x]])/(4*b) + (ArcTanh[Sqrt[Sin[a + b*x]]]*Sqrt[Csc[a + b*x]]*Sqrt[Sin[a + b*x]])/(4*b)}
{Sec[a + b*x]^4/Csc[a + b*x]^(1/2), x, 4, Sec[a + b*x]/(2*b*Csc[a + b*x]^(3/2)) + Sec[a + b*x]^3/(3*b*Csc[a + b*x]^(3/2)) + (Sqrt[Csc[a + b*x]]*EllipticE[Pi/4 + (1/2)*(-a - b*x), 2]*Sqrt[Sin[a + b*x]])/(2*b)}


(* ::Subsection::Closed:: *)
(*Integrands of the form Sec[a+b x]^(m/2) Csc[a+b x]^(n/2)*)


(* ::Subsubsection::Closed:: *)
(*m>0*)


{Sec[a + b*x]^(1/2)*Csc[a + b*x]^(5/2), x, 3, -((2*Csc[a + b*x]^(3/2))/(3*b*Sqrt[Sec[a + b*x]])) - (4*Hypergeometric2F1[1/4, 3/4, 5/4, Cos[a + b*x]^2])/(3*b*Sqrt[Csc[a + b*x]]*Sqrt[Sec[a + b*x]]*(Sin[a + b*x]^2)^(1/4))}
{Sec[a + b*x]^(1/2)*Csc[a + b*x]^(3/2), x, 1, -((2*Sqrt[Csc[a + b*x]])/(b*Sqrt[Sec[a + b*x]]))}
{Sec[a + b*x]^(1/2)*Csc[a + b*x]^(1/2), x, 2, -((2*Hypergeometric2F1[1/4, 3/4, 5/4, Cos[a + b*x]^2])/(b*Sqrt[Csc[a + b*x]]*Sqrt[Sec[a + b*x]]*(Sin[a + b*x]^2)^(1/4)))}
{Sec[a + b*x]^(1/2)/Csc[a + b*x]^(1/2), x, 9, -((ArcTan[1 - Sqrt[2]*Sqrt[Tan[a + b*x]]]*Sqrt[Sec[a + b*x]])/(Sqrt[2]*b*Sqrt[Csc[a + b*x]]*Sqrt[Tan[a + b*x]])) + (ArcTan[1 + Sqrt[2]*Sqrt[Tan[a + b*x]]]*Sqrt[Sec[a + b*x]])/(Sqrt[2]*b*Sqrt[Csc[a + b*x]]*Sqrt[Tan[a + b*x]]) + (Log[1 - Sqrt[2]*Sqrt[Tan[a + b*x]] + Tan[a + b*x]]*Sqrt[Sec[a + b*x]])/(2*Sqrt[2]*b*Sqrt[Csc[a + b*x]]*Sqrt[Tan[a + b*x]]) - (Log[1 + Sqrt[2]*Sqrt[Tan[a + b*x]] + Tan[a + b*x]]*Sqrt[Sec[a + b*x]])/(2*Sqrt[2]*b*Sqrt[Csc[a + b*x]]*Sqrt[Tan[a + b*x]])}
{Sec[a + b*x]^(1/2)/Csc[a + b*x]^(3/2), x, 3, -(1/(b*Sqrt[Csc[a + b*x]]*Sqrt[Sec[a + b*x]])) - Hypergeometric2F1[1/4, 3/4, 5/4, Cos[a + b*x]^2]/(b*Sqrt[Csc[a + b*x]]*Sqrt[Sec[a + b*x]]*(Sin[a + b*x]^2)^(1/4))}
{Sec[a + b*x]^(1/2)/Csc[a + b*x]^(5/2), x, 10, -(1/(2*b*Csc[a + b*x]^(3/2)*Sqrt[Sec[a + b*x]])) - (3*ArcTan[1 - Sqrt[2]*Sqrt[Tan[a + b*x]]]*Sqrt[Sec[a + b*x]])/(4*Sqrt[2]*b*Sqrt[Csc[a + b*x]]*Sqrt[Tan[a + b*x]]) + (3*ArcTan[1 + Sqrt[2]*Sqrt[Tan[a + b*x]]]*Sqrt[Sec[a + b*x]])/(4*Sqrt[2]*b*Sqrt[Csc[a + b*x]]*Sqrt[Tan[a + b*x]]) + (3*Log[1 - Sqrt[2]*Sqrt[Tan[a + b*x]] + Tan[a + b*x]]*Sqrt[Sec[a + b*x]])/(8*Sqrt[2]*b*Sqrt[Csc[a + b*x]]*Sqrt[Tan[a + b*x]]) - (3*Log[1 + Sqrt[2]*Sqrt[Tan[a + b*x]] + Tan[a + b*x]]*Sqrt[Sec[a + b*x]])/(8*Sqrt[2]*b*Sqrt[Csc[a + b*x]]*Sqrt[Tan[a + b*x]])}


{Sec[a + b*x]^(3/2)*Csc[a + b*x]^(5/2), x, 2, (8*Sqrt[Sec[a + b*x]])/(3*b*Sqrt[Csc[a + b*x]]) - (2*Csc[a + b*x]^(3/2)*Sqrt[Sec[a + b*x]])/(3*b)}
{Sec[a + b*x]^(3/2)*Csc[a + b*x]^(3/2), x, 4, (4*Sqrt[Sec[a + b*x]])/(b*Csc[a + b*x]^(3/2)) - (2*Sqrt[Csc[a + b*x]]*Sqrt[Sec[a + b*x]])/b + (8*Hypergeometric2F1[1/4, 3/4, 7/4, Cos[a + b*x]^2])/(3*b*Csc[a + b*x]^(3/2)*Sec[a + b*x]^(3/2)*(Sin[a + b*x]^2)^(3/4))}
{Sec[a + b*x]^(3/2)*Csc[a + b*x]^(1/2), x, 1, (2*Sqrt[Sec[a + b*x]])/(b*Sqrt[Csc[a + b*x]])}
{Sec[a + b*x]^(3/2)/Csc[a + b*x]^(1/2), x, 3, (2*Sqrt[Sec[a + b*x]])/(b*Csc[a + b*x]^(3/2)) + (4*Hypergeometric2F1[1/4, 3/4, 7/4, Cos[a + b*x]^2])/(3*b*Csc[a + b*x]^(3/2)*Sec[a + b*x]^(3/2)*(Sin[a + b*x]^2)^(3/4))}
{Sec[a + b*x]^(3/2)/Csc[a + b*x]^(3/2), x, 10, (2*Sqrt[Sec[a + b*x]])/(b*Sqrt[Csc[a + b*x]]) + (ArcTan[1 - Sqrt[2]*Sqrt[Tan[a + b*x]]]*Sqrt[Csc[a + b*x]]*Sqrt[Tan[a + b*x]])/(Sqrt[2]*b*Sqrt[Sec[a + b*x]]) - (ArcTan[1 + Sqrt[2]*Sqrt[Tan[a + b*x]]]*Sqrt[Csc[a + b*x]]*Sqrt[Tan[a + b*x]])/(Sqrt[2]*b*Sqrt[Sec[a + b*x]]) + (Sqrt[Csc[a + b*x]]*Log[1 - Sqrt[2]*Sqrt[Tan[a + b*x]] + Tan[a + b*x]]*Sqrt[Tan[a + b*x]])/(2*Sqrt[2]*b*Sqrt[Sec[a + b*x]]) - (Sqrt[Csc[a + b*x]]*Log[1 + Sqrt[2]*Sqrt[Tan[a + b*x]] + Tan[a + b*x]]*Sqrt[Tan[a + b*x]])/(2*Sqrt[2]*b*Sqrt[Sec[a + b*x]])}
{Sec[a + b*x]^(3/2)/Csc[a + b*x]^(5/2), x, 3, (2*Sqrt[Sec[a + b*x]])/(b*Csc[a + b*x]^(3/2)) + (2*Hypergeometric2F1[1/4, 3/4, 7/4, Cos[a + b*x]^2])/(b*Csc[a + b*x]^(3/2)*Sec[a + b*x]^(3/2)*(Sin[a + b*x]^2)^(3/4))}


(* ::Subsubsection::Closed:: *)
(*m>0*)


{1/Sec[a + b*x]^(1/2)*Csc[a + b*x]^(5/2), x, 1, -((2*Csc[a + b*x]^(3/2))/(3*b*Sec[a + b*x]^(3/2)))}
{1/Sec[a + b*x]^(1/2)*Csc[a + b*x]^(3/2), x, 3, -((2*Sqrt[Csc[a + b*x]])/(b*Sec[a + b*x]^(3/2))) + (4*Hypergeometric2F1[1/4, 3/4, 7/4, Cos[a + b*x]^2])/(3*b*Csc[a + b*x]^(3/2)*Sec[a + b*x]^(3/2)*(Sin[a + b*x]^2)^(3/4))}
{1/Sec[a + b*x]^(1/2)*Csc[a + b*x]^(1/2), x, 9, -((ArcTan[1 - Sqrt[2]*Sqrt[Tan[a + b*x]]]*Sqrt[Csc[a + b*x]]*Sqrt[Tan[a + b*x]])/(Sqrt[2]*b*Sqrt[Sec[a + b*x]])) + (ArcTan[1 + Sqrt[2]*Sqrt[Tan[a + b*x]]]*Sqrt[Csc[a + b*x]]*Sqrt[Tan[a + b*x]])/(Sqrt[2]*b*Sqrt[Sec[a + b*x]]) - (Sqrt[Csc[a + b*x]]*Log[1 - Sqrt[2]*Sqrt[Tan[a + b*x]] + Tan[a + b*x]]*Sqrt[Tan[a + b*x]])/(2*Sqrt[2]*b*Sqrt[Sec[a + b*x]]) + (Sqrt[Csc[a + b*x]]*Log[1 + Sqrt[2]*Sqrt[Tan[a + b*x]] + Tan[a + b*x]]*Sqrt[Tan[a + b*x]])/(2*Sqrt[2]*b*Sqrt[Sec[a + b*x]])}
{1/Sec[a + b*x]^(1/2)/Csc[a + b*x]^(1/2), x, 2, -((2*Hypergeometric2F1[1/4, 3/4, 7/4, Cos[a + b*x]^2])/(3*b*Csc[a + b*x]^(3/2)*Sec[a + b*x]^(3/2)*(Sin[a + b*x]^2)^(3/4)))}
{1/Sec[a + b*x]^(1/2)/Csc[a + b*x]^(3/2), x, 10, -(1/(2*b*Sqrt[Csc[a + b*x]]*Sec[a + b*x]^(3/2))) - (ArcTan[1 - Sqrt[2]*Sqrt[Tan[a + b*x]]]*Sqrt[Csc[a + b*x]]*Sqrt[Tan[a + b*x]])/(4*Sqrt[2]*b*Sqrt[Sec[a + b*x]]) + (ArcTan[1 + Sqrt[2]*Sqrt[Tan[a + b*x]]]*Sqrt[Csc[a + b*x]]*Sqrt[Tan[a + b*x]])/(4*Sqrt[2]*b*Sqrt[Sec[a + b*x]]) - (Sqrt[Csc[a + b*x]]*Log[1 - Sqrt[2]*Sqrt[Tan[a + b*x]] + Tan[a + b*x]]*Sqrt[Tan[a + b*x]])/(8*Sqrt[2]*b*Sqrt[Sec[a + b*x]]) + (Sqrt[Csc[a + b*x]]*Log[1 + Sqrt[2]*Sqrt[Tan[a + b*x]] + Tan[a + b*x]]*Sqrt[Tan[a + b*x]])/(8*Sqrt[2]*b*Sqrt[Sec[a + b*x]])}
{1/Sec[a + b*x]^(1/2)/Csc[a + b*x]^(5/2), x, 3, -(1/(3*b*Csc[a + b*x]^(3/2)*Sec[a + b*x]^(3/2))) - Hypergeometric2F1[1/4, 3/4, 7/4, Cos[a + b*x]^2]/(3*b*Csc[a + b*x]^(3/2)*Sec[a + b*x]^(3/2)*(Sin[a + b*x]^2)^(3/4))}


{1/Sec[a + b*x]^(3/2)*Csc[a + b*x]^(5/2), x, 3, -((2*Csc[a + b*x]^(3/2))/(3*b*Sqrt[Sec[a + b*x]])) + (2*Hypergeometric2F1[1/4, 3/4, 5/4, Cos[a + b*x]^2])/(3*b*Sqrt[Csc[a + b*x]]*Sqrt[Sec[a + b*x]]*(Sin[a + b*x]^2)^(1/4))}
{1/Sec[a + b*x]^(3/2)*Csc[a + b*x]^(3/2), x, 10, -((2*Sqrt[Csc[a + b*x]])/(b*Sqrt[Sec[a + b*x]])) + (ArcTan[1 - Sqrt[2]*Sqrt[Tan[a + b*x]]]*Sqrt[Sec[a + b*x]])/(Sqrt[2]*b*Sqrt[Csc[a + b*x]]*Sqrt[Tan[a + b*x]]) - (ArcTan[1 + Sqrt[2]*Sqrt[Tan[a + b*x]]]*Sqrt[Sec[a + b*x]])/(Sqrt[2]*b*Sqrt[Csc[a + b*x]]*Sqrt[Tan[a + b*x]]) - (Log[1 - Sqrt[2]*Sqrt[Tan[a + b*x]] + Tan[a + b*x]]*Sqrt[Sec[a + b*x]])/(2*Sqrt[2]*b*Sqrt[Csc[a + b*x]]*Sqrt[Tan[a + b*x]]) + (Log[1 + Sqrt[2]*Sqrt[Tan[a + b*x]] + Tan[a + b*x]]*Sqrt[Sec[a + b*x]])/(2*Sqrt[2]*b*Sqrt[Csc[a + b*x]]*Sqrt[Tan[a + b*x]])}
{1/Sec[a + b*x]^(3/2)*Csc[a + b*x]^(1/2), x, 3, 1/(b*Sqrt[Csc[a + b*x]]*Sqrt[Sec[a + b*x]]) - Hypergeometric2F1[1/4, 3/4, 5/4, Cos[a + b*x]^2]/(b*Sqrt[Csc[a + b*x]]*Sqrt[Sec[a + b*x]]*(Sin[a + b*x]^2)^(1/4))}
{1/Sec[a + b*x]^(3/2)/Csc[a + b*x]^(1/2), x, 10, 1/(2*b*Csc[a + b*x]^(3/2)*Sqrt[Sec[a + b*x]]) - (ArcTan[1 - Sqrt[2]*Sqrt[Tan[a + b*x]]]*Sqrt[Sec[a + b*x]])/(4*Sqrt[2]*b*Sqrt[Csc[a + b*x]]*Sqrt[Tan[a + b*x]]) + (ArcTan[1 + Sqrt[2]*Sqrt[Tan[a + b*x]]]*Sqrt[Sec[a + b*x]])/(4*Sqrt[2]*b*Sqrt[Csc[a + b*x]]*Sqrt[Tan[a + b*x]]) + (Log[1 - Sqrt[2]*Sqrt[Tan[a + b*x]] + Tan[a + b*x]]*Sqrt[Sec[a + b*x]])/(8*Sqrt[2]*b*Sqrt[Csc[a + b*x]]*Sqrt[Tan[a + b*x]]) - (Log[1 + Sqrt[2]*Sqrt[Tan[a + b*x]] + Tan[a + b*x]]*Sqrt[Sec[a + b*x]])/(8*Sqrt[2]*b*Sqrt[Csc[a + b*x]]*Sqrt[Tan[a + b*x]])}
{1/Sec[a + b*x]^(3/2)/Csc[a + b*x]^(3/2), x, 4, -(1/(3*b*Sqrt[Csc[a + b*x]]*Sec[a + b*x]^(5/2))) + 1/(6*b*Sqrt[Csc[a + b*x]]*Sqrt[Sec[a + b*x]]) - Hypergeometric2F1[1/4, 3/4, 5/4, Cos[a + b*x]^2]/(6*b*Sqrt[Csc[a + b*x]]*Sqrt[Sec[a + b*x]]*(Sin[a + b*x]^2)^(1/4))}
{1/Sec[a + b*x]^(3/2)/Csc[a + b*x]^(5/2), x, 11, -(1/(4*b*Csc[a + b*x]^(3/2)*Sec[a + b*x]^(5/2))) + 3/(16*b*Csc[a + b*x]^(3/2)*Sqrt[Sec[a + b*x]]) - (3*ArcTan[1 - Sqrt[2]*Sqrt[Tan[a + b*x]]]*Sqrt[Sec[a + b*x]])/(32*Sqrt[2]*b*Sqrt[Csc[a + b*x]]*Sqrt[Tan[a + b*x]]) + (3*ArcTan[1 + Sqrt[2]*Sqrt[Tan[a + b*x]]]*Sqrt[Sec[a + b*x]])/(32*Sqrt[2]*b*Sqrt[Csc[a + b*x]]*Sqrt[Tan[a + b*x]]) + (3*Log[1 - Sqrt[2]*Sqrt[Tan[a + b*x]] + Tan[a + b*x]]*Sqrt[Sec[a + b*x]])/(64*Sqrt[2]*b*Sqrt[Csc[a + b*x]]*Sqrt[Tan[a + b*x]]) - (3*Log[1 + Sqrt[2]*Sqrt[Tan[a + b*x]] + Tan[a + b*x]]*Sqrt[Sec[a + b*x]])/(64*Sqrt[2]*b*Sqrt[Csc[a + b*x]]*Sqrt[Tan[a + b*x]])}
