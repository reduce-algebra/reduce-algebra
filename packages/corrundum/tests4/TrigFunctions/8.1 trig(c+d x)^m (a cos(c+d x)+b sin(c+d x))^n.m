(* ::Package:: *)

(* ::Title:: *)
(*Integrands of the form trig(c+d x)^m (a cos(c+d x)+b sin(c+d x))^n*)


(* ::Section::Closed:: *)
(*Integrands of the form Sin[c+d x]^m (a Cos[c+d x]+b Sin[c+d x])^n*)


(* ::Subsection::Closed:: *)
(*Integrands of the form Sin[c+d x]^m (a Cos[c+d x]+b Sin[c+d x])^n*)


(* ::Subsubsection::Closed:: *)
(*n>0*)


{Sin[x]^3*(a*Cos[x] + b*Sin[x]), x, 5, (3*b*x)/8 - (3/8)*b*Cos[x]*Sin[x] - (1/4)*b*Cos[x]*Sin[x]^3 + (1/4)*a*Sin[x]^4}
{Sin[x]^2*(a*Cos[x] + b*Sin[x]), x, 5, (-b)*Cos[x] + (1/3)*b*Cos[x]^3 + (1/3)*a*Sin[x]^3}
{Sin[x]^1*(a*Cos[x] + b*Sin[x]), x, 4, (b*x)/2 - (1/2)*b*Cos[x]*Sin[x] + (1/2)*a*Sin[x]^2}
{Sin[x]^0*(a*Cos[x] + b*Sin[x]), x, 3, (-b)*Cos[x] + a*Sin[x]}
{Csc[x]^1*(a*Cos[x] + b*Sin[x]), x, 3, b*x + a*Log[Sin[x]]}
{Csc[x]^2*(a*Cos[x] + b*Sin[x]), x, 4, (-b)*ArcTanh[Cos[x]] - a*Csc[x]}
{Csc[x]^3*(a*Cos[x] + b*Sin[x]), x, 4, (-b)*Cot[x] - (1/2)*a*Csc[x]^2}


(* ::Subsubsection::Closed:: *)
(*n<0*)


{Sin[x]^3/(a*Cos[x] + b*Sin[x]), x, 4, (a^2*b*x)/(a^2 + b^2)^2 + (b*x)/(2*(a^2 + b^2)) - (a^3*Log[a*Cos[x] + b*Sin[x]])/(a^2 + b^2)^2 - (b*Cos[x]*Sin[x])/(2*(a^2 + b^2)) - (a*Sin[x]^2)/(2*(a^2 + b^2))}
{Sin[x]^2/(a*Cos[x] + b*Sin[x]), x, 4, -((a^2*ArcTanh[(b*Cos[x] - a*Sin[x])/Sqrt[a^2 + b^2]])/(a^2 + b^2)^(3/2)) - (b*Cos[x])/(a^2 + b^2) - (a*Sin[x])/(a^2 + b^2)}
{Sin[x]^1/(a*Cos[x] + b*Sin[x]), x, 2, (b*x)/(a^2 + b^2) - (a*Log[a*Cos[x] + b*Sin[x]])/(a^2 + b^2)}
{Sin[x]^0/(a*Cos[x] + b*Sin[x]), x, 2, -(ArcTanh[(b*Cos[x] - a*Sin[x])/Sqrt[a^2 + b^2]]/Sqrt[a^2 + b^2])}
{Csc[x]^1/(a*Cos[x] + b*Sin[x]), x, 3, Log[Sin[x]]/a - Log[a*Cos[x] + b*Sin[x]]/a}
{Csc[x]^2/(a*Cos[x] + b*Sin[x]), x, 4, (b*ArcTanh[Cos[x]])/a^2 - (Sqrt[a^2 + b^2]*ArcTanh[(b*Cos[x] - a*Sin[x])/Sqrt[a^2 + b^2]])/a^2 - Csc[x]/a}
{Csc[x]^3/(a*Cos[x] + b*Sin[x]), x, 5, (b*Cot[x])/a^2 - Csc[x]^2/(2*a) + ((a^2 + b^2)*Log[Sin[x]])/a^3 - ((a^2 + b^2)*Log[a*Cos[x] + b*Sin[x]])/a^3}


{Sin[x]^3/(a*Cos[x] + b*Sin[x])^2, x, 0, (12*a^2*b*Sqrt[a^2 + b^2]*ArcTanh[(-b + a*Tan[x/2])/Sqrt[a^2 + b^2]]*(a*Cos[x] + b*Sin[x]) + (a^2 + b^2)*(3*a*(a^2 - b^2) + a*(a^2 + b^2)*Cos[2*x] - b*(a^2 + b^2)*Sin[2*x]))/(2*(a^2 + b^2)^3*(a*Cos[x] + b*Sin[x]))}
{Sin[x]^2/(a*Cos[x] + b*Sin[x])^2, x, 6, -(((a^2 - b^2)*x)/(a^2 + b^2)^2) + a/((a^2 + b^2)*(b + a*Cot[x])) - (2*a*b*Log[b + a*Cot[x]])/(a^2 + b^2)^2 - (2*a*b*Log[Sin[x]])/(a^2 + b^2)^2}
{Sin[x]^1/(a*Cos[x] + b*Sin[x])^2, x, 3, -((b*ArcTanh[(b*Cos[x] - a*Sin[x])/Sqrt[a^2 + b^2]])/(a^2 + b^2)^(3/2)) + a/((a^2 + b^2)*(a*Cos[x] + b*Sin[x]))}
{Sin[x]^0/(a*Cos[x] + b*Sin[x])^2, x, 1, Sin[x]/(a*(a*Cos[x] + b*Sin[x]))}
{Csc[x]^1/(a*Cos[x] + b*Sin[x])^2, x, 4, -(ArcTanh[Cos[x]]/a^2) + (b*ArcTanh[(b*Cos[x] - a*Sin[x])/Sqrt[a^2 + b^2]])/(a^2*Sqrt[a^2 + b^2]) + 1/(a*(a*Cos[x] + b*Sin[x]))}
{Csc[x]^2/(a*Cos[x] + b*Sin[x])^2, x, 3, -(Cot[x]/a^2) - (2*b*Log[Tan[x]])/a^3 + (2*b*Log[a + b*Tan[x]])/a^3 - (1/b + b/a^2)/(a + b*Tan[x])}
{Csc[x]^3/(a*Cos[x] + b*Sin[x])^2, x, 11, -(ArcTanh[Cos[x]]/(2*a^2)) - (2*b^2*ArcTanh[Cos[x]])/a^4 - ((a^2 + b^2)*ArcTanh[Cos[x]])/a^4 + (3*b*Sqrt[a^2 + b^2]*ArcTanh[(b*Cos[x] - a*Sin[x])/Sqrt[a^2 + b^2]])/a^4 + (2*b*Csc[x])/a^3 - (Cot[x]*Csc[x])/(2*a^2) + (a^2 + b^2)/(a^3*(a*Cos[x] + b*Sin[x]))}


{Sin[x]^3/(a*Cos[x] + b*Sin[x])^3, x, 7, -((b*(3*a^2 - b^2)*x)/(a^2 + b^2)^3) + a/(2*(a^2 + b^2)*(b + a*Cot[x])^2) + (2*a*b)/((a^2 + b^2)^2*(b + a*Cot[x])) + (a*(a^2 - 3*b^2)*Log[b + a*Cot[x]])/(a^2 + b^2)^3 + (a*(a^2 - 3*b^2)*Log[Sin[x]])/(a^2 + b^2)^3}
{Sin[x]^2/(a*Cos[x] + b*Sin[x])^3, x, 0, -(((a^2 - 2*b^2)*ArcTanh[(-b + a*Tan[x/2])/Sqrt[a^2 + b^2]])/(a^2 + b^2)^(5/2)) + (a*(3*a*b*Cos[x] + (a^2 + 4*b^2)*Sin[x]))/(2*(a^2 + b^2)^2*(a*Cos[x] + b*Sin[x])^2)}
{Sin[x]^1/(a*Cos[x] + b*Sin[x])^3, x, 2, 1/(2*a*(b + a*Cot[x])^2), Tan[x]^2/(2*a*(a + b*Tan[x])^2)}
{Sin[x]^0/(a*Cos[x] + b*Sin[x])^3, x, 3, -(ArcTanh[(b*Cos[x] - a*Sin[x])/Sqrt[a^2 + b^2]]/(2*(a^2 + b^2)^(3/2))) - (b*Cos[x] - a*Sin[x])/(2*(a^2 + b^2)*(a*Cos[x] + b*Sin[x])^2)}
{Csc[x]^1/(a*Cos[x] + b*Sin[x])^3, x, 3, Log[Tan[x]]/a^3 - Log[a + b*Tan[x]]/a^3 + (1/a + a/b^2)/(2*(a + b*Tan[x])^2) + (1/a^2 - 1/b^2)/(a + b*Tan[x])}
{Csc[x]^2/(a*Cos[x] + b*Sin[x])^3, x, 12, (3*b*ArcTanh[Cos[x]])/a^4 - ArcTanh[(b*Cos[x] - a*Sin[x])/Sqrt[a^2 + b^2]]/(2*a^2*Sqrt[a^2 + b^2]) - (2*b^2*ArcTanh[(b*Cos[x] - a*Sin[x])/Sqrt[a^2 + b^2]])/(a^4*Sqrt[a^2 + b^2]) - (Sqrt[a^2 + b^2]*ArcTanh[(b*Cos[x] - a*Sin[x])/Sqrt[a^2 + b^2]])/a^4 - Csc[x]/a^3 - (b*Cos[x] - a*Sin[x])/(2*a^2*(a*Cos[x] + b*Sin[x])^2) - (2*b)/(a^3*(a*Cos[x] + b*Sin[x]))}
{Csc[x]^3/(a*Cos[x] + b*Sin[x])^3, x, 3, (3*b*Cot[x])/a^4 - Cot[x]^2/(2*a^3) + (2*(a^2 + 3*b^2)*Log[Tan[x]])/a^5 - (2*(a^2 + 3*b^2)*Log[a + b*Tan[x]])/a^5 + (a^2 + b^2)^2/(2*a^3*b^2*(a + b*Tan[x])^2) - ((a^2 - 3*b^2)*(a^2 + b^2))/(a^4*b^2*(a + b*Tan[x]))}


(* ::Subsection:: *)
(*Integrands of the form Sin[c+d x]^m (a Cos[c+d x]+b Sin[c+d x])^n when a^2+b^2=0*)


(* ::Section::Closed:: *)
(*Integrands of the form Cos[c+d x]^m (a Cos[c+d x]+b Sin[c+d x])^n*)


(* ::Subsection::Closed:: *)
(*Integrands of the form Cos[c+d x]^m (a Cos[c+d x]+b Sin[c+d x])^n*)


(* ::Subsubsection::Closed:: *)
(*n>0*)


{Cos[c + d*x]^5*(a*Cos[c + d*x] + b*Sin[c + d*x]), x, 6, (5*a*x)/16 - (b*Cos[c + d*x]^6)/(6*d) + (5*a*Cos[c + d*x]*Sin[c + d*x])/(16*d) + (5*a*Cos[c + d*x]^3*Sin[c + d*x])/(24*d) + (a*Cos[c + d*x]^5*Sin[c + d*x])/(6*d)}
{Cos[c + d*x]^4*(a*Cos[c + d*x] + b*Sin[c + d*x]), x, 5, -((b*Cos[c + d*x]^5)/(5*d)) + (a*Sin[c + d*x])/d - (2*a*Sin[c + d*x]^3)/(3*d) + (a*Sin[c + d*x]^5)/(5*d)}
{Cos[c + d*x]^3*(a*Cos[c + d*x] + b*Sin[c + d*x]), x, 5, (3*a*x)/8 - (b*Cos[c + d*x]^4)/(4*d) + (3*a*Cos[c + d*x]*Sin[c + d*x])/(8*d) + (a*Cos[c + d*x]^3*Sin[c + d*x])/(4*d)}
{Cos[c + d*x]^2*(a*Cos[c + d*x] + b*Sin[c + d*x]), x, 5, -((b*Cos[c + d*x]^3)/(3*d)) + (a*Sin[c + d*x])/d - (a*Sin[c + d*x]^3)/(3*d)}
{Cos[c + d*x]^1*(a*Cos[c + d*x] + b*Sin[c + d*x]), x, 4, (a*x)/2 + (a*Cos[c + d*x]*Sin[c + d*x])/(2*d) + (b*Sin[c + d*x]^2)/(2*d)}
{Cos[c + d*x]^0*(a*Cos[c + d*x] + b*Sin[c + d*x]), x, 3, -((b*Cos[c + d*x])/d) + (a*Sin[c + d*x])/d}
{Sec[c + d*x]^1*(a*Cos[c + d*x] + b*Sin[c + d*x]), x, 3, a*x - (b*Log[Cos[c + d*x]])/d}
{Sec[c + d*x]^2*(a*Cos[c + d*x] + b*Sin[c + d*x]), x, 4, (a*ArcTanh[Sin[c + d*x]])/d + (b*Sec[c + d*x])/d}
{Sec[c + d*x]^3*(a*Cos[c + d*x] + b*Sin[c + d*x]), x, 4, (b*Sec[c + d*x]^2)/(2*d) + (a*Tan[c + d*x])/d}
{Sec[c + d*x]^4*(a*Cos[c + d*x] + b*Sin[c + d*x]), x, 5, (a*ArcTanh[Sin[c + d*x]])/(2*d) + (b*Sec[c + d*x]^3)/(3*d) + (a*Sec[c + d*x]*Tan[c + d*x])/(2*d)}
{Sec[c + d*x]^5*(a*Cos[c + d*x] + b*Sin[c + d*x]), x, 5, (b*Sec[c + d*x]^4)/(4*d) + (a*Tan[c + d*x])/d + (a*Tan[c + d*x]^3)/(3*d)}
{Sec[c + d*x]^6*(a*Cos[c + d*x] + b*Sin[c + d*x]), x, 6, (3*a*ArcTanh[Sin[c + d*x]])/(8*d) + (b*Sec[c + d*x]^5)/(5*d) + (3*a*Sec[c + d*x]*Tan[c + d*x])/(8*d) + (a*Sec[c + d*x]^3*Tan[c + d*x])/(4*d)}
{Sec[c + d*x]^7*(a*Cos[c + d*x] + b*Sin[c + d*x]), x, 5, (b*Sec[c + d*x]^6)/(6*d) + (a*Tan[c + d*x])/d + (2*a*Tan[c + d*x]^3)/(3*d) + (a*Tan[c + d*x]^5)/(5*d)}


{Cos[c + d*x]^5*(a*Cos[c + d*x] + b*Sin[c + d*x])^2, x, 8, -((2*a*b*Cos[c + d*x]^7)/(7*d)) + (a^2*Sin[c + d*x])/d - (a^2*Sin[c + d*x]^3)/d + (b^2*Sin[c + d*x]^3)/(3*d) + (3*a^2*Sin[c + d*x]^5)/(5*d) - (2*b^2*Sin[c + d*x]^5)/(5*d) - (a^2*Sin[c + d*x]^7)/(7*d) + (b^2*Sin[c + d*x]^7)/(7*d)}
{Cos[c + d*x]^4*(a*Cos[c + d*x] + b*Sin[c + d*x])^2, x, 9, (5*a^2*x)/16 + (b^2*x)/16 - (a*b*Cos[c + d*x]^6)/(3*d) + (5*a^2*Cos[c + d*x]*Sin[c + d*x])/(16*d) + (b^2*Cos[c + d*x]*Sin[c + d*x])/(16*d) + (5*a^2*Cos[c + d*x]^3*Sin[c + d*x])/(24*d) + (b^2*Cos[c + d*x]^3*Sin[c + d*x])/(24*d) + (a^2*Cos[c + d*x]^5*Sin[c + d*x])/(6*d) - (b^2*Cos[c + d*x]^5*Sin[c + d*x])/(6*d)}
{Cos[c + d*x]^3*(a*Cos[c + d*x] + b*Sin[c + d*x])^2, x, 8, -((2*a*b*Cos[c + d*x]^5)/(5*d)) + (a^2*Sin[c + d*x])/d - (2*a^2*Sin[c + d*x]^3)/(3*d) + (b^2*Sin[c + d*x]^3)/(3*d) + (a^2*Sin[c + d*x]^5)/(5*d) - (b^2*Sin[c + d*x]^5)/(5*d)}
{Cos[c + d*x]^2*(a*Cos[c + d*x] + b*Sin[c + d*x])^2, x, 7, (3*a^2*x)/8 + (b^2*x)/8 - (a*b*Cos[c + d*x]^4)/(2*d) + (3*a^2*Cos[c + d*x]*Sin[c + d*x])/(8*d) + (b^2*Cos[c + d*x]*Sin[c + d*x])/(8*d) + (a^2*Cos[c + d*x]^3*Sin[c + d*x])/(4*d) - (b^2*Cos[c + d*x]^3*Sin[c + d*x])/(4*d)}
{Cos[c + d*x]^1*(a*Cos[c + d*x] + b*Sin[c + d*x])^2, x, 6, -((2*a*b*Cos[c + d*x]^3)/(3*d)) + (a^2*Sin[c + d*x])/d - (a^2*Sin[c + d*x]^3)/(3*d) + (b^2*Sin[c + d*x]^3)/(3*d)}
{Cos[c + d*x]^0*(a*Cos[c + d*x] + b*Sin[c + d*x])^2, x, 2, (1/2)*(a^2 + b^2)*x - ((b*Cos[c + d*x] - a*Sin[c + d*x])*(a*Cos[c + d*x] + b*Sin[c + d*x]))/(2*d)}
{Sec[c + d*x]^1*(a*Cos[c + d*x] + b*Sin[c + d*x])^2, x, 6, (b^2*ArcTanh[Sin[c + d*x]])/d - (2*a*b*Cos[c + d*x])/d + (a^2*Sin[c + d*x])/d - (b^2*Sin[c + d*x])/d}
{Sec[c + d*x]^2*(a*Cos[c + d*x] + b*Sin[c + d*x])^2, x, 3, (a^2 - b^2)*x - (2*a*b*Log[Cos[c + d*x]])/d + (b^2*Tan[c + d*x])/d}
{Sec[c + d*x]^3*(a*Cos[c + d*x] + b*Sin[c + d*x])^2, x, 6, (a^2*ArcTanh[Sin[c + d*x]])/d - (b^2*ArcTanh[Sin[c + d*x]])/(2*d) + (2*a*b*Sec[c + d*x])/d + (b^2*Sec[c + d*x]*Tan[c + d*x])/(2*d)}
{Sec[c + d*x]^4*(a*Cos[c + d*x] + b*Sin[c + d*x])^2, x, 2, ((b + a*Cot[c + d*x])^3*Tan[c + d*x]^3)/(3*b*d)}
{Sec[c + d*x]^5*(a*Cos[c + d*x] + b*Sin[c + d*x])^2, x, 8, (a^2*ArcTanh[Sin[c + d*x]])/(2*d) - (b^2*ArcTanh[Sin[c + d*x]])/(8*d) + (2*a*b*Sec[c + d*x]^3)/(3*d) + (a^2*Sec[c + d*x]*Tan[c + d*x])/(2*d) + (b^2*Sec[c + d*x]*Tan[c + d*x])/(8*d) + (b^2*Sec[c + d*x]*Tan[c + d*x]^3)/(4*d)}
{Sec[c + d*x]^6*(a*Cos[c + d*x] + b*Sin[c + d*x])^2, x, 3, (a^2*Tan[c + d*x])/d + (a*b*Tan[c + d*x]^2)/d + ((a^2 + b^2)*Tan[c + d*x]^3)/(3*d) + (a*b*Tan[c + d*x]^4)/(2*d) + (b^2*Tan[c + d*x]^5)/(5*d)}
{Sec[c + d*x]^7*(a*Cos[c + d*x] + b*Sin[c + d*x])^2, x, 10, (3*a^2*ArcTanh[Sin[c + d*x]])/(8*d) - (b^2*ArcTanh[Sin[c + d*x]])/(16*d) + (2*a*b*Sec[c + d*x]^5)/(5*d) + (3*a^2*Sec[c + d*x]*Tan[c + d*x])/(8*d) + (b^2*Sec[c + d*x]*Tan[c + d*x])/(16*d) + (a^2*Sec[c + d*x]^3*Tan[c + d*x])/(4*d) + (b^2*Sec[c + d*x]*Tan[c + d*x]^3)/(8*d) + (b^2*Sec[c + d*x]^3*Tan[c + d*x]^3)/(6*d)}
{Sec[c + d*x]^8*(a*Cos[c + d*x] + b*Sin[c + d*x])^2, x, 3, (a^2*Tan[c + d*x])/d + (a*b*Tan[c + d*x]^2)/d + ((2*a^2 + b^2)*Tan[c + d*x]^3)/(3*d) + (a*b*Tan[c + d*x]^4)/d + ((a^2 + 2*b^2)*Tan[c + d*x]^5)/(5*d) + (a*b*Tan[c + d*x]^6)/(3*d) + (b^2*Tan[c + d*x]^7)/(7*d)}


