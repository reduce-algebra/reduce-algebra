(* ::Package:: *)

(* ::Title:: *)
(*Integration Problems Involving Cosines*)


(* ::Subsection::Closed:: *)
(*x^m Cos[a+b x]^n*)


(* Integrands of the form x^m*Cos[a+b*x]^n where m and n are integers *)
{x*Cos[a + b*x], x, 2, Cos[a + b*x]/b^2 + (x*Sin[a + b*x])/b}
{x*Cos[a + b*x]^2, x, 2, x^2/4 + Cos[a + b*x]^2/(4*b^2) + (x*Cos[a + b*x]*Sin[a + b*x])/(2*b)}
{x*Cos[a + b*x]^3, x, 3, (2*Cos[a + b*x])/(3*b^2) + Cos[a + b*x]^3/(9*b^2) + (2*x*Sin[a + b*x])/(3*b) + (x*Cos[a + b*x]^2*Sin[a + b*x])/(3*b)}

{x^2*Cos[a + b*x], x, 3, (2*x*Cos[a + b*x])/b^2 - (2*Sin[a + b*x])/b^3 + (x^2*Sin[a + b*x])/b}
{x^2*Cos[a + b*x]^2, x, 3, -(x/(4*b^2)) + x^3/6 + (x*Cos[a + b*x]^2)/(2*b^2) - (Cos[a + b*x]*Sin[a + b*x])/(4*b^3) + (x^2*Cos[a + b*x]*Sin[a + b*x])/(2*b)}
{x^2*Cos[a + b*x]^3, x, 6, (4*x*Cos[a + b*x])/(3*b^2) + (2*x*Cos[a + b*x]^3)/(9*b^2) - (14*Sin[a + b*x])/(9*b^3) + (2*x^2*Sin[a + b*x])/(3*b) + (x^2*Cos[a + b*x]^2*Sin[a + b*x])/(3*b) + (2*Sin[a + b*x]^3)/(27*b^3)}
{x^2*Cos[a + b*x]^4, x, 6, -((15*x)/(64*b^2)) + x^3/8 + (3*x*Cos[a + b*x]^2)/(8*b^2) + (x*Cos[a + b*x]^4)/(8*b^2) - (15*Cos[a + b*x]*Sin[a + b*x])/(64*b^3) + (3*x^2*Cos[a + b*x]*Sin[a + b*x])/(8*b) - (Cos[a + b*x]^3*Sin[a + b*x])/(32*b^3) + (x^2*Cos[a + b*x]^3*Sin[a + b*x])/(4*b)}

{x^3*Cos[a + b*x], x, 4, -((6*Cos[a + b*x])/b^4) + (3*x^2*Cos[a + b*x])/b^2 - (6*x*Sin[a + b*x])/b^3 + (x^3*Sin[a + b*x])/b}
{x^3*Cos[a + b*x]^2, x, 4, -((3*x^2)/(8*b^2)) + x^4/8 - (3*Cos[a + b*x]^2)/(8*b^4) + (3*x^2*Cos[a + b*x]^2)/(4*b^2) - (3*x*Cos[a + b*x]*Sin[a + b*x])/(4*b^3) + (x^3*Cos[a + b*x]*Sin[a + b*x])/(2*b)}
{x^3*Cos[a + b*x]^3, x, 8, -((40*Cos[a + b*x])/(9*b^4)) + (2*x^2*Cos[a + b*x])/b^2 - (2*Cos[a + b*x]^3)/(27*b^4) + (x^2*Cos[a + b*x]^3)/(3*b^2) - (40*x*Sin[a + b*x])/(9*b^3) + (2*x^3*Sin[a + b*x])/(3*b) - (2*x*Cos[a + b*x]^2*Sin[a + b*x])/(9*b^3) + (x^3*Cos[a + b*x]^2*Sin[a + b*x])/(3*b)}

{x^5*Cos[a + b*x], x, 6, (120*Cos[a + b*x])/b^6 - (60*x^2*Cos[a + b*x])/b^4 + (5*x^4*Cos[a + b*x])/b^2 + (120*x*Sin[a + b*x])/b^5 - (20*x^3*Sin[a + b*x])/b^3 + (x^5*Sin[a + b*x])/b}

{Cos[a + b*x^n]/x, x, 3, (Cos[a]*CosIntegral[b*x^n])/n - (Sin[a]*SinIntegral[b*x^n])/n}
{Cos[a + b*x^n]^2/x, x, 7, (Cos[2*a]*CosIntegral[2*b*x^n])/(2*n) + Log[x]/2 - (Sin[2*a]*SinIntegral[2*b*x^n])/(2*n), (Cos[2*a]*CosIntegral[2*b*x^n])/(2*n) + Log[x^n]/(2*n) - (Sin[2*a]*SinIntegral[2*b*x^n])/(2*n)}
{Cos[a + b*x^n]^3/x, x, 9, (3*Cos[a]*CosIntegral[b*x^n])/(4*n) + (Cos[3*a]*CosIntegral[3*b*x^n])/(4*n) - (3*Sin[a]*SinIntegral[b*x^n])/(4*n) - (Sin[3*a]*SinIntegral[3*b*x^n])/(4*n)}

{Cos[a + b*x]/x^2, x, 4, -(Cos[a + b*x]/x) - b*CosIntegral[b*x]*Sin[a] - b*Cos[a]*SinIntegral[b*x]}
{Cos[a + b*x]^2/x^2, x, 7, -(1/(2*x)) - Cos[2*a + 2*b*x]/(2*x) - b*CosIntegral[2*b*x]*Sin[2*a] - b*Cos[2*a]*SinIntegral[2*b*x]}
{Cos[a + b*x]^3/x^2, x, 10, -((3*Cos[a + b*x])/(4*x)) - Cos[3*a + 3*b*x]/(4*x) - (3/4)*b*CosIntegral[b*x]*Sin[a] - (3/4)*b*CosIntegral[3*b*x]*Sin[3*a] - (3/4)*b*Cos[a]*SinIntegral[b*x] - (3/4)*b*Cos[3*a]*SinIntegral[3*b*x]}

{Cos[a + b*x]/x^3, x, 5, -(Cos[a + b*x]/(2*x^2)) - (1/2)*b^2*Cos[a]*CosIntegral[b*x] + (b*Sin[a + b*x])/(2*x) + (1/2)*b^2*Sin[a]*SinIntegral[b*x]}
{Cos[a + b*x]^2/x^3, x, 8, -(Cos[a + b*x]^2/(2*x^2)) - b^2*Cos[2*a]*CosIntegral[2*b*x] + (b*Cos[a + b*x]*Sin[a + b*x])/x + b^2*Sin[2*a]*SinIntegral[2*b*x]}
{Cos[a + b*x]^3/x^3, x, 12, -(Cos[a + b*x]^3/(2*x^2)) - (3/8)*b^2*Cos[a]*CosIntegral[b*x] - (9/8)*b^2*Cos[3*a]*CosIntegral[3*b*x] + (3*b*Cos[a + b*x]^2*Sin[a + b*x])/(2*x) + (3/8)*b^2*Sin[a]*SinIntegral[b*x] + (9/8)*b^2*Sin[3*a]*SinIntegral[3*b*x]}


{x*Cos[a + b*x^2]^7, x, 3, Sin[a + b*x^2]/(2*b) - Sin[a + b*x^2]^3/(2*b) + (3*Sin[a + b*x^2]^5)/(10*b) - Sin[a + b*x^2]^7/(14*b)}


{Cos[x]/Sqrt[x], x, 2, Sqrt[2*Pi]*FresnelC[Sqrt[2/Pi]*Sqrt[x]]}
{Sqrt[x]*Cos[x], x, 3, (-Sqrt[Pi/2])*FresnelS[Sqrt[2/Pi]*Sqrt[x]] + Sqrt[x]*Sin[x]}


{Cos[x]^(3/2)/x^3, x, 1, -(Cos[x]^(3/2)/(2*x^2)) + (3/8)*Int[1/(x*Sqrt[Cos[x]]), x] - (9/8)*Int[Cos[x]^(3/2)/x, x] + (3*Sqrt[Cos[x]]*Sin[x])/(4*x)}


(* ::Subsection::Closed:: *)
(*(a Cos[a+b x]^n)^m*)


(* Integrands of the form (a*Cos[x]^2)^m where m is a half-integer *)
{(a*Cos[x]^2)^(5/2),x, 3, a^2*Sqrt[a*Cos[x]^2]*Tan[x] - (2/3)*a^2*Sqrt[a*Cos[x]^2]*Sin[x]^2*Tan[x] + (1/5)*a^2*Sqrt[a*Cos[x]^2]*Sin[x]^4*Tan[x]}
{(a*Cos[x]^2)^(3/2),x, 3, a*Sqrt[a*Cos[x]^2]*Tan[x] - (1/3)*a*Sqrt[a*Cos[x]^2]*Sin[x]^2*Tan[x]}
{(a*Cos[x]^2)^(1/2), x, 2, Sqrt[a*Cos[x]^2]*Tan[x]}
{1/(a*Cos[x]^2)^(1/2), x, 2, (ArcTanh[Sin[x]]*Cos[x])/Sqrt[a*Cos[x]^2]}
{1/(a*Cos[x]^2)^(3/2), x, 3, (ArcTanh[Sin[x]]*Cos[x])/(2*a*Sqrt[a*Cos[x]^2]) + Tan[x]/(2*a*Sqrt[a*Cos[x]^2])}
{1/(a*Cos[x]^2)^(5/2), x, 4, (3*ArcTanh[Sin[x]]*Cos[x])/(8*a^2*Sqrt[a*Cos[x]^2]) + (3*Tan[x])/(8*a^2*Sqrt[a*Cos[x]^2]) + (Sec[x]^2*Tan[x])/(4*a^2*Sqrt[a*Cos[x]^2])}


(* Integrands of the form (a*Cos[x]^4)^m where m is a half-integer *)
{(a*Cos[x]^3)^(5/2),x, 6, (2*a^2*Sqrt[a*Cos[x]^3]*(195*EllipticF[x/2, 2] + 195*Sqrt[Cos[x]]*Sin[x] + 117*Cos[x]^(5/2)*Sin[x] + 91*Cos[x]^(9/2)*Sin[x] + 77*Cos[x]^(13/2)*Sin[x]))/(1155*Cos[x]^(3/2))}
{(a*Cos[x]^3)^(3/2),x, 4, (2*a*Sqrt[a*Cos[x]^3]*(21*EllipticE[x/2, 2] + 7*Cos[x]^(3/2)*Sin[x] + 5*Cos[x]^(7/2)*Sin[x]))/(45*Cos[x]^(3/2))}
{(a*Cos[x]^3)^(1/2), x, 3, (2*Sqrt[a*Cos[x]^3]*(EllipticF[x/2, 2] + Sqrt[Cos[x]]*Sin[x]))/(3*Cos[x]^(3/2))}
{1/(a*Cos[x]^3)^(1/2), x, 3, -((2*Cos[x]*(Sqrt[Cos[x]]*EllipticE[x/2, 2] - Sin[x]))/Sqrt[a*Cos[x]^3])}
{1/(a*Cos[x]^3)^(3/2),x, 4, (2*Sec[x]^2*(3*Sin[x] + 5*Cos[x]^2*(Cos[x]^(3/2)*EllipticF[x/2, 2] + Sin[x])))/(21*a*Sqrt[a*Cos[x]^3])}
{1/(a*Cos[x]^3)^(5/2),x, 6, -((2*Sec[x]^5*(11*Cos[x]^2*(7*Cos[x]^2*(3*Cos[x]^2*(Sqrt[Cos[x]]*EllipticE[x/2, 2] - Sin[x]) - Sin[x]) - 5*Sin[x]) - 45*Sin[x]))/(585*a^2*Sqrt[a*Cos[x]^3]))}


(* Integrands of the form (a*Cos[x]^4)^m where m is a half-integer *)
{(a*Cos[x]^4)^(5/2),x, 6, (63/256)*a^2*x*Sqrt[a*Cos[x]^4]*Sec[x]^2 + (21/128)*a^2*Cos[x]*Sqrt[a*Cos[x]^4]*Sin[x] + (21/160)*a^2*Cos[x]^3*Sqrt[a*Cos[x]^4]*Sin[x] + (9/80)*a^2*Cos[x]^5*Sqrt[a*Cos[x]^4]*Sin[x] + (1/10)*a^2*Cos[x]^7*Sqrt[a*Cos[x]^4]*Sin[x] + (63/256)*a^2*Sqrt[a*Cos[x]^4]*Tan[x]}
{(a*Cos[x]^4)^(3/2),x, 4, (5/16)*a*x*Sqrt[a*Cos[x]^4]*Sec[x]^2 + (5/24)*a*Cos[x]*Sqrt[a*Cos[x]^4]*Sin[x] + (1/6)*a*Cos[x]^3*Sqrt[a*Cos[x]^4]*Sin[x] + (5/16)*a*Sqrt[a*Cos[x]^4]*Tan[x]}
{(a*Cos[x]^4)^(1/2), x, 2, (1/2)*x*Sqrt[a*Cos[x]^4]*Sec[x]^2 + (1/2)*Sqrt[a*Cos[x]^4]*Tan[x]}
{1/(a*Cos[x]^4)^(1/2), x, 2, (Cos[x]*Sin[x])/Sqrt[a*Cos[x]^4]}
{1/(a*Cos[x]^4)^(3/2),x, 4, (Cos[x]*Sin[x])/(a*Sqrt[a*Cos[x]^4]) + (2*Sin[x]^2*Tan[x])/(3*a*Sqrt[a*Cos[x]^4]) + (Sin[x]^2*Tan[x]^3)/(5*a*Sqrt[a*Cos[x]^4])}
{1/(a*Cos[x]^4)^(5/2),x, 4, (Cos[x]*Sin[x])/(a^2*Sqrt[a*Cos[x]^4]) + (4*Sin[x]^2*Tan[x])/(3*a^2*Sqrt[a*Cos[x]^4]) + (6*Sin[x]^2*Tan[x]^3)/(5*a^2*Sqrt[a*Cos[x]^4]) + (4*Sin[x]^2*Tan[x]^5)/(7*a^2*Sqrt[a*Cos[x]^4]) + (Sin[x]^2*Tan[x]^7)/(9*a^2*Sqrt[a*Cos[x]^4])}


(* ::Subsection::Closed:: *)
(*x^m (a+b Cos[c+d x])^n*)


(* Integrands of the form x^m/(a+b*Cos[x]) where m is an integer *)
{1/(x*(a + b*Cos[x])), x, 0, Int[1/(x*(a + b*Cos[x])), x]}
{x/(a + b*Cos[c + d*x]), x, 8, -((I*x*Log[1 + (b*E^(I*c + I*d*x))/(a - Sqrt[a^2 - b^2])])/(Sqrt[a^2 - b^2]*d)) + (I*x*Log[1 + (b*E^(I*c + I*d*x))/(a + Sqrt[a^2 - b^2])])/(Sqrt[a^2 - b^2]*d) - PolyLog[2, -((b*E^(I*c + I*d*x))/(a - Sqrt[a^2 - b^2]))]/(Sqrt[a^2 - b^2]*d^2) + PolyLog[2, -((b*E^(I*c + I*d*x))/(a + Sqrt[a^2 - b^2]))]/(Sqrt[a^2 - b^2]*d^2)}
{x^2/(a + b*Cos[c + d*x]), x, 10, -((I*x^2*Log[1 + (b*E^(I*c + I*d*x))/(a - Sqrt[a^2 - b^2])])/(Sqrt[a^2 - b^2]*d)) + (I*x^2*Log[1 + (b*E^(I*c + I*d*x))/(a + Sqrt[a^2 - b^2])])/(Sqrt[a^2 - b^2]*d) - (2*x*PolyLog[2, -((b*E^(I*c + I*d*x))/(a - Sqrt[a^2 - b^2]))])/(Sqrt[a^2 - b^2]*d^2) + (2*x*PolyLog[2, -((b*E^(I*c + I*d*x))/(a + Sqrt[a^2 - b^2]))])/(Sqrt[a^2 - b^2]*d^2) - (2*I*PolyLog[3, -((b*E^(I*c + I*d*x))/(a - Sqrt[a^2 - b^2]))])/(Sqrt[a^2 - b^2]*d^3) + (2*I*PolyLog[3, -((b*E^(I*c + I*d*x))/(a + Sqrt[a^2 - b^2]))])/(Sqrt[a^2 - b^2]*d^3)}
{x^3/(a + b*Cos[x]), x, 12, -((I*x^3*Log[1 + (b*E^(I*x))/(a - Sqrt[a^2 - b^2])])/Sqrt[a^2 - b^2]) + (I*x^3*Log[1 + (b*E^(I*x))/(a + Sqrt[a^2 - b^2])])/Sqrt[a^2 - b^2] - (3*x^2*PolyLog[2, -((b*E^(I*x))/(a - Sqrt[a^2 - b^2]))])/Sqrt[a^2 - b^2] + (3*x^2*PolyLog[2, -((b*E^(I*x))/(a + Sqrt[a^2 - b^2]))])/Sqrt[a^2 - b^2] - (6*I*x*PolyLog[3, -((b*E^(I*x))/(a - Sqrt[a^2 - b^2]))])/Sqrt[a^2 - b^2] + (6*I*x*PolyLog[3, -((b*E^(I*x))/(a + Sqrt[a^2 - b^2]))])/Sqrt[a^2 - b^2] + (6*PolyLog[4, -((b*E^(I*x))/(a - Sqrt[a^2 - b^2]))])/Sqrt[a^2 - b^2] - (6*PolyLog[4, -((b*E^(I*x))/(a + Sqrt[a^2 - b^2]))])/Sqrt[a^2 - b^2]}
(* {x^3/(a + b*Cos[c + d*x]), x, 12, -((I*x^3*Log[1 + (b*E^(I*c + I*d*x))/(a - Sqrt[a^2 - b^2])])/(Sqrt[a^2 - b^2]*d)) + (I*x^3*Log[1 + (b*E^(I*c + I*d*x))/(a + Sqrt[a^2 - b^2])])/(Sqrt[a^2 - b^2]*d) - (3*x^2*PolyLog[2, -((b*E^(I*c + I*d*x))/(a - Sqrt[a^2 - b^2]))])/(Sqrt[a^2 - b^2]*d^2) + (3*x^2*PolyLog[2, -((b*E^(I*c + I*d*x))/(a + Sqrt[a^2 - b^2]))])/(Sqrt[a^2 - b^2]*d^2) - (6*I*x*PolyLog[3, -((b*E^(I*c + I*d*x))/(a - Sqrt[a^2 - b^2]))])/(Sqrt[a^2 - b^2]*d^3) + (6*I*x*PolyLog[3, -((b*E^(I*c + I*d*x))/(a + Sqrt[a^2 - b^2]))])/(Sqrt[a^2 - b^2]*d^3) + (6*PolyLog[4, -((b*E^(I*c + I*d*x))/(a - Sqrt[a^2 - b^2]))])/(Sqrt[a^2 - b^2]*d^4) - (6*PolyLog[4, -((b*E^(I*c + I*d*x))/(a + Sqrt[a^2 - b^2]))])/(Sqrt[a^2 - b^2]*d^4)} *)

