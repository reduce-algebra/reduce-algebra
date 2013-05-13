(* ::Package:: *)

(* ::Title:: *)
(*Integration Problems Involving Hyperbolic Cosecants*)


(* ::Section::Closed:: *)
(*Integrands of the form Csch[a+b x]^n*)


(* ::Subsection::Closed:: *)
(*Integrands of the form Csch[a+b x]^n*)


{Csch[a + b*x], x, 1, -(ArcTanh[Cosh[a + b*x]]/b)}
{Csch[a + b*x]^2, x, 1, -Coth[a + b*x]/b}
{Csch[a + b*x]^3, x, 2, ArcTanh[Cosh[a + b*x]]/(2*b) - (Coth[a + b*x]*Csch[a + b*x])/(2*b)}
{Csch[a + b*x]^4, x, 2, Coth[a + b*x]/b - Coth[a + b*x]^3/(3*b)}
{Csch[a + b*x]^5, x, 3, -((3*ArcTanh[Cosh[a + b*x]])/(8*b)) + (3*Coth[a + b*x]*Csch[a + b*x])/(8*b) - (Coth[a + b*x]*Csch[a + b*x]^3)/(4*b)}
{Csch[a + b*x]^6, x, 2, -(Coth[a + b*x]/b) + (2*Coth[a + b*x]^3)/(3*b) - Coth[a + b*x]^5/(5*b)}


(* ::Subsection::Closed:: *)
(*Integrands of the form Csch[a+b x]^(n/2)*)


{Csch[a + b*x]^(5/2), x, 3, -((2*Cosh[a + b*x]*Csch[a + b*x]^(3/2))/(3*b)) - (2*I*Sqrt[Csch[a + b*x]]*EllipticF[Pi/4 - (1/2)*I*(a + b*x), 2]*Sqrt[I*Sinh[a + b*x]])/(3*b)}
{Csch[a + b*x]^(3/2), x, 3, -((2*Cosh[a + b*x]*Sqrt[Csch[a + b*x]])/b) + (2*I*EllipticE[Pi/4 - (1/2)*I*(a + b*x), 2])/(b*Sqrt[Csch[a + b*x]]*Sqrt[I*Sinh[a + b*x]])}
{Csch[a + b*x]^(1/2), x, 2, (2*I*Sqrt[Csch[a + b*x]]*EllipticF[Pi/4 - (1/2)*I*(a + b*x), 2]*Sqrt[I*Sinh[a + b*x]])/b}
{1/Csch[a + b*x]^(1/2), x, 2, (2*I*EllipticE[Pi/4 - (1/2)*I*(a + b*x), 2])/(b*Sqrt[Csch[a + b*x]]*Sqrt[I*Sinh[a + b*x]])}
{1/Csch[a + b*x]^(3/2), x, 3, (2*Cosh[a + b*x])/(3*b*Sqrt[Csch[a + b*x]]) - (2*I*Sqrt[Csch[a + b*x]]*EllipticF[Pi/4 - (1/2)*I*(a + b*x), 2]*Sqrt[I*Sinh[a + b*x]])/(3*b)}
{1/Csch[a + b*x]^(5/2), x, 3, (2*Cosh[a + b*x])/(5*b*Csch[a + b*x]^(3/2)) - (6*I*EllipticE[Pi/4 - (1/2)*I*(a + b*x), 2])/(5*b*Sqrt[Csch[a + b*x]]*Sqrt[I*Sinh[a + b*x]])}


(* ::Section::Closed:: *)
(*Integrands of the form (c Csch[a+b x]^m)^n*)


(* ::Subsection::Closed:: *)
(*Integrands of the form (c Csch[a+b x])^n*)


{(b*Csch[c + d*x])^n, x, 2, -((b*Cosh[c + d*x]*(b*Csch[c + d*x])^(-1 + n)*Hypergeometric2F1[1/2, (1 + n)/2, 3/2, Cosh[c + d*x]^2]*(-Sinh[c + d*x]^2)^((1/2)*(-1 + n)))/d)}

{(b*Csch[c + d*x])^(7/2), x, 4, (6*b^3*Cosh[c + d*x]*Sqrt[b*Csch[c + d*x]])/(5*d) - (2*b*Cosh[c + d*x]*(b*Csch[c + d*x])^(5/2))/(5*d) - (6*I*b^4*EllipticE[Pi/4 - (1/2)*I*(c + d*x), 2])/(5*d*Sqrt[b*Csch[c + d*x]]*Sqrt[I*Sinh[c + d*x]])}
{(b*Csch[c + d*x])^(5/2), x, 3, -((2*b*Cosh[c + d*x]*(b*Csch[c + d*x])^(3/2))/(3*d)) - (2*I*b^2*Sqrt[b*Csch[c + d*x]]*EllipticF[Pi/4 - (1/2)*I*(c + d*x), 2]*Sqrt[I*Sinh[c + d*x]])/(3*d)}
{(b*Csch[c + d*x])^(3/2), x, 3, -((2*b*Cosh[c + d*x]*Sqrt[b*Csch[c + d*x]])/d) + (2*I*b^2*EllipticE[Pi/4 - (1/2)*I*(c + d*x), 2])/(d*Sqrt[b*Csch[c + d*x]]*Sqrt[I*Sinh[c + d*x]])}
{(b*Csch[c + d*x])^(1/2), x, 2, (2*I*Sqrt[b*Csch[c + d*x]]*EllipticF[Pi/4 - (1/2)*I*(c + d*x), 2]*Sqrt[I*Sinh[c + d*x]])/d}
{1/(b*Csch[c + d*x])^(1/2), x, 2, (2*I*EllipticE[Pi/4 - (1/2)*I*(c + d*x), 2])/(d*Sqrt[b*Csch[c + d*x]]*Sqrt[I*Sinh[c + d*x]])}
{1/(b*Csch[c + d*x])^(3/2), x, 3, (2*Cosh[c + d*x])/(3*b*d*Sqrt[b*Csch[c + d*x]]) - (2*I*Sqrt[b*Csch[c + d*x]]*EllipticF[Pi/4 - (1/2)*I*(c + d*x), 2]*Sqrt[I*Sinh[c + d*x]])/(3*b^2*d)}
{1/(b*Csch[c + d*x])^(5/2), x, 3, (2*Cosh[c + d*x])/(5*b*d*(b*Csch[c + d*x])^(3/2)) - (6*I*EllipticE[Pi/4 - (1/2)*I*(c + d*x), 2])/(5*b^2*d*Sqrt[b*Csch[c + d*x]]*Sqrt[I*Sinh[c + d*x]])}
{1/(b*Csch[c + d*x])^(7/2), x, 4, (2*Cosh[c + d*x])/(7*b*d*(b*Csch[c + d*x])^(5/2)) - (10*Cosh[c + d*x])/(21*b^3*d*Sqrt[b*Csch[c + d*x]]) + (10*I*Sqrt[b*Csch[c + d*x]]*EllipticF[Pi/4 - (1/2)*I*(c + d*x), 2]*Sqrt[I*Sinh[c + d*x]])/(21*b^4*d)}


(* ::Subsection::Closed:: *)
(*Integrands of the form (c Csch[a+b x]^2)^n*)


{(-Csch[x]^2)^(5/2), x, 4, (3/8)*ArcSin[Coth[x]] + (3/8)*Coth[x]*Sqrt[1 - Coth[x]^2] + (1/4)*Coth[x]*(1 - Coth[x]^2)^(3/2)}
{(-Csch[x]^2)^(3/2), x, 3, (1/2)*ArcSin[Coth[x]] + (1/2)*Coth[x]*Sqrt[1 - Coth[x]^2]}
{(-Csch[x]^2)^(1/2), x, 2, ArcSin[Coth[x]]}
{1/(-Csch[x]^2)^(1/2), x, 2, Coth[x]/Sqrt[-Csch[x]^2], Coth[x]/Sqrt[1 - Coth[x]^2]}
{1/(-Csch[x]^2)^(3/2), x, 3, Coth[x]/(3*(1 - Coth[x]^2)^(3/2)) + (2*Coth[x])/(3*Sqrt[1 - Coth[x]^2])}
{1/(-Csch[x]^2)^(5/2), x, 4, Coth[x]/(5*(1 - Coth[x]^2)^(5/2)) + (4*Coth[x])/(15*(1 - Coth[x]^2)^(3/2)) + (8*Coth[x])/(15*Sqrt[1 - Coth[x]^2])}
{1/(-Csch[x]^2)^(7/2), x, 5, Coth[x]/(7*(1 - Coth[x]^2)^(7/2)) + (6*Coth[x])/(35*(1 - Coth[x]^2)^(5/2)) + (8*Coth[x])/(35*(1 - Coth[x]^2)^(3/2)) + (16*Coth[x])/(35*Sqrt[1 - Coth[x]^2])}


