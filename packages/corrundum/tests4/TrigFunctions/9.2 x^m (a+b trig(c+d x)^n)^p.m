(* ::Package:: *)

(* ::Title:: *)
(*Problems for integrands of the form x^m (a+b trig(c+d x)^n)^p*)


(* ::Section:: *)
(*Integrands of the form x^m (a+b Sin[c+d x]^n)^p*)


(* ::Subsection::Closed:: *)
(*Integrands of the form x^m (a+b Sin[c+d x]^1)^p*)


(* ::Subsubsection::Closed:: *)
(*p*)


{1/(x*(a + b*Sin[x])), x, 0, Int[1/(x*(a + b*Sin[x])), x]}
{x/(a + b*Sin[x]), x, 8, -((I*x*Log[1 - (I*b*E^(I*x))/(a - Sqrt[a^2 - b^2])])/Sqrt[a^2 - b^2]) + (I*x*Log[1 - (I*b*E^(I*x))/(a + Sqrt[a^2 - b^2])])/Sqrt[a^2 - b^2] - PolyLog[2, (I*b*E^(I*x))/(a - Sqrt[a^2 - b^2])]/Sqrt[a^2 - b^2] + PolyLog[2, (I*b*E^(I*x))/(a + Sqrt[a^2 - b^2])]/Sqrt[a^2 - b^2]}
{x^2/(a + b*Sin[x]), x, 10, -((I*x^2*Log[1 - (I*b*E^(I*x))/(a - Sqrt[a^2 - b^2])])/Sqrt[a^2 - b^2]) + (I*x^2*Log[1 - (I*b*E^(I*x))/(a + Sqrt[a^2 - b^2])])/Sqrt[a^2 - b^2] - (2*x*PolyLog[2, (I*b*E^(I*x))/(a - Sqrt[a^2 - b^2])])/Sqrt[a^2 - b^2] + (2*x*PolyLog[2, (I*b*E^(I*x))/(a + Sqrt[a^2 - b^2])])/Sqrt[a^2 - b^2] - (2*I*PolyLog[3, (I*b*E^(I*x))/(a - Sqrt[a^2 - b^2])])/Sqrt[a^2 - b^2] + (2*I*PolyLog[3, (I*b*E^(I*x))/(a + Sqrt[a^2 - b^2])])/Sqrt[a^2 - b^2]}
{x^3/(a + b*Sin[x]), x, 12, -((I*x^3*Log[1 - (I*b*E^(I*x))/(a - Sqrt[a^2 - b^2])])/Sqrt[a^2 - b^2]) + (I*x^3*Log[1 - (I*b*E^(I*x))/(a + Sqrt[a^2 - b^2])])/Sqrt[a^2 - b^2] - (3*x^2*PolyLog[2, (I*b*E^(I*x))/(a - Sqrt[a^2 - b^2])])/Sqrt[a^2 - b^2] + (3*x^2*PolyLog[2, (I*b*E^(I*x))/(a + Sqrt[a^2 - b^2])])/Sqrt[a^2 - b^2] - (6*I*x*PolyLog[3, (I*b*E^(I*x))/(a - Sqrt[a^2 - b^2])])/Sqrt[a^2 - b^2] + (6*I*x*PolyLog[3, (I*b*E^(I*x))/(a + Sqrt[a^2 - b^2])])/Sqrt[a^2 - b^2] + (6*PolyLog[4, (I*b*E^(I*x))/(a - Sqrt[a^2 - b^2])])/Sqrt[a^2 - b^2] - (6*PolyLog[4, (I*b*E^(I*x))/(a + Sqrt[a^2 - b^2])])/Sqrt[a^2 - b^2]}

{1/(x*(a + a*Sin[x])), x, 1, Int[Sec[Pi/4 - x/2]^2/x, x]/(2*a)}
{x/(a + a*Sin[x]), x, 3, (2*Log[Cos[Pi/4 - x/2]])/a - (x*Tan[Pi/4 - x/2])/a}
{x^2/(a + a*Sin[x]), x, 6, (I*x^2)/a + (4*x*Log[1 + E^((I*Pi)/2 - I*x)])/a + (4*I*PolyLog[2, -E^((I*Pi)/2 - I*x)])/a - (x^2*Tan[Pi/4 - x/2])/a}
{x^3/(a + a*Sin[x]), x, 7, (I*x^3)/a + (6*x^2*Log[1 + E^((I*Pi)/2 - I*x)])/a + (12*I*x*PolyLog[2, -E^((I*Pi)/2 - I*x)])/a + (12*PolyLog[3, -E^((I*Pi)/2 - I*x)])/a - (x^3*Tan[Pi/4 - x/2])/a}

{1/(x*(a - a*Sin[x])), x, 1, Int[Sec[Pi/4 + x/2]^2/x, x]/(2*a)}
{x/(a - a*Sin[x]), x, 3, (2*Log[Cos[Pi/4 + x/2]])/a + (x*Tan[Pi/4 + x/2])/a}
{x^2/(a - a*Sin[x]), x, 6, -((I*x^2)/a) + (4*x*Log[1 + E^((I*Pi)/2 + I*x)])/a - (4*I*PolyLog[2, -E^((I*Pi)/2 + I*x)])/a + (x^2*Tan[Pi/4 + x/2])/a}
{x^3/(a - a*Sin[x]), x, 7, -((I*x^3)/a) + (6*x^2*Log[1 + E^((I*Pi)/2 + I*x)])/a - (12*I*x*PolyLog[2, -E^((I*Pi)/2 + I*x)])/a + (12*PolyLog[3, -E^((I*Pi)/2 + I*x)])/a + (x^3*Tan[Pi/4 + x/2])/a}


{x/(a + b*Sin[c + d*x])^2, x, 12, -((I*a*x*Log[1 - (I*b*E^(I*c + I*d*x))/(a - Sqrt[a^2 - b^2])])/((a^2 - b^2)^(3/2)*d)) + (I*a*x*Log[1 - (I*b*E^(I*c + I*d*x))/(a + Sqrt[a^2 - b^2])])/((a^2 - b^2)^(3/2)*d) - Log[a + b*Sin[c + d*x]]/((a^2 - b^2)*d^2) - (a*PolyLog[2, (I*b*E^(I*c + I*d*x))/(a - Sqrt[a^2 - b^2])])/((a^2 - b^2)^(3/2)*d^2) + (a*PolyLog[2, (I*b*E^(I*c + I*d*x))/(a + Sqrt[a^2 - b^2])])/((a^2 - b^2)^(3/2)*d^2) + (b*x*Cos[c + d*x])/((a^2 - b^2)*d*(a + b*Sin[c + d*x]))}
{(e + f*x)/(a + b*Sin[c + d*x])^2, x, 17, (2*a*e*ArcTan[(b + a*Tan[(1/2)*(c + d*x)])/Sqrt[a^2 - b^2]])/((a^2 - b^2)^(3/2)*d) - (I*a*f*x*Log[1 - (I*b*E^(I*c + I*d*x))/(a - Sqrt[a^2 - b^2])])/((a^2 - b^2)^(3/2)*d) + (I*a*f*x*Log[1 - (I*b*E^(I*c + I*d*x))/(a + Sqrt[a^2 - b^2])])/((a^2 - b^2)^(3/2)*d) - (f*Log[a + b*Sin[c + d*x]])/((a^2 - b^2)*d^2) - (a*f*PolyLog[2, (I*b*E^(I*c + I*d*x))/(a - Sqrt[a^2 - b^2])])/((a^2 - b^2)^(3/2)*d^2) + (a*f*PolyLog[2, (I*b*E^(I*c + I*d*x))/(a + Sqrt[a^2 - b^2])])/((a^2 - b^2)^(3/2)*d^2) + (b*e*Cos[c + d*x])/((a^2 - b^2)*d*(a + b*Sin[c + d*x])) + (b*f*x*Cos[c + d*x])/((a^2 - b^2)*d*(a + b*Sin[c + d*x]))}


(* ::Subsubsection::Closed:: *)
(*p/2*)


