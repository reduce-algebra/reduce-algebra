(* ::Package:: *)

(* ::Title:: *)
(*Symmetric Mod Function Integration Problems*)


{Mods[a + b/x], x, 2, b*Log[x] + x*Mods[a + b/x]}
{Mods[a + b*x^n], x, 2, x*(-((b*n*x^n)/(1 + n)) + Mods[a + b*x^n])}


{1/Mods[a + b*x^2], x, 1, ArcTan[(Sqrt[b]*x)/Sqrt[(-b)*x^2 + Mods[a + b*x^2]]]/(Sqrt[b]*Sqrt[(-b)*x^2 + Mods[a + b*x^2]])}
{1/Mods[a + b*x], x, 1, Log[Mods[a + b*x]]/b}
{1/Mods[a + b/x], x, 3, (x^2*((-b)*(1 + Log[x*Mods[a + b/x]]) + x*Mods[a + b/x]))/(b - x*Mods[a + b/x])^2}
{1/Mods[a + b/x^2], x, 3, -((x + (Sqrt[b]*ArcTan[Sqrt[b]/(x*Sqrt[-(b/x^2) + Mods[a + b/x^2]])])/Sqrt[-(b/x^2) + Mods[a + b/x^2]])/(b/x^2 - Mods[a + b/x^2]))}


(* Expressions of the form x^m*Mods[a+b*x]^n where m is an integer and n is symbolic *)
{Mods[a + b*x]^n, x, 1, Mods[a + b*x]^(1 + n)/(b + b*n)}
{x*Mods[a + b*x]^n, x, 2, ((b*(2 + n)*x - Mods[a + b*x])*Mods[a + b*x]^(1 + n))/(b^2*(1 + n)*(2 + n))}
{x^2*Mods[a + b*x]^n, x, 3, If[$VersionNumber>6, (Mods[a + b*x]^(1 + n)*(b^2*(6 + 5*n + n^2)*x^2 - 2*b*(3 + n)*x*Mods[a + b*x] + 2*Mods[a + b*x]^2))/(b^3*(3 + n)*(2 + 3*n + n^2)), (Mods[a + b*x]^(1 + n)*(b^2*(6 + 5*n + n^2)*x^2 - 2*b*(3 + n)*x*Mods[a + b*x] + 2*Mods[a + b*x]^2))/(b^3*(6 + 11*n + 6*n^2 + n^3))]}
{x^3*Mods[a + b*x]^n, x, 4, If[$VersionNumber>6, (Mods[a + b*x]^(1 + n)*(b^3*(24 + 26*n + 9*n^2 + n^3)*x^3 - 3*b^2*(12 + 7*n + n^2)*x^2*Mods[a + b*x] + 6*b*(4 + n)*x*Mods[a + b*x]^2 - 6*Mods[a + b*x]^3))/(b^4*(3 + n)*(4 + n)*(2 + 3*n + n^2)), (Mods[a + b*x]^(1 + n)*(b^3*(24 + 26*n + 9*n^2 + n^3)*x^3 - 3*b^2*(12 + 7*n + n^2)*x^2*Mods[a + b*x] + 6*b*(4 + n)*x*Mods[a + b*x]^2 - 6*Mods[a + b*x]^3))/(b^4*(24 + 50*n + 35*n^2 + 10*n^3 + n^4))]}
{Mods[a + b*x]^n/x, x, 0, Int[Mods[a+b*x]^n/x,x]}
{Mods[a + b*x]^n/x^2, x, 1, (b*n*Int[Mods[a + b*x]^n/x, x])/((-b)*x + Mods[a + b*x]) - Mods[a + b*x]^(1 + n)/(x*((-b)*x + Mods[a + b*x]))}
{Mods[a + b*x]^n/x^3, x, 2, Mods[a + b*x]^(1 + n)/(2*x^2*(b*x - Mods[a + b*x])) - (b*(-1 + n)*((b*n*Int[Mods[a + b*x]^n/x, x])/((-b)*x + Mods[a + b*x]) - Mods[a + b*x]^(1 + n)/(x*((-b)*x + Mods[a + b*x]))))/(2*(b*x - Mods[a + b*x]))}


(* Integrands of the form x^m*Mods[a+b*x]^n where m and n are integers *)
{Mods[a + b*x], x, 1, Mods[a + b*x]^2/(2*b)}
{Mods[a + b*x]^2, x, 1, Mods[a + b*x]^3/(3*b)}
{Mods[a + b*x]^3, x, 1, Mods[a + b*x]^4/(4*b)}
{Mods[a + b*x]^(-1), x, 1, Log[Mods[a + b*x]]/b}
{Mods[a + b*x]^(-2), x, 1, -(1/(b*Mods[a + b*x]))}
{Mods[a + b*x]^(-3), x, 1, -1/(2*b*Mods[a + b*x]^2)}

{(c + d*x)*Mods[a + b*x], x, 2, -(((c + d*x)^2*(b*(c + d*x) - 3*d*Mods[a + b*x]))/(6*d^2))}
{(c + d*x)*Mods[a + b*x]^2, x, 2, (Mods[a + b*x]^3*(4*b*(c + d*x) - d*Mods[a + b*x]))/(12*b^2)}
{(c + d*x)*Mods[a + b*x]^3, x, 2, (Mods[a + b*x]^4*(5*b*(c + d*x) - d*Mods[a + b*x]))/(20*b^2)}
{(c + d*x)/Mods[a + b*x], x, 2, (b*(c + d*x)*(1 + Log[Mods[a + b*x]]) - d*Log[Mods[a + b*x]]*Mods[a + b*x])/b^2}
{(c + d*x)/Mods[a + b*x]^2, x, 2, (d*Log[Mods[a + b*x]] - (b*(c + d*x))/Mods[a + b*x])/b^2}
{(c + d*x)/Mods[a + b*x]^3, x, 2, -((b*c + b*d*x + d*Mods[a + b*x])/(2*b^2*Mods[a + b*x]^2))}

{(c + d*x)^2*Mods[a + b*x], x, 2, -(((c + d*x)^3*(b*(c + d*x) - 4*d*Mods[a + b*x]))/(12*d^2))}
{(c + d*x)^2*Mods[a + b*x]^2, x, 3, ((c + d*x)^3*(b^2*(c + d*x)^2 - 5*b*d*(c + d*x)*Mods[a + b*x] + 10*d^2*Mods[a + b*x]^2))/(30*d^3)}
{(c + d*x)^2*Mods[a + b*x]^3, x, 3, (Mods[a + b*x]^4*(15*b^2*(c + d*x)^2 - 6*b*d*(c + d*x)*Mods[a + b*x] + d^2*Mods[a + b*x]^2))/(60*b^3)}
{(c + d*x)^2/Mods[a + b*x], x, 3, ((c + d*x)^2 + (2*(b*(c + d*x) - d*Mods[a + b*x])*(b*(c + d*x)*(1 + Log[Mods[a + b*x]]) - d*Log[Mods[a + b*x]]*Mods[a + b*x]))/b^2)/(2*b)}
{(c + d*x)^2/Mods[a + b*x]^2, x, 3, (-((c + d*x)^2/Mods[a + b*x]) + (2*d*(b*(c + d*x)*(1 + Log[Mods[a + b*x]]) - d*Log[Mods[a + b*x]]*Mods[a + b*x]))/b^2)/b}
{(c + d*x)^2/Mods[a + b*x]^3, x, 3, ((2*d*(d*Log[Mods[a + b*x]] - (b*(c + d*x))/Mods[a + b*x]))/b^2 - (c + d*x)^2/Mods[a + b*x]^2)/(2*b)}

{(c + d*x)^3*Mods[a + b*x], x, 2, -(((c + d*x)^4*(b*(c + d*x) - 5*d*Mods[a + b*x]))/(20*d^2))}
{(c + d*x)^3*Mods[a + b*x]^2, x, 3, ((c + d*x)^4*(b^2*(c + d*x)^2 - 6*b*d*(c + d*x)*Mods[a + b*x] + 15*d^2*Mods[a + b*x]^2))/(60*d^3)}
{(c + d*x)^3*Mods[a + b*x]^3, x, 4, -(((c + d*x)^4*(b^3*(c + d*x)^3 - 7*b^2*d*(c + d*x)^2*Mods[a + b*x] + 21*b*d^2*(c + d*x)*Mods[a + b*x]^2 - 35*d^3*Mods[a + b*x]^3))/(140*d^4))}
{(c + d*x)^3/Mods[a + b*x], x, 4, (1/(3*b))*((c + d*x)^3 + (1/(2*b^3))*(3*(b*(c + d*x) - d*Mods[a + b*x])*(b^2*(c + d*x)^2*(3 + 2*Log[Mods[a + b*x]]) - 2*b*d*(c + d*x)*(1 + 2*Log[Mods[a + b*x]])*Mods[a + b*x] + 2*d^2*Log[Mods[a + b*x]]*Mods[a + b*x]^2)))}
{(c + d*x)^3/Mods[a + b*x]^2, x, 4, (-((c + d*x)^3/Mods[a + b*x]) + (3*d*((c + d*x)^2 + (2*(b*(c + d*x) - d*Mods[a + b*x])*(b*(c + d*x)*(1 + Log[Mods[a + b*x]]) - d*Log[Mods[a + b*x]]*Mods[a + b*x]))/b^2))/(2*b))/b}
{(c + d*x)^3/Mods[a + b*x]^3, x, 4, -((1/(2*b^4*Mods[a + b*x]^2))*(b^3*(c + d*x)^3 + 3*b^2*d*(c + d*x)^2*Mods[a + b*x] - 6*b*d^2*(c + d*x)*(1 + Log[Mods[a + b*x]])*Mods[a + b*x]^2 + 6*d^3*Log[Mods[a + b*x]]*Mods[a + b*x]^3))}

{Mods[a + b*x]/(c + d*x), x, 2, (b*d*x - Log[c + d*x]*(b*(c + d*x) - d*Mods[a + b*x]))/d^2}
{Mods[a + b*x]^2/(c + d*x), x, 3, (Mods[a + b*x]^2 - (2*(b*(c + d*x) - d*Mods[a + b*x])*(b*d*x - Log[c + d*x]*(b*(c + d*x) - d*Mods[a + b*x])))/d^2)/(2*d)}
{Mods[a + b*x]^3/(c + d*x), x, 4, (Mods[a + b*x]^3 - (3*(b*(c + d*x) - d*Mods[a + b*x])*(Mods[a + b*x]^2 - (2*(b*(c + d*x) - d*Mods[a + b*x])*(b*d*x - Log[c + d*x]*(b*(c + d*x) - d*Mods[a + b*x])))/d^2))/(2*d))/(3*d)}
{1/((c + d*x)*Mods[a + b*x]), x, 1, (-Log[c + d*x] + Log[Mods[a + b*x]])/(b*(c + d*x) - d*Mods[a + b*x])}
{1/((c + d*x)*Mods[a + b*x]^2), x, 2, ((-b)*(c + d*x) + d*(1 + Log[c + d*x] - Log[Mods[a + b*x]])*Mods[a + b*x])/(Mods[a + b*x]*(b*(c + d*x) - d*Mods[a + b*x])^2)}
{1/((c + d*x)*Mods[a + b*x]^3), x, 3, ((-b^2)*(c + d*x)^2 + 4*b*d*(c + d*x)*Mods[a + b*x] + d^2*(-3 - 2*Log[c + d*x] + 2*Log[Mods[a + b*x]])*Mods[a + b*x]^2)/(2*Mods[a + b*x]^2*(b*(c + d*x) - d*Mods[a + b*x])^3)}

{Mods[a + b*x]/(c + d*x)^2, x, 2, (b*Log[c + d*x] - (d*Mods[a + b*x])/(c + d*x))/d^2}
{Mods[a + b*x]^2/(c + d*x)^2, x, 3, (-(Mods[a + b*x]^2/(c + d*x)) + (2*b*(b*d*x - Log[c + d*x]*(b*(c + d*x) - d*Mods[a + b*x])))/d^2)/d}
{Mods[a + b*x]^3/(c + d*x)^2, x, 4, (-(Mods[a + b*x]^3/(c + d*x)) + (3*b*(Mods[a + b*x]^2 - (2*(b*(c + d*x) - d*Mods[a + b*x])*(b*d*x - Log[c + d*x]*(b*(c + d*x) - d*Mods[a + b*x])))/d^2))/(2*d))/d}
{1/((c + d*x)^2*Mods[a + b*x]), x, 2, -((b*(c + d*x)*(-1 + Log[c + d*x] - Log[Mods[a + b*x]]) + d*Mods[a + b*x])/((c + d*x)*(b*(c + d*x) - d*Mods[a + b*x])^2))}
{1/((c + d*x)^2*Mods[a + b*x]^2), x, 3, ((-b^2)*(c + d*x)^2 + 2*b*d*(c + d*x)*(Log[c + d*x] - Log[Mods[a + b*x]])*Mods[a + b*x] + d^2*Mods[a + b*x]^2)/((c + d*x)*Mods[a + b*x]*(b*(c + d*x) - d*Mods[a + b*x])^3)}
{1/((c + d*x)^2*Mods[a + b*x]^3), x, 4, -((b^3*(c + d*x)^3 - 6*b^2*d*(c + d*x)^2*Mods[a + b*x] + 3*b*d^2*(c + d*x)*(1 + 2*Log[c + d*x] - 2*Log[Mods[a + b*x]])*Mods[a + b*x]^2 + 2*d^3*Mods[a + b*x]^3)/(2*(c + d*x)*Mods[a + b*x]^2*(b*(c + d*x) - d*Mods[a + b*x])^4))}

{Mods[a + b*x]/(c + d*x)^3, x, 2, -((b*(c + d*x) + d*Mods[a + b*x])/(2*d^2*(c + d*x)^2))}
{Mods[a + b*x]^2/(c + d*x)^3, x, 3, -((-2*b^2*(c + d*x)^2*Log[c + d*x] + 2*b*d*(c + d*x)*Mods[a + b*x] + d^2*Mods[a + b*x]^2)/(2*d^3*(c + d*x)^2))}
{Mods[a + b*x]^3/(c + d*x)^3, x, 4, (-(Mods[a + b*x]^3/(c + d*x)^2) + (3*b*(-(Mods[a + b*x]^2/(c + d*x)) + (2*b*(b*d*x - Log[c + d*x]*(b*(c + d*x) - d*Mods[a + b*x])))/d^2))/d)/(2*d)}
{1/((c + d*x)^3*Mods[a + b*x]), x, 3, ((-b^2)*(c + d*x)^2*(-3 + 2*Log[c + d*x] - 2*Log[Mods[a + b*x]]) - 4*b*d*(c + d*x)*Mods[a + b*x] + d^2*Mods[a + b*x]^2)/(2*(c + d*x)^2*(b*(c + d*x) - d*Mods[a + b*x])^3)}
{1/((c + d*x)^3*Mods[a + b*x]^2), x, 4, (-2*b^3*(c + d*x)^3 + 3*b^2*d*(c + d*x)^2*(-1 + 2*Log[c + d*x] - 2*Log[Mods[a + b*x]])*Mods[a + b*x] + 6*b*d^2*(c + d*x)*Mods[a + b*x]^2 - d^3*Mods[a + b*x]^3)/(2*(c + d*x)^2*Mods[a + b*x]*(b*(c + d*x) - d*Mods[a + b*x])^4)}
{1/((c + d*x)^3*Mods[a + b*x]^3), x, 5, ((-b^4)*(c + d*x)^4 + 8*b^3*d*(c + d*x)^3*Mods[a + b*x] - 12*b^2*d^2*(c + d*x)^2*(Log[c + d*x] - Log[Mods[a + b*x]])*Mods[a + b*x]^2 - 8*b*d^3*(c + d*x)*Mods[a + b*x]^3 + d^4*Mods[a + b*x]^4)/(2*(c + d*x)^2*Mods[a + b*x]^2*(b*(c + d*x) - d*Mods[a + b*x])^5)}


