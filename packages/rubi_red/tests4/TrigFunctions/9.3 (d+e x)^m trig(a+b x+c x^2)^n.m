(* ::Package:: *)

(* ::Title:: *)
(*Problems for integrands of the form (d+e x)^m trig(a+b x+c x^2)^n*)


(* ::Section:: *)
(*Integrands of the form (d+e x)^m Sin[a+b x+c x^2]^n*)


(* ::Subsection::Closed:: *)
(*Integrands of the form x^m Sin[a+b x+c x^2]^n*)


{x^2*Sin[a + b*x + c*x^2], x, 8, (b*Cos[a + b*x + c*x^2])/(4*c^2) - (x*Cos[a + b*x + c*x^2])/(2*c) + (Sqrt[Pi/2]*Cos[a - b^2/(4*c)]*FresnelC[(b + 2*c*x)/(Sqrt[c]*Sqrt[2*Pi])])/(2*c^(3/2)) + (b^2*Sqrt[Pi/2]*Cos[a - b^2/(4*c)]*FresnelS[(b + 2*c*x)/(Sqrt[c]*Sqrt[2*Pi])])/(4*c^(5/2)) + (b^2*Sqrt[Pi/2]*FresnelC[(b + 2*c*x)/(Sqrt[c]*Sqrt[2*Pi])]*Sin[a - b^2/(4*c)])/(4*c^(5/2)) - (Sqrt[Pi/2]*FresnelS[(b + 2*c*x)/(Sqrt[c]*Sqrt[2*Pi])]*Sin[a - b^2/(4*c)])/(2*c^(3/2))}
{x*Sin[a + b*x + c*x^2], x, 4, -(Cos[a + b*x + c*x^2]/(2*c)) - (b*Sqrt[Pi/2]*Cos[a - b^2/(4*c)]*FresnelS[(b + 2*c*x)/(Sqrt[c]*Sqrt[2*Pi])])/(2*c^(3/2)) - (b*Sqrt[Pi/2]*FresnelC[(b + 2*c*x)/(Sqrt[c]*Sqrt[2*Pi])]*Sin[a - b^2/(4*c)])/(2*c^(3/2))}
{Sin[a + b*x + c*x^2], x, 3, (Sqrt[Pi/2]*Cos[a - b^2/(4*c)]*FresnelS[(b + 2*c*x)/(Sqrt[c]*Sqrt[2*Pi])])/Sqrt[c] + (Sqrt[Pi/2]*FresnelC[(b + 2*c*x)/(Sqrt[c]*Sqrt[2*Pi])]*Sin[a - b^2/(4*c)])/Sqrt[c]}
{Sin[a + b*x + c*x^2]/x, x, 0, Int[Sin[a + b*x + c*x^2]/x, x]}
{Sin[a + b*x + c*x^2]/x^2 - b*Cos[a + b*x + c*x^2]/x, x, 5, Sqrt[c]*Sqrt[2*Pi]*Cos[a - b^2/(4*c)]*FresnelC[(b + 2*c*x)/(Sqrt[c]*Sqrt[2*Pi])] - Sqrt[c]*Sqrt[2*Pi]*FresnelS[(b + 2*c*x)/(Sqrt[c]*Sqrt[2*Pi])]*Sin[a - b^2/(4*c)] - Sin[a + b*x + c*x^2]/x}

