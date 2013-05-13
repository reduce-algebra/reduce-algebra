(* ::Package:: *)

(* ::Title:: *)
(*Integrands of the form trig(c+d x)^m (a+b tan(c+d x))^n*)


(* ::Section::Closed:: *)
(*Integrands of the form Sin[c+d x]^m (a+b Tan[c+d x])^n when a^2+b^2=0*)


(* ::Subsection::Closed:: *)
(*Integrands of the form Sin[c+d x]^m (a+b Tan[c+d x])^n*)


(* ::Subsubsection:: *)
(*n>0*)


(* ::Subsubsection::Closed:: *)
(*n<0*)


{Sin[x]^4/(I + Tan[x]), x, 5, -((I*x)/16) - 1/(32*(I - Tan[x])^2) - I/(8*(I - Tan[x])) + I/(24*(I + Tan[x])^3) - 5/(32*(I + Tan[x])^2) - (3*I)/(16*(I + Tan[x]))}
{Sin[x]^3/(I + Tan[x]), x, 8, (1/3)*I*Cos[x]^3 - (1/5)*I*Cos[x]^5 + Sin[x]^5/5}
{Sin[x]^2/(I + Tan[x]), x, 5, -((I*x)/8) - I/(8*(I - Tan[x])) - 1/(8*(I + Tan[x])^2) - I/(4*(I + Tan[x]))}
{Sin[x]^1/(I + Tan[x]), x, 6, (1/3)*I*Cos[x]^3 + Sin[x]^3/3}
{Csc[x]^1/(I + Tan[x]), x, 7, I*ArcTanh[Cos[x]] - I*Cos[x] + Sin[x]}
{Csc[x]^2/(I + Tan[x]), x, 3, I*Cot[x] + Log[Tan[x]] - Log[I + Tan[x]]}
{Csc[x]^3/(I + Tan[x]), x, 7, (-(1/2))*I*ArcTanh[Cos[x]] - Csc[x] + (1/2)*I*Cot[x]*Csc[x]}
{Csc[x]^4/(I + Tan[x]), x, 4, (-(1/2))*Cot[x]^2 + (1/3)*I*Cot[x]^3}
{Csc[x]^5/(I + Tan[x]), x, 8, (-(1/8))*I*ArcTanh[Cos[x]] + (1/8)*I*Cot[x]*Csc[x] + (1/4)*I*Cot[x]^3*Csc[x] - Csc[x]^3/3}
{Csc[x]^6/(I + Tan[x]), x, 4, (-(1/2))*Cot[x]^2 + (1/3)*I*Cot[x]^3 - Cot[x]^4/4 + (1/5)*I*Cot[x]^5}


(* ::Section::Closed:: *)
(*Integrands of the form Sin[c+d x]^m (a+b Tan[c+d x])^n*)


(* ::Subsection::Closed:: *)
(*Integrands of the form Sin[c+d x]^m (a+b Tan[c+d x])^n*)
(**)


(* ::Subsubsection::Closed:: *)
(*n>0*)


{Sin[c + d*x]^m*(a + b*Tan[c + d*x]), x, 6, (b*Hypergeometric2F1[1, (2 + m)/2, (4 + m)/2, Sin[c + d*x]^2]*Sin[c + d*x]^(2 + m))/(d*(2 + m)) - (a*Cos[c + d*x]*Hypergeometric2F1[1/2, (1 - m)/2, 3/2, Cos[c + d*x]^2]*Sin[c + d*x]^(1 + m)*(Sin[c + d*x]^2)^((1/2)*(-1 - m)))/d}

{Sin[c + d*x]^5*(a + b*Tan[c + d*x]), x, 8, (b*ArcTanh[Sin[c + d*x]])/d - (a*Cos[c + d*x])/d + (2*a*Cos[c + d*x]^3)/(3*d) - (a*Cos[c + d*x]^5)/(5*d) - (b*Sin[c + d*x])/d - (b*Sin[c + d*x]^3)/(3*d) - (b*Sin[c + d*x]^5)/(5*d)}
{Sin[c + d*x]^4*(a + b*Tan[c + d*x]), x, 7, (3*a*x)/8 + (b*Cos[c + d*x]^2)/d - (b*Cos[c + d*x]^4)/(4*d) - (b*Log[Cos[c + d*x]])/d - (3*a*Cos[c + d*x]*Sin[c + d*x])/(8*d) - (a*Cos[c + d*x]*Sin[c + d*x]^3)/(4*d)}
{Sin[c + d*x]^3*(a + b*Tan[c + d*x]), x, 7, (b*ArcTanh[Sin[c + d*x]])/d - (a*Cos[c + d*x])/d + (a*Cos[c + d*x]^3)/(3*d) - (b*Sin[c + d*x])/d - (b*Sin[c + d*x]^3)/(3*d)}
{Sin[c + d*x]^2*(a + b*Tan[c + d*x]), x, 6, (a*x)/2 + (b*Cos[c + d*x]^2)/(2*d) - (b*Log[Cos[c + d*x]])/d - (a*Cos[c + d*x]*Sin[c + d*x])/(2*d)}
{Sin[c + d*x]^1*(a + b*Tan[c + d*x]), x, 5, (b*ArcTanh[Sin[c + d*x]])/d - (a*Cos[c + d*x])/d - (b*Sin[c + d*x])/d}
{Csc[c + d*x]^1*(a + b*Tan[c + d*x]), x, 4, -((a*ArcTanh[Cos[c + d*x]])/d) + (b*ArcTanh[Sin[c + d*x]])/d}
{Csc[c + d*x]^2*(a + b*Tan[c + d*x]), x, 5, -((a*Cot[c + d*x])/d) + (b*Log[Tan[c + d*x]])/d}
{Csc[c + d*x]^3*(a + b*Tan[c + d*x]), x, 6, -((a*ArcTanh[Cos[c + d*x]])/(2*d)) + (b*ArcTanh[Sin[c + d*x]])/d - (b*Csc[c + d*x])/d - (a*Cot[c + d*x]*Csc[c + d*x])/(2*d)}
{Csc[c + d*x]^4*(a + b*Tan[c + d*x]), x, 7, -((a*Cot[c + d*x])/d) - (b*Cot[c + d*x]^2)/(2*d) - (a*Cot[c + d*x]^3)/(3*d) + (b*Log[Tan[c + d*x]])/d}
{Csc[c + d*x]^5*(a + b*Tan[c + d*x]), x, 8, -((3*a*ArcTanh[Cos[c + d*x]])/(8*d)) + (b*ArcTanh[Sin[c + d*x]])/d - (b*Csc[c + d*x])/d - (3*a*Cot[c + d*x]*Csc[c + d*x])/(8*d) - (b*Csc[c + d*x]^3)/(3*d) - (a*Cot[c + d*x]*Csc[c + d*x]^3)/(4*d)}
{Csc[c + d*x]^6*(a + b*Tan[c + d*x]), x, 7, -((a*Cot[c + d*x])/d) - (b*Cot[c + d*x]^2)/d - (2*a*Cot[c + d*x]^3)/(3*d) - (b*Cot[c + d*x]^4)/(4*d) - (a*Cot[c + d*x]^5)/(5*d) + (b*Log[Tan[c + d*x]])/d}


{Sin[c + d*x]^m*(a + b*Tan[c + d*x])^2, x, 8, (2*a*b*Hypergeometric2F1[1, (2 + m)/2, (4 + m)/2, Sin[c + d*x]^2]*Sin[c + d*x]^(2 + m))/(d*(2 + m)) + (b^2*Sec[c + d*x]*Sin[c + d*x]^(3 + m))/d + (b^2*(2 + m)*Cos[c + d*x]*Hypergeometric2F1[1/2, (1/2)*(-1 - m), 3/2, Cos[c + d*x]^2]*Sin[c + d*x]^(3 + m)*(Sin[c + d*x]^2)^((1/2)*(-3 - m)))/d - (a^2*Cos[c + d*x]*Hypergeometric2F1[1/2, (1 - m)/2, 3/2, Cos[c + d*x]^2]*Sin[c + d*x]^(1 + m)*(Sin[c + d*x]^2)^((1/2)*(-1 - m)))/d}

{Sin[c + d*x]^4*(a + b*Tan[c + d*x])^2, x, 11, (a^2 - 3*b^2)*x - (1/2)*(2*a^2 - 3*b^2)*x + (3/8)*(a^2 - b^2)*x + (a*b*Log[1 + Tan[c + d*x]^2])/d + (b^2*Tan[c + d*x])/d - (2*a*b - (a^2 - b^2)*Tan[c + d*x])/(4*d*(1 + Tan[c + d*x]^2)^2) + (3*(a^2 - b^2)*Tan[c + d*x])/(8*d*(1 + Tan[c + d*x]^2)) + (4*a*b - (2*a^2 - 3*b^2)*Tan[c + d*x])/(2*d*(1 + Tan[c + d*x]^2))}
{Sin[c + d*x]^3*(a + b*Tan[c + d*x])^2, x, 10, (2*a*b*ArcTanh[Sin[c + d*x]])/d - (a^2*Cos[c + d*x])/d + (2*b^2*Cos[c + d*x])/d + (a^2*Cos[c + d*x]^3)/(3*d) - (b^2*Cos[c + d*x]^3)/(3*d) + (b^2*Sec[c + d*x])/d - (2*a*b*Sin[c + d*x])/d - (2*a*b*Sin[c + d*x]^3)/(3*d)}
{Sin[c + d*x]^2*(a + b*Tan[c + d*x])^2, x, 8, (a^2 - 2*b^2)*x - (1/2)*(a^2 - b^2)*x + (a*b*Log[1 + Tan[c + d*x]^2])/d + (b^2*Tan[c + d*x])/d + (2*a*b - (a^2 - b^2)*Tan[c + d*x])/(2*d*(1 + Tan[c + d*x]^2))}
{Sin[c + d*x]^1*(a + b*Tan[c + d*x])^2, x, 8, (2*a*b*ArcTanh[Sin[c + d*x]])/d - (a^2*Cos[c + d*x])/d + (b^2*Cos[c + d*x])/d + (b^2*Sec[c + d*x])/d - (2*a*b*Sin[c + d*x])/d}
{Csc[c + d*x]^1*(a + b*Tan[c + d*x])^2, x, 5, -((a^2*ArcTanh[Cos[c + d*x]])/d) + (2*a*b*ArcTanh[Sin[c + d*x]])/d + (b^2*Sec[c + d*x])/d}
{Csc[c + d*x]^2*(a + b*Tan[c + d*x])^2, x, 3, -((a^2*Cot[c + d*x])/d) + (2*a*b*Log[Tan[c + d*x]])/d + (b^2*Tan[c + d*x])/d}
{Csc[c + d*x]^3*(a + b*Tan[c + d*x])^2, x, 8, -((a^2*ArcTanh[Cos[c + d*x]])/(2*d)) - (b^2*ArcTanh[Cos[c + d*x]])/d + (2*a*b*ArcTanh[Sin[c + d*x]])/d - (2*a*b*Csc[c + d*x])/d - (a^2*Cot[c + d*x]*Csc[c + d*x])/(2*d) + (b^2*Sec[c + d*x])/d}
{Csc[c + d*x]^4*(a + b*Tan[c + d*x])^2, x, 3, -(((a^2 + b^2)*Cot[c + d*x])/d) - (a*b*Cot[c + d*x]^2)/d - (a^2*Cot[c + d*x]^3)/(3*d) + (2*a*b*Log[Tan[c + d*x]])/d + (b^2*Tan[c + d*x])/d}
{Csc[c + d*x]^5*(a + b*Tan[c + d*x])^2, x, 11, -((3*a^2*ArcTanh[Cos[c + d*x]])/(8*d)) - (3*b^2*ArcTanh[Cos[c + d*x]])/(2*d) + (2*a*b*ArcTanh[Sin[c + d*x]])/d - (2*a*b*Csc[c + d*x])/d - (3*a^2*Cot[c + d*x]*Csc[c + d*x])/(8*d) - (2*a*b*Csc[c + d*x]^3)/(3*d) - (a^2*Cot[c + d*x]*Csc[c + d*x]^3)/(4*d) + (3*b^2*Sec[c + d*x])/(2*d) - (b^2*Csc[c + d*x]^2*Sec[c + d*x])/(2*d)}
{Csc[c + d*x]^6*(a + b*Tan[c + d*x])^2, x, 3, -(((a^2 + 2*b^2)*Cot[c + d*x])/d) - (2*a*b*Cot[c + d*x]^2)/d - ((2*a^2 + b^2)*Cot[c + d*x]^3)/(3*d) - (a*b*Cot[c + d*x]^4)/(2*d) - (a^2*Cot[c + d*x]^5)/(5*d) + (2*a*b*Log[Tan[c + d*x]])/d + (b^2*Tan[c + d*x])/d}


{Sin[c + d*x]^m*(a + b*Tan[c + d*x])^3, x, 12, (b^3*Sin[c + d*x]^(2 + m))/(2*d) - (b^3*Hypergeometric2F1[1, (2 + m)/2, (4 + m)/2, Sin[c + d*x]^2]*Sin[c + d*x]^(2 + m))/(2*d) + (3*a^2*b*Hypergeometric2F1[1, (2 + m)/2, (4 + m)/2, Sin[c + d*x]^2]*Sin[c + d*x]^(2 + m))/(d*(2 + m)) + (3*a*b^2*Sec[c + d*x]*Sin[c + d*x]^(3 + m))/d + (3*a*b^2*(2 + m)*Cos[c + d*x]*Hypergeometric2F1[1/2, (1/2)*(-1 - m), 3/2, Cos[c + d*x]^2]*Sin[c + d*x]^(3 + m)*(Sin[c + d*x]^2)^((1/2)*(-3 - m)))/d - (a^3*Cos[c + d*x]*Hypergeometric2F1[1/2, (1 - m)/2, 3/2, Cos[c + d*x]^2]*Sin[c + d*x]^(1 + m)*(Sin[c + d*x]^2)^((1/2)*(-1 - m)))/d + (b^3*Sin[c + d*x]^(4 + m))/(2*d*(1 - Sin[c + d*x]^2))}

{Sin[c + d*x]^3*(a + b*Tan[c + d*x])^3, x, 14, (3*a^2*b*ArcTanh[Sin[c + d*x]])/d - (5*b^3*ArcTanh[Sin[c + d*x]])/(2*d) - (a^3*Cos[c + d*x])/d + (6*a*b^2*Cos[c + d*x])/d + (a^3*Cos[c + d*x]^3)/(3*d) - (a*b^2*Cos[c + d*x]^3)/d + (3*a*b^2*Sec[c + d*x])/d - (3*a^2*b*Sin[c + d*x])/d + (5*b^3*Sin[c + d*x])/(2*d) - (a^2*b*Sin[c + d*x]^3)/d + (5*b^3*Sin[c + d*x]*Tan[c + d*x]^2)/(6*d) - (b^3*Sin[c + d*x]^3*Tan[c + d*x]^2)/(3*d)}
{Sin[c + d*x]^2*(a + b*Tan[c + d*x])^3, x, 8, a*(a^2 - 6*b^2)*x - (1/2)*a*(a^2 - 3*b^2)*x + (b*(3*a^2 - 2*b^2)*Log[1 + Tan[c + d*x]^2])/(2*d) + (3*a*b^2*Tan[c + d*x])/d + (b^3*Tan[c + d*x]^2)/(2*d) + (b*(3*a^2 - b^2) - a*(a^2 - 3*b^2)*Tan[c + d*x])/(2*d*(1 + Tan[c + d*x]^2))}
{Sin[c + d*x]^1*(a + b*Tan[c + d*x])^3, x, 11, (3*a^2*b*ArcTanh[Sin[c + d*x]])/d - (3*b^3*ArcTanh[Sin[c + d*x]])/(2*d) - (a^3*Cos[c + d*x])/d + (3*a*b^2*Cos[c + d*x])/d + (3*a*b^2*Sec[c + d*x])/d - (3*a^2*b*Sin[c + d*x])/d + (3*b^3*Sin[c + d*x])/(2*d) + (b^3*Sin[c + d*x]*Tan[c + d*x]^2)/(2*d)}
{Csc[c + d*x]^1*(a + b*Tan[c + d*x])^3, x, 7, -((a^3*ArcTanh[Cos[c + d*x]])/d) + (3*a^2*b*ArcTanh[Sin[c + d*x]])/d - (b^3*ArcTanh[Sin[c + d*x]])/(2*d) + (3*a*b^2*Sec[c + d*x])/d + (b^3*Sec[c + d*x]*Tan[c + d*x])/(2*d)}
{Csc[c + d*x]^2*(a + b*Tan[c + d*x])^3, x, 3, -((a^3*Cot[c + d*x])/d) + (3*a^2*b*Log[Tan[c + d*x]])/d + (3*a*b^2*Tan[c + d*x])/d + (b^3*Tan[c + d*x]^2)/(2*d)}
{Csc[c + d*x]^3*(a + b*Tan[c + d*x])^3, x, 10, -((a^3*ArcTanh[Cos[c + d*x]])/(2*d)) - (3*a*b^2*ArcTanh[Cos[c + d*x]])/d + (3*a^2*b*ArcTanh[Sin[c + d*x]])/d + (b^3*ArcTanh[Sin[c + d*x]])/(2*d) - (3*a^2*b*Csc[c + d*x])/d - (a^3*Cot[c + d*x]*Csc[c + d*x])/(2*d) + (3*a*b^2*Sec[c + d*x])/d + (b^3*Sec[c + d*x]*Tan[c + d*x])/(2*d)}
{Csc[c + d*x]^4*(a + b*Tan[c + d*x])^3, x, 3, -((a*(a^2 + 3*b^2)*Cot[c + d*x])/d) - (3*a^2*b*Cot[c + d*x]^2)/(2*d) - (a^3*Cot[c + d*x]^3)/(3*d) + (b*(3*a^2 + b^2)*Log[Tan[c + d*x]])/d + (3*a*b^2*Tan[c + d*x])/d + (b^3*Tan[c + d*x]^2)/(2*d)}
{Csc[c + d*x]^5*(a + b*Tan[c + d*x])^3, x, 14, -((3*a^3*ArcTanh[Cos[c + d*x]])/(8*d)) - (9*a*b^2*ArcTanh[Cos[c + d*x]])/(2*d) + (3*a^2*b*ArcTanh[Sin[c + d*x]])/d + (3*b^3*ArcTanh[Sin[c + d*x]])/(2*d) - (3*a^2*b*Csc[c + d*x])/d - (3*b^3*Csc[c + d*x])/(2*d) - (3*a^3*Cot[c + d*x]*Csc[c + d*x])/(8*d) - (a^2*b*Csc[c + d*x]^3)/d - (a^3*Cot[c + d*x]*Csc[c + d*x]^3)/(4*d) + (9*a*b^2*Sec[c + d*x])/(2*d) - (3*a*b^2*Csc[c + d*x]^2*Sec[c + d*x])/(2*d) + (b^3*Csc[c + d*x]*Sec[c + d*x]^2)/(2*d)}
{Csc[c + d*x]^6*(a + b*Tan[c + d*x])^3, x, 3, -((a*(a^2 + 6*b^2)*Cot[c + d*x])/d) - (b*(6*a^2 + b^2)*Cot[c + d*x]^2)/(2*d) - (a*(2*a^2 + 3*b^2)*Cot[c + d*x]^3)/(3*d) - (3*a^2*b*Cot[c + d*x]^4)/(4*d) - (a^3*Cot[c + d*x]^5)/(5*d) + (b*(3*a^2 + 2*b^2)*Log[Tan[c + d*x]])/d + (3*a*b^2*Tan[c + d*x])/d + (b^3*Tan[c + d*x]^2)/(2*d)}


