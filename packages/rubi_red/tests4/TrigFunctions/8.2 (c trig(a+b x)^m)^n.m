(* ::Package:: *)

(* ::Title:: *)
(*Problems for integrands of the form (c trig(a+b x)^m)^n*)


(* ::Section::Closed:: *)
(*Integrands of the form (c Sin[a+b x]^m)^n*)


(* ::Subsection::Closed:: *)
(*Integrands of the form (c Sin[a+b x]^1)^n*)


{(c*Sin[a + b*x])^n,x, 2, -((Cos[a + b*x]*Hypergeometric2F1[1/2, (1 - n)/2, 3/2, Cos[a + b*x]^2]*(c*Sin[a + b*x])^(1 + n)*(Sin[a + b*x]^2)^((1/2)*(-1 - n)))/(b*c))}

{(c*Sin[a + b*x])^(5/2),x, 3, -((6*c^2*EllipticE[Pi/4 + (1/2)*(-a - b*x), 2]*Sqrt[c*Sin[a + b*x]])/(5*b*Sqrt[Sin[a + b*x]])) - (2*c*Cos[a + b*x]*(c*Sin[a + b*x])^(3/2))/(5*b)}
{(c*Sin[a + b*x])^(3/2),x, 3, -((2*c^2*EllipticF[Pi/4 + (1/2)*(-a - b*x), 2]*Sqrt[Sin[a + b*x]])/(3*b*Sqrt[c*Sin[a + b*x]])) - (2*c*Cos[a + b*x]*Sqrt[c*Sin[a + b*x]])/(3*b)}
{(c*Sin[a + b*x])^(1/2), x, 2, -((2*EllipticE[Pi/4 + (1/2)*(-a - b*x), 2]*Sqrt[c*Sin[a + b*x]])/(b*Sqrt[Sin[a + b*x]]))}
{1/(c*Sin[a + b*x])^(1/2), x, 2, -((2*EllipticF[Pi/4 + (1/2)*(-a - b*x), 2]*Sqrt[Sin[a + b*x]])/(b*Sqrt[c*Sin[a + b*x]]))}
{1/(c*Sin[a + b*x])^(3/2), x, 3, -((2*Cos[a + b*x])/(b*c*Sqrt[c*Sin[a + b*x]])) + (2*EllipticE[Pi/4 + (1/2)*(-a - b*x), 2]*Sqrt[c*Sin[a + b*x]])/(b*c^2*Sqrt[Sin[a + b*x]])}
{1/(c*Sin[a + b*x])^(5/2), x, 3, -((2*Cos[a + b*x])/(3*b*c*(c*Sin[a + b*x])^(3/2))) - (2*EllipticF[Pi/4 + (1/2)*(-a - b*x), 2]*Sqrt[Sin[a + b*x]])/(3*b*c^2*Sqrt[c*Sin[a + b*x]])}


(* ::Subsection::Closed:: *)
(*Integrands of the form (c Sin[a+b x]^2)^n*)


{(c*Sin[a + b*x]^2)^n,x, 2, -((Cos[a + b*x]*Hypergeometric2F1[1/2, (1/2)*(1 - 2*n), 3/2, Cos[a + b*x]^2]*Sin[a + b*x]*(Sin[a + b*x]^2)^((1/2)*(-1 - 2*n))*(c*Sin[a + b*x]^2)^n)/b)}

{(a*Sin[x]^2)^(5/2),x, 4, (-(8/15))*a^2*Cot[x]*Sqrt[a*Sin[x]^2] - (4/15)*a*Cot[x]*(a*Sin[x]^2)^(3/2) - (1/5)*Cot[x]*(a*Sin[x]^2)^(5/2)}
{(a*Sin[x]^2)^(3/2),x, 3, (-(2/3))*a*Cot[x]*Sqrt[a*Sin[x]^2] - (1/3)*Cot[x]*(a*Sin[x]^2)^(3/2)}
{(a*Sin[x]^2)^(1/2), x, 2, (-Cot[x])*Sqrt[a*Sin[x]^2]}
{1/(a*Sin[x]^2)^(1/2), x, 2, -((ArcTanh[Cos[x]]*Sin[x])/Sqrt[a*Sin[x]^2])}
{1/(a*Sin[x]^2)^(3/2), x, 3, -(Cot[x]/(2*a*Sqrt[a*Sin[x]^2])) - (ArcTanh[Cos[x]]*Sin[x])/(2*a*Sqrt[a*Sin[x]^2])}
{1/(a*Sin[x]^2)^(5/2), x, 4, -(Cot[x]/(4*a*(a*Sin[x]^2)^(3/2))) - (3*Cot[x])/(8*a^2*Sqrt[a*Sin[x]^2]) - (3*ArcTanh[Cos[x]]*Sin[x])/(8*a^2*Sqrt[a*Sin[x]^2])}


(* ::Subsection::Closed:: *)
(*Integrands of the form (c Sin[a+b x]^3)^n*)


{(c*Sin[a + b*x]^3)^n,x, 2, -((Cos[a + b*x]*Hypergeometric2F1[1/2, (1/2)*(1 - 3*n), 3/2, Cos[a + b*x]^2]*Sin[a + b*x]*(Sin[a + b*x]^2)^((1/2)*(-1 - 3*n))*(c*Sin[a + b*x]^3)^n)/b)}

{(a*Sin[x]^3)^(5/2),x, 6, (-(26/77))*a^2*Cot[x]*Sqrt[a*Sin[x]^3] - (26*a^2*EllipticF[Pi/4 - x/2, 2]*Sqrt[a*Sin[x]^3])/(77*Sin[x]^(3/2)) - (78/385)*a^2*Cos[x]*Sin[x]*Sqrt[a*Sin[x]^3] - (26/165)*a^2*Cos[x]*Sin[x]^3*Sqrt[a*Sin[x]^3] - (2/15)*a^2*Cos[x]*Sin[x]^5*Sqrt[a*Sin[x]^3]}
{(a*Sin[x]^3)^(3/2),x, 4, (-(14/45))*a*Cos[x]*Sqrt[a*Sin[x]^3] - (14*a*EllipticE[Pi/4 - x/2, 2]*Sqrt[a*Sin[x]^3])/(15*Sin[x]^(3/2)) - (2/9)*a*Cos[x]*Sin[x]^2*Sqrt[a*Sin[x]^3]}
{(a*Sin[x]^3)^(1/2), x, 3, (-(2/3))*Cot[x]*Sqrt[a*Sin[x]^3] - (2*EllipticF[Pi/4 - x/2, 2]*Sqrt[a*Sin[x]^3])/(3*Sin[x]^(3/2))}
{1/(a*Sin[x]^3)^(1/2), x, 3, -((2*Cos[x]*Sin[x])/Sqrt[a*Sin[x]^3]) + (2*EllipticE[Pi/4 - x/2, 2]*Sin[x]^(3/2))/Sqrt[a*Sin[x]^3]}
{1/(a*Sin[x]^3)^(3/2),x, 4, -((10*Cos[x])/(21*a*Sqrt[a*Sin[x]^3])) - (2*Cot[x]*Csc[x])/(7*a*Sqrt[a*Sin[x]^3]) - (10*EllipticF[Pi/4 - x/2, 2]*Sin[x]^(3/2))/(21*a*Sqrt[a*Sin[x]^3])}
{1/(a*Sin[x]^3)^(5/2),x, 6, -((154*Cot[x])/(585*a^2*Sqrt[a*Sin[x]^3])) - (22*Cot[x]*Csc[x]^2)/(117*a^2*Sqrt[a*Sin[x]^3]) - (2*Cot[x]*Csc[x]^4)/(13*a^2*Sqrt[a*Sin[x]^3]) - (154*Cos[x]*Sin[x])/(195*a^2*Sqrt[a*Sin[x]^3]) + (154*EllipticE[Pi/4 - x/2, 2]*Sin[x]^(3/2))/(195*a^2*Sqrt[a*Sin[x]^3])}


