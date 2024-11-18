(* ::Package:: *)

(* ::Title:: *)
(*Integration problems of the form *)
(*Sin[c+d x]^m (A+B Sin[c+d x]+C Sin[c+d x]^2) (a+b Sin[c+d x])^n when a^2=b^2*)


(* ::Section:: *)
(*Sin[c+d x]^m (a+a Sin[c+d x])^n*)


(* ::Subsection::Closed:: *)
(*Integrands of the form Sin[c+d x]^m (a+a Sin[c+d x])^n*)


{Sin[x]^4/(a + a*Sin[x]), x, 4, -((3*x)/(2*a)) - (8*Cos[x])/(3*a) + (3*Cos[x]*Sin[x])/(2*a) - (4*Cos[x]*Sin[x]^2)/(3*a) + (Cos[x]*Sin[x]^3)/(a + a*Sin[x])}
{Sin[x]^3/(a + a*Sin[x]), x, 3, (3*x)/(2*a) + (2*Cos[x])/a - (3*Cos[x]*Sin[x])/(2*a) + (Cos[x]*Sin[x]^2)/(a + a*Sin[x])}
{Sin[x]^2/(a + a*Sin[x]), x, 4, -(x/a) - Cos[x]/a - Cos[x]/(a*(1 + Sin[x]))}
{Sin[x]^1/(a + a*Sin[x]), x, 2, x/a + Cos[x]/(a + a*Sin[x])}
{Csc[x]^1/(a + a*Sin[x]), x, 3, -(ArcTanh[Cos[x]]/a) + Cos[x]/(a + a*Sin[x])}
{Csc[x]^2/(a + a*Sin[x]), x, 4, ArcTanh[Cos[x]]/a - (2*Cot[x])/a + Cot[x]/(a + a*Sin[x])}
{Csc[x]^3/(a + a*Sin[x]), x, 5, -((3*ArcTanh[Cos[x]])/(2*a)) + (2*Cot[x])/a - (3*Cot[x]*Csc[x])/(2*a) + (Cot[x]*Csc[x])/(a + a*Sin[x])}
{Csc[x]^4/(a + a*Sin[x]), x, 6, (3*ArcTanh[Cos[x]])/(2*a) - (8*Cot[x])/(3*a) + (3*Cot[x]*Csc[x])/(2*a) - (4*Cot[x]*Csc[x]^2)/(3*a) + (Cot[x]*Csc[x]^2)/(a + a*Sin[x])}


{Sin[x]^4/(a + a*Sin[x])^2, x, 4, (7*x)/(2*a^2) + (16*Cos[x])/(3*a^2) - (7*Cos[x]*Sin[x])/(2*a^2) + (Cos[x]*Sin[x]^3)/(3*(a + a*Sin[x])^2) + (8*Cos[x]*Sin[x]^2)/(3*a*(a + a*Sin[x]))}
{Sin[x]^3/(a + a*Sin[x])^2, x, 4, -((2*x)/a^2) - (4*Cos[x])/(3*a^2) + (Cos[x]*Sin[x]^2)/(3*(a + a*Sin[x])^2) - (2*Cos[x])/(a*(a + a*Sin[x]))}
{Sin[x]^2/(a + a*Sin[x])^2, x, 3, x/a^2 - Cos[x]/(3*(a + a*Sin[x])^2) + (5*Cos[x])/(3*a*(a + a*Sin[x]))}
{Sin[x]^1/(a + a*Sin[x])^2, x, 2, Cos[x]/(3*(a + a*Sin[x])^2) - (2*Cos[x])/(3*a*(a + a*Sin[x]))}
{Csc[x]^1/(a + a*Sin[x])^2, x, 3, -(ArcTanh[Cos[x]]/a^2) + Cos[x]/(3*(a + a*Sin[x])^2) + (4*Cos[x])/(3*a*(a + a*Sin[x]))}
{Csc[x]^2/(a + a*Sin[x])^2, x, 5, (2*ArcTanh[Cos[x]])/a^2 - (10*Cot[x])/(3*a^2) + Cot[x]/(3*(a + a*Sin[x])^2) + (2*Cot[x])/(a*(a + a*Sin[x]))}
{Csc[x]^3/(a + a*Sin[x])^2, x, 6, -((7*ArcTanh[Cos[x]])/(2*a^2)) + (16*Cot[x])/(3*a^2) - (7*Cot[x]*Csc[x])/(2*a^2) + (Cot[x]*Csc[x])/(3*(a + a*Sin[x])^2) + (8*Cot[x]*Csc[x])/(3*a*(a + a*Sin[x]))}
{Csc[x]^4/(a + a*Sin[x])^2, x, 7, (5*ArcTanh[Cos[x]])/a^2 - (4*Cot[x])/a^2 - Cot[x]^3/(3*a^2) + (Cot[x]*Csc[x])/a^2 - Cos[x]/(3*(a + a*Sin[x])^2) - (13*Cos[x])/(3*a*(a + a*Sin[x])), (5*ArcTanh[Cos[x]])/a^2 - (8*Cot[x])/a^2 + (5*Cot[x]*Csc[x])/a^2 - (4*Cot[x]*Csc[x]^2)/a^2 + (Cot[x]*Csc[x]^2)/(3*(a + a*Sin[x])^2) + (10*Cot[x]*Csc[x]^2)/(3*a*(a + a*Sin[x]))}


