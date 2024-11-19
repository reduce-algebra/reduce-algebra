(* ::Package:: *)

{x^3/(1 + I*Tan[x]), x, 0, 0}
{x^2/(1 + I*Tan[x]), x, 0, 0}
{x/(1 + I*Tan[x]), x, 0, -I*x/4 + x^2/4 + (1 + 2*I*x)/(4*(1 + I*Tan[x]))}
{1/(1 + I*Tan[x]), x, 1, x/2 + I/(2*(1 + I*Tan[x]))}


{x^3/(1 + I*Cot[x]), x, 0, 0}
{x^2/(1 + I*Cot[x]), x, 0, 0}
{x/(1 + I*Cot[x]), x, 0, I*x/4 + x^2/4 + (1 - 2*I*x)/(4*(1 + I*Cot[x]))}
{1/(1 + I*Cot[x]), x, 1, x/2 - I/(2*(1 + I*Cot[x]))}


{x^3/(1 + Tanh[x]), x, 0, (3*x)/8 + (3*x^2)/8 + x^3/4 + x^4/8 + (-3 - 6*x - 6*x^2 - 4*x^3)/(8*(1 + Tanh[x]))}
{x^2/(1 + Tanh[x]), x, 0, x/4 + x^2/4 + x^3/6 + (-1 - 2*x - 2*x^2)/(4*(1 + Tanh[x]))}
{x/(1 + Tanh[x]), x, 0, x/4 + x^2/4 - (1 + 2*x)/(4*(1 + Tanh[x]))}
{1/(1 + Tanh[x]), x, 1, x/2 - 1/(2*(1 + Tanh[x]))}


{x^3/(1 + Coth[x]), x, 0, (3*x)/8 + (3*x^2)/8 + x^3/4 + x^4/8 + (-3 - 6*x - 6*x^2 - 4*x^3)/(8*(1 + Coth[x]))}
{x^2/(1 + Coth[x]), x, 0, x/4 + x^2/4 + x^3/6 + (-1 - 2*x - 2*x^2)/(4*(1 + Coth[x]))}
{x/(1 + Coth[x]), x, 0, x/4 + x^2/4 - (1 + 2*x)/(4*(1 + Coth[x]))}
{1/(1 + Coth[x]), x, 1, x/2 - 1/(2*(1 + Coth[x]))}


{Tan[x]/(1 + Tan[x])^2, x, 0, x/2 + 1/(2*(1 + Tan[x]))}
{Tan[x]/(1 - Tan[x])^2, x, 0, -(x/2) + 1/(2*(1 - Tan[x]))}


{Cot[x]/(1 + Cot[x])^2, x, 0, x/2 + 1/(2*(1 + Cot[x]))}
{Cot[x]/(1 - Cot[x])^2, x, 0, -(x/2) + 1/(2*(1 - Cot[x]))}


{Tanh[x]/(1 + Tanh[x])^2, x, 0, x/2 + 1/(2*(1 + Tanh[x]))}
{Tanh[x]/(1 - Tanh[x])^2, x, 0, -(x/2) + 1/(2*(1 - Tanh[x]))}


{Coth[x]/(1 + Coth[x])^2, x, 0, x/2 + 1/(2*(1 + Coth[x]))}
{Coth[x]/(1 - Coth[x])^2, x, 0, -(x/2) + 1/(2*(1 - Coth[x]))}