{(a*Csch[x]^2)^(5/2), x, 4, (3/8)*a^2*Coth[x]*Sqrt[a*Csch[x]^2] - (1/4)*a^2*Coth[x]*Csch[x]^2*Sqrt[a*Csch[x]^2] - (3/8)*a^2*ArcTanh[Cosh[x]]*Sqrt[a*Csch[x]^2]*Sinh[x]}
{(a*Csch[x]^2)^(3/2), x, 3, (-(1/2))*a*Coth[x]*Sqrt[a*Csch[x]^2] + (1/2)*a*ArcTanh[Cosh[x]]*Sqrt[a*Csch[x]^2]*Sinh[x]}
{(a*Csch[x]^2)^(1/2), x, 2, (-ArcTanh[Cosh[x]])*Sqrt[a*Csch[x]^2]*Sinh[x]}
{1/(a*Csch[x]^2)^(1/2), x, 2, Coth[x]/Sqrt[a*Csch[x]^2]}
{1/(a*Csch[x]^2)^(3/2), x, 3, -(Coth[x]/(a*Sqrt[a*Csch[x]^2])) + (Cosh[x]^2*Coth[x])/(3*a*Sqrt[a*Csch[x]^2])}
{1/(a*Csch[x]^2)^(5/2), x, 3, Coth[x]/(a^2*Sqrt[a*Csch[x]^2]) - (2*Cosh[x]^2*Coth[x])/(3*a^2*Sqrt[a*Csch[x]^2]) + (Cosh[x]^4*Coth[x])/(5*a^2*Sqrt[a*Csch[x]^2])}
{1/(a*Csch[x]^2)^(7/2), x, 3, -(Coth[x]/(a^3*Sqrt[a*Csch[x]^2])) + (Cosh[x]^2*Coth[x])/(a^3*Sqrt[a*Csch[x]^2]) - (3*Cosh[x]^4*Coth[x])/(5*a^3*Sqrt[a*Csch[x]^2]) + (Cosh[x]^6*Coth[x])/(7*a^3*Sqrt[a*Csch[x]^2])}


(* ::Subsection::Closed:: *)
(*Integrands of the form (c Csch[a+b x]^3)^n*)


{(a*Csch[x]^3)^(5/2), x, 7, (-(154/585))*a^2*Coth[x]*Sqrt[a*Csch[x]^3] + (22/117)*a^2*Coth[x]*Csch[x]^2*Sqrt[a*Csch[x]^3] - (2/13)*a^2*Coth[x]*Csch[x]^4*Sqrt[a*Csch[x]^3] + (154/195)*a^2*Cosh[x]*Sqrt[a*Csch[x]^3]*Sinh[x] - (154*I*a^2*Sqrt[a*Csch[x]^3]*EllipticE[Pi/4 - (I*x)/2, 2]*Sinh[x]^2)/(195*Sqrt[I*Sinh[x]])}
{(a*Csch[x]^3)^(3/2), x, 5, (10/21)*a*Cosh[x]*Sqrt[a*Csch[x]^3] - (2/7)*a*Coth[x]*Csch[x]*Sqrt[a*Csch[x]^3] + (10/21)*I*a*Sqrt[a*Csch[x]^3]*EllipticF[Pi/4 - (I*x)/2, 2]*Sqrt[I*Sinh[x]]*Sinh[x]}
{(a*Csch[x]^3)^(1/2), x, 4, -2*Cosh[x]*Sqrt[a*Csch[x]^3]*Sinh[x] + (2*I*Sqrt[a*Csch[x]^3]*EllipticE[Pi/4 - (I*x)/2, 2]*Sinh[x]^2)/Sqrt[I*Sinh[x]]}
{1/(a*Csch[x]^3)^(1/2), x, 4, (2*Coth[x])/(3*Sqrt[a*Csch[x]^3]) - (2*I*Csch[x]^2*EllipticF[Pi/4 - (I*x)/2, 2]*Sqrt[I*Sinh[x]])/(3*Sqrt[a*Csch[x]^3])}
{1/(a*Csch[x]^3)^(3/2), x, 5, -((14*Cosh[x])/(45*a*Sqrt[a*Csch[x]^3])) + (14*I*Csch[x]*EllipticE[Pi/4 - (I*x)/2, 2])/(15*a*Sqrt[a*Csch[x]^3]*Sqrt[I*Sinh[x]]) + (2*Cosh[x]*Sinh[x]^2)/(9*a*Sqrt[a*Csch[x]^3])}
{1/(a*Csch[x]^3)^(5/2), x, 7, -((26*Coth[x])/(77*a^2*Sqrt[a*Csch[x]^3])) + (26*I*Csch[x]^2*EllipticF[Pi/4 - (I*x)/2, 2]*Sqrt[I*Sinh[x]])/(77*a^2*Sqrt[a*Csch[x]^3]) + (78*Cosh[x]*Sinh[x])/(385*a^2*Sqrt[a*Csch[x]^3]) - (26*Cosh[x]*Sinh[x]^3)/(165*a^2*Sqrt[a*Csch[x]^3]) + (2*Cosh[x]*Sinh[x]^5)/(15*a^2*Sqrt[a*Csch[x]^3])}


(* ::Subsection::Closed:: *)
(*Integrands of the form (c Csch[a+b x]^4)^n*)


{(a*Csch[x]^4)^(7/2), x, 3, 2*a^3*Cosh[x]^2*Coth[x]*Sqrt[a*Csch[x]^4] - 3*a^3*Cosh[x]^2*Coth[x]^3*Sqrt[a*Csch[x]^4] + (20/7)*a^3*Cosh[x]^2*Coth[x]^5*Sqrt[a*Csch[x]^4] - (5/3)*a^3*Cosh[x]^2*Coth[x]^7*Sqrt[a*Csch[x]^4] + (6/11)*a^3*Cosh[x]^2*Coth[x]^9*Sqrt[a*Csch[x]^4] - (1/13)*a^3*Cosh[x]^2*Coth[x]^11*Sqrt[a*Csch[x]^4] - a^3*Cosh[x]*Sqrt[a*Csch[x]^4]*Sinh[x]}
{(a*Csch[x]^4)^(5/2), x, 3, (4/3)*a^2*Cosh[x]^2*Coth[x]*Sqrt[a*Csch[x]^4] - (6/5)*a^2*Cosh[x]^2*Coth[x]^3*Sqrt[a*Csch[x]^4] + (4/7)*a^2*Cosh[x]^2*Coth[x]^5*Sqrt[a*Csch[x]^4] - (1/9)*a^2*Cosh[x]^2*Coth[x]^7*Sqrt[a*Csch[x]^4] - a^2*Cosh[x]*Sqrt[a*Csch[x]^4]*Sinh[x]}
{(a*Csch[x]^4)^(3/2), x, 3, (2/3)*a*Cosh[x]^2*Coth[x]*Sqrt[a*Csch[x]^4] - (1/5)*a*Cosh[x]^2*Coth[x]^3*Sqrt[a*Csch[x]^4] - a*Cosh[x]*Sqrt[a*Csch[x]^4]*Sinh[x]}
{(a*Csch[x]^4)^(1/2), x, 2, (-Cosh[x])*Sqrt[a*Csch[x]^4]*Sinh[x]}
{1/(a*Csch[x]^4)^(1/2), x, 2, Coth[x]/(2*Sqrt[a*Csch[x]^4]) - (x*Csch[x]^2)/(2*Sqrt[a*Csch[x]^4])}
{1/(a*Csch[x]^4)^(3/2), x, 4, (5*Coth[x])/(16*a*Sqrt[a*Csch[x]^4]) - (5*x*Csch[x]^2)/(16*a*Sqrt[a*Csch[x]^4]) - (5*Cosh[x]*Sinh[x])/(24*a*Sqrt[a*Csch[x]^4]) + (Cosh[x]*Sinh[x]^3)/(6*a*Sqrt[a*Csch[x]^4])}
{1/(a*Csch[x]^4)^(5/2), x, 6, (63*Coth[x])/(256*a^2*Sqrt[a*Csch[x]^4]) - (63*x*Csch[x]^2)/(256*a^2*Sqrt[a*Csch[x]^4]) - (21*Cosh[x]*Sinh[x])/(128*a^2*Sqrt[a*Csch[x]^4]) + (21*Cosh[x]*Sinh[x]^3)/(160*a^2*Sqrt[a*Csch[x]^4]) - (9*Cosh[x]*Sinh[x]^5)/(80*a^2*Sqrt[a*Csch[x]^4]) + (Cosh[x]*Sinh[x]^7)/(10*a^2*Sqrt[a*Csch[x]^4])}