{Sin[x]^4/(a + a*Sin[x])^3, x, 5, -((3*x)/a^3) - (9*Cos[x])/(5*a^3) + (Cos[x]*Sin[x]^3)/(5*(a + a*Sin[x])^3) + (3*Cos[x]*Sin[x]^2)/(5*a*(a + a*Sin[x])^2) - (3*Cos[x])/(a^2*(a + a*Sin[x]))}
{Sin[x]^3/(a + a*Sin[x])^3, x, 4, x/a^3 + (Cos[x]*Sin[x]^2)/(5*(a + a*Sin[x])^3) + (7*Cos[x]*Sin[x])/(15*a*(a + a*Sin[x])^2) + (22*Cos[x])/(15*a^2*(a + a*Sin[x]))}
{Sin[x]^2/(a + a*Sin[x])^3, x, 3, -(Cos[x]/(5*(a + a*Sin[x])^3)) + (8*Cos[x])/(15*a*(a + a*Sin[x])^2) - (7*Cos[x])/(15*a^2*(a + a*Sin[x]))}
{Sin[x]^1/(a + a*Sin[x])^3, x, 3, Cos[x]/(5*(a + a*Sin[x])^3) - Cos[x]/(5*a*(a + a*Sin[x])^2) - Cos[x]/(5*a^2*(a + a*Sin[x]))}
{Csc[x]^1/(a + a*Sin[x])^3, x, 4, -(ArcTanh[Cos[x]]/a^3) + Cos[x]/(5*(a + a*Sin[x])^3) + (7*Cos[x])/(15*a*(a + a*Sin[x])^2) + (22*Cos[x])/(15*a^2*(a + a*Sin[x]))}
{Csc[x]^2/(a + a*Sin[x])^3, x, 6, (3*ArcTanh[Cos[x]])/a^3 - (24*Cot[x])/(5*a^3) + Cot[x]/(5*(a + a*Sin[x])^3) + (3*Cot[x])/(5*a*(a + a*Sin[x])^2) + (3*Cot[x])/(a^2*(a + a*Sin[x]))}
{Csc[x]^3/(a + a*Sin[x])^3, x, 7, -((13*ArcTanh[Cos[x]])/(2*a^3)) + (152*Cot[x])/(15*a^3) - (13*Cot[x]*Csc[x])/(2*a^3) + (Cot[x]*Csc[x])/(5*(a + a*Sin[x])^3) + (11*Cot[x]*Csc[x])/(15*a*(a + a*Sin[x])^2) + (76*Cot[x]*Csc[x])/(15*a^2*(a + a*Sin[x]))}
{Csc[x]^4/(a + a*Sin[x])^3, x, 8, (23*ArcTanh[Cos[x]])/(2*a^3) - (272*Cot[x])/(15*a^3) + (23*Cot[x]*Csc[x])/(2*a^3) - (136*Cot[x]*Csc[x]^2)/(15*a^3) + (Cot[x]*Csc[x]^2)/(5*(a + a*Sin[x])^3) + (13*Cot[x]*Csc[x]^2)/(15*a*(a + a*Sin[x])^2) + (23*Cot[x]*Csc[x]^2)/(3*a^2*(a + a*Sin[x]))}


