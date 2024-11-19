(* ::Package:: *)

(* ::Title:: *)
(*Integration problems of the form (a+b x^n)^m (c+d x^n)^p*)


(* ::Section:: *)
(*Integrands of the form (a+b x^2)^m (c+d x^2)^p*)


(* ::Subsection::Closed:: *)
(*Integrands of the form (a+b x^2)^m (c+d x^2)^p*)


(* ::Subsubsection::Closed:: *)
(*m>0*)


{(a + b*x^2)*(c + d*x^2)^4, x, 2, a*c^4*x + (1/3)*c^3*(b*c + 4*a*d)*x^3 + (2/5)*c^2*d*(2*b*c + 3*a*d)*x^5 + (2/7)*c*d^2*(3*b*c + 2*a*d)*x^7 + (1/9)*d^3*(4*b*c + a*d)*x^9 + (1/11)*b*d^4*x^11}
{(a + b*x^2)*(c + d*x^2)^3, x, 2, a*c^3*x + (1/3)*c^2*(b*c + 3*a*d)*x^3 + (3/5)*c*d*(b*c + a*d)*x^5 + (1/7)*d^2*(3*b*c + a*d)*x^7 + (1/9)*b*d^3*x^9}
{(a + b*x^2)*(c + d*x^2)^2, x, 2, a*c^2*x + (1/3)*c*(b*c + 2*a*d)*x^3 + (1/5)*d*(2*b*c + a*d)*x^5 + (1/7)*b*d^2*x^7}
{(a + b*x^2)*(c + d*x^2)^1, x, 2, a*c*x + (1/3)*(b*c + a*d)*x^3 + (1/5)*b*d*x^5}
{(a + b*x^2)/(c + d*x^2)^1, x, 2, (b*x)/d - ((b*c - a*d)*ArcTan[(Sqrt[d]*x)/Sqrt[c]])/(Sqrt[c]*d^(3/2))}
{(a + b*x^2)/(c + d*x^2)^2, x, 2, -(((b*c - a*d)*x)/(2*c*d*(c + d*x^2))) + ((b*c + a*d)*ArcTan[(Sqrt[d]*x)/Sqrt[c]])/(2*c^(3/2)*d^(3/2))}
{(a + b*x^2)/(c + d*x^2)^3, x, 3, -(((b*c - a*d)*x)/(4*c*d*(c + d*x^2)^2)) + ((b*c + 3*a*d)*x)/(8*c^2*d*(c + d*x^2)) + ((b*c + 3*a*d)*ArcTan[(Sqrt[d]*x)/Sqrt[c]])/(8*c^(5/2)*d^(3/2))}


{(a + b*x^2)^2*(c + d*x^2)^3, x, 2, a^2*c^3*x + (1/3)*a*c^2*(2*b*c + 3*a*d)*x^3 + (1/5)*c*(b^2*c^2 + 6*a*b*c*d + 3*a^2*d^2)*x^5 + (1/7)*d*(3*b^2*c^2 + 6*a*b*c*d + a^2*d^2)*x^7 + (1/9)*b*d^2*(3*b*c + 2*a*d)*x^9 + (1/11)*b^2*d^3*x^11}
{(a + b*x^2)^2*(c + d*x^2)^2, x, 2, a^2*c^2*x + (2/3)*a*c*(b*c + a*d)*x^3 + (1/5)*(b^2*c^2 + 4*a*b*c*d + a^2*d^2)*x^5 + (2/7)*b*d*(b*c + a*d)*x^7 + (1/9)*b^2*d^2*x^9}
{(a + b*x^2)^2*(c + d*x^2)^1, x, 2, a^2*c*x + (1/3)*a*(2*b*c + a*d)*x^3 + (1/5)*b*(b*c + 2*a*d)*x^5 + (1/7)*b^2*d*x^7}
{(a + b*x^2)^2/(c + d*x^2)^1, x, 3, -((b*(b*c - 2*a*d)*x)/d^2) + (b^2*x^3)/(3*d) + ((b*c - a*d)^2*ArcTan[(Sqrt[d]*x)/Sqrt[c]])/(Sqrt[c]*d^(5/2))}
{(a + b*x^2)^2/(c + d*x^2)^2, x, 4, (b^2*x)/d^2 + ((b*c - a*d)^2*x)/(2*c*d^2*(c + d*x^2)) - ((b*c - a*d)*(3*b*c + a*d)*ArcTan[(Sqrt[d]*x)/Sqrt[c]])/(2*c^(3/2)*d^(5/2))}
{(a + b*x^2)^2/(c + d*x^2)^3, x, 3, -(((b*c - a*d)*x*(a + b*x^2))/(4*c*d*(c + d*x^2)^2)) + (3*(a^2/c^2 - b^2/d^2)*x)/(8*(c + d*x^2)) + ((3*b^2*c^2 + 2*a*b*c*d + 3*a^2*d^2)*ArcTan[(Sqrt[d]*x)/Sqrt[c]])/(8*c^(5/2)*d^(5/2))}


{(a + b*x^2)^3*(c + d*x^2)^3, x, 2, a^3*c^3*x + a^2*c^2*(b*c + a*d)*x^3 + (3/5)*a*c*(b^2*c^2 + 3*a*b*c*d + a^2*d^2)*x^5 + (1/7)*(b*c + a*d)*(b^2*c^2 + 8*a*b*c*d + a^2*d^2)*x^7 + (1/3)*b*d*(b^2*c^2 + 3*a*b*c*d + a^2*d^2)*x^9 + (3/11)*b^2*d^2*(b*c + a*d)*x^11 + (1/13)*b^3*d^3*x^13}
{(a + b*x^2)^3*(c + d*x^2)^2, x, 2, a^3*c^2*x + (1/3)*a^2*c*(3*b*c + 2*a*d)*x^3 + (1/5)*a*(3*b^2*c^2 + 6*a*b*c*d + a^2*d^2)*x^5 + (1/7)*b*(b^2*c^2 + 6*a*b*c*d + 3*a^2*d^2)*x^7 + (1/9)*b^2*d*(2*b*c + 3*a*d)*x^9 + (1/11)*b^3*d^2*x^11}
{(a + b*x^2)^3*(c + d*x^2)^1, x, 2, a^3*c*x + (1/3)*a^2*(3*b*c + a*d)*x^3 + (3/5)*a*b*(b*c + a*d)*x^5 + (1/7)*b^2*(b*c + 3*a*d)*x^7 + (1/9)*b^3*d*x^9}
{(a + b*x^2)^3/(c + d*x^2)^1, x, 3, (b*(b^2*c^2 - 3*a*b*c*d + 3*a^2*d^2)*x)/d^3 - (b^2*(b*c - 3*a*d)*x^3)/(3*d^2) + (b^3*x^5)/(5*d) - ((b*c - a*d)^3*ArcTan[(Sqrt[d]*x)/Sqrt[c]])/(Sqrt[c]*d^(7/2))}
{(a + b*x^2)^3/(c + d*x^2)^2, x, 4, -((b^2*(2*b*c - 3*a*d)*x)/d^3) + (b^3*x^3)/(3*d^2) - ((b*c - a*d)^3*x)/(2*c*d^3*(c + d*x^2)) + ((b*c - a*d)^2*(5*b*c + a*d)*ArcTan[(Sqrt[d]*x)/Sqrt[c]])/(2*c^(3/2)*d^(7/2))}
{(a + b*x^2)^3/(c + d*x^2)^3, x, 5, (b^3*x)/d^3 - ((b*c - a*d)^3*x)/(4*c*d^3*(c + d*x^2)^2) + (3*(b*c - a*d)^2*(3*b*c + a*d)*x)/(8*c^2*d^3*(c + d*x^2)) - (3*(b*c - a*d)*(4*b^2*c^2 + (b*c + a*d)^2)*ArcTan[(Sqrt[d]*x)/Sqrt[c]])/(8*c^(5/2)*d^(7/2))}


(* ::Subsubsection::Closed:: *)
(*m<0*)


{1/(a + b*x^2)*(c + d*x^2)^4, x, 3, (d*(2*b*c - a*d)*(2*b^2*c^2 - 2*a*b*c*d + a^2*d^2)*x)/b^4 + (d^2*(6*b^2*c^2 - 4*a*b*c*d + a^2*d^2)*x^3)/(3*b^3) + (d^3*(4*b*c - a*d)*x^5)/(5*b^2) + (d^4*x^7)/(7*b) + ((b*c - a*d)^4*ArcTan[(Sqrt[b]*x)/Sqrt[a]])/(Sqrt[a]*b^(9/2))}
{1/(a + b*x^2)*(c + d*x^2)^3, x, 3, (d*(3*b^2*c^2 - 3*a*b*c*d + a^2*d^2)*x)/b^3 + (d^2*(3*b*c - a*d)*x^3)/(3*b^2) + (d^3*x^5)/(5*b) + ((b*c - a*d)^3*ArcTan[(Sqrt[b]*x)/Sqrt[a]])/(Sqrt[a]*b^(7/2))}
{1/(a + b*x^2)*(c + d*x^2)^2, x, 3, (d*(2*b*c - a*d)*x)/b^2 + (d^2*x^3)/(3*b) + ((b*c - a*d)^2*ArcTan[(Sqrt[b]*x)/Sqrt[a]])/(Sqrt[a]*b^(5/2))}
{1/(a + b*x^2)*(c + d*x^2)^1, x, 2, (d*x)/b + ((b*c - a*d)*ArcTan[(Sqrt[b]*x)/Sqrt[a]])/(Sqrt[a]*b^(3/2))}
{1/(a + b*x^2)/(c + d*x^2)^1, x, 3, (Sqrt[b]*ArcTan[(Sqrt[b]*x)/Sqrt[a]])/(Sqrt[a]*(b*c - a*d)) - (Sqrt[d]*ArcTan[(Sqrt[d]*x)/Sqrt[c]])/(Sqrt[c]*(b*c - a*d))}
{1/(a + b*x^2)/(c + d*x^2)^2, x, 4, -((d*x)/(2*c*(b*c - a*d)*(c + d*x^2))) + (b^(3/2)*ArcTan[(Sqrt[b]*x)/Sqrt[a]])/(Sqrt[a]*(b*c - a*d)^2) - (Sqrt[d]*(3*b*c - a*d)*ArcTan[(Sqrt[d]*x)/Sqrt[c]])/(2*c^(3/2)*(b*c - a*d)^2)}
{1/(a + b*x^2)/(c + d*x^2)^3, x, 5, -((d*x)/(4*c*(b*c - a*d)*(c + d*x^2)^2)) - (d*(7*b*c - 3*a*d)*x)/(8*c^2*(b*c - a*d)^2*(c + d*x^2)) + (b^(5/2)*ArcTan[(Sqrt[b]*x)/Sqrt[a]])/(Sqrt[a]*(b*c - a*d)^3) - (Sqrt[d]*(15*b^2*c^2 - 10*a*b*c*d + 3*a^2*d^2)*ArcTan[(Sqrt[d]*x)/Sqrt[c]])/(8*c^(5/2)*(b*c - a*d)^3)}


