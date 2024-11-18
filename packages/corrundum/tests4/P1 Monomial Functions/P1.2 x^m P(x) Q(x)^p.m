(* ::Package:: *)

(* ::Title:: *)
(*Integration problems of the form x^m P[x] Q[x]^p*)


(* ::Section::Closed:: *)
(*Integrands of the form x^m P[x] (a+b x^n+c x^(2 n))^p*)


{x^4*(A + B*x + c*x^2)/(a + b*x^2 + c*x^4), x, 12, ((A - b)*x)/c + (B*x^2)/(2*c) + x^3/3 - ((2*a*(A - b)*c - ((A - b)*b + a*c)*(b - Sqrt[b^2 - 4*a*c]))*ArcTan[(Sqrt[2]*Sqrt[c]*x)/Sqrt[b - Sqrt[b^2 - 4*a*c]]])/(Sqrt[2]*c^(3/2)*Sqrt[b^2 - 4*a*c]*Sqrt[b - Sqrt[b^2 - 4*a*c]]) + ((2*a*(A - b)*c - (A*b - b^2 + a*c)*(b + Sqrt[b^2 - 4*a*c]))*ArcTan[(Sqrt[2]*Sqrt[c]*x)/Sqrt[b + Sqrt[b^2 - 4*a*c]]])/(Sqrt[2]*c^(3/2)*Sqrt[b^2 - 4*a*c]*Sqrt[b + Sqrt[b^2 - 4*a*c]]) - (B*(b^2 - 2*a*c)*ArcTanh[(b + 2*c*x^2)/Sqrt[b^2 - 4*a*c]])/(2*c^2*Sqrt[b^2 - 4*a*c]) - (b*B*Log[a + b*x^2 + c*x^4])/(4*c^2)}
{x^3*(A + B*x + c*x^2)/(a + b*x^2 + c*x^4), x, 12, (B*x)/c + x^2/2 + (B*(b^2 - 2*a*c - b*Sqrt[b^2 - 4*a*c])*ArcTan[(Sqrt[2]*Sqrt[c]*x)/Sqrt[b - Sqrt[b^2 - 4*a*c]]])/(Sqrt[2]*c^(3/2)*Sqrt[b^2 - 4*a*c]*Sqrt[b - Sqrt[b^2 - 4*a*c]]) + (B*(2*a*c - b*(b + Sqrt[b^2 - 4*a*c]))*ArcTan[(Sqrt[2]*Sqrt[c]*x)/Sqrt[b + Sqrt[b^2 - 4*a*c]]])/(Sqrt[2]*c^(3/2)*Sqrt[b^2 - 4*a*c]*Sqrt[b + Sqrt[b^2 - 4*a*c]]) + ((A*b - b^2 + 2*a*c)*ArcTanh[(b + 2*c*x^2)/Sqrt[b^2 - 4*a*c]])/(2*c*Sqrt[b^2 - 4*a*c]) + ((A - b)*Log[a + b*x^2 + c*x^4])/(4*c)}
{x^2*(A + B*x + c*x^2)/(a + b*x^2 + c*x^4), x, 10, x - ((2*a*c + (A - b)*(b - Sqrt[b^2 - 4*a*c]))*ArcTan[(Sqrt[2]*Sqrt[c]*x)/Sqrt[b - Sqrt[b^2 - 4*a*c]]])/(Sqrt[2]*Sqrt[c]*Sqrt[b^2 - 4*a*c]*Sqrt[b - Sqrt[b^2 - 4*a*c]]) + ((2*a*c + (A - b)*(b + Sqrt[b^2 - 4*a*c]))*ArcTan[(Sqrt[2]*Sqrt[c]*x)/Sqrt[b + Sqrt[b^2 - 4*a*c]]])/(Sqrt[2]*Sqrt[c]*Sqrt[b^2 - 4*a*c]*Sqrt[b + Sqrt[b^2 - 4*a*c]]) + (b*B*ArcTanh[(b + 2*c*x^2)/Sqrt[b^2 - 4*a*c]])/(2*c*Sqrt[b^2 - 4*a*c]) + (B*Log[a + b*x^2 + c*x^4])/(4*c)}
{x^1*(A + B*x + c*x^2)/(a + b*x^2 + c*x^4), x, 9, -((B*Sqrt[b - Sqrt[b^2 - 4*a*c]]*ArcTan[(Sqrt[2]*Sqrt[c]*x)/Sqrt[b - Sqrt[b^2 - 4*a*c]]])/(Sqrt[2]*Sqrt[c]*Sqrt[b^2 - 4*a*c])) + (B*Sqrt[b + Sqrt[b^2 - 4*a*c]]*ArcTan[(Sqrt[2]*Sqrt[c]*x)/Sqrt[b + Sqrt[b^2 - 4*a*c]]])/(Sqrt[2]*Sqrt[c]*Sqrt[b^2 - 4*a*c]) - ((2*A - b)*ArcTanh[(b + 2*c*x^2)/Sqrt[b^2 - 4*a*c]])/(2*Sqrt[b^2 - 4*a*c]) + (1/4)*Log[a + b*x^2 + c*x^4]}
{x^0*(A + B*x + c*x^2)/(a + b*x^2 + c*x^4), x, 7, (Sqrt[c]*(2*A - b + Sqrt[b^2 - 4*a*c])*ArcTan[(Sqrt[2]*Sqrt[c]*x)/Sqrt[b - Sqrt[b^2 - 4*a*c]]])/(Sqrt[2]*Sqrt[b^2 - 4*a*c]*Sqrt[b - Sqrt[b^2 - 4*a*c]]) - (Sqrt[c]*(2*A - b - Sqrt[b^2 - 4*a*c])*ArcTan[(Sqrt[2]*Sqrt[c]*x)/Sqrt[b + Sqrt[b^2 - 4*a*c]]])/(Sqrt[2]*Sqrt[b^2 - 4*a*c]*Sqrt[b + Sqrt[b^2 - 4*a*c]]) - (B*ArcTanh[(b + 2*c*x^2)/Sqrt[b^2 - 4*a*c]])/Sqrt[b^2 - 4*a*c]}
{(A + B*x + c*x^2)/(x^1*(a + b*x^2 + c*x^4)), x, 10, (Sqrt[2]*B*Sqrt[c]*ArcTan[(Sqrt[2]*Sqrt[c]*x)/Sqrt[b - Sqrt[b^2 - 4*a*c]]])/(Sqrt[b^2 - 4*a*c]*Sqrt[b - Sqrt[b^2 - 4*a*c]]) - (Sqrt[2]*B*Sqrt[c]*ArcTan[(Sqrt[2]*Sqrt[c]*x)/Sqrt[b + Sqrt[b^2 - 4*a*c]]])/(Sqrt[b^2 - 4*a*c]*Sqrt[b + Sqrt[b^2 - 4*a*c]]) + ((A*b - 2*a*c)*ArcTanh[(b + 2*c*x^2)/Sqrt[b^2 - 4*a*c]])/(2*a*Sqrt[b^2 - 4*a*c]) + (A*Log[x])/a - (A*Log[a + b*x^2 + c*x^4])/(4*a)}
{(A + B*x + c*x^2)/(x^2*(a + b*x^2 + c*x^4)), x, 11, -(A/(a*x)) + (Sqrt[c]*(2*a*c - A*(b + Sqrt[b^2 - 4*a*c]))*ArcTan[(Sqrt[2]*Sqrt[c]*x)/Sqrt[b - Sqrt[b^2 - 4*a*c]]])/(Sqrt[2]*a*Sqrt[b^2 - 4*a*c]*Sqrt[b - Sqrt[b^2 - 4*a*c]]) - (Sqrt[c]*(2*a*c - A*(b - Sqrt[b^2 - 4*a*c]))*ArcTan[(Sqrt[2]*Sqrt[c]*x)/Sqrt[b + Sqrt[b^2 - 4*a*c]]])/(Sqrt[2]*a*Sqrt[b^2 - 4*a*c]*Sqrt[b + Sqrt[b^2 - 4*a*c]]) + (b*B*ArcTanh[(b + 2*c*x^2)/Sqrt[b^2 - 4*a*c]])/(2*a*Sqrt[b^2 - 4*a*c]) + (B*Log[x])/a - (B*Log[a + b*x^2 + c*x^4])/(4*a)}
{(A + B*x + c*x^2)/(x^3*(a + b*x^2 + c*x^4)), x, 12, -(A/(2*a*x^2)) - B/(a*x) - (B*Sqrt[c]*(b + Sqrt[b^2 - 4*a*c])*ArcTan[(Sqrt[2]*Sqrt[c]*x)/Sqrt[b - Sqrt[b^2 - 4*a*c]]])/(Sqrt[2]*a*Sqrt[b^2 - 4*a*c]*Sqrt[b - Sqrt[b^2 - 4*a*c]]) + (B*Sqrt[c]*(b - Sqrt[b^2 - 4*a*c])*ArcTan[(Sqrt[2]*Sqrt[c]*x)/Sqrt[b + Sqrt[b^2 - 4*a*c]]])/(Sqrt[2]*a*Sqrt[b^2 - 4*a*c]*Sqrt[b + Sqrt[b^2 - 4*a*c]]) - ((A*b^2 - 2*a*A*c - a*b*c)*ArcTanh[(b + 2*c*x^2)/Sqrt[b^2 - 4*a*c]])/(2*a^2*Sqrt[b^2 - 4*a*c]) - ((A*b - a*c)*Log[x])/a^2 + ((A*b - a*c)*Log[a + b*x^2 + c*x^4])/(4*a^2)}


