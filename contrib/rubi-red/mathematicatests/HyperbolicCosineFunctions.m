(* ::Package:: *)

(* ::Title:: *)
(*Integration Problems Involving Hyperbolic Cosines*)


(* ::Subsection::Closed:: *)
(*Cosh[a+b x]^n*)


(* Integrands of the form Cosh[a+b*x]^n where n is an integer *)
{Cosh[a + b*x], x, 1, Sinh[a + b*x]/b}
{Cosh[a + b*x]^2, x, 1, x/2 + (Cosh[a + b*x]*Sinh[a + b*x])/(2*b)}
{Cosh[a + b*x]^3, x, 2, Sinh[a + b*x]/b + Sinh[a + b*x]^3/(3*b)}
{Cosh[a + b*x]^4, x, 2, (3*x)/8 + (3*Cosh[a + b*x]*Sinh[a + b*x])/(8*b) + (Cosh[a + b*x]^3*Sinh[a + b*x])/(4*b)}
{Cosh[a + b*x]^5, x, 2, Sinh[a + b*x]/b + (2*Sinh[a + b*x]^3)/(3*b) + Sinh[a + b*x]^5/(5*b)}


(* Integrands of the form Cosh[a+b*x]^n where n is a half-integer *)
{Cosh[a + b*x]^(1/2), x, 1, -((2*I*EllipticE[(1/2)*I*(a + b*x), 2])/b)}
{Cosh[a + b*x]^(3/2), x, 2, -((2*I*EllipticF[(1/2)*I*(a + b*x), 2])/(3*b)) + (2*Sqrt[Cosh[a + b*x]]*Sinh[a + b*x])/(3*b)}
{Cosh[a + b*x]^(5/2), x, 2, -((6*I*EllipticE[(1/2)*I*(a + b*x), 2])/(5*b)) + (2*Cosh[a + b*x]^(3/2)*Sinh[a + b*x])/(5*b)}

{1/Cosh[a + b*x]^(1/2), x, 1, -((2*I*EllipticF[(1/2)*I*(a + b*x), 2])/b)}
{1/Cosh[a + b*x]^(3/2), x, 2, (2*I*EllipticE[(1/2)*I*(a + b*x), 2])/b + (2*Sinh[a + b*x])/(b*Sqrt[Cosh[a + b*x]])}
{1/Cosh[a + b*x]^(5/2), x, 2, -((2*I*EllipticF[(1/2)*I*(a + b*x), 2])/(3*b)) + (2*Sinh[a + b*x])/(3*b*Cosh[a + b*x]^(3/2))}


(* ::Subsection::Closed:: *)
(*x^m Cosh[a+b x]^n*)


(* Integrands of the form x^m*Cosh[a+b*x]^n where m and n are integers *)
{x*Cosh[a + b*x], x, 2, -(Cosh[a + b*x]/b^2) + (x*Sinh[a + b*x])/b}
{x*Cosh[a + b*x]^2, x, 2, x^2/4 - Cosh[a + b*x]^2/(4*b^2) + (x*Cosh[a + b*x]*Sinh[a + b*x])/(2*b)}
{x*Cosh[a + b*x]^3, x, 3, -((2*Cosh[a + b*x])/(3*b^2)) - Cosh[a + b*x]^3/(9*b^2) + (2*x*Sinh[a + b*x])/(3*b) + (x*Cosh[a + b*x]^2*Sinh[a + b*x])/(3*b)}

{x^2*Cosh[a + b*x], x, 3, -((2*x*Cosh[a + b*x])/b^2) + (2*Sinh[a + b*x])/b^3 + (x^2*Sinh[a + b*x])/b}
{x^2*Cosh[a + b*x]^2, x, 3, x/(4*b^2) + x^3/6 - (x*Cosh[a + b*x]^2)/(2*b^2) + (Cosh[a + b*x]*Sinh[a + b*x])/(4*b^3) + (x^2*Cosh[a + b*x]*Sinh[a + b*x])/(2*b)}
{x^2*Cosh[a + b*x]^3, x, 6, -((4*x*Cosh[a + b*x])/(3*b^2)) - (2*x*Cosh[a + b*x]^3)/(9*b^2) + (14*Sinh[a + b*x])/(9*b^3) + (2*x^2*Sinh[a + b*x])/(3*b) + (x^2*Cosh[a + b*x]^2*Sinh[a + b*x])/(3*b) + (2*Sinh[a + b*x]^3)/(27*b^3)}
{x^2*Cosh[a + b*x]^4, x, 6, (15*x)/(64*b^2) + x^3/8 - (3*x*Cosh[a + b*x]^2)/(8*b^2) - (x*Cosh[a + b*x]^4)/(8*b^2) + (15*Cosh[a + b*x]*Sinh[a + b*x])/(64*b^3) + (3*x^2*Cosh[a + b*x]*Sinh[a + b*x])/(8*b) + (Cosh[a + b*x]^3*Sinh[a + b*x])/(32*b^3) + (x^2*Cosh[a + b*x]^3*Sinh[a + b*x])/(4*b)}

{x^3*Cosh[a + b*x], x, 4, -((6*Cosh[a + b*x])/b^4) - (3*x^2*Cosh[a + b*x])/b^2 + (6*x*Sinh[a + b*x])/b^3 + (x^3*Sinh[a + b*x])/b}
{x^3*Cosh[a + b*x]^2, x, 4, (3*x^2)/(8*b^2) + x^4/8 - (3*Cosh[a + b*x]^2)/(8*b^4) - (3*x^2*Cosh[a + b*x]^2)/(4*b^2) + (3*x*Cosh[a + b*x]*Sinh[a + b*x])/(4*b^3) + (x^3*Cosh[a + b*x]*Sinh[a + b*x])/(2*b)}
{x^3*Cosh[a + b*x]^3, x, 8, -((40*Cosh[a + b*x])/(9*b^4)) - (2*x^2*Cosh[a + b*x])/b^2 - (2*Cosh[a + b*x]^3)/(27*b^4) - (x^2*Cosh[a + b*x]^3)/(3*b^2) + (40*x*Sinh[a + b*x])/(9*b^3) + (2*x^3*Sinh[a + b*x])/(3*b) + (2*x*Cosh[a + b*x]^2*Sinh[a + b*x])/(9*b^3) + (x^3*Cosh[a + b*x]^2*Sinh[a + b*x])/(3*b)}

{x^5*Cosh[a + b*x], x, 6, -((120*Cosh[a + b*x])/b^6) - (60*x^2*Cosh[a + b*x])/b^4 - (5*x^4*Cosh[a + b*x])/b^2 + (120*x*Sinh[a + b*x])/b^5 + (20*x^3*Sinh[a + b*x])/b^3 + (x^5*Sinh[a + b*x])/b}

{Cosh[a + b*x^n]/x, x, 3, (Cosh[a]*CoshIntegral[b*x^n])/n + (Sinh[a]*SinhIntegral[b*x^n])/n}
{Cosh[a + b*x^n]^2/x, x, 7, (Cosh[2*a]*CoshIntegral[2*b*x^n])/(2*n) + Log[x]/2 + (Sinh[2*a]*SinhIntegral[2*b*x^n])/(2*n), (Cosh[2*a]*CoshIntegral[2*b*x^n])/(2*n) + Log[x^n]/(2*n) + (Sinh[2*a]*SinhIntegral[2*b*x^n])/(2*n)}
{Cosh[a + b*x^n]^3/x, x, 9, (3*Cosh[a]*CoshIntegral[b*x^n])/(4*n) + (Cosh[3*a]*CoshIntegral[3*b*x^n])/(4*n) + (3*Sinh[a]*SinhIntegral[b*x^n])/(4*n) + (Sinh[3*a]*SinhIntegral[3*b*x^n])/(4*n)}

{Cosh[a + b*x]/x^2, x, 4, -(Cosh[a + b*x]/x) + b*CoshIntegral[b*x]*Sinh[a] + b*Cosh[a]*SinhIntegral[b*x]}
{Cosh[a + b*x]^2/x^2, x, 7, -(1/(2*x)) - Cosh[2*a + 2*b*x]/(2*x) + b*CoshIntegral[2*b*x]*Sinh[2*a] + b*Cosh[2*a]*SinhIntegral[2*b*x]}
{Cosh[a + b*x]^3/x^2, x, 10, -((3*Cosh[a + b*x])/(4*x)) - Cosh[3*a + 3*b*x]/(4*x) + (3/4)*b*CoshIntegral[b*x]*Sinh[a] + (3/4)*b*CoshIntegral[3*b*x]*Sinh[3*a] + (3/4)*b*Cosh[a]*SinhIntegral[b*x] + (3/4)*b*Cosh[3*a]*SinhIntegral[3*b*x]}

{Cosh[a + b*x]/x^3, x, 5, -(Cosh[a + b*x]/(2*x^2)) + (1/2)*b^2*Cosh[a]*CoshIntegral[b*x] - (b*Sinh[a + b*x])/(2*x) + (1/2)*b^2*Sinh[a]*SinhIntegral[b*x]}
{Cosh[a + b*x]^2/x^3, x, 8, -(Cosh[a + b*x]^2/(2*x^2)) + b^2*Cosh[2*a]*CoshIntegral[2*b*x] - (b*Cosh[a + b*x]*Sinh[a + b*x])/x + b^2*Sinh[2*a]*SinhIntegral[2*b*x]}
{Cosh[a + b*x]^3/x^3, x, 12, -(Cosh[a + b*x]^3/(2*x^2)) + (3/8)*b^2*Cosh[a]*CoshIntegral[b*x] + (9/8)*b^2*Cosh[3*a]*CoshIntegral[3*b*x] - (3*b*Cosh[a + b*x]^2*Sinh[a + b*x])/(2*x) + (3/8)*b^2*Sinh[a]*SinhIntegral[b*x] + (9/8)*b^2*Sinh[3*a]*SinhIntegral[3*b*x]}


{Cosh[x]/Sqrt[x], x, 4, (1/2)*Sqrt[Pi]*Erf[Sqrt[x]] + (1/2)*Sqrt[Pi]*Erfi[Sqrt[x]]}
{Sqrt[x]*Cosh[x], x, 5, (1/4)*Sqrt[Pi]*Erf[Sqrt[x]] - (1/4)*Sqrt[Pi]*Erfi[Sqrt[x]] + Sqrt[x]*Sinh[x]}


{Cosh[x]^(3/2)/x^3, x, 1, -(Cosh[x]^(3/2)/(2*x^2)) - (3/8)*Int[1/(x*Sqrt[Cosh[x]]), x] + (9/8)*Int[Cosh[x]^(3/2)/x, x] - (3*Sqrt[Cosh[x]]*Sinh[x])/(4*x)}


(* ::Subsection::Closed:: *)
(*(a Cosh[a+b x]^n)^m*)


(* Integrands of the form Cosh[x]^m where m is a half-integer *)
{Cosh[x]^(7/2), x, 3, (-(10/21))*I*EllipticF[(I*x)/2, 2] + (10/21)*Sqrt[Cosh[x]]*Sinh[x] + (2/7)*Cosh[x]^(5/2)*Sinh[x]}
{Cosh[x]^(5/2), x, 2, (-(6/5))*I*EllipticE[(I*x)/2, 2] + (2/5)*Cosh[x]^(3/2)*Sinh[x]}
{Cosh[x]^(3/2),x, 2, (-(2/3))*I*EllipticF[(I*x)/2, 2] + (2/3)*Sqrt[Cosh[x]]*Sinh[x]}
{Cosh[x]^(1/2), x, 1, -2*I*EllipticE[(I*x)/2, 2]}
{1/Cosh[x]^(1/2), x, 1, -2*I*EllipticF[(I*x)/2, 2]}
{1/Cosh[x]^(3/2), x, 2, 2*I*EllipticE[(I*x)/2, 2] + (2*Sinh[x])/Sqrt[Cosh[x]]}
{1/Cosh[x]^(5/2), x, 2, (-(2/3))*I*EllipticF[(I*x)/2, 2] + (2*Sinh[x])/(3*Cosh[x]^(3/2))}
{1/Cosh[x]^(7/2), x, 3, (6/5)*I*EllipticE[(I*x)/2, 2] + (2*Sinh[x])/(5*Cosh[x]^(5/2)) + (6*Sinh[x])/(5*Sqrt[Cosh[x]])}


(* Integrands of the form (a*Cosh[x])^m where m is a half-integer *)
{(a*Cosh[x])^(7/2), x, 4, -((10*I*a^4*Sqrt[Cosh[x]]*EllipticF[(I*x)/2, 2])/(21*Sqrt[a*Cosh[x]])) + (10/21)*a^3*Sqrt[a*Cosh[x]]*Sinh[x] + (2/7)*a*(a*Cosh[x])^(5/2)*Sinh[x]}
{(a*Cosh[x])^(5/2), x, 3, -((6*I*a^2*Sqrt[a*Cosh[x]]*EllipticE[(I*x)/2, 2])/(5*Sqrt[Cosh[x]])) + (2/5)*a*(a*Cosh[x])^(3/2)*Sinh[x]}
{(a*Cosh[x])^(3/2),x, 3, -((2*I*a^2*Sqrt[Cosh[x]]*EllipticF[(I*x)/2, 2])/(3*Sqrt[a*Cosh[x]])) + (2/3)*a*Sqrt[a*Cosh[x]]*Sinh[x]}
{(a*Cosh[x])^(1/2), x, 2, -((2*I*Sqrt[a*Cosh[x]]*EllipticE[(I*x)/2, 2])/Sqrt[Cosh[x]])}
{1/(a*Cosh[x])^(1/2), x, 2, -((2*I*Sqrt[Cosh[x]]*EllipticF[(I*x)/2, 2])/Sqrt[a*Cosh[x]])}
{1/(a*Cosh[x])^(3/2), x, 3, (2*I*Sqrt[a*Cosh[x]]*EllipticE[(I*x)/2, 2])/(a^2*Sqrt[Cosh[x]]) + (2*Sinh[x])/(a*Sqrt[a*Cosh[x]])}
{1/(a*Cosh[x])^(5/2), x, 3, -((2*I*Sqrt[Cosh[x]]*EllipticF[(I*x)/2, 2])/(3*a^2*Sqrt[a*Cosh[x]])) + (2*Sinh[x])/(3*a*(a*Cosh[x])^(3/2))}
{1/(a*Cosh[x])^(7/2), x, 4, (6*I*Sqrt[a*Cosh[x]]*EllipticE[(I*x)/2, 2])/(5*a^4*Sqrt[Cosh[x]]) + (2*Sinh[x])/(5*a*(a*Cosh[x])^(5/2)) + (6*Sinh[x])/(5*a^3*Sqrt[a*Cosh[x]])}


(* Integrands of the form (a*Cosh[x]^2)^m where m is a half-integer *)
{(a*Cosh[x]^2)^(5/2),x, 3, a^2*Sqrt[a*Cosh[x]^2]*Tanh[x] + (2/3)*a^2*Sqrt[a*Cosh[x]^2]*Sinh[x]^2*Tanh[x] + (1/5)*a^2*Sqrt[a*Cosh[x]^2]*Sinh[x]^4*Tanh[x]}
{(a*Cosh[x]^2)^(3/2),x, 3, a*Sqrt[a*Cosh[x]^2]*Tanh[x] + (1/3)*a*Sqrt[a*Cosh[x]^2]*Sinh[x]^2*Tanh[x]}
{(a*Cosh[x]^2)^(1/2), x, 2, Sqrt[a*Cosh[x]^2]*Tanh[x]}
{1/(a*Cosh[x]^2)^(1/2), x, 2, (ArcTan[Sinh[x]]*Cosh[x])/Sqrt[a*Cosh[x]^2]}
{1/(a*Cosh[x]^2)^(3/2), x, 3, (ArcTan[Sinh[x]]*Cosh[x])/(2*a*Sqrt[a*Cosh[x]^2]) + Tanh[x]/(2*a*Sqrt[a*Cosh[x]^2])}
{1/(a*Cosh[x]^2)^(5/2), x, 4, (3*ArcTan[Sinh[x]]*Cosh[x])/(8*a^2*Sqrt[a*Cosh[x]^2]) + (3*Tanh[x])/(8*a^2*Sqrt[a*Cosh[x]^2]) + (Sech[x]^2*Tanh[x])/(4*a^2*Sqrt[a*Cosh[x]^2])}


(* Integrands of the form (a*Cosh[x]^4)^m where m is a half-integer *)
{(a*Cosh[x]^3)^(5/2),x, 6, -((2*a^2*Sqrt[a*Cosh[x]^3]*(195*I*EllipticF[(I*x)/2, 2] - 195*Sqrt[Cosh[x]]*Sinh[x] - 117*Cosh[x]^(5/2)*Sinh[x] - 91*Cosh[x]^(9/2)*Sinh[x] - 77*Cosh[x]^(13/2)*Sinh[x]))/(1155*Cosh[x]^(3/2)))}
{(a*Cosh[x]^3)^(3/2),x, 4, -((2*a*Sqrt[a*Cosh[x]^3]*(21*I*EllipticE[(I*x)/2, 2] - 7*Cosh[x]^(3/2)*Sinh[x] - 5*Cosh[x]^(7/2)*Sinh[x]))/(45*Cosh[x]^(3/2)))}
{(a*Cosh[x]^3)^(1/2), x, 3, -((2*Sqrt[a*Cosh[x]^3]*(I*EllipticF[(I*x)/2, 2] - Sqrt[Cosh[x]]*Sinh[x]))/(3*Cosh[x]^(3/2)))}
{1/(a*Cosh[x]^3)^(1/2), x, 3, (2*Cosh[x]*(I*Sqrt[Cosh[x]]*EllipticE[(I*x)/2, 2] + Sinh[x]))/Sqrt[a*Cosh[x]^3]}
{1/(a*Cosh[x]^3)^(3/2),x, 4, -((2*Sech[x]^2*(5*Cosh[x]^2*(I*Cosh[x]^(3/2)*EllipticF[(I*x)/2, 2] - Sinh[x]) - 3*Sinh[x]))/(21*a*Sqrt[a*Cosh[x]^3]))}
{1/(a*Cosh[x]^3)^(5/2),x, 6, (2*Sech[x]^5*(45*Sinh[x] + 11*Cosh[x]^2*(5*Sinh[x] + 7*Cosh[x]^2*(Sinh[x] + 3*Cosh[x]^2*(I*Sqrt[Cosh[x]]*EllipticE[(I*x)/2, 2] + Sinh[x])))))/(585*a^2*Sqrt[a*Cosh[x]^3])}


