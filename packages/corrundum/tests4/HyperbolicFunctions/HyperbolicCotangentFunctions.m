(* ::Package:: *)

(* ::Title:: *)
(*Integration Problems Involving Hyperbolic Cotangents*)


(* ::Section::Closed:: *)
(*Integrands of the form Coth[a+b x]^n*)


(* ::Subsection::Closed:: *)
(*Integrands of the form Coth[a+b x]^n*)


{Coth[a + b*x]^n, x, 2, (Coth[a + b*x]^(1 + n)*Hypergeometric2F1[1, (1 + n)/2, (3 + n)/2, Coth[a + b*x]^2])/(b*(1 + n))}

{Coth[a + b*x], x, 1, Log[Sinh[a + b*x]]/b}
{Coth[a + b*x]^2, x, 2, x - Coth[a + b*x]/b}
{Coth[a + b*x]^3, x, 2, -(Coth[a + b*x]^2/(2*b)) + Log[Sinh[a + b*x]]/b}
{Coth[a + b*x]^4, x, 3, x - Coth[a + b*x]/b - Coth[a + b*x]^3/(3*b)}
{Coth[a + b*x]^5, x, 3, -(Coth[a + b*x]^2/(2*b)) - Coth[a + b*x]^4/(4*b) + Log[Sinh[a + b*x]]/b}
{Coth[a + b*x]^6, x, 4, x - Coth[a + b*x]/b - Coth[a + b*x]^3/(3*b) - Coth[a + b*x]^5/(5*b)}


(* ::Subsection::Closed:: *)
(*Integrands of the form Coth[a+b x]^(n/2)*)


{Coth[a + b*x]^(7/2), x, 6, ArcTan[Sqrt[Coth[a + b*x]]]/b + ArcTanh[Sqrt[Coth[a + b*x]]]/b - (2*Sqrt[Coth[a + b*x]])/b - (2*Coth[a + b*x]^(5/2))/(5*b)}
{Coth[a + b*x]^(5/2), x, 5, -(ArcTan[Sqrt[Coth[a + b*x]]]/b) + ArcTanh[Sqrt[Coth[a + b*x]]]/b - (2*Coth[a + b*x]^(3/2))/(3*b)}
{Coth[a + b*x]^(3/2), x, 5, ArcTan[Sqrt[Coth[a + b*x]]]/b + ArcTanh[Sqrt[Coth[a + b*x]]]/b - (2*Sqrt[Coth[a + b*x]])/b}
{Coth[a + b*x]^(1/2), x, 4, -(ArcTan[Sqrt[Coth[a + b*x]]]/b) + ArcTanh[Sqrt[Coth[a + b*x]]]/b}
{1/Coth[a + b*x]^(1/2), x, 4, ArcTan[Sqrt[Coth[a + b*x]]]/b + ArcTanh[Sqrt[Coth[a + b*x]]]/b}
{1/Coth[a + b*x]^(3/2), x, 5, -(ArcTan[Sqrt[Coth[a + b*x]]]/b) + ArcTanh[Sqrt[Coth[a + b*x]]]/b - 2/(b*Sqrt[Coth[a + b*x]])}
{1/Coth[a + b*x]^(5/2), x, 5, ArcTan[Sqrt[Coth[a + b*x]]]/b + ArcTanh[Sqrt[Coth[a + b*x]]]/b - 2/(3*b*Coth[a + b*x]^(3/2))}
{1/Coth[a + b*x]^(7/2), x, 6, -(ArcTan[Sqrt[Coth[a + b*x]]]/b) + ArcTanh[Sqrt[Coth[a + b*x]]]/b - 2/(5*b*Coth[a + b*x]^(5/2)) - 2/(b*Sqrt[Coth[a + b*x]])}


(* ::Subsection::Closed:: *)
(*Integrands of the form Coth[a+b x]^(n/3)*)


{Coth[a + b*x]^(4/3), x, 9, -((Sqrt[3]*ArcTan[(1 - 2*Coth[a + b*x]^(1/3))/Sqrt[3]])/(2*b)) + (Sqrt[3]*ArcTan[(1 + 2*Coth[a + b*x]^(1/3))/Sqrt[3]])/(2*b) + ArcTanh[Coth[a + b*x]^(1/3)]/b + ArcTanh[Coth[a + b*x]^(1/3)/(1 + Coth[a + b*x]^(2/3))]/(2*b) - (3*Coth[a + b*x]^(1/3))/b}
{Coth[a + b*x]^(2/3), x, 8, (Sqrt[3]*ArcTan[(1 - 2*Coth[a + b*x]^(1/3))/Sqrt[3]])/(2*b) - (Sqrt[3]*ArcTan[(1 + 2*Coth[a + b*x]^(1/3))/Sqrt[3]])/(2*b) + ArcTanh[Coth[a + b*x]^(1/3)]/b + ArcTanh[Coth[a + b*x]^(1/3)/(1 + Coth[a + b*x]^(2/3))]/(2*b)}
{Coth[a + b*x]^(1/3), x, 7, -((Sqrt[3]*ArcTan[(1 + 2*Coth[a + b*x]^(2/3))/Sqrt[3]])/(2*b)) - Log[1 - Coth[a + b*x]^(2/3)]/(2*b) + Log[1 + Coth[a + b*x]^(2/3) + Coth[a + b*x]^(4/3)]/(4*b)}
{1/Coth[a + b*x]^(1/3), x, 7, (Sqrt[3]*ArcTan[(1 + 2*Coth[a + b*x]^(2/3))/Sqrt[3]])/(2*b) - Log[1 - Coth[a + b*x]^(2/3)]/(2*b) + Log[1 + Coth[a + b*x]^(2/3) + Coth[a + b*x]^(4/3)]/(4*b)}
{1/Coth[a + b*x]^(2/3), x, 8, -((Sqrt[3]*ArcTan[(1 - 2*Coth[a + b*x]^(1/3))/Sqrt[3]])/(2*b)) + (Sqrt[3]*ArcTan[(1 + 2*Coth[a + b*x]^(1/3))/Sqrt[3]])/(2*b) + ArcTanh[Coth[a + b*x]^(1/3)]/b + ArcTanh[Coth[a + b*x]^(1/3)/(1 + Coth[a + b*x]^(2/3))]/(2*b)}
{1/Coth[a + b*x]^(4/3), x, 9, (Sqrt[3]*ArcTan[(1 - 2*Coth[a + b*x]^(1/3))/Sqrt[3]])/(2*b) - (Sqrt[3]*ArcTan[(1 + 2*Coth[a + b*x]^(1/3))/Sqrt[3]])/(2*b) + ArcTanh[Coth[a + b*x]^(1/3)]/b + ArcTanh[Coth[a + b*x]^(1/3)/(1 + Coth[a + b*x]^(2/3))]/(2*b) - 3/(b*Coth[a + b*x]^(1/3))}


(* ::Section::Closed:: *)
(*Integrands of the form (b Coth[c+d x]^m)^n*)


(* ::Subsection::Closed:: *)
(*Integrands of the form (b Coth[c+d x])^n*)


{(b*Coth[c + d*x])^n,x, 3, (Coth[c + d*x]*(b*Coth[c + d*x])^n*Hypergeometric2F1[1, (1 + n)/2, (3 + n)/2, Coth[c + d*x]^2])/(d*(1 + n))}

{(b*Coth[c + d*x])^(7/2),x, 6, (b^(7/2)*ArcTan[Sqrt[b*Coth[c + d*x]]/Sqrt[b]])/d + (b^(7/2)*ArcTanh[Sqrt[b*Coth[c + d*x]]/Sqrt[b]])/d - (2*b^3*Sqrt[b*Coth[c + d*x]])/d - (2*b*(b*Coth[c + d*x])^(5/2))/(5*d)}
{(b*Coth[c + d*x])^(5/2),x, 5, -((b^(5/2)*ArcTan[Sqrt[b*Coth[c + d*x]]/Sqrt[b]])/d) + (b^(5/2)*ArcTanh[Sqrt[b*Coth[c + d*x]]/Sqrt[b]])/d - (2*b*(b*Coth[c + d*x])^(3/2))/(3*d)}
{(b*Coth[c + d*x])^(3/2),x, 5, (b^(3/2)*ArcTan[Sqrt[b*Coth[c + d*x]]/Sqrt[b]])/d + (b^(3/2)*ArcTanh[Sqrt[b*Coth[c + d*x]]/Sqrt[b]])/d - (2*b*Sqrt[b*Coth[c + d*x]])/d}
{(b*Coth[c + d*x])^(1/2), x, 4, -((Sqrt[b]*ArcTan[Sqrt[b*Coth[c + d*x]]/Sqrt[b]])/d) + (Sqrt[b]*ArcTanh[Sqrt[b*Coth[c + d*x]]/Sqrt[b]])/d}
{1/(b*Coth[c + d*x])^(1/2), x, 4, ArcTan[Sqrt[b*Coth[c + d*x]]/Sqrt[b]]/(Sqrt[b]*d) + ArcTanh[Sqrt[b*Coth[c + d*x]]/Sqrt[b]]/(Sqrt[b]*d)}
{1/(b*Coth[c + d*x])^(3/2), x, 5, -(ArcTan[Sqrt[b*Coth[c + d*x]]/Sqrt[b]]/(b^(3/2)*d)) + ArcTanh[Sqrt[b*Coth[c + d*x]]/Sqrt[b]]/(b^(3/2)*d) - 2/(b*d*Sqrt[b*Coth[c + d*x]])}
{1/(b*Coth[c + d*x])^(5/2), x, 5, ArcTan[Sqrt[b*Coth[c + d*x]]/Sqrt[b]]/(b^(5/2)*d) + ArcTanh[Sqrt[b*Coth[c + d*x]]/Sqrt[b]]/(b^(5/2)*d) - 2/(3*b*d*(b*Coth[c + d*x])^(3/2))}
{1/(b*Coth[c + d*x])^(7/2), x, 6, -(ArcTan[Sqrt[b*Coth[c + d*x]]/Sqrt[b]]/(b^(7/2)*d)) + ArcTanh[Sqrt[b*Coth[c + d*x]]/Sqrt[b]]/(b^(7/2)*d) - 2/(5*b*d*(b*Coth[c + d*x])^(5/2)) - 2/(b^3*d*Sqrt[b*Coth[c + d*x]])}