{Cos[c + d*x]^5*(a*Cos[c + d*x] + b*Sin[c + d*x])^3, x, 14, (35*a^3*x)/128 + (15/128)*a*b^2*x - (b^3*Cos[c + d*x]^6)/(6*d) - (3*a^2*b*Cos[c + d*x]^8)/(8*d) + (b^3*Cos[c + d*x]^8)/(8*d) + (35*a^3*Cos[c + d*x]*Sin[c + d*x])/(128*d) + (15*a*b^2*Cos[c + d*x]*Sin[c + d*x])/(128*d) + (35*a^3*Cos[c + d*x]^3*Sin[c + d*x])/(192*d) + (5*a*b^2*Cos[c + d*x]^3*Sin[c + d*x])/(64*d) + (7*a^3*Cos[c + d*x]^5*Sin[c + d*x])/(48*d) + (a*b^2*Cos[c + d*x]^5*Sin[c + d*x])/(16*d) + (a^3*Cos[c + d*x]^7*Sin[c + d*x])/(8*d) - (3*a*b^2*Cos[c + d*x]^7*Sin[c + d*x])/(8*d)}
{Cos[c + d*x]^4*(a*Cos[c + d*x] + b*Sin[c + d*x])^3, x, 11, -((b^3*Cos[c + d*x]^5)/(5*d)) - (3*a^2*b*Cos[c + d*x]^7)/(7*d) + (b^3*Cos[c + d*x]^7)/(7*d) + (a^3*Sin[c + d*x])/d - (a^3*Sin[c + d*x]^3)/d + (a*b^2*Sin[c + d*x]^3)/d + (3*a^3*Sin[c + d*x]^5)/(5*d) - (6*a*b^2*Sin[c + d*x]^5)/(5*d) - (a^3*Sin[c + d*x]^7)/(7*d) + (3*a*b^2*Sin[c + d*x]^7)/(7*d)}
{Cos[c + d*x]^3*(a*Cos[c + d*x] + b*Sin[c + d*x])^3, x, 12, (5*a^3*x)/16 + (3/16)*a*b^2*x - (a^2*b*Cos[c + d*x]^6)/(2*d) + (5*a^3*Cos[c + d*x]*Sin[c + d*x])/(16*d) + (3*a*b^2*Cos[c + d*x]*Sin[c + d*x])/(16*d) + (5*a^3*Cos[c + d*x]^3*Sin[c + d*x])/(24*d) + (a*b^2*Cos[c + d*x]^3*Sin[c + d*x])/(8*d) + (a^3*Cos[c + d*x]^5*Sin[c + d*x])/(6*d) - (a*b^2*Cos[c + d*x]^5*Sin[c + d*x])/(2*d) + (b^3*Sin[c + d*x]^4)/(4*d) - (b^3*Sin[c + d*x]^6)/(6*d)}
{Cos[c + d*x]^2*(a*Cos[c + d*x] + b*Sin[c + d*x])^3, x, 11, -((b^3*Cos[c + d*x]^3)/(3*d)) - (3*a^2*b*Cos[c + d*x]^5)/(5*d) + (b^3*Cos[c + d*x]^5)/(5*d) + (a^3*Sin[c + d*x])/d - (2*a^3*Sin[c + d*x]^3)/(3*d) + (a*b^2*Sin[c + d*x]^3)/d + (a^3*Sin[c + d*x]^5)/(5*d) - (3*a*b^2*Sin[c + d*x]^5)/(5*d)}
{Cos[c + d*x]^1*(a*Cos[c + d*x] + b*Sin[c + d*x])^3, x, 5, (3/8)*a*(a^2 + b^2)*x + (b + a*Cot[c + d*x])^3/(4*d*(1 + Cot[c + d*x]^2)^2) + (3*a*(b + a*Cot[c + d*x])*(a - b*Cot[c + d*x]))/(8*d*(1 + Cot[c + d*x]^2))}
{Cos[c + d*x]^0*(a*Cos[c + d*x] + b*Sin[c + d*x])^3, x, 2, -(((a^2 + b^2)*(b*Cos[c + d*x] - a*Sin[c + d*x]))/d) + (b*Cos[c + d*x] - a*Sin[c + d*x])^3/(3*d)}
{Sec[c + d*x]^1*(a*Cos[c + d*x] + b*Sin[c + d*x])^3, x, 8, a^3*x - (1/2)*a*(a^2 - 3*b^2)*x + (b*(3*a^2 - b^2) + a*(a^2 - 3*b^2)*Cot[c + d*x])/(2*d*(1 + Cot[c + d*x]^2)) - (b^3*Log[Cot[c + d*x]])/d + (b^3*Log[1 + Cot[c + d*x]^2])/(2*d)}
{Sec[c + d*x]^2*(a*Cos[c + d*x] + b*Sin[c + d*x])^3, x, 9, (3*a*b^2*ArcTanh[Sin[c + d*x]])/d - (3*a^2*b*Cos[c + d*x])/d + (b^3*Cos[c + d*x])/d + (b^3*Sec[c + d*x])/d + (a^3*Sin[c + d*x])/d - (3*a*b^2*Sin[c + d*x])/d}
{Sec[c + d*x]^3*(a*Cos[c + d*x] + b*Sin[c + d*x])^3, x, 5, a*(a^2 - 3*b^2)*x - (b*(3*a^2 - b^2)*Log[Cos[c + d*x]])/d + (2*a*b*(a + b*Tan[c + d*x]))/d + (b*(a + b*Tan[c + d*x])^2)/(2*d)}
{Sec[c + d*x]^4*(a*Cos[c + d*x] + b*Sin[c + d*x])^3, x, 8, (a^3*ArcTanh[Sin[c + d*x]])/d - (3*a*b^2*ArcTanh[Sin[c + d*x]])/(2*d) + (3*a^2*b*Sec[c + d*x])/d - (b^3*Sec[c + d*x])/d + (b^3*Sec[c + d*x]^3)/(3*d) + (3*a*b^2*Sec[c + d*x]*Tan[c + d*x])/(2*d)}
{Sec[c + d*x]^5*(a*Cos[c + d*x] + b*Sin[c + d*x])^3, x, 2, ((b + a*Cot[c + d*x])^4*Tan[c + d*x]^4)/(4*b*d)}
{Sec[c + d*x]^6*(a*Cos[c + d*x] + b*Sin[c + d*x])^3, x, 11, (a^3*ArcTanh[Sin[c + d*x]])/(2*d) - (3*a*b^2*ArcTanh[Sin[c + d*x]])/(8*d) + (a^2*b*Sec[c + d*x]^3)/d - (b^3*Sec[c + d*x]^3)/(3*d) + (b^3*Sec[c + d*x]^5)/(5*d) + (a^3*Sec[c + d*x]*Tan[c + d*x])/(2*d) + (3*a*b^2*Sec[c + d*x]*Tan[c + d*x])/(8*d) + (3*a*b^2*Sec[c + d*x]*Tan[c + d*x]^3)/(4*d)}
{Sec[c + d*x]^7*(a*Cos[c + d*x] + b*Sin[c + d*x])^3, x, 3, (a^3*Tan[c + d*x])/d + (3*a^2*b*Tan[c + d*x]^2)/(2*d) + (a*(a^2 + 3*b^2)*Tan[c + d*x]^3)/(3*d) + (b*(3*a^2 + b^2)*Tan[c + d*x]^4)/(4*d) + (3*a*b^2*Tan[c + d*x]^5)/(5*d) + (b^3*Tan[c + d*x]^6)/(6*d)}
{Sec[c + d*x]^8*(a*Cos[c + d*x] + b*Sin[c + d*x])^3, x, 13, (3*a^3*ArcTanh[Sin[c + d*x]])/(8*d) - (3*a*b^2*ArcTanh[Sin[c + d*x]])/(16*d) + (3*a^2*b*Sec[c + d*x]^5)/(5*d) - (b^3*Sec[c + d*x]^5)/(5*d) + (b^3*Sec[c + d*x]^7)/(7*d) + (3*a^3*Sec[c + d*x]*Tan[c + d*x])/(8*d) + (3*a*b^2*Sec[c + d*x]*Tan[c + d*x])/(16*d) + (a^3*Sec[c + d*x]^3*Tan[c + d*x])/(4*d) + (3*a*b^2*Sec[c + d*x]*Tan[c + d*x]^3)/(8*d) + (a*b^2*Sec[c + d*x]^3*Tan[c + d*x]^3)/(2*d)}
{Sec[c + d*x]^9*(a*Cos[c + d*x] + b*Sin[c + d*x])^3, x, 3, (a^3*Tan[c + d*x])/d + (3*a^2*b*Tan[c + d*x]^2)/(2*d) + (a*(2*a^2 + 3*b^2)*Tan[c + d*x]^3)/(3*d) + (b*(6*a^2 + b^2)*Tan[c + d*x]^4)/(4*d) + (a*(a^2 + 6*b^2)*Tan[c + d*x]^5)/(5*d) + (b*(3*a^2 + 2*b^2)*Tan[c + d*x]^6)/(6*d) + (3*a*b^2*Tan[c + d*x]^7)/(7*d) + (b^3*Tan[c + d*x]^8)/(8*d)}
{Sec[c + d*x]^10*(a*Cos[c + d*x] + b*Sin[c + d*x])^3, x, 15, (5*a^3*ArcTanh[Sin[c + d*x]])/(16*d) - (15*a*b^2*ArcTanh[Sin[c + d*x]])/(128*d) + (3*a^2*b*Sec[c + d*x]^7)/(7*d) - (b^3*Sec[c + d*x]^7)/(7*d) + (b^3*Sec[c + d*x]^9)/(9*d) + (5*a^3*Sec[c + d*x]*Tan[c + d*x])/(16*d) + (15*a*b^2*Sec[c + d*x]*Tan[c + d*x])/(128*d) + (5*a^3*Sec[c + d*x]^3*Tan[c + d*x])/(24*d) + (a^3*Sec[c + d*x]^5*Tan[c + d*x])/(6*d) + (15*a*b^2*Sec[c + d*x]*Tan[c + d*x]^3)/(64*d) + (5*a*b^2*Sec[c + d*x]^3*Tan[c + d*x]^3)/(16*d) + (3*a*b^2*Sec[c + d*x]^5*Tan[c + d*x]^3)/(8*d)}
{Sec[c + d*x]^11*(a*Cos[c + d*x] + b*Sin[c + d*x])^3, x, 3, (a^3*Tan[c + d*x])/d + (3*a^2*b*Tan[c + d*x]^2)/(2*d) + (a*(a^2 + b^2)*Tan[c + d*x]^3)/d + (b*(9*a^2 + b^2)*Tan[c + d*x]^4)/(4*d) + (3*a*(a^2 + 3*b^2)*Tan[c + d*x]^5)/(5*d) + (b*(3*a^2 + b^2)*Tan[c + d*x]^6)/(2*d) + (a*(a^2 + 9*b^2)*Tan[c + d*x]^7)/(7*d) + (3*b*(a^2 + b^2)*Tan[c + d*x]^8)/(8*d) + (a*b^2*Tan[c + d*x]^9)/(3*d) + (b^3*Tan[c + d*x]^10)/(10*d)}