(* ::Subsection::Closed:: *)
(*Integrands of the form (c Sin[a+b x]^4)^n*)


{(c*Sin[a + b*x]^4)^n,x, 2, -((Cos[a + b*x]*Hypergeometric2F1[1/2, (1/2)*(1 - 4*n), 3/2, Cos[a + b*x]^2]*Sin[a + b*x]*(Sin[a + b*x]^2)^((1/2)*(-1 - 4*n))*(c*Sin[a + b*x]^4)^n)/b)}

{(a*Sin[x]^4)^(5/2),x, 6, (-(63/256))*a^2*Cot[x]*Sqrt[a*Sin[x]^4] + (63/256)*a^2*x*Csc[x]^2*Sqrt[a*Sin[x]^4] - (21/128)*a^2*Cos[x]*Sin[x]*Sqrt[a*Sin[x]^4] - (21/160)*a^2*Cos[x]*Sin[x]^3*Sqrt[a*Sin[x]^4] - (9/80)*a^2*Cos[x]*Sin[x]^5*Sqrt[a*Sin[x]^4] - (1/10)*a^2*Cos[x]*Sin[x]^7*Sqrt[a*Sin[x]^4]}
{(a*Sin[x]^4)^(3/2),x, 4, (-(5/16))*a*Cot[x]*Sqrt[a*Sin[x]^4] + (5/16)*a*x*Csc[x]^2*Sqrt[a*Sin[x]^4] - (5/24)*a*Cos[x]*Sin[x]*Sqrt[a*Sin[x]^4] - (1/6)*a*Cos[x]*Sin[x]^3*Sqrt[a*Sin[x]^4]}
{(a*Sin[x]^4)^(1/2), x, 2, (-(1/2))*Cot[x]*Sqrt[a*Sin[x]^4] + (1/2)*x*Csc[x]^2*Sqrt[a*Sin[x]^4]}
{1/(a*Sin[x]^4)^(1/2), x, 2, -((Cos[x]*Sin[x])/Sqrt[a*Sin[x]^4])}
{1/(a*Sin[x]^4)^(3/2),x, 3, -((2*Cos[x]^2*Cot[x])/(3*a*Sqrt[a*Sin[x]^4])) - (Cos[x]^2*Cot[x]^3)/(5*a*Sqrt[a*Sin[x]^4]) - (Cos[x]*Sin[x])/(a*Sqrt[a*Sin[x]^4])}
{1/(a*Sin[x]^4)^(5/2),x, 3, -((4*Cos[x]^2*Cot[x])/(3*a^2*Sqrt[a*Sin[x]^4])) - (6*Cos[x]^2*Cot[x]^3)/(5*a^2*Sqrt[a*Sin[x]^4]) - (4*Cos[x]^2*Cot[x]^5)/(7*a^2*Sqrt[a*Sin[x]^4]) - (Cos[x]^2*Cot[x]^7)/(9*a^2*Sqrt[a*Sin[x]^4]) - (Cos[x]*Sin[x])/(a^2*Sqrt[a*Sin[x]^4])}


(* ::Subsection::Closed:: *)
(*Integrands of the form (c Sin[a+b x]^m)^n*)


{(c*Sin[a + b*x]^m)^n, x, 2, -((Cos[a + b*x]*Hypergeometric2F1[1/2, (1/2)*(1 - m*n), 3/2, Cos[a + b*x]^2]*Sin[a + b*x]*(Sin[a + b*x]^2)^((1/2)*(-1 - m*n))*(c*Sin[a + b*x]^m)^n)/b)}

{(c*Sin[a + b*x]^m)^(5/2), x, 2, -((c^2*Cos[a + b*x]*Hypergeometric2F1[1/2, (1/4)*(2 - 5*m), 3/2, Cos[a + b*x]^2]*Sin[a + b*x]^(1 + 2*m)*(Sin[a + b*x]^2)^((1/4)*(-2 - 5*m))*Sqrt[c*Sin[a + b*x]^m])/b)}
{(c*Sin[a + b*x]^m)^(3/2), x, 2, -((c*Cos[a + b*x]*Hypergeometric2F1[1/2, (1/4)*(2 - 3*m), 3/2, Cos[a + b*x]^2]*Sin[a + b*x]^(1 + m)*(Sin[a + b*x]^2)^((1/4)*(-2 - 3*m))*Sqrt[c*Sin[a + b*x]^m])/b)}
{(c*Sin[a + b*x]^m)^(1/2), x, 2, -((Cos[a + b*x]*Hypergeometric2F1[1/2, (2 - m)/4, 3/2, Cos[a + b*x]^2]*Sin[a + b*x]*(Sin[a + b*x]^2)^((1/4)*(-2 - m))*Sqrt[c*Sin[a + b*x]^m])/b)}
{1/(c*Sin[a + b*x]^m)^(1/2), x, 2, -((Cos[a + b*x]*Hypergeometric2F1[1/2, (2 + m)/4, 3/2, Cos[a + b*x]^2]*Sin[a + b*x]*(Sin[a + b*x]^2)^((1/4)*(-2 + m)))/(b*Sqrt[c*Sin[a + b*x]^m]))}
{1/(c*Sin[a + b*x]^m)^(3/2), x, 2, -((Cos[a + b*x]*Hypergeometric2F1[1/2, (1/4)*(2 + 3*m), 3/2, Cos[a + b*x]^2]*Sin[a + b*x]^(1 - m)*(Sin[a + b*x]^2)^((1/4)*(-2 + 3*m)))/(b*c*Sqrt[c*Sin[a + b*x]^m]))}
{1/(c*Sin[a + b*x]^m)^(5/2), x, 2, -((Cos[a + b*x]*Hypergeometric2F1[1/2, (1/4)*(2 + 5*m), 3/2, Cos[a + b*x]^2]*Sin[a + b*x]^(1 - 2*m)*(Sin[a + b*x]^2)^((1/4)*(-2 + 5*m)))/(b*c^2*Sqrt[c*Sin[a + b*x]^m]))}


{(c*Sin[a + b*x]^m)^(1/m), x, 2, -((Cot[a + b*x]*(c*Sin[a + b*x]^m)^(1/m))/b)}


(* ::Section::Closed:: *)
(*Integrands of the form (c Cos[a+b x]^m)^n*)


(* ::Subsection::Closed:: *)
(*Integrands of the form (c Cos[a+b x]^2)^n*)


{(a*Cos[x]^2)^(5/2),x, 4, (8/15)*a^2*Sqrt[a*Cos[x]^2]*Tan[x] + (4/15)*a*(a*Cos[x]^2)^(3/2)*Tan[x] + (1/5)*(a*Cos[x]^2)^(5/2)*Tan[x]}
{(a*Cos[x]^2)^(3/2),x, 3, (2/3)*a*Sqrt[a*Cos[x]^2]*Tan[x] + (1/3)*(a*Cos[x]^2)^(3/2)*Tan[x]}
{(a*Cos[x]^2)^(1/2), x, 2, Sqrt[a*Cos[x]^2]*Tan[x]}
{1/(a*Cos[x]^2)^(1/2), x, 2, (ArcTanh[Sin[x]]*Cos[x])/Sqrt[a*Cos[x]^2]}
{1/(a*Cos[x]^2)^(3/2), x, 3, (ArcTanh[Sin[x]]*Cos[x])/(2*a*Sqrt[a*Cos[x]^2]) + Tan[x]/(2*a*Sqrt[a*Cos[x]^2])}
{1/(a*Cos[x]^2)^(5/2), x, 4, (3*ArcTanh[Sin[x]]*Cos[x])/(8*a^2*Sqrt[a*Cos[x]^2]) + Tan[x]/(4*a*(a*Cos[x]^2)^(3/2)) + (3*Tan[x])/(8*a^2*Sqrt[a*Cos[x]^2])}


