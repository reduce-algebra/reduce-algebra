(* ::Package:: *)

(* ::Title:: *)
(*Problems for integrands of the form (a+b trig(c+d x)^m)^n*)


(* ::Section:: *)
(*Integrands of the form (a+b Sin[c+d x]^m)^n*)


(* ::Subsection::Closed:: *)
(*Integrands of the form (a+b Sin[c+d x]^2)^n*)


(* ::Subsubsection::Closed:: *)
(*n*)


{(a + b*Sin[x]^2)^4, x, 6, (1/128)*(128*a^4 + 256*a^3*b + 288*a^2*b^2 + 160*a*b^3 + 35*b^4)*x - (b*(2*a + b)*(256*a^2 + 256*a*b + 105*b^2)*Tan[x])/(384*(1 + Tan[x]^2)) - (7*b*(2*a + b)*Tan[x]*(a + (a + b)*Tan[x]^2)^2)/(48*(1 + Tan[x]^2)^3) - (b*Tan[x]*(a + (a + b)*Tan[x]^2)^3)/(8*(1 + Tan[x]^2)^4) - (b*Tan[x]*(a*(48*a^2 + 20*a*b + 7*b^2) + (a + b)*(48*a^2 + 76*a*b + 35*b^2)*Tan[x]^2))/(192*(1 + Tan[x]^2)^2)}
{(a + b*Sin[x]^2)^3, x, 5, (1/16)*(2*a + b)*(8*a^2 + 8*a*b + 5*b^2)*x - (b*(52*a^2 + 52*a*b + 15*b^2)*Tan[x])/(48*(1 + Tan[x]^2)) - (b*Tan[x]*(a + (a + b)*Tan[x]^2)^2)/(6*(1 + Tan[x]^2)^3) - (b*Tan[x]*(a*(6*a + b) + (a + b)*(6*a + 5*b)*Tan[x]^2))/(24*(1 + Tan[x]^2)^2)}
{(a + b*Sin[x]^2)^2, x, 4, (1/8)*(8*a^2 + 8*a*b + 3*b^2)*x - (3/8)*b*(2*a + b)*Cos[x]*Sin[x] - (1/4)*b*Cos[x]^3*Sin[x]*(a + (a + b)*Tan[x]^2), (1/8)*(8*a^2 + 8*a*b + 3*b^2)*x - (3*b*(2*a + b)*Tan[x])/(8*(1 + Tan[x]^2)) - (b*Tan[x]*(a + (a + b)*Tan[x]^2))/(4*(1 + Tan[x]^2)^2)}
{(a + b*Sin[x]^2), x, 2, a*x + (b*x)/2 - (1/2)*b*Cos[x]*Sin[x]}
{1/(a + b*Sin[x]^2), x, 2, ArcTan[(Sqrt[a + b]*Tan[x])/Sqrt[a]]/(Sqrt[a]*Sqrt[a + b])}
{1/(a + b*Sin[x]^2)^2, x, 3, ((2*a + b)*ArcTan[(Sqrt[a + b]*Tan[x])/Sqrt[a]])/(2*a^(3/2)*(a + b)^(3/2)) + (b*Tan[x])/(2*a*(a + b)*(a + (a + b)*Tan[x]^2))}
{1/(a + b*Sin[x]^2)^3, x, 4, ((8*a^2 + 8*a*b + 3*b^2)*ArcTan[(Sqrt[a + b]*Tan[x])/Sqrt[a]])/(8*a^(5/2)*(a + b)^(5/2)) + (b*Sec[x]^2*Tan[x])/(4*a*(a + b)*(a + (a + b)*Tan[x]^2)^2) + (3*b*(2*a + b)*Tan[x])/(8*a^2*(a + b)^2*(a + (a + b)*Tan[x]^2)), ((8*a^2 + 8*a*b + 3*b^2)*ArcTan[(Sqrt[a + b]*Tan[x])/Sqrt[a]])/(8*a^(5/2)*(a + b)^(5/2)) + (b*Tan[x]*(1 + Tan[x]^2))/(4*a*(a + b)*(a + (a + b)*Tan[x]^2)^2) + (3*b*(2*a + b)*Tan[x])/(8*a^2*(a + b)^2*(a + (a + b)*Tan[x]^2))}


{(a - a*Sin[x]^2)^4, x, 5, (35*a^4*x)/128 + (35/128)*a^4*Cos[x]*Sin[x] + (35/192)*a^4*Cos[x]^3*Sin[x] + (7/48)*a^4*Cos[x]^5*Sin[x] + (1/8)*a^4*Cos[x]^7*Sin[x]}
{(a - a*Sin[x]^2)^3, x, 4, (5*a^3*x)/16 + (5/16)*a^3*Cos[x]*Sin[x] + (5/24)*a^3*Cos[x]^3*Sin[x] + (1/6)*a^3*Cos[x]^5*Sin[x]}
{(a - a*Sin[x]^2)^2, x, 3, (3*a^2*x)/8 + (3/8)*a^2*Cos[x]*Sin[x] + (1/4)*a^2*Cos[x]^3*Sin[x]}
{(a - a*Sin[x]^2), x, 2, (a*x)/2 + (1/2)*a*Cos[x]*Sin[x]}
{1/(a - a*Sin[x]^2), x, 2, Tan[x]/a}
{1/(a - a*Sin[x]^2)^2, x, 3, Tan[x]/a^2 + Tan[x]^3/(3*a^2)}
{1/(a - a*Sin[x]^2)^3, x, 3, Tan[x]/a^3 + (2*Tan[x]^3)/(3*a^3) + Tan[x]^5/(5*a^3)}
{1/(a - a*Sin[x]^2)^4, x, 3, Tan[x]/a^4 + Tan[x]^3/a^4 + (3*Tan[x]^5)/(5*a^4) + Tan[x]^7/(7*a^4)}
{1/(a - a*Sin[x]^2)^5, x, 3, Tan[x]/a^5 + (4*Tan[x]^3)/(3*a^5) + (6*Tan[x]^5)/(5*a^5) + (4*Tan[x]^7)/(7*a^5) + Tan[x]^9/(9*a^5)}


(* ::Subsubsection::Closed:: *)
(*n/2*)


{(a + b*Sin[x]^2)^(5/2), x, 8, ((23*a^2 + 23*a*b + 8*b^2)*Sqrt[2*a + b - b*Cos[2*x]]*EllipticE[x, -(b/a)])/(15*Sqrt[(2*a + b - b*Cos[2*x])/a]) - (4*a*(a + b)*(2*a + b)*Sqrt[(2*a + b - b*Cos[2*x])/a]*EllipticF[x, -(b/a)])/(15*Sqrt[2*a + b - b*Cos[2*x]]) - (1/15)*Sqrt[2]*b*(2*a + b)*Sqrt[2*a + b - b*Cos[2*x]]*Sin[2*x] - (b*(2*a + b - b*Cos[2*x])^(3/2)*Sin[2*x])/(20*Sqrt[2])}
{(a + b*Sin[x]^2)^(3/2), x, 7, (2*(2*a + b)*Sqrt[2*a + b - b*Cos[2*x]]*EllipticE[x, -(b/a)])/(3*Sqrt[(2*a + b - b*Cos[2*x])/a]) - (a*(a + b)*Sqrt[(2*a + b - b*Cos[2*x])/a]*EllipticF[x, -(b/a)])/(3*Sqrt[2*a + b - b*Cos[2*x]]) - (b*Sqrt[2*a + b - b*Cos[2*x]]*Sin[2*x])/(6*Sqrt[2])}
{(a + b*Sin[x]^2)^(1/2), x, 3, (Sqrt[2*a + b - b*Cos[2*x]]*EllipticE[x, -(b/a)])/Sqrt[(2*a + b - b*Cos[2*x])/a]}
{1/(a + b*Sin[x]^2)^(1/2), x, 3, (Sqrt[(2*a + b - b*Cos[2*x])/a]*EllipticF[x, -(b/a)])/Sqrt[2*a + b - b*Cos[2*x]]}
{1/(a + b*Sin[x]^2)^(3/2), x, 5, (Sqrt[2*a + b - b*Cos[2*x]]*EllipticE[x, -(b/a)])/(a*(a + b)*Sqrt[(2*a + b - b*Cos[2*x])/a]) + (b*Sin[2*x])/(Sqrt[2]*a*(a + b)*Sqrt[2*a + b - b*Cos[2*x]])}
{1/(a + b*Sin[x]^2)^(5/2), x, 8, (2*(2*a + b)*Sqrt[2*a + b - b*Cos[2*x]]*EllipticE[x, -(b/a)])/(3*a^2*(a + b)^2*Sqrt[(2*a + b - b*Cos[2*x])/a]) - (Sqrt[(2*a + b - b*Cos[2*x])/a]*EllipticF[x, -(b/a)])/(3*a*(a + b)*Sqrt[2*a + b - b*Cos[2*x]]) + (Sqrt[2]*b*Sin[2*x])/(3*a*(a + b)*(2*a + b - b*Cos[2*x])^(3/2)) + (Sqrt[2]*b*(2*a + b)*Sin[2*x])/(3*a^2*(a + b)^2*Sqrt[2*a + b - b*Cos[2*x]])}


{(a - a*Sin[x]^2)^(5/2), x, 5, (8/15)*a^2*Sqrt[a*Cos[x]^2]*Tan[x] + (4/15)*a*(a*Cos[x]^2)^(3/2)*Tan[x] + (1/5)*(a*Cos[x]^2)^(5/2)*Tan[x]}
{(a - a*Sin[x]^2)^(3/2), x, 4, (2/3)*a*Sqrt[a*Cos[x]^2]*Tan[x] + (1/3)*(a*Cos[x]^2)^(3/2)*Tan[x]}
{(a - a*Sin[x]^2)^(1/2), x, 3, Sqrt[a*Cos[x]^2]*Tan[x]}
{1/(a - a*Sin[x]^2)^(1/2), x, 3, (ArcTanh[Sin[x]]*Cos[x])/Sqrt[a*Cos[x]^2]}
{1/(a - a*Sin[x]^2)^(3/2), x, 4, (ArcTanh[Sin[x]]*Cos[x])/(2*a*Sqrt[a*Cos[x]^2]) + Tan[x]/(2*a*Sqrt[a*Cos[x]^2])}
{1/(a - a*Sin[x]^2)^(5/2), x, 5, (3*ArcTanh[Sin[x]]*Cos[x])/(8*a^2*Sqrt[a*Cos[x]^2]) + Tan[x]/(4*a*(a*Cos[x]^2)^(3/2)) + (3*Tan[x])/(8*a^2*Sqrt[a*Cos[x]^2])}


(* ::Subsection::Closed:: *)
(*Integrands of the form (a+b Sin[c+d x]^m)^n*)