{Cos[c + d*x]^5*(a*Cos[c + d*x] + b*Sin[c + d*x])^4, x, 14, -((4*a*b^3*Cos[c + d*x]^7)/(7*d)) - (4*a^3*b*Cos[c + d*x]^9)/(9*d) + (4*a*b^3*Cos[c + d*x]^9)/(9*d) + (a^4*Sin[c + d*x])/d - (4*a^4*Sin[c + d*x]^3)/(3*d) + (2*a^2*b^2*Sin[c + d*x]^3)/d + (6*a^4*Sin[c + d*x]^5)/(5*d) - (18*a^2*b^2*Sin[c + d*x]^5)/(5*d) + (b^4*Sin[c + d*x]^5)/(5*d) - (4*a^4*Sin[c + d*x]^7)/(7*d) + (18*a^2*b^2*Sin[c + d*x]^7)/(7*d) - (2*b^4*Sin[c + d*x]^7)/(7*d) + (a^4*Sin[c + d*x]^9)/(9*d) - (2*a^2*b^2*Sin[c + d*x]^9)/(3*d) + (b^4*Sin[c + d*x]^9)/(9*d)}
{Cos[c + d*x]^4*(a*Cos[c + d*x] + b*Sin[c + d*x])^4, x, 18, (35*a^4*x)/128 + (15/64)*a^2*b^2*x + (3*b^4*x)/128 - (2*a*b^3*Cos[c + d*x]^6)/(3*d) - (a^3*b*Cos[c + d*x]^8)/(2*d) + (a*b^3*Cos[c + d*x]^8)/(2*d) + (35*a^4*Cos[c + d*x]*Sin[c + d*x])/(128*d) + (15*a^2*b^2*Cos[c + d*x]*Sin[c + d*x])/(64*d) + (3*b^4*Cos[c + d*x]*Sin[c + d*x])/(128*d) + (35*a^4*Cos[c + d*x]^3*Sin[c + d*x])/(192*d) + (5*a^2*b^2*Cos[c + d*x]^3*Sin[c + d*x])/(32*d) + (b^4*Cos[c + d*x]^3*Sin[c + d*x])/(64*d) + (7*a^4*Cos[c + d*x]^5*Sin[c + d*x])/(48*d) + (a^2*b^2*Cos[c + d*x]^5*Sin[c + d*x])/(8*d) - (b^4*Cos[c + d*x]^5*Sin[c + d*x])/(16*d) + (a^4*Cos[c + d*x]^7*Sin[c + d*x])/(8*d) - (3*a^2*b^2*Cos[c + d*x]^7*Sin[c + d*x])/(4*d) - (b^4*Cos[c + d*x]^5*Sin[c + d*x]^3)/(8*d)}
{Cos[c + d*x]^3*(a*Cos[c + d*x] + b*Sin[c + d*x])^4, x, 14, -((4*a*b^3*Cos[c + d*x]^5)/(5*d)) - (4*a^3*b*Cos[c + d*x]^7)/(7*d) + (4*a*b^3*Cos[c + d*x]^7)/(7*d) + (a^4*Sin[c + d*x])/d - (a^4*Sin[c + d*x]^3)/d + (2*a^2*b^2*Sin[c + d*x]^3)/d + (3*a^4*Sin[c + d*x]^5)/(5*d) - (12*a^2*b^2*Sin[c + d*x]^5)/(5*d) + (b^4*Sin[c + d*x]^5)/(5*d) - (a^4*Sin[c + d*x]^7)/(7*d) + (6*a^2*b^2*Sin[c + d*x]^7)/(7*d) - (b^4*Sin[c + d*x]^7)/(7*d)}
{Cos[c + d*x]^2*(a*Cos[c + d*x] + b*Sin[c + d*x])^4, x, 15, (5*a^4*x)/16 + (3/8)*a^2*b^2*x + (b^4*x)/16 - (2*a^3*b*Cos[c + d*x]^6)/(3*d) + (5*a^4*Cos[c + d*x]*Sin[c + d*x])/(16*d) + (3*a^2*b^2*Cos[c + d*x]*Sin[c + d*x])/(8*d) + (b^4*Cos[c + d*x]*Sin[c + d*x])/(16*d) + (5*a^4*Cos[c + d*x]^3*Sin[c + d*x])/(24*d) + (a^2*b^2*Cos[c + d*x]^3*Sin[c + d*x])/(4*d) - (b^4*Cos[c + d*x]^3*Sin[c + d*x])/(8*d) + (a^4*Cos[c + d*x]^5*Sin[c + d*x])/(6*d) - (a^2*b^2*Cos[c + d*x]^5*Sin[c + d*x])/d - (b^4*Cos[c + d*x]^3*Sin[c + d*x]^3)/(6*d) + (a*b^3*Sin[c + d*x]^4)/d - (2*a*b^3*Sin[c + d*x]^6)/(3*d)}
{Cos[c + d*x]^1*(a*Cos[c + d*x] + b*Sin[c + d*x])^4, x, 12, -((4*a*b^3*Cos[c + d*x]^3)/(3*d)) - (4*a^3*b*Cos[c + d*x]^5)/(5*d) + (4*a*b^3*Cos[c + d*x]^5)/(5*d) + (a^4*Sin[c + d*x])/d - (2*a^4*Sin[c + d*x]^3)/(3*d) + (2*a^2*b^2*Sin[c + d*x]^3)/d + (a^4*Sin[c + d*x]^5)/(5*d) - (6*a^2*b^2*Sin[c + d*x]^5)/(5*d) + (b^4*Sin[c + d*x]^5)/(5*d)}
{Cos[c + d*x]^0*(a*Cos[c + d*x] + b*Sin[c + d*x])^4, x, 3, (3/8)*(a^2 + b^2)^2*x - (3*(a^2 + b^2)*(b*Cos[c + d*x] - a*Sin[c + d*x])*(a*Cos[c + d*x] + b*Sin[c + d*x]))/(8*d) - ((b*Cos[c + d*x] - a*Sin[c + d*x])*(a*Cos[c + d*x] + b*Sin[c + d*x])^3)/(4*d)}
{Sec[c + d*x]^1*(a*Cos[c + d*x] + b*Sin[c + d*x])^4, x, 11, (b^4*ArcTanh[Sin[c + d*x]])/d - (4*a*b^3*Cos[c + d*x])/d - (4*a^3*b*Cos[c + d*x]^3)/(3*d) + (4*a*b^3*Cos[c + d*x]^3)/(3*d) + (a^4*Sin[c + d*x])/d - (b^4*Sin[c + d*x])/d - (a^4*Sin[c + d*x]^3)/(3*d) + (2*a^2*b^2*Sin[c + d*x]^3)/d - (b^4*Sin[c + d*x]^3)/(3*d)}
{Sec[c + d*x]^2*(a*Cos[c + d*x] + b*Sin[c + d*x])^4, x, 8, (a^4 - b^4)*x - (1/2)*(a^4 - 6*a^2*b^2 + b^4)*x + (4*a*b*(a^2 - b^2) + (a^4 - 6*a^2*b^2 + b^4)*Cot[c + d*x])/(2*d*(1 + Cot[c + d*x]^2)) - (4*a*b^3*Log[Cot[c + d*x]])/d + (2*a*b^3*Log[1 + Cot[c + d*x]^2])/d + (b^4*Tan[c + d*x])/d}
{Sec[c + d*x]^3*(a*Cos[c + d*x] + b*Sin[c + d*x])^4, x, 12, (6*a^2*b^2*ArcTanh[Sin[c + d*x]])/d - (3*b^4*ArcTanh[Sin[c + d*x]])/(2*d) - (4*a^3*b*Cos[c + d*x])/d + (4*a*b^3*Cos[c + d*x])/d + (4*a*b^3*Sec[c + d*x])/d + (a^4*Sin[c + d*x])/d - (6*a^2*b^2*Sin[c + d*x])/d + (3*b^4*Sin[c + d*x])/(2*d) + (b^4*Sin[c + d*x]*Tan[c + d*x]^2)/(2*d)}
{Sec[c + d*x]^4*(a*Cos[c + d*x] + b*Sin[c + d*x])^4, x, 6, (a^4 - 6*a^2*b^2 + b^4)*x - (4*a*b*(a^2 - b^2)*Log[Cos[c + d*x]])/d + (b*(3*a^2 - b^2)*(a + b*Tan[c + d*x]))/d + (a*b*(a + b*Tan[c + d*x])^2)/d + (b*(a + b*Tan[c + d*x])^3)/(3*d)}
{Sec[c + d*x]^5*(a*Cos[c + d*x] + b*Sin[c + d*x])^4, x, 11, (a^4*ArcTanh[Sin[c + d*x]])/d - (3*a^2*b^2*ArcTanh[Sin[c + d*x]])/d + (3*b^4*ArcTanh[Sin[c + d*x]])/(8*d) + (4*a^3*b*Sec[c + d*x])/d - (4*a*b^3*Sec[c + d*x])/d + (4*a*b^3*Sec[c + d*x]^3)/(3*d) + (3*a^2*b^2*Sec[c + d*x]*Tan[c + d*x])/d - (3*b^4*Sec[c + d*x]*Tan[c + d*x])/(8*d) + (b^4*Sec[c + d*x]*Tan[c + d*x]^3)/(4*d)}
{Sec[c + d*x]^6*(a*Cos[c + d*x] + b*Sin[c + d*x])^4, x, 2, ((b + a*Cot[c + d*x])^5*Tan[c + d*x]^5)/(5*b*d)}
{Sec[c + d*x]^7*(a*Cos[c + d*x] + b*Sin[c + d*x])^4, x, 15, (a^4*ArcTanh[Sin[c + d*x]])/(2*d) - (3*a^2*b^2*ArcTanh[Sin[c + d*x]])/(4*d) + (b^4*ArcTanh[Sin[c + d*x]])/(16*d) + (4*a^3*b*Sec[c + d*x]^3)/(3*d) - (4*a*b^3*Sec[c + d*x]^3)/(3*d) + (4*a*b^3*Sec[c + d*x]^5)/(5*d) + (a^4*Sec[c + d*x]*Tan[c + d*x])/(2*d) + (3*a^2*b^2*Sec[c + d*x]*Tan[c + d*x])/(4*d) - (b^4*Sec[c + d*x]*Tan[c + d*x])/(16*d) + (3*a^2*b^2*Sec[c + d*x]*Tan[c + d*x]^3)/(2*d) + (b^4*Sec[c + d*x]*Tan[c + d*x]^3)/(24*d) + (b^4*Sec[c + d*x]*Tan[c + d*x]^5)/(6*d)}
{Sec[c + d*x]^8*(a*Cos[c + d*x] + b*Sin[c + d*x])^4, x, 3, (a^4*Tan[c + d*x])/d + (2*a^3*b*Tan[c + d*x]^2)/d + (a^2*(a^2 + 6*b^2)*Tan[c + d*x]^3)/(3*d) + (a*b*(a^2 + b^2)*Tan[c + d*x]^4)/d + (b^2*(6*a^2 + b^2)*Tan[c + d*x]^5)/(5*d) + (2*a*b^3*Tan[c + d*x]^6)/(3*d) + (b^4*Tan[c + d*x]^7)/(7*d)}
{Sec[c + d*x]^9*(a*Cos[c + d*x] + b*Sin[c + d*x])^4, x, 18, (3*a^4*ArcTanh[Sin[c + d*x]])/(8*d) - (3*a^2*b^2*ArcTanh[Sin[c + d*x]])/(8*d) + (3*b^4*ArcTanh[Sin[c + d*x]])/(128*d) + (4*a^3*b*Sec[c + d*x]^5)/(5*d) - (4*a*b^3*Sec[c + d*x]^5)/(5*d) + (4*a*b^3*Sec[c + d*x]^7)/(7*d) + (3*a^4*Sec[c + d*x]*Tan[c + d*x])/(8*d) + (3*a^2*b^2*Sec[c + d*x]*Tan[c + d*x])/(8*d) - (3*b^4*Sec[c + d*x]*Tan[c + d*x])/(128*d) + (a^4*Sec[c + d*x]^3*Tan[c + d*x])/(4*d) + (3*a^2*b^2*Sec[c + d*x]*Tan[c + d*x]^3)/(4*d) + (b^4*Sec[c + d*x]*Tan[c + d*x]^3)/(64*d) + (a^2*b^2*Sec[c + d*x]^3*Tan[c + d*x]^3)/d + (b^4*Sec[c + d*x]*Tan[c + d*x]^5)/(16*d) + (b^4*Sec[c + d*x]^3*Tan[c + d*x]^5)/(8*d)}
{Sec[c + d*x]^10*(a*Cos[c + d*x] + b*Sin[c + d*x])^4, x, 3, (a^4*Tan[c + d*x])/d + (2*a^3*b*Tan[c + d*x]^2)/d + (2*a^2*(a^2 + 3*b^2)*Tan[c + d*x]^3)/(3*d) + (a*b*(2*a^2 + b^2)*Tan[c + d*x]^4)/d + ((a^4 + 12*a^2*b^2 + b^4)*Tan[c + d*x]^5)/(5*d) + (2*a*b*(a^2 + 2*b^2)*Tan[c + d*x]^6)/(3*d) + (2*b^2*(3*a^2 + b^2)*Tan[c + d*x]^7)/(7*d) + (a*b^3*Tan[c + d*x]^8)/(2*d) + (b^4*Tan[c + d*x]^9)/(9*d)}
{Sec[c + d*x]^11*(a*Cos[c + d*x] + b*Sin[c + d*x])^4, x, 21, (5*a^4*ArcTanh[Sin[c + d*x]])/(16*d) - (15*a^2*b^2*ArcTanh[Sin[c + d*x]])/(64*d) + (3*b^4*ArcTanh[Sin[c + d*x]])/(256*d) + (4*a^3*b*Sec[c + d*x]^7)/(7*d) - (4*a*b^3*Sec[c + d*x]^7)/(7*d) + (4*a*b^3*Sec[c + d*x]^9)/(9*d) + (5*a^4*Sec[c + d*x]*Tan[c + d*x])/(16*d) + (15*a^2*b^2*Sec[c + d*x]*Tan[c + d*x])/(64*d) - (3*b^4*Sec[c + d*x]*Tan[c + d*x])/(256*d) + (5*a^4*Sec[c + d*x]^3*Tan[c + d*x])/(24*d) + (a^4*Sec[c + d*x]^5*Tan[c + d*x])/(6*d) + (15*a^2*b^2*Sec[c + d*x]*Tan[c + d*x]^3)/(32*d) + (b^4*Sec[c + d*x]*Tan[c + d*x]^3)/(128*d) + (5*a^2*b^2*Sec[c + d*x]^3*Tan[c + d*x]^3)/(8*d) + (3*a^2*b^2*Sec[c + d*x]^5*Tan[c + d*x]^3)/(4*d) + (b^4*Sec[c + d*x]*Tan[c + d*x]^5)/(32*d) + (b^4*Sec[c + d*x]^3*Tan[c + d*x]^5)/(16*d) + (b^4*Sec[c + d*x]^5*Tan[c + d*x]^5)/(10*d)}
{Sec[c + d*x]^12*(a*Cos[c + d*x] + b*Sin[c + d*x])^4, x, 3, (a^4*Tan[c + d*x])/d + (2*a^3*b*Tan[c + d*x]^2)/d + (a^2*(a^2 + 2*b^2)*Tan[c + d*x]^3)/d + (a*b*(3*a^2 + b^2)*Tan[c + d*x]^4)/d + ((3*a^4 + 18*a^2*b^2 + b^4)*Tan[c + d*x]^5)/(5*d) + (2*a*b*(a^2 + b^2)*Tan[c + d*x]^6)/d + ((a^4 + 18*a^2*b^2 + 3*b^4)*Tan[c + d*x]^7)/(7*d) + (a*b*(a^2 + 3*b^2)*Tan[c + d*x]^8)/(2*d) + (b^2*(2*a^2 + b^2)*Tan[c + d*x]^9)/(3*d) + (2*a*b^3*Tan[c + d*x]^10)/(5*d) + (b^4*Tan[c + d*x]^11)/(11*d)}


{Cos[c + d*x]^5*(a*Cos[c + d*x] + b*Sin[c + d*x])^5, x, 25, (63*a^5*x)/256 + (35/128)*a^3*b^2*x + (15/256)*a*b^4*x - (5*a^2*b^3*Cos[c + d*x]^8)/(4*d) - (a^4*b*Cos[c + d*x]^10)/(2*d) + (a^2*b^3*Cos[c + d*x]^10)/d + (63*a^5*Cos[c + d*x]*Sin[c + d*x])/(256*d) + (35*a^3*b^2*Cos[c + d*x]*Sin[c + d*x])/(128*d) + (15*a*b^4*Cos[c + d*x]*Sin[c + d*x])/(256*d) + (21*a^5*Cos[c + d*x]^3*Sin[c + d*x])/(128*d) + (35*a^3*b^2*Cos[c + d*x]^3*Sin[c + d*x])/(192*d) + (5*a*b^4*Cos[c + d*x]^3*Sin[c + d*x])/(128*d) + (21*a^5*Cos[c + d*x]^5*Sin[c + d*x])/(160*d) + (7*a^3*b^2*Cos[c + d*x]^5*Sin[c + d*x])/(48*d) + (a*b^4*Cos[c + d*x]^5*Sin[c + d*x])/(32*d) + (9*a^5*Cos[c + d*x]^7*Sin[c + d*x])/(80*d) + (a^3*b^2*Cos[c + d*x]^7*Sin[c + d*x])/(8*d) - (3*a*b^4*Cos[c + d*x]^7*Sin[c + d*x])/(16*d) + (a^5*Cos[c + d*x]^9*Sin[c + d*x])/(10*d) - (a^3*b^2*Cos[c + d*x]^9*Sin[c + d*x])/d - (a*b^4*Cos[c + d*x]^7*Sin[c + d*x]^3)/(2*d) + (b^5*Sin[c + d*x]^6)/(6*d) - (b^5*Sin[c + d*x]^8)/(4*d) + (b^5*Sin[c + d*x]^10)/(10*d)}
{Cos[c + d*x]^4*(a*Cos[c + d*x] + b*Sin[c + d*x])^5, x, 17, -((b^5*Cos[c + d*x]^5)/(5*d)) - (10*a^2*b^3*Cos[c + d*x]^7)/(7*d) + (2*b^5*Cos[c + d*x]^7)/(7*d) - (5*a^4*b*Cos[c + d*x]^9)/(9*d) + (10*a^2*b^3*Cos[c + d*x]^9)/(9*d) - (b^5*Cos[c + d*x]^9)/(9*d) + (a^5*Sin[c + d*x])/d - (4*a^5*Sin[c + d*x]^3)/(3*d) + (10*a^3*b^2*Sin[c + d*x]^3)/(3*d) + (6*a^5*Sin[c + d*x]^5)/(5*d) - (6*a^3*b^2*Sin[c + d*x]^5)/d + (a*b^4*Sin[c + d*x]^5)/d - (4*a^5*Sin[c + d*x]^7)/(7*d) + (30*a^3*b^2*Sin[c + d*x]^7)/(7*d) - (10*a*b^4*Sin[c + d*x]^7)/(7*d) + (a^5*Sin[c + d*x]^9)/(9*d) - (10*a^3*b^2*Sin[c + d*x]^9)/(9*d) + (5*a*b^4*Sin[c + d*x]^9)/(9*d)}
{Cos[c + d*x]^3*(a*Cos[c + d*x] + b*Sin[c + d*x])^5, x, 21, (35*a^5*x)/128 + (25/64)*a^3*b^2*x + (15/128)*a*b^4*x - (5*a^2*b^3*Cos[c + d*x]^6)/(3*d) - (5*a^4*b*Cos[c + d*x]^8)/(8*d) + (5*a^2*b^3*Cos[c + d*x]^8)/(4*d) + (35*a^5*Cos[c + d*x]*Sin[c + d*x])/(128*d) + (25*a^3*b^2*Cos[c + d*x]*Sin[c + d*x])/(64*d) + (15*a*b^4*Cos[c + d*x]*Sin[c + d*x])/(128*d) + (35*a^5*Cos[c + d*x]^3*Sin[c + d*x])/(192*d) + (25*a^3*b^2*Cos[c + d*x]^3*Sin[c + d*x])/(96*d) + (5*a*b^4*Cos[c + d*x]^3*Sin[c + d*x])/(64*d) + (7*a^5*Cos[c + d*x]^5*Sin[c + d*x])/(48*d) + (5*a^3*b^2*Cos[c + d*x]^5*Sin[c + d*x])/(24*d) - (5*a*b^4*Cos[c + d*x]^5*Sin[c + d*x])/(16*d) + (a^5*Cos[c + d*x]^7*Sin[c + d*x])/(8*d) - (5*a^3*b^2*Cos[c + d*x]^7*Sin[c + d*x])/(4*d) - (5*a*b^4*Cos[c + d*x]^5*Sin[c + d*x]^3)/(8*d) + (b^5*Sin[c + d*x]^6)/(6*d) - (b^5*Sin[c + d*x]^8)/(8*d)}
{Cos[c + d*x]^2*(a*Cos[c + d*x] + b*Sin[c + d*x])^5, x, 17, -((b^5*Cos[c + d*x]^3)/(3*d)) - (2*a^2*b^3*Cos[c + d*x]^5)/d + (2*b^5*Cos[c + d*x]^5)/(5*d) - (5*a^4*b*Cos[c + d*x]^7)/(7*d) + (10*a^2*b^3*Cos[c + d*x]^7)/(7*d) - (b^5*Cos[c + d*x]^7)/(7*d) + (a^5*Sin[c + d*x])/d - (a^5*Sin[c + d*x]^3)/d + (10*a^3*b^2*Sin[c + d*x]^3)/(3*d) + (3*a^5*Sin[c + d*x]^5)/(5*d) - (4*a^3*b^2*Sin[c + d*x]^5)/d + (a*b^4*Sin[c + d*x]^5)/d - (a^5*Sin[c + d*x]^7)/(7*d) + (10*a^3*b^2*Sin[c + d*x]^7)/(7*d) - (5*a*b^4*Sin[c + d*x]^7)/(7*d)}
{Cos[c + d*x]^1*(a*Cos[c + d*x] + b*Sin[c + d*x])^5, x, 6, (5/16)*a*(a^2 + b^2)^2*x + (b + a*Cot[c + d*x])^5/(6*d*(1 + Cot[c + d*x]^2)^3) + (5*a*(b + a*Cot[c + d*x])^3*(a - b*Cot[c + d*x]))/(24*d*(1 + Cot[c + d*x]^2)^2) + (5*a*(a^2 + b^2)*(b + a*Cot[c + d*x])*(a - b*Cot[c + d*x]))/(16*d*(1 + Cot[c + d*x]^2))}
{Cos[c + d*x]^0*(a*Cos[c + d*x] + b*Sin[c + d*x])^5, x, 3, -(((a^2 + b^2)^2*(b*Cos[c + d*x] - a*Sin[c + d*x]))/d) + (2*(a^2 + b^2)*(b*Cos[c + d*x] - a*Sin[c + d*x])^3)/(3*d) - (b*Cos[c + d*x] - a*Sin[c + d*x])^5/(5*d)}
{Sec[c + d*x]^1*(a*Cos[c + d*x] + b*Sin[c + d*x])^5, x, 11, a^5*x - a^3*(a^2 - 5*b^2)*x + (3/8)*a*(a^4 - 10*a^2*b^2 + 5*b^4)*x - (b*(5*a^4 - 10*a^2*b^2 + b^4) + a*(a^4 - 10*a^2*b^2 + 5*b^4)*Cot[c + d*x])/(4*d*(1 + Cot[c + d*x]^2)^2) - (3*a*(a^4 - 10*a^2*b^2 + 5*b^4)*Cot[c + d*x])/(8*d*(1 + Cot[c + d*x]^2)) + (b*(5*a^4 - b^4) + 2*a^3*(a^2 - 5*b^2)*Cot[c + d*x])/(2*d*(1 + Cot[c + d*x]^2)) - (b^5*Log[Cot[c + d*x]])/d + (b^5*Log[1 + Cot[c + d*x]^2])/(2*d)}
{Sec[c + d*x]^2*(a*Cos[c + d*x] + b*Sin[c + d*x])^5, x, 14, (5*a*b^4*ArcTanh[Sin[c + d*x]])/d - (10*a^2*b^3*Cos[c + d*x])/d + (2*b^5*Cos[c + d*x])/d - (5*a^4*b*Cos[c + d*x]^3)/(3*d) + (10*a^2*b^3*Cos[c + d*x]^3)/(3*d) - (b^5*Cos[c + d*x]^3)/(3*d) + (b^5*Sec[c + d*x])/d + (a^5*Sin[c + d*x])/d - (5*a*b^4*Sin[c + d*x])/d - (a^5*Sin[c + d*x]^3)/(3*d) + (10*a^3*b^2*Sin[c + d*x]^3)/(3*d) - (5*a*b^4*Sin[c + d*x]^3)/(3*d)}
{Sec[c + d*x]^3*(a*Cos[c + d*x] + b*Sin[c + d*x])^5, x, 8, a*(a^4 - 5*b^4)*x - (1/2)*a*(a^4 - 10*a^2*b^2 + 5*b^4)*x + (b*(5*a^4 - 10*a^2*b^2 + b^4) + a*(a^4 - 10*a^2*b^2 + 5*b^4)*Cot[c + d*x])/(2*d*(1 + Cot[c + d*x]^2)) - (2*b^3*(5*a^2 - b^2)*Log[Cot[c + d*x]])/d + (b^3*(5*a^2 - b^2)*Log[1 + Cot[c + d*x]^2])/d + (5*a*b^4*Tan[c + d*x])/d + (b^5*Tan[c + d*x]^2)/(2*d)}
{Sec[c + d*x]^4*(a*Cos[c + d*x] + b*Sin[c + d*x])^5, x, 15, (10*a^3*b^2*ArcTanh[Sin[c + d*x]])/d - (15*a*b^4*ArcTanh[Sin[c + d*x]])/(2*d) - (5*a^4*b*Cos[c + d*x])/d + (10*a^2*b^3*Cos[c + d*x])/d - (b^5*Cos[c + d*x])/d + (10*a^2*b^3*Sec[c + d*x])/d - (2*b^5*Sec[c + d*x])/d + (b^5*Sec[c + d*x]^3)/(3*d) + (a^5*Sin[c + d*x])/d - (10*a^3*b^2*Sin[c + d*x])/d + (15*a*b^4*Sin[c + d*x])/(2*d) + (5*a*b^4*Sin[c + d*x]*Tan[c + d*x]^2)/(2*d)}
{Sec[c + d*x]^5*(a*Cos[c + d*x] + b*Sin[c + d*x])^5, x, 7, a*(a^4 - 10*a^2*b^2 + 5*b^4)*x - (b*(5*a^4 - 10*a^2*b^2 + b^4)*Log[Cos[c + d*x]])/d + (4*a*b*(a^2 - b^2)*(a + b*Tan[c + d*x]))/d + (b*(3*a^2 - b^2)*(a + b*Tan[c + d*x])^2)/(2*d) + (2*a*b*(a + b*Tan[c + d*x])^3)/(3*d) + (b*(a + b*Tan[c + d*x])^4)/(4*d)}
{Sec[c + d*x]^6*(a*Cos[c + d*x] + b*Sin[c + d*x])^5, x, 14, (a^5*ArcTanh[Sin[c + d*x]])/d - (5*a^3*b^2*ArcTanh[Sin[c + d*x]])/d + (15*a*b^4*ArcTanh[Sin[c + d*x]])/(8*d) + (5*a^4*b*Sec[c + d*x])/d - (10*a^2*b^3*Sec[c + d*x])/d + (b^5*Sec[c + d*x])/d + (10*a^2*b^3*Sec[c + d*x]^3)/(3*d) - (2*b^5*Sec[c + d*x]^3)/(3*d) + (b^5*Sec[c + d*x]^5)/(5*d) + (5*a^3*b^2*Sec[c + d*x]*Tan[c + d*x])/d - (15*a*b^4*Sec[c + d*x]*Tan[c + d*x])/(8*d) + (5*a*b^4*Sec[c + d*x]*Tan[c + d*x]^3)/(4*d)}
{Sec[c + d*x]^7*(a*Cos[c + d*x] + b*Sin[c + d*x])^5, x, 2, ((b + a*Cot[c + d*x])^6*Tan[c + d*x]^6)/(6*b*d)}
{Sec[c + d*x]^8*(a*Cos[c + d*x] + b*Sin[c + d*x])^5, x, 18, (a^5*ArcTanh[Sin[c + d*x]])/(2*d) - (5*a^3*b^2*ArcTanh[Sin[c + d*x]])/(4*d) + (5*a*b^4*ArcTanh[Sin[c + d*x]])/(16*d) + (5*a^4*b*Sec[c + d*x]^3)/(3*d) - (10*a^2*b^3*Sec[c + d*x]^3)/(3*d) + (b^5*Sec[c + d*x]^3)/(3*d) + (2*a^2*b^3*Sec[c + d*x]^5)/d - (2*b^5*Sec[c + d*x]^5)/(5*d) + (b^5*Sec[c + d*x]^7)/(7*d) + (a^5*Sec[c + d*x]*Tan[c + d*x])/(2*d) + (5*a^3*b^2*Sec[c + d*x]*Tan[c + d*x])/(4*d) - (5*a*b^4*Sec[c + d*x]*Tan[c + d*x])/(16*d) + (5*a^3*b^2*Sec[c + d*x]*Tan[c + d*x]^3)/(2*d) + (5*a*b^4*Sec[c + d*x]*Tan[c + d*x]^3)/(24*d) + (5*a*b^4*Sec[c + d*x]*Tan[c + d*x]^5)/(6*d)}
{Sec[c + d*x]^9*(a*Cos[c + d*x] + b*Sin[c + d*x])^5, x, 3, (a^5*Tan[c + d*x])/d + (5*a^4*b*Tan[c + d*x]^2)/(2*d) + (a^3*(a^2 + 10*b^2)*Tan[c + d*x]^3)/(3*d) + (5*a^2*b*(a^2 + 2*b^2)*Tan[c + d*x]^4)/(4*d) + (a*b^2*(2*a^2 + b^2)*Tan[c + d*x]^5)/d + (b^3*(10*a^2 + b^2)*Tan[c + d*x]^6)/(6*d) + (5*a*b^4*Tan[c + d*x]^7)/(7*d) + (b^5*Tan[c + d*x]^8)/(8*d)}
{Sec[c + d*x]^10*(a*Cos[c + d*x] + b*Sin[c + d*x])^5, x, 21, (3*a^5*ArcTanh[Sin[c + d*x]])/(8*d) - (5*a^3*b^2*ArcTanh[Sin[c + d*x]])/(8*d) + (15*a*b^4*ArcTanh[Sin[c + d*x]])/(128*d) + (a^4*b*Sec[c + d*x]^5)/d - (2*a^2*b^3*Sec[c + d*x]^5)/d + (b^5*Sec[c + d*x]^5)/(5*d) + (10*a^2*b^3*Sec[c + d*x]^7)/(7*d) - (2*b^5*Sec[c + d*x]^7)/(7*d) + (b^5*Sec[c + d*x]^9)/(9*d) + (3*a^5*Sec[c + d*x]*Tan[c + d*x])/(8*d) + (5*a^3*b^2*Sec[c + d*x]*Tan[c + d*x])/(8*d) - (15*a*b^4*Sec[c + d*x]*Tan[c + d*x])/(128*d) + (a^5*Sec[c + d*x]^3*Tan[c + d*x])/(4*d) + (5*a^3*b^2*Sec[c + d*x]*Tan[c + d*x]^3)/(4*d) + (5*a*b^4*Sec[c + d*x]*Tan[c + d*x]^3)/(64*d) + (5*a^3*b^2*Sec[c + d*x]^3*Tan[c + d*x]^3)/(3*d) + (5*a*b^4*Sec[c + d*x]*Tan[c + d*x]^5)/(16*d) + (5*a*b^4*Sec[c + d*x]^3*Tan[c + d*x]^5)/(8*d)}
{Sec[c + d*x]^11*(a*Cos[c + d*x] + b*Sin[c + d*x])^5, x, 3, (a^5*Tan[c + d*x])/d + (5*a^4*b*Tan[c + d*x]^2)/(2*d) + (2*a^3*(a^2 + 5*b^2)*Tan[c + d*x]^3)/(3*d) + (5*a^2*b*(a^2 + b^2)*Tan[c + d*x]^4)/(2*d) + (a*(a^4 + 20*a^2*b^2 + 5*b^4)*Tan[c + d*x]^5)/(5*d) + (b*(5*a^4 + 20*a^2*b^2 + b^4)*Tan[c + d*x]^6)/(6*d) + (10*a*b^2*(a^2 + b^2)*Tan[c + d*x]^7)/(7*d) + (b^3*(5*a^2 + b^2)*Tan[c + d*x]^8)/(4*d) + (5*a*b^4*Tan[c + d*x]^9)/(9*d) + (b^5*Tan[c + d*x]^10)/(10*d)}
{Sec[c + d*x]^12*(a*Cos[c + d*x] + b*Sin[c + d*x])^5, x, 24, (5*a^5*ArcTanh[Sin[c + d*x]])/(16*d) - (25*a^3*b^2*ArcTanh[Sin[c + d*x]])/(64*d) + (15*a*b^4*ArcTanh[Sin[c + d*x]])/(256*d) + (5*a^4*b*Sec[c + d*x]^7)/(7*d) - (10*a^2*b^3*Sec[c + d*x]^7)/(7*d) + (b^5*Sec[c + d*x]^7)/(7*d) + (10*a^2*b^3*Sec[c + d*x]^9)/(9*d) - (2*b^5*Sec[c + d*x]^9)/(9*d) + (b^5*Sec[c + d*x]^11)/(11*d) + (5*a^5*Sec[c + d*x]*Tan[c + d*x])/(16*d) + (25*a^3*b^2*Sec[c + d*x]*Tan[c + d*x])/(64*d) - (15*a*b^4*Sec[c + d*x]*Tan[c + d*x])/(256*d) + (5*a^5*Sec[c + d*x]^3*Tan[c + d*x])/(24*d) + (a^5*Sec[c + d*x]^5*Tan[c + d*x])/(6*d) + (25*a^3*b^2*Sec[c + d*x]*Tan[c + d*x]^3)/(32*d) + (5*a*b^4*Sec[c + d*x]*Tan[c + d*x]^3)/(128*d) + (25*a^3*b^2*Sec[c + d*x]^3*Tan[c + d*x]^3)/(24*d) + (5*a^3*b^2*Sec[c + d*x]^5*Tan[c + d*x]^3)/(4*d) + (5*a*b^4*Sec[c + d*x]*Tan[c + d*x]^5)/(32*d) + (5*a*b^4*Sec[c + d*x]^3*Tan[c + d*x]^5)/(16*d) + (a*b^4*Sec[c + d*x]^5*Tan[c + d*x]^5)/(2*d)}