(* ::Subsection::Closed:: *)
(*Integrands of the form (c Cos[a+b x]^3)^n*)


{(a*Cos[x]^3)^(5/2),x, 6, (26*a^2*Sqrt[a*Cos[x]^3]*EllipticF[x/2, 2])/(77*Cos[x]^(3/2)) + (78/385)*a^2*Cos[x]*Sqrt[a*Cos[x]^3]*Sin[x] + (26/165)*a^2*Cos[x]^3*Sqrt[a*Cos[x]^3]*Sin[x] + (2/15)*a^2*Cos[x]^5*Sqrt[a*Cos[x]^3]*Sin[x] + (26/77)*a^2*Sqrt[a*Cos[x]^3]*Tan[x]}
{(a*Cos[x]^3)^(3/2),x, 4, (14*a*Sqrt[a*Cos[x]^3]*EllipticE[x/2, 2])/(15*Cos[x]^(3/2)) + (14/45)*a*Sqrt[a*Cos[x]^3]*Sin[x] + (2/9)*a*Cos[x]^2*Sqrt[a*Cos[x]^3]*Sin[x]}
{(a*Cos[x]^3)^(1/2), x, 3, (2*Sqrt[a*Cos[x]^3]*EllipticF[x/2, 2])/(3*Cos[x]^(3/2)) + (2/3)*Sqrt[a*Cos[x]^3]*Tan[x]}
{1/(a*Cos[x]^3)^(1/2), x, 3, -((2*Cos[x]^(3/2)*EllipticE[x/2, 2])/Sqrt[a*Cos[x]^3]) + (2*Cos[x]*Sin[x])/Sqrt[a*Cos[x]^3]}
{1/(a*Cos[x]^3)^(3/2),x, 4, (10*Cos[x]^(3/2)*EllipticF[x/2, 2])/(21*a*Sqrt[a*Cos[x]^3]) + (10*Sin[x])/(21*a*Sqrt[a*Cos[x]^3]) + (2*Sec[x]*Tan[x])/(7*a*Sqrt[a*Cos[x]^3])}
{1/(a*Cos[x]^3)^(5/2),x, 6, -((154*Cos[x]^(3/2)*EllipticE[x/2, 2])/(195*a^2*Sqrt[a*Cos[x]^3])) + (154*Cos[x]*Sin[x])/(195*a^2*Sqrt[a*Cos[x]^3]) + (154*Tan[x])/(585*a^2*Sqrt[a*Cos[x]^3]) + (22*Sec[x]^2*Tan[x])/(117*a^2*Sqrt[a*Cos[x]^3]) + (2*Sec[x]^4*Tan[x])/(13*a^2*Sqrt[a*Cos[x]^3])}


(* ::Subsection::Closed:: *)
(*Integrands of the form (c Cos[a+b x]^4)^n*)


{(a*Cos[x]^4)^(5/2),x, 6, (63/256)*a^2*x*Sqrt[a*Cos[x]^4]*Sec[x]^2 + (21/128)*a^2*Cos[x]*Sqrt[a*Cos[x]^4]*Sin[x] + (21/160)*a^2*Cos[x]^3*Sqrt[a*Cos[x]^4]*Sin[x] + (9/80)*a^2*Cos[x]^5*Sqrt[a*Cos[x]^4]*Sin[x] + (1/10)*a^2*Cos[x]^7*Sqrt[a*Cos[x]^4]*Sin[x] + (63/256)*a^2*Sqrt[a*Cos[x]^4]*Tan[x]}
{(a*Cos[x]^4)^(3/2),x, 4, (5/16)*a*x*Sqrt[a*Cos[x]^4]*Sec[x]^2 + (5/24)*a*Cos[x]*Sqrt[a*Cos[x]^4]*Sin[x] + (1/6)*a*Cos[x]^3*Sqrt[a*Cos[x]^4]*Sin[x] + (5/16)*a*Sqrt[a*Cos[x]^4]*Tan[x]}
{(a*Cos[x]^4)^(1/2), x, 2, (1/2)*x*Sqrt[a*Cos[x]^4]*Sec[x]^2 + (1/2)*Sqrt[a*Cos[x]^4]*Tan[x]}
{1/(a*Cos[x]^4)^(1/2), x, 2, (Cos[x]*Sin[x])/Sqrt[a*Cos[x]^4]}
{1/(a*Cos[x]^4)^(3/2),x, 3, (Cos[x]*Sin[x])/(a*Sqrt[a*Cos[x]^4]) + (2*Sin[x]^2*Tan[x])/(3*a*Sqrt[a*Cos[x]^4]) + (Sin[x]^2*Tan[x]^3)/(5*a*Sqrt[a*Cos[x]^4])}
{1/(a*Cos[x]^4)^(5/2),x, 3, (Cos[x]*Sin[x])/(a^2*Sqrt[a*Cos[x]^4]) + (4*Sin[x]^2*Tan[x])/(3*a^2*Sqrt[a*Cos[x]^4]) + (6*Sin[x]^2*Tan[x]^3)/(5*a^2*Sqrt[a*Cos[x]^4]) + (4*Sin[x]^2*Tan[x]^5)/(7*a^2*Sqrt[a*Cos[x]^4]) + (Sin[x]^2*Tan[x]^7)/(9*a^2*Sqrt[a*Cos[x]^4])}


(* ::Subsection::Closed:: *)
(*Integrands of the form (c Cos[a+b x]^m)^n*)


{(c*Cos[a + b*x]^m)^n, x, 2, (Cos[a + b*x]*(Cos[a + b*x]^2)^((1/2)*(-1 - m*n))*(c*Cos[a + b*x]^m)^n*Hypergeometric2F1[1/2, (1/2)*(1 - m*n), 3/2, Sin[a + b*x]^2]*Sin[a + b*x])/b}

{(c*Cos[a + b*x]^m)^(5/2), x, 2, (c^2*Cos[a + b*x]^(1 + 2*m)*(Cos[a + b*x]^2)^((1/4)*(-2 - 5*m))*Sqrt[c*Cos[a + b*x]^m]*Hypergeometric2F1[1/2, (1/4)*(2 - 5*m), 3/2, Sin[a + b*x]^2]*Sin[a + b*x])/b}
{(c*Cos[a + b*x]^m)^(3/2), x, 2, (c*Cos[a + b*x]^(1 + m)*(Cos[a + b*x]^2)^((1/4)*(-2 - 3*m))*Sqrt[c*Cos[a + b*x]^m]*Hypergeometric2F1[1/2, (1/4)*(2 - 3*m), 3/2, Sin[a + b*x]^2]*Sin[a + b*x])/b}
{(c*Cos[a + b*x]^m)^(1/2), x, 2, (Cos[a + b*x]*(Cos[a + b*x]^2)^((1/4)*(-2 - m))*Sqrt[c*Cos[a + b*x]^m]*Hypergeometric2F1[1/2, (2 - m)/4, 3/2, Sin[a + b*x]^2]*Sin[a + b*x])/b}
{1/(c*Cos[a + b*x]^m)^(1/2), x, 2, (Cos[a + b*x]*(Cos[a + b*x]^2)^((1/4)*(-2 + m))*Hypergeometric2F1[1/2, (2 + m)/4, 3/2, Sin[a + b*x]^2]*Sin[a + b*x])/(b*Sqrt[c*Cos[a + b*x]^m])}
{1/(c*Cos[a + b*x]^m)^(3/2), x, 2, (Cos[a + b*x]^(1 - m)*(Cos[a + b*x]^2)^((1/4)*(-2 + 3*m))*Hypergeometric2F1[1/2, (1/4)*(2 + 3*m), 3/2, Sin[a + b*x]^2]*Sin[a + b*x])/(b*c*Sqrt[c*Cos[a + b*x]^m])}
{1/(c*Cos[a + b*x]^m)^(5/2), x, 2, (Cos[a + b*x]^(1 - 2*m)*(Cos[a + b*x]^2)^((1/4)*(-2 + 5*m))*Hypergeometric2F1[1/2, (1/4)*(2 + 5*m), 3/2, Sin[a + b*x]^2]*Sin[a + b*x])/(b*c^2*Sqrt[c*Cos[a + b*x]^m])}


