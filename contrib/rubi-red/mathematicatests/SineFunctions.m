(* ::Package:: *)

(* ::Title:: *)
(*Integration Problems Involving Sines*)


(* ::Subsection::Closed:: *)
(*x^m Sin[a+b x]^n*)


(* Integrands of the form x^m*Sin[a+b*x]^n where m and n are integers *)
{x*Sin[a + b*x], x, 2, -((x*Cos[a + b*x])/b) + Sin[a + b*x]/b^2}
{x*Sin[a + b*x]^2, x, 2, x^2/4 - (x*Cos[a + b*x]*Sin[a + b*x])/(2*b) + Sin[a + b*x]^2/(4*b^2)}
{x*Sin[a + b*x]^3, x, 3, -((2*x*Cos[a + b*x])/(3*b)) + (2*Sin[a + b*x])/(3*b^2) - (x*Cos[a + b*x]*Sin[a + b*x]^2)/(3*b) + Sin[a + b*x]^3/(9*b^2)}

{x^2*Sin[a + b*x], x, 3, (2*Cos[a + b*x])/b^3 - (x^2*Cos[a + b*x])/b + (2*x*Sin[a + b*x])/b^2}
{x^2*Sin[a + b*x]^2, x, 3, -(x/(4*b^2)) + x^3/6 + (Cos[a + b*x]*Sin[a + b*x])/(4*b^3) - (x^2*Cos[a + b*x]*Sin[a + b*x])/(2*b) + (x*Sin[a + b*x]^2)/(2*b^2)}
{x^2*Sin[a + b*x]^3, x, 6, (14*Cos[a + b*x])/(9*b^3) - (2*x^2*Cos[a + b*x])/(3*b) - (2*Cos[a + b*x]^3)/(27*b^3) + (4*x*Sin[a + b*x])/(3*b^2) - (x^2*Cos[a + b*x]*Sin[a + b*x]^2)/(3*b) + (2*x*Sin[a + b*x]^3)/(9*b^2)}

{x^3*Sin[a + b*x], x, 4, (6*x*Cos[a + b*x])/b^3 - (x^3*Cos[a + b*x])/b - (6*Sin[a + b*x])/b^4 + (3*x^2*Sin[a + b*x])/b^2}
{x^3*Sin[a + b*x]^2, x, 4, -((3*x^2)/(8*b^2)) + x^4/8 + (3*x*Cos[a + b*x]*Sin[a + b*x])/(4*b^3) - (x^3*Cos[a + b*x]*Sin[a + b*x])/(2*b) - (3*Sin[a + b*x]^2)/(8*b^4) + (3*x^2*Sin[a + b*x]^2)/(4*b^2)}
{x^3*Sin[a + b*x]^3, x, 8, (40*x*Cos[a + b*x])/(9*b^3) - (2*x^3*Cos[a + b*x])/(3*b) - (40*Sin[a + b*x])/(9*b^4) + (2*x^2*Sin[a + b*x])/b^2 + (2*x*Cos[a + b*x]*Sin[a + b*x]^2)/(9*b^3) - (x^3*Cos[a + b*x]*Sin[a + b*x]^2)/(3*b) - (2*Sin[a + b*x]^3)/(27*b^4) + (x^2*Sin[a + b*x]^3)/(3*b^2)}

{Sin[a + b*x^n]/x, x, 3, (CosIntegral[b*x^n]*Sin[a])/n + (Cos[a]*SinIntegral[b*x^n])/n}
{Sin[a + b*x^n]^2/x, x, 7, -((Cos[2*a]*CosIntegral[2*b*x^n])/(2*n)) + Log[x]/2 + (Sin[2*a]*SinIntegral[2*b*x^n])/(2*n), -((Cos[2*a]*CosIntegral[2*b*x^n])/(2*n)) + Log[x^n]/(2*n) + (Sin[2*a]*SinIntegral[2*b*x^n])/(2*n)}
{Sin[a + b*x^n]^3/x, x, 9, (3*CosIntegral[b*x^n]*Sin[a])/(4*n) - (CosIntegral[3*b*x^n]*Sin[3*a])/(4*n) + (3*Cos[a]*SinIntegral[b*x^n])/(4*n) - (Cos[3*a]*SinIntegral[3*b*x^n])/(4*n)}

{Sin[a + b*x]/x^2, x, 4, b*Cos[a]*CosIntegral[b*x] - Sin[a + b*x]/x - b*Sin[a]*SinIntegral[b*x]}
{Sin[a + b*x]^2/x^2, x, 7, -(1/(2*x)) + Cos[2*a + 2*b*x]/(2*x) + b*CosIntegral[2*b*x]*Sin[2*a] + b*Cos[2*a]*SinIntegral[2*b*x]}
{Sin[a + b*x]^3/x^2, x, 10, (3/4)*b*Cos[a]*CosIntegral[b*x] - (3/4)*b*Cos[3*a]*CosIntegral[3*b*x] - (3*Sin[a + b*x])/(4*x) + Sin[3*a + 3*b*x]/(4*x) - (3/4)*b*Sin[a]*SinIntegral[b*x] + (3/4)*b*Sin[3*a]*SinIntegral[3*b*x]}

{Sin[a + b*x]/x^3, x, 5, -((b*Cos[a + b*x])/(2*x)) - (1/2)*b^2*CosIntegral[b*x]*Sin[a] - Sin[a + b*x]/(2*x^2) - (1/2)*b^2*Cos[a]*SinIntegral[b*x]}
{Sin[a + b*x]^2/x^3, x, 8, b^2*Cos[2*a]*CosIntegral[2*b*x] - (b*Cos[a + b*x]*Sin[a + b*x])/x - Sin[a + b*x]^2/(2*x^2) - b^2*Sin[2*a]*SinIntegral[2*b*x]}
{Sin[a + b*x]^3/x^3, x, 12, (-(3/8))*b^2*CosIntegral[b*x]*Sin[a] + (9/8)*b^2*CosIntegral[3*b*x]*Sin[3*a] - (3*b*Cos[a + b*x]*Sin[a + b*x]^2)/(2*x) - Sin[a + b*x]^3/(2*x^2) - (3/8)*b^2*Cos[a]*SinIntegral[b*x] + (9/8)*b^2*Cos[3*a]*SinIntegral[3*b*x]}


{x*Sin[a + b*x^2]^7, x, 3, -(Cos[a + b*x^2]/(2*b)) + Cos[a + b*x^2]^3/(2*b) - (3*Cos[a + b*x^2]^5)/(10*b) + Cos[a + b*x^2]^7/(14*b)}


{Sin[x]/Sqrt[x], x, 2, Sqrt[2*Pi]*FresnelS[Sqrt[2/Pi]*Sqrt[x]]}
{Sqrt[x]*Sin[x], x, 3, -(Sqrt[x]*Cos[x]) + Sqrt[Pi/2]*FresnelC[Sqrt[2/Pi]*Sqrt[x]]}


{Sin[x]^(3/2)/x^3, x, 1, (3/8)*Int[1/(x*Sqrt[Sin[x]]), x] - (9/8)*Int[Sin[x]^(3/2)/x, x] - (3*Cos[x]*Sqrt[Sin[x]])/(4*x) - Sin[x]^(3/2)/(2*x^2)}


(* ::Subsection::Closed:: *)
(*(a Sin[a+b x]^n)^m*)


(* Integrands of the form (a*Sin[x]^2)^m where m is a half-integer *)
{(a*Sin[x]^2)^(5/2),x, 3, (-a^2)*Cot[x]*Sqrt[a*Sin[x]^2] + (2/3)*a^2*Cos[x]^2*Cot[x]*Sqrt[a*Sin[x]^2] - (1/5)*a^2*Cos[x]^4*Cot[x]*Sqrt[a*Sin[x]^2]}
{(a*Sin[x]^2)^(3/2),x, 3, (-a)*Cot[x]*Sqrt[a*Sin[x]^2] + (1/3)*a*Cos[x]^2*Cot[x]*Sqrt[a*Sin[x]^2]}
{(a*Sin[x]^2)^(1/2), x, 2, (-Cot[x])*Sqrt[a*Sin[x]^2]}
{1/(a*Sin[x]^2)^(1/2), x, 2, -((ArcTanh[Cos[x]]*Sin[x])/Sqrt[a*Sin[x]^2])}
{1/(a*Sin[x]^2)^(3/2), x, 3, -(Cot[x]/(2*a*Sqrt[a*Sin[x]^2])) - (ArcTanh[Cos[x]]*Sin[x])/(2*a*Sqrt[a*Sin[x]^2])}
{1/(a*Sin[x]^2)^(5/2), x, 4, -((3*Cot[x])/(8*a^2*Sqrt[a*Sin[x]^2])) - (Cot[x]*Csc[x]^2)/(4*a^2*Sqrt[a*Sin[x]^2]) - (3*ArcTanh[Cos[x]]*Sin[x])/(8*a^2*Sqrt[a*Sin[x]^2])}


(* Integrands of the form (a*Sin[x]^4)^m where m is a half-integer *)
{(a*Sin[x]^3)^(5/2),x, 6, -((2*a^2*Sqrt[a*Sin[x]^3]*(195*EllipticF[Pi/4 - x/2, 2] + 195*Cos[x]*Sqrt[Sin[x]] + 117*Cos[x]*Sin[x]^(5/2) + 91*Cos[x]*Sin[x]^(9/2) + 77*Cos[x]*Sin[x]^(13/2)))/(1155*Sin[x]^(3/2)))}
{(a*Sin[x]^3)^(3/2),x, 4, -((2*a*Sqrt[a*Sin[x]^3]*(21*EllipticE[Pi/4 - x/2, 2] + 7*Cos[x]*Sin[x]^(3/2) + 5*Cos[x]*Sin[x]^(7/2)))/(45*Sin[x]^(3/2)))}
{(a*Sin[x]^3)^(1/2), x, 3, -((2*(EllipticF[Pi/4 - x/2, 2] + Cos[x]*Sqrt[Sin[x]])*Sqrt[a*Sin[x]^3])/(3*Sin[x]^(3/2)))}
{1/(a*Sin[x]^3)^(1/2), x, 3, -((2*(Cos[x] - EllipticE[Pi/4 - x/2, 2]*Sqrt[Sin[x]])*Sin[x])/Sqrt[a*Sin[x]^3])}
{1/(a*Sin[x]^3)^(3/2),x, 4, -((2*Csc[x]^2*(3*Cos[x] + 5*Sin[x]^2*(Cos[x] + EllipticF[Pi/4 - x/2, 2]*Sin[x]^(3/2))))/(21*a*Sqrt[a*Sin[x]^3]))}
{1/(a*Sin[x]^3)^(5/2),x, 6, -((2*Csc[x]^5*(45*Cos[x] + 11*Sin[x]^2*(5*Cos[x] + 7*Sin[x]^2*(Cos[x] + 3*(Cos[x] - EllipticE[Pi/4 - x/2, 2]*Sqrt[Sin[x]])*Sin[x]^2))))/(585*a^2*Sqrt[a*Sin[x]^3]))}


(* Integrands of the form (a*Sin[x]^4)^m where m is a half-integer *)
{(a*Sin[x]^4)^(5/2),x, 6, (-(63/256))*a^2*Cot[x]*Sqrt[a*Sin[x]^4] + (63/256)*a^2*x*Csc[x]^2*Sqrt[a*Sin[x]^4] - (21/128)*a^2*Cos[x]*Sin[x]*Sqrt[a*Sin[x]^4] - (21/160)*a^2*Cos[x]*Sin[x]^3*Sqrt[a*Sin[x]^4] - (9/80)*a^2*Cos[x]*Sin[x]^5*Sqrt[a*Sin[x]^4] - (1/10)*a^2*Cos[x]*Sin[x]^7*Sqrt[a*Sin[x]^4]}
{(a*Sin[x]^4)^(3/2),x, 4, (-(5/16))*a*Cot[x]*Sqrt[a*Sin[x]^4] + (5/16)*a*x*Csc[x]^2*Sqrt[a*Sin[x]^4] - (5/24)*a*Cos[x]*Sin[x]*Sqrt[a*Sin[x]^4] - (1/6)*a*Cos[x]*Sin[x]^3*Sqrt[a*Sin[x]^4]}
{(a*Sin[x]^4)^(1/2), x, 2, (-(1/2))*Cot[x]*Sqrt[a*Sin[x]^4] + (1/2)*x*Csc[x]^2*Sqrt[a*Sin[x]^4]}
{1/(a*Sin[x]^4)^(1/2), x, 2, -((Cos[x]*Sin[x])/Sqrt[a*Sin[x]^4])}
{1/(a*Sin[x]^4)^(3/2),x, 3, -((2*Cos[x]^2*Cot[x])/(3*a*Sqrt[a*Sin[x]^4])) - (Cos[x]^2*Cot[x]^3)/(5*a*Sqrt[a*Sin[x]^4]) - (Cos[x]*Sin[x])/(a*Sqrt[a*Sin[x]^4])}
{1/(a*Sin[x]^4)^(5/2),x, 3, -((4*Cos[x]^2*Cot[x])/(3*a^2*Sqrt[a*Sin[x]^4])) - (6*Cos[x]^2*Cot[x]^3)/(5*a^2*Sqrt[a*Sin[x]^4]) - (4*Cos[x]^2*Cot[x]^5)/(7*a^2*Sqrt[a*Sin[x]^4]) - (Cos[x]^2*Cot[x]^7)/(9*a^2*Sqrt[a*Sin[x]^4]) - (Cos[x]*Sin[x])/(a^2*Sqrt[a*Sin[x]^4])}


(* ::Subsection::Closed:: *)
(*x^m (a+b Sin[c+d x])^n*)


(* Integrands of the form x^m/(a+b*Sin[x]) where m is an integer *)
{1/(x*(a + b*Sin[x])), x, 0, Int[1/(x*(a + b*Sin[x])), x]}
{x/(a + b*Sin[x]), x, 8, -((I*x*Log[1 - (I*b*E^(I*x))/(a - Sqrt[a^2 - b^2])])/Sqrt[a^2 - b^2]) + (I*x*Log[1 - (I*b*E^(I*x))/(a + Sqrt[a^2 - b^2])])/Sqrt[a^2 - b^2] - PolyLog[2, (I*b*E^(I*x))/(a - Sqrt[a^2 - b^2])]/Sqrt[a^2 - b^2] + PolyLog[2, (I*b*E^(I*x))/(a + Sqrt[a^2 - b^2])]/Sqrt[a^2 - b^2]}
{x^2/(a + b*Sin[x]), x, 10, -((I*x^2*Log[1 - (I*b*E^(I*x))/(a - Sqrt[a^2 - b^2])])/Sqrt[a^2 - b^2]) + (I*x^2*Log[1 - (I*b*E^(I*x))/(a + Sqrt[a^2 - b^2])])/Sqrt[a^2 - b^2] - (2*x*PolyLog[2, (I*b*E^(I*x))/(a - Sqrt[a^2 - b^2])])/Sqrt[a^2 - b^2] + (2*x*PolyLog[2, (I*b*E^(I*x))/(a + Sqrt[a^2 - b^2])])/Sqrt[a^2 - b^2] - (2*I*PolyLog[3, (I*b*E^(I*x))/(a - Sqrt[a^2 - b^2])])/Sqrt[a^2 - b^2] + (2*I*PolyLog[3, (I*b*E^(I*x))/(a + Sqrt[a^2 - b^2])])/Sqrt[a^2 - b^2]}
{x^3/(a + b*Sin[x]), x, 12, -((I*x^3*Log[1 - (I*b*E^(I*x))/(a - Sqrt[a^2 - b^2])])/Sqrt[a^2 - b^2]) + (I*x^3*Log[1 - (I*b*E^(I*x))/(a + Sqrt[a^2 - b^2])])/Sqrt[a^2 - b^2] - (3*x^2*PolyLog[2, (I*b*E^(I*x))/(a - Sqrt[a^2 - b^2])])/Sqrt[a^2 - b^2] + (3*x^2*PolyLog[2, (I*b*E^(I*x))/(a + Sqrt[a^2 - b^2])])/Sqrt[a^2 - b^2] - (6*I*x*PolyLog[3, (I*b*E^(I*x))/(a - Sqrt[a^2 - b^2])])/Sqrt[a^2 - b^2] + (6*I*x*PolyLog[3, (I*b*E^(I*x))/(a + Sqrt[a^2 - b^2])])/Sqrt[a^2 - b^2] + (6*PolyLog[4, (I*b*E^(I*x))/(a - Sqrt[a^2 - b^2])])/Sqrt[a^2 - b^2] - (6*PolyLog[4, (I*b*E^(I*x))/(a + Sqrt[a^2 - b^2])])/Sqrt[a^2 - b^2]}

{1/(x*(a + a*Sin[x])), x, 2, Int[Csc[Pi/4 + x/2]^2/x, x]/(2*a)}
{x/(a + a*Sin[x]), x, 3, (2*Log[Cos[Pi/4 - x/2]])/a - (x*Tan[Pi/4 - x/2])/a}
{x^2/(a + a*Sin[x]), x, 6, (I*x^2)/a + (4*x*Log[1 + E^((I*Pi)/2 - I*x)])/a + (4*I*PolyLog[2, -E^((I*Pi)/2 - I*x)])/a - (x^2*Tan[Pi/4 - x/2])/a}
{x^3/(a + a*Sin[x]), x, 7, (I*x^3)/a + (6*x^2*Log[1 + E^((I*Pi)/2 - I*x)])/a + (12*I*x*PolyLog[2, -E^((I*Pi)/2 - I*x)])/a + (12*PolyLog[3, -E^((I*Pi)/2 - I*x)])/a - (x^3*Tan[Pi/4 - x/2])/a}

{1/(x*(a - a*Sin[x])), x, 1, Int[Sec[Pi/4 + x/2]^2/x, x]/(2*a)}
{x/(a - a*Sin[x]), x, 3, (2*Log[Cos[Pi/4 + x/2]])/a + (x*Tan[Pi/4 + x/2])/a}
{x^2/(a - a*Sin[x]), x, 6, -((I*x^2)/a) + (4*x*Log[1 + E^((I*Pi)/2 + I*x)])/a - (4*I*PolyLog[2, -E^((I*Pi)/2 + I*x)])/a + (x^2*Tan[Pi/4 + x/2])/a}
{x^3/(a - a*Sin[x]), x, 7, -((I*x^3)/a) + (6*x^2*Log[1 + E^((I*Pi)/2 + I*x)])/a - (12*I*x*PolyLog[2, -E^((I*Pi)/2 + I*x)])/a + (12*PolyLog[3, -E^((I*Pi)/2 + I*x)])/a + (x^3*Tan[Pi/4 + x/2])/a}


{x/(a + b*Sin[c + d*x])^2, x, 12, -((I*a*x*Log[1 - (I*b*E^(I*c + I*d*x))/(a - Sqrt[a^2 - b^2])])/((a^2 - b^2)^(3/2)*d)) + (I*a*x*Log[1 - (I*b*E^(I*c + I*d*x))/(a + Sqrt[a^2 - b^2])])/((a^2 - b^2)^(3/2)*d) - Log[a + b*Sin[c + d*x]]/((a^2 - b^2)*d^2) - (a*PolyLog[2, (I*b*E^(I*c + I*d*x))/(a - Sqrt[a^2 - b^2])])/((a^2 - b^2)^(3/2)*d^2) + (a*PolyLog[2, (I*b*E^(I*c + I*d*x))/(a + Sqrt[a^2 - b^2])])/((a^2 - b^2)^(3/2)*d^2) + (b*x*Cos[c + d*x])/((a^2 - b^2)*d*(a + b*Sin[c + d*x]))}
{(e + f*x)/(a + b*Sin[c + d*x])^2, x, 17, (2*a*e*ArcTan[(b + a*Tan[(1/2)*(c + d*x)])/Sqrt[a^2 - b^2]])/((a^2 - b^2)^(3/2)*d) - (I*a*f*x*Log[1 - (I*b*E^(I*c + I*d*x))/(a - Sqrt[a^2 - b^2])])/((a^2 - b^2)^(3/2)*d) + (I*a*f*x*Log[1 - (I*b*E^(I*c + I*d*x))/(a + Sqrt[a^2 - b^2])])/((a^2 - b^2)^(3/2)*d) - (f*Log[a + b*Sin[c + d*x]])/((a^2 - b^2)*d^2) - (a*f*PolyLog[2, (I*b*E^(I*c + I*d*x))/(a - Sqrt[a^2 - b^2])])/((a^2 - b^2)^(3/2)*d^2) + (a*f*PolyLog[2, (I*b*E^(I*c + I*d*x))/(a + Sqrt[a^2 - b^2])])/((a^2 - b^2)^(3/2)*d^2) + (b*e*Cos[c + d*x])/((a^2 - b^2)*d*(a + b*Sin[c + d*x])) + (b*f*x*Cos[c + d*x])/((a^2 - b^2)*d*(a + b*Sin[c + d*x]))}


