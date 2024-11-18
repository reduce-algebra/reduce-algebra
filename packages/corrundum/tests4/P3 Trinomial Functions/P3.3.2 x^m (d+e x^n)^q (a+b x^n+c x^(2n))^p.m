(* ::Package:: *)

(* ::Title:: *)
(*Integration problems of the form x^m (d+e x^3)^n (a+b x^3+c x^6)^p*)


(* ::Section:: *)
(*Integrands of the form x^m (A+B x^3) (a+b x^3+c x^6)^p when a=0*)


(* ::Section:: *)
(*Integrands of the form x^m (A+B x^3) (a+b x^3+c x^6)^p when b=0*)


(* ::Section::Closed:: *)
(*Integrands of the form x^m (A+B x^3) (a+b x^3+c x^6)^p*)


(* ::Subsection::Closed:: *)
(*Integrands of the form x^m (A+B x^3) (a+b x^3+c x^6)^p*)


(* ::Subsubsection:: *)
(*p>0*)


(* ::Subsubsection::Closed:: *)
(*p<0*)


{x^4*(d + e*x^3)/(a + b*x^3 + c*x^6), x, 12, (e*x^2)/(2*c) - ((c*d - b*e - (b*c*d - b^2*e + 2*a*c*e)/Sqrt[b^2 - 4*a*c])*ArcTan[(2^(2/3)*(b - Sqrt[b^2 - 4*a*c])^(1/3) - 4*c^(1/3)*x)/(2^(2/3)*Sqrt[3]*(b - Sqrt[b^2 - 4*a*c])^(1/3))])/(2^(2/3)*Sqrt[3]*c^(5/3)*(b - Sqrt[b^2 - 4*a*c])^(1/3)) - ((c*d - b*e + (b*c*d - b^2*e + 2*a*c*e)/Sqrt[b^2 - 4*a*c])*ArcTan[(2^(2/3)*(b + Sqrt[b^2 - 4*a*c])^(1/3) - 4*c^(1/3)*x)/(2^(2/3)*Sqrt[3]*(b + Sqrt[b^2 - 4*a*c])^(1/3))])/(2^(2/3)*Sqrt[3]*c^(5/3)*(b + Sqrt[b^2 - 4*a*c])^(1/3)) - ((c*d - b*e - (b*c*d - b^2*e + 2*a*c*e)/Sqrt[b^2 - 4*a*c])*Log[(b - Sqrt[b^2 - 4*a*c])^(1/3) + 2^(1/3)*c^(1/3)*x])/(3*2^(2/3)*c^(5/3)*(b - Sqrt[b^2 - 4*a*c])^(1/3)) - ((c*d - b*e + (b*c*d - b^2*e + 2*a*c*e)/Sqrt[b^2 - 4*a*c])*Log[(b + Sqrt[b^2 - 4*a*c])^(1/3) + 2^(1/3)*c^(1/3)*x])/(3*2^(2/3)*c^(5/3)*(b + Sqrt[b^2 - 4*a*c])^(1/3)) + ((c*d - b*e - (b*c*d - b^2*e + 2*a*c*e)/Sqrt[b^2 - 4*a*c])*Log[(b - Sqrt[b^2 - 4*a*c])^(2/3) - 2^(1/3)*c^(1/3)*(b - Sqrt[b^2 - 4*a*c])^(1/3)*x + 2^(2/3)*c^(2/3)*x^2])/(6*2^(2/3)*c^(5/3)*(b - Sqrt[b^2 - 4*a*c])^(1/3)) + ((c*d - b*e + (b*c*d - b^2*e + 2*a*c*e)/Sqrt[b^2 - 4*a*c])*Log[(b + Sqrt[b^2 - 4*a*c])^(2/3) - 2^(1/3)*c^(1/3)*(b + Sqrt[b^2 - 4*a*c])^(1/3)*x + 2^(2/3)*c^(2/3)*x^2])/(6*2^(2/3)*c^(5/3)*(b + Sqrt[b^2 - 4*a*c])^(1/3))}
{x^3*(d + e*x^3)/(a + b*x^3 + c*x^6), x, 12, (e*x)/c + ((2*a*c*e + (b - Sqrt[b^2 - 4*a*c])*(c*d - b*e))*ArcTan[(2^(2/3)*(b - Sqrt[b^2 - 4*a*c])^(1/3) - 4*c^(1/3)*x)/(2^(2/3)*Sqrt[3]*(b - Sqrt[b^2 - 4*a*c])^(1/3))])/(2^(1/3)*Sqrt[3]*c^(4/3)*Sqrt[b^2 - 4*a*c]*(b - Sqrt[b^2 - 4*a*c])^(2/3)) - ((2*a*c*e + (b + Sqrt[b^2 - 4*a*c])*(c*d - b*e))*ArcTan[(2^(2/3)*(b + Sqrt[b^2 - 4*a*c])^(1/3) - 4*c^(1/3)*x)/(2^(2/3)*Sqrt[3]*(b + Sqrt[b^2 - 4*a*c])^(1/3))])/(2^(1/3)*Sqrt[3]*c^(4/3)*Sqrt[b^2 - 4*a*c]*(b + Sqrt[b^2 - 4*a*c])^(2/3)) - ((2*a*c*e + (b - Sqrt[b^2 - 4*a*c])*(c*d - b*e))*Log[(b - Sqrt[b^2 - 4*a*c])^(1/3) + 2^(1/3)*c^(1/3)*x])/(3*2^(1/3)*c^(4/3)*Sqrt[b^2 - 4*a*c]*(b - Sqrt[b^2 - 4*a*c])^(2/3)) + ((2*a*c*e + (b + Sqrt[b^2 - 4*a*c])*(c*d - b*e))*Log[(b + Sqrt[b^2 - 4*a*c])^(1/3) + 2^(1/3)*c^(1/3)*x])/(3*2^(1/3)*c^(4/3)*Sqrt[b^2 - 4*a*c]*(b + Sqrt[b^2 - 4*a*c])^(2/3)) + ((2*a*c*e + (b - Sqrt[b^2 - 4*a*c])*(c*d - b*e))*Log[(b - Sqrt[b^2 - 4*a*c])^(2/3) - 2^(1/3)*c^(1/3)*(b - Sqrt[b^2 - 4*a*c])^(1/3)*x + 2^(2/3)*c^(2/3)*x^2])/(6*2^(1/3)*c^(4/3)*Sqrt[b^2 - 4*a*c]*(b - Sqrt[b^2 - 4*a*c])^(2/3)) - ((2*a*c*e + (b + Sqrt[b^2 - 4*a*c])*(c*d - b*e))*Log[(b + Sqrt[b^2 - 4*a*c])^(2/3) - 2^(1/3)*c^(1/3)*(b + Sqrt[b^2 - 4*a*c])^(1/3)*x + 2^(2/3)*c^(2/3)*x^2])/(6*2^(1/3)*c^(4/3)*Sqrt[b^2 - 4*a*c]*(b + Sqrt[b^2 - 4*a*c])^(2/3))}
{x^2*(d + e*x^3)/(a + b*x^3 + c*x^6), x, 4, -(((2*c*d - b*e)*ArcTanh[(b + 2*c*x^3)/Sqrt[b^2 - 4*a*c]])/(3*c*Sqrt[b^2 - 4*a*c])) + (e*Log[a + b*x^3 + c*x^6])/(6*c)}
{x^1*(d + e*x^3)/(a + b*x^3 + c*x^6), x, 11, -(((e + (2*c*d - b*e)/Sqrt[b^2 - 4*a*c])*ArcTan[(2^(2/3)*(b - Sqrt[b^2 - 4*a*c])^(1/3) - 4*c^(1/3)*x)/(2^(2/3)*Sqrt[3]*(b - Sqrt[b^2 - 4*a*c])^(1/3))])/(2^(2/3)*Sqrt[3]*c^(2/3)*(b - Sqrt[b^2 - 4*a*c])^(1/3))) - ((e - (2*c*d - b*e)/Sqrt[b^2 - 4*a*c])*ArcTan[(2^(2/3)*(b + Sqrt[b^2 - 4*a*c])^(1/3) - 4*c^(1/3)*x)/(2^(2/3)*Sqrt[3]*(b + Sqrt[b^2 - 4*a*c])^(1/3))])/(2^(2/3)*Sqrt[3]*c^(2/3)*(b + Sqrt[b^2 - 4*a*c])^(1/3)) - ((e + (2*c*d - b*e)/Sqrt[b^2 - 4*a*c])*Log[(b - Sqrt[b^2 - 4*a*c])^(1/3) + 2^(1/3)*c^(1/3)*x])/(3*2^(2/3)*c^(2/3)*(b - Sqrt[b^2 - 4*a*c])^(1/3)) - ((e - (2*c*d - b*e)/Sqrt[b^2 - 4*a*c])*Log[(b + Sqrt[b^2 - 4*a*c])^(1/3) + 2^(1/3)*c^(1/3)*x])/(3*2^(2/3)*c^(2/3)*(b + Sqrt[b^2 - 4*a*c])^(1/3)) + ((e + (2*c*d - b*e)/Sqrt[b^2 - 4*a*c])*Log[(b - Sqrt[b^2 - 4*a*c])^(2/3) - 2^(1/3)*c^(1/3)*(b - Sqrt[b^2 - 4*a*c])^(1/3)*x + 2^(2/3)*c^(2/3)*x^2])/(6*2^(2/3)*c^(2/3)*(b - Sqrt[b^2 - 4*a*c])^(1/3)) + ((e - (2*c*d - b*e)/Sqrt[b^2 - 4*a*c])*Log[(b + Sqrt[b^2 - 4*a*c])^(2/3) - 2^(1/3)*c^(1/3)*(b + Sqrt[b^2 - 4*a*c])^(1/3)*x + 2^(2/3)*c^(2/3)*x^2])/(6*2^(2/3)*c^(2/3)*(b + Sqrt[b^2 - 4*a*c])^(1/3))}
{x^0*(d + e*x^3)/(a + b*x^3 + c*x^6), x, 11, -(((2*c*d - (b - Sqrt[b^2 - 4*a*c])*e)*ArcTan[(2^(2/3)*(b - Sqrt[b^2 - 4*a*c])^(1/3) - 4*c^(1/3)*x)/(2^(2/3)*Sqrt[3]*(b - Sqrt[b^2 - 4*a*c])^(1/3))])/(2^(1/3)*Sqrt[3]*c^(1/3)*Sqrt[b^2 - 4*a*c]*(b - Sqrt[b^2 - 4*a*c])^(2/3))) + ((2*c*d - (b + Sqrt[b^2 - 4*a*c])*e)*ArcTan[(2^(2/3)*(b + Sqrt[b^2 - 4*a*c])^(1/3) - 4*c^(1/3)*x)/(2^(2/3)*Sqrt[3]*(b + Sqrt[b^2 - 4*a*c])^(1/3))])/(2^(1/3)*Sqrt[3]*c^(1/3)*Sqrt[b^2 - 4*a*c]*(b + Sqrt[b^2 - 4*a*c])^(2/3)) + ((2*c*d - (b - Sqrt[b^2 - 4*a*c])*e)*Log[(b - Sqrt[b^2 - 4*a*c])^(1/3) + 2^(1/3)*c^(1/3)*x])/(3*2^(1/3)*c^(1/3)*Sqrt[b^2 - 4*a*c]*(b - Sqrt[b^2 - 4*a*c])^(2/3)) - ((2*c*d - (b + Sqrt[b^2 - 4*a*c])*e)*Log[(b + Sqrt[b^2 - 4*a*c])^(1/3) + 2^(1/3)*c^(1/3)*x])/(3*2^(1/3)*c^(1/3)*Sqrt[b^2 - 4*a*c]*(b + Sqrt[b^2 - 4*a*c])^(2/3)) - ((2*c*d - (b - Sqrt[b^2 - 4*a*c])*e)*Log[(b - Sqrt[b^2 - 4*a*c])^(2/3) - 2^(1/3)*c^(1/3)*(b - Sqrt[b^2 - 4*a*c])^(1/3)*x + 2^(2/3)*c^(2/3)*x^2])/(6*2^(1/3)*c^(1/3)*Sqrt[b^2 - 4*a*c]*(b - Sqrt[b^2 - 4*a*c])^(2/3)) + ((2*c*d - (b + Sqrt[b^2 - 4*a*c])*e)*Log[(b + Sqrt[b^2 - 4*a*c])^(2/3) - 2^(1/3)*c^(1/3)*(b + Sqrt[b^2 - 4*a*c])^(1/3)*x + 2^(2/3)*c^(2/3)*x^2])/(6*2^(1/3)*c^(1/3)*Sqrt[b^2 - 4*a*c]*(b + Sqrt[b^2 - 4*a*c])^(2/3))}
{x^(-1)*(d + e*x^3)/(a + b*x^3 + c*x^6), x, 5, ((b*d - 2*a*e)*ArcTanh[(b + 2*c*x^3)/Sqrt[b^2 - 4*a*c]])/(3*a*Sqrt[b^2 - 4*a*c]) + (d*Log[x])/a - (d*Log[a + b*x^3 + c*x^6])/(6*a)}
{x^(-2)*(d + e*x^3)/(a + b*x^3 + c*x^6), x, 12, -(d/(a*x)) + (c^(1/3)*(d + (b*d - 2*a*e)/Sqrt[b^2 - 4*a*c])*ArcTan[(2^(2/3)*(b - Sqrt[b^2 - 4*a*c])^(1/3) - 4*c^(1/3)*x)/(2^(2/3)*Sqrt[3]*(b - Sqrt[b^2 - 4*a*c])^(1/3))])/(2^(2/3)*Sqrt[3]*a*(b - Sqrt[b^2 - 4*a*c])^(1/3)) + (c^(1/3)*(d - (b*d - 2*a*e)/Sqrt[b^2 - 4*a*c])*ArcTan[(2^(2/3)*(b + Sqrt[b^2 - 4*a*c])^(1/3) - 4*c^(1/3)*x)/(2^(2/3)*Sqrt[3]*(b + Sqrt[b^2 - 4*a*c])^(1/3))])/(2^(2/3)*Sqrt[3]*a*(b + Sqrt[b^2 - 4*a*c])^(1/3)) + (c^(1/3)*(d + (b*d - 2*a*e)/Sqrt[b^2 - 4*a*c])*Log[(b - Sqrt[b^2 - 4*a*c])^(1/3) + 2^(1/3)*c^(1/3)*x])/(3*2^(2/3)*a*(b - Sqrt[b^2 - 4*a*c])^(1/3)) + (c^(1/3)*(d - (b*d - 2*a*e)/Sqrt[b^2 - 4*a*c])*Log[(b + Sqrt[b^2 - 4*a*c])^(1/3) + 2^(1/3)*c^(1/3)*x])/(3*2^(2/3)*a*(b + Sqrt[b^2 - 4*a*c])^(1/3)) - (c^(1/3)*(d + (b*d - 2*a*e)/Sqrt[b^2 - 4*a*c])*Log[(b - Sqrt[b^2 - 4*a*c])^(2/3) - 2^(1/3)*c^(1/3)*(b - Sqrt[b^2 - 4*a*c])^(1/3)*x + 2^(2/3)*c^(2/3)*x^2])/(6*2^(2/3)*a*(b - Sqrt[b^2 - 4*a*c])^(1/3)) - (c^(1/3)*(d - (b*d - 2*a*e)/Sqrt[b^2 - 4*a*c])*Log[(b + Sqrt[b^2 - 4*a*c])^(2/3) - 2^(1/3)*c^(1/3)*(b + Sqrt[b^2 - 4*a*c])^(1/3)*x + 2^(2/3)*c^(2/3)*x^2])/(6*2^(2/3)*a*(b + Sqrt[b^2 - 4*a*c])^(1/3))}
{x^(-3)*(d + e*x^3)/(a + b*x^3 + c*x^6), x, 12, -(d/(2*a*x^2)) + (c^(2/3)*(b*d + Sqrt[b^2 - 4*a*c]*d - 2*a*e)*ArcTan[(2^(2/3)*(b - Sqrt[b^2 - 4*a*c])^(1/3) - 4*c^(1/3)*x)/(2^(2/3)*Sqrt[3]*(b - Sqrt[b^2 - 4*a*c])^(1/3))])/(2^(1/3)*Sqrt[3]*a*Sqrt[b^2 - 4*a*c]*(b - Sqrt[b^2 - 4*a*c])^(2/3)) - (c^(2/3)*(b*d - Sqrt[b^2 - 4*a*c]*d - 2*a*e)*ArcTan[(2^(2/3)*(b + Sqrt[b^2 - 4*a*c])^(1/3) - 4*c^(1/3)*x)/(2^(2/3)*Sqrt[3]*(b + Sqrt[b^2 - 4*a*c])^(1/3))])/(2^(1/3)*Sqrt[3]*a*Sqrt[b^2 - 4*a*c]*(b + Sqrt[b^2 - 4*a*c])^(2/3)) - (c^(2/3)*(b*d + Sqrt[b^2 - 4*a*c]*d - 2*a*e)*Log[(b - Sqrt[b^2 - 4*a*c])^(1/3) + 2^(1/3)*c^(1/3)*x])/(3*2^(1/3)*a*Sqrt[b^2 - 4*a*c]*(b - Sqrt[b^2 - 4*a*c])^(2/3)) + (c^(2/3)*(b*d - Sqrt[b^2 - 4*a*c]*d - 2*a*e)*Log[(b + Sqrt[b^2 - 4*a*c])^(1/3) + 2^(1/3)*c^(1/3)*x])/(3*2^(1/3)*a*Sqrt[b^2 - 4*a*c]*(b + Sqrt[b^2 - 4*a*c])^(2/3)) + (c^(2/3)*(b*d + Sqrt[b^2 - 4*a*c]*d - 2*a*e)*Log[(b - Sqrt[b^2 - 4*a*c])^(2/3) - 2^(1/3)*c^(1/3)*(b - Sqrt[b^2 - 4*a*c])^(1/3)*x + 2^(2/3)*c^(2/3)*x^2])/(6*2^(1/3)*a*Sqrt[b^2 - 4*a*c]*(b - Sqrt[b^2 - 4*a*c])^(2/3)) - (c^(2/3)*(b*d - Sqrt[b^2 - 4*a*c]*d - 2*a*e)*Log[(b + Sqrt[b^2 - 4*a*c])^(2/3) - 2^(1/3)*c^(1/3)*(b + Sqrt[b^2 - 4*a*c])^(1/3)*x + 2^(2/3)*c^(2/3)*x^2])/(6*2^(1/3)*a*Sqrt[b^2 - 4*a*c]*(b + Sqrt[b^2 - 4*a*c])^(2/3))}
{x^(-4)*(d + e*x^3)/(a + b*x^3 + c*x^6), x, 6, -(d/(3*a*x^3)) - ((b^2*d - 2*a*c*d - a*b*e)*ArcTanh[(b + 2*c*x^3)/Sqrt[b^2 - 4*a*c]])/(3*a^2*Sqrt[b^2 - 4*a*c]) - ((b*d - a*e)*Log[x])/a^2 + ((b*d - a*e)*Log[a + b*x^3 + c*x^6])/(6*a^2)}