(* Integrands of the form x^m*Mods[a+b*x]^n where m is a half-integer and n is an integer *)
{Sqrt[x]*Mods[a + b*x], x, 2, (2*x^(3/2)*(-2*b*x + 5*Mods[a + b*x]))/15}
{Sqrt[x]*Mods[a + b*x]^2, x, 4, (2*x^(3/2)*(8*b^2*x^2 - 28*b*x*Mods[a + b*x] + 35*Mods[a + b*x]^2))/105}
{Sqrt[x]*Mods[a + b*x]^3, x, 5, (-2*x^(3/2)*(16*b^3*x^3 - 72*b^2*x^2*Mods[a + b*x] + 126*b*x*Mods[a + b*x]^2 - 105*Mods[a + b*x]^3))/315}
{Sqrt[x]/Mods[a + b*x], x, 2, (2*Sqrt[x])/b - (2*ArcTan[(Sqrt[b]*Sqrt[x])/Sqrt[-(b*x) + Mods[a + b*x]]]*Sqrt[-(b*x) + Mods[a + b*x]])/b^(3/2)}
{Sqrt[x]/Mods[a + b*x]^2, x, 2, -(Sqrt[x]/(b*Mods[a + b*x])) + ArcTan[(Sqrt[b]*Sqrt[x])/Sqrt[-(b*x) + Mods[a + b*x]]]/(b^(3/2)*Sqrt[-(b*x) + Mods[a + b*x]])}
{Sqrt[x]/Mods[a + b*x]^3, x, 3, ((-2*Sqrt[x])/Mods[a + b*x]^2 + ArcTan[(Sqrt[b]*Sqrt[x])/Sqrt[-(b*x) + Mods[a + b*x]]]/(Sqrt[b]*(-(b*x) + Mods[a + b*x])^(3/2)) + Sqrt[x]/(Mods[a + b*x]*(-(b*x) + Mods[a + b*x])))/(4*b)}

{x^(3/2)*Mods[a + b*x], x, 2, (2*x^(5/2)*(-2*b*x + 7*Mods[a + b*x]))/35}
{x^(3/2)*Mods[a + b*x]^2, x, 5, (2*x^(5/2)*(8*b^2*x^2 - 36*b*x*Mods[a + b*x] + 63*Mods[a + b*x]^2))/315}
{x^(3/2)*Mods[a + b*x]^3, x, 6, (-2*x^(5/2)*(16*b^3*x^3 - 88*b^2*x^2*Mods[a + b*x] + 198*b*x*Mods[a + b*x]^2 - 231*Mods[a + b*x]^3))/1155}
{x^(3/2)/Mods[a + b*x], x, 3, (2*x^(3/2) + (6*(b*x - Mods[a + b*x])*(Sqrt[b]*Sqrt[x] - ArcTan[(Sqrt[b]*Sqrt[x])/Sqrt[-(b*x) + Mods[a + b*x]]]*Sqrt[-(b*x) + Mods[a + b*x]]))/b^(3/2))/(3*b)}
{x^(3/2)/Mods[a + b*x]^2, x, 3, (3*Sqrt[x])/b^2 - x^(3/2)/(b*Mods[a + b*x]) - (3*ArcTan[(Sqrt[b]*Sqrt[x])/Sqrt[-(b*x) + Mods[a + b*x]]]*Sqrt[-(b*x) + Mods[a + b*x]])/b^(5/2)}
{x^(3/2)/Mods[a + b*x]^3, x, 3, -(x^(3/2)/(2*b*Mods[a + b*x]^2)) - (3*Sqrt[x])/(4*b^2*Mods[a + b*x]) - (3*ArcTan[(Sqrt[b]*Sqrt[x])/Sqrt[(-b)*x + Mods[a + b*x]]]*Sqrt[(-b)*x + Mods[a + b*x]])/(b^(5/2)*(4*b*x - 4*Mods[a + b*x]))}

{x^(5/2)*Mods[a + b*x], x, 2, (2*x^(7/2)*(-2*b*x + 9*Mods[a + b*x]))/63}
{x^(5/2)*Mods[a + b*x]^2, x, 3, (2*x^(7/2)*(8*b^2*x^2 - 44*b*x*Mods[a + b*x] + 99*Mods[a + b*x]^2))/693}
{x^(5/2)*Mods[a + b*x]^3, x, 7, (-2*x^(7/2)*(16*b^3*x^3 - 104*b^2*x^2*Mods[a + b*x] + 286*b*x*Mods[a + b*x]^2 - 429*Mods[a + b*x]^3))/3003}
{x^(5/2)/Mods[a + b*x], x, 4, (2*x^(5/2) + (5*(b*x - Mods[a + b*x])*(2*x^(3/2) + (6*(b*x - Mods[a + b*x])*(Sqrt[b]*Sqrt[x] - ArcTan[(Sqrt[b]*Sqrt[x])/Sqrt[-(b*x) + Mods[a + b*x]]]*Sqrt[-(b*x) + Mods[a + b*x]]))/b^(3/2)))/(3*b))/(5*b)}
{x^(5/2)/Mods[a + b*x]^2, x, 4, ((-2*x^(5/2))/Mods[a + b*x] + (5*(2*x^(3/2) + (6*(b*x - Mods[a + b*x])*(Sqrt[b]*Sqrt[x] - ArcTan[(Sqrt[b]*Sqrt[x])/Sqrt[-(b*x) + Mods[a + b*x]]]*Sqrt[-(b*x) + Mods[a + b*x]]))/b^(3/2)))/(3*b))/(2*b)}
{x^(5/2)/Mods[a + b*x]^3, x, 4, (1/4)*((15*Sqrt[x])/b^3 - (2*x^(5/2))/(b*Mods[a + b*x]^2) - (5*x^(3/2))/(b^2*Mods[a + b*x]) - (15*ArcTan[(Sqrt[b]*Sqrt[x])/Sqrt[(-b)*x + Mods[a + b*x]]]*Sqrt[(-b)*x + Mods[a + b*x]])/b^(7/2))}

{Mods[a + b*x]/Sqrt[x], x, 2, (2*Sqrt[x]*(-2*b*x + 3*Mods[a + b*x]))/3}
{Mods[a + b*x]^2/Sqrt[x], x, 3, (2*Sqrt[x]*(8*b^2*x^2 - 20*b*x*Mods[a + b*x] + 15*Mods[a + b*x]^2))/15}
{Mods[a + b*x]^3/Sqrt[x], x, 4, (2*Sqrt[x]*(-16*b^3*x^3 + 56*b^2*x^2*Mods[a + b*x] - 70*b*x*Mods[a + b*x]^2 + 35*Mods[a + b*x]^3))/35}
{1/(Sqrt[x]*Mods[a + b*x]), x, 1, (2*ArcTan[(Sqrt[b]*Sqrt[x])/Sqrt[-(b*x) + Mods[a + b*x]]])/(Sqrt[b]*Sqrt[-(b*x) + Mods[a + b*x]])}
{1/(Sqrt[x]*Mods[a + b*x]^2), x, 2, ArcTan[(Sqrt[b]*Sqrt[x])/Sqrt[-(b*x) + Mods[a + b*x]]]/(Sqrt[b]*(-(b*x) + Mods[a + b*x])^(3/2)) + Sqrt[x]/(Mods[a + b*x]*(-(b*x) + Mods[a + b*x]))}
{1/(Sqrt[x]*Mods[a + b*x]^3), x, 3, ((3*ArcTan[(Sqrt[b]*Sqrt[x])/Sqrt[-(b*x) + Mods[a + b*x]]])/(Sqrt[b]*(-(b*x) + Mods[a + b*x])^(5/2)) - (2*b*x^(3/2))/(Mods[a + b*x]^2*(-(b*x) + Mods[a + b*x])^2) + (5*Sqrt[x])/(Mods[a + b*x]*(-(b*x) + Mods[a + b*x])^2))/4}

{Mods[a + b*x]/x^(3/2), x, 2, (4*b*x - 2*Mods[a + b*x])/Sqrt[x]}
{Mods[a + b*x]^2/x^(3/2), x, 3, (-2*(8*b^2*x^2 - 12*b*x*Mods[a + b*x] + 3*Mods[a + b*x]^2))/(3*Sqrt[x])}
{Mods[a + b*x]^3/x^(3/2), x, 4, (2*(16*b^3*x^3 - 40*b^2*x^2*Mods[a + b*x] + 30*b*x*Mods[a + b*x]^2 - 5*Mods[a + b*x]^3))/(5*Sqrt[x])}
{1/(x^(3/2)*Mods[a + b*x]), x, 2, (2*(1/Sqrt[x] + (Sqrt[b]*ArcTan[(Sqrt[b]*Sqrt[x])/Sqrt[-(b*x) + Mods[a + b*x]]])/Sqrt[-(b*x) + Mods[a + b*x]]))/(b*x - Mods[a + b*x])}
{1/(x^(3/2)*Mods[a + b*x]^2), x, 3, (-3*Sqrt[b]*ArcTan[(Sqrt[b]*Sqrt[x])/Sqrt[-(b*x) + Mods[a + b*x]]])/(-(b*x) + Mods[a + b*x])^(5/2) - 2/(Sqrt[x]*(-(b*x) + Mods[a + b*x])^2) - (b*Sqrt[x])/(Mods[a + b*x]*(-(b*x) + Mods[a + b*x])^2)}
{1/(x^(3/2)*Mods[a + b*x]^3), x, 4, (8/(Sqrt[x]*(b*x - Mods[a + b*x])^3) + (9*b*Sqrt[x])/((b*x - Mods[a + b*x])^3*Mods[a + b*x]) - (15*Sqrt[b]*ArcTan[(Sqrt[b]*Sqrt[x])/Sqrt[-(b*x) + Mods[a + b*x]]])/(-(b*x) + Mods[a + b*x])^(7/2) + (2*b^2*x^(3/2))/(Mods[a + b*x]^2*(-(b*x) + Mods[a + b*x])^3))/4}

{Mods[a + b*x]/x^(5/2), x, 2, (-2*(2*b*x + Mods[a + b*x]))/(3*x^(3/2))}
{Mods[a + b*x]^2/x^(5/2), x, 3, (2*(8*b^2*x^2 - 4*b*x*Mods[a + b*x] - Mods[a + b*x]^2))/(3*x^(3/2))}
{Mods[a + b*x]^3/x^(5/2), x, 4, (-2*(16*b^3*x^3 - 24*b^2*x^2*Mods[a + b*x] + 6*b*x*Mods[a + b*x]^2 + Mods[a + b*x]^3))/(3*x^(3/2))}
{1/(x^(5/2)*Mods[a + b*x]), x, 3, ((8*b)/Sqrt[x] - (2*Mods[a + b*x])/x^(3/2) + (6*b^(3/2)*ArcTan[(Sqrt[b]*Sqrt[x])/Sqrt[-(b*x) + Mods[a + b*x]]])/Sqrt[-(b*x) + Mods[a + b*x]])/(3*(-(b*x) + Mods[a + b*x])^2)}
{1/(x^(5/2)*Mods[a + b*x]^2), x, 4, (2*Mods[a + b*x])/(3*x^(3/2)*(b*x - Mods[a + b*x])^3) + (5*b^(3/2)*ArcTan[(Sqrt[b]*Sqrt[x])/Sqrt[-(b*x) + Mods[a + b*x]]])/(-(b*x) + Mods[a + b*x])^(7/2) + (14*b)/(3*Sqrt[x]*(-(b*x) + Mods[a + b*x])^3) + (b^2*Sqrt[x])/(Mods[a + b*x]*(-(b*x) + Mods[a + b*x])^3)}
{1/(x^(5/2)*Mods[a + b*x]^3), x, 5, ((105*b^(3/2)*ArcTan[(Sqrt[b]*Sqrt[x])/Sqrt[-(b*x) + Mods[a + b*x]]])/(-(b*x) + Mods[a + b*x])^(9/2) + (80*b)/(Sqrt[x]*(-(b*x) + Mods[a + b*x])^4) - (6*b^3*x^(3/2))/(Mods[a + b*x]^2*(-(b*x) + Mods[a + b*x])^4) + (39*b^2*Sqrt[x])/(Mods[a + b*x]*(-(b*x) + Mods[a + b*x])^4) - (8*Mods[a + b*x])/(x^(3/2)*(-(b*x) + Mods[a + b*x])^4))/12}


(* Integrands of the form x^m*Mods[a+b*x]^n where m is an integer and n is a half-integer *)
{Sqrt[Mods[a + b*x]], x, 1, (2*Mods[a + b*x]^(3/2))/(3*b)}
{Mods[a + b*x]^(3/2), x, 1, (2*Mods[a + b*x]^(5/2))/(5*b)}
{Mods[a + b*x]^(5/2), x, 1, (2*Mods[a + b*x]^(7/2))/(7*b)}
{1/Sqrt[Mods[a + b*x]], x, 1, (2*Sqrt[Mods[a + b*x]])/b}
{Mods[a + b*x]^(-3/2), x, 1, -2/(b*Sqrt[Mods[a + b*x]])}
{Mods[a + b*x]^(-5/2), x, 1, -2/(3*b*Mods[a + b*x]^(3/2))}

{x*Sqrt[Mods[a + b*x]], x, 2, (2*(5*b*x - 2*Mods[a + b*x])*Mods[a + b*x]^(3/2))/(15*b^2)}
{x*Mods[a + b*x]^(3/2), x, 2, (2*(7*b*x - 2*Mods[a + b*x])*Mods[a + b*x]^(5/2))/(35*b^2)}
{x*Mods[a + b*x]^(5/2), x, 2, (2*(9*b*x - 2*Mods[a + b*x])*Mods[a + b*x]^(7/2))/(63*b^2)}
{x/Sqrt[Mods[a + b*x]], x, 2, (2*(3*b*x - 2*Mods[a + b*x])*Sqrt[Mods[a + b*x]])/(3*b^2)}
{x/Mods[a + b*x]^(3/2), x, 2, (-2*b*x + 4*Mods[a + b*x])/(b^2*Sqrt[Mods[a + b*x]])}
{x/Mods[a + b*x]^(5/2), x, 2, (-2*(b*x + 2*Mods[a + b*x]))/(3*b^2*Mods[a + b*x]^(3/2))}

{x^2*Sqrt[Mods[a + b*x]], x, 3, (2*Mods[a + b*x]^(3/2)*(35*b^2*x^2 - 28*b*x*Mods[a + b*x] + 8*Mods[a + b*x]^2))/(105*b^3)}
{x^2*Mods[a + b*x]^(3/2), x, 3, (2*Mods[a + b*x]^(5/2)*(63*b^2*x^2 - 36*b*x*Mods[a + b*x] + 8*Mods[a + b*x]^2))/(315*b^3)}
{x^2*Mods[a + b*x]^(5/2), x, 3, (2*Mods[a + b*x]^(7/2)*(99*b^2*x^2 - 44*b*x*Mods[a + b*x] + 8*Mods[a + b*x]^2))/(693*b^3)}
{x^2/Sqrt[Mods[a + b*x]], x, 3, (2*Sqrt[Mods[a + b*x]]*(15*b^2*x^2 - 20*b*x*Mods[a + b*x] + 8*Mods[a + b*x]^2))/(15*b^3)}
{x^2/Mods[a + b*x]^(3/2), x, 3, (-2*(3*b^2*x^2 - 12*b*x*Mods[a + b*x] + 8*Mods[a + b*x]^2))/(3*b^3*Sqrt[Mods[a + b*x]])}
{x^2/Mods[a + b*x]^(5/2), x, 3, (-2*(b^2*x^2 + 4*b*x*Mods[a + b*x] - 8*Mods[a + b*x]^2))/(3*b^3*Mods[a + b*x]^(3/2))}