(* ::Subsection:: *)
(*Integrands of the form (c Csch[a+b x]^m)^n*)


(* ::Section::Closed:: *)
(*Integrands of the form Hyper[c+d x]^m (a+b Csch[c+d x])^n*)


(* ::Subsection::Closed:: *)
(*Integrands of the form Sinh[c+d x]^m (a+b Csch[c+d x])^n*)


(* ::Subsubsection::Closed:: *)
(*a^2+b^2=0*)


{1/(a + I*a*Csch[a + b*x]), x, 2, x/a - Coth[a + b*x]/(b*(a + I*a*Csch[a + b*x]))}


{1/(a - I*a*Csch[a + b*x]), x, 2, x/a - Coth[a + b*x]/(b*(a - I*a*Csch[a + b*x]))}


{(a + a*I*Csch[c + d*x])^(5/2), x, 4, (2*a^(5/2)*ArcTanh[(Sqrt[a]*Coth[c + d*x])/Sqrt[a + I*a*Csch[c + d*x]]])/d + (14*a^3*Coth[c + d*x])/(3*d*Sqrt[a + I*a*Csch[c + d*x]]) + (2*a^2*Coth[c + d*x]*Sqrt[a + I*a*Csch[c + d*x]])/(3*d)}
{(a + a*I*Csch[c + d*x])^(3/2), x, 3, (2*a^(3/2)*ArcTanh[(Sqrt[a]*Coth[c + d*x])/Sqrt[a + I*a*Csch[c + d*x]]])/d + (2*a^2*Coth[c + d*x])/(d*Sqrt[a + I*a*Csch[c + d*x]])}
{(a + a*I*Csch[c + d*x])^(1/2), x, 1, (2*Sqrt[a]*ArcTanh[(Sqrt[a]*Coth[c + d*x])/Sqrt[a + I*a*Csch[c + d*x]]])/d}
{1/(a + a*I*Csch[c + d*x])^(1/2), x, 3, (2*ArcTanh[(Sqrt[a]*Coth[c + d*x])/Sqrt[a + I*a*Csch[c + d*x]]])/(Sqrt[a]*d) - (Sqrt[2]*ArcTanh[(Sqrt[a]*Coth[c + d*x])/(Sqrt[2]*Sqrt[a + I*a*Csch[c + d*x]])])/(Sqrt[a]*d)}
{1/(a + a*I*Csch[c + d*x])^(3/2), x, 4, (2*ArcTanh[(Sqrt[a]*Coth[c + d*x])/Sqrt[a + I*a*Csch[c + d*x]]])/(a^(3/2)*d) - (5*ArcTanh[(Sqrt[a]*Coth[c + d*x])/(Sqrt[2]*Sqrt[a + I*a*Csch[c + d*x]])])/(2*Sqrt[2]*a^(3/2)*d) - Coth[c + d*x]/(2*d*(a + I*a*Csch[c + d*x])^(3/2))}

{Sqrt[a - a*I*Csch[c + d*x]], x, 1, (2*Sqrt[a]*ArcTanh[(Sqrt[a]*Coth[c + d*x])/Sqrt[a - I*a*Csch[c + d*x]]])/d}
{1/Sqrt[a - I*a*Csch[c + d*x]], x, 3, (2*ArcTanh[(Sqrt[a]*Coth[c + d*x])/Sqrt[a - I*a*Csch[c + d*x]]])/(Sqrt[a]*d) - (Sqrt[2]*ArcTanh[(Sqrt[a]*Coth[c + d*x])/(Sqrt[2]*Sqrt[a - I*a*Csch[c + d*x]])])/(Sqrt[a]*d)}


{Sqrt[3 + 3*I*Csch[x]], x, 1, 2*Sqrt[3]*ArcTanh[Coth[x]/Sqrt[1 + I*Csch[x]]]}
{Sqrt[3 - 3*I*Csch[x]], x, 1, 2*Sqrt[3]*ArcTanh[Coth[x]/Sqrt[1 - I*Csch[x]]]}
{Sqrt[-3 + 3*I*Csch[x]], x, 1, -2*Sqrt[3]*ArcTan[Coth[x]/Sqrt[-1 + I*Csch[x]]]}
{Sqrt[-3 - 3*I*Csch[x]], x, 1, -2*Sqrt[3]*ArcTan[Coth[x]/Sqrt[-1 - I*Csch[x]]]}


(* ::Subsubsection::Closed:: *)
(*a^2-b^2!=0*)


{(a + b*Csch[c + d*x])^4, x, 5, a^4*x - (2*a*b*(2*a^2 - b^2)*ArcTanh[Cosh[c + d*x]])/d - (b^2*(13*a^2 - 2*b^2)*Coth[c + d*x])/(3*d) - (4*a*b^2*Coth[c + d*x]*(a + b*Csch[c + d*x]))/(3*d) - (b^2*Coth[c + d*x]*(a + b*Csch[c + d*x])^2)/(3*d)}
{(a + b*Csch[c + d*x])^3, x, 4, a^3*x - (b*(6*a^2 - b^2)*ArcTanh[Cosh[c + d*x]])/(2*d) - (5*a*b^2*Coth[c + d*x])/(2*d) - (b^2*Coth[c + d*x]*(a + b*Csch[c + d*x]))/(2*d)}
{(a + b*Csch[c + d*x])^2, x, 3, a^2*x - (2*a*b*ArcTanh[Cosh[c + d*x]])/d - (b^2*Coth[c + d*x])/d}
{(a + b*Csch[c + d*x])^1, x, 2, a*x - (b*ArcTanh[Cosh[c + d*x]])/d}
{1/(a + b*Csch[c + d*x])^1, x, 2, x/a + (2*b*ArcTanh[(a - b*Tanh[(1/2)*(c + d*x)])/Sqrt[a^2 + b^2]])/(a*Sqrt[a^2 + b^2]*d)}
{1/(a + b*Csch[c + d*x])^2, x, 3, x/a^2 + (2*b*(2*a^2 + b^2)*ArcTanh[(a - b*Tanh[(1/2)*(c + d*x)])/Sqrt[a^2 + b^2]])/(a^2*(a^2 + b^2)^(3/2)*d) - (b^2*Coth[c + d*x])/(a*(a^2 + b^2)*d*(a + b*Csch[c + d*x]))}
{1/(a + b*Csch[c + d*x])^3, x, 4, x/a^3 + (b*(6*a^4 + 5*a^2*b^2 + 2*b^4)*ArcTanh[(a - b*Tanh[(1/2)*(c + d*x)])/Sqrt[a^2 + b^2]])/(a^3*(a^2 + b^2)^(5/2)*d) - (b^2*Coth[c + d*x])/(2*a*(a^2 + b^2)*d*(a + b*Csch[c + d*x])^2) - (b^2*(5*a^2 + 2*b^2)*Coth[c + d*x])/(2*a^2*(a^2 + b^2)^2*d*(a + b*Csch[c + d*x]))}


(* ::Subsection::Closed:: *)
(*Integrands of the form Cosh[c+d x]^m (a+b Csch[c+d x])^n*)


(* ::Subsubsection:: *)
(*a^2+b^2=0*)


(* ::Subsubsection:: *)
(*a^2-b^2!=0*)


(* ::Subsection::Closed:: *)
(*Integrands of the form Tanh[c+d x]^m (a+b Csch[c+d x])^n*)


(* ::Subsubsection:: *)
(*a^2+b^2=0*)


(* ::Subsubsection:: *)
(*a^2-b^2!=0*)


(* ::Section::Closed:: *)
(*Integrands of the form Hyper[c+d x]^m (a+b Csch[c+d x]^2)^n*)


(* ::Subsection::Closed:: *)
(*Integrands of the form Sinh[c+d x]^m (a+b Csch[c+d x]^2)^n*)


(* ::Subsubsection::Closed:: *)
(*p*)