(* ::Subsubsection::Closed:: *)
(*n<0*)


{Cos[c + d*x]^5/(a*Cos[c + d*x] + b*Sin[c + d*x]), x, 7, (a*b^4*x)/(a^2 + b^2)^3 + (a*b^2*x)/(2*(a^2 + b^2)^2) + (3*a*x)/(8*(a^2 + b^2)) + (b^3*Cos[c + d*x]^2)/(2*(a^2 + b^2)^2*d) + (b*Cos[c + d*x]^4)/(4*(a^2 + b^2)*d) + (b^5*Log[a*Cos[c + d*x] + b*Sin[c + d*x]])/((a^2 + b^2)^3*d) + (a*b^2*Cos[c + d*x]*Sin[c + d*x])/(2*(a^2 + b^2)^2*d) + (3*a*Cos[c + d*x]*Sin[c + d*x])/(8*(a^2 + b^2)*d) + (a*Cos[c + d*x]^3*Sin[c + d*x])/(4*(a^2 + b^2)*d)}
{Cos[c + d*x]^4/(a*Cos[c + d*x] + b*Sin[c + d*x]), x, 7, -((b^4*ArcTanh[(b*Cos[c + d*x] - a*Sin[c + d*x])/Sqrt[a^2 + b^2]])/((a^2 + b^2)^(5/2)*d)) + (b^3*Cos[c + d*x])/((a^2 + b^2)^2*d) + (b*Cos[c + d*x]^3)/(3*(a^2 + b^2)*d) + (a*b^2*Sin[c + d*x])/((a^2 + b^2)^2*d) + (a*Sin[c + d*x])/((a^2 + b^2)*d) - (a*Sin[c + d*x]^3)/(3*(a^2 + b^2)*d)}
{Cos[c + d*x]^3/(a*Cos[c + d*x] + b*Sin[c + d*x]), x, 4, (a*b^2*x)/(a^2 + b^2)^2 + (a*x)/(2*(a^2 + b^2)) + (b*Cos[c + d*x]^2)/(2*(a^2 + b^2)*d) + (b^3*Log[a*Cos[c + d*x] + b*Sin[c + d*x]])/((a^2 + b^2)^2*d) + (a*Cos[c + d*x]*Sin[c + d*x])/(2*(a^2 + b^2)*d)}
{Cos[c + d*x]^2/(a*Cos[c + d*x] + b*Sin[c + d*x]), x, 4, -((b^2*ArcTanh[(b*Cos[c + d*x] - a*Sin[c + d*x])/Sqrt[a^2 + b^2]])/((a^2 + b^2)^(3/2)*d)) + (b*Cos[c + d*x])/((a^2 + b^2)*d) + (a*Sin[c + d*x])/((a^2 + b^2)*d)}
{Cos[c + d*x]^1/(a*Cos[c + d*x] + b*Sin[c + d*x]), x, 2, (a*x)/(a^2 + b^2) + (b*Log[a*Cos[c + d*x] + b*Sin[c + d*x]])/((a^2 + b^2)*d)}
{Cos[c + d*x]^0/(a*Cos[c + d*x] + b*Sin[c + d*x]), x, 2, -(ArcTanh[(b*Cos[c + d*x] - a*Sin[c + d*x])/Sqrt[a^2 + b^2]]/(Sqrt[a^2 + b^2]*d))}
{Sec[c + d*x]^1/(a*Cos[c + d*x] + b*Sin[c + d*x]), x, 3, -(Log[Cos[c + d*x]]/(b*d)) + Log[a*Cos[c + d*x] + b*Sin[c + d*x]]/(b*d)}
{Sec[c + d*x]^2/(a*Cos[c + d*x] + b*Sin[c + d*x]), x, 4, -((a*ArcTanh[Sin[c + d*x]])/(b^2*d)) - (Sqrt[a^2 + b^2]*ArcTanh[(b*Cos[c + d*x] - a*Sin[c + d*x])/Sqrt[a^2 + b^2]])/(b^2*d) + Sec[c + d*x]/(b*d)}
{Sec[c + d*x]^3/(a*Cos[c + d*x] + b*Sin[c + d*x]), x, 5, -(((a^2 + b^2)*Log[Cos[c + d*x]])/(b^3*d)) + ((a^2 + b^2)*Log[a*Cos[c + d*x] + b*Sin[c + d*x]])/(b^3*d) + Sec[c + d*x]^2/(2*b*d) - (a*Tan[c + d*x])/(b^2*d)}
{Sec[c + d*x]^4/(a*Cos[c + d*x] + b*Sin[c + d*x]), x, 7, -((a*ArcTanh[Sin[c + d*x]])/(2*b^2*d)) - (a*(a^2 + b^2)*ArcTanh[Sin[c + d*x]])/(b^4*d) - ((a^2 + b^2)^(3/2)*ArcTanh[(b*Cos[c + d*x] - a*Sin[c + d*x])/Sqrt[a^2 + b^2]])/(b^4*d) + ((a^2 + b^2)*Sec[c + d*x])/(b^3*d) + Sec[c + d*x]^3/(3*b*d) - (a*Sec[c + d*x]*Tan[c + d*x])/(2*b^2*d)}
{Sec[c + d*x]^5/(a*Cos[c + d*x] + b*Sin[c + d*x]), x, 8, -(((a^2 + b^2)^2*Log[Cos[c + d*x]])/(b^5*d)) + ((a^2 + b^2)^2*Log[a*Cos[c + d*x] + b*Sin[c + d*x]])/(b^5*d) + ((a^2 + b^2)*Sec[c + d*x]^2)/(2*b^3*d) + Sec[c + d*x]^4/(4*b*d) - (a*Tan[c + d*x])/(b^2*d) - (a*(a^2 + b^2)*Tan[c + d*x])/(b^4*d) - (a*Tan[c + d*x]^3)/(3*b^2*d)}
{Sec[c + d*x]^6/(a*Cos[c + d*x] + b*Sin[c + d*x]), x, 11, -((3*a*ArcTanh[Sin[c + d*x]])/(8*b^2*d)) - (a*(a^2 + b^2)*ArcTanh[Sin[c + d*x]])/(2*b^4*d) - (a*(a^2 + b^2)^2*ArcTanh[Sin[c + d*x]])/(b^6*d) - ((a^2 + b^2)^(5/2)*ArcTanh[(b*Cos[c + d*x] - a*Sin[c + d*x])/Sqrt[a^2 + b^2]])/(b^6*d) + ((a^2 + b^2)^2*Sec[c + d*x])/(b^5*d) + ((a^2 + b^2)*Sec[c + d*x]^3)/(3*b^3*d) + Sec[c + d*x]^5/(5*b*d) - (3*a*Sec[c + d*x]*Tan[c + d*x])/(8*b^2*d) - (a*(a^2 + b^2)*Sec[c + d*x]*Tan[c + d*x])/(2*b^4*d) - (a*Sec[c + d*x]^3*Tan[c + d*x])/(4*b^2*d)}


{Cos[c + d*x]^4/(a*Cos[c + d*x] + b*Sin[c + d*x])^2, x, 8, -(((a^2 - b^2)*x)/(2*(a^2 + b^2)^2)) + ((a^4 + 3*a^2*b^2 - 2*b^4)*x)/(a^2 + b^2)^3 + b^4/(a*(a^2 + b^2)^2*d*(b + a*Cot[c + d*x])) - (2*a*b - (a^2 - b^2)*Cot[c + d*x])/(2*(a^2 + b^2)^2*d*(1 + Cot[c + d*x]^2)) + (4*a*b^3*Log[b + a*Cot[c + d*x]])/((a^2 + b^2)^3*d) - (2*a*b^3*Log[1 + Cot[c + d*x]^2])/((a^2 + b^2)^3*d)}
{Cos[c + d*x]^3/(a*Cos[c + d*x] + b*Sin[c + d*x])^2, x, 0, -((3*a*b^2*ArcTanh[(b*Cos[c + d*x] - a*Sin[c + d*x])/Sqrt[a^2 + b^2]])/((a^2 + b^2)^(5/2)*d)) + (2*a*b*Cos[c + d*x])/((a^2 + b^2)^2*d) + ((a^2 - b^2)*Sin[c + d*x])/((a^2 + b^2)^2*d) - b^3/((a^2 + b^2)^2*d*(a*Cos[c + d*x] + b*Sin[c + d*x]))}
{Cos[c + d*x]^2/(a*Cos[c + d*x] + b*Sin[c + d*x])^2, x, 6, ((a^2 - b^2)*x)/(a^2 + b^2)^2 + b^2/(a*(a^2 + b^2)*d*(b + a*Cot[c + d*x])) + (2*a*b*Log[a*Cos[c + d*x] + b*Sin[c + d*x]])/((a^2 + b^2)^2*d), ((a^2 - b^2)*x)/(a^2 + b^2)^2 + (2*a*b*Log[Cos[c + d*x]])/((a^2 + b^2)^2*d) + (2*a*b*Log[a + b*Tan[c + d*x]])/((a^2 + b^2)^2*d) - b/((a^2 + b^2)*d*(a + b*Tan[c + d*x]))}
{Cos[c + d*x]^1/(a*Cos[c + d*x] + b*Sin[c + d*x])^2, x, 3, -((a*ArcTanh[(b*Cos[c + d*x] - a*Sin[c + d*x])/Sqrt[a^2 + b^2]])/((a^2 + b^2)^(3/2)*d)) - b/((a^2 + b^2)*d*(a*Cos[c + d*x] + b*Sin[c + d*x]))}
{Cos[c + d*x]^0/(a*Cos[c + d*x] + b*Sin[c + d*x])^2, x, 1, Sin[c + d*x]/(a*d*(a*Cos[c + d*x] + b*Sin[c + d*x]))}
{Sec[c + d*x]^1/(a*Cos[c + d*x] + b*Sin[c + d*x])^2, x, 4, ArcTanh[Sin[c + d*x]]/(b^2*d) + (a*ArcTanh[(b*Cos[c + d*x] - a*Sin[c + d*x])/Sqrt[a^2 + b^2]])/(b^2*Sqrt[a^2 + b^2]*d) - 1/(b*d*(a*Cos[c + d*x] + b*Sin[c + d*x]))}
{Sec[c + d*x]^2/(a*Cos[c + d*x] + b*Sin[c + d*x])^2, x, 3, (1/a + a/b^2)/(d*(b + a*Cot[c + d*x])) + (2*a*Log[Cot[c + d*x]])/(b^3*d) - (2*a*Log[b + a*Cot[c + d*x]])/(b^3*d) + Tan[c + d*x]/(b^2*d)}
{Sec[c + d*x]^3/(a*Cos[c + d*x] + b*Sin[c + d*x])^2, x, 11, (2*a^2*ArcTanh[Sin[c + d*x]])/(b^4*d) + ArcTanh[Sin[c + d*x]]/(2*b^2*d) + ((a^2 + b^2)*ArcTanh[Sin[c + d*x]])/(b^4*d) + (3*a*Sqrt[a^2 + b^2]*ArcTanh[(b*Cos[c + d*x] - a*Sin[c + d*x])/Sqrt[a^2 + b^2]])/(b^4*d) - (2*a*Sec[c + d*x])/(b^3*d) - (a^2 + b^2)/(b^3*d*(a*Cos[c + d*x] + b*Sin[c + d*x])) + (Sec[c + d*x]*Tan[c + d*x])/(2*b^2*d)}
{Sec[c + d*x]^4/(a*Cos[c + d*x] + b*Sin[c + d*x])^2, x, 3, (a^2 + b^2)^2/(a*b^4*d*(b + a*Cot[c + d*x])) + (4*a*(a^2 + b^2)*Log[Cot[c + d*x]])/(b^5*d) - (4*a*(a^2 + b^2)*Log[b + a*Cot[c + d*x]])/(b^5*d) + ((3*a^2 + 2*b^2)*Tan[c + d*x])/(b^4*d) - (a*Tan[c + d*x]^2)/(b^3*d) + Tan[c + d*x]^3/(3*b^2*d)}