{x^3*Sqrt[Mods[a + b*x]], x, 4, (2*Mods[a + b*x]^(3/2)*(105*b^3*x^3 - 126*b^2*x^2*Mods[a + b*x] + 72*b*x*Mods[a + b*x]^2 - 16*Mods[a + b*x]^3))/(315*b^4)}
{x^3*Mods[a + b*x]^(3/2), x, 4, (2*Mods[a + b*x]^(5/2)*(231*b^3*x^3 - 198*b^2*x^2*Mods[a + b*x] + 88*b*x*Mods[a + b*x]^2 - 16*Mods[a + b*x]^3))/(1155*b^4)}
{x^3*Mods[a + b*x]^(5/2), x, 4, (2*Mods[a + b*x]^(7/2)*(429*b^3*x^3 - 286*b^2*x^2*Mods[a + b*x] + 104*b*x*Mods[a + b*x]^2 - 16*Mods[a + b*x]^3))/(3003*b^4)}
{x^3/Sqrt[Mods[a + b*x]], x, 4, (2*Sqrt[Mods[a + b*x]]*(35*b^3*x^3 - 70*b^2*x^2*Mods[a + b*x] + 56*b*x*Mods[a + b*x]^2 - 16*Mods[a + b*x]^3))/(35*b^4)}
{x^3/Mods[a + b*x]^(3/2), x, 4, (-2*(5*b^3*x^3 - 30*b^2*x^2*Mods[a + b*x] + 40*b*x*Mods[a + b*x]^2 - 16*Mods[a + b*x]^3))/(5*b^4*Sqrt[Mods[a + b*x]])}
{x^3/Mods[a + b*x]^(5/2), x, 4, (-2*(b^3*x^3 + 6*b^2*x^2*Mods[a + b*x] - 24*b*x*Mods[a + b*x]^2 + 16*Mods[a + b*x]^3))/(3*b^4*Mods[a + b*x]^(3/2))}

{Sqrt[Mods[a + b*x]]/x, x, 2, -2*ArcTan[Sqrt[Mods[a + b*x]]/Sqrt[b*x - Mods[a + b*x]]]*Sqrt[b*x - Mods[a + b*x]] + 2*Sqrt[Mods[a + b*x]]}
{Mods[a + b*x]^(3/2)/x, x, 3, 2*(ArcTan[Sqrt[Mods[a + b*x]]/Sqrt[b*x - Mods[a + b*x]]]*Sqrt[b*x - Mods[a + b*x]] - Sqrt[Mods[a + b*x]])*(b*x - Mods[a + b*x]) + (2*Mods[a + b*x]^(3/2))/3}
{Mods[a + b*x]^(5/2)/x, x, 4, (2*Mods[a + b*x]^(5/2))/5 - (b*x - Mods[a + b*x])*(2*(ArcTan[Sqrt[Mods[a + b*x]]/Sqrt[b*x - Mods[a + b*x]]]*Sqrt[b*x - Mods[a + b*x]] - Sqrt[Mods[a + b*x]])*(b*x - Mods[a + b*x]) + (2*Mods[a + b*x]^(3/2))/3)}
{1/(x*Sqrt[Mods[a + b*x]]), x, 1, (2*ArcTan[Sqrt[Mods[a + b*x]]/Sqrt[b*x - Mods[a + b*x]]])/Sqrt[b*x - Mods[a + b*x]]}
{1/(x*Mods[a + b*x]^(3/2)), x, 2, (-2*ArcTan[Sqrt[Mods[a + b*x]]/Sqrt[b*x - Mods[a + b*x]]])/(b*x - Mods[a + b*x])^(3/2) - 2/((b*x - Mods[a + b*x])*Sqrt[Mods[a + b*x]])}
{1/(x*Mods[a + b*x]^(5/2)), x, 3, (2*ArcTan[Sqrt[Mods[a + b*x]]/Sqrt[b*x - Mods[a + b*x]]])/(b*x - Mods[a + b*x])^(5/2) - (2*b*x)/(3*Mods[a + b*x]^(3/2)*(-(b*x) + Mods[a + b*x])^2) + 8/(3*Sqrt[Mods[a + b*x]]*(-(b*x) + Mods[a + b*x])^2)}

{Sqrt[Mods[a + b*x]]/x^2, x, 2, (b*ArcTan[Sqrt[Mods[a + b*x]]/Sqrt[b*x - Mods[a + b*x]]])/Sqrt[b*x - Mods[a + b*x]] - Sqrt[Mods[a + b*x]]/x}
{Mods[a + b*x]^(3/2)/x^2, x, 3, -3*b*ArcTan[Sqrt[Mods[a + b*x]]/Sqrt[b*x - Mods[a + b*x]]]*Sqrt[b*x - Mods[a + b*x]] + 3*b*Sqrt[Mods[a + b*x]] - Mods[a + b*x]^(3/2)/x}
{Mods[a + b*x]^(5/2)/x^2, x, 4, -(Mods[a + b*x]^(5/2)/x) + (5*b*(2*(ArcTan[Sqrt[Mods[a + b*x]]/Sqrt[b*x - Mods[a + b*x]]]*Sqrt[b*x - Mods[a + b*x]] - Sqrt[Mods[a + b*x]])*(b*x - Mods[a + b*x]) + (2*Mods[a + b*x]^(3/2))/3))/2}
{1/(x^2*Sqrt[Mods[a + b*x]]), x, 2, (b*ArcTan[Sqrt[Mods[a + b*x]]/Sqrt[b*x - Mods[a + b*x]]])/(b*x - Mods[a + b*x])^(3/2) + Sqrt[Mods[a + b*x]]/(b*x^2 - x*Mods[a + b*x])}
{1/(x^2*Mods[a + b*x]^(3/2)), x, 3, (-3*b*ArcTan[Sqrt[Mods[a + b*x]]/Sqrt[b*x - Mods[a + b*x]]])/(b*x - Mods[a + b*x])^(5/2) - (2*b)/(Sqrt[Mods[a + b*x]]*(-(b*x) + Mods[a + b*x])^2) - Sqrt[Mods[a + b*x]]/(x*(-(b*x) + Mods[a + b*x])^2)}
{1/(x^2*Mods[a + b*x]^(5/2)), x, 4, (5*b*ArcTan[Sqrt[Mods[a + b*x]]/Sqrt[b*x - Mods[a + b*x]]])/(b*x - Mods[a + b*x])^(7/2) + (14*b)/(3*(b*x - Mods[a + b*x])^3*Sqrt[Mods[a + b*x]]) + Sqrt[Mods[a + b*x]]/(x*(b*x - Mods[a + b*x])^3) + (2*b^2*x)/(3*Mods[a + b*x]^(3/2)*(-(b*x) + Mods[a + b*x])^3)}

{Sqrt[Mods[a + b*x]]/x^3, x, 3, ((b^2*ArcTan[Sqrt[Mods[a + b*x]]/Sqrt[b*x - Mods[a + b*x]]])/(b*x - Mods[a + b*x])^(3/2) + Sqrt[Mods[a + b*x]]*(-2/x^2 + b/(b*x^2 - x*Mods[a + b*x])))/4}
{Mods[a + b*x]^(3/2)/x^3, x, 3, ((3*b^2*x^2*ArcTan[Sqrt[Mods[a + b*x]]/Sqrt[b*x - Mods[a + b*x]]])/Sqrt[b*x - Mods[a + b*x]] - 3*b*x*Sqrt[Mods[a + b*x]] - 2*Mods[a + b*x]^(3/2))/(4*x^2)}
{Mods[a + b*x]^(5/2)/x^3, x, 4, -(2*Mods[a + b*x]^(5/2) + 5*b*x*(3*b*x*ArcTan[Sqrt[Mods[a + b*x]]/Sqrt[b*x - Mods[a + b*x]]]*Sqrt[b*x - Mods[a + b*x]] - 3*b*x*Sqrt[Mods[a + b*x]] + Mods[a + b*x]^(3/2)))/(4*x^2)}
{1/(x^3*Sqrt[Mods[a + b*x]]), x, 3, ((3*b^2*x^2*ArcTan[Sqrt[Mods[a + b*x]]/Sqrt[b*x - Mods[a + b*x]]])/(b*x - Mods[a + b*x])^(5/2) + (5*b*x*Sqrt[Mods[a + b*x]])/(-(b*x) + Mods[a + b*x])^2 - (2*Mods[a + b*x]^(3/2))/(-(b*x) + Mods[a + b*x])^2)/(4*x^2)}
{1/(x^3*Mods[a + b*x]^(3/2)), x, 4, ((-15*b^2*ArcTan[Sqrt[Mods[a + b*x]]/Sqrt[b*x - Mods[a + b*x]]])/(b*x - Mods[a + b*x])^(7/2) - (9*b*Sqrt[Mods[a + b*x]])/(x*(b*x - Mods[a + b*x])^3) + (2*Mods[a + b*x]^(3/2))/(x^2*(b*x - Mods[a + b*x])^3) + (8*b^2)/(Sqrt[Mods[a + b*x]]*(-(b*x) + Mods[a + b*x])^3))/4}
{1/(x^3*Mods[a + b*x]^(5/2)), x, 5, ((105*b^2*ArcTan[Sqrt[Mods[a + b*x]]/Sqrt[b*x - Mods[a + b*x]]])/(b*x - Mods[a + b*x])^(9/2) - (8*b^3*x)/(Mods[a + b*x]^(3/2)*(-(b*x) + Mods[a + b*x])^4) + (80*b^2)/(Sqrt[Mods[a + b*x]]*(-(b*x) + Mods[a + b*x])^4) + (39*b*Sqrt[Mods[a + b*x]])/(x*(-(b*x) + Mods[a + b*x])^4) - (6*Mods[a + b*x]^(3/2))/(x^2*(-(b*x) + Mods[a + b*x])^4))/12}


(* Integrands of the form x^m*Mods[a+b*x]^n where m and n are half-integers *)
{Sqrt[x]*Sqrt[Mods[a + b*x]], x, 3, ((-((ArcTanh[(Sqrt[b]*Sqrt[x])/Sqrt[Mods[a + b*x]]]*(b*x - Mods[a + b*x]))/Sqrt[b]) + Sqrt[x]*Sqrt[Mods[a + b*x]])*(b*x - Mods[a + b*x]) + 2*Sqrt[x]*Mods[a + b*x]^(3/2))/(4*b)}
{Sqrt[x]*Mods[a + b*x]^(3/2), x, 4, (2*Sqrt[x]*Mods[a + b*x]^(5/2) + (b*x - Mods[a + b*x])*((-3*(-((ArcTanh[(Sqrt[b]*Sqrt[x])/Sqrt[Mods[a + b*x]]]*(b*x - Mods[a + b*x]))/Sqrt[b]) + Sqrt[x]*Sqrt[Mods[a + b*x]])*(b*x - Mods[a + b*x]))/4 + (Sqrt[x]*Mods[a + b*x]^(3/2))/2))/(6*b)}
{Sqrt[x]*Mods[a + b*x]^(5/2), x, 5, (2*Sqrt[x]*Mods[a + b*x]^(7/2) + (b*x - Mods[a + b*x])*((Sqrt[x]*Mods[a + b*x]^(5/2))/3 - (5*(b*x - Mods[a + b*x])*((-3*(-((ArcTanh[(Sqrt[b]*Sqrt[x])/Sqrt[Mods[a + b*x]]]*(b*x - Mods[a + b*x]))/Sqrt[b]) + Sqrt[x]*Sqrt[Mods[a + b*x]])*(b*x - Mods[a + b*x]))/4 + (Sqrt[x]*Mods[a + b*x]^(3/2))/2))/6))/(8*b)}
{Sqrt[x]/Sqrt[Mods[a + b*x]], x, 2, (ArcTanh[(Sqrt[b]*Sqrt[x])/Sqrt[Mods[a + b*x]]]*(b*x - Mods[a + b*x]))/b^(3/2) + (Sqrt[x]*Sqrt[Mods[a + b*x]])/b}
{Sqrt[x]/Mods[a + b*x]^(3/2), x, 2, (2*ArcTanh[(Sqrt[b]*Sqrt[x])/Sqrt[Mods[a + b*x]]])/b^(3/2) - (2*Sqrt[x])/(b*Sqrt[Mods[a + b*x]])}
{Sqrt[x]/Mods[a + b*x]^(5/2), x, 1, (2*x^(3/2))/(3*Mods[a + b*x]^(3/2)*(-(b*x) + Mods[a + b*x]))}

{x^(3/2)*Sqrt[Mods[a + b*x]], x, 4, (2*x^(3/2)*Mods[a + b*x]^(3/2) + (3*(b*x - Mods[a + b*x])*((-((ArcTanh[(Sqrt[b]*Sqrt[x])/Sqrt[Mods[a + b*x]]]*(b*x - Mods[a + b*x]))/Sqrt[b]) + Sqrt[x]*Sqrt[Mods[a + b*x]])*(b*x - Mods[a + b*x]) + 2*Sqrt[x]*Mods[a + b*x]^(3/2)))/(4*b))/(6*b)}
{x^(3/2)*Mods[a + b*x]^(3/2), x, 5, (2*x^(3/2)*Mods[a + b*x]^(5/2) + ((b*x - Mods[a + b*x])*(2*Sqrt[x]*Mods[a + b*x]^(5/2) + (b*x - Mods[a + b*x])*((-3*(-((ArcTanh[(Sqrt[b]*Sqrt[x])/Sqrt[Mods[a + b*x]]]*(b*x - Mods[a + b*x]))/Sqrt[b]) + Sqrt[x]*Sqrt[Mods[a + b*x]])*(b*x - Mods[a + b*x]))/4 + (Sqrt[x]*Mods[a + b*x]^(3/2))/2)))/(2*b))/(8*b)}
{x^(3/2)*Mods[a + b*x]^(5/2), x, 6, (2*x^(3/2)*Mods[a + b*x]^(7/2) + (3*(b*x - Mods[a + b*x])*(2*Sqrt[x]*Mods[a + b*x]^(7/2) + (b*x - Mods[a + b*x])*((Sqrt[x]*Mods[a + b*x]^(5/2))/3 - (5*(b*x - Mods[a + b*x])*((-3*(-((ArcTanh[(Sqrt[b]*Sqrt[x])/Sqrt[Mods[a + b*x]]]*(b*x - Mods[a + b*x]))/Sqrt[b]) + Sqrt[x]*Sqrt[Mods[a + b*x]])*(b*x - Mods[a + b*x]))/4 + (Sqrt[x]*Mods[a + b*x]^(3/2))/2))/6)))/(8*b))/(10*b)}
{x^(3/2)/Sqrt[Mods[a + b*x]], x, 3, (3*((ArcTanh[(Sqrt[b]*Sqrt[x])/Sqrt[Mods[a + b*x]]]*(b*x - Mods[a + b*x]))/b^(3/2) + (Sqrt[x]*Sqrt[Mods[a + b*x]])/b)*(b*x - Mods[a + b*x]) + 2*x^(3/2)*Sqrt[Mods[a + b*x]])/(4*b)}
{x^(3/2)/Mods[a + b*x]^(3/2), x, 3, (3*((ArcTanh[(Sqrt[b]*Sqrt[x])/Sqrt[Mods[a + b*x]]]*(b*x - Mods[a + b*x]))/b^(3/2) + (Sqrt[x]*Sqrt[Mods[a + b*x]])/b) - (2*x^(3/2))/Sqrt[Mods[a + b*x]])/b}
{x^(3/2)/Mods[a + b*x]^(5/2), x, 3, (2*ArcTanh[(Sqrt[b]*Sqrt[x])/Sqrt[Mods[a + b*x]]])/b^(5/2) - (2*x^(3/2))/(3*b*Mods[a + b*x]^(3/2)) - (2*Sqrt[x])/(b^2*Sqrt[Mods[a + b*x]])}