(* Integrands of the form (a*Cosh[x]^4)^m where m is a half-integer *)
{(a*Cosh[x]^4)^(5/2),x, 6, (63/256)*a^2*x*Sqrt[a*Cosh[x]^4]*Sech[x]^2 + (21/128)*a^2*Cosh[x]*Sqrt[a*Cosh[x]^4]*Sinh[x] + (21/160)*a^2*Cosh[x]^3*Sqrt[a*Cosh[x]^4]*Sinh[x] + (9/80)*a^2*Cosh[x]^5*Sqrt[a*Cosh[x]^4]*Sinh[x] + (1/10)*a^2*Cosh[x]^7*Sqrt[a*Cosh[x]^4]*Sinh[x] + (63/256)*a^2*Sqrt[a*Cosh[x]^4]*Tanh[x]}
{(a*Cosh[x]^4)^(3/2),x, 4, (5/16)*a*x*Sqrt[a*Cosh[x]^4]*Sech[x]^2 + (5/24)*a*Cosh[x]*Sqrt[a*Cosh[x]^4]*Sinh[x] + (1/6)*a*Cosh[x]^3*Sqrt[a*Cosh[x]^4]*Sinh[x] + (5/16)*a*Sqrt[a*Cosh[x]^4]*Tanh[x]}
{(a*Cosh[x]^4)^(1/2), x, 2, (1/2)*x*Sqrt[a*Cosh[x]^4]*Sech[x]^2 + (1/2)*Sqrt[a*Cosh[x]^4]*Tanh[x]}
{1/(a*Cosh[x]^4)^(1/2), x, 2, (Cosh[x]*Sinh[x])/Sqrt[a*Cosh[x]^4]}
{1/(a*Cosh[x]^4)^(3/2),x, 4, (Cosh[x]*Sinh[x])/(a*Sqrt[a*Cosh[x]^4]) - (2*Sinh[x]^2*Tanh[x])/(3*a*Sqrt[a*Cosh[x]^4]) + (Sinh[x]^2*Tanh[x]^3)/(5*a*Sqrt[a*Cosh[x]^4])}
{1/(a*Cosh[x]^4)^(5/2),x, 4, (Cosh[x]*Sinh[x])/(a^2*Sqrt[a*Cosh[x]^4]) - (4*Sinh[x]^2*Tanh[x])/(3*a^2*Sqrt[a*Cosh[x]^4]) + (6*Sinh[x]^2*Tanh[x]^3)/(5*a^2*Sqrt[a*Cosh[x]^4]) - (4*Sinh[x]^2*Tanh[x]^5)/(7*a^2*Sqrt[a*Cosh[x]^4]) + (Sinh[x]^2*Tanh[x]^7)/(9*a^2*Sqrt[a*Cosh[x]^4])}


(* ::Subsection::Closed:: *)
(*(a+b Cosh[c+d x])^n*)


(* Integrands of the form (a+b*Cosh[c+d*x])^n where n is an integer *)
{(a + b*Cosh[c + d*x])^4, x, 8, a^4*x + 3*a^2*b^2*x + (3*b^4*x)/8 + (4*a^3*b*Sinh[c + d*x])/d + (4*a*b^3*Sinh[c + d*x])/d + (3*a^2*b^2*Cosh[c + d*x]*Sinh[c + d*x])/d + (3*b^4*Cosh[c + d*x]*Sinh[c + d*x])/(8*d) + (b^4*Cosh[c + d*x]^3*Sinh[c + d*x])/(4*d) + (4*a*b^3*Sinh[c + d*x]^3)/(3*d)}
{(a + b*Cosh[c + d*x])^3, x, 6, a^3*x + (3/2)*a*b^2*x + (3*a^2*b*Sinh[c + d*x])/d + (b^3*Sinh[c + d*x])/d + (3*a*b^2*Cosh[c + d*x]*Sinh[c + d*x])/(2*d) + (b^3*Sinh[c + d*x]^3)/(3*d)}
{(a + b*Cosh[c + d*x])^2, x, 4, a^2*x + (b^2*x)/2 + (2*a*b*Sinh[c + d*x])/d + (b^2*Cosh[c + d*x]*Sinh[c + d*x])/(2*d)}
{(a + b*Cosh[c + d*x]), x, 2, a*x + (b*Sinh[c + d*x])/d}
{1/(a + b*Cosh[c + d*x]), x, 1, (2*ArcTanh[((a - b)*Tanh[(1/2)*(c + d*x)])/Sqrt[a^2 - b^2]])/(Sqrt[a^2 - b^2]*d)}
{1/(a + b*Cosh[c + d*x])^2, x, 2, (2*a*ArcTanh[((a - b)*Tanh[(1/2)*(c + d*x)])/Sqrt[a^2 - b^2]])/((a^2 - b^2)^(3/2)*d) - (b*Sinh[c + d*x])/((a^2 - b^2)*d*(a + b*Cosh[c + d*x]))}
{1/(a + b*Cosh[c + d*x])^3, x, 3, ((2*a^2 + b^2)*ArcTanh[((a - b)*Tanh[(1/2)*(c + d*x)])/Sqrt[a^2 - b^2]])/((a^2 - b^2)^(5/2)*d) - (b*Sinh[c + d*x])/(2*(a^2 - b^2)*d*(a + b*Cosh[c + d*x])^2) - (3*a*b*Sinh[c + d*x])/(2*(a^2 - b^2)^2*d*(a + b*Cosh[c + d*x]))}
{1/(a + b*Cosh[c + d*x])^4, x, 4, (a*(2*a^2 + 3*b^2)*ArcTanh[((a - b)*Tanh[(1/2)*(c + d*x)])/Sqrt[a^2 - b^2]])/((a^2 - b^2)^(7/2)*d) - (b*Sinh[c + d*x])/(3*(a^2 - b^2)*d*(a + b*Cosh[c + d*x])^3) - (5*a*b*Sinh[c + d*x])/(6*(a^2 - b^2)^2*d*(a + b*Cosh[c + d*x])^2) - (b*(11*a^2 + 4*b^2)*Sinh[c + d*x])/(6*(a^2 - b^2)^3*d*(a + b*Cosh[c + d*x]))}

{1/(1 + Cosh[c + d*x]), x, 1, Sinh[c + d*x]/(d*(1 + Cosh[c + d*x]))}
{1/(1 + Cosh[c + d*x])^2, x, 2, Sinh[c + d*x]/(3*d*(1 + Cosh[c + d*x])^2) + Sinh[c + d*x]/(3*d*(1 + Cosh[c + d*x]))}
{1/(1 + Cosh[c + d*x])^3, x, 3, Sinh[c + d*x]/(5*d*(1 + Cosh[c + d*x])^3) + (2*Sinh[c + d*x])/(15*d*(1 + Cosh[c + d*x])^2) + (2*Sinh[c + d*x])/(15*d*(1 + Cosh[c + d*x]))}
{1/(1 + Cosh[c + d*x])^4, x, 4, Sinh[c + d*x]/(7*d*(1 + Cosh[c + d*x])^4) + (3*Sinh[c + d*x])/(35*d*(1 + Cosh[c + d*x])^3) + (2*Sinh[c + d*x])/(35*d*(1 + Cosh[c + d*x])^2) + (2*Sinh[c + d*x])/(35*d*(1 + Cosh[c + d*x]))}

{1/(1 - Cosh[c + d*x]), x, 1, -(Sinh[c + d*x]/(d*(1 - Cosh[c + d*x])))}
{1/(1 - Cosh[c + d*x])^2, x, 2, -(Sinh[c + d*x]/(3*d*(1 - Cosh[c + d*x])^2)) - Sinh[c + d*x]/(3*d*(1 - Cosh[c + d*x]))}
{1/(1 - Cosh[c + d*x])^3, x, 3, -(Sinh[c + d*x]/(5*d*(1 - Cosh[c + d*x])^3)) - (2*Sinh[c + d*x])/(15*d*(1 - Cosh[c + d*x])^2) - (2*Sinh[c + d*x])/(15*d*(1 - Cosh[c + d*x]))}
{1/(1 - Cosh[c + d*x])^4, x, 4, -(Sinh[c + d*x]/(7*d*(1 - Cosh[c + d*x])^4)) - (3*Sinh[c + d*x])/(35*d*(1 - Cosh[c + d*x])^3) - (2*Sinh[c + d*x])/(35*d*(1 - Cosh[c + d*x])^2) - (2*Sinh[c + d*x])/(35*d*(1 - Cosh[c + d*x]))}

{1/(3 + 5*Cosh[c + d*x]), x, 1, ArcTan[(1/2)*Tanh[(1/2)*(c + d*x)]]/(2*d)}
{1/(3 + 5*Cosh[c + d*x])^2, x, 2, -((3*ArcTan[(1/2)*Tanh[(1/2)*(c + d*x)]])/(32*d)) + (5*Sinh[c + d*x])/(16*d*(3 + 5*Cosh[c + d*x]))}
{1/(3 + 5*Cosh[c + d*x])^3, x, 3, (43*ArcTan[(1/2)*Tanh[(1/2)*(c + d*x)]])/(1024*d) + (5*Sinh[c + d*x])/(32*d*(3 + 5*Cosh[c + d*x])^2) - (45*Sinh[c + d*x])/(512*d*(3 + 5*Cosh[c + d*x]))}
{1/(3 + 5*Cosh[c + d*x])^4, x, 4, -((279*ArcTan[(1/2)*Tanh[(1/2)*(c + d*x)]])/(16384*d)) + (5*Sinh[c + d*x])/(48*d*(3 + 5*Cosh[c + d*x])^3) - (25*Sinh[c + d*x])/(512*d*(3 + 5*Cosh[c + d*x])^2) + (995*Sinh[c + d*x])/(24576*d*(3 + 5*Cosh[c + d*x]))}

{1/(5 + 3*Cosh[c + d*x]), x, 1, ArcTanh[(1/2)*Tanh[(1/2)*(c + d*x)]]/(2*d)}
{1/(5 + 3*Cosh[c + d*x])^2, x, 2, (5*ArcTanh[(1/2)*Tanh[(1/2)*(c + d*x)]])/(32*d) - (3*Sinh[c + d*x])/(16*d*(5 + 3*Cosh[c + d*x]))}
{1/(5 + 3*Cosh[c + d*x])^3, x, 3, (59*ArcTanh[(1/2)*Tanh[(1/2)*(c + d*x)]])/(1024*d) - (3*Sinh[c + d*x])/(32*d*(5 + 3*Cosh[c + d*x])^2) - (45*Sinh[c + d*x])/(512*d*(5 + 3*Cosh[c + d*x]))}
{1/(5 + 3*Cosh[c + d*x])^4, x, 4, (385*ArcTanh[(1/2)*Tanh[(1/2)*(c + d*x)]])/(16384*d) - Sinh[c + d*x]/(16*d*(5 + 3*Cosh[c + d*x])^3) - (25*Sinh[c + d*x])/(512*d*(5 + 3*Cosh[c + d*x])^2) - (311*Sinh[c + d*x])/(8192*d*(5 + 3*Cosh[c + d*x]))}


(* Integrands of the form (a+b*Cosh[c+d*x])^n where n is a half- integer *)
{(a + b*Cosh[x])^(5/2), x, 7, -((2*I*(23*a^2 + 9*b^2)*Sqrt[a + b*Cosh[x]]*EllipticE[(I*x)/2, (2*b)/(a + b)])/(15*Sqrt[(a + b*Cosh[x])/(a + b)])) + (16*I*a*(a^2 - b^2)*Sqrt[(a + b*Cosh[x])/(a + b)]*EllipticF[(I*x)/2, (2*b)/(a + b)])/(15*Sqrt[a + b*Cosh[x]]) + (16/15)*a*b*Sqrt[a + b*Cosh[x]]*Sinh[x] + (2/5)*b*(a + b*Cosh[x])^(3/2)*Sinh[x]}
{(a + b*Cosh[x])^(3/2), x, 6, -((8*I*a*Sqrt[a + b*Cosh[x]]*EllipticE[(I*x)/2, (2*b)/(a + b)])/(3*Sqrt[(a + b*Cosh[x])/(a + b)])) + (2*I*(a^2 - b^2)*Sqrt[(a + b*Cosh[x])/(a + b)]*EllipticF[(I*x)/2, (2*b)/(a + b)])/(3*Sqrt[a + b*Cosh[x]]) + (2/3)*b*Sqrt[a + b*Cosh[x]]*Sinh[x]}
{(a + b*Cosh[c + d*x])^(1/2), x, 2, -((2*I*Sqrt[a + b*Cosh[c + d*x]]*EllipticE[(1/2)*I*(c + d*x), (2*b)/(a + b)])/(d*Sqrt[(a + b*Cosh[c + d*x])/(a + b)]))}
{1/(a + b*Cosh[x])^(1/2), x, 2, -((2*I*Sqrt[(a + b*Cosh[x])/(a + b)]*EllipticF[(I*x)/2, (2*b)/(a + b)])/Sqrt[a + b*Cosh[x]])}
{1/(a + b*Cosh[x])^(3/2), x, 3, -((2*I*Sqrt[a + b*Cosh[x]]*EllipticE[(I*x)/2, (2*b)/(a + b)])/((a^2 - b^2)*Sqrt[(a + b*Cosh[x])/(a + b)])) - (2*b*Sinh[x])/((a^2 - b^2)*Sqrt[a + b*Cosh[x]])}
{1/(a + b*Cosh[x])^(5/2), x, 7, -((8*I*a*Sqrt[a + b*Cosh[x]]*EllipticE[(I*x)/2, (2*b)/(a + b)])/(3*(a^2 - b^2)^2*Sqrt[(a + b*Cosh[x])/(a + b)])) + (2*I*Sqrt[(a + b*Cosh[x])/(a + b)]*EllipticF[(I*x)/2, (2*b)/(a + b)])/(3*(a^2 - b^2)*Sqrt[a + b*Cosh[x]]) - (2*b*Sinh[x])/(3*(a^2 - b^2)*(a + b*Cosh[x])^(3/2)) - (8*a*b*Sinh[x])/(3*(a^2 - b^2)^2*Sqrt[a + b*Cosh[x]])}
{1/(a + b*Cosh[x])^(7/2), x, 8, -((2*I*(23*a^2 + 9*b^2)*Sqrt[a + b*Cosh[x]]*EllipticE[(I*x)/2, (2*b)/(a + b)])/(15*(a^2 - b^2)^3*Sqrt[(a + b*Cosh[x])/(a + b)])) + (16*I*a*Sqrt[(a + b*Cosh[x])/(a + b)]*EllipticF[(I*x)/2, (2*b)/(a + b)])/(15*(a^2 - b^2)^2*Sqrt[a + b*Cosh[x]]) - (2*b*Sinh[x])/(5*(a^2 - b^2)*(a + b*Cosh[x])^(5/2)) - (16*a*b*Sinh[x])/(15*(a^2 - b^2)^2*(a + b*Cosh[x])^(3/2)) - (2*b*(23*a^2 + 9*b^2)*Sinh[x])/(15*(a^2 - b^2)^3*Sqrt[a + b*Cosh[x]])}

{(a + a*Cosh[c + d*x])^(5/2), x, 3, (64*a^3*Sinh[c + d*x])/(15*d*Sqrt[a + a*Cosh[c + d*x]]) + (16*a^2*Sqrt[a + a*Cosh[c + d*x]]*Sinh[c + d*x])/(15*d) + (2*a*(a + a*Cosh[c + d*x])^(3/2)*Sinh[c + d*x])/(5*d)}
{(a + a*Cosh[c + d*x])^(3/2), x, 2, (8*a^2*Sinh[c + d*x])/(3*d*Sqrt[a + a*Cosh[c + d*x]]) + (2*a*Sqrt[a + a*Cosh[c + d*x]]*Sinh[c + d*x])/(3*d)}
{(a + a*Cosh[c + d*x])^(1/2), x, 1, (2*a*Sinh[c + d*x])/(d*Sqrt[a + a*Cosh[c + d*x]])}
{1/(a + a*Cosh[c + d*x])^(1/2), x, 1, (2*ArcTan[Sinh[(1/2)*(c + d*x)]]*Cosh[(1/2)*(c + d*x)])/(d*Sqrt[a + a*Cosh[c + d*x]])}
{1/(a + a*Cosh[c + d*x])^(3/2), x, 2, (ArcTan[Sinh[(1/2)*(c + d*x)]]*Cosh[(1/2)*(c + d*x)])/(2*a*d*Sqrt[a + a*Cosh[c + d*x]]) + Sinh[c + d*x]/(2*d*(a + a*Cosh[c + d*x])^(3/2))}
{1/(a + a*Cosh[c + d*x])^(5/2), x, 3, (3*ArcTan[Sinh[(1/2)*(c + d*x)]]*Cosh[(1/2)*(c + d*x)])/(16*a^2*d*Sqrt[a + a*Cosh[c + d*x]]) + Sinh[c + d*x]/(4*d*(a + a*Cosh[c + d*x])^(5/2)) + (3*Sinh[c + d*x])/(16*a*d*(a + a*Cosh[c + d*x])^(3/2))}