{1/(1 + Sin[c + d*x]), x, 1, -(Cos[c + d*x]/(d*(1 + Sin[c + d*x])))}
{1/(1 + Sin[c + d*x])^2, x, 2, -(Cos[c + d*x]/(3*d*(1 + Sin[c + d*x])^2)) - Cos[c + d*x]/(3*d*(1 + Sin[c + d*x]))}
{1/(1 + Sin[c + d*x])^3, x, 3, -(Cos[c + d*x]/(5*d*(1 + Sin[c + d*x])^3)) - (2*Cos[c + d*x])/(15*d*(1 + Sin[c + d*x])^2) - (2*Cos[c + d*x])/(15*d*(1 + Sin[c + d*x]))}
{1/(1 + Sin[c + d*x])^4, x, 4, -(Cos[c + d*x]/(7*d*(1 + Sin[c + d*x])^4)) - (3*Cos[c + d*x])/(35*d*(1 + Sin[c + d*x])^3) - (2*Cos[c + d*x])/(35*d*(1 + Sin[c + d*x])^2) - (2*Cos[c + d*x])/(35*d*(1 + Sin[c + d*x]))}

{1/(1 - Sin[c + d*x]), x, 1, -(Cos[c + d*x]/(d*(-1 + Sin[c + d*x])))}
{1/(1 - Sin[c + d*x])^2, x, 2, Cos[c + d*x]/(3*d*(1 - Sin[c + d*x])^2) - Cos[c + d*x]/(3*d*(-1 + Sin[c + d*x]))}
{1/(1 - Sin[c + d*x])^3, x, 3, Cos[c + d*x]/(5*d*(1 - Sin[c + d*x])^3) + (2*Cos[c + d*x])/(15*d*(1 - Sin[c + d*x])^2) - (2*Cos[c + d*x])/(15*d*(-1 + Sin[c + d*x]))}
{1/(1 - Sin[c + d*x])^4, x, 4, Cos[c + d*x]/(7*d*(1 - Sin[c + d*x])^4) + (3*Cos[c + d*x])/(35*d*(1 - Sin[c + d*x])^3) + (2*Cos[c + d*x])/(35*d*(1 - Sin[c + d*x])^2) - (2*Cos[c + d*x])/(35*d*(-1 + Sin[c + d*x]))}


(* ::Subsection::Closed:: *)
(*Integrands of the form Sin[c+d x]^m (a+a Sin[c+d x])^(n/2)*)


{Sin[x]^2*Sqrt[a + a*Sin[x]], x, 3, -((14*a*Cos[x])/(15*Sqrt[a + a*Sin[x]])) + (4/15)*Cos[x]*Sqrt[a + a*Sin[x]] - (2*Cos[x]*(a + a*Sin[x])^(3/2))/(5*a)}
{Sin[x]^1*Sqrt[a + a*Sin[x]], x, 2, -((2*a*Cos[x])/(3*Sqrt[a + a*Sin[x]])) - (2/3)*Cos[x]*Sqrt[a + a*Sin[x]]}


{Sin[x]^2/Sqrt[a + a*Sin[x]], x, 3, -((2*ArcTanh[Sin[Pi/4 - x/2]]*Cos[Pi/4 - x/2])/Sqrt[a + a*Sin[x]]) + (4*Cos[x])/(3*Sqrt[a + a*Sin[x]]) - (2*Cos[x]*Sqrt[a + a*Sin[x]])/(3*a)}
{Sin[x]^1/Sqrt[a + a*Sin[x]], x, 2, (2*ArcTanh[Sin[Pi/4 - x/2]]*Cos[Pi/4 - x/2])/Sqrt[a + a*Sin[x]] - (2*Cos[x])/Sqrt[a + a*Sin[x]]}