{1/(x*(a + a*Cos[x])), x, 1, Int[Sec[x/2]^2/x, x]/(2*a)}
{x/(a + a*Cos[x]), x, 3, (2*Log[Cos[x/2]])/a + (x*Tan[x/2])/a}
{x^2/(a + a*Cos[x]), x, 6, -((I*x^2)/a) + (4*x*Log[1 + E^(I*x)])/a - (4*I*PolyLog[2, -E^(I*x)])/a + (x^2*Tan[x/2])/a}
{x^3/(a + a*Cos[x]), x, 7, -((I*x^3)/a) + (6*x^2*Log[1 + E^(I*x)])/a - (12*I*x*PolyLog[2, -E^(I*x)])/a + (12*PolyLog[3, -E^(I*x)])/a + (x^3*Tan[x/2])/a}

{1/(x*(a - a*Cos[x])), x, 1, Int[Csc[x/2]^2/x, x]/(2*a)}
{x/(a - a*Cos[x]), x, 3, -((x*Cot[x/2])/a) + (2*Log[Sin[x/2]])/a}
{x^2/(a - a*Cos[x]), x, 6, -((I*x^2)/a) - (x^2*Cot[x/2])/a + (4*x*Log[1 - E^(I*x)])/a - (4*I*PolyLog[2, E^(I*x)])/a}
{x^3/(a - a*Cos[x]), x, 7, -((I*x^3)/a) - (x^3*Cot[x/2])/a + (6*x^2*Log[1 - E^(I*x)])/a - (12*I*x*PolyLog[2, E^(I*x)])/a + (12*PolyLog[3, E^(I*x)])/a}


{x/(a + b*Cos[c + d*x])^2, x, 12, -((I*a*x*Log[1 + (b*E^(I*c + I*d*x))/(a - Sqrt[a^2 - b^2])])/((a^2 - b^2)^(3/2)*d)) + (I*a*x*Log[1 + (b*E^(I*c + I*d*x))/(a + Sqrt[a^2 - b^2])])/((a^2 - b^2)^(3/2)*d) - Log[a + b*Cos[c + d*x]]/((a^2 - b^2)*d^2) - (a*PolyLog[2, -((b*E^(I*c + I*d*x))/(a - Sqrt[a^2 - b^2]))])/((a^2 - b^2)^(3/2)*d^2) + (a*PolyLog[2, -((b*E^(I*c + I*d*x))/(a + Sqrt[a^2 - b^2]))])/((a^2 - b^2)^(3/2)*d^2) - (b*x*Sin[c + d*x])/((a^2 - b^2)*d*(a + b*Cos[c + d*x]))}
{(e + f*x)/(a + b*Cos[c + d*x])^2, x, 17, (2*a*e*ArcTan[((a - b)*Tan[(1/2)*(c + d*x)])/Sqrt[a^2 - b^2]])/((a^2 - b^2)^(3/2)*d) - (I*a*f*x*Log[1 + (b*E^(I*c + I*d*x))/(a - Sqrt[a^2 - b^2])])/((a^2 - b^2)^(3/2)*d) + (I*a*f*x*Log[1 + (b*E^(I*c + I*d*x))/(a + Sqrt[a^2 - b^2])])/((a^2 - b^2)^(3/2)*d) - (f*Log[a + b*Cos[c + d*x]])/((a^2 - b^2)*d^2) - (a*f*PolyLog[2, -((b*E^(I*c + I*d*x))/(a - Sqrt[a^2 - b^2]))])/((a^2 - b^2)^(3/2)*d^2) + (a*f*PolyLog[2, -((b*E^(I*c + I*d*x))/(a + Sqrt[a^2 - b^2]))])/((a^2 - b^2)^(3/2)*d^2) - (b*e*Sin[c + d*x])/((a^2 - b^2)*d*(a + b*Cos[c + d*x])) - (b*f*x*Sin[c + d*x])/((a^2 - b^2)*d*(a + b*Cos[c + d*x]))}


(* Integrands of the form x^m*(a+a*Cos[x])^n where m is an integer and n is a half-integer *)
{x^3*Sqrt[a + a*Cos[x]], x, 5, -96*Sqrt[a + a*Cos[x]] + 12*x^2*Sqrt[a + a*Cos[x]] - 48*x*Sqrt[a + a*Cos[x]]*Tan[x/2] + 2*x^3*Sqrt[a + a*Cos[x]]*Tan[x/2]}
{x^2*Sqrt[a + a*Cos[x]], x, 4, 8*x*Sqrt[a + a*Cos[x]] - 16*Sqrt[a + a*Cos[x]]*Tan[x/2] + 2*x^2*Sqrt[a + a*Cos[x]]*Tan[x/2]}
{x*Sqrt[a + a*Cos[x]], x, 3, 4*Sqrt[a + a*Cos[x]] + 2*x*Sqrt[a + a*Cos[x]]*Tan[x/2]}
{Sqrt[a + a*Cos[x]], x, 1, (2*a*Sin[x])/Sqrt[a + a*Cos[x]]}
{Sqrt[a + a*Cos[x]]/x, x, 2, Sqrt[a + a*Cos[x]]*CosIntegral[x/2]*Sec[x/2]}
{Sqrt[a + a*Cos[x]]/x^2, x, 3, -(Sqrt[a + a*Cos[x]]/x) - (1/2)*Sqrt[a + a*Cos[x]]*Sec[x/2]*SinIntegral[x/2]}
{Sqrt[a + a*Cos[x]]/x^3, x, 4, -(Sqrt[a + a*Cos[x]]/(2*x^2)) - (1/8)*Sqrt[a + a*Cos[x]]*CosIntegral[x/2]*Sec[x/2] + (Sqrt[a + a*Cos[x]]*Tan[x/2])/(4*x)}

{x^3*(a + a*Cos[x])^(3/2), x, 9, (-(1280/9))*a*Sqrt[a + a*Cos[x]] + 16*a*x^2*Sqrt[a + a*Cos[x]] - (64/27)*a*Cos[x/2]^2*Sqrt[a + a*Cos[x]] + (8/3)*a*x^2*Cos[x/2]^2*Sqrt[a + a*Cos[x]] - (32/9)*a*x*Cos[x/2]*Sqrt[a + a*Cos[x]]*Sin[x/2] + (4/3)*a*x^3*Cos[x/2]*Sqrt[a + a*Cos[x]]*Sin[x/2] - (640/9)*a*x*Sqrt[a + a*Cos[x]]*Tan[x/2] + (8/3)*a*x^3*Sqrt[a + a*Cos[x]]*Tan[x/2]}
{x^2*(a + a*Cos[x])^(3/2), x, 7, (32/3)*a*x*Sqrt[a + a*Cos[x]] + (16/9)*a*x*Cos[x/2]^2*Sqrt[a + a*Cos[x]] + (4/3)*a*x^2*Cos[x/2]*Sqrt[a + a*Cos[x]]*Sin[x/2] - (224/9)*a*Sqrt[a + a*Cos[x]]*Tan[x/2] + (8/3)*a*x^2*Sqrt[a + a*Cos[x]]*Tan[x/2] + (32/27)*a*Sqrt[a + a*Cos[x]]*Sin[x/2]^2*Tan[x/2]}
{x*(a + a*Cos[x])^(3/2), x, 4, (16/3)*a*Sqrt[a + a*Cos[x]] + (8/9)*a*Cos[x/2]^2*Sqrt[a + a*Cos[x]] + (4/3)*a*x*Cos[x/2]*Sqrt[a + a*Cos[x]]*Sin[x/2] + (8/3)*a*x*Sqrt[a + a*Cos[x]]*Tan[x/2]}
{(a + a*Cos[x])^(3/2)/x, x, 5, (3/2)*a*Sqrt[a + a*Cos[x]]*CosIntegral[x/2]*Sec[x/2] + (1/2)*a*Sqrt[a + a*Cos[x]]*CosIntegral[(3*x)/2]*Sec[x/2]}
{(a + a*Cos[x])^(3/2)/x^2, x, 7, -((3*a*Sqrt[a + a*Cos[x]])/(2*x)) - (a*Sqrt[a + a*Cos[x]]*Cos[(3*x)/2]*Sec[x/2])/(2*x) - (3/4)*a*Sqrt[a + a*Cos[x]]*Sec[x/2]*SinIntegral[x/2] - (3/4)*a*Sqrt[a + a*Cos[x]]*Sec[x/2]*SinIntegral[(3*x)/2]}
{(a + a*Cos[x])^(3/2)/x^3, x, 7, -((a*Cos[x/2]^2*Sqrt[a + a*Cos[x]])/x^2) - (3/16)*a*Sqrt[a + a*Cos[x]]*CosIntegral[x/2]*Sec[x/2] - (9/16)*a*Sqrt[a + a*Cos[x]]*CosIntegral[(3*x)/2]*Sec[x/2] + (3*a*Cos[x/2]*Sqrt[a + a*Cos[x]]*Sin[x/2])/(2*x)}

{x^3/Sqrt[a + a*Cos[x]], x, 9, -((2*I*x^3*ArcTan[E^((I*x)/2)]*Sqrt[a + a*Cos[x]]*Sec[x/2])/a) + (6*I*x^2*Sqrt[a + a*Cos[x]]*PolyLog[2, (-I)*E^((I*x)/2)]*Sec[x/2])/a - (6*I*x^2*Sqrt[a + a*Cos[x]]*PolyLog[2, I*E^((I*x)/2)]*Sec[x/2])/a - (24*x*Sqrt[a + a*Cos[x]]*PolyLog[3, (-I)*E^((I*x)/2)]*Sec[x/2])/a + (24*x*Sqrt[a + a*Cos[x]]*PolyLog[3, I*E^((I*x)/2)]*Sec[x/2])/a - (48*I*Sqrt[a + a*Cos[x]]*PolyLog[4, (-I)*E^((I*x)/2)]*Sec[x/2])/a + (48*I*Sqrt[a + a*Cos[x]]*PolyLog[4, I*E^((I*x)/2)]*Sec[x/2])/a}
{x^2/Sqrt[a + a*Cos[x]], x, 7, -((2*I*x^2*ArcTan[E^((I*x)/2)]*Sqrt[a + a*Cos[x]]*Sec[x/2])/a) + (4*I*x*Sqrt[a + a*Cos[x]]*PolyLog[2, (-I)*E^((I*x)/2)]*Sec[x/2])/a - (4*I*x*Sqrt[a + a*Cos[x]]*PolyLog[2, I*E^((I*x)/2)]*Sec[x/2])/a - (8*Sqrt[a + a*Cos[x]]*PolyLog[3, (-I)*E^((I*x)/2)]*Sec[x/2])/a + (8*Sqrt[a + a*Cos[x]]*PolyLog[3, I*E^((I*x)/2)]*Sec[x/2])/a}
{x/Sqrt[a + a*Cos[x]], x, 5, -((2*I*x*ArcTan[E^((I*x)/2)]*Sqrt[a + a*Cos[x]]*Sec[x/2])/a) + (2*I*Sqrt[a + a*Cos[x]]*PolyLog[2, (-I)*E^((I*x)/2)]*Sec[x/2])/a - (2*I*Sqrt[a + a*Cos[x]]*PolyLog[2, I*E^((I*x)/2)]*Sec[x/2])/a}
{1/Sqrt[a + a*Cos[x]], x, 1, (2*ArcTanh[Sin[x/2]]*Cos[x/2])/Sqrt[a + a*Cos[x]]}
{1/(x*Sqrt[a + a*Cos[x]]), x, 1, (Sqrt[a + a*Cos[x]]*Int[Sec[x/2]/x, x]*Sec[x/2])/(2*a)}

{x^3/(a + a*Cos[x])^(3/2), x, 14, -((12*I*x*ArcTan[E^((I*x)/2)]*Sqrt[a + a*Cos[x]]*Sec[x/2])/a^2) - (I*x^3*ArcTan[E^((I*x)/2)]*Sqrt[a + a*Cos[x]]*Sec[x/2])/(2*a^2) + (3*I*(8 + x^2)*Sqrt[a*(1 + Cos[x])]*PolyLog[2, (-I)*E^((I*x)/2)]*Sec[x/2])/(2*a^2) - (3*I*(8 + x^2)*Sqrt[a*(1 + Cos[x])]*PolyLog[2, I*E^((I*x)/2)]*Sec[x/2])/(2*a^2) - (6*x*Sqrt[a + a*Cos[x]]*PolyLog[3, (-I)*E^((I*x)/2)]*Sec[x/2])/a^2 + (6*x*Sqrt[a + a*Cos[x]]*PolyLog[3, I*E^((I*x)/2)]*Sec[x/2])/a^2 - (12*I*Sqrt[a + a*Cos[x]]*PolyLog[4, (-I)*E^((I*x)/2)]*Sec[x/2])/a^2 + (12*I*Sqrt[a + a*Cos[x]]*PolyLog[4, I*E^((I*x)/2)]*Sec[x/2])/a^2 - (3*x^2*Sqrt[a + a*Cos[x]]*Sec[x/2]^2)/(2*a^2) + (x^3*Sqrt[a + a*Cos[x]]*Sec[x/2]^2*Tan[x/2])/(4*a^2)}
{x^2/(a + a*Cos[x])^(3/2), x, 9, -((I*x^2*ArcTan[E^((I*x)/2)]*Sqrt[a + a*Cos[x]]*Sec[x/2])/(2*a^2)) + (2*ArcTanh[Sin[x/2]]*Sqrt[a + a*Cos[x]]*Sec[x/2])/a^2 + (I*x*Sqrt[a + a*Cos[x]]*PolyLog[2, (-I)*E^((I*x)/2)]*Sec[x/2])/a^2 - (I*x*Sqrt[a + a*Cos[x]]*PolyLog[2, I*E^((I*x)/2)]*Sec[x/2])/a^2 - (2*Sqrt[a + a*Cos[x]]*PolyLog[3, (-I)*E^((I*x)/2)]*Sec[x/2])/a^2 + (2*Sqrt[a + a*Cos[x]]*PolyLog[3, I*E^((I*x)/2)]*Sec[x/2])/a^2 - (x*Sqrt[a + a*Cos[x]]*Sec[x/2]^2)/a^2 + (x^2*Sqrt[a + a*Cos[x]]*Sec[x/2]^2*Tan[x/2])/(4*a^2)}
{x/(a + a*Cos[x])^(3/2), x, 6, -((I*x*ArcTan[E^((I*x)/2)]*Sqrt[a + a*Cos[x]]*Sec[x/2])/(2*a^2)) + (I*Sqrt[a + a*Cos[x]]*PolyLog[2, (-I)*E^((I*x)/2)]*Sec[x/2])/(2*a^2) - (I*Sqrt[a + a*Cos[x]]*PolyLog[2, I*E^((I*x)/2)]*Sec[x/2])/(2*a^2) - (Sqrt[a + a*Cos[x]]*Sec[x/2]^2)/(2*a^2) + (x*Sqrt[a + a*Cos[x]]*Sec[x/2]^2*Tan[x/2])/(4*a^2)}
{1/(x*(a + a*Cos[x])^(3/2)), x, 1, (Sqrt[a + a*Cos[x]]*Int[Sec[x/2]^3/x, x]*Sec[x/2])/(4*a^2)}


(* Integrands of the form x^m*(a-a*Cos[x])^n where m is an integer and n is a half-integer *)
{x^3*Sqrt[a - a*Cos[x]], x, 5, -96*Sqrt[a - a*Cos[x]] + 12*x^2*Sqrt[a - a*Cos[x]] + 48*x*Sqrt[a - a*Cos[x]]*Cot[x/2] - 2*x^3*Sqrt[a - a*Cos[x]]*Cot[x/2]}
{x^2*Sqrt[a - a*Cos[x]], x, 4, 8*x*Sqrt[a - a*Cos[x]] + 16*Sqrt[a - a*Cos[x]]*Cot[x/2] - 2*x^2*Sqrt[a - a*Cos[x]]*Cot[x/2]}
{x*Sqrt[a - a*Cos[x]], x, 3, 4*Sqrt[a - a*Cos[x]] - 2*x*Sqrt[a - a*Cos[x]]*Cot[x/2]}
{Sqrt[a - a*Cos[x]], x, 1, -((2*a*Sin[x])/Sqrt[a - a*Cos[x]])}
{Sqrt[a - a*Cos[x]]/x, x, 2, Sqrt[a - a*Cos[x]]*Csc[x/2]*SinIntegral[x/2]}
{Sqrt[a - a*Cos[x]]/x^2, x, 3, -(Sqrt[a - a*Cos[x]]/x) + (1/2)*Sqrt[a - a*Cos[x]]*CosIntegral[x/2]*Csc[x/2]}
{Sqrt[a - a*Cos[x]]/x^3, x, 4, -(Sqrt[a - a*Cos[x]]/(2*x^2)) - (Sqrt[a - a*Cos[x]]*Cot[x/2])/(4*x) - (1/8)*Sqrt[a - a*Cos[x]]*Csc[x/2]*SinIntegral[x/2]}