{1/(a + b*Sin[x]^4), x, 5, ArcTan[Sqrt[1 + Sqrt[b]/Sqrt[-a]]*Tan[x]]/(2*a*Sqrt[1 + Sqrt[b]/Sqrt[-a]]) + ArcTan[Sqrt[1 + (a*Sqrt[b])/(-a)^(3/2)]*Tan[x]]/(2*a*Sqrt[1 + (a*Sqrt[b])/(-a)^(3/2)])}
{1/(a + b*Sin[x]^5), x, 11, -((2*ArcTan[((-1)^(1/5)*b^(1/5) - a^(1/5)*Tan[x/2])/Sqrt[a^(2/5) - (-1)^(2/5)*b^(2/5)]])/(5*a^(4/5)*Sqrt[a^(2/5) - (-1)^(2/5)*b^(2/5)])) - (2*ArcTan[((-1)^(3/5)*b^(1/5) - a^(1/5)*Tan[x/2])/Sqrt[a^(2/5) + (-1)^(1/5)*b^(2/5)]])/(5*a^(4/5)*Sqrt[a^(2/5) + (-1)^(1/5)*b^(2/5)]) + (2*ArcTan[(b^(1/5) + a^(1/5)*Tan[x/2])/Sqrt[a^(2/5) - b^(2/5)]])/(5*a^(4/5)*Sqrt[a^(2/5) - b^(2/5)]) + (2*ArcTan[((-1)^(2/5)*b^(1/5) + a^(1/5)*Tan[x/2])/Sqrt[a^(2/5) - (-1)^(4/5)*b^(2/5)]])/(5*a^(4/5)*Sqrt[a^(2/5) - (-1)^(4/5)*b^(2/5)]) + (2*ArcTan[((-1)^(4/5)*b^(1/5) + a^(1/5)*Tan[x/2])/Sqrt[a^(2/5) + (-1)^(3/5)*b^(2/5)]])/(5*a^(4/5)*Sqrt[a^(2/5) + (-1)^(3/5)*b^(2/5)])}
{1/(a + b*Sin[x]^6), x, 7, ArcTan[Sqrt[1 + b^(1/3)/a^(1/3)]*Tan[x]]/(3*a*Sqrt[1 + b^(1/3)/a^(1/3)]) + ArcTan[Sqrt[1 - ((-1)^(1/3)*b^(1/3))/a^(1/3)]*Tan[x]]/(3*a*Sqrt[1 - ((-1)^(1/3)*b^(1/3))/a^(1/3)]) + ArcTan[Sqrt[1 + ((-1)^(2/3)*b^(1/3))/a^(1/3)]*Tan[x]]/(3*a*Sqrt[1 + ((-1)^(2/3)*b^(1/3))/a^(1/3)])}
{1/(a + b*Sin[x]^8), x, 9, ArcTan[Sqrt[1 - (I*b^(1/4))/(-a)^(1/4)]*Tan[x]]/(4*a*Sqrt[1 - (I*b^(1/4))/(-a)^(1/4)]) + ArcTan[Sqrt[1 + (I*b^(1/4))/(-a)^(1/4)]*Tan[x]]/(4*a*Sqrt[1 + (I*b^(1/4))/(-a)^(1/4)]) + ArcTan[Sqrt[1 + b^(1/4)/(-a)^(1/4)]*Tan[x]]/(4*a*Sqrt[1 + b^(1/4)/(-a)^(1/4)]) + ArcTan[Sqrt[1 + (a*b^(1/4))/(-a)^(5/4)]*Tan[x]]/(4*a*Sqrt[1 + (a*b^(1/4))/(-a)^(5/4)])}

{1/(a - b*Sin[x]^4), x, 5, ArcTan[Sqrt[1 - Sqrt[b]/Sqrt[a]]*Tan[x]]/(2*a*Sqrt[1 - Sqrt[b]/Sqrt[a]]) + ArcTan[Sqrt[1 + Sqrt[b]/Sqrt[a]]*Tan[x]]/(2*a*Sqrt[1 + Sqrt[b]/Sqrt[a]])}
{1/(a - b*Sin[x]^5), x, 11, -((2*ArcTan[(b^(1/5) - a^(1/5)*Tan[x/2])/Sqrt[a^(2/5) - b^(2/5)]])/(5*a^(4/5)*Sqrt[a^(2/5) - b^(2/5)])) - (2*ArcTan[((-1)^(2/5)*b^(1/5) - a^(1/5)*Tan[x/2])/Sqrt[a^(2/5) - (-1)^(4/5)*b^(2/5)]])/(5*a^(4/5)*Sqrt[a^(2/5) - (-1)^(4/5)*b^(2/5)]) - (2*ArcTan[((-1)^(4/5)*b^(1/5) - a^(1/5)*Tan[x/2])/Sqrt[a^(2/5) + (-1)^(3/5)*b^(2/5)]])/(5*a^(4/5)*Sqrt[a^(2/5) + (-1)^(3/5)*b^(2/5)]) + (2*ArcTan[((-1)^(1/5)*b^(1/5) + a^(1/5)*Tan[x/2])/Sqrt[a^(2/5) - (-1)^(2/5)*b^(2/5)]])/(5*a^(4/5)*Sqrt[a^(2/5) - (-1)^(2/5)*b^(2/5)]) + (2*ArcTan[((-1)^(3/5)*b^(1/5) + a^(1/5)*Tan[x/2])/Sqrt[a^(2/5) + (-1)^(1/5)*b^(2/5)]])/(5*a^(4/5)*Sqrt[a^(2/5) + (-1)^(1/5)*b^(2/5)])}
{1/(a - b*Sin[x]^6), x, 7, ArcTan[Sqrt[1 - b^(1/3)/a^(1/3)]*Tan[x]]/(3*a*Sqrt[1 - b^(1/3)/a^(1/3)]) + ArcTan[Sqrt[1 + ((-1)^(1/3)*b^(1/3))/a^(1/3)]*Tan[x]]/(3*a*Sqrt[1 + ((-1)^(1/3)*b^(1/3))/a^(1/3)]) + ArcTan[Sqrt[1 - ((-1)^(2/3)*b^(1/3))/a^(1/3)]*Tan[x]]/(3*a*Sqrt[1 - ((-1)^(2/3)*b^(1/3))/a^(1/3)])}
{1/(a - b*Sin[x]^8), x, 9, ArcTan[Sqrt[1 - b^(1/4)/a^(1/4)]*Tan[x]]/(4*a*Sqrt[1 - b^(1/4)/a^(1/4)]) + ArcTan[Sqrt[1 - (I*b^(1/4))/a^(1/4)]*Tan[x]]/(4*a*Sqrt[1 - (I*b^(1/4))/a^(1/4)]) + ArcTan[Sqrt[1 + (I*b^(1/4))/a^(1/4)]*Tan[x]]/(4*a*Sqrt[1 + (I*b^(1/4))/a^(1/4)]) + ArcTan[Sqrt[1 + b^(1/4)/a^(1/4)]*Tan[x]]/(4*a*Sqrt[1 + b^(1/4)/a^(1/4)])}


{1/(1 + Sin[x]^4), x, 5, (1/2)*Sqrt[1/2 - I/2]*ArcTan[Tan[x]/Sqrt[1/2 - I/2]] + (1/2)*Sqrt[1/2 + I/2]*ArcTan[Tan[x]/Sqrt[1/2 + I/2]]}
{1/(1 + Sin[x]^5), x, 6, -((2*ArcTan[((-1)^(1/5) - Tan[x/2])/Sqrt[1 - (-1)^(2/5)]])/(5*Sqrt[1 - (-1)^(2/5)])) - (2*ArcTan[((-1)^(3/5) - Tan[x/2])/Sqrt[1 + (-1)^(1/5)]])/(5*Sqrt[1 + (-1)^(1/5)]) + (2*ArcTan[((-1)^(2/5) + Tan[x/2])/Sqrt[1 - (-1)^(4/5)]])/(5*Sqrt[1 - (-1)^(4/5)]) + (2*ArcTan[((-1)^(4/5) + Tan[x/2])/Sqrt[1 + (-1)^(3/5)]])/(5*Sqrt[1 + (-1)^(3/5)]) - Cos[x]/(5*(1 + Sin[x]))}
{1/(1 + Sin[x]^6), x, 7, ArcTan[Sqrt[2]*Tan[x]]/(3*Sqrt[2]) + ArcTan[Sqrt[1 - (-1)^(1/3)]*Tan[x]]/(3*Sqrt[1 - (-1)^(1/3)]) + ArcTan[Sqrt[1 + (-1)^(2/3)]*Tan[x]]/(3*Sqrt[1 + (-1)^(2/3)])}
{1/(1 + Sin[x]^8), x, 9, (1/8)*(Sqrt[1 + Sqrt[4 - 2*Sqrt[2]]] + Sqrt[2 + 2*2^(1/4) + 2*Sqrt[1 + Sqrt[2]] + 2*Sqrt[2 + Sqrt[2]]] + Sqrt[1 + Sqrt[4 + 2*Sqrt[2]]])*(x - ArcTan[Tan[x]]) + ArcTan[Sqrt[1 - (-1)^(1/4)]*Tan[x]]/(4*Sqrt[1 - (-1)^(1/4)]) + ArcTan[Sqrt[1 + (-1)^(1/4)]*Tan[x]]/(4*Sqrt[1 + (-1)^(1/4)]) + ArcTan[Sqrt[1 - (-1)^(3/4)]*Tan[x]]/(4*Sqrt[1 - (-1)^(3/4)]) + ArcTan[Sqrt[1 + (-1)^(3/4)]*Tan[x]]/(4*Sqrt[1 + (-1)^(3/4)]), ArcTan[Sqrt[1 - (-1)^(1/4)]*Tan[x]]/(4*Sqrt[1 - (-1)^(1/4)]) + ArcTan[Sqrt[1 + (-1)^(1/4)]*Tan[x]]/(4*Sqrt[1 + (-1)^(1/4)]) + ArcTan[Sqrt[1 - (-1)^(3/4)]*Tan[x]]/(4*Sqrt[1 - (-1)^(3/4)]) + ArcTan[Sqrt[1 + (-1)^(3/4)]*Tan[x]]/(4*Sqrt[1 + (-1)^(3/4)])}

{1/(1 - Sin[x]^4), x, 5, ArcTan[Sqrt[2]*Tan[x]]/(2*Sqrt[2]) + Tan[x]/2}
{1/(1 - Sin[x]^5), x, 6, -((2*ArcTan[((-1)^(2/5) - Tan[x/2])/Sqrt[1 - (-1)^(4/5)]])/(5*Sqrt[1 - (-1)^(4/5)])) - (2*ArcTan[((-1)^(4/5) - Tan[x/2])/Sqrt[1 + (-1)^(3/5)]])/(5*Sqrt[1 + (-1)^(3/5)]) + (2*ArcTan[((-1)^(1/5) + Tan[x/2])/Sqrt[1 - (-1)^(2/5)]])/(5*Sqrt[1 - (-1)^(2/5)]) + (2*ArcTan[((-1)^(3/5) + Tan[x/2])/Sqrt[1 + (-1)^(1/5)]])/(5*Sqrt[1 + (-1)^(1/5)]) + Cos[x]/(5*(1 - Sin[x]))}
{1/(1 - Sin[x]^6), x, 7, ArcTan[Sqrt[1 + (-1)^(1/3)]*Tan[x]]/(3*Sqrt[1 + (-1)^(1/3)]) + ArcTan[Sqrt[1 - (-1)^(2/3)]*Tan[x]]/(3*Sqrt[1 - (-1)^(2/3)]) + Tan[x]/3}
{1/(1 - Sin[x]^8), x, 9, (1/4)*Sqrt[1/2 - I/2]*ArcTan[Tan[x]/Sqrt[1/2 - I/2]] + (1/4)*Sqrt[1/2 + I/2]*ArcTan[Tan[x]/Sqrt[1/2 + I/2]] + ArcTan[Sqrt[2]*Tan[x]]/(4*Sqrt[2]) + Tan[x]/4}


(* ::Section:: *)
(*Integrands of the form (a+b Cos[c+d x]^m)^n*)


(* ::Subsection::Closed:: *)
(*Integrands of the form (a+b Cos[c+d x]^2)^n*)


(* ::Subsubsection::Closed:: *)
(*n*)


{1/(a + b*Cos[x]^2), x, 2, ArcTan[(Sqrt[a]*Tan[x])/Sqrt[a + b]]/(Sqrt[a]*Sqrt[a + b])}
{1/(a + b*Cos[x]^2)^2, x, 3, ((2*a + b)*ArcTan[(Sqrt[a]*Tan[x])/Sqrt[a + b]])/(2*a^(3/2)*(a + b)^(3/2)) - (b*Tan[x])/(2*a*(a + b)*(a + b + a*Tan[x]^2))}
{1/(a + b*Cos[x]^2)^3, x, 4, ((8*a^2 + 8*a*b + 3*b^2)*ArcTan[(Sqrt[a]*Tan[x])/Sqrt[a + b]])/(8*a^(5/2)*(a + b)^(5/2)) - (b*Tan[x]*(1 + Tan[x]^2))/(4*a*(a + b)*(a + b + a*Tan[x]^2)^2) - (3*b*(2*a + b)*Tan[x])/(8*a^2*(a + b)^2*(a + b + a*Tan[x]^2))}