(* Integrands of the form x^m*(a+a*Sin[x])^n where m is an integer and n is a half-integer *)
{x^3*Sqrt[a + a*Sin[x]], x, 5, -96*Sqrt[a + a*Sin[x]] + 12*x^2*Sqrt[a + a*Sin[x]] + 48*x*Sqrt[a + a*Sin[x]]*Tan[Pi/4 - x/2] - 2*x^3*Sqrt[a + a*Sin[x]]*Tan[Pi/4 - x/2]}
{x^2*Sqrt[a + a*Sin[x]], x, 4, 8*x*Sqrt[a + a*Sin[x]] + 16*Sqrt[a + a*Sin[x]]*Tan[Pi/4 - x/2] - 2*x^2*Sqrt[a + a*Sin[x]]*Tan[Pi/4 - x/2]}
{x*Sqrt[a + a*Sin[x]], x, 3, 4*Sqrt[a + a*Sin[x]] - 2*x*Sqrt[a + a*Sin[x]]*Tan[Pi/4 - x/2]}
{Sqrt[a + a*Sin[x]]/x, x, 5, (CosIntegral[x/2]*Sec[Pi/4 - x/2]*Sqrt[a + a*Sin[x]])/Sqrt[2] + (Sec[Pi/4 - x/2]*Sqrt[a + a*Sin[x]]*SinIntegral[x/2])/Sqrt[2]}
{Sqrt[a + a*Sin[x]]/x^2, x, 6, -(Sqrt[a + a*Sin[x]]/x) + (CosIntegral[x/2]*Sec[Pi/4 - x/2]*Sqrt[a + a*Sin[x]])/(2*Sqrt[2]) - (Sec[Pi/4 - x/2]*Sqrt[a + a*Sin[x]]*SinIntegral[x/2])/(2*Sqrt[2])}
{Sqrt[a + a*Sin[x]]/x^3, x, 7, -(Sqrt[a + a*Sin[x]]/(2*x^2)) - (CosIntegral[x/2]*Sec[Pi/4 - x/2]*Sqrt[a + a*Sin[x]])/(8*Sqrt[2]) - (Sec[Pi/4 - x/2]*Sqrt[a + a*Sin[x]]*SinIntegral[x/2])/(8*Sqrt[2]) - (Sqrt[a + a*Sin[x]]*Tan[Pi/4 - x/2])/(4*x)}

{x^3*(a + a*Sin[x])^(3/2), x, 9, (-(1280/9))*a*Sqrt[a + a*Sin[x]] + 16*a*x^2*Sqrt[a + a*Sin[x]] - (64/27)*a*Cos[Pi/4 - x/2]^2*Sqrt[a + a*Sin[x]] + (8/3)*a*x^2*Cos[Pi/4 - x/2]^2*Sqrt[a + a*Sin[x]] + (32/9)*a*x*Cos[Pi/4 - x/2]*Sin[Pi/4 - x/2]*Sqrt[a + a*Sin[x]] - (4/3)*a*x^3*Cos[Pi/4 - x/2]*Sin[Pi/4 - x/2]*Sqrt[a + a*Sin[x]] + (640/9)*a*x*Sqrt[a + a*Sin[x]]*Tan[Pi/4 - x/2] - (8/3)*a*x^3*Sqrt[a + a*Sin[x]]*Tan[Pi/4 - x/2]}
{x^2*(a + a*Sin[x])^(3/2), x, 7, (32/3)*a*x*Sqrt[a + a*Sin[x]] + (16/9)*a*x*Cos[Pi/4 - x/2]^2*Sqrt[a + a*Sin[x]] - (4/3)*a*x^2*Cos[Pi/4 - x/2]*Sin[Pi/4 - x/2]*Sqrt[a + a*Sin[x]] + (224/9)*a*Sqrt[a + a*Sin[x]]*Tan[Pi/4 - x/2] - (8/3)*a*x^2*Sqrt[a + a*Sin[x]]*Tan[Pi/4 - x/2] - (32/27)*a*Sin[Pi/4 - x/2]^2*Sqrt[a + a*Sin[x]]*Tan[Pi/4 - x/2]}
{x*(a + a*Sin[x])^(3/2), x, 4, (16/3)*a*Sqrt[a + a*Sin[x]] + (8/9)*a*Cos[Pi/4 - x/2]^2*Sqrt[a + a*Sin[x]] - (4/3)*a*x*Cos[Pi/4 - x/2]*Sin[Pi/4 - x/2]*Sqrt[a + a*Sin[x]] - (8/3)*a*x*Sqrt[a + a*Sin[x]]*Tan[Pi/4 - x/2]}
{(a + a*Sin[x])^(3/2)/x, x, 9, (3*a*CosIntegral[x/2]*Sec[Pi/4 - x/2]*Sqrt[a + a*Sin[x]])/(2*Sqrt[2]) - (a*CosIntegral[(3*x)/2]*Sec[Pi/4 - x/2]*Sqrt[a + a*Sin[x]])/(2*Sqrt[2]) + (3*a*Sec[Pi/4 - x/2]*Sqrt[a + a*Sin[x]]*SinIntegral[x/2])/(2*Sqrt[2]) + (a*Sec[Pi/4 - x/2]*Sqrt[a + a*Sin[x]]*SinIntegral[(3*x)/2])/(2*Sqrt[2])}
{(a + a*Sin[x])^(3/2)/x^2, x, 11, (a*Cos[Pi/4 + (3*x)/2]*Sec[Pi/4 - x/2]*Sqrt[a + a*Sin[x]])/(2*x) + (3*a*CosIntegral[x/2]*Sec[Pi/4 - x/2]*Sqrt[a + a*Sin[x]])/(4*Sqrt[2]) + (3*a*CosIntegral[(3*x)/2]*Sec[Pi/4 - x/2]*Sqrt[a + a*Sin[x]])/(4*Sqrt[2]) - (3*a*Sec[Pi/4 - x/2]*Sin[Pi/4 + x/2]*Sqrt[a + a*Sin[x]])/(2*x) - (3*a*Sec[Pi/4 - x/2]*Sqrt[a + a*Sin[x]]*SinIntegral[x/2])/(4*Sqrt[2]) + (3*a*Sec[Pi/4 - x/2]*Sqrt[a + a*Sin[x]]*SinIntegral[(3*x)/2])/(4*Sqrt[2])}
{(a + a*Sin[x])^(3/2)/x^3, x, 14, -((a*Cos[Pi/4 - x/2]^2*Sqrt[a + a*Sin[x]])/x^2) - (3*a*CosIntegral[x/2]*Sec[Pi/4 - x/2]*Sqrt[a + a*Sin[x]])/(16*Sqrt[2]) + (9*a*CosIntegral[(3*x)/2]*Sec[Pi/4 - x/2]*Sqrt[a + a*Sin[x]])/(16*Sqrt[2]) - (3*a*Cos[Pi/4 - x/2]*Sin[Pi/4 - x/2]*Sqrt[a + a*Sin[x]])/(2*x) - (3*a*Sec[Pi/4 - x/2]*Sqrt[a + a*Sin[x]]*SinIntegral[x/2])/(16*Sqrt[2]) - (9*a*Sec[Pi/4 - x/2]*Sqrt[a + a*Sin[x]]*SinIntegral[(3*x)/2])/(16*Sqrt[2])}

{x^3/Sqrt[a + a*Sin[x]], x, 9, (2*I*x^3*ArcTan[E^((I*Pi)/4 - (I*x)/2)]*Sec[Pi/4 - x/2]*Sqrt[a + a*Sin[x]])/a + (6*I*x^2*PolyLog[2, (-I)*E^((I*Pi)/4 - (I*x)/2)]*Sec[Pi/4 - x/2]*Sqrt[a + a*Sin[x]])/a - (6*I*x^2*PolyLog[2, I*E^((I*Pi)/4 - (I*x)/2)]*Sec[Pi/4 - x/2]*Sqrt[a + a*Sin[x]])/a + (24*x*PolyLog[3, (-I)*E^((I*Pi)/4 - (I*x)/2)]*Sec[Pi/4 - x/2]*Sqrt[a + a*Sin[x]])/a - (24*x*PolyLog[3, I*E^((I*Pi)/4 - (I*x)/2)]*Sec[Pi/4 - x/2]*Sqrt[a + a*Sin[x]])/a - (48*I*PolyLog[4, (-I)*E^((I*Pi)/4 - (I*x)/2)]*Sec[Pi/4 - x/2]*Sqrt[a + a*Sin[x]])/a + (48*I*PolyLog[4, I*E^((I*Pi)/4 - (I*x)/2)]*Sec[Pi/4 - x/2]*Sqrt[a + a*Sin[x]])/a}
{x^2/Sqrt[a + a*Sin[x]], x, 7, (2*I*x^2*ArcTan[E^((I*Pi)/4 - (I*x)/2)]*Sec[Pi/4 - x/2]*Sqrt[a + a*Sin[x]])/a + (4*I*x*PolyLog[2, (-I)*E^((I*Pi)/4 - (I*x)/2)]*Sec[Pi/4 - x/2]*Sqrt[a + a*Sin[x]])/a - (4*I*x*PolyLog[2, I*E^((I*Pi)/4 - (I*x)/2)]*Sec[Pi/4 - x/2]*Sqrt[a + a*Sin[x]])/a + (8*PolyLog[3, (-I)*E^((I*Pi)/4 - (I*x)/2)]*Sec[Pi/4 - x/2]*Sqrt[a + a*Sin[x]])/a - (8*PolyLog[3, I*E^((I*Pi)/4 - (I*x)/2)]*Sec[Pi/4 - x/2]*Sqrt[a + a*Sin[x]])/a}
{x/Sqrt[a + a*Sin[x]], x, 5, (2*I*x*ArcTan[E^((I*Pi)/4 - (I*x)/2)]*Sec[Pi/4 - x/2]*Sqrt[a + a*Sin[x]])/a + (2*I*PolyLog[2, (-I)*E^((I*Pi)/4 - (I*x)/2)]*Sec[Pi/4 - x/2]*Sqrt[a + a*Sin[x]])/a - (2*I*PolyLog[2, I*E^((I*Pi)/4 - (I*x)/2)]*Sec[Pi/4 - x/2]*Sqrt[a + a*Sin[x]])/a}
{1/(x*Sqrt[a + a*Sin[x]]), x, 2, (Int[Csc[Pi/4 + x/2]/x, x]*Sec[Pi/4 - x/2]*Sqrt[a + a*Sin[x]])/(2*a)}

(* {x^3/(a + a*Sin[x])^(3/2), x, 14, (3*I*(8 + x^2)*PolyLog[2, (-I)*E^((I*Pi)/4 - (I*x)/2)]*Sqrt[a*(1 + Sin[x])])/(Sqrt[2]*a^2*(Cos[x/2] + Sin[x/2])) - (3*I*(8 + x^2)*PolyLog[2, I*E^((I*Pi)/4 - (I*x)/2)]*Sqrt[a*(1 + Sin[x])])/(Sqrt[2]*a^2*(Cos[x/2] + Sin[x/2])) + (12*I*x*ArcTan[E^((I*Pi)/4 - (I*x)/2)]*Sec[Pi/4 - x/2]*Sqrt[a + a*Sin[x]])/a^2 + (I*x^3*ArcTan[E^((I*Pi)/4 - (I*x)/2)]*Sec[Pi/4 - x/2]*Sqrt[a + a*Sin[x]])/(2*a^2) + (6*x*PolyLog[3, (-I)*E^((I*Pi)/4 - (I*x)/2)]*Sec[Pi/4 - x/2]*Sqrt[a + a*Sin[x]])/a^2 - (6*x*PolyLog[3, I*E^((I*Pi)/4 - (I*x)/2)]*Sec[Pi/4 - x/2]*Sqrt[a + a*Sin[x]])/a^2 - (12*I*PolyLog[4, (-I)*E^((I*Pi)/4 - (I*x)/2)]*Sec[Pi/4 - x/2]*Sqrt[a + a*Sin[x]])/a^2 + (12*I*PolyLog[4, I*E^((I*Pi)/4 - (I*x)/2)]*Sec[Pi/4 - x/2]*Sqrt[a + a*Sin[x]])/a^2 - (3*x^2*Sec[Pi/4 - x/2]^2*Sqrt[a + a*Sin[x]])/(2*a^2) - (x^3*Sec[Pi/4 - x/2]^2*Sqrt[a + a*Sin[x]]*Tan[Pi/4 - x/2])/(4*a^2)} *)
{x^2/(a + a*Sin[x])^(3/2), x, 9, (I*x^2*ArcTan[E^((I*Pi)/4 - (I*x)/2)]*Sec[Pi/4 - x/2]*Sqrt[a + a*Sin[x]])/(2*a^2) - (2*ArcTanh[Sin[Pi/4 - x/2]]*Sec[Pi/4 - x/2]*Sqrt[a + a*Sin[x]])/a^2 + (I*x*PolyLog[2, (-I)*E^((I*Pi)/4 - (I*x)/2)]*Sec[Pi/4 - x/2]*Sqrt[a + a*Sin[x]])/a^2 - (I*x*PolyLog[2, I*E^((I*Pi)/4 - (I*x)/2)]*Sec[Pi/4 - x/2]*Sqrt[a + a*Sin[x]])/a^2 + (2*PolyLog[3, (-I)*E^((I*Pi)/4 - (I*x)/2)]*Sec[Pi/4 - x/2]*Sqrt[a + a*Sin[x]])/a^2 - (2*PolyLog[3, I*E^((I*Pi)/4 - (I*x)/2)]*Sec[Pi/4 - x/2]*Sqrt[a + a*Sin[x]])/a^2 - (x*Sec[Pi/4 - x/2]^2*Sqrt[a + a*Sin[x]])/a^2 - (x^2*Sec[Pi/4 - x/2]^2*Sqrt[a + a*Sin[x]]*Tan[Pi/4 - x/2])/(4*a^2)}
{x/(a + a*Sin[x])^(3/2), x, 6, (I*x*ArcTan[E^((I*Pi)/4 - (I*x)/2)]*Sec[Pi/4 - x/2]*Sqrt[a + a*Sin[x]])/(2*a^2) + (I*PolyLog[2, (-I)*E^((I*Pi)/4 - (I*x)/2)]*Sec[Pi/4 - x/2]*Sqrt[a + a*Sin[x]])/(2*a^2) - (I*PolyLog[2, I*E^((I*Pi)/4 - (I*x)/2)]*Sec[Pi/4 - x/2]*Sqrt[a + a*Sin[x]])/(2*a^2) - (Sec[Pi/4 - x/2]^2*Sqrt[a + a*Sin[x]])/(2*a^2) - (x*Sec[Pi/4 - x/2]^2*Sqrt[a + a*Sin[x]]*Tan[Pi/4 - x/2])/(4*a^2)}
{1/(x*(a + a*Sin[x])^(3/2)), x, 2, (Int[Csc[Pi/4 + x/2]^3/x, x]*Sec[Pi/4 - x/2]*Sqrt[a + a*Sin[x]])/(4*a^2)}


(* Integrands of the form x^m*(a-a*Sin[x])^n where m is an integer and n is a half-integer *)
{x^3*Sqrt[a - a*Sin[x]], x, 5, -96*Sqrt[a - a*Sin[x]] + 12*x^2*Sqrt[a - a*Sin[x]] - 48*x*Sqrt[a - a*Sin[x]]*Tan[Pi/4 + x/2] + 2*x^3*Sqrt[a - a*Sin[x]]*Tan[Pi/4 + x/2]}
{x^2*Sqrt[a - a*Sin[x]], x, 4, 8*x*Sqrt[a - a*Sin[x]] - 16*Sqrt[a - a*Sin[x]]*Tan[Pi/4 + x/2] + 2*x^2*Sqrt[a - a*Sin[x]]*Tan[Pi/4 + x/2]}
{x*Sqrt[a - a*Sin[x]], x, 3, 4*Sqrt[a - a*Sin[x]] + 2*x*Sqrt[a - a*Sin[x]]*Tan[Pi/4 + x/2]}
{Sqrt[a - a*Sin[x]]/x, x, 4, (CosIntegral[x/2]*Sec[Pi/4 + x/2]*Sqrt[a - a*Sin[x]])/Sqrt[2] - (Sec[Pi/4 + x/2]*Sqrt[a - a*Sin[x]]*SinIntegral[x/2])/Sqrt[2]}
{Sqrt[a - a*Sin[x]]/x^2, x, 5, -(Sqrt[a - a*Sin[x]]/x) - (CosIntegral[x/2]*Sec[Pi/4 + x/2]*Sqrt[a - a*Sin[x]])/(2*Sqrt[2]) - (Sec[Pi/4 + x/2]*Sqrt[a - a*Sin[x]]*SinIntegral[x/2])/(2*Sqrt[2])}
{Sqrt[a - a*Sin[x]]/x^3, x, 6, -(Sqrt[a - a*Sin[x]]/(2*x^2)) - (CosIntegral[x/2]*Sec[Pi/4 + x/2]*Sqrt[a - a*Sin[x]])/(8*Sqrt[2]) + (Sec[Pi/4 + x/2]*Sqrt[a - a*Sin[x]]*SinIntegral[x/2])/(8*Sqrt[2]) + (Sqrt[a - a*Sin[x]]*Tan[Pi/4 + x/2])/(4*x)}

{x^3/Sqrt[a - a*Sin[x]], x, 9, -((2*I*x^3*ArcTan[E^((I*Pi)/4 + (I*x)/2)]*Sec[Pi/4 + x/2]*Sqrt[a - a*Sin[x]])/a) + (6*I*x^2*PolyLog[2, (-I)*E^((I*Pi)/4 + (I*x)/2)]*Sec[Pi/4 + x/2]*Sqrt[a - a*Sin[x]])/a - (6*I*x^2*PolyLog[2, I*E^((I*Pi)/4 + (I*x)/2)]*Sec[Pi/4 + x/2]*Sqrt[a - a*Sin[x]])/a - (24*x*PolyLog[3, (-I)*E^((I*Pi)/4 + (I*x)/2)]*Sec[Pi/4 + x/2]*Sqrt[a - a*Sin[x]])/a + (24*x*PolyLog[3, I*E^((I*Pi)/4 + (I*x)/2)]*Sec[Pi/4 + x/2]*Sqrt[a - a*Sin[x]])/a - (48*I*PolyLog[4, (-I)*E^((I*Pi)/4 + (I*x)/2)]*Sec[Pi/4 + x/2]*Sqrt[a - a*Sin[x]])/a + (48*I*PolyLog[4, I*E^((I*Pi)/4 + (I*x)/2)]*Sec[Pi/4 + x/2]*Sqrt[a - a*Sin[x]])/a}
{x^2/Sqrt[a - a*Sin[x]], x, 7, -((2*I*x^2*ArcTan[E^((I*Pi)/4 + (I*x)/2)]*Sec[Pi/4 + x/2]*Sqrt[a - a*Sin[x]])/a) + (4*I*x*PolyLog[2, (-I)*E^((I*Pi)/4 + (I*x)/2)]*Sec[Pi/4 + x/2]*Sqrt[a - a*Sin[x]])/a - (4*I*x*PolyLog[2, I*E^((I*Pi)/4 + (I*x)/2)]*Sec[Pi/4 + x/2]*Sqrt[a - a*Sin[x]])/a - (8*PolyLog[3, (-I)*E^((I*Pi)/4 + (I*x)/2)]*Sec[Pi/4 + x/2]*Sqrt[a - a*Sin[x]])/a + (8*PolyLog[3, I*E^((I*Pi)/4 + (I*x)/2)]*Sec[Pi/4 + x/2]*Sqrt[a - a*Sin[x]])/a}
{x/Sqrt[a - a*Sin[x]], x, 5, -((2*I*x*ArcTan[E^((I*Pi)/4 + (I*x)/2)]*Sec[Pi/4 + x/2]*Sqrt[a - a*Sin[x]])/a) + (2*I*PolyLog[2, (-I)*E^((I*Pi)/4 + (I*x)/2)]*Sec[Pi/4 + x/2]*Sqrt[a - a*Sin[x]])/a - (2*I*PolyLog[2, I*E^((I*Pi)/4 + (I*x)/2)]*Sec[Pi/4 + x/2]*Sqrt[a - a*Sin[x]])/a}
{1/(x*Sqrt[a - a*Sin[x]]), x, 1, (Int[Sec[Pi/4 + x/2]/x, x]*Sec[Pi/4 + x/2]*Sqrt[a - a*Sin[x]])/(2*a)}