{x^3/Sqrt[a - a*Cos[x]], x, 9, -((2*x^3*ArcTanh[E^((I*x)/2)]*Sqrt[a - a*Cos[x]]*Csc[x/2])/a) + (6*I*x^2*Sqrt[a - a*Cos[x]]*Csc[x/2]*PolyLog[2, -E^((I*x)/2)])/a - (6*I*x^2*Sqrt[a - a*Cos[x]]*Csc[x/2]*PolyLog[2, E^((I*x)/2)])/a - (24*x*Sqrt[a - a*Cos[x]]*Csc[x/2]*PolyLog[3, -E^((I*x)/2)])/a + (24*x*Sqrt[a - a*Cos[x]]*Csc[x/2]*PolyLog[3, E^((I*x)/2)])/a - (48*I*Sqrt[a - a*Cos[x]]*Csc[x/2]*PolyLog[4, -E^((I*x)/2)])/a + (48*I*Sqrt[a - a*Cos[x]]*Csc[x/2]*PolyLog[4, E^((I*x)/2)])/a}
{x^2/Sqrt[a - a*Cos[x]], x, 7, -((2*x^2*ArcTanh[E^((I*x)/2)]*Sqrt[a - a*Cos[x]]*Csc[x/2])/a) + (4*I*x*Sqrt[a - a*Cos[x]]*Csc[x/2]*PolyLog[2, -E^((I*x)/2)])/a - (4*I*x*Sqrt[a - a*Cos[x]]*Csc[x/2]*PolyLog[2, E^((I*x)/2)])/a - (8*Sqrt[a - a*Cos[x]]*Csc[x/2]*PolyLog[3, -E^((I*x)/2)])/a + (8*Sqrt[a - a*Cos[x]]*Csc[x/2]*PolyLog[3, E^((I*x)/2)])/a}
{x/Sqrt[a - a*Cos[x]], x, 5, -((2*x*ArcTanh[E^((I*x)/2)]*Sqrt[a - a*Cos[x]]*Csc[x/2])/a) + (2*I*Sqrt[a - a*Cos[x]]*Csc[x/2]*PolyLog[2, -E^((I*x)/2)])/a - (2*I*Sqrt[a - a*Cos[x]]*Csc[x/2]*PolyLog[2, E^((I*x)/2)])/a}
{1/Sqrt[a - a*Cos[x]], x, 1, -((2*ArcTanh[Cos[x/2]]*Sin[x/2])/Sqrt[a - a*Cos[x]])}
{1/(x*Sqrt[a - a*Cos[x]]), x, 1, (Sqrt[a - a*Cos[x]]*Csc[x/2]*Int[Csc[x/2]/x, x])/(2*a)}


(* Integrands of the form x^m*(a+a*Cos[c+d*x])^n where m is an integer and n is a half-integer *)
{x^3*Sqrt[a + a*Cos[c + d*x]], x, 5, -((96*Sqrt[a + a*Cos[c + d*x]])/d^4) + (12*x^2*Sqrt[a + a*Cos[c + d*x]])/d^2 - (48*x*Sqrt[a + a*Cos[c + d*x]]*Tan[c/2 + (d*x)/2])/d^3 + (2*x^3*Sqrt[a + a*Cos[c + d*x]]*Tan[c/2 + (d*x)/2])/d}
{x^2*Sqrt[a + a*Cos[c + d*x]], x, 4, (8*x*Sqrt[a + a*Cos[c + d*x]])/d^2 - (16*Sqrt[a + a*Cos[c + d*x]]*Tan[c/2 + (d*x)/2])/d^3 + (2*x^2*Sqrt[a + a*Cos[c + d*x]]*Tan[c/2 + (d*x)/2])/d}
{x*Sqrt[a + a*Cos[c + d*x]], x, 3, (4*Sqrt[a + a*Cos[c + d*x]])/d^2 + (2*x*Sqrt[a + a*Cos[c + d*x]]*Tan[c/2 + (d*x)/2])/d}
{Sqrt[a + a*Cos[c + d*x]], x, 1, (2*a*Sin[c + d*x])/(d*Sqrt[a + a*Cos[c + d*x]])}
{Sqrt[a + a*Cos[c + d*x]]/x, x, 4, Cos[c/2]*Sqrt[a + a*Cos[c + d*x]]*CosIntegral[(d*x)/2]*Sec[c/2 + (d*x)/2] - Sqrt[a + a*Cos[c + d*x]]*Sec[c/2 + (d*x)/2]*Sin[c/2]*SinIntegral[(d*x)/2]}
{Sqrt[a + a*Cos[c + d*x]]/x^2, x, 5, -(Sqrt[a + a*Cos[c + d*x]]/x) - (1/2)*d*Sqrt[a + a*Cos[c + d*x]]*CosIntegral[(d*x)/2]*Sec[c/2 + (d*x)/2]*Sin[c/2] - (1/2)*d*Cos[c/2]*Sqrt[a + a*Cos[c + d*x]]*Sec[c/2 + (d*x)/2]*SinIntegral[(d*x)/2]}
{Sqrt[a + a*Cos[c + d*x]]/x^3, x, 6, -(Sqrt[a + a*Cos[c + d*x]]/(2*x^2)) - (1/8)*d^2*Cos[c/2]*Sqrt[a + a*Cos[c + d*x]]*CosIntegral[(d*x)/2]*Sec[c/2 + (d*x)/2] + (1/8)*d^2*Sqrt[a + a*Cos[c + d*x]]*Sec[c/2 + (d*x)/2]*Sin[c/2]*SinIntegral[(d*x)/2] + (d*Sqrt[a + a*Cos[c + d*x]]*Tan[c/2 + (d*x)/2])/(4*x)}

{x^3/Sqrt[a + a*Cos[c + d*x]], x, 9, -((2*I*x^3*ArcTan[E^((I*c)/2 + (I*d*x)/2)]*Sqrt[a + a*Cos[c + d*x]]*Sec[c/2 + (d*x)/2])/(a*d)) + (6*I*x^2*Sqrt[a + a*Cos[c + d*x]]*PolyLog[2, (-I)*E^((I*c)/2 + (I*d*x)/2)]*Sec[c/2 + (d*x)/2])/(a*d^2) - (6*I*x^2*Sqrt[a + a*Cos[c + d*x]]*PolyLog[2, I*E^((I*c)/2 + (I*d*x)/2)]*Sec[c/2 + (d*x)/2])/(a*d^2) - (24*x*Sqrt[a + a*Cos[c + d*x]]*PolyLog[3, (-I)*E^((I*c)/2 + (I*d*x)/2)]*Sec[c/2 + (d*x)/2])/(a*d^3) + (24*x*Sqrt[a + a*Cos[c + d*x]]*PolyLog[3, I*E^((I*c)/2 + (I*d*x)/2)]*Sec[c/2 + (d*x)/2])/(a*d^3) - (48*I*Sqrt[a + a*Cos[c + d*x]]*PolyLog[4, (-I)*E^((I*c)/2 + (I*d*x)/2)]*Sec[c/2 + (d*x)/2])/(a*d^4) + (48*I*Sqrt[a + a*Cos[c + d*x]]*PolyLog[4, I*E^((I*c)/2 + (I*d*x)/2)]*Sec[c/2 + (d*x)/2])/(a*d^4)}
{x^2/Sqrt[a + a*Cos[c + d*x]], x, 7, -((2*I*x^2*ArcTan[E^((I*c)/2 + (I*d*x)/2)]*Sqrt[a + a*Cos[c + d*x]]*Sec[c/2 + (d*x)/2])/(a*d)) + (4*I*x*Sqrt[a + a*Cos[c + d*x]]*PolyLog[2, (-I)*E^((I*c)/2 + (I*d*x)/2)]*Sec[c/2 + (d*x)/2])/(a*d^2) - (4*I*x*Sqrt[a + a*Cos[c + d*x]]*PolyLog[2, I*E^((I*c)/2 + (I*d*x)/2)]*Sec[c/2 + (d*x)/2])/(a*d^2) - (8*Sqrt[a + a*Cos[c + d*x]]*PolyLog[3, (-I)*E^((I*c)/2 + (I*d*x)/2)]*Sec[c/2 + (d*x)/2])/(a*d^3) + (8*Sqrt[a + a*Cos[c + d*x]]*PolyLog[3, I*E^((I*c)/2 + (I*d*x)/2)]*Sec[c/2 + (d*x)/2])/(a*d^3)}
{x/Sqrt[a + a*Cos[c + d*x]], x, 5, -((2*I*x*ArcTan[E^((I*c)/2 + (I*d*x)/2)]*Sqrt[a + a*Cos[c + d*x]]*Sec[c/2 + (d*x)/2])/(a*d)) + (2*I*Sqrt[a + a*Cos[c + d*x]]*PolyLog[2, (-I)*E^((I*c)/2 + (I*d*x)/2)]*Sec[c/2 + (d*x)/2])/(a*d^2) - (2*I*Sqrt[a + a*Cos[c + d*x]]*PolyLog[2, I*E^((I*c)/2 + (I*d*x)/2)]*Sec[c/2 + (d*x)/2])/(a*d^2)}
{1/Sqrt[a + a*Cos[c + d*x]], x, 1, (2*ArcTanh[Sin[(1/2)*(c + d*x)]]*Cos[(1/2)*(c + d*x)])/(d*Sqrt[a + a*Cos[c + d*x]])}
{1/(x*Sqrt[a + a*Cos[c + d*x]]), x, 1, (Sqrt[a + a*Cos[c + d*x]]*Int[Sec[c/2 + (d*x)/2]/x, x]*Sec[c/2 + (d*x)/2])/(2*a)}


(* Used to hang Rubi *)
{(a + a*Cos[c + d*x])^(1/3)/x, x, 0, Int[(a + a*Cos[c + d*x])^(1/3)/x, x]}


(* ::Subsection::Closed:: *)
(*(a+b Cos[c+d x]^2)^n*)


(* Integrands of the form 1/(a+b*Cos[x]^2)^n where n is an integer *)
{1/(a + b*Cos[x]^2), x, 2, ArcTan[(Sqrt[a]*Tan[x])/Sqrt[a + b]]/(Sqrt[a]*Sqrt[a + b])}
{1/(a + b*Cos[x]^2)^2, x, 4, ((2*a + b)*ArcTan[(Sqrt[a]*Tan[x])/Sqrt[a + b]])/(2*a^(3/2)*(a + b)^(3/2)) - (b*Sin[2*x])/(2*a*(a + b)*(2*a + b + b*Cos[2*x]))}
{1/(a + b*Cos[x]^2)^3, x, 5, ((8*a^2 + 8*a*b + 3*b^2)*ArcTan[(Sqrt[a]*Tan[x])/Sqrt[a + b]])/(8*a^(5/2)*(a + b)^(5/2)) - (b*Sin[2*x])/(2*a*(a + b)*(2*a + b + b*Cos[2*x])^2) - (3*b*(2*a + b)*Sin[2*x])/(8*a^2*(a + b)^2*(2*a + b + b*Cos[2*x]))}

{1/(1 + Cos[x]^2), x, 2, ArcTan[Tan[x]/Sqrt[2]]/Sqrt[2]}
{1/(1 + Cos[x]^2)^2, x, 4, (3*x)/(4*Sqrt[2]) - (3*ArcTan[Sin[2*x]/(3 + 2*Sqrt[2] + Cos[2*x])])/(4*Sqrt[2]) - Sin[2*x]/(4*(3 + Cos[2*x]))}
{1/(1 + Cos[x]^2)^3, x, 5, (19*x)/(32*Sqrt[2]) - (19*ArcTan[Sin[2*x]/(3 + 2*Sqrt[2] + Cos[2*x])])/(32*Sqrt[2]) - Sin[2*x]/(4*(3 + Cos[2*x])^2) - (9*Sin[2*x])/(32*(3 + Cos[2*x]))}

{1/(1 - Cos[x]^2), x, 2, -Cot[x]}
{1/(1 - Cos[x]^2)^2, x, 3, -Cot[x] - Cot[x]^3/3}
{1/(1 - Cos[x]^2)^3, x, 3, -Cot[x] - (2*Cot[x]^3)/3 - Cot[x]^5/5}


(* Integrands of the form (a+b*Cos[x]^2)^m where m is a half-integer *)
{Sqrt[1 + Cos[x]^2], x, 2, Sqrt[2]*EllipticE[x, 1/2]}
{Sqrt[1 - Cos[x]^2], x, 3, -(Cot[x]*Sqrt[Sin[x]^2])}
{Sqrt[-1 + Cos[x]^2], x, 3, (-Cot[x])*Sqrt[-Sin[x]^2]}
{Sqrt[-1 - Cos[x]^2], x, 3, -((Sqrt[2]*Sqrt[3 + Cos[2*x]]*EllipticE[x, 1/2])/Sqrt[-3 - Cos[2*x]])}
{Sqrt[a + b*Cos[x]^2], x, 3, ((a + b)*Sqrt[(2*a + b + b*Cos[2*x])/(a + b)]*EllipticE[x, b/(a + b)])/Sqrt[2*a + b + b*Cos[2*x]]}

{1/Sqrt[1 + Cos[x]^2], x, 2, EllipticF[x, 1/2]/Sqrt[2]}
{1/Sqrt[1 - Cos[x]^2], x, 3, -((ArcTanh[Cos[x]]*Sin[x])/Sqrt[Sin[x]^2])}
{1/Sqrt[-1 + Cos[x]^2], x, 3, -((ArcTanh[Cos[x]]*Sin[x])/Sqrt[-Sin[x]^2])}
{1/Sqrt[-1 - Cos[x]^2], x, 3, (Sqrt[3 + Cos[2*x]]*EllipticF[x, 1/2])/(Sqrt[2]*Sqrt[-3 - Cos[2*x]])}
{1/Sqrt[a + b*Cos[x]^2], x, 3, (Sqrt[(2*a + b + b*Cos[2*x])/(a + b)]*EllipticF[x, b/(a + b)])/Sqrt[2*a + b + b*Cos[2*x]]}

{(1 - Cos[x]^2)^(3/2), x, 4, (-Cot[x])*Sqrt[Sin[x]^2] + (1/3)*Cos[x]^2*Cot[x]*Sqrt[Sin[x]^2]}
{(-1 + Cos[x]^2)^(3/2), x, 4, Cot[x]*Sqrt[-Sin[x]^2] - (1/3)*Cos[x]^2*Cot[x]*Sqrt[-Sin[x]^2]}
(* {(1 + Cos[x]^2)^(3/2), x, 0, 0} *)
(* {(-1 - Cos[x]^2)^(3/2), x, 0, 0} *)
(* {(a + b*Cos[x]^2)^(3/2), x, 0, 0} *)


(* ::Subsection::Closed:: *)
(*x^m (a+b Cos[c+d x]^2)^n*)


{x/(a + b*Cos[x]^2), x, 9, -((I*x*Log[1 + (b*E^(2*I*x))/(2*a + b - 2*Sqrt[a]*Sqrt[a + b])])/(2*Sqrt[a]*Sqrt[a + b])) + (I*x*Log[1 + (b*E^(2*I*x))/(2*a + b + 2*Sqrt[a]*Sqrt[a + b])])/(2*Sqrt[a]*Sqrt[a + b]) - PolyLog[2, -((b*E^(2*I*x))/(2*a + b - 2*Sqrt[a]*Sqrt[a + b]))]/(4*Sqrt[a]*Sqrt[a + b]) + PolyLog[2, -((b*E^(2*I*x))/(2*a + b + 2*Sqrt[a]*Sqrt[a + b]))]/(4*Sqrt[a]*Sqrt[a + b])}
{x^2/(a + b*Cos[x]^2), x, 11, -((I*x^2*Log[1 + (b*E^(2*I*x))/(2*a + b - 2*Sqrt[a]*Sqrt[a + b])])/(2*Sqrt[a]*Sqrt[a + b])) + (I*x^2*Log[1 + (b*E^(2*I*x))/(2*a + b + 2*Sqrt[a]*Sqrt[a + b])])/(2*Sqrt[a]*Sqrt[a + b]) - (x*PolyLog[2, -((b*E^(2*I*x))/(2*a + b - 2*Sqrt[a]*Sqrt[a + b]))])/(2*Sqrt[a]*Sqrt[a + b]) + (x*PolyLog[2, -((b*E^(2*I*x))/(2*a + b + 2*Sqrt[a]*Sqrt[a + b]))])/(2*Sqrt[a]*Sqrt[a + b]) - (I*PolyLog[3, -((b*E^(2*I*x))/(2*a + b - 2*Sqrt[a]*Sqrt[a + b]))])/(4*Sqrt[a]*Sqrt[a + b]) + (I*PolyLog[3, -((b*E^(2*I*x))/(2*a + b + 2*Sqrt[a]*Sqrt[a + b]))])/(4*Sqrt[a]*Sqrt[a + b])}
{x^3/(a + b*Cos[x]^2), x, 13, -((I*x^3*Log[1 + (b*E^(2*I*x))/(2*a + b - 2*Sqrt[a]*Sqrt[a + b])])/(2*Sqrt[a]*Sqrt[a + b])) + (I*x^3*Log[1 + (b*E^(2*I*x))/(2*a + b + 2*Sqrt[a]*Sqrt[a + b])])/(2*Sqrt[a]*Sqrt[a + b]) - (3*x^2*PolyLog[2, -((b*E^(2*I*x))/(2*a + b - 2*Sqrt[a]*Sqrt[a + b]))])/(4*Sqrt[a]*Sqrt[a + b]) + (3*x^2*PolyLog[2, -((b*E^(2*I*x))/(2*a + b + 2*Sqrt[a]*Sqrt[a + b]))])/(4*Sqrt[a]*Sqrt[a + b]) - (3*I*x*PolyLog[3, -((b*E^(2*I*x))/(2*a + b - 2*Sqrt[a]*Sqrt[a + b]))])/(4*Sqrt[a]*Sqrt[a + b]) + (3*I*x*PolyLog[3, -((b*E^(2*I*x))/(2*a + b + 2*Sqrt[a]*Sqrt[a + b]))])/(4*Sqrt[a]*Sqrt[a + b]) + (3*PolyLog[4, -((b*E^(2*I*x))/(2*a + b - 2*Sqrt[a]*Sqrt[a + b]))])/(8*Sqrt[a]*Sqrt[a + b]) - (3*PolyLog[4, -((b*E^(2*I*x))/(2*a + b + 2*Sqrt[a]*Sqrt[a + b]))])/(8*Sqrt[a]*Sqrt[a + b])}


