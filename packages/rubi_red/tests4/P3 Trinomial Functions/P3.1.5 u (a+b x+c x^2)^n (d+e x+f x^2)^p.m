(* ::Package:: *)

(* ::Title:: *)
(*Integrands of the form u (a+b x+c x^2)^n (d+e x+f x^2)^p*)


(* ::Section:: *)
(*Integrands of the form (a+b x+c x^2)^n (d+e x+f x^2)^p when e=0*)


(* ::Subsection::Closed:: *)
(*Integrands of the form (a+b x+c x^2)^n (d+f x^2)^p when b^2-4 a c=0*)


{Sqrt[1 + 2*x + x^2]/Sqrt[1 + x^2], x, 3, (Sqrt[1 + x^2]*Sqrt[1 + 2*x + x^2])/(1 + x) + (Sqrt[1 + 2*x + x^2]*ArcSinh[x])/(1 + x)}


(* ::Subsection::Closed:: *)
(*Integrands of the form (a+b x+c x^2)^n (d+f x^2)^p*)


(* ::Subsubsection::Closed:: *)
(*p>0*)


{(A + C*x^2)*(a + b*x + c*x^2)^4, x, 2, a^4*A*x + 2*a^3*A*b*x^2 + (1/3)*a^2*(6*A*b^2 + 4*a*A*c + a^2*C)*x^3 + a*b*(A*(b^2 + 3*a*c) + a^2*C)*x^4 + (1/5)*(A*(b^4 + 12*a*b^2*c + 6*a^2*c^2) + 2*a^2*(3*b^2 + 2*a*c)*C)*x^5 + (2/3)*b*(b^2 + 3*a*c)*(A*c + a*C)*x^6 + (1/7)*(2*A*c^2*(3*b^2 + 2*a*c) + (b^4 + 12*a*b^2*c + 6*a^2*c^2)*C)*x^7 + (1/2)*b*c*(A*c^2 + (b^2 + 3*a*c)*C)*x^8 + (1/9)*c^2*(A*c^2 + 6*b^2*C + 4*a*c*C)*x^9 + (2/5)*b*c^3*C*x^10 + (1/11)*c^4*C*x^11}
{(A + C*x^2)*(a + b*x + c*x^2)^3, x, 2, a^3*A*x + (3/2)*a^2*A*b*x^2 + (1/3)*a*(3*A*(b^2 + a*c) + a^2*C)*x^3 + (1/4)*b*(A*(b^2 + 6*a*c) + 3*a^2*C)*x^4 + (3/5)*(b^2 + a*c)*(A*c + a*C)*x^5 + (1/6)*b*(3*A*c^2 + (b^2 + 6*a*c)*C)*x^6 + (1/7)*c*(A*c^2 + 3*(b^2 + a*c)*C)*x^7 + (3/8)*b*c^2*C*x^8 + (1/9)*c^3*C*x^9}
{(A + C*x^2)*(a + b*x + c*x^2)^2, x, 2, a^2*A*x + a*A*b*x^2 + (1/3)*(A*(b^2 + 2*a*c) + a^2*C)*x^3 + (1/2)*b*(A*c + a*C)*x^4 + (1/5)*(A*c^2 + (b^2 + 2*a*c)*C)*x^5 + (1/3)*b*c*C*x^6 + (1/7)*c^2*C*x^7}
{(A + C*x^2)*(a + b*x + c*x^2)^1, x, 2, a*A*x + (1/2)*A*b*x^2 + (1/3)*(A*c + a*C)*x^3 + (1/4)*b*C*x^4 + (1/5)*c*C*x^5}
{(A + C*x^2)/(a + b*x + c*x^2)^1, x, 4, (C*x)/c - ((2*A*c^2 + (b^2 - 2*a*c)*C)*ArcTanh[(b + 2*c*x)/Sqrt[b^2 - 4*a*c]])/(c^2*Sqrt[b^2 - 4*a*c]) - (b*C*Log[a + b*x + c*x^2])/(2*c^2)}
{(A + C*x^2)/(a + b*x + c*x^2)^2, x, 2, -((b*(A*c + a*C) + (2*A*c^2 + (b^2 - 2*a*c)*C)*x)/(c*(b^2 - 4*a*c)*(a + b*x + c*x^2))) + (4*(A*c + a*C)*ArcTanh[(b + 2*c*x)/Sqrt[b^2 - 4*a*c]])/(b^2 - 4*a*c)^(3/2)}
{(A + C*x^2)/(a + b*x + c*x^2)^3, x, 3, -((b*(A*c + a*C) + (2*A*c^2 + (b^2 - 2*a*c)*C)*x)/(2*c*(b^2 - 4*a*c)*(a + b*x + c*x^2)^2)) + ((6*A*c^2 + (b^2 + 2*a*c)*C)*(b + 2*c*x))/(2*c*(b^2 - 4*a*c)^2*(a + b*x + c*x^2)) - (2*(6*A*c^2 + (b^2 + 2*a*c)*C)*ArcTanh[(b + 2*c*x)/Sqrt[b^2 - 4*a*c]])/(b^2 - 4*a*c)^(5/2)}
{(A + C*x^2)/(a + b*x + c*x^2)^4, x, 4, -((b*(A*c + a*C) + (2*A*c^2 + (b^2 - 2*a*c)*C)*x)/(3*c*(b^2 - 4*a*c)*(a + b*x + c*x^2)^3)) + ((5*A*c^2 + (b^2 + a*c)*C)*(b + 2*c*x))/(3*c*(b^2 - 4*a*c)^2*(a + b*x + c*x^2)^2) - (2*(5*A*c^2 + (b^2 + a*c)*C)*(b + 2*c*x))/((b^2 - 4*a*c)^3*(a + b*x + c*x^2)) + (8*c*(5*A*c^2 + (b^2 + a*c)*C)*ArcTanh[(b + 2*c*x)/Sqrt[b^2 - 4*a*c]])/(b^2 - 4*a*c)^(7/2)}


{(1 - x^2)/(1 + x + x^2)^2, x, 1, x/(1 + x + x^2)}
{(1 + x^2)/(1 + x + x^2), x, 4, x + ArcTan[(1 + 2*x)/Sqrt[3]]/Sqrt[3] - Log[1 + x + x^2]/2}
{(-1 + x^2)/(25 - 6*x + x^2), x, 4, x + 2*ArcTan[3/4 - x/4] + 3*Log[25 - 6*x + x^2]}
{(-10 + 3*x^2)/(4 - 4*x + x^2), x, 4, 2/(2 - x) + 3*x + 12*Log[2 - x]}
{(8 + x^2)/(6 - 5*x + x^2), x, 4, x - 12*Log[2 - x] + 17*Log[3 - x]}


(* ::Subsubsection::Closed:: *)
(*n>0*)


{(A + B*x + C*x^2)*(a + c*x^2)^3, x, 2, a^3*A*x + (1/2)*a^3*B*x^2 + (1/3)*a^2*(3*A*c + a*C)*x^3 + (3/4)*a^2*B*c*x^4 + (3/5)*a*c*(A*c + a*C)*x^5 + (1/2)*a*B*c^2*x^6 + (1/7)*c^2*(A*c + 3*a*C)*x^7 + (1/8)*B*c^3*x^8 + (1/9)*c^3*C*x^9}
{(A + B*x + C*x^2)*(a + c*x^2)^2, x, 2, a^2*A*x + (1/2)*a^2*B*x^2 + (1/3)*a*(2*A*c + a*C)*x^3 + (1/2)*a*B*c*x^4 + (1/5)*c*(A*c + 2*a*C)*x^5 + (1/6)*B*c^2*x^6 + (1/7)*c^2*C*x^7}
{(A + B*x + C*x^2)*(a + c*x^2)^1, x, 2, a*A*x + (1/2)*a*B*x^2 + (1/3)*(A*c + a*C)*x^3 + (1/4)*B*c*x^4 + (1/5)*c*C*x^5}
{(A + B*x + C*x^2)/(a + c*x^2)^1, x, 4, (C*x)/c + ((A*c - a*C)*ArcTan[(Sqrt[c]*x)/Sqrt[a]])/(Sqrt[a]*c^(3/2)) + (B*Log[a + c*x^2])/(2*c)}
{(A + B*x + C*x^2)/(a + c*x^2)^2, x, 2, -((a*B - (A*c - a*C)*x)/(2*a*c*(a + c*x^2))) + ((A*c + a*C)*ArcTan[(Sqrt[c]*x)/Sqrt[a]])/(2*a^(3/2)*c^(3/2))}
{(A + B*x + C*x^2)/(a + c*x^2)^3, x, 3, -((a*B - (A*c - a*C)*x)/(4*a*c*(a + c*x^2)^2)) + ((3*A*c + a*C)*x)/(8*a^2*c*(a + c*x^2)) + ((3*A*c + a*C)*ArcTan[(Sqrt[c]*x)/Sqrt[a]])/(8*a^(5/2)*c^(3/2))}
{(A + B*x + C*x^2)/(a + c*x^2)^4, x, 4, -((a*B - (A*c - a*C)*x)/(6*a*c*(a + c*x^2)^3)) + ((5*A*c + a*C)*x)/(24*a^2*c*(a + c*x^2)^2) + ((5*A*c + a*C)*x)/(16*a^3*c*(a + c*x^2)) + ((5*A*c + a*C)*ArcTan[(Sqrt[c]*x)/Sqrt[a]])/(16*a^(7/2)*c^(3/2))}


{(1 + 2*x + x^2)/(1 + x^2)^2, x, 2, -(1/(1 + x^2)) + ArcTan[x]}
{(2 + 12*x + 3*x^2)/(4 + x^2)^2, x, 2, -((24 + 5*x)/(4*(4 + x^2))) + (7/8)*ArcTan[x/2]}


(* ::Subsection::Closed:: *)
(*Integrands of the form (a+b x+c x^2)^(n/2) (d+f x^2)^p*)


(* ::Subsubsection::Closed:: *)
(*p>0*)