{Sin[c + d*x]^m*(a + b*Tan[c + d*x])^4, x, 15, (2*a*b^3*Sin[c + d*x]^(2 + m))/d - (2*a*b^3*Hypergeometric2F1[1, (2 + m)/2, (4 + m)/2, Sin[c + d*x]^2]*Sin[c + d*x]^(2 + m))/d + (4*a^3*b*Hypergeometric2F1[1, (2 + m)/2, (4 + m)/2, Sin[c + d*x]^2]*Sin[c + d*x]^(2 + m))/(d*(2 + m)) + (6*a^2*b^2*Sec[c + d*x]*Sin[c + d*x]^(3 + m))/d - (b^4*(2 + m)*Sec[c + d*x]*Sin[c + d*x]^(5 + m))/(3*d) + (b^4*Sec[c + d*x]^3*Sin[c + d*x]^(5 + m))/(3*d) - (b^4*(2 + m)*(4 + m)*Cos[c + d*x]*Hypergeometric2F1[1/2, (1/2)*(-3 - m), 3/2, Cos[c + d*x]^2]*Sin[c + d*x]^(5 + m)*(Sin[c + d*x]^2)^((1/2)*(-5 - m)))/(3*d) + (6*a^2*b^2*(2 + m)*Cos[c + d*x]*Hypergeometric2F1[1/2, (1/2)*(-1 - m), 3/2, Cos[c + d*x]^2]*Sin[c + d*x]^(3 + m)*(Sin[c + d*x]^2)^((1/2)*(-3 - m)))/d - (a^4*Cos[c + d*x]*Hypergeometric2F1[1/2, (1 - m)/2, 3/2, Cos[c + d*x]^2]*Sin[c + d*x]^(1 + m)*(Sin[c + d*x]^2)^((1/2)*(-1 - m)))/d + (2*a*b^3*Sin[c + d*x]^(4 + m))/(d*(1 - Sin[c + d*x]^2))}

{Sin[c + d*x]^3*(a + b*Tan[c + d*x])^4, x, 17, (4*a^3*b*ArcTanh[Sin[c + d*x]])/d - (10*a*b^3*ArcTanh[Sin[c + d*x]])/d - (a^4*Cos[c + d*x])/d + (12*a^2*b^2*Cos[c + d*x])/d - (3*b^4*Cos[c + d*x])/d + (a^4*Cos[c + d*x]^3)/(3*d) - (2*a^2*b^2*Cos[c + d*x]^3)/d + (b^4*Cos[c + d*x]^3)/(3*d) + (6*a^2*b^2*Sec[c + d*x])/d - (3*b^4*Sec[c + d*x])/d + (b^4*Sec[c + d*x]^3)/(3*d) - (4*a^3*b*Sin[c + d*x])/d + (10*a*b^3*Sin[c + d*x])/d - (4*a^3*b*Sin[c + d*x]^3)/(3*d) + (10*a*b^3*Sin[c + d*x]*Tan[c + d*x]^2)/(3*d) - (4*a*b^3*Sin[c + d*x]^3*Tan[c + d*x]^2)/(3*d)}
{Sin[c + d*x]^2*(a + b*Tan[c + d*x])^4, x, 8, (-(1/2))*(a^4 - 6*a^2*b^2 + b^4)*x + (a^4 - 12*a^2*b^2 + 3*b^4)*x + (2*a*b*(a^2 - 2*b^2)*Log[1 + Tan[c + d*x]^2])/d + (2*b^2*(3*a^2 - b^2)*Tan[c + d*x])/d + (2*a*b^3*Tan[c + d*x]^2)/d + (b^4*Tan[c + d*x]^3)/(3*d) + (4*a*b*(a^2 - b^2) - (a^4 - 6*a^2*b^2 + b^4)*Tan[c + d*x])/(2*d*(1 + Tan[c + d*x]^2))}
{Sin[c + d*x]^1*(a + b*Tan[c + d*x])^4, x, 14, (4*a^3*b*ArcTanh[Sin[c + d*x]])/d - (6*a*b^3*ArcTanh[Sin[c + d*x]])/d - (a^4*Cos[c + d*x])/d + (6*a^2*b^2*Cos[c + d*x])/d - (b^4*Cos[c + d*x])/d + (6*a^2*b^2*Sec[c + d*x])/d - (2*b^4*Sec[c + d*x])/d + (b^4*Sec[c + d*x]^3)/(3*d) - (4*a^3*b*Sin[c + d*x])/d + (6*a*b^3*Sin[c + d*x])/d + (2*a*b^3*Sin[c + d*x]*Tan[c + d*x]^2)/d}
{Csc[c + d*x]^1*(a + b*Tan[c + d*x])^4, x, 9, -((a^4*ArcTanh[Cos[c + d*x]])/d) + (4*a^3*b*ArcTanh[Sin[c + d*x]])/d - (2*a*b^3*ArcTanh[Sin[c + d*x]])/d + (6*a^2*b^2*Sec[c + d*x])/d - (b^4*Sec[c + d*x])/d + (b^4*Sec[c + d*x]^3)/(3*d) + (2*a*b^3*Sec[c + d*x]*Tan[c + d*x])/d}
{Csc[c + d*x]^2*(a + b*Tan[c + d*x])^4, x, 3, -((a^4*Cot[c + d*x])/d) + (4*a^3*b*Log[Tan[c + d*x]])/d + (6*a^2*b^2*Tan[c + d*x])/d + (2*a*b^3*Tan[c + d*x]^2)/d + (b^4*Tan[c + d*x]^3)/(3*d)}
{Csc[c + d*x]^3*(a + b*Tan[c + d*x])^4, x, 11, -((a^4*ArcTanh[Cos[c + d*x]])/(2*d)) - (6*a^2*b^2*ArcTanh[Cos[c + d*x]])/d + (4*a^3*b*ArcTanh[Sin[c + d*x]])/d + (2*a*b^3*ArcTanh[Sin[c + d*x]])/d - (4*a^3*b*Csc[c + d*x])/d - (a^4*Cot[c + d*x]*Csc[c + d*x])/(2*d) + (6*a^2*b^2*Sec[c + d*x])/d + (b^4*Sec[c + d*x]^3)/(3*d) + (2*a*b^3*Sec[c + d*x]*Tan[c + d*x])/d}
{Csc[c + d*x]^4*(a + b*Tan[c + d*x])^4, x, 3, -((a^2*(a^2 + 6*b^2)*Cot[c + d*x])/d) - (2*a^3*b*Cot[c + d*x]^2)/d - (a^4*Cot[c + d*x]^3)/(3*d) + (4*a*b*(a^2 + b^2)*Log[Tan[c + d*x]])/d + (b^2*(6*a^2 + b^2)*Tan[c + d*x])/d + (2*a*b^3*Tan[c + d*x]^2)/d + (b^4*Tan[c + d*x]^3)/(3*d)}
{Csc[c + d*x]^5*(a + b*Tan[c + d*x])^4, x, 17, -((3*a^4*ArcTanh[Cos[c + d*x]])/(8*d)) - (9*a^2*b^2*ArcTanh[Cos[c + d*x]])/d - (b^4*ArcTanh[Cos[c + d*x]])/d + (4*a^3*b*ArcTanh[Sin[c + d*x]])/d + (6*a*b^3*ArcTanh[Sin[c + d*x]])/d - (4*a^3*b*Csc[c + d*x])/d - (6*a*b^3*Csc[c + d*x])/d - (3*a^4*Cot[c + d*x]*Csc[c + d*x])/(8*d) - (4*a^3*b*Csc[c + d*x]^3)/(3*d) - (a^4*Cot[c + d*x]*Csc[c + d*x]^3)/(4*d) + (9*a^2*b^2*Sec[c + d*x])/d + (b^4*Sec[c + d*x])/d - (3*a^2*b^2*Csc[c + d*x]^2*Sec[c + d*x])/d + (2*a*b^3*Csc[c + d*x]*Sec[c + d*x]^2)/d + (b^4*Sec[c + d*x]^3)/(3*d)}
{Csc[c + d*x]^6*(a + b*Tan[c + d*x])^4, x, 3, -(((a^4 + 12*a^2*b^2 + b^4)*Cot[c + d*x])/d) - (2*a*b*(2*a^2 + b^2)*Cot[c + d*x]^2)/d - (2*a^2*(a^2 + 3*b^2)*Cot[c + d*x]^3)/(3*d) - (a^3*b*Cot[c + d*x]^4)/d - (a^4*Cot[c + d*x]^5)/(5*d) + (4*a*b*(a^2 + 2*b^2)*Log[Tan[c + d*x]])/d + (2*b^2*(3*a^2 + b^2)*Tan[c + d*x])/d + (2*a*b^3*Tan[c + d*x]^2)/d + (b^4*Tan[c + d*x]^3)/(3*d)}
{Csc[c + d*x]^7*(a + b*Tan[c + d*x])^4, x, 22, -((5*a^4*ArcTanh[Cos[c + d*x]])/(16*d)) - (45*a^2*b^2*ArcTanh[Cos[c + d*x]])/(4*d) - (5*b^4*ArcTanh[Cos[c + d*x]])/(2*d) + (4*a^3*b*ArcTanh[Sin[c + d*x]])/d + (10*a*b^3*ArcTanh[Sin[c + d*x]])/d - (4*a^3*b*Csc[c + d*x])/d - (10*a*b^3*Csc[c + d*x])/d - (5*a^4*Cot[c + d*x]*Csc[c + d*x])/(16*d) - (4*a^3*b*Csc[c + d*x]^3)/(3*d) - (10*a*b^3*Csc[c + d*x]^3)/(3*d) - (5*a^4*Cot[c + d*x]*Csc[c + d*x]^3)/(24*d) - (4*a^3*b*Csc[c + d*x]^5)/(5*d) - (a^4*Cot[c + d*x]*Csc[c + d*x]^5)/(6*d) + (45*a^2*b^2*Sec[c + d*x])/(4*d) + (5*b^4*Sec[c + d*x])/(2*d) - (15*a^2*b^2*Csc[c + d*x]^2*Sec[c + d*x])/(4*d) - (3*a^2*b^2*Csc[c + d*x]^4*Sec[c + d*x])/(2*d) + (2*a*b^3*Csc[c + d*x]^3*Sec[c + d*x]^2)/d + (5*b^4*Sec[c + d*x]^3)/(6*d) - (b^4*Csc[c + d*x]^2*Sec[c + d*x]^3)/(2*d)}


(* ::Subsubsection::Closed:: *)
(*n<0*)


{Sin[c + d*x]^m/(a + b*Tan[c + d*x]), x, 1, Int[(Cos[c + d*x]*Sin[c + d*x]^m)/(a*Cos[c + d*x] + b*Sin[c + d*x]), x]}

