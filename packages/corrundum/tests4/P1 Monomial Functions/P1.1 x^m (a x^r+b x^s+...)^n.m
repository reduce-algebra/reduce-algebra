(* ::Package:: *)

(* ::Title:: *)
(*Integration problems of the form u f[(a x^n)^p,x]*)


(* ::Section::Closed:: *)
(*Integrands of the form x^m (a x^n)^p*)


(* ::Subsection::Closed:: *)
(*Integrands of the form x^m (a x^n)^(p/2)*)


(* ::Subsubsection::Closed:: *)
(*p>0*)


{x^m*Sqrt[a*x^n], x, 2, (2*x^(1 + m)*Sqrt[a*x^n])/(2 + 2*m + n)}
{Sqrt[a*x^n]/x^(n/2+1), x, 2, (Sqrt[a*x^n]*Log[x])/x^(n/2)}

{x^2*Sqrt[a*x^n], x, 2, (2*x^3*Sqrt[a*x^n])/(6 + n)}
{x^1*Sqrt[a*x^n], x, 2, (2*x^2*Sqrt[a*x^n])/(4 + n)}
{x^0*Sqrt[a*x^n], x, 2, (2*x*Sqrt[a*x^n])/(2 + n)}
{Sqrt[a*x^n]/x^1, x, 2, (2*Sqrt[a*x^n])/n}
{Sqrt[a*x^n]/x^2, x, 2, -((2*Sqrt[a*x^n])/((2 - n)*x))}
{Sqrt[a*x^n]/x^3, x, 2, -((2*Sqrt[a*x^n])/((4 - n)*x^2))}


{x^m*(a*x^n)^(3/2), x, 2, (2*a*x^(1 + m + n)*Sqrt[a*x^n])/(2 + 2*m + 3*n)}
{(a*x^n)^(3/2)/x^(3*n/2+1), x, 2, (a*Sqrt[a*x^n]*Log[x])/x^(n/2)}

{x^2*(a*x^n)^(3/2), x, 2, (2*a*x^(3 + n)*Sqrt[a*x^n])/(3*(2 + n))}
{x^1*(a*x^n)^(3/2), x, 2, (2*a*x^(2 + n)*Sqrt[a*x^n])/(4 + 3*n)}
{x^0*(a*x^n)^(3/2), x, 2, (2*a*x^(1 + n)*Sqrt[a*x^n])/(2 + 3*n)}
{(a*x^n)^(3/2)/x^1, x, 2, (2*a*x^n*Sqrt[a*x^n])/(3*n)}
{(a*x^n)^(3/2)/x^2, x, 2, -((2*a*x^(-1 + n)*Sqrt[a*x^n])/(2 - 3*n))}
{(a*x^n)^(3/2)/x^3, x, 2, -((2*a*x^(-2 + n)*Sqrt[a*x^n])/(4 - 3*n))}


{Sqrt[a*x^3], x, 2, (2/5)*x*Sqrt[a*x^3]}
{Sqrt[a*x^2], x, 2, (1/2)*x*Sqrt[a*x^2]}
{Sqrt[a*x^1], x, 1, (2*(a*x)^(3/2))/(3*a)}
{Sqrt[a/x^1], x, 2, 2*Sqrt[a/x]*x}
{Sqrt[a/x^2], x, 2, Sqrt[a/x^2]*x*Log[x]}
{Sqrt[a/x^3], x, 2, -2*Sqrt[a/x^3]*x}


{(a*x^3)^(3/2), x, 2, (2/11)*a*x^4*Sqrt[a*x^3]}
{(a*x^2)^(3/2), x, 2, (1/4)*a*x^3*Sqrt[a*x^2]}
{(a*x^1)^(3/2), x, 1, (2*(a*x)^(5/2))/(5*a)}
{(a/x^1)^(3/2), x, 2, -2*a*Sqrt[a/x]}
{(a/x^2)^(3/2), x, 2, -((a*Sqrt[a/x^2])/(2*x))}
{(a/x^3)^(3/2), x, 2, -((2*a*Sqrt[a/x^3])/(7*x^2))}


(* ::Subsubsection::Closed:: *)
(*p<0*)


{x^m/Sqrt[a*x^n], x, 2, (2*x^(1 + m))/((2 + 2*m - n)*Sqrt[a*x^n])}
{x^(n/2-1)/Sqrt[a*x^n], x, 2, (x^(n/2)*Log[x])/Sqrt[a*x^n]}

{x^2/Sqrt[a*x^n], x, 2, (2*x^3)/((6 - n)*Sqrt[a*x^n])}
{x^1/Sqrt[a*x^n], x, 2, (2*x^2)/((4 - n)*Sqrt[a*x^n])}
{x^0/Sqrt[a*x^n], x, 2, (2*x)/((2 - n)*Sqrt[a*x^n])}
{Sqrt[a*x^n]/x^1, x, 2, (2*Sqrt[a*x^n])/n}
{Sqrt[a*x^n]/x^2, x, 2, -((2*Sqrt[a*x^n])/((2 - n)*x))}
{Sqrt[a*x^n]/x^3, x, 2, -((2*Sqrt[a*x^n])/((4 - n)*x^2))}


{x^m/(a*x^n)^(3/2), x, 2, (2*x^(1 + m - n))/(a*(2 + 2*m - 3*n)*Sqrt[a*x^n])}
{x^(3*n/2-1)/(a*x^n)^(3/2), x, 2, (x^(n/2)*Log[x])/(a*Sqrt[a*x^n])}

{x^2/(a*x^n)^(3/2), x, 2, (2*x^(3 - n))/(3*a*(2 - n)*Sqrt[a*x^n])}
{x^1/(a*x^n)^(3/2), x, 2, (2*x^(2 - n))/(a*(4 - 3*n)*Sqrt[a*x^n])}
{x^0/(a*x^n)^(3/2), x, 2, (2*x^(1 - n))/(a*(2 - 3*n)*Sqrt[a*x^n])}
{(a*x^n)^(3/2)/x^1, x, 2, (2*a*x^n*Sqrt[a*x^n])/(3*n)}
{(a*x^n)^(3/2)/x^2, x, 2, -((2*a*x^(-1 + n)*Sqrt[a*x^n])/(2 - 3*n))}
{(a*x^n)^(3/2)/x^3, x, 2, -((2*a*x^(-2 + n)*Sqrt[a*x^n])/(4 - 3*n))}


{1/Sqrt[a*x^3], x, 2, -((2*x)/Sqrt[a*x^3])}
{1/Sqrt[a*x^2], x, 2, (x*Log[x])/Sqrt[a*x^2]}
{1/Sqrt[a*x^1], x, 1, (2*Sqrt[a*x])/a}
{1/Sqrt[a/x^1], x, 2, (2*x)/(3*Sqrt[a/x])}
{1/Sqrt[a/x^2], x, 2, x/(2*Sqrt[a/x^2])}
{1/Sqrt[a/x^3], x, 2, (2*x)/(5*Sqrt[a/x^3])}


{1/(a*x^3)^(3/2), x, 2, -(2/(7*a*x^2*Sqrt[a*x^3]))}
{1/(a*x^2)^(3/2), x, 2, -(1/(2*a*x*Sqrt[a*x^2]))}
{1/(a*x^1)^(3/2), x, 1, -(2/(a*Sqrt[a*x]))}
{1/(a/x^1)^(3/2), x, 2, (2*x^2)/(5*a*Sqrt[a/x])}
{1/(a/x^2)^(3/2), x, 2, x^3/(4*a*Sqrt[a/x^2])}
{1/(a/x^3)^(3/2), x, 2, (2*x^4)/(11*a*Sqrt[a/x^3])}


(* ::Subsection::Closed:: *)
(*Integrands of the form x^m (a x^n)^(p/3)*)


(* ::Subsubsection::Closed:: *)
(*p>0*)


{(a*x^n)^(1/3), x, 2, (3*x*(a*x^n)^(1/3))/(3 + n)}

{(a*x^3)^(1/3), x, 2, (1/2)*x*(a*x^3)^(1/3)}
{(a*x^2)^(1/3), x, 2, (3/5)*x*(a*x^2)^(1/3)}
{(a*x^1)^(1/3), x, 1, (3*(a*x)^(4/3))/(4*a)}
{(a/x^1)^(1/3), x, 2, (3/2)*(a/x)^(1/3)*x}
{(a/x^2)^(1/3), x, 2, 3*(a/x^2)^(1/3)*x}
{(a/x^3)^(1/3), x, 2, (a/x^3)^(1/3)*x*Log[x]}


{(a*x^n)^(2/3), x, 2, (3*x*(a*x^n)^(2/3))/(3 + 2*n)}

{(a*x^3)^(2/3), x, 2, (1/3)*x*(a*x^3)^(2/3)}
{(a*x^2)^(2/3), x, 2, (3/7)*x*(a*x^2)^(2/3)}
{(a*x^1)^(2/3), x, 1, (3*(a*x)^(5/3))/(5*a)}
{(a/x^1)^(2/3), x, 2, 3*(a/x)^(2/3)*x}
{(a/x^2)^(2/3), x, 2, -3*(a/x^2)^(2/3)*x}
{(a/x^3)^(2/3), x, 2, (-(a/x^3)^(2/3))*x}


(* ::Subsubsection::Closed:: *)
(*p<0*)


{1/(a*x^n)^(1/3), x, 2, (3*x)/((3 - n)*(a*x^n)^(1/3))}

{1/(a*x^3)^(1/3), x, 2, (x*Log[x])/(a*x^3)^(1/3)}
{1/(a*x^2)^(1/3), x, 2, (3*x)/(a*x^2)^(1/3)}
{1/(a*x^1)^(1/3), x, 1, (3*(a*x)^(2/3))/(2*a)}
{1/(a/x^1)^(1/3), x, 2, (3*x)/(4*(a/x)^(1/3))}
{1/(a/x^2)^(1/3), x, 2, (3*x)/(5*(a/x^2)^(1/3))}
{1/(a/x^3)^(1/3), x, 2, x/(2*(a/x^3)^(1/3))}


{1/(a*x^n)^(2/3), x, 2, (3*x)/((3 - 2*n)*(a*x^n)^(2/3))}

{1/(a*x^3)^(2/3), x, 2, -(x/(a*x^3)^(2/3))}
{1/(a*x^2)^(2/3), x, 2, -((3*x)/(a*x^2)^(2/3))}
{1/(a*x^1)^(2/3), x, 1, (3*(a*x)^(1/3))/a}
{1/(a/x^1)^(2/3), x, 2, (3*x)/(5*(a/x)^(2/3))}
{1/(a/x^2)^(2/3), x, 2, (3*x)/(7*(a/x^2)^(2/3))}
{1/(a/x^3)^(2/3), x, 2, x/(3*(a/x^3)^(2/3))}


(* ::Subsection::Closed:: *)
(*Integrands of the form x^m (a x^n)^p when p is symbolic*)


{x^m*(a*x^n)^p, x, 2, (x^(1 + m)*(a*x^n)^p)/(1 + m + n*p)}
{x^m/(a*x^n)^((1 + m)/n), x, 2, (x^(1 + m)*Log[x])/(a*x^n)^((1 + m)/n)}
{(a*x^n)^p/x^(n*p+1), x, 2, ((a*x^n)^p*Log[x])/x^(n*p)}

{x^2*(a*x^n)^p, x, 2, (x^3*(a*x^n)^p)/(3 + n*p)}
{x^1*(a*x^n)^p, x, 2, (x^2*(a*x^n)^p)/(2 + n*p)}
{x^0*(a*x^n)^p, x, 2, (x*(a*x^n)^p)/(1 + n*p)}
{(a*x^n)^p/x^1, x, 2, (a*x^n)^p/(n*p)}
{(a*x^n)^p/x^2, x, 2, -((a*x^n)^p/((1 - n*p)*x))}


{x^m/(a*x^n)^(1/n), x, 2, x^(1 + m)/((a*x^n)^(1/n)*m)}

{x^2/(a*x^n)^(1/n), x, 2, ((1/2)*x^3)/(a*x^n)^(1/n)}
{x^1/(a*x^n)^(1/n), x, 2, x^2/(a*x^n)^(1/n)}
{x^0/(a*x^n)^(1/n), x, 2, (x*Log[x])/(a*x^n)^(1/n)}
{1/(x^1*(a*x^n)^(1/n)), x, 2, -(a*x^n)^(-n^(-1))}
{1/(x^2*(a*x^n)^(1/n)), x, 2, -(1/((a*x^n)^(1/n)*(2*x)))}


(* ::Section::Closed:: *)
(*Integrands of the form x^m (a+b (c x^n)^p)^q*)


(* ::Subsection::Closed:: *)
(*Integrands of the form (a+b (c x^n)^(m/n))^p*)


{(a + b*(c*x^n)^(1/n))^p, x, 2, (x*(a + b*(c*x^n)^(1/n))^(1 + p))/((c*x^n)^n^(-1)*(b*(1 + p)))}

{(a + b*(c*x^n)^(1/n))^3, x, 2, (x*(a + b*(c*x^n)^(1/n))^4)/((c*x^n)^n^(-1)*(4*b))}
{(a + b*(c*x^n)^(1/n))^2, x, 2, (x*(a + b*(c*x^n)^(1/n))^3)/((c*x^n)^n^(-1)*(3*b))}
{(a + b*(c*x^n)^(1/n))^1, x, 3, a*x + (1/2)*b*x*(c*x^n)^(1/n)}
{1/(a + b*(c*x^n)^(1/n))^1, x, 2, (x*Log[a + b*(c*x^n)^(1/n)])/((c*x^n)^n^(-1)*b)}
{1/(a + b*(c*x^n)^(1/n))^2, x, 2, x/(a^2 + a*b*(c*x^n)^(1/n)), -(x/((c*x^n)^n^(-1)*(b*(a + b*(c*x^n)^(1/n)))))}
{1/(a + b*(c*x^n)^(1/n))^3, x, 2, -(x/((c*x^n)^n^(-1)*(2*b*(a + b*(c*x^n)^(1/n))^2)))}