{(A + C*x^2)*(a + b*x + c*x^2)^(5/2), x, 5, (5*(b^2 - 4*a*c)^2*(32*A*c^2 + 9*b^2*C - 4*a*c*C)*(b + 2*c*x)*Sqrt[a + b*x + c*x^2])/(16384*c^5) - (5*(b^2 - 4*a*c)*(32*A*c^2 + 9*b^2*C - 4*a*c*C)*(b + 2*c*x)*(a + b*x + c*x^2)^(3/2))/(6144*c^4) + ((32*A*c^2 + 9*b^2*C - 4*a*c*C)*(b + 2*c*x)*(a + b*x + c*x^2)^(5/2))/(384*c^3) - (C*(9*b - 14*c*x)*(a + b*x + c*x^2)^(7/2))/(112*c^2) - (5*(b^2 - 4*a*c)^3*(32*A*c^2 + 9*b^2*C - 4*a*c*C)*ArcTanh[(b + 2*c*x)/(2*Sqrt[c]*Sqrt[a + b*x + c*x^2])])/(32768*c^(11/2))}
{(A + C*x^2)*(a + b*x + c*x^2)^(3/2), x, 4, -(((b^2 - 4*a*c)*(24*A*c^2 + 7*b^2*C - 4*a*c*C)*(b + 2*c*x)*Sqrt[a + b*x + c*x^2])/(512*c^4)) + ((24*A*c^2 + 7*b^2*C - 4*a*c*C)*(b + 2*c*x)*(a + b*x + c*x^2)^(3/2))/(192*c^3) - (C*(7*b - 10*c*x)*(a + b*x + c*x^2)^(5/2))/(60*c^2) + ((b^2 - 4*a*c)^2*(24*A*c^2 + 7*b^2*C - 4*a*c*C)*ArcTanh[(b + 2*c*x)/(2*Sqrt[c]*Sqrt[a + b*x + c*x^2])])/(1024*c^(9/2))}
{(A + C*x^2)*(a + b*x + c*x^2)^(1/2), x, 3, ((16*A*c^2 + 5*b^2*C - 4*a*c*C)*(b + 2*c*x)*Sqrt[a + b*x + c*x^2])/(64*c^3) - (C*(5*b - 6*c*x)*(a + b*x + c*x^2)^(3/2))/(24*c^2) - ((b^2 - 4*a*c)*(16*A*c^2 + 5*b^2*C - 4*a*c*C)*ArcTanh[(b + 2*c*x)/(2*Sqrt[c]*Sqrt[a + b*x + c*x^2])])/(128*c^(7/2))}
{(A + C*x^2)/(a + b*x + c*x^2)^(1/2), x, 2, -((C*(3*b - 2*c*x)*Sqrt[a + b*x + c*x^2])/(4*c^2)) + ((8*A*c^2 + 3*b^2*C - 4*a*c*C)*ArcTanh[(b + 2*c*x)/(2*Sqrt[c]*Sqrt[a + b*x + c*x^2])])/(8*c^(5/2))}
{(A + C*x^2)/(a + b*x + c*x^2)^(3/2), x, 2, -((2*(b*(A*c + a*C) + (2*A*c^2 + (b^2 - 2*a*c)*C)*x))/(c*(b^2 - 4*a*c)*Sqrt[a + b*x + c*x^2])) + (C*ArcTanh[(b + 2*c*x)/(2*Sqrt[c]*Sqrt[a + b*x + c*x^2])])/c^(3/2)}
{(A + C*x^2)/(a + b*x + c*x^2)^(5/2), x, 2, -((2*(b*(A*c + a*C) + (2*A*c^2 + (b^2 - 2*a*c)*C)*x))/(3*c*(b^2 - 4*a*c)*(a + b*x + c*x^2)^(3/2))) + (2*(8*A*c^2 + (b^2 + 4*a*c)*C)*(b + 2*c*x))/(3*c*(b^2 - 4*a*c)^2*Sqrt[a + b*x + c*x^2])}
{(A + C*x^2)/(a + b*x + c*x^2)^(7/2), x, 3, -((2*(b*(A*c + a*C) + (2*A*c^2 + (b^2 - 2*a*c)*C)*x))/(5*c*(b^2 - 4*a*c)*(a + b*x + c*x^2)^(5/2))) + (2*(16*A*c^2 + 3*b^2*C + 4*a*c*C)*(b + 2*c*x))/(15*c*(b^2 - 4*a*c)^2*(a + b*x + c*x^2)^(3/2)) - (16*(16*A*c^2 + 3*b^2*C + 4*a*c*C)*(b + 2*c*x))/(15*(b^2 - 4*a*c)^3*Sqrt[a + b*x + c*x^2])}
{(A + C*x^2)/(a + b*x + c*x^2)^(9/2), x, 4, -((2*(b*(A*c + a*C) + (2*A*c^2 + (b^2 - 2*a*c)*C)*x))/(7*c*(b^2 - 4*a*c)*(a + b*x + c*x^2)^(7/2))) + (2*(24*A*c^2 + 5*b^2*C + 4*a*c*C)*(b + 2*c*x))/(35*c*(b^2 - 4*a*c)^2*(a + b*x + c*x^2)^(5/2)) - (32*(24*A*c^2 + 5*b^2*C + 4*a*c*C)*(b + 2*c*x))/(105*(b^2 - 4*a*c)^3*(a + b*x + c*x^2)^(3/2)) + (256*c*(24*A*c^2 + 5*b^2*C + 4*a*c*C)*(b + 2*c*x))/(105*(b^2 - 4*a*c)^4*Sqrt[a + b*x + c*x^2])}


(* ::Subsubsection:: *)
(*p<0*)


(* ::Subsection::Closed:: *)
(*Integrands of the form (a+b x+c x^2)^n (d+f x^2)^(p/2)*)


(* ::Subsubsection::Closed:: *)
(*m>0*)


{(A + B*x + C*x^2)*(a + c*x^2)^(5/2), x, 5, (5*a^2*(8*A*c - a*C)*x*Sqrt[a + c*x^2])/(128*c) + (5*a*(8*A*c - a*C)*x*(a + c*x^2)^(3/2))/(192*c) + ((8*A*c - a*C)*x*(a + c*x^2)^(5/2))/(48*c) + ((8*B + 7*C*x)*(a + c*x^2)^(7/2))/(56*c) + (5*a^3*(8*A*c - a*C)*ArcTanh[(Sqrt[c]*x)/Sqrt[a + c*x^2]])/(128*c^(3/2))}
{(A + B*x + C*x^2)*(a + c*x^2)^(3/2), x, 4, (a*(6*A*c - a*C)*x*Sqrt[a + c*x^2])/(16*c) + ((6*A*c - a*C)*x*(a + c*x^2)^(3/2))/(24*c) + ((6*B + 5*C*x)*(a + c*x^2)^(5/2))/(30*c) + (a^2*(6*A*c - a*C)*ArcTanh[(Sqrt[c]*x)/Sqrt[a + c*x^2]])/(16*c^(3/2))}
{(A + B*x + C*x^2)*(a + c*x^2)^(1/2), x, 3, ((4*A*c - a*C)*x*Sqrt[a + c*x^2])/(8*c) + ((4*B + 3*C*x)*(a + c*x^2)^(3/2))/(12*c) + (a*(4*A*c - a*C)*ArcTanh[(Sqrt[c]*x)/Sqrt[a + c*x^2]])/(8*c^(3/2))}
{(A + B*x + C*x^2)/(a + c*x^2)^(1/2), x, 2, ((2*B + C*x)*Sqrt[a + c*x^2])/(2*c) + ((2*A*c - a*C)*ArcTanh[(Sqrt[c]*x)/Sqrt[a + c*x^2]])/(2*c^(3/2))}
{(A + B*x + C*x^2)/(a + c*x^2)^(3/2), x, 2, -((a*B - (A*c - a*C)*x)/(a*c*Sqrt[a + c*x^2])) + (C*ArcTanh[(Sqrt[c]*x)/Sqrt[a + c*x^2]])/c^(3/2)}
{(A + B*x + C*x^2)/(a + c*x^2)^(5/2), x, 2, -((a*B - (A*c - a*C)*x)/(3*a*c*(a + c*x^2)^(3/2))) + ((2*A*c + a*C)*x)/(3*a^2*c*Sqrt[a + c*x^2])}
{(A + B*x + C*x^2)/(a + c*x^2)^(7/2), x, 3, -((a*B - (A*c - a*C)*x)/(5*a*c*(a + c*x^2)^(5/2))) + ((4*A*c + a*C)*x)/(15*a^2*c*(a + c*x^2)^(3/2)) + (2*(4*A*c + a*C)*x)/(15*a^3*c*Sqrt[a + c*x^2])}
{(A + B*x + C*x^2)/(a + c*x^2)^(9/2), x, 4, -((a*B - (A*c - a*C)*x)/(7*a*c*(a + c*x^2)^(7/2))) + ((6*A*c + a*C)*x)/(35*a^2*c*(a + c*x^2)^(5/2)) + (4*(6*A*c + a*C)*x)/(105*a^3*c*(a + c*x^2)^(3/2)) + (8*(6*A*c + a*C)*x)/(105*a^4*c*Sqrt[a + c*x^2])}


(* ::Subsubsection:: *)
(*m<0*)


(* ::Section:: *)
(*Integrands of the form (a+b x+c x^2)^n (d+e x+f x^2)^p*)


(* ::Subsection::Closed:: *)
(*Integrands of the form (a+b x+c x^2)^n (d+e x+f x^2)^p*)


(* ::Subsubsection::Closed:: *)
(*p>0*)


{(A + B*x + C*x^2)*(a + b*x + c*x^2)^3, x, 2, a^3*A*x + (1/2)*a^2*(3*A*b + a*B)*x^2 + (1/3)*a*(3*A*(b^2 + a*c) + a*(3*b*B + a*C))*x^3 + (1/4)*(A*(b^3 + 6*a*b*c) + 3*a*(b^2*B + a*B*c + a*b*C))*x^4 + (1/5)*(b^3*B + 6*a*b*B*c + 3*b^2*(A*c + a*C) + 3*a*c*(A*c + a*C))*x^5 + (1/6)*(3*b^2*B*c + 3*a*B*c^2 + b^3*C + 3*b*c*(A*c + 2*a*C))*x^6 + (1/7)*c*(3*b*B*c + 3*b^2*C + c*(A*c + 3*a*C))*x^7 + (1/8)*c^2*(B*c + 3*b*C)*x^8 + (1/9)*c^3*C*x^9}
{(A + B*x + C*x^2)*(a + b*x + c*x^2)^2, x, 2, a^2*A*x + (1/2)*a*(2*A*b + a*B)*x^2 + (1/3)*(A*(b^2 + 2*a*c) + a*(2*b*B + a*C))*x^3 + (1/4)*(b^2*B + 2*a*B*c + 2*b*(A*c + a*C))*x^4 + (1/5)*(2*b*B*c + b^2*C + c*(A*c + 2*a*C))*x^5 + (1/6)*c*(B*c + 2*b*C)*x^6 + (1/7)*c^2*C*x^7}
{(A + B*x + C*x^2)*(a + b*x + c*x^2)^1, x, 2, a*A*x + (1/2)*(A*b + a*B)*x^2 + (1/3)*(b*B + A*c + a*C)*x^3 + (1/4)*(B*c + b*C)*x^4 + (1/5)*c*C*x^5}
{(A + B*x + C*x^2)/(a + b*x + c*x^2)^1, x, 4, (C*x)/c + ((b*B*c - b^2*C - 2*c*(A*c - a*C))*ArcTanh[(b + 2*c*x)/Sqrt[b^2 - 4*a*c]])/(c^2*Sqrt[b^2 - 4*a*c]) + ((B*c - b*C)*Log[a + b*x + c*x^2])/(2*c^2)}
{(A + B*x + C*x^2)/(a + b*x + c*x^2)^2, x, 2, -((A*b*c - 2*a*B*c + a*b*C - (b*B*c - b^2*C - 2*c*(A*c - a*C))*x)/(c*(b^2 - 4*a*c)*(a + b*x + c*x^2))) - (2*(b*B - 2*A*c - 2*a*C)*ArcTanh[(b + 2*c*x)/Sqrt[b^2 - 4*a*c]])/(b^2 - 4*a*c)^(3/2)}
{(A + B*x + C*x^2)/(a + b*x + c*x^2)^3, x, 3, -((A*b*c - 2*a*B*c + a*b*C - (b*B*c - b^2*C - 2*c*(A*c - a*C))*x)/(2*c*(b^2 - 4*a*c)*(a + b*x + c*x^2)^2)) - ((3*b*B*c - b^2*C - 2*c*(3*A*c + a*C))*(b + 2*c*x))/(2*c*(b^2 - 4*a*c)^2*(a + b*x + c*x^2)) + (2*(3*b*B*c - b^2*C - 2*c*(3*A*c + a*C))*ArcTanh[(b + 2*c*x)/Sqrt[b^2 - 4*a*c]])/(b^2 - 4*a*c)^(5/2)}
{(A + B*x + C*x^2)/(a + b*x + c*x^2)^4, x, 4, -((A*b*c - 2*a*B*c + a*b*C - (b*B*c - b^2*C - 2*c*(A*c - a*C))*x)/(3*c*(b^2 - 4*a*c)*(a + b*x + c*x^2)^3)) - ((5*b*B*c - 2*b^2*C - 2*c*(5*A*c + a*C))*(b + 2*c*x))/(6*c*(b^2 - 4*a*c)^2*(a + b*x + c*x^2)^2) + ((5*b*B*c - 2*b^2*C - 2*c*(5*A*c + a*C))*(b + 2*c*x))/((b^2 - 4*a*c)^3*(a + b*x + c*x^2)) - (4*c*(5*b*B*c - 2*b^2*C - 2*c*(5*A*c + a*C))*ArcTanh[(b + 2*c*x)/Sqrt[b^2 - 4*a*c]])/(b^2 - 4*a*c)^(7/2)}