{Sin[c + d*x]^5/(a + b*Tan[c + d*x]), x, 12, (a^5*b*ArcTanh[(b*Cos[c + d*x] - a*Sin[c + d*x])/Sqrt[a^2 + b^2]])/((a^2 + b^2)^(7/2)*d) + (a^3*b^2*Cos[c + d*x])/((a^2 + b^2)^3*d) + (a*b^2*Cos[c + d*x])/((a^2 + b^2)^2*d) - (a*Cos[c + d*x])/((a^2 + b^2)*d) - (a*b^2*Cos[c + d*x]^3)/(3*(a^2 + b^2)^2*d) + (2*a*Cos[c + d*x]^3)/(3*(a^2 + b^2)*d) - (a*Cos[c + d*x]^5)/(5*(a^2 + b^2)*d) + (a^4*b*Sin[c + d*x])/((a^2 + b^2)^3*d) + (a^2*b*Sin[c + d*x]^3)/(3*(a^2 + b^2)^2*d) + (b*Sin[c + d*x]^5)/(5*(a^2 + b^2)*d)}
{Sin[c + d*x]^4/(a + b*Tan[c + d*x]), x, 11, (a^5*x)/(a^2 + b^2)^3 + (3*a*x)/(8*(a^2 + b^2)) - (a*(2*a^2 + b^2)*x)/(2*(a^2 + b^2)^2) + (a^4*b*Log[a + b*Tan[c + d*x]])/((a^2 + b^2)^3*d) - (a^4*b*Log[1 + Tan[c + d*x]^2])/(2*(a^2 + b^2)^3*d) + (b + a*Tan[c + d*x])/(4*(a^2 + b^2)*d*(1 + Tan[c + d*x]^2)^2) + (3*a*Tan[c + d*x])/(8*(a^2 + b^2)*d*(1 + Tan[c + d*x]^2)) - ((2*a^2 + b^2)*(b + a*Tan[c + d*x]))/(2*(a^2 + b^2)^2*d*(1 + Tan[c + d*x]^2))}
{Sin[c + d*x]^3/(a + b*Tan[c + d*x]), x, 9, (a^3*b*ArcTanh[(b*Cos[c + d*x] - a*Sin[c + d*x])/Sqrt[a^2 + b^2]])/((a^2 + b^2)^(5/2)*d) + (a*b^2*Cos[c + d*x])/((a^2 + b^2)^2*d) - (a*Cos[c + d*x])/((a^2 + b^2)*d) + (a*Cos[c + d*x]^3)/(3*(a^2 + b^2)*d) + (a^2*b*Sin[c + d*x])/((a^2 + b^2)^2*d) + (b*Sin[c + d*x]^3)/(3*(a^2 + b^2)*d)}
{Sin[c + d*x]^2/(a + b*Tan[c + d*x]), x, 8, (a^3*x)/(a^2 + b^2)^2 - (a*x)/(2*(a^2 + b^2)) + (a^2*b*Log[a + b*Tan[c + d*x]])/((a^2 + b^2)^2*d) - (a^2*b*Log[1 + Tan[c + d*x]^2])/(2*(a^2 + b^2)^2*d) - (b + a*Tan[c + d*x])/(2*(a^2 + b^2)*d*(1 + Tan[c + d*x]^2))}
{Sin[c + d*x]^1/(a + b*Tan[c + d*x]), x, 6, (a*b*ArcTanh[(b*Cos[c + d*x] - a*Sin[c + d*x])/Sqrt[a^2 + b^2]])/((a^2 + b^2)^(3/2)*d) - (a*Cos[c + d*x])/((a^2 + b^2)*d) + (b*Sin[c + d*x])/((a^2 + b^2)*d)}
{Csc[c + d*x]^1/(a + b*Tan[c + d*x]), x, 6, -(ArcTanh[Cos[c + d*x]]/(a*d)) + (b*ArcTanh[(b*Cos[c + d*x] - a*Sin[c + d*x])/Sqrt[a^2 + b^2]])/(a*Sqrt[a^2 + b^2]*d)}
{Csc[c + d*x]^2/(a + b*Tan[c + d*x]), x, 3, -(Cot[c + d*x]/(a*d)) - (b*Log[Tan[c + d*x]])/(a^2*d) + (b*Log[a + b*Tan[c + d*x]])/(a^2*d)}
{Csc[c + d*x]^3/(a + b*Tan[c + d*x]), x, 13, -(ArcTanh[Cos[c + d*x]]/(2*a*d)) - (b^2*ArcTanh[Cos[c + d*x]])/(a^3*d) + (b*Sqrt[a^2 + b^2]*ArcTanh[(b*Cos[c + d*x] - a*Sin[c + d*x])/Sqrt[a^2 + b^2]])/(a^3*d) + (b*Csc[c + d*x])/(a^2*d) - (Cot[c + d*x]*Csc[c + d*x])/(2*a*d)}
{Csc[c + d*x]^4/(a + b*Tan[c + d*x]), x, 3, -(((a^2 + b^2)*Cot[c + d*x])/(a^3*d)) + (b*Cot[c + d*x]^2)/(2*a^2*d) - Cot[c + d*x]^3/(3*a*d) - (b*(a^2 + b^2)*Log[Tan[c + d*x]])/(a^4*d) + (b*(a^2 + b^2)*Log[a + b*Tan[c + d*x]])/(a^4*d)}
(* {Csc[c + d*x]^5/(a + b*Tan[c + d*x]), x, 25, -((3*ArcTanh[Cos[c + d*x]])/(8*a*d)) - (3*b^2*ArcTanh[Cos[c + d*x]])/(2*a^3*d) - (b^4*ArcTanh[Cos[c + d*x]])/(a^5*d) - (b*ArcTanh[Sin[c + d*x]])/(a^2*d) - (b^3*ArcTanh[Sin[c + d*x]])/(a^4*d) + (b*(a^2 + b^2)*ArcTanh[Sin[c + d*x]])/(a^4*d) + (b*(a^2 + b^2)^(3/2)*ArcTanh[(b*Cos[c + d*x] - a*Sin[c + d*x])/Sqrt[a^2 + b^2]])/(a^5*d) + (b*Csc[c + d*x])/(a^2*d) + (3*b^3*Csc[c + d*x])/(2*a^4*d) - (3*Cot[c + d*x]*Csc[c + d*x])/(8*a*d) + (b*Csc[c + d*x]^3)/(3*a^2*d) - (Cot[c + d*x]*Csc[c + d*x]^3)/(4*a*d) + (3*b^2*Sec[c + d*x])/(2*a^3*d) + (b^4*Sec[c + d*x])/(a^5*d) - (b^2*(a^2 + b^2)*Sec[c + d*x])/(a^5*d) - (b^2*Csc[c + d*x]^2*Sec[c + d*x])/(2*a^3*d) - (b^3*Csc[c + d*x]*Sec[c + d*x]^2)/(2*a^4*d) + (b^3*Sec[c + d*x]*Tan[c + d*x])/(2*a^4*d)} *)
{Csc[c + d*x]^6/(a + b*Tan[c + d*x]), x, 3, -(((a^2 + b^2)^2*Cot[c + d*x])/(a^5*d)) + (b*(2*a^2 + b^2)*Cot[c + d*x]^2)/(2*a^4*d) - ((2*a^2 + b^2)*Cot[c + d*x]^3)/(3*a^3*d) + (b*Cot[c + d*x]^4)/(4*a^2*d) - Cot[c + d*x]^5/(5*a*d) - (b*(a^2 + b^2)^2*Log[Tan[c + d*x]])/(a^6*d) + (b*(a^2 + b^2)^2*Log[a + b*Tan[c + d*x]])/(a^6*d)}


{Sin[c + d*x]^m/(a + b*Tan[c + d*x])^2, x, 1, Int[(Cos[c + d*x]^2*Sin[c + d*x]^m)/(a*Cos[c + d*x] + b*Sin[c + d*x])^2, x]}

{Sin[c + d*x]^6/(a + b*Tan[c + d*x])^2, x, 15, (a^6*(a^2 - 7*b^2)*x)/(a^2 + b^2)^5 - (5*(a^2 - b^2)*x)/(16*(a^2 + b^2)^2) + (3*(3*a^4 - 3*a^2*b^2 - 2*b^4)*x)/(8*(a^2 + b^2)^3) - ((3*a^6 - 6*a^4*b^2 - 4*a^2*b^4 - b^6)*x)/(2*(a^2 + b^2)^4) + (2*a^5*b*(a^2 - 3*b^2)*Log[a + b*Tan[c + d*x]])/((a^2 + b^2)^5*d) - (a^5*b*(a^2 - 3*b^2)*Log[1 + Tan[c + d*x]^2])/((a^2 + b^2)^5*d) - (a^6*b)/((a^2 + b^2)^4*d*(a + b*Tan[c + d*x])) - (2*a*b + (a^2 - b^2)*Tan[c + d*x])/(6*(a^2 + b^2)^2*d*(1 + Tan[c + d*x]^2)^3) - (5*(a^2 - b^2)*Tan[c + d*x])/(24*(a^2 + b^2)^2*d*(1 + Tan[c + d*x]^2)^2) + (2*a*b*(3*a^2 + b^2) + (3*a^4 - 3*a^2*b^2 - 2*b^4)*Tan[c + d*x])/(4*(a^2 + b^2)^3*d*(1 + Tan[c + d*x]^2)^2) - (5*(a^2 - b^2)*Tan[c + d*x])/(16*(a^2 + b^2)^2*d*(1 + Tan[c + d*x]^2)) + (3*(3*a^4 - 3*a^2*b^2 - 2*b^4)*Tan[c + d*x])/(8*(a^2 + b^2)^3*d*(1 + Tan[c + d*x]^2)) - (6*a^5*b + (3*a^6 - 6*a^4*b^2 - 4*a^2*b^4 - b^6)*Tan[c + d*x])/(2*(a^2 + b^2)^4*d*(1 + Tan[c + d*x]^2))}
{Sin[c + d*x]^5/(a + b*Tan[c + d*x])^2, x, 0, (5*Sec[c + d*x]^2*(a*Cos[c + d*x] + b*Sin[c + d*x])*(a*(a^2 + b^2) + 2*b*Sqrt[a^2 + b^2]*ArcTanh[(-b + a*Tan[(1/2)*(c + d*x)])/Sqrt[a^2 + b^2]]*(a*Cos[c + d*x] + b*Sin[c + d*x])))/(64*(a^2 + b^2)^2*d*(a + b*Tan[c + d*x])^2) + (1/(64*(a^2 + b^2)^3*d*(a + b*Tan[c + d*x])^2))*(Sec[c + d*x]^2*(a*Cos[c + d*x] + b*Sin[c + d*x])*(6*b*(-3*a^2 + b^2)*Sqrt[a^2 + b^2]*ArcTanh[(-b + a*Tan[(1/2)*(c + d*x)])/Sqrt[a^2 + b^2]]*(a*Cos[c + d*x] + b*Sin[c + d*x]) - (a^2 + b^2)*(3*a*(a^2 - 3*b^2) + 2*a*(a^2 + b^2)*Cos[2*(c + d*x)] - 2*b*(a^2 + b^2)*Sin[2*(c + d*x)]))) - (3*Sec[c + d*x]^2*(a*Cos[c + d*x] + b*Sin[c + d*x])^2*((10*b*(5*a^4 - 10*a^2*b^2 + b^4)*ArcTanh[(-b + a*Tan[(1/2)*(c + d*x)])/Sqrt[a^2 + b^2]])/(a^2 + b^2)^(7/2) + (8*(a^4 - 6*a^2*b^2 + b^4)*Cos[c + d*x])/(a^2 + b^2)^3 - (4*(a^2 - b^2)*Cos[3*(c + d*x)])/(3*(a^2 + b^2)^2) - (32*a*b*(a^2 - b^2)*Sin[c + d*x])/(a^2 + b^2)^3 + (a*(a^4 - 10*a^2*b^2 + 5*b^4))/((a^2 + b^2)^3*(a*Cos[c + d*x] + b*Sin[c + d*x])) + (8*a*b*Sin[3*(c + d*x)])/(3*(a^2 + b^2)^2)))/(64*d*(a + b*Tan[c + d*x])^2) + (1/(64*d*(a + b*Tan[c + d*x])^2))*(Sec[c + d*x]^2*(a*Cos[c + d*x] + b*Sin[c + d*x])^2*((14*b*(-7*a^6 + 35*a^4*b^2 - 21*a^2*b^4 + b^6)*ArcTanh[(-b + a*Tan[(1/2)*(c + d*x)])/Sqrt[a^2 + b^2]])/(a^2 + b^2)^(9/2) - (12*(a^6 - 15*a^4*b^2 + 15*a^2*b^4 - b^6)*Cos[c + d*x])/(a^2 + b^2)^4 + (8*(a^4 - 6*a^2*b^2 + b^4)*Cos[3*(c + d*x)])/(3*(a^2 + b^2)^3) - (4*(a^2 - b^2)*Cos[5*(c + d*x)])/(5*(a^2 + b^2)^2) + (24*a*b*(3*a^4 - 10*a^2*b^2 + 3*b^4)*Sin[c + d*x])/(a^2 + b^2)^4 - (a*(a^6 - 21*a^4*b^2 + 35*a^2*b^4 - 7*b^6))/((a^2 + b^2)^4*(a*Cos[c + d*x] + b*Sin[c + d*x])) - (32*a*b*(a^2 - b^2)*Sin[3*(c + d*x)])/(3*(a^2 + b^2)^3) + (8*a*b*Sin[5*(c + d*x)])/(5*(a^2 + b^2)^2)))}
{Sin[c + d*x]^4/(a + b*Tan[c + d*x])^2, x, 11, (a^4*(a^2 - 5*b^2)*x)/(a^2 + b^2)^4 + (3*(a^2 - b^2)*x)/(8*(a^2 + b^2)^2) - ((2*a^4 - 3*a^2*b^2 - b^4)*x)/(2*(a^2 + b^2)^3) + (2*a^3*b*(a^2 - 2*b^2)*Log[a + b*Tan[c + d*x]])/((a^2 + b^2)^4*d) - (a^3*b*(a^2 - 2*b^2)*Log[1 + Tan[c + d*x]^2])/((a^2 + b^2)^4*d) - (a^4*b)/((a^2 + b^2)^3*d*(a + b*Tan[c + d*x])) + (2*a*b + (a^2 - b^2)*Tan[c + d*x])/(4*(a^2 + b^2)^2*d*(1 + Tan[c + d*x]^2)^2) + (3*(a^2 - b^2)*Tan[c + d*x])/(8*(a^2 + b^2)^2*d*(1 + Tan[c + d*x]^2)) - (4*a^3*b + (2*a^4 - 3*a^2*b^2 - b^4)*Tan[c + d*x])/(2*(a^2 + b^2)^3*d*(1 + Tan[c + d*x]^2))}
{Sin[c + d*x]^3/(a + b*Tan[c + d*x])^2, x, 31, (2*a^4*b*ArcTanh[(b*Cos[c + d*x] - a*Sin[c + d*x])/Sqrt[a^2 + b^2]])/((a^2 + b^2)^(7/2)*d) - (3*a^2*b^3*ArcTanh[(b*Cos[c + d*x] - a*Sin[c + d*x])/Sqrt[a^2 + b^2]])/((a^2 + b^2)^(7/2)*d) + (4*a^2*b^2*Cos[c + d*x])/((a^2 + b^2)^3*d) - (a^2*Cos[c + d*x])/((a^2 + b^2)^2*d) + (a^2*Cos[c + d*x]^3)/(3*(a^2 + b^2)^2*d) - (b^2*Cos[c + d*x]^3)/(3*(a^2 + b^2)^2*d) + (2*a^3*b*Sin[c + d*x])/((a^2 + b^2)^3*d) - (2*a*b^3*Sin[c + d*x])/((a^2 + b^2)^3*d) + (2*a*b*Sin[c + d*x]^3)/(3*(a^2 + b^2)^2*d) + (a^3*b^2)/((a^2 + b^2)^3*d*(a*Cos[c + d*x] + b*Sin[c + d*x]))}
{Sin[c + d*x]^2/(a + b*Tan[c + d*x])^2, x, 8, (a^2*(a^2 - 3*b^2)*x)/(a^2 + b^2)^3 - ((a^2 - b^2)*x)/(2*(a^2 + b^2)^2) + (2*a*b*(a^2 - b^2)*Log[a + b*Tan[c + d*x]])/((a^2 + b^2)^3*d) - (a*b*(a^2 - b^2)*Log[1 + Tan[c + d*x]^2])/((a^2 + b^2)^3*d) - (a^2*b)/((a^2 + b^2)^2*d*(a + b*Tan[c + d*x])) - (2*a*b + (a^2 - b^2)*Tan[c + d*x])/(2*(a^2 + b^2)^2*d*(1 + Tan[c + d*x]^2))}
{Sin[c + d*x]^1/(a + b*Tan[c + d*x])^2, x, 14, (2*a^2*b*ArcTanh[(b*Cos[c + d*x] - a*Sin[c + d*x])/Sqrt[a^2 + b^2]])/((a^2 + b^2)^(5/2)*d) - (b^3*ArcTanh[(b*Cos[c + d*x] - a*Sin[c + d*x])/Sqrt[a^2 + b^2]])/((a^2 + b^2)^(5/2)*d) - (a^2*Cos[c + d*x])/((a^2 + b^2)^2*d) + (b^2*Cos[c + d*x])/((a^2 + b^2)^2*d) + (2*a*b*Sin[c + d*x])/((a^2 + b^2)^2*d) + (a*b^2)/((a^2 + b^2)^2*d*(a*Cos[c + d*x] + b*Sin[c + d*x]))}
{Csc[c + d*x]^1/(a + b*Tan[c + d*x])^2, x, 9, -(ArcTanh[Cos[c + d*x]]/(a^2*d)) + (b*ArcTanh[(b*Cos[c + d*x] - a*Sin[c + d*x])/Sqrt[a^2 + b^2]])/((a^2 + b^2)^(3/2)*d) + (b*ArcTanh[(b*Cos[c + d*x] - a*Sin[c + d*x])/Sqrt[a^2 + b^2]])/(a^2*Sqrt[a^2 + b^2]*d) + b^2/(a*(a^2 + b^2)*d*(a*Cos[c + d*x] + b*Sin[c + d*x]))}
{Csc[c + d*x]^2/(a + b*Tan[c + d*x])^2, x, 3, -(Cot[c + d*x]/(a^2*d)) - (2*b*Log[Tan[c + d*x]])/(a^3*d) + (2*b*Log[a + b*Tan[c + d*x]])/(a^3*d) - b/(a^2*d*(a + b*Tan[c + d*x]))}
{Csc[c + d*x]^3/(a + b*Tan[c + d*x])^2, x, 17, -(ArcTanh[Cos[c + d*x]]/(2*a^2*d)) - (3*b^2*ArcTanh[Cos[c + d*x]])/(a^4*d) - (b*ArcTanh[(b*Cos[c + d*x] - a*Sin[c + d*x])/Sqrt[a^2 + b^2]])/(a^2*Sqrt[a^2 + b^2]*d) + (3*b*Sqrt[a^2 + b^2]*ArcTanh[(b*Cos[c + d*x] - a*Sin[c + d*x])/Sqrt[a^2 + b^2]])/(a^4*d) + (2*b*Csc[c + d*x])/(a^3*d) - (Cot[c + d*x]*Csc[c + d*x])/(2*a^2*d) + b^2/(a^3*d*(a*Cos[c + d*x] + b*Sin[c + d*x]))}
{Csc[c + d*x]^4/(a + b*Tan[c + d*x])^2, x, 3, -(((a^2 + 3*b^2)*Cot[c + d*x])/(a^4*d)) + (b*Cot[c + d*x]^2)/(a^3*d) - Cot[c + d*x]^3/(3*a^2*d) - (2*b*(a^2 + 2*b^2)*Log[Tan[c + d*x]])/(a^5*d) + (2*b*(a^2 + 2*b^2)*Log[a + b*Tan[c + d*x]])/(a^5*d) - (b*(a^2 + b^2))/(a^4*d*(a + b*Tan[c + d*x]))}


{Sin[c + d*x]^m/(a + b*Tan[c + d*x])^3, x, 1, Int[(Cos[c + d*x]^3*Sin[c + d*x]^m)/(a*Cos[c + d*x] + b*Sin[c + d*x])^3, x]}