(* ::Section::Closed:: *)
(*Integrands of the form x^m (A+B x^n) / (a+b x^(2 (m+1))+c x^n+d x^(2 n))*)


(* ::Subsection::Closed:: *)
(*Integrands of the form (A+B x^n) / (a+b x^2+c x^n+d x^(2 n))*)


{(e - 2*f*x^2)/(e^2 + 4*d*f*x^2 + 4*e*f*x^2 + 4*f^2*x^4), x, 2, ArcTan[(2*Sqrt[d]*Sqrt[f]*x)/(e + 2*f*x^2)]/(2*Sqrt[d]*Sqrt[f])}
{(e - 2*f*x^2)/(e^2 - 4*d*f*x^2 + 4*e*f*x^2 + 4*f^2*x^4), x, 2, ArcTanh[(2*Sqrt[d]*Sqrt[f]*x)/(e + 2*f*x^2)]/(2*Sqrt[d]*Sqrt[f])}

{(e - 4*f*x^3)/(e^2 + 4*d*f*x^2 + 4*e*f*x^3 + 4*f^2*x^6), x, 1, ArcTan[(2*Sqrt[d]*Sqrt[f]*x)/(e + 2*f*x^3)]/(2*Sqrt[d]*Sqrt[f])}
{(e - 4*f*x^3)/(e^2 - 4*d*f*x^2 + 4*e*f*x^3 + 4*f^2*x^6), x, 1, ArcTanh[(2*Sqrt[d]*Sqrt[f]*x)/(e + 2*f*x^3)]/(2*Sqrt[d]*Sqrt[f])}