{1/(a + b*x^2)^2*(c + d*x^2)^5, x, 4, (d^2*(10*b^3*c^3 - 20*a*b^2*c^2*d + 15*a^2*b*c*d^2 - 4*a^3*d^3)*x)/b^5 + (d^3*(10*b^2*c^2 - 10*a*b*c*d + 3*a^2*d^2)*x^3)/(3*b^4) + (d^4*(5*b*c - 2*a*d)*x^5)/(5*b^3) + (d^5*x^7)/(7*b^2) + ((b*c - a*d)^5*x)/(2*a*b^5*(a + b*x^2)) + ((b*c - a*d)^4*(b*c + 9*a*d)*ArcTan[(Sqrt[b]*x)/Sqrt[a]])/(2*a^(3/2)*b^(11/2))}
{1/(a + b*x^2)^2*(c + d*x^2)^4, x, 4, (d^2*(6*b^2*c^2 - 8*a*b*c*d + 3*a^2*d^2)*x)/b^4 + (2*d^3*(2*b*c - a*d)*x^3)/(3*b^3) + (d^4*x^5)/(5*b^2) + ((b*c - a*d)^4*x)/(2*a*b^4*(a + b*x^2)) + ((b*c - a*d)^3*(b*c + 7*a*d)*ArcTan[(Sqrt[b]*x)/Sqrt[a]])/(2*a^(3/2)*b^(9/2))}
{1/(a + b*x^2)^2*(c + d*x^2)^3, x, 4, (d^2*(3*b*c - 2*a*d)*x)/b^3 + (d^3*x^3)/(3*b^2) + ((b*c - a*d)^3*x)/(2*a*b^3*(a + b*x^2)) + ((b*c - a*d)^2*(b*c + 5*a*d)*ArcTan[(Sqrt[b]*x)/Sqrt[a]])/(2*a^(3/2)*b^(7/2))}
{1/(a + b*x^2)^2*(c + d*x^2)^2, x, 4, (d^2*x)/b^2 + ((b*c - a*d)^2*x)/(2*a*b^2*(a + b*x^2)) + ((b*c - a*d)*(b*c + 3*a*d)*ArcTan[(Sqrt[b]*x)/Sqrt[a]])/(2*a^(3/2)*b^(5/2))}
{1/(a + b*x^2)^2*(c + d*x^2)^1, x, 2, ((b*c - a*d)*x)/(2*a*b*(a + b*x^2)) + ((b*c + a*d)*ArcTan[(Sqrt[b]*x)/Sqrt[a]])/(2*a^(3/2)*b^(3/2))}
{1/(a + b*x^2)^2/(c + d*x^2)^1, x, 4, (b*x)/(2*a*(b*c - a*d)*(a + b*x^2)) + (Sqrt[b]*(b*c - 3*a*d)*ArcTan[(Sqrt[b]*x)/Sqrt[a]])/(2*a^(3/2)*(b*c - a*d)^2) + (d^(3/2)*ArcTan[(Sqrt[d]*x)/Sqrt[c]])/(Sqrt[c]*(b*c - a*d)^2)}
{1/(a + b*x^2)^2/(c + d*x^2)^2, x, 5, (d*(b*c + a*d)*x)/(2*a*c*(b*c - a*d)^2*(c + d*x^2)) + (b*x)/(2*a*(b*c - a*d)*(a + b*x^2)*(c + d*x^2)) + (b^(3/2)*(b*c - 5*a*d)*ArcTan[(Sqrt[b]*x)/Sqrt[a]])/(2*a^(3/2)*(b*c - a*d)^3) + (d^(3/2)*(5*b*c - a*d)*ArcTan[(Sqrt[d]*x)/Sqrt[c]])/(2*c^(3/2)*(b*c - a*d)^3)}
{1/(a + b*x^2)^2/(c + d*x^2)^3, x, 6, (d*(2*b*c + a*d)*x)/(4*a*c*(b*c - a*d)^2*(c + d*x^2)^2) + (b*x)/(2*a*(b*c - a*d)*(a + b*x^2)*(c + d*x^2)^2) + (d*(4*b*c - a*d)*(b*c + 3*a*d)*x)/(8*a*c^2*(b*c - a*d)^3*(c + d*x^2)) + (b^(5/2)*(b*c - 7*a*d)*ArcTan[(Sqrt[b]*x)/Sqrt[a]])/(2*a^(3/2)*(b*c - a*d)^4) + (d^(3/2)*(35*b^2*c^2 - 14*a*b*c*d + 3*a^2*d^2)*ArcTan[(Sqrt[d]*x)/Sqrt[c]])/(8*c^(5/2)*(b*c - a*d)^4)}


{1/(a + b*x^2)^3*(c + d*x^2)^5, x, 5, (d^3*(10*b^2*c^2 - 15*a*b*c*d + 6*a^2*d^2)*x)/b^5 + (d^4*(5*b*c - 3*a*d)*x^3)/(3*b^4) + (d^5*x^5)/(5*b^3) + ((b*c - a*d)^5*x)/(4*a*b^5*(a + b*x^2)^2) + ((b*c - a*d)^4*(3*b*c + 17*a*d)*x)/(8*a^2*b^5*(a + b*x^2)) + ((b*c - a*d)^3*(3*b^2*c^2 + 14*a*b*c*d + 63*a^2*d^2)*ArcTan[(Sqrt[b]*x)/Sqrt[a]])/(8*a^(5/2)*b^(11/2))}
{1/(a + b*x^2)^3*(c + d*x^2)^4, x, 5, (d^3*(4*b*c - 3*a*d)*x)/b^4 + (d^4*x^3)/(3*b^3) + ((b*c - a*d)^4*x)/(4*a*b^4*(a + b*x^2)^2) + ((b*c - a*d)^3*(3*b*c + 13*a*d)*x)/(8*a^2*b^4*(a + b*x^2)) + ((b*c - a*d)^2*(3*b^2*c^2 + 10*a*b*c*d + 35*a^2*d^2)*ArcTan[(Sqrt[b]*x)/Sqrt[a]])/(8*a^(5/2)*b^(9/2))}
{1/(a + b*x^2)^3*(c + d*x^2)^3, x, 5, (d^3*x)/b^3 + ((b*c - a*d)^3*x)/(4*a*b^3*(a + b*x^2)^2) + (3*(b*c - a*d)^2*(b*c + 3*a*d)*x)/(8*a^2*b^3*(a + b*x^2)) + (3*(b*c - a*d)*(4*a^2*d^2 + (b*c + a*d)^2)*ArcTan[(Sqrt[b]*x)/Sqrt[a]])/(8*a^(5/2)*b^(7/2))}
{1/(a + b*x^2)^3*(c + d*x^2)^2, x, 3, (3*(c^2/a^2 - d^2/b^2)*x)/(8*(a + b*x^2)) + ((b*c - a*d)*x*(c + d*x^2))/(4*a*b*(a + b*x^2)^2) + ((3*b^2*c^2 + 2*a*b*c*d + 3*a^2*d^2)*ArcTan[(Sqrt[b]*x)/Sqrt[a]])/(8*a^(5/2)*b^(5/2))}
{1/(a + b*x^2)^3*(c + d*x^2)^1, x, 3, ((b*c - a*d)*x)/(4*a*b*(a + b*x^2)^2) + ((3*b*c + a*d)*x)/(8*a^2*b*(a + b*x^2)) + ((3*b*c + a*d)*ArcTan[(Sqrt[b]*x)/Sqrt[a]])/(8*a^(5/2)*b^(3/2))}
{1/(a + b*x^2)^3/(c + d*x^2)^1, x, 5, (b*x)/(4*a*(b*c - a*d)*(a + b*x^2)^2) + (b*(3*b*c - 7*a*d)*x)/(8*a^2*(b*c - a*d)^2*(a + b*x^2)) + (Sqrt[b]*(3*b^2*c^2 - 10*a*b*c*d + 15*a^2*d^2)*ArcTan[(Sqrt[b]*x)/Sqrt[a]])/(8*a^(5/2)*(b*c - a*d)^3) - (d^(5/2)*ArcTan[(Sqrt[d]*x)/Sqrt[c]])/(Sqrt[c]*(b*c - a*d)^3)}
{1/(a + b*x^2)^3/(c + d*x^2)^2, x, 6, (d*(b*c - 4*a*d)*(3*b*c + a*d)*x)/(8*a^2*c*(b*c - a*d)^3*(c + d*x^2)) + (b*x)/(4*a*(b*c - a*d)*(a + b*x^2)^2*(c + d*x^2)) + (3*b*(b*c - 3*a*d)*x)/(8*a^2*(b*c - a*d)^2*(a + b*x^2)*(c + d*x^2)) + (b^(3/2)*(3*b^2*c^2 - 14*a*b*c*d + 35*a^2*d^2)*ArcTan[(Sqrt[b]*x)/Sqrt[a]])/(8*a^(5/2)*(b*c - a*d)^4) - (d^(5/2)*(7*b*c - a*d)*ArcTan[(Sqrt[d]*x)/Sqrt[c]])/(2*c^(3/2)*(b*c - a*d)^4)}
{1/(a + b*x^2)^3/(c + d*x^2)^3, x, 7, (d*(3*b^2*c^2 - 13*a*b*c*d - 2*a^2*d^2)*x)/(8*a^2*c*(b*c - a*d)^3*(c + d*x^2)^2) + (b*x)/(4*a*(b*c - a*d)*(a + b*x^2)^2*(c + d*x^2)^2) + (b*(3*b*c - 11*a*d)*x)/(8*a^2*(b*c - a*d)^2*(a + b*x^2)*(c + d*x^2)^2) + (3*d*(b*c + a*d)*(b^2*c^2 - 6*a*b*c*d + a^2*d^2)*x)/(8*a^2*c^2*(b*c - a*d)^4*(c + d*x^2)) + (3*b^(5/2)*(b^2*c^2 - 6*a*b*c*d + 21*a^2*d^2)*ArcTan[(Sqrt[b]*x)/Sqrt[a]])/(8*a^(5/2)*(b*c - a*d)^5) - (3*d^(5/2)*(21*b^2*c^2 - 6*a*b*c*d + a^2*d^2)*ArcTan[(Sqrt[d]*x)/Sqrt[c]])/(8*c^(5/2)*(b*c - a*d)^5)}


{(-1 + x^2)^3/(1 + x^2)^4, x, 3, -((x*(1 - x^2)^2)/(3*(1 + x^2)^3)) - (2*x)/(3*(1 + x^2))}
{(-1 + x^2)^4/(1 + x^2)^5, x, 5, (x*(1 - x^2)^3)/(4*(1 + x^2)^4) + (3*x*(1 - x^2))/(8*(1 + x^2)^2) + (3*ArcTan[x])/8}


(* ::Subsection::Closed:: *)
(*Integrands of the form (a+b x^2)^(m/2) (c+d x^2)^p*)


(* ::Subsubsection::Closed:: *)
(*m>0*)


{(a + b*x^2)^(1/2)*(c + d*x^2)^3, x, 5, ((64*b^3*c^3 - 48*a*b^2*c^2*d + 24*a^2*b*c*d^2 - 5*a^3*d^3)*x*Sqrt[a + b*x^2])/(128*b^3) + (d*(88*b^2*c^2 - 68*a*b*c*d + 15*a^2*d^2)*x*(a + b*x^2)^(3/2))/(192*b^3) + (d*x*(a + b*x^2)^(3/2)*(c + d*x^2)^2)/(8*b) + (d*x*(a + b*x^2)^(3/2)*(c*(8*b*c - a*d) + d*(12*b*c - 5*a*d)*x^2))/(48*b^2) + (a*(64*b^3*c^3 - 48*a*b^2*c^2*d + 24*a^2*b*c*d^2 - 5*a^3*d^3)*ArcTanh[(Sqrt[b]*x)/Sqrt[a + b*x^2]])/(128*b^(7/2))}
{(a + b*x^2)^(1/2)*(c + d*x^2)^2, x, 4, ((8*b^2*c^2 - 4*a*b*c*d + a^2*d^2)*x*Sqrt[a + b*x^2])/(16*b^2) + (d*(8*b*c - 3*a*d)*x*(a + b*x^2)^(3/2))/(24*b^2) + (d*x*(a + b*x^2)^(3/2)*(c + d*x^2))/(6*b) + (a*(8*b^2*c^2 - 4*a*b*c*d + a^2*d^2)*ArcTanh[(Sqrt[b]*x)/Sqrt[a + b*x^2]])/(16*b^(5/2))}
{(a + b*x^2)^(1/2)*(c + d*x^2)^1, x, 3, ((4*b*c - a*d)*x*Sqrt[a + b*x^2])/(8*b) + (d*x*(a + b*x^2)^(3/2))/(4*b) + (a*(4*b*c - a*d)*ArcTanh[(Sqrt[b]*x)/Sqrt[a + b*x^2]])/(8*b^(3/2))}
{(a + b*x^2)^(1/2)*(c + d*x^2)^0, x, 2, (1/2)*x*Sqrt[a + b*x^2] + (a*ArcTanh[(Sqrt[b]*x)/Sqrt[a + b*x^2]])/(2*Sqrt[b])}
{(a + b*x^2)^(1/2)/(c + d*x^2)^1, x, 3, (Sqrt[b]*ArcTanh[(Sqrt[b]*x)/Sqrt[a + b*x^2]])/d - (Sqrt[b*c - a*d]*ArcTanh[(Sqrt[b*c - a*d]*x)/(Sqrt[c]*Sqrt[a + b*x^2])])/(Sqrt[c]*d)}
{(a + b*x^2)^(1/2)/(c + d*x^2)^2, x, 3, (x*Sqrt[a + b*x^2])/(2*c*(c + d*x^2)) + (a*ArcTanh[(Sqrt[b*c - a*d]*x)/(Sqrt[c]*Sqrt[a + b*x^2])])/(2*c^(3/2)*Sqrt[b*c - a*d])}
{(a + b*x^2)^(1/2)/(c + d*x^2)^3, x, 4, (x*Sqrt[a + b*x^2])/(4*c*(c + d*x^2)^2) + ((2*b*c - 3*a*d)*x*Sqrt[a + b*x^2])/(8*c^2*(b*c - a*d)*(c + d*x^2)) + (a*(4*b*c - 3*a*d)*ArcTanh[(Sqrt[b*c - a*d]*x)/(Sqrt[c]*Sqrt[a + b*x^2])])/(8*c^(5/2)*(b*c - a*d)^(3/2))}
{(a + b*x^2)^(1/2)/(c + d*x^2)^4, x, 5, (x*Sqrt[a + b*x^2])/(6*c*(c + d*x^2)^3) + ((4*b*c - 5*a*d)*x*Sqrt[a + b*x^2])/(24*c^2*(b*c - a*d)*(c + d*x^2)^2) + ((2*b*c - 5*a*d)*(4*b*c - 3*a*d)*x*Sqrt[a + b*x^2])/(48*c^3*(b*c - a*d)^2*(c + d*x^2)) + (a*(8*b^2*c^2 - 12*a*b*c*d + 5*a^2*d^2)*ArcTanh[(Sqrt[b*c - a*d]*x)/(Sqrt[c]*Sqrt[a + b*x^2])])/(16*c^(7/2)*(b*c - a*d)^(5/2))}