{(a - a*Cosh[c + d*x])^(5/2), x, 3, -((64*a^3*Sinh[c + d*x])/(15*d*Sqrt[a - a*Cosh[c + d*x]])) - (16*a^2*Sqrt[a - a*Cosh[c + d*x]]*Sinh[c + d*x])/(15*d) - (2*a*(a - a*Cosh[c + d*x])^(3/2)*Sinh[c + d*x])/(5*d)}
{(a - a*Cosh[c + d*x])^(3/2), x, 2, -((8*a^2*Sinh[c + d*x])/(3*d*Sqrt[a - a*Cosh[c + d*x]])) - (2*a*Sqrt[a - a*Cosh[c + d*x]]*Sinh[c + d*x])/(3*d)}
{(a - a*Cosh[c + d*x])^(1/2), x, 1, -((2*a*Sinh[c + d*x])/(d*Sqrt[a - a*Cosh[c + d*x]]))}
{1/(a - a*Cosh[c + d*x])^(1/2), x, 1, -((2*ArcTanh[Cosh[(1/2)*(c + d*x)]]*Sinh[(1/2)*(c + d*x)])/(d*Sqrt[a - a*Cosh[c + d*x]]))}
{1/(a - a*Cosh[c + d*x])^(3/2), x, 2, -((ArcTanh[Cosh[(1/2)*(c + d*x)]]*Sinh[(1/2)*(c + d*x)])/(2*a*d*Sqrt[a - a*Cosh[c + d*x]])) - Sinh[c + d*x]/(2*d*(a - a*Cosh[c + d*x])^(3/2))}
{1/(a - a*Cosh[c + d*x])^(5/2), x, 3, -((3*ArcTanh[Cosh[(1/2)*(c + d*x)]]*Sinh[(1/2)*(c + d*x)])/(16*a^2*d*Sqrt[a - a*Cosh[c + d*x]])) - Sinh[c + d*x]/(4*d*(a - a*Cosh[c + d*x])^(5/2)) - (3*Sinh[c + d*x])/(16*a*d*(a - a*Cosh[c + d*x])^(3/2))}


(* ::Subsection::Closed:: *)
(*x^m (a+b Cosh[c+d x])^n*)


(* Integrands of the form x^m/(c+d*Cosh[x]) where m is an integer *)
{1/(x*(a + b*Cosh[c + d*x])), x, 0, Int[1/(x*(a + b*Cosh[c + d*x])), x]}
{x/(a + b*Cosh[c + d*x]), x, 8, (x*Log[1 + (b*E^(c + d*x))/(a - Sqrt[a^2 - b^2])])/(Sqrt[a^2 - b^2]*d) - (x*Log[1 + (b*E^(c + d*x))/(a + Sqrt[a^2 - b^2])])/(Sqrt[a^2 - b^2]*d) + PolyLog[2, -((b*E^(c + d*x))/(a - Sqrt[a^2 - b^2]))]/(Sqrt[a^2 - b^2]*d^2) - PolyLog[2, -((b*E^(c + d*x))/(a + Sqrt[a^2 - b^2]))]/(Sqrt[a^2 - b^2]*d^2)}
{x^2/(a + b*Cosh[c + d*x]), x, 10, (x^2*Log[1 + (b*E^(c + d*x))/(a - Sqrt[a^2 - b^2])])/(Sqrt[a^2 - b^2]*d) - (x^2*Log[1 + (b*E^(c + d*x))/(a + Sqrt[a^2 - b^2])])/(Sqrt[a^2 - b^2]*d) + (2*x*PolyLog[2, -((b*E^(c + d*x))/(a - Sqrt[a^2 - b^2]))])/(Sqrt[a^2 - b^2]*d^2) - (2*x*PolyLog[2, -((b*E^(c + d*x))/(a + Sqrt[a^2 - b^2]))])/(Sqrt[a^2 - b^2]*d^2) - (2*PolyLog[3, -((b*E^(c + d*x))/(a - Sqrt[a^2 - b^2]))])/(Sqrt[a^2 - b^2]*d^3) + (2*PolyLog[3, -((b*E^(c + d*x))/(a + Sqrt[a^2 - b^2]))])/(Sqrt[a^2 - b^2]*d^3)}
{x^3/(a + b*Cosh[x]), x, 12, (x^3*Log[1 + (b*E^x)/(a - Sqrt[a^2 - b^2])])/Sqrt[a^2 - b^2] - (x^3*Log[1 + (b*E^x)/(a + Sqrt[a^2 - b^2])])/Sqrt[a^2 - b^2] + (3*x^2*PolyLog[2, -((b*E^x)/(a - Sqrt[a^2 - b^2]))])/Sqrt[a^2 - b^2] - (3*x^2*PolyLog[2, -((b*E^x)/(a + Sqrt[a^2 - b^2]))])/Sqrt[a^2 - b^2] - (6*x*PolyLog[3, -((b*E^x)/(a - Sqrt[a^2 - b^2]))])/Sqrt[a^2 - b^2] + (6*x*PolyLog[3, -((b*E^x)/(a + Sqrt[a^2 - b^2]))])/Sqrt[a^2 - b^2] + (6*PolyLog[4, -((b*E^x)/(a - Sqrt[a^2 - b^2]))])/Sqrt[a^2 - b^2] - (6*PolyLog[4, -((b*E^x)/(a + Sqrt[a^2 - b^2]))])/Sqrt[a^2 - b^2]}
(* {x^3/(a + b*Cosh[c + d*x]), x, 12, 0} *)

{1/(x*(1 + Cosh[x])), x, 1, (1/2)*Int[Sech[x/2]^2/x, x]}
{x/(1 + Cosh[x]), x, 3, -2*Log[Cosh[x/2]] + x*Tanh[x/2]}
{x^2/(1 + Cosh[x]), x, 6, x^2 - 4*x*Log[1 + E^x] - 4*PolyLog[2, -E^x] + x^2*Tanh[x/2]}
{x^3/(1 + Cosh[x]), x, 7, x^3 - 6*x^2*Log[1 + E^x] - 12*x*PolyLog[2, -E^x] + 12*PolyLog[3, -E^x] + x^3*Tanh[x/2]}

{1/(x*(1 - Cosh[x])), x, 1, (-(1/2))*Int[Csch[x/2]^2/x, x]}
{x/(1 - Cosh[x]), x, 3, x*Coth[x/2] - 2*Log[Sinh[x/2]]}
{x^2/(1 - Cosh[x]), x, 6, x^2 + x^2*Coth[x/2] - 4*x*Log[1 - E^x] - 4*PolyLog[2, E^x]}
{x^3/(1 - Cosh[x]), x, 7, x^3 + x^3*Coth[x/2] - 6*x^2*Log[1 - E^x] - 12*x*PolyLog[2, E^x] + 12*PolyLog[3, E^x]}


{x/(a + b*Cosh[c + d*x])^2, x, 12, (a*x*Log[1 + (b*E^(c + d*x))/(a - Sqrt[a^2 - b^2])])/((a^2 - b^2)^(3/2)*d) - (a*x*Log[1 + (b*E^(c + d*x))/(a + Sqrt[a^2 - b^2])])/((a^2 - b^2)^(3/2)*d) + Log[a + b*Cosh[c + d*x]]/((a^2 - b^2)*d^2) + (a*PolyLog[2, -((b*E^(c + d*x))/(a - Sqrt[a^2 - b^2]))])/((a^2 - b^2)^(3/2)*d^2) - (a*PolyLog[2, -((b*E^(c + d*x))/(a + Sqrt[a^2 - b^2]))])/((a^2 - b^2)^(3/2)*d^2) - (b*x*Sinh[c + d*x])/((a^2 - b^2)*d*(a + b*Cosh[c + d*x]))}
{(e + f*x)/(a + b*Cosh[c + d*x])^2, x, 16, (2*a*e*ArcTanh[((a - b)*Tanh[(1/2)*(c + d*x)])/Sqrt[a^2 - b^2]])/((a^2 - b^2)^(3/2)*d) + (a*f*x*Log[1 + (b*E^(c + d*x))/(a - Sqrt[a^2 - b^2])])/((a^2 - b^2)^(3/2)*d) - (a*f*x*Log[1 + (b*E^(c + d*x))/(a + Sqrt[a^2 - b^2])])/((a^2 - b^2)^(3/2)*d) + (f*Log[a + b*Cosh[c + d*x]])/((a^2 - b^2)*d^2) + (a*f*PolyLog[2, -((b*E^(c + d*x))/(a - Sqrt[a^2 - b^2]))])/((a^2 - b^2)^(3/2)*d^2) - (a*f*PolyLog[2, -((b*E^(c + d*x))/(a + Sqrt[a^2 - b^2]))])/((a^2 - b^2)^(3/2)*d^2) - (b*e*Sinh[c + d*x])/((a^2 - b^2)*d*(a + b*Cosh[c + d*x])) - (b*f*x*Sinh[c + d*x])/((a^2 - b^2)*d*(a + b*Cosh[c + d*x]))}


(* Integrands of the form x^m*(a+a*Cosh[x])^n where m is an integer and n is a half-integer *)
{x^3*Sqrt[a + a*Cosh[x]], x, 5, -96*Sqrt[a + a*Cosh[x]] - 12*x^2*Sqrt[a + a*Cosh[x]] + 48*x*Sqrt[a + a*Cosh[x]]*Tanh[x/2] + 2*x^3*Sqrt[a + a*Cosh[x]]*Tanh[x/2]}
{x^2*Sqrt[a + a*Cosh[x]], x, 4, -8*x*Sqrt[a + a*Cosh[x]] + 16*Sqrt[a + a*Cosh[x]]*Tanh[x/2] + 2*x^2*Sqrt[a + a*Cosh[x]]*Tanh[x/2]}
{x*Sqrt[a + a*Cosh[x]], x, 3, -4*Sqrt[a + a*Cosh[x]] + 2*x*Sqrt[a + a*Cosh[x]]*Tanh[x/2]}
{Sqrt[a + a*Cosh[x]], x, 1, (2*a*Sinh[x])/Sqrt[a + a*Cosh[x]]}
{Sqrt[a + a*Cosh[x]]/x, x, 2, Sqrt[a + a*Cosh[x]]*CoshIntegral[x/2]*Sech[x/2]}
{Sqrt[a + a*Cosh[x]]/x^2, x, 3, -(Sqrt[a + a*Cosh[x]]/x) + (1/2)*Sqrt[a + a*Cosh[x]]*Sech[x/2]*SinhIntegral[x/2]}
{Sqrt[a + a*Cosh[x]]/x^3, x, 4, -(Sqrt[a + a*Cosh[x]]/(2*x^2)) + (1/8)*Sqrt[a + a*Cosh[x]]*CoshIntegral[x/2]*Sech[x/2] - (Sqrt[a + a*Cosh[x]]*Tanh[x/2])/(4*x)}

{x^3*(a + a*Cosh[x])^(3/2), x, 9, (-(1280/9))*a*Sqrt[a + a*Cosh[x]] - 16*a*x^2*Sqrt[a + a*Cosh[x]] - (64/27)*a*Cosh[x/2]^2*Sqrt[a + a*Cosh[x]] - (8/3)*a*x^2*Cosh[x/2]^2*Sqrt[a + a*Cosh[x]] + (32/9)*a*x*Cosh[x/2]*Sqrt[a + a*Cosh[x]]*Sinh[x/2] + (4/3)*a*x^3*Cosh[x/2]*Sqrt[a + a*Cosh[x]]*Sinh[x/2] + (640/9)*a*x*Sqrt[a + a*Cosh[x]]*Tanh[x/2] + (8/3)*a*x^3*Sqrt[a + a*Cosh[x]]*Tanh[x/2]}
{x^2*(a + a*Cosh[x])^(3/2), x, 7, (-(32/3))*a*x*Sqrt[a + a*Cosh[x]] - (16/9)*a*x*Cosh[x/2]^2*Sqrt[a + a*Cosh[x]] + (4/3)*a*x^2*Cosh[x/2]*Sqrt[a + a*Cosh[x]]*Sinh[x/2] + (224/9)*a*Sqrt[a + a*Cosh[x]]*Tanh[x/2] + (8/3)*a*x^2*Sqrt[a + a*Cosh[x]]*Tanh[x/2] + (32/27)*a*Sqrt[a + a*Cosh[x]]*Sinh[x/2]^2*Tanh[x/2]}
{x*(a + a*Cosh[x])^(3/2), x, 4, (-(16/3))*a*Sqrt[a + a*Cosh[x]] - (8/9)*a*Cosh[x/2]^2*Sqrt[a + a*Cosh[x]] + (4/3)*a*x*Cosh[x/2]*Sqrt[a + a*Cosh[x]]*Sinh[x/2] + (8/3)*a*x*Sqrt[a + a*Cosh[x]]*Tanh[x/2]}
{(a + a*Cosh[x])^(3/2), x, 2, (8*a^2*Sinh[x])/(3*Sqrt[a + a*Cosh[x]]) + (2/3)*a*Sqrt[a + a*Cosh[x]]*Sinh[x]}
{(a + a*Cosh[x])^(3/2)/x, x, 5, (3/2)*a*Sqrt[a + a*Cosh[x]]*CoshIntegral[x/2]*Sech[x/2] + (1/2)*a*Sqrt[a + a*Cosh[x]]*CoshIntegral[(3*x)/2]*Sech[x/2]}
{(a + a*Cosh[x])^(3/2)/x^2, x, 7, -((3*a*Sqrt[a + a*Cosh[x]])/(2*x)) - (a*Sqrt[a + a*Cosh[x]]*Cosh[(3*x)/2]*Sech[x/2])/(2*x) + (3/4)*a*Sqrt[a + a*Cosh[x]]*Sech[x/2]*SinhIntegral[x/2] + (3/4)*a*Sqrt[a + a*Cosh[x]]*Sech[x/2]*SinhIntegral[(3*x)/2]}
{(a + a*Cosh[x])^(3/2)/x^3, x, 7, -((a*Cosh[x/2]^2*Sqrt[a + a*Cosh[x]])/x^2) + (3/16)*a*Sqrt[a + a*Cosh[x]]*CoshIntegral[x/2]*Sech[x/2] + (9/16)*a*Sqrt[a + a*Cosh[x]]*CoshIntegral[(3*x)/2]*Sech[x/2] - (3*a*Cosh[x/2]*Sqrt[a + a*Cosh[x]]*Sinh[x/2])/(2*x)}

{x^3/Sqrt[a + a*Cosh[x]], x, 9, (2*x^3*ArcTan[E^(x/2)]*Sqrt[a + a*Cosh[x]]*Sech[x/2])/a - (6*I*x^2*Sqrt[a + a*Cosh[x]]*PolyLog[2, (-I)*E^(x/2)]*Sech[x/2])/a + (6*I*x^2*Sqrt[a + a*Cosh[x]]*PolyLog[2, I*E^(x/2)]*Sech[x/2])/a + (24*I*x*Sqrt[a + a*Cosh[x]]*PolyLog[3, (-I)*E^(x/2)]*Sech[x/2])/a - (24*I*x*Sqrt[a + a*Cosh[x]]*PolyLog[3, I*E^(x/2)]*Sech[x/2])/a - (48*I*Sqrt[a + a*Cosh[x]]*PolyLog[4, (-I)*E^(x/2)]*Sech[x/2])/a + (48*I*Sqrt[a + a*Cosh[x]]*PolyLog[4, I*E^(x/2)]*Sech[x/2])/a}
{x^2/Sqrt[a + a*Cosh[x]], x, 7, (2*x^2*ArcTan[E^(x/2)]*Sqrt[a + a*Cosh[x]]*Sech[x/2])/a - (4*I*x*Sqrt[a + a*Cosh[x]]*PolyLog[2, (-I)*E^(x/2)]*Sech[x/2])/a + (4*I*x*Sqrt[a + a*Cosh[x]]*PolyLog[2, I*E^(x/2)]*Sech[x/2])/a + (8*I*Sqrt[a + a*Cosh[x]]*PolyLog[3, (-I)*E^(x/2)]*Sech[x/2])/a - (8*I*Sqrt[a + a*Cosh[x]]*PolyLog[3, I*E^(x/2)]*Sech[x/2])/a}
{x/Sqrt[a + a*Cosh[x]], x, 5, (2*x*ArcTan[E^(x/2)]*Sqrt[a + a*Cosh[x]]*Sech[x/2])/a - (2*I*Sqrt[a + a*Cosh[x]]*PolyLog[2, (-I)*E^(x/2)]*Sech[x/2])/a + (2*I*Sqrt[a + a*Cosh[x]]*PolyLog[2, I*E^(x/2)]*Sech[x/2])/a}
{1/Sqrt[a + a*Cosh[x]], x, 1, (2*ArcTan[Sinh[x/2]]*Cosh[x/2])/Sqrt[a + a*Cosh[x]]}
{1/(x*Sqrt[a + a*Cosh[x]]), x, 1, (Sqrt[a + a*Cosh[x]]*Int[Sech[x/2]/x, x]*Sech[x/2])/(2*a)}