{(b*Coth[c + d*x])^(4/3),x, 7, -((b^3*(Sqrt[3]*b^(2/3) + Sqrt[-b^(4/3)])*ArcTan[(Sqrt[2]*(b*Coth[c + d*x])^(1/3))/Sqrt[b^(2/3) - Sqrt[3]*Sqrt[-b^(4/3)]]])/(Sqrt[2]*(-b^(4/3))^(3/2)*Sqrt[b^(2/3) - Sqrt[3]*Sqrt[-b^(4/3)]]*d)) + (b^3*(Sqrt[3]*b^(2/3) - Sqrt[-b^(4/3)])*ArcTan[(Sqrt[2]*(b*Coth[c + d*x])^(1/3))/Sqrt[b^(2/3) + Sqrt[3]*Sqrt[-b^(4/3)]]])/(Sqrt[2]*(-b^(4/3))^(3/2)*Sqrt[b^(2/3) + Sqrt[3]*Sqrt[-b^(4/3)]]*d) + (b^(4/3)*ArcTanh[(b*Coth[c + d*x])^(1/3)/b^(1/3)])/d - (3*b*(b*Coth[c + d*x])^(1/3))/d}
{(b*Coth[c + d*x])^(2/3),x, 6, -((Sqrt[2]*b*ArcTan[(Sqrt[2]*(b*Coth[c + d*x])^(1/3))/Sqrt[b^(2/3) - Sqrt[3]*Sqrt[-b^(4/3)]]])/(Sqrt[b^(2/3) - Sqrt[3]*Sqrt[-b^(4/3)]]*d)) - (Sqrt[2]*b*ArcTan[(Sqrt[2]*(b*Coth[c + d*x])^(1/3))/Sqrt[b^(2/3) + Sqrt[3]*Sqrt[-b^(4/3)]]])/(Sqrt[b^(2/3) + Sqrt[3]*Sqrt[-b^(4/3)]]*d) + (b^(2/3)*ArcTanh[(b*Coth[c + d*x])^(1/3)/b^(1/3)])/d}
{(b*Coth[c + d*x])^(1/3), x, 7, -((Sqrt[3]*b^(1/3)*ArcTan[(b^(2/3) + 2*(b*Coth[c + d*x])^(2/3))/(Sqrt[3]*b^(2/3))])/(2*d)) - (b^(1/3)*Log[b^(2/3) - (b*Coth[c + d*x])^(2/3)])/(2*d) + (b^(1/3)*Log[b^(4/3) + b^(2/3)*(b*Coth[c + d*x])^(2/3) + (b*Coth[c + d*x])^(4/3)])/(4*d)}
{1/(b*Coth[c + d*x])^(1/3), x, 7, (Sqrt[3]*ArcTan[(b^(2/3) + 2*(b*Coth[c + d*x])^(2/3))/(Sqrt[3]*b^(2/3))])/(2*b^(1/3)*d) - Log[b^(2/3) - (b*Coth[c + d*x])^(2/3)]/(2*b^(1/3)*d) + Log[b^(4/3) + b^(2/3)*(b*Coth[c + d*x])^(2/3) + (b*Coth[c + d*x])^(4/3)]/(4*b^(1/3)*d)}
{1/(b*Coth[c + d*x])^(2/3), x, 6, -((b*(Sqrt[3]*b^(2/3) + Sqrt[-b^(4/3)])*ArcTan[(Sqrt[2]*(b*Coth[c + d*x])^(1/3))/Sqrt[b^(2/3) - Sqrt[3]*Sqrt[-b^(4/3)]]])/(Sqrt[2]*(-b^(4/3))^(3/2)*Sqrt[b^(2/3) - Sqrt[3]*Sqrt[-b^(4/3)]]*d)) + (b*(Sqrt[3]*b^(2/3) - Sqrt[-b^(4/3)])*ArcTan[(Sqrt[2]*(b*Coth[c + d*x])^(1/3))/Sqrt[b^(2/3) + Sqrt[3]*Sqrt[-b^(4/3)]]])/(Sqrt[2]*(-b^(4/3))^(3/2)*Sqrt[b^(2/3) + Sqrt[3]*Sqrt[-b^(4/3)]]*d) + ArcTanh[(b*Coth[c + d*x])^(1/3)/b^(1/3)]/(b^(2/3)*d)}
{1/(b*Coth[c + d*x])^(4/3), x, 7, -((Sqrt[2]*ArcTan[(Sqrt[2]*(b*Coth[c + d*x])^(1/3))/Sqrt[b^(2/3) - Sqrt[3]*Sqrt[-b^(4/3)]]])/(b*Sqrt[b^(2/3) - Sqrt[3]*Sqrt[-b^(4/3)]]*d)) - (Sqrt[2]*ArcTan[(Sqrt[2]*(b*Coth[c + d*x])^(1/3))/Sqrt[b^(2/3) + Sqrt[3]*Sqrt[-b^(4/3)]]])/(b*Sqrt[b^(2/3) + Sqrt[3]*Sqrt[-b^(4/3)]]*d) + ArcTanh[(b*Coth[c + d*x])^(1/3)/b^(1/3)]/(b^(4/3)*d) - 3/(b*d*(b*Coth[c + d*x])^(1/3))}


(* ::Subsection::Closed:: *)
(*Integrands of the form (b Coth[c+d x]^2)^n*)


{(b*Coth[c + d*x]^2)^n,x, 3, (Coth[c + d*x]*(b*Coth[c + d*x]^2)^n*Hypergeometric2F1[1, (1/2)*(1 + 2*n), (1/2)*(3 + 2*n), Coth[c + d*x]^2])/(d*(1 + 2*n))}

{(b*Coth[c + d*x]^2)^(3/2),x, 3, -((b*Coth[c + d*x]*Sqrt[b*Coth[c + d*x]^2])/(2*d)) + (b*Sqrt[b*Coth[c + d*x]^2]*Log[Sinh[c + d*x]]*Tanh[c + d*x])/d}
{(b*Coth[c + d*x]^2)^(1/2), x, 2, (Sqrt[b*Coth[c + d*x]^2]*Log[Sinh[c + d*x]]*Tanh[c + d*x])/d}
{1/(b*Coth[c + d*x]^2)^(1/2), x, 2, (Coth[c + d*x]*Log[Cosh[c + d*x]])/(d*Sqrt[b*Coth[c + d*x]^2])}
{1/(b*Coth[c + d*x]^2)^(3/2), x, 3, (Coth[c + d*x]*Log[Cosh[c + d*x]])/(b*d*Sqrt[b*Coth[c + d*x]^2]) - Tanh[c + d*x]/(2*b*d*Sqrt[b*Coth[c + d*x]^2])}


{(b*Coth[c + d*x]^2)^(4/3),x, 10, (Sqrt[3]*ArcTan[(1 - 2*Coth[c + d*x]^(1/3))/Sqrt[3]]*(b*Coth[c + d*x]^2)^(4/3))/(2*d*Coth[c + d*x]^(8/3)) - (Sqrt[3]*ArcTan[(1 + 2*Coth[c + d*x]^(1/3))/Sqrt[3]]*(b*Coth[c + d*x]^2)^(4/3))/(2*d*Coth[c + d*x]^(8/3)) + (ArcTanh[Coth[c + d*x]^(1/3)]*(b*Coth[c + d*x]^2)^(4/3))/(d*Coth[c + d*x]^(8/3)) + (ArcTanh[Coth[c + d*x]^(1/3)/(1 + Coth[c + d*x]^(2/3))]*(b*Coth[c + d*x]^2)^(4/3))/(2*d*Coth[c + d*x]^(8/3)) - (3*(b*Coth[c + d*x]^2)^(4/3)*Tanh[c + d*x])/(5*d)}
{(b*Coth[c + d*x]^2)^(2/3),x, 10, -((Sqrt[3]*ArcTan[(1 - 2*Coth[c + d*x]^(1/3))/Sqrt[3]]*(b*Coth[c + d*x]^2)^(2/3))/(2*d*Coth[c + d*x]^(4/3))) + (Sqrt[3]*ArcTan[(1 + 2*Coth[c + d*x]^(1/3))/Sqrt[3]]*(b*Coth[c + d*x]^2)^(2/3))/(2*d*Coth[c + d*x]^(4/3)) + (ArcTanh[Coth[c + d*x]^(1/3)]*(b*Coth[c + d*x]^2)^(2/3))/(d*Coth[c + d*x]^(4/3)) + (ArcTanh[Coth[c + d*x]^(1/3)/(1 + Coth[c + d*x]^(2/3))]*(b*Coth[c + d*x]^2)^(2/3))/(2*d*Coth[c + d*x]^(4/3)) - (3*(b*Coth[c + d*x]^2)^(2/3)*Tanh[c + d*x])/d}
{(b*Coth[c + d*x]^2)^(1/3), x, 9, (Sqrt[3]*ArcTan[(1 - 2*Coth[c + d*x]^(1/3))/Sqrt[3]]*(b*Coth[c + d*x]^2)^(1/3))/(2*d*Coth[c + d*x]^(2/3)) - (Sqrt[3]*ArcTan[(1 + 2*Coth[c + d*x]^(1/3))/Sqrt[3]]*(b*Coth[c + d*x]^2)^(1/3))/(2*d*Coth[c + d*x]^(2/3)) + (ArcTanh[Coth[c + d*x]^(1/3)]*(b*Coth[c + d*x]^2)^(1/3))/(d*Coth[c + d*x]^(2/3)) + (ArcTanh[Coth[c + d*x]^(1/3)/(1 + Coth[c + d*x]^(2/3))]*(b*Coth[c + d*x]^2)^(1/3))/(2*d*Coth[c + d*x]^(2/3))}
{1/(b*Coth[c + d*x]^2)^(1/3), x, 9, -((Sqrt[3]*ArcTan[(1 - 2*Coth[c + d*x]^(1/3))/Sqrt[3]]*Coth[c + d*x]^(2/3))/(2*d*(b*Coth[c + d*x]^2)^(1/3))) + (Sqrt[3]*ArcTan[(1 + 2*Coth[c + d*x]^(1/3))/Sqrt[3]]*Coth[c + d*x]^(2/3))/(2*d*(b*Coth[c + d*x]^2)^(1/3)) + (ArcTanh[Coth[c + d*x]^(1/3)]*Coth[c + d*x]^(2/3))/(d*(b*Coth[c + d*x]^2)^(1/3)) + (ArcTanh[Coth[c + d*x]^(1/3)/(1 + Coth[c + d*x]^(2/3))]*Coth[c + d*x]^(2/3))/(2*d*(b*Coth[c + d*x]^2)^(1/3))}
{1/(b*Coth[c + d*x]^2)^(2/3), x, 10, -((3*Coth[c + d*x])/(d*(b*Coth[c + d*x]^2)^(2/3))) + (Sqrt[3]*ArcTan[(1 - 2*Coth[c + d*x]^(1/3))/Sqrt[3]]*Coth[c + d*x]^(4/3))/(2*d*(b*Coth[c + d*x]^2)^(2/3)) - (Sqrt[3]*ArcTan[(1 + 2*Coth[c + d*x]^(1/3))/Sqrt[3]]*Coth[c + d*x]^(4/3))/(2*d*(b*Coth[c + d*x]^2)^(2/3)) + (ArcTanh[Coth[c + d*x]^(1/3)]*Coth[c + d*x]^(4/3))/(d*(b*Coth[c + d*x]^2)^(2/3)) + (ArcTanh[Coth[c + d*x]^(1/3)/(1 + Coth[c + d*x]^(2/3))]*Coth[c + d*x]^(4/3))/(2*d*(b*Coth[c + d*x]^2)^(2/3))}
{1/(b*Coth[c + d*x]^2)^(4/3), x, 10, -((3*Coth[c + d*x])/(5*d*(b*Coth[c + d*x]^2)^(4/3))) - (Sqrt[3]*ArcTan[(1 - 2*Coth[c + d*x]^(1/3))/Sqrt[3]]*Coth[c + d*x]^(8/3))/(2*d*(b*Coth[c + d*x]^2)^(4/3)) + (Sqrt[3]*ArcTan[(1 + 2*Coth[c + d*x]^(1/3))/Sqrt[3]]*Coth[c + d*x]^(8/3))/(2*d*(b*Coth[c + d*x]^2)^(4/3)) + (ArcTanh[Coth[c + d*x]^(1/3)]*Coth[c + d*x]^(8/3))/(d*(b*Coth[c + d*x]^2)^(4/3)) + (ArcTanh[Coth[c + d*x]^(1/3)/(1 + Coth[c + d*x]^(2/3))]*Coth[c + d*x]^(8/3))/(2*d*(b*Coth[c + d*x]^2)^(4/3))}


(* ::Subsection::Closed:: *)
(*Integrands of the form (b Coth[c+d x]^3)^n*)


{(b*Coth[c + d*x]^3)^n,x, 3, (Coth[c + d*x]*(b*Coth[c + d*x]^3)^n*Hypergeometric2F1[1, (1/2)*(1 + 3*n), (3*(1 + n))/2, Coth[c + d*x]^2])/(d*(1 + 3*n))}