(* ::Subsubsection::Closed:: *)
(*p<0*)


{(-4 + 3*x + x^2)/(-8 - 2*x + x^2), x, 4, x + 4*Log[4 - x] + Log[2 + x]}
{(7 + 5*x + 4*x^2)/(5 + 4*x + 4*x^2), x, 4, x + (3/8)*ArcTan[1/2 + x] + (1/8)*Log[5 + 4*x + 4*x^2]}
{(2 - x + x^2)/(-5 + 2*x + x^2), x, 4, x - (1/6)*(9 - 5*Sqrt[6])*Log[1 - Sqrt[6] + x] - (1/6)*(9 + 5*Sqrt[6])*Log[1 + Sqrt[6] + x]}

{(1 + 4*x + 3*x^2)/(4 + 7*x + 2*x^2)^2, x, 1, -((2 + 3*x)/(2*(4 + 7*x + 2*x^2)))}
{(1 + x + x^2)/(3 + 2*x + x^2)^2, x, 2, (1 - x)/(4*(3 + 2*x + x^2)) + (3*ArcTan[(1 + x)/Sqrt[2]])/(4*Sqrt[2])}

{(-1 + 2*x + 5*x^2)/(1 + x + x^2)^4, x, 1, -(x/(1 + x + x^2)^3)}


(* ::Subsection::Closed:: *)
(*Integrands of the form (a+b x+c x^2)^(n/2) (d+e x+f x^2)^p*)


(* ::Subsubsection::Closed:: *)
(*p>0*)


{(A + B*x + C*x^2)*(a + b*x + c*x^2)^(5/2), x, 5, -((5*(b^2 - 4*a*c)^2*(16*b*B*c - 9*b^2*C - 4*c*(8*A*c - a*C))*(b + 2*c*x)*Sqrt[a + b*x + c*x^2])/(16384*c^5)) + (5*(b^2 - 4*a*c)*(16*b*B*c - 9*b^2*C - 4*c*(8*A*c - a*C))*(b + 2*c*x)*(a + b*x + c*x^2)^(3/2))/(6144*c^4) - ((16*b*B*c - 32*A*c^2 - 9*b^2*C + 4*a*c*C)*(b + 2*c*x)*(a + b*x + c*x^2)^(5/2))/(384*c^3) + ((16*B*c - 9*b*C + 14*c*C*x)*(a + b*x + c*x^2)^(7/2))/(112*c^2) + (5*(b^2 - 4*a*c)^3*(16*b*B*c - 9*b^2*C - 4*c*(8*A*c - a*C))*ArcTanh[(b + 2*c*x)/(2*Sqrt[c]*Sqrt[a + b*x + c*x^2])])/(32768*c^(11/2))}
{(A + B*x + C*x^2)*(a + b*x + c*x^2)^(3/2), x, 4, ((b^2 - 4*a*c)*(12*b*B*c - 7*b^2*C - 4*c*(6*A*c - a*C))*(b + 2*c*x)*Sqrt[a + b*x + c*x^2])/(512*c^4) - ((12*b*B*c - 24*A*c^2 - 7*b^2*C + 4*a*c*C)*(b + 2*c*x)*(a + b*x + c*x^2)^(3/2))/(192*c^3) + ((12*B*c - 7*b*C + 10*c*C*x)*(a + b*x + c*x^2)^(5/2))/(60*c^2) - ((b^2 - 4*a*c)^2*(12*b*B*c - 7*b^2*C - 4*c*(6*A*c - a*C))*ArcTanh[(b + 2*c*x)/(2*Sqrt[c]*Sqrt[a + b*x + c*x^2])])/(1024*c^(9/2))}
{(A + B*x + C*x^2)*(a + b*x + c*x^2)^(1/2), x, 3, -(((8*b*B*c - 16*A*c^2 - 5*b^2*C + 4*a*c*C)*(b + 2*c*x)*Sqrt[a + b*x + c*x^2])/(64*c^3)) + ((8*B*c - 5*b*C + 6*c*C*x)*(a + b*x + c*x^2)^(3/2))/(24*c^2) + ((b^2 - 4*a*c)*(8*b*B*c - 5*b^2*C - 4*c*(4*A*c - a*C))*ArcTanh[(b + 2*c*x)/(2*Sqrt[c]*Sqrt[a + b*x + c*x^2])])/(128*c^(7/2))}
{(A + B*x + C*x^2)/(a + b*x + c*x^2)^(1/2), x, 2, ((4*B*c - 3*b*C + 2*c*C*x)*Sqrt[a + b*x + c*x^2])/(4*c^2) - ((4*b*B*c - 8*A*c^2 - 3*b^2*C + 4*a*c*C)*ArcTanh[(b + 2*c*x)/(2*Sqrt[c]*Sqrt[a + b*x + c*x^2])])/(8*c^(5/2))}
{(A + B*x + C*x^2)/(a + b*x + c*x^2)^(3/2), x, 2, -((2*(A*b*c - 2*a*B*c + a*b*C - (b*B*c - b^2*C - 2*c*(A*c - a*C))*x))/(c*(b^2 - 4*a*c)*Sqrt[a + b*x + c*x^2])) + (C*ArcTanh[(b + 2*c*x)/(2*Sqrt[c]*Sqrt[a + b*x + c*x^2])])/c^(3/2)}
{(A + B*x + C*x^2)/(a + b*x + c*x^2)^(5/2), x, 2, -((2*(A*b*c - 2*a*B*c + a*b*C - (b*B*c - b^2*C - 2*c*(A*c - a*C))*x))/(3*c*(b^2 - 4*a*c)*(a + b*x + c*x^2)^(3/2))) - (2*(4*b*B*c - b^2*C - 4*c*(2*A*c + a*C))*(b + 2*c*x))/(3*c*(b^2 - 4*a*c)^2*Sqrt[a + b*x + c*x^2])}
{(A + B*x + C*x^2)/(a + b*x + c*x^2)^(7/2), x, 3, -((2*(A*b*c - 2*a*B*c + a*b*C - (b*B*c - b^2*C - 2*c*(A*c - a*C))*x))/(5*c*(b^2 - 4*a*c)*(a + b*x + c*x^2)^(5/2))) - (2*(8*b*B*c - 3*b^2*C - 4*c*(4*A*c + a*C))*(b + 2*c*x))/(15*c*(b^2 - 4*a*c)^2*(a + b*x + c*x^2)^(3/2)) + (16*(8*b*B*c - 3*b^2*C - 4*c*(4*A*c + a*C))*(b + 2*c*x))/(15*(b^2 - 4*a*c)^3*Sqrt[a + b*x + c*x^2])}
{(A + B*x + C*x^2)/(a + b*x + c*x^2)^(9/2), x, 4, -((2*(A*b*c - 2*a*B*c + a*b*C - (b*B*c - b^2*C - 2*c*(A*c - a*C))*x))/(7*c*(b^2 - 4*a*c)*(a + b*x + c*x^2)^(7/2))) - (2*(12*b*B*c - 5*b^2*C - 4*c*(6*A*c + a*C))*(b + 2*c*x))/(35*c*(b^2 - 4*a*c)^2*(a + b*x + c*x^2)^(5/2)) + (32*(12*b*B*c - 5*b^2*C - 4*c*(6*A*c + a*C))*(b + 2*c*x))/(105*(b^2 - 4*a*c)^3*(a + b*x + c*x^2)^(3/2)) - (256*c*(12*b*B*c - 5*b^2*C - 4*c*(6*A*c + a*C))*(b + 2*c*x))/(105*(b^2 - 4*a*c)^4*Sqrt[a + b*x + c*x^2])}


(* ::Subsubsection:: *)
(*p<0*)


(* ::Section:: *)
(*Integrands of the form (A+B x) (a+b x+c x^2)^n (d+e x+f x^2)^p when e=0*)


(* ::Subsection::Closed:: *)
(*Integrands of the form (A+B x) (a+b x+c x^2)^n / (d+f x^2)*)


(* ::Subsubsection::Closed:: *)
(*n>0*)


