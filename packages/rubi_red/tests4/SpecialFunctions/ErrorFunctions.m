(* ::Package:: *)

(* ::Title:: *)
(*Integration Problems Involving Error Functions*)


(* ::Subsection::Closed:: *)
(*Error function*)


{x^5*Erf[b*x]^2, x, 11, 11/(E^(2*b^2*x^2)*(12*b^6*Pi)) + (7*x^2)/(E^(2*b^2*x^2)*(12*b^4*Pi)) + x^4/(E^(2*b^2*x^2)*(6*b^2*Pi)) + (5*x*Erf[b*x])/(E^(b^2*x^2)*(4*b^5*Sqrt[Pi])) + (5*x^3*Erf[b*x])/(E^(b^2*x^2)*(6*b^3*Sqrt[Pi])) + (x^5*Erf[b*x])/(E^(b^2*x^2)*(3*b*Sqrt[Pi])) - (5*Erf[b*x]^2)/(16*b^6) + (1/6)*x^6*Erf[b*x]^2}
{x^4*Erf[b*x]^2, x, 10, (11*x)/(E^(2*b^2*x^2)*(20*b^4*Pi)) + x^3/(E^(2*b^2*x^2)*(5*b^2*Pi)) + (4*Erf[b*x])/(E^(b^2*x^2)*(5*b^5*Sqrt[Pi])) + (4*x^2*Erf[b*x])/(E^(b^2*x^2)*(5*b^3*Sqrt[Pi])) + (2*x^4*Erf[b*x])/(E^(b^2*x^2)*(5*b*Sqrt[Pi])) + (1/5)*x^5*Erf[b*x]^2 - (43*Erf[Sqrt[2]*b*x])/(40*b^5*Sqrt[2*Pi])}
{x^3*Erf[b*x]^2, x, 7, 1/(E^(2*b^2*x^2)*(2*b^4*Pi)) + x^2/(E^(2*b^2*x^2)*(4*b^2*Pi)) + (3*x*Erf[b*x])/(E^(b^2*x^2)*(4*b^3*Sqrt[Pi])) + (x^3*Erf[b*x])/(E^(b^2*x^2)*(2*b*Sqrt[Pi])) - (3*Erf[b*x]^2)/(16*b^4) + (1/4)*x^4*Erf[b*x]^2}
{x^2*Erf[b*x]^2, x, 6, x/(E^(2*b^2*x^2)*(3*b^2*Pi)) + (2*Erf[b*x])/(E^(b^2*x^2)*(3*b^3*Sqrt[Pi])) + (2*x^2*Erf[b*x])/(E^(b^2*x^2)*(3*b*Sqrt[Pi])) + (1/3)*x^3*Erf[b*x]^2 - (5*Erf[Sqrt[2]*b*x])/(6*b^3*Sqrt[2*Pi])}
{x^1*Erf[b*x]^2, x, 4, 1/(E^(2*b^2*x^2)*(2*b^2*Pi)) + (x*Erf[b*x])/(E^(b^2*x^2)*(b*Sqrt[Pi])) - Erf[b*x]^2/(4*b^2) + (1/2)*x^2*Erf[b*x]^2}
{x^0*Erf[b*x]^2, x, 4, (2*Erf[b*x])/(E^(b^2*x^2)*(b*Sqrt[Pi])) + x*Erf[b*x]^2 - (Sqrt[2/Pi]*Erf[Sqrt[2]*b*x])/b}
{Erf[b*x]^2/x^1, x, 0, Int[Erf[b*x]^2/x, x]}
{Erf[b*x]^2/x^2, x, 0, Int[Erf[b*x]^2/x^2, x]}
{Erf[b*x]^2/x^3, x, 4, -((2*b*Erf[b*x])/(E^(b^2*x^2)*(Sqrt[Pi]*x))) - b^2*Erf[b*x]^2 - Erf[b*x]^2/(2*x^2) + (2*b^2*ExpIntegralEi[-2*b^2*x^2])/Pi}
{Erf[b*x]^2/x^4, x, 0, Int[Erf[b*x]^2/x^4, x]}
{Erf[b*x]^2/x^5, x, 7, -(b^2/(E^(2*b^2*x^2)*(3*Pi*x^2))) - (b*Erf[b*x])/(E^(b^2*x^2)*(3*Sqrt[Pi]*x^3)) + (2*b^3*Erf[b*x])/(E^(b^2*x^2)*(3*Sqrt[Pi]*x)) + (1/3)*b^4*Erf[b*x]^2 - Erf[b*x]^2/(4*x^4) - (4*b^4*ExpIntegralEi[-2*b^2*x^2])/(3*Pi)}
{Erf[b*x]^2/x^6, x, 0, Int[Erf[b*x]^2/x^6, x]}
{Erf[b*x]^2/x^7, x, 11, -(b^2/(E^(2*b^2*x^2)*(15*Pi*x^4))) + (2*b^4)/(E^(2*b^2*x^2)*(9*Pi*x^2)) - (2*b*Erf[b*x])/(E^(b^2*x^2)*(15*Sqrt[Pi]*x^5)) + (4*b^3*Erf[b*x])/(E^(b^2*x^2)*(45*Sqrt[Pi]*x^3)) - (8*b^5*Erf[b*x])/(E^(b^2*x^2)*(45*Sqrt[Pi]*x)) - (4/45)*b^6*Erf[b*x]^2 - Erf[b*x]^2/(6*x^6) + (28*b^6*ExpIntegralEi[-2*b^2*x^2])/(45*Pi)}
{Erf[b*x]^2/x^8, x, 0, Int[Erf[b*x]^2/x^8, x]}