{(b*Coth[c + d*x]^3)^(3/2),x, 7, -((2*b*Sqrt[b*Coth[c + d*x]^3])/(3*d)) - (b*ArcTan[Sqrt[Coth[c + d*x]]]*Sqrt[b*Coth[c + d*x]^3])/(d*Coth[c + d*x]^(3/2)) + (b*ArcTanh[Sqrt[Coth[c + d*x]]]*Sqrt[b*Coth[c + d*x]^3])/(d*Coth[c + d*x]^(3/2)) - (2*b*Coth[c + d*x]^2*Sqrt[b*Coth[c + d*x]^3])/(7*d)}
{(b*Coth[c + d*x]^3)^(1/2), x, 6, (ArcTan[Sqrt[Coth[c + d*x]]]*Sqrt[b*Coth[c + d*x]^3])/(d*Coth[c + d*x]^(3/2)) + (ArcTanh[Sqrt[Coth[c + d*x]]]*Sqrt[b*Coth[c + d*x]^3])/(d*Coth[c + d*x]^(3/2)) - (2*Sqrt[b*Coth[c + d*x]^3]*Tanh[c + d*x])/d}
{1/(b*Coth[c + d*x]^3)^(1/2), x, 6, -((2*Coth[c + d*x])/(d*Sqrt[b*Coth[c + d*x]^3])) - (ArcTan[Sqrt[Coth[c + d*x]]]*Coth[c + d*x]^(3/2))/(d*Sqrt[b*Coth[c + d*x]^3]) + (ArcTanh[Sqrt[Coth[c + d*x]]]*Coth[c + d*x]^(3/2))/(d*Sqrt[b*Coth[c + d*x]^3])}
{1/(b*Coth[c + d*x]^3)^(3/2), x, 7, -(2/(3*b*d*Sqrt[b*Coth[c + d*x]^3])) + (ArcTan[Sqrt[Coth[c + d*x]]]*Coth[c + d*x]^(3/2))/(b*d*Sqrt[b*Coth[c + d*x]^3]) + (ArcTanh[Sqrt[Coth[c + d*x]]]*Coth[c + d*x]^(3/2))/(b*d*Sqrt[b*Coth[c + d*x]^3]) - (2*Tanh[c + d*x]^2)/(7*b*d*Sqrt[b*Coth[c + d*x]^3])}


{(b*Coth[c + d*x]^3)^(4/3),x, 4, -(((b*Coth[c + d*x]^3)^(4/3)*Tanh[c + d*x])/(3*d)) - ((b*Coth[c + d*x]^3)^(4/3)*Tanh[c + d*x]^3)/d + x*(b*Coth[c + d*x]^3)^(4/3)*Tanh[c + d*x]^4}
{(b*Coth[c + d*x]^3)^(2/3),x, 3, -(((b*Coth[c + d*x]^3)^(2/3)*Tanh[c + d*x])/d) + x*(b*Coth[c + d*x]^3)^(2/3)*Tanh[c + d*x]^2}
{(b*Coth[c + d*x]^3)^(1/3), x, 2, ((b*Coth[c + d*x]^3)^(1/3)*Log[Sinh[c + d*x]]*Tanh[c + d*x])/d}
{1/(b*Coth[c + d*x]^3)^(1/3), x, 2, (Coth[c + d*x]*Log[Cosh[c + d*x]])/(d*(b*Coth[c + d*x]^3)^(1/3))}
{1/(b*Coth[c + d*x]^3)^(2/3), x, 3, -(Coth[c + d*x]/(d*(b*Coth[c + d*x]^3)^(2/3))) + (x*Coth[c + d*x]^2)/(b*Coth[c + d*x]^3)^(2/3)}
{1/(b*Coth[c + d*x]^3)^(4/3), x, 4, -(Coth[c + d*x]/(3*d*(b*Coth[c + d*x]^3)^(4/3))) - Coth[c + d*x]^3/(d*(b*Coth[c + d*x]^3)^(4/3)) + (x*Coth[c + d*x]^4)/(b*Coth[c + d*x]^3)^(4/3)}


(* ::Subsection::Closed:: *)
(*Integrands of the form (b Coth[c+d x]^4)^n*)


{(b*Coth[c + d*x]^4)^n,x, 3, (Coth[c + d*x]*(b*Coth[c + d*x]^4)^n*Hypergeometric2F1[1, (1/2)*(1 + 4*n), (1/2)*(3 + 4*n), Coth[c + d*x]^2])/(d*(1 + 4*n))}

{(b*Coth[c + d*x]^4)^(3/2),x, 5, -((b*Coth[c + d*x]*Sqrt[b*Coth[c + d*x]^4])/(3*d)) - (b*Coth[c + d*x]^3*Sqrt[b*Coth[c + d*x]^4])/(5*d) - (b*Sqrt[b*Coth[c + d*x]^4]*Tanh[c + d*x])/d + b*x*Sqrt[b*Coth[c + d*x]^4]*Tanh[c + d*x]^2}
{(b*Coth[c + d*x]^4)^(1/2), x, 3, -((Sqrt[b*Coth[c + d*x]^4]*Tanh[c + d*x])/d) + x*Sqrt[b*Coth[c + d*x]^4]*Tanh[c + d*x]^2}
{1/(b*Coth[c + d*x]^4)^(1/2), x, 3, -(Coth[c + d*x]/(d*Sqrt[b*Coth[c + d*x]^4])) + (x*Coth[c + d*x]^2)/Sqrt[b*Coth[c + d*x]^4]}
{1/(b*Coth[c + d*x]^4)^(3/2), x, 5, -(Coth[c + d*x]/(b*d*Sqrt[b*Coth[c + d*x]^4])) + (x*Coth[c + d*x]^2)/(b*Sqrt[b*Coth[c + d*x]^4]) - Tanh[c + d*x]/(3*b*d*Sqrt[b*Coth[c + d*x]^4]) - Tanh[c + d*x]^3/(5*b*d*Sqrt[b*Coth[c + d*x]^4])}


{(b*Coth[c + d*x]^4)^(4/3),x, 12, -((Sqrt[3]*ArcTan[(1 - 2*Coth[c + d*x]^(1/3))/Sqrt[3]]*(b*Coth[c + d*x]^4)^(4/3))/(2*d*Coth[c + d*x]^(16/3))) + (Sqrt[3]*ArcTan[(1 + 2*Coth[c + d*x]^(1/3))/Sqrt[3]]*(b*Coth[c + d*x]^4)^(4/3))/(2*d*Coth[c + d*x]^(16/3)) + (ArcTanh[Coth[c + d*x]^(1/3)]*(b*Coth[c + d*x]^4)^(4/3))/(d*Coth[c + d*x]^(16/3)) + (ArcTanh[Coth[c + d*x]^(1/3)/(1 + Coth[c + d*x]^(2/3))]*(b*Coth[c + d*x]^4)^(4/3))/(2*d*Coth[c + d*x]^(16/3)) - (3*(b*Coth[c + d*x]^4)^(4/3)*Tanh[c + d*x])/(13*d) - (3*(b*Coth[c + d*x]^4)^(4/3)*Tanh[c + d*x]^3)/(7*d) - (3*(b*Coth[c + d*x]^4)^(4/3)*Tanh[c + d*x]^5)/d}
{(b*Coth[c + d*x]^4)^(2/3),x, 10, (Sqrt[3]*ArcTan[(1 - 2*Coth[c + d*x]^(1/3))/Sqrt[3]]*(b*Coth[c + d*x]^4)^(2/3))/(2*d*Coth[c + d*x]^(8/3)) - (Sqrt[3]*ArcTan[(1 + 2*Coth[c + d*x]^(1/3))/Sqrt[3]]*(b*Coth[c + d*x]^4)^(2/3))/(2*d*Coth[c + d*x]^(8/3)) + (ArcTanh[Coth[c + d*x]^(1/3)]*(b*Coth[c + d*x]^4)^(2/3))/(d*Coth[c + d*x]^(8/3)) + (ArcTanh[Coth[c + d*x]^(1/3)/(1 + Coth[c + d*x]^(2/3))]*(b*Coth[c + d*x]^4)^(2/3))/(2*d*Coth[c + d*x]^(8/3)) - (3*(b*Coth[c + d*x]^4)^(2/3)*Tanh[c + d*x])/(5*d)}
{(b*Coth[c + d*x]^4)^(1/3), x, 10, -((Sqrt[3]*ArcTan[(1 - 2*Coth[c + d*x]^(1/3))/Sqrt[3]]*(b*Coth[c + d*x]^4)^(1/3))/(2*d*Coth[c + d*x]^(4/3))) + (Sqrt[3]*ArcTan[(1 + 2*Coth[c + d*x]^(1/3))/Sqrt[3]]*(b*Coth[c + d*x]^4)^(1/3))/(2*d*Coth[c + d*x]^(4/3)) + (ArcTanh[Coth[c + d*x]^(1/3)]*(b*Coth[c + d*x]^4)^(1/3))/(d*Coth[c + d*x]^(4/3)) + (ArcTanh[Coth[c + d*x]^(1/3)/(1 + Coth[c + d*x]^(2/3))]*(b*Coth[c + d*x]^4)^(1/3))/(2*d*Coth[c + d*x]^(4/3)) - (3*(b*Coth[c + d*x]^4)^(1/3)*Tanh[c + d*x])/d}
{1/(b*Coth[c + d*x]^4)^(1/3), x, 10, -((3*Coth[c + d*x])/(d*(b*Coth[c + d*x]^4)^(1/3))) + (Sqrt[3]*ArcTan[(1 - 2*Coth[c + d*x]^(1/3))/Sqrt[3]]*Coth[c + d*x]^(4/3))/(2*d*(b*Coth[c + d*x]^4)^(1/3)) - (Sqrt[3]*ArcTan[(1 + 2*Coth[c + d*x]^(1/3))/Sqrt[3]]*Coth[c + d*x]^(4/3))/(2*d*(b*Coth[c + d*x]^4)^(1/3)) + (ArcTanh[Coth[c + d*x]^(1/3)]*Coth[c + d*x]^(4/3))/(d*(b*Coth[c + d*x]^4)^(1/3)) + (ArcTanh[Coth[c + d*x]^(1/3)/(1 + Coth[c + d*x]^(2/3))]*Coth[c + d*x]^(4/3))/(2*d*(b*Coth[c + d*x]^4)^(1/3))}
{1/(b*Coth[c + d*x]^4)^(2/3), x, 10, -((3*Coth[c + d*x])/(5*d*(b*Coth[c + d*x]^4)^(2/3))) - (Sqrt[3]*ArcTan[(1 - 2*Coth[c + d*x]^(1/3))/Sqrt[3]]*Coth[c + d*x]^(8/3))/(2*d*(b*Coth[c + d*x]^4)^(2/3)) + (Sqrt[3]*ArcTan[(1 + 2*Coth[c + d*x]^(1/3))/Sqrt[3]]*Coth[c + d*x]^(8/3))/(2*d*(b*Coth[c + d*x]^4)^(2/3)) + (ArcTanh[Coth[c + d*x]^(1/3)]*Coth[c + d*x]^(8/3))/(d*(b*Coth[c + d*x]^4)^(2/3)) + (ArcTanh[Coth[c + d*x]^(1/3)/(1 + Coth[c + d*x]^(2/3))]*Coth[c + d*x]^(8/3))/(2*d*(b*Coth[c + d*x]^4)^(2/3))}
{1/(b*Coth[c + d*x]^4)^(4/3), x, 12, -((3*Coth[c + d*x])/(13*d*(b*Coth[c + d*x]^4)^(4/3))) - (3*Coth[c + d*x]^3)/(7*d*(b*Coth[c + d*x]^4)^(4/3)) - (3*Coth[c + d*x]^5)/(d*(b*Coth[c + d*x]^4)^(4/3)) + (Sqrt[3]*ArcTan[(1 - 2*Coth[c + d*x]^(1/3))/Sqrt[3]]*Coth[c + d*x]^(16/3))/(2*d*(b*Coth[c + d*x]^4)^(4/3)) - (Sqrt[3]*ArcTan[(1 + 2*Coth[c + d*x]^(1/3))/Sqrt[3]]*Coth[c + d*x]^(16/3))/(2*d*(b*Coth[c + d*x]^4)^(4/3)) + (ArcTanh[Coth[c + d*x]^(1/3)]*Coth[c + d*x]^(16/3))/(d*(b*Coth[c + d*x]^4)^(4/3)) + (ArcTanh[Coth[c + d*x]^(1/3)/(1 + Coth[c + d*x]^(2/3))]*Coth[c + d*x]^(16/3))/(2*d*(b*Coth[c + d*x]^4)^(4/3))}