{x^2*Sin[a + b*x - c*x^2], x, 8, (b*Cos[a + b*x - c*x^2])/(4*c^2) + (x*Cos[a + b*x - c*x^2])/(2*c) + (Sqrt[Pi/2]*Cos[a + b^2/(4*c)]*FresnelC[(b - 2*c*x)/(Sqrt[c]*Sqrt[2*Pi])])/(2*c^(3/2)) + (b^2*Sqrt[Pi/2]*Cos[a + b^2/(4*c)]*FresnelS[(b - 2*c*x)/(Sqrt[c]*Sqrt[2*Pi])])/(4*c^(5/2)) - (b^2*Sqrt[Pi/2]*FresnelC[(b - 2*c*x)/(Sqrt[c]*Sqrt[2*Pi])]*Sin[a + b^2/(4*c)])/(4*c^(5/2)) + (Sqrt[Pi/2]*FresnelS[(b - 2*c*x)/(Sqrt[c]*Sqrt[2*Pi])]*Sin[a + b^2/(4*c)])/(2*c^(3/2))}
{x*Sin[a + b*x - c*x^2], x, 4, Cos[a + b*x - c*x^2]/(2*c) + (b*Sqrt[Pi/2]*Cos[a + b^2/(4*c)]*FresnelS[(b - 2*c*x)/(Sqrt[c]*Sqrt[2*Pi])])/(2*c^(3/2)) - (b*Sqrt[Pi/2]*FresnelC[(b - 2*c*x)/(Sqrt[c]*Sqrt[2*Pi])]*Sin[a + b^2/(4*c)])/(2*c^(3/2))}
{Sin[a + b*x - c*x^2], x, 3, (Sqrt[Pi/2]*Cos[a + b^2/(4*c)]*FresnelS[(b - 2*c*x)/(Sqrt[c]*Sqrt[2*Pi])])/Sqrt[c] - (Sqrt[Pi/2]*FresnelC[(b - 2*c*x)/(Sqrt[c]*Sqrt[2*Pi])]*Sin[a + b^2/(4*c)])/Sqrt[c]}
{Sin[a + b*x - c*x^2]/x, x, 0, Int[Sin[a + b*x - c*x^2]/x, x]}
{Sin[a + b*x - c*x^2]/x^2 - b*Cos[a + b*x - c*x^2]/x, x, 5, Sqrt[c]*Sqrt[2*Pi]*Cos[a + b^2/(4*c)]*FresnelC[(b - 2*c*x)/(Sqrt[c]*Sqrt[2*Pi])] + Sqrt[c]*Sqrt[2*Pi]*FresnelS[(b - 2*c*x)/(Sqrt[c]*Sqrt[2*Pi])]*Sin[a + b^2/(4*c)] - Sin[a + b*x - c*x^2]/x}

{x^2*Sin[1/4 + x + x^2], x, 6, (1/4)*Cos[1/4 + x + x^2] - (1/2)*x*Cos[1/4 + x + x^2] + (1/2)*Sqrt[Pi/2]*FresnelC[(1 + 2*x)/Sqrt[2*Pi]] + (1/4)*Sqrt[Pi/2]*FresnelS[(1 + 2*x)/Sqrt[2*Pi]]}
{x*Sin[1/4 + x + x^2], x, 3, (-(1/2))*Cos[1/4 + x + x^2] - (1/2)*Sqrt[Pi/2]*FresnelS[(1 + 2*x)/Sqrt[2*Pi]]}
{Sin[1/4 + x + x^2], x, 2, Sqrt[Pi/2]*FresnelS[(1 + 2*x)/Sqrt[2*Pi]]}
{Sin[1/4 + x + x^2]/x, x, 0, Int[Sin[1/4 + x + x^2]/x, x]}
{Sin[1/4 + x + x^2]/x^2, x, 3, Sqrt[2*Pi]*FresnelC[(1 + 2*x)/Sqrt[2*Pi]] + Int[Cos[1/4 + x + x^2]/x, x] - Sin[1/4 + x + x^2]/x}


{x^2*Sin[a + b*x + c*x^2]^2, x, 10, x^3/6 - (b^2*Sqrt[Pi]*Cos[2*a - b^2/(2*c)]*FresnelC[(b + 2*c*x)/(Sqrt[c]*Sqrt[Pi])])/(16*c^(5/2)) + (Sqrt[Pi]*Cos[2*a - b^2/(2*c)]*FresnelS[(b + 2*c*x)/(Sqrt[c]*Sqrt[Pi])])/(16*c^(3/2)) + (Sqrt[Pi]*FresnelC[(b + 2*c*x)/(Sqrt[c]*Sqrt[Pi])]*Sin[2*a - b^2/(2*c)])/(16*c^(3/2)) + (b^2*Sqrt[Pi]*FresnelS[(b + 2*c*x)/(Sqrt[c]*Sqrt[Pi])]*Sin[2*a - b^2/(2*c)])/(16*c^(5/2)) + (b*Sin[2*a + 2*b*x + 2*c*x^2])/(16*c^2) - (x*Sin[2*a + 2*b*x + 2*c*x^2])/(8*c)}
{x*Sin[a + b*x + c*x^2]^2, x, 6, x^2/4 + (b*Sqrt[Pi]*Cos[2*a - b^2/(2*c)]*FresnelC[(b + 2*c*x)/(Sqrt[c]*Sqrt[Pi])])/(8*c^(3/2)) - (b*Sqrt[Pi]*FresnelS[(b + 2*c*x)/(Sqrt[c]*Sqrt[Pi])]*Sin[2*a - b^2/(2*c)])/(8*c^(3/2)) - Sin[2*a + 2*b*x + 2*c*x^2]/(8*c)}
{Sin[a + b*x + c*x^2]^2, x, 5, x/2 - (Sqrt[Pi]*Cos[2*a - b^2/(2*c)]*FresnelC[(b + 2*c*x)/(Sqrt[c]*Sqrt[Pi])])/(4*Sqrt[c]) + (Sqrt[Pi]*FresnelS[(b + 2*c*x)/(Sqrt[c]*Sqrt[Pi])]*Sin[2*a - b^2/(2*c)])/(4*Sqrt[c])}
{Sin[a + b*x + c*x^2]^2/x, x, 2, (-(1/2))*Int[Cos[2*a + 2*b*x + 2*c*x^2]/x, x] + Log[x]/2}