{(a + b*(c*x^n)^(2/n))^3, x, 3, a^3*x + a^2*b*x*(c*x^n)^(2/n) + (3/5)*a*b^2*x*(c*x^n)^(4/n) + (1/7)*b^3*x*(c*x^n)^(6/n)}
{(a + b*(c*x^n)^(2/n))^2, x, 3, a^2*x + (2/3)*a*b*x*(c*x^n)^(2/n) + (1/5)*b^2*x*(c*x^n)^(4/n)}
{(a + b*(c*x^n)^(2/n)), x, 3, a*x + (1/3)*b*x*(c*x^n)^(2/n)}
{1/(a + b*(c*x^n)^(2/n)), x, 2, (x*ArcTan[(Sqrt[b]*(c*x^n)^(1/n))/Sqrt[a]])/((c*x^n)^n^(-1)*(Sqrt[a]*Sqrt[b]))}
{1/(a + b*(c*x^n)^(2/n))^2, x, 3, x/(2*a*(a + b*(c*x^n)^(2/n))) + (x*ArcTan[(Sqrt[b]*(c*x^n)^(1/n))/Sqrt[a]])/((c*x^n)^n^(-1)*(2*a^(3/2)*Sqrt[b]))}
{1/(a + b*(c*x^n)^(2/n))^3, x, 4, x/(4*a*(a + b*(c*x^n)^(2/n))^2) + (3*x)/(8*a^2*(a + b*(c*x^n)^(2/n))) + (3*x*ArcTan[(Sqrt[b]*(c*x^n)^(1/n))/Sqrt[a]])/((c*x^n)^n^(-1)*(8*a^(5/2)*Sqrt[b]))}


{(a + b*(c*x^n)^(3/n))^3, x, 3, a^3*x + (3/4)*a^2*b*x*(c*x^n)^(3/n) + (3/7)*a*b^2*x*(c*x^n)^(6/n) + (1/10)*b^3*x*(c*x^n)^(9/n)}
{(a + b*(c*x^n)^(3/n))^2, x, 3, a^2*x + (1/2)*a*b*x*(c*x^n)^(3/n) + (1/7)*b^2*x*(c*x^n)^(6/n)}
{(a + b*(c*x^n)^(3/n)), x, 3, a*x + (1/4)*b*x*(c*x^n)^(3/n)}
{1/(a + b*(c*x^n)^(3/n)), x, 6, -((x*ArcTan[(a^(1/3) - 2*b^(1/3)*(c*x^n)^(1/n))/(Sqrt[3]*a^(1/3))])/((c*x^n)^(1/n)*(Sqrt[3]*a^(2/3)*b^(1/3)))) + (x*Log[a^(1/3) + b^(1/3)*(c*x^n)^(1/n)])/((c*x^n)^(1/n)*(3*a^(2/3)*b^(1/3))) - (x*Log[a^(2/3) - a^(1/3)*b^(1/3)*(c*x^n)^(1/n) + b^(2/3)*(c*x^n)^(2/n)])/((c*x^n)^(1/n)*(6*a^(2/3)*b^(1/3)))}
{1/(a + b*(c*x^n)^(3/n))^2, x, 7, x/(3*a*(a + b*(c*x^n)^(3/n))) - (2*x*ArcTan[(a^(1/3) - 2*b^(1/3)*(c*x^n)^(1/n))/(Sqrt[3]*a^(1/3))])/((c*x^n)^n^(-1)*(3*Sqrt[3]*a^(5/3)*b^(1/3))) + (2*x*Log[a^(1/3) + b^(1/3)*(c*x^n)^(1/n)])/((c*x^n)^n^(-1)*(9*a^(5/3)*b^(1/3))) - (x*Log[a^(2/3) - a^(1/3)*b^(1/3)*(c*x^n)^(1/n) + b^(2/3)*(c*x^n)^(2/n)])/((c*x^n)^n^(-1)*(9*a^(5/3)*b^(1/3)))}
{1/(a + b*(c*x^n)^(3/n))^3, x, 8, x/(6*a*(a + b*(c*x^n)^(3/n))^2) + (5*x)/(18*a^2*(a + b*(c*x^n)^(3/n))) - (5*x*ArcTan[(a^(1/3) - 2*b^(1/3)*(c*x^n)^(1/n))/(Sqrt[3]*a^(1/3))])/((c*x^n)^n^(-1)*(9*Sqrt[3]*a^(8/3)*b^(1/3))) + (5*x*Log[a^(1/3) + b^(1/3)*(c*x^n)^(1/n)])/((c*x^n)^n^(-1)*(27*a^(8/3)*b^(1/3))) - (5*x*Log[a^(2/3) - a^(1/3)*b^(1/3)*(c*x^n)^(1/n) + b^(2/3)*(c*x^n)^(2/n)])/((c*x^n)^n^(-1)*(54*a^(8/3)*b^(1/3)))}


{1/(1 + (x^3)^(2/3)), x, 2, (x*ArcTan[(x^3)^(1/3)])/(x^3)^(1/3)}
{1/(1 + (x^2)^(3/2)), x, 6, -((x*ArcTan[(1 - 2*Sqrt[x^2])/Sqrt[3]])/(Sqrt[3]*Sqrt[x^2])) - (x*Log[1 + x^2 - Sqrt[x^2]])/(6*Sqrt[x^2]) + (x*Log[1 + Sqrt[x^2]])/(3*Sqrt[x^2])}