(* {x^3/(a + a*Cosh[x])^(3/2), x, 14, -((12*x*ArcTan[E^(x/2)]*Sqrt[a + a*Cosh[x]]*Sech[x/2])/a^2) + (x^3*ArcTan[E^(x/2)]*Sqrt[a + a*Cosh[x]]*Sech[x/2])/(2*a^2) + (3*I*(8 - x^2)*Sqrt[a*(1 + Cosh[x])]*PolyLog[2, (-I)*E^(x/2)]*Sech[x/2])/(2*a^2) - (3*I*(8 - x^2)*Sqrt[a*(1 + Cosh[x])]*PolyLog[2, I*E^(x/2)]*Sech[x/2])/(2*a^2) + (6*I*x*Sqrt[a + a*Cosh[x]]*PolyLog[3, (-I)*E^(x/2)]*Sech[x/2])/a^2 - (6*I*x*Sqrt[a + a*Cosh[x]]*PolyLog[3, I*E^(x/2)]*Sech[x/2])/a^2 - (12*I*Sqrt[a + a*Cosh[x]]*PolyLog[4, (-I)*E^(x/2)]*Sech[x/2])/a^2 + (12*I*Sqrt[a + a*Cosh[x]]*PolyLog[4, I*E^(x/2)]*Sech[x/2])/a^2 + (3*x^2*Sqrt[a + a*Cosh[x]]*Sech[x/2]^2)/(2*a^2) + (x^3*Sqrt[a + a*Cosh[x]]*Sech[x/2]^2*Tanh[x/2])/(4*a^2)} *)
{x^2/(a + a*Cosh[x])^(3/2), x, 9, (x^2*ArcTan[E^(x/2)]*Sqrt[a + a*Cosh[x]]*Sech[x/2])/(2*a^2) - (2*ArcTan[Sinh[x/2]]*Sqrt[a + a*Cosh[x]]*Sech[x/2])/a^2 - (I*x*Sqrt[a + a*Cosh[x]]*PolyLog[2, (-I)*E^(x/2)]*Sech[x/2])/a^2 + (I*x*Sqrt[a + a*Cosh[x]]*PolyLog[2, I*E^(x/2)]*Sech[x/2])/a^2 + (2*I*Sqrt[a + a*Cosh[x]]*PolyLog[3, (-I)*E^(x/2)]*Sech[x/2])/a^2 - (2*I*Sqrt[a + a*Cosh[x]]*PolyLog[3, I*E^(x/2)]*Sech[x/2])/a^2 + (x*Sqrt[a + a*Cosh[x]]*Sech[x/2]^2)/a^2 + (x^2*Sqrt[a + a*Cosh[x]]*Sech[x/2]^2*Tanh[x/2])/(4*a^2)}
{x/(a + a*Cosh[x])^(3/2), x, 6, (x*ArcTan[E^(x/2)]*Sqrt[a + a*Cosh[x]]*Sech[x/2])/(2*a^2) - (I*Sqrt[a + a*Cosh[x]]*PolyLog[2, (-I)*E^(x/2)]*Sech[x/2])/(2*a^2) + (I*Sqrt[a + a*Cosh[x]]*PolyLog[2, I*E^(x/2)]*Sech[x/2])/(2*a^2) + (Sqrt[a + a*Cosh[x]]*Sech[x/2]^2)/(2*a^2) + (x*Sqrt[a + a*Cosh[x]]*Sech[x/2]^2*Tanh[x/2])/(4*a^2)}
{1/(a + a*Cosh[x])^(3/2), x, 2, (ArcTan[Sinh[x/2]]*Cosh[x/2])/(2*a*Sqrt[a + a*Cosh[x]]) + Sinh[x]/(2*(a + a*Cosh[x])^(3/2))}
{1/(x*(a + a*Cosh[x])^(3/2)), x, 1, (Sqrt[a + a*Cosh[x]]*Int[Sech[x/2]^3/x, x]*Sech[x/2])/(4*a^2)}


(* Integrands of the form x^m*(a-a*Cosh[x])^n where m is an integer and n is a half-integer *)
{x^3*Sqrt[a - a*Cosh[x]], x, 5, -96*Sqrt[a - a*Cosh[x]] - 12*x^2*Sqrt[a - a*Cosh[x]] + 48*x*Sqrt[a - a*Cosh[x]]*Coth[x/2] + 2*x^3*Sqrt[a - a*Cosh[x]]*Coth[x/2]}
{x^2*Sqrt[a - a*Cosh[x]], x, 4, -8*x*Sqrt[a - a*Cosh[x]] + 16*Sqrt[a - a*Cosh[x]]*Coth[x/2] + 2*x^2*Sqrt[a - a*Cosh[x]]*Coth[x/2]}
{x*Sqrt[a - a*Cosh[x]], x, 3, -4*Sqrt[a - a*Cosh[x]] + 2*x*Sqrt[a - a*Cosh[x]]*Coth[x/2]}
{Sqrt[a - a*Cosh[x]], x, 1, -((2*a*Sinh[x])/Sqrt[a - a*Cosh[x]])}
{Sqrt[a - a*Cosh[x]]/x, x, 2, Sqrt[a - a*Cosh[x]]*Csch[x/2]*SinhIntegral[x/2]}
{Sqrt[a - a*Cosh[x]]/x^2, x, 3, -(Sqrt[a - a*Cosh[x]]/x) + (1/2)*Sqrt[a - a*Cosh[x]]*CoshIntegral[x/2]*Csch[x/2]}
{Sqrt[a - a*Cosh[x]]/x^3, x, 4, -(Sqrt[a - a*Cosh[x]]/(2*x^2)) - (Sqrt[a - a*Cosh[x]]*Coth[x/2])/(4*x) + (1/8)*Sqrt[a - a*Cosh[x]]*Csch[x/2]*SinhIntegral[x/2]}

{x^3/Sqrt[a - a*Cosh[x]], x, 9, (2*x^3*ArcTanh[E^(x/2)]*Sqrt[a - a*Cosh[x]]*Csch[x/2])/a + (6*x^2*Sqrt[a - a*Cosh[x]]*Csch[x/2]*PolyLog[2, -E^(x/2)])/a - (6*x^2*Sqrt[a - a*Cosh[x]]*Csch[x/2]*PolyLog[2, E^(x/2)])/a - (24*x*Sqrt[a - a*Cosh[x]]*Csch[x/2]*PolyLog[3, -E^(x/2)])/a + (24*x*Sqrt[a - a*Cosh[x]]*Csch[x/2]*PolyLog[3, E^(x/2)])/a + (48*Sqrt[a - a*Cosh[x]]*Csch[x/2]*PolyLog[4, -E^(x/2)])/a - (48*Sqrt[a - a*Cosh[x]]*Csch[x/2]*PolyLog[4, E^(x/2)])/a}
{x^2/Sqrt[a - a*Cosh[x]], x, 7, (2*x^2*ArcTanh[E^(x/2)]*Sqrt[a - a*Cosh[x]]*Csch[x/2])/a + (4*x*Sqrt[a - a*Cosh[x]]*Csch[x/2]*PolyLog[2, -E^(x/2)])/a - (4*x*Sqrt[a - a*Cosh[x]]*Csch[x/2]*PolyLog[2, E^(x/2)])/a - (8*Sqrt[a - a*Cosh[x]]*Csch[x/2]*PolyLog[3, -E^(x/2)])/a + (8*Sqrt[a - a*Cosh[x]]*Csch[x/2]*PolyLog[3, E^(x/2)])/a}
{x/Sqrt[a - a*Cosh[x]], x, 5, (2*x*ArcTanh[E^(x/2)]*Sqrt[a - a*Cosh[x]]*Csch[x/2])/a + (2*Sqrt[a - a*Cosh[x]]*Csch[x/2]*PolyLog[2, -E^(x/2)])/a - (2*Sqrt[a - a*Cosh[x]]*Csch[x/2]*PolyLog[2, E^(x/2)])/a}
{1/Sqrt[a - a*Cosh[x]], x, 1, -((2*ArcTanh[Cosh[x/2]]*Sinh[x/2])/Sqrt[a - a*Cosh[x]])}
{1/(x*Sqrt[a - a*Cosh[x]]), x, 1, -((Sqrt[a - a*Cosh[x]]*Csch[x/2]*Int[Csch[x/2]/x, x])/(2*a))}


(* Integrands of the form x^m*(a+a*Cosh[c+d*x])^n where m is an integer and n is a half-integer *)
{x^3*Sqrt[a + a*Cosh[c + d*x]], x, 5, -((96*Sqrt[a + a*Cosh[c + d*x]])/d^4) - (12*x^2*Sqrt[a + a*Cosh[c + d*x]])/d^2 + (48*x*Sqrt[a + a*Cosh[c + d*x]]*Tanh[c/2 + (d*x)/2])/d^3 + (2*x^3*Sqrt[a + a*Cosh[c + d*x]]*Tanh[c/2 + (d*x)/2])/d}
{x^2*Sqrt[a + a*Cosh[c + d*x]], x, 4, -((8*x*Sqrt[a + a*Cosh[c + d*x]])/d^2) + (16*Sqrt[a + a*Cosh[c + d*x]]*Tanh[c/2 + (d*x)/2])/d^3 + (2*x^2*Sqrt[a + a*Cosh[c + d*x]]*Tanh[c/2 + (d*x)/2])/d}
{x*Sqrt[a + a*Cosh[c + d*x]], x, 3, -((4*Sqrt[a + a*Cosh[c + d*x]])/d^2) + (2*x*Sqrt[a + a*Cosh[c + d*x]]*Tanh[c/2 + (d*x)/2])/d}
{Sqrt[a + a*Cosh[c + d*x]], x, 1, (2*a*Sinh[c + d*x])/(d*Sqrt[a + a*Cosh[c + d*x]])}
{Sqrt[a + a*Cosh[c + d*x]]/x, x, 4, Cosh[c/2]*Sqrt[a + a*Cosh[c + d*x]]*CoshIntegral[(d*x)/2]*Sech[c/2 + (d*x)/2] + Sqrt[a + a*Cosh[c + d*x]]*Sech[c/2 + (d*x)/2]*Sinh[c/2]*SinhIntegral[(d*x)/2]}
{Sqrt[a + a*Cosh[c + d*x]]/x^2, x, 5, -(Sqrt[a + a*Cosh[c + d*x]]/x) + (1/2)*d*Sqrt[a + a*Cosh[c + d*x]]*CoshIntegral[(d*x)/2]*Sech[c/2 + (d*x)/2]*Sinh[c/2] + (1/2)*d*Cosh[c/2]*Sqrt[a + a*Cosh[c + d*x]]*Sech[c/2 + (d*x)/2]*SinhIntegral[(d*x)/2]}
{Sqrt[a + a*Cosh[c + d*x]]/x^3, x, 6, -(Sqrt[a + a*Cosh[c + d*x]]/(2*x^2)) + (1/8)*d^2*Cosh[c/2]*Sqrt[a + a*Cosh[c + d*x]]*CoshIntegral[(d*x)/2]*Sech[c/2 + (d*x)/2] + (1/8)*d^2*Sqrt[a + a*Cosh[c + d*x]]*Sech[c/2 + (d*x)/2]*Sinh[c/2]*SinhIntegral[(d*x)/2] - (d*Sqrt[a + a*Cosh[c + d*x]]*Tanh[c/2 + (d*x)/2])/(4*x)}

{x^3/Sqrt[a + a*Cosh[c + d*x]], x, 9, (2*x^3*ArcTan[E^(c/2 + (d*x)/2)]*Sqrt[a + a*Cosh[c + d*x]]*Sech[c/2 + (d*x)/2])/(a*d) - (6*I*x^2*Sqrt[a + a*Cosh[c + d*x]]*PolyLog[2, (-I)*E^(c/2 + (d*x)/2)]*Sech[c/2 + (d*x)/2])/(a*d^2) + (6*I*x^2*Sqrt[a + a*Cosh[c + d*x]]*PolyLog[2, I*E^(c/2 + (d*x)/2)]*Sech[c/2 + (d*x)/2])/(a*d^2) + (24*I*x*Sqrt[a + a*Cosh[c + d*x]]*PolyLog[3, (-I)*E^(c/2 + (d*x)/2)]*Sech[c/2 + (d*x)/2])/(a*d^3) - (24*I*x*Sqrt[a + a*Cosh[c + d*x]]*PolyLog[3, I*E^(c/2 + (d*x)/2)]*Sech[c/2 + (d*x)/2])/(a*d^3) - (48*I*Sqrt[a + a*Cosh[c + d*x]]*PolyLog[4, (-I)*E^(c/2 + (d*x)/2)]*Sech[c/2 + (d*x)/2])/(a*d^4) + (48*I*Sqrt[a + a*Cosh[c + d*x]]*PolyLog[4, I*E^(c/2 + (d*x)/2)]*Sech[c/2 + (d*x)/2])/(a*d^4)}
{x^2/Sqrt[a + a*Cosh[c + d*x]], x, 7, (2*x^2*ArcTan[E^(c/2 + (d*x)/2)]*Sqrt[a + a*Cosh[c + d*x]]*Sech[c/2 + (d*x)/2])/(a*d) - (4*I*x*Sqrt[a + a*Cosh[c + d*x]]*PolyLog[2, (-I)*E^(c/2 + (d*x)/2)]*Sech[c/2 + (d*x)/2])/(a*d^2) + (4*I*x*Sqrt[a + a*Cosh[c + d*x]]*PolyLog[2, I*E^(c/2 + (d*x)/2)]*Sech[c/2 + (d*x)/2])/(a*d^2) + (8*I*Sqrt[a + a*Cosh[c + d*x]]*PolyLog[3, (-I)*E^(c/2 + (d*x)/2)]*Sech[c/2 + (d*x)/2])/(a*d^3) - (8*I*Sqrt[a + a*Cosh[c + d*x]]*PolyLog[3, I*E^(c/2 + (d*x)/2)]*Sech[c/2 + (d*x)/2])/(a*d^3)}
{x/Sqrt[a + a*Cosh[c + d*x]], x, 5, (2*x*ArcTan[E^(c/2 + (d*x)/2)]*Sqrt[a + a*Cosh[c + d*x]]*Sech[c/2 + (d*x)/2])/(a*d) - (2*I*Sqrt[a + a*Cosh[c + d*x]]*PolyLog[2, (-I)*E^(c/2 + (d*x)/2)]*Sech[c/2 + (d*x)/2])/(a*d^2) + (2*I*Sqrt[a + a*Cosh[c + d*x]]*PolyLog[2, I*E^(c/2 + (d*x)/2)]*Sech[c/2 + (d*x)/2])/(a*d^2)}
{1/Sqrt[a + a*Cosh[c + d*x]], x, 1, (2*ArcTan[Sinh[(1/2)*(c + d*x)]]*Cosh[(1/2)*(c + d*x)])/(d*Sqrt[a + a*Cosh[c + d*x]])}
{1/(x*Sqrt[a + a*Cosh[c + d*x]]), x, 1, (Sqrt[a + a*Cosh[c + d*x]]*Int[Sech[c/2 + (d*x)/2]/x, x]*Sech[c/2 + (d*x)/2])/(2*a)}


(* Used to hang Rubi *)
{(a + a*Cosh[c + d*x])^(1/3)/x, x, 0, Int[(a + a*Cosh[c + d*x])^(1/3)/x, x]}


(* ::Subsection::Closed:: *)
(*(a+b Cosh[c+d x]^2)^n*)


(* Integrands of the form 1/(a+b*Cosh[x]^2)^n where n is an integer *)
{1/(a + b*Cosh[x]^2), x, 2, ArcTanh[(Sqrt[a]*Tanh[x])/Sqrt[a + b]]/(Sqrt[a]*Sqrt[a + b])}
{1/(a + b*Cosh[x]^2)^2, x, 3, ((2*a + b)*ArcTanh[(Sqrt[a]*Tanh[x])/Sqrt[a + b]])/(2*a^(3/2)*(a + b)^(3/2)) - (b*Cosh[x]*Sinh[x])/(2*a*(a + b)*(a + b*Cosh[x]^2)), ((2*a + b)*ArcTanh[(Sqrt[a]*Tanh[x])/Sqrt[a + b]])/(2*a^(3/2)*(a + b)^(3/2)) - (b*Sinh[2*x])/(2*a*(a + b)*(2*a + b + b*Cosh[2*x]))}
{1/(a + b*Cosh[x]^2)^3, x, 4, ((b^2 + 2*(2*a + b)^2)*ArcTanh[(Sqrt[a]*Tanh[x])/Sqrt[a + b]])/(8*a^(5/2)*(a + b)^(5/2)) - (b*Sinh[2*x])/(2*a*(a + b)*(2*a + b + b*Cosh[2*x])^2) - (3*b*(2*a + b)*Sinh[2*x])/(8*a^2*(a + b)^2*(2*a + b + b*Cosh[2*x]))}

{1/(1 + Cosh[x]^2), x, 2, ArcTanh[Tanh[x]/Sqrt[2]]/Sqrt[2]}
{1/(1 + Cosh[x]^2)^2, x, 3, (3*ArcTanh[Tanh[x]/Sqrt[2]])/(4*Sqrt[2]) - Sinh[2*x]/(4*(3 + Cosh[2*x]))}
{1/(1 + Cosh[x]^2)^3, x, 4, (19*ArcTanh[Tanh[x]/Sqrt[2]])/(32*Sqrt[2]) - Sinh[2*x]/(4*(3 + Cosh[2*x])^2) - (9*Sinh[2*x])/(32*(3 + Cosh[2*x]))}