{x/(a + b*Cos[c + d*x]^2)^2, x, 13, -((I*(2*a + b)*x*Log[1 + (b*E^(2*I*c + 2*I*d*x))/(2*a + b - 2*Sqrt[a]*Sqrt[a + b])])/(4*a^(3/2)*(a + b)^(3/2)*d)) + (I*(2*a + b)*x*Log[1 + (b*E^(2*I*c + 2*I*d*x))/(2*a + b + 2*Sqrt[a]*Sqrt[a + b])])/(4*a^(3/2)*(a + b)^(3/2)*d) - Log[2*a + b + b*Cos[2*c + 2*d*x]]/(4*a*(a + b)*d^2) - ((2*a + b)*PolyLog[2, -((b*E^(2*I*c + 2*I*d*x))/(2*a + b - 2*Sqrt[a]*Sqrt[a + b]))])/(8*a^(3/2)*(a + b)^(3/2)*d^2) + ((2*a + b)*PolyLog[2, -((b*E^(2*I*c + 2*I*d*x))/(2*a + b + 2*Sqrt[a]*Sqrt[a + b]))])/(8*a^(3/2)*(a + b)^(3/2)*d^2) - (b*x*Sin[2*c + 2*d*x])/(2*a*(a + b)*d*(2*a + b + b*Cos[2*c + 2*d*x]))}


(* ::Subsection::Closed:: *)
(*1 / (a+b Cos[c+d x]^n)		where n>2*)


(* Integrands of the form 1/(a+b*Cos[x]^n) where n is an integer *)
{1/(a + b*Cos[x]^3), x, 7, (2*ArcTan[((a^(1/3) - b^(1/3))*Tan[x/2])/Sqrt[a^(2/3) - b^(2/3)]])/(3*a^(2/3)*Sqrt[a^(2/3) - b^(2/3)]) + (2*ArcTan[((a^(1/3) - (-1)^(2/3)*b^(1/3))*Tan[x/2])/Sqrt[a^(2/3) + (-1)^(1/3)*b^(2/3)]])/(3*a^(2/3)*Sqrt[a^(2/3) + (-1)^(1/3)*b^(2/3)]) + (2*ArcTan[((a^(1/3) + (-1)^(1/3)*b^(1/3))*Tan[x/2])/Sqrt[a^(2/3) - (-1)^(2/3)*b^(2/3)]])/(3*a^(2/3)*Sqrt[a^(2/3) - (-1)^(2/3)*b^(2/3)])}
{1/(a + b*Cos[x]^4), x, 7, -(ArcTan[((-a)^(1/4)*Tan[x])/Sqrt[Sqrt[-a] - Sqrt[b]]]/(2*(-a)^(3/4)*Sqrt[Sqrt[-a] - Sqrt[b]])) - ArcTan[((-a)^(1/4)*Tan[x])/Sqrt[Sqrt[-a] + Sqrt[b]]]/(2*(-a)^(3/4)*Sqrt[Sqrt[-a] + Sqrt[b]])}
{1/(a + b*Cos[x]^5), x, 11, (2*ArcTan[((a^(1/5) - b^(1/5))*Tan[x/2])/Sqrt[a^(2/5) - b^(2/5)]])/(5*a^(4/5)*Sqrt[a^(2/5) - b^(2/5)]) + (2*ArcTan[((a^(1/5) + (-1)^(3/5)*b^(1/5))*Tan[x/2])/Sqrt[a^(2/5) + (-1)^(1/5)*b^(2/5)]])/(5*a^(4/5)*Sqrt[a^(2/5) + (-1)^(1/5)*b^(2/5)]) + (2*ArcTan[((a^(1/5) + (-1)^(1/5)*b^(1/5))*Tan[x/2])/Sqrt[a^(2/5) - (-1)^(2/5)*b^(2/5)]])/(5*a^(4/5)*Sqrt[a^(2/5) - (-1)^(2/5)*b^(2/5)]) + (2*ArcTan[((a^(1/5) - (-1)^(4/5)*b^(1/5))*Tan[x/2])/Sqrt[a^(2/5) + (-1)^(3/5)*b^(2/5)]])/(5*a^(4/5)*Sqrt[a^(2/5) + (-1)^(3/5)*b^(2/5)]) + (2*ArcTan[((a^(1/5) - (-1)^(2/5)*b^(1/5))*Tan[x/2])/Sqrt[a^(2/5) - (-1)^(4/5)*b^(2/5)]])/(5*a^(4/5)*Sqrt[a^(2/5) - (-1)^(4/5)*b^(2/5)])}
{1/(a + b*Cos[x]^6), x, 10, ArcTan[(a^(1/6)*Tan[x])/Sqrt[a^(1/3) + b^(1/3)]]/(3*a^(5/6)*Sqrt[a^(1/3) + b^(1/3)]) + ArcTan[(a^(1/6)*Tan[x])/Sqrt[a^(1/3) - (-1)^(1/3)*b^(1/3)]]/(3*a^(5/6)*Sqrt[a^(1/3) - (-1)^(1/3)*b^(1/3)]) + ArcTan[(a^(1/6)*Tan[x])/Sqrt[a^(1/3) + (-1)^(2/3)*b^(1/3)]]/(3*a^(5/6)*Sqrt[a^(1/3) + (-1)^(2/3)*b^(1/3)])}
{1/(a + b*Cos[x]^8), x, 13, -(ArcTan[((-a)^(1/8)*Tan[x])/Sqrt[(-a)^(1/4) - b^(1/4)]]/(4*(-a)^(7/8)*Sqrt[(-a)^(1/4) - b^(1/4)])) - ArcTan[((-a)^(1/8)*Tan[x])/Sqrt[(-a)^(1/4) - I*b^(1/4)]]/(4*(-a)^(7/8)*Sqrt[(-a)^(1/4) - I*b^(1/4)]) - ArcTan[((-a)^(1/8)*Tan[x])/Sqrt[(-a)^(1/4) + I*b^(1/4)]]/(4*(-a)^(7/8)*Sqrt[(-a)^(1/4) + I*b^(1/4)]) - ArcTan[((-a)^(1/8)*Tan[x])/Sqrt[(-a)^(1/4) + b^(1/4)]]/(4*(-a)^(7/8)*Sqrt[(-a)^(1/4) + b^(1/4)])}

{1/(a - b*Cos[x]^3), x, 7, (2*ArcTan[((a^(1/3) + b^(1/3))*Tan[x/2])/Sqrt[a^(2/3) - b^(2/3)]])/(3*a^(2/3)*Sqrt[a^(2/3) - b^(2/3)]) + (2*ArcTan[((a^(1/3) + (-1)^(2/3)*b^(1/3))*Tan[x/2])/Sqrt[a^(2/3) + (-1)^(1/3)*b^(2/3)]])/(3*a^(2/3)*Sqrt[a^(2/3) + (-1)^(1/3)*b^(2/3)]) + (2*ArcTan[((a^(1/3) - (-1)^(1/3)*b^(1/3))*Tan[x/2])/Sqrt[a^(2/3) - (-1)^(2/3)*b^(2/3)]])/(3*a^(2/3)*Sqrt[a^(2/3) - (-1)^(2/3)*b^(2/3)])}
{1/(a - b*Cos[x]^4), x, 7, ArcTan[(a^(1/4)*Tan[x])/Sqrt[Sqrt[a] - Sqrt[b]]]/(2*a^(3/4)*Sqrt[Sqrt[a] - Sqrt[b]]) + ArcTan[(a^(1/4)*Tan[x])/Sqrt[Sqrt[a] + Sqrt[b]]]/(2*a^(3/4)*Sqrt[Sqrt[a] + Sqrt[b]])}
{1/(a - b*Cos[x]^5), x, 11, (2*ArcTan[((a^(1/5) + b^(1/5))*Tan[x/2])/Sqrt[a^(2/5) - b^(2/5)]])/(5*a^(4/5)*Sqrt[a^(2/5) - b^(2/5)]) + (2*ArcTan[((a^(1/5) - (-1)^(3/5)*b^(1/5))*Tan[x/2])/Sqrt[a^(2/5) + (-1)^(1/5)*b^(2/5)]])/(5*a^(4/5)*Sqrt[a^(2/5) + (-1)^(1/5)*b^(2/5)]) + (2*ArcTan[((a^(1/5) - (-1)^(1/5)*b^(1/5))*Tan[x/2])/Sqrt[a^(2/5) - (-1)^(2/5)*b^(2/5)]])/(5*a^(4/5)*Sqrt[a^(2/5) - (-1)^(2/5)*b^(2/5)]) + (2*ArcTan[((a^(1/5) + (-1)^(4/5)*b^(1/5))*Tan[x/2])/Sqrt[a^(2/5) + (-1)^(3/5)*b^(2/5)]])/(5*a^(4/5)*Sqrt[a^(2/5) + (-1)^(3/5)*b^(2/5)]) + (2*ArcTan[((a^(1/5) + (-1)^(2/5)*b^(1/5))*Tan[x/2])/Sqrt[a^(2/5) - (-1)^(4/5)*b^(2/5)]])/(5*a^(4/5)*Sqrt[a^(2/5) - (-1)^(4/5)*b^(2/5)])}
{1/(a - b*Cos[x]^6), x, 10, ArcTan[(a^(1/6)*Tan[x])/Sqrt[a^(1/3) - b^(1/3)]]/(3*a^(5/6)*Sqrt[a^(1/3) - b^(1/3)]) + ArcTan[(a^(1/6)*Tan[x])/Sqrt[a^(1/3) + (-1)^(1/3)*b^(1/3)]]/(3*a^(5/6)*Sqrt[a^(1/3) + (-1)^(1/3)*b^(1/3)]) + ArcTan[(a^(1/6)*Tan[x])/Sqrt[a^(1/3) - (-1)^(2/3)*b^(1/3)]]/(3*a^(5/6)*Sqrt[a^(1/3) - (-1)^(2/3)*b^(1/3)])}
{1/(a - b*Cos[x]^8), x, 13, ArcTan[(a^(1/8)*Tan[x])/Sqrt[a^(1/4) - b^(1/4)]]/(4*a^(7/8)*Sqrt[a^(1/4) - b^(1/4)]) + ArcTan[(a^(1/8)*Tan[x])/Sqrt[a^(1/4) - I*b^(1/4)]]/(4*a^(7/8)*Sqrt[a^(1/4) - I*b^(1/4)]) + ArcTan[(a^(1/8)*Tan[x])/Sqrt[a^(1/4) + I*b^(1/4)]]/(4*a^(7/8)*Sqrt[a^(1/4) + I*b^(1/4)]) + ArcTan[(a^(1/8)*Tan[x])/Sqrt[a^(1/4) + b^(1/4)]]/(4*a^(7/8)*Sqrt[a^(1/4) + b^(1/4)])}

{1/(1 + Cos[x]^3), x, 5, -((2*ArcTan[(-1)^(2/3)*Sqrt[1 + (-1)^(1/3)]*Tan[x/2]])/(3*Sqrt[1 + (-1)^(1/3)])) + (2*ArcTan[(-1)^(1/3)*Sqrt[1 - (-1)^(2/3)]*Tan[x/2]])/(3*Sqrt[1 - (-1)^(2/3)]) + Sin[x]/(3*(1 + Cos[x]))}
{1/(1 + Cos[x]^4), x, 9, ArcTan[Tan[x]/Sqrt[1 - I]]/(2*Sqrt[1 - I]) + ArcTan[Tan[x]/Sqrt[1 + I]]/(2*Sqrt[1 + I])}
{1/(1 + Cos[x]^5), x, 8, (2*ArcTan[((1 + (-1)^(1/5))*Tan[x/2])/Sqrt[1 - (-1)^(2/5)]])/(5*Sqrt[1 - (-1)^(2/5)]) + (2*ArcTan[((1 + (-1)^(3/5))*Tan[x/2])/Sqrt[1 + (-1)^(1/5)]])/(5*Sqrt[1 + (-1)^(1/5)]) + (2*ArcTan[((1 - (-1)^(2/5))*Tan[x/2])/Sqrt[1 - (-1)^(4/5)]])/(5*Sqrt[1 - (-1)^(4/5)]) + (2*ArcTan[((1 - (-1)^(4/5))*Tan[x/2])/Sqrt[1 + (-1)^(3/5)]])/(5*Sqrt[1 + (-1)^(3/5)]) + Sin[x]/(5*(1 + Cos[x]))}
{1/(1 + Cos[x]^6), x, 8, ArcTan[Tan[x]/Sqrt[2]]/(3*Sqrt[2]) + ArcTan[Tan[x]/Sqrt[1 - (-1)^(1/3)]]/(3*Sqrt[1 - (-1)^(1/3)]) + ArcTan[Tan[x]/Sqrt[1 + (-1)^(2/3)]]/(3*Sqrt[1 + (-1)^(2/3)])}
{1/(1 + Cos[x]^8), x, 11, ArcTan[Tan[x]/Sqrt[1 - (-1)^(1/4)]]/(4*Sqrt[1 - (-1)^(1/4)]) + ArcTan[Tan[x]/Sqrt[1 + (-1)^(1/4)]]/(4*Sqrt[1 + (-1)^(1/4)]) + ArcTan[Tan[x]/Sqrt[1 - (-1)^(3/4)]]/(4*Sqrt[1 - (-1)^(3/4)]) + ArcTan[Tan[x]/Sqrt[1 + (-1)^(3/4)]]/(4*Sqrt[1 + (-1)^(3/4)])}

{1/(1 - Cos[x]^3), x, 5, (2*ArcTan[((1 - (-1)^(1/3))*Tan[x/2])/Sqrt[1 - (-1)^(2/3)]])/(3*Sqrt[1 - (-1)^(2/3)]) + (2*ArcTan[((1 + (-1)^(2/3))*Tan[x/2])/Sqrt[1 + (-1)^(1/3)]])/(3*Sqrt[1 + (-1)^(1/3)]) - Sin[x]/(3*(1 - Cos[x]))}
{1/(1 - Cos[x]^4), x, 5, ArcTan[Tan[x]/Sqrt[2]]/(2*Sqrt[2]) - Cot[x]/2}
{1/(1 - Cos[x]^5), x, 8, (2*ArcTan[((1 - (-1)^(1/5))*Tan[x/2])/Sqrt[1 - (-1)^(2/5)]])/(5*Sqrt[1 - (-1)^(2/5)]) + (2*ArcTan[((1 - (-1)^(3/5))*Tan[x/2])/Sqrt[1 + (-1)^(1/5)]])/(5*Sqrt[1 + (-1)^(1/5)]) + (2*ArcTan[((1 + (-1)^(2/5))*Tan[x/2])/Sqrt[1 - (-1)^(4/5)]])/(5*Sqrt[1 - (-1)^(4/5)]) + (2*ArcTan[((1 + (-1)^(4/5))*Tan[x/2])/Sqrt[1 + (-1)^(3/5)]])/(5*Sqrt[1 + (-1)^(3/5)]) - Sin[x]/(5*(1 - Cos[x]))}
{1/(1 - Cos[x]^6), x, 8, ArcTan[Tan[x]/Sqrt[1 + (-1)^(1/3)]]/(3*Sqrt[1 + (-1)^(1/3)]) + ArcTan[Tan[x]/Sqrt[1 - (-1)^(2/3)]]/(3*Sqrt[1 - (-1)^(2/3)]) - Cot[x]/3}
{1/(1 - Cos[x]^8), x, 13, ArcTan[Tan[x]/Sqrt[1 - I]]/(4*Sqrt[1 - I]) + ArcTan[Tan[x]/Sqrt[1 + I]]/(4*Sqrt[1 + I]) + ArcTan[Tan[x]/Sqrt[2]]/(4*Sqrt[2]) - Cot[x]/4}


(* ::Subsection::Closed:: *)
(*(c+d x)^m Cos[a+b x]^n*)


(* Integrands of the form Cos[a+b*x]^m*(c+d*x)^n where m is an integer and n is a half-integer *)
{Cos[a + b*x]*Sqrt[c + d*x], x, 5, -((Sqrt[d]*Sqrt[Pi/2]*Cos[a - (b*c)/d]*FresnelS[(Sqrt[b]*Sqrt[2/Pi]*Sqrt[c + d*x])/Sqrt[d]])/b^(3/2)) - (Sqrt[d]*Sqrt[Pi/2]*FresnelC[(Sqrt[b]*Sqrt[2/Pi]*Sqrt[c + d*x])/Sqrt[d]]*Sin[a - (b*c)/d])/b^(3/2) + (Sqrt[c + d*x]*Sin[a + b*x])/b}
{Cos[a + b*x]/Sqrt[c + d*x], x, 4, (Sqrt[2*Pi]*Cos[(b*c - a*d)/d]*FresnelC[(Sqrt[b]*Sqrt[2/Pi]*Sqrt[c + d*x])/Sqrt[d]])/(Sqrt[b]*Sqrt[d]) + (Sqrt[2*Pi]*FresnelS[(Sqrt[b]*Sqrt[2/Pi]*Sqrt[c + d*x])/Sqrt[d]]*Sin[(b*c - a*d)/d])/(Sqrt[b]*Sqrt[d])}
{Cos[a + b*x]/(c + d*x)^(3/2), x, 5, -((2*Cos[a + b*x])/(d*Sqrt[c + d*x])) - (2*Sqrt[b]*Sqrt[2*Pi]*Cos[a - (b*c)/d]*FresnelS[(Sqrt[b]*Sqrt[2/Pi]*Sqrt[c + d*x])/Sqrt[d]])/d^(3/2) - (2*Sqrt[b]*Sqrt[2*Pi]*FresnelC[(Sqrt[b]*Sqrt[2/Pi]*Sqrt[c + d*x])/Sqrt[d]]*Sin[a - (b*c)/d])/d^(3/2)}