{(A + B*x)*(a + b*x + c*x^2)^1/(d + f*x^2), x, 5, ((b*B + A*c)*x)/f + (B*c*x^2)/(2*f) - ((b*B*d + A*c*d - a*A*f)*ArcTan[(Sqrt[f]*x)/Sqrt[d]])/(Sqrt[d]*f^(3/2)) - ((B*c*d - A*b*f - a*B*f)*Log[d + f*x^2])/(2*f^2)}
{(A + B*x)*(a + b*x + c*x^2)^2/(d + f*x^2), x, 5, ((A*b^2*f - A*c*(c*d - 2*a*f) - b*B*(2*c*d - 2*a*f))*x)/f^2 + ((2*A*b*c*f - B*(c^2*d - b^2*f - 2*a*c*f))*x^2)/(2*f^2) + (c*(2*b*B + A*c)*x^3)/(3*f) + (B*c^2*x^4)/(4*f) - ((A*b^2*d*f - 2*b*B*d*(c*d - a*f) - A*(c*d - a*f)^2)*ArcTan[(Sqrt[f]*x)/Sqrt[d]])/(Sqrt[d]*f^(5/2)) - ((2*A*b*f*(c*d - a*f) - B*(c^2*d^2 - 2*a*c*d*f - f*(b^2*d - a^2*f)))*Log[d + f*x^2])/(2*f^3)}
{(A + B*x)*(a + b*x + c*x^2)^3/(d + f*x^2), x, 5, -(((b^3*B*d*f + 3*A*b^2*f*(c*d - a*f) - 3*b*B*(c*d - a*f)^2 - A*c*(c^2*d^2 - 3*a*c*d*f + 3*a^2*f^2))*x)/f^3) - ((A*b*f*(3*c^2*d - b^2*f - 6*a*c*f) - B*(c^3*d^2 - 3*a*c^2*d*f + 3*a*b^2*f^2 - 3*c*f*(b^2*d - a^2*f)))*x^2)/(2*f^3) + ((b^3*B*f + 3*A*b^2*c*f - A*c^2*(c*d - 3*a*f) - 3*b*B*c*(c*d - 2*a*f))*x^3)/(3*f^2) + (c*(3*A*b*c*f - B*(c^2*d - 3*b^2*f - 3*a*c*f))*x^4)/(4*f^2) + (c^2*(3*b*B + A*c)*x^5)/(5*f) + (B*c^3*x^6)/(6*f) + ((b^3*B*d^2*f + 3*A*b^2*d*f*(c*d - a*f) - 3*b*B*d*(c*d - a*f)^2 - A*(c*d - a*f)^3)*ArcTan[(Sqrt[f]*x)/Sqrt[d]])/(Sqrt[d]*f^(7/2)) + ((A*b*f*(3*c^2*d^2 - 6*a*c*d*f - f*(b^2*d - 3*a^2*f)) - B*(c*d - a*f)*(c^2*d^2 - 2*a*c*d*f - f*(3*b^2*d - a^2*f)))*Log[d + f*x^2])/(2*f^4)}


(* ::Subsubsection::Closed:: *)
(*n<0*)


{(A + B*x)/(a + b*x + c*x^2)^1/(d + f*x^2), x, 8, (Sqrt[f]*(b*B*d - A*c*d + a*A*f)*ArcTan[(Sqrt[f]*x)/Sqrt[d]])/(Sqrt[d]*(c^2*d^2 - 2*a*c*d*f + f*(b^2*d + a^2*f))) - ((A*b^2*f + 2*A*c*(c*d - a*f) - b*B*(c*d + a*f))*ArcTanh[(b + 2*c*x)/Sqrt[b^2 - 4*a*c]])/(Sqrt[b^2 - 4*a*c]*(c^2*d^2 - 2*a*c*d*f + f*(b^2*d + a^2*f))) + ((B*c*d + A*b*f - a*B*f)*Log[a + b*x + c*x^2])/(2*(c^2*d^2 - 2*a*c*d*f + f*(b^2*d + a^2*f))) - ((B*c*d + A*b*f - a*B*f)*Log[d + f*x^2])/(2*(c^2*d^2 - 2*a*c*d*f + f*(b^2*d + a^2*f)))}
{(A + B*x)/(a + b*x + c*x^2)^2/(d + f*x^2), x, 10, -((A*b*(c^2*d + b^2*f - 3*a*c*f) - a*B*(2*c^2*d + b^2*f - 2*a*c*f) + c*(A*b^2*f + 2*A*c*(c*d - a*f) - b*B*(c*d + a*f))*x)/((b^2 - 4*a*c)*(c^2*d^2 - 2*a*c*d*f + f*(b^2*d + a^2*f))*(a + b*x + c*x^2))) - (f^(3/2)*(A*b^2*d*f + 2*b*B*d*(c*d - a*f) - A*(c*d - a*f)^2)*ArcTan[(Sqrt[f]*x)/Sqrt[d]])/(Sqrt[d]*(c^2*d^2 - 2*a*c*d*f + f*(b^2*d + a^2*f))^2) + (2*c*(A*b^2*f + 2*A*c*(c*d - a*f) - b*B*(c*d + a*f))*ArcTanh[(b + 2*c*x)/Sqrt[b^2 - 4*a*c]])/((b^2 - 4*a*c)^(3/2)*(c^2*d^2 - 2*a*c*d*f + f*(b^2*d + a^2*f))) - (f*(b^3*B*d*f + 2*a*A*b^2*f^2 - 2*A*c*(c*d - a*f)^2 + b*B*(3*c^2*d^2 - 2*a*c*d*f - a^2*f^2))*ArcTanh[(b + 2*c*x)/Sqrt[b^2 - 4*a*c]])/(Sqrt[b^2 - 4*a*c]*(c^2*d^2 - 2*a*c*d*f + f*(b^2*d + a^2*f))^2) - (f*(2*A*b*f*(c*d - a*f) + B*(c^2*d^2 - 2*a*c*d*f - f*(b^2*d - a^2*f)))*Log[a + b*x + c*x^2])/(2*(c^2*d^2 - 2*a*c*d*f + f*(b^2*d + a^2*f))^2) + (f*(2*A*b*f*(c*d - a*f) + B*(c^2*d^2 - 2*a*c*d*f - f*(b^2*d - a^2*f)))*Log[d + f*x^2])/(2*(c^2*d^2 - 2*a*c*d*f + f*(b^2*d + a^2*f))^2)}


(* ::Subsection::Closed:: *)
(*Integrands of the form (A+B x) (a+b x+c x^2)^(n/2) / (d+f x^2)*)


(* ::Subsubsection::Closed:: *)
(*m>0*)


{(A + B*x)*(a + b*x + c*x^2)^(1/2)/(d + f*x^2), x, 6, (B*Sqrt[a + b*x + c*x^2])/f + ((B*c*d - A*b*f - a*B*f + (d*Sqrt[f]*(b*B*d + A*c*d - a*A*f))/(-d)^(3/2))*ArcTan[(b*Sqrt[-d] - 2*a*Sqrt[f] + (2*c*Sqrt[-d] - b*Sqrt[f])*x)/(2*Sqrt[c*d + b*Sqrt[-d]*Sqrt[f] - a*f]*Sqrt[a + b*x + c*x^2])])/(2*f^(3/2)*Sqrt[c*d + b*Sqrt[-d]*Sqrt[f] - a*f]) - ((B*c*d - A*b*f - a*B*f + (Sqrt[f]*(b*B*d + A*c*d - a*A*f))/Sqrt[-d])*ArcTan[(b*Sqrt[-d] + 2*a*Sqrt[f] + (2*c*Sqrt[-d] + b*Sqrt[f])*x)/(2*Sqrt[c*d - b*Sqrt[-d]*Sqrt[f] - a*f]*Sqrt[a + b*x + c*x^2])])/(2*f^(3/2)*Sqrt[c*d - b*Sqrt[-d]*Sqrt[f] - a*f]) + ((b*B + 2*A*c)*ArcTanh[(b + 2*c*x)/(2*Sqrt[c]*Sqrt[a + b*x + c*x^2])])/(2*Sqrt[c]*f)}
{(A + B*x)*(a + b*x + c*x^2)^(3/2)/(d + f*x^2), x, 10, -(((B*c*d - A*b*f - a*B*f)*Sqrt[a + b*x + c*x^2])/f^2) + ((b*B + 2*A*c)*(b + 2*c*x)*Sqrt[a + b*x + c*x^2])/(8*c*f) + (B*(a + b*x + c*x^2)^(3/2))/(3*f) + ((b*f*(b*B*d + A*c*d - a*A*f) - (c*d - a*f)*(B*c*d - A*b*f - a*B*f) - (Sqrt[f]*(A*b^2*d*f - 2*b*B*d*(c*d - a*f) - A*(c*d - a*f)^2))/Sqrt[-d])*ArcTan[(b*Sqrt[-d] - 2*a*Sqrt[f] + (2*c*Sqrt[-d] - b*Sqrt[f])*x)/(2*Sqrt[c*d + b*Sqrt[-d]*Sqrt[f] - a*f]*Sqrt[a + b*x + c*x^2])])/(2*f^(5/2)*Sqrt[c*d + b*Sqrt[-d]*Sqrt[f] - a*f]) - ((b*f*(b*B*d + A*c*d - a*A*f) - (c*d - a*f)*(B*c*d - A*b*f - a*B*f) + (Sqrt[f]*(A*b^2*d*f - 2*b*B*d*(c*d - a*f) - A*(c*d - a*f)^2))/Sqrt[-d])*ArcTan[(b*Sqrt[-d] + 2*a*Sqrt[f] + (2*c*Sqrt[-d] + b*Sqrt[f])*x)/(2*Sqrt[c*d - b*Sqrt[-d]*Sqrt[f] - a*f]*Sqrt[a + b*x + c*x^2])])/(2*f^(5/2)*Sqrt[c*d - b*Sqrt[-d]*Sqrt[f] - a*f]) - ((b^2 - 4*a*c)*(b*B + 2*A*c)*ArcTanh[(b + 2*c*x)/(2*Sqrt[c]*Sqrt[a + b*x + c*x^2])])/(16*c^(3/2)*f) + ((A*b^2*f - 2*A*c*(c*d - a*f) - b*B*(3*c*d - a*f))*ArcTanh[(b + 2*c*x)/(2*Sqrt[c]*Sqrt[a + b*x + c*x^2])])/(2*Sqrt[c]*f^2)}


(* ::Subsubsection::Closed:: *)
(*m<0*)