{x^6*(1 - x^3)/(1 - x^3 + x^6), x, 12, -(x^4/4) - ((I + Sqrt[3])*ArcTan[(2^(2/3)*(1 - I*Sqrt[3])^(1/3) + 4*x)/(2^(2/3)*Sqrt[3]*(1 - I*Sqrt[3])^(1/3))])/(3*2^(1/3)*(1 - I*Sqrt[3])^(2/3)) + ((I - Sqrt[3])*ArcTan[(2^(2/3)*(1 + I*Sqrt[3])^(1/3) + 4*x)/(2^(2/3)*Sqrt[3]*(1 + I*Sqrt[3])^(1/3))])/(3*2^(1/3)*(1 + I*Sqrt[3])^(2/3)) + ((I + Sqrt[3])*Log[(1 - I*Sqrt[3])^(1/3) - 2^(1/3)*x])/(3*2^(1/3)*Sqrt[3]*(1 - I*Sqrt[3])^(2/3)) - ((I - Sqrt[3])*Log[(1 + I*Sqrt[3])^(1/3) - 2^(1/3)*x])/(3*2^(1/3)*Sqrt[3]*(1 + I*Sqrt[3])^(2/3)) - ((I + Sqrt[3])*Log[(1 - I*Sqrt[3])^(2/3) + (2*(1 - I*Sqrt[3]))^(1/3)*x + 2^(2/3)*x^2])/(6*2^(1/3)*Sqrt[3]*(1 - I*Sqrt[3])^(2/3)) + ((I - Sqrt[3])*Log[(1 + I*Sqrt[3])^(2/3) + (2*(1 + I*Sqrt[3]))^(1/3)*x + 2^(2/3)*x^2])/(6*2^(1/3)*Sqrt[3]*(1 + I*Sqrt[3])^(2/3))}
{x^5*(1 - x^3)/(1 - x^3 + x^6), x, 4, -(x^3/3) - (2*ArcTan[(1 - 2*x^3)/Sqrt[3]])/(3*Sqrt[3])}
{x^4*(1 - x^3)/(1 - x^3 + x^6), x, 12, -(x^2/2) + (I*ArcTan[(2^(2/3)*(1 - I*Sqrt[3])^(1/3) + 4*x)/(2^(2/3)*Sqrt[3]*(1 - I*Sqrt[3])^(1/3))])/(3*((1/2)*(1 - I*Sqrt[3]))^(1/3)) - (I*ArcTan[(2^(2/3)*(1 + I*Sqrt[3])^(1/3) + 4*x)/(2^(2/3)*Sqrt[3]*(1 + I*Sqrt[3])^(1/3))])/(3*((1/2)*(1 + I*Sqrt[3]))^(1/3)) + (I*Log[(1 - I*Sqrt[3])^(1/3) - 2^(1/3)*x])/(3*Sqrt[3]*((1/2)*(1 - I*Sqrt[3]))^(1/3)) - (I*Log[(1 + I*Sqrt[3])^(1/3) - 2^(1/3)*x])/(3*Sqrt[3]*((1/2)*(1 + I*Sqrt[3]))^(1/3)) - (I*Log[(1 - I*Sqrt[3])^(2/3) + (2*(1 - I*Sqrt[3]))^(1/3)*x + 2^(2/3)*x^2])/(3*2^(2/3)*Sqrt[3]*(1 - I*Sqrt[3])^(1/3)) + (I*Log[(1 + I*Sqrt[3])^(2/3) + (2*(1 + I*Sqrt[3]))^(1/3)*x + 2^(2/3)*x^2])/(3*2^(2/3)*Sqrt[3]*(1 + I*Sqrt[3])^(1/3))}
{x^3*(1 - x^3)/(1 - x^3 + x^6), x, 12, -x - (I*ArcTan[(2^(2/3)*(1 - I*Sqrt[3])^(1/3) + 4*x)/(2^(2/3)*Sqrt[3]*(1 - I*Sqrt[3])^(1/3))])/(3*((1/2)*(1 - I*Sqrt[3]))^(2/3)) + (I*ArcTan[(2^(2/3)*(1 + I*Sqrt[3])^(1/3) + 4*x)/(2^(2/3)*Sqrt[3]*(1 + I*Sqrt[3])^(1/3))])/(3*((1/2)*(1 + I*Sqrt[3]))^(2/3)) + (I*Log[(1 - I*Sqrt[3])^(1/3) - 2^(1/3)*x])/(3*Sqrt[3]*((1/2)*(1 - I*Sqrt[3]))^(2/3)) - (I*Log[(1 + I*Sqrt[3])^(1/3) - 2^(1/3)*x])/(3*Sqrt[3]*((1/2)*(1 + I*Sqrt[3]))^(2/3)) - (I*Log[(1 - I*Sqrt[3])^(2/3) + (2*(1 - I*Sqrt[3]))^(1/3)*x + 2^(2/3)*x^2])/(3*2^(1/3)*Sqrt[3]*(1 - I*Sqrt[3])^(2/3)) + (I*Log[(1 + I*Sqrt[3])^(2/3) + (2*(1 + I*Sqrt[3]))^(1/3)*x + 2^(2/3)*x^2])/(3*2^(1/3)*Sqrt[3]*(1 + I*Sqrt[3])^(2/3))}
{x^2*(1 - x^3)/(1 - x^3 + x^6), x, 4, -(ArcTan[(1 - 2*x^3)/Sqrt[3]]/(3*Sqrt[3])) - (1/6)*Log[1 - x^3 + x^6]}
{x^1*(1 - x^3)/(1 - x^3 + x^6), x, 11, ((I - Sqrt[3])*ArcTan[(2^(2/3)*(1 - I*Sqrt[3])^(1/3) + 4*x)/(2^(2/3)*Sqrt[3]*(1 - I*Sqrt[3])^(1/3))])/(3*2^(2/3)*(1 - I*Sqrt[3])^(1/3)) - ((I + Sqrt[3])*ArcTan[(2^(2/3)*(1 + I*Sqrt[3])^(1/3) + 4*x)/(2^(2/3)*Sqrt[3]*(1 + I*Sqrt[3])^(1/3))])/(3*2^(2/3)*(1 + I*Sqrt[3])^(1/3)) + (I*(3*I + Sqrt[3])*Log[(1 - I*Sqrt[3])^(1/3) - 2^(1/3)*x])/(9*2^(2/3)*(1 - I*Sqrt[3])^(1/3)) - ((I + Sqrt[3])*Log[(1 + I*Sqrt[3])^(1/3) - 2^(1/3)*x])/(3*2^(2/3)*Sqrt[3]*(1 + I*Sqrt[3])^(1/3)) - (I*(3*I + Sqrt[3])*Log[(1 - I*Sqrt[3])^(2/3) + (2*(1 - I*Sqrt[3]))^(1/3)*x + 2^(2/3)*x^2])/(18*2^(2/3)*(1 - I*Sqrt[3])^(1/3)) + ((I + Sqrt[3])*Log[(1 + I*Sqrt[3])^(2/3) + (2*(1 + I*Sqrt[3]))^(1/3)*x + 2^(2/3)*x^2])/(6*2^(2/3)*Sqrt[3]*(1 + I*Sqrt[3])^(1/3))}
{x^0*(1 - x^3)/(1 - x^3 + x^6), x, 11, -(((I - Sqrt[3])*ArcTan[(2^(2/3)*(1 - I*Sqrt[3])^(1/3) + 4*x)/(2^(2/3)*Sqrt[3]*(1 - I*Sqrt[3])^(1/3))])/(3*2^(1/3)*(1 - I*Sqrt[3])^(2/3))) + ((I + Sqrt[3])*ArcTan[(2^(2/3)*(1 + I*Sqrt[3])^(1/3) + 4*x)/(2^(2/3)*Sqrt[3]*(1 + I*Sqrt[3])^(1/3))])/(3*2^(1/3)*(1 + I*Sqrt[3])^(2/3)) + ((I - Sqrt[3])*Log[(1 - I*Sqrt[3])^(1/3) - 2^(1/3)*x])/(3*2^(1/3)*Sqrt[3]*(1 - I*Sqrt[3])^(2/3)) - ((I + Sqrt[3])*Log[(1 + I*Sqrt[3])^(1/3) - 2^(1/3)*x])/(3*2^(1/3)*Sqrt[3]*(1 + I*Sqrt[3])^(2/3)) - ((I - Sqrt[3])*Log[(1 - I*Sqrt[3])^(2/3) + (2*(1 - I*Sqrt[3]))^(1/3)*x + 2^(2/3)*x^2])/(6*2^(1/3)*Sqrt[3]*(1 - I*Sqrt[3])^(2/3)) + ((I + Sqrt[3])*Log[(1 + I*Sqrt[3])^(2/3) + (2*(1 + I*Sqrt[3]))^(1/3)*x + 2^(2/3)*x^2])/(6*2^(1/3)*Sqrt[3]*(1 + I*Sqrt[3])^(2/3))}
{x^(-1)*(1 - x^3)/(1 - x^3 + x^6), x, 5, ArcTan[(1 - 2*x^3)/Sqrt[3]]/(3*Sqrt[3]) + Log[x] - (1/6)*Log[1 - x^3 + x^6]}
{x^(-2)*(1 - x^3)/(1 - x^3 + x^6), x, 12, -(1/x) - (1/3)*I*((1/2)*(1 - I*Sqrt[3]))^(2/3)*ArcTan[(2^(2/3)*(1 - I*Sqrt[3])^(1/3) + 4*x)/(2^(2/3)*Sqrt[3]*(1 - I*Sqrt[3])^(1/3))] + (1/3)*I*((1/2)*(1 + I*Sqrt[3]))^(2/3)*ArcTan[(2^(2/3)*(1 + I*Sqrt[3])^(1/3) + 4*x)/(2^(2/3)*Sqrt[3]*(1 + I*Sqrt[3])^(1/3))] - ((I + Sqrt[3])*Log[(1 - I*Sqrt[3])^(1/3) - 2^(1/3)*x])/(3*2^(2/3)*Sqrt[3]*(1 - I*Sqrt[3])^(1/3)) + (I*(3*I + Sqrt[3])*Log[(1 + I*Sqrt[3])^(1/3) - 2^(1/3)*x])/(9*2^(2/3)*(1 + I*Sqrt[3])^(1/3)) + ((I + Sqrt[3])*Log[(1 - I*Sqrt[3])^(2/3) + (2*(1 - I*Sqrt[3]))^(1/3)*x + 2^(2/3)*x^2])/(6*2^(2/3)*Sqrt[3]*(1 - I*Sqrt[3])^(1/3)) - (I*(3*I + Sqrt[3])*Log[(1 + I*Sqrt[3])^(2/3) + (2*(1 + I*Sqrt[3]))^(1/3)*x + 2^(2/3)*x^2])/(18*2^(2/3)*(1 + I*Sqrt[3])^(1/3))}
{x^(-3)*(1 - x^3)/(1 - x^3 + x^6), x, 12, -(1/(2*x^2)) + ((I + Sqrt[3])*ArcTan[(2^(2/3)*(1 - I*Sqrt[3])^(1/3) + 4*x)/(2^(2/3)*Sqrt[3]*(1 - I*Sqrt[3])^(1/3))])/(3*2^(1/3)*(1 - I*Sqrt[3])^(2/3)) - ((I - Sqrt[3])*ArcTan[(2^(2/3)*(1 + I*Sqrt[3])^(1/3) + 4*x)/(2^(2/3)*Sqrt[3]*(1 + I*Sqrt[3])^(1/3))])/(3*2^(1/3)*(1 + I*Sqrt[3])^(2/3)) - ((I + Sqrt[3])*Log[(1 - I*Sqrt[3])^(1/3) - 2^(1/3)*x])/(3*2^(1/3)*Sqrt[3]*(1 - I*Sqrt[3])^(2/3)) + ((I - Sqrt[3])*Log[(1 + I*Sqrt[3])^(1/3) - 2^(1/3)*x])/(3*2^(1/3)*Sqrt[3]*(1 + I*Sqrt[3])^(2/3)) + ((I + Sqrt[3])*Log[(1 - I*Sqrt[3])^(2/3) + (2*(1 - I*Sqrt[3]))^(1/3)*x + 2^(2/3)*x^2])/(6*2^(1/3)*Sqrt[3]*(1 - I*Sqrt[3])^(2/3)) - ((I - Sqrt[3])*Log[(1 + I*Sqrt[3])^(2/3) + (2*(1 + I*Sqrt[3]))^(1/3)*x + 2^(2/3)*x^2])/(6*2^(1/3)*Sqrt[3]*(1 + I*Sqrt[3])^(2/3))}
{x^(-4)*(1 - x^3)/(1 - x^3 + x^6), x, 3, -(1/(3*x^3)) + (2*ArcTan[(1 - 2*x^3)/Sqrt[3]])/(3*Sqrt[3])}