(* ::Subsection::Closed:: *)
(*Integrands of the form (b Coth[c+d x]^m)^n*)


{(b*Coth[c + d*x]^m)^n,x, 3, (Coth[c + d*x]*(b*Coth[c + d*x]^m)^n*Hypergeometric2F1[1, (1/2)*(1 + m*n), (1/2)*(3 + m*n), Coth[c + d*x]^2])/(d*(1 + m*n))}

{(b*Coth[c + d*x]^m)^(3/2),x, 3, (2*b*Coth[c + d*x]^(1 + m)*Sqrt[b*Coth[c + d*x]^m]*Hypergeometric2F1[1, (1/4)*(2 + 3*m), (3*(2 + m))/4, Coth[c + d*x]^2])/(d*(2 + 3*m))}
{(b*Coth[c + d*x]^m)^(1/2), x, 3, (2*Coth[c + d*x]*Sqrt[b*Coth[c + d*x]^m]*Hypergeometric2F1[1, (2 + m)/4, (6 + m)/4, Coth[c + d*x]^2])/(d*(2 + m))}
{1/(b*Coth[c + d*x]^m)^(1/2), x, 3, (2*Coth[c + d*x]*Hypergeometric2F1[1, (2 - m)/4, (6 - m)/4, Coth[c + d*x]^2])/(d*(2 - m)*Sqrt[b*Coth[c + d*x]^m])}
{1/(b*Coth[c + d*x]^m)^(3/2), x, 3, (2*Coth[c + d*x]^(1 - m)*Hypergeometric2F1[1, (1/4)*(2 - 3*m), (3*(2 - m))/4, Coth[c + d*x]^2])/(b*d*(2 - 3*m)*Sqrt[b*Coth[c + d*x]^m])}


{(b*Coth[c + d*x]^m)^(4/3),x, 3, (3*Coth[c + d*x]*(b*Coth[c + d*x]^m)^(4/3)*Hypergeometric2F1[1, (1/6)*(3 + 4*m), (1/6)*(9 + 4*m), Coth[c + d*x]^2])/(d*(3 + 4*m))}
{(b*Coth[c + d*x]^m)^(2/3),x, 3, (3*Coth[c + d*x]*(b*Coth[c + d*x]^m)^(2/3)*Hypergeometric2F1[1, (1/6)*(3 + 2*m), (1/6)*(9 + 2*m), Coth[c + d*x]^2])/(d*(3 + 2*m))}
{(b*Coth[c + d*x]^m)^(1/3), x, 3, (3*Coth[c + d*x]*(b*Coth[c + d*x]^m)^(1/3)*Hypergeometric2F1[1, (3 + m)/6, (9 + m)/6, Coth[c + d*x]^2])/(d*(3 + m))}
{1/(b*Coth[c + d*x]^m)^(1/3), x, 3, (3*Coth[c + d*x]*Hypergeometric2F1[1, (3 - m)/6, (9 - m)/6, Coth[c + d*x]^2])/(d*(3 - m)*(b*Coth[c + d*x]^m)^(1/3))}
{1/(b*Coth[c + d*x]^m)^(2/3), x, 3, (3*Coth[c + d*x]*Hypergeometric2F1[1, (1/6)*(3 - 2*m), (1/6)*(9 - 2*m), Coth[c + d*x]^2])/(d*(3 - 2*m)*(b*Coth[c + d*x]^m)^(2/3))}
{1/(b*Coth[c + d*x]^m)^(4/3), x, 3, (3*Coth[c + d*x]*Hypergeometric2F1[1, (1/6)*(3 - 4*m), (1/6)*(9 - 4*m), Coth[c + d*x]^2])/(d*(3 - 4*m)*(b*Coth[c + d*x]^m)^(4/3))}


(* ::Section::Closed:: *)
(*Integrands of the form Hyper[c+d x]^m (a+b Coth[c+d x])^n*)


(* ::Subsection::Closed:: *)
(*Integrands of the form Sinh[c+d x]^m (a+b Coth[c+d x])^n*)


(* ::Subsubsection::Closed:: *)
(*a^2-b^2 = 0*)


{(1 + Coth[x])^5, x, 5, 16*x - 8*Coth[x] - 2*(1 + Coth[x])^2 - (2/3)*(1 + Coth[x])^3 - (1/4)*(1 + Coth[x])^4 + 16*Log[Sinh[x]]}
{(1 + Coth[x])^4, x, 4, 8*x - 4*Coth[x] - (1 + Coth[x])^2 - (1/3)*(1 + Coth[x])^3 + 8*Log[Sinh[x]]}
{(1 + Coth[x])^3, x, 3, 4*x - 2*Coth[x] - (1/2)*(1 + Coth[x])^2 + 4*Log[Sinh[x]]}
{(1 + Coth[x])^2, x, 2, 2*x - Coth[x] + 2*Log[Sinh[x]]}
{1/(1 + Coth[x]), x, 2, x/2 - 1/(2*(1 + Coth[x]))}
{1/(1 + Coth[x])^2, x, 3, x/4 - 1/(4*(1 + Coth[x])^2) - 1/(4*(1 + Coth[x]))}
{1/(1 + Coth[x])^3, x, 4, x/8 - 1/(6*(1 + Coth[x])^3) - 1/(8*(1 + Coth[x])^2) - 1/(8*(1 + Coth[x]))}
{1/(1 + Coth[x])^4, x, 5, x/16 - 1/(8*(1 + Coth[x])^4) - 1/(12*(1 + Coth[x])^3) - 1/(16*(1 + Coth[x])^2) - 1/(16*(1 + Coth[x]))}
{1/(1 + Coth[x])^5, x, 6, x/32 - 1/(10*(1 + Coth[x])^5) - 1/(16*(1 + Coth[x])^4) - 1/(24*(1 + Coth[x])^3) - 1/(32*(1 + Coth[x])^2) - 1/(32*(1 + Coth[x]))}


{(1 + Coth[x])^(7/2), x, 5, 8*Sqrt[2]*ArcTanh[Sqrt[1 + Coth[x]]/Sqrt[2]] - 8*Sqrt[1 + Coth[x]] - (4/3)*(1 + Coth[x])^(3/2) - (2/5)*(1 + Coth[x])^(5/2)}
{(1 + Coth[x])^(5/2), x, 4, 4*Sqrt[2]*ArcTanh[Sqrt[1 + Coth[x]]/Sqrt[2]] - 4*Sqrt[1 + Coth[x]] - (2/3)*(1 + Coth[x])^(3/2)}
{(1 + Coth[x])^(3/2), x, 3, 2*Sqrt[2]*ArcTanh[Sqrt[1 + Coth[x]]/Sqrt[2]] - 2*Sqrt[1 + Coth[x]]}
{(1 + Coth[x])^(1/2), x, 2, Sqrt[2]*ArcTanh[Sqrt[1 + Coth[x]]/Sqrt[2]]}
{1/(1 + Coth[x])^(1/2), x, 3, ArcTanh[Sqrt[1 + Coth[x]]/Sqrt[2]]/Sqrt[2] - 1/Sqrt[1 + Coth[x]]}
{1/(1 + Coth[x])^(3/2), x, 4, ArcTanh[Sqrt[1 + Coth[x]]/Sqrt[2]]/(2*Sqrt[2]) - 1/(3*(1 + Coth[x])^(3/2)) - 1/(2*Sqrt[1 + Coth[x]])}
{1/(1 + Coth[x])^(5/2), x, 5, ArcTanh[Sqrt[1 + Coth[x]]/Sqrt[2]]/(4*Sqrt[2]) - 1/(5*(1 + Coth[x])^(5/2)) - 1/(6*(1 + Coth[x])^(3/2)) - 1/(4*Sqrt[1 + Coth[x]])}


{Sinh[x]^4/(1 + Coth[x]), x, 5, (5*x)/16 + 1/(32*(1 - Coth[x])^2) + 1/(8*(1 - Coth[x])) - 1/(24*(1 + Coth[x])^3) - 3/(32*(1 + Coth[x])^2) - 3/(16*(1 + Coth[x]))}
{Sinh[x]^3/(1 + Coth[x]), x, 7, -Cosh[x] + (2*Cosh[x]^3)/3 - Cosh[x]^5/5 + Sinh[x]^5/5}
{Sinh[x]^2/(1 + Coth[x]), x, 5, -((3*x)/8) - 1/(8*(1 - Coth[x])) + 1/(8*(1 + Coth[x])^2) + 1/(4*(1 + Coth[x]))}
{Sinh[x]^1/(1 + Coth[x]), x, 7, Cosh[x] - Cosh[x]^3/3 + Sinh[x]^3/3}
{Csch[x]^1/(1 + Coth[x]), x, 2, -(1/(Cosh[x] + Sinh[x]))}
{Csch[x]^2/(1 + Coth[x]), x, 2, -Log[1 + Coth[x]]}
{Csch[x]^3/(1 + Coth[x]), x, 6, ArcTanh[Cosh[x]] - Csch[x]}
{Csch[x]^4/(1 + Coth[x]), x, 3, Coth[x] - Coth[x]^2/2}


(* ::Subsubsection::Closed:: *)
(*a^2-b^2 /= 0*)