{Cos[c + d*x]^4/(a*Cos[c + d*x] + b*Sin[c + d*x])^3, x, 0, (-((6*b^2*(-4*a^2 + b^2)*ArcTanh[(-b + a*Tan[(1/2)*(c + d*x)])/Sqrt[a^2 + b^2]])/(a^2 + b^2)^(7/2)) - (2*b*(-3*a^2 + b^2)*Cos[c + d*x])/(a^2 + b^2)^3 + (2*a*(a^2 - 3*b^2)*Sin[c + d*x])/(a^2 + b^2)^3 + (b^4*Sin[c + d*x])/(a*(a - I*b)^2*(a + I*b)^2*(a*Cos[c + d*x] + b*Sin[c + d*x])^2) - (b^3*(8*a^2 + b^2))/(a*(a^2 + b^2)^3*(a*Cos[c + d*x] + b*Sin[c + d*x])))/(2*d)}
{Cos[c + d*x]^3/(a*Cos[c + d*x] + b*Sin[c + d*x])^3, x, 7, (a*(a^2 - 3*b^2)*x)/(a^2 + b^2)^3 + (b*(3*a^2 - b^2)*Log[Cos[c + d*x]])/((a^2 + b^2)^3*d) + (b*(3*a^2 - b^2)*Log[a + b*Tan[c + d*x]])/((a^2 + b^2)^3*d) - b/(2*(a^2 + b^2)*d*(a + b*Tan[c + d*x])^2) - (2*a*b)/((a^2 + b^2)^2*d*(a + b*Tan[c + d*x]))}
{Cos[c + d*x]^2/(a*Cos[c + d*x] + b*Sin[c + d*x])^3, x, 0, ((2*(2*a^2 - b^2)*ArcTanh[(-b + a*Tan[(1/2)*(c + d*x)])/Sqrt[a^2 + b^2]])/(a^2 + b^2)^(5/2) - (b*((4*a^2 + b^2)*Cos[c + d*x] + 3*a*b*Sin[c + d*x]))/((a^2 + b^2)^2*(a*Cos[c + d*x] + b*Sin[c + d*x])^2))/(2*d)}
{Cos[c + d*x]^1/(a*Cos[c + d*x] + b*Sin[c + d*x])^3, x, 2, -(1/(2*b*d*(a + b*Tan[c + d*x])^2)), -(Cot[c + d*x]^2/(2*b*d*(b + a*Cot[c + d*x])^2))}
{Cos[c + d*x]^0/(a*Cos[c + d*x] + b*Sin[c + d*x])^3, x, 3, -(ArcTanh[(b*Cos[c + d*x] - a*Sin[c + d*x])/Sqrt[a^2 + b^2]]/(2*(a^2 + b^2)^(3/2)*d)) - (b*Cos[c + d*x] - a*Sin[c + d*x])/(2*(a^2 + b^2)*d*(a*Cos[c + d*x] + b*Sin[c + d*x])^2)}
{Sec[c + d*x]^1/(a*Cos[c + d*x] + b*Sin[c + d*x])^3, x, 3, -((1/b + b/a^2)/(2*d*(b + a*Cot[c + d*x])^2)) + (1/a^2 - 1/b^2)/(d*(b + a*Cot[c + d*x])) - Log[Cot[c + d*x]]/(b^3*d) + Log[b + a*Cot[c + d*x]]/(b^3*d)}
{Sec[c + d*x]^2/(a*Cos[c + d*x] + b*Sin[c + d*x])^3, x, 12, -((3*a*ArcTanh[Sin[c + d*x]])/(b^4*d)) - (2*a^2*ArcTanh[(b*Cos[c + d*x] - a*Sin[c + d*x])/Sqrt[a^2 + b^2]])/(b^4*Sqrt[a^2 + b^2]*d) - ArcTanh[(b*Cos[c + d*x] - a*Sin[c + d*x])/Sqrt[a^2 + b^2]]/(2*b^2*Sqrt[a^2 + b^2]*d) - (Sqrt[a^2 + b^2]*ArcTanh[(b*Cos[c + d*x] - a*Sin[c + d*x])/Sqrt[a^2 + b^2]])/(b^4*d) + Sec[c + d*x]/(b^3*d) - (b*Cos[c + d*x] - a*Sin[c + d*x])/(2*b^2*d*(a*Cos[c + d*x] + b*Sin[c + d*x])^2) + (2*a)/(b^3*d*(a*Cos[c + d*x] + b*Sin[c + d*x]))}
{Sec[c + d*x]^3/(a*Cos[c + d*x] + b*Sin[c + d*x])^3, x, 3, -((a^2 + b^2)^2/(2*a^2*b^3*d*(b + a*Cot[c + d*x])^2)) - ((3*a^2 - b^2)*(a^2 + b^2))/(a^2*b^4*d*(b + a*Cot[c + d*x])) - (2*(3*a^2 + b^2)*Log[Cot[c + d*x]])/(b^5*d) + (2*(3*a^2 + b^2)*Log[b + a*Cot[c + d*x]])/(b^5*d) - (3*a*Tan[c + d*x])/(b^4*d) + Tan[c + d*x]^2/(2*b^3*d)}
{Sec[c + d*x]^4/(a*Cos[c + d*x] + b*Sin[c + d*x])^3, x, 31, -((4*a^3*ArcTanh[Sin[c + d*x]])/(b^6*d)) - (3*a*ArcTanh[Sin[c + d*x]])/(2*b^4*d) - (6*a*(a^2 + b^2)*ArcTanh[Sin[c + d*x]])/(b^6*d) - (8*a^2*Sqrt[a^2 + b^2]*ArcTanh[(b*Cos[c + d*x] - a*Sin[c + d*x])/Sqrt[a^2 + b^2]])/(b^6*d) - (Sqrt[a^2 + b^2]*ArcTanh[(b*Cos[c + d*x] - a*Sin[c + d*x])/Sqrt[a^2 + b^2]])/(2*b^4*d) - (2*(a^2 + b^2)^(3/2)*ArcTanh[(b*Cos[c + d*x] - a*Sin[c + d*x])/Sqrt[a^2 + b^2]])/(b^6*d) + (4*a^2*Sec[c + d*x])/(b^5*d) + (2*(a^2 + b^2)*Sec[c + d*x])/(b^5*d) + Sec[c + d*x]^3/(3*b^3*d) - ((a^2 + b^2)*(b*Cos[c + d*x] - a*Sin[c + d*x]))/(2*b^4*d*(a*Cos[c + d*x] + b*Sin[c + d*x])^2) + (4*a*(a^2 + b^2))/(b^5*d*(a*Cos[c + d*x] + b*Sin[c + d*x])) - (3*a*Sec[c + d*x]*Tan[c + d*x])/(2*b^4*d)}
{Sec[c + d*x]^5/(a*Cos[c + d*x] + b*Sin[c + d*x])^3, x, 3, -((a^2 + b^2)^3/(2*a^2*b^5*d*(b + a*Cot[c + d*x])^2)) - ((5*a^2 - b^2)*(a^2 + b^2)^2)/(a^2*b^6*d*(b + a*Cot[c + d*x])) - (3*(a^2 + b^2)*(5*a^2 + b^2)*Log[Cot[c + d*x]])/(b^7*d) + (3*(a^2 + b^2)*(5*a^2 + b^2)*Log[b + a*Cot[c + d*x]])/(b^7*d) - (a*(10*a^2 + 9*b^2)*Tan[c + d*x])/(b^6*d) + (3*(2*a^2 + b^2)*Tan[c + d*x]^2)/(2*b^5*d) - (a*Tan[c + d*x]^3)/(b^4*d) + Tan[c + d*x]^4/(4*b^3*d)}


{Cos[c + d*x]^4/(a*Cos[c + d*x] + b*Sin[c + d*x])^4, x, 8, ((a^4 - 6*a^2*b^2 + b^4)*x)/(a^2 + b^2)^4 + (4*a*b*(a^2 - b^2)*Log[Cos[c + d*x]])/((a^2 + b^2)^4*d) + (4*a*b*(a^2 - b^2)*Log[a + b*Tan[c + d*x]])/((a^2 + b^2)^4*d) - b/(3*(a^2 + b^2)*d*(a + b*Tan[c + d*x])^3) - (a*b)/((a^2 + b^2)^2*d*(a + b*Tan[c + d*x])^2) - (b*(3*a^2 - b^2))/((a^2 + b^2)^3*d*(a + b*Tan[c + d*x]))}
{Cos[c + d*x]^3/(a*Cos[c + d*x] + b*Sin[c + d*x])^4, x, 0, ((6*a*(2*a^2 - 3*b^2)*ArcTanh[(-b + a*Tan[(1/2)*(c + d*x)])/Sqrt[a^2 + b^2]])/(a^2 + b^2)^(7/2) + (-3*(3*a^4*b - a^2*b^3 + b^5)*Cos[2*(c + d*x)] + (1/2)*b*(-9*a^2 + b^2)*(2*(a^2 + b^2) + 3*a*b*Sin[2*(c + d*x)]))/((a - I*b)^3*(a + I*b)^3*(a*Cos[c + d*x] + b*Sin[c + d*x])^3))/(6*d)}
{Cos[c + d*x]^2/(a*Cos[c + d*x] + b*Sin[c + d*x])^4, x, 2, -(Cot[c + d*x]^3/(3*b*d*(b + a*Cot[c + d*x])^3))}
{Cos[c + d*x]^1/(a*Cos[c + d*x] + b*Sin[c + d*x])^4, x, 5, -((a*ArcTanh[(b*Cos[c + d*x] - a*Sin[c + d*x])/Sqrt[a^2 + b^2]])/(2*(a^2 + b^2)^(5/2)*d)) - b/(3*(a^2 + b^2)*d*(a*Cos[c + d*x] + b*Sin[c + d*x])^3) - (a*(b*Cos[c + d*x] - a*Sin[c + d*x]))/(2*(a^2 + b^2)^2*d*(a*Cos[c + d*x] + b*Sin[c + d*x])^2)}
{Cos[c + d*x]^0/(a*Cos[c + d*x] + b*Sin[c + d*x])^4, x, 2, -((b*Cos[c + d*x] - a*Sin[c + d*x])/(3*(a^2 + b^2)*d*(a*Cos[c + d*x] + b*Sin[c + d*x])^3)) + (2*Sin[c + d*x])/(3*a*(a^2 + b^2)*d*(a*Cos[c + d*x] + b*Sin[c + d*x]))}
{Sec[c + d*x]^1/(a*Cos[c + d*x] + b*Sin[c + d*x])^4, x, 8, ArcTanh[Sin[c + d*x]]/(b^4*d) + (a*ArcTanh[(b*Cos[c + d*x] - a*Sin[c + d*x])/Sqrt[a^2 + b^2]])/(2*b^2*(a^2 + b^2)^(3/2)*d) + (a*ArcTanh[(b*Cos[c + d*x] - a*Sin[c + d*x])/Sqrt[a^2 + b^2]])/(b^4*Sqrt[a^2 + b^2]*d) - 1/(3*b*d*(a*Cos[c + d*x] + b*Sin[c + d*x])^3) + (a*(b*Cos[c + d*x] - a*Sin[c + d*x]))/(2*b^2*(a^2 + b^2)*d*(a*Cos[c + d*x] + b*Sin[c + d*x])^2) - 1/(b^3*d*(a*Cos[c + d*x] + b*Sin[c + d*x]))}
{Sec[c + d*x]^2/(a*Cos[c + d*x] + b*Sin[c + d*x])^4, x, 3, (a^2 + b^2)^2/(3*a^3*b^2*d*(b + a*Cot[c + d*x])^3) + (a/b^3 - b/a^3)/(d*(b + a*Cot[c + d*x])^2) + (1/a^3 + (3*a)/b^4)/(d*(b + a*Cot[c + d*x])) + (4*a*Log[Cot[c + d*x]])/(b^5*d) - (4*a*Log[b + a*Cot[c + d*x]])/(b^5*d) + Tan[c + d*x]/(b^4*d)}
{Sec[c + d*x]^3/(a*Cos[c + d*x] + b*Sin[c + d*x])^4, x, 32, (8*a^2*ArcTanh[Sin[c + d*x]])/(b^6*d) + ArcTanh[Sin[c + d*x]]/(2*b^4*d) + (2*(a^2 + b^2)*ArcTanh[Sin[c + d*x]])/(b^6*d) + (4*a^3*ArcTanh[(b*Cos[c + d*x] - a*Sin[c + d*x])/Sqrt[a^2 + b^2]])/(b^6*Sqrt[a^2 + b^2]*d) + (3*a*ArcTanh[(b*Cos[c + d*x] - a*Sin[c + d*x])/Sqrt[a^2 + b^2]])/(2*b^4*Sqrt[a^2 + b^2]*d) + (6*a*Sqrt[a^2 + b^2]*ArcTanh[(b*Cos[c + d*x] - a*Sin[c + d*x])/Sqrt[a^2 + b^2]])/(b^6*d) - (4*a*Sec[c + d*x])/(b^5*d) - (a^2 + b^2)/(3*b^3*d*(a*Cos[c + d*x] + b*Sin[c + d*x])^3) + (3*a*(b*Cos[c + d*x] - a*Sin[c + d*x]))/(2*b^4*d*(a*Cos[c + d*x] + b*Sin[c + d*x])^2) - (4*a^2)/(b^5*d*(a*Cos[c + d*x] + b*Sin[c + d*x])) - (2*(a^2 + b^2))/(b^5*d*(a*Cos[c + d*x] + b*Sin[c + d*x])) + (Sec[c + d*x]*Tan[c + d*x])/(2*b^4*d)}
{Sec[c + d*x]^4/(a*Cos[c + d*x] + b*Sin[c + d*x])^4, x, 3, (a^2 + b^2)^3/(3*a^3*b^4*d*(b + a*Cot[c + d*x])^3) + (2*a^6 + 3*a^4*b^2 - b^6)/(a^3*b^5*d*(b + a*Cot[c + d*x])^2) + (10*a^6 + 9*a^4*b^2 + b^6)/(a^3*b^6*d*(b + a*Cot[c + d*x])) + (4*a*(5*a^2 + 3*b^2)*Log[Cot[c + d*x]])/(b^7*d) - (4*a*(5*a^2 + 3*b^2)*Log[b + a*Cot[c + d*x]])/(b^7*d) + ((10*a^2 + 3*b^2)*Tan[c + d*x])/(b^6*d) - (2*a*Tan[c + d*x]^2)/(b^5*d) + Tan[c + d*x]^3/(3*b^4*d)}


(* ::Subsection::Closed:: *)
(*Integrands of the form Cos[c+d x]^m (a Cos[c+d x]+b Sin[c+d x])^n when a^2+b^2=0*)


(* ::Subsubsection:: *)
(*n>0*)


(* ::Subsubsection::Closed:: *)
(*n<0*)


{Cos[c + d*x]^5/(a*Cos[c + d*x] + I*a*Sin[c + d*x]), x, 7, (5*x)/(16*a) + (I*Cos[c + d*x]^6)/(6*a*d) + (5*Cos[c + d*x]*Sin[c + d*x])/(16*a*d) + (5*Cos[c + d*x]^3*Sin[c + d*x])/(24*a*d) + (Cos[c + d*x]^5*Sin[c + d*x])/(6*a*d)}
{Cos[c + d*x]^4/(a*Cos[c + d*x] + I*a*Sin[c + d*x]), x, 6, (I*Cos[c + d*x]^5)/(5*a*d) + Sin[c + d*x]/(a*d) - (2*Sin[c + d*x]^3)/(3*a*d) + Sin[c + d*x]^5/(5*a*d)}
{Cos[c + d*x]^3/(a*Cos[c + d*x] + I*a*Sin[c + d*x]), x, 6, (3*x)/(8*a) + (I*Cos[c + d*x]^4)/(4*a*d) + (3*Cos[c + d*x]*Sin[c + d*x])/(8*a*d) + (Cos[c + d*x]^3*Sin[c + d*x])/(4*a*d)}
{Cos[c + d*x]^2/(a*Cos[c + d*x] + I*a*Sin[c + d*x]), x, 6, (I*Cos[c + d*x]^3)/(3*a*d) + Sin[c + d*x]/(a*d) - Sin[c + d*x]^3/(3*a*d)}
{Cos[c + d*x]^1/(a*Cos[c + d*x] + I*a*Sin[c + d*x]), x, 2, x/(2*a) + (I*Cos[c + d*x])/(2*d*(a*Cos[c + d*x] + I*a*Sin[c + d*x]))}
{Cos[c + d*x]^0/(a*Cos[c + d*x] + I*a*Sin[c + d*x]), x, 1, I/(d*(a*Cos[c + d*x] + I*a*Sin[c + d*x]))}
{Sec[c + d*x]^1/(a*Cos[c + d*x] + I*a*Sin[c + d*x]), x, 4, x/a + (I*Log[Cos[c + d*x]])/(a*d)}
{Sec[c + d*x]^2/(a*Cos[c + d*x] + I*a*Sin[c + d*x]), x, 5, ArcTanh[Sin[c + d*x]]/(a*d) - (I*Sec[c + d*x])/(a*d)}
{Sec[c + d*x]^3/(a*Cos[c + d*x] + I*a*Sin[c + d*x]), x, 5, -((I*Sec[c + d*x]^2)/(2*a*d)) + Tan[c + d*x]/(a*d)}
{Sec[c + d*x]^4/(a*Cos[c + d*x] + I*a*Sin[c + d*x]), x, 6, ArcTanh[Sin[c + d*x]]/(2*a*d) - (I*Sec[c + d*x]^3)/(3*a*d) + (Sec[c + d*x]*Tan[c + d*x])/(2*a*d)}
{Sec[c + d*x]^5/(a*Cos[c + d*x] + I*a*Sin[c + d*x]), x, 6, -((I*Sec[c + d*x]^4)/(4*a*d)) + Tan[c + d*x]/(a*d) + Tan[c + d*x]^3/(3*a*d)}
{Sec[c + d*x]^6/(a*Cos[c + d*x] + I*a*Sin[c + d*x]), x, 7, (3*ArcTanh[Sin[c + d*x]])/(8*a*d) - (I*Sec[c + d*x]^5)/(5*a*d) + (3*Sec[c + d*x]*Tan[c + d*x])/(8*a*d) + (Sec[c + d*x]^3*Tan[c + d*x])/(4*a*d)}
{Sec[c + d*x]^7/(a*Cos[c + d*x] + I*a*Sin[c + d*x]), x, 6, -((I*Sec[c + d*x]^6)/(6*a*d)) + Tan[c + d*x]/(a*d) + (2*Tan[c + d*x]^3)/(3*a*d) + Tan[c + d*x]^5/(5*a*d)}