{(c*Cos[a + b*x]^m)^(1/m), x, 2, ((c*Cos[a + b*x]^m)^(1/m)*Tan[a + b*x])/b}


(* ::Section::Closed:: *)
(*Integrands of the form (c Tan[a+b x]^m)^n*)


(* ::Subsection::Closed:: *)
(*Integrands of the form (c Tan[a+b x]^1)^n*)


{(a*Tan[x])^(3/2),x, 5, (-a)*(-a^2)^(1/4)*ArcTan[Sqrt[a*Tan[x]]/(-a^2)^(1/4)] - a*(-a^2)^(1/4)*ArcTanh[Sqrt[a*Tan[x]]/(-a^2)^(1/4)] + 2*a*Sqrt[a*Tan[x]]}
{Sqrt[a*Tan[x]], x, 4, (a*ArcTan[Sqrt[a*Tan[x]]/(-a^2)^(1/4)])/(-a^2)^(1/4) - (a*ArcTanh[Sqrt[a*Tan[x]]/(-a^2)^(1/4)])/(-a^2)^(1/4)}
{1/Sqrt[a*Tan[x]], x, 4, -((a*ArcTan[Sqrt[a*Tan[x]]/(-a^2)^(1/4)])/(-a^2)^(3/4)) - (a*ArcTanh[Sqrt[a*Tan[x]]/(-a^2)^(1/4)])/(-a^2)^(3/4)}
{1/(a*Tan[x])^(3/2),x, 5, (a*ArcTan[Sqrt[a*Tan[x]]/(-a^2)^(1/4)])/(-a^2)^(5/4) - (a*ArcTanh[Sqrt[a*Tan[x]]/(-a^2)^(1/4)])/(-a^2)^(5/4) - 2/(a*Sqrt[a*Tan[x]])}


(* ::Subsection::Closed:: *)
(*Integrands of the form (c Tan[a+b x]^2)^n*)


{(Tan[x]^2)^(3/2),x, 3, Cot[x]*Log[Cos[x]]*Sqrt[Tan[x]^2] + (1/2)*Cot[x]*(Tan[x]^2)^(3/2)}
{Sqrt[Tan[x]^2], x, 2, (-Cot[x])*Log[Cos[x]]*Sqrt[Tan[x]^2]}
{1/Sqrt[Tan[x]^2], x, 2, (Log[Sin[x]]*Tan[x])/Sqrt[Tan[x]^2]}
{1/(Tan[x]^2)^(3/2),x, 3, -(Cot[x]/(2*Sqrt[Tan[x]^2])) - (Log[Sin[x]]*Tan[x])/Sqrt[Tan[x]^2]}


{(a*Tan[x]^2)^(3/2),x, 3, a*Cot[x]*Log[Cos[x]]*Sqrt[a*Tan[x]^2] + (1/2)*a*Tan[x]*Sqrt[a*Tan[x]^2]}
{Sqrt[a*Tan[x]^2], x, 2, (-Cot[x])*Log[Cos[x]]*Sqrt[a*Tan[x]^2]}
{1/Sqrt[a*Tan[x]^2], x, 2, (Log[Sin[x]]*Tan[x])/Sqrt[a*Tan[x]^2]}
{1/(a*Tan[x]^2)^(3/2),x, 3, -(Cot[x]/(2*a*Sqrt[a*Tan[x]^2])) - (Log[Sin[x]]*Tan[x])/(a*Sqrt[a*Tan[x]^2])}


(* ::Subsection::Closed:: *)
(*Integrands of the form (c Tan[a+b x]^3)^n*)


{(a*Tan[x]^3)^(3/2),x, 11, (-(2/3))*a*Sqrt[a*Tan[x]^3] - (a*ArcTan[1 - Sqrt[2]*Sqrt[Tan[x]]]*Sqrt[a*Tan[x]^3])/(Sqrt[2]*Tan[x]^(3/2)) + (a*ArcTan[1 + Sqrt[2]*Sqrt[Tan[x]]]*Sqrt[a*Tan[x]^3])/(Sqrt[2]*Tan[x]^(3/2)) + (a*Log[1 - Sqrt[2]*Sqrt[Tan[x]] + Tan[x]]*Sqrt[a*Tan[x]^3])/(2*Sqrt[2]*Tan[x]^(3/2)) - (a*Log[1 + Sqrt[2]*Sqrt[Tan[x]] + Tan[x]]*Sqrt[a*Tan[x]^3])/(2*Sqrt[2]*Tan[x]^(3/2)) + (2/7)*a*Tan[x]^2*Sqrt[a*Tan[x]^3]}
{Sqrt[a*Tan[x]^3], x, 10, 2*Cot[x]*Sqrt[a*Tan[x]^3] + (ArcTan[1 - Sqrt[2]*Sqrt[Tan[x]]]*Sqrt[a*Tan[x]^3])/(Sqrt[2]*Tan[x]^(3/2)) - (ArcTan[1 + Sqrt[2]*Sqrt[Tan[x]]]*Sqrt[a*Tan[x]^3])/(Sqrt[2]*Tan[x]^(3/2)) + (Log[1 - Sqrt[2]*Sqrt[Tan[x]] + Tan[x]]*Sqrt[a*Tan[x]^3])/(2*Sqrt[2]*Tan[x]^(3/2)) - (Log[1 + Sqrt[2]*Sqrt[Tan[x]] + Tan[x]]*Sqrt[a*Tan[x]^3])/(2*Sqrt[2]*Tan[x]^(3/2))}
{1/Sqrt[a*Tan[x]^3], x, 10, -((2*Tan[x])/Sqrt[a*Tan[x]^3]) + (ArcTan[1 - Sqrt[2]*Sqrt[Tan[x]]]*Tan[x]^(3/2))/(Sqrt[2]*Sqrt[a*Tan[x]^3]) - (ArcTan[1 + Sqrt[2]*Sqrt[Tan[x]]]*Tan[x]^(3/2))/(Sqrt[2]*Sqrt[a*Tan[x]^3]) - (Log[1 - Sqrt[2]*Sqrt[Tan[x]] + Tan[x]]*Tan[x]^(3/2))/(2*Sqrt[2]*Sqrt[a*Tan[x]^3]) + (Log[1 + Sqrt[2]*Sqrt[Tan[x]] + Tan[x]]*Tan[x]^(3/2))/(2*Sqrt[2]*Sqrt[a*Tan[x]^3])}
{1/(a*Tan[x]^3)^(3/2),x, 11, 2/(3*a*Sqrt[a*Tan[x]^3]) - (2*Cot[x]^2)/(7*a*Sqrt[a*Tan[x]^3]) - (ArcTan[1 - Sqrt[2]*Sqrt[Tan[x]]]*Tan[x]^(3/2))/(Sqrt[2]*a*Sqrt[a*Tan[x]^3]) + (ArcTan[1 + Sqrt[2]*Sqrt[Tan[x]]]*Tan[x]^(3/2))/(Sqrt[2]*a*Sqrt[a*Tan[x]^3]) - (Log[1 - Sqrt[2]*Sqrt[Tan[x]] + Tan[x]]*Tan[x]^(3/2))/(2*Sqrt[2]*a*Sqrt[a*Tan[x]^3]) + (Log[1 + Sqrt[2]*Sqrt[Tan[x]] + Tan[x]]*Tan[x]^(3/2))/(2*Sqrt[2]*a*Sqrt[a*Tan[x]^3])}


