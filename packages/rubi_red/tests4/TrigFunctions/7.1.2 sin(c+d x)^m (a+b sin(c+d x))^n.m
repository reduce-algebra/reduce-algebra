(* ::Package:: *)

(* ::Title:: *)
(*Integration problems of the form *)
(*Sin[c+d x]^m (A+B Sin[c+d x]+C Sin[c+d x]^2) (a+b Sin[c+d x])^n*)


(* ::Section:: *)
(*Sin[c+d x]^m (a+b Sin[c+d x])^n*)


(* ::Subsection::Closed:: *)
(*Integrands of the form Sin[c+d x]^m (a+b Sin[c+d x])^n*)


(* ::Subsubsection::Closed:: *)
(*n>0*)


{(a + b*Sin[c + d*x])^4, x, 4, (1/8)*(8*a^4 + 24*a^2*b^2 + 3*b^4)*x - (a*b*(19*a^2 + 16*b^2)*Cos[c + d*x])/(6*d) - (b^2*(26*a^2 + 9*b^2)*Cos[c + d*x]*Sin[c + d*x])/(24*d) - (7*a*b*Cos[c + d*x]*(a + b*Sin[c + d*x])^2)/(12*d) - (b*Cos[c + d*x]*(a + b*Sin[c + d*x])^3)/(4*d)}
{(a + b*Sin[c + d*x])^3, x, 3, (1/2)*a*(2*a^2 + 3*b^2)*x - (2*b*(4*a^2 + b^2)*Cos[c + d*x])/(3*d) - (5*a*b^2*Cos[c + d*x]*Sin[c + d*x])/(6*d) - (b*Cos[c + d*x]*(a + b*Sin[c + d*x])^2)/(3*d)}
{(a + b*Sin[c + d*x])^2, x, 2, (1/2)*(2*a^2 + b^2)*x - (2*a*b*Cos[c + d*x])/d - (b^2*Cos[c + d*x]*Sin[c + d*x])/(2*d)}
{(a + b*Sin[c + d*x]), x, 2, a*x - (b*Cos[c + d*x])/d}


(* ::Subsubsection::Closed:: *)
(*n<0*)


{Sin[x]^4/(a + b*Sin[x]), x, 5, -((a*(2*a^2 + b^2)*x)/(2*b^4)) + (2*a^4*ArcTan[(b + a*Tan[x/2])/Sqrt[a^2 - b^2]])/(b^4*Sqrt[a^2 - b^2]) - ((3*a^2 + 2*b^2)*Cos[x])/(3*b^3) + (a*Cos[x]*Sin[x])/(2*b^2) - (Cos[x]*Sin[x]^2)/(3*b)}
{Sin[x]^3/(a + b*Sin[x]), x, 4, ((2*a^2 + b^2)*x)/(2*b^3) - (2*a^3*ArcTan[(b + a*Tan[x/2])/Sqrt[a^2 - b^2]])/(b^3*Sqrt[a^2 - b^2]) + (a*Cos[x])/b^2 - (Cos[x]*Sin[x])/(2*b)}
{Sin[x]^2/(a + b*Sin[x]), x, 3, -((a*x)/b^2) + (2*a^2*ArcTan[(b + a*Tan[x/2])/Sqrt[a^2 - b^2]])/(b^2*Sqrt[a^2 - b^2]) - Cos[x]/b}
{Sin[x]^1/(a + b*Sin[x]), x, 2, x/b - (2*a*ArcTan[(b + a*Tan[x/2])/Sqrt[a^2 - b^2]])/(b*Sqrt[a^2 - b^2])}
{Csc[x]^1/(a + b*Sin[x]), x, 3, -((2*b*ArcTan[(b + a*Tan[x/2])/Sqrt[a^2 - b^2]])/(a*Sqrt[a^2 - b^2])) - ArcTanh[Cos[x]]/a}
{Csc[x]^2/(a + b*Sin[x]), x, 5, (2*b^2*ArcTan[(b + a*Tan[x/2])/Sqrt[a^2 - b^2]])/(a^2*Sqrt[a^2 - b^2]) + (b*ArcTanh[Cos[x]])/a^2 - Cot[x]/a}
{Csc[x]^3/(a + b*Sin[x]), x, 5, -((2*b^3*ArcTan[(b + a*Tan[x/2])/Sqrt[a^2 - b^2]])/(a^3*Sqrt[a^2 - b^2])) - ((a^2 + 2*b^2)*ArcTanh[Cos[x]])/(2*a^3) + (b*Cot[x])/a^2 - (Cot[x]*Csc[x])/(2*a)}
{Csc[x]^4/(a + b*Sin[x]), x, 6, (2*b^4*ArcTan[(b + a*Tan[x/2])/Sqrt[a^2 - b^2]])/(a^4*Sqrt[a^2 - b^2]) + (b*(a^2 + 2*b^2)*ArcTanh[Cos[x]])/(2*a^4) - ((2*a^2 + 3*b^2)*Cot[x])/(3*a^3) + (b*Cot[x]*Csc[x])/(2*a^2) - (Cot[x]*Csc[x]^2)/(3*a)}