{(a + b*x^2)^(3/2)*(c + d*x^2)^3, x, 6, (3*a*(4*b*c - a*d)*(8*b^2*c^2 - 2*a*b*c*d + a^2*d^2)*x*Sqrt[a + b*x^2])/(256*b^3) + ((4*b*c - a*d)*(8*b^2*c^2 - 2*a*b*c*d + a^2*d^2)*x*(a + b*x^2)^(3/2))/(128*b^3) + (d*(44*b^2*c^2 - 28*a*b*c*d + 5*a^2*d^2)*x*(a + b*x^2)^(5/2))/(160*b^3) + (d*x*(a + b*x^2)^(5/2)*(c + d*x^2)^2)/(10*b) + (d*x*(a + b*x^2)^(5/2)*(c*(10*b*c - a*d) + d*(14*b*c - 5*a*d)*x^2))/(80*b^2) + (3*a^2*(4*b*c - a*d)*(8*b^2*c^2 - 2*a*b*c*d + a^2*d^2)*ArcTanh[(Sqrt[b]*x)/Sqrt[a + b*x^2]])/(256*b^(7/2))}
{(a + b*x^2)^(3/2)*(c + d*x^2)^2, x, 5, (a*(48*b^2*c^2 - 16*a*b*c*d + 3*a^2*d^2)*x*Sqrt[a + b*x^2])/(128*b^2) + ((48*b^2*c^2 - 16*a*b*c*d + 3*a^2*d^2)*x*(a + b*x^2)^(3/2))/(192*b^2) + (d*(10*b*c - 3*a*d)*x*(a + b*x^2)^(5/2))/(48*b^2) + (d*x*(a + b*x^2)^(5/2)*(c + d*x^2))/(8*b) + (a^2*(48*b^2*c^2 - 16*a*b*c*d + 3*a^2*d^2)*ArcTanh[(Sqrt[b]*x)/Sqrt[a + b*x^2]])/(128*b^(5/2))}
{(a + b*x^2)^(3/2)*(c + d*x^2)^1, x, 4, (a*(6*b*c - a*d)*x*Sqrt[a + b*x^2])/(16*b) + ((6*b*c - a*d)*x*(a + b*x^2)^(3/2))/(24*b) + (d*x*(a + b*x^2)^(5/2))/(6*b) + (a^2*(6*b*c - a*d)*ArcTanh[(Sqrt[b]*x)/Sqrt[a + b*x^2]])/(16*b^(3/2))}
{(a + b*x^2)^(3/2)*(c + d*x^2)^0, x, 3, (3/8)*a*x*Sqrt[a + b*x^2] + (1/4)*x*(a + b*x^2)^(3/2) + (3*a^2*ArcTanh[(Sqrt[b]*x)/Sqrt[a + b*x^2]])/(8*Sqrt[b])}
{(a + b*x^2)^(3/2)/(c + d*x^2)^1, x, 4, (b*x*Sqrt[a + b*x^2])/(2*d) - (Sqrt[b]*(2*b*c - 3*a*d)*ArcTanh[(Sqrt[b]*x)/Sqrt[a + b*x^2]])/(2*d^2) + ((b*c - a*d)^(3/2)*ArcTanh[(Sqrt[b*c - a*d]*x)/(Sqrt[c]*Sqrt[a + b*x^2])])/(Sqrt[c]*d^2)}
{(a + b*x^2)^(3/2)/(c + d*x^2)^2, x, 4, -(((b*c - a*d)*x*Sqrt[a + b*x^2])/(2*c*d*(c + d*x^2))) + (b^(3/2)*ArcTanh[(Sqrt[b]*x)/Sqrt[a + b*x^2]])/d^2 - (Sqrt[b*c - a*d]*(2*b*c + a*d)*ArcTanh[(Sqrt[b*c - a*d]*x)/(Sqrt[c]*Sqrt[a + b*x^2])])/(2*c^(3/2)*d^2)}
{(a + b*x^2)^(3/2)/(c + d*x^2)^3, x, 4, -(((b*c - a*d)*x*Sqrt[a + b*x^2])/(4*c*d*(c + d*x^2)^2)) + ((2*b*c + 3*a*d)*x*Sqrt[a + b*x^2])/(8*c^2*d*(c + d*x^2)) + (3*a^2*ArcTanh[(Sqrt[b*c - a*d]*x)/(Sqrt[c]*Sqrt[a + b*x^2])])/(8*c^(5/2)*Sqrt[b*c - a*d])}
{(a + b*x^2)^(3/2)/(c + d*x^2)^4, x, 5, -(((b*c - a*d)*x*Sqrt[a + b*x^2])/(6*c*d*(c + d*x^2)^3)) + ((2*b*c + 5*a*d)*x*Sqrt[a + b*x^2])/(24*c^2*d*(c + d*x^2)^2) + ((4*b^2*c^2 + 8*a*b*c*d - 15*a^2*d^2)*x*Sqrt[a + b*x^2])/(48*c^3*d*(b*c - a*d)*(c + d*x^2)) + (a^2*(6*b*c - 5*a*d)*ArcTanh[(Sqrt[b*c - a*d]*x)/(Sqrt[c]*Sqrt[a + b*x^2])])/(16*c^(7/2)*(b*c - a*d)^(3/2))}
{(a + b*x^2)^(3/2)/(c + d*x^2)^5, x, 6, -(((b*c - a*d)*x*Sqrt[a + b*x^2])/(8*c*d*(c + d*x^2)^4)) + ((2*b*c + 7*a*d)*x*Sqrt[a + b*x^2])/(48*c^2*d*(c + d*x^2)^3) + ((8*b^2*c^2 + 24*a*b*c*d - 35*a^2*d^2)*x*Sqrt[a + b*x^2])/(192*c^3*d*(b*c - a*d)*(c + d*x^2)^2) + ((16*b^3*c^3 + 40*a*b^2*c^2*d - 170*a^2*b*c*d^2 + 105*a^3*d^3)*x*Sqrt[a + b*x^2])/(384*c^4*d*(b*c - a*d)^2*(c + d*x^2)) + (a^2*(48*b^2*c^2 - 80*a*b*c*d + 35*a^2*d^2)*ArcTanh[(Sqrt[b*c - a*d]*x)/(Sqrt[c]*Sqrt[a + b*x^2])])/(128*c^(9/2)*(b*c - a*d)^(5/2))}


{Sqrt[1 - x^2]/(1 + x^2), x, 3, -ArcSin[x] + Sqrt[2]*ArcTan[(Sqrt[2]*x)/Sqrt[1 - x^2]]}
{Sqrt[1 + x^2]/(-1 + x^2), x, 3, ArcSinh[x] - Sqrt[2]*ArcTanh[(Sqrt[2]*x)/Sqrt[1 + x^2]]}
{Sqrt[1 - x^2]/(-1 + 2*x^2), x, 3, -(ArcSin[x]/2) - (1/2)*ArcTanh[x/Sqrt[1 - x^2]]}


(* ::Subsubsection::Closed:: *)
(*m<0*)


{1/(a + b*x^2)^(1/2)*(c + d*x^2)^3, x, 4, (d*(52*b^2*c^2 - 52*a*b*c*d + 15*a^2*d^2)*x*Sqrt[a + b*x^2])/(48*b^3) + (d*x*Sqrt[a + b*x^2]*(c + d*x^2)^2)/(6*b) + (d*x*Sqrt[a + b*x^2]*(c*(6*b*c - a*d) + 5*d*(2*b*c - a*d)*x^2))/(24*b^2) + ((2*b*c - a*d)*(8*b^2*c^2 - 8*a*b*c*d + 5*a^2*d^2)*ArcTanh[(Sqrt[b]*x)/Sqrt[a + b*x^2]])/(16*b^(7/2))}
{1/(a + b*x^2)^(1/2)*(c + d*x^2)^2, x, 3, (3*d*(2*b*c - a*d)*x*Sqrt[a + b*x^2])/(8*b^2) + (d*x*Sqrt[a + b*x^2]*(c + d*x^2))/(4*b) + ((8*b^2*c^2 - 8*a*b*c*d + 3*a^2*d^2)*ArcTanh[(Sqrt[b]*x)/Sqrt[a + b*x^2]])/(8*b^(5/2))}
{1/(a + b*x^2)^(1/2)*(c + d*x^2)^1, x, 2, (d*x*Sqrt[a + b*x^2])/(2*b) + ((2*b*c - a*d)*ArcTanh[(Sqrt[b]*x)/Sqrt[a + b*x^2]])/(2*b^(3/2))}
{1/(a + b*x^2)^(1/2)*(c + d*x^2)^0, x, 1, ArcTanh[(Sqrt[b]*x)/Sqrt[a + b*x^2]]/Sqrt[b]}
{1/(a + b*x^2)^(1/2)/(c + d*x^2)^1, x, 1, ArcTanh[(Sqrt[b*c - a*d]*x)/(Sqrt[c]*Sqrt[a + b*x^2])]/(Sqrt[c]*Sqrt[b*c - a*d])}
{1/(a + b*x^2)^(1/2)/(c + d*x^2)^2, x, 2, -((d*x*Sqrt[a + b*x^2])/(2*c*(b*c - a*d)*(c + d*x^2))) + ((2*b*c - a*d)*ArcTanh[(Sqrt[b*c - a*d]*x)/(Sqrt[c]*Sqrt[a + b*x^2])])/(2*c^(3/2)*(b*c - a*d)^(3/2))}
{1/(a + b*x^2)^(1/2)/(c + d*x^2)^3, x, 4, -((d*x*Sqrt[a + b*x^2])/(4*c*(b*c - a*d)*(c + d*x^2)^2)) - (3*d*(2*b*c - a*d)*x*Sqrt[a + b*x^2])/(8*c^2*(b*c - a*d)^2*(c + d*x^2)) + ((8*b^2*c^2 - 8*a*b*c*d + 3*a^2*d^2)*ArcTanh[(Sqrt[b*c - a*d]*x)/(Sqrt[c]*Sqrt[a + b*x^2])])/(8*c^(5/2)*(b*c - a*d)^(5/2))}