{(x^2*(-2 + x^3))/(1 - x^3 + x^6), x, 4, ArcTan[(1 - 2*x^3)/Sqrt[3]]/Sqrt[3] + (1/6)*Log[1 - x^3 + x^6]}
{(1 + x^3)/(x*(1 - x^3 + x^6)), x, 5, -(ArcTan[(1 - 2*x^3)/Sqrt[3]]/Sqrt[3]) + Log[x] - (1/6)*Log[1 - x^3 + x^6]}


(* ::Subsection::Closed:: *)
(*Integrands of the form x^m (A+B x^3) (a+b x^3+c x^6)^(p/2)*)


(* ::Subsubsection:: *)
(*p>0*)


(* ::Subsubsection:: *)
(*p<0*)


(* ::Subsection::Closed:: *)
(*Integrands of the form x^(m/2) (A+B x^3) (a+b x^3+c x^6)^p*)


(* ::Subsubsection:: *)
(*p>0*)


(* ::Subsubsection:: *)
(*p<0*)


(* ::Subsection::Closed:: *)
(*Integrands of the form x^(m/2) (A+B x^3) (a+b x^3+c x^6)^(p/2)*)


(* ::Subsubsection:: *)
(*p>0*)


(* ::Subsubsection:: *)
(*p<0*)


(* ::Section::Closed:: *)
(*Integrands of the form x^m (d+e x^3)^n (a+b x^3+c x^6)*)


(* ::Subsection::Closed:: *)
(*Integrands of the form x^m (d+e x^3)^n (a+b x^3+c x^6)*)