{1/(1 - Cosh[x]^2), x, 3, Coth[x]}
{1/(1 - Cosh[x]^2)^2, x, 3, Coth[x] - Coth[x]^3/3}
{1/(1 - Cosh[x]^2)^3, x, 5, Coth[x] - (2*Coth[x]^3)/3 + Coth[x]^5/5}


(* Integrands of the form (a+b*Cosh[x]^2)^m where m is a half-integer *)
{Sqrt[1 + Cosh[x]^2], x, 2, (-I)*Sqrt[2]*EllipticE[I*x, 1/2]}
{Sqrt[1 - Cosh[x]^2], x, 3, Coth[x]*Sqrt[-Sinh[x]^2]}
{Sqrt[-1 + Cosh[x]^2], x, 3, Coth[x]*Sqrt[Sinh[x]^2]}
{Sqrt[-1 - Cosh[x]^2], x, 3, -((I*Sqrt[2]*Sqrt[-3 - Cosh[2*x]]*EllipticE[I*x, 1/2])/Sqrt[3 + Cosh[2*x]])}
{Sqrt[a + b*Cosh[x]^2], x, 3, -((I*Sqrt[2*a + b + b*Cosh[2*x]]*EllipticE[I*x, b/(a + b)])/Sqrt[(2*a + b + b*Cosh[2*x])/(a + b)])}

{1/Sqrt[1 + Cosh[x]^2], x, 2, -((I*EllipticF[I*x, 1/2])/Sqrt[2])}
{1/Sqrt[1 - Cosh[x]^2], x, 3, -((ArcCoth[Cosh[x]]*Sinh[x])/Sqrt[-Sinh[x]^2])}
{1/Sqrt[-1 + Cosh[x]^2], x, 3, -((ArcCoth[Cosh[x]]*Sinh[x])/Sqrt[Sinh[x]^2])}
{1/Sqrt[-1 - Cosh[x]^2], x, 3, -((I*Sqrt[3 + Cosh[2*x]]*EllipticF[I*x, 1/2])/(Sqrt[2]*Sqrt[-3 - Cosh[2*x]]))}
{1/Sqrt[a + b*Cosh[x]^2], x, 3, -((I*Sqrt[(2*a + b + b*Cosh[2*x])/(a + b)]*EllipticF[I*x, b/(a + b)])/Sqrt[2*a + b + b*Cosh[2*x]])}

{(1 - Cosh[x]^2)^(3/2), x, 4, Coth[x]*Sqrt[-Sinh[x]^2] - (1/3)*Cosh[x]^2*Coth[x]*Sqrt[-Sinh[x]^2]}
{(-1 + Cosh[x]^2)^(3/2), x, 4, (-Coth[x])*Sqrt[Sinh[x]^2] + (1/3)*Cosh[x]^2*Coth[x]*Sqrt[Sinh[x]^2]}
(* {(1 + Cosh[x]^2)^(3/2), x, 0, 0} *)
(* {(-1 - Cosh[x]^2)^(3/2), x, 0, 0} *)
(* {(a + b*Cosh[x]^2)^(3/2), x, 0, 0} *)


(* ::Subsection::Closed:: *)
(*x^m (a+b Cosh[c+d x]^2)^n*)


(* Integrands of the form x^m/(a+b*Cosh[x]^2) where m is an integer *)
{x/(a + b*Cosh[x]^2), x, 9, (x*Log[1 + (b*E^(2*x))/(2*a + b - 2*Sqrt[a]*Sqrt[a + b])])/(2*Sqrt[a]*Sqrt[a + b]) - (x*Log[1 + (b*E^(2*x))/(2*a + b + 2*Sqrt[a]*Sqrt[a + b])])/(2*Sqrt[a]*Sqrt[a + b]) + PolyLog[2, -((b*E^(2*x))/(2*a + b - 2*Sqrt[a]*Sqrt[a + b]))]/(4*Sqrt[a]*Sqrt[a + b]) - PolyLog[2, -((b*E^(2*x))/(2*a + b + 2*Sqrt[a]*Sqrt[a + b]))]/(4*Sqrt[a]*Sqrt[a + b])}
{x^2/(a + b*Cosh[x]^2), x, 11, (x^2*Log[1 + (b*E^(2*x))/(2*a + b - 2*Sqrt[a]*Sqrt[a + b])])/(2*Sqrt[a]*Sqrt[a + b]) - (x^2*Log[1 + (b*E^(2*x))/(2*a + b + 2*Sqrt[a]*Sqrt[a + b])])/(2*Sqrt[a]*Sqrt[a + b]) + (x*PolyLog[2, -((b*E^(2*x))/(2*a + b - 2*Sqrt[a]*Sqrt[a + b]))])/(2*Sqrt[a]*Sqrt[a + b]) - (x*PolyLog[2, -((b*E^(2*x))/(2*a + b + 2*Sqrt[a]*Sqrt[a + b]))])/(2*Sqrt[a]*Sqrt[a + b]) - PolyLog[3, -((b*E^(2*x))/(2*a + b - 2*Sqrt[a]*Sqrt[a + b]))]/(4*Sqrt[a]*Sqrt[a + b]) + PolyLog[3, -((b*E^(2*x))/(2*a + b + 2*Sqrt[a]*Sqrt[a + b]))]/(4*Sqrt[a]*Sqrt[a + b])}
{x^3/(a + b*Cosh[x]^2), x, 13, (x^3*Log[1 + (b*E^(2*x))/(2*a + b - 2*Sqrt[a]*Sqrt[a + b])])/(2*Sqrt[a]*Sqrt[a + b]) - (x^3*Log[1 + (b*E^(2*x))/(2*a + b + 2*Sqrt[a]*Sqrt[a + b])])/(2*Sqrt[a]*Sqrt[a + b]) + (3*x^2*PolyLog[2, -((b*E^(2*x))/(2*a + b - 2*Sqrt[a]*Sqrt[a + b]))])/(4*Sqrt[a]*Sqrt[a + b]) - (3*x^2*PolyLog[2, -((b*E^(2*x))/(2*a + b + 2*Sqrt[a]*Sqrt[a + b]))])/(4*Sqrt[a]*Sqrt[a + b]) - (3*x*PolyLog[3, -((b*E^(2*x))/(2*a + b - 2*Sqrt[a]*Sqrt[a + b]))])/(4*Sqrt[a]*Sqrt[a + b]) + (3*x*PolyLog[3, -((b*E^(2*x))/(2*a + b + 2*Sqrt[a]*Sqrt[a + b]))])/(4*Sqrt[a]*Sqrt[a + b]) + (3*PolyLog[4, -((b*E^(2*x))/(2*a + b - 2*Sqrt[a]*Sqrt[a + b]))])/(8*Sqrt[a]*Sqrt[a + b]) - (3*PolyLog[4, -((b*E^(2*x))/(2*a + b + 2*Sqrt[a]*Sqrt[a + b]))])/(8*Sqrt[a]*Sqrt[a + b])}


(* ::Subsection::Closed:: *)
(*1 / (a+b Cosh[c+d x]^n)	where n>2*)


(* Integrands of the form 1/(a+b*Cosh[x]^n) where n is an integer *)
{1/(a + b*Cosh[x]^3), x, 7, (2*ArcTanh[((a^(1/3) - b^(1/3))*Tanh[x/2])/Sqrt[a^(2/3) - b^(2/3)]])/(3*a^(2/3)*Sqrt[a^(2/3) - b^(2/3)]) + (2*ArcTanh[((a^(1/3) - (-1)^(2/3)*b^(1/3))*Tanh[x/2])/Sqrt[a^(2/3) + (-1)^(1/3)*b^(2/3)]])/(3*a^(2/3)*Sqrt[a^(2/3) + (-1)^(1/3)*b^(2/3)]) + (2*ArcTanh[((a^(1/3) + (-1)^(1/3)*b^(1/3))*Tanh[x/2])/Sqrt[a^(2/3) - (-1)^(2/3)*b^(2/3)]])/(3*a^(2/3)*Sqrt[a^(2/3) - (-1)^(2/3)*b^(2/3)])}
{1/(a + b*Cosh[x]^4), x, 7, -(ArcTanh[((-a)^(1/4)*Tanh[x])/Sqrt[Sqrt[-a] - Sqrt[b]]]/(2*(-a)^(3/4)*Sqrt[Sqrt[-a] - Sqrt[b]])) - ArcTanh[((-a)^(1/4)*Tanh[x])/Sqrt[Sqrt[-a] + Sqrt[b]]]/(2*(-a)^(3/4)*Sqrt[Sqrt[-a] + Sqrt[b]])}
{1/(a + b*Cosh[x]^5), x, 11, (2*ArcTanh[((a^(1/5) - b^(1/5))*Tanh[x/2])/Sqrt[a^(2/5) - b^(2/5)]])/(5*a^(4/5)*Sqrt[a^(2/5) - b^(2/5)]) + (2*ArcTanh[((a^(1/5) + (-1)^(3/5)*b^(1/5))*Tanh[x/2])/Sqrt[a^(2/5) + (-1)^(1/5)*b^(2/5)]])/(5*a^(4/5)*Sqrt[a^(2/5) + (-1)^(1/5)*b^(2/5)]) + (2*ArcTanh[((a^(1/5) + (-1)^(1/5)*b^(1/5))*Tanh[x/2])/Sqrt[a^(2/5) - (-1)^(2/5)*b^(2/5)]])/(5*a^(4/5)*Sqrt[a^(2/5) - (-1)^(2/5)*b^(2/5)]) + (2*ArcTanh[((a^(1/5) - (-1)^(4/5)*b^(1/5))*Tanh[x/2])/Sqrt[a^(2/5) + (-1)^(3/5)*b^(2/5)]])/(5*a^(4/5)*Sqrt[a^(2/5) + (-1)^(3/5)*b^(2/5)]) + (2*ArcTanh[((a^(1/5) - (-1)^(2/5)*b^(1/5))*Tanh[x/2])/Sqrt[a^(2/5) - (-1)^(4/5)*b^(2/5)]])/(5*a^(4/5)*Sqrt[a^(2/5) - (-1)^(4/5)*b^(2/5)])}
{1/(a + b*Cosh[x]^6), x, 10, ArcTanh[(a^(1/6)*Tanh[x])/Sqrt[a^(1/3) + b^(1/3)]]/(3*a^(5/6)*Sqrt[a^(1/3) + b^(1/3)]) + ArcTanh[(a^(1/6)*Tanh[x])/Sqrt[a^(1/3) - (-1)^(1/3)*b^(1/3)]]/(3*a^(5/6)*Sqrt[a^(1/3) - (-1)^(1/3)*b^(1/3)]) + ArcTanh[(a^(1/6)*Tanh[x])/Sqrt[a^(1/3) + (-1)^(2/3)*b^(1/3)]]/(3*a^(5/6)*Sqrt[a^(1/3) + (-1)^(2/3)*b^(1/3)])}
{1/(a + b*Cosh[x]^8), x, 13, -(ArcTanh[((-a)^(1/8)*Tanh[x])/Sqrt[(-a)^(1/4) - b^(1/4)]]/(4*(-a)^(7/8)*Sqrt[(-a)^(1/4) - b^(1/4)])) - ArcTanh[((-a)^(1/8)*Tanh[x])/Sqrt[(-a)^(1/4) - I*b^(1/4)]]/(4*(-a)^(7/8)*Sqrt[(-a)^(1/4) - I*b^(1/4)]) - ArcTanh[((-a)^(1/8)*Tanh[x])/Sqrt[(-a)^(1/4) + I*b^(1/4)]]/(4*(-a)^(7/8)*Sqrt[(-a)^(1/4) + I*b^(1/4)]) - ArcTanh[((-a)^(1/8)*Tanh[x])/Sqrt[(-a)^(1/4) + b^(1/4)]]/(4*(-a)^(7/8)*Sqrt[(-a)^(1/4) + b^(1/4)])}

{1/(a - b*Cosh[x]^3), x, 7, (2*ArcTanh[((a^(1/3) + b^(1/3))*Tanh[x/2])/Sqrt[a^(2/3) - b^(2/3)]])/(3*a^(2/3)*Sqrt[a^(2/3) - b^(2/3)]) + (2*ArcTanh[((a^(1/3) + (-1)^(2/3)*b^(1/3))*Tanh[x/2])/Sqrt[a^(2/3) + (-1)^(1/3)*b^(2/3)]])/(3*a^(2/3)*Sqrt[a^(2/3) + (-1)^(1/3)*b^(2/3)]) + (2*ArcTanh[((a^(1/3) - (-1)^(1/3)*b^(1/3))*Tanh[x/2])/Sqrt[a^(2/3) - (-1)^(2/3)*b^(2/3)]])/(3*a^(2/3)*Sqrt[a^(2/3) - (-1)^(2/3)*b^(2/3)])}
{1/(a - b*Cosh[x]^4), x, 7, ArcTanh[(a^(1/4)*Tanh[x])/Sqrt[Sqrt[a] - Sqrt[b]]]/(2*a^(3/4)*Sqrt[Sqrt[a] - Sqrt[b]]) + ArcTanh[(a^(1/4)*Tanh[x])/Sqrt[Sqrt[a] + Sqrt[b]]]/(2*a^(3/4)*Sqrt[Sqrt[a] + Sqrt[b]])}
{1/(a - b*Cosh[x]^5), x, 11, (2*ArcTanh[((a^(1/5) + b^(1/5))*Tanh[x/2])/Sqrt[a^(2/5) - b^(2/5)]])/(5*a^(4/5)*Sqrt[a^(2/5) - b^(2/5)]) + (2*ArcTanh[((a^(1/5) - (-1)^(3/5)*b^(1/5))*Tanh[x/2])/Sqrt[a^(2/5) + (-1)^(1/5)*b^(2/5)]])/(5*a^(4/5)*Sqrt[a^(2/5) + (-1)^(1/5)*b^(2/5)]) + (2*ArcTanh[((a^(1/5) - (-1)^(1/5)*b^(1/5))*Tanh[x/2])/Sqrt[a^(2/5) - (-1)^(2/5)*b^(2/5)]])/(5*a^(4/5)*Sqrt[a^(2/5) - (-1)^(2/5)*b^(2/5)]) + (2*ArcTanh[((a^(1/5) + (-1)^(4/5)*b^(1/5))*Tanh[x/2])/Sqrt[a^(2/5) + (-1)^(3/5)*b^(2/5)]])/(5*a^(4/5)*Sqrt[a^(2/5) + (-1)^(3/5)*b^(2/5)]) + (2*ArcTanh[((a^(1/5) + (-1)^(2/5)*b^(1/5))*Tanh[x/2])/Sqrt[a^(2/5) - (-1)^(4/5)*b^(2/5)]])/(5*a^(4/5)*Sqrt[a^(2/5) - (-1)^(4/5)*b^(2/5)])}
{1/(a - b*Cosh[x]^6), x, 10, ArcTanh[(a^(1/6)*Tanh[x])/Sqrt[a^(1/3) - b^(1/3)]]/(3*a^(5/6)*Sqrt[a^(1/3) - b^(1/3)]) + ArcTanh[(a^(1/6)*Tanh[x])/Sqrt[a^(1/3) + (-1)^(1/3)*b^(1/3)]]/(3*a^(5/6)*Sqrt[a^(1/3) + (-1)^(1/3)*b^(1/3)]) + ArcTanh[(a^(1/6)*Tanh[x])/Sqrt[a^(1/3) - (-1)^(2/3)*b^(1/3)]]/(3*a^(5/6)*Sqrt[a^(1/3) - (-1)^(2/3)*b^(1/3)])}
{1/(a - b*Cosh[x]^8), x, 13, ArcTanh[(a^(1/8)*Tanh[x])/Sqrt[a^(1/4) - b^(1/4)]]/(4*a^(7/8)*Sqrt[a^(1/4) - b^(1/4)]) + ArcTanh[(a^(1/8)*Tanh[x])/Sqrt[a^(1/4) - I*b^(1/4)]]/(4*a^(7/8)*Sqrt[a^(1/4) - I*b^(1/4)]) + ArcTanh[(a^(1/8)*Tanh[x])/Sqrt[a^(1/4) + I*b^(1/4)]]/(4*a^(7/8)*Sqrt[a^(1/4) + I*b^(1/4)]) + ArcTanh[(a^(1/8)*Tanh[x])/Sqrt[a^(1/4) + b^(1/4)]]/(4*a^(7/8)*Sqrt[a^(1/4) + b^(1/4)])}