{1/(a + b*x^2)^(3/2)*(c + d*x^2)^4, x, 5, -((d*(96*b^3*c^3 - 352*a*b^2*c^2*d + 346*a^2*b*c*d^2 - 105*a^3*d^3)*x*Sqrt[a + b*x^2])/(48*a*b^4)) - (d*(6*b*c - 7*a*d)*x*Sqrt[a + b*x^2]*(c + d*x^2)^2)/(6*a*b^2) + ((b*c - a*d)*x*(c + d*x^2)^3)/(a*b*Sqrt[a + b*x^2]) + (d^2*x*Sqrt[a + b*x^2]*(a*c*(12*b*c - 7*a*d) - (24*b^2*c^2 - 64*a*b*c*d + 35*a^2*d^2)*x^2))/(24*a*b^3) + (d*(64*b^3*c^3 - 144*a*b^2*c^2*d + 120*a^2*b*c*d^2 - 35*a^3*d^3)*ArcTanh[(Sqrt[b]*x)/Sqrt[a + b*x^2]])/(16*b^(9/2))}
{1/(a + b*x^2)^(3/2)*(c + d*x^2)^3, x, 4, -((d*(8*b*c - 5*a*d)*(2*b*c - 3*a*d)*x*Sqrt[a + b*x^2])/(8*a*b^3)) + ((b*c - a*d)*x*(c + d*x^2)^2)/(a*b*Sqrt[a + b*x^2]) + (d^2*x*Sqrt[a + b*x^2]*(a*c - (4*b*c - 5*a*d)*x^2))/(4*a*b^2) + (3*d*(8*b^2*c^2 - 12*a*b*c*d + 5*a^2*d^2)*ArcTanh[(Sqrt[b]*x)/Sqrt[a + b*x^2]])/(8*b^(7/2))}
{1/(a + b*x^2)^(3/2)*(c + d*x^2)^2, x, 3, ((b*c - a*d)^2*x)/(a*b^2*Sqrt[a + b*x^2]) + (d^2*x*Sqrt[a + b*x^2])/(2*b^2) + (d*(4*b*c - 3*a*d)*ArcTanh[(Sqrt[b]*x)/Sqrt[a + b*x^2]])/(2*b^(5/2)), -((d*(2*b*c - 3*a*d)*x*Sqrt[a + b*x^2])/(2*a*b^2)) + ((b*c - a*d)*x*(c + d*x^2))/(a*b*Sqrt[a + b*x^2]) + (d*(4*b*c - 3*a*d)*ArcTanh[(Sqrt[b]*x)/Sqrt[a + b*x^2]])/(2*b^(5/2))}
{1/(a + b*x^2)^(3/2)*(c + d*x^2)^1, x, 2, ((b*c - a*d)*x)/(a*b*Sqrt[a + b*x^2]) + (d*ArcTanh[(Sqrt[b]*x)/Sqrt[a + b*x^2]])/b^(3/2)}
{1/(a + b*x^2)^(3/2)*(c + d*x^2)^0, x, 1, x/(a*Sqrt[a + b*x^2])}
{1/(a + b*x^2)^(3/2)/(c + d*x^2)^1, x, 2, (b*x)/(a*(b*c - a*d)*Sqrt[a + b*x^2]) - (d*ArcTanh[(Sqrt[b*c - a*d]*x)/(Sqrt[c]*Sqrt[a + b*x^2])])/(Sqrt[c]*(b*c - a*d)^(3/2))}
{1/(a + b*x^2)^(3/2)/(c + d*x^2)^2, x, 4, (b*x)/(a*(b*c - a*d)*Sqrt[a + b*x^2]*(c + d*x^2)) + (d*(2*b*c + a*d)*x*Sqrt[a + b*x^2])/(2*a*c*(b*c - a*d)^2*(c + d*x^2)) - (d*(4*b*c - a*d)*ArcTanh[(Sqrt[b*c - a*d]*x)/(Sqrt[c]*Sqrt[a + b*x^2])])/(2*c^(3/2)*(b*c - a*d)^(5/2))}
{1/(a + b*x^2)^(3/2)/(c + d*x^2)^3, x, 5, (b*x)/(a*(b*c - a*d)*Sqrt[a + b*x^2]*(c + d*x^2)^2) + (d*(4*b*c + a*d)*x*Sqrt[a + b*x^2])/(4*a*c*(b*c - a*d)^2*(c + d*x^2)^2) + (d*(4*b*c - a*d)*(2*b*c + 3*a*d)*x*Sqrt[a + b*x^2])/(8*a*c^2*(b*c - a*d)^3*(c + d*x^2)) - (3*d*(8*b^2*c^2 - 4*a*b*c*d + a^2*d^2)*ArcTanh[(Sqrt[b*c - a*d]*x)/(Sqrt[c]*Sqrt[a + b*x^2])])/(8*c^(5/2)*(b*c - a*d)^(7/2))}


{1/((b*c/d + b*x^2)*Sqrt[c + d*x^2]), x, 2, (d*x)/(b*c*Sqrt[c + d*x^2])}
{1/((1 + x^2)*Sqrt[1 - x^2]), x, 1, ArcTan[(Sqrt[2]*x)/Sqrt[1 - x^2]]/Sqrt[2]}
{1/((a + b*x^2)*Sqrt[c + d*x^2]), x, 1, ArcTan[(Sqrt[b*c - a*d]*x)/(Sqrt[a]*Sqrt[c + d*x^2])]/(Sqrt[a]*Sqrt[b*c - a*d])}

{(-1 + x^2)/(1 + x^2)^(3/2), x, 2, (-2*x)/Sqrt[1 + x^2] + ArcSinh[x]}


(* ::Subsection::Closed:: *)
(*Integrands of the form (a+b x^2)^(m/2) (c+d x^2)^(p/2)*)


(* ::Subsubsection::Closed:: *)
(*p>0*)


{(a + b*x^2)^(5/2)*(c + d*x^2)^(1/2), x, 8, -(((4*b^2*c^2 - 13*a*b*c*d - 15*a^2*d^2)*x*Sqrt[a + b*x^2]*Sqrt[c + d*x^2])/(105*d^2)) - (2*(2*b*c - 5*a*d)*x*(a + b*x^2)^(3/2)*Sqrt[c + d*x^2])/(35*d) + (b*x*(a + b*x^2)^(3/2)*(c + d*x^2)^(3/2))/(7*d) + (Sqrt[c]*(8*b^3*c^3 - 33*a*b^2*c^2*d + 58*a^2*b*c*d^2 + 15*a^3*d^3)*Sqrt[a + b*x^2]*Sqrt[(c + d*x^2)/c]*EllipticE[ArcSin[(Sqrt[-d]*x)/Sqrt[c]], (b*c)/(a*d)])/(105*b*(-d)^(5/2)*Sqrt[(a + b*x^2)/a]*Sqrt[c + d*x^2]) - (a*Sqrt[c]*(b*c - a*d)*(4*b^2*c^2 - 13*a*b*c*d - 15*a^2*d^2)*Sqrt[(a + b*x^2)/a]*Sqrt[(c + d*x^2)/c]*EllipticF[ArcSin[(Sqrt[-d]*x)/Sqrt[c]], (b*c)/(a*d)])/(105*b*(-d)^(5/2)*Sqrt[a + b*x^2]*Sqrt[c + d*x^2])}
{(a + b*x^2)^(3/2)*(c + d*x^2)^(1/2), x, 7, -((2*(b*c - 3*a*d)*x*Sqrt[a + b*x^2]*Sqrt[c + d*x^2])/(15*d)) + (b*x*Sqrt[a + b*x^2]*(c + d*x^2)^(3/2))/(5*d) + (Sqrt[c]*(2*b^2*c^2 - 7*a*b*c*d - 3*a^2*d^2)*Sqrt[a + b*x^2]*Sqrt[(c + d*x^2)/c]*EllipticE[ArcSin[(Sqrt[-d]*x)/Sqrt[c]], (b*c)/(a*d)])/(15*b*(-d)^(3/2)*Sqrt[(a + b*x^2)/a]*Sqrt[c + d*x^2]) - (a*Sqrt[c]*(b*c - a*d)*(b*c + 3*a*d)*Sqrt[(a + b*x^2)/a]*Sqrt[(c + d*x^2)/c]*EllipticF[ArcSin[(Sqrt[-d]*x)/Sqrt[c]], (b*c)/(a*d)])/(15*b*(-d)^(3/2)*Sqrt[a + b*x^2]*Sqrt[c + d*x^2])}
{(a + b*x^2)^(1/2)*(c + d*x^2)^(1/2), x, 6, (1/3)*x*Sqrt[a + b*x^2]*Sqrt[c + d*x^2] + (Sqrt[c]*(b*c + a*d)*Sqrt[a + b*x^2]*Sqrt[(c + d*x^2)/c]*EllipticE[ArcSin[(Sqrt[-d]*x)/Sqrt[c]], (b*c)/(a*d)])/(3*b*Sqrt[-d]*Sqrt[(a + b*x^2)/a]*Sqrt[c + d*x^2]) + (a*Sqrt[c]*(b*c - a*d)*Sqrt[(a + b*x^2)/a]*Sqrt[(c + d*x^2)/c]*EllipticF[ArcSin[(Sqrt[-d]*x)/Sqrt[c]], (b*c)/(a*d)])/(3*b*Sqrt[-d]*Sqrt[a + b*x^2]*Sqrt[c + d*x^2])}
{1/(a + b*x^2)^(1/2)*(c + d*x^2)^(1/2), x, 2, (Sqrt[a]*Sqrt[(a + b*x^2)/a]*Sqrt[c + d*x^2]*EllipticE[ArcSin[(Sqrt[-b]*x)/Sqrt[a]], (a*d)/(b*c)])/(Sqrt[-b]*Sqrt[a + b*x^2]*Sqrt[(c + d*x^2)/c])}
{1/(a + b*x^2)^(3/2)*(c + d*x^2)^(1/2), x, 7, (x*Sqrt[c + d*x^2])/(a*Sqrt[a + b*x^2]) + (Sqrt[c]*Sqrt[-d]*Sqrt[a + b*x^2]*Sqrt[(c + d*x^2)/c]*EllipticE[ArcSin[(Sqrt[-d]*x)/Sqrt[c]], (b*c)/(a*d)])/(a*b*Sqrt[(a + b*x^2)/a]*Sqrt[c + d*x^2]) - (Sqrt[c]*Sqrt[-d]*Sqrt[(a + b*x^2)/a]*Sqrt[(c + d*x^2)/c]*EllipticF[ArcSin[(Sqrt[-d]*x)/Sqrt[c]], (b*c)/(a*d)])/(b*Sqrt[a + b*x^2]*Sqrt[c + d*x^2])}
{1/(a + b*x^2)^(5/2)*(c + d*x^2)^(1/2), x, 7, (x*Sqrt[c + d*x^2])/(3*a*(a + b*x^2)^(3/2)) + ((2*b*c - a*d)*x*Sqrt[c + d*x^2])/(3*a^2*(b*c - a*d)*Sqrt[a + b*x^2]) + (Sqrt[c]*Sqrt[-d]*(2*b*c - a*d)*Sqrt[a + b*x^2]*Sqrt[(c + d*x^2)/c]*EllipticE[ArcSin[(Sqrt[-d]*x)/Sqrt[c]], (b*c)/(a*d)])/(3*a^2*b*(b*c - a*d)*Sqrt[(a + b*x^2)/a]*Sqrt[c + d*x^2]) - (Sqrt[c]*Sqrt[-d]*Sqrt[(a + b*x^2)/a]*Sqrt[(c + d*x^2)/c]*EllipticF[ArcSin[(Sqrt[-d]*x)/Sqrt[c]], (b*c)/(a*d)])/(3*a*b*Sqrt[a + b*x^2]*Sqrt[c + d*x^2])}
{1/(a + b*x^2)^(7/2)*(c + d*x^2)^(1/2), x, 8, (x*Sqrt[c + d*x^2])/(5*a*(a + b*x^2)^(5/2)) + ((4*b*c - 3*a*d)*x*Sqrt[c + d*x^2])/(15*a^2*(b*c - a*d)*(a + b*x^2)^(3/2)) + ((8*b^2*c^2 - 13*a*b*c*d + 3*a^2*d^2)*x*Sqrt[c + d*x^2])/(15*a^3*(b*c - a*d)^2*Sqrt[a + b*x^2]) + (Sqrt[c]*Sqrt[-d]*(8*b^2*c^2 - 13*a*b*c*d + 3*a^2*d^2)*Sqrt[a + b*x^2]*Sqrt[(c + d*x^2)/c]*EllipticE[ArcSin[(Sqrt[-d]*x)/Sqrt[c]], (b*c)/(a*d)])/(15*a^3*b*(b*c - a*d)^2*Sqrt[(a + b*x^2)/a]*Sqrt[c + d*x^2]) - (Sqrt[c]*Sqrt[-d]*(4*b*c - 3*a*d)*Sqrt[(a + b*x^2)/a]*Sqrt[(c + d*x^2)/c]*EllipticF[ArcSin[(Sqrt[-d]*x)/Sqrt[c]], (b*c)/(a*d)])/(15*a^2*b*(b*c - a*d)*Sqrt[a + b*x^2]*Sqrt[c + d*x^2])}