{(a + b*Coth[c + d*x])^5, x, 6, a*(a^4 + 10*a^2*b^2 + 5*b^4)*x - (4*a*b*(a^2 + b^2)*(a + b*Coth[c + d*x]))/d - (b*(3*a^2 + b^2)*(a + b*Coth[c + d*x])^2)/(2*d) - (2*a*b*(a + b*Coth[c + d*x])^3)/(3*d) - (b*(a + b*Coth[c + d*x])^4)/(4*d) + (b*(5*a^4 + 10*a^2*b^2 + b^4)*Log[Sinh[c + d*x]])/d}
{(a + b*Coth[c + d*x])^4, x, 5, (a^4 + 6*a^2*b^2 + b^4)*x - (b*(3*a^2 + b^2)*(a + b*Coth[c + d*x]))/d - (a*b*(a + b*Coth[c + d*x])^2)/d - (b*(a + b*Coth[c + d*x])^3)/(3*d) + (4*a*b*(a^2 + b^2)*Log[Sinh[c + d*x]])/d}
{(a + b*Coth[c + d*x])^3, x, 4, a*(a^2 + 3*b^2)*x - (2*a*b*(a + b*Coth[c + d*x]))/d - (b*(a + b*Coth[c + d*x])^2)/(2*d) + (b*(3*a^2 + b^2)*Log[Sinh[c + d*x]])/d}
{(a + b*Coth[c + d*x])^2, x, 2, (a^2 + b^2)*x - (b^2*Coth[c + d*x])/d + (2*a*b*Log[Sinh[c + d*x]])/d}
{1/(a + b*Coth[c + d*x]),x, 3, (a*x)/(a^2 - b^2) - (b*Log[a + b*Coth[c + d*x]])/((a^2 - b^2)*d) - (b*Log[Sinh[c + d*x]])/((a^2 - b^2)*d)}
{1/(a + b*Coth[c + d*x])^2,x, 5, ((a^2 + b^2)*x)/(a^2 - b^2)^2 + b/((a^2 - b^2)*d*(a + b*Coth[c + d*x])) - (2*a*b*Log[a + b*Coth[c + d*x]])/((a^2 - b^2)^2*d) - (2*a*b*Log[Sinh[c + d*x]])/((a^2 - b^2)^2*d)}
{1/(a + b*Coth[c + d*x])^3,x, 6, (a*(a^2 + 3*b^2)*x)/(a^2 - b^2)^3 + b/(2*(a^2 - b^2)*d*(a + b*Coth[c + d*x])^2) + (2*a*b)/((a^2 - b^2)^2*d*(a + b*Coth[c + d*x])) - (b*(3*a^2 + b^2)*Log[a + b*Coth[c + d*x]])/((a^2 - b^2)^3*d) - (b*(3*a^2 + b^2)*Log[Sinh[c + d*x]])/((a^2 - b^2)^3*d)}
{1/(a + b*Coth[c + d*x])^4,x, 7, ((a^4 + 6*a^2*b^2 + b^4)*x)/(a^2 - b^2)^4 + b/(3*(a^2 - b^2)*d*(a + b*Coth[c + d*x])^3) + (a*b)/((a^2 - b^2)^2*d*(a + b*Coth[c + d*x])^2) + (b*(3*a^2 + b^2))/((a^2 - b^2)^3*d*(a + b*Coth[c + d*x])) - (4*a*b*(a^2 + b^2)*Log[a + b*Coth[c + d*x]])/((a^2 - b^2)^4*d) - (4*a*b*(a^2 + b^2)*Log[Sinh[c + d*x]])/((a^2 - b^2)^4*d)}

{1/(4 + 6*Coth[c + d*x]), x, 3, -(x/5) + (3*Log[2 + 3*Coth[c + d*x]])/(10*d) + (3*Log[Sinh[c + d*x]])/(10*d)}
{1/(4 - 6*Coth[c + d*x]), x, 3, -(x/5) - (3*Log[2 - 3*Coth[c + d*x]])/(10*d) - (3*Log[Sinh[c + d*x]])/(10*d)}


{Sqrt[a + b*Coth[c + d*x]], x, 5, -((Sqrt[a - b]*ArcTanh[Sqrt[a + b*Coth[c + d*x]]/Sqrt[a - b]])/d) + (Sqrt[a + b]*ArcTanh[Sqrt[a + b*Coth[c + d*x]]/Sqrt[a + b]])/d}
{1/Sqrt[a + b*Coth[c + d*x]], x, 5, -(ArcTanh[Sqrt[a + b*Coth[c + d*x]]/Sqrt[a - b]]/(Sqrt[a - b]*d)) + ArcTanh[Sqrt[a + b*Coth[c + d*x]]/Sqrt[a + b]]/(Sqrt[a + b]*d)}


{Sinh[x]^4/(a + b*Coth[x]), x, 8, (a*(3*a^4 - 10*a^2*b^2 + 15*b^4)*x)/(8*(a^2 - b^2)^3) - (b - a*Coth[x])/(4*(a^2 - b^2)*(1 - Coth[x]^2)^2) + (4*b^3 + a*(3*a^2 - 7*b^2)*Coth[x])/(8*(a^2 - b^2)^2*(1 - Coth[x]^2)) - (b^5*Log[a + b*Coth[x]])/(a^2 - b^2)^3 + (b^5*Log[1 - Coth[x]^2])/(2*(a^2 - b^2)^3)}
{Sinh[x]^3/(a + b*Coth[x]), x, 8, -((b^4*ArcTanh[(a*Cosh[x] + b*Sinh[x])/Sqrt[a^2 - b^2]])/(a^2 - b^2)^(5/2)) + (a*b^2*Cosh[x])/(a^2 - b^2)^2 - (a*Cosh[x])/(a^2 - b^2) + (a*Cosh[x]^3)/(3*(a^2 - b^2)) - (b^3*Sinh[x])/(a^2 - b^2)^2 - (b*Sinh[x]^3)/(3*(a^2 - b^2))}
{Sinh[x]^2/(a + b*Coth[x]), x, 7, -((a*(a^2 - 3*b^2)*x)/(2*(a^2 - b^2)^2)) + (b - a*Coth[x])/(2*(a^2 - b^2)*(1 - Coth[x]^2)) - (b^3*Log[a + b*Coth[x]])/(a^2 - b^2)^2 + (b^3*Log[1 - Coth[x]^2])/(2*(a^2 - b^2)^2)}
{Sinh[x]^1/(a + b*Coth[x]), x, 5, -((b^2*ArcTanh[(a*Cosh[x] + b*Sinh[x])/Sqrt[a^2 - b^2]])/(a^2 - b^2)^(3/2)) + (a*Cosh[x])/(a^2 - b^2) - (b*Sinh[x])/(a^2 - b^2)}
{Csch[x]^1/(a + b*Coth[x]), x, 3, -(ArcTanh[(a*Cosh[x] + b*Sinh[x])/Sqrt[a^2 - b^2]]/Sqrt[a^2 - b^2])}
{Csch[x]^2/(a + b*Coth[x]), x, 2, -(Log[a + b*Coth[x]]/b)}
{Csch[x]^3/(a + b*Coth[x]), x, 5, (a*ArcTanh[Cosh[x]])/b^2 - (Sqrt[a^2 - b^2]*ArcTanh[(a*Cosh[x] + b*Sinh[x])/Sqrt[a^2 - b^2]])/b^2 - Csch[x]/b}
{Csch[x]^4/(a + b*Coth[x]), x, 3, (a*Coth[x])/b^2 - Coth[x]^2/(2*b) - ((a^2 - b^2)*Log[a + b*Coth[x]])/b^3}


(* ::Subsection::Closed:: *)
(*Integrands of the form Cosh[c+d x]^m (a+b Coth[c+d x])^n*)


{Cosh[x]^4/(a + b*Coth[x]), x, 3, 1/(16*(a + b)*(1 - Coth[x])^2) - (5*a + 3*b)/(16*(a + b)^2*(1 - Coth[x])) - 1/(16*(a - b)*(1 + Coth[x])^2) + (5*a - 3*b)/(16*(a - b)^2*(1 + Coth[x])) - (a*(3*a + b)*Log[1 - Coth[x]])/(16*(a + b)^3) + (a*(3*a - b)*Log[1 + Coth[x]])/(16*(a - b)^3) - (a^4*b*Log[a + b*Coth[x]])/(a^2 - b^2)^3}
{Cosh[x]^3/(a + b*Coth[x]), x, 9, (a^3*b*ArcTanh[(a*Cosh[x] + b*Sinh[x])/Sqrt[a^2 - b^2]])/(a^2 - b^2)^(5/2) - (a^2*b*Cosh[x])/(a^2 - b^2)^2 - (b*Cosh[x]^3)/(3*(a^2 - b^2)) + (a*b^2*Sinh[x])/(a^2 - b^2)^2 + (a*Sinh[x])/(a^2 - b^2) + (a*Sinh[x]^3)/(3*(a^2 - b^2))}
{Cosh[x]^2/(a + b*Coth[x]), x, 3, -(1/(4*(a + b)*(1 - Coth[x]))) + 1/(4*(a - b)*(1 + Coth[x])) - (a*Log[1 - Coth[x]])/(4*(a + b)^2) + (a*Log[1 + Coth[x]])/(4*(a - b)^2) - (a^2*b*Log[a + b*Coth[x]])/(a^2 - b^2)^2}
{Cosh[x]^1/(a + b*Coth[x]), x, 6, (a*b*ArcTanh[(a*Cosh[x] + b*Sinh[x])/Sqrt[a^2 - b^2]])/(a^2 - b^2)^(3/2) - (b*Cosh[x])/(a^2 - b^2) + (a*Sinh[x])/(a^2 - b^2)}
{Sech[x]^1/(a + b*Coth[x]), x, 6, ArcTan[Sinh[x]]/a + (b*ArcTanh[(a*Cosh[x] + b*Sinh[x])/Sqrt[a^2 - b^2]])/(a*Sqrt[a^2 - b^2])}
{Sech[x]^2/(a + b*Coth[x]), x, 3, (b*Log[Coth[x]])/a^2 - (b*Log[a + b*Coth[x]])/a^2 + Tanh[x]/a}
{Sech[x]^3/(a + b*Coth[x]), x, 9, ArcTan[Sinh[x]]/(2*a) - (b^2*ArcTan[Sinh[x]])/a^3 + (b*Sqrt[a^2 - b^2]*ArcTanh[(a*Cosh[x] + b*Sinh[x])/Sqrt[a^2 - b^2]])/a^3 - (b*Sech[x])/a^2 + (Sech[x]*Tanh[x])/(2*a)}
{Sech[x]^4/(a + b*Coth[x]), x, 3, (b*(a^2 - b^2)*Log[Coth[x]])/a^4 - (b*(a^2 - b^2)*Log[a + b*Coth[x]])/a^4 + ((a^2 - b^2)*Tanh[x])/a^3 + (b*Tanh[x]^2)/(2*a^2) - Tanh[x]^3/(3*a)}


{Cosh[x]^4/(1 + Coth[x]), x, 5, x/16 + 1/(32*(1 - Coth[x])^2) - 1/(8*(1 - Coth[x])) - 1/(24*(1 + Coth[x])^3) + 5/(32*(1 + Coth[x])^2) - 3/(16*(1 + Coth[x]))}
{Cosh[x]^3/(1 + Coth[x]), x, 8, Cosh[x]^5/5 - Sinh[x]^3/3 - Sinh[x]^5/5}
{Cosh[x]^2/(1 + Coth[x]), x, 5, x/8 - 1/(8*(1 - Coth[x])) + 1/(8*(1 + Coth[x])^2) - 1/(4*(1 + Coth[x]))}
{Cosh[x]^1/(1 + Coth[x]), x, 6, Cosh[x]^3/3 - Sinh[x]^3/3}
{Sech[x]^1/(1 + Coth[x]), x, 7, ArcTan[Sinh[x]] + Cosh[x] - Sinh[x]}
{Sech[x]^2/(1 + Coth[x]), x, 3, Log[Coth[x]] - Log[1 + Coth[x]] + Tanh[x]}
{Sech[x]^3/(1 + Coth[x]), x, 7, (-(1/2))*ArcTan[Sinh[x]] - Sech[x] + (1/2)*Sech[x]*Tanh[x]}
{Sech[x]^4/(1 + Coth[x]), x, 4, Tanh[x]^2/2 - Tanh[x]^3/3}


{Sech[x]^2*Sqrt[1 + Coth[x]], x, 3, ArcTanh[Sqrt[1 + Coth[x]]] + Sqrt[1 + Coth[x]]*Tanh[x]}


(* Following hangs Mathematica: *) 
{Sech[x]/(I + 2*Coth[x]), x, 6, (-I)*ArcTan[Sinh[x]] - (2*ArcTanh[(Cosh[x] - 2*I*Sinh[x])/Sqrt[5]])/Sqrt[5]}


(* ::Subsection::Closed:: *)
(*Integrands of the form Tanh[c+d x]^m (a+b Coth[c+d x])^n*)


