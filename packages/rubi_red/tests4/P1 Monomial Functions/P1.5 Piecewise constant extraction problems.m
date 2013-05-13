(* ::Package:: *)

(* ::Title:: *)
(*Piecewise Constant Extraction Problems*)


(* ::Section::Closed:: *)
(*Integrands of the form u (a + b x^n)^p when n<0*)


(* ::Subsection::Closed:: *)
(*Integrands of the form u (a + b/x)^p*)


{x^m*Sqrt[b - a/x]/Sqrt[a - b*x], x, 7, (2*Sqrt[b - a/x]*x^(1 + m))/((1 + 2*m)*Sqrt[a - b*x]), (2*Sqrt[b - a/x]*x^(1 + m))/((1 + 2*m)*Sqrt[-((b - a/x)*x)])}

{x^2*Sqrt[b - a/x]/Sqrt[a - b*x], x, 4, (2*Sqrt[b - a/x]*x^3)/(5*Sqrt[a - b*x]), -((2*x^2*Sqrt[-((b - a/x)*x)])/(5*Sqrt[b - a/x]))}
{x^1*Sqrt[b - a/x]/Sqrt[a - b*x], x, 4, (2*Sqrt[b - a/x]*x^2)/(3*Sqrt[a - b*x]), -((2*x*Sqrt[-((b - a/x)*x)])/(3*Sqrt[b - a/x]))}
{x^0*Sqrt[b - a/x]/Sqrt[a - b*x], x, 4, (2*Sqrt[b - a/x]*x)/Sqrt[a - b*x], (2*Sqrt[b - a/x]*x)/Sqrt[-((b - a/x)*x)]}
{Sqrt[b - a/x]/(x^1*Sqrt[a - b*x]), x, 4, -((2*Sqrt[b - a/x])/Sqrt[a - b*x]), (2*Sqrt[-((b - a/x)*x)])/(Sqrt[b - a/x]*x)}
{Sqrt[b - a/x]/(x^2*Sqrt[a - b*x]), x, 4, -((2*Sqrt[b - a/x])/(3*x*Sqrt[a - b*x])), -((2*Sqrt[b - a/x])/(3*x*Sqrt[-((b - a/x)*x)]))}


{(a + b/x)^m*(c + d*x)^n, x, 2, ((a + b/x)^m*x*(c + d*x)^n*AppellF1[1 - m, -m, -n, 2 - m, -((a*x)/b), -((d*x)/c)])/(((b + a*x)/b)^m*((c + d*x)/c)^n*(1 - m))}

{(a + b/x)^m*(c + d*x)^2, x, 14, (c^2*(a + b/x)^(1 + m)*x)/a - (b*c*d*(1 - m)*(a + b/x)^(1 + m)*x)/a^2 + (b^2*d^2*(1 - m)*(2 - m)*(a + b/x)^(1 + m)*x)/(6*a^3) + (c*d*(a + b/x)^(1 + m)*x^2)/a - (b*d^2*(2 - m)*(a + b/x)^(1 + m)*x^2)/(6*a^2) + (d^2*(a + b/x)^(1 + m)*x^3)/(3*a) + (b*c^2*m*(a + b/x)^(1 + m)*Hypergeometric2F1[1, 1 + m, 2 + m, (a + b/x)/a])/(a^2*(1 + m)) - (b^2*c*d*(1 - m)*m*(a + b/x)^(1 + m)*Hypergeometric2F1[1, 1 + m, 2 + m, (a + b/x)/a])/(a^3*(1 + m)) + (b^3*d^2*(1 - m)*(2 - m)*m*(a + b/x)^(1 + m)*Hypergeometric2F1[1, 1 + m, 2 + m, (a + b/x)/a])/(6*a^4*(1 + m))}
{(a + b/x)^m*(c + d*x)^1, x, 9, (c*(a + b/x)^(1 + m)*x)/a - (b*d*(1 - m)*(a + b/x)^(1 + m)*x)/(2*a^2) + (d*(a + b/x)^(1 + m)*x^2)/(2*a) + (b*c*m*(a + b/x)^(1 + m)*Hypergeometric2F1[1, 1 + m, 2 + m, (a + b/x)/a])/(a^2*(1 + m)) - (b^2*d*(1 - m)*m*(a + b/x)^(1 + m)*Hypergeometric2F1[1, 1 + m, 2 + m, (a + b/x)/a])/(2*a^3*(1 + m))}
{(a + b/x)^m*(c + d*x)^0, x, 3, ((a + b/x)^(1 + m)*x)/a + (b*m*(a + b/x)^(1 + m)*Hypergeometric2F1[1, 1 + m, 2 + m, (a + b/x)/a])/(a^2*(1 + m))}
{(a + b/x)^m/(c + d*x)^1, x, 2, ((a + b/x)^m*x*AppellF1[1 - m, -m, 1, 2 - m, -((a*x)/b), -((d*x)/c)])/(((b + a*x)/b)^m*(c*(1 - m)))}
{(a + b/x)^m/(c + d*x)^2, x, 2, ((a + b/x)^m*x*(1 + (d*x)/c)^(-1 + m)*Hypergeometric2F1[1 - m, -m, 2 - m, -(((a*c - b*d)*x)/(b*(c + d*x)))])/(((b + a*x)/b)^m*(c^2*(1 - m)))}
{(a + b/x)^m/(c + d*x)^3, x, 2, ((a + b/x)^m*x*Defer[AppellF1][1 - m, -m, 3, 2 - m, -((a*x)/b), -((d*x)/c)])/(((b + a*x)/b)^m*(c^3*(1 - m)))}
{(a + b/x)^m/(c + d*x)^4, x, 2, ((a + b/x)^m*x*Defer[AppellF1][1 - m, -m, 4, 2 - m, -((a*x)/b), -((d*x)/c)])/(((b + a*x)/b)^m*(c^4*(1 - m)))}