{x^3*Erf[a + b*x], x, 13, -((5*a)/(E^(a + b*x)^2*(8*b^4*Sqrt[Pi]))) - a^3/(E^(a + b*x)^2*(4*b^4*Sqrt[Pi])) + (3*x)/(E^(a + b*x)^2*(8*b^3*Sqrt[Pi])) + (a^2*x)/(E^(a + b*x)^2*(4*b^3*Sqrt[Pi])) - (a*x^2)/(E^(a + b*x)^2*(4*b^2*Sqrt[Pi])) + x^3/(E^(a + b*x)^2*(4*b*Sqrt[Pi])) - (3*Erf[a + b*x])/(16*b^4) - (3*a^2*Erf[a + b*x])/(4*b^4) - (a^4*Erf[a + b*x])/(4*b^4) + (1/4)*x^4*Erf[a + b*x]}
{x^2*Erf[a + b*x], x, 8, 1/(E^(a + b*x)^2*(3*b^3*Sqrt[Pi])) + a^2/(E^(a + b*x)^2*(3*b^3*Sqrt[Pi])) - (a*x)/(E^(a + b*x)^2*(3*b^2*Sqrt[Pi])) + x^2/(E^(a + b*x)^2*(3*b*Sqrt[Pi])) + (a*Erf[a + b*x])/(2*b^3) + (a^3*Erf[a + b*x])/(3*b^3) + (1/3)*x^3*Erf[a + b*x]}
{x^1*Erf[a + b*x], x, 5, -(a/(E^(a + b*x)^2*(2*b^2*Sqrt[Pi]))) + x/(E^(a + b*x)^2*(2*b*Sqrt[Pi])) - Erf[a + b*x]/(4*b^2) - (a^2*Erf[a + b*x])/(2*b^2) + (1/2)*x^2*Erf[a + b*x]}
{x^0*Erf[a + b*x], x, 1, 1/(E^(a + b*x)^2*(b*Sqrt[Pi])) + ((a + b*x)*Erf[a + b*x])/b}
{Erf[a + b*x]/x^1, x, 0, Int[Erf[a + b*x]/x, x]}
{Erf[a + b*x]/x^2, x, 1, -(Erf[a + b*x]/x) + (2*b*Int[1/(E^(a + b*x)^2*x), x])/Sqrt[Pi]}


{x^2*Erf[a + b*x]^2, x, 16, -(a/(E^(2*(a + b*x)^2)*(b^3*Pi))) + (a + b*x)/(E^(2*(a + b*x)^2)*(3*b^3*Pi)) + (2*Erf[a + b*x])/(E^(a + b*x)^2*(3*b^3*Sqrt[Pi])) + (2*a^2*Erf[a + b*x])/(E^(a + b*x)^2*(b^3*Sqrt[Pi])) - (2*a*(a + b*x)*Erf[a + b*x])/(E^(a + b*x)^2*(b^3*Sqrt[Pi])) + (2*(a + b*x)^2*Erf[a + b*x])/(E^(a + b*x)^2*(3*b^3*Sqrt[Pi])) + (a*Erf[a + b*x]^2)/(2*b^3) + (a^2*(a + b*x)*Erf[a + b*x]^2)/b^3 - (a*(a + b*x)^2*Erf[a + b*x]^2)/b^3 + ((a + b*x)^3*Erf[a + b*x]^2)/(3*b^3) - (a^2*Sqrt[2/Pi]*Erf[Sqrt[2]*(a + b*x)])/b^3 - (5*Erf[Sqrt[2]*(a + b*x)])/(6*b^3*Sqrt[2*Pi])}
{x^1*Erf[a + b*x]^2, x, 10, 1/(E^(2*(a + b*x)^2)*(2*b^2*Pi)) - (2*a*Erf[a + b*x])/(E^(a + b*x)^2*(b^2*Sqrt[Pi])) + ((a + b*x)*Erf[a + b*x])/(E^(a + b*x)^2*(b^2*Sqrt[Pi])) - Erf[a + b*x]^2/(4*b^2) - (a*(a + b*x)*Erf[a + b*x]^2)/b^2 + ((a + b*x)^2*Erf[a + b*x]^2)/(2*b^2) + (a*Sqrt[2/Pi]*Erf[Sqrt[2]*(a + b*x)])/b^2}
{x^0*Erf[a + b*x]^2, x, 4, (2*Erf[a + b*x])/(E^(a + b*x)^2*(b*Sqrt[Pi])) + ((a + b*x)*Erf[a + b*x]^2)/b - (Sqrt[2/Pi]*Erf[Sqrt[2]*(a + b*x)])/b}
{Erf[a + b*x]^2/x^1, x, 0, Int[Erf[a + b*x]^2/x, x]}
{Erf[a + b*x]^2/x^2, x, 0, Int[Erf[a + b*x]^2/x^2, x]}