{x^2*Sin[a + b*x - c*x^2]^2, x, 10, x^3/6 + (b^2*Sqrt[Pi]*Cos[2*a + b^2/(2*c)]*FresnelC[(b - 2*c*x)/(Sqrt[c]*Sqrt[Pi])])/(16*c^(5/2)) - (Sqrt[Pi]*Cos[2*a + b^2/(2*c)]*FresnelS[(b - 2*c*x)/(Sqrt[c]*Sqrt[Pi])])/(16*c^(3/2)) + (Sqrt[Pi]*FresnelC[(b - 2*c*x)/(Sqrt[c]*Sqrt[Pi])]*Sin[2*a + b^2/(2*c)])/(16*c^(3/2)) + (b^2*Sqrt[Pi]*FresnelS[(b - 2*c*x)/(Sqrt[c]*Sqrt[Pi])]*Sin[2*a + b^2/(2*c)])/(16*c^(5/2)) + (b*Sin[2*a + 2*b*x - 2*c*x^2])/(16*c^2) + (x*Sin[2*a + 2*b*x - 2*c*x^2])/(8*c)}
{x*Sin[a + b*x - c*x^2]^2, x, 6, x^2/4 + (b*Sqrt[Pi]*Cos[2*a + b^2/(2*c)]*FresnelC[(b - 2*c*x)/(Sqrt[c]*Sqrt[Pi])])/(8*c^(3/2)) + (b*Sqrt[Pi]*FresnelS[(b - 2*c*x)/(Sqrt[c]*Sqrt[Pi])]*Sin[2*a + b^2/(2*c)])/(8*c^(3/2)) + Sin[2*a + 2*b*x - 2*c*x^2]/(8*c)}
{Sin[a + b*x - c*x^2]^2, x, 5, x/2 + (Sqrt[Pi]*Cos[2*a + b^2/(2*c)]*FresnelC[(b - 2*c*x)/(Sqrt[c]*Sqrt[Pi])])/(4*Sqrt[c]) + (Sqrt[Pi]*FresnelS[(b - 2*c*x)/(Sqrt[c]*Sqrt[Pi])]*Sin[2*a + b^2/(2*c)])/(4*Sqrt[c])}
{Sin[a + b*x - c*x^2]^2/x, x, 2, (-(1/2))*Int[Cos[2*a + 2*b*x - 2*c*x^2]/x, x] + Log[x]/2}

{x^2*Sin[1/4 + x + x^2]^2, x, 8, x^3/6 - (1/16)*Sqrt[Pi]*FresnelC[(1 + 2*x)/Sqrt[Pi]] + (1/16)*Sqrt[Pi]*FresnelS[(1 + 2*x)/Sqrt[Pi]] + (1/16)*Sin[1/2 + 2*x + 2*x^2] - (1/8)*x*Sin[1/2 + 2*x + 2*x^2]}
{x*Sin[1/4 + x + x^2]^2, x, 5, x^2/4 + (1/8)*Sqrt[Pi]*FresnelC[(1 + 2*x)/Sqrt[Pi]] - (1/8)*Sin[1/2 + 2*x + 2*x^2]}
{Sin[1/4 + x + x^2]^2, x, 4, x/2 - (1/4)*Sqrt[Pi]*FresnelC[(1 + 2*x)/Sqrt[Pi]]}
{Sin[1/4 + x + x^2]^2/x, x, 2, (-(1/2))*Int[Cos[1/2 + 2*x + 2*x^2]/x, x] + Log[x]/2}
{Sin[1/4 + x + x^2]^2/x^2, x, 5, -(1/(2*x)) + Cos[1/2 + 2*x + 2*x^2]/(2*x) + Sqrt[Pi]*FresnelS[(1 + 2*x)/Sqrt[Pi]] + Int[Sin[1/2 + 2*x + 2*x^2]/x, x]}


(* ::Subsection::Closed:: *)
(*Integrands of the form (d+e x)^m Sin[a+b x+c x^2]^n*)