{(d + e*x^3)^5*(a + b*x^3 + c*x^6), x, 2, a*d^5*x + (1/4)*d^4*(b*d + 5*a*e)*x^4 + (1/7)*d^3*(c*d^2 + 5*e*(b*d + 2*a*e))*x^7 + (1/2)*d^2*e*(c*d^2 + 2*e*(b*d + a*e))*x^10 + (5/13)*d*e^2*(2*c*d^2 + e*(2*b*d + a*e))*x^13 + (1/16)*e^3*(10*c*d^2 + e*(5*b*d + a*e))*x^16 + (1/19)*e^4*(5*c*d + b*e)*x^19 + (1/22)*c*e^5*x^22}
{(d + e*x^3)^4*(a + b*x^3 + c*x^6), x, 2, a*d^4*x + (d^3*(b*d + 4*a*e)*x^4)/4 + (d^2*(c*d^2 + 4*b*d*e + 6*a*e^2)*x^7)/7 + (d*e*(2*c*d^2 + e*(3*b*d + 2*a*e))*x^10)/5 + (e^2*(6*c*d^2 + e*(4*b*d + a*e))*x^13)/13 + (e^3*(4*c*d + b*e)*x^16)/16 + (c*e^4*x^19)/19}
{(d + e*x^3)^3*(a + b*x^3 + c*x^6), x, 2, a*d^3*x + (d^2*(b*d + 3*a*e)*x^4)/4 + (d*(c*d^2 + 3*e*(b*d + a*e))*x^7)/7 + (e*(3*c*d^2 + e*(3*b*d + a*e))*x^10)/10 + (e^2*(3*c*d + b*e)*x^13)/13 + (c*e^3*x^16)/16}
{(d + e*x^3)^2*(a + b*x^3 + c*x^6), x, 2, a*d^2*x + (d*(b*d + 2*a*e)*x^4)/4 + ((c*d^2 + e*(2*b*d + a*e))*x^7)/7 + (e*(2*c*d + b*e)*x^10)/10 + (c*e^2*x^13)/13}
{(d + e*x^3)*(a + b*x^3 + c*x^6), x, 2, a*d*x + ((b*d + a*e)*x^4)/4 + ((c*d + b*e)*x^7)/7 + (c*e*x^10)/10}
{(a + b*x^3 + c*x^6)/(d + e*x^3), x, 7, -(((c*d - b*e)*x)/e^2) + (c*x^4)/(4*e) - ((c*d^2 - b*d*e + a*e^2)*ArcTan[(d^(1/3) - 2*e^(1/3)*x)/(Sqrt[3]*d^(1/3))])/(Sqrt[3]*d^(2/3)*e^(7/3)) + ((c*d^2 - b*d*e + a*e^2)*Log[d^(1/3) + e^(1/3)*x])/(3*d^(2/3)*e^(7/3)) - ((c*d^2 - b*d*e + a*e^2)*Log[d^(2/3) - d^(1/3)*e^(1/3)*x + e^(2/3)*x^2])/(6*d^(2/3)*e^(7/3))}
{(a + b*x^3 + c*x^6)/(d + e*x^3)^2, x, 7, (c*x)/e^2 + ((c*d^2 - b*d*e + a*e^2)*x)/(3*d*e^2*(d + e*x^3)) + ((4*c*d^2 - e*(b*d + 2*a*e))*ArcTan[(d^(1/3) - 2*e^(1/3)*x)/(Sqrt[3]*d^(1/3))])/(3*Sqrt[3]*d^(5/3)*e^(7/3)) - ((4*c*d^2 - e*(b*d + 2*a*e))*Log[d^(1/3) + e^(1/3)*x])/(9*d^(5/3)*e^(7/3)) + ((4*c*d^2 - e*(b*d + 2*a*e))*Log[d^(2/3) - d^(1/3)*e^(1/3)*x + e^(2/3)*x^2])/(18*d^(5/3)*e^(7/3))}
{(a + b*x^3 + c*x^6)/(d + e*x^3)^3, x, 7, ((c*d^2 - b*d*e + a*e^2)*x)/(6*d*e^2*(d + e*x^3)^2) - ((7*c*d^2 - e*(b*d + 5*a*e))*x)/(18*d^2*e^2*(d + e*x^3)) - ((2*c*d^2 + e*(b*d + 5*a*e))*ArcTan[(d^(1/3) - 2*e^(1/3)*x)/(Sqrt[3]*d^(1/3))])/(9*Sqrt[3]*d^(8/3)*e^(7/3)) + ((2*c*d^2 + e*(b*d + 5*a*e))*Log[d^(1/3) + e^(1/3)*x])/(27*d^(8/3)*e^(7/3)) - ((2*c*d^2 + e*(b*d + 5*a*e))*Log[d^(2/3) - d^(1/3)*e^(1/3)*x + e^(2/3)*x^2])/(54*d^(8/3)*e^(7/3))}


(* ::Subsection::Closed:: *)
(*Integrands of the form x^m (d+e x^3)^(n/2) (a+b x^3+c x^6)*)


(* Mathematica cannot verify these by differentiation, but random substitution of numeric values for parameters does make them appear to be correct. *)
{(a + b*x^3 + c*x^6)*(d + e*x^3)^(3/2), x, 8, (18*d*(16*c*d^2 - 46*b*d*e + 391*a*e^2)*x*Sqrt[d + e*x^3])/(21505*e^2) + (2*(16*c*d^2 - 46*b*d*e + 391*a*e^2)*x*(d + e*x^3)^(3/2))/(4301*e^2) - (2*(c*d^2 - b*d*e + a*e^2)*x*(d + e*x^3)^(5/2))/(15*d*e^2) + (2*(16*c*d^2 - 46*b*d*e + 391*a*e^2)*x*(d + e*x^3)^(5/2))/(5865*d*e^2) + (2*c*x*(d + e*x^3)^(7/2))/(23*e^2) + (1/(21505*e^(5/2)*Sqrt[d + e*x^3]))*(27*Sqrt[2]*3^(1/4)*d^(13/6)*Sqrt[-Sqrt[-e^(2/3)] + Sqrt[3]*e^(1/3)]*(16*c*d^2 - 23*e*(2*b*d - 17*a*e))*Sqrt[d^(1/3) + e^(1/3)*x]*Sqrt[(d^(1/3)*(Sqrt[3]*Sqrt[-e^(2/3)] + e^(1/3)) - 2*e^(2/3)*x)/(d^(1/3)*(Sqrt[3]*Sqrt[-e^(2/3)] + 3*e^(1/3)))]*Sqrt[(d^(1/3)*(Sqrt[3]*Sqrt[-e^(2/3)] - e^(1/3)) + 2*e^(2/3)*x)/(d^(1/3)*(Sqrt[3]*Sqrt[-e^(2/3)] - 3*e^(1/3)))]*EllipticF[ArcSin[(Sqrt[2]*e^(1/6)*Sqrt[d^(1/3) + e^(1/3)*x])/(3^(1/4)*d^(1/6)*Sqrt[-Sqrt[-e^(2/3)] + Sqrt[3]*e^(1/3)])], -((Sqrt[3]*Sqrt[-e^(2/3)] - 3*e^(1/3))/(Sqrt[3]*Sqrt[-e^(2/3)] + 3*e^(1/3)))])}
{(a + b*x^3 + c*x^6)*(d + e*x^3)^(1/2), x, 7, (2*(16*c*d^2 - 34*b*d*e + 187*a*e^2)*x*Sqrt[d + e*x^3])/(935*e^2) - (2*(c*d^2 - b*d*e + a*e^2)*x*(d + e*x^3)^(3/2))/(9*d*e^2) + (2*(16*c*d^2 - 34*b*d*e + 187*a*e^2)*x*(d + e*x^3)^(3/2))/(1683*d*e^2) + (2*c*x*(d + e*x^3)^(5/2))/(17*e^2) + (1/(935*e^(5/2)*Sqrt[d + e*x^3]))*(3*Sqrt[2]*3^(1/4)*d^(7/6)*Sqrt[-Sqrt[-e^(2/3)] + Sqrt[3]*e^(1/3)]*(16*c*d^2 - 17*e*(2*b*d - 11*a*e))*Sqrt[d^(1/3) + e^(1/3)*x]*Sqrt[(d^(1/3)*(Sqrt[3]*Sqrt[-e^(2/3)] + e^(1/3)) - 2*e^(2/3)*x)/(d^(1/3)*(Sqrt[3]*Sqrt[-e^(2/3)] + 3*e^(1/3)))]*Sqrt[(d^(1/3)*(Sqrt[3]*Sqrt[-e^(2/3)] - e^(1/3)) + 2*e^(2/3)*x)/(d^(1/3)*(Sqrt[3]*Sqrt[-e^(2/3)] - 3*e^(1/3)))]*EllipticF[ArcSin[(Sqrt[2]*e^(1/6)*Sqrt[d^(1/3) + e^(1/3)*x])/(3^(1/4)*d^(1/6)*Sqrt[-Sqrt[-e^(2/3)] + Sqrt[3]*e^(1/3)])], -((Sqrt[3]*Sqrt[-e^(2/3)] - 3*e^(1/3))/(Sqrt[3]*Sqrt[-e^(2/3)] + 3*e^(1/3)))])}
{(a + b*x^3 + c*x^6)/(d + e*x^3)^(1/2), x, 6, -((2*(c*d^2 - b*d*e + a*e^2)*x*Sqrt[d + e*x^3])/(3*d*e^2)) + (2*(16*c*d^2 - 22*b*d*e + 55*a*e^2)*x*Sqrt[d + e*x^3])/(165*d*e^2) + (2*c*x*(d + e*x^3)^(3/2))/(11*e^2) + (Sqrt[2]*3^(1/4)*d^(1/6)*Sqrt[-Sqrt[-e^(2/3)] + Sqrt[3]*e^(1/3)]*(16*c*d^2 - 11*e*(2*b*d - 5*a*e))*Sqrt[d^(1/3) + e^(1/3)*x]*Sqrt[(d^(1/3)*(Sqrt[3]*Sqrt[-e^(2/3)] + e^(1/3)) - 2*e^(2/3)*x)/(d^(1/3)*(Sqrt[3]*Sqrt[-e^(2/3)] + 3*e^(1/3)))]*Sqrt[(d^(1/3)*(Sqrt[3]*Sqrt[-e^(2/3)] - e^(1/3)) + 2*e^(2/3)*x)/(d^(1/3)*(Sqrt[3]*Sqrt[-e^(2/3)] - 3*e^(1/3)))]*EllipticF[ArcSin[(Sqrt[2]*e^(1/6)*Sqrt[d^(1/3) + e^(1/3)*x])/(3^(1/4)*d^(1/6)*Sqrt[-Sqrt[-e^(2/3)] + Sqrt[3]*e^(1/3)])], -((Sqrt[3]*Sqrt[-e^(2/3)] - 3*e^(1/3))/(Sqrt[3]*Sqrt[-e^(2/3)] + 3*e^(1/3)))])/(55*e^(5/2)*Sqrt[d + e*x^3])}
{(a + b*x^3 + c*x^6)/(d + e*x^3)^(3/2), x, 5, (2*(c*d^2 - b*d*e + a*e^2)*x)/(3*d*e^2*Sqrt[d + e*x^3]) + (2*c*x*Sqrt[d + e*x^3])/(5*e^2) - (1/(5*3^(3/4)*d^(5/6)*e^(5/2)*Sqrt[d + e*x^3]))*(Sqrt[2]*Sqrt[-Sqrt[-e^(2/3)] + Sqrt[3]*e^(1/3)]*(16*c*d^2 - 5*e*(2*b*d + a*e))*Sqrt[d^(1/3) + e^(1/3)*x]*Sqrt[(d^(1/3)*(Sqrt[3]*Sqrt[-e^(2/3)] + e^(1/3)) - 2*e^(2/3)*x)/(d^(1/3)*(Sqrt[3]*Sqrt[-e^(2/3)] + 3*e^(1/3)))]*Sqrt[(d^(1/3)*(Sqrt[3]*Sqrt[-e^(2/3)] - e^(1/3)) + 2*e^(2/3)*x)/(d^(1/3)*(Sqrt[3]*Sqrt[-e^(2/3)] - 3*e^(1/3)))]*EllipticF[ArcSin[(Sqrt[2]*e^(1/6)*Sqrt[d^(1/3) + e^(1/3)*x])/(3^(1/4)*d^(1/6)*Sqrt[-Sqrt[-e^(2/3)] + Sqrt[3]*e^(1/3)])], -((Sqrt[3]*Sqrt[-e^(2/3)] - 3*e^(1/3))/(Sqrt[3]*Sqrt[-e^(2/3)] + 3*e^(1/3)))])}
{(a + b*x^3 + c*x^6)/(d + e*x^3)^(5/2), x, 5, (2*(c*d^2 - b*d*e + a*e^2)*x)/(9*d*e^2*(d + e*x^3)^(3/2)) - (2*(11*c*d^2 - 2*b*d*e - 7*a*e^2)*x)/(27*d^2*e^2*Sqrt[d + e*x^3]) + (1/(9*3^(3/4)*d^(11/6)*e^(5/2)*Sqrt[d + e*x^3]))*(Sqrt[2]*Sqrt[-Sqrt[-e^(2/3)] + Sqrt[3]*e^(1/3)]*(16*c*d^2 + e*(2*b*d + 7*a*e))*Sqrt[d^(1/3) + e^(1/3)*x]*Sqrt[(d^(1/3)*(Sqrt[3]*Sqrt[-e^(2/3)] + e^(1/3)) - 2*e^(2/3)*x)/(d^(1/3)*(Sqrt[3]*Sqrt[-e^(2/3)] + 3*e^(1/3)))]*Sqrt[(d^(1/3)*(Sqrt[3]*Sqrt[-e^(2/3)] - e^(1/3)) + 2*e^(2/3)*x)/(d^(1/3)*(Sqrt[3]*Sqrt[-e^(2/3)] - 3*e^(1/3)))]*EllipticF[ArcSin[(Sqrt[2]*e^(1/6)*Sqrt[d^(1/3) + e^(1/3)*x])/(3^(1/4)*d^(1/6)*Sqrt[-Sqrt[-e^(2/3)] + Sqrt[3]*e^(1/3)])], -((Sqrt[3]*Sqrt[-e^(2/3)] - 3*e^(1/3))/(Sqrt[3]*Sqrt[-e^(2/3)] + 3*e^(1/3)))])}
{(a + b*x^3 + c*x^6)/(d + e*x^3)^(7/2), x, 6, (2*(c*d^2 - b*d*e + a*e^2)*x)/(15*d*e^2*(d + e*x^3)^(5/2)) - (2*(17*c*d^2 - 2*b*d*e - 13*a*e^2)*x)/(135*d^2*e^2*(d + e*x^3)^(3/2)) + (2*(16*c*d^2 + 14*b*d*e + 91*a*e^2)*x)/(405*d^3*e^2*Sqrt[d + e*x^3]) + (Sqrt[2]*Sqrt[-Sqrt[-e^(2/3)] + Sqrt[3]*e^(1/3)]*(16*c*d^2 + 7*e*(2*b*d + 13*a*e))*Sqrt[d^(1/3) + e^(1/3)*x]*Sqrt[(d^(1/3)*(Sqrt[3]*Sqrt[-e^(2/3)] + e^(1/3)) - 2*e^(2/3)*x)/(d^(1/3)*(Sqrt[3]*Sqrt[-e^(2/3)] + 3*e^(1/3)))]*Sqrt[(d^(1/3)*(Sqrt[3]*Sqrt[-e^(2/3)] - e^(1/3)) + 2*e^(2/3)*x)/(d^(1/3)*(Sqrt[3]*Sqrt[-e^(2/3)] - 3*e^(1/3)))]*EllipticF[ArcSin[(Sqrt[2]*e^(1/6)*Sqrt[d^(1/3) + e^(1/3)*x])/(3^(1/4)*d^(1/6)*Sqrt[-Sqrt[-e^(2/3)] + Sqrt[3]*e^(1/3)])], -((Sqrt[3]*Sqrt[-e^(2/3)] - 3*e^(1/3))/(Sqrt[3]*Sqrt[-e^(2/3)] + 3*e^(1/3)))])/(135*3^(3/4)*d^(17/6)*e^(5/2)*Sqrt[d + e*x^3])}
{(a + b*x^3 + c*x^6)/(d + e*x^3)^(9/2), x, 7, (2*(c*d^2 - b*d*e + a*e^2)*x)/(21*d*e^2*(d + e*x^3)^(7/2)) - (2*(23*c*d^2 - 2*b*d*e - 19*a*e^2)*x)/(315*d^2*e^2*(d + e*x^3)^(5/2)) + (2*(16*c*d^2 + 26*b*d*e + 247*a*e^2)*x)/(2835*d^3*e^2*(d + e*x^3)^(3/2)) + (2*(16*c*d^2 + 26*b*d*e + 247*a*e^2)*x)/(1215*d^4*e^2*Sqrt[d + e*x^3]) + (Sqrt[2]*Sqrt[-Sqrt[-e^(2/3)] + Sqrt[3]*e^(1/3)]*(16*c*d^2 + 13*e*(2*b*d + 19*a*e))*Sqrt[d^(1/3) + e^(1/3)*x]*Sqrt[(d^(1/3)*(Sqrt[3]*Sqrt[-e^(2/3)] + e^(1/3)) - 2*e^(2/3)*x)/(d^(1/3)*(Sqrt[3]*Sqrt[-e^(2/3)] + 3*e^(1/3)))]*Sqrt[(d^(1/3)*(Sqrt[3]*Sqrt[-e^(2/3)] - e^(1/3)) + 2*e^(2/3)*x)/(d^(1/3)*(Sqrt[3]*Sqrt[-e^(2/3)] - 3*e^(1/3)))]*EllipticF[ArcSin[(Sqrt[2]*e^(1/6)*Sqrt[d^(1/3) + e^(1/3)*x])/(3^(1/4)*d^(1/6)*Sqrt[-Sqrt[-e^(2/3)] + Sqrt[3]*e^(1/3)])], -((Sqrt[3]*Sqrt[-e^(2/3)] - 3*e^(1/3))/(Sqrt[3]*Sqrt[-e^(2/3)] + 3*e^(1/3)))])/(405*3^(3/4)*d^(23/6)*e^(5/2)*Sqrt[d + e*x^3])}
{(a + b*x^3 + c*x^6)/(d + e*x^3)^(11/2), x, 8, (2*(c*d^2 - b*d*e + a*e^2)*x)/(27*d*e^2*(d + e*x^3)^(9/2)) - (2*(29*c*d^2 - 2*b*d*e - 25*a*e^2)*x)/(567*d^2*e^2*(d + e*x^3)^(7/2)) + (2*(16*c*d^2 + 38*b*d*e + 475*a*e^2)*x)/(8505*d^3*e^2*(d + e*x^3)^(5/2)) + (26*(16*c*d^2 + 38*b*d*e + 475*a*e^2)*x)/(76545*d^4*e^2*(d + e*x^3)^(3/2)) + (26*(16*c*d^2 + 38*b*d*e + 475*a*e^2)*x)/(32805*d^5*e^2*Sqrt[d + e*x^3]) + (13*Sqrt[2]*Sqrt[-Sqrt[-e^(2/3)] + Sqrt[3]*e^(1/3)]*(16*c*d^2 + 19*e*(2*b*d + 25*a*e))*Sqrt[d^(1/3) + e^(1/3)*x]*Sqrt[(d^(1/3)*(Sqrt[3]*Sqrt[-e^(2/3)] + e^(1/3)) - 2*e^(2/3)*x)/(d^(1/3)*(Sqrt[3]*Sqrt[-e^(2/3)] + 3*e^(1/3)))]*Sqrt[(d^(1/3)*(Sqrt[3]*Sqrt[-e^(2/3)] - e^(1/3)) + 2*e^(2/3)*x)/(d^(1/3)*(Sqrt[3]*Sqrt[-e^(2/3)] - 3*e^(1/3)))]*EllipticF[ArcSin[(Sqrt[2]*e^(1/6)*Sqrt[d^(1/3) + e^(1/3)*x])/(3^(1/4)*d^(1/6)*Sqrt[-Sqrt[-e^(2/3)] + Sqrt[3]*e^(1/3)])], -((Sqrt[3]*Sqrt[-e^(2/3)] - 3*e^(1/3))/(Sqrt[3]*Sqrt[-e^(2/3)] + 3*e^(1/3)))])/(10935*3^(3/4)*d^(29/6)*e^(5/2)*Sqrt[d + e*x^3])}