{x^3*Sqrt[a + a*Sin[x]], x, 5, -96*Sqrt[a + a*Sin[x]] + 12*x^2*Sqrt[a + a*Sin[x]] + 48*x*Sqrt[a + a*Sin[x]]*Tan[Pi/4 - x/2] - 2*x^3*Sqrt[a + a*Sin[x]]*Tan[Pi/4 - x/2]}
{x^2*Sqrt[a + a*Sin[x]], x, 4, 8*x*Sqrt[a + a*Sin[x]] + 16*Sqrt[a + a*Sin[x]]*Tan[Pi/4 - x/2] - 2*x^2*Sqrt[a + a*Sin[x]]*Tan[Pi/4 - x/2]}
{x*Sqrt[a + a*Sin[x]], x, 3, 4*Sqrt[a + a*Sin[x]] - 2*x*Sqrt[a + a*Sin[x]]*Tan[Pi/4 - x/2]}
{Sqrt[a + a*Sin[x]]/x, x, 4, (CosIntegral[x/2]*Sec[Pi/4 - x/2]*Sqrt[a + a*Sin[x]])/Sqrt[2] + (Sec[Pi/4 - x/2]*Sqrt[a + a*Sin[x]]*SinIntegral[x/2])/Sqrt[2]}
{Sqrt[a + a*Sin[x]]/x^2, x, 5, -(Sqrt[a + a*Sin[x]]/x) + (CosIntegral[x/2]*Sec[Pi/4 - x/2]*Sqrt[a + a*Sin[x]])/(2*Sqrt[2]) - (Sec[Pi/4 - x/2]*Sqrt[a + a*Sin[x]]*SinIntegral[x/2])/(2*Sqrt[2])}
{Sqrt[a + a*Sin[x]]/x^3, x, 6, -(Sqrt[a + a*Sin[x]]/(2*x^2)) - (CosIntegral[x/2]*Sec[Pi/4 - x/2]*Sqrt[a + a*Sin[x]])/(8*Sqrt[2]) - (Sec[Pi/4 - x/2]*Sqrt[a + a*Sin[x]]*SinIntegral[x/2])/(8*Sqrt[2]) - (Sqrt[a + a*Sin[x]]*Tan[Pi/4 - x/2])/(4*x)}

{x^3*(a + a*Sin[x])^(3/2), x, 9, (-(1280/9))*a*Sqrt[a + a*Sin[x]] + 16*a*x^2*Sqrt[a + a*Sin[x]] - (64/27)*a*Cos[Pi/4 - x/2]^2*Sqrt[a + a*Sin[x]] + (8/3)*a*x^2*Cos[Pi/4 - x/2]^2*Sqrt[a + a*Sin[x]] + (32/9)*a*x*Cos[Pi/4 - x/2]*Sin[Pi/4 - x/2]*Sqrt[a + a*Sin[x]] - (4/3)*a*x^3*Cos[Pi/4 - x/2]*Sin[Pi/4 - x/2]*Sqrt[a + a*Sin[x]] + (640/9)*a*x*Sqrt[a + a*Sin[x]]*Tan[Pi/4 - x/2] - (8/3)*a*x^3*Sqrt[a + a*Sin[x]]*Tan[Pi/4 - x/2]}
{x^2*(a + a*Sin[x])^(3/2), x, 7, (32/3)*a*x*Sqrt[a + a*Sin[x]] + (16/9)*a*x*Cos[Pi/4 - x/2]^2*Sqrt[a + a*Sin[x]] - (4/3)*a*x^2*Cos[Pi/4 - x/2]*Sin[Pi/4 - x/2]*Sqrt[a + a*Sin[x]] + (224/9)*a*Sqrt[a + a*Sin[x]]*Tan[Pi/4 - x/2] - (8/3)*a*x^2*Sqrt[a + a*Sin[x]]*Tan[Pi/4 - x/2] - (32/27)*a*Sin[Pi/4 - x/2]^2*Sqrt[a + a*Sin[x]]*Tan[Pi/4 - x/2]}
{x*(a + a*Sin[x])^(3/2), x, 4, (16/3)*a*Sqrt[a + a*Sin[x]] + (8/9)*a*Cos[Pi/4 - x/2]^2*Sqrt[a + a*Sin[x]] - (4/3)*a*x*Cos[Pi/4 - x/2]*Sin[Pi/4 - x/2]*Sqrt[a + a*Sin[x]] - (8/3)*a*x*Sqrt[a + a*Sin[x]]*Tan[Pi/4 - x/2]}
{(a + a*Sin[x])^(3/2)/x, x, 9, (3*a*CosIntegral[x/2]*Sec[Pi/4 - x/2]*Sqrt[a + a*Sin[x]])/(2*Sqrt[2]) - (a*CosIntegral[(3*x)/2]*Sec[Pi/4 - x/2]*Sqrt[a + a*Sin[x]])/(2*Sqrt[2]) + (3*a*Sec[Pi/4 - x/2]*Sqrt[a + a*Sin[x]]*SinIntegral[x/2])/(2*Sqrt[2]) + (a*Sec[Pi/4 - x/2]*Sqrt[a + a*Sin[x]]*SinIntegral[(3*x)/2])/(2*Sqrt[2])}
{(a + a*Sin[x])^(3/2)/x^2, x, 9, -((2*a*Cos[Pi/4 - x/2]^2*Sqrt[a + a*Sin[x]])/x) + (3*a*CosIntegral[x/2]*Sec[Pi/4 - x/2]*Sqrt[a + a*Sin[x]])/(4*Sqrt[2]) + (3*a*CosIntegral[(3*x)/2]*Sec[Pi/4 - x/2]*Sqrt[a + a*Sin[x]])/(4*Sqrt[2]) - (3*a*Sec[Pi/4 - x/2]*Sqrt[a + a*Sin[x]]*SinIntegral[x/2])/(4*Sqrt[2]) + (3*a*Sec[Pi/4 - x/2]*Sqrt[a + a*Sin[x]]*SinIntegral[(3*x)/2])/(4*Sqrt[2])}
{(a + a*Sin[x])^(3/2)/x^3, x, 13, -((a*Cos[Pi/4 - x/2]^2*Sqrt[a + a*Sin[x]])/x^2) - (3*a*CosIntegral[x/2]*Sec[Pi/4 - x/2]*Sqrt[a + a*Sin[x]])/(16*Sqrt[2]) + (9*a*CosIntegral[(3*x)/2]*Sec[Pi/4 - x/2]*Sqrt[a + a*Sin[x]])/(16*Sqrt[2]) - (3*a*Cos[Pi/4 - x/2]*Sin[Pi/4 - x/2]*Sqrt[a + a*Sin[x]])/(2*x) - (3*a*Sec[Pi/4 - x/2]*Sqrt[a + a*Sin[x]]*SinIntegral[x/2])/(16*Sqrt[2]) - (9*a*Sec[Pi/4 - x/2]*Sqrt[a + a*Sin[x]]*SinIntegral[(3*x)/2])/(16*Sqrt[2])}