{(e - 2*f*(-1 + n)*x^n)/(e^2 + 4*d*f*x^2 + 4*e*f*x^n + 4*f^2*x^(2*n)), x, 1, ArcTan[(2*Sqrt[d]*Sqrt[f]*x)/(e + 2*f*x^n)]/(2*Sqrt[d]*Sqrt[f])}
{(e - 2*f*(-1 + n)*x^n)/(e^2 - 4*d*f*x^2 + 4*e*f*x^n + 4*f^2*x^(2*n)), x, 1, ArcTanh[(2*Sqrt[d]*Sqrt[f]*x)/(e + 2*f*x^n)]/(2*Sqrt[d]*Sqrt[f])}


(* ::Subsection::Closed:: *)
(*Integrands of the form x^m (A+B x^n) / (a+b x^(2 (m+1))+c x^n+d x^(2 n))*)


{x/(e^2 + 4*e*f*x^2 + 4*d*f*x^4 + 4*f^2*x^4), x, 3, ArcTan[(Sqrt[f]*(e + 2*(d + f)*x^2))/(Sqrt[d]*e)]/(4*Sqrt[d]*e*Sqrt[f])}
{x/(e^2 + 4*e*f*x^2 - 4*d*f*x^4 + 4*f^2*x^4), x, 3, -(ArcTanh[(Sqrt[f]*(e - 2*(d - f)*x^2))/(Sqrt[d]*e)]/(4*Sqrt[d]*e*Sqrt[f]))}