(* ::Title:: *)
(*Integration problems of the form x^m (d+e x^4)^n (a+b x^4+c x^8)^p*)


(* ::Section:: *)
(*Integrands of the form x^m (A+B x^4) (a+b x^4+c x^8)^p when a=0*)


(* ::Section:: *)
(*Integrands of the form x^m (A+B x^4) (a+b x^4+c x^8)^p when b=0*)


(* ::Section::Closed:: *)
(*Integrands of the form x^m (A+B x^4) (a+b x^4+c x^8)^p*)


(* ::Subsection::Closed:: *)
(*Integrands of the form x^m (A+B x^4) (a+b x^4+c x^8)^p*)


(* ::Subsubsection:: *)
(*p>0*)


(* ::Subsubsection::Closed:: *)
(*p<0*)


{x^4*(d + e*x^4)/(a + b*x^4 + c*x^8), x, 8, (e*x)/c + ((2*a*c*e + (b - Sqrt[b^2 - 4*a*c])*(c*d - b*e))*ArcTan[(2^(1/4)*c^(1/4)*x)/(-b + Sqrt[b^2 - 4*a*c])^(1/4)])/(2*2^(1/4)*c^(5/4)*Sqrt[b^2 - 4*a*c]*(-b + Sqrt[b^2 - 4*a*c])^(3/4)) - ((-(1/c))^(5/4)*(2*a*c*e + (b + Sqrt[b^2 - 4*a*c])*(c*d - b*e))*ArcTan[(2^(1/4)*x)/((-(1/c))^(1/4)*(b + Sqrt[b^2 - 4*a*c])^(1/4))])/(2*2^(1/4)*Sqrt[b^2 - 4*a*c]*(b + Sqrt[b^2 - 4*a*c])^(3/4)) + ((2*a*c*e + (b - Sqrt[b^2 - 4*a*c])*(c*d - b*e))*ArcTanh[(2^(1/4)*c^(1/4)*x)/(-b + Sqrt[b^2 - 4*a*c])^(1/4)])/(2*2^(1/4)*c^(5/4)*Sqrt[b^2 - 4*a*c]*(-b + Sqrt[b^2 - 4*a*c])^(3/4)) - ((-(1/c))^(5/4)*(2*a*c*e + (b + Sqrt[b^2 - 4*a*c])*(c*d - b*e))*ArcTanh[(2^(1/4)*x)/((-(1/c))^(1/4)*(b + Sqrt[b^2 - 4*a*c])^(1/4))])/(2*2^(1/4)*Sqrt[b^2 - 4*a*c]*(b + Sqrt[b^2 - 4*a*c])^(3/4))}
{x^3*(d + e*x^4)/(a + b*x^4 + c*x^8), x, 4, -(((2*c*d - b*e)*ArcTanh[(b + 2*c*x^4)/Sqrt[b^2 - 4*a*c]])/(4*c*Sqrt[b^2 - 4*a*c])) + (e*Log[a + b*x^4 + c*x^8])/(8*c)}
{x^2*(d + e*x^4)/(a + b*x^4 + c*x^8), x, 7, ((e + (2*c*d - b*e)/Sqrt[b^2 - 4*a*c])*ArcTan[(2^(1/4)*c^(1/4)*x)/(-b + Sqrt[b^2 - 4*a*c])^(1/4)])/(2*2^(3/4)*c^(3/4)*(-b + Sqrt[b^2 - 4*a*c])^(1/4)) - ((-(1/c))^(3/4)*(e - (2*c*d - b*e)/Sqrt[b^2 - 4*a*c])*ArcTan[(2^(1/4)*x)/((-(1/c))^(1/4)*(b + Sqrt[b^2 - 4*a*c])^(1/4))])/(2*2^(3/4)*(b + Sqrt[b^2 - 4*a*c])^(1/4)) - ((e + (2*c*d - b*e)/Sqrt[b^2 - 4*a*c])*ArcTanh[(2^(1/4)*c^(1/4)*x)/(-b + Sqrt[b^2 - 4*a*c])^(1/4)])/(2*2^(3/4)*c^(3/4)*(-b + Sqrt[b^2 - 4*a*c])^(1/4)) + ((-(1/c))^(3/4)*(e - (2*c*d - b*e)/Sqrt[b^2 - 4*a*c])*ArcTanh[(2^(1/4)*x)/((-(1/c))^(1/4)*(b + Sqrt[b^2 - 4*a*c])^(1/4))])/(2*2^(3/4)*(b + Sqrt[b^2 - 4*a*c])^(1/4))}
{x^1*(d + e*x^4)/(a + b*x^4 + c*x^8), x, 4, ((2*c*d - (b - Sqrt[b^2 - 4*a*c])*e)*ArcTan[(Sqrt[2]*Sqrt[c]*x^2)/Sqrt[b - Sqrt[b^2 - 4*a*c]]])/(2*Sqrt[2]*Sqrt[c]*Sqrt[b^2 - 4*a*c]*Sqrt[b - Sqrt[b^2 - 4*a*c]]) - ((2*c*d - (b + Sqrt[b^2 - 4*a*c])*e)*ArcTan[(Sqrt[2]*Sqrt[c]*x^2)/Sqrt[b + Sqrt[b^2 - 4*a*c]]])/(2*Sqrt[2]*Sqrt[c]*Sqrt[b^2 - 4*a*c]*Sqrt[b + Sqrt[b^2 - 4*a*c]])}
{x^0*(d + e*x^4)/(a + b*x^4 + c*x^8), x, 7, -(((2*c*d - (b - Sqrt[b^2 - 4*a*c])*e)*ArcTan[(2^(1/4)*c^(1/4)*x)/(-b + Sqrt[b^2 - 4*a*c])^(1/4)])/(2*2^(1/4)*c^(1/4)*Sqrt[b^2 - 4*a*c]*(-b + Sqrt[b^2 - 4*a*c])^(3/4))) - ((-(1/c))^(1/4)*(2*c*d - (b + Sqrt[b^2 - 4*a*c])*e)*ArcTan[(2^(1/4)*x)/((-(1/c))^(1/4)*(b + Sqrt[b^2 - 4*a*c])^(1/4))])/(2*2^(1/4)*Sqrt[b^2 - 4*a*c]*(b + Sqrt[b^2 - 4*a*c])^(3/4)) - ((2*c*d - (b - Sqrt[b^2 - 4*a*c])*e)*ArcTanh[(2^(1/4)*c^(1/4)*x)/(-b + Sqrt[b^2 - 4*a*c])^(1/4)])/(2*2^(1/4)*c^(1/4)*Sqrt[b^2 - 4*a*c]*(-b + Sqrt[b^2 - 4*a*c])^(3/4)) - ((-(1/c))^(1/4)*(2*c*d - (b + Sqrt[b^2 - 4*a*c])*e)*ArcTanh[(2^(1/4)*x)/((-(1/c))^(1/4)*(b + Sqrt[b^2 - 4*a*c])^(1/4))])/(2*2^(1/4)*Sqrt[b^2 - 4*a*c]*(b + Sqrt[b^2 - 4*a*c])^(3/4))}
{x^(-1)*(d + e*x^4)/(a + b*x^4 + c*x^8), x, 5, ((b*d - 2*a*e)*ArcTanh[(b + 2*c*x^4)/Sqrt[b^2 - 4*a*c]])/(4*a*Sqrt[b^2 - 4*a*c]) + (d*Log[x])/a - (d*Log[a + b*x^4 + c*x^8])/(8*a)}
{x^(-2)*(d + e*x^4)/(a + b*x^4 + c*x^8), x, 8, -(d/(a*x)) - (c^(1/4)*(d + (b*d - 2*a*e)/Sqrt[b^2 - 4*a*c])*ArcTan[(2^(1/4)*c^(1/4)*x)/(-b + Sqrt[b^2 - 4*a*c])^(1/4)])/(2*2^(3/4)*a*(-b + Sqrt[b^2 - 4*a*c])^(1/4)) - ((d - (b*d - 2*a*e)/Sqrt[b^2 - 4*a*c])*ArcTan[(2^(1/4)*x)/((-(1/c))^(1/4)*(b + Sqrt[b^2 - 4*a*c])^(1/4))])/(2*2^(3/4)*a*(-(1/c))^(1/4)*(b + Sqrt[b^2 - 4*a*c])^(1/4)) + (c^(1/4)*(d + (b*d - 2*a*e)/Sqrt[b^2 - 4*a*c])*ArcTanh[(2^(1/4)*c^(1/4)*x)/(-b + Sqrt[b^2 - 4*a*c])^(1/4)])/(2*2^(3/4)*a*(-b + Sqrt[b^2 - 4*a*c])^(1/4)) + ((d - (b*d - 2*a*e)/Sqrt[b^2 - 4*a*c])*ArcTanh[(2^(1/4)*x)/((-(1/c))^(1/4)*(b + Sqrt[b^2 - 4*a*c])^(1/4))])/(2*2^(3/4)*a*(-(1/c))^(1/4)*(b + Sqrt[b^2 - 4*a*c])^(1/4))}
{x^(-3)*(d + e*x^4)/(a + b*x^4 + c*x^8), x, 5, -(d/(2*a*x^2)) - (Sqrt[c]*(b*d + Sqrt[b^2 - 4*a*c]*d - 2*a*e)*ArcTan[(Sqrt[2]*Sqrt[c]*x^2)/Sqrt[b - Sqrt[b^2 - 4*a*c]]])/(2*Sqrt[2]*a*Sqrt[b^2 - 4*a*c]*Sqrt[b - Sqrt[b^2 - 4*a*c]]) + (Sqrt[c]*(b*d - Sqrt[b^2 - 4*a*c]*d - 2*a*e)*ArcTan[(Sqrt[2]*Sqrt[c]*x^2)/Sqrt[b + Sqrt[b^2 - 4*a*c]]])/(2*Sqrt[2]*a*Sqrt[b^2 - 4*a*c]*Sqrt[b + Sqrt[b^2 - 4*a*c]])}
{x^(-4)*(d + e*x^4)/(a + b*x^4 + c*x^8), x, 8, -(d/(3*a*x^3)) + (c^(3/4)*(b*d + Sqrt[b^2 - 4*a*c]*d - 2*a*e)*ArcTan[(2^(1/4)*c^(1/4)*x)/(-b + Sqrt[b^2 - 4*a*c])^(1/4)])/(2*2^(1/4)*a*Sqrt[b^2 - 4*a*c]*(-b + Sqrt[b^2 - 4*a*c])^(3/4)) - ((b*d - Sqrt[b^2 - 4*a*c]*d - 2*a*e)*ArcTan[(2^(1/4)*x)/((-(1/c))^(1/4)*(b + Sqrt[b^2 - 4*a*c])^(1/4))])/(2*2^(1/4)*a*(-(1/c))^(3/4)*Sqrt[b^2 - 4*a*c]*(b + Sqrt[b^2 - 4*a*c])^(3/4)) + (c^(3/4)*(b*d + Sqrt[b^2 - 4*a*c]*d - 2*a*e)*ArcTanh[(2^(1/4)*c^(1/4)*x)/(-b + Sqrt[b^2 - 4*a*c])^(1/4)])/(2*2^(1/4)*a*Sqrt[b^2 - 4*a*c]*(-b + Sqrt[b^2 - 4*a*c])^(3/4)) - ((b*d - Sqrt[b^2 - 4*a*c]*d - 2*a*e)*ArcTanh[(2^(1/4)*x)/((-(1/c))^(1/4)*(b + Sqrt[b^2 - 4*a*c])^(1/4))])/(2*2^(1/4)*a*(-(1/c))^(3/4)*Sqrt[b^2 - 4*a*c]*(b + Sqrt[b^2 - 4*a*c])^(3/4))}