(* Integrands of the form x^m*(a+a*Sin[c+d*x])^n where m is an integer and n is a half-integer *)
{x^3*Sqrt[a + a*Sin[c + d*x]], x, 5, -((96*Sqrt[a + a*Sin[c + d*x]])/d^4) + (12*x^2*Sqrt[a + a*Sin[c + d*x]])/d^2 - (48*x*Sqrt[a + a*Sin[c + d*x]]*Tan[c/2 - Pi/4 + (d*x)/2])/d^3 + (2*x^3*Sqrt[a + a*Sin[c + d*x]]*Tan[c/2 - Pi/4 + (d*x)/2])/d}
{x^2*Sqrt[a + a*Sin[c + d*x]], x, 4, (8*x*Sqrt[a + a*Sin[c + d*x]])/d^2 - (16*Sqrt[a + a*Sin[c + d*x]]*Tan[c/2 - Pi/4 + (d*x)/2])/d^3 + (2*x^2*Sqrt[a + a*Sin[c + d*x]]*Tan[c/2 - Pi/4 + (d*x)/2])/d}
{x*Sqrt[a + a*Sin[c + d*x]], x, 3, (4*Sqrt[a + a*Sin[c + d*x]])/d^2 + (2*x*Sqrt[a + a*Sin[c + d*x]]*Tan[c/2 - Pi/4 + (d*x)/2])/d}
{Sqrt[a + a*Sin[c + d*x]]/x, x, 4, Cos[c/2 - Pi/4]*CosIntegral[(d*x)/2]*Sec[c/2 - Pi/4 + (d*x)/2]*Sqrt[a + a*Sin[c + d*x]] - Sec[c/2 - Pi/4 + (d*x)/2]*Sin[c/2 - Pi/4]*Sqrt[a + a*Sin[c + d*x]]*SinIntegral[(d*x)/2]}
{Sqrt[a + a*Sin[c + d*x]]/x^2, x, 5, -(Sqrt[a + a*Sin[c + d*x]]/x) - (1/2)*d*CosIntegral[(d*x)/2]*Sec[c/2 - Pi/4 + (d*x)/2]*Sin[c/2 - Pi/4]*Sqrt[a + a*Sin[c + d*x]] - (1/2)*d*Cos[c/2 - Pi/4]*Sec[c/2 - Pi/4 + (d*x)/2]*Sqrt[a + a*Sin[c + d*x]]*SinIntegral[(d*x)/2]}
{Sqrt[a + a*Sin[c + d*x]]/x^3, x, 6, -(Sqrt[a + a*Sin[c + d*x]]/(2*x^2)) - (1/8)*d^2*Cos[c/2 - Pi/4]*CosIntegral[(d*x)/2]*Sec[c/2 - Pi/4 + (d*x)/2]*Sqrt[a + a*Sin[c + d*x]] + (1/8)*d^2*Sec[c/2 - Pi/4 + (d*x)/2]*Sin[c/2 - Pi/4]*Sqrt[a + a*Sin[c + d*x]]*SinIntegral[(d*x)/2] + (d*Sqrt[a + a*Sin[c + d*x]]*Tan[c/2 - Pi/4 + (d*x)/2])/(4*x)}

(* {x^3/Sqrt[a + a*Sin[c + d*x]], x, 9, -((2*I*x^3*ArcTan[E^((1/4)*I*(2*c - Pi) + (I*d*x)/2)]*Sec[c/2 - Pi/4 + (d*x)/2]*Sqrt[a + a*Sin[c + d*x]])/(a*d)) + (6*I*x^2*PolyLog[2, (-I)*E^((1/4)*I*(2*c - Pi) + (I*d*x)/2)]*Sec[c/2 - Pi/4 + (d*x)/2]*Sqrt[a + a*Sin[c + d*x]])/(a*d^2) - (6*I*x^2*PolyLog[2, I*E^((1/4)*I*(2*c - Pi) + (I*d*x)/2)]*Sec[c/2 - Pi/4 + (d*x)/2]*Sqrt[a + a*Sin[c + d*x]])/(a*d^2) - (24*x*PolyLog[3, (-I)*E^((1/4)*I*(2*c - Pi) + (I*d*x)/2)]*Sec[c/2 - Pi/4 + (d*x)/2]*Sqrt[a + a*Sin[c + d*x]])/(a*d^3) + (24*x*PolyLog[3, I*E^((1/4)*I*(2*c - Pi) + (I*d*x)/2)]*Sec[c/2 - Pi/4 + (d*x)/2]*Sqrt[a + a*Sin[c + d*x]])/(a*d^3) - (48*I*PolyLog[4, (-I)*E^((1/4)*I*(2*c - Pi) + (I*d*x)/2)]*Sec[c/2 - Pi/4 + (d*x)/2]*Sqrt[a + a*Sin[c + d*x]])/(a*d^4) + (48*I*PolyLog[4, I*E^((1/4)*I*(2*c - Pi) + (I*d*x)/2)]*Sec[c/2 - Pi/4 + (d*x)/2]*Sqrt[a + a*Sin[c + d*x]])/(a*d^4)} *)
{x^2/Sqrt[a + a*Sin[c + d*x]], x, 7, -((2*I*x^2*ArcTan[E^((1/4)*I*(2*c - Pi) + (I*d*x)/2)]*Sec[c/2 - Pi/4 + (d*x)/2]*Sqrt[a + a*Sin[c + d*x]])/(a*d)) + (4*I*x*PolyLog[2, (-I)*E^((1/4)*I*(2*c - Pi) + (I*d*x)/2)]*Sec[c/2 - Pi/4 + (d*x)/2]*Sqrt[a + a*Sin[c + d*x]])/(a*d^2) - (4*I*x*PolyLog[2, I*E^((1/4)*I*(2*c - Pi) + (I*d*x)/2)]*Sec[c/2 - Pi/4 + (d*x)/2]*Sqrt[a + a*Sin[c + d*x]])/(a*d^2) - (8*PolyLog[3, (-I)*E^((1/4)*I*(2*c - Pi) + (I*d*x)/2)]*Sec[c/2 - Pi/4 + (d*x)/2]*Sqrt[a + a*Sin[c + d*x]])/(a*d^3) + (8*PolyLog[3, I*E^((1/4)*I*(2*c - Pi) + (I*d*x)/2)]*Sec[c/2 - Pi/4 + (d*x)/2]*Sqrt[a + a*Sin[c + d*x]])/(a*d^3)}
{x/Sqrt[a + a*Sin[c + d*x]], x, 5, -((2*I*x*ArcTan[E^((1/4)*I*(2*c - Pi) + (I*d*x)/2)]*Sec[c/2 - Pi/4 + (d*x)/2]*Sqrt[a + a*Sin[c + d*x]])/(a*d)) + (2*I*PolyLog[2, (-I)*E^((1/4)*I*(2*c - Pi) + (I*d*x)/2)]*Sec[c/2 - Pi/4 + (d*x)/2]*Sqrt[a + a*Sin[c + d*x]])/(a*d^2) - (2*I*PolyLog[2, I*E^((1/4)*I*(2*c - Pi) + (I*d*x)/2)]*Sec[c/2 - Pi/4 + (d*x)/2]*Sqrt[a + a*Sin[c + d*x]])/(a*d^2)}
{1/(x*Sqrt[a + a*Sin[c + d*x]]), x, 2, (Int[Sec[(1/4)*(2*c - Pi) + (d*x)/2]/x, x]*Sec[c/2 - Pi/4 + (d*x)/2]*Sqrt[a + a*Sin[c + d*x]])/(2*a)}


(* ::Subsection::Closed:: *)
(*(a+b Sin[c+d x]^2)^n*)


{(a + b*Sin[x]^2)^4, x, 5, (1/384)*(b^2*(104*a^2 + 104*a*b + 35*b^2) + 2*(2*a + b)*(96*a^3 + 144*a^2*b + 118*a*b^2 + 35*b^3))*x - (1/384)*b*(96*a^3 + 144*a^2*b + 118*a*b^2 + 35*b^3 + (2*a + b)*(104*a^2 + 104*a*b + 35*b^2))*Sin[2*x] + (1/768)*b^2*(104*a^2 + 104*a*b + 35*b^2)*Cos[2*x]*Sin[2*x] - (7/384)*b*(2*a + b)*(2*a + b - b*Cos[2*x])^2*Sin[2*x] - (1/128)*b*(2*a + b - b*Cos[2*x])^3*Sin[2*x]}
{(a + b*Sin[x]^2)^3, x, 4, (1/16)*(2*a + b)*(5*b^2 + 8*a*(a + b))*x - (1/48)*b*(12*a^2 + 12*a*b + 5*b^2 + 5*(2*a + b)^2)*Sin[2*x] + (5/96)*b^2*(2*a + b)*Cos[2*x]*Sin[2*x] - (1/48)*b*(2*a + b - b*Cos[2*x])^2*Sin[2*x]}
{(a + b*Sin[x]^2)^2, x, 3, (1/8)*(b^2 + 2*(2*a + b)^2)*x - (1/4)*b*(2*a + b)*Sin[2*x] + (1/16)*b^2*Cos[2*x]*Sin[2*x]}
{(a + b*Sin[x]^2), x, 2, a*x + (b*x)/2 - (1/2)*b*Cos[x]*Sin[x]}
{1/(a + b*Sin[x]^2), x, 2, ArcTan[(Sqrt[a + b]*Tan[x])/Sqrt[a]]/(Sqrt[a]*Sqrt[a + b]), -(ArcTan[(Sqrt[a]*Cot[x])/Sqrt[a + b]]/(Sqrt[a]*Sqrt[a + b]))}
{1/(a + b*Sin[x]^2)^2, x, 4, ((2*a + b)*ArcTan[(Sqrt[a + b]*Tan[x])/Sqrt[a]])/(2*a^(3/2)*(a + b)^(3/2)) + (b*Cos[x]*Sin[x])/(2*a*(a + b)*(a + b*Sin[x]^2)), ((2*a + b)*ArcTan[(Sqrt[a + b]*Tan[x])/Sqrt[a]])/(2*a^(3/2)*(a + b)^(3/2)) + (b*Sin[2*x])/(2*a*(a + b)*(2*a + b - b*Cos[2*x]))}
{1/(a + b*Sin[x]^2)^3, x, 5, ((8*a^2 + 8*a*b + 3*b^2)*ArcTan[(Sqrt[a + b]*Tan[x])/Sqrt[a]])/(8*a^(5/2)*(a + b)^(5/2)) + (b*Sin[2*x])/(2*a*(a + b)*(2*a + b - b*Cos[2*x])^2) + (3*b*(2*a + b)*Sin[2*x])/(8*a^2*(a + b)^2*(2*a + b - b*Cos[2*x]))}


{(a + b*Sin[x]^2)^(5/2), x, 8, (a*(23*a^2 + 23*a*b + 8*b^2)*Sqrt[(2*a + b - b*Cos[2*x])/a]*EllipticE[x, -(b/a)])/(15*Sqrt[2*a + b - b*Cos[2*x]]) + ((30*a^3 + 45*a^2*b + 31*a*b^2 + 8*b^3 - (2*a + b)*(23*a^2 + 23*a*b + 8*b^2))*Sqrt[(2*a + b - b*Cos[2*x])/a]*EllipticF[x, -(b/a)])/(30*Sqrt[2*a + b - b*Cos[2*x]]) - (1/15)*Sqrt[2]*b*(2*a + b)*Sqrt[2*a + b - b*Cos[2*x]]*Sin[2*x] - (b*(2*a + b - b*Cos[2*x])^(3/2)*Sin[2*x])/(20*Sqrt[2])}
{(a + b*Sin[x]^2)^(3/2), x, 7, (2*a*(2*a + b)*Sqrt[(2*a + b - b*Cos[2*x])/a]*EllipticE[x, -(b/a)])/(3*Sqrt[2*a + b - b*Cos[2*x]]) - (a*(a + b)*Sqrt[(2*a + b - b*Cos[2*x])/a]*EllipticF[x, -(b/a)])/(3*Sqrt[2*a + b - b*Cos[2*x]]) - (b*Sqrt[2*a + b - b*Cos[2*x]]*Sin[2*x])/(6*Sqrt[2])}
{(a + b*Sin[x]^2)^(1/2), x, 3, (a*Sqrt[(2*a + b - b*Cos[2*x])/a]*EllipticE[x, -(b/a)])/Sqrt[2*a + b - b*Cos[2*x]]}
{1/(a + b*Sin[x]^2)^(1/2), x, 3, (Sqrt[(2*a + b - b*Cos[2*x])/a]*EllipticF[x, -(b/a)])/Sqrt[2*a + b - b*Cos[2*x]]}
{1/(a + b*Sin[x]^2)^(3/2), x, 5, (Sqrt[(2*a + b - b*Cos[2*x])/a]*EllipticE[x, -(b/a)])/((a + b)*Sqrt[2*a + b - b*Cos[2*x]]) + (b*Sin[2*x])/(Sqrt[2]*a*(a + b)*Sqrt[2*a + b - b*Cos[2*x]])}
{1/(a + b*Sin[x]^2)^(5/2), x, 8, (2*(2*a + b)*Sqrt[(2*a + b - b*Cos[2*x])/a]*EllipticE[x, -(b/a)])/(3*a*(a + b)^2*Sqrt[2*a + b - b*Cos[2*x]]) - (Sqrt[(2*a + b - b*Cos[2*x])/a]*EllipticF[x, -(b/a)])/(3*a*(a + b)*Sqrt[2*a + b - b*Cos[2*x]]) + (Sqrt[2]*b*Sin[2*x])/(3*a*(a + b)*(2*a + b - b*Cos[2*x])^(3/2)) + (Sqrt[2]*b*(2*a + b)*Sin[2*x])/(3*a^2*(a + b)^2*Sqrt[2*a + b - b*Cos[2*x]])}


{(a - a*Sin[x]^2)^4, x, 6, (35*a^4*x)/128 + (35/128)*a^4*Cos[x]*Sin[x] + (35/192)*a^4*Cos[x]^3*Sin[x] + (7/48)*a^4*Cos[x]^5*Sin[x] + (1/8)*a^4*Cos[x]^7*Sin[x]}
{(a - a*Sin[x]^2)^3, x, 5, (5*a^3*x)/16 + (5/16)*a^3*Cos[x]*Sin[x] + (5/24)*a^3*Cos[x]^3*Sin[x] + (1/6)*a^3*Cos[x]^5*Sin[x]}
{(a - a*Sin[x]^2)^2, x, 4, (3*a^2*x)/8 + (3/8)*a^2*Cos[x]*Sin[x] + (1/4)*a^2*Cos[x]^3*Sin[x]}
{(a - a*Sin[x]^2), x, 2, (a*x)/2 + (1/2)*a*Cos[x]*Sin[x]}
{1/(a - a*Sin[x]^2), x, 3, Tan[x]/a}
{1/(a - a*Sin[x]^2)^2, x, 4, Tan[x]/a^2 + Tan[x]^3/(3*a^2)}
{1/(a - a*Sin[x]^2)^3, x, 5, Tan[x]/a^3 + (2*Tan[x]^3)/(3*a^3) + Tan[x]^5/(5*a^3)}
{1/(a - a*Sin[x]^2)^4, x, 5, Tan[x]/a^4 + Tan[x]^3/a^4 + (3*Tan[x]^5)/(5*a^4) + Tan[x]^7/(7*a^4)}
{1/(a - a*Sin[x]^2)^5, x, 5, Tan[x]/a^5 + (4*Tan[x]^3)/(3*a^5) + (6*Tan[x]^5)/(5*a^5) + (4*Tan[x]^7)/(7*a^5) + Tan[x]^9/(9*a^5)}


{(a - a*Sin[x]^2)^(5/2), x, 4, a^2*Sqrt[a*Cos[x]^2]*Tan[x] - (2/3)*a^2*Sqrt[a*Cos[x]^2]*Sin[x]^2*Tan[x] + (1/5)*a^2*Sqrt[a*Cos[x]^2]*Sin[x]^4*Tan[x]}
{(a - a*Sin[x]^2)^(3/2), x, 4, a*Sqrt[a*Cos[x]^2]*Tan[x] - (1/3)*a*Sqrt[a*Cos[x]^2]*Sin[x]^2*Tan[x]}
{(a - a*Sin[x]^2)^(1/2), x, 3, Sqrt[a*Cos[x]^2]*Tan[x]}
{1/(a - a*Sin[x]^2)^(1/2), x, 3, (ArcTanh[Sin[x]]*Cos[x])/Sqrt[a*Cos[x]^2]}
{1/(a - a*Sin[x]^2)^(3/2), x, 4, (ArcTanh[Sin[x]]*Cos[x])/(2*a*Sqrt[a*Cos[x]^2]) + Tan[x]/(2*a*Sqrt[a*Cos[x]^2])}
{1/(a - a*Sin[x]^2)^(5/2), x, 5, (3*ArcTanh[Sin[x]]*Cos[x])/(8*a^2*Sqrt[a*Cos[x]^2]) + (3*Tan[x])/(8*a^2*Sqrt[a*Cos[x]^2]) + (Sec[x]^2*Tan[x])/(4*a^2*Sqrt[a*Cos[x]^2])}


(* ::Subsection::Closed:: *)
(*x^m (a+b Sin[c+d x]^2)^n*)


{x/(a + b*Sin[x]^2), x, 9, -((I*x*Log[1 - (b*E^(2*I*x))/(2*a + b - 2*Sqrt[a]*Sqrt[a + b])])/(2*Sqrt[a]*Sqrt[a + b])) + (I*x*Log[1 - (b*E^(2*I*x))/(2*a + b + 2*Sqrt[a]*Sqrt[a + b])])/(2*Sqrt[a]*Sqrt[a + b]) - PolyLog[2, (b*E^(2*I*x))/(2*a + b - 2*Sqrt[a]*Sqrt[a + b])]/(4*Sqrt[a]*Sqrt[a + b]) + PolyLog[2, (b*E^(2*I*x))/(2*a + b + 2*Sqrt[a]*Sqrt[a + b])]/(4*Sqrt[a]*Sqrt[a + b])}
{x^2/(a + b*Sin[x]^2), x, 11, -((I*x^2*Log[1 - (b*E^(2*I*x))/(2*a + b - 2*Sqrt[a]*Sqrt[a + b])])/(2*Sqrt[a]*Sqrt[a + b])) + (I*x^2*Log[1 - (b*E^(2*I*x))/(2*a + b + 2*Sqrt[a]*Sqrt[a + b])])/(2*Sqrt[a]*Sqrt[a + b]) - (x*PolyLog[2, (b*E^(2*I*x))/(2*a + b - 2*Sqrt[a]*Sqrt[a + b])])/(2*Sqrt[a]*Sqrt[a + b]) + (x*PolyLog[2, (b*E^(2*I*x))/(2*a + b + 2*Sqrt[a]*Sqrt[a + b])])/(2*Sqrt[a]*Sqrt[a + b]) - (I*PolyLog[3, (b*E^(2*I*x))/(2*a + b - 2*Sqrt[a]*Sqrt[a + b])])/(4*Sqrt[a]*Sqrt[a + b]) + (I*PolyLog[3, (b*E^(2*I*x))/(2*a + b + 2*Sqrt[a]*Sqrt[a + b])])/(4*Sqrt[a]*Sqrt[a + b])}
{x^3/(a + b*Sin[x]^2), x, 13, -((I*x^3*Log[1 - (b*E^(2*I*x))/(2*a + b - 2*Sqrt[a]*Sqrt[a + b])])/(2*Sqrt[a]*Sqrt[a + b])) + (I*x^3*Log[1 - (b*E^(2*I*x))/(2*a + b + 2*Sqrt[a]*Sqrt[a + b])])/(2*Sqrt[a]*Sqrt[a + b]) - (3*x^2*PolyLog[2, (b*E^(2*I*x))/(2*a + b - 2*Sqrt[a]*Sqrt[a + b])])/(4*Sqrt[a]*Sqrt[a + b]) + (3*x^2*PolyLog[2, (b*E^(2*I*x))/(2*a + b + 2*Sqrt[a]*Sqrt[a + b])])/(4*Sqrt[a]*Sqrt[a + b]) - (3*I*x*PolyLog[3, (b*E^(2*I*x))/(2*a + b - 2*Sqrt[a]*Sqrt[a + b])])/(4*Sqrt[a]*Sqrt[a + b]) + (3*I*x*PolyLog[3, (b*E^(2*I*x))/(2*a + b + 2*Sqrt[a]*Sqrt[a + b])])/(4*Sqrt[a]*Sqrt[a + b]) + (3*PolyLog[4, (b*E^(2*I*x))/(2*a + b - 2*Sqrt[a]*Sqrt[a + b])])/(8*Sqrt[a]*Sqrt[a + b]) - (3*PolyLog[4, (b*E^(2*I*x))/(2*a + b + 2*Sqrt[a]*Sqrt[a + b])])/(8*Sqrt[a]*Sqrt[a + b])}