{Sin[c + d*x]^6/(a + b*Tan[c + d*x])^3, x, 15, -((3*a^5*(a^2 - 7*b^2)*x)/(2*(a^2 + b^2)^5)) - (5*a*(a^2 - 3*b^2)*x)/(16*(a^2 + b^2)^3) + (9*a*(a^4 - 4*a^2*b^2 - b^4)*x)/(8*(a^2 + b^2)^4) + (a^5*(a^4 - 18*a^2*b^2 + 21*b^4)*x)/(a^2 + b^2)^6 + (a^4*b*(3*a^4 - 22*a^2*b^2 + 15*b^4)*Log[a + b*Tan[c + d*x]])/((a^2 + b^2)^6*d) - (a^4*b*(3*a^4 - 22*a^2*b^2 + 15*b^4)*Log[1 + Tan[c + d*x]^2])/(2*(a^2 + b^2)^6*d) - (a^6*b)/(2*(a^2 + b^2)^4*d*(a + b*Tan[c + d*x])^2) - (2*a^5*b*(a^2 - 3*b^2))/((a^2 + b^2)^5*d*(a + b*Tan[c + d*x])) - (b*(3*a^2 - b^2) + a*(a^2 - 3*b^2)*Tan[c + d*x])/(6*(a^2 + b^2)^3*d*(1 + Tan[c + d*x]^2)^3) - (5*a*(a^2 - 3*b^2)*Tan[c + d*x])/(24*(a^2 + b^2)^3*d*(1 + Tan[c + d*x]^2)^2) + (b*(9*a^4 - 4*a^2*b^2 - b^4) + 3*a*(a^4 - 4*a^2*b^2 - b^4)*Tan[c + d*x])/(4*(a^2 + b^2)^4*d*(1 + Tan[c + d*x]^2)^2) - (5*a*(a^2 - 3*b^2)*Tan[c + d*x])/(16*(a^2 + b^2)^3*d*(1 + Tan[c + d*x]^2)) + (9*a*(a^4 - 4*a^2*b^2 - b^4)*Tan[c + d*x])/(8*(a^2 + b^2)^4*d*(1 + Tan[c + d*x]^2)) - (3*a^4*(b*(3*a^2 - 5*b^2) + a*(a^2 - 7*b^2)*Tan[c + d*x]))/(2*(a^2 + b^2)^5*d*(1 + Tan[c + d*x]^2))}
{Sin[c + d*x]^5/(a + b*Tan[c + d*x])^3, x, 0, (3*Sec[c + d*x]^3*(a*Cos[c + d*x] + b*Sin[c + d*x])*(6*a*b*Sqrt[a^2 + b^2]*ArcTanh[(-b + a*Tan[(1/2)*(c + d*x)])/Sqrt[a^2 + b^2]]*(a*Cos[c + d*x] + b*Sin[c + d*x])^2 + (a^2 + b^2)*(a*(2*a^2 - b^2)*Cos[c + d*x] + b*(a^2 - 2*b^2)*Sin[c + d*x])))/(64*(a^2 + b^2)^3*d*(a + b*Tan[c + d*x])^3) + (1/(64*d*(a + b*Tan[c + d*x])^3))*(Sec[c + d*x]^3*(a*Cos[c + d*x] + b*Sin[c + d*x])^3*(-((70*a*b*(3*a^4 - 10*a^2*b^2 + 3*b^4)*ArcTanh[(-b + a*Tan[(1/2)*(c + d*x)])/Sqrt[a^2 + b^2]])/(a^2 + b^2)^(9/2)) - (24*a*(a^4 - 10*a^2*b^2 + 5*b^4)*Cos[c + d*x])/(a^2 + b^2)^4 + (8*a*(a^2 - 3*b^2)*Cos[3*(c + d*x)])/(3*(a^2 + b^2)^3) + (24*b*(5*a^4 - 10*a^2*b^2 + b^4)*Sin[c + d*x])/(a^2 + b^2)^4 - (b*(-3*a^4 + 10*a^2*b^2 - 3*b^4)*Sin[c + d*x])/((a^2 + b^2)^3*(a*Cos[c + d*x] + b*Sin[c + d*x])^2) - (6*a^6 - 87*a^4*b^2 + 80*a^2*b^4 - 3*b^6)/((a^2 + b^2)^4*(a*Cos[c + d*x] + b*Sin[c + d*x])) + (8*b*(-3*a^2 + b^2)*Sin[3*(c + d*x)])/(3*(a^2 + b^2)^3))) + (Sec[c + d*x]^3*(a*Cos[c + d*x] + b*Sin[c + d*x])^3*((60*a*b*(a^2 - b^2)*ArcTanh[(-b + a*Tan[(1/2)*(c + d*x)])/Sqrt[a^2 + b^2]])/(a^2 + b^2)^(7/2) + (2*(5*a^3*(a^2 - 5*b^2)*Cos[c + d*x] + a*(a^2 + b^2)^2*Cos[3*(c + d*x)] - b*(-5*b^2*(-5*a^2 + b^2)*Sin[c + d*x] + (a^2 + b^2)^2*Sin[3*(c + d*x)])))/((a^2 + b^2)^3*(a*Cos[c + d*x] + b*Sin[c + d*x])^2)))/(64*d*(a + b*Tan[c + d*x])^3) - (1/(320*(a^2 + b^2)^6*d*(a + b*Tan[c + d*x])^3))*(Sec[c + d*x]^3*(a*Cos[c + d*x] + b*Sin[c + d*x])*(1260*a*b*Sqrt[a^2 + b^2]*(a^6 - 7*a^4*b^2 + 7*a^2*b^4 - b^6)*ArcTanh[(-b + a*Tan[(1/2)*(c + d*x)])/Sqrt[a^2 + b^2]]*(a*Cos[c + d*x] + b*Sin[c + d*x])^2 + (a^2 + b^2)*(105*a*(a^8 - 26*a^6*b^2 + 56*a^4*b^4 - 14*a^2*b^6 - b^8)*Cos[c + d*x] + 21*a*(a^2 + b^2)^2*(a^4 - 10*a^2*b^2 + 5*b^4)*Cos[3*(c + d*x)] - 3*a^9*Cos[5*(c + d*x)] + 18*a^5*b^4*Cos[5*(c + d*x)] + 24*a^3*b^6*Cos[5*(c + d*x)] + 9*a*b^8*Cos[5*(c + d*x)] + a^9*Cos[7*(c + d*x)] + 4*a^7*b^2*Cos[7*(c + d*x)] + 6*a^5*b^4*Cos[7*(c + d*x)] + 4*a^3*b^6*Cos[7*(c + d*x)] + a*b^8*Cos[7*(c + d*x)] - 105*a^8*b*Sin[c + d*x] - 1470*a^6*b^3*Sin[c + d*x] + 5880*a^4*b^5*Sin[c + d*x] - 2730*a^2*b^7*Sin[c + d*x] + 105*b^9*Sin[c + d*x] - 105*a^8*b*Sin[3*(c + d*x)] + 294*a^4*b^5*Sin[3*(c + d*x)] + 168*a^2*b^7*Sin[3*(c + d*x)] - 21*b^9*Sin[3*(c + d*x)] + 9*a^8*b*Sin[5*(c + d*x)] + 24*a^6*b^3*Sin[5*(c + d*x)] + 18*a^4*b^5*Sin[5*(c + d*x)] - 3*b^9*Sin[5*(c + d*x)] - a^8*b*Sin[7*(c + d*x)] - 4*a^6*b^3*Sin[7*(c + d*x)] - 6*a^4*b^5*Sin[7*(c + d*x)] - 4*a^2*b^7*Sin[7*(c + d*x)] - b^9*Sin[7*(c + d*x)])))}
{Sin[c + d*x]^4/(a + b*Tan[c + d*x])^3, x, 11, -((a^3*(a^2 - 5*b^2)*x)/(a^2 + b^2)^4) + (3*a*(a^2 - 3*b^2)*x)/(8*(a^2 + b^2)^3) + (a^3*(a^4 - 13*a^2*b^2 + 10*b^4)*x)/(a^2 + b^2)^5 + (3*a^2*b*(a^4 - 5*a^2*b^2 + 2*b^4)*Log[a + b*Tan[c + d*x]])/((a^2 + b^2)^5*d) - (3*a^2*b*(a^4 - 5*a^2*b^2 + 2*b^4)*Log[1 + Tan[c + d*x]^2])/(2*(a^2 + b^2)^5*d) - (a^4*b)/(2*(a^2 + b^2)^3*d*(a + b*Tan[c + d*x])^2) - (2*a^3*b*(a^2 - 2*b^2))/((a^2 + b^2)^4*d*(a + b*Tan[c + d*x])) + (b*(3*a^2 - b^2) + a*(a^2 - 3*b^2)*Tan[c + d*x])/(4*(a^2 + b^2)^3*d*(1 + Tan[c + d*x]^2)^2) + (3*a*(a^2 - 3*b^2)*Tan[c + d*x])/(8*(a^2 + b^2)^3*d*(1 + Tan[c + d*x]^2)) - (a^2*(3*b*(a^2 - b^2) + a*(a^2 - 5*b^2)*Tan[c + d*x]))/((a^2 + b^2)^4*d*(1 + Tan[c + d*x]^2))}
{Sin[c + d*x]^3/(a + b*Tan[c + d*x])^3, x, 99, (3*a^5*b*ArcTanh[(b*Cos[c + d*x] - a*Sin[c + d*x])/Sqrt[a^2 + b^2]])/((a^2 + b^2)^(9/2)*d) - (23*a^3*b^3*ArcTanh[(b*Cos[c + d*x] - a*Sin[c + d*x])/Sqrt[a^2 + b^2]])/(2*(a^2 + b^2)^(9/2)*d) + (3*a*b^5*ArcTanh[(b*Cos[c + d*x] - a*Sin[c + d*x])/Sqrt[a^2 + b^2]])/((a^2 + b^2)^(9/2)*d) + (9*a^3*b^2*Cos[c + d*x])/((a^2 + b^2)^4*d) - (3*a*b^4*Cos[c + d*x])/((a^2 + b^2)^4*d) - (a^3*Cos[c + d*x])/((a^2 + b^2)^3*d) + (a^3*Cos[c + d*x]^3)/(3*(a^2 + b^2)^3*d) - (a*b^2*Cos[c + d*x]^3)/((a^2 + b^2)^3*d) + (3*a^4*b*Sin[c + d*x])/((a^2 + b^2)^4*d) - (9*a^2*b^3*Sin[c + d*x])/((a^2 + b^2)^4*d) + (b^3*Sin[c + d*x])/((a^2 + b^2)^3*d) + (a^2*b*Sin[c + d*x]^3)/((a^2 + b^2)^3*d) - (b^3*Sin[c + d*x]^3)/(3*(a^2 + b^2)^3*d) + (a^3*b^3*(b*Cos[c + d*x] - a*Sin[c + d*x]))/(2*(a^2 + b^2)^4*d*(a*Cos[c + d*x] + b*Sin[c + d*x])^2) + (3*a^4*b^2)/((a^2 + b^2)^4*d*(a*Cos[c + d*x] + b*Sin[c + d*x])) - (3*a^2*b^4)/((a^2 + b^2)^4*d*(a*Cos[c + d*x] + b*Sin[c + d*x]))}
{Sin[c + d*x]^2/(a + b*Tan[c + d*x])^3, x, 8, -((a*(a^2 - 3*b^2)*x)/(2*(a^2 + b^2)^3)) + (a*(a^4 - 8*a^2*b^2 + 3*b^4)*x)/(a^2 + b^2)^4 + (b*(3*a^4 - 8*a^2*b^2 + b^4)*Log[a + b*Tan[c + d*x]])/((a^2 + b^2)^4*d) - (b*(3*a^4 - 8*a^2*b^2 + b^4)*Log[1 + Tan[c + d*x]^2])/(2*(a^2 + b^2)^4*d) - (a^2*b)/(2*(a^2 + b^2)^2*d*(a + b*Tan[c + d*x])^2) - (2*a*b*(a^2 - b^2))/((a^2 + b^2)^3*d*(a + b*Tan[c + d*x])) - (b*(3*a^2 - b^2) + a*(a^2 - 3*b^2)*Tan[c + d*x])/(2*(a^2 + b^2)^3*d*(1 + Tan[c + d*x]^2))}
{Sin[c + d*x]^1/(a + b*Tan[c + d*x])^3, x, 0, -((1/(4*(a^2 + b^2)^(7/2)*d*(a + b*Tan[c + d*x])^3))*(Sec[c + d*x]^3*(a*Cos[c + d*x] + b*Sin[c + d*x])*(12*a*b*(2*a^2 - 3*b^2)*ArcTanh[(-b + a*Tan[(1/2)*(c + d*x)])/Sqrt[a^2 + b^2]]*(a*Cos[c + d*x] + b*Sin[c + d*x])^2 + Sqrt[a^2 + b^2]*(a*(3*a^4 - 26*a^2*b^2 + b^4)*Cos[c + d*x] + a*(a^2 + b^2)^2*Cos[3*(c + d*x)] - 2*b*(a^4 + 13*a^2*b^2 - 3*b^4 + (a^2 + b^2)^2*Cos[2*(c + d*x)])*Sin[c + d*x]))))}
{Csc[c + d*x]^1/(a + b*Tan[c + d*x])^3, x, 0, (1/(2*a^3*d*(a + b*Tan[c + d*x])^3))*(Sec[c + d*x]^2*(a*Cos[c + d*x] + b*Sin[c + d*x])*((3*a*b^2*(2*a^2 + b^2)*Sec[c + d*x]*(a*Cos[c + d*x] + b*Sin[c + d*x]))/(a^2 + b^2)^2 - (2*b*(6*a^4 + 5*a^2*b^2 + 2*b^4)*ArcTanh[(-b + a*Tan[(1/2)*(c + d*x)])/Sqrt[a^2 + b^2]]*Sec[c + d*x]*(a*Cos[c + d*x] + b*Sin[c + d*x])^2)/(a^2 + b^2)^(5/2) - 2*Log[Cos[(1/2)*(c + d*x)]]*Sec[c + d*x]*(a*Cos[c + d*x] + b*Sin[c + d*x])^2 + 2*Log[Sin[(1/2)*(c + d*x)]]*Sec[c + d*x]*(a*Cos[c + d*x] + b*Sin[c + d*x])^2 - (a*b^3*Tan[c + d*x])/(a^2 + b^2)))}
{Csc[c + d*x]^2/(a + b*Tan[c + d*x])^3, x, 3, -(Cot[c + d*x]/(a^3*d)) - (3*b*Log[Tan[c + d*x]])/(a^4*d) + (3*b*Log[a + b*Tan[c + d*x]])/(a^4*d) - b/(2*a^2*d*(a + b*Tan[c + d*x])^2) - (2*b)/(a^3*d*(a + b*Tan[c + d*x]))}
{Csc[c + d*x]^3/(a + b*Tan[c + d*x])^3, x, 20, -(ArcTanh[Cos[c + d*x]]/(2*a^3*d)) - (6*b^2*ArcTanh[Cos[c + d*x]])/(a^5*d) + (b^3*ArcTanh[(b*Cos[c + d*x] - a*Sin[c + d*x])/Sqrt[a^2 + b^2]])/(2*a^3*(a^2 + b^2)^(3/2)*d) - (3*b*ArcTanh[(b*Cos[c + d*x] - a*Sin[c + d*x])/Sqrt[a^2 + b^2]])/(a^3*Sqrt[a^2 + b^2]*d) + (6*b*Sqrt[a^2 + b^2]*ArcTanh[(b*Cos[c + d*x] - a*Sin[c + d*x])/Sqrt[a^2 + b^2]])/(a^5*d) + (3*b*Csc[c + d*x])/(a^4*d) - (Cot[c + d*x]*Csc[c + d*x])/(2*a^3*d) + (b^3*(b*Cos[c + d*x] - a*Sin[c + d*x]))/(2*a^3*(a^2 + b^2)*d*(a*Cos[c + d*x] + b*Sin[c + d*x])^2) + (3*b^2)/(a^4*d*(a*Cos[c + d*x] + b*Sin[c + d*x]))}
{Csc[c + d*x]^4/(a + b*Tan[c + d*x])^3, x, 3, -(((a^2 + 6*b^2)*Cot[c + d*x])/(a^5*d)) + (3*b*Cot[c + d*x]^2)/(2*a^4*d) - Cot[c + d*x]^3/(3*a^3*d) - (b*(3*a^2 + 10*b^2)*Log[Tan[c + d*x]])/(a^6*d) + (b*(3*a^2 + 10*b^2)*Log[a + b*Tan[c + d*x]])/(a^6*d) - (b*(a^2 + b^2))/(2*a^4*d*(a + b*Tan[c + d*x])^2) - (2*b*(a^2 + 2*b^2))/(a^5*d*(a + b*Tan[c + d*x]))}