{x^3/Sqrt[a + a*Sin[x]], x, 8, (2*I*x^3*ArcTan[E^((I*Pi)/4 - (I*x)/2)]*Sec[Pi/4 - x/2]*Sqrt[a + a*Sin[x]])/a + (6*I*x^2*PolyLog[2, (-I)*E^((1/4)*I*(Pi - 2*x))]*Sec[Pi/4 - x/2]*Sqrt[a + a*Sin[x]])/a - (6*I*x^2*PolyLog[2, I*E^((1/4)*I*(Pi - 2*x))]*Sec[Pi/4 - x/2]*Sqrt[a + a*Sin[x]])/a + (24*x*PolyLog[3, (-I)*E^((1/4)*I*(Pi - 2*x))]*Sec[Pi/4 - x/2]*Sqrt[a + a*Sin[x]])/a - (24*x*PolyLog[3, I*E^((1/4)*I*(Pi - 2*x))]*Sec[Pi/4 - x/2]*Sqrt[a + a*Sin[x]])/a - (48*I*PolyLog[4, (-I)*E^((1/4)*I*(Pi - 2*x))]*Sec[Pi/4 - x/2]*Sqrt[a + a*Sin[x]])/a + (48*I*PolyLog[4, I*E^((1/4)*I*(Pi - 2*x))]*Sec[Pi/4 - x/2]*Sqrt[a + a*Sin[x]])/a}
{x^2/Sqrt[a + a*Sin[x]], x, 6, (2*I*x^2*ArcTan[E^((I*Pi)/4 - (I*x)/2)]*Sec[Pi/4 - x/2]*Sqrt[a + a*Sin[x]])/a + (4*I*x*PolyLog[2, (-I)*E^((1/4)*I*(Pi - 2*x))]*Sec[Pi/4 - x/2]*Sqrt[a + a*Sin[x]])/a - (4*I*x*PolyLog[2, I*E^((1/4)*I*(Pi - 2*x))]*Sec[Pi/4 - x/2]*Sqrt[a + a*Sin[x]])/a + (8*PolyLog[3, (-I)*E^((1/4)*I*(Pi - 2*x))]*Sec[Pi/4 - x/2]*Sqrt[a + a*Sin[x]])/a - (8*PolyLog[3, I*E^((1/4)*I*(Pi - 2*x))]*Sec[Pi/4 - x/2]*Sqrt[a + a*Sin[x]])/a}
{x/Sqrt[a + a*Sin[x]], x, 4, (2*I*x*ArcTan[E^((I*Pi)/4 - (I*x)/2)]*Sec[Pi/4 - x/2]*Sqrt[a + a*Sin[x]])/a + (2*I*PolyLog[2, (-I)*E^((1/4)*I*(Pi - 2*x))]*Sec[Pi/4 - x/2]*Sqrt[a + a*Sin[x]])/a - (2*I*PolyLog[2, I*E^((1/4)*I*(Pi - 2*x))]*Sec[Pi/4 - x/2]*Sqrt[a + a*Sin[x]])/a}
{1/(x*Sqrt[a + a*Sin[x]]), x, 1, (Int[Sec[Pi/4 - x/2]/x, x]*Sec[Pi/4 - x/2]*Sqrt[a + a*Sin[x]])/(2*a)}

{x^3/(a + a*Sin[x])^(3/2), x, 12, (12*I*x*ArcTan[E^((I*Pi)/4 - (I*x)/2)]*Sec[Pi/4 - x/2]*Sqrt[a + a*Sin[x]])/a^2 + (I*x^3*ArcTan[E^((I*Pi)/4 - (I*x)/2)]*Sec[Pi/4 - x/2]*Sqrt[a + a*Sin[x]])/(2*a^2) + (12*I*PolyLog[2, (-I)*E^((1/4)*I*(Pi - 2*x))]*Sec[Pi/4 - x/2]*Sqrt[a + a*Sin[x]])/a^2 + (3*I*x^2*PolyLog[2, (-I)*E^((1/4)*I*(Pi - 2*x))]*Sec[Pi/4 - x/2]*Sqrt[a + a*Sin[x]])/(2*a^2) - (12*I*PolyLog[2, I*E^((1/4)*I*(Pi - 2*x))]*Sec[Pi/4 - x/2]*Sqrt[a + a*Sin[x]])/a^2 - (3*I*x^2*PolyLog[2, I*E^((1/4)*I*(Pi - 2*x))]*Sec[Pi/4 - x/2]*Sqrt[a + a*Sin[x]])/(2*a^2) + (6*x*PolyLog[3, (-I)*E^((1/4)*I*(Pi - 2*x))]*Sec[Pi/4 - x/2]*Sqrt[a + a*Sin[x]])/a^2 - (6*x*PolyLog[3, I*E^((1/4)*I*(Pi - 2*x))]*Sec[Pi/4 - x/2]*Sqrt[a + a*Sin[x]])/a^2 - (12*I*PolyLog[4, (-I)*E^((1/4)*I*(Pi - 2*x))]*Sec[Pi/4 - x/2]*Sqrt[a + a*Sin[x]])/a^2 + (12*I*PolyLog[4, I*E^((1/4)*I*(Pi - 2*x))]*Sec[Pi/4 - x/2]*Sqrt[a + a*Sin[x]])/a^2 - (3*x^2*Sec[Pi/4 - x/2]^2*Sqrt[a + a*Sin[x]])/(2*a^2) - (x^3*Sec[Pi/4 - x/2]^2*Sqrt[a + a*Sin[x]]*Tan[Pi/4 - x/2])/(4*a^2)}
{x^2/(a + a*Sin[x])^(3/2), x, 8, (I*x^2*ArcTan[E^((I*Pi)/4 - (I*x)/2)]*Sec[Pi/4 - x/2]*Sqrt[a + a*Sin[x]])/(2*a^2) - (2*ArcTanh[Sin[Pi/4 - x/2]]*Sec[Pi/4 - x/2]*Sqrt[a + a*Sin[x]])/a^2 + (I*x*PolyLog[2, (-I)*E^((1/4)*I*(Pi - 2*x))]*Sec[Pi/4 - x/2]*Sqrt[a + a*Sin[x]])/a^2 - (I*x*PolyLog[2, I*E^((1/4)*I*(Pi - 2*x))]*Sec[Pi/4 - x/2]*Sqrt[a + a*Sin[x]])/a^2 + (2*PolyLog[3, (-I)*E^((1/4)*I*(Pi - 2*x))]*Sec[Pi/4 - x/2]*Sqrt[a + a*Sin[x]])/a^2 - (2*PolyLog[3, I*E^((1/4)*I*(Pi - 2*x))]*Sec[Pi/4 - x/2]*Sqrt[a + a*Sin[x]])/a^2 - (x*Sec[Pi/4 - x/2]^2*Sqrt[a + a*Sin[x]])/a^2 - (x^2*Sec[Pi/4 - x/2]^2*Sqrt[a + a*Sin[x]]*Tan[Pi/4 - x/2])/(4*a^2)}
{x/(a + a*Sin[x])^(3/2), x, 5, (I*x*ArcTan[E^((I*Pi)/4 - (I*x)/2)]*Sec[Pi/4 - x/2]*Sqrt[a + a*Sin[x]])/(2*a^2) + (I*PolyLog[2, (-I)*E^((1/4)*I*(Pi - 2*x))]*Sec[Pi/4 - x/2]*Sqrt[a + a*Sin[x]])/(2*a^2) - (I*PolyLog[2, I*E^((1/4)*I*(Pi - 2*x))]*Sec[Pi/4 - x/2]*Sqrt[a + a*Sin[x]])/(2*a^2) - (Sec[Pi/4 - x/2]^2*Sqrt[a + a*Sin[x]])/(2*a^2) - (x*Sec[Pi/4 - x/2]^2*Sqrt[a + a*Sin[x]]*Tan[Pi/4 - x/2])/(4*a^2)}
{1/(x*(a + a*Sin[x])^(3/2)), x, 1, (Int[Sec[Pi/4 - x/2]^3/x, x]*Sec[Pi/4 - x/2]*Sqrt[a + a*Sin[x]])/(4*a^2)}


(* Integrands of the form x^m*(a-a*Sin[x])^n where m is an integer and n is a half-integer *)
{x^3*Sqrt[a - a*Sin[x]], x, 5, -96*Sqrt[a - a*Sin[x]] + 12*x^2*Sqrt[a - a*Sin[x]] - 48*x*Sqrt[a - a*Sin[x]]*Tan[Pi/4 + x/2] + 2*x^3*Sqrt[a - a*Sin[x]]*Tan[Pi/4 + x/2]}
{x^2*Sqrt[a - a*Sin[x]], x, 4, 8*x*Sqrt[a - a*Sin[x]] - 16*Sqrt[a - a*Sin[x]]*Tan[Pi/4 + x/2] + 2*x^2*Sqrt[a - a*Sin[x]]*Tan[Pi/4 + x/2]}
{x*Sqrt[a - a*Sin[x]], x, 3, 4*Sqrt[a - a*Sin[x]] + 2*x*Sqrt[a - a*Sin[x]]*Tan[Pi/4 + x/2]}
{Sqrt[a - a*Sin[x]]/x, x, 4, (CosIntegral[x/2]*Sec[Pi/4 + x/2]*Sqrt[a - a*Sin[x]])/Sqrt[2] - (Sec[Pi/4 + x/2]*Sqrt[a - a*Sin[x]]*SinIntegral[x/2])/Sqrt[2]}
{Sqrt[a - a*Sin[x]]/x^2, x, 5, -(Sqrt[a - a*Sin[x]]/x) - (CosIntegral[x/2]*Sec[Pi/4 + x/2]*Sqrt[a - a*Sin[x]])/(2*Sqrt[2]) - (Sec[Pi/4 + x/2]*Sqrt[a - a*Sin[x]]*SinIntegral[x/2])/(2*Sqrt[2])}
{Sqrt[a - a*Sin[x]]/x^3, x, 6, -(Sqrt[a - a*Sin[x]]/(2*x^2)) - (CosIntegral[x/2]*Sec[Pi/4 + x/2]*Sqrt[a - a*Sin[x]])/(8*Sqrt[2]) + (Sec[Pi/4 + x/2]*Sqrt[a - a*Sin[x]]*SinIntegral[x/2])/(8*Sqrt[2]) + (Sqrt[a - a*Sin[x]]*Tan[Pi/4 + x/2])/(4*x)}