{(a + b*Csch[c + d*x]^2)^4, x, 4, a^4*x - ((2*a - b)*b*(2*a^2 - 2*a*b + b^2)*Coth[c + d*x])/d - (b^2*(6*a^2 - 8*a*b + 3*b^2)*Coth[c + d*x]^3)/(3*d) - ((4*a - 3*b)*b^3*Coth[c + d*x]^5)/(5*d) - (b^4*Coth[c + d*x]^7)/(7*d)}
{(a + b*Csch[c + d*x]^2)^3, x, 4, a^3*x - (b*(3*a^2 - 3*a*b + b^2)*Coth[c + d*x])/d - ((3*a - 2*b)*b^2*Coth[c + d*x]^3)/(3*d) - (b^3*Coth[c + d*x]^5)/(5*d)}
{(a + b*Csch[c + d*x]^2)^2, x, 4, a^2*x - ((2*a - b)*b*Coth[c + d*x])/d - (b^2*Coth[c + d*x]^3)/(3*d)}
{(a + b*Csch[c + d*x]^2)^1, x, 2, a*x - (b*Coth[c + d*x])/d}
{1/(a + b*Csch[c + d*x]^2)^1, x, 3, x/a - (Sqrt[b]*ArcTanh[(Sqrt[-a + b]*Tanh[c + d*x])/Sqrt[b]])/(a*Sqrt[-a + b]*d)}
{1/(a + b*Csch[c + d*x]^2)^2, x, 5, x/a^2 + ((3*a - 2*b)*Sqrt[b]*ArcTan[(Sqrt[b]*Coth[c + d*x])/Sqrt[a - b]])/(2*a^2*(a - b)^(3/2)*d) + (b*Coth[c + d*x])/(2*a*(a - b)*d*(a - b + b*Coth[c + d*x]^2))}
{1/(a + b*Csch[c + d*x]^2)^3, x, 6, x/a^3 + (Sqrt[b]*(15*a^2 - 20*a*b + 8*b^2)*ArcTan[(Sqrt[b]*Coth[c + d*x])/Sqrt[a - b]])/(8*a^3*(a - b)^(5/2)*d) + (b*Coth[c + d*x])/(4*a*(a - b)*d*(a - b + b*Coth[c + d*x]^2)^2) + ((7*a - 4*b)*b*Coth[c + d*x])/(8*a^2*(a - b)^2*d*(a - b + b*Coth[c + d*x]^2))}
{1/(a + b*Csch[c + d*x]^2)^4, x, 7, x/a^4 + (Sqrt[b]*(35*a^3 - 70*a^2*b + 56*a*b^2 - 16*b^3)*ArcTan[(Sqrt[b]*Coth[c + d*x])/Sqrt[a - b]])/(16*a^4*(a - b)^(7/2)*d) + (b*Coth[c + d*x])/(6*a*(a - b)*d*(a - b + b*Coth[c + d*x]^2)^3) + ((11*a - 6*b)*b*Coth[c + d*x])/(24*a^2*(a - b)^2*d*(a - b + b*Coth[c + d*x]^2)^2) + (b*(19*a^2 - 22*a*b + 8*b^2)*Coth[c + d*x])/(16*a^3*(a - b)^3*d*(a - b + b*Coth[c + d*x]^2))}


{Sinh[x]^4/(a + b*Csch[x]), x, 6, ((3*a^4 - 4*a^2*b^2 + 8*b^4)*x)/(8*a^5) + (2*b^5*ArcTanh[(a - b*Tanh[x/2])/Sqrt[a^2 + b^2]])/(a^5*Sqrt[a^2 + b^2]) + (b*(2*a^2 - 3*b^2)*Cosh[x])/(3*a^4) - ((3*a^2 - 4*b^2)*Cosh[x]*Sinh[x])/(8*a^3) - (b*Cosh[x]*Sinh[x]^2)/(3*a^2) + (Cosh[x]*Sinh[x]^3)/(4*a)}
{Sinh[x]^3/(a + b*Csch[x]), x, 5, (b*(a^2 - 2*b^2)*x)/(2*a^4) - (2*b^4*ArcTanh[(a - b*Tanh[x/2])/Sqrt[a^2 + b^2]])/(a^4*Sqrt[a^2 + b^2]) - ((2*a^2 - 3*b^2)*Cosh[x])/(3*a^3) - (b*Cosh[x]*Sinh[x])/(2*a^2) + (Cosh[x]*Sinh[x]^2)/(3*a)}
{Sinh[x]^2/(a + b*Csch[x]), x, 4, -(((a^2 - 2*b^2)*x)/(2*a^3)) + (2*b^3*ArcTanh[(a - b*Tanh[x/2])/Sqrt[a^2 + b^2]])/(a^3*Sqrt[a^2 + b^2]) - (b*Cosh[x])/a^2 + (Cosh[x]*Sinh[x])/(2*a)}
{Sinh[x]^1/(a + b*Csch[x]), x, 4, -((b*x)/a^2) - (2*b^2*ArcTanh[(a - b*Tanh[x/2])/Sqrt[a^2 + b^2]])/(a^2*Sqrt[a^2 + b^2]) + Cosh[x]/a}
{Csch[x]^1/(a + b*Csch[x]), x, 2, -((2*ArcTanh[(a - b*Tanh[x/2])/Sqrt[a^2 + b^2]])/Sqrt[a^2 + b^2])}
{Csch[x]^2/(a + b*Csch[x]), x, 4, -(ArcTanh[Cosh[x]]/b) + (2*a*ArcTanh[(a - b*Tanh[x/2])/Sqrt[a^2 + b^2]])/(b*Sqrt[a^2 + b^2])}
{Csch[x]^3/(a + b*Csch[x]), x, 6, (a*ArcTanh[Cosh[x]])/b^2 - (2*a^2*ArcTanh[(a - b*Tanh[x/2])/Sqrt[a^2 + b^2]])/(b^2*Sqrt[a^2 + b^2]) - Coth[x]/b}
{Csch[x]^4/(a + b*Csch[x]), x, 6, -(((2*a^2 - b^2)*ArcTanh[Cosh[x]])/(2*b^3)) + (2*a^3*ArcTanh[(a - b*Tanh[x/2])/Sqrt[a^2 + b^2]])/(b^3*Sqrt[a^2 + b^2]) + (a*Coth[x])/b^2 - (Coth[x]*Csch[x])/(2*b)}


{Sinh[x]^4/(I + Csch[x]), x, 6, -((15*I*x)/8) - 4*Cosh[x] + (4*Cosh[x]^3)/3 + (15/8)*I*Cosh[x]*Sinh[x] - (5/4)*I*Cosh[x]*Sinh[x]^3 - (Cosh[x]*Sinh[x]^3)/(I + Csch[x])}
{Sinh[x]^3/(I + Csch[x]), x, 5, -((3*x)/2) + 4*I*Cosh[x] - (4/3)*I*Cosh[x]^3 + (3/2)*Cosh[x]*Sinh[x] - (Cosh[x]*Sinh[x]^2)/(I + Csch[x])}
{Sinh[x]^2/(I + Csch[x]), x, 4, (3*I*x)/2 + 2*Cosh[x] - (3/2)*I*Cosh[x]*Sinh[x] - (Cosh[x]*Sinh[x])/(I + Csch[x])}
{Sinh[x]^1/(I + Csch[x]), x, 3, x - 2*I*Cosh[x] - Cosh[x]/(I + Csch[x])}
{Csch[x]^1/(I + Csch[x]), x, 2, -(Cosh[x]/(I - Sinh[x]))}
{Csch[x]^2/(I + Csch[x]), x, 4, -ArcTanh[Cosh[x]] + (I*Cosh[x])/(I - Sinh[x])}
{Csch[x]^3/(I + Csch[x]), x, 3, I*ArcTanh[Cosh[x]] - 2*Coth[x] + (Coth[x]*Csch[x])/(I + Csch[x])}
{Csch[x]^4/(I + Csch[x]), x, 4, (3/2)*ArcTanh[Cosh[x]] + 2*I*Coth[x] - (3/2)*Coth[x]*Csch[x] + (Coth[x]*Csch[x]^2)/(I + Csch[x])}


(* ::Subsubsection::Closed:: *)
(*p/2*)


