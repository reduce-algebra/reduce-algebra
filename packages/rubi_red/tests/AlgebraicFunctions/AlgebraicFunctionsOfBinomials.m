(* ::Package:: *)

(* ::Title:: *)
(*Algebraic Function Integration Problems Involving Binomials*)


(* ::Subsection::Closed:: *)
(*Integrands involving roots of quadratic binomials*)


(* ::Subsubsection::Closed:: *)
(*Integrands of the form x^m (a+b x^2)^n*)


(* Integrands of the form x^m*(9+4*x^2)^n where m is an integer and n is a half-integer *)
{x^5*(9 + 4*x^2)^(3/2), x, 4, (9/280)*(9 + 4*x^2)^(5/2) - (1/28)*x^2*(9 + 4*x^2)^(5/2) + (1/36)*x^4*(9 + 4*x^2)^(5/2)}
{x^4*(9 + 4*x^2)^(3/2), x, 5, -((2187*x*Sqrt[9 + 4*x^2])/2048) + (81/256)*x^3*Sqrt[9 + 4*x^2] + (9/16)*x^5*Sqrt[9 + 4*x^2] + (1/8)*x^5*(9 + 4*x^2)^(3/2) + (19683*ArcSinh[(2*x)/3])/4096}
{x^3*(9 + 4*x^2)^(3/2), x, 3, (-(9/280))*(9 + 4*x^2)^(5/2) + (1/28)*x^2*(9 + 4*x^2)^(5/2)}
{x^2*(9 + 4*x^2)^(3/2), x, 4, (81/64)*x*Sqrt[9 + 4*x^2] + (9/8)*x^3*Sqrt[9 + 4*x^2] + (1/6)*x^3*(9 + 4*x^2)^(3/2) - (729/128)*ArcSinh[(2*x)/3]}
{x*(9 + 4*x^2)^(3/2), x, 2, (9 + 4*x^2)^(5/2)/20}
{(9 + 4*x^2)^(3/2), x, 3, (27/8)*x*Sqrt[9 + 4*x^2] + (1/4)*x*(9 + 4*x^2)^(3/2) + (243/16)*ArcSinh[(2*x)/3]}
{(9 + 4*x^2)^(3/2)/x, x, 3, 9*Sqrt[9 + 4*x^2] + (1/3)*(9 + 4*x^2)^(3/2) - 27*ArcTanh[(1/3)*Sqrt[9 + 4*x^2]]}
{(9 + 4*x^2)^(3/2)/x^2, x, 3, 6*x*Sqrt[9 + 4*x^2] - (9 + 4*x^2)^(3/2)/x + 27*ArcSinh[(2*x)/3]}
{(9 + 4*x^2)^(3/2)/x^3, x, 3, 6*Sqrt[9 + 4*x^2] - (9 + 4*x^2)^(3/2)/(2*x^2) - 18*ArcTanh[(1/3)*Sqrt[9 + 4*x^2]]}
{(9 + 4*x^2)^(3/2)/x^4, x, 3, -((4*Sqrt[9 + 4*x^2])/x) - (9 + 4*x^2)^(3/2)/(3*x^3) + 8*ArcSinh[(2*x)/3]}
{(9 + 4*x^2)^(3/2)/x^5, x, 3, -((3*Sqrt[9 + 4*x^2])/(2*x^2)) - (9 + 4*x^2)^(3/2)/(4*x^4) - 2*ArcTanh[(1/3)*Sqrt[9 + 4*x^2]]}

{x^5*Sqrt[9 + 4*x^2], x, 4, (27/280)*(9 + 4*x^2)^(3/2) - (9/140)*x^2*(9 + 4*x^2)^(3/2) + (1/28)*x^4*(9 + 4*x^2)^(3/2)}
{x^4*Sqrt[9 + 4*x^2], x, 4, (-(81/256))*x*Sqrt[9 + 4*x^2] + (3/32)*x^3*Sqrt[9 + 4*x^2] + (1/6)*x^5*Sqrt[9 + 4*x^2] + (729/512)*ArcSinh[(2*x)/3]}
{x^3*Sqrt[9 + 4*x^2], x, 3, (-(3/40))*(9 + 4*x^2)^(3/2) + (1/20)*x^2*(9 + 4*x^2)^(3/2)}
{x^2*Sqrt[9 + 4*x^2], x, 3, (9/32)*x*Sqrt[9 + 4*x^2] + (1/4)*x^3*Sqrt[9 + 4*x^2] - (81/64)*ArcSinh[(2*x)/3]}
{x*Sqrt[9 + 4*x^2], x, 2, (9 + 4*x^2)^(3/2)/12}
{Sqrt[9 + 4*x^2], x, 2, (1/2)*x*Sqrt[9 + 4*x^2] + (9/4)*ArcSinh[(2*x)/3]}
{Sqrt[9 + 4*x^2]/x, x, 2, Sqrt[9 + 4*x^2] - 3*ArcTanh[Sqrt[9 + 4*x^2]/3]}
{Sqrt[9 + 4*x^2]/x^2, x, 2, -(Sqrt[9 + 4*x^2]/x) + 2*ArcSinh[(2*x)/3]}
{Sqrt[9 + 4*x^2]/x^3, x, 2, -Sqrt[9 + 4*x^2]/(2*x^2) - (2*ArcTanh[Sqrt[9 + 4*x^2]/3])/3}
{Sqrt[9 + 4*x^2]/x^4, x, 1, -(9 + 4*x^2)^(3/2)/(27*x^3)}
{Sqrt[9 + 4*x^2]/x^5, x, 3, -(Sqrt[9 + 4*x^2]/(4*x^4)) - Sqrt[9 + 4*x^2]/(18*x^2) + (2/27)*ArcTanh[(1/3)*Sqrt[9 + 4*x^2]]}


(* Integrands of the form x^m*(9-4*x^2)^n where m is an integer and n is a half-integer *)
{x^5*(9 - 4*x^2)^(3/2), x, 4, (-(9/280))*(9 - 4*x^2)^(5/2) - (1/28)*x^2*(9 - 4*x^2)^(5/2) - (1/36)*x^4*(9 - 4*x^2)^(5/2)}
{x^4*(9 - 4*x^2)^(3/2), x, 5, -((2187*x*Sqrt[9 - 4*x^2])/2048) - (81/256)*x^3*Sqrt[9 - 4*x^2] + (9/16)*x^5*Sqrt[9 - 4*x^2] + (1/8)*x^5*(9 - 4*x^2)^(3/2) + (19683*ArcSin[(2*x)/3])/4096}
{x^3*(9 - 4*x^2)^(3/2), x, 3, (-(9/280))*(9 - 4*x^2)^(5/2) - (1/28)*x^2*(9 - 4*x^2)^(5/2)}
{x^2*(9 - 4*x^2)^(3/2), x, 4, (-(81/64))*x*Sqrt[9 - 4*x^2] + (9/8)*x^3*Sqrt[9 - 4*x^2] + (1/6)*x^3*(9 - 4*x^2)^(3/2) + (729/128)*ArcSin[(2*x)/3]}
{x*(9 - 4*x^2)^(3/2), x, 2, -(9 - 4*x^2)^(5/2)/20}
{(9 - 4*x^2)^(3/2), x, 3, (27/8)*x*Sqrt[9 - 4*x^2] + (1/4)*x*(9 - 4*x^2)^(3/2) + (243/16)*ArcSin[(2*x)/3]}
{(9 - 4*x^2)^(3/2)/x, x, 3, 9*Sqrt[9 - 4*x^2] + (1/3)*(9 - 4*x^2)^(3/2) - 27*ArcTanh[(1/3)*Sqrt[9 - 4*x^2]]}
{(9 - 4*x^2)^(3/2)/x^2, x, 3, -6*x*Sqrt[9 - 4*x^2] - (9 - 4*x^2)^(3/2)/x - 27*ArcSin[(2*x)/3]}
{(9 - 4*x^2)^(3/2)/x^3, x, 3, -6*Sqrt[9 - 4*x^2] - (9 - 4*x^2)^(3/2)/(2*x^2) + 18*ArcTanh[(1/3)*Sqrt[9 - 4*x^2]]}
{(9 - 4*x^2)^(3/2)/x^4, x, 3, (4*Sqrt[9 - 4*x^2])/x - (9 - 4*x^2)^(3/2)/(3*x^3) + 8*ArcSin[(2*x)/3]}
{(9 - 4*x^2)^(3/2)/x^5, x, 3, (3*Sqrt[9 - 4*x^2])/(2*x^2) - (9 - 4*x^2)^(3/2)/(4*x^4) - 2*ArcTanh[(1/3)*Sqrt[9 - 4*x^2]]}

{x^5*Sqrt[9 - 4*x^2], x, 4, (-(27/280))*(9 - 4*x^2)^(3/2) - (9/140)*x^2*(9 - 4*x^2)^(3/2) - (1/28)*x^4*(9 - 4*x^2)^(3/2)}
{x^4*Sqrt[9 - 4*x^2], x, 4, (-(81/256))*x*Sqrt[9 - 4*x^2] - (3/32)*x^3*Sqrt[9 - 4*x^2] + (1/6)*x^5*Sqrt[9 - 4*x^2] + (729/512)*ArcSin[(2*x)/3]}
{x^3*Sqrt[9 - 4*x^2], x, 3, (-(3/40))*(9 - 4*x^2)^(3/2) - (1/20)*x^2*(9 - 4*x^2)^(3/2)}
{x^2*Sqrt[9 - 4*x^2], x, 3, (-(9/32))*x*Sqrt[9 - 4*x^2] + (1/4)*x^3*Sqrt[9 - 4*x^2] + (81/64)*ArcSin[(2*x)/3]}
{x*Sqrt[9 - 4*x^2], x, 2, -(9 - 4*x^2)^(3/2)/12}
{Sqrt[9 - 4*x^2], x, 2, (1/2)*x*Sqrt[9 - 4*x^2] + (9/4)*ArcSin[(2*x)/3]}
{Sqrt[9 - 4*x^2]/x, x, 2, Sqrt[9 - 4*x^2] - 3*ArcTanh[Sqrt[9 - 4*x^2]/3]}
{Sqrt[9 - 4*x^2]/x^2, x, 2, -(Sqrt[9 - 4*x^2]/x) - 2*ArcSin[(2*x)/3]}
{Sqrt[9 - 4*x^2]/x^3, x, 2, -Sqrt[9 - 4*x^2]/(2*x^2) + (2*ArcTanh[Sqrt[9 - 4*x^2]/3])/3}
{Sqrt[9 - 4*x^2]/x^4, x, 1, -(9 - 4*x^2)^(3/2)/(27*x^3)}
{Sqrt[9 - 4*x^2]/x^5, x, 3, -(Sqrt[9 - 4*x^2]/(4*x^4)) + Sqrt[9 - 4*x^2]/(18*x^2) + (2/27)*ArcTanh[(1/3)*Sqrt[9 - 4*x^2]]}


(* Integrands of the form x^m*(-9+4*x^2)^n where m is an integer and n is a half-integer *)
{x^5*(-9 + 4*x^2)^(3/2), x, 4, (9/280)*(-9 + 4*x^2)^(5/2) + (1/28)*x^2*(-9 + 4*x^2)^(5/2) + (1/36)*x^4*(-9 + 4*x^2)^(5/2)}
{x^4*(-9 + 4*x^2)^(3/2), x, 5, (2187*x*Sqrt[-9 + 4*x^2])/2048 + (81/256)*x^3*Sqrt[-9 + 4*x^2] - (9/16)*x^5*Sqrt[-9 + 4*x^2] + (1/8)*x^5*(-9 + 4*x^2)^(3/2) + (19683*ArcTanh[(2*x)/Sqrt[-9 + 4*x^2]])/4096}
{x^3*(-9 + 4*x^2)^(3/2), x, 3, (9/280)*(-9 + 4*x^2)^(5/2) + (1/28)*x^2*(-9 + 4*x^2)^(5/2)}
{x^2*(-9 + 4*x^2)^(3/2), x, 4, (81/64)*x*Sqrt[-9 + 4*x^2] - (9/8)*x^3*Sqrt[-9 + 4*x^2] + (1/6)*x^3*(-9 + 4*x^2)^(3/2) + (729/128)*ArcTanh[(2*x)/Sqrt[-9 + 4*x^2]]}
{x*(-9 + 4*x^2)^(3/2), x, 2, (-9 + 4*x^2)^(5/2)/20}
{(-9 + 4*x^2)^(3/2), x, 3, (-(27/8))*x*Sqrt[-9 + 4*x^2] + (1/4)*x*(-9 + 4*x^2)^(3/2) + (243/16)*ArcTanh[(2*x)/Sqrt[-9 + 4*x^2]]}
{(-9 + 4*x^2)^(3/2)/x, x, 3, -9*Sqrt[-9 + 4*x^2] + (1/3)*(-9 + 4*x^2)^(3/2) + 27*ArcTan[(1/3)*Sqrt[-9 + 4*x^2]]}
{(-9 + 4*x^2)^(3/2)/x^2, x, 3, 6*x*Sqrt[-9 + 4*x^2] - (-9 + 4*x^2)^(3/2)/x - 27*ArcTanh[(2*x)/Sqrt[-9 + 4*x^2]]}
{(-9 + 4*x^2)^(3/2)/x^3, x, 3, 6*Sqrt[-9 + 4*x^2] - (-9 + 4*x^2)^(3/2)/(2*x^2) - 18*ArcTan[(1/3)*Sqrt[-9 + 4*x^2]]}
{(-9 + 4*x^2)^(3/2)/x^4, x, 3, -((4*Sqrt[-9 + 4*x^2])/x) - (-9 + 4*x^2)^(3/2)/(3*x^3) + 8*ArcTanh[(2*x)/Sqrt[-9 + 4*x^2]]}
{(-9 + 4*x^2)^(3/2)/x^5, x, 3, -((3*Sqrt[-9 + 4*x^2])/(2*x^2)) - (-9 + 4*x^2)^(3/2)/(4*x^4) + 2*ArcTan[(1/3)*Sqrt[-9 + 4*x^2]]}

{x^5*Sqrt[-9 + 4*x^2], x, 4, (27/280)*(-9 + 4*x^2)^(3/2) + (9/140)*x^2*(-9 + 4*x^2)^(3/2) + (1/28)*x^4*(-9 + 4*x^2)^(3/2)}
{x^4*Sqrt[-9 + 4*x^2], x, 4, (-(81/256))*x*Sqrt[-9 + 4*x^2] - (3/32)*x^3*Sqrt[-9 + 4*x^2] + (1/6)*x^5*Sqrt[-9 + 4*x^2] - (729/512)*ArcTanh[(2*x)/Sqrt[-9 + 4*x^2]]}
{x^3*Sqrt[-9 + 4*x^2], x, 3, (3/40)*(-9 + 4*x^2)^(3/2) + (1/20)*x^2*(-9 + 4*x^2)^(3/2)}
{x^2*Sqrt[-9 + 4*x^2], x, 3, (-(9/32))*x*Sqrt[-9 + 4*x^2] + (1/4)*x^3*Sqrt[-9 + 4*x^2] - (81/64)*ArcTanh[(2*x)/Sqrt[-9 + 4*x^2]]}
{x*Sqrt[-9 + 4*x^2], x, 2, (-9 + 4*x^2)^(3/2)/12}
{Sqrt[-9 + 4*x^2], x, 2, (1/2)*x*Sqrt[-9 + 4*x^2] - (9/4)*ArcTanh[(2*x)/Sqrt[-9 + 4*x^2]]}
{Sqrt[-9 + 4*x^2]/x, x, 2, Sqrt[-9 + 4*x^2] - 3*ArcTan[Sqrt[-9 + 4*x^2]/3]}
{Sqrt[-9 + 4*x^2]/x^2, x, 2, -(Sqrt[-9 + 4*x^2]/x) + 2*ArcTanh[(2*x)/Sqrt[-9 + 4*x^2]]}
{Sqrt[-9 + 4*x^2]/x^3, x, 2, -Sqrt[-9 + 4*x^2]/(2*x^2) + (2*ArcTan[Sqrt[-9 + 4*x^2]/3])/3}
{Sqrt[-9 + 4*x^2]/x^4, x, 1, (-9 + 4*x^2)^(3/2)/(27*x^3)}
{Sqrt[-9 + 4*x^2]/x^5, x, 3, -(Sqrt[-9 + 4*x^2]/(4*x^4)) + Sqrt[-9 + 4*x^2]/(18*x^2) + (2/27)*ArcTan[(1/3)*Sqrt[-9 + 4*x^2]]}


(* Integrands of the form x^m*(-9-4*x^2)^n where m is an integer and n is a half-integer *)
{x^5*(-9 - 4*x^2)^(3/2), x, 4, (-(9/280))*(-9 - 4*x^2)^(5/2) + (1/28)*x^2*(-9 - 4*x^2)^(5/2) - (1/36)*x^4*(-9 - 4*x^2)^(5/2)}
{x^4*(-9 - 4*x^2)^(3/2), x, 5, (2187*x*Sqrt[-9 - 4*x^2])/2048 - (81/256)*x^3*Sqrt[-9 - 4*x^2] - (9/16)*x^5*Sqrt[-9 - 4*x^2] + (1/8)*x^5*(-9 - 4*x^2)^(3/2) + (19683*ArcTan[(2*x)/Sqrt[-9 - 4*x^2]])/4096}
{x^3*(-9 - 4*x^2)^(3/2), x, 3, (9/280)*(-9 - 4*x^2)^(5/2) - (1/28)*x^2*(-9 - 4*x^2)^(5/2)}
{x^2*(-9 - 4*x^2)^(3/2), x, 4, (-(81/64))*x*Sqrt[-9 - 4*x^2] - (9/8)*x^3*Sqrt[-9 - 4*x^2] + (1/6)*x^3*(-9 - 4*x^2)^(3/2) - (729/128)*ArcTan[(2*x)/Sqrt[-9 - 4*x^2]]}
{x*(-9 - 4*x^2)^(3/2), x, 2, -(-9 - 4*x^2)^(5/2)/20}
{(-9 - 4*x^2)^(3/2), x, 3, (-(27/8))*x*Sqrt[-9 - 4*x^2] + (1/4)*x*(-9 - 4*x^2)^(3/2) + (243/16)*ArcTan[(2*x)/Sqrt[-9 - 4*x^2]]}
{(-9 - 4*x^2)^(3/2)/x, x, 3, -9*Sqrt[-9 - 4*x^2] + (1/3)*(-9 - 4*x^2)^(3/2) + 27*ArcTan[(1/3)*Sqrt[-9 - 4*x^2]]}
{(-9 - 4*x^2)^(3/2)/x^2, x, 3, -6*x*Sqrt[-9 - 4*x^2] - (-9 - 4*x^2)^(3/2)/x + 27*ArcTan[(2*x)/Sqrt[-9 - 4*x^2]]}
{(-9 - 4*x^2)^(3/2)/x^3, x, 3, -6*Sqrt[-9 - 4*x^2] - (-9 - 4*x^2)^(3/2)/(2*x^2) + 18*ArcTan[(1/3)*Sqrt[-9 - 4*x^2]]}
{(-9 - 4*x^2)^(3/2)/x^4, x, 3, (4*Sqrt[-9 - 4*x^2])/x - (-9 - 4*x^2)^(3/2)/(3*x^3) + 8*ArcTan[(2*x)/Sqrt[-9 - 4*x^2]]}
{(-9 - 4*x^2)^(3/2)/x^5, x, 3, (3*Sqrt[-9 - 4*x^2])/(2*x^2) - (-9 - 4*x^2)^(3/2)/(4*x^4) + 2*ArcTan[(1/3)*Sqrt[-9 - 4*x^2]]}

{x^5*Sqrt[-9 - 4*x^2], x, 4, (-(27/280))*(-9 - 4*x^2)^(3/2) + (9/140)*x^2*(-9 - 4*x^2)^(3/2) - (1/28)*x^4*(-9 - 4*x^2)^(3/2)}
{x^4*Sqrt[-9 - 4*x^2], x, 4, (-(81/256))*x*Sqrt[-9 - 4*x^2] + (3/32)*x^3*Sqrt[-9 - 4*x^2] + (1/6)*x^5*Sqrt[-9 - 4*x^2] - (729/512)*ArcTan[(2*x)/Sqrt[-9 - 4*x^2]]}
{x^3*Sqrt[-9 - 4*x^2], x, 3, (3/40)*(-9 - 4*x^2)^(3/2) - (1/20)*x^2*(-9 - 4*x^2)^(3/2)}
{x^2*Sqrt[-9 - 4*x^2], x, 3, (9/32)*x*Sqrt[-9 - 4*x^2] + (1/4)*x^3*Sqrt[-9 - 4*x^2] + (81/64)*ArcTan[(2*x)/Sqrt[-9 - 4*x^2]]}
{x*Sqrt[-9 - 4*x^2], x, 2, -(-9 - 4*x^2)^(3/2)/12}
{Sqrt[-9 - 4*x^2], x, 2, (1/2)*x*Sqrt[-9 - 4*x^2] - (9/4)*ArcTan[(2*x)/Sqrt[-9 - 4*x^2]]}
{Sqrt[-9 - 4*x^2]/x, x, 2, Sqrt[-9 - 4*x^2] - 3*ArcTan[Sqrt[-9 - 4*x^2]/3]}
{Sqrt[-9 - 4*x^2]/x^2, x, 2, -(Sqrt[-9 - 4*x^2]/x) - 2*ArcTan[(2*x)/Sqrt[-9 - 4*x^2]]}
{Sqrt[-9 - 4*x^2]/x^3, x, 2, -Sqrt[-9 - 4*x^2]/(2*x^2) - (2*ArcTan[Sqrt[-9 - 4*x^2]/3])/3}
{Sqrt[-9 - 4*x^2]/x^4, x, 1, (-9 - 4*x^2)^(3/2)/(27*x^3)}
{Sqrt[-9 - 4*x^2]/x^5, x, 3, -(Sqrt[-9 - 4*x^2]/(4*x^4)) - Sqrt[-9 - 4*x^2]/(18*x^2) + (2/27)*ArcTan[(1/3)*Sqrt[-9 - 4*x^2]]}


(* ::Subsubsection::Closed:: *)
(*Integrands of the form x^m / (a+b x^2)^n*)


(* Integrands of the form 1/Sqrt[a+b*x^2] *)
{1/Sqrt[9 + b*x^2], x, 1, ArcSinh[(Sqrt[b]*x)/3]/Sqrt[b]}
{1/Sqrt[9 - b*x^2], x, 1, ArcSin[(Sqrt[b]*x)/3]/Sqrt[b]}
{1/Sqrt[-9 + b*x^2], x, 1, ArcTanh[(Sqrt[b]*x)/Sqrt[-9 + b*x^2]]/Sqrt[b]}
{1/Sqrt[-9 - b*x^2], x, 1, ArcTan[(Sqrt[b]*x)/Sqrt[-9 - b*x^2]]/Sqrt[b]}

{1/Sqrt[Pi + b*x^2], x, 1, ArcSinh[(Sqrt[b]*x)/Sqrt[Pi]]/Sqrt[b]}
{1/Sqrt[Pi - b*x^2], x, 1, ArcSin[(Sqrt[b]*x)/Sqrt[Pi]]/Sqrt[b]}
{1/Sqrt[-Pi + b*x^2], x, 1, ArcTanh[(Sqrt[b]*x)/Sqrt[-Pi + b*x^2]]/Sqrt[b]}
{1/Sqrt[-Pi - b*x^2], x, 1, ArcTan[(Sqrt[b]*x)/Sqrt[-Pi - b*x^2]]/Sqrt[b]}

{1/Sqrt[a + b*x^2], x, 1, ArcTanh[(Sqrt[b]*x)/Sqrt[a + b*x^2]]/Sqrt[b]}
{1/Sqrt[a - b*x^2], x, 1, ArcTan[(Sqrt[b]*x)/Sqrt[a - b*x^2]]/Sqrt[b]}
{1/Sqrt[-a + b*x^2], x, 1, ArcTanh[(Sqrt[b]*x)/Sqrt[-a + b*x^2]]/Sqrt[b]}
{1/Sqrt[-a - b*x^2], x, 1, ArcTan[(Sqrt[b]*x)/Sqrt[-a - b*x^2]]/Sqrt[b]}