(* ::Subsection::Closed:: *)
(*Integrands of the form (c Tan[a+b x]^4)^n*)


{(a*Tan[x]^4)^(3/2),x, 5, a*Cot[x]*Sqrt[a*Tan[x]^4] - a*x*Cot[x]^2*Sqrt[a*Tan[x]^4] - (1/3)*a*Tan[x]*Sqrt[a*Tan[x]^4] + (1/5)*a*Tan[x]^3*Sqrt[a*Tan[x]^4]}
{Sqrt[a*Tan[x]^4], x, 3, Cot[x]*Sqrt[a*Tan[x]^4] - x*Cot[x]^2*Sqrt[a*Tan[x]^4]}
{1/Sqrt[a*Tan[x]^4], x, 3, -(Tan[x]/Sqrt[a*Tan[x]^4]) - (x*Tan[x]^2)/Sqrt[a*Tan[x]^4]}
{1/(a*Tan[x]^4)^(3/2),x, 5, Cot[x]/(3*a*Sqrt[a*Tan[x]^4]) - Cot[x]^3/(5*a*Sqrt[a*Tan[x]^4]) - Tan[x]/(a*Sqrt[a*Tan[x]^4]) - (x*Tan[x]^2)/(a*Sqrt[a*Tan[x]^4])}


(* ::Subsection:: *)
(*Integrands of the form (c Tan[a+b x]^m)^n*)


(* ::Section::Closed:: *)
(*Integrands of the form (c Cot[a+b x]^m)^n*)


(* ::Subsection::Closed:: *)
(*Integrands of the form (c Cot[a+b x]^1)^n*)


{(a*Cot[x])^(3/2),x, 5, a*(-a^2)^(1/4)*ArcTan[Sqrt[a*Cot[x]]/(-a^2)^(1/4)] + a*(-a^2)^(1/4)*ArcTanh[Sqrt[a*Cot[x]]/(-a^2)^(1/4)] - 2*a*Sqrt[a*Cot[x]]}
{Sqrt[a*Cot[x]], x, 4, -((a*ArcTan[Sqrt[a*Cot[x]]/(-a^2)^(1/4)])/(-a^2)^(1/4)) + (a*ArcTanh[Sqrt[a*Cot[x]]/(-a^2)^(1/4)])/(-a^2)^(1/4)}
{1/Sqrt[a*Cot[x]], x, 4, (a*ArcTan[Sqrt[a*Cot[x]]/(-a^2)^(1/4)])/(-a^2)^(3/4) + (a*ArcTanh[Sqrt[a*Cot[x]]/(-a^2)^(1/4)])/(-a^2)^(3/4)}
{1/(a*Cot[x])^(3/2),x, 5, -((a*ArcTan[Sqrt[a*Cot[x]]/(-a^2)^(1/4)])/(-a^2)^(5/4)) + (a*ArcTanh[Sqrt[a*Cot[x]]/(-a^2)^(1/4)])/(-a^2)^(5/4) + 2/(a*Sqrt[a*Cot[x]])}


(* ::Subsection::Closed:: *)
(*Integrands of the form (c Cot[a+b x]^2)^n*)


{(a*Cot[x]^2)^(3/2),x, 3, (-(1/2))*a*Cot[x]*Sqrt[a*Cot[x]^2] - a*Sqrt[a*Cot[x]^2]*Log[Sin[x]]*Tan[x]}
{Sqrt[a*Cot[x]^2], x, 2, Sqrt[a*Cot[x]^2]*Log[Sin[x]]*Tan[x]}
{1/Sqrt[a*Cot[x]^2], x, 2, -((Cot[x]*Log[Cos[x]])/Sqrt[a*Cot[x]^2])}
{1/(a*Cot[x]^2)^(3/2),x, 3, (Cot[x]*Log[Cos[x]])/(a*Sqrt[a*Cot[x]^2]) + Tan[x]/(2*a*Sqrt[a*Cot[x]^2])}


(* ::Subsection::Closed:: *)
(*Integrands of the form (c Cot[a+b x]^3)^n*)


{(a*Cot[x]^3)^(3/2),x, 11, (2/3)*a*Sqrt[a*Cot[x]^3] + (a*ArcTan[1 - Sqrt[2]*Sqrt[Cot[x]]]*Sqrt[a*Cot[x]^3])/(Sqrt[2]*Cot[x]^(3/2)) - (a*ArcTan[1 + Sqrt[2]*Sqrt[Cot[x]]]*Sqrt[a*Cot[x]^3])/(Sqrt[2]*Cot[x]^(3/2)) - (2/7)*a*Cot[x]^2*Sqrt[a*Cot[x]^3] - (a*Sqrt[a*Cot[x]^3]*Log[1 - Sqrt[2]*Sqrt[Cot[x]] + Cot[x]])/(2*Sqrt[2]*Cot[x]^(3/2)) + (a*Sqrt[a*Cot[x]^3]*Log[1 + Sqrt[2]*Sqrt[Cot[x]] + Cot[x]])/(2*Sqrt[2]*Cot[x]^(3/2))}
{Sqrt[a*Cot[x]^3], x, 10, -((ArcTan[1 - Sqrt[2]*Sqrt[Cot[x]]]*Sqrt[a*Cot[x]^3])/(Sqrt[2]*Cot[x]^(3/2))) + (ArcTan[1 + Sqrt[2]*Sqrt[Cot[x]]]*Sqrt[a*Cot[x]^3])/(Sqrt[2]*Cot[x]^(3/2)) - (Sqrt[a*Cot[x]^3]*Log[1 - Sqrt[2]*Sqrt[Cot[x]] + Cot[x]])/(2*Sqrt[2]*Cot[x]^(3/2)) + (Sqrt[a*Cot[x]^3]*Log[1 + Sqrt[2]*Sqrt[Cot[x]] + Cot[x]])/(2*Sqrt[2]*Cot[x]^(3/2)) - 2*Sqrt[a*Cot[x]^3]*Tan[x]}
{1/Sqrt[a*Cot[x]^3], x, 10, (2*Cot[x])/Sqrt[a*Cot[x]^3] - (ArcTan[1 - Sqrt[2]*Sqrt[Cot[x]]]*Cot[x]^(3/2))/(Sqrt[2]*Sqrt[a*Cot[x]^3]) + (ArcTan[1 + Sqrt[2]*Sqrt[Cot[x]]]*Cot[x]^(3/2))/(Sqrt[2]*Sqrt[a*Cot[x]^3]) + (Cot[x]^(3/2)*Log[1 - Sqrt[2]*Sqrt[Cot[x]] + Cot[x]])/(2*Sqrt[2]*Sqrt[a*Cot[x]^3]) - (Cot[x]^(3/2)*Log[1 + Sqrt[2]*Sqrt[Cot[x]] + Cot[x]])/(2*Sqrt[2]*Sqrt[a*Cot[x]^3])}
{1/(a*Cot[x]^3)^(3/2),x, 11, -(2/(3*a*Sqrt[a*Cot[x]^3])) + (ArcTan[1 - Sqrt[2]*Sqrt[Cot[x]]]*Cot[x]^(3/2))/(Sqrt[2]*a*Sqrt[a*Cot[x]^3]) - (ArcTan[1 + Sqrt[2]*Sqrt[Cot[x]]]*Cot[x]^(3/2))/(Sqrt[2]*a*Sqrt[a*Cot[x]^3]) + (Cot[x]^(3/2)*Log[1 - Sqrt[2]*Sqrt[Cot[x]] + Cot[x]])/(2*Sqrt[2]*a*Sqrt[a*Cot[x]^3]) - (Cot[x]^(3/2)*Log[1 + Sqrt[2]*Sqrt[Cot[x]] + Cot[x]])/(2*Sqrt[2]*a*Sqrt[a*Cot[x]^3]) + (2*Tan[x]^2)/(7*a*Sqrt[a*Cot[x]^3])}