{1/(1 + Cos[x]^2), x, 2, ArcTan[Tan[x]/Sqrt[2]]/Sqrt[2]}
{1/(1 + Cos[x]^2)^2, x, 3, (3*ArcTan[Tan[x]/Sqrt[2]])/(4*Sqrt[2]) - Tan[x]/(4*(2 + Tan[x]^2))}
{1/(1 + Cos[x]^2)^3, x, 4, (19*ArcTan[Tan[x]/Sqrt[2]])/(32*Sqrt[2]) - (Tan[x]*(1 + Tan[x]^2))/(8*(2 + Tan[x]^2)^2) - (9*Tan[x])/(32*(2 + Tan[x]^2))}

{1/(1 - Cos[x]^2), x, 2, -Cot[x]}
{1/(1 - Cos[x]^2)^2, x, 3, -Cot[x] - Cot[x]^3/3}
{1/(1 - Cos[x]^2)^3, x, 3, -Cot[x] - (2*Cot[x]^3)/3 - Cot[x]^5/5}


(* ::Subsubsection::Closed:: *)
(*n/2*)


{Sqrt[1 + Cos[x]^2], x, 2, Sqrt[2]*EllipticE[x, 1/2]}
{Sqrt[1 - Cos[x]^2], x, 3, -(Cot[x]*Sqrt[Sin[x]^2])}
{Sqrt[-1 + Cos[x]^2], x, 3, (-Cot[x])*Sqrt[-Sin[x]^2]}
{Sqrt[-1 - Cos[x]^2], x, 3, (Sqrt[2]*Sqrt[-3 - Cos[2*x]]*EllipticE[x, 1/2])/Sqrt[3 + Cos[2*x]]}
{Sqrt[a + b*Cos[x]^2], x, 3, (Sqrt[2*a + b + b*Cos[2*x]]*EllipticE[x, b/(a + b)])/Sqrt[(2*a + b + b*Cos[2*x])/(a + b)]}

{1/Sqrt[1 + Cos[x]^2], x, 2, EllipticF[x, 1/2]/Sqrt[2]}
{1/Sqrt[1 - Cos[x]^2], x, 3, -((ArcTanh[Cos[x]]*Sin[x])/Sqrt[Sin[x]^2])}
{1/Sqrt[-1 + Cos[x]^2], x, 3, -((ArcTanh[Cos[x]]*Sin[x])/Sqrt[-Sin[x]^2])}
{1/Sqrt[-1 - Cos[x]^2], x, 3, (Sqrt[3 + Cos[2*x]]*EllipticF[x, 1/2])/(Sqrt[2]*Sqrt[-3 - Cos[2*x]])}
{1/Sqrt[a + b*Cos[x]^2], x, 3, (Sqrt[(2*a + b + b*Cos[2*x])/(a + b)]*EllipticF[x, b/(a + b)])/Sqrt[2*a + b + b*Cos[2*x]]}

{(1 - Cos[x]^2)^(3/2), x, 4, (-(2/3))*Cot[x]*Sqrt[Sin[x]^2] - (1/3)*Cot[x]*(Sin[x]^2)^(3/2)}
{(-1 + Cos[x]^2)^(3/2), x, 4, (2/3)*Cot[x]*Sqrt[-Sin[x]^2] - (1/3)*Cot[x]*(-Sin[x]^2)^(3/2)}
(* {(1 + Cos[x]^2)^(3/2), x, 0, 0} *)
(* {(-1 - Cos[x]^2)^(3/2), x, 0, 0} *)
(* {(a + b*Cos[x]^2)^(3/2), x, 0, 0} *)


(* ::Subsection::Closed:: *)
(*Integrands of the form (a+b Cos[c+d x]^m)^n*)


{1/(a + b*Cos[x]^4), x, 5, ArcTan[Tan[x]/Sqrt[1 + Sqrt[b]/Sqrt[-a]]]/(2*a*Sqrt[1 + Sqrt[b]/Sqrt[-a]]) + ArcTan[Tan[x]/Sqrt[1 + (a*Sqrt[b])/(-a)^(3/2)]]/(2*a*Sqrt[1 + (a*Sqrt[b])/(-a)^(3/2)])}
{1/(a + b*Cos[x]^5), x, 11, (2*ArcTan[(Sqrt[a^(2/5) - b^(2/5)]*Tan[x/2])/(a^(1/5) + b^(1/5))])/(5*a^(4/5)*Sqrt[a^(2/5) - b^(2/5)]) + (2*ArcTan[(Sqrt[a^(2/5) + (-1)^(1/5)*b^(2/5)]*Tan[x/2])/(a^(1/5) - (-1)^(3/5)*b^(1/5))])/(5*a^(4/5)*Sqrt[a^(2/5) + (-1)^(1/5)*b^(2/5)]) + (2*ArcTan[(Sqrt[a^(2/5) - (-1)^(2/5)*b^(2/5)]*Tan[x/2])/(a^(1/5) - (-1)^(1/5)*b^(1/5))])/(5*a^(4/5)*Sqrt[a^(2/5) - (-1)^(2/5)*b^(2/5)]) + (2*ArcTan[(Sqrt[a^(2/5) + (-1)^(3/5)*b^(2/5)]*Tan[x/2])/(a^(1/5) + (-1)^(4/5)*b^(1/5))])/(5*a^(4/5)*Sqrt[a^(2/5) + (-1)^(3/5)*b^(2/5)]) + (2*ArcTan[(Sqrt[a^(2/5) - (-1)^(4/5)*b^(2/5)]*Tan[x/2])/(a^(1/5) + (-1)^(2/5)*b^(1/5))])/(5*a^(4/5)*Sqrt[a^(2/5) - (-1)^(4/5)*b^(2/5)])}
{1/(a + b*Cos[x]^6), x, 7, ArcTan[Tan[x]/Sqrt[1 + b^(1/3)/a^(1/3)]]/(3*a*Sqrt[1 + b^(1/3)/a^(1/3)]) + ArcTan[Tan[x]/Sqrt[1 - ((-1)^(1/3)*b^(1/3))/a^(1/3)]]/(3*a*Sqrt[1 - ((-1)^(1/3)*b^(1/3))/a^(1/3)]) + ArcTan[Tan[x]/Sqrt[1 + ((-1)^(2/3)*b^(1/3))/a^(1/3)]]/(3*a*Sqrt[1 + ((-1)^(2/3)*b^(1/3))/a^(1/3)])}
{1/(a + b*Cos[x]^8), x, 9, ArcTan[Tan[x]/Sqrt[1 - (I*b^(1/4))/(-a)^(1/4)]]/(4*a*Sqrt[1 - (I*b^(1/4))/(-a)^(1/4)]) + ArcTan[Tan[x]/Sqrt[1 + (I*b^(1/4))/(-a)^(1/4)]]/(4*a*Sqrt[1 + (I*b^(1/4))/(-a)^(1/4)]) + ArcTan[Tan[x]/Sqrt[1 + b^(1/4)/(-a)^(1/4)]]/(4*a*Sqrt[1 + b^(1/4)/(-a)^(1/4)]) + ArcTan[Tan[x]/Sqrt[1 + (a*b^(1/4))/(-a)^(5/4)]]/(4*a*Sqrt[1 + (a*b^(1/4))/(-a)^(5/4)])}

{1/(a - b*Cos[x]^4), x, 5, ArcTan[Tan[x]/Sqrt[1 - Sqrt[b]/Sqrt[a]]]/(2*a*Sqrt[1 - Sqrt[b]/Sqrt[a]]) + ArcTan[Tan[x]/Sqrt[1 + Sqrt[b]/Sqrt[a]]]/(2*a*Sqrt[1 + Sqrt[b]/Sqrt[a]])}
{1/(a - b*Cos[x]^5), x, 11, (2*ArcTan[(Sqrt[a^(2/5) - b^(2/5)]*Tan[x/2])/(a^(1/5) - b^(1/5))])/(5*a^(4/5)*Sqrt[a^(2/5) - b^(2/5)]) + (2*ArcTan[(Sqrt[a^(2/5) + (-1)^(1/5)*b^(2/5)]*Tan[x/2])/(a^(1/5) + (-1)^(3/5)*b^(1/5))])/(5*a^(4/5)*Sqrt[a^(2/5) + (-1)^(1/5)*b^(2/5)]) + (2*ArcTan[(Sqrt[a^(2/5) - (-1)^(2/5)*b^(2/5)]*Tan[x/2])/(a^(1/5) + (-1)^(1/5)*b^(1/5))])/(5*a^(4/5)*Sqrt[a^(2/5) - (-1)^(2/5)*b^(2/5)]) + (2*ArcTan[(Sqrt[a^(2/5) + (-1)^(3/5)*b^(2/5)]*Tan[x/2])/(a^(1/5) - (-1)^(4/5)*b^(1/5))])/(5*a^(4/5)*Sqrt[a^(2/5) + (-1)^(3/5)*b^(2/5)]) + (2*ArcTan[(Sqrt[a^(2/5) - (-1)^(4/5)*b^(2/5)]*Tan[x/2])/(a^(1/5) - (-1)^(2/5)*b^(1/5))])/(5*a^(4/5)*Sqrt[a^(2/5) - (-1)^(4/5)*b^(2/5)])}
{1/(a - b*Cos[x]^6), x, 7, ArcTan[Tan[x]/Sqrt[1 - b^(1/3)/a^(1/3)]]/(3*a*Sqrt[1 - b^(1/3)/a^(1/3)]) + ArcTan[Tan[x]/Sqrt[1 + ((-1)^(1/3)*b^(1/3))/a^(1/3)]]/(3*a*Sqrt[1 + ((-1)^(1/3)*b^(1/3))/a^(1/3)]) + ArcTan[Tan[x]/Sqrt[1 - ((-1)^(2/3)*b^(1/3))/a^(1/3)]]/(3*a*Sqrt[1 - ((-1)^(2/3)*b^(1/3))/a^(1/3)])}
{1/(a - b*Cos[x]^8), x, 9, ArcTan[Tan[x]/Sqrt[1 - b^(1/4)/a^(1/4)]]/(4*a*Sqrt[1 - b^(1/4)/a^(1/4)]) + ArcTan[Tan[x]/Sqrt[1 - (I*b^(1/4))/a^(1/4)]]/(4*a*Sqrt[1 - (I*b^(1/4))/a^(1/4)]) + ArcTan[Tan[x]/Sqrt[1 + (I*b^(1/4))/a^(1/4)]]/(4*a*Sqrt[1 + (I*b^(1/4))/a^(1/4)]) + ArcTan[Tan[x]/Sqrt[1 + b^(1/4)/a^(1/4)]]/(4*a*Sqrt[1 + b^(1/4)/a^(1/4)])}


{1/(1 + Cos[x]^4), x, 5, ArcTan[Tan[x]/Sqrt[1 - I]]/(2*Sqrt[1 - I]) + ArcTan[Tan[x]/Sqrt[1 + I]]/(2*Sqrt[1 + I])}
{1/(1 + Cos[x]^5), x, 6, (2*ArcTan[(Sqrt[1 - (-1)^(2/5)]*Tan[x/2])/(1 - (-1)^(1/5))])/(5*Sqrt[1 - (-1)^(2/5)]) + (2*ArcTan[(Sqrt[1 + (-1)^(1/5)]*Tan[x/2])/(1 - (-1)^(3/5))])/(5*Sqrt[1 + (-1)^(1/5)]) + (2*ArcTan[(Sqrt[1 - (-1)^(4/5)]*Tan[x/2])/(1 + (-1)^(2/5))])/(5*Sqrt[1 - (-1)^(4/5)]) + (2*ArcTan[(Sqrt[1 + (-1)^(3/5)]*Tan[x/2])/(1 + (-1)^(4/5))])/(5*Sqrt[1 + (-1)^(3/5)]) + Sin[x]/(5*(1 + Cos[x]))}
{1/(1 + Cos[x]^6), x, 7, ArcTan[Tan[x]/Sqrt[2]]/(3*Sqrt[2]) + ArcTan[Tan[x]/Sqrt[1 - (-1)^(1/3)]]/(3*Sqrt[1 - (-1)^(1/3)]) + ArcTan[Tan[x]/Sqrt[1 + (-1)^(2/3)]]/(3*Sqrt[1 + (-1)^(2/3)])}
{1/(1 + Cos[x]^8), x, 9, ArcTan[Tan[x]/Sqrt[1 - (-1)^(1/4)]]/(4*Sqrt[1 - (-1)^(1/4)]) + ArcTan[Tan[x]/Sqrt[1 + (-1)^(1/4)]]/(4*Sqrt[1 + (-1)^(1/4)]) + ArcTan[Tan[x]/Sqrt[1 - (-1)^(3/4)]]/(4*Sqrt[1 - (-1)^(3/4)]) + ArcTan[Tan[x]/Sqrt[1 + (-1)^(3/4)]]/(4*Sqrt[1 + (-1)^(3/4)])}