{Cos[c + d*x]^5/(a*Cos[c + d*x] + I*a*Sin[c + d*x])^2, x, 9, (2*I*Cos[c + d*x]^7)/(7*a^2*d) + Sin[c + d*x]/(a^2*d) - (4*Sin[c + d*x]^3)/(3*a^2*d) + Sin[c + d*x]^5/(a^2*d) - (2*Sin[c + d*x]^7)/(7*a^2*d)}
{Cos[c + d*x]^4/(a*Cos[c + d*x] + I*a*Sin[c + d*x])^2, x, 5, x/(4*a^2) - 1/(16*a^2*d*(I - Cot[c + d*x])) - 1/(12*a^2*d*(I + Cot[c + d*x])^3) - (3*I)/(8*a^2*d*(I + Cot[c + d*x])^2) + 11/(16*a^2*d*(I + Cot[c + d*x]))}
{Cos[c + d*x]^3/(a*Cos[c + d*x] + I*a*Sin[c + d*x])^2, x, 9, (2*I*Cos[c + d*x]^5)/(5*a^2*d) + Sin[c + d*x]/(a^2*d) - Sin[c + d*x]^3/(a^2*d) + (2*Sin[c + d*x]^5)/(5*a^2*d)}
{Cos[c + d*x]^2/(a*Cos[c + d*x] + I*a*Sin[c + d*x])^2, x, 3, x/(4*a^2) + (I*Cos[c + d*x]^2)/(4*d*(a*Cos[c + d*x] + I*a*Sin[c + d*x])^2) + (I*Cos[c + d*x])/(4*d*(a^2*Cos[c + d*x] + I*a^2*Sin[c + d*x]))}
{Cos[c + d*x]^1/(a*Cos[c + d*x] + I*a*Sin[c + d*x])^2, x, 7, (2*I*Cos[c + d*x]^3)/(3*a^2*d) + Sin[c + d*x]/(a^2*d) - (2*Sin[c + d*x]^3)/(3*a^2*d)}
{Cos[c + d*x]^0/(a*Cos[c + d*x] + I*a*Sin[c + d*x])^2, x, 1, I/(2*d*(a*Cos[c + d*x] + I*a*Sin[c + d*x])^2)}
{Sec[c + d*x]^1/(a*Cos[c + d*x] + I*a*Sin[c + d*x])^2, x, 7, -(ArcTanh[Sin[c + d*x]]/(a^2*d)) + (2*I*Cos[c + d*x])/(a^2*d) + (2*Sin[c + d*x])/(a^2*d)}
{Sec[c + d*x]^2/(a*Cos[c + d*x] + I*a*Sin[c + d*x])^2, x, 4, (2*I*Log[Cot[c + d*x]])/(a^2*d) - (2*I*Log[I + Cot[c + d*x]])/(a^2*d) - Tan[c + d*x]/(a^2*d)}
{Sec[c + d*x]^3/(a*Cos[c + d*x] + I*a*Sin[c + d*x])^2, x, 7, (3*ArcTanh[Sin[c + d*x]])/(2*a^2*d) - (2*I*Sec[c + d*x])/(a^2*d) - (Sec[c + d*x]*Tan[c + d*x])/(2*a^2*d)}
{Sec[c + d*x]^4/(a*Cos[c + d*x] + I*a*Sin[c + d*x])^2, x, 3, -((I*(I - Cot[c + d*x])^3*Tan[c + d*x]^3)/(3*a^2*d))}
{Sec[c + d*x]^5/(a*Cos[c + d*x] + I*a*Sin[c + d*x])^2, x, 9, (5*ArcTanh[Sin[c + d*x]])/(8*a^2*d) - (2*I*Sec[c + d*x]^3)/(3*a^2*d) + (3*Sec[c + d*x]*Tan[c + d*x])/(8*a^2*d) - (Sec[c + d*x]*Tan[c + d*x]^3)/(4*a^2*d)}
{Sec[c + d*x]^6/(a*Cos[c + d*x] + I*a*Sin[c + d*x])^2, x, 4, Tan[c + d*x]/(a^2*d) - (I*Tan[c + d*x]^2)/(a^2*d) - (I*Tan[c + d*x]^4)/(2*a^2*d) - Tan[c + d*x]^5/(5*a^2*d)}


{Cos[c + d*x]^5/(a*Cos[c + d*x] + I*a*Sin[c + d*x])^3, x, 5, (5*x)/(32*a^3) - 1/(32*a^3*d*(I - Cot[c + d*x])) + I/(16*a^3*d*(I + Cot[c + d*x])^4) - 1/(3*a^3*d*(I + Cot[c + d*x])^3) - (23*I)/(32*a^3*d*(I + Cot[c + d*x])^2) + 13/(16*a^3*d*(I + Cot[c + d*x]))}
{Cos[c + d*x]^4/(a*Cos[c + d*x] + I*a*Sin[c + d*x])^3, x, 12, -((I*Cos[c + d*x]^5)/(5*a^3*d)) + (4*I*Cos[c + d*x]^7)/(7*a^3*d) + Sin[c + d*x]/(a^3*d) - (2*Sin[c + d*x]^3)/(a^3*d) + (9*Sin[c + d*x]^5)/(5*a^3*d) - (4*Sin[c + d*x]^7)/(7*a^3*d)}
{Cos[c + d*x]^3/(a*Cos[c + d*x] + I*a*Sin[c + d*x])^3, x, 4, x/(8*a^3) + (I*Cos[c + d*x]^3)/(6*d*(a*Cos[c + d*x] + I*a*Sin[c + d*x])^3) + (I*Cos[c + d*x]^2)/(8*a*d*(a*Cos[c + d*x] + I*a*Sin[c + d*x])^2) + (I*Cos[c + d*x])/(8*d*(a^3*Cos[c + d*x] + I*a^3*Sin[c + d*x]))}
{Cos[c + d*x]^2/(a*Cos[c + d*x] + I*a*Sin[c + d*x])^3, x, 12, -((I*Cos[c + d*x]^3)/(3*a^3*d)) + (4*I*Cos[c + d*x]^5)/(5*a^3*d) + Sin[c + d*x]/(a^3*d) - (5*Sin[c + d*x]^3)/(3*a^3*d) + (4*Sin[c + d*x]^5)/(5*a^3*d)}
{Cos[c + d*x]^1/(a*Cos[c + d*x] + I*a*Sin[c + d*x])^3, x, 2, (I*Cot[c + d*x]^2)/(2*a^3*d*(I + Cot[c + d*x])^2)}
{Cos[c + d*x]^0/(a*Cos[c + d*x] + I*a*Sin[c + d*x])^3, x, 1, I/(3*d*(a*Cos[c + d*x] + I*a*Sin[c + d*x])^3)}
{Sec[c + d*x]^1/(a*Cos[c + d*x] + I*a*Sin[c + d*x])^3, x, 4, 2/(a^3*d*(I + Cot[c + d*x])) - (I*Log[Cot[c + d*x]])/(a^3*d) + (I*Log[I + Cot[c + d*x]])/(a^3*d)}
{Sec[c + d*x]^2/(a*Cos[c + d*x] + I*a*Sin[c + d*x])^3, x, 10, -((3*ArcTanh[Sin[c + d*x]])/(a^3*d)) + (4*I*Cos[c + d*x])/(a^3*d) + (I*Sec[c + d*x])/(a^3*d) + (4*Sin[c + d*x])/(a^3*d)}
{Sec[c + d*x]^3/(a*Cos[c + d*x] + I*a*Sin[c + d*x])^3, x, 4, (4*I*Log[Cot[c + d*x]])/(a^3*d) - (4*I*Log[I + Cot[c + d*x]])/(a^3*d) - (3*Tan[c + d*x])/(a^3*d) + (I*Tan[c + d*x]^2)/(2*a^3*d)}
{Sec[c + d*x]^4/(a*Cos[c + d*x] + I*a*Sin[c + d*x])^3, x, 9, (5*ArcTanh[Sin[c + d*x]])/(2*a^3*d) - (4*I*Sec[c + d*x])/(a^3*d) + (I*Sec[c + d*x]^3)/(3*a^3*d) - (3*Sec[c + d*x]*Tan[c + d*x])/(2*a^3*d)}
{Sec[c + d*x]^5/(a*Cos[c + d*x] + I*a*Sin[c + d*x])^3, x, 3, (I*(I - Cot[c + d*x])^4*Tan[c + d*x]^4)/(4*a^3*d)}
{Sec[c + d*x]^6/(a*Cos[c + d*x] + I*a*Sin[c + d*x])^3, x, 12, (7*ArcTanh[Sin[c + d*x]])/(8*a^3*d) - (4*I*Sec[c + d*x]^3)/(3*a^3*d) + (I*Sec[c + d*x]^5)/(5*a^3*d) + (Sec[c + d*x]*Tan[c + d*x])/(8*a^3*d) - (3*Sec[c + d*x]*Tan[c + d*x]^3)/(4*a^3*d)}


(* ::Section::Closed:: *)
(*Integrands of the form Trig[c+d x]^m (a Sec[c+d x]+b Tan[c+d x])^n*)


{1/(Sec[x] + Tan[x]), x, 3, Log[1 + Sin[x]]}
{Sin[x]/(Sec[x] + Tan[x]), x, 4, -Log[1 + Sin[x]] + Sin[x]}
{Cos[x]/(Sec[x] + Tan[x]), x, 3, x + Cos[x]}
{Tan[x]/(Sec[x] + Tan[x]), x, 3, x + Cos[x]/(1 + Sin[x])}
{Cot[x]/(Sec[x] + Tan[x]), x, 4, -x - ArcTanh[Cos[x]]}
{Sec[x]/(Sec[x] + Tan[x]), x, 2, -(Cos[x]/(1 + Sin[x]))}
{Csc[x]/(Sec[x] + Tan[x]), x, 4, Log[Sin[x]] - Log[1 + Sin[x]]}


{1/(Sec[x] - Tan[x]), x, 3, -Log[1 - Sin[x]]}
{Sin[x]/(Sec[x] - Tan[x]), x, 4, -Log[1 - Sin[x]] - Sin[x]}
{Cos[x]/(Sec[x] - Tan[x]), x, 3, x - Cos[x]}
{Tan[x]/(Sec[x] - Tan[x]), x, 3, -x + Cos[x]/(1 - Sin[x])}
{Cot[x]/(Sec[x] - Tan[x]), x, 4, x - ArcTanh[Cos[x]]}
{Sec[x]/(Sec[x] - Tan[x]), x, 2, Cos[x]/(1 - Sin[x])}
{Csc[x]/(Sec[x] - Tan[x]), x, 4, -Log[1 - Sin[x]] + Log[Sin[x]]}


(* ::Section::Closed:: *)
(*Integrands of the form Trig[c+d x]^m (a Csc[c+d x]+b Cot[c+d x])^n*)


{Sin[x]/(Csc[x] + Cot[x]), x, 3, x - Sin[x]}
{Cos[x]/(Csc[x] + Cot[x]), x, 4, -Cos[x] + Log[1 + Cos[x]]}
{Tan[x]/(Csc[x] + Cot[x]), x, 4, -x+ArcTanh[Sin[x]]}
{Cot[x]/(Csc[x] + Cot[x]), x, 3, x - Sin[x]/(1 + Cos[x])}
{Sec[x]/(Csc[x] + Cot[x]), x, 4, -Log[Cos[x]] + Log[1 + Cos[x]]}
{Csc[x]/(Csc[x] + Cot[x]), x, 2, Sin[x]/(1 + Cos[x])}


{Sin[x]/(Csc[x] - Cot[x]), x, 3, x + Sin[x]}
{Cos[x]/(Csc[x] - Cot[x]), x, 4, Cos[x] + Log[1 - Cos[x]]}
{Tan[x]/(Csc[x] - Cot[x]), x, 4, x + ArcTanh[Sin[x]]}
{Cot[x]/(Csc[x] - Cot[x]), x, 3, -x - Sin[x]/(1 - Cos[x])}
{Sec[x]/(Csc[x] - Cot[x]), x, 4, Log[1 - Cos[x]] - Log[Cos[x]]}
{Csc[x]/(Csc[x] - Cot[x]), x, 2, -(Sin[x]/(1 - Cos[x]))}


(* ::Section::Closed:: *)
(*Integrands of the form Trig[c+d x]^m (a Csc[c+d x]+b Sin[c+d x])^n*)


{1/(Csc[c + d*x] + Sin[c + d*x]), x, 3, -(ArcTanh[Cos[c + d*x]/Sqrt[2]]/(Sqrt[2]*d))}
{Sin[c + d*x]/(Csc[c + d*x] + Sin[c + d*x]), x, 5, x + ArcTan[Cot[c + d*x]/Sqrt[2]]/(Sqrt[2]*d)}
{Cos[c + d*x]/(Csc[c + d*x] + Sin[c + d*x]), x, 2, Log[1 + Sin[c + d*x]^2]/(2*d)}
{Tan[c + d*x]/(Csc[c + d*x] + Sin[c + d*x]), x, 4, -(ArcTan[Sin[c + d*x]]/(2*d)) + ArcTanh[Sin[c + d*x]]/(2*d)}
{Cot[c + d*x]/(Csc[c + d*x] + Sin[c + d*x]), x, 2, ArcTan[Sin[c + d*x]]/d}
{Sec[c + d*x]/(Csc[c + d*x] + Sin[c + d*x]), x, 3, ArcTanh[Sin[c + d*x]^2]/(2*d)}
{Csc[c + d*x]/(Csc[c + d*x] + Sin[c + d*x]), x, 3, ArcTan[Sqrt[2]*Tan[c + d*x]]/(Sqrt[2]*d)}


{1/(Csc[c + d*x] - Sin[c + d*x]), x, 2, Sec[c + d*x]/d}
{Sin[c + d*x]/(Csc[c + d*x] - Sin[c + d*x]), x, 3, -x + Tan[c + d*x]/d}
{Cos[c + d*x]/(Csc[c + d*x] - Sin[c + d*x]), x, 2, -(Log[Cos[c + d*x]]/d), -(Log[1 - Sin[c + d*x]^2]/(2*d))}
{Tan[c + d*x]/(Csc[c + d*x] - Sin[c + d*x]), x, 3, -(ArcTanh[Sin[c + d*x]]/(2*d)) + Sin[c + d*x]/(2*d*(1 - Sin[c + d*x]^2))}
{Cot[c + d*x]/(Csc[c + d*x] - Sin[c + d*x]), x, 2, ArcTanh[Sin[c + d*x]]/d}
{Sec[c + d*x]/(Csc[c + d*x] - Sin[c + d*x]), x, 2, 1/(2*d*(1 - Sin[c + d*x]^2))}
{Csc[c + d*x]/(Csc[c + d*x] - Sin[c + d*x]), x, 2, Tan[c + d*x]/d}


(* ::Section::Closed:: *)
(*Integrands of the form Trig[c+d x]^m (a Sin[c+d x]+b Tan[c+d x])^n*)


(* ::Subsection::Closed:: *)
(*Integrands of the form Cos[c+d x]^m (a Sin[c+d x]+b Tan[c+d x])^n*)


(* ::Subsubsection::Closed:: *)
(*n>0*)


{Cos[c + d*x]^m*(a*Sin[c + d*x] + b*Tan[c + d*x]), x, 5, -((b*Cos[c + d*x]^m)/(d*m)) - (a*Cos[c + d*x]^(1 + m))/(d*(1 + m))}

{Cos[c + d*x]^3*(a*Sin[c + d*x] + b*Tan[c + d*x]), x, 5, -((b*Cos[c + d*x]^3)/(3*d)) - (a*Cos[c + d*x]^4)/(4*d)}
{Cos[c + d*x]^2*(a*Sin[c + d*x] + b*Tan[c + d*x]), x, 5, -((a*Cos[c + d*x]^3)/(3*d)) + (b*Sin[c + d*x]^2)/(2*d)}
{Cos[c + d*x]^1*(a*Sin[c + d*x] + b*Tan[c + d*x]), x, 5, -((b*Cos[c + d*x])/d) + (a*Sin[c + d*x]^2)/(2*d)}
{Cos[c + d*x]^0*(a*Sin[c + d*x] + b*Tan[c + d*x]), x, 3, -((a*Cos[c + d*x])/d) - (b*Log[Cos[c + d*x]])/d}
{Sec[c + d*x]^1*(a*Sin[c + d*x] + b*Tan[c + d*x]), x, 5, -((a*Log[Cos[c + d*x]])/d) + (b*Sec[c + d*x])/d}
{Sec[c + d*x]^2*(a*Sin[c + d*x] + b*Tan[c + d*x]), x, 5, (a*Sec[c + d*x])/d + (b*Sec[c + d*x]^2)/(2*d)}
{Sec[c + d*x]^3*(a*Sin[c + d*x] + b*Tan[c + d*x]), x, 5, (a*Sec[c + d*x]^2)/(2*d) + (b*Sec[c + d*x]^3)/(3*d)}


{Cos[c + d*x]^m*(a*Sin[c + d*x] + b*Tan[c + d*x])^2, x, 9, -((b^2*Cos[c + d*x]^(-1 + m)*Sin[c + d*x])/(d*m)) - (2*a*b*Cos[c + d*x]^m*Sin[c + d*x])/(d*(1 + m)) - (a^2*Cos[c + d*x]^(1 + m)*Sin[c + d*x])/(d*(2 + m)) + (a^2*Cos[c + d*x]^(1 + m)*(Cos[c + d*x]^2)^((1/2)*(-1 - m))*Hypergeometric2F1[1/2, (1 - m)/2, 3/2, Sin[c + d*x]^2]*Sin[c + d*x])/(d*(2 + m)) + (2*a*b*Cos[c + d*x]^m*Hypergeometric2F1[1/2, (2 - m)/2, 3/2, Sin[c + d*x]^2]*Sin[c + d*x])/((Cos[c + d*x]^2)^(m/2)*(d*(1 + m))) + (b^2*Cos[c + d*x]^(-1 + m)*(Cos[c + d*x]^2)^((1 - m)/2)*Hypergeometric2F1[1/2, (3 - m)/2, 3/2, Sin[c + d*x]^2]*Sin[c + d*x])/(d*m)}

{Cos[c + d*x]^3*(a*Sin[c + d*x] + b*Tan[c + d*x])^2, x, 9, (a*b*x)/4 + (a*b*Cos[c + d*x]*Sin[c + d*x])/(4*d) - (a*b*Cos[c + d*x]^3*Sin[c + d*x])/(2*d) + (a^2*Sin[c + d*x]^3)/(3*d) + (b^2*Sin[c + d*x]^3)/(3*d) - (a^2*Sin[c + d*x]^5)/(5*d)}
{Cos[c + d*x]^2*(a*Sin[c + d*x] + b*Tan[c + d*x])^2, x, 7, (a^2*x)/8 + (b^2*x)/2 + (a^2*Cos[c + d*x]*Sin[c + d*x])/(8*d) - (b^2*Cos[c + d*x]*Sin[c + d*x])/(2*d) - (a^2*Cos[c + d*x]^3*Sin[c + d*x])/(4*d) + (2*a*b*Sin[c + d*x]^3)/(3*d)}
{Cos[c + d*x]^1*(a*Sin[c + d*x] + b*Tan[c + d*x])^2, x, 7, a*b*x + (b^2*ArcTanh[Sin[c + d*x]])/d - (b^2*Sin[c + d*x])/d - (a*b*Cos[c + d*x]*Sin[c + d*x])/d + (a^2*Sin[c + d*x]^3)/(3*d)}
{Cos[c + d*x]^0*(a*Sin[c + d*x] + b*Tan[c + d*x])^2, x, 8, (a^2*x)/2 - b^2*x + (2*a*b*ArcTanh[Sin[c + d*x]])/d - (2*a*b*Sin[c + d*x])/d - (a^2*Cos[c + d*x]*Sin[c + d*x])/(2*d) + (b^2*Tan[c + d*x])/d}
{Sec[c + d*x]^1*(a*Sin[c + d*x] + b*Tan[c + d*x])^2, x, 9, -2*a*b*x + (a^2*ArcTanh[Sin[c + d*x]])/d - (b^2*ArcTanh[Sin[c + d*x]])/(2*d) - (a^2*Sin[c + d*x])/d + (2*a*b*Tan[c + d*x])/d + (b^2*Sec[c + d*x]*Tan[c + d*x])/(2*d)}
{Sec[c + d*x]^2*(a*Sin[c + d*x] + b*Tan[c + d*x])^2, x, 9, (-a^2)*x - (a*b*ArcTanh[Sin[c + d*x]])/d + (a^2*Tan[c + d*x])/d + (a*b*Sec[c + d*x]*Tan[c + d*x])/d + (b^2*Tan[c + d*x]^3)/(3*d)}
{Sec[c + d*x]^3*(a*Sin[c + d*x] + b*Tan[c + d*x])^2, x, 10, -((a^2*ArcTanh[Sin[c + d*x]])/(2*d)) - (b^2*ArcTanh[Sin[c + d*x]])/(8*d) + (a^2*Sec[c + d*x]*Tan[c + d*x])/(2*d) + (b^2*Sec[c + d*x]*Tan[c + d*x])/(8*d) + (2*a*b*Tan[c + d*x]^3)/(3*d) + (b^2*Sec[c + d*x]*Tan[c + d*x]^3)/(4*d)}