{x/(a + b*Sin[c + d*x]^2)^2, x, 13, -((I*(2*a + b)*x*Log[1 - (b*E^(2*I*c + 2*I*d*x))/(2*a + b - 2*Sqrt[a]*Sqrt[a + b])])/(4*a^(3/2)*(a + b)^(3/2)*d)) + (I*(2*a + b)*x*Log[1 - (b*E^(2*I*c + 2*I*d*x))/(2*a + b + 2*Sqrt[a]*Sqrt[a + b])])/(4*a^(3/2)*(a + b)^(3/2)*d) - Log[2*a + b - b*Cos[2*c + 2*d*x]]/(4*a*(a + b)*d^2) - ((2*a + b)*PolyLog[2, (b*E^(2*I*c + 2*I*d*x))/(2*a + b - 2*Sqrt[a]*Sqrt[a + b])])/(8*a^(3/2)*(a + b)^(3/2)*d^2) + ((2*a + b)*PolyLog[2, (b*E^(2*I*c + 2*I*d*x))/(2*a + b + 2*Sqrt[a]*Sqrt[a + b])])/(8*a^(3/2)*(a + b)^(3/2)*d^2) + (b*x*Sin[2*c + 2*d*x])/(2*a*(a + b)*d*(2*a + b - b*Cos[2*c + 2*d*x]))}


{x*Sqrt[Sin[x]^2], x, 3, Sqrt[Sin[x]^2] - x*Cot[x]*Sqrt[Sin[x]^2]}


(* ::Subsection::Closed:: *)
(*1 / (a+b Sin[c+d x]^n)		where n>2*)


(* Integrands of the form 1/(a+b*Sin[x]^n) where n is an integer *)
{1/(a + b*Sin[x]^3), x, 7, -((2*ArcTan[((-1)^(1/3)*b^(1/3) - a^(1/3)*Tan[x/2])/Sqrt[a^(2/3) - (-1)^(2/3)*b^(2/3)]])/(3*a^(2/3)*Sqrt[a^(2/3) - (-1)^(2/3)*b^(2/3)])) + (2*ArcTan[(b^(1/3) + a^(1/3)*Tan[x/2])/Sqrt[a^(2/3) - b^(2/3)]])/(3*a^(2/3)*Sqrt[a^(2/3) - b^(2/3)]) + (2*ArcTan[((-1)^(2/3)*b^(1/3) + a^(1/3)*Tan[x/2])/Sqrt[a^(2/3) + (-1)^(1/3)*b^(2/3)]])/(3*a^(2/3)*Sqrt[a^(2/3) + (-1)^(1/3)*b^(2/3)])}
{1/(a + b*Sin[x]^4), x, 7, ArcTan[((-a)^(1/4)*Cot[x])/Sqrt[Sqrt[-a] - Sqrt[b]]]/(2*(-a)^(3/4)*Sqrt[Sqrt[-a] - Sqrt[b]]) + ArcTan[((-a)^(1/4)*Cot[x])/Sqrt[Sqrt[-a] + Sqrt[b]]]/(2*(-a)^(3/4)*Sqrt[Sqrt[-a] + Sqrt[b]])}
{1/(a + b*Sin[x]^5), x, 11, -((2*ArcTan[((-1)^(1/5)*b^(1/5) - a^(1/5)*Tan[x/2])/Sqrt[a^(2/5) - (-1)^(2/5)*b^(2/5)]])/(5*a^(4/5)*Sqrt[a^(2/5) - (-1)^(2/5)*b^(2/5)])) - (2*ArcTan[((-1)^(3/5)*b^(1/5) - a^(1/5)*Tan[x/2])/Sqrt[a^(2/5) + (-1)^(1/5)*b^(2/5)]])/(5*a^(4/5)*Sqrt[a^(2/5) + (-1)^(1/5)*b^(2/5)]) + (2*ArcTan[(b^(1/5) + a^(1/5)*Tan[x/2])/Sqrt[a^(2/5) - b^(2/5)]])/(5*a^(4/5)*Sqrt[a^(2/5) - b^(2/5)]) + (2*ArcTan[((-1)^(2/5)*b^(1/5) + a^(1/5)*Tan[x/2])/Sqrt[a^(2/5) - (-1)^(4/5)*b^(2/5)]])/(5*a^(4/5)*Sqrt[a^(2/5) - (-1)^(4/5)*b^(2/5)]) + (2*ArcTan[((-1)^(4/5)*b^(1/5) + a^(1/5)*Tan[x/2])/Sqrt[a^(2/5) + (-1)^(3/5)*b^(2/5)]])/(5*a^(4/5)*Sqrt[a^(2/5) + (-1)^(3/5)*b^(2/5)])}
{1/(a + b*Sin[x]^6), x, 10, -(ArcTan[(a^(1/6)*Cot[x])/Sqrt[a^(1/3) + b^(1/3)]]/(3*a^(5/6)*Sqrt[a^(1/3) + b^(1/3)])) - ArcTan[(a^(1/6)*Cot[x])/Sqrt[a^(1/3) - (-1)^(1/3)*b^(1/3)]]/(3*a^(5/6)*Sqrt[a^(1/3) - (-1)^(1/3)*b^(1/3)]) - ArcTan[(a^(1/6)*Cot[x])/Sqrt[a^(1/3) + (-1)^(2/3)*b^(1/3)]]/(3*a^(5/6)*Sqrt[a^(1/3) + (-1)^(2/3)*b^(1/3)])}
{1/(a + b*Sin[x]^8), x, 13, ArcTan[((-a)^(1/8)*Cot[x])/Sqrt[(-a)^(1/4) - b^(1/4)]]/(4*(-a)^(7/8)*Sqrt[(-a)^(1/4) - b^(1/4)]) + ArcTan[((-a)^(1/8)*Cot[x])/Sqrt[(-a)^(1/4) - I*b^(1/4)]]/(4*(-a)^(7/8)*Sqrt[(-a)^(1/4) - I*b^(1/4)]) + ArcTan[((-a)^(1/8)*Cot[x])/Sqrt[(-a)^(1/4) + I*b^(1/4)]]/(4*(-a)^(7/8)*Sqrt[(-a)^(1/4) + I*b^(1/4)]) + ArcTan[((-a)^(1/8)*Cot[x])/Sqrt[(-a)^(1/4) + b^(1/4)]]/(4*(-a)^(7/8)*Sqrt[(-a)^(1/4) + b^(1/4)])}

{1/(a - b*Sin[x]^3), x, 7, -((2*ArcTan[(b^(1/3) - a^(1/3)*Tan[x/2])/Sqrt[a^(2/3) - b^(2/3)]])/(3*a^(2/3)*Sqrt[a^(2/3) - b^(2/3)])) - (2*ArcTan[((-1)^(2/3)*b^(1/3) - a^(1/3)*Tan[x/2])/Sqrt[a^(2/3) + (-1)^(1/3)*b^(2/3)]])/(3*a^(2/3)*Sqrt[a^(2/3) + (-1)^(1/3)*b^(2/3)]) + (2*ArcTan[((-1)^(1/3)*b^(1/3) + a^(1/3)*Tan[x/2])/Sqrt[a^(2/3) - (-1)^(2/3)*b^(2/3)]])/(3*a^(2/3)*Sqrt[a^(2/3) - (-1)^(2/3)*b^(2/3)])}
{1/(a - b*Sin[x]^4), x, 7, -(ArcTan[(a^(1/4)*Cot[x])/Sqrt[Sqrt[a] - Sqrt[b]]]/(2*a^(3/4)*Sqrt[Sqrt[a] - Sqrt[b]])) - ArcTan[(a^(1/4)*Cot[x])/Sqrt[Sqrt[a] + Sqrt[b]]]/(2*a^(3/4)*Sqrt[Sqrt[a] + Sqrt[b]])}
{1/(a - b*Sin[x]^5), x, 11, -((2*ArcTan[(b^(1/5) - a^(1/5)*Tan[x/2])/Sqrt[a^(2/5) - b^(2/5)]])/(5*a^(4/5)*Sqrt[a^(2/5) - b^(2/5)])) - (2*ArcTan[((-1)^(2/5)*b^(1/5) - a^(1/5)*Tan[x/2])/Sqrt[a^(2/5) - (-1)^(4/5)*b^(2/5)]])/(5*a^(4/5)*Sqrt[a^(2/5) - (-1)^(4/5)*b^(2/5)]) - (2*ArcTan[((-1)^(4/5)*b^(1/5) - a^(1/5)*Tan[x/2])/Sqrt[a^(2/5) + (-1)^(3/5)*b^(2/5)]])/(5*a^(4/5)*Sqrt[a^(2/5) + (-1)^(3/5)*b^(2/5)]) + (2*ArcTan[((-1)^(1/5)*b^(1/5) + a^(1/5)*Tan[x/2])/Sqrt[a^(2/5) - (-1)^(2/5)*b^(2/5)]])/(5*a^(4/5)*Sqrt[a^(2/5) - (-1)^(2/5)*b^(2/5)]) + (2*ArcTan[((-1)^(3/5)*b^(1/5) + a^(1/5)*Tan[x/2])/Sqrt[a^(2/5) + (-1)^(1/5)*b^(2/5)]])/(5*a^(4/5)*Sqrt[a^(2/5) + (-1)^(1/5)*b^(2/5)])}
{1/(a - b*Sin[x]^6), x, 10, -(ArcTan[(a^(1/6)*Cot[x])/Sqrt[a^(1/3) - b^(1/3)]]/(3*a^(5/6)*Sqrt[a^(1/3) - b^(1/3)])) - ArcTan[(a^(1/6)*Cot[x])/Sqrt[a^(1/3) + (-1)^(1/3)*b^(1/3)]]/(3*a^(5/6)*Sqrt[a^(1/3) + (-1)^(1/3)*b^(1/3)]) - ArcTan[(a^(1/6)*Cot[x])/Sqrt[a^(1/3) - (-1)^(2/3)*b^(1/3)]]/(3*a^(5/6)*Sqrt[a^(1/3) - (-1)^(2/3)*b^(1/3)])}
{1/(a - b*Sin[x]^8), x, 13, -(ArcTan[(a^(1/8)*Cot[x])/Sqrt[a^(1/4) - b^(1/4)]]/(4*a^(7/8)*Sqrt[a^(1/4) - b^(1/4)])) - ArcTan[(a^(1/8)*Cot[x])/Sqrt[a^(1/4) - I*b^(1/4)]]/(4*a^(7/8)*Sqrt[a^(1/4) - I*b^(1/4)]) - ArcTan[(a^(1/8)*Cot[x])/Sqrt[a^(1/4) + I*b^(1/4)]]/(4*a^(7/8)*Sqrt[a^(1/4) + I*b^(1/4)]) - ArcTan[(a^(1/8)*Cot[x])/Sqrt[a^(1/4) + b^(1/4)]]/(4*a^(7/8)*Sqrt[a^(1/4) + b^(1/4)])}

{1/(1 + Sin[x]^3), x, 5, -((2*ArcTan[((-1)^(1/3) - Tan[x/2])/Sqrt[1 - (-1)^(2/3)]])/(3*Sqrt[1 - (-1)^(2/3)])) + (2*ArcTan[((-1)^(2/3) + Tan[x/2])/Sqrt[1 + (-1)^(1/3)]])/(3*Sqrt[1 + (-1)^(1/3)]) - Cos[x]/(3*(1 + Sin[x]))}
{1/(1 + Sin[x]^4), x, 9, -(ArcTan[Cot[x]/Sqrt[1 - I]]/(2*Sqrt[1 - I])) - ArcTan[Cot[x]/Sqrt[1 + I]]/(2*Sqrt[1 + I])}
{1/(1 + Sin[x]^5), x, 8, -((2*ArcTan[((-1)^(1/5) - Tan[x/2])/Sqrt[1 - (-1)^(2/5)]])/(5*Sqrt[1 - (-1)^(2/5)])) - (2*ArcTan[((-1)^(3/5) - Tan[x/2])/Sqrt[1 + (-1)^(1/5)]])/(5*Sqrt[1 + (-1)^(1/5)]) + (2*ArcTan[((-1)^(2/5) + Tan[x/2])/Sqrt[1 - (-1)^(4/5)]])/(5*Sqrt[1 - (-1)^(4/5)]) + (2*ArcTan[((-1)^(4/5) + Tan[x/2])/Sqrt[1 + (-1)^(3/5)]])/(5*Sqrt[1 + (-1)^(3/5)]) - Cos[x]/(5*(1 + Sin[x]))}
{1/(1 + Sin[x]^6), x, 8, -(ArcTan[Cot[x]/Sqrt[2]]/(3*Sqrt[2])) - ArcTan[Cot[x]/Sqrt[1 - (-1)^(1/3)]]/(3*Sqrt[1 - (-1)^(1/3)]) - ArcTan[Cot[x]/Sqrt[1 + (-1)^(2/3)]]/(3*Sqrt[1 + (-1)^(2/3)])}
{1/(1 + Sin[x]^8), x, 11, -(ArcTan[Cot[x]/Sqrt[1 - (-1)^(1/4)]]/(4*Sqrt[1 - (-1)^(1/4)])) - ArcTan[Cot[x]/Sqrt[1 + (-1)^(1/4)]]/(4*Sqrt[1 + (-1)^(1/4)]) - ArcTan[Cot[x]/Sqrt[1 - (-1)^(3/4)]]/(4*Sqrt[1 - (-1)^(3/4)]) - ArcTan[Cot[x]/Sqrt[1 + (-1)^(3/4)]]/(4*Sqrt[1 + (-1)^(3/4)])}

{1/(1 - Sin[x]^3), x, 5, -((2*ArcTan[((-1)^(2/3) - Tan[x/2])/Sqrt[1 + (-1)^(1/3)]])/(3*Sqrt[1 + (-1)^(1/3)])) + (2*ArcTan[((-1)^(1/3) + Tan[x/2])/Sqrt[1 - (-1)^(2/3)]])/(3*Sqrt[1 - (-1)^(2/3)]) + Cos[x]/(3*(1 - Sin[x]))}
{1/(1 - Sin[x]^4), x, 5, -(ArcTan[Cot[x]/Sqrt[2]]/(2*Sqrt[2])) + Tan[x]/2}
{1/(1 - Sin[x]^5), x, 8, -((2*ArcTan[((-1)^(2/5) - Tan[x/2])/Sqrt[1 - (-1)^(4/5)]])/(5*Sqrt[1 - (-1)^(4/5)])) - (2*ArcTan[((-1)^(4/5) - Tan[x/2])/Sqrt[1 + (-1)^(3/5)]])/(5*Sqrt[1 + (-1)^(3/5)]) + (2*ArcTan[((-1)^(1/5) + Tan[x/2])/Sqrt[1 - (-1)^(2/5)]])/(5*Sqrt[1 - (-1)^(2/5)]) + (2*ArcTan[((-1)^(3/5) + Tan[x/2])/Sqrt[1 + (-1)^(1/5)]])/(5*Sqrt[1 + (-1)^(1/5)]) + Cos[x]/(5*(1 - Sin[x]))}
{1/(1 - Sin[x]^6), x, 8, -(ArcTan[Cot[x]/Sqrt[1 + (-1)^(1/3)]]/(3*Sqrt[1 + (-1)^(1/3)])) - ArcTan[Cot[x]/Sqrt[1 - (-1)^(2/3)]]/(3*Sqrt[1 - (-1)^(2/3)]) + Tan[x]/3}
{1/(1 - Sin[x]^8), x, 13, -(ArcTan[Cot[x]/Sqrt[1 - I]]/(4*Sqrt[1 - I])) - ArcTan[Cot[x]/Sqrt[1 + I]]/(4*Sqrt[1 + I]) - ArcTan[Cot[x]/Sqrt[2]]/(4*Sqrt[2]) + Tan[x]/4}


(* ::Subsection::Closed:: *)
(*(c+d x)^m Sin[a+b x]^n*)


(* Integrands of the form Sin[a+b*x]^m*(c+d*x)^n where m is an integer and n is a half-integer *)
{Sin[a + b*x]*Sqrt[c + d*x], x, 5, -((Sqrt[c + d*x]*Cos[a + b*x])/b) + (Sqrt[d]*Sqrt[Pi/2]*Cos[a - (b*c)/d]*FresnelC[(Sqrt[b]*Sqrt[2/Pi]*Sqrt[c + d*x])/Sqrt[d]])/b^(3/2) - (Sqrt[d]*Sqrt[Pi/2]*FresnelS[(Sqrt[b]*Sqrt[2/Pi]*Sqrt[c + d*x])/Sqrt[d]]*Sin[a - (b*c)/d])/b^(3/2)}
{Sin[a + b*x]/Sqrt[c + d*x], x, 4, (Sqrt[2*Pi]*Cos[(b*c - a*d)/d]*FresnelS[(Sqrt[b]*Sqrt[2/Pi]*Sqrt[c + d*x])/Sqrt[d]])/(Sqrt[b]*Sqrt[d]) - (Sqrt[2*Pi]*FresnelC[(Sqrt[b]*Sqrt[2/Pi]*Sqrt[c + d*x])/Sqrt[d]]*Sin[(b*c - a*d)/d])/(Sqrt[b]*Sqrt[d])}
{Sin[a + b*x]/(c + d*x)^(3/2), x, 5, (2*Sqrt[b]*Sqrt[2*Pi]*Cos[a - (b*c)/d]*FresnelC[(Sqrt[b]*Sqrt[2/Pi]*Sqrt[c + d*x])/Sqrt[d]])/d^(3/2) - (2*Sqrt[b]*Sqrt[2*Pi]*FresnelS[(Sqrt[b]*Sqrt[2/Pi]*Sqrt[c + d*x])/Sqrt[d]]*Sin[a - (b*c)/d])/d^(3/2) - (2*Sin[a + b*x])/(d*Sqrt[c + d*x])}

{Sin[a + b*x]^2*Sqrt[c + d*x], x, 8, (c + d*x)^(3/2)/(3*d) + (Sqrt[d]*Sqrt[Pi]*Cos[2*(a - (b*c)/d)]*FresnelS[(2*Sqrt[b]*Sqrt[c + d*x])/(Sqrt[d]*Sqrt[Pi])])/(8*b^(3/2)) + (Sqrt[d]*Sqrt[Pi]*FresnelC[(2*Sqrt[b]*Sqrt[c + d*x])/(Sqrt[d]*Sqrt[Pi])]*Sin[2*(a - (b*c)/d)])/(8*b^(3/2)) - (Sqrt[c + d*x]*Sin[2*a + 2*b*x])/(4*b)}
{Sin[a + b*x]^2/Sqrt[c + d*x], x, 6, Sqrt[c + d*x]/d - (Sqrt[Pi]*Cos[2*a - (2*b*c)/d]*FresnelC[(2*Sqrt[b]*Sqrt[c + d*x])/(Sqrt[d]*Sqrt[Pi])])/(2*Sqrt[b]*Sqrt[d]) + (Sqrt[Pi]*FresnelS[(2*Sqrt[b]*Sqrt[c + d*x])/(Sqrt[d]*Sqrt[Pi])]*Sin[2*a - (2*b*c)/d])/(2*Sqrt[b]*Sqrt[d])}
{Sin[a + b*x]^2/(c + d*x)^(3/2), x, 6, -((2*Sin[a + b*x]^2)/(d*Sqrt[c + d*x])) + (2*Sqrt[b]*Sqrt[Pi]*Cos[2*(a - (b*c)/d)]*FresnelS[(2*Sqrt[b]*Sqrt[c + d*x])/(Sqrt[d]*Sqrt[Pi])])/d^(3/2) + (2*Sqrt[b]*Sqrt[Pi]*FresnelC[(2*Sqrt[b]*Sqrt[c + d*x])/(Sqrt[d]*Sqrt[Pi])]*Sin[2*(a - (b*c)/d)])/d^(3/2)}


