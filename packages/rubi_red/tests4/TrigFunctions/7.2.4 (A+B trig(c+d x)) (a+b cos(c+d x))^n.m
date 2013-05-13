(* ::Package:: *)

(* ::Title:: *)
(*Problems for integrands of the form (A+B trig(c+d x)) (a+b cos(a+b x))^n*)


(* ::Section::Closed:: *)
(*Integrands of the form (A+B Sin[c+d x]) (a+b Cos[c+d x])^n*)


(* Integrands of the form (A+B*Sin[x])*(a+b*Cos[x])^n where n is an integer *)
{(A + B*Sin[x])/(a + b*Cos[x]), x, 5, (2*A*ArcTan[(Sqrt[a^2 - b^2]*Tan[x/2])/(a + b)])/Sqrt[a^2 - b^2] - (B*Log[a + b*Cos[x]])/b}

{(A + B*Sin[x])/(1 + Cos[x]), x, 5, (-B)*Log[1 + Cos[x]] + (A*Sin[x])/(1 + Cos[x])}
{(A + B*Sin[x])/(1 - Cos[x]), x, 5, B*Log[1 - Cos[x]] - (A*Sin[x])/(1 - Cos[x])}


(* ::Section::Closed:: *)
(*Integrands of the form (A+B Tan[c+d x]) (a+b Cos[c+d x])^n*)


{(A + B*Tan[x])/(a + b*Cos[x]), x, 6, (2*A*ArcTan[(Sqrt[a^2 - b^2]*Tan[x/2])/(a + b)])/Sqrt[a^2 - b^2] - (B*Log[Cos[x]])/a + (B*Log[a + b*Cos[x]])/a}


(* ::Section::Closed:: *)
(*Integrands of the form (A+B Cot[c+d x]) (a+b Cos[c+d x])^n*)


{(A + B*Cot[x])/(a + b*Cos[x]), x, 9, (2*A*ArcTan[(Sqrt[a^2 - b^2]*Tan[x/2])/(a + b)])/Sqrt[a^2 - b^2] + (B*Log[1 - Cos[x]])/(2*(a + b)) + (B*Log[1 + Cos[x]])/(2*(a - b)) - (a*B*Log[a + b*Cos[x]])/(a^2 - b^2)}


(* ::Section:: *)
(*Integrands of the form (A+B Sec[c+d x]) (a+b Cos[c+d x])^n*)


(* ::Section::Closed:: *)
(*Integrands of the form (A+B Csc[c+d x]) (a+b Cos[c+d x])^n*)


{(A + B*Csc[x])/(a + b*Cos[x]), x, 9, (2*A*ArcTan[(Sqrt[a^2 - b^2]*Tan[x/2])/(a + b)])/Sqrt[a^2 - b^2] + (B*Log[1 - Cos[x]])/(2*(a + b)) - (B*Log[1 + Cos[x]])/(2*(a - b)) + (b*B*Log[a + b*Cos[x]])/(a^2 - b^2)}


(* ::Title:: *)
(*Problems for integrands of the form (A+B Cos[c+d x]+C Sin[c+d x]^2) (a+b cos(a+b x))^n*)


(* ::Section::Closed:: *)
(*Integrands of the form (A+B Cos[c+d x]+C Sin[c+d x]^2) (a+b Cos[c+d x])^n*)


{(A + B*Cos[d + e*x] + C*Sin[d + e*x])/(a + b*Cos[d + e*x]), x, 6, (B*x)/b + (2*(A*b - a*B)*ArcTan[(Sqrt[a^2 - b^2]*Tan[(1/2)*(d + e*x)])/(a + b)])/(b*Sqrt[a^2 - b^2]*e) - (C*Log[a + b*Cos[d + e*x]])/(b*e)}
{(A + B*Cos[d + e*x] + C*Sin[d + e*x])/(a + b*Cos[d + e*x])^2, x, 7, (2*(a*A - b*B)*ArcTan[(Sqrt[a^2 - b^2]*Tan[(1/2)*(d + e*x)])/(a + b)])/((a^2 - b^2)^(3/2)*e) + C/(b*e*(a + b*Cos[d + e*x])) - ((A*b - a*B)*Sin[d + e*x])/((a^2 - b^2)*e*(a + b*Cos[d + e*x]))}
{(A + B*Cos[d + e*x] + C*Sin[d + e*x])/(a + b*Cos[d + e*x])^3, x, 8, ((2*a^2*A + A*b^2 - 3*a*b*B)*ArcTan[(Sqrt[a^2 - b^2]*Tan[(1/2)*(d + e*x)])/(a + b)])/((a^2 - b^2)^(5/2)*e) + C/(2*b*e*(a + b*Cos[d + e*x])^2) - ((A*b - a*B)*Sin[d + e*x])/(2*(a^2 - b^2)*e*(a + b*Cos[d + e*x])^2) - ((3*a*A*b - a^2*B - 2*b^2*B)*Sin[d + e*x])/(2*(a^2 - b^2)^2*e*(a + b*Cos[d + e*x]))}
{(A + B*Cos[d + e*x] + C*Sin[d + e*x])/(a + b*Cos[d + e*x])^4, x, 9, ((2*a^3*A + 3*a*A*b^2 - 4*a^2*b*B - b^3*B)*ArcTan[(Sqrt[a^2 - b^2]*Tan[(1/2)*(d + e*x)])/(a + b)])/((a^2 - b^2)^(7/2)*e) + C/(3*b*e*(a + b*Cos[d + e*x])^3) - ((A*b - a*B)*Sin[d + e*x])/(3*(a^2 - b^2)*e*(a + b*Cos[d + e*x])^3) - ((5*a*A*b - 2*a^2*B - 3*b^2*B)*Sin[d + e*x])/(6*(a^2 - b^2)^2*e*(a + b*Cos[d + e*x])^2) - ((11*a^2*A*b + 4*A*b^3 - 2*a^3*B - 13*a*b^2*B)*Sin[d + e*x])/(6*(a^2 - b^2)^3*e*(a + b*Cos[d + e*x]))}