{x^6*E^(-b^2*x^2)*Erf[b*x], x, 10, -(11/(E^(2*b^2*x^2)*(8*b^7*Sqrt[Pi]))) - (7*x^2)/(E^(2*b^2*x^2)*(8*b^5*Sqrt[Pi])) - x^4/(E^(2*b^2*x^2)*(4*b^3*Sqrt[Pi])) - (15*x*Erf[b*x])/(E^(b^2*x^2)*(8*b^6)) - (5*x^3*Erf[b*x])/(E^(b^2*x^2)*(4*b^4)) - (x^5*Erf[b*x])/(E^(b^2*x^2)*(2*b^2)) + (15*Sqrt[Pi]*Erf[b*x]^2)/(32*b^7)}
{x^5*E^(-b^2*x^2)*Erf[b*x], x, 9, -((11*x)/(E^(2*b^2*x^2)*(16*b^5*Sqrt[Pi]))) - x^3/(E^(2*b^2*x^2)*(4*b^3*Sqrt[Pi])) - Erf[b*x]/(E^(b^2*x^2)*b^6) - (x^2*Erf[b*x])/(E^(b^2*x^2)*b^4) - (x^4*Erf[b*x])/(E^(b^2*x^2)*(2*b^2)) + (43*Erf[Sqrt[2]*b*x])/(32*Sqrt[2]*b^6)}
{x^4*E^(-b^2*x^2)*Erf[b*x], x, 6, -(1/(E^(2*b^2*x^2)*(2*b^5*Sqrt[Pi]))) - x^2/(E^(2*b^2*x^2)*(4*b^3*Sqrt[Pi])) - (3*x*Erf[b*x])/(E^(b^2*x^2)*(4*b^4)) - (x^3*Erf[b*x])/(E^(b^2*x^2)*(2*b^2)) + (3*Sqrt[Pi]*Erf[b*x]^2)/(16*b^5)}
{x^3*E^(-b^2*x^2)*Erf[b*x], x, 5, -(x/(E^(2*b^2*x^2)*(4*b^3*Sqrt[Pi]))) - Erf[b*x]/(E^(b^2*x^2)*(2*b^4)) - (x^2*Erf[b*x])/(E^(b^2*x^2)*(2*b^2)) + (5*Erf[Sqrt[2]*b*x])/(8*Sqrt[2]*b^4)}
{x^2*E^(-b^2*x^2)*Erf[b*x], x, 3, -(1/(E^(2*b^2*x^2)*(4*b^3*Sqrt[Pi]))) - (x*Erf[b*x])/(E^(b^2*x^2)*(2*b^2)) + (Sqrt[Pi]*Erf[b*x]^2)/(8*b^3)}
{x^1*E^(-b^2*x^2)*Erf[b*x], x, 2, -(Erf[b*x]/(E^(b^2*x^2)*(2*b^2))) + Erf[Sqrt[2]*b*x]/(2*Sqrt[2]*b^2)}
{x^0*E^(-b^2*x^2)*Erf[b*x], x, 1, (Sqrt[Pi]*Erf[b*x]^2)/(4*b)}
{E^(-b^2*x^2)*Erf[b*x]/x^1, x, 0, Int[Erf[b*x]/(E^(b^2*x^2)*x), x]}
{E^(-b^2*x^2)*Erf[b*x]/x^2, x, 3, -(Erf[b*x]/(E^(b^2*x^2)*x)) - (1/2)*b*Sqrt[Pi]*Erf[b*x]^2 + (b*ExpIntegralEi[-2*b^2*x^2])/Sqrt[Pi]}
{E^(-b^2*x^2)*Erf[b*x]/x^3, x, 3, -(b/(E^(2*b^2*x^2)*(Sqrt[Pi]*x))) - Erf[b*x]/(E^(b^2*x^2)*(2*x^2)) - Sqrt[2]*b^2*Erf[Sqrt[2]*b*x] - b^2*Int[Erf[b*x]/(E^(b^2*x^2)*x), x]}
{E^(-b^2*x^2)*Erf[b*x]/x^4, x, 6, -(b/(E^(2*b^2*x^2)*(3*Sqrt[Pi]*x^2))) - Erf[b*x]/(E^(b^2*x^2)*(3*x^3)) + (2*b^2*Erf[b*x])/(E^(b^2*x^2)*(3*x)) + (1/3)*b^3*Sqrt[Pi]*Erf[b*x]^2 - (4*b^3*ExpIntegralEi[-2*b^2*x^2])/(3*Sqrt[Pi])}
{E^(-b^2*x^2)*Erf[b*x]/x^5, x, 7, -(b/(E^(2*b^2*x^2)*(6*Sqrt[Pi]*x^3))) + (7*b^3)/(E^(2*b^2*x^2)*(6*Sqrt[Pi]*x)) - Erf[b*x]/(E^(b^2*x^2)*(4*x^4)) + (b^2*Erf[b*x])/(E^(b^2*x^2)*(4*x^2)) + (b^4*Erf[Sqrt[2]*b*x])/Sqrt[2] + (2/3)*Sqrt[2]*b^4*Erf[Sqrt[2]*b*x] + (1/2)*b^4*Int[Erf[b*x]/(E^(b^2*x^2)*x), x]}
{E^(-b^2*x^2)*Erf[b*x]/x^6, x, 10, -(b/(E^(2*b^2*x^2)*(10*Sqrt[Pi]*x^4))) + b^3/(E^(2*b^2*x^2)*(3*Sqrt[Pi]*x^2)) - Erf[b*x]/(E^(b^2*x^2)*(5*x^5)) + (2*b^2*Erf[b*x])/(E^(b^2*x^2)*(15*x^3)) - (4*b^4*Erf[b*x])/(E^(b^2*x^2)*(15*x)) - (2/15)*b^5*Sqrt[Pi]*Erf[b*x]^2 + (14*b^5*ExpIntegralEi[-2*b^2*x^2])/(15*Sqrt[Pi])}


{Erf[b*x]/(E^(b^2*x^2)*x^3) + (b^2*Erf[b*x])/(E^(b^2*x^2)*x), x, 4, -(b/(E^(2*b^2*x^2)*(Sqrt[Pi]*x))) - Erf[b*x]/(E^(b^2*x^2)*(2*x^2)) - Sqrt[2]*b^2*Erf[Sqrt[2]*b*x]}


(* ::Subsection::Closed:: *)
(*Complementary Error function*)


{Erfc[b*x]^2/x^8, x, 0, Int[Erfc[b*x]^2/x^8, x]}
{Erfc[b*x]^2/x^7, x, 11, -(b^2/(E^(2*b^2*x^2)*(15*Pi*x^4))) + (2*b^4)/(E^(2*b^2*x^2)*(9*Pi*x^2)) + (2*b*Erfc[b*x])/(E^(b^2*x^2)*(15*Sqrt[Pi]*x^5)) - (4*b^3*Erfc[b*x])/(E^(b^2*x^2)*(45*Sqrt[Pi]*x^3)) + (8*b^5*Erfc[b*x])/(E^(b^2*x^2)*(45*Sqrt[Pi]*x)) - (4/45)*b^6*Erfc[b*x]^2 - Erfc[b*x]^2/(6*x^6) + (28*b^6*ExpIntegralEi[-2*b^2*x^2])/(45*Pi)}
{Erfc[b*x]^2/x^6, x, 0, Int[Erfc[b*x]^2/x^6, x]}
{Erfc[b*x]^2/x^5, x, 7, -(b^2/(E^(2*b^2*x^2)*(3*Pi*x^2))) + (b*Erfc[b*x])/(E^(b^2*x^2)*(3*Sqrt[Pi]*x^3)) - (2*b^3*Erfc[b*x])/(E^(b^2*x^2)*(3*Sqrt[Pi]*x)) + (1/3)*b^4*Erfc[b*x]^2 - Erfc[b*x]^2/(4*x^4) - (4*b^4*ExpIntegralEi[-2*b^2*x^2])/(3*Pi)}
{Erfc[b*x]^2/x^4, x, 0, Int[Erfc[b*x]^2/x^4, x]}
{Erfc[b*x]^2/x^3, x, 4, (2*b*Erfc[b*x])/(E^(b^2*x^2)*(Sqrt[Pi]*x)) - b^2*Erfc[b*x]^2 - Erfc[b*x]^2/(2*x^2) + (2*b^2*ExpIntegralEi[-2*b^2*x^2])/Pi}
{Erfc[b*x]^2/x^2, x, 0, Int[Erfc[b*x]^2/x^2, x]}
{Erfc[b*x]^2/x, x, 0, Int[Erfc[b*x]^2/x, x]}
{Erfc[b*x]^2, x, 4, -((Sqrt[2/Pi]*Erf[Sqrt[2]*b*x])/b) - (2*Erfc[b*x])/(E^(b^2*x^2)*(b*Sqrt[Pi])) + x*Erfc[b*x]^2}
{x*Erfc[b*x]^2, x, 4, 1/(E^(2*b^2*x^2)*(2*b^2*Pi)) - (x*Erfc[b*x])/(E^(b^2*x^2)*(b*Sqrt[Pi])) - Erfc[b*x]^2/(4*b^2) + (1/2)*x^2*Erfc[b*x]^2}
{x^2*Erfc[b*x]^2, x, 6, x/(E^(2*b^2*x^2)*(3*b^2*Pi)) - (5*Erf[Sqrt[2]*b*x])/(6*b^3*Sqrt[2*Pi]) - (2*Erfc[b*x])/(E^(b^2*x^2)*(3*b^3*Sqrt[Pi])) - (2*x^2*Erfc[b*x])/(E^(b^2*x^2)*(3*b*Sqrt[Pi])) + (1/3)*x^3*Erfc[b*x]^2}
{x^3*Erfc[b*x]^2, x, 7, 1/(E^(2*b^2*x^2)*(2*b^4*Pi)) + x^2/(E^(2*b^2*x^2)*(4*b^2*Pi)) - (3*x*Erfc[b*x])/(E^(b^2*x^2)*(4*b^3*Sqrt[Pi])) - (x^3*Erfc[b*x])/(E^(b^2*x^2)*(2*b*Sqrt[Pi])) - (3*Erfc[b*x]^2)/(16*b^4) + (1/4)*x^4*Erfc[b*x]^2}
{x^4*Erfc[b*x]^2, x, 10, (11*x)/(E^(2*b^2*x^2)*(20*b^4*Pi)) + x^3/(E^(2*b^2*x^2)*(5*b^2*Pi)) - (43*Erf[Sqrt[2]*b*x])/(40*b^5*Sqrt[2*Pi]) - (4*Erfc[b*x])/(E^(b^2*x^2)*(5*b^5*Sqrt[Pi])) - (4*x^2*Erfc[b*x])/(E^(b^2*x^2)*(5*b^3*Sqrt[Pi])) - (2*x^4*Erfc[b*x])/(E^(b^2*x^2)*(5*b*Sqrt[Pi])) + (1/5)*x^5*Erfc[b*x]^2}
{x^5*Erfc[b*x]^2, x, 11, 11/(E^(2*b^2*x^2)*(12*b^6*Pi)) + (7*x^2)/(E^(2*b^2*x^2)*(12*b^4*Pi)) + x^4/(E^(2*b^2*x^2)*(6*b^2*Pi)) - (5*x*Erfc[b*x])/(E^(b^2*x^2)*(4*b^5*Sqrt[Pi])) - (5*x^3*Erfc[b*x])/(E^(b^2*x^2)*(6*b^3*Sqrt[Pi])) - (x^5*Erfc[b*x])/(E^(b^2*x^2)*(3*b*Sqrt[Pi])) - (5*Erfc[b*x]^2)/(16*b^6) + (1/6)*x^6*Erfc[b*x]^2}