{1/(1 - Cos[x]^4), x, 5, ArcTan[Tan[x]/Sqrt[2]]/(2*Sqrt[2]) - Cot[x]/2}
{1/(1 - Cos[x]^5), x, 6, (2*ArcTan[(Sqrt[1 - (-1)^(2/5)]*Tan[x/2])/(1 + (-1)^(1/5))])/(5*Sqrt[1 - (-1)^(2/5)]) + (2*ArcTan[(Sqrt[1 + (-1)^(1/5)]*Tan[x/2])/(1 + (-1)^(3/5))])/(5*Sqrt[1 + (-1)^(1/5)]) + (2*ArcTan[(Sqrt[1 + (-1)^(3/5)]*Tan[x/2])/(1 - (-1)^(4/5))])/(5*Sqrt[1 + (-1)^(3/5)]) + (2*ArcTan[(Sqrt[1 - (-1)^(4/5)]*Tan[x/2])/(1 - (-1)^(2/5))])/(5*Sqrt[1 - (-1)^(4/5)]) - Sin[x]/(5*(1 - Cos[x]))}
{1/(1 - Cos[x]^6), x, 7, ArcTan[Tan[x]/Sqrt[1 + (-1)^(1/3)]]/(3*Sqrt[1 + (-1)^(1/3)]) + ArcTan[Tan[x]/Sqrt[1 - (-1)^(2/3)]]/(3*Sqrt[1 - (-1)^(2/3)]) - Cot[x]/3}
{1/(1 - Cos[x]^8), x, 9, ArcTan[Tan[x]/Sqrt[1 - I]]/(4*Sqrt[1 - I]) + ArcTan[Tan[x]/Sqrt[1 + I]]/(4*Sqrt[1 + I]) + ArcTan[Tan[x]/Sqrt[2]]/(4*Sqrt[2]) - Cot[x]/4}


(* ::Section:: *)
(*Integrands of the form (a+b Tan[c+d x]^m)^n*)


(* ::Subsection::Closed:: *)
(*Integrands of the form (a+b Tan[c+d x]^2)^n*)


(* ::Subsubsection::Closed:: *)
(*n*)


{(a + b*Tan[c + d*x]^2)^4, x, 4, ((a - b)^4*d*x)/d + ((2*a - b)*b*(2*a^2 - 2*a*b + b^2)*Tan[c + d*x])/d + (b^2*(6*a^2 - 4*a*b + b^2)*Tan[c + d*x]^3)/(3*d) + ((4*a - b)*b^3*Tan[c + d*x]^5)/(5*d) + (b^4*Tan[c + d*x]^7)/(7*d)}
{(a + b*Tan[c + d*x]^2)^3, x, 4, ((a - b)^3*d*x)/d + (b*(3*a^2 - 3*a*b + b^2)*Tan[c + d*x])/d + ((3*a - b)*b^2*Tan[c + d*x]^3)/(3*d) + (b^3*Tan[c + d*x]^5)/(5*d)}
{(a + b*Tan[c + d*x]^2)^2, x, 4, ((a - b)^2*d*x)/d + ((2*a - b)*b*Tan[c + d*x])/d + (b^2*Tan[c + d*x]^3)/(3*d)}
{(a + b*Tan[c + d*x]^2)^1, x, 3, a*x - b*x + (b*Tan[c + d*x])/d}
{1/(a + b*Tan[c + d*x]^2)^1, x, 3, (d*x)/((a - b)*d) - (Sqrt[b]*ArcTan[(Sqrt[b]*Tan[c + d*x])/Sqrt[a]])/(Sqrt[a]*(a - b)*d)}
{1/(a + b*Tan[c + d*x]^2)^2, x, 5, (d*x)/((a - b)^2*d) - ((3*a - b)*Sqrt[b]*ArcTan[(Sqrt[b]*Tan[c + d*x])/Sqrt[a]])/(2*a^(3/2)*(a - b)^2*d) - (b*Tan[c + d*x])/(2*a*(a - b)*d*(a + b*Tan[c + d*x]^2))}
{1/(a + b*Tan[c + d*x]^2)^3, x, 6, (d*x)/((a - b)^3*d) - (Sqrt[b]*(15*a^2 - 10*a*b + 3*b^2)*ArcTan[(Sqrt[b]*Tan[c + d*x])/Sqrt[a]])/(8*a^(5/2)*(a - b)^3*d) - (b*Tan[c + d*x])/(4*a*(a - b)*d*(a + b*Tan[c + d*x]^2)^2) - ((7*a - 3*b)*b*Tan[c + d*x])/(8*a^2*(a - b)^2*d*(a + b*Tan[c + d*x]^2))}


{(a + a*Tan[c + d*x]^2)^4, x, 4, (a^4*Tan[c + d*x])/d + (a^4*Tan[c + d*x]^3)/d + (3*a^4*Tan[c + d*x]^5)/(5*d) + (a^4*Tan[c + d*x]^7)/(7*d)}
{(a + a*Tan[c + d*x]^2)^3, x, 4, (a^3*Tan[c + d*x])/d + (2*a^3*Tan[c + d*x]^3)/(3*d) + (a^3*Tan[c + d*x]^5)/(5*d)}
{(a + a*Tan[c + d*x]^2)^2, x, 3, (a^2*Tan[c + d*x])/d + (a^2*Tan[c + d*x]^3)/(3*d)}
{(a + a*Tan[c + d*x]^2)^1, x, 3, (a*Tan[c + d*x])/d}
{1/(a + a*Tan[c + d*x]^2)^1, x, 2, x/(2*a) + (Cos[c + d*x]*Sin[c + d*x])/(2*a*d)}
{1/(a + a*Tan[c + d*x]^2)^2, x, 5, (3*x)/(8*a^2) + Tan[c + d*x]/(4*a^2*d*(1 + Tan[c + d*x]^2)^2) + (3*Tan[c + d*x])/(8*a^2*d*(1 + Tan[c + d*x]^2))}
{1/(a + a*Tan[c + d*x]^2)^3, x, 6, (5*x)/(16*a^3) + Tan[c + d*x]/(6*a^3*d*(1 + Tan[c + d*x]^2)^3) + (5*Tan[c + d*x])/(24*a^3*d*(1 + Tan[c + d*x]^2)^2) + (5*Tan[c + d*x])/(16*a^3*d*(1 + Tan[c + d*x]^2))}


(* ::Subsubsection::Closed:: *)
(*n/2*)


{(a + b*Tan[c + d*x]^2)^(5/2), x, 6, ((a - b)^(5/2)*ArcTan[(Sqrt[a - b]*Tan[c + d*x])/Sqrt[a + b*Tan[c + d*x]^2]])/d + (Sqrt[b]*(15*a^2 - 20*a*b + 8*b^2)*ArcTanh[(Sqrt[b]*Tan[c + d*x])/Sqrt[a + b*Tan[c + d*x]^2]])/(8*d) + ((7*a - 4*b)*b*Tan[c + d*x]*Sqrt[a + b*Tan[c + d*x]^2])/(8*d) + (b*Tan[c + d*x]*(a + b*Tan[c + d*x]^2)^(3/2))/(4*d)}
{(a + b*Tan[c + d*x]^2)^(3/2), x, 5, ((a - b)^(3/2)*ArcTan[(Sqrt[a - b]*Tan[c + d*x])/Sqrt[a + b*Tan[c + d*x]^2]])/d + ((3*a - 2*b)*Sqrt[b]*ArcTanh[(Sqrt[b]*Tan[c + d*x])/Sqrt[a + b*Tan[c + d*x]^2]])/(2*d) + (b*Tan[c + d*x]*Sqrt[a + b*Tan[c + d*x]^2])/(2*d)}
{(a + b*Tan[c + d*x]^2)^(1/2), x, 4, (Sqrt[a - b]*ArcTan[(Sqrt[a - b]*Tan[c + d*x])/Sqrt[a + b*Tan[c + d*x]^2]])/d + (Sqrt[b]*ArcTanh[(Sqrt[b]*Tan[c + d*x])/Sqrt[a + b*Tan[c + d*x]^2]])/d}
{1/(a + b*Tan[c + d*x]^2)^(1/2), x, 2, ArcTan[(Sqrt[a - b]*Tan[c + d*x])/Sqrt[a + b*Tan[c + d*x]^2]]/(Sqrt[a - b]*d)}
{1/(a + b*Tan[c + d*x]^2)^(3/2), x, 3, ArcTan[(Sqrt[a - b]*Tan[c + d*x])/Sqrt[a + b*Tan[c + d*x]^2]]/((a - b)^(3/2)*d) - (b*Tan[c + d*x])/(a*(a - b)*d*Sqrt[a + b*Tan[c + d*x]^2])}
{1/(a + b*Tan[c + d*x]^2)^(5/2), x, 5, ArcTan[(Sqrt[a - b]*Tan[c + d*x])/Sqrt[a + b*Tan[c + d*x]^2]]/((a - b)^(5/2)*d) - (b*Tan[c + d*x])/(3*a*(a - b)*d*(a + b*Tan[c + d*x]^2)^(3/2)) - ((5*a - 2*b)*b*Tan[c + d*x])/(3*a^2*(a - b)^2*d*Sqrt[a + b*Tan[c + d*x]^2])}
{1/(a + b*Tan[c + d*x]^2)^(7/2), x, 6, ArcTan[(Sqrt[a - b]*Tan[c + d*x])/Sqrt[a + b*Tan[c + d*x]^2]]/((a - b)^(7/2)*d) - (b*Tan[c + d*x])/(5*a*(a - b)*d*(a + b*Tan[c + d*x]^2)^(5/2)) - ((9*a - 4*b)*b*Tan[c + d*x])/(15*a^2*(a - b)^2*d*(a + b*Tan[c + d*x]^2)^(3/2)) - (b*(33*a^2 - 26*a*b + 8*b^2)*Tan[c + d*x])/(15*a^3*(a - b)^3*d*Sqrt[a + b*Tan[c + d*x]^2])}


{(a + a*Tan[c + d*x]^2)^(5/2), x, 5, (3*a^(5/2)*ArcTanh[(Sqrt[a]*Tan[c + d*x])/Sqrt[a + a*Tan[c + d*x]^2]])/(8*d) + (3*a^2*Tan[c + d*x]*Sqrt[a + a*Tan[c + d*x]^2])/(8*d) + (a*Tan[c + d*x]*(a + a*Tan[c + d*x]^2)^(3/2))/(4*d)}
{(a + a*Tan[c + d*x]^2)^(3/2), x, 4, (a^(3/2)*ArcTanh[(Sqrt[a]*Tan[c + d*x])/Sqrt[a + a*Tan[c + d*x]^2]])/(2*d) + (a*Tan[c + d*x]*Sqrt[a + a*Tan[c + d*x]^2])/(2*d)}
{(a + a*Tan[c + d*x]^2)^(1/2), x, 3, (Sqrt[a]*ArcTanh[(Sqrt[a]*Tan[c + d*x])/Sqrt[a + a*Tan[c + d*x]^2]])/d}
{1/(a + a*Tan[c + d*x]^2)^(1/2), x, 3, Tan[c + d*x]/(d*Sqrt[a + a*Tan[c + d*x]^2])}
{1/(a + a*Tan[c + d*x]^2)^(3/2), x, 4, Tan[c + d*x]/(3*d*(a + a*Tan[c + d*x]^2)^(3/2)) + (2*Tan[c + d*x])/(3*a*d*Sqrt[a + a*Tan[c + d*x]^2])}
{1/(a + a*Tan[c + d*x]^2)^(5/2), x, 5, Tan[c + d*x]/(5*d*(a + a*Tan[c + d*x]^2)^(5/2)) + (4*Tan[c + d*x])/(15*a*d*(a + a*Tan[c + d*x]^2)^(3/2)) + (8*Tan[c + d*x])/(15*a^2*d*Sqrt[a + a*Tan[c + d*x]^2])}
{1/(a + a*Tan[c + d*x]^2)^(7/2), x, 6, Tan[c + d*x]/(7*d*(a + a*Tan[c + d*x]^2)^(7/2)) + (6*Tan[c + d*x])/(35*a*d*(a + a*Tan[c + d*x]^2)^(5/2)) + (8*Tan[c + d*x])/(35*a^2*d*(a + a*Tan[c + d*x]^2)^(3/2)) + (16*Tan[c + d*x])/(35*a^3*d*Sqrt[a + a*Tan[c + d*x]^2])}