{Sin[c + d*x]^m/(a + b*Tan[c + d*x])^4, x, 1, Int[(Cos[c + d*x]^4*Sin[c + d*x]^m)/(a*Cos[c + d*x] + b*Sin[c + d*x])^4, x]}

{Sin[c + d*x]^6/(a + b*Tan[c + d*x])^4, x, 15, -((5*(a^4 - 6*a^2*b^2 + b^4)*x)/(16*(a^2 + b^2)^4)) - (a^4*(3*a^4 - 42*a^2*b^2 + 35*b^4)*x)/(2*(a^2 + b^2)^6) + (a^4*(a^6 - 33*a^4*b^2 + 91*a^2*b^4 - 35*b^6)*x)/(a^2 + b^2)^7 + (3*(3*a^6 - 25*a^4*b^2 + 5*a^2*b^4 + b^6)*x)/(8*(a^2 + b^2)^5) + (4*a^3*b*(a^6 - 13*a^4*b^2 + 21*a^2*b^4 - 5*b^6)*Log[a + b*Tan[c + d*x]])/((a^2 + b^2)^7*d) - (2*a^3*b*(a^6 - 13*a^4*b^2 + 21*a^2*b^4 - 5*b^6)*Log[1 + Tan[c + d*x]^2])/((a^2 + b^2)^7*d) - (a^6*b)/(3*(a^2 + b^2)^4*d*(a + b*Tan[c + d*x])^3) - (a^5*b*(a^2 - 3*b^2))/((a^2 + b^2)^5*d*(a + b*Tan[c + d*x])^2) - (a^4*b*(3*a^4 - 22*a^2*b^2 + 15*b^4))/((a^2 + b^2)^6*d*(a + b*Tan[c + d*x])) - (4*a*b*(a^2 - b^2) + (a^4 - 6*a^2*b^2 + b^4)*Tan[c + d*x])/(6*(a^2 + b^2)^4*d*(1 + Tan[c + d*x]^2)^3) - (5*(a^4 - 6*a^2*b^2 + b^4)*Tan[c + d*x])/(24*(a^2 + b^2)^4*d*(1 + Tan[c + d*x]^2)^2) + (4*a^3*b*(3*a^2 - 5*b^2) + (3*a^6 - 25*a^4*b^2 + 5*a^2*b^4 + b^6)*Tan[c + d*x])/(4*(a^2 + b^2)^5*d*(1 + Tan[c + d*x]^2)^2) - (5*(a^4 - 6*a^2*b^2 + b^4)*Tan[c + d*x])/(16*(a^2 + b^2)^4*d*(1 + Tan[c + d*x]^2)) + (3*(3*a^6 - 25*a^4*b^2 + 5*a^2*b^4 + b^6)*Tan[c + d*x])/(8*(a^2 + b^2)^5*d*(1 + Tan[c + d*x]^2)) - (a^3*(4*b*(3*a^4 - 12*a^2*b^2 + 5*b^4) + a*(3*a^4 - 42*a^2*b^2 + 35*b^4)*Tan[c + d*x]))/(2*(a^2 + b^2)^6*d*(1 + Tan[c + d*x]^2))}
{Sin[c + d*x]^5/(a + b*Tan[c + d*x])^4, x, 0, (1/(64*d*(a + b*Tan[c + d*x])^4))*(Sec[c + d*x]^4*(a*Cos[c + d*x] + b*Sin[c + d*x])^4*((35*b*(5*a^4 - 10*a^2*b^2 + b^4)*ArcTanh[(-b + a*Tan[(1/2)*(c + d*x)])/Sqrt[a^2 + b^2]])/(a^2 + b^2)^(9/2) + (16*(a^4 - 6*a^2*b^2 + b^4)*Cos[c + d*x])/(a^2 + b^2)^4 - (64*a*b*(a^2 - b^2)*Sin[c + d*x])/(a^2 + b^2)^4 - (a*(a^4 - 10*a^2*b^2 + 5*b^4))/(3*(a - I*b)^3*(a + I*b)^3*(a*Cos[c + d*x] + b*Sin[c + d*x])^3) - (5*b*(5*a^4 - 10*a^2*b^2 + b^4)*Sin[c + d*x])/(2*a*(a^2 + b^2)^3*(a*Cos[c + d*x] + b*Sin[c + d*x])^2) + (24*a^6 - 215*a^4*b^2 + 70*a^2*b^4 + 5*b^6)/(2*a*(a^2 + b^2)^4*(a*Cos[c + d*x] + b*Sin[c + d*x])))) + (Sec[c + d*x]^4*(a*Cos[c + d*x] + b*Sin[c + d*x])*(6*b*Sqrt[a^2 + b^2]*ArcTanh[(-b + a*Tan[(1/2)*(c + d*x)])/Sqrt[a^2 + b^2]]*(a*Cos[c + d*x] + b*Sin[c + d*x])^3 + (1/2)*(a^2 + b^2)*(4*a*(a^2 + b^2) - 6*a*b^2*Cos[2*(c + d*x)] + 3*b*(a^2 - b^2)*Sin[2*(c + d*x)])))/(256*(a - I*b)^3*(a + I*b)^3*d*(a + b*Tan[c + d*x])^4) + (Sec[c + d*x]^4*(a*Cos[c + d*x] + b*Sin[c + d*x])^4*(-((30*b*(-3*a^2 + b^2)*ArcTanh[(-b + a*Tan[(1/2)*(c + d*x)])/Sqrt[a^2 + b^2]])/(a^2 + b^2)^(7/2)) + (3*a*(4*a^4 - 7*a^2*b^2 + 9*b^4)*Cos[2*(c + d*x)] + 3*b*(7*a^4 - 3*b^4)*Cos[c + d*x]*Sin[c + d*x] + 2*a*(5*(a^4 - 2*a^2*b^2 - 3*b^4) - 27*a*b^3*Sin[2*(c + d*x)]))/((a - I*b)^3*(a + I*b)^3*(a*Cos[c + d*x] + b*Sin[c + d*x])^3)))/(384*d*(a + b*Tan[c + d*x])^4) + (1/(256*d*(a + b*Tan[c + d*x])^4))*(Sec[c + d*x]^4*(a*Cos[c + d*x] + b*Sin[c + d*x])^4*((105*b*(-7*a^6 + 35*a^4*b^2 - 21*a^2*b^4 + b^6)*ArcTanh[(-b + a*Tan[(1/2)*(c + d*x)])/Sqrt[a^2 + b^2]])/(a^2 + b^2)^(11/2) + (1/(12*(a^2 + b^2)^5*(a*Cos[c + d*x] + b*Sin[c + d*x])^3))*(-420*a^9 + 8400*a^7*b^2 - 5880*a^5*b^4 - 11760*a^3*b^6 + 2940*a*b^8 - 126*a*(4*a^8 - 67*a^6*b^2 + 119*a^4*b^4 - 105*a^2*b^6 + 25*b^8)*Cos[2*(c + d*x)] - 72*a*(a^2 - 3*b^2)*(a^2 + b^2)^3*Cos[4*(c + d*x)] + 8*a^9*Cos[6*(c + d*x)] + 32*a^7*b^2*Cos[6*(c + d*x)] + 48*a^5*b^4*Cos[6*(c + d*x)] + 32*a^3*b^6*Cos[6*(c + d*x)] + 8*a*b^8*Cos[6*(c + d*x)] + 315*a^8*b*Sin[2*(c + d*x)] + 13230*a^6*b^3*Sin[2*(c + d*x)] - 24696*a^4*b^5*Sin[2*(c + d*x)] + 2898*a^2*b^7*Sin[2*(c + d*x)] + 189*b^9*Sin[2*(c + d*x)] + 216*a^8*b*Sin[4*(c + d*x)] + 576*a^6*b^3*Sin[4*(c + d*x)] + 432*a^4*b^5*Sin[4*(c + d*x)] - 72*b^9*Sin[4*(c + d*x)] - 8*a^8*b*Sin[6*(c + d*x)] - 32*a^6*b^3*Sin[6*(c + d*x)] - 48*a^4*b^5*Sin[6*(c + d*x)] - 32*a^2*b^7*Sin[6*(c + d*x)] - 8*b^9*Sin[6*(c + d*x)]))) - (1/(15360*(a^2 + b^2)^7*d*(a + b*Tan[c + d*x])^4))*(Sec[c + d*x]^4*(a*Cos[c + d*x] + b*Sin[c + d*x])*(13860*b*Sqrt[a^2 + b^2]*(9*a^8 - 84*a^6*b^2 + 126*a^4*b^4 - 36*a^2*b^6 + b^8)*ArcTanh[(-b + a*Tan[(1/2)*(c + d*x)])/Sqrt[a^2 + b^2]]*(a*Cos[c + d*x] + b*Sin[c + d*x])^3 + (a^2 + b^2)*(4620*a^11 - 161700*a^9*b^2 + 415800*a^7*b^4 + 194040*a^5*b^6 - 346500*a^3*b^8 + 41580*a*b^10 + 1386*a*(4*a^10 - 121*a^8*b^2 + 396*a^6*b^4 - 462*a^4*b^6 + 264*a^2*b^8 - 33*b^10)*Cos[2*(c + d*x)] + 792*a*(a^2 + b^2)^3*(a^4 - 10*a^2*b^2 + 5*b^4)*Cos[4*(c + d*x)] - 88*a^11*Cos[6*(c + d*x)] - 88*a^9*b^2*Cos[6*(c + d*x)] + 528*a^7*b^4*Cos[6*(c + d*x)] + 1232*a^5*b^6*Cos[6*(c + d*x)] + 968*a^3*b^8*Cos[6*(c + d*x)] + 264*a*b^10*Cos[6*(c + d*x)] + 24*a^11*Cos[8*(c + d*x)] + 120*a^9*b^2*Cos[8*(c + d*x)] + 240*a^7*b^4*Cos[8*(c + d*x)] + 240*a^5*b^6*Cos[8*(c + d*x)] + 120*a^3*b^8*Cos[8*(c + d*x)] + 24*a*b^10*Cos[8*(c + d*x)] - 7623*a^10*b*Sin[2*(c + d*x)] - 205821*a^8*b^3*Sin[2*(c + d*x)] + 960498*a^6*b^5*Sin[2*(c + d*x)] - 594594*a^4*b^7*Sin[2*(c + d*x)] + 22869*a^2*b^9*Sin[2*(c + d*x)] + 2079*b^11*Sin[2*(c + d*x)] - 3960*a^10*b*Sin[4*(c + d*x)] - 3960*a^8*b^3*Sin[4*(c + d*x)] + 11088*a^6*b^5*Sin[4*(c + d*x)] + 17424*a^4*b^7*Sin[4*(c + d*x)] + 5544*a^2*b^9*Sin[4*(c + d*x)] - 792*b^11*Sin[4*(c + d*x)] + 264*a^10*b*Sin[6*(c + d*x)] + 968*a^8*b^3*Sin[6*(c + d*x)] + 1232*a^6*b^5*Sin[6*(c + d*x)] + 528*a^4*b^7*Sin[6*(c + d*x)] - 88*a^2*b^9*Sin[6*(c + d*x)] - 88*b^11*Sin[6*(c + d*x)] - 24*a^10*b*Sin[8*(c + d*x)] - 120*a^8*b^3*Sin[8*(c + d*x)] - 240*a^6*b^5*Sin[8*(c + d*x)] - 240*a^4*b^7*Sin[8*(c + d*x)] - 120*a^2*b^9*Sin[8*(c + d*x)] - 24*b^11*Sin[8*(c + d*x)])))}
{Sin[c + d*x]^4/(a + b*Tan[c + d*x])^4, x, 11, (3*(a^4 - 6*a^2*b^2 + b^4)*x)/(8*(a^2 + b^2)^4) - (a^2*(a^4 - 10*a^2*b^2 + 5*b^4)*x)/(a^2 + b^2)^5 + (a^2*(a^6 - 24*a^4*b^2 + 45*a^2*b^4 - 10*b^6)*x)/(a^2 + b^2)^6 + (4*a*b*(a^2 - b^2)*(a^4 - 8*a^2*b^2 + b^4)*Log[a + b*Tan[c + d*x]])/((a^2 + b^2)^6*d) - (2*a*b*(a^2 - b^2)*(a^4 - 8*a^2*b^2 + b^4)*Log[1 + Tan[c + d*x]^2])/((a^2 + b^2)^6*d) - (a^4*b)/(3*(a^2 + b^2)^3*d*(a + b*Tan[c + d*x])^3) - (a^3*b*(a^2 - 2*b^2))/((a^2 + b^2)^4*d*(a + b*Tan[c + d*x])^2) - (3*a^2*b*(a^4 - 5*a^2*b^2 + 2*b^4))/((a^2 + b^2)^5*d*(a + b*Tan[c + d*x])) + (4*a*b*(a^2 - b^2) + (a^4 - 6*a^2*b^2 + b^4)*Tan[c + d*x])/(4*(a^2 + b^2)^4*d*(1 + Tan[c + d*x]^2)^2) + (3*(a^4 - 6*a^2*b^2 + b^4)*Tan[c + d*x])/(8*(a^2 + b^2)^4*d*(1 + Tan[c + d*x]^2)) - (a*(2*b*(2*a^4 - 5*a^2*b^2 + b^4) + a*(a^4 - 10*a^2*b^2 + 5*b^4)*Tan[c + d*x]))/((a^2 + b^2)^5*d*(1 + Tan[c + d*x]^2))}
{Sin[c + d*x]^3/(a + b*Tan[c + d*x])^4, x, 0, (1/(64*d*(a + b*Tan[c + d*x])^4))*(Sec[c + d*x]^4*(a*Cos[c + d*x] + b*Sin[c + d*x])^4*((35*b*(5*a^4 - 10*a^2*b^2 + b^4)*ArcTanh[(-b + a*Tan[(1/2)*(c + d*x)])/Sqrt[a^2 + b^2]])/(a^2 + b^2)^(9/2) + (16*(a^4 - 6*a^2*b^2 + b^4)*Cos[c + d*x])/(a^2 + b^2)^4 - (64*a*b*(a^2 - b^2)*Sin[c + d*x])/(a^2 + b^2)^4 - (a*(a^4 - 10*a^2*b^2 + 5*b^4))/(3*(a - I*b)^3*(a + I*b)^3*(a*Cos[c + d*x] + b*Sin[c + d*x])^3) - (5*b*(5*a^4 - 10*a^2*b^2 + b^4)*Sin[c + d*x])/(2*a*(a^2 + b^2)^3*(a*Cos[c + d*x] + b*Sin[c + d*x])^2) + (24*a^6 - 215*a^4*b^2 + 70*a^2*b^4 + 5*b^6)/(2*a*(a^2 + b^2)^4*(a*Cos[c + d*x] + b*Sin[c + d*x])))) + (Sec[c + d*x]^4*(a*Cos[c + d*x] + b*Sin[c + d*x])*(6*b*Sqrt[a^2 + b^2]*ArcTanh[(-b + a*Tan[(1/2)*(c + d*x)])/Sqrt[a^2 + b^2]]*(a*Cos[c + d*x] + b*Sin[c + d*x])^3 + (1/2)*(a^2 + b^2)*(4*a*(a^2 + b^2) - 6*a*b^2*Cos[2*(c + d*x)] + 3*b*(a^2 - b^2)*Sin[2*(c + d*x)])))/(128*(a - I*b)^3*(a + I*b)^3*d*(a + b*Tan[c + d*x])^4) + (Sec[c + d*x]^4*(a*Cos[c + d*x] + b*Sin[c + d*x])^4*(-((30*b*(-3*a^2 + b^2)*ArcTanh[(-b + a*Tan[(1/2)*(c + d*x)])/Sqrt[a^2 + b^2]])/(a^2 + b^2)^(7/2)) + (3*a*(4*a^4 - 7*a^2*b^2 + 9*b^4)*Cos[2*(c + d*x)] + 3*b*(7*a^4 - 3*b^4)*Cos[c + d*x]*Sin[c + d*x] + 2*a*(5*(a^4 - 2*a^2*b^2 - 3*b^4) - 27*a*b^3*Sin[2*(c + d*x)]))/((a - I*b)^3*(a + I*b)^3*(a*Cos[c + d*x] + b*Sin[c + d*x])^3)))/(128*d*(a + b*Tan[c + d*x])^4) + (1/(64*d*(a + b*Tan[c + d*x])^4))*(Sec[c + d*x]^4*(a*Cos[c + d*x] + b*Sin[c + d*x])^4*((105*b*(-7*a^6 + 35*a^4*b^2 - 21*a^2*b^4 + b^6)*ArcTanh[(-b + a*Tan[(1/2)*(c + d*x)])/Sqrt[a^2 + b^2]])/(a^2 + b^2)^(11/2) + (1/(12*(a^2 + b^2)^5*(a*Cos[c + d*x] + b*Sin[c + d*x])^3))*(-420*a^9 + 8400*a^7*b^2 - 5880*a^5*b^4 - 11760*a^3*b^6 + 2940*a*b^8 - 126*a*(4*a^8 - 67*a^6*b^2 + 119*a^4*b^4 - 105*a^2*b^6 + 25*b^8)*Cos[2*(c + d*x)] - 72*a*(a^2 - 3*b^2)*(a^2 + b^2)^3*Cos[4*(c + d*x)] + 8*a^9*Cos[6*(c + d*x)] + 32*a^7*b^2*Cos[6*(c + d*x)] + 48*a^5*b^4*Cos[6*(c + d*x)] + 32*a^3*b^6*Cos[6*(c + d*x)] + 8*a*b^8*Cos[6*(c + d*x)] + 315*a^8*b*Sin[2*(c + d*x)] + 13230*a^6*b^3*Sin[2*(c + d*x)] - 24696*a^4*b^5*Sin[2*(c + d*x)] + 2898*a^2*b^7*Sin[2*(c + d*x)] + 189*b^9*Sin[2*(c + d*x)] + 216*a^8*b*Sin[4*(c + d*x)] + 576*a^6*b^3*Sin[4*(c + d*x)] + 432*a^4*b^5*Sin[4*(c + d*x)] - 72*b^9*Sin[4*(c + d*x)] - 8*a^8*b*Sin[6*(c + d*x)] - 32*a^6*b^3*Sin[6*(c + d*x)] - 48*a^4*b^5*Sin[6*(c + d*x)] - 32*a^2*b^7*Sin[6*(c + d*x)] - 8*b^9*Sin[6*(c + d*x)])))}
{Sin[c + d*x]^2/(a + b*Tan[c + d*x])^4, x, 8, -(((a^4 - 6*a^2*b^2 + b^4)*x)/(2*(a^2 + b^2)^4)) + ((a^6 - 15*a^4*b^2 + 15*a^2*b^4 - b^6)*x)/(a^2 + b^2)^5 + (4*a*b*(a^4 - 5*a^2*b^2 + 2*b^4)*Log[a + b*Tan[c + d*x]])/((a^2 + b^2)^5*d) - (2*a*b*(a^4 - 5*a^2*b^2 + 2*b^4)*Log[1 + Tan[c + d*x]^2])/((a^2 + b^2)^5*d) - (a^2*b)/(3*(a^2 + b^2)^2*d*(a + b*Tan[c + d*x])^3) - (a*b*(a^2 - b^2))/((a^2 + b^2)^3*d*(a + b*Tan[c + d*x])^2) - (b*(3*a^4 - 8*a^2*b^2 + b^4))/((a^2 + b^2)^4*d*(a + b*Tan[c + d*x])) - (4*a*b*(a^2 - b^2) + (a^4 - 6*a^2*b^2 + b^4)*Tan[c + d*x])/(2*(a^2 + b^2)^4*d*(1 + Tan[c + d*x]^2))}
{Sin[c + d*x]^1/(a + b*Tan[c + d*x])^4, x, 0, (1/(96*d*(a + b*Tan[c + d*x])^4))*(Sec[c + d*x]^4*(a*Cos[c + d*x] + b*Sin[c + d*x])*(6*(a*Cos[c + d*x] + b*Sin[c + d*x])^3*(-((35*b*(5*a^4 - 10*a^2*b^2 + b^4)*ArcTanh[(-b + a*Tan[(1/2)*(c + d*x)])/Sqrt[a^2 + b^2]])/(a^2 + b^2)^(9/2)) - (16*(a^4 - 6*a^2*b^2 + b^4)*Cos[c + d*x])/(a^2 + b^2)^4 + (64*a*b*(a^2 - b^2)*Sin[c + d*x])/(a^2 + b^2)^4 + (a*(a^4 - 10*a^2*b^2 + 5*b^4))/(3*(a - I*b)^3*(a + I*b)^3*(a*Cos[c + d*x] + b*Sin[c + d*x])^3) + (5*b*(5*a^4 - 10*a^2*b^2 + b^4)*Sin[c + d*x])/(2*a*(a^2 + b^2)^3*(a*Cos[c + d*x] + b*Sin[c + d*x])^2) - (24*a^6 - 215*a^4*b^2 + 70*a^2*b^4 + 5*b^6)/(2*a*(a^2 + b^2)^4*(a*Cos[c + d*x] + b*Sin[c + d*x]))) + (2*(6*b*Sqrt[a^2 + b^2]*ArcTanh[(-b + a*Tan[(1/2)*(c + d*x)])/Sqrt[a^2 + b^2]]*(a*Cos[c + d*x] + b*Sin[c + d*x])^3 + (1/2)*(a^2 + b^2)*(4*a*(a^2 + b^2) - 6*a*b^2*Cos[2*(c + d*x)] + 3*b*(a^2 - b^2)*Sin[2*(c + d*x)])))/(a^2 + b^2)^3 + 3*(a*Cos[c + d*x] + b*Sin[c + d*x])^3*(-((30*b*(-3*a^2 + b^2)*ArcTanh[(-b + a*Tan[(1/2)*(c + d*x)])/Sqrt[a^2 + b^2]])/(a^2 + b^2)^(7/2)) + (10*(a^5 - 2*a^3*b^2 - 3*a*b^4) + 3*(4*a^5 - 7*a^3*b^2 + 9*a*b^4)*Cos[2*(c + d*x)] + (3/2)*(7*a^4*b - 36*a^2*b^3 - 3*b^5)*Sin[2*(c + d*x)])/((a - I*b)^3*(a + I*b)^3*(a*Cos[c + d*x] + b*Sin[c + d*x])^3))))}
{Csc[c + d*x]^1/(a + b*Tan[c + d*x])^4, x, 0, (1/(6*a^4*d*(a + b*Tan[c + d*x])^4))*(Sec[c + d*x]^4*(a*Cos[c + d*x] + b*Sin[c + d*x])*((2*a^3*b^4)/(a^2 + b^2)^2 - (3*a*b^3*(4*a^2 + b^2)*Sin[c + d*x]*(a*Cos[c + d*x] + b*Sin[c + d*x]))/(a^2 + b^2)^2 + (3*a*b^2*(12*a^4 + 10*a^2*b^2 + 3*b^4)*(a*Cos[c + d*x] + b*Sin[c + d*x])^2)/(a^2 + b^2)^3 - (6*b*(8*a^6 + 8*a^4*b^2 + 7*a^2*b^4 + 2*b^6)*ArcTanh[(-b + a*Tan[(1/2)*(c + d*x)])/Sqrt[a^2 + b^2]]*(a*Cos[c + d*x] + b*Sin[c + d*x])^3)/(a^2 + b^2)^(7/2) - 6*Log[Cos[(1/2)*(c + d*x)]]*(a*Cos[c + d*x] + b*Sin[c + d*x])^3 + 6*Log[Sin[(1/2)*(c + d*x)]]*(a*Cos[c + d*x] + b*Sin[c + d*x])^3))}
{Csc[c + d*x]^2/(a + b*Tan[c + d*x])^4, x, 3, -(Cot[c + d*x]/(a^4*d)) - (4*b*Log[Tan[c + d*x]])/(a^5*d) + (4*b*Log[a + b*Tan[c + d*x]])/(a^5*d) - b/(3*a^2*d*(a + b*Tan[c + d*x])^3) - b/(a^3*d*(a + b*Tan[c + d*x])^2) - (3*b)/(a^4*d*(a + b*Tan[c + d*x]))}
{Csc[c + d*x]^3/(a + b*Tan[c + d*x])^4, x, 25, -(ArcTanh[Cos[c + d*x]]/(2*a^4*d)) - (10*b^2*ArcTanh[Cos[c + d*x]])/(a^6*d) + (b^3*ArcTanh[(b*Cos[c + d*x] - a*Sin[c + d*x])/Sqrt[a^2 + b^2]])/(2*a^2*(a^2 + b^2)^(5/2)*d) + (3*b^3*ArcTanh[(b*Cos[c + d*x] - a*Sin[c + d*x])/Sqrt[a^2 + b^2]])/(2*a^4*(a^2 + b^2)^(3/2)*d) - (6*b*ArcTanh[(b*Cos[c + d*x] - a*Sin[c + d*x])/Sqrt[a^2 + b^2]])/(a^4*Sqrt[a^2 + b^2]*d) + (10*b*Sqrt[a^2 + b^2]*ArcTanh[(b*Cos[c + d*x] - a*Sin[c + d*x])/Sqrt[a^2 + b^2]])/(a^6*d) + (4*b*Csc[c + d*x])/(a^5*d) - (Cot[c + d*x]*Csc[c + d*x])/(2*a^4*d) + b^4/(3*a^3*(a^2 + b^2)*d*(a*Cos[c + d*x] + b*Sin[c + d*x])^3) + (b^3*(b*Cos[c + d*x] - a*Sin[c + d*x]))/(2*a^2*(a^2 + b^2)^2*d*(a*Cos[c + d*x] + b*Sin[c + d*x])^2) + (3*b^3*(b*Cos[c + d*x] - a*Sin[c + d*x]))/(2*a^4*(a^2 + b^2)*d*(a*Cos[c + d*x] + b*Sin[c + d*x])^2) + (6*b^2)/(a^5*d*(a*Cos[c + d*x] + b*Sin[c + d*x]))}
{Csc[c + d*x]^4/(a + b*Tan[c + d*x])^4, x, 3, -(((a^2 + 10*b^2)*Cot[c + d*x])/(a^6*d)) + (2*b*Cot[c + d*x]^2)/(a^5*d) - Cot[c + d*x]^3/(3*a^4*d) - (4*b*(a^2 + 5*b^2)*Log[Tan[c + d*x]])/(a^7*d) + (4*b*(a^2 + 5*b^2)*Log[a + b*Tan[c + d*x]])/(a^7*d) - (b*(a^2 + b^2))/(3*a^4*d*(a + b*Tan[c + d*x])^3) - (b*(a^2 + 2*b^2))/(a^5*d*(a + b*Tan[c + d*x])^2) - (b*(3*a^2 + 10*b^2))/(a^6*d*(a + b*Tan[c + d*x]))}