{Erfc[a + b*x]/x, x, 0, Int[Erfc[a + b*x]/x, x]}
{Erfc[a + b*x], x, 1, -(1/(E^(a + b*x)^2*(b*Sqrt[Pi]))) + ((a + b*x)*Erfc[a + b*x])/b}
{x*Erfc[a + b*x], x, 5, a/(E^(a + b*x)^2*(2*b^2*Sqrt[Pi])) - x/(E^(a + b*x)^2*(2*b*Sqrt[Pi])) + Erf[a + b*x]/(4*b^2) + (a^2*Erf[a + b*x])/(2*b^2) + (1/2)*x^2*Erfc[a + b*x]}
{x^2*Erfc[a + b*x], x, 8, -(1/(E^(a + b*x)^2*(3*b^3*Sqrt[Pi]))) - a^2/(E^(a + b*x)^2*(3*b^3*Sqrt[Pi])) + (a*x)/(E^(a + b*x)^2*(3*b^2*Sqrt[Pi])) - x^2/(E^(a + b*x)^2*(3*b*Sqrt[Pi])) - (a*Erf[a + b*x])/(2*b^3) - (a^3*Erf[a + b*x])/(3*b^3) + (1/3)*x^3*Erfc[a + b*x]}
{x^3*Erfc[a + b*x], x, 13, (5*a)/(E^(a + b*x)^2*(8*b^4*Sqrt[Pi])) + a^3/(E^(a + b*x)^2*(4*b^4*Sqrt[Pi])) - (3*x)/(E^(a + b*x)^2*(8*b^3*Sqrt[Pi])) - (a^2*x)/(E^(a + b*x)^2*(4*b^3*Sqrt[Pi])) + (a*x^2)/(E^(a + b*x)^2*(4*b^2*Sqrt[Pi])) - x^3/(E^(a + b*x)^2*(4*b*Sqrt[Pi])) + (3*Erf[a + b*x])/(16*b^4) + (3*a^2*Erf[a + b*x])/(4*b^4) + (a^4*Erf[a + b*x])/(4*b^4) + (1/4)*x^4*Erfc[a + b*x]}


{Erfc[a + b*x]^2/x, x, 0, Int[Erfc[a + b*x]^2/x, x]}
{Erfc[a + b*x]^2, x, 4, -((Sqrt[2/Pi]*Erf[Sqrt[2]*(a + b*x)])/b) - (2*Erfc[a + b*x])/(E^(a + b*x)^2*(b*Sqrt[Pi])) + ((a + b*x)*Erfc[a + b*x]^2)/b}
{x*Erfc[a + b*x]^2, x, 10, 1/(E^(2*(a + b*x)^2)*(2*b^2*Pi)) + (a*Sqrt[2/Pi]*Erf[Sqrt[2]*(a + b*x)])/b^2 + (2*a*Erfc[a + b*x])/(E^(a + b*x)^2*(b^2*Sqrt[Pi])) - ((a + b*x)*Erfc[a + b*x])/(E^(a + b*x)^2*(b^2*Sqrt[Pi])) - Erfc[a + b*x]^2/(4*b^2) - (a*(a + b*x)*Erfc[a + b*x]^2)/b^2 + ((a + b*x)^2*Erfc[a + b*x]^2)/(2*b^2)}
{x^2*Erfc[a + b*x]^2, x, 16, -(a/(E^(2*(a + b*x)^2)*(b^3*Pi))) + (a + b*x)/(E^(2*(a + b*x)^2)*(3*b^3*Pi)) - (a^2*Sqrt[2/Pi]*Erf[Sqrt[2]*(a + b*x)])/b^3 - (5*Erf[Sqrt[2]*(a + b*x)])/(6*b^3*Sqrt[2*Pi]) - (2*Erfc[a + b*x])/(E^(a + b*x)^2*(3*b^3*Sqrt[Pi])) - (2*a^2*Erfc[a + b*x])/(E^(a + b*x)^2*(b^3*Sqrt[Pi])) + (2*a*(a + b*x)*Erfc[a + b*x])/(E^(a + b*x)^2*(b^3*Sqrt[Pi])) - (2*(a + b*x)^2*Erfc[a + b*x])/(E^(a + b*x)^2*(3*b^3*Sqrt[Pi])) + (a*Erfc[a + b*x]^2)/(2*b^3) + (a^2*(a + b*x)*Erfc[a + b*x]^2)/b^3 - (a*(a + b*x)^2*Erfc[a + b*x]^2)/b^3 + ((a + b*x)^3*Erfc[a + b*x]^2)/(3*b^3)}