{(1 + Tan[x]^2)^(3/2), x, 3, (1/2)*ArcSinh[Tan[x]] + (1/2)*Tan[x]*Sqrt[1 + Tan[x]^2]}
{Sqrt[1 + Tan[x]^2], x, 2, ArcSinh[Tan[x]]}
{1/Sqrt[1 + Tan[x]^2], x, 2, Tan[x]/Sqrt[1 + Tan[x]^2]}


{(1 - Tan[x]^2)^(3/2), x, 5, (-(5/2))*ArcSin[Tan[x]] + 2*Sqrt[2]*ArcTan[(Sqrt[2]*Tan[x])/Sqrt[1 - Tan[x]^2]] - (1/2)*Tan[x]*Sqrt[1 - Tan[x]^2]}
{Sqrt[1 - Tan[x]^2], x, 4, -ArcSin[Tan[x]] + Sqrt[2]*ArcTan[(Sqrt[2]*Tan[x])/Sqrt[1 - Tan[x]^2]]}
{1/Sqrt[1 - Tan[x]^2], x, 2, ArcTan[(Sqrt[2]*Tan[x])/Sqrt[1 - Tan[x]^2]]/Sqrt[2]}


{(-1 + Tan[x]^2)^(3/2), x, 5, (-(5/2))*ArcTanh[Tan[x]/Sqrt[-1 + Tan[x]^2]] + 2*Sqrt[2]*ArcTanh[(Sqrt[2]*Tan[x])/Sqrt[-1 + Tan[x]^2]] + (1/2)*Tan[x]*Sqrt[-1 + Tan[x]^2]}
{Sqrt[-1 + Tan[x]^2], x, 4, ArcTanh[Tan[x]/Sqrt[-1 + Tan[x]^2]] - Sqrt[2]*ArcTanh[(Sqrt[2]*Tan[x])/Sqrt[-1 + Tan[x]^2]]}
{1/Sqrt[-1 + Tan[x]^2], x, 2, ArcTanh[(Sqrt[2]*Tan[x])/Sqrt[-1 + Tan[x]^2]]/Sqrt[2]}


{(-1 - Tan[x]^2)^(3/2), x, 4, (1/2)*ArcTan[Tan[x]/Sqrt[-1 - Tan[x]^2]] - (1/2)*Tan[x]*Sqrt[-1 - Tan[x]^2]}
{Sqrt[-1 - Tan[x]^2], x, 3, -ArcTan[Tan[x]/Sqrt[-1 - Tan[x]^2]]}
{1/Sqrt[-1 - Tan[x]^2], x, 3, Tan[x]/Sqrt[-1 - Tan[x]^2]}


(* ::Subsection::Closed:: *)
(*Integrands of the form (a+b Tan[c+d x]^3)^n*)


(* ::Subsubsection::Closed:: *)
(*n*)


{(a + b*Tan[c + d*x]^3)^4, x, 6, (a^4 - 6*a^2*b^2 + b^4)*x - (2*a*b*(a^2 - b^2)*Log[1 + Tan[c + d*x]^2])/d + (b^2*(6*a^2 - b^2)*Tan[c + d*x])/d + (2*a*b*(a^2 - b^2)*Tan[c + d*x]^2)/d - (b^2*(6*a^2 - b^2)*Tan[c + d*x]^3)/(3*d) + (a*b^3*Tan[c + d*x]^4)/d + (b^2*(6*a^2 - b^2)*Tan[c + d*x]^5)/(5*d) - (2*a*b^3*Tan[c + d*x]^6)/(3*d) + (b^4*Tan[c + d*x]^7)/(7*d) + (a*b^3*Tan[c + d*x]^8)/(2*d) - (b^4*Tan[c + d*x]^9)/(9*d) + (b^4*Tan[c + d*x]^11)/(11*d)}
{(a + b*Tan[c + d*x]^3)^3, x, 6, a*(a^2 - 3*b^2)*x - (b*(3*a^2 - b^2)*Log[1 + Tan[c + d*x]^2])/(2*d) + (3*a*b^2*Tan[c + d*x])/d + (b*(3*a^2 - b^2)*Tan[c + d*x]^2)/(2*d) - (a*b^2*Tan[c + d*x]^3)/d + (b^3*Tan[c + d*x]^4)/(4*d) + (3*a*b^2*Tan[c + d*x]^5)/(5*d) - (b^3*Tan[c + d*x]^6)/(6*d) + (b^3*Tan[c + d*x]^8)/(8*d)}
{(a + b*Tan[c + d*x]^3)^2, x, 6, (a^2 - b^2)*x - (a*b*Log[1 + Tan[c + d*x]^2])/d + (b^2*Tan[c + d*x])/d + (a*b*Tan[c + d*x]^2)/d - (b^2*Tan[c + d*x]^3)/(3*d) + (b^2*Tan[c + d*x]^5)/(5*d)}
{(a + b*Tan[c + d*x]^3)^1, x, 3, a*x + (b*Log[Cos[c + d*x]])/d + (b*Tan[c + d*x]^2)/(2*d)}
{1/(a + b*Tan[c + d*x]^3)^1, x, 13, (a*x)/(a^2 + b^2) + (b^(1/3)*(a^(4/3) - b^(4/3))*ArcTan[(a^(1/3) - 2*b^(1/3)*Tan[c + d*x])/(Sqrt[3]*a^(1/3))])/(Sqrt[3]*a^(2/3)*(a^2 + b^2)*d) + (b^(1/3)*(a^(4/3) + b^(4/3))*Log[a^(1/3) + b^(1/3)*Tan[c + d*x]])/(3*a^(2/3)*(a^2 + b^2)*d) + (b*Log[1 + Tan[c + d*x]^2])/(2*(a^2 + b^2)*d) - (b^(1/3)*(a^(4/3) + b^(4/3))*Log[a^(2/3) - a^(1/3)*b^(1/3)*Tan[c + d*x] + b^(2/3)*Tan[c + d*x]^2])/(6*a^(2/3)*(a^2 + b^2)*d) - (b*Log[a + b*Tan[c + d*x]^3])/(3*(a^2 + b^2)*d)}
{1/(a + b*Tan[c + d*x]^3)^2, x, 28, ((a^2 - b^2)*x)/(a^2 + b^2)^2 + (b^(1/3)*(a^2 - 2*a^(2/3)*b^(4/3) - b^2)*ArcTan[(a^(1/3) - 2*b^(1/3)*Tan[c + d*x])/(Sqrt[3]*a^(1/3))])/(Sqrt[3]*a^(1/3)*(a^2 + b^2)^2*d) + (b^(1/3)*ArcTan[(a^(1/3) - 2*b^(1/3)*Tan[c + d*x])/(Sqrt[3]*a^(1/3))])/(3*Sqrt[3]*a^(1/3)*(a^2 + b^2)*d) - (2*b^(5/3)*ArcTan[(a^(1/3) - 2*b^(1/3)*Tan[c + d*x])/(Sqrt[3]*a^(1/3))])/(3*Sqrt[3]*a^(5/3)*(a^2 + b^2)*d) + (b^(1/3)*(a^2 + 2*a^(2/3)*b^(4/3) - b^2)*Log[a^(1/3) + b^(1/3)*Tan[c + d*x]])/(3*a^(1/3)*(a^2 + b^2)^2*d) + (b^(1/3)*Log[a^(1/3) + b^(1/3)*Tan[c + d*x]])/(9*a^(1/3)*(a^2 + b^2)*d) + (2*b^(5/3)*Log[a^(1/3) + b^(1/3)*Tan[c + d*x]])/(9*a^(5/3)*(a^2 + b^2)*d) + (a*b*Log[1 + Tan[c + d*x]^2])/((a^2 + b^2)^2*d) - (b^(1/3)*(a^2 + 2*a^(2/3)*b^(4/3) - b^2)*Log[a^(2/3) - a^(1/3)*b^(1/3)*Tan[c + d*x] + b^(2/3)*Tan[c + d*x]^2])/(6*a^(1/3)*(a^2 + b^2)^2*d) - (b^(1/3)*Log[a^(2/3) - a^(1/3)*b^(1/3)*Tan[c + d*x] + b^(2/3)*Tan[c + d*x]^2])/(18*a^(1/3)*(a^2 + b^2)*d) - (b^(5/3)*Log[a^(2/3) - a^(1/3)*b^(1/3)*Tan[c + d*x] + b^(2/3)*Tan[c + d*x]^2])/(9*a^(5/3)*(a^2 + b^2)*d) - (2*a*b*Log[a + b*Tan[c + d*x]^3])/(3*(a^2 + b^2)^2*d) + b/(3*(a^2 + b^2)*d*(a + b*Tan[c + d*x]^3)) + (b^2*Tan[c + d*x])/(3*a*(a^2 + b^2)*d*(a + b*Tan[c + d*x]^3)) - (b*Tan[c + d*x]^2)/(3*(a^2 + b^2)*d*(a + b*Tan[c + d*x]^3))}


{1/(1 + Tan[x]^3), x, 7, x/2 + (1/6)*Log[1 + Tan[x]] + (1/4)*Log[1 + Tan[x]^2] - (1/3)*Log[1 - Tan[x] + Tan[x]^2]}


(* ::Subsubsection:: *)
(*n/2*)


(* ::Subsection::Closed:: *)
(*Integrands of the form (a+b Tan[c+d x]^4)^n*)


(* ::Subsubsection::Closed:: *)
(*n*)