{1/(1 + Cosh[x]^3), x, 5, -((2*ArcTanh[(-1)^(2/3)*Sqrt[1 + (-1)^(1/3)]*Tanh[x/2]])/(3*Sqrt[1 + (-1)^(1/3)])) + (2*ArcTanh[(-1)^(1/3)*Sqrt[1 - (-1)^(2/3)]*Tanh[x/2]])/(3*Sqrt[1 - (-1)^(2/3)]) + Sinh[x]/(3*(1 + Cosh[x]))}
{1/(1 + Cosh[x]^4), x, 9, ArcTanh[Tanh[x]/Sqrt[1 - I]]/(2*Sqrt[1 - I]) + ArcTanh[Tanh[x]/Sqrt[1 + I]]/(2*Sqrt[1 + I])}
{1/(1 + Cosh[x]^5), x, 8, (2*ArcTanh[((1 + (-1)^(1/5))*Tanh[x/2])/Sqrt[1 - (-1)^(2/5)]])/(5*Sqrt[1 - (-1)^(2/5)]) + (2*ArcTanh[((1 + (-1)^(3/5))*Tanh[x/2])/Sqrt[1 + (-1)^(1/5)]])/(5*Sqrt[1 + (-1)^(1/5)]) + (2*ArcTanh[((1 - (-1)^(2/5))*Tanh[x/2])/Sqrt[1 - (-1)^(4/5)]])/(5*Sqrt[1 - (-1)^(4/5)]) + (2*ArcTanh[((1 - (-1)^(4/5))*Tanh[x/2])/Sqrt[1 + (-1)^(3/5)]])/(5*Sqrt[1 + (-1)^(3/5)]) + Sinh[x]/(5*(1 + Cosh[x]))}
{1/(1 + Cosh[x]^6), x, 8, ArcTanh[Tanh[x]/Sqrt[2]]/(3*Sqrt[2]) + ArcTanh[Tanh[x]/Sqrt[1 - (-1)^(1/3)]]/(3*Sqrt[1 - (-1)^(1/3)]) + ArcTanh[Tanh[x]/Sqrt[1 + (-1)^(2/3)]]/(3*Sqrt[1 + (-1)^(2/3)])}
{1/(1 + Cosh[x]^8), x, 11, ArcTanh[Tanh[x]/Sqrt[1 - (-1)^(1/4)]]/(4*Sqrt[1 - (-1)^(1/4)]) + ArcTanh[Tanh[x]/Sqrt[1 + (-1)^(1/4)]]/(4*Sqrt[1 + (-1)^(1/4)]) + ArcTanh[Tanh[x]/Sqrt[1 - (-1)^(3/4)]]/(4*Sqrt[1 - (-1)^(3/4)]) + ArcTanh[Tanh[x]/Sqrt[1 + (-1)^(3/4)]]/(4*Sqrt[1 + (-1)^(3/4)])}

{1/(1 - Cosh[x]^3), x, 5, (2*ArcTanh[((1 - (-1)^(1/3))*Tanh[x/2])/Sqrt[1 - (-1)^(2/3)]])/(3*Sqrt[1 - (-1)^(2/3)]) + (2*ArcTanh[((1 + (-1)^(2/3))*Tanh[x/2])/Sqrt[1 + (-1)^(1/3)]])/(3*Sqrt[1 + (-1)^(1/3)]) - Sinh[x]/(3*(1 - Cosh[x]))}
{1/(1 - Cosh[x]^4), x, 6, ArcTanh[Tanh[x]/Sqrt[2]]/(2*Sqrt[2]) + Coth[x]/2}
{1/(1 - Cosh[x]^5), x, 8, (2*ArcTanh[((1 - (-1)^(1/5))*Tanh[x/2])/Sqrt[1 - (-1)^(2/5)]])/(5*Sqrt[1 - (-1)^(2/5)]) + (2*ArcTanh[((1 - (-1)^(3/5))*Tanh[x/2])/Sqrt[1 + (-1)^(1/5)]])/(5*Sqrt[1 + (-1)^(1/5)]) + (2*ArcTanh[((1 + (-1)^(2/5))*Tanh[x/2])/Sqrt[1 - (-1)^(4/5)]])/(5*Sqrt[1 - (-1)^(4/5)]) + (2*ArcTanh[((1 + (-1)^(4/5))*Tanh[x/2])/Sqrt[1 + (-1)^(3/5)]])/(5*Sqrt[1 + (-1)^(3/5)]) - Sinh[x]/(5*(1 - Cosh[x]))}
{1/(1 - Cosh[x]^6), x, 9, ArcTanh[Tanh[x]/Sqrt[1 + (-1)^(1/3)]]/(3*Sqrt[1 + (-1)^(1/3)]) + ArcTanh[Tanh[x]/Sqrt[1 - (-1)^(2/3)]]/(3*Sqrt[1 - (-1)^(2/3)]) + Coth[x]/3}
{1/(1 - Cosh[x]^8), x, 14, ArcTanh[Tanh[x]/Sqrt[1 - I]]/(4*Sqrt[1 - I]) + ArcTanh[Tanh[x]/Sqrt[1 + I]]/(4*Sqrt[1 + I]) + ArcTanh[Tanh[x]/Sqrt[2]]/(4*Sqrt[2]) + Coth[x]/4}


(* ::Subsection::Closed:: *)
(*(c+d x)^m Cosh[a+b x]^n*)


(* Integrands of the form Cosh[a+b*x]^m*(c+d*x)^n where m is an integer and n is a half-integer *)
{Cosh[a + b*x]*Sqrt[c + d*x], x, 5, (Sqrt[d]*E^(-a + (b*c)/d)*Sqrt[Pi]*Erf[(Sqrt[b]*Sqrt[c + d*x])/Sqrt[d]])/(4*b^(3/2)) - (Sqrt[d]*E^(a - (b*c)/d)*Sqrt[Pi]*Erfi[(Sqrt[b]*Sqrt[c + d*x])/Sqrt[d]])/(4*b^(3/2)) + (Sqrt[c + d*x]*Sinh[a + b*x])/b}
{Cosh[a + b*x]/Sqrt[c + d*x], x, 4, (E^((b*c - a*d)/d)*Sqrt[Pi]*Erf[(Sqrt[b]*Sqrt[c + d*x])/Sqrt[d]])/(2*Sqrt[b]*Sqrt[d]) + (Sqrt[Pi]*Erfi[(Sqrt[b]*Sqrt[c + d*x])/Sqrt[d]])/(E^((b*c - a*d)/d)*(2*Sqrt[b]*Sqrt[d]))}
{Cosh[a + b*x]/(c + d*x)^(3/2), x, 5, -((2*Cosh[a + b*x])/(d*Sqrt[c + d*x])) - (Sqrt[b]*E^(-a + (b*c)/d)*Sqrt[Pi]*Erf[(Sqrt[b]*Sqrt[c + d*x])/Sqrt[d]])/d^(3/2) + (Sqrt[b]*E^(a - (b*c)/d)*Sqrt[Pi]*Erfi[(Sqrt[b]*Sqrt[c + d*x])/Sqrt[d]])/d^(3/2)}

{Cosh[a + b*x]^2*Sqrt[c + d*x], x, 8, (c + d*x)^(3/2)/(3*d) + (Sqrt[d]*Sqrt[Pi/2]*Erf[(Sqrt[2]*Sqrt[b]*Sqrt[c + d*x])/Sqrt[d]])/(E^(2*(a - (b*c)/d))*(16*b^(3/2))) - (Sqrt[d]*E^(2*(a - (b*c)/d))*Sqrt[Pi/2]*Erfi[(Sqrt[2]*Sqrt[b]*Sqrt[c + d*x])/Sqrt[d]])/(16*b^(3/2)) + (Sqrt[c + d*x]*Sinh[2*a + 2*b*x])/(4*b)}
{Cosh[a + b*x]^2/Sqrt[c + d*x], x, 6, Sqrt[c + d*x]/d + (E^((2*(b*c - a*d))/d)*Sqrt[Pi/2]*Erf[(Sqrt[2]*Sqrt[b]*Sqrt[c + d*x])/Sqrt[d]])/(4*Sqrt[b]*Sqrt[d]) + (Sqrt[Pi/2]*Erfi[(Sqrt[2]*Sqrt[b]*Sqrt[c + d*x])/Sqrt[d]])/(E^((2*(b*c - a*d))/d)*(4*Sqrt[b]*Sqrt[d]))}
{Cosh[a + b*x]^2/(c + d*x)^(3/2), x, 6, -((2*Cosh[a + b*x]^2)/(d*Sqrt[c + d*x])) - (Sqrt[b]*Sqrt[Pi/2]*Erf[(Sqrt[2]*Sqrt[b]*Sqrt[c + d*x])/Sqrt[d]])/(E^(2*(a - (b*c)/d))*d^(3/2)) + (Sqrt[b]*E^(2*(a - (b*c)/d))*Sqrt[Pi/2]*Erfi[(Sqrt[2]*Sqrt[b]*Sqrt[c + d*x])/Sqrt[d]])/d^(3/2)}


(* ::Subsection::Closed:: *)
(*(d+e x)^m Cosh[a+b x+c x^2]^n*)


(* Integrands of the form x^m*Cosh[a+b*x+c*x^2] where m is an integer *)
{x^2*Cosh[a + b*x + c*x^2], x, 16, ((b^2 + 2*c)*E^(-a + b^2/(4*c))*Sqrt[Pi]*Erf[(b + 2*c*x)/(2*Sqrt[c])])/(16*c^(5/2)) + ((b^2 - 2*c)*E^(a - b^2/(4*c))*Sqrt[Pi]*Erfi[(b + 2*c*x)/(2*Sqrt[c])])/(16*c^(5/2)) - (b*Sinh[a + b*x + c*x^2])/(4*c^2) + (x*Sinh[a + b*x + c*x^2])/(2*c)}
{x*Cosh[a + b*x + c*x^2], x, 8, -((b*E^(-a + b^2/(4*c))*Sqrt[Pi]*Erf[(b + 2*c*x)/(2*Sqrt[c])])/(8*c^(3/2))) - (b*E^(a - b^2/(4*c))*Sqrt[Pi]*Erfi[(b + 2*c*x)/(2*Sqrt[c])])/(8*c^(3/2)) + Sinh[a + b*x + c*x^2]/(2*c)}
{Cosh[a + b*x + c*x^2], x, 7, (E^(-a + b^2/(4*c))*Sqrt[Pi]*Erf[(b + 2*c*x)/(2*Sqrt[c])])/(4*Sqrt[c]) + (E^(a - b^2/(4*c))*Sqrt[Pi]*Erfi[(b + 2*c*x)/(2*Sqrt[c])])/(4*Sqrt[c])}
{Cosh[a + b*x + c*x^2]/x, x, 0, Int[Cosh[a + b*x + c*x^2]/x, x]}
{Cosh[a + b*x + c*x^2]/x^2 - b*Sinh[a + b*x + c*x^2]/x, x, 9, -(Cosh[a + b*x + c*x^2]/x) - (1/2)*Sqrt[c]*E^(-a + b^2/(4*c))*Sqrt[Pi]*Erf[(b + 2*c*x)/(2*Sqrt[c])] + (1/2)*Sqrt[c]*E^(a - b^2/(4*c))*Sqrt[Pi]*Erfi[(b + 2*c*x)/(2*Sqrt[c])]}

{x^2*Cosh[a + b*x - c*x^2], x, 16, -(((b^2 + 2*c)*E^(a + b^2/(4*c))*Sqrt[Pi]*Erf[(b - 2*c*x)/(2*Sqrt[c])])/(16*c^(5/2))) - ((b^2 - 2*c)*E^(-a - b^2/(4*c))*Sqrt[Pi]*Erfi[(b - 2*c*x)/(2*Sqrt[c])])/(16*c^(5/2)) - (b*Sinh[a + b*x - c*x^2])/(4*c^2) - (x*Sinh[a + b*x - c*x^2])/(2*c)}
{x*Cosh[a + b*x - c*x^2], x, 8, -((b*E^(a + b^2/(4*c))*Sqrt[Pi]*Erf[(b - 2*c*x)/(2*Sqrt[c])])/(8*c^(3/2))) - (b*E^(-a - b^2/(4*c))*Sqrt[Pi]*Erfi[(b - 2*c*x)/(2*Sqrt[c])])/(8*c^(3/2)) - Sinh[a + b*x - c*x^2]/(2*c)}
{Cosh[a + b*x - c*x^2], x, 7, -((E^(a + b^2/(4*c))*Sqrt[Pi]*Erf[(b - 2*c*x)/(2*Sqrt[c])])/(4*Sqrt[c])) - (E^(-a - b^2/(4*c))*Sqrt[Pi]*Erfi[(b - 2*c*x)/(2*Sqrt[c])])/(4*Sqrt[c])}
{Cosh[a + b*x - c*x^2]/x, x, 0, Int[Cosh[a + b*x - c*x^2]/x, x]}
{Cosh[a + b*x - c*x^2]/x^2 - b*Sinh[a + b*x - c*x^2]/x, x, 9, -(Cosh[a + b*x - c*x^2]/x) + (1/2)*Sqrt[c]*E^(a + b^2/(4*c))*Sqrt[Pi]*Erf[(b - 2*c*x)/(2*Sqrt[c])] - (1/2)*Sqrt[c]*E^(-a - b^2/(4*c))*Sqrt[Pi]*Erfi[(b - 2*c*x)/(2*Sqrt[c])]}

{x^2*Cosh[1/4 + x + x^2], x, 12, (3/16)*Sqrt[Pi]*Erf[(1/2)*(1 + 2*x)] - (1/16)*Sqrt[Pi]*Erfi[(1/2)*(1 + 2*x)] - (1/4)*Sinh[1/4 + x + x^2] + (1/2)*x*Sinh[1/4 + x + x^2]}
{x*Cosh[1/4 + x + x^2], x, 6, (-(1/8))*Sqrt[Pi]*Erf[(1/2)*(1 + 2*x)] - (1/8)*Sqrt[Pi]*Erfi[(1/2)*(1 + 2*x)] + (1/2)*Sinh[1/4 + x + x^2]}
{Cosh[1/4 + x + x^2], x, 5, (1/4)*Sqrt[Pi]*Erf[(1/2)*(1 + 2*x)] + (1/4)*Sqrt[Pi]*Erfi[(1/2)*(1 + 2*x)]}
{Cosh[1/4 + x + x^2]/x, x, 0, Int[Cosh[1/4 + x + x^2]/x, x]}
{Cosh[1/4 + x + x^2]/x^2, x, 6, -(Cosh[1/4 + x + x^2]/x) - (1/2)*Sqrt[Pi]*Erf[(1/2)*(1 + 2*x)] + (1/2)*Sqrt[Pi]*Erfi[(1/2)*(1 + 2*x)] + Int[Sinh[1/4 + x + x^2]/x, x]}


(* Integrands of the form x^m*Cos[a+b*x+c*x^2]^2 where m is an integer *)
{x^2*Cosh[a + b*x + c*x^2]^2, x, 19, x^3/6 + ((b^2 + c)*E^(-2*a + b^2/(2*c))*Sqrt[Pi/2]*Erf[(b + 2*c*x)/(Sqrt[2]*Sqrt[c])])/(32*c^(5/2)) + ((b^2 - c)*E^(2*a - b^2/(2*c))*Sqrt[Pi/2]*Erfi[(b + 2*c*x)/(Sqrt[2]*Sqrt[c])])/(32*c^(5/2)) - (b*Sinh[2*a + 2*b*x + 2*c*x^2])/(16*c^2) + (x*Sinh[2*a + 2*b*x + 2*c*x^2])/(8*c)}
{x*Cosh[a + b*x + c*x^2]^2, x, 11, x^2/4 - (b*E^(-2*a + b^2/(2*c))*Sqrt[Pi/2]*Erf[(b + 2*c*x)/(Sqrt[2]*Sqrt[c])])/(16*c^(3/2)) - (b*E^(2*a - b^2/(2*c))*Sqrt[Pi/2]*Erfi[(b + 2*c*x)/(Sqrt[2]*Sqrt[c])])/(16*c^(3/2)) + Sinh[2*a + 2*b*x + 2*c*x^2]/(8*c)}
{Cosh[a + b*x + c*x^2]^2, x, 9, x/2 + (E^(-2*a + b^2/(2*c))*Sqrt[Pi/2]*Erf[(b + 2*c*x)/(Sqrt[2]*Sqrt[c])])/(8*Sqrt[c]) + (E^(2*a - b^2/(2*c))*Sqrt[Pi/2]*Erfi[(b + 2*c*x)/(Sqrt[2]*Sqrt[c])])/(8*Sqrt[c])}
{Cosh[a + b*x + c*x^2]^2/x, x, 3, (1/2)*Int[Cosh[2*a + 2*b*x + 2*c*x^2]/x, x] + Log[x]/2}

{x^2*Cosh[a + b*x - c*x^2]^2, x, 19, x^3/6 - ((b^2 + c)*E^(2*a + b^2/(2*c))*Sqrt[Pi/2]*Erf[(b - 2*c*x)/(Sqrt[2]*Sqrt[c])])/(32*c^(5/2)) - ((b^2 - c)*E^(-2*a - b^2/(2*c))*Sqrt[Pi/2]*Erfi[(b - 2*c*x)/(Sqrt[2]*Sqrt[c])])/(32*c^(5/2)) - (b*Sinh[2*a + 2*b*x - 2*c*x^2])/(16*c^2) - (x*Sinh[2*a + 2*b*x - 2*c*x^2])/(8*c)}
{x*Cosh[a + b*x - c*x^2]^2, x, 11, x^2/4 - (b*E^(2*a + b^2/(2*c))*Sqrt[Pi/2]*Erf[(b - 2*c*x)/(Sqrt[2]*Sqrt[c])])/(16*c^(3/2)) - (b*E^(-2*a - b^2/(2*c))*Sqrt[Pi/2]*Erfi[(b - 2*c*x)/(Sqrt[2]*Sqrt[c])])/(16*c^(3/2)) - Sinh[2*a + 2*b*x - 2*c*x^2]/(8*c)}
{Cosh[a + b*x - c*x^2]^2, x, 9, x/2 - (E^(2*a + b^2/(2*c))*Sqrt[Pi/2]*Erf[(b - 2*c*x)/(Sqrt[2]*Sqrt[c])])/(8*Sqrt[c]) - (E^(-2*a - b^2/(2*c))*Sqrt[Pi/2]*Erfi[(b - 2*c*x)/(Sqrt[2]*Sqrt[c])])/(8*Sqrt[c])}
{Cosh[a + b*x - c*x^2]^2/x, x, 3, (1/2)*Int[Cosh[2*a + 2*b*x - 2*c*x^2]/x, x] + Log[x]/2}