(* Integrands of the form (a+b*Cosh[c+d*x])^n where n is a half- integer *)
{(a + b*Cosh[x])^(5/2), x, 8, -((2*I*(23*a^2 + 9*b^2)*Sqrt[a + b*Cosh[x]]*EllipticE[(I*x)/2, (2*b)/(a + b)])/(15*Sqrt[(a + b*Cosh[x])/(a + b)])) + (16*I*a*(a^2 - b^2)*Sqrt[(a + b*Cosh[x])/(a + b)]*EllipticF[(I*x)/2, (2*b)/(a + b)])/(15*Sqrt[a + b*Cosh[x]]) + (16/15)*a*b*Sqrt[a + b*Cosh[x]]*Sinh[x] + (2/5)*b*(a + b*Cosh[x])^(3/2)*Sinh[x]}
{(a + b*Cosh[x])^(3/2), x, 5, -((8*I*a*Sqrt[a + b*Cosh[x]]*EllipticE[(I*x)/2, (2*b)/(a + b)])/(3*Sqrt[(a + b*Cosh[x])/(a + b)])) + (2*I*(a^2 - b^2)*Sqrt[(a + b*Cosh[x])/(a + b)]*EllipticF[(I*x)/2, (2*b)/(a + b)])/(3*Sqrt[a + b*Cosh[x]]) + (2/3)*b*Sqrt[a + b*Cosh[x]]*Sinh[x]}
{(a + b*Cosh[c + d*x])^(1/2), x, 2, -((2*I*Sqrt[a + b*Cosh[c + d*x]]*EllipticE[(1/2)*I*(c + d*x), (2*b)/(a + b)])/(d*Sqrt[(a + b*Cosh[c + d*x])/(a + b)]))}
{1/(a + b*Cosh[x])^(1/2), x, 2, -((2*I*Sqrt[(a + b*Cosh[x])/(a + b)]*EllipticF[(I*x)/2, (2*b)/(a + b)])/Sqrt[a + b*Cosh[x]])}
{1/(a + b*Cosh[x])^(3/2), x, 5, -((2*I*Sqrt[a + b*Cosh[x]]*EllipticE[(I*x)/2, (2*b)/(a + b)])/((a^2 - b^2)*Sqrt[(a + b*Cosh[x])/(a + b)])) - (2*b*Sinh[x])/((a^2 - b^2)*Sqrt[a + b*Cosh[x]])}
{1/(a + b*Cosh[x])^(5/2), x, 7, -((8*I*a*Sqrt[a + b*Cosh[x]]*EllipticE[(I*x)/2, (2*b)/(a + b)])/(3*(a^2 - b^2)^2*Sqrt[(a + b*Cosh[x])/(a + b)])) + (2*I*Sqrt[(a + b*Cosh[x])/(a + b)]*EllipticF[(I*x)/2, (2*b)/(a + b)])/(3*(a^2 - b^2)*Sqrt[a + b*Cosh[x]]) - (2*b*Sinh[x])/(3*(a^2 - b^2)*(a + b*Cosh[x])^(3/2)) - (8*a*b*Sinh[x])/(3*(a^2 - b^2)^2*Sqrt[a + b*Cosh[x]])}
{1/(a + b*Cosh[x])^(7/2), x, 8, -((2*I*(23*a^2 + 9*b^2)*Sqrt[a + b*Cosh[x]]*EllipticE[(I*x)/2, (2*b)/(a + b)])/(15*(a^2 - b^2)^3*Sqrt[(a + b*Cosh[x])/(a + b)])) + (16*I*a*Sqrt[(a + b*Cosh[x])/(a + b)]*EllipticF[(I*x)/2, (2*b)/(a + b)])/(15*(a^2 - b^2)^2*Sqrt[a + b*Cosh[x]]) - (2*b*Sinh[x])/(5*(a^2 - b^2)*(a + b*Cosh[x])^(5/2)) - (16*a*b*Sinh[x])/(15*(a^2 - b^2)^2*(a + b*Cosh[x])^(3/2)) - (2*b*(23*a^2 + 9*b^2)*Sinh[x])/(15*(a^2 - b^2)^3*Sqrt[a + b*Cosh[x]])}

{(a + a*Cosh[c + d*x])^(5/2), x, 3, (64*a^3*Sinh[c + d*x])/(15*d*Sqrt[a + a*Cosh[c + d*x]]) + (16*a^2*Sqrt[a + a*Cosh[c + d*x]]*Sinh[c + d*x])/(15*d) + (2*a*(a + a*Cosh[c + d*x])^(3/2)*Sinh[c + d*x])/(5*d)}
{(a + a*Cosh[c + d*x])^(3/2), x, 2, (8*a^2*Sinh[c + d*x])/(3*d*Sqrt[a + a*Cosh[c + d*x]]) + (2*a*Sqrt[a + a*Cosh[c + d*x]]*Sinh[c + d*x])/(3*d)}
{(a + a*Cosh[c + d*x])^(1/2), x, 1, (2*a*Sinh[c + d*x])/(d*Sqrt[a + a*Cosh[c + d*x]])}
{1/(a + a*Cosh[c + d*x])^(1/2), x, 1, (2*ArcTan[Sinh[(1/2)*(c + d*x)]]*Cosh[(1/2)*(c + d*x)])/(d*Sqrt[a + a*Cosh[c + d*x]])}
{1/(a + a*Cosh[c + d*x])^(3/2), x, 2, (ArcTan[Sinh[(1/2)*(c + d*x)]]*Cosh[(1/2)*(c + d*x)])/(2*a*d*Sqrt[a + a*Cosh[c + d*x]]) + Sinh[c + d*x]/(2*d*(a + a*Cosh[c + d*x])^(3/2))}
{1/(a + a*Cosh[c + d*x])^(5/2), x, 3, (3*ArcTan[Sinh[(1/2)*(c + d*x)]]*Cosh[(1/2)*(c + d*x)])/(16*a^2*d*Sqrt[a + a*Cosh[c + d*x]]) + Sinh[c + d*x]/(4*d*(a + a*Cosh[c + d*x])^(5/2)) + (3*Sinh[c + d*x])/(16*a*d*(a + a*Cosh[c + d*x])^(3/2))}