{x^3/Sqrt[a - a*Sin[x]], x, 8, -((2*I*x^3*ArcTan[E^((I*Pi)/4 + (I*x)/2)]*Sec[Pi/4 + x/2]*Sqrt[a - a*Sin[x]])/a) + (6*I*x^2*PolyLog[2, (-I)*E^((1/4)*I*(Pi + 2*x))]*Sec[Pi/4 + x/2]*Sqrt[a - a*Sin[x]])/a - (6*I*x^2*PolyLog[2, I*E^((1/4)*I*(Pi + 2*x))]*Sec[Pi/4 + x/2]*Sqrt[a - a*Sin[x]])/a - (24*x*PolyLog[3, (-I)*E^((1/4)*I*(Pi + 2*x))]*Sec[Pi/4 + x/2]*Sqrt[a - a*Sin[x]])/a + (24*x*PolyLog[3, I*E^((1/4)*I*(Pi + 2*x))]*Sec[Pi/4 + x/2]*Sqrt[a - a*Sin[x]])/a - (48*I*PolyLog[4, (-I)*E^((1/4)*I*(Pi + 2*x))]*Sec[Pi/4 + x/2]*Sqrt[a - a*Sin[x]])/a + (48*I*PolyLog[4, I*E^((1/4)*I*(Pi + 2*x))]*Sec[Pi/4 + x/2]*Sqrt[a - a*Sin[x]])/a}
{x^2/Sqrt[a - a*Sin[x]], x, 6, -((2*I*x^2*ArcTan[E^((I*Pi)/4 + (I*x)/2)]*Sec[Pi/4 + x/2]*Sqrt[a - a*Sin[x]])/a) + (4*I*x*PolyLog[2, (-I)*E^((1/4)*I*(Pi + 2*x))]*Sec[Pi/4 + x/2]*Sqrt[a - a*Sin[x]])/a - (4*I*x*PolyLog[2, I*E^((1/4)*I*(Pi + 2*x))]*Sec[Pi/4 + x/2]*Sqrt[a - a*Sin[x]])/a - (8*PolyLog[3, (-I)*E^((1/4)*I*(Pi + 2*x))]*Sec[Pi/4 + x/2]*Sqrt[a - a*Sin[x]])/a + (8*PolyLog[3, I*E^((1/4)*I*(Pi + 2*x))]*Sec[Pi/4 + x/2]*Sqrt[a - a*Sin[x]])/a}
{x/Sqrt[a - a*Sin[x]], x, 4, -((2*I*x*ArcTan[E^((I*Pi)/4 + (I*x)/2)]*Sec[Pi/4 + x/2]*Sqrt[a - a*Sin[x]])/a) + (2*I*PolyLog[2, (-I)*E^((1/4)*I*(Pi + 2*x))]*Sec[Pi/4 + x/2]*Sqrt[a - a*Sin[x]])/a - (2*I*PolyLog[2, I*E^((1/4)*I*(Pi + 2*x))]*Sec[Pi/4 + x/2]*Sqrt[a - a*Sin[x]])/a}
{1/(x*Sqrt[a - a*Sin[x]]), x, 1, (Int[Sec[Pi/4 + x/2]/x, x]*Sec[Pi/4 + x/2]*Sqrt[a - a*Sin[x]])/(2*a)}


(* Integrands of the form x^m*(a+a*Sin[c+d*x])^n where m is an integer and n is a half-integer *)
{x^3*Sqrt[a + a*Sin[c + d*x]], x, 5, -((96*Sqrt[a + a*Sin[c + d*x]])/d^4) + (12*x^2*Sqrt[a + a*Sin[c + d*x]])/d^2 - (48*x*Sqrt[a + a*Sin[c + d*x]]*Tan[(1/4)*(2*c - Pi) + (d*x)/2])/d^3 + (2*x^3*Sqrt[a + a*Sin[c + d*x]]*Tan[(1/4)*(2*c - Pi) + (d*x)/2])/d}
{x^2*Sqrt[a + a*Sin[c + d*x]], x, 4, (8*x*Sqrt[a + a*Sin[c + d*x]])/d^2 - (16*Sqrt[a + a*Sin[c + d*x]]*Tan[(1/4)*(2*c - Pi) + (d*x)/2])/d^3 + (2*x^2*Sqrt[a + a*Sin[c + d*x]]*Tan[(1/4)*(2*c - Pi) + (d*x)/2])/d}
{x*Sqrt[a + a*Sin[c + d*x]], x, 3, (4*Sqrt[a + a*Sin[c + d*x]])/d^2 + (2*x*Sqrt[a + a*Sin[c + d*x]]*Tan[(1/4)*(2*c - Pi) + (d*x)/2])/d}
{Sqrt[a + a*Sin[c + d*x]]/x, x, 4, CosIntegral[(d*x)/2]*Sec[(1/4)*(2*c - Pi) + (d*x)/2]*Sin[(1/4)*(2*c + Pi)]*Sqrt[a + a*Sin[c + d*x]] - Sec[(1/4)*(2*c - Pi) + (d*x)/2]*Sin[(1/4)*(2*c - Pi)]*Sqrt[a + a*Sin[c + d*x]]*SinIntegral[(d*x)/2]}
{Sqrt[a + a*Sin[c + d*x]]/x^2, x, 5, -(Sqrt[a + a*Sin[c + d*x]]/x) - (1/2)*d*CosIntegral[(d*x)/2]*Sec[(1/4)*(2*c - Pi) + (d*x)/2]*Sin[(1/4)*(2*c - Pi)]*Sqrt[a + a*Sin[c + d*x]] - (1/2)*d*Sec[(1/4)*(2*c - Pi) + (d*x)/2]*Sin[(1/4)*(2*c + Pi)]*Sqrt[a + a*Sin[c + d*x]]*SinIntegral[(d*x)/2]}
{Sqrt[a + a*Sin[c + d*x]]/x^3, x, 6, -(Sqrt[a + a*Sin[c + d*x]]/(2*x^2)) - (1/8)*d^2*CosIntegral[(d*x)/2]*Sec[(1/4)*(2*c - Pi) + (d*x)/2]*Sin[(1/4)*(2*c + Pi)]*Sqrt[a + a*Sin[c + d*x]] + (1/8)*d^2*Sec[(1/4)*(2*c - Pi) + (d*x)/2]*Sin[(1/4)*(2*c - Pi)]*Sqrt[a + a*Sin[c + d*x]]*SinIntegral[(d*x)/2] + (d*Sqrt[a + a*Sin[c + d*x]]*Tan[(1/4)*(2*c - Pi) + (d*x)/2])/(4*x)}