{x^4*(1 - x^4)/(1 - x^4 + x^8), x, 12, -x - ArcTan[2 - Sqrt[3] + Sqrt[2]*x - Sqrt[6]*x]/(2*Sqrt[6]) + ArcTan[2 - Sqrt[3] + Sqrt[2]*(-1 + Sqrt[3])*x]/(2*Sqrt[6]) - ArcTan[2 + Sqrt[3] - 2*Sqrt[2 + Sqrt[3]]*x]/(2*Sqrt[6]) + ArcTan[2 + Sqrt[3] + (Sqrt[2] + Sqrt[6])*x]/(2*Sqrt[6]) + ArcTanh[(Sqrt[2 - Sqrt[3]]*x)/(1 + x^2)]/(2*Sqrt[6]) + ArcTanh[(Sqrt[2 + Sqrt[3]]*x)/(1 + x^2)]/(2*Sqrt[6]), -x - ((1 + Sqrt[3])*ArcTan[(Sqrt[2 - Sqrt[3]] - 2*x)/Sqrt[2 + Sqrt[3]]])/(4*Sqrt[3*(2 + Sqrt[3])]) + ((1 - Sqrt[3])*ArcTan[(Sqrt[2 + Sqrt[3]] - 2*x)/Sqrt[2 - Sqrt[3]]])/(4*Sqrt[3*(2 - Sqrt[3])]) + ((1 + Sqrt[3])*ArcTan[(Sqrt[2 - Sqrt[3]] + 2*x)/Sqrt[2 + Sqrt[3]]])/(4*Sqrt[3*(2 + Sqrt[3])]) - ((1 - Sqrt[3])*ArcTan[(Sqrt[2 + Sqrt[3]] + 2*x)/Sqrt[2 - Sqrt[3]]])/(4*Sqrt[3*(2 - Sqrt[3])]) - ((1 - Sqrt[3])*ArcTanh[(Sqrt[2 - Sqrt[3]]*x)/(1 + x^2)])/(4*Sqrt[3*(2 - Sqrt[3])]) + ((1 + Sqrt[3])*ArcTanh[(Sqrt[2 + Sqrt[3]]*x)/(1 + x^2)])/(4*Sqrt[3*(2 + Sqrt[3])])}
{x^3*(1 - x^4)/(1 - x^4 + x^8), x, 4, -(ArcTan[(1 - 2*x^4)/Sqrt[3]]/(4*Sqrt[3])) - (1/8)*Log[1 - x^4 + x^8]}
{x^2*(1 - x^4)/(1 - x^4 + x^8), x, 13, (1/4)*Sqrt[(1/3)*(2 + Sqrt[3])]*ArcTan[(Sqrt[2 - Sqrt[3]] - 2*x)/Sqrt[2 + Sqrt[3]]] - (1/4)*Sqrt[(1/3)*(2 - Sqrt[3])]*ArcTan[(Sqrt[2 + Sqrt[3]] - 2*x)/Sqrt[2 - Sqrt[3]]] - (1/4)*Sqrt[(1/3)*(2 + Sqrt[3])]*ArcTan[(Sqrt[2 - Sqrt[3]] + 2*x)/Sqrt[2 + Sqrt[3]]] + (1/4)*Sqrt[(1/3)*(2 - Sqrt[3])]*ArcTan[(Sqrt[2 + Sqrt[3]] + 2*x)/Sqrt[2 - Sqrt[3]]] - (1/4)*Sqrt[(1/3)*(2 - Sqrt[3])]*ArcTanh[(Sqrt[2 - Sqrt[3]]*x)/(1 + x^2)] + (1/4)*Sqrt[(1/3)*(2 + Sqrt[3])]*ArcTanh[(Sqrt[2 + Sqrt[3]]*x)/(1 + x^2)]}
{x^1*(1 - x^4)/(1 - x^4 + x^8), x, 2, ArcTanh[(Sqrt[3]*x^2)/(1 + x^4)]/(2*Sqrt[3])}
{x^0*(1 - x^4)/(1 - x^4 + x^8), x, 11, (-(1/4))*Sqrt[(1/3)*(2 + Sqrt[3])]*ArcTan[(Sqrt[2 - Sqrt[3]] - 2*x)/Sqrt[2 + Sqrt[3]]] + (1/4)*Sqrt[(1/3)*(2 - Sqrt[3])]*ArcTan[(Sqrt[2 + Sqrt[3]] - 2*x)/Sqrt[2 - Sqrt[3]]] + (1/4)*Sqrt[(1/3)*(2 + Sqrt[3])]*ArcTan[(Sqrt[2 - Sqrt[3]] + 2*x)/Sqrt[2 + Sqrt[3]]] - (1/4)*Sqrt[(1/3)*(2 - Sqrt[3])]*ArcTan[(Sqrt[2 + Sqrt[3]] + 2*x)/Sqrt[2 - Sqrt[3]]] - (1/4)*Sqrt[(1/3)*(2 - Sqrt[3])]*ArcTanh[(Sqrt[2 - Sqrt[3]]*x)/(1 + x^2)] + (1/4)*Sqrt[(1/3)*(2 + Sqrt[3])]*ArcTanh[(Sqrt[2 + Sqrt[3]]*x)/(1 + x^2)]}
{x^(-1)*(1 - x^4)/(1 - x^4 + x^8), x, 5, ArcTan[(1 - 2*x^4)/Sqrt[3]]/(4*Sqrt[3]) + Log[x] - (1/8)*Log[1 - x^4 + x^8]}
{x^(-2)*(1 - x^4)/(1 - x^4 + x^8), x, 14, -(1/x) + ArcTan[2 - Sqrt[3] + Sqrt[2]*x - Sqrt[6]*x]/(2*Sqrt[6]) - ArcTan[2 - Sqrt[3] + Sqrt[2]*(-1 + Sqrt[3])*x]/(2*Sqrt[6]) + ArcTan[2 + Sqrt[3] - 2*Sqrt[2 + Sqrt[3]]*x]/(2*Sqrt[6]) - ArcTan[2 + Sqrt[3] + (Sqrt[2] + Sqrt[6])*x]/(2*Sqrt[6]) + ArcTanh[(Sqrt[2 - Sqrt[3]]*x)/(1 + x^2)]/(2*Sqrt[6]) + ArcTanh[(Sqrt[2 + Sqrt[3]]*x)/(1 + x^2)]/(2*Sqrt[6]), -(1/x) + ((1 + Sqrt[3])*ArcTan[(Sqrt[2 - Sqrt[3]] - 2*x)/Sqrt[2 + Sqrt[3]]])/(4*Sqrt[3*(2 + Sqrt[3])]) - ((1 - Sqrt[3])*ArcTan[(Sqrt[2 + Sqrt[3]] - 2*x)/Sqrt[2 - Sqrt[3]]])/(4*Sqrt[3*(2 - Sqrt[3])]) - ((1 + Sqrt[3])*ArcTan[(Sqrt[2 - Sqrt[3]] + 2*x)/Sqrt[2 + Sqrt[3]]])/(4*Sqrt[3*(2 + Sqrt[3])]) + ((1 - Sqrt[3])*ArcTan[(Sqrt[2 + Sqrt[3]] + 2*x)/Sqrt[2 - Sqrt[3]]])/(4*Sqrt[3*(2 - Sqrt[3])]) - ((1 - Sqrt[3])*ArcTanh[(Sqrt[2 - Sqrt[3]]*x)/(1 + x^2)])/(4*Sqrt[3*(2 - Sqrt[3])]) + ((1 + Sqrt[3])*ArcTanh[(Sqrt[2 + Sqrt[3]]*x)/(1 + x^2)])/(4*Sqrt[3*(2 + Sqrt[3])])}
{x^(-3)*(1 - x^4)/(1 - x^4 + x^8), x, 7, -(1/(2*x^2)) + (1/4)*ArcTan[Sqrt[3] - 2*x^2] - (1/4)*ArcTan[Sqrt[3] + 2*x^2] + ArcTanh[(Sqrt[3]*x^2)/(1 + x^4)]/(4*Sqrt[3])}
{x^(-4)*(1 - x^4)/(1 - x^4 + x^8), x, 12, -(1/(3*x^3)) - ArcTan[(Sqrt[2 - Sqrt[3]] - 2*x)/Sqrt[2 + Sqrt[3]]]/(4*Sqrt[3*(2 + Sqrt[3])]) + ArcTan[(Sqrt[2 + Sqrt[3]] - 2*x)/Sqrt[2 - Sqrt[3]]]/(4*Sqrt[3*(2 - Sqrt[3])]) + ArcTan[(Sqrt[2 - Sqrt[3]] + 2*x)/Sqrt[2 + Sqrt[3]]]/(4*Sqrt[3*(2 + Sqrt[3])]) - ArcTan[(Sqrt[2 + Sqrt[3]] + 2*x)/Sqrt[2 - Sqrt[3]]]/(4*Sqrt[3*(2 - Sqrt[3])]) - ArcTanh[(Sqrt[2 - Sqrt[3]]*x)/(1 + x^2)]/(4*Sqrt[3*(2 - Sqrt[3])]) + ArcTanh[(Sqrt[2 + Sqrt[3]]*x)/(1 + x^2)]/(4*Sqrt[3*(2 + Sqrt[3])])}