(* ::Subsection::Closed:: *)
(*Integrands of the form (c Cot[a+b x]^4)^n*)


{(a*Cot[x]^4)^(3/2),x, 5, (1/3)*a*Cot[x]*Sqrt[a*Cot[x]^4] - (1/5)*a*Cot[x]^3*Sqrt[a*Cot[x]^4] - a*Sqrt[a*Cot[x]^4]*Tan[x] - a*x*Sqrt[a*Cot[x]^4]*Tan[x]^2}
{Sqrt[a*Cot[x]^4], x, 3, (-Sqrt[a*Cot[x]^4])*Tan[x] - x*Sqrt[a*Cot[x]^4]*Tan[x]^2}
{1/Sqrt[a*Cot[x]^4], x, 3, Cot[x]/Sqrt[a*Cot[x]^4] - (x*Cot[x]^2)/Sqrt[a*Cot[x]^4]}
{1/(a*Cot[x]^4)^(3/2),x, 5, Cot[x]/(a*Sqrt[a*Cot[x]^4]) - (x*Cot[x]^2)/(a*Sqrt[a*Cot[x]^4]) - Tan[x]/(3*a*Sqrt[a*Cot[x]^4]) + Tan[x]^3/(5*a*Sqrt[a*Cot[x]^4])}


(* ::Subsection:: *)
(*Integrands of the form (c Cot[a+b x]^m)^n*)


(* ::Section::Closed:: *)
(*Integrands of the form (c Sec[a+b x]^m)^n*)


(* ::Subsection::Closed:: *)
(*Integrands of the form (c Sec[a+b x]^2)^n*)


{(Sec[x]^2)^(7/2), x, 5, (5/16)*ArcSinh[Tan[x]] + (5/16)*Tan[x]*Sqrt[1 + Tan[x]^2] + (5/24)*Tan[x]*(1 + Tan[x]^2)^(3/2) + (1/6)*Tan[x]*(1 + Tan[x]^2)^(5/2)}
{(Sec[x]^2)^(5/2), x, 4, (3/8)*ArcSinh[Tan[x]] + (3/8)*Tan[x]*Sqrt[1 + Tan[x]^2] + (1/4)*Tan[x]*(1 + Tan[x]^2)^(3/2)}
{(Sec[x]^2)^(3/2), x, 3, (1/2)*ArcSinh[Tan[x]] + (1/2)*Tan[x]*Sqrt[1 + Tan[x]^2]}
{(Sec[x]^2)^(1/2), x, 2, ArcSinh[Tan[x]]}
{1/(Sec[x]^2)^(1/2), x, 2, Tan[x]/Sqrt[Sec[x]^2], Tan[x]/Sqrt[1 + Tan[x]^2]}
{1/(Sec[x]^2)^(3/2), x, 3, Tan[x]/(3*(1 + Tan[x]^2)^(3/2)) + (2*Tan[x])/(3*Sqrt[1 + Tan[x]^2])}
{1/(Sec[x]^2)^(5/2), x, 4, Tan[x]/(5*(1 + Tan[x]^2)^(5/2)) + (4*Tan[x])/(15*(1 + Tan[x]^2)^(3/2)) + (8*Tan[x])/(15*Sqrt[1 + Tan[x]^2])}
{1/(Sec[x]^2)^(7/2), x, 5, Tan[x]/(7*(1 + Tan[x]^2)^(7/2)) + (6*Tan[x])/(35*(1 + Tan[x]^2)^(5/2)) + (8*Tan[x])/(35*(1 + Tan[x]^2)^(3/2)) + (16*Tan[x])/(35*Sqrt[1 + Tan[x]^2])}


{(a*Sec[x]^2)^(7/2), x, 5, (5/16)*a^3*ArcTanh[Sin[x]]*Cos[x]*Sqrt[a*Sec[x]^2] + (5/16)*a^3*Sqrt[a*Sec[x]^2]*Tan[x] + (5/24)*a^3*Sec[x]^2*Sqrt[a*Sec[x]^2]*Tan[x] + (1/6)*a^3*Sec[x]^4*Sqrt[a*Sec[x]^2]*Tan[x]}
{(a*Sec[x]^2)^(5/2), x, 4, (3/8)*a^2*ArcTanh[Sin[x]]*Cos[x]*Sqrt[a*Sec[x]^2] + (3/8)*a^2*Sqrt[a*Sec[x]^2]*Tan[x] + (1/4)*a^2*Sec[x]^2*Sqrt[a*Sec[x]^2]*Tan[x]}
{(a*Sec[x]^2)^(3/2), x, 3, (1/2)*a*ArcTanh[Sin[x]]*Cos[x]*Sqrt[a*Sec[x]^2] + (1/2)*a*Sqrt[a*Sec[x]^2]*Tan[x]}
{(a*Sec[x]^2)^(1/2), x, 2, ArcTanh[Sin[x]]*Cos[x]*Sqrt[a*Sec[x]^2]}
{1/(a*Sec[x]^2)^(1/2), x, 2, Tan[x]/Sqrt[a*Sec[x]^2]}
{1/(a*Sec[x]^2)^(3/2), x, 3, Tan[x]/(a*Sqrt[a*Sec[x]^2]) - (Sin[x]^2*Tan[x])/(3*a*Sqrt[a*Sec[x]^2])}
{1/(a*Sec[x]^2)^(5/2), x, 3, Tan[x]/(a^2*Sqrt[a*Sec[x]^2]) - (2*Sin[x]^2*Tan[x])/(3*a^2*Sqrt[a*Sec[x]^2]) + (Sin[x]^4*Tan[x])/(5*a^2*Sqrt[a*Sec[x]^2])}
{1/(a*Sec[x]^2)^(7/2), x, 3, Tan[x]/(a^3*Sqrt[a*Sec[x]^2]) - (Sin[x]^2*Tan[x])/(a^3*Sqrt[a*Sec[x]^2]) + (3*Sin[x]^4*Tan[x])/(5*a^3*Sqrt[a*Sec[x]^2]) - (Sin[x]^6*Tan[x])/(7*a^3*Sqrt[a*Sec[x]^2])}


(* ::Subsection::Closed:: *)
(*Integrands of the form (c Sec[a+b x]^3)^n*)


{(a*Sec[x]^3)^(5/2), x, 7, (-(154/195))*a^2*Cos[x]^(3/2)*EllipticE[x/2, 2]*Sqrt[a*Sec[x]^3] + (154/195)*a^2*Cos[x]*Sqrt[a*Sec[x]^3]*Sin[x] + (154/585)*a^2*Sqrt[a*Sec[x]^3]*Tan[x] + (22/117)*a^2*Sec[x]^2*Sqrt[a*Sec[x]^3]*Tan[x] + (2/13)*a^2*Sec[x]^4*Sqrt[a*Sec[x]^3]*Tan[x]}
{(a*Sec[x]^3)^(3/2), x, 5, (10/21)*a*Cos[x]^(3/2)*EllipticF[x/2, 2]*Sqrt[a*Sec[x]^3] + (10/21)*a*Sqrt[a*Sec[x]^3]*Sin[x] + (2/7)*a*Sec[x]*Sqrt[a*Sec[x]^3]*Tan[x]}
{(a*Sec[x]^3)^(1/2), x, 4, -2*Cos[x]^(3/2)*EllipticE[x/2, 2]*Sqrt[a*Sec[x]^3] + 2*Cos[x]*Sqrt[a*Sec[x]^3]*Sin[x]}
{1/(a*Sec[x]^3)^(1/2), x, 4, (2*EllipticF[x/2, 2])/(3*Cos[x]^(3/2)*Sqrt[a*Sec[x]^3]) + (2*Tan[x])/(3*Sqrt[a*Sec[x]^3])}
{1/(a*Sec[x]^3)^(3/2), x, 5, (14*EllipticE[x/2, 2])/(15*a*Cos[x]^(3/2)*Sqrt[a*Sec[x]^3]) + (14*Sin[x])/(45*a*Sqrt[a*Sec[x]^3]) + (2*Cos[x]^2*Sin[x])/(9*a*Sqrt[a*Sec[x]^3])}
{1/(a*Sec[x]^3)^(5/2), x, 7, (26*EllipticF[x/2, 2])/(77*a^2*Cos[x]^(3/2)*Sqrt[a*Sec[x]^3]) + (78*Cos[x]*Sin[x])/(385*a^2*Sqrt[a*Sec[x]^3]) + (26*Cos[x]^3*Sin[x])/(165*a^2*Sqrt[a*Sec[x]^3]) + (2*Cos[x]^5*Sin[x])/(15*a^2*Sqrt[a*Sec[x]^3]) + (26*Tan[x])/(77*a^2*Sqrt[a*Sec[x]^3])}