{(A + B*x)/(a + b*x + c*x^2)^(1/2)/(d + f*x^2), x, 3, -(((B - (A*Sqrt[f])/Sqrt[-d])*ArcTan[(b*Sqrt[-d] - 2*a*Sqrt[f] + (2*c*Sqrt[-d] - b*Sqrt[f])*x)/(2*Sqrt[c*d + b*Sqrt[-d]*Sqrt[f] - a*f]*Sqrt[a + b*x + c*x^2])])/(2*Sqrt[f]*Sqrt[c*d + b*Sqrt[-d]*Sqrt[f] - a*f])) + ((B + (A*Sqrt[f])/Sqrt[-d])*ArcTan[(b*Sqrt[-d] + 2*a*Sqrt[f] + (2*c*Sqrt[-d] + b*Sqrt[f])*x)/(2*Sqrt[c*d - b*Sqrt[-d]*Sqrt[f] - a*f]*Sqrt[a + b*x + c*x^2])])/(2*Sqrt[f]*Sqrt[c*d - b*Sqrt[-d]*Sqrt[f] - a*f])}
{(A + B*x)/(a + b*x + c*x^2)^(3/2)/(d + f*x^2), x, 5, -((2*(A*b*(c^2*d + b^2*f - 3*a*c*f) - a*B*(2*c^2*d + b^2*f - 2*a*c*f) + c*(A*b^2*f + 2*A*c*(c*d - a*f) - b*B*(c*d + a*f))*x))/((b^2 - 4*a*c)*(c^2*d^2 - 2*a*c*d*f + f*(b^2*d + a^2*f))*Sqrt[a + b*x + c*x^2])) + (Sqrt[f]*(B*c*d + A*b*f - a*B*f + (Sqrt[f]*(b*B*d - A*c*d + a*A*f))/Sqrt[-d])*ArcTan[(b*Sqrt[-d] - 2*a*Sqrt[f] + (2*c*Sqrt[-d] - b*Sqrt[f])*x)/(2*Sqrt[c*d + b*Sqrt[-d]*Sqrt[f] - a*f]*Sqrt[a + b*x + c*x^2])])/(2*Sqrt[c*d + b*Sqrt[-d]*Sqrt[f] - a*f]*(c^2*d^2 - 2*a*c*d*f + f*(b^2*d + a^2*f))) - (Sqrt[f]*(B*c*d + A*b*f - a*B*f + (d*Sqrt[f]*(b*B*d - A*c*d + a*A*f))/(-d)^(3/2))*ArcTan[(b*Sqrt[-d] + 2*a*Sqrt[f] + (2*c*Sqrt[-d] + b*Sqrt[f])*x)/(2*Sqrt[c*d - b*Sqrt[-d]*Sqrt[f] - a*f]*Sqrt[a + b*x + c*x^2])])/(2*Sqrt[c*d - b*Sqrt[-d]*Sqrt[f] - a*f]*(c^2*d^2 - 2*a*c*d*f + f*(b^2*d + a^2*f)))}
{(A + B*x)/(a + b*x + c*x^2)^(5/2)/(d + f*x^2), x, 8, -((2*(A*b*(c^2*d + b^2*f - 3*a*c*f) - a*B*(2*c^2*d + b^2*f - 2*a*c*f) + c*(A*b^2*f + 2*A*c*(c*d - a*f) - b*B*(c*d + a*f))*x))/(3*(b^2 - 4*a*c)*(c^2*d^2 - 2*a*c*d*f + f*(b^2*d + a^2*f))*(a + b*x + c*x^2)^(3/2))) + (8*c*(A*b^2*f + 2*A*c*(c*d - a*f) - b*B*(c*d + a*f))*(b + 2*c*x))/(3*(b^2 - 4*a*c)^2*(c^2*d^2 - 2*a*c*d*f + f*(b^2*d + a^2*f))*Sqrt[a + b*x + c*x^2]) - (2*f*(b^4*B*d*f - A*b^3*f*(c*d - 2*a*f) + 2*a*B*c*(c*d - a*f)^2 + b^2*B*(c^2*d^2 - 2*a*c*d*f - a^2*f^2) - A*b*c*(c^2*d^2 - 6*a*c*d*f + 5*a^2*f^2) + c*(b^3*B*d*f + 2*a*A*b^2*f^2 - 2*A*c*(c*d - a*f)^2 + b*B*(3*c^2*d^2 - 2*a*c*d*f - a^2*f^2))*x))/((b^2 - 4*a*c)*(c^2*d^2 - 2*a*c*d*f + f*(b^2*d + a^2*f))^2*Sqrt[a + b*x + c*x^2]) + (f^(3/2)*(b*f*(b*B*d - A*c*d + a*A*f) - (c*d - a*f)*(B*c*d + A*b*f - a*B*f) - (Sqrt[f]*(A*b^2*d*f + 2*b*B*d*(c*d - a*f) - A*(c*d - a*f)^2))/Sqrt[-d])*ArcTan[(b*Sqrt[-d] - 2*a*Sqrt[f] + (2*c*Sqrt[-d] - b*Sqrt[f])*x)/(2*Sqrt[c*d + b*Sqrt[-d]*Sqrt[f] - a*f]*Sqrt[a + b*x + c*x^2])])/(2*Sqrt[c*d + b*Sqrt[-d]*Sqrt[f] - a*f]*(c^2*d^2 - 2*a*c*d*f + f*(b^2*d + a^2*f))^2) - (f^(3/2)*(b*f*(b*B*d - A*c*d + a*A*f) - (c*d - a*f)*(B*c*d + A*b*f - a*B*f) + (Sqrt[f]*(A*b^2*d*f + 2*b*B*d*(c*d - a*f) - A*(c*d - a*f)^2))/Sqrt[-d])*ArcTan[(b*Sqrt[-d] + 2*a*Sqrt[f] + (2*c*Sqrt[-d] + b*Sqrt[f])*x)/(2*Sqrt[c*d - b*Sqrt[-d]*Sqrt[f] - a*f]*Sqrt[a + b*x + c*x^2])])/(2*Sqrt[c*d - b*Sqrt[-d]*Sqrt[f] - a*f]*(c^2*d^2 - 2*a*c*d*f + f*(b^2*d + a^2*f))^2)}


(* ::Section:: *)
(*Integrands of the form (A+B x) (a+b x+c x^2)^n (d+e x+f x^2)^p*)


(* ::Subsection::Closed:: *)
(*Integrands of the form (A+B x) (a+b x+c x^2)^n / (d+e x+f x^2)*)


(* ::Subsubsection::Closed:: *)
(*m>0*)


{(A + B*x)*(a + b*x + c*x^2)^1/(d + e*x + f*x^2), x, 5, -(((B*c*e - b*B*f - A*c*f)*x)/f^2) + (B*c*x^2)/(2*f) - ((A*f*(c*e^2 - 2*c*d*f - b*e*f + 2*a*f^2) + B*(f*(b*e^2 - 2*b*d*f - a*e*f) - c*(e^3 - 3*d*e*f)))*ArcTanh[(e + 2*f*x)/Sqrt[e^2 - 4*d*f]])/(f^3*Sqrt[e^2 - 4*d*f]) - ((A*f*(c*e - b*f) - B*(c*e^2 - c*d*f - b*e*f + a*f^2))*Log[d + e*x + f*x^2])/(2*f^3)}
{(A + B*x)*(a + b*x + c*x^2)^2/(d + e*x + f*x^2), x, 5, ((B*(c*e - b*f)*(f*(b*e - 2*a*f) - c*(e^2 - 2*d*f)) + A*f*(b^2*f^2 - 2*c*f*(b*e - a*f) + c^2*(e^2 - d*f)))*x)/f^4 - ((A*c*f*(c*e - 2*b*f) - B*(b^2*f^2 - 2*c*f*(b*e - a*f) + c^2*(e^2 - d*f)))*x^2)/(2*f^3) - (c*(B*c*e - 2*b*B*f - A*c*f)*x^3)/(3*f^2) + (B*c^2*x^4)/(4*f) - ((A*f*(c^2*(e^4 - 4*d*e^2*f + 2*d^2*f^2) - f^2*(2*a*b*e*f - 2*a^2*f^2 - b^2*(e^2 - 2*d*f)) + 2*c*f*(a*f*(e^2 - 2*d*f) - b*(e^3 - 3*d*e*f))) - B*(c^2*(e^5 - 5*d*e^3*f + 5*d^2*e*f^2) + f^2*(a^2*e*f^2 - 2*a*b*f*(e^2 - 2*d*f) + b^2*(e^3 - 3*d*e*f)) + 2*c*f*(a*e*f*(e^2 - 3*d*f) - b*(e^4 - 4*d*e^2*f + 2*d^2*f^2))))*ArcTanh[(e + 2*f*x)/Sqrt[e^2 - 4*d*f]])/(f^5*Sqrt[e^2 - 4*d*f]) + ((A*f*(c*e - b*f)*(f*(b*e - 2*a*f) - c*(e^2 - 2*d*f)) + B*(c^2*(e^4 - 3*d*e^2*f + d^2*f^2) - f^2*(2*a*b*e*f - a^2*f^2 - b^2*(e^2 - d*f)) + 2*c*f*(a*f*(e^2 - d*f) - b*(e^3 - 2*d*e*f))))*Log[d + e*x + f*x^2])/(2*f^5)}


(* ::Subsubsection::Closed:: *)
(*m<0*)


{(A + B*x)/(a + b*x + c*x^2)^1/(d + e*x + f*x^2), x, 8, -(((A*b^2*f + 2*c*(A*c*d + a*B*e - a*A*f) - b*(B*c*d + A*c*e + a*B*f))*ArcTanh[(b + 2*c*x)/Sqrt[b^2 - 4*a*c]])/(Sqrt[b^2 - 4*a*c]*(c^2*d^2 + f*(b^2*d - a*b*e + a^2*f) - c*(b*d*e - a*(e^2 - 2*d*f))))) + ((B*(c*d*e - 2*b*d*f + a*e*f) - A*(c*e^2 - 2*c*d*f - b*e*f + 2*a*f^2))*ArcTanh[(e + 2*f*x)/Sqrt[e^2 - 4*d*f]])/(Sqrt[e^2 - 4*d*f]*(c^2*d^2 + f*(b^2*d - a*b*e + a^2*f) - c*(b*d*e - a*(e^2 - 2*d*f)))) + ((B*c*d - A*c*e + A*b*f - a*B*f)*Log[a + b*x + c*x^2])/(2*(c^2*d^2 + f*(b^2*d - a*b*e + a^2*f) - c*(b*d*e - a*(e^2 - 2*d*f)))) - ((B*c*d - A*c*e + A*b*f - a*B*f)*Log[d + e*x + f*x^2])/(2*(c^2*d^2 + f*(b^2*d - a*b*e + a^2*f) - c*(b*d*e - a*(e^2 - 2*d*f))))}
{(A + B*x)/(a + b*x + c*x^2)^2/(d + e*x + f*x^2), x, 10, (A*(b^2*c*e - 2*a*c^2*e - b^3*f - b*c*(c*d - 3*a*f)) + a*B*(2*c^2*d + b^2*f - c*(b*e + 2*a*f)) - c*(A*b^2*f + 2*c*(A*c*d + a*B*e - a*A*f) - b*(B*c*d + A*c*e + a*B*f))*x)/((b^2 - 4*a*c)*(c^2*d^2 + f*(b^2*d - a*b*e + a^2*f) - c*(b*d*e - a*(e^2 - 2*d*f)))*(a + b*x + c*x^2)) + (2*c*(A*b^2*f + 2*c*(A*c*d + a*B*e - a*A*f) - b*(B*c*d + A*c*e + a*B*f))*ArcTanh[(b + 2*c*x)/Sqrt[b^2 - 4*a*c]])/((b^2 - 4*a*c)^(3/2)*(c^2*d^2 + f*(b^2*d - a*b*e + a^2*f) - c*(b*d*e - a*(e^2 - 2*d*f)))) + ((B*(2*c^3*d^2*e - b*f^2*(b^2*d - a^2*f) - b*c^2*d*(e^2 + 3*d*f) + 2*c*f*(b^2*d*e + a*b*d*f - a^2*e*f)) + A*(b^2*f^2*(b*e - 2*a*f) - 2*c^3*d*(e^2 - d*f) - 2*c*f*(b^2*e^2 - a*b*e*f - a^2*f^2) + c^2*(b*e^3 + 2*b*d*e*f - 4*a*d*f^2)))*ArcTanh[(b + 2*c*x)/Sqrt[b^2 - 4*a*c]])/(Sqrt[b^2 - 4*a*c]*(c^2*d^2 + f*(b^2*d - a*b*e + a^2*f) - c*(b*d*e - a*(e^2 - 2*d*f)))^2) + ((B*(c^2*d*e*(e^2 - 3*d*f) - 2*c*d*f*(b*e^2 - 2*b*d*f - a*e*f) + f^2*(b^2*d*e - 4*a*b*d*f + a^2*e*f)) - A*(c^2*(e^4 - 4*d*e^2*f + 2*d^2*f^2) - f^2*(2*a*b*e*f - 2*a^2*f^2 - b^2*(e^2 - 2*d*f)) + 2*c*f*(a*f*(e^2 - 2*d*f) - b*(e^3 - 3*d*e*f))))*ArcTanh[(e + 2*f*x)/Sqrt[e^2 - 4*d*f]])/(Sqrt[e^2 - 4*d*f]*(c^2*d^2 + f*(b^2*d - a*b*e + a^2*f) - c*(b*d*e - a*(e^2 - 2*d*f)))^2) + ((A*(c*e - b*f)*(f*(b*e - 2*a*f) - c*(e^2 - 2*d*f)) - B*(2*c*d*f*(b*e - a*f) - f^2*(b^2*d - a^2*f) - c^2*d*(e^2 - d*f)))*Log[a + b*x + c*x^2])/(2*(c^2*d^2 + f*(b^2*d - a*b*e + a^2*f) - c*(b*d*e - a*(e^2 - 2*d*f)))^2) - ((A*(c*e - b*f)*(f*(b*e - 2*a*f) - c*(e^2 - 2*d*f)) - B*(2*c*d*f*(b*e - a*f) - f^2*(b^2*d - a^2*f) - c^2*d*(e^2 - d*f)))*Log[d + e*x + f*x^2])/(2*(c^2*d^2 + f*(b^2*d - a*b*e + a^2*f) - c*(b*d*e - a*(e^2 - 2*d*f)))^2)}