{(a - a*Cosh[c + d*x])^(5/2), x, 3, -((64*a^3*Sinh[c + d*x])/(15*d*Sqrt[a - a*Cosh[c + d*x]])) - (16*a^2*Sqrt[a - a*Cosh[c + d*x]]*Sinh[c + d*x])/(15*d) - (2*a*(a - a*Cosh[c + d*x])^(3/2)*Sinh[c + d*x])/(5*d)}
{(a - a*Cosh[c + d*x])^(3/2), x, 2, -((8*a^2*Sinh[c + d*x])/(3*d*Sqrt[a - a*Cosh[c + d*x]])) - (2*a*Sqrt[a - a*Cosh[c + d*x]]*Sinh[c + d*x])/(3*d)}
{(a - a*Cosh[c + d*x])^(1/2), x, 1, -((2*a*Sinh[c + d*x])/(d*Sqrt[a - a*Cosh[c + d*x]]))}
{1/(a - a*Cosh[c + d*x])^(1/2), x, 1, -((2*ArcTanh[Cosh[(1/2)*(c + d*x)]]*Sinh[(1/2)*(c + d*x)])/(d*Sqrt[a - a*Cosh[c + d*x]]))}
{1/(a - a*Cosh[c + d*x])^(3/2), x, 2, -((ArcTanh[Cosh[(1/2)*(c + d*x)]]*Sinh[(1/2)*(c + d*x)])/(2*a*d*Sqrt[a - a*Cosh[c + d*x]])) - Sinh[c + d*x]/(2*d*(a - a*Cosh[c + d*x])^(3/2))}
{1/(a - a*Cosh[c + d*x])^(5/2), x, 3, -((3*ArcTanh[Cosh[(1/2)*(c + d*x)]]*Sinh[(1/2)*(c + d*x)])/(16*a^2*d*Sqrt[a - a*Cosh[c + d*x]])) - Sinh[c + d*x]/(4*d*(a - a*Cosh[c + d*x])^(5/2)) - (3*Sinh[c + d*x])/(16*a*d*(a - a*Cosh[c + d*x])^(3/2))}


{(Cos[x]*Sin[x])/Sqrt[x], x, 0, (1/2)*Sqrt[Pi]*FresnelS[(2*Sqrt[x])/Sqrt[Pi]]}