{(x^2*(3*e + 2*f*x^2))/(e^2 + 4*e*f*x^2 + 4*f^2*x^4 + 4*d*f*x^6), x, 1, ArcTan[(2*Sqrt[d]*Sqrt[f]*x^3)/(e + 2*f*x^2)]/(2*Sqrt[d]*Sqrt[f])}
{(x^2*(3*e + 2*f*x^2))/(e^2 + 4*e*f*x^2 + 4*f^2*x^4 - 4*d*f*x^6), x, 1, ArcTanh[(2*Sqrt[d]*Sqrt[f]*x^3)/(e + 2*f*x^2)]/(2*Sqrt[d]*Sqrt[f])}

{(x^m*(e*(1 + m) + 2*f*(-1 + m)*x^2))/(e^2 + 4*e*f*x^2 + 4*f^2*x^4 + 4*d*f*x^(2 + 2*m)), x, 1, ArcTan[(2*Sqrt[d]*Sqrt[f]*x^(1 + m))/(e + 2*f*x^2)]/(2*Sqrt[d]*Sqrt[f])}
{(x^m*(e*(1 + m) + 2*f*(-1 + m)*x^2))/(e^2 + 4*e*f*x^2 + 4*f^2*x^4 - 4*d*f*x^(2 + 2*m)), x, 1, ArcTanh[(2*Sqrt[d]*Sqrt[f]*x^(1 + m))/(e + 2*f*x^2)]/(2*Sqrt[d]*Sqrt[f])}


{(x*(2*e - 2*f*x^3))/(e^2 + 4*e*f*x^3 + 4*d*f*x^4 + 4*f^2*x^6), x, 1, ArcTan[(2*Sqrt[d]*Sqrt[f]*x^2)/(e + 2*f*x^3)]/(2*Sqrt[d]*Sqrt[f])}
{(x*(2*e - 2*f*x^3))/(e^2 + 4*e*f*x^3 - 4*d*f*x^4 + 4*f^2*x^6), x, 1, ArcTanh[(2*Sqrt[d]*Sqrt[f]*x^2)/(e + 2*f*x^3)]/(2*Sqrt[d]*Sqrt[f])}

{x^2/(e^2 + 4*e*f*x^3 + 4*d*f*x^6 + 4*f^2*x^6), x, 3, ArcTan[(Sqrt[f]*(e + 2*(d + f)*x^3))/(Sqrt[d]*e)]/(6*Sqrt[d]*e*Sqrt[f])}
{x^2/(e^2 + 4*e*f*x^3 - 4*d*f*x^6 + 4*f^2*x^6), x, 3, -(ArcTanh[(Sqrt[f]*(e - 2*(d - f)*x^3))/(Sqrt[d]*e)]/(6*Sqrt[d]*e*Sqrt[f]))}

{(x^m*(e*(1 + m) + 2*f*(-2 + m)*x^3))/(e^2 + 4*e*f*x^3 + 4*f^2*x^6 + 4*d*f*x^(2 + 2*m)), x, 1, ArcTan[(2*Sqrt[d]*Sqrt[f]*x^(1 + m))/(e + 2*f*x^3)]/(2*Sqrt[d]*Sqrt[f])}
{(x^m*(e*(1 + m) + 2*f*(-2 + m)*x^3))/(e^2 + 4*e*f*x^3 + 4*f^2*x^6 - 4*d*f*x^(2 + 2*m)), x, 1, ArcTanh[(2*Sqrt[d]*Sqrt[f]*x^(1 + m))/(e + 2*f*x^3)]/(2*Sqrt[d]*Sqrt[f])}