{E^(-b^2*x^2)*Erfc[b*x]/x^8, x, 15, b/(E^(2*b^2*x^2)*(21*Sqrt[Pi]*x^6)) - (8*b^3)/(E^(2*b^2*x^2)*(105*Sqrt[Pi]*x^4)) + (4*b^5)/(E^(2*b^2*x^2)*(21*Sqrt[Pi]*x^2)) - Erfc[b*x]/(E^(b^2*x^2)*(7*x^7)) + (2*b^2*Erfc[b*x])/(E^(b^2*x^2)*(35*x^5)) - (4*b^4*Erfc[b*x])/(E^(b^2*x^2)*(105*x^3)) + (8*b^6*Erfc[b*x])/(E^(b^2*x^2)*(105*x)) - (4/105)*b^7*Sqrt[Pi]*Erfc[b*x]^2 + (16*b^7*ExpIntegralEi[-2*b^2*x^2])/(35*Sqrt[Pi])}
{E^(-b^2*x^2)*Erfc[b*x]/x^7, x, 12, b/(E^(2*b^2*x^2)*(15*Sqrt[Pi]*x^5)) - (13*b^3)/(E^(2*b^2*x^2)*(90*Sqrt[Pi]*x^3)) + (67*b^5)/(E^(2*b^2*x^2)*(90*Sqrt[Pi]*x)) + (b^6*Erf[Sqrt[2]*b*x])/(3*Sqrt[2]) + (26/45)*Sqrt[2]*b^6*Erf[Sqrt[2]*b*x] - Erfc[b*x]/(E^(b^2*x^2)*(6*x^6)) + (b^2*Erfc[b*x])/(E^(b^2*x^2)*(12*x^4)) - (b^4*Erfc[b*x])/(E^(b^2*x^2)*(12*x^2)) - (1/6)*b^6*Int[Erfc[b*x]/(E^(b^2*x^2)*x), x]}
{E^(-b^2*x^2)*Erfc[b*x]/x^6, x, 10, b/(E^(2*b^2*x^2)*(10*Sqrt[Pi]*x^4)) - b^3/(E^(2*b^2*x^2)*(3*Sqrt[Pi]*x^2)) - Erfc[b*x]/(E^(b^2*x^2)*(5*x^5)) + (2*b^2*Erfc[b*x])/(E^(b^2*x^2)*(15*x^3)) - (4*b^4*Erfc[b*x])/(E^(b^2*x^2)*(15*x)) + (2/15)*b^5*Sqrt[Pi]*Erfc[b*x]^2 - (14*b^5*ExpIntegralEi[-2*b^2*x^2])/(15*Sqrt[Pi])}
{E^(-b^2*x^2)*Erfc[b*x]/x^5, x, 7, b/(E^(2*b^2*x^2)*(6*Sqrt[Pi]*x^3)) - (7*b^3)/(E^(2*b^2*x^2)*(6*Sqrt[Pi]*x)) - (b^4*Erf[Sqrt[2]*b*x])/Sqrt[2] - (2/3)*Sqrt[2]*b^4*Erf[Sqrt[2]*b*x] - Erfc[b*x]/(E^(b^2*x^2)*(4*x^4)) + (b^2*Erfc[b*x])/(E^(b^2*x^2)*(4*x^2)) + (1/2)*b^4*Int[Erfc[b*x]/(E^(b^2*x^2)*x), x]}
{E^(-b^2*x^2)*Erfc[b*x]/x^4, x, 6, b/(E^(2*b^2*x^2)*(3*Sqrt[Pi]*x^2)) - Erfc[b*x]/(E^(b^2*x^2)*(3*x^3)) + (2*b^2*Erfc[b*x])/(E^(b^2*x^2)*(3*x)) - (1/3)*b^3*Sqrt[Pi]*Erfc[b*x]^2 + (4*b^3*ExpIntegralEi[-2*b^2*x^2])/(3*Sqrt[Pi])}
{E^(-b^2*x^2)*Erfc[b*x]/x^3, x, 3, b/(E^(2*b^2*x^2)*(Sqrt[Pi]*x)) + Sqrt[2]*b^2*Erf[Sqrt[2]*b*x] - Erfc[b*x]/(E^(b^2*x^2)*(2*x^2)) - b^2*Int[Erfc[b*x]/(E^(b^2*x^2)*x), x]}
{E^(-b^2*x^2)*Erfc[b*x]/x^2, x, 3, -(Erfc[b*x]/(E^(b^2*x^2)*x)) + (1/2)*b*Sqrt[Pi]*Erfc[b*x]^2 - (b*ExpIntegralEi[-2*b^2*x^2])/Sqrt[Pi]}
{E^(-b^2*x^2)*Erfc[b*x]/x, x, 0, Int[Erfc[b*x]/(E^(b^2*x^2)*x), x]}
{E^(-b^2*x^2)*Erfc[b*x], x, 1, -((Sqrt[Pi]*Erfc[b*x]^2)/(4*b))}
{x*E^(-b^2*x^2)*Erfc[b*x], x, 2, -(Erf[Sqrt[2]*b*x]/(2*Sqrt[2]*b^2)) - Erfc[b*x]/(E^(b^2*x^2)*(2*b^2))}
{x^2*E^(-b^2*x^2)*Erfc[b*x], x, 3, 1/(E^(2*b^2*x^2)*(4*b^3*Sqrt[Pi])) - (x*Erfc[b*x])/(E^(b^2*x^2)*(2*b^2)) - (Sqrt[Pi]*Erfc[b*x]^2)/(8*b^3)}
{x^3*E^(-b^2*x^2)*Erfc[b*x], x, 5, x/(E^(2*b^2*x^2)*(4*b^3*Sqrt[Pi])) - (5*Erf[Sqrt[2]*b*x])/(8*Sqrt[2]*b^4) - Erfc[b*x]/(E^(b^2*x^2)*(2*b^4)) - (x^2*Erfc[b*x])/(E^(b^2*x^2)*(2*b^2))}
{x^4*E^(-b^2*x^2)*Erfc[b*x], x, 6, 1/(E^(2*b^2*x^2)*(2*b^5*Sqrt[Pi])) + x^2/(E^(2*b^2*x^2)*(4*b^3*Sqrt[Pi])) - (3*x*Erfc[b*x])/(E^(b^2*x^2)*(4*b^4)) - (x^3*Erfc[b*x])/(E^(b^2*x^2)*(2*b^2)) - (3*Sqrt[Pi]*Erfc[b*x]^2)/(16*b^5)}
{x^5*E^(-b^2*x^2)*Erfc[b*x], x, 9, (11*x)/(E^(2*b^2*x^2)*(16*b^5*Sqrt[Pi])) + x^3/(E^(2*b^2*x^2)*(4*b^3*Sqrt[Pi])) - (43*Erf[Sqrt[2]*b*x])/(32*Sqrt[2]*b^6) - Erfc[b*x]/(E^(b^2*x^2)*b^6) - (x^2*Erfc[b*x])/(E^(b^2*x^2)*b^4) - (x^4*Erfc[b*x])/(E^(b^2*x^2)*(2*b^2))}
{x^6*E^(-b^2*x^2)*Erfc[b*x], x, 10, 11/(E^(2*b^2*x^2)*(8*b^7*Sqrt[Pi])) + (7*x^2)/(E^(2*b^2*x^2)*(8*b^5*Sqrt[Pi])) + x^4/(E^(2*b^2*x^2)*(4*b^3*Sqrt[Pi])) - (15*x*Erfc[b*x])/(E^(b^2*x^2)*(8*b^6)) - (5*x^3*Erfc[b*x])/(E^(b^2*x^2)*(4*b^4)) - (x^5*Erfc[b*x])/(E^(b^2*x^2)*(2*b^2)) - (15*Sqrt[Pi]*Erfc[b*x]^2)/(32*b^7)}