{(d + e*x)^2*Sin[a + b*x + c*x^2], x, 8, -((e*(2*c*d - b*e)*Cos[a + b*x + c*x^2])/(4*c^2)) - (e*(d + e*x)*Cos[a + b*x + c*x^2])/(2*c) + (e^2*Sqrt[Pi/2]*Cos[a - b^2/(4*c)]*FresnelC[(b + 2*c*x)/(Sqrt[c]*Sqrt[2*Pi])])/(2*c^(3/2)) + ((2*c*d - b*e)^2*Sqrt[Pi/2]*Cos[a - b^2/(4*c)]*FresnelS[(b + 2*c*x)/(Sqrt[c]*Sqrt[2*Pi])])/(4*c^(5/2)) + ((2*c*d - b*e)^2*Sqrt[Pi/2]*FresnelC[(b + 2*c*x)/(Sqrt[c]*Sqrt[2*Pi])]*Sin[a - b^2/(4*c)])/(4*c^(5/2)) - (e^2*Sqrt[Pi/2]*FresnelS[(b + 2*c*x)/(Sqrt[c]*Sqrt[2*Pi])]*Sin[a - b^2/(4*c)])/(2*c^(3/2))}
{(d + e*x)^1*Sin[a + b*x + c*x^2], x, 4, -((e*Cos[a + b*x + c*x^2])/(2*c)) + ((2*c*d - b*e)*Sqrt[Pi/2]*Cos[a - b^2/(4*c)]*FresnelS[(b + 2*c*x)/(Sqrt[c]*Sqrt[2*Pi])])/(2*c^(3/2)) + ((2*c*d - b*e)*Sqrt[Pi/2]*FresnelC[(b + 2*c*x)/(Sqrt[c]*Sqrt[2*Pi])]*Sin[a - b^2/(4*c)])/(2*c^(3/2))}
{(d + e*x)^0*Sin[a + b*x + c*x^2], x, 3, (Sqrt[Pi/2]*Cos[a - b^2/(4*c)]*FresnelS[(b + 2*c*x)/(Sqrt[c]*Sqrt[2*Pi])])/Sqrt[c] + (Sqrt[Pi/2]*FresnelC[(b + 2*c*x)/(Sqrt[c]*Sqrt[2*Pi])]*Sin[a - b^2/(4*c)])/Sqrt[c]}
{Sin[a + b*x + c*x^2]/(d + e*x)^1, x, 0, Int[Sin[a + b*x + c*x^2]/(d + e*x), x]}


{(d + e*x)^2*Sin[a + b*x + c*x^2]^2, x, 10, (d + e*x)^3/(6*e) - ((2*c*d - b*e)^2*Sqrt[Pi]*Cos[2*a - b^2/(2*c)]*FresnelC[(b + 2*c*x)/(Sqrt[c]*Sqrt[Pi])])/(16*c^(5/2)) + (e^2*Sqrt[Pi]*Cos[2*a - b^2/(2*c)]*FresnelS[(b + 2*c*x)/(Sqrt[c]*Sqrt[Pi])])/(16*c^(3/2)) + (e^2*Sqrt[Pi]*FresnelC[(b + 2*c*x)/(Sqrt[c]*Sqrt[Pi])]*Sin[2*a - b^2/(2*c)])/(16*c^(3/2)) + ((2*c*d - b*e)^2*Sqrt[Pi]*FresnelS[(b + 2*c*x)/(Sqrt[c]*Sqrt[Pi])]*Sin[2*a - b^2/(2*c)])/(16*c^(5/2)) - (e*(2*c*d - b*e)*Sin[2*a + 2*b*x + 2*c*x^2])/(16*c^2) - (e*(d + e*x)*Sin[2*a + 2*b*x + 2*c*x^2])/(8*c)}
{(d + e*x)^1*Sin[a + b*x + c*x^2]^2, x, 6, (d + e*x)^2/(4*e) - ((2*c*d - b*e)*Sqrt[Pi]*Cos[2*a - b^2/(2*c)]*FresnelC[(b + 2*c*x)/(Sqrt[c]*Sqrt[Pi])])/(8*c^(3/2)) + ((2*c*d - b*e)*Sqrt[Pi]*FresnelS[(b + 2*c*x)/(Sqrt[c]*Sqrt[Pi])]*Sin[2*a - b^2/(2*c)])/(8*c^(3/2)) - (e*Sin[2*a + 2*b*x + 2*c*x^2])/(8*c)}
{(d + e*x)^0*Sin[a + b*x + c*x^2]^2, x, 5, x/2 - (Sqrt[Pi]*Cos[2*a - b^2/(2*c)]*FresnelC[(b + 2*c*x)/(Sqrt[c]*Sqrt[Pi])])/(4*Sqrt[c]) + (Sqrt[Pi]*FresnelS[(b + 2*c*x)/(Sqrt[c]*Sqrt[Pi])]*Sin[2*a - b^2/(2*c)])/(4*Sqrt[c])}
{Sin[a + b*x + c*x^2]^2/(d + e*x)^1, x, 2, (-(1/2))*Int[Cos[2*a + 2*b*x + 2*c*x^2]/(d + e*x), x] + Log[d + e*x]/(2*e)}