(* ::Subsection::Closed:: *)
(*Integrands of the form (A+B x) (a+b x+c x^2)^(n/2) / (d+e x+f x^2)*)


(* ::Subsubsection::Closed:: *)
(*m>0*)


{(A + B*x)*(a + b*x + c*x^2)^(1/2)/(d + e*x + f*x^2), x, 6, (B*Sqrt[a + b*x + c*x^2])/f - ((2*B*c*e - b*B*f - 2*A*c*f)*ArcTanh[(b + 2*c*x)/(2*Sqrt[c]*Sqrt[a + b*x + c*x^2])])/(2*Sqrt[c]*f^2) + ((2*f*(A*f*(c*d - a*f) - B*d*(c*e - b*f)) - (e - Sqrt[e^2 - 4*d*f])*(A*f*(c*e - b*f) + B*(f*(b*e - a*f) - c*(e^2 - d*f))))*ArcTanh[(4*a*f - b*(e - Sqrt[e^2 - 4*d*f]) + 2*(b*f - c*(e - Sqrt[e^2 - 4*d*f]))*x)/(2*Sqrt[4*a*f^2 - 2*b*f*(e - Sqrt[e^2 - 4*d*f]) + c*(e - Sqrt[e^2 - 4*d*f])^2]*Sqrt[a + b*x + c*x^2])])/(f^2*Sqrt[e^2 - 4*d*f]*Sqrt[4*a*f^2 - 2*b*f*(e - Sqrt[e^2 - 4*d*f]) + c*(e - Sqrt[e^2 - 4*d*f])^2]) - ((2*f*(A*f*(c*d - a*f) - B*d*(c*e - b*f)) - (e + Sqrt[e^2 - 4*d*f])*(A*f*(c*e - b*f) + B*(f*(b*e - a*f) - c*(e^2 - d*f))))*ArcTanh[(4*a*f - b*(e + Sqrt[e^2 - 4*d*f]) + 2*(b*f - c*(e + Sqrt[e^2 - 4*d*f]))*x)/(2*Sqrt[4*a*f^2 - 2*b*f*(e + Sqrt[e^2 - 4*d*f]) + c*(e + Sqrt[e^2 - 4*d*f])^2]*Sqrt[a + b*x + c*x^2])])/(f^2*Sqrt[e^2 - 4*d*f]*Sqrt[4*a*f^2 - 2*b*f*(e + Sqrt[e^2 - 4*d*f]) + c*(e + Sqrt[e^2 - 4*d*f])^2])}
{(A + B*x)*(a + b*x + c*x^2)^(3/2)/(d + e*x + f*x^2), x, 10, -(((A*f*(c*e - b*f) - B*(c*e^2 - c*d*f - b*e*f + a*f^2))*Sqrt[a + b*x + c*x^2])/f^3) - ((2*B*c*e - b*B*f - 2*A*c*f)*(b + 2*c*x)*Sqrt[a + b*x + c*x^2])/(8*c*f^2) + (B*(a + b*x + c*x^2)^(3/2))/(3*f) + ((b^2 - 4*a*c)*(2*B*c*e - b*B*f - 2*A*c*f)*ArcTanh[(b + 2*c*x)/(2*Sqrt[c]*Sqrt[a + b*x + c*x^2])])/(16*c^(3/2)*f^2) + ((A*f*(b^2*f^2 - c*f*(3*b*e - 2*a*f) + 2*c^2*(e^2 - d*f)) - B*(b*f^2*(b*e - a*f) - c*f*(3*b*e^2 - 3*b*d*f - 2*a*e*f) + 2*c^2*(e^3 - 2*d*e*f)))*ArcTanh[(b + 2*c*x)/(2*Sqrt[c]*Sqrt[a + b*x + c*x^2])])/(2*Sqrt[c]*f^4) + (1/(f^4*Sqrt[e^2 - 4*d*f]*Sqrt[4*a*f^2 - 2*b*f*(e - Sqrt[e^2 - 4*d*f]) + c*(e - Sqrt[e^2 - 4*d*f])^2]))*((2*f*(B*d*(c*e - b*f)*(f*(b*e - 2*a*f) - c*(e^2 - 2*d*f)) - A*f*(2*c*d*f*(b*e - a*f) - f^2*(b^2*d - a^2*f) - c^2*d*(e^2 - d*f))) + (e - Sqrt[e^2 - 4*d*f])*(f*(c*e - b*f)*(A*f*(c*d - a*f) - B*d*(c*e - b*f)) + (f*(b*e - a*f) - c*(e^2 - d*f))*(A*f*(c*e - b*f) + B*(f*(b*e - a*f) - c*(e^2 - d*f)))))*ArcTanh[(4*a*f - b*(e - Sqrt[e^2 - 4*d*f]) + 2*(b*f - c*(e - Sqrt[e^2 - 4*d*f]))*x)/(2*Sqrt[4*a*f^2 - 2*b*f*(e - Sqrt[e^2 - 4*d*f]) + c*(e - Sqrt[e^2 - 4*d*f])^2]*Sqrt[a + b*x + c*x^2])]) - (1/(f^4*Sqrt[e^2 - 4*d*f]*Sqrt[4*a*f^2 - 2*b*f*(e + Sqrt[e^2 - 4*d*f]) + c*(e + Sqrt[e^2 - 4*d*f])^2]))*((2*f*(B*d*(c*e - b*f)*(f*(b*e - 2*a*f) - c*(e^2 - 2*d*f)) - A*f*(2*c*d*f*(b*e - a*f) - f^2*(b^2*d - a^2*f) - c^2*d*(e^2 - d*f))) + (e + Sqrt[e^2 - 4*d*f])*(f*(c*e - b*f)*(A*f*(c*d - a*f) - B*d*(c*e - b*f)) + (f*(b*e - a*f) - c*(e^2 - d*f))*(A*f*(c*e - b*f) + B*(f*(b*e - a*f) - c*(e^2 - d*f)))))*ArcTanh[(4*a*f - b*(e + Sqrt[e^2 - 4*d*f]) + 2*(b*f - c*(e + Sqrt[e^2 - 4*d*f]))*x)/(2*Sqrt[4*a*f^2 - 2*b*f*(e + Sqrt[e^2 - 4*d*f]) + c*(e + Sqrt[e^2 - 4*d*f])^2]*Sqrt[a + b*x + c*x^2])])}


(* ::Subsubsection::Closed:: *)
(*m<0*)


{(A + B*x)/(a + b*x + c*x^2)^(1/2)/(d + e*x + f*x^2), x, 3, -(((2*A*f - B*(e - Sqrt[e^2 - 4*d*f]))*ArcTanh[(4*a*f - b*(e - Sqrt[e^2 - 4*d*f]) + 2*(b*f - c*(e - Sqrt[e^2 - 4*d*f]))*x)/(2*Sqrt[4*a*f^2 - 2*b*f*(e - Sqrt[e^2 - 4*d*f]) + c*(e - Sqrt[e^2 - 4*d*f])^2]*Sqrt[a + b*x + c*x^2])])/(Sqrt[e^2 - 4*d*f]*Sqrt[4*a*f^2 - 2*b*f*(e - Sqrt[e^2 - 4*d*f]) + c*(e - Sqrt[e^2 - 4*d*f])^2])) + ((2*A*f - B*(e + Sqrt[e^2 - 4*d*f]))*ArcTanh[(4*a*f - b*(e + Sqrt[e^2 - 4*d*f]) + 2*(b*f - c*(e + Sqrt[e^2 - 4*d*f]))*x)/(2*Sqrt[4*a*f^2 - 2*b*f*(e + Sqrt[e^2 - 4*d*f]) + c*(e + Sqrt[e^2 - 4*d*f])^2]*Sqrt[a + b*x + c*x^2])])/(Sqrt[e^2 - 4*d*f]*Sqrt[4*a*f^2 - 2*b*f*(e + Sqrt[e^2 - 4*d*f]) + c*(e + Sqrt[e^2 - 4*d*f])^2])}
{(A + B*x)/(a + b*x + c*x^2)^(3/2)/(d + e*x + f*x^2), x, 5, (2*(A*(b^2*c*e - 2*a*c^2*e - b^3*f - b*c*(c*d - 3*a*f)) + a*B*(2*c^2*d + b^2*f - c*(b*e + 2*a*f)) - c*(A*b^2*f + 2*c*(A*c*d + a*B*e - a*A*f) - b*(B*c*d + A*c*e + a*B*f))*x))/((b^2 - 4*a*c)*(c^2*d^2 + f*(b^2*d - a*b*e + a^2*f) - c*(b*d*e - a*(e^2 - 2*d*f)))*Sqrt[a + b*x + c*x^2]) - (f*((B*c*d - A*c*e + A*b*f - a*B*f)*(e - Sqrt[e^2 - 4*d*f]) - 2*(B*(c*d*e - b*d*f) + A*(f*(b*e - a*f) - c*(e^2 - d*f))))*ArcTanh[(4*a*f - b*(e - Sqrt[e^2 - 4*d*f]) + 2*(b*f - c*(e - Sqrt[e^2 - 4*d*f]))*x)/(2*Sqrt[4*a*f^2 - 2*b*f*(e - Sqrt[e^2 - 4*d*f]) + c*(e - Sqrt[e^2 - 4*d*f])^2]*Sqrt[a + b*x + c*x^2])])/(Sqrt[e^2 - 4*d*f]*Sqrt[4*a*f^2 - 2*b*f*(e - Sqrt[e^2 - 4*d*f]) + c*(e - Sqrt[e^2 - 4*d*f])^2]*(c^2*d^2 + f*(b^2*d - a*b*e + a^2*f) - c*(b*d*e - a*(e^2 - 2*d*f)))) + (f*((B*c*d - A*c*e + A*b*f - a*B*f)*(e + Sqrt[e^2 - 4*d*f]) - 2*(B*(c*d*e - b*d*f) + A*(f*(b*e - a*f) - c*(e^2 - d*f))))*ArcTanh[(4*a*f - b*(e + Sqrt[e^2 - 4*d*f]) + 2*(b*f - c*(e + Sqrt[e^2 - 4*d*f]))*x)/(2*Sqrt[4*a*f^2 - 2*b*f*(e + Sqrt[e^2 - 4*d*f]) + c*(e + Sqrt[e^2 - 4*d*f])^2]*Sqrt[a + b*x + c*x^2])])/(Sqrt[e^2 - 4*d*f]*Sqrt[4*a*f^2 - 2*b*f*(e + Sqrt[e^2 - 4*d*f]) + c*(e + Sqrt[e^2 - 4*d*f])^2]*(c^2*d^2 + f*(b^2*d - a*b*e + a^2*f) - c*(b*d*e - a*(e^2 - 2*d*f))))}