{x^(5/2)*Sqrt[Mods[a + b*x]], x, 5, (2*x^(5/2)*Mods[a + b*x]^(3/2) + (5*(b*x - Mods[a + b*x])*(2*x^(3/2)*Mods[a + b*x]^(3/2) + (3*(b*x - Mods[a + b*x])*((-((ArcTanh[(Sqrt[b]*Sqrt[x])/Sqrt[Mods[a + b*x]]]*(b*x - Mods[a + b*x]))/Sqrt[b]) + Sqrt[x]*Sqrt[Mods[a + b*x]])*(b*x - Mods[a + b*x]) + 2*Sqrt[x]*Mods[a + b*x]^(3/2)))/(4*b)))/(6*b))/(8*b)}
{x^(5/2)*Mods[a + b*x]^(3/2), x, 6, (2*x^(5/2)*Mods[a + b*x]^(5/2) + (5*(b*x - Mods[a + b*x])*(2*x^(3/2)*Mods[a + b*x]^(5/2) + ((b*x - Mods[a + b*x])*(2*Sqrt[x]*Mods[a + b*x]^(5/2) + (b*x - Mods[a + b*x])*((-3*(-((ArcTanh[(Sqrt[b]*Sqrt[x])/Sqrt[Mods[a + b*x]]]*(b*x - Mods[a + b*x]))/Sqrt[b]) + Sqrt[x]*Sqrt[Mods[a + b*x]])*(b*x - Mods[a + b*x]))/4 + (Sqrt[x]*Mods[a + b*x]^(3/2))/2)))/(2*b)))/(8*b))/(10*b)}
{x^(5/2)*Mods[a + b*x]^(5/2), x, 7, (2*x^(5/2)*Mods[a + b*x]^(7/2) + ((b*x - Mods[a + b*x])*(2*x^(3/2)*Mods[a + b*x]^(7/2) + (3*(b*x - Mods[a + b*x])*(2*Sqrt[x]*Mods[a + b*x]^(7/2) + (b*x - Mods[a + b*x])*((Sqrt[x]*Mods[a + b*x]^(5/2))/3 - (5*(b*x - Mods[a + b*x])*((-3*(-((ArcTanh[(Sqrt[b]*Sqrt[x])/Sqrt[Mods[a + b*x]]]*(b*x - Mods[a + b*x]))/Sqrt[b]) + Sqrt[x]*Sqrt[Mods[a + b*x]])*(b*x - Mods[a + b*x]))/4 + (Sqrt[x]*Mods[a + b*x]^(3/2))/2))/6)))/(8*b)))/(2*b))/(12*b)}
{x^(5/2)/Sqrt[Mods[a + b*x]], x, 4, ((5*(3*((ArcTanh[(Sqrt[b]*Sqrt[x])/Sqrt[Mods[a + b*x]]]*(b*x - Mods[a + b*x]))/b^(3/2) + (Sqrt[x]*Sqrt[Mods[a + b*x]])/b)*(b*x - Mods[a + b*x]) + 2*x^(3/2)*Sqrt[Mods[a + b*x]])*(b*x - Mods[a + b*x]))/(4*b) + 2*x^(5/2)*Sqrt[Mods[a + b*x]])/(6*b)}
{x^(5/2)/Mods[a + b*x]^(3/2), x, 4, ((5*(3*((ArcTanh[(Sqrt[b]*Sqrt[x])/Sqrt[Mods[a + b*x]]]*(b*x - Mods[a + b*x]))/b^(3/2) + (Sqrt[x]*Sqrt[Mods[a + b*x]])/b)*(b*x - Mods[a + b*x]) + 2*x^(3/2)*Sqrt[Mods[a + b*x]]))/(4*b) - (2*x^(5/2))/Sqrt[Mods[a + b*x]])/b}
{x^(5/2)/Mods[a + b*x]^(5/2), x, 4, ((5*(3*((ArcTanh[(Sqrt[b]*Sqrt[x])/Sqrt[Mods[a + b*x]]]*(b*x - Mods[a + b*x]))/b^(3/2) + (Sqrt[x]*Sqrt[Mods[a + b*x]])/b) - (2*x^(3/2))/Sqrt[Mods[a + b*x]]))/b - (2*x^(5/2))/Mods[a + b*x]^(3/2))/(3*b)}

{Sqrt[Mods[a + b*x]]/Sqrt[x], x, 2, -((ArcTanh[(Sqrt[b]*Sqrt[x])/Sqrt[Mods[a + b*x]]]*(b*x - Mods[a + b*x]))/Sqrt[b]) + Sqrt[x]*Sqrt[Mods[a + b*x]]}
{Mods[a + b*x]^(3/2)/Sqrt[x], x, 3, (-3*(-((ArcTanh[(Sqrt[b]*Sqrt[x])/Sqrt[Mods[a + b*x]]]*(b*x - Mods[a + b*x]))/Sqrt[b]) + Sqrt[x]*Sqrt[Mods[a + b*x]])*(b*x - Mods[a + b*x]))/4 + (Sqrt[x]*Mods[a + b*x]^(3/2))/2}
{Mods[a + b*x]^(5/2)/Sqrt[x], x, 4, (Sqrt[x]*Mods[a + b*x]^(5/2))/3 - (5*(b*x - Mods[a + b*x])*((-3*(-((ArcTanh[(Sqrt[b]*Sqrt[x])/Sqrt[Mods[a + b*x]]]*(b*x - Mods[a + b*x]))/Sqrt[b]) + Sqrt[x]*Sqrt[Mods[a + b*x]])*(b*x - Mods[a + b*x]))/4 + (Sqrt[x]*Mods[a + b*x]^(3/2))/2))/6}
{1/(Sqrt[x]*Sqrt[Mods[a + b*x]]), x, 1, (2*ArcTanh[(Sqrt[b]*Sqrt[x])/Sqrt[Mods[a + b*x]]])/Sqrt[b]}
{1/(Sqrt[x]*Mods[a + b*x]^(3/2)), x, 1, (-2*Sqrt[x])/((b*x - Mods[a + b*x])*Sqrt[Mods[a + b*x]])}
{1/(Sqrt[x]*Mods[a + b*x]^(5/2)), x, 2, (-2*Sqrt[x]*(b*x - 3*Mods[a + b*x]))/(3*Mods[a + b*x]^(3/2)*(-(b*x) + Mods[a + b*x])^2)}

{Sqrt[Mods[a + b*x]]/x^(3/2), x, 2, 2*Sqrt[b]*ArcTanh[(Sqrt[b]*Sqrt[x])/Sqrt[Mods[a + b*x]]] - (2*Sqrt[Mods[a + b*x]])/Sqrt[x]}
{Mods[a + b*x]^(3/2)/x^(3/2), x, 3, 3*b*(-((ArcTanh[(Sqrt[b]*Sqrt[x])/Sqrt[Mods[a + b*x]]]*(b*x - Mods[a + b*x]))/Sqrt[b]) + Sqrt[x]*Sqrt[Mods[a + b*x]]) - (2*Mods[a + b*x]^(3/2))/Sqrt[x]}
{Mods[a + b*x]^(5/2)/x^(3/2), x, 4, (-2*Mods[a + b*x]^(5/2))/Sqrt[x] + 5*b*((-3*(-((ArcTanh[(Sqrt[b]*Sqrt[x])/Sqrt[Mods[a + b*x]]]*(b*x - Mods[a + b*x]))/Sqrt[b]) + Sqrt[x]*Sqrt[Mods[a + b*x]])*(b*x - Mods[a + b*x]))/4 + (Sqrt[x]*Mods[a + b*x]^(3/2))/2)}
{1/(x^(3/2)*Sqrt[Mods[a + b*x]]), x, 1, (2*Sqrt[Mods[a + b*x]])/(Sqrt[x]*(b*x - Mods[a + b*x]))}
{1/(x^(3/2)*Mods[a + b*x]^(3/2)), x, 2, (-2*(b*x + Mods[a + b*x]))/(Sqrt[x]*Sqrt[Mods[a + b*x]]*(-(b*x) + Mods[a + b*x])^2)}
{1/(x^(3/2)*Mods[a + b*x]^(5/2)), x, 3, (-2*(b^2*x^2 - 6*b*x*Mods[a + b*x] - 3*Mods[a + b*x]^2))/(3*Sqrt[x]*(b*x - Mods[a + b*x])^3*Mods[a + b*x]^(3/2))}

{Sqrt[Mods[a + b*x]]/x^(5/2), x, 1, (2*Mods[a + b*x]^(3/2))/(x^(3/2)*(3*b*x - 3*Mods[a + b*x]))}
{Mods[a + b*x]^(3/2)/x^(5/2), x, 3, 2*b^(3/2)*ArcTanh[(Sqrt[b]*Sqrt[x])/Sqrt[Mods[a + b*x]]] - (2*b*Sqrt[Mods[a + b*x]])/Sqrt[x] - (2*Mods[a + b*x]^(3/2))/(3*x^(3/2))}
{Mods[a + b*x]^(5/2)/x^(5/2), x, 4, (-2*Mods[a + b*x]^(5/2))/(3*x^(3/2)) + (5*b*(3*b*(-((ArcTanh[(Sqrt[b]*Sqrt[x])/Sqrt[Mods[a + b*x]]]*(b*x - Mods[a + b*x]))/Sqrt[b]) + Sqrt[x]*Sqrt[Mods[a + b*x]]) - (2*Mods[a + b*x]^(3/2))/Sqrt[x]))/3}
{1/(x^(5/2)*Sqrt[Mods[a + b*x]]), x, 2, (-2*Sqrt[Mods[a + b*x]]*(-3*b*x + Mods[a + b*x]))/(3*x^(3/2)*(-(b*x) + Mods[a + b*x])^2)}
{1/(x^(5/2)*Mods[a + b*x]^(3/2)), x, 3, (2*(-3*b^2*x^2 - 6*b*x*Mods[a + b*x] + Mods[a + b*x]^2))/(3*x^(3/2)*(b*x - Mods[a + b*x])^3*Sqrt[Mods[a + b*x]])}
{1/(x^(5/2)*Mods[a + b*x]^(5/2)), x, 4, (-2*(b^3*x^3 - 9*b^2*x^2*Mods[a + b*x] - 9*b*x*Mods[a + b*x]^2 + Mods[a + b*x]^3))/(3*x^(3/2)*Mods[a + b*x]^(3/2)*(-(b*x) + Mods[a + b*x])^4)}


(* Integrands of the form x^m*Mods[a-b*x]^n where m and n are half-integers *)
{Sqrt[x]*Sqrt[Mods[a - b*x]], x, 3, -(2*Sqrt[x]*Mods[a - b*x]^(3/2) + (-(b*x) - Mods[a - b*x])*(Sqrt[x]*Sqrt[Mods[a - b*x]] - (ArcTan[Sqrt[Mods[a - b*x]]/(Sqrt[b]*Sqrt[x])]*(b*x + Mods[a - b*x]))/Sqrt[b]))/(4*b)}
{Sqrt[x]*Mods[a - b*x]^(3/2), x, 4, -(2*Sqrt[x]*Mods[a - b*x]^(5/2) + (-(b*x) - Mods[a - b*x])*((Sqrt[x]*Mods[a - b*x]^(3/2))/2 - (3*(-(b*x) - Mods[a - b*x])*(Sqrt[x]*Sqrt[Mods[a - b*x]] - (ArcTan[Sqrt[Mods[a - b*x]]/(Sqrt[b]*Sqrt[x])]*(b*x + Mods[a - b*x]))/Sqrt[b]))/4))/(6*b)}
{Sqrt[x]*Mods[a - b*x]^(5/2), x, 5, -(2*Sqrt[x]*Mods[a - b*x]^(7/2) + (-(b*x) - Mods[a - b*x])*((Sqrt[x]*Mods[a - b*x]^(5/2))/3 - (5*(-(b*x) - Mods[a - b*x])*((Sqrt[x]*Mods[a - b*x]^(3/2))/2 - (3*(-(b*x) - Mods[a - b*x])*(Sqrt[x]*Sqrt[Mods[a - b*x]] - (ArcTan[Sqrt[Mods[a - b*x]]/(Sqrt[b]*Sqrt[x])]*(b*x + Mods[a - b*x]))/Sqrt[b]))/4))/6))/(8*b)}
{Sqrt[x]/Sqrt[Mods[a - b*x]], x, 2, -((Sqrt[x]*Sqrt[Mods[a - b*x]])/b) - (ArcTan[Sqrt[Mods[a - b*x]]/(Sqrt[b]*Sqrt[x])]*(b*x + Mods[a - b*x]))/b^(3/2)}
{Sqrt[x]/Mods[a - b*x]^(3/2), x, 2, (2*ArcTan[Sqrt[Mods[a - b*x]]/(Sqrt[b]*Sqrt[x])])/b^(3/2) + (2*Sqrt[x])/(b*Sqrt[Mods[a - b*x]])}
{Sqrt[x]/Mods[a - b*x]^(5/2), x, 1, (2*x^(3/2))/(3*Mods[a - b*x]^(3/2)*(b*x + Mods[a - b*x]))}

{x^(3/2)*Sqrt[Mods[a - b*x]], x, 4, (-2*x^(3/2)*Mods[a - b*x]^(3/2) + (3*(-(b*x) - Mods[a - b*x])*(2*Sqrt[x]*Mods[a - b*x]^(3/2) + (-(b*x) - Mods[a - b*x])*(Sqrt[x]*Sqrt[Mods[a - b*x]] - (ArcTan[Sqrt[Mods[a - b*x]]/(Sqrt[b]*Sqrt[x])]*(b*x + Mods[a - b*x]))/Sqrt[b])))/(4*b))/(6*b)}
{x^(3/2)*Mods[a - b*x]^(3/2), x, 5, (-2*x^(3/2)*Mods[a - b*x]^(5/2) + ((-(b*x) - Mods[a - b*x])*(2*Sqrt[x]*Mods[a - b*x]^(5/2) + (-(b*x) - Mods[a - b*x])*((Sqrt[x]*Mods[a - b*x]^(3/2))/2 - (3*(-(b*x) - Mods[a - b*x])*(Sqrt[x]*Sqrt[Mods[a - b*x]] - (ArcTan[Sqrt[Mods[a - b*x]]/(Sqrt[b]*Sqrt[x])]*(b*x + Mods[a - b*x]))/Sqrt[b]))/4)))/(2*b))/(8*b)}
{x^(3/2)*Mods[a - b*x]^(5/2), x, 6, (-2*x^(3/2)*Mods[a - b*x]^(7/2) + (3*(-(b*x) - Mods[a - b*x])*(2*Sqrt[x]*Mods[a - b*x]^(7/2) + (-(b*x) - Mods[a - b*x])*((Sqrt[x]*Mods[a - b*x]^(5/2))/3 - (5*(-(b*x) - Mods[a - b*x])*((Sqrt[x]*Mods[a - b*x]^(3/2))/2 - (3*(-(b*x) - Mods[a - b*x])*(Sqrt[x]*Sqrt[Mods[a - b*x]] - (ArcTan[Sqrt[Mods[a - b*x]]/(Sqrt[b]*Sqrt[x])]*(b*x + Mods[a - b*x]))/Sqrt[b]))/4))/6)))/(8*b))/(10*b)}
{x^(3/2)/Sqrt[Mods[a - b*x]], x, 3, -(2*x^(3/2)*Sqrt[Mods[a - b*x]] + 3*(-(b*x) - Mods[a - b*x])*(-((Sqrt[x]*Sqrt[Mods[a - b*x]])/b) - (ArcTan[Sqrt[Mods[a - b*x]]/(Sqrt[b]*Sqrt[x])]*(b*x + Mods[a - b*x]))/b^(3/2)))/(4*b)}
{x^(3/2)/Mods[a - b*x]^(3/2), x, 3, ((2*x^(3/2))/Sqrt[Mods[a - b*x]] - 3*(-((Sqrt[x]*Sqrt[Mods[a - b*x]])/b) - (ArcTan[Sqrt[Mods[a - b*x]]/(Sqrt[b]*Sqrt[x])]*(b*x + Mods[a - b*x]))/b^(3/2)))/b}
{x^(3/2)/Mods[a - b*x]^(5/2), x, 3, (-2*ArcTan[Sqrt[Mods[a - b*x]]/(Sqrt[b]*Sqrt[x])])/b^(5/2) + (2*x^(3/2))/(3*b*Mods[a - b*x]^(3/2)) - (2*Sqrt[x])/(b^2*Sqrt[Mods[a - b*x]])}