(* Hangs Mathematica 6 & 7: *) 
{Csc[x]/(1 + Tan[x]), x, 6, -ArcTanh[Cos[x]] + ArcTanh[(Cos[x] - Sin[x])/Sqrt[2]]/Sqrt[2]}


(* ::Subsubsection::Closed:: *)
(*n symbolic*)


{Sin[c + d*x]^m*(a + b*Tan[c + d*x])^n, x, 0, Int[Sin[c + d*x]^m*(a + b*Tan[c + d*x])^n, x]}

{Sin[c + d*x]^4*(a + b*Tan[c + d*x])^n, x, 15, -((I*(3*a^2 - I*a*b*(6 + 5*n) - b^2*(3 + 4*n + n^2))*Hypergeometric2F1[1, 1 + n, 2 + n, (a + b*Tan[c + d*x])/(a - I*b)]*(a + b*Tan[c + d*x])^(1 + n))/(16*(a - I*b)^3*d*(1 + n))) + (I*(3*a^2 + I*a*b*(6 + 5*n) - b^2*(3 + 4*n + n^2))*Hypergeometric2F1[1, 1 + n, 2 + n, (a + b*Tan[c + d*x])/(a + I*b)]*(a + b*Tan[c + d*x])^(1 + n))/(16*(a + I*b)^3*d*(1 + n)) + (Cos[c + d*x]^4*(b + a*Tan[c + d*x])*(a + b*Tan[c + d*x])^(1 + n))/(4*(a^2 + b^2)*d) - ((b + a*Tan[c + d*x])*(a + b*Tan[c + d*x])^(1 + n))/((a^2 + b^2)*d*(1 + Tan[c + d*x]^2)) + ((a + b*Tan[c + d*x])^(1 + n)*(b*(b^2*(3 - n) + a^2*(1 + n)) + a*(3*a^2 + b^2*(5 - 2*n))*Tan[c + d*x]))/(8*(a^2 + b^2)^2*d*(1 + Tan[c + d*x]^2)), (Hypergeometric2F1[1, 1 + n, 2 + n, (a + b*Tan[c + d*x])/(a - I*b)]*(a + b*Tan[c + d*x])^(1 + n))/(2*(I*a + b)*d*(1 + n)) + ((I*a + b - b*n)*Hypergeometric2F1[1, 1 + n, 2 + n, (a + b*Tan[c + d*x])/(a - I*b)]*(a + b*Tan[c + d*x])^(1 + n))/(2*(a - I*b)^2*d*(1 + n)) - ((3*I*a^2 + 3*a*b*(2 - n) - I*b^2*(3 - 4*n + n^2))*Hypergeometric2F1[1, 1 + n, 2 + n, (a + b*Tan[c + d*x])/(a - I*b)]*(a + b*Tan[c + d*x])^(1 + n))/(16*(a - I*b)^3*d*(1 + n)) + (I*Hypergeometric2F1[1, 1 + n, 2 + n, (a + b*Tan[c + d*x])/(a + I*b)]*(a + b*Tan[c + d*x])^(1 + n))/(2*(a + I*b)*d*(1 + n)) - ((I*a - b*(1 - n))*Hypergeometric2F1[1, 1 + n, 2 + n, (a + b*Tan[c + d*x])/(a + I*b)]*(a + b*Tan[c + d*x])^(1 + n))/(2*(a + I*b)^2*d*(1 + n)) + ((3*I*a^2 - 3*a*b*(2 - n) - I*b^2*(3 - 4*n + n^2))*Hypergeometric2F1[1, 1 + n, 2 + n, (a + b*Tan[c + d*x])/(a + I*b)]*(a + b*Tan[c + d*x])^(1 + n))/(16*(a + I*b)^3*d*(1 + n)) + ((b + a*Tan[c + d*x])*(a + b*Tan[c + d*x])^(1 + n))/(4*(a^2 + b^2)*d*(1 + Tan[c + d*x]^2)^2) - ((b + a*Tan[c + d*x])*(a + b*Tan[c + d*x])^(1 + n))/((a^2 + b^2)*d*(1 + Tan[c + d*x]^2)) + ((a + b*Tan[c + d*x])^(1 + n)*(b*(b^2*(3 - n) + a^2*(1 + n)) + a*(3*a^2 + b^2*(5 - 2*n))*Tan[c + d*x]))/(8*(a^2 + b^2)^2*d*(1 + Tan[c + d*x]^2))}
{Sin[c + d*x]^3*(a + b*Tan[c + d*x])^n, x, 0, Int[Sin[c + d*x]^3*(a + b*Tan[c + d*x])^n, x]}
{Sin[c + d*x]^2*(a + b*Tan[c + d*x])^n, x, 10, -((I*(a - I*b*(1 + n))*Hypergeometric2F1[1, 1 + n, 2 + n, (a + b*Tan[c + d*x])/(a - I*b)]*(a + b*Tan[c + d*x])^(1 + n))/(4*(a - I*b)^2*d*(1 + n))) + (I*(a + I*b*(1 + n))*Hypergeometric2F1[1, 1 + n, 2 + n, (a + b*Tan[c + d*x])/(a + I*b)]*(a + b*Tan[c + d*x])^(1 + n))/(4*(a + I*b)^2*d*(1 + n)) - ((b + a*Tan[c + d*x])*(a + b*Tan[c + d*x])^(1 + n))/(2*(a^2 + b^2)*d*(1 + Tan[c + d*x]^2)), (Hypergeometric2F1[1, 1 + n, 2 + n, (a + b*Tan[c + d*x])/(a - I*b)]*(a + b*Tan[c + d*x])^(1 + n))/(2*(I*a + b)*d*(1 + n)) + ((I*a + b - b*n)*Hypergeometric2F1[1, 1 + n, 2 + n, (a + b*Tan[c + d*x])/(a - I*b)]*(a + b*Tan[c + d*x])^(1 + n))/(4*(a - I*b)^2*d*(1 + n)) + (I*Hypergeometric2F1[1, 1 + n, 2 + n, (a + b*Tan[c + d*x])/(a + I*b)]*(a + b*Tan[c + d*x])^(1 + n))/(2*(a + I*b)*d*(1 + n)) - ((I*a - b*(1 - n))*Hypergeometric2F1[1, 1 + n, 2 + n, (a + b*Tan[c + d*x])/(a + I*b)]*(a + b*Tan[c + d*x])^(1 + n))/(4*(a + I*b)^2*d*(1 + n)) - ((b + a*Tan[c + d*x])*(a + b*Tan[c + d*x])^(1 + n))/(2*(a^2 + b^2)*d*(1 + Tan[c + d*x]^2))}
{Sin[c + d*x]^1*(a + b*Tan[c + d*x])^n, x, 0, Int[Sin[c + d*x]*(a + b*Tan[c + d*x])^n, x]}
{Csc[c + d*x]^1*(a + b*Tan[c + d*x])^n, x, 0, Int[Csc[c + d*x]*(a + b*Tan[c + d*x])^n, x]}
{Csc[c + d*x]^2*(a + b*Tan[c + d*x])^n, x, 3, -((Cot[c + d*x]*(a + b*Tan[c + d*x])^(1 + n))/(a*d)) - (b*n*Hypergeometric2F1[1, 1 + n, 2 + n, (a + b*Tan[c + d*x])/a]*(a + b*Tan[c + d*x])^(1 + n))/(a^2*d*(1 + n))}
{Csc[c + d*x]^3*(a + b*Tan[c + d*x])^n, x, 0, Int[Csc[c + d*x]^3*(a + b*Tan[c + d*x])^n, x]}
{Csc[c + d*x]^4*(a + b*Tan[c + d*x])^n, x, 9, -(((6*a^2 + b^2*(2 - 3*n + n^2))*Cot[c + d*x]*(a + b*Tan[c + d*x])^(1 + n))/(6*a^3*d)) + (b*(2 - n)*Cot[c + d*x]^2*(a + b*Tan[c + d*x])^(1 + n))/(6*a^2*d) - (Cot[c + d*x]^3*(a + b*Tan[c + d*x])^(1 + n))/(3*a*d) - (b*n*(6*a^2 + b^2*(2 - 3*n + n^2))*Hypergeometric2F1[1, 1 + n, 2 + n, 1 + (b*Tan[c + d*x])/a]*(a + b*Tan[c + d*x])^(1 + n))/(6*a^4*d*(1 + n)), -((Cot[c + d*x]*(a + b*Tan[c + d*x])^(1 + n))/(a*d)) - (b^2*(1 - n)*(2 - n)*Cot[c + d*x]*(a + b*Tan[c + d*x])^(1 + n))/(6*a^3*d) + (b*(2 - n)*Cot[c + d*x]^2*(a + b*Tan[c + d*x])^(1 + n))/(6*a^2*d) - (Cot[c + d*x]^3*(a + b*Tan[c + d*x])^(1 + n))/(3*a*d) - (b*n*Hypergeometric2F1[1, 1 + n, 2 + n, (a + b*Tan[c + d*x])/a]*(a + b*Tan[c + d*x])^(1 + n))/(a^2*d*(1 + n)) - (b^3*(1 - n)*(2 - n)*n*Hypergeometric2F1[1, 1 + n, 2 + n, (a + b*Tan[c + d*x])/a]*(a + b*Tan[c + d*x])^(1 + n))/(6*a^4*d*(1 + n))}