(* ::Section:: *)
(*Integrands of the form x^m (a+b x+c x^2)^n (d+e x+f x^2)^p when b^2-4 a c=0*)


(* ::Subsection::Closed:: *)
(*Integrands of the form x^m (a^2+2 a b x+b^2 x^2)^(n/2) (d+f x^2)^(p/2)*)


{x^2*Sqrt[a^2 + 2*a*b*x + b^2*x^2]*Sqrt[c + d*x^2], x, 6, -((a*c*x*Sqrt[a^2 + 2*a*b*x + b^2*x^2]*Sqrt[c + d*x^2])/(8*d*(a + b*x))) - (b*c*Sqrt[a^2 + 2*a*b*x + b^2*x^2]*(c + d*x^2)^(3/2))/(30*d^2*(a + b*x)) + (b*x^2*Sqrt[a^2 + 2*a*b*x + b^2*x^2]*(c + d*x^2)^(3/2))/(5*d*(a + b*x)) - ((2*b*c - 5*a*d*x)*Sqrt[a^2 + 2*a*b*x + b^2*x^2]*(c + d*x^2)^(3/2))/(20*d^2*(a + b*x)) - (a*c^2*Sqrt[a^2 + 2*a*b*x + b^2*x^2]*ArcTanh[(Sqrt[d]*x)/Sqrt[c + d*x^2]])/(8*d^(3/2)*(a + b*x))}
{x^1*Sqrt[a^2 + 2*a*b*x + b^2*x^2]*Sqrt[c + d*x^2], x, 5, -((b*c*x*Sqrt[a^2 + 2*a*b*x + b^2*x^2]*Sqrt[c + d*x^2])/(8*d*(a + b*x))) + (Sqrt[a^2 + 2*a*b*x + b^2*x^2]*(c + d*x^2)^(3/2))/(4*d) + (a*Sqrt[a^2 + 2*a*b*x + b^2*x^2]*(c + d*x^2)^(3/2))/(12*d*(a + b*x)) - (b*c^2*Sqrt[a^2 + 2*a*b*x + b^2*x^2]*ArcTanh[(Sqrt[d]*x)/Sqrt[c + d*x^2]])/(8*d^(3/2)*(a + b*x))}
{x^0*Sqrt[a^2 + 2*a*b*x + b^2*x^2]*Sqrt[c + d*x^2], x, 4, (a*x*Sqrt[a^2 + 2*a*b*x + b^2*x^2]*Sqrt[c + d*x^2])/(2*(a + b*x)) + (b*Sqrt[a^2 + 2*a*b*x + b^2*x^2]*(c + d*x^2)^(3/2))/(3*d*(a + b*x)) + (a*c*Sqrt[a^2 + 2*a*b*x + b^2*x^2]*ArcTanh[(Sqrt[d]*x)/Sqrt[c + d*x^2]])/(2*Sqrt[d]*(a + b*x))}
{1/x^1*Sqrt[a^2 + 2*a*b*x + b^2*x^2]*Sqrt[c + d*x^2], x, 6, ((2*a + b*x)*Sqrt[a^2 + 2*a*b*x + b^2*x^2]*Sqrt[c + d*x^2])/(2*(a + b*x)) + (b*c*Sqrt[a^2 + 2*a*b*x + b^2*x^2]*ArcTanh[(Sqrt[d]*x)/Sqrt[c + d*x^2]])/(2*Sqrt[d]*(a + b*x)) - (a*Sqrt[c]*Sqrt[a^2 + 2*a*b*x + b^2*x^2]*ArcTanh[Sqrt[c + d*x^2]/Sqrt[c]])/(a + b*x)}
{1/x^2*Sqrt[a^2 + 2*a*b*x + b^2*x^2]*Sqrt[c + d*x^2], x, 6, -(((a - b*x)*Sqrt[a^2 + 2*a*b*x + b^2*x^2]*Sqrt[c + d*x^2])/(x*(a + b*x))) + (a*Sqrt[d]*Sqrt[a^2 + 2*a*b*x + b^2*x^2]*ArcTanh[(Sqrt[d]*x)/Sqrt[c + d*x^2]])/(a + b*x) - (b*Sqrt[c]*Sqrt[a^2 + 2*a*b*x + b^2*x^2]*ArcTanh[Sqrt[c + d*x^2]/Sqrt[c]])/(a + b*x)}
{1/x^3*Sqrt[a^2 + 2*a*b*x + b^2*x^2]*Sqrt[c + d*x^2], x, 7, -(((2*b*c - a*d*x)*Sqrt[a^2 + 2*a*b*x + b^2*x^2]*Sqrt[c + d*x^2])/(2*c*x*(a + b*x))) - (a*Sqrt[a^2 + 2*a*b*x + b^2*x^2]*(c + d*x^2)^(3/2))/(2*c*x^2*(a + b*x)) + (b*Sqrt[d]*Sqrt[a^2 + 2*a*b*x + b^2*x^2]*ArcTanh[(Sqrt[d]*x)/Sqrt[c + d*x^2]])/(a + b*x) - (a*d*Sqrt[a^2 + 2*a*b*x + b^2*x^2]*ArcTanh[Sqrt[c + d*x^2]/Sqrt[c]])/(2*Sqrt[c]*(a + b*x))}


(* ::Subsection::Closed:: *)
(*Integrands of the form x^m (a^2+2 a b x+b^2 x^2)^(n/2) (d+e x+f x^2)^(p/2)*)


{x^2*Sqrt[a^2 + 2*a*b*x + b^2*x^2]*Sqrt[c + e*x + d*x^2], x, 6, -(((2*a*d*(4*c*d - 5*e^2) - b*(12*c*d*e - 7*e^3))*(e + 2*d*x)*Sqrt[a^2 + 2*a*b*x + b^2*x^2]*Sqrt[c + e*x + d*x^2])/(128*d^4*(a + b*x))) - ((8*b*c*d + 50*a*d*e - 35*b*e^2)*Sqrt[a^2 + 2*a*b*x + b^2*x^2]*(c + e*x + d*x^2)^(3/2))/(240*d^3*(a + b*x)) + (b*x^2*Sqrt[a^2 + 2*a*b*x + b^2*x^2]*(c + e*x + d*x^2)^(3/2))/(5*d*(a + b*x)) - ((4*b*c - (10*a*d - 7*b*e)*x)*Sqrt[a^2 + 2*a*b*x + b^2*x^2]*(c + e*x + d*x^2)^(3/2))/(40*d^2*(a + b*x)) - ((4*c*d - e^2)*(2*a*d*(4*c*d - 5*e^2) - b*(12*c*d*e - 7*e^3))*Sqrt[a^2 + 2*a*b*x + b^2*x^2]*ArcTanh[(e + 2*d*x)/(2*Sqrt[d]*Sqrt[c + e*x + d*x^2])])/(256*d^(9/2)*(a + b*x))}
{x^1*Sqrt[a^2 + 2*a*b*x + b^2*x^2]*Sqrt[c + e*x + d*x^2], x, 5, -(((4*b*c*d + 8*a*d*e - 5*b*e^2)*(e + 2*d*x)*Sqrt[a^2 + 2*a*b*x + b^2*x^2]*Sqrt[c + e*x + d*x^2])/(64*d^3*(a + b*x))) + (Sqrt[a^2 + 2*a*b*x + b^2*x^2]*(c + e*x + d*x^2)^(3/2))/(4*d) + ((2*a*d - 5*b*e)*Sqrt[a^2 + 2*a*b*x + b^2*x^2]*(c + e*x + d*x^2)^(3/2))/(24*d^2*(a + b*x)) - ((4*c*d - e^2)*(4*b*c*d + 8*a*d*e - 5*b*e^2)*Sqrt[a^2 + 2*a*b*x + b^2*x^2]*ArcTanh[(e + 2*d*x)/(2*Sqrt[d]*Sqrt[c + e*x + d*x^2])])/(128*d^(7/2)*(a + b*x))}
{x^0*Sqrt[a^2 + 2*a*b*x + b^2*x^2]*Sqrt[c + e*x + d*x^2], x, 4, ((2*a*d - b*e)*(e + 2*d*x)*Sqrt[a^2 + 2*a*b*x + b^2*x^2]*Sqrt[c + e*x + d*x^2])/(8*d^2*(a + b*x)) + (b*Sqrt[a^2 + 2*a*b*x + b^2*x^2]*(c + e*x + d*x^2)^(3/2))/(3*d*(a + b*x)) + ((2*a*d - b*e)*(4*c*d - e^2)*Sqrt[a^2 + 2*a*b*x + b^2*x^2]*ArcTanh[(e + 2*d*x)/(2*Sqrt[d]*Sqrt[c + e*x + d*x^2])])/(16*d^(5/2)*(a + b*x))}
{1/x^1*Sqrt[a^2 + 2*a*b*x + b^2*x^2]*Sqrt[c + e*x + d*x^2], x, 5, ((4*a*d + b*e + 2*b*d*x)*Sqrt[a^2 + 2*a*b*x + b^2*x^2]*Sqrt[c + e*x + d*x^2])/(4*d*(a + b*x)) + ((4*b*c*d + 4*a*d*e - b*e^2)*Sqrt[a^2 + 2*a*b*x + b^2*x^2]*ArcTanh[(e + 2*d*x)/(2*Sqrt[d]*Sqrt[c + e*x + d*x^2])])/(8*d^(3/2)*(a + b*x)) - (a*Sqrt[c]*Sqrt[a^2 + 2*a*b*x + b^2*x^2]*ArcTanh[(2*c + e*x)/(2*Sqrt[c]*Sqrt[c + e*x + d*x^2])])/(a + b*x)}
{1/x^2*Sqrt[a^2 + 2*a*b*x + b^2*x^2]*Sqrt[c + e*x + d*x^2], x, 5, -(((a - b*x)*Sqrt[a^2 + 2*a*b*x + b^2*x^2]*Sqrt[c + e*x + d*x^2])/(x*(a + b*x))) + ((2*a*d + b*e)*Sqrt[a^2 + 2*a*b*x + b^2*x^2]*ArcTanh[(e + 2*d*x)/(2*Sqrt[d]*Sqrt[c + e*x + d*x^2])])/(2*Sqrt[d]*(a + b*x)) - ((2*b*c + a*e)*Sqrt[a^2 + 2*a*b*x + b^2*x^2]*ArcTanh[(2*c + e*x)/(2*Sqrt[c]*Sqrt[c + e*x + d*x^2])])/(2*Sqrt[c]*(a + b*x))}
{1/x^3*Sqrt[a^2 + 2*a*b*x + b^2*x^2]*Sqrt[c + e*x + d*x^2], x, 6, -(((4*b*c - a*e - 2*a*d*x)*Sqrt[a^2 + 2*a*b*x + b^2*x^2]*Sqrt[c + e*x + d*x^2])/(4*c*x*(a + b*x))) - (a*Sqrt[a^2 + 2*a*b*x + b^2*x^2]*(c + e*x + d*x^2)^(3/2))/(2*c*x^2*(a + b*x)) + (b*Sqrt[d]*Sqrt[a^2 + 2*a*b*x + b^2*x^2]*ArcTanh[(e + 2*d*x)/(2*Sqrt[d]*Sqrt[c + e*x + d*x^2])])/(a + b*x) - ((4*a*c*d + 4*b*c*e - a*e^2)*Sqrt[a^2 + 2*a*b*x + b^2*x^2]*ArcTanh[(2*c + e*x)/(2*Sqrt[c]*Sqrt[c + e*x + d*x^2])])/(8*c^(3/2)*(a + b*x))}