{(a + b*x^2)^(3/2)*(c + d*x^2)^(3/2), x, 8, (1/35)*(9*a*c + (b*c^2)/d - (2*a^2*d)/b)*x*Sqrt[a + b*x^2]*Sqrt[c + d*x^2] + (2*(4*b*c - a*d)*x*(a + b*x^2)^(3/2)*Sqrt[c + d*x^2])/(35*b) + (d*x*(a + b*x^2)^(5/2)*Sqrt[c + d*x^2])/(7*b) + (2*Sqrt[c]*(b*c + a*d)*(b^2*c^2 - 6*a*b*c*d + a^2*d^2)*Sqrt[a + b*x^2]*Sqrt[(c + d*x^2)/c]*EllipticE[ArcSin[(Sqrt[-d]*x)/Sqrt[c]], (b*c)/(a*d)])/(35*b^2*(-d)^(3/2)*Sqrt[(a + b*x^2)/a]*Sqrt[c + d*x^2]) - (a*Sqrt[c]*(b*c - a*d)*(b^2*c^2 + 9*a*b*c*d - 2*a^2*d^2)*Sqrt[(a + b*x^2)/a]*Sqrt[(c + d*x^2)/c]*EllipticF[ArcSin[(Sqrt[-d]*x)/Sqrt[c]], (b*c)/(a*d)])/(35*b^2*(-d)^(3/2)*Sqrt[a + b*x^2]*Sqrt[c + d*x^2])}
{(a + b*x^2)^(1/2)*(c + d*x^2)^(3/2), x, 7, (2*(3*b*c - a*d)*x*Sqrt[a + b*x^2]*Sqrt[c + d*x^2])/(15*b) + (d*x*(a + b*x^2)^(3/2)*Sqrt[c + d*x^2])/(5*b) + (Sqrt[c]*(3*b^2*c^2 + 7*a*b*c*d - 2*a^2*d^2)*Sqrt[a + b*x^2]*Sqrt[(c + d*x^2)/c]*EllipticE[ArcSin[(Sqrt[-d]*x)/Sqrt[c]], (b*c)/(a*d)])/(15*b^2*Sqrt[-d]*Sqrt[(a + b*x^2)/a]*Sqrt[c + d*x^2]) + (2*a*Sqrt[c]*(b*c - a*d)*(3*b*c - a*d)*Sqrt[(a + b*x^2)/a]*Sqrt[(c + d*x^2)/c]*EllipticF[ArcSin[(Sqrt[-d]*x)/Sqrt[c]], (b*c)/(a*d)])/(15*b^2*Sqrt[-d]*Sqrt[a + b*x^2]*Sqrt[c + d*x^2])}
{1/(a + b*x^2)^(1/2)*(c + d*x^2)^(3/2), x, 6, (d*x*Sqrt[a + b*x^2]*Sqrt[c + d*x^2])/(3*b) - (2*Sqrt[c]*Sqrt[-d]*(2*b*c - a*d)*Sqrt[a + b*x^2]*Sqrt[(c + d*x^2)/c]*EllipticE[ArcSin[(Sqrt[-d]*x)/Sqrt[c]], (b*c)/(a*d)])/(3*b^2*Sqrt[(a + b*x^2)/a]*Sqrt[c + d*x^2]) + (Sqrt[c]*(3*b*c - 2*a*d)*(b*c - a*d)*Sqrt[(a + b*x^2)/a]*Sqrt[(c + d*x^2)/c]*EllipticF[ArcSin[(Sqrt[-d]*x)/Sqrt[c]], (b*c)/(a*d)])/(3*b^2*Sqrt[-d]*Sqrt[a + b*x^2]*Sqrt[c + d*x^2])}
{1/(a + b*x^2)^(3/2)*(c + d*x^2)^(3/2), x, 6, ((b*c - a*d)*x*Sqrt[c + d*x^2])/(a*b*Sqrt[a + b*x^2]) + (Sqrt[c]*Sqrt[-d]*(b*c - 2*a*d)*Sqrt[a + b*x^2]*Sqrt[(c + d*x^2)/c]*EllipticE[ArcSin[(Sqrt[-d]*x)/Sqrt[c]], (b*c)/(a*d)])/(a*b^2*Sqrt[(a + b*x^2)/a]*Sqrt[c + d*x^2]) - (2*Sqrt[c]*Sqrt[-d]*(b*c - a*d)*Sqrt[(a + b*x^2)/a]*Sqrt[(c + d*x^2)/c]*EllipticF[ArcSin[(Sqrt[-d]*x)/Sqrt[c]], (b*c)/(a*d)])/(b^2*Sqrt[a + b*x^2]*Sqrt[c + d*x^2])}
{1/(a + b*x^2)^(5/2)*(c + d*x^2)^(3/2), x, 7, ((b*c - a*d)*x*Sqrt[c + d*x^2])/(3*a*b*(a + b*x^2)^(3/2)) + (2*(b*c + a*d)*x*Sqrt[c + d*x^2])/(3*a^2*b*Sqrt[a + b*x^2]) + (2*Sqrt[c]*Sqrt[-d]*(b*c + a*d)*Sqrt[a + b*x^2]*Sqrt[(c + d*x^2)/c]*EllipticE[ArcSin[(Sqrt[-d]*x)/Sqrt[c]], (b*c)/(a*d)])/(3*a^2*b^2*Sqrt[(a + b*x^2)/a]*Sqrt[c + d*x^2]) - (Sqrt[c]*Sqrt[-d]*(b*c + 2*a*d)*Sqrt[(a + b*x^2)/a]*Sqrt[(c + d*x^2)/c]*EllipticF[ArcSin[(Sqrt[-d]*x)/Sqrt[c]], (b*c)/(a*d)])/(3*a*b^2*Sqrt[a + b*x^2]*Sqrt[c + d*x^2])}
{1/(a + b*x^2)^(7/2)*(c + d*x^2)^(3/2), x, 8, ((b*c - a*d)*x*Sqrt[c + d*x^2])/(5*a*b*(a + b*x^2)^(5/2)) + (2*(2*b*c + a*d)*x*Sqrt[c + d*x^2])/(15*a^2*b*(a + b*x^2)^(3/2)) + ((8*b^2*c^2 - 3*a*b*c*d - 2*a^2*d^2)*x*Sqrt[c + d*x^2])/(15*a^3*b*(b*c - a*d)*Sqrt[a + b*x^2]) + (Sqrt[c]*Sqrt[-d]*(8*b^2*c^2 - 3*a*b*c*d - 2*a^2*d^2)*Sqrt[a + b*x^2]*Sqrt[(c + d*x^2)/c]*EllipticE[ArcSin[(Sqrt[-d]*x)/Sqrt[c]], (b*c)/(a*d)])/(15*a^3*b^2*(b*c - a*d)*Sqrt[(a + b*x^2)/a]*Sqrt[c + d*x^2]) - (2*Sqrt[c]*Sqrt[-d]*(2*b*c + a*d)*Sqrt[(a + b*x^2)/a]*Sqrt[(c + d*x^2)/c]*EllipticF[ArcSin[(Sqrt[-d]*x)/Sqrt[c]], (b*c)/(a*d)])/(15*a^2*b^2*Sqrt[a + b*x^2]*Sqrt[c + d*x^2])}


{Sqrt[2 + b*x^2]*Sqrt[3 + d*x^2], x, 4, (1/3)*x*Sqrt[2 + b*x^2]*Sqrt[3 + d*x^2] + (Sqrt[2]*(3*b + 2*d)*EllipticE[ArcSin[(Sqrt[-d]*x)/Sqrt[3]], (3*b)/(2*d)])/(3*b*Sqrt[-d]) + (Sqrt[2]*(3*b - 2*d)*EllipticF[ArcSin[(Sqrt[-d]*x)/Sqrt[3]], (3*b)/(2*d)])/(3*b*Sqrt[-d])}
{Sqrt[a + b*x^2]*Sqrt[c + d*x^2], x, 6, (1/3)*x*Sqrt[a + b*x^2]*Sqrt[c + d*x^2] + (Sqrt[c]*(b*c + a*d)*Sqrt[a + b*x^2]*Sqrt[(c + d*x^2)/c]*EllipticE[ArcSin[(Sqrt[-d]*x)/Sqrt[c]], (b*c)/(a*d)])/(3*b*Sqrt[-d]*Sqrt[(a + b*x^2)/a]*Sqrt[c + d*x^2]) + (a*Sqrt[c]*(b*c - a*d)*Sqrt[(a + b*x^2)/a]*Sqrt[(c + d*x^2)/c]*EllipticF[ArcSin[(Sqrt[-d]*x)/Sqrt[c]], (b*c)/(a*d)])/(3*b*Sqrt[-d]*Sqrt[a + b*x^2]*Sqrt[c + d*x^2])}
{Sqrt[2 + 4*x^2]*Sqrt[3 - 6*x^2], x, 3, Sqrt[2/3]*x*Sqrt[1 - 2*x^2]*Sqrt[1 + 2*x^2] + (2*EllipticF[ArcSin[Sqrt[2]*x], -1])/Sqrt[3]}
{Sqrt[2 + 4*x^2]*Sqrt[3 + 6*x^2], x, 2, Sqrt[6]*x + 2*Sqrt[2/3]*x^3}


(* ::Subsubsection::Closed:: *)
(*p<0*)