(* ::Section:: *)
(*Integrands of the form (d+e x)^m Cos[a+b x+c x^2]^n*)


(* ::Subsection::Closed:: *)
(*Integrands of the form x^m Cos[a+b x+c x^2]^n*)


{x^2*Cos[a + b*x + c*x^2], x, 8, (b^2*Sqrt[Pi/2]*Cos[a - b^2/(4*c)]*FresnelC[(b + 2*c*x)/(Sqrt[c]*Sqrt[2*Pi])])/(4*c^(5/2)) - (Sqrt[Pi/2]*Cos[a - b^2/(4*c)]*FresnelS[(b + 2*c*x)/(Sqrt[c]*Sqrt[2*Pi])])/(2*c^(3/2)) - (Sqrt[Pi/2]*FresnelC[(b + 2*c*x)/(Sqrt[c]*Sqrt[2*Pi])]*Sin[a - b^2/(4*c)])/(2*c^(3/2)) - (b^2*Sqrt[Pi/2]*FresnelS[(b + 2*c*x)/(Sqrt[c]*Sqrt[2*Pi])]*Sin[a - b^2/(4*c)])/(4*c^(5/2)) - (b*Sin[a + b*x + c*x^2])/(4*c^2) + (x*Sin[a + b*x + c*x^2])/(2*c)}
{x*Cos[a + b*x + c*x^2], x, 4, -((b*Sqrt[Pi/2]*Cos[a - b^2/(4*c)]*FresnelC[(b + 2*c*x)/(Sqrt[c]*Sqrt[2*Pi])])/(2*c^(3/2))) + (b*Sqrt[Pi/2]*FresnelS[(b + 2*c*x)/(Sqrt[c]*Sqrt[2*Pi])]*Sin[a - b^2/(4*c)])/(2*c^(3/2)) + Sin[a + b*x + c*x^2]/(2*c)}
{Cos[a + b*x + c*x^2], x, 3, (Sqrt[Pi/2]*Cos[a - b^2/(4*c)]*FresnelC[(b + 2*c*x)/(Sqrt[c]*Sqrt[2*Pi])])/Sqrt[c] - (Sqrt[Pi/2]*FresnelS[(b + 2*c*x)/(Sqrt[c]*Sqrt[2*Pi])]*Sin[a - b^2/(4*c)])/Sqrt[c]}
{Cos[a + b*x + c*x^2]/x, x, 0, Int[Cos[a + b*x + c*x^2]/x, x]}
{Cos[a + b*x + c*x^2]/x^2 + b*Sin[a + b*x + c*x^2]/x, x, 5, -(Cos[a + b*x + c*x^2]/x) - Sqrt[c]*Sqrt[2*Pi]*Cos[a - b^2/(4*c)]*FresnelS[(b + 2*c*x)/(Sqrt[c]*Sqrt[2*Pi])] - Sqrt[c]*Sqrt[2*Pi]*FresnelC[(b + 2*c*x)/(Sqrt[c]*Sqrt[2*Pi])]*Sin[a - b^2/(4*c)]}