(* ::Subsection::Closed:: *)
(*Integrands of the form (c Sec[a+b x]^4)^n*)


{(a*Sec[x]^4)^(7/2), x, 3, a^3*Cos[x]*Sqrt[a*Sec[x]^4]*Sin[x] + 2*a^3*Sqrt[a*Sec[x]^4]*Sin[x]^2*Tan[x] + 3*a^3*Sqrt[a*Sec[x]^4]*Sin[x]^2*Tan[x]^3 + (20/7)*a^3*Sqrt[a*Sec[x]^4]*Sin[x]^2*Tan[x]^5 + (5/3)*a^3*Sqrt[a*Sec[x]^4]*Sin[x]^2*Tan[x]^7 + (6/11)*a^3*Sqrt[a*Sec[x]^4]*Sin[x]^2*Tan[x]^9 + (1/13)*a^3*Sqrt[a*Sec[x]^4]*Sin[x]^2*Tan[x]^11}
{(a*Sec[x]^4)^(5/2), x, 3, a^2*Cos[x]*Sqrt[a*Sec[x]^4]*Sin[x] + (4/3)*a^2*Sqrt[a*Sec[x]^4]*Sin[x]^2*Tan[x] + (6/5)*a^2*Sqrt[a*Sec[x]^4]*Sin[x]^2*Tan[x]^3 + (4/7)*a^2*Sqrt[a*Sec[x]^4]*Sin[x]^2*Tan[x]^5 + (1/9)*a^2*Sqrt[a*Sec[x]^4]*Sin[x]^2*Tan[x]^7}
{(a*Sec[x]^4)^(3/2), x, 3, a*Cos[x]*Sqrt[a*Sec[x]^4]*Sin[x] + (2/3)*a*Sqrt[a*Sec[x]^4]*Sin[x]^2*Tan[x] + (1/5)*a*Sqrt[a*Sec[x]^4]*Sin[x]^2*Tan[x]^3}
{(a*Sec[x]^4)^(1/2), x, 2, Cos[x]*Sqrt[a*Sec[x]^4]*Sin[x]}
{1/(a*Sec[x]^4)^(1/2), x, 2, (x*Sec[x]^2)/(2*Sqrt[a*Sec[x]^4]) + Tan[x]/(2*Sqrt[a*Sec[x]^4])}
{1/(a*Sec[x]^4)^(3/2), x, 4, (5*x*Sec[x]^2)/(16*a*Sqrt[a*Sec[x]^4]) + (5*Cos[x]*Sin[x])/(24*a*Sqrt[a*Sec[x]^4]) + (Cos[x]^3*Sin[x])/(6*a*Sqrt[a*Sec[x]^4]) + (5*Tan[x])/(16*a*Sqrt[a*Sec[x]^4])}
{1/(a*Sec[x]^4)^(5/2), x, 6, (63*x*Sec[x]^2)/(256*a^2*Sqrt[a*Sec[x]^4]) + (21*Cos[x]*Sin[x])/(128*a^2*Sqrt[a*Sec[x]^4]) + (21*Cos[x]^3*Sin[x])/(160*a^2*Sqrt[a*Sec[x]^4]) + (9*Cos[x]^5*Sin[x])/(80*a^2*Sqrt[a*Sec[x]^4]) + (Cos[x]^7*Sin[x])/(10*a^2*Sqrt[a*Sec[x]^4]) + (63*Tan[x])/(256*a^2*Sqrt[a*Sec[x]^4])}


(* ::Subsection:: *)
(*Integrands of the form (c Sec[a+b x]^m)^n*)


(* ::Section::Closed:: *)
(*Integrands of the form (c Csc[a+b x]^m)^n*)


(* ::Subsection::Closed:: *)
(*Integrands of the form (c Csc[a+b x]^2)^n*)


{(Csc[x]^2)^(7/2), x, 5, (-(5/16))*ArcSinh[Cot[x]] - (5/16)*Cot[x]*Sqrt[1 + Cot[x]^2] - (5/24)*Cot[x]*(1 + Cot[x]^2)^(3/2) - (1/6)*Cot[x]*(1 + Cot[x]^2)^(5/2)}
{(Csc[x]^2)^(5/2), x, 4, (-(3/8))*ArcSinh[Cot[x]] - (3/8)*Cot[x]*Sqrt[1 + Cot[x]^2] - (1/4)*Cot[x]*(1 + Cot[x]^2)^(3/2)}
{(Csc[x]^2)^(3/2), x, 3, (-(1/2))*ArcSinh[Cot[x]] - (1/2)*Cot[x]*Sqrt[1 + Cot[x]^2]}
{(Csc[x]^2)^(1/2), x, 2, -ArcSinh[Cot[x]]}
{1/(Csc[x]^2)^(1/2), x, 2, -(Cot[x]/Sqrt[Csc[x]^2]), -(Cot[x]/Sqrt[1 + Cot[x]^2])}
{1/(Csc[x]^2)^(3/2), x, 3, -(Cot[x]/(3*(1 + Cot[x]^2)^(3/2))) - (2*Cot[x])/(3*Sqrt[1 + Cot[x]^2])}
{1/(Csc[x]^2)^(5/2), x, 4, -(Cot[x]/(5*(1 + Cot[x]^2)^(5/2))) - (4*Cot[x])/(15*(1 + Cot[x]^2)^(3/2)) - (8*Cot[x])/(15*Sqrt[1 + Cot[x]^2])}
{1/(Csc[x]^2)^(7/2), x, 5, -(Cot[x]/(7*(1 + Cot[x]^2)^(7/2))) - (6*Cot[x])/(35*(1 + Cot[x]^2)^(5/2)) - (8*Cot[x])/(35*(1 + Cot[x]^2)^(3/2)) - (16*Cot[x])/(35*Sqrt[1 + Cot[x]^2])}