{Sin[x]^4/(a + b*Sin[x])^2, x, 5, ((6*a^2 + b^2)*x)/(2*b^4) - (2*a^3*(3*a^2 - 4*b^2)*ArcTan[(b + a*Tan[x/2])/Sqrt[a^2 - b^2]])/(b^4*(a^2 - b^2)^(3/2)) + (a*(3*a^2 - 2*b^2)*Cos[x])/(b^3*(a^2 - b^2)) - ((3*a^2 - b^2)*Cos[x]*Sin[x])/(2*b^2*(a^2 - b^2)) + (a^2*Cos[x]*Sin[x]^2)/(b*(a^2 - b^2)*(a + b*Sin[x]))}
{Sin[x]^3/(a + b*Sin[x])^2, x, 4, -((2*a*x)/b^3) + (2*a^2*(2*a^2 - 3*b^2)*ArcTan[(b + a*Tan[x/2])/Sqrt[a^2 - b^2]])/(b^3*(a^2 - b^2)^(3/2)) - ((2*a^2 - b^2)*Cos[x])/(b^2*(a^2 - b^2)) + (a^2*Cos[x]*Sin[x])/(b*(a^2 - b^2)*(a + b*Sin[x]))}
{Sin[x]^2/(a + b*Sin[x])^2, x, 3, x/b^2 - (2*a*(a^2 - 2*b^2)*ArcTan[(b + a*Tan[x/2])/Sqrt[a^2 - b^2]])/(b^2*(a^2 - b^2)^(3/2)) + (a^2*Cos[x])/(b*(a^2 - b^2)*(a + b*Sin[x]))}
{Sin[x]^1/(a + b*Sin[x])^2, x, 3, -((2*b*ArcTan[(b + a*Tan[x/2])/Sqrt[a^2 - b^2]])/(a^2 - b^2)^(3/2)) - (a*Cos[x])/((a^2 - b^2)*(a + b*Sin[x]))}
{Csc[x]^1/(a + b*Sin[x])^2, x, 4, -((2*b*(2*a^2 - b^2)*ArcTan[(b + a*Tan[x/2])/Sqrt[a^2 - b^2]])/(a^2*(a^2 - b^2)^(3/2))) - ArcTanh[Cos[x]]/a^2 - (b^2*Cos[x])/(a*(a^2 - b^2)*(a + b*Sin[x]))}
{Csc[x]^2/(a + b*Sin[x])^2, x, 5, (2*b^2*(3*a^2 - 2*b^2)*ArcTan[(b + a*Tan[x/2])/Sqrt[a^2 - b^2]])/(a^3*(a^2 - b^2)^(3/2)) + (2*b*ArcTanh[Cos[x]])/a^3 - ((a^2 - 2*b^2)*Cot[x])/(a^2*(a^2 - b^2)) - (b^2*Cot[x])/(a*(a^2 - b^2)*(a + b*Sin[x]))}
{Csc[x]^3/(a + b*Sin[x])^2, x, 6, -((2*b^3*(4*a^2 - 3*b^2)*ArcTan[(b + a*Tan[x/2])/Sqrt[a^2 - b^2]])/(a^4*(a^2 - b^2)^(3/2))) - ((a^2 + 6*b^2)*ArcTanh[Cos[x]])/(2*a^4) + (b*(2*a^2 - 3*b^2)*Cot[x])/(a^3*(a^2 - b^2)) - ((a^2 - 3*b^2)*Cot[x]*Csc[x])/(2*a^2*(a^2 - b^2)) - (b^2*Cot[x]*Csc[x])/(a*(a^2 - b^2)*(a + b*Sin[x]))}
{Csc[x]^4/(a + b*Sin[x])^2, x, 7, (2*b^4*(5*a^2 - 4*b^2)*ArcTan[(b + a*Tan[x/2])/Sqrt[a^2 - b^2]])/(a^5*(a^2 - b^2)^(3/2)) + (b*(a^2 + 4*b^2)*ArcTanh[Cos[x]])/a^5 - ((a^2 + 3*b^2)*Cot[x])/a^4 - Cot[x]^3/(3*a^2) + (b*Cot[x]*Csc[x])/a^3 + (b^5*Cos[x])/(a^4*(a^2 - b^2)*(a + b*Sin[x])), (2*b^4*(5*a^2 - 4*b^2)*ArcTan[(b + a*Tan[x/2])/Sqrt[a^2 - b^2]])/(a^5*(a^2 - b^2)^(3/2)) + (b*(a^2 + 4*b^2)*ArcTanh[Cos[x]])/a^5 - ((2*a^4 + 7*a^2*b^2 - 12*b^4)*Cot[x])/(3*a^4*(a^2 - b^2)) + (b*(a^2 - 2*b^2)*Cot[x]*Csc[x])/(a^3*(a^2 - b^2)) - ((a^2 - 4*b^2)*Cot[x]*Csc[x]^2)/(3*a^2*(a^2 - b^2)) - (b^2*Cot[x]*Csc[x]^2)/(a*(a^2 - b^2)*(a + b*Sin[x]))}