{(a + b*x^2)^(7/2)/(c + d*x^2)^(1/2), x, 8, (b*(24*b^2*c^2 - 71*a*b*c*d + 71*a^2*d^2)*x*Sqrt[a + b*x^2]*Sqrt[c + d*x^2])/(105*d^3) - (6*b*(b*c - 2*a*d)*x*(a + b*x^2)^(3/2)*Sqrt[c + d*x^2])/(35*d^2) + (b*x*(a + b*x^2)^(5/2)*Sqrt[c + d*x^2])/(7*d) + (8*Sqrt[c]*(b*c - 2*a*d)*(6*b^2*c^2 - 11*a*b*c*d + 11*a^2*d^2)*Sqrt[a + b*x^2]*Sqrt[(c + d*x^2)/c]*EllipticE[ArcSin[(Sqrt[-d]*x)/Sqrt[c]], (b*c)/(a*d)])/(105*(-d)^(7/2)*Sqrt[(a + b*x^2)/a]*Sqrt[c + d*x^2]) - (a*Sqrt[c]*(b*c - a*d)*(24*b^2*c^2 - 71*a*b*c*d + 71*a^2*d^2)*Sqrt[(a + b*x^2)/a]*Sqrt[(c + d*x^2)/c]*EllipticF[ArcSin[(Sqrt[-d]*x)/Sqrt[c]], (b*c)/(a*d)])/(105*(-d)^(7/2)*Sqrt[a + b*x^2]*Sqrt[c + d*x^2])}
{(a + b*x^2)^(5/2)/(c + d*x^2)^(1/2), x, 7, -((4*b*(b*c - 2*a*d)*x*Sqrt[a + b*x^2]*Sqrt[c + d*x^2])/(15*d^2)) + (b*x*(a + b*x^2)^(3/2)*Sqrt[c + d*x^2])/(5*d) + (Sqrt[c]*(8*b^2*c^2 - 23*a*b*c*d + 23*a^2*d^2)*Sqrt[a + b*x^2]*Sqrt[(c + d*x^2)/c]*EllipticE[ArcSin[(Sqrt[-d]*x)/Sqrt[c]], (b*c)/(a*d)])/(15*(-d)^(5/2)*Sqrt[(a + b*x^2)/a]*Sqrt[c + d*x^2]) - (4*a*Sqrt[c]*(b*c - 2*a*d)*(b*c - a*d)*Sqrt[(a + b*x^2)/a]*Sqrt[(c + d*x^2)/c]*EllipticF[ArcSin[(Sqrt[-d]*x)/Sqrt[c]], (b*c)/(a*d)])/(15*(-d)^(5/2)*Sqrt[a + b*x^2]*Sqrt[c + d*x^2])}
{(a + b*x^2)^(3/2)/(c + d*x^2)^(1/2), x, 6, (b*x*Sqrt[a + b*x^2]*Sqrt[c + d*x^2])/(3*d) + (2*Sqrt[c]*(b*c - 2*a*d)*Sqrt[a + b*x^2]*Sqrt[(c + d*x^2)/c]*EllipticE[ArcSin[(Sqrt[-d]*x)/Sqrt[c]], (b*c)/(a*d)])/(3*(-d)^(3/2)*Sqrt[(a + b*x^2)/a]*Sqrt[c + d*x^2]) - (a*Sqrt[c]*(b*c - a*d)*Sqrt[(a + b*x^2)/a]*Sqrt[(c + d*x^2)/c]*EllipticF[ArcSin[(Sqrt[-d]*x)/Sqrt[c]], (b*c)/(a*d)])/(3*(-d)^(3/2)*Sqrt[a + b*x^2]*Sqrt[c + d*x^2])}
{(a + b*x^2)^(1/2)/(c + d*x^2)^(1/2), x, 2, (Sqrt[c]*Sqrt[a + b*x^2]*Sqrt[(c + d*x^2)/c]*EllipticE[ArcSin[(Sqrt[-d]*x)/Sqrt[c]], (b*c)/(a*d)])/(Sqrt[-d]*Sqrt[(a + b*x^2)/a]*Sqrt[c + d*x^2])}
{1/((a + b*x^2)^(1/2)*(c + d*x^2)^(1/2)), x, 2, (Sqrt[c]*Sqrt[(a + b*x^2)/a]*Sqrt[(c + d*x^2)/c]*EllipticF[ArcSin[(Sqrt[-d]*x)/Sqrt[c]], (b*c)/(a*d)])/(Sqrt[-d]*Sqrt[a + b*x^2]*Sqrt[c + d*x^2])}
{1/((a + b*x^2)^(3/2)*(c + d*x^2)^(1/2)), x, 4, (b*x*Sqrt[c + d*x^2])/(a*(b*c - a*d)*Sqrt[a + b*x^2]) + (Sqrt[c]*Sqrt[-d]*Sqrt[a + b*x^2]*Sqrt[(c + d*x^2)/c]*EllipticE[ArcSin[(Sqrt[-d]*x)/Sqrt[c]], (b*c)/(a*d)])/(a*(b*c - a*d)*Sqrt[(a + b*x^2)/a]*Sqrt[c + d*x^2])}
{1/((a + b*x^2)^(5/2)*(c + d*x^2)^(1/2)), x, 7, (b*x*Sqrt[c + d*x^2])/(3*a*(b*c - a*d)*(a + b*x^2)^(3/2)) + (2*b*(b*c - 2*a*d)*x*Sqrt[c + d*x^2])/(3*a^2*(b*c - a*d)^2*Sqrt[a + b*x^2]) + (2*Sqrt[c]*Sqrt[-d]*(b*c - 2*a*d)*Sqrt[a + b*x^2]*Sqrt[(c + d*x^2)/c]*EllipticE[ArcSin[(Sqrt[-d]*x)/Sqrt[c]], (b*c)/(a*d)])/(3*a^2*(b*c - a*d)^2*Sqrt[(a + b*x^2)/a]*Sqrt[c + d*x^2]) - (Sqrt[c]*Sqrt[-d]*Sqrt[(a + b*x^2)/a]*Sqrt[(c + d*x^2)/c]*EllipticF[ArcSin[(Sqrt[-d]*x)/Sqrt[c]], (b*c)/(a*d)])/(3*a*(b*c - a*d)*Sqrt[a + b*x^2]*Sqrt[c + d*x^2])}
{1/((a + b*x^2)^(7/2)*(c + d*x^2)^(1/2)), x, 8, (b*x*Sqrt[c + d*x^2])/(5*a*(b*c - a*d)*(a + b*x^2)^(5/2)) + (4*b*(b*c - 2*a*d)*x*Sqrt[c + d*x^2])/(15*a^2*(b*c - a*d)^2*(a + b*x^2)^(3/2)) + (b*(8*b^2*c^2 - 23*a*b*c*d + 23*a^2*d^2)*x*Sqrt[c + d*x^2])/(15*a^3*(b*c - a*d)^3*Sqrt[a + b*x^2]) + (Sqrt[c]*Sqrt[-d]*(8*b^2*c^2 - 23*a*b*c*d + 23*a^2*d^2)*Sqrt[a + b*x^2]*Sqrt[(c + d*x^2)/c]*EllipticE[ArcSin[(Sqrt[-d]*x)/Sqrt[c]], (b*c)/(a*d)])/(15*a^3*(b*c - a*d)^3*Sqrt[(a + b*x^2)/a]*Sqrt[c + d*x^2]) - (4*Sqrt[c]*Sqrt[-d]*(b*c - 2*a*d)*Sqrt[(a + b*x^2)/a]*Sqrt[(c + d*x^2)/c]*EllipticF[ArcSin[(Sqrt[-d]*x)/Sqrt[c]], (b*c)/(a*d)])/(15*a^2*(b*c - a*d)^2*Sqrt[a + b*x^2]*Sqrt[c + d*x^2])}


{(a + b*x^2)^(7/2)/(c + d*x^2)^(3/2), x, 8, -(((b*c - a*d)*x*(a + b*x^2)^(5/2))/(c*d*Sqrt[c + d*x^2])) - (b*(24*b^2*c^2 - 43*a*b*c*d + 15*a^2*d^2)*x*Sqrt[a + b*x^2]*Sqrt[c + d*x^2])/(15*c*d^3) + (b*(6*b*c - 5*a*d)*x*(a + b*x^2)^(3/2)*Sqrt[c + d*x^2])/(5*c*d^2) - ((48*b^3*c^3 - 128*a*b^2*c^2*d + 103*a^2*b*c*d^2 - 15*a^3*d^3)*Sqrt[a + b*x^2]*Sqrt[(c + d*x^2)/c]*EllipticE[ArcSin[(Sqrt[-d]*x)/Sqrt[c]], (b*c)/(a*d)])/(15*Sqrt[c]*(-d)^(7/2)*Sqrt[(a + b*x^2)/a]*Sqrt[c + d*x^2]) + (a*(b*c - a*d)*(24*b^2*c^2 - 43*a*b*c*d + 15*a^2*d^2)*Sqrt[(a + b*x^2)/a]*Sqrt[(c + d*x^2)/c]*EllipticF[ArcSin[(Sqrt[-d]*x)/Sqrt[c]], (b*c)/(a*d)])/(15*Sqrt[c]*(-d)^(7/2)*Sqrt[a + b*x^2]*Sqrt[c + d*x^2])}
{(a + b*x^2)^(5/2)/(c + d*x^2)^(3/2), x, 7, -(((b*c - a*d)*x*(a + b*x^2)^(3/2))/(c*d*Sqrt[c + d*x^2])) + (b*(4*b*c - 3*a*d)*x*Sqrt[a + b*x^2]*Sqrt[c + d*x^2])/(3*c*d^2) - ((8*b^2*c^2 - 13*a*b*c*d + 3*a^2*d^2)*Sqrt[a + b*x^2]*Sqrt[(c + d*x^2)/c]*EllipticE[ArcSin[(Sqrt[-d]*x)/Sqrt[c]], (b*c)/(a*d)])/(3*Sqrt[c]*(-d)^(5/2)*Sqrt[(a + b*x^2)/a]*Sqrt[c + d*x^2]) + (a*(4*b*c - 3*a*d)*(b*c - a*d)*Sqrt[(a + b*x^2)/a]*Sqrt[(c + d*x^2)/c]*EllipticF[ArcSin[(Sqrt[-d]*x)/Sqrt[c]], (b*c)/(a*d)])/(3*Sqrt[c]*(-d)^(5/2)*Sqrt[a + b*x^2]*Sqrt[c + d*x^2])}
{(a + b*x^2)^(3/2)/(c + d*x^2)^(3/2), x, 6, -(((b*c - a*d)*x*Sqrt[a + b*x^2])/(c*d*Sqrt[c + d*x^2])) - ((2*b*c - a*d)*Sqrt[a + b*x^2]*Sqrt[(c + d*x^2)/c]*EllipticE[ArcSin[(Sqrt[-d]*x)/Sqrt[c]], (b*c)/(a*d)])/(Sqrt[c]*(-d)^(3/2)*Sqrt[(a + b*x^2)/a]*Sqrt[c + d*x^2]) + (a*(b*c - a*d)*Sqrt[(a + b*x^2)/a]*Sqrt[(c + d*x^2)/c]*EllipticF[ArcSin[(Sqrt[-d]*x)/Sqrt[c]], (b*c)/(a*d)])/(Sqrt[c]*(-d)^(3/2)*Sqrt[a + b*x^2]*Sqrt[c + d*x^2])}
{(a + b*x^2)^(1/2)/(c + d*x^2)^(3/2), x, 7, (x*Sqrt[a + b*x^2])/(c*Sqrt[c + d*x^2]) - (Sqrt[a + b*x^2]*Sqrt[(c + d*x^2)/c]*EllipticE[ArcSin[(Sqrt[-d]*x)/Sqrt[c]], (b*c)/(a*d)])/(Sqrt[c]*Sqrt[-d]*Sqrt[(a + b*x^2)/a]*Sqrt[c + d*x^2]) + (a*Sqrt[(a + b*x^2)/a]*Sqrt[(c + d*x^2)/c]*EllipticF[ArcSin[(Sqrt[-d]*x)/Sqrt[c]], (b*c)/(a*d)])/(Sqrt[c]*Sqrt[-d]*Sqrt[a + b*x^2]*Sqrt[c + d*x^2])}
{1/((a + b*x^2)^(1/2)*(c + d*x^2)^(3/2)), x, 4, -((d*x*Sqrt[a + b*x^2])/(c*(b*c - a*d)*Sqrt[c + d*x^2])) - (Sqrt[a]*Sqrt[-b]*Sqrt[(a + b*x^2)/a]*Sqrt[c + d*x^2]*EllipticE[ArcSin[(Sqrt[-b]*x)/Sqrt[a]], (a*d)/(b*c)])/(c*(b*c - a*d)*Sqrt[a + b*x^2]*Sqrt[(c + d*x^2)/c])}
{1/((a + b*x^2)^(3/2)*(c + d*x^2)^(3/2)), x, 7, (b*x)/(a*(b*c - a*d)*Sqrt[a + b*x^2]*Sqrt[c + d*x^2]) + (d*(b*c + a*d)*x*Sqrt[a + b*x^2])/(a*c*(b*c - a*d)^2*Sqrt[c + d*x^2]) + (Sqrt[-d]*(b*c + a*d)*Sqrt[a + b*x^2]*Sqrt[(c + d*x^2)/c]*EllipticE[ArcSin[(Sqrt[-d]*x)/Sqrt[c]], (b*c)/(a*d)])/(a*Sqrt[c]*(b*c - a*d)^2*Sqrt[(a + b*x^2)/a]*Sqrt[c + d*x^2]) + (Sqrt[-d]*Sqrt[(a + b*x^2)/a]*Sqrt[(c + d*x^2)/c]*EllipticF[ArcSin[(Sqrt[-d]*x)/Sqrt[c]], (b*c)/(a*d)])/(Sqrt[c]*(b*c - a*d)*Sqrt[a + b*x^2]*Sqrt[c + d*x^2])}
{1/((a + b*x^2)^(5/2)*(c + d*x^2)^(3/2)), x, 8, (b*x)/(3*a*(b*c - a*d)*(a + b*x^2)^(3/2)*Sqrt[c + d*x^2]) + (2*b*(b*c - 3*a*d)*x)/(3*a^2*(b*c - a*d)^2*Sqrt[a + b*x^2]*Sqrt[c + d*x^2]) + (d*(2*b^2*c^2 - 7*a*b*c*d - 3*a^2*d^2)*x*Sqrt[a + b*x^2])/(3*a^2*c*(b*c - a*d)^3*Sqrt[c + d*x^2]) + (Sqrt[-d]*(2*b^2*c^2 - 7*a*b*c*d - 3*a^2*d^2)*Sqrt[a + b*x^2]*Sqrt[(c + d*x^2)/c]*EllipticE[ArcSin[(Sqrt[-d]*x)/Sqrt[c]], (b*c)/(a*d)])/(3*a^2*Sqrt[c]*(b*c - a*d)^3*Sqrt[(a + b*x^2)/a]*Sqrt[c + d*x^2]) - (Sqrt[-d]*(b*c + 3*a*d)*Sqrt[(a + b*x^2)/a]*Sqrt[(c + d*x^2)/c]*EllipticF[ArcSin[(Sqrt[-d]*x)/Sqrt[c]], (b*c)/(a*d)])/(3*a*Sqrt[c]*(b*c - a*d)^2*Sqrt[a + b*x^2]*Sqrt[c + d*x^2])}


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