{(a + b*Tan[c + d*x]^4)^4, x, 4, (a + b)^4*x - (b*(2*a + b)*(2*a^2 + 2*a*b + b^2)*Tan[c + d*x])/d + (b*(2*a + b)*(2*a^2 + 2*a*b + b^2)*Tan[c + d*x]^3)/(3*d) - (b^2*(6*a^2 + 4*a*b + b^2)*Tan[c + d*x]^5)/(5*d) + (b^2*(6*a^2 + 4*a*b + b^2)*Tan[c + d*x]^7)/(7*d) - (b^3*(4*a + b)*Tan[c + d*x]^9)/(9*d) + (b^3*(4*a + b)*Tan[c + d*x]^11)/(11*d) - (b^4*Tan[c + d*x]^13)/(13*d) + (b^4*Tan[c + d*x]^15)/(15*d)}
{(a + b*Tan[c + d*x]^4)^3, x, 4, (a + b)^3*x - (b*(3*a^2 + 3*a*b + b^2)*Tan[c + d*x])/d + (b*(3*a^2 + 3*a*b + b^2)*Tan[c + d*x]^3)/(3*d) - (b^2*(3*a + b)*Tan[c + d*x]^5)/(5*d) + (b^2*(3*a + b)*Tan[c + d*x]^7)/(7*d) - (b^3*Tan[c + d*x]^9)/(9*d) + (b^3*Tan[c + d*x]^11)/(11*d)}
{(a + b*Tan[c + d*x]^4)^2, x, 4, (a + b)^2*x - (b*(2*a + b)*Tan[c + d*x])/d + (b*(2*a + b)*Tan[c + d*x]^3)/(3*d) - (b^2*Tan[c + d*x]^5)/(5*d) + (b^2*Tan[c + d*x]^7)/(7*d)}
{(a + b*Tan[c + d*x]^4)^1, x, 4, a*x + b*x - (b*Tan[c + d*x])/d + (b*Tan[c + d*x]^3)/(3*d)}
{1/(a + b*Tan[c + d*x]^4)^1, x, 7, x/(a + b) - ((Sqrt[-a] + Sqrt[b])*b^(1/4)*ArcTan[(b^(1/4)*Tan[c + d*x])/(-a)^(1/4)])/(2*(-a)^(3/4)*(a + b)*d) + ((Sqrt[-a] - Sqrt[b])*b^(1/4)*ArcTanh[(b^(1/4)*Tan[c + d*x])/(-a)^(1/4)])/(2*(-a)^(3/4)*(a + b)*d)}
{1/(a + b*Tan[c + d*x]^4)^2, x, 11, x/(a + b)^2 - ((Sqrt[-a] + Sqrt[b])*b^(1/4)*ArcTan[(b^(1/4)*Tan[c + d*x])/(-a)^(1/4)])/(2*(-a)^(3/4)*(a + b)^2*d) + ((Sqrt[-a] + 3*Sqrt[b])*b^(1/4)*ArcTan[(b^(1/4)*Tan[c + d*x])/(-a)^(1/4)])/(8*(-a)^(7/4)*(a + b)*d) + ((Sqrt[-a] - Sqrt[b])*b^(1/4)*ArcTanh[(b^(1/4)*Tan[c + d*x])/(-a)^(1/4)])/(2*(-a)^(3/4)*(a + b)^2*d) - ((Sqrt[-a] - 3*Sqrt[b])*b^(1/4)*ArcTanh[(b^(1/4)*Tan[c + d*x])/(-a)^(1/4)])/(8*(-a)^(7/4)*(a + b)*d) + (b*Tan[c + d*x]*(1 - Tan[c + d*x]^2))/(4*a*(a + b)*d*(a + b*Tan[c + d*x]^4))}


(* ::Subsubsection::Closed:: *)
(*n/2*)


{(a + b*Tan[c + d*x]^4)^(1/2), x, 6, -((a^(3/4)*(-b)^(1/4)*EllipticE[ArcSin[((-b)^(1/4)*Tan[c + d*x])/a^(1/4)], -1]*Sqrt[(a + b*Tan[c + d*x]^4)/a])/(d*Sqrt[a + b*Tan[c + d*x]^4])) + (a^(1/4)*(Sqrt[a] + Sqrt[-b])*(-b)^(1/4)*EllipticF[ArcSin[((-b)^(1/4)*Tan[c + d*x])/a^(1/4)], -1]*Sqrt[(a + b*Tan[c + d*x]^4)/a])/(d*Sqrt[a + b*Tan[c + d*x]^4]) + ((a + b)*EllipticPi[Sqrt[a]/Sqrt[-b], ArcSin[Sqrt[-(Sqrt[-b]/Sqrt[a])]*Tan[c + d*x]], -1]*Sqrt[(a + b*Tan[c + d*x]^4)/a])/(Sqrt[-(Sqrt[-b]/Sqrt[a])]*d*Sqrt[a + b*Tan[c + d*x]^4])}
{1/(a + b*Tan[c + d*x]^4)^(1/2), x, 3, (EllipticPi[Sqrt[a]/Sqrt[-b], ArcSin[Sqrt[-(Sqrt[-b]/Sqrt[a])]*Tan[c + d*x]], -1]*Sqrt[(a + b*Tan[c + d*x]^4)/a])/(Sqrt[-(Sqrt[-b]/Sqrt[a])]*d*Sqrt[a + b*Tan[c + d*x]^4])}


(* ::Section:: *)
(*Integrands of the form (a+b Cot[c+d x]^m)^n*)


(* ::Subsection::Closed:: *)
(*Integrands of the form (a+b Cot[c+d x]^2)^n*)


(* ::Subsubsection::Closed:: *)
(*n*)


{(a + b*Cot[c + d*x]^2)^4, x, 4, (a - b)^4*x - ((2*a - b)*b*(2*a^2 - 2*a*b + b^2)*Cot[c + d*x])/d - (b^2*(6*a^2 - 4*a*b + b^2)*Cot[c + d*x]^3)/(3*d) - ((4*a - b)*b^3*Cot[c + d*x]^5)/(5*d) - (b^4*Cot[c + d*x]^7)/(7*d)}
{(a + b*Cot[c + d*x]^2)^3, x, 4, (a - b)^3*x - (b*(3*a^2 - 3*a*b + b^2)*Cot[c + d*x])/d - ((3*a - b)*b^2*Cot[c + d*x]^3)/(3*d) - (b^3*Cot[c + d*x]^5)/(5*d)}
{(a + b*Cot[c + d*x]^2)^2, x, 4, (a - b)^2*x - ((2*a - b)*b*Cot[c + d*x])/d - (b^2*Cot[c + d*x]^3)/(3*d)}
{(a + b*Cot[c + d*x]^2)^1, x, 3, a*x - b*x - (b*Cot[c + d*x])/d}
{1/(a + b*Cot[c + d*x]^2)^1, x, 3, x/(a - b) + (Sqrt[b]*ArcTan[(Sqrt[b]*Cot[c + d*x])/Sqrt[a]])/(Sqrt[a]*(a - b)*d)}
{1/(a + b*Cot[c + d*x]^2)^2, x, 5, x/(a - b)^2 + ((3*a - b)*Sqrt[b]*ArcTan[(Sqrt[b]*Cot[c + d*x])/Sqrt[a]])/(2*a^(3/2)*(a - b)^2*d) + (b*Cot[c + d*x])/(2*a*(a - b)*d*(a + b*Cot[c + d*x]^2))}
{1/(a + b*Cot[c + d*x]^2)^3, x, 6, x/(a - b)^3 + (Sqrt[b]*(15*a^2 - 10*a*b + 3*b^2)*ArcTan[(Sqrt[b]*Cot[c + d*x])/Sqrt[a]])/(8*a^(5/2)*(a - b)^3*d) + (b*Cot[c + d*x])/(4*a*(a - b)*d*(a + b*Cot[c + d*x]^2)^2) + ((7*a - 3*b)*b*Cot[c + d*x])/(8*a^2*(a - b)^2*d*(a + b*Cot[c + d*x]^2))}


(* ::Subsubsection::Closed:: *)
(*n/2*)


{(a + b*Cot[c + d*x]^2)^(5/2), x, 6, -(((a - b)^(5/2)*ArcTan[(Sqrt[a - b]*Cot[c + d*x])/Sqrt[a + b*Cot[c + d*x]^2]])/d) - (Sqrt[b]*(15*a^2 - 20*a*b + 8*b^2)*ArcTanh[(Sqrt[b]*Cot[c + d*x])/Sqrt[a + b*Cot[c + d*x]^2]])/(8*d) - ((7*a - 4*b)*b*Cot[c + d*x]*Sqrt[a + b*Cot[c + d*x]^2])/(8*d) - (b*Cot[c + d*x]*(a + b*Cot[c + d*x]^2)^(3/2))/(4*d)}
{(a + b*Cot[c + d*x]^2)^(3/2), x, 5, -(((a - b)^(3/2)*ArcTan[(Sqrt[a - b]*Cot[c + d*x])/Sqrt[a + b*Cot[c + d*x]^2]])/d) - ((3*a - 2*b)*Sqrt[b]*ArcTanh[(Sqrt[b]*Cot[c + d*x])/Sqrt[a + b*Cot[c + d*x]^2]])/(2*d) - (b*Cot[c + d*x]*Sqrt[a + b*Cot[c + d*x]^2])/(2*d)}
{(a + b*Cot[c + d*x]^2)^(1/2), x, 4, -((Sqrt[a - b]*ArcTan[(Sqrt[a - b]*Cot[c + d*x])/Sqrt[a + b*Cot[c + d*x]^2]])/d) - (Sqrt[b]*ArcTanh[(Sqrt[b]*Cot[c + d*x])/Sqrt[a + b*Cot[c + d*x]^2]])/d}
{1/(a + b*Cot[c + d*x]^2)^(1/2), x, 2, -(ArcTan[(Sqrt[a - b]*Cot[c + d*x])/Sqrt[a + b*Cot[c + d*x]^2]]/(Sqrt[a - b]*d))}
{1/(a + b*Cot[c + d*x]^2)^(3/2), x, 3, -(ArcTan[(Sqrt[a - b]*Cot[c + d*x])/Sqrt[a + b*Cot[c + d*x]^2]]/((a - b)^(3/2)*d)) + (b*Cot[c + d*x])/(a*(a - b)*d*Sqrt[a + b*Cot[c + d*x]^2])}
{1/(a + b*Cot[c + d*x]^2)^(5/2), x, 5, -(ArcTan[(Sqrt[a - b]*Cot[c + d*x])/Sqrt[a + b*Cot[c + d*x]^2]]/((a - b)^(5/2)*d)) + (b*Cot[c + d*x])/(3*a*(a - b)*d*(a + b*Cot[c + d*x]^2)^(3/2)) + ((5*a - 2*b)*b*Cot[c + d*x])/(3*a^2*(a - b)^2*d*Sqrt[a + b*Cot[c + d*x]^2])}
{1/(a + b*Cot[c + d*x]^2)^(7/2), x, 6, -(ArcTan[(Sqrt[a - b]*Cot[c + d*x])/Sqrt[a + b*Cot[c + d*x]^2]]/((a - b)^(7/2)*d)) + (b*Cot[c + d*x])/(5*a*(a - b)*d*(a + b*Cot[c + d*x]^2)^(5/2)) + ((9*a - 4*b)*b*Cot[c + d*x])/(15*a^2*(a - b)^2*d*(a + b*Cot[c + d*x]^2)^(3/2)) + (b*(33*a^2 - 26*a*b + 8*b^2)*Cot[c + d*x])/(15*a^3*(a - b)^3*d*Sqrt[a + b*Cot[c + d*x]^2])}


{(1 + Cot[x]^2)^(3/2), x, 3, (-(1/2))*ArcSinh[Cot[x]] - (1/2)*Cot[x]*Sqrt[1 + Cot[x]^2]}
{Sqrt[1 + Cot[x]^2], x, 2, -ArcSinh[Cot[x]]}
{1/Sqrt[1 + Cot[x]^2], x, 2, -(Cot[x]/Sqrt[1 + Cot[x]^2])}


{(1 - Cot[x]^2)^(3/2), x, 5, (5/2)*ArcSin[Cot[x]] - 2*Sqrt[2]*ArcTan[(Sqrt[2]*Cot[x])/Sqrt[1 - Cot[x]^2]] + (1/2)*Cot[x]*Sqrt[1 - Cot[x]^2]}
{Sqrt[1 - Cot[x]^2], x, 4, ArcSin[Cot[x]] - Sqrt[2]*ArcTan[(Sqrt[2]*Cot[x])/Sqrt[1 - Cot[x]^2]]}
{1/Sqrt[1 - Cot[x]^2], x, 2, -(ArcTan[(Sqrt[2]*Cot[x])/Sqrt[1 - Cot[x]^2]]/Sqrt[2])}


{(-1 + Cot[x]^2)^(3/2), x, 5, (5/2)*ArcTanh[Cot[x]/Sqrt[-1 + Cot[x]^2]] - 2*Sqrt[2]*ArcTanh[(Sqrt[2]*Cot[x])/Sqrt[-1 + Cot[x]^2]] - (1/2)*Cot[x]*Sqrt[-1 + Cot[x]^2]}
{Sqrt[-1 + Cot[x]^2], x, 4, -ArcTanh[Cot[x]/Sqrt[-1 + Cot[x]^2]] + Sqrt[2]*ArcTanh[(Sqrt[2]*Cot[x])/Sqrt[-1 + Cot[x]^2]]}
{1/Sqrt[-1 + Cot[x]^2], x, 2, -(ArcTanh[(Sqrt[2]*Cot[x])/Sqrt[-1 + Cot[x]^2]]/Sqrt[2])}


