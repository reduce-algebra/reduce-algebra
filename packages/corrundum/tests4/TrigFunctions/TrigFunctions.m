(* ::Package:: *)

(* ::Title:: *)
(*Miscellaneous Integration Problems Involving Trig Functions*)


(* ::Section::Closed:: *)
(*Integrands involving sines*)


{(x + Sin[x])^2, x, 5, x/2 + x^3/3 - 2*x*Cos[x] + 2*Sin[x] - (1/2)*Cos[x]*Sin[x]}
{(x + Sin[x])^3, x, 9, (3*x^2)/4 + x^4/4 + 5*Cos[x] - 3*x^2*Cos[x] + Cos[x]^3/3 + 6*x*Sin[x] - (3/2)*x*Cos[x]*Sin[x] + (3*Sin[x]^2)/4}


{Sin[a + b*x]/(c + d*x^2), x, 7, -((CosIntegral[(b*Sqrt[-c])/Sqrt[d] + b*x]*Sin[a - (b*Sqrt[-c])/Sqrt[d]])/(2*Sqrt[-c]*Sqrt[d])) + (CosIntegral[(b*Sqrt[-c])/Sqrt[d] - b*x]*Sin[a + (b*Sqrt[-c])/Sqrt[d]])/(2*Sqrt[-c]*Sqrt[d]) - (Cos[a + (b*Sqrt[-c])/Sqrt[d]]*SinIntegral[(b*Sqrt[-c])/Sqrt[d] - b*x])/(2*Sqrt[-c]*Sqrt[d]) - (Cos[a - (b*Sqrt[-c])/Sqrt[d]]*SinIntegral[(b*Sqrt[-c])/Sqrt[d] + b*x])/(2*Sqrt[-c]*Sqrt[d])}
{Sin[a + b*x]/(c + d*x + e*x^2), x, 7, (CosIntegral[(b*(d - Sqrt[d^2 - 4*c*e]))/(2*e) + b*x]*Sin[a - (b*(d - Sqrt[d^2 - 4*c*e]))/(2*e)])/Sqrt[d^2 - 4*c*e] - (CosIntegral[(b*(d + Sqrt[d^2 - 4*c*e]))/(2*e) + b*x]*Sin[a - (b*(d + Sqrt[d^2 - 4*c*e]))/(2*e)])/Sqrt[d^2 - 4*c*e] + (Cos[a - (b*(d - Sqrt[d^2 - 4*c*e]))/(2*e)]*SinIntegral[(b*(d - Sqrt[d^2 - 4*c*e]))/(2*e) + b*x])/Sqrt[d^2 - 4*c*e] - (Cos[a - (b*(d + Sqrt[d^2 - 4*c*e]))/(2*e)]*SinIntegral[(b*(d + Sqrt[d^2 - 4*c*e]))/(2*e) + b*x])/Sqrt[d^2 - 4*c*e]}


{Sin[Sqrt[1 + x]], x, 4, -2*Sqrt[1 + x]*Cos[Sqrt[1 + x]] + 2*Sin[Sqrt[1 + x]]}
{Sin[Sqrt[-7 + x]]/Sqrt[-7 + x], x, 2, -2*Cos[Sqrt[-7 + x]]}


{Sin[x]*Sqrt[b - a/x^2]/Sqrt[a - b*x^2], x, 2, (Sqrt[b - a/x^2]*x*SinIntegral[x])/Sqrt[a - b*x^2]}


(* ::Subsection::Closed:: *)
(*Sin[(a+b x)/(c+d x)]^n*)


{Sin[(a + b*x)/(c + d*x)]^1, x, 5, ((b*c - a*d)*Cos[b/d]*CosIntegral[(b*c - a*d)/(d*(c + d*x))])/d^2 + ((c + d*x)*Sin[b/d - (b*c - a*d)/(d*(c + d*x))])/d + ((b*c - a*d)*Sin[b/d]*SinIntegral[(b*c - a*d)/(d*(c + d*x))])/d^2}
{Sin[(a + b*x)/(c + d*x)]^2, x, 6, ((b*c - a*d)*CosIntegral[(2*(b*c - a*d))/(d*(c + d*x))]*Sin[(2*b)/d])/d^2 + ((c + d*x)*Sin[b/d - (b*c - a*d)/(d*(c + d*x))]^2)/d - ((b*c - a*d)*Cos[(2*b)/d]*SinIntegral[(2*(b*c - a*d))/(d*(c + d*x))])/d^2}
{Sin[(a + b*x)/(c + d*x)]^3, x, 9, (3*(b*c - a*d)*Cos[b/d]*CosIntegral[(b*c - a*d)/(d*(c + d*x))])/(4*d^2) - (3*(b*c - a*d)*Cos[(3*b)/d]*CosIntegral[(3*(b*c - a*d))/(d*(c + d*x))])/(4*d^2) + ((c + d*x)*Sin[b/d - (b*c - a*d)/(d*(c + d*x))]^3)/d + (3*(b*c - a*d)*Sin[b/d]*SinIntegral[(b*c - a*d)/(d*(c + d*x))])/(4*d^2) - (3*(b*c - a*d)*Sin[(3*b)/d]*SinIntegral[(3*(b*c - a*d))/(d*(c + d*x))])/(4*d^2)}


(* ::Section::Closed:: *)
(*Integrands involving cosines*)


{(x + Cos[x])^2, x, 5, x/2 + x^3/3 + 2*Cos[x] + 2*x*Sin[x] + (1/2)*Cos[x]*Sin[x]}
{(x + Cos[x])^3, x, 9, (3*x^2)/4 + x^4/4 + 6*x*Cos[x] + (3*Cos[x]^2)/4 - 5*Sin[x] + 3*x^2*Sin[x] + (3/2)*x*Cos[x]*Sin[x] - Sin[x]^3/3}


{Cos[a + b*x]/(c + d*x^2), x, 7, (Cos[a + (b*Sqrt[-c])/Sqrt[d]]*CosIntegral[(b*Sqrt[-c])/Sqrt[d] - b*x])/(2*Sqrt[-c]*Sqrt[d]) - (Cos[a - (b*Sqrt[-c])/Sqrt[d]]*CosIntegral[(b*Sqrt[-c])/Sqrt[d] + b*x])/(2*Sqrt[-c]*Sqrt[d]) + (Sin[a + (b*Sqrt[-c])/Sqrt[d]]*SinIntegral[(b*Sqrt[-c])/Sqrt[d] - b*x])/(2*Sqrt[-c]*Sqrt[d]) + (Sin[a - (b*Sqrt[-c])/Sqrt[d]]*SinIntegral[(b*Sqrt[-c])/Sqrt[d] + b*x])/(2*Sqrt[-c]*Sqrt[d])}
{Cos[a + b*x]/(c + d*x + e*x^2), x, 7, (Cos[a - (b*(d - Sqrt[d^2 - 4*c*e]))/(2*e)]*CosIntegral[(b*(d - Sqrt[d^2 - 4*c*e]))/(2*e) + b*x])/Sqrt[d^2 - 4*c*e] - (Cos[a - (b*(d + Sqrt[d^2 - 4*c*e]))/(2*e)]*CosIntegral[(b*(d + Sqrt[d^2 - 4*c*e]))/(2*e) + b*x])/Sqrt[d^2 - 4*c*e] - (Sin[a - (b*(d - Sqrt[d^2 - 4*c*e]))/(2*e)]*SinIntegral[(b*(d - Sqrt[d^2 - 4*c*e]))/(2*e) + b*x])/Sqrt[d^2 - 4*c*e] + (Sin[a - (b*(d + Sqrt[d^2 - 4*c*e]))/(2*e)]*SinIntegral[(b*(d + Sqrt[d^2 - 4*c*e]))/(2*e) + b*x])/Sqrt[d^2 - 4*c*e]}


{Cos[Sqrt[1 - x]], x, 4, -2*Cos[Sqrt[1 - x]] - 2*Sqrt[1 - x]*Sin[Sqrt[1 - x]]}


{(x*Cos[Sqrt[1 + x^2]])/Sqrt[1 + x^2], x, 3, Sin[Sqrt[1 + x^2]]}
{(x*Cos[Sqrt[3]*Sqrt[2 + x^2]])/Sqrt[2 + x^2], x, 3, Sin[Sqrt[3]*Sqrt[2 + x^2]]/Sqrt[3]}
{((-1 + 2*x)*Cos[Sqrt[6 + 3*(-1 + 2*x)^2]])/Sqrt[6 + 3*(-1 + 2*x)^2], x, 4, (1/6)*Sin[Sqrt[6 + 3*(1 - 2*x)^2]]}


(* ::Subsection::Closed:: *)
(*Cos[(a+b x)/(c+d x)]^n*)


{Cos[(a + b*x)/(c + d*x)], x, 5, ((c + d*x)*Cos[b/d - (b*c - a*d)/(d*(c + d*x))])/d - ((b*c - a*d)*CosIntegral[(b*c - a*d)/(d*(c + d*x))]*Sin[b/d])/d^2 + ((b*c - a*d)*Cos[b/d]*SinIntegral[(b*c - a*d)/(d*(c + d*x))])/d^2}
{Cos[(a + b*x)/(c + d*x)]^2, x, 6, ((c + d*x)*Cos[b/d - (b*c - a*d)/(d*(c + d*x))]^2)/d - ((b*c - a*d)*CosIntegral[(2*(b*c - a*d))/(d*(c + d*x))]*Sin[(2*b)/d])/d^2 + ((b*c - a*d)*Cos[(2*b)/d]*SinIntegral[(2*(b*c - a*d))/(d*(c + d*x))])/d^2}


(* ::Section::Closed:: *)
(*Integrands involving tangents*)


{Tan[Sqrt[x]]/Sqrt[x], x, 2, -2*Log[Cos[Sqrt[x]]]}
{Tan[Sqrt[x]]^2/Sqrt[x], x, 3, -2*Sqrt[x] + 2*Tan[Sqrt[x]]}


{Sqrt[x]*Tan[Sqrt[x]], x, 6, (2/3)*I*x^(3/2) - 2*x*Log[1 + E^(2*I*Sqrt[x])] + 2*I*Sqrt[x]*PolyLog[2, -E^(2*I*Sqrt[x])] - PolyLog[3, -E^(2*I*Sqrt[x])]}


{x*Tan[a + b*x + c*x^2] + (b*Tan[a + b*x + c*x^2])/(2*c), x, 2, -(Log[Cos[a + b*x + c*x^2]]/(2*c))}


(* ::Section::Closed:: *)
(*Integrands involving cotangents*)


{Cot[Sqrt[x]]^2/Sqrt[x], x, 3, -2*Sqrt[x] - 2*Cot[Sqrt[x]]}


(* ::Section::Closed:: *)
(*Integrands involving secants*)


{Sqrt[a + b*Sec[c + d*x]]/(1 + Cos[c + d*x]), x, 2, ((a + b)*Sqrt[1 + Cos[c + d*x]]*Sqrt[(b + a*Cos[c + d*x])/((a + b)*(1 + Cos[c + d*x]))]*EllipticE[ArcSin[Sin[c + d*x]/(1 + Cos[c + d*x])], (a - b)/(a + b)])/(d*Sqrt[Cos[c + d*x]]*Sqrt[a + b*Sec[c + d*x]])}


{Sec[a + b*x]*Sec[2*a + 2*b*x], x, 4, -(ArcTanh[Sin[a + b*x]]/b) + (Sqrt[2]*ArcTanh[Sqrt[2]*Sin[a + b*x]])/b}
{Sec[a + b*x]*Sec[2*(a + b*x)], x, 4, -(ArcTanh[Sin[a + b*x]]/b) + (Sqrt[2]*ArcTanh[Sqrt[2]*Sin[a + b*x]])/b}


(* ::Title:: *)
(*Integration Problems Involving Two Trig Functions*)


(* ::Section::Closed:: *)
(*Integrands of the form Trig[a+b x]^m Trig[2 a+2 b x]^n*)


(* ::Subsection::Closed:: *)
(*Integrands of the form Sin[a+b x]^m Sin[2 a+2 b x]^n*)


{Sin[a + b*x]*Sin[2*a + 2*b*x]^5, x, 4, (32*Sin[a + b*x]^7)/(7*b) - (64*Sin[a + b*x]^9)/(9*b) + (32*Sin[a + b*x]^11)/(11*b)}
{Sin[a + b*x]*Sin[2*a + 2*b*x]^4, x, 4, -((16*Cos[a + b*x]^5)/(5*b)) + (32*Cos[a + b*x]^7)/(7*b) - (16*Cos[a + b*x]^9)/(9*b)}
{Sin[a + b*x]*Sin[2*a + 2*b*x]^3, x, 4, (8*Sin[a + b*x]^5)/(5*b) - (8*Sin[a + b*x]^7)/(7*b)}
{Sin[a + b*x]*Sin[2*a + 2*b*x]^2, x, 4, -((4*Cos[a + b*x]^3)/(3*b)) + (4*Cos[a + b*x]^5)/(5*b)}
{Sin[a + b*x]*Sin[2*a + 2*b*x]^1, x, 2, (2*Sin[a + b*x]^3)/(3*b)}
{Sin[a + b*x]*Csc[2*a + 2*b*x]^1, x, 2, ArcTanh[Sin[a + b*x]]/(2*b)}
{Sin[a + b*x]*Csc[2*a + 2*b*x]^2, x, 3, -(ArcTanh[Cos[a + b*x]]/(4*b)) + Sec[a + b*x]/(4*b)}
{Sin[a + b*x]*Csc[2*a + 2*b*x]^3, x, 4, (3*ArcTanh[Sin[a + b*x]])/(16*b) - (3*Csc[a + b*x])/(16*b) + (Csc[a + b*x]*Sec[a + b*x]^2)/(16*b)}
{Sin[a + b*x]*Csc[2*a + 2*b*x]^4, x, 5, -((5*ArcTanh[Cos[a + b*x]])/(32*b)) + (5*Sec[a + b*x])/(32*b) + (5*Sec[a + b*x]^3)/(96*b) - (Csc[a + b*x]^2*Sec[a + b*x]^3)/(32*b)}
{Sin[a + b*x]*Csc[2*a + 2*b*x]^5, x, 6, (35*ArcTanh[Sin[a + b*x]])/(256*b) - (35*Csc[a + b*x])/(256*b) - (35*Csc[a + b*x]^3)/(768*b) + (7*Csc[a + b*x]^3*Sec[a + b*x]^2)/(256*b) + (Csc[a + b*x]^3*Sec[a + b*x]^4)/(128*b)}


{Sin[a + b*x]^2*Sin[2*a + 2*b*x]^5, x, 5, (4*Sin[a + b*x]^8)/b - (32*Sin[a + b*x]^10)/(5*b) + (8*Sin[a + b*x]^12)/(3*b)}
{Sin[a + b*x]^2*Sin[2*a + 2*b*x]^4, x, 4, (3*x)/16 - (3*Cos[2*a + 2*b*x]*Sin[2*a + 2*b*x])/(32*b) - (Cos[2*a + 2*b*x]*Sin[2*a + 2*b*x]^3)/(16*b) - Sin[2*a + 2*b*x]^5/(20*b)}
{Sin[a + b*x]^2*Sin[2*a + 2*b*x]^3, x, 4, (4*Sin[a + b*x]^6)/(3*b) - Sin[a + b*x]^8/b}
{Sin[a + b*x]^2*Sin[2*a + 2*b*x]^2, x, 3, x/4 - (Cos[2*a + 2*b*x]*Sin[2*a + 2*b*x])/(8*b) - Sin[2*a + 2*b*x]^3/(12*b)}
{Sin[a + b*x]^2*Sin[2*a + 2*b*x]^1, x, 2, Sin[a + b*x]^4/(2*b)}
{Sin[a + b*x]^2*Csc[2*a + 2*b*x]^1, x, 2, -(Log[Cos[a + b*x]]/(2*b))}
{Sin[a + b*x]^2*Csc[2*a + 2*b*x]^2, x, 2, Tan[a + b*x]/(4*b)}
{Sin[a + b*x]^2*Csc[2*a + 2*b*x]^3, x, 4, Log[Tan[a + b*x]]/(8*b) + Tan[a + b*x]^2/(16*b)}
{Sin[a + b*x]^2*Csc[2*a + 2*b*x]^4, x, 4, -(Cot[a + b*x]/(16*b)) + Tan[a + b*x]/(8*b) + Tan[a + b*x]^3/(48*b)}
{Sin[a + b*x]^2*Csc[2*a + 2*b*x]^5, x, 4, -(Cot[a + b*x]^2/(64*b)) + (3*Log[Tan[a + b*x]])/(32*b) + (3*Tan[a + b*x]^2)/(64*b) + Tan[a + b*x]^4/(128*b)}


{Sin[a + b*x]^3*Sin[2*a + 2*b*x]^5, x, 4, (32*Sin[a + b*x]^9)/(9*b) - (64*Sin[a + b*x]^11)/(11*b) + (32*Sin[a + b*x]^13)/(13*b)}
{Sin[a + b*x]^3*Sin[2*a + 2*b*x]^4, x, 4, -((16*Cos[a + b*x]^5)/(5*b)) + (48*Cos[a + b*x]^7)/(7*b) - (16*Cos[a + b*x]^9)/(3*b) + (16*Cos[a + b*x]^11)/(11*b)}
{Sin[a + b*x]^3*Sin[2*a + 2*b*x]^3, x, 4, (8*Sin[a + b*x]^7)/(7*b) - (8*Sin[a + b*x]^9)/(9*b)}
{Sin[a + b*x]^3*Sin[2*a + 2*b*x]^2, x, 4, -((4*Cos[a + b*x]^3)/(3*b)) + (8*Cos[a + b*x]^5)/(5*b) - (4*Cos[a + b*x]^7)/(7*b)}
{Sin[a + b*x]^3*Sin[2*a + 2*b*x]^1, x, 2, (2*Sin[a + b*x]^5)/(5*b)}
{Sin[a + b*x]^3*Csc[2*a + 2*b*x]^1, x, 3, ArcTanh[Sin[a + b*x]]/(2*b) - Sin[a + b*x]/(2*b)}
{Sin[a + b*x]^3*Csc[2*a + 2*b*x]^2, x, 2, Sec[a + b*x]/(4*b)}
{Sin[a + b*x]^3*Csc[2*a + 2*b*x]^3, x, 3, ArcTanh[Sin[a + b*x]]/(16*b) + (Sec[a + b*x]*Tan[a + b*x])/(16*b)}
{Sin[a + b*x]^3*Csc[2*a + 2*b*x]^4, x, 4, -(ArcTanh[Cos[a + b*x]]/(16*b)) + Sec[a + b*x]/(16*b) + Sec[a + b*x]^3/(48*b)}
{Sin[a + b*x]^3*Csc[2*a + 2*b*x]^5, x, 5, (15*ArcTanh[Sin[a + b*x]])/(256*b) - (15*Csc[a + b*x])/(256*b) + (5*Csc[a + b*x]*Sec[a + b*x]^2)/(256*b) + (Csc[a + b*x]*Sec[a + b*x]^4)/(128*b)}


(* ::Subsection::Closed:: *)
(*Integrands of the form Sin[a+b x]^m Sin[2 a+2 b x]^(n/2)*)


{Sin[a + b*x]*Sin[2*a + 2*b*x]^(5/2), x, 4, -((5*ArcSin[Cos[a + b*x] - Sin[a + b*x]])/(32*b)) + (5*Log[Cos[a + b*x] + Sin[a + b*x] + Sqrt[Sin[2*a + 2*b*x]]])/(32*b) - (5*Cos[a + b*x]*Sqrt[Sin[2*a + 2*b*x]])/(16*b) + (5*Sin[a + b*x]*Sin[2*a + 2*b*x]^(3/2))/(24*b) - (Cos[a + b*x]*Sin[2*a + 2*b*x]^(5/2))/(6*b)}
{Sin[a + b*x]*Sin[2*a + 2*b*x]^(3/2), x, 3, -((3*ArcSin[Cos[a + b*x] - Sin[a + b*x]])/(16*b)) - (3*Log[Cos[a + b*x] + Sin[a + b*x] + Sqrt[Sin[2*a + 2*b*x]]])/(16*b) + (3*Sin[a + b*x]*Sqrt[Sin[2*a + 2*b*x]])/(8*b) - (Cos[a + b*x]*Sin[2*a + 2*b*x]^(3/2))/(4*b)}
{Sin[a + b*x]*Sin[2*a + 2*b*x]^(1/2), x, 2, -(ArcSin[Cos[a + b*x] - Sin[a + b*x]]/(4*b)) + Log[Cos[a + b*x] + Sin[a + b*x] + Sqrt[Sin[2*a + 2*b*x]]]/(4*b) - (Cos[a + b*x]*Sqrt[Sin[2*a + 2*b*x]])/(2*b)}
{Sin[a + b*x]/Sin[2*a + 2*b*x]^(1/2), x, 1, -(ArcSin[Cos[a + b*x] - Sin[a + b*x]]/(2*b)) - Log[Cos[a + b*x] + Sin[a + b*x] + Sqrt[Sin[2*a + 2*b*x]]]/(2*b)}
{Sin[a + b*x]/Sin[2*a + 2*b*x]^(3/2), x, 1, Sin[a + b*x]/(b*Sqrt[Sin[2*a + 2*b*x]])}
{Sin[a + b*x]/Sin[2*a + 2*b*x]^(5/2), x, 2, Sin[a + b*x]/(3*b*Sin[2*a + 2*b*x]^(3/2)) - (2*Cos[a + b*x])/(3*b*Sqrt[Sin[2*a + 2*b*x]])}
{Sin[a + b*x]/Sin[2*a + 2*b*x]^(7/2), x, 3, Sin[a + b*x]/(5*b*Sin[2*a + 2*b*x]^(5/2)) - (4*Cos[a + b*x])/(15*b*Sin[2*a + 2*b*x]^(3/2)) + (8*Sin[a + b*x])/(15*b*Sqrt[Sin[2*a + 2*b*x]])}
{Sin[a + b*x]/Sin[2*a + 2*b*x]^(9/2), x, 4, Sin[a + b*x]/(7*b*Sin[2*a + 2*b*x]^(7/2)) - (6*Cos[a + b*x])/(35*b*Sin[2*a + 2*b*x]^(5/2)) + (8*Sin[a + b*x])/(35*b*Sin[2*a + 2*b*x]^(3/2)) - (16*Cos[a + b*x])/(35*b*Sqrt[Sin[2*a + 2*b*x]])}


{Sin[a + b*x]^2*Sin[2*a + 2*b*x]^(7/2), x, 5, (5*EllipticF[(1/4)*(4*a - Pi) + b*x, 2])/(42*b) - (5*Cos[2*a + 2*b*x]*Sqrt[Sin[2*a + 2*b*x]])/(42*b) - (Cos[2*a + 2*b*x]*Sin[2*a + 2*b*x]^(5/2))/(14*b) - Sin[2*a + 2*b*x]^(9/2)/(18*b)}
{Sin[a + b*x]^2*Sin[2*a + 2*b*x]^(5/2), x, 4, (3*EllipticE[(1/4)*(4*a - Pi) + b*x, 2])/(10*b) - (Cos[2*a + 2*b*x]*Sin[2*a + 2*b*x]^(3/2))/(10*b) - Sin[2*a + 2*b*x]^(7/2)/(14*b)}
{Sin[a + b*x]^2*Sin[2*a + 2*b*x]^(3/2), x, 4, EllipticF[(1/4)*(4*a - Pi) + b*x, 2]/(6*b) - (Cos[2*a + 2*b*x]*Sqrt[Sin[2*a + 2*b*x]])/(6*b) - Sin[2*a + 2*b*x]^(5/2)/(10*b)}
{Sin[a + b*x]^2*Sin[2*a + 2*b*x]^(1/2), x, 3, EllipticE[(1/4)*(4*a - Pi) + b*x, 2]/(2*b) - Sin[2*a + 2*b*x]^(3/2)/(6*b)}
{Sin[a + b*x]^2/Sin[2*a + 2*b*x]^(1/2), x, 3, EllipticF[(1/4)*(4*a - Pi) + b*x, 2]/(2*b) - Sqrt[Sin[2*a + 2*b*x]]/(2*b)}
{Sin[a + b*x]^2/Sin[2*a + 2*b*x]^(3/2), x, 4, -(EllipticE[(1/4)*(4*a - Pi) + b*x, 2]/(2*b)) + 1/(2*b*Sqrt[Sin[2*a + 2*b*x]]) - Cos[2*a + 2*b*x]/(2*b*Sqrt[Sin[2*a + 2*b*x]])}
{Sin[a + b*x]^2/Sin[2*a + 2*b*x]^(5/2), x, 4, EllipticF[(1/4)*(4*a - Pi) + b*x, 2]/(6*b) + 1/(6*b*Sin[2*a + 2*b*x]^(3/2)) - Cos[2*a + 2*b*x]/(6*b*Sin[2*a + 2*b*x]^(3/2))}
{Sin[a + b*x]^2/Sin[2*a + 2*b*x]^(7/2), x, 5, -((3*EllipticE[(1/4)*(4*a - Pi) + b*x, 2])/(10*b)) + 1/(10*b*Sin[2*a + 2*b*x]^(5/2)) - Cos[2*a + 2*b*x]/(10*b*Sin[2*a + 2*b*x]^(5/2)) - (3*Cos[2*a + 2*b*x])/(10*b*Sqrt[Sin[2*a + 2*b*x]])}


(* {Sin[a + b*x]^3*Sin[2*a + 2*b*x]^(5/2), x, 5, 0}
{Sin[a + b*x]^3*Sin[2*a + 2*b*x]^(3/2), x, 5, 0}
{Sin[a + b*x]^3*Sin[2*a + 2*b*x]^(1/2), x, 4, 0}
{Sin[a + b*x]^3/Sin[2*a + 2*b*x]^(1/2), x, 4, 0}
{Sin[a + b*x]^3/Sin[2*a + 2*b*x]^(3/2), x, 5, 0}
{Sin[a + b*x]^3/Sin[2*a + 2*b*x]^(5/2), x, 5, 0}
{Sin[a + b*x]^3/Sin[2*a + 2*b*x]^(7/2), x, 6, 0}
{Sin[a + b*x]^3/Sin[2*a + 2*b*x]^(9/2), x, 6, 0} *)


(* ::Subsection::Closed:: *)
(*Integrands of the form Cos[a+b x]^m Sin[2 a+2 b x]^n*)


{Cos[a + b*x]*Sin[2*a + 2*b*x]^5, x, 4, -((32*Cos[a + b*x]^7)/(7*b)) + (64*Cos[a + b*x]^9)/(9*b) - (32*Cos[a + b*x]^11)/(11*b)}
{Cos[a + b*x]*Sin[2*a + 2*b*x]^4, x, 4, (16*Sin[a + b*x]^5)/(5*b) - (32*Sin[a + b*x]^7)/(7*b) + (16*Sin[a + b*x]^9)/(9*b)}
{Cos[a + b*x]*Sin[2*a + 2*b*x]^3, x, 4, -((8*Cos[a + b*x]^5)/(5*b)) + (8*Cos[a + b*x]^7)/(7*b)}
{Cos[a + b*x]*Sin[2*a + 2*b*x]^2, x, 4, (4*Sin[a + b*x]^3)/(3*b) - (4*Sin[a + b*x]^5)/(5*b)}
{Cos[a + b*x]*Sin[2*a + 2*b*x]^1, x, 2, -((2*Cos[a + b*x]^3)/(3*b))}
{Cos[a + b*x]/Sin[2*a + 2*b*x]^1, x, 2, -(ArcTanh[Cos[a + b*x]]/(2*b))}
{Cos[a + b*x]/Sin[2*a + 2*b*x]^2, x, 3, ArcTanh[Sin[a + b*x]]/(4*b) - Csc[a + b*x]/(4*b)}
{Cos[a + b*x]/Sin[2*a + 2*b*x]^3, x, 4, -((3*ArcTanh[Cos[a + b*x]])/(16*b)) + (3*Sec[a + b*x])/(16*b) - (Csc[a + b*x]^2*Sec[a + b*x])/(16*b)}
{Cos[a + b*x]/Sin[2*a + 2*b*x]^4, x, 5, (5*ArcTanh[Sin[a + b*x]])/(32*b) - (5*Csc[a + b*x])/(32*b) - (5*Csc[a + b*x]^3)/(96*b) + (Csc[a + b*x]^3*Sec[a + b*x]^2)/(32*b)}
{Cos[a + b*x]/Sin[2*a + 2*b*x]^5, x, 6, -((35*ArcTanh[Cos[a + b*x]])/(256*b)) + (35*Sec[a + b*x])/(256*b) + (35*Sec[a + b*x]^3)/(768*b) - (7*Csc[a + b*x]^2*Sec[a + b*x]^3)/(256*b) - (Csc[a + b*x]^4*Sec[a + b*x]^3)/(128*b)}


{Cos[a + b*x]^2*Sin[2*a + 2*b*x]^5, x, 5, -((4*Cos[a + b*x]^8)/b) + (32*Cos[a + b*x]^10)/(5*b) - (8*Cos[a + b*x]^12)/(3*b)}
{Cos[a + b*x]^2*Sin[2*a + 2*b*x]^4, x, 4, (3*x)/16 - (3*Cos[2*a + 2*b*x]*Sin[2*a + 2*b*x])/(32*b) - (Cos[2*a + 2*b*x]*Sin[2*a + 2*b*x]^3)/(16*b) + Sin[2*a + 2*b*x]^5/(20*b)}
{Cos[a + b*x]^2*Sin[2*a + 2*b*x]^3, x, 4, -((4*Cos[a + b*x]^6)/(3*b)) + Cos[a + b*x]^8/b}
{Cos[a + b*x]^2*Sin[2*a + 2*b*x]^2, x, 3, x/4 - (Cos[2*a + 2*b*x]*Sin[2*a + 2*b*x])/(8*b) + Sin[2*a + 2*b*x]^3/(12*b)}
{Cos[a + b*x]^2*Sin[2*a + 2*b*x]^1, x, 2, -(Cos[a + b*x]^4/(2*b))}
{Cos[a + b*x]^2/Sin[2*a + 2*b*x]^1, x, 2, Log[Sin[a + b*x]]/(2*b)}
{Cos[a + b*x]^2/Sin[2*a + 2*b*x]^2, x, 2, -(Cot[a + b*x]/(4*b))}
{Cos[a + b*x]^2/Sin[2*a + 2*b*x]^3, x, 4, -(Cot[a + b*x]^2/(16*b)) + Log[Tan[a + b*x]]/(8*b)}
{Cos[a + b*x]^2/Sin[2*a + 2*b*x]^4, x, 4, -(Cot[a + b*x]/(8*b)) - Cot[a + b*x]^3/(48*b) + Tan[a + b*x]/(16*b)}
{Cos[a + b*x]^2/Sin[2*a + 2*b*x]^5, x, 4, -((3*Cot[a + b*x]^2)/(64*b)) - Cot[a + b*x]^4/(128*b) + (3*Log[Tan[a + b*x]])/(32*b) + Tan[a + b*x]^2/(64*b)}


{Cos[a + b*x]^3*Sin[2*a + 2*b*x]^5, x, 4, -((32*Cos[a + b*x]^9)/(9*b)) + (64*Cos[a + b*x]^11)/(11*b) - (32*Cos[a + b*x]^13)/(13*b)}
{Cos[a + b*x]^3*Sin[2*a + 2*b*x]^4, x, 4, (16*Sin[a + b*x]^5)/(5*b) - (48*Sin[a + b*x]^7)/(7*b) + (16*Sin[a + b*x]^9)/(3*b) - (16*Sin[a + b*x]^11)/(11*b)}
{Cos[a + b*x]^3*Sin[2*a + 2*b*x]^3, x, 4, -((8*Cos[a + b*x]^7)/(7*b)) + (8*Cos[a + b*x]^9)/(9*b)}
{Cos[a + b*x]^3*Sin[2*a + 2*b*x]^2, x, 4, (4*Sin[a + b*x]^3)/(3*b) - (8*Sin[a + b*x]^5)/(5*b) + (4*Sin[a + b*x]^7)/(7*b)}
{Cos[a + b*x]^3*Sin[2*a + 2*b*x]^1, x, 2, -((2*Cos[a + b*x]^5)/(5*b))}
{Cos[a + b*x]^3/Sin[2*a + 2*b*x]^1, x, 3, -(ArcTanh[Cos[a + b*x]]/(2*b)) + Cos[a + b*x]/(2*b)}
{Cos[a + b*x]^3/Sin[2*a + 2*b*x]^2, x, 2, -(Csc[a + b*x]/(4*b))}
{Cos[a + b*x]^3/Sin[2*a + 2*b*x]^3, x, 3, -(ArcTanh[Cos[a + b*x]]/(16*b)) - (Cot[a + b*x]*Csc[a + b*x])/(16*b)}
{Cos[a + b*x]^3/Sin[2*a + 2*b*x]^4, x, 4, ArcTanh[Sin[a + b*x]]/(16*b) - Csc[a + b*x]/(16*b) - Csc[a + b*x]^3/(48*b)}
{Cos[a + b*x]^3/Sin[2*a + 2*b*x]^5, x, 5, -((15*ArcTanh[Cos[a + b*x]])/(256*b)) + (15*Sec[a + b*x])/(256*b) - (5*Csc[a + b*x]^2*Sec[a + b*x])/(256*b) - (Csc[a + b*x]^4*Sec[a + b*x])/(128*b)}


(* ::Subsection::Closed:: *)
(*Integrands of the form Cos[a+b x]^m Sin[2 a+2 b x]^(n/2)*)


{Cos[a + b*x]*Sin[2*a + 2*b*x]^(5/2), x, 4, -((5*ArcSin[Cos[a + b*x] - Sin[a + b*x]])/(32*b)) - (5*Log[Cos[a + b*x] + Sin[a + b*x] + Sqrt[Sin[2*a + 2*b*x]]])/(32*b) + (5*Sin[a + b*x]*Sqrt[Sin[2*a + 2*b*x]])/(16*b) - (5*Cos[a + b*x]*Sin[2*a + 2*b*x]^(3/2))/(24*b) + (Sin[a + b*x]*Sin[2*a + 2*b*x]^(5/2))/(6*b)}
{Cos[a + b*x]*Sin[2*a + 2*b*x]^(3/2), x, 3, -((3*ArcSin[Cos[a + b*x] - Sin[a + b*x]])/(16*b)) + (3*Log[Cos[a + b*x] + Sin[a + b*x] + Sqrt[Sin[2*a + 2*b*x]]])/(16*b) - (3*Cos[a + b*x]*Sqrt[Sin[2*a + 2*b*x]])/(8*b) + (Sin[a + b*x]*Sin[2*a + 2*b*x]^(3/2))/(4*b)}
{Cos[a + b*x]*Sin[2*a + 2*b*x]^(1/2), x, 2, -(ArcSin[Cos[a + b*x] - Sin[a + b*x]]/(4*b)) - Log[Cos[a + b*x] + Sin[a + b*x] + Sqrt[Sin[2*a + 2*b*x]]]/(4*b) + (Sin[a + b*x]*Sqrt[Sin[2*a + 2*b*x]])/(2*b)}
{Cos[a + b*x]/Sin[2*a + 2*b*x]^(1/2), x, 1, -(ArcSin[Cos[a + b*x] - Sin[a + b*x]]/(2*b)) + Log[Cos[a + b*x] + Sin[a + b*x] + Sqrt[Sin[2*a + 2*b*x]]]/(2*b)}
{Cos[a + b*x]/Sin[2*a + 2*b*x]^(3/2), x, 1, -(Cos[a + b*x]/(b*Sqrt[Sin[2*a + 2*b*x]]))}
{Cos[a + b*x]/Sin[2*a + 2*b*x]^(5/2), x, 2, -(Cos[a + b*x]/(3*b*Sin[2*a + 2*b*x]^(3/2))) + (2*Sin[a + b*x])/(3*b*Sqrt[Sin[2*a + 2*b*x]])}
{Cos[a + b*x]/Sin[2*a + 2*b*x]^(7/2), x, 3, -(Cos[a + b*x]/(5*b*Sin[2*a + 2*b*x]^(5/2))) + (4*Sin[a + b*x])/(15*b*Sin[2*a + 2*b*x]^(3/2)) - (8*Cos[a + b*x])/(15*b*Sqrt[Sin[2*a + 2*b*x]])}
{Cos[a + b*x]/Sin[2*a + 2*b*x]^(9/2), x, 4, -(Cos[a + b*x]/(7*b*Sin[2*a + 2*b*x]^(7/2))) + (6*Sin[a + b*x])/(35*b*Sin[2*a + 2*b*x]^(5/2)) - (8*Cos[a + b*x])/(35*b*Sin[2*a + 2*b*x]^(3/2)) + (16*Sin[a + b*x])/(35*b*Sqrt[Sin[2*a + 2*b*x]])}


{Cos[a + b*x]^2*Sin[2*a + 2*b*x]^(7/2), x, 5, (5*EllipticF[(1/4)*(4*a - Pi) + b*x, 2])/(42*b) - (5*Cos[2*a + 2*b*x]*Sqrt[Sin[2*a + 2*b*x]])/(42*b) - (Cos[2*a + 2*b*x]*Sin[2*a + 2*b*x]^(5/2))/(14*b) + Sin[2*a + 2*b*x]^(9/2)/(18*b)}
{Cos[a + b*x]^2*Sin[2*a + 2*b*x]^(5/2), x, 4, (3*EllipticE[(1/4)*(4*a - Pi) + b*x, 2])/(10*b) - (Cos[2*a + 2*b*x]*Sin[2*a + 2*b*x]^(3/2))/(10*b) + Sin[2*a + 2*b*x]^(7/2)/(14*b)}
{Cos[a + b*x]^2*Sin[2*a + 2*b*x]^(3/2), x, 4, EllipticF[(1/4)*(4*a - Pi) + b*x, 2]/(6*b) - (Cos[2*a + 2*b*x]*Sqrt[Sin[2*a + 2*b*x]])/(6*b) + Sin[2*a + 2*b*x]^(5/2)/(10*b)}
{Cos[a + b*x]^2*Sin[2*a + 2*b*x]^(1/2), x, 3, EllipticE[(1/4)*(4*a - Pi) + b*x, 2]/(2*b) + Sin[2*a + 2*b*x]^(3/2)/(6*b)}
{Cos[a + b*x]^2/Sin[2*a + 2*b*x]^(1/2), x, 3, EllipticF[(1/4)*(4*a - Pi) + b*x, 2]/(2*b) + Sqrt[Sin[2*a + 2*b*x]]/(2*b)}
{Cos[a + b*x]^2/Sin[2*a + 2*b*x]^(3/2), x, 4, -(EllipticE[(1/4)*(4*a - Pi) + b*x, 2]/(2*b)) - 1/(2*b*Sqrt[Sin[2*a + 2*b*x]]) - Cos[2*a + 2*b*x]/(2*b*Sqrt[Sin[2*a + 2*b*x]])}
{Cos[a + b*x]^2/Sin[2*a + 2*b*x]^(5/2), x, 4, EllipticF[(1/4)*(4*a - Pi) + b*x, 2]/(6*b) - 1/(6*b*Sin[2*a + 2*b*x]^(3/2)) - Cos[2*a + 2*b*x]/(6*b*Sin[2*a + 2*b*x]^(3/2))}
{Cos[a + b*x]^2/Sin[2*a + 2*b*x]^(7/2), x, 5, -((3*EllipticE[(1/4)*(4*a - Pi) + b*x, 2])/(10*b)) - 1/(10*b*Sin[2*a + 2*b*x]^(5/2)) - Cos[2*a + 2*b*x]/(10*b*Sin[2*a + 2*b*x]^(5/2)) - (3*Cos[2*a + 2*b*x])/(10*b*Sqrt[Sin[2*a + 2*b*x]])}


(* ::Section::Closed:: *)
(*Integrands of the form x^m Trig[a+b x]^n Trig[a+ b x]^p*)


(* ::Subsection::Closed:: *)
(*Integrands of the form x^m Trig[a+b x]^n Trig[a+ b x]^p*)


(* ::Subsubsection::Closed:: *)
(*Integrands of the form x^m Cos[a+b x]^n Sin[a+b x]^p*)


{Sin[x]*Cos[x]/x, x, 3, (1/2)*SinIntegral[2*x]}
{Sin[x]*Cos[x]/x^2, x, 4, CosIntegral[2*x] - Sin[2*x]/(2*x)}
{Sin[x]*Cos[x]/x^3, x, 5, -(Cos[2*x]/(2*x)) - Sin[2*x]/(4*x^2) - SinIntegral[2*x]}


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

{x^3*Sin[a + b*x]^2*Cos[a + b*x]^2, x, 6, x^4/32 + (3*Cos[4*a + 4*b*x])/(1024*b^4) - (3*x^2*Cos[4*a + 4*b*x])/(128*b^2) + (3*x*Sin[4*a + 4*b*x])/(256*b^3) - (x^3*Sin[4*a + 4*b*x])/(32*b)}
{x^2*Sin[a + b*x]^2*Cos[a + b*x]^2, x, 5, x^3/24 - (x*Cos[4*a + 4*b*x])/(64*b^2) + Sin[4*a + 4*b*x]/(256*b^3) - (x^2*Sin[4*a + 4*b*x])/(32*b)}
{x*Sin[a + b*x]^2*Cos[a + b*x]^2, x, 4, x^2/16 - Cos[4*a + 4*b*x]/(128*b^2) - (x*Sin[4*a + 4*b*x])/(32*b)}
{Sin[a + b*x]^2*Cos[a + b*x]^2/x, x, 5, (-(1/8))*Cos[4*a]*CosIntegral[4*b*x] + Log[x]/8 + (1/8)*Sin[4*a]*SinIntegral[4*b*x]}
{Sin[a + b*x]^2*Cos[a + b*x]^2/x^2, x, 6, -(1/(8*x)) + Cos[4*a + 4*b*x]/(8*x) + (1/2)*b*CosIntegral[4*b*x]*Sin[4*a] + (1/2)*b*Cos[4*a]*SinIntegral[4*b*x]}
{Sin[a + b*x]^2*Cos[a + b*x]^2/x^3, x, 7, -(1/(16*x^2)) + Cos[4*a + 4*b*x]/(16*x^2) + b^2*Cos[4*a]*CosIntegral[4*b*x] - (b*Sin[4*a + 4*b*x])/(4*x) - b^2*Sin[4*a]*SinIntegral[4*b*x]}

{x^3*Sin[a + b*x]^3*Cos[a + b*x]^3, x, 10, (9*x*Cos[2*a + 2*b*x])/(128*b^3) - (3*x^3*Cos[2*a + 2*b*x])/(64*b) - (x*Cos[6*a + 6*b*x])/(1152*b^3) + (x^3*Cos[6*a + 6*b*x])/(192*b) - (9*Sin[2*a + 2*b*x])/(256*b^4) + (9*x^2*Sin[2*a + 2*b*x])/(128*b^2) + Sin[6*a + 6*b*x]/(6912*b^4) - (x^2*Sin[6*a + 6*b*x])/(384*b^2)}
{x^2*Sin[a + b*x]^3*Cos[a + b*x]^3, x, 8, (3*Cos[2*a + 2*b*x])/(128*b^3) - (3*x^2*Cos[2*a + 2*b*x])/(64*b) - Cos[6*a + 6*b*x]/(3456*b^3) + (x^2*Cos[6*a + 6*b*x])/(192*b) + (3*x*Sin[2*a + 2*b*x])/(64*b^2) - (x*Sin[6*a + 6*b*x])/(576*b^2)}
{x*Sin[a + b*x]^3*Cos[a + b*x]^3, x, 6, -((3*x*Cos[2*a + 2*b*x])/(64*b)) + (x*Cos[6*a + 6*b*x])/(192*b) + (3*Sin[2*a + 2*b*x])/(128*b^2) - Sin[6*a + 6*b*x]/(1152*b^2)}
{Sin[a + b*x]^3*Cos[a + b*x]^3/x, x, 8, (3/32)*CosIntegral[2*b*x]*Sin[2*a] - (1/32)*CosIntegral[6*b*x]*Sin[6*a] + (3/32)*Cos[2*a]*SinIntegral[2*b*x] - (1/32)*Cos[6*a]*SinIntegral[6*b*x]}
{Sin[a + b*x]^3*Cos[a + b*x]^3/x^2, x, 10, (3/16)*b*Cos[2*a]*CosIntegral[2*b*x] - (3/16)*b*Cos[6*a]*CosIntegral[6*b*x] - (3*Sin[2*a + 2*b*x])/(32*x) + Sin[6*a + 6*b*x]/(32*x) - (3/16)*b*Sin[2*a]*SinIntegral[2*b*x] + (3/16)*b*Sin[6*a]*SinIntegral[6*b*x]}
{Sin[a + b*x]^3*Cos[a + b*x]^3/x^3, x, 12, -((3*b*Cos[2*a + 2*b*x])/(32*x)) + (3*b*Cos[6*a + 6*b*x])/(32*x) - (3/16)*b^2*CosIntegral[2*b*x]*Sin[2*a] + (9/16)*b^2*CosIntegral[6*b*x]*Sin[6*a] - (3*Sin[2*a + 2*b*x])/(64*x^2) + Sin[6*a + 6*b*x]/(64*x^2) - (3/16)*b^2*Cos[2*a]*SinIntegral[2*b*x] + (9/16)*b^2*Cos[6*a]*SinIntegral[6*b*x]}


{x*Sin[a + b*x]*Cos[a + b*x]^(3/2), x, 3, -((2*x*Cos[a + b*x]^(5/2))/(5*b)) + (12*EllipticE[(1/2)*(a + b*x), 2])/(25*b^2) + (4*Cos[a + b*x]^(3/2)*Sin[a + b*x])/(25*b^2)}
{x*Sin[a + b*x]*Sqrt[Cos[a + b*x]], x, 3, -((2*x*Cos[a + b*x]^(3/2))/(3*b)) + (4*EllipticF[(1/2)*(a + b*x), 2])/(9*b^2) + (4*Sqrt[Cos[a + b*x]]*Sin[a + b*x])/(9*b^2)}
{x*Sin[a + b*x]/Sqrt[Cos[a + b*x]], x, 2, -((2*x*Sqrt[Cos[a + b*x]])/b) + (4*EllipticE[(1/2)*(a + b*x), 2])/b^2}
{x*Sin[a + b*x]/Cos[a + b*x]^(3/2), x, 2, (2*x)/(b*Sqrt[Cos[a + b*x]]) - (4*EllipticF[(1/2)*(a + b*x), 2])/b^2}
{x*Sin[a + b*x]/Cos[a + b*x]^(5/2), x, 3, (2*x)/(3*b*Cos[a + b*x]^(3/2)) + (4*EllipticE[(1/2)*(a + b*x), 2])/(3*b^2) - (4*Sin[a + b*x])/(3*b^2*Sqrt[Cos[a + b*x]])}


{x*Cos[a + b*x]*Sin[a + b*x]^(3/2), x, 3, (12*EllipticE[Pi/4 + (1/2)*(-a - b*x), 2])/(25*b^2) + (4*Cos[a + b*x]*Sin[a + b*x]^(3/2))/(25*b^2) + (2*x*Sin[a + b*x]^(5/2))/(5*b)}
{x*Cos[a + b*x]*Sqrt[Sin[a + b*x]], x, 3, (4*EllipticF[Pi/4 + (1/2)*(-a - b*x), 2])/(9*b^2) + (4*Cos[a + b*x]*Sqrt[Sin[a + b*x]])/(9*b^2) + (2*x*Sin[a + b*x]^(3/2))/(3*b)}
{x*Cos[a + b*x]/Sqrt[Sin[a + b*x]], x, 2, (4*EllipticE[Pi/4 + (1/2)*(-a - b*x), 2])/b^2 + (2*x*Sqrt[Sin[a + b*x]])/b}
{x*Cos[a + b*x]/Sin[a + b*x]^(3/2), x, 2, -((4*EllipticF[Pi/4 + (1/2)*(-a - b*x), 2])/b^2) - (2*x)/(b*Sqrt[Sin[a + b*x]])}
{x*Cos[a + b*x]/Sin[a + b*x]^(5/2), x, 3, (4*EllipticE[Pi/4 + (1/2)*(-a - b*x), 2])/(3*b^2) - (2*x)/(3*b*Sin[a + b*x]^(3/2)) - (4*Cos[a + b*x])/(3*b^2*Sqrt[Sin[a + b*x]])}


{x*Sin[a + b*x]*Sec[a + b*x]^(5/2), x, 4, (4*Sqrt[Cos[a + b*x]]*EllipticE[(1/2)*(a + b*x), 2]*Sqrt[Sec[a + b*x]])/(3*b^2) + (2*x*Sec[a + b*x]^(3/2))/(3*b) - (4*Sqrt[Sec[a + b*x]]*Sin[a + b*x])/(3*b^2)}
{x*Sin[a + b*x]*Sec[a + b*x]^(3/2), x, 3, (2*x*Sqrt[Sec[a + b*x]])/b - (4*Sqrt[Cos[a + b*x]]*EllipticF[(1/2)*(a + b*x), 2]*Sqrt[Sec[a + b*x]])/b^2}
{x*Sin[a + b*x]*Sqrt[Sec[a + b*x]], x, 3, -((2*x)/(b*Sqrt[Sec[a + b*x]])) + (4*Sqrt[Cos[a + b*x]]*EllipticE[(1/2)*(a + b*x), 2]*Sqrt[Sec[a + b*x]])/b^2}
{x*Sin[a + b*x]/Sqrt[Sec[a + b*x]], x, 4, -((2*x)/(3*b*Sec[a + b*x]^(3/2))) + (4*Sqrt[Cos[a + b*x]]*EllipticF[(1/2)*(a + b*x), 2]*Sqrt[Sec[a + b*x]])/(9*b^2) + (4*Sin[a + b*x])/(9*b^2*Sqrt[Sec[a + b*x]])}
{x*Sin[a + b*x]/Sec[a + b*x]^(3/2), x, 4, -((2*x)/(5*b*Sec[a + b*x]^(5/2))) + (12*Sqrt[Cos[a + b*x]]*EllipticE[(1/2)*(a + b*x), 2]*Sqrt[Sec[a + b*x]])/(25*b^2) + (4*Sin[a + b*x])/(25*b^2*Sec[a + b*x]^(3/2))}


{x*Cos[a + b*x]*Csc[a + b*x]^(5/2), x, 4, -((4*Cos[a + b*x]*Sqrt[Csc[a + b*x]])/(3*b^2)) - (2*x*Csc[a + b*x]^(3/2))/(3*b) + (4*Sqrt[Csc[a + b*x]]*EllipticE[Pi/4 + (1/2)*(-a - b*x), 2]*Sqrt[Sin[a + b*x]])/(3*b^2)}
{x*Cos[a + b*x]*Csc[a + b*x]^(3/2), x, 3, -((2*x*Sqrt[Csc[a + b*x]])/b) - (4*Sqrt[Csc[a + b*x]]*EllipticF[Pi/4 + (1/2)*(-a - b*x), 2]*Sqrt[Sin[a + b*x]])/b^2}
{x*Cos[a + b*x]*Sqrt[Csc[a + b*x]], x, 3, (2*x)/(b*Sqrt[Csc[a + b*x]]) + (4*Sqrt[Csc[a + b*x]]*EllipticE[Pi/4 + (1/2)*(-a - b*x), 2]*Sqrt[Sin[a + b*x]])/b^2}
{x*Cos[a + b*x]/Sqrt[Csc[a + b*x]], x, 4, (2*x)/(3*b*Csc[a + b*x]^(3/2)) + (4*Cos[a + b*x])/(9*b^2*Sqrt[Csc[a + b*x]]) + (4*Sqrt[Csc[a + b*x]]*EllipticF[Pi/4 + (1/2)*(-a - b*x), 2]*Sqrt[Sin[a + b*x]])/(9*b^2)}
{x*Cos[a + b*x]/Csc[a + b*x]^(3/2), x, 4, (2*x)/(5*b*Csc[a + b*x]^(5/2)) + (4*Cos[a + b*x])/(25*b^2*Csc[a + b*x]^(3/2)) + (12*Sqrt[Csc[a + b*x]]*EllipticE[Pi/4 + (1/2)*(-a - b*x), 2]*Sqrt[Sin[a + b*x]])/(25*b^2)}


(* ::Subsubsection::Closed:: *)
(*Integrands of the form x^m Trig[a+b x]^n Tan[a+b x]^p*)


{x*Sec[a + b*x]*Tan[a + b*x], x, 2, -(ArcTanh[Sin[a + b*x]]/b^2) + (x*Sec[a + b*x])/b}
{x^2*Sec[a + b*x]*Tan[a + b*x], x, 4, (4*I*x*ArcTan[E^(I*a + I*b*x)])/b^2 - (2*I*PolyLog[2, (-I)*E^(I*(a + b*x))])/b^3 + (2*I*PolyLog[2, I*E^(I*(a + b*x))])/b^3 + (x^2*Sec[a + b*x])/b}
{x^3*Sec[a + b*x]*Tan[a + b*x], x, 6, (6*I*x^2*ArcTan[E^(I*a + I*b*x)])/b^2 - (6*I*x*PolyLog[2, (-I)*E^(I*(a + b*x))])/b^3 + (6*I*x*PolyLog[2, I*E^(I*(a + b*x))])/b^3 + (6*PolyLog[3, (-I)*E^(I*(a + b*x))])/b^4 - (6*PolyLog[3, I*E^(I*(a + b*x))])/b^4 + (x^3*Sec[a + b*x])/b}
{Sec[a + b*x]*Tan[a + b*x]/x, x, 0, Int[(Sec[a + b*x]*Tan[a + b*x])/x, x]}

{x*Sec[a + b*x]^2*Tan[a + b*x], x, 2, (x*Sec[a + b*x]^2)/(2*b) - Tan[a + b*x]/(2*b^2)}
{x^2*Sec[a + b*x]^2*Tan[a + b*x], x, 3, -(Log[Cos[a + b*x]]/b^3) + (x^2*Sec[a + b*x]^2)/(2*b) - (x*Tan[a + b*x])/b^2}
{x^3*Sec[a + b*x]^2*Tan[a + b*x], x, 6, (3*I*x^2)/(2*b^2) - (3*x*Log[1 + E^(2*I*a + 2*I*b*x)])/b^3 + (3*I*PolyLog[2, -E^(2*I*a + 2*I*b*x)])/(2*b^4) + (x^3*Sec[a + b*x]^2)/(2*b) - (3*x^2*Tan[a + b*x])/(2*b^2)}
{Sec[a + b*x]^2*Tan[a + b*x]/x, x, 0, Int[(Sec[a + b*x]^2*Tan[a + b*x])/x, x]}


(* ::Subsubsection::Closed:: *)
(*Integrands of the form x^m Trig[a+b x]^n Cot[a+b x]^p*)


{x*Csc[a + b*x]*Cot[a + b*x], x, 2, -(ArcTanh[Cos[a + b*x]]/b^2) - (x*Csc[a + b*x])/b}
{x^2*Csc[a + b*x]*Cot[a + b*x], x, 4, -((4*x*ArcTanh[E^(I*a + I*b*x)])/b^2) - (x^2*Csc[a + b*x])/b + (2*I*PolyLog[2, -E^(I*(a + b*x))])/b^3 - (2*I*PolyLog[2, E^(I*(a + b*x))])/b^3}
{x^3*Csc[a + b*x]*Cot[a + b*x], x, 6, -((6*x^2*ArcTanh[E^(I*a + I*b*x)])/b^2) - (x^3*Csc[a + b*x])/b + (6*I*x*PolyLog[2, -E^(I*(a + b*x))])/b^3 - (6*I*x*PolyLog[2, E^(I*(a + b*x))])/b^3 - (6*PolyLog[3, -E^(I*(a + b*x))])/b^4 + (6*PolyLog[3, E^(I*(a + b*x))])/b^4}
{Csc[a + b*x]*Cot[a + b*x]/x, x, 0, Int[(Cot[a + b*x]*Csc[a + b*x])/x, x]}

{x*Csc[a + b*x]^2*Cot[a + b*x], x, 2, -(Cot[a + b*x]/(2*b^2)) - (x*Csc[a + b*x]^2)/(2*b)}
{x^2*Csc[a + b*x]^2*Cot[a + b*x], x, 3, -((x*Cot[a + b*x])/b^2) - (x^2*Csc[a + b*x]^2)/(2*b) + Log[Sin[a + b*x]]/b^3}
{x^3*Csc[a + b*x]^2*Cot[a + b*x], x, 6, -((3*I*x^2)/(2*b^2)) - (3*x^2*Cot[a + b*x])/(2*b^2) - (x^3*Csc[a + b*x]^2)/(2*b) + (3*x*Log[1 - E^(2*I*a + 2*I*b*x)])/b^3 - (3*I*PolyLog[2, E^(2*I*a + 2*I*b*x)])/(2*b^4)}
{Csc[a + b*x]^2*Cot[a + b*x]/x, x, 0, Int[(Cot[a + b*x]*Csc[a + b*x]^2)/x, x]}


(* ::Subsubsection::Closed:: *)
(*Integrands of the form x^m Csc[a+b x]^n Sec[a+b x]^p*)


{x^3*Csc[a + b*x]*Sec[a + b*x], x, 8, -((2*x^3*ArcTanh[E^(2*I*a + 2*I*b*x)])/b) + (3*I*x^2*PolyLog[2, -E^(2*I*(a + b*x))])/(2*b^2) - (3*I*x^2*PolyLog[2, E^(2*I*(a + b*x))])/(2*b^2) - (3*x*PolyLog[3, -E^(2*I*(a + b*x))])/(2*b^3) + (3*x*PolyLog[3, E^(2*I*(a + b*x))])/(2*b^3) - (3*I*PolyLog[4, -E^(2*I*(a + b*x))])/(4*b^4) + (3*I*PolyLog[4, E^(2*I*(a + b*x))])/(4*b^4)}
{x^2*Csc[a + b*x]*Sec[a + b*x], x, 6, -((2*x^2*ArcTanh[E^(2*I*a + 2*I*b*x)])/b) + (I*x*PolyLog[2, -E^(2*I*(a + b*x))])/b^2 - (I*x*PolyLog[2, E^(2*I*(a + b*x))])/b^2 - PolyLog[3, -E^(2*I*(a + b*x))]/(2*b^3) + PolyLog[3, E^(2*I*(a + b*x))]/(2*b^3)}
{x^1*Csc[a + b*x]*Sec[a + b*x], x, 4, -((2*x*ArcTanh[E^(2*I*a + 2*I*b*x)])/b) + (I*PolyLog[2, -E^(2*I*(a + b*x))])/(2*b^2) - (I*PolyLog[2, E^(2*I*(a + b*x))])/(2*b^2)}
{x^0*Csc[a + b*x]*Sec[a + b*x], x, 2, Log[Tan[a + b*x]]/b}
{Csc[a + b*x]*Sec[a + b*x]/x^1, x, 1, 2*Int[Csc[2*a + 2*b*x]/x, x]}

{x^3*Csc[a + b*x]*Sec[a + b*x]^2, x, 19, (6*I*x^2*ArcTan[E^(I*a + I*b*x)])/b^2 - (2*x^3*ArcTanh[E^(I*a + I*b*x)])/b + (x^3*ArcTanh[Cos[a + b*x]])/b + (3*I*x^2*PolyLog[2, -E^(I*(a + b*x))])/b^2 - (6*I*x*PolyLog[2, (-I)*E^(I*(a + b*x))])/b^3 + (6*I*x*PolyLog[2, I*E^(I*(a + b*x))])/b^3 - (3*I*x^2*PolyLog[2, E^(I*(a + b*x))])/b^2 - (6*x*PolyLog[3, -E^(I*(a + b*x))])/b^3 + (6*PolyLog[3, (-I)*E^(I*(a + b*x))])/b^4 - (6*PolyLog[3, I*E^(I*(a + b*x))])/b^4 + (6*x*PolyLog[3, E^(I*(a + b*x))])/b^3 - (6*I*PolyLog[4, -E^(I*(a + b*x))])/b^4 + (6*I*PolyLog[4, E^(I*(a + b*x))])/b^4 - x^3*(ArcTanh[Cos[a + b*x]]/b - Sec[a + b*x]/b)}
{x^2*Csc[a + b*x]*Sec[a + b*x]^2, x, 15, (4*I*x*ArcTan[E^(I*a + I*b*x)])/b^2 - (2*x^2*ArcTanh[E^(I*a + I*b*x)])/b + (x^2*ArcTanh[Cos[a + b*x]])/b + (2*I*x*PolyLog[2, -E^(I*(a + b*x))])/b^2 - (2*I*PolyLog[2, (-I)*E^(I*(a + b*x))])/b^3 + (2*I*PolyLog[2, I*E^(I*(a + b*x))])/b^3 - (2*I*x*PolyLog[2, E^(I*(a + b*x))])/b^2 - (2*PolyLog[3, -E^(I*(a + b*x))])/b^3 + (2*PolyLog[3, E^(I*(a + b*x))])/b^3 - x^2*(ArcTanh[Cos[a + b*x]]/b - Sec[a + b*x]/b)}
{x^1*Csc[a + b*x]*Sec[a + b*x]^2, x, 8, -((2*x*ArcTanh[E^(I*a + I*b*x)])/b) + (x*ArcTanh[Cos[a + b*x]])/b - ArcTanh[Sin[a + b*x]]/b^2 + (I*PolyLog[2, -E^(I*(a + b*x))])/b^2 - (I*PolyLog[2, E^(I*(a + b*x))])/b^2 - x*(ArcTanh[Cos[a + b*x]]/b - Sec[a + b*x]/b)}
{x^0*Csc[a + b*x]*Sec[a + b*x]^2, x, 2, -(ArcTanh[Cos[a + b*x]]/b) + Sec[a + b*x]/b}
{Csc[a + b*x]*Sec[a + b*x]^2/x^1, x, 0, Int[(Csc[a + b*x]*Sec[a + b*x]^2)/x, x]}

{x^3*Csc[a + b*x]*Sec[a + b*x]^3, x, 20, (3*I*x^2)/(2*b^2) + x^3/(2*b) - (2*x^3*ArcTanh[E^(2*I*a + 2*I*b*x)])/b - (3*x*Log[1 + E^(2*I*a + 2*I*b*x)])/b^3 - (x^3*Log[Tan[a + b*x]])/b + (3*I*PolyLog[2, -E^(2*I*a + 2*I*b*x)])/(2*b^4) + (3*I*x^2*PolyLog[2, -E^(2*I*(a + b*x))])/(2*b^2) - (3*I*x^2*PolyLog[2, E^(2*I*(a + b*x))])/(2*b^2) - (3*x*PolyLog[3, -E^(2*I*(a + b*x))])/(2*b^3) + (3*x*PolyLog[3, E^(2*I*(a + b*x))])/(2*b^3) - (3*I*PolyLog[4, -E^(2*I*(a + b*x))])/(4*b^4) + (3*I*PolyLog[4, E^(2*I*(a + b*x))])/(4*b^4) - (3*x^2*Tan[a + b*x])/(2*b^2) + (1/2)*x^3*((2*Log[Tan[a + b*x]])/b + Tan[a + b*x]^2/b)}
{x^2*Csc[a + b*x]*Sec[a + b*x]^3, x, 15, x^2/(2*b) - (2*x^2*ArcTanh[E^(2*I*a + 2*I*b*x)])/b - Log[Cos[a + b*x]]/b^3 - (x^2*Log[Tan[a + b*x]])/b + (I*x*PolyLog[2, -E^(2*I*(a + b*x))])/b^2 - (I*x*PolyLog[2, E^(2*I*(a + b*x))])/b^2 - PolyLog[3, -E^(2*I*(a + b*x))]/(2*b^3) + PolyLog[3, E^(2*I*(a + b*x))]/(2*b^3) - (x*Tan[a + b*x])/b^2 + (1/2)*x^2*((2*Log[Tan[a + b*x]])/b + Tan[a + b*x]^2/b)}
{x^1*Csc[a + b*x]*Sec[a + b*x]^3, x, 9, x/(2*b) - (2*x*ArcTanh[E^(2*I*a + 2*I*b*x)])/b - (x*Log[Tan[a + b*x]])/b + (I*PolyLog[2, -E^(2*I*(a + b*x))])/(2*b^2) - (I*PolyLog[2, E^(2*I*(a + b*x))])/(2*b^2) - Tan[a + b*x]/(2*b^2) + (1/2)*x*((2*Log[Tan[a + b*x]])/b + Tan[a + b*x]^2/b)}
{x^0*Csc[a + b*x]*Sec[a + b*x]^3, x, 3, Log[Tan[a + b*x]]/b + Tan[a + b*x]^2/(2*b)}
{Csc[a + b*x]*Sec[a + b*x]^3/x^1, x, 0, Int[(Csc[a + b*x]*Sec[a + b*x]^3)/x, x]}


{x^3*Csc[a + b*x]^2*Sec[a + b*x], x, 19, -((2*I*x^3*ArcTan[E^(I*a + I*b*x)])/b) - (6*x^2*ArcTanh[E^(I*a + I*b*x)])/b^2 - (x^3*ArcTanh[Sin[a + b*x]])/b + x^3*(ArcTanh[Sin[a + b*x]]/b - Csc[a + b*x]/b) + (6*I*x*PolyLog[2, -E^(I*(a + b*x))])/b^3 + (3*I*x^2*PolyLog[2, (-I)*E^(I*(a + b*x))])/b^2 - (3*I*x^2*PolyLog[2, I*E^(I*(a + b*x))])/b^2 - (6*I*x*PolyLog[2, E^(I*(a + b*x))])/b^3 - (6*PolyLog[3, -E^(I*(a + b*x))])/b^4 - (6*x*PolyLog[3, (-I)*E^(I*(a + b*x))])/b^3 + (6*x*PolyLog[3, I*E^(I*(a + b*x))])/b^3 + (6*PolyLog[3, E^(I*(a + b*x))])/b^4 - (6*I*PolyLog[4, (-I)*E^(I*(a + b*x))])/b^4 + (6*I*PolyLog[4, I*E^(I*(a + b*x))])/b^4}
{x^2*Csc[a + b*x]^2*Sec[a + b*x], x, 15, -((2*I*x^2*ArcTan[E^(I*a + I*b*x)])/b) - (4*x*ArcTanh[E^(I*a + I*b*x)])/b^2 - (x^2*ArcTanh[Sin[a + b*x]])/b + x^2*(ArcTanh[Sin[a + b*x]]/b - Csc[a + b*x]/b) + (2*I*PolyLog[2, -E^(I*(a + b*x))])/b^3 + (2*I*x*PolyLog[2, (-I)*E^(I*(a + b*x))])/b^2 - (2*I*x*PolyLog[2, I*E^(I*(a + b*x))])/b^2 - (2*I*PolyLog[2, E^(I*(a + b*x))])/b^3 - (2*PolyLog[3, (-I)*E^(I*(a + b*x))])/b^3 + (2*PolyLog[3, I*E^(I*(a + b*x))])/b^3}
{x^1*Csc[a + b*x]^2*Sec[a + b*x], x, 8, -((2*I*x*ArcTan[E^(I*a + I*b*x)])/b) - ArcTanh[Cos[a + b*x]]/b^2 - (x*ArcTanh[Sin[a + b*x]])/b + x*(ArcTanh[Sin[a + b*x]]/b - Csc[a + b*x]/b) + (I*PolyLog[2, (-I)*E^(I*(a + b*x))])/b^2 - (I*PolyLog[2, I*E^(I*(a + b*x))])/b^2}
{x^0*Csc[a + b*x]^2*Sec[a + b*x], x, 2, ArcTanh[Sin[a + b*x]]/b - Csc[a + b*x]/b}
{Csc[a + b*x]^2*Sec[a + b*x]/x^1, x, 0, Int[(Csc[a + b*x]^2*Sec[a + b*x])/x, x]}

{x^3*Csc[a + b*x]^2*Sec[a + b*x]^2, x, 7, -((2*I*x^3)/b) - (2*x^3*Cot[2*a + 2*b*x])/b + (3*x^2*Log[1 - E^(4*I*a + 4*I*b*x)])/b^2 - (3*I*x*PolyLog[2, E^(4*I*a + 4*I*b*x)])/(2*b^3) + (3*PolyLog[3, E^(4*I*a + 4*I*b*x)])/(8*b^4)}
{x^2*Csc[a + b*x]^2*Sec[a + b*x]^2, x, 6, -((2*I*x^2)/b) - (2*x^2*Cot[2*a + 2*b*x])/b + (2*x*Log[1 - E^(4*I*a + 4*I*b*x)])/b^2 - (I*PolyLog[2, E^(4*I*a + 4*I*b*x)])/(2*b^3)}
{x^1*Csc[a + b*x]^2*Sec[a + b*x]^2, x, 3, -((2*x*Cot[2*a + 2*b*x])/b) + Log[Sin[2*a + 2*b*x]]/b^2}
{x^0*Csc[a + b*x]^2*Sec[a + b*x]^2, x, 3, -(Cot[a + b*x]/b) + Tan[a + b*x]/b}
{Csc[a + b*x]^2*Sec[a + b*x]^2/x^1, x, 1, 4*Int[Csc[2*a + 2*b*x]^2/x, x]}

{x^3*Csc[a + b*x]^2*Sec[a + b*x]^3, x, 36, -((6*I*x*ArcTan[E^(I*a + I*b*x)])/b^3) - (3*I*x^3*ArcTan[E^(I*a + I*b*x)])/b - (6*x^2*ArcTanh[E^(I*a + I*b*x)])/b^2 - (3*x^2*ArcTanh[Cos[a + b*x]])/(2*b^2) - (3*x^3*ArcTanh[Sin[a + b*x]])/(2*b) + (6*I*x*PolyLog[2, -E^(I*(a + b*x))])/b^3 + (3*I*PolyLog[2, (-I)*E^(I*(a + b*x))])/b^4 + (9*I*x^2*PolyLog[2, (-I)*E^(I*(a + b*x))])/(2*b^2) - (3*I*PolyLog[2, I*E^(I*(a + b*x))])/b^4 - (9*I*x^2*PolyLog[2, I*E^(I*(a + b*x))])/(2*b^2) - (6*I*x*PolyLog[2, E^(I*(a + b*x))])/b^3 - (6*PolyLog[3, -E^(I*(a + b*x))])/b^4 - (9*x*PolyLog[3, (-I)*E^(I*(a + b*x))])/b^3 + (9*x*PolyLog[3, I*E^(I*(a + b*x))])/b^3 + (6*PolyLog[3, E^(I*(a + b*x))])/b^4 - (9*I*PolyLog[4, (-I)*E^(I*(a + b*x))])/b^4 + (9*I*PolyLog[4, I*E^(I*(a + b*x))])/b^4 + (3*x^2*(ArcTanh[Cos[a + b*x]]/b - Sec[a + b*x]/b))/(2*b) + (1/2)*x^3*((3*ArcTanh[Sin[a + b*x]])/b - (3*Csc[a + b*x])/b + (Csc[a + b*x]*Sec[a + b*x]^2)/b)}
{x^2*Csc[a + b*x]^2*Sec[a + b*x]^3, x, 25, -((3*I*x^2*ArcTan[E^(I*a + I*b*x)])/b) - (4*x*ArcTanh[E^(I*a + I*b*x)])/b^2 - (x*ArcTanh[Cos[a + b*x]])/b^2 + ArcTanh[Sin[a + b*x]]/b^3 - (3*x^2*ArcTanh[Sin[a + b*x]])/(2*b) + (2*I*PolyLog[2, -E^(I*(a + b*x))])/b^3 + (3*I*x*PolyLog[2, (-I)*E^(I*(a + b*x))])/b^2 - (3*I*x*PolyLog[2, I*E^(I*(a + b*x))])/b^2 - (2*I*PolyLog[2, E^(I*(a + b*x))])/b^3 - (3*PolyLog[3, (-I)*E^(I*(a + b*x))])/b^3 + (3*PolyLog[3, I*E^(I*(a + b*x))])/b^3 + (x*(ArcTanh[Cos[a + b*x]]/b - Sec[a + b*x]/b))/b + (1/2)*x^2*((3*ArcTanh[Sin[a + b*x]])/b - (3*Csc[a + b*x])/b + (Csc[a + b*x]*Sec[a + b*x]^2)/b)}
{x^1*Csc[a + b*x]^2*Sec[a + b*x]^3, x, 10, -((3*I*x*ArcTan[E^(I*a + I*b*x)])/b) - ArcTanh[Cos[a + b*x]]/b^2 - (3*x*ArcTanh[Sin[a + b*x]])/(2*b) + (3*I*PolyLog[2, (-I)*E^(I*(a + b*x))])/(2*b^2) - (3*I*PolyLog[2, I*E^(I*(a + b*x))])/(2*b^2) - Sec[a + b*x]/(2*b^2) + (1/2)*x*((3*ArcTanh[Sin[a + b*x]])/b - (3*Csc[a + b*x])/b + (Csc[a + b*x]*Sec[a + b*x]^2)/b)}
{x^0*Csc[a + b*x]^2*Sec[a + b*x]^3, x, 3, (3*ArcTanh[Sin[a + b*x]])/(2*b) - (3*Csc[a + b*x])/(2*b) + (Csc[a + b*x]*Sec[a + b*x]^2)/(2*b)}
{Csc[a + b*x]^2*Sec[a + b*x]^3/x^1, x, 0, Int[(Csc[a + b*x]^2*Sec[a + b*x]^3)/x, x]}


{x^3*Csc[a + b*x]^3*Sec[a + b*x], x, 20, -((3*I*x^2)/(2*b^2)) - x^3/(2*b) - (2*x^3*ArcTanh[E^(2*I*a + 2*I*b*x)])/b - (3*x^2*Cot[a + b*x])/(2*b^2) + (3*x*Log[1 - E^(2*I*a + 2*I*b*x)])/b^3 - (x^3*Log[Tan[a + b*x]])/b - (1/2)*x^3*(Cot[a + b*x]^2/b - (2*Log[Tan[a + b*x]])/b) - (3*I*PolyLog[2, E^(2*I*a + 2*I*b*x)])/(2*b^4) + (3*I*x^2*PolyLog[2, -E^(2*I*(a + b*x))])/(2*b^2) - (3*I*x^2*PolyLog[2, E^(2*I*(a + b*x))])/(2*b^2) - (3*x*PolyLog[3, -E^(2*I*(a + b*x))])/(2*b^3) + (3*x*PolyLog[3, E^(2*I*(a + b*x))])/(2*b^3) - (3*I*PolyLog[4, -E^(2*I*(a + b*x))])/(4*b^4) + (3*I*PolyLog[4, E^(2*I*(a + b*x))])/(4*b^4)}
{x^2*Csc[a + b*x]^3*Sec[a + b*x], x, 15, -(x^2/(2*b)) - (2*x^2*ArcTanh[E^(2*I*a + 2*I*b*x)])/b - (x*Cot[a + b*x])/b^2 + Log[Sin[a + b*x]]/b^3 - (x^2*Log[Tan[a + b*x]])/b - (1/2)*x^2*(Cot[a + b*x]^2/b - (2*Log[Tan[a + b*x]])/b) + (I*x*PolyLog[2, -E^(2*I*(a + b*x))])/b^2 - (I*x*PolyLog[2, E^(2*I*(a + b*x))])/b^2 - PolyLog[3, -E^(2*I*(a + b*x))]/(2*b^3) + PolyLog[3, E^(2*I*(a + b*x))]/(2*b^3)}
{x^1*Csc[a + b*x]^3*Sec[a + b*x], x, 9, -(x/(2*b)) - (2*x*ArcTanh[E^(2*I*a + 2*I*b*x)])/b - Cot[a + b*x]/(2*b^2) - (x*Log[Tan[a + b*x]])/b - (1/2)*x*(Cot[a + b*x]^2/b - (2*Log[Tan[a + b*x]])/b) + (I*PolyLog[2, -E^(2*I*(a + b*x))])/(2*b^2) - (I*PolyLog[2, E^(2*I*(a + b*x))])/(2*b^2)}
{x^0*Csc[a + b*x]^3*Sec[a + b*x], x, 3, -(Cot[a + b*x]^2/(2*b)) + Log[Tan[a + b*x]]/b}
{Csc[a + b*x]^3*Sec[a + b*x]/x^1, x, 0, Int[(Csc[a + b*x]^3*Sec[a + b*x])/x, x]}

{x^3*Csc[a + b*x]^3*Sec[a + b*x]^2, x, 36, (6*I*x^2*ArcTan[E^(I*a + I*b*x)])/b^2 - (6*x*ArcTanh[E^(I*a + I*b*x)])/b^3 - (3*x^3*ArcTanh[E^(I*a + I*b*x)])/b + (3*x^3*ArcTanh[Cos[a + b*x]])/(2*b) - (3*x^2*ArcTanh[Sin[a + b*x]])/(2*b^2) + (3*x^2*(ArcTanh[Sin[a + b*x]]/b - Csc[a + b*x]/b))/(2*b) + (3*I*PolyLog[2, -E^(I*(a + b*x))])/b^4 + (9*I*x^2*PolyLog[2, -E^(I*(a + b*x))])/(2*b^2) - (6*I*x*PolyLog[2, (-I)*E^(I*(a + b*x))])/b^3 + (6*I*x*PolyLog[2, I*E^(I*(a + b*x))])/b^3 - (3*I*PolyLog[2, E^(I*(a + b*x))])/b^4 - (9*I*x^2*PolyLog[2, E^(I*(a + b*x))])/(2*b^2) - (9*x*PolyLog[3, -E^(I*(a + b*x))])/b^3 + (6*PolyLog[3, (-I)*E^(I*(a + b*x))])/b^4 - (6*PolyLog[3, I*E^(I*(a + b*x))])/b^4 + (9*x*PolyLog[3, E^(I*(a + b*x))])/b^3 - (9*I*PolyLog[4, -E^(I*(a + b*x))])/b^4 + (9*I*PolyLog[4, E^(I*(a + b*x))])/b^4 - (1/2)*x^3*((3*ArcTanh[Cos[a + b*x]])/b - (3*Sec[a + b*x])/b + (Csc[a + b*x]^2*Sec[a + b*x])/b)}
{x^2*Csc[a + b*x]^3*Sec[a + b*x]^2, x, 25, (4*I*x*ArcTan[E^(I*a + I*b*x)])/b^2 - (3*x^2*ArcTanh[E^(I*a + I*b*x)])/b - ArcTanh[Cos[a + b*x]]/b^3 + (3*x^2*ArcTanh[Cos[a + b*x]])/(2*b) - (x*ArcTanh[Sin[a + b*x]])/b^2 + (x*(ArcTanh[Sin[a + b*x]]/b - Csc[a + b*x]/b))/b + (3*I*x*PolyLog[2, -E^(I*(a + b*x))])/b^2 - (2*I*PolyLog[2, (-I)*E^(I*(a + b*x))])/b^3 + (2*I*PolyLog[2, I*E^(I*(a + b*x))])/b^3 - (3*I*x*PolyLog[2, E^(I*(a + b*x))])/b^2 - (3*PolyLog[3, -E^(I*(a + b*x))])/b^3 + (3*PolyLog[3, E^(I*(a + b*x))])/b^3 - (1/2)*x^2*((3*ArcTanh[Cos[a + b*x]])/b - (3*Sec[a + b*x])/b + (Csc[a + b*x]^2*Sec[a + b*x])/b)}
{x^1*Csc[a + b*x]^3*Sec[a + b*x]^2, x, 10, -((3*x*ArcTanh[E^(I*a + I*b*x)])/b) + (3*x*ArcTanh[Cos[a + b*x]])/(2*b) - ArcTanh[Sin[a + b*x]]/b^2 - Csc[a + b*x]/(2*b^2) + (3*I*PolyLog[2, -E^(I*(a + b*x))])/(2*b^2) - (3*I*PolyLog[2, E^(I*(a + b*x))])/(2*b^2) - (1/2)*x*((3*ArcTanh[Cos[a + b*x]])/b - (3*Sec[a + b*x])/b + (Csc[a + b*x]^2*Sec[a + b*x])/b)}
{x^0*Csc[a + b*x]^3*Sec[a + b*x]^2, x, 3, -((3*ArcTanh[Cos[a + b*x]])/(2*b)) + (3*Sec[a + b*x])/(2*b) - (Csc[a + b*x]^2*Sec[a + b*x])/(2*b)}
{Csc[a + b*x]^3*Sec[a + b*x]^2/x^1, x, 0, Int[(Csc[a + b*x]^3*Sec[a + b*x]^2)/x, x]}

{x^3*Sec[a + b*x]^3*Csc[a + b*x]^3, x, 12, -((6*x*ArcTanh[E^(2*I*a + 2*I*b*x)])/b^3) - (4*x^3*ArcTanh[E^(2*I*a + 2*I*b*x)])/b - (3*x^2*Csc[2*a + 2*b*x])/b^2 - (2*x^3*Cot[2*a + 2*b*x]*Csc[2*a + 2*b*x])/b + (3*I*PolyLog[2, -E^(2*I*(a + b*x))])/(2*b^4) + (3*I*x^2*PolyLog[2, -E^(2*I*(a + b*x))])/b^2 - (3*I*PolyLog[2, E^(2*I*(a + b*x))])/(2*b^4) - (3*I*x^2*PolyLog[2, E^(2*I*(a + b*x))])/b^2 - (3*x*PolyLog[3, -E^(2*I*(a + b*x))])/b^3 + (3*x*PolyLog[3, E^(2*I*(a + b*x))])/b^3 - (3*I*PolyLog[4, -E^(2*I*(a + b*x))])/(2*b^4) + (3*I*PolyLog[4, E^(2*I*(a + b*x))])/(2*b^4)}
{x^2*Sec[a + b*x]^3*Csc[a + b*x]^3, x, 8, -((4*x^2*ArcTanh[E^(2*I*a + 2*I*b*x)])/b) - ArcTanh[Cos[2*a + 2*b*x]]/b^3 - (2*x*Csc[2*a + 2*b*x])/b^2 - (2*x^2*Cot[2*a + 2*b*x]*Csc[2*a + 2*b*x])/b + (2*I*x*PolyLog[2, -E^(2*I*(a + b*x))])/b^2 - (2*I*x*PolyLog[2, E^(2*I*(a + b*x))])/b^2 - PolyLog[3, -E^(2*I*(a + b*x))]/b^3 + PolyLog[3, E^(2*I*(a + b*x))]/b^3}
{x^1*Sec[a + b*x]^3*Csc[a + b*x]^3, x, 5, -((4*x*ArcTanh[E^(2*I*a + 2*I*b*x)])/b) - Csc[2*a + 2*b*x]/b^2 - (2*x*Cot[2*a + 2*b*x]*Csc[2*a + 2*b*x])/b + (I*PolyLog[2, -E^(2*I*(a + b*x))])/b^2 - (I*PolyLog[2, E^(2*I*(a + b*x))])/b^2}
{x^0*Sec[a + b*x]^3*Csc[a + b*x]^3, x, 3, -(Cot[a + b*x]^2/(2*b)) + (2*Log[Tan[a + b*x]])/b + Tan[a + b*x]^2/(2*b)}
{Sec[a + b*x]^3*Csc[a + b*x]^3/x^1, x, 1, 8*Int[Csc[2*a + 2*b*x]^3/x, x]}


(* ::Subsection::Closed:: *)
(*Integrands of the form Trig[m x]^p Trig[n x]^q*)


(* ::Subsubsection::Closed:: *)
(*Integrands of the form Trig[m x] Sin[n x]*)


{Sin[2*x]*Sin[x],x, 2, (2*Sin[x]^3)/3}
{Sin[3*x]*Sin[x],x, 3, (1/4)*Sin[2*x] - (1/8)*Sin[4*x]}
{Sin[4*x]*Sin[x],x, 3, (1/6)*Sin[3*x] - (1/10)*Sin[5*x]}
{Sin[m*x]*Sin[x],x, 4, Sin[(1 - m)*x]/(2*(1 - m)) - Sin[(1 + m)*x]/(2*(1 + m))}


{Cos[2*x]*Sin[x],x, 3, Cos[x]/2 - (1/6)*Cos[3*x]}
{Cos[3*x]*Sin[x],x, 3, (1/4)*Cos[2*x] - (1/8)*Cos[4*x]}
{Cos[4*x]*Sin[x],x, 3, (1/6)*Cos[3*x] - (1/10)*Cos[5*x]}
{Cos[m*x]*Sin[x],x, 4, -(Cos[(1 - m)*x]/(2*(1 - m))) - Cos[(1 + m)*x]/(2*(1 + m))}


{Tan[2*x]*Sin[x], x, 4, ArcTanh[Sqrt[2]*Sin[x]]/Sqrt[2] - Sin[x]}
{Tan[3*x]*Sin[x], x, 3, (1/3)*ArcTanh[(3*Sin[x])/(1 + 2*Sin[x]^2)] - Sin[x]}
{Tan[4*x]*Sin[x], x, 5, -(((1 - Sqrt[2])*ArcTanh[(2*Sin[x])/Sqrt[2 - Sqrt[2]]])/(2*Sqrt[2*(2 - Sqrt[2])])) + ((1 + Sqrt[2])*ArcTanh[(2*Sin[x])/Sqrt[2 + Sqrt[2]]])/(2*Sqrt[2*(2 + Sqrt[2])]) - Sin[x]}
{Tan[5*x]*Sin[x], x, 12, (1/5)*ArcTanh[Sin[x]] + (1/20)*(-1 + Sqrt[5])*Log[1 - Sqrt[5] - 4*Sin[x]] + (1/20)*(-1 - Sqrt[5])*Log[1 + Sqrt[5] - 4*Sin[x]] + (1/20)*(1 - Sqrt[5])*Log[1 - Sqrt[5] + 4*Sin[x]] + (1/20)*(1 + Sqrt[5])*Log[1 + Sqrt[5] + 4*Sin[x]] - Sin[x]}
{Tan[6*x]*Sin[x], x, 10, ArcTanh[Sqrt[2]*Sin[x]]/(3*Sqrt[2]) + (1/6)*Sqrt[2 - Sqrt[3]]*ArcTanh[(2*Sin[x])/Sqrt[2 - Sqrt[3]]] + (1/6)*Sqrt[2 + Sqrt[3]]*ArcTanh[(2*Sin[x])/Sqrt[2 + Sqrt[3]]] - Sin[x]}
(* Before use of TryTrigReduceQ in ExpandExpression, TrigReduce expansion resulted in infinite recursion. *)
{Tan[n*x]*Sin[x], x, 0, Int[Sin[x]*Tan[n*x], x]}


{Cot[2*x]*Sin[x], x, 3, (-(1/2))*ArcTanh[Sin[x]] + Sin[x]}
{Cot[3*x]*Sin[x], x, 3, -(ArcTanh[(2*Sin[x])/Sqrt[3]]/Sqrt[3]) + Sin[x]}
{Cot[4*x]*Sin[x], x, 6, (-(1/4))*ArcTanh[Sin[x]] - ArcTanh[Sqrt[2]*Sin[x]]/(2*Sqrt[2]) + Sin[x]}
{Cot[5*x]*Sin[x], x, 6, ((1 - Sqrt[5])*ArcTanh[(2*Sqrt[2/(-1 + Sqrt[5])]*Sin[x])/5^(1/4)])/Sqrt[10*(5 - Sqrt[5])] - ((1 + Sqrt[5])*ArcTanh[(2*Sqrt[2/(1 + Sqrt[5])]*Sin[x])/5^(1/4)])/Sqrt[10*(5 + Sqrt[5])] + Sin[x]}
{Cot[6*x]*Sin[x], x, 9, (-(1/6))*ArcTanh[Sin[x]] - (1/6)*ArcTanh[2*Sin[x]] - ArcTanh[(2*Sin[x])/Sqrt[3]]/(2*Sqrt[3]) + Sin[x]}


{Sec[2*x]*Sin[x], x, 2, ArcTanh[Sqrt[2]*Cos[x]]/Sqrt[2]}
{Sec[3*x]*Sin[x], x, 2, (-(1/3))*ArcTanh[1 - (8*Cos[x]^2)/3]}
{Sec[4*x]*Sin[x], x, 4, -(ArcTanh[(2*Cos[x])/Sqrt[2 - Sqrt[2]]]/(2*Sqrt[2*(2 - Sqrt[2])])) + ArcTanh[(2*Cos[x])/Sqrt[2 + Sqrt[2]]]/(2*Sqrt[2*(2 + Sqrt[2])])}
{Sec[5*x]*Sin[x], x, 6, (-(1/5))*Log[Cos[x]] - (1/20)*(-1 - Sqrt[5])*Log[5 - Sqrt[5] - 8*Cos[x]^2] - (1/20)*(-1 + Sqrt[5])*Log[5 + Sqrt[5] - 8*Cos[x]^2]}
{Sec[6*x]*Sin[x], x, 7, -(ArcTanh[Sqrt[2]*Cos[x]]/(3*Sqrt[2])) + ArcTanh[(2*Cos[x])/Sqrt[2 - Sqrt[3]]]/(6*Sqrt[2 - Sqrt[3]]) + ArcTanh[(2*Cos[x])/Sqrt[2 + Sqrt[3]]]/(6*Sqrt[2 + Sqrt[3]])}


{Csc[2*x]*Sin[x], x, 2, (1/2)*ArcTanh[Sin[x]]}
{Csc[3*x]*Sin[x], x, 3, ArcTanh[Sqrt[3]*Cot[x]]/Sqrt[3]}
{Csc[4*x]*Sin[x], x, 4, (-(1/4))*ArcTanh[Sin[x]] + ArcTanh[Sqrt[2]*Sin[x]]/(2*Sqrt[2])}
{Csc[5*x]*Sin[x], x, 8, (1/10)*Sqrt[10 - 2*Sqrt[5]]*ArcTanh[Sqrt[5 - 2*Sqrt[5]]*Cot[x]] - (1/10)*Sqrt[10 + 2*Sqrt[5]]*ArcTanh[Sqrt[5 + 2*Sqrt[5]]*Cot[x]]}
{Csc[6*x]*Sin[x], x, 7, (1/6)*ArcTanh[Sin[x]] + (1/6)*ArcTanh[2*Sin[x]] - ArcTanh[(2*Sin[x])/Sqrt[3]]/(2*Sqrt[3])}

{Csc[x]*Sin[3*x], x, 3, x + 2*Cos[x]*Sin[x]}
{Csc[3*x]*Sin[6*x], x, 2, (2*Sin[3*x])/3}


(* ::Subsubsection::Closed:: *)
(*Integrands of the form Trig[m x] Cos[n x]*)


{Sin[2*x]*Cos[x], x, 2, (-(2/3))*Cos[x]^3}
{Sin[3*x]*Cos[x], x, 3, (-(1/4))*Cos[2*x] - (1/8)*Cos[4*x]}
{Sin[4*x]*Cos[x], x, 3, (-(1/6))*Cos[3*x] - (1/10)*Cos[5*x]}
{Sin[m*x]*Cos[x], x, 4, Cos[(1 - m)*x]/(2*(1 - m)) - Cos[(1 + m)*x]/(2*(1 + m))}


{Cos[2*x]*Cos[x], x, 3, Sin[x]/2 + (1/6)*Sin[3*x]}
{Cos[3*x]*Cos[x], x, 3, (1/4)*Sin[2*x] + (1/8)*Sin[4*x]}
{Cos[4*x]*Cos[x], x, 3, (1/6)*Sin[3*x] + (1/10)*Sin[5*x]}
{Cos[m*x]*Cos[x], x, 4, Sin[(1 - m)*x]/(2*(1 - m)) + Sin[(1 + m)*x]/(2*(1 + m))}


{Tan[2*x]*Cos[x], x, 4, ArcTanh[Sqrt[2]*Cos[x]]/Sqrt[2] - Cos[x]}
{Tan[3*x]*Cos[x], x, 3, ArcTanh[(2*Cos[x])/Sqrt[3]]/Sqrt[3] - Cos[x]}
{Tan[4*x]*Cos[x], x, 6, -(((1 - Sqrt[2])*ArcTanh[(2*Cos[x])/Sqrt[2 - Sqrt[2]]])/(2*Sqrt[2*(2 - Sqrt[2])])) + ((1 + Sqrt[2])*ArcTanh[(2*Cos[x])/Sqrt[2 + Sqrt[2]]])/(2*Sqrt[2*(2 + Sqrt[2])]) - Cos[x]}
{Tan[5*x]*Cos[x], x, 6, -(((1 - Sqrt[5])*ArcTanh[(2*Sqrt[2/(-1 + Sqrt[5])]*Cos[x])/5^(1/4)])/Sqrt[10*(5 - Sqrt[5])]) + ((1 + Sqrt[5])*ArcTanh[(2*Sqrt[2/(1 + Sqrt[5])]*Cos[x])/5^(1/4)])/Sqrt[10*(5 + Sqrt[5])] - Cos[x]}
{Tan[6*x]*Cos[x], x, 10, ArcTanh[Sqrt[2]*Cos[x]]/(3*Sqrt[2]) + (1/6)*Sqrt[2 - Sqrt[3]]*ArcTanh[(2*Cos[x])/Sqrt[2 - Sqrt[3]]] + (1/6)*Sqrt[2 + Sqrt[3]]*ArcTanh[(2*Cos[x])/Sqrt[2 + Sqrt[3]]] - Cos[x]}


{Cot[2*x]*Cos[x], x, 4, (-(1/2))*ArcTanh[Cos[x]] + Cos[x]}
{Cot[3*x]*Cos[x], x, 3, (-(1/3))*ArcTanh[(3*Cos[x])/(1 + 2*Cos[x]^2)] + Cos[x]}
{Cot[4*x]*Cos[x], x, 6, (-(1/4))*ArcTanh[Cos[x]] - ArcTanh[Sqrt[2]*Cos[x]]/(2*Sqrt[2]) + Cos[x]}
{Cot[5*x]*Cos[x], x, 12, (-(1/5))*ArcTanh[Cos[x]] + Cos[x] - (1/20)*(-1 + Sqrt[5])*Log[1 - Sqrt[5] - 4*Cos[x]] - (1/20)*(-1 - Sqrt[5])*Log[1 + Sqrt[5] - 4*Cos[x]] - (1/20)*(1 - Sqrt[5])*Log[1 - Sqrt[5] + 4*Cos[x]] - (1/20)*(1 + Sqrt[5])*Log[1 + Sqrt[5] + 4*Cos[x]]}
{Cot[6*x]*Cos[x], x, 9, (-(1/6))*ArcTanh[Cos[x]] - (1/6)*ArcTanh[2*Cos[x]] - ArcTanh[(2*Cos[x])/Sqrt[3]]/(2*Sqrt[3]) + Cos[x]}
(* Before use of TryTrigReduceQ in ExpandExpression, TrigReduce expansion resulted in infinite recursion. *)
{Cot[n*x]*Cos[x], x, 0, Int[Cos[x]*Cot[n*x], x]}


{Sec[2*x]*Cos[x], x, 2, ArcTanh[Sqrt[2]*Sin[x]]/Sqrt[2]}
{Sec[3*x]*Cos[x], x, 3, ArcTanh[Sqrt[3]*Tan[x]]/Sqrt[3]}
{Sec[4*x]*Cos[x], x, 4, ArcTanh[(2*Sin[x])/Sqrt[2 - Sqrt[2]]]/(2*Sqrt[2*(2 - Sqrt[2])]) - ArcTanh[(2*Sin[x])/Sqrt[2 + Sqrt[2]]]/(2*Sqrt[2*(2 + Sqrt[2])])}
{Sec[5*x]*Cos[x], x, 8, (-(1/10))*Sqrt[10 - 2*Sqrt[5]]*ArcTanh[Sqrt[5 - 2*Sqrt[5]]*Tan[x]] + (1/10)*Sqrt[10 + 2*Sqrt[5]]*ArcTanh[Sqrt[5 + 2*Sqrt[5]]*Tan[x]]}
{Sec[6*x]*Cos[x], x, 7, -(ArcTanh[Sqrt[2]*Sin[x]]/(3*Sqrt[2])) + ArcTanh[(2*Sin[x])/Sqrt[2 - Sqrt[3]]]/(6*Sqrt[2 - Sqrt[3]]) + ArcTanh[(2*Sin[x])/Sqrt[2 + Sqrt[3]]]/(6*Sqrt[2 + Sqrt[3]])}

{Sec[x]*Cos[2*x], x, 3, -ArcTanh[Sin[x]] + 2*Sin[x]}
{Sec[2*x]*Cos[4*x], x, 3, -ArcTanh[Sin[2*x]]/2 + Sin[2*x]}


{Csc[2*x]*Cos[x], x, 2, (-(1/2))*ArcTanh[Cos[x]]}
{Csc[3*x]*Cos[x], x, 2, (-(1/3))*ArcTanh[1 - (8*Sin[x]^2)/3]}
{Csc[4*x]*Cos[x], x, 4, (-(1/4))*ArcTanh[Cos[x]] + ArcTanh[Sqrt[2]*Cos[x]]/(2*Sqrt[2])}
{Csc[5*x]*Cos[x], x, 6, (1/5)*Log[Sin[x]] - (1/20)*(1 + Sqrt[5])*Log[5 - Sqrt[5] - 8*Sin[x]^2] - (1/20)*(1 - Sqrt[5])*Log[5 + Sqrt[5] - 8*Sin[x]^2]}
{Csc[6*x]*Cos[x], x, 7, (-(1/6))*ArcTanh[Cos[x]] - (1/6)*ArcTanh[2*Cos[x]] + ArcTanh[(2*Cos[x])/Sqrt[3]]/(2*Sqrt[3])}


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


{x*Cos[2*x]*Sec[x], x, -1, 2*Cos[x] - x*Log[1 - I*E^(I*x)] + x*Log[1 + I*E^(I*x)] - I*PolyLog[2, (-I)*E^(I*x)] + I*PolyLog[2, I*E^(I*x)] + 2*x*Sin[x]}
{x*Cos[2*x]*Sec[x]^2, x, 7, x^2 - Log[Cos[x]] - x*Tan[x]}
{x*Cos[2*x]*Sec[x]^3, x, -1, -3*I*x*ArcTan[E^(I*x)] + (3/2)*I*PolyLog[2, (-I)*E^(I*x)] - (3/2)*I*PolyLog[2, I*E^(I*x)] + Sec[x]/2 - (1/2)*x*Sec[x]*Tan[x]}


(* ::Subsection::Closed:: *)
(*Integrands of the form (Trig[a+b x] Trig[a+b x])^m*)


{(Sin[x]*Tan[x])^(1/2), x, 2, -2*Cot[x]*Sqrt[Sin[x]*Tan[x]]}
{(Sin[x]*Tan[x])^(3/2), x, 3, (8/3)*Csc[x]*Sqrt[Sin[x]*Tan[x]] - (2/3)*Sin[x]*Sqrt[Sin[x]*Tan[x]]}
{(Sin[x]*Tan[x])^(5/2), x, 4, (64/15)*Cot[x]*Sqrt[Sin[x]*Tan[x]] + (16/15)*Tan[x]*Sqrt[Sin[x]*Tan[x]] - (2/5)*Sin[x]^2*Tan[x]*Sqrt[Sin[x]*Tan[x]]}


{(Cos[x]*Cot[x])^(1/2), x, 2, 2*Sqrt[Cos[x]*Cot[x]]*Tan[x]}
{(Cos[x]*Cot[x])^(3/2), x, 3, (2/3)*Cos[x]*Sqrt[Cos[x]*Cot[x]] - (8/3)*Sqrt[Cos[x]*Cot[x]]*Sec[x]}
{(Cos[x]*Cot[x])^(5/2), x, 4, (-(16/15))*Cot[x]*Sqrt[Cos[x]*Cot[x]] + (2/5)*Cos[x]^2*Cot[x]*Sqrt[Cos[x]*Cot[x]] - (64/15)*Sqrt[Cos[x]*Cot[x]]*Tan[x]}


(* ::Section::Closed:: *)
(*Integrands of the form x^q Trig[x]^m (a+b Trig[x]^n)^p*)


(* ::Subsection::Closed:: *)
(*Integrands of the form x^q Trig[x]^m (a+b Trig[x]^n)^p*)


{x*Cos[x]/(a + b*Sin[x])^2, x, 2, (2*ArcTan[(b + a*Tan[x/2])/Sqrt[a^2 - b^2]])/(b*Sqrt[a^2 - b^2]) - x/(b*(a + b*Sin[x]))}
{x*Cos[x]/(a + b*Sin[x])^3, x, 4, (a*ArcTan[(b + a*Tan[x/2])/Sqrt[a^2 - b^2]])/(b*(a^2 - b^2)^(3/2)) - x/(2*b*(a + b*Sin[x])^2) + Cos[x]/(2*(a^2 - b^2)*(a + b*Sin[x]))}


{x*Sin[x]/(a + b*Cos[x])^2, x, 2, -((2*ArcTan[(Sqrt[a^2 - b^2]*Tan[x/2])/(a + b)])/(b*Sqrt[a^2 - b^2])) + x/(b*(a + b*Cos[x]))}
{x*Sin[x]/(a + b*Cos[x])^3, x, 4, -((a*ArcTan[(Sqrt[a^2 - b^2]*Tan[x/2])/(a + b)])/(b*(a^2 - b^2)^(3/2))) + x/(2*b*(a + b*Cos[x])^2) + Sin[x]/(2*(a^2 - b^2)*(a + b*Cos[x]))}


{x*Sec[x]^2/(a + b*Tan[x])^2, x, 2, (a*x)/(b*(a^2 + b^2)) + Log[a*Cos[x] + b*Sin[x]]/(a^2 + b^2) - x/(b*(a + b*Tan[x]))}
{x*Csc[x]^2/(a + b*Cot[x])^2, x, 2, -((a*x)/(b*(a^2 + b^2))) + x/(b*(a + b*Cot[x])) + Log[b*Cos[x] + a*Sin[x]]/(a^2 + b^2)}


(* ::Subsubsection::Closed:: *)
(*Integrands of the form x^m Sec[x]^2 / (a+b Tan[x]^2)*)


{Sec[c + d*x]^2/(a + b*Tan[c + d*x]^2), x, 2, ArcTan[(Sqrt[b]*Tan[c + d*x])/Sqrt[a]]/(Sqrt[a]*Sqrt[b]*d)}
{x*Sec[c + d*x]^2/(a + b*Tan[c + d*x]^2), x, 10, -((I*x*Log[1 + ((a - b)*E^(2*I*c + 2*I*d*x))/(a - 2*Sqrt[a]*Sqrt[b] + b)])/(2*Sqrt[a]*Sqrt[b]*d)) + (I*x*Log[1 + ((a - b)*E^(2*I*c + 2*I*d*x))/(a + 2*Sqrt[a]*Sqrt[b] + b)])/(2*Sqrt[a]*Sqrt[b]*d) - PolyLog[2, -(((a - b)*E^(2*I*c + 2*I*d*x))/(a - 2*Sqrt[a]*Sqrt[b] + b))]/(4*Sqrt[a]*Sqrt[b]*d^2) + PolyLog[2, -(((a - b)*E^(2*I*c + 2*I*d*x))/(a + 2*Sqrt[a]*Sqrt[b] + b))]/(4*Sqrt[a]*Sqrt[b]*d^2)}
{x^2*Sec[c + d*x]^2/(a + b*Tan[c + d*x]^2), x, 12, -((I*x^2*Log[1 + ((a - b)*E^(2*I*c + 2*I*d*x))/(a - 2*Sqrt[a]*Sqrt[b] + b)])/(2*Sqrt[a]*Sqrt[b]*d)) + (I*x^2*Log[1 + ((a - b)*E^(2*I*c + 2*I*d*x))/(a + 2*Sqrt[a]*Sqrt[b] + b)])/(2*Sqrt[a]*Sqrt[b]*d) - (x*PolyLog[2, -(((a - b)*E^(2*I*c + 2*I*d*x))/(a - 2*Sqrt[a]*Sqrt[b] + b))])/(2*Sqrt[a]*Sqrt[b]*d^2) + (x*PolyLog[2, -(((a - b)*E^(2*I*c + 2*I*d*x))/(a + 2*Sqrt[a]*Sqrt[b] + b))])/(2*Sqrt[a]*Sqrt[b]*d^2) - (I*PolyLog[3, -(((a - b)*E^(2*I*c + 2*I*d*x))/(a - 2*Sqrt[a]*Sqrt[b] + b))])/(4*Sqrt[a]*Sqrt[b]*d^3) + (I*PolyLog[3, -(((a - b)*E^(2*I*c + 2*I*d*x))/(a + 2*Sqrt[a]*Sqrt[b] + b))])/(4*Sqrt[a]*Sqrt[b]*d^3)}


(* ::Section::Closed:: *)
(*Integrands of the form (A+B Trig[x]^m)^p / (a+b Trig[x]^n)*)


(* ::Subsection::Closed:: *)
(*Integrands of the form (A+B Trig[x]) (a+b Trig[x])^n*)


{(A + B*Sec[x])*(a + a*Cos[x]), x, 4, a*(A + B)*x + a*B*ArcTanh[Sin[x]] + a*A*Sin[x]}
{(A + B*Sec[x])*(a + a*Cos[x])^2, x, 5, (1/2)*a^2*(3*A + 4*B)*x + a^2*B*ArcTanh[Sin[x]] + (1/2)*a^2*(3*A + 2*B)*Sin[x] + (1/2)*A*(a^2 + a^2*Cos[x])*Sin[x]}
{(A + B*Sec[x])*(a + a*Cos[x])^3, x, 6, (1/2)*a^3*(5*A + 7*B)*x + a^3*B*ArcTanh[Sin[x]] + (5/2)*a^3*(A + B)*Sin[x] + (1/3)*a*A*(a + a*Cos[x])^2*Sin[x] + (1/6)*(5*A + 3*B)*(a^3 + a^3*Cos[x])*Sin[x]}
{(A + B*Sec[x])*(a + a*Cos[x])^4, x, 7, (1/8)*a^4*(35*A + 48*B)*x + a^4*B*ArcTanh[Sin[x]] + (5/8)*a^4*(7*A + 8*B)*Sin[x] + (1/4)*a*A*(a + a*Cos[x])^3*Sin[x] + (1/12)*(7*A + 4*B)*(a^2 + a^2*Cos[x])^2*Sin[x] + (1/24)*(35*A + 32*B)*(a^4 + a^4*Cos[x])*Sin[x]}


{(A + B*Sec[x])/(a + a*Cos[x]), x, 3, (B*ArcTanh[Sin[x]])/a + ((A - B)*Sin[x])/(a + a*Cos[x])}
{(A + B*Sec[x])/(a + a*Cos[x])^2, x, 4, (B*ArcTanh[Sin[x]])/a^2 + ((A - 4*B)*Sin[x])/(3*a^2*(1 + Cos[x])) + ((A - B)*Sin[x])/(3*(a + a*Cos[x])^2)}
{(A + B*Sec[x])/(a + a*Cos[x])^3, x, 5, (B*ArcTanh[Sin[x]])/a^3 + ((A - B)*Sin[x])/(5*(a + a*Cos[x])^3) + ((2*A - 7*B)*Sin[x])/(15*a*(a + a*Cos[x])^2) + (2*(A - 11*B)*Sin[x])/(15*(a^3 + a^3*Cos[x]))}
{(A + B*Sec[x])/(a + a*Cos[x])^4, x, 6, (B*ArcTanh[Sin[x]])/a^4 + ((6*A - 55*B)*Sin[x])/(105*a^4*(1 + Cos[x])^2) + (2*(3*A - 80*B)*Sin[x])/(105*a^4*(1 + Cos[x])) + ((A - B)*Sin[x])/(7*(a + a*Cos[x])^4) + ((3*A - 10*B)*Sin[x])/(35*a*(a + a*Cos[x])^3)}


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


{(1 + Sin[x]^2)/(1 - Sin[x]^2), x, 6, -x + 2*Tan[x]}
{(1 - Sin[x]^2)/(1 + Sin[x]^2), x, 5, -x + Sqrt[2]*ArcTan[Sqrt[2]*Tan[x]]}


{(1 + Cos[x]^2)/(1 - Cos[x]^2), x, 6, -x - 2*Cot[x]}
{(1 - Cos[x]^2)/(1 + Cos[x]^2), x, 5, -x - Sqrt[2]*ArcTan[Sqrt[2]*Cot[x]]}


{(-1 + c^2/d^2 + Sin[x]^2)/(c + d*Cos[x]), x, 4, (c*x)/d^2 - Sin[x]/d}
{(a + b*Sin[x]^2)/(c + d*Cos[x]), x, 6, (b*c*x)/d^2 + (2*a*ArcTan[(Sqrt[c^2 - d^2]*Tan[x/2])/(c + d)])/Sqrt[c^2 - d^2] - (2*b*Sqrt[c^2 - d^2]*ArcTan[(Sqrt[c^2 - d^2]*Tan[x/2])/(c + d)])/d^2 - (b*Sin[x])/d}

{(a + b*Sin[x]^2)/(c + c*Cos[x]^2), x, 8, -((b*x)/c) + ((a + 2*b)*ArcTan[Tan[x]/Sqrt[2]])/(Sqrt[2]*c), -((b*x)/c) + (a*ArcTan[Tan[x]/Sqrt[2]])/(Sqrt[2]*c) + (Sqrt[2]*b*ArcTan[Tan[x]/Sqrt[2]])/c}
{(a + b*Sin[x]^2)/(c - c*Cos[x]^2), x, 3, (b*x)/c - (a*Cot[x])/c}
{(a + b*Sin[x]^2)/(c + d*Cos[x]^2), x, 8, -((b*x)/d) + ((b*c + (a + b)*d)*ArcTan[(Sqrt[c]*Tan[x])/Sqrt[c + d]])/(Sqrt[c]*d*Sqrt[c + d])}


{(-1 + c^2/d^2 + Cos[x]^2)/(c + d*Sin[x]), x, 4, (c*x)/d^2 + Cos[x]/d}
{(a + b*Cos[x]^2)/(c + d*Sin[x]), x, 6, (b*c*x)/d^2 + (2*a*ArcTan[(d + c*Tan[x/2])/Sqrt[c^2 - d^2]])/Sqrt[c^2 - d^2] - (2*b*Sqrt[c^2 - d^2]*ArcTan[(d + c*Tan[x/2])/Sqrt[c^2 - d^2]])/d^2 + (b*Cos[x])/d}

{(a + b*Cos[x]^2)/(c + c*Sin[x]^2), x, 8, -((b*x)/c) - ((a + 2*b)*ArcTan[Cot[x]/Sqrt[2]])/(Sqrt[2]*c), -((b*x)/c) - (Sqrt[2]*b*ArcTan[Cot[x]/Sqrt[2]])/c + (a*ArcTan[Sqrt[2]*Tan[x]])/(Sqrt[2]*c)}
{(a + b*Cos[x]^2)/(c - c*Sin[x]^2), x, 3, (b*x)/c + (a*Tan[x])/c}
{(a + b*Cos[x]^2)/(c + d*Sin[x]^2), x, 8, -((b*x)/d) - (b*Sqrt[c + d]*ArcTan[(Sqrt[c]*Cot[x])/Sqrt[c + d]])/(Sqrt[c]*d) + (a*ArcTan[(Sqrt[c + d]*Tan[x])/Sqrt[c]])/(Sqrt[c]*Sqrt[c + d])}


{(a + b*Sec[x]^2)/(c + d*Cos[x]), x, 5, (2*(a*c^2 + b*d^2)*ArcTan[(Sqrt[c^2 - d^2]*Tan[x/2])/(c + d)])/(c^2*Sqrt[c^2 - d^2]) - (b*d*ArcTanh[Sin[x]])/c^2 + (b*Tan[x])/c}
{(a + b*Csc[x]^2)/(c + d*Sin[x]), x, 5, (2*(a*c^2 + b*d^2)*ArcTan[(d + c*Tan[x/2])/Sqrt[c^2 - d^2]])/(c^2*Sqrt[c^2 - d^2]) + (b*d*ArcTanh[Cos[x]])/c^2 - (b*Cot[x])/c}


(* {Sqrt[1 + Sin[x]]/(1 - Tan[x]^2), x, 0, 0} *)


(* ::Section::Closed:: *)
(*Integrands of the form (a Trig[c+d x] + b Trig[c+d x])^n*)


(* ::Subsection::Closed:: *)
(*Integrands of the form (a Cos[c+d x] + b Sin[c+d x])^n*)


(* ::Subsubsection::Closed:: *)
(*Integrands of the form (a Cos[c+d x] + b Sin[c+d x])^n*)


{(a*Cos[c+d*x] + b*Sin[c+d*x])^n, x, 2, (1/d)*((Cos[c + d*x - ArcTan[a, b]]^(1 + n)*(Cos[c + d*x - ArcTan[a, b]]^2)^((1/2)*(-1 - n))*Hypergeometric2F1[1/2, (1 - n)/2, 3/2, Sin[c + d*x - ArcTan[a, b]]^2]*(a*Cos[c + d*x] + b*Sin[c + d*x])^n*Sin[c + d*x - ArcTan[a, b]])/((a*Cos[c + d*x] + b*Sin[c + d*x])/Sqrt[a^2 + b^2])^n)}
{(2*Cos[c+d*x] + 3*Sin[c+d*x])^n, x, 2, (13^(n/2)*Cos[c + d*x - ArcTan[3/2]]^(1 + n)*(Cos[c + d*x - ArcTan[3/2]]^2)^((1/2)*(-1 - n))*Hypergeometric2F1[1/2, (1 - n)/2, 3/2, Sin[c + d*x - ArcTan[3/2]]^2]*Sin[c + d*x - ArcTan[3/2]])/d}

{(a*Cos[c+d*x] + b*Sin[c+d*x])^7, x, 3, -(((a^2 + b^2)^3*(b*Cos[c + d*x] - a*Sin[c + d*x]))/d) + ((a^2 + b^2)^2*(b*Cos[c + d*x] - a*Sin[c + d*x])^3)/d - (3*(a^2 + b^2)*(b*Cos[c + d*x] - a*Sin[c + d*x])^5)/(5*d) + (b*Cos[c + d*x] - a*Sin[c + d*x])^7/(7*d)}
{(a*Cos[c+d*x] + b*Sin[c+d*x])^6, x, 4, (5/16)*(a^2 + b^2)^3*x - (5*(a^2 + b^2)^2*(b*Cos[c + d*x] - a*Sin[c + d*x])*(a*Cos[c + d*x] + b*Sin[c + d*x]))/(16*d) - (5*(a^2 + b^2)*(b*Cos[c + d*x] - a*Sin[c + d*x])*(a*Cos[c + d*x] + b*Sin[c + d*x])^3)/(24*d) - ((b*Cos[c + d*x] - a*Sin[c + d*x])*(a*Cos[c + d*x] + b*Sin[c + d*x])^5)/(6*d)}
{(a*Cos[c+d*x] + b*Sin[c+d*x])^5, x, 3, -(((a^2 + b^2)^2*(b*Cos[c + d*x] - a*Sin[c + d*x]))/d) + (2*(a^2 + b^2)*(b*Cos[c + d*x] - a*Sin[c + d*x])^3)/(3*d) - (b*Cos[c + d*x] - a*Sin[c + d*x])^5/(5*d)}
{(a*Cos[c+d*x] + b*Sin[c+d*x])^4, x, 3, (3/8)*(a^2 + b^2)^2*x - (3*(a^2 + b^2)*(b*Cos[c + d*x] - a*Sin[c + d*x])*(a*Cos[c + d*x] + b*Sin[c + d*x]))/(8*d) - ((b*Cos[c + d*x] - a*Sin[c + d*x])*(a*Cos[c + d*x] + b*Sin[c + d*x])^3)/(4*d)}
{(a*Cos[c+d*x] + b*Sin[c+d*x])^3, x, 2, -(((a^2 + b^2)*(b*Cos[c + d*x] - a*Sin[c + d*x]))/d) + (b*Cos[c + d*x] - a*Sin[c + d*x])^3/(3*d)}
{(a*Cos[c+d*x] + b*Sin[c+d*x])^2, x, 2, (1/2)*(a^2 + b^2)*x - ((b*Cos[c + d*x] - a*Sin[c + d*x])*(a*Cos[c + d*x] + b*Sin[c + d*x]))/(2*d)}
{(a*Cos[c+d*x] + b*Sin[c+d*x])^1, x, 3, -((b*Cos[c + d*x])/d) + (a*Sin[c + d*x])/d}
{1/(a*Cos[c+d*x] + b*Sin[c+d*x])^1, x, 2, -(ArcTanh[(b*Cos[c + d*x] - a*Sin[c + d*x])/Sqrt[a^2 + b^2]]/(Sqrt[a^2 + b^2]*d))}
{1/(a*Cos[c+d*x] + b*Sin[c+d*x])^2, x, 1, Sin[c + d*x]/(a*d*(a*Cos[c + d*x] + b*Sin[c + d*x]))}
{1/(a*Cos[c+d*x] + b*Sin[c+d*x])^3, x, 3, -(ArcTanh[(b*Cos[c + d*x] - a*Sin[c + d*x])/Sqrt[a^2 + b^2]]/(2*(a^2 + b^2)^(3/2)*d)) - (b*Cos[c + d*x] - a*Sin[c + d*x])/(2*(a^2 + b^2)*d*(a*Cos[c + d*x] + b*Sin[c + d*x])^2)}
{1/(a*Cos[c+d*x] + b*Sin[c+d*x])^4, x, 2, -((b*Cos[c + d*x] - a*Sin[c + d*x])/(3*(a^2 + b^2)*d*(a*Cos[c + d*x] + b*Sin[c + d*x])^3)) + (2*Sin[c + d*x])/(3*a*(a^2 + b^2)*d*(a*Cos[c + d*x] + b*Sin[c + d*x]))}
{1/(a*Cos[c+d*x] + b*Sin[c+d*x])^5, x, 4, -((3*ArcTanh[(b*Cos[c + d*x] - a*Sin[c + d*x])/Sqrt[a^2 + b^2]])/(8*(a^2 + b^2)^(5/2)*d)) - (b*Cos[c + d*x] - a*Sin[c + d*x])/(4*(a^2 + b^2)*d*(a*Cos[c + d*x] + b*Sin[c + d*x])^4) - (3*(b*Cos[c + d*x] - a*Sin[c + d*x]))/(8*(a^2 + b^2)^2*d*(a*Cos[c + d*x] + b*Sin[c + d*x])^2)}
{1/(a*Cos[c+d*x] + b*Sin[c+d*x])^6, x, 3, -((b*Cos[c + d*x] - a*Sin[c + d*x])/(5*(a^2 + b^2)*d*(a*Cos[c + d*x] + b*Sin[c + d*x])^5)) - (4*(b*Cos[c + d*x] - a*Sin[c + d*x]))/(15*(a^2 + b^2)^2*d*(a*Cos[c + d*x] + b*Sin[c + d*x])^3) + (8*Sin[c + d*x])/(15*a*(a^2 + b^2)^2*d*(a*Cos[c + d*x] + b*Sin[c + d*x]))}


(* ::Subsubsection::Closed:: *)
(*Integrands of the form (a Cos[c+d x] + b Sin[c+d x])^(n/2)*)


{(a*Cos[c+d*x] + b*Sin[c+d*x])^(7/2), x, 4, -((10*(a^2 + b^2)*(b*Cos[c + d*x] - a*Sin[c + d*x])*Sqrt[a*Cos[c + d*x] + b*Sin[c + d*x]])/(21*d)) - (2*(b*Cos[c + d*x] - a*Sin[c + d*x])*(a*Cos[c + d*x] + b*Sin[c + d*x])^(5/2))/(7*d) + (10*(a^2 + b^2)^2*EllipticF[(1/2)*(c + d*x - ArcTan[a, b]), 2]*Sqrt[(a*Cos[c + d*x] + b*Sin[c + d*x])/Sqrt[a^2 + b^2]])/(21*d*Sqrt[a*Cos[c + d*x] + b*Sin[c + d*x]])}
{(a*Cos[c+d*x] + b*Sin[c+d*x])^(5/2), x, 3, -((2*(b*Cos[c + d*x] - a*Sin[c + d*x])*(a*Cos[c + d*x] + b*Sin[c + d*x])^(3/2))/(5*d)) + (6*(a^2 + b^2)*EllipticE[(1/2)*(c + d*x - ArcTan[a, b]), 2]*Sqrt[a*Cos[c + d*x] + b*Sin[c + d*x]])/(5*d*Sqrt[(a*Cos[c + d*x] + b*Sin[c + d*x])/Sqrt[a^2 + b^2]])}
{(a*Cos[c+d*x] + b*Sin[c+d*x])^(3/2), x, 3, -((2*(b*Cos[c + d*x] - a*Sin[c + d*x])*Sqrt[a*Cos[c + d*x] + b*Sin[c + d*x]])/(3*d)) + (2*(a^2 + b^2)*EllipticF[(1/2)*(c + d*x - ArcTan[a, b]), 2]*Sqrt[(a*Cos[c + d*x] + b*Sin[c + d*x])/Sqrt[a^2 + b^2]])/(3*d*Sqrt[a*Cos[c + d*x] + b*Sin[c + d*x]])}
{(a*Cos[c+d*x] + b*Sin[c+d*x])^(1/2), x, 2, (2*EllipticE[(1/2)*(c + d*x - ArcTan[a, b]), 2]*Sqrt[a*Cos[c + d*x] + b*Sin[c + d*x]])/(d*Sqrt[(a*Cos[c + d*x] + b*Sin[c + d*x])/Sqrt[a^2 + b^2]])}
{1/(a*Cos[c+d*x] + b*Sin[c+d*x])^(1/2), x, 2, (2*EllipticF[(1/2)*(c + d*x - ArcTan[a, b]), 2]*Sqrt[(a*Cos[c + d*x] + b*Sin[c + d*x])/Sqrt[a^2 + b^2]])/(d*Sqrt[a*Cos[c + d*x] + b*Sin[c + d*x]])}
{1/(a*Cos[c+d*x] + b*Sin[c+d*x])^(3/2), x, 3, -((2*(b*Cos[c + d*x] - a*Sin[c + d*x]))/((a^2 + b^2)*d*Sqrt[a*Cos[c + d*x] + b*Sin[c + d*x]])) - (2*EllipticE[(1/2)*(c + d*x - ArcTan[a, b]), 2]*Sqrt[a*Cos[c + d*x] + b*Sin[c + d*x]])/((a^2 + b^2)*d*Sqrt[(a*Cos[c + d*x] + b*Sin[c + d*x])/Sqrt[a^2 + b^2]])}
{1/(a*Cos[c+d*x] + b*Sin[c+d*x])^(5/2), x, 3, -((2*(b*Cos[c + d*x] - a*Sin[c + d*x]))/(3*(a^2 + b^2)*d*(a*Cos[c + d*x] + b*Sin[c + d*x])^(3/2))) + (2*EllipticF[(1/2)*(c + d*x - ArcTan[a, b]), 2]*Sqrt[(a*Cos[c + d*x] + b*Sin[c + d*x])/Sqrt[a^2 + b^2]])/(3*(a^2 + b^2)*d*Sqrt[a*Cos[c + d*x] + b*Sin[c + d*x]])}
{1/(a*Cos[c+d*x] + b*Sin[c+d*x])^(7/2), x, 4, -((2*(b*Cos[c + d*x] - a*Sin[c + d*x]))/(5*(a^2 + b^2)*d*(a*Cos[c + d*x] + b*Sin[c + d*x])^(5/2))) - (6*(b*Cos[c + d*x] - a*Sin[c + d*x]))/(5*(a^2 + b^2)^2*d*Sqrt[a*Cos[c + d*x] + b*Sin[c + d*x]]) - (6*EllipticE[(1/2)*(c + d*x - ArcTan[a, b]), 2]*Sqrt[a*Cos[c + d*x] + b*Sin[c + d*x]])/(5*(a^2 + b^2)^2*d*Sqrt[(a*Cos[c + d*x] + b*Sin[c + d*x])/Sqrt[a^2 + b^2]])}


{(2*Cos[c+d*x] + 3*Sin[c+d*x])^(7/2), x, 4, (130*13^(3/4)*EllipticF[(1/2)*(c + d*x - ArcTan[3/2]), 2])/(21*d) - (130*(3*Cos[c + d*x] - 2*Sin[c + d*x])*Sqrt[2*Cos[c + d*x] + 3*Sin[c + d*x]])/(21*d) - (2*(3*Cos[c + d*x] - 2*Sin[c + d*x])*(2*Cos[c + d*x] + 3*Sin[c + d*x])^(5/2))/(7*d)}
{(2*Cos[c+d*x] + 3*Sin[c+d*x])^(5/2), x, 3, (78*13^(1/4)*EllipticE[(1/2)*(c + d*x - ArcTan[3/2]), 2])/(5*d) - (2*(3*Cos[c + d*x] - 2*Sin[c + d*x])*(2*Cos[c + d*x] + 3*Sin[c + d*x])^(3/2))/(5*d)}
{(2*Cos[c+d*x] + 3*Sin[c+d*x])^(3/2), x, 3, (2*13^(3/4)*EllipticF[(1/2)*(c + d*x - ArcTan[3/2]), 2])/(3*d) - (2*(3*Cos[c + d*x] - 2*Sin[c + d*x])*Sqrt[2*Cos[c + d*x] + 3*Sin[c + d*x]])/(3*d)}
{(2*Cos[c+d*x] + 3*Sin[c+d*x])^(1/2), x, 2, (2*13^(1/4)*EllipticE[(1/2)*(c + d*x - ArcTan[3/2]), 2])/d}
{1/(2*Cos[c+d*x] + 3*Sin[c+d*x])^(1/2), x, 2, (2*EllipticF[(1/2)*(c + d*x - ArcTan[3/2]), 2])/(13^(1/4)*d)}
{1/(2*Cos[c+d*x] + 3*Sin[c+d*x])^(3/2), x, 3, -((2*EllipticE[(1/2)*(c + d*x - ArcTan[3/2]), 2])/(13^(3/4)*d)) - (2*(3*Cos[c + d*x] - 2*Sin[c + d*x]))/(13*d*Sqrt[2*Cos[c + d*x] + 3*Sin[c + d*x]])}
{1/(2*Cos[c+d*x] + 3*Sin[c+d*x])^(5/2), x, 3, (2*EllipticF[(1/2)*(c + d*x - ArcTan[3/2]), 2])/(39*13^(1/4)*d) - (2*(3*Cos[c + d*x] - 2*Sin[c + d*x]))/(39*d*(2*Cos[c + d*x] + 3*Sin[c + d*x])^(3/2))}
{1/(2*Cos[c+d*x] + 3*Sin[c+d*x])^(7/2), x, 4, -((6*EllipticE[(1/2)*(c + d*x - ArcTan[3/2]), 2])/(65*13^(3/4)*d)) - (2*(3*Cos[c + d*x] - 2*Sin[c + d*x]))/(65*d*(2*Cos[c + d*x] + 3*Sin[c + d*x])^(5/2)) - (6*(3*Cos[c + d*x] - 2*Sin[c + d*x]))/(845*d*Sqrt[2*Cos[c + d*x] + 3*Sin[c + d*x]])}


(* ::Subsubsection::Closed:: *)
(*Integrands of the form (a Cos[c+d x] + i a Sin[c+d x])^n*)


{(a*Cos[c + d*x] + I*a*Sin[c + d*x])^n, x, 1, -((I*(a*Cos[c + d*x] + I*a*Sin[c + d*x])^n)/(d*n))}

{(a*Cos[c + d*x] + I*a*Sin[c + d*x])^4, x, 1, -((I*(a*Cos[c + d*x] + I*a*Sin[c + d*x])^4)/(4*d))}
{(a*Cos[c + d*x] + I*a*Sin[c + d*x])^3, x, 1, -((I*(a*Cos[c + d*x] + I*a*Sin[c + d*x])^3)/(3*d))}
{(a*Cos[c + d*x] + I*a*Sin[c + d*x])^2, x, 1, -((I*(a*Cos[c + d*x] + I*a*Sin[c + d*x])^2)/(2*d))}
{(a*Cos[c + d*x] + I*a*Sin[c + d*x])^1, x, 3, -((I*a*Cos[c + d*x])/d) + (a*Sin[c + d*x])/d}
{1/(a*Cos[c + d*x] + I*a*Sin[c + d*x])^1, x, 1, I/(d*(a*Cos[c + d*x] + I*a*Sin[c + d*x]))}
{1/(a*Cos[c + d*x] + I*a*Sin[c + d*x])^2, x, 1, I/(2*d*(a*Cos[c + d*x] + I*a*Sin[c + d*x])^2)}
{1/(a*Cos[c + d*x] + I*a*Sin[c + d*x])^3, x, 1, I/(3*d*(a*Cos[c + d*x] + I*a*Sin[c + d*x])^3)}
{1/(a*Cos[c + d*x] + I*a*Sin[c + d*x])^4, x, 1, I/(4*d*(a*Cos[c + d*x] + I*a*Sin[c + d*x])^4)}


(* ::Subsubsection::Closed:: *)
(*Integrands of the form (a Cos[c+d x] + i a Sin[c+d x])^(n/2)*)


{(a*Cos[c + d*x] + I*a*Sin[c + d*x])^(5/2), x, 1, -((2*I*(a*Cos[c + d*x] + I*a*Sin[c + d*x])^(5/2))/(5*d))}
{(a*Cos[c + d*x] + I*a*Sin[c + d*x])^(3/2), x, 1, -((2*I*(a*Cos[c + d*x] + I*a*Sin[c + d*x])^(3/2))/(3*d))}
{(a*Cos[c + d*x] + I*a*Sin[c + d*x])^(1/2), x, 1, -((2*I*Sqrt[a*Cos[c + d*x] + I*a*Sin[c + d*x]])/d)}
{1/(a*Cos[c + d*x] + I*a*Sin[c + d*x])^(1/2), x, 1, (2*I)/(d*Sqrt[a*Cos[c + d*x] + I*a*Sin[c + d*x]])}
{1/(a*Cos[c + d*x] + I*a*Sin[c + d*x])^(3/2), x, 1, (2*I)/(3*d*(a*Cos[c + d*x] + I*a*Sin[c + d*x])^(3/2))}
{1/(a*Cos[c + d*x] + I*a*Sin[c + d*x])^(5/2), x, 1, (2*I)/(5*d*(a*Cos[c + d*x] + I*a*Sin[c + d*x])^(5/2))}


(* ::Subsection::Closed:: *)
(*Integrands of the form (a Sec[c+d x] + b Tan[c+d x])^n*)


{(a*Sec[x] + b*Tan[x])^5, x, 9, (-(1/16))*(a + b)^3*(3*a^2 - 9*a*b + 8*b^2)*Log[1 - Sin[x]] + (1/16)*(a - b)^3*(3*a^2 + 9*a*b + 8*b^2)*Log[1 + Sin[x]] + (1/8)*a*b^2*(3*a^2 - 7*b^2)*Sin[x] + (1/8)*b*(3*a^2 - 4*b^2)*(a + b*Sin[x])^2 + ((b + a*Sin[x])*(a + b*Sin[x])^4)/(4*(1 - Sin[x]^2)^2) - ((a + b*Sin[x])^3*(a*b - (3*a^2 - 4*b^2)*Sin[x]))/(8*(1 - Sin[x]^2))}
{(a*Sec[x] + b*Tan[x])^4, x, 13, b^4*x - 4*a*b^3*Sec[x] + (4/3)*a^3*b*Sec[x]^3 + (4/3)*a*b^3*Sec[x]^3 + a^4*Tan[x] - b^4*Tan[x] + (1/3)*a^4*Tan[x]^3 + 2*a^2*b^2*Tan[x]^3 + (1/3)*b^4*Tan[x]^3}
{(a*Sec[x] + b*Tan[x])^3, x, 7, (-(1/4))*(a - 2*b)*(a + b)^2*Log[1 - Sin[x]] + (1/4)*(a - b)^2*(a + 2*b)*Log[1 + Sin[x]] + (1/2)*a*b^2*Sin[x] + ((b + a*Sin[x])*(a + b*Sin[x])^2)/(2*(1 - Sin[x]^2))}
{(a*Sec[x] + b*Tan[x])^2, x, 7, (-b^2)*x + 2*a*b*Sec[x] + a^2*Tan[x] + b^2*Tan[x]}
{(a*Sec[x] + b*Tan[x])^1, x, 3, a*ArcTanh[Sin[x]] - b*Log[Cos[x]]}
{1/(a*Sec[x] + b*Tan[x])^1, x, 3, Log[a + b*Sin[x]]/b}
{1/(a*Sec[x] + b*Tan[x])^2, x, 4, -(x/b^2) + (2*a*ArcTan[(b + a*Tan[x/2])/Sqrt[a^2 - b^2]])/(b^2*Sqrt[a^2 - b^2]) - Cos[x]/(b*(a + b*Sin[x]))}
{1/(a*Sec[x] + b*Tan[x])^3, x, 4, -(Log[a + b*Sin[x]]/b^3) + (a^2 - b^2)/(2*b^3*(a + b*Sin[x])^2) - (2*a)/(b^3*(a + b*Sin[x]))}
{1/(a*Sec[x] + b*Tan[x])^4, x, 14, x/b^4 + (a*ArcTan[(b + a*Tan[x/2])/Sqrt[a^2 - b^2]])/(b^2*(a^2 - b^2)^(3/2)) - (2*a*ArcTan[(b + a*Tan[x/2])/Sqrt[a^2 - b^2]])/(b^4*Sqrt[a^2 - b^2]) + ((a^2 - b^2)*Cos[x])/(3*b^3*(a + b*Sin[x])^3) - (7*a*Cos[x])/(6*b^3*(a + b*Sin[x])^2) + Cos[x]/(b^3*(a + b*Sin[x])) + (a^2*Cos[x])/(b^3*(a^2 - b^2)*(a + b*Sin[x])) - ((a^2 + 2*b^2)*Cos[x])/(6*b^3*(a^2 - b^2)*(a + b*Sin[x]))}
{1/(a*Sec[x] + b*Tan[x])^5, x, 4, Log[a + b*Sin[x]]/b^5 - (a^2 - b^2)^2/(4*b^5*(a + b*Sin[x])^4) + (4*a*(a^2 - b^2))/(3*b^5*(a + b*Sin[x])^3) - (3*a^2 - b^2)/(b^5*(a + b*Sin[x])^2) + (4*a)/(b^5*(a + b*Sin[x]))}


{(Sec[x] + Tan[x])^5, x, 5, -Log[1 - Sin[x]] + 2/(1 - Sin[x])^2 - 4/(1 - Sin[x])}
{(Sec[x] + Tan[x])^4, x, 4, x - 2*Tan[Pi/4 + x/2] + (2/3)*Tan[Pi/4 + x/2]^3}
{(Sec[x] + Tan[x])^3, x, 5, Log[1 - Sin[x]] + 2/(1 - Sin[x])}
{(Sec[x] + Tan[x])^2, x, 3, -x + 2*Tan[Pi/4 + x/2]}
{(Sec[x] + Tan[x])^1, x, 3, -2*Log[Cos[(1/4)*(Pi + 2*x)]], ArcTanh[Sin[x]] - Log[Cos[x]]}
{1/(Sec[x] + Tan[x])^1, x, 3, Log[1 + Sin[x]]}
{1/(Sec[x] + Tan[x])^2, x, 3, -x - 2*Cot[Pi/4 + x/2]}
{1/(Sec[x] + Tan[x])^3, x, 5, -Log[1 + Sin[x]] - 2/(1 + Sin[x])}
{1/(Sec[x] + Tan[x])^4, x, 4, x + 2*Cot[Pi/4 + x/2] - (2/3)*Cot[Pi/4 + x/2]^3}
{1/(Sec[x] + Tan[x])^5, x, 5, Log[1 + Sin[x]] - 2/(1 + Sin[x])^2 + 4/(1 + Sin[x])}


(* ::Subsection::Closed:: *)
(*Integrands of the form (a Cot[c+d x] + b Csc[c+d x])^n*)


{(a*Cot[x] + b*Csc[x])^5, x, 9, (1/8)*a^2*b*(7*a^2 - 3*b^2)*Cos[x] + (1/8)*a*(4*a^2 - 3*b^2)*(b + a*Cos[x])^2 - ((b + a*Cos[x])^4*(a + b*Cos[x]))/(4*(1 - Cos[x]^2)^2) + ((b + a*Cos[x])^3*(a*b + (4*a^2 - 3*b^2)*Cos[x]))/(8*(1 - Cos[x]^2)) + (1/16)*(a + b)^3*(8*a^2 - 9*a*b + 3*b^2)*Log[1 - Cos[x]] + (1/16)*(a - b)^3*(8*a^2 + 9*a*b + 3*b^2)*Log[1 + Cos[x]]}
{(a*Cot[x] + b*Csc[x])^4, x, 13, a^4*x + a^4*Cot[x] - b^4*Cot[x] - (1/3)*a^4*Cot[x]^3 - 2*a^2*b^2*Cot[x]^3 - (1/3)*b^4*Cot[x]^3 + 4*a^3*b*Csc[x] - (4/3)*a^3*b*Csc[x]^3 - (4/3)*a*b^3*Csc[x]^3}
{(a*Cot[x] + b*Csc[x])^3, x, 7, (-(1/2))*a^2*b*Cos[x] - ((b + a*Cos[x])^2*(a + b*Cos[x]))/(2*(1 - Cos[x]^2)) - (1/4)*(2*a - b)*(a + b)^2*Log[1 - Cos[x]] - (1/4)*(a - b)^2*(2*a + b)*Log[1 + Cos[x]]}
{(a*Cot[x] + b*Csc[x])^2, x, 7, (-a^2)*x - a^2*Cot[x] - b^2*Cot[x] - 2*a*b*Csc[x]}
{(a*Cot[x] + b*Csc[x])^1, x, 3, (-b)*ArcTanh[Cos[x]] + a*Log[Sin[x]]}
{1/(a*Cot[x] + b*Csc[x])^1, x, 3, -(Log[b + a*Cos[x]]/a)}
{1/(a*Cot[x] + b*Csc[x])^2, x, 4, -(x/a^2) + (2*b*ArcTanh[(Sqrt[a^2 - b^2]*Tan[x/2])/(a + b)])/(a^2*Sqrt[a^2 - b^2]) + Sin[x]/(a*(b + a*Cos[x]))}
{1/(a*Cot[x] + b*Csc[x])^3, x, 4, (a^2 - b^2)/(2*a^3*(b + a*Cos[x])^2) + (2*b)/(a^3*(b + a*Cos[x])) + Log[b + a*Cos[x]]/a^3}
{1/(a*Cot[x] + b*Csc[x])^4, x, 14, x/a^4 - (b*ArcTanh[(Sqrt[a^2 - b^2]*Tan[x/2])/(a + b)])/(a^2*(a^2 - b^2)^(3/2)) - (2*b*ArcTanh[(Sqrt[a^2 - b^2]*Tan[x/2])/(a + b)])/(a^4*Sqrt[a^2 - b^2]) + ((a^2 - b^2)*Sin[x])/(3*a^3*(b + a*Cos[x])^3) + (7*b*Sin[x])/(6*a^3*(b + a*Cos[x])^2) - Sin[x]/(a^3*(b + a*Cos[x])) + (b^2*Sin[x])/(a^3*(a^2 - b^2)*(b + a*Cos[x])) - ((2*a^2 + b^2)*Sin[x])/(6*a^3*(a^2 - b^2)*(b + a*Cos[x]))}
{1/(a*Cot[x] + b*Csc[x])^5, x, 4, (a^2 - b^2)^2/(4*a^5*(b + a*Cos[x])^4) + (4*b*(a^2 - b^2))/(3*a^5*(b + a*Cos[x])^3) - (a^2 - 3*b^2)/(a^5*(b + a*Cos[x])^2) - (4*b)/(a^5*(b + a*Cos[x])) - Log[b + a*Cos[x]]/a^5}


{(Csc[x] + Cot[x])^5, x, 5, -(2/(1 - Cos[x])^2) + 4/(1 - Cos[x]) + Log[1 - Cos[x]]}
{(Csc[x] + Cot[x])^4, x, 4, x + 2*Cot[x/2] - (2/3)*Cot[x/2]^3}
{(Csc[x] + Cot[x])^3, x, 5, -(2/(1 - Cos[x])) - Log[1 - Cos[x]]}
{(Csc[x] + Cot[x])^2, x, 3, -x - 2*Cot[x/2]}
{(Csc[x] + Cot[x])^1, x, 3, -ArcTanh[Cos[x]] + Log[Sin[x]]}
{1/(Csc[x] + Cot[x])^1, x, 3, -Log[1 + Cos[x]]}
{1/(Csc[x] + Cot[x])^2, x, 3, -x + 2*Tan[x/2]}
{1/(Csc[x] + Cot[x])^3, x, 5, 2/(1 + Cos[x]) + Log[1 + Cos[x]]}
{1/(Csc[x] + Cot[x])^4, x, 4, x - 2*Tan[x/2] + (2/3)*Tan[x/2]^3}
{1/(Csc[x] + Cot[x])^5, x, 5, 2/(1 + Cos[x])^2 - 4/(1 + Cos[x]) - Log[1 + Cos[x]]}


(* ::Subsection::Closed:: *)
(*Integrands of the form (a Csc[c+d x] + b Sin[c+d x])^n*)


(* Note that Csc[x]-Sin[x] == Cos[x]*Cot[x] *)
{(Csc[x] - Sin[x])^4, x, 6, (35*x)/8 + (35*Cot[x])/8 - (35*Cot[x]^3)/24 + (7/8)*Cos[x]^2*Cot[x]^3 + (1/4)*Cos[x]^4*Cot[x]^3}
{(Csc[x] - Sin[x])^3, x, 5, (5/2)*ArcTanh[Cos[x]] - (5*Cos[x])/2 - (5/6)*Cos[x]*Cot[x]^2 + (1/3)*Cos[x]^3*Cot[x]^2}
{(Csc[x] - Sin[x])^2, x, 4, -((3*x)/2) - (3*Cot[x])/2 + (1/2)*Cos[x]^2*Cot[x]}
{(Csc[x] - Sin[x]), x, 3, -ArcTanh[Cos[x]] + Cos[x]}
{1/(Csc[x] - Sin[x])^1, x, 2, Sec[x]}
{1/(Csc[x] - Sin[x])^2, x, 3, Tan[x]^3/3}
{1/(Csc[x] - Sin[x])^3, x, 4, (-(1/3))*Sec[x]^3 + Sec[x]^5/5}
{1/(Csc[x] - Sin[x])^4, x, 4, Tan[x]^5/5 + Tan[x]^7/7}
{1/(Csc[x] - Sin[x])^5, x, 4, Sec[x]^5/5 - (2*Sec[x]^7)/7 + Sec[x]^9/9}
{1/(Csc[x] - Sin[x])^6, x, 4, Tan[x]^7/7 + (2*Tan[x]^9)/9 + Tan[x]^11/11}
{1/(Csc[x] - Sin[x])^7, x, 4, (-(1/7))*Sec[x]^7 + Sec[x]^9/3 - (3*Sec[x]^11)/11 + Sec[x]^13/13}


{(Csc[x] - Sin[x])^(7/2), x, 6, (8/7)*Cos[x]*Cot[x]^2*Sqrt[Cos[x]*Cot[x]] + (2/7)*Cos[x]^3*Cot[x]^2*Sqrt[Cos[x]*Cot[x]] - (64/35)*Cot[x]*Sqrt[Cos[x]*Cot[x]]*Csc[x] + (256/35)*Sqrt[Cos[x]*Cot[x]]*Sec[x]}
{(Csc[x] - Sin[x])^(5/2), x, 5, (-(16/15))*Cot[x]*Sqrt[Cos[x]*Cot[x]] + (2/5)*Cos[x]^2*Cot[x]*Sqrt[Cos[x]*Cot[x]] - (64/15)*Sqrt[Cos[x]*Cot[x]]*Tan[x]}
{(Csc[x] - Sin[x])^(3/2), x, 4, (2/3)*Cos[x]*Sqrt[Cos[x]*Cot[x]] - (8/3)*Sqrt[Cos[x]*Cot[x]]*Sec[x]}
{(Csc[x] - Sin[x])^(1/2), x, 3, 2*Sqrt[Cos[x]*Cot[x]]*Tan[x]}
{1/(Csc[x] - Sin[x])^(1/2), x, 8, (-ArcTan[Sqrt[Sin[x]]])*Sqrt[Cos[x]*Cot[x]]*Sec[x]*Sqrt[Sin[x]] + ArcTanh[Sqrt[Sin[x]]]*Sqrt[Cos[x]*Cot[x]]*Sec[x]*Sqrt[Sin[x]]}
{1/(Csc[x] - Sin[x])^(3/2), x, 10, (-(1/4))*ArcTan[Sqrt[Sin[x]]]*Sqrt[Cos[x]*Cot[x]]*Sec[x]*Sqrt[Sin[x]] - (1/4)*ArcTanh[Sqrt[Sin[x]]]*Sqrt[Cos[x]*Cot[x]]*Sec[x]*Sqrt[Sin[x]] + (1/2)*Sqrt[Cos[x]*Cot[x]]*Tan[x] + (1/2)*Sqrt[Cos[x]*Cot[x]]*Tan[x]^3}
{1/(Csc[x] - Sin[x])^(5/2), x, 10, (3/32)*ArcTan[Sqrt[Sin[x]]]*Sqrt[Cos[x]*Cot[x]]*Sec[x]*Sqrt[Sin[x]] - (3/32)*ArcTanh[Sqrt[Sin[x]]]*Sqrt[Cos[x]*Cot[x]]*Sec[x]*Sqrt[Sin[x]] + (1/16)*Sqrt[Cos[x]*Cot[x]]*Sec[x]*Tan[x]^2 + (1/4)*Sqrt[Cos[x]*Cot[x]]*Sec[x]*Tan[x]^4}
{1/(Csc[x] - Sin[x])^(7/2), x, 12, (5/128)*ArcTan[Sqrt[Sin[x]]]*Sqrt[Cos[x]*Cot[x]]*Sec[x]*Sqrt[Sin[x]] + (5/128)*ArcTanh[Sqrt[Sin[x]]]*Sqrt[Cos[x]*Cot[x]]*Sec[x]*Sqrt[Sin[x]] - (5/64)*Sqrt[Cos[x]*Cot[x]]*Tan[x] - (1/64)*Sqrt[Cos[x]*Cot[x]]*Tan[x]^3 + (1/16)*Sqrt[Cos[x]*Cot[x]]*Tan[x]^5 + (1/6)*Sqrt[Cos[x]*Cot[x]]*Sec[x]^2*Tan[x]^5}


(* ::Subsection::Closed:: *)
(*Integrands of the form (a Sec[c+d x] + b Cos[c+d x])^n*)


(* Note that Sec[x]-Cos[x] == Sin[x]*Tan[x] *)
{(Sec[x] - Cos[x])^4, x, 6, (35*x)/8 - (35*Tan[x])/8 + (35*Tan[x]^3)/24 - (7/8)*Sin[x]^2*Tan[x]^3 - (1/4)*Sin[x]^4*Tan[x]^3}
{(Sec[x] - Cos[x])^3, x, 5, (-(5/2))*ArcTanh[Sin[x]] + (5*Sin[x])/2 + (5/6)*Sin[x]*Tan[x]^2 - (1/3)*Sin[x]^3*Tan[x]^2}
{(Sec[x] - Cos[x])^2, x, 4, -((3*x)/2) + (3*Tan[x])/2 - (1/2)*Sin[x]^2*Tan[x]}
{(Sec[x] - Cos[x])^1, x, 3, ArcTanh[Sin[x]] - Sin[x]}
{1/(Sec[x] - Cos[x])^1, x, 2, -Csc[x]}
{1/(Sec[x] - Cos[x])^2, x, 3, (-(1/3))*Cot[x]^3}
{1/(Sec[x] - Cos[x])^3, x, 4, Csc[x]^3/3 - Csc[x]^5/5}
{1/(Sec[x] - Cos[x])^4, x, 4, (-(1/5))*Cot[x]^5 - Cot[x]^7/7}
{1/(Sec[x] - Cos[x])^5, x, 4, (-(1/5))*Csc[x]^5 + (2*Csc[x]^7)/7 - Csc[x]^9/9}
{1/(Sec[x] - Cos[x])^6, x, 4, (-(1/7))*Cot[x]^7 - (2*Cot[x]^9)/9 - Cot[x]^11/11}
{1/(Sec[x] - Cos[x])^7, x, 4, Csc[x]^7/7 - Csc[x]^9/3 + (3*Csc[x]^11)/11 - Csc[x]^13/13}


{(Sec[x] - Cos[x])^(7/2), x, 6, (-(256/35))*Csc[x]*Sqrt[Sin[x]*Tan[x]] + (64/35)*Sec[x]*Tan[x]*Sqrt[Sin[x]*Tan[x]] - (8/7)*Sin[x]*Tan[x]^2*Sqrt[Sin[x]*Tan[x]] - (2/7)*Sin[x]^3*Tan[x]^2*Sqrt[Sin[x]*Tan[x]]}
{(Sec[x] - Cos[x])^(5/2), x, 5, (64/15)*Cot[x]*Sqrt[Sin[x]*Tan[x]] + (16/15)*Tan[x]*Sqrt[Sin[x]*Tan[x]] - (2/5)*Sin[x]^2*Tan[x]*Sqrt[Sin[x]*Tan[x]]}
{(Sec[x] - Cos[x])^(3/2), x, 4, (8/3)*Csc[x]*Sqrt[Sin[x]*Tan[x]] - (2/3)*Sin[x]*Sqrt[Sin[x]*Tan[x]]}
{(Sec[x] - Cos[x])^(1/2), x, 3, -2*Cot[x]*Sqrt[Sin[x]*Tan[x]]}
{1/(Sec[x] - Cos[x])^(1/2), x, 8, ArcTan[Sqrt[Cos[x]]]*Sqrt[Cos[x]]*Csc[x]*Sqrt[Sin[x]*Tan[x]] - ArcTanh[Sqrt[Cos[x]]]*Sqrt[Cos[x]]*Csc[x]*Sqrt[Sin[x]*Tan[x]]}
{1/(Sec[x] - Cos[x])^(3/2), x, 10, (-(1/2))*Cot[x]*Sqrt[Sin[x]*Tan[x]] - (1/2)*Cot[x]^3*Sqrt[Sin[x]*Tan[x]] + (1/4)*ArcTan[Sqrt[Cos[x]]]*Sqrt[Cos[x]]*Csc[x]*Sqrt[Sin[x]*Tan[x]] + (1/4)*ArcTanh[Sqrt[Cos[x]]]*Sqrt[Cos[x]]*Csc[x]*Sqrt[Sin[x]*Tan[x]]}
{1/(Sec[x] - Cos[x])^(5/2), x, 10, (-(3/32))*ArcTan[Sqrt[Cos[x]]]*Sqrt[Cos[x]]*Csc[x]*Sqrt[Sin[x]*Tan[x]] + (3/32)*ArcTanh[Sqrt[Cos[x]]]*Sqrt[Cos[x]]*Csc[x]*Sqrt[Sin[x]*Tan[x]] - (1/16)*Cot[x]^2*Csc[x]*Sqrt[Sin[x]*Tan[x]] - (1/4)*Cot[x]^4*Csc[x]*Sqrt[Sin[x]*Tan[x]]}
{1/(Sec[x] - Cos[x])^(7/2), x, 12, (5/64)*Cot[x]*Sqrt[Sin[x]*Tan[x]] + (1/64)*Cot[x]^3*Sqrt[Sin[x]*Tan[x]] - (1/16)*Cot[x]^5*Sqrt[Sin[x]*Tan[x]] - (5/128)*ArcTan[Sqrt[Cos[x]]]*Sqrt[Cos[x]]*Csc[x]*Sqrt[Sin[x]*Tan[x]] - (5/128)*ArcTanh[Sqrt[Cos[x]]]*Sqrt[Cos[x]]*Csc[x]*Sqrt[Sin[x]*Tan[x]] - (1/6)*Cot[x]^5*Csc[x]^2*Sqrt[Sin[x]*Tan[x]]}


(* ::Subsection::Closed:: *)
(*Integrands of the form (a Sin[c+d x] + b Tan[c+d x])^n*)


{(Sin[x] + Tan[x])^4, x, 15, -((61*x)/8) - 2*ArcTanh[Sin[x]] + (19/8)*Cos[x]*Sin[x] + (1/4)*Cos[x]^3*Sin[x] - (4*Sin[x]^3)/3 + 5*Tan[x] + 2*Sec[x]*Tan[x] + Tan[x]^3/3}
{(Sin[x] + Tan[x])^3, x, 5, 2*Cos[x] + (3*Cos[x]^2)/2 + Cos[x]^3/3 - 2*Log[Cos[x]] + 3*Sec[x] + Sec[x]^2/2}
{(Sin[x] + Tan[x])^2, x, 7, -(x/2) + 2*ArcTanh[Sin[x]] - 2*Sin[x] - (1/2)*Cos[x]*Sin[x] + Tan[x]}
{(Sin[x] + Tan[x])^1, x, 3, -Cos[x] - Log[Cos[x]]}
{1/(Sin[x] + Tan[x])^1, x, 6, (-(1/2))*ArcTanh[Cos[x]] - 1/(2*(1 + Cos[x]))}
{1/(Sin[x] + Tan[x])^2, x, 8, (-(1/3))*Cot[x]^3 - (2*Cot[x]^5)/5 - (2*Csc[x]^3)/3 + (2*Csc[x]^5)/5}
{1/(Sin[x] + Tan[x])^3, x, 6, (1/32)*ArcTanh[Cos[x]] - 1/(32*(1 - Cos[x])) - 1/(16*(1 + Cos[x])^4) + 1/(6*(1 + Cos[x])^3) - 3/(32*(1 + Cos[x])^2) - 1/(16*(1 + Cos[x]))}
{1/(Sin[x] + Tan[x])^4, x, 27, -(Sin[x]/(192*(1 - Cos[x])^2)) + Sin[x]/(96*(1 - Cos[x])) + Sin[x]/(44*(1 + Cos[x])^6) - (7*Sin[x])/(99*(1 + Cos[x])^5) + (641*Sin[x])/(11088*(1 + Cos[x])^4) + (179*Sin[x])/(18480*(1 + Cos[x])^3) - (2033*Sin[x])/(221760*(1 + Cos[x])^2) - (2749*Sin[x])/(110880*(1 + Cos[x]))}


(* ::Section::Closed:: *)
(*Integrands of the form (a + b Trig[d+e x] + c Trig[d+e x])^n*)


(* ::Subsection::Closed:: *)
(*Integrands of the form (a + b Cos[d+e x] + c Sin[d+e x])^n*)


(* ::Subsubsection::Closed:: *)
(*Integrands of the form (a + b Cos[d+e x] + c Sin[d+e x])^n*)


{(a + b*Cos[d + e*x] + c*Sin[d + e*x])^4, x, 6, ((8*a^4 + 24*a^2*(b^2 + c^2) + 3*(b^2 + c^2)^2)*x)/8 - (5*a*c*(10*a^2 + 11*(b^2 + c^2))*Cos[d + e*x])/(24*e) + (5*a*b*(10*a^2 + 11*(b^2 + c^2))*Sin[d + e*x])/(24*e) - (7*(a*c*Cos[d + e*x] - a*b*Sin[d + e*x])*(a + b*Cos[d + e*x] + c*Sin[d + e*x])^2)/(12*e) - ((c*Cos[d + e*x] - b*Sin[d + e*x])*(a + b*Cos[d + e*x] + c*Sin[d + e*x])^3)/(4*e) - ((a + b*Cos[d + e*x] + c*Sin[d + e*x])*(c*(26*a^2 + 9*(b^2 + c^2))*Cos[d + e*x] - b*(26*a^2 + 9*(b^2 + c^2))*Sin[d + e*x]))/(24*e)}
{(a + b*Cos[d + e*x] + c*Sin[d + e*x])^3, x, 5, (a*(2*a^2 + 3*(b^2 + c^2))*x)/2 - (c*(11*a^2 + 4*(b^2 + c^2))*Cos[d + e*x])/(6*e) + (b*(11*a^2 + 4*(b^2 + c^2))*Sin[d + e*x])/(6*e) - (5*(a*c*Cos[d + e*x] - a*b*Sin[d + e*x])*(a + b*Cos[d + e*x] + c*Sin[d + e*x]))/(6*e) - ((c*Cos[d + e*x] - b*Sin[d + e*x])*(a + b*Cos[d + e*x] + c*Sin[d + e*x])^2)/(3*e)}
{(a + b*Cos[d + e*x] + c*Sin[d + e*x])^2, x, 4, ((2*a^2 + b^2 + c^2)*x)/2 - (3*a*c*Cos[d + e*x])/(2*e) + (3*a*b*Sin[d + e*x])/(2*e) - ((c*Cos[d + e*x] - b*Sin[d + e*x])*(a + b*Cos[d + e*x] + c*Sin[d + e*x]))/(2*e)}
{a + b*Cos[d + e*x] + c*Sin[d + e*x], x, 3, a*x - (c*Cos[d + e*x])/e + (b*Sin[d + e*x])/e}
{(a + b*Cos[d + e*x] + c*Sin[d + e*x])^(-1), x, 1, (2*ArcTan[(c + (a - b)*Tan[(d + e*x)/2])/Sqrt[a^2 - b^2 - c^2]])/(Sqrt[a^2 - b^2 - c^2]*e)}
{(a + b*Cos[d + e*x] + c*Sin[d + e*x])^(-2), x, 3, (2*a*ArcTan[(c + (a - b)*Tan[(d + e*x)/2])/Sqrt[a^2 - b^2 - c^2]])/((a^2 - b^2 - c^2)^(3/2)*e) + (c*Cos[d + e*x] - b*Sin[d + e*x])/((a^2 - b^2 - c^2)*e*(a + b*Cos[d + e*x] + c*Sin[d + e*x]))}
{(a + b*Cos[d + e*x] + c*Sin[d + e*x])^(-3), x, 3, ((2*a^2 + b^2 + c^2)*ArcTan[(c + (a - b)*Tan[(d + e*x)/2])/Sqrt[a^2 - b^2 - c^2]])/((a^2 - b^2 - c^2)^(5/2)*e) + (c*Cos[d + e*x] - b*Sin[d + e*x])/(2*(a^2 - b^2 - c^2)*e*(a + b*Cos[d + e*x] + c*Sin[d + e*x])^2) + (3*(a*c*Cos[d + e*x] - a*b*Sin[d + e*x]))/(2*(a^2 - b^2 - c^2)^2*e*(a + b*Cos[d + e*x] + c*Sin[d + e*x]))}
{(a + b*Cos[d + e*x] + c*Sin[d + e*x])^(-4), x, 4, (a*(2*a^2 + 3*(b^2 + c^2))*ArcTan[(c + (a - b)*Tan[(d + e*x)/2])/Sqrt[a^2 - b^2 - c^2]])/((a^2 - b^2 - c^2)^(7/2)*e) + (c*Cos[d + e*x] - b*Sin[d + e*x])/(3*(a^2 - b^2 - c^2)*e*(a + b*Cos[d + e*x] + c*Sin[d + e*x])^3) + (5*(a*c*Cos[d + e*x] - a*b*Sin[d + e*x]))/(6*(a^2 - b^2 - c^2)^2*e*(a + b*Cos[d + e*x] + c*Sin[d + e*x])^2) + (c*(11*a^2 + 4*(b^2 + c^2))*Cos[d + e*x] - b*(11*a^2 + 4*(b^2 + c^2))*Sin[d + e*x])/(6*(a^2 - b^2 - c^2)^3*e*(a + b*Cos[d + e*x] + c*Sin[d + e*x]))}


{(a + a*Cos[d + e*x] + c*Sin[d + e*x])^3, x, 5, (a*(5*a^2 + 3*c^2)*x)/2 - (c*(15*a^2 + 4*c^2)*Cos[d + e*x])/(6*e) + (a*(15*a^2 + 4*c^2)*Sin[d + e*x])/(6*e) - (5*(a*c*Cos[d + e*x] - a^2*Sin[d + e*x])*(a + a*Cos[d + e*x] + c*Sin[d + e*x]))/(6*e) - ((c*Cos[d + e*x] - a*Sin[d + e*x])*(a + a*Cos[d + e*x] + c*Sin[d + e*x])^2)/(3*e)}
{(a + a*Cos[d + e*x] + c*Sin[d + e*x])^2, x, 4, ((3*a^2 + c^2)*x)/2 - (3*a*c*Cos[d + e*x])/(2*e) + (3*a^2*Sin[d + e*x])/(2*e) - ((c*Cos[d + e*x] - a*Sin[d + e*x])*(a + a*Cos[d + e*x] + c*Sin[d + e*x]))/(2*e)}
{a + a*Cos[d + e*x] + c*Sin[d + e*x], x, 3, a*x - (c*Cos[d + e*x])/e + (a*Sin[d + e*x])/e}
{(a + a*Cos[d + e*x] + c*Sin[d + e*x])^(-1), x, 1, Log[a + c*Tan[(d + e*x)/2]]/(c*e)}
{(a + a*Cos[d + e*x] + c*Sin[d + e*x])^(-2), x, 3, -((a*Log[a + c*Tan[(d + e*x)/2]])/(c^3*e)) - (c*Cos[d + e*x] - a*Sin[d + e*x])/(c^2*e*(a + a*Cos[d + e*x] + c*Sin[d + e*x]))}
{(a + a*Cos[d + e*x] + c*Sin[d + e*x])^(-3), x, 3, ((3*a^2 + c^2)*Log[a + c*Tan[(d + e*x)/2]])/(2*c^5*e) - (c*Cos[d + e*x] - a*Sin[d + e*x])/(2*c^2*e*(a + a*Cos[d + e*x] + c*Sin[d + e*x])^2) + (3*(a*c*Cos[d + e*x] - a^2*Sin[d + e*x]))/(2*c^4*e*(a + a*Cos[d + e*x] + c*Sin[d + e*x]))}
{(a + a*Cos[d + e*x] + c*Sin[d + e*x])^(-4), x, 4, -(a*(5*a^2 + 3*c^2)*Log[a + c*Tan[(d + e*x)/2]])/(2*c^7*e) - (c*Cos[d + e*x] - a*Sin[d + e*x])/(3*c^2*e*(a + a*Cos[d + e*x] + c*Sin[d + e*x])^3) + (5*(a*c*Cos[d + e*x] - a^2*Sin[d + e*x]))/(6*c^4*e*(a + a*Cos[d + e*x] + c*Sin[d + e*x])^2) - (c*(15*a^2 + 4*c^2)*Cos[d + e*x] - a*(15*a^2 + 4*c^2)*Sin[d + e*x])/(6*c^6*e*(a + a*Cos[d + e*x] + c*Sin[d + e*x]))}


{(Sqrt[b^2 + c^2] + b*Cos[d + e*x] + c*Sin[d + e*x])^4, x, 6, (35*(b^2 + c^2)^2*x)/8 - (35*c*(b^2 + c^2)^(3/2)*Cos[d + e*x])/(8*e) + (35*b*(b^2 + c^2)^(3/2)*Sin[d + e*x])/(8*e) - (35*(b^2 + c^2)*(c*Cos[d + e*x] - b*Sin[d + e*x])*(Sqrt[b^2 + c^2] + b*Cos[d + e*x] + c*Sin[d + e*x]))/(24*e) - (7*Sqrt[b^2 + c^2]*(c*Cos[d + e*x] - b*Sin[d + e*x])*(Sqrt[b^2 + c^2] + b*Cos[d + e*x] + c*Sin[d + e*x])^2)/(12*e) - ((c*Cos[d + e*x] - b*Sin[d + e*x])*(Sqrt[b^2 + c^2] + b*Cos[d + e*x] + c*Sin[d + e*x])^3)/(4*e)}
{(Sqrt[b^2 + c^2] + b*Cos[d + e*x] + c*Sin[d + e*x])^3, x, 5, (5*(b^2 + c^2)^(3/2)*x)/2 - (5*c*(b^2 + c^2)*Cos[d + e*x])/(2*e) + (5*b*(b^2 + c^2)*Sin[d + e*x])/(2*e) - (5*Sqrt[b^2 + c^2]*(c*Cos[d + e*x] - b*Sin[d + e*x])*(Sqrt[b^2 + c^2] + b*Cos[d + e*x] + c*Sin[d + e*x]))/(6*e) - ((c*Cos[d + e*x] - b*Sin[d + e*x])*(Sqrt[b^2 + c^2] + b*Cos[d + e*x] + c*Sin[d + e*x])^2)/(3*e)}
{(Sqrt[b^2 + c^2] + b*Cos[d + e*x] + c*Sin[d + e*x])^2, x, 4, (3*(b^2 + c^2)*x)/2 - (3*c*Sqrt[b^2 + c^2]*Cos[d + e*x])/(2*e) + (3*b*Sqrt[b^2 + c^2]*Sin[d + e*x])/(2*e) - ((c*Cos[d + e*x] - b*Sin[d + e*x])*(Sqrt[b^2 + c^2] + b*Cos[d + e*x] + c*Sin[d + e*x]))/(2*e)}
{Sqrt[b^2 + c^2] + b*Cos[d + e*x] + c*Sin[d + e*x], x, 3, Sqrt[b^2 + c^2]*x - (c*Cos[d + e*x])/e + (b*Sin[d + e*x])/e}
{(Sqrt[b^2 + c^2] + b*Cos[d + e*x] + c*Sin[d + e*x])^(-1), x, 1, -((c - Sqrt[b^2 + c^2]*Sin[d + e*x])/(c*e*(c*Cos[d + e*x] - b*Sin[d + e*x])))}
{(Sqrt[b^2 + c^2] + b*Cos[d + e*x] + c*Sin[d + e*x])^(-2), x, 2, -(c*Cos[d + e*x] - b*Sin[d + e*x])/(3*Sqrt[b^2 + c^2]*e*(Sqrt[b^2 + c^2] + b*Cos[d + e*x] + c*Sin[d + e*x])^2) - (c - Sqrt[b^2 + c^2]*Sin[d + e*x])/(3*c*Sqrt[b^2 + c^2]*e*(c*Cos[d + e*x] - b*Sin[d + e*x]))}
{(Sqrt[b^2 + c^2] + b*Cos[d + e*x] + c*Sin[d + e*x])^(-3), x, 3, -(c*Cos[d + e*x] - b*Sin[d + e*x])/(5*Sqrt[b^2 + c^2]*e*(Sqrt[b^2 + c^2] + b*Cos[d + e*x] + c*Sin[d + e*x])^3) - (2*(c*Cos[d + e*x] - b*Sin[d + e*x]))/(15*(b^2 + c^2)*e*(Sqrt[b^2 + c^2] + b*Cos[d + e*x] + c*Sin[d + e*x])^2) - (2*(c - Sqrt[b^2 + c^2]*Sin[d + e*x]))/(15*c*(b^2 + c^2)*e*(c*Cos[d + e*x] - b*Sin[d + e*x]))}
{(Sqrt[b^2 + c^2] + b*Cos[d + e*x] + c*Sin[d + e*x])^(-4), x, 4, -(c*Cos[d + e*x] - b*Sin[d + e*x])/(7*Sqrt[b^2 + c^2]*e*(Sqrt[b^2 + c^2] + b*Cos[d + e*x] + c*Sin[d + e*x])^4) - (3*(c*Cos[d + e*x] - b*Sin[d + e*x]))/(35*(b^2 + c^2)*e*(Sqrt[b^2 + c^2] + b*Cos[d + e*x] + c*Sin[d + e*x])^3) - (2*(c*Cos[d + e*x] - b*Sin[d + e*x]))/(35*(b^2 + c^2)^(3/2)*e*(Sqrt[b^2 + c^2] + b*Cos[d + e*x] + c*Sin[d + e*x])^2) - (2*(c - Sqrt[b^2 + c^2]*Sin[d + e*x]))/(35*c*(b^2 + c^2)^(3/2)*e*(c*Cos[d + e*x] - b*Sin[d + e*x]))}


(* ::Subsubsection::Closed:: *)
(*Integrands of the form (a + b Cos[d+e x] + c Sin[d+e x])^(n/2)*)


{(2 + 3*Cos[d + e*x] + 5*Sin[d + e*x])^(5/2), x, 7, (796*Sqrt[2 + Sqrt[34]]*EllipticE[(d + e*x - ArcTan[5/3])/2, (2*(17 - Sqrt[34]))/15])/(15*e) + (64*EllipticF[(d + e*x - ArcTan[5/3])/2, (2*(17 - Sqrt[34]))/15])/(Sqrt[2 + Sqrt[34]]*e) - (32*(5*Cos[d + e*x] - 3*Sin[d + e*x])*Sqrt[2 + 3*Cos[d + e*x] + 5*Sin[d + e*x]])/(15*e) - (2*(5*Cos[d + e*x] - 3*Sin[d + e*x])*(2 + 3*Cos[d + e*x] + 5*Sin[d + e*x])^(3/2))/(5*e)}
{(2 + 3*Cos[d + e*x] + 5*Sin[d + e*x])^(3/2), x, 6, (16*Sqrt[2 + Sqrt[34]]*EllipticE[(d + e*x - ArcTan[5/3])/2, (2*(17 - Sqrt[34]))/15])/(3*e) + (20*EllipticF[(d + e*x - ArcTan[5/3])/2, (2*(17 - Sqrt[34]))/15])/(Sqrt[2 + Sqrt[34]]*e) - (2*(5*Cos[d + e*x] - 3*Sin[d + e*x])*Sqrt[2 + 3*Cos[d + e*x] + 5*Sin[d + e*x]])/(3*e)}
{Sqrt[2 + 3*Cos[d + e*x] + 5*Sin[d + e*x]], x, 2, (2*Sqrt[2 + Sqrt[34]]*EllipticE[(d + e*x - ArcTan[5/3])/2, (2*(17 - Sqrt[34]))/15])/e}
{1/Sqrt[2 + 3*Cos[d + e*x] + 5*Sin[d + e*x]], x, 2, (2*EllipticF[(d + e*x - ArcTan[5/3])/2, (2*(17 - Sqrt[34]))/15])/(Sqrt[2 + Sqrt[34]]*e)}
{(2 + 3*Cos[d + e*x] + 5*Sin[d + e*x])^(-3/2), x, 3, -(Sqrt[2 + Sqrt[34]]*EllipticE[(d + e*x - ArcTan[5/3])/2, (2*(17 - Sqrt[34]))/15])/(15*e) - (5*Cos[d + e*x] - 3*Sin[d + e*x])/(15*e*Sqrt[2 + 3*Cos[d + e*x] + 5*Sin[d + e*x]])}
{(2 + 3*Cos[d + e*x] + 5*Sin[d + e*x])^(-5/2), x, 7, (4*Sqrt[2 + Sqrt[34]]*EllipticE[(d + e*x - ArcTan[5/3])/2, (2*(17 - Sqrt[34]))/15])/(675*e) + EllipticF[(d + e*x - ArcTan[5/3])/2, (2*(17 - Sqrt[34]))/15]/(45*Sqrt[2 + Sqrt[34]]*e) - (5*Cos[d + e*x] - 3*Sin[d + e*x])/(45*e*(2 + 3*Cos[d + e*x] + 5*Sin[d + e*x])^(3/2)) + (4*(5*Cos[d + e*x] - 3*Sin[d + e*x]))/(675*e*Sqrt[2 + 3*Cos[d + e*x] + 5*Sin[d + e*x]])}
{(2 + 3*Cos[d + e*x] + 5*Sin[d + e*x])^(-7/2), x, 8, (-199*Sqrt[2 + Sqrt[34]]*EllipticE[(d + e*x - ArcTan[5/3])/2, (2*(17 - Sqrt[34]))/15])/(101250*e) - (8*EllipticF[(d + e*x - ArcTan[5/3])/2, (2*(17 - Sqrt[34]))/15])/(3375*Sqrt[2 + Sqrt[34]]*e) - (5*Cos[d + e*x] - 3*Sin[d + e*x])/(75*e*(2 + 3*Cos[d + e*x] + 5*Sin[d + e*x])^(5/2)) + (8*(5*Cos[d + e*x] - 3*Sin[d + e*x]))/(3375*e*(2 + 3*Cos[d + e*x] + 5*Sin[d + e*x])^(3/2)) - (199*(5*Cos[d + e*x] - 3*Sin[d + e*x]))/(101250*e*Sqrt[2 + 3*Cos[d + e*x] + 5*Sin[d + e*x]])}


{(a + b*Cos[d + e*x] + c*Sin[d + e*x])^(5/2), x, 7, (-16*(a*c*Cos[d + e*x] - a*b*Sin[d + e*x])*Sqrt[a + b*Cos[d + e*x] + c*Sin[d + e*x]])/(15*e) - (2*(c*Cos[d + e*x] - b*Sin[d + e*x])*(a + b*Cos[d + e*x] + c*Sin[d + e*x])^(3/2))/(5*e) + (2*(23*a^2 + 9*(b^2 + c^2))*EllipticE[(d + e*x - ArcTan[b, c])/2, (2*Sqrt[b^2 + c^2])/(a + Sqrt[b^2 + c^2])]*Sqrt[a + b*Cos[d + e*x] + c*Sin[d + e*x]])/(15*e*Sqrt[(a + b*Cos[d + e*x] + c*Sin[d + e*x])/(a + Sqrt[b^2 + c^2])]) - (16*a*(a^2 - b^2 - c^2)*EllipticF[(d + e*x - ArcTan[b, c])/2, (2*Sqrt[b^2 + c^2])/(a + Sqrt[b^2 + c^2])]*Sqrt[(a + b*Cos[d + e*x] + c*Sin[d + e*x])/(a + Sqrt[b^2 + c^2])])/(15*e*Sqrt[a + b*Cos[d + e*x] + c*Sin[d + e*x]])}
{(a + b*Cos[d + e*x] + c*Sin[d + e*x])^(3/2), x, 6, (-2*(c*Cos[d + e*x] - b*Sin[d + e*x])*Sqrt[a + b*Cos[d + e*x] + c*Sin[d + e*x]])/(3*e) + (8*a*EllipticE[(d + e*x - ArcTan[b, c])/2, (2*Sqrt[b^2 + c^2])/(a + Sqrt[b^2 + c^2])]*Sqrt[a + b*Cos[d + e*x] + c*Sin[d + e*x]])/(3*e*Sqrt[(a + b*Cos[d + e*x] + c*Sin[d + e*x])/(a + Sqrt[b^2 + c^2])]) - (2*(a^2 - b^2 - c^2)*EllipticF[(d + e*x - ArcTan[b, c])/2, (2*Sqrt[b^2 + c^2])/(a + Sqrt[b^2 + c^2])]*Sqrt[(a + b*Cos[d + e*x] + c*Sin[d + e*x])/(a + Sqrt[b^2 + c^2])])/(3*e*Sqrt[a + b*Cos[d + e*x] + c*Sin[d + e*x]])}
{Sqrt[a + b*Cos[d + e*x] + c*Sin[d + e*x]], x, 2, (2*EllipticE[(d + e*x - ArcTan[b, c])/2, (2*Sqrt[b^2 + c^2])/(a + Sqrt[b^2 + c^2])]*Sqrt[a + b*Cos[d + e*x] + c*Sin[d + e*x]])/(e*Sqrt[(a + b*Cos[d + e*x] + c*Sin[d + e*x])/(a + Sqrt[b^2 + c^2])])}
{1/Sqrt[a + b*Cos[d + e*x] + c*Sin[d + e*x]], x, 2, (2*EllipticF[(d + e*x - ArcTan[b, c])/2, (2*Sqrt[b^2 + c^2])/(a + Sqrt[b^2 + c^2])]*Sqrt[(a + b*Cos[d + e*x] + c*Sin[d + e*x])/(a + Sqrt[b^2 + c^2])])/(e*Sqrt[a + b*Cos[d + e*x] + c*Sin[d + e*x]])}
{(a + b*Cos[d + e*x] + c*Sin[d + e*x])^(-3/2), x, 3, (2*(c*Cos[d + e*x] - b*Sin[d + e*x]))/((a^2 - b^2 - c^2)*e*Sqrt[a + b*Cos[d + e*x] + c*Sin[d + e*x]]) + (2*EllipticE[(d + e*x - ArcTan[b, c])/2, (2*Sqrt[b^2 + c^2])/(a + Sqrt[b^2 + c^2])]*Sqrt[a + b*Cos[d + e*x] + c*Sin[d + e*x]])/((a^2 - b^2 - c^2)*e*Sqrt[(a + b*Cos[d + e*x] + c*Sin[d + e*x])/(a + Sqrt[b^2 + c^2])])}
{(a + b*Cos[d + e*x] + c*Sin[d + e*x])^(-5/2), x, 7, (2*(c*Cos[d + e*x] - b*Sin[d + e*x]))/(3*(a^2 - b^2 - c^2)*e*(a + b*Cos[d + e*x] + c*Sin[d + e*x])^(3/2)) + (8*(a*c*Cos[d + e*x] - a*b*Sin[d + e*x]))/(3*(a^2 - b^2 - c^2)^2*e*Sqrt[a + b*Cos[d + e*x] + c*Sin[d + e*x]]) + (8*a*EllipticE[(d + e*x - ArcTan[b, c])/2, (2*Sqrt[b^2 + c^2])/(a + Sqrt[b^2 + c^2])]*Sqrt[a + b*Cos[d + e*x] + c*Sin[d + e*x]])/(3*(a^2 - b^2 - c^2)^2*e*Sqrt[(a + b*Cos[d + e*x] + c*Sin[d + e*x])/(a + Sqrt[b^2 + c^2])]) - (2*EllipticF[(d + e*x - ArcTan[b, c])/2, (2*Sqrt[b^2 + c^2])/(a + Sqrt[b^2 + c^2])]*Sqrt[(a + b*Cos[d + e*x] + c*Sin[d + e*x])/(a + Sqrt[b^2 + c^2])])/(3*(a^2 - b^2 - c^2)*e*Sqrt[a + b*Cos[d + e*x] + c*Sin[d + e*x]])}
{(a + b*Cos[d + e*x] + c*Sin[d + e*x])^(-7/2), x, 8, (2*(c*Cos[d + e*x] - b*Sin[d + e*x]))/(5*(a^2 - b^2 - c^2)*e*(a + b*Cos[d + e*x] + c*Sin[d + e*x])^(5/2)) + (16*(a*c*Cos[d + e*x] - a*b*Sin[d + e*x]))/(15*(a^2 - b^2 - c^2)^2*e*(a + b*Cos[d + e*x] + c*Sin[d + e*x])^(3/2)) + (2*(23*a^2 + 9*(b^2 + c^2))*EllipticE[(d + e*x - ArcTan[b, c])/2, (2*Sqrt[b^2 + c^2])/(a + Sqrt[b^2 + c^2])]*Sqrt[a + b*Cos[d + e*x] + c*Sin[d + e*x]])/(15*(a^2 - b^2 - c^2)^3*e*Sqrt[(a + b*Cos[d + e*x] + c*Sin[d + e*x])/(a + Sqrt[b^2 + c^2])]) - (16*a*EllipticF[(d + e*x - ArcTan[b, c])/2, (2*Sqrt[b^2 + c^2])/(a + Sqrt[b^2 + c^2])]*Sqrt[(a + b*Cos[d + e*x] + c*Sin[d + e*x])/(a + Sqrt[b^2 + c^2])])/(15*(a^2 - b^2 - c^2)^2*e*Sqrt[a + b*Cos[d + e*x] + c*Sin[d + e*x]]) + (2*(c*(23*a^2 + 9*(b^2 + c^2))*Cos[d + e*x] - b*(23*a^2 + 9*(b^2 + c^2))*Sin[d + e*x]))/(15*(a^2 - b^2 - c^2)^3*e*Sqrt[a + b*Cos[d + e*x] + c*Sin[d + e*x]])}


{(5 + 4*Cos[d + e*x] + 3*Sin[d + e*x])^(5/2), x, 3, (-320*(3*Cos[d + e*x] - 4*Sin[d + e*x]))/(3*e*Sqrt[5 + 4*Cos[d + e*x] + 3*Sin[d + e*x]]) - (16*(3*Cos[d + e*x] - 4*Sin[d + e*x])*Sqrt[5 + 4*Cos[d + e*x] + 3*Sin[d + e*x]])/(3*e) - (2*(3*Cos[d + e*x] - 4*Sin[d + e*x])*(5 + 4*Cos[d + e*x] + 3*Sin[d + e*x])^(3/2))/(5*e)}
{(5 + 4*Cos[d + e*x] + 3*Sin[d + e*x])^(3/2), x, 2, (-40*(3*Cos[d + e*x] - 4*Sin[d + e*x]))/(3*e*Sqrt[5 + 4*Cos[d + e*x] + 3*Sin[d + e*x]]) - (2*(3*Cos[d + e*x] - 4*Sin[d + e*x])*Sqrt[5 + 4*Cos[d + e*x] + 3*Sin[d + e*x]])/(3*e)}
{Sqrt[5 + 4*Cos[d + e*x] + 3*Sin[d + e*x]], x, 1, (-2*(3*Cos[d + e*x] - 4*Sin[d + e*x]))/(e*Sqrt[5 + 4*Cos[d + e*x] + 3*Sin[d + e*x]])}
{1/Sqrt[5 + 4*Cos[d + e*x] + 3*Sin[d + e*x]], x, 2, (2*ArcTanh[Sin[(d + e*x - ArcTan[3/4])/2]]*Cos[(d + e*x - ArcTan[3/4])/2])/(Sqrt[5]*e*Sqrt[1 + Cos[d + e*x - ArcTan[3/4]]])}
{(5 + 4*Cos[d + e*x] + 3*Sin[d + e*x])^(-3/2), x, 3, (ArcTanh[Sin[(d + e*x - ArcTan[3/4])/2]]*Cos[(d + e*x - ArcTan[3/4])/2])/(10*Sqrt[5]*e*Sqrt[1 + Cos[d + e*x - ArcTan[3/4]]]) - (3*Cos[d + e*x] - 4*Sin[d + e*x])/(10*e*(5 + 4*Cos[d + e*x] + 3*Sin[d + e*x])^(3/2))}
{(5 + 4*Cos[d + e*x] + 3*Sin[d + e*x])^(-5/2), x, 4, (3*ArcTanh[Sin[(d + e*x - ArcTan[3/4])/2]]*Cos[(d + e*x - ArcTan[3/4])/2])/(400*Sqrt[5]*e*Sqrt[1 + Cos[d + e*x - ArcTan[3/4]]]) - (3*Cos[d + e*x] - 4*Sin[d + e*x])/(20*e*(5 + 4*Cos[d + e*x] + 3*Sin[d + e*x])^(5/2)) - (3*(3*Cos[d + e*x] - 4*Sin[d + e*x]))/(400*e*(5 + 4*Cos[d + e*x] + 3*Sin[d + e*x])^(3/2))}


{(-5 + 4*Cos[d + e*x] + 3*Sin[d + e*x])^(7/2), x, 4, (6400*(3*Cos[d + e*x] - 4*Sin[d + e*x]))/(7*e*Sqrt[-5 + 4*Cos[d + e*x] + 3*Sin[d + e*x]]) - (320*(3*Cos[d + e*x] - 4*Sin[d + e*x])*Sqrt[-5 + 4*Cos[d + e*x] + 3*Sin[d + e*x]])/(7*e) + (24*(3*Cos[d + e*x] - 4*Sin[d + e*x])*(-5 + 4*Cos[d + e*x] + 3*Sin[d + e*x])^(3/2))/(7*e) - (2*(3*Cos[d + e*x] - 4*Sin[d + e*x])*(-5 + 4*Cos[d + e*x] + 3*Sin[d + e*x])^(5/2))/(7*e)}
{(-5 + 4*Cos[d + e*x] + 3*Sin[d + e*x])^(5/2), x, 3, (-320*(3*Cos[d + e*x] - 4*Sin[d + e*x]))/(3*e*Sqrt[-5 + 4*Cos[d + e*x] + 3*Sin[d + e*x]]) + (16*(3*Cos[d + e*x] - 4*Sin[d + e*x])*Sqrt[-5 + 4*Cos[d + e*x] + 3*Sin[d + e*x]])/(3*e) - (2*(3*Cos[d + e*x] - 4*Sin[d + e*x])*(-5 + 4*Cos[d + e*x] + 3*Sin[d + e*x])^(3/2))/(5*e)}
{(-5 + 4*Cos[d + e*x] + 3*Sin[d + e*x])^(3/2), x, 2, (40*(3*Cos[d + e*x] - 4*Sin[d + e*x]))/(3*e*Sqrt[-5 + 4*Cos[d + e*x] + 3*Sin[d + e*x]]) - (2*(3*Cos[d + e*x] - 4*Sin[d + e*x])*Sqrt[-5 + 4*Cos[d + e*x] + 3*Sin[d + e*x]])/(3*e)}
{Sqrt[-5 + 4*Cos[d + e*x] + 3*Sin[d + e*x]], x, 1, (-2*(3*Cos[d + e*x] - 4*Sin[d + e*x]))/(e*Sqrt[-5 + 4*Cos[d + e*x] + 3*Sin[d + e*x]])}
{1/Sqrt[-5 + 4*Cos[d + e*x] + 3*Sin[d + e*x]], x, 2, (-2*ArcTanh[Cos[(d + e*x - ArcTan[3/4])/2]]*Sin[(d + e*x - ArcTan[3/4])/2])/(Sqrt[5]*e*Sqrt[-1 + Cos[d + e*x - ArcTan[3/4]]])}
{(-5 + 4*Cos[d + e*x] + 3*Sin[d + e*x])^(-3/2), x, 3, (3*Cos[d + e*x] - 4*Sin[d + e*x])/(10*e*(-5 + 4*Cos[d + e*x] + 3*Sin[d + e*x])^(3/2)) + (ArcTanh[Cos[(d + e*x - ArcTan[3/4])/2]]*Sin[(d + e*x - ArcTan[3/4])/2])/(10*Sqrt[5]*e*Sqrt[-1 + Cos[d + e*x - ArcTan[3/4]]])}
{(-5 + 4*Cos[d + e*x] + 3*Sin[d + e*x])^(-5/2), x, 4, (3*Cos[d + e*x] - 4*Sin[d + e*x])/(20*e*(-5 + 4*Cos[d + e*x] + 3*Sin[d + e*x])^(5/2)) - (3*(3*Cos[d + e*x] - 4*Sin[d + e*x]))/(400*e*(-5 + 4*Cos[d + e*x] + 3*Sin[d + e*x])^(3/2)) - (3*ArcTanh[Cos[(d + e*x - ArcTan[3/4])/2]]*Sin[(d + e*x - ArcTan[3/4])/2])/(400*Sqrt[5]*e*Sqrt[-1 + Cos[d + e*x - ArcTan[3/4]]])}


{(Sqrt[b^2 + c^2] + b*Cos[d + e*x] + c*Sin[d + e*x])^(7/2), x, 4, (-256*(b^2 + c^2)^(3/2)*(c*Cos[d + e*x] - b*Sin[d + e*x]))/(35*e*Sqrt[Sqrt[b^2 + c^2] + b*Cos[d + e*x] + c*Sin[d + e*x]]) - (64*(b^2 + c^2)*(c*Cos[d + e*x] - b*Sin[d + e*x])*Sqrt[Sqrt[b^2 + c^2] + b*Cos[d + e*x] + c*Sin[d + e*x]])/(35*e) - (24*Sqrt[b^2 + c^2]*(c*Cos[d + e*x] - b*Sin[d + e*x])*(Sqrt[b^2 + c^2] + b*Cos[d + e*x] + c*Sin[d + e*x])^(3/2))/(35*e) - (2*(c*Cos[d + e*x] - b*Sin[d + e*x])*(Sqrt[b^2 + c^2] + b*Cos[d + e*x] + c*Sin[d + e*x])^(5/2))/(7*e)}
{(Sqrt[b^2 + c^2] + b*Cos[d + e*x] + c*Sin[d + e*x])^(5/2), x, 3, (-64*(b^2 + c^2)*(c*Cos[d + e*x] - b*Sin[d + e*x]))/(15*e*Sqrt[Sqrt[b^2 + c^2] + b*Cos[d + e*x] + c*Sin[d + e*x]]) - (16*Sqrt[b^2 + c^2]*(c*Cos[d + e*x] - b*Sin[d + e*x])*Sqrt[Sqrt[b^2 + c^2] + b*Cos[d + e*x] + c*Sin[d + e*x]])/(15*e) - (2*(c*Cos[d + e*x] - b*Sin[d + e*x])*(Sqrt[b^2 + c^2] + b*Cos[d + e*x] + c*Sin[d + e*x])^(3/2))/(5*e)}
{(Sqrt[b^2 + c^2] + b*Cos[d + e*x] + c*Sin[d + e*x])^(3/2), x, 2, (-8*Sqrt[b^2 + c^2]*(c*Cos[d + e*x] - b*Sin[d + e*x]))/(3*e*Sqrt[Sqrt[b^2 + c^2] + b*Cos[d + e*x] + c*Sin[d + e*x]]) - (2*(c*Cos[d + e*x] - b*Sin[d + e*x])*Sqrt[Sqrt[b^2 + c^2] + b*Cos[d + e*x] + c*Sin[d + e*x]])/(3*e)}
{Sqrt[Sqrt[b^2 + c^2] + b*Cos[d + e*x] + c*Sin[d + e*x]], x, 1, (-2*(c*Cos[d + e*x] - b*Sin[d + e*x]))/(e*Sqrt[Sqrt[b^2 + c^2] + b*Cos[d + e*x] + c*Sin[d + e*x]])}
{1/Sqrt[Sqrt[b^2 + c^2] + b*Cos[d + e*x] + c*Sin[d + e*x]], x, 2, (2*ArcTanh[Sin[(d + e*x - ArcTan[b, c])/2]]*Cos[(d + e*x - ArcTan[b, c])/2])/(e*Sqrt[Sqrt[b^2 + c^2] + Sqrt[b^2 + c^2]*Cos[d + e*x - ArcTan[b, c]]])}
{(Sqrt[b^2 + c^2] + b*Cos[d + e*x] + c*Sin[d + e*x])^(-3/2), x, 3, (ArcTanh[Sin[(d + e*x - ArcTan[b, c])/2]]*Cos[(d + e*x - ArcTan[b, c])/2])/(2*Sqrt[b^2 + c^2]*e*Sqrt[Sqrt[b^2 + c^2] + Sqrt[b^2 + c^2]*Cos[d + e*x - ArcTan[b, c]]]) - (c*Cos[d + e*x] - b*Sin[d + e*x])/(2*Sqrt[b^2 + c^2]*e*(Sqrt[b^2 + c^2] + b*Cos[d + e*x] + c*Sin[d + e*x])^(3/2))}
{(Sqrt[b^2 + c^2] + b*Cos[d + e*x] + c*Sin[d + e*x])^(-5/2), x, 4, (3*ArcTanh[Sin[(d + e*x - ArcTan[b, c])/2]]*Cos[(d + e*x - ArcTan[b, c])/2])/(16*(b^2 + c^2)*e*Sqrt[Sqrt[b^2 + c^2] + Sqrt[b^2 + c^2]*Cos[d + e*x - ArcTan[b, c]]]) - (c*Cos[d + e*x] - b*Sin[d + e*x])/(4*Sqrt[b^2 + c^2]*e*(Sqrt[b^2 + c^2] + b*Cos[d + e*x] + c*Sin[d + e*x])^(5/2)) - (3*(c*Cos[d + e*x] - b*Sin[d + e*x]))/(16*(b^2 + c^2)*e*(Sqrt[b^2 + c^2] + b*Cos[d + e*x] + c*Sin[d + e*x])^(3/2))}


{(-Sqrt[b^2 + c^2] + b*Cos[d + e*x] + c*Sin[d + e*x])^(5/2), x, 3, (-64*(b^2 + c^2)*(c*Cos[d + e*x] - b*Sin[d + e*x]))/(15*e*Sqrt[-Sqrt[b^2 + c^2] + b*Cos[d + e*x] + c*Sin[d + e*x]]) + (16*Sqrt[b^2 + c^2]*(c*Cos[d + e*x] - b*Sin[d + e*x])*Sqrt[-Sqrt[b^2 + c^2] + b*Cos[d + e*x] + c*Sin[d + e*x]])/(15*e) - (2*(c*Cos[d + e*x] - b*Sin[d + e*x])*(-Sqrt[b^2 + c^2] + b*Cos[d + e*x] + c*Sin[d + e*x])^(3/2))/(5*e)}
{(-Sqrt[b^2 + c^2] + b*Cos[d + e*x] + c*Sin[d + e*x])^(3/2), x, 2, (8*Sqrt[b^2 + c^2]*(c*Cos[d + e*x] - b*Sin[d + e*x]))/(3*e*Sqrt[-Sqrt[b^2 + c^2] + b*Cos[d + e*x] + c*Sin[d + e*x]]) - (2*(c*Cos[d + e*x] - b*Sin[d + e*x])*Sqrt[-Sqrt[b^2 + c^2] + b*Cos[d + e*x] + c*Sin[d + e*x]])/(3*e)}
{Sqrt[-Sqrt[b^2 + c^2] + b*Cos[d + e*x] + c*Sin[d + e*x]], x, 1, (-2*(c*Cos[d + e*x] - b*Sin[d + e*x]))/(e*Sqrt[-Sqrt[b^2 + c^2] + b*Cos[d + e*x] + c*Sin[d + e*x]])}
{1/Sqrt[-Sqrt[b^2 + c^2] + b*Cos[d + e*x] + c*Sin[d + e*x]], x, 2, (-2*ArcTanh[Cos[(d + e*x - ArcTan[b, c])/2]]*Sin[(d + e*x - ArcTan[b, c])/2])/(e*Sqrt[-Sqrt[b^2 + c^2] + Sqrt[b^2 + c^2]*Cos[d + e*x - ArcTan[b, c]]])}
{(-Sqrt[b^2 + c^2] + b*Cos[d + e*x] + c*Sin[d + e*x])^(-3/2), x, 3, (c*Cos[d + e*x] - b*Sin[d + e*x])/(2*Sqrt[b^2 + c^2]*e*(-Sqrt[b^2 + c^2] + b*Cos[d + e*x] + c*Sin[d + e*x])^(3/2)) + (ArcTanh[Cos[(d + e*x - ArcTan[b, c])/2]]*Sin[(d + e*x - ArcTan[b, c])/2])/(2*Sqrt[b^2 + c^2]*e*Sqrt[-Sqrt[b^2 + c^2] + Sqrt[b^2 + c^2]*Cos[d + e*x - ArcTan[b, c]]])}
{(-Sqrt[b^2 + c^2] + b*Cos[d + e*x] + c*Sin[d + e*x])^(-5/2), x, 4, (c*Cos[d + e*x] - b*Sin[d + e*x])/(4*Sqrt[b^2 + c^2]*e*(-Sqrt[b^2 + c^2] + b*Cos[d + e*x] + c*Sin[d + e*x])^(5/2)) - (3*(c*Cos[d + e*x] - b*Sin[d + e*x]))/(16*(b^2 + c^2)*e*(-Sqrt[b^2 + c^2] + b*Cos[d + e*x] + c*Sin[d + e*x])^(3/2)) - (3*ArcTanh[Cos[(d + e*x - ArcTan[b, c])/2]]*Sin[(d + e*x - ArcTan[b, c])/2])/(16*(b^2 + c^2)*e*Sqrt[-Sqrt[b^2 + c^2] + Sqrt[b^2 + c^2]*Cos[d + e*x - ArcTan[b, c]]])}


(* ::Subsection::Closed:: *)
(*Integrands of the form (a + b Tan[d+e x] + c Sec[d+e x])^n*)


{1/(a + b*Tan[x] + c*Sec[x]), x, -9, (a*x)/(a^2 + b^2) + (2*a*c*ArcTanh[(b + (-a + c)*Tan[x/2])/Sqrt[a^2 + b^2 - c^2]])/((a^2 + b^2)*Sqrt[a^2 + b^2 - c^2]) + (b*Log[c + a*Cos[x] + b*Sin[x]])/(a^2 + b^2)}
{1/(a + b*Cot[x] + c*Csc[x]), x, -9, (a*x)/(a^2 + b^2) + (2*a*c*ArcTanh[(a + (-b + c)*Tan[x/2])/Sqrt[a^2 + b^2 - c^2]])/((a^2 + b^2)*Sqrt[a^2 + b^2 - c^2]) - (b*Log[c + b*Cos[x] + a*Sin[x]])/(a^2 + b^2)}


(* ::Section::Closed:: *)
(*Integrands of the form (a Trig[c+d x]^2 + b Trig[c+d x]^2)^n*)


(* ::Subsection::Closed:: *)
(*Integrands of the form (a Cos[c+d x]^2 + b Sin[c+d x]^2)^n*)


{1/(Cos[x]^2 + Sin[x]^2), x, 2, x}
{1/(Cos[x]^2 + Sin[x]^2)^2, x, 2, x}
{1/(Cos[x]^2 + Sin[x]^2)^3, x, 2, x}

{1/(Cos[x]^2 - Sin[x]^2), x, 3, ArcTanh[Tan[x]]}
{1/(Cos[x]^2 - Sin[x]^2)^2, x, 3, Tan[x]/(1 - Tan[x]^2)}
{1/(Cos[x]^2 - Sin[x]^2)^3, x, 5, (1/2)*ArcTanh[Tan[x]] + (Tan[x]*(1 + Tan[x]^2))/(2*(1 - Tan[x]^2)^2)}


{1/(Cos[x]^2 + a^2*Sin[x]^2), x, 3, ArcTan[a*Tan[x]]/a}
{1/(b^2*Cos[x]^2 + Sin[x]^2), x, 3, ArcTan[Tan[x]/b]/b}
{1/(b^2*Cos[x]^2 + a^2*Sin[x]^2), x, 3, ArcTan[(a*Tan[x])/b]/(a*b)}
{1/(4*Cos[1 + 2*x]^2 + 3*Sin[1 + 2*x]^2), x, 3, ArcTan[(1/2)*Sqrt[3]*Tan[1 + 2*x]]/(4*Sqrt[3])}


(* ::Subsection::Closed:: *)
(*Integrands of the form (a Sec[c+d x]^2 + b Tan[c+d x]^2)^n*)


{1/(Sec[x]^2 + Tan[x]^2), x, 5, -x + Sqrt[2]*ArcTan[Sqrt[2]*Tan[x]]}
{1/(Sec[x]^2 + Tan[x]^2)^2, x, 7, x - ArcTan[Sqrt[2]*Tan[x]]/Sqrt[2] + Tan[x]/(1 + 2*Tan[x]^2)}
{1/(Sec[x]^2 + Tan[x]^2)^3, x, 7, -x + (7*ArcTan[Sqrt[2]*Tan[x]])/(4*Sqrt[2]) + Tan[x]/(2*(1 + 2*Tan[x]^2)^2) - Tan[x]/(4*(1 + 2*Tan[x]^2))}

{1/(Sec[x]^2 - Tan[x]^2), x, 2, x}
{1/(Sec[x]^2 - Tan[x]^2)^2, x, 2, x}
{1/(Sec[x]^2 - Tan[x]^2)^3, x, 2, x}


(* ::Subsection::Closed:: *)
(*Integrands of the form (a Cot[c+d x]^2 + b Csc[c+d x]^2)^n*)


{1/(Cot[x]^2 + Csc[x]^2), x, 5, -x - Sqrt[2]*ArcTan[Sqrt[2]*Cot[x]]}
{1/(Cot[x]^2 + Csc[x]^2)^2, x, 7, x + ArcTan[Sqrt[2]*Cot[x]]/Sqrt[2] - Cot[x]/(1 + 2*Cot[x]^2)}
{1/(Cot[x]^2 + Csc[x]^2)^3, x, 7, -x - (7*ArcTan[Sqrt[2]*Cot[x]])/(4*Sqrt[2]) - Cot[x]/(2*(1 + 2*Cot[x]^2)^2) + Cot[x]/(4*(1 + 2*Cot[x]^2))}

{1/(Cot[x]^2 - Csc[x]^2), x, 2, -x}
{1/(Cot[x]^2 - Csc[x]^2)^2, x, 2, x}
{1/(Cot[x]^2 - Csc[x]^2)^3, x, 2, -x}


(* ::Section::Closed:: *)
(*Integrands of the form x^m (a + b Trig[d+e x]^n + c Trig[d+e x]^n)^p*)


{1/(a + b*Cos[x]^2 + c*Sin[x]^2), x, 3, ArcTan[(Sqrt[a + c]*Tan[x])/Sqrt[a + b]]/(Sqrt[a + b]*Sqrt[a + c])}
{x/(a + b*Cos[x]^2 + c*Sin[x]^2), x, 9, -((I*x*Log[1 + ((b - c)*E^(2*I*x))/(2*a + b + c - 2*Sqrt[a + b]*Sqrt[a + c])])/(2*Sqrt[a + b]*Sqrt[a + c])) + (I*x*Log[1 + ((b - c)*E^(2*I*x))/(2*a + b + c + 2*Sqrt[a + b]*Sqrt[a + c])])/(2*Sqrt[a + b]*Sqrt[a + c]) - PolyLog[2, -(((b - c)*E^(2*I*x))/(2*a + b + c - 2*Sqrt[a + b]*Sqrt[a + c]))]/(4*Sqrt[a + b]*Sqrt[a + c]) + PolyLog[2, -(((b - c)*E^(2*I*x))/(2*a + b + c + 2*Sqrt[a + b]*Sqrt[a + c]))]/(4*Sqrt[a + b]*Sqrt[a + c])}
{x^2/(a + b*Cos[x]^2 + c*Sin[x]^2), x, 11, -((I*x^2*Log[1 + ((b - c)*E^(2*I*x))/(2*a + b + c - 2*Sqrt[a + b]*Sqrt[a + c])])/(2*Sqrt[a + b]*Sqrt[a + c])) + (I*x^2*Log[1 + ((b - c)*E^(2*I*x))/(2*a + b + c + 2*Sqrt[a + b]*Sqrt[a + c])])/(2*Sqrt[a + b]*Sqrt[a + c]) - (x*PolyLog[2, -(((b - c)*E^(2*I*x))/(2*a + b + c - 2*Sqrt[a + b]*Sqrt[a + c]))])/(2*Sqrt[a + b]*Sqrt[a + c]) + (x*PolyLog[2, -(((b - c)*E^(2*I*x))/(2*a + b + c + 2*Sqrt[a + b]*Sqrt[a + c]))])/(2*Sqrt[a + b]*Sqrt[a + c]) - (I*PolyLog[3, -(((b - c)*E^(2*I*x))/(2*a + b + c - 2*Sqrt[a + b]*Sqrt[a + c]))])/(4*Sqrt[a + b]*Sqrt[a + c]) + (I*PolyLog[3, -(((b - c)*E^(2*I*x))/(2*a + b + c + 2*Sqrt[a + b]*Sqrt[a + c]))])/(4*Sqrt[a + b]*Sqrt[a + c])}
(* {x^3/(a + b*Cos[x]^2 + c*Sin[x]^2), x, 13, -((I*x^3*Log[1 + ((b - c)*E^(2*I*x))/(2*a + b + c - 2*Sqrt[a + b]*Sqrt[a + c])])/(2*Sqrt[a + b]*Sqrt[a + c])) + (I*x^3*Log[1 + ((b - c)*E^(2*I*x))/(2*a + b + c + 2*Sqrt[a + b]*Sqrt[a + c])])/(2*Sqrt[a + b]*Sqrt[a + c]) - (3*x^2*PolyLog[2, -(((b - c)*E^(2*I*x))/(2*a + b + c - 2*Sqrt[a + b]*Sqrt[a + c]))])/(4*Sqrt[a + b]*Sqrt[a + c]) + (3*x^2*PolyLog[2, -(((b - c)*E^(2*I*x))/(2*a + b + c + 2*Sqrt[a + b]*Sqrt[a + c]))])/(4*Sqrt[a + b]*Sqrt[a + c]) - (3*I*x*PolyLog[3, -(((b - c)*E^(2*I*x))/(2*a + b + c - 2*Sqrt[a + b]*Sqrt[a + c]))])/(4*Sqrt[a + b]*Sqrt[a + c]) + (3*I*x*PolyLog[3, -(((b - c)*E^(2*I*x))/(2*a + b + c + 2*Sqrt[a + b]*Sqrt[a + c]))])/(4*Sqrt[a + b]*Sqrt[a + c]) + (3*PolyLog[4, -(((b - c)*E^(2*I*x))/(2*a + b + c - 2*Sqrt[a + b]*Sqrt[a + c]))])/(8*Sqrt[a + b]*Sqrt[a + c]) - (3*PolyLog[4, -(((b - c)*E^(2*I*x))/(2*a + b + c + 2*Sqrt[a + b]*Sqrt[a + c]))])/(8*Sqrt[a + b]*Sqrt[a + c])} *)


(* ::Section::Closed:: *)
(*Miscellaneous integrands involving two trig functions*)


{1/(a + b*Sin[x]*Cos[x]), x, 2, (2*ArcTan[(b + 2*a*Tan[x])/Sqrt[4*a^2 - b^2]])/Sqrt[4*a^2 - b^2]}
{x/(a + b*Sin[x]*Cos[x]), x, 9, -((I*x*Log[1 - (I*b*E^(2*I*x))/(2*a - Sqrt[4*a^2 - b^2])])/Sqrt[4*a^2 - b^2]) + (I*x*Log[1 - (I*b*E^(2*I*x))/(2*a + Sqrt[4*a^2 - b^2])])/Sqrt[4*a^2 - b^2] - PolyLog[2, (I*b*E^(2*I*x))/(2*a - Sqrt[4*a^2 - b^2])]/(2*Sqrt[4*a^2 - b^2]) + PolyLog[2, (I*b*E^(2*I*x))/(2*a + Sqrt[4*a^2 - b^2])]/(2*Sqrt[4*a^2 - b^2])}
{x^2/(a + b*Sin[x]*Cos[x]), x, 11, -((I*x^2*Log[1 - (I*b*E^(2*I*x))/(2*a - Sqrt[4*a^2 - b^2])])/Sqrt[4*a^2 - b^2]) + (I*x^2*Log[1 - (I*b*E^(2*I*x))/(2*a + Sqrt[4*a^2 - b^2])])/Sqrt[4*a^2 - b^2] - (x*PolyLog[2, (I*b*E^(2*I*x))/(2*a - Sqrt[4*a^2 - b^2])])/Sqrt[4*a^2 - b^2] + (x*PolyLog[2, (I*b*E^(2*I*x))/(2*a + Sqrt[4*a^2 - b^2])])/Sqrt[4*a^2 - b^2] - (I*PolyLog[3, (I*b*E^(2*I*x))/(2*a - Sqrt[4*a^2 - b^2])])/(2*Sqrt[4*a^2 - b^2]) + (I*PolyLog[3, (I*b*E^(2*I*x))/(2*a + Sqrt[4*a^2 - b^2])])/(2*Sqrt[4*a^2 - b^2])}
{x^3/(a + b*Sin[x]*Cos[x]), x, 13, -((I*x^3*Log[1 - (I*b*E^(2*I*x))/(2*a - Sqrt[4*a^2 - b^2])])/Sqrt[4*a^2 - b^2]) + (I*x^3*Log[1 - (I*b*E^(2*I*x))/(2*a + Sqrt[4*a^2 - b^2])])/Sqrt[4*a^2 - b^2] - (3*x^2*PolyLog[2, (I*b*E^(2*I*x))/(2*a - Sqrt[4*a^2 - b^2])])/(2*Sqrt[4*a^2 - b^2]) + (3*x^2*PolyLog[2, (I*b*E^(2*I*x))/(2*a + Sqrt[4*a^2 - b^2])])/(2*Sqrt[4*a^2 - b^2]) - (3*I*x*PolyLog[3, (I*b*E^(2*I*x))/(2*a - Sqrt[4*a^2 - b^2])])/(2*Sqrt[4*a^2 - b^2]) + (3*I*x*PolyLog[3, (I*b*E^(2*I*x))/(2*a + Sqrt[4*a^2 - b^2])])/(2*Sqrt[4*a^2 - b^2]) + (3*PolyLog[4, (I*b*E^(2*I*x))/(2*a - Sqrt[4*a^2 - b^2])])/(4*Sqrt[4*a^2 - b^2]) - (3*PolyLog[4, (I*b*E^(2*I*x))/(2*a + Sqrt[4*a^2 - b^2])])/(4*Sqrt[4*a^2 - b^2])}


{Sqrt[a + b*Sin[x]*Cos[x]], x, 3, -(((2*a + b)*EllipticE[Pi/4 - x, (2*b)/(2*a + b)]*Sqrt[(2*a + b*Sin[2*x])/(2*a + b)])/(Sqrt[2]*Sqrt[2*a + b*Sin[2*x]]))}
{1/Sqrt[a + b*Sin[x]*Cos[x]], x, 3, -((Sqrt[2]*EllipticF[Pi/4 - x, (2*b)/(2*a + b)]*Sqrt[(2*a + b*Sin[2*x])/(2*a + b)])/Sqrt[2*a + b*Sin[2*x]])}


{(Cot[Sqrt[x]]*Csc[Sqrt[x]])/Sqrt[x], x, 2, -2*Csc[Sqrt[x]]}
{(Cos[Sqrt[x]]*Sin[Sqrt[x]])/Sqrt[x], x, 1, Sin[Sqrt[x]]^2}
{(Sec[Sqrt[x]]*Tan[Sqrt[x]])/Sqrt[x], x, 2, 2*Sec[Sqrt[x]]}


{Tan[c+d*x]/Sqrt[a*Sin[c+d*x]^2], x, 3, ArcTanh[Sqrt[a - a*Cos[c + d*x]^2]/Sqrt[a]]/(Sqrt[a]*d)}
{Cot[c+d*x]/Sqrt[a*Cos[c+d*x]^2], x, 3, -(ArcTanh[Sqrt[a - a*Sin[c + d*x]^2]/Sqrt[a]]/(Sqrt[a]*d))}


{(x*Cos[x^2])/Sqrt[Sin[x^2]], x, 1, Sqrt[Sin[x^2]]}


{Cos[x]/Sqrt[1 - Cos[2*x]], x, 4, (Log[Sin[x]]*Sin[x])/(Sqrt[2]*Sqrt[Sin[x]^2])}


{Sqrt[(1 - Cos[x])/(a - Cos[x])], x, 4, (-Sqrt[2])*ArcTan[(Sqrt[2]*Cos[x/2])/Sqrt[1 + a - 2*Cos[x/2]^2]]*Sqrt[(1 - Cos[x])/(a - Cos[x])]*Sqrt[a - Cos[x]]*Csc[x/2]}


{Sin[x]^2/(a + b*Sin[2*x]), x, 5, ArcTan[(b + a*Tan[x])/Sqrt[a^2 - b^2]]/(2*Sqrt[a^2 - b^2]) - Log[a + b*Sin[2*x]]/(4*b)}
{Cos[x]^2/(a + b*Sin[2*x]), x, 5, ArcTan[(b + a*Tan[x])/Sqrt[a^2 - b^2]]/(2*Sqrt[a^2 - b^2]) + Log[a + b*Sin[2*x]]/(4*b)}

{Sin[x]^2/(a + b*Cos[2*x]), x, 5, -(x/(2*b)) - (Sqrt[a + b]*ArcTan[(Sqrt[a + b]*Cot[x])/Sqrt[a - b]])/(2*Sqrt[a - b]*b)}
{Cos[x]^2/(a + b*Cos[2*x]), x, 4, x/(2*b) - (Sqrt[a - b]*ArcTan[(Sqrt[a - b]*Tan[x])/Sqrt[a + b]])/(2*b*Sqrt[a + b])}


{Cos[Log[x]]^2*Sin[Log[x]]^2/x, x, 3, Log[x]/8 + (1/8)*Cos[Log[x]]*Sin[Log[x]] - (1/4)*Cos[Log[x]]^3*Sin[Log[x]]}


(* ::Section::Closed:: *)
(*Integrands involving three trig functions*)


(* ::Subsection::Closed:: *)
(*Integrands of the form Trig[x]^m / (a+b Trig[x] + c Trig[x])*)


{Sin[x]/(a + b*Cos[x] + c*Sin[x]), x, 2, (c*x)/(b^2 + c^2) - (2*a*c*ArcTan[(c + (a - b)*Tan[x/2])/Sqrt[a^2 - b^2 - c^2]])/(Sqrt[a^2 - b^2 - c^2]*(b^2 + c^2)) - (b*Log[a + b*Cos[x] + c*Sin[x]])/(b^2 + c^2)}
{Sin[x]/(1 + Cos[x] + Sin[x]), x, 2, x/2 - (1/2)*Log[1 + Cos[x] + Sin[x]] - (1/2)*Log[1 + Tan[x/2]]}

{Sec[x]/(a + b*Tan[x] + c*Sec[x]), x, 2, -((2*ArcTanh[(b - (a - c)*Tan[x/2])/Sqrt[a^2 + b^2 - c^2]])/Sqrt[a^2 + b^2 - c^2])}
{Sec[x]^2/(a + b*Tan[x] + c*Sec[x]), x, 9, -((2*a*c*ArcTanh[(b - (a - c)*Tan[x/2])/Sqrt[a^2 + b^2 - c^2]])/((b^2 - c^2)*Sqrt[a^2 + b^2 - c^2])) - Log[1 - Tan[x/2]]/(b + c) - Log[1 + Tan[x/2]]/(b - c) + (b*Log[a + c + 2*b*Tan[x/2] - (a - c)*Tan[x/2]^2])/(b^2 - c^2)}

{Csc[x]/(2 + 2*Cot[x] + 3*Csc[x]), x, 2, 2*ArcTan[2 + Tan[x/2]]}
{Csc[x]/(a + b*Cot[x] + c*Csc[x]), x, 2, -((2*ArcTanh[(a - (b - c)*Tan[x/2])/Sqrt[a^2 + b^2 - c^2]])/Sqrt[a^2 + b^2 - c^2])}
{Csc[x]^2/(a + b*Cot[x] + c*Csc[x]), x, 8, -((2*a*c*ArcTanh[(a - (b - c)*Tan[x/2])/Sqrt[a^2 + b^2 - c^2]])/((b^2 - c^2)*Sqrt[a^2 + b^2 - c^2])) + Log[Tan[x/2]]/(b + c) - (b*Log[b + c + 2*a*Tan[x/2] - (b - c)*Tan[x/2]^2])/(b^2 - c^2)}


(* ::Subsection::Closed:: *)
(*Integrands of the form (A + B Trig[x]) (a Trig[x] + b Trig[x])^n*)


{(A + C*Sin[x])/(b*Cos[x] + c*Sin[x]), x, 3, (c*C*x)/(b^2 + c^2) - (A*ArcTanh[(c*Cos[x] - b*Sin[x])/Sqrt[b^2 + c^2]])/Sqrt[b^2 + c^2] - (b*C*Log[b*Cos[x] + c*Sin[x]])/(b^2 + c^2)}
{(A + C*Sin[x])/(b*Cos[x] + c*Sin[x])^2, x, 3, -((c*C*ArcTanh[(c*Cos[x] - b*Sin[x])/Sqrt[b^2 + c^2]])/(b^2 + c^2)^(3/2)) + (b*C - A*c*Cos[x] + A*b*Sin[x])/((b^2 + c^2)*(b*Cos[x] + c*Sin[x]))}
{(A + C*Sin[x])/(b*Cos[x] + c*Sin[x])^3, x, 4, -((A*ArcTanh[(c*Cos[x] - b*Sin[x])/Sqrt[b^2 + c^2]])/(2*(b^2 + c^2)^(3/2))) + (b*C - A*c*Cos[x] + A*b*Sin[x])/(2*(b^2 + c^2)*(b*Cos[x] + c*Sin[x])^2) - (c^2*C*Cos[x] - b*c*C*Sin[x])/((b^2 + c^2)^2*(b*Cos[x] + c*Sin[x]))}


{(A + B*Cos[x])/(b*Cos[x] + c*Sin[x]), x, 3, (b*B*x)/(b^2 + c^2) - (A*ArcTanh[(c*Cos[x] - b*Sin[x])/Sqrt[b^2 + c^2]])/Sqrt[b^2 + c^2] + (B*c*Log[b*Cos[x] + c*Sin[x]])/(b^2 + c^2)}
{(A + B*Cos[x])/(b*Cos[x] + c*Sin[x])^2, x, 3, -((b*B*ArcTanh[(c*Cos[x] - b*Sin[x])/Sqrt[b^2 + c^2]])/(b^2 + c^2)^(3/2)) - (B*c + A*c*Cos[x] - A*b*Sin[x])/((b^2 + c^2)*(b*Cos[x] + c*Sin[x]))}
{(A + B*Cos[x])/(b*Cos[x] + c*Sin[x])^3, x, 4, -((A*ArcTanh[(c*Cos[x] - b*Sin[x])/Sqrt[b^2 + c^2]])/(2*(b^2 + c^2)^(3/2))) - (B*c + A*c*Cos[x] - A*b*Sin[x])/(2*(b^2 + c^2)*(b*Cos[x] + c*Sin[x])^2) - (b*B*c*Cos[x] - b^2*B*Sin[x])/((b^2 + c^2)^2*(b*Cos[x] + c*Sin[x]))}


(* ::Subsection::Closed:: *)
(*Integrands of the form (A + B Trig[x]) (a+b Trig[x] + c Trig[x])^n*)


{(A + C*Sin[x])/(a + b*Cos[x] + c*Sin[x]), x, 2, (c*C*x)/(b^2 + c^2) + (2*(A*(b^2 + c^2) - a*c*C)*ArcTan[(c + (a - b)*Tan[x/2])/Sqrt[a^2 - b^2 - c^2]])/(Sqrt[a^2 - b^2 - c^2]*(b^2 + c^2)) - (b*C*Log[a + b*Cos[x] + c*Sin[x]])/(b^2 + c^2)}
{(A + C*Sin[x])/(a + b*Cos[x] + c*Sin[x])^2, x, 2, (2*(a*A - c*C)*ArcTan[(c + (a - b)*Tan[x/2])/Sqrt[a^2 - b^2 - c^2]])/(a^2 - b^2 - c^2)^(3/2) - (b*C - (A*c - a*C)*Cos[x] + A*b*Sin[x])/((a^2 - b^2 - c^2)*(a + b*Cos[x] + c*Sin[x]))}
{(A + C*Sin[x])/(a + b*Cos[x] + c*Sin[x])^3, x, 3, ((2*a^2*A + A*(b^2 + c^2) - 3*a*c*C)*ArcTan[(c + (a - b)*Tan[x/2])/Sqrt[a^2 - b^2 - c^2]])/(a^2 - b^2 - c^2)^(5/2) - (b*C - (A*c - a*C)*Cos[x] + A*b*Sin[x])/(2*(a^2 - b^2 - c^2)*(a + b*Cos[x] + c*Sin[x])^2) - (a*b*C - (3*a*A*c - a^2*C - 2*c^2*C)*Cos[x] + b*(3*a*A - 2*c*C)*Sin[x])/(2*(a^2 - b^2 - c^2)^2*(a + b*Cos[x] + c*Sin[x]))}


{(A + B*Cos[x])/(a + b*Cos[x] + c*Sin[x]), x, 2, (b*B*x)/(b^2 + c^2) - (2*(a*b*B - A*(b^2 + c^2))*ArcTan[(c + (a - b)*Tan[x/2])/Sqrt[a^2 - b^2 - c^2]])/(Sqrt[a^2 - b^2 - c^2]*(b^2 + c^2)) + (B*c*Log[a + b*Cos[x] + c*Sin[x]])/(b^2 + c^2)}
{(A + B*Cos[x])/(a + b*Cos[x] + c*Sin[x])^2, x, 2, (2*(a*A - b*B)*ArcTan[(c + (a - b)*Tan[x/2])/Sqrt[a^2 - b^2 - c^2]])/(a^2 - b^2 - c^2)^(3/2) + (B*c + A*c*Cos[x] - (A*b - a*B)*Sin[x])/((a^2 - b^2 - c^2)*(a + b*Cos[x] + c*Sin[x]))}
{(A + B*Cos[x])/(a + b*Cos[x] + c*Sin[x])^3, x, 3, ((2*a^2*A - 3*a*b*B + A*(b^2 + c^2))*ArcTan[(c + (a - b)*Tan[x/2])/Sqrt[a^2 - b^2 - c^2]])/(a^2 - b^2 - c^2)^(5/2) + (B*c + A*c*Cos[x] - (A*b - a*B)*Sin[x])/(2*(a^2 - b^2 - c^2)*(a + b*Cos[x] + c*Sin[x])^2) + (a*B*c + (3*a*A - 2*b*B)*c*Cos[x] - (3*a*A*b - a^2*B - 2*b^2*B)*Sin[x])/(2*(a^2 - b^2 - c^2)^2*(a + b*Cos[x] + c*Sin[x]))}


{(A + B*Cos[d + e*x] + C*Sin[d + e*x])/(a + c*Sin[d + e*x]), x, 7, (C*x)/c + (2*(A*c - a*C)*ArcTan[(c + a*Tan[(1/2)*(d + e*x)])/Sqrt[a^2 - c^2]])/(c*Sqrt[a^2 - c^2]*e) + (B*Log[a + c*Sin[d + e*x]])/(c*e)}
{(A + B*Cos[d + e*x] + C*Sin[d + e*x])/(a + c*Sin[d + e*x])^2, x, 7, (2*(a*A - c*C)*ArcTan[(c + a*Tan[(1/2)*(d + e*x)])/Sqrt[a^2 - c^2]])/((a^2 - c^2)^(3/2)*e) - B/(c*e*(a + c*Sin[d + e*x])) + ((A*c - a*C)*Cos[d + e*x])/((a^2 - c^2)*e*(a + c*Sin[d + e*x]))}
{(A + B*Cos[d + e*x] + C*Sin[d + e*x])/(a + c*Sin[d + e*x])^3, x, 8, ((2*a^2*A + A*c^2 - 3*a*c*C)*ArcTan[(c + a*Tan[(1/2)*(d + e*x)])/Sqrt[a^2 - c^2]])/((a^2 - c^2)^(5/2)*e) - B/(2*c*e*(a + c*Sin[d + e*x])^2) + ((A*c - a*C)*Cos[d + e*x])/(2*(a^2 - c^2)*e*(a + c*Sin[d + e*x])^2) + ((3*a*A*c - a^2*C - 2*c^2*C)*Cos[d + e*x])/(2*(a^2 - c^2)^2*e*(a + c*Sin[d + e*x]))}
{(A + B*Cos[d + e*x] + C*Sin[d + e*x])/(a + c*Sin[d + e*x])^4, x, 9, ((2*a^3*A + 3*a*A*c^2 - 4*a^2*c*C - c^3*C)*ArcTan[(c + a*Tan[(1/2)*(d + e*x)])/Sqrt[a^2 - c^2]])/((a^2 - c^2)^(7/2)*e) - B/(3*c*e*(a + c*Sin[d + e*x])^3) + ((A*c - a*C)*Cos[d + e*x])/(3*(a^2 - c^2)*e*(a + c*Sin[d + e*x])^3) + ((5*a*A*c - 2*a^2*C - 3*c^2*C)*Cos[d + e*x])/(6*(a^2 - c^2)^2*e*(a + c*Sin[d + e*x])^2) + ((11*a^2*A*c + 4*A*c^3 - 2*a^3*C - 13*a*c^2*C)*Cos[d + e*x])/(6*(a^2 - c^2)^3*e*(a + c*Sin[d + e*x]))}


(* ::Subsection::Closed:: *)
(*Miscellaneous rational functions of three trig functions*)


{Sin[x]^2/(a*Cos[x]^2 + b*Sin[x]^2), x, 2, -(x/(a - b)) - (Sqrt[a]*ArcTan[(Sqrt[a]*Cot[x])/Sqrt[b]])/((a - b)*Sqrt[b])}
{Cos[x]^2/(a*Cos[x]^2 + b*Sin[x]^2), x, 2, x/(a - b) - (Sqrt[b]*ArcTan[(Sqrt[b]*Tan[x])/Sqrt[a]])/(Sqrt[a]*(a - b))}

{Sin[x]^3/(Cos[x]^3 + Sin[x]^3), x, 7, x/2 - (1/6)*Log[Cos[x] + Sin[x]] + (1/3)*Log[2 - Sin[2*x]]}
{Cos[x]^3/(Cos[x]^3 + Sin[x]^3), x, 7, x/2 + (1/6)*Log[Cos[x] + Sin[x]] - (1/3)*Log[2 - Sin[2*x]]}


{Sin[x]^4/(a + b*Sin[x] + c*Sin[x]^2), x, 7, x/(2*c) + ((b^2 - a*c)*x)/c^3 - (2*(b^3 - 2*a*b*c - (b^4 - 4*a*b^2*c + 2*a^2*c^2)/Sqrt[b^2 - 4*a*c])*ArcTan[(2*c + (b - Sqrt[b^2 - 4*a*c])*Tan[x/2])/Sqrt[-4*c^2 + (b - Sqrt[b^2 - 4*a*c])^2]])/(c^3*Sqrt[-4*c^2 + (b - Sqrt[b^2 - 4*a*c])^2]) - (2*(b^3 - 2*a*b*c + (b^4 - 4*a*b^2*c + 2*a^2*c^2)/Sqrt[b^2 - 4*a*c])*ArcTan[(2*c + (b + Sqrt[b^2 - 4*a*c])*Tan[x/2])/Sqrt[-4*c^2 + (b + Sqrt[b^2 - 4*a*c])^2]])/(c^3*Sqrt[-4*c^2 + (b + Sqrt[b^2 - 4*a*c])^2]) + (b*Cos[x])/c^2 - (Cos[x]*Sin[x])/(2*c)}
{Sin[x]^3/(a + b*Sin[x] + c*Sin[x]^2), x, 6, -((b*x)/c^2) + (2*(b^2 - a*c - (b^3 - 3*a*b*c)/Sqrt[b^2 - 4*a*c])*ArcTan[(2*c + (b - Sqrt[b^2 - 4*a*c])*Tan[x/2])/Sqrt[-4*c^2 + (b - Sqrt[b^2 - 4*a*c])^2]])/(c^2*Sqrt[-4*c^2 + (b - Sqrt[b^2 - 4*a*c])^2]) + (2*(b^2 - a*c + (b^3 - 3*a*b*c)/Sqrt[b^2 - 4*a*c])*ArcTan[(2*c + (b + Sqrt[b^2 - 4*a*c])*Tan[x/2])/Sqrt[-4*c^2 + (b + Sqrt[b^2 - 4*a*c])^2]])/(c^2*Sqrt[-4*c^2 + (b + Sqrt[b^2 - 4*a*c])^2]) - Cos[x]/c}
{Sin[x]^2/(a + b*Sin[x] + c*Sin[x]^2), x, 5, x/c - (2*(b - (b^2 - 2*a*c)/Sqrt[b^2 - 4*a*c])*ArcTan[(2*c + (b - Sqrt[b^2 - 4*a*c])*Tan[x/2])/Sqrt[-4*c^2 + (b - Sqrt[b^2 - 4*a*c])^2]])/(c*Sqrt[-4*c^2 + (b - Sqrt[b^2 - 4*a*c])^2]) - (2*(b + (b^2 - 2*a*c)/Sqrt[b^2 - 4*a*c])*ArcTan[(2*c + (b + Sqrt[b^2 - 4*a*c])*Tan[x/2])/Sqrt[-4*c^2 + (b + Sqrt[b^2 - 4*a*c])^2]])/(c*Sqrt[-4*c^2 + (b + Sqrt[b^2 - 4*a*c])^2])}
{Sin[x]^1/(a + b*Sin[x] + c*Sin[x]^2), x, 3, (2*(1 - b/Sqrt[b^2 - 4*a*c])*ArcTan[(2*c + (b - Sqrt[b^2 - 4*a*c])*Tan[x/2])/Sqrt[-4*c^2 + (b - Sqrt[b^2 - 4*a*c])^2]])/Sqrt[-4*c^2 + (b - Sqrt[b^2 - 4*a*c])^2] + (2*(1 + b/Sqrt[b^2 - 4*a*c])*ArcTan[(2*c + (b + Sqrt[b^2 - 4*a*c])*Tan[x/2])/Sqrt[-4*c^2 + (b + Sqrt[b^2 - 4*a*c])^2]])/Sqrt[-4*c^2 + (b + Sqrt[b^2 - 4*a*c])^2]}
{Sin[x]^0/(a + b*Sin[x] + c*Sin[x]^2), x, 3, (4*c*ArcTan[(2*c + (b - Sqrt[b^2 - 4*a*c])*Tan[x/2])/Sqrt[-4*c^2 + (b - Sqrt[b^2 - 4*a*c])^2]])/(Sqrt[b^2 - 4*a*c]*Sqrt[-4*c^2 + (b - Sqrt[b^2 - 4*a*c])^2]) - (4*c*ArcTan[(2*c + (b + Sqrt[b^2 - 4*a*c])*Tan[x/2])/Sqrt[-4*c^2 + (b + Sqrt[b^2 - 4*a*c])^2]])/(Sqrt[b^2 - 4*a*c]*Sqrt[-4*c^2 + (b + Sqrt[b^2 - 4*a*c])^2])}
{Csc[x]^1/(a + b*Sin[x] + c*Sin[x]^2), x, 6, -((2*c*(1 + b/Sqrt[b^2 - 4*a*c])*ArcTan[(2*c + (b - Sqrt[b^2 - 4*a*c])*Tan[x/2])/Sqrt[-4*c^2 + (b - Sqrt[b^2 - 4*a*c])^2]])/(a*Sqrt[-4*c^2 + (b - Sqrt[b^2 - 4*a*c])^2])) - (2*c*(1 - b/Sqrt[b^2 - 4*a*c])*ArcTan[(2*c + (b + Sqrt[b^2 - 4*a*c])*Tan[x/2])/Sqrt[-4*c^2 + (b + Sqrt[b^2 - 4*a*c])^2]])/(a*Sqrt[-4*c^2 + (b + Sqrt[b^2 - 4*a*c])^2]) - ArcTanh[Cos[x]]/a}
{Csc[x]^2/(a + b*Sin[x] + c*Sin[x]^2), x, 7, (2*c*(b + (b^2 - 2*a*c)/Sqrt[b^2 - 4*a*c])*ArcTan[(2*c + (b - Sqrt[b^2 - 4*a*c])*Tan[x/2])/Sqrt[-4*c^2 + (b - Sqrt[b^2 - 4*a*c])^2]])/(a^2*Sqrt[-4*c^2 + (b - Sqrt[b^2 - 4*a*c])^2]) + (2*c*(b - (b^2 - 2*a*c)/Sqrt[b^2 - 4*a*c])*ArcTan[(2*c + (b + Sqrt[b^2 - 4*a*c])*Tan[x/2])/Sqrt[-4*c^2 + (b + Sqrt[b^2 - 4*a*c])^2]])/(a^2*Sqrt[-4*c^2 + (b + Sqrt[b^2 - 4*a*c])^2]) + (b*ArcTanh[Cos[x]])/a^2 - Cot[x]/a}
{Csc[x]^3/(a + b*Sin[x] + c*Sin[x]^2), x, 9, -((2*c*(b^2 - a*c + b^3/Sqrt[b^2 - 4*a*c] - (3*a*b*c)/Sqrt[b^2 - 4*a*c])*ArcTan[(2*c + (b - Sqrt[b^2 - 4*a*c])*Tan[x/2])/Sqrt[-4*c^2 + (b - Sqrt[b^2 - 4*a*c])^2]])/(a^3*Sqrt[-4*c^2 + (b - Sqrt[b^2 - 4*a*c])^2])) - (2*c*(b^2 - a*c - b^3/Sqrt[b^2 - 4*a*c] + (3*a*b*c)/Sqrt[b^2 - 4*a*c])*ArcTan[(2*c + (b + Sqrt[b^2 - 4*a*c])*Tan[x/2])/Sqrt[-4*c^2 + (b + Sqrt[b^2 - 4*a*c])^2]])/(a^3*Sqrt[-4*c^2 + (b + Sqrt[b^2 - 4*a*c])^2]) - ArcTanh[Cos[x]]/(2*a) - ((b^2 - a*c)*ArcTanh[Cos[x]])/a^3 + (b*Cot[x])/a^2 - (Cot[x]*Csc[x])/(2*a)}

{(a + b*Sin[x])/(b^2 + 2*a*b*Sin[x] + a^2*Sin[x]^2), x, 3, -(Cos[x]/(b + a*Sin[x]))}
{(d + e*Sin[x])/(a + b*Sin[x] + c*Sin[x]^2), x, 3, (2*(e + (2*c*d - b*e)/Sqrt[b^2 - 4*a*c])*ArcTan[(2*c + (b - Sqrt[b^2 - 4*a*c])*Tan[x/2])/Sqrt[-4*c^2 + (b - Sqrt[b^2 - 4*a*c])^2]])/Sqrt[-4*c^2 + (b - Sqrt[b^2 - 4*a*c])^2] + (2*(e - (2*c*d - b*e)/Sqrt[b^2 - 4*a*c])*ArcTan[(2*c + (b + Sqrt[b^2 - 4*a*c])*Tan[x/2])/Sqrt[-4*c^2 + (b + Sqrt[b^2 - 4*a*c])^2]])/Sqrt[-4*c^2 + (b + Sqrt[b^2 - 4*a*c])^2]}


{Cos[x]^4/(a + b*Cos[x] + c*Cos[x]^2), x, 7, x/(2*c) + ((b^2 - a*c)*x)/c^3 - (2*(b^3 - 2*a*b*c - (b^4 - 4*a*b^2*c + 2*a^2*c^2)/Sqrt[b^2 - 4*a*c])*ArcTan[(Sqrt[-4*c^2 + (b - Sqrt[b^2 - 4*a*c])^2]*Tan[x/2])/(b + 2*c - Sqrt[b^2 - 4*a*c])])/(c^3*Sqrt[-4*c^2 + (b - Sqrt[b^2 - 4*a*c])^2]) - (2*(b^3 - 2*a*b*c + (b^4 - 4*a*b^2*c + 2*a^2*c^2)/Sqrt[b^2 - 4*a*c])*ArcTan[(Sqrt[-4*c^2 + (b + Sqrt[b^2 - 4*a*c])^2]*Tan[x/2])/(b + 2*c + Sqrt[b^2 - 4*a*c])])/(c^3*Sqrt[-4*c^2 + (b + Sqrt[b^2 - 4*a*c])^2]) - (b*Sin[x])/c^2 + (Cos[x]*Sin[x])/(2*c)}
{Cos[x]^3/(a + b*Cos[x] + c*Cos[x]^2), x, 6, -((b*x)/c^2) + (2*(b^2 - a*c - (b^3 - 3*a*b*c)/Sqrt[b^2 - 4*a*c])*ArcTan[(Sqrt[-4*c^2 + (b - Sqrt[b^2 - 4*a*c])^2]*Tan[x/2])/(b + 2*c - Sqrt[b^2 - 4*a*c])])/(c^2*Sqrt[-4*c^2 + (b - Sqrt[b^2 - 4*a*c])^2]) + (2*(b^2 - a*c + (b^3 - 3*a*b*c)/Sqrt[b^2 - 4*a*c])*ArcTan[(Sqrt[-4*c^2 + (b + Sqrt[b^2 - 4*a*c])^2]*Tan[x/2])/(b + 2*c + Sqrt[b^2 - 4*a*c])])/(c^2*Sqrt[-4*c^2 + (b + Sqrt[b^2 - 4*a*c])^2]) + Sin[x]/c}
{Cos[x]^2/(a + b*Cos[x] + c*Cos[x]^2), x, 5, x/c - (2*(b - (b^2 - 2*a*c)/Sqrt[b^2 - 4*a*c])*ArcTan[(Sqrt[-4*c^2 + (b - Sqrt[b^2 - 4*a*c])^2]*Tan[x/2])/(b + 2*c - Sqrt[b^2 - 4*a*c])])/(c*Sqrt[-4*c^2 + (b - Sqrt[b^2 - 4*a*c])^2]) - (2*(b + (b^2 - 2*a*c)/Sqrt[b^2 - 4*a*c])*ArcTan[(Sqrt[-4*c^2 + (b + Sqrt[b^2 - 4*a*c])^2]*Tan[x/2])/(b + 2*c + Sqrt[b^2 - 4*a*c])])/(c*Sqrt[-4*c^2 + (b + Sqrt[b^2 - 4*a*c])^2])}
{Cos[x]^1/(a + b*Cos[x] + c*Cos[x]^2), x, 3, (2*(1 - b/Sqrt[b^2 - 4*a*c])*ArcTan[(Sqrt[-4*c^2 + (b - Sqrt[b^2 - 4*a*c])^2]*Tan[x/2])/(b + 2*c - Sqrt[b^2 - 4*a*c])])/Sqrt[-4*c^2 + (b - Sqrt[b^2 - 4*a*c])^2] + (2*(1 + b/Sqrt[b^2 - 4*a*c])*ArcTan[(Sqrt[-4*c^2 + (b + Sqrt[b^2 - 4*a*c])^2]*Tan[x/2])/(b + 2*c + Sqrt[b^2 - 4*a*c])])/Sqrt[-4*c^2 + (b + Sqrt[b^2 - 4*a*c])^2]}
{Cos[x]^0/(a + b*Cos[x] + c*Cos[x]^2), x, 3, (4*c*ArcTan[(Sqrt[-4*c^2 + (b - Sqrt[b^2 - 4*a*c])^2]*Tan[x/2])/(b + 2*c - Sqrt[b^2 - 4*a*c])])/(Sqrt[b^2 - 4*a*c]*Sqrt[-4*c^2 + (b - Sqrt[b^2 - 4*a*c])^2]) - (4*c*ArcTan[(Sqrt[-4*c^2 + (b + Sqrt[b^2 - 4*a*c])^2]*Tan[x/2])/(b + 2*c + Sqrt[b^2 - 4*a*c])])/(Sqrt[b^2 - 4*a*c]*Sqrt[-4*c^2 + (b + Sqrt[b^2 - 4*a*c])^2])}
{Sec[x]^1/(a + b*Cos[x] + c*Cos[x]^2), x, 6, -((2*c*(1 + b/Sqrt[b^2 - 4*a*c])*ArcTan[(Sqrt[-4*c^2 + (b - Sqrt[b^2 - 4*a*c])^2]*Tan[x/2])/(b + 2*c - Sqrt[b^2 - 4*a*c])])/(a*Sqrt[-4*c^2 + (b - Sqrt[b^2 - 4*a*c])^2])) - (2*c*(1 - b/Sqrt[b^2 - 4*a*c])*ArcTan[(Sqrt[-4*c^2 + (b + Sqrt[b^2 - 4*a*c])^2]*Tan[x/2])/(b + 2*c + Sqrt[b^2 - 4*a*c])])/(a*Sqrt[-4*c^2 + (b + Sqrt[b^2 - 4*a*c])^2]) + ArcTanh[Sin[x]]/a}
{Sec[x]^2/(a + b*Cos[x] + c*Cos[x]^2), x, 7, (2*c*(b + (b^2 - 2*a*c)/Sqrt[b^2 - 4*a*c])*ArcTan[(Sqrt[-4*c^2 + (b - Sqrt[b^2 - 4*a*c])^2]*Tan[x/2])/(b + 2*c - Sqrt[b^2 - 4*a*c])])/(a^2*Sqrt[-4*c^2 + (b - Sqrt[b^2 - 4*a*c])^2]) + (2*c*(b - (b^2 - 2*a*c)/Sqrt[b^2 - 4*a*c])*ArcTan[(Sqrt[-4*c^2 + (b + Sqrt[b^2 - 4*a*c])^2]*Tan[x/2])/(b + 2*c + Sqrt[b^2 - 4*a*c])])/(a^2*Sqrt[-4*c^2 + (b + Sqrt[b^2 - 4*a*c])^2]) - (b*ArcTanh[Sin[x]])/a^2 + Tan[x]/a}
{Sec[x]^3/(a + b*Cos[x] + c*Cos[x]^2), x, 9, -((2*c*(b^2 - a*c + b^3/Sqrt[b^2 - 4*a*c] - (3*a*b*c)/Sqrt[b^2 - 4*a*c])*ArcTan[(Sqrt[-4*c^2 + (b - Sqrt[b^2 - 4*a*c])^2]*Tan[x/2])/(b + 2*c - Sqrt[b^2 - 4*a*c])])/(a^3*Sqrt[-4*c^2 + (b - Sqrt[b^2 - 4*a*c])^2])) - (2*c*(b^2 - a*c - b^3/Sqrt[b^2 - 4*a*c] + (3*a*b*c)/Sqrt[b^2 - 4*a*c])*ArcTan[(Sqrt[-4*c^2 + (b + Sqrt[b^2 - 4*a*c])^2]*Tan[x/2])/(b + 2*c + Sqrt[b^2 - 4*a*c])])/(a^3*Sqrt[-4*c^2 + (b + Sqrt[b^2 - 4*a*c])^2]) + ArcTanh[Sin[x]]/(2*a) + ((b^2 - a*c)*ArcTanh[Sin[x]])/a^3 - (b*Tan[x])/a^2 + (Sec[x]*Tan[x])/(2*a)}

{(a + b*Cos[x])/(b^2 + 2*a*b*Cos[x] + a^2*Cos[x]^2), x, 3, Sin[x]/(b + a*Cos[x])}
{(d + e*Cos[x])/(a + b*Cos[x] + c*Cos[x]^2), x, 3, (2*(e + (2*c*d - b*e)/Sqrt[b^2 - 4*a*c])*ArcTan[(Sqrt[-4*c^2 + (b - Sqrt[b^2 - 4*a*c])^2]*Tan[x/2])/(b + 2*c - Sqrt[b^2 - 4*a*c])])/Sqrt[-4*c^2 + (b - Sqrt[b^2 - 4*a*c])^2] + (2*(e - (2*c*d - b*e)/Sqrt[b^2 - 4*a*c])*ArcTan[(Sqrt[-4*c^2 + (b + Sqrt[b^2 - 4*a*c])^2]*Tan[x/2])/(b + 2*c + Sqrt[b^2 - 4*a*c])])/Sqrt[-4*c^2 + (b + Sqrt[b^2 - 4*a*c])^2]}


{Sin[x]/(-2 + Cos[x] + Cos[x]^2), x, 4, (-(1/3))*Log[1 - Cos[x]] + (1/3)*Log[2 + Cos[x]]}
{Sin[x]/(4 - 5*Cos[x] + Cos[x]^2), x, 4, (1/3)*Log[1 - Cos[x]] - (1/3)*Log[4 - Cos[x]]}
{Sin[x]/(3 - 2*Cos[x] + Cos[x]^2), x, 2, ArcTan[(1 - Cos[x])/Sqrt[2]]/Sqrt[2]}
{Sin[x]/(13 - 4*Cos[x] + Cos[x]^2)^2, x, 3, (1/54)*ArcTan[2/3 - Cos[x]/3] + (2 - Cos[x])/(18*(13 - 4*Cos[x] + Cos[x]^2))}

{Cos[x]/(-6 + Sin[x] + Sin[x]^2), x, 4, (1/5)*Log[2 - Sin[x]] - (1/5)*Log[3 + Sin[x]]}
{Cos[x]/(2 - 3*Sin[x] + Sin[x]^2), x, 2, 2*ArcTanh[3 - 2*Sin[x]]}
{Cos[x]/(-5 + 4*Sin[x] + Sin[x]^2), x, 4, (1/6)*Log[1 - Sin[x]] - (1/6)*Log[5 + Sin[x]]}
{Cos[x]/(10 - 6*Sin[x] + Sin[x]^2), x, 2, -ArcTan[3 - Sin[x]]}
{Cos[x]/(2 + 2*Sin[x] + Sin[x]^2), x, 2, ArcTan[1 + Sin[x]]}

{Sec[x]/(-5 + Cos[x]^2 + 4*Sin[x]), x, 3, (-(4/9))*Log[2 - Sin[x]] + (1/2)*Log[1 - Sin[x]] - (1/18)*Log[1 + Sin[x]] + 1/(3*(2 - Sin[x]))}


(* Nonidempotent expansion results in infinite recursion: *) 
(* {(x*Cos[x] - Sin[x])/(x - Sin[x])^2, x, -7, x/(x - Sin[x])} *)
(* {x/(x - Cos[x])^2, x, 1, Defer[Int][x/(x - Cos[x])^2, x]} *)
(* {Cos[x]/(x - Cos[x])^2, x, 1, Defer[Int][Cos[x]/(x - Cos[x])^2, x]} *)
(* {(Cos[x] + x*Sin[x])/(x - Cos[x])^2, x, 0, -x/(x - Cos[x])} *)


(* ::Subsection::Closed:: *)
(*Miscellaneous algebraic functions of three trig functions*)


{1/(Cos[x]^(3/2)*Sqrt[3*Cos[x] + Sin[x]]), x, -6, (2*Sqrt[3*Cos[x] + Sin[x]])/Sqrt[Cos[x]]}
{(Csc[x]*Sqrt[Cos[x] + Sin[x]])/Cos[x]^(3/2), x, -6, -Log[Sin[x]] + 2*Log[-Sqrt[Cos[x]] + Sqrt[Cos[x] + Sin[x]]] + (2*Sqrt[Cos[x] + Sin[x]])/Sqrt[Cos[x]]}
{(Cos[x] + Sin[x])/Sqrt[1 + Sin[2*x]], x, 20, (x*Sqrt[1 + Sin[2*x]])/(Cos[x] + Sin[x])}
{Sec[x]*Sqrt[Sec[x] + Tan[x]], x, 4, 2*Sqrt[(1 + Tan[x/2])/(1 - Tan[x/2])]}

{Sec[x]*Sqrt[4 + 3*Sec[x]]*Tan[x], x, 2, (2*(4 + 3*Sec[x])^(3/2))/9}
{Sec[x]*Sqrt[1 + Sec[x]]*Tan[x]^3, x, 4, (-(4/5))*(1 + Sec[x])^(5/2) + (2/7)*(1 + Sec[x])^(7/2)}
{Csc[x]*Sqrt[1 + Csc[x]]*Cot[x]^3, x, 4, (4/5)*(1 + Csc[x])^(5/2) - (2/7)*(1 + Csc[x])^(7/2)}

{Sqrt[Csc[x]]*(x*Cos[x] - 4*Sec[x]*Tan[x]), x, 8, (2*x)/Sqrt[Csc[x]] - (4*Sec[x])/Csc[x]^(3/2)}


{Cot[x]*Sqrt[-1 + Csc[x]^2]*(1 - Sin[x]^2)^3, x, 7, (-(35/16))*Sqrt[Cot[x]^2] + (35/48)*Cos[x]^2*Sqrt[Cot[x]^2] + (7/24)*Cos[x]^4*Sqrt[Cot[x]^2] + (1/6)*Cos[x]^6*Sqrt[Cot[x]^2] - (35/16)*x*Sqrt[Cot[x]^2]*Tan[x]}
{Cos[x]*Sqrt[-1 + Csc[x]^2]*(1 - Sin[x]^2)^3, x, 8, Sqrt[Cot[x]^2]*Sin[x] + (1/3)*Cos[x]^2*Sqrt[Cot[x]^2]*Sin[x] + (1/5)*Cos[x]^4*Sqrt[Cot[x]^2]*Sin[x] + (1/7)*Cos[x]^6*Sqrt[Cot[x]^2]*Sin[x] - ArcTanh[Cos[x]]*Sqrt[Cot[x]^2]*Tan[x]}


{(x^1*Csc[x]*Sec[x])/Sqrt[a*Sec[x]^2], x, 5, -((2*x*ArcTanh[E^(I*x)]*Sec[x])/Sqrt[a*Sec[x]^2]) + (I*PolyLog[2, -E^(I*x)]*Sec[x])/Sqrt[a*Sec[x]^2] - (I*PolyLog[2, E^(I*x)]*Sec[x])/Sqrt[a*Sec[x]^2]}
{(x^2*Csc[x]*Sec[x])/Sqrt[a*Sec[x]^2], x, 7, -((2*x^2*ArcTanh[E^(I*x)]*Sec[x])/Sqrt[a*Sec[x]^2]) + (2*I*x*PolyLog[2, -E^(I*x)]*Sec[x])/Sqrt[a*Sec[x]^2] - (2*I*x*PolyLog[2, E^(I*x)]*Sec[x])/Sqrt[a*Sec[x]^2] - (2*PolyLog[3, -E^(I*x)]*Sec[x])/Sqrt[a*Sec[x]^2] + (2*PolyLog[3, E^(I*x)]*Sec[x])/Sqrt[a*Sec[x]^2]}
{(x^3*Csc[x]*Sec[x])/Sqrt[a*Sec[x]^2], x, 9, -((2*x^3*ArcTanh[E^(I*x)]*Sec[x])/Sqrt[a*Sec[x]^2]) + (3*I*x^2*PolyLog[2, -E^(I*x)]*Sec[x])/Sqrt[a*Sec[x]^2] - (3*I*x^2*PolyLog[2, E^(I*x)]*Sec[x])/Sqrt[a*Sec[x]^2] - (6*x*PolyLog[3, -E^(I*x)]*Sec[x])/Sqrt[a*Sec[x]^2] + (6*x*PolyLog[3, E^(I*x)]*Sec[x])/Sqrt[a*Sec[x]^2] - (6*I*PolyLog[4, -E^(I*x)]*Sec[x])/Sqrt[a*Sec[x]^2] + (6*I*PolyLog[4, E^(I*x)]*Sec[x])/Sqrt[a*Sec[x]^2]}


{(x^1*Csc[x]*Sec[x])/Sqrt[a*Sec[x]^4], x, 6, -((I*x^2*Sec[x]^2)/(2*Sqrt[a*Sec[x]^4])) + (x*Log[1 - E^(2*I*x)]*Sec[x]^2)/Sqrt[a*Sec[x]^4] - (I*PolyLog[2, E^(2*I*x)]*Sec[x]^2)/(2*Sqrt[a*Sec[x]^4])}
{(x^2*Csc[x]*Sec[x])/Sqrt[a*Sec[x]^4], x, 7, -((I*x^3*Sec[x]^2)/(3*Sqrt[a*Sec[x]^4])) + (x^2*Log[1 - E^(2*I*x)]*Sec[x]^2)/Sqrt[a*Sec[x]^4] - (I*x*PolyLog[2, E^(2*I*x)]*Sec[x]^2)/Sqrt[a*Sec[x]^4] + (PolyLog[3, E^(2*I*x)]*Sec[x]^2)/(2*Sqrt[a*Sec[x]^4])}
{(x^3*Csc[x]*Sec[x])/Sqrt[a*Sec[x]^4], x, 8, -((I*x^4*Sec[x]^2)/(4*Sqrt[a*Sec[x]^4])) + (x^3*Log[1 - E^(2*I*x)]*Sec[x]^2)/Sqrt[a*Sec[x]^4] - (3*I*x^2*PolyLog[2, E^(2*I*x)]*Sec[x]^2)/(2*Sqrt[a*Sec[x]^4]) + (3*x*PolyLog[3, E^(2*I*x)]*Sec[x]^2)/(2*Sqrt[a*Sec[x]^4]) + (3*I*PolyLog[4, E^(2*I*x)]*Sec[x]^2)/(4*Sqrt[a*Sec[x]^4])}


{(x^1*Csc[x]*Sec[x])*Sqrt[a*Sec[x]^2], x, 9, -2*x*ArcTanh[E^(I*x)]*Cos[x]*Sqrt[a*Sec[x]^2] + x*ArcTanh[Cos[x]]*Cos[x]*Sqrt[a*Sec[x]^2] - ArcTanh[Sin[x]]*Cos[x]*Sqrt[a*Sec[x]^2] + I*Cos[x]*PolyLog[2, -E^(I*x)]*Sqrt[a*Sec[x]^2] - I*Cos[x]*PolyLog[2, E^(I*x)]*Sqrt[a*Sec[x]^2] - x*Cos[x]*(ArcTanh[Cos[x]] - Sec[x])*Sqrt[a*Sec[x]^2]}
{(x^2*Csc[x]*Sec[x])*Sqrt[a*Sec[x]^2], x, 14, 4*I*x*ArcTan[E^(I*x)]*Cos[x]*Sqrt[a*Sec[x]^2] - 2*x^2*ArcTanh[E^(I*x)]*Cos[x]*Sqrt[a*Sec[x]^2] + x^2*ArcTanh[Cos[x]]*Cos[x]*Sqrt[a*Sec[x]^2] + 2*I*x*Cos[x]*PolyLog[2, -E^(I*x)]*Sqrt[a*Sec[x]^2] - 2*I*Cos[x]*PolyLog[2, (-I)*E^(I*x)]*Sqrt[a*Sec[x]^2] + 2*I*Cos[x]*PolyLog[2, I*E^(I*x)]*Sqrt[a*Sec[x]^2] - 2*I*x*Cos[x]*PolyLog[2, E^(I*x)]*Sqrt[a*Sec[x]^2] - 2*Cos[x]*PolyLog[3, -E^(I*x)]*Sqrt[a*Sec[x]^2] + 2*Cos[x]*PolyLog[3, E^(I*x)]*Sqrt[a*Sec[x]^2] - x^2*Cos[x]*(ArcTanh[Cos[x]] - Sec[x])*Sqrt[a*Sec[x]^2]}
{(x^3*Csc[x]*Sec[x])*Sqrt[a*Sec[x]^2], x, 18, 6*I*x^2*ArcTan[E^(I*x)]*Cos[x]*Sqrt[a*Sec[x]^2] - 2*x^3*ArcTanh[E^(I*x)]*Cos[x]*Sqrt[a*Sec[x]^2] + x^3*ArcTanh[Cos[x]]*Cos[x]*Sqrt[a*Sec[x]^2] + 3*I*x^2*Cos[x]*PolyLog[2, -E^(I*x)]*Sqrt[a*Sec[x]^2] - 6*I*x*Cos[x]*PolyLog[2, (-I)*E^(I*x)]*Sqrt[a*Sec[x]^2] + 6*I*x*Cos[x]*PolyLog[2, I*E^(I*x)]*Sqrt[a*Sec[x]^2] - 3*I*x^2*Cos[x]*PolyLog[2, E^(I*x)]*Sqrt[a*Sec[x]^2] - 6*x*Cos[x]*PolyLog[3, -E^(I*x)]*Sqrt[a*Sec[x]^2] + 6*Cos[x]*PolyLog[3, (-I)*E^(I*x)]*Sqrt[a*Sec[x]^2] - 6*Cos[x]*PolyLog[3, I*E^(I*x)]*Sqrt[a*Sec[x]^2] + 6*x*Cos[x]*PolyLog[3, E^(I*x)]*Sqrt[a*Sec[x]^2] - 6*I*Cos[x]*PolyLog[4, -E^(I*x)]*Sqrt[a*Sec[x]^2] + 6*I*Cos[x]*PolyLog[4, E^(I*x)]*Sqrt[a*Sec[x]^2] - x^3*Cos[x]*(ArcTanh[Cos[x]] - Sec[x])*Sqrt[a*Sec[x]^2]}


{(x^1*Csc[x]*Sec[x])*Sqrt[a*Sec[x]^4], x, 11, (1/2)*x*Cos[x]^2*Sqrt[a*Sec[x]^4] - 2*x*ArcTanh[E^(2*I*x)]*Cos[x]^2*Sqrt[a*Sec[x]^4] - x*Cos[x]^2*Log[Tan[x]]*Sqrt[a*Sec[x]^4] + (1/2)*I*Cos[x]^2*PolyLog[2, -E^(2*I*x)]*Sqrt[a*Sec[x]^4] - (1/2)*I*Cos[x]^2*PolyLog[2, E^(2*I*x)]*Sqrt[a*Sec[x]^4] - (1/2)*Cos[x]*Sqrt[a*Sec[x]^4]*Sin[x] + (1/2)*x*Cos[x]^2*Sqrt[a*Sec[x]^4]*(2*Log[Tan[x]] + Tan[x]^2)}
{(x^2*Csc[x]*Sec[x])*Sqrt[a*Sec[x]^4], x, 17, (1/2)*x^2*Cos[x]^2*Sqrt[a*Sec[x]^4] - 2*x^2*ArcTanh[E^(2*I*x)]*Cos[x]^2*Sqrt[a*Sec[x]^4] - Cos[x]^2*Log[Cos[x]]*Sqrt[a*Sec[x]^4] - x^2*Cos[x]^2*Log[Tan[x]]*Sqrt[a*Sec[x]^4] + I*x*Cos[x]^2*PolyLog[2, -E^(2*I*x)]*Sqrt[a*Sec[x]^4] - I*x*Cos[x]^2*PolyLog[2, E^(2*I*x)]*Sqrt[a*Sec[x]^4] - (1/2)*Cos[x]^2*PolyLog[3, -E^(2*I*x)]*Sqrt[a*Sec[x]^4] + (1/2)*Cos[x]^2*PolyLog[3, E^(2*I*x)]*Sqrt[a*Sec[x]^4] - x*Cos[x]*Sqrt[a*Sec[x]^4]*Sin[x] + (1/2)*x^2*Cos[x]^2*Sqrt[a*Sec[x]^4]*(2*Log[Tan[x]] + Tan[x]^2)}
{(x^3*Csc[x]*Sec[x])*Sqrt[a*Sec[x]^4], x, 22, (3/2)*I*x^2*Cos[x]^2*Sqrt[a*Sec[x]^4] + (1/2)*x^3*Cos[x]^2*Sqrt[a*Sec[x]^4] - 2*x^3*ArcTanh[E^(2*I*x)]*Cos[x]^2*Sqrt[a*Sec[x]^4] - 3*x*Cos[x]^2*Log[1 + E^(2*I*x)]*Sqrt[a*Sec[x]^4] - x^3*Cos[x]^2*Log[Tan[x]]*Sqrt[a*Sec[x]^4] + (3/2)*I*Cos[x]^2*PolyLog[2, -E^(2*I*x)]*Sqrt[a*Sec[x]^4] + (3/2)*I*x^2*Cos[x]^2*PolyLog[2, -E^(2*I*x)]*Sqrt[a*Sec[x]^4] - (3/2)*I*x^2*Cos[x]^2*PolyLog[2, E^(2*I*x)]*Sqrt[a*Sec[x]^4] - (3/2)*x*Cos[x]^2*PolyLog[3, -E^(2*I*x)]*Sqrt[a*Sec[x]^4] + (3/2)*x*Cos[x]^2*PolyLog[3, E^(2*I*x)]*Sqrt[a*Sec[x]^4] - (3/4)*I*Cos[x]^2*PolyLog[4, -E^(2*I*x)]*Sqrt[a*Sec[x]^4] + (3/4)*I*Cos[x]^2*PolyLog[4, E^(2*I*x)]*Sqrt[a*Sec[x]^4] - (3/2)*x^2*Cos[x]*Sqrt[a*Sec[x]^4]*Sin[x] + (1/2)*x^3*Cos[x]^2*Sqrt[a*Sec[x]^4]*(2*Log[Tan[x]] + Tan[x]^2)}


(* ::Section::Closed:: *)
(*Integrands involving four trig functions*)


(* ::Subsection::Closed:: *)
(*Integrands of the form (A + B Trig[x] + C Trig[x]) (b Trig[x] + c Trig[x])^n*)


{(B*Cos[x] + C*Sin[x])/(b*Cos[x] + c*Sin[x]), x, 1, ((b*B + c*C)*x)/(b^2 + c^2) + ((B*c - b*C)*Log[b*Cos[x] + c*Sin[x]])/(b^2 + c^2)}
{(B*Cos[x] + C*Sin[x])/(b*Cos[x] + c*Sin[x])^2, x, 3, -(((b*B + c*C)*ArcTanh[(c*Cos[x] - b*Sin[x])/Sqrt[b^2 + c^2]])/(b^2 + c^2)^(3/2)) - (B*c - b*C)/((b^2 + c^2)*(b*Cos[x] + c*Sin[x]))}
{(B*Cos[x] + C*Sin[x])/(b*Cos[x] + c*Sin[x])^3, x, 3, -((B*c - b*C)/(2*(b^2 + c^2)*(b*Cos[x] + c*Sin[x])^2)) + ((b*B + c*C)*Sin[x])/(b*(b^2 + c^2)*(b*Cos[x] + c*Sin[x]))}

{(Cos[x] - Sin[x])/(Cos[x] + Sin[x]), x, 1, Log[Cos[x] + Sin[x]]}
{(Cos[x] - I*Sin[x])/(Cos[x] + I*Sin[x]), x, 4, (I*Cos[x])/(Cos[x] + I*Sin[x])}


{(A + B*Cos[x] + C*Sin[x])/(b*Cos[x] + c*Sin[x]), x, 3, ((b*B + c*C)*x)/(b^2 + c^2) - (A*ArcTanh[(c*Cos[x] - b*Sin[x])/Sqrt[b^2 + c^2]])/Sqrt[b^2 + c^2] + ((B*c - b*C)*Log[b*Cos[x] + c*Sin[x]])/(b^2 + c^2)}
{(A + B*Cos[x] + C*Sin[x])/(b*Cos[x] + c*Sin[x])^2, x, 3, -(((b*B + c*C)*ArcTanh[(c*Cos[x] - b*Sin[x])/Sqrt[b^2 + c^2]])/(b^2 + c^2)^(3/2)) - (B*c - b*C + A*c*Cos[x] - A*b*Sin[x])/((b^2 + c^2)*(b*Cos[x] + c*Sin[x]))}
{(A + B*Cos[x] + C*Sin[x])/(b*Cos[x] + c*Sin[x])^3, x, 4, -((A*ArcTanh[(c*Cos[x] - b*Sin[x])/Sqrt[b^2 + c^2]])/(2*(b^2 + c^2)^(3/2))) - (B*c - b*C + A*c*Cos[x] - A*b*Sin[x])/(2*(b^2 + c^2)*(b*Cos[x] + c*Sin[x])^2) - (c*(b*B + c*C)*Cos[x] - b*(b*B + c*C)*Sin[x])/((b^2 + c^2)^2*(b*Cos[x] + c*Sin[x]))}


(* ::Subsection::Closed:: *)
(*Integrands of the form (A + B Trig[x] + C Trig[x]) (a + b Trig[x] + c Trig[x])^n*)


{(B*Cos[x] + C*Sin[x])/(a + b*Cos[x] + c*Sin[x]), x, 2, ((b*B + c*C)*x)/(b^2 + c^2) - (2*a*(b*B + c*C)*ArcTan[(c + (a - b)*Tan[x/2])/Sqrt[a^2 - b^2 - c^2]])/(Sqrt[a^2 - b^2 - c^2]*(b^2 + c^2)) + ((B*c - b*C)*Log[a + b*Cos[x] + c*Sin[x]])/(b^2 + c^2)}
{(B*Cos[x] + C*Sin[x])/(a + b*Cos[x] + c*Sin[x])^2, x, 2, -((2*(b*B + c*C)*ArcTan[(c + (a - b)*Tan[x/2])/Sqrt[a^2 - b^2 - c^2]])/(a^2 - b^2 - c^2)^(3/2)) + (B*c - b*C - a*C*Cos[x] + a*B*Sin[x])/((a^2 - b^2 - c^2)*(a + b*Cos[x] + c*Sin[x]))}
{(B*Cos[x] + C*Sin[x])/(a + b*Cos[x] + c*Sin[x])^3, x, 3, -((3*a*(b*B + c*C)*ArcTan[(c + (a - b)*Tan[x/2])/Sqrt[a^2 - b^2 - c^2]])/(a^2 - b^2 - c^2)^(5/2)) + (B*c - b*C - a*C*Cos[x] + a*B*Sin[x])/(2*(a^2 - b^2 - c^2)*(a + b*Cos[x] + c*Sin[x])^2) + (a*(B*c - b*C) - (2*b*B*c + (a^2 + 2*c^2)*C)*Cos[x] + (a^2*B + 2*b*(b*B + c*C))*Sin[x])/(2*(a^2 - b^2 - c^2)^2*(a + b*Cos[x] + c*Sin[x]))}


{(A + B*Cos[x] + C*Sin[x])/(a + b*Cos[x] + c*Sin[x]), x, 2, ((b*B + c*C)*x)/(b^2 + c^2) + (2*(A*(b^2 + c^2) - a*(b*B + c*C))*ArcTan[(c + (a - b)*Tan[x/2])/Sqrt[a^2 - b^2 - c^2]])/(Sqrt[a^2 - b^2 - c^2]*(b^2 + c^2)) + ((B*c - b*C)*Log[a + b*Cos[x] + c*Sin[x]])/(b^2 + c^2)}
{(A + B*Cos[x] + C*Sin[x])/(a + b*Cos[x] + c*Sin[x])^2, x, 2, (2*(a*A - b*B - c*C)*ArcTan[(c + (a - b)*Tan[x/2])/Sqrt[a^2 - b^2 - c^2]])/(a^2 - b^2 - c^2)^(3/2) + (B*c - b*C + (A*c - a*C)*Cos[x] - (A*b - a*B)*Sin[x])/((a^2 - b^2 - c^2)*(a + b*Cos[x] + c*Sin[x]))}
{(A + B*Cos[x] + C*Sin[x])/(a + b*Cos[x] + c*Sin[x])^3, x, 3, ((2*a^2*A + A*(b^2 + c^2) - 3*a*(b*B + c*C))*ArcTan[(c + (a - b)*Tan[x/2])/Sqrt[a^2 - b^2 - c^2]])/(a^2 - b^2 - c^2)^(5/2) + (B*c - b*C + (A*c - a*C)*Cos[x] - (A*b - a*B)*Sin[x])/(2*(a^2 - b^2 - c^2)*(a + b*Cos[x] + c*Sin[x])^2) + (a*(B*c - b*C) + (3*a*A*c - a^2*C - 2*c*(b*B + c*C))*Cos[x] - (3*a*A*b - a^2*B - 2*b*(b*B + c*C))*Sin[x])/(2*(a^2 - b^2 - c^2)^2*(a + b*Cos[x] + c*Sin[x]))}

{(b^2 + c^2 + a*b*Cos[x] + a*c*Sin[x])/(a + b*Cos[x] + c*Sin[x])^2, x, 1, -((c*Cos[x] - b*Sin[x])/(a + b*Cos[x] + c*Sin[x])), -((c*(a^2 - b^2 - c^2)*Cos[x] - b*(a^2 - b^2 - c^2)*Sin[x])/((a^2 - b^2 - c^2)*(a + b*Cos[x] + c*Sin[x])))}


{(d + b*e*Cos[x] + c*e*Sin[x])*(a + b*Cos[x] + c*Sin[x])^(5/2), x, 8, (2*(161*a^2*d + 63*(b^2 + c^2)*d + 15*a^3*e + 145*a*(b^2 + c^2)*e)*EllipticE[(1/2)*(x - ArcTan[b, c]), (2*Sqrt[b^2 + c^2])/(a + Sqrt[b^2 + c^2])]*Sqrt[a + b*Cos[x] + c*Sin[x]])/(105*Sqrt[(a + b*Cos[x] + c*Sin[x])/(a + Sqrt[b^2 + c^2])]) - (2*(a^2 - b^2 - c^2)*(56*a*d + 15*a^2*e + 25*(b^2 + c^2)*e)*EllipticF[(1/2)*(x - ArcTan[b, c]), (2*Sqrt[b^2 + c^2])/(a + Sqrt[b^2 + c^2])]*Sqrt[(a + b*Cos[x] + c*Sin[x])/(a + Sqrt[b^2 + c^2])])/(105*Sqrt[a + b*Cos[x] + c*Sin[x]]) - (2/7)*(a + b*Cos[x] + c*Sin[x])^(5/2)*(c*e*Cos[x] - b*e*Sin[x]) - (2/35)*(a + b*Cos[x] + c*Sin[x])^(3/2)*(c*(7*d + 5*a*e)*Cos[x] - b*(7*d + 5*a*e)*Sin[x]) - (2/105)*Sqrt[a + b*Cos[x] + c*Sin[x]]*(c*(56*a*d + 15*a^2*e + 25*(b^2 + c^2)*e)*Cos[x] - b*(56*a*d + 15*a^2*e + 25*(b^2 + c^2)*e)*Sin[x])}
{(d + b*e*Cos[x] + c*e*Sin[x])*(a + b*Cos[x] + c*Sin[x])^(3/2), x, 7, (2*(20*a*d + 3*a^2*e + 9*(b^2 + c^2)*e)*EllipticE[(1/2)*(x - ArcTan[b, c]), (2*Sqrt[b^2 + c^2])/(a + Sqrt[b^2 + c^2])]*Sqrt[a + b*Cos[x] + c*Sin[x]])/(15*Sqrt[(a + b*Cos[x] + c*Sin[x])/(a + Sqrt[b^2 + c^2])]) - (2*(a^2 - b^2 - c^2)*(5*d + 3*a*e)*EllipticF[(1/2)*(x - ArcTan[b, c]), (2*Sqrt[b^2 + c^2])/(a + Sqrt[b^2 + c^2])]*Sqrt[(a + b*Cos[x] + c*Sin[x])/(a + Sqrt[b^2 + c^2])])/(15*Sqrt[a + b*Cos[x] + c*Sin[x]]) - (2/5)*(a + b*Cos[x] + c*Sin[x])^(3/2)*(c*e*Cos[x] - b*e*Sin[x]) - (2/15)*Sqrt[a + b*Cos[x] + c*Sin[x]]*(c*(5*d + 3*a*e)*Cos[x] - b*(5*d + 3*a*e)*Sin[x])}
{(d + b*e*Cos[x] + c*e*Sin[x])*(a + b*Cos[x] + c*Sin[x])^(1/2), x, 6, (2*(3*d + a*e)*EllipticE[(1/2)*(x - ArcTan[b, c]), (2*Sqrt[b^2 + c^2])/(a + Sqrt[b^2 + c^2])]*Sqrt[a + b*Cos[x] + c*Sin[x]])/(3*Sqrt[(a + b*Cos[x] + c*Sin[x])/(a + Sqrt[b^2 + c^2])]) - (2*(a^2 - b^2 - c^2)*e*EllipticF[(1/2)*(x - ArcTan[b, c]), (2*Sqrt[b^2 + c^2])/(a + Sqrt[b^2 + c^2])]*Sqrt[(a + b*Cos[x] + c*Sin[x])/(a + Sqrt[b^2 + c^2])])/(3*Sqrt[a + b*Cos[x] + c*Sin[x]]) - (2/3)*Sqrt[a + b*Cos[x] + c*Sin[x]]*(c*e*Cos[x] - b*e*Sin[x])}
{(d + b*e*Cos[x] + c*e*Sin[x])/(a + b*Cos[x] + c*Sin[x])^(1/2), x, 5, (2*e*EllipticE[(1/2)*(x - ArcTan[b, c]), (2*Sqrt[b^2 + c^2])/(a + Sqrt[b^2 + c^2])]*Sqrt[a + b*Cos[x] + c*Sin[x]])/Sqrt[(a + b*Cos[x] + c*Sin[x])/(a + Sqrt[b^2 + c^2])] + (2*(d - a*e)*EllipticF[(1/2)*(x - ArcTan[b, c]), (2*Sqrt[b^2 + c^2])/(a + Sqrt[b^2 + c^2])]*Sqrt[(a + b*Cos[x] + c*Sin[x])/(a + Sqrt[b^2 + c^2])])/Sqrt[a + b*Cos[x] + c*Sin[x]]}
{(d + b*e*Cos[x] + c*e*Sin[x])/(a + b*Cos[x] + c*Sin[x])^(3/2), x, 6, (2*(d - a*e)*EllipticE[(1/2)*(x - ArcTan[b, c]), (2*Sqrt[b^2 + c^2])/(a + Sqrt[b^2 + c^2])]*Sqrt[a + b*Cos[x] + c*Sin[x]])/((a^2 - b^2 - c^2)*Sqrt[(a + b*Cos[x] + c*Sin[x])/(a + Sqrt[b^2 + c^2])]) + (2*e*EllipticF[(1/2)*(x - ArcTan[b, c]), (2*Sqrt[b^2 + c^2])/(a + Sqrt[b^2 + c^2])]*Sqrt[(a + b*Cos[x] + c*Sin[x])/(a + Sqrt[b^2 + c^2])])/Sqrt[a + b*Cos[x] + c*Sin[x]] + (2*(c*(d - a*e)*Cos[x] - b*(d - a*e)*Sin[x]))/((a^2 - b^2 - c^2)*Sqrt[a + b*Cos[x] + c*Sin[x]])}
{(d + b*e*Cos[x] + c*e*Sin[x])/(a + b*Cos[x] + c*Sin[x])^(5/2), x, 7, (2*(4*a*d - a^2*e - 3*(b^2 + c^2)*e)*EllipticE[(1/2)*(x - ArcTan[b, c]), (2*Sqrt[b^2 + c^2])/(a + Sqrt[b^2 + c^2])]*Sqrt[a + b*Cos[x] + c*Sin[x]])/(3*(a^2 - b^2 - c^2)^2*Sqrt[(a + b*Cos[x] + c*Sin[x])/(a + Sqrt[b^2 + c^2])]) - (2*(d - a*e)*EllipticF[(1/2)*(x - ArcTan[b, c]), (2*Sqrt[b^2 + c^2])/(a + Sqrt[b^2 + c^2])]*Sqrt[(a + b*Cos[x] + c*Sin[x])/(a + Sqrt[b^2 + c^2])])/(3*(a^2 - b^2 - c^2)*Sqrt[a + b*Cos[x] + c*Sin[x]]) + (2*(c*(d - a*e)*Cos[x] - b*(d - a*e)*Sin[x]))/(3*(a^2 - b^2 - c^2)*(a + b*Cos[x] + c*Sin[x])^(3/2)) + (2*(c*(4*a*d - a^2*e - 3*(b^2 + c^2)*e)*Cos[x] - b*(4*a*d - a^2*e - 3*(b^2 + c^2)*e)*Sin[x]))/(3*(a^2 - b^2 - c^2)^2*Sqrt[a + b*Cos[x] + c*Sin[x]])}


{(A + C*Sin[x])/(a + b*Cos[x] + I*b*Sin[x]), x, 1, ((2*a*A - I*b*C)*x)/(2*a^2) - (C*Cos[x])/(2*a) + ((2*I*a*A*b - a^2*C + b^2*C)*Log[a + b*Cos[x] + I*b*Sin[x]])/(2*a^2*b) + (I*C*Sin[x])/(2*a)}
{(A + B*Cos[x])/(a + b*Cos[x] + I*b*Sin[x]), x, 1, ((2*a*A - b*B)*x)/(2*a^2) + (I*B*Cos[x])/(2*a) + (I*(2*a*A*b - a^2*B - b^2*B)*Log[a + b*Cos[x] + I*b*Sin[x]])/(2*a^2*b) + (B*Sin[x])/(2*a)}
{(A + B*Cos[x]+C*Sin[x])/(a + b*Cos[x] + I*b*Sin[x]), x, 1, ((2*a*A - b*(B + I*C))*x)/(2*a^2) + (I*(2*a*A*b - a^2*(B - I*C) - b^2*(B + I*C))*Log[a + b*Cos[x] + I*b*Sin[x]])/(2*a^2*b) + (I*(B + I*C)*(Cos[x] - I*Sin[x]))/(2*a)}

{(A + C*Sin[x])/(a + b*Cos[x] - I*b*Sin[x]), x, 1, ((2*a*A + I*b*C)*x)/(2*a^2) - (C*Cos[x])/(2*a) - ((2*I*a*A*b + a^2*C - b^2*C)*Log[a + b*Cos[x] - I*b*Sin[x]])/(2*a^2*b) - (I*C*Sin[x])/(2*a)}
{(A + B*Cos[x])/(a + b*Cos[x] - I*b*Sin[x]), x, 1, ((2*a*A - b*B)*x)/(2*a^2) - (I*B*Cos[x])/(2*a) - (I*(2*a*A*b - a^2*B - b^2*B)*Log[a + b*Cos[x] - I*b*Sin[x]])/(2*a^2*b) + (B*Sin[x])/(2*a)}
{(A + B*Cos[x]+C*Sin[x])/(a + b*Cos[x] - I*b*Sin[x]), x, 1, ((2*a*A - b*B + I*b*C)*x)/(2*a^2) - (I*(2*a*A*b - b^2*(B - I*C) - a^2*(B + I*C))*Log[a + b*Cos[x] - I*b*Sin[x]])/(2*a^2*b) - ((I*B + C)*(Cos[x] + I*Sin[x]))/(2*a)}


(* ::Section::Closed:: *)
(*Products of functions of a trig function and its derivative*)


{Cos[a + b*x]*f[c, d, Sin[a + b*x], r, s], x, 1, Subst[Int[f[c, d, x, r, s], x], x, Sin[a + b*x]]/b}
{Sin[a + b*x]*f[c, d, Cos[a + b*x], r, s], x, 1, -(Subst[Int[f[c, d, x, r, s], x], x, Cos[a + b*x]]/b)}
{Sec[a + b*x]^2*f[c, d, Tan[a + b*x], r, s], x, 1, Subst[Int[f[c, d, x, r, s], x], x, Tan[a + b*x]]/b}
{Csc[a + b*x]^2*f[c, d, Cot[a + b*x], r, s], x, 1, -(Subst[Int[f[c, d, x, r, s], x], x, Cot[a + b*x]]/b)}


{Cos[x]/(a + b*Sin[x]), x, 2, Log[a + b*Sin[x]]/b}
{Cos[x]*(a + b*Sin[x])^n, x, 2, (a + b*Sin[x])^(1 + n)/(b*(1 + n))}

{Cos[x]*Csc[x]^(7/3), x, 1, (-3*Csc[x]^(4/3))/4}
{Cos[x]/Sqrt[1 + Sin[x]^2], x, 2, ArcSinh[Sin[x]]}
{Cos[x]/Sqrt[4 - Sin[x]^2], x, 2, ArcSin[Sin[x]/2]}
{Cos[3*x]/Sqrt[4 - Sin[3*x]^2], x, 2, ArcSin[Sin[3*x]/2]/3}
{Cos[x]*Sqrt[1 + Csc[x]], x, 4, ArcTanh[Sqrt[1 + Csc[x]]] + Sqrt[1 + Csc[x]]*Sin[x]}
{Cos[x]*Sqrt[4 - Sin[x]^2], x, 3, 2*ArcSin[Sin[x]/2] + (Sin[x]*Sqrt[4 - Sin[x]^2])/2}
{Cos[x]*Sin[x]*Sqrt[1 + Sin[x]^2], x, 2, (1/3)*(1 + Sin[x]^2)^(3/2)}
{Cos[x]/Sqrt[2*Sin[x] + Sin[x]^2], x, 2, 2*ArcTanh[Sin[x]/Sqrt[2*Sin[x] + Sin[x]^2]]}

{Cos[x]^3*Sqrt[Sin[x]], x, 3, (2/3)*Sin[x]^(3/2) - (2/7)*Sin[x]^(7/2)}
{Cos[x]^3*Sin[x]^(3/2), x, 3, (2/5)*Sin[x]^(5/2) - (2/9)*Sin[x]^(9/2)}
{Cos[x]^3*Sin[x]^(5/2), x, 3, (2/7)*Sin[x]^(7/2) - (2/11)*Sin[x]^(11/2)}
{Cos[x]^3/Sqrt[Sin[x]], x, 3, 2*Sqrt[Sin[x]] - (2/5)*Sin[x]^(5/2)}
{Cos[x]^3/Sqrt[Sin[x]^3], x, 4, -((2*Sin[x])/Sqrt[Sin[x]^3]) - (2/3)*Sqrt[Sin[x]^3]}
{Cos[x]^3*Sqrt[Csc[x]], x, 4, -(2/(5*Csc[x]^(5/2))) + 2/Sqrt[Csc[x]]}
{Cos[x]^3*Csc[x]^(9/2), x, 4, (2/3)*Csc[x]^(3/2) - (2/7)*Csc[x]^(7/2)}


{Sin[x]/(a + b*Cos[x]), x, 2, -(Log[a + b*Cos[x]]/b)}
{Sin[x]*(a + b*Cos[x])^n, x, 2, -((a + b*Cos[x])^(1 + n)/(b*(1 + n)))}

{Sin[x]/Sqrt[1 + Cos[x]^2], x, 2, -ArcSinh[Cos[x]]}
{Sin[x]^5/Sqrt[1 - 5*Cos[x]], x, 3, (1152*Sqrt[1 - 5*Cos[x]])/3125 + (64*(1 - 5*Cos[x])^(3/2))/3125 - (88*(1 - 5*Cos[x])^(5/2))/15625 - (8*(1 - 5*Cos[x])^(7/2))/21875 + (2*(1 - 5*Cos[x])^(9/2))/28125}


{Sec[x]^2/(a + b*Tan[x]), x, 2, Log[a + b*Tan[x]]/b}
{Sec[x]^2*(a + b*Tan[x])^n, x, 2, (a + b*Tan[x])^(1 + n)/(b*(1 + n))}

{1 + Sec[x]^2, x, 2, x + Tan[x]}
{2 + Tan[x]^2, x, 3, x + Tan[x]}
{Sec[x]^2*(1 + Cos[x]^2), x, 2, x + Tan[x]}
{Sec[x]^2*(1 + 1/(1 + Tan[x]^2)), x, 3, x + Tan[x]}
{Sec[x]^2*(2 + Tan[x]^2)/(1 + Tan[x]^2), x, 3, x + Tan[x]}

{Sec[x]^2/(1 - Tan[x]^2), x, 2, ArcTanh[Tan[x]]}
{Sec[x]^2/(9 + Tan[x]^2), x, 2, ArcTan[Tan[x]/3]/3}
{Sec[x]^2/(2 + 2*Tan[x] + Tan[x]^2), x, 2, ArcTan[1 + Tan[x]]}
{Sec[x]^2/(Tan[x]^2 + Tan[x]^3), x, 3, -Cot[x] + Log[1 + Cot[x]], -Cot[x] - Log[Tan[x]] + Log[1 + Tan[x]]}
{Sec[x]^2/(-Tan[x]^2 + Tan[x]^3), x, 3, Cot[x] + Log[1 - Cot[x]], Cot[x] + Log[1 - Tan[x]] - Log[Tan[x]]}
{Sec[x]^2/(3 - 4*Tan[x]^3), x, 6, ArcTan[(6^(1/3) + 4*Tan[x])/(2^(1/3)*3^(5/6))]/(3*2^(2/3)*3^(1/6)) - Log[3^(1/3) - 2^(2/3)*Tan[x]]/(3*6^(2/3)) + Log[3^(2/3) + 2^(2/3)*3^(1/3)*Tan[x] + 2*2^(1/3)*Tan[x]^2]/(6*6^(2/3))}
{Sec[x]^2/(11 - 5*Tan[x] + 5*Tan[x]^2), x, 2, -((2*ArcTan[Sqrt[5/39]*(1 - 2*Tan[x])])/Sqrt[195])}
{Sec[x]^2/(1 + Sec[x]^2 - 3*Tan[x]), x, 2, 2*ArcTanh[3 - 2*Tan[x]]}

{Sec[x]^2*(a + b*Tan[x])/(c + d*Tan[x]), x, 5, -(((b*c - a*d)*Log[c + d*Tan[x]])/d^2) + (b*Tan[x])/d}
{Sec[x]^2*(a + b*Tan[x])^2/(c + d*Tan[x]), x, 3, ((b*c - a*d)^2*Log[c + d*Tan[x]])/d^3 - (b*(b*c - a*d)*Tan[x])/d^2 + (a + b*Tan[x])^2/(2*d)}
{Sec[x]^2*(a + b*Tan[x])^3/(c + d*Tan[x]), x, 3, -(((b*c - a*d)^3*Log[c + d*Tan[x]])/d^4) + (b*(b*c - a*d)^2*Tan[x])/d^3 - ((b*c - a*d)*(a + b*Tan[x])^2)/(2*d^2) + (a + b*Tan[x])^3/(3*d)}
{Sec[x]^2*Tan[x]^2/(2 + Tan[x]^3)^2, x, 2, -1/(3*(2 + Tan[x]^3))}
{Sec[x]^2*Tan[x]^6*(1 + Tan[x]^2)^3, x, 3, Tan[x]^7/7 + Tan[x]^9/3 + (3*Tan[x]^11)/11 + Tan[x]^13/13}
{Sec[x]^2*(2 + Tan[x]^2)/(1 + Tan[x]^3), x, 5, -((2*ArcTan[(1 - 2*Tan[x])/Sqrt[3]])/Sqrt[3]) + Log[1 + Tan[x]]}

{Sec[x]^4*(-1 + Sec[x]^2)^2*Tan[x], x, 4, Tan[x]^6/6 + Tan[x]^8/8}
{Tan[x]^2*Sec[x]^4, x, 3, Tan[x]^3/3 + Tan[x]^5/5}
{Tan[x]^3*Sec[x]^4, x, 3, Tan[x]^4/4 + Tan[x]^6/6}
{Tan[x]^n*Sec[x]^4, x, 3, Tan[x]^(1 + n)/(1 + n) + Tan[x]^(3 + n)/(3 + n)}

{Sec[x]^2/Sqrt[4 - Sec[x]^2], x, 2, ArcSin[Tan[x]/Sqrt[3]]}
{Sec[x]^2/Sqrt[1 - 4*Tan[x]^2], x, 2, ArcSin[2*Tan[x]]/2}
{Sec[x]^2/Sqrt[-4 + Tan[x]^2], x, 2, ArcTanh[Tan[x]/Sqrt[-4 + Tan[x]^2]]}
{Sec[x]^2*Sqrt[1 - Cot[x]^2], x, 4, ArcSin[Cot[x]] + Sqrt[1 - Cot[x]^2]*Tan[x]}
{Sec[x]^2*Sqrt[1 - Tan[x]^2], x, 3, (1/2)*ArcSin[Tan[x]] + (1/2)*Tan[x]*Sqrt[1 - Tan[x]^2]}


{Csc[x]^2/(a + b*Cot[x]), x, 2, -(Log[a + b*Cot[x]]/b)}
{Csc[x]^2*(a + b*Cot[x])^n, x, 2, -((a + b*Cot[x])^(1 + n)/(b*(1 + n)))}

{1 + Csc[x]^2, x, 2, x - Cot[x]}
{2 + Cot[x]^2, x, 2, x - Cot[x]}
{(1 + Sin[x]^2)*Csc[x]^2, x, 2, x - Cot[x]}
{(1 + 1/(1 + Cot[x]^2))*Csc[x]^2, x, 3, x - Cot[x]}

{Csc[x]^2*(a + b*Cot[x])/(c + d*Cot[x]), x, 3, -((b*Cot[x])/d) + ((b*c - a*d)*Log[c + d*Cot[x]])/d^2}
{Csc[x]^2*(a + b*Cot[x])^2/(c + d*Cot[x]), x, 3, (b*(b*c - a*d)*Cot[x])/d^2 - (a + b*Cot[x])^2/(2*d) - ((b*c - a*d)^2*Log[c + d*Cot[x]])/d^3}
{Csc[x]^2*(a + b*Cot[x])^3/(c + d*Cot[x]), x, 3, -((b*(b*c - a*d)^2*Cot[x])/d^3) + ((b*c - a*d)*(a + b*Cot[x])^2)/(2*d^2) - (a + b*Cot[x])^3/(3*d) + ((b*c - a*d)^3*Log[c + d*Cot[x]])/d^4}

{Cot[x]^2*Csc[x]^4, x, 3, (-(1/3))*Cot[x]^3 - Cot[x]^5/5}
{Cot[x]^3*Csc[x]^4, x, 3, (-(1/4))*Cot[x]^4 - Cot[x]^6/6}
{Cot[x]^n*Csc[x]^4, x, 3, -(Cot[x]^(1 + n)/(1 + n)) - Cot[x]^(3 + n)/(3 + n)}


{(Sec[x]*Tan[x])/(a + b*Sec[x]), x, 2, Log[a + b*Sec[x]]/b}
{(Sec[2*x]*Tan[2*x])/(1 + Sec[2*x])^(3/2), x, 2, -(1/Sqrt[1 + Sec[2*x]])}
{(Sec[x]*Tan[x])/(1 + Sec[x]^2), x, 2, -ArcTan[Cos[x]]}
{(Sec[x]*Tan[x])/(9 + 4*Sec[x]^2), x, 2, (-(1/6))*ArcTan[(3*Cos[x])/2]}
{(Sec[x]*Tan[x])/(Sec[x] + Sec[x]^2), x, 2, -Log[1 + Cos[x]]}
{(Sec[x]*Tan[x])/Sqrt[4 + Sec[x]^2], x, 3, ArcSinh[Sec[x]/2]}
{(Sec[x]*Tan[x])/Sqrt[1 + Cos[x]^2], x, 2, Sqrt[1 + Cos[x]^2]*Sec[x]}
{Sqrt[1 + 5*Cos[3*x]^2]*Sec[3*x]*Tan[3*x], x, 3, (-(1/3))*Sqrt[5]*ArcSinh[Sqrt[5]*Cos[3*x]] + (1/3)*Sqrt[1 + 5*Cos[3*x]^2]*Sec[3*x]}
{(Sec[3*x]*Tan[3*x])/Sqrt[1 + 5*Cos[3*x]^2], x, 2, (Sqrt[1 + 5*Cos[3*x]^2]*Sec[3*x])/3}


{(Csc[x]*Cot[x])/(a + b*Csc[x]), x, 2, -Log[a + b*Csc[x]]/b}
{5^Csc[3*x]*Cot[3*x]*Csc[3*x], x, 2, -5^Csc[3*x]/(3*Log[5])}
{(Cot[x]*Csc[x])/(1 + Csc[x]^2), x, 2, ArcTan[Sin[x]]}
{(Cot[6*x]*Csc[6*x])/(5 - 11*Csc[6*x]^2)^2, x, 3, -(ArcTanh[Sqrt[5/11]*Sin[6*x]]/(60*Sqrt[55])) + Sin[6*x]/(60*(11 - 5*Sin[6*x]^2))}
{(Cot[x]*Csc[x])/Sqrt[1 + Sin[x]^2], x, 2, -(Csc[x]*Sqrt[1 + Sin[x]^2])}
{(Cot[5*x]*Csc[5*x]^3)/Sqrt[1 + Sin[5*x]^2], x, 3, (2/15)*Csc[5*x]*Sqrt[1 + Sin[5*x]^2] - (1/15)*Csc[5*x]^3*Sqrt[1 + Sin[5*x]^2]}


{Cos[x]^3*(a + b*Cos[x]^2)^3*Sin[x], x, 4, (a*(a + b*Cos[x]^2)^4)/(8*b^2) - (a + b*Cos[x]^2)^5/(10*b^2)}
{Sin[x]^3*(a + b*Sin[x]^2)^3*Cos[x], x, 4, -((a*(a + b*Sin[x]^2)^4)/(8*b^2)) + (a + b*Sin[x]^2)^5/(10*b^2)}


{Cos[x]*Cos[Sin[x]], x, 2, Sin[Sin[x]]}
{Cos[x]*Cos[Sin[x]]*Cos[Sin[Sin[x]]], x, 3, Sin[Sin[Sin[x]]]}
{Cos[x]*Sec[Sin[x]], x, 2, ArcTanh[Sin[Sin[x]]]}

{Cos[Cos[x]]*Sin[x], x, 2, -Sin[Cos[x]]}
{Sin[3*x]*Sin[Cos[3*x]], x, 2, Cos[Cos[3*x]]/3}
{Cos[x]*Cos[Cos[x]]*Sin[x]*Sin[Cos[x]], x, 3, Cos[x]/4 - (1/4)*Cos[Cos[x]]*Sin[Cos[x]] - (1/2)*Cos[x]*Sin[Cos[x]]^2}
{Cos[Cos[x]]*Sin[x]*Sin[6*Cos[x]]^2, x, 6, (-(1/2))*Sin[Cos[x]] + (1/44)*Sin[11*Cos[x]] + (1/52)*Sin[13*Cos[x]]}


(* ::Section::Closed:: *)
(*Problems from Calculus textbooks*)


(* ::Subsection::Closed:: *)
(*Anton Calculus, 4th Edition*)


{x*Sec[x]^2, x, 2, Log[Cos[x]] + x*Tan[x]}
{x*Cos[x^2]^4, x, 3, (3*x^2)/16 + (3/16)*Cos[x^2]*Sin[x^2] + (1/8)*Cos[x^2]^3*Sin[x^2]}

{Sqrt[Cos[x]]*Sin[x], x, 1, (-2*Cos[x]^(3/2))/3}
{Tan[E^(-2*x)]/E^(2*x), x, 2, Log[Cos[E^(-2*x)]]/2}
{(Sec[x]*Sin[2*x])/(1 + Cos[x]), x, 3, -2*Log[1 + Cos[x]]}
{x*Sec[3*x]^2, x, 2, (1/9)*Log[Cos[3*x]] + (1/3)*x*Tan[3*x]}
{Cos[2*Pi*x]/E^(2*Pi*x), x, 1, -(Cos[2*Pi*x]/(E^(2*Pi*x)*(4*Pi))) + Sin[2*Pi*x]/(E^(2*Pi*x)*(4*Pi))}
{Cos[x]^12*Sin[x]^10 - Cos[x]^10*Sin[x]^12, x, -23, (Cos[x]^11*Sin[x]^11)/11}


(* ::Subsection::Closed:: *)
(*Ayres Calculus, 1964 edition*)


{x*Cot[x^2], x, 2, Log[Sin[x^2]]/2}
{x*Sec[x^2]^2, x, 2, Tan[x^2]/2}
{Sin[8*x]/(9 + Sin[4*x]^4), x, 4, ArcTan[Sin[4*x]^2/3]/12}
{Cos[2*x]/(8 + Sin[2*x]^2), x, 2, ArcTan[Sin[2*x]/(2*Sqrt[2])]/(4*Sqrt[2])}
{x*(Cos[x^2]^3 - Sin[x^2]^3), x, 6, Cos[x^2]/2 - (1/6)*Cos[x^2]^3 + Sin[x^2]/2 - (1/6)*Sin[x^2]^3}
{Cos[x]*Sin[x]/(1 - Cos[x]), x, 3, Cos[x] + Log[1 - Cos[x]]}


(* ::Subsection::Closed:: *)
(*Edwards and Penney Calculus*)


{x*Cos[x^2], x, 1, Sin[x^2]/2}
{x^2*Cos[4*x^3], x, 1, Sin[4*x^3]/12}
{x^3*Cos[x^4], x, 1, Sin[x^4]/4}
{x*Sin[x^2/2], x, 1, -Cos[x^2/2]}
{x*Sec[x^2]*Tan[x^2], x, 2, Sec[x^2]/2}
{Tan[1/x]^2/x^2, x, 3, x^(-1) - Tan[x^(-1)]}
{x*Tan[1 + x^2], x, 2, -Log[Cos[1 + x^2]]/2}
{Sin[Pi*(1 + 2*x)], x, 1, Cos[2*Pi*x]/(2*Pi)}

{(Cot[x] + Csc[x]^2)/(1 - Cos[x]^2), x, 6, -Cot[x] - Cot[x]^3/3 - Csc[x]^2/2}


(* ::Subsection::Closed:: *)
(*Grossman Calculus*)


{-(x*Cos[x^2]), x, 2, -Sin[x^2]/2}
{x^2*Cos[4*x^3]*Cos[5*x^3], x, 4, Sin[x^3]/6 + (1/54)*Sin[9*x^3]}
{x^14*Sin[x^3], x, 5, -8*Cos[x^3] + 4*x^6*Cos[x^3] - (1/3)*x^12*Cos[x^3] - 8*x^3*Sin[x^3] + (4/3)*x^9*Sin[x^3]}
{(x^2*Sin[2*x^3])/E^(3*x^3), x, 2, ((-(2/39))*Cos[2*x^3])/E^(3*x^3) - ((1/13)*Sin[2*x^3])/E^(3*x^3)}


(* ::Subsection::Closed:: *)
(*Hughes, Hallet, Gleason, et al Calculus, 2nd Edition*)


{2*x*Cos[x^2], x, 2, Sin[x^2]}
{3*x^2*Cos[7 + x^3], x, 2, Sin[7 + x^3]}
{(1 + x^2)^(-1) + Sin[x], x, 3, ArcTan[x] - Cos[x]}
{x*Sin[1 + x^2], x, 1, -Cos[1 + x^2]/2}
{x*Cos[1 + x^2], x, 1, Sin[1 + x^2]/2}
{1 + x^2*Cos[x^3], x, 2, x + Sin[x^3]/3}
{x^2*Sin[1 + x^3], x, 1, -Cos[1 + x^3]/3}
{12*x^2*Cos[x^3], x, 2, 4*Sin[x^3]}
{(1 + x)*Sin[1 + x], x, 2, -((1 + x)*Cos[1 + x]) + Sin[1 + x]}
{x^5*Cos[x^3], x, 2, Cos[x^3]/3 + (1/3)*x^3*Sin[x^3]}
{Cos[x]/E^(3*x), x, 1, ((-(3/10))*Cos[x])/E^(3*x) + ((1/10)*Sin[x])/E^(3*x)}
{x^3*Sin[x^2], x, 2, (-(1/2))*x^2*Cos[x^2] + Sin[x^2]/2}
{x^3*Cos[x^2], x, 2, Cos[x^2]/2 + (1/2)*x^2*Sin[x^2]}
{Cos[x]*Cos[2*Sin[x]], x, 2, (1/2)*Sin[2*Sin[x]]}
{(Cos[x]*Sin[x])/(1 + Cos[x]^2), x, 2, (-(1/2))*Log[1 + Cos[x]^2]}
{(1 + Cos[x])*(x + Sin[x])^3, x, 1, (x + Sin[x])^4/4}


(* ::Subsection::Closed:: *)
(*Spivak Calculus*)


{(1 + Cos[x])*Csc[x]^2, x, 1, -((1 + Cos[x])*Csc[x])}
{Sin[x]*Tan[x]^2, x, 3, Cos[x] + Sec[x]}


(* ::Subsection::Closed:: *)
(*Stewart Calculus*)


{x*Csc[x]^2, x, 2, -(x*Cot[x]) + Log[Sin[x]]}
{Cos[x]*Sin[Pi/6 + x], x, 3, x/4 - (1/4)*Cos[Pi/6 + 2*x]}
{x*Sin[x^2]^3, x, 3, (-(1/2))*Cos[x^2] + (1/6)*Cos[x^2]^3}
{Sin[x]^2*Tan[x], x, 3, Cos[x]^2/2 - Log[Cos[x]]}
{Cos[x]^2*Cot[x]^3, x, 3, (-(1/2))*Csc[x]^2 - 2*Log[Sin[x]] + Sin[x]^2/2}
{Sec[x]*(1 - Sin[x]), x, 1, Log[1 + Sin[x]]}
{(1 + Cos[x])*Csc[x], x, 1, Log[1 - Cos[x]]}
{Cos[x]^2*(1 - Tan[x]^2), x, 4, Cos[x]*Sin[x]}
{Csc[2*x]*(Cos[x] + Sin[x]), x, 5, (-(1/2))*ArcTanh[Cos[x]] + (1/2)*ArcTanh[Sin[x]]}
{(Cos[x]*(-3 + 2*Sin[x]))/(2 - 3*Sin[x] + Sin[x]^2), x, 2, Log[2 - 3*Sin[x] + Sin[x]^2]}
{(Cos[x]^2*Sin[x])/(5 + Cos[x]^2), x, 3, Sqrt[5]*ArcTan[Cos[x]/Sqrt[5]] - Cos[x]}
{Cos[x]/(Sin[x] + Sin[x]^2), x, 3, Log[Sin[x]] - Log[1 + Sin[x]]}
{Cos[x]/(Sin[x] + Sin[x]^Sqrt[2]), x, 2, -2*(1 + Sqrt[2])*ArcTanh[1 + 2*Sin[x]^(-1 + Sqrt[2])]}
{1/(2*Sin[x] + Sin[2*x]), x, 7, (1/4)*Log[Tan[x/2]] + (1/8)*Tan[x/2]^2, (-(1/4))*ArcTanh[Cos[x]] + 1/(4*(1 + Cos[x]))}
{(-3 + 4*x + x^2)*Sin[2*x], x, 8, (7/4)*Cos[2*x] - 2*x*Cos[2*x] - (1/2)*x^2*Cos[2*x] + Sin[2*x] + (1/2)*x*Sin[2*x]}
{Cos[4*x]/E^(3*x), x, 1, ((-(3/25))*Cos[4*x])/E^(3*x) + ((4/25)*Sin[4*x])/E^(3*x)}
{(Cos[x]*Sin[x])/Sqrt[1 + Sin[x]], x, 3, -2*Sqrt[1 + Sin[x]] + (2/3)*(1 + Sin[x])^(3/2)}
{x + 60*Cos[x]^5*Sin[x]^4, x, 4, x^2/2 + 12*Sin[x]^5 - (120*Sin[x]^7)/7 + (20*Sin[x]^9)/3}


(* ::Subsection::Closed:: *)
(*Thomas Calculus, 8th Edition*)


{Cos[x]*(Sec[x] + Tan[x]), x, 3, x - Cos[x]}
{Cos[x]*(Sec[x]^3 + Tan[x]), x, 4, -Cos[x] + Tan[x]}
{(-(Cot[x]*Csc[x]) + Csc[x]^2)/2, x, 4, -(Cot[x]/2) + Csc[x]/2}
{-Csc[x]^2 + Sin[2*x], x, 3, -Cos[2*x]/2 + Cot[x]}
{2*Cot[2*x] - 3*Sin[3*x], x, 3, Cos[3*x] + Log[Sin[2*x]]}
{x*Sin[2*x^2], x, 1, -Cos[2*x^2]/4}
{-(Cos[1 - x]*Sin[1 - x]*Sqrt[1 + Sin[1 - x]^2]), x, 3, (1/3)*(1 + Sin[1 - x]^2)^(3/2)}
{(Cos[1/x]*Sin[1/x])/x^2, x, 1, (-(1/2))*Sin[1/x]^2}
{Cos[(1 + 3*x)/2]*Sin[(1 + 3*x)/2]^3, x, 1, (1/6)*Sin[1/2 + (3*x)/2]^4}
{4*x*Tan[x^2], x, 3, -2*Log[Cos[x^2]]}
{x*Sec[5 - x^2], x, 2, -ArcTanh[Sin[5 - x^2]]/2}
{Csc[x^(-1)]/x^2, x, 2, ArcTanh[Cos[1/x]]}
{(Csc[x] - Sec[x])*(Cos[x] + Sin[x]), x, 8, Log[Cos[x]] + Log[Sin[x]]}
{-Cos[3*x]*Sin[2*x] + Cos[2*x]*Sin[3*x], x, 5, -Cos[x]}
{4*x*Sec[2*x]^2, x, 3, Log[Cos[2*x]] + 2*x*Tan[2*x]}
{4*Sin[x]^2*Tan[x]^2, x, 4, -6*x + 6*Tan[x] - 2*Sin[x]^2*Tan[x]}
{Cos[x]^4*Cot[x]^2, x, 4, -((15*x)/8) - (15*Cot[x])/8 + (5/8)*Cos[x]^2*Cot[x] + (1/4)*Cos[x]^4*Cot[x]}
{16*Cos[x]^2*Sin[x]^2, x, 3, 2*x + 2*Cos[x]*Sin[x] - 4*Cos[x]^3*Sin[x]}
{8*Cos[x]^2*Sin[x]^4, x, 4, x/2 + (1/2)*Cos[x]*Sin[x] - Cos[x]^3*Sin[x] - (4/3)*Cos[x]^3*Sin[x]^3}
{35*Cos[x]^3*Sin[x]^4, x, 4, 7*Sin[x]^5 - 5*Sin[x]^7}
{4*Cos[x]^4*Sin[x]^4, x, 5, (3*x)/32 + (3/32)*Cos[x]*Sin[x] + (1/16)*Cos[x]^3*Sin[x] - (1/4)*Cos[x]^5*Sin[x] - (1/2)*Cos[x]^5*Sin[x]^3}
{Cos[x]/(-Sin[x] + Sin[x]^3), x, 2, ArcTanh[1 - 2*Sin[x]^2]}


(* ::Section::Closed:: *)
(*Problems from integration competitions*)


(* ::Subsection::Closed:: *)
(*MIT Integration Competition*)


{-1 + 2*Cos[x]^2 + Cos[x]*Sin[x], x, 3, Cos[x]*Sin[x] + Sin[x]^2/2}


(* ::Subsection::Closed:: *)
(*North Texas University Integration Competition*)


{Cos[x]^2 + Sin[x]^2, x, 3, x}
{-Cos[x]^2 + Sin[x]^2, x, 3, -(Cos[x]*Sin[x])}
{2^Sin[x]*Cos[x], x, 2, 2^Sin[x]/Log[2]}


(* ::Subsection::Closed:: *)
(*University of Wisconsin Integration Competition*)


{Tan[x]^3 + Tan[x]^5, x, 6, Tan[x]^4/4}
{x*Sec[x]*(2 + x*Tan[x]), x, 9, x^2*Sec[x]}


(* ::Section::Closed:: *)
(*Miscellaneous problems*)


(* Problems contributed by Michael Wester *)

(* This example involves several symbolic parameters
   => 1/sqrt(b^2 - a^2) log ([sqrt (b^2 - a^2) tan (x/2) + a + b]/
                            [sqrt (b^2 - a^2) tan (x/2) - a - b])   (a^2 < b^2)
      [Gradshteyn and Ryzhik 2.553(3)] *)
(*
{1/(a + b*Cos[x]), x, 0, Assumptions -> a^2 < b^2,
 1/Sqrt[b^2 - a^2]*Log[(Sqrt[b^2 - a^2]*Tan[x/2] + a + b)/
                       (Sqrt[b^2 - a^2]*Tan[x/2] - a - b)]}
*)
{1/(a + b*Cos[x]), x, 1, (2*ArcTan[(Sqrt[a^2 - b^2]*Tan[x/2])/(a + b)])/Sqrt[a^2 - b^2]}
(* The integral of 1/(a + 3 cos x + 4 sin x) can have 4 different forms
   depending on the value of a !   [Gradshteyn and Ryzhik 2.558(4)]
   => (a = 3) 1/4 log[3 + 4 tan (x/2)] *)
{1/(3 + 3*Cos[x] + 4*Sin[x]), x, 1, 1/4*Log[3 + 4*Tan[x/2]]}
(* => (a = 4) 1/3 log ([tan (x/2) + 1]/[tan (x/2) + 7]) *)
{1/(4 + 3*Cos[x] + 4*Sin[x]), x, 1, (-(2/3))*ArcTanh[(1/3)*(4 + Tan[x/2])]}
(* => (a = 5) -1/[2 + tan (x/2)] *)
{1/(5 + 3*Cos[x] + 4*Sin[x]), x, 1, -1/(2 + Tan[x/2]), -((4 - 5*Sin[x])/(4*(4*Cos[x] - 3*Sin[x])))}
(* => (a = 6) 2/sqrt(11) arctan ([3 tan (x/2) + 4]/sqrt(11)) *)
{1/(6 + 3*Cos[x] + 4*Sin[x]), x, 1, 2/Sqrt[11]*ArcTan[(3*Tan[x/2] + 4)/Sqrt[11]]}


{Sin[x]*Sin[2*x]*Sin[3*x], x, 3, (3*Sin[x]^4)/2 - (4*Sin[x]^6)/3}
{Cos[x]*Cos[2*x]*Cos[3*x], x, 5, x/4 + (1/8)*Sin[2*x] + (1/12)*Cos[3*x]*Sin[3*x] + (1/16)*Sin[4*x]}
{Cos[x]*Sin[2*x]*Sin[3*x], x, 11, x/4 + (1/8)*Sin[2*x] - (1/16)*Sin[4*x] - (1/24)*Sin[6*x]}
{Cos[2*x]*Cos[3*x]*Sin[x], x, 3, (-(3/2))*Cos[x]^2 + (5*Cos[x]^4)/2 - (4*Cos[x]^6)/3}


{x*Sin[x^2], x, 1, -Cos[x^2]/2}
{(-Cos[x] + Sin[x])*(Cos[x] + Sin[x])^5, x, 1, -(Cos[x] + Sin[x])^6/6}
{2*x*Sec[x]^2*Tan[x], x, 3, x*Sec[x]^2 - Tan[x]}
{(1 + Cos[x]^2)/(1 + Cos[2*x]), x, 4, x/2 + Tan[x]/2}


{Sin[x]/(Cos[x]^3 - Cos[x]^5), x, 3, Log[Tan[x]] + Tan[x]^2/2, ArcTanh[1 - 2*Cos[x]^2] + Sec[x]^2/2}
{Sec[x]*(5 - 11*Sec[x]^5)^2*Tan[x], x, 3, 25*Sec[x] - (55*Sec[x]^6)/3 + 11*Sec[x]^11}
{Sin[5*x]^3*Tan[5*x]^3, x, 4, (-(1/2))*ArcTanh[Sin[5*x]] + (1/2)*Sin[5*x] + (1/6)*Sin[5*x]*Tan[5*x]^2 - (1/15)*Sin[5*x]^3*Tan[5*x]^2}
{Sin[5*x]^3*Tan[5*x]^4, x, 3, (-(3/5))*Cos[5*x] + (1/15)*Cos[5*x]^3 - (3/5)*Sec[5*x] + (1/15)*Sec[5*x]^3}
{Sin[6*x]^5*Tan[6*x]^3, x, 5, (-(7/12))*ArcTanh[Sin[6*x]] + (7/12)*Sin[6*x] + (7/36)*Sin[6*x]*Tan[6*x]^2 - (7/90)*Sin[6*x]^3*Tan[6*x]^2 - (1/30)*Sin[6*x]^5*Tan[6*x]^2}
{(-1 + Sec[2*x]^2)^3*Sin[2*x], x, 3, (1/2)*Cos[2*x] + (3/2)*Sec[2*x] - (1/2)*Sec[2*x]^3 + (1/10)*Sec[2*x]^5}
{Sin[x]*Tan[x]^5, x, 4, (15/8)*ArcTanh[Sin[x]] - (15*Sin[x])/8 - (5/8)*Sin[x]*Tan[x]^2 + (1/4)*Sin[x]*Tan[x]^4}
{Cos[2*x]^5*Cot[2*x]^4, x, 3, 2*Csc[2*x] - (1/6)*Csc[2*x]^3 + 3*Sin[2*x] - (2/3)*Sin[2*x]^3 + (1/10)*Sin[2*x]^5}

{Cos[3*x]*(-1 + Csc[3*x]^2)^3*(1 - Sin[3*x]^2)^5, x, 4, (-(28/3))*Csc[3*x] + (8/9)*Csc[3*x]^3 - (1/15)*Csc[3*x]^5 - (56/3)*Sin[3*x] + (70/9)*Sin[3*x]^3 - (56/15)*Sin[3*x]^5 + (4/3)*Sin[3*x]^7 - (8/27)*Sin[3*x]^9 + (1/33)*Sin[3*x]^11}
{Cot[2*x]*(-1 + Csc[2*x]^2)^2*(1 - Sin[2*x]^2)^2, x, 4, Csc[2*x]^2 - (1/8)*Csc[2*x]^4 + 3*Log[Sin[2*x]] - Sin[2*x]^2 + (1/8)*Sin[2*x]^4}
{Cos[2*x]*(-1 + Csc[2*x]^2)^4*(1 - Sin[2*x]^2)^2, x, 4, 10*Csc[2*x] - (5/2)*Csc[2*x]^3 + (3/5)*Csc[2*x]^5 - (1/14)*Csc[2*x]^7 + (15/2)*Sin[2*x] - Sin[2*x]^3 + (1/10)*Sin[2*x]^5}
{Cot[3*x]*(-1 + Csc[3*x]^2)^3*(1 - Sin[3*x]^2)^2, x, 4, (-(5/3))*Csc[3*x]^2 + (5/12)*Csc[3*x]^4 - (1/18)*Csc[3*x]^6 - (10/3)*Log[Sin[3*x]] + (5/6)*Sin[3*x]^2 - (1/12)*Sin[3*x]^4}
{(1 + Cot[9*x]^2)^2*(1 + Tan[9*x]^2)^3, x, 3, (-(4/9))*Cot[9*x] - (1/27)*Cot[9*x]^3 + (2/3)*Tan[9*x] + (4/27)*Tan[9*x]^3 + (1/45)*Tan[9*x]^5}
{(Cos[x]*(9 - 7*Sin[x]^3)^2)/(1 - Sin[x]^2), x, 7, -2*Log[1 - Sin[x]] + 128*Log[1 + Sin[x]] - 49*Sin[x] + 63*Sin[x]^2 - (49*Sin[x]^3)/3 - (49*Sin[x]^5)/5}

{Cos[2*x]^4*Cot[2*x]^5, x, 3, Csc[2*x]^2 - (1/8)*Csc[2*x]^4 + 3*Log[Sin[2*x]] - Sin[2*x]^2 + (1/8)*Sin[2*x]^4}
{(Sec[x]*Tan[x]^2)/(4 + 3*Sec[x]), x, 4, (-(4/9))*ArcTanh[Sin[x]] + (2/9)*Sqrt[7]*ArcTanh[Tan[x/2]/Sqrt[7]] + Tan[x]/3}
{x*Sec[1 + x]*Tan[1 + x], x, 2, -ArcTanh[Sin[1 + x]] + x*Sec[1 + x]}
{Sin[2*x]/Sqrt[9 - Sin[x]^2], x, 3, -2*Sqrt[9 - Sin[x]^2]}
{Sin[2*x]/Sqrt[9 - Cos[x]^4], x, 4, -ArcSin[Cos[x]^2/3]}
{Cos[x^(-1)]/x^5, x, 4, 6*Cos[1/x] - (3*Cos[1/x])/x^2 - Sin[1/x]/x^3 + (6*Sin[1/x])/x}
{Cos[1 + x]^3*Sin[1 + x]^3, x, 3, (1/4)*Sin[1 + x]^4 - (1/6)*Sin[1 + x]^6}
{(1 + 2*x)^3*Sin[1 + 2*x]^2, x, 4, -((3*x)/4) - (3*x^2)/4 + (1/16)*(1 + 2*x)^4 + (3/8)*(1 + 2*x)*Cos[1 + 2*x]*Sin[1 + 2*x] - (1/4)*(1 + 2*x)^3*Cos[1 + 2*x]*Sin[1 + 2*x] - (3/16)*Sin[1 + 2*x]^2 + (3/8)*(1 + 2*x)^2*Sin[1 + 2*x]^2}
{(-1 + Sec[x])/(1 - Tan[x]), x, 4, -(x/2) + Sqrt[2]*ArcTanh[(1 + Tan[x/2])/Sqrt[2]] + (1/2)*Log[Cos[x] - Sin[x]]}
{x^2*Cos[3*x]*Cos[5*x], x, 8, (1/4)*x*Cos[2*x] + (1/64)*x*Cos[8*x] - (1/8)*Sin[2*x] + (1/4)*x^2*Sin[2*x] - (1/512)*Sin[8*x] + (1/16)*x^2*Sin[8*x]}
{Cos[x]^2*Sqrt[Tan[x]], x, 8, -(ArcTan[1 - Sqrt[2]*Sqrt[Tan[x]]]/(4*Sqrt[2])) + ArcTan[1 + Sqrt[2]*Sqrt[Tan[x]]]/(4*Sqrt[2]) + Log[1 - Sqrt[2]*Sqrt[Tan[x]] + Tan[x]]/(8*Sqrt[2]) - Log[1 + Sqrt[2]*Sqrt[Tan[x]] + Tan[x]]/(8*Sqrt[2]) + (1/2)*Cos[x]^2*Tan[x]^(3/2)}


{Sec[x]^2*(1 + Sin[x]), x, 2, Sec[x] + Tan[x]}

{10*x^9*Cos[x^5*Log[x]] - x^10*(x^4 + 5*x^4*Log[x])*Sin[x^5*Log[x]], x, 5, x^10*Cos[x^5*Log[x]]}
{Cos[x/2]^2*Tan[Pi/4 + x/2], x, 4, If[$VersionNumber > 6, x/2 - Cos[x]/2 - Log[Cos[Pi/4 + x/2]], x/2 - Cos[x]/2 - Log[-Cos[x/2] + Sin[x/2]]]}

{(2 + 3*x)^2*Sin[x]^3, x, 6, 14*Cos[x] - (2/3)*(2 + 3*x)^2*Cos[x] - (2*Cos[x]^3)/3 + 4*(2 + 3*x)*Sin[x] - (1/3)*(2 + 3*x)^2*Cos[x]*Sin[x]^2 + (2/3)*(2 + 3*x)*Sin[x]^3}
{Sec[x]^(1 + m)*Sin[x], x, 1, Sec[x]^m/m}
{Cos[a + b*x]^n*Sin[a + b*x]^(-2 - n), x, 1, -((Cos[a + b*x]^(1 + n)*Sin[a + b*x]^(-1 - n))/(b*(1 + n)))}
(* {Sin[(1+x)^2]/x, x, 0} *)
{(1 + Sin[x^2])^2/x^3, x, 8, -(1/(2*x^2)) + CosIntegral[x^2] - Sin[x^2]/x^2 - Sin[x^2]^2/(2*x^2) + (1/2)*SinIntegral[2*x^2]}
{1/(Sec[x] + Sin[x]*Tan[x]), x, 3, ArcTan[Sin[x]]}
{(a + b*x + c*x^2)*Sin[x], x, 8, (-a)*Cos[x] + 2*c*Cos[x] - b*x*Cos[x] - c*x^2*Cos[x] + b*Sin[x] + 2*c*x*Sin[x]}
{Sin[x^5]/x, x, 1, SinIntegral[x^5]/5}
{Sin[2^x]/(1 + 2^x), x, 7, (CosIntegral[1 + 2^x]*Sin[1])/Log[2] + SinIntegral[2^x]/Log[2] - (Cos[1]*SinIntegral[1 + 2^x])/Log[2]}

{x*Cos[2*x^2]*Sin[2*x^2]^(3/4), x, 1, Sin[2*x^2]^(7/4)/7}
{x*Sec[x^2]^2*Tan[x^2]^2, x, 1, Tan[x^2]^3/6}
{x^2*Cos[a + b*x^3]^7*Sin[a + b*x^3], x, 1, -Cos[a + b*x^3]^8/(24*b)}
{x^5*Cos[a + b*x^3]^7*Sin[a + b*x^3], x, 6, (35*x^3)/(3072*b) - (x^3*Cos[a + b*x^3]^8)/(24*b) + (35*Cos[a + b*x^3]*Sin[a + b*x^3])/(3072*b^2) + (35*Cos[a + b*x^3]^3*Sin[a + b*x^3])/(4608*b^2) + (7*Cos[a + b*x^3]^5*Sin[a + b*x^3])/(1152*b^2) + (Cos[a + b*x^3]^7*Sin[a + b*x^3])/(192*b^2)}
{x^5*Sec[a + b*x^3]^7*Tan[a + b*x^3], x, 6, -((5*ArcTanh[Sin[a + b*x^3]])/(336*b^2)) + (x^3*Sec[a + b*x^3]^7)/(21*b) - (5*Sec[a + b*x^3]*Tan[a + b*x^3])/(336*b^2) - (5*Sec[a + b*x^3]^3*Tan[a + b*x^3])/(504*b^2) - (Sec[a + b*x^3]^5*Tan[a + b*x^3])/(126*b^2)}

{Sec[x^(-1)]^2/x^2, x, 2, -Tan[x^(-1)]}
{3*x^2*Cos[x^3], x, 2, Sin[x^3]}

{(1 + 2*x)*Sec[1 + 2*x]^2, x, 2, (1/2)*Log[Cos[1 + 2*x]] + (1/2)*(1 + 2*x)*Tan[1 + 2*x]}


(* Problems requiring simplification of irreducible integrands *)
{(x^2*Cos[a + b*x])/Sqrt[3*Sin[a + b*x] + x^3] + x^4/(Sqrt[x^3 + 3*Sin[a + b*x]]*b) + (4*x*Sqrt[x^3 + 3*Sin[a + b*x]])/(3*b), x, 2, (2*x^2*Sqrt[x^3 + 3*Sin[a + b*x]])/(3*b)}
{x^2*(Cos[a + b*x]/Sqrt[3*Sin[a + b*x] + x^3]), x, 1, -(Defer[Int][x^4/Sqrt[x^3 + 3*Sin[a + b*x]], x]/b) - (4*Defer[Int][x*Sqrt[x^3 + 3*Sin[a + b*x]], x])/(3*b) + (2*x^2*Sqrt[x^3 + 3*Sin[a + b*x]])/(3*b)}