(* Integrands of the form 1/(a+b*(x^(2*n))^(1/n) where n is an integer *)
{(1 + 4*Sqrt[x^4])^(-1), x, 2, (x*ArcTan[2*(x^4)^(1/4)])/(2*(x^4)^(1/4))}
{(1 - 4*Sqrt[x^4])^(-1), x, 2, (x*ArcTanh[2*(x^4)^(1/4)])/(2*(x^4)^(1/4))}
{(1 + 4*(x^6)^(1/3))^(-1), x, 2, (x*ArcTan[2*(x^6)^(1/6)])/(2*(x^6)^(1/6))}
{(1 - 4*(x^6)^(1/3))^(-1), x, 2, (x*ArcTanh[2*(x^6)^(1/6)])/(2*(x^6)^(1/6))}
{(1 + 4*(x^(2*n))^n^(-1))^(-1), x, 2, ((1/2)*x*ArcTan[2*(x^(2*n))^(1/(2*n))])/(x^(2*n))^(1/(2*n))}
{(1 - 4*(x^(2*n))^n^(-1))^(-1), x, 2, ((1/2)*x*ArcTanh[2*(x^(2*n))^(1/(2*n))])/(x^(2*n))^(1/(2*n))}


(* ::Subsection::Closed:: *)
(*Integrands of the form x^m (a+b (c x^n)^(m/n))^p*)


{x^3/(a + b*(c*x^n)^(1/n)), x, 3, (a^2*x^4)/((c*x^n)^(3/n)*b^3) - (a*x^4)/((c*x^n)^(2/n)*(2*b^2)) + x^4/((c*x^n)^n^(-1)*(3*b)) - (a^3*x^4*Log[a + b*(c*x^n)^(1/n)])/((c*x^n)^(4/n)*b^4)}
{x^2/(a + b*(c*x^n)^(1/n)), x, 3, -((a*x^3)/((c*x^n)^(2/n)*b^2)) + x^3/((c*x^n)^n^(-1)*(2*b)) + (a^2*x^3*Log[a + b*(c*x^n)^(1/n)])/((c*x^n)^(3/n)*b^3)}
{x^1/(a + b*(c*x^n)^(1/n)), x, 3, x^2/((c*x^n)^n^(-1)*b) - (a*x^2*Log[a + b*(c*x^n)^(1/n)])/((c*x^n)^(2/n)*b^2)}
{x^0/(a + b*(c*x^n)^(1/n)), x, 2, (x*Log[a + b*(c*x^n)^(1/n)])/((c*x^n)^n^(-1)*b)}
{1/(x^1*(a + b*(c*x^n)^(1/n))), x, 3, Log[x]/a - Log[a + b*(c*x^n)^(1/n)]/a, Log[(c*x^n)^(1/n)]/a - Log[a + b*(c*x^n)^(1/n)]/a}
{1/(x^2*(a + b*(c*x^n)^(1/n))), x, 3, -(1/(a*x)) - (b*(c*x^n)^(1/n)*Log[(c*x^n)^(1/n)])/(a^2*x) + (b*(c*x^n)^(1/n)*Log[a + b*(c*x^n)^(1/n)])/(a^2*x)}
{1/(x^3*(a + b*(c*x^n)^(1/n))), x, 3, -(1/(2*a*x^2)) + (b*(c*x^n)^(1/n))/(a^2*x^2) + (b^2*(c*x^n)^(2/n)*Log[(c*x^n)^(1/n)])/(a^3*x^2) - (b^2*(c*x^n)^(2/n)*Log[a + b*(c*x^n)^(1/n)])/(a^3*x^2)}


{x^3/(a + b*(c*x^n)^(1/n))^2, x, 3, -((2*a*x^4)/((c*x^n)^(3/n)*b^3)) + x^4/((c*x^n)^(2/n)*(2*b^2)) + (a^3*x^4)/((c*x^n)^(4/n)*(b^4*(a + b*(c*x^n)^(1/n)))) + (3*a^2*x^4*Log[a + b*(c*x^n)^(1/n)])/((c*x^n)^(4/n)*b^4)}
{x^2/(a + b*(c*x^n)^(1/n))^2, x, 3, x^3/((c*x^n)^(2/n)*b^2) - (a^2*x^3)/((c*x^n)^(3/n)*(b^3*(a + b*(c*x^n)^(1/n)))) - (2*a*x^3*Log[a + b*(c*x^n)^(1/n)])/((c*x^n)^(3/n)*b^3)}
{x^1/(a + b*(c*x^n)^(1/n))^2, x, 3, (a*x^2)/((c*x^n)^(2/n)*(b^2*(a + b*(c*x^n)^(1/n)))) + (x^2*Log[a + b*(c*x^n)^(1/n)])/((c*x^n)^(2/n)*b^2)}
{x^0/(a + b*(c*x^n)^(1/n))^2, x, 2, -(x/((c*x^n)^n^(-1)*(b*(a + b*(c*x^n)^(1/n)))))}
{1/(x^1*(a + b*(c*x^n)^(1/n))^2), x, 3, 1/(a*(a + b*(c*x^n)^(1/n))) + Log[(c*x^n)^(1/n)]/a^2 - Log[a + b*(c*x^n)^(1/n)]/a^2}
{1/(x^2*(a + b*(c*x^n)^(1/n))^2), x, 3, -(1/(a^2*x)) - (b*(c*x^n)^(1/n))/(a^2*x*(a + b*(c*x^n)^(1/n))) - (2*b*(c*x^n)^(1/n)*Log[(c*x^n)^(1/n)])/(a^3*x) + (2*b*(c*x^n)^(1/n)*Log[a + b*(c*x^n)^(1/n)])/(a^3*x)}
{1/(x^3*(a + b*(c*x^n)^(1/n))^2), x, 3, -(1/(2*a^2*x^2)) + (2*b*(c*x^n)^(1/n))/(a^3*x^2) + (b^2*(c*x^n)^(2/n))/(a^3*x^2*(a + b*(c*x^n)^(1/n))) + (3*b^2*(c*x^n)^(2/n)*Log[(c*x^n)^(1/n)])/(a^4*x^2) - (3*b^2*(c*x^n)^(2/n)*Log[a + b*(c*x^n)^(1/n)])/(a^4*x^2)}


{x^3*(a + b*(c*x^n)^(1/n))^p, x, 3, -((a^3*x^4*(a + b*(c*x^n)^(1/n))^(1 + p))/((c*x^n)^(4/n)*(b^4*(1 + p)))) + (3*a^2*x^4*(a + b*(c*x^n)^(1/n))^(2 + p))/((c*x^n)^(4/n)*(b^4*(2 + p))) - (3*a*x^4*(a + b*(c*x^n)^(1/n))^(3 + p))/((c*x^n)^(4/n)*(b^4*(3 + p))) + (x^4*(a + b*(c*x^n)^(1/n))^(4 + p))/((c*x^n)^(4/n)*(b^4*(4 + p)))}
{x^2*(a + b*(c*x^n)^(1/n))^p, x, 3, (a^2*x^3*(a + b*(c*x^n)^(1/n))^(1 + p))/((c*x^n)^(3/n)*(b^3*(1 + p))) - (2*a*x^3*(a + b*(c*x^n)^(1/n))^(2 + p))/((c*x^n)^(3/n)*(b^3*(2 + p))) + (x^3*(a + b*(c*x^n)^(1/n))^(3 + p))/((c*x^n)^(3/n)*(b^3*(3 + p)))}
{x^1*(a + b*(c*x^n)^(1/n))^p, x, 3, -((a*x^2*(a + b*(c*x^n)^(1/n))^(1 + p))/((c*x^n)^(2/n)*(b^2*(1 + p)))) + (x^2*(a + b*(c*x^n)^(1/n))^(2 + p))/((c*x^n)^(2/n)*(b^2*(2 + p)))}
{x^0*(a + b*(c*x^n)^(1/n))^p, x, 2, (x*(a + b*(c*x^n)^(1/n))^(1 + p))/((c*x^n)^n^(-1)*(b*(1 + p)))}
{(a + b*(c*x^n)^(1/n))^p/x^1, x, 2, -(((a + b*(c*x^n)^(1/n))^(1 + p)*Hypergeometric2F1[1, 1 + p, 2 + p, (a + b*(c*x^n)^(1/n))/a])/(a*(1 + p)))}


{x/(1 + (x^n)^(1/n))^2, x, 3, x^2/((x^n)^(2/n)*(1 + (x^n)^(1/n))) + (x^2*Log[1 + (x^n)^(1/n)])/(x^n)^(2/n)}


(* ::Section::Closed:: *)
(*Integrands of the form x^m (a (b x^n)^p)^q*)


{x^m*(a*(b*x^n)^p)^q, x, 2, (x^(1 + m)*(a*(b*x^n)^p)^q)/(1 + m + n*p*q)}

{x^2*(a*(b*x^n)^p)^q, x, 2, (x^3*(a*(b*x^n)^p)^q)/(3 + n*p*q)}
{x^1*(a*(b*x^n)^p)^q, x, 2, (x^2*(a*(b*x^n)^p)^q)/(2 + n*p*q)}
{x^0*(a*(b*x^n)^p)^q, x, 2, (x*(a*(b*x^n)^p)^q)/(1 + n*p*q)}
{(a*(b*x^n)^p)^q/x^1, x, 2, (a*(b*x^n)^p)^q/(n*p*q)}
{(a*(b*x^n)^p)^q/x^2, x, 2, -((a*(b*x^n)^p)^q/((1 - n*p*q)*x))}
{(a*(b*x^n)^p)^q/x^3, x, 2, -((a*(b*x^n)^p)^q/((2 - n*p*q)*x^2))}


{x^2/(a*(b*x^m)^n)^(1/(m*n)), x, 2, ((1/2)*x^3)/(a*(b*x^m)^n)^(1/(m*n))}
{x^1/(a*(b*x^m)^n)^(1/(m*n)), x, 2, x^2/(a*(b*x^m)^n)^(1/(m*n))}
{x^0/(a*(b*x^m)^n)^(1/(m*n)), x, 2, (x*Log[x])/(a*(b*x^m)^n)^(1/(m*n))}
{1/(x^1*(a*(b*x^m)^n)^(1/(m*n))), x, 2, -(a*(b*x^m)^n)^(-(1/(m*n)))}
{1/(x^2*(a*(b*x^m)^n)^(1/(m*n))), x, 2, -(1/((a*(b*x^m)^n)^(1/(m*n))*(2*x)))}


{x^(2-n*p*q)*(a*(b*x^n)^p)^q, x, 2, (1/3)*x^(3 - n*p*q)*(a*(b*x^n)^p)^q}
{x^(1-n*p*q)*(a*(b*x^n)^p)^q, x, 2, (1/2)*x^(2 - n*p*q)*(a*(b*x^n)^p)^q}
{x^(0-n*p*q)*(a*(b*x^n)^p)^q, x, 2, x^(1 - n*p*q)*(a*(b*x^n)^p)^q}
{x^(-1-n*p*q)*(a*(b*x^n)^p)^q, x, 2, ((a*(b*x^n)^p)^q*Log[x])/x^(n*p*q)}
{x^(-2-n*p*q)*(a*(b*x^n)^p)^q, x, 2, (-x^(-1 - n*p*q))*(a*(b*x^n)^p)^q}


(* ::Section::Closed:: *)
(*Integrands of the form x^m (a+b x)^n (c x^2)^p*)


(* ::Subsection::Closed:: *)
(*Integrands of the form x^m (a+b x)^n (c x^2)^(p/2)*)


(* ::Subsubsection::Closed:: *)
(*p>0*)


{x^2*Sqrt[c*x^2]*(a + b*x)^n, x, 3, -((a^3*Sqrt[c*x^2]*(a + b*x)^(1 + n))/(b^4*(1 + n)*x)) + (3*a^2*Sqrt[c*x^2]*(a + b*x)^(2 + n))/(b^4*(2 + n)*x) - (3*a*Sqrt[c*x^2]*(a + b*x)^(3 + n))/(b^4*(3 + n)*x) + (Sqrt[c*x^2]*(a + b*x)^(4 + n))/(b^4*(4 + n)*x)}
{x*Sqrt[c*x^2]*(a + b*x)^n, x, 3, (a^2*Sqrt[c*x^2]*(a + b*x)^(1 + n))/(b^3*(1 + n)*x) - (2*a*Sqrt[c*x^2]*(a + b*x)^(2 + n))/(b^3*(2 + n)*x) + (Sqrt[c*x^2]*(a + b*x)^(3 + n))/(b^3*(3 + n)*x)}
{Sqrt[c*x^2]*(a + b*x)^n, x, 3, -((a*Sqrt[c*x^2]*(a + b*x)^(1 + n))/(b^2*(1 + n)*x)) + (Sqrt[c*x^2]*(a + b*x)^(2 + n))/(b^2*(2 + n)*x)}
{(Sqrt[c*x^2]*(a + b*x)^n)/x, x, 2, (Sqrt[c*x^2]*(a + b*x)^(1 + n))/(b*(1 + n)*x)}
{(Sqrt[c*x^2]*(a + b*x)^n)/x^2, x, 2, -((Sqrt[c*x^2]*(a + b*x)^(1 + n)*Hypergeometric2F1[1, 1 + n, 2 + n, (a + b*x)/a])/(a*(1 + n)*x))}
{(Sqrt[c*x^2]*(a + b*x)^n)/x^3, x, 3, -((Sqrt[c*x^2]*(a + b*x)^(1 + n))/(a*x^2)) - (b*n*Sqrt[c*x^2]*(a + b*x)^(1 + n)*Hypergeometric2F1[1, 1 + n, 2 + n, (a + b*x)/a])/(a^2*(1 + n)*x)}
{(Sqrt[c*x^2]*(a + b*x)^n)/x^4, x, 4, -((Sqrt[c*x^2]*(a + b*x)^(1 + n))/(2*a*x^3)) + (b*(1 - n)*Sqrt[c*x^2]*(a + b*x)^(1 + n))/(2*a^2*x^2) + (b^2*(1 - n)*n*Sqrt[c*x^2]*(a + b*x)^(1 + n)*Hypergeometric2F1[1, 1 + n, 2 + n, (a + b*x)/a])/(2*a^3*(1 + n)*x)}


{x*(c*x^2)^(3/2)*(a + b*x)^n, x, 3, (a^4*c*Sqrt[c*x^2]*(a + b*x)^(1 + n))/(b^5*(1 + n)*x) - (4*a^3*c*Sqrt[c*x^2]*(a + b*x)^(2 + n))/(b^5*(2 + n)*x) + (6*a^2*c*Sqrt[c*x^2]*(a + b*x)^(3 + n))/(b^5*(3 + n)*x) - (4*a*c*Sqrt[c*x^2]*(a + b*x)^(4 + n))/(b^5*(4 + n)*x) + (c*Sqrt[c*x^2]*(a + b*x)^(5 + n))/(b^5*(5 + n)*x)}
{(c*x^2)^(3/2)*(a + b*x)^n, x, 3, -((a^3*c*Sqrt[c*x^2]*(a + b*x)^(1 + n))/(b^4*(1 + n)*x)) + (3*a^2*c*Sqrt[c*x^2]*(a + b*x)^(2 + n))/(b^4*(2 + n)*x) - (3*a*c*Sqrt[c*x^2]*(a + b*x)^(3 + n))/(b^4*(3 + n)*x) + (c*Sqrt[c*x^2]*(a + b*x)^(4 + n))/(b^4*(4 + n)*x)}
{((c*x^2)^(3/2)*(a + b*x)^n)/x, x, 3, (a^2*c*Sqrt[c*x^2]*(a + b*x)^(1 + n))/(b^3*(1 + n)*x) - (2*a*c*Sqrt[c*x^2]*(a + b*x)^(2 + n))/(b^3*(2 + n)*x) + (c*Sqrt[c*x^2]*(a + b*x)^(3 + n))/(b^3*(3 + n)*x)}
{((c*x^2)^(3/2)*(a + b*x)^n)/x^2, x, 3, -((a*c*Sqrt[c*x^2]*(a + b*x)^(1 + n))/(b^2*(1 + n)*x)) + (c*Sqrt[c*x^2]*(a + b*x)^(2 + n))/(b^2*(2 + n)*x)}
{((c*x^2)^(3/2)*(a + b*x)^n)/x^3, x, 2, (c*Sqrt[c*x^2]*(a + b*x)^(1 + n))/(b*(1 + n)*x)}
{((c*x^2)^(3/2)*(a + b*x)^n)/x^4, x, 2, -((c*Sqrt[c*x^2]*(a + b*x)^(1 + n)*Hypergeometric2F1[1, 1 + n, 2 + n, (a + b*x)/a])/(a*(1 + n)*x))}
{((c*x^2)^(3/2)*(a + b*x)^n)/x^5, x, 3, -((c*Sqrt[c*x^2]*(a + b*x)^(1 + n))/(a*x^2)) - (b*c*n*Sqrt[c*x^2]*(a + b*x)^(1 + n)*Hypergeometric2F1[1, 1 + n, 2 + n, (a + b*x)/a])/(a^2*(1 + n)*x)}
{((c*x^2)^(3/2)*(a + b*x)^n)/x^6, x, 4, -((c*Sqrt[c*x^2]*(a + b*x)^(1 + n))/(2*a*x^3)) + (b*c*(1 - n)*Sqrt[c*x^2]*(a + b*x)^(1 + n))/(2*a^2*x^2) + (b^2*c*(1 - n)*n*Sqrt[c*x^2]*(a + b*x)^(1 + n)*Hypergeometric2F1[1, 1 + n, 2 + n, (a + b*x)/a])/(2*a^3*(1 + n)*x)}


{(c*x^2)^(5/2)*(a + b*x)^n, x, 3, -((a^5*c^2*Sqrt[c*x^2]*(a + b*x)^(1 + n))/(b^6*(1 + n)*x)) + (5*a^4*c^2*Sqrt[c*x^2]*(a + b*x)^(2 + n))/(b^6*(2 + n)*x) - (10*a^3*c^2*Sqrt[c*x^2]*(a + b*x)^(3 + n))/(b^6*(3 + n)*x) + (10*a^2*c^2*Sqrt[c*x^2]*(a + b*x)^(4 + n))/(b^6*(4 + n)*x) - (5*a*c^2*Sqrt[c*x^2]*(a + b*x)^(5 + n))/(b^6*(5 + n)*x) + (c^2*Sqrt[c*x^2]*(a + b*x)^(6 + n))/(b^6*(6 + n)*x)}
{((c*x^2)^(5/2)*(a + b*x)^n)/x, x, 3, (a^4*c^2*Sqrt[c*x^2]*(a + b*x)^(1 + n))/(b^5*(1 + n)*x) - (4*a^3*c^2*Sqrt[c*x^2]*(a + b*x)^(2 + n))/(b^5*(2 + n)*x) + (6*a^2*c^2*Sqrt[c*x^2]*(a + b*x)^(3 + n))/(b^5*(3 + n)*x) - (4*a*c^2*Sqrt[c*x^2]*(a + b*x)^(4 + n))/(b^5*(4 + n)*x) + (c^2*Sqrt[c*x^2]*(a + b*x)^(5 + n))/(b^5*(5 + n)*x)}
{((c*x^2)^(5/2)*(a + b*x)^n)/x^2, x, 3, -((a^3*c^2*Sqrt[c*x^2]*(a + b*x)^(1 + n))/(b^4*(1 + n)*x)) + (3*a^2*c^2*Sqrt[c*x^2]*(a + b*x)^(2 + n))/(b^4*(2 + n)*x) - (3*a*c^2*Sqrt[c*x^2]*(a + b*x)^(3 + n))/(b^4*(3 + n)*x) + (c^2*Sqrt[c*x^2]*(a + b*x)^(4 + n))/(b^4*(4 + n)*x)}
{((c*x^2)^(5/2)*(a + b*x)^n)/x^3, x, 3, (a^2*c^2*Sqrt[c*x^2]*(a + b*x)^(1 + n))/(b^3*(1 + n)*x) - (2*a*c^2*Sqrt[c*x^2]*(a + b*x)^(2 + n))/(b^3*(2 + n)*x) + (c^2*Sqrt[c*x^2]*(a + b*x)^(3 + n))/(b^3*(3 + n)*x)}
{((c*x^2)^(5/2)*(a + b*x)^n)/x^4, x, 3, -((a*c^2*Sqrt[c*x^2]*(a + b*x)^(1 + n))/(b^2*(1 + n)*x)) + (c^2*Sqrt[c*x^2]*(a + b*x)^(2 + n))/(b^2*(2 + n)*x)}
{((c*x^2)^(5/2)*(a + b*x)^n)/x^5, x, 2, (c^2*Sqrt[c*x^2]*(a + b*x)^(1 + n))/(b*(1 + n)*x)}
{((c*x^2)^(5/2)*(a + b*x)^n)/x^6, x, 2, -((c^2*Sqrt[c*x^2]*(a + b*x)^(1 + n)*Hypergeometric2F1[1, 1 + n, 2 + n, (a + b*x)/a])/(a*(1 + n)*x))}
{((c*x^2)^(5/2)*(a + b*x)^n)/x^7, x, 3, -((c^2*Sqrt[c*x^2]*(a + b*x)^(1 + n))/(a*x^2)) - (b*c^2*n*Sqrt[c*x^2]*(a + b*x)^(1 + n)*Hypergeometric2F1[1, 1 + n, 2 + n, (a + b*x)/a])/(a^2*(1 + n)*x)}


(* ::Subsubsection::Closed:: *)
(*p<0*)


{(x^4*(a + b*x)^n)/Sqrt[c*x^2], x, 3, -((a^3*x*(a + b*x)^(1 + n))/(b^4*(1 + n)*Sqrt[c*x^2])) + (3*a^2*x*(a + b*x)^(2 + n))/(b^4*(2 + n)*Sqrt[c*x^2]) - (3*a*x*(a + b*x)^(3 + n))/(b^4*(3 + n)*Sqrt[c*x^2]) + (x*(a + b*x)^(4 + n))/(b^4*(4 + n)*Sqrt[c*x^2])}
{(x^3*(a + b*x)^n)/Sqrt[c*x^2], x, 3, (a^2*x*(a + b*x)^(1 + n))/(b^3*(1 + n)*Sqrt[c*x^2]) - (2*a*x*(a + b*x)^(2 + n))/(b^3*(2 + n)*Sqrt[c*x^2]) + (x*(a + b*x)^(3 + n))/(b^3*(3 + n)*Sqrt[c*x^2])}
{(x^2*(a + b*x)^n)/Sqrt[c*x^2], x, 3, -((a*x*(a + b*x)^(1 + n))/(b^2*(1 + n)*Sqrt[c*x^2])) + (x*(a + b*x)^(2 + n))/(b^2*(2 + n)*Sqrt[c*x^2])}
{(x*(a + b*x)^n)/Sqrt[c*x^2], x, 2, (x*(a + b*x)^(1 + n))/(b*(1 + n)*Sqrt[c*x^2])}
{(a + b*x)^n/Sqrt[c*x^2], x, 2, -((x*(a + b*x)^(1 + n)*Hypergeometric2F1[1, 1 + n, 2 + n, (a + b*x)/a])/(a*(1 + n)*Sqrt[c*x^2]))}
{(a + b*x)^n/(x*Sqrt[c*x^2]), x, 3, -((a + b*x)^(1 + n)/(a*Sqrt[c*x^2])) - (b*n*x*(a + b*x)^(1 + n)*Hypergeometric2F1[1, 1 + n, 2 + n, (a + b*x)/a])/(a^2*(1 + n)*Sqrt[c*x^2])}
{(a + b*x)^n/(x^2*Sqrt[c*x^2]), x, 4, (b*(1 - n)*(a + b*x)^(1 + n))/(2*a^2*Sqrt[c*x^2]) - (a + b*x)^(1 + n)/(2*a*x*Sqrt[c*x^2]) + (b^2*(1 - n)*n*x*(a + b*x)^(1 + n)*Hypergeometric2F1[1, 1 + n, 2 + n, (a + b*x)/a])/(2*a^3*(1 + n)*Sqrt[c*x^2])}
{(a + b*x)^n/(x^3*Sqrt[c*x^2]), x, 5, -((b^2*(1 - n)*(2 - n)*(a + b*x)^(1 + n))/(6*a^3*Sqrt[c*x^2])) - (a + b*x)^(1 + n)/(3*a*x^2*Sqrt[c*x^2]) + (b*(2 - n)*(a + b*x)^(1 + n))/(6*a^2*x*Sqrt[c*x^2]) - (b^3*(1 - n)*(2 - n)*n*x*(a + b*x)^(1 + n)*Hypergeometric2F1[1, 1 + n, 2 + n, (a + b*x)/a])/(6*a^4*(1 + n)*Sqrt[c*x^2])}


{(x^6*(a + b*x)^n)/(c*x^2)^(3/2), x, 3, -((a^3*x*(a + b*x)^(1 + n))/(b^4*c*(1 + n)*Sqrt[c*x^2])) + (3*a^2*x*(a + b*x)^(2 + n))/(b^4*c*(2 + n)*Sqrt[c*x^2]) - (3*a*x*(a + b*x)^(3 + n))/(b^4*c*(3 + n)*Sqrt[c*x^2]) + (x*(a + b*x)^(4 + n))/(b^4*c*(4 + n)*Sqrt[c*x^2])}
{(x^5*(a + b*x)^n)/(c*x^2)^(3/2), x, 3, (a^2*x*(a + b*x)^(1 + n))/(b^3*c*(1 + n)*Sqrt[c*x^2]) - (2*a*x*(a + b*x)^(2 + n))/(b^3*c*(2 + n)*Sqrt[c*x^2]) + (x*(a + b*x)^(3 + n))/(b^3*c*(3 + n)*Sqrt[c*x^2])}
{(x^4*(a + b*x)^n)/(c*x^2)^(3/2), x, 3, -((a*x*(a + b*x)^(1 + n))/(b^2*c*(1 + n)*Sqrt[c*x^2])) + (x*(a + b*x)^(2 + n))/(b^2*c*(2 + n)*Sqrt[c*x^2])}
{(x^3*(a + b*x)^n)/(c*x^2)^(3/2), x, 2, (x*(a + b*x)^(1 + n))/(b*c*(1 + n)*Sqrt[c*x^2])}
{(x^2*(a + b*x)^n)/(c*x^2)^(3/2), x, 2, -((x*(a + b*x)^(1 + n)*Hypergeometric2F1[1, 1 + n, 2 + n, (a + b*x)/a])/(a*c*(1 + n)*Sqrt[c*x^2]))}
{(x*(a + b*x)^n)/(c*x^2)^(3/2), x, 3, -((a + b*x)^(1 + n)/(a*c*Sqrt[c*x^2])) - (b*n*x*(a + b*x)^(1 + n)*Hypergeometric2F1[1, 1 + n, 2 + n, (a + b*x)/a])/(a^2*c*(1 + n)*Sqrt[c*x^2])}
{(a + b*x)^n/(c*x^2)^(3/2), x, 4, (b*(1 - n)*(a + b*x)^(1 + n))/(2*a^2*c*Sqrt[c*x^2]) - (a + b*x)^(1 + n)/(2*a*c*x*Sqrt[c*x^2]) + (b^2*(1 - n)*n*x*(a + b*x)^(1 + n)*Hypergeometric2F1[1, 1 + n, 2 + n, (a + b*x)/a])/(2*a^3*c*(1 + n)*Sqrt[c*x^2])}
{(a + b*x)^n/(x*(c*x^2)^(3/2)), x, 5, -((b^2*(1 - n)*(2 - n)*(a + b*x)^(1 + n))/(6*a^3*c*Sqrt[c*x^2])) - (a + b*x)^(1 + n)/(3*a*c*x^2*Sqrt[c*x^2]) + (b*(2 - n)*(a + b*x)^(1 + n))/(6*a^2*c*x*Sqrt[c*x^2]) - (b^3*(1 - n)*(2 - n)*n*x*(a + b*x)^(1 + n)*Hypergeometric2F1[1, 1 + n, 2 + n, (a + b*x)/a])/(6*a^4*c*(1 + n)*Sqrt[c*x^2])}


{(x^8*(a + b*x)^n)/(c*x^2)^(5/2), x, 3, -((a^3*x*(a + b*x)^(1 + n))/(b^4*c^2*(1 + n)*Sqrt[c*x^2])) + (3*a^2*x*(a + b*x)^(2 + n))/(b^4*c^2*(2 + n)*Sqrt[c*x^2]) - (3*a*x*(a + b*x)^(3 + n))/(b^4*c^2*(3 + n)*Sqrt[c*x^2]) + (x*(a + b*x)^(4 + n))/(b^4*c^2*(4 + n)*Sqrt[c*x^2])}
{(x^7*(a + b*x)^n)/(c*x^2)^(5/2), x, 3, (a^2*x*(a + b*x)^(1 + n))/(b^3*c^2*(1 + n)*Sqrt[c*x^2]) - (2*a*x*(a + b*x)^(2 + n))/(b^3*c^2*(2 + n)*Sqrt[c*x^2]) + (x*(a + b*x)^(3 + n))/(b^3*c^2*(3 + n)*Sqrt[c*x^2])}
{(x^6*(a + b*x)^n)/(c*x^2)^(5/2), x, 3, -((a*x*(a + b*x)^(1 + n))/(b^2*c^2*(1 + n)*Sqrt[c*x^2])) + (x*(a + b*x)^(2 + n))/(b^2*c^2*(2 + n)*Sqrt[c*x^2])}
{(x^5*(a + b*x)^n)/(c*x^2)^(5/2), x, 2, (x*(a + b*x)^(1 + n))/(b*c^2*(1 + n)*Sqrt[c*x^2])}
{(x^4*(a + b*x)^n)/(c*x^2)^(5/2), x, 2, -((x*(a + b*x)^(1 + n)*Hypergeometric2F1[1, 1 + n, 2 + n, (a + b*x)/a])/(a*c^2*(1 + n)*Sqrt[c*x^2]))}
{(x^3*(a + b*x)^n)/(c*x^2)^(5/2), x, 3, -((a + b*x)^(1 + n)/(a*c^2*Sqrt[c*x^2])) - (b*n*x*(a + b*x)^(1 + n)*Hypergeometric2F1[1, 1 + n, 2 + n, (a + b*x)/a])/(a^2*c^2*(1 + n)*Sqrt[c*x^2])}
{(x^2*(a + b*x)^n)/(c*x^2)^(5/2), x, 4, (b*(1 - n)*(a + b*x)^(1 + n))/(2*a^2*c^2*Sqrt[c*x^2]) - (a + b*x)^(1 + n)/(2*a*c^2*x*Sqrt[c*x^2]) + (b^2*(1 - n)*n*x*(a + b*x)^(1 + n)*Hypergeometric2F1[1, 1 + n, 2 + n, (a + b*x)/a])/(2*a^3*c^2*(1 + n)*Sqrt[c*x^2])}
{(x^1*(a + b*x)^n)/(c*x^2)^(5/2), x, 5, -((b^2*(1 - n)*(2 - n)*(a + b*x)^(1 + n))/(6*a^3*c^2*Sqrt[c*x^2])) - (a + b*x)^(1 + n)/(3*a*c^2*x^2*Sqrt[c*x^2]) + (b*(2 - n)*(a + b*x)^(1 + n))/(6*a^2*c^2*x*Sqrt[c*x^2]) - (b^3*(1 - n)*(2 - n)*n*x*(a + b*x)^(1 + n)*Hypergeometric2F1[1, 1 + n, 2 + n, (a + b*x)/a])/(6*a^4*c^2*(1 + n)*Sqrt[c*x^2])}


(* ::Subsection::Closed:: *)
(*Integrands of the form x^m (a+b x)^1 (c x^2)^(p/2)*)


(* ::Subsubsection::Closed:: *)
(*p>0*)


{x^m*Sqrt[c*x^2]*(a + b*x), x, 3, (a*x^(1 + m)*Sqrt[c*x^2])/(2 + m) + (b*x^(2 + m)*Sqrt[c*x^2])/(3 + m)}

{x^3*Sqrt[c*x^2]*(a + b*x), x, 3, (a*x^4*Sqrt[c*x^2])/5 + (b*x^5*Sqrt[c*x^2])/6}
{x^2*Sqrt[c*x^2]*(a + b*x), x, 3, (a*x^3*Sqrt[c*x^2])/4 + (b*x^4*Sqrt[c*x^2])/5}
{x*Sqrt[c*x^2]*(a + b*x), x, 3, (a*x^2*Sqrt[c*x^2])/3 + (b*x^3*Sqrt[c*x^2])/4}
{Sqrt[c*x^2]*(a + b*x), x, 3, (a*x*Sqrt[c*x^2])/2 + (b*x^2*Sqrt[c*x^2])/3}
{(Sqrt[c*x^2]*(a + b*x))/x, x, 2, a*Sqrt[c*x^2] + (b*x*Sqrt[c*x^2])/2}
{(Sqrt[c*x^2]*(a + b*x))/x^2, x, 3, b*Sqrt[c*x^2] + (a*Sqrt[c*x^2]*Log[x])/x}
{(Sqrt[c*x^2]*(a + b*x))/x^3, x, 3, -((a*Sqrt[c*x^2])/x^2) + (b*Sqrt[c*x^2]*Log[x])/x}
{(Sqrt[c*x^2]*(a + b*x))/x^4, x, 3, -(a*Sqrt[c*x^2])/(2*x^3) - (b*Sqrt[c*x^2])/x^2}


{x^m*(c*x^2)^(3/2)*(a + b*x), x, 3, (a*c*x^(3 + m)*Sqrt[c*x^2])/(4 + m) + (b*c*x^(4 + m)*Sqrt[c*x^2])/(5 + m)}

{x^3*(c*x^2)^(3/2)*(a + b*x), x, 3, (a*c*x^6*Sqrt[c*x^2])/7 + (b*c*x^7*Sqrt[c*x^2])/8}
{x^2*(c*x^2)^(3/2)*(a + b*x), x, 3, (a*c*x^5*Sqrt[c*x^2])/6 + (b*c*x^6*Sqrt[c*x^2])/7}
{x*(c*x^2)^(3/2)*(a + b*x), x, 3, (a*c*x^4*Sqrt[c*x^2])/5 + (b*c*x^5*Sqrt[c*x^2])/6}
{(c*x^2)^(3/2)*(a + b*x), x, 3, (a*c*x^3*Sqrt[c*x^2])/4 + (b*c*x^4*Sqrt[c*x^2])/5}
{((c*x^2)^(3/2)*(a + b*x))/x, x, 3, (a*c*x^2*Sqrt[c*x^2])/3 + (b*c*x^3*Sqrt[c*x^2])/4}
{((c*x^2)^(3/2)*(a + b*x))/x^2, x, 3, (a*c*x*Sqrt[c*x^2])/2 + (b*c*x^2*Sqrt[c*x^2])/3}
{((c*x^2)^(3/2)*(a + b*x))/x^3, x, 2, a*c*Sqrt[c*x^2] + (b*c*x*Sqrt[c*x^2])/2}
{((c*x^2)^(3/2)*(a + b*x))/x^4, x, 3, b*c*Sqrt[c*x^2] + (a*c*Sqrt[c*x^2]*Log[x])/x}


{x^m*(c*x^2)^(5/2)*(a + b*x), x, 3, (a*c^2*x^(5 + m)*Sqrt[c*x^2])/(6 + m) + (b*c^2*x^(6 + m)*Sqrt[c*x^2])/(7 + m)}

{x^3*(c*x^2)^(5/2)*(a + b*x), x, 3, (a*c^2*x^8*Sqrt[c*x^2])/9 + (b*c^2*x^9*Sqrt[c*x^2])/10}
{x^2*(c*x^2)^(5/2)*(a + b*x), x, 3, (a*c^2*x^7*Sqrt[c*x^2])/8 + (b*c^2*x^8*Sqrt[c*x^2])/9}
{x*(c*x^2)^(5/2)*(a + b*x), x, 3, (a*c^2*x^6*Sqrt[c*x^2])/7 + (b*c^2*x^7*Sqrt[c*x^2])/8}
{(c*x^2)^(5/2)*(a + b*x), x, 3, (a*c^2*x^5*Sqrt[c*x^2])/6 + (b*c^2*x^6*Sqrt[c*x^2])/7}
{((c*x^2)^(5/2)*(a + b*x))/x, x, 3, (a*c^2*x^4*Sqrt[c*x^2])/5 + (b*c^2*x^5*Sqrt[c*x^2])/6}
{((c*x^2)^(5/2)*(a + b*x))/x^2, x, 3, (a*c^2*x^3*Sqrt[c*x^2])/4 + (b*c^2*x^4*Sqrt[c*x^2])/5}
{((c*x^2)^(5/2)*(a + b*x))/x^3, x, 3, (a*c^2*x^2*Sqrt[c*x^2])/3 + (b*c^2*x^3*Sqrt[c*x^2])/4}
{((c*x^2)^(5/2)*(a + b*x))/x^4, x, 3, (a*c^2*x*Sqrt[c*x^2])/2 + (b*c^2*x^2*Sqrt[c*x^2])/3}


(* ::Subsubsection::Closed:: *)
(*p<0*)


{(x^m*(a + b*x))/Sqrt[c*x^2], x, 3, (a*x^(1 + m))/(m*Sqrt[c*x^2]) + (b*x^(2 + m))/((1 + m)*Sqrt[c*x^2])}

{(x^3*(a + b*x))/Sqrt[c*x^2], x, 3, (a*x^4)/(3*Sqrt[c*x^2]) + (b*x^5)/(4*Sqrt[c*x^2])}
{(x^2*(a + b*x))/Sqrt[c*x^2], x, 3, (a*x^3)/(2*Sqrt[c*x^2]) + (b*x^4)/(3*Sqrt[c*x^2])}
{(x*(a + b*x))/Sqrt[c*x^2], x, 2, (a*x^2)/Sqrt[c*x^2] + (b*x^3)/(2*Sqrt[c*x^2])}
{(a + b*x)/Sqrt[c*x^2], x, 3, (b*x^2)/Sqrt[c*x^2] + (a*x*Log[x])/Sqrt[c*x^2]}
{(a + b*x)/(x*Sqrt[c*x^2]), x, 3, -(a/Sqrt[c*x^2]) + (b*x*Log[x])/Sqrt[c*x^2]}
{(a + b*x)/(x^2*Sqrt[c*x^2]), x, 3, -(b/Sqrt[c*x^2]) - a/(2*x*Sqrt[c*x^2])}
{(a + b*x)/(x^3*Sqrt[c*x^2]), x, 3, -a/(3*x^2*Sqrt[c*x^2]) - b/(2*x*Sqrt[c*x^2])}
{(a + b*x)/(x^4*Sqrt[c*x^2]), x, 3, -a/(4*x^3*Sqrt[c*x^2]) - b/(3*x^2*Sqrt[c*x^2])}


{(x^m*(a + b*x))/(c*x^2)^(3/2), x, 3, -((a*x^(-1 + m))/(c*(2 - m)*Sqrt[c*x^2])) - (b*x^m)/(c*(1 - m)*Sqrt[c*x^2])}

{(x^3*(a + b*x))/(c*x^2)^(3/2), x, 2, (a*x^2)/(c*Sqrt[c*x^2]) + (b*x^3)/(2*c*Sqrt[c*x^2])}
{(x^2*(a + b*x))/(c*x^2)^(3/2), x, 3, (b*x^2)/(c*Sqrt[c*x^2]) + (a*x*Log[x])/(c*Sqrt[c*x^2])}
{(x*(a + b*x))/(c*x^2)^(3/2), x, 3, -(a/(c*Sqrt[c*x^2])) + (b*x*Log[x])/(c*Sqrt[c*x^2])}
{(a + b*x)/(c*x^2)^(3/2), x, 3, -(b/(c*Sqrt[c*x^2])) - a/(2*c*x*Sqrt[c*x^2])}
{(a + b*x)/(x*(c*x^2)^(3/2)), x, 3, -a/(3*c*x^2*Sqrt[c*x^2]) - b/(2*c*x*Sqrt[c*x^2])}
{(a + b*x)/(x^2*(c*x^2)^(3/2)), x, 3, -a/(4*c*x^3*Sqrt[c*x^2]) - b/(3*c*x^2*Sqrt[c*x^2])}
{(a + b*x)/(x^3*(c*x^2)^(3/2)), x, 3, -a/(5*c*x^4*Sqrt[c*x^2]) - b/(4*c*x^3*Sqrt[c*x^2])}
{(a + b*x)/(x^4*(c*x^2)^(3/2)), x, 3, -a/(6*c*x^5*Sqrt[c*x^2]) - b/(5*c*x^4*Sqrt[c*x^2])}


{(x^m*(a + b*x))/(c*x^2)^(5/2), x, 3, -((a*x^(-3 + m))/(c^2*(4 - m)*Sqrt[c*x^2])) - (b*x^(-2 + m))/(c^2*(3 - m)*Sqrt[c*x^2])}

{(x^3*(a + b*x))/(c*x^2)^(5/2), x, 3, -(a/(c^2*Sqrt[c*x^2])) + (b*x*Log[x])/(c^2*Sqrt[c*x^2])}
{(x^2*(a + b*x))/(c*x^2)^(5/2), x, 3, -(b/(c^2*Sqrt[c*x^2])) - a/(2*c^2*x*Sqrt[c*x^2])}
{(x*(a + b*x))/(c*x^2)^(5/2), x, 3, -a/(3*c^2*x^2*Sqrt[c*x^2]) - b/(2*c^2*x*Sqrt[c*x^2])}
{(a + b*x)/(c*x^2)^(5/2), x, 3, -a/(4*c^2*x^3*Sqrt[c*x^2]) - b/(3*c^2*x^2*Sqrt[c*x^2])}
{(a + b*x)/(x*(c*x^2)^(5/2)), x, 3, -a/(5*c^2*x^4*Sqrt[c*x^2]) - b/(4*c^2*x^3*Sqrt[c*x^2])}
{(a + b*x)/(x^2*(c*x^2)^(5/2)), x, 3, -a/(6*c^2*x^5*Sqrt[c*x^2]) - b/(5*c^2*x^4*Sqrt[c*x^2])}
{(a + b*x)/(x^3*(c*x^2)^(5/2)), x, 3, -a/(7*c^2*x^6*Sqrt[c*x^2]) - b/(6*c^2*x^5*Sqrt[c*x^2])}
{(a + b*x)/(x^4*(c*x^2)^(5/2)), x, 3, -a/(8*c^2*x^7*Sqrt[c*x^2]) - b/(7*c^2*x^6*Sqrt[c*x^2])}


(* ::Subsection::Closed:: *)
(*Integrands of the form x^m (a+b x)^2 (c x^2)^(p/2)*)


(* ::Subsubsection::Closed:: *)
(*p>0*)


{x^m*Sqrt[c*x^2]*(a + b*x)^2, x, 3, (a^2*x^(1 + m)*Sqrt[c*x^2])/(2 + m) + (2*a*b*x^(2 + m)*Sqrt[c*x^2])/(3 + m) + (b^2*x^(3 + m)*Sqrt[c*x^2])/(4 + m)}

{x^3*Sqrt[c*x^2]*(a + b*x)^2, x, 3, (a^2*x^4*Sqrt[c*x^2])/5 + (a*b*x^5*Sqrt[c*x^2])/3 + (b^2*x^6*Sqrt[c*x^2])/7}
{x^2*Sqrt[c*x^2]*(a + b*x)^2, x, 3, (a^2*x^3*Sqrt[c*x^2])/4 + (2*a*b*x^4*Sqrt[c*x^2])/5 + (b^2*x^5*Sqrt[c*x^2])/6}
{x*Sqrt[c*x^2]*(a + b*x)^2, x, 3, (a^2*x^2*Sqrt[c*x^2])/3 + (a*b*x^3*Sqrt[c*x^2])/2 + (b^2*x^4*Sqrt[c*x^2])/5}
{Sqrt[c*x^2]*(a + b*x)^2, x, 3, (a^2*x*Sqrt[c*x^2])/2 + (2*a*b*x^2*Sqrt[c*x^2])/3 + (b^2*x^3*Sqrt[c*x^2])/4}
{(Sqrt[c*x^2]*(a + b*x)^2)/x, x, 2, (Sqrt[c*x^2]*(a + b*x)^3)/(3*b*x)}
{(Sqrt[c*x^2]*(a + b*x)^2)/x^2, x, 3, 2*a*b*Sqrt[c*x^2] + (b^2*x*Sqrt[c*x^2])/2 + (a^2*Sqrt[c*x^2]*Log[x])/x}
{(Sqrt[c*x^2]*(a + b*x)^2)/x^3, x, 3, b^2*Sqrt[c*x^2] - (a^2*Sqrt[c*x^2])/x^2 + (2*a*b*Sqrt[c*x^2]*Log[x])/x}
{(Sqrt[c*x^2]*(a + b*x)^2)/x^4, x, 3, -(a^2*Sqrt[c*x^2])/(2*x^3) - (2*a*b*Sqrt[c*x^2])/x^2 + (b^2*Sqrt[c*x^2]*Log[x])/x}


{x^m*(c*x^2)^(3/2)*(a + b*x)^2, x, 3, (a^2*c*x^(3 + m)*Sqrt[c*x^2])/(4 + m) + (2*a*b*c*x^(4 + m)*Sqrt[c*x^2])/(5 + m) + (b^2*c*x^(5 + m)*Sqrt[c*x^2])/(6 + m)}

{x^3*(c*x^2)^(3/2)*(a + b*x)^2, x, 3, (a^2*c*x^6*Sqrt[c*x^2])/7 + (a*b*c*x^7*Sqrt[c*x^2])/4 + (b^2*c*x^8*Sqrt[c*x^2])/9}
{x^2*(c*x^2)^(3/2)*(a + b*x)^2, x, 3, (a^2*c*x^5*Sqrt[c*x^2])/6 + (2*a*b*c*x^6*Sqrt[c*x^2])/7 + (b^2*c*x^7*Sqrt[c*x^2])/8}
{x*(c*x^2)^(3/2)*(a + b*x)^2, x, 3, (a^2*c*x^4*Sqrt[c*x^2])/5 + (a*b*c*x^5*Sqrt[c*x^2])/3 + (b^2*c*x^6*Sqrt[c*x^2])/7}
{(c*x^2)^(3/2)*(a + b*x)^2, x, 3, (a^2*c*x^3*Sqrt[c*x^2])/4 + (2*a*b*c*x^4*Sqrt[c*x^2])/5 + (b^2*c*x^5*Sqrt[c*x^2])/6}
{((c*x^2)^(3/2)*(a + b*x)^2)/x, x, 3, (a^2*c*x^2*Sqrt[c*x^2])/3 + (a*b*c*x^3*Sqrt[c*x^2])/2 + (b^2*c*x^4*Sqrt[c*x^2])/5}
{((c*x^2)^(3/2)*(a + b*x)^2)/x^2, x, 3, (a^2*c*x*Sqrt[c*x^2])/2 + (2*a*b*c*x^2*Sqrt[c*x^2])/3 + (b^2*c*x^3*Sqrt[c*x^2])/4}
{((c*x^2)^(3/2)*(a + b*x)^2)/x^3, x, 2, (c*Sqrt[c*x^2]*(a + b*x)^3)/(3*b*x)}
{((c*x^2)^(3/2)*(a + b*x)^2)/x^4, x, 3, 2*a*b*c*Sqrt[c*x^2] + (b^2*c*x*Sqrt[c*x^2])/2 + (a^2*c*Sqrt[c*x^2]*Log[x])/x}


{x^m*(c*x^2)^(5/2)*(a + b*x)^2, x, 3, (a^2*c^2*x^(5 + m)*Sqrt[c*x^2])/(6 + m) + (2*a*b*c^2*x^(6 + m)*Sqrt[c*x^2])/(7 + m) + (b^2*c^2*x^(7 + m)*Sqrt[c*x^2])/(8 + m)}

{x^3*(c*x^2)^(5/2)*(a + b*x)^2, x, 3, (a^2*c^2*x^8*Sqrt[c*x^2])/9 + (a*b*c^2*x^9*Sqrt[c*x^2])/5 + (b^2*c^2*x^10*Sqrt[c*x^2])/11}
{x^2*(c*x^2)^(5/2)*(a + b*x)^2, x, 3, (a^2*c^2*x^7*Sqrt[c*x^2])/8 + (2*a*b*c^2*x^8*Sqrt[c*x^2])/9 + (b^2*c^2*x^9*Sqrt[c*x^2])/10}
{x*(c*x^2)^(5/2)*(a + b*x)^2, x, 3, (a^2*c^2*x^6*Sqrt[c*x^2])/7 + (a*b*c^2*x^7*Sqrt[c*x^2])/4 + (b^2*c^2*x^8*Sqrt[c*x^2])/9}
{(c*x^2)^(5/2)*(a + b*x)^2, x, 3, (a^2*c^2*x^5*Sqrt[c*x^2])/6 + (2*a*b*c^2*x^6*Sqrt[c*x^2])/7 + (b^2*c^2*x^7*Sqrt[c*x^2])/8}
{((c*x^2)^(5/2)*(a + b*x)^2)/x, x, 3, (a^2*c^2*x^4*Sqrt[c*x^2])/5 + (a*b*c^2*x^5*Sqrt[c*x^2])/3 + (b^2*c^2*x^6*Sqrt[c*x^2])/7}
{((c*x^2)^(5/2)*(a + b*x)^2)/x^2, x, 3, (a^2*c^2*x^3*Sqrt[c*x^2])/4 + (2*a*b*c^2*x^4*Sqrt[c*x^2])/5 + (b^2*c^2*x^5*Sqrt[c*x^2])/6}
{((c*x^2)^(5/2)*(a + b*x)^2)/x^3, x, 3, (a^2*c^2*x^2*Sqrt[c*x^2])/3 + (a*b*c^2*x^3*Sqrt[c*x^2])/2 + (b^2*c^2*x^4*Sqrt[c*x^2])/5}
{((c*x^2)^(5/2)*(a + b*x)^2)/x^4, x, 3, (a^2*c^2*x*Sqrt[c*x^2])/2 + (2*a*b*c^2*x^2*Sqrt[c*x^2])/3 + (b^2*c^2*x^3*Sqrt[c*x^2])/4}


(* ::Subsubsection::Closed:: *)
(*p<0*)


{(x^m*(a + b*x)^2)/Sqrt[c*x^2], x, 3, (a^2*x^(1 + m))/(m*Sqrt[c*x^2]) + (2*a*b*x^(2 + m))/((1 + m)*Sqrt[c*x^2]) + (b^2*x^(3 + m))/((2 + m)*Sqrt[c*x^2])}

{(x^3*(a + b*x)^2)/Sqrt[c*x^2], x, 3, (a^2*x^4)/(3*Sqrt[c*x^2]) + (a*b*x^5)/(2*Sqrt[c*x^2]) + (b^2*x^6)/(5*Sqrt[c*x^2])}
{(x^2*(a + b*x)^2)/Sqrt[c*x^2], x, 3, (a^2*x^3)/(2*Sqrt[c*x^2]) + (2*a*b*x^4)/(3*Sqrt[c*x^2]) + (b^2*x^5)/(4*Sqrt[c*x^2])}
{(x*(a + b*x)^2)/Sqrt[c*x^2], x, 2, (x*(a + b*x)^3)/(3*b*Sqrt[c*x^2])}
{(a + b*x)^2/Sqrt[c*x^2], x, 3, (2*a*b*x^2)/Sqrt[c*x^2] + (b^2*x^3)/(2*Sqrt[c*x^2]) + (a^2*x*Log[x])/Sqrt[c*x^2]}
{(a + b*x)^2/(x*Sqrt[c*x^2]), x, 3, -(a^2/Sqrt[c*x^2]) + (b^2*x^2)/Sqrt[c*x^2] + (2*a*b*x*Log[x])/Sqrt[c*x^2]}
{(a + b*x)^2/(x^2*Sqrt[c*x^2]), x, 3, (-2*a*b)/Sqrt[c*x^2] - a^2/(2*x*Sqrt[c*x^2]) + (b^2*x*Log[x])/Sqrt[c*x^2]}
{(a + b*x)^2/(x^3*Sqrt[c*x^2]), x, 2, -(a + b*x)^3/(3*a*x^2*Sqrt[c*x^2])}
{(a + b*x)^2/(x^4*Sqrt[c*x^2]), x, 3, -a^2/(4*x^3*Sqrt[c*x^2]) - (2*a*b)/(3*x^2*Sqrt[c*x^2]) - b^2/(2*x*Sqrt[c*x^2])}


{(x^m*(a + b*x)^2)/(c*x^2)^(3/2), x, 3, -((a^2*x^(-1 + m))/(c*(2 - m)*Sqrt[c*x^2])) - (2*a*b*x^m)/(c*(1 - m)*Sqrt[c*x^2]) + (b^2*x^(1 + m))/(c*m*Sqrt[c*x^2])}

{(x^3*(a + b*x)^2)/(c*x^2)^(3/2), x, 2, (x*(a + b*x)^3)/(3*b*c*Sqrt[c*x^2])}
{(x^2*(a + b*x)^2)/(c*x^2)^(3/2), x, 3, (2*a*b*x^2)/(c*Sqrt[c*x^2]) + (b^2*x^3)/(2*c*Sqrt[c*x^2]) + (a^2*x*Log[x])/(c*Sqrt[c*x^2])}
{(x*(a + b*x)^2)/(c*x^2)^(3/2), x, 3, -(a^2/(c*Sqrt[c*x^2])) + (b^2*x^2)/(c*Sqrt[c*x^2]) + (2*a*b*x*Log[x])/(c*Sqrt[c*x^2])}
{(a + b*x)^2/(c*x^2)^(3/2), x, 3, (-2*a*b)/(c*Sqrt[c*x^2]) - a^2/(2*c*x*Sqrt[c*x^2]) + (b^2*x*Log[x])/(c*Sqrt[c*x^2])}
{(a + b*x)^2/(x*(c*x^2)^(3/2)), x, 2, -(a + b*x)^3/(3*a*c*x^2*Sqrt[c*x^2])}
{(a + b*x)^2/(x^2*(c*x^2)^(3/2)), x, 3, -a^2/(4*c*x^3*Sqrt[c*x^2]) - (2*a*b)/(3*c*x^2*Sqrt[c*x^2]) - b^2/(2*c*x*Sqrt[c*x^2])}
{(a + b*x)^2/(x^3*(c*x^2)^(3/2)), x, 3, -a^2/(5*c*x^4*Sqrt[c*x^2]) - (a*b)/(2*c*x^3*Sqrt[c*x^2]) - b^2/(3*c*x^2*Sqrt[c*x^2])}
{(a + b*x)^2/(x^4*(c*x^2)^(3/2)), x, 3, -a^2/(6*c*x^5*Sqrt[c*x^2]) - (2*a*b)/(5*c*x^4*Sqrt[c*x^2]) - b^2/(4*c*x^3*Sqrt[c*x^2])}


{(x^m*(a + b*x)^2)/(c*x^2)^(5/2), x, 3, -((a^2*x^(-3 + m))/(c^2*(4 - m)*Sqrt[c*x^2])) - (2*a*b*x^(-2 + m))/(c^2*(3 - m)*Sqrt[c*x^2]) - (b^2*x^(-1 + m))/(c^2*(2 - m)*Sqrt[c*x^2])}

{(x^3*(a + b*x)^2)/(c*x^2)^(5/2), x, 3, -(a^2/(c^2*Sqrt[c*x^2])) + (b^2*x^2)/(c^2*Sqrt[c*x^2]) + (2*a*b*x*Log[x])/(c^2*Sqrt[c*x^2])}
{(x^2*(a + b*x)^2)/(c*x^2)^(5/2), x, 3, (-2*a*b)/(c^2*Sqrt[c*x^2]) - a^2/(2*c^2*x*Sqrt[c*x^2]) + (b^2*x*Log[x])/(c^2*Sqrt[c*x^2])}
{(x*(a + b*x)^2)/(c*x^2)^(5/2), x, 2, -(a + b*x)^3/(3*a*c^2*x^2*Sqrt[c*x^2])}
{(a + b*x)^2/(c*x^2)^(5/2), x, 3, -a^2/(4*c^2*x^3*Sqrt[c*x^2]) - (2*a*b)/(3*c^2*x^2*Sqrt[c*x^2]) - b^2/(2*c^2*x*Sqrt[c*x^2])}
{(a + b*x)^2/(x*(c*x^2)^(5/2)), x, 3, -a^2/(5*c^2*x^4*Sqrt[c*x^2]) - (a*b)/(2*c^2*x^3*Sqrt[c*x^2]) - b^2/(3*c^2*x^2*Sqrt[c*x^2])}
{(a + b*x)^2/(x^2*(c*x^2)^(5/2)), x, 3, -a^2/(6*c^2*x^5*Sqrt[c*x^2]) - (2*a*b)/(5*c^2*x^4*Sqrt[c*x^2]) - b^2/(4*c^2*x^3*Sqrt[c*x^2])}
{(a + b*x)^2/(x^3*(c*x^2)^(5/2)), x, 3, -a^2/(7*c^2*x^6*Sqrt[c*x^2]) - (a*b)/(3*c^2*x^5*Sqrt[c*x^2]) - b^2/(5*c^2*x^4*Sqrt[c*x^2])}
{(a + b*x)^2/(x^4*(c*x^2)^(5/2)), x, 3, -a^2/(8*c^2*x^7*Sqrt[c*x^2]) - (2*a*b)/(7*c^2*x^6*Sqrt[c*x^2]) - b^2/(6*c^2*x^5*Sqrt[c*x^2])}


(* ::Subsection::Closed:: *)
(*Integrands of the form x^m / (a+b x)^1 (c x^2)^(p/2)*)


(* ::Subsubsection::Closed:: *)
(*p>0*)


{(x^3*Sqrt[c*x^2])/(a + b*x), x, 3, -((a^3*Sqrt[c*x^2])/b^4) + (a^2*x*Sqrt[c*x^2])/(2*b^3) - (a*x^2*Sqrt[c*x^2])/(3*b^2) + (x^3*Sqrt[c*x^2])/(4*b) + (a^4*Sqrt[c*x^2]*Log[a + b*x])/(b^5*x)}
{(x^2*Sqrt[c*x^2])/(a + b*x), x, 3, (a^2*Sqrt[c*x^2])/b^3 - (a*x*Sqrt[c*x^2])/(2*b^2) + (x^2*Sqrt[c*x^2])/(3*b) - (a^3*Sqrt[c*x^2]*Log[a + b*x])/(b^4*x)}
{(x*Sqrt[c*x^2])/(a + b*x), x, 3, -((a*Sqrt[c*x^2])/b^2) + (x*Sqrt[c*x^2])/(2*b) + (a^2*Sqrt[c*x^2]*Log[a + b*x])/(b^3*x)}
{Sqrt[c*x^2]/(a + b*x), x, 3, Sqrt[c*x^2]/b - (a*Sqrt[c*x^2]*Log[a + b*x])/(b^2*x)}
{Sqrt[c*x^2]/(x*(a + b*x)), x, 2, (Sqrt[c*x^2]*Log[a + b*x])/(b*x)}
{Sqrt[c*x^2]/(x^2*(a + b*x)), x, 3, (Sqrt[c*x^2]*Log[x])/(a*x) - (Sqrt[c*x^2]*Log[a + b*x])/(a*x)}
{Sqrt[c*x^2]/(x^3*(a + b*x)), x, 3, -(Sqrt[c*x^2]/(a*x^2)) - (b*Sqrt[c*x^2]*Log[x])/(a^2*x) + (b*Sqrt[c*x^2]*Log[a + b*x])/(a^2*x)}
{Sqrt[c*x^2]/(x^4*(a + b*x)), x, 3, -Sqrt[c*x^2]/(2*a*x^3) + (b*Sqrt[c*x^2])/(a^2*x^2) + (b^2*Sqrt[c*x^2]*Log[x])/(a^3*x) - (b^2*Sqrt[c*x^2]*Log[a + b*x])/(a^3*x)}


{(x*(c*x^2)^(3/2))/(a + b*x), x, 3, -((a^3*c*Sqrt[c*x^2])/b^4) + (a^2*c*x*Sqrt[c*x^2])/(2*b^3) - (a*c*x^2*Sqrt[c*x^2])/(3*b^2) + (c*x^3*Sqrt[c*x^2])/(4*b) + (a^4*c*Sqrt[c*x^2]*Log[a + b*x])/(b^5*x)}
{(c*x^2)^(3/2)/(a + b*x), x, 3, (a^2*c*Sqrt[c*x^2])/b^3 - (a*c*x*Sqrt[c*x^2])/(2*b^2) + (c*x^2*Sqrt[c*x^2])/(3*b) - (a^3*c*Sqrt[c*x^2]*Log[a + b*x])/(b^4*x)}
{(c*x^2)^(3/2)/(x*(a + b*x)), x, 3, -((a*c*Sqrt[c*x^2])/b^2) + (c*x*Sqrt[c*x^2])/(2*b) + (a^2*c*Sqrt[c*x^2]*Log[a + b*x])/(b^3*x)}
{(c*x^2)^(3/2)/(x^2*(a + b*x)), x, 3, (c*Sqrt[c*x^2])/b - (a*c*Sqrt[c*x^2]*Log[a + b*x])/(b^2*x)}
{(c*x^2)^(3/2)/(x^3*(a + b*x)), x, 2, (c*Sqrt[c*x^2]*Log[a + b*x])/(b*x)}
{(c*x^2)^(3/2)/(x^4*(a + b*x)), x, 3, (c*Sqrt[c*x^2]*Log[x])/(a*x) - (c*Sqrt[c*x^2]*Log[a + b*x])/(a*x)}
{(c*x^2)^(3/2)/(x^5*(a + b*x)), x, 3, -((c*Sqrt[c*x^2])/(a*x^2)) - (b*c*Sqrt[c*x^2]*Log[x])/(a^2*x) + (b*c*Sqrt[c*x^2]*Log[a + b*x])/(a^2*x)}
{(c*x^2)^(3/2)/(x^6*(a + b*x)), x, 3, -(c*Sqrt[c*x^2])/(2*a*x^3) + (b*c*Sqrt[c*x^2])/(a^2*x^2) + (b^2*c*Sqrt[c*x^2]*Log[x])/(a^3*x) - (b^2*c*Sqrt[c*x^2]*Log[a + b*x])/(a^3*x)}
{(c*x^2)^(3/2)/(x^7*(a + b*x)), x, 3, -(c*Sqrt[c*x^2])/(3*a*x^4) + (b*c*Sqrt[c*x^2])/(2*a^2*x^3) - (b^2*c*Sqrt[c*x^2])/(a^3*x^2) - (b^3*c*Sqrt[c*x^2]*Log[x])/(a^4*x) + (b^3*c*Sqrt[c*x^2]*Log[a + b*x])/(a^4*x)}


{(c*x^2)^(5/2)/(a + b*x), x, 3, (a^4*c^2*Sqrt[c*x^2])/b^5 - (a^3*c^2*x*Sqrt[c*x^2])/(2*b^4) + (a^2*c^2*x^2*Sqrt[c*x^2])/(3*b^3) - (a*c^2*x^3*Sqrt[c*x^2])/(4*b^2) + (c^2*x^4*Sqrt[c*x^2])/(5*b) - (a^5*c^2*Sqrt[c*x^2]*Log[a + b*x])/(b^6*x)}
{(c*x^2)^(5/2)/(x*(a + b*x)), x, 3, -((a^3*c^2*Sqrt[c*x^2])/b^4) + (a^2*c^2*x*Sqrt[c*x^2])/(2*b^3) - (a*c^2*x^2*Sqrt[c*x^2])/(3*b^2) + (c^2*x^3*Sqrt[c*x^2])/(4*b) + (a^4*c^2*Sqrt[c*x^2]*Log[a + b*x])/(b^5*x)}
{(c*x^2)^(5/2)/(x^2*(a + b*x)), x, 3, (a^2*c^2*Sqrt[c*x^2])/b^3 - (a*c^2*x*Sqrt[c*x^2])/(2*b^2) + (c^2*x^2*Sqrt[c*x^2])/(3*b) - (a^3*c^2*Sqrt[c*x^2]*Log[a + b*x])/(b^4*x)}
{(c*x^2)^(5/2)/(x^3*(a + b*x)), x, 3, -((a*c^2*Sqrt[c*x^2])/b^2) + (c^2*x*Sqrt[c*x^2])/(2*b) + (a^2*c^2*Sqrt[c*x^2]*Log[a + b*x])/(b^3*x)}
{(c*x^2)^(5/2)/(x^4*(a + b*x)), x, 3, (c^2*Sqrt[c*x^2])/b - (a*c^2*Sqrt[c*x^2]*Log[a + b*x])/(b^2*x)}
{(c*x^2)^(5/2)/(x^5*(a + b*x)), x, 2, (c^2*Sqrt[c*x^2]*Log[a + b*x])/(b*x)}
{(c*x^2)^(5/2)/(x^6*(a + b*x)), x, 3, (c^2*Sqrt[c*x^2]*Log[x])/(a*x) - (c^2*Sqrt[c*x^2]*Log[a + b*x])/(a*x)}
{(c*x^2)^(5/2)/(x^7*(a + b*x)), x, 3, -((c^2*Sqrt[c*x^2])/(a*x^2)) - (b*c^2*Sqrt[c*x^2]*Log[x])/(a^2*x) + (b*c^2*Sqrt[c*x^2]*Log[a + b*x])/(a^2*x)}


(* ::Subsubsection::Closed:: *)
(*p<0*)


{x^4/(Sqrt[c*x^2]*(a + b*x)), x, 3, (a^2*x^2)/(b^3*Sqrt[c*x^2]) - (a*x^3)/(2*b^2*Sqrt[c*x^2]) + x^4/(3*b*Sqrt[c*x^2]) - (a^3*x*Log[a + b*x])/(b^4*Sqrt[c*x^2])}
{x^3/(Sqrt[c*x^2]*(a + b*x)), x, 3, -((a*x^2)/(b^2*Sqrt[c*x^2])) + x^3/(2*b*Sqrt[c*x^2]) + (a^2*x*Log[a + b*x])/(b^3*Sqrt[c*x^2])}
{x^2/(Sqrt[c*x^2]*(a + b*x)), x, 3, x^2/(b*Sqrt[c*x^2]) - (a*x*Log[a + b*x])/(b^2*Sqrt[c*x^2])}
{x/(Sqrt[c*x^2]*(a + b*x)), x, 2, (x*Log[a + b*x])/(b*Sqrt[c*x^2])}
{1/(Sqrt[c*x^2]*(a + b*x)), x, 3, (x*Log[x])/(a*Sqrt[c*x^2]) - (x*Log[a + b*x])/(a*Sqrt[c*x^2])}
{1/(x*Sqrt[c*x^2]*(a + b*x)), x, 3, -(1/(a*Sqrt[c*x^2])) - (b*x*Log[x])/(a^2*Sqrt[c*x^2]) + (b*x*Log[a + b*x])/(a^2*Sqrt[c*x^2])}
{1/(x^2*Sqrt[c*x^2]*(a + b*x)), x, 3, b/(a^2*Sqrt[c*x^2]) - 1/(2*a*x*Sqrt[c*x^2]) + (b^2*x*Log[x])/(a^3*Sqrt[c*x^2]) - (b^2*x*Log[a + b*x])/(a^3*Sqrt[c*x^2])}
{1/(x^3*Sqrt[c*x^2]*(a + b*x)), x, 3, -(b^2/(a^3*Sqrt[c*x^2])) - 1/(3*a*x^2*Sqrt[c*x^2]) + b/(2*a^2*x*Sqrt[c*x^2]) - (b^3*x*Log[x])/(a^4*Sqrt[c*x^2]) + (b^3*x*Log[a + b*x])/(a^4*Sqrt[c*x^2])}


{x^6/((c*x^2)^(3/2)*(a + b*x)), x, 3, (a^2*x^2)/(b^3*c*Sqrt[c*x^2]) - (a*x^3)/(2*b^2*c*Sqrt[c*x^2]) + x^4/(3*b*c*Sqrt[c*x^2]) - (a^3*x*Log[a + b*x])/(b^4*c*Sqrt[c*x^2])}
{x^5/((c*x^2)^(3/2)*(a + b*x)), x, 3, -((a*x^2)/(b^2*c*Sqrt[c*x^2])) + x^3/(2*b*c*Sqrt[c*x^2]) + (a^2*x*Log[a + b*x])/(b^3*c*Sqrt[c*x^2])}
{x^4/((c*x^2)^(3/2)*(a + b*x)), x, 3, x^2/(b*c*Sqrt[c*x^2]) - (a*x*Log[a + b*x])/(b^2*c*Sqrt[c*x^2])}
{x^3/((c*x^2)^(3/2)*(a + b*x)), x, 2, (x*Log[a + b*x])/(b*c*Sqrt[c*x^2])}
{x^2/((c*x^2)^(3/2)*(a + b*x)), x, 3, (x*Log[x])/(a*c*Sqrt[c*x^2]) - (x*Log[a + b*x])/(a*c*Sqrt[c*x^2])}
{x/((c*x^2)^(3/2)*(a + b*x)), x, 3, -(1/(a*c*Sqrt[c*x^2])) - (b*x*Log[x])/(a^2*c*Sqrt[c*x^2]) + (b*x*Log[a + b*x])/(a^2*c*Sqrt[c*x^2])}
{1/((c*x^2)^(3/2)*(a + b*x)), x, 3, b/(a^2*c*Sqrt[c*x^2]) - 1/(2*a*c*x*Sqrt[c*x^2]) + (b^2*x*Log[x])/(a^3*c*Sqrt[c*x^2]) - (b^2*x*Log[a + b*x])/(a^3*c*Sqrt[c*x^2])}
{1/(x*(c*x^2)^(3/2)*(a + b*x)), x, 3, -(b^2/(a^3*c*Sqrt[c*x^2])) - 1/(3*a*c*x^2*Sqrt[c*x^2]) + b/(2*a^2*c*x*Sqrt[c*x^2]) - (b^3*x*Log[x])/(a^4*c*Sqrt[c*x^2]) + (b^3*x*Log[a + b*x])/(a^4*c*Sqrt[c*x^2])}


(* ::Subsection::Closed:: *)
(*Integrands of the form x^m / (a+b x)^2 (c x^2)^(p/2)*)


(* ::Subsubsection::Closed:: *)
(*p>0*)


{(x^3*Sqrt[c*x^2])/(a + b*x)^2, x, 3, (3*a^2*Sqrt[c*x^2])/b^4 - (a*x*Sqrt[c*x^2])/b^3 + (x^2*Sqrt[c*x^2])/(3*b^2) - (a^4*Sqrt[c*x^2])/(b^5*x*(a + b*x)) - (4*a^3*Sqrt[c*x^2]*Log[a + b*x])/(b^5*x)}
{(x^2*Sqrt[c*x^2])/(a + b*x)^2, x, 3, (-2*a*Sqrt[c*x^2])/b^3 + (x*Sqrt[c*x^2])/(2*b^2) + (a^3*Sqrt[c*x^2])/(b^4*x*(a + b*x)) + (3*a^2*Sqrt[c*x^2]*Log[a + b*x])/(b^4*x)}
{(x*Sqrt[c*x^2])/(a + b*x)^2, x, 3, Sqrt[c*x^2]/b^2 - (a^2*Sqrt[c*x^2])/(b^3*x*(a + b*x)) - (2*a*Sqrt[c*x^2]*Log[a + b*x])/(b^3*x)}
{Sqrt[c*x^2]/(a + b*x)^2, x, 3, (a*Sqrt[c*x^2])/(b^2*x*(a + b*x)) + (Sqrt[c*x^2]*Log[a + b*x])/(b^2*x)}
{Sqrt[c*x^2]/(x*(a + b*x)^2), x, 2, -(Sqrt[c*x^2]/(b*x*(a + b*x)))}
{Sqrt[c*x^2]/(x^2*(a + b*x)^2), x, 3, Sqrt[c*x^2]/(a*x*(a + b*x)) + (Sqrt[c*x^2]*Log[x])/(a^2*x) - (Sqrt[c*x^2]*Log[a + b*x])/(a^2*x)}
{Sqrt[c*x^2]/(x^3*(a + b*x)^2), x, 3, -(Sqrt[c*x^2]/(a^2*x^2)) - (b*Sqrt[c*x^2])/(a^2*x*(a + b*x)) - (2*b*Sqrt[c*x^2]*Log[x])/(a^3*x) + (2*b*Sqrt[c*x^2]*Log[a + b*x])/(a^3*x)}
{Sqrt[c*x^2]/(x^4*(a + b*x)^2), x, 3, -Sqrt[c*x^2]/(2*a^2*x^3) + (2*b*Sqrt[c*x^2])/(a^3*x^2) + (b^2*Sqrt[c*x^2])/(a^3*x*(a + b*x)) + (3*b^2*Sqrt[c*x^2]*Log[x])/(a^4*x) - (3*b^2*Sqrt[c*x^2]*Log[a + b*x])/(a^4*x)}


{(x*(c*x^2)^(3/2))/(a + b*x)^2, x, 3, (3*a^2*c*Sqrt[c*x^2])/b^4 - (a*c*x*Sqrt[c*x^2])/b^3 + (c*x^2*Sqrt[c*x^2])/(3*b^2) - (a^4*c*Sqrt[c*x^2])/(b^5*x*(a + b*x)) - (4*a^3*c*Sqrt[c*x^2]*Log[a + b*x])/(b^5*x)}
{(c*x^2)^(3/2)/(a + b*x)^2, x, 3, (-2*a*c*Sqrt[c*x^2])/b^3 + (c*x*Sqrt[c*x^2])/(2*b^2) + (a^3*c*Sqrt[c*x^2])/(b^4*x*(a + b*x)) + (3*a^2*c*Sqrt[c*x^2]*Log[a + b*x])/(b^4*x)}
{(c*x^2)^(3/2)/(x*(a + b*x)^2), x, 3, (c*Sqrt[c*x^2])/b^2 - (a^2*c*Sqrt[c*x^2])/(b^3*x*(a + b*x)) - (2*a*c*Sqrt[c*x^2]*Log[a + b*x])/(b^3*x)}
{(c*x^2)^(3/2)/(x^2*(a + b*x)^2), x, 3, (a*c*Sqrt[c*x^2])/(b^2*x*(a + b*x)) + (c*Sqrt[c*x^2]*Log[a + b*x])/(b^2*x)}
{(c*x^2)^(3/2)/(x^3*(a + b*x)^2), x, 2, -((c*Sqrt[c*x^2])/(b*x*(a + b*x)))}
{(c*x^2)^(3/2)/(x^4*(a + b*x)^2), x, 3, (c*Sqrt[c*x^2])/(a*x*(a + b*x)) + (c*Sqrt[c*x^2]*Log[x])/(a^2*x) - (c*Sqrt[c*x^2]*Log[a + b*x])/(a^2*x)}
{(c*x^2)^(3/2)/(x^5*(a + b*x)^2), x, 3, -((c*Sqrt[c*x^2])/(a^2*x^2)) - (b*c*Sqrt[c*x^2])/(a^2*x*(a + b*x)) - (2*b*c*Sqrt[c*x^2]*Log[x])/(a^3*x) + (2*b*c*Sqrt[c*x^2]*Log[a + b*x])/(a^3*x)}
{(c*x^2)^(3/2)/(x^6*(a + b*x)^2), x, 3, -(c*Sqrt[c*x^2])/(2*a^2*x^3) + (2*b*c*Sqrt[c*x^2])/(a^3*x^2) + (b^2*c*Sqrt[c*x^2])/(a^3*x*(a + b*x)) + (3*b^2*c*Sqrt[c*x^2]*Log[x])/(a^4*x) - (3*b^2*c*Sqrt[c*x^2]*Log[a + b*x])/(a^4*x)}


(* ::Subsubsection::Closed:: *)
(*p<0*)


{x^5/(Sqrt[c*x^2]*(a + b*x)^2), x, 3, (3*a^2*x^2)/(b^4*Sqrt[c*x^2]) - (a*x^3)/(b^3*Sqrt[c*x^2]) + x^4/(3*b^2*Sqrt[c*x^2]) - (a^4*x)/(b^5*Sqrt[c*x^2]*(a + b*x)) - (4*a^3*x*Log[a + b*x])/(b^5*Sqrt[c*x^2])}
{x^4/(Sqrt[c*x^2]*(a + b*x)^2), x, 3, (-2*a*x^2)/(b^3*Sqrt[c*x^2]) + x^3/(2*b^2*Sqrt[c*x^2]) + (a^3*x)/(b^4*Sqrt[c*x^2]*(a + b*x)) + (3*a^2*x*Log[a + b*x])/(b^4*Sqrt[c*x^2])}
{x^3/(Sqrt[c*x^2]*(a + b*x)^2), x, 3, x^2/(b^2*Sqrt[c*x^2]) - (a^2*x)/(b^3*Sqrt[c*x^2]*(a + b*x)) - (2*a*x*Log[a + b*x])/(b^3*Sqrt[c*x^2])}
{x^2/(Sqrt[c*x^2]*(a + b*x)^2), x, 3, (a*x)/(b^2*Sqrt[c*x^2]*(a + b*x)) + (x*Log[a + b*x])/(b^2*Sqrt[c*x^2])}
{x/(Sqrt[c*x^2]*(a + b*x)^2), x, 2, -(x/(b*Sqrt[c*x^2]*(a + b*x)))}
{1/(Sqrt[c*x^2]*(a + b*x)^2), x, 3, x/(a*Sqrt[c*x^2]*(a + b*x)) + (x*Log[x])/(a^2*Sqrt[c*x^2]) - (x*Log[a + b*x])/(a^2*Sqrt[c*x^2])}
{1/(x*Sqrt[c*x^2]*(a + b*x)^2), x, 3, -(1/(a^2*Sqrt[c*x^2])) - (b*x)/(a^2*Sqrt[c*x^2]*(a + b*x)) - (2*b*x*Log[x])/(a^3*Sqrt[c*x^2]) + (2*b*x*Log[a + b*x])/(a^3*Sqrt[c*x^2])}
{1/(x^2*Sqrt[c*x^2]*(a + b*x)^2), x, 3, (2*b)/(a^3*Sqrt[c*x^2]) - 1/(2*a^2*x*Sqrt[c*x^2]) + (b^2*x)/(a^3*Sqrt[c*x^2]*(a + b*x)) + (3*b^2*x*Log[x])/(a^4*Sqrt[c*x^2]) - (3*b^2*x*Log[a + b*x])/(a^4*Sqrt[c*x^2])}


{x^5/((c*x^2)^(3/2)*(a + b*x)^2), x, 3, x^2/(b^2*c*Sqrt[c*x^2]) - (a^2*x)/(b^3*c*Sqrt[c*x^2]*(a + b*x)) - (2*a*x*Log[a + b*x])/(b^3*c*Sqrt[c*x^2])}
{x^4/((c*x^2)^(3/2)*(a + b*x)^2), x, 3, (a*x)/(b^2*c*Sqrt[c*x^2]*(a + b*x)) + (x*Log[a + b*x])/(b^2*c*Sqrt[c*x^2])}
{x^3/((c*x^2)^(3/2)*(a + b*x)^2), x, 2, -(x/(b*c*Sqrt[c*x^2]*(a + b*x)))}
{x^2/((c*x^2)^(3/2)*(a + b*x)^2), x, 3, x/(a*c*Sqrt[c*x^2]*(a + b*x)) + (x*Log[x])/(a^2*c*Sqrt[c*x^2]) - (x*Log[a + b*x])/(a^2*c*Sqrt[c*x^2])}
{x/((c*x^2)^(3/2)*(a + b*x)^2), x, 3, -(1/(a^2*c*Sqrt[c*x^2])) - (b*x)/(a^2*c*Sqrt[c*x^2]*(a + b*x)) - (2*b*x*Log[x])/(a^3*c*Sqrt[c*x^2]) + (2*b*x*Log[a + b*x])/(a^3*c*Sqrt[c*x^2])}
{1/((c*x^2)^(3/2)*(a + b*x)^2), x, 3, (2*b)/(a^3*c*Sqrt[c*x^2]) - 1/(2*a^2*c*x*Sqrt[c*x^2]) + (b^2*x)/(a^3*c*Sqrt[c*x^2]*(a + b*x)) + (3*b^2*x*Log[x])/(a^4*c*Sqrt[c*x^2]) - (3*b^2*x*Log[a + b*x])/(a^4*c*Sqrt[c*x^2])}


(* ::Subsection::Closed:: *)
(*Integrands of the form x^m (a+b x)^(2 p+m+2) (c x^2)^p*)


{x^m*(c*x^2)^p/(a + b*x)^(2*p + m + 2), x, 2, (x^(1 + m)*(c*x^2)^p*(a + b*x)^(-1 - m - 2*p))/(a*(1 + m + 2*p))}

{x^3*(c*x^2)^p/(a + b*x)^(2*p + 5), x, 2, (x^4*(c*x^2)^p)/((a + b*x)^(2*(2 + p))*(2*a*(2 + p)))}
{x^2*(c*x^2)^p/(a + b*x)^(2*p + 4), x, 2, (x^3*(c*x^2)^p*(a + b*x)^(-3 - 2*p))/(a*(3 + 2*p))}
{x^1*(c*x^2)^p/(a + b*x)^(2*p + 3), x, 2, (x^2*(c*x^2)^p)/((a + b*x)^(2*(1 + p))*(2*a*(1 + p)))}
{x^0*(c*x^2)^p/(a + b*x)^(2*p + 2), x, 2, (x*(c*x^2)^p*(a + b*x)^(-1 - 2*p))/(a*(1 + 2*p))}
{(c*x^2)^p/(a + b*x)^(2*p + 1)/x^1, x, 2, (c*x^2)^p/((a + b*x)^(2*p)*(2*a*p))}
{(c*x^2)^p/(a + b*x)^(2*p + 0)/x^2, x, 2, -(((c*x^2)^p*(a + b*x)^(1 - 2*p))/(a*(1 - 2*p)*x))}
{(c*x^2)^p/(a + b*x)^(2*p - 1)/x^3, x, 2, -(((c*x^2)^p*(a + b*x)^(2 - 2*p))/(2*a*(1 - p)*x^2))}
{(c*x^2)^p/(a + b*x)^(2*p - 2)/x^4, x, 2, -(((c*x^2)^p*(a + b*x)^(3 - 2*p))/(a*(3 - 2*p)*x^3))}


(* ::Section::Closed:: *)
(*Integrands of the form u (a x^n)^p*)


(* ::Subsection::Closed:: *)
(*Integrands of the form u (a x^n)^p*)


(* Integrands of the form Sqrt[a*x^n]/Sqrt[1+x^5] where n mod 10 = 3 *)
{Sqrt[a*x^23]/Sqrt[1 + x^5], x, 5, -((3*Sqrt[a*x^23]*Sqrt[1 + x^5])/(20*x^9)) + (Sqrt[a*x^23]*Sqrt[1 + x^5])/(10*x^4) + (3*Sqrt[a*x^23]*ArcSinh[x^(5/2)])/(20*x^(23/2))}
{Sqrt[a*x^13]/Sqrt[1 + x^5], x, 4, (Sqrt[a*x^13]*Sqrt[1 + x^5])/(5*x^4) - (Sqrt[a*x^13]*ArcSinh[x^(5/2)])/(5*x^(13/2))}
{Sqrt[a*x^3]/Sqrt[1 + x^5], x, 3, (2*Sqrt[a*x^3]*ArcSinh[x^(5/2)])/(5*x^(3/2))}
{Sqrt[a/x^7]/Sqrt[1 + x^5], x, 2, (-(2/5))*Sqrt[a/x^7]*x*Sqrt[1 + x^5]}
{Sqrt[a/x^17]/Sqrt[1 + x^5], x, 3, (-(2/15))*Sqrt[a/x^17]*x*Sqrt[1 + x^5] + (4/15)*Sqrt[a/x^17]*x^6*Sqrt[1 + x^5]}


{Sqrt[a*x^6]/(x*(1 - x^4)), x, 4, -((Sqrt[a*x^6]*ArcTan[x])/(2*x^3)) + (Sqrt[a*x^6]*ArcTanh[x])/(2*x^3)}
{Sqrt[a*x^6]/(x - x^5), x, 5, -((Sqrt[a*x^6]*ArcTan[x])/(2*x^3)) + (Sqrt[a*x^6]*ArcTanh[x])/(2*x^3)}
{(a*x^6)^(3/2)/(x*(1 - x^4)), x, 6, -((a*Sqrt[a*x^6])/x^2) - (1/5)*a*x^2*Sqrt[a*x^6] + (a*Sqrt[a*x^6]*ArcTan[x])/(2*x^3) + (a*Sqrt[a*x^6]*ArcTanh[x])/(2*x^3)}

{1/(1 - x^4) - Sqrt[a*x^6]/(x*(1 - x^4)), x, 8, ArcTan[x]/2 + (Sqrt[a*x^6]*ArcTan[x])/(2*x^3) + ArcTanh[x]/2 - (Sqrt[a*x^6]*ArcTanh[x])/(2*x^3)}
{1/(1 - x^4) - Sqrt[a*x^6]/(x - x^5), x, 9, ArcTan[x]/2 + (Sqrt[a*x^6]*ArcTan[x])/(2*x^3) + ArcTanh[x]/2 - (Sqrt[a*x^6]*ArcTanh[x])/(2*x^3)}

{Sqrt[a*x^3]/(x - x^3), x, 6, -((Sqrt[a*x^3]*ArcTan[Sqrt[x]])/x^(3/2)) + (Sqrt[a*x^3]*ArcTanh[Sqrt[x]])/x^(3/2)}


{Sqrt[a*x^4]/Sqrt[1 + x^2], x, 3, (Sqrt[a*x^4]*Sqrt[1 + x^2])/(2*x) - (Sqrt[a*x^4]*ArcSinh[x])/(2*x^2)}
{Sqrt[a*x^3]/Sqrt[1 + x^2], x, 4, (2*Sqrt[a*x^3]*Sqrt[1 + x^2])/(3*x) + (2*(-1)^(3/4)*Sqrt[a*x^3]*EllipticF[ArcSin[(-1)^(1/4)*Sqrt[x]], -1])/(3*x^(3/2))}
{Sqrt[a*x^2]/Sqrt[1 + x^2], x, 2, (Sqrt[a*x^2]*Sqrt[1 + x^2])/x}
{Sqrt[a*x^1]/Sqrt[1 + x^2], x, 3, -((2*(-1)^(1/4)*Sqrt[a*x]*EllipticE[ArcSin[(-1)^(1/4)*Sqrt[x]], -1])/Sqrt[x]) + (2*(-1)^(1/4)*Sqrt[a*x]*EllipticF[ArcSin[(-1)^(1/4)*Sqrt[x]], -1])/Sqrt[x]}
{Sqrt[a/x^1]/Sqrt[1 + x^2], x, 3, -2*(-1)^(3/4)*Sqrt[a/x]*Sqrt[x]*EllipticF[ArcSin[(-1)^(1/4)*Sqrt[x]], -1]}
{Sqrt[a/x^2]/Sqrt[1 + x^2], x, 3, (-Sqrt[a/x^2])*x*ArcTanh[Sqrt[1 + x^2]]}
{Sqrt[a/x^3]/Sqrt[1 + x^2], x, 4, -2*Sqrt[a/x^3]*x*Sqrt[1 + x^2] - 2*(-1)^(1/4)*Sqrt[a/x^3]*x^(3/2)*EllipticE[ArcSin[(-1)^(1/4)*Sqrt[x]], -1] + 2*(-1)^(1/4)*Sqrt[a/x^3]*x^(3/2)*EllipticF[ArcSin[(-1)^(1/4)*Sqrt[x]], -1]}
{Sqrt[a/x^4]/Sqrt[1 + x^2], x, 2, (-Sqrt[a/x^4])*x*Sqrt[1 + x^2]}


{Sqrt[a*x^4]/Sqrt[1 + x^3], x, 2, (2*Sqrt[a*x^4]*Sqrt[1 + x^3])/(3*x^2)}
{Sqrt[a*x^3]/Sqrt[1 + x^3], x, 3, (2/5)*x*Sqrt[a*x^3]*Hypergeometric2F1[1/2, 5/6, 11/6, -x^3]}
{Sqrt[a*x^2]/Sqrt[1 + x^3], x, 7, ((1/2 + I/2)*Sqrt[I*(1 - I*Sqrt[3] - 2*x)]*Sqrt[1 + I*Sqrt[3] - 2*x]*Sqrt[a*x^2]*(1 + x)*EllipticE[I*ArcSinh[((1/2 + I/2)*Sqrt[1 + I*Sqrt[3] - 2*x])/3^(1/4)], -((2*Sqrt[3])/(3*I - Sqrt[3]))])/(x*Sqrt[(1 + x)/(3 + I*Sqrt[3])]*Sqrt[1 + x^3]) - ((1 + I)*Sqrt[I*(1 - I*Sqrt[3] - 2*x)]*Sqrt[1 + I*Sqrt[3] - 2*x]*Sqrt[a*x^2]*Sqrt[(1 + x)/(3 + I*Sqrt[3])]*EllipticF[I*ArcSinh[((1/2 + I/2)*Sqrt[1 + I*Sqrt[3] - 2*x])/3^(1/4)], -((2*Sqrt[3])/(3*I - Sqrt[3]))])/(x*Sqrt[1 + x^3])}
{Sqrt[a*x^1]/Sqrt[1 + x^3], x, 3, (2*Sqrt[a*x]*ArcSinh[x^(3/2)])/(3*Sqrt[x])}
{Sqrt[a/x^1]/Sqrt[1 + x^3], x, 3, (Sqrt[a/x]*x*(1 + x)*Sqrt[(1 - x + x^2)/(1 + x + Sqrt[3]*x)^2]*EllipticF[ArcCos[(1 + x - Sqrt[3]*x)/(1 + x + Sqrt[3]*x)], (1/4)*(2 + Sqrt[3])])/(3^(1/4)*Sqrt[(x*(1 + x))/(1 + x + Sqrt[3]*x)^2]*Sqrt[1 + x^3]), (Sqrt[a/x]*x*Sqrt[(1 - x + x^2)/(1 + (1 + Sqrt[3])*x)^2]*EllipticF[ArcCos[(1 + (1 - Sqrt[3])*x)/(1 + (1 + Sqrt[3])*x)], (1/4)*(2 + Sqrt[3])])/(3^(1/4)*Sqrt[(x*(1 + x))/(1 + (1 + Sqrt[3])*x)^2]*Sqrt[1 + x^3]) + (Sqrt[a/x]*x^2*Sqrt[(1 - x + x^2)/(1 + (1 + Sqrt[3])*x)^2]*EllipticF[ArcCos[(1 + (1 - Sqrt[3])*x)/(1 + (1 + Sqrt[3])*x)], (1/4)*(2 + Sqrt[3])])/(3^(1/4)*Sqrt[(x*(1 + x))/(1 + (1 + Sqrt[3])*x)^2]*Sqrt[1 + x^3])}
{Sqrt[a/x^2]/Sqrt[1 + x^3], x, 3, (-(2/3))*Sqrt[a/x^2]*x*ArcTanh[Sqrt[1 + x^3]]}
{Sqrt[a/x^3]/Sqrt[1 + x^3], x, 4, -2*Sqrt[a/x^3]*x*Sqrt[1 + x^3] + (4/5)*Sqrt[a/x^3]*x^4*Hypergeometric2F1[1/2, 5/6, 11/6, -x^3]}
{Sqrt[a/x^4]/Sqrt[1 + x^3], x, 8, (-Sqrt[a/x^4])*x*Sqrt[1 + x^3] + ((1/4 + I/4)*Sqrt[I*(1 - I*Sqrt[3] - 2*x)]*Sqrt[1 + I*Sqrt[3] - 2*x]*Sqrt[a/x^4]*x^2*(1 + x)*EllipticE[I*ArcSinh[((1/2 + I/2)*Sqrt[1 + I*Sqrt[3] - 2*x])/3^(1/4)], -((2*Sqrt[3])/(3*I - Sqrt[3]))])/(Sqrt[(1 + x)/(3 + I*Sqrt[3])]*Sqrt[1 + x^3]) - ((1/2 + I/2)*Sqrt[I*(1 - I*Sqrt[3] - 2*x)]*Sqrt[1 + I*Sqrt[3] - 2*x]*Sqrt[a/x^4]*x^2*Sqrt[(1 + x)/(3 + I*Sqrt[3])]*EllipticF[I*ArcSinh[((1/2 + I/2)*Sqrt[1 + I*Sqrt[3] - 2*x])/3^(1/4)], -((2*Sqrt[3])/(3*I - Sqrt[3]))])/Sqrt[1 + x^3]}


{Sqrt[a*x^(2*n)]/Sqrt[1 + x^n], x, 3, (2*x^(1 - n)*Sqrt[a*x^(2*n)]*Sqrt[1 + x^n])/(2 + n) - (2*x^(1 - n)*Sqrt[a*x^(2*n)]*Hypergeometric2F1[1/2, 1/n, 1 + 1/n, -x^n])/(2 + n)}
{Sqrt[a*x^n]/Sqrt[1 + x^n], x, 2, (2*x*Sqrt[a*x^n]*Hypergeometric2F1[1/2, (1/2)*(1 + 2/n), (1/2)*(3 + 2/n), -x^n])/(2 + n)}
{Sqrt[a*x^(n/2)]/Sqrt[1 + x^n], x, 2, (4*x*Sqrt[a*x^(n/2)]*Hypergeometric2F1[1/2, (1/4)*(1 + 4/n), (1/4)*(5 + 4/n), -x^n])/(4 + n)}

{Sqrt[a*x^(2*n)]/Sqrt[1 + x^n] + (2*Sqrt[a*x^(2*n)])/(x^n*((2 + n)*Sqrt[1 + x^n])), x, 6, (2*x^(1 - n)*Sqrt[a*x^(2*n)]*Sqrt[1 + x^n])/(2 + n)}


{Sqrt[a*x]/(Sqrt[d + e*x]*Sqrt[e + f*x]), x, 2, (2*Sqrt[-e^2 + d*f]*Sqrt[a*x]*Sqrt[(e*(e + f*x))/(e^2 - d*f)]*EllipticE[ArcSin[(Sqrt[f]*Sqrt[d + e*x])/Sqrt[-e^2 + d*f]], 1 - e^2/(d*f)])/(e*Sqrt[f]*Sqrt[-((e*x)/d)]*Sqrt[e + f*x])}


(* ::Subsection::Closed:: *)
(*Integrands of the form (a x^n)^p (b x^m)^q ...*)


{(a*x^m)^r, x, 2, (x*(a*x^m)^r)/(1 + m*r)}
{(a*x^m)^r*(b*x^n)^s, x, 3, (x*(a*x^m)^r*(b*x^n)^s)/(1 + m*r + n*s)}
{(a*x^m)^r*(b*x^n)^s*(c*x^p)^t, x, 4, (x*(a*x^m)^r*(b*x^n)^s*(c*x^p)^t)/(1 + m*r + n*s + p*t)}


(* ::Subsection::Closed:: *)
(*Integrands of the form (c x^n)^(1/n) (a+b (c x^n)^(m/n))^p*)


{(c*x^n)^(1/n)*(a + b*(c*x^n)^(1/n))^p, x, 4, -((a*x*(a + b*(c*x^n)^(1/n))^(1 + p))/((c*x^n)^n^(-1)*(b^2*(1 + p)))) + (x*(a + b*(c*x^n)^(1/n))^(2 + p))/((c*x^n)^n^(-1)*(b^2*(2 + p)))}

{(c*x^n)^(1/n)*(a + b*(c*x^n)^(1/n))^3, x, 4, -((a*x*(a + b*(c*x^n)^(1/n))^4)/((c*x^n)^n^(-1)*(4*b^2))) + (x*(a + b*(c*x^n)^(1/n))^5)/((c*x^n)^n^(-1)*(5*b^2))}
{(c*x^n)^(1/n)*(a + b*(c*x^n)^(1/n))^2, x, 4, (1/2)*a^2*x*(c*x^n)^(1/n) + (2/3)*a*b*x*(c*x^n)^(2/n) + (1/4)*b^2*x*(c*x^n)^(3/n)}
{(c*x^n)^(1/n)*(a + b*(c*x^n)^(1/n))^1, x, 4, (1/2)*a*x*(c*x^n)^(1/n) + (1/3)*b*x*(c*x^n)^(2/n)}
{(c*x^n)^(1/n)/(a + b*(c*x^n)^(1/n))^1, x, 4, x/b - (a*x*Log[a + b*(c*x^n)^(1/n)])/((c*x^n)^n^(-1)*b^2)}
{(c*x^n)^(1/n)/(a + b*(c*x^n)^(1/n))^2, x, 4, (a*x)/((c*x^n)^n^(-1)*(b^2*(a + b*(c*x^n)^(1/n)))) + (x*Log[a + b*(c*x^n)^(1/n)])/((c*x^n)^n^(-1)*b^2)}
{(c*x^n)^(1/n)/(a + b*(c*x^n)^(1/n))^3, x, 3, (x*(c*x^n)^(1/n))/(2*a*(a + b*(c*x^n)^(1/n))^2)}
{(c*x^n)^(1/n)/(a + b*(c*x^n)^(1/n))^4, x, 4, (a*x)/((c*x^n)^n^(-1)*(3*b^2*(a + b*(c*x^n)^(1/n))^3)) - x/((c*x^n)^n^(-1)*(2*b^2*(a + b*(c*x^n)^(1/n))^2))}
{(c*x^n)^(1/n)/(a + b*(c*x^n)^(1/n))^5, x, 4, (a*x)/((c*x^n)^n^(-1)*(4*b^2*(a + b*(c*x^n)^(1/n))^4)) - x/((c*x^n)^n^(-1)*(3*b^2*(a + b*(c*x^n)^(1/n))^3))}