{Cos[c + d*x]^m*(a*Sin[c + d*x] + b*Tan[c + d*x])^3, x, 4, (b^3*Cos[c + d*x]^(-2 + m))/(d*(2 - m)) + (3*a*b^2*Cos[c + d*x]^(-1 + m))/(d*(1 - m)) - (b*(3*a^2 - b^2)*Cos[c + d*x]^m)/(d*m) - (a*(a^2 - 3*b^2)*Cos[c + d*x]^(1 + m))/(d*(1 + m)) + (3*a^2*b*Cos[c + d*x]^(2 + m))/(d*(2 + m)) + (a^3*Cos[c + d*x]^(3 + m))/(d*(3 + m))}

{Cos[c + d*x]^3*(a*Sin[c + d*x] + b*Tan[c + d*x])^3, x, 4, -(((a^2 - b^2)*(b + a*Cos[c + d*x])^4)/(4*a^3*d)) - (2*b*(b + a*Cos[c + d*x])^5)/(5*a^3*d) + (b + a*Cos[c + d*x])^6/(6*a^3*d)}
{Cos[c + d*x]^2*(a*Sin[c + d*x] + b*Tan[c + d*x])^3, x, 4, -((3*a*b^2*Cos[c + d*x])/d) - (b*(3*a^2 - b^2)*Cos[c + d*x]^2)/(2*d) - (a*(a^2 - 3*b^2)*Cos[c + d*x]^3)/(3*d) + (3*a^2*b*Cos[c + d*x]^4)/(4*d) + (a^3*Cos[c + d*x]^5)/(5*d) - (b^3*Log[Cos[c + d*x]])/d}
{Cos[c + d*x]^1*(a*Sin[c + d*x] + b*Tan[c + d*x])^3, x, 4, -((b*(3*a^2 - b^2)*Cos[c + d*x])/d) - (a*(a^2 - 3*b^2)*Cos[c + d*x]^2)/(2*d) + (a^2*b*Cos[c + d*x]^3)/d + (a^3*Cos[c + d*x]^4)/(4*d) - (3*a*b^2*Log[Cos[c + d*x]])/d + (b^3*Sec[c + d*x])/d}
{Cos[c + d*x]^0*(a*Sin[c + d*x] + b*Tan[c + d*x])^3, x, 4, -((a*(a^2 - 3*b^2)*Cos[c + d*x])/d) + (3*a^2*b*Cos[c + d*x]^2)/(2*d) + (a^3*Cos[c + d*x]^3)/(3*d) - (b*(3*a^2 - b^2)*Log[Cos[c + d*x]])/d + (3*a*b^2*Sec[c + d*x])/d + (b^3*Sec[c + d*x]^2)/(2*d)}
{Sec[c + d*x]^1*(a*Sin[c + d*x] + b*Tan[c + d*x])^3, x, 4, (3*a^2*b*Cos[c + d*x])/d + (a^3*Cos[c + d*x]^2)/(2*d) - (a*(a^2 - 3*b^2)*Log[Cos[c + d*x]])/d + (b*(3*a^2 - b^2)*Sec[c + d*x])/d + (3*a*b^2*Sec[c + d*x]^2)/(2*d) + (b^3*Sec[c + d*x]^3)/(3*d)}
{Sec[c + d*x]^2*(a*Sin[c + d*x] + b*Tan[c + d*x])^3, x, 4, (a^3*Cos[c + d*x])/d + (3*a^2*b*Log[Cos[c + d*x]])/d + (a*(a^2 - 3*b^2)*Sec[c + d*x])/d + (b*(3*a^2 - b^2)*Sec[c + d*x]^2)/(2*d) + (a*b^2*Sec[c + d*x]^3)/d + (b^3*Sec[c + d*x]^4)/(4*d)}
{Sec[c + d*x]^3*(a*Sin[c + d*x] + b*Tan[c + d*x])^3, x, 4, (a^3*Log[Cos[c + d*x]])/d - (3*a^2*b*Sec[c + d*x])/d + (a*(a^2 - 3*b^2)*Sec[c + d*x]^2)/(2*d) + (b*(3*a^2 - b^2)*Sec[c + d*x]^3)/(3*d) + (3*a*b^2*Sec[c + d*x]^4)/(4*d) + (b^3*Sec[c + d*x]^5)/(5*d)}


(* ::Subsubsection::Closed:: *)
(*n<0*)


{Cos[c + d*x]^3/(a*Sin[c + d*x] + b*Tan[c + d*x]), x, 4, -((b*Cos[c + d*x])/(a^2*d)) + Cos[c + d*x]^2/(2*a*d) + Log[1 - Cos[c + d*x]]/(2*(a + b)*d) + Log[1 + Cos[c + d*x]]/(2*(a - b)*d) - (b^4*Log[b + a*Cos[c + d*x]])/(a^3*(a^2 - b^2)*d)}
{Cos[c + d*x]^2/(a*Sin[c + d*x] + b*Tan[c + d*x]), x, 4, Cos[c + d*x]/(a*d) + Log[1 - Cos[c + d*x]]/(2*(a + b)*d) - Log[1 + Cos[c + d*x]]/(2*(a - b)*d) + (b^3*Log[b + a*Cos[c + d*x]])/(a^2*(a^2 - b^2)*d)}
{Cos[c + d*x]^1/(a*Sin[c + d*x] + b*Tan[c + d*x]), x, 4, Log[1 - Cos[c + d*x]]/(2*(a + b)*d) + Log[1 + Cos[c + d*x]]/(2*(a - b)*d) - (b^2*Log[b + a*Cos[c + d*x]])/(a*(a^2 - b^2)*d)}
{Cos[c + d*x]^0/(a*Sin[c + d*x] + b*Tan[c + d*x]), x, 7, Log[1 - Cos[c + d*x]]/(2*(a + b)*d) - Log[1 + Cos[c + d*x]]/(2*(a - b)*d) + (b*Log[b + a*Cos[c + d*x]])/((a^2 - b^2)*d)}
{Sec[c + d*x]^1/(a*Sin[c + d*x] + b*Tan[c + d*x]), x, 7, Log[1 - Cos[c + d*x]]/(2*(a + b)*d) + Log[1 + Cos[c + d*x]]/(2*(a - b)*d) - (a*Log[b + a*Cos[c + d*x]])/((a^2 - b^2)*d)}
{Sec[c + d*x]^2/(a*Sin[c + d*x] + b*Tan[c + d*x]), x, 4, Log[1 - Cos[c + d*x]]/(2*(a + b)*d) - Log[Cos[c + d*x]]/(b*d) - Log[1 + Cos[c + d*x]]/(2*(a - b)*d) + (a^2*Log[b + a*Cos[c + d*x]])/(b*(a^2 - b^2)*d)}
{Sec[c + d*x]^3/(a*Sin[c + d*x] + b*Tan[c + d*x]), x, 4, Log[1 - Cos[c + d*x]]/(2*(a + b)*d) + (a*Log[Cos[c + d*x]])/(b^2*d) + Log[1 + Cos[c + d*x]]/(2*(a - b)*d) - (a^3*Log[b + a*Cos[c + d*x]])/(b^2*(a^2 - b^2)*d) + Sec[c + d*x]/(b*d)}


{Cos[c + d*x]^3/(a*Sin[c + d*x] + b*Tan[c + d*x])^2, x, 0, -((-((4*b*(c + d*x)*(b + a*Cos[c + d*x]))/a^3) + (4*b^4*(5*a^2 - 2*b^2)*ArcTanh[((-a + b)*Tan[(1/2)*(c + d*x)])/Sqrt[a^2 - b^2]]*(b + a*Cos[c + d*x]))/(a^3*(a^2 - b^2)^(5/2)) + ((b + a*Cos[c + d*x])*Cot[(1/2)*(c + d*x)])/(a + b)^2 + (2*b^5*Sin[c + d*x])/(a^2*(a - b)^2*(a + b)^2) + (2*(b + a*Cos[c + d*x])*Sin[c + d*x])/a^2 + ((b + a*Cos[c + d*x])*Tan[(1/2)*(c + d*x)])/(a - b)^2)/(2*d*(b + a*Cos[c + d*x])))}
{Cos[c + d*x]^2/(a*Sin[c + d*x] + b*Tan[c + d*x])^2, x, 0, (-((2*(c + d*x)*(b + a*Cos[c + d*x]))/a^2) - (4*b^3*(-4*a^2 + b^2)*ArcTanh[((-a + b)*Tan[(1/2)*(c + d*x)])/Sqrt[a^2 - b^2]]*(b + a*Cos[c + d*x]))/(a^2*(a^2 - b^2)^(5/2)) - ((b + a*Cos[c + d*x])*Cot[(1/2)*(c + d*x)])/(a + b)^2 + (2*b^4*Sin[c + d*x])/(a*(a - b)^2*(a + b)^2) + ((b + a*Cos[c + d*x])*Tan[(1/2)*(c + d*x)])/(a - b)^2)/(2*d*(b + a*Cos[c + d*x]))}
{Cos[c + d*x]^1/(a*Sin[c + d*x] + b*Tan[c + d*x])^2, x, 0, -((6*a*b^2*ArcTanh[((-a + b)*Tan[(1/2)*(c + d*x)])/Sqrt[a^2 - b^2]])/((a^2 - b^2)^(5/2)*d)) + (2*a*b*Cot[c + d*x])/((a^2 - b^2)^2*d) - ((a^2 + b^2)*Csc[c + d*x])/((a^2 - b^2)^2*d) - (b^3*Sin[c + d*x])/((a^2 - b^2)^2*d*(b + a*Cos[c + d*x]))}
{Cos[c + d*x]^0/(a*Sin[c + d*x] + b*Tan[c + d*x])^2, x, 9, -((4*a^2*b*ArcTanh[(Sqrt[a^2 - b^2]*Tan[(1/2)*(c + d*x)])/(a + b)])/((a^2 - b^2)^(5/2)*d)) - (2*b^3*ArcTanh[(Sqrt[a^2 - b^2]*Tan[(1/2)*(c + d*x)])/(a + b)])/((a^2 - b^2)^(5/2)*d) - Sin[c + d*x]/(2*(a + b)^2*d*(1 - Cos[c + d*x])) + Sin[c + d*x]/(2*(a - b)^2*d*(1 + Cos[c + d*x])) + (a*b^2*Sin[c + d*x])/((a^2 - b^2)^2*d*(b + a*Cos[c + d*x]))}
{Sec[c + d*x]^1/(a*Sin[c + d*x] + b*Tan[c + d*x])^2, x, 0, -((2*a*(a^2 + 2*b^2)*ArcTanh[((-a + b)*Tan[(1/2)*(c + d*x)])/Sqrt[a^2 - b^2]])/((a^2 - b^2)^(5/2)*d)) + (2*a*b*Cot[c + d*x])/((a^2 - b^2)^2*d) - ((a^2 + b^2)*Csc[c + d*x])/((a^2 - b^2)^2*d) - (a^2*b*Sin[c + d*x])/((a^2 - b^2)^2*d*(b + a*Cos[c + d*x]))}
{Sec[c + d*x]^2/(a*Sin[c + d*x] + b*Tan[c + d*x])^2, x, 6, -((6*a^2*b*ArcTanh[(Sqrt[a^2 - b^2]*Tan[(1/2)*(c + d*x)])/(a + b)])/((a^2 - b^2)^(5/2)*d)) - Cot[c + d*x]/(d*(b + a*Cos[c + d*x])^2) - (a*b*Sin[c + d*x])/((a^2 - b^2)*d*(b + a*Cos[c + d*x])^2) + (a*(2*a^2 + b^2)*Sin[c + d*x])/((a^2 - b^2)^2*d*(b + a*Cos[c + d*x]))}
{Sec[c + d*x]^3/(a*Sin[c + d*x] + b*Tan[c + d*x])^2, x, 0, -((-((4*(a^5 - 4*a^3*b^2)*ArcTanh[((-a + b)*Tan[(1/2)*(c + d*x)])/Sqrt[a^2 - b^2]])/(b^2*(a^2 - b^2)^(5/2))) + Cot[(1/2)*(c + d*x)]/(a + b)^2 + (2*Log[Cos[(1/2)*(c + d*x)] - Sin[(1/2)*(c + d*x)]])/b^2 - (2*Log[Cos[(1/2)*(c + d*x)] + Sin[(1/2)*(c + d*x)]])/b^2 + (2*a^4*Sin[c + d*x])/((a - b)^2*b*(a + b)^2*(b + a*Cos[c + d*x])) + Tan[(1/2)*(c + d*x)]/(a - b)^2)/(2*d))}


{Cos[c + d*x]^3/(a*Sin[c + d*x] + b*Tan[c + d*x])^3, x, 4, -(1/(4*(a + b)^3*d*(1 - Cos[c + d*x]))) - 1/(4*(a - b)^3*d*(1 + Cos[c + d*x])) + b^6/(2*a^3*(a^2 - b^2)^2*d*(b + a*Cos[c + d*x])^2) - (2*b^5*(3*a^2 - b^2))/(a^3*(a^2 - b^2)^3*d*(b + a*Cos[c + d*x])) - ((2*a + 5*b)*Log[1 - Cos[c + d*x]])/(4*(a + b)^4*d) - ((2*a - 5*b)*Log[1 + Cos[c + d*x]])/(4*(a - b)^4*d) - (b^4*(15*a^4 - 4*a^2*b^2 + b^4)*Log[b + a*Cos[c + d*x]])/(a^3*(a^2 - b^2)^4*d)}
{Cos[c + d*x]^2/(a*Sin[c + d*x] + b*Tan[c + d*x])^3, x, 4, -(1/(4*(a + b)^3*d*(1 - Cos[c + d*x]))) + 1/(4*(a - b)^3*d*(1 + Cos[c + d*x])) - b^5/(2*a^2*(a^2 - b^2)^2*d*(b + a*Cos[c + d*x])^2) + (b^4*(5*a^2 - b^2))/(a^2*(a^2 - b^2)^3*d*(b + a*Cos[c + d*x])) - ((a + 4*b)*Log[1 - Cos[c + d*x]])/(4*(a + b)^4*d) + ((a - 4*b)*Log[1 + Cos[c + d*x]])/(4*(a - b)^4*d) + (2*b^3*(5*a^2 + b^2)*Log[b + a*Cos[c + d*x]])/((a^2 - b^2)^4*d)}
{Cos[c + d*x]^1/(a*Sin[c + d*x] + b*Tan[c + d*x])^3, x, 4, -(1/(4*(a + b)^3*d*(1 - Cos[c + d*x]))) - 1/(4*(a - b)^3*d*(1 + Cos[c + d*x])) + b^4/(2*a*(a^2 - b^2)^2*d*(b + a*Cos[c + d*x])^2) - (4*a*b^3)/((a^2 - b^2)^3*d*(b + a*Cos[c + d*x])) - (3*b*Log[1 - Cos[c + d*x]])/(4*(a + b)^4*d) + (3*b*Log[1 + Cos[c + d*x]])/(4*(a - b)^4*d) - (6*a*b^2*(a^2 + b^2)*Log[b + a*Cos[c + d*x]])/((a^2 - b^2)^4*d)}
{Cos[c + d*x]^0/(a*Sin[c + d*x] + b*Tan[c + d*x])^3, x, 4, -(1/(4*(a + b)^3*d*(1 - Cos[c + d*x]))) + 1/(4*(a - b)^3*d*(1 + Cos[c + d*x])) - b^3/(2*(a^2 - b^2)^2*d*(b + a*Cos[c + d*x])^2) + (b^2*(3*a^2 + b^2))/((a^2 - b^2)^3*d*(b + a*Cos[c + d*x])) + ((a - 2*b)*Log[1 - Cos[c + d*x]])/(4*(a + b)^4*d) - ((a + 2*b)*Log[1 + Cos[c + d*x]])/(4*(a - b)^4*d) + (b*(3*a^4 + 8*a^2*b^2 + b^4)*Log[b + a*Cos[c + d*x]])/((a^2 - b^2)^4*d)}
{Sec[c + d*x]^1/(a*Sin[c + d*x] + b*Tan[c + d*x])^3, x, 4, -(1/(4*(a + b)^3*d*(1 - Cos[c + d*x]))) - 1/(4*(a - b)^3*d*(1 + Cos[c + d*x])) + (a*b^2)/(2*(a^2 - b^2)^2*d*(b + a*Cos[c + d*x])^2) - (2*a*b*(a^2 + b^2))/((a^2 - b^2)^3*d*(b + a*Cos[c + d*x])) + ((2*a - b)*Log[1 - Cos[c + d*x]])/(4*(a + b)^4*d) + ((2*a + b)*Log[1 + Cos[c + d*x]])/(4*(a - b)^4*d) - (a*(a^4 + 8*a^2*b^2 + 3*b^4)*Log[b + a*Cos[c + d*x]])/((a^2 - b^2)^4*d)}
{Sec[c + d*x]^2/(a*Sin[c + d*x] + b*Tan[c + d*x])^3, x, 10, -((3*a^2*b)/(2*(a^2 - b^2)^2*d*(b + a*Cos[c + d*x])^2)) + (3*a^2*(a^2 + 3*b^2))/(2*(a^2 - b^2)^3*d*(b + a*Cos[c + d*x])) + (b - a*Cos[c + d*x])/(2*(a^2 - b^2)*d*(b + a*Cos[c + d*x])^2*(1 - Cos[c + d*x]^2)) + (3*a*Log[1 - Cos[c + d*x]])/(4*(a + b)^4*d) - (3*a*Log[1 + Cos[c + d*x]])/(4*(a - b)^4*d) + (6*a^2*b*(a^2 + b^2)*Log[b + a*Cos[c + d*x]])/((a^2 - b^2)^4*d)}
{Sec[c + d*x]^3/(a*Sin[c + d*x] + b*Tan[c + d*x])^3, x, 10, (a*(2*a^2 + b^2))/(2*(a^2 - b^2)^2*d*(b + a*Cos[c + d*x])^2) - (a*b*(11*a^2 + b^2))/(2*(a^2 - b^2)^3*d*(b + a*Cos[c + d*x])) - (a - b*Cos[c + d*x])/(2*(a^2 - b^2)*d*(b + a*Cos[c + d*x])^2*(1 - Cos[c + d*x]^2)) + ((4*a + b)*Log[1 - Cos[c + d*x]])/(4*(a + b)^4*d) + ((4*a - b)*Log[1 + Cos[c + d*x]])/(4*(a - b)^4*d) - (2*a^3*(a^2 + 5*b^2)*Log[b + a*Cos[c + d*x]])/((a^2 - b^2)^4*d)}


(* ::Section::Closed:: *)
(*Integrands of the form Trig[c+d x]^m (a Csc[c+d x]+b Cot[c+d x])^n*)


(* ::Subsection::Closed:: *)
(*Integrands of the form Sin[c+d x]^m (a Csc[c+d x]+b Cot[c+d x])^n*)


{Csc[c + d*x]*(Cot[c + d*x] + Csc[c + d*x]), x, 2, -(((1 + Cos[c + d*x])*Csc[c + d*x])/d)}