(* ::Subsection::Closed:: *)
(*Integrands of the form u (a + b/x^2)^p*)


{x^m*Sqrt[b - a/x^2]/Sqrt[a - b*x^2], x, 2, (Sqrt[b - a/x^2]*x^(1 + m))/(m*Sqrt[a - b*x^2])}

{x^2*Sqrt[b - a/x^2]/Sqrt[a - b*x^2], x, 2, (Sqrt[b - a/x^2]*x^3)/(2*Sqrt[a - b*x^2])}
{x^1*Sqrt[b - a/x^2]/Sqrt[a - b*x^2], x, 5, (Sqrt[b - a/x^2]*x^2)/Sqrt[a - b*x^2], (Sqrt[b - a/x^2]*x^2)/Sqrt[-((b - a/x^2)*x^2)]}
{x^0*Sqrt[b - a/x^2]/Sqrt[a - b*x^2], x, 2, (Sqrt[b - a/x^2]*x*Log[x])/Sqrt[a - b*x^2]}
{Sqrt[b - a/x^2]/(x^1*Sqrt[a - b*x^2]), x, 5, -(Sqrt[b - a/x^2]/Sqrt[a - b*x^2]), Sqrt[-((b - a/x^2)*x^2)]/(Sqrt[b - a/x^2]*x^2)}
{Sqrt[b - a/x^2]/(x^2*Sqrt[a - b*x^2]), x, 2, -(Sqrt[b - a/x^2]/(2*x*Sqrt[a - b*x^2]))}


(* ::Section::Closed:: *)
(*Integrands of the form u (a + b x^n)^p*)


(* ::Subsection::Closed:: *)
(*Integrands of the form u (a^2 - b^2 x^4)^(p/2)*)