(* ::Subsection::Closed:: *)
(*(d+e x)^m Sin[a+b x+c x^2]^n*)


(* Integrands of the form x^m*Sin[a+b*x+c*x^2] where m is an integer *)
{x^2*Sin[a + b*x + c*x^2], x, 12, (b*Cos[a + b*x + c*x^2])/(4*c^2) - (x*Cos[a + b*x + c*x^2])/(2*c) + (Sqrt[Pi/2]*FresnelC[(b + 2*c*x)/(Sqrt[c]*Sqrt[2*Pi])]*(2*c*Cos[a - b^2/(4*c)] + b^2*Sin[a - b^2/(4*c)]))/(4*c^(5/2)) + (Sqrt[Pi/2]*FresnelS[(b + 2*c*x)/(Sqrt[c]*Sqrt[2*Pi])]*(b^2*Cos[a - b^2/(4*c)] - 2*c*Sin[a - b^2/(4*c)]))/(4*c^(5/2))}
{x*Sin[a + b*x + c*x^2], x, 6, -(Cos[a + b*x + c*x^2]/(2*c)) - (b*Sqrt[Pi/2]*Cos[(b^2 - 4*a*c)/(4*c)]*FresnelS[(b + 2*c*x)/(Sqrt[c]*Sqrt[2*Pi])])/(2*c^(3/2)) + (b*Sqrt[Pi/2]*FresnelC[(b + 2*c*x)/(Sqrt[c]*Sqrt[2*Pi])]*Sin[(b^2 - 4*a*c)/(4*c)])/(2*c^(3/2))}
{Sin[a + b*x + c*x^2], x, 5, (Sqrt[Pi/2]*Cos[(b^2 - 4*a*c)/(4*c)]*FresnelS[(b + 2*c*x)/(Sqrt[c]*Sqrt[2*Pi])])/Sqrt[c] - (Sqrt[Pi/2]*FresnelC[(b + 2*c*x)/(Sqrt[c]*Sqrt[2*Pi])]*Sin[(b^2 - 4*a*c)/(4*c)])/Sqrt[c]}
{Sin[a + b*x + c*x^2]/x, x, 0, Int[Sin[a + b*x + c*x^2]/x, x]}
{Sin[a + b*x + c*x^2]/x^2 - b*Cos[a + b*x + c*x^2]/x, x, 7, Sqrt[c]*Sqrt[2*Pi]*Cos[(b^2 - 4*a*c)/(4*c)]*FresnelC[(b + 2*c*x)/(Sqrt[c]*Sqrt[2*Pi])] + Sqrt[c]*Sqrt[2*Pi]*FresnelS[(b + 2*c*x)/(Sqrt[c]*Sqrt[2*Pi])]*Sin[(b^2 - 4*a*c)/(4*c)] - Sin[a + b*x + c*x^2]/x}

{x^2*Sin[a + b*x - c*x^2], x, 14, (b*Cos[a + b*x - c*x^2])/(4*c^2) + (x*Cos[a + b*x - c*x^2])/(2*c) + (Sqrt[Pi/2]*FresnelC[(b - 2*c*x)/(Sqrt[c]*Sqrt[2*Pi])]*(2*c*Cos[a + b^2/(4*c)] - b^2*Sin[a + b^2/(4*c)]))/(4*c^(5/2)) + (Sqrt[Pi/2]*FresnelS[(b - 2*c*x)/(Sqrt[c]*Sqrt[2*Pi])]*(b^2*Cos[a + b^2/(4*c)] + 2*c*Sin[a + b^2/(4*c)]))/(4*c^(5/2))}
{x*Sin[a + b*x - c*x^2], x, 7, Cos[a + b*x - c*x^2]/(2*c) + (b*Sqrt[Pi/2]*Cos[(b^2 + 4*a*c)/(4*c)]*FresnelS[(b - 2*c*x)/(Sqrt[c]*Sqrt[2*Pi])])/(2*c^(3/2)) - (b*Sqrt[Pi/2]*FresnelC[(b - 2*c*x)/(Sqrt[c]*Sqrt[2*Pi])]*Sin[(b^2 + 4*a*c)/(4*c)])/(2*c^(3/2))}
{Sin[a + b*x - c*x^2], x, 6, (Sqrt[Pi/2]*Cos[(b^2 + 4*a*c)/(4*c)]*FresnelS[(b - 2*c*x)/(Sqrt[c]*Sqrt[2*Pi])])/Sqrt[c] - (Sqrt[Pi/2]*FresnelC[(b - 2*c*x)/(Sqrt[c]*Sqrt[2*Pi])]*Sin[(b^2 + 4*a*c)/(4*c)])/Sqrt[c]}
{Sin[a + b*x - c*x^2]/x, x, 0, Int[Sin[a + b*x - c*x^2]/x, x]}
{Sin[a + b*x - c*x^2]/x^2 - b*Cos[a + b*x - c*x^2]/x, x, 8, Sqrt[c]*Sqrt[2*Pi]*Cos[(b^2 + 4*a*c)/(4*c)]*FresnelC[(b - 2*c*x)/(Sqrt[c]*Sqrt[2*Pi])] + Sqrt[c]*Sqrt[2*Pi]*FresnelS[(b - 2*c*x)/(Sqrt[c]*Sqrt[2*Pi])]*Sin[(b^2 + 4*a*c)/(4*c)] - Sin[a + b*x - c*x^2]/x}

{x^2*Sin[1/4 + x + x^2], x, 8, (1/4)*Cos[1/4 + x + x^2] - (1/2)*x*Cos[1/4 + x + x^2] + (1/2)*Sqrt[Pi/2]*FresnelC[(1 + 2*x)/Sqrt[2*Pi]] + (1/4)*Sqrt[Pi/2]*FresnelS[(1 + 2*x)/Sqrt[2*Pi]]}
{x*Sin[1/4 + x + x^2], x, 4, (-(1/2))*Cos[1/4 + x + x^2] - (1/2)*Sqrt[Pi/2]*FresnelS[(1 + 2*x)/Sqrt[2*Pi]]}
{Sin[1/4 + x + x^2], x, 3, Sqrt[Pi/2]*FresnelS[(1 + 2*x)/Sqrt[2*Pi]]}
{Sin[1/4 + x + x^2]/x, x, 0, Int[Sin[1/4 + x + x^2]/x, x]}
{Sin[1/4 + x + x^2]/x^2, x, 4, Sqrt[2*Pi]*FresnelC[(1 + 2*x)/Sqrt[2*Pi]] + Int[Cos[1/4 + x + x^2]/x, x] - Sin[1/4 + x + x^2]/x}


(* Integrands of the form x^m*Sin[a+b*x+c*x^2]^2 where m is an integer *)
{x^2*Sin[a + b*x + c*x^2]^2, x, 15, x^3/6 + (Sqrt[Pi]*FresnelS[(b + 2*c*x)/(Sqrt[c]*Sqrt[Pi])]*(c*Cos[2*a - b^2/(2*c)] + b^2*Sin[2*a - b^2/(2*c)]))/(16*c^(5/2)) - (Sqrt[Pi]*FresnelC[(b + 2*c*x)/(Sqrt[c]*Sqrt[Pi])]*(b^2*Cos[2*a - b^2/(2*c)] - c*Sin[2*a - b^2/(2*c)]))/(16*c^(5/2)) + (b*Sin[2*a + 2*b*x + 2*c*x^2])/(16*c^2) - (x*Sin[2*a + 2*b*x + 2*c*x^2])/(8*c)}
{x*Sin[a + b*x + c*x^2]^2, x, 9, x^2/4 + (b*Sqrt[Pi]*Cos[(b^2 - 4*a*c)/(2*c)]*FresnelC[(b + 2*c*x)/(Sqrt[c]*Sqrt[Pi])])/(8*c^(3/2)) + (b*Sqrt[Pi]*FresnelS[(b + 2*c*x)/(Sqrt[c]*Sqrt[Pi])]*Sin[(b^2 - 4*a*c)/(2*c)])/(8*c^(3/2)) - Sin[2*a + 2*b*x + 2*c*x^2]/(8*c)}
{Sin[a + b*x + c*x^2]^2, x, 7, x/2 - (Sqrt[Pi]*Cos[(b^2 - 4*a*c)/(2*c)]*FresnelC[(b + 2*c*x)/(Sqrt[c]*Sqrt[Pi])])/(4*Sqrt[c]) - (Sqrt[Pi]*FresnelS[(b + 2*c*x)/(Sqrt[c]*Sqrt[Pi])]*Sin[(b^2 - 4*a*c)/(2*c)])/(4*Sqrt[c])}
{Sin[a + b*x + c*x^2]^2/x, x, 3, (-(1/2))*Int[Cos[2*a + 2*b*x + 2*c*x^2]/x, x] + Log[x]/2}

{x^2*Sin[a + b*x - c*x^2]^2, x, 17, x^3/6 - (Sqrt[Pi]*FresnelS[(b - 2*c*x)/(Sqrt[c]*Sqrt[Pi])]*(c*Cos[2*a + b^2/(2*c)] - b^2*Sin[2*a + b^2/(2*c)]))/(16*c^(5/2)) + (Sqrt[Pi]*FresnelC[(b - 2*c*x)/(Sqrt[c]*Sqrt[Pi])]*(b^2*Cos[2*a + b^2/(2*c)] + c*Sin[2*a + b^2/(2*c)]))/(16*c^(5/2)) + (b*Sin[2*a + 2*b*x - 2*c*x^2])/(16*c^2) + (x*Sin[2*a + 2*b*x - 2*c*x^2])/(8*c)}
{x*Sin[a + b*x - c*x^2]^2, x, 10, x^2/4 + (b*Sqrt[Pi]*Cos[(b^2 + 4*a*c)/(2*c)]*FresnelC[(b - 2*c*x)/(Sqrt[c]*Sqrt[Pi])])/(8*c^(3/2)) + (b*Sqrt[Pi]*FresnelS[(b - 2*c*x)/(Sqrt[c]*Sqrt[Pi])]*Sin[(b^2 + 4*a*c)/(2*c)])/(8*c^(3/2)) + Sin[2*a + 2*b*x - 2*c*x^2]/(8*c)}
{Sin[a + b*x - c*x^2]^2, x, 8, x/2 + (Sqrt[Pi]*Cos[(b^2 + 4*a*c)/(2*c)]*FresnelC[(b - 2*c*x)/(Sqrt[c]*Sqrt[Pi])])/(4*Sqrt[c]) + (Sqrt[Pi]*FresnelS[(b - 2*c*x)/(Sqrt[c]*Sqrt[Pi])]*Sin[(b^2 + 4*a*c)/(2*c)])/(4*Sqrt[c])}
{Sin[a + b*x - c*x^2]^2/x, x, 3, (-(1/2))*Int[Cos[2*a + 2*b*x - 2*c*x^2]/x, x] + Log[x]/2}

{x^2*Sin[1/4 + x + x^2]^2, x, 11, x^3/6 - (1/16)*Sqrt[Pi]*FresnelC[(1 + 2*x)/Sqrt[Pi]] + (1/16)*Sqrt[Pi]*FresnelS[(1 + 2*x)/Sqrt[Pi]] + (1/16)*Sin[(1/2)*(1 + 2*x)^2] - (1/8)*x*Sin[(1/2)*(1 + 2*x)^2]}
{x*Sin[1/4 + x + x^2]^2, x, 9, x^2/4 + (1/8)*Sqrt[Pi]*FresnelC[(1 + 2*x)/Sqrt[Pi]] - (1/8)*Sin[(1/2)*(1 + 2*x)^2]}
{Sin[1/4 + x + x^2]^2, x, 5, x/2 - (1/4)*Sqrt[Pi]*FresnelC[(1 + 2*x)/Sqrt[Pi]]}
{Sin[1/4 + x + x^2]^2/x, x, 3, (-(1/2))*Int[Cos[(1/2)*(1 + 2*x)^2]/x, x] + Log[x]/2}
{Sin[1/4 + x + x^2]^2/x^2, x, 3, -(1/(2*x)) - (1/2)*Int[Cos[(1/2)*(1 + 2*x)^2]/x^2, x]}


(* Integrands of the form (d+e*x)^m*Sin[a+b*x+c*x^2]^n where m and n are integers *)
{(d + e*x)^2*Sin[a + b*x + c*x^2], x, 12, -((e*(4*c*d - b*e)*Cos[a + b*x + c*x^2])/(4*c^2)) - (e^2*x*Cos[a + b*x + c*x^2])/(2*c) + (Sqrt[Pi/2]*FresnelS[(b + 2*c*x)/(Sqrt[c]*Sqrt[2*Pi])]*((2*c*d - b*e)^2*Cos[a - b^2/(4*c)] - 2*c*e^2*Sin[a - b^2/(4*c)]))/(4*c^(5/2)) + (Sqrt[Pi/2]*FresnelC[(b + 2*c*x)/(Sqrt[c]*Sqrt[2*Pi])]*(2*c*e^2*Cos[a - b^2/(4*c)] + (2*c*d - b*e)^2*Sin[a - b^2/(4*c)]))/(4*c^(5/2))}
{(d + e*x)*Sin[a + b*x + c*x^2], x, 6, -((e*Cos[a + b*x + c*x^2])/(2*c)) + ((2*c*d - b*e)*Sqrt[Pi/2]*Cos[(b^2 - 4*a*c)/(4*c)]*FresnelS[(b + 2*c*x)/(Sqrt[c]*Sqrt[2*Pi])])/(2*c^(3/2)) - ((2*c*d - b*e)*Sqrt[Pi/2]*FresnelC[(b + 2*c*x)/(Sqrt[c]*Sqrt[2*Pi])]*Sin[(b^2 - 4*a*c)/(4*c)])/(2*c^(3/2))}
{Sin[a + b*x + c*x^2]/(d + e*x), x, 0, Int[Sin[a + b*x + c*x^2]/(d + e*x), x]}

{(d + e*x)^2*Sin[a + b*x + c*x^2]^2, x, 33, (d^2*x)/2 + (1/2)*d*e*x^2 + (e^2*x^3)/6 + (Sqrt[Pi]*FresnelS[(b + 2*c*x)/(Sqrt[c]*Sqrt[Pi])]*(c*e^2*Cos[2*a - b^2/(2*c)] + (2*c*d - b*e)^2*Sin[2*a - b^2/(2*c)]))/(16*c^(5/2)) - (Sqrt[Pi]*FresnelC[(b + 2*c*x)/(Sqrt[c]*Sqrt[Pi])]*((2*c*d - b*e)^2*Cos[2*a - b^2/(2*c)] + c*e^2*Sin[(b^2 - 4*a*c)/(2*c)]))/(16*c^(5/2)) - (d*e*Sin[2*a + 2*b*x + 2*c*x^2])/(4*c) + (b*e^2*Sin[2*a + 2*b*x + 2*c*x^2])/(16*c^2) - (e^2*x*Sin[2*a + 2*b*x + 2*c*x^2])/(8*c)}
{(d + e*x)*Sin[a + b*x + c*x^2]^2, x, 18, (d*x)/2 + (e*x^2)/4 - ((2*c*d - b*e)*Sqrt[Pi]*Cos[2*a - b^2/(2*c)]*FresnelC[(b + 2*c*x)/(Sqrt[c]*Sqrt[Pi])])/(8*c^(3/2)) + ((2*c*d - b*e)*Sqrt[Pi]*FresnelS[(b + 2*c*x)/(Sqrt[c]*Sqrt[Pi])]*Sin[2*a - b^2/(2*c)])/(8*c^(3/2)) - (e*Sin[2*a + 2*b*x + 2*c*x^2])/(8*c)}
{Sin[a + b*x + c*x^2]^2/(d + e*x), x, 3, (-(1/2))*Int[Cos[2*a + 2*b*x + 2*c*x^2]/(d + e*x), x] + Log[d + e*x]/(2*e)}


(* ::Subsection::Closed:: *)
(*Sin[(a+b x)/(c+d x)]^n*)


{Sin[(a + b*x)/(c + d*x)], x, 5, ((b*c - a*d)*Cos[b/d]*CosIntegral[-((b*c - a*d)/(d*(c + d*x)))])/d^2 + ((c + d*x)*Sin[(a + b*x)/(c + d*x)])/d - ((b*c - a*d)*Sin[b/d]*SinIntegral[a/(c + d*x) - (b*c)/(d*(c + d*x))])/d^2}
{Sin[(a + b*x)/(c + d*x)]^2, x, 8, x/2 - ((c + d*x)*Cos[(2*(a + b*x))/(c + d*x)])/(2*d) + ((b*c - a*d)*CosIntegral[-((2*(b*c - a*d))/(d*(c + d*x)))]*Sin[(2*b)/d])/d^2 + ((b*c - a*d)*Cos[(2*b)/d]*SinIntegral[(2*a)/(c + d*x) - (2*b*c)/(d*(c + d*x))])/d^2}


(* ::Subsection::Closed:: *)
(*x^m Sin[a+b x^n]^p*)


{x^3*Sin[a + b*x^2], x, 3, -((x^2*Cos[a + b*x^2])/(2*b)) + Sin[a + b*x^2]/(2*b^2)}
{x^2*Sin[a + b*x^2], x, 4, -((x*Cos[a + b*x^2])/(2*b)) + (Sqrt[Pi/2]*Cos[a]*FresnelC[Sqrt[b]*Sqrt[2/Pi]*x])/(2*b^(3/2)) - (Sqrt[Pi/2]*FresnelS[Sqrt[b]*Sqrt[2/Pi]*x]*Sin[a])/(2*b^(3/2))}
{x*Sin[a + b*x^2], x, 2, -(Cos[a + b*x^2]/(2*b))}
{Sin[a + b*x^2], x, 3, (Sqrt[Pi/2]*Cos[a]*FresnelS[Sqrt[b]*Sqrt[2/Pi]*x])/Sqrt[b] + (Sqrt[Pi/2]*FresnelC[Sqrt[b]*Sqrt[2/Pi]*x]*Sin[a])/Sqrt[b]}
{Sin[a + b*x^2]/x, x, 3, (1/2)*CosIntegral[b*x^2]*Sin[a] + (1/2)*Cos[a]*SinIntegral[b*x^2]}
{Sin[a + b*x^2]/x^2, x, 4, Sqrt[b]*Sqrt[2*Pi]*Cos[a]*FresnelC[Sqrt[b]*Sqrt[2/Pi]*x] - Sqrt[b]*Sqrt[2*Pi]*FresnelS[Sqrt[b]*Sqrt[2/Pi]*x]*Sin[a] - Sin[a + b*x^2]/x}
{Sin[a + b*x^2]/x^3, x, 4, (1/2)*b*Cos[a]*CosIntegral[b*x^2] - Sin[a + b*x^2]/(2*x^2) - (1/2)*b*Sin[a]*SinIntegral[b*x^2]}


{x^3*Sin[a + b*x^2]^2, x, 2, x^4/8 - (x^2*Cos[a + b*x^2]*Sin[a + b*x^2])/(4*b) + Sin[a + b*x^2]^2/(8*b^2)}
{x^2*Sin[a + b*x^2]^2, x, 7, x^3/6 + (Sqrt[Pi]*Cos[2*a]*FresnelS[(2*Sqrt[b]*x)/Sqrt[Pi]])/(16*b^(3/2)) + (Sqrt[Pi]*FresnelC[(2*Sqrt[b]*x)/Sqrt[Pi]]*Sin[2*a])/(16*b^(3/2)) - (x*Sin[2*a + 2*b*x^2])/(8*b)}
{x*Sin[a + b*x^2]^2, x, 2, x^2/4 - (Cos[a + b*x^2]*Sin[a + b*x^2])/(4*b)}
{Sin[a + b*x^2]^2, x, 5, x/2 - (Sqrt[Pi]*Cos[2*a]*FresnelC[(2*Sqrt[b]*x)/Sqrt[Pi]])/(4*Sqrt[b]) + (Sqrt[Pi]*FresnelS[(2*Sqrt[b]*x)/Sqrt[Pi]]*Sin[2*a])/(4*Sqrt[b])}
{Sin[a + b*x^2]^2/x, x, 7, (-(1/4))*Cos[2*a]*CosIntegral[2*b*x^2] + Log[x^2]/4 + (1/4)*Sin[2*a]*SinIntegral[2*b*x^2]}
{Sin[a + b*x^2]^2/x^2, x, 5, -(Sin[a + b*x^2]^2/x) + Sqrt[b]*Sqrt[Pi]*Cos[2*a]*FresnelS[(2*Sqrt[b]*x)/Sqrt[Pi]] + Sqrt[b]*Sqrt[Pi]*FresnelC[(2*Sqrt[b]*x)/Sqrt[Pi]]*Sin[2*a]}
{Sin[a + b*x^2]^2/x^3, x, 8, -(1/(4*x^2)) + Cos[2*a + 2*b*x^2]/(4*x^2) + (1/2)*b*CosIntegral[2*b*x^2]*Sin[2*a] + (1/2)*b*Cos[2*a]*SinIntegral[2*b*x^2]}