{x^4*Sin[a + b*x^2]^2, x, 7, -((3*x)/(32*b^2)) + x^5/10 + (3*Sqrt[Pi]*Cos[2*a]*FresnelC[(2*Sqrt[b]*x)/Sqrt[Pi]])/(64*b^(5/2)) - (3*Sqrt[Pi]*FresnelS[(2*Sqrt[b]*x)/Sqrt[Pi]]*Sin[2*a])/(64*b^(5/2)) - (x^3*Cos[a + b*x^2]*Sin[a + b*x^2])/(4*b) + (3*x*Sin[a + b*x^2]^2)/(16*b^2)}
{x^3*Sin[a + b*x^2]^2, x, 2, x^4/8 - (x^2*Cos[a + b*x^2]*Sin[a + b*x^2])/(4*b) + Sin[a + b*x^2]^2/(8*b^2)}
{x^2*Sin[a + b*x^2]^2, x, 7, x^3/6 + (Sqrt[Pi]*Cos[2*a]*FresnelS[(2*Sqrt[b]*x)/Sqrt[Pi]])/(16*b^(3/2)) + (Sqrt[Pi]*FresnelC[(2*Sqrt[b]*x)/Sqrt[Pi]]*Sin[2*a])/(16*b^(3/2)) - (x*Sin[2*a + 2*b*x^2])/(8*b)}
{x*Sin[a + b*x^2]^2, x, 2, x^2/4 - (Cos[a + b*x^2]*Sin[a + b*x^2])/(4*b)}
{Sin[a + b*x^2]^2, x, 5, x/2 - (Sqrt[Pi]*Cos[2*a]*FresnelC[(2*Sqrt[b]*x)/Sqrt[Pi]])/(4*Sqrt[b]) + (Sqrt[Pi]*FresnelS[(2*Sqrt[b]*x)/Sqrt[Pi]]*Sin[2*a])/(4*Sqrt[b])}
{Sin[a + b*x^2]^2/x, x, 7, (-(1/4))*Cos[2*a]*CosIntegral[2*b*x^2] + Log[x^2]/4 + (1/4)*Sin[2*a]*SinIntegral[2*b*x^2]}
{Sin[a + b*x^2]^2/x^2, x, 7, -(1/(2*x)) + Cos[2*a + 2*b*x^2]/(2*x) + Sqrt[b]*Sqrt[Pi]*Cos[2*a]*FresnelS[(2*Sqrt[b]*x)/Sqrt[Pi]] + Sqrt[b]*Sqrt[Pi]*FresnelC[(2*Sqrt[b]*x)/Sqrt[Pi]]*Sin[2*a]}
{Sin[a + b*x^2]^2/x^3, x, 8, -(1/(4*x^2)) + Cos[2*a + 2*b*x^2]/(4*x^2) + (1/2)*b*CosIntegral[2*b*x^2]*Sin[2*a] + (1/2)*b*Cos[2*a]*SinIntegral[2*b*x^2]}
{Sin[a + b*x^2]^2/x^4, x, 7, (4/3)*b^(3/2)*Sqrt[Pi]*Cos[2*a]*FresnelC[(2*Sqrt[b]*x)/Sqrt[Pi]] - (4/3)*b^(3/2)*Sqrt[Pi]*FresnelS[(2*Sqrt[b]*x)/Sqrt[Pi]]*Sin[2*a] - (4*b*Cos[a + b*x^2]*Sin[a + b*x^2])/(3*x) - Sin[a + b*x^2]^2/(3*x^3)}


{Sin[a+b*x]/x^(3/2), x, 5, 2*Sqrt[b]*Sqrt[2*Pi]*Cos[a]*FresnelC[Sqrt[b]*Sqrt[2/Pi]*Sqrt[x]] - 2*Sqrt[b]*Sqrt[2*Pi]*FresnelS[Sqrt[b]*Sqrt[2/Pi]*Sqrt[x]]*Sin[a] - (2*Sin[a + b*x])/Sqrt[x]}
{Sin[a+b*x]^2/x^(3/2), x, 8, -(1/Sqrt[x]) + Cos[2*a + 2*b*x]/Sqrt[x] + 2*Sqrt[b]*Sqrt[Pi]*Cos[2*a]*FresnelS[(2*Sqrt[b]*Sqrt[x])/Sqrt[Pi]] + 2*Sqrt[b]*Sqrt[Pi]*FresnelC[(2*Sqrt[b]*Sqrt[x])/Sqrt[Pi]]*Sin[2*a]}
{Sin[a+b*x]^3/x^(3/2), x, 11, 3*Sqrt[b]*Sqrt[Pi/2]*Cos[a]*FresnelC[Sqrt[b]*Sqrt[2/Pi]*Sqrt[x]] - Sqrt[b]*Sqrt[(3*Pi)/2]*Cos[3*a]*FresnelC[Sqrt[b]*Sqrt[6/Pi]*Sqrt[x]] - 3*Sqrt[b]*Sqrt[Pi/2]*FresnelS[Sqrt[b]*Sqrt[2/Pi]*Sqrt[x]]*Sin[a] + Sqrt[b]*Sqrt[(3*Pi)/2]*FresnelS[Sqrt[b]*Sqrt[6/Pi]*Sqrt[x]]*Sin[3*a] - (3*Sin[a + b*x])/(2*Sqrt[x]) + Sin[3*a + 3*b*x]/(2*Sqrt[x])}
{Sin[a+b*x]^4/x^(3/2), x, 14, -(3/(4*Sqrt[x])) + Cos[2*a + 2*b*x]/Sqrt[x] - Cos[4*a + 4*b*x]/(4*Sqrt[x]) - Sqrt[b]*Sqrt[Pi/2]*Cos[4*a]*FresnelS[2*Sqrt[b]*Sqrt[2/Pi]*Sqrt[x]] + 2*Sqrt[b]*Sqrt[Pi]*Cos[2*a]*FresnelS[(2*Sqrt[b]*Sqrt[x])/Sqrt[Pi]] + 2*Sqrt[b]*Sqrt[Pi]*FresnelC[(2*Sqrt[b]*Sqrt[x])/Sqrt[Pi]]*Sin[2*a] - Sqrt[b]*Sqrt[Pi/2]*FresnelC[2*Sqrt[b]*Sqrt[2/Pi]*Sqrt[x]]*Sin[4*a]}