(* ::Subsection::Closed:: *)
(*Integrands of the form x^m (d+e x+f x^2)^(n/2) (a^2+2 a b x^2+b^2 x^4)^(p/2)*)


{x^1*Sqrt[a^2 + 2*a*b*x^2 + b^2*x^4]*Sqrt[c + e*x + d*x^2], x, 11, -((a*e*(e + 2*d*x)*Sqrt[c + e*x + d*x^2]*Sqrt[a^2 + 2*a*b*x^2 + b^2*x^4])/(8*d^2*(a + b*x^2))) + (b*e*(12*c*d - 7*e^2)*(e + 2*d*x)*Sqrt[c + e*x + d*x^2]*Sqrt[a^2 + 2*a*b*x^2 + b^2*x^4])/(128*d^4*(a + b*x^2)) + (a*(c + e*x + d*x^2)^(3/2)*Sqrt[a^2 + 2*a*b*x^2 + b^2*x^4])/(3*d*(a + b*x^2)) - (b*(8*c*d - 35*e^2)*(c + e*x + d*x^2)^(3/2)*Sqrt[a^2 + 2*a*b*x^2 + b^2*x^4])/(240*d^3*(a + b*x^2)) + (b*x^2*(c + e*x + d*x^2)^(3/2)*Sqrt[a^2 + 2*a*b*x^2 + b^2*x^4])/(5*d*(a + b*x^2)) - (b*(4*c + 7*e*x)*(c + e*x + d*x^2)^(3/2)*Sqrt[a^2 + 2*a*b*x^2 + b^2*x^4])/(40*d^2*(a + b*x^2)) - (a*e*(4*c*d - e^2)*Sqrt[a^2 + 2*a*b*x^2 + b^2*x^4]*ArcTanh[(e + 2*d*x)/(2*Sqrt[d]*Sqrt[c + e*x + d*x^2])])/(16*d^(5/2)*(a + b*x^2)) + (b*e*(12*c*d - 7*e^2)*(4*c*d - e^2)*Sqrt[a^2 + 2*a*b*x^2 + b^2*x^4]*ArcTanh[(e + 2*d*x)/(2*Sqrt[d]*Sqrt[c + e*x + d*x^2])])/(256*d^(9/2)*(a + b*x^2))}
{x^0*Sqrt[a^2 + 2*a*b*x^2 + b^2*x^4]*Sqrt[c + e*x + d*x^2], x, 4, -(((4*b*c*d - 16*a*d^2 - 5*b*e^2)*(e + 2*d*x)*Sqrt[c + e*x + d*x^2]*Sqrt[a^2 + 2*a*b*x^2 + b^2*x^4])/(64*d^3*(a + b*x^2))) - (b*(5*e - 6*d*x)*(c + e*x + d*x^2)^(3/2)*Sqrt[a^2 + 2*a*b*x^2 + b^2*x^4])/(24*d^2*(a + b*x^2)) - ((4*c*d - e^2)*(4*b*c*d - 16*a*d^2 - 5*b*e^2)*Sqrt[a^2 + 2*a*b*x^2 + b^2*x^4]*ArcTanh[(e + 2*d*x)/(2*Sqrt[d]*Sqrt[c + e*x + d*x^2])])/(128*d^(7/2)*(a + b*x^2))}
{1/x^1*Sqrt[a^2 + 2*a*b*x^2 + b^2*x^4]*Sqrt[c + e*x + d*x^2], x, 10, (a*Sqrt[c + e*x + d*x^2]*Sqrt[a^2 + 2*a*b*x^2 + b^2*x^4])/(a + b*x^2) - (b*e*(e + 2*d*x)*Sqrt[c + e*x + d*x^2]*Sqrt[a^2 + 2*a*b*x^2 + b^2*x^4])/(8*d^2*(a + b*x^2)) + (b*(c + e*x + d*x^2)^(3/2)*Sqrt[a^2 + 2*a*b*x^2 + b^2*x^4])/(3*d*(a + b*x^2)) + (a*e*Sqrt[a^2 + 2*a*b*x^2 + b^2*x^4]*ArcTanh[(e + 2*d*x)/(2*Sqrt[d]*Sqrt[c + e*x + d*x^2])])/(2*Sqrt[d]*(a + b*x^2)) - (b*e*(4*c*d - e^2)*Sqrt[a^2 + 2*a*b*x^2 + b^2*x^4]*ArcTanh[(e + 2*d*x)/(2*Sqrt[d]*Sqrt[c + e*x + d*x^2])])/(16*d^(5/2)*(a + b*x^2)) - (a*Sqrt[c]*Sqrt[a^2 + 2*a*b*x^2 + b^2*x^4]*ArcTanh[(2*c + e*x)/(2*Sqrt[c]*Sqrt[c + e*x + d*x^2])])/(a + b*x^2)}
{1/x^2*Sqrt[a^2 + 2*a*b*x^2 + b^2*x^4]*Sqrt[c + e*x + d*x^2], x, 9, -((a*Sqrt[c + e*x + d*x^2]*Sqrt[a^2 + 2*a*b*x^2 + b^2*x^4])/(x*(a + b*x^2))) + (b*(e + 2*d*x)*Sqrt[c + e*x + d*x^2]*Sqrt[a^2 + 2*a*b*x^2 + b^2*x^4])/(4*d*(a + b*x^2)) + (a*Sqrt[d]*Sqrt[a^2 + 2*a*b*x^2 + b^2*x^4]*ArcTanh[(e + 2*d*x)/(2*Sqrt[d]*Sqrt[c + e*x + d*x^2])])/(a + b*x^2) + (b*(4*c*d - e^2)*Sqrt[a^2 + 2*a*b*x^2 + b^2*x^4]*ArcTanh[(e + 2*d*x)/(2*Sqrt[d]*Sqrt[c + e*x + d*x^2])])/(8*d^(3/2)*(a + b*x^2)) - (a*e*Sqrt[a^2 + 2*a*b*x^2 + b^2*x^4]*ArcTanh[(2*c + e*x)/(2*Sqrt[c]*Sqrt[c + e*x + d*x^2])])/(2*Sqrt[c]*(a + b*x^2))}
{1/x^3*Sqrt[a^2 + 2*a*b*x^2 + b^2*x^4]*Sqrt[c + e*x + d*x^2], x, 9, (b*Sqrt[c + e*x + d*x^2]*Sqrt[a^2 + 2*a*b*x^2 + b^2*x^4])/(a + b*x^2) - (a*(2*c + e*x)*Sqrt[c + e*x + d*x^2]*Sqrt[a^2 + 2*a*b*x^2 + b^2*x^4])/(4*c*x^2*(a + b*x^2)) + (b*e*Sqrt[a^2 + 2*a*b*x^2 + b^2*x^4]*ArcTanh[(e + 2*d*x)/(2*Sqrt[d]*Sqrt[c + e*x + d*x^2])])/(2*Sqrt[d]*(a + b*x^2)) - (b*Sqrt[c]*Sqrt[a^2 + 2*a*b*x^2 + b^2*x^4]*ArcTanh[(2*c + e*x)/(2*Sqrt[c]*Sqrt[c + e*x + d*x^2])])/(a + b*x^2) - (a*(4*c*d - e^2)*Sqrt[a^2 + 2*a*b*x^2 + b^2*x^4]*ArcTanh[(2*c + e*x)/(2*Sqrt[c]*Sqrt[c + e*x + d*x^2])])/(8*c^(3/2)*(a + b*x^2))}
{1/x^4*Sqrt[a^2 + 2*a*b*x^2 + b^2*x^4]*Sqrt[c + e*x + d*x^2], x, 10, -((b*Sqrt[c + e*x + d*x^2]*Sqrt[a^2 + 2*a*b*x^2 + b^2*x^4])/(x*(a + b*x^2))) + (a*e*(2*c + e*x)*Sqrt[c + e*x + d*x^2]*Sqrt[a^2 + 2*a*b*x^2 + b^2*x^4])/(8*c^2*x^2*(a + b*x^2)) - (a*(c + e*x + d*x^2)^(3/2)*Sqrt[a^2 + 2*a*b*x^2 + b^2*x^4])/(3*c*x^3*(a + b*x^2)) + (b*Sqrt[d]*Sqrt[a^2 + 2*a*b*x^2 + b^2*x^4]*ArcTanh[(e + 2*d*x)/(2*Sqrt[d]*Sqrt[c + e*x + d*x^2])])/(a + b*x^2) - (b*e*Sqrt[a^2 + 2*a*b*x^2 + b^2*x^4]*ArcTanh[(2*c + e*x)/(2*Sqrt[c]*Sqrt[c + e*x + d*x^2])])/(2*Sqrt[c]*(a + b*x^2)) + (a*e*(4*c*d - e^2)*Sqrt[a^2 + 2*a*b*x^2 + b^2*x^4]*ArcTanh[(2*c + e*x)/(2*Sqrt[c]*Sqrt[c + e*x + d*x^2])])/(16*c^(5/2)*(a + b*x^2))}