{(a + b*x^2)^(5/2)/Sqrt[a^2 - b^2*x^4], x, 4, -((9*a*x*(a - b*x^2)*Sqrt[a + b*x^2])/(8*Sqrt[a^2 - b^2*x^4])) - (x*(a - b*x^2)*(a + b*x^2)^(3/2))/(4*Sqrt[a^2 - b^2*x^4]) + (19*a^2*Sqrt[a - b*x^2]*Sqrt[a + b*x^2]*ArcTan[(Sqrt[b]*x)/Sqrt[a - b*x^2]])/(8*Sqrt[b]*Sqrt[a^2 - b^2*x^4])}
{(a + b*x^2)^(3/2)/Sqrt[a^2 - b^2*x^4], x, 3, -((x*(a - b*x^2)*Sqrt[a + b*x^2])/(2*Sqrt[a^2 - b^2*x^4])) + (3*a*Sqrt[a - b*x^2]*Sqrt[a + b*x^2]*ArcTan[(Sqrt[b]*x)/Sqrt[a - b*x^2]])/(2*Sqrt[b]*Sqrt[a^2 - b^2*x^4])}
{(a + b*x^2)^(1/2)/Sqrt[a^2 - b^2*x^4], x, 2, (Sqrt[a - b*x^2]*Sqrt[a + b*x^2]*ArcTan[(Sqrt[b]*x)/Sqrt[a - b*x^2]])/(Sqrt[b]*Sqrt[a^2 - b^2*x^4])}
{1/((a + b*x^2)^(1/2)*Sqrt[a^2 - b^2*x^4]), x, 2, (Sqrt[a - b*x^2]*Sqrt[a + b*x^2]*ArcTan[(Sqrt[2]*Sqrt[b]*x)/Sqrt[a - b*x^2]])/(Sqrt[2]*a*Sqrt[b]*Sqrt[a^2 - b^2*x^4])}
{1/((a + b*x^2)^(3/2)*Sqrt[a^2 - b^2*x^4]), x, 3, (x*(a - b*x^2))/(4*a^2*Sqrt[a + b*x^2]*Sqrt[a^2 - b^2*x^4]) + (3*Sqrt[a - b*x^2]*Sqrt[a + b*x^2]*ArcTan[(Sqrt[2]*Sqrt[b]*x)/Sqrt[a - b*x^2]])/(4*Sqrt[2]*a^2*Sqrt[b]*Sqrt[a^2 - b^2*x^4])}
{1/((a + b*x^2)^(5/2)*Sqrt[a^2 - b^2*x^4]), x, 5, (x*(a - b*x^2))/(8*a^2*(a + b*x^2)^(3/2)*Sqrt[a^2 - b^2*x^4]) + (9*x*(a - b*x^2))/(32*a^3*Sqrt[a + b*x^2]*Sqrt[a^2 - b^2*x^4]) + (19*Sqrt[a - b*x^2]*Sqrt[a + b*x^2]*ArcTan[(Sqrt[2]*Sqrt[b]*x)/Sqrt[a - b*x^2]])/(32*Sqrt[2]*a^3*Sqrt[b]*Sqrt[a^2 - b^2*x^4])}


{(a - b*x^2)^(5/2)/Sqrt[a^2 - b^2*x^4], x, 4, -((9*a*x*Sqrt[a - b*x^2]*(a + b*x^2))/(8*Sqrt[a^2 - b^2*x^4])) - (x*(a - b*x^2)^(3/2)*(a + b*x^2))/(4*Sqrt[a^2 - b^2*x^4]) + (19*a^2*Sqrt[a - b*x^2]*Sqrt[a + b*x^2]*ArcTanh[(Sqrt[b]*x)/Sqrt[a + b*x^2]])/(8*Sqrt[b]*Sqrt[a^2 - b^2*x^4])}
{(a - b*x^2)^(3/2)/Sqrt[a^2 - b^2*x^4], x, 3, -((x*Sqrt[a - b*x^2]*(a + b*x^2))/(2*Sqrt[a^2 - b^2*x^4])) + (3*a*Sqrt[a - b*x^2]*Sqrt[a + b*x^2]*ArcTanh[(Sqrt[b]*x)/Sqrt[a + b*x^2]])/(2*Sqrt[b]*Sqrt[a^2 - b^2*x^4])}
{(a - b*x^2)^(1/2)/Sqrt[a^2 - b^2*x^4], x, 2, (Sqrt[a - b*x^2]*Sqrt[a + b*x^2]*ArcTanh[(Sqrt[b]*x)/Sqrt[a + b*x^2]])/(Sqrt[b]*Sqrt[a^2 - b^2*x^4])}
{1/((a - b*x^2)^(1/2)*Sqrt[a^2 - b^2*x^4]), x, 2, (Sqrt[a - b*x^2]*Sqrt[a + b*x^2]*ArcTanh[(Sqrt[2]*Sqrt[b]*x)/Sqrt[a + b*x^2]])/(Sqrt[2]*a*Sqrt[b]*Sqrt[a^2 - b^2*x^4])}
{1/((a - b*x^2)^(3/2)*Sqrt[a^2 - b^2*x^4]), x, 3, (x*(a + b*x^2))/(4*a^2*Sqrt[a - b*x^2]*Sqrt[a^2 - b^2*x^4]) + (3*Sqrt[a - b*x^2]*Sqrt[a + b*x^2]*ArcTanh[(Sqrt[2]*Sqrt[b]*x)/Sqrt[a + b*x^2]])/(4*Sqrt[2]*a^2*Sqrt[b]*Sqrt[a^2 - b^2*x^4])}
{1/((a - b*x^2)^(5/2)*Sqrt[a^2 - b^2*x^4]), x, 5, (x*(a + b*x^2))/(8*a^2*(a - b*x^2)^(3/2)*Sqrt[a^2 - b^2*x^4]) + (9*x*(a + b*x^2))/(32*a^3*Sqrt[a - b*x^2]*Sqrt[a^2 - b^2*x^4]) + (19*Sqrt[a - b*x^2]*Sqrt[a + b*x^2]*ArcTanh[(Sqrt[2]*Sqrt[b]*x)/Sqrt[a + b*x^2]])/(32*Sqrt[2]*a^3*Sqrt[b]*Sqrt[a^2 - b^2*x^4])}