(* {x^3/Sqrt[a + a*Sin[c + d*x]], x, 9, -((2*I*x^3*ArcTan[E^((1/4)*I*(2*c - Pi) + (I*d*x)/2)]*Sec[c/2 - Pi/4 + (d*x)/2]*Sqrt[a + a*Sin[c + d*x]])/(a*d)) + (6*I*x^2*PolyLog[2, (-I)*E^((1/4)*I*(2*c - Pi) + (I*d*x)/2)]*Sec[c/2 - Pi/4 + (d*x)/2]*Sqrt[a + a*Sin[c + d*x]])/(a*d^2) - (6*I*x^2*PolyLog[2, I*E^((1/4)*I*(2*c - Pi) + (I*d*x)/2)]*Sec[c/2 - Pi/4 + (d*x)/2]*Sqrt[a + a*Sin[c + d*x]])/(a*d^2) - (24*x*PolyLog[3, (-I)*E^((1/4)*I*(2*c - Pi) + (I*d*x)/2)]*Sec[c/2 - Pi/4 + (d*x)/2]*Sqrt[a + a*Sin[c + d*x]])/(a*d^3) + (24*x*PolyLog[3, I*E^((1/4)*I*(2*c - Pi) + (I*d*x)/2)]*Sec[c/2 - Pi/4 + (d*x)/2]*Sqrt[a + a*Sin[c + d*x]])/(a*d^3) - (48*I*PolyLog[4, (-I)*E^((1/4)*I*(2*c - Pi) + (I*d*x)/2)]*Sec[c/2 - Pi/4 + (d*x)/2]*Sqrt[a + a*Sin[c + d*x]])/(a*d^4) + (48*I*PolyLog[4, I*E^((1/4)*I*(2*c - Pi) + (I*d*x)/2)]*Sec[c/2 - Pi/4 + (d*x)/2]*Sqrt[a + a*Sin[c + d*x]])/(a*d^4)} *)
{x^2/Sqrt[a + a*Sin[c + d*x]], x, 6, -((2*I*x^2*ArcTan[E^((1/4)*I*(2*c - Pi) + (I*d*x)/2)]*Sec[(1/4)*(2*c - Pi) + (d*x)/2]*Sqrt[a + a*Sin[c + d*x]])/(a*d)) + (4*I*x*PolyLog[2, (-I)*E^((1/4)*I*(2*c - Pi + 2*d*x))]*Sec[(1/4)*(2*c - Pi) + (d*x)/2]*Sqrt[a + a*Sin[c + d*x]])/(a*d^2) - (4*I*x*PolyLog[2, I*E^((1/4)*I*(2*c - Pi + 2*d*x))]*Sec[(1/4)*(2*c - Pi) + (d*x)/2]*Sqrt[a + a*Sin[c + d*x]])/(a*d^2) - (8*PolyLog[3, (-I)*E^((1/4)*I*(2*c - Pi + 2*d*x))]*Sec[(1/4)*(2*c - Pi) + (d*x)/2]*Sqrt[a + a*Sin[c + d*x]])/(a*d^3) + (8*PolyLog[3, I*E^((1/4)*I*(2*c - Pi + 2*d*x))]*Sec[(1/4)*(2*c - Pi) + (d*x)/2]*Sqrt[a + a*Sin[c + d*x]])/(a*d^3)}
{x/Sqrt[a + a*Sin[c + d*x]], x, 4, -((2*I*x*ArcTan[E^((1/4)*I*(2*c - Pi) + (I*d*x)/2)]*Sec[(1/4)*(2*c - Pi) + (d*x)/2]*Sqrt[a + a*Sin[c + d*x]])/(a*d)) + (2*I*PolyLog[2, (-I)*E^((1/4)*I*(2*c - Pi + 2*d*x))]*Sec[(1/4)*(2*c - Pi) + (d*x)/2]*Sqrt[a + a*Sin[c + d*x]])/(a*d^2) - (2*I*PolyLog[2, I*E^((1/4)*I*(2*c - Pi + 2*d*x))]*Sec[(1/4)*(2*c - Pi) + (d*x)/2]*Sqrt[a + a*Sin[c + d*x]])/(a*d^2)}
{1/(x*Sqrt[a + a*Sin[c + d*x]]), x, 1, (Int[Sec[c/2 - Pi/4 + (d*x)/2]/x, x]*Sec[(1/4)*(2*c - Pi) + (d*x)/2]*Sqrt[a + a*Sin[c + d*x]])/(2*a)}


(* Used to hang Rubi *)
{(a + a*Sin[c + d*x])^(1/3)/x, x, 1, (Int[Cos[c/2 - Pi/4 + (d*x)/2]^(2/3)/x, x]*Sec[(1/4)*(2*c - Pi) + (d*x)/2]*Sqrt[a + a*Sin[c + d*x]])/(2^(1/6)*a^(1/6))}


(* ::Subsection::Closed:: *)
(*Integrands of the form x^m (a+b Sin[c+d x]^2)^p*)


{x/(a + b*Sin[x]^2), x, 9, -((I*x*Log[1 - (b*E^(2*I*x))/(2*a + b - 2*Sqrt[a]*Sqrt[a + b])])/(2*Sqrt[a]*Sqrt[a + b])) + (I*x*Log[1 - (b*E^(2*I*x))/(2*a + b + 2*Sqrt[a]*Sqrt[a + b])])/(2*Sqrt[a]*Sqrt[a + b]) - PolyLog[2, (b*E^(2*I*x))/(2*a + b - 2*Sqrt[a]*Sqrt[a + b])]/(4*Sqrt[a]*Sqrt[a + b]) + PolyLog[2, (b*E^(2*I*x))/(2*a + b + 2*Sqrt[a]*Sqrt[a + b])]/(4*Sqrt[a]*Sqrt[a + b])}
{x^2/(a + b*Sin[x]^2), x, 11, -((I*x^2*Log[1 - (b*E^(2*I*x))/(2*a + b - 2*Sqrt[a]*Sqrt[a + b])])/(2*Sqrt[a]*Sqrt[a + b])) + (I*x^2*Log[1 - (b*E^(2*I*x))/(2*a + b + 2*Sqrt[a]*Sqrt[a + b])])/(2*Sqrt[a]*Sqrt[a + b]) - (x*PolyLog[2, (b*E^(2*I*x))/(2*a + b - 2*Sqrt[a]*Sqrt[a + b])])/(2*Sqrt[a]*Sqrt[a + b]) + (x*PolyLog[2, (b*E^(2*I*x))/(2*a + b + 2*Sqrt[a]*Sqrt[a + b])])/(2*Sqrt[a]*Sqrt[a + b]) - (I*PolyLog[3, (b*E^(2*I*x))/(2*a + b - 2*Sqrt[a]*Sqrt[a + b])])/(4*Sqrt[a]*Sqrt[a + b]) + (I*PolyLog[3, (b*E^(2*I*x))/(2*a + b + 2*Sqrt[a]*Sqrt[a + b])])/(4*Sqrt[a]*Sqrt[a + b])}
{x^3/(a + b*Sin[x]^2), x, 13, -((I*x^3*Log[1 - (b*E^(2*I*x))/(2*a + b - 2*Sqrt[a]*Sqrt[a + b])])/(2*Sqrt[a]*Sqrt[a + b])) + (I*x^3*Log[1 - (b*E^(2*I*x))/(2*a + b + 2*Sqrt[a]*Sqrt[a + b])])/(2*Sqrt[a]*Sqrt[a + b]) - (3*x^2*PolyLog[2, (b*E^(2*I*x))/(2*a + b - 2*Sqrt[a]*Sqrt[a + b])])/(4*Sqrt[a]*Sqrt[a + b]) + (3*x^2*PolyLog[2, (b*E^(2*I*x))/(2*a + b + 2*Sqrt[a]*Sqrt[a + b])])/(4*Sqrt[a]*Sqrt[a + b]) - (3*I*x*PolyLog[3, (b*E^(2*I*x))/(2*a + b - 2*Sqrt[a]*Sqrt[a + b])])/(4*Sqrt[a]*Sqrt[a + b]) + (3*I*x*PolyLog[3, (b*E^(2*I*x))/(2*a + b + 2*Sqrt[a]*Sqrt[a + b])])/(4*Sqrt[a]*Sqrt[a + b]) + (3*PolyLog[4, (b*E^(2*I*x))/(2*a + b - 2*Sqrt[a]*Sqrt[a + b])])/(8*Sqrt[a]*Sqrt[a + b]) - (3*PolyLog[4, (b*E^(2*I*x))/(2*a + b + 2*Sqrt[a]*Sqrt[a + b])])/(8*Sqrt[a]*Sqrt[a + b])}