{Sin[x]^4/(a + b*Sin[x])^3, x, 5, -((3*a*x)/b^4) + (3*a^2*(2*a^4 - 5*a^2*b^2 + 4*b^4)*ArcTan[(b + a*Tan[x/2])/Sqrt[a^2 - b^2]])/(b^4*(a^2 - b^2)^(5/2)) - ((6*a^4 - 11*a^2*b^2 + 2*b^4)*Cos[x])/(2*b^3*(a^2 - b^2)^2) + (a^2*Cos[x]*Sin[x]^2)/(2*b*(a^2 - b^2)*(a + b*Sin[x])^2) + (3*a^2*(a^2 - 2*b^2)*Cos[x]*Sin[x])/(2*b^2*(a^2 - b^2)^2*(a + b*Sin[x]))}
{Sin[x]^3/(a + b*Sin[x])^3, x, 4, x/b^3 - (a*(2*a^4 - 5*a^2*b^2 + 6*b^4)*ArcTan[(b + a*Tan[x/2])/Sqrt[a^2 - b^2]])/(b^3*(a^2 - b^2)^(5/2)) + (a^2*Cos[x]*Sin[x])/(2*b*(a^2 - b^2)*(a + b*Sin[x])^2) + (a^2*(2*a^2 - 5*b^2)*Cos[x])/(2*b^2*(a^2 - b^2)^2*(a + b*Sin[x]))}
{Sin[x]^2/(a + b*Sin[x])^3, x, 4, ((a^2 + 2*b^2)*ArcTan[(b + a*Tan[x/2])/Sqrt[a^2 - b^2]])/(a^2 - b^2)^(5/2) + (a^2*Cos[x])/(2*b*(a^2 - b^2)*(a + b*Sin[x])^2) - (a*(a^2 - 4*b^2)*Cos[x])/(2*b*(a^2 - b^2)^2*(a + b*Sin[x]))}
{Sin[x]^1/(a + b*Sin[x])^3, x, 4, -((3*a*b*ArcTan[(b + a*Tan[x/2])/Sqrt[a^2 - b^2]])/(a^2 - b^2)^(5/2)) - (a*Cos[x])/(2*(a^2 - b^2)*(a + b*Sin[x])^2) - ((a^2 + 2*b^2)*Cos[x])/(2*(a^2 - b^2)^2*(a + b*Sin[x]))}
{Csc[x]^1/(a + b*Sin[x])^3, x, 5, -((b*(6*a^4 - 5*a^2*b^2 + 2*b^4)*ArcTan[(b + a*Tan[x/2])/Sqrt[a^2 - b^2]])/(a^3*(a^2 - b^2)^(5/2))) - ArcTanh[Cos[x]]/a^3 - (b^2*Cos[x])/(2*a*(a^2 - b^2)*(a + b*Sin[x])^2) - (b^2*(5*a^2 - 2*b^2)*Cos[x])/(2*a^2*(a^2 - b^2)^2*(a + b*Sin[x]))}
{Csc[x]^2/(a + b*Sin[x])^3, x, 6, (3*b^2*(4*a^4 - 5*a^2*b^2 + 2*b^4)*ArcTan[(b + a*Tan[x/2])/Sqrt[a^2 - b^2]])/(a^4*(a^2 - b^2)^(5/2)) + (3*b*ArcTanh[Cos[x]])/a^4 - ((2*a^4 - 11*a^2*b^2 + 6*b^4)*Cot[x])/(2*a^3*(a^2 - b^2)^2) - (b^2*Cot[x])/(2*a*(a^2 - b^2)*(a + b*Sin[x])^2) - (3*b^2*(2*a^2 - b^2)*Cot[x])/(2*a^2*(a^2 - b^2)^2*(a + b*Sin[x]))}
{Csc[x]^3/(a + b*Sin[x])^3, x, 7, -((b^3*(20*a^4 - 29*a^2*b^2 + 12*b^4)*ArcTan[(b + a*Tan[x/2])/Sqrt[a^2 - b^2]])/(a^5*(a^2 - b^2)^(5/2))) - ((a^2 + 12*b^2)*ArcTanh[Cos[x]])/(2*a^5) + (3*b*(2*a^4 - 7*a^2*b^2 + 4*b^4)*Cot[x])/(2*a^4*(a^2 - b^2)^2) - ((a^4 - 10*a^2*b^2 + 6*b^4)*Cot[x]*Csc[x])/(2*a^3*(a^2 - b^2)^2) - (b^2*Cot[x]*Csc[x])/(2*a*(a^2 - b^2)*(a + b*Sin[x])^2) - (b^2*(7*a^2 - 4*b^2)*Cot[x]*Csc[x])/(2*a^2*(a^2 - b^2)^2*(a + b*Sin[x]))}
{Csc[x]^4/(a + b*Sin[x])^3, x, 8, (b^4*(30*a^4 - 47*a^2*b^2 + 20*b^4)*ArcTan[(b + a*Tan[x/2])/Sqrt[a^2 - b^2]])/(a^6*(a^2 - b^2)^(5/2)) + (b*(3*a^2 + 20*b^2)*ArcTanh[Cos[x]])/(2*a^6) - ((4*a^6 + 28*a^4*b^2 - 101*a^2*b^4 + 60*b^6)*Cot[x])/(6*a^5*(a^2 - b^2)^2) + (b*(3*a^4 - 16*a^2*b^2 + 10*b^4)*Cot[x]*Csc[x])/(2*a^4*(a^2 - b^2)^2) - ((2*a^4 - 31*a^2*b^2 + 20*b^4)*Cot[x]*Csc[x]^2)/(6*a^3*(a^2 - b^2)^2) - (b^2*Cot[x]*Csc[x]^2)/(2*a*(a^2 - b^2)*(a + b*Sin[x])^2) - (b^2*(8*a^2 - 5*b^2)*Cot[x]*Csc[x]^2)/(2*a^2*(a^2 - b^2)^2*(a + b*Sin[x]))}