{x^2*Cosh[1/4 + x + x^2]^2, x, 15, x^3/6 + (1/16)*Sqrt[Pi/2]*Erf[(1 + 2*x)/Sqrt[2]] - (1/16)*Sinh[1/2 + 2*x + 2*x^2] + (1/8)*x*Sinh[1/2 + 2*x + 2*x^2]}
{x*Cosh[1/4 + x + x^2]^2, x, 9, x^2/4 - (1/16)*Sqrt[Pi/2]*Erf[(1 + 2*x)/Sqrt[2]] - (1/16)*Sqrt[Pi/2]*Erfi[(1 + 2*x)/Sqrt[2]] + (1/8)*Sinh[1/2 + 2*x + 2*x^2]}
{Cosh[1/4 + x + x^2]^2, x, 7, x/2 + (1/8)*Sqrt[Pi/2]*Erf[(1 + 2*x)/Sqrt[2]] + (1/8)*Sqrt[Pi/2]*Erfi[(1 + 2*x)/Sqrt[2]]}
{Cosh[1/4 + x + x^2]^2/x, x, 3, (1/2)*Int[Cosh[1/2 + 2*x + 2*x^2]/x, x] + Log[x]/2}


(* Integrands of the form (d+e*x)^m*Cosh[a+b*x+c*x^2]^n where m and n are integers *)
{(d + e*x)^2*Cosh[a + b*x + c*x^2], x, 16, ((4*c^2*d^2 - 2*c*(2*b*d - e)*e + b^2*e^2)*E^(-a + b^2/(4*c))*Sqrt[Pi]*Erf[(b + 2*c*x)/(2*Sqrt[c])])/(16*c^(5/2)) + ((4*c^2*d^2 + b^2*e^2 - 2*c*e*(2*b*d + e))*E^(a - b^2/(4*c))*Sqrt[Pi]*Erfi[(b + 2*c*x)/(2*Sqrt[c])])/(16*c^(5/2)) + (e*(4*c*d - b*e)*Sinh[a + b*x + c*x^2])/(4*c^2) + (e^2*x*Sinh[a + b*x + c*x^2])/(2*c)}
{(d + e*x)*Cosh[a + b*x + c*x^2], x, 8, ((2*c*d - b*e)*E^(-a + b^2/(4*c))*Sqrt[Pi]*Erf[(b + 2*c*x)/(2*Sqrt[c])])/(8*c^(3/2)) + ((2*c*d - b*e)*E^(a - b^2/(4*c))*Sqrt[Pi]*Erfi[(b + 2*c*x)/(2*Sqrt[c])])/(8*c^(3/2)) + (e*Sinh[a + b*x + c*x^2])/(2*c)}
{Cosh[a + b*x + c*x^2]/(d + e*x), x, 0, Int[Cosh[a + b*x + c*x^2]/(d + e*x), x]}

{(d + e*x)^2*Cosh[a + b*x + c*x^2]^2, x, 41, (d^2*x)/2 + (1/2)*d*e*x^2 + (e^2*x^3)/6 + ((4*c^2*d^2 - c*(4*b*d - e)*e + b^2*e^2)*E^(-2*a + b^2/(2*c))*Sqrt[Pi/2]*Erf[(b + 2*c*x)/(Sqrt[2]*Sqrt[c])])/(32*c^(5/2)) + ((4*c^2*d^2 + b^2*e^2 - c*e*(4*b*d + e))*E^(2*a - b^2/(2*c))*Sqrt[Pi/2]*Erfi[(b + 2*c*x)/(Sqrt[2]*Sqrt[c])])/(32*c^(5/2)) + (d*e*Sinh[2*a + 2*b*x + 2*c*x^2])/(4*c) - (b*e^2*Sinh[2*a + 2*b*x + 2*c*x^2])/(16*c^2) + (e^2*x*Sinh[2*a + 2*b*x + 2*c*x^2])/(8*c)}
{(d + e*x)*Cosh[a + b*x + c*x^2]^2, x, 22, (d*x)/2 + (e*x^2)/4 + ((2*c*d - b*e)*E^(-2*a + b^2/(2*c))*Sqrt[Pi/2]*Erf[(b + 2*c*x)/(Sqrt[2]*Sqrt[c])])/(16*c^(3/2)) + ((2*c*d - b*e)*E^(2*a - b^2/(2*c))*Sqrt[Pi/2]*Erfi[(b + 2*c*x)/(Sqrt[2]*Sqrt[c])])/(16*c^(3/2)) + (e*Sinh[2*a + 2*b*x + 2*c*x^2])/(8*c)}
{Cosh[a + b*x + c*x^2]^2/(d + e*x), x, 3, (1/2)*Int[Cosh[2*a + 2*b*x + 2*c*x^2]/(d + e*x), x] + Log[d + e*x]/(2*e)}


(* ::Subsection::Closed:: *)
(*Cosh[(a+b x)/(c+d x)]^n*)


{Cosh[(a + b*x)/(c + d*x)], x, 5, ((c + d*x)*Cosh[(a + b*x)/(c + d*x)])/d + ((b*c - a*d)*CoshIntegral[-((b*c - a*d)/(d*(c + d*x)))]*Sinh[b/d])/d^2 + ((b*c - a*d)*Cosh[b/d]*SinhIntegral[a/(c + d*x) - (b*c)/(d*(c + d*x))])/d^2}
{Cosh[(a + b*x)/(c + d*x)]^2, x, 7, x/2 + ((c + d*x)*Cosh[(2*(a + b*x))/(c + d*x)])/(2*d) + ((b*c - a*d)*CoshIntegral[-((2*(b*c - a*d))/(d*(c + d*x)))]*Sinh[(2*b)/d])/d^2 + ((b*c - a*d)*Cosh[(2*b)/d]*SinhIntegral[(2*a)/(c + d*x) - (2*b*c)/(d*(c + d*x))])/d^2}


(* ::Subsection::Closed:: *)
(*x^m Cosh[a+b x^n]^p*)


{x^3*Cosh[a + b*x^2], x, 3, -(Cosh[a + b*x^2]/(2*b^2)) + (x^2*Sinh[a + b*x^2])/(2*b)}
{x^2*Cosh[a + b*x^2], x, 4, (Sqrt[Pi]*Erf[Sqrt[b]*x])/(E^a*(8*b^(3/2))) - (E^a*Sqrt[Pi]*Erfi[Sqrt[b]*x])/(8*b^(3/2)) + (x*Sinh[a + b*x^2])/(2*b)}
{x*Cosh[a + b*x^2], x, 2, Sinh[a + b*x^2]/(2*b)}
{Cosh[a + b*x^2], x, 3, (Sqrt[Pi]*Erf[Sqrt[b]*x])/(E^a*(4*Sqrt[b])) + (E^a*Sqrt[Pi]*Erfi[Sqrt[b]*x])/(4*Sqrt[b])}
{Cosh[a + b*x^2]/x, x, 3, (1/2)*Cosh[a]*CoshIntegral[b*x^2] + (1/2)*Sinh[a]*SinhIntegral[b*x^2]}
{Cosh[a + b*x^2]/x^2, x, 4, -(Cosh[a + b*x^2]/x) - ((1/2)*Sqrt[b]*Sqrt[Pi]*Erf[Sqrt[b]*x])/E^a + (1/2)*Sqrt[b]*E^a*Sqrt[Pi]*Erfi[Sqrt[b]*x]}
{Cosh[a + b*x^2]/x^3, x, 4, -(Cosh[a + b*x^2]/(2*x^2)) + (1/2)*b*CoshIntegral[b*x^2]*Sinh[a] + (1/2)*b*Cosh[a]*SinhIntegral[b*x^2]}


{x^3*Cosh[a + b*x^2]^2, x, 2, x^4/8 - Cosh[a + b*x^2]^2/(8*b^2) + (x^2*Cosh[a + b*x^2]*Sinh[a + b*x^2])/(4*b)}
{x^2*Cosh[a + b*x^2]^2, x, 7, x^3/6 + (Sqrt[Pi/2]*Erf[Sqrt[2]*Sqrt[b]*x])/(E^(2*a)*(32*b^(3/2))) - (E^(2*a)*Sqrt[Pi/2]*Erfi[Sqrt[2]*Sqrt[b]*x])/(32*b^(3/2)) + (x*Sinh[2*a + 2*b*x^2])/(8*b)}
{x*Cosh[a + b*x^2]^2, x, 2, x^2/4 + (Cosh[a + b*x^2]*Sinh[a + b*x^2])/(4*b)}
{Cosh[a + b*x^2]^2, x, 5, x/2 + (Sqrt[Pi/2]*Erf[Sqrt[2]*Sqrt[b]*x])/(E^(2*a)*(8*Sqrt[b])) + (E^(2*a)*Sqrt[Pi/2]*Erfi[Sqrt[2]*Sqrt[b]*x])/(8*Sqrt[b])}
{Cosh[a + b*x^2]^2/x, x, 7, (1/4)*Cosh[2*a]*CoshIntegral[2*b*x^2] + Log[x^2]/4 + (1/4)*Sinh[2*a]*SinhIntegral[2*b*x^2]}
{Cosh[a + b*x^2]^2/x^2, x, 5, -(Cosh[a + b*x^2]^2/x) - ((1/2)*Sqrt[b]*Sqrt[Pi/2]*Erf[Sqrt[2]*Sqrt[b]*x])/E^(2*a) + (1/2)*Sqrt[b]*E^(2*a)*Sqrt[Pi/2]*Erfi[Sqrt[2]*Sqrt[b]*x]}
{Cosh[a + b*x^2]^2/x^3, x, 8, -(1/(4*x^2)) - Cosh[2*a + 2*b*x^2]/(4*x^2) + (1/2)*b*CoshIntegral[2*b*x^2]*Sinh[2*a] + (1/2)*b*Cosh[2*a]*SinhIntegral[2*b*x^2]}


{x^3*Cosh[a + b*x^2]^3, x, 4, -(Cosh[a + b*x^2]/(3*b^2)) - Cosh[a + b*x^2]^3/(18*b^2) + (x^2*Sinh[a + b*x^2])/(3*b) + (x^2*Cosh[a + b*x^2]^2*Sinh[a + b*x^2])/(6*b)}
{x^2*Cosh[a + b*x^2]^3, x, 10, (3*Sqrt[Pi]*Erf[Sqrt[b]*x])/(E^a*(32*b^(3/2))) + (Sqrt[Pi/3]*Erf[Sqrt[3]*Sqrt[b]*x])/(E^(3*a)*(96*b^(3/2))) - (3*E^a*Sqrt[Pi]*Erfi[Sqrt[b]*x])/(32*b^(3/2)) - (E^(3*a)*Sqrt[Pi/3]*Erfi[Sqrt[3]*Sqrt[b]*x])/(96*b^(3/2)) + (3*x*Sinh[a + b*x^2])/(8*b) + (x*Sinh[3*a + 3*b*x^2])/(24*b)}
{x*Cosh[a + b*x^2]^3, x, 3, Sinh[a + b*x^2]/(2*b) + Sinh[a + b*x^2]^3/(6*b)}
{Cosh[a + b*x^2]^3, x, 8, (3*Sqrt[Pi]*Erf[Sqrt[b]*x])/(E^a*(16*Sqrt[b])) + (Sqrt[Pi/3]*Erf[Sqrt[3]*Sqrt[b]*x])/(E^(3*a)*(16*Sqrt[b])) + (3*E^a*Sqrt[Pi]*Erfi[Sqrt[b]*x])/(16*Sqrt[b]) + (E^(3*a)*Sqrt[Pi/3]*Erfi[Sqrt[3]*Sqrt[b]*x])/(16*Sqrt[b])}
{Cosh[a + b*x^2]^3/x, x, 9, (3/8)*Cosh[a]*CoshIntegral[b*x^2] + (1/8)*Cosh[3*a]*CoshIntegral[3*b*x^2] + (3/8)*Sinh[a]*SinhIntegral[b*x^2] + (1/8)*Sinh[3*a]*SinhIntegral[3*b*x^2]}
{Cosh[a + b*x^2]^3/x^2, x, 9, -(Cosh[a + b*x^2]^3/x) - ((3/8)*Sqrt[b]*Sqrt[Pi]*Erf[Sqrt[b]*x])/E^a - ((1/8)*Sqrt[b]*Sqrt[3*Pi]*Erf[Sqrt[3]*Sqrt[b]*x])/E^(3*a) + (3/8)*Sqrt[b]*E^a*Sqrt[Pi]*Erfi[Sqrt[b]*x] + (1/8)*Sqrt[b]*E^(3*a)*Sqrt[3*Pi]*Erfi[Sqrt[3]*Sqrt[b]*x]}
{Cosh[a + b*x^2]^3/x^3, x, 11, -((3*Cosh[a + b*x^2])/(8*x^2)) - Cosh[3*a + 3*b*x^2]/(8*x^2) + (3/8)*b*CoshIntegral[b*x^2]*Sinh[a] + (3/8)*b*CoshIntegral[3*b*x^2]*Sinh[3*a] + (3/8)*b*Cosh[a]*SinhIntegral[b*x^2] + (3/8)*b*Cosh[3*a]*SinhIntegral[3*b*x^2]}


{x*Cosh[a + b*x^2]^7, x, 3, Sinh[a + b*x^2]/(2*b) + Sinh[a + b*x^2]^3/(2*b) + (3*Sinh[a + b*x^2]^5)/(10*b) + Sinh[a + b*x^2]^7/(14*b)}


(* Integrands of the form Cosh[a+b/x^n]/x^m where m and n are positive integers *)
{Cosh[a + b/x], x, 4, x*Cosh[a + b/x] - b*CoshIntegral[b/x]*Sinh[a] - b*Cosh[a]*SinhIntegral[b/x]}
{Cosh[a + b/x]/x, x, 3, (-Cosh[a])*CoshIntegral[b/x] - Sinh[a]*SinhIntegral[b/x]}
{Cosh[a + b/x]/x^2, x, 2, -(Sinh[a + b/x]/b)}
{Cosh[a + b/x]/x^3, x, 3, Cosh[a + b/x]/b^2 - Sinh[a + b/x]/(b*x)}
{Cosh[a + b/x]/x^4, x, 4, (2*Cosh[a + b/x])/(b^2*x) - (2*Sinh[a + b/x])/b^3 - Sinh[a + b/x]/(b*x^2)}


{Cosh[a + b/x^2], x, 5, x*Cosh[a + b/x^2] + ((1/2)*Sqrt[b]*Sqrt[Pi]*Erf[Sqrt[b]/x])/E^a - (1/2)*Sqrt[b]*E^a*Sqrt[Pi]*Erfi[Sqrt[b]/x]}
{Cosh[a + b/x^2]/x, x, 3, (-(1/2))*Cosh[a]*CoshIntegral[b/x^2] - (1/2)*Sinh[a]*SinhIntegral[b/x^2]}
{Cosh[a + b/x^2]/x^2, x, 4, -((Sqrt[Pi]*Erf[Sqrt[b]/x])/(E^a*(4*Sqrt[b]))) - (E^a*Sqrt[Pi]*Erfi[Sqrt[b]/x])/(4*Sqrt[b])}
{Cosh[a + b/x^2]/x^3, x, 2, -(Sinh[a + b/x^2]/(2*b))}
{Cosh[a + b/x^2]/x^4, x, 5, -((Sqrt[Pi]*Erf[Sqrt[b]/x])/(E^a*(8*b^(3/2)))) + (E^a*Sqrt[Pi]*Erfi[Sqrt[b]/x])/(8*b^(3/2)) - Sinh[a + b/x^2]/(2*b*x)}


{Cosh[a + b*x^n], x, 3, -((E^a*x*Gamma[1/n, (-b)*x^n])/(((-b)*x^n)^n^(-1)*(2*n))) - (x*Gamma[1/n, b*x^n])/(E^a*(b*x^n)^n^(-1)*(2*n))}
{Cosh[a + b*x^n]^2, x, 5, x/2 - (2^(-2 - 1/n)*E^(2*a)*x*Gamma[1/n, -2*b*x^n])/(((-b)*x^n)^n^(-1)*n) - (2^(-2 - 1/n)*x*Gamma[1/n, 2*b*x^n])/(E^(2*a)*(b*x^n)^n^(-1)*n)}
{Cosh[a + b*x^n]^3, x, 8, -((E^(3*a)*x*Gamma[1/n, -3*b*x^n])/(3^n^(-1)*((-b)*x^n)^n^(-1)*(8*n))) - (3*E^a*x*Gamma[1/n, (-b)*x^n])/(((-b)*x^n)^n^(-1)*(8*n)) - (3*x*Gamma[1/n, b*x^n])/(E^a*(b*x^n)^n^(-1)*(8*n)) - (x*Gamma[1/n, 3*b*x^n])/(3^n^(-1)*E^(3*a)*(b*x^n)^n^(-1)*(8*n))}