{(a + a*Sin[c + d*x])^(5/2), x, 3, -((64*a^3*Cos[c + d*x])/(15*d*Sqrt[a + a*Sin[c + d*x]])) - (16*a^2*Cos[c + d*x]*Sqrt[a + a*Sin[c + d*x]])/(15*d) - (2*a*Cos[c + d*x]*(a + a*Sin[c + d*x])^(3/2))/(5*d)}
{(a + a*Sin[c + d*x])^(3/2), x, 2, -((8*a^2*Cos[c + d*x])/(3*d*Sqrt[a + a*Sin[c + d*x]])) - (2*a*Cos[c + d*x]*Sqrt[a + a*Sin[c + d*x]])/(3*d)}
{(a + a*Sin[c + d*x])^(1/2), x, 1, -((2*a*Cos[c + d*x])/(d*Sqrt[a + a*Sin[c + d*x]]))}
{1/(a + a*Sin[c + d*x])^(1/2), x, 1, -((2*ArcTanh[Sin[Pi/4 + (1/2)*(-c - d*x)]]*Cos[Pi/4 + (1/2)*(-c - d*x)])/(d*Sqrt[a + a*Sin[c + d*x]]))}
{1/(a + a*Sin[c + d*x])^(3/2), x, 2, -(Cos[c + d*x]/(2*d*(a + a*Sin[c + d*x])^(3/2))) - (ArcTanh[Sin[Pi/4 + (1/2)*(-c - d*x)]]*Cos[Pi/4 + (1/2)*(-c - d*x)])/(2*a*d*Sqrt[a + a*Sin[c + d*x]])}
{1/(a + a*Sin[c + d*x])^(5/2), x, 3, -(Cos[c + d*x]/(4*d*(a + a*Sin[c + d*x])^(5/2))) - (3*Cos[c + d*x])/(16*a*d*(a + a*Sin[c + d*x])^(3/2)) - (3*ArcTanh[Sin[Pi/4 + (1/2)*(-c - d*x)]]*Cos[Pi/4 + (1/2)*(-c - d*x)])/(16*a^2*d*Sqrt[a + a*Sin[c + d*x]])}

{(a - a*Sin[c + d*x])^(5/2), x, 3, (64*a^3*Cos[c + d*x])/(15*d*Sqrt[a - a*Sin[c + d*x]]) + (16*a^2*Cos[c + d*x]*Sqrt[a - a*Sin[c + d*x]])/(15*d) + (2*a*Cos[c + d*x]*(a - a*Sin[c + d*x])^(3/2))/(5*d)}
{(a - a*Sin[c + d*x])^(3/2), x, 2, (8*a^2*Cos[c + d*x])/(3*d*Sqrt[a - a*Sin[c + d*x]]) + (2*a*Cos[c + d*x]*Sqrt[a - a*Sin[c + d*x]])/(3*d)}
{(a - a*Sin[c + d*x])^(1/2), x, 1, (2*a*Cos[c + d*x])/(d*Sqrt[a - a*Sin[c + d*x]])}
{1/(a - a*Sin[c + d*x])^(1/2), x, 1, (2*ArcTanh[Sin[Pi/4 + (1/2)*(c + d*x)]]*Cos[Pi/4 + (1/2)*(c + d*x)])/(d*Sqrt[a - a*Sin[c + d*x]])}
{1/(a - a*Sin[c + d*x])^(3/2), x, 2, Cos[c + d*x]/(2*d*(a - a*Sin[c + d*x])^(3/2)) + (ArcTanh[Sin[Pi/4 + (1/2)*(c + d*x)]]*Cos[Pi/4 + (1/2)*(c + d*x)])/(2*a*d*Sqrt[a - a*Sin[c + d*x]])}
{1/(a - a*Sin[c + d*x])^(5/2), x, 3, Cos[c + d*x]/(4*d*(a - a*Sin[c + d*x])^(5/2)) + (3*Cos[c + d*x])/(16*a*d*(a - a*Sin[c + d*x])^(3/2)) + (3*ArcTanh[Sin[Pi/4 + (1/2)*(c + d*x)]]*Cos[Pi/4 + (1/2)*(c + d*x)])/(16*a^2*d*Sqrt[a - a*Sin[c + d*x]])}


(* Used to hang Rubi *)
{(a + a*Sin[c + d*x])^(1/3)/x, x, 0, Int[(a + a*Sin[c + d*x])^(1/3)/x, x]}


(* ::Subsection::Closed:: *)
(*Integrands of the form Sin[c+d x]^(m/2) (a+a Sin[c+d x])^(n/2)*)


{1/(Sqrt[1 + Sin[x]]*Sqrt[Sin[x]]), x, 1, (-Sqrt[2])*ArcSin[Tan[Pi/4 - x/2]]}
{1/(Sqrt[a + a*Sin[x]]*Sqrt[Sin[x]]), x, 1, -((Sqrt[2]*ArcTan[(Sqrt[a]*Cos[x])/(Sqrt[2]*Sqrt[Sin[x]]*Sqrt[a + a*Sin[x]])])/Sqrt[a])}

{1/(Sqrt[1 - Sin[x]]*Sqrt[Sin[x]]), x, 1, Sqrt[2]*ArcTanh[Cos[x]/(Sqrt[2]*Sqrt[1 - Sin[x]]*Sqrt[Sin[x]])]}
{1/(Sqrt[a - a*Sin[x]]*Sqrt[Sin[x]]), x, 1, (Sqrt[2]*ArcTan[(Sqrt[-a]*Cos[x])/(Sqrt[2]*Sqrt[Sin[x]]*Sqrt[a - a*Sin[x]])])/Sqrt[-a]}