(* Integrands of the form x^m/(9+4*x^2)^n where m is an integer and n is a half-integer *)
{x^5/Sqrt[9 + 4*x^2], x, 4, (27/40)*Sqrt[9 + 4*x^2] - (3/20)*x^2*Sqrt[9 + 4*x^2] + (1/20)*x^4*Sqrt[9 + 4*x^2]}
{x^4/Sqrt[9 + 4*x^2], x, 3, (-(27/128))*x*Sqrt[9 + 4*x^2] + (1/16)*x^3*Sqrt[9 + 4*x^2] + (243/256)*ArcSinh[(2*x)/3]}
{x^3/Sqrt[9 + 4*x^2], x, 3, (-(3/8))*Sqrt[9 + 4*x^2] + (1/12)*x^2*Sqrt[9 + 4*x^2]}
{x^2/Sqrt[9 + 4*x^2], x, 2, (1/8)*x*Sqrt[9 + 4*x^2] - (9/16)*ArcSinh[(2*x)/3]}
{x/Sqrt[9 + 4*x^2], x, 2, Sqrt[9 + 4*x^2]/4}
{1/Sqrt[9 + 4*x^2], x, 1, ArcSinh[(2*x)/3]/2}
{1/(x*Sqrt[9 + 4*x^2]), x, 1, -ArcTanh[Sqrt[9 + 4*x^2]/3]/3}
{1/(x^2*Sqrt[9 + 4*x^2]), x, 1, -Sqrt[9 + 4*x^2]/(9*x)}
{1/(x^3*Sqrt[9 + 4*x^2]), x, 2, -(Sqrt[9 + 4*x^2]/(18*x^2)) + (2/27)*ArcTanh[(1/3)*Sqrt[9 + 4*x^2]]}
{1/(x^4*Sqrt[9 + 4*x^2]), x, 2, -(Sqrt[9 + 4*x^2]/(27*x^3)) + (8*Sqrt[9 + 4*x^2])/(243*x)}
{1/(x^5*Sqrt[9 + 4*x^2]), x, 3, -(Sqrt[9 + 4*x^2]/(36*x^4)) + Sqrt[9 + 4*x^2]/(54*x^2) - (2/81)*ArcTanh[(1/3)*Sqrt[9 + 4*x^2]]}

{x^5/(9 + 4*x^2)^(3/2), x, 4, -(x^4/(4*Sqrt[9 + 4*x^2])) - (3/8)*Sqrt[9 + 4*x^2] + (1/12)*x^2*Sqrt[9 + 4*x^2]}
{x^4/(9 + 4*x^2)^(3/2), x, 3, -(x^3/(4*Sqrt[9 + 4*x^2])) + (3/32)*x*Sqrt[9 + 4*x^2] - (27/64)*ArcSinh[(2*x)/3]}
{x^3/(9 + 4*x^2)^(3/2), x, 3, -(x^2/(4*Sqrt[9 + 4*x^2])) + (1/8)*Sqrt[9 + 4*x^2]}
{x^2/(9 + 4*x^2)^(3/2), x, 2, -(x/(4*Sqrt[9 + 4*x^2])) + (1/8)*ArcSinh[(2*x)/3]}
{x/(9 + 4*x^2)^(3/2), x, 2, -1/(4*Sqrt[9 + 4*x^2])}
{(9 + 4*x^2)^(-3/2), x, 1, x/(9*Sqrt[9 + 4*x^2])}
{1/(x*(9 + 4*x^2)^(3/2)), x, 2, 1/(9*Sqrt[9 + 4*x^2]) - (1/27)*ArcTanh[(1/3)*Sqrt[9 + 4*x^2]]}
{1/(x^2*(9 + 4*x^2)^(3/2)), x, 2, 1/(9*x*Sqrt[9 + 4*x^2]) - (2*Sqrt[9 + 4*x^2])/(81*x)}
{1/(x^3*(9 + 4*x^2)^(3/2)), x, 3, 1/(9*x^2*Sqrt[9 + 4*x^2]) - Sqrt[9 + 4*x^2]/(54*x^2) + (2/81)*ArcTanh[(1/3)*Sqrt[9 + 4*x^2]]}
{1/(x^4*(9 + 4*x^2)^(3/2)), x, 3, 1/(9*x^3*Sqrt[9 + 4*x^2]) - (4*Sqrt[9 + 4*x^2])/(243*x^3) + (32*Sqrt[9 + 4*x^2])/(2187*x)}
{1/(x^5*(9 + 4*x^2)^(3/2)), x, 4, 1/(9*x^4*Sqrt[9 + 4*x^2]) - (5*Sqrt[9 + 4*x^2])/(324*x^4) + (5*Sqrt[9 + 4*x^2])/(486*x^2) - (10/729)*ArcTanh[(1/3)*Sqrt[9 + 4*x^2]]}

{x^5/(9 + 4*x^2)^(5/2), x, 4, -(x^4/(12*(9 + 4*x^2)^(3/2))) - x^2/(12*Sqrt[9 + 4*x^2]) + (1/24)*Sqrt[9 + 4*x^2]}
{x^4/(9 + 4*x^2)^(5/2), x, 3, -(x^3/(12*(9 + 4*x^2)^(3/2))) - x/(16*Sqrt[9 + 4*x^2]) + (1/32)*ArcSinh[(2*x)/3]}
{x^3/(9 + 4*x^2)^(5/2), x, 3, -(x^2/(12*(9 + 4*x^2)^(3/2))) - 1/(24*Sqrt[9 + 4*x^2])}
{x^2/(9 + 4*x^2)^(5/2), x, 1, x^3/(27*(9 + 4*x^2)^(3/2))}
{x/(9 + 4*x^2)^(5/2), x, 2, -1/(12*(9 + 4*x^2)^(3/2))}
{1/(9 + 4*x^2)^(5/2), x, 2, x/(27*(9 + 4*x^2)^(3/2)) + (2*x)/(243*Sqrt[9 + 4*x^2])}
{1/(x*(9 + 4*x^2)^(5/2)), x, 3, 1/(27*(9 + 4*x^2)^(3/2)) + 1/(81*Sqrt[9 + 4*x^2]) - (1/243)*ArcTanh[(1/3)*Sqrt[9 + 4*x^2]]}
{1/(x^2*(9 + 4*x^2)^(5/2)), x, 3, 1/(27*x*(9 + 4*x^2)^(3/2)) + 4/(243*x*Sqrt[9 + 4*x^2]) - (8*Sqrt[9 + 4*x^2])/(2187*x)}
{1/(x^3*(9 + 4*x^2)^(5/2)), x, 4, 1/(27*x^2*(9 + 4*x^2)^(3/2)) + 5/(243*x^2*Sqrt[9 + 4*x^2]) - (5*Sqrt[9 + 4*x^2])/(1458*x^2) + (10*ArcTanh[(1/3)*Sqrt[9 + 4*x^2]])/2187}
{1/(x^4*(9 + 4*x^2)^(5/2)), x, 4, 1/(27*x^3*(9 + 4*x^2)^(3/2)) + 2/(81*x^3*Sqrt[9 + 4*x^2]) - (8*Sqrt[9 + 4*x^2])/(2187*x^3) + (64*Sqrt[9 + 4*x^2])/(19683*x)}
{1/(x^5*(9 + 4*x^2)^(5/2)), x, 5, 1/(27*x^4*(9 + 4*x^2)^(3/2)) + 7/(243*x^4*Sqrt[9 + 4*x^2]) - (35*Sqrt[9 + 4*x^2])/(8748*x^4) + (35*Sqrt[9 + 4*x^2])/(13122*x^2) - (70*ArcTanh[(1/3)*Sqrt[9 + 4*x^2]])/19683}


(* Integrands of the form x^m/(9-4*x^2)^n where m is an integer and n is a half-integer *)
{x^5/Sqrt[9 - 4*x^2], x, 4, (-(27/40))*Sqrt[9 - 4*x^2] - (3/20)*x^2*Sqrt[9 - 4*x^2] - (1/20)*x^4*Sqrt[9 - 4*x^2]}
{x^4/Sqrt[9 - 4*x^2], x, 3, (-(27/128))*x*Sqrt[9 - 4*x^2] - (1/16)*x^3*Sqrt[9 - 4*x^2] + (243/256)*ArcSin[(2*x)/3]}
{x^3/Sqrt[9 - 4*x^2], x, 3, (-(3/8))*Sqrt[9 - 4*x^2] - (1/12)*x^2*Sqrt[9 - 4*x^2]}
{x^2/Sqrt[9 - 4*x^2], x, 2, (-(1/8))*x*Sqrt[9 - 4*x^2] + (9/16)*ArcSin[(2*x)/3]}
{x/Sqrt[9 - 4*x^2], x, 2, -Sqrt[9 - 4*x^2]/4}
{1/Sqrt[9 - 4*x^2], x, 1, ArcSin[(2*x)/3]/2}
{1/(x*Sqrt[9 - 4*x^2]), x, 1, -ArcTanh[Sqrt[9 - 4*x^2]/3]/3}
{1/(x^2*Sqrt[9 - 4*x^2]), x, 1, -Sqrt[9 - 4*x^2]/(9*x)}
{1/(x^3*Sqrt[9 - 4*x^2]), x, 2, -(Sqrt[9 - 4*x^2]/(18*x^2)) - (2/27)*ArcTanh[(1/3)*Sqrt[9 - 4*x^2]]}
{1/(x^4*Sqrt[9 - 4*x^2]), x, 2, -(Sqrt[9 - 4*x^2]/(27*x^3)) - (8*Sqrt[9 - 4*x^2])/(243*x)}
{1/(x^5*Sqrt[9 - 4*x^2]), x, 3, -(Sqrt[9 - 4*x^2]/(36*x^4)) - Sqrt[9 - 4*x^2]/(54*x^2) - (2/81)*ArcTanh[(1/3)*Sqrt[9 - 4*x^2]]}

{x^5/(9 - 4*x^2)^(3/2), x, 4, x^4/(4*Sqrt[9 - 4*x^2]) + (3/8)*Sqrt[9 - 4*x^2] + (1/12)*x^2*Sqrt[9 - 4*x^2]}
{x^4/(9 - 4*x^2)^(3/2), x, 3, x^3/(4*Sqrt[9 - 4*x^2]) + (3/32)*x*Sqrt[9 - 4*x^2] - (27/64)*ArcSin[(2*x)/3]}
{x^3/(9 - 4*x^2)^(3/2), x, 3, x^2/(4*Sqrt[9 - 4*x^2]) + (1/8)*Sqrt[9 - 4*x^2]}
{x^2/(9 - 4*x^2)^(3/2), x, 2, x/(4*Sqrt[9 - 4*x^2]) - (1/8)*ArcSin[(2*x)/3]}
{x/(9 - 4*x^2)^(3/2), x, 2, 1/(4*Sqrt[9 - 4*x^2])}
{(9 - 4*x^2)^(-3/2), x, 1, x/(9*Sqrt[9 - 4*x^2])}
{1/(x*(9 - 4*x^2)^(3/2)), x, 2, 1/(9*Sqrt[9 - 4*x^2]) - (1/27)*ArcTanh[(1/3)*Sqrt[9 - 4*x^2]]}
{1/(x^2*(9 - 4*x^2)^(3/2)), x, 2, 1/(9*x*Sqrt[9 - 4*x^2]) - (2*Sqrt[9 - 4*x^2])/(81*x)}
{1/(x^3*(9 - 4*x^2)^(3/2)), x, 3, 1/(9*x^2*Sqrt[9 - 4*x^2]) - Sqrt[9 - 4*x^2]/(54*x^2) - (2/81)*ArcTanh[(1/3)*Sqrt[9 - 4*x^2]]}
{1/(x^4*(9 - 4*x^2)^(3/2)), x, 3, 1/(9*x^3*Sqrt[9 - 4*x^2]) - (4*Sqrt[9 - 4*x^2])/(243*x^3) - (32*Sqrt[9 - 4*x^2])/(2187*x)}
{1/(x^5*(9 - 4*x^2)^(3/2)), x, 4, 1/(9*x^4*Sqrt[9 - 4*x^2]) - (5*Sqrt[9 - 4*x^2])/(324*x^4) - (5*Sqrt[9 - 4*x^2])/(486*x^2) - (10/729)*ArcTanh[(1/3)*Sqrt[9 - 4*x^2]]}

{x^5/(9 - 4*x^2)^(5/2), x, 4, x^4/(12*(9 - 4*x^2)^(3/2)) - x^2/(12*Sqrt[9 - 4*x^2]) - (1/24)*Sqrt[9 - 4*x^2]}
{x^4/(9 - 4*x^2)^(5/2), x, 3, x^3/(12*(9 - 4*x^2)^(3/2)) - x/(16*Sqrt[9 - 4*x^2]) + (1/32)*ArcSin[(2*x)/3]}
{x^3/(9 - 4*x^2)^(5/2), x, 3, x^2/(12*(9 - 4*x^2)^(3/2)) - 1/(24*Sqrt[9 - 4*x^2])}
{x^2/(9 - 4*x^2)^(5/2), x, 1, x^3/(27*(9 - 4*x^2)^(3/2))}
{x/(9 - 4*x^2)^(5/2), x, 2, 1/(12*(9 - 4*x^2)^(3/2))}
{1/(9 - 4*x^2)^(5/2), x, 2, x/(27*(9 - 4*x^2)^(3/2)) + (2*x)/(243*Sqrt[9 - 4*x^2])}
{1/(x*(9 - 4*x^2)^(5/2)), x, 3, 1/(27*(9 - 4*x^2)^(3/2)) + 1/(81*Sqrt[9 - 4*x^2]) - (1/243)*ArcTanh[(1/3)*Sqrt[9 - 4*x^2]]}
{1/(x^2*(9 - 4*x^2)^(5/2)), x, 3, 1/(27*x*(9 - 4*x^2)^(3/2)) + 4/(243*x*Sqrt[9 - 4*x^2]) - (8*Sqrt[9 - 4*x^2])/(2187*x)}
{1/(x^3*(9 - 4*x^2)^(5/2)), x, 4, 1/(27*x^2*(9 - 4*x^2)^(3/2)) + 5/(243*x^2*Sqrt[9 - 4*x^2]) - (5*Sqrt[9 - 4*x^2])/(1458*x^2) - (10*ArcTanh[(1/3)*Sqrt[9 - 4*x^2]])/2187}
{1/(x^4*(9 - 4*x^2)^(5/2)), x, 4, 1/(27*x^3*(9 - 4*x^2)^(3/2)) + 2/(81*x^3*Sqrt[9 - 4*x^2]) - (8*Sqrt[9 - 4*x^2])/(2187*x^3) - (64*Sqrt[9 - 4*x^2])/(19683*x)}
{1/(x^5*(9 - 4*x^2)^(5/2)), x, 5, 1/(27*x^4*(9 - 4*x^2)^(3/2)) + 7/(243*x^4*Sqrt[9 - 4*x^2]) - (35*Sqrt[9 - 4*x^2])/(8748*x^4) - (35*Sqrt[9 - 4*x^2])/(13122*x^2) - (70*ArcTanh[(1/3)*Sqrt[9 - 4*x^2]])/19683}


(* Integrands of the form x^m/(-9+4*x^2)^n where m is an integer and n is a half-integer *)
{x^5/Sqrt[-9 + 4*x^2], x, 4, (27/40)*Sqrt[-9 + 4*x^2] + (3/20)*x^2*Sqrt[-9 + 4*x^2] + (1/20)*x^4*Sqrt[-9 + 4*x^2]}
{x^4/Sqrt[-9 + 4*x^2], x, 3, (27/128)*x*Sqrt[-9 + 4*x^2] + (1/16)*x^3*Sqrt[-9 + 4*x^2] + (243/256)*ArcTanh[(2*x)/Sqrt[-9 + 4*x^2]]}
{x^3/Sqrt[-9 + 4*x^2], x, 3, (3/8)*Sqrt[-9 + 4*x^2] + (1/12)*x^2*Sqrt[-9 + 4*x^2]}
{x^2/Sqrt[-9 + 4*x^2], x, 2, (1/8)*x*Sqrt[-9 + 4*x^2] + (9/16)*ArcTanh[(2*x)/Sqrt[-9 + 4*x^2]]}
{x/Sqrt[-9 + 4*x^2], x, 2, Sqrt[-9 + 4*x^2]/4}
{1/Sqrt[-9 + 4*x^2], x, 1, (1/2)*ArcTanh[(2*x)/Sqrt[-9 + 4*x^2]]}
{1/(x*Sqrt[-9 + 4*x^2]), x, 1, ArcTan[Sqrt[-9 + 4*x^2]/3]/3}
{1/(x^2*Sqrt[-9 + 4*x^2]), x, 1, Sqrt[-9 + 4*x^2]/(9*x)}
{1/(x^3*Sqrt[-9 + 4*x^2]), x, 2, Sqrt[-9 + 4*x^2]/(18*x^2) + (2/27)*ArcTan[(1/3)*Sqrt[-9 + 4*x^2]]}
{1/(x^4*Sqrt[-9 + 4*x^2]), x, 2, Sqrt[-9 + 4*x^2]/(27*x^3) + (8*Sqrt[-9 + 4*x^2])/(243*x)}
{1/(x^5*Sqrt[-9 + 4*x^2]), x, 3, Sqrt[-9 + 4*x^2]/(36*x^4) + Sqrt[-9 + 4*x^2]/(54*x^2) + (2/81)*ArcTan[(1/3)*Sqrt[-9 + 4*x^2]]}

{x^5/(-9 + 4*x^2)^(3/2), x, 4, -(x^4/(4*Sqrt[-9 + 4*x^2])) + (3/8)*Sqrt[-9 + 4*x^2] + (1/12)*x^2*Sqrt[-9 + 4*x^2]}
{x^4/(-9 + 4*x^2)^(3/2), x, 3, -(x^3/(4*Sqrt[-9 + 4*x^2])) + (3/32)*x*Sqrt[-9 + 4*x^2] + (27/64)*ArcTanh[(2*x)/Sqrt[-9 + 4*x^2]]}
{x^3/(-9 + 4*x^2)^(3/2), x, 3, -(x^2/(4*Sqrt[-9 + 4*x^2])) + (1/8)*Sqrt[-9 + 4*x^2]}
{x^2/(-9 + 4*x^2)^(3/2), x, 2, -(x/(4*Sqrt[-9 + 4*x^2])) + (1/8)*ArcTanh[(2*x)/Sqrt[-9 + 4*x^2]]}
{x/(-9 + 4*x^2)^(3/2), x, 2, -1/(4*Sqrt[-9 + 4*x^2])}
{(-9 + 4*x^2)^(-3/2), x, 1, -x/(9*Sqrt[-9 + 4*x^2])}
{1/(x*(-9 + 4*x^2)^(3/2)), x, 2, -(1/(9*Sqrt[-9 + 4*x^2])) - (1/27)*ArcTan[(1/3)*Sqrt[-9 + 4*x^2]]}
{1/(x^2*(-9 + 4*x^2)^(3/2)), x, 2, -(1/(9*x*Sqrt[-9 + 4*x^2])) - (2*Sqrt[-9 + 4*x^2])/(81*x)}
{1/(x^3*(-9 + 4*x^2)^(3/2)), x, 3, -(1/(9*x^2*Sqrt[-9 + 4*x^2])) - Sqrt[-9 + 4*x^2]/(54*x^2) - (2/81)*ArcTan[(1/3)*Sqrt[-9 + 4*x^2]]}
{1/(x^4*(-9 + 4*x^2)^(3/2)), x, 3, -(1/(9*x^3*Sqrt[-9 + 4*x^2])) - (4*Sqrt[-9 + 4*x^2])/(243*x^3) - (32*Sqrt[-9 + 4*x^2])/(2187*x)}
{1/(x^5*(-9 + 4*x^2)^(3/2)), x, 4, -(1/(9*x^4*Sqrt[-9 + 4*x^2])) - (5*Sqrt[-9 + 4*x^2])/(324*x^4) - (5*Sqrt[-9 + 4*x^2])/(486*x^2) - (10/729)*ArcTan[(1/3)*Sqrt[-9 + 4*x^2]]}

{x^5/(-9 + 4*x^2)^(5/2), x, 4, -(x^4/(12*(-9 + 4*x^2)^(3/2))) - x^2/(12*Sqrt[-9 + 4*x^2]) + (1/24)*Sqrt[-9 + 4*x^2]}
{x^4/(-9 + 4*x^2)^(5/2), x, 3, -(x^3/(12*(-9 + 4*x^2)^(3/2))) - x/(16*Sqrt[-9 + 4*x^2]) + (1/32)*ArcTanh[(2*x)/Sqrt[-9 + 4*x^2]]}
{x^3/(-9 + 4*x^2)^(5/2), x, 3, -(x^2/(12*(-9 + 4*x^2)^(3/2))) - 1/(24*Sqrt[-9 + 4*x^2])}
{x^2/(-9 + 4*x^2)^(5/2), x, 1, -x^3/(27*(-9 + 4*x^2)^(3/2))}
{x/(-9 + 4*x^2)^(5/2), x, 2, -1/(12*(-9 + 4*x^2)^(3/2))}
{1/(-9 + 4*x^2)^(5/2), x, 2, -(x/(27*(-9 + 4*x^2)^(3/2))) + (2*x)/(243*Sqrt[-9 + 4*x^2])}
{1/(x*(-9 + 4*x^2)^(5/2)), x, 3, -(1/(27*(-9 + 4*x^2)^(3/2))) + 1/(81*Sqrt[-9 + 4*x^2]) + (1/243)*ArcTan[(1/3)*Sqrt[-9 + 4*x^2]]}
{1/(x^2*(-9 + 4*x^2)^(5/2)), x, 3, -(1/(27*x*(-9 + 4*x^2)^(3/2))) + 4/(243*x*Sqrt[-9 + 4*x^2]) + (8*Sqrt[-9 + 4*x^2])/(2187*x)}
{1/(x^3*(-9 + 4*x^2)^(5/2)), x, 4, -(1/(27*x^2*(-9 + 4*x^2)^(3/2))) + 5/(243*x^2*Sqrt[-9 + 4*x^2]) + (5*Sqrt[-9 + 4*x^2])/(1458*x^2) + (10*ArcTan[(1/3)*Sqrt[-9 + 4*x^2]])/2187}
{1/(x^4*(-9 + 4*x^2)^(5/2)), x, 4, -(1/(27*x^3*(-9 + 4*x^2)^(3/2))) + 2/(81*x^3*Sqrt[-9 + 4*x^2]) + (8*Sqrt[-9 + 4*x^2])/(2187*x^3) + (64*Sqrt[-9 + 4*x^2])/(19683*x)}
{1/(x^5*(-9 + 4*x^2)^(5/2)), x, 5, -(1/(27*x^4*(-9 + 4*x^2)^(3/2))) + 7/(243*x^4*Sqrt[-9 + 4*x^2]) + (35*Sqrt[-9 + 4*x^2])/(8748*x^4) + (35*Sqrt[-9 + 4*x^2])/(13122*x^2) + (70*ArcTan[(1/3)*Sqrt[-9 + 4*x^2]])/19683}


(* Integrands of the form x^m/(-9-4*x^2)^n where m is an integer and n is a half-integer *)
{x^5/Sqrt[-9 - 4*x^2], x, 4, (-(27/40))*Sqrt[-9 - 4*x^2] + (3/20)*x^2*Sqrt[-9 - 4*x^2] - (1/20)*x^4*Sqrt[-9 - 4*x^2]}
{x^4/Sqrt[-9 - 4*x^2], x, 3, (27/128)*x*Sqrt[-9 - 4*x^2] - (1/16)*x^3*Sqrt[-9 - 4*x^2] + (243/256)*ArcTan[(2*x)/Sqrt[-9 - 4*x^2]]}
{x^3/Sqrt[-9 - 4*x^2], x, 3, (3/8)*Sqrt[-9 - 4*x^2] - (1/12)*x^2*Sqrt[-9 - 4*x^2]}
{x^2/Sqrt[-9 - 4*x^2], x, 2, (-(1/8))*x*Sqrt[-9 - 4*x^2] - (9/16)*ArcTan[(2*x)/Sqrt[-9 - 4*x^2]]}
{x/Sqrt[-9 - 4*x^2], x, 2, -Sqrt[-9 - 4*x^2]/4}
{1/Sqrt[-9 - 4*x^2], x, 1, (1/2)*ArcTan[(2*x)/Sqrt[-9 - 4*x^2]]}
{1/(x*Sqrt[-9 - 4*x^2]), x, 1, ArcTan[Sqrt[-9 - 4*x^2]/3]/3}
{1/(x^2*Sqrt[-9 - 4*x^2]), x, 1, Sqrt[-9 - 4*x^2]/(9*x)}
{1/(x^3*Sqrt[-9 - 4*x^2]), x, 2, Sqrt[-9 - 4*x^2]/(18*x^2) - (2/27)*ArcTan[(1/3)*Sqrt[-9 - 4*x^2]]}
{1/(x^4*Sqrt[-9 - 4*x^2]), x, 2, Sqrt[-9 - 4*x^2]/(27*x^3) - (8*Sqrt[-9 - 4*x^2])/(243*x)}
{1/(x^5*Sqrt[-9 - 4*x^2]), x, 3, Sqrt[-9 - 4*x^2]/(36*x^4) - Sqrt[-9 - 4*x^2]/(54*x^2) + (2/81)*ArcTan[(1/3)*Sqrt[-9 - 4*x^2]]}