{(1 + x^4)/(1 + x^4 + x^8), x, 11, -(ArcTan[(1 - 2*x)/Sqrt[3]]/(4*Sqrt[3])) - (1/4)*ArcTan[Sqrt[3] - 2*x] + ArcTan[(1 + 2*x)/Sqrt[3]]/(4*Sqrt[3]) + (1/4)*ArcTan[Sqrt[3] + 2*x] + (1/4)*ArcTanh[x/(1 + x^2)] + ArcTanh[(Sqrt[3]*x)/(1 + x^2)]/(4*Sqrt[3])}
{(1 - x^4)/(1 + x^4 + x^8), x, 11, (-(1/4))*Sqrt[3]*ArcTan[(1 - 2*x)/Sqrt[3]] + (1/4)*ArcTan[Sqrt[3] - 2*x] + (1/4)*Sqrt[3]*ArcTan[(1 + 2*x)/Sqrt[3]] - (1/4)*ArcTan[Sqrt[3] + 2*x] - (1/4)*ArcTanh[x/(1 + x^2)] + (1/4)*Sqrt[3]*ArcTanh[(Sqrt[3]*x)/(1 + x^2)]}

{(1 + x^4)/(1 - x^4 + x^8), x, 13, (-(1/4))*Sqrt[2 - Sqrt[3]]*ArcTan[(Sqrt[2 - Sqrt[3]] - 2*x)/Sqrt[2 + Sqrt[3]]] - (1/4)*Sqrt[2 + Sqrt[3]]*ArcTan[(Sqrt[2 + Sqrt[3]] - 2*x)/Sqrt[2 - Sqrt[3]]] + (1/4)*Sqrt[2 - Sqrt[3]]*ArcTan[(Sqrt[2 - Sqrt[3]] + 2*x)/Sqrt[2 + Sqrt[3]]] + (1/4)*Sqrt[2 + Sqrt[3]]*ArcTan[(Sqrt[2 + Sqrt[3]] + 2*x)/Sqrt[2 - Sqrt[3]]] + (1/4)*Sqrt[2 + Sqrt[3]]*ArcTanh[(Sqrt[2 - Sqrt[3]]*x)/(1 + x^2)] + (1/4)*Sqrt[2 - Sqrt[3]]*ArcTanh[(Sqrt[2 + Sqrt[3]]*x)/(1 + x^2)]}

{(1 - x^4)/(1 - 3*x^4 + x^8), x, 7, (1/20)*Sqrt[-10 + 10*Sqrt[5]]*ArcTan[(1/2)*Sqrt[-2 + 2*Sqrt[5]]*x] + (1/20)*Sqrt[10 + 10*Sqrt[5]]*ArcTan[(1/2)*Sqrt[2 + 2*Sqrt[5]]*x] + (1/20)*Sqrt[-10 + 10*Sqrt[5]]*ArcTanh[(1/2)*Sqrt[-2 + 2*Sqrt[5]]*x] + (1/20)*Sqrt[10 + 10*Sqrt[5]]*ArcTanh[(1/2)*Sqrt[2 + 2*Sqrt[5]]*x], ((1 + Sqrt[5])*ArcTan[(2/(3 + Sqrt[5]))^(1/4)*x])/(2*2^(1/4)*Sqrt[5]*(3 + Sqrt[5])^(3/4)) - ((1 - Sqrt[5])*(3 + Sqrt[5])^(1/4)*ArcTan[((1/2)*(3 + Sqrt[5]))^(1/4)*x])/(2*2^(3/4)*Sqrt[5*(3 - Sqrt[5])]) + ((1 + Sqrt[5])*ArcTanh[(2/(3 + Sqrt[5]))^(1/4)*x])/(2*2^(1/4)*Sqrt[5]*(3 + Sqrt[5])^(3/4)) - ((1 - Sqrt[5])*(3 + Sqrt[5])^(1/4)*ArcTanh[((1/2)*(3 + Sqrt[5]))^(1/4)*x])/(2*2^(3/4)*Sqrt[5*(3 - Sqrt[5])])}


{(-1 + Sqrt[3] + 2*x^4)/(1 - x^4 + x^8), x, 5, -(ArcTan[2 + Sqrt[3] - 2*Sqrt[2 + Sqrt[3]]*x]/Sqrt[2]) + ArcTan[2 + Sqrt[3] + 2*Sqrt[2 + Sqrt[3]]*x]/Sqrt[2] + ArcTanh[(Sqrt[2 - Sqrt[3]]*x)/(1 + x^2)]/Sqrt[2], (1/2)*(1 - Sqrt[3])*Sqrt[2 + Sqrt[3]]*ArcTan[(Sqrt[2 + Sqrt[3]] - 2*x)/Sqrt[2 - Sqrt[3]]] - (1/2)*(1 - Sqrt[3])*Sqrt[2 + Sqrt[3]]*ArcTan[(Sqrt[2 + Sqrt[3]] + 2*x)/Sqrt[2 - Sqrt[3]]] + (1/2)*(1 - Sqrt[3])*Sqrt[2 + Sqrt[3]]*ArcTanh[((1 - Sqrt[3])*Sqrt[3*(2 - Sqrt[3])]*x)/(3 - Sqrt[3] - Sqrt[3]*(1 - Sqrt[3])*x^2)]}
{(1 + (1 + Sqrt[3])*x^4)/(1 - x^4 + x^8), x, 5, (-(1/2))*Sqrt[2 + Sqrt[3]]*ArcTan[(Sqrt[2 + Sqrt[3]] - 2*x)/Sqrt[2 - Sqrt[3]]] + (1/2)*Sqrt[2 + Sqrt[3]]*ArcTan[(Sqrt[2 + Sqrt[3]] + 2*x)/Sqrt[2 - Sqrt[3]]] + (1/2)*Sqrt[2 + Sqrt[3]]*ArcTanh[(Sqrt[2 - Sqrt[3]]*x)/(1 + x^2)]}
{(3 - 2*Sqrt[3] + (-3 + Sqrt[3])*x^4)/(1 - x^4 + x^8), x, 5, (1/2)*Sqrt[3*(2 - Sqrt[3])]*ArcTan[2 + Sqrt[3] - 2*Sqrt[2 + Sqrt[3]]*x] - (1/2)*Sqrt[3*(2 - Sqrt[3])]*ArcTan[2 + Sqrt[3] + 2*Sqrt[2 + Sqrt[3]]*x] - (1/2)*Sqrt[3*(2 - Sqrt[3])]*ArcTanh[(Sqrt[2 - Sqrt[3]]*x)/(1 + x^2)], (1/2)*Sqrt[3*(2 - Sqrt[3])]*ArcTan[(Sqrt[2 - Sqrt[3]]*(2 + Sqrt[3]) - 2*x)/Sqrt[2 - Sqrt[3]]] - (1/2)*Sqrt[3*(2 - Sqrt[3])]*ArcTan[(Sqrt[2 - Sqrt[3]]*(2 + Sqrt[3]) + 2*x)/Sqrt[2 - Sqrt[3]]] - (1/2)*Sqrt[3*(2 - Sqrt[3])]*ArcTanh[((2 - Sqrt[3])^(3/2)*x)/(2 - Sqrt[3] + (2 - Sqrt[3])*x^2)]}