(* ::Section:: *)
(*Sin[c+d x]^m (A+B Sin[c+d x]) (a+a Sin[c+d x])^n*)


(* ::Subsection::Closed:: *)
(*Integrands of the form Sin[c+d x]^m (A+B Sin[c+d x]) (a+a Sin[c+d x])^n*)


{(A + B*Sin[x])/(1 + Sin[x]), x, 2, B*x - ((A - B)*Cos[x])/(1 + Sin[x])}
{(A + B*Sin[x])/(1 + Sin[x])^2, x, 2, -(((A - B)*Cos[x])/(3*(1 + Sin[x])^2)) - ((A + 2*B)*Cos[x])/(3*(1 + Sin[x]))}
{(A + B*Sin[x])/(1 + Sin[x])^3, x, 3, -(((A - B)*Cos[x])/(5*(1 + Sin[x])^3)) - ((2*A + 3*B)*Cos[x])/(15*(1 + Sin[x])^2) - ((2*A + 3*B)*Cos[x])/(15*(1 + Sin[x]))}
{(A + B*Sin[x])/(1 + Sin[x])^4, x, 4, -(((A - B)*Cos[x])/(7*(1 + Sin[x])^4)) - ((3*A + 4*B)*Cos[x])/(35*(1 + Sin[x])^3) - (2*(3*A + 4*B)*Cos[x])/(105*(1 + Sin[x])^2) - (2*(3*A + 4*B)*Cos[x])/(105*(1 + Sin[x]))}

{(A + B*Sin[x])/(1 - Sin[x]), x, 2, (-B)*x + ((-A - B)*Cos[x])/(-1 + Sin[x])}
{(A + B*Sin[x])/(1 - Sin[x])^2, x, 2, ((A + B)*Cos[x])/(3*(1 - Sin[x])^2) + ((-A + 2*B)*Cos[x])/(3*(-1 + Sin[x]))}
{(A + B*Sin[x])/(1 - Sin[x])^3, x, 3, ((A + B)*Cos[x])/(5*(1 - Sin[x])^3) + ((2*A - 3*B)*Cos[x])/(15*(1 - Sin[x])^2) + ((-2*A + 3*B)*Cos[x])/(15*(-1 + Sin[x]))}
{(A + B*Sin[x])/(1 - Sin[x])^4, x, 4, ((A + B)*Cos[x])/(7*(1 - Sin[x])^4) + ((3*A - 4*B)*Cos[x])/(35*(1 - Sin[x])^3) + (2*(3*A - 4*B)*Cos[x])/(105*(1 - Sin[x])^2) - (2*(3*A - 4*B)*Cos[x])/(105*(-1 + Sin[x]))}


(* ::Subsection::Closed:: *)
(*Integrands of the form Sin[c+d x]^m (A+B Sin[c+d x]) (a+a Sin[c+d x])^(n/2)*)


{(A + B*Sin[x])*(a + a*Sin[x])^(5/2), x, 4, -((64*a^3*(7*A + 5*B)*Cos[x])/(105*Sqrt[a + a*Sin[x]])) - (16/105)*a^2*(7*A + 5*B)*Cos[x]*Sqrt[a + a*Sin[x]] - (2/35)*a*(7*A + 5*B)*Cos[x]*(a + a*Sin[x])^(3/2) - (2/7)*B*Cos[x]*(a + a*Sin[x])^(5/2)}
{(A + B*Sin[x])*(a + a*Sin[x])^(3/2), x, 3, -((8*a^2*(5*A + 3*B)*Cos[x])/(15*Sqrt[a + a*Sin[x]])) - (2/15)*a*(5*A + 3*B)*Cos[x]*Sqrt[a + a*Sin[x]] - (2/5)*B*Cos[x]*(a + a*Sin[x])^(3/2)}
{(A + B*Sin[x])*(a + a*Sin[x])^(1/2), x, 2, -((2*a*(3*A + B)*Cos[x])/(3*Sqrt[a + a*Sin[x]])) - (2/3)*B*Cos[x]*Sqrt[a + a*Sin[x]]}
{(A + B*Sin[x])/(a + a*Sin[x])^(1/2), x, 2, -((2*(A - B)*ArcTanh[Sin[Pi/4 - x/2]]*Cos[Pi/4 - x/2])/Sqrt[a + a*Sin[x]]) - (2*B*Cos[x])/Sqrt[a + a*Sin[x]]}
{(A + B*Sin[x])/(a + a*Sin[x])^(3/2), x, 2, ((-A + B)*Cos[x])/(2*(a + a*Sin[x])^(3/2)) - ((A + 3*B)*ArcTanh[Sin[Pi/4 - x/2]]*Cos[Pi/4 - x/2])/(2*a*Sqrt[a + a*Sin[x]])}
{(A + B*Sin[x])/(a + a*Sin[x])^(5/2), x, 3, ((-A + B)*Cos[x])/(4*(a + a*Sin[x])^(5/2)) - ((3*A + 5*B)*Cos[x])/(16*a*(a + a*Sin[x])^(3/2)) - ((3*A + 5*B)*ArcTanh[Sin[Pi/4 - x/2]]*Cos[Pi/4 - x/2])/(16*a^2*Sqrt[a + a*Sin[x]])}