{(a*Csc[x]^2)^(7/2), x, 5, (-(5/16))*a^3*Cot[x]*Sqrt[a*Csc[x]^2] - (5/24)*a^3*Cot[x]*Csc[x]^2*Sqrt[a*Csc[x]^2] - (1/6)*a^3*Cot[x]*Csc[x]^4*Sqrt[a*Csc[x]^2] - (5/16)*a^3*ArcTanh[Cos[x]]*Sqrt[a*Csc[x]^2]*Sin[x]}
{(a*Csc[x]^2)^(5/2), x, 4, (-(3/8))*a^2*Cot[x]*Sqrt[a*Csc[x]^2] - (1/4)*a^2*Cot[x]*Csc[x]^2*Sqrt[a*Csc[x]^2] - (3/8)*a^2*ArcTanh[Cos[x]]*Sqrt[a*Csc[x]^2]*Sin[x]}
{(a*Csc[x]^2)^(3/2), x, 3, (-(1/2))*a*Cot[x]*Sqrt[a*Csc[x]^2] - (1/2)*a*ArcTanh[Cos[x]]*Sqrt[a*Csc[x]^2]*Sin[x]}
{(a*Csc[x]^2)^(1/2), x, 2, (-ArcTanh[Cos[x]])*Sqrt[a*Csc[x]^2]*Sin[x]}
{1/(a*Csc[x]^2)^(1/2), x, 2, -(Cot[x]/Sqrt[a*Csc[x]^2])}
{1/(a*Csc[x]^2)^(3/2), x, 3, -(Cot[x]/(a*Sqrt[a*Csc[x]^2])) + (Cos[x]^2*Cot[x])/(3*a*Sqrt[a*Csc[x]^2])}
{1/(a*Csc[x]^2)^(5/2), x, 3, -(Cot[x]/(a^2*Sqrt[a*Csc[x]^2])) + (2*Cos[x]^2*Cot[x])/(3*a^2*Sqrt[a*Csc[x]^2]) - (Cos[x]^4*Cot[x])/(5*a^2*Sqrt[a*Csc[x]^2])}
{1/(a*Csc[x]^2)^(7/2), x, 3, -(Cot[x]/(a^3*Sqrt[a*Csc[x]^2])) + (Cos[x]^2*Cot[x])/(a^3*Sqrt[a*Csc[x]^2]) - (3*Cos[x]^4*Cot[x])/(5*a^3*Sqrt[a*Csc[x]^2]) + (Cos[x]^6*Cot[x])/(7*a^3*Sqrt[a*Csc[x]^2])}


(* ::Subsection::Closed:: *)
(*Integrands of the form (c Csc[a+b x]^3)^n*)


{(a*Csc[x]^3)^(5/2), x, 7, (-(154/585))*a^2*Cot[x]*Sqrt[a*Csc[x]^3] - (22/117)*a^2*Cot[x]*Csc[x]^2*Sqrt[a*Csc[x]^3] - (2/13)*a^2*Cot[x]*Csc[x]^4*Sqrt[a*Csc[x]^3] - (154/195)*a^2*Cos[x]*Sqrt[a*Csc[x]^3]*Sin[x] + (154/195)*a^2*Sqrt[a*Csc[x]^3]*EllipticE[Pi/4 - x/2, 2]*Sin[x]^(3/2)}
{(a*Csc[x]^3)^(3/2), x, 5, (-(10/21))*a*Cos[x]*Sqrt[a*Csc[x]^3] - (2/7)*a*Cot[x]*Csc[x]*Sqrt[a*Csc[x]^3] - (10/21)*a*Sqrt[a*Csc[x]^3]*EllipticF[Pi/4 - x/2, 2]*Sin[x]^(3/2)}
{(a*Csc[x]^3)^(1/2), x, 4, -2*Cos[x]*Sqrt[a*Csc[x]^3]*Sin[x] + 2*Sqrt[a*Csc[x]^3]*EllipticE[Pi/4 - x/2, 2]*Sin[x]^(3/2)}
{1/(a*Csc[x]^3)^(1/2), x, 4, -((2*Cot[x])/(3*Sqrt[a*Csc[x]^3])) - (2*EllipticF[Pi/4 - x/2, 2])/(3*Sqrt[a*Csc[x]^3]*Sin[x]^(3/2))}
{1/(a*Csc[x]^3)^(3/2), x, 5, -((14*Cos[x])/(45*a*Sqrt[a*Csc[x]^3])) - (14*EllipticE[Pi/4 - x/2, 2])/(15*a*Sqrt[a*Csc[x]^3]*Sin[x]^(3/2)) - (2*Cos[x]*Sin[x]^2)/(9*a*Sqrt[a*Csc[x]^3])}
{1/(a*Csc[x]^3)^(5/2), x, 7, -((26*Cot[x])/(77*a^2*Sqrt[a*Csc[x]^3])) - (26*EllipticF[Pi/4 - x/2, 2])/(77*a^2*Sqrt[a*Csc[x]^3]*Sin[x]^(3/2)) - (78*Cos[x]*Sin[x])/(385*a^2*Sqrt[a*Csc[x]^3]) - (26*Cos[x]*Sin[x]^3)/(165*a^2*Sqrt[a*Csc[x]^3]) - (2*Cos[x]*Sin[x]^5)/(15*a^2*Sqrt[a*Csc[x]^3])}


(* ::Subsection::Closed:: *)
(*Integrands of the form (c Csc[a+b x]^4)^n*)


{(a*Csc[x]^4)^(7/2), x, 3, -2*a^3*Cos[x]^2*Cot[x]*Sqrt[a*Csc[x]^4] - 3*a^3*Cos[x]^2*Cot[x]^3*Sqrt[a*Csc[x]^4] - (20/7)*a^3*Cos[x]^2*Cot[x]^5*Sqrt[a*Csc[x]^4] - (5/3)*a^3*Cos[x]^2*Cot[x]^7*Sqrt[a*Csc[x]^4] - (6/11)*a^3*Cos[x]^2*Cot[x]^9*Sqrt[a*Csc[x]^4] - (1/13)*a^3*Cos[x]^2*Cot[x]^11*Sqrt[a*Csc[x]^4] - a^3*Cos[x]*Sqrt[a*Csc[x]^4]*Sin[x]}
{(a*Csc[x]^4)^(5/2), x, 3, (-(4/3))*a^2*Cos[x]^2*Cot[x]*Sqrt[a*Csc[x]^4] - (6/5)*a^2*Cos[x]^2*Cot[x]^3*Sqrt[a*Csc[x]^4] - (4/7)*a^2*Cos[x]^2*Cot[x]^5*Sqrt[a*Csc[x]^4] - (1/9)*a^2*Cos[x]^2*Cot[x]^7*Sqrt[a*Csc[x]^4] - a^2*Cos[x]*Sqrt[a*Csc[x]^4]*Sin[x]}
{(a*Csc[x]^4)^(3/2), x, 3, (-(2/3))*a*Cos[x]^2*Cot[x]*Sqrt[a*Csc[x]^4] - (1/5)*a*Cos[x]^2*Cot[x]^3*Sqrt[a*Csc[x]^4] - a*Cos[x]*Sqrt[a*Csc[x]^4]*Sin[x]}
{(a*Csc[x]^4)^(1/2), x, 2, (-Cos[x])*Sqrt[a*Csc[x]^4]*Sin[x]}
{1/(a*Csc[x]^4)^(1/2), x, 2, -(Cot[x]/(2*Sqrt[a*Csc[x]^4])) + (x*Csc[x]^2)/(2*Sqrt[a*Csc[x]^4])}
{1/(a*Csc[x]^4)^(3/2), x, 4, -((5*Cot[x])/(16*a*Sqrt[a*Csc[x]^4])) + (5*x*Csc[x]^2)/(16*a*Sqrt[a*Csc[x]^4]) - (5*Cos[x]*Sin[x])/(24*a*Sqrt[a*Csc[x]^4]) - (Cos[x]*Sin[x]^3)/(6*a*Sqrt[a*Csc[x]^4])}
{1/(a*Csc[x]^4)^(5/2), x, 6, -((63*Cot[x])/(256*a^2*Sqrt[a*Csc[x]^4])) + (63*x*Csc[x]^2)/(256*a^2*Sqrt[a*Csc[x]^4]) - (21*Cos[x]*Sin[x])/(128*a^2*Sqrt[a*Csc[x]^4]) - (21*Cos[x]*Sin[x]^3)/(160*a^2*Sqrt[a*Csc[x]^4]) - (9*Cos[x]*Sin[x]^5)/(80*a^2*Sqrt[a*Csc[x]^4]) - (Cos[x]*Sin[x]^7)/(10*a^2*Sqrt[a*Csc[x]^4])}


(* ::Subsection:: *)
(*Integrands of the form (c Csc[a+b x]^m)^n*)