{1/(Sqrt[1 - x^2]*Sqrt[-1 + 2*x^2]), x, 2, -EllipticF[ArcCos[x], 2], (Sqrt[1 - 2*x^2]*EllipticF[ArcSin[x], 2])/Sqrt[-1 + 2*x^2]}


{Sqrt[2 + b*x^2]/Sqrt[3 + d*x^2], x, 1, (Sqrt[2]*EllipticE[ArcSin[(Sqrt[-d]*x)/Sqrt[3]], (3*b)/(2*d)])/Sqrt[-d]}
{Sqrt[a + b*x^2]/Sqrt[c + d*x^2], x, 2, (Sqrt[c]*Sqrt[a + b*x^2]*Sqrt[(c + d*x^2)/c]*EllipticE[ArcSin[(Sqrt[-d]*x)/Sqrt[c]], (b*c)/(a*d)])/(Sqrt[-d]*Sqrt[(a + b*x^2)/a]*Sqrt[c + d*x^2])}
{Sqrt[-1 + 3*x^2]/Sqrt[2 - 3*x^2], x, 2, (Sqrt[-1 + 3*x^2]*EllipticE[ArcSin[Sqrt[3/2]*x], 2])/(Sqrt[3]*Sqrt[1 - 3*x^2])}


{Sqrt[1 + (2*c*x^2)/(b - Sqrt[b^2 - 4*a*c])]/Sqrt[1 + (2*c*x^2)/(b + Sqrt[b^2 - 4*a*c])], x, 1, (Sqrt[b + Sqrt[b^2 - 4*a*c]]*EllipticE[ArcSin[(Sqrt[2]*Sqrt[-c]*x)/Sqrt[b + Sqrt[b^2 - 4*a*c]]], (b + Sqrt[b^2 - 4*a*c])/(b - Sqrt[b^2 - 4*a*c])])/(Sqrt[2]*Sqrt[-c])}


(* ::Section:: *)
(*Integrands of the form (a+b x^3)^m (c+d x^3)^p*)


(* ::Subsection::Closed:: *)
(*Integrands of the form (a+b x^3)^m (c+d x^3)^p*)


(* ::Subsubsection::Closed:: *)
(*m>0*)


{(a + b*x^3)*(c + d*x^3)^4, x, 2, a*c^4*x + (1/4)*c^3*(b*c + 4*a*d)*x^4 + (2/7)*c^2*d*(2*b*c + 3*a*d)*x^7 + (1/5)*c*d^2*(3*b*c + 2*a*d)*x^10 + (1/13)*d^3*(4*b*c + a*d)*x^13 + (1/16)*b*d^4*x^16}
{(a + b*x^3)*(c + d*x^3)^3, x, 2, a*c^3*x + (1/4)*c^2*(b*c + 3*a*d)*x^4 + (3/7)*c*d*(b*c + a*d)*x^7 + (1/10)*d^2*(3*b*c + a*d)*x^10 + (1/13)*b*d^3*x^13}
{(a + b*x^3)*(c + d*x^3)^2, x, 2, a*c^2*x + (1/4)*c*(b*c + 2*a*d)*x^4 + (1/7)*d*(2*b*c + a*d)*x^7 + (1/10)*b*d^2*x^10}
{(a + b*x^3)*(c + d*x^3)^1, x, 2, a*c*x + (1/4)*(b*c + a*d)*x^4 + (1/7)*b*d*x^7}
{(a + b*x^3)/(c + d*x^3)^1, x, 6, (b*x)/d + ((b*c - a*d)*ArcTan[(c^(1/3) - 2*d^(1/3)*x)/(Sqrt[3]*c^(1/3))])/(Sqrt[3]*c^(2/3)*d^(4/3)) - ((b*c - a*d)*Log[c^(1/3) + d^(1/3)*x])/(3*c^(2/3)*d^(4/3)) + ((b*c - a*d)*Log[c^(2/3) - c^(1/3)*d^(1/3)*x + d^(2/3)*x^2])/(6*c^(2/3)*d^(4/3))}
{(a + b*x^3)/(c + d*x^3)^2, x, 6, -(((b*c - a*d)*x)/(3*c*d*(c + d*x^3))) - ((b*c + 2*a*d)*ArcTan[(c^(1/3) - 2*d^(1/3)*x)/(Sqrt[3]*c^(1/3))])/(3*Sqrt[3]*c^(5/3)*d^(4/3)) + ((b*c + 2*a*d)*Log[c^(1/3) + d^(1/3)*x])/(9*c^(5/3)*d^(4/3)) - ((b*c + 2*a*d)*Log[c^(2/3) - c^(1/3)*d^(1/3)*x + d^(2/3)*x^2])/(18*c^(5/3)*d^(4/3))}
{(a + b*x^3)/(c + d*x^3)^3, x, 7, -(((b*c - a*d)*x)/(6*c*d*(c + d*x^3)^2)) + ((b*c + 5*a*d)*x)/(18*c^2*d*(c + d*x^3)) - ((b*c + 5*a*d)*ArcTan[(c^(1/3) - 2*d^(1/3)*x)/(Sqrt[3]*c^(1/3))])/(9*Sqrt[3]*c^(8/3)*d^(4/3)) + ((b*c + 5*a*d)*Log[c^(1/3) + d^(1/3)*x])/(27*c^(8/3)*d^(4/3)) - ((b*c + 5*a*d)*Log[c^(2/3) - c^(1/3)*d^(1/3)*x + d^(2/3)*x^2])/(54*c^(8/3)*d^(4/3))}


{(a + b*x^3)^2*(c + d*x^3)^3, x, 2, a^2*c^3*x + (1/4)*a*c^2*(2*b*c + 3*a*d)*x^4 + (1/7)*c*(b^2*c^2 + 6*a*b*c*d + 3*a^2*d^2)*x^7 + (1/10)*d*(3*b^2*c^2 + 6*a*b*c*d + a^2*d^2)*x^10 + (1/13)*b*d^2*(3*b*c + 2*a*d)*x^13 + (1/16)*b^2*d^3*x^16}
{(a + b*x^3)^2*(c + d*x^3)^2, x, 2, a^2*c^2*x + (1/2)*a*c*(b*c + a*d)*x^4 + (1/7)*(b^2*c^2 + 4*a*b*c*d + a^2*d^2)*x^7 + (1/5)*b*d*(b*c + a*d)*x^10 + (1/13)*b^2*d^2*x^13}
{(a + b*x^3)^2*(c + d*x^3)^1, x, 2, a^2*c*x + (1/4)*a*(2*b*c + a*d)*x^4 + (1/7)*b*(b*c + 2*a*d)*x^7 + (1/10)*b^2*d*x^10}
{(a + b*x^3)^2/(c + d*x^3)^1, x, 7, -((b*(b*c - 2*a*d)*x)/d^2) + (b^2*x^4)/(4*d) - ((b*c - a*d)^2*ArcTan[(c^(1/3) - 2*d^(1/3)*x)/(Sqrt[3]*c^(1/3))])/(Sqrt[3]*c^(2/3)*d^(7/3)) + ((b*c - a*d)^2*Log[c^(1/3) + d^(1/3)*x])/(3*c^(2/3)*d^(7/3)) - ((b*c - a*d)^2*Log[c^(2/3) - c^(1/3)*d^(1/3)*x + d^(2/3)*x^2])/(6*c^(2/3)*d^(7/3))}
{(a + b*x^3)^2/(c + d*x^3)^2, x, 8, (b^2*x)/d^2 + ((b*c - a*d)^2*x)/(3*c*d^2*(c + d*x^3)) + (2*(b*c - a*d)*(2*b*c + a*d)*ArcTan[(c^(1/3) - 2*d^(1/3)*x)/(Sqrt[3]*c^(1/3))])/(3*Sqrt[3]*c^(5/3)*d^(7/3)) - (2*(b*c - a*d)*(2*b*c + a*d)*Log[c^(1/3) + d^(1/3)*x])/(9*c^(5/3)*d^(7/3)) + ((b*c - a*d)*(2*b*c + a*d)*Log[c^(2/3) - c^(1/3)*d^(1/3)*x + d^(2/3)*x^2])/(9*c^(5/3)*d^(7/3))}
{(a + b*x^3)^2/(c + d*x^3)^3, x, 7, -(((b*c - a*d)*x*(a + b*x^3))/(6*c*d*(c + d*x^3)^2)) - ((b*c - a*d)*(4*b*c + 5*a*d)*x)/(18*c^2*d^2*(c + d*x^3)) - ((2*b^2*c^2 + 2*a*b*c*d + 5*a^2*d^2)*ArcTan[(c^(1/3) - 2*d^(1/3)*x)/(Sqrt[3]*c^(1/3))])/(9*Sqrt[3]*c^(8/3)*d^(7/3)) + ((2*b^2*c^2 + 2*a*b*c*d + 5*a^2*d^2)*Log[c^(1/3) + d^(1/3)*x])/(27*c^(8/3)*d^(7/3)) - ((2*b^2*c^2 + 2*a*b*c*d + 5*a^2*d^2)*Log[c^(2/3) - c^(1/3)*d^(1/3)*x + d^(2/3)*x^2])/(54*c^(8/3)*d^(7/3))}


(* ::Subsubsection::Closed:: *)
(*m<0*)


{1/(a + b*x^3)*(c + d*x^3)^4, x, 7, (d*(2*b*c - a*d)*(2*b^2*c^2 - 2*a*b*c*d + a^2*d^2)*x)/b^4 + (d^2*(6*b^2*c^2 - 4*a*b*c*d + a^2*d^2)*x^4)/(4*b^3) + (d^3*(4*b*c - a*d)*x^7)/(7*b^2) + (d^4*x^10)/(10*b) - ((b*c - a*d)^4*ArcTan[(a^(1/3) - 2*b^(1/3)*x)/(Sqrt[3]*a^(1/3))])/(Sqrt[3]*a^(2/3)*b^(13/3)) + ((b*c - a*d)^4*Log[a^(1/3) + b^(1/3)*x])/(3*a^(2/3)*b^(13/3)) - ((b*c - a*d)^4*Log[a^(2/3) - a^(1/3)*b^(1/3)*x + b^(2/3)*x^2])/(6*a^(2/3)*b^(13/3))}
{1/(a + b*x^3)*(c + d*x^3)^3, x, 7, (d*(3*b^2*c^2 - 3*a*b*c*d + a^2*d^2)*x)/b^3 + (d^2*(3*b*c - a*d)*x^4)/(4*b^2) + (d^3*x^7)/(7*b) - ((b*c - a*d)^3*ArcTan[(a^(1/3) - 2*b^(1/3)*x)/(Sqrt[3]*a^(1/3))])/(Sqrt[3]*a^(2/3)*b^(10/3)) + ((b*c - a*d)^3*Log[a^(1/3) + b^(1/3)*x])/(3*a^(2/3)*b^(10/3)) - ((b*c - a*d)^3*Log[a^(2/3) - a^(1/3)*b^(1/3)*x + b^(2/3)*x^2])/(6*a^(2/3)*b^(10/3))}
{1/(a + b*x^3)*(c + d*x^3)^2, x, 7, (d*(2*b*c - a*d)*x)/b^2 + (d^2*x^4)/(4*b) - ((b*c - a*d)^2*ArcTan[(a^(1/3) - 2*b^(1/3)*x)/(Sqrt[3]*a^(1/3))])/(Sqrt[3]*a^(2/3)*b^(7/3)) + ((b*c - a*d)^2*Log[a^(1/3) + b^(1/3)*x])/(3*a^(2/3)*b^(7/3)) - ((b*c - a*d)^2*Log[a^(2/3) - a^(1/3)*b^(1/3)*x + b^(2/3)*x^2])/(6*a^(2/3)*b^(7/3))}
{1/(a + b*x^3)*(c + d*x^3)^1, x, 6, (d*x)/b - ((b*c - a*d)*ArcTan[(a^(1/3) - 2*b^(1/3)*x)/(Sqrt[3]*a^(1/3))])/(Sqrt[3]*a^(2/3)*b^(4/3)) + ((b*c - a*d)*Log[a^(1/3) + b^(1/3)*x])/(3*a^(2/3)*b^(4/3)) - ((b*c - a*d)*Log[a^(2/3) - a^(1/3)*b^(1/3)*x + b^(2/3)*x^2])/(6*a^(2/3)*b^(4/3))}
{1/(a + b*x^3)/(c + d*x^3)^1, x, 11, -((b^(2/3)*ArcTan[(a^(1/3) - 2*b^(1/3)*x)/(Sqrt[3]*a^(1/3))])/(Sqrt[3]*a^(2/3)*(b*c - a*d))) + (d^(2/3)*ArcTan[(c^(1/3) - 2*d^(1/3)*x)/(Sqrt[3]*c^(1/3))])/(Sqrt[3]*c^(2/3)*(b*c - a*d)) + (b^(2/3)*Log[a^(1/3) + b^(1/3)*x])/(3*a^(2/3)*(b*c - a*d)) - (d^(2/3)*Log[c^(1/3) + d^(1/3)*x])/(3*c^(2/3)*(b*c - a*d)) - (b^(2/3)*Log[a^(2/3) - a^(1/3)*b^(1/3)*x + b^(2/3)*x^2])/(6*a^(2/3)*(b*c - a*d)) + (d^(2/3)*Log[c^(2/3) - c^(1/3)*d^(1/3)*x + d^(2/3)*x^2])/(6*c^(2/3)*(b*c - a*d))}
{1/(a + b*x^3)/(c + d*x^3)^2, x, 12, -((d*x)/(3*c*(b*c - a*d)*(c + d*x^3))) - (b^(5/3)*ArcTan[(a^(1/3) - 2*b^(1/3)*x)/(Sqrt[3]*a^(1/3))])/(Sqrt[3]*a^(2/3)*(b*c - a*d)^2) + (d^(2/3)*(5*b*c - 2*a*d)*ArcTan[(c^(1/3) - 2*d^(1/3)*x)/(Sqrt[3]*c^(1/3))])/(3*Sqrt[3]*c^(5/3)*(b*c - a*d)^2) + (b^(5/3)*Log[a^(1/3) + b^(1/3)*x])/(3*a^(2/3)*(b*c - a*d)^2) - (d^(2/3)*(5*b*c - 2*a*d)*Log[c^(1/3) + d^(1/3)*x])/(9*c^(5/3)*(b*c - a*d)^2) - (b^(5/3)*Log[a^(2/3) - a^(1/3)*b^(1/3)*x + b^(2/3)*x^2])/(6*a^(2/3)*(b*c - a*d)^2) + (d^(2/3)*(5*b*c - 2*a*d)*Log[c^(2/3) - c^(1/3)*d^(1/3)*x + d^(2/3)*x^2])/(18*c^(5/3)*(b*c - a*d)^2)}