{x^2*Cos[a + b*x - c*x^2], x, 8, -((b^2*Sqrt[Pi/2]*Cos[a + b^2/(4*c)]*FresnelC[(b - 2*c*x)/(Sqrt[c]*Sqrt[2*Pi])])/(4*c^(5/2))) + (Sqrt[Pi/2]*Cos[a + b^2/(4*c)]*FresnelS[(b - 2*c*x)/(Sqrt[c]*Sqrt[2*Pi])])/(2*c^(3/2)) - (Sqrt[Pi/2]*FresnelC[(b - 2*c*x)/(Sqrt[c]*Sqrt[2*Pi])]*Sin[a + b^2/(4*c)])/(2*c^(3/2)) - (b^2*Sqrt[Pi/2]*FresnelS[(b - 2*c*x)/(Sqrt[c]*Sqrt[2*Pi])]*Sin[a + b^2/(4*c)])/(4*c^(5/2)) - (b*Sin[a + b*x - c*x^2])/(4*c^2) - (x*Sin[a + b*x - c*x^2])/(2*c)}
{x*Cos[a + b*x - c*x^2], x, 4, -((b*Sqrt[Pi/2]*Cos[a + b^2/(4*c)]*FresnelC[(b - 2*c*x)/(Sqrt[c]*Sqrt[2*Pi])])/(2*c^(3/2))) - (b*Sqrt[Pi/2]*FresnelS[(b - 2*c*x)/(Sqrt[c]*Sqrt[2*Pi])]*Sin[a + b^2/(4*c)])/(2*c^(3/2)) - Sin[a + b*x - c*x^2]/(2*c)}
{Cos[a + b*x - c*x^2], x, 3, -((Sqrt[Pi/2]*Cos[a + b^2/(4*c)]*FresnelC[(b - 2*c*x)/(Sqrt[c]*Sqrt[2*Pi])])/Sqrt[c]) - (Sqrt[Pi/2]*FresnelS[(b - 2*c*x)/(Sqrt[c]*Sqrt[2*Pi])]*Sin[a + b^2/(4*c)])/Sqrt[c]}
{Cos[a + b*x - c*x^2]/x, x, 0, Int[Cos[a + b*x - c*x^2]/x, x]}
{Cos[a + b*x - c*x^2]/x^2 + b*Sin[a + b*x - c*x^2]/x, x, 5, -(Cos[a + b*x - c*x^2]/x) + Sqrt[c]*Sqrt[2*Pi]*Cos[a + b^2/(4*c)]*FresnelS[(b - 2*c*x)/(Sqrt[c]*Sqrt[2*Pi])] - Sqrt[c]*Sqrt[2*Pi]*FresnelC[(b - 2*c*x)/(Sqrt[c]*Sqrt[2*Pi])]*Sin[a + b^2/(4*c)]}

{x^2*Cos[1/4 + x + x^2], x, 6, (1/4)*Sqrt[Pi/2]*FresnelC[(1 + 2*x)/Sqrt[2*Pi]] - (1/2)*Sqrt[Pi/2]*FresnelS[(1 + 2*x)/Sqrt[2*Pi]] - (1/4)*Sin[1/4 + x + x^2] + (1/2)*x*Sin[1/4 + x + x^2]}
{x*Cos[1/4 + x + x^2], x, 3, (-(1/2))*Sqrt[Pi/2]*FresnelC[(1 + 2*x)/Sqrt[2*Pi]] + (1/2)*Sin[1/4 + x + x^2]}
{Cos[1/4 + x + x^2], x, 2, Sqrt[Pi/2]*FresnelC[(1 + 2*x)/Sqrt[2*Pi]]}
{Cos[1/4 + x + x^2]/x, x, 0, Int[Cos[1/4 + x + x^2]/x, x]}
{Cos[1/4 + x + x^2]/x^2, x, 3, -(Cos[1/4 + x + x^2]/x) - Sqrt[2*Pi]*FresnelS[(1 + 2*x)/Sqrt[2*Pi]] - Int[Sin[1/4 + x + x^2]/x, x]}


{x^2*Cos[a + b*x + c*x^2]^2, x, 10, x^3/6 + (b^2*Sqrt[Pi]*Cos[2*a - b^2/(2*c)]*FresnelC[(b + 2*c*x)/(Sqrt[c]*Sqrt[Pi])])/(16*c^(5/2)) - (Sqrt[Pi]*Cos[2*a - b^2/(2*c)]*FresnelS[(b + 2*c*x)/(Sqrt[c]*Sqrt[Pi])])/(16*c^(3/2)) - (Sqrt[Pi]*FresnelC[(b + 2*c*x)/(Sqrt[c]*Sqrt[Pi])]*Sin[2*a - b^2/(2*c)])/(16*c^(3/2)) - (b^2*Sqrt[Pi]*FresnelS[(b + 2*c*x)/(Sqrt[c]*Sqrt[Pi])]*Sin[2*a - b^2/(2*c)])/(16*c^(5/2)) - (b*Sin[2*a + 2*b*x + 2*c*x^2])/(16*c^2) + (x*Sin[2*a + 2*b*x + 2*c*x^2])/(8*c)}
{x*Cos[a + b*x + c*x^2]^2, x, 6, x^2/4 - (b*Sqrt[Pi]*Cos[2*a - b^2/(2*c)]*FresnelC[(b + 2*c*x)/(Sqrt[c]*Sqrt[Pi])])/(8*c^(3/2)) + (b*Sqrt[Pi]*FresnelS[(b + 2*c*x)/(Sqrt[c]*Sqrt[Pi])]*Sin[2*a - b^2/(2*c)])/(8*c^(3/2)) + Sin[2*a + 2*b*x + 2*c*x^2]/(8*c)}
{Cos[a + b*x + c*x^2]^2, x, 5, x/2 + (Sqrt[Pi]*Cos[2*a - b^2/(2*c)]*FresnelC[(b + 2*c*x)/(Sqrt[c]*Sqrt[Pi])])/(4*Sqrt[c]) - (Sqrt[Pi]*FresnelS[(b + 2*c*x)/(Sqrt[c]*Sqrt[Pi])]*Sin[2*a - b^2/(2*c)])/(4*Sqrt[c])}
{Cos[a + b*x + c*x^2]^2/x, x, 2, (1/2)*Int[Cos[2*a + 2*b*x + 2*c*x^2]/x, x] + Log[x]/2}