(* ::Subsection::Closed:: *)
(*Integrands of the form x^m (A+B x^4) (a+b x^4+c x^8)^(p/2)*)


(* ::Subsubsection:: *)
(*p>0*)


(* ::Subsubsection:: *)
(*p<0*)


(* ::Subsection::Closed:: *)
(*Integrands of the form x^(m/2) (A+B x^4) (a+b x^4+c x^8)^p*)


(* ::Subsubsection:: *)
(*p>0*)


(* ::Subsubsection:: *)
(*p<0*)


(* ::Subsection::Closed:: *)
(*Integrands of the form x^(m/2) (A+B x^4) (a+b x^4+c x^8)^(p/2)*)


(* ::Subsubsection:: *)
(*p>0*)


(* ::Subsubsection:: *)
(*p<0*)


(* ::Title:: *)
(*Integration problems of the form x^m (d+e x^n)^q (a+b x^n+c x^(2n))^p*)


(* ::Section:: *)
(*Integrands of the form x^m (A+B x^n) (a+b x^n+c x^(2n))^p when a=0*)


(* ::Section:: *)
(*Integrands of the form x^m (A+B x^n) (a+b x^n+c x^(2n))^p when b=0*)


(* ::Section::Closed:: *)
(*Integrands of the form x^m (A+B x^n) (a+b x^n+c x^(2n))^p when 2 A c-b B=0*)


(* ::Subsection::Closed:: *)
(*Integrands of the form x^m (b + 2 c x^n) (a + b x^n + c x^(2 n))^p*)


(* ::Subsubsection::Closed:: *)
(*p>0*)


{x^0*(b + 2*c*x^1)*(a + b*x^1 + c*x^2)^13, x, 1, (1/14)*(a + b*x + c*x^2)^14}
{x^1*(b + 2*c*x^2)*(a + b*x^2 + c*x^4)^13, x, 2, (1/28)*(a + b*x^2 + c*x^4)^14}
{x^2*(b + 2*c*x^3)*(a + b*x^3 + c*x^6)^13, x, 2, (1/42)*(a + b*x^3 + c*x^6)^14}
{x^(n - 1)*(b + 2*c*x^n)*(a + b*x^n + c*x^(2*n))^13, x, 2, (a + b*x^n + c*x^(2*n))^14/(14*n)}


{x^0*(b + 2*c*x^1)*(-a + b*x^1 + c*x^2)^13, x, 1, (1/14)*(a - b*x - c*x^2)^14}
{x^1*(b + 2*c*x^2)*(-a + b*x^2 + c*x^4)^13, x, 2, (1/28)*(a - b*x^2 - c*x^4)^14}
{x^2*(b + 2*c*x^3)*(-a + b*x^3 + c*x^6)^13, x, 2, (1/42)*(a - b*x^3 - c*x^6)^14}
{x^(n - 1)*(b + 2*c*x^n)*(-a + b*x^n + c*x^(2*n))^13, x, 2, (a - b*x^n - c*x^(2*n))^14/(14*n)}


{x^0*(b + 2*c*x^1)*(b*x^1 + c*x^2)^13, x, 2, (1/14)*x^14*(b + c*x)^14}
{x^1*(b + 2*c*x^2)*(b*x^2 + c*x^4)^13, x, 3, (1/28)*x^28*(b + c*x^2)^14}
{x^2*(b + 2*c*x^3)*(b*x^3 + c*x^6)^13, x, 3, (1/42)*x^42*(b + c*x^3)^14}
{x^(n - 1)*(b + 2*c*x^n)*(b*x^n + c*x^(2*n))^13, x, 3, (x^(14*n)*(b + c*x^n)^14)/(14*n)}


(* ::Subsubsection::Closed:: *)
(*p<0*)


{x^0*(b + 2*c*x^1)/(a + b*x^1 + c*x^2), x, 1, Log[a + b*x + c*x^2]}
{x^1*(b + 2*c*x^2)/(a + b*x^2 + c*x^4), x, 2, (1/2)*Log[a + b*x^2 + c*x^4]}
{x^2*(b + 2*c*x^3)/(a + b*x^3 + c*x^6), x, 2, (1/3)*Log[a + b*x^3 + c*x^6]}
{x^(n - 1)*(b + 2*c*x^n)/(a + b*x^n + c*x^(2*n)), x, 2, Log[a + b*x^n + c*x^(2*n)]/n}


{x^0*(b + 2*c*x^1)/(a + b*x^1 + c*x^2)^8, x, 1, -(1/(7*(a + b*x + c*x^2)^7))}
{x^1*(b + 2*c*x^2)/(a + b*x^2 + c*x^4)^8, x, 2, -(1/(14*(a + b*x^2 + c*x^4)^7))}
{x^2*(b + 2*c*x^3)/(a + b*x^3 + c*x^6)^8, x, 2, -(1/(21*(a + b*x^3 + c*x^6)^7))}
{x^(n - 1)*(b + 2*c*x^n)/(a + b*x^n + c*x^(2*n))^8, x, 2, -(1/(7*n*(a + b*x^n + c*x^(2*n))^7))}


{x^0*(b + 2*c*x^1)/(-a + b*x^1 + c*x^2), x, 1, Log[a - b*x - c*x^2]}
{x^1*(b + 2*c*x^2)/(-a + b*x^2 + c*x^4), x, 2, (1/2)*Log[a - b*x^2 - c*x^4]}
{x^2*(b + 2*c*x^3)/(-a + b*x^3 + c*x^6), x, 2, (1/3)*Log[a - b*x^3 - c*x^6]}
{x^(n - 1)*(b + 2*c*x^n)/(-a + b*x^n + c*x^(2*n)), x, 2, Log[a - b*x^n - c*x^(2*n)]/n}


{x^0*(b + 2*c*x^1)/(-a + b*x^1 + c*x^2)^8, x, 1, 1/(7*(a - b*x - c*x^2)^7)}
{x^1*(b + 2*c*x^2)/(-a + b*x^2 + c*x^4)^8, x, 2, 1/(14*(a - b*x^2 - c*x^4)^7)}
{x^2*(b + 2*c*x^3)/(-a + b*x^3 + c*x^6)^8, x, 2, 1/(21*(a - b*x^3 - c*x^6)^7)}
{x^(n - 1)*(b + 2*c*x^n)/(-a + b*x^n + c*x^(2*n))^8, x, 2, 1/(7*n*(a - b*x^n - c*x^(2*n))^7)}


{x^0*(b + 2*c*x^1)/(b*x^1 + c*x^2), x, 3, Log[x] + Log[b + c*x]}
{x^1*(b + 2*c*x^2)/(b*x^2 + c*x^4), x, 3, Log[x] + (1/2)*Log[b + c*x^2]}
{x^2*(b + 2*c*x^3)/(b*x^3 + c*x^6), x, 3, Log[x] + (1/3)*Log[b + c*x^3]}
{x^(n - 1)*(b + 2*c*x^n)/(b*x^n + c*x^(2*n)), x, 3, Log[x] + Log[b + c*x^n]/n}


{x^0*(b + 2*c*x^1)/(b*x^1 + c*x^2)^8, x, 2, -(1/(7*x^7*(b + c*x)^7))}
{x^1*(b + 2*c*x^2)/(b*x^2 + c*x^4)^8, x, 2, -(1/(14*x^14*(b + c*x^2)^7))}
{x^2*(b + 2*c*x^3)/(b*x^3 + c*x^6)^8, x, 2, -(1/(21*x^21*(b + c*x^3)^7))}
{x^(n - 1)*(b + 2*c*x^n)/(b*x^n + c*x^(2*n))^8, x, 2, -(1/(x^(7*n)*(7*n*(b + c*x^n)^7)))}


(* ::Subsubsection::Closed:: *)
(*p symbolic*)


{x^0*(b + 2*c*x^1)*(a + b*x^1 + c*x^2)^p, x, 1, (a + b*x + c*x^2)^(1 + p)/(1 + p)}
{x^1*(b + 2*c*x^2)*(a + b*x^2 + c*x^4)^p, x, 2, (a + b*x^2 + c*x^4)^(1 + p)/(2*(1 + p))}
{x^2*(b + 2*c*x^3)*(a + b*x^3 + c*x^6)^p, x, 2, (a + b*x^3 + c*x^6)^(1 + p)/(3*(1 + p))}
{x^(n - 1)*(b + 2*c*x^n)*(a + b*x^n + c*x^(2*n))^p, x, 2, (a + b*x^n + c*x^(2*n))^(1 + p)/(n*(1 + p))}


{x^0*(b + 2*c*x^1)*(-a + b*x^1 + c*x^2)^p, x, 1, (-a + b*x + c*x^2)^(1 + p)/(1 + p)}
{x^1*(b + 2*c*x^2)*(-a + b*x^2 + c*x^4)^p, x, 2, (-a + b*x^2 + c*x^4)^(1 + p)/(2*(1 + p))}
{x^2*(b + 2*c*x^3)*(-a + b*x^3 + c*x^6)^p, x, 2, (-a + b*x^3 + c*x^6)^(1 + p)/(3*(1 + p))}
{x^(n - 1)*(b + 2*c*x^n)*(-a + b*x^n + c*x^(2*n))^p, x, 2, (-a + b*x^n + c*x^(2*n))^(1 + p)/(n*(1 + p))}


{x^0*(b + 2*c*x^1)*(b*x^1 + c*x^2)^p, x, 1, (b*x + c*x^2)^(1 + p)/(1 + p)}
{x^1*(b + 2*c*x^2)*(b*x^2 + c*x^4)^p, x, 1, (b*x^2 + c*x^4)^(1 + p)/(2*(1 + p))}
{x^2*(b + 2*c*x^3)*(b*x^3 + c*x^6)^p, x, 1, (b*x^3 + c*x^6)^(1 + p)/(3*(1 + p))}
{x^(n - 1)*(b + 2*c*x^n)*(b*x^n + c*x^(2*n))^p, x, 1, (b*x^n + c*x^(2*n))^(1 + p)/(n*(1 + p))}


(* ::Section::Closed:: *)
(*Integrands of the form x^m (A+B x^n) (a+b x^n+c x^(2n))^p*)


(* ::Subsection::Closed:: *)
(*Integrands of the form x^m (A+B x^n) (a+b x^n)^p*)


(* ::Subsubsection:: *)
(*p>0*)


(* ::Subsubsection::Closed:: *)
(*p<0*)


{(1 + x^3)/(x - x^4 + x^7), x, 6, -(ArcTan[(1 - 2*x^3)/Sqrt[3]]/Sqrt[3]) + Log[x] - (1/6)*Log[1 - x^3 + x^6]}