{1/(a + b*x^3)^2*(c + d*x^3)^5, x, 8, (d^2*(10*b^3*c^3 - 20*a*b^2*c^2*d + 15*a^2*b*c*d^2 - 4*a^3*d^3)*x)/b^5 + (d^3*(10*b^2*c^2 - 10*a*b*c*d + 3*a^2*d^2)*x^4)/(4*b^4) + (d^4*(5*b*c - 2*a*d)*x^7)/(7*b^3) + (d^5*x^10)/(10*b^2) + ((b*c - a*d)^5*x)/(3*a*b^5*(a + b*x^3)) - ((b*c - a*d)^4*(2*b*c + 13*a*d)*ArcTan[(a^(1/3) - 2*b^(1/3)*x)/(Sqrt[3]*a^(1/3))])/(3*Sqrt[3]*a^(5/3)*b^(16/3)) + ((b*c - a*d)^4*(2*b*c + 13*a*d)*Log[a^(1/3) + b^(1/3)*x])/(9*a^(5/3)*b^(16/3)) - ((b*c - a*d)^4*(2*b*c + 13*a*d)*Log[a^(2/3) - a^(1/3)*b^(1/3)*x + b^(2/3)*x^2])/(18*a^(5/3)*b^(16/3))}
{1/(a + b*x^3)^2*(c + d*x^3)^4, x, 8, (d^2*(6*b^2*c^2 - 8*a*b*c*d + 3*a^2*d^2)*x)/b^4 + (d^3*(2*b*c - a*d)*x^4)/(2*b^3) + (d^4*x^7)/(7*b^2) + ((b*c - a*d)^4*x)/(3*a*b^4*(a + b*x^3)) - (2*(b*c - a*d)^3*(b*c + 5*a*d)*ArcTan[(a^(1/3) - 2*b^(1/3)*x)/(Sqrt[3]*a^(1/3))])/(3*Sqrt[3]*a^(5/3)*b^(13/3)) + (2*(b*c - a*d)^3*(b*c + 5*a*d)*Log[a^(1/3) + b^(1/3)*x])/(9*a^(5/3)*b^(13/3)) - ((b*c - a*d)^3*(b*c + 5*a*d)*Log[a^(2/3) - a^(1/3)*b^(1/3)*x + b^(2/3)*x^2])/(9*a^(5/3)*b^(13/3))}
{1/(a + b*x^3)^2*(c + d*x^3)^3, x, 8, (d^2*(3*b*c - 2*a*d)*x)/b^3 + (d^3*x^4)/(4*b^2) + ((b*c - a*d)^3*x)/(3*a*b^3*(a + b*x^3)) - ((b*c - a*d)^2*(2*b*c + 7*a*d)*ArcTan[(a^(1/3) - 2*b^(1/3)*x)/(Sqrt[3]*a^(1/3))])/(3*Sqrt[3]*a^(5/3)*b^(10/3)) + ((b*c - a*d)^2*(2*b*c + 7*a*d)*Log[a^(1/3) + b^(1/3)*x])/(9*a^(5/3)*b^(10/3)) - ((b*c - a*d)^2*(2*b*c + 7*a*d)*Log[a^(2/3) - a^(1/3)*b^(1/3)*x + b^(2/3)*x^2])/(18*a^(5/3)*b^(10/3))}
{1/(a + b*x^3)^2*(c + d*x^3)^2, x, 8, (d^2*x)/b^2 + ((b*c - a*d)^2*x)/(3*a*b^2*(a + b*x^3)) - (2*(b*c - a*d)*(b*c + 2*a*d)*ArcTan[(a^(1/3) - 2*b^(1/3)*x)/(Sqrt[3]*a^(1/3))])/(3*Sqrt[3]*a^(5/3)*b^(7/3)) + (2*(b*c - a*d)*(b*c + 2*a*d)*Log[a^(1/3) + b^(1/3)*x])/(9*a^(5/3)*b^(7/3)) - ((b*c - a*d)*(b*c + 2*a*d)*Log[a^(2/3) - a^(1/3)*b^(1/3)*x + b^(2/3)*x^2])/(9*a^(5/3)*b^(7/3))}
{1/(a + b*x^3)^2*(c + d*x^3)^1, x, 6, ((b*c - a*d)*x)/(3*a*b*(a + b*x^3)) - ((2*b*c + a*d)*ArcTan[(a^(1/3) - 2*b^(1/3)*x)/(Sqrt[3]*a^(1/3))])/(3*Sqrt[3]*a^(5/3)*b^(4/3)) + ((2*b*c + a*d)*Log[a^(1/3) + b^(1/3)*x])/(9*a^(5/3)*b^(4/3)) - ((2*b*c + a*d)*Log[a^(2/3) - a^(1/3)*b^(1/3)*x + b^(2/3)*x^2])/(18*a^(5/3)*b^(4/3))}
{1/(a + b*x^3)^2/(c + d*x^3)^1, x, 12, (b*x)/(3*a*(b*c - a*d)*(a + b*x^3)) - (b^(2/3)*(2*b*c - 5*a*d)*ArcTan[(a^(1/3) - 2*b^(1/3)*x)/(Sqrt[3]*a^(1/3))])/(3*Sqrt[3]*a^(5/3)*(b*c - a*d)^2) - (d^(5/3)*ArcTan[(c^(1/3) - 2*d^(1/3)*x)/(Sqrt[3]*c^(1/3))])/(Sqrt[3]*c^(2/3)*(b*c - a*d)^2) + (b^(2/3)*(2*b*c - 5*a*d)*Log[a^(1/3) + b^(1/3)*x])/(9*a^(5/3)*(b*c - a*d)^2) + (d^(5/3)*Log[c^(1/3) + d^(1/3)*x])/(3*c^(2/3)*(b*c - a*d)^2) - (b^(2/3)*(2*b*c - 5*a*d)*Log[a^(2/3) - a^(1/3)*b^(1/3)*x + b^(2/3)*x^2])/(18*a^(5/3)*(b*c - a*d)^2) - (d^(5/3)*Log[c^(2/3) - c^(1/3)*d^(1/3)*x + d^(2/3)*x^2])/(6*c^(2/3)*(b*c - a*d)^2)}
{1/(a + b*x^3)^2/(c + d*x^3)^2, x, 13, (d*(b*c + a*d)*x)/(3*a*c*(b*c - a*d)^2*(c + d*x^3)) + (b*x)/(3*a*(b*c - a*d)*(a + b*x^3)*(c + d*x^3)) - (2*b^(5/3)*(b*c - 4*a*d)*ArcTan[(a^(1/3) - 2*b^(1/3)*x)/(Sqrt[3]*a^(1/3))])/(3*Sqrt[3]*a^(5/3)*(b*c - a*d)^3) - (2*d^(5/3)*(4*b*c - a*d)*ArcTan[(c^(1/3) - 2*d^(1/3)*x)/(Sqrt[3]*c^(1/3))])/(3*Sqrt[3]*c^(5/3)*(b*c - a*d)^3) + (2*b^(5/3)*(b*c - 4*a*d)*Log[a^(1/3) + b^(1/3)*x])/(9*a^(5/3)*(b*c - a*d)^3) + (2*d^(5/3)*(4*b*c - a*d)*Log[c^(1/3) + d^(1/3)*x])/(9*c^(5/3)*(b*c - a*d)^3) - (b^(5/3)*(b*c - 4*a*d)*Log[a^(2/3) - a^(1/3)*b^(1/3)*x + b^(2/3)*x^2])/(9*a^(5/3)*(b*c - a*d)^3) - (d^(5/3)*(4*b*c - a*d)*Log[c^(2/3) - c^(1/3)*d^(1/3)*x + d^(2/3)*x^2])/(9*c^(5/3)*(b*c - a*d)^3)}


(* ::Section:: *)
(*Integrands of the form (a+b x^n)^m (c+d x^n)^p*)


(* ::Subsection::Closed:: *)
(*Integrands of the form (a+b/x^n)^m (c+d/x^n)^p*)


{(a + b/x^2)/(c + d/x^2), x, 2, (a*x)/c + ((b*c - a*d)*ArcTan[(Sqrt[c]*x)/Sqrt[d]])/(c^(3/2)*Sqrt[d])}
{(a + b/x^3)/(c + d/x^3), x, 6, (a*x)/c - ((b*c - a*d)*ArcTan[(d^(1/3) - 2*c^(1/3)*x)/(Sqrt[3]*d^(1/3))])/(Sqrt[3]*c^(4/3)*d^(2/3)) + ((b*c - a*d)*Log[d^(1/3) + c^(1/3)*x])/(3*c^(4/3)*d^(2/3)) - ((b*c - a*d)*Log[d^(2/3) - c^(1/3)*d^(1/3)*x + c^(2/3)*x^2])/(6*c^(4/3)*d^(2/3))}


{(a + b*Sqrt[x])/(c + d*Sqrt[x]), x, 3, -((2*(b*c - a*d)*Sqrt[x])/d^2) + (b*x)/d + (2*c*(b*c - a*d)*Log[c + d*Sqrt[x]])/d^3}
{(-1 + x^(1/3))/(1 + x^(1/3)), x, 4, 6*x^(1/3) - 3*x^(2/3) + x - 6*Log[1 + x^(1/3)]}
{(1 + x^(-1/3))/(-1 + x^(-1/3)), x, 4, -6*x^(1/3) - 3*x^(2/3) - x - 6*Log[1 - x^(1/3)]}
{(1 + x^(2/3))/(-1 + x^(2/3)), x, 4, 6*x^(1/3) + x - 6*ArcTanh[x^(1/3)]}
{(-16 + x^(3/4))/(16 + x^(3/4)), x, 8, -128*x^(1/4) + x - (256*2^(1/3)*ArcTan[(2^(1/3) - x^(1/4))/(2^(1/3)*Sqrt[3])])/Sqrt[3] + (256/3)*2^(1/3)*Log[2*2^(1/3) + x^(1/4)] - (128/3)*2^(1/3)*Log[4*2^(2/3) - 2*2^(1/3)*x^(1/4) + Sqrt[x]]}


(* ::Title:: *)
(*Integration problems of the form (A+B x^n) (a+b x^n)^m (c+d x^n)^p*)