{1/(a + b*Sin[c + d*x]), x, 1, (2*ArcTan[(b + a*Tan[(1/2)*(c + d*x)])/Sqrt[a^2 - b^2]])/(Sqrt[a^2 - b^2]*d)}
{1/(a + b*Sin[c + d*x])^2, x, 3, (2*a*ArcTan[(b + a*Tan[(1/2)*(c + d*x)])/Sqrt[a^2 - b^2]])/((a^2 - b^2)^(3/2)*d) + (b*Cos[c + d*x])/((a^2 - b^2)*d*(a + b*Sin[c + d*x]))}
{1/(a + b*Sin[c + d*x])^3, x, 4, ((2*a^2 + b^2)*ArcTan[(b + a*Tan[(1/2)*(c + d*x)])/Sqrt[a^2 - b^2]])/((a^2 - b^2)^(5/2)*d) + (b*Cos[c + d*x])/(2*(a^2 - b^2)*d*(a + b*Sin[c + d*x])^2) + (3*a*b*Cos[c + d*x])/(2*(a^2 - b^2)^2*d*(a + b*Sin[c + d*x]))}
{1/(a + b*Sin[c + d*x])^4, x, 5, (a*(2*a^2 + 3*b^2)*ArcTan[(b + a*Tan[(1/2)*(c + d*x)])/Sqrt[a^2 - b^2]])/((a^2 - b^2)^(7/2)*d) + (b*Cos[c + d*x])/(3*(a^2 - b^2)*d*(a + b*Sin[c + d*x])^3) + (5*a*b*Cos[c + d*x])/(6*(a^2 - b^2)^2*d*(a + b*Sin[c + d*x])^2) + (b*(11*a^2 + 4*b^2)*Cos[c + d*x])/(6*(a^2 - b^2)^3*d*(a + b*Sin[c + d*x]))}

{1/(3 + 5*Sin[c + d*x]), x, 1, -(ArcTanh[(1/4)*(5 + 3*Tan[(1/2)*(c + d*x)])]/(2*d))}
{1/(3 + 5*Sin[c + d*x])^2, x, 3, (3*ArcTanh[(1/4)*(5 + 3*Tan[(1/2)*(c + d*x)])])/(32*d) - (5*Cos[c + d*x])/(16*d*(3 + 5*Sin[c + d*x]))}
{1/(3 + 5*Sin[c + d*x])^3, x, 4, -((43*ArcTanh[(1/4)*(5 + 3*Tan[(1/2)*(c + d*x)])])/(1024*d)) - (5*Cos[c + d*x])/(32*d*(3 + 5*Sin[c + d*x])^2) + (45*Cos[c + d*x])/(512*d*(3 + 5*Sin[c + d*x]))}
{1/(3 + 5*Sin[c + d*x])^4, x, 5, (279*ArcTanh[(1/4)*(5 + 3*Tan[(1/2)*(c + d*x)])])/(16384*d) - (5*Cos[c + d*x])/(48*d*(3 + 5*Sin[c + d*x])^3) + (25*Cos[c + d*x])/(512*d*(3 + 5*Sin[c + d*x])^2) - (995*Cos[c + d*x])/(24576*d*(3 + 5*Sin[c + d*x]))}

{1/(5 + 3*Sin[c + d*x]), x, 1, x/4 + ArcTan[Cos[c + d*x]/(3 + Sin[c + d*x])]/(2*d)}
{1/(5 + 3*Sin[c + d*x])^2, x, 3, (5*x)/64 + (5*ArcTan[Cos[c + d*x]/(3 + Sin[c + d*x])])/(32*d) + (3*Cos[c + d*x])/(16*d*(5 + 3*Sin[c + d*x]))}
{1/(5 + 3*Sin[c + d*x])^3, x, 4, (59*x)/2048 + (59*ArcTan[Cos[c + d*x]/(3 + Sin[c + d*x])])/(1024*d) + (3*Cos[c + d*x])/(32*d*(5 + 3*Sin[c + d*x])^2) + (45*Cos[c + d*x])/(512*d*(5 + 3*Sin[c + d*x]))}
{1/(5 + 3*Sin[c + d*x])^4, x, 5, (385*x)/32768 + (385*ArcTan[Cos[c + d*x]/(3 + Sin[c + d*x])])/(16384*d) + Cos[c + d*x]/(16*d*(5 + 3*Sin[c + d*x])^3) + (25*Cos[c + d*x])/(512*d*(5 + 3*Sin[c + d*x])^2) + (311*Cos[c + d*x])/(8192*d*(5 + 3*Sin[c + d*x]))}