{(x^m*(e*(1 + m) + 2*f*(1 + m - n)*x^n))/(e^2 + 4*d*f*x^(2 + 2*m) + 4*e*f*x^n + 4*f^2*x^(2*n)), x, 1, ArcTan[(2*Sqrt[d]*Sqrt[f]*x^(1 + m))/(e + 2*f*x^n)]/(2*Sqrt[d]*Sqrt[f])}
{(x^m*(e*(1 + m) + 2*f*(1 + m - n)*x^n))/(e^2 - 4*d*f*x^(2 + 2*m) + 4*e*f*x^n + 4*f^2*x^(2*n)), x, 1, ArcTanh[(2*Sqrt[d]*Sqrt[f]*x^(1 + m))/(e + 2*f*x^n)]/(2*Sqrt[d]*Sqrt[f])}


(* ::Section::Closed:: *)
(*Integrands of the form x^m (A+B x+C x^2+D x^3) / (a+b x+c x^2+b x^3+a x^4)*)


{(A + B*x + C*x^2 + D*x^3)/(a + b*x + c*x^2 + b*x^3 + a*x^4), x, 7, ((4*a^2*B + b*(b - Sqrt[8*a^2 + b^2 - 4*a*c])*D - a*(A*(b - Sqrt[8*a^2 + b^2 - 4*a*c]) + b*C - Sqrt[8*a^2 + b^2 - 4*a*c]*C + 2*c*D))*ArcTan[(b - Sqrt[8*a^2 + b^2 - 4*a*c] + 4*a*x)/Sqrt[16*a^2 - (b - Sqrt[8*a^2 + b^2 - 4*a*c])^2]])/(Sqrt[2]*a*Sqrt[8*a^2 + b^2 - 4*a*c]*Sqrt[4*a^2 + 2*a*c - b*(b - Sqrt[8*a^2 + b^2 - 4*a*c])]) - ((4*a^2*B + b*(b + Sqrt[8*a^2 + b^2 - 4*a*c])*D - a*(A*(b + Sqrt[8*a^2 + b^2 - 4*a*c]) + b*C + Sqrt[8*a^2 + b^2 - 4*a*c]*C + 2*c*D))*ArcTan[(b + Sqrt[8*a^2 + b^2 - 4*a*c] + 4*a*x)/Sqrt[16*a^2 - (b + Sqrt[8*a^2 + b^2 - 4*a*c])^2]])/(Sqrt[2]*a*Sqrt[8*a^2 + b^2 - 4*a*c]*Sqrt[4*a^2 + 2*a*c - b*(b + Sqrt[8*a^2 + b^2 - 4*a*c])]) - ((2*a*(A - C) + (b - Sqrt[8*a^2 + b^2 - 4*a*c])*D)*Log[2*a + (b - Sqrt[8*a^2 + b^2 - 4*a*c])*x + 2*a*x^2])/(4*a*Sqrt[8*a^2 + b^2 - 4*a*c]) + ((2*a*(A - C) + (b + Sqrt[8*a^2 + b^2 - 4*a*c])*D)*Log[2*a + (b + Sqrt[8*a^2 + b^2 - 4*a*c])*x + 2*a*x^2])/(4*a*Sqrt[8*a^2 + b^2 - 4*a*c])}