{(-1 - Cot[x]^2)^(3/2), x, 4, (-(1/2))*ArcTan[Cot[x]/Sqrt[-1 - Cot[x]^2]] + (1/2)*Cot[x]*Sqrt[-1 - Cot[x]^2]}
{Sqrt[-1 - Cot[x]^2], x, 3, ArcTan[Cot[x]/Sqrt[-1 - Cot[x]^2]]}
{1/Sqrt[-1 - Cot[x]^2], x, 3, -(Cot[x]/Sqrt[-1 - Cot[x]^2])}


(* ::Subsection::Closed:: *)
(*Integrands of the form (a+b Cot[c+d x]^3)^n*)


{1/(1 + Cot[x]^3), x, 7, x/2 - (1/6)*Log[1 + Cot[x]] - (1/4)*Log[1 + Cot[x]^2] + (1/3)*Log[1 - Cot[x] + Cot[x]^2]}


(* ::Subsection:: *)
(*Integrands of the form (a+b Cot[c+d x]^4)^n*)


(* ::Section:: *)
(*Integrands of the form (a+b Sec[c+d x]^m)^n*)


(* ::Subsection::Closed:: *)
(*Integrands of the form (a+b Sec[c+d x]^2)^n*)


(* ::Subsubsection::Closed:: *)
(*n*)


{(a + b*Sec[c + d*x]^2)^4, x, 4, a^4*x + (b*(2*a + b)*(2*a^2 + 2*a*b + b^2)*Tan[c + d*x])/d + (b^2*(6*a^2 + 8*a*b + 3*b^2)*Tan[c + d*x]^3)/(3*d) + (b^3*(4*a + 3*b)*Tan[c + d*x]^5)/(5*d) + (b^4*Tan[c + d*x]^7)/(7*d)}
{(a + b*Sec[c + d*x]^2)^3, x, 4, a^3*x + (b*(3*a^2 + 3*a*b + b^2)*Tan[c + d*x])/d + (b^2*(3*a + 2*b)*Tan[c + d*x]^3)/(3*d) + (b^3*Tan[c + d*x]^5)/(5*d)}
{(a + b*Sec[c + d*x]^2)^2, x, 4, a^2*x + (b*(2*a + b)*Tan[c + d*x])/d + (b^2*Tan[c + d*x]^3)/(3*d)}
{(a + b*Sec[c + d*x]^2)^1, x, 2, a*x + (b*Tan[c + d*x])/d}
{1/(a + b*Sec[c + d*x]^2)^1, x, 3, x/a - (Sqrt[b]*ArcTan[(Sqrt[b]*Tan[c + d*x])/Sqrt[a + b]])/(a*Sqrt[a + b]*d)}
{1/(a + b*Sec[c + d*x]^2)^2, x, 5, x/a^2 - (Sqrt[b]*(3*a + 2*b)*ArcTan[(Sqrt[b]*Tan[c + d*x])/Sqrt[a + b]])/(2*a^2*(a + b)^(3/2)*d) - (b*Tan[c + d*x])/(2*a*(a + b)*d*(a + b + b*Tan[c + d*x]^2))}
{1/(a + b*Sec[c + d*x]^2)^3, x, 6, x/a^3 - (Sqrt[b]*(15*a^2 + 20*a*b + 8*b^2)*ArcTan[(Sqrt[b]*Tan[c + d*x])/Sqrt[a + b]])/(8*a^3*(a + b)^(5/2)*d) - (b*Tan[c + d*x])/(4*a*(a + b)*d*(a + b + b*Tan[c + d*x]^2)^2) - (b*(7*a + 4*b)*Tan[c + d*x])/(8*a^2*(a + b)^2*d*(a + b + b*Tan[c + d*x]^2))}
{1/(a + b*Sec[c + d*x]^2)^4, x, 7, x/a^4 - (Sqrt[b]*(35*a^3 + 70*a^2*b + 56*a*b^2 + 16*b^3)*ArcTan[(Sqrt[b]*Tan[c + d*x])/Sqrt[a + b]])/(16*a^4*(a + b)^(7/2)*d) - (b*Tan[c + d*x])/(6*a*(a + b)*d*(a + b + b*Tan[c + d*x]^2)^3) - (b*(11*a + 6*b)*Tan[c + d*x])/(24*a^2*(a + b)^2*d*(a + b + b*Tan[c + d*x]^2)^2) - (b*(19*a^2 + 22*a*b + 8*b^2)*Tan[c + d*x])/(16*a^3*(a + b)^3*d*(a + b + b*Tan[c + d*x]^2))}


{(a - a*Sec[c + d*x]^2)^4, x, 7, a^4*x - (a^4*Tan[c + d*x])/d + (a^4*Tan[c + d*x]^3)/(3*d) - (a^4*Tan[c + d*x]^5)/(5*d) + (a^4*Tan[c + d*x]^7)/(7*d)}
{(a - a*Sec[c + d*x]^2)^3, x, 6, a^3*x - (a^3*Tan[c + d*x])/d + (a^3*Tan[c + d*x]^3)/(3*d) - (a^3*Tan[c + d*x]^5)/(5*d)}
{(a - a*Sec[c + d*x]^2)^2, x, 5, a^2*x - (a^2*Tan[c + d*x])/d + (a^2*Tan[c + d*x]^3)/(3*d)}
{(a - a*Sec[c + d*x]^2)^1, x, 2, a*x - (a*Tan[c + d*x])/d}
{1/(a - a*Sec[c + d*x]^2)^1, x, 4, x/a + Cot[c + d*x]/(a*d)}
{1/(a - a*Sec[c + d*x]^2)^2, x, 5, x/a^2 + Cot[c + d*x]/(a^2*d) - Cot[c + d*x]^3/(3*a^2*d)}
{1/(a - a*Sec[c + d*x]^2)^3, x, 6, x/a^3 + Cot[c + d*x]/(a^3*d) - Cot[c + d*x]^3/(3*a^3*d) + Cot[c + d*x]^5/(5*a^3*d)}
{1/(a - a*Sec[c + d*x]^2)^4, x, 7, x/a^4 + Cot[c + d*x]/(a^4*d) - Cot[c + d*x]^3/(3*a^4*d) + Cot[c + d*x]^5/(5*a^4*d) - Cot[c + d*x]^7/(7*a^4*d)}


(* ::Subsubsection::Closed:: *)
(*n/2*)


{(a + b*Sec[c + d*x]^2)^(5/2), x, 6, (a^(5/2)*ArcTan[(Sqrt[a]*Tan[c + d*x])/Sqrt[a + b + b*Tan[c + d*x]^2]])/d + (Sqrt[b]*(15*a^2 + 10*a*b + 3*b^2)*ArcTanh[(Sqrt[b]*Tan[c + d*x])/Sqrt[a + b + b*Tan[c + d*x]^2]])/(8*d) + (b*(7*a + 3*b)*Tan[c + d*x]*Sqrt[a + b + b*Tan[c + d*x]^2])/(8*d) + (b*Tan[c + d*x]*(a + b + b*Tan[c + d*x]^2)^(3/2))/(4*d)}
{(a + b*Sec[c + d*x]^2)^(3/2), x, 5, (a^(3/2)*ArcTan[(Sqrt[a]*Tan[c + d*x])/Sqrt[a + b + b*Tan[c + d*x]^2]])/d + (Sqrt[b]*(3*a + b)*ArcTanh[(Sqrt[b]*Tan[c + d*x])/Sqrt[a + b + b*Tan[c + d*x]^2]])/(2*d) + (b*Tan[c + d*x]*Sqrt[a + b + b*Tan[c + d*x]^2])/(2*d)}
{(a + b*Sec[c + d*x]^2)^(1/2), x, 4, (Sqrt[a]*ArcTan[(Sqrt[a]*Tan[c + d*x])/Sqrt[a + b + b*Tan[c + d*x]^2]])/d + (Sqrt[b]*ArcTanh[(Sqrt[b]*Tan[c + d*x])/Sqrt[a + b + b*Tan[c + d*x]^2]])/d}
{1/(a + b*Sec[c + d*x]^2)^(1/2), x, 2, ArcTan[(Sqrt[a]*Tan[c + d*x])/Sqrt[a + b*Sec[c + d*x]^2]]/(Sqrt[a]*d), ArcTan[(Sqrt[a]*Tan[c + d*x])/Sqrt[a + b + b*Tan[c + d*x]^2]]/(Sqrt[a]*d)}
{1/(a + b*Sec[c + d*x]^2)^(3/2), x, 3, ArcTan[(Sqrt[a]*Tan[c + d*x])/Sqrt[a + b + b*Tan[c + d*x]^2]]/(a^(3/2)*d) - (b*Tan[c + d*x])/(a*(a + b)*d*Sqrt[a + b + b*Tan[c + d*x]^2])}
{1/(a + b*Sec[c + d*x]^2)^(5/2), x, 5, ArcTan[(Sqrt[a]*Tan[c + d*x])/Sqrt[a + b + b*Tan[c + d*x]^2]]/(a^(5/2)*d) - (b*Tan[c + d*x])/(3*a*(a + b)*d*(a + b + b*Tan[c + d*x]^2)^(3/2)) - (b*(5*a + 3*b)*Tan[c + d*x])/(3*a^2*(a + b)^2*d*Sqrt[a + b + b*Tan[c + d*x]^2])}
{1/(a + b*Sec[c + d*x]^2)^(7/2), x, 6, ArcTan[(Sqrt[a]*Tan[c + d*x])/Sqrt[a + b + b*Tan[c + d*x]^2]]/(a^(7/2)*d) - (b*Tan[c + d*x])/(5*a*(a + b)*d*(a + b + b*Tan[c + d*x]^2)^(5/2)) - (b*(9*a + 5*b)*Tan[c + d*x])/(15*a^2*(a + b)^2*d*(a + b + b*Tan[c + d*x]^2)^(3/2)) - (b*(33*a^2 + 40*a*b + 15*b^2)*Tan[c + d*x])/(15*a^3*(a + b)^3*d*Sqrt[a + b + b*Tan[c + d*x]^2])}


{(a - a*Sec[c + d*x]^2)^(7/2), x, 6, -((a^3*Cot[c + d*x]*Log[Cos[c + d*x]]*Sqrt[(-a)*Tan[c + d*x]^2])/d) - (a^3*Tan[c + d*x]*Sqrt[(-a)*Tan[c + d*x]^2])/(2*d) + (a^3*Tan[c + d*x]^3*Sqrt[(-a)*Tan[c + d*x]^2])/(4*d) - (a^3*Tan[c + d*x]^5*Sqrt[(-a)*Tan[c + d*x]^2])/(6*d)}
{(a - a*Sec[c + d*x]^2)^(5/2), x, 5, -((a^2*Cot[c + d*x]*Log[Cos[c + d*x]]*Sqrt[(-a)*Tan[c + d*x]^2])/d) - (a^2*Tan[c + d*x]*Sqrt[(-a)*Tan[c + d*x]^2])/(2*d) + (a^2*Tan[c + d*x]^3*Sqrt[(-a)*Tan[c + d*x]^2])/(4*d)}
{(a - a*Sec[c + d*x]^2)^(3/2), x, 4, -((a*Cot[c + d*x]*Log[Cos[c + d*x]]*Sqrt[(-a)*Tan[c + d*x]^2])/d) - (a*Tan[c + d*x]*Sqrt[(-a)*Tan[c + d*x]^2])/(2*d)}
{(a - a*Sec[c + d*x]^2)^(1/2), x, 3, -((Cot[c + d*x]*Log[Cos[c + d*x]]*Sqrt[(-a)*Tan[c + d*x]^2])/d)}
{1/(a - a*Sec[c + d*x]^2)^(1/2), x, 3, (Log[Sin[c + d*x]]*Tan[c + d*x])/(d*Sqrt[(-a)*Tan[c + d*x]^2])}
{1/(a - a*Sec[c + d*x]^2)^(3/2), x, 4, Cot[c + d*x]/(2*a*d*Sqrt[(-a)*Tan[c + d*x]^2]) + (Log[Sin[c + d*x]]*Tan[c + d*x])/(a*d*Sqrt[(-a)*Tan[c + d*x]^2])}
{1/(a - a*Sec[c + d*x]^2)^(5/2), x, 5, Cot[c + d*x]/(2*a^2*d*Sqrt[(-a)*Tan[c + d*x]^2]) - Cot[c + d*x]^3/(4*a^2*d*Sqrt[(-a)*Tan[c + d*x]^2]) + (Log[Sin[c + d*x]]*Tan[c + d*x])/(a^2*d*Sqrt[(-a)*Tan[c + d*x]^2])}
{1/(a - a*Sec[c + d*x]^2)^(7/2), x, 6, Cot[c + d*x]/(2*a^3*d*Sqrt[(-a)*Tan[c + d*x]^2]) - Cot[c + d*x]^3/(4*a^3*d*Sqrt[(-a)*Tan[c + d*x]^2]) + Cot[c + d*x]^5/(6*a^3*d*Sqrt[(-a)*Tan[c + d*x]^2]) + (Log[Sin[c + d*x]]*Tan[c + d*x])/(a^3*d*Sqrt[(-a)*Tan[c + d*x]^2])}