(* ::Section::Closed:: *)
(*Miscellaneous integrands requiring piecewise constant extraction*)


{Sqrt[x^2/(-1 + x^2)]/(1 + x^2), x, 3, (Sqrt[-(x^2/(1 - x^2))]*Sqrt[-1 + x^2]*ArcTan[Sqrt[-1 + x^2]/Sqrt[2]])/(Sqrt[2]*x)}
{Sqrt[x^2/(-1 + a + (1 + a)*x^2)]/(1 + x^2), x, 3, (Sqrt[-(x^2/(1 - a - (1 + a)*x^2))]*Sqrt[-1 + a + (1 + a)*x^2]*ArcTan[Sqrt[-1 + a + (1 + a)*x^2]/Sqrt[2]])/(Sqrt[2]*x)}

{1/((1 + x)*(-1 + x^2))^(2/3), x, 2, -((3*(1 - x^2))/(2*(-((1 + x)*(1 - x^2)))^(2/3)))}


{(-1 + x^2)/((1 + x^2)*Sqrt[x*(1 + x^2)]), x, 2, -((2*x)/Sqrt[x*(1 + x^2)])}
{(-1 + x^2)/((1 + x^2)*Sqrt[x + x^3]), x, 2, -((2*x)/Sqrt[x*(1 + x^2)])}
{Sqrt[(-1 + x^2)^2/(x + x^3)]/(1 + x^2), x, 3, (2*x*Sqrt[(1/x - 2*x + x^3)/(1 + x^2)])/(1 - x^2), (2*x*Sqrt[(1 - x^2)^2/(x + x^3)]*Sqrt[x + x^3])/((1 - x^2)*Sqrt[x*(1 + x^2)])}


{1/(Sqrt[a + b/x^2]*Sqrt[c + d*x^2]), x, 3, (Sqrt[b + a*x^2]*ArcTanh[(Sqrt[d]*Sqrt[b + a*x^2])/(Sqrt[a]*Sqrt[c + d*x^2])])/(Sqrt[a]*Sqrt[d]*x*Sqrt[(b + a*x^2)/x^2])}


{Sqrt[-2*x^2 + x^4]/((-1 + x^2)*(2 + x^2)), x, 6, (2*Sqrt[(-x^2)*(2 - x^2)]*ArcTan[(1/2)*Sqrt[-2 + x^2]])/(3*x*Sqrt[-2 + x^2]) - (Sqrt[(-x^2)*(2 - x^2)]*ArcTan[Sqrt[-2 + x^2]])/(3*x*Sqrt[-2 + x^2])}