{Sin[c + d*x]^(-1 - a^2/(a^2 + b^2))*(a + b*Sin[c + d*x])^2, x, 2, -(((a^2 + b^2)*Cos[c + d*x])/(Sin[c + d*x]^(a^2/(a^2 + b^2))*d)) - (2*a*b*Cos[c + d*x]*Hypergeometric2F1[1/2, (1/2)*(1 + a^2/(a^2 + b^2)), 3/2, Cos[c + d*x]^2]*Sin[c + d*x]^(b^2/(a^2 + b^2)))/((Sin[c + d*x]^2)^(b^2/(2*(a^2 + b^2)))*d)}
{(1 + 2*Sin[c + d*x])^2/Sin[c + d*x]^(6/5), x, 2, -((5*Cos[c + d*x])/(d*Sin[c + d*x]^(1/5))) - (4*Cos[c + d*x]*Hypergeometric2F1[1/2, 3/5, 3/2, Cos[c + d*x]^2]*Sin[c + d*x]^(4/5))/(d*(Sin[c + d*x]^2)^(2/5))}


(* ::Subsection::Closed:: *)
(*Integrands of the form Sin[c+d x]^m (a+b Sin[c+d x])^(n/2)*)


{Sin[x]/Sqrt[a + b*Sin[x]], x, 5, -((2*EllipticE[Pi/4 - x/2, (2*b)/(a + b)]*Sqrt[a + b*Sin[x]])/(b*Sqrt[(a + b*Sin[x])/(a + b)])) + (2*a*EllipticF[Pi/4 - x/2, (2*b)/(a + b)]*Sqrt[(a + b*Sin[x])/(a + b)])/(b*Sqrt[a + b*Sin[x]])}


(* Integrands of the form (a+b*Sin[c+d*x])^n where n is a half- integer *)
{(a + b*Sin[x])^(7/2), x, 8, (-(2/105))*b*(71*a^2 + 25*b^2)*Cos[x]*Sqrt[a + b*Sin[x]] - (24/35)*a*b*Cos[x]*(a + b*Sin[x])^(3/2) - (2/7)*b*Cos[x]*(a + b*Sin[x])^(5/2) - (32*a*(11*a^2 + 13*b^2)*EllipticE[Pi/4 - x/2, (2*b)/(a + b)]*Sqrt[a + b*Sin[x]])/(105*Sqrt[(a + b*Sin[x])/(a + b)]) + (2*(71*a^4 - 46*a^2*b^2 - 25*b^4)*EllipticF[Pi/4 - x/2, (2*b)/(a + b)]*Sqrt[(a + b*Sin[x])/(a + b)])/(105*Sqrt[a + b*Sin[x]])}
{(a + b*Sin[x])^(5/2), x, 7, (-(16/15))*a*b*Cos[x]*Sqrt[a + b*Sin[x]] - (2/5)*b*Cos[x]*(a + b*Sin[x])^(3/2) - (2*(23*a^2 + 9*b^2)*EllipticE[Pi/4 - x/2, (2*b)/(a + b)]*Sqrt[a + b*Sin[x]])/(15*Sqrt[(a + b*Sin[x])/(a + b)]) + (16*a*(a^2 - b^2)*EllipticF[Pi/4 - x/2, (2*b)/(a + b)]*Sqrt[(a + b*Sin[x])/(a + b)])/(15*Sqrt[a + b*Sin[x]])}
{(a + b*Sin[x])^(3/2), x, 6, (-(2/3))*b*Cos[x]*Sqrt[a + b*Sin[x]] - (8*a*EllipticE[Pi/4 - x/2, (2*b)/(a + b)]*Sqrt[a + b*Sin[x]])/(3*Sqrt[(a + b*Sin[x])/(a + b)]) + (2*(a^2 - b^2)*EllipticF[Pi/4 - x/2, (2*b)/(a + b)]*Sqrt[(a + b*Sin[x])/(a + b)])/(3*Sqrt[a + b*Sin[x]])}
{(a + b*Sin[x])^(1/2), x, 2, -((2*EllipticE[Pi/4 - x/2, (2*b)/(a + b)]*Sqrt[a + b*Sin[x]])/Sqrt[(a + b*Sin[x])/(a + b)])}
{1/(a + b*Sin[x])^(1/2), x, 2, -((2*EllipticF[Pi/4 - x/2, (2*b)/(a + b)]*Sqrt[(a + b*Sin[x])/(a + b)])/Sqrt[a + b*Sin[x]])}
{1/(a + b*Sin[x])^(3/2), x, 4, (2*b*Cos[x])/((a^2 - b^2)*Sqrt[a + b*Sin[x]]) - (2*EllipticE[Pi/4 - x/2, (2*b)/(a + b)]*Sqrt[a + b*Sin[x]])/((a^2 - b^2)*Sqrt[(a + b*Sin[x])/(a + b)])}
{1/(a + b*Sin[x])^(5/2), x, 7, (2*b*Cos[x])/(3*(a^2 - b^2)*(a + b*Sin[x])^(3/2)) + (8*a*b*Cos[x])/(3*(a^2 - b^2)^2*Sqrt[a + b*Sin[x]]) - (8*a*EllipticE[Pi/4 - x/2, (2*b)/(a + b)]*Sqrt[a + b*Sin[x]])/(3*(a^2 - b^2)^2*Sqrt[(a + b*Sin[x])/(a + b)]) + (2*EllipticF[Pi/4 - x/2, (2*b)/(a + b)]*Sqrt[(a + b*Sin[x])/(a + b)])/(3*(a^2 - b^2)*Sqrt[a + b*Sin[x]])}
{1/(a + b*Sin[x])^(7/2), x, 8, (2*b*Cos[x])/(5*(a^2 - b^2)*(a + b*Sin[x])^(5/2)) + (16*a*b*Cos[x])/(15*(a^2 - b^2)^2*(a + b*Sin[x])^(3/2)) + (2*b*(23*a^2 + 9*b^2)*Cos[x])/(15*(a^2 - b^2)^3*Sqrt[a + b*Sin[x]]) - (2*(23*a^2 + 9*b^2)*EllipticE[Pi/4 - x/2, (2*b)/(a + b)]*Sqrt[a + b*Sin[x]])/(15*(a^2 - b^2)^3*Sqrt[(a + b*Sin[x])/(a + b)]) + (16*a*EllipticF[Pi/4 - x/2, (2*b)/(a + b)]*Sqrt[(a + b*Sin[x])/(a + b)])/(15*(a^2 - b^2)^2*Sqrt[a + b*Sin[x]])}