{(a + b*Csch[c + d*x]^2)^(5/2), x, 6, (a^(5/2)*ArcTanh[(Sqrt[a]*Coth[c + d*x])/Sqrt[a - b + b*Coth[c + d*x]^2]])/d - (Sqrt[b]*(15*a^2 - 10*a*b + 3*b^2)*ArcTanh[(Sqrt[b]*Coth[c + d*x])/Sqrt[a - b + b*Coth[c + d*x]^2]])/(8*d) - ((7*a - 3*b)*b*Coth[c + d*x]*Sqrt[a - b + b*Coth[c + d*x]^2])/(8*d) - (b*Coth[c + d*x]*(a - b + b*Coth[c + d*x]^2)^(3/2))/(4*d)}
{(a + b*Csch[c + d*x]^2)^(3/2), x, 5, (a^(3/2)*ArcTanh[(Sqrt[a]*Coth[c + d*x])/Sqrt[a - b + b*Coth[c + d*x]^2]])/d - ((3*a - b)*Sqrt[b]*ArcTanh[(Sqrt[b]*Coth[c + d*x])/Sqrt[a - b + b*Coth[c + d*x]^2]])/(2*d) - (b*Coth[c + d*x]*Sqrt[a - b + b*Coth[c + d*x]^2])/(2*d)}
{(a + b*Csch[c + d*x]^2)^(1/2), x, 4, (Sqrt[a]*ArcTanh[(Sqrt[a]*Coth[c + d*x])/Sqrt[a - b + b*Coth[c + d*x]^2]])/d - (Sqrt[b]*ArcTanh[(Sqrt[b]*Coth[c + d*x])/Sqrt[a - b + b*Coth[c + d*x]^2]])/d}
{1/(a + b*Csch[c + d*x]^2)^(1/2), x, 2, ArcTanh[(Sqrt[a]*Coth[c + d*x])/Sqrt[a + b*Csch[c + d*x]^2]]/(Sqrt[a]*d), ArcTanh[(Sqrt[a]*Coth[c + d*x])/Sqrt[a - b + b*Coth[c + d*x]^2]]/(Sqrt[a]*d)}
{1/(a + b*Csch[c + d*x]^2)^(3/2), x, 3, ArcTanh[(Sqrt[a]*Coth[c + d*x])/Sqrt[a - b + b*Coth[c + d*x]^2]]/(a^(3/2)*d) + (b*Coth[c + d*x])/(a*(a - b)*d*Sqrt[a - b + b*Coth[c + d*x]^2])}
{1/(a + b*Csch[c + d*x]^2)^(5/2), x, 5, ArcTanh[(Sqrt[a]*Coth[c + d*x])/Sqrt[a - b + b*Coth[c + d*x]^2]]/(a^(5/2)*d) + (b*Coth[c + d*x])/(3*a*(a - b)*d*(a - b + b*Coth[c + d*x]^2)^(3/2)) + ((5*a - 3*b)*b*Coth[c + d*x])/(3*a^2*(a - b)^2*d*Sqrt[a - b + b*Coth[c + d*x]^2])}
{1/(a + b*Csch[c + d*x]^2)^(7/2), x, 6, ArcTanh[(Sqrt[a]*Coth[c + d*x])/Sqrt[a - b + b*Coth[c + d*x]^2]]/(a^(7/2)*d) + (b*Coth[c + d*x])/(5*a*(a - b)*d*(a - b + b*Coth[c + d*x]^2)^(5/2)) + ((9*a - 5*b)*b*Coth[c + d*x])/(15*a^2*(a - b)^2*d*(a - b + b*Coth[c + d*x]^2)^(3/2)) + (b*(33*a^2 - 40*a*b + 15*b^2)*Coth[c + d*x])/(15*a^3*(a - b)^3*d*Sqrt[a - b + b*Coth[c + d*x]^2])}


{(1 + Csch[x]^2)^(3/2), x, 4, (-(1/2))*(Coth[x]^2)^(3/2)*Tanh[x] + Sqrt[Coth[x]^2]*Log[Sinh[x]]*Tanh[x]}
{Sqrt[1 + Csch[x]^2], x, 3, Sqrt[Coth[x]^2]*Log[Sinh[x]]*Tanh[x]}
{1/Sqrt[1 + Csch[x]^2], x, 3, (Coth[x]*Log[Cosh[x]])/Sqrt[Coth[x]^2]}


{(1 - Csch[x]^2)^(3/2), x, 5, 2*ArcSin[Coth[x]/Sqrt[2]] + ArcTanh[Coth[x]/Sqrt[2 - Coth[x]^2]] + (1/2)*Coth[x]*Sqrt[2 - Coth[x]^2]}
{Sqrt[1 - Csch[x]^2], x, 4, ArcSin[Coth[x]/Sqrt[2]] + ArcTanh[Coth[x]/Sqrt[2 - Coth[x]^2]]}
{1/Sqrt[1 - Csch[x]^2], x, 2, ArcTanh[Coth[x]/Sqrt[2 - Coth[x]^2]]}


{(-1 + Csch[x]^2)^(3/2), x, 5, ArcTan[Coth[x]/Sqrt[-2 + Coth[x]^2]] + 2*ArcTanh[Coth[x]/Sqrt[-2 + Coth[x]^2]] - (1/2)*Coth[x]*Sqrt[-2 + Coth[x]^2]}
{Sqrt[-1 + Csch[x]^2], x, 4, -ArcTan[Coth[x]/Sqrt[-2 + Coth[x]^2]] - ArcTanh[Coth[x]/Sqrt[-2 + Coth[x]^2]]}
{1/Sqrt[-1 + Csch[x]^2], x, 2, ArcTan[Coth[x]/Sqrt[-2 + Coth[x]^2]]}


{(-1 - Csch[x]^2)^(3/2), x, 4, (1/2)*Coth[x]*Sqrt[-Coth[x]^2] - Sqrt[-Coth[x]^2]*Log[Sinh[x]]*Tanh[x]}
{Sqrt[-1 - Csch[x]^2], x, 3, Sqrt[-Coth[x]^2]*Log[Sinh[x]]*Tanh[x]}
{1/Sqrt[-1 - Csch[x]^2], x, 3, (Coth[x]*Log[Cosh[x]])/Sqrt[-Coth[x]^2]}


(* ::Subsection::Closed:: *)
(*Integrands of the form Cosh[c+d x]^m (a+b Csch[c+d x]^2)^n*)


{Cosh[x]^4/(a + b*Csch[x]), x, 7, -(x/(8*a)) - ((a^2 + b^2)*x)/(2*a^3) + ((a^2 + b^2)^2*x)/a^5 + (2*b*(a^2 + b^2)^(3/2)*ArcTanh[(a - b*Tanh[x/2])/Sqrt[a^2 + b^2]])/a^5 - (b*(a^2 + b^2)*Cosh[x])/a^4 - (b*Cosh[x]^3)/(3*a^2) - (Cosh[x]*Sinh[x])/(8*a) + ((a^2 + b^2)*Cosh[x]*Sinh[x])/(2*a^3) + (Cosh[x]^3*Sinh[x])/(4*a)}
{Cosh[x]^3/(a + b*Csch[x]), x, 3, -((b*(a^2 + b^2)*Log[b + a*Sinh[x]])/a^4) + ((a^2 + b^2)*Sinh[x])/a^3 - (b*Sinh[x]^2)/(2*a^2) + Sinh[x]^3/(3*a)}
{Cosh[x]^2/(a + b*Csch[x]), x, 4, -(x/(2*a)) + ((a^2 + b^2)*x)/a^3 + (2*b*Sqrt[a^2 + b^2]*ArcTanh[(a - b*Tanh[x/2])/Sqrt[a^2 + b^2]])/a^3 - (b*Cosh[x])/a^2 + (Cosh[x]*Sinh[x])/(2*a)}
{Cosh[x]^1/(a + b*Csch[x]), x, 3, -((b*Log[b + a*Sinh[x]])/a^2) + Sinh[x]/a}
{Sech[x]^1/(a + b*Csch[x]), x, 6, (I*Log[1 - I*Sinh[x]])/(2*(a + I*b)) + Log[1 + I*Sinh[x]]/(2*(I*a + b)) - (b*Log[b + a*Sinh[x]])/(a^2 + b^2)}
{Sech[x]^2/(a + b*Csch[x]), x, 5, (2*a*b*ArcTanh[(a - b*Tanh[x/2])/Sqrt[a^2 + b^2]])/(a^2 + b^2)^(3/2) - (b*Sech[x])/(a^2 + b^2) + (a*Tanh[x])/(a^2 + b^2)}
{Sech[x]^3/(a + b*Csch[x]), x, 7, (I*a*Log[1 - I*Sinh[x]])/(4*(a + I*b)^2) - (I*a*Log[1 + I*Sinh[x]])/(4*(a - I*b)^2) - (a^2*b*Log[b + a*Sinh[x]])/(a^2 + b^2)^2 - (b - a*Sinh[x])/(2*(a^2 + b^2)*(1 + Sinh[x]^2))}
{Sech[x]^4/(a + b*Csch[x]), x, 8, (2*a^3*b*ArcTanh[(a - b*Tanh[x/2])/Sqrt[a^2 + b^2]])/(a^2 + b^2)^(5/2) - (a^2*b*Sech[x])/(a^2 + b^2)^2 - (b*Sech[x]^3)/(3*(a^2 + b^2)) + (a^3*Tanh[x])/(a^2 + b^2)^2 - (a*Tanh[x]^3)/(3*(a^2 + b^2))}


