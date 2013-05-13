(* ::Package:: *)

(* {Sqrt[2*x + Sqrt[3 - 4*x^2]]/Sqrt[3 - 4*x^2], x, 3, 0}
{Sqrt[2*x + Sqrt[3 - 4*x^2]]/((c + d*x)*Sqrt[3 - 4*x^2]), x, 5, 0} *)


{Sqrt[2*x + Sqrt[3 + 4*x^2]]/Sqrt[3 + 4*x^2], x, 3, Sqrt[2*x + Sqrt[3 + 4*x^2]]}
{Sqrt[2*x - Sqrt[3 + 4*x^2]]/Sqrt[3 + 4*x^2], x, 3, -Sqrt[2*x - Sqrt[3 + 4*x^2]]}

{Sqrt[-2*x + Sqrt[3 + 4*x^2]]/Sqrt[3 + 4*x^2], x, 3, Sqrt[2*x + Sqrt[3 + 4*x^2]]}
{Sqrt[-2*x - Sqrt[3 + 4*x^2]]/Sqrt[3 + 4*x^2], x, 3, Sqrt[-2*x - Sqrt[3 + 4*x^2]]}


{Sqrt[2*x + Sqrt[3 + 4*x^2]]/((c + d*x)*Sqrt[3 + 4*x^2]), x, 5, -((2*Sqrt[2*c - Sqrt[4*c^2 + 3*d^2]]*ArcTan[(Sqrt[d]*Sqrt[2*x + Sqrt[3 + 4*x^2]])/Sqrt[2*c - Sqrt[4*c^2 + 3*d^2]]])/(Sqrt[d]*Sqrt[4*c^2 + 3*d^2])) + (2*Sqrt[2*c + Sqrt[4*c^2 + 3*d^2]]*ArcTan[(Sqrt[d]*Sqrt[2*x + Sqrt[3 + 4*x^2]])/Sqrt[2*c + Sqrt[4*c^2 + 3*d^2]]])/(Sqrt[d]*Sqrt[4*c^2 + 3*d^2])}


{Sqrt[2*x^2 + Sqrt[3 - 4*x^4]]/Sqrt[3 - 4*x^4], x, 3, 0}
{Sqrt[2*x^2 + Sqrt[3 - 4*x^4]]/((c + d*x)*Sqrt[3 - 4*x^4]), x, 3, 0}


{Sqrt[2*x^2 + Sqrt[3 + 4*x^4]]/Sqrt[3 + 4*x^4], x, 3, (-(1/2))*I*ArcSin[((1 + I)*x)/3^(1/4)] + (1/2)*ArcSinh[((1 + I)*x)/3^(1/4)]}
{Sqrt[2*x^2 + Sqrt[3 + 4*x^4]]/((c + d*x)*Sqrt[3 + 4*x^4]), x, 3, -(((1/2 - I/2)*ArcTan[(Sqrt[2*I*c^2 - Sqrt[3]*d^2]*Sqrt[Sqrt[3] - 2*I*x^2])/(Sqrt[3]*d + 2*I*c*x)])/Sqrt[2*I*c^2 - Sqrt[3]*d^2]) - ((1/2 + I/2)*ArcTanh[(Sqrt[2*I*c^2 + Sqrt[3]*d^2]*Sqrt[Sqrt[3] + 2*I*x^2])/(Sqrt[3]*d - 2*I*c*x)])/Sqrt[2*I*c^2 + Sqrt[3]*d^2]}