{x^5/(-9 - 4*x^2)^(3/2), x, 4, x^4/(4*Sqrt[-9 - 4*x^2]) - (3/8)*Sqrt[-9 - 4*x^2] + (1/12)*x^2*Sqrt[-9 - 4*x^2]}
{x^4/(-9 - 4*x^2)^(3/2), x, 3, x^3/(4*Sqrt[-9 - 4*x^2]) + (3/32)*x*Sqrt[-9 - 4*x^2] + (27/64)*ArcTan[(2*x)/Sqrt[-9 - 4*x^2]]}
{x^3/(-9 - 4*x^2)^(3/2), x, 3, x^2/(4*Sqrt[-9 - 4*x^2]) + (1/8)*Sqrt[-9 - 4*x^2]}
{x^2/(-9 - 4*x^2)^(3/2), x, 2, x/(4*Sqrt[-9 - 4*x^2]) - (1/8)*ArcTan[(2*x)/Sqrt[-9 - 4*x^2]]}
{x/(-9 - 4*x^2)^(3/2), x, 2, 1/(4*Sqrt[-9 - 4*x^2])}
{(-9 - 4*x^2)^(-3/2), x, 1, -x/(9*Sqrt[-9 - 4*x^2])}
{1/(x*(-9 - 4*x^2)^(3/2)), x, 2, -(1/(9*Sqrt[-9 - 4*x^2])) - (1/27)*ArcTan[(1/3)*Sqrt[-9 - 4*x^2]]}
{1/(x^2*(-9 - 4*x^2)^(3/2)), x, 2, -(1/(9*x*Sqrt[-9 - 4*x^2])) - (2*Sqrt[-9 - 4*x^2])/(81*x)}
{1/(x^3*(-9 - 4*x^2)^(3/2)), x, 3, -(1/(9*x^2*Sqrt[-9 - 4*x^2])) - Sqrt[-9 - 4*x^2]/(54*x^2) + (2/81)*ArcTan[(1/3)*Sqrt[-9 - 4*x^2]]}
{1/(x^4*(-9 - 4*x^2)^(3/2)), x, 3, -(1/(9*x^3*Sqrt[-9 - 4*x^2])) - (4*Sqrt[-9 - 4*x^2])/(243*x^3) + (32*Sqrt[-9 - 4*x^2])/(2187*x)}
{1/(x^5*(-9 - 4*x^2)^(3/2)), x, 4, -(1/(9*x^4*Sqrt[-9 - 4*x^2])) - (5*Sqrt[-9 - 4*x^2])/(324*x^4) + (5*Sqrt[-9 - 4*x^2])/(486*x^2) - (10/729)*ArcTan[(1/3)*Sqrt[-9 - 4*x^2]]}

{x^5/(-9 - 4*x^2)^(5/2), x, 4, x^4/(12*(-9 - 4*x^2)^(3/2)) - x^2/(12*Sqrt[-9 - 4*x^2]) - (1/24)*Sqrt[-9 - 4*x^2]}
{x^4/(-9 - 4*x^2)^(5/2), x, 3, x^3/(12*(-9 - 4*x^2)^(3/2)) - x/(16*Sqrt[-9 - 4*x^2]) + (1/32)*ArcTan[(2*x)/Sqrt[-9 - 4*x^2]]}
{x^3/(-9 - 4*x^2)^(5/2), x, 3, x^2/(12*(-9 - 4*x^2)^(3/2)) - 1/(24*Sqrt[-9 - 4*x^2])}
{x^2/(-9 - 4*x^2)^(5/2), x, 1, -x^3/(27*(-9 - 4*x^2)^(3/2))}
{x/(-9 - 4*x^2)^(5/2), x, 2, 1/(12*(-9 - 4*x^2)^(3/2))}
{1/(-9 - 4*x^2)^(5/2), x, 2, -(x/(27*(-9 - 4*x^2)^(3/2))) + (2*x)/(243*Sqrt[-9 - 4*x^2])}
{1/(x*(-9 - 4*x^2)^(5/2)), x, 3, -(1/(27*(-9 - 4*x^2)^(3/2))) + 1/(81*Sqrt[-9 - 4*x^2]) + (1/243)*ArcTan[(1/3)*Sqrt[-9 - 4*x^2]]}
{1/(x^2*(-9 - 4*x^2)^(5/2)), x, 3, -(1/(27*x*(-9 - 4*x^2)^(3/2))) + 4/(243*x*Sqrt[-9 - 4*x^2]) + (8*Sqrt[-9 - 4*x^2])/(2187*x)}
{1/(x^3*(-9 - 4*x^2)^(5/2)), x, 4, -(1/(27*x^2*(-9 - 4*x^2)^(3/2))) + 5/(243*x^2*Sqrt[-9 - 4*x^2]) + (5*Sqrt[-9 - 4*x^2])/(1458*x^2) - (10*ArcTan[(1/3)*Sqrt[-9 - 4*x^2]])/2187}
{1/(x^4*(-9 - 4*x^2)^(5/2)), x, 4, -(1/(27*x^3*(-9 - 4*x^2)^(3/2))) + 2/(81*x^3*Sqrt[-9 - 4*x^2]) + (8*Sqrt[-9 - 4*x^2])/(2187*x^3) - (64*Sqrt[-9 - 4*x^2])/(19683*x)}
{1/(x^5*(-9 - 4*x^2)^(5/2)), x, 5, -(1/(27*x^4*(-9 - 4*x^2)^(3/2))) + 7/(243*x^4*Sqrt[-9 - 4*x^2]) + (35*Sqrt[-9 - 4*x^2])/(8748*x^4) - (35*Sqrt[-9 - 4*x^2])/(13122*x^2) + (70*ArcTan[(1/3)*Sqrt[-9 - 4*x^2]])/19683}


(* ::Subsubsection::Closed:: *)
(*Integrands of the form (a+b x^2)^m (c+d x^2)^n*)


{1/((b*c/d + b*x^2)*Sqrt[c + d*x^2]), x, 2, (d*x)/(b*c*Sqrt[c + d*x^2])}
{1/((a + b*x^2)*Sqrt[c + d*x^2]), x, 1, ArcTan[(Sqrt[b*c - a*d]*x)/(Sqrt[a]*Sqrt[c + d*x^2])]/(Sqrt[a]*Sqrt[b*c - a*d])}


{1/(Sqrt[2 + b*x^2]*Sqrt[3 + d*x^2]), x, 1, EllipticF[ArcSin[(Sqrt[-d]*x)/Sqrt[3]], (3*b)/(2*d)]/(Sqrt[2]*Sqrt[-d])}
{1/(Sqrt[a + b*x^2]*Sqrt[c + d*x^2]), x, 2, (Sqrt[c]*Sqrt[(a + b*x^2)/a]*Sqrt[(c + d*x^2)/c]*EllipticF[ArcSin[(Sqrt[-d]*x)/Sqrt[c]], (b*c)/(a*d)])/(Sqrt[-d]*Sqrt[a + b*x^2]*Sqrt[c + d*x^2])}
{1/(Sqrt[4 - x^2]*Sqrt[c + d*x^2]), x, 2, (Sqrt[(c + d*x^2)/c]*EllipticF[ArcSin[x/2], -((4*d)/c)])/Sqrt[c + d*x^2]}
{1/(Sqrt[4 + x^2]*Sqrt[c + d*x^2]), x, 2, -((I*Sqrt[(c + d*x^2)/c]*EllipticF[I*ArcSinh[x/2], (4*d)/c])/Sqrt[c + d*x^2])}

{1/(Sqrt[1 - x^2]*Sqrt[2 + 3*x^2]), x, 1, EllipticF[ArcSin[x], -(3/2)]/Sqrt[2]}
{1/(Sqrt[1 - x^2]*Sqrt[2 - 3*x^2]), x, 1, EllipticF[ArcSin[x], 3/2]/Sqrt[2]}
{1/(Sqrt[4 - x^2]*Sqrt[2 + 3*x^2]), x, 1, EllipticF[ArcSin[x/2], -6]/Sqrt[2]}
{1/(Sqrt[4 - x^2]*Sqrt[2 - 3*x^2]), x, 1, EllipticF[ArcSin[x/2], 6]/Sqrt[2]}
{1/(Sqrt[1 - 4*x^2]*Sqrt[2 + 3*x^2]), x, 1, EllipticF[ArcSin[2*x], -(3/8)]/(2*Sqrt[2])}
{1/(Sqrt[1 - 4*x^2]*Sqrt[2 - 3*x^2]), x, 1, EllipticF[ArcSin[2*x], 3/8]/(2*Sqrt[2])}

{1/(Sqrt[1 + x^2]*Sqrt[2 + 3*x^2]), x, 1, -((I*EllipticF[I*ArcSinh[x], 3/2])/Sqrt[2])}
{1/(Sqrt[1 + x^2]*Sqrt[2 - 3*x^2]), x, 1, EllipticF[ArcSin[Sqrt[3/2]*x], -(2/3)]/Sqrt[3]}
{1/(Sqrt[4 + x^2]*Sqrt[2 + 3*x^2]), x, 1, -((I*EllipticF[I*ArcSinh[x/2], 6])/Sqrt[2])}
{1/(Sqrt[4 + x^2]*Sqrt[2 - 3*x^2]), x, 1, EllipticF[ArcSin[Sqrt[3/2]*x], -(1/6)]/(2*Sqrt[3])}
{1/(Sqrt[1 + 4*x^2]*Sqrt[2 + 3*x^2]), x, 1, -((I*EllipticF[I*ArcSinh[2*x], 3/8])/(2*Sqrt[2]))}
{1/(Sqrt[1 + 4*x^2]*Sqrt[2 - 3*x^2]), x, 1, EllipticF[ArcSin[Sqrt[3/2]*x], -(8/3)]/Sqrt[3]}

{1/(Sqrt[1 - x^2]*Sqrt[-1 + 2*x^2]), x, -2, -EllipticF[ArcCos[x], 2]}


{Sqrt[2 + b*x^2]/Sqrt[3 + d*x^2], x, 1, (Sqrt[2]*EllipticE[ArcSin[(Sqrt[-d]*x)/Sqrt[3]], (3*b)/(2*d)])/Sqrt[-d]}
{Sqrt[a + b*x^2]/Sqrt[c + d*x^2], x, 2, (Sqrt[c]*Sqrt[a + b*x^2]*Sqrt[(c + d*x^2)/c]*EllipticE[ArcSin[(Sqrt[-d]*x)/Sqrt[c]], (b*c)/(a*d)])/(Sqrt[-d]*Sqrt[(a + b*x^2)/a]*Sqrt[c + d*x^2])}
{Sqrt[-1 + 3*x^2]/Sqrt[2 - 3*x^2], x, 2, (Sqrt[-1 + 3*x^2]*EllipticE[ArcSin[Sqrt[3/2]*x], 2])/(Sqrt[3]*Sqrt[1 - 3*x^2])}


{Sqrt[2 + b*x^2]*Sqrt[3 + d*x^2], x, 3, (1/3)*x*Sqrt[2 + b*x^2]*Sqrt[3 + d*x^2] + ((3*b + 2*d)*EllipticE[ArcSin[(Sqrt[-b]*x)/Sqrt[2]], (2*d)/(3*b)])/(Sqrt[3]*Sqrt[-b]*d) + ((3*b - 2*d)*EllipticF[ArcSin[(Sqrt[-d]*x)/Sqrt[3]], (3*b)/(2*d)])/(Sqrt[2]*(-d)^(3/2))}
{Sqrt[a + b*x^2]*Sqrt[c + d*x^2], x, 5, (1/3)*x*Sqrt[a + b*x^2]*Sqrt[c + d*x^2] + (Sqrt[a]*(b*c + a*d)*Sqrt[(a + b*x^2)/a]*Sqrt[c + d*x^2]*EllipticE[ArcSin[(Sqrt[-b]*x)/Sqrt[a]], (a*d)/(b*c)])/(3*Sqrt[-b]*d*Sqrt[a + b*x^2]*Sqrt[(c + d*x^2)/c]) + (c^(3/2)*(b*c - a*d)*Sqrt[(a + b*x^2)/a]*Sqrt[(c + d*x^2)/c]*EllipticF[ArcSin[(Sqrt[-d]*x)/Sqrt[c]], (b*c)/(a*d)])/(3*(-d)^(3/2)*Sqrt[a + b*x^2]*Sqrt[c + d*x^2])}
{Sqrt[2 + 4*x^2]*Sqrt[3 - 6*x^2], x, 3, Sqrt[2/3]*x*Sqrt[1 - 4*x^4] + (2*EllipticF[ArcSin[Sqrt[2]*x], -1])/Sqrt[3]}
{Sqrt[2 + 4*x^2]*Sqrt[3 + 6*x^2], x, 2, Sqrt[6]*x + 2*Sqrt[2/3]*x^3}


(* ::Subsubsection::Closed:: *)
(*Integrands of the form (a+b x^2)^m (c+d x^2)^n (e+f x^2)^p*)


{1/((a + b*x^2)*Sqrt[2 + d*x^2]*Sqrt[3 + f*x^2]), x, 1, EllipticPi[(2*b)/(a*d), ArcSin[(Sqrt[-d]*x)/Sqrt[2]], (2*f)/(3*d)]/(Sqrt[3]*a*Sqrt[-d])}
{1/((a + b*x^2)*Sqrt[c + d*x^2]*Sqrt[e + f*x^2]), x, 2, (Sqrt[c]*Sqrt[(c + d*x^2)/c]*Sqrt[(e + f*x^2)/e]*EllipticPi[(b*c)/(a*d), ArcSin[(Sqrt[-d]*x)/Sqrt[c]], (c*f)/(d*e)])/(a*Sqrt[-d]*Sqrt[c + d*x^2]*Sqrt[e + f*x^2])}


{Sqrt[2 + f*x^2]/((a + b*x^2)*Sqrt[3 + d*x^2]), x, 3, -((Sqrt[-f]*EllipticF[ArcSin[(Sqrt[-f]*x)/Sqrt[2]], (2*d)/(3*f)])/(Sqrt[3]*b)) + ((2*b - a*f)*EllipticPi[(3*b)/(a*d), ArcSin[(Sqrt[-d]*x)/Sqrt[3]], (3*f)/(2*d)])/(Sqrt[2]*a*b*Sqrt[-d])}
{Sqrt[e + f*x^2]/((a + b*x^2)*Sqrt[c + d*x^2]), x, 5, -((Sqrt[e]*Sqrt[-f]*Sqrt[(c + d*x^2)/c]*Sqrt[(e + f*x^2)/e]*EllipticF[ArcSin[(Sqrt[-f]*x)/Sqrt[e]], (d*e)/(c*f)])/(b*Sqrt[c + d*x^2]*Sqrt[e + f*x^2])) + (Sqrt[c]*(b*e - a*f)*Sqrt[(c + d*x^2)/c]*Sqrt[(e + f*x^2)/e]*EllipticPi[(b*c)/(a*d), ArcSin[(Sqrt[-d]*x)/Sqrt[c]], (c*f)/(d*e)])/(a*b*Sqrt[-d]*Sqrt[c + d*x^2]*Sqrt[e + f*x^2])}

{Sqrt[1 - x^2]/((x^2 - 1)*Sqrt[a + b*x^2]), x, 3, -((Sqrt[(a + b*x^2)/a]*EllipticF[ArcSin[x], -(b/a)])/Sqrt[a + b*x^2])}


{Sqrt[2 + d*x^2]*Sqrt[3 + f*x^2]/(a + b*x^2), x, 5, -((Sqrt[3]*Sqrt[-d]*EllipticE[ArcSin[(Sqrt[-d]*x)/Sqrt[2]], (2*f)/(3*d)])/b) - ((2*b - a*d)*Sqrt[-f]*EllipticF[ArcSin[(Sqrt[-f]*x)/Sqrt[3]], (3*d)/(2*f)])/(Sqrt[2]*b^2) + ((2*b - a*d)*(3*b - a*f)*EllipticPi[(2*b)/(a*d), ArcSin[(Sqrt[-d]*x)/Sqrt[2]], (2*f)/(3*d)])/(Sqrt[3]*a*b^2*Sqrt[-d])}
{Sqrt[c + d*x^2]*Sqrt[e + f*x^2]/(a + b*x^2), x, 8, -((Sqrt[c]*Sqrt[-d]*Sqrt[(c + d*x^2)/c]*Sqrt[e + f*x^2]*EllipticE[ArcSin[(Sqrt[-d]*x)/Sqrt[c]], (c*f)/(d*e)])/(b*Sqrt[c + d*x^2]*Sqrt[(e + f*x^2)/e])) - ((b*c - a*d)*Sqrt[e]*Sqrt[-f]*Sqrt[(c + d*x^2)/c]*Sqrt[(e + f*x^2)/e]*EllipticF[ArcSin[(Sqrt[-f]*x)/Sqrt[e]], (d*e)/(c*f)])/(b^2*Sqrt[c + d*x^2]*Sqrt[e + f*x^2]) + (Sqrt[c]*(b*c - a*d)*(b*e - a*f)*Sqrt[(c + d*x^2)/c]*Sqrt[(e + f*x^2)/e]*EllipticPi[(b*c)/(a*d), ArcSin[(Sqrt[-d]*x)/Sqrt[c]], (c*f)/(d*e)])/(a*b^2*Sqrt[-d]*Sqrt[c + d*x^2]*Sqrt[e + f*x^2])}


{(a + b*x^2)/(Sqrt[2 + d*x^2]*Sqrt[3 + f*x^2]), x, 3, (Sqrt[2]*b*EllipticE[ArcSin[(Sqrt[-f]*x)/Sqrt[3]], (3*d)/(2*f)])/(d*Sqrt[-f]) - ((2*b - a*d)*EllipticF[ArcSin[(Sqrt[-f]*x)/Sqrt[3]], (3*d)/(2*f)])/(Sqrt[2]*d*Sqrt[-f])}
{(a + b*x^2)/(Sqrt[c + d*x^2]*Sqrt[e + f*x^2]), x, 5, (b*Sqrt[e]*Sqrt[c + d*x^2]*Sqrt[(e + f*x^2)/e]*EllipticE[ArcSin[(Sqrt[-f]*x)/Sqrt[e]], (d*e)/(c*f)])/(d*Sqrt[-f]*Sqrt[(c + d*x^2)/c]*Sqrt[e + f*x^2]) - ((b*c - a*d)*Sqrt[e]*Sqrt[(c + d*x^2)/c]*Sqrt[(e + f*x^2)/e]*EllipticF[ArcSin[(Sqrt[-f]*x)/Sqrt[e]], (d*e)/(c*f)])/(d*Sqrt[-f]*Sqrt[c + d*x^2]*Sqrt[e + f*x^2])}


{(a + b*x^2)*Sqrt[2 + d*x^2]/Sqrt[3 + f*x^2], x, 7, (b*x*Sqrt[2 + d*x^2]*Sqrt[3 + f*x^2])/(3*f) + (Sqrt[2]*(6*b*d - 2*b*f - 3*a*d*f)*EllipticE[ArcSin[(Sqrt[-f]*x)/Sqrt[3]], (3*d)/(2*f)])/(3*d*(-f)^(3/2)) - (Sqrt[2]*b*(3*d - 2*f)*EllipticF[ArcSin[(Sqrt[-f]*x)/Sqrt[3]], (3*d)/(2*f)])/(3*d*(-f)^(3/2))}
{(a + b*x^2)*Sqrt[c + d*x^2]/Sqrt[e + f*x^2], x, 10, (b*x*Sqrt[c + d*x^2]*Sqrt[e + f*x^2])/(3*f) + (Sqrt[e]*(2*b*d*e - b*c*f - 3*a*d*f)*Sqrt[c + d*x^2]*Sqrt[1 + (f*x^2)/e]*EllipticE[ArcSin[(Sqrt[-f]*x)/Sqrt[e]], (d*e)/(c*f)])/(3*d*(-f)^(3/2)*Sqrt[1 + (d*x^2)/c]*Sqrt[e + f*x^2]) - (b*c*Sqrt[e]*(d*e - c*f)*Sqrt[(c + d*x^2)/c]*Sqrt[(e + f*x^2)/e]*EllipticF[ArcSin[(Sqrt[-f]*x)/Sqrt[e]], (d*e)/(c*f)])/(3*d*(-f)^(3/2)*Sqrt[c + d*x^2]*Sqrt[e + f*x^2])}


{(a + b*x^2)*Sqrt[2 + d*x^2]*Sqrt[3 + f*x^2], x, -5, 0}
{(a + b*x^2)*Sqrt[c + d*x^2]*Sqrt[e + f*x^2], x, -7, 0}


(* ::Subsubsection::Closed:: *)
(*Integrands of the form x^m (a + b x^2)^(n/2) (c + d x^2)^(p/2)*)


(* Integrands of the form x^m/(Sqrt[a+b*x^2]*Sqrt[c+d*x^2]) where m is an integer *)
{x/(Sqrt[2 + b*x^2]*Sqrt[3 + d*x^2]), x, 2, ArcTanh[(Sqrt[d]*Sqrt[2 + b*x^2])/(Sqrt[b]*Sqrt[3 + d*x^2])]/(Sqrt[b]*Sqrt[d])}
{x^2/(Sqrt[2 + b*x^2]*Sqrt[3 + d*x^2]), x, 3, (Sqrt[2]*EllipticE[ArcSin[(Sqrt[-d]*x)/Sqrt[3]], (3*b)/(2*d)])/(b*Sqrt[-d]) - (Sqrt[2]*EllipticF[ArcSin[(Sqrt[-d]*x)/Sqrt[3]], (3*b)/(2*d)])/(b*Sqrt[-d])}

{x/(Sqrt[4 - x^2]*Sqrt[c + d*x^2]), x, 2, -(ArcTan[(Sqrt[d]*Sqrt[4 - x^2])/Sqrt[c + d*x^2]]/Sqrt[d])}
{x^2/(Sqrt[4 - x^2]*Sqrt[c + d*x^2]), x, 5, (Sqrt[c + d*x^2]*EllipticE[ArcSin[x/2], -((4*d)/c)])/(d*Sqrt[(c + d*x^2)/c]) - (c*Sqrt[(c + d*x^2)/c]*EllipticF[ArcSin[x/2], -((4*d)/c)])/(d*Sqrt[c + d*x^2])}

{x/(Sqrt[4 + x^2]*Sqrt[c + d*x^2]), x, 2, ArcTanh[(Sqrt[d]*Sqrt[4 + x^2])/Sqrt[c + d*x^2]]/Sqrt[d]}
{x^2/(Sqrt[4 + x^2]*Sqrt[c + d*x^2]), x, 5, -((I*Sqrt[c + d*x^2]*EllipticE[I*ArcSinh[x/2], (4*d)/c])/(d*Sqrt[(c + d*x^2)/c])) + (I*c*Sqrt[(c + d*x^2)/c]*EllipticF[I*ArcSinh[x/2], (4*d)/c])/(d*Sqrt[c + d*x^2])}