{x^4*(5 + x + 3*x^2 + 2*x^3)/(2 + x + 3*x^2 + x^3 + 2*x^4), x, 10, (5*x)/4 - (3*x^2)/4 + x^3/3 + x^4/4 + (1/24)*Sqrt[5/3]*ArcTan[(1 - 4*x)/Sqrt[15]] - (10*ArcTan[(1 + 2*x)/Sqrt[3]])/(3*Sqrt[3]) + (1/3)*Log[1 + x + x^2] - (13/48)*Log[2 - x + 2*x^2]}
{x^3*(5 + x + 3*x^2 + 2*x^3)/(2 + x + 3*x^2 + x^3 + 2*x^4), x, 10, -((3*x)/2) + x^2/2 + x^3/3 + (5/12)*Sqrt[5/3]*ArcTan[(1 - 4*x)/Sqrt[15]] + (8*ArcTan[(1 + 2*x)/Sqrt[3]])/(3*Sqrt[3]) + (2/3)*Log[1 + x + x^2] - (1/24)*Log[2 - x + 2*x^2]}
{x^2*(5 + x + 3*x^2 + 2*x^3)/(2 + x + 3*x^2 + x^3 + 2*x^4), x, 10, x + x^2/2 + (1/6)*Sqrt[5/3]*ArcTan[(1 - 4*x)/Sqrt[15]] + (2*ArcTan[(1 + 2*x)/Sqrt[3]])/(3*Sqrt[3]) - Log[1 + x + x^2] + (1/4)*Log[2 - x + 2*x^2]}
{x^1*(5 + x + 3*x^2 + 2*x^3)/(2 + x + 3*x^2 + x^3 + 2*x^4), x, 10, x - (1/3)*Sqrt[5/3]*ArcTan[(1 - 4*x)/Sqrt[15]] - (10*ArcTan[(1 + 2*x)/Sqrt[3]])/(3*Sqrt[3]) + (1/3)*Log[1 + x + x^2] + (1/6)*Log[2 - x + 2*x^2]}
{x^0*(5 + x + 3*x^2 + 2*x^3)/(2 + x + 3*x^2 + x^3 + 2*x^4), x, 8, (-(1/3))*Sqrt[5/3]*ArcTan[(1 - 4*x)/Sqrt[15]] + (8*ArcTan[(1 + 2*x)/Sqrt[3]])/(3*Sqrt[3]) + (2/3)*Log[1 + x + x^2] - (1/6)*Log[2 - x + 2*x^2]}
{(5 + x + 3*x^2 + 2*x^3)/(x^1*(2 + x + 3*x^2 + x^3 + 2*x^4)), x, 8, (1/6)*Sqrt[5/3]*ArcTan[(1 - 4*x)/Sqrt[15]] + (2*ArcTan[(1 + 2*x)/Sqrt[3]])/(3*Sqrt[3]) + (5*Log[x])/2 - Log[1 + x + x^2] - (1/4)*Log[2 - x + 2*x^2]}
{(5 + x + 3*x^2 + 2*x^3)/(x^2*(2 + x + 3*x^2 + x^3 + 2*x^4)), x, 8, -(5/(2*x)) + (5/12)*Sqrt[5/3]*ArcTan[(1 - 4*x)/Sqrt[15]] - (10*ArcTan[(1 + 2*x)/Sqrt[3]])/(3*Sqrt[3]) - (3*Log[x])/4 + (1/3)*Log[1 + x + x^2] + (1/24)*Log[2 - x + 2*x^2]}
{(5 + x + 3*x^2 + 2*x^3)/(x^3*(2 + x + 3*x^2 + x^3 + 2*x^4)), x, 8, -(5/(4*x^2)) + 3/(4*x) + (1/24)*Sqrt[5/3]*ArcTan[(1 - 4*x)/Sqrt[15]] + (8*ArcTan[(1 + 2*x)/Sqrt[3]])/(3*Sqrt[3]) - (15*Log[x])/8 + (2/3)*Log[1 + x + x^2] + (13/48)*Log[2 - x + 2*x^2]}