(* ::Subsection::Closed:: *)
(*Imaginary Error function*)


{Erfi[b*x]^2/x^8, x, 0, Int[Erfi[b*x]^2/x^8, x]}
{Erfi[b*x]^2/x^7, x, 11, -((b^2*E^(2*b^2*x^2))/(15*Pi*x^4)) - (2*b^4*E^(2*b^2*x^2))/(9*Pi*x^2) - (2*b*E^(b^2*x^2)*Erfi[b*x])/(15*Sqrt[Pi]*x^5) - (4*b^3*E^(b^2*x^2)*Erfi[b*x])/(45*Sqrt[Pi]*x^3) - (8*b^5*E^(b^2*x^2)*Erfi[b*x])/(45*Sqrt[Pi]*x) + (4/45)*b^6*Erfi[b*x]^2 - Erfi[b*x]^2/(6*x^6) + (28*b^6*ExpIntegralEi[2*b^2*x^2])/(45*Pi)}
{Erfi[b*x]^2/x^6, x, 0, Int[Erfi[b*x]^2/x^6, x]}
{Erfi[b*x]^2/x^5, x, 7, -((b^2*E^(2*b^2*x^2))/(3*Pi*x^2)) - (b*E^(b^2*x^2)*Erfi[b*x])/(3*Sqrt[Pi]*x^3) - (2*b^3*E^(b^2*x^2)*Erfi[b*x])/(3*Sqrt[Pi]*x) + (1/3)*b^4*Erfi[b*x]^2 - Erfi[b*x]^2/(4*x^4) + (4*b^4*ExpIntegralEi[2*b^2*x^2])/(3*Pi)}
{Erfi[b*x]^2/x^4, x, 0, Int[Erfi[b*x]^2/x^4, x]}
{Erfi[b*x]^2/x^3, x, 4, -((2*b*E^(b^2*x^2)*Erfi[b*x])/(Sqrt[Pi]*x)) + b^2*Erfi[b*x]^2 - Erfi[b*x]^2/(2*x^2) + (2*b^2*ExpIntegralEi[2*b^2*x^2])/Pi}
{Erfi[b*x]^2/x^2, x, 0, Int[Erfi[b*x]^2/x^2, x]}
{Erfi[b*x]^2/x, x, 0, Int[Erfi[b*x]^2/x, x]}
{Erfi[b*x]^2, x, 4, -((2*E^(b^2*x^2)*Erfi[b*x])/(b*Sqrt[Pi])) + x*Erfi[b*x]^2 + (Sqrt[2/Pi]*Erfi[Sqrt[2]*b*x])/b}
{x*Erfi[b*x]^2, x, 4, E^(2*b^2*x^2)/(2*b^2*Pi) - (E^(b^2*x^2)*x*Erfi[b*x])/(b*Sqrt[Pi]) + Erfi[b*x]^2/(4*b^2) + (1/2)*x^2*Erfi[b*x]^2}
{x^2*Erfi[b*x]^2, x, 6, (E^(2*b^2*x^2)*x)/(3*b^2*Pi) + (2*E^(b^2*x^2)*Erfi[b*x])/(3*b^3*Sqrt[Pi]) - (2*E^(b^2*x^2)*x^2*Erfi[b*x])/(3*b*Sqrt[Pi]) + (1/3)*x^3*Erfi[b*x]^2 - (5*Erfi[Sqrt[2]*b*x])/(6*b^3*Sqrt[2*Pi])}
{x^3*Erfi[b*x]^2, x, 7, -(E^(2*b^2*x^2)/(2*b^4*Pi)) + (E^(2*b^2*x^2)*x^2)/(4*b^2*Pi) + (3*E^(b^2*x^2)*x*Erfi[b*x])/(4*b^3*Sqrt[Pi]) - (E^(b^2*x^2)*x^3*Erfi[b*x])/(2*b*Sqrt[Pi]) - (3*Erfi[b*x]^2)/(16*b^4) + (1/4)*x^4*Erfi[b*x]^2}
{x^4*Erfi[b*x]^2, x, 10, -((11*E^(2*b^2*x^2)*x)/(20*b^4*Pi)) + (E^(2*b^2*x^2)*x^3)/(5*b^2*Pi) - (4*E^(b^2*x^2)*Erfi[b*x])/(5*b^5*Sqrt[Pi]) + (4*E^(b^2*x^2)*x^2*Erfi[b*x])/(5*b^3*Sqrt[Pi]) - (2*E^(b^2*x^2)*x^4*Erfi[b*x])/(5*b*Sqrt[Pi]) + (1/5)*x^5*Erfi[b*x]^2 + (43*Erfi[Sqrt[2]*b*x])/(40*b^5*Sqrt[2*Pi])}
{x^5*Erfi[b*x]^2, x, 11, (11*E^(2*b^2*x^2))/(12*b^6*Pi) - (7*E^(2*b^2*x^2)*x^2)/(12*b^4*Pi) + (E^(2*b^2*x^2)*x^4)/(6*b^2*Pi) - (5*E^(b^2*x^2)*x*Erfi[b*x])/(4*b^5*Sqrt[Pi]) + (5*E^(b^2*x^2)*x^3*Erfi[b*x])/(6*b^3*Sqrt[Pi]) - (E^(b^2*x^2)*x^5*Erfi[b*x])/(3*b*Sqrt[Pi]) + (5*Erfi[b*x]^2)/(16*b^6) + (1/6)*x^6*Erfi[b*x]^2}