{x/(Sqrt[a + b*x^2]*Sqrt[c + d*x^2]), x, 2, ArcTanh[(Sqrt[d]*Sqrt[a + b*x^2])/(Sqrt[b]*Sqrt[c + d*x^2])]/(Sqrt[b]*Sqrt[d])}
{x^2/(Sqrt[a + b*x^2]*Sqrt[c + d*x^2]), x, 5, (Sqrt[c]*Sqrt[a + b*x^2]*Sqrt[(c + d*x^2)/c]*EllipticE[ArcSin[(Sqrt[-d]*x)/Sqrt[c]], (b*c)/(a*d)])/(b*Sqrt[-d]*Sqrt[(a + b*x^2)/a]*Sqrt[c + d*x^2]) - (a*Sqrt[c]*Sqrt[(a + b*x^2)/a]*Sqrt[(c + d*x^2)/c]*EllipticF[ArcSin[(Sqrt[-d]*x)/Sqrt[c]], (b*c)/(a*d)])/(b*Sqrt[-d]*Sqrt[a + b*x^2]*Sqrt[c + d*x^2])}


(* Integrands of the form x^m*Sqrt[a+b*x^2]/Sqrt[c+d*x^2] where m is an integer *)
{x*Sqrt[2 + b*x^2]/Sqrt[3 + d*x^2], x, 3, (Sqrt[2 + b*x^2]*Sqrt[3 + d*x^2])/(2*d) - ((3*b - 2*d)*ArcTanh[(Sqrt[d]*Sqrt[2 + b*x^2])/(Sqrt[b]*Sqrt[3 + d*x^2])])/(2*Sqrt[b]*d^(3/2))}
{x^2*Sqrt[2 + b*x^2]/Sqrt[3 + d*x^2], x, 4, (x*Sqrt[2 + b*x^2]*Sqrt[3 + d*x^2])/(3*d) + (2*Sqrt[2]*(3*b - d)*EllipticE[ArcSin[(Sqrt[-d]*x)/Sqrt[3]], (3*b)/(2*d)])/(3*b*(-d)^(3/2)) - (Sqrt[2]*(3*b - 2*d)*EllipticF[ArcSin[(Sqrt[-d]*x)/Sqrt[3]], (3*b)/(2*d)])/(3*b*(-d)^(3/2))}

{x*Sqrt[-1 + 3*x^2]/Sqrt[2 - 3*x^2], x, 3, (-(1/6))*Sqrt[2 - 3*x^2]*Sqrt[-1 + 3*x^2] - (1/12)*ArcSin[3 - 6*x^2]}
{x^2*Sqrt[-1 + 3*x^2]/Sqrt[2 - 3*x^2], x, 6, (-(1/9))*x*Sqrt[2 - 3*x^2]*Sqrt[-1 + 3*x^2] - (Sqrt[2/3]*Sqrt[1 - 3*x^2]*EllipticE[ArcSin[Sqrt[3]*x], 1/2])/(3*Sqrt[-1 + 3*x^2]) + (4*Sqrt[1 - 3*x^2]*EllipticF[ArcSin[Sqrt[3/2]*x], 2])/(9*Sqrt[3]*Sqrt[-1 + 3*x^2])}
{x^3*Sqrt[-1 + 3*x^2]/Sqrt[2 - 3*x^2], x, 5, (-(5/72))*Sqrt[2 - 3*x^2]*Sqrt[-1 + 3*x^2] - (1/12)*x^2*Sqrt[2 - 3*x^2]*Sqrt[-1 + 3*x^2] - (7/144)*ArcSin[3 - 6*x^2]}
{x^4*Sqrt[-1 + 3*x^2]/Sqrt[2 - 3*x^2], x, -1, 0}

{x*Sqrt[a + b*x^2]/Sqrt[c + d*x^2], x, 3, (Sqrt[a + b*x^2]*Sqrt[c + d*x^2])/(2*d) - ((b*c - a*d)*ArcTanh[(Sqrt[d]*Sqrt[a + b*x^2])/(Sqrt[b]*Sqrt[c + d*x^2])])/(2*Sqrt[b]*d^(3/2))}
{x^2*Sqrt[a + b*x^2]/Sqrt[c + d*x^2], x, 6, (x*Sqrt[a + b*x^2]*Sqrt[c + d*x^2])/(3*d) + (Sqrt[c]*(2*b*c - a*d)*Sqrt[a + b*x^2]*Sqrt[(c + d*x^2)/c]*EllipticE[ArcSin[(Sqrt[-d]*x)/Sqrt[c]], (b*c)/(a*d)])/(3*b*(-d)^(3/2)*Sqrt[(a + b*x^2)/a]*Sqrt[c + d*x^2]) - (a*Sqrt[c]*(b*c - a*d)*Sqrt[(a + b*x^2)/a]*Sqrt[(c + d*x^2)/c]*EllipticF[ArcSin[(Sqrt[-d]*x)/Sqrt[c]], (b*c)/(a*d)])/(3*b*(-d)^(3/2)*Sqrt[a + b*x^2]*Sqrt[c + d*x^2])}


(* ::Subsubsection::Closed:: *)
(*Miscellaneous integrands involving quadratic binomials*)


{1/(Sqrt[-1 + x]*Sqrt[1 + x]*Sqrt[-1 + 2*x^2]), x, -7, (-I)*EllipticF[I*ArcCosh[x], 2]}


{1/(x^3*Sqrt[1 - a^2*x^2]), x, 2, -(Sqrt[1 - a^2*x^2]/(2*x^2)) - (1/2)*a^2*ArcTanh[Sqrt[1 - a^2*x^2]]}


(* Integrands of the form (a+b*x)^m*(c+d*x^2)^n where m is an integer and n is a half-integer *)
{(1 - x)/Sqrt[1 - x^2], x, 2, Sqrt[1 - x^2] + ArcSin[x]}
{(1 + x)/Sqrt[1 - x^2], x, 2, -Sqrt[1 - x^2] + ArcSin[x]}
{(3 + x)/Sqrt[1 - x^2], x, 2, -Sqrt[1 - x^2] + 3*ArcSin[x]}
{(1 + x)/Sqrt[4 - x^2], x, 2, -Sqrt[4 - x^2] + ArcSin[x/2]}
{(2 + x)/Sqrt[9 + x^2], x, 2, Sqrt[9 + x^2] + 2*ArcSinh[x/3]}

{1/((1 + x)*Sqrt[1 - x^2]), x, 1, -(Sqrt[1 - x^2]/(1 + x))}
{1/((a + b*x)*Sqrt[c + d*x^2]), x, 1, -(ArcTanh[(b*c - a*d*x)/(Sqrt[b^2*c + a^2*d]*Sqrt[c + d*x^2])]/Sqrt[b^2*c + a^2*d])}
{1/((a + b*x)*Sqrt[-c + d*x^2]), x, 1, -(ArcTan[(b*c + a*d*x)/(Sqrt[b^2*c - a^2*d]*Sqrt[-c + d*x^2])]/Sqrt[b^2*c - a^2*d])}

{Sqrt[a^2 - x^2]/(a - x), x, 4, -Sqrt[a^2 - x^2] + a*ArcTan[x/Sqrt[a^2 - x^2]]}
{Sqrt[2 + x^2]/(1 + 4*x), x, 6, Sqrt[2 + x^2]/4 - (1/16)*ArcSinh[x/Sqrt[2]] - (1/8)*Sqrt[33]*ArcTanh[(1 + 4*(x + Sqrt[2 + x^2]))/Sqrt[33]], 1/(4*(x + Sqrt[2 + x^2])) + (1/8)*(x + Sqrt[2 + x^2]) - (1/8)*Sqrt[33]*ArcTanh[(1 + 4*(x + Sqrt[2 + x^2]))/Sqrt[33]] - (1/16)*Log[x + Sqrt[2 + x^2]]}
{Sqrt[2 + 4*x^2]/(5 + 4*x), x, 6, (1/4)*Sqrt[2 + 4*x^2] - (5/8)*ArcSinh[Sqrt[2]*x] - (1/4)*Sqrt[33]*ArcTanh[(5 + 4*x + 2*Sqrt[2 + 4*x^2])/Sqrt[33]], 1/(4*(2*x + Sqrt[2]*Sqrt[1 + 2*x^2])) + (1/8)*(2*x + Sqrt[2]*Sqrt[1 + 2*x^2]) - (1/4)*Sqrt[33]*ArcTanh[(5 + 4*x + 2*Sqrt[2]*Sqrt[1 + 2*x^2])/Sqrt[33]] - (5/8)*Log[2*x + Sqrt[2]*Sqrt[1 + 2*x^2]]}
{Sqrt[1 - x^2]/(1 + x), x, 4, Sqrt[1 - x^2] + ArcSin[x]}
{Sqrt[1 - x^2]/(-1 + x), x, 4, Sqrt[1 - x^2] - ArcSin[x]}

{Sqrt[1 - x^2]/(-1 + x)^2, x, 5, Sqrt[1 - x^2] + (1 - x^2)^(3/2)/(1 - x)^2 - ArcSin[x]}
{Sqrt[c + d*x^2]/(a + b*x)^2, x, -9, -(Sqrt[c + d*x^2]/(b*(a + b*x))) + (2*a*d*ArcTanh[(a*Sqrt[d] + b*(Sqrt[d]*x + Sqrt[c + d*x^2]))/Sqrt[b^2*c + a^2*d]])/(b^2*Sqrt[b^2*c + a^2*d]) + (Sqrt[d] + Sqrt[d]*Log[Sqrt[d]*x + Sqrt[c + d*x^2]])/b^2}

{Sqrt[1 - x^2]/(-1 + x)^3, x, 1, -((1 - x^2)^(3/2)/(3*(1 - x)^3))}

{(1 + x)*Sqrt[-1 + x^2], x, 3, (1/2)*x*Sqrt[-1 + x^2] + (1/3)*(-1 + x^2)^(3/2) - (1/2)*ArcTanh[x/Sqrt[-1 + x^2]]}
{(2 + 3*x)*Sqrt[-5 + 7*x^2], x, 3, x*Sqrt[-5 + 7*x^2] + (1/7)*(-5 + 7*x^2)^(3/2) - (5*ArcTanh[(Sqrt[7]*x)/Sqrt[-5 + 7*x^2]])/Sqrt[7]}


{(a + b*x)^2*Sqrt[-((a^2*c)/b^2) + c*x^2], x, 4, (5/8)*a^2*x*Sqrt[-((a^2*c)/b^2) + c*x^2] + (2*a*b*(-((a^2*c)/b^2) + c*x^2)^(3/2))/(3*c) + (b^2*x*(-((a^2*c)/b^2) + c*x^2)^(3/2))/(4*c) - (5*a^4*Sqrt[c]*ArcTanh[(Sqrt[c]*x)/Sqrt[-((a^2*c)/b^2) + c*x^2]])/(8*b^2)}
{(a + b*x)^3*Sqrt[-((a^2*c)/b^2) + c*x^2], x, 5, (7/8)*a^3*x*Sqrt[-((a^2*c)/b^2) + c*x^2] + (14*a^2*b*(-((a^2*c)/b^2) + c*x^2)^(3/2))/(15*c) + (7*a*b^2*x*(-((a^2*c)/b^2) + c*x^2)^(3/2))/(20*c) + (b*(a + b*x)^2*(-((a^2*c)/b^2) + c*x^2)^(3/2))/(5*c) - (7*a^5*Sqrt[c]*ArcTanh[(Sqrt[c]*x)/Sqrt[-((a^2*c)/b^2) + c*x^2]])/(8*b^2)}

{(a + b*x)^2/Sqrt[1 - x^2], x, 7, -2*a*b*Sqrt[1 - x^2] - (1/2)*b^2*x*Sqrt[1 - x^2] + a^2*ArcSin[x] + (1/2)*b^2*ArcSin[x]}
{x^2/Sqrt[1 - (a + b*x)^2], x, 5, (3*a*Sqrt[1 - a^2 - 2*a*b*x - b^2*x^2])/(2*b^3) - (x*Sqrt[1 - a^2 - 2*a*b*x - b^2*x^2])/(2*b^2) + ArcSin[a + b*x]/(2*b^3) + (a^2*ArcSin[a + b*x])/b^3}

{(a + b*x)^2/Sqrt[1 + x^2], x, 7, 2*a*b*Sqrt[1 + x^2] + (1/2)*b^2*x*Sqrt[1 + x^2] + a^2*ArcSinh[x] - (1/2)*b^2*ArcSinh[x]}
{x^2/Sqrt[1 + (a + b*x)^2], x, 5, -((3*a*Sqrt[1 + a^2 + 2*a*b*x + b^2*x^2])/(2*b^3)) + (x*Sqrt[1 + a^2 + 2*a*b*x + b^2*x^2])/(2*b^2) - ArcSinh[a + b*x]/(2*b^3) + (a^2*ArcSinh[a + b*x])/b^3}


(* Integrands of the form x^m/(a*x+b*Sqrt[c+d*x^2]) where m is an integer *)
{1/(x - Sqrt[1 + x^2]), x, 4, -(x^2/2) - (1/2)*x*Sqrt[1 + x^2] - ArcSinh[x]/2}
{1/(x - Sqrt[1 - x^2]), x, 6, -(ArcSin[x]/2) - (1/2)*ArcTanh[x/Sqrt[1 - x^2]] + (1/4)*Log[1 - 2*x^2]}
{1/(x - Sqrt[1 + 2*x^2]), x, 7, -(Sqrt[2]*ArcSinh[Sqrt[2]*x]) + ArcTanh[x/Sqrt[1 + 2*x^2]] - Log[1 + x^2]/2}

{x/(x - Sqrt[1 + x^2]), x, 4, -(x^3/3) - (1/3)*(1 + x^2)^(3/2)}
{x/(x - Sqrt[1 - x^2]), x, 7, x/2 + Sqrt[1 - x^2]/2 - ArcTanh[Sqrt[2]*x]/(2*Sqrt[2]) - ArcTanh[Sqrt[2]*Sqrt[1 - x^2]]/(2*Sqrt[2])}
{x/(x - Sqrt[1 + 2*x^2]), x, 7, -x - Sqrt[1 + 2*x^2] + ArcTan[x] + ArcTan[Sqrt[1 + 2*x^2]]}


{(-1 + x^2)/(1 + x^2)^(3/2), x, 5, (-2*x)/Sqrt[1 + x^2] + ArcSinh[x]}
{1/(Sqrt[1 - x^2]*(1 + x^2)), x, 1, ArcTan[(Sqrt[2]*x)/Sqrt[1 - x^2]]/Sqrt[2]}
{Sqrt[1 - x^2]/(1 + x^2), x, 3, -ArcSin[x] + Sqrt[2]*ArcTan[(Sqrt[2]*x)/Sqrt[1 - x^2]]}
(* {Sqrt[1+x^2]/(1-x^3), x, 0} *)
{Sqrt[x - Sqrt[-4 + x^2]], x, 1, (2*Sqrt[x - Sqrt[-4 + x^2]]*(2*x + Sqrt[-4 + x^2]))/3}
{Sqrt[1 + Sqrt[1 - x^2]], x, 1, (2*(1 + x^2 - Sqrt[1 - x^2])*Sqrt[1 + Sqrt[1 - x^2]])/(3*x)}
{Sqrt[-1 + 4*x^2]/(x + Sqrt[-1 + 4*x^2]), x, 7, (4*x)/3 - (1/3)*Sqrt[-1 + 4*x^2] - ArcTanh[Sqrt[3]*x]/(3*Sqrt[3]) + ArcTanh[Sqrt[3]*Sqrt[-1 + 4*x^2]]/(3*Sqrt[3])}
{Sqrt[1 + 2*x^2]/(1 + Sqrt[1 + 2*x^2]), x, 5, -(1/(2*x)) + x + Sqrt[1 + 2*x^2]/(2*x) - ArcSinh[Sqrt[2]*x]/Sqrt[2]}
{(-1 + x)/(1 + Sqrt[1 + x^2]), x, 9, -x^(-1) + (1 + x^(-1))*Sqrt[1 + x^2] - ArcSinh[x] - Log[1 + Sqrt[1 + x^2]], -(1/x) + Sqrt[1 + x^2] + Sqrt[1 + x^2]/x - ArcSinh[x] - ArcTanh[Sqrt[1 + x^2]] - Log[x]}
{(-1 + x + x^2)/(1 + Sqrt[1 + x^2]), x, 11, -x^(-1) - x + (1 + x^(-1) + x/2)*Sqrt[1 + x^2] - ArcSinh[x]/2 - Log[1 + Sqrt[1 + x^2]], -x^(-1) - x + Sqrt[1 + x^2] + Sqrt[1 + x^2]/x + (x*Sqrt[1 + x^2])/2 - ArcSinh[x]/2 - ArcTanh[Sqrt[1 + x^2]] - Log[x]}
{(-1 + x + x^2)/(1 + x + Sqrt[1 + x^2]), x, 12, (6*x^2 + 2*x^3 + (4 - 3*x - 2*x^2)*Sqrt[1 + x^2] - 3*ArcSinh[x] - 6*Log[1 + Sqrt[1 + x^2]])/12, x^2/2 + x^3/6 + Sqrt[1 + x^2]/2 - (1/4)*x*Sqrt[1 + x^2] - (1/6)*(1 + x^2)^(3/2) - ArcSinh[x]/4 - (1/2)*ArcTanh[Sqrt[1 + x^2]] - Log[x]/2}
{((-5 - 4*x)*Sqrt[1 - x^2] + 3*(1 - x^2))^(-1), x, 4, 1/(2*(1 + (2*(1 - Sqrt[1 - x^2]))/x))}
{(x - x^2)/Sqrt[1 - x^2], x, 6, -Sqrt[1 - x^2] + (1/2)*x*Sqrt[1 - x^2] - ArcSin[x]/2}
{(-x + x^3)/Sqrt[-2 + x^2], x, 7, (1/3)*Sqrt[-2 + x^2] + (1/3)*x^2*Sqrt[-2 + x^2]}

{x*(-1 + x^2)^(7/3), x, 2, (3*(-1 + x^2)^(10/3))/20}
{x^3/(4 + x^2)^(1/3), x, 3, (-(9/5))*(4 + x^2)^(2/3) + (3/10)*x^2*(4 + x^2)^(2/3)}
{x*(1 + x^2)^(1/3), x, 2, (3*(1 + x^2)^(4/3))/8}
{x*(1 - x^2)^(1/3), x, 2, (-3*(1 - x^2)^(4/3))/8}
{(3*x)/(3 + 2*x^2)^(1/3), x, 3, (9*(3 + 2*x^2)^(2/3))/8}
{x^3*(1 + x^2)^(1/3), x, 3, (-(9/56))*(1 + x^2)^(4/3) + (3/14)*x^2*(1 + x^2)^(4/3)}
{x^3/(-1 + x^2)^(4/3), x, 3, -((3*x^2)/(2*(-1 + x^2)^(1/3))) + (9/4)*(-1 + x^2)^(2/3)}
{(2 + 3*x)/(4 + x^2)^(3/2), x, 2, -(3/Sqrt[4 + x^2]) + x/(2*Sqrt[4 + x^2])}
{x^(2/3)/(1 + x^2), x, 6, ArcTan[x^(1/3)] + (1/2)*ArcTan[x^(1/3)/(1 - x^(2/3))] - (1/2)*Sqrt[3]*ArcTanh[(Sqrt[3]*x^(1/3))/(1 + x^(2/3))]}
{x^3/(1 + x^2)^(1/3), x, 3, (-(9/20))*(1 + x^2)^(2/3) + (3/10)*x^2*(1 + x^2)^(2/3)}

{1/((1 + x)^(2/3)*(-1 + x^2)^(2/3)), x, 1, (3*(-1 + x^2)^(1/3))/(2*(1 + x)^(2/3))}
{1/((1 + x)*(-1 + x^2))^(2/3), x, 2, -((3*(1 - x^2))/(2*(-((1 + x)*(1 - x^2)))^(2/3)))}

{(x*Sqrt[1 - x^2])/(1 + x), x, 5, -Sqrt[1 - x^2] + (1/2)*x*Sqrt[1 - x^2] - ArcSin[x]/2}
{(x*(1 + x)^2)/Sqrt[1 - x^2], x, 9, (-(5/3))*Sqrt[1 - x^2] - x*Sqrt[1 - x^2] - (1/3)*x^2*Sqrt[1 - x^2] + ArcSin[x]}


(* ::Subsection::Closed:: *)
(*Integrands involving roots of cubic binomials*)


(* Integrands involving expressions of the form (a+b*x^3)^n where n is a fraction *)
{x^5/Sqrt[1 + x^3], x, 3, (-(4/9))*Sqrt[1 + x^3] + (2/9)*x^3*Sqrt[1 + x^3]}
{x^2/Sqrt[1 - x^3], x, 2, -2*Sqrt[1 - x^3]/3}
{1/(x*Sqrt[a + b*x^3]), x, 1, (-2*ArcTanh[Sqrt[a + b*x^3]/Sqrt[a]])/(3*Sqrt[a])}
{1/(x*Sqrt[-1 + x^3]), x, 1, (2*ArcTan[Sqrt[-1 + x^3]])/3}
{1/(x*Sqrt[1 - x^3]), x, 1, (-2*ArcTanh[Sqrt[1 - x^3]])/3}
{(3*x^5)/(1 + x^3)^(3/2), x, 4, -((2*x^3)/Sqrt[1 + x^3]) + 4*Sqrt[1 + x^3]}

{x^5*Sqrt[2 - x^3], x, 3, (-(8/45))*(2 - x^3)^(3/2) - (2/15)*x^3*(2 - x^3)^(3/2)}
{x^2*Sqrt[4 + 5*x^3], x, 2, (2*(4 + 5*x^3)^(3/2))/45}
{Sqrt[-2 + x^3]/x, x, 2, (2/3)*Sqrt[-2 + x^3] - (2/3)*Sqrt[2]*ArcTan[Sqrt[-2 + x^3]/Sqrt[2]]}

{x/(1 - x^3)^(2/3), x, 5, -(ArcTan[(1 - (2*x)/(1 - x^3)^(1/3))/Sqrt[3]]/Sqrt[3]) + (1/6)*Log[1 + x^2/(1 - x^3)^(2/3) - x/(1 - x^3)^(1/3)] - (1/3)*Log[1 + x/(1 - x^3)^(1/3)]}
{x*(1 - x^3)^(1/3), x, 6, (1/3)*x^2*(1 - x^3)^(1/3) - ArcTan[(1 - (2*x)/(1 - x^3)^(1/3))/Sqrt[3]]/(3*Sqrt[3]) + (1/18)*Log[1 + x^2/(1 - x^3)^(2/3) - x/(1 - x^3)^(1/3)] - (1/9)*Log[1 + x/(1 - x^3)^(1/3)]}
{x^2/(2 + x^3)^(1/4), x, 2, (4*(2 + x^3)^(3/4))/9}
{x^8*(1 - x^3)^(1/3), x, 4, (-(9/140))*(1 - x^3)^(4/3) - (3/35)*x^3*(1 - x^3)^(4/3) - (1/10)*x^6*(1 - x^3)^(4/3)}
{x^8*(1 - x^3)^(6/5), x, 4, -((125*(1 - x^3)^(11/5))/5544) - (25/504)*x^3*(1 - x^3)^(11/5) - (5/63)*x^6*(1 - x^3)^(11/5)}
{1/(x^3*(16 - x^3)^(1/3)), x, 1, -(16 - x^3)^(2/3)/(32*x^2)}
{1/(x^3*(-16 + x^3)^(1/3)), x, 1, (-16 + x^3)^(2/3)/(32*x^2)}
{x^5*Sqrt[1 - x^3]*(1 + x^9)^2, x, 4, (-(8/9))*(1 - x^3)^(3/2) + (32/15)*(1 - x^3)^(5/2) - (22/7)*(1 - x^3)^(7/2) + (86/27)*(1 - x^3)^(9/2) - (74/33)*(1 - x^3)^(11/2) + (14/13)*(1 - x^3)^(13/2) - (14/45)*(1 - x^3)^(15/2) + (2/51)*(1 - x^3)^(17/2)}


(* ::Subsection::Closed:: *)
(*Integrands involving roots of quartic binomials*)