{x^(5/2)*Sqrt[Mods[a - b*x]], x, 5, -(2*x^(5/2)*Mods[a - b*x]^(3/2) + (5*(-(b*x) - Mods[a - b*x])*(-2*x^(3/2)*Mods[a - b*x]^(3/2) + (3*(-(b*x) - Mods[a - b*x])*(2*Sqrt[x]*Mods[a - b*x]^(3/2) + (-(b*x) - Mods[a - b*x])*(Sqrt[x]*Sqrt[Mods[a - b*x]] - (ArcTan[Sqrt[Mods[a - b*x]]/(Sqrt[b]*Sqrt[x])]*(b*x + Mods[a - b*x]))/Sqrt[b])))/(4*b)))/(6*b))/(8*b)}
{x^(5/2)*Mods[a - b*x]^(3/2), x, 6, -(2*x^(5/2)*Mods[a - b*x]^(5/2) + (5*(-(b*x) - Mods[a - b*x])*(-2*x^(3/2)*Mods[a - b*x]^(5/2) + ((-(b*x) - Mods[a - b*x])*(2*Sqrt[x]*Mods[a - b*x]^(5/2) + (-(b*x) - Mods[a - b*x])*((Sqrt[x]*Mods[a - b*x]^(3/2))/2 - (3*(-(b*x) - Mods[a - b*x])*(Sqrt[x]*Sqrt[Mods[a - b*x]] - (ArcTan[Sqrt[Mods[a - b*x]]/(Sqrt[b]*Sqrt[x])]*(b*x + Mods[a - b*x]))/Sqrt[b]))/4)))/(2*b)))/(8*b))/(10*b)}
{x^(5/2)*Mods[a - b*x]^(5/2), x, 7, -(2*x^(5/2)*Mods[a - b*x]^(7/2) + ((-(b*x) - Mods[a - b*x])*(-2*x^(3/2)*Mods[a - b*x]^(7/2) + (3*(-(b*x) - Mods[a - b*x])*(2*Sqrt[x]*Mods[a - b*x]^(7/2) + (-(b*x) - Mods[a - b*x])*((Sqrt[x]*Mods[a - b*x]^(5/2))/3 - (5*(-(b*x) - Mods[a - b*x])*((Sqrt[x]*Mods[a - b*x]^(3/2))/2 - (3*(-(b*x) - Mods[a - b*x])*(Sqrt[x]*Sqrt[Mods[a - b*x]] - (ArcTan[Sqrt[Mods[a - b*x]]/(Sqrt[b]*Sqrt[x])]*(b*x + Mods[a - b*x]))/Sqrt[b]))/4))/6)))/(8*b)))/(2*b))/(12*b)}
{x^(5/2)/Sqrt[Mods[a - b*x]], x, 4, (-2*x^(5/2)*Sqrt[Mods[a - b*x]] + (5*(-(b*x) - Mods[a - b*x])*(2*x^(3/2)*Sqrt[Mods[a - b*x]] + 3*(-(b*x) - Mods[a - b*x])*(-((Sqrt[x]*Sqrt[Mods[a - b*x]])/b) - (ArcTan[Sqrt[Mods[a - b*x]]/(Sqrt[b]*Sqrt[x])]*(b*x + Mods[a - b*x]))/b^(3/2))))/(4*b))/(6*b)}
{x^(5/2)/Mods[a - b*x]^(3/2), x, 4, ((2*x^(5/2))/Sqrt[Mods[a - b*x]] + (5*(2*x^(3/2)*Sqrt[Mods[a - b*x]] + 3*(-(b*x) - Mods[a - b*x])*(-((Sqrt[x]*Sqrt[Mods[a - b*x]])/b) - (ArcTan[Sqrt[Mods[a - b*x]]/(Sqrt[b]*Sqrt[x])]*(b*x + Mods[a - b*x]))/b^(3/2))))/(4*b))/b}
{x^(5/2)/Mods[a - b*x]^(5/2), x, 4, ((2*x^(5/2))/Mods[a - b*x]^(3/2) - (5*((2*x^(3/2))/Sqrt[Mods[a - b*x]] - 3*(-((Sqrt[x]*Sqrt[Mods[a - b*x]])/b) - (ArcTan[Sqrt[Mods[a - b*x]]/(Sqrt[b]*Sqrt[x])]*(b*x + Mods[a - b*x]))/b^(3/2))))/b)/(3*b)}

{Sqrt[Mods[a - b*x]]/Sqrt[x], x, 2, Sqrt[x]*Sqrt[Mods[a - b*x]] - (ArcTan[Sqrt[Mods[a - b*x]]/(Sqrt[b]*Sqrt[x])]*(b*x + Mods[a - b*x]))/Sqrt[b]}
{Mods[a - b*x]^(3/2)/Sqrt[x], x, 3, (Sqrt[x]*Mods[a - b*x]^(3/2))/2 - (3*(-(b*x) - Mods[a - b*x])*(Sqrt[x]*Sqrt[Mods[a - b*x]] - (ArcTan[Sqrt[Mods[a - b*x]]/(Sqrt[b]*Sqrt[x])]*(b*x + Mods[a - b*x]))/Sqrt[b]))/4}
{Mods[a - b*x]^(5/2)/Sqrt[x], x, 4, (Sqrt[x]*Mods[a - b*x]^(5/2))/3 - (5*(-(b*x) - Mods[a - b*x])*((Sqrt[x]*Mods[a - b*x]^(3/2))/2 - (3*(-(b*x) - Mods[a - b*x])*(Sqrt[x]*Sqrt[Mods[a - b*x]] - (ArcTan[Sqrt[Mods[a - b*x]]/(Sqrt[b]*Sqrt[x])]*(b*x + Mods[a - b*x]))/Sqrt[b]))/4))/6}
{1/(Sqrt[x]*Sqrt[Mods[a - b*x]]), x, 1, (-2*ArcTan[Sqrt[Mods[a - b*x]]/(Sqrt[b]*Sqrt[x])])/Sqrt[b]}
{1/(Sqrt[x]*Mods[a - b*x]^(3/2)), x, 1, (2*Sqrt[x])/(Sqrt[Mods[a - b*x]]*(b*x + Mods[a - b*x]))}
{1/(Sqrt[x]*Mods[a - b*x]^(5/2)), x, 2, (2*Sqrt[x]*(b*x + 3*Mods[a - b*x]))/(3*Mods[a - b*x]^(3/2)*(b*x + Mods[a - b*x])^2)}

{Sqrt[Mods[a - b*x]]/x^(3/2), x, 2, 2*Sqrt[b]*ArcTan[Sqrt[Mods[a - b*x]]/(Sqrt[b]*Sqrt[x])] - (2*Sqrt[Mods[a - b*x]])/Sqrt[x]}
{Mods[a - b*x]^(3/2)/x^(3/2), x, 3, (-2*Mods[a - b*x]^(3/2))/Sqrt[x] - 3*b*(Sqrt[x]*Sqrt[Mods[a - b*x]] - (ArcTan[Sqrt[Mods[a - b*x]]/(Sqrt[b]*Sqrt[x])]*(b*x + Mods[a - b*x]))/Sqrt[b])}
{Mods[a - b*x]^(5/2)/x^(3/2), x, 4, (-2*Mods[a - b*x]^(5/2))/Sqrt[x] - 5*b*((Sqrt[x]*Mods[a - b*x]^(3/2))/2 - (3*(-(b*x) - Mods[a - b*x])*(Sqrt[x]*Sqrt[Mods[a - b*x]] - (ArcTan[Sqrt[Mods[a - b*x]]/(Sqrt[b]*Sqrt[x])]*(b*x + Mods[a - b*x]))/Sqrt[b]))/4)}
{1/(x^(3/2)*Sqrt[Mods[a - b*x]]), x, 1, (-2*Sqrt[Mods[a - b*x]])/(Sqrt[x]*(b*x + Mods[a - b*x]))}
{1/(x^(3/2)*Mods[a - b*x]^(3/2)), x, 2, (2*(b*x - Mods[a - b*x]))/(Sqrt[x]*Sqrt[Mods[a - b*x]]*(b*x + Mods[a - b*x])^2)}
{1/(x^(3/2)*Mods[a - b*x]^(5/2)), x, 3, (2*(b^2*x^2 + 6*b*x*Mods[a - b*x] - 3*Mods[a - b*x]^2))/(3*Sqrt[x]*Mods[a - b*x]^(3/2)*(b*x + Mods[a - b*x])^3)}

{Sqrt[Mods[a - b*x]]/x^(5/2), x, 1, (-2*Mods[a - b*x]^(3/2))/(3*x^(3/2)*(b*x + Mods[a - b*x]))}
{Mods[a - b*x]^(3/2)/x^(5/2), x, 3, (-2*(3*b^(3/2)*x^(3/2)*ArcTan[Sqrt[Mods[a - b*x]]/(Sqrt[b]*Sqrt[x])] - 3*b*x*Sqrt[Mods[a - b*x]] + Mods[a - b*x]^(3/2)))/(3*x^(3/2))}
{Mods[a - b*x]^(5/2)/x^(5/2), x, 4, (-2*Mods[a - b*x]^(5/2))/(3*x^(3/2)) - (5*b*((-2*Mods[a - b*x]^(3/2))/Sqrt[x] - 3*b*(Sqrt[x]*Sqrt[Mods[a - b*x]] - (ArcTan[Sqrt[Mods[a - b*x]]/(Sqrt[b]*Sqrt[x])]*(b*x + Mods[a - b*x]))/Sqrt[b])))/3}
{1/(x^(5/2)*Sqrt[Mods[a - b*x]]), x, 2, (-2*Sqrt[Mods[a - b*x]]*(3*b*x + Mods[a - b*x]))/(3*x^(3/2)*(b*x + Mods[a - b*x])^2)}
{1/(x^(5/2)*Mods[a - b*x]^(3/2)), x, 3, (2*(3*b^2*x^2 - 6*b*x*Mods[a - b*x] - Mods[a - b*x]^2))/(3*x^(3/2)*Sqrt[Mods[a - b*x]]*(b*x + Mods[a - b*x])^3)}
{1/(x^(5/2)*Mods[a - b*x]^(5/2)), x, 4, (2*(b^3*x^3 + 9*b^2*x^2*Mods[a - b*x] - 9*b*x*Mods[a - b*x]^2 - Mods[a - b*x]^3))/(3*x^(3/2)*Mods[a - b*x]^(3/2)*(b*x + Mods[a - b*x])^4)}


(* Integrands of the form x^m*Mods[a+b*x^2]^n where m and n are integers *)
{Mods[a + b*x^2], x, 2, (-2*b*x^3)/3 + x*Mods[a + b*x^2]}
{Mods[a + b*x^2]^2, x, 3, (8*b^2*x^5)/15 - (4*b*x^3*Mods[a + b*x^2])/3 + x*Mods[a + b*x^2]^2}
{Mods[a + b*x^2]^3, x, 4, (-16*b^3*x^7)/35 + (8*b^2*x^5*Mods[a + b*x^2])/5 - 2*b*x^3*Mods[a + b*x^2]^2 + x*Mods[a + b*x^2]^3}
{Mods[a + b*x^2]^(-1), x, 1, ArcTan[(Sqrt[b]*x)/Sqrt[-(b*x^2) + Mods[a + b*x^2]]]/(Sqrt[b]*Sqrt[-(b*x^2) + Mods[a + b*x^2]])}
{Mods[a + b*x^2]^(-2), x, 2, (ArcTan[(Sqrt[b]*x)/Sqrt[-(b*x^2) + Mods[a + b*x^2]]]/(Sqrt[b]*(-(b*x^2) + Mods[a + b*x^2])^(3/2)) + x/(Mods[a + b*x^2]*(-(b*x^2) + Mods[a + b*x^2])))/2}
{Mods[a + b*x^2]^(-3), x, 3, ((3*ArcTan[(Sqrt[b]*x)/Sqrt[-(b*x^2) + Mods[a + b*x^2]]])/(Sqrt[b]*(-(b*x^2) + Mods[a + b*x^2])^(5/2)) - (2*b*x^3)/(Mods[a + b*x^2]^2*(-(b*x^2) + Mods[a + b*x^2])^2) + (5*x)/(Mods[a + b*x^2]*(-(b*x^2) + Mods[a + b*x^2])^2))/8}

{x*Mods[a + b*x^2], x, 1, Mods[a + b*x^2]^2/(4*b)}
{x*Mods[a + b*x^2]^2, x, 1, Mods[a + b*x^2]^3/(6*b)}
{x*Mods[a + b*x^2]^3, x, 1, Mods[a + b*x^2]^4/(8*b)}
{x/Mods[a + b*x^2], x, 1, Log[Mods[a + b*x^2]]/(2*b)}
{x/Mods[a + b*x^2]^2, x, 1, -1/(2*b*Mods[a + b*x^2])}
{x/Mods[a + b*x^2]^3, x, 1, -1/(4*b*Mods[a + b*x^2]^2)}

{x^2*Mods[a + b*x^2], x, 2, (-2*b*x^5 + 5*x^3*Mods[a + b*x^2])/15}
{x^2*Mods[a + b*x^2]^2, x, 5, (8*b^2*x^7 - 28*b*x^5*Mods[a + b*x^2] + 35*x^3*Mods[a + b*x^2]^2)/105}
{x^2*Mods[a + b*x^2]^3, x, 6, (-16*b^3*x^9 + 72*b^2*x^7*Mods[a + b*x^2] - 126*b*x^5*Mods[a + b*x^2]^2 + 105*x^3*Mods[a + b*x^2]^3)/315}
{x^2/Mods[a + b*x^2], x, 2, x/b - (ArcTan[(Sqrt[b]*x)/Sqrt[-(b*x^2) + Mods[a + b*x^2]]]*Sqrt[-(b*x^2) + Mods[a + b*x^2]])/b^(3/2)}
{x^2/Mods[a + b*x^2]^2, x, 2, -x/(2*b*Mods[a + b*x^2]) + ArcTan[(Sqrt[b]*x)/Sqrt[-(b*x^2) + Mods[a + b*x^2]]]/(2*b^(3/2)*Sqrt[-(b*x^2) + Mods[a + b*x^2]])}
{x^2/Mods[a + b*x^2]^3, x, 3, ((-2*x)/(b*Mods[a + b*x^2]^2) + ArcTan[(Sqrt[b]*x)/Sqrt[-(b*x^2) + Mods[a + b*x^2]]]/(b^(3/2)*(-(b*x^2) + Mods[a + b*x^2])^(3/2)) + x/(b*Mods[a + b*x^2]*(-(b*x^2) + Mods[a + b*x^2])))/8}

{x^3*Mods[a + b*x^2], x, 2, -(x^4*(b*x^2 - 3*Mods[a + b*x^2]))/12}
{x^3*Mods[a + b*x^2]^2, x, 3, (b^2*x^8 - 4*b*x^6*Mods[a + b*x^2] + 6*x^4*Mods[a + b*x^2]^2)/24}
{x^3*Mods[a + b*x^2]^3, x, 4, (-(b^3*x^10) + 5*b^2*x^8*Mods[a + b*x^2] - 10*b*x^6*Mods[a + b*x^2]^2 + 10*x^4*Mods[a + b*x^2]^3)/40}
{x^3/Mods[a + b*x^2], x, 2, (b*x^2*(1 + Log[Mods[a + b*x^2]]) - Log[Mods[a + b*x^2]]*Mods[a + b*x^2])/(2*b^2)}
{x^3/Mods[a + b*x^2]^2, x, 2, (Log[Mods[a + b*x^2]] - (b*x^2)/Mods[a + b*x^2])/(2*b^2)}
{x^3/Mods[a + b*x^2]^3, x, 2, -(b*x^2 + Mods[a + b*x^2])/(4*b^2*Mods[a + b*x^2]^2)}