(* ::Subsection:: *)
(*Integrands of the form Sin[c+d x]^(m/2) (a+b Sin[c+d x])^n*)


(* ::Subsection::Closed:: *)
(*Integrands of the form Sin[c+d x]^(m/2) (a+b Sin[c+d x])^(n/2)*)


{Sqrt[Sin[c + d*x]]*Sqrt[a + b*Sin[c + d*x]], x, 6, -((Cos[c + d*x]*Sqrt[Sin[c + d*x]]*Sqrt[a + b*Sin[c + d*x]])/(d*(1 + Sin[c + d*x]))) - ((a + b)*EllipticE[ArcSin[Cos[c + d*x]/(1 + Sin[c + d*x])], -((a - b)/(a + b))]*Sqrt[1 + Sin[c + d*x]]*Sqrt[(a + b*Sin[c + d*x])/((a + b)*(1 + Sin[c + d*x]))])/(d*Sqrt[a + b*Sin[c + d*x]]) + (2*a*EllipticF[ArcSin[Cos[c + d*x]/(1 + Sin[c + d*x])], -((a - b)/(a + b))]*Sqrt[1 + Sin[c + d*x]]*Sqrt[(a + b*Sin[c + d*x])/((a + b)*(1 + Sin[c + d*x]))])/(d*Sqrt[a + b*Sin[c + d*x]]) + (2*a*EllipticPi[-1, -ArcSin[Cos[c + d*x]/(1 + Sin[c + d*x])], -((a - b)/(a + b))]*Sqrt[1 + Sin[c + d*x]]*Sqrt[(a + b*Sin[c + d*x])/((a + b)*(1 + Sin[c + d*x]))])/(d*Sqrt[a + b*Sin[c + d*x]])}
{1/(Sqrt[Sin[c + d*x]]*Sqrt[a + b*Sin[c + d*x]]), x, 1, -((2*EllipticF[ArcSin[Cos[c + d*x]/(1 + Sin[c + d*x])], -((a - b)/(a + b))]*Sqrt[1 + Sin[c + d*x]]*Sqrt[(a + b*Sin[c + d*x])/((a + b)*(1 + Sin[c + d*x]))])/(d*Sqrt[a + b*Sin[c + d*x]]))}


(* ::Section:: *)
(*Sin[c+d x]^m (A+B Sin[c+d x]) (a+b Sin[c+d x])^n*)


(* ::Subsection::Closed:: *)
(*Integrands of the form Sin[c+d x]^m (A+B Sin[c+d x]) (a+b Sin[c+d x])^n*)