{Cos[a+b*x]/x^(3/2), x, 5, -((2*Cos[a + b*x])/Sqrt[x]) - 2*Sqrt[b]*Sqrt[2*Pi]*Cos[a]*FresnelS[Sqrt[b]*Sqrt[2/Pi]*Sqrt[x]] - 2*Sqrt[b]*Sqrt[2*Pi]*FresnelC[Sqrt[b]*Sqrt[2/Pi]*Sqrt[x]]*Sin[a]}
{Cos[a+b*x]^2/x^(3/2), x, 8, -(1/Sqrt[x]) - Cos[2*a + 2*b*x]/Sqrt[x] - 2*Sqrt[b]*Sqrt[Pi]*Cos[2*a]*FresnelS[(2*Sqrt[b]*Sqrt[x])/Sqrt[Pi]] - 2*Sqrt[b]*Sqrt[Pi]*FresnelC[(2*Sqrt[b]*Sqrt[x])/Sqrt[Pi]]*Sin[2*a]}
{Cos[a+b*x]^3/x^(3/2), x, 11, -((3*Cos[a + b*x])/(2*Sqrt[x])) - Cos[3*a + 3*b*x]/(2*Sqrt[x]) - 3*Sqrt[b]*Sqrt[Pi/2]*Cos[a]*FresnelS[Sqrt[b]*Sqrt[2/Pi]*Sqrt[x]] - Sqrt[b]*Sqrt[(3*Pi)/2]*Cos[3*a]*FresnelS[Sqrt[b]*Sqrt[6/Pi]*Sqrt[x]] - 3*Sqrt[b]*Sqrt[Pi/2]*FresnelC[Sqrt[b]*Sqrt[2/Pi]*Sqrt[x]]*Sin[a] - Sqrt[b]*Sqrt[(3*Pi)/2]*FresnelC[Sqrt[b]*Sqrt[6/Pi]*Sqrt[x]]*Sin[3*a]}
{Cos[a+b*x]^4/x^(3/2), x, 14, -(3/(4*Sqrt[x])) - Cos[2*a + 2*b*x]/Sqrt[x] - Cos[4*a + 4*b*x]/(4*Sqrt[x]) - Sqrt[b]*Sqrt[Pi/2]*Cos[4*a]*FresnelS[2*Sqrt[b]*Sqrt[2/Pi]*Sqrt[x]] - 2*Sqrt[b]*Sqrt[Pi]*Cos[2*a]*FresnelS[(2*Sqrt[b]*Sqrt[x])/Sqrt[Pi]] - 2*Sqrt[b]*Sqrt[Pi]*FresnelC[(2*Sqrt[b]*Sqrt[x])/Sqrt[Pi]]*Sin[2*a] - Sqrt[b]*Sqrt[Pi/2]*FresnelC[2*Sqrt[b]*Sqrt[2/Pi]*Sqrt[x]]*Sin[4*a]}