{x^2*Cos[a + b*x - c*x^2]^2, x, 10, x^3/6 - (b^2*Sqrt[Pi]*Cos[2*a + b^2/(2*c)]*FresnelC[(b - 2*c*x)/(Sqrt[c]*Sqrt[Pi])])/(16*c^(5/2)) + (Sqrt[Pi]*Cos[2*a + b^2/(2*c)]*FresnelS[(b - 2*c*x)/(Sqrt[c]*Sqrt[Pi])])/(16*c^(3/2)) - (Sqrt[Pi]*FresnelC[(b - 2*c*x)/(Sqrt[c]*Sqrt[Pi])]*Sin[2*a + b^2/(2*c)])/(16*c^(3/2)) - (b^2*Sqrt[Pi]*FresnelS[(b - 2*c*x)/(Sqrt[c]*Sqrt[Pi])]*Sin[2*a + b^2/(2*c)])/(16*c^(5/2)) - (b*Sin[2*a + 2*b*x - 2*c*x^2])/(16*c^2) - (x*Sin[2*a + 2*b*x - 2*c*x^2])/(8*c)}
{x*Cos[a + b*x - c*x^2]^2, x, 6, x^2/4 - (b*Sqrt[Pi]*Cos[2*a + b^2/(2*c)]*FresnelC[(b - 2*c*x)/(Sqrt[c]*Sqrt[Pi])])/(8*c^(3/2)) - (b*Sqrt[Pi]*FresnelS[(b - 2*c*x)/(Sqrt[c]*Sqrt[Pi])]*Sin[2*a + b^2/(2*c)])/(8*c^(3/2)) - Sin[2*a + 2*b*x - 2*c*x^2]/(8*c)}
{Cos[a + b*x - c*x^2]^2, x, 5, x/2 - (Sqrt[Pi]*Cos[2*a + b^2/(2*c)]*FresnelC[(b - 2*c*x)/(Sqrt[c]*Sqrt[Pi])])/(4*Sqrt[c]) - (Sqrt[Pi]*FresnelS[(b - 2*c*x)/(Sqrt[c]*Sqrt[Pi])]*Sin[2*a + b^2/(2*c)])/(4*Sqrt[c])}
{Cos[a + b*x - c*x^2]^2/x, x, 2, (1/2)*Int[Cos[2*a + 2*b*x - 2*c*x^2]/x, x] + Log[x]/2}

{x^2*Cos[1/4 + x + x^2]^2, x, 8, x^3/6 + (1/16)*Sqrt[Pi]*FresnelC[(1 + 2*x)/Sqrt[Pi]] - (1/16)*Sqrt[Pi]*FresnelS[(1 + 2*x)/Sqrt[Pi]] - (1/16)*Sin[1/2 + 2*x + 2*x^2] + (1/8)*x*Sin[1/2 + 2*x + 2*x^2]}
{x*Cos[1/4 + x + x^2]^2, x, 5, x^2/4 - (1/8)*Sqrt[Pi]*FresnelC[(1 + 2*x)/Sqrt[Pi]] + (1/8)*Sin[1/2 + 2*x + 2*x^2]}
{Cos[1/4 + x + x^2]^2, x, 4, x/2 + (1/4)*Sqrt[Pi]*FresnelC[(1 + 2*x)/Sqrt[Pi]]}
{Cos[1/4 + x + x^2]^2/x, x, 2, (1/2)*Int[Cos[1/2 + 2*x + 2*x^2]/x, x] + Log[x]/2}
{Cos[1/4 + x + x^2]^2/x^2, x, 5, -(1/(2*x)) - Cos[1/2 + 2*x + 2*x^2]/(2*x) - Sqrt[Pi]*FresnelS[(1 + 2*x)/Sqrt[Pi]] - Int[Sin[1/2 + 2*x + 2*x^2]/x, x]}