{Tanh[x]^4/(a + b*Coth[x]), x, 9, (a*x)/(a^2 - b^2) - (b*(a^2 + b^2)*Log[Cosh[x]])/a^4 - (b^5*Log[a + b*Coth[x]])/(a^4*(a^2 - b^2)) - (b^5*Log[Sinh[x]])/(a^4*(a^2 - b^2)) - ((a^2 + b^2)*Tanh[x])/a^3 + (b*Tanh[x]^2)/(2*a^2) - Tanh[x]^3/(3*a)}
{Tanh[x]^3/(a + b*Coth[x]), x, 8, -((b*x)/(a^2 - b^2)) + ((a^2 + b^2)*Log[Cosh[x]])/a^3 + (b^4*Log[a + b*Coth[x]])/(a^3*(a^2 - b^2)) + (b^4*Log[Sinh[x]])/(a^3*(a^2 - b^2)) + (b*Tanh[x])/a^2 - Tanh[x]^2/(2*a)}
{Tanh[x]^2/(a + b*Coth[x]), x, 7, (a*x)/(a^2 - b^2) - (b*Log[Cosh[x]])/a^2 - (b^3*Log[a + b*Coth[x]])/(a^2*(a^2 - b^2)) - (b^3*Log[Sinh[x]])/(a^2*(a^2 - b^2)) - Tanh[x]/a}
{Tanh[x]^1/(a + b*Coth[x]), x, 5, -((b*x)/(a^2 - b^2)) + Log[Cosh[x]]/a + (b^2*Log[a + b*Coth[x]])/(a*(a^2 - b^2)) + (b^2*Log[Sinh[x]])/(a*(a^2 - b^2))}
{Tanh[x]^0/(a + b*Coth[x]), x, 3, (a*x)/(a^2 - b^2) - (b*Log[a + b*Coth[x]])/(a^2 - b^2) - (b*Log[Sinh[x]])/(a^2 - b^2)}
{Coth[x]^1/(a + b*Coth[x]), x, 4, -((b*x)/(a^2 - b^2)) + (a*Log[Cosh[x]])/(a^2 - b^2) + (a*Log[b + a*Tanh[x]])/(a^2 - b^2)}
{Coth[x]^2/(a + b*Coth[x]), x, 4, (a*x)/(a^2 - b^2) - Log[a + b*Coth[x]]/b - (b*Log[a + b*Coth[x]])/(a^2 - b^2) - (b*Log[Sinh[x]])/(a^2 - b^2)}
{Coth[x]^3/(a + b*Coth[x]), x, 4, -((b*x)/(a^2 - b^2)) - Coth[x]/b + (a^3*Log[a + b*Coth[x]])/(b^2*(a^2 - b^2)) + (a*Log[Sinh[x]])/(a^2 - b^2)}
{Coth[x]^4/(a + b*Coth[x]), x, 5, (a*x)/(a^2 - b^2) + (a*Coth[x])/b^2 - Coth[x]^2/(2*b) - (a^4*Log[a + b*Coth[x]])/(b^3*(a^2 - b^2)) - (b*Log[Sinh[x]])/(a^2 - b^2)}


{Tanh[x]^4/(1 + Coth[x]), x, 6, (5*x)/2 - 2*Log[Cosh[x]] - (5*Tanh[x])/2 + Tanh[x]^2 - (5*Tanh[x]^3)/6 + Tanh[x]^3/(2*(1 + Coth[x]))}
{Tanh[x]^3/(1 + Coth[x]), x, 5, -((3*x)/2) + 2*Log[Cosh[x]] + (3*Tanh[x])/2 - Tanh[x]^2 + Tanh[x]^2/(2*(1 + Coth[x]))}
{Tanh[x]^2/(1 + Coth[x]), x, 4, (3*x)/2 - Log[Cosh[x]] - (3*Tanh[x])/2 + Tanh[x]/(2*(1 + Coth[x]))}
{Tanh[x]^1/(1 + Coth[x]), x, 4, -(x/2) + 1/(2*(1 + Coth[x])) + Log[Cosh[x]]}
{Tanh[x]^0/(1 + Coth[x]), x, 2, x/2 - 1/(2*(1 + Coth[x]))}
{Coth[x]^1/(1 + Coth[x]), x, 3, x/2 - 1/(2*(1 + Tanh[x]))}
{Coth[x]^2/(1 + Coth[x]), x, 3, x/2 - 1/(2*(1 + Coth[x])) - Log[1 + Coth[x]]}
{Coth[x]^3/(1 + Coth[x]), x, 4, (3*x)/2 - (3*Coth[x])/2 + Coth[x]^2/(2*(1 + Coth[x])) - Log[Sinh[x]]}
{Coth[x]^4/(1 + Coth[x]), x, 5, -((3*x)/2) + (3*Coth[x])/2 - Coth[x]^2 + Coth[x]^3/(2*(1 + Coth[x])) + 2*Log[Sinh[x]]}


{Coth[x]*(1 + Coth[x])^(3/2), x, 4, 2*Sqrt[2]*ArcTanh[Sqrt[1 + Coth[x]]/Sqrt[2]] - 2*Sqrt[1 + Coth[x]] - (2/3)*(1 + Coth[x])^(3/2)}
{Coth[x]*Sqrt[1 + Coth[x]], x, 3, Sqrt[2]*ArcTanh[Sqrt[1 + Coth[x]]/Sqrt[2]] - 2*Sqrt[1 + Coth[x]]}
{Coth[x]/Sqrt[1 + Coth[x]], x, 3, ArcTanh[Sqrt[1 + Coth[x]]/Sqrt[2]]/Sqrt[2] + 1/Sqrt[1 + Coth[x]]}
{Coth[x]/(1 + Coth[x])^(3/2), x, 4, ArcTanh[Sqrt[1 + Coth[x]]/Sqrt[2]]/(2*Sqrt[2]) + 1/(3*(1 + Coth[x])^(3/2)) - 1/(2*Sqrt[1 + Coth[x]])}


{Coth[x]^2*(1 + Coth[x])^(3/2), x, 4, 2*Sqrt[2]*ArcTanh[Sqrt[1 + Coth[x]]/Sqrt[2]] - 2*Sqrt[1 + Coth[x]] - (2/5)*(1 + Coth[x])^(5/2)}
{Coth[x]^2*Sqrt[1 + Coth[x]], x, 3, Sqrt[2]*ArcTanh[Sqrt[1 + Coth[x]]/Sqrt[2]] - (2/3)*(1 + Coth[x])^(3/2)}
{Coth[x]^2/Sqrt[1 + Coth[x]], x, 4, ArcTanh[Sqrt[1 + Coth[x]]/Sqrt[2]]/Sqrt[2] - 1/Sqrt[1 + Coth[x]] - 2*Sqrt[1 + Coth[x]]}
{Coth[x]^2/(1 + Coth[x])^(3/2), x, 5, ArcTanh[Sqrt[1 + Coth[x]]/Sqrt[2]]/(2*Sqrt[2]) - 1/(3*(1 + Coth[x])^(3/2)) + 3/(2*Sqrt[1 + Coth[x]])}


(* ::Section::Closed:: *)
(*Integrands of the form Hyper[c+d x]^m (a+b Coth[c+d x]^2)^n*)


(* ::Subsection:: *)
(*Integrands of the form Sinh[c+d x]^m (a+b Coth[c+d x]^2)^n*)


(* ::Subsection:: *)
(*Integrands of the form Cosh[c+d x]^m (a+b Coth[c+d x]^2)^n*)


(* ::Subsection::Closed:: *)
(*Integrands of the form Tanh[c+d x]^m (a+b Coth[c+d x]^2)^n*)


(* ::Subsubsection::Closed:: *)
(*n*)


{(a + b*Coth[c + d*x]^2)^5, x, 4, (a + b)^5*x - (b*(5*a^4 + 10*a^3*b + 10*a^2*b^2 + 5*a*b^3 + b^4)*Coth[c + d*x])/d - (b^2*(10*a^3 + 10*a^2*b + 5*a*b^2 + b^3)*Coth[c + d*x]^3)/(3*d) - (b^3*(10*a^2 + 5*a*b + b^2)*Coth[c + d*x]^5)/(5*d) - (b^4*(5*a + b)*Coth[c + d*x]^7)/(7*d) - (b^5*Coth[c + d*x]^9)/(9*d)}
{(a + b*Coth[c + d*x]^2)^4, x, 4, (a + b)^4*x - (b*(2*a + b)*(2*a^2 + 2*a*b + b^2)*Coth[c + d*x])/d - (b^2*(6*a^2 + 4*a*b + b^2)*Coth[c + d*x]^3)/(3*d) - (b^3*(4*a + b)*Coth[c + d*x]^5)/(5*d) - (b^4*Coth[c + d*x]^7)/(7*d)}
{(a + b*Coth[c + d*x]^2)^3, x, 4, (a + b)^3*x - (b*(3*a^2 + 3*a*b + b^2)*Coth[c + d*x])/d - (b^2*(3*a + b)*Coth[c + d*x]^3)/(3*d) - (b^3*Coth[c + d*x]^5)/(5*d)}
{(a + b*Coth[c + d*x]^2)^2, x, 4, (a + b)^2*x - (b*(2*a + b)*Coth[c + d*x])/d - (b^2*Coth[c + d*x]^3)/(3*d)}
{1/(a + b*Coth[c + d*x]^2),x, 3, x/(a + b) + (Sqrt[b]*ArcTan[(Sqrt[b]*Coth[c + d*x])/Sqrt[a]])/(Sqrt[a]*(a + b)*d)}
{1/(a + b*Coth[c + d*x]^2)^2,x, 5, x/(a + b)^2 + (Sqrt[b]*(3*a + b)*ArcTan[(Sqrt[b]*Coth[c + d*x])/Sqrt[a]])/(2*a^(3/2)*(a + b)^2*d) + (b*Coth[c + d*x])/(2*a*(a + b)*d*(a + b*Coth[c + d*x]^2))}
{1/(a + b*Coth[c + d*x]^2)^3,x, 6, x/(a + b)^3 + (Sqrt[b]*(15*a^2 + 10*a*b + 3*b^2)*ArcTan[(Sqrt[b]*Coth[c + d*x])/Sqrt[a]])/(8*a^(5/2)*(a + b)^3*d) + (b*Coth[c + d*x])/(4*a*(a + b)*d*(a + b*Coth[c + d*x]^2)^2) + (b*(7*a + 3*b)*Coth[c + d*x])/(8*a^2*(a + b)^2*d*(a + b*Coth[c + d*x]^2))}
{1/(a + b*Coth[c + d*x]^2)^4,x, 7, x/(a + b)^4 + (Sqrt[b]*(35*a^3 + 35*a^2*b + 21*a*b^2 + 5*b^3)*ArcTan[(Sqrt[b]*Coth[c + d*x])/Sqrt[a]])/(16*a^(7/2)*(a + b)^4*d) + (b*Coth[c + d*x])/(6*a*(a + b)*d*(a + b*Coth[c + d*x]^2)^3) + (b*(11*a + 5*b)*Coth[c + d*x])/(24*a^2*(a + b)^2*d*(a + b*Coth[c + d*x]^2)^2) + (b*(19*a^2 + 16*a*b + 5*b^2)*Coth[c + d*x])/(16*a^3*(a + b)^3*d*(a + b*Coth[c + d*x]^2))}

{1/(1 - 2*Coth[x]^2), x, 3, -x + Sqrt[2]*ArcTanh[Sqrt[2]*Coth[x]]}


(* ::Subsubsection::Closed:: *)
(*n/2*)