{x^3*Sin[a + b*x^2]^3, x, 4, -((x^2*Cos[a + b*x^2])/(3*b)) + Sin[a + b*x^2]/(3*b^2) - (x^2*Cos[a + b*x^2]*Sin[a + b*x^2]^2)/(6*b) + Sin[a + b*x^2]^3/(18*b^2)}
{x^2*Sin[a + b*x^2]^3, x, 10, -((3*x*Cos[a + b*x^2])/(8*b)) + (x*Cos[3*a + 3*b*x^2])/(24*b) + (3*Sqrt[Pi/2]*Cos[a]*FresnelC[Sqrt[b]*Sqrt[2/Pi]*x])/(8*b^(3/2)) - (Sqrt[Pi/6]*Cos[3*a]*FresnelC[Sqrt[b]*Sqrt[6/Pi]*x])/(24*b^(3/2)) - (3*Sqrt[Pi/2]*FresnelS[Sqrt[b]*Sqrt[2/Pi]*x]*Sin[a])/(8*b^(3/2)) + (Sqrt[Pi/6]*FresnelS[Sqrt[b]*Sqrt[6/Pi]*x]*Sin[3*a])/(24*b^(3/2))}
{x*Sin[a + b*x^2]^3, x, 3, -(Cos[a + b*x^2]/(2*b)) + Cos[a + b*x^2]^3/(6*b)}
{Sin[a + b*x^2]^3, x, 8, (3*Sqrt[Pi/2]*Cos[a]*FresnelS[Sqrt[b]*Sqrt[2/Pi]*x])/(4*Sqrt[b]) - (Sqrt[Pi/6]*Cos[3*a]*FresnelS[Sqrt[b]*Sqrt[6/Pi]*x])/(4*Sqrt[b]) + (3*Sqrt[Pi/2]*FresnelC[Sqrt[b]*Sqrt[2/Pi]*x]*Sin[a])/(4*Sqrt[b]) - (Sqrt[Pi/6]*FresnelC[Sqrt[b]*Sqrt[6/Pi]*x]*Sin[3*a])/(4*Sqrt[b])}
{Sin[a + b*x^2]^3/x, x, 9, (3/8)*CosIntegral[b*x^2]*Sin[a] - (1/8)*CosIntegral[3*b*x^2]*Sin[3*a] + (3/8)*Cos[a]*SinIntegral[b*x^2] - (1/8)*Cos[3*a]*SinIntegral[3*b*x^2]}
{Sin[a + b*x^2]^3/x^2, x, 9, (3/2)*Sqrt[b]*Sqrt[Pi/2]*Cos[a]*FresnelC[Sqrt[b]*Sqrt[2/Pi]*x] - (1/2)*Sqrt[b]*Sqrt[(3*Pi)/2]*Cos[3*a]*FresnelC[Sqrt[b]*Sqrt[6/Pi]*x] - (3/2)*Sqrt[b]*Sqrt[Pi/2]*FresnelS[Sqrt[b]*Sqrt[2/Pi]*x]*Sin[a] + (1/2)*Sqrt[b]*Sqrt[(3*Pi)/2]*FresnelS[Sqrt[b]*Sqrt[6/Pi]*x]*Sin[3*a] - Sin[a + b*x^2]^3/x}
{Sin[a + b*x^2]^3/x^3, x, 11, (3/8)*b*Cos[a]*CosIntegral[b*x^2] - (3/8)*b*Cos[3*a]*CosIntegral[3*b*x^2] - (3*Sin[a + b*x^2])/(8*x^2) + Sin[3*a + 3*b*x^2]/(8*x^2) - (3/8)*b*Sin[a]*SinIntegral[b*x^2] + (3/8)*b*Sin[3*a]*SinIntegral[3*b*x^2]}

{x^2*Sin[x^2]^3, x, 6, (-(1/2))*x*Cos[x^2] + (1/6)*x*Cos[x^2]^3 + (3/8)*Sqrt[Pi/2]*FresnelC[Sqrt[2/Pi]*x] - (1/24)*Sqrt[Pi/6]*FresnelC[Sqrt[6/Pi]*x], (-(3/8))*x*Cos[x^2] + (1/24)*x*Cos[3*x^2] + (3/8)*Sqrt[Pi/2]*FresnelC[Sqrt[2/Pi]*x] - (1/24)*Sqrt[Pi/6]*FresnelC[Sqrt[6/Pi]*x]}
{x^4*Cos[x^2]*Sin[x^2]^2, x, 7, (1/4)*x*Cos[x^2] - (1/12)*x*Cos[x^2]^3 - (3/16)*Sqrt[Pi/2]*FresnelC[Sqrt[2/Pi]*x] + (1/48)*Sqrt[Pi/6]*FresnelC[Sqrt[6/Pi]*x] + (1/6)*x^3*Sin[x^2]^3, (3/16)*x*Cos[x^2] - (1/48)*x*Cos[3*x^2] - (3/16)*Sqrt[Pi/2]*FresnelC[Sqrt[2/Pi]*x] + (1/48)*Sqrt[Pi/6]*FresnelC[Sqrt[6/Pi]*x] + (1/6)*x^3*Sin[x^2]^3}


{Sin[a + b/x], x, 4, (-b)*Cos[a]*CosIntegral[b/x] + x*Sin[a + b/x] + b*Sin[a]*SinIntegral[b/x]}
{Sin[a + b/x]/x, x, 3, (-CosIntegral[b/x])*Sin[a] - Cos[a]*SinIntegral[b/x]}
{Sin[a + b/x]/x^2, x, 2, Cos[a + b/x]/b}
{Sin[a + b/x]/x^3, x, 3, Cos[a + b/x]/(b*x) - Sin[a + b/x]/b^2}
{Sin[a + b/x]/x^4, x, 4, -((2*Cos[a + b/x])/b^3) + Cos[a + b/x]/(b*x^2) - (2*Sin[a + b/x])/(b^2*x)}


{Sin[a + b/x^2], x, 5, (-Sqrt[b])*Sqrt[2*Pi]*Cos[a]*FresnelC[(Sqrt[b]*Sqrt[2/Pi])/x] + Sqrt[b]*Sqrt[2*Pi]*FresnelS[(Sqrt[b]*Sqrt[2/Pi])/x]*Sin[a] + x*Sin[a + b/x^2]}
{Sin[a + b/x^2]/x, x, 3, (-(1/2))*CosIntegral[b/x^2]*Sin[a] - (1/2)*Cos[a]*SinIntegral[b/x^2]}
{Sin[a + b/x^2]/x^2, x, 4, -((Sqrt[Pi/2]*Cos[a]*FresnelS[(Sqrt[b]*Sqrt[2/Pi])/x])/Sqrt[b]) - (Sqrt[Pi/2]*FresnelC[(Sqrt[b]*Sqrt[2/Pi])/x]*Sin[a])/Sqrt[b]}
{Sin[a + b/x^2]/x^3, x, 2, Cos[a + b/x^2]/(2*b)}
{Sin[a + b/x^2]/x^4, x, 5, Cos[a + b/x^2]/(2*b*x) - (Sqrt[Pi/2]*Cos[a]*FresnelC[(Sqrt[b]*Sqrt[2/Pi])/x])/(2*b^(3/2)) + (Sqrt[Pi/2]*FresnelS[(Sqrt[b]*Sqrt[2/Pi])/x]*Sin[a])/(2*b^(3/2))}


{Sin[a + b*x^n], x, 3, (I*E^(I*a)*x*Gamma[1/n, (-I)*b*x^n])/(((-I)*b*x^n)^n^(-1)*(2*n)) - (I*x*Gamma[1/n, I*b*x^n])/(E^(I*a)*(I*b*x^n)^n^(-1)*(2*n))}
{Sin[a + b*x^n]^2, x, 5, x/2 + (2^(-2 - 1/n)*E^(2*I*a)*x*Gamma[1/n, -2*I*b*x^n])/(((-I)*b*x^n)^n^(-1)*n) + (2^(-2 - 1/n)*x*Gamma[1/n, 2*I*b*x^n])/(E^(2*I*a)*(I*b*x^n)^n^(-1)*n)}
{Sin[a + b*x^n]^3, x, 8, (3*I*E^(I*a)*x*Gamma[1/n, (-I)*b*x^n])/(((-I)*b*x^n)^n^(-1)*(8*n)) - (3*I*x*Gamma[1/n, I*b*x^n])/(E^(I*a)*(I*b*x^n)^n^(-1)*(8*n)) - (I*E^(3*I*a)*x*Gamma[1/n, -3*I*b*x^n])/(3^n^(-1)*((-I)*b*x^n)^n^(-1)*(8*n)) + (I*x*Gamma[1/n, 3*I*b*x^n])/(3^n^(-1)*E^(3*I*a)*(I*b*x^n)^n^(-1)*(8*n))}

{x^m*Sin[a + b*x^n], x, 3, (I*E^(I*a)*x^(1 + m)*Gamma[(1 + m)/n, (-I)*b*x^n])/(((-I)*b*x^n)^((1 + m)/n)*(2*n)) - (I*x^(1 + m)*Gamma[(1 + m)/n, I*b*x^n])/(E^(I*a)*(I*b*x^n)^((1 + m)/n)*(2*n))}
{x^m*Sin[a + b*x^n]^2, x, 6, x^(1 + m)/(2*(1 + m)) + (2^(-2 - (1 + m)/n)*E^(2*I*a)*x^(1 + m)*Gamma[(1 + m)/n, -2*I*b*x^n])/(((-I)*b*x^n)^((1 + m)/n)*n) + (2^(-2 - (1 + m)/n)*x^(1 + m)*Gamma[(1 + m)/n, 2*I*b*x^n])/(E^(2*I*a)*(I*b*x^n)^((1 + m)/n)*n)}
{x^m*Sin[a + b*x^n]^3, x, 8, (3*I*E^(I*a)*x^(1 + m)*Gamma[(1 + m)/n, (-I)*b*x^n])/(((-I)*b*x^n)^((1 + m)/n)*(8*n)) - (3*I*x^(1 + m)*Gamma[(1 + m)/n, I*b*x^n])/(E^(I*a)*(I*b*x^n)^((1 + m)/n)*(8*n)) - (I*E^(3*I*a)*x^(1 + m)*Gamma[(1 + m)/n, -3*I*b*x^n])/(3^((1 + m)/n)*((-I)*b*x^n)^((1 + m)/n)*(8*n)) + (I*x^(1 + m)*Gamma[(1 + m)/n, 3*I*b*x^n])/(3^((1 + m)/n)*E^(3*I*a)*(I*b*x^n)^((1 + m)/n)*(8*n))}

{Sin[a + b*x^n]/x^(n + 1), x, 4, (b*Cos[a]*CosIntegral[b*x^n])/n - Sin[a + b*x^n]/(x^n*n) - (b*Sin[a]*SinIntegral[b*x^n])/n}
{Sin[a + b*x^n]^2/x^(n + 1), x, 7, -(1/(x^n*(2*n))) + Cos[2*a + 2*b*x^n]/(x^n*(2*n)) + (b*CosIntegral[2*b*x^n]*Sin[2*a])/n + (b*Cos[2*a]*SinIntegral[2*b*x^n])/n}
{Sin[a + b*x^n]^3/x^(n + 1), x, 11, (3*b*Cos[a]*CosIntegral[b*x^n])/(4*n) - (3*b*Cos[3*a]*CosIntegral[3*b*x^n])/(4*n) - (3*Sin[a + b*x^n])/(x^n*(4*n)) + Sin[3*a + 3*b*x^n]/(x^n*(4*n)) - (3*b*Sin[a]*SinIntegral[b*x^n])/(4*n) + (3*b*Sin[3*a]*SinIntegral[3*b*x^n])/(4*n)}


(* ::Subsection::Closed:: *)
(*x^m Sin[a+b Log[c x^n]]^p*)


(* Integrands of the form Sin[a+b*Log[c*x^n]] *)
{Sin[a + b*Log[c*x^n]], x, 1, -((b*n*x*Cos[a + b*Log[c*x^n]])/(1 + b^2*n^2)) + (x*Sin[a + b*Log[c*x^n]])/(1 + b^2*n^2)}
{Sin[a + b*Log[c*x^n]]^2, x, 2, (2*b^2*n^2*x)/(1 + 4*b^2*n^2) - (2*b*n*x*Cos[a + b*Log[c*x^n]]*Sin[a + b*Log[c*x^n]])/(1 + 4*b^2*n^2) + (x*Sin[a + b*Log[c*x^n]]^2)/(1 + 4*b^2*n^2)}
{Sin[a + b*Log[c*x^n]]^3, x, 2, -((6*b^3*n^3*x*Cos[a + b*Log[c*x^n]])/((1 + b^2*n^2)*(1 + 9*b^2*n^2))) + (6*b^2*n^2*x*Sin[a + b*Log[c*x^n]])/((1 + b^2*n^2)*(1 + 9*b^2*n^2)) - (3*b*n*x*Cos[a + b*Log[c*x^n]]*Sin[a + b*Log[c*x^n]]^2)/(1 + 9*b^2*n^2) + (x*Sin[a + b*Log[c*x^n]]^3)/(1 + 9*b^2*n^2)}
{Sin[a + b*Log[c*x^n]]^4, x, 3, (24*b^4*n^4*x)/((1 + 4*b^2*n^2)*(1 + 16*b^2*n^2)) - (24*b^3*n^3*x*Cos[a + b*Log[c*x^n]]*Sin[a + b*Log[c*x^n]])/((1 + 4*b^2*n^2)*(1 + 16*b^2*n^2)) + (12*b^2*n^2*x*Sin[a + b*Log[c*x^n]]^2)/((1 + 4*b^2*n^2)*(1 + 16*b^2*n^2)) - (4*b*n*x*Cos[a + b*Log[c*x^n]]*Sin[a + b*Log[c*x^n]]^3)/(1 + 16*b^2*n^2) + (x*Sin[a + b*Log[c*x^n]]^4)/(1 + 16*b^2*n^2)}


(* Integrands of the form x^m*Sin[a+b*Log[c*x^n]]^p where p is an integer *)
{x^m*Sin[a + b*Log[c*x^n]], x, 1, -((b*n*x^(1 + m)*Cos[a + b*Log[c*x^n]])/((1 + m)^2 + b^2*n^2)) + ((1 + m)*x^(1 + m)*Sin[a + b*Log[c*x^n]])/((1 + m)^2 + b^2*n^2)}
{x^m*Sin[a + b*Log[c*x^n]]^2, x, 2, (2*b^2*n^2*x^(1 + m))/((1 + m)*((1 + m)^2 + 4*b^2*n^2)) - (2*b*n*x^(1 + m)*Cos[a + b*Log[c*x^n]]*Sin[a + b*Log[c*x^n]])/((1 + m)^2 + 4*b^2*n^2) + ((1 + m)*x^(1 + m)*Sin[a + b*Log[c*x^n]]^2)/((1 + m)^2 + 4*b^2*n^2)}
{x^m*Sin[a + b*Log[c*x^n]]^3, x, 2, -((6*b^3*n^3*x^(1 + m)*Cos[a + b*Log[c*x^n]])/(((1 + m)^2 + b^2*n^2)*((1 + m)^2 + 9*b^2*n^2))) + (6*b^2*(1 + m)*n^2*x^(1 + m)*Sin[a + b*Log[c*x^n]])/(((1 + m)^2 + b^2*n^2)*((1 + m)^2 + 9*b^2*n^2)) - (3*b*n*x^(1 + m)*Cos[a + b*Log[c*x^n]]*Sin[a + b*Log[c*x^n]]^2)/((1 + m)^2 + 9*b^2*n^2) + ((1 + m)*x^(1 + m)*Sin[a + b*Log[c*x^n]]^3)/((1 + m)^2 + 9*b^2*n^2)}
{x^m*Sin[a + b*Log[c*x^n]]^4, x, 3, (24*b^4*n^4*x^(1 + m))/((1 + m)*((1 + m)^2 + 4*b^2*n^2)*((1 + m)^2 + 16*b^2*n^2)) - (24*b^3*n^3*x^(1 + m)*Cos[a + b*Log[c*x^n]]*Sin[a + b*Log[c*x^n]])/(((1 + m)^2 + 4*b^2*n^2)*((1 + m)^2 + 16*b^2*n^2)) + (12*b^2*(1 + m)*n^2*x^(1 + m)*Sin[a + b*Log[c*x^n]]^2)/(((1 + m)^2 + 4*b^2*n^2)*((1 + m)^2 + 16*b^2*n^2)) - (4*b*n*x^(1 + m)*Cos[a + b*Log[c*x^n]]*Sin[a + b*Log[c*x^n]]^3)/((1 + m)^2 + 16*b^2*n^2) + ((1 + m)*x^(1 + m)*Sin[a + b*Log[c*x^n]]^4)/((1 + m)^2 + 16*b^2*n^2)}


(* Integrands of the form Sin[a+b*Log[c*x^n]]^p/x where p is an integer *)
{Sin[a + b*Log[c*x^n]]/x, x, 2, -(Cos[a + b*Log[c*x^n]]/(b*n))}
{Sin[a + b*Log[c*x^n]]^2/x, x, 2, Log[c*x^n]/(2*n) - (Cos[a + b*Log[c*x^n]]*Sin[a + b*Log[c*x^n]])/(2*b*n)}
{Sin[a + b*Log[c*x^n]]^3/x, x, 3, -(Cos[a + b*Log[c*x^n]]/(b*n)) + Cos[a + b*Log[c*x^n]]^3/(3*b*n)}
{Sin[a + b*Log[c*x^n]]^4/x, x, 3, (3*Log[c*x^n])/(8*n) - (3*Cos[a + b*Log[c*x^n]]*Sin[a + b*Log[c*x^n]])/(8*b*n) - (Cos[a + b*Log[c*x^n]]*Sin[a + b*Log[c*x^n]]^3)/(4*b*n)}
{Sin[a + b*Log[c*x^n]]^5/x, x, 3, -(Cos[a + b*Log[c*x^n]]/(b*n)) + (2*Cos[a + b*Log[c*x^n]]^3)/(3*b*n) - Cos[a + b*Log[c*x^n]]^5/(5*b*n)}


(* Integrands of the form Sin[a+b*Log[c*x^n]]^p/x where p is a half-integer *)
{Sin[a + b*Log[c*x^n]]^(5/2)/x, x, 3, -((6*EllipticE[Pi/4 + (1/2)*(-a - b*Log[c*x^n]), 2])/(5*b*n)) - (2*Cos[a + b*Log[c*x^n]]*Sin[a + b*Log[c*x^n]]^(3/2))/(5*b*n)}
{Sin[a + b*Log[c*x^n]]^(3/2)/x, x, 3, -((2*EllipticF[Pi/4 + (1/2)*(-a - b*Log[c*x^n]), 2])/(3*b*n)) - (2*Cos[a + b*Log[c*x^n]]*Sqrt[Sin[a + b*Log[c*x^n]]])/(3*b*n)}
{Sqrt[Sin[a + b*Log[c*x^n]]]/x, x, 2, -((2*EllipticE[Pi/4 + (1/2)*(-a - b*Log[c*x^n]), 2])/(b*n))}
{1/(x*Sqrt[Sin[a + b*Log[c*x^n]]]), x, 2, -((2*EllipticF[Pi/4 + (1/2)*(-a - b*Log[c*x^n]), 2])/(b*n))}
{1/(x*Sin[a + b*Log[c*x^n]]^(3/2)), x, 3, (2*EllipticE[Pi/4 + (1/2)*(-a - b*Log[c*x^n]), 2])/(b*n) - (2*Cos[a + b*Log[c*x^n]])/(b*n*Sqrt[Sin[a + b*Log[c*x^n]]])}
{1/(x*Sin[a + b*Log[c*x^n]]^(5/2)), x, 3, -((2*EllipticF[Pi/4 + (1/2)*(-a - b*Log[c*x^n]), 2])/(3*b*n)) - (2*Cos[a + b*Log[c*x^n]])/(3*b*n*Sin[a + b*Log[c*x^n]]^(3/2))}