{x/(a + b*Sin[c + d*x]^2)^2, x, 13, -((I*(2*a + b)*x*Log[1 - (b*E^(2*I*c + 2*I*d*x))/(2*a + b - 2*Sqrt[a]*Sqrt[a + b])])/(4*a^(3/2)*(a + b)^(3/2)*d)) + (I*(2*a + b)*x*Log[1 - (b*E^(2*I*c + 2*I*d*x))/(2*a + b + 2*Sqrt[a]*Sqrt[a + b])])/(4*a^(3/2)*(a + b)^(3/2)*d) - Log[2*a + b - b*Cos[2*c + 2*d*x]]/(4*a*(a + b)*d^2) - ((2*a + b)*PolyLog[2, (b*E^(2*I*c + 2*I*d*x))/(2*a + b - 2*Sqrt[a]*Sqrt[a + b])])/(8*a^(3/2)*(a + b)^(3/2)*d^2) + ((2*a + b)*PolyLog[2, (b*E^(2*I*c + 2*I*d*x))/(2*a + b + 2*Sqrt[a]*Sqrt[a + b])])/(8*a^(3/2)*(a + b)^(3/2)*d^2) + (b*x*Sin[2*c + 2*d*x])/(2*a*(a + b)*d*(2*a + b - b*Cos[2*c + 2*d*x]))}


{x*Sqrt[Sin[x]^2], x, 3, Sqrt[Sin[x]^2] - x*Cot[x]*Sqrt[Sin[x]^2]}


(* ::Section:: *)
(*Integrands of the form x^m (a+b Cos[c+d x]^n)^p*)


(* ::Subsection::Closed:: *)
(*Integrands of the form x^m (a+b Cos[c+d x]^1)^p*)


(* ::Subsubsection::Closed:: *)
(*p*)


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
{(e + f*x)/(a + b*Cos[c + d*x])^2, x, 17, (2*a*e*ArcTan[(Sqrt[a^2 - b^2]*Tan[(1/2)*(c + d*x)])/(a + b)])/((a^2 - b^2)^(3/2)*d) - (I*a*f*x*Log[1 + (b*E^(I*c + I*d*x))/(a - Sqrt[a^2 - b^2])])/((a^2 - b^2)^(3/2)*d) + (I*a*f*x*Log[1 + (b*E^(I*c + I*d*x))/(a + Sqrt[a^2 - b^2])])/((a^2 - b^2)^(3/2)*d) - (f*Log[a + b*Cos[c + d*x]])/((a^2 - b^2)*d^2) - (a*f*PolyLog[2, -((b*E^(I*c + I*d*x))/(a - Sqrt[a^2 - b^2]))])/((a^2 - b^2)^(3/2)*d^2) + (a*f*PolyLog[2, -((b*E^(I*c + I*d*x))/(a + Sqrt[a^2 - b^2]))])/((a^2 - b^2)^(3/2)*d^2) - (b*e*Sin[c + d*x])/((a^2 - b^2)*d*(a + b*Cos[c + d*x])) - (b*f*x*Sin[c + d*x])/((a^2 - b^2)*d*(a + b*Cos[c + d*x]))}


(* ::Subsubsection::Closed:: *)
(*p/2*)


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
{(a + a*Cos[x])^(3/2)/x^2, x, 5, -((2*a*Cos[x/2]^2*Sqrt[a + a*Cos[x]])/x) - (3/4)*a*Sqrt[a + a*Cos[x]]*Sec[x/2]*SinIntegral[x/2] - (3/4)*a*Sqrt[a + a*Cos[x]]*Sec[x/2]*SinIntegral[(3*x)/2]}
{(a + a*Cos[x])^(3/2)/x^3, x, 7, -((a*Cos[x/2]^2*Sqrt[a + a*Cos[x]])/x^2) - (3/16)*a*Sqrt[a + a*Cos[x]]*CosIntegral[x/2]*Sec[x/2] - (9/16)*a*Sqrt[a + a*Cos[x]]*CosIntegral[(3*x)/2]*Sec[x/2] + (3*a*Cos[x/2]*Sqrt[a + a*Cos[x]]*Sin[x/2])/(2*x)}

{x^3/Sqrt[a + a*Cos[x]], x, 8, -((2*I*x^3*ArcTan[E^((I*x)/2)]*Sqrt[a + a*Cos[x]]*Sec[x/2])/a) + (6*I*x^2*Sqrt[a + a*Cos[x]]*PolyLog[2, (-I)*E^((I*x)/2)]*Sec[x/2])/a - (6*I*x^2*Sqrt[a + a*Cos[x]]*PolyLog[2, I*E^((I*x)/2)]*Sec[x/2])/a - (24*x*Sqrt[a + a*Cos[x]]*PolyLog[3, (-I)*E^((I*x)/2)]*Sec[x/2])/a + (24*x*Sqrt[a + a*Cos[x]]*PolyLog[3, I*E^((I*x)/2)]*Sec[x/2])/a - (48*I*Sqrt[a + a*Cos[x]]*PolyLog[4, (-I)*E^((I*x)/2)]*Sec[x/2])/a + (48*I*Sqrt[a + a*Cos[x]]*PolyLog[4, I*E^((I*x)/2)]*Sec[x/2])/a}
{x^2/Sqrt[a + a*Cos[x]], x, 6, -((2*I*x^2*ArcTan[E^((I*x)/2)]*Sqrt[a + a*Cos[x]]*Sec[x/2])/a) + (4*I*x*Sqrt[a + a*Cos[x]]*PolyLog[2, (-I)*E^((I*x)/2)]*Sec[x/2])/a - (4*I*x*Sqrt[a + a*Cos[x]]*PolyLog[2, I*E^((I*x)/2)]*Sec[x/2])/a - (8*Sqrt[a + a*Cos[x]]*PolyLog[3, (-I)*E^((I*x)/2)]*Sec[x/2])/a + (8*Sqrt[a + a*Cos[x]]*PolyLog[3, I*E^((I*x)/2)]*Sec[x/2])/a}
{x/Sqrt[a + a*Cos[x]], x, 4, -((2*I*x*ArcTan[E^((I*x)/2)]*Sqrt[a + a*Cos[x]]*Sec[x/2])/a) + (2*I*Sqrt[a + a*Cos[x]]*PolyLog[2, (-I)*E^((I*x)/2)]*Sec[x/2])/a - (2*I*Sqrt[a + a*Cos[x]]*PolyLog[2, I*E^((I*x)/2)]*Sec[x/2])/a}
{1/Sqrt[a + a*Cos[x]], x, 1, (2*ArcTanh[Sin[x/2]]*Cos[x/2])/Sqrt[a + a*Cos[x]]}
{1/(x*Sqrt[a + a*Cos[x]]), x, 1, (Sqrt[a + a*Cos[x]]*Int[Sec[x/2]/x, x]*Sec[x/2])/(2*a)}