{(a + b*Coth[x]^2)^(3/2), x, 5, (-(1/2))*Sqrt[b]*(3*a + 2*b)*ArcTanh[(Sqrt[b]*Coth[x])/Sqrt[a + b*Coth[x]^2]] + (a + b)^(3/2)*ArcTanh[(Sqrt[a + b]*Coth[x])/Sqrt[a + b*Coth[x]^2]] - (1/2)*b*Coth[x]*Sqrt[a + b*Coth[x]^2]}
{Sqrt[a + b*Coth[x]^2], x, 4, (-Sqrt[b])*ArcTanh[(Sqrt[b]*Coth[x])/Sqrt[a + b*Coth[x]^2]] + Sqrt[a + b]*ArcTanh[(Sqrt[a + b]*Coth[x])/Sqrt[a + b*Coth[x]^2]]}
{1/Sqrt[a + b*Coth[x]^2], x, 2, ArcTanh[(Sqrt[a + b]*Coth[x])/Sqrt[a + b*Coth[x]^2]]/Sqrt[a + b]}


{(1 + Coth[x]^2)^(3/2), x, 5, (-(5/2))*ArcSinh[Coth[x]] + 2*Sqrt[2]*ArcTanh[(Sqrt[2]*Coth[x])/Sqrt[1 + Coth[x]^2]] - (1/2)*Coth[x]*Sqrt[1 + Coth[x]^2]}
{Sqrt[1 + Coth[x]^2], x, 4, -ArcSinh[Coth[x]] + Sqrt[2]*ArcTanh[(Sqrt[2]*Coth[x])/Sqrt[1 + Coth[x]^2]]}
{1/Sqrt[1 + Coth[x]^2], x, 2, ArcTanh[(Sqrt[2]*Coth[x])/Sqrt[1 + Coth[x]^2]]/Sqrt[2]}


{(1 - Coth[x]^2)^(3/2), x, 3, (1/2)*ArcSin[Coth[x]] + (1/2)*Coth[x]*Sqrt[1 - Coth[x]^2]}
{Sqrt[1 - Coth[x]^2], x, 2, ArcSin[Coth[x]]}
{1/Sqrt[1 - Coth[x]^2], x, 2, Coth[x]/Sqrt[-Csch[x]^2], Coth[x]/Sqrt[1 - Coth[x]^2]}


{(-1 + Coth[x]^2)^(3/2), x, 4, (1/2)*ArcTanh[Coth[x]/Sqrt[-1 + Coth[x]^2]] - (1/2)*Coth[x]*Sqrt[-1 + Coth[x]^2]}
{Sqrt[-1 + Coth[x]^2], x, 3, -ArcTanh[Coth[x]/Sqrt[-1 + Coth[x]^2]]}
{1/Sqrt[-1 + Coth[x]^2], x, 3, Coth[x]/Sqrt[-1 + Coth[x]^2]}


{(-1 - Coth[x]^2)^(3/2), x, 5, (-(5/2))*ArcTan[Coth[x]/Sqrt[-1 - Coth[x]^2]] + 2*Sqrt[2]*ArcTan[(Sqrt[2]*Coth[x])/Sqrt[-1 - Coth[x]^2]] + (1/2)*Coth[x]*Sqrt[-1 - Coth[x]^2]}
{Sqrt[-1 - Coth[x]^2], x, 4, ArcTan[Coth[x]/Sqrt[-1 - Coth[x]^2]] - Sqrt[2]*ArcTan[(Sqrt[2]*Coth[x])/Sqrt[-1 - Coth[x]^2]]}
{1/Sqrt[-1 - Coth[x]^2], x, 2, ArcTan[(Sqrt[2]*Coth[x])/Sqrt[-1 - Coth[x]^2]]/Sqrt[2]}


(* ::Subsubsection::Closed:: *)
(*n/2>0*)


{Coth[x]^3*Sqrt[a + b*Coth[x]^2], x, 5, Sqrt[a + b]*ArcTanh[Sqrt[a + b*Coth[x]^2]/Sqrt[a + b]] - Sqrt[a + b*Coth[x]^2] - (a + b*Coth[x]^2)^(3/2)/(3*b)}
{Coth[x]^2*Sqrt[a + b*Coth[x]^2], x, 5, -(((a + 2*b)*ArcTanh[(Sqrt[b]*Coth[x])/Sqrt[a + b*Coth[x]^2]])/(2*Sqrt[b])) + Sqrt[a + b]*ArcTanh[(Sqrt[a + b]*Coth[x])/Sqrt[a + b*Coth[x]^2]] - (1/2)*Coth[x]*Sqrt[a + b*Coth[x]^2]}
{Coth[x]*Sqrt[a + b*Coth[x]^2], x, 4, Sqrt[a + b]*ArcTanh[Sqrt[a + b*Coth[x]^2]/Sqrt[a + b]] - Sqrt[a + b*Coth[x]^2]}
{Tanh[x]*Sqrt[a + b*Coth[x]^2], x, 6, (-Sqrt[a])*ArcTanh[Sqrt[a + b*Coth[x]^2]/Sqrt[a]] + Sqrt[a + b]*ArcTanh[Sqrt[a + b*Coth[x]^2]/Sqrt[a + b]]}
{Tanh[x]^2*Sqrt[a + b*Coth[x]^2], x, 4, Sqrt[a + b]*ArcTanh[(Sqrt[a + b]*Coth[x])/Sqrt[a + b*Coth[x]^2]] - Sqrt[a + b*Coth[x]^2]*Tanh[x]}


{Coth[x]^3*(a + b*Coth[x]^2)^(3/2), x, 6, (a + b)^(3/2)*ArcTanh[Sqrt[a + b*Coth[x]^2]/Sqrt[a + b]] - (a + b)*Sqrt[a + b*Coth[x]^2] - (1/3)*(a + b*Coth[x]^2)^(3/2) - (a + b*Coth[x]^2)^(5/2)/(5*b)}
{Coth[x]^2*(a + b*Coth[x]^2)^(3/2), x, 6, -(((3*a^2 + 12*a*b + 8*b^2)*ArcTanh[(Sqrt[b]*Coth[x])/Sqrt[a + b*Coth[x]^2]])/(8*Sqrt[b])) + (a + b)^(3/2)*ArcTanh[(Sqrt[a + b]*Coth[x])/Sqrt[a + b*Coth[x]^2]] - (1/8)*(5*a + 4*b)*Coth[x]*Sqrt[a + b*Coth[x]^2] - (1/4)*b*Coth[x]^3*Sqrt[a + b*Coth[x]^2]}
{Coth[x]*(a + b*Coth[x]^2)^(3/2), x, 5, (a + b)^(3/2)*ArcTanh[Sqrt[a + b*Coth[x]^2]/Sqrt[a + b]] - (a + b)*Sqrt[a + b*Coth[x]^2] - (1/3)*(a + b*Coth[x]^2)^(3/2)}
{Tanh[x]*(a + b*Coth[x]^2)^(3/2), x, 7, (-a^(3/2))*ArcTanh[Sqrt[a + b*Coth[x]^2]/Sqrt[a]] + (a + b)^(3/2)*ArcTanh[Sqrt[a + b*Coth[x]^2]/Sqrt[a + b]] - b*Sqrt[a + b*Coth[x]^2]}
{Tanh[x]^2*(a + b*Coth[x]^2)^(3/2), x, 5, (-b^(3/2))*ArcTanh[(Sqrt[b]*Coth[x])/Sqrt[a + b*Coth[x]^2]] + (a + b)^(3/2)*ArcTanh[(Sqrt[a + b]*Coth[x])/Sqrt[a + b*Coth[x]^2]] - a*Sqrt[a + b*Coth[x]^2]*Tanh[x]}


(* ::Subsubsection::Closed:: *)
(*n/2<0*)


{Coth[x]^3/Sqrt[a + b*Coth[x]^2], x, 4, ArcTanh[Sqrt[a + b*Coth[x]^2]/Sqrt[a + b]]/Sqrt[a + b] - Sqrt[a + b*Coth[x]^2]/b}
{Coth[x]^2/Sqrt[a + b*Coth[x]^2], x, 4, -(ArcTanh[(Sqrt[b]*Coth[x])/Sqrt[a + b*Coth[x]^2]]/Sqrt[b]) + ArcTanh[(Sqrt[a + b]*Coth[x])/Sqrt[a + b*Coth[x]^2]]/Sqrt[a + b]}
{Coth[x]/Sqrt[a + b*Coth[x]^2], x, 3, ArcTanh[Sqrt[a + b*Coth[x]^2]/Sqrt[a + b]]/Sqrt[a + b]}
{Tanh[x]/Sqrt[a + b*Coth[x]^2], x, 6, -(ArcTanh[Sqrt[a + b*Coth[x]^2]/Sqrt[a]]/Sqrt[a]) + ArcTanh[Sqrt[a + b*Coth[x]^2]/Sqrt[a + b]]/Sqrt[a + b]}
{Tanh[x]^2/Sqrt[a + b*Coth[x]^2], x, 4, ArcTanh[(Sqrt[a + b]*Coth[x])/Sqrt[a + b*Coth[x]^2]]/Sqrt[a + b] - (Sqrt[a + b*Coth[x]^2]*Tanh[x])/a}


{Coth[x]^3/(a + b*Coth[x]^2)^(3/2), x, 4, ArcTanh[Sqrt[a + b*Coth[x]^2]/Sqrt[a + b]]/(a + b)^(3/2) + a/(b*(a + b)*Sqrt[a + b*Coth[x]^2])}
{Coth[x]^2/(a + b*Coth[x]^2)^(3/2), x, 3, ArcTanh[(Sqrt[a + b]*Coth[x])/Sqrt[a + b*Coth[x]^2]]/(a + b)^(3/2) - Coth[x]/((a + b)*Sqrt[a + b*Coth[x]^2])}
{Coth[x]/(a + b*Coth[x]^2)^(3/2), x, 4, ArcTanh[Sqrt[a + b*Coth[x]^2]/Sqrt[a + b]]/(a + b)^(3/2) - 1/((a + b)*Sqrt[a + b*Coth[x]^2])}
{Tanh[x]/(a + b*Coth[x]^2)^(3/2), x, 7, -(ArcTanh[Sqrt[a + b*Coth[x]^2]/Sqrt[a]]/a^(3/2)) + ArcTanh[Sqrt[a + b*Coth[x]^2]/Sqrt[a + b]]/(a + b)^(3/2) + b/(a*(a + b)*Sqrt[a + b*Coth[x]^2])}
{Tanh[x]^2/(a + b*Coth[x]^2)^(3/2), x, 5, ArcTanh[(Sqrt[a + b]*Coth[x])/Sqrt[a + b*Coth[x]^2]]/(a + b)^(3/2) + (b*Tanh[x])/(a*(a + b)*Sqrt[a + b*Coth[x]^2]) - ((a + 2*b)*Sqrt[a + b*Coth[x]^2]*Tanh[x])/(a^2*(a + b))}


{Coth[x]^3/(a + b*Coth[x]^2)^(5/2), x, 5, ArcTanh[Sqrt[a + b*Coth[x]^2]/Sqrt[a + b]]/(a + b)^(5/2) + a/(3*b*(a + b)*(a + b*Coth[x]^2)^(3/2)) - 1/((a + b)^2*Sqrt[a + b*Coth[x]^2])}
{Coth[x]^2/(a + b*Coth[x]^2)^(5/2), x, 5, ArcTanh[(Sqrt[a + b]*Coth[x])/Sqrt[a + b*Coth[x]^2]]/(a + b)^(5/2) - Coth[x]/(3*(a + b)*(a + b*Coth[x]^2)^(3/2)) - ((2*a - b)*Coth[x])/(3*a*(a + b)^2*Sqrt[a + b*Coth[x]^2])}
{Coth[x]/(a + b*Coth[x]^2)^(5/2), x, 5, ArcTanh[Sqrt[a + b*Coth[x]^2]/Sqrt[a + b]]/(a + b)^(5/2) - 1/(3*(a + b)*(a + b*Coth[x]^2)^(3/2)) - 1/((a + b)^2*Sqrt[a + b*Coth[x]^2])}
{Tanh[x]/(a + b*Coth[x]^2)^(5/2), x, 8, -(ArcTanh[Sqrt[a + b*Coth[x]^2]/Sqrt[a]]/a^(5/2)) + ArcTanh[Sqrt[a + b*Coth[x]^2]/Sqrt[a + b]]/(a + b)^(5/2) + b/(3*a*(a + b)*(a + b*Coth[x]^2)^(3/2)) + (b*(2*a + b))/(a^2*(a + b)^2*Sqrt[a + b*Coth[x]^2])}
{Tanh[x]^2/(a + b*Coth[x]^2)^(5/2), x, 6, ArcTanh[(Sqrt[a + b]*Coth[x])/Sqrt[a + b*Coth[x]^2]]/(a + b)^(5/2) + (b*Tanh[x])/(3*a*(a + b)*(a + b*Coth[x]^2)^(3/2)) + (b*(7*a + 4*b)*Tanh[x])/(3*a^2*(a + b)^2*Sqrt[a + b*Coth[x]^2]) - ((3*a + 2*b)*(a + 4*b)*Sqrt[a + b*Coth[x]^2]*Tanh[x])/(3*a^3*(a + b)^2)}