{(1 + Sec[x]^2)^(3/2), x, 5, 2*ArcSinh[Tan[x]/Sqrt[2]] + ArcTan[Tan[x]/Sqrt[2 + Tan[x]^2]] + (1/2)*Tan[x]*Sqrt[2 + Tan[x]^2]}
{Sqrt[1 + Sec[x]^2], x, 4, ArcSinh[Tan[x]/Sqrt[2]] + ArcTan[Tan[x]/Sqrt[2 + Tan[x]^2]]}
{1/Sqrt[1 + Sec[x]^2], x, 2, ArcTan[Tan[x]/Sqrt[2 + Tan[x]^2]]}


(* ::Subsection:: *)
(*Integrands of the form (a+b Sec[c+d x]^3)^n*)


(* ::Subsection:: *)
(*Integrands of the form (a+b Sec[c+d x]^4)^n*)


(* ::Section:: *)
(*Integrands of the form (a+b Csc[c+d x]^m)^n*)


(* ::Subsection::Closed:: *)
(*Integrands of the form (a+b Csc[c+d x]^2)^n*)


(* ::Subsubsection::Closed:: *)
(*n*)


{(a + b*Csc[c + d*x]^2)^4, x, 4, a^4*x - (b*(2*a + b)*(2*a^2 + 2*a*b + b^2)*Cot[c + d*x])/d - (b^2*(6*a^2 + 8*a*b + 3*b^2)*Cot[c + d*x]^3)/(3*d) - (b^3*(4*a + 3*b)*Cot[c + d*x]^5)/(5*d) - (b^4*Cot[c + d*x]^7)/(7*d)}
{(a + b*Csc[c + d*x]^2)^3, x, 4, a^3*x - (b*(3*a^2 + 3*a*b + b^2)*Cot[c + d*x])/d - (b^2*(3*a + 2*b)*Cot[c + d*x]^3)/(3*d) - (b^3*Cot[c + d*x]^5)/(5*d)}
{(a + b*Csc[c + d*x]^2)^2, x, 4, a^2*x - (b*(2*a + b)*Cot[c + d*x])/d - (b^2*Cot[c + d*x]^3)/(3*d)}
{(a + b*Csc[c + d*x]^2)^1, x, 2, a*x - (b*Cot[c + d*x])/d}
{1/(a + b*Csc[c + d*x]^2)^1, x, 3, x/a - (Sqrt[b]*ArcTan[(Sqrt[a + b]*Tan[c + d*x])/Sqrt[b]])/(a*Sqrt[a + b]*d)}
{1/(a + b*Csc[c + d*x]^2)^2, x, 5, x/a^2 + (Sqrt[b]*(3*a + 2*b)*ArcTan[(Sqrt[b]*Cot[c + d*x])/Sqrt[a + b]])/(2*a^2*(a + b)^(3/2)*d) + (b*Cot[c + d*x])/(2*a*(a + b)*d*(a + b + b*Cot[c + d*x]^2))}
{1/(a + b*Csc[c + d*x]^2)^3, x, 6, x/a^3 + (Sqrt[b]*(15*a^2 + 20*a*b + 8*b^2)*ArcTan[(Sqrt[b]*Cot[c + d*x])/Sqrt[a + b]])/(8*a^3*(a + b)^(5/2)*d) + (b*Cot[c + d*x])/(4*a*(a + b)*d*(a + b + b*Cot[c + d*x]^2)^2) + (b*(7*a + 4*b)*Cot[c + d*x])/(8*a^2*(a + b)^2*d*(a + b + b*Cot[c + d*x]^2))}
{1/(a + b*Csc[c + d*x]^2)^4, x, 7, x/a^4 + (Sqrt[b]*(35*a^3 + 70*a^2*b + 56*a*b^2 + 16*b^3)*ArcTan[(Sqrt[b]*Cot[c + d*x])/Sqrt[a + b]])/(16*a^4*(a + b)^(7/2)*d) + (b*Cot[c + d*x])/(6*a*(a + b)*d*(a + b + b*Cot[c + d*x]^2)^3) + (b*(11*a + 6*b)*Cot[c + d*x])/(24*a^2*(a + b)^2*d*(a + b + b*Cot[c + d*x]^2)^2) + (b*(19*a^2 + 22*a*b + 8*b^2)*Cot[c + d*x])/(16*a^3*(a + b)^3*d*(a + b + b*Cot[c + d*x]^2))}


(* ::Subsubsection::Closed:: *)
(*n/2*)


{(a + b*Csc[c + d*x]^2)^(5/2), x, 6, -((a^(5/2)*ArcTan[(Sqrt[a]*Cot[c + d*x])/Sqrt[a + b + b*Cot[c + d*x]^2]])/d) - (Sqrt[b]*(15*a^2 + 10*a*b + 3*b^2)*ArcTanh[(Sqrt[b]*Cot[c + d*x])/Sqrt[a + b + b*Cot[c + d*x]^2]])/(8*d) - (b*(7*a + 3*b)*Cot[c + d*x]*Sqrt[a + b + b*Cot[c + d*x]^2])/(8*d) - (b*Cot[c + d*x]*(a + b + b*Cot[c + d*x]^2)^(3/2))/(4*d)}
{(a + b*Csc[c + d*x]^2)^(3/2), x, 5, -((a^(3/2)*ArcTan[(Sqrt[a]*Cot[c + d*x])/Sqrt[a + b + b*Cot[c + d*x]^2]])/d) - (Sqrt[b]*(3*a + b)*ArcTanh[(Sqrt[b]*Cot[c + d*x])/Sqrt[a + b + b*Cot[c + d*x]^2]])/(2*d) - (b*Cot[c + d*x]*Sqrt[a + b + b*Cot[c + d*x]^2])/(2*d)}
{(a + b*Csc[c + d*x]^2)^(1/2), x, 4, -((Sqrt[a]*ArcTan[(Sqrt[a]*Cot[c + d*x])/Sqrt[a + b + b*Cot[c + d*x]^2]])/d) - (Sqrt[b]*ArcTanh[(Sqrt[b]*Cot[c + d*x])/Sqrt[a + b + b*Cot[c + d*x]^2]])/d}
{1/(a + b*Csc[c + d*x]^2)^(1/2), x, 2, -(ArcTan[(Sqrt[a]*Cot[c + d*x])/Sqrt[a + b*Csc[c + d*x]^2]]/(Sqrt[a]*d)), -(ArcTan[(Sqrt[a]*Cot[c + d*x])/Sqrt[a + b + b*Cot[c + d*x]^2]]/(Sqrt[a]*d))}
{1/(a + b*Csc[c + d*x]^2)^(3/2), x, 3, -(ArcTan[(Sqrt[a]*Cot[c + d*x])/Sqrt[a + b + b*Cot[c + d*x]^2]]/(a^(3/2)*d)) + (b*Cot[c + d*x])/(a*(a + b)*d*Sqrt[a + b + b*Cot[c + d*x]^2])}
{1/(a + b*Csc[c + d*x]^2)^(5/2), x, 5, -(ArcTan[(Sqrt[a]*Cot[c + d*x])/Sqrt[a + b + b*Cot[c + d*x]^2]]/(a^(5/2)*d)) + (b*Cot[c + d*x])/(3*a*(a + b)*d*(a + b + b*Cot[c + d*x]^2)^(3/2)) + (b*(5*a + 3*b)*Cot[c + d*x])/(3*a^2*(a + b)^2*d*Sqrt[a + b + b*Cot[c + d*x]^2])}
{1/(a + b*Csc[c + d*x]^2)^(7/2), x, 6, -(ArcTan[(Sqrt[a]*Cot[c + d*x])/Sqrt[a + b + b*Cot[c + d*x]^2]]/(a^(7/2)*d)) + (b*Cot[c + d*x])/(5*a*(a + b)*d*(a + b + b*Cot[c + d*x]^2)^(5/2)) + (b*(9*a + 5*b)*Cot[c + d*x])/(15*a^2*(a + b)^2*d*(a + b + b*Cot[c + d*x]^2)^(3/2)) + (b*(33*a^2 + 40*a*b + 15*b^2)*Cot[c + d*x])/(15*a^3*(a + b)^3*d*Sqrt[a + b + b*Cot[c + d*x]^2])}


{(1 + Csc[x]^2)^(3/2), x, 5, -2*ArcSinh[Cot[x]/Sqrt[2]] - ArcTan[Cot[x]/Sqrt[2 + Cot[x]^2]] - (1/2)*Cot[x]*Sqrt[2 + Cot[x]^2]}
{Sqrt[1 + Csc[x]^2], x, 4, -ArcSinh[Cot[x]/Sqrt[2]] - ArcTan[Cot[x]/Sqrt[2 + Cot[x]^2]]}
{1/Sqrt[1 + Csc[x]^2], x, 2, -ArcTan[Cot[x]/Sqrt[2 + Cot[x]^2]]}


{(1 - Csc[x]^2)^(3/2), x, 4, (1/2)*Cot[x]*Sqrt[-Cot[x]^2] + Sqrt[-Cot[x]^2]*Log[Sin[x]]*Tan[x]}
{Sqrt[1 - Csc[x]^2], x, 3, Sqrt[-Cot[x]^2]*Log[Sin[x]]*Tan[x]}
{1/Sqrt[1 - Csc[x]^2], x, 3, -((Cot[x]*Log[Cos[x]])/Sqrt[-Cot[x]^2])}


{(-1 + Csc[x]^2)^(3/2), x, 4, (-(1/2))*(Cot[x]^2)^(3/2)*Tan[x] - Sqrt[Cot[x]^2]*Log[Sin[x]]*Tan[x]}
{Sqrt[-1 + Csc[x]^2], x, 3, Sqrt[Cot[x]^2]*Log[Sin[x]]*Tan[x]}
{1/Sqrt[-1 + Csc[x]^2], x, 3, -((Cot[x]*Log[Cos[x]])/Sqrt[Cot[x]^2])}


{(-1 - Csc[x]^2)^(3/2), x, 5, -2*ArcTan[Cot[x]/Sqrt[-2 - Cot[x]^2]] - ArcTanh[Cot[x]/Sqrt[-2 - Cot[x]^2]] + (1/2)*Cot[x]*Sqrt[-2 - Cot[x]^2]}
{Sqrt[-1 - Csc[x]^2], x, 4, ArcTan[Cot[x]/Sqrt[-2 - Cot[x]^2]] + ArcTanh[Cot[x]/Sqrt[-2 - Cot[x]^2]]}
{1/Sqrt[-1 - Csc[x]^2], x, 2, -ArcTanh[Cot[x]/Sqrt[-2 - Cot[x]^2]]}


(* ::Subsection:: *)
(*Integrands of the form (a+b Csc[c+d x]^3)^n*)


(* ::Subsection:: *)
(*Integrands of the form (a+b Csc[c+d x]^4)^n*)