{Cos[a + b*x]^2*Sqrt[c + d*x], x, 8, (c + d*x)^(3/2)/(3*d) - (Sqrt[d]*Sqrt[Pi]*Cos[2*(a - (b*c)/d)]*FresnelS[(2*Sqrt[b]*Sqrt[c + d*x])/(Sqrt[d]*Sqrt[Pi])])/(8*b^(3/2)) - (Sqrt[d]*Sqrt[Pi]*FresnelC[(2*Sqrt[b]*Sqrt[c + d*x])/(Sqrt[d]*Sqrt[Pi])]*Sin[2*(a - (b*c)/d)])/(8*b^(3/2)) + (Sqrt[c + d*x]*Sin[2*a + 2*b*x])/(4*b)}
{Cos[a + b*x]^2/Sqrt[c + d*x], x, 6, Sqrt[c + d*x]/d + (Sqrt[Pi]*Cos[2*a - (2*b*c)/d]*FresnelC[(2*Sqrt[b]*Sqrt[c + d*x])/(Sqrt[d]*Sqrt[Pi])])/(2*Sqrt[b]*Sqrt[d]) - (Sqrt[Pi]*FresnelS[(2*Sqrt[b]*Sqrt[c + d*x])/(Sqrt[d]*Sqrt[Pi])]*Sin[2*a - (2*b*c)/d])/(2*Sqrt[b]*Sqrt[d])}
{Cos[a + b*x]^2/(c + d*x)^(3/2), x, 6, -((2*Cos[a + b*x]^2)/(d*Sqrt[c + d*x])) - (2*Sqrt[b]*Sqrt[Pi]*Cos[2*(a - (b*c)/d)]*FresnelS[(2*Sqrt[b]*Sqrt[c + d*x])/(Sqrt[d]*Sqrt[Pi])])/d^(3/2) - (2*Sqrt[b]*Sqrt[Pi]*FresnelC[(2*Sqrt[b]*Sqrt[c + d*x])/(Sqrt[d]*Sqrt[Pi])]*Sin[2*(a - (b*c)/d)])/d^(3/2)}


(* ::Subsection::Closed:: *)
(*(d+e x)^m Cos[a+b x+c x^2]^n*)


(* Integrands of the form x^m*Cos[a+b*x+c*x^2] where m is an integer *)
{x^2*Cos[a + b*x + c*x^2], x, 12, -((Sqrt[Pi/2]*FresnelS[(b + 2*c*x)/(Sqrt[c]*Sqrt[2*Pi])]*(2*c*Cos[a - b^2/(4*c)] + b^2*Sin[a - b^2/(4*c)]))/(4*c^(5/2))) + (Sqrt[Pi/2]*FresnelC[(b + 2*c*x)/(Sqrt[c]*Sqrt[2*Pi])]*(b^2*Cos[a - b^2/(4*c)] - 2*c*Sin[a - b^2/(4*c)]))/(4*c^(5/2)) - (b*Sin[a + b*x + c*x^2])/(4*c^2) + (x*Sin[a + b*x + c*x^2])/(2*c)}
{x*Cos[a + b*x + c*x^2], x, 6, -((b*Sqrt[Pi/2]*Cos[(b^2 - 4*a*c)/(4*c)]*FresnelC[(b + 2*c*x)/(Sqrt[c]*Sqrt[2*Pi])])/(2*c^(3/2))) - (b*Sqrt[Pi/2]*FresnelS[(b + 2*c*x)/(Sqrt[c]*Sqrt[2*Pi])]*Sin[(b^2 - 4*a*c)/(4*c)])/(2*c^(3/2)) + Sin[a + b*x + c*x^2]/(2*c)}
{Cos[a + b*x + c*x^2], x, 5, (Sqrt[Pi/2]*Cos[(b^2 - 4*a*c)/(4*c)]*FresnelC[(b + 2*c*x)/(Sqrt[c]*Sqrt[2*Pi])])/Sqrt[c] + (Sqrt[Pi/2]*FresnelS[(b + 2*c*x)/(Sqrt[c]*Sqrt[2*Pi])]*Sin[(b^2 - 4*a*c)/(4*c)])/Sqrt[c]}
{Cos[a + b*x + c*x^2]/x, x, 0, Int[Cos[a + b*x + c*x^2]/x, x]}
{Cos[a + b*x + c*x^2]/x^2 + b*Sin[a + b*x + c*x^2]/x, x, 7, -(Cos[a + b*x + c*x^2]/x) - Sqrt[c]*Sqrt[2*Pi]*Cos[(b^2 - 4*a*c)/(4*c)]*FresnelS[(b + 2*c*x)/(Sqrt[c]*Sqrt[2*Pi])] + Sqrt[c]*Sqrt[2*Pi]*FresnelC[(b + 2*c*x)/(Sqrt[c]*Sqrt[2*Pi])]*Sin[(b^2 - 4*a*c)/(4*c)]}

{x^2*Cos[a + b*x - c*x^2], x, 14, (Sqrt[Pi/2]*FresnelS[(b - 2*c*x)/(Sqrt[c]*Sqrt[2*Pi])]*(2*c*Cos[a + b^2/(4*c)] - b^2*Sin[a + b^2/(4*c)]))/(4*c^(5/2)) - (Sqrt[Pi/2]*FresnelC[(b - 2*c*x)/(Sqrt[c]*Sqrt[2*Pi])]*(b^2*Cos[a + b^2/(4*c)] + 2*c*Sin[a + b^2/(4*c)]))/(4*c^(5/2)) - (b*Sin[a + b*x - c*x^2])/(4*c^2) - (x*Sin[a + b*x - c*x^2])/(2*c)}
{x*Cos[a + b*x - c*x^2], x, 7, -((b*Sqrt[Pi/2]*Cos[(b^2 + 4*a*c)/(4*c)]*FresnelC[(b - 2*c*x)/(Sqrt[c]*Sqrt[2*Pi])])/(2*c^(3/2))) - (b*Sqrt[Pi/2]*FresnelS[(b - 2*c*x)/(Sqrt[c]*Sqrt[2*Pi])]*Sin[(b^2 + 4*a*c)/(4*c)])/(2*c^(3/2)) - Sin[a + b*x - c*x^2]/(2*c)}
{Cos[a + b*x - c*x^2], x, 6, -((Sqrt[Pi/2]*Cos[(b^2 + 4*a*c)/(4*c)]*FresnelC[(b - 2*c*x)/(Sqrt[c]*Sqrt[2*Pi])])/Sqrt[c]) - (Sqrt[Pi/2]*FresnelS[(b - 2*c*x)/(Sqrt[c]*Sqrt[2*Pi])]*Sin[(b^2 + 4*a*c)/(4*c)])/Sqrt[c]}
{Cos[a + b*x - c*x^2]/x, x, 0, Int[Cos[a + b*x - c*x^2]/x, x]}
{Cos[a + b*x - c*x^2]/x^2 + b*Sin[a + b*x - c*x^2]/x, x, 8, -(Cos[a + b*x - c*x^2]/x) + Sqrt[c]*Sqrt[2*Pi]*Cos[(b^2 + 4*a*c)/(4*c)]*FresnelS[(b - 2*c*x)/(Sqrt[c]*Sqrt[2*Pi])] - Sqrt[c]*Sqrt[2*Pi]*FresnelC[(b - 2*c*x)/(Sqrt[c]*Sqrt[2*Pi])]*Sin[(b^2 + 4*a*c)/(4*c)]}

{x^2*Cos[1/4 + x + x^2], x, 8, (1/4)*Sqrt[Pi/2]*FresnelC[(1 + 2*x)/Sqrt[2*Pi]] - (1/2)*Sqrt[Pi/2]*FresnelS[(1 + 2*x)/Sqrt[2*Pi]] - (1/4)*Sin[1/4 + x + x^2] + (1/2)*x*Sin[1/4 + x + x^2]}
{x*Cos[1/4 + x + x^2], x, 4, (-(1/2))*Sqrt[Pi/2]*FresnelC[(1 + 2*x)/Sqrt[2*Pi]] + (1/2)*Sin[1/4 + x + x^2]}
{Cos[1/4 + x + x^2], x, 3, Sqrt[Pi/2]*FresnelC[(1 + 2*x)/Sqrt[2*Pi]]}
{Cos[1/4 + x + x^2]/x, x, 0, Int[Cos[1/4 + x + x^2]/x, x]}
{Cos[1/4 + x + x^2]/x^2, x, 4, -(Cos[1/4 + x + x^2]/x) - Sqrt[2*Pi]*FresnelS[(1 + 2*x)/Sqrt[2*Pi]] - Int[Sin[1/4 + x + x^2]/x, x]}


(* Integrands of the form x^m*Cos[a+b*x+c*x^2]^2 where m is an integer *)
{x^2*Cos[a + b*x + c*x^2]^2, x, 15, x^3/6 - (Sqrt[Pi]*FresnelS[(b + 2*c*x)/(Sqrt[c]*Sqrt[Pi])]*(c*Cos[2*a - b^2/(2*c)] + b^2*Sin[2*a - b^2/(2*c)]))/(16*c^(5/2)) + (Sqrt[Pi]*FresnelC[(b + 2*c*x)/(Sqrt[c]*Sqrt[Pi])]*(b^2*Cos[2*a - b^2/(2*c)] - c*Sin[2*a - b^2/(2*c)]))/(16*c^(5/2)) - (b*Sin[2*a + 2*b*x + 2*c*x^2])/(16*c^2) + (x*Sin[2*a + 2*b*x + 2*c*x^2])/(8*c)}
{x*Cos[a + b*x + c*x^2]^2, x, 9, x^2/4 - (b*Sqrt[Pi]*Cos[(b^2 - 4*a*c)/(2*c)]*FresnelC[(b + 2*c*x)/(Sqrt[c]*Sqrt[Pi])])/(8*c^(3/2)) - (b*Sqrt[Pi]*FresnelS[(b + 2*c*x)/(Sqrt[c]*Sqrt[Pi])]*Sin[(b^2 - 4*a*c)/(2*c)])/(8*c^(3/2)) + Sin[2*a + 2*b*x + 2*c*x^2]/(8*c)}
{Cos[a + b*x + c*x^2]^2, x, 7, x/2 + (Sqrt[Pi]*Cos[(b^2 - 4*a*c)/(2*c)]*FresnelC[(b + 2*c*x)/(Sqrt[c]*Sqrt[Pi])])/(4*Sqrt[c]) + (Sqrt[Pi]*FresnelS[(b + 2*c*x)/(Sqrt[c]*Sqrt[Pi])]*Sin[(b^2 - 4*a*c)/(2*c)])/(4*Sqrt[c])}
{Cos[a + b*x + c*x^2]^2/x, x, 3, (1/2)*Int[Cos[2*a + 2*b*x + 2*c*x^2]/x, x] + Log[x]/2}

{x^2*Cos[a + b*x - c*x^2]^2, x, 17, x^3/6 + (Sqrt[Pi]*FresnelS[(b - 2*c*x)/(Sqrt[c]*Sqrt[Pi])]*(c*Cos[2*a + b^2/(2*c)] - b^2*Sin[2*a + b^2/(2*c)]))/(16*c^(5/2)) - (Sqrt[Pi]*FresnelC[(b - 2*c*x)/(Sqrt[c]*Sqrt[Pi])]*(b^2*Cos[2*a + b^2/(2*c)] + c*Sin[2*a + b^2/(2*c)]))/(16*c^(5/2)) - (b*Sin[2*a + 2*b*x - 2*c*x^2])/(16*c^2) - (x*Sin[2*a + 2*b*x - 2*c*x^2])/(8*c)}
{x*Cos[a + b*x - c*x^2]^2, x, 10, x^2/4 - (b*Sqrt[Pi]*Cos[(b^2 + 4*a*c)/(2*c)]*FresnelC[(b - 2*c*x)/(Sqrt[c]*Sqrt[Pi])])/(8*c^(3/2)) - (b*Sqrt[Pi]*FresnelS[(b - 2*c*x)/(Sqrt[c]*Sqrt[Pi])]*Sin[(b^2 + 4*a*c)/(2*c)])/(8*c^(3/2)) - Sin[2*a + 2*b*x - 2*c*x^2]/(8*c)}
{Cos[a + b*x - c*x^2]^2, x, 8, x/2 - (Sqrt[Pi]*Cos[(b^2 + 4*a*c)/(2*c)]*FresnelC[(b - 2*c*x)/(Sqrt[c]*Sqrt[Pi])])/(4*Sqrt[c]) - (Sqrt[Pi]*FresnelS[(b - 2*c*x)/(Sqrt[c]*Sqrt[Pi])]*Sin[(b^2 + 4*a*c)/(2*c)])/(4*Sqrt[c])}
{Cos[a + b*x - c*x^2]^2/x, x, 3, (1/2)*Int[Cos[2*a + 2*b*x - 2*c*x^2]/x, x] + Log[x]/2}

{x^2*Cos[1/4 + x + x^2]^2, x, 11, x^3/6 + (1/16)*Sqrt[Pi]*FresnelC[(1 + 2*x)/Sqrt[Pi]] - (1/16)*Sqrt[Pi]*FresnelS[(1 + 2*x)/Sqrt[Pi]] - (1/16)*Sin[(1/2)*(1 + 2*x)^2] + (1/8)*x*Sin[(1/2)*(1 + 2*x)^2]}
{x*Cos[1/4 + x + x^2]^2, x, 9, x^2/4 - (1/8)*Sqrt[Pi]*FresnelC[(1 + 2*x)/Sqrt[Pi]] + (1/8)*Sin[(1/2)*(1 + 2*x)^2]}
{Cos[1/4 + x + x^2]^2, x, 5, x/2 + (1/4)*Sqrt[Pi]*FresnelC[(1 + 2*x)/Sqrt[Pi]]}
{Cos[1/4 + x + x^2]^2/x, x, 3, (1/2)*Int[Cos[(1/2)*(1 + 2*x)^2]/x, x] + Log[x]/2}
{Cos[1/4 + x + x^2]^2/x^2, x, 3, -(1/(2*x)) + (1/2)*Int[Cos[(1/2)*(1 + 2*x)^2]/x^2, x]}


(* Integrands of the form (d+e*x)^m*Cos[a+b*x+c*x^2]^n where m and n are integers *)
{(d + e*x)^2*Cos[a + b*x + c*x^2], x, 12, (Sqrt[Pi/2]*FresnelC[(b + 2*c*x)/(Sqrt[c]*Sqrt[2*Pi])]*((2*c*d - b*e)^2*Cos[a - b^2/(4*c)] - 2*c*e^2*Sin[a - b^2/(4*c)]))/(4*c^(5/2)) - (Sqrt[Pi/2]*FresnelS[(b + 2*c*x)/(Sqrt[c]*Sqrt[2*Pi])]*(2*c*e^2*Cos[a - b^2/(4*c)] + (2*c*d - b*e)^2*Sin[a - b^2/(4*c)]))/(4*c^(5/2)) + (e*(4*c*d - b*e)*Sin[a + b*x + c*x^2])/(4*c^2) + (e^2*x*Sin[a + b*x + c*x^2])/(2*c)}
{(d + e*x)*Cos[a + b*x + c*x^2], x, 6, ((2*c*d - b*e)*Sqrt[Pi/2]*Cos[(b^2 - 4*a*c)/(4*c)]*FresnelC[(b + 2*c*x)/(Sqrt[c]*Sqrt[2*Pi])])/(2*c^(3/2)) + ((2*c*d - b*e)*Sqrt[Pi/2]*FresnelS[(b + 2*c*x)/(Sqrt[c]*Sqrt[2*Pi])]*Sin[(b^2 - 4*a*c)/(4*c)])/(2*c^(3/2)) + (e*Sin[a + b*x + c*x^2])/(2*c)}
{Cos[a + b*x + c*x^2]/(d + e*x), x, 0, Int[Cos[a + b*x + c*x^2]/(d + e*x), x]}

{(d + e*x)^2*Cos[a + b*x + c*x^2]^2, x, 33, (d^2*x)/2 + (1/2)*d*e*x^2 + (e^2*x^3)/6 - (Sqrt[Pi]*FresnelS[(b + 2*c*x)/(Sqrt[c]*Sqrt[Pi])]*(c*e^2*Cos[2*a - b^2/(2*c)] + (2*c*d - b*e)^2*Sin[2*a - b^2/(2*c)]))/(16*c^(5/2)) + (Sqrt[Pi]*FresnelC[(b + 2*c*x)/(Sqrt[c]*Sqrt[Pi])]*((2*c*d - b*e)^2*Cos[2*a - b^2/(2*c)] + c*e^2*Sin[(b^2 - 4*a*c)/(2*c)]))/(16*c^(5/2)) + (d*e*Sin[2*a + 2*b*x + 2*c*x^2])/(4*c) - (b*e^2*Sin[2*a + 2*b*x + 2*c*x^2])/(16*c^2) + (e^2*x*Sin[2*a + 2*b*x + 2*c*x^2])/(8*c)}
{(d + e*x)*Cos[a + b*x + c*x^2]^2, x, 18, (d*x)/2 + (e*x^2)/4 + ((2*c*d - b*e)*Sqrt[Pi]*Cos[2*a - b^2/(2*c)]*FresnelC[(b + 2*c*x)/(Sqrt[c]*Sqrt[Pi])])/(8*c^(3/2)) - ((2*c*d - b*e)*Sqrt[Pi]*FresnelS[(b + 2*c*x)/(Sqrt[c]*Sqrt[Pi])]*Sin[2*a - b^2/(2*c)])/(8*c^(3/2)) + (e*Sin[2*a + 2*b*x + 2*c*x^2])/(8*c)}
{Cos[a + b*x + c*x^2]^2/(d + e*x), x, 3, (1/2)*Int[Cos[2*a + 2*b*x + 2*c*x^2]/(d + e*x), x] + Log[d + e*x]/(2*e)}


(* ::Subsection::Closed:: *)
(*Cos[(a+b x)/(c+d x)]^n*)


{Cos[(a + b*x)/(c + d*x)], x, 5, ((c + d*x)*Cos[(a + b*x)/(c + d*x)])/d - ((b*c - a*d)*CosIntegral[-((b*c - a*d)/(d*(c + d*x)))]*Sin[b/d])/d^2 - ((b*c - a*d)*Cos[b/d]*SinIntegral[a/(c + d*x) - (b*c)/(d*(c + d*x))])/d^2}
{Cos[(a + b*x)/(c + d*x)]^2, x, 8, x/2 + ((c + d*x)*Cos[(2*(a + b*x))/(c + d*x)])/(2*d) - ((b*c - a*d)*CosIntegral[-((2*(b*c - a*d))/(d*(c + d*x)))]*Sin[(2*b)/d])/d^2 - ((b*c - a*d)*Cos[(2*b)/d]*SinIntegral[(2*a)/(c + d*x) - (2*b*c)/(d*(c + d*x))])/d^2}