{Cosh[x]^4/(I + Csch[x]), x, 3, (I*x)/8 + Cosh[x]^3/3 + (1/8)*I*Cosh[x]*Sinh[x] - (1/4)*I*Cosh[x]^3*Sinh[x]}
{Cosh[x]^3/(I + Csch[x]), x, 2, Cosh[x]^2/2 - (1/3)*I*Sinh[x]^3}
{Cosh[x]^2/(I + Csch[x]), x, 2, (I*x)/2 + Cosh[x] - (1/2)*I*Cosh[x]*Sinh[x]}
{Cosh[x]^1/(I + Csch[x]), x, 3, Log[1 + I*Sinh[x]] - I*Sinh[x]}
{Sech[x]^1/(I + Csch[x]), x, 3, (-(1/2))*I*ArcTan[Sinh[x]] - Sech[x]^2/2 + (1/2)*I*Sech[x]*Tanh[x]}
{Sech[x]^2/(I + Csch[x]), x, 3, (-(1/3))*Sech[x]^3 - (1/3)*I*Tanh[x]^3}
{Sech[x]^3/(I + Csch[x]), x, 4, (-(1/8))*I*ArcTan[Sinh[x]] - Sech[x]^4/4 + (1/8)*I*Sech[x]*Tanh[x] - (1/4)*I*Sech[x]*Tanh[x]^3}
{Sech[x]^4/(I + Csch[x]), x, 4, (-(1/5))*Sech[x]^5 - (1/3)*I*Tanh[x]^3 + (1/5)*I*Tanh[x]^5}


(* ::Subsection::Closed:: *)
(*Integrands of the form Tanh[c+d x]^m (a+b Csch[c+d x]^2)^n*)


{Tanh[x]^5/(a + b*Csch[x]), x, 3, ((8*a^2 + 21*I*a*b - 15*b^2)*Log[1 - I*Sinh[x]])/(16*(a + I*b)^3) + ((8*a^2 - 21*I*a*b - 15*b^2)*Log[1 + I*Sinh[x]])/(16*(a - I*b)^3) + (b^6*Log[b + a*Sinh[x]])/(a*(a^2 + b^2)^3) - 1/(16*(a + I*b)*(1 - I*Sinh[x])^2) + (7*a + 9*I*b)/(16*(a + I*b)^2*(1 - I*Sinh[x])) - 1/(16*(a - I*b)*(1 + I*Sinh[x])^2) + (7*a - 9*I*b)/(16*(a - I*b)^2*(1 + I*Sinh[x]))}
{Tanh[x]^4/(a + b*Csch[x]), x, 12, (a*b^2*x)/(a^2 + b^2)^2 + (b^4*x)/(a*(a^2 + b^2)^2) + (a*x)/(a^2 + b^2) + (2*b^5*ArcTanh[(a - b*Tanh[x/2])/Sqrt[a^2 + b^2]])/(a*(a^2 + b^2)^(5/2)) + (b^3*Sech[x])/(a^2 + b^2)^2 + (b*Sech[x])/(a^2 + b^2) - (b*Sech[x]^3)/(3*(a^2 + b^2)) - (a*b^2*Tanh[x])/(a^2 + b^2)^2 - (a*Tanh[x])/(a^2 + b^2) - (a*Tanh[x]^3)/(3*(a^2 + b^2))}
{Tanh[x]^3/(a + b*Csch[x]), x, 3, ((2*a + 3*I*b)*Log[1 - I*Sinh[x]])/(4*(a + I*b)^2) + ((2*a - 3*I*b)*Log[1 + I*Sinh[x]])/(4*(a - I*b)^2) + (b^4*Log[b + a*Sinh[x]])/(a*(a^2 + b^2)^2) + 1/(4*(a + I*b)*(1 - I*Sinh[x])) + 1/(4*(a - I*b)*(1 + I*Sinh[x]))}
{Tanh[x]^2/(a + b*Csch[x]), x, 6, (a*x)/(a^2 + b^2) + (b^2*x)/(a*(a^2 + b^2)) + (2*b^3*ArcTanh[(a - b*Tanh[x/2])/Sqrt[a^2 + b^2]])/(a*(a^2 + b^2)^(3/2)) + (b*Sech[x])/(a^2 + b^2) - (a*Tanh[x])/(a^2 + b^2)}
{Tanh[x]^1/(a + b*Csch[x]), x, 3, Log[1 - I*Sinh[x]]/(2*(a + I*b)) + Log[1 + I*Sinh[x]]/(2*(a - I*b)) + (b^2*Log[b + a*Sinh[x]])/(a*(a^2 + b^2))}
{Coth[x]^1/(a + b*Csch[x]), x, 2, Log[b + a*Sinh[x]]/a}
{Coth[x]^2/(a + b*Csch[x]), x, 5, (1/a + a/b^2)*x - (a*x)/b^2 - ArcTanh[Cosh[x]]/b + (2*Sqrt[a^2 + b^2]*ArcTanh[(a - b*Tanh[x/2])/Sqrt[a^2 + b^2]])/(a*b)}
{Coth[x]^3/(a + b*Csch[x]), x, 3, -(Csch[x]/b) - (a*Log[Sinh[x]])/b^2 + (1/a + a/b^2)*Log[b + a*Sinh[x]]}
{Coth[x]^4/(a + b*Csch[x]), x, 10, -((a*x)/b^2) - (a*(a^2 + b^2)*x)/b^4 + ((a^2 + b^2)^2*x)/(a*b^4) - ArcTanh[Cosh[x]]/(2*b) - ((a^2 + b^2)*ArcTanh[Cosh[x]])/b^3 + (2*(a^2 + b^2)^(3/2)*ArcTanh[(a - b*Tanh[x/2])/Sqrt[a^2 + b^2]])/(a*b^3) + (a*Coth[x])/b^2 - (Coth[x]*Csch[x])/(2*b)}
{Coth[x]^5/(a + b*Csch[x]), x, 3, -(((a^2 + 2*b^2)*Csch[x])/b^3) + (a*Csch[x]^2)/(2*b^2) - Csch[x]^3/(3*b) - (a*(a^2 + 2*b^2)*Log[Sinh[x]])/b^4 + ((a^2 + b^2)^2*Log[b + a*Sinh[x]])/(a*b^4)}
{Coth[x]^6/(a + b*Csch[x]), x, 17, -((a*x)/b^2) - (a*(a^2 + b^2)*x)/b^4 - (a*(a^2 + b^2)^2*x)/b^6 + ((a^2 + b^2)^3*x)/(a*b^6) - (3*ArcTanh[Cosh[x]])/(8*b) - ((a^2 + b^2)*ArcTanh[Cosh[x]])/(2*b^3) - ((a^2 + b^2)^2*ArcTanh[Cosh[x]])/b^5 + (2*(a^2 + b^2)^(5/2)*ArcTanh[(a - b*Tanh[x/2])/Sqrt[a^2 + b^2]])/(a*b^5) + (a*Coth[x])/b^2 + (a*(a^2 + b^2)*Coth[x])/b^4 + (a*Coth[x]^3)/(3*b^2) - (3*Coth[x]*Csch[x])/(8*b) - ((a^2 + b^2)*Coth[x]*Csch[x])/(2*b^3) - (Coth[x]^3*Csch[x])/(4*b)}
{Coth[x]^7/(a + b*Csch[x]), x, 3, -(((a^4 + 3*a^2*b^2 + 3*b^4)*Csch[x])/b^5) + (a*(a^2 + 3*b^2)*Csch[x]^2)/(2*b^4) - ((a^2 + 3*b^2)*Csch[x]^3)/(3*b^3) + (a*Csch[x]^4)/(4*b^2) - Csch[x]^5/(5*b) - (a*(a^4 + 3*a^2*b^2 + 3*b^4)*Log[Sinh[x]])/b^6 + ((a^2 + b^2)^3*Log[b + a*Sinh[x]])/(a*b^6)}