(* ::Section::Closed:: *)
(*Integrands of the form Hyper[c+d x]^m (a+b Coth[c+d x]^n)^p*)


(* ::Subsection:: *)
(*Integrands of the form Sinh[c+d x]^m (a+b Coth[c+d x]^n)^p*)


(* ::Subsection:: *)
(*Integrands of the form Cosh[c+d x]^m (a+b Coth[c+d x]^n)^p*)


(* ::Subsection::Closed:: *)
(*Integrands of the form Tanh[c+d x]^m (a+b Coth[c+d x]^n)^p*)


{1/(1 + Coth[x]^3), x, 5, x/2 - (2*ArcTan[(1 - 2*Coth[x])/Sqrt[3]])/(3*Sqrt[3]) - 1/(6*(1 + Coth[x]))}


{Coth[x]*(a + b*Coth[x]^4)^(1/2), x, 6, (-(1/2))*Sqrt[b]*ArcTanh[(Sqrt[b]*Coth[x]^2)/Sqrt[a + b*Coth[x]^4]] + (1/2)*Sqrt[a + b]*ArcTanh[(a + b*Coth[x]^2)/(Sqrt[a + b]*Sqrt[a + b*Coth[x]^4])] - (1/2)*Sqrt[a + b*Coth[x]^4]}
{Coth[x]/(a + b*Coth[x]^4)^(1/2), x, 3, ArcTanh[(a + b*Coth[x]^2)/(Sqrt[a + b]*Sqrt[a + b*Coth[x]^4])]/(2*Sqrt[a + b])}
{Coth[x]/(a + b*Coth[x]^4)^(3/2), x, 4, ArcTanh[(a + b*Coth[x]^2)/(Sqrt[a + b]*Sqrt[a + b*Coth[x]^4])]/(2*(a + b)^(3/2)) - (a - b*Coth[x]^2)/(2*a*(a + b)*Sqrt[a + b*Coth[x]^4])}


{Coth[x]/(a + b*Coth[x]^4)^(3/2), x, 4, ArcTanh[(a + b*Coth[x]^2)/(Sqrt[a + b]*Sqrt[a + b*Coth[x]^4])]/(2*(a + b)^(3/2)) - (a - b*Coth[x]^2)/(2*a*(a + b)*Sqrt[a + b*Coth[x]^4])}


(* ::Section::Closed:: *)
(*Integrands of the form x^m Coth[a+b x]^n*)


(* ::Subsection::Closed:: *)
(*Integrands of the form x^m Coth[a+b x]^n*)


{x^3*Coth[a + b*x], x, 6, -(x^4/4) + (x^3*Log[1 - E^(2*a + 2*b*x)])/b + (3*x^2*PolyLog[2, E^(2*a + 2*b*x)])/(2*b^2) - (3*x*PolyLog[3, E^(2*a + 2*b*x)])/(2*b^3) + (3*PolyLog[4, E^(2*a + 2*b*x)])/(4*b^4)}
{x^2*Coth[a + b*x], x, 5, -(x^3/3) + (x^2*Log[1 - E^(2*a + 2*b*x)])/b + (x*PolyLog[2, E^(2*a + 2*b*x)])/b^2 - PolyLog[3, E^(2*a + 2*b*x)]/(2*b^3)}
{x^1*Coth[a + b*x], x, 4, -(x^2/2) + (x*Log[1 - E^(2*a + 2*b*x)])/b + PolyLog[2, E^(2*a + 2*b*x)]/(2*b^2)}
{Coth[a + b*x]/x^1, x, 0, Int[Coth[a + b*x]/x, x]}
{Coth[a + b*x]/x^2, x, 0, Int[Coth[a + b*x]/x^2, x]}


{x^3*Coth[a + b*x]^2, x, 7, -(x^3/b) + x^4/4 - (x^3*Coth[a + b*x])/b + (3*x^2*Log[1 - E^(2*a + 2*b*x)])/b^2 + (3*x*PolyLog[2, E^(2*a + 2*b*x)])/b^3 - (3*PolyLog[3, E^(2*a + 2*b*x)])/(2*b^4)}
{x^2*Coth[a + b*x]^2, x, 6, -(x^2/b) + x^3/3 - (x^2*Coth[a + b*x])/b + (2*x*Log[1 - E^(2*a + 2*b*x)])/b^2 + PolyLog[2, E^(2*a + 2*b*x)]/b^3}
{x^1*Coth[a + b*x]^2, x, 3, x^2/2 - (x*Coth[a + b*x])/b + Log[Sinh[a + b*x]]/b^2}
{Coth[a + b*x]^2/x^1, x, 0, Int[Coth[a + b*x]^2/x, x]}
{Coth[a + b*x]^2/x^2, x, 0, Int[Coth[a + b*x]^2/x^2, x]}


{x^3*Coth[a + b*x]^3, x, 13, -((3*x^2)/(2*b^2)) + x^3/(2*b) - x^4/4 - (3*x^2*Coth[a + b*x])/(2*b^2) - (x^3*Coth[a + b*x]^2)/(2*b) + (3*x*Log[1 - E^(2*a + 2*b*x)])/b^3 + (x^3*Log[1 - E^(2*a + 2*b*x)])/b + (3*PolyLog[2, E^(2*a + 2*b*x)])/(2*b^4) + (3*x^2*PolyLog[2, E^(2*a + 2*b*x)])/(2*b^2) - (3*x*PolyLog[3, E^(2*a + 2*b*x)])/(2*b^3) + (3*PolyLog[4, E^(2*a + 2*b*x)])/(4*b^4)}
{x^2*Coth[a + b*x]^3, x, 9, x^2/(2*b) - x^3/3 - (x*Coth[a + b*x])/b^2 - (x^2*Coth[a + b*x]^2)/(2*b) + (x^2*Log[1 - E^(2*a + 2*b*x)])/b + Log[Sinh[a + b*x]]/b^3 + (x*PolyLog[2, E^(2*a + 2*b*x)])/b^2 - PolyLog[3, E^(2*a + 2*b*x)]/(2*b^3)}
{x^1*Coth[a + b*x]^3, x, 7, x/(2*b) - x^2/2 - Coth[a + b*x]/(2*b^2) - (x*Coth[a + b*x]^2)/(2*b) + (x*Log[1 - E^(2*a + 2*b*x)])/b + PolyLog[2, E^(2*a + 2*b*x)]/(2*b^2)}
{Coth[a + b*x]^3/x^1, x, 0, Int[Coth[a + b*x]^3/x, x]}
{Coth[a + b*x]^3/x^2, x, 0, Int[Coth[a + b*x]^3/x^2, x]}


(* ::Subsection:: *)
(*Integrands of the form x^m Coth[a+b x]^(n/2)*)


(* ::Section::Closed:: *)
(*Integrands of the form x^m Csch[c+d x]^2 (a+b Coth[c+d x]^n)^p*)


{x*Csch[x]^2/(a + b*Coth[x])^2, x, 2, -((a*x)/(b*(a^2 - b^2))) + x/(b*(a + b*Coth[x])) + Log[b*Cosh[x] + a*Sinh[x]]/(a^2 - b^2)}


(* ::Section::Closed:: *)
(*Integrands of the form x^m Coth[a+b Log[c x^n]]^p*)


(* ::Subsection::Closed:: *)
(*Integrands of the form x^m Coth[a+b Log[c x^n]]^p*)


{Coth[a + b*Log[c*x^n]]/x, x, 2, Log[Sinh[a + b*Log[c*x^n]]]/(b*n)}
{Coth[a + b*Log[c*x^n]]^2/x, x, 3, -(Coth[a + b*Log[c*x^n]]/(b*n)) + Log[c*x^n]/n}
{Coth[a + b*Log[c*x^n]]^3/x, x, 3, -(Coth[a + b*Log[c*x^n]]^2/(2*b*n)) + Log[Sinh[a + b*Log[c*x^n]]]/(b*n)}
{Coth[a + b*Log[c*x^n]]^4/x, x, 4, -(Coth[a + b*Log[c*x^n]]/(b*n)) - Coth[a + b*Log[c*x^n]]^3/(3*b*n) + Log[c*x^n]/n}
{Coth[a + b*Log[c*x^n]]^5/x, x, 4, -(Coth[a + b*Log[c*x^n]]^2/(2*b*n)) - Coth[a + b*Log[c*x^n]]^4/(4*b*n) + Log[Sinh[a + b*Log[c*x^n]]]/(b*n)}


(* ::Subsection::Closed:: *)
(*Integrands of the form x^m Coth[a+b Log[c x^n]]^(p/2)*)


{Coth[a + b*Log[c*x^n]]^(5/2)/x, x, 6, -(ArcTan[Sqrt[Coth[a + b*Log[c*x^n]]]]/(b*n)) + ArcTanh[Sqrt[Coth[a + b*Log[c*x^n]]]]/(b*n) - (2*Coth[a + b*Log[c*x^n]]^(3/2))/(3*b*n)}
{Coth[a + b*Log[c*x^n]]^(3/2)/x, x, 6, ArcTan[Sqrt[Coth[a + b*Log[c*x^n]]]]/(b*n) + ArcTanh[Sqrt[Coth[a + b*Log[c*x^n]]]]/(b*n) - (2*Sqrt[Coth[a + b*Log[c*x^n]]])/(b*n)}
{Sqrt[Coth[a + b*Log[c*x^n]]]/x, x, 5, -(ArcTan[Sqrt[Coth[a + b*Log[c*x^n]]]]/(b*n)) + ArcTanh[Sqrt[Coth[a + b*Log[c*x^n]]]]/(b*n)}
{1/(x*Sqrt[Coth[a + b*Log[c*x^n]]]), x, 5, ArcTan[Sqrt[Coth[a + b*Log[c*x^n]]]]/(b*n) + ArcTanh[Sqrt[Coth[a + b*Log[c*x^n]]]]/(b*n)}
{1/(x*Coth[a + b*Log[c*x^n]]^(3/2)), x, 6, -(ArcTan[Sqrt[Coth[a + b*Log[c*x^n]]]]/(b*n)) + ArcTanh[Sqrt[Coth[a + b*Log[c*x^n]]]]/(b*n) - 2/(b*n*Sqrt[Coth[a + b*Log[c*x^n]]])}
{1/(x*Coth[a + b*Log[c*x^n]]^(5/2)), x, 6, ArcTan[Sqrt[Coth[a + b*Log[c*x^n]]]]/(b*n) + ArcTanh[Sqrt[Coth[a + b*Log[c*x^n]]]]/(b*n) - 2/(3*b*n*Coth[a + b*Log[c*x^n]]^(3/2))}