(* ::Subsection::Closed:: *)
(*x^m Cos[a+b x^n]^p*)


{x^3*Cos[a + b*x^2], x, 3, Cos[a + b*x^2]/(2*b^2) + (x^2*Sin[a + b*x^2])/(2*b)}
{x^2*Cos[a + b*x^2], x, 4, -((Sqrt[Pi/2]*Cos[a]*FresnelS[Sqrt[b]*Sqrt[2/Pi]*x])/(2*b^(3/2))) - (Sqrt[Pi/2]*FresnelC[Sqrt[b]*Sqrt[2/Pi]*x]*Sin[a])/(2*b^(3/2)) + (x*Sin[a + b*x^2])/(2*b)}
{x*Cos[a + b*x^2], x, 2, Sin[a + b*x^2]/(2*b)}
{Cos[a + b*x^2], x, 3, (Sqrt[Pi/2]*Cos[a]*FresnelC[Sqrt[b]*Sqrt[2/Pi]*x])/Sqrt[b] - (Sqrt[Pi/2]*FresnelS[Sqrt[b]*Sqrt[2/Pi]*x]*Sin[a])/Sqrt[b]}
{Cos[a + b*x^2]/x, x, 3, (1/2)*Cos[a]*CosIntegral[b*x^2] - (1/2)*Sin[a]*SinIntegral[b*x^2]}
{Cos[a + b*x^2]/x^2, x, 4, -(Cos[a + b*x^2]/x) - Sqrt[b]*Sqrt[2*Pi]*Cos[a]*FresnelS[Sqrt[b]*Sqrt[2/Pi]*x] - Sqrt[b]*Sqrt[2*Pi]*FresnelC[Sqrt[b]*Sqrt[2/Pi]*x]*Sin[a]}
{Cos[a + b*x^2]/x^3, x, 4, -(Cos[a + b*x^2]/(2*x^2)) - (1/2)*b*CosIntegral[b*x^2]*Sin[a] - (1/2)*b*Cos[a]*SinIntegral[b*x^2]}


{x^3*Cos[a + b*x^2]^2, x, 2, x^4/8 + Cos[a + b*x^2]^2/(8*b^2) + (x^2*Cos[a + b*x^2]*Sin[a + b*x^2])/(4*b)}
{x^2*Cos[a + b*x^2]^2, x, 7, x^3/6 - (Sqrt[Pi]*Cos[2*a]*FresnelS[(2*Sqrt[b]*x)/Sqrt[Pi]])/(16*b^(3/2)) - (Sqrt[Pi]*FresnelC[(2*Sqrt[b]*x)/Sqrt[Pi]]*Sin[2*a])/(16*b^(3/2)) + (x*Sin[2*a + 2*b*x^2])/(8*b)}
{x*Cos[a + b*x^2]^2, x, 2, x^2/4 + (Cos[a + b*x^2]*Sin[a + b*x^2])/(4*b)}
{Cos[a + b*x^2]^2, x, 5, x/2 + (Sqrt[Pi]*Cos[2*a]*FresnelC[(2*Sqrt[b]*x)/Sqrt[Pi]])/(4*Sqrt[b]) - (Sqrt[Pi]*FresnelS[(2*Sqrt[b]*x)/Sqrt[Pi]]*Sin[2*a])/(4*Sqrt[b])}
{Cos[a + b*x^2]^2/x, x, 7, (1/4)*Cos[2*a]*CosIntegral[2*b*x^2] + Log[x^2]/4 - (1/4)*Sin[2*a]*SinIntegral[2*b*x^2]}
{Cos[a + b*x^2]^2/x^2, x, 5, -(Cos[a + b*x^2]^2/x) - Sqrt[b]*Sqrt[Pi]*Cos[2*a]*FresnelS[(2*Sqrt[b]*x)/Sqrt[Pi]] - Sqrt[b]*Sqrt[Pi]*FresnelC[(2*Sqrt[b]*x)/Sqrt[Pi]]*Sin[2*a]}
{Cos[a + b*x^2]^2/x^3, x, 8, -(1/(4*x^2)) - Cos[2*a + 2*b*x^2]/(4*x^2) - (1/2)*b*CosIntegral[2*b*x^2]*Sin[2*a] - (1/2)*b*Cos[2*a]*SinIntegral[2*b*x^2]}


{x^3*Cos[a + b*x^2]^3, x, 4, Cos[a + b*x^2]/(3*b^2) + Cos[a + b*x^2]^3/(18*b^2) + (x^2*Sin[a + b*x^2])/(3*b) + (x^2*Cos[a + b*x^2]^2*Sin[a + b*x^2])/(6*b)}
{x^2*Cos[a + b*x^2]^3, x, 10, -((3*Sqrt[Pi/2]*Cos[a]*FresnelS[Sqrt[b]*Sqrt[2/Pi]*x])/(8*b^(3/2))) - (Sqrt[Pi/6]*Cos[3*a]*FresnelS[Sqrt[b]*Sqrt[6/Pi]*x])/(24*b^(3/2)) - (3*Sqrt[Pi/2]*FresnelC[Sqrt[b]*Sqrt[2/Pi]*x]*Sin[a])/(8*b^(3/2)) - (Sqrt[Pi/6]*FresnelC[Sqrt[b]*Sqrt[6/Pi]*x]*Sin[3*a])/(24*b^(3/2)) + (3*x*Sin[a + b*x^2])/(8*b) + (x*Sin[3*a + 3*b*x^2])/(24*b)}
{x*Cos[a + b*x^2]^3, x, 3, Sin[a + b*x^2]/(2*b) - Sin[a + b*x^2]^3/(6*b)}
{Cos[a + b*x^2]^3, x, 8, (3*Sqrt[Pi/2]*Cos[a]*FresnelC[Sqrt[b]*Sqrt[2/Pi]*x])/(4*Sqrt[b]) + (Sqrt[Pi/6]*Cos[3*a]*FresnelC[Sqrt[b]*Sqrt[6/Pi]*x])/(4*Sqrt[b]) - (3*Sqrt[Pi/2]*FresnelS[Sqrt[b]*Sqrt[2/Pi]*x]*Sin[a])/(4*Sqrt[b]) - (Sqrt[Pi/6]*FresnelS[Sqrt[b]*Sqrt[6/Pi]*x]*Sin[3*a])/(4*Sqrt[b])}
{Cos[a + b*x^2]^3/x, x, 9, (3/8)*Cos[a]*CosIntegral[b*x^2] + (1/8)*Cos[3*a]*CosIntegral[3*b*x^2] - (3/8)*Sin[a]*SinIntegral[b*x^2] - (1/8)*Sin[3*a]*SinIntegral[3*b*x^2]}
{Cos[a + b*x^2]^3/x^2, x, 9, -(Cos[a + b*x^2]^3/x) - (3/2)*Sqrt[b]*Sqrt[Pi/2]*Cos[a]*FresnelS[Sqrt[b]*Sqrt[2/Pi]*x] - (1/2)*Sqrt[b]*Sqrt[(3*Pi)/2]*Cos[3*a]*FresnelS[Sqrt[b]*Sqrt[6/Pi]*x] - (3/2)*Sqrt[b]*Sqrt[Pi/2]*FresnelC[Sqrt[b]*Sqrt[2/Pi]*x]*Sin[a] - (1/2)*Sqrt[b]*Sqrt[(3*Pi)/2]*FresnelC[Sqrt[b]*Sqrt[6/Pi]*x]*Sin[3*a]}
{Cos[a + b*x^2]^3/x^3, x, 11, -((3*Cos[a + b*x^2])/(8*x^2)) - Cos[3*a + 3*b*x^2]/(8*x^2) - (3/8)*b*CosIntegral[b*x^2]*Sin[a] - (3/8)*b*CosIntegral[3*b*x^2]*Sin[3*a] - (3/8)*b*Cos[a]*SinIntegral[b*x^2] - (3/8)*b*Cos[3*a]*SinIntegral[3*b*x^2]}


(* Integrands of the form Cos[a+b/x^n]/x^m where m and n are positive integers *)
{Cos[a + b/x], x, 4, x*Cos[a + b/x] + b*CosIntegral[b/x]*Sin[a] + b*Cos[a]*SinIntegral[b/x]}
{Cos[a + b/x]/x, x, 3, (-Cos[a])*CosIntegral[b/x] + Sin[a]*SinIntegral[b/x]}
{Cos[a + b/x]/x^2, x, 2, -(Sin[a + b/x]/b)}
{Cos[a + b/x]/x^3, x, 3, -(Cos[a + b/x]/b^2) - Sin[a + b/x]/(b*x)}
{Cos[a + b/x]/x^4, x, 4, -((2*Cos[a + b/x])/(b^2*x)) + (2*Sin[a + b/x])/b^3 - Sin[a + b/x]/(b*x^2)}


{Cos[a + b/x^2], x, 5, x*Cos[a + b/x^2] + Sqrt[b]*Sqrt[2*Pi]*Cos[a]*FresnelS[(Sqrt[b]*Sqrt[2/Pi])/x] + Sqrt[b]*Sqrt[2*Pi]*FresnelC[(Sqrt[b]*Sqrt[2/Pi])/x]*Sin[a]}
{Cos[a + b/x^2]/x, x, 3, (-(1/2))*Cos[a]*CosIntegral[b/x^2] + (1/2)*Sin[a]*SinIntegral[b/x^2]}
{Cos[a + b/x^2]/x^2, x, 4, -((Sqrt[Pi/2]*Cos[a]*FresnelC[(Sqrt[b]*Sqrt[2/Pi])/x])/Sqrt[b]) + (Sqrt[Pi/2]*FresnelS[(Sqrt[b]*Sqrt[2/Pi])/x]*Sin[a])/Sqrt[b]}
{Cos[a + b/x^2]/x^3, x, 2, -(Sin[a + b/x^2]/(2*b))}
{Cos[a + b/x^2]/x^4, x, 5, (Sqrt[Pi/2]*Cos[a]*FresnelS[(Sqrt[b]*Sqrt[2/Pi])/x])/(2*b^(3/2)) + (Sqrt[Pi/2]*FresnelC[(Sqrt[b]*Sqrt[2/Pi])/x]*Sin[a])/(2*b^(3/2)) - Sin[a + b/x^2]/(2*b*x)}


{Cos[a + b*x^n], x, 3, -((E^(I*a)*x*Gamma[1/n, (-I)*b*x^n])/(((-I)*b*x^n)^n^(-1)*(2*n))) - (x*Gamma[1/n, I*b*x^n])/(E^(I*a)*(I*b*x^n)^n^(-1)*(2*n))}
{Cos[a + b*x^n]^2, x, 5, x/2 - (2^(-2 - 1/n)*E^(2*I*a)*x*Gamma[1/n, -2*I*b*x^n])/(((-I)*b*x^n)^n^(-1)*n) - (2^(-2 - 1/n)*x*Gamma[1/n, 2*I*b*x^n])/(E^(2*I*a)*(I*b*x^n)^n^(-1)*n)}
{Cos[a + b*x^n]^3, x, 8, -((3*E^(I*a)*x*Gamma[1/n, (-I)*b*x^n])/(((-I)*b*x^n)^n^(-1)*(8*n))) - (3*x*Gamma[1/n, I*b*x^n])/(E^(I*a)*(I*b*x^n)^n^(-1)*(8*n)) - (E^(3*I*a)*x*Gamma[1/n, -3*I*b*x^n])/(3^n^(-1)*((-I)*b*x^n)^n^(-1)*(8*n)) - (x*Gamma[1/n, 3*I*b*x^n])/(3^n^(-1)*E^(3*I*a)*(I*b*x^n)^n^(-1)*(8*n))}

{x^m*Cos[a + b*x^n], x, 3, -((E^(I*a)*x^(1 + m)*Gamma[(1 + m)/n, (-I)*b*x^n])/(((-I)*b*x^n)^((1 + m)/n)*(2*n))) - (x^(1 + m)*Gamma[(1 + m)/n, I*b*x^n])/(E^(I*a)*(I*b*x^n)^((1 + m)/n)*(2*n))}
{x^m*Cos[a + b*x^n]^2, x, 6, x^(1 + m)/(2*(1 + m)) - (2^(-2 - (1 + m)/n)*E^(2*I*a)*x^(1 + m)*Gamma[(1 + m)/n, -2*I*b*x^n])/(((-I)*b*x^n)^((1 + m)/n)*n) - (2^(-2 - (1 + m)/n)*x^(1 + m)*Gamma[(1 + m)/n, 2*I*b*x^n])/(E^(2*I*a)*(I*b*x^n)^((1 + m)/n)*n)}
{x^m*Cos[a + b*x^n]^3, x, 8, -((3*E^(I*a)*x^(1 + m)*Gamma[(1 + m)/n, (-I)*b*x^n])/(((-I)*b*x^n)^((1 + m)/n)*(8*n))) - (3*x^(1 + m)*Gamma[(1 + m)/n, I*b*x^n])/(E^(I*a)*(I*b*x^n)^((1 + m)/n)*(8*n)) - (E^(3*I*a)*x^(1 + m)*Gamma[(1 + m)/n, -3*I*b*x^n])/(3^((1 + m)/n)*((-I)*b*x^n)^((1 + m)/n)*(8*n)) - (x^(1 + m)*Gamma[(1 + m)/n, 3*I*b*x^n])/(3^((1 + m)/n)*E^(3*I*a)*(I*b*x^n)^((1 + m)/n)*(8*n))}

{Cos[a + b*x^n]/x^(n + 1), x, 4, -(Cos[a + b*x^n]/(x^n*n)) - (b*CosIntegral[b*x^n]*Sin[a])/n - (b*Cos[a]*SinIntegral[b*x^n])/n}
{Sin[a + b*x^n]^2/x^(n + 1), x, 7, -(1/(x^n*(2*n))) + Cos[2*a + 2*b*x^n]/(x^n*(2*n)) + (b*CosIntegral[2*b*x^n]*Sin[2*a])/n + (b*Cos[2*a]*SinIntegral[2*b*x^n])/n}
{Sin[a + b*x^n]^3/x^(n + 1), x, 11, (3*b*Cos[a]*CosIntegral[b*x^n])/(4*n) - (3*b*Cos[3*a]*CosIntegral[3*b*x^n])/(4*n) - (3*Sin[a + b*x^n])/(x^n*(4*n)) + Sin[3*a + 3*b*x^n]/(x^n*(4*n)) - (3*b*Sin[a]*SinIntegral[b*x^n])/(4*n) + (3*b*Sin[3*a]*SinIntegral[3*b*x^n])/(4*n)}


(* ::Subsection::Closed:: *)
(*x^m Cos[a+b Log[c x^n]]^p*)


(* Integrands of the form Cos[a+b*Log[c*x^n]] *)
{Cos[a + b*Log[c*x^n]], x, 1, (x*Cos[a + b*Log[c*x^n]])/(1 + b^2*n^2) + (b*n*x*Sin[a + b*Log[c*x^n]])/(1 + b^2*n^2)}
{Cos[a + b*Log[c*x^n]]^2, x, 2, (2*b^2*n^2*x)/(1 + 4*b^2*n^2) + (x*Cos[a + b*Log[c*x^n]]^2)/(1 + 4*b^2*n^2) + (2*b*n*x*Cos[a + b*Log[c*x^n]]*Sin[a + b*Log[c*x^n]])/(1 + 4*b^2*n^2)}
{Cos[a + b*Log[c*x^n]]^3, x, 2, (6*b^2*n^2*x*Cos[a + b*Log[c*x^n]])/((1 + b^2*n^2)*(1 + 9*b^2*n^2)) + (x*Cos[a + b*Log[c*x^n]]^3)/(1 + 9*b^2*n^2) + (6*b^3*n^3*x*Sin[a + b*Log[c*x^n]])/((1 + b^2*n^2)*(1 + 9*b^2*n^2)) + (3*b*n*x*Cos[a + b*Log[c*x^n]]^2*Sin[a + b*Log[c*x^n]])/(1 + 9*b^2*n^2)}
{Cos[a + b*Log[c*x^n]]^4, x, 3, (24*b^4*n^4*x)/((1 + 4*b^2*n^2)*(1 + 16*b^2*n^2)) + (12*b^2*n^2*x*Cos[a + b*Log[c*x^n]]^2)/((1 + 4*b^2*n^2)*(1 + 16*b^2*n^2)) + (x*Cos[a + b*Log[c*x^n]]^4)/(1 + 16*b^2*n^2) + (24*b^3*n^3*x*Cos[a + b*Log[c*x^n]]*Sin[a + b*Log[c*x^n]])/((1 + 4*b^2*n^2)*(1 + 16*b^2*n^2)) + (4*b*n*x*Cos[a + b*Log[c*x^n]]^3*Sin[a + b*Log[c*x^n]])/(1 + 16*b^2*n^2)}