{Tanh[x]^5/(I + Csch[x]), x, 9, (5/16)*ArcTan[Sinh[x]] - I*Log[Cosh[x]] - (5/16)*Sech[x]*Tanh[x] + (1/2)*I*Tanh[x]^2 - (5/24)*Sech[x]*Tanh[x]^3 + (1/4)*I*Tanh[x]^4 - (1/6)*Sech[x]*Tanh[x]^5 + (1/6)*I*Tanh[x]^6}
{Tanh[x]^4/(I + Csch[x]), x, 8, (-I)*x - Sech[x] + (2*Sech[x]^3)/3 - Sech[x]^5/5 + I*Tanh[x] + (1/3)*I*Tanh[x]^3 + (1/5)*I*Tanh[x]^5}
{Tanh[x]^3/(I + Csch[x]), x, 7, (3/8)*ArcTan[Sinh[x]] - I*Log[Cosh[x]] - (3/8)*Sech[x]*Tanh[x] + (1/2)*I*Tanh[x]^2 - (1/4)*Sech[x]*Tanh[x]^3 + (1/4)*I*Tanh[x]^4}
{Tanh[x]^2/(I + Csch[x]), x, 6, (-I)*x - Sech[x] + Sech[x]^3/3 + I*Tanh[x] + (1/3)*I*Tanh[x]^3}
{Tanh[x]^1/(I + Csch[x]), x, 5, (1/2)*ArcTan[Sinh[x]] - I*Log[Cosh[x]] - (1/2)*Sech[x]*Tanh[x] + (1/2)*I*Tanh[x]^2}
{Coth[x]^1/(I + Csch[x]), x, 2, (-I)*Log[1 + I*Sinh[x]]}
{Coth[x]^2/(I + Csch[x]), x, 3, (-I)*x - ArcTanh[Cosh[x]]}
{Coth[x]^3/(I + Csch[x]), x, 3, -Csch[x] - I*Log[Sinh[x]]}
{Coth[x]^4/(I + Csch[x]), x, 5, (-I)*x - (1/2)*ArcTanh[Cosh[x]] + I*Coth[x] - (1/2)*Coth[x]*Csch[x]}
{Coth[x]^5/(I + Csch[x]), x, 5, (1/2)*I*Coth[x]^2 - Csch[x] - Csch[x]^3/3 - I*Log[Sinh[x]]}
{Coth[x]^6/(I + Csch[x]), x, 7, (-I)*x - (3/8)*ArcTanh[Cosh[x]] + I*Coth[x] + (1/3)*I*Coth[x]^3 - (3/8)*Coth[x]*Csch[x] - (1/4)*Coth[x]^3*Csch[x]}


(* ::Section::Closed:: *)
(*Integrands of the form (c+d x)^m Csch[a+b x]^n*)


(* ::Subsection::Closed:: *)
(*Integrands of the form (c+d x)^m Csch[a+b x]^n*)


{(c + d*x)^3*Csch[a + b*x], x, 7, -((2*(c + d*x)^3*ArcTanh[E^(a + b*x)])/b) - (3*d*(c + d*x)^2*PolyLog[2, -E^(a + b*x)])/b^2 + (3*d*(c + d*x)^2*PolyLog[2, E^(a + b*x)])/b^2 + (6*d^2*(c + d*x)*PolyLog[3, -E^(a + b*x)])/b^3 - (6*d^2*(c + d*x)*PolyLog[3, E^(a + b*x)])/b^3 - (6*d^3*PolyLog[4, -E^(a + b*x)])/b^4 + (6*d^3*PolyLog[4, E^(a + b*x)])/b^4}
{(c + d*x)^2*Csch[a + b*x], x, 5, -((2*(c + d*x)^2*ArcTanh[E^(a + b*x)])/b) - (2*d*(c + d*x)*PolyLog[2, -E^(a + b*x)])/b^2 + (2*d*(c + d*x)*PolyLog[2, E^(a + b*x)])/b^2 + (2*d^2*PolyLog[3, -E^(a + b*x)])/b^3 - (2*d^2*PolyLog[3, E^(a + b*x)])/b^3}
{(c + d*x)^1*Csch[a + b*x], x, 3, -((2*(c + d*x)*ArcTanh[E^(a + b*x)])/b) - (d*PolyLog[2, -E^(a + b*x)])/b^2 + (d*PolyLog[2, E^(a + b*x)])/b^2}
{1/x^1*Csch[a + b*x], x, 0, Int[Csch[a + b*x]/x, x]}


{(c + d*x)^3*Csch[a + b*x]^2, x, 6, -((c + d*x)^3/b) - ((c + d*x)^3*Coth[a + b*x])/b + (3*d*(c + d*x)^2*Log[1 - E^(2*a + 2*b*x)])/b^2 + (3*d^2*(c + d*x)*PolyLog[2, E^(2*a + 2*b*x)])/b^3 - (3*d^3*PolyLog[3, E^(2*a + 2*b*x)])/(2*b^4)}
{(c + d*x)^2*Csch[a + b*x]^2, x, 5, -((c + d*x)^2/b) - ((c + d*x)^2*Coth[a + b*x])/b + (2*d*(c + d*x)*Log[1 - E^(2*a + 2*b*x)])/b^2 + (d^2*PolyLog[2, E^(2*a + 2*b*x)])/b^3}
{(c + d*x)^1*Csch[a + b*x]^2, x, 2, -(((c + d*x)*Coth[a + b*x])/b) + (d*Log[Sinh[a + b*x]])/b^2}
{1/x^1*Csch[a + b*x]^2, x, 0, Int[Csch[a + b*x]^2/x, x]}


{(c + d*x)^3*Csch[a + b*x]^3, x, 11, -((6*d^2*(c + d*x)*ArcTanh[E^(a + b*x)])/b^3) + ((c + d*x)^3*ArcTanh[E^(a + b*x)])/b - (3*d*(c + d*x)^2*Csch[a + b*x])/(2*b^2) - ((c + d*x)^3*Coth[a + b*x]*Csch[a + b*x])/(2*b) - (3*d^3*PolyLog[2, -E^(a + b*x)])/b^4 + (3*d*(c + d*x)^2*PolyLog[2, -E^(a + b*x)])/(2*b^2) + (3*d^3*PolyLog[2, E^(a + b*x)])/b^4 - (3*d*(c + d*x)^2*PolyLog[2, E^(a + b*x)])/(2*b^2) - (3*d^2*(c + d*x)*PolyLog[3, -E^(a + b*x)])/b^3 + (3*d^2*(c + d*x)*PolyLog[3, E^(a + b*x)])/b^3 + (3*d^3*PolyLog[4, -E^(a + b*x)])/b^4 - (3*d^3*PolyLog[4, E^(a + b*x)])/b^4}
{(c + d*x)^2*Csch[a + b*x]^3, x, 7, ((c + d*x)^2*ArcTanh[E^(a + b*x)])/b - (d^2*ArcTanh[Cosh[a + b*x]])/b^3 - (d*(c + d*x)*Csch[a + b*x])/b^2 - ((c + d*x)^2*Coth[a + b*x]*Csch[a + b*x])/(2*b) + (d*(c + d*x)*PolyLog[2, -E^(a + b*x)])/b^2 - (d*(c + d*x)*PolyLog[2, E^(a + b*x)])/b^2 - (d^2*PolyLog[3, -E^(a + b*x)])/b^3 + (d^2*PolyLog[3, E^(a + b*x)])/b^3}
{(c + d*x)^1*Csch[a + b*x]^3, x, 4, ((c + d*x)*ArcTanh[E^(a + b*x)])/b - (d*Csch[a + b*x])/(2*b^2) - ((c + d*x)*Coth[a + b*x]*Csch[a + b*x])/(2*b) + (d*PolyLog[2, -E^(a + b*x)])/(2*b^2) - (d*PolyLog[2, E^(a + b*x)])/(2*b^2)}
{1/x^1*Csch[a + b*x]^3, x, 0, Int[Csch[a + b*x]^3/x, x]}


(* ::Subsection:: *)
(*Integrands of the form (c+d x)^(m/2) Csch[a+b x]^n*)


(* ::Subsection::Closed:: *)
(*Integrands of the form (c+d x)^m Csch[a+b x]^(n/2)*)


{x/Csch[x]^(3/2) + x*Sqrt[Csch[x]]/3, x, 4, -(4/(9*Csch[x]^(3/2))) + (2*x*Cosh[x])/(3*Sqrt[Csch[x]])}
{x/Csch[x]^(5/2) + 3*x/(5*Sqrt[Csch[x]]), x, 4, -(4/(25*Csch[x]^(5/2))) + (2*x*Cosh[x])/(5*Csch[x]^(3/2))}
{x/Csch[x]^(7/2) - (5/21)*x*Sqrt[Csch[x]], x, 5, -(4/(49*Csch[x]^(7/2))) + (2*x*Cosh[x])/(7*Csch[x]^(5/2)) + 20/(63*Csch[x]^(3/2)) - (10*x*Cosh[x])/(21*Sqrt[Csch[x]])}
{x^2/Csch[x]^(3/2) + (1/3)*x^2*Sqrt[Csch[x]], x, 7, -((8*x)/(9*Csch[x]^(3/2))) + (16*Cosh[x])/(27*Sqrt[Csch[x]]) + (2*x^2*Cosh[x])/(3*Sqrt[Csch[x]]) - (16/27)*I*Sqrt[Csch[x]]*EllipticF[Pi/4 - (I*x)/2, 2]*Sqrt[I*Sinh[x]]}