{Erfi[a + b*x]/x, x, 0, Int[Erfi[a + b*x]/x, x]}
{Erfi[a + b*x], x, 1, -(E^(a + b*x)^2/(b*Sqrt[Pi])) + ((a + b*x)*Erfi[a + b*x])/b}
{x*Erfi[a + b*x], x, 5, (a*E^(a + b*x)^2)/(2*b^2*Sqrt[Pi]) - (E^(a + b*x)^2*x)/(2*b*Sqrt[Pi]) + Erfi[a + b*x]/(4*b^2) - (a^2*Erfi[a + b*x])/(2*b^2) + (1/2)*x^2*Erfi[a + b*x]}
{x^2*Erfi[a + b*x], x, 8, E^(a + b*x)^2/(3*b^3*Sqrt[Pi]) - (a^2*E^(a + b*x)^2)/(3*b^3*Sqrt[Pi]) + (a*E^(a + b*x)^2*x)/(3*b^2*Sqrt[Pi]) - (E^(a + b*x)^2*x^2)/(3*b*Sqrt[Pi]) - (a*Erfi[a + b*x])/(2*b^3) + (a^3*Erfi[a + b*x])/(3*b^3) + (1/3)*x^3*Erfi[a + b*x]}
{x^3*Erfi[a + b*x], x, 13, -((5*a*E^(a + b*x)^2)/(8*b^4*Sqrt[Pi])) + (a^3*E^(a + b*x)^2)/(4*b^4*Sqrt[Pi]) + (3*E^(a + b*x)^2*x)/(8*b^3*Sqrt[Pi]) - (a^2*E^(a + b*x)^2*x)/(4*b^3*Sqrt[Pi]) + (a*E^(a + b*x)^2*x^2)/(4*b^2*Sqrt[Pi]) - (E^(a + b*x)^2*x^3)/(4*b*Sqrt[Pi]) - (3*Erfi[a + b*x])/(16*b^4) + (3*a^2*Erfi[a + b*x])/(4*b^4) - (a^4*Erfi[a + b*x])/(4*b^4) + (1/4)*x^4*Erfi[a + b*x]}


{Erfi[a + b*x]^2/x, x, 0, Int[Erfi[a + b*x]^2/x, x]}
{Erfi[a + b*x]^2, x, 4, -((2*E^(a + b*x)^2*Erfi[a + b*x])/(b*Sqrt[Pi])) + ((a + b*x)*Erfi[a + b*x]^2)/b + (Sqrt[2/Pi]*Erfi[Sqrt[2]*(a + b*x)])/b}
{x*Erfi[a + b*x]^2, x, 10, E^(2*(a + b*x)^2)/(2*b^2*Pi) + (2*a*E^(a + b*x)^2*Erfi[a + b*x])/(b^2*Sqrt[Pi]) - (E^(a + b*x)^2*(a + b*x)*Erfi[a + b*x])/(b^2*Sqrt[Pi]) + Erfi[a + b*x]^2/(4*b^2) - (a*(a + b*x)*Erfi[a + b*x]^2)/b^2 + ((a + b*x)^2*Erfi[a + b*x]^2)/(2*b^2) - (a*Sqrt[2/Pi]*Erfi[Sqrt[2]*(a + b*x)])/b^2}
{x^2*Erfi[a + b*x]^2, x, 16, -((a*E^(2*(a + b*x)^2))/(b^3*Pi)) + (E^(2*(a + b*x)^2)*(a + b*x))/(3*b^3*Pi) + (2*E^(a + b*x)^2*Erfi[a + b*x])/(3*b^3*Sqrt[Pi]) - (2*a^2*E^(a + b*x)^2*Erfi[a + b*x])/(b^3*Sqrt[Pi]) + (2*a*E^(a + b*x)^2*(a + b*x)*Erfi[a + b*x])/(b^3*Sqrt[Pi]) - (2*E^(a + b*x)^2*(a + b*x)^2*Erfi[a + b*x])/(3*b^3*Sqrt[Pi]) - (a*Erfi[a + b*x]^2)/(2*b^3) + (a^2*(a + b*x)*Erfi[a + b*x]^2)/b^3 - (a*(a + b*x)^2*Erfi[a + b*x]^2)/b^3 + ((a + b*x)^3*Erfi[a + b*x]^2)/(3*b^3) + (a^2*Sqrt[2/Pi]*Erfi[Sqrt[2]*(a + b*x)])/b^3 - (5*Erfi[Sqrt[2]*(a + b*x)])/(6*b^3*Sqrt[2*Pi])}