{x^3/(a + a*Cos[x])^(3/2), x, 12, -((12*I*x*ArcTan[E^((I*x)/2)]*Sqrt[a + a*Cos[x]]*Sec[x/2])/a^2) - (I*x^3*ArcTan[E^((I*x)/2)]*Sqrt[a + a*Cos[x]]*Sec[x/2])/(2*a^2) + (12*I*Sqrt[a + a*Cos[x]]*PolyLog[2, (-I)*E^((I*x)/2)]*Sec[x/2])/a^2 + (3*I*x^2*Sqrt[a + a*Cos[x]]*PolyLog[2, (-I)*E^((I*x)/2)]*Sec[x/2])/(2*a^2) - (12*I*Sqrt[a + a*Cos[x]]*PolyLog[2, I*E^((I*x)/2)]*Sec[x/2])/a^2 - (3*I*x^2*Sqrt[a + a*Cos[x]]*PolyLog[2, I*E^((I*x)/2)]*Sec[x/2])/(2*a^2) - (6*x*Sqrt[a + a*Cos[x]]*PolyLog[3, (-I)*E^((I*x)/2)]*Sec[x/2])/a^2 + (6*x*Sqrt[a + a*Cos[x]]*PolyLog[3, I*E^((I*x)/2)]*Sec[x/2])/a^2 - (12*I*Sqrt[a + a*Cos[x]]*PolyLog[4, (-I)*E^((I*x)/2)]*Sec[x/2])/a^2 + (12*I*Sqrt[a + a*Cos[x]]*PolyLog[4, I*E^((I*x)/2)]*Sec[x/2])/a^2 - (3*x^2*Sqrt[a + a*Cos[x]]*Sec[x/2]^2)/(2*a^2) + (x^3*Sqrt[a + a*Cos[x]]*Sec[x/2]^2*Tan[x/2])/(4*a^2)}
{x^2/(a + a*Cos[x])^(3/2), x, 8, -((I*x^2*ArcTan[E^((I*x)/2)]*Sqrt[a + a*Cos[x]]*Sec[x/2])/(2*a^2)) + (2*ArcTanh[Sin[x/2]]*Sqrt[a + a*Cos[x]]*Sec[x/2])/a^2 + (I*x*Sqrt[a + a*Cos[x]]*PolyLog[2, (-I)*E^((I*x)/2)]*Sec[x/2])/a^2 - (I*x*Sqrt[a + a*Cos[x]]*PolyLog[2, I*E^((I*x)/2)]*Sec[x/2])/a^2 - (2*Sqrt[a + a*Cos[x]]*PolyLog[3, (-I)*E^((I*x)/2)]*Sec[x/2])/a^2 + (2*Sqrt[a + a*Cos[x]]*PolyLog[3, I*E^((I*x)/2)]*Sec[x/2])/a^2 - (x*Sqrt[a + a*Cos[x]]*Sec[x/2]^2)/a^2 + (x^2*Sqrt[a + a*Cos[x]]*Sec[x/2]^2*Tan[x/2])/(4*a^2)}
{x/(a + a*Cos[x])^(3/2), x, 5, -((I*x*ArcTan[E^((I*x)/2)]*Sqrt[a + a*Cos[x]]*Sec[x/2])/(2*a^2)) + (I*Sqrt[a + a*Cos[x]]*PolyLog[2, (-I)*E^((I*x)/2)]*Sec[x/2])/(2*a^2) - (I*Sqrt[a + a*Cos[x]]*PolyLog[2, I*E^((I*x)/2)]*Sec[x/2])/(2*a^2) - (Sqrt[a + a*Cos[x]]*Sec[x/2]^2)/(2*a^2) + (x*Sqrt[a + a*Cos[x]]*Sec[x/2]^2*Tan[x/2])/(4*a^2)}
{1/(x*(a + a*Cos[x])^(3/2)), x, 1, (Sqrt[a + a*Cos[x]]*Int[Sec[x/2]^3/x, x]*Sec[x/2])/(4*a^2)}


(* Integrands of the form x^m*(a-a*Cos[x])^n where m is an integer and n is a half-integer *)
{x^3*Sqrt[a - a*Cos[x]], x, 5, -96*Sqrt[a - a*Cos[x]] + 12*x^2*Sqrt[a - a*Cos[x]] + 48*x*Sqrt[a - a*Cos[x]]*Cot[x/2] - 2*x^3*Sqrt[a - a*Cos[x]]*Cot[x/2]}
{x^2*Sqrt[a - a*Cos[x]], x, 4, 8*x*Sqrt[a - a*Cos[x]] + 16*Sqrt[a - a*Cos[x]]*Cot[x/2] - 2*x^2*Sqrt[a - a*Cos[x]]*Cot[x/2]}
{x*Sqrt[a - a*Cos[x]], x, 3, 4*Sqrt[a - a*Cos[x]] - 2*x*Sqrt[a - a*Cos[x]]*Cot[x/2]}
{Sqrt[a - a*Cos[x]], x, 1, -((2*a*Sin[x])/Sqrt[a - a*Cos[x]])}
{Sqrt[a - a*Cos[x]]/x, x, 2, Sqrt[a - a*Cos[x]]*Csc[x/2]*SinIntegral[x/2]}
{Sqrt[a - a*Cos[x]]/x^2, x, 3, -(Sqrt[a - a*Cos[x]]/x) + (1/2)*Sqrt[a - a*Cos[x]]*CosIntegral[x/2]*Csc[x/2]}
{Sqrt[a - a*Cos[x]]/x^3, x, 4, -(Sqrt[a - a*Cos[x]]/(2*x^2)) - (Sqrt[a - a*Cos[x]]*Cot[x/2])/(4*x) - (1/8)*Sqrt[a - a*Cos[x]]*Csc[x/2]*SinIntegral[x/2]}

{x^3/Sqrt[a - a*Cos[x]], x, 8, -((2*x^3*ArcTanh[E^((I*x)/2)]*Sqrt[a - a*Cos[x]]*Csc[x/2])/a) + (6*I*x^2*Sqrt[a - a*Cos[x]]*Csc[x/2]*PolyLog[2, -E^((I*x)/2)])/a - (6*I*x^2*Sqrt[a - a*Cos[x]]*Csc[x/2]*PolyLog[2, E^((I*x)/2)])/a - (24*x*Sqrt[a - a*Cos[x]]*Csc[x/2]*PolyLog[3, -E^((I*x)/2)])/a + (24*x*Sqrt[a - a*Cos[x]]*Csc[x/2]*PolyLog[3, E^((I*x)/2)])/a - (48*I*Sqrt[a - a*Cos[x]]*Csc[x/2]*PolyLog[4, -E^((I*x)/2)])/a + (48*I*Sqrt[a - a*Cos[x]]*Csc[x/2]*PolyLog[4, E^((I*x)/2)])/a}
{x^2/Sqrt[a - a*Cos[x]], x, 6, -((2*x^2*ArcTanh[E^((I*x)/2)]*Sqrt[a - a*Cos[x]]*Csc[x/2])/a) + (4*I*x*Sqrt[a - a*Cos[x]]*Csc[x/2]*PolyLog[2, -E^((I*x)/2)])/a - (4*I*x*Sqrt[a - a*Cos[x]]*Csc[x/2]*PolyLog[2, E^((I*x)/2)])/a - (8*Sqrt[a - a*Cos[x]]*Csc[x/2]*PolyLog[3, -E^((I*x)/2)])/a + (8*Sqrt[a - a*Cos[x]]*Csc[x/2]*PolyLog[3, E^((I*x)/2)])/a}
{x/Sqrt[a - a*Cos[x]], x, 4, -((2*x*ArcTanh[E^((I*x)/2)]*Sqrt[a - a*Cos[x]]*Csc[x/2])/a) + (2*I*Sqrt[a - a*Cos[x]]*Csc[x/2]*PolyLog[2, -E^((I*x)/2)])/a - (2*I*Sqrt[a - a*Cos[x]]*Csc[x/2]*PolyLog[2, E^((I*x)/2)])/a}
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