(* Integrands of the form x^m*Cos[a+b*Log[c*x^n]]^p where p is an integer *)
{x^m*Cos[a + b*Log[c*x^n]], x, 1, ((1 + m)*x^(1 + m)*Cos[a + b*Log[c*x^n]])/((1 + m)^2 + b^2*n^2) + (b*n*x^(1 + m)*Sin[a + b*Log[c*x^n]])/((1 + m)^2 + b^2*n^2)}
{x^m*Cos[a + b*Log[c*x^n]]^2, x, 2, (2*b^2*n^2*x^(1 + m))/((1 + m)*((1 + m)^2 + 4*b^2*n^2)) + ((1 + m)*x^(1 + m)*Cos[a + b*Log[c*x^n]]^2)/((1 + m)^2 + 4*b^2*n^2) + (2*b*n*x^(1 + m)*Cos[a + b*Log[c*x^n]]*Sin[a + b*Log[c*x^n]])/((1 + m)^2 + 4*b^2*n^2)}
{x^m*Cos[a + b*Log[c*x^n]]^3, x, 2, (6*b^2*(1 + m)*n^2*x^(1 + m)*Cos[a + b*Log[c*x^n]])/(((1 + m)^2 + b^2*n^2)*((1 + m)^2 + 9*b^2*n^2)) + ((1 + m)*x^(1 + m)*Cos[a + b*Log[c*x^n]]^3)/((1 + m)^2 + 9*b^2*n^2) + (6*b^3*n^3*x^(1 + m)*Sin[a + b*Log[c*x^n]])/(((1 + m)^2 + b^2*n^2)*((1 + m)^2 + 9*b^2*n^2)) + (3*b*n*x^(1 + m)*Cos[a + b*Log[c*x^n]]^2*Sin[a + b*Log[c*x^n]])/((1 + m)^2 + 9*b^2*n^2)}
{x^m*Cos[a + b*Log[c*x^n]]^4, x, 3, (24*b^4*n^4*x^(1 + m))/((1 + m)*((1 + m)^2 + 4*b^2*n^2)*((1 + m)^2 + 16*b^2*n^2)) + (12*b^2*(1 + m)*n^2*x^(1 + m)*Cos[a + b*Log[c*x^n]]^2)/(((1 + m)^2 + 4*b^2*n^2)*((1 + m)^2 + 16*b^2*n^2)) + ((1 + m)*x^(1 + m)*Cos[a + b*Log[c*x^n]]^4)/((1 + m)^2 + 16*b^2*n^2) + (24*b^3*n^3*x^(1 + m)*Cos[a + b*Log[c*x^n]]*Sin[a + b*Log[c*x^n]])/(((1 + m)^2 + 4*b^2*n^2)*((1 + m)^2 + 16*b^2*n^2)) + (4*b*n*x^(1 + m)*Cos[a + b*Log[c*x^n]]^3*Sin[a + b*Log[c*x^n]])/((1 + m)^2 + 16*b^2*n^2)}


(* Integrands of the form Cos[a+b*Log[c*x^n]]^p/x where p is an integer *)
{Cos[a + b*Log[c*x^n]]/x, x, 2, Sin[a + b*Log[c*x^n]]/(b*n)}
{Cos[a + b*Log[c*x^n]]^2/x, x, 2, Log[c*x^n]/(2*n) + (Cos[a + b*Log[c*x^n]]*Sin[a + b*Log[c*x^n]])/(2*b*n)}
{Cos[a + b*Log[c*x^n]]^3/x, x, 3, Sin[a + b*Log[c*x^n]]/(b*n) - Sin[a + b*Log[c*x^n]]^3/(3*b*n)}
{Cos[a + b*Log[c*x^n]]^4/x, x, 3, (3*Log[c*x^n])/(8*n) + (3*Cos[a + b*Log[c*x^n]]*Sin[a + b*Log[c*x^n]])/(8*b*n) + (Cos[a + b*Log[c*x^n]]^3*Sin[a + b*Log[c*x^n]])/(4*b*n)}
{Cos[a + b*Log[c*x^n]]^5/x, x, 3, Sin[a + b*Log[c*x^n]]/(b*n) - (2*Sin[a + b*Log[c*x^n]]^3)/(3*b*n) + Sin[a + b*Log[c*x^n]]^5/(5*b*n)}


(* Integrands of the form Cos[a+b*Log[c*x^n]]^p/x where p is a half-integer *)
{Cos[a + b*Log[c*x^n]]^(5/2)/x, x, 3, (6*EllipticE[(1/2)*(a + b*Log[c*x^n]), 2])/(5*b*n) + (2*Cos[a + b*Log[c*x^n]]^(3/2)*Sin[a + b*Log[c*x^n]])/(5*b*n)}
{Cos[a + b*Log[c*x^n]]^(3/2)/x, x, 3, (2*EllipticF[(1/2)*(a + b*Log[c*x^n]), 2])/(3*b*n) + (2*Sqrt[Cos[a + b*Log[c*x^n]]]*Sin[a + b*Log[c*x^n]])/(3*b*n)}
{Sqrt[Cos[a + b*Log[c*x^n]]]/x, x, 2, (2*EllipticE[(a + b*Log[c*x^n])/2, 2])/(b*n)}
{1/(x*Sqrt[Cos[a + b*Log[c*x^n]]]), x, 2, (2*EllipticF[(a + b*Log[c*x^n])/2, 2])/(b*n)}
{1/(x*Cos[a + b*Log[c*x^n]]^(3/2)), x, 3, -((2*EllipticE[(1/2)*(a + b*Log[c*x^n]), 2])/(b*n)) + (2*Sin[a + b*Log[c*x^n]])/(b*n*Sqrt[Cos[a + b*Log[c*x^n]]])}
{1/(x*Cos[a + b*Log[c*x^n]]^(5/2)), x, 3, (2*EllipticF[(1/2)*(a + b*Log[c*x^n]), 2])/(3*b*n) + (2*Sin[a + b*Log[c*x^n]])/(3*b*n*Cos[a + b*Log[c*x^n]]^(3/2))}


{1/Cos[a - 2*I*Log[c*x]]^(3/2), x, 1, (-x)*Sqrt[Cos[a - 2*I*Log[c*x]]] + (I*x*Sin[a - 2*I*Log[c*x]])/Sqrt[Cos[a - 2*I*Log[c*x]]]}


(* ::Subsection::Closed:: *)
(*Miscellaneous integrands involving one cosine*)


(* Integrands of the form x^m*Cos[x]^n where m is an integer and n is a half-integer *)
{x/Cos[x]^(3/2) + x*Sqrt[Cos[x]], x, 2, 4*Sqrt[Cos[x]] + (2*x*Sin[x])/Sqrt[Cos[x]]}
{x/Cos[x]^(5/2) - x/(3*Sqrt[Cos[x]]), x, 2, -(4/(3*Sqrt[Cos[x]])) + (2*x*Sin[x])/(3*Cos[x]^(3/2))}
{x/Cos[x]^(7/2) + (3/5)*x*Sqrt[Cos[x]], x, 3, -(4/(15*Cos[x]^(3/2))) + (12*Sqrt[Cos[x]])/5 + (2*x*Sin[x])/(5*Cos[x]^(5/2)) + (6*x*Sin[x])/(5*Sqrt[Cos[x]])}
{x^2/Cos[x]^(3/2) + x^2*Sqrt[Cos[x]], x, 3, 8*x*Sqrt[Cos[x]] - 16*EllipticE[x/2, 2] + (2*x^2*Sin[x])/Sqrt[Cos[x]]}


{(x + Cos[x])^2, x, 6, x/2 + x^3/3 + 2*Cos[x] + 2*x*Sin[x] + (1/2)*Cos[x]*Sin[x]}
{(x + Cos[x])^3, x, 10, (3*x^2)/4 + x^4/4 + 6*x*Cos[x] + (3*Cos[x]^2)/4 - 5*Sin[x] + 3*x^2*Sin[x] + (3/2)*x*Cos[x]*Sin[x] - Sin[x]^3/3}


{Cos[a + b*x]/(c + d*x^2), x, 10, (Cos[a + (b*Sqrt[-c])/Sqrt[d]]*CosIntegral[-((b*(Sqrt[-c] - Sqrt[d]*x))/Sqrt[d])])/(2*Sqrt[-c]*Sqrt[d]) - (Cos[a - (b*Sqrt[-c])/Sqrt[d]]*CosIntegral[-((b*(Sqrt[-c] + Sqrt[d]*x))/Sqrt[d])])/(2*Sqrt[-c]*Sqrt[d]) + (Sin[a + (b*Sqrt[-c])/Sqrt[d]]*SinIntegral[(b*Sqrt[-c])/Sqrt[d] - b*x])/(2*Sqrt[-c]*Sqrt[d]) + (Sin[a - (b*Sqrt[-c])/Sqrt[d]]*SinIntegral[(b*Sqrt[-c])/Sqrt[d] + b*x])/(2*Sqrt[-c]*Sqrt[d])}
{Cos[a + b*x]/(c + d*x + e*x^2), x, 9, (Cos[a - (b*(d - Sqrt[d^2 - 4*c*e]))/(2*e)]*CosIntegral[(b*(d - Sqrt[d^2 - 4*c*e] + 2*e*x))/(2*e)])/Sqrt[d^2 - 4*c*e] - (Cos[a - (b*(d + Sqrt[d^2 - 4*c*e]))/(2*e)]*CosIntegral[(b*(d + Sqrt[d^2 - 4*c*e] + 2*e*x))/(2*e)])/Sqrt[d^2 - 4*c*e] - (Sin[a - (b*(d - Sqrt[d^2 - 4*c*e]))/(2*e)]*SinIntegral[(b*(d - Sqrt[d^2 - 4*c*e] + 2*e*x))/(2*e)])/Sqrt[d^2 - 4*c*e] + (Sin[a - (b*(d + Sqrt[d^2 - 4*c*e]))/(2*e)]*SinIntegral[(b*(d + Sqrt[d^2 - 4*c*e] + 2*e*x))/(2*e)])/Sqrt[d^2 - 4*c*e]}


{Cos[Sqrt[x]], x, 3, 2*Cos[Sqrt[x]] + 2*Sqrt[x]*Sin[Sqrt[x]]}
{Cos[Sqrt[1 - x]], x, 3, -2*Cos[Sqrt[1 - x]] - 2*Sqrt[1 - x]*Sin[Sqrt[1 - x]]}
{Cos[Sqrt[x]]/Sqrt[x], x, 2, 2*Sin[Sqrt[x]]}
{Cos[Sqrt[x]]^2, x, 3, x/2 + (1/2)*Cos[Sqrt[x]]^2 + Sqrt[x]*Cos[Sqrt[x]]*Sin[Sqrt[x]]}
{Cos[Sqrt[x]]^2/Sqrt[x], x, 2, Sqrt[x] + Cos[Sqrt[x]]*Sin[Sqrt[x]]}
{Cos[x^(1/3)]^3, x, 7, 4*x^(1/3)*Cos[x^(1/3)] + (2/3)*x^(1/3)*Cos[x^(1/3)]^3 - (14/3)*Sin[x^(1/3)] + 2*x^(2/3)*Sin[x^(1/3)] + x^(2/3)*Cos[x^(1/3)]^2*Sin[x^(1/3)] + (2/9)*Sin[x^(1/3)]^3}
{Cos[x^(1/6)]/(6*x^(5/6)), x, 3, Sin[x^(1/6)]}


{(x*Cos[Sqrt[1 + x^2]])/Sqrt[1 + x^2], x, 3, Sin[Sqrt[1 + x^2]]}
{(x*Cos[Sqrt[3]*Sqrt[2 + x^2]])/Sqrt[2 + x^2], x, 3, Sin[Sqrt[3]*Sqrt[2 + x^2]]/Sqrt[3]}
{((-1 + 2*x)*Cos[Sqrt[6 + 3*(-1 + 2*x)^2]])/Sqrt[6 + 3*(-1 + 2*x)^2], x, 2, (1/6)*Sin[Sqrt[3]*Sqrt[2 + (1 - 2*x)^2]]}


(* Integrands of the form x^m*Cos[a+b*Log[c*x^n]]^p where p is a positive integer *)
{Cos[a + b*Log[c*x^n]], x, 1, (x*Cos[a + b*Log[c*x^n]])/(1 + b^2*n^2) + (b*n*x*Sin[a + b*Log[c*x^n]])/(1 + b^2*n^2)}
{x*Cos[a + b*Log[c*x^n]], x, 1, (2*x^2*Cos[a + b*Log[c*x^n]])/(4 + b^2*n^2) + (b*n*x^2*Sin[a + b*Log[c*x^n]])/(4 + b^2*n^2)}
{x^2*Cos[a + b*Log[c*x^n]], x, 1, (3*x^3*Cos[a + b*Log[c*x^n]])/(9 + b^2*n^2) + (b*n*x^3*Sin[a + b*Log[c*x^n]])/(9 + b^2*n^2)}
{Cos[a + b*Log[c*x^n]]/x^2, x, 1, -(Cos[a + b*Log[c*x^n]]/((1 + b^2*n^2)*x)) + (b*n*Sin[a + b*Log[c*x^n]])/((1 + b^2*n^2)*x)}
{x^m*Cos[a + b*Log[c*x^n]], x, 1, ((1 + m)*x^(1 + m)*Cos[a + b*Log[c*x^n]])/((1 + m)^2 + b^2*n^2) + (b*n*x^(1 + m)*Sin[a + b*Log[c*x^n]])/((1 + m)^2 + b^2*n^2)}

{Cos[a + b*Log[c*x^n]]^2, x, 2, (2*b^2*n^2*x)/(1 + 4*b^2*n^2) + (x*Cos[a + b*Log[c*x^n]]^2)/(1 + 4*b^2*n^2) + (2*b*n*x*Cos[a + b*Log[c*x^n]]*Sin[a + b*Log[c*x^n]])/(1 + 4*b^2*n^2)}
{x*Cos[a + b*Log[c*x^n]]^2, x, 2, (b^2*n^2*x^2)/(4*(1 + b^2*n^2)) + (x^2*Cos[a + b*Log[c*x^n]]^2)/(2*(1 + b^2*n^2)) + (b*n*x^2*Cos[a + b*Log[c*x^n]]*Sin[a + b*Log[c*x^n]])/(2*(1 + b^2*n^2))}
{x^2*Cos[a + b*Log[c*x^n]]^2, x, 2, (2*b^2*n^2*x^3)/(3*(9 + 4*b^2*n^2)) + (3*x^3*Cos[a + b*Log[c*x^n]]^2)/(9 + 4*b^2*n^2) + (2*b*n*x^3*Cos[a + b*Log[c*x^n]]*Sin[a + b*Log[c*x^n]])/(9 + 4*b^2*n^2)}
{Cos[a + b*Log[c*x^n]]^2/x^2, x, 2, -((2*b^2*n^2)/((1 + 4*b^2*n^2)*x)) - Cos[a + b*Log[c*x^n]]^2/((1 + 4*b^2*n^2)*x) + (2*b*n*Cos[a + b*Log[c*x^n]]*Sin[a + b*Log[c*x^n]])/((1 + 4*b^2*n^2)*x)}
{x^m*Cos[a + b*Log[c*x^n]]^2, x, 2, (2*b^2*n^2*x^(1 + m))/((1 + m)*((1 + m)^2 + 4*b^2*n^2)) + ((1 + m)*x^(1 + m)*Cos[a + b*Log[c*x^n]]^2)/((1 + m)^2 + 4*b^2*n^2) + (2*b*n*x^(1 + m)*Cos[a + b*Log[c*x^n]]*Sin[a + b*Log[c*x^n]])/((1 + m)^2 + 4*b^2*n^2)}

{Cos[a + b*Log[c*x^n]]^3, x, 2, (6*b^2*n^2*x*Cos[a + b*Log[c*x^n]])/((1 + b^2*n^2)*(1 + 9*b^2*n^2)) + (x*Cos[a + b*Log[c*x^n]]^3)/(1 + 9*b^2*n^2) + (6*b^3*n^3*x*Sin[a + b*Log[c*x^n]])/((1 + b^2*n^2)*(1 + 9*b^2*n^2)) + (3*b*n*x*Cos[a + b*Log[c*x^n]]^2*Sin[a + b*Log[c*x^n]])/(1 + 9*b^2*n^2)}
{x*Cos[a + b*Log[c*x^n]]^3, x, 2, (12*b^2*n^2*x^2*Cos[a + b*Log[c*x^n]])/((4 + b^2*n^2)*(4 + 9*b^2*n^2)) + (2*x^2*Cos[a + b*Log[c*x^n]]^3)/(4 + 9*b^2*n^2) + (6*b^3*n^3*x^2*Sin[a + b*Log[c*x^n]])/((4 + b^2*n^2)*(4 + 9*b^2*n^2)) + (3*b*n*x^2*Cos[a + b*Log[c*x^n]]^2*Sin[a + b*Log[c*x^n]])/(4 + 9*b^2*n^2)}
{x^2*Cos[a + b*Log[c*x^n]]^3, x, 2, (2*b^2*n^2*x^3*Cos[a + b*Log[c*x^n]])/((1 + b^2*n^2)*(9 + b^2*n^2)) + (x^3*Cos[a + b*Log[c*x^n]]^3)/(3*(1 + b^2*n^2)) + (2*b^3*n^3*x^3*Sin[a + b*Log[c*x^n]])/(3*(1 + b^2*n^2)*(9 + b^2*n^2)) + (b*n*x^3*Cos[a + b*Log[c*x^n]]^2*Sin[a + b*Log[c*x^n]])/(3*(1 + b^2*n^2))}
{Cos[a + b*Log[c*x^n]]^3/x^2, x, 2, -((6*b^2*n^2*Cos[a + b*Log[c*x^n]])/((1 + b^2*n^2)*(1 + 9*b^2*n^2)*x)) - Cos[a + b*Log[c*x^n]]^3/((1 + 9*b^2*n^2)*x) + (6*b^3*n^3*Sin[a + b*Log[c*x^n]])/((1 + b^2*n^2)*(1 + 9*b^2*n^2)*x) + (3*b*n*Cos[a + b*Log[c*x^n]]^2*Sin[a + b*Log[c*x^n]])/((1 + 9*b^2*n^2)*x)}
{x^m*Cos[a + b*Log[c*x^n]]^3, x, 2, (6*b^2*(1 + m)*n^2*x^(1 + m)*Cos[a + b*Log[c*x^n]])/(((1 + m)^2 + b^2*n^2)*((1 + m)^2 + 9*b^2*n^2)) + ((1 + m)*x^(1 + m)*Cos[a + b*Log[c*x^n]]^3)/((1 + m)^2 + 9*b^2*n^2) + (6*b^3*n^3*x^(1 + m)*Sin[a + b*Log[c*x^n]])/(((1 + m)^2 + b^2*n^2)*((1 + m)^2 + 9*b^2*n^2)) + (3*b*n*x^(1 + m)*Cos[a + b*Log[c*x^n]]^2*Sin[a + b*Log[c*x^n]])/((1 + m)^2 + 9*b^2*n^2)}


{Cos[Log[6 + 3*x]], x, 2, (1/2)*(2 + x)*Cos[Log[6 + 3*x]] + (1/2)*(2 + x)*Sin[Log[6 + 3*x]]}


(* ::Subsection::Closed:: *)
(*Integrands of the form Sin[c+d x]^m (a+b Cos[c+d x])^n*)