(* Integrands of the form (A+B*Sin[x])*(a+b*Sin[x])^n where n is an integer *)
{(A + B*Sin[x])/(a + b*Sin[x]), x, 2, (B*x)/b + (2*(A*b - a*B)*ArcTan[(b + a*Tan[x/2])/Sqrt[a^2 - b^2]])/(b*Sqrt[a^2 - b^2])}
{(A + B*Sin[x])/(a + b*Sin[x])^2, x, 3, (2*(a*A - b*B)*ArcTan[(b + a*Tan[x/2])/Sqrt[a^2 - b^2]])/(a^2 - b^2)^(3/2) + ((A*b - a*B)*Cos[x])/((a^2 - b^2)*(a + b*Sin[x]))}
{(A + B*Sin[x])/(a + b*Sin[x])^3, x, 4, ((2*a^2*A + A*b^2 - 3*a*b*B)*ArcTan[(b + a*Tan[x/2])/Sqrt[a^2 - b^2]])/(a^2 - b^2)^(5/2) + ((A*b - a*B)*Cos[x])/(2*(a^2 - b^2)*(a + b*Sin[x])^2) + ((3*a*A*b - a^2*B - 2*b^2*B)*Cos[x])/(2*(a^2 - b^2)^2*(a + b*Sin[x]))}
{(A + B*Sin[x])/(a + b*Sin[x])^4, x, 5, ((2*a^3*A + 3*a*A*b^2 - 4*a^2*b*B - b^3*B)*ArcTan[(b + a*Tan[x/2])/Sqrt[a^2 - b^2]])/(a^2 - b^2)^(7/2) + ((A*b - a*B)*Cos[x])/(3*(a^2 - b^2)*(a + b*Sin[x])^3) + ((5*a*A*b - 2*a^2*B - 3*b^2*B)*Cos[x])/(6*(a^2 - b^2)^2*(a + b*Sin[x])^2) + ((11*a^2*A*b + 4*A*b^3 - 2*a^3*B - 13*a*b^2*B)*Cos[x])/(6*(a^2 - b^2)^3*(a + b*Sin[x]))}

{(b*B/a + B*Sin[x])/(a + b*Sin[x]), x, 2, (B*x)/b - (2*Sqrt[a^2 - b^2]*B*ArcTan[(b + a*Tan[x/2])/Sqrt[a^2 - b^2]])/(a*b)}
{(a*B/b + B*Sin[x])/(a + b*Sin[x]), x, 2, (B*x)/b}

{(a + b*Sin[x])/(b + a*Sin[x])^2, x, 2, -(Cos[x]/(b + a*Sin[x]))}
{(2 - Sin[x])/(2 + Sin[x]), x, 2, -x + (4*x)/Sqrt[3] + (8*ArcTan[Cos[x]/(2 + Sqrt[3] + Sin[x])])/Sqrt[3]}


(* ::Subsection::Closed:: *)
(*Integrands of the form Sin[c+d x]^m (A+B Sin[c+d x]) (a+b Sin[c+d x])^(n/2)*)