(* ::Section::Closed:: *)
(*Integrands of the form x^m Csch[a+b x^n]^p*)


(* ::Subsection::Closed:: *)
(*Integrands of the form x^m Csch[a+b x^2]^p*)


{x*Csch[a + b*x^2]^7, x, 5, (5*ArcTanh[Cosh[a + b*x^2]])/(32*b) - (5*Coth[a + b*x^2]*Csch[a + b*x^2])/(32*b) + (5*Coth[a + b*x^2]*Csch[a + b*x^2]^3)/(48*b) - (Coth[a + b*x^2]*Csch[a + b*x^2]^5)/(12*b)}


(* ::Subsection:: *)
(*Integrands of the form x^m Csch[a+b x^n]*)


(* ::Subsection:: *)
(*Integrands of the form x^m Csch[a+b x^n]^p*)


(* ::Section::Closed:: *)
(*Integrands of the form x^m Csch[a+b Log[c x^n]]^p*)


(* ::Subsection::Closed:: *)
(*Integrands of the form x^m Csch[a+b Log[c x^n]]^p*)


{Csch[a + b*Log[c*x^n]], x, 0, Int[Csch[a + b*Log[c*x^n]], x]}
{Csch[a + b*Log[c*x^n]]^2, x, 0, Int[Csch[a + b*Log[c*x^n]]^2, x]}
{Csch[a + b*Log[c*x^n]]^3, x, 1, -((x*Csch[a + b*Log[c*x^n]])/(2*b^2*n^2)) - (x*Coth[a + b*Log[c*x^n]]*Csch[a + b*Log[c*x^n]])/(2*b*n) - (1/2)*(1 - 1/(b^2*n^2))*Int[Csch[a + b*Log[c*x^n]], x]}
{Csch[a + b*Log[c*x^n]]^4, x, 1, -((x*Csch[a + b*Log[c*x^n]]^2)/(6*b^2*n^2)) - (x*Coth[a + b*Log[c*x^n]]*Csch[a + b*Log[c*x^n]]^2)/(3*b*n) - (1/6)*(4 - 1/(b^2*n^2))*Int[Csch[a + b*Log[c*x^n]]^2, x]}

{2*b^2*n^2*Csch[a + b*Log[c*x^n]]^3 - (1 - b^2*n^2)*Csch[a + b*Log[c*x^n]], x, 2, (-x)*Csch[a + b*Log[c*x^n]] - b*n*x*Coth[a + b*Log[c*x^n]]*Csch[a + b*Log[c*x^n]]}


{Csch[a + 2*Log[c*x^(1/2)]]^3, x, 1, (-(1/2))*x*Csch[a + 2*Log[c*Sqrt[x]]] - (1/2)*x*Coth[a + 2*Log[c*Sqrt[x]]]*Csch[a + 2*Log[c*Sqrt[x]]]}
{Csch[a + 2*Log[c/x^(1/2)]]^3, x, 1, (-(1/2))*x*Csch[a + 2*Log[c/Sqrt[x]]] + (1/2)*x*Coth[a + 2*Log[c/Sqrt[x]]]*Csch[a + 2*Log[c/Sqrt[x]]]}
{Csch[a + 1/(n*(-2 + p))*Log[c*x^n]]^p, x, 1, -(((2 - p)*x*Csch[a - Log[c*x^n]/(n*(2 - p))]^(-2 + p))/(1 - p)) - ((2 - p)*x*Cosh[a - Log[c*x^n]/(n*(2 - p))]*Csch[a - Log[c*x^n]/(n*(2 - p))]^(-1 + p))/(1 - p)}
{Csch[a - 1/(n*(-2 + p))*Log[c*x^n]]^p, x, 1, -(((2 - p)*x*Csch[a + Log[c*x^n]/(n*(2 - p))]^(-2 + p))/(1 - p)) + ((2 - p)*x*Cosh[a + Log[c*x^n]/(n*(2 - p))]*Csch[a + Log[c*x^n]/(n*(2 - p))]^(-1 + p))/(1 - p)}


{Csch[a + b*Log[c*x^n]]/x, x, 2, -(ArcTanh[Cosh[a + b*Log[c*x^n]]]/(b*n))}
{Csch[a + b*Log[c*x^n]]^2/x, x, 2, -(Coth[a + b*Log[c*x^n]]/(b*n))}
{Csch[a + b*Log[c*x^n]]^3/x, x, 3, ArcTanh[Cosh[a + b*Log[c*x^n]]]/(2*b*n) - (Coth[a + b*Log[c*x^n]]*Csch[a + b*Log[c*x^n]])/(2*b*n)}
{Csch[a + b*Log[c*x^n]]^4/x, x, 3, Coth[a + b*Log[c*x^n]]/(b*n) - Coth[a + b*Log[c*x^n]]^3/(3*b*n)}
{Csch[a + b*Log[c*x^n]]^5/x, x, 4, -((3*ArcTanh[Cosh[a + b*Log[c*x^n]]])/(8*b*n)) + (3*Coth[a + b*Log[c*x^n]]*Csch[a + b*Log[c*x^n]])/(8*b*n) - (Coth[a + b*Log[c*x^n]]*Csch[a + b*Log[c*x^n]]^3)/(4*b*n)}


(* ::Subsection::Closed:: *)
(*Integrands of the form x^m Csch[a+b Log[c x^n]]^(p/2)*)


{Csch[a + b*Log[c*x^n]]^(5/2)/x, x, 4, -((2*Cosh[a + b*Log[c*x^n]]*Csch[a + b*Log[c*x^n]]^(3/2))/(3*b*n)) - (2*I*Sqrt[Csch[a + b*Log[c*x^n]]]*EllipticF[Pi/4 - (1/2)*I*(a + b*Log[c*x^n]), 2]*Sqrt[I*Sinh[a + b*Log[c*x^n]]])/(3*b*n)}
{Csch[a + b*Log[c*x^n]]^(3/2)/x, x, 4, -((2*Cosh[a + b*Log[c*x^n]]*Sqrt[Csch[a + b*Log[c*x^n]]])/(b*n)) + (2*I*EllipticE[Pi/4 - (1/2)*I*(a + b*Log[c*x^n]), 2])/(b*n*Sqrt[Csch[a + b*Log[c*x^n]]]*Sqrt[I*Sinh[a + b*Log[c*x^n]]])}
{Sqrt[Csch[a + b*Log[c*x^n]]]/x, x, 3, (2*I*Sqrt[Csch[a + b*Log[c*x^n]]]*EllipticF[Pi/4 - (1/2)*I*(a + b*Log[c*x^n]), 2]*Sqrt[I*Sinh[a + b*Log[c*x^n]]])/(b*n)}
{1/(x*Sqrt[Csch[a + b*Log[c*x^n]]]), x, 3, (2*I*EllipticE[Pi/4 - (1/2)*I*(a + b*Log[c*x^n]), 2])/(b*n*Sqrt[Csch[a + b*Log[c*x^n]]]*Sqrt[I*Sinh[a + b*Log[c*x^n]]])}
{1/(x*Csch[a + b*Log[c*x^n]]^(3/2)), x, 4, (2*Cosh[a + b*Log[c*x^n]])/(3*b*n*Sqrt[Csch[a + b*Log[c*x^n]]]) - (2*I*Sqrt[Csch[a + b*Log[c*x^n]]]*EllipticF[Pi/4 - (1/2)*I*(a + b*Log[c*x^n]), 2]*Sqrt[I*Sinh[a + b*Log[c*x^n]]])/(3*b*n)}
{1/(x*Csch[a + b*Log[c*x^n]]^(5/2)), x, 4, (2*Cosh[a + b*Log[c*x^n]])/(5*b*n*Csch[a + b*Log[c*x^n]]^(3/2)) - (6*I*EllipticE[Pi/4 - (1/2)*I*(a + b*Log[c*x^n]), 2])/(5*b*n*Sqrt[Csch[a + b*Log[c*x^n]]]*Sqrt[I*Sinh[a + b*Log[c*x^n]]])}