(* Integrands of the form Sin[x]^m/(a+b*Cos[x]) where m is a positive integer *)
{Sin[x]/(a + b*Cos[x]), x, 2, -(Log[a + b*Cos[x]]/b)}
{Sin[x]^2/(a + b*Cos[x]), x, 4, (a*x)/b^2 - (2*Sqrt[a^2 - b^2]*ArcTan[((a - b)*Tan[x/2])/Sqrt[a^2 - b^2]])/b^2 - Sin[x]/b}
{Sin[x]^3/(a + b*Cos[x]), x, 5, -((a*Cos[x])/b^2) + Cos[x]^2/(2*b) + ((a^2 - b^2)*Log[a + b*Cos[x]])/b^3}
{Sin[x]^4/(a + b*Cos[x]), x, 7, -((a^3*x)/b^4) + (3*a*x)/(2*b^2) + (2*(a^2 - b^2)^(3/2)*ArcTan[((a - b)*Tan[x/2])/Sqrt[a^2 - b^2]])/b^4 + (a^2*Sin[x])/b^3 - Sin[x]/b - (a*Cos[x]*Sin[x])/(2*b^2) - Sin[x]^3/(3*b)}

{Sin[x]/(a + a*Cos[x]), x, 3, -(Log[1 + Cos[x]]/a)}
{Sin[2*x]/(1 + Cos[2*x]), x, 2, -Log[Cos[x]], (-(1/2))*Log[1 + Cos[2*x]]}
{Sin[2*x]/(1 - Cos[2*x]), x, 2, Log[Sin[x]], (1/2)*Log[1 - Cos[2*x]]}
{Sin[x]^2/(a + a*Cos[x]), x, 3, x/a - Sin[x]/a}
{Sin[x]^3/(a + a*Cos[x]), x, 2, -(Cos[x]/a) + Cos[x]^2/(2*a)}
{Sin[x]^4/(a + a*Cos[x]), x, 6, x/(2*a) - (Cos[x]*Sin[x])/(2*a) - Sin[x]^3/(3*a)}


(* Integrands of the form Sin[x]^n/(1+/-Cos[x])^n *)
{Sin[x]/(1 + Cos[x])^2, x, 2, 1/(1 + Cos[x])}
{Sin[x]/(1 - Cos[x])^2, x, 2, -(1/(1 - Cos[x]))}
{Sin[x]^2/(1 + Cos[x])^2, x, 2, -x + 2*Tan[x/2]}
{Sin[x]^2/(1 - Cos[x])^2, x, 2, -x - 2*Cot[x/2]}
{Sin[x]^3/(1 + Cos[x])^2, x, 4, Cos[x] - 2*Log[1 + Cos[x]]}
{Sin[x]^3/(1 - Cos[x])^2, x, 4, Cos[x] + 2*Log[1 - Cos[x]]}


{Sin[x]/(1 + Cos[x])^3, x, 2, 1/(2*(1 + Cos[x])^2)}
{Sin[x]/(1 - Cos[x])^3, x, 2, -(1/(2*(1 - Cos[x])^2))}
{Sin[x]^2/(1 + Cos[x])^3, x, 5, (2*Sin[x])/(3*(1 + Cos[x])^2) - Sin[x]/(3*(1 + Cos[x]))}
{Sin[x]^2/(1 - Cos[x])^3, x, 5, -((2*Sin[x])/(3*(1 - Cos[x])^2)) + Sin[x]/(3*(1 - Cos[x]))}
{Sin[x]^3/(1 + Cos[x])^3, x, 5, 2/(1 + Cos[x]) + Log[1 + Cos[x]]}
{Sin[x]^3/(1 - Cos[x])^3, x, 5, -(2/(1 - Cos[x])) - Log[1 - Cos[x]]}


(* ::Subsection::Closed:: *)
(*Integrands of the form Tan[c+d x]^m (a+b Cos[c+d x])^n*)


(* Integrands of the form Tan[x]^m/(a+b*Cos[x]) where m is a positive integer *)
{Tan[x]/(a + b*Cos[x]), x, 2, -(Log[Cos[x]]/a) + Log[a + b*Cos[x]]/a}
{Tan[x]^2/(a + b*Cos[x]), x, 5, -((2*Sqrt[a^2 - b^2]*ArcTan[((a - b)*Tan[x/2])/Sqrt[a^2 - b^2]])/a^2) - (b*ArcTanh[Sin[x]])/a^2 + Tan[x]/a}
{Tan[x]^3/(a + b*Cos[x]), x, 5, ((a^2 - b^2)*Log[Cos[x]])/a^3 - ((a^2 - b^2)*Log[a + b*Cos[x]])/a^3 - (b*Sec[x])/a^2 + Sec[x]^2/(2*a)}
{Tan[x]^4/(a + b*Cos[x]), x, 9, (2*(a^2 - b^2)^(3/2)*ArcTan[((a - b)*Tan[x/2])/Sqrt[a^2 - b^2]])/a^4 + (3*b*ArcTanh[Sin[x]])/(2*a^2) - (b^3*ArcTanh[Sin[x]])/a^4 - Tan[x]/a + (b^2*Tan[x])/a^3 - (b*Sec[x]*Tan[x])/(2*a^2) + Tan[x]^3/(3*a)}

{Tan[x]/(a + a*Cos[x]), x, 3, (2*ArcTanh[1 + 2*Cos[x]])/a}
{Tan[x]^2/(a + a*Cos[x]), x, 4, -(ArcTanh[Sin[x]]/a) + Tan[x]/a}
{Tan[x]^3/(a + a*Cos[x]), x, 3, -(Sec[x]/a) + Sec[x]^2/(2*a)}
{Tan[x]^4/(a + a*Cos[x]), x, 8, ArcTanh[Sin[x]]/(2*a) - (Sec[x]*Tan[x])/(2*a) + Tan[x]^3/(3*a)}


{Tan[3*x]/(1 + Cos[3*x])^2, x, 5, (2/3)*ArcTanh[1 + 2*Cos[3*x]] - 1/(3*(1 + Cos[3*x]))}


{Tan[x]*Sqrt[2 + 3*Cos[x]], x, 3, 2*Sqrt[2]*ArcTanh[Sqrt[2 + 3*Cos[x]]/Sqrt[2]] - 2*Sqrt[2 + 3*Cos[x]]}


(* ::Subsection::Closed:: *)
(*Integrands of the form Cot[c+d x]^m (a+b Cos[c+d x])^n*)


(* Integrands of the form Cot[x]^m/(a+b*Cos[x]) where m is a positive integer *)
{Cot[x]/(a + b*Cos[x]), x, 7, Log[1 - Cos[x]]/(2*(a + b)) + Log[1 + Cos[x]]/(2*(a - b)) - (a*Log[a + b*Cos[x]])/(a^2 - b^2)}
{Cot[x]^2/(a + b*Cos[x]), x, 5, -((2*a^2*ArcTan[((a - b)*Tan[x/2])/Sqrt[a^2 - b^2]])/(a^2 - b^2)^(3/2)) - Sin[x]/(2*(a + b)*(1 - Cos[x])) + Sin[x]/(2*(a - b)*(1 + Cos[x]))}
{Cot[x]^3/(a + b*Cos[x]), x, 8, -(1/(4*(a + b)*(1 - Cos[x]))) - 1/(4*(a - b)*(1 + Cos[x])) - ((2*a + b)*Log[1 - Cos[x]])/(4*(a + b)^2) - ((2*a - b)*Log[1 + Cos[x]])/(4*(a - b)^2) + (a^3*Log[a + b*Cos[x]])/(a^2 - b^2)^2}
{Cot[x]^4/(a + b*Cos[x]), x, 9, (2*a^4*ArcTan[((a - b)*Tan[x/2])/Sqrt[a^2 - b^2]])/(a^2 - b^2)^(5/2) - Sin[x]/(12*(a + b)*(1 - Cos[x])^2) - Sin[x]/(12*(a + b)*(1 - Cos[x])) + ((3*a + 2*b)*Sin[x])/(4*(a + b)^2*(1 - Cos[x])) + Sin[x]/(12*(a - b)*(1 + Cos[x])^2) - ((3*a - 2*b)*Sin[x])/(4*(a - b)^2*(1 + Cos[x])) + Sin[x]/(12*(a - b)*(1 + Cos[x]))}

{Cot[x]/(a + a*Cos[x]), x, 6, -(ArcTanh[Cos[x]]/(2*a)) - 1/(2*a*(1 + Cos[x]))}
{Cot[x]^2/(a + a*Cos[x]), x, 6, -(Sin[x]/(4*a*(1 - Cos[x]))) + Sin[x]/(6*a*(1 + Cos[x])^2) - (7*Sin[x])/(12*a*(1 + Cos[x]))}
{Cot[x]^3/(a + a*Cos[x]), x, 8, (3*ArcTanh[Cos[x]])/(8*a) - 1/(8*a*(1 - Cos[x])) - 1/(8*a*(1 + Cos[x])^2) + 1/(2*a*(1 + Cos[x]))}
{Cot[x]^4/(a + a*Cos[x]), x, 11, -(Sin[x]/(24*a*(1 - Cos[x])^2)) + (13*Sin[x])/(48*a*(1 - Cos[x])) + Sin[x]/(20*a*(1 + Cos[x])^3) - (13*Sin[x])/(60*a*(1 + Cos[x])^2) + (113*Sin[x])/(240*a*(1 + Cos[x]))}


{Cot[x]/Sqrt[3 - Cos[x]], x, 5, -ArcTanh[Sqrt[3 - Cos[x]]/2]/2 - ArcTanh[Sqrt[3 - Cos[x]]/Sqrt[2]]/Sqrt[2]}


(* ::Subsection::Closed:: *)
(*Integrands of the form Csc[c+d x]^m (a+b Cos[c+d x])^n*)


(* Integrands of the form Csc[x]^m/(a+b*Cos[x]) where m is a positive integer *)
{Csc[x]/(a + b*Cos[x]), x, 7, Log[1 - Cos[x]]/(2*(a + b)) - Log[1 + Cos[x]]/(2*(a - b)) + (b*Log[a + b*Cos[x]])/(a^2 - b^2)}
{Csc[x]^2/(a + b*Cos[x]), x, 5, -((2*b^2*ArcTan[(Sqrt[a - b]*Tan[x/2])/Sqrt[a + b]])/((a - b)^(3/2)*(a + b)^(3/2))) - Cot[x/2]/(2*(a + b)) + Tan[x/2]/(2*(a - b)), -((2*b^2*ArcTan[((a - b)*Tan[x/2])/Sqrt[a^2 - b^2]])/(a^2 - b^2)^(3/2)) - Sin[x]/(2*(a + b)*(1 - Cos[x])) + Sin[x]/(2*(a - b)*(1 + Cos[x]))}
{Csc[x]^3/(a + b*Cos[x]), x, 8, -(1/(4*(a + b)*(1 - Cos[x]))) + 1/(4*(a - b)*(1 + Cos[x])) + ((a + 2*b)*Log[1 - Cos[x]])/(4*(a + b)^2) - ((a - 2*b)*Log[1 + Cos[x]])/(4*(a - b)^2) - (b^3*Log[a + b*Cos[x]])/(a^2 - b^2)^2}
{Csc[x]^4/(a + b*Cos[x]), x, 9, (2*b^4*ArcTan[((a - b)*Tan[x/2])/Sqrt[a^2 - b^2]])/(a^2 - b^2)^(5/2) - Sin[x]/(12*(a + b)*(1 - Cos[x])^2) - Sin[x]/(12*(a + b)*(1 - Cos[x])) - ((a + 2*b)*Sin[x])/(4*(a + b)^2*(1 - Cos[x])) + Sin[x]/(12*(a - b)*(1 + Cos[x])^2) + ((a - 2*b)*Sin[x])/(4*(a - b)^2*(1 + Cos[x])) + Sin[x]/(12*(a - b)*(1 + Cos[x]))}

{Csc[x]/(a + a*Cos[x]), x, 6, -(ArcTanh[Cos[x]]/(2*a)) + 1/(2*a*(1 + Cos[x]))}
{Csc[x]^2/(a + a*Cos[x]), x, 6, -(Sin[x]/(4*a*(1 - Cos[x]))) + Sin[x]/(6*a*(1 + Cos[x])^2) + (5*Sin[x])/(12*a*(1 + Cos[x]))}
{Csc[x]^3/(a + a*Cos[x]), x, 8, -((3*ArcTanh[Cos[x]])/(8*a)) - 1/(8*a*(1 - Cos[x])) + 1/(8*a*(1 + Cos[x])^2) + 1/(4*a*(1 + Cos[x]))}
{Csc[x]^4/(a + a*Cos[x]), x, 11, -(Sin[x]/(24*a*(1 - Cos[x])^2)) - (11*Sin[x])/(48*a*(1 - Cos[x])) + Sin[x]/(20*a*(1 + Cos[x])^3) + (7*Sin[x])/(60*a*(1 + Cos[x])^2) + (73*Sin[x])/(240*a*(1 + Cos[x]))}


(* ::Subsection::Closed:: *)
(*Integrands of the form (A+B Sin[c+d x]) (a+b Cos[c+d x])^n*)


(* Integrands of the form (A+B*Sin[x])*(a+b*Cos[x])^n where n is an integer *)
{(A + B*Sin[x])/(a + b*Cos[x]), x, 5, (2*A*ArcTan[((a - b)*Tan[x/2])/Sqrt[a^2 - b^2]])/Sqrt[a^2 - b^2] - (B*Log[a + b*Cos[x]])/b}

{(A + B*Sin[x])/(1 + Cos[x]), x, 4, (-B)*Log[1 + Cos[x]] + (A*Sin[x])/(1 + Cos[x]), -2*B*Log[Cos[x/2]] + (A*Sin[x])/(1 + Cos[x])}
{(A + B*Sin[x])/(1 - Cos[x]), x, 4, B*Log[1 - Cos[x]] - (A*Sin[x])/(1 - Cos[x]), 2*B*Log[Sin[x/2]] - (A*Sin[x])/(1 - Cos[x])}


(* ::Subsection::Closed:: *)
(*Integrands of the form (A+B Tan[c+d x]) (a+b Cos[c+d x])^n*)


{(A + B*Tan[x])/(a + b*Cos[x]), x, 5, (2*A*ArcTan[((a - b)*Tan[x/2])/Sqrt[a^2 - b^2]])/Sqrt[a^2 - b^2] - (B*Log[Cos[x]])/a + (B*Log[a + b*Cos[x]])/a}


(* ::Subsection::Closed:: *)
(*Integrands of the form (A+B Cot[c+d x]) (a+b Cos[c+d x])^n*)


{(A + B*Cot[x])/(a + b*Cos[x]), x, 10, (2*A*ArcTan[((a - b)*Tan[x/2])/Sqrt[a^2 - b^2]])/Sqrt[a^2 - b^2] + (B*Log[1 - Cos[x]])/(2*(a + b)) + (B*Log[1 + Cos[x]])/(2*(a - b)) - (a*B*Log[a + b*Cos[x]])/(a^2 - b^2)}


(* ::Subsection::Closed:: *)
(*Integrands of the form (A+B Csc[c+d x]) (a+b Cos[c+d x])^n*)


{(A + B*Csc[x])/(a + b*Cos[x]), x, 10, (2*A*ArcTan[((a - b)*Tan[x/2])/Sqrt[a^2 - b^2]])/Sqrt[a^2 - b^2] + (B*Log[1 - Cos[x]])/(2*(a + b)) - (B*Log[1 + Cos[x]])/(2*(a - b)) + (b*B*Log[a + b*Cos[x]])/(a^2 - b^2)}


(* ::Subsection::Closed:: *)
(*Integrands of the form (A+B Cos[c+d x]+C Sin[c+d x]^2) (a+b Cos[c+d x])^n*)


{(A + B*Cos[d + e*x] + C*Sin[d + e*x])/(a + b*Cos[d + e*x]), x, 6, (B*x)/b + (2*(A*b - a*B)*ArcTan[((a - b)*Tan[(1/2)*(d + e*x)])/Sqrt[a^2 - b^2]])/(b*Sqrt[a^2 - b^2]*e) - (C*Log[a + b*Cos[d + e*x]])/(b*e)}
{(A + B*Cos[d + e*x] + C*Sin[d + e*x])/(a + b*Cos[d + e*x])^2, x, 7, (2*(a*A - b*B)*ArcTan[((a - b)*Tan[(1/2)*(d + e*x)])/Sqrt[a^2 - b^2]])/((a^2 - b^2)^(3/2)*e) + C/(b*e*(a + b*Cos[d + e*x])) - ((A*b - a*B)*Sin[d + e*x])/((a^2 - b^2)*e*(a + b*Cos[d + e*x]))}
{(A + B*Cos[d + e*x] + C*Sin[d + e*x])/(a + b*Cos[d + e*x])^3, x, 8, ((2*a^2*A + A*b^2 - 3*a*b*B)*ArcTan[((a - b)*Tan[(1/2)*(d + e*x)])/Sqrt[a^2 - b^2]])/((a^2 - b^2)^(5/2)*e) + C/(2*b*e*(a + b*Cos[d + e*x])^2) - ((A*b - a*B)*Sin[d + e*x])/(2*(a^2 - b^2)*e*(a + b*Cos[d + e*x])^2) + ((2*b^2*B - a*(3*A*b - a*B))*Sin[d + e*x])/(2*(a^2 - b^2)^2*e*(a + b*Cos[d + e*x]))}
{(A + B*Cos[d + e*x] + C*Sin[d + e*x])/(a + b*Cos[d + e*x])^4, x, 9, ((2*a^3*A + 3*a*A*b^2 - 4*a^2*b*B - b^3*B)*ArcTan[((a - b)*Tan[(1/2)*(d + e*x)])/Sqrt[a^2 - b^2]])/((a^2 - b^2)^(7/2)*e) + C/(3*b*e*(a + b*Cos[d + e*x])^3) - ((A*b - a*B)*Sin[d + e*x])/(3*(a^2 - b^2)*e*(a + b*Cos[d + e*x])^3) + ((2*a^2*B - 3*b*((5*a*A)/3 - b*B))*Sin[d + e*x])/(6*(a^2 - b^2)^2*e*(a + b*Cos[d + e*x])^2) - ((4*A*b^3 + a*(11*a*A*b - 2*a^2*B - 13*b^2*B))*Sin[d + e*x])/(6*(a^2 - b^2)^3*e*(a + b*Cos[d + e*x]))}