(* Integrands of the form (A+B*Sin[x])*(a+b*Sin[x])^n where n is a half-integer *)
{(A + B*Sin[x])*(a + b*Sin[x])^(5/2), x, 8, (-(2/105))*(56*a*A*b + 15*a^2*B + 25*b^2*B)*Cos[x]*Sqrt[a + b*Sin[x]] - (2/35)*(7*A*b + 5*a*B)*Cos[x]*(a + b*Sin[x])^(3/2) - (2/7)*B*Cos[x]*(a + b*Sin[x])^(5/2) - (2*(161*a^2*A*b + 63*A*b^3 + 15*a^3*B + 145*a*b^2*B)*EllipticE[Pi/4 - x/2, (2*b)/(a + b)]*Sqrt[a + b*Sin[x]])/(105*b*Sqrt[(a + b*Sin[x])/(a + b)]) + (2*(a^2 - b^2)*(56*a*A*b + 15*a^2*B + 25*b^2*B)*EllipticF[Pi/4 - x/2, (2*b)/(a + b)]*Sqrt[(a + b*Sin[x])/(a + b)])/(105*b*Sqrt[a + b*Sin[x]])}
{(A + B*Sin[x])*(a + b*Sin[x])^(3/2), x, 7, (-(2/15))*(5*A*b + 3*a*B)*Cos[x]*Sqrt[a + b*Sin[x]] - (2/5)*B*Cos[x]*(a + b*Sin[x])^(3/2) - (2*(20*a*A*b + 3*a^2*B + 9*b^2*B)*EllipticE[Pi/4 - x/2, (2*b)/(a + b)]*Sqrt[a + b*Sin[x]])/(15*b*Sqrt[(a + b*Sin[x])/(a + b)]) + (2*(a^2 - b^2)*(5*A*b + 3*a*B)*EllipticF[Pi/4 - x/2, (2*b)/(a + b)]*Sqrt[(a + b*Sin[x])/(a + b)])/(15*b*Sqrt[a + b*Sin[x]])}
{(A + B*Sin[x])*(a + b*Sin[x])^(1/2), x, 6, (-(2/3))*B*Cos[x]*Sqrt[a + b*Sin[x]] - (2*(3*A*b + a*B)*EllipticE[Pi/4 - x/2, (2*b)/(a + b)]*Sqrt[a + b*Sin[x]])/(3*b*Sqrt[(a + b*Sin[x])/(a + b)]) + (2*(a^2 - b^2)*B*EllipticF[Pi/4 - x/2, (2*b)/(a + b)]*Sqrt[(a + b*Sin[x])/(a + b)])/(3*b*Sqrt[a + b*Sin[x]])}
{(A + B*Sin[x])/(a + b*Sin[x])^(1/2), x, 5, -((2*B*EllipticE[Pi/4 - x/2, (2*b)/(a + b)]*Sqrt[a + b*Sin[x]])/(b*Sqrt[(a + b*Sin[x])/(a + b)])) - (2*(A*b - a*B)*EllipticF[Pi/4 - x/2, (2*b)/(a + b)]*Sqrt[(a + b*Sin[x])/(a + b)])/(b*Sqrt[a + b*Sin[x]])}
{(A + B*Sin[x])/(a + b*Sin[x])^(3/2), x, 6, (2*(A*b - a*B)*Cos[x])/((a^2 - b^2)*Sqrt[a + b*Sin[x]]) - (2*(A*b - a*B)*EllipticE[Pi/4 - x/2, (2*b)/(a + b)]*Sqrt[a + b*Sin[x]])/(b*(a^2 - b^2)*Sqrt[(a + b*Sin[x])/(a + b)]) - (2*B*EllipticF[Pi/4 - x/2, (2*b)/(a + b)]*Sqrt[(a + b*Sin[x])/(a + b)])/(b*Sqrt[a + b*Sin[x]])}
{(A + B*Sin[x])/(a + b*Sin[x])^(5/2), x, 7, (2*(A*b - a*B)*Cos[x])/(3*(a^2 - b^2)*(a + b*Sin[x])^(3/2)) + (2*(4*a*A*b - a^2*B - 3*b^2*B)*Cos[x])/(3*(a^2 - b^2)^2*Sqrt[a + b*Sin[x]]) - (2*(4*a*A*b - a^2*B - 3*b^2*B)*EllipticE[Pi/4 - x/2, (2*b)/(a + b)]*Sqrt[a + b*Sin[x]])/(3*b*(a^2 - b^2)^2*Sqrt[(a + b*Sin[x])/(a + b)]) + (2*(A*b - a*B)*EllipticF[Pi/4 - x/2, (2*b)/(a + b)]*Sqrt[(a + b*Sin[x])/(a + b)])/(3*b*(a^2 - b^2)*Sqrt[a + b*Sin[x]])}


(* ::Section:: *)
(*Sin[c+d x]^m (A+C Sin[c+d x]^2) (a+b Sin[c+d x])^n*)


(* ::Subsection:: *)
(*Integrands of the form Sin[c+d x]^m (A+C Sin[c+d x]^2) (a+b Sin[c+d x])^n*)


(* ::Subsection:: *)
(*Integrands of the form Sin[c+d x]^m (A+C Sin[c+d x]^2) (a+b Sin[c+d x])^(n/2)*)


(* ::Section:: *)
(*Sin[c+d x]^m (A+B Sin[c+d x]+C Sin[c+d x]^2) (a+b Sin[c+d x])^n*)


(* ::Subsection::Closed:: *)
(*Integrands of the form Sin[c+d x]^m (A+B Sin[c+d x]+C Sin[c+d x]^2) (a+b Sin[c+d x])^n*)


{(A + B*Sin[c + d*x] + C*Sin[c + d*x]^2)*(a + b*Sin[c + d*x]), x, 3, (1/2)*(b*B + a*(2*A + C))*x - ((A*b + a*B + b*C)*Cos[c + d*x])/d + (b*C*Cos[c + d*x]^3)/(3*d) - ((b*B + a*C)*Cos[c + d*x]*Sin[c + d*x])/(2*d), (1/2)*(b*B + a*(2*A + C))*x - ((3*A*b^2 + 3*a*b*B - a^2*C + 2*b^2*C)*Cos[c + d*x])/(3*b*d) - ((3*b*B - a*C)*Cos[c + d*x]*Sin[c + d*x])/(6*d) - (C*Cos[c + d*x]*(a + b*Sin[c + d*x])^2)/(3*b*d)}


(* ::Subsection:: *)
(*Integrands of the form Sin[c+d x]^m (A+B Sin[c+d x]+C Sin[c+d x]^2) (a+b Sin[c+d x])^(n/2)*)


(* ::Subsection::Closed:: *)
(*Integrands of the form Sin[c+d x]^(m/2) (A+B Sin[c+d x]+C Sin[c+d x]^2) (a+b Sin[c+d x])^n*)


{((a + b*Sin[x])*(A + B*Sin[x] + C*Sin[x]^2))/Sin[x]^(3/2), x, 5, -2*(b*B - a*(A - C))*EllipticE[Pi/4 - x/2, 2] - (2/3)*(3*A*b + 3*a*B + b*C)*EllipticF[Pi/4 - x/2, 2] - (2*a*A*Cos[x])/Sqrt[Sin[x]] - (2/3)*b*C*Cos[x]*Sqrt[Sin[x]]}