(* ::Subsection::Closed:: *)
(*Integrands of the form Sin[c+d x]^m (a+b Tan[c+d x])^(n/2)*)


(* ::Subsubsection:: *)
(*n>0*)


(* ::Subsubsection:: *)
(*n<0*)


(* ::Subsection::Closed:: *)
(*Integrands of the form Sin[c+d x]^(m/2) (a+b Tan[c+d x])^n*)


(* ::Subsubsection:: *)
(*n>0*)


(* ::Subsubsection:: *)
(*n<0*)


(* ::Subsubsection:: *)
(*n symbolic*)


(* ::Subsection::Closed:: *)
(*Integrands of the form Sin[c+d x]^(m/2) (a+b Tan[c+d x])^(n/2)*)
(**)


(* ::Subsubsection:: *)
(*n>0*)


(* ::Subsubsection:: *)
(*n<0*)


(* ::Subsection::Closed:: *)
(*Integrands of the form Sin[c+d x]^(m/3) (a+b Tan[c+d x])^n*)


(* ::Subsubsection:: *)
(*n>0*)


(* ::Subsubsection:: *)
(*n<0*)


(* ::Subsection::Closed:: *)
(*Integrands of the form Sin[c+d x]^(m/3) (a+b Tan[c+d x])^(n/2)*)


(* ::Subsubsection:: *)
(*n>0*)


(* ::Subsubsection:: *)
(*n<0*)


(* ::Subsection::Closed:: *)
(*Integrands of the form Csc[c+d x]^(m/2) (a+b Tan[c+d x])^n*)


(* ::Subsubsection:: *)
(*n>0*)


(* ::Subsubsection:: *)
(*n<0*)


(* ::Subsubsection:: *)
(*n symbolic*)


(* ::Subsection::Closed:: *)
(*Integrands of the form Csc[c+d x]^(m/2) (a+b Tan[c+d x])^(n/2)*)


(* ::Subsubsection:: *)
(*n>0*)


(* ::Subsubsection:: *)
(*n<0*)


(* ::Section::Closed:: *)
(*Integrands of the form Cos[c+d x]^m (a+b Tan[c+d x])^n when a^2+b^2=0*)


(* ::Subsection::Closed:: *)
(*Integrands of the form Cos[c+d x]^m (a+b Tan[c+d x])^n when a^2+b^2=0*)


(* ::Subsubsection:: *)
(*n>0*)


(* ::Subsubsection::Closed:: *)
(*n<0*)


{Cos[x]^4/(I + Tan[x]), x, 5, -((5*I*x)/16) - 1/(32*(I - Tan[x])^2) + I/(8*(I - Tan[x])) + I/(24*(I + Tan[x])^3) + 3/(32*(I + Tan[x])^2) - (3*I)/(16*(I + Tan[x]))}
{Cos[x]^3/(I + Tan[x]), x, 7, (-(1/5))*Cos[x]^5 - I*Sin[x] + (2/3)*I*Sin[x]^3 - (1/5)*I*Sin[x]^5}
{Cos[x]^2/(I + Tan[x]), x, 5, -((3*I*x)/8) + I/(8*(I - Tan[x])) + 1/(8*(I + Tan[x])^2) - I/(4*(I + Tan[x]))}
{Cos[x]^1/(I + Tan[x]), x, 7, (-(1/3))*Cos[x]^3 - I*Sin[x] + (1/3)*I*Sin[x]^3}
{Sec[x]^1/(I + Tan[x]), x, 2, -(I/(I*Cos[x] + Sin[x]))}
{Sec[x]^2/(I + Tan[x]), x, 2, Log[I + Tan[x]]}
{Sec[x]^3/(I + Tan[x]), x, 6, (-I)*ArcTanh[Sin[x]] + Sec[x]}
{Sec[x]^4/(I + Tan[x]), x, 3, (-I)*Tan[x] + Tan[x]^2/2}


(* ::Section::Closed:: *)
(*Integrands of the form Cos[c+d x]^m (a+b Tan[c+d x])^n*)


(* ::Subsection::Closed:: *)
(*Integrands of the form Cos[c+d x]^m (a+b Tan[c+d x])^n*)


(* ::Subsubsection:: *)
(*n>0*)


(* ::Subsubsection::Closed:: *)
(*n<0*)


(* {Cos[c + d*x]^m/(a + b*Tan[c + d*x]), x, 0, 0} *)

{Cos[c + d*x]^4/(a + b*Tan[c + d*x]), x, 8, (a*(3*a^4 + 10*a^2*b^2 + 15*b^4)*x)/(8*(a^2 + b^2)^3) + (b^5*Log[a + b*Tan[c + d*x]])/((a^2 + b^2)^3*d) - (b^5*Log[1 + Tan[c + d*x]^2])/(2*(a^2 + b^2)^3*d) + (b + a*Tan[c + d*x])/(4*(a^2 + b^2)*d*(1 + Tan[c + d*x]^2)^2) + (4*b^3 + a*(3*a^2 + 7*b^2)*Tan[c + d*x])/(8*(a^2 + b^2)^2*d*(1 + Tan[c + d*x]^2))}
{Cos[c + d*x]^3/(a + b*Tan[c + d*x]), x, 8, -((b^4*ArcTanh[(b*Cos[c + d*x] - a*Sin[c + d*x])/Sqrt[a^2 + b^2]])/((a^2 + b^2)^(5/2)*d)) + (b^3*Cos[c + d*x])/((a^2 + b^2)^2*d) + (b*Cos[c + d*x]^3)/(3*(a^2 + b^2)*d) + (a*b^2*Sin[c + d*x])/((a^2 + b^2)^2*d) + (a*Sin[c + d*x])/((a^2 + b^2)*d) - (a*Sin[c + d*x]^3)/(3*(a^2 + b^2)*d)}
{Cos[c + d*x]^2/(a + b*Tan[c + d*x]), x, 7, (a*(a^2 + 3*b^2)*x)/(2*(a^2 + b^2)^2) + (b^3*Log[a + b*Tan[c + d*x]])/((a^2 + b^2)^2*d) - (b^3*Log[1 + Tan[c + d*x]^2])/(2*(a^2 + b^2)^2*d) + (b + a*Tan[c + d*x])/(2*(a^2 + b^2)*d*(1 + Tan[c + d*x]^2))}
{Cos[c + d*x]^1/(a + b*Tan[c + d*x]), x, 5, -((b^2*ArcTanh[(b*Cos[c + d*x] - a*Sin[c + d*x])/Sqrt[a^2 + b^2]])/((a^2 + b^2)^(3/2)*d)) + (b*Cos[c + d*x])/((a^2 + b^2)*d) + (a*Sin[c + d*x])/((a^2 + b^2)*d)}
{Sec[c + d*x]^1/(a + b*Tan[c + d*x]), x, 3, -(ArcTanh[(b*Cos[c + d*x] - a*Sin[c + d*x])/Sqrt[a^2 + b^2]]/(Sqrt[a^2 + b^2]*d))}
{Sec[c + d*x]^2/(a + b*Tan[c + d*x]), x, 2, Log[a + b*Tan[c + d*x]]/(b*d)}
{Sec[c + d*x]^3/(a + b*Tan[c + d*x]), x, 5, -((a*ArcTanh[Sin[c + d*x]])/(b^2*d)) - (Sqrt[a^2 + b^2]*ArcTanh[(b*Cos[c + d*x] - a*Sin[c + d*x])/Sqrt[a^2 + b^2]])/(b^2*d) + Sec[c + d*x]/(b*d)}
{Sec[c + d*x]^4/(a + b*Tan[c + d*x]), x, 3, ((a^2 + b^2)*Log[a + b*Tan[c + d*x]])/(b^3*d) - (a*Tan[c + d*x])/(b^2*d) + Tan[c + d*x]^2/(2*b*d)}
{Sec[c + d*x]^5/(a + b*Tan[c + d*x]), x, 8, -((a*ArcTanh[Sin[c + d*x]])/(2*b^2*d)) - (a*(a^2 + b^2)*ArcTanh[Sin[c + d*x]])/(b^4*d) - ((a^2 + b^2)^(3/2)*ArcTanh[(b*Cos[c + d*x] - a*Sin[c + d*x])/Sqrt[a^2 + b^2]])/(b^4*d) + ((a^2 + b^2)*Sec[c + d*x])/(b^3*d) + Sec[c + d*x]^3/(3*b*d) - (a*Sec[c + d*x]*Tan[c + d*x])/(2*b^2*d)}
{Sec[c + d*x]^6/(a + b*Tan[c + d*x]), x, 3, ((a^2 + b^2)^2*Log[a + b*Tan[c + d*x]])/(b^5*d) - (a*(a^2 + 2*b^2)*Tan[c + d*x])/(b^4*d) + ((a^2 + 2*b^2)*Tan[c + d*x]^2)/(2*b^3*d) - (a*Tan[c + d*x]^3)/(3*b^2*d) + Tan[c + d*x]^4/(4*b*d)}


(* {Cos[c + d*x]^m/(a + b*Tan[c + d*x])^2, x, 0, 0} *)

{Cos[c + d*x]^4/(a + b*Tan[c + d*x])^2, x, 9, (3*(a^6 + 5*a^4*b^2 + 15*a^2*b^4 - 5*b^6)*x)/(8*(a^2 + b^2)^4) + (6*a*b^5*Log[a + b*Tan[c + d*x]])/((a^2 + b^2)^4*d) - (3*a*b^5*Log[1 + Tan[c + d*x]^2])/((a^2 + b^2)^4*d) + (3*b*(a^2 - b^2)*(a^2 + 5*b^2))/(8*(a^2 + b^2)^3*d*(a + b*Tan[c + d*x])) + (b + a*Tan[c + d*x])/(4*(a^2 + b^2)*d*(a + b*Tan[c + d*x])*(1 + Tan[c + d*x]^2)^2) - (b*(a^2 - 5*b^2) - 3*a*(a^2 + 3*b^2)*Tan[c + d*x])/(8*(a^2 + b^2)^2*d*(a + b*Tan[c + d*x])*(1 + Tan[c + d*x]^2))}
{Cos[c + d*x]^3/(a + b*Tan[c + d*x])^2, x, 0, (1/(24*(a^2 + b^2)^4*d*(a + b*Tan[c + d*x])^2))*(Sec[c + d*x]^2*(a*Cos[c + d*x] + b*Sin[c + d*x])*(240*a*b^4*Sqrt[a^2 + b^2]*ArcTanh[(-b + a*Tan[(1/2)*(c + d*x)])/Sqrt[a^2 + b^2]]*(a*Cos[c + d*x] + b*Sin[c + d*x]) + (a^2 + b^2)*(15*a^4*b + 90*a^2*b^3 - 45*b^5 + 20*b^3*(a^2 + b^2)*Cos[2*(c + d*x)] + b*(a^2 + b^2)^2*Cos[4*(c + d*x)] + 10*a^5*Sin[2*(c + d*x)] + 40*a^3*b^2*Sin[2*(c + d*x)] + 30*a*b^4*Sin[2*(c + d*x)] + a^5*Sin[4*(c + d*x)] + 2*a^3*b^2*Sin[4*(c + d*x)] + a*b^4*Sin[4*(c + d*x)])))}
{Cos[c + d*x]^2/(a + b*Tan[c + d*x])^2, x, 8, ((a^4 + 6*a^2*b^2 - 3*b^4)*x)/(2*(a^2 + b^2)^3) + (4*a*b^3*Log[a + b*Tan[c + d*x]])/((a^2 + b^2)^3*d) - (2*a*b^3*Log[1 + Tan[c + d*x]^2])/((a^2 + b^2)^3*d) + (b*(a^2 - 3*b^2))/(2*(a^2 + b^2)^2*d*(a + b*Tan[c + d*x])) + (b + a*Tan[c + d*x])/(2*(a^2 + b^2)*d*(a + b*Tan[c + d*x])*(1 + Tan[c + d*x]^2))}
{Cos[c + d*x]^1/(a + b*Tan[c + d*x])^2, x, 0, -((3*a*b^2*ArcTanh[(b*Cos[c + d*x] - a*Sin[c + d*x])/Sqrt[a^2 + b^2]])/((a^2 + b^2)^(5/2)*d)) + (2*a*b*Cos[c + d*x])/((a^2 + b^2)^2*d) + ((a^2 - b^2)*Sin[c + d*x])/((a^2 + b^2)^2*d) - b^3/((a^2 + b^2)^2*d*(a*Cos[c + d*x] + b*Sin[c + d*x]))}
{Sec[c + d*x]^1/(a + b*Tan[c + d*x])^2, x, 4, -((a*ArcTanh[(b*Cos[c + d*x] - a*Sin[c + d*x])/Sqrt[a^2 + b^2]])/((a^2 + b^2)^(3/2)*d)) - b/((a^2 + b^2)*d*(a*Cos[c + d*x] + b*Sin[c + d*x]))}
{Sec[c + d*x]^2/(a + b*Tan[c + d*x])^2, x, 2, -(1/(b*d*(a + b*Tan[c + d*x])))}
{Sec[c + d*x]^3/(a + b*Tan[c + d*x])^2, x, 5, ArcTanh[Sin[c + d*x]]/(b^2*d) + (a*ArcTanh[(b*Cos[c + d*x] - a*Sin[c + d*x])/Sqrt[a^2 + b^2]])/(b^2*Sqrt[a^2 + b^2]*d) - 1/(b*d*(a*Cos[c + d*x] + b*Sin[c + d*x]))}
{Sec[c + d*x]^4/(a + b*Tan[c + d*x])^2, x, 3, -((2*a*Log[a + b*Tan[c + d*x]])/(b^3*d)) + Tan[c + d*x]/(b^2*d) - (a^2 + b^2)/(b^3*d*(a + b*Tan[c + d*x]))}
{Sec[c + d*x]^5/(a + b*Tan[c + d*x])^2, x, 12, (2*a^2*ArcTanh[Sin[c + d*x]])/(b^4*d) + ArcTanh[Sin[c + d*x]]/(2*b^2*d) + ((a^2 + b^2)*ArcTanh[Sin[c + d*x]])/(b^4*d) + (3*a*Sqrt[a^2 + b^2]*ArcTanh[(b*Cos[c + d*x] - a*Sin[c + d*x])/Sqrt[a^2 + b^2]])/(b^4*d) - (2*a*Sec[c + d*x])/(b^3*d) - (a^2 + b^2)/(b^3*d*(a*Cos[c + d*x] + b*Sin[c + d*x])) + (Sec[c + d*x]*Tan[c + d*x])/(2*b^2*d)}
{Sec[c + d*x]^6/(a + b*Tan[c + d*x])^2, x, 3, -((4*a*(a^2 + b^2)*Log[a + b*Tan[c + d*x]])/(b^5*d)) + ((3*a^2 + 2*b^2)*Tan[c + d*x])/(b^4*d) - (a*Tan[c + d*x]^2)/(b^3*d) + Tan[c + d*x]^3/(3*b^2*d) - (a^2 + b^2)^2/(b^5*d*(a + b*Tan[c + d*x]))}