(* Integrands of the form x^m/Sqrt[a+b*x^4] where m is an integer *)
{x^7/Sqrt[16 - x^4], x, 3, (-(16/3))*Sqrt[16 - x^4] - (1/6)*x^4*Sqrt[16 - x^4]}
{x^6/Sqrt[16 - x^4], x, 2, (-(1/5))*x^3*Sqrt[16 - x^4] + (96/5)*EllipticE[ArcSin[x/2], -1] - (96/5)*EllipticF[ArcSin[x/2], -1]}
{x^5/Sqrt[16 - x^4], x, 3, (-(1/4))*x^2*Sqrt[16 - x^4] + 4*ArcSin[x^2/4]}
{x^4/Sqrt[16 - x^4], x, 2, (-(1/3))*x*Sqrt[16 - x^4] + (8/3)*EllipticF[ArcSin[x/2], -1]}
{x^3/Sqrt[16 - x^4], x, 2, (-(1/2))*Sqrt[16 - x^4]}
{x^2/Sqrt[16 - x^4], x, 1, 2*EllipticE[ArcSin[x/2], -1] - 2*EllipticF[ArcSin[x/2], -1]}
{x/Sqrt[16 - x^4], x, 2, (1/2)*ArcSin[x^2/4]}
{x/Sqrt[-4 + x^4], x, 2, (1/2)*ArcTanh[x^2/Sqrt[-4 + x^4]]}
{x/Sqrt[4 + x^4], x, 2, ArcSinh[x^2/2]/2}
{1/Sqrt[16 - x^4], x, 1, (1/2)*EllipticF[ArcSin[x/2], -1]}
{1/(x*Sqrt[16 - x^4]), x, 1, (-(1/8))*ArcTanh[Sqrt[16 - x^4]/4]}
{1/(x*Sqrt[-1 + x^4]), x, 1, ArcTan[Sqrt[-1 + x^4]]/2}
{1/(x^2*Sqrt[16 - x^4]), x, 2, -(Sqrt[16 - x^4]/(16*x)) - (1/8)*EllipticE[ArcSin[x/2], -1] + (1/8)*EllipticF[ArcSin[x/2], -1]}
{1/(x^3*Sqrt[16 - x^4]), x, 1, -(Sqrt[16 - x^4]/(32*x^2))}
{1/(x^4*Sqrt[16 - x^4]), x, 2, -(Sqrt[16 - x^4]/(48*x^3)) + (1/96)*EllipticF[ArcSin[x/2], -1]}

{x^6/Sqrt[a + b*x^4], x, 2, (x^3*Sqrt[a + b*x^4])/(5*b) + (3*a^(7/4)*Sqrt[(a + b*x^4)/a]*EllipticE[ArcSin[((-b)^(1/4)*x)/a^(1/4)], -1])/(5*(-b)^(7/4)*Sqrt[a + b*x^4]) - (3*a^(7/4)*Sqrt[(a + b*x^4)/a]*EllipticF[ArcSin[((-b)^(1/4)*x)/a^(1/4)], -1])/(5*(-b)^(7/4)*Sqrt[a + b*x^4])}
{x^5/Sqrt[a + b*x^4], x, 3, (x^2*Sqrt[a + b*x^4])/(4*b) - (a*ArcTanh[(Sqrt[b]*x^2)/Sqrt[a + b*x^4]])/(4*b^(3/2))}
{x^4/Sqrt[a + b*x^4], x, 2, (x*Sqrt[a + b*x^4])/(3*b) + (a^(5/4)*Sqrt[(a + b*x^4)/a]*EllipticF[ArcSin[((-b)^(1/4)*x)/a^(1/4)], -1])/(3*(-b)^(5/4)*Sqrt[a + b*x^4])}
{x^3/Sqrt[a + b*x^4], x, 2, Sqrt[a + b*x^4]/(2*b)}
{x^2/Sqrt[a + b*x^4], x, 1, (a^(3/4)*Sqrt[(a + b*x^4)/a]*EllipticE[ArcSin[((-b)^(1/4)*x)/a^(1/4)], -1])/((-b)^(3/4)*Sqrt[a + b*x^4]) - (a^(3/4)*Sqrt[(a + b*x^4)/a]*EllipticF[ArcSin[((-b)^(1/4)*x)/a^(1/4)], -1])/((-b)^(3/4)*Sqrt[a + b*x^4])}
{x/Sqrt[a + b*x^4], x, 2, ArcTanh[(Sqrt[b]*x^2)/Sqrt[a + b*x^4]]/(2*Sqrt[b])}
{1/Sqrt[a + b*x^4], x, 1, (a^(1/4)*Sqrt[(a + b*x^4)/a]*EllipticF[ArcSin[((-b)^(1/4)*x)/a^(1/4)], -1])/((-b)^(1/4)*Sqrt[a + b*x^4])}
{1/(x*Sqrt[a + b*x^4]), x, 1, -(ArcTanh[Sqrt[a + b*x^4]/Sqrt[a]]/(2*Sqrt[a]))}
{1/(x^2*Sqrt[a + b*x^4]), x, 2, -(Sqrt[a + b*x^4]/(a*x)) - ((-b)^(1/4)*Sqrt[(a + b*x^4)/a]*EllipticE[ArcSin[((-b)^(1/4)*x)/a^(1/4)], -1])/(a^(1/4)*Sqrt[a + b*x^4]) + ((-b)^(1/4)*Sqrt[(a + b*x^4)/a]*EllipticF[ArcSin[((-b)^(1/4)*x)/a^(1/4)], -1])/(a^(1/4)*Sqrt[a + b*x^4])}
{1/(x^3*Sqrt[a + b*x^4]), x, 1, -(Sqrt[a + b*x^4]/(2*a*x^2))}
{1/(x^4*Sqrt[a + b*x^4]), x, 2, -(Sqrt[a + b*x^4]/(3*a*x^3)) + ((-b)^(3/4)*Sqrt[(a + b*x^4)/a]*EllipticF[ArcSin[((-b)^(1/4)*x)/a^(1/4)], -1])/(3*a^(3/4)*Sqrt[a + b*x^4])}


(* Integrands of the form x^m*Sqrt[a+b*x^4] where m is an integer *)
{x^7*Sqrt[5 + 3*x^4], x, 3, (-(1/27))*(5 + 3*x^4)^(3/2) + (1/30)*x^4*(5 + 3*x^4)^(3/2)}
{x^3*Sqrt[5 + x^4], x, 2, (5 + x^4)^(3/2)/6}
{x*Sqrt[3 + 2*x^4], x, 3, (1/4)*x^2*Sqrt[3 + 2*x^4] + (3*ArcSinh[Sqrt[2/3]*x^2])/(4*Sqrt[2])}
{x*Sqrt[-2 + x^4], x, 3, (1/4)*x^2*Sqrt[-2 + x^4] - (1/2)*ArcTanh[x^2/Sqrt[-2 + x^4]]}
{(1 + x^4)^(1/2), x, 2, (1/3)*x*Sqrt[1 + x^4] - (2/3)*(-1)^(3/4)*EllipticF[ArcSin[(-1)^(1/4)*x], -1]}
{(a + b*x^4)^(1/2), x, 2, (1/3)*x*Sqrt[a + b*x^4] + (2*a^(5/4)*Sqrt[(a + b*x^4)/a]*EllipticF[ArcSin[((-b)^(1/4)*x)/a^(1/4)], -1])/(3*(-b)^(1/4)*Sqrt[a + b*x^4])}
{(1 - x^4)^(1/2), x, 2, (1/3)*x*Sqrt[1 - x^4] + (2/3)*EllipticF[ArcSin[x], -1]}


(* Integrands involving expressions of the form (a+b*x^4)^n where n is a half-integer *)
{(a + b*x^4)^(3/2), x, 3, (2/7)*a*x*Sqrt[a + b*x^4] + (1/7)*x*(a + b*x^4)^(3/2) + (4*a^(9/4)*Sqrt[(a + b*x^4)/a]*EllipticF[ArcSin[((-b)^(1/4)*x)/a^(1/4)], -1])/(7*(-b)^(1/4)*Sqrt[a + b*x^4])}
{1/(a + b*x^4)^(3/2), x, 2, x/(2*a*Sqrt[a + b*x^4]) + (Sqrt[(a + b*x^4)/a]*EllipticF[ArcSin[((-b)^(1/4)*x)/a^(1/4)], -1])/(2*a^(3/4)*(-b)^(1/4)*Sqrt[a + b*x^4])}
{1/(a + b*x^4)^(5/2), x, 3, x/(6*a*(a + b*x^4)^(3/2)) + (5*x)/(12*a^2*Sqrt[a + b*x^4]) + (5*Sqrt[(a + b*x^4)/a]*EllipticF[ArcSin[((-b)^(1/4)*x)/a^(1/4)], -1])/(12*a^(7/4)*(-b)^(1/4)*Sqrt[a + b*x^4])}

{(1 + x^4)^(3/2), x, 3, (2/7)*x*Sqrt[1 + x^4] + (1/7)*x*(1 + x^4)^(3/2) - (4/7)*(-1)^(3/4)*EllipticF[ArcSin[(-1)^(1/4)*x], -1]}
{1/(1 + x^4)^(3/2), x, 2, x/(2*Sqrt[1 + x^4]) - (1/2)*(-1)^(3/4)*EllipticF[ArcSin[(-1)^(1/4)*x], -1]}
{1/(1 + x^4)^(5/2), x, 3, x/(6*(1 + x^4)^(3/2)) + (5*x)/(12*Sqrt[1 + x^4]) - (5/12)*(-1)^(3/4)*EllipticF[ArcSin[(-1)^(1/4)*x], -1]}

{(1 - x^4)^(3/2), x, 3, (2/7)*x*Sqrt[1 - x^4] + (1/7)*x*(1 - x^4)^(3/2) + (4/7)*EllipticF[ArcSin[x], -1]}
{1/(1 - x^4)^(3/2), x, 2, x/(2*Sqrt[1 - x^4]) + (1/2)*EllipticF[ArcSin[x], -1]}
{1/(1 - x^4)^(5/2), x, 3, x/(6*(1 - x^4)^(3/2)) + (5*x)/(12*Sqrt[1 - x^4]) + (5/12)*EllipticF[ArcSin[x], -1]}


{(-1 + x^4)/(1 + x^4)^(3/2), x, 1, -(x/Sqrt[1 + x^4])}
{x^7/(1 + x^4)^(3/2), x, 3, -(x^4/(2*Sqrt[1 + x^4])) + Sqrt[1 + x^4]}
{x^7*(1 + x^4)^(1/3), x, 3, (-(9/112))*(1 + x^4)^(4/3) + (3/28)*x^4*(1 + x^4)^(4/3)}
{(2*x^3)/(1 + x^4)^(4/3), x, 3, -3/(2*(1 + x^4)^(1/3))}
{x^3/(1 + x^4)^(1/3), x, 2, (3*(1 + x^4)^(2/3))/8}
{(6*x^3)/(1 + x^4)^(1/4), x, 3, 2*(1 + x^4)^(3/4)}
{(-Sqrt[-1 + x^2] + Sqrt[1 + x^2])/Sqrt[-1 + x^4], x, 6, -((Sqrt[-1 + x^2]*Sqrt[1 + x^2]*ArcSinh[x])/Sqrt[-1 + x^4]) + (Sqrt[-1 + x^2]*Sqrt[1 + x^2]*ArcTanh[x/Sqrt[-1 + x^2]])/Sqrt[-1 + x^4]}
{Sqrt[1 + x^2]/Sqrt[-1 + x^4], x, 2, (Sqrt[-1 + x^2]*Sqrt[1 + x^2]*ArcTanh[x/Sqrt[-1 + x^2]])/Sqrt[-1 + x^4]}
{Sqrt[(1 + x^2)/(-1 + x^4)], x, 3, Sqrt[-(1/(1 - x^2))]*Sqrt[-1 + x^2]*ArcTanh[x/Sqrt[-1 + x^2]]}


{Sqrt[b*x^2 + Sqrt[a + b^2*x^4]]/Sqrt[a + b^2*x^4], x, 1, ArcTanh[(Sqrt[2]*Sqrt[b]*x)/Sqrt[b*x^2 + Sqrt[a + b^2*x^4]]]/(Sqrt[2]*Sqrt[b])}
{Sqrt[-b*x^2 + Sqrt[a + b^2*x^4]]/Sqrt[a + b^2*x^4], x, 1, ArcTan[(Sqrt[2]*Sqrt[b]*x)/Sqrt[(-b)*x^2 + Sqrt[a + b^2*x^4]]]/(Sqrt[2]*Sqrt[b])}


{Sqrt[2*x^2 + Sqrt[3 + 4*x^4]]/((c + d*x)*Sqrt[3 + 4*x^4]), x, 3, ((1/2 - I/2)*ArcTan[(Sqrt[3]*d + 2*I*c*x)/(Sqrt[2*I*c^2 - Sqrt[3]*d^2]*Sqrt[Sqrt[3] - 2*I*x^2])])/Sqrt[2*I*c^2 - Sqrt[3]*d^2] - ((1/2 + I/2)*ArcTanh[(Sqrt[3]*d - 2*I*c*x)/(Sqrt[2*I*c^2 + Sqrt[3]*d^2]*Sqrt[Sqrt[3] + 2*I*x^2])])/Sqrt[2*I*c^2 + Sqrt[3]*d^2]}
{Sqrt[2*x^2 + Sqrt[3 + 4*x^4]]/((c + d*x)^2*Sqrt[3 + 4*x^4]), x, 5, ((1/2 - I/2)*d*Sqrt[Sqrt[3] - 2*I*x^2])/((2*I*c^2 - Sqrt[3]*d^2)*(c + d*x)) - ((1/2 + I/2)*d*Sqrt[Sqrt[3] + 2*I*x^2])/((2*I*c^2 + Sqrt[3]*d^2)*(c + d*x)) + ((1 + I)*c*ArcTan[(Sqrt[3]*d + 2*I*c*x)/(Sqrt[2*I*c^2 - Sqrt[3]*d^2]*Sqrt[Sqrt[3] - 2*I*x^2])])/(2*I*c^2 - Sqrt[3]*d^2)^(3/2) + ((1 - I)*c*ArcTanh[(Sqrt[3]*d - 2*I*c*x)/(Sqrt[2*I*c^2 + Sqrt[3]*d^2]*Sqrt[Sqrt[3] + 2*I*x^2])])/(2*I*c^2 + Sqrt[3]*d^2)^(3/2)}


(* ::Subsection::Closed:: *)
(*Integrands involving roots of quintic binomials*)


(* Integrands of the form x^(n/2)/Sqrt[1+x^5] where n mod 10 = 0 *)
{x^(23/2)/Sqrt[1 + x^5], x, 5, (-(3/20))*x^(5/2)*Sqrt[1 + x^5] + (1/10)*x^(15/2)*Sqrt[1 + x^5] + (3/20)*ArcSinh[x^(5/2)]}
{x^(13/2)/Sqrt[1 + x^5], x, 4, (1/5)*x^(5/2)*Sqrt[1 + x^5] - (1/5)*ArcSinh[x^(5/2)]}
{x^(3/2)/Sqrt[1 + x^5], x, 2, (2/5)*ArcSinh[x^(5/2)]}
{x^(-7/2)/Sqrt[1 + x^5], x, 1, -((2*Sqrt[1 + x^5])/(5*x^(5/2)))}
{x^(-17/2)/Sqrt[1 + x^5], x, 3, -((2*Sqrt[1 + x^5])/(15*x^(15/2))) + (4*Sqrt[1 + x^5])/(15*x^(5/2))}


(* Integrands of the form x^(n/2)/Sqrt[a+b*x^5] where n mod 10 = 0 *)
{x^(23/2)/Sqrt[a + b*x^5], x, 5, -((3*a*x^(5/2)*Sqrt[a + b*x^5])/(20*b^2)) + (x^(15/2)*Sqrt[a + b*x^5])/(10*b) + (3*a^2*ArcTanh[(Sqrt[b]*x^(5/2))/Sqrt[a + b*x^5]])/(20*b^(5/2))}
{x^(13/2)/Sqrt[a + b*x^5], x, 4, (x^(5/2)*Sqrt[a + b*x^5])/(5*b) - (a*ArcTanh[(Sqrt[b]*x^(5/2))/Sqrt[a + b*x^5]])/(5*b^(3/2))}
{x^(3/2)/Sqrt[a + b*x^5], x, 2, (2*ArcTanh[(Sqrt[b]*x^(5/2))/Sqrt[a + b*x^5]])/(5*Sqrt[b])}
{x^(-7/2)/Sqrt[a + b*x^5], x, 1, -((2*Sqrt[a + b*x^5])/(5*a*x^(5/2)))}
{x^(-17/2)/Sqrt[a + b*x^5], x, 3, -((2*Sqrt[a + b*x^5])/(15*a*x^(15/2))) + (4*b*Sqrt[a + b*x^5])/(15*a^2*x^(5/2))}


(* Integrands of the form Sqrt[x^n]/Sqrt[1+x^5] where n mod 10 = 0 *)
{Sqrt[x^23]/Sqrt[1 + x^5], x, 6, -((Sqrt[x^23]*(3*x^(5/2)*Sqrt[1 + x^5] - 2*x^(15/2)*Sqrt[1 + x^5] - 3*ArcSinh[x^(5/2)]))/(20*x^(23/2)))}
{Sqrt[x^13]/Sqrt[1 + x^5], x, 5, (Sqrt[x^13]*(x^(5/2)*Sqrt[1 + x^5] - ArcSinh[x^(5/2)]))/(5*x^(13/2))}
{Sqrt[x^3]/Sqrt[1 + x^5], x, 3, (2*Sqrt[x^3]*ArcSinh[x^(5/2)])/(5*x^(3/2))}
{Sqrt[x^(-7)]/Sqrt[1 + x^5], x, 2, (-(2/5))*Sqrt[1/x^7]*x*Sqrt[1 + x^5]}
{Sqrt[x^(-17)]/Sqrt[1 + x^5], x, 4, (-(2/15))*Sqrt[1/x^17]*x*(1 - 2*x^5)*Sqrt[1 + x^5]}


(* ::Subsection::Closed:: *)
(*Integrands involving roots of higher binomials*)


(* Integrands involving expressions of the form x^m*(a+b*x^6)^n *)
{x^2/Sqrt[1 - x^6], x, 2, ArcSin[x^3]/3}
{x^2/Sqrt[1 + x^6], x, 2, ArcSinh[x^3]/3}
{1/(x*Sqrt[1 + x^6]), x, 1, -ArcTanh[Sqrt[1 + x^6]]/3}
{1/(x*Sqrt[-25 + x^6]), x, 1, ArcTan[Sqrt[-25 + x^6]/5]/15}

{x^8*Sqrt[-1 + 4*x^6], x, 4, (-(1/96))*x^3*Sqrt[-1 + 4*x^6] + (1/12)*x^9*Sqrt[-1 + 4*x^6] - (1/192)*ArcTanh[(2*x^3)/Sqrt[-1 + 4*x^6]]}
{x^5*Sqrt[a^6 - x^6], x, 2, -(a^6 - x^6)^(3/2)/9}
{x^2*Sqrt[-2 + x^6], x, 3, (1/6)*x^3*Sqrt[-2 + x^6] - (1/3)*ArcTanh[x^3/Sqrt[-2 + x^6]]}

{(1 - x^6)^(2/3) + (1 - x^6)^(2/3)/x^6, x, 3, -((1 - x^6)^(2/3)/(5*x^5)) + (1/5)*x*(1 - x^6)^(2/3)}

{x^(1/3)/(1 - x^6), x, 13, -(ArcTan[(1 + 2*x^(2/3))/Sqrt[3]]/(2*Sqrt[3])) - (1/3)*ArcTan[(x^(2/3) + Cos[Pi/9])*Csc[Pi/9]]*(1 - Cos[(2*Pi)/9])*Cot[Pi/9] - (1/6)*Log[1 - x^(2/3)] + (1/12)*Log[1 + x^(2/3) + x^(4/3)] - (1/6)*Cos[(2*Pi)/9]*Log[1 + x^(4/3) + 2*x^(2/3)*Cos[Pi/9]] + (1/6)*Cos[Pi/9]*Log[1 + x^(4/3) - 2*x^(2/3)*Sin[Pi/18]] + (1/3)*ArcTan[(x^(2/3) - Cos[(2*Pi)/9])*Csc[(2*Pi)/9]]*Cot[(2*Pi)/9]*(1 - Sin[Pi/18]) - (1/6)*Log[1 + x^(4/3) - 2*x^(2/3)*Cos[(2*Pi)/9]]*Sin[Pi/18] + (1/3)*ArcTan[Sec[Pi/18]*(x^(2/3) - Sin[Pi/18])]*(1 + Cos[Pi/9])*Tan[Pi/18]}


{1/(x*Sqrt[1 + x^8]), x, 1, -ArcTanh[Sqrt[1 + x^8]]/4}
{x^3*Sqrt[-2 + x^8], x, 3, (1/8)*x^4*Sqrt[-2 + x^8] - (1/4)*ArcTanh[x^4/Sqrt[-2 + x^8]]}
{(Sqrt[1 + x^8]*(1 + 2*x^8))/(x + 2*x^9 + x^17), x, 7, -(1/(4*Sqrt[1 + x^8])) - (1/4)*ArcTanh[Sqrt[1 + x^8]]}


{x^4/Sqrt[1 - x^10], x, 2, ArcSin[x^5]/5}
{x^4/Sqrt[-2 + x^10], x, 2, (1/5)*ArcTanh[x^5/Sqrt[-2 + x^10]]}
{x^5*Sqrt[9 + x^12], x, 3, (1/12)*x^6*Sqrt[9 + x^12] + (3/4)*ArcSinh[x^6/3]}
{(x^31*Sqrt[1 + x^16])/(1 - x^16), x, 6, (-(1/8))*Sqrt[1 + x^16] - (1/24)*(1 + x^16)^(3/2) + ArcTanh[Sqrt[1 + x^16]/Sqrt[2]]/(4*Sqrt[2])}


(* ::Subsection::Closed:: *)
(*Integrands involving roots of improper binomials*)


(* ::Subsubsection:: *)
(*Integrands of the form x^m (a+b/x^n)^p*)


(* ::Subsubsection::Closed:: *)
(*Integrands of the form x^m (a+b/x)^p*)


(* Integrands of the form x^m*Sqrt[a+b/x] where m is an integer *)
{x^3*Sqrt[a + b/x], x, 5, (5*b^3*Sqrt[a + b/x]*x)/(64*a^3) - (5*b^2*Sqrt[a + b/x]*x^2)/(96*a^2) + (b*Sqrt[a + b/x]*x^3)/(24*a) + (1/4)*Sqrt[a + b/x]*x^4 - (5*b^4*ArcTanh[Sqrt[a + b/x]/Sqrt[a]])/(64*a^(7/2))}
{x^2*Sqrt[a + b/x], x, 4, -((b^2*Sqrt[a + b/x]*x)/(8*a^2)) + (b*Sqrt[a + b/x]*x^2)/(12*a) + (1/3)*Sqrt[a + b/x]*x^3 + (b^3*ArcTanh[Sqrt[a + b/x]/Sqrt[a]])/(8*a^(5/2))}
{x*Sqrt[a + b/x], x, 3, (b*Sqrt[a + b/x]*x)/(4*a) + (1/2)*Sqrt[a + b/x]*x^2 - (b^2*ArcTanh[Sqrt[a + b/x]/Sqrt[a]])/(4*a^(3/2))}
{Sqrt[a + b/x], x, 3, Sqrt[a + b/x]*x + (b*ArcTanh[Sqrt[a + b/x]/Sqrt[a]])/Sqrt[a]}
{Sqrt[a + b/x]/x, x, 2, -2*Sqrt[a + b/x] + 2*Sqrt[a]*ArcTanh[Sqrt[a + b/x]/Sqrt[a]]}
{Sqrt[a + b/x]/x^2, x, 2, -((2*(a + b/x)^(3/2))/(3*b))}
{Sqrt[a + b/x]/x^3, x, 3, (4*a*(a + b/x)^(3/2))/(15*b^2) - (2*(a + b/x)^(3/2))/(5*b*x)}