(* ::Subsection::Closed:: *)
(*Integrands of the form (d+e x)^m Cos[a+b x+c x^2]^n*)


{(d + e*x)^2*Cos[a + b*x + c*x^2], x, 8, ((2*c*d - b*e)^2*Sqrt[Pi/2]*Cos[a - b^2/(4*c)]*FresnelC[(b + 2*c*x)/(Sqrt[c]*Sqrt[2*Pi])])/(4*c^(5/2)) - (e^2*Sqrt[Pi/2]*Cos[a - b^2/(4*c)]*FresnelS[(b + 2*c*x)/(Sqrt[c]*Sqrt[2*Pi])])/(2*c^(3/2)) - (e^2*Sqrt[Pi/2]*FresnelC[(b + 2*c*x)/(Sqrt[c]*Sqrt[2*Pi])]*Sin[a - b^2/(4*c)])/(2*c^(3/2)) - ((2*c*d - b*e)^2*Sqrt[Pi/2]*FresnelS[(b + 2*c*x)/(Sqrt[c]*Sqrt[2*Pi])]*Sin[a - b^2/(4*c)])/(4*c^(5/2)) + (e*(2*c*d - b*e)*Sin[a + b*x + c*x^2])/(4*c^2) + (e*(d + e*x)*Sin[a + b*x + c*x^2])/(2*c)}
{(d + e*x)*Cos[a + b*x + c*x^2], x, 4, ((2*c*d - b*e)*Sqrt[Pi/2]*Cos[a - b^2/(4*c)]*FresnelC[(b + 2*c*x)/(Sqrt[c]*Sqrt[2*Pi])])/(2*c^(3/2)) - ((2*c*d - b*e)*Sqrt[Pi/2]*FresnelS[(b + 2*c*x)/(Sqrt[c]*Sqrt[2*Pi])]*Sin[a - b^2/(4*c)])/(2*c^(3/2)) + (e*Sin[a + b*x + c*x^2])/(2*c)}
{Cos[a + b*x + c*x^2]/(d + e*x), x, 0, Int[Cos[a + b*x + c*x^2]/(d + e*x), x]}


{(d + e*x)^2*Cos[a + b*x + c*x^2]^2, x, 10, (d + e*x)^3/(6*e) + ((2*c*d - b*e)^2*Sqrt[Pi]*Cos[2*a - b^2/(2*c)]*FresnelC[(b + 2*c*x)/(Sqrt[c]*Sqrt[Pi])])/(16*c^(5/2)) - (e^2*Sqrt[Pi]*Cos[2*a - b^2/(2*c)]*FresnelS[(b + 2*c*x)/(Sqrt[c]*Sqrt[Pi])])/(16*c^(3/2)) - (e^2*Sqrt[Pi]*FresnelC[(b + 2*c*x)/(Sqrt[c]*Sqrt[Pi])]*Sin[2*a - b^2/(2*c)])/(16*c^(3/2)) - ((2*c*d - b*e)^2*Sqrt[Pi]*FresnelS[(b + 2*c*x)/(Sqrt[c]*Sqrt[Pi])]*Sin[2*a - b^2/(2*c)])/(16*c^(5/2)) + (e*(2*c*d - b*e)*Sin[2*a + 2*b*x + 2*c*x^2])/(16*c^2) + (e*(d + e*x)*Sin[2*a + 2*b*x + 2*c*x^2])/(8*c)}
{(d + e*x)*Cos[a + b*x + c*x^2]^2, x, 6, (d + e*x)^2/(4*e) + ((2*c*d - b*e)*Sqrt[Pi]*Cos[2*a - b^2/(2*c)]*FresnelC[(b + 2*c*x)/(Sqrt[c]*Sqrt[Pi])])/(8*c^(3/2)) - ((2*c*d - b*e)*Sqrt[Pi]*FresnelS[(b + 2*c*x)/(Sqrt[c]*Sqrt[Pi])]*Sin[2*a - b^2/(2*c)])/(8*c^(3/2)) + (e*Sin[2*a + 2*b*x + 2*c*x^2])/(8*c)}
{Cos[a + b*x + c*x^2]^2/(d + e*x), x, 2, (1/2)*Int[Cos[2*a + 2*b*x + 2*c*x^2]/(d + e*x), x] + Log[d + e*x]/(2*e)}