{1/Sin[a - 2*I*Log[c*x]]^(3/2), x, 1, -((I*x*Cos[a - 2*I*Log[c*x]])/Sqrt[Sin[a - 2*I*Log[c*x]]]) - x*Sqrt[Sin[a - 2*I*Log[c*x]]]}


(* ::Subsection::Closed:: *)
(*Miscellaneous integrands involving one sine*)


(* Integrands of the form x^m*Sin[x]^n where m is an integer and n is a half-integer *)
{x/Sin[x]^(3/2) + x*Sqrt[Sin[x]], x, 2, -((2*x*Cos[x])/Sqrt[Sin[x]]) + 4*Sqrt[Sin[x]]}
{x/Sin[x]^(5/2) - x/(3*Sqrt[Sin[x]]), x, 2, -((2*x*Cos[x])/(3*Sin[x]^(3/2))) - 4/(3*Sqrt[Sin[x]])}
{x/Sin[x]^(7/2) + (3/5)*x*Sqrt[Sin[x]], x, 3, -((2*x*Cos[x])/(5*Sin[x]^(5/2))) - 4/(15*Sin[x]^(3/2)) - (6*x*Cos[x])/(5*Sqrt[Sin[x]]) + (12*Sqrt[Sin[x]])/5}
{x^2/Sin[x]^(3/2) + x^2*Sqrt[Sin[x]], x, 3, 16*EllipticE[Pi/4 - x/2, 2] - (2*x^2*Cos[x])/Sqrt[Sin[x]] + 8*x*Sqrt[Sin[x]]}


{(x + Sin[x])^2, x, 6, x/2 + x^3/3 - 2*x*Cos[x] + 2*Sin[x] - (1/2)*Cos[x]*Sin[x]}
{(x + Sin[x])^3, x, 10, (3*x^2)/4 + x^4/4 + 5*Cos[x] - 3*x^2*Cos[x] + Cos[x]^3/3 + 6*x*Sin[x] - (3/2)*x*Cos[x]*Sin[x] + (3*Sin[x]^2)/4}


{Sin[a + b*x]/(c + d*x^2), x, 10, -((CosIntegral[-((b*(Sqrt[-c] + Sqrt[d]*x))/Sqrt[d])]*Sin[a - (b*Sqrt[-c])/Sqrt[d]])/(2*Sqrt[-c]*Sqrt[d])) + (CosIntegral[-((b*(Sqrt[-c] - Sqrt[d]*x))/Sqrt[d])]*Sin[a + (b*Sqrt[-c])/Sqrt[d]])/(2*Sqrt[-c]*Sqrt[d]) - (Cos[a + (b*Sqrt[-c])/Sqrt[d]]*SinIntegral[(b*Sqrt[-c])/Sqrt[d] - b*x])/(2*Sqrt[-c]*Sqrt[d]) - (Cos[a - (b*Sqrt[-c])/Sqrt[d]]*SinIntegral[(b*Sqrt[-c])/Sqrt[d] + b*x])/(2*Sqrt[-c]*Sqrt[d])}
{Sin[a + b*x]/(c + d*x + e*x^2), x, 9, (CosIntegral[(b*(d - Sqrt[d^2 - 4*c*e] + 2*e*x))/(2*e)]*Sin[a - (b*(d - Sqrt[d^2 - 4*c*e]))/(2*e)])/Sqrt[d^2 - 4*c*e] - (CosIntegral[(b*(d + Sqrt[d^2 - 4*c*e] + 2*e*x))/(2*e)]*Sin[a - (b*(d + Sqrt[d^2 - 4*c*e]))/(2*e)])/Sqrt[d^2 - 4*c*e] + (Cos[a - (b*(d - Sqrt[d^2 - 4*c*e]))/(2*e)]*SinIntegral[(b*(d - Sqrt[d^2 - 4*c*e] + 2*e*x))/(2*e)])/Sqrt[d^2 - 4*c*e] - (Cos[a - (b*(d + Sqrt[d^2 - 4*c*e]))/(2*e)]*SinIntegral[(b*(d + Sqrt[d^2 - 4*c*e] + 2*e*x))/(2*e)])/Sqrt[d^2 - 4*c*e]}


{Sin[Sqrt[x]], x, 3, -2*Sqrt[x]*Cos[Sqrt[x]] + 2*Sin[Sqrt[x]]}
{Sin[Sqrt[1 + x]], x, 3, -2*Sqrt[1 + x]*Cos[Sqrt[1 + x]] + 2*Sin[Sqrt[1 + x]]}
{Sin[Sqrt[x]]/Sqrt[x], x, 2, -2*Cos[Sqrt[x]]}
{Sin[Sqrt[-7 + x]]/Sqrt[-7 + x], x, 2, -2*Cos[Sqrt[-7 + x]]}
{Sin[Sqrt[x]]^3/Sqrt[x], x, 3, -2*Cos[Sqrt[x]] + (2/3)*Cos[Sqrt[x]]^3}
{Sin[x^(1/3)]^2, x, 4, -((3*x^(1/3))/4) + x/2 + (3/4)*Cos[x^(1/3)]*Sin[x^(1/3)] - (3/2)*x^(2/3)*Cos[x^(1/3)]*Sin[x^(1/3)] + (3/2)*x^(1/3)*Sin[x^(1/3)]^2}
{Sin[x^(1/3)]^3, x, 7, (14/3)*Cos[x^(1/3)] - 2*x^(2/3)*Cos[x^(1/3)] - (2/9)*Cos[x^(1/3)]^3 + 4*x^(1/3)*Sin[x^(1/3)] - x^(2/3)*Cos[x^(1/3)]*Sin[x^(1/3)]^2 + (2/3)*x^(1/3)*Sin[x^(1/3)]^3}


{Sin[x]*Sqrt[b - a/x^2]/Sqrt[a - b*x^2], x, 2, (Sqrt[b - a/x^2]*x*SinIntegral[x])/Sqrt[a - b*x^2]}


(* Integrands of the form x^m*Sin[a+b*Log[c*x^n]]^p where p is a positive integer *)
{Sin[a + b*Log[c*x^n]], x, 1, -((b*n*x*Cos[a + b*Log[c*x^n]])/(1 + b^2*n^2)) + (x*Sin[a + b*Log[c*x^n]])/(1 + b^2*n^2)}
{x*Sin[a + b*Log[c*x^n]], x, 1, -((b*n*x^2*Cos[a + b*Log[c*x^n]])/(4 + b^2*n^2)) + (2*x^2*Sin[a + b*Log[c*x^n]])/(4 + b^2*n^2)}
{x^2*Sin[a + b*Log[c*x^n]], x, 1, -((b*n*x^3*Cos[a + b*Log[c*x^n]])/(9 + b^2*n^2)) + (3*x^3*Sin[a + b*Log[c*x^n]])/(9 + b^2*n^2)}
{Sin[a + b*Log[c*x^n]]/x^2, x, 1, -((b*n*Cos[a + b*Log[c*x^n]])/((1 + b^2*n^2)*x)) - Sin[a + b*Log[c*x^n]]/((1 + b^2*n^2)*x)}
{x^m*Sin[a + b*Log[c*x^n]], x, 1, -((b*n*x^(1 + m)*Cos[a + b*Log[c*x^n]])/((1 + m)^2 + b^2*n^2)) + ((1 + m)*x^(1 + m)*Sin[a + b*Log[c*x^n]])/((1 + m)^2 + b^2*n^2)}

{Sin[a + b*Log[c*x^n]]^2, x, 2, (2*b^2*n^2*x)/(1 + 4*b^2*n^2) - (2*b*n*x*Cos[a + b*Log[c*x^n]]*Sin[a + b*Log[c*x^n]])/(1 + 4*b^2*n^2) + (x*Sin[a + b*Log[c*x^n]]^2)/(1 + 4*b^2*n^2)}
{x*Sin[a + b*Log[c*x^n]]^2, x, 2, (b^2*n^2*x^2)/(4*(1 + b^2*n^2)) - (b*n*x^2*Cos[a + b*Log[c*x^n]]*Sin[a + b*Log[c*x^n]])/(2*(1 + b^2*n^2)) + (x^2*Sin[a + b*Log[c*x^n]]^2)/(2*(1 + b^2*n^2))}
{x^2*Sin[a + b*Log[c*x^n]]^2, x, 2, (2*b^2*n^2*x^3)/(3*(9 + 4*b^2*n^2)) - (2*b*n*x^3*Cos[a + b*Log[c*x^n]]*Sin[a + b*Log[c*x^n]])/(9 + 4*b^2*n^2) + (3*x^3*Sin[a + b*Log[c*x^n]]^2)/(9 + 4*b^2*n^2)}
{Sin[a + b*Log[c*x^n]]^2/x^2, x, 2, -((2*b^2*n^2)/((1 + 4*b^2*n^2)*x)) - (2*b*n*Cos[a + b*Log[c*x^n]]*Sin[a + b*Log[c*x^n]])/((1 + 4*b^2*n^2)*x) - Sin[a + b*Log[c*x^n]]^2/((1 + 4*b^2*n^2)*x)}
{x^m*Sin[a + b*Log[c*x^n]]^2, x, 2, (2*b^2*n^2*x^(1 + m))/((1 + m)*((1 + m)^2 + 4*b^2*n^2)) - (2*b*n*x^(1 + m)*Cos[a + b*Log[c*x^n]]*Sin[a + b*Log[c*x^n]])/((1 + m)^2 + 4*b^2*n^2) + ((1 + m)*x^(1 + m)*Sin[a + b*Log[c*x^n]]^2)/((1 + m)^2 + 4*b^2*n^2)}

{Sin[a + b*Log[c*x^n]]^3, x, 2, -((6*b^3*n^3*x*Cos[a + b*Log[c*x^n]])/((1 + b^2*n^2)*(1 + 9*b^2*n^2))) + (6*b^2*n^2*x*Sin[a + b*Log[c*x^n]])/((1 + b^2*n^2)*(1 + 9*b^2*n^2)) - (3*b*n*x*Cos[a + b*Log[c*x^n]]*Sin[a + b*Log[c*x^n]]^2)/(1 + 9*b^2*n^2) + (x*Sin[a + b*Log[c*x^n]]^3)/(1 + 9*b^2*n^2)}
{x*Sin[a + b*Log[c*x^n]]^3, x, 2, -((6*b^3*n^3*x^2*Cos[a + b*Log[c*x^n]])/((4 + b^2*n^2)*(4 + 9*b^2*n^2))) + (12*b^2*n^2*x^2*Sin[a + b*Log[c*x^n]])/((4 + b^2*n^2)*(4 + 9*b^2*n^2)) - (3*b*n*x^2*Cos[a + b*Log[c*x^n]]*Sin[a + b*Log[c*x^n]]^2)/(4 + 9*b^2*n^2) + (2*x^2*Sin[a + b*Log[c*x^n]]^3)/(4 + 9*b^2*n^2)}
{x^2*Sin[a + b*Log[c*x^n]]^3, x, 2, -((2*b^3*n^3*x^3*Cos[a + b*Log[c*x^n]])/(3*(1 + b^2*n^2)*(9 + b^2*n^2))) + (2*b^2*n^2*x^3*Sin[a + b*Log[c*x^n]])/((1 + b^2*n^2)*(9 + b^2*n^2)) - (b*n*x^3*Cos[a + b*Log[c*x^n]]*Sin[a + b*Log[c*x^n]]^2)/(3*(1 + b^2*n^2)) + (x^3*Sin[a + b*Log[c*x^n]]^3)/(3*(1 + b^2*n^2))}
{Sin[a + b*Log[c*x^n]]^3/x^2, x, 2, -((6*b^3*n^3*Cos[a + b*Log[c*x^n]])/((1 + b^2*n^2)*(1 + 9*b^2*n^2)*x)) - (6*b^2*n^2*Sin[a + b*Log[c*x^n]])/((1 + b^2*n^2)*(1 + 9*b^2*n^2)*x) - (3*b*n*Cos[a + b*Log[c*x^n]]*Sin[a + b*Log[c*x^n]]^2)/((1 + 9*b^2*n^2)*x) - Sin[a + b*Log[c*x^n]]^3/((1 + 9*b^2*n^2)*x)}
{x^m*Sin[a + b*Log[c*x^n]]^3, x, 2, -((6*b^3*n^3*x^(1 + m)*Cos[a + b*Log[c*x^n]])/(((1 + m)^2 + b^2*n^2)*((1 + m)^2 + 9*b^2*n^2))) + (6*b^2*(1 + m)*n^2*x^(1 + m)*Sin[a + b*Log[c*x^n]])/(((1 + m)^2 + b^2*n^2)*((1 + m)^2 + 9*b^2*n^2)) - (3*b*n*x^(1 + m)*Cos[a + b*Log[c*x^n]]*Sin[a + b*Log[c*x^n]]^2)/((1 + m)^2 + 9*b^2*n^2) + ((1 + m)*x^(1 + m)*Sin[a + b*Log[c*x^n]]^3)/((1 + m)^2 + 9*b^2*n^2)}


{1/(x*(1 + Sin[Log[x]])), x, 2, -(Cos[Log[x]]/(1 + Sin[Log[x]]))}
{Sin[Log[a + b*x]], x, 2, -(((a + b*x)*Cos[Log[a + b*x]])/(2*b)) + ((a + b*x)*Sin[Log[a + b*x]])/(2*b)}


(* ::Subsection::Closed:: *)
(*Integrands of the form Cos[c+d x]^m (a+b Sin[c+d x])^n*)


(* Integrands of the form Cos[x]^m/(a+b*Sin[x]) where m is a positive integer *)
{Cos[x]/(a + b*Sin[x]), x, 2, Log[a + b*Sin[x]]/b}
{Cos[x]^2/(a + b*Sin[x]), x, 4, (a*x)/b^2 - (2*Sqrt[a^2 - b^2]*ArcTan[(b + a*Tan[x/2])/Sqrt[a^2 - b^2]])/b^2 + Cos[x]/b}
{Cos[x]^3/(a + b*Sin[x]), x, 5, -(((a^2 - b^2)*Log[a + b*Sin[x]])/b^3) + (a*Sin[x])/b^2 - Sin[x]^2/(2*b)}
{Cos[x]^4/(a + b*Sin[x]), x, 7, -((a^3*x)/b^4) + (3*a*x)/(2*b^2) + (2*(a^2 - b^2)^(3/2)*ArcTan[(b + a*Tan[x/2])/Sqrt[a^2 - b^2]])/b^4 - (a^2*Cos[x])/b^3 + Cos[x]/b + Cos[x]^3/(3*b) + (a*Cos[x]*Sin[x])/(2*b^2)}

{Cos[x]/(a + a*Sin[x]), x, 3, Log[1 + Sin[x]]/a}
{Cos[x]^2/(a + a*Sin[x]), x, 3, x/a + Cos[x]/a}
{Cos[x]^3/(a + a*Sin[x]), x, 2, Sin[x]/a - Sin[x]^2/(2*a)}
{Cos[x]^4/(a + a*Sin[x]), x, 6, x/(2*a) + Cos[x]^3/(3*a) + (Cos[x]*Sin[x])/(2*a)}


(* Integrands of the form Cos[x]^m/(a+b*Sin[x])^2 where m is a positive integer *)
{Cos[x]/(a + b*Sin[x])^2, x, 2, -(1/(b*(a + b*Sin[x])))}
{Cos[x]^2/(a + b*Sin[x])^2, x, 6, -(x/b^2) + (2*a*ArcTan[(b + a*Tan[x/2])/Sqrt[a^2 - b^2]])/(b^2*Sqrt[a^2 - b^2]) - Cos[x]/(b*(a + b*Sin[x]))}
{Cos[x]^3/(a + b*Sin[x])^2, x, 5, (2*a*Log[a + b*Sin[x]])/b^3 - Sin[x]/b^2 + (a^2 - b^2)/(b^3*(a + b*Sin[x]))}
{Cos[x]^4/(a + b*Sin[x])^2, x, 8, (3*a^2*x)/b^4 - (3*x)/(2*b^2) - (6*a*Sqrt[a^2 - b^2]*ArcTan[(b + a*Tan[x/2])/Sqrt[a^2 - b^2]])/b^4 + (2*a*Cos[x])/b^3 - (Cos[x]*Sin[x])/(2*b^2) + ((a^2 - b^2)*Cos[x])/(b^3*(a + b*Sin[x]))}

{Cos[x]/(a + a*Sin[x])^2, x, 2, -(1/(a^2*(1 + Sin[x])))}
{Cos[x]^2/(a + a*Sin[x])^2, x, 3, -(x/a^2) - (2*Cos[x])/(a^2*(1 + Sin[x]))}
{Cos[x]^3/(a + a*Sin[x])^2, x, 5, (2*Log[1 + Sin[x]])/a^2 - Sin[x]/a^2}
{Cos[x]^4/(a + a*Sin[x])^2, x, 4, (3*x)/(2*a^2) + (2*Cos[x])/a^2 - (Cos[x]*Sin[x])/(2*a^2)}


{Cos[x]/(1 + Sin[x])^3, x, 2, -(1/(2*(1 + Sin[x])^2))}
{Cos[x]/(1 - Sin[x])^3, x, 2, 1/(2*(1 - Sin[x])^2)}
{Cos[x]^2/(1 + Sin[x])^3, x, 5, -((2*Cos[x])/(3*(1 + Sin[x])^2)) + Cos[x]/(3*(1 + Sin[x]))}
{Cos[x]^2/(1 - Sin[x])^3, x, 5, (2*Cos[x])/(3*(1 - Sin[x])^2) - Cos[x]/(3*(1 - Sin[x]))}
{Cos[x]^3/(1 + Sin[x])^3, x, 5, -Log[1 + Sin[x]] - 2/(1 + Sin[x])}
{Cos[x]^3/(1 - Sin[x])^3, x, 5, Log[1 - Sin[x]] + 2/(1 - Sin[x])}


{Cos[x]^2*Sqrt[1 + Sin[x]], x, 11, -((Sqrt[1 + Sin[x]]*(30*Cos[x/2] - 5*Cos[(3*x)/2] + 3*Cos[(5*x)/2] - 30*Sin[x/2] - 5*Sin[(3*x)/2] - 3*Sin[(5*x)/2]))/(30*(Cos[x/2] + Sin[x/2])))}


(* ::Subsection::Closed:: *)
(*Integrands of the form Tan[c+d x]^m (a+b Sin[c+d x])^n*)


(* Integrands of the form Tan[x]^m/(a+b*Sin[x]) where m is a positive integer *)
{Tan[x]/(a + b*Sin[x]), x, 7, -(Log[1 - Sin[x]]/(2*(a + b))) - Log[1 + Sin[x]]/(2*(a - b)) + (a*Log[a + b*Sin[x]])/(a^2 - b^2)}
{Tan[x]^2/(a + b*Sin[x]), x, 5, -((2*a^2*ArcTan[(b + a*Tan[x/2])/Sqrt[a^2 - b^2]])/(a^2 - b^2)^(3/2)) + Cos[x]/(2*(a + b)*(1 - Sin[x])) - Cos[x]/(2*(a - b)*(1 + Sin[x]))}
{Tan[x]^3/(a + b*Sin[x]), x, 8, ((2*a + b)*Log[1 - Sin[x]])/(4*(a + b)^2) + ((2*a - b)*Log[1 + Sin[x]])/(4*(a - b)^2) - (a^3*Log[a + b*Sin[x]])/(a^2 - b^2)^2 + 1/(4*(a + b)*(1 - Sin[x])) + 1/(4*(a - b)*(1 + Sin[x]))}
{Tan[x]^4/(a + b*Sin[x]), x, 9, (2*a^4*ArcTan[(b + a*Tan[x/2])/Sqrt[a^2 - b^2]])/(a^2 - b^2)^(5/2) + Cos[x]/(12*(a + b)*(1 - Sin[x])^2) + Cos[x]/(12*(a + b)*(1 - Sin[x])) - ((3*a + 2*b)*Cos[x])/(4*(a + b)^2*(1 - Sin[x])) - Cos[x]/(12*(a - b)*(1 + Sin[x])^2) + ((3*a - 2*b)*Cos[x])/(4*(a - b)^2*(1 + Sin[x])) - Cos[x]/(12*(a - b)*(1 + Sin[x]))}