{(A + B*Sin[x])*(a - a*Sin[x])^(5/2), x, 4, (64*a^3*(7*A - 5*B)*Cos[x])/(105*Sqrt[a - a*Sin[x]]) + (16/105)*a^2*(7*A - 5*B)*Cos[x]*Sqrt[a - a*Sin[x]] + (2/35)*a*(7*A - 5*B)*Cos[x]*(a - a*Sin[x])^(3/2) - (2/7)*B*Cos[x]*(a - a*Sin[x])^(5/2)}
{(A + B*Sin[x])*(a - a*Sin[x])^(3/2), x, 3, (8*a^2*(5*A - 3*B)*Cos[x])/(15*Sqrt[a - a*Sin[x]]) + (2/15)*a*(5*A - 3*B)*Cos[x]*Sqrt[a - a*Sin[x]] - (2/5)*B*Cos[x]*(a - a*Sin[x])^(3/2)}
{(A + B*Sin[x])*(a - a*Sin[x])^(1/2), x, 2, (2*a*(3*A - B)*Cos[x])/(3*Sqrt[a - a*Sin[x]]) - (2/3)*B*Cos[x]*Sqrt[a - a*Sin[x]]}
{(A + B*Sin[x])/(a - a*Sin[x])^(1/2), x, 2, (2*(A + B)*ArcTanh[Sin[Pi/4 + x/2]]*Cos[Pi/4 + x/2])/Sqrt[a - a*Sin[x]] - (2*B*Cos[x])/Sqrt[a - a*Sin[x]]}
{(A + B*Sin[x])/(a - a*Sin[x])^(3/2), x, 2, ((A + B)*Cos[x])/(2*(a - a*Sin[x])^(3/2)) + ((A - 3*B)*ArcTanh[Sin[Pi/4 + x/2]]*Cos[Pi/4 + x/2])/(2*a*Sqrt[a - a*Sin[x]])}
{(A + B*Sin[x])/(a - a*Sin[x])^(5/2), x, 3, ((A + B)*Cos[x])/(4*(a - a*Sin[x])^(5/2)) + ((3*A - 5*B)*Cos[x])/(16*a*(a - a*Sin[x])^(3/2)) + ((3*A - 5*B)*ArcTanh[Sin[Pi/4 + x/2]]*Cos[Pi/4 + x/2])/(16*a^2*Sqrt[a - a*Sin[x]])}


(* ::Section:: *)
(*Sin[c+d x]^m (A+C Sin[c+d x]^2) (a+a Sin[c+d x])^n*)


(* ::Subsection:: *)
(*Integrands of the form Sin[c+d x]^m (A+C Sin[c+d x]^2) (a+a Sin[c+d x])^n*)


(* ::Subsection:: *)
(*Integrands of the form Sin[c+d x]^m (A+C Sin[c+d x]^2) (a+a Sin[c+d x])^(n/2)*)


(* ::Section:: *)
(*Sin[c+d x]^m (A+B Sin[c+d x]+C Sin[c+d x]^2) (a+a Sin[c+d x])^n*)


(* ::Subsection:: *)
(*Integrands of the form Sin[c+d x]^m (A+B Sin[c+d x]+C Sin[c+d x]^2) (a+a Sin[c+d x])^n*)


(* ::Subsection:: *)
(*Integrands of the form Sin[c+d x]^m (A+B Sin[c+d x]+C Sin[c+d x]^2) (a+a Sin[c+d x])^(n/2)*)