{Mods[a + b*x^2]/x, x, 2, -(b*x^2*Log[x]) + (1/2 + Log[x])*Mods[a + b*x^2]}
{Mods[a + b*x^2]^2/x, x, 3, (4*b^2*x^4*Log[x] - 2*b*x^2*(1 + 4*Log[x])*Mods[a + b*x^2] + (3 + 4*Log[x])*Mods[a + b*x^2]^2)/4}
{Mods[a + b*x^2]^3/x, x, 4, -(b^3*x^6*Log[x]) + (b^2*x^4*(1 + 6*Log[x])*Mods[a + b*x^2])/2 - (b*x^2*(5 + 12*Log[x])*Mods[a + b*x^2]^2)/4 + (11/12 + Log[x])*Mods[a + b*x^2]^3}
{1/(x*Mods[a + b*x^2]), x, 2, Log[Mods[a + b*x^2]/x^2]/(2*b*x^2 - 2*Mods[a + b*x^2])}
{1/(x*Mods[a + b*x^2]^2), x, 3, -(b*x^2 + (-1 + Log[Mods[a + b*x^2]/x^2])*Mods[a + b*x^2])/(2*Mods[a + b*x^2]*(-(b*x^2) + Mods[a + b*x^2])^2)}
{1/(x*Mods[a + b*x^2]^3), x, 4, If[$VersionNumber>6, (b^2*x^4 - 4*b*x^2*Mods[a + b*x^2] + (3 - 2*Log[Mods[a + b*x^2]/x^2])*Mods[a + b*x^2]^2)/(4*Mods[a + b*x^2]^2*((-b)*x^2 + Mods[a + b*x^2])^3), ((-b^2)*x^4 + 4*b*x^2*Mods[a + b*x^2] + (-3 + 2*Log[Mods[a + b*x^2]/x^2])*Mods[a + b*x^2]^2)/(4*(b*x^2 - Mods[a + b*x^2])^3*Mods[a + b*x^2]^2)]}

{Mods[a + b*x^2]/x^2, x, 2, 2*b*x - Mods[a + b*x^2]/x}
{Mods[a + b*x^2]^2/x^2, x, 3, (-8*b^2*x^3)/3 + 4*b*x*Mods[a + b*x^2] - Mods[a + b*x^2]^2/x}
{Mods[a + b*x^2]^3/x^2, x, 4, (16*b^3*x^5)/5 - 8*b^2*x^3*Mods[a + b*x^2] + 6*b*x*Mods[a + b*x^2]^2 - Mods[a + b*x^2]^3/x}
{1/(x^2*Mods[a + b*x^2]), x, 2, (1 + (Sqrt[b]*x*ArcTan[(Sqrt[b]*x)/Sqrt[-(b*x^2) + Mods[a + b*x^2]]])/Sqrt[-(b*x^2) + Mods[a + b*x^2]])/(b*x^3 - x*Mods[a + b*x^2])}
{1/(x^2*Mods[a + b*x^2]^2), x, 3, (-3*Sqrt[b]*ArcTan[(Sqrt[b]*x)/Sqrt[-(b*x^2) + Mods[a + b*x^2]]])/(2*(-(b*x^2) + Mods[a + b*x^2])^(5/2)) - 1/(x*(-(b*x^2) + Mods[a + b*x^2])^2) - (b*x)/(2*Mods[a + b*x^2]*(-(b*x^2) + Mods[a + b*x^2])^2)}
{1/(x^2*Mods[a + b*x^2]^3), x, 4, (8/(x*(b*x^2 - Mods[a + b*x^2])^3) + (9*b*x)/((b*x^2 - Mods[a + b*x^2])^3*Mods[a + b*x^2]) - (15*Sqrt[b]*ArcTan[(Sqrt[b]*x)/Sqrt[-(b*x^2) + Mods[a + b*x^2]]])/(-(b*x^2) + Mods[a + b*x^2])^(7/2) + (2*b^2*x^3)/(Mods[a + b*x^2]^2*(-(b*x^2) + Mods[a + b*x^2])^3))/8}

{Mods[a + b*x^2]/x^3, x, 2, b*Log[x] - Mods[a + b*x^2]/(2*x^2)}
{Mods[a + b*x^2]^2/x^3, x, 3, -(4*b^2*x^4*Log[x] - 2*b*x^2*(1 + 2*Log[x])*Mods[a + b*x^2] + Mods[a + b*x^2]^2)/(2*x^2)}
{Mods[a + b*x^2]^3/x^3, x, 4, (12*b^3*x^6*Log[x] - 6*b^2*x^4*(1 + 4*Log[x])*Mods[a + b*x^2] + 3*b*x^2*(3 + 4*Log[x])*Mods[a + b*x^2]^2 - 2*Mods[a + b*x^2]^3)/(4*x^2)}
{1/(x^3*Mods[a + b*x^2]), x, 3, (b*x^2*(1 + Log[Mods[a + b*x^2]/x^2]) - Mods[a + b*x^2])/(2*(b*x^3 - x*Mods[a + b*x^2])^2)}
{1/(x^3*Mods[a + b*x^2]^2), x, 4, (-(b^2*x^4) - 2*b*x^2*Log[Mods[a + b*x^2]/x^2]*Mods[a + b*x^2] + Mods[a + b*x^2]^2)/(2*x^2*(b*x^2 - Mods[a + b*x^2])^3*Mods[a + b*x^2])}
{1/(x^3*Mods[a + b*x^2]^3), x, 5, (-(b^3*x^6) + 6*b^2*x^4*Mods[a + b*x^2] + 3*b*x^2*(-1 + 2*Log[Mods[a + b*x^2]/x^2])*Mods[a + b*x^2]^2 - 2*Mods[a + b*x^2]^3)/(4*x^2*Mods[a + b*x^2]^2*(-(b*x^2) + Mods[a + b*x^2])^4)}


(* Integrands of the form x^m*Mods[a+b*x^2]^n where m is a half-integer and n is an integer *)
{Sqrt[x]*Mods[a + b*x^2], x, 2, (2*x^(3/2)*(-4*b*x^2 + 7*Mods[a + b*x^2]))/21}
{Sqrt[x]*Mods[a + b*x^2]^2, x, 3, (2*x^(3/2)*(32*b^2*x^4 - 88*b*x^2*Mods[a + b*x^2] + 77*Mods[a + b*x^2]^2))/231}
{Sqrt[x]*Mods[a + b*x^2]^3, x, 4, (2*x^(3/2)*(-128*b^3*x^6 + 480*b^2*x^4*Mods[a + b*x^2] - 660*b*x^2*Mods[a + b*x^2]^2 + 385*Mods[a + b*x^2]^3))/1155}
{Sqrt[x]/Mods[a + b*x^2], x, 2, (-2*ArcTan[1 - (Sqrt[2]*b^(1/4)*Sqrt[x])/((-b)*x^2 + Mods[a + b*x^2])^(1/4)] + 2*ArcTan[1 + (Sqrt[2]*b^(1/4)*Sqrt[x])/((-b)*x^2 + Mods[a + b*x^2])^(1/4)] + Log[x - (Sqrt[2]*Sqrt[x]*((-b)*x^2 + Mods[a + b*x^2])^(1/4))/b^(1/4) + Sqrt[(-b)*x^2 + Mods[a + b*x^2]]/Sqrt[b]] - Log[x + (Sqrt[2]*Sqrt[x]*((-b)*x^2 + Mods[a + b*x^2])^(1/4))/b^(1/4) + Sqrt[(-b)*x^2 + Mods[a + b*x^2]]/Sqrt[b]])/(2*Sqrt[2]*b^(3/4)*((-b)*x^2 + Mods[a + b*x^2])^(1/4))}
{Sqrt[x]/Mods[a + b*x^2]^2, x, 3, (1/16)*((Sqrt[2]*(-2*ArcTan[1 - (Sqrt[2]*b^(1/4)*Sqrt[x])/((-b)*x^2 + Mods[a + b*x^2])^(1/4)] + 2*ArcTan[1 + (Sqrt[2]*b^(1/4)*Sqrt[x])/((-b)*x^2 + Mods[a + b*x^2])^(1/4)] + Log[x - (1/b^(1/4))*(Sqrt[2]*Sqrt[x]*((-b)*x^2 + Mods[a + b*x^2])^(1/4)) + Sqrt[(-b)*x^2 + Mods[a + b*x^2]]/Sqrt[b]] - Log[x + (1/b^(1/4))*(Sqrt[2]*Sqrt[x]*((-b)*x^2 + Mods[a + b*x^2])^(1/4)) + Sqrt[(-b)*x^2 + Mods[a + b*x^2]]/Sqrt[b]]))/(b^(3/4)*((-b)*x^2 + Mods[a + b*x^2])^(5/4)) + (8*x^(3/2))/(Mods[a + b*x^2]*((-b)*x^2 + Mods[a + b*x^2])))}
{Sqrt[x]/Mods[a + b*x^2]^3, x, 4, (-5*Sqrt[2]*(2*ArcTan[1 - (Sqrt[2]*b^(1/4)*Sqrt[x])/(-(b*x^2) + Mods[a + b*x^2])^(1/4)] - 2*ArcTan[1 + (Sqrt[2]*b^(1/4)*Sqrt[x])/(-(b*x^2) + Mods[a + b*x^2])^(1/4)] - Log[x - (Sqrt[2]*Sqrt[x]*(-(b*x^2) + Mods[a + b*x^2])^(1/4))/b^(1/4) + Sqrt[-(b*x^2) + Mods[a + b*x^2]]/Sqrt[b]] + Log[x + (Sqrt[2]*Sqrt[x]*(-(b*x^2) + Mods[a + b*x^2])^(1/4))/b^(1/4) + Sqrt[-(b*x^2) + Mods[a + b*x^2]]/Sqrt[b]])*Mods[a + b*x^2]^2 - 32*b^(7/4)*x^(7/2)*(-(b*x^2) + Mods[a + b*x^2])^(1/4) + 72*b^(3/4)*x^(3/2)*Mods[a + b*x^2]*(-(b*x^2) + Mods[a + b*x^2])^(1/4))/(128*b^(3/4)*Mods[a + b*x^2]^2*(-(b*x^2) + Mods[a + b*x^2])^(9/4))}

{x^(3/2)*Mods[a + b*x^2], x, 2, (2*x^(5/2)*(-4*b*x^2 + 9*Mods[a + b*x^2]))/45}
{x^(3/2)*Mods[a + b*x^2]^2, x, 3, (2*x^(5/2)*(32*b^2*x^4 - 104*b*x^2*Mods[a + b*x^2] + 117*Mods[a + b*x^2]^2))/585}
{x^(3/2)*Mods[a + b*x^2]^3, x, 4, (-2*x^(5/2)*(128*b^3*x^6 - 544*b^2*x^4*Mods[a + b*x^2] + 884*b*x^2*Mods[a + b*x^2]^2 - 663*Mods[a + b*x^2]^3))/3315}
{x^(3/2)/Mods[a + b*x^2], x, 3, (2*Sqrt[x])/b + (1/(2*Sqrt[2]*b^(5/4)))*((2*ArcTan[1 - (Sqrt[2]*b^(1/4)*Sqrt[x])/((-b)*x^2 + Mods[a + b*x^2])^(1/4)] - 2*ArcTan[1 + (Sqrt[2]*b^(1/4)*Sqrt[x])/((-b)*x^2 + Mods[a + b*x^2])^(1/4)] + Log[x - (Sqrt[2]*Sqrt[x]*((-b)*x^2 + Mods[a + b*x^2])^(1/4))/b^(1/4) + Sqrt[(-b)*x^2 + Mods[a + b*x^2]]/Sqrt[b]] - Log[x + (Sqrt[2]*Sqrt[x]*((-b)*x^2 + Mods[a + b*x^2])^(1/4))/b^(1/4) + Sqrt[(-b)*x^2 + Mods[a + b*x^2]]/Sqrt[b]])*((-b)*x^2 + Mods[a + b*x^2])^(1/4))}
{x^(3/2)/Mods[a + b*x^2]^2, x, 4, (1/(4*((-b)*x^2 + Mods[a + b*x^2])))*(-((2*Sqrt[x])/b) + (2*x^(5/2))/Mods[a + b*x^2] + (1/(2*Sqrt[2]*b^(5/4)))*((-2*ArcTan[1 - (Sqrt[2]*b^(1/4)*Sqrt[x])/((-b)*x^2 + Mods[a + b*x^2])^(1/4)] + 2*ArcTan[1 + (Sqrt[2]*b^(1/4)*Sqrt[x])/((-b)*x^2 + Mods[a + b*x^2])^(1/4)] - Log[x - (Sqrt[2]*Sqrt[x]*((-b)*x^2 + Mods[a + b*x^2])^(1/4))/b^(1/4) + Sqrt[(-b)*x^2 + Mods[a + b*x^2]]/Sqrt[b]] + Log[x + (Sqrt[2]*Sqrt[x]*((-b)*x^2 + Mods[a + b*x^2])^(1/4))/b^(1/4) + Sqrt[(-b)*x^2 + Mods[a + b*x^2]]/Sqrt[b]])*((-b)*x^2 + Mods[a + b*x^2])^(1/4)))}
{x^(3/2)/Mods[a + b*x^2]^3, x, 5, (1/(8*((-b)*x^2 + Mods[a + b*x^2])))*((2*x^(5/2))/Mods[a + b*x^2]^2 + (1/(4*((-b)*x^2 + Mods[a + b*x^2])))*(3*(-((2*Sqrt[x])/b) + (2*x^(5/2))/Mods[a + b*x^2] + (1/(2*Sqrt[2]*b^(5/4)))*((-2*ArcTan[1 - (Sqrt[2]*b^(1/4)*Sqrt[x])/((-b)*x^2 + Mods[a + b*x^2])^(1/4)] + 2*ArcTan[1 + (Sqrt[2]*b^(1/4)*Sqrt[x])/((-b)*x^2 + Mods[a + b*x^2])^(1/4)] - Log[x - (Sqrt[2]*Sqrt[x]*((-b)*x^2 + Mods[a + b*x^2])^(1/4))/b^(1/4) + Sqrt[(-b)*x^2 + Mods[a + b*x^2]]/Sqrt[b]] + Log[x + (Sqrt[2]*Sqrt[x]*((-b)*x^2 + Mods[a + b*x^2])^(1/4))/b^(1/4) + Sqrt[(-b)*x^2 + Mods[a + b*x^2]]/Sqrt[b]])*((-b)*x^2 + Mods[a + b*x^2])^(1/4)))))}