{x^3*Sqrt[-a + b/x], x, 5, -((5*b^3*Sqrt[-a + b/x]*x)/(64*a^3)) - (5*b^2*Sqrt[-a + b/x]*x^2)/(96*a^2) - (b*Sqrt[-a + b/x]*x^3)/(24*a) + (1/4)*Sqrt[-a + b/x]*x^4 - (5*b^4*ArcTan[Sqrt[-a + b/x]/Sqrt[a]])/(64*a^(7/2))}
{x^2*Sqrt[-a + b/x], x, 4, -((b^2*Sqrt[-a + b/x]*x)/(8*a^2)) - (b*Sqrt[-a + b/x]*x^2)/(12*a) + (1/3)*Sqrt[-a + b/x]*x^3 - (b^3*ArcTan[Sqrt[-a + b/x]/Sqrt[a]])/(8*a^(5/2))}
{x*Sqrt[-a + b/x], x, 3, -((b*Sqrt[-a + b/x]*x)/(4*a)) + (1/2)*Sqrt[-a + b/x]*x^2 - (b^2*ArcTan[Sqrt[-a + b/x]/Sqrt[a]])/(4*a^(3/2))}
{Sqrt[-a + b/x], x, 3, Sqrt[-a + b/x]*x - (b*ArcTan[Sqrt[-a + b/x]/Sqrt[a]])/Sqrt[a]}
{Sqrt[-a + b/x]/x, x, 2, -2*Sqrt[-a + b/x] + 2*Sqrt[a]*ArcTan[Sqrt[-a + b/x]/Sqrt[a]]}
{Sqrt[-a + b/x]/x^2, x, 2, -((2*(-a + b/x)^(3/2))/(3*b))}
{Sqrt[-a + b/x]/x^3, x, 3, -((4*a*(-a + b/x)^(3/2))/(15*b^2)) - (2*(-a + b/x)^(3/2))/(5*b*x)}


(* Integrands of the form x^m/Sqrt[a+b/x] where m is an integer *)
{x^3/Sqrt[a + b/x], x, 5, -((35*b^3*Sqrt[a + b/x]*x)/(64*a^4)) + (35*b^2*Sqrt[a + b/x]*x^2)/(96*a^3) - (7*b*Sqrt[a + b/x]*x^3)/(24*a^2) + (Sqrt[a + b/x]*x^4)/(4*a) + (35*b^4*ArcTanh[Sqrt[a + b/x]/Sqrt[a]])/(64*a^(9/2))}
{x^2/Sqrt[a + b/x], x, 4, (5*b^2*Sqrt[a + b/x]*x)/(8*a^3) - (5*b*Sqrt[a + b/x]*x^2)/(12*a^2) + (Sqrt[a + b/x]*x^3)/(3*a) - (5*b^3*ArcTanh[Sqrt[a + b/x]/Sqrt[a]])/(8*a^(7/2))}
{x/Sqrt[a + b/x], x, 3, -((3*b*Sqrt[a + b/x]*x)/(4*a^2)) + (Sqrt[a + b/x]*x^2)/(2*a) + (3*b^2*ArcTanh[Sqrt[a + b/x]/Sqrt[a]])/(4*a^(5/2))}
{1/Sqrt[a + b/x], x, 2, (Sqrt[a + b/x]*x)/a - (b*ArcTanh[Sqrt[a + b/x]/Sqrt[a]])/a^(3/2)}
{1/(x*Sqrt[a + b/x]), x, 1, (2*ArcTanh[Sqrt[a + b/x]/Sqrt[a]])/Sqrt[a]}
{1/(x^2*Sqrt[a + b/x]), x, 2, -((2*Sqrt[a + b/x])/b)}
{1/(x^3*Sqrt[a + b/x]), x, 3, (4*a*Sqrt[a + b/x])/(3*b^2) - (2*Sqrt[a + b/x])/(3*b*x)}

{x^3/Sqrt[-a + b/x], x, 5, -((35*b^3*Sqrt[-a + b/x]*x)/(64*a^4)) - (35*b^2*Sqrt[-a + b/x]*x^2)/(96*a^3) - (7*b*Sqrt[-a + b/x]*x^3)/(24*a^2) - (Sqrt[-a + b/x]*x^4)/(4*a) - (35*b^4*ArcTan[Sqrt[-a + b/x]/Sqrt[a]])/(64*a^(9/2))}
{x^2/Sqrt[-a + b/x], x, 4, -((5*b^2*Sqrt[-a + b/x]*x)/(8*a^3)) - (5*b*Sqrt[-a + b/x]*x^2)/(12*a^2) - (Sqrt[-a + b/x]*x^3)/(3*a) - (5*b^3*ArcTan[Sqrt[-a + b/x]/Sqrt[a]])/(8*a^(7/2))}
{x/Sqrt[-a + b/x], x, 3, -((3*b*Sqrt[-a + b/x]*x)/(4*a^2)) - (Sqrt[-a + b/x]*x^2)/(2*a) - (3*b^2*ArcTan[Sqrt[-a + b/x]/Sqrt[a]])/(4*a^(5/2))}
{1/Sqrt[-a + b/x], x, 2, -((Sqrt[-a + b/x]*x)/a) - (b*ArcTan[Sqrt[-a + b/x]/Sqrt[a]])/a^(3/2)}
{1/(x*Sqrt[-a + b/x]), x, 1, -((2*ArcTan[Sqrt[-a + b/x]/Sqrt[a]])/Sqrt[a])}
{1/(x^2*Sqrt[-a + b/x]), x, 2, -((2*Sqrt[-a + b/x])/b)}
{1/(x^3*Sqrt[-a + b/x]), x, 3, -((4*a*Sqrt[-a + b/x])/(3*b^2)) - (2*Sqrt[-a + b/x])/(3*b*x)}


(* ::Subsubsection::Closed:: *)
(*Integrands of the form x^m (a+b/x^2)^p*)


(* Integrands of the form x^m*(a+b/x^2)^n where n is a half-integer *)
{x^3/Sqrt[a + b/x^2], x, 3, -((3*b*Sqrt[a + b/x^2]*x^2)/(8*a^2)) + (Sqrt[a + b/x^2]*x^4)/(4*a) + (3*b^2*ArcTanh[Sqrt[a + b/x^2]/Sqrt[a]])/(8*a^(5/2))}
{x^2/Sqrt[a + b/x^2], x, 2, -((2*b*Sqrt[a + b/x^2]*x)/(3*a^2)) + (Sqrt[a + b/x^2]*x^3)/(3*a)}
{x/Sqrt[a + b/x^2], x, 2, (Sqrt[a + b/x^2]*x^2)/(2*a) - (b*ArcTanh[Sqrt[a + b/x^2]/Sqrt[a]])/(2*a^(3/2))}
{1/Sqrt[a + b/x^2], x, 1, (Sqrt[a + b/x^2]*x)/a}
{1/(x*Sqrt[a + b/x^2]), x, 1, ArcTanh[Sqrt[a + b/x^2]/Sqrt[a]]/Sqrt[a]}
{1/(x*Sqrt[-a + b/x^2]), x, 1, -(ArcTan[Sqrt[-a + b/x^2]/Sqrt[a]]/Sqrt[a])}
{1/(x^2*Sqrt[2 + b/x^2]), x, 2, -(ArcSinh[Sqrt[b]/(Sqrt[2]*x)]/Sqrt[b])}
{1/(x^2*Sqrt[2 - b/x^2]), x, 2, -(ArcSin[Sqrt[b]/(Sqrt[2]*x)]/Sqrt[b])}
{1/(x^2*Sqrt[a + b/x^2]), x, 2, -(ArcTanh[Sqrt[b]/(Sqrt[a + b/x^2]*x)]/Sqrt[b])}
{1/(x^3*Sqrt[a + b/x^2]), x, 2, -(Sqrt[a + b/x^2]/b)}

{x^3*Sqrt[a + b/x^2], x, 3, (b*Sqrt[a + b/x^2]*x^2)/(8*a) + (1/4)*Sqrt[a + b/x^2]*x^4 - (b^2*ArcTanh[Sqrt[a + b/x^2]/Sqrt[a]])/(8*a^(3/2))}
{x^2*Sqrt[a + b/x^2], x, 1, ((a + b/x^2)^(3/2)*x^3)/(3*a)}
{x*Sqrt[a + b/x^2], x, 2, (1/2)*Sqrt[a + b/x^2]*x^2 + (b*ArcTanh[Sqrt[a + b/x^2]/Sqrt[a]])/(2*Sqrt[a])}
{Sqrt[a + b/x^2], x, 3, Sqrt[a + b/x^2]*x - Sqrt[b]*ArcTanh[Sqrt[b]/(Sqrt[a + b/x^2]*x)]}
{Sqrt[a + b/x^2]/x, x, 2, -Sqrt[a + b/x^2] + Sqrt[a]*ArcTanh[Sqrt[a + b/x^2]/Sqrt[a]]}
{Sqrt[a + b/x^2]/x^2, x, 3, -(Sqrt[a + b/x^2]/(2*x)) - (a*ArcTanh[Sqrt[b]/(Sqrt[a + b/x^2]*x)])/(2*Sqrt[b])}
{Sqrt[a + b/x^2]/x^3, x, 2, -((a + b/x^2)^(3/2)/(3*b))}

{(1 + 1/x^2)^(1/3)/x^3, x, 2, (-3*(1 + x^(-2))^(4/3))/8}
{(1 + 1/x^2)^(5/3)/x^3, x, 2, (-3*(1 + x^(-2))^(8/3))/16}


{Sqrt[2 + b/x^2]/(b + 2*x^2), x, 3, -(ArcSinh[Sqrt[b]/(Sqrt[2]*x)]/Sqrt[b])}
{Sqrt[2 - b/x^2]/(-b + 2*x^2), x, 3, -(ArcSin[Sqrt[b]/(Sqrt[2]*x)]/Sqrt[b])}


(* Integrands of the form Sqrt[-1+1/x^2]*(-1+x^2)^n/x where n is an integer *)
{Sqrt[-1 + 1/x^2]*(-1 + x^2)/x, x, 7, Sqrt[-1 + 1/x^2] + (1/2)*Sqrt[-1 + 1/x^2]*x^2 - (3/2)*ArcTan[Sqrt[-1 + 1/x^2]]}
{Sqrt[-1 + 1/x^2]*(-1 + x^2)^2/x, x, 10, -Sqrt[-1 + 1/x^2] - (9/8)*Sqrt[-1 + 1/x^2]*x^2 + (1/4)*Sqrt[-1 + 1/x^2]*x^4 + (15/8)*ArcTan[Sqrt[-1 + 1/x^2]]}
{Sqrt[-1 + 1/x^2]*(-1 + x^2)^3/x, x, 14, Sqrt[-1 + 1/x^2] + (29/16)*Sqrt[-1 + 1/x^2]*x^2 - (19/24)*Sqrt[-1 + 1/x^2]*x^4 + (1/6)*Sqrt[-1 + 1/x^2]*x^6 - (35/16)*ArcTan[Sqrt[-1 + 1/x^2]]}
{Sqrt[-1 + 1/x^2]/(x*(-1 + x^2)), x, 3, Sqrt[-1 + 1/x^2]}
{Sqrt[-1 + 1/x^2]/(x*(-1 + x^2)^2), x, 3, 1/Sqrt[-1 + 1/x^2] - Sqrt[-1 + 1/x^2]}
{Sqrt[-1 + 1/x^2]/(x*(-1 + x^2)^3), x, 4, -(1/(3*(-1 + 1/x^2)^(3/2))) - 2/Sqrt[-1 + 1/x^2] + Sqrt[-1 + 1/x^2]}


{(-1 + x^2)/(Sqrt[a + b*(-1 + 1/x^2)]*x^3), x, 5, Sqrt[a - b + b/x^2]/b + ArcTanh[Sqrt[a - b + b/x^2]/Sqrt[a - b]]/Sqrt[a - b]}
{(-1 + x^2)/(Sqrt[a - b + b/x^2]*x^3), x, 5, Sqrt[a - b + b/x^2]/b + ArcTanh[Sqrt[a - b + b/x^2]/Sqrt[a - b]]/Sqrt[a - b]}


(* ::Subsubsection::Closed:: *)
(*Integrands of the form x^m (a+b/x^3)^p*)


(* Integrands of the form x^m*(a+b/x^3)^n where n is a half-integer *)
{1/(x*Sqrt[a + b/x^3]), x, 1, (2*ArcTanh[Sqrt[a + b/x^3]/Sqrt[a]])/(3*Sqrt[a])}
{1/(x*Sqrt[-a + b/x^3]), x, 1, -((2*ArcTan[Sqrt[-a + b/x^3]/Sqrt[a]])/(3*Sqrt[a]))}
{x^2/Sqrt[a + b/x^3], x, 2, (Sqrt[a + b/x^3]*x^3)/(3*a) - (b*ArcTanh[Sqrt[a + b/x^3]/Sqrt[a]])/(3*a^(3/2))}

{Sqrt[a + b/x^3]/x, x, 2, (-(2/3))*Sqrt[a + b/x^3] + (2/3)*Sqrt[a]*ArcTanh[Sqrt[a + b/x^3]/Sqrt[a]]}
{Sqrt[-a + b/x^3]/x, x, 2, (-(2/3))*Sqrt[-a + b/x^3] + (2/3)*Sqrt[a]*ArcTan[Sqrt[-a + b/x^3]/Sqrt[a]]}
{x^2*Sqrt[a + b/x^3], x, 2, (1/3)*Sqrt[a + b/x^3]*x^3 + (b*ArcTanh[Sqrt[a + b/x^3]/Sqrt[a]])/(3*Sqrt[a])}


(* ::Subsubsection::Closed:: *)
(*Integrands of the form x^m (a+b/x^4)^p*)


{1/(Sqrt[a + b/x^4]*x^3), x, 2, -(ArcTanh[Sqrt[b]/(Sqrt[a + b/x^4]*x^2)]/(2*Sqrt[b]))}
{x^m/Sqrt[a + b*x^(2 + 2*m)], x, 2, ArcTanh[(Sqrt[b]*x^(1 + m))/Sqrt[a + b*x^(2 + 2*m)]]/(Sqrt[b]*(1 + m))}


(* ::Subsubsection::Closed:: *)
(*Integrands of the form x^m (a+b/x^5)^p*)


(* Integrands of the form x^m*(a+b/x^5)^n where n is a half-integer *)
{1/(Sqrt[a + b/x^5]*x), x, 1, (2*ArcTanh[Sqrt[a + b/x^5]/Sqrt[a]])/(5*Sqrt[a])}
{1/(Sqrt[-a + b/x^5]*x), x, 1, (-2*ArcTan[Sqrt[-a + b/x^5]/Sqrt[a]])/(5*Sqrt[a])}


(* ::Subsubsection::Closed:: *)
(*Integrands of the form x^m (a+b x^n)^p*)


{1/Sqrt[1 + Sqrt[1/x]], x, 4, -((3*Sqrt[1 + Sqrt[1/x]])/(2*Sqrt[1/x])) + Sqrt[1 + Sqrt[1/x]]*x + (3/2)*ArcTanh[Sqrt[1 + Sqrt[1/x]]]}
{1/Sqrt[1 + x^(1/3)], x, 4, (16/5)*Sqrt[1 + x^(1/3)] - (8/5)*Sqrt[1 + x^(1/3)]*x^(1/3) + (6/5)*Sqrt[1 + x^(1/3)]*x^(2/3)}
{1/Sqrt[1 + Sqrt[x]], x, 3, (-(8/3))*Sqrt[1 + Sqrt[x]] + (4/3)*Sqrt[1 + Sqrt[x]]*Sqrt[x]}
{Sqrt[1 + Sqrt[x]], x, 4, (-(8/15))*Sqrt[1 + Sqrt[x]] + (4/15)*Sqrt[1 + Sqrt[x]]*Sqrt[x] + (4/5)*Sqrt[1 + Sqrt[x]]*x}
{(1 + x^(-1/3))^(-1), x, 6, 3*x^(1/3) - (3*x^(2/3))/2 + x - 3*Log[1 + x^(1/3)]}
{1/Sqrt[1 + 1/Sqrt[x]], x, 4, (-(3/2))*Sqrt[1 + 1/Sqrt[x]]*Sqrt[x] + Sqrt[1 + 1/Sqrt[x]]*x + (3/2)*ArcTanh[Sqrt[1 + 1/Sqrt[x]]]}
{Sqrt[3 - 1/Sqrt[x]], x, 5, (-(1/6))*Sqrt[3 - 1/Sqrt[x]]*Sqrt[x] + Sqrt[3 - 1/Sqrt[x]]*x - ArcTanh[Sqrt[3 - 1/Sqrt[x]]/Sqrt[3]]/(6*Sqrt[3])}


(* ::Subsubsection::Closed:: *)
(*Integrands of the form x^m (a x+b x^2)^p*)


{x^3*(a*x + b*x^2)^(5/2), x, 7, -((55*a^7*(a + 2*b*x)*Sqrt[a*x + b*x^2])/(32768*b^6)) + (55*a^5*(a + 2*b*x)*(a*x + b*x^2)^(3/2))/(12288*b^5) - (11*a^3*(a + 2*b*x)*(a*x + b*x^2)^(5/2))/(768*b^4) + (11*a^2*(a*x + b*x^2)^(7/2))/(224*b^3) - (11*a*x*(a*x + b*x^2)^(7/2))/(144*b^2) + (x^2*(a*x + b*x^2)^(7/2))/(9*b) + (55*a^9*ArcTanh[(Sqrt[b]*x)/Sqrt[a*x + b*x^2]])/(32768*b^(13/2))}
{x^2*(a*x + b*x^2)^(5/2), x, 6, (45*a^6*(a + 2*b*x)*Sqrt[a*x + b*x^2])/(16384*b^5) - (15*a^4*(a + 2*b*x)*(a*x + b*x^2)^(3/2))/(2048*b^4) + (3*a^2*(a + 2*b*x)*(a*x + b*x^2)^(5/2))/(128*b^3) - (9*a*(a*x + b*x^2)^(7/2))/(112*b^2) + (x*(a*x + b*x^2)^(7/2))/(8*b) - (45*a^8*ArcTanh[(Sqrt[b]*x)/Sqrt[a*x + b*x^2]])/(16384*b^(11/2))}
{x*(a*x + b*x^2)^(5/2), x, 5, -((5*a^5*(a + 2*b*x)*Sqrt[a*x + b*x^2])/(1024*b^4)) + (5*a^3*(a + 2*b*x)*(a*x + b*x^2)^(3/2))/(384*b^3) - (a*(a + 2*b*x)*(a*x + b*x^2)^(5/2))/(24*b^2) + (a*x + b*x^2)^(7/2)/(7*b) + (5*a^7*ArcTanh[(Sqrt[b]*x)/Sqrt[a*x + b*x^2]])/(1024*b^(9/2))}
{(a*x + b*x^2)^(5/2), x, 4, (5*a^4*(a + 2*b*x)*Sqrt[a*x + b*x^2])/(512*b^3) - (5*a^2*(a + 2*b*x)*(a*x + b*x^2)^(3/2))/(192*b^2) + ((a + 2*b*x)*(a*x + b*x^2)^(5/2))/(12*b) - (5*a^6*ArcTanh[(Sqrt[b]*x)/Sqrt[a*x + b*x^2]])/(512*b^(7/2))}
{(a*x + b*x^2)^(5/2)/x, x, 4, -((3*a^3*(a + 2*b*x)*Sqrt[a*x + b*x^2])/(128*b^2)) + (a*(a + 2*b*x)*(a*x + b*x^2)^(3/2))/(16*b) + (1/5)*(a*x + b*x^2)^(5/2) + (3*a^5*ArcTanh[(Sqrt[b]*x)/Sqrt[a*x + b*x^2]])/(128*b^(5/2))}
{(a*x + b*x^2)^(5/2)/x^2, x, 5, (5*a^2*(a + 2*b*x)*Sqrt[a*x + b*x^2])/(64*b) - (5/24)*(a + 2*b*x)*(a*x + b*x^2)^(3/2) - (2*b*(a*x + b*x^2)^(5/2))/(3*a) + (2*(a*x + b*x^2)^(7/2))/(3*a*x^2) - (5*a^4*ArcTanh[(Sqrt[b]*x)/Sqrt[a*x + b*x^2]])/(64*b^(3/2))}
{(a*x + b*x^2)^(5/2)/x^3, x, 6, (-(5/8))*a*(a + 2*b*x)*Sqrt[a*x + b*x^2] + (5*b*(a + 2*b*x)*(a*x + b*x^2)^(3/2))/(3*a) + (16*b^2*(a*x + b*x^2)^(5/2))/(3*a^2) + (2*(a*x + b*x^2)^(7/2))/(a*x^3) - (16*b*(a*x + b*x^2)^(7/2))/(3*a^2*x^2) + (5*a^3*ArcTanh[(Sqrt[b]*x)/Sqrt[a*x + b*x^2]])/(8*Sqrt[b])}


{x^3*(a*x + b*x^2)^(3/2), x, 6, (9*a^5*(a + 2*b*x)*Sqrt[a*x + b*x^2])/(1024*b^5) - (3*a^3*(a + 2*b*x)*(a*x + b*x^2)^(3/2))/(128*b^4) + (3*a^2*(a*x + b*x^2)^(5/2))/(40*b^3) - (3*a*x*(a*x + b*x^2)^(5/2))/(28*b^2) + (x^2*(a*x + b*x^2)^(5/2))/(7*b) - (9*a^7*ArcTanh[(Sqrt[b]*x)/Sqrt[a*x + b*x^2]])/(1024*b^(11/2))}
{x^2*(a*x + b*x^2)^(3/2), x, 5, -((7*a^4*(a + 2*b*x)*Sqrt[a*x + b*x^2])/(512*b^4)) + (7*a^2*(a + 2*b*x)*(a*x + b*x^2)^(3/2))/(192*b^3) - (7*a*(a*x + b*x^2)^(5/2))/(60*b^2) + (x*(a*x + b*x^2)^(5/2))/(6*b) + (7*a^6*ArcTanh[(Sqrt[b]*x)/Sqrt[a*x + b*x^2]])/(512*b^(9/2))}
{x*(a*x + b*x^2)^(3/2), x, 4, (3*a^3*(a + 2*b*x)*Sqrt[a*x + b*x^2])/(128*b^3) - (a*(a + 2*b*x)*(a*x + b*x^2)^(3/2))/(16*b^2) + (a*x + b*x^2)^(5/2)/(5*b) - (3*a^5*ArcTanh[(Sqrt[b]*x)/Sqrt[a*x + b*x^2]])/(128*b^(7/2))}
{(a*x + b*x^2)^(3/2), x, 3, -((3*a^2*(a + 2*b*x)*Sqrt[a*x + b*x^2])/(64*b^2)) + ((a + 2*b*x)*(a*x + b*x^2)^(3/2))/(8*b) + (3*a^4*ArcTanh[(Sqrt[b]*x)/Sqrt[a*x + b*x^2]])/(64*b^(5/2))}
{(a*x + b*x^2)^(3/2)/x, x, 3, (a*(a + 2*b*x)*Sqrt[a*x + b*x^2])/(8*b) + (1/3)*(a*x + b*x^2)^(3/2) - (a^3*ArcTanh[(Sqrt[b]*x)/Sqrt[a*x + b*x^2]])/(8*b^(3/2))}
{(a*x + b*x^2)^(3/2)/x^2, x, 4, (-(3/4))*(a + 2*b*x)*Sqrt[a*x + b*x^2] - (2*b*(a*x + b*x^2)^(3/2))/a + (2*(a*x + b*x^2)^(5/2))/(a*x^2) + (3*a^2*ArcTanh[(Sqrt[b]*x)/Sqrt[a*x + b*x^2]])/(4*Sqrt[b])}
{(a*x + b*x^2)^(3/2)/x^3, x, 5, -((3*b*(a + 2*b*x)*Sqrt[a*x + b*x^2])/a) - (8*b^2*(a*x + b*x^2)^(3/2))/a^2 - (2*(a*x + b*x^2)^(5/2))/(a*x^3) + (8*b*(a*x + b*x^2)^(5/2))/(a^2*x^2) + 3*a*Sqrt[b]*ArcTanh[(Sqrt[b]*x)/Sqrt[a*x + b*x^2]]}