{x^m*Cosh[a + b*x^n], x, 3, -((E^a*x^(1 + m)*Gamma[(1 + m)/n, (-b)*x^n])/(((-b)*x^n)^((1 + m)/n)*(2*n))) - (x^(1 + m)*Gamma[(1 + m)/n, b*x^n])/(E^a*(b*x^n)^((1 + m)/n)*(2*n))}
{x^m*Cosh[a + b*x^n]^2, x, 6, x^(1 + m)/(2*(1 + m)) - (2^(-2 - (1 + m)/n)*E^(2*a)*x^(1 + m)*Gamma[(1 + m)/n, -2*b*x^n])/(((-b)*x^n)^((1 + m)/n)*n) - (2^(-2 - (1 + m)/n)*x^(1 + m)*Gamma[(1 + m)/n, 2*b*x^n])/(E^(2*a)*(b*x^n)^((1 + m)/n)*n)}
{x^m*Cosh[a + b*x^n]^3, x, 8, -((E^(3*a)*x^(1 + m)*Gamma[(1 + m)/n, -3*b*x^n])/(3^((1 + m)/n)*((-b)*x^n)^((1 + m)/n)*(8*n))) - (3*E^a*x^(1 + m)*Gamma[(1 + m)/n, (-b)*x^n])/(((-b)*x^n)^((1 + m)/n)*(8*n)) - (3*x^(1 + m)*Gamma[(1 + m)/n, b*x^n])/(E^a*(b*x^n)^((1 + m)/n)*(8*n)) - (x^(1 + m)*Gamma[(1 + m)/n, 3*b*x^n])/(3^((1 + m)/n)*E^(3*a)*(b*x^n)^((1 + m)/n)*(8*n))}

{Cosh[a + b*x^n]/x^(n + 1), x, 4, -(Cosh[a + b*x^n]/(x^n*n)) + (b*CoshIntegral[b*x^n]*Sinh[a])/n + (b*Cosh[a]*SinhIntegral[b*x^n])/n}
{Sin[a + b*x^n]^2/x^(n + 1), x, 7, -(1/(x^n*(2*n))) + Cos[2*a + 2*b*x^n]/(x^n*(2*n)) + (b*CosIntegral[2*b*x^n]*Sin[2*a])/n + (b*Cos[2*a]*SinIntegral[2*b*x^n])/n}
{Sin[a + b*x^n]^3/x^(n + 1), x, 11, (3*b*Cos[a]*CosIntegral[b*x^n])/(4*n) - (3*b*Cos[3*a]*CosIntegral[3*b*x^n])/(4*n) - (3*Sin[a + b*x^n])/(x^n*(4*n)) + Sin[3*a + 3*b*x^n]/(x^n*(4*n)) - (3*b*Sin[a]*SinIntegral[b*x^n])/(4*n) + (3*b*Sin[3*a]*SinIntegral[3*b*x^n])/(4*n)}


(* Integrands of the form x^m*Cosh[x^n] where m and n are integers *)
{x^2*Cosh[x^3], x, 2, Sinh[x^3]/3}
{Cosh[x^(-5)]/x^6, x, 2, -Sinh[x^(-5)]/5}


(* ::Subsection::Closed:: *)
(*x^m Cosh[a+b Log[c x^n]]^p*)


(* Integrands of the form Cosh[a+b*Log[c*x^n]] *)
{Cosh[a + b*Log[c*x^n]], x, 1, (x*Cosh[a + b*Log[c*x^n]])/(1 - b^2*n^2) - (b*n*x*Sinh[a + b*Log[c*x^n]])/(1 - b^2*n^2)}
{Cosh[a + b*Log[c*x^n]]^2, x, 2, -((2*b^2*n^2*x)/(1 - 4*b^2*n^2)) + (x*Cosh[a + b*Log[c*x^n]]^2)/(1 - 4*b^2*n^2) - (2*b*n*x*Cosh[a + b*Log[c*x^n]]*Sinh[a + b*Log[c*x^n]])/(1 - 4*b^2*n^2)}
{Cosh[a + b*Log[c*x^n]]^3, x, 2, -((6*b^2*n^2*x*Cosh[a + b*Log[c*x^n]])/((1 - 9*b^2*n^2)*(1 - b^2*n^2))) + (x*Cosh[a + b*Log[c*x^n]]^3)/(1 - 9*b^2*n^2) + (6*b^3*n^3*x*Sinh[a + b*Log[c*x^n]])/((1 - 9*b^2*n^2)*(1 - b^2*n^2)) - (3*b*n*x*Cosh[a + b*Log[c*x^n]]^2*Sinh[a + b*Log[c*x^n]])/(1 - 9*b^2*n^2)}
{Cosh[a + b*Log[c*x^n]]^4, x, 3, (24*b^4*n^4*x)/((1 - 16*b^2*n^2)*(1 - 4*b^2*n^2)) - (12*b^2*n^2*x*Cosh[a + b*Log[c*x^n]]^2)/((1 - 16*b^2*n^2)*(1 - 4*b^2*n^2)) + (x*Cosh[a + b*Log[c*x^n]]^4)/(1 - 16*b^2*n^2) + (24*b^3*n^3*x*Cosh[a + b*Log[c*x^n]]*Sinh[a + b*Log[c*x^n]])/((1 - 16*b^2*n^2)*(1 - 4*b^2*n^2)) - (4*b*n*x*Cosh[a + b*Log[c*x^n]]^3*Sinh[a + b*Log[c*x^n]])/(1 - 16*b^2*n^2)}


(* Integrands of the form x^m*Cosh[a+b*Log[c*x^n]]^p where p is an integer *)
{x^m*Cosh[a + b*Log[c*x^n]], x, 1, ((1 + m)*x^(1 + m)*Cosh[a + b*Log[c*x^n]])/((1 + m)^2 - b^2*n^2) - (b*n*x^(1 + m)*Sinh[a + b*Log[c*x^n]])/((1 + m)^2 - b^2*n^2)}
{x^m*Cosh[a + b*Log[c*x^n]]^2, x, 2, -((2*b^2*n^2*x^(1 + m))/((1 + m)*((1 + m)^2 - 4*b^2*n^2))) + ((1 + m)*x^(1 + m)*Cosh[a + b*Log[c*x^n]]^2)/((1 + m)^2 - 4*b^2*n^2) - (2*b*n*x^(1 + m)*Cosh[a + b*Log[c*x^n]]*Sinh[a + b*Log[c*x^n]])/((1 + m)^2 - 4*b^2*n^2)}
{x^m*Cosh[a + b*Log[c*x^n]]^3, x, 2, -((6*b^2*(1 + m)*n^2*x^(1 + m)*Cosh[a + b*Log[c*x^n]])/(((1 + m)^2 - 9*b^2*n^2)*((1 + m)^2 - b^2*n^2))) + ((1 + m)*x^(1 + m)*Cosh[a + b*Log[c*x^n]]^3)/((1 + m)^2 - 9*b^2*n^2) + (6*b^3*n^3*x^(1 + m)*Sinh[a + b*Log[c*x^n]])/(((1 + m)^2 - 9*b^2*n^2)*((1 + m)^2 - b^2*n^2)) - (3*b*n*x^(1 + m)*Cosh[a + b*Log[c*x^n]]^2*Sinh[a + b*Log[c*x^n]])/((1 + m)^2 - 9*b^2*n^2)}
{x^m*Cosh[a + b*Log[c*x^n]]^4, x, 3, (24*b^4*n^4*x^(1 + m))/((1 + m)*((1 + m)^2 - 16*b^2*n^2)*((1 + m)^2 - 4*b^2*n^2)) - (12*b^2*(1 + m)*n^2*x^(1 + m)*Cosh[a + b*Log[c*x^n]]^2)/(((1 + m)^2 - 16*b^2*n^2)*((1 + m)^2 - 4*b^2*n^2)) + ((1 + m)*x^(1 + m)*Cosh[a + b*Log[c*x^n]]^4)/((1 + m)^2 - 16*b^2*n^2) + (24*b^3*n^3*x^(1 + m)*Cosh[a + b*Log[c*x^n]]*Sinh[a + b*Log[c*x^n]])/(((1 + m)^2 - 16*b^2*n^2)*((1 + m)^2 - 4*b^2*n^2)) - (4*b*n*x^(1 + m)*Cosh[a + b*Log[c*x^n]]^3*Sinh[a + b*Log[c*x^n]])/((1 + m)^2 - 16*b^2*n^2)}


(* Integrands of the form Cosh[a+b*Log[c*x^n]]^p/x where p is an integer *)
{Cosh[a + b*Log[c*x^n]]/x, x, 2, Sinh[a + b*Log[c*x^n]]/(b*n)}
{Cosh[a + b*Log[c*x^n]]^2/x, x, 2, Log[c*x^n]/(2*n) + (Cosh[a + b*Log[c*x^n]]*Sinh[a + b*Log[c*x^n]])/(2*b*n)}
{Cosh[a + b*Log[c*x^n]]^3/x, x, 3, Sinh[a + b*Log[c*x^n]]/(b*n) + Sinh[a + b*Log[c*x^n]]^3/(3*b*n)}
{Cosh[a + b*Log[c*x^n]]^4/x, x, 3, (3*Log[c*x^n])/(8*n) + (3*Cosh[a + b*Log[c*x^n]]*Sinh[a + b*Log[c*x^n]])/(8*b*n) + (Cosh[a + b*Log[c*x^n]]^3*Sinh[a + b*Log[c*x^n]])/(4*b*n)}
{Cosh[a + b*Log[c*x^n]]^5/x, x, 3, Sinh[a + b*Log[c*x^n]]/(b*n) + (2*Sinh[a + b*Log[c*x^n]]^3)/(3*b*n) + Sinh[a + b*Log[c*x^n]]^5/(5*b*n)}


(* Integrands of the form Cosh[a+b*Log[c*x^n]]^p/x where p is a half-integer *)
{Cosh[a + b*Log[c*x^n]]^(5/2)/x, x, 3, -((6*I*EllipticE[(1/2)*I*(a + b*Log[c*x^n]), 2])/(5*b*n)) + (2*Cosh[a + b*Log[c*x^n]]^(3/2)*Sinh[a + b*Log[c*x^n]])/(5*b*n)}
{Cosh[a + b*Log[c*x^n]]^(3/2)/x, x, 3, -((2*I*EllipticF[(1/2)*I*(a + b*Log[c*x^n]), 2])/(3*b*n)) + (2*Sqrt[Cosh[a + b*Log[c*x^n]]]*Sinh[a + b*Log[c*x^n]])/(3*b*n)}
{Sqrt[Cosh[a + b*Log[c*x^n]]]/x, x, 2, -((2*I*EllipticE[(1/2)*I*(a + b*Log[c*x^n]), 2])/(b*n))}
{1/(x*Sqrt[Cosh[a + b*Log[c*x^n]]]), x, 2, -((2*I*EllipticF[(1/2)*I*(a + b*Log[c*x^n]), 2])/(b*n))}
{1/(x*Cosh[a + b*Log[c*x^n]]^(3/2)), x, 3, (2*I*EllipticE[(1/2)*I*(a + b*Log[c*x^n]), 2])/(b*n) + (2*Sinh[a + b*Log[c*x^n]])/(b*n*Sqrt[Cosh[a + b*Log[c*x^n]]])}
{1/(x*Cosh[a + b*Log[c*x^n]]^(5/2)), x, 3, -((2*I*EllipticF[(1/2)*I*(a + b*Log[c*x^n]), 2])/(3*b*n)) + (2*Sinh[a + b*Log[c*x^n]])/(3*b*n*Cosh[a + b*Log[c*x^n]]^(3/2))}


(* Integrands of the form Cosh[a+2/n*Log[c*x^n]]^p where p is a half-integer *)
{Cosh[a + 2/n*Log[c*x^n]]^(5/2), x, 6, (5*x*(Sqrt[1 + E^(2*a)*(c*x^n)^(4/n)] - ArcTanh[Sqrt[1 + E^(2*a)*(c*x^n)^(4/n)]])*Sqrt[Cosh[a + (2*Log[c*x^n])/n]])/(16*Sqrt[1 + E^(2*a)*(c*x^n)^(4/n)]) - (1/24)*x*Cosh[a + (2*Log[c*x^n])/n]^(5/2) + (5/24)*x*Cosh[a + (2*Log[c*x^n])/n]^(3/2)*Sinh[a + (2*Log[c*x^n])/n]}
{Sqrt[Cosh[a + 2/n*Log[c*x^n]]], x, 5, (x*(Sqrt[1 + E^(2*a)*(c*x^n)^(4/n)] - ArcTanh[Sqrt[1 + E^(2*a)*(c*x^n)^(4/n)]])*Sqrt[Cosh[a + (2*Log[c*x^n])/n]])/(2*Sqrt[1 + E^(2*a)*(c*x^n)^(4/n)])}
{1/Cosh[a + 2/n*Log[c*x^n]]^(3/2), x, 1, (-x)*Sqrt[Cosh[a + (2*Log[c*x^n])/n]] + (x*Sinh[a + (2*Log[c*x^n])/n])/Sqrt[Cosh[a + (2*Log[c*x^n])/n]]}
{1/Cosh[a + 2/n*Log[c*x^n]]^(7/2), x, 2, x/(15*Cosh[a + (2*Log[c*x^n])/n]^(3/2)) - (8/15)*x*Sqrt[Cosh[a + (2*Log[c*x^n])/n]] + (x*Sinh[a + (2*Log[c*x^n])/n])/(5*Cosh[a + (2*Log[c*x^n])/n]^(5/2)) + (8*x*Sinh[a + (2*Log[c*x^n])/n])/(15*Sqrt[Cosh[a + (2*Log[c*x^n])/n]])}


(* ::Subsection::Closed:: *)
(*Miscellaneous integrands involving one cosine*)


(* Integrands of the form x^m*Cosh[x]^n where m is an integer and n is a half-integer *)
{x/Cosh[x]^(3/2) + x*Sqrt[Cosh[x]], x, 2, -4*Sqrt[Cosh[x]] + (2*x*Sinh[x])/Sqrt[Cosh[x]]}
{x/Cosh[x]^(5/2) - x/(3*Sqrt[Cosh[x]]), x, 2, 4/(3*Sqrt[Cosh[x]]) + (2*x*Sinh[x])/(3*Cosh[x]^(3/2))}
{x/Cosh[x]^(7/2) + (3/5)*x*Sqrt[Cosh[x]], x, 3, 4/(15*Cosh[x]^(3/2)) - (12*Sqrt[Cosh[x]])/5 + (2*x*Sinh[x])/(5*Cosh[x]^(5/2)) + (6*x*Sinh[x])/(5*Sqrt[Cosh[x]])}
{x^2/Cosh[x]^(3/2) + x^2*Sqrt[Cosh[x]], x, 3, -8*x*Sqrt[Cosh[x]] - 16*I*EllipticE[(I*x)/2, 2] + (2*x^2*Sinh[x])/Sqrt[Cosh[x]]}


{(x + Cosh[x])^2, x, 6, x/2 + x^3/3 - 2*Cosh[x] + 2*x*Sinh[x] + (1/2)*Cosh[x]*Sinh[x]}
{(x + Cosh[x])^3, x, 10, (3*x^2)/4 + x^4/4 - 6*x*Cosh[x] - (3*Cosh[x]^2)/4 + 7*Sinh[x] + 3*x^2*Sinh[x] + (3/2)*x*Cosh[x]*Sinh[x] + Sinh[x]^3/3}


{Cosh[a + b*x]/(c + d*x^2), x, 10, (Cosh[a + (b*Sqrt[-c])/Sqrt[d]]*CoshIntegral[-((b*(Sqrt[-c] - Sqrt[d]*x))/Sqrt[d])])/(2*Sqrt[-c]*Sqrt[d]) - (Cosh[a - (b*Sqrt[-c])/Sqrt[d]]*CoshIntegral[-((b*(Sqrt[-c] + Sqrt[d]*x))/Sqrt[d])])/(2*Sqrt[-c]*Sqrt[d]) - (Sinh[a + (b*Sqrt[-c])/Sqrt[d]]*SinhIntegral[(b*Sqrt[-c])/Sqrt[d] - b*x])/(2*Sqrt[-c]*Sqrt[d]) - (Sinh[a - (b*Sqrt[-c])/Sqrt[d]]*SinhIntegral[(b*Sqrt[-c])/Sqrt[d] + b*x])/(2*Sqrt[-c]*Sqrt[d])}
{Cosh[a + b*x]/(c + d*x + e*x^2), x, 9, (Cosh[a - (b*(d - Sqrt[d^2 - 4*c*e]))/(2*e)]*CoshIntegral[(b*(d - Sqrt[d^2 - 4*c*e] + 2*e*x))/(2*e)])/Sqrt[d^2 - 4*c*e] - (Cosh[a - (b*(d + Sqrt[d^2 - 4*c*e]))/(2*e)]*CoshIntegral[(b*(d + Sqrt[d^2 - 4*c*e] + 2*e*x))/(2*e)])/Sqrt[d^2 - 4*c*e] + (Sinh[a - (b*(d - Sqrt[d^2 - 4*c*e]))/(2*e)]*SinhIntegral[(b*(d - Sqrt[d^2 - 4*c*e] + 2*e*x))/(2*e)])/Sqrt[d^2 - 4*c*e] - (Sinh[a - (b*(d + Sqrt[d^2 - 4*c*e]))/(2*e)]*SinhIntegral[(b*(d + Sqrt[d^2 - 4*c*e] + 2*e*x))/(2*e)])/Sqrt[d^2 - 4*c*e]}