{E^(b^2*x^2)*Erfi[b*x]/x^8, x, 15, -((b*E^(2*b^2*x^2))/(21*Sqrt[Pi]*x^6)) - (8*b^3*E^(2*b^2*x^2))/(105*Sqrt[Pi]*x^4) - (4*b^5*E^(2*b^2*x^2))/(21*Sqrt[Pi]*x^2) - (E^(b^2*x^2)*Erfi[b*x])/(7*x^7) - (2*b^2*E^(b^2*x^2)*Erfi[b*x])/(35*x^5) - (4*b^4*E^(b^2*x^2)*Erfi[b*x])/(105*x^3) - (8*b^6*E^(b^2*x^2)*Erfi[b*x])/(105*x) + (4/105)*b^7*Sqrt[Pi]*Erfi[b*x]^2 + (16*b^7*ExpIntegralEi[2*b^2*x^2])/(35*Sqrt[Pi])}
{E^(b^2*x^2)*Erfi[b*x]/x^7, x, 12, -((b*E^(2*b^2*x^2))/(15*Sqrt[Pi]*x^5)) - (13*b^3*E^(2*b^2*x^2))/(90*Sqrt[Pi]*x^3) - (67*b^5*E^(2*b^2*x^2))/(90*Sqrt[Pi]*x) - (E^(b^2*x^2)*Erfi[b*x])/(6*x^6) - (b^2*E^(b^2*x^2)*Erfi[b*x])/(12*x^4) - (b^4*E^(b^2*x^2)*Erfi[b*x])/(12*x^2) + (b^6*Erfi[Sqrt[2]*b*x])/(3*Sqrt[2]) + (26/45)*Sqrt[2]*b^6*Erfi[Sqrt[2]*b*x] + (1/6)*b^6*Int[(E^(b^2*x^2)*Erfi[b*x])/x, x]}
{E^(b^2*x^2)*Erfi[b*x]/x^6, x, 10, -((b*E^(2*b^2*x^2))/(10*Sqrt[Pi]*x^4)) - (b^3*E^(2*b^2*x^2))/(3*Sqrt[Pi]*x^2) - (E^(b^2*x^2)*Erfi[b*x])/(5*x^5) - (2*b^2*E^(b^2*x^2)*Erfi[b*x])/(15*x^3) - (4*b^4*E^(b^2*x^2)*Erfi[b*x])/(15*x) + (2/15)*b^5*Sqrt[Pi]*Erfi[b*x]^2 + (14*b^5*ExpIntegralEi[2*b^2*x^2])/(15*Sqrt[Pi])}
{E^(b^2*x^2)*Erfi[b*x]/x^5, x, 7, -((b*E^(2*b^2*x^2))/(6*Sqrt[Pi]*x^3)) - (7*b^3*E^(2*b^2*x^2))/(6*Sqrt[Pi]*x) - (E^(b^2*x^2)*Erfi[b*x])/(4*x^4) - (b^2*E^(b^2*x^2)*Erfi[b*x])/(4*x^2) + (b^4*Erfi[Sqrt[2]*b*x])/Sqrt[2] + (2/3)*Sqrt[2]*b^4*Erfi[Sqrt[2]*b*x] + (1/2)*b^4*Int[(E^(b^2*x^2)*Erfi[b*x])/x, x]}
{E^(b^2*x^2)*Erfi[b*x]/x^4, x, 6, -((b*E^(2*b^2*x^2))/(3*Sqrt[Pi]*x^2)) - (E^(b^2*x^2)*Erfi[b*x])/(3*x^3) - (2*b^2*E^(b^2*x^2)*Erfi[b*x])/(3*x) + (1/3)*b^3*Sqrt[Pi]*Erfi[b*x]^2 + (4*b^3*ExpIntegralEi[2*b^2*x^2])/(3*Sqrt[Pi])}
{E^(b^2*x^2)*Erfi[b*x]/x^3, x, 3, -((b*E^(2*b^2*x^2))/(Sqrt[Pi]*x)) - (E^(b^2*x^2)*Erfi[b*x])/(2*x^2) + Sqrt[2]*b^2*Erfi[Sqrt[2]*b*x] + b^2*Int[(E^(b^2*x^2)*Erfi[b*x])/x, x]}
{E^(b^2*x^2)*Erfi[b*x]/x^2, x, 3, -((E^(b^2*x^2)*Erfi[b*x])/x) + (1/2)*b*Sqrt[Pi]*Erfi[b*x]^2 + (b*ExpIntegralEi[2*b^2*x^2])/Sqrt[Pi]}
{E^(b^2*x^2)*Erfi[b*x]/x, x, 0, Int[(E^(b^2*x^2)*Erfi[b*x])/x, x]}
{E^(b^2*x^2)*Erfi[b*x], x, 1, (Sqrt[Pi]*Erfi[b*x]^2)/(4*b)}
{x*E^(b^2*x^2)*Erfi[b*x], x, 2, (E^(b^2*x^2)*Erfi[b*x])/(2*b^2) - Erfi[Sqrt[2]*b*x]/(2*Sqrt[2]*b^2)}
{x^2*E^(b^2*x^2)*Erfi[b*x], x, 3, -(E^(2*b^2*x^2)/(4*b^3*Sqrt[Pi])) + (E^(b^2*x^2)*x*Erfi[b*x])/(2*b^2) - (Sqrt[Pi]*Erfi[b*x]^2)/(8*b^3)}
{x^3*E^(b^2*x^2)*Erfi[b*x], x, 5, -((E^(2*b^2*x^2)*x)/(4*b^3*Sqrt[Pi])) - (E^(b^2*x^2)*Erfi[b*x])/(2*b^4) + (E^(b^2*x^2)*x^2*Erfi[b*x])/(2*b^2) + (5*Erfi[Sqrt[2]*b*x])/(8*Sqrt[2]*b^4)}
{x^4*E^(b^2*x^2)*Erfi[b*x], x, 6, E^(2*b^2*x^2)/(2*b^5*Sqrt[Pi]) - (E^(2*b^2*x^2)*x^2)/(4*b^3*Sqrt[Pi]) - (3*E^(b^2*x^2)*x*Erfi[b*x])/(4*b^4) + (E^(b^2*x^2)*x^3*Erfi[b*x])/(2*b^2) + (3*Sqrt[Pi]*Erfi[b*x]^2)/(16*b^5)}
{x^5*E^(b^2*x^2)*Erfi[b*x], x, 9, (11*E^(2*b^2*x^2)*x)/(16*b^5*Sqrt[Pi]) - (E^(2*b^2*x^2)*x^3)/(4*b^3*Sqrt[Pi]) + (E^(b^2*x^2)*Erfi[b*x])/b^6 - (E^(b^2*x^2)*x^2*Erfi[b*x])/b^4 + (E^(b^2*x^2)*x^4*Erfi[b*x])/(2*b^2) - (43*Erfi[Sqrt[2]*b*x])/(32*Sqrt[2]*b^6)}
{x^6*E^(b^2*x^2)*Erfi[b*x], x, 10, -((11*E^(2*b^2*x^2))/(8*b^7*Sqrt[Pi])) + (7*E^(2*b^2*x^2)*x^2)/(8*b^5*Sqrt[Pi]) - (E^(2*b^2*x^2)*x^4)/(4*b^3*Sqrt[Pi]) + (15*E^(b^2*x^2)*x*Erfi[b*x])/(8*b^6) - (5*E^(b^2*x^2)*x^3*Erfi[b*x])/(4*b^4) + (E^(b^2*x^2)*x^5*Erfi[b*x])/(2*b^2) - (15*Sqrt[Pi]*Erfi[b*x]^2)/(32*b^7)}