{x^3*Sqrt[a*x + b*x^2], x, 5, -((7*a^3*(a + 2*b*x)*Sqrt[a*x + b*x^2])/(128*b^4)) + (7*a^2*(a*x + b*x^2)^(3/2))/(48*b^3) - (7*a*x*(a*x + b*x^2)^(3/2))/(40*b^2) + (x^2*(a*x + b*x^2)^(3/2))/(5*b) + (7*a^5*ArcTanh[(Sqrt[b]*x)/Sqrt[a*x + b*x^2]])/(128*b^(9/2))}
{x^2*Sqrt[a*x + b*x^2], x, 4, (5*a^2*(a + 2*b*x)*Sqrt[a*x + b*x^2])/(64*b^3) - (5*a*(a*x + b*x^2)^(3/2))/(24*b^2) + (x*(a*x + b*x^2)^(3/2))/(4*b) - (5*a^4*ArcTanh[(Sqrt[b]*x)/Sqrt[a*x + b*x^2]])/(64*b^(7/2))}
{x*Sqrt[a*x + b*x^2], x, 3, -((a*(a + 2*b*x)*Sqrt[a*x + b*x^2])/(8*b^2)) + (a*x + b*x^2)^(3/2)/(3*b) + (a^3*ArcTanh[(Sqrt[b]*x)/Sqrt[a*x + b*x^2]])/(8*b^(5/2))}
{Sqrt[a*x + b*x^2], x, 2, ((a + 2*b*x)*Sqrt[a*x + b*x^2])/(4*b) - (a^2*ArcTanh[(Sqrt[b]*x)/Sqrt[a*x + b*x^2]])/(4*b^(3/2))}
{Sqrt[a*x + b*x^2]/x, x, 2, Sqrt[a*x + b*x^2] + (a*ArcTanh[(Sqrt[b]*x)/Sqrt[a*x + b*x^2]])/Sqrt[b]}
{Sqrt[a*x + b*x^2]/x^2, x, 3, (2*b*Sqrt[a*x + b*x^2])/a - (2*(a*x + b*x^2)^(3/2))/(a*x^2) + 2*Sqrt[b]*ArcTanh[(Sqrt[b]*x)/Sqrt[a*x + b*x^2]]}
{Sqrt[a*x + b*x^2]/x^3, x, 1, -((2*(a*x + b*x^2)^(3/2))/(3*a*x^3))}
{Sqrt[a*x + b*x^2]/x^4, x, 2, -((2*(a*x + b*x^2)^(3/2))/(5*a*x^4)) + (4*b*(a*x + b*x^2)^(3/2))/(15*a^2*x^3)}
{Sqrt[a*x + b*x^2]/x^5, x, 3, -((2*(a*x + b*x^2)^(3/2))/(7*a*x^5)) + (8*b*(a*x + b*x^2)^(3/2))/(35*a^2*x^4) - (16*b^2*(a*x + b*x^2)^(3/2))/(105*a^3*x^3)}


{x^3/Sqrt[a*x + b*x^2], x, 4, (5*a^2*Sqrt[a*x + b*x^2])/(8*b^3) - (5*a*x*Sqrt[a*x + b*x^2])/(12*b^2) + (x^2*Sqrt[a*x + b*x^2])/(3*b) - (5*a^3*ArcTanh[(Sqrt[b]*x)/Sqrt[a*x + b*x^2]])/(8*b^(7/2))}
{x^2/Sqrt[a*x + b*x^2], x, 3, -((3*a*Sqrt[a*x + b*x^2])/(4*b^2)) + (x*Sqrt[a*x + b*x^2])/(2*b) + (3*a^2*ArcTanh[(Sqrt[b]*x)/Sqrt[a*x + b*x^2]])/(4*b^(5/2))}
{x/Sqrt[a*x + b*x^2], x, 2, Sqrt[a*x + b*x^2]/b - (a*ArcTanh[(Sqrt[b]*x)/Sqrt[a*x + b*x^2]])/b^(3/2)}
{1/Sqrt[a*x + b*x^2], x, 1, (2*ArcTanh[(Sqrt[b]*x)/Sqrt[a*x + b*x^2]])/Sqrt[b]}
{1/(x*Sqrt[a*x + b*x^2]), x, 1, -((2*Sqrt[a*x + b*x^2])/(a*x))}
{1/(x^2*Sqrt[a*x + b*x^2]), x, 2, -((2*Sqrt[a*x + b*x^2])/(3*a*x^2)) + (4*b*Sqrt[a*x + b*x^2])/(3*a^2*x)}
{1/(x^3*Sqrt[a*x + b*x^2]), x, 3, -((2*Sqrt[a*x + b*x^2])/(5*a*x^3)) + (8*b*Sqrt[a*x + b*x^2])/(15*a^2*x^2) - (16*b^2*Sqrt[a*x + b*x^2])/(15*a^3*x)}


{x^3/(a*x + b*x^2)^(3/2), x, 5, (3*a*x)/(b^2*Sqrt[a*x + b*x^2]) + x^2/(b*Sqrt[a*x + b*x^2]) - (3*a*ArcTanh[(Sqrt[b]*x)/Sqrt[a*x + b*x^2]])/b^(5/2)}
{x^2/(a*x + b*x^2)^(3/2), x, 4, -((2*x)/(b*Sqrt[a*x + b*x^2])) + (2*ArcTanh[(Sqrt[b]*x)/Sqrt[a*x + b*x^2]])/b^(3/2)}
{x/(a*x + b*x^2)^(3/2), x, 2, (2*x)/(a*Sqrt[a*x + b*x^2])}
{1/(a*x + b*x^2)^(3/2), x, 1, -((2*(a + 2*b*x))/(a^2*Sqrt[a*x + b*x^2]))}
{1/(x*(a*x + b*x^2)^(3/2)), x, 2, -(2/(3*a*x*Sqrt[a*x + b*x^2])) + (8*b*(a + 2*b*x))/(3*a^3*Sqrt[a*x + b*x^2])}
{1/(x^2*(a*x + b*x^2)^(3/2)), x, 3, -(2/(5*a*x^2*Sqrt[a*x + b*x^2])) + (4*b)/(5*a^2*x*Sqrt[a*x + b*x^2]) - (16*b^2*(a + 2*b*x))/(5*a^4*Sqrt[a*x + b*x^2])}
{1/(x^3*(a*x + b*x^2)^(3/2)), x, 4, -(2/(7*a*x^3*Sqrt[a*x + b*x^2])) + (16*b)/(35*a^2*x^2*Sqrt[a*x + b*x^2]) - (32*b^2)/(35*a^3*x*Sqrt[a*x + b*x^2]) + (128*b^3*(a + 2*b*x))/(35*a^5*Sqrt[a*x + b*x^2])}


{x^3/(a*x + b*x^2)^(5/2), x, 5, -((a*x)/(3*b^2*(a*x + b*x^2)^(3/2))) - x^2/(b*(a*x + b*x^2)^(3/2)) + (a + 2*b*x)/(3*a*b^2*Sqrt[a*x + b*x^2])}
{x^2/(a*x + b*x^2)^(5/2), x, 4, -((2*x)/(3*b*(a*x + b*x^2)^(3/2))) + (2*(a + 2*b*x))/(3*a^2*b*Sqrt[a*x + b*x^2])}
{x/(a*x + b*x^2)^(5/2), x, 3, (2*x)/(3*a*(a*x + b*x^2)^(3/2)) - (8*(a + 2*b*x))/(3*a^3*Sqrt[a*x + b*x^2])}
{1/(a*x + b*x^2)^(5/2), x, 2, -((2*(a + 2*b*x))/(3*a^2*(a*x + b*x^2)^(3/2))) + (16*b*(a + 2*b*x))/(3*a^4*Sqrt[a*x + b*x^2])}
{1/(x*(a*x + b*x^2)^(5/2)), x, 3, -(2/(5*a*x*(a*x + b*x^2)^(3/2))) + (16*b*(a + 2*b*x))/(15*a^3*(a*x + b*x^2)^(3/2)) - (128*b^2*(a + 2*b*x))/(15*a^5*Sqrt[a*x + b*x^2])}
{1/(x^2*(a*x + b*x^2)^(5/2)), x, 4, -(2/(7*a*x^2*(a*x + b*x^2)^(3/2))) + (4*b)/(7*a^2*x*(a*x + b*x^2)^(3/2)) - (32*b^2*(a + 2*b*x))/(21*a^4*(a*x + b*x^2)^(3/2)) + (256*b^3*(a + 2*b*x))/(21*a^6*Sqrt[a*x + b*x^2])}
{1/(x^3*(a*x + b*x^2)^(5/2)), x, 5, -(2/(9*a*x^3*(a*x + b*x^2)^(3/2))) + (8*b)/(21*a^2*x^2*(a*x + b*x^2)^(3/2)) - (16*b^2)/(21*a^3*x*(a*x + b*x^2)^(3/2)) + (128*b^3*(a + 2*b*x))/(63*a^5*(a*x + b*x^2)^(3/2)) - (1024*b^4*(a + 2*b*x))/(63*a^7*Sqrt[a*x + b*x^2])}


(* Integrands of the form (a*x+b*x^2)^n where n is a half-integer *)
{1/Sqrt[6*x - x^2], x, 1, -ArcSin[(3 - x)/3]}
{1/Sqrt[(1 - x)*x], x, 3, -ArcSin[1 - 2*x]}
{1/Sqrt[4*x + x^2], x, 1, 2*ArcTanh[x/Sqrt[4*x + x^2]]}
{1/Sqrt[-2*x + x^2], x, 1, 2*ArcTanh[x/Sqrt[-2*x + x^2]]}

{Sqrt[6*x - x^2], x, 2, (-(1/2))*(3 - x)*Sqrt[6*x - x^2] - (9/2)*ArcSin[(3 - x)/3]}
{Sqrt[(4 - x)*x], x, 3, (-(1/2))*(2 - x)*Sqrt[4*x - x^2] - 2*ArcSin[(2 - x)/2]}
{Sqrt[5*x - 9*x^2], x, 2, (-(1/36))*(5 - 18*x)*Sqrt[5*x - 9*x^2] - (25/216)*ArcSin[(1/5)*(5 - 18*x)]}

{Sqrt[4*x + x^2], x, 2, (1/2)*(2 + x)*Sqrt[4*x + x^2] - 4*ArcTanh[x/Sqrt[4*x + x^2]]}
{Sqrt[-8*x + x^2], x, 2, (-(1/2))*(4 - x)*Sqrt[-8*x + x^2] - 16*ArcTanh[x/Sqrt[-8*x + x^2]]}
{Sqrt[-x + x^2], x, 2, (-(1/4))*(1 - 2*x)*Sqrt[-x + x^2] - (1/4)*ArcTanh[x/Sqrt[-x + x^2]]}


(* Integrands of the form x^m*(a*x+b*x^2)^n where n is a half-integer *)
{x/Sqrt[4*x - x^2], x, 2, -Sqrt[4*x - x^2] - 2*ArcSin[(2 - x)/2]}
{x/Sqrt[-4*x + x^2], x, 2, Sqrt[-4*x + x^2] + 4*ArcTanh[x/Sqrt[-4*x + x^2]]}
{x^2/Sqrt[2*x - x^2], x, 3, (-(3/2))*Sqrt[2*x - x^2] - (1/2)*x*Sqrt[2*x - x^2] - (3/2)*ArcSin[1 - x]}

{x*Sqrt[2*x - x^2], x, 3, (-(1/2))*(1 - x)*Sqrt[2*x - x^2] - (1/3)*(2*x - x^2)^(3/2) - (1/2)*ArcSin[1 - x]}
{x*Sqrt[3*x - 4*x^2], x, 3, (-(3/128))*(3 - 8*x)*Sqrt[3*x - 4*x^2] - (1/12)*(3*x - 4*x^2)^(3/2) - (27/512)*ArcSin[(1/3)*(3 - 8*x)]}
{x*Sqrt[x + x^2], x, 3, (-(1/8))*(1 + 2*x)*Sqrt[x + x^2] + (1/3)*(x + x^2)^(3/2) + (1/8)*ArcTanh[x/Sqrt[x + x^2]]}

{Sqrt[2*x + x^2]/(1 + x), x, 2, Sqrt[2*x + x^2] - ArcTan[Sqrt[2*x + x^2]]}


(* Integrands equivalent to expressions of the form 1/Sqrt[c*x*(a + b*x)] *)
{1/Sqrt[a*x + b*x^2], x, 1, (2*ArcTanh[(Sqrt[b]*x)/Sqrt[a*x + b*x^2]])/Sqrt[b]}
{1/Sqrt[x*(a + b*x)], x, 2, (2*ArcTanh[(Sqrt[b]*x)/Sqrt[x*(a + b*x)]])/Sqrt[b]}
{1/Sqrt[x^2*(b + a/x)], x, 1, (2*ArcTanh[(Sqrt[b]*x)/Sqrt[x*(a + b*x)]])/Sqrt[b]}

{1/Sqrt[a*c*x + b*c*x^2], x, 1, (2*ArcTanh[(Sqrt[b]*Sqrt[c]*x)/Sqrt[a*c*x + b*c*x^2]])/(Sqrt[b]*Sqrt[c])}
{1/Sqrt[c*(a*x + b*x^2)], x, 2, (2*ArcTanh[(Sqrt[b]*Sqrt[c]*x)/Sqrt[a*c*x + b*c*x^2]])/(Sqrt[b]*Sqrt[c])}
{1/Sqrt[c*x*(a + b*x)], x, 2, (2*ArcTanh[(Sqrt[b]*Sqrt[c]*x)/Sqrt[c*x*(a + b*x)]])/(Sqrt[b]*Sqrt[c])}
{1/Sqrt[c*x^2*(b + a/x)], x, 1, (2*ArcTanh[(Sqrt[b]*Sqrt[c]*x)/Sqrt[c*x*(a + b*x)]])/(Sqrt[b]*Sqrt[c])}


(* ::Subsubsection::Closed:: *)
(*Integrands of the form 1 / Sqrt[a x^n+b x^2]*)


(* Integrands equivalent to expressions of the form 1/Sqrt[c*x^2*(a+b*x^n)] *)
{1/Sqrt[(a + b*x^3)/x], x, 2, (2*ArcTanh[(Sqrt[b]*x)/Sqrt[(a + b*x^3)/x]])/(3*Sqrt[b])}
{1/Sqrt[(a + b*x^4)/x^2], x, 2, ArcTanh[(Sqrt[b]*x)/Sqrt[(a + b*x^4)/x^2]]/(2*Sqrt[b])}
{1/Sqrt[(a + b*x^5)/x^3], x, 2, (2*ArcTanh[(Sqrt[b]*x)/Sqrt[(a + b*x^5)/x^3]])/(5*Sqrt[b])}
{1/Sqrt[(a + b*x^n)/x^(n-2)], x, 2, (2*ArcTanh[(Sqrt[b]*x)/Sqrt[x^2*(b + a/x^n)]])/(Sqrt[b]*n)}

{1/Sqrt[(a - b*x^3)/x], x, 2, (2*ArcTan[(Sqrt[b]*x)/Sqrt[(a - b*x^3)/x]])/(3*Sqrt[b])}
{1/Sqrt[(a - b*x^4)/x^2], x, 2, ArcTan[(Sqrt[b]*x)/Sqrt[(a - b*x^4)/x^2]]/(2*Sqrt[b])}
{1/Sqrt[(a - b*x^5)/x^3], x, 2, (2*ArcTan[(Sqrt[b]*x)/Sqrt[(a - b*x^5)/x^3]])/(5*Sqrt[b])}
{1/Sqrt[(a - b*x^n)/x^(n-2)], x, 2, (2*ArcTan[(Sqrt[b]*x)/Sqrt[(-x^2)*(b - a/x^n)]])/(Sqrt[b]*n)}

{1/Sqrt[x^n*(a + b*x^(2 - n))], x, 2, (2*ArcTanh[(Sqrt[b]*x)/Sqrt[x^2*(b + a*x^(-2 + n))]])/(Sqrt[b]*(2 - n))}
{1/Sqrt[x^2*(b + a*x^(-2 + n))], x, 1, (2*ArcTanh[(Sqrt[b]*x)/Sqrt[x^2*(b + a*x^(-2 + n))]])/(Sqrt[b]*(2 - n))}
{1/Sqrt[x*(b*x + a*x^(-1 + n))], x, 2, (2*ArcTanh[(Sqrt[b]*x)/Sqrt[x^2*(b + a*x^(-2 + n))]])/(Sqrt[b]*(2 - n))}
{1/Sqrt[b*x^2 + a*x^n], x, 2, (2*ArcTanh[(Sqrt[b]*x)/Sqrt[x^2*(b + a*x^(-2 + n))]])/(Sqrt[b]*(2 - n))}

{1/Sqrt[x^n*(a - b*x^(2 - n))], x, 2, (2*ArcTan[(Sqrt[b]*x)/Sqrt[(-x^2)*(b - a*x^(-2 + n))]])/(Sqrt[b]*(2 - n))}
{1/Sqrt[x^2*(-b + a*x^(-2 + n))], x, 1, (2*ArcTan[(Sqrt[b]*x)/Sqrt[(-x^2)*(b - a*x^(-2 + n))]])/(Sqrt[b]*(2 - n))}
{1/Sqrt[x*(-b*x + a*x^(-1 + n))], x, 2, (2*ArcTan[(Sqrt[b]*x)/Sqrt[(-x^2)*(b - a*x^(-2 + n))]])/(Sqrt[b]*(2 - n))}
{1/Sqrt[-b*x^2 + a*x^n], x, 2, (2*ArcTan[(Sqrt[b]*x)/Sqrt[(-x^2)*(b - a*x^(-2 + n))]])/(Sqrt[b]*(2 - n))}

{1/Sqrt[6*x^3 - x^2], x, 2, -2*ArcTan[x/Sqrt[(-(1 - 6*x))*x^2]]}
{1/Sqrt[6/x^3 - x^2], x, 2, (2/5)*ArcTan[x/Sqrt[(6 - x^5)/x^3]]}


(* Integrands of the form Sqrt[(a+b*x^n)/x^2] *)
{Sqrt[(a + b*x)/x^2], x, 3, (2*x*Sqrt[(a + b*x)/x^2]*(Sqrt[a + b*x] - Sqrt[a]*ArcTanh[Sqrt[a + b*x]/Sqrt[a]]))/Sqrt[a + b*x]}
{Sqrt[(a + b*x^2)/x^2], x, 4, Sqrt[b + a/x^2]*x - Sqrt[a]*ArcTanh[Sqrt[a]/(Sqrt[b + a/x^2]*x)]}
{Sqrt[(a + b*x^3)/x^2], x, 3, (2*x*Sqrt[(a + b*x^3)/x^2]*(Sqrt[a + b*x^3] - Sqrt[a]*ArcTanh[Sqrt[a + b*x^3]/Sqrt[a]]))/(3*Sqrt[a + b*x^3])}
{Sqrt[(a + b*x^n)/x^2], x, 3, (2*x*Sqrt[(a + b*x^n)/x^2]*(Sqrt[a + b*x^n] - Sqrt[a]*ArcTanh[Sqrt[a + b*x^n]/Sqrt[a]]))/(n*Sqrt[a + b*x^n])}

{Sqrt[(-a + b*x)/x^2], x, 3, (2*x*Sqrt[-((a - b*x)/x^2)]*(Sqrt[-a + b*x] - Sqrt[a]*ArcTan[Sqrt[-a + b*x]/Sqrt[a]]))/Sqrt[-a + b*x]}
{Sqrt[(-a + b*x^2)/x^2], x, 4, Sqrt[b - a/x^2]*x + Sqrt[a]*ArcTan[Sqrt[a]/(Sqrt[b - a/x^2]*x)]}
{Sqrt[(-a + b*x^3)/x^2], x, 3, (2*x*Sqrt[-((a - b*x^3)/x^2)]*(Sqrt[-a + b*x^3] - Sqrt[a]*ArcTan[Sqrt[-a + b*x^3]/Sqrt[a]]))/(3*Sqrt[-a + b*x^3])}
{Sqrt[(-a + b*x^n)/x^2], x, 3, (2*x*Sqrt[-((a - b*x^n)/x^2)]*(Sqrt[-a + b*x^n] - Sqrt[a]*ArcTan[Sqrt[-a + b*x^n]/Sqrt[a]]))/(n*Sqrt[-a + b*x^n])}


(* ::Subsubsection::Closed:: *)
(*Integrands of the form (a + b (c x^m)^(n/m))^p*)


{1/(1 + (x^3)^(2/3)), x, 2, (x*ArcTan[(x^3)^(1/3)])/(x^3)^(1/3)}
{1/(1 + (x^2)^(3/2)), x, 5, -((x*ArcTan[(1 - 2*Sqrt[x^2])/Sqrt[3]])/(Sqrt[3]*Sqrt[x^2])) - (x*Log[1 + x^2 - Sqrt[x^2]])/(6*Sqrt[x^2]) + (x*Log[1 + Sqrt[x^2]])/(3*Sqrt[x^2])}