{Sinh[a+b*x]/x^(3/2), x, 5, (Sqrt[b]*Sqrt[Pi]*Erf[Sqrt[b]*Sqrt[x]])/E^a + Sqrt[b]*E^a*Sqrt[Pi]*Erfi[Sqrt[b]*Sqrt[x]] - (2*Sinh[a + b*x])/Sqrt[x]}
{Sinh[a+b*x]^2/x^(3/2), x, 8, 1/Sqrt[x] - Cosh[2*a + 2*b*x]/Sqrt[x] - (Sqrt[b]*Sqrt[Pi/2]*Erf[Sqrt[2]*Sqrt[b]*Sqrt[x]])/E^(2*a) + Sqrt[b]*E^(2*a)*Sqrt[Pi/2]*Erfi[Sqrt[2]*Sqrt[b]*Sqrt[x]]}
{Sinh[a+b*x]^3/x^(3/2), x, 11, ((-(3/4))*Sqrt[b]*Sqrt[Pi]*Erf[Sqrt[b]*Sqrt[x]])/E^a + ((1/4)*Sqrt[b]*Sqrt[3*Pi]*Erf[Sqrt[3]*Sqrt[b]*Sqrt[x]])/E^(3*a) - (3/4)*Sqrt[b]*E^a*Sqrt[Pi]*Erfi[Sqrt[b]*Sqrt[x]] + (1/4)*Sqrt[b]*E^(3*a)*Sqrt[3*Pi]*Erfi[Sqrt[3]*Sqrt[b]*Sqrt[x]] + (3*Sinh[a + b*x])/(2*Sqrt[x]) - Sinh[3*a + 3*b*x]/(2*Sqrt[x])}
{Sinh[a+b*x]^4/x^(3/2), x, 12, -(3/(4*Sqrt[x])) + Cosh[2*a + 2*b*x]/Sqrt[x] - Cosh[4*a + 4*b*x]/(4*Sqrt[x]) - ((1/4)*Sqrt[b]*Sqrt[Pi]*Erf[2*Sqrt[b]*Sqrt[x]])/E^(4*a) + (Sqrt[b]*Sqrt[Pi/2]*Erf[Sqrt[2]*Sqrt[b]*Sqrt[x]])/E^(2*a) + (1/4)*Sqrt[b]*E^(4*a)*Sqrt[Pi]*Erfi[2*Sqrt[b]*Sqrt[x]] - Sqrt[b]*E^(2*a)*Sqrt[Pi/2]*Erfi[Sqrt[2]*Sqrt[b]*Sqrt[x]]}


{Cosh[a+b*x]/x^(3/2), x, 5, -((2*Cosh[a + b*x])/Sqrt[x]) - (Sqrt[b]*Sqrt[Pi]*Erf[Sqrt[b]*Sqrt[x]])/E^a + Sqrt[b]*E^a*Sqrt[Pi]*Erfi[Sqrt[b]*Sqrt[x]]}
{Cosh[a+b*x]^2/x^(3/2), x, 8, -(1/Sqrt[x]) - Cosh[2*a + 2*b*x]/Sqrt[x] - (Sqrt[b]*Sqrt[Pi/2]*Erf[Sqrt[2]*Sqrt[b]*Sqrt[x]])/E^(2*a) + Sqrt[b]*E^(2*a)*Sqrt[Pi/2]*Erfi[Sqrt[2]*Sqrt[b]*Sqrt[x]]}
{Cosh[a+b*x]^3/x^(3/2), x, 11, -((3*Cosh[a + b*x])/(2*Sqrt[x])) - Cosh[3*a + 3*b*x]/(2*Sqrt[x]) - ((3/4)*Sqrt[b]*Sqrt[Pi]*Erf[Sqrt[b]*Sqrt[x]])/E^a - ((1/4)*Sqrt[b]*Sqrt[3*Pi]*Erf[Sqrt[3]*Sqrt[b]*Sqrt[x]])/E^(3*a) + (3/4)*Sqrt[b]*E^a*Sqrt[Pi]*Erfi[Sqrt[b]*Sqrt[x]] + (1/4)*Sqrt[b]*E^(3*a)*Sqrt[3*Pi]*Erfi[Sqrt[3]*Sqrt[b]*Sqrt[x]]}
{Cosh[a+b*x]^4/x^(3/2), x, 12, -(3/(4*Sqrt[x])) - Cosh[2*a + 2*b*x]/Sqrt[x] - Cosh[4*a + 4*b*x]/(4*Sqrt[x]) - ((1/4)*Sqrt[b]*Sqrt[Pi]*Erf[2*Sqrt[b]*Sqrt[x]])/E^(4*a) - (Sqrt[b]*Sqrt[Pi/2]*Erf[Sqrt[2]*Sqrt[b]*Sqrt[x]])/E^(2*a) + (1/4)*Sqrt[b]*E^(4*a)*Sqrt[Pi]*Erfi[2*Sqrt[b]*Sqrt[x]] + Sqrt[b]*E^(2*a)*Sqrt[Pi/2]*Erfi[Sqrt[2]*Sqrt[b]*Sqrt[x]]}