(* ::Section::Closed:: *)
(*Integrands of the form Cos[c+d x]^m Sin[c+d x]^n (a Cos[c+d x]+b Sin[c+d x])^p*)


(* ::Subsubsection:: *)
(*p>0*)


(* ::Subsubsection::Closed:: *)
(*p<0*)


{Cos[x]*Sin[x]^1/(a*Cos[x] + b*Sin[x]), x, 5, (a*b*ArcTanh[(b*Cos[x] - a*Sin[x])/Sqrt[a^2 + b^2]])/(a^2 + b^2)^(3/2) - (a*Cos[x])/(a^2 + b^2) + (b*Sin[x])/(a^2 + b^2)}
{Cos[x]*Sin[x]^2/(a*Cos[x] + b*Sin[x]), x, 5, -((a*b^2*x)/(a^2 + b^2)^2) + (a*x)/(2*(a^2 + b^2)) + (a^2*b*Log[a*Cos[x] + b*Sin[x]])/(a^2 + b^2)^2 - (a*Cos[x]*Sin[x])/(2*(a^2 + b^2)) + (b*Sin[x]^2)/(2*(a^2 + b^2))}
{Cos[x]*Sin[x]^3/(a*Cos[x] + b*Sin[x]), x, 8, (a^3*b*ArcTanh[(b*Cos[x] - a*Sin[x])/Sqrt[a^2 + b^2]])/(a^2 + b^2)^(5/2) + (a*b^2*Cos[x])/(a^2 + b^2)^2 - (a*Cos[x])/(a^2 + b^2) + (a*Cos[x]^3)/(3*(a^2 + b^2)) + (a^2*b*Sin[x])/(a^2 + b^2)^2 + (b*Sin[x]^3)/(3*(a^2 + b^2))}

{Cos[x]^2*Sin[x]^1/(a*Cos[x] + b*Sin[x]), x, 5, -((a^2*b*x)/(a^2 + b^2)^2) + (b*x)/(2*(a^2 + b^2)) - (a*b^2*Log[a*Cos[x] + b*Sin[x]])/(a^2 + b^2)^2 + (b*Cos[x]*Sin[x])/(2*(a^2 + b^2)) + (a*Sin[x]^2)/(2*(a^2 + b^2))}
{Cos[x]^2*Sin[x]^2/(a*Cos[x] + b*Sin[x]), x, 8, -((a^2*b^2*ArcTanh[(b*Cos[x] - a*Sin[x])/Sqrt[a^2 + b^2]])/(a^2 + b^2)^(5/2)) + (a^2*b*Cos[x])/(a^2 + b^2)^2 - (b*Cos[x]^3)/(3*(a^2 + b^2)) - (a*b^2*Sin[x])/(a^2 + b^2)^2 + (a*Sin[x]^3)/(3*(a^2 + b^2))}
{Cos[x]^2*Sin[x]^3/(a*Cos[x] + b*Sin[x]), x, 9, (a^2*b^3*x)/(a^2 + b^2)^3 - (a^2*b*x)/(2*(a^2 + b^2)^2) + (b*x)/(8*(a^2 + b^2)) - (a^3*b^2*Log[a*Cos[x] + b*Sin[x]])/(a^2 + b^2)^3 + (a^2*b*Cos[x]*Sin[x])/(2*(a^2 + b^2)^2) + (b*Cos[x]*Sin[x])/(8*(a^2 + b^2)) - (b*Cos[x]^3*Sin[x])/(4*(a^2 + b^2)) - (a*b^2*Sin[x]^2)/(2*(a^2 + b^2)^2) + (a*Sin[x]^4)/(4*(a^2 + b^2))}

{Cos[x]^3*Sin[x]^1/(a*Cos[x] + b*Sin[x]), x, 8, (a*b^3*ArcTanh[(b*Cos[x] - a*Sin[x])/Sqrt[a^2 + b^2]])/(a^2 + b^2)^(5/2) - (a*b^2*Cos[x])/(a^2 + b^2)^2 - (a*Cos[x]^3)/(3*(a^2 + b^2)) - (a^2*b*Sin[x])/(a^2 + b^2)^2 + (b*Sin[x])/(a^2 + b^2) - (b*Sin[x]^3)/(3*(a^2 + b^2))}
{Cos[x]^3*Sin[x]^2/(a*Cos[x] + b*Sin[x]), x, 9, (a^3*b^2*x)/(a^2 + b^2)^3 - (a*b^2*x)/(2*(a^2 + b^2)^2) + (a*x)/(8*(a^2 + b^2)) - (b*Cos[x]^4)/(4*(a^2 + b^2)) + (a^2*b^3*Log[a*Cos[x] + b*Sin[x]])/(a^2 + b^2)^3 - (a*b^2*Cos[x]*Sin[x])/(2*(a^2 + b^2)^2) + (a*Cos[x]*Sin[x])/(8*(a^2 + b^2)) - (a*Cos[x]^3*Sin[x])/(4*(a^2 + b^2)) - (a^2*b*Sin[x]^2)/(2*(a^2 + b^2)^2)}
{Cos[x]^3*Sin[x]^3/(a*Cos[x] + b*Sin[x]), x, 15, (a^3*b^3*ArcTanh[(b*Cos[x] - a*Sin[x])/Sqrt[a^2 + b^2]])/(a^2 + b^2)^(7/2) - (a^3*b^2*Cos[x])/(a^2 + b^2)^3 + (a*b^2*Cos[x]^3)/(3*(a^2 + b^2)^2) - (a*Cos[x]^3)/(3*(a^2 + b^2)) + (a*Cos[x]^5)/(5*(a^2 + b^2)) + (a^2*b^3*Sin[x])/(a^2 + b^2)^3 - (a^2*b*Sin[x]^3)/(3*(a^2 + b^2)^2) + (b*Sin[x]^3)/(3*(a^2 + b^2)) - (b*Sin[x]^5)/(5*(a^2 + b^2))}


{Cos[x]*Sin[x]^1/(a*Cos[x] + b*Sin[x])^2, x, 6, (2*a*b*x)/(a^2 + b^2)^2 - ((a^2 - b^2)*Log[a*Cos[x] + b*Sin[x]])/(a^2 + b^2)^2 - (b*Sin[x])/((a^2 + b^2)*(a*Cos[x] + b*Sin[x])), (2*a*b*x)/(a^2 + b^2)^2 - (a^2*Log[a*Cos[x] + b*Sin[x]])/(a^2 + b^2)^2 + (b^2*Log[a*Cos[x] + b*Sin[x]])/(a^2 + b^2)^2 - (b*Sin[x])/((a^2 + b^2)*(a*Cos[x] + b*Sin[x]))}
{Cos[x]*Sin[x]^2/(a*Cos[x] + b*Sin[x])^2, x, 13, -((a*(a^2 - 2*b^2)*ArcTanh[(b*Cos[x] - a*Sin[x])/Sqrt[a^2 + b^2]])/(a^2 + b^2)^(5/2)) - (2*a*b*Cos[x])/(a^2 + b^2)^2 - ((a^2 - b^2)*Sin[x])/(a^2 + b^2)^2 - (a^2*b)/((a^2 + b^2)^2*(a*Cos[x] + b*Sin[x])), -((a^3*ArcTanh[(b*Cos[x] - a*Sin[x])/Sqrt[a^2 + b^2]])/(a^2 + b^2)^(5/2)) + (2*a*b^2*ArcTanh[(b*Cos[x] - a*Sin[x])/Sqrt[a^2 + b^2]])/(a^2 + b^2)^(5/2) - (2*a*b*Cos[x])/(a^2 + b^2)^2 - (a^2*Sin[x])/(a^2 + b^2)^2 + (b^2*Sin[x])/(a^2 + b^2)^2 - (a^2*b)/((a^2 + b^2)^2*(a*Cos[x] + b*Sin[x]))}
{Cos[x]*Sin[x]^3/(a*Cos[x] + b*Sin[x])^2, x, 16, (b*(3*a^3 - a*b^2)*x)/(a^2 + b^2)^3 - (a^2*(a^2 - 3*b^2)*Log[a*Cos[x] + b*Sin[x]])/(a^2 + b^2)^3 - (a*b*Cos[x]*Sin[x])/(a^2 + b^2)^2 - ((a^2 - b^2)*Sin[x]^2)/(2*(a^2 + b^2)^2) - (a^2*b*Sin[x])/((a^2 + b^2)^2*(a*Cos[x] + b*Sin[x])), (a^3*b*x)/(a^2 + b^2)^3 - (a*b^3*x)/(a^2 + b^2)^3 + (a*b*(a^2 - b^2)*x)/(a^2 + b^2)^3 + (a*b*x)/(a^2 + b^2)^2 - (a^2*b)/((a^2 + b^2)^2*(b + a*Cot[x])) + (2*a^2*b^2*Log[b + a*Cot[x]])/(a^2 + b^2)^3 + (2*a^2*b^2*Log[Sin[x]])/(a^2 + b^2)^3 - (a^4*Log[a*Cos[x] + b*Sin[x]])/(a^2 + b^2)^3 + (a^2*b^2*Log[a*Cos[x] + b*Sin[x]])/(a^2 + b^2)^3 - (a*b*Cos[x]*Sin[x])/(a^2 + b^2)^2 - (a^2*Sin[x]^2)/(2*(a^2 + b^2)^2) + (b^2*Sin[x]^2)/(2*(a^2 + b^2)^2)}

{Cos[x]^2*Sin[x]^1/(a*Cos[x] + b*Sin[x])^2, x, 13, -((b*(-2*a^2 + b^2)*ArcTanh[(b*Cos[x] - a*Sin[x])/Sqrt[a^2 + b^2]])/(a^2 + b^2)^(5/2)) - ((a^2 - b^2)*Cos[x])/(a^2 + b^2)^2 + (2*a*b*Sin[x])/(a^2 + b^2)^2 + (a*b^2)/((a^2 + b^2)^2*(a*Cos[x] + b*Sin[x])), (2*a^2*b*ArcTanh[(b*Cos[x] - a*Sin[x])/Sqrt[a^2 + b^2]])/(a^2 + b^2)^(5/2) - (b^3*ArcTanh[(b*Cos[x] - a*Sin[x])/Sqrt[a^2 + b^2]])/(a^2 + b^2)^(5/2) - (a^2*Cos[x])/(a^2 + b^2)^2 + (b^2*Cos[x])/(a^2 + b^2)^2 + (2*a*b*Sin[x])/(a^2 + b^2)^2 + (a*b^2)/((a^2 + b^2)^2*(a*Cos[x] + b*Sin[x]))}
{Cos[x]^2*Sin[x]^2/(a*Cos[x] + b*Sin[x])^2, x, 17, ((a^4 - 6*a^2*b^2 + b^4)*x)/(2*(a^2 + b^2)^3) + (2*a*b*(a^2 - b^2)*Log[a*Cos[x] + b*Sin[x]])/(a^2 + b^2)^3 + ((-a^2 + b^2)*Cos[x]*Sin[x])/(2*(a^2 + b^2)^2) + (a*b*Sin[x]^2)/(a^2 + b^2)^2 + (a*b^2*Sin[x])/((a^2 + b^2)^2*(a*Cos[x] + b*Sin[x])), -((4*a^2*b^2*x)/(a^2 + b^2)^3) + (a^2*x)/(2*(a^2 + b^2)^2) + (b^2*x)/(2*(a^2 + b^2)^2) + (2*a^3*b*Log[a*Cos[x] + b*Sin[x]])/(a^2 + b^2)^3 - (2*a*b^3*Log[a*Cos[x] + b*Sin[x]])/(a^2 + b^2)^3 - (a^2*Cos[x]*Sin[x])/(2*(a^2 + b^2)^2) + (b^2*Cos[x]*Sin[x])/(2*(a^2 + b^2)^2) + (a*b*Sin[x]^2)/(a^2 + b^2)^2 + (a*b^2*Sin[x])/((a^2 + b^2)^2*(a*Cos[x] + b*Sin[x]))}
{Cos[x]^2*Sin[x]^3/(a*Cos[x] + b*Sin[x])^2, x, 30, (a^2*b*(2*a^2 - 3*b^2)*ArcTanh[(b*Cos[x] - a*Sin[x])/Sqrt[a^2 + b^2]])/(a^2 + b^2)^(7/2) - (a^2*(a^2 - 3*b^2)*Cos[x])/(a^2 + b^2)^3 + ((a^2 - b^2)*Cos[x]^3)/(3*(a^2 + b^2)^2) + (2*a*b*(a^2 - b^2)*Sin[x])/(a^2 + b^2)^3 + (2*a*b*Sin[x]^3)/(3*(a^2 + b^2)^2) + (a^3*b^2)/((a^2 + b^2)^3*(a*Cos[x] + b*Sin[x])), (2*a^4*b*ArcTanh[(b*Cos[x] - a*Sin[x])/Sqrt[a^2 + b^2]])/(a^2 + b^2)^(7/2) - (3*a^2*b^3*ArcTanh[(b*Cos[x] - a*Sin[x])/Sqrt[a^2 + b^2]])/(a^2 + b^2)^(7/2) + (4*a^2*b^2*Cos[x])/(a^2 + b^2)^3 - (a^2*Cos[x])/(a^2 + b^2)^2 + (a^2*Cos[x]^3)/(3*(a^2 + b^2)^2) - (b^2*Cos[x]^3)/(3*(a^2 + b^2)^2) + (2*a^3*b*Sin[x])/(a^2 + b^2)^3 - (2*a*b^3*Sin[x])/(a^2 + b^2)^3 + (2*a*b*Sin[x]^3)/(3*(a^2 + b^2)^2) + (a^3*b^2)/((a^2 + b^2)^3*(a*Cos[x] + b*Sin[x]))}

{Cos[x]^3*Sin[x]^1/(a*Cos[x] + b*Sin[x])^2, x, 16, -((a*b*(a^2 - 3*b^2)*x)/(a^2 + b^2)^3) - (b^2*(3*a^2 - b^2)*Log[a*Cos[x] + b*Sin[x]])/(a^2 + b^2)^3 + (a*b*Cos[x]*Sin[x])/(a^2 + b^2)^2 + ((a^2 - b^2)*Sin[x]^2)/(2*(a^2 + b^2)^2) + (a*b^2*Cos[x])/((a^2 + b^2)^2*(a*Cos[x] + b*Sin[x])), -((a^3*b*x)/(a^2 + b^2)^3) + (a*b^3*x)/(a^2 + b^2)^3 - (a*b*(a^2 - b^2)*x)/(a^2 + b^2)^3 + (a*b*x)/(a^2 + b^2)^2 + (b^2*Cos[x]^2)/(2*(a^2 + b^2)^2) - (2*a^2*b^2*Log[Cos[x]])/(a^2 + b^2)^3 - (a^2*b^2*Log[a*Cos[x] + b*Sin[x]])/(a^2 + b^2)^3 + (b^4*Log[a*Cos[x] + b*Sin[x]])/(a^2 + b^2)^3 - (2*a^2*b^2*Log[a + b*Tan[x]])/(a^2 + b^2)^3 + (a*b*Cos[x]*Sin[x])/(a^2 + b^2)^2 + (a^2*Sin[x]^2)/(2*(a^2 + b^2)^2) + (a*b^2)/((a^2 + b^2)^2*(a + b*Tan[x]))}
{Cos[x]^3*Sin[x]^2/(a*Cos[x] + b*Sin[x])^2, x, 30, -((a*b^2*(3*a^2 - 2*b^2)*ArcTanh[(b*Cos[x] - a*Sin[x])/Sqrt[a^2 + b^2]])/(a^2 + b^2)^(7/2)) + (2*a*b*(a^2 - b^2)*Cos[x])/(a^2 + b^2)^3 - (2*a*b*Cos[x]^3)/(3*(a^2 + b^2)^2) - (b^2*(3*a^2 - b^2)*Sin[x])/(a^2 + b^2)^3 + ((a^2 - b^2)*Sin[x]^3)/(3*(a^2 + b^2)^2) - (a^2*b^3)/((a^2 + b^2)^3*(a*Cos[x] + b*Sin[x])), -((3*a^3*b^2*ArcTanh[(b*Cos[x] - a*Sin[x])/Sqrt[a^2 + b^2]])/(a^2 + b^2)^(7/2)) + (2*a*b^4*ArcTanh[(b*Cos[x] - a*Sin[x])/Sqrt[a^2 + b^2]])/(a^2 + b^2)^(7/2) + (2*a^3*b*Cos[x])/(a^2 + b^2)^3 - (2*a*b^3*Cos[x])/(a^2 + b^2)^3 - (2*a*b*Cos[x]^3)/(3*(a^2 + b^2)^2) - (4*a^2*b^2*Sin[x])/(a^2 + b^2)^3 + (b^2*Sin[x])/(a^2 + b^2)^2 + (a^2*Sin[x]^3)/(3*(a^2 + b^2)^2) - (b^2*Sin[x]^3)/(3*(a^2 + b^2)^2) - (a^2*b^3)/((a^2 + b^2)^3*(a*Cos[x] + b*Sin[x]))}
{Cos[x]^3*Sin[x]^3/(a*Cos[x] + b*Sin[x])^2, x, 36, -((3*a*b*(a^4 - 6*a^2*b^2 + b^4)*x)/(4*(a^2 + b^2)^4)) - (b^2*Cos[x]^4)/(4*(a^2 + b^2)^2) - (3*a^2*b^2*(a^2 - b^2)*Log[a*Cos[x] + b*Sin[x]])/(a^2 + b^2)^4 + (a*b*(5*a^2 - 3*b^2)*Cos[x]*Sin[x])/(4*(a^2 + b^2)^3) - (a*b*Cos[x]^3*Sin[x])/(2*(a^2 + b^2)^2) - (2*a^2*b^2*Sin[x]^2)/(a^2 + b^2)^3 + (a^2*Sin[x]^4)/(4*(a^2 + b^2)^2) - (a^2*b^3*Sin[x])/((a^2 + b^2)^3*(a*Cos[x] + b*Sin[x])), (6*a^3*b^3*x)/(a^2 + b^2)^4 - (a^3*b*x)/(a^2 + b^2)^3 - (a*b^3*x)/(a^2 + b^2)^3 + (a*b*x)/(4*(a^2 + b^2)^2) - (b^2*Cos[x]^4)/(4*(a^2 + b^2)^2) - (3*a^4*b^2*Log[a*Cos[x] + b*Sin[x]])/(a^2 + b^2)^4 + (3*a^2*b^4*Log[a*Cos[x] + b*Sin[x]])/(a^2 + b^2)^4 + (a^3*b*Cos[x]*Sin[x])/(a^2 + b^2)^3 - (a*b^3*Cos[x]*Sin[x])/(a^2 + b^2)^3 + (a*b*Cos[x]*Sin[x])/(4*(a^2 + b^2)^2) - (a*b*Cos[x]^3*Sin[x])/(2*(a^2 + b^2)^2) - (2*a^2*b^2*Sin[x]^2)/(a^2 + b^2)^3 + (a^2*Sin[x]^4)/(4*(a^2 + b^2)^2) - (a^2*b^3*Sin[x])/((a^2 + b^2)^3*(a*Cos[x] + b*Sin[x]))}


{Tan[x]/(a*Sin[x] + b*Cos[x]), x, 5, ArcTanh[Sin[x]]/a + (b*ArcTanh[(a*Cos[x] - b*Sin[x])/Sqrt[a^2 + b^2]])/(a*Sqrt[a^2 + b^2])}


{Cot[x]/(a*Sin[x] + b*Cos[x]), x, 5, -(ArcTanh[Cos[x]]/b) + (a*ArcTanh[(a*Cos[x] - b*Sin[x])/Sqrt[a^2 + b^2]])/(b*Sqrt[a^2 + b^2])}