{x^(5/2)*Mods[a + b*x^2], x, 2, (2*x^(7/2)*(-4*b*x^2 + 11*Mods[a + b*x^2]))/77}
{x^(5/2)*Mods[a + b*x^2]^2, x, 3, (2*x^(7/2)*(32*b^2*x^4 - 120*b*x^2*Mods[a + b*x^2] + 165*Mods[a + b*x^2]^2))/1155}
{x^(5/2)*Mods[a + b*x^2]^3, x, 4, (-2*x^(7/2)*(128*b^3*x^6 - 608*b^2*x^4*Mods[a + b*x^2] + 1140*b*x^2*Mods[a + b*x^2]^2 - 1045*Mods[a + b*x^2]^3))/7315}
{x^(5/2)/Mods[a + b*x^2], x, 3, (2*x^(3/2))/(3*b) + (1/(2*Sqrt[2]*b^(7/4)))*((2*ArcTan[1 - (Sqrt[2]*b^(1/4)*Sqrt[x])/((-b)*x^2 + Mods[a + b*x^2])^(1/4)] - 2*ArcTan[1 + (Sqrt[2]*b^(1/4)*Sqrt[x])/((-b)*x^2 + Mods[a + b*x^2])^(1/4)] - Log[x - (Sqrt[2]*Sqrt[x]*((-b)*x^2 + Mods[a + b*x^2])^(1/4))/b^(1/4) + Sqrt[(-b)*x^2 + Mods[a + b*x^2]]/Sqrt[b]] + Log[x + (Sqrt[2]*Sqrt[x]*((-b)*x^2 + Mods[a + b*x^2])^(1/4))/b^(1/4) + Sqrt[(-b)*x^2 + Mods[a + b*x^2]]/Sqrt[b]])*((-b)*x^2 + Mods[a + b*x^2])^(3/4))}
{x^(5/2)/Mods[a + b*x^2]^2, x, 4, (1/(4*((-b)*x^2 + Mods[a + b*x^2])))*((2*x^(7/2))/Mods[a + b*x^2] - 3*((2*x^(3/2))/(3*b) + (1/(2*Sqrt[2]*b^(7/4)))*((2*ArcTan[1 - (Sqrt[2]*b^(1/4)*Sqrt[x])/((-b)*x^2 + Mods[a + b*x^2])^(1/4)] - 2*ArcTan[1 + (Sqrt[2]*b^(1/4)*Sqrt[x])/((-b)*x^2 + Mods[a + b*x^2])^(1/4)] - Log[x - (Sqrt[2]*Sqrt[x]*((-b)*x^2 + Mods[a + b*x^2])^(1/4))/b^(1/4) + Sqrt[(-b)*x^2 + Mods[a + b*x^2]]/Sqrt[b]] + Log[x + (Sqrt[2]*Sqrt[x]*((-b)*x^2 + Mods[a + b*x^2])^(1/4))/b^(1/4) + Sqrt[(-b)*x^2 + Mods[a + b*x^2]]/Sqrt[b]])*((-b)*x^2 + Mods[a + b*x^2])^(3/4))))}
{x^(5/2)/Mods[a + b*x^2]^3, x, 5, (32*x^(7/2) - (8*x^(3/2)*Mods[a + b*x^2])/b - (3*Sqrt[2]*(2*ArcTan[1 - (Sqrt[2]*b^(1/4)*Sqrt[x])/((-b)*x^2 + Mods[a + b*x^2])^(1/4)] - 2*ArcTan[1 + (Sqrt[2]*b^(1/4)*Sqrt[x])/((-b)*x^2 + Mods[a + b*x^2])^(1/4)] - Log[x - (Sqrt[2]*Sqrt[x]*((-b)*x^2 + Mods[a + b*x^2])^(1/4))/b^(1/4) + Sqrt[(-b)*x^2 + Mods[a + b*x^2]]/Sqrt[b]] + Log[x + (Sqrt[2]*Sqrt[x]*((-b)*x^2 + Mods[a + b*x^2])^(1/4))/b^(1/4) + Sqrt[(-b)*x^2 + Mods[a + b*x^2]]/Sqrt[b]])*Mods[a + b*x^2]^2)/(b^(7/4)*((-b)*x^2 + Mods[a + b*x^2])^(1/4)))/(128*Mods[a + b*x^2]^2*((-b)*x^2 + Mods[a + b*x^2]))}

{Mods[a + b*x^2]/Sqrt[x], x, 2, (-8*b*x^(5/2))/5 + 2*Sqrt[x]*Mods[a + b*x^2]}
{Mods[a + b*x^2]^2/Sqrt[x], x, 3, (2*Sqrt[x]*(32*b^2*x^4 - 72*b*x^2*Mods[a + b*x^2] + 45*Mods[a + b*x^2]^2))/45}
{Mods[a + b*x^2]^3/Sqrt[x], x, 4, (2*Sqrt[x]*(-128*b^3*x^6 + 416*b^2*x^4*Mods[a + b*x^2] - 468*b*x^2*Mods[a + b*x^2]^2 + 195*Mods[a + b*x^2]^3))/195}
{1/(Sqrt[x]*Mods[a + b*x^2]), x, 2, (-2*ArcTan[1 - (Sqrt[2]*b^(1/4)*Sqrt[x])/(-(b*x^2) + Mods[a + b*x^2])^(1/4)] + 2*ArcTan[1 + (Sqrt[2]*b^(1/4)*Sqrt[x])/(-(b*x^2) + Mods[a + b*x^2])^(1/4)] - Log[x - (Sqrt[2]*Sqrt[x]*(-(b*x^2) + Mods[a + b*x^2])^(1/4))/b^(1/4) + Sqrt[-(b*x^2) + Mods[a + b*x^2]]/Sqrt[b]] + Log[x + (Sqrt[2]*Sqrt[x]*(-(b*x^2) + Mods[a + b*x^2])^(1/4))/b^(1/4) + Sqrt[-(b*x^2) + Mods[a + b*x^2]]/Sqrt[b]])/(2*Sqrt[2]*b^(1/4)*(-(b*x^2) + Mods[a + b*x^2])^(3/4))}
{1/(Sqrt[x]*Mods[a + b*x^2]^2), x, 3, (3*(-2*ArcTan[1 - (Sqrt[2]*b^(1/4)*Sqrt[x])/((-b)*x^2 + Mods[a + b*x^2])^(1/4)] + 2*ArcTan[1 + (Sqrt[2]*b^(1/4)*Sqrt[x])/((-b)*x^2 + Mods[a + b*x^2])^(1/4)] - Log[x - (Sqrt[2]*Sqrt[x]*((-b)*x^2 + Mods[a + b*x^2])^(1/4))/b^(1/4) + Sqrt[(-b)*x^2 + Mods[a + b*x^2]]/Sqrt[b]] + Log[x + (Sqrt[2]*Sqrt[x]*((-b)*x^2 + Mods[a + b*x^2])^(1/4))/b^(1/4) + Sqrt[(-b)*x^2 + Mods[a + b*x^2]]/Sqrt[b]]))/(8*Sqrt[2]*b^(1/4)*((-b)*x^2 + Mods[a + b*x^2])^(7/4)) - Sqrt[x]/(2*b*x^2*Mods[a + b*x^2] - 2*Mods[a + b*x^2]^2)}
{1/(Sqrt[x]*Mods[a + b*x^2]^3), x, 4, (1/(8*((-b)*x^2 + Mods[a + b*x^2])))*((2*Sqrt[x])/Mods[a + b*x^2]^2 - (21*(2*ArcTan[1 - (Sqrt[2]*b^(1/4)*Sqrt[x])/((-b)*x^2 + Mods[a + b*x^2])^(1/4)] - 2*ArcTan[1 + (Sqrt[2]*b^(1/4)*Sqrt[x])/((-b)*x^2 + Mods[a + b*x^2])^(1/4)] + Log[x - (Sqrt[2]*Sqrt[x]*((-b)*x^2 + Mods[a + b*x^2])^(1/4))/b^(1/4) + Sqrt[(-b)*x^2 + Mods[a + b*x^2]]/Sqrt[b]] - Log[x + (Sqrt[2]*Sqrt[x]*((-b)*x^2 + Mods[a + b*x^2])^(1/4))/b^(1/4) + Sqrt[(-b)*x^2 + Mods[a + b*x^2]]/Sqrt[b]]))/(8*Sqrt[2]*b^(1/4)*((-b)*x^2 + Mods[a + b*x^2])^(7/4)) - (7*Sqrt[x])/(2*b*x^2*Mods[a + b*x^2] - 2*Mods[a + b*x^2]^2))}

{Mods[a + b*x^2]/x^(3/2), x, 2, (2*(4*b*x^2 - 3*Mods[a + b*x^2]))/(3*Sqrt[x])}
{Mods[a + b*x^2]^2/x^(3/2), x, 3, (-2*(32*b^2*x^4 - 56*b*x^2*Mods[a + b*x^2] + 21*Mods[a + b*x^2]^2))/(21*Sqrt[x])}
{Mods[a + b*x^2]^3/x^(3/2), x, 4, (2*(128*b^3*x^6 - 352*b^2*x^4*Mods[a + b*x^2] + 308*b*x^2*Mods[a + b*x^2]^2 - 77*Mods[a + b*x^2]^3))/(77*Sqrt[x])}
{1/(x^(3/2)*Mods[a + b*x^2]), x, 4, 2/(Sqrt[x]*(b*x^2 - Mods[a + b*x^2])) + (b^(1/4)*(2*ArcTan[1 - (Sqrt[2]*b^(1/4)*Sqrt[x])/((-b)*x^2 + Mods[a + b*x^2])^(1/4)] - 2*ArcTan[1 + (Sqrt[2]*b^(1/4)*Sqrt[x])/((-b)*x^2 + Mods[a + b*x^2])^(1/4)] - Log[x - (Sqrt[2]*Sqrt[x]*((-b)*x^2 + Mods[a + b*x^2])^(1/4))/b^(1/4) + Sqrt[(-b)*x^2 + Mods[a + b*x^2]]/Sqrt[b]] + Log[x + (Sqrt[2]*Sqrt[x]*((-b)*x^2 + Mods[a + b*x^2])^(1/4))/b^(1/4) + Sqrt[(-b)*x^2 + Mods[a + b*x^2]]/Sqrt[b]]))/(2*Sqrt[2]*((-b)*x^2 + Mods[a + b*x^2])^(5/4))}
{1/(x^(3/2)*Mods[a + b*x^2]^2), x, 5, (1/(4*((-b)*x^2 + Mods[a + b*x^2])))*(2/(Sqrt[x]*Mods[a + b*x^2]) + 5*(2/(Sqrt[x]*(b*x^2 - Mods[a + b*x^2])) + (b^(1/4)*(2*ArcTan[1 - (Sqrt[2]*b^(1/4)*Sqrt[x])/((-b)*x^2 + Mods[a + b*x^2])^(1/4)] - 2*ArcTan[1 + (Sqrt[2]*b^(1/4)*Sqrt[x])/((-b)*x^2 + Mods[a + b*x^2])^(1/4)] - Log[x - (Sqrt[2]*Sqrt[x]*((-b)*x^2 + Mods[a + b*x^2])^(1/4))/b^(1/4) + Sqrt[(-b)*x^2 + Mods[a + b*x^2]]/Sqrt[b]] + Log[x + (Sqrt[2]*Sqrt[x]*((-b)*x^2 + Mods[a + b*x^2])^(1/4))/b^(1/4) + Sqrt[(-b)*x^2 + Mods[a + b*x^2]]/Sqrt[b]]))/(2*Sqrt[2]*((-b)*x^2 + Mods[a + b*x^2])^(5/4))))}
{1/(x^(3/2)*Mods[a + b*x^2]^3), x, 6, (1/(8*((-b)*x^2 + Mods[a + b*x^2])))*(2/(Sqrt[x]*Mods[a + b*x^2]^2) + (1/(4*((-b)*x^2 + Mods[a + b*x^2])))*(9*(2/(Sqrt[x]*Mods[a + b*x^2]) + 5*(2/(Sqrt[x]*(b*x^2 - Mods[a + b*x^2])) + (b^(1/4)*(2*ArcTan[1 - (Sqrt[2]*b^(1/4)*Sqrt[x])/((-b)*x^2 + Mods[a + b*x^2])^(1/4)] - 2*ArcTan[1 + (Sqrt[2]*b^(1/4)*Sqrt[x])/((-b)*x^2 + Mods[a + b*x^2])^(1/4)] - Log[x - (Sqrt[2]*Sqrt[x]*((-b)*x^2 + Mods[a + b*x^2])^(1/4))/b^(1/4) + Sqrt[(-b)*x^2 + Mods[a + b*x^2]]/Sqrt[b]] + Log[x + (Sqrt[2]*Sqrt[x]*((-b)*x^2 + Mods[a + b*x^2])^(1/4))/b^(1/4) + Sqrt[(-b)*x^2 + Mods[a + b*x^2]]/Sqrt[b]]))/(2*Sqrt[2]*((-b)*x^2 + Mods[a + b*x^2])^(5/4))))))}

{Mods[a + b*x^2]/x^(5/2), x, 2, (2*(4*b*x^2 - Mods[a + b*x^2]))/(3*x^(3/2))}
{Mods[a + b*x^2]^2/x^(5/2), x, 3, (-2*(32*b^2*x^4 - 40*b*x^2*Mods[a + b*x^2] + 5*Mods[a + b*x^2]^2))/(15*x^(3/2))}
{Mods[a + b*x^2]^3/x^(5/2), x, 4, (2*(128*b^3*x^6 - 288*b^2*x^4*Mods[a + b*x^2] + 180*b*x^2*Mods[a + b*x^2]^2 - 15*Mods[a + b*x^2]^3))/(45*x^(3/2))}
{1/(x^(5/2)*Mods[a + b*x^2]), x, 3, 2/(x^(3/2)*(3*b*x^2 - 3*Mods[a + b*x^2])) + (b^(3/4)*(2*ArcTan[1 - (Sqrt[2]*b^(1/4)*Sqrt[x])/((-b)*x^2 + Mods[a + b*x^2])^(1/4)] - 2*ArcTan[1 + (Sqrt[2]*b^(1/4)*Sqrt[x])/((-b)*x^2 + Mods[a + b*x^2])^(1/4)] + Log[x - (Sqrt[2]*Sqrt[x]*((-b)*x^2 + Mods[a + b*x^2])^(1/4))/b^(1/4) + Sqrt[(-b)*x^2 + Mods[a + b*x^2]]/Sqrt[b]] - Log[x + (Sqrt[2]*Sqrt[x]*((-b)*x^2 + Mods[a + b*x^2])^(1/4))/b^(1/4) + Sqrt[(-b)*x^2 + Mods[a + b*x^2]]/Sqrt[b]]))/(2*Sqrt[2]*((-b)*x^2 + Mods[a + b*x^2])^(7/4))}
{1/(x^(5/2)*Mods[a + b*x^2]^2), x, 4, (1/(4*((-b)*x^2 + Mods[a + b*x^2])))*(2/(x^(3/2)*Mods[a + b*x^2]) + 7*(2/(x^(3/2)*(3*b*x^2 - 3*Mods[a + b*x^2])) + (b^(3/4)*(2*ArcTan[1 - (Sqrt[2]*b^(1/4)*Sqrt[x])/((-b)*x^2 + Mods[a + b*x^2])^(1/4)] - 2*ArcTan[1 + (Sqrt[2]*b^(1/4)*Sqrt[x])/((-b)*x^2 + Mods[a + b*x^2])^(1/4)] + Log[x - (Sqrt[2]*Sqrt[x]*((-b)*x^2 + Mods[a + b*x^2])^(1/4))/b^(1/4) + Sqrt[(-b)*x^2 + Mods[a + b*x^2]]/Sqrt[b]] - Log[x + (Sqrt[2]*Sqrt[x]*((-b)*x^2 + Mods[a + b*x^2])^(1/4))/b^(1/4) + Sqrt[(-b)*x^2 + Mods[a + b*x^2]]/Sqrt[b]]))/(2*Sqrt[2]*((-b)*x^2 + Mods[a + b*x^2])^(7/4))))}
{1/(x^(5/2)*Mods[a + b*x^2]^3), x, 5, (1/(8*((-b)*x^2 + Mods[a + b*x^2])))*(2/(x^(3/2)*Mods[a + b*x^2]^2) + (1/(4*((-b)*x^2 + Mods[a + b*x^2])))*(11*(2/(x^(3/2)*Mods[a + b*x^2]) + 7*(2/(x^(3/2)*(3*b*x^2 - 3*Mods[a + b*x^2])) + (b^(3/4)*(2*ArcTan[1 - (Sqrt[2]*b^(1/4)*Sqrt[x])/((-b)*x^2 + Mods[a + b*x^2])^(1/4)] - 2*ArcTan[1 + (Sqrt[2]*b^(1/4)*Sqrt[x])/((-b)*x^2 + Mods[a + b*x^2])^(1/4)] + Log[x - (Sqrt[2]*Sqrt[x]*((-b)*x^2 + Mods[a + b*x^2])^(1/4))/b^(1/4) + Sqrt[(-b)*x^2 + Mods[a + b*x^2]]/Sqrt[b]] - Log[x + (Sqrt[2]*Sqrt[x]*((-b)*x^2 + Mods[a + b*x^2])^(1/4))/b^(1/4) + Sqrt[(-b)*x^2 + Mods[a + b*x^2]]/Sqrt[b]]))/(2*Sqrt[2]*((-b)*x^2 + Mods[a + b*x^2])^(7/4))))))}