{x^3/Sqrt[a + a*Cos[c + d*x]], x, 8, -((2*I*x^3*ArcTan[E^((I*c)/2 + (I*d*x)/2)]*Sqrt[a + a*Cos[c + d*x]]*Sec[c/2 + (d*x)/2])/(a*d)) + (6*I*x^2*Sqrt[a + a*Cos[c + d*x]]*PolyLog[2, (-I)*E^((1/2)*I*(c + d*x))]*Sec[c/2 + (d*x)/2])/(a*d^2) - (6*I*x^2*Sqrt[a + a*Cos[c + d*x]]*PolyLog[2, I*E^((1/2)*I*(c + d*x))]*Sec[c/2 + (d*x)/2])/(a*d^2) - (24*x*Sqrt[a + a*Cos[c + d*x]]*PolyLog[3, (-I)*E^((1/2)*I*(c + d*x))]*Sec[c/2 + (d*x)/2])/(a*d^3) + (24*x*Sqrt[a + a*Cos[c + d*x]]*PolyLog[3, I*E^((1/2)*I*(c + d*x))]*Sec[c/2 + (d*x)/2])/(a*d^3) - (48*I*Sqrt[a + a*Cos[c + d*x]]*PolyLog[4, (-I)*E^((1/2)*I*(c + d*x))]*Sec[c/2 + (d*x)/2])/(a*d^4) + (48*I*Sqrt[a + a*Cos[c + d*x]]*PolyLog[4, I*E^((1/2)*I*(c + d*x))]*Sec[c/2 + (d*x)/2])/(a*d^4)}
{x^2/Sqrt[a + a*Cos[c + d*x]], x, 6, -((2*I*x^2*ArcTan[E^((I*c)/2 + (I*d*x)/2)]*Sqrt[a + a*Cos[c + d*x]]*Sec[c/2 + (d*x)/2])/(a*d)) + (4*I*x*Sqrt[a + a*Cos[c + d*x]]*PolyLog[2, (-I)*E^((1/2)*I*(c + d*x))]*Sec[c/2 + (d*x)/2])/(a*d^2) - (4*I*x*Sqrt[a + a*Cos[c + d*x]]*PolyLog[2, I*E^((1/2)*I*(c + d*x))]*Sec[c/2 + (d*x)/2])/(a*d^2) - (8*Sqrt[a + a*Cos[c + d*x]]*PolyLog[3, (-I)*E^((1/2)*I*(c + d*x))]*Sec[c/2 + (d*x)/2])/(a*d^3) + (8*Sqrt[a + a*Cos[c + d*x]]*PolyLog[3, I*E^((1/2)*I*(c + d*x))]*Sec[c/2 + (d*x)/2])/(a*d^3)}
{x/Sqrt[a + a*Cos[c + d*x]], x, 4, -((2*I*x*ArcTan[E^((I*c)/2 + (I*d*x)/2)]*Sqrt[a + a*Cos[c + d*x]]*Sec[c/2 + (d*x)/2])/(a*d)) + (2*I*Sqrt[a + a*Cos[c + d*x]]*PolyLog[2, (-I)*E^((1/2)*I*(c + d*x))]*Sec[c/2 + (d*x)/2])/(a*d^2) - (2*I*Sqrt[a + a*Cos[c + d*x]]*PolyLog[2, I*E^((1/2)*I*(c + d*x))]*Sec[c/2 + (d*x)/2])/(a*d^2)}
{1/Sqrt[a + a*Cos[c + d*x]], x, 1, (2*ArcTanh[Sin[(1/2)*(c + d*x)]]*Cos[(1/2)*(c + d*x)])/(d*Sqrt[a + a*Cos[c + d*x]])}
{1/(x*Sqrt[a + a*Cos[c + d*x]]), x, 1, (Sqrt[a + a*Cos[c + d*x]]*Int[Sec[c/2 + (d*x)/2]/x, x]*Sec[c/2 + (d*x)/2])/(2*a)}


(* Used to hang Rubi *)
{(a + a*Cos[c + d*x])^(1/3)/x, x, 1, (Sqrt[a + a*Cos[c + d*x]]*Int[Cos[c/2 + (d*x)/2]^(2/3)/x, x]*Sec[c/2 + (d*x)/2])/(2^(1/6)*a^(1/6))}


(* ::Subsection::Closed:: *)
(*Integrands of the form x^m (a+b Cos[c+d x]^2)^p*)


{x/(a + b*Cos[x]^2), x, 9, -((I*x*Log[1 + (b*E^(2*I*x))/(2*a + b - 2*Sqrt[a]*Sqrt[a + b])])/(2*Sqrt[a]*Sqrt[a + b])) + (I*x*Log[1 + (b*E^(2*I*x))/(2*a + b + 2*Sqrt[a]*Sqrt[a + b])])/(2*Sqrt[a]*Sqrt[a + b]) - PolyLog[2, -((b*E^(2*I*x))/(2*a + b - 2*Sqrt[a]*Sqrt[a + b]))]/(4*Sqrt[a]*Sqrt[a + b]) + PolyLog[2, -((b*E^(2*I*x))/(2*a + b + 2*Sqrt[a]*Sqrt[a + b]))]/(4*Sqrt[a]*Sqrt[a + b])}
{x^2/(a + b*Cos[x]^2), x, 11, -((I*x^2*Log[1 + (b*E^(2*I*x))/(2*a + b - 2*Sqrt[a]*Sqrt[a + b])])/(2*Sqrt[a]*Sqrt[a + b])) + (I*x^2*Log[1 + (b*E^(2*I*x))/(2*a + b + 2*Sqrt[a]*Sqrt[a + b])])/(2*Sqrt[a]*Sqrt[a + b]) - (x*PolyLog[2, -((b*E^(2*I*x))/(2*a + b - 2*Sqrt[a]*Sqrt[a + b]))])/(2*Sqrt[a]*Sqrt[a + b]) + (x*PolyLog[2, -((b*E^(2*I*x))/(2*a + b + 2*Sqrt[a]*Sqrt[a + b]))])/(2*Sqrt[a]*Sqrt[a + b]) - (I*PolyLog[3, -((b*E^(2*I*x))/(2*a + b - 2*Sqrt[a]*Sqrt[a + b]))])/(4*Sqrt[a]*Sqrt[a + b]) + (I*PolyLog[3, -((b*E^(2*I*x))/(2*a + b + 2*Sqrt[a]*Sqrt[a + b]))])/(4*Sqrt[a]*Sqrt[a + b])}
{x^3/(a + b*Cos[x]^2), x, 13, -((I*x^3*Log[1 + (b*E^(2*I*x))/(2*a + b - 2*Sqrt[a]*Sqrt[a + b])])/(2*Sqrt[a]*Sqrt[a + b])) + (I*x^3*Log[1 + (b*E^(2*I*x))/(2*a + b + 2*Sqrt[a]*Sqrt[a + b])])/(2*Sqrt[a]*Sqrt[a + b]) - (3*x^2*PolyLog[2, -((b*E^(2*I*x))/(2*a + b - 2*Sqrt[a]*Sqrt[a + b]))])/(4*Sqrt[a]*Sqrt[a + b]) + (3*x^2*PolyLog[2, -((b*E^(2*I*x))/(2*a + b + 2*Sqrt[a]*Sqrt[a + b]))])/(4*Sqrt[a]*Sqrt[a + b]) - (3*I*x*PolyLog[3, -((b*E^(2*I*x))/(2*a + b - 2*Sqrt[a]*Sqrt[a + b]))])/(4*Sqrt[a]*Sqrt[a + b]) + (3*I*x*PolyLog[3, -((b*E^(2*I*x))/(2*a + b + 2*Sqrt[a]*Sqrt[a + b]))])/(4*Sqrt[a]*Sqrt[a + b]) + (3*PolyLog[4, -((b*E^(2*I*x))/(2*a + b - 2*Sqrt[a]*Sqrt[a + b]))])/(8*Sqrt[a]*Sqrt[a + b]) - (3*PolyLog[4, -((b*E^(2*I*x))/(2*a + b + 2*Sqrt[a]*Sqrt[a + b]))])/(8*Sqrt[a]*Sqrt[a + b])}


{x/(a + b*Cos[c + d*x]^2)^2, x, 13, -((I*(2*a + b)*x*Log[1 + (b*E^(2*I*c + 2*I*d*x))/(2*a + b - 2*Sqrt[a]*Sqrt[a + b])])/(4*a^(3/2)*(a + b)^(3/2)*d)) + (I*(2*a + b)*x*Log[1 + (b*E^(2*I*c + 2*I*d*x))/(2*a + b + 2*Sqrt[a]*Sqrt[a + b])])/(4*a^(3/2)*(a + b)^(3/2)*d) - Log[2*a + b + b*Cos[2*c + 2*d*x]]/(4*a*(a + b)*d^2) - ((2*a + b)*PolyLog[2, -((b*E^(2*I*c + 2*I*d*x))/(2*a + b - 2*Sqrt[a]*Sqrt[a + b]))])/(8*a^(3/2)*(a + b)^(3/2)*d^2) + ((2*a + b)*PolyLog[2, -((b*E^(2*I*c + 2*I*d*x))/(2*a + b + 2*Sqrt[a]*Sqrt[a + b]))])/(8*a^(3/2)*(a + b)^(3/2)*d^2) - (b*x*Sin[2*c + 2*d*x])/(2*a*(a + b)*d*(2*a + b + b*Cos[2*c + 2*d*x]))}