{Sqrt[1 - 1/(-1 + x^2)^2]/(2 - x^2), x, 3, ((1 - x)*(1 + x)*Sqrt[-((x^2*(2 - x^2))/((1 - x)^2*(1 + x)^2))]*ArcTan[Sqrt[-2 + x^2]])/(x*Sqrt[-2 + x^2])}
{Sqrt[Together[1 - 1/(-1 + x^2)^2]]/(2 + x^2), x, 6, -((2*(1 - x^2)*Sqrt[-((x^2*(2 - x^2))/(1 - x^2)^2)]*ArcTan[(1/2)*Sqrt[-2 + x^2]])/(3*x*Sqrt[-2 + x^2])) + ((1 - x^2)*Sqrt[-((x^2*(2 - x^2))/(1 - x^2)^2)]*ArcTan[Sqrt[-2 + x^2]])/(3*x*Sqrt[-2 + x^2]), -((2*(1 - x^2)*Sqrt[(-x^2)*(2 - x^2)]*Sqrt[-((2*x^2 - x^4)/(1 - x^2)^2)]*ArcTan[(1/2)*Sqrt[-2 + x^2]])/(3*x*Sqrt[-2 + x^2]*Sqrt[-2*x^2 + x^4])) + ((1 - x^2)*Sqrt[(-x^2)*(2 - x^2)]*Sqrt[-((2*x^2 - x^4)/(1 - x^2)^2)]*ArcTan[Sqrt[-2 + x^2]])/(3*x*Sqrt[-2 + x^2]*Sqrt[-2*x^2 + x^4])}


{(1 + 2*x/(1 + x^2))^(5/2), x, 7, (2/3)*(1 + x)^2*(1 + 3*x)*Sqrt[(1 + x)^2/(1 + x^2)] - ((1 - x)*(1 + x)^3*Sqrt[(1 + x)^2/(1 + x^2)])/(3*(1 + x^2)) - 3*Sqrt[(1 + x)^2/(1 + x^2)]*(1 + x^2) - (Sqrt[(1 + x)^2/(1 + x^2)]*(1 + x^2))/(1 + x) - 2*(1 + x)*Sqrt[(1 + x)^2/(1 + x^2)]*(1 + x^2) + (5*Sqrt[(1 + x)^2/(1 + x^2)]*Sqrt[1 + x^2]*ArcSinh[x])/(1 + x)}
{(1 + 2*x/(1 + x^2))^(3/2), x, 5, -((1 - x)*(1 + x)*Sqrt[(1 + x)^2/(1 + x^2)]) - Sqrt[(1 + x)^2/(1 + x^2)]*(1 + x^2) + (Sqrt[(1 + x)^2/(1 + x^2)]*(1 + x^2))/(1 + x) + (3*Sqrt[(1 + x)^2/(1 + x^2)]*Sqrt[1 + x^2]*ArcSinh[x])/(1 + x)}
{(1 + 2*x/(1 + x^2))^(1/2), x, 3, (Sqrt[(1 + x)^2/(1 + x^2)]*(1 + x^2))/(1 + x) + (Sqrt[(1 + x)^2/(1 + x^2)]*Sqrt[1 + x^2]*ArcSinh[x])/(1 + x)}
{1/(1 + 2*x/(1 + x^2))^(1/2), x, 5, (1 + x)/Sqrt[(1 + x)^2/(1 + x^2)] - ((1 + x)*ArcSinh[x])/(Sqrt[(1 + x)^2/(1 + x^2)]*Sqrt[1 + x^2]) - (Sqrt[2]*(1 + x)*ArcTanh[(1 - x)/(Sqrt[2]*Sqrt[1 + x^2])])/(Sqrt[(1 + x)^2/(1 + x^2)]*Sqrt[1 + x^2])}
{1/(1 + 2*x/(1 + x^2))^(3/2), x, 6, (3*(2 + x))/(2*Sqrt[(1 + x)^2/(1 + x^2)]) - (1 + x^2)/(2*(1 + x)*Sqrt[(1 + x)^2/(1 + x^2)]) - (3*(1 + x)*ArcSinh[x])/(Sqrt[(1 + x)^2/(1 + x^2)]*Sqrt[1 + x^2]) - (9*(1 + x)*ArcTanh[(1 - x)/(Sqrt[2]*Sqrt[1 + x^2])])/(2*Sqrt[2]*Sqrt[(1 + x)^2/(1 + x^2)]*Sqrt[1 + x^2])}

{Sqrt[1 + 2*x/(1 + x^2)]/(1 + x^2), x, 2, -(((1 - x)*Sqrt[(1 + x)^2/(1 + x^2)])/(1 + x))}