(* Integrands of the form x^m*Mods[a+b*x^2]^n where m is an integer and n is a half-integer *)
{Sqrt[Mods[a + b*x^2]], x, 2, (1/2)*(x*Sqrt[Mods[a + b*x^2]] + (ArcTanh[Sqrt[Mods[a + b*x^2]]/(Sqrt[b]*x)]*((-b)*x^2 + Mods[a + b*x^2]))/Sqrt[b])}
{Mods[a + b*x^2]^(3/2), x, 3, (1/4)*(x*Mods[a + b*x^2]^(3/2) + (3/2)*((-b)*x^2 + Mods[a + b*x^2])*(x*Sqrt[Mods[a + b*x^2]] + (ArcTanh[Sqrt[Mods[a + b*x^2]]/(Sqrt[b]*x)]*((-b)*x^2 + Mods[a + b*x^2]))/Sqrt[b]))}
{Mods[a + b*x^2]^(5/2), x, 4, (1/6)*(x*Mods[a + b*x^2]^(5/2) + (5/4)*((-b)*x^2 + Mods[a + b*x^2])*(x*Mods[a + b*x^2]^(3/2) + (3/2)*((-b)*x^2 + Mods[a + b*x^2])*(x*Sqrt[Mods[a + b*x^2]] + (ArcTanh[Sqrt[Mods[a + b*x^2]]/(Sqrt[b]*x)]*((-b)*x^2 + Mods[a + b*x^2]))/Sqrt[b])))}
{1/Sqrt[Mods[a + b*x^2]], x, 1, ArcTanh[Sqrt[Mods[a + b*x^2]]/(Sqrt[b]*x)]/Sqrt[b]}
{Mods[a + b*x^2]^(-3/2), x, 1, x/(Sqrt[Mods[a + b*x^2]]*(-(b*x^2) + Mods[a + b*x^2]))}
{Mods[a + b*x^2]^(-5/2), x, 2, (-(b*x^3) + 3*x*Mods[a + b*x^2])/(3*Mods[a + b*x^2]^(3/2)*(-(b*x^2) + Mods[a + b*x^2])^2)}

{x*Sqrt[Mods[a + b*x^2]], x, 1, Mods[a + b*x^2]^(3/2)/(3*b)}
{x*Mods[a + b*x^2]^(3/2), x, 1, Mods[a + b*x^2]^(5/2)/(5*b)}
{x*Mods[a + b*x^2]^(5/2), x, 1, Mods[a + b*x^2]^(7/2)/(7*b)}
{x/Sqrt[Mods[a + b*x^2]], x, 1, Sqrt[Mods[a + b*x^2]]/b}
{x/Mods[a + b*x^2]^(3/2), x, 1, -(1/(b*Sqrt[Mods[a + b*x^2]]))}
{x/Mods[a + b*x^2]^(5/2), x, 1, -1/(3*b*Mods[a + b*x^2]^(3/2))}

{x^2*Sqrt[Mods[a + b*x^2]], x, 4, (1/(4*b))*(x*Mods[a + b*x^2]^(3/2) - (1/2)*((-b)*x^2 + Mods[a + b*x^2])*(x*Sqrt[Mods[a + b*x^2]] + (ArcTanh[Sqrt[Mods[a + b*x^2]]/(Sqrt[b]*x)]*((-b)*x^2 + Mods[a + b*x^2]))/Sqrt[b]))}
{x^2*Mods[a + b*x^2]^(3/2), x, 5, (1/(6*b))*(x*Mods[a + b*x^2]^(5/2) - (1/4)*((-b)*x^2 + Mods[a + b*x^2])*(x*Mods[a + b*x^2]^(3/2) + (3/2)*((-b)*x^2 + Mods[a + b*x^2])*(x*Sqrt[Mods[a + b*x^2]] + (ArcTanh[Sqrt[Mods[a + b*x^2]]/(Sqrt[b]*x)]*((-b)*x^2 + Mods[a + b*x^2]))/Sqrt[b])))}
{x^2*Mods[a + b*x^2]^(5/2), x, 6, (1/(8*b))*(x*Mods[a + b*x^2]^(7/2) - (1/6)*((-b)*x^2 + Mods[a + b*x^2])*(x*Mods[a + b*x^2]^(5/2) + (5/4)*((-b)*x^2 + Mods[a + b*x^2])*(x*Mods[a + b*x^2]^(3/2) + (3/2)*((-b)*x^2 + Mods[a + b*x^2])*(x*Sqrt[Mods[a + b*x^2]] + (ArcTanh[Sqrt[Mods[a + b*x^2]]/(Sqrt[b]*x)]*((-b)*x^2 + Mods[a + b*x^2]))/Sqrt[b]))))}
{x^2/Sqrt[Mods[a + b*x^2]], x, 3, ((ArcTanh[Sqrt[Mods[a + b*x^2]]/(Sqrt[b]*x)]*(b*x^2 - Mods[a + b*x^2]))/Sqrt[b] + x*Sqrt[Mods[a + b*x^2]])/(2*b)}
{x^2/Mods[a + b*x^2]^(3/2), x, 2, ArcTanh[Sqrt[Mods[a + b*x^2]]/(Sqrt[b]*x)]/b^(3/2) - x/(b*Sqrt[Mods[a + b*x^2]])}
{x^2/Mods[a + b*x^2]^(5/2), x, 1, x^3/(3*Mods[a + b*x^2]^(3/2)*(-(b*x^2) + Mods[a + b*x^2]))}

{x^3*Sqrt[Mods[a + b*x^2]], x, 3, ((5*b*x^2 - 2*Mods[a + b*x^2])*Mods[a + b*x^2]^(3/2))/(15*b^2)}
{x^3*Mods[a + b*x^2]^(3/2), x, 4, ((7*b*x^2 - 2*Mods[a + b*x^2])*Mods[a + b*x^2]^(5/2))/(35*b^2)}
{x^3*Mods[a + b*x^2]^(5/2), x, 5, ((9*b*x^2 - 2*Mods[a + b*x^2])*Mods[a + b*x^2]^(7/2))/(63*b^2)}
{x^3/Sqrt[Mods[a + b*x^2]], x, 2, ((3*b*x^2 - 2*Mods[a + b*x^2])*Sqrt[Mods[a + b*x^2]])/(3*b^2)}
{x^3/Mods[a + b*x^2]^(3/2), x, 2, (-(b*x^2) + 2*Mods[a + b*x^2])/(b^2*Sqrt[Mods[a + b*x^2]])}
{x^3/Mods[a + b*x^2]^(5/2), x, 2, (-(b*x^2) - 2*Mods[a + b*x^2])/(3*b^2*Mods[a + b*x^2]^(3/2))}

{Sqrt[Mods[a + b*x^2]]/x, x, 3, -(ArcTan[Sqrt[Mods[a + b*x^2]]/Sqrt[b*x^2 - Mods[a + b*x^2]]]*Sqrt[b*x^2 - Mods[a + b*x^2]]) + Sqrt[Mods[a + b*x^2]]}
{Mods[a + b*x^2]^(3/2)/x, x, 4, Mods[a + b*x^2]^(3/2)/3 + (-(ArcTan[Sqrt[Mods[a + b*x^2]]/Sqrt[b*x^2 - Mods[a + b*x^2]]]*Sqrt[b*x^2 - Mods[a + b*x^2]]) + Sqrt[Mods[a + b*x^2]])*(-(b*x^2) + Mods[a + b*x^2])}
{Mods[a + b*x^2]^(5/2)/x, x, 5, Mods[a + b*x^2]^(5/2)/5 + (-(b*x^2) + Mods[a + b*x^2])*(Mods[a + b*x^2]^(3/2)/3 + (-(ArcTan[Sqrt[Mods[a + b*x^2]]/Sqrt[b*x^2 - Mods[a + b*x^2]]]*Sqrt[b*x^2 - Mods[a + b*x^2]]) + Sqrt[Mods[a + b*x^2]])*(-(b*x^2) + Mods[a + b*x^2]))}
{1/(x*Sqrt[Mods[a + b*x^2]]), x, 2, ArcTan[Sqrt[Mods[a + b*x^2]]/Sqrt[b*x^2 - Mods[a + b*x^2]]]/Sqrt[b*x^2 - Mods[a + b*x^2]]}
{1/(x*Mods[a + b*x^2]^(3/2)), x, 3, -(ArcTan[Sqrt[Mods[a + b*x^2]]/Sqrt[b*x^2 - Mods[a + b*x^2]]]/(b*x^2 - Mods[a + b*x^2])^(3/2)) + 1/(Sqrt[Mods[a + b*x^2]]*(-(b*x^2) + Mods[a + b*x^2]))}
{1/(x*Mods[a + b*x^2]^(5/2)), x, 4, ArcTan[Sqrt[Mods[a + b*x^2]]/Sqrt[b*x^2 - Mods[a + b*x^2]]]/(b*x^2 - Mods[a + b*x^2])^(5/2) - (b*x^2)/(3*Mods[a + b*x^2]^(3/2)*(-(b*x^2) + Mods[a + b*x^2])^2) + 4/(3*Sqrt[Mods[a + b*x^2]]*(-(b*x^2) + Mods[a + b*x^2])^2)}

{Sqrt[Mods[a + b*x^2]]/x^2, x, 2, Sqrt[b]*ArcTanh[Sqrt[Mods[a + b*x^2]]/(Sqrt[b]*x)] - Sqrt[Mods[a + b*x^2]]/x}
{Mods[a + b*x^2]^(3/2)/x^2, x, 3, -(Mods[a + b*x^2]^(3/2)/x) + (3/2)*b*(x*Sqrt[Mods[a + b*x^2]] + (ArcTanh[Sqrt[Mods[a + b*x^2]]/(Sqrt[b]*x)]*((-b)*x^2 + Mods[a + b*x^2]))/Sqrt[b])}
{Mods[a + b*x^2]^(5/2)/x^2, x, 4, -(Mods[a + b*x^2]^(5/2)/x) + (5/4)*b*(x*Mods[a + b*x^2]^(3/2) + (3/2)*((-b)*x^2 + Mods[a + b*x^2])*(x*Sqrt[Mods[a + b*x^2]] + (ArcTanh[Sqrt[Mods[a + b*x^2]]/(Sqrt[b]*x)]*((-b)*x^2 + Mods[a + b*x^2]))/Sqrt[b]))}
{1/(x^2*Sqrt[Mods[a + b*x^2]]), x, 1, Sqrt[Mods[a + b*x^2]]/(b*x^3 - x*Mods[a + b*x^2])}
{1/(x^2*Mods[a + b*x^2]^(3/2)), x, 2, (-(b*x^2) - Mods[a + b*x^2])/(x*Sqrt[Mods[a + b*x^2]]*(-(b*x^2) + Mods[a + b*x^2])^2)}
{1/(x^2*Mods[a + b*x^2]^(5/2)), x, 3, (-(b^2*x^4) + 6*b*x^2*Mods[a + b*x^2] + 3*Mods[a + b*x^2]^2)/(3*x*(b*x^2 - Mods[a + b*x^2])^3*Mods[a + b*x^2]^(3/2))}

{Sqrt[Mods[a + b*x^2]]/x^3, x, 3, ((b*ArcTan[Sqrt[Mods[a + b*x^2]]/Sqrt[b*x^2 - Mods[a + b*x^2]]])/Sqrt[b*x^2 - Mods[a + b*x^2]] - Sqrt[Mods[a + b*x^2]]/x^2)/2}
{Mods[a + b*x^2]^(3/2)/x^3, x, 4, (3*b*(-(ArcTan[Sqrt[Mods[a + b*x^2]]/Sqrt[b*x^2 - Mods[a + b*x^2]]]*Sqrt[b*x^2 - Mods[a + b*x^2]]) + Sqrt[Mods[a + b*x^2]]))/2 - Mods[a + b*x^2]^(3/2)/(2*x^2)}
{Mods[a + b*x^2]^(5/2)/x^3, x, 5, -Mods[a + b*x^2]^(5/2)/(2*x^2) + (5*b*(Mods[a + b*x^2]^(3/2)/3 + (-(ArcTan[Sqrt[Mods[a + b*x^2]]/Sqrt[b*x^2 - Mods[a + b*x^2]]]*Sqrt[b*x^2 - Mods[a + b*x^2]]) + Sqrt[Mods[a + b*x^2]])*(-(b*x^2) + Mods[a + b*x^2])))/2}
{1/(x^3*Sqrt[Mods[a + b*x^2]]), x, 3, ((b*ArcTan[Sqrt[Mods[a + b*x^2]]/Sqrt[b*x^2 - Mods[a + b*x^2]]])/(b*x^2 - Mods[a + b*x^2])^(3/2) + Sqrt[Mods[a + b*x^2]]/(b*x^4 - x^2*Mods[a + b*x^2]))/2}
{1/(x^3*Mods[a + b*x^2]^(3/2)), x, 4, (-3*b*ArcTan[Sqrt[Mods[a + b*x^2]]/Sqrt[b*x^2 - Mods[a + b*x^2]]])/(2*(b*x^2 - Mods[a + b*x^2])^(5/2)) - b/(Sqrt[Mods[a + b*x^2]]*(-(b*x^2) + Mods[a + b*x^2])^2) - Sqrt[Mods[a + b*x^2]]/(2*(b*x^3 - x*Mods[a + b*x^2])^2)}
{1/(x^3*Mods[a + b*x^2]^(5/2)), x, 5, ((15*b*ArcTan[Sqrt[Mods[a + b*x^2]]/Sqrt[b*x^2 - Mods[a + b*x^2]]])/(b*x^2 - Mods[a + b*x^2])^(7/2) - (2*b^2*x^2)/((b*x^2 - Mods[a + b*x^2])^3*Mods[a + b*x^2]^(3/2)) + (14*b)/((b*x^2 - Mods[a + b*x^2])^3*Sqrt[Mods[a + b*x^2]]) + (3*Sqrt[Mods[a + b*x^2]])/(x^2*(b*x^2 - Mods[a + b*x^2])^3))/6}


(* Integrands of the form Log[Pi*Mods[x/Pi]]^m where m is an integer *)
{Log[Pi*Mods[x/Pi]]^3, x, 5, -6*Pi*Mods[x/Pi] + 6*Pi*Log[Pi*Mods[x/Pi]]*Mods[x/Pi] - 3*Pi*Log[Pi*Mods[x/Pi]]^2*Mods[x/Pi] + Pi*Log[Pi*Mods[x/Pi]]^3*Mods[x/Pi]}
{Log[Pi*Mods[x/Pi]]^2, x, 4, 2*Pi*Mods[x/Pi] - 2*Pi*Log[Pi*Mods[x/Pi]]*Mods[x/Pi] + Pi*Log[Pi*Mods[x/Pi]]^2*Mods[x/Pi]}
{Log[Pi*Mods[x/Pi]], x, 3, (-Pi)*Mods[x/Pi] + Pi*Log[Pi*Mods[x/Pi]]*Mods[x/Pi]}
{1/Log[Pi*Mods[x/Pi]], x, 3, LogIntegral[Pi*Mods[x/Pi]]}
{1/Log[Pi*Mods[x/Pi]]^2, x, 4, LogIntegral[Pi*Mods[x/Pi]] - (Pi*Mods[x/Pi])/Log[Pi*Mods[x/Pi]]}
{1/Log[Pi*Mods[x/Pi]]^3, x, 5, (1/2)*LogIntegral[Pi*Mods[x/Pi]] - (Pi*Mods[x/Pi])/(2*Log[Pi*Mods[x/Pi]]^2) - (Pi*Mods[x/Pi])/(2*Log[Pi*Mods[x/Pi]])}


{Log[Mods[a + b*x]], x, 3, ((-1 + Log[Mods[a + b*x]])*Mods[a + b*x])/b}
{Sin[Mods[a + b*x]], x, 3, -(Cos[Mods[a + b*x]]/b)}
{x^(-2 - n)*Mods[a + b*x]^n, x, 1, (x^(-1 - n)*Mods[a + b*x]^(1 + n))/((1 + n)*(b*x - Mods[a + b*x]))}
{1/(x^2*Sqrt[Mods[a+b/x^2]]), x, 2, -(ArcTanh[(x*Sqrt[Mods[a + b/x^2]])/Sqrt[b]]/Sqrt[b])}