{x^3*(5 + x + 3*x^2 + 2*x^3)/(2 + x + 5*x^2 + x^3 + 2*x^4), x, 11, (-(1/28))*(35 - 9*I*Sqrt[7])*x - (1/28)*(35 + 9*I*Sqrt[7])*x - ((5*I - Sqrt[7])*x^2)/(4*Sqrt[7]) + ((5*I + Sqrt[7])*x^2)/(4*Sqrt[7]) - ((5*I - Sqrt[7])*x^3)/(6*Sqrt[7]) + ((5*I + Sqrt[7])*x^3)/(6*Sqrt[7]) + (11*(9*I + 5*Sqrt[7])*ArcTan[(1 - I*Sqrt[7] + 8*x)/(7^(1/4)*Sqrt[2*(I + 5*Sqrt[7])])])/(4*7^(3/4)*Sqrt[2*(I + 5*Sqrt[7])]) - (11*(9*I - 5*Sqrt[7])*ArcTan[(1 + I*Sqrt[7] + 8*x)/(7^(1/4)*Sqrt[2*(-I + 5*Sqrt[7])])])/(4*7^(3/4)*Sqrt[2*(-I + 5*Sqrt[7])]) - (3*(11*I - Sqrt[7])*Log[4 + (1 - I*Sqrt[7])*x + 4*x^2])/(16*Sqrt[7]) + (3*(11*I + Sqrt[7])*Log[4 + (1 + I*Sqrt[7])*x + 4*x^2])/(16*Sqrt[7])}
{x^2*(5 + x + 3*x^2 + 2*x^3)/(2 + x + 5*x^2 + x^3 + 2*x^4), x, 11, -(((5*I - Sqrt[7])*x)/(2*Sqrt[7])) + ((5*I + Sqrt[7])*x)/(2*Sqrt[7]) - ((5*I - Sqrt[7])*x^2)/(4*Sqrt[7]) + ((5*I + Sqrt[7])*x^2)/(4*Sqrt[7]) - ((53*I + Sqrt[7])*ArcTan[(1 - I*Sqrt[7] + 8*x)/(7^(1/4)*Sqrt[2*(I + 5*Sqrt[7])])])/(2*7^(3/4)*Sqrt[2*(I + 5*Sqrt[7])]) + ((53*I - Sqrt[7])*ArcTan[(1 + I*Sqrt[7] + 8*x)/(7^(1/4)*Sqrt[2*(-I + 5*Sqrt[7])])])/(2*7^(3/4)*Sqrt[2*(-I + 5*Sqrt[7])]) - (1/56)*(35 + 9*I*Sqrt[7])*Log[4 + (1 - I*Sqrt[7])*x + 4*x^2] - (1/56)*(35 - 9*I*Sqrt[7])*Log[4 + (1 + I*Sqrt[7])*x + 4*x^2]}
{x^1*(5 + x + 3*x^2 + 2*x^3)/(2 + x + 5*x^2 + x^3 + 2*x^4), x, 11, -(((5*I - Sqrt[7])*x)/(2*Sqrt[7])) + ((5*I + Sqrt[7])*x)/(2*Sqrt[7]) - ((19*I + 7*Sqrt[7])*ArcTan[(1 - I*Sqrt[7] + 8*x)/(7^(1/4)*Sqrt[2*(I + 5*Sqrt[7])])])/(7^(3/4)*Sqrt[2*(I + 5*Sqrt[7])]) + ((19*I - 7*Sqrt[7])*ArcTan[(1 + I*Sqrt[7] + 8*x)/(7^(1/4)*Sqrt[2*(-I + 5*Sqrt[7])])])/(7^(3/4)*Sqrt[2*(-I + 5*Sqrt[7])]) + ((5*I + Sqrt[7])*Log[4 + (1 - I*Sqrt[7])*x + 4*x^2])/(4*Sqrt[7]) - ((5*I - Sqrt[7])*Log[4 + (1 + I*Sqrt[7])*x + 4*x^2])/(4*Sqrt[7])}
{x^0*(5 + x + 3*x^2 + 2*x^3)/(2 + x + 5*x^2 + x^3 + 2*x^4), x, 7, ((19*I + 7*Sqrt[7])*ArcTan[(1 - I*Sqrt[7] + 8*x)/(7^(1/4)*Sqrt[2*(I + 5*Sqrt[7])])])/(7^(3/4)*Sqrt[2*(I + 5*Sqrt[7])]) - ((19*I - 7*Sqrt[7])*ArcTan[(1 + I*Sqrt[7] + 8*x)/(7^(1/4)*Sqrt[2*(-I + 5*Sqrt[7])])])/(7^(3/4)*Sqrt[2*(-I + 5*Sqrt[7])]) + ((5*I + Sqrt[7])*Log[4 + (1 - I*Sqrt[7])*x + 4*x^2])/(4*Sqrt[7]) - ((5*I - Sqrt[7])*Log[4 + (1 + I*Sqrt[7])*x + 4*x^2])/(4*Sqrt[7])}
{(5 + x + 3*x^2 + 2*x^3)/(x^1*(2 + x + 5*x^2 + x^3 + 2*x^4)), x, 11, ((53*I + Sqrt[7])*ArcTan[(1 - I*Sqrt[7] + 8*x)/(7^(1/4)*Sqrt[2*(I + 5*Sqrt[7])])])/(2*7^(3/4)*Sqrt[2*(I + 5*Sqrt[7])]) - ((53*I - Sqrt[7])*ArcTan[(1 + I*Sqrt[7] + 8*x)/(7^(1/4)*Sqrt[2*(-I + 5*Sqrt[7])])])/(2*7^(3/4)*Sqrt[2*(-I + 5*Sqrt[7])]) + (1/28)*(35 - 9*I*Sqrt[7])*Log[x] + (1/28)*(35 + 9*I*Sqrt[7])*Log[x] - (1/56)*(35 + 9*I*Sqrt[7])*Log[4 + (1 - I*Sqrt[7])*x + 4*x^2] - (1/56)*(35 - 9*I*Sqrt[7])*Log[4 + (1 + I*Sqrt[7])*x + 4*x^2]}
{(5 + x + 3*x^2 + 2*x^3)/(x^2*(2 + x + 5*x^2 + x^3 + 2*x^4)), x, 13, -((35 - 9*I*Sqrt[7])/(28*x)) - (35 + 9*I*Sqrt[7])/(28*x) - (11*(9*I + 5*Sqrt[7])*ArcTan[(1 - I*Sqrt[7] + 8*x)/(7^(1/4)*Sqrt[2*(I + 5*Sqrt[7])])])/(4*7^(3/4)*Sqrt[2*(I + 5*Sqrt[7])]) + (11*(9*I - 5*Sqrt[7])*ArcTan[(1 + I*Sqrt[7] + 8*x)/(7^(1/4)*Sqrt[2*(-I + 5*Sqrt[7])])])/(4*7^(3/4)*Sqrt[2*(-I + 5*Sqrt[7])]) + (3*(11*I - Sqrt[7])*Log[x])/(8*Sqrt[7]) - (3*(11*I + Sqrt[7])*Log[x])/(8*Sqrt[7]) - (3*(11*I - Sqrt[7])*Log[4 + (1 - I*Sqrt[7])*x + 4*x^2])/(16*Sqrt[7]) + (3*(11*I + Sqrt[7])*Log[4 + (1 + I*Sqrt[7])*x + 4*x^2])/(16*Sqrt[7])}
{(5 + x + 3*x^2 + 2*x^3)/(x^3*(2 + x + 5*x^2 + x^3 + 2*x^4)), x, 15, -((35 - 9*I*Sqrt[7])/(56*x^2)) - (35 + 9*I*Sqrt[7])/(56*x^2) - (3*(11*I - Sqrt[7]))/(8*Sqrt[7]*x) + (3*(11*I + Sqrt[7]))/(8*Sqrt[7]*x) - ((355*I - 73*Sqrt[7])*ArcTan[(1 - I*Sqrt[7] + 8*x)/(7^(1/4)*Sqrt[2*(I + 5*Sqrt[7])])])/(8*7^(3/4)*Sqrt[2*(I + 5*Sqrt[7])]) + ((355*I + 73*Sqrt[7])*ArcTan[(1 + I*Sqrt[7] + 8*x)/(7^(1/4)*Sqrt[2*(-I + 5*Sqrt[7])])])/(8*7^(3/4)*Sqrt[2*(-I + 5*Sqrt[7])]) - (1/16)*(35 - 9*I*Sqrt[7])*Log[x] - (1/16)*(35 + 9*I*Sqrt[7])*Log[x] + (1/32)*(35 + 9*I*Sqrt[7])*Log[4 + (1 - I*Sqrt[7])*x + 4*x^2] + (1/32)*(35 - 9*I*Sqrt[7])*Log[4 + (1 + I*Sqrt[7])*x + 4*x^2]}