(* Integrands of the form 1/(a+b*(x^(2*n))^(1/n) where n is an integer *)
{(1 + 4*Sqrt[x^4])^(-1), x, 2, (x*ArcTan[2*(x^4)^(1/4)])/(2*(x^4)^(1/4))}
{(1 - 4*Sqrt[x^4])^(-1), x, 2, (x*ArcTanh[2*(x^4)^(1/4)])/(2*(x^4)^(1/4))}
{(1 + 4*(x^6)^(1/3))^(-1), x, 2, (x*ArcTan[2*(x^6)^(1/6)])/(2*(x^6)^(1/6))}
{(1 - 4*(x^6)^(1/3))^(-1), x, 2, (x*ArcTanh[2*(x^6)^(1/6)])/(2*(x^6)^(1/6))}
{(1 + 4*(x^(2*n))^n^(-1))^(-1), x, 2, ((1/2)*x*ArcTan[2*(x^(2*n))^(1/(2*n))])/(x^(2*n))^(1/(2*n))}
{(1 - 4*(x^(2*n))^n^(-1))^(-1), x, 2, ((1/2)*x*ArcTanh[2*(x^(2*n))^(1/(2*n))])/(x^(2*n))^(1/(2*n))}


{(a + b*(c*x^m)^(1/m))^3, x, 2, (x*(a + b*(c*x^m)^(1/m))^4)/((c*x^m)^m^(-1)*(4*b))}
{(a + b*(c*x^m)^(1/m))^2, x, 2, (x*(a + b*(c*x^m)^(1/m))^3)/((c*x^m)^m^(-1)*(3*b))}
{(a + b*(c*x^m)^(1/m)), x, 2, a*x + (1/2)*b*x*(c*x^m)^(1/m)}
{1/(a + b*(c*x^m)^(1/m)), x, 2, (x*Log[a + b*(c*x^m)^(1/m)])/((c*x^m)^m^(-1)*b)}
{1/(a + b*(c*x^m)^(1/m))^2, x, 2, x/(a^2 + a*b*(c*x^m)^(1/m)), -(x/((c*x^m)^m^(-1)*(b*(a + b*(c*x^m)^(1/m)))))}
{1/(a + b*(c*x^m)^(1/m))^3, x, 2, -(x/((c*x^m)^m^(-1)*(2*b*(a + b*(c*x^m)^(1/m))^2)))}
{(a + b*(c*x^m)^(1/m))^n, x, 2, (x*(a + b*(c*x^m)^(1/m))^(1 + n))/((c*x^m)^m^(-1)*(b*(1 + n)))}


{(a + b*(c*x^m)^(2/m))^3, x, 3, a^3*x + a^2*b*x*(c*x^m)^(2/m) + (3/5)*a*b^2*x*(c*x^m)^(4/m) + (1/7)*b^3*x*(c*x^m)^(6/m)}
{(a + b*(c*x^m)^(2/m))^2, x, 3, a^2*x + (2/3)*a*b*x*(c*x^m)^(2/m) + (1/5)*b^2*x*(c*x^m)^(4/m)}
{(a + b*(c*x^m)^(2/m)), x, 2, a*x + (1/3)*b*x*(c*x^m)^(2/m)}
{1/(a + b*(c*x^m)^(2/m)), x, 2, (x*ArcTan[(Sqrt[b]*(c*x^m)^(1/m))/Sqrt[a]])/((c*x^m)^m^(-1)*(Sqrt[a]*Sqrt[b]))}
{1/(a + b*(c*x^m)^(2/m))^2, x, 3, x/(2*a*(a + b*(c*x^m)^(2/m))) + (x*ArcTan[(Sqrt[b]*(c*x^m)^(1/m))/Sqrt[a]])/((c*x^m)^m^(-1)*(2*a^(3/2)*Sqrt[b]))}
{1/(a + b*(c*x^m)^(2/m))^3, x, 4, x/(4*a*(a + b*(c*x^m)^(2/m))^2) + (3*x)/(8*a^2*(a + b*(c*x^m)^(2/m))) + (3*x*ArcTan[(Sqrt[b]*(c*x^m)^(1/m))/Sqrt[a]])/((c*x^m)^m^(-1)*(8*a^(5/2)*Sqrt[b]))}


{(a + b*(c*x^m)^(3/m))^3, x, 3, a^3*x + (3/4)*a^2*b*x*(c*x^m)^(3/m) + (3/7)*a*b^2*x*(c*x^m)^(6/m) + (1/10)*b^3*x*(c*x^m)^(9/m)}
{(a + b*(c*x^m)^(3/m))^2, x, 3, a^2*x + (1/2)*a*b*x*(c*x^m)^(3/m) + (1/7)*b^2*x*(c*x^m)^(6/m)}
{(a + b*(c*x^m)^(3/m)), x, 2, a*x + (1/4)*b*x*(c*x^m)^(3/m)}
{1/(a + b*(c*x^m)^(3/m)), x, 5, -((x*ArcTan[(a^(1/3) - 2*b^(1/3)*(c*x^m)^(1/m))/(Sqrt[3]*a^(1/3))])/((c*x^m)^(1/m)*(Sqrt[3]*a^(2/3)*b^(1/3)))) + (x*Log[a^(1/3) + b^(1/3)*(c*x^m)^(1/m)])/((c*x^m)^(1/m)*(3*a^(2/3)*b^(1/3))) - (x*Log[a^(2/3) - a^(1/3)*b^(1/3)*(c*x^m)^(1/m) + b^(2/3)*(c*x^m)^(2/m)])/((c*x^m)^(1/m)*(6*a^(2/3)*b^(1/3)))}
{1/(a + b*(c*x^m)^(3/m))^2, x, 6, x/(3*a*(a + b*(c*x^m)^(3/m))) - (2*x*ArcTan[(a^(1/3) - 2*b^(1/3)*(c*x^m)^(1/m))/(Sqrt[3]*a^(1/3))])/((c*x^m)^m^(-1)*(3*Sqrt[3]*a^(5/3)*b^(1/3))) + (2*x*Log[a^(1/3) + b^(1/3)*(c*x^m)^(1/m)])/((c*x^m)^m^(-1)*(9*a^(5/3)*b^(1/3))) - (x*Log[a^(2/3) - a^(1/3)*b^(1/3)*(c*x^m)^(1/m) + b^(2/3)*(c*x^m)^(2/m)])/((c*x^m)^m^(-1)*(9*a^(5/3)*b^(1/3)))}
{1/(a + b*(c*x^m)^(3/m))^3, x, 7, x/(6*a*(a + b*(c*x^m)^(3/m))^2) + (5*x)/(18*a^2*(a + b*(c*x^m)^(3/m))) - (5*x*ArcTan[(a^(1/3) - 2*b^(1/3)*(c*x^m)^(1/m))/(Sqrt[3]*a^(1/3))])/((c*x^m)^m^(-1)*(9*Sqrt[3]*a^(8/3)*b^(1/3))) + (5*x*Log[a^(1/3) + b^(1/3)*(c*x^m)^(1/m)])/((c*x^m)^m^(-1)*(27*a^(8/3)*b^(1/3))) - (5*x*Log[a^(2/3) - a^(1/3)*b^(1/3)*(c*x^m)^(1/m) + b^(2/3)*(c*x^m)^(2/m)])/((c*x^m)^m^(-1)*(54*a^(8/3)*b^(1/3)))}


{1/(x*(a + b*(c*x^m)^(1/m))), x, 3, Log[(c*x^m)^(1/m)]/a - Log[a + b*(c*x^m)^(1/m)]/a}


(* ::Subsection::Closed:: *)
(*Integrands involving roots of binomials*)


(* Integrands of the form (a+b*(c*x)^n)^m/x where m is a half-integer *)
{(a + b*(c*x)^n)^(5/2)/x, x, 5, (2*a^2*Sqrt[a + b*(c*x)^n])/n + (2*a*(a + b*(c*x)^n)^(3/2))/(3*n) + (2*(a + b*(c*x)^n)^(5/2))/(5*n) - (2*a^(5/2)*ArcTanh[Sqrt[a + b*(c*x)^n]/Sqrt[a]])/n}
{(a + b*(c*x)^n)^(3/2)/x, x, 4, (2*a*Sqrt[a + b*(c*x)^n])/n + (2*(a + b*(c*x)^n)^(3/2))/(3*n) - (2*a^(3/2)*ArcTanh[Sqrt[a + b*(c*x)^n]/Sqrt[a]])/n}
{Sqrt[a + b*(c*x)^n]/x, x, 3, (2*Sqrt[a + b*(c*x)^n])/n - (2*Sqrt[a]*ArcTanh[Sqrt[a + b*(c*x)^n]/Sqrt[a]])/n}
{1/(x*Sqrt[a + b*x^n]), x, 1, (-2*ArcTanh[Sqrt[a + b*x^n]/Sqrt[a]])/(Sqrt[a]*n)}
{1/(x*Sqrt[a + b*(c*x)^n]), x, 2, -((2*ArcTanh[Sqrt[a + b*(c*x)^n]/Sqrt[a]])/(Sqrt[a]*n))}
{1/(x*(a + b*(c*x)^n)^(3/2)), x, 3, 2/(a*n*Sqrt[a + b*(c*x)^n]) - (2*ArcTanh[Sqrt[a + b*(c*x)^n]/Sqrt[a]])/(a^(3/2)*n)}
{1/(x*(a + b*(c*x)^n)^(5/2)), x, 4, 2/(3*a*n*(a + b*(c*x)^n)^(3/2)) + 2/(a^2*n*Sqrt[a + b*(c*x)^n]) - (2*ArcTanh[Sqrt[a + b*(c*x)^n]/Sqrt[a]])/(a^(5/2)*n)}

{(-a + b*(c*x)^n)^(5/2)/x, x, 5, (2*a^2*Sqrt[-a + b*(c*x)^n])/n - (2*a*(-a + b*(c*x)^n)^(3/2))/(3*n) + (2*(-a + b*(c*x)^n)^(5/2))/(5*n) - (2*a^(5/2)*ArcTan[Sqrt[-a + b*(c*x)^n]/Sqrt[a]])/n}
{(-a + b*(c*x)^n)^(3/2)/x, x, 4, -((2*a*Sqrt[-a + b*(c*x)^n])/n) + (2*(-a + b*(c*x)^n)^(3/2))/(3*n) + (2*a^(3/2)*ArcTan[Sqrt[-a + b*(c*x)^n]/Sqrt[a]])/n}
{Sqrt[-a + b*(c*x)^n]/x, x, 3, (2*Sqrt[-a + b*(c*x)^n])/n - (2*Sqrt[a]*ArcTan[Sqrt[-a + b*(c*x)^n]/Sqrt[a]])/n}
{1/(x*Sqrt[-a + b*x^n]), x, 1, (2*ArcTan[Sqrt[-a + b*x^n]/Sqrt[a]])/(Sqrt[a]*n)}
{1/(x*Sqrt[-a + b*(c*x)^n]), x, 2, (2*ArcTan[Sqrt[-a + b*(c*x)^n]/Sqrt[a]])/(Sqrt[a]*n)}
{1/(x*(-a + b*(c*x)^n)^(3/2)), x, 3, -(2/(a*n*Sqrt[-a + b*(c*x)^n])) - (2*ArcTan[Sqrt[-a + b*(c*x)^n]/Sqrt[a]])/(a^(3/2)*n)}
{1/(x*(-a + b*(c*x)^n)^(5/2)), x, 4, -(2/(3*a*n*(-a + b*(c*x)^n)^(3/2))) + 2/(a^2*n*Sqrt[-a + b*(c*x)^n]) + (2*ArcTan[Sqrt[-a + b*(c*x)^n]/Sqrt[a]])/(a^(5/2)*n)}


(* Integrands of the form f[(a*x)^n]/x *)
{1/(x*Sqrt[a + b*x]), x, 1, -((2*ArcTanh[Sqrt[a + b*x]/Sqrt[a]])/Sqrt[a])}
{1/(x*Sqrt[a + b*(c*x)^m]), x, 2, -((2*ArcTanh[Sqrt[a + b*(c*x)^m]/Sqrt[a]])/(Sqrt[a]*m))}
{1/(x*Sqrt[a + b*(c*(d*x)^m)^n]), x, 3, -((2*ArcTanh[Sqrt[a + b*(c*(d*x)^m)^n]/Sqrt[a]])/(Sqrt[a]*m*n))}
{1/(x*Sqrt[a + b*(c*(d*(e*x)^m)^n)^p]), x, 4, -((2*ArcTanh[Sqrt[a + b*(c*(d*(e*x)^m)^n)^p]/Sqrt[a]])/(Sqrt[a]*m*n*p))}
{1/(x*Sqrt[a + b*(c*(d*(e*(f*x)^m)^n)^p)^q]), x, 5, -((2*ArcTanh[Sqrt[a + b*(c*(d*(e*(f*x)^m)^n)^p)^q]/Sqrt[a]])/(Sqrt[a]*m*n*p*q))}


(* Integrands of the form x^(m*n-1)*(a+b*x^n)^p where m is an integer *)
{x*(a + b*x^2)^p, x, 2, (a + b*x^2)^(1 + p)/(2*b*(1 + p))}
{x^3*(a + b*x^2)^p, x, 3, -((a*(a + b*x^2)^(1 + p))/(2*b^2*(1 + p)*(2 + p))) + (x^2*(a + b*x^2)^(1 + p))/(2*b*(2 + p))}
{x^5*(a + b*x^2)^p, x, 4, (a^2*(a + b*x^2)^(1 + p))/(b^3*(1 + p)*(2 + p)*(3 + p)) - (a*x^2*(a + b*x^2)^(1 + p))/(b^2*(2 + p)*(3 + p)) + (x^4*(a + b*x^2)^(1 + p))/(2*b*(3 + p))}
{x^7*(a + b*x^2)^p, x, 5, -((3*a^3*(a + b*x^2)^(1 + p))/(b^4*(1 + p)*(2 + p)*(3 + p)*(4 + p))) + (3*a^2*x^2*(a + b*x^2)^(1 + p))/(b^3*(2 + p)*(3 + p)*(4 + p)) - (3*a*x^4*(a + b*x^2)^(1 + p))/(2*b^2*(3 + p)*(4 + p)) + (x^6*(a + b*x^2)^(1 + p))/(2*b*(4 + p))}

{x^2*(a + b*x^3)^p, x, 2, (a + b*x^3)^(1 + p)/(3*b*(1 + p))}
{x^5*(a + b*x^3)^p, x, 3, -((a*(a + b*x^3)^(1 + p))/(3*b^2*(1 + p)*(2 + p))) + (x^3*(a + b*x^3)^(1 + p))/(3*b*(2 + p))}
{x^8*(a + b*x^3)^p, x, 4, (2*a^2*(a + b*x^3)^(1 + p))/(3*b^3*(1 + p)*(2 + p)*(3 + p)) - (2*a*x^3*(a + b*x^3)^(1 + p))/(3*b^2*(2 + p)*(3 + p)) + (x^6*(a + b*x^3)^(1 + p))/(3*b*(3 + p))}
{x^11*(a + b*x^3)^p, x, 5, -((2*a^3*(a + b*x^3)^(1 + p))/(b^4*(1 + p)*(2 + p)*(3 + p)*(4 + p))) + (2*a^2*x^3*(a + b*x^3)^(1 + p))/(b^3*(2 + p)*(3 + p)*(4 + p)) - (a*x^6*(a + b*x^3)^(1 + p))/(b^2*(3 + p)*(4 + p)) + (x^9*(a + b*x^3)^(1 + p))/(3*b*(4 + p))}

{x^(n - 1)*(a + b*x^n)^p, x, 2, (a + b*x^n)^(1 + p)/(b*n*(1 + p))}
{x^(2*n - 1)*(a + b*x^n)^p, x, 3, -((a*(a + b*x^n)^(1 + p))/(b^2*n*(1 + p)*(2 + p))) + (x^n*(a + b*x^n)^(1 + p))/(b*n*(2 + p))}
{x^(3*n - 1)*(a + b*x^n)^p, x, 4, (2*a^2*(a + b*x^n)^(1 + p))/(b^3*n*(1 + p)*(2 + p)*(3 + p)) - (2*a*x^n*(a + b*x^n)^(1 + p))/(b^2*n*(2 + p)*(3 + p)) + (x^(2*n)*(a + b*x^n)^(1 + p))/(b*n*(3 + p))}
{x^(4*n - 1)*(a + b*x^n)^p, x, 5, -((6*a^3*(a + b*x^n)^(1 + p))/(b^4*n*(1 + p)*(2 + p)*(3 + p)*(4 + p))) + (6*a^2*x^n*(a + b*x^n)^(1 + p))/(b^3*n*(2 + p)*(3 + p)*(4 + p)) - (3*a*x^(2*n)*(a + b*x^n)^(1 + p))/(b^2*n*(3 + p)*(4 + p)) + (x^(3*n)*(a + b*x^n)^(1 + p))/(b*n*(4 + p))}


{x^(-1 - n*q - p*(1 + q))*(x^n*(a + b*x^p))^q, x, 1, -((x^(-n - n*q - p*(1 + q))*(x^n*(a + b*x^p))^(1 + q))/(a*p*(1 + q)))}
{x^(-1 + n - p*(1 + q))*(a*x^n + b*x^p)^q, x, 2, (x^n*(a + b*x^(-n + p)))^(1 + q)/(x^(p*(1 + q))*(a*(n - p)*(1 + q)))}

{(x^(-1 + m)*(2*a*m + b*(2*m - n)*x^n))/(2*(a + b*x^n)^(3/2)), x, 2, x^m/Sqrt[a + b*x^n]}

{x^(3 + 2*n)/Sqrt[a + b*x^n], x, 2, -((4*a*(4 + n)*x^4*Sqrt[a + b*x^n])/(b^2*(8 + n)*(8 + 3*n))) + (2*x^(4 + n)*Sqrt[a + b*x^n])/(b*(8 + 3*n)) + (16*a^2*(4 + n)*Int[x^3/Sqrt[a + b*x^n], x])/(b^2*(64 + 32*n + 3*n^2))}
{x^(3 + n)/Sqrt[a + b*x^n], x, 1, (2*x^4*Sqrt[a + b*x^n])/(b*(8 + n)) - (8*a*Int[x^3/Sqrt[a + b*x^n], x])/(b*(8 + n))}
{x^(3 - n)/Sqrt[a + b*x^n], x, 1, (x^(4 - n)*Sqrt[a + b*x^n])/(a*(4 - n)) - (b*(8 - n)*Int[x^3/Sqrt[a + b*x^n], x])/(2*a*(4 - n))}
{x^(3 - 2*n)/Sqrt[a + b*x^n], x, 2, (x^(4 - 2*n)*Sqrt[a + b*x^n])/(2*a*(2 - n)) - (b*(8 - 3*n)*x^(4 - n)*Sqrt[a + b*x^n])/(4*a^2*(2 - n)*(4 - n)) + (b^2*(8 - 3*n)*(8 - n)*Int[x^3/Sqrt[a + b*x^n], x])/(8*a^2*(8 - 6*n + n^2))}

{x^(m + 2*n)/Sqrt[a + b*x^n], x, 2, -((4*a*(1 + m + n)*x^(1 + m)*Sqrt[a + b*x^n])/(b^2*(2 + 2*m + n)*(2 + 2*m + 3*n))) + (2*x^(1 + m + n)*Sqrt[a + b*x^n])/(b*(2 + 2*m + 3*n)) + (4*a^2*(1 + m)*(1 + m + n)*Int[x^m/Sqrt[a + b*x^n], x])/(b^2*(2 + 2*m + n)*(2 + 2*m + 3*n))}
{x^(m + n)/Sqrt[a + b*x^n], x, 1, (2*x^(1 + m)*Sqrt[a + b*x^n])/(b*(2 + 2*m + n)) - (2*a*(1 + m)*Int[x^m/Sqrt[a + b*x^n], x])/(b*(2 + 2*m + n))}
{x^(m - n)/Sqrt[a + b*x^n], x, 1, (x^(1 + m - n)*Sqrt[a + b*x^n])/(a*(1 + m - n)) - (b*(2 + 2*m - n)*Int[x^m/Sqrt[a + b*x^n], x])/(2*a*(1 + m - n))}
{x^(m - 2*n)/Sqrt[a + b*x^n], x, 2, (x^(1 + m - 2*n)*Sqrt[a + b*x^n])/(a*(1 + m - 2*n)) - (b*(2 + 2*m - 3*n)*x^(1 + m - n)*Sqrt[a + b*x^n])/(2*a^2*(1 + m - 2*n)*(1 + m - n)) + (b^2*(2 + 2*m - 3*n)*(2 + 2*m - n)*Int[x^m/Sqrt[a + b*x^n], x])/(4*a^2*(1 + m - 2*n)*(1 + m - n))}

{x^m/Sqrt[a + b*x^(m-2)], x, 1, (2*x^3*Sqrt[a + b*x^(-2 + m)])/(b*(4 + m)) - (6*a*Int[x^2/Sqrt[a + b*x^(-2 + m)], x])/(b*(4 + m))}
{x^m/Sqrt[a + b*x^(2-m)], x, 1, (x^(1 + m)*Sqrt[a + b*x^(2 - m)])/(a*(1 + m)) - (b*(4 + m)*Int[x^2/Sqrt[a + b*x^(2 - m)], x])/(2*a*(1 + m))}

{-((b*n*x^(-1 + m + n))/(2*(a + b*x^n)^(3/2))) + (m*x^(-1 + m))/Sqrt[a + b*x^n], x, 3, x^m/Sqrt[a + b*x^n], -((b*x^(m + n))/(a*Sqrt[a + b*x^n])) + (x^m*Sqrt[a + b*x^n])/a}


{(x^(1 + m)*(a*(2 + m) + b*(3 + m)*x^2))/Sqrt[a + b*x^2], x, 1, x^(2 + m)*Sqrt[a + b*x^2]}
{(a*(2 + m)*x^(1 + m))/Sqrt[a + b*x^2] + (b*(3 + m)*x^(3 + m))/Sqrt[a + b*x^2], x, 2, x^(2 + m)*Sqrt[a + b*x^2]}


{Simplify[D[x^m/Sqrt[a + b*x], x]], x, 2, x^m/Sqrt[a + b*x]}
{Simplify[D[x^m/Sqrt[a + b*x^2], x]], x, 1, x^m/Sqrt[a + b*x^2]}
{Simplify[D[x^m/Sqrt[a + b*x^n], x]], x, 2, x^m/Sqrt[a + b*x^n]}


{D[x^m/Sqrt[a + b*x], x], x, 5, x^m/Sqrt[a + b*x], -((b*x^(1 + m))/(a*Sqrt[a + b*x])) + (x^m*Sqrt[a + b*x])/a}
{D[x^m/Sqrt[a + b*x^2], x], x, 3, x^m/Sqrt[a + b*x^2], -((b*x^(2 + m))/(a*Sqrt[a + b*x^2])) + (x^m*Sqrt[a + b*x^2])/a}
{D[x^m/Sqrt[a + b*x^n], x], x, 3, x^m/Sqrt[a + b*x^n], -((b*x^(m + n))/(a*Sqrt[a + b*x^n])) + (x^m*Sqrt[a + b*x^n])/a}


{(x^(2*(n - 1))*(a + b*x^n))^(1/2), x, 1, (2*x^(3*(1 - n))*((a + b*x^n)/x^(2*(1 - n)))^(3/2))/(3*b*n)}
{(x^(3*(n - 1))*(a + b*x^n))^(1/3), x, 1, (3*x^(4*(1 - n))*((a + b*x^n)/x^(3*(1 - n)))^(4/3))/(4*b*n)}
{(x^(4*(n - 1))*(a + b*x^n))^(1/4), x, 1, (4*x^(5*(1 - n))*((a + b*x^n)/x^(4*(1 - n)))^(5/4))/(5*b*n)}
{(x^(p*(n - 1))*(a + b*x^n))^(1/p), x, 1, (x^((1 - n)*(1 + p))*((a + b*x^n)/x^((1 - n)*p))^(1 + 1/p))/(b*n*(1 + 1/p)), (x^((1 - n)*(1 + 1/p)*p)*((a + b*x^n)/x^((1 - n)*p))^(1 + 1/p))/(b*n*(1 + 1/p))}

{(x^((n - 1)/p)*(a + b*x^n))^p, x, 1, (x^(((1 - n)*(1 + p))/p)*((a + b*x^n)/x^((1 - n)/p))^(1 + p))/(b*n*(1 + p))}


(* Integrands of the form 1/(x*(a+b*x^n)) *)
{1/(x*(a + b*x^n)), x, 1, Log[x]/a - Log[a + b*x^n]/(a*n)}
{1/(x*(a + b/x^n)), x, 1, Log[b + a*x^n]/(a*n)}
{1/(x*(2 + 3*x^n)), x, 1, -ArcTanh[1 + 3*x^n]/n}
{1/(x*(2 + 3/x^n)), x, 1, Log[3 + 2*x^n]/(2*n)}

{1/((1 + x^(-1/3))*x), x, 1, 3*Log[1 + x^(1/3)]}
{1/((1 + x^(1/3))*x), x, 1, -6*ArcTanh[1 + 2*x^(1/3)]}
{1/((1 + 3*Sqrt[x])*x), x, 1, -4*ArcTanh[1 + 6*Sqrt[x]]}


(* Integrands of the form 1/(a*x+b*x^n) *)
{1/(a*x + b*x^n), x, 2, Log[b + a*x^(1 - n)]/(a*(1 - n))}
{1/(a*x + b*x^(n + 1)), x, 2, Log[x]/a - Log[a + b*x^n]/(a*n)}
{1/(a*x + b/x^(n - 1)), x, 2, Log[b + a*x^n]/(a*n)}
{1/(2*x + 3*x^(n+1)), x, 2, -ArcTanh[1 + 3*x^n]/n}
{1/(2*x + 3/x^(n-1)), x, 2, Log[3 + 2*x^n]/(2*n)}

{1/(-Sqrt[x] + x), x, 2, 2*Log[-1 + Sqrt[x]]}
{1/(-x^(3/5) + x), x, 2, (5/2)*Log[-1 + x^(2/5)]}
{1/(x^(-1/3) + x), x, 2, (3*Log[1 + x^(4/3)])/4}
{1/(x + x^Sqrt[2]), x, 2, -2*(1 + Sqrt[2])*ArcTanh[1 + 2*x^(-1 + Sqrt[2])]}


{x^m/(a + b*x^(m+1)), x, 2, Log[a + b*x^(1 + m)]/(b*(1 + m))}
{x^m*(a + b*x^(m+1))^n, x, 2, (a + b*x^(1 + m))^(1 + n)/(b*(1 + m)*(1 + n))}


(* Integrands of the form x^m*(a+b*x^(2*(m+1))^n where n is an integer *)
{x^m*(a + b*x^(2*(m+1)))^2, x, 2, (a^2*x^(1 + m))/(1 + m) + (2*a*b*x^(3 + 3*m))/(3*(1 + m)) + (b^2*x^(5 + 5*m))/(5*(1 + m))}
{x^m*(a + b*x^(2*(m+1))), x, 2, (a*x^(1 + m))/(1 + m) + (b*x^(3 + 3*m))/(3*(1 + m))}
{x^m/(a + b*x^(2*(m+1))), x, 2, ArcTan[(Sqrt[b]*x^(1 + m))/Sqrt[a]]/(Sqrt[a]*Sqrt[b]*(1 + m))}
{x^m/(a + b*x^(2*(m+1)))^2, x, 3, x^(1 + m)/(2*a*(1 + m)*(a + b*x^(2 + 2*m))) + ArcTan[(Sqrt[b]*x^(1 + m))/Sqrt[a]]/(2*a^(3/2)*Sqrt[b]*(1 + m))}


(* Integrands of the form x^m*(a+b*x^n)^p where n is symbolic and p is a half-integer *)
{x^n*Sqrt[1 + x^(1 + n)], x, 2, (2*(1 + x^(1 + n))^(3/2))/(3*(1 + n))}
{x^n*Sqrt[a^2 + x^(1 + n)], x, 2, (2*(a^2 + x^(1 + n))^(3/2))/(3*(1 + n))}


{(a + b*x^n)^5, x, 2, a^5*x + (5*a^4*b*x^(1 + n))/(1 + n) + (10*a^3*b^2*x^(1 + 2*n))/(1 + 2*n) + (10*a^2*b^3*x^(1 + 3*n))/(1 + 3*n) + (5*a*b^4*x^(1 + 4*n))/(1 + 4*n) + (b^5*x^(1 + 5*n))/(1 + 5*n)}