{Tan[x]/(a + a*Sin[x]), x, 6, ArcTanh[Sin[x]]/(2*a) + 1/(2*a*(1 + Sin[x]))}
{Tan[x]^2/(a + a*Sin[x]), x, 6, Cos[x]/(4*a*(1 - Sin[x])) - Cos[x]/(6*a*(1 + Sin[x])^2) + (7*Cos[x])/(12*a*(1 + Sin[x]))}
{Tan[x]^3/(a + a*Sin[x]), x, 8, -((3*ArcTanh[Sin[x]])/(8*a)) + 1/(8*a*(1 - Sin[x])) + 1/(8*a*(1 + Sin[x])^2) - 1/(2*a*(1 + Sin[x]))}
{Tan[x]^4/(a + a*Sin[x]), x, 11, Cos[x]/(24*a*(1 - Sin[x])^2) - (13*Cos[x])/(48*a*(1 - Sin[x])) - Cos[x]/(20*a*(1 + Sin[x])^3) + (13*Cos[x])/(60*a*(1 + Sin[x])^2) - (113*Cos[x])/(240*a*(1 + Sin[x]))}


(* Integrands of the form Tan[x]^m/(a+b*Sin[x])^2 where m is a positive integer *)
{Tan[x]/(a + b*Sin[x])^2, x, 8, -(Log[1 - Sin[x]]/(2*(a + b)^2)) - Log[1 + Sin[x]]/(2*(a - b)^2) + ((a^2 + b^2)*Log[a + b*Sin[x]])/(a^2 - b^2)^2 - a/((a^2 - b^2)*(a + b*Sin[x]))}
{Tan[x]^2/(a + b*Sin[x])^2, x, 8, -((2*a^3*ArcTan[(b + a*Tan[x/2])/Sqrt[a^2 - b^2]])/(a^2 - b^2)^(5/2)) - (4*a*b^2*ArcTan[(b + a*Tan[x/2])/Sqrt[a^2 - b^2]])/(a^2 - b^2)^(5/2) + Cos[x]/(2*(a + b)^2*(1 - Sin[x])) - Cos[x]/(2*(a - b)^2*(1 + Sin[x])) - (a^2*b*Cos[x])/((a^2 - b^2)^2*(a + b*Sin[x]))}
{Tan[x]^3/(a + b*Sin[x])^2, x, 9, (a*Log[1 - Sin[x]])/(2*(a + b)^3) + (a*Log[1 + Sin[x]])/(2*(a - b)^3) - (a^2*(a^2 + 3*b^2)*Log[a + b*Sin[x]])/(a^2 - b^2)^3 + 1/(4*(a + b)^2*(1 - Sin[x])) + 1/(4*(a - b)^2*(1 + Sin[x])) + a^3/((a^2 - b^2)^2*(a + b*Sin[x]))}
(* {Tan[x]^4/(a + b*Sin[x])^2, x, 11, (2*a^5*ArcTan[(b + a*Tan[x/2])/Sqrt[a^2 - b^2]])/(a^2 - b^2)^(7/2) + (8*a^3*b^2*ArcTan[(b + a*Tan[x/2])/Sqrt[a^2 - b^2]])/(a^2 - b^2)^(7/2) + Cos[x]/(12*(a + b)^2*(1 - Sin[x])^2) + Cos[x]/(12*(a + b)^2*(1 - Sin[x])) - ((3*a + b)*Cos[x])/(4*(a + b)^3*(1 - Sin[x])) - Cos[x]/(12*(a - b)^2*(1 + Sin[x])^2) - Cos[x]/(12*(a - b)^2*(1 + Sin[x])) + ((3*a - b)*Cos[x])/(4*(a - b)^3*(1 + Sin[x])) + (a^4*b*Cos[x])/((a^2 - b^2)^3*(a + b*Sin[x]))} *)

{Tan[x]/(a + a*Sin[x])^2, x, 7, ArcTanh[Sin[x]]/(4*a^2) + 1/(4*a^2*(1 + Sin[x])^2) - 1/(4*a^2*(1 + Sin[x]))}
{Tan[x]^2/(a + a*Sin[x])^2, x, 9, Cos[x]/(8*a^2*(1 - Sin[x])) - Cos[x]/(10*a^2*(1 + Sin[x])^3) + (11*Cos[x])/(60*a^2*(1 + Sin[x])^2) + (7*Cos[x])/(120*a^2*(1 + Sin[x]))}
{Tan[x]^3/(a + a*Sin[x])^2, x, 9, -(ArcTanh[Sin[x]]/(8*a^2)) + 1/(16*a^2*(1 - Sin[x])) + 1/(12*a^2*(1 + Sin[x])^3) - 1/(4*a^2*(1 + Sin[x])^2) + 3/(16*a^2*(1 + Sin[x]))}
(* {Tan[x]^4/(a + a*Sin[x])^2, x, 14, Cos[x]/(48*a^2*(1 - Sin[x])^2) + Cos[x]/(48*a^2*(1 - Sin[x])) - Cos[x]/(28*a^2*(1 + Sin[x])^4) + (9*Cos[x])/(70*a^2*(1 + Sin[x])^3) - (241*Cos[x])/(1680*a^2*(1 + Sin[x])^2) - (241*Cos[x])/(1680*a^2*(1 + Sin[x])) - Tan[x]/(4*a^2)} *)


(* ::Subsection::Closed:: *)
(*Integrands of the form Cot[c+d x]^m (a+b Sin[c+d x])^n*)


(* Integrands of the form Cot[x]^m/(a+b*Sin[x]) where m is a positive integer *)
{Cot[x]/(a + b*Sin[x]), x, 2, Log[Sin[x]]/a - Log[a + b*Sin[x]]/a}
{Cot[x]^2/(a + b*Sin[x]), x, 5, -((2*Sqrt[a^2 - b^2]*ArcTan[(b + a*Tan[x/2])/Sqrt[a^2 - b^2]])/a^2) + (b*ArcTanh[Cos[x]])/a^2 - Cot[x]/a}
{Cot[x]^3/(a + b*Sin[x]), x, 5, (b*Csc[x])/a^2 - Csc[x]^2/(2*a) - ((a^2 - b^2)*Log[Sin[x]])/a^3 + ((a^2 - b^2)*Log[a + b*Sin[x]])/a^3}
{Cot[x]^4/(a + b*Sin[x]), x, 9, (2*(a^2 - b^2)^(3/2)*ArcTan[(b + a*Tan[x/2])/Sqrt[a^2 - b^2]])/a^4 - (3*b*ArcTanh[Cos[x]])/(2*a^2) + (b^3*ArcTanh[Cos[x]])/a^4 + Cot[x]/a - (b^2*Cot[x])/a^3 - Cot[x]^3/(3*a) + (b*Cot[x]*Csc[x])/(2*a^2)}

{Cot[x]/(a + a*Sin[x]), x, 3, -((2*ArcTanh[1 + 2*Sin[x]])/a)}
{Cot[x]^2/(a + a*Sin[x]), x, 4, ArcTanh[Cos[x]]/a - Cot[x]/a}
{Cot[x]^3/(a + a*Sin[x]), x, 3, Csc[x]/a - Csc[x]^2/(2*a)}
{Cot[x]^4/(a + a*Sin[x]), x, 8, -(ArcTanh[Cos[x]]/(2*a)) - Cot[x]^3/(3*a) + (Cot[x]*Csc[x])/(2*a)}


(* Integrands of the form Cot[x]^m/(a+b*Sin[x])^2 where m is a positive integer *)
{Cot[x]/(a + b*Sin[x])^2, x, 5, Log[Sin[x]]/a^2 - Log[a + b*Sin[x]]/a^2 + 1/(a*(a + b*Sin[x]))}
{Cot[x]^2/(a + b*Sin[x])^2, x, 8, -((2*ArcTan[(b + a*Tan[x/2])/Sqrt[a^2 - b^2]])/(a*Sqrt[a^2 - b^2])) + (4*b^2*ArcTan[(b + a*Tan[x/2])/Sqrt[a^2 - b^2]])/(a^3*Sqrt[a^2 - b^2]) + (2*b*ArcTanh[Cos[x]])/a^3 - Cot[x]/a^2 - (b*Cos[x])/(a^2*(a + b*Sin[x]))}
{Cot[x]^3/(a + b*Sin[x])^2, x, 6, (2*b*Csc[x])/a^3 - Csc[x]^2/(2*a^2) - ((a^2 - 3*b^2)*Log[Sin[x]])/a^4 + ((a^2 - 3*b^2)*Log[a + b*Sin[x]])/a^4 - (a^2 - b^2)/(a^3*(a + b*Sin[x]))}
(* {Cot[x]^4/(a + b*Sin[x])^2, x, 11, (2*Sqrt[a^2 - b^2]*ArcTan[(b + a*Tan[x/2])/Sqrt[a^2 - b^2]])/a^3 - (8*b^2*Sqrt[a^2 - b^2]*ArcTan[(b + a*Tan[x/2])/Sqrt[a^2 - b^2]])/a^5 - (3*b*ArcTanh[Cos[x]])/a^3 + (4*b^3*ArcTanh[Cos[x]])/a^5 + Cot[x]/a^2 - (3*b^2*Cot[x])/a^4 - Cot[x]^3/(3*a^2) + (b*Cot[x]*Csc[x])/a^3 + (b*(a^2 - b^2)*Cos[x])/(a^4*(a + b*Sin[x]))} *)

{Cot[x]/(a + a*Sin[x])^2, x, 5, -((2*ArcTanh[1 + 2*Sin[x]])/a^2) + 1/(a^2*(1 + Sin[x]))}
{Cot[x]^2/(a + a*Sin[x])^2, x, 5, (2*ArcTanh[Cos[x]])/a^2 - Cot[x]/a^2 - (2*Cos[x])/(a^2*(1 + Sin[x]))}
{Cot[x]^3/(a + a*Sin[x])^2, x, 6, -((4*ArcTanh[1 + 2*Sin[x]])/a^2) + (2*Csc[x])/a^2 - Csc[x]^2/(2*a^2)}
(* {Cot[x]^4/(a + a*Sin[x])^2, x, 7, ArcTanh[Cos[x]]/a^2 - (2*Cot[x])/a^2 - Cot[x]^3/(3*a^2) + (Cot[x]*Csc[x])/a^2} *)


{Cot[x]*Sqrt[1 + Sin[x]], x, 3, -2*ArcTanh[Sqrt[1 + Sin[x]]] + 2*Sqrt[1 + Sin[x]]}


(* ::Subsection::Closed:: *)
(*Integrands of the form Sec[c+d x]^m (a+b Sin[c+d x])^n*)


(* Integrands of the form Sec[x]^m/(a+b*Sin[x]) where m is a positive integer *)
{Sec[x]/(a + b*Sin[x]), x, 7, -(Log[1 - Sin[x]]/(2*(a + b))) + Log[1 + Sin[x]]/(2*(a - b)) - (b*Log[a + b*Sin[x]])/(a^2 - b^2)}
{Sec[x]^2/(a + b*Sin[x]), x, 5, -((2*b^2*ArcTan[(b + a*Tan[x/2])/Sqrt[a^2 - b^2]])/(a^2 - b^2)^(3/2)) + Cos[x]/(2*(a + b)*(1 - Sin[x])) - Cos[x]/(2*(a - b)*(1 + Sin[x]))}
{Sec[x]^3/(a + b*Sin[x]), x, 8, -(((a + 2*b)*Log[1 - Sin[x]])/(4*(a + b)^2)) + ((a - 2*b)*Log[1 + Sin[x]])/(4*(a - b)^2) + (b^3*Log[a + b*Sin[x]])/(a^2 - b^2)^2 + 1/(4*(a + b)*(1 - Sin[x])) - 1/(4*(a - b)*(1 + Sin[x]))}
{Sec[x]^4/(a + b*Sin[x]), x, 9, (2*b^4*ArcTan[(b + a*Tan[x/2])/Sqrt[a^2 - b^2]])/(a^2 - b^2)^(5/2) + Cos[x]/(12*(a + b)*(1 - Sin[x])^2) + Cos[x]/(12*(a + b)*(1 - Sin[x])) + ((a + 2*b)*Cos[x])/(4*(a + b)^2*(1 - Sin[x])) - Cos[x]/(12*(a - b)*(1 + Sin[x])^2) - ((a - 2*b)*Cos[x])/(4*(a - b)^2*(1 + Sin[x])) - Cos[x]/(12*(a - b)*(1 + Sin[x]))}

{Sec[x]/(a + a*Sin[x]), x, 6, ArcTanh[Sin[x]]/(2*a) - 1/(2*a*(1 + Sin[x]))}
{Sec[x]^2/(a + a*Sin[x]), x, 6, Cos[x]/(4*a*(1 - Sin[x])) - Cos[x]/(6*a*(1 + Sin[x])^2) - (5*Cos[x])/(12*a*(1 + Sin[x]))}
{Sec[x]^3/(a + a*Sin[x]), x, 8, (3*ArcTanh[Sin[x]])/(8*a) + 1/(8*a*(1 - Sin[x])) - 1/(8*a*(1 + Sin[x])^2) - 1/(4*a*(1 + Sin[x]))}
{Sec[x]^4/(a + a*Sin[x]), x, 11, Cos[x]/(24*a*(1 - Sin[x])^2) + (11*Cos[x])/(48*a*(1 - Sin[x])) - Cos[x]/(20*a*(1 + Sin[x])^3) - (7*Cos[x])/(60*a*(1 + Sin[x])^2) - (73*Cos[x])/(240*a*(1 + Sin[x]))}


(* Integrands of the form Sec[x]^m/(a+b*Sin[x])^2 where m is a positive integer *)
{Sec[x]/(a + b*Sin[x])^2, x, 8, -(Log[1 - Sin[x]]/(2*(a + b)^2)) + Log[1 + Sin[x]]/(2*(a - b)^2) - (2*a*b*Log[a + b*Sin[x]])/(a^2 - b^2)^2 + b/((a^2 - b^2)*(a + b*Sin[x]))}
{Sec[x]^2/(a + b*Sin[x])^2, x, 8, -((6*a*b^2*ArcTan[(b + a*Tan[x/2])/Sqrt[a^2 - b^2]])/(a^2 - b^2)^(5/2)) + Cos[x]/(2*(a + b)^2*(1 - Sin[x])) - Cos[x]/(2*(a - b)^2*(1 + Sin[x])) - (b^3*Cos[x])/((a^2 - b^2)^2*(a + b*Sin[x]))}
{Sec[x]^3/(a + b*Sin[x])^2, x, 9, -(((a + 3*b)*Log[1 - Sin[x]])/(4*(a + b)^3)) + ((a - 3*b)*Log[1 + Sin[x]])/(4*(a - b)^3) + (4*a*b^3*Log[a + b*Sin[x]])/(a^2 - b^2)^3 + 1/(4*(a + b)^2*(1 - Sin[x])) - 1/(4*(a - b)^2*(1 + Sin[x])) - b^3/((a^2 - b^2)^2*(a + b*Sin[x]))}
(* {Sec[x]^4/(a + b*Sin[x])^2, x, 11, (10*a*b^4*ArcTan[(b + a*Tan[x/2])/Sqrt[a^2 - b^2]])/(a^2 - b^2)^(7/2) + Cos[x]/(12*(a + b)^2*(1 - Sin[x])^2) + Cos[x]/(12*(a + b)^2*(1 - Sin[x])) + ((a + 3*b)*Cos[x])/(4*(a + b)^3*(1 - Sin[x])) - Cos[x]/(12*(a - b)^2*(1 + Sin[x])^2) - ((a - 3*b)*Cos[x])/(4*(a - b)^3*(1 + Sin[x])) - Cos[x]/(12*(a - b)^2*(1 + Sin[x])) + (b^5*Cos[x])/((a^2 - b^2)^3*(a + b*Sin[x]))} *)

{Sec[x]/(a + a*Sin[x])^2, x, 7, ArcTanh[Sin[x]]/(4*a^2) - 1/(4*a^2*(1 + Sin[x])^2) - 1/(4*a^2*(1 + Sin[x]))}
{Sec[x]^2/(a + a*Sin[x])^2, x, 9, Cos[x]/(8*a^2*(1 - Sin[x])) - Cos[x]/(10*a^2*(1 + Sin[x])^3) - (3*Cos[x])/(20*a^2*(1 + Sin[x])^2) - (11*Cos[x])/(40*a^2*(1 + Sin[x]))}
{Sec[x]^3/(a + a*Sin[x])^2, x, 9, ArcTanh[Sin[x]]/(4*a^2) + 1/(16*a^2*(1 - Sin[x])) - 1/(12*a^2*(1 + Sin[x])^3) - 1/(8*a^2*(1 + Sin[x])^2) - 3/(16*a^2*(1 + Sin[x]))}
(* {Sec[x]^4/(a + a*Sin[x])^2, x, 14, Cos[x]/(48*a^2*(1 - Sin[x])^2) + Cos[x]/(48*a^2*(1 - Sin[x])) - Cos[x]/(28*a^2*(1 + Sin[x])^4) - Cos[x]/(14*a^2*(1 + Sin[x])^3) - (37*Cos[x])/(336*a^2*(1 + Sin[x])^2) - (37*Cos[x])/(336*a^2*(1 + Sin[x])) + Tan[x]/(4*a^2)} *)


{Sec[x]/Sqrt[1 + Sin[x]], x, 4, ArcTanh[Sqrt[1 + Sin[x]]/Sqrt[2]]/Sqrt[2] - 1/Sqrt[1 + Sin[x]]}


(* ::Subsection::Closed:: *)
(*Integrands of the form (A+B Cos[c+d x]) (a+b Sin[c+d x])^n*)


(* Integrands of the form (A+B*Cos[x])*(a+b*Sin[x])^n where n is an integer *)
{(A + B*Cos[x])/(a + b*Sin[x]), x, 5, (2*A*ArcTan[(b + a*Tan[x/2])/Sqrt[a^2 - b^2]])/Sqrt[a^2 - b^2] + (B*Log[a + b*Sin[x]])/b}

{(A + B*Cos[x])/(1 + Sin[x]), x, 5, B*Log[1 + Sin[x]] - (A*Cos[x])/(1 + Sin[x])}
{(A + B*Cos[x])/(1 - Sin[x]), x, 5, (-B)*Log[1 - Sin[x]] + (A*Cos[x])/(1 - Sin[x])}


(* ::Subsection::Closed:: *)
(*Integrands of the form (A+B Tan[c+d x]) (a+b Sin[c+d x])^n*)


{(A + B*Tan[x])/(a + b*Sin[x]), x, 10, (2*A*ArcTan[(b + a*Tan[x/2])/Sqrt[a^2 - b^2]])/Sqrt[a^2 - b^2] - (B*Log[1 - Sin[x]])/(2*(a + b)) - (B*Log[1 + Sin[x]])/(2*(a - b)) + (a*B*Log[a + b*Sin[x]])/(a^2 - b^2)}


(* ::Subsection::Closed:: *)
(*Integrands of the form (A+B Cot[c+d x]) (a+b Sin[c+d x])^n*)


{(A + B*Cot[x])/(a + b*Sin[x]), x, 5, (2*A*ArcTan[(b + a*Tan[x/2])/Sqrt[a^2 - b^2]])/Sqrt[a^2 - b^2] + (B*Log[Sin[x]])/a - (B*Log[a + b*Sin[x]])/a}


(* ::Subsection::Closed:: *)
(*Integrands of the form (A+B Sec[c+d x]) (a+b Sin[c+d x])^n*)


{(A + B*Sec[x])/(a + b*Sin[x]), x, 10, (2*A*ArcTan[(b + a*Tan[x/2])/Sqrt[a^2 - b^2]])/Sqrt[a^2 - b^2] - (B*Log[1 - Sin[x]])/(2*(a + b)) + (B*Log[1 + Sin[x]])/(2*(a - b)) - (b*B*Log[a + b*Sin[x]])/(a^2 - b^2)}


(* ::Subsection::Closed:: *)
(*Integrands of the form (A+B Csc[c+d x]) (a+b Sin[c+d x])^n*)


{(A + B*Csc[x])/(a + b*Sin[x]), x, 4, (2*(a*A - b*B)*ArcTan[(b + a*Tan[x/2])/Sqrt[a^2 - b^2]])/(a*Sqrt[a^2 - b^2]) - (B*ArcTanh[Cos[x]])/a}