(* {Cos[c + d*x]^m/(a + b*Tan[c + d*x])^3, x, 0, 0} *)

{Cos[c + d*x]^4/(a + b*Tan[c + d*x])^3, x, 10, (3*a*(a^6 + 7*a^4*b^2 + 35*a^2*b^4 - 35*b^6)*x)/(8*(a^2 + b^2)^5) + (3*b^5*(7*a^2 - b^2)*Log[a + b*Tan[c + d*x]])/((a^2 + b^2)^5*d) - (3*b^5*(7*a^2 - b^2)*Log[1 + Tan[c + d*x]^2])/(2*(a^2 + b^2)^5*d) + (3*b*(a^4 + 5*a^2*b^2 - 4*b^4))/(8*(a^2 + b^2)^3*d*(a + b*Tan[c + d*x])^2) + (3*a*b*(a^4 + 6*a^2*b^2 - 27*b^4))/(8*(a^2 + b^2)^4*d*(a + b*Tan[c + d*x])) + (b + a*Tan[c + d*x])/(4*(a^2 + b^2)*d*(a + b*Tan[c + d*x])^2*(1 + Tan[c + d*x]^2)^2) - (2*b*(a^2 - 3*b^2) - a*(3*a^2 + 11*b^2)*Tan[c + d*x])/(8*(a^2 + b^2)^2*d*(a + b*Tan[c + d*x])^2*(1 + Tan[c + d*x]^2))}
{Cos[c + d*x]^3/(a + b*Tan[c + d*x])^3, x, 0, (1/(12*d*(a + b*Tan[c + d*x])^3))*(Sec[c + d*x]^2*(a*Cos[c + d*x] + b*Sin[c + d*x])*(-((6*b^5*(12*a^2 + b^2)*Sec[c + d*x]*(a*Cos[c + d*x] + b*Sin[c + d*x]))/(a*(a^2 + b^2)^4)) + (9*b*(a^4 + 14*a^2*b^2 - 3*b^4)*(a*Cos[c + d*x] + b*Sin[c + d*x])^2)/(a^2 + b^2)^4 - (b*(-3*a^2 + b^2)*(-1 + 2*Cos[2*(c + d*x)])*(a*Cos[c + d*x] + b*Sin[c + d*x])^2)/(a^2 + b^2)^3 - (60*b^4*(-6*a^2 + b^2)*ArcTanh[(-b + a*Tan[(1/2)*(c + d*x)])/Sqrt[a^2 + b^2]]*Sec[c + d*x]*(a*Cos[c + d*x] + b*Sin[c + d*x])^2)/(a^2 + b^2)^(9/2) + (a*(a^2 - 3*b^2)*Sec[c + d*x]*(a*Cos[c + d*x] + b*Sin[c + d*x])^2*Sin[3*(c + d*x)])/(a^2 + b^2)^3 + (6*b^6*Tan[c + d*x])/(a*(a^2 + b^2)^3) + (9*a*(a^4 + 6*a^2*b^2 - 11*b^4)*(a*Cos[c + d*x] + b*Sin[c + d*x])^2*Tan[c + d*x])/(a^2 + b^2)^4))}
{Cos[c + d*x]^2/(a + b*Tan[c + d*x])^3, x, 9, (a*(a^4 + 10*a^2*b^2 - 15*b^4)*x)/(2*(a^2 + b^2)^4) + (2*b^3*(5*a^2 - b^2)*Log[a + b*Tan[c + d*x]])/((a^2 + b^2)^4*d) - (b^3*(5*a^2 - b^2)*Log[1 + Tan[c + d*x]^2])/((a^2 + b^2)^4*d) + (b*(a^2 - 2*b^2))/(2*(a^2 + b^2)^2*d*(a + b*Tan[c + d*x])^2) + (a*b*(a^2 - 11*b^2))/(2*(a^2 + b^2)^3*d*(a + b*Tan[c + d*x])) + (b + a*Tan[c + d*x])/(2*(a^2 + b^2)*d*(a + b*Tan[c + d*x])^2*(1 + Tan[c + d*x]^2))}
{Cos[c + d*x]^1/(a + b*Tan[c + d*x])^3, x, 0, (1/(2*d*(a + b*Tan[c + d*x])^3))*(Sec[c + d*x]^2*(a*Cos[c + d*x] + b*Sin[c + d*x])*(-((b^3*(8*a^2 + b^2)*Sec[c + d*x]*(a*Cos[c + d*x] + b*Sin[c + d*x]))/(a*(a^2 + b^2)^3)) - (2*b*(-3*a^2 + b^2)*(a*Cos[c + d*x] + b*Sin[c + d*x])^2)/(a^2 + b^2)^3 - (6*b^2*(-4*a^2 + b^2)*ArcTanh[(-b + a*Tan[(1/2)*(c + d*x)])/Sqrt[a^2 + b^2]]*Sec[c + d*x]*(a*Cos[c + d*x] + b*Sin[c + d*x])^2)/(a^2 + b^2)^(7/2) + (b^4*Tan[c + d*x])/(a*(a^2 + b^2)^2) + (2*a*(a^2 - 3*b^2)*(a*Cos[c + d*x] + b*Sin[c + d*x])^2*Tan[c + d*x])/(a^2 + b^2)^3))}
{Sec[c + d*x]^1/(a + b*Tan[c + d*x])^3, x, 0, (Sec[c + d*x]^2*(a*Cos[c + d*x] + b*Sin[c + d*x])*(2*(2*a^2 - b^2)*ArcTanh[(-b + a*Tan[(1/2)*(c + d*x)])/Sqrt[a^2 + b^2]]*Sec[c + d*x]*(a*Cos[c + d*x] + b*Sin[c + d*x])^2 - b*Sqrt[a^2 + b^2]*(4*a^2 + b^2 + 3*a*b*Tan[c + d*x])))/(2*(a^2 + b^2)^(5/2)*d*(a + b*Tan[c + d*x])^3)}
{Sec[c + d*x]^2/(a + b*Tan[c + d*x])^3, x, 2, -(1/(2*b*d*(a + b*Tan[c + d*x])^2))}
{Sec[c + d*x]^3/(a + b*Tan[c + d*x])^3, x, 4, -(ArcTanh[(b*Cos[c + d*x] - a*Sin[c + d*x])/Sqrt[a^2 + b^2]]/(2*(a^2 + b^2)^(3/2)*d)) - (b*Cos[c + d*x] - a*Sin[c + d*x])/(2*(a^2 + b^2)*d*(a*Cos[c + d*x] + b*Sin[c + d*x])^2)}
{Sec[c + d*x]^4/(a + b*Tan[c + d*x])^3, x, 3, Log[a + b*Tan[c + d*x]]/(b^3*d) - (a^2 + b^2)/(2*b^3*d*(a + b*Tan[c + d*x])^2) + (2*a)/(b^3*d*(a + b*Tan[c + d*x]))}
{Sec[c + d*x]^5/(a + b*Tan[c + d*x])^3, x, 13, -((3*a*ArcTanh[Sin[c + d*x]])/(b^4*d)) - (2*a^2*ArcTanh[(b*Cos[c + d*x] - a*Sin[c + d*x])/Sqrt[a^2 + b^2]])/(b^4*Sqrt[a^2 + b^2]*d) - ArcTanh[(b*Cos[c + d*x] - a*Sin[c + d*x])/Sqrt[a^2 + b^2]]/(2*b^2*Sqrt[a^2 + b^2]*d) - (Sqrt[a^2 + b^2]*ArcTanh[(b*Cos[c + d*x] - a*Sin[c + d*x])/Sqrt[a^2 + b^2]])/(b^4*d) + Sec[c + d*x]/(b^3*d) - (b*Cos[c + d*x] - a*Sin[c + d*x])/(2*b^2*d*(a*Cos[c + d*x] + b*Sin[c + d*x])^2) + (2*a)/(b^3*d*(a*Cos[c + d*x] + b*Sin[c + d*x]))}
{Sec[c + d*x]^6/(a + b*Tan[c + d*x])^3, x, 3, (2*(3*a^2 + b^2)*Log[a + b*Tan[c + d*x]])/(b^5*d) - (3*a*Tan[c + d*x])/(b^4*d) + Tan[c + d*x]^2/(2*b^3*d) - (a^2 + b^2)^2/(2*b^5*d*(a + b*Tan[c + d*x])^2) + (4*a*(a^2 + b^2))/(b^5*d*(a + b*Tan[c + d*x]))}


{Sec[c + d*x]^2/(a + b*Tan[c + d*x])^2, x, 2, -(1/(b*d*(a + b*Tan[c + d*x])))}


(* ::Subsubsection::Closed:: *)
(*n symbolic*)


(* {Cos[c + d*x]^m*(a + b*Tan[c + d*x])^n, x, 0, 0} *)

{Cos[c + d*x]^4*(a + b*Tan[c + d*x])^n, x, 6, -(((3*I*a^2 + 3*a*b*(2 - n) - I*b^2*(3 - 4*n + n^2))*Hypergeometric2F1[1, 1 + n, 2 + n, (a + b*Tan[c + d*x])/(a - I*b)]*(a + b*Tan[c + d*x])^(1 + n))/(16*(a - I*b)^3*d*(1 + n))) + ((3*I*a^2 - 3*a*b*(2 - n) - I*b^2*(3 - 4*n + n^2))*Hypergeometric2F1[1, 1 + n, 2 + n, (a + b*Tan[c + d*x])/(a + I*b)]*(a + b*Tan[c + d*x])^(1 + n))/(16*(a + I*b)^3*d*(1 + n)) + ((b + a*Tan[c + d*x])*(a + b*Tan[c + d*x])^(1 + n))/(4*(a^2 + b^2)*d*(1 + Tan[c + d*x]^2)^2) + ((a + b*Tan[c + d*x])^(1 + n)*(b*(b^2*(3 - n) + a^2*(1 + n)) + a*(3*a^2 + b^2*(5 - 2*n))*Tan[c + d*x]))/(8*(a^2 + b^2)^2*d*(1 + Tan[c + d*x]^2))}
(* {Cos[c + d*x]^3*(a + b*Tan[c + d*x])^n, x, 0, (2*(a^2 + b^2)^2*(2 + n)*AppellF1[1 + n, 5/2, 5/2, 2 + n, (a + b*Tan[c + d*x])/(a - I*b), (a + b*Tan[c + d*x])/(a + I*b)]*Cos[c + d*x]^8*(-I + Tan[c + d*x])*(I + Tan[c + d*x])*(a + b*Tan[c + d*x])^(1 + n))/((a - I*b)*(a + I*b)*b*d*(1 + n)*(2*(a^2 + b^2)*(2 + n)*AppellF1[1 + n, 5/2, 5/2, 2 + n, (a + b*Tan[c + d*x])/(a - I*b), (a + b*Tan[c + d*x])/(a + I*b)]*Cos[c + d*x] + 5*((a - I*b)*AppellF1[2 + n, 5/2, 7/2, 3 + n, (a + b*Tan[c + d*x])/(a - I*b), (a + b*Tan[c + d*x])/(a + I*b)] + (a + I*b)*AppellF1[2 + n, 7/2, 5/2, 3 + n, (a + b*Tan[c + d*x])/(a - I*b), (a + b*Tan[c + d*x])/(a + I*b)])*(a*Cos[c + d*x] + b*Sin[c + d*x])))} *)
{Cos[c + d*x]^2*(a + b*Tan[c + d*x])^n, x, 5, -(((I*a + b - b*n)*Hypergeometric2F1[1, 1 + n, 2 + n, (a + b*Tan[c + d*x])/(a - I*b)]*(a + b*Tan[c + d*x])^(1 + n))/(4*(a - I*b)^2*d*(1 + n))) + ((I*a - b*(1 - n))*Hypergeometric2F1[1, 1 + n, 2 + n, (a + b*Tan[c + d*x])/(a + I*b)]*(a + b*Tan[c + d*x])^(1 + n))/(4*(a + I*b)^2*d*(1 + n)) + ((b + a*Tan[c + d*x])*(a + b*Tan[c + d*x])^(1 + n))/(2*(a^2 + b^2)*d*(1 + Tan[c + d*x]^2))}
(* {Cos[c + d*x]^1*(a + b*Tan[c + d*x])^n, x, 0, (2*(a^2 + b^2)*(2 + n)*AppellF1[1 + n, 3/2, 3/2, 2 + n, (a + b*Tan[c + d*x])/(a - I*b), (a + b*Tan[c + d*x])/(a + I*b)]*Cos[c + d*x]^4*(a + b*Tan[c + d*x])^(1 + n))/(b*d*(1 + n)*(2*(a^2 + b^2)*(2 + n)*AppellF1[1 + n, 3/2, 3/2, 2 + n, (a + b*Tan[c + d*x])/(a - I*b), (a + b*Tan[c + d*x])/(a + I*b)]*Cos[c + d*x] + 3*((a - I*b)*AppellF1[2 + n, 3/2, 5/2, 3 + n, (a + b*Tan[c + d*x])/(a - I*b), (a + b*Tan[c + d*x])/(a + I*b)] + (a + I*b)*AppellF1[2 + n, 5/2, 3/2, 3 + n, (a + b*Tan[c + d*x])/(a - I*b), (a + b*Tan[c + d*x])/(a + I*b)])*(a*Cos[c + d*x] + b*Sin[c + d*x])))} *)
(* {Sec[c + d*x]^1*(a + b*Tan[c + d*x])^n, x, 0, -((b*(-1 + n)*AppellF1[-n, 1/2, -n, 1 - n, 2*Cos[c + d*x]*(Cos[c + d*x] - I*Sin[c + d*x]), (a + I*b)/(I*b - b*Tan[c + d*x])]*Cos[c + d*x]*(I + Tan[c + d*x])*(a + b*Tan[c + d*x])^n)/(d*n*(((-I)*a + b)*n*AppellF1[1 - n, 1/2, 1 - n, 2 - n, 2*Cos[c + d*x]*(Cos[c + d*x] - I*Sin[c + d*x]), (a + I*b)/(I*b - b*Tan[c + d*x])]*Cos[c + d*x] - b*(AppellF1[1 - n, 3/2, -n, 2 - n, 2*Cos[c + d*x]*(Cos[c + d*x] - I*Sin[c + d*x]), (a + I*b)/(I*b - b*Tan[c + d*x])]*Cos[c + d*x] - (-1 + n)*AppellF1[-n, 1/2, -n, 1 - n, 2*Cos[c + d*x]*(Cos[c + d*x] - I*Sin[c + d*x]), (a + I*b)/(I*b - b*Tan[c + d*x])]*(Cos[c + d*x] + I*Sin[c + d*x])))*(Cos[c + d*x] - I*Sin[c + d*x])^3))} *)
{Sec[c + d*x]^2*(a + b*Tan[c + d*x])^n, x, 2, (a + b*Tan[c + d*x])^(1 + n)/(b*d*(1 + n))}
(* {Sec[c + d*x]^3*(a + b*Tan[c + d*x])^n, x, 0, (20*(a + I*b)*AppellF1[3/2, -(1/2), -n, 5/2, (1/2)*(1 + I*Tan[c + d*x]), -((b*(-I + Tan[c + d*x]))/(a + I*b))]*Sec[c + d*x]*(Cos[c + d*x] + I*Sin[c + d*x])*(a + b*Tan[c + d*x])^n)/(3*d*(10*I*(a + I*b)*AppellF1[3/2, -(1/2), -n, 5/2, (1/2)*(1 + I*Tan[c + d*x]), -((b*(-I + Tan[c + d*x]))/(a + I*b))]*Cos[c + d*x] + (4*b*n*AppellF1[5/2, -(1/2), 1 - n, 7/2, (1/2)*(1 + I*Tan[c + d*x]), -((b*(-I + Tan[c + d*x]))/(a + I*b))] + ((-I)*a + b)*AppellF1[5/2, 1/2, -n, 7/2, (1/2)*(1 + I*Tan[c + d*x]), -((b*(-I + Tan[c + d*x]))/(a + I*b))])*(Cos[c + d*x] + I*Sin[c + d*x])))} *)
{Sec[c + d*x]^4*(a + b*Tan[c + d*x])^n, x, 3, ((a^2 + b^2)*(a + b*Tan[c + d*x])^(1 + n))/(b^3*d*(1 + n)) - (2*a*(a + b*Tan[c + d*x])^(2 + n))/(b^3*d*(2 + n)) + (a + b*Tan[c + d*x])^(3 + n)/(b^3*d*(3 + n))}
