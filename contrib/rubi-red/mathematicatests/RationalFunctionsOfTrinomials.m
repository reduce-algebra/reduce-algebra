(* ::Package:: *)

(* ::Title:: *)
(*Rational Function Integration Problems Involving Trinomials*)


(* ::Subsection::Closed:: *)
(*Integrands involving polynomials*)


(* ::Subsubsection::Closed:: *)
(*Constants*)


{0, x, 1, 0}
{1, x, 1, x}
{5, x, 1, 5*x}
{-2, x, 1, -2*x}
{-3/2, x, 1, -3/2*x}
{Pi, x, 1, Pi*x}
{a, x, 1, a*x}
{3*a, x, 1, 3*a*x}
{Pi/Sqrt[16 - E^2], x, 1, (Pi*x)/Sqrt[16 - E^2]}


(* ::Subsubsection::Closed:: *)
(*Monomials*)


{x, x, 1, x^2/2}
{x^2, x, 1, x^3/3}
{x^3, x, 1, x^4/4}
{x^100, x, 1, x^101/101}
{1/x, x, 1, Log[x]}
{1/x^2, x, 1, -1/x}
{1/x^3, x, 1, -1/(2*x^2)}
{1/x^100, x, 1, -1/(99*x^99)}

{Sqrt[x], x, 1, 2*x^(3/2)/3}
{x^(3/2), x, 1, 2*x^(5/2)/5}
{x^(5/2), x, 1, 2*x^(7/2)/7}
{1/Sqrt[x], x, 1, 2*Sqrt[x]}
{1/x^(3/2), x, 1, -2/Sqrt[x]}
{1/x^(5/2), x, 1, -2/(3*x^(3/2))}

{x^(1/3), x, 1, (3/4)*x^(4/3)}
{x^(2/3), x, 1, (3/5)*x^(5/3)}

{x^n, x, 1, x^(1+n)/(1+n)}


(* ::Subsubsection::Closed:: *)
(*Fully expanded polynomials*)


{a + b*x + c*x^2 + d*x^3, x, 1, a*x + (b*x^2)/2 + (c*x^3)/3 + (d*x^4)/4}
{-x^3 + x^4, x, 1, -(x^4/4) + x^5/5}
{-1 + x^5, x, 1, -x + x^6/6}
{7 + 4*x, x, 1, 7*x + 2*x^2}
{4*x + Pi*x^3, x, 1, 2*x^2 + (Pi*x^4)/4}
{2*x + 5*x^2, x, 1, x^2 + (5*x^3)/3}
{x^2/2 + x^3/3, x, 1, x^3/6 + x^4/12}
{3 - 5*x + 2*x^2, x, 1, 3*x - (5*x^2)/2 + (2*x^3)/3}
{-2*x + x^2 + x^3, x, 1, -x^2 + x^3/3 + x^4/4}
{1 - x^2 - 3*x^5, x, 1, x - x^3/3 - x^6/2}
{5 + 2*x + 3*x^2 + 4*x^3, x, 1, 5*x + x^2 + x^3 + x^4}


(* ::Subsubsection::Closed:: *)
(*Fully expanded monomial sums*)


(* Integrands of the form a*x^m + b*x^n + ... where m and n are rationals *)
{a + b/x + c/x^2 + d/x^3, x, 1, -(d/(2*x^2)) - c/x + a*x + b*Log[x]}
{x^(-5) + x + x^5, x, 1, -(1/(4*x^4)) + x^2/2 + x^6/6}
{x^(-3) + x^(-2) + x^(-1), x, 1, -(1/(2*x^2)) - 1/x + Log[x]}
{-2/x^2 + 3/x, x, 1, 2/x + 3*Log[x]}
{-1/(7*x^6) + x^6, x, 1, 1/(35*x^5) + x^7/7}
{1 + x^(-1) + x, x, 1, x + x^2/2 + Log[x]}
{-3/x^3 + 4/x^2, x, 1, 3/(2*x^2) - 4/x}
{x^(-1) + 2*x + x^2, x, 1, x^2 + x^3/3 + Log[x]}

{(a/x + b*x)^2, x, 3, -(a^2/x) + 2*a*b*x + (b^2*x^3)/3}
{(a/x + b*x)^3, x, 3, -(a^3/(2*x^2)) + (3/2)*a*b^2*x^2 + (b^3*x^4)/4 + 3*a^2*b*Log[x]}
{(a/x + b*x)^4, x, 3, -(a^4/(3*x^3)) - (4*a^3*b)/x + 6*a^2*b^2*x + (4/3)*a*b^3*x^3 + (b^4*x^5)/5}


(* Integrands of the form a*x^m + b*x^n + ... where m and n are rationals *)
{x^(5/6) - x^3, x, 1, (6*x^(11/6))/11 - x^4/4}
{33 + x^(1/33), x, 1, 33*x + (33*x^(34/33))/34}
{1/(2*Sqrt[x]) + 2*Sqrt[x], x, 1, Sqrt[x] + (4*x^(3/2))/3}
{-x^(-2) + 10/x + 6*Sqrt[x], x, 1, x^(-1) + 4*x^(3/2) + 10*Log[x]}
{x^(-3/2) + x^(3/2), x, 1, -(2/Sqrt[x]) + (2*x^(5/2))/5}
{-5*x^(3/2) + 7*x^(5/2), x, 1, -2*x^(5/2) + 2*x^(7/2)}
{2/Sqrt[x] + Sqrt[x] - x/2, x, 1, 4*Sqrt[x] + (2*x^(3/2))/3 - x^2/4}
{-2/x + Sqrt[x]/5 + x^(3/2), x, 1, (2*x^(3/2))/15 + (2*x^(5/2))/5 - 2*Log[x]}


(* ::Subsubsection::Closed:: *)
(*Products of polynomials and their derivative*)


(* Integrands of the form x^(n-1)*(a+b*x^n)^m *)
{x^(n - 1)*(a + b*x^n)^m, x, 2, (a + b*x^n)^(1 + m)/(b*(1 + m)*n)}
{x^2*(a + b*x^3)^m, x, 2, (a + b*x^3)^(1 + m)/(3*b*(1 + m))}

{x^(n - 1)*(a + b*x^n)^16, x, 2, (a + b*x^n)^17/(17*b*n)}
{x^2*(a + b*x^3)^16, x, 2, (a + b*x^3)^17/(51*b)}


(* Integrands of the form (b+2*c*x)*(a+b*x+c*x^2)^m *)
{(b + 2*c*x)*(a + b*x + c*x^2)^m, x, 1, (a + b*x + c*x^2)^(1 + m)/(1 + m)}
{(b + 2*c*x)*(b*x + c*x^2)^m, x, 1, (b*x + c*x^2)^(1 + m)/(1 + m)}
{x^m*(b + 2*c*x)*(b + c*x)^m, x, 1, (x^(1 + m)*(b + c*x)^(1 + m))/(1 + m)}

{(b + 2*c*x)*(a + b*x + c*x^2)^12, x, 1, (1/13)*(a + b*x + c*x^2)^13}
{(b + 2*c*x)*(b*x + c*x^2)^12, x, 1, (1/13)*x^13*(b + c*x)^13}
{x^12*(b + 2*c*x)*(b + c*x)^12, x, 1, (1/13)*x^13*(b + c*x)^13}


(* Products of symbolic powers of a polynomial and the polynomial's derivative *)
{(b + 2*c*x + 3*d*x^2)*(a + b*x + c*x^2 + d*x^3)^n, x, 2, (a + b*x + c*x^2 + d*x^3)^(1 + n)/(1 + n)}
{(b + 2*c*x + 3*d*x^2)*(b*x + c*x^2 + d*x^3)^n, x, 2, (b*x + c*x^2 + d*x^3)^(1 + n)/(1 + n)}
{(b + 2*c*x + 3*d*x^2)*x^n*(b + c*x + d*x^2)^n, x, 1, (x^(1 + n)*(b + c*x + d*x^2)^(1 + n))/(1 + n)}

{(b + 3*d*x^2)*(a + b*x + d*x^3)^n, x, 2, (a + b*x + d*x^3)^(1 + n)/(1 + n)}
{(b + 3*d*x^2)*(b*x + d*x^3)^n, x, 2, (b*x + d*x^3)^(1 + n)/(1 + n)}
{(b + 3*d*x^2)*x^n*(b + d*x^2)^n, x, 1, (x^(1 + n)*(b + d*x^2)^(1 + n))/(1 + n)}

{(2*c*x + 3*d*x^2)*(a + c*x^2 + d*x^3)^n, x, 2, (a + c*x^2 + d*x^3)^(1 + n)/(1 + n)}
{(2*c*x + 3*d*x^2)*(c*x^2 + d*x^3)^n, x, 2, (c*x^2 + d*x^3)^(1 + n)/(1 + n)}
{(2*c*x + 3*d*x^2)*x^n*(c*x + d*x^2)^n, x, 1, (x^(1 + n)*(c*x + d*x^2)^(1 + n))/(1 + n)}
{(2*c*x + 3*d*x^2)*x^(2*n)*(c + d*x)^n, x, 1, (x^(2 + 2*n)*(c + d*x)^(1 + n))/(1 + n)}

{x*(2*c + 3*d*x)*(a + c*x^2 + d*x^3)^n, x, 2, (a + c*x^2 + d*x^3)^(1 + n)/(1 + n)}
{x*(2*c + 3*d*x)*(c*x^2 + d*x^3)^n, x, 2, (c*x^2 + d*x^3)^(1 + n)/(1 + n)}
{x^(n+1)*(2*c + 3*d*x)*(c*x + d*x^2)^n, x, 1, (x^(1 + n)*(c*x + d*x^2)^(1 + n))/(1 + n)}
{x^(2*n+1)*(2*c + 3*d*x)*(c + d*x)^n, x, 1, (x^(2 + 2*n)*(c + d*x)^(1 + n))/(1 + n)}
{x^m*(a + b*x^n)^p*(a*(m + q + 1)*x^q + b*(m + q + n*(p + 1) + 1)*x^(n + q)), x, 1, x^(1 + m + q)*(a + b*x^n)^(1 + p)}


(* Products of integer powers of a polynomial and the polynomial's derivative *)
{(b + 2*c*x + 3*d*x^2)*(a + b*x + c*x^2 + d*x^3)^7, x, 2, (1/8)*(a + b*x + c*x^2 + d*x^3)^8}
{(b + 2*c*x + 3*d*x^2)*(b*x + c*x^2 + d*x^3)^7, x, 2, (1/8)*x^8*(b + c*x + d*x^2)^8}
{(b + 2*c*x + 3*d*x^2)*x^7*(b + c*x + d*x^2)^7, x, 1, (1/8)*x^8*(b + c*x + d*x^2)^8}

{(b + 3*d*x^2)*(a + b*x + d*x^3)^7, x, 2, (1/8)*(a + b*x + d*x^3)^8}
{(b + 3*d*x^2)*(b*x + d*x^3)^7, x, 2, (1/8)*x^8*(b + d*x^2)^8}
{(b + 3*d*x^2)*x^7*(b + d*x^2)^7, x, 1, (1/8)*x^8*(b + d*x^2)^8}

{(2*c*x + 3*d*x^2)*(a + c*x^2 + d*x^3)^7, x, 2, (1/8)*(a + c*x^2 + d*x^3)^8}
{(2*c*x + 3*d*x^2)*(c*x^2 + d*x^3)^7, x, 2, (1/8)*x^16*(c + d*x)^8}
{(2*c*x + 3*d*x^2)*x^7*(c*x + d*x^2)^7, x, 1, (1/8)*x^16*(c + d*x)^8}
{(2*c*x + 3*d*x^2)*x^14*(c + d*x)^7, x, 1, (x^(2 + 2*7)*(c + d*x)^8)/8}

{x*(2*c + 3*d*x)*(a + c*x^2 + d*x^3)^7, x, 2, (a + c*x^2 + d*x^3)^8/8}
{x*(2*c + 3*d*x)*(c*x^2 + d*x^3)^7, x, 2, (1/8)*x^16*(c + d*x)^8}
{x^8*(2*c + 3*d*x)*(c*x + d*x^2)^7, x, 1, (1/8)*x^16*(c + d*x)^8}
{x^15*(2*c + 3*d*x)*(c + d*x)^7, x, 1, (x^(2 + 2*7)*(c + d*x)^8)/8}

{(-4 + 4*x + x^2)*(5 - 12*x + 6*x^2 + x^3), x, 2, (5 - 12*x + 6*x^2 + x^3)^2/6}
{(2*x + x^3)*(1 + 4*x^2 + x^4), x, 2, (1/8)*(1 + 4*x^2 + x^4)^2}

{(1 + 2*x)*(x + x^2)^3*(-18 + 7*(x + x^2)^3)^2, x, 3, 81*x^4*(1 + x)^4 - 36*x^7*(1 + x)^7 + (49/10)*x^10*(1 + x)^10}
{x^3*(1 + x)^3*(1 + 2*x)*(-18 + 7*x^3*(1 + x)^3)^2, x, 2, 81*x^4*(1 + x)^4 - 36*x^7*(1 + x)^7 + (49/10)*x^10*(1 + x)^10, 81*x^4 + 324*x^5 + 486*x^6 + 288*x^7 - 171*x^8 - 756*x^9 - (12551*x^10)/10 - 1211*x^11 - (1071*x^12)/2 + 336*x^13 + 993*x^14 + (6174*x^15)/5 + 1029*x^16 + 588*x^17 + (441*x^18)/2 + 49*x^19 + (49*x^20)/10}


(* ::Subsubsection::Closed:: *)
(*Disguised derivative divides examples*)


(* Integrands of the form x^(12*m)*(a + b*x^(12*m+1))^12 *)
{x^12*(a + b*x^13)^12, x, 2, (a + b*x^13)^13/(169*b)}
{x^24*(a + b*x^25)^12, x, 2, (a + b*x^25)^13/(325*b)}
{x^36*(a + b*x^37)^12, x, 2, (a + b*x^37)^13/(481*b)}
{x^(12*m)*(a + b*x^(12*m + 1))^12, x, 2, (a + b*x^(1 + 12*m))^13/(13*b*(1 + 12*m))}

(* Integrands of the form x^(12*(m-1))*(a*x + b*x^(12*m+2))^12 *)
{(a*x + b*x^14)^12, x, 3, (a + b*x^13)^13/(169*b)}
{x^12*(a*x + b*x^26)^12, x, 3, (a + b*x^25)^13/(325*b)}
{x^24*(a*x + b*x^38)^12, x, 3, (a + b*x^37)^13/(481*b)}
{x^(12*(m-1))*(a*x + b*x^(12*m + 2))^12, x, 3, (a + b*x^(1 + 12*m))^13/(13*b*(1 + 12*m))}

(* Integrands of the form (a*x^m + b*x^(12*m+m+1))^12 *)
{(a*x + b*x^14)^12, x, 3, (a + b*x^13)^13/(169*b)}
{(a*x^2 + b*x^27)^12, x, 3, (a + b*x^25)^13/(325*b)}
{(a*x^3 + b*x^40)^12, x, 3, (a + b*x^37)^13/(481*b)}
{(a*x^m + b*x^(12*m + m + 1))^12, x, 3, (a + b*x^(1 + 12*m))^13/(13*b*(1 + 12*m))}


(* Integrands of the form x^p*(a*x^n+b*x^(m*n+n+p+1))^m *)
{x^p*(a*x^n + b*x^(12*n + n + p + 1))^12, x, 3, (a + b*x^(1 + 12*n + p))^13/(13*b*(1 + 12*n + p))}

{x^12*(a + b*x^13)^12, x, 2, (a + b*x^13)^13/(169*b)}
{x^12*(a*x + b*x^26)^12, x, 3, (a + b*x^25)^13/(325*b)}
{x^12*(a*x^2 + b*x^39)^12, x, 3, (a + b*x^37)^13/(481*b)}

{x^24*(a + b*x^25)^12, x, 2, (a + b*x^25)^13/(325*b)}
{x^24*(a*x + b*x^38)^12, x, 3, (a + b*x^37)^13/(481*b)}

{x^36*(a + b*x^37)^12, x, 2, (a + b*x^37)^13/(481*b)}


(* ::Subsubsection::Closed:: *)
(*Miscellaneous polynomial expressions*)


{x^2*(2 + x)^5*(2 + 3*x), x, 1, (1/3)*x^3*(2 + x)^6}
{(5 - 2*x)^6*(2 + 3*x)^3*(-16 + 33*x), x, 1, (-(1/2))*(5 - 2*x)^7*(2 + 3*x)^4}


(* Integrands of the form x^m*(a+b*x)^n*(c+d*x)^p *)
{x*(a + b*x)*(c + d*x)^16, x, 3, ((b*c - 18*a*d)*(2*b*c + 17*a*d)*(c + d*x)^17)/(5814*b*d^3) - ((2*b*c + 17*a*d)*x*(c + d*x)^17)/(342*d^2) + ((a + b*x)^2*(c + d*x)^17)/(19*b*d)}
{x*(a + b*x)^2*(c + d*x)^16, x, 4, -(((b*c - a*d)^2*(3*b*c + 17*a*d)*(c + d*x)^17)/(58140*b*d^4)) + ((b*c - a*d)*(3*b*c + 17*a*d)*(a + b*x)*(c + d*x)^17)/(3420*b*d^3) - ((3*b*c + 17*a*d)*(a + b*x)^2*(c + d*x)^17)/(380*b*d^2) + ((a + b*x)^3*(c + d*x)^17)/(20*b*d)}
{x^2*(a + b*x)*(c + d*x)^16, x, 6, (a*c*(b*c - 18*a*d)*(c + d*x)^17)/(6120*b*d^3) - ((b*c - 18*a*d)*(b*c + 6*a*d)*(2*b*c + 17*a*d)*(c + d*x)^17)/(38760*b^2*d^4) - (a*c*x*(c + d*x)^17)/(360*d^2) + ((b*c + 6*a*d)*(2*b*c + 17*a*d)*x*(c + d*x)^17)/(2280*b*d^3) - (3*(b*c + 6*a*d)*(a + b*x)^2*(c + d*x)^17)/(380*b^2*d^2) + (x*(a + b*x)^2*(c + d*x)^17)/(20*b*d)}
(* {x^2*(a + b*x)^2*(c + d*x)^16, x, 8, -((a*c*(b*c - a*d)^2*(c + d*x)^17)/(61047*b*d^4)) + ((b*c - a*d)^2*(2*b*c + 9*a*d)*(3*b*c + 17*a*d)*(c + d*x)^17)/(610470*b^2*d^5) + (a*c*(b*c - a*d)*(a + b*x)*(c + d*x)^17)/(3591*b*d^3) - ((b*c - a*d)*(2*b*c + 9*a*d)*(3*b*c + 17*a*d)*(a + b*x)*(c + d*x)^17)/(35910*b^2*d^4) - (a*c*(a + b*x)^2*(c + d*x)^17)/(399*b*d^2) + ((2*b*c + 9*a*d)*(3*b*c + 17*a*d)*(a + b*x)^2*(c + d*x)^17)/(3990*b^2*d^3) - ((2*b*c + 9*a*d)*(a + b*x)^3*(c + d*x)^17)/(210*b^2*d^2) + (x*(a + b*x)^3*(c + d*x)^17)/(21*b*d)} *)


{(a + b*x)*(1 + (a*x + b*(x^2/2))^4), x, 2, a*x + (b*x^2)/2 + (1/160)*x^5*(2*a + b*x)^5}
{(a + b*x)*(1 + (c + a*x + b*(x^2/2))^4), x, 2, c + a*x + (b*x^2)/2 + (1/160)*(2*c + 2*a*x + b*x^2)^5}

{(a + b*x)*(1 + (a*x + b*(x^2/2))^n), x, 2, a*x + (b*x^2)/2 + (2^(-1 - n)*(2*a*x + b*x^2)^(1 + n))/(1 + n)}
{(a + b*x)*(1 + (c + a*x + b*(x^2/2))^n), x, 2, c + a*x + (b*x^2)/2 + (2^(-1 - n)*(2*c + 2*a*x + b*x^2)^(1 + n))/(1 + n)}

{(a + c*x^2)*(1 + (a*x + c*(x^3/3))^5), x, 2, a*x + (c*x^3)/3 + (x^6*(3*a + c*x^2)^6)/4374}
{(a + c*x^2)*(1 + (d + a*x + c*(x^3/3))^5), x, 2, d + a*x + (c*x^3)/3 + (3*d + 3*a*x + c*x^3)^6/4374}

{(b*x + c*x^2)*(1 + (b*(x^2/2) + c*(x^3/3))^5), x, 2, (b*x^2)/2 + (c*x^3)/3 + (x^12*(3*b + 2*c*x)^6)/279936}
{(b*x + c*x^2)*(1 + (d + b*(x^2/2) + c*(x^3/3))^5), x, 2, d + (b*x^2)/2 + (c*x^3)/3 + (6*d + 3*b*x^2 + 2*c*x^3)^6/279936}

{(a + b*x + c*x^2)*(1 + (a*x + b*(x^2/2) + c*(x^3/3))^5), x, 2, a*x + (b*x^2)/2 + (c*x^3)/3 + (x^6*(6*a + 3*b*x + 2*c*x^2)^6)/279936}
{(a + b*x + c*x^2)*(1 + (d + a*x + b*(x^2/2) + c*(x^3/3))^5), x, 2, d + a*x + (b*x^2)/2 + (c*x^3)/3 + (6*d + 6*a*x + 3*b*x^2 + 2*c*x^3)^6/279936}

{(a + c*x^2)*(1 + (a*x + c*(x^3/3))^n), x, 2, a*x + (c*x^3)/3 + (3^(-1 - n)*(3*a*x + c*x^3)^(1 + n))/(1 + n)}
{(b*x + c*x^2)*(1 + (b*(x^2/2) + c*(x^3/3))^n), x, 2, (b*x^2)/2 + (c*x^3)/3 + (6^(-1 - n)*(3*b*x^2 + 2*c*x^3)^(1 + n))/(1 + n)}
{(a + b*x + c*x^2)*(1 + (a*x + b*(x^2/2) + c*(x^3/3))^n), x, 2, a*x + (b*x^2)/2 + (c*x^3)/3 + (6^(-1 - n)*(6*a*x + 3*b*x^2 + 2*c*x^3)^(1 + n))/(1 + n)}


(* Integrands of the form f[x^m*(a+b*x^n)^p] where m==-n*p *)
(* Test to ensure NormalForm does not result in infinite recursion *)
{f[(a + b*x)/x], x, 1, Int[f[b + a/x], x]}
{f[(a + b*x^2)/x^2], x, 1, Int[f[b + a/x^2], x]}
{f[x/(a + b*x)], x, 1, Int[f[1/(b + a/x)], x]}
{f[x^2/(a + b*x^2)], x, 1, Int[f[1/(b + a/x^2)], x]}
{f[x^2/(a + b*x)^2], x, 2, -Subst[Int[f[1/(b + a*x)^2]/x^2, x], x, 1/x]}
{f[x^4/(a + b*x^2)^2], x, 1, Int[f[1/(b + a/x^2)^2], x]}


{(2 + 3*x)^6*(1 + (2 + 3*x)^7 + (2 + 3*x)^14), x, 2, (1/21)*(2 + 3*x)^7 + (1/42)*(2 + 3*x)^14 + (1/63)*(2 + 3*x)^21}
{(2 + 3*x)^6*(1 + (2 + 3*x)^7 + (2 + 3*x)^14)^2, x, 3, (1/21)*(2 + 3*x)^7 + (1/21)*(2 + 3*x)^14 + (1/21)*(2 + 3*x)^21 + (1/42)*(2 + 3*x)^28 + (1/105)*(2 + 3*x)^35}


(* Miscellaneous polynomial integrands *)
{c*(a + b*x), x, 1, (c*(a + b*x)^2)/(2*b)}
{((c + d)*(a + b*x))/e, x, 1, ((c + d)*(a + b*x)^2)/(2*b*e)}
{(2 + x)*(3 + x), x, 2, 6*x + (5*x^2)/2 + x^3/3}
{(-4*x + 3*x^3)^6, x, 3, (4096*x^7)/7 - 2048*x^9 + (34560*x^11)/11 - (34560*x^13)/13 + 1296*x^15 - (5832*x^17)/17 + (729*x^19)/19}
{x^8*(a + b*x^7), x, 2, (a*x^9)/9 + (b*x^16)/16}
{x^2*(a + b*x^2)^3, x, 2, (a^3*x^3)/3 + (3*a^2*b*x^5)/5 + (3*a*b^2*x^7)/7 + (b^3*x^9)/9}
{x*(a + b*x + c*x^2), x, 2, (a*x^2)/2 + (b*x^3)/3 + (c*x^4)/4}
{x^6*(-4 + 3*x^2), x, 2, (-4*x^7)/7 + x^9/3}


(* ::Subsection::Closed:: *)
(*Integrands involving powers of quadratic trinomials*)


(* ::Subsubsection::Closed:: *)
(*Integrands of the form x^m (a+b x+c x^2)^n*)


(* Integrands of the form x^m*(a+b*x+c*x^2) where m is an integer *)
{x^4*(a + b*x + c*x^2), x, 2, (a*x^5)/5 + (b*x^6)/6 + (c*x^7)/7}
{x^3*(a + b*x + c*x^2), x, 2, (a*x^4)/4 + (b*x^5)/5 + (c*x^6)/6}
{x^2*(a + b*x + c*x^2), x, 2, (a*x^3)/3 + (b*x^4)/4 + (c*x^5)/5}
{x*(a + b*x + c*x^2), x, 2, (a*x^2)/2 + (b*x^3)/3 + (c*x^4)/4}
{a + b*x + c*x^2, x, 1, a*x + (b*x^2)/2 + (c*x^3)/3}
{a + x*(b + c*x), x, 3, a*x + (b*x^2)/2 + (c*x^3)/3}
{(a + b*x + c*x^2)/x, x, 2, b*x + (c*x^2)/2 + a*Log[x]}
{(a + b*x + c*x^2)/x^2, x, 2, -(a/x) + c*x + b*Log[x]}
{(a + b*x + c*x^2)/x^3, x, 2, -(a/(2*x^2)) - b/x + c*Log[x]}
{(a + b*x + c*x^2)/x^4, x, 2, -(a/(3*x^3)) - b/(2*x^2) - c/x}


(* Integrands of the form x^m*(a+b*x+c*x^2)^2 where m is an integer *)
{x^4*(a + b*x + c*x^2)^2, x, 2, (a^2*x^5)/5 + (1/3)*a*b*x^6 + (1/7)*(b^2 + 2*a*c)*x^7 + (1/4)*b*c*x^8 + (c^2*x^9)/9}
{x^3*(a + b*x + c*x^2)^2, x, 2, (a^2*x^4)/4 + (2/5)*a*b*x^5 + (1/6)*(b^2 + 2*a*c)*x^6 + (2/7)*b*c*x^7 + (c^2*x^8)/8}
{x^2*(a + b*x + c*x^2)^2, x, 2, (a^2*x^3)/3 + (1/2)*a*b*x^4 + (1/5)*(b^2 + 2*a*c)*x^5 + (1/3)*b*c*x^6 + (c^2*x^7)/7}
{x*(a + b*x + c*x^2)^2, x, 2, (a^2*x^2)/2 + (2/3)*a*b*x^3 + (1/4)*(b^2 + 2*a*c)*x^4 + (2/5)*b*c*x^5 + (c^2*x^6)/6}
{(a + b*x + c*x^2)^2, x, 2, a^2*x + a*b*x^2 + (1/3)*(b^2 + 2*a*c)*x^3 + (1/2)*b*c*x^4 + (c^2*x^5)/5}
{(a + b*x + c*x^2)^2/x, x, 2, 2*a*b*x + (1/2)*(b^2 + 2*a*c)*x^2 + (2/3)*b*c*x^3 + (c^2*x^4)/4 + a^2*Log[x]}
{(a + b*x + c*x^2)^2/x^2, x, 2, -(a^2/x) + (b^2 + 2*a*c)*x + b*c*x^2 + (c^2*x^3)/3 + 2*a*b*Log[x]}
{(a + b*x + c*x^2)^2/x^3, x, 2, -(a^2/(2*x^2)) - (2*a*b)/x + 2*b*c*x + (c^2*x^2)/2 + (b^2 + 2*a*c)*Log[x]}
{(a + b*x + c*x^2)^2/x^4, x, 2, -(a^2/(3*x^3)) - (a*b)/x^2 - (b^2 + 2*a*c)/x + c^2*x + 2*b*c*Log[x]}
{(a + b*x + c*x^2)^2/x^5, x, 2, -(a^2/(4*x^4)) - (2*a*b)/(3*x^3) - (b^2 + 2*a*c)/(2*x^2) - (2*b*c)/x + c^2*Log[x]}
{(a + b*x + c*x^2)^2/x^6, x, 2, -(a^2/(5*x^5)) - (a*b)/(2*x^4) - (b^2 + 2*a*c)/(3*x^3) - (b*c)/x^2 - c^2/x}
{(a + b*x + c*x^2)^2/x^7, x, 2, -(a^2/(6*x^6)) - (2*a*b)/(5*x^5) - (b^2 + 2*a*c)/(4*x^4) - (2*b*c)/(3*x^3) - c^2/(2*x^2)}


(* Integrands of the form x^m/(a+b*x+c*x^2) where m is an integer *)
{x^4/(a + b*x + c*x^2), x, 5, ((b^2 - a*c)*x)/c^3 - (b*x^2)/(2*c^2) + x^3/(3*c) - ((b^4 - 2*a*c*(2*b^2 - a*c))*ArcTanh[(b + 2*c*x)/Sqrt[b^2 - 4*a*c]])/(c^4*Sqrt[b^2 - 4*a*c]) - (b*(b^2 - 2*a*c)*Log[a + b*x + c*x^2])/(2*c^4)}
{x^3/(a + b*x + c*x^2), x, 5, -((b*x)/c^2) + x^2/(2*c) + (b*(b^2 - 3*a*c)*ArcTanh[(b + 2*c*x)/Sqrt[b^2 - 4*a*c]])/(c^3*Sqrt[b^2 - 4*a*c]) + ((b^2 - a*c)*Log[a + b*x + c*x^2])/(2*c^3)}
{x^2/(a + b*x + c*x^2), x, 4, x/c - ((b^2 - 2*a*c)*ArcTanh[(b + 2*c*x)/Sqrt[b^2 - 4*a*c]])/(c^2*Sqrt[b^2 - 4*a*c]) - (b*Log[a + b*x + c*x^2])/(2*c^2)}
{x/(a + b*x + c*x^2), x, 2, (b*ArcTanh[(b + 2*c*x)/Sqrt[b^2 - 4*a*c]])/(c*Sqrt[b^2 - 4*a*c]) + Log[a + b*x + c*x^2]/(2*c)}
{1/(a + b*x + c*x^2), x, 1, -((2*ArcTanh[(b + 2*c*x)/Sqrt[b^2 - 4*a*c]])/Sqrt[b^2 - 4*a*c])}
{1/(x*(a + b*x + c*x^2)), x, 5, (b*ArcTanh[(b + 2*c*x)/Sqrt[b^2 - 4*a*c]])/(a*Sqrt[b^2 - 4*a*c]) + Log[x]/a - Log[a + b*x + c*x^2]/(2*a)}
{1/(x^2*(a + b*x + c*x^2)), x, 5, -(1/(a*x)) - ((b^2 - 2*a*c)*ArcTanh[(b + 2*c*x)/Sqrt[b^2 - 4*a*c]])/(a^2*Sqrt[b^2 - 4*a*c]) - (b*Log[x])/a^2 + (b*Log[a + b*x + c*x^2])/(2*a^2)}
{1/(x^3*(a + b*x + c*x^2)), x, 5, -(1/(2*a*x^2)) + b/(a^2*x) + (b*(b^2 - 3*a*c)*ArcTanh[(b + 2*c*x)/Sqrt[b^2 - 4*a*c]])/(a^3*Sqrt[b^2 - 4*a*c]) + ((b^2 - a*c)*Log[x])/a^3 - ((b^2 - a*c)*Log[a + b*x + c*x^2])/(2*a^3)}
{1/(x^4*(a + b*x + c*x^2)), x, 5, -(1/(3*a*x^3)) + b/(2*a^2*x^2) - (b^2 - a*c)/(a^3*x) - ((b^4 - 4*a*b^2*c + 2*a^2*c^2)*ArcTanh[(b + 2*c*x)/Sqrt[b^2 - 4*a*c]])/(a^4*Sqrt[b^2 - 4*a*c]) - (b*(b^2 - 2*a*c)*Log[x])/a^4 + (b*(b^2 - 2*a*c)*Log[a + b*x + c*x^2])/(2*a^4)}


(* Integrands of the form x^m/(a+b*x+c*x^2)^2 where m is an integer *)
{x^4/(a + b*x + c*x^2)^2, x, 7, x/c^2 + (b*(b^2 - 2*a*c))/(2*c^4*(a + b*x + c*x^2)) - ((2*a^2*c^2 + b^2*(b^2 - 4*a*c))*(b + 2*c*x))/(2*c^4*(b^2 - 4*a*c)*(a + b*x + c*x^2)) + (4*a^2*ArcTanh[(b + 2*c*x)/Sqrt[b^2 - 4*a*c]])/(c*(b^2 - 4*a*c)^(3/2)) - (4*(b^2/2 - a*c)*ArcTanh[(b + 2*c*x)/Sqrt[b^2 - 4*a*c]])/(c^3*Sqrt[b^2 - 4*a*c]) - (b*Log[a + b*x + c*x^2])/c^3}
{x^3/(a + b*x + c*x^2)^2, x, 7, -((b^2 - a*c)/(2*c^3*(a + b*x + c*x^2))) + (b*(b^2 - 3*a*c)*(b + 2*c*x))/(2*c^3*(b^2 - 4*a*c)*(a + b*x + c*x^2)) + (3*b*ArcTanh[(b + 2*c*x)/Sqrt[b^2 - 4*a*c]])/(c^2*Sqrt[b^2 - 4*a*c]) - (2*b*(b^2 - 3*a*c)*ArcTanh[(b + 2*c*x)/Sqrt[b^2 - 4*a*c]])/(c^2*(b^2 - 4*a*c)^(3/2)) + Log[a + b*x + c*x^2]/(2*c^2)}
{x^2/(a + b*x + c*x^2)^2, x, 3, -(x/(c*(a + b*x + c*x^2))) - (a*(b + 2*c*x))/(c*(b^2 - 4*a*c)*(a + b*x + c*x^2)) + (4*a*ArcTanh[(b + 2*c*x)/Sqrt[b^2 - 4*a*c]])/(b^2 - 4*a*c)^(3/2)}
{x/(a + b*x + c*x^2)^2, x, 3, (2*a + b*x)/((b^2 - 4*a*c)*(a + b*x + c*x^2)) - (2*b*ArcTanh[(b + 2*c*x)/Sqrt[b^2 - 4*a*c]])/(b^2 - 4*a*c)^(3/2)}
{1/(a + b*x + c*x^2)^2, x, 2, -((b + 2*c*x)/((b^2 - 4*a*c)*(a + b*x + c*x^2))) + (4*c*ArcTanh[(b + 2*c*x)/Sqrt[b^2 - 4*a*c]])/(b^2 - 4*a*c)^(3/2)}
{1/(x*(a + b*x + c*x^2)^2), x, 8, 1/(2*a*(a + b*x + c*x^2)) + (b*(b + 2*c*x))/(2*a*(b^2 - 4*a*c)*(a + b*x + c*x^2)) - (2*b*c*ArcTanh[(b + 2*c*x)/Sqrt[b^2 - 4*a*c]])/(a*(b^2 - 4*a*c)^(3/2)) + (b*ArcTanh[(b + 2*c*x)/Sqrt[b^2 - 4*a*c]])/(a^2*Sqrt[b^2 - 4*a*c]) + Log[x]/a^2 - Log[a + b*x + c*x^2]/(2*a^2)}
{1/(x^2*(a + b*x + c*x^2)^2), x, 8, -(1/(a^2*x)) - b/(2*a^2*(a + b*x + c*x^2)) + (((-b^2)*c + 2*c*(b^2 - a*c))*(b + 2*c*x))/(2*a^2*c*(-b^2 + 4*a*c)*(a + b*x + c*x^2)) - (2*(b^4 - 6*a*b^2*c + 6*a^2*c^2)*ArcTanh[(b + 2*c*x)/Sqrt[b^2 - 4*a*c]])/(a^3*(b^2 - 4*a*c)^(3/2)) - (2*b*Log[x])/a^3 + (b*Log[a + b*x + c*x^2])/a^3, -(1/(a^2*x)) - b/(2*a^2*(a + b*x + c*x^2)) - ((b^2 - 2*a*c)*(b + 2*c*x))/(2*a^2*(b^2 - 4*a*c)*(a + b*x + c*x^2)) + (2*c*(b^2 - 2*a*c)*ArcTanh[(b + 2*c*x)/Sqrt[b^2 - 4*a*c]])/(a^2*(b^2 - 4*a*c)^(3/2)) - (2*(b^2 - a*c)*ArcTanh[(b + 2*c*x)/Sqrt[b^2 - 4*a*c]])/(a^3*Sqrt[b^2 - 4*a*c]) - (2*b*Log[x])/a^3 + (b*Log[a + b*x + c*x^2])/a^3}
{1/(x^3*(a + b*x + c*x^2)^2), x, 8, -(1/(2*a^2*x^2)) + (2*b)/(a^3*x) - ((-b^2)*c + a*c^2)/(2*a^3*c*(a + b*x + c*x^2)) + ((2*c*(-b^3 + 2*a*b*c) - b*((-b^2)*c + a*c^2))*(b + 2*c*x))/(2*a^3*c*(-b^2 + 4*a*c)*(a + b*x + c*x^2)) + (b*(3*b^4 - 20*a*b^2*c + 30*a^2*c^2)*ArcTanh[(b + 2*c*x)/Sqrt[b^2 - 4*a*c]])/(a^4*(b^2 - 4*a*c)^(3/2)) + ((3*b^2 - 2*a*c)*Log[x])/a^4 + ((-3*b^2*c + 2*a*c^2)*Log[a + b*x + c*x^2])/(2*a^4*c), -(1/(2*a^2*x^2)) + (2*b)/(a^3*x) + (b^2 - a*c)/(2*a^3*(a + b*x + c*x^2)) + (b*(b^2 - 3*a*c)*(b + 2*c*x))/(2*a^3*(b^2 - 4*a*c)*(a + b*x + c*x^2)) - (2*b*c*(b^2 - 3*a*c)*ArcTanh[(b + 2*c*x)/Sqrt[b^2 - 4*a*c]])/(a^3*(b^2 - 4*a*c)^(3/2)) + (3*b*(b^2 - 2*a*c)*ArcTanh[(b + 2*c*x)/Sqrt[b^2 - 4*a*c]])/(a^4*Sqrt[b^2 - 4*a*c]) + ((3*b^2 - 2*a*c)*Log[x])/a^4 - ((3*b^2 - 2*a*c)*Log[a + b*x + c*x^2])/(2*a^4)}
{1/(x^4*(a + b*x + c*x^2)^2), x, 8, -(1/(3*a^2*x^3)) + b/(a^3*x^2) - (3*b^2 - 2*a*c)/(a^4*x) - (b*(b^2 - 2*a*c))/(2*a^4*(a + b*x + c*x^2)) - ((2*a^2*c^2 + b^2*(b^2 - 4*a*c))*(b + 2*c*x))/(2*a^4*(b^2 - 4*a*c)*(a + b*x + c*x^2)) - (4*(b^4 + a^2*c^2)*ArcTanh[(b + 2*c*x)/Sqrt[b^2 - 4*a*c]])/(a^5*Sqrt[b^2 - 4*a*c]) + (2*c*(2*a^2*c^2 + 7*b^2*(b^2 - 4*a*c))*ArcTanh[(b + 2*c*x)/Sqrt[b^2 - 4*a*c]])/(a^4*(b^2 - 4*a*c)^(3/2)) - (2*b*(2*b^2 - 3*a*c)*Log[x])/a^5 + (b*(2*b^2 - 3*a*c)*Log[a + b*x + c*x^2])/a^5}

(* Integrands of the form x^m/(a+b*x+c*x^2)^3 where m is an integer *)
{x^4/(a + b*x + c*x^2)^3, x, 7, -((a*x)/(c^2*(a + b*x + c*x^2)^2)) - (b*x^2)/(2*c^2*(a + b*x + c*x^2)^2) - x^3/(c*(a + b*x + c*x^2)^2) - (a^2*(b + 2*c*x))/(2*c^2*(b^2 - 4*a*c)*(a + b*x + c*x^2)^2) + (3*a^2*(b + 2*c*x))/(c*(b^2 - 4*a*c)^2*(a + b*x + c*x^2)) - (12*a^2*ArcTanh[(b + 2*c*x)/Sqrt[b^2 - 4*a*c]])/(b^2 - 4*a*c)^(5/2)}
{x^3/(a + b*x + c*x^2)^3, x, 5, -(x^2/(2*c*(a + b*x + c*x^2)^2)) + (a*(2*a + b*x))/(2*c*(b^2 - 4*a*c)*(a + b*x + c*x^2)^2) - (3*a*b*(b + 2*c*x))/(2*c*(b^2 - 4*a*c)^2*(a + b*x + c*x^2)) + (6*a*b*ArcTanh[(b + 2*c*x)/Sqrt[b^2 - 4*a*c]])/(b^2 - 4*a*c)^(5/2)}
{x^2/(a + b*x + c*x^2)^3, x, 5, b/(12*c^2*(a + b*x + c*x^2)^2) - x/(3*c*(a + b*x + c*x^2)^2) - ((b^2 + 2*a*c)*(b + 2*c*x))/(12*c^2*(b^2 - 4*a*c)*(a + b*x + c*x^2)^2) + ((2*a + b^2/c)*(b + 2*c*x))/(2*(b^2 - 4*a*c)^2*(a + b*x + c*x^2)) - (2*(b^2 + 2*a*c)*ArcTanh[(b + 2*c*x)/Sqrt[b^2 - 4*a*c]])/(b^2 - 4*a*c)^(5/2)}
{x/(a + b*x + c*x^2)^3, x, 4, (2*a + b*x)/(2*(b^2 - 4*a*c)*(a + b*x + c*x^2)^2) - (3*b*(b + 2*c*x))/(2*(b^2 - 4*a*c)^2*(a + b*x + c*x^2)) + (6*b*c*ArcTanh[(b + 2*c*x)/Sqrt[b^2 - 4*a*c]])/(b^2 - 4*a*c)^(5/2)}
{1/(a + b*x + c*x^2)^3, x, 3, -((b + 2*c*x)/(2*(b^2 - 4*a*c)*(a + b*x + c*x^2)^2)) + (3*c*(b + 2*c*x))/((b^2 - 4*a*c)^2*(a + b*x + c*x^2)) - (12*c^2*ArcTanh[(b + 2*c*x)/Sqrt[b^2 - 4*a*c]])/(b^2 - 4*a*c)^(5/2)}
{1/(x*(a + b*x + c*x^2)^3), x, 12, 1/(4*a*(a + b*x + c*x^2)^2) + (b*(b + 2*c*x))/(4*a*(b^2 - 4*a*c)*(a + b*x + c*x^2)^2) + 1/(2*a^2*(a + b*x + c*x^2)) - (3*b*c*(b + 2*c*x))/(2*a*(b^2 - 4*a*c)^2*(a + b*x + c*x^2)) + (b*(b + 2*c*x))/(2*a^2*(b^2 - 4*a*c)*(a + b*x + c*x^2)) + (6*b*c^2*ArcTanh[(b + 2*c*x)/Sqrt[b^2 - 4*a*c]])/(a*(b^2 - 4*a*c)^(5/2)) - (2*b*c*ArcTanh[(b + 2*c*x)/Sqrt[b^2 - 4*a*c]])/(a^2*(b^2 - 4*a*c)^(3/2)) + (b*ArcTanh[(b + 2*c*x)/Sqrt[b^2 - 4*a*c]])/(a^3*Sqrt[b^2 - 4*a*c]) + Log[x]/a^3 - Log[a + b*x + c*x^2]/(2*a^3)}
{1/(x^2*(a + b*x + c*x^2)^3), x, 12, -(1/(a^3*x)) - b/(4*a^2*(a + b*x + c*x^2)^2) - ((b^2 - 2*a*c)*(b + 2*c*x))/(4*a^2*(b^2 - 4*a*c)*(a + b*x + c*x^2)^2) - b/(a^3*(a + b*x + c*x^2)) + (3*c*(b^2 - 2*a*c)*(b + 2*c*x))/(2*a^2*(b^2 - 4*a*c)^2*(a + b*x + c*x^2)) - ((b^2 - a*c)*(b + 2*c*x))/(a^3*(b^2 - 4*a*c)*(a + b*x + c*x^2)) - (3*(b^6 - 10*a*b^4*c + 30*a^2*b^2*c^2 - 20*a^3*c^3)*ArcTanh[(b + 2*c*x)/Sqrt[b^2 - 4*a*c]])/(a^4*(b^2 - 4*a*c)^(5/2)) - (3*b*Log[x])/a^4 + (3*b*Log[a + b*x + c*x^2])/(2*a^4), -(1/(a^3*x)) - b/(4*a^2*(a + b*x + c*x^2)^2) - ((b^2 - 2*a*c)*(b + 2*c*x))/(4*a^2*(b^2 - 4*a*c)*(a + b*x + c*x^2)^2) - b/(a^3*(a + b*x + c*x^2)) + (3*c*(b^2 - 2*a*c)*(b + 2*c*x))/(2*a^2*(b^2 - 4*a*c)^2*(a + b*x + c*x^2)) - ((b^2 - a*c)*(b + 2*c*x))/(a^3*(b^2 - 4*a*c)*(a + b*x + c*x^2)) - (6*c^2*(b^2 - 2*a*c)*ArcTanh[(b + 2*c*x)/Sqrt[b^2 - 4*a*c]])/(a^2*(b^2 - 4*a*c)^(5/2)) - ((3*b^2 - 2*a*c)*ArcTanh[(b + 2*c*x)/Sqrt[b^2 - 4*a*c]])/(a^4*Sqrt[b^2 - 4*a*c]) + (4*c*(b^2 - a*c)*ArcTanh[(b + 2*c*x)/Sqrt[b^2 - 4*a*c]])/(a^3*(b^2 - 4*a*c)^(3/2)) - (3*b*Log[x])/a^4 + (3*b*Log[a + b*x + c*x^2])/(2*a^4)}
(* {1/(x^3*(a + b*x + c*x^2)^3), x, 12, -(1/(2*a^3*x^2)) + (3*b)/(a^4*x) + (b^2 - a*c)/(4*a^3*(a + b*x + c*x^2)^2) + (b*(b^2 - 3*a*c)*(b + 2*c*x))/(4*a^3*(b^2 - 4*a*c)*(a + b*x + c*x^2)^2) + (3*b^2 - 2*a*c)/(2*a^4*(a + b*x + c*x^2)) - (3*b*c*(b^2 - 3*a*c)*(b + 2*c*x))/(2*a^3*(b^2 - 4*a*c)^2*(a + b*x + c*x^2)) + (3*b*(b^2 - 2*a*c)*(b + 2*c*x))/(2*a^4*(b^2 - 4*a*c)*(a + b*x + c*x^2)) + (6*b*c^2*(b^2 - 3*a*c)*ArcTanh[(b + 2*c*x)/Sqrt[b^2 - 4*a*c]])/(a^3*(b^2 - 4*a*c)^(5/2)) + (3*b*(2*b^2 - 3*a*c)*ArcTanh[(b + 2*c*x)/Sqrt[b^2 - 4*a*c]])/(a^5*Sqrt[b^2 - 4*a*c]) - (6*b*c*(b^2 - 2*a*c)*ArcTanh[(b + 2*c*x)/Sqrt[b^2 - 4*a*c]])/(a^4*(b^2 - 4*a*c)^(3/2)) + (3*(2*b^2 - a*c)*Log[x])/a^5 - (3*(2*b^2 - a*c)*Log[a + b*x + c*x^2])/(2*a^5)} *)
(* {1/(x^4*(a + b*x + c*x^2)^3), x, 0, 0} *)


(* Integrands of the form x^m/(a+b*x+c*x^2)^4 where m is an integer *)
{x^3/(c + d*x + e*x^2)^4, x, 7, -((d^2 + 5*c*e)/(60*e^3*(c + d*x + e*x^2)^3)) + (d*x)/(20*e^2*(c + d*x + e*x^2)^3) - x^2/(4*e*(c + d*x + e*x^2)^3) + (d*(d^2 + 6*c*e)*(d + 2*e*x))/(60*e^3*(d^2 - 4*c*e)*(c + d*x + e*x^2)^3) - (d*(d^2 + 6*c*e)*(d + 2*e*x))/(12*e^2*(d^2 - 4*c*e)^2*(c + d*x + e*x^2)^2) + (d*(6*c + d^2/e)*(d + 2*e*x))/(2*(d^2 - 4*c*e)^3*(c + d*x + e*x^2)) - (2*d*(d^2 + 6*c*e)*ArcTanh[(d + 2*e*x)/Sqrt[d^2 - 4*c*e]])/(d^2 - 4*c*e)^(7/2)}


(* Integrands of the form 1/(a+b*x+c*x^2) where b^2-4*a*c==0 *)
{(4 + 12*x + 9*x^2)^(-1), x, 2, -(1/(3*(2 + 3*x)))}
{(4 - 12*x + 9*x^2)^(-1), x, 2, 1/(3*(2 - 3*x))}
{(a^2 + 2*a*b*x + b^2*x^2)^(-1), x, 2, -(1/(b*(a + b*x)))}
{(a^2 - 2*a*b*x + b^2*x^2)^(-1), x, 2, 1/(b*(a - b*x))}


(* Integrands of the form 1/(a+b*x+c*x^2) *)
{(2 + 4*x + 3*x^2)^(-1), x, 1, ArcTan[(2 + 3*x)/Sqrt[2]]/Sqrt[2]}
{(2 + 4*x - 3*x^2)^(-1), x, 1, -(ArcTanh[(2 - 3*x)/Sqrt[10]]/Sqrt[10])}
{(2 + 5*x + 3*x^2)^(-1), x, 1, -2*ArcTanh[5 + 6*x]}
{(2 + 5*x - 3*x^2)^(-1), x, 1, (-(2/7))*ArcTanh[5/7 - (6*x)/7]}
{(1 + Pi*x + 2*x^2)^(-1), x, 1, (-2*ArcTanh[(Pi + 4*x)/Sqrt[-8 + Pi^2]])/Sqrt[-8 + Pi^2]}
{(1 + Pi*x - 2*x^2)^(-1), x, 1, (-2*ArcTanh[(Pi - 4*x)/Sqrt[8 + Pi^2]])/Sqrt[8 + Pi^2]}
{(1 + Pi*x + 3*x^2)^(-1), x, 1, (2*ArcTan[(Pi + 6*x)/Sqrt[12 - Pi^2]])/Sqrt[12 - Pi^2]}
{(1 + Pi*x - 3*x^2)^(-1), x, 1, (-2*ArcTanh[(Pi - 6*x)/Sqrt[12 + Pi^2]])/Sqrt[12 + Pi^2]}
{(a + b*x + c*x^2)^(-1), x, 1, (-2*ArcTanh[(b + 2*c*x)/Sqrt[b^2 - 4*a*c]])/Sqrt[b^2 - 4*a*c]}
{(a + c*x + b*x^2)^(-1), x, 1, (2*ArcTan[(c + 2*b*x)/Sqrt[4*a*b - c^2]])/Sqrt[4*a*b - c^2]}
{(b + 2*a*x + b*x^2)^(-1), x, 1, -(ArcTanh[(a + b*x)/Sqrt[a^2 - b^2]]/Sqrt[a^2 - b^2])}
{(b + 2*a*x - b*x^2)^(-1), x, 1, -(ArcTanh[(a - b*x)/Sqrt[a^2 + b^2]]/Sqrt[a^2 + b^2])}


(* Integrands of the form 1/(a+b*x+c*x^2)^2 *)
{(2 + 4*x + 3*x^2)^(-2), x, 2, (2 + 3*x)/(4*(2 + 4*x + 3*x^2)) + (3*ArcTan[(2 + 3*x)/Sqrt[2]])/(4*Sqrt[2])}
{(2 + 4*x - 3*x^2)^(-2), x, 2, -((2 - 3*x)/(20*(2 + 4*x - 3*x^2))) - (3*ArcTanh[(2 - 3*x)/Sqrt[10]])/(20*Sqrt[10])}
{(2 + 5*x + 3*x^2)^(-2), x, 2, -((5 + 6*x)/(2 + 5*x + 3*x^2)) + 12*ArcTanh[5 + 6*x]}
{(2 + 5*x - 3*x^2)^(-2), x, 2, -((5 - 6*x)/(49*(2 + 5*x - 3*x^2))) - (12/343)*ArcTanh[5/7 - (6*x)/7]}
{(a + b*x + c*x^2)^(-2), x, 2, -((b + 2*c*x)/((b^2 - 4*a*c)*(a + b*x + c*x^2))) + (4*c*ArcTanh[(b + 2*c*x)/Sqrt[b^2 - 4*a*c]])/(b^2 - 4*a*c)^(3/2)}
{(a + c*x + b*x^2)^(-2), x, 2, (c + 2*b*x)/((4*a*b - c^2)*(a + c*x + b*x^2)) + (4*b*ArcTan[(c + 2*b*x)/Sqrt[4*a*b - c^2]])/(4*a*b - c^2)^(3/2)}
{(b + 2*a*x + b*x^2)^(-2), x, 2, -((a + b*x)/(2*(a^2 - b^2)*(b + 2*a*x + b*x^2))) + (b*ArcTanh[(a + b*x)/Sqrt[a^2 - b^2]])/(2*(a^2 - b^2)^(3/2))}
{(b + 2*a*x - b*x^2)^(-2), x, 2, -((a - b*x)/(2*(a^2 + b^2)*(b + 2*a*x - b*x^2))) - (b*ArcTanh[(a - b*x)/Sqrt[a^2 + b^2]])/(2*(a^2 + b^2)^(3/2))}


(* Integrands of the form x^m*(a+b*x+c*x^2)^n where m and n are integers *)
{x/(4 + 4*x + x^2), x, 5, 2/(2 + x) + Log[2 + x]}
{x/(5 + 2*x + x^2), x, 2, (-(1/2))*ArcTan[1/2 + x/2] + (1/2)*Log[5 + 2*x + x^2]}
{x/(6 - 5*x + x^2), x, 4, -2*Log[2 - x] + 3*Log[3 - x]}
{x/(2 + 2*x + x^2)^2, x, 3, -(1/(2 + 2*x + x^2)) - x/(2*(2 + 2*x + x^2)) - (1/2)*ArcTan[1 + x]}
{x/(1 + x + x^2)^3, x, 4, -(1/(3*(1 + x + x^2)^2)) - x/(6*(1 + x + x^2)^2) - (1 + 2*x)/(6*(1 + x + x^2)) - (2*ArcTan[(1 + 2*x)/Sqrt[3]])/(3*Sqrt[3])}

{x^2/(1 + x + x^2), x, 4, x - ArcTan[(1 + 2*x)/Sqrt[3]]/Sqrt[3] - Log[1 + x + x^2]/2}
{x^2/(2 - 3*x + x^2), x, 4, x - Log[1 - x] + 4*Log[2 - x]}
{x^2/(-6 + x + x^2), x, 4, x + (4/5)*Log[2 - x] - (9/5)*Log[3 + x]}
{x^2/(2 + 2*x + x^2)^2, x, 3, (2 + 2*x + x^2)^(-1) + ArcTan[1 + x]}

{x^3/(2 - 3*x + x^2), x, 5, 3*x + x^2/2 - Log[1 - x] + 8*Log[2 - x]}
{x^3/(1 + 2*x + x^2), x, 6, -2*x + x^2/2 + 1/(1 + x) + 3*Log[1 + x]}
{x^3/(1 - 2*x + x^2), x, 6, 1/(1 - x) + 2*x + x^2/2 + 3*Log[1 - x]}

{x^4/(4 + 4*x + x^2), x, 6, 12*x - 2*x^2 + x^3/3 - 16/(2 + x) - 32*Log[2 + x]}

{(1 + x + x^2)/x, x, 2, x + x^2/2 + Log[x]}
{(9 + 6*x + x^2)/x^2, x, 2, -9/x + x + 6*Log[x]}
{(3 - 4*x + x^2)/x^3, x, 2, -(3/(2*x^2)) + 4/x + Log[x]}
{(1 + 2*x + x^2)/x^4, x, 2, -(1/(3*x^3)) - 1/x^2 - 1/x}

{1/(x*(1 + x + x^2)), x, 5, -(ArcTan[(1 + 2*x)/Sqrt[3]]/Sqrt[3]) + Log[x] - Log[1 + x + x^2]/2}


{1/((a/b)^(2/n) + x^2 - 2*(a/b)^(1/n)*x*Cos[(Pi - 2*k*Pi)/n]), x, 1, (ArcTan[((x - (a/b)^(1/n)*Cos[((1 - 2*k)*Pi)/n])*Csc[((1 - 2*k)*Pi)/n])/(a/b)^n^(-1)]*Csc[((1 - 2*k)*Pi)/n])/(a/b)^n^(-1)}


(* ::Subsubsection::Closed:: *)
(*Integrands of the form (d+e x)^m (a+b x+c x^2)^n*)


{1/(b*x + c*(d + e*x)^2), x, 2, -((2*ArcTanh[(b + 2*c*d*e + 2*c*e^2*x)/(Sqrt[b]*Sqrt[b + 4*c*d*e])])/(Sqrt[b]*Sqrt[b + 4*c*d*e]))}
{1/(a + b*x + c*(d + e*x)^2), x, 2, -((2*ArcTanh[(b + 2*c*d*e + 2*c*e^2*x)/Sqrt[b^2 + 4*b*c*d*e - 4*a*c*e^2]])/Sqrt[b^2 + 4*b*c*d*e - 4*a*c*e^2])}


(* Integrands of the form (d+e*x)^m/(a+b*x+c*x^2) where m is an integer *)
{(d + e*x)^3/(a + b*x + c*x^2), x, 5, (e^2*(3*c*d - b*e)*x)/c^2 + (e^3*x^2)/(2*c) - ((2*c*d - b*e)*(c^2*d^2 + b^2*e^2 - c*e*(b*d + 3*a*e))*ArcTanh[(b + 2*c*x)/Sqrt[b^2 - 4*a*c]])/(c^3*Sqrt[b^2 - 4*a*c]) + (e*(3*c^2*d^2 - 3*b*c*d*e + b^2*e^2 - a*c*e^2)*Log[a + b*x + c*x^2])/(2*c^3)}
{(d + e*x)^2/(a + b*x + c*x^2), x, 4, (e^2*x)/c - ((b^2*e^2 + 2*c*(c*d^2 - e*(b*d + a*e)))*ArcTanh[(b + 2*c*x)/Sqrt[b^2 - 4*a*c]])/(c^2*Sqrt[b^2 - 4*a*c]) + (e*(2*c*d - b*e)*Log[a + b*x + c*x^2])/(2*c^2)}
{(d + e*x)/(a + b*x + c*x^2), x, 2, -(((2*d - (b*e)/c)*ArcTanh[(b + 2*c*x)/Sqrt[b^2 - 4*a*c]])/Sqrt[b^2 - 4*a*c]) + (e*Log[a + b*x + c*x^2])/(2*c)}
{1/((d + e*x)*(a + b*x + c*x^2)), x, 5, -(((2*c*d - b*e)*ArcTanh[(b + 2*c*x)/Sqrt[b^2 - 4*a*c]])/(Sqrt[b^2 - 4*a*c]*(c*d^2 - e*(b*d - a*e)))) + (e*Log[d + e*x])/(c*d^2 - e*(b*d - a*e)) - (e*Log[a + b*x + c*x^2])/(2*(c*d^2 - e*(b*d - a*e)))}
{1/((d + e*x)^2*(a + b*x + c*x^2)), x, 6, -(e/((c*d^2 - e*(b*d - a*e))*(d + e*x))) - ((2*c^2*d^2 + b^2*e^2 - 2*c*e*(b*d + a*e))*ArcTanh[(b + 2*c*x)/Sqrt[b^2 - 4*a*c]])/(Sqrt[b^2 - 4*a*c]*(c*d^2 - e*(b*d - a*e))^2) + (e*(2*c*d - b*e)*Log[d + e*x])/(c*d^2 - e*(b*d - a*e))^2 - (e*(2*c*d - b*e)*Log[a + b*x + c*x^2])/(2*(c*d^2 - e*(b*d - a*e))^2)}
(* {1/((d + e*x)^3*(a + b*x + c*x^2)), x, 7, -(e/(2*(c*d^2 - b*d*e + a*e^2)*(d + e*x)^2)) - (e*(2*c*d - b*e))/((c*d^2 - e*(b*d - a*e))^2*(d + e*x)) + ((3*b*c^2*d^2*e - 3*b^2*c*d*e^2 + b^3*e^3 - 3*a*b*c*e^3 - 2*c^2*d*(c*d^2 - 3*a*e^2))*ArcTanh[(b + 2*c*x)/Sqrt[b^2 - 4*a*c]])/(Sqrt[b^2 - 4*a*c]*(c*d^2 - e*(b*d - a*e))^3) + (e*(3*c^2*d^2 + b^2*e^2 - c*e*(3*b*d + a*e))*Log[d + e*x])/(c*d^2 - e*(b*d - a*e))^3 - (e*(3*c^2*d^2 - 3*b*c*d*e + b^2*e^2 - a*c*e^2)*Log[a + b*x + c*x^2])/(2*(c*d^2 - e*(b*d - a*e))^3)} *)


(* Integrands of the form (d+e*x)^m/(a+b*x+c*x^2)^2 where m is an integer *)
(* {(d + e*x)^3/(a + b*x + c*x^2)^2, x, 6, -(((2*c*d - b*e)*(c*d^2 - e*(b*d - a*e))*(b + 2*c*x))/(2*c^2*(b^2 - 4*a*c)*(a + b*x + c*x^2))) - (e*(2*c*d - b*e)*(d + e*x))/(2*c^2*(a + b*x + c*x^2)) - (e*(d + e*x)^2)/(2*c*(a + b*x + c*x^2)) - (e^2*(2*c*d - b*e)*ArcTanh[(b + 2*c*x)/Sqrt[b^2 - 4*a*c]])/(c^2*Sqrt[b^2 - 4*a*c]) + (2*(2*c*d - b*e)*(c*d^2 - e*(b*d - a*e))*ArcTanh[(b + 2*c*x)/Sqrt[b^2 - 4*a*c]])/(c*(b^2 - 4*a*c)^(3/2)) + (e^3*Log[a + b*x + c*x^2])/(2*c^2)} *)
{(d + e*x)^2/(a + b*x + c*x^2)^2, x, 3, -(((c*d^2 - e*(b*d - a*e))*(b + 2*c*x))/(c*(b^2 - 4*a*c)*(a + b*x + c*x^2))) - (e*(d + e*x))/(c*(a + b*x + c*x^2)) + (4*(c*d^2 - e*(b*d - a*e))*ArcTanh[(b + 2*c*x)/Sqrt[b^2 - 4*a*c]])/(b^2 - 4*a*c)^(3/2)}
{(d + e*x)/(a + b*x + c*x^2)^2, x, 3, -(e/(2*c*(a + b*x + c*x^2))) - ((2*c*d - b*e)*(b + 2*c*x))/(2*c*(b^2 - 4*a*c)*(a + b*x + c*x^2)) + (2*(2*c*d - b*e)*ArcTanh[(b + 2*c*x)/Sqrt[b^2 - 4*a*c]])/(b^2 - 4*a*c)^(3/2)}
{1/((d + e*x)*(a + b*x + c*x^2)^2), x, 8, e/(2*(c*d^2 - e*(b*d - a*e))*(a + b*x + c*x^2)) - ((2*c*d - b*e)*(b + 2*c*x))/(2*(b^2 - 4*a*c)*(c*d^2 - e*(b*d - a*e))*(a + b*x + c*x^2)) - (e^2*(2*c*d - b*e)*ArcTanh[(b + 2*c*x)/Sqrt[b^2 - 4*a*c]])/(Sqrt[b^2 - 4*a*c]*(c*d^2 - e*(b*d - a*e))^2) + (2*c*(2*c*d - b*e)*ArcTanh[(b + 2*c*x)/Sqrt[b^2 - 4*a*c]])/((b^2 - 4*a*c)^(3/2)*(c*d^2 - e*(b*d - a*e))) + (e^3*Log[d + e*x])/(c*d^2 - e*(b*d - a*e))^2 - (e^3*Log[a + b*x + c*x^2])/(2*(c*d^2 - e*(b*d - a*e))^2)}
(* {1/((d + e*x)^2*(a + b*x + c*x^2)^2), x, 9, -(e^3/((c*d^2 - e*(b*d - a*e))^2*(d + e*x))) + (e*(2*c*d - b*e))/(2*(c*d^2 - e*(b*d - a*e))^2*(a + b*x + c*x^2)) + ((2*b*c*d*e - b^2*e^2 - 2*c*(c*d^2 - a*e^2))*(b + 2*c*x))/(2*(b^2 - 4*a*c)*(c*d^2 - e*(b*d - a*e))^2*(a + b*x + c*x^2)) - (2*e^2*(3*c^2*d^2 - 3*b*c*d*e + b^2*e^2 - a*c*e^2)*ArcTanh[(b + 2*c*x)/Sqrt[b^2 - 4*a*c]])/(Sqrt[b^2 - 4*a*c]*(c*d^2 - e*(b*d - a*e))^3) - (2*c*(2*b*c*d*e - b^2*e^2 - 2*c*(c*d^2 - a*e^2))*ArcTanh[(b + 2*c*x)/Sqrt[b^2 - 4*a*c]])/((b^2 - 4*a*c)^(3/2)*(c*d^2 - e*(b*d - a*e))^2) + (2*e^3*(2*c*d - b*e)*Log[d + e*x])/(c*d^2 - e*(b*d - a*e))^3 - (e^3*(2*c*d - b*e)*Log[a + b*x + c*x^2])/(c*d^2 - e*(b*d - a*e))^3} *)
(* {1/((d + e*x)^3*(a + b*x + c*x^2)^2), x, 10, -(e^3/(2*(c*d^2 - e*(b*d - a*e))^2*(d + e*x)^2)) - (2*e^3*(2*c*d - b*e))/((c*d^2 - e*(b*d - a*e))^3*(d + e*x)) + (e*(3*c^2*d^2 - 3*b*c*d*e + b^2*e^2 - a*c*e^2))/(2*(c*d^2 - e*(b*d - a*e))^3*(a + b*x + c*x^2)) + ((3*b*c^2*d^2*e - 3*b^2*c*d*e^2 + b^3*e^3 - 3*a*b*c*e^3 - 2*c^2*d*(c*d^2 - 3*a*e^2))*(b + 2*c*x))/(2*(b^2 - 4*a*c)*(c*d^2 - e*(b*d - a*e))^3*(a + b*x + c*x^2)) - (2*c*(3*b*c^2*d^2*e - 3*b^2*c*d*e^2 + b^3*e^3 - 3*a*b*c*e^3 - 2*c^2*d*(c*d^2 - 3*a*e^2))*ArcTanh[(b + 2*c*x)/Sqrt[b^2 - 4*a*c]])/((b^2 - 4*a*c)^(3/2)*(c*d^2 - e*(b*d - a*e))^3) + (3*e^2*(6*b*c^2*d^2*e - 4*b^2*c*d*e^2 + b^3*e^3 - 2*a*b*c*e^3 - 4*c^2*d*(c*d^2 - a*e^2))*ArcTanh[(b + 2*c*x)/Sqrt[b^2 - 4*a*c]])/(Sqrt[b^2 - 4*a*c]*(c*d^2 - b*d*e + a*e^2)^4) + (e^3*(10*c^2*d^2 + 3*b^2*e^2 - 2*c*e*(5*b*d + a*e))*Log[d + e*x])/(c*d^2 - e*(b*d - a*e))^4 - (e^3*(10*c^2*d^2 - 10*b*c*d*e + 3*b^2*e^2 - 2*a*c*e^2)*Log[a + b*x + c*x^2])/(2*(c*d^2 - b*d*e + a*e^2)^4)} *)


(* Integrands of the form x^m*(d+e*x)/(a+b*x+c*x^2) where m is an integer *)
{x^4*(d + e*x)/(a + b*x + c*x^2), x, 5, ((b^2*c*d - a*c^2*d - b^3*e + 2*a*b*c*e)*x)/c^4 - ((b*c*d - b^2*e + a*c*e)*x^2)/(2*c^3) + ((c*d - b*e)*x^3)/(3*c^2) + (e*x^4)/(4*c) + ((b^5*e - c*(b^4*d - 4*a*b^2*c*d + 2*a^2*c^2*d + 5*a*b^3*e - 5*a^2*b*c*e))*ArcTanh[(b + 2*c*x)/Sqrt[b^2 - 4*a*c]])/(c^5*Sqrt[b^2 - 4*a*c]) - ((b^3*c*d - 2*a*b*c^2*d - b^4*e + 3*a*b^2*c*e - a^2*c^2*e)*Log[a + b*x + c*x^2])/(2*c^5)}
{x^3*(d + e*x)/(a + b*x + c*x^2), x, 5, -(((b*c*d - b^2*e + a*c*e)*x)/c^3) + ((c*d - b*e)*x^2)/(2*c^2) + (e*x^3)/(3*c) - ((b^4*e - c*(b^3*d - 3*a*b*c*d + 4*a*b^2*e - 2*a^2*c*e))*ArcTanh[(b + 2*c*x)/Sqrt[b^2 - 4*a*c]])/(c^4*Sqrt[b^2 - 4*a*c]) + ((b^2*c*d - a*c^2*d - b^3*e + 2*a*b*c*e)*Log[a + b*x + c*x^2])/(2*c^4)}
{x^2*(d + e*x)/(a + b*x + c*x^2), x, 5, ((c*d - b*e)*x)/c^2 + (e*x^2)/(2*c) + ((b^3*e - c*(b^2*d - 2*a*c*d + 3*a*b*e))*ArcTanh[(b + 2*c*x)/Sqrt[b^2 - 4*a*c]])/(c^3*Sqrt[b^2 - 4*a*c]) - ((b*c*d - b^2*e + a*c*e)*Log[a + b*x + c*x^2])/(2*c^3)}
{x*(d + e*x)/(a + b*x + c*x^2), x, 4, (e*x)/c - ((b^2*e - c*(b*d + 2*a*e))*ArcTanh[(b + 2*c*x)/Sqrt[b^2 - 4*a*c]])/(c^2*Sqrt[b^2 - 4*a*c]) + ((c*d - b*e)*Log[a + b*x + c*x^2])/(2*c^2)}
{(d + e*x)/(a + b*x + c*x^2), x, 2, -(((2*d - (b*e)/c)*ArcTanh[(b + 2*c*x)/Sqrt[b^2 - 4*a*c]])/Sqrt[b^2 - 4*a*c]) + (e*Log[a + b*x + c*x^2])/(2*c)}
{(d + e*x)/(x*(a + b*x + c*x^2)), x, 5, ((b*d - 2*a*e)*ArcTanh[(b + 2*c*x)/Sqrt[b^2 - 4*a*c]])/(a*Sqrt[b^2 - 4*a*c]) + (d*Log[x])/a - (d*Log[a + b*x + c*x^2])/(2*a)}
{(d + e*x)/(x^2*(a + b*x + c*x^2)), x, 5, -(d/(a*x)) - ((b^2*d - 2*a*c*d - a*b*e)*ArcTanh[(b + 2*c*x)/Sqrt[b^2 - 4*a*c]])/(a^2*Sqrt[b^2 - 4*a*c]) - ((b*d - a*e)*Log[x])/a^2 + ((b*d - a*e)*Log[a + b*x + c*x^2])/(2*a^2)}
{(d + e*x)/(x^3*(a + b*x + c*x^2)), x, 5, -(d/(2*a*x^2)) + (b*d - a*e)/(a^2*x) + ((b^3*d - 3*a*b*c*d - a*b^2*e + 2*a^2*c*e)*ArcTanh[(b + 2*c*x)/Sqrt[b^2 - 4*a*c]])/(a^3*Sqrt[b^2 - 4*a*c]) + ((b^2*d - a*c*d - a*b*e)*Log[x])/a^3 - ((b^2*d - a*c*d - a*b*e)*Log[a + b*x + c*x^2])/(2*a^3)}
{(d + e*x)/(x^4*(a + b*x + c*x^2)), x, 5, -(d/(3*a*x^3)) + (b*d - a*e)/(2*a^2*x^2) - (b^2*d - a*c*d - a*b*e)/(a^3*x) - ((b^4*d - 4*a*b^2*c*d + 2*a^2*c^2*d - a*b^3*e + 3*a^2*b*c*e)*ArcTanh[(b + 2*c*x)/Sqrt[b^2 - 4*a*c]])/(a^4*Sqrt[b^2 - 4*a*c]) - ((b^3*d - 2*a*b*c*d - a*b^2*e + a^2*c*e)*Log[x])/a^4 + ((b^3*d - 2*a*b*c*d - a*b^2*e + a^2*c*e)*Log[a + b*x + c*x^2])/(2*a^4)}


(* Integrands of the form (a+b*x)^m/(a*c+(b*c+a*d)*x+b*d*x^2) where m is an integer *)
{(a + b*x)/(a*c + (b*c + a*d)*x + b*d*x^2), x, 2, Log[c + d*x]/d}
{(a + b*x)^2/(a*c + (b*c + a*d)*x + b*d*x^2), x, 4, (b*x)/d - ((b*c - a*d)*Log[c + d*x])/d^2}
{(a + b*x)^3/(a*c + (b*c + a*d)*x + b*d*x^2), x, 5, -((b*(b*c - a*d)*x)/d^2) + (a + b*x)^2/(2*d) + ((b*c - a*d)^2*Log[c + d*x])/d^3}

{1/((a + b*x)*(a*c + (b*c + a*d)*x + b*d*x^2)), x, 6, -(1/((b*c - a*d)*(a + b*x))) - (d*Log[a + b*x])/(b*c - a*d)^2 + (d*Log[c + d*x])/(b*c - a*d)^2}
{1/((a + b*x)^2*(a*c + (b*c + a*d)*x + b*d*x^2)), x, 7, -(1/(2*(b*c - a*d)*(a + b*x)^2)) + d/((b*c - a*d)^2*(a + b*x)) + (d^2*Log[a + b*x])/(b*c - a*d)^3 - (d^2*Log[c + d*x])/(b*c - a*d)^3}
{1/((a + b*x)^3*(a*c + (b*c + a*d)*x + b*d*x^2)), x, 8, -(1/(3*(b*c - a*d)*(a + b*x)^3)) + d/(2*(b*c - a*d)^2*(a + b*x)^2) - d^2/((b*c - a*d)^3*(a + b*x)) - (d^3*Log[a + b*x])/(b*c - a*d)^4 + (d^3*Log[c + d*x])/(b*c - a*d)^4}


(* Integrands of the form (a+b*x)^m/(a*c+(b*c+a*d)*x+b*d*x^2)^2 where m is an integer *)
{(a + b*x)/(a*c + (b*c + a*d)*x + b*d*x^2)^2, x, 6, 1/((b*c - a*d)*(c + d*x)) + (b*Log[a + b*x])/(b*c - a*d)^2 - (b*Log[c + d*x])/(b*c - a*d)^2}
{(a + b*x)^2/(a*c + (b*c + a*d)*x + b*d*x^2)^2, x, 2, -(1/(d*(c + d*x)))}
{(a + b*x)^3/(a*c + (b*c + a*d)*x + b*d*x^2)^2, x, 5, (b*c - a*d)/(d^2*(c + d*x)) + (b*Log[c + d*x])/d^2}

{1/((a + b*x)*(a*c + (b*c + a*d)*x + b*d*x^2)^2), x, 8, -(b/(2*(b*c - a*d)^2*(a + b*x)^2)) + (2*b*d)/((b*c - a*d)^3*(a + b*x)) + d^2/((b*c - a*d)^3*(c + d*x)) + (3*b*d^2*Log[a + b*x])/(b*c - a*d)^4 - (3*b*d^2*Log[c + d*x])/(b*c - a*d)^4}
{1/((a + b*x)^2*(a*c + (b*c + a*d)*x + b*d*x^2)^2), x, 9, -(b/(3*(b*c - a*d)^2*(a + b*x)^3)) + (b*d)/((b*c - a*d)^3*(a + b*x)^2) - (3*b*d^2)/((b*c - a*d)^4*(a + b*x)) - d^3/((b*c - a*d)^4*(c + d*x)) - (4*b*d^3*Log[a + b*x])/(b*c - a*d)^5 + (4*b*d^3*Log[c + d*x])/(b*c - a*d)^5}
{1/((a + b*x)^3*(a*c + (b*c + a*d)*x + b*d*x^2)^2), x, 10, -(b/(4*(b*c - a*d)^2*(a + b*x)^4)) + (2*b*d)/(3*(b*c - a*d)^3*(a + b*x)^3) - (3*b*d^2)/(2*(b*c - a*d)^4*(a + b*x)^2) + (4*b*d^3)/((b*c - a*d)^5*(a + b*x)) + d^4/((b*c - a*d)^5*(c + d*x)) + (5*b*d^4*Log[a + b*x])/(b*c - a*d)^6 - (5*b*d^4*Log[c + d*x])/(b*c - a*d)^6}


(* Integrands of the form (a+b*x)^m/(a*c+(b*c+a*d)*x+b*d*x^2)^3 where m is an integer *)
{(a + b*x)/(a*c + (b*c + a*d)*x + b*d*x^2)^3, x, 8, -(b^2/((b*c - a*d)^3*(a + b*x))) - d/(2*(b*c - a*d)^2*(c + d*x)^2) - (2*b*d)/((b*c - a*d)^3*(c + d*x)) - (3*b^2*d*Log[a + b*x])/(b*c - a*d)^4 + (3*b^2*d*Log[c + d*x])/(b*c - a*d)^4}
{(a + b*x)^2/(a*c + (b*c + a*d)*x + b*d*x^2)^3, x, 7, 1/(2*(b*c - a*d)*(c + d*x)^2) + b/((b*c - a*d)^2*(c + d*x)) + (b^2*Log[a + b*x])/(b*c - a*d)^3 - (b^2*Log[c + d*x])/(b*c - a*d)^3}
{(a + b*x)^3/(a*c + (b*c + a*d)*x + b*d*x^2)^3, x, 2, -(1/(2*d*(c + d*x)^2))}

{1/((a + b*x)*(a*c + (b*c + a*d)*x + b*d*x^2)^3), x, 10, -(b^2/(3*(b*c - a*d)^3*(a + b*x)^3)) + (3*b^2*d)/(2*(b*c - a*d)^4*(a + b*x)^2) - (6*b^2*d^2)/((b*c - a*d)^5*(a + b*x)) - d^3/(2*(b*c - a*d)^4*(c + d*x)^2) - (4*b*d^3)/((b*c - a*d)^5*(c + d*x)) - (10*b^2*d^3*Log[a + b*x])/(b*c - a*d)^6 + (10*b^2*d^3*Log[c + d*x])/(b*c - a*d)^6}
{1/((a + b*x)^2*(a*c + (b*c + a*d)*x + b*d*x^2)^3), x, 11, -(b^2/(4*(b*c - a*d)^3*(a + b*x)^4)) + (b^2*d)/((b*c - a*d)^4*(a + b*x)^3) - (3*b^2*d^2)/((b*c - a*d)^5*(a + b*x)^2) + (10*b^2*d^3)/((b*c - a*d)^6*(a + b*x)) + d^4/(2*(b*c - a*d)^5*(c + d*x)^2) + (5*b*d^4)/((b*c - a*d)^6*(c + d*x)) + (15*b^2*d^4*Log[a + b*x])/(b*c - a*d)^7 - (15*b^2*d^4*Log[c + d*x])/(b*c - a*d)^7}
{1/((a + b*x)^3*(a*c + (b*c + a*d)*x + b*d*x^2)^3), x, 12, -(b^2/(5*(b*c - a*d)^3*(a + b*x)^5)) + (3*b^2*d)/(4*(b*c - a*d)^4*(a + b*x)^4) - (2*b^2*d^2)/((b*c - a*d)^5*(a + b*x)^3) + (5*b^2*d^3)/((b*c - a*d)^6*(a + b*x)^2) - (15*b^2*d^4)/((b*c - a*d)^7*(a + b*x)) - d^5/(2*(b*c - a*d)^6*(c + d*x)^2) - (6*b*d^5)/((b*c - a*d)^7*(c + d*x)) - (21*b^2*d^5*Log[a + b*x])/(b*c - a*d)^8 + (21*b^2*d^5*Log[c + d*x])/(b*c - a*d)^8}


{(5 + x)/(9 + 12*x + 4*x^2), x, 4, -(7/(4*(3 + 2*x))) + (1/4)*Log[3 + 2*x]}
{(a + b*x)/(4 - 4*x + x^2), x, 4, (a + 2*b)/(2 - x) + b*Log[2 - x]}


(* Integrands of the form (d+e*x)/(a+b*x+c*x^2) where m is an integer *)
{(5 + 2*x)/(4 + 5*x + x^2), x, 1, Log[4 + 5*x + x^2]}
{(7 + 3*x)/(8 + 6*x + x^2), x, 4, (1/2)*Log[2 + x] + (5/2)*Log[4 + x]}
{(-1 + 2*x)/(1 + 8*x + 4*x^2), x, 2, (1/2)*Sqrt[3]*ArcTanh[(2*(1 + x))/Sqrt[3]] + (1/4)*Log[1 + 8*x + 4*x^2]}
{(5 + 2*x)/(5 + 4*x + x^2), x, 2, ArcTan[2 + x] + Log[5 + 4*x + x^2]}
{(-2 + 7*x)/(42 - 16*x + 2*x^2), x, 3, -((13*ArcTan[(4 - x)/Sqrt[5]])/Sqrt[5]) + (7/4)*Log[21 - 8*x + x^2]}


(* Integrands of the form (a+b*x^n)^m*(c+d*x+e*x^2)^p where m, n and p are integers *)
{(3 + 2*x)/(13 + 12*x + 4*x^2)^2, x, 1, -(1/(4*(13 + 12*x + 4*x^2)))}
{(4 + x)/(5 + 4*x + x^2)^2, x, 3, 3/(2*(5 + 4*x + x^2)) + x/(5 + 4*x + x^2) + ArcTan[2 + x]}
{(-1 + 3*x)/(1 + x + x^2)^2, x, 3, -(7/(3*(1 + x + x^2))) - (5*x)/(3*(1 + x + x^2)) - (10*ArcTan[(1 + 2*x)/Sqrt[3]])/(3*Sqrt[3])}

{(1 + x)/(1 - x + x^2)^3, x, 4, -(1/(2*(1 - x + x^2)^2)) + x/(2*(1 - x + x^2)^2) - (1 - 2*x)/(2*(1 - x + x^2)) - (2*ArcTan[(1 - 2*x)/Sqrt[3]])/Sqrt[3]}

{(1 + x^2)/(1 + x + x^2), x, 4, x + ArcTan[(1 + 2*x)/Sqrt[3]]/Sqrt[3] - Log[1 + x + x^2]/2}
{(-1 + x^2)/(25 - 6*x + x^2), x, 4, x + 2*ArcTan[3/4 - x/4] + 3*Log[25 - 6*x + x^2]}
{(-10 + 3*x^2)/(4 - 4*x + x^2), x, 4, 2/(2 - x) + 3*x + 12*Log[2 - x]}
{(1 + x^2)/(2 - 3*x + x^2), x, 4, x - 2*Log[1 - x] + 5*Log[2 - x]}

{(1 - x^2)/(1 + x + x^2)^2, x, 1, x/(1 + x + x^2)}
{(8 + x^2)/(6 - 5*x + x^2), x, 4, x - 12*Log[2 - x] + 17*Log[3 - x]}

{(-1 + x^3)/(1 + x + x^2), x, 2, -x + x^2/2}
{(-3 + x^3)/(-7 - 6*x + x^2), x, 5, 6*x + x^2/2 + (85/2)*Log[7 - x] + (1/2)*Log[1 + x]}

{(1 + x^3)/(13 + 4*x + x^2)^2, x, 7, 67/(18*(13 + 4*x + x^2)) + (47*x)/(18*(13 + 4*x + x^2)) - (61/54)*ArcTan[2/3 + x/3] + (1/2)*Log[13 + 4*x + x^2]}

{(2 + 2*x + x^2)/(2 + x), x, 4, x^2/2 + 2*Log[2 + x]}
{(5 + 4*x + x^2)/(-2 + x), x, 4, 6*x + x^2/2 + 17*Log[2 - x]}

{(2 + 2*x + x^2)/(1 + x)^3, x, 4, -1/(2*(1 + x)^2) + Log[1 + x]}
{(3 + 3*x + 2*x^2)/(1 + x)^3, x, 5, -(1/(1 + x)^2) + 1/(1 + x) + 2*Log[1 + x]}

{(2 + 12*x + 3*x^2)/(4 + x^2)^2, x, 4, -(6/(4 + x^2)) - (5*x)/(4*(4 + x^2)) + (7/8)*ArcTan[x/2]}
{(1 + 2*x + x^2)/(1 + x^2)^2, x, 4, -(1/(1 + x^2)) + ArcTan[x]}

{(1 - x + 3*x^2)/(-1 + x^3), x, 5, (-2*ArcTan[(1 + 2*x)/Sqrt[3]])/Sqrt[3] + Log[1 - x] + Log[1 + x + x^2]}

{1/((-1 + x)*(1 + x + x^2)), x, 5, -(ArcTan[(1 + 2*x)/Sqrt[3]]/Sqrt[3]) + (1/3)*Log[1 - x] - (1/6)*Log[1 + x + x^2]}

{(b + 2*c*x)*(a + b*x + c*x^2)^n, x, 1, (a + b*x + c*x^2)^(1 + n)/(1 + n)}

{(b + 2*c*x)^5/(a + b*x + c*x^2)^3, x, 3, -((b + 2*c*x)^4/(2*(a + b*x + c*x^2)^2)) - (4*c*(b + 2*c*x)^2)/(a + b*x + c*x^2) + 16*c^2*Log[a + b*x + c*x^2]}


{(2*((a/b)^(1/n) - x*Cos[((-1 + 2*k)*Pi)/n]))/((a/b)^(2/n) + x^2 - 2*(a/b)^(1/n)*x*Cos[((-1 + 2*k)*Pi)/n]), x, 3, (-Cos[((1 - 2*k)*Pi)/n])*Log[(a/b)^(2/n) + x^2 - 2*(a/b)^(1/n)*x*Cos[((1 - 2*k)*Pi)/n]] + 2*ArcTan[((x - (a/b)^(1/n)*Cos[((1 - 2*k)*Pi)/n])*Csc[((1 - 2*k)*Pi)/n])/(a/b)^n^(-1)]*Sin[((1 - 2*k)*Pi)/n]}


(* ::Subsubsection::Closed:: *)
(*Miscellaneous integrands involving rational functions of quadratic trinomials*)


(* Integrands of the form (a+b*x+c*x^2)^m*(d+e*x+f*x^2)^n where m and n are integers *)
{(-4 + 3*x + x^2)/(-8 - 2*x + x^2), x, 4, x + 4*Log[4 - x] + Log[2 + x]}
{(7 + 5*x + 4*x^2)/(5 + 4*x + 4*x^2), x, 4, x + (3/8)*ArcTan[1/2 + x] + (1/8)*Log[5 + 4*x + 4*x^2]}
{(7 - 3*x)/(-5 + 2*x + x^2), x, 2, -5*Sqrt[2/3]*ArcTanh[(1 + x)/Sqrt[6]] - (3/2)*Log[5 - 2*x - x^2]}
{(2 - x + x^2)/(-5 + 2*x + x^2), x, 4, x - 5*Sqrt[2/3]*ArcTanh[(1 + x)/Sqrt[6]] - (3/2)*Log[5 - 2*x - x^2]}

{(1 + x + x^2)/(3 + 2*x + x^2)^2, x, 4, 1/(4*(3 + 2*x + x^2)) - x/(4*(3 + 2*x + x^2)) + (3*ArcTan[(1 + x)/Sqrt[2]])/(4*Sqrt[2])}
{(-1 + 2*x + 5*x^2)/(1 + x + x^2)^4, x, 1, -(x/(1 + x + x^2)^3)}

{1/((4 - 4*x + x^2)*(5 - 4*x + x^2)), x, 4, 1/(2 - x) + ArcTan[2 - x]}


{(-3 + x + x^2)/((-3 + x)*x^2), x, 4, -(1/x) + Log[3 - x]}
{(1 + x + 4*x^2)/(x + 4*x^3), x, 4, ArcTan[2*x]/2 + Log[x]}
{(1 - x + 3*x^2)/(-x^2 + x^3), x, 4, 1/x + 3*Log[1 - x]}
{(4 + 3*x + x^2)/(x + x^2), x, 4, x + 4*Log[x] - 2*Log[1 + x]}
{(4 + x + 3*x^2)/(x + x^3), x, 6, ArcTan[x] + 4*Log[x] - Log[1 + x^2]/2}
{(x^2 + x^3)/(-2 + x + x^2), x, 5, x^2/2 + (2/3)*Log[1 - x] + (4/3)*Log[2 + x]}

{(7 - 4*x + 8*x^2)/((1 + 4*x)*(1 + x^2)), x, 4, -ArcTan[x] + 2*Log[1 + 4*x]}
{x^2/((-1 + x)*(1 + 2*x + x^2)), x, 5, 1/(2*(1 + x)) + (1/4)*Log[1 - x] + (3/4)*Log[1 + x]}
{(-4 + 3*x + x^2)/((-1 + 2*x)^2*(3 + 2*x)), x, 5, -(9/(32*(1 - 2*x))) + (41/128)*Log[1 - 2*x] - (25/128)*Log[3 + 2*x]}
{(5 - 4*x + 3*x^2)/((-1 + x)*(1 + x^2)), x, 6, -3*ArcTan[x] + 2*Log[1 - x] + (1/2)*Log[1 + x^2]}
{(-1 - 2*x + x^2)/((-1 + x)^2*(1 + x^2)), x, 7, -(1/(1 - x)) + ArcTan[x] + Log[1 - x] - (1/2)*Log[1 + x^2]}
{(5 + x^3)/((10 - 6*x + x^2)*(1/2 - x + x^2)), x, 6, (-(261/221))*ArcTan[1 - 2*x] - (1026/221)*ArcTan[3 - x] + (56/221)*Log[10 - 6*x + x^2] + (109/442)*Log[1 - 2*x + 2*x^2]}

{(4 + 3*x + x^2)/((-3 + x)*(-2 + x)*(-1 + x)), x, 5, 4*Log[1 - x] - 14*Log[2 - x] + 11*Log[3 - x]}
{(1 + 16*x)/((5 + x)^2*(-3 + 2*x)*(1 + x + x^2)), x, 7, -(79/(273*(5 + x))) + (451*ArcTan[(1 + 2*x)/Sqrt[3]])/(2793*Sqrt[3]) + (200*Log[3 - 2*x])/3211 + (2731*Log[5 + x])/24843 - (481*Log[1 + x + x^2])/5586}
{x/((-1 + x)^3*(3 + 5*x + 4*x^2)^2), x, 10, -(1/(288*(1 - x)^2)) - 7/(864*(1 - x)) + 325/(13248*(3 + 5*x + 4*x^2)) + (551*x)/(9936*(3 + 5*x + 4*x^2)) + (6023*ArcTan[(5 + 8*x)/Sqrt[23]])/(52992*Sqrt[23]) + (11*Log[1 - x])/2304 - (11*Log[3 + 5*x + 4*x^2])/4608}


(* Integrands of the form x^m/(a*x^n+b*x^p+c*x^q) where m, n, p and q are integers *)
(* In some of the following examples gcd cancellation should occur without also partial fraction 
	expansion, since that will result in unnecessary expansion. *)
{x^4/(2 + 13*x + 15*x^2), x, 5, (139*x)/3375 - (13*x^2)/450 + x^3/45 - (16/567)*Log[2 + 3*x] + Log[1 + 5*x]/4375}
{x^3/(2 + 13*x + 15*x^2), x, 5, -((13*x)/225) + x^2/30 + (8/189)*Log[2 + 3*x] - (1/875)*Log[1 + 5*x]}
{x^2/(2 + 13*x + 15*x^2), x, 4, x/15 - (4/63)*Log[2 + 3*x] + (1/175)*Log[1 + 5*x]}
{x/(2 + 13*x + 15*x^2), x, 4, (2/21)*Log[2 + 3*x] - (1/35)*Log[1 + 5*x]}
{1/(2 + 13*x + 15*x^2), x, 1, (-(2/7))*ArcTanh[13/7 + (30*x)/7]}
{1/(x*(2 + 13*x + 15*x^2)), x, 5, Log[x]/2 + (3/14)*Log[2 + 3*x] - (5/7)*Log[1 + 5*x]}
{1/(x^2*(2 + 13*x + 15*x^2)), x, 5, -(1/(2*x)) - (13*Log[x])/4 - (9/28)*Log[2 + 3*x] + (25/7)*Log[1 + 5*x]}
{1/(x^3*(2 + 13*x + 15*x^2)), x, 5, -(1/(4*x^2)) + 13/(4*x) + (139*Log[x])/8 + (27/56)*Log[2 + 3*x] - (125/7)*Log[1 + 5*x]}
{1/(x^4*(2 + 13*x + 15*x^2)), x, 5, -(1/(6*x^3)) + 13/(8*x^2) - 139/(8*x) - (1417*Log[x])/16 - (81/112)*Log[2 + 3*x] + (625/7)*Log[1 + 5*x]}

{x^3/(2/x + 13 + 15*x), x, 5, (139*x)/3375 - (13*x^2)/450 + x^3/45 - (16/567)*Log[2 + 3*x] + Log[1 + 5*x]/4375}
{x^2/(2/x + 13 + 15*x), x, 5, -((13*x)/225) + x^2/30 + (8/189)*Log[2 + 3*x] - (1/875)*Log[1 + 5*x]}
{x/(2/x + 13 + 15*x), x, 4, x/15 - (4/63)*Log[2 + 3*x] + (1/175)*Log[1 + 5*x]}
{1/(2/x + 13 + 15*x), x, 4, (2/21)*Log[2 + 3*x] - (1/35)*Log[1 + 5*x]}
{1/(x*(2/x + 13 + 15*x)), x, 2, (-(2/7))*ArcTanh[13/7 + (30*x)/7]}
{1/(x^2*(2/x + 13 + 15*x)), x, 5, Log[x]/2 + (3/14)*Log[2 + 3*x] - (5/7)*Log[1 + 5*x]}
{1/(x^3*(2/x + 13 + 15*x)), x, 5, -(1/(2*x)) - (13*Log[x])/4 - (9/28)*Log[2 + 3*x] + (25/7)*Log[1 + 5*x]}
{1/(x^4*(2/x + 13 + 15*x)), x, 5, -(1/(4*x^2)) + 13/(4*x) + (139*Log[x])/8 + (27/56)*Log[2 + 3*x] - (125/7)*Log[1 + 5*x]}
{1/(x^5*(2/x + 13 + 15*x)), x, 5, -(1/(6*x^3)) + 13/(8*x^2) - 139/(8*x) - (1417*Log[x])/16 - (81/112)*Log[2 + 3*x] + (625/7)*Log[1 + 5*x]}

{x^2/(2/x^2 + 13/x + 15), x, 5, (139*x)/3375 - (13*x^2)/450 + x^3/45 - (16/567)*Log[2 + 3*x] + Log[1 + 5*x]/4375}
{x/(2/x^2 + 13/x + 15), x, 5, -((13*x)/225) + x^2/30 + (8/189)*Log[2 + 3*x] - (1/875)*Log[1 + 5*x]}
{1/(2/x^2 + 13/x + 15), x, 4, x/15 - (4/63)*Log[2 + 3*x] + (1/175)*Log[1 + 5*x]}
{1/(x*(2/x^2 + 13/x + 15)), x, 4, (2/21)*Log[2 + 3*x] - (1/35)*Log[1 + 5*x]}
{1/(x^2*(2/x^2 + 13/x + 15)), x, 2, (2/7)*ArcTanh[13/7 + 4/(7*x)]}
{1/(x^3*(2/x^2 + 13/x + 15)), x, 5, Log[x]/2 + (3/14)*Log[2 + 3*x] - (5/7)*Log[1 + 5*x]}
{1/(x^4*(2/x^2 + 13/x + 15)), x, 5, -(1/(2*x)) - (13*Log[x])/4 - (9/28)*Log[2 + 3*x] + (25/7)*Log[1 + 5*x]}
{1/(x^5*(2/x^2 + 13/x + 15)), x, 5, -(1/(4*x^2)) + 13/(4*x) + (139*Log[x])/8 + (27/56)*Log[2 + 3*x] - (125/7)*Log[1 + 5*x]}
{1/(x^6*(2/x^2 + 13/x + 15)), x, 5, -(1/(6*x^3)) + 13/(8*x^2) - 139/(8*x) - (1417*Log[x])/16 - (81/112)*Log[2 + 3*x] + (625/7)*Log[1 + 5*x]}

{x^5/(2*x + 13*x^2 + 15*x^3), x, 6, (139*x)/3375 - (13*x^2)/450 + x^3/45 - (16/567)*Log[2 + 3*x] + Log[1 + 5*x]/4375}
{x^4/(2*x + 13*x^2 + 15*x^3), x, 6, -((13*x)/225) + x^2/30 + (8/189)*Log[2 + 3*x] - (1/875)*Log[1 + 5*x]}
{x^3/(2*x + 13*x^2 + 15*x^3), x, 5, x/15 - (4/63)*Log[2 + 3*x] + (1/175)*Log[1 + 5*x]}
{x^2/(2*x + 13*x^2 + 15*x^3), x, 5, (2/21)*Log[2 + 3*x] - (1/35)*Log[1 + 5*x]}
{x/(2*x + 13*x^2 + 15*x^3), x, 2, (-(2/7))*ArcTanh[13/7 + (30*x)/7]}
{1/(2*x + 13*x^2 + 15*x^3), x, 5, Log[x]/2 + (3/14)*Log[2 + 3*x] - (5/7)*Log[1 + 5*x]}
{1/(x*(2*x + 13*x^2 + 15*x^3)), x, 5, -(1/(2*x)) - (13*Log[x])/4 - (9/28)*Log[2 + 3*x] + (25/7)*Log[1 + 5*x]}
{1/(x^2*(2*x + 13*x^2 + 15*x^3)), x, 5, -(1/(4*x^2)) + 13/(4*x) + (139*Log[x])/8 + (27/56)*Log[2 + 3*x] - (125/7)*Log[1 + 5*x]}
{1/(x^3*(2*x + 13*x^2 + 15*x^3)), x, 5, -(1/(6*x^3)) + 13/(8*x^2) - 139/(8*x) - (1417*Log[x])/16 - (81/112)*Log[2 + 3*x] + (625/7)*Log[1 + 5*x]}


(* ::Subsection::Closed:: *)
(*Integrands involving powers of quartic trinomials*)


(* ::Subsubsection::Closed:: *)
(*Integrands of the form x^m (a+b x^2+c x^4)^n*)


(* Integrands of the form x^m*(a+b*x^2+c*x^4) where m is an integer *)
{x^4*(a + b*x^2 + c*x^4), x, 2, (a*x^5)/5 + (b*x^7)/7 + (c*x^9)/9}
{x^3*(a + b*x^2 + c*x^4), x, 2, (a*x^4)/4 + (b*x^6)/6 + (c*x^8)/8}
{x^2*(a + b*x^2 + c*x^4), x, 2, (a*x^3)/3 + (b*x^5)/5 + (c*x^7)/7}
{x*(a + b*x^2 + c*x^4), x, 2, (a*x^2)/2 + (b*x^4)/4 + (c*x^6)/6}
{(a + b*x^2 + c*x^4), x, 1, a*x + (b*x^3)/3 + (c*x^5)/5}
{(a + b*x^2 + c*x^4)/x, x, 2, (b*x^2)/2 + (c*x^4)/4 + a*Log[x]}
{(a + b*x^2 + c*x^4)/x^2, x, 2, -(a/x) + b*x + (c*x^3)/3}
{(a + b*x^2 + c*x^4)/x^3, x, 2, -(a/(2*x^2)) + (c*x^2)/2 + b*Log[x]}
{(a + b*x^2 + c*x^4)/x^4, x, 2, -(a/(3*x^3)) - b/x + c*x}


(* Integrands of the form x^m*(a+b*x^2+c*x^4)^2 where m is an integer *)
{x^4*(a + b*x^2 + c*x^4)^2, x, 2, (a^2*x^5)/5 + (2/7)*a*b*x^7 + (1/9)*(b^2 + 2*a*c)*x^9 + (2/11)*b*c*x^11 + (c^2*x^13)/13}
{x^3*(a + b*x^2 + c*x^4)^2, x, 3, (a^2*x^4)/4 + (1/3)*a*b*x^6 + (1/8)*(b^2 + 2*a*c)*x^8 + (1/5)*b*c*x^10 + (c^2*x^12)/12}
{x^2*(a + b*x^2 + c*x^4)^2, x, 2, (a^2*x^3)/3 + (2/5)*a*b*x^5 + (1/7)*(b^2 + 2*a*c)*x^7 + (2/9)*b*c*x^9 + (c^2*x^11)/11}
{x*(a + b*x^2 + c*x^4)^2, x, 3, (a^2*x^2)/2 + (1/2)*a*b*x^4 + (1/6)*(b^2 + 2*a*c)*x^6 + (1/4)*b*c*x^8 + (c^2*x^10)/10}
{(a + b*x^2 + c*x^4)^2, x, 2, a^2*x + (2/3)*a*b*x^3 + (1/5)*(b^2 + 2*a*c)*x^5 + (2/7)*b*c*x^7 + (c^2*x^9)/9}
{(a + b*x^2 + c*x^4)^2/x, x, 2, a*b*x^2 + (1/4)*(b^2 + 2*a*c)*x^4 + (1/3)*b*c*x^6 + (c^2*x^8)/8 + a^2*Log[x]}
{(a + b*x^2 + c*x^4)^2/x^2, x, 2, -(a^2/x) + 2*a*b*x + (1/3)*(b^2 + 2*a*c)*x^3 + (2/5)*b*c*x^5 + (c^2*x^7)/7}
{(a + b*x^2 + c*x^4)^2/x^3, x, 2, -(a^2/(2*x^2)) + (1/2)*(b^2 + 2*a*c)*x^2 + (1/2)*b*c*x^4 + (c^2*x^6)/6 + 2*a*b*Log[x]}
{(a + b*x^2 + c*x^4)^2/x^4, x, 2, -(a^2/(3*x^3)) - (2*a*b)/x + (b^2 + 2*a*c)*x + (2/3)*b*c*x^3 + (c^2*x^5)/5}
{(a + b*x^2 + c*x^4)^2/x^7, x, 2, -(a^2/(6*x^6)) - (a*b)/(2*x^4) - (b^2 + 2*a*c)/(2*x^2) + (c^2*x^2)/2 + 2*b*c*Log[x]}
{(a + b*x^2 + c*x^4)^2/x^13, x, 2, -(a^2/(12*x^12)) - (a*b)/(5*x^10) - (b^2 + 2*a*c)/(8*x^8) - (b*c)/(3*x^6) - c^2/(4*x^4)}


(* Integrands of the form x^m*(a+b*x^2+c*x^4)^3 where m is an integer *)
{x^4*(a + b*x^2 + c*x^4)^3, x, 2, (a^3*x^5)/5 + (3/7)*a^2*b*x^7 + (1/3)*a*(b^2 + a*c)*x^9 + (1/11)*b*(b^2 + 6*a*c)*x^11 + (3/13)*c*(b^2 + a*c)*x^13 + (1/5)*b*c^2*x^15 + (c^3*x^17)/17}
{x^3*(a + b*x^2 + c*x^4)^3, x, 3, (a^3*x^4)/4 + (1/2)*a^2*b*x^6 + (3/8)*a*(b^2 + a*c)*x^8 + (1/10)*b*(b^2 + 6*a*c)*x^10 + (1/4)*c*(b^2 + a*c)*x^12 + (3/14)*b*c^2*x^14 + (c^3*x^16)/16}
{x^2*(a + b*x^2 + c*x^4)^3, x, 2, (a^3*x^3)/3 + (3/5)*a^2*b*x^5 + (3/7)*a*(b^2 + a*c)*x^7 + (1/9)*b*(b^2 + 6*a*c)*x^9 + (3/11)*c*(b^2 + a*c)*x^11 + (3/13)*b*c^2*x^13 + (c^3*x^15)/15}
{x*(a + b*x^2 + c*x^4)^3, x, 3, (a^3*x^2)/2 + (3/4)*a^2*b*x^4 + (1/2)*a*(b^2 + a*c)*x^6 + (1/8)*b*(b^2 + 6*a*c)*x^8 + (3/10)*c*(b^2 + a*c)*x^10 + (1/4)*b*c^2*x^12 + (c^3*x^14)/14}
{(a + b*x^2 + c*x^4)^3, x, 2, a^3*x + a^2*b*x^3 + (3/5)*a*(b^2 + a*c)*x^5 + (1/7)*b*(b^2 + 6*a*c)*x^7 + (1/3)*c*(b^2 + a*c)*x^9 + (3/11)*b*c^2*x^11 + (c^3*x^13)/13}
{(a + b*x^2 + c*x^4)^3/x, x, 2, (3/2)*a^2*b*x^2 + (3/4)*a*(b^2 + a*c)*x^4 + (1/6)*b*(b^2 + 6*a*c)*x^6 + (3/8)*c*(b^2 + a*c)*x^8 + (3/10)*b*c^2*x^10 + (c^3*x^12)/12 + a^3*Log[x]}
{(a + b*x^2 + c*x^4)^3/x^2, x, 2, -(a^3/x) + 3*a^2*b*x + a*(b^2 + a*c)*x^3 + (1/5)*b*(b^2 + 6*a*c)*x^5 + (3/7)*c*(b^2 + a*c)*x^7 + (1/3)*b*c^2*x^9 + (c^3*x^11)/11}
{(a + b*x^2 + c*x^4)^3/x^3, x, 2, -(a^3/(2*x^2)) + (3/2)*a*(b^2 + a*c)*x^2 + (1/4)*b*(b^2 + 6*a*c)*x^4 + (1/2)*c*(b^2 + a*c)*x^6 + (3/8)*b*c^2*x^8 + (c^3*x^10)/10 + 3*a^2*b*Log[x]}
{(a + b*x^2 + c*x^4)^3/x^4, x, 2, -(a^3/(3*x^3)) - (3*a^2*b)/x + 3*a*(b^2 + a*c)*x + (1/3)*b*(b^2 + 6*a*c)*x^3 + (3/5)*c*(b^2 + a*c)*x^5 + (3/7)*b*c^2*x^7 + (c^3*x^9)/9}


(* Integrands of the form x^m/(a+b*x^2+c*x^4) where m is an integer *)
{x^4/(a + b*x^2 + c*x^4), x, 4, x/c - ((b - (b^2 - 2*a*c)/Sqrt[b^2 - 4*a*c])*ArcTan[(Sqrt[2]*Sqrt[c]*x)/Sqrt[b - Sqrt[b^2 - 4*a*c]]])/(Sqrt[2]*c^(3/2)*Sqrt[b - Sqrt[b^2 - 4*a*c]]) - ((b + (b^2 - 2*a*c)/Sqrt[b^2 - 4*a*c])*ArcTan[(Sqrt[2]*Sqrt[c]*x)/Sqrt[b + Sqrt[b^2 - 4*a*c]]])/(Sqrt[2]*c^(3/2)*Sqrt[b + Sqrt[b^2 - 4*a*c]])}
{x^3/(a + b*x^2 + c*x^4), x, 3, (b*ArcTanh[(b + 2*c*x^2)/Sqrt[b^2 - 4*a*c]])/(2*c*Sqrt[b^2 - 4*a*c]) + Log[a + b*x^2 + c*x^4]/(4*c)}
{x^2/(a + b*x^2 + c*x^4), x, 3, -((Sqrt[b - Sqrt[b^2 - 4*a*c]]*ArcTan[(Sqrt[2]*Sqrt[c]*x)/Sqrt[b - Sqrt[b^2 - 4*a*c]]])/(Sqrt[2]*Sqrt[c]*Sqrt[b^2 - 4*a*c])) + (Sqrt[b + Sqrt[b^2 - 4*a*c]]*ArcTan[(Sqrt[2]*Sqrt[c]*x)/Sqrt[b + Sqrt[b^2 - 4*a*c]]])/(Sqrt[2]*Sqrt[c]*Sqrt[b^2 - 4*a*c])}
{x/(a + b*x^2 + c*x^4), x, 2, -(ArcTanh[(b + 2*c*x^2)/Sqrt[b^2 - 4*a*c]]/Sqrt[b^2 - 4*a*c])}
{1/(a + b*x^2 + c*x^4), x, 3, (Sqrt[2]*Sqrt[c]*ArcTan[(Sqrt[2]*Sqrt[c]*x)/Sqrt[b - Sqrt[b^2 - 4*a*c]]])/(Sqrt[b^2 - 4*a*c]*Sqrt[b - Sqrt[b^2 - 4*a*c]]) - (Sqrt[2]*Sqrt[c]*ArcTan[(Sqrt[2]*Sqrt[c]*x)/Sqrt[b + Sqrt[b^2 - 4*a*c]]])/(Sqrt[b^2 - 4*a*c]*Sqrt[b + Sqrt[b^2 - 4*a*c]])}
{1/(x*(a + b*x^2 + c*x^4)), x, 3, (b*ArcTanh[(b + 2*c*x^2)/Sqrt[b^2 - 4*a*c]])/(2*a*Sqrt[b^2 - 4*a*c]) + Log[x]/a - Log[a + b*x^2 + c*x^4]/(4*a)}
{1/(x^2*(a + b*x^2 + c*x^4)), x, 4, -(1/(a*x)) - (Sqrt[c]*(1 + b/Sqrt[b^2 - 4*a*c])*ArcTan[(Sqrt[2]*Sqrt[c]*x)/Sqrt[b - Sqrt[b^2 - 4*a*c]]])/(Sqrt[2]*a*Sqrt[b - Sqrt[b^2 - 4*a*c]]) - (Sqrt[c]*(1 - b/Sqrt[b^2 - 4*a*c])*ArcTan[(Sqrt[2]*Sqrt[c]*x)/Sqrt[b + Sqrt[b^2 - 4*a*c]]])/(Sqrt[2]*a*Sqrt[b + Sqrt[b^2 - 4*a*c]])}
{1/(x^3*(a + b*x^2 + c*x^4)), x, 4, -(1/(2*a*x^2)) - ((b^2 - 2*a*c)*ArcTanh[(b + 2*c*x^2)/Sqrt[b^2 - 4*a*c]])/(2*a^2*Sqrt[b^2 - 4*a*c]) - (b*Log[x])/a^2 + (b*Log[a + b*x^2 + c*x^4])/(4*a^2)}

{x^4/(a - b*x^2 + c*x^4), x, 4, x/c - ((b - (b^2 - 2*a*c)/Sqrt[b^2 - 4*a*c])*ArcTanh[(Sqrt[2]*Sqrt[c]*x)/Sqrt[b - Sqrt[b^2 - 4*a*c]]])/(Sqrt[2]*c^(3/2)*Sqrt[b - Sqrt[b^2 - 4*a*c]]) - ((b + (b^2 - 2*a*c)/Sqrt[b^2 - 4*a*c])*ArcTanh[(Sqrt[2]*Sqrt[c]*x)/Sqrt[b + Sqrt[b^2 - 4*a*c]]])/(Sqrt[2]*c^(3/2)*Sqrt[b + Sqrt[b^2 - 4*a*c]])}
{x^3/(a - b*x^2 + c*x^4), x, 3, (b*ArcTanh[(b - 2*c*x^2)/Sqrt[b^2 - 4*a*c]])/(2*c*Sqrt[b^2 - 4*a*c]) + Log[a - b*x^2 + c*x^4]/(4*c)}
{x^2/(a - b*x^2 + c*x^4), x, 3, (Sqrt[b - Sqrt[b^2 - 4*a*c]]*ArcTanh[(Sqrt[2]*Sqrt[c]*x)/Sqrt[b - Sqrt[b^2 - 4*a*c]]])/(Sqrt[2]*Sqrt[c]*Sqrt[b^2 - 4*a*c]) - (Sqrt[b + Sqrt[b^2 - 4*a*c]]*ArcTanh[(Sqrt[2]*Sqrt[c]*x)/Sqrt[b + Sqrt[b^2 - 4*a*c]]])/(Sqrt[2]*Sqrt[c]*Sqrt[b^2 - 4*a*c])}
{x/(a - b*x^2 + c*x^4), x, 2, ArcTanh[(b - 2*c*x^2)/Sqrt[b^2 - 4*a*c]]/Sqrt[b^2 - 4*a*c]}
{1/(a - b*x^2 + c*x^4), x, 3, (Sqrt[2]*Sqrt[c]*ArcTanh[(Sqrt[2]*Sqrt[c]*x)/Sqrt[b - Sqrt[b^2 - 4*a*c]]])/(Sqrt[b^2 - 4*a*c]*Sqrt[b - Sqrt[b^2 - 4*a*c]]) - (Sqrt[2]*Sqrt[c]*ArcTanh[(Sqrt[2]*Sqrt[c]*x)/Sqrt[b + Sqrt[b^2 - 4*a*c]]])/(Sqrt[b^2 - 4*a*c]*Sqrt[b + Sqrt[b^2 - 4*a*c]])}


(* Integrands of the form x^m/(a+b*x^2+c*x^4)^2 where m is an integer *)
{x^4/(a + b*x^2 + c*x^4)^2, x, 5, -(x/(3*c*(a + b*x^2 + c*x^4))) - (x*(2*a - (2*b^2)/c - 3*b*x^2))/(6*(b^2 - 4*a*c)*(a + b*x^2 + c*x^4)) - ((b^2 + 4*a*c - b*Sqrt[b^2 - 4*a*c])*ArcTan[(Sqrt[2]*Sqrt[c]*x)/Sqrt[b - Sqrt[b^2 - 4*a*c]]])/(2*Sqrt[2]*Sqrt[c]*(b^2 - 4*a*c)^(3/2)*Sqrt[b - Sqrt[b^2 - 4*a*c]]) + ((b^2 + 4*a*c + b*Sqrt[b^2 - 4*a*c])*ArcTan[(Sqrt[2]*Sqrt[c]*x)/Sqrt[b + Sqrt[b^2 - 4*a*c]]])/(2*Sqrt[2]*Sqrt[c]*(b^2 - 4*a*c)^(3/2)*Sqrt[b + Sqrt[b^2 - 4*a*c]])}
{x^3/(a + b*x^2 + c*x^4)^2, x, 4, (2*a + b*x^2)/(2*(b^2 - 4*a*c)*(a + b*x^2 + c*x^4)) - (b*ArcTanh[(b + 2*c*x^2)/Sqrt[b^2 - 4*a*c]])/(b^2 - 4*a*c)^(3/2)}
{x^2/(a + b*x^2 + c*x^4)^2, x, 4, -((x*(b + 2*c*x^2))/(2*(b^2 - 4*a*c)*(a + b*x^2 + c*x^4))) + (Sqrt[c]*(2*b - Sqrt[b^2 - 4*a*c])*ArcTan[(Sqrt[2]*Sqrt[c]*x)/Sqrt[b - Sqrt[b^2 - 4*a*c]]])/(Sqrt[2]*(b^2 - 4*a*c)^(3/2)*Sqrt[b - Sqrt[b^2 - 4*a*c]]) - (Sqrt[c]*(2*b + Sqrt[b^2 - 4*a*c])*ArcTan[(Sqrt[2]*Sqrt[c]*x)/Sqrt[b + Sqrt[b^2 - 4*a*c]]])/(Sqrt[2]*(b^2 - 4*a*c)^(3/2)*Sqrt[b + Sqrt[b^2 - 4*a*c]])}
{x/(a + b*x^2 + c*x^4)^2, x, 3, -((b + 2*c*x^2)/(2*(b^2 - 4*a*c)*(a + b*x^2 + c*x^4))) + (2*c*ArcTanh[(b + 2*c*x^2)/Sqrt[b^2 - 4*a*c]])/(b^2 - 4*a*c)^(3/2)}
{1/(a + b*x^2 + c*x^4)^2, x, 4, (x*(b^2 - 2*a*c + b*c*x^2))/(2*a*(b^2 - 4*a*c)*(a + b*x^2 + c*x^4)) + (Sqrt[c]*(b^2 - 12*a*c + b*Sqrt[b^2 - 4*a*c])*ArcTan[(Sqrt[2]*Sqrt[c]*x)/Sqrt[b - Sqrt[b^2 - 4*a*c]]])/(2*Sqrt[2]*a*(b^2 - 4*a*c)^(3/2)*Sqrt[b - Sqrt[b^2 - 4*a*c]]) - (Sqrt[c]*(b^2 - 12*a*c - b*Sqrt[b^2 - 4*a*c])*ArcTan[(Sqrt[2]*Sqrt[c]*x)/Sqrt[b + Sqrt[b^2 - 4*a*c]]])/(2*Sqrt[2]*a*(b^2 - 4*a*c)^(3/2)*Sqrt[b + Sqrt[b^2 - 4*a*c]])}
{1/(x*(a + b*x^2 + c*x^4)^2), x, 11, 1/(4*a*(a + b*x^2 + c*x^4)) + (b*(b + 2*c*x^2))/(4*a*(b^2 - 4*a*c)*(a + b*x^2 + c*x^4)) - (b*c*ArcTanh[(b + 2*c*x^2)/Sqrt[b^2 - 4*a*c]])/(a*(b^2 - 4*a*c)^(3/2)) + (b*ArcTanh[(b + 2*c*x^2)/Sqrt[b^2 - 4*a*c]])/(2*a^2*Sqrt[b^2 - 4*a*c]) + Log[x]/a^2 - Log[a + b*x^2 + c*x^4]/(4*a^2)}
{1/(x^2*(a + b*x^2 + c*x^4)^2), x, 10, -(1/(a^2*x)) - (x*(b^3 - 3*a*b*c + c*(b^2 - 2*a*c)*x^2))/(2*a^2*(b^2 - 4*a*c)*(a + b*x^2 + c*x^4)) - (Sqrt[c]*(3*b^3 - 16*a*b*c + 3*b^2*Sqrt[b^2 - 4*a*c] - 10*a*c*Sqrt[b^2 - 4*a*c])*ArcTan[(Sqrt[2]*Sqrt[c]*x)/Sqrt[b - Sqrt[b^2 - 4*a*c]]])/(2*Sqrt[2]*a^2*(b^2 - 4*a*c)^(3/2)*Sqrt[b - Sqrt[b^2 - 4*a*c]]) + (Sqrt[c]*(3*b^3 - 16*a*b*c - 3*b^2*Sqrt[b^2 - 4*a*c] + 10*a*c*Sqrt[b^2 - 4*a*c])*ArcTan[(Sqrt[2]*Sqrt[c]*x)/Sqrt[b + Sqrt[b^2 - 4*a*c]]])/(2*Sqrt[2]*a^2*(b^2 - 4*a*c)^(3/2)*Sqrt[b + Sqrt[b^2 - 4*a*c]]), -(1/(a^2*x)) + (x*(-b^3 + 3*a*b*c + c*(-b^2 + 2*a*c)*x^2))/(2*a^2*(b^2 - 4*a*c)*(a + b*x^2 + c*x^4)) - ((c + (b*c)/Sqrt[b^2 - 4*a*c])*ArcTan[(Sqrt[2]*Sqrt[c]*x)/Sqrt[b - Sqrt[b^2 - 4*a*c]]])/(Sqrt[2]*a^2*Sqrt[c]*Sqrt[b - Sqrt[b^2 - 4*a*c]]) - (((-c)*(-b^2 + 2*a*c) + (b*c*(-b^2 + 2*a*c) + 2*c*(-b^3 + 3*a*b*c + 2*b*(b^2 - 4*a*c)))/Sqrt[b^2 - 4*a*c])*ArcTan[(Sqrt[2]*Sqrt[c]*x)/Sqrt[b - Sqrt[b^2 - 4*a*c]]])/(2*Sqrt[2]*a^2*Sqrt[c]*(b^2 - 4*a*c)*Sqrt[b - Sqrt[b^2 - 4*a*c]]) - ((c - (b*c)/Sqrt[b^2 - 4*a*c])*ArcTan[(Sqrt[2]*Sqrt[c]*x)/Sqrt[b + Sqrt[b^2 - 4*a*c]]])/(Sqrt[2]*a^2*Sqrt[c]*Sqrt[b + Sqrt[b^2 - 4*a*c]]) - (((-c)*(-b^2 + 2*a*c) - (b*c*(-b^2 + 2*a*c) + 2*c*(-b^3 + 3*a*b*c + 2*b*(b^2 - 4*a*c)))/Sqrt[b^2 - 4*a*c])*ArcTan[(Sqrt[2]*Sqrt[c]*x)/Sqrt[b + Sqrt[b^2 - 4*a*c]]])/(2*Sqrt[2]*a^2*Sqrt[c]*(b^2 - 4*a*c)*Sqrt[b + Sqrt[b^2 - 4*a*c]])}
{1/(x^3*(a + b*x^2 + c*x^4)^2), x, 11, -(1/(2*a^2*x^2)) - b/(4*a^2*(a + b*x^2 + c*x^4)) - ((b^2 - 2*a*c)*(b + 2*c*x^2))/(4*a^2*(b^2 - 4*a*c)*(a + b*x^2 + c*x^4)) + (c*(b^2 - 2*a*c)*ArcTanh[(b + 2*c*x^2)/Sqrt[b^2 - 4*a*c]])/(a^2*(b^2 - 4*a*c)^(3/2)) - ((b^2 - a*c)*ArcTanh[(b + 2*c*x^2)/Sqrt[b^2 - 4*a*c]])/(a^3*Sqrt[b^2 - 4*a*c]) - (2*b*Log[x])/a^3 + (b*Log[a + b*x^2 + c*x^4])/(2*a^3)}
{1/(x^4*(a + b*x^2 + c*x^4)^2), x, 10, -(1/(3*a^2*x^3)) + (2*b)/(a^3*x) + (x*(b^4 - 4*a*b^2*c + 2*a^2*c^2 + b*c*(b^2 - 3*a*c)*x^2))/(2*a^3*(b^2 - 4*a*c)*(a + b*x^2 + c*x^4)) + (Sqrt[c]*(5*b^4 - 29*a*b^2*c + 28*a^2*c^2 + 5*b^3*Sqrt[b^2 - 4*a*c] - 19*a*b*c*Sqrt[b^2 - 4*a*c])*ArcTan[(Sqrt[2]*Sqrt[c]*x)/Sqrt[b - Sqrt[b^2 - 4*a*c]]])/(2*Sqrt[2]*a^3*(b^2 - 4*a*c)^(3/2)*Sqrt[b - Sqrt[b^2 - 4*a*c]]) - (Sqrt[c]*(5*b^4 - 29*a*b^2*c + 28*a^2*c^2 - 5*b^3*Sqrt[b^2 - 4*a*c] + 19*a*b*c*Sqrt[b^2 - 4*a*c])*ArcTan[(Sqrt[2]*Sqrt[c]*x)/Sqrt[b + Sqrt[b^2 - 4*a*c]]])/(2*Sqrt[2]*a^3*(b^2 - 4*a*c)^(3/2)*Sqrt[b + Sqrt[b^2 - 4*a*c]]), -(1/(3*a^2*x^3)) + (2*b)/(a^3*x) - (x*(a*b^2*c - b^2*(b^2 - a*c) + 2*a*c*(b^2 - a*c) + c*(2*a*b*c - b*(b^2 - a*c))*x^2))/(2*a^3*(b^2 - 4*a*c)*(a + b*x^2 + c*x^4)) + ((2*b*c + (-2*b^2*c + 2*c*(2*b^2 - a*c))/Sqrt[b^2 - 4*a*c])*ArcTan[(Sqrt[2]*Sqrt[c]*x)/Sqrt[b - Sqrt[b^2 - 4*a*c]]])/(Sqrt[2]*a^3*Sqrt[c]*Sqrt[b - Sqrt[b^2 - 4*a*c]]) + (((-c)*(2*a*b*c - b*(b^2 - a*c)) + (b*c*(2*a*b*c - b*(b^2 - a*c)) + 2*c*(a*b^2*c - b^2*(b^2 - a*c) + 2*a*c*(b^2 - a*c) + 2*(b^2 - 4*a*c)*(b^2 - a*c)))/Sqrt[b^2 - 4*a*c])*ArcTan[(Sqrt[2]*Sqrt[c]*x)/Sqrt[b - Sqrt[b^2 - 4*a*c]]])/(2*Sqrt[2]*a^3*Sqrt[c]*(b^2 - 4*a*c)*Sqrt[b - Sqrt[b^2 - 4*a*c]]) + ((2*b*c - (-2*b^2*c + 2*c*(2*b^2 - a*c))/Sqrt[b^2 - 4*a*c])*ArcTan[(Sqrt[2]*Sqrt[c]*x)/Sqrt[b + Sqrt[b^2 - 4*a*c]]])/(Sqrt[2]*a^3*Sqrt[c]*Sqrt[b + Sqrt[b^2 - 4*a*c]]) + (((-c)*(2*a*b*c - b*(b^2 - a*c)) - (b*c*(2*a*b*c - b*(b^2 - a*c)) + 2*c*(a*b^2*c - b^2*(b^2 - a*c) + 2*a*c*(b^2 - a*c) + 2*(b^2 - 4*a*c)*(b^2 - a*c)))/Sqrt[b^2 - 4*a*c])*ArcTan[(Sqrt[2]*Sqrt[c]*x)/Sqrt[b + Sqrt[b^2 - 4*a*c]]])/(2*Sqrt[2]*a^3*Sqrt[c]*(b^2 - 4*a*c)*Sqrt[b + Sqrt[b^2 - 4*a*c]])}


(* Integrands of the form x^m/(a+b*x^2+c*x^4)^3 where m is an integer *)
{x^4/(a + b*x^2 + c*x^4)^3, x, 6, -(x/(7*c*(a + b*x^2 + c*x^4)^2)) - (x*(2*a - (4*b^2)/c - 7*b*x^2))/(28*(b^2 - 4*a*c)*(a + b*x^2 + c*x^4)^2) - (x*(7*b^2 - 4*a*c + 12*b*c*x^2))/(8*(b^2 - 4*a*c)^2*(a + b*x^2 + c*x^4)) + (3*Sqrt[c]*(3*b^2 + 4*a*c - 2*b*Sqrt[b^2 - 4*a*c])*ArcTan[(Sqrt[2]*Sqrt[c]*x)/Sqrt[b - Sqrt[b^2 - 4*a*c]]])/(4*Sqrt[2]*(b^2 - 4*a*c)^(5/2)*Sqrt[b - Sqrt[b^2 - 4*a*c]]) - (3*Sqrt[c]*(3*b^2 + 4*a*c + 2*b*Sqrt[b^2 - 4*a*c])*ArcTan[(Sqrt[2]*Sqrt[c]*x)/Sqrt[b + Sqrt[b^2 - 4*a*c]]])/(4*Sqrt[2]*(b^2 - 4*a*c)^(5/2)*Sqrt[b + Sqrt[b^2 - 4*a*c]])}
{x^3/(a + b*x^2 + c*x^4)^3, x, 5, (2*a + b*x^2)/(4*(b^2 - 4*a*c)*(a + b*x^2 + c*x^4)^2) - (3*b*(b + 2*c*x^2))/(4*(b^2 - 4*a*c)^2*(a + b*x^2 + c*x^4)) + (3*b*c*ArcTanh[(b + 2*c*x^2)/Sqrt[b^2 - 4*a*c]])/(b^2 - 4*a*c)^(5/2)}
{x^2/(a + b*x^2 + c*x^4)^3, x, 5, -((x*(b + 2*c*x^2))/(4*(b^2 - 4*a*c)*(a + b*x^2 + c*x^4)^2)) + (x*(b^3 + 8*a*b*c + c*(b^2 + 20*a*c)*x^2))/(8*a*(b^2 - 4*a*c)^2*(a + b*x^2 + c*x^4)) + (Sqrt[c]*(b*(b^2 - 52*a*c) + Sqrt[b^2 - 4*a*c]*(b^2 + 20*a*c))*ArcTan[(Sqrt[2]*Sqrt[c]*x)/Sqrt[b - Sqrt[b^2 - 4*a*c]]])/(8*Sqrt[2]*a*(b^2 - 4*a*c)^(5/2)*Sqrt[b - Sqrt[b^2 - 4*a*c]]) - (Sqrt[c]*(b*(b^2 - 52*a*c) - Sqrt[b^2 - 4*a*c]*(b^2 + 20*a*c))*ArcTan[(Sqrt[2]*Sqrt[c]*x)/Sqrt[b + Sqrt[b^2 - 4*a*c]]])/(8*Sqrt[2]*a*(b^2 - 4*a*c)^(5/2)*Sqrt[b + Sqrt[b^2 - 4*a*c]])}
{x/(a + b*x^2 + c*x^4)^3, x, 4, -((b + 2*c*x^2)/(4*(b^2 - 4*a*c)*(a + b*x^2 + c*x^4)^2)) + (3*c*(b + 2*c*x^2))/(2*(b^2 - 4*a*c)^2*(a + b*x^2 + c*x^4)) - (6*c^2*ArcTanh[(b + 2*c*x^2)/Sqrt[b^2 - 4*a*c]])/(b^2 - 4*a*c)^(5/2)}
{1/(a + b*x^2 + c*x^4)^3, x, 5, (x*(b^2 - 2*a*c + b*c*x^2))/(4*a*(b^2 - 4*a*c)*(a + b*x^2 + c*x^4)^2) + (x*(3*b^4 - 25*a*b^2*c + 28*a^2*c^2 + 3*b*c*(b^2 - 8*a*c)*x^2))/(8*a^2*(b^2 - 4*a*c)^2*(a + b*x^2 + c*x^4)) - (Sqrt[c]*(9*b^4 - 3*b*(b^2 - 8*a*c)*Sqrt[b^2 - 4*a*c] - 2*(37*a*b^2*c - 28*a^2*c^2 + 2*(3*b^2 - 14*a*c)*(b^2 - 4*a*c)))*ArcTan[(Sqrt[2]*Sqrt[c]*x)/Sqrt[b - Sqrt[b^2 - 4*a*c]]])/(8*Sqrt[2]*a^2*(b^2 - 4*a*c)^(5/2)*Sqrt[b - Sqrt[b^2 - 4*a*c]]) + (Sqrt[c]*(9*b^4 + 3*b*(b^2 - 8*a*c)*Sqrt[b^2 - 4*a*c] - 2*(37*a*b^2*c - 28*a^2*c^2 + 2*(3*b^2 - 14*a*c)*(b^2 - 4*a*c)))*ArcTan[(Sqrt[2]*Sqrt[c]*x)/Sqrt[b + Sqrt[b^2 - 4*a*c]]])/(8*Sqrt[2]*a^2*(b^2 - 4*a*c)^(5/2)*Sqrt[b + Sqrt[b^2 - 4*a*c]])}
{1/(x*(a + b*x^2 + c*x^4)^3), x, 17, 1/(8*a*(a + b*x^2 + c*x^4)^2) + (b*(b + 2*c*x^2))/(8*a*(b^2 - 4*a*c)*(a + b*x^2 + c*x^4)^2) + 1/(4*a^2*(a + b*x^2 + c*x^4)) - (3*b*c*(b + 2*c*x^2))/(4*a*(b^2 - 4*a*c)^2*(a + b*x^2 + c*x^4)) + (b*(b + 2*c*x^2))/(4*a^2*(b^2 - 4*a*c)*(a + b*x^2 + c*x^4)) + (3*b*c^2*ArcTanh[(b + 2*c*x^2)/Sqrt[b^2 - 4*a*c]])/(a*(b^2 - 4*a*c)^(5/2)) - (b*c*ArcTanh[(b + 2*c*x^2)/Sqrt[b^2 - 4*a*c]])/(a^2*(b^2 - 4*a*c)^(3/2)) + (b*ArcTanh[(b + 2*c*x^2)/Sqrt[b^2 - 4*a*c]])/(2*a^3*Sqrt[b^2 - 4*a*c]) + Log[x]/a^3 - Log[a + b*x^2 + c*x^4]/(4*a^3)}
{1/(x^2*(a + b*x^2 + c*x^4)^3), x, 15, -(1/(a^3*x)) - (x*(b^3 - 3*a*b*c + c*(b^2 - 2*a*c)*x^2))/(4*a^2*(b^2 - 4*a*c)*(a + b*x^2 + c*x^4)^2) - (x*(b^3 - 3*a*b*c + c*(b^2 - 2*a*c)*x^2))/(2*a^3*(b^2 - 4*a*c)*(a + b*x^2 + c*x^4)) - (x*(3*b^5 - 24*a*b^3*c + 36*a^2*b*c^2 + c*(3*b^4 - 10*a*c*((23*b^2)/10 - 2*a*c))*x^2))/(8*a^3*(b^2 - 4*a*c)^2*(a + b*x^2 + c*x^4)) - (Sqrt[c]*(1 + b/Sqrt[b^2 - 4*a*c])*ArcTan[(Sqrt[2]*Sqrt[c]*x)/Sqrt[b - Sqrt[b^2 - 4*a*c]]])/(Sqrt[2]*a^3*Sqrt[b - Sqrt[b^2 - 4*a*c]]) - (Sqrt[c]*(b*(b^2 - 8*a*c) + Sqrt[b^2 - 4*a*c]*(b^2 - 2*a*c))*ArcTan[(Sqrt[2]*Sqrt[c]*x)/Sqrt[b - Sqrt[b^2 - 4*a*c]]])/(2*Sqrt[2]*a^3*(b^2 - 4*a*c)^(3/2)*Sqrt[b - Sqrt[b^2 - 4*a*c]]) - (Sqrt[c]*(Sqrt[b^2 - 4*a*c]*(3*b^4 - a*c*(23*b^2 - 20*a*c)) - b*(9*b^4 - 71*a*b^2*c + 92*a^2*c^2 - 4*(3*b^2 - 13*a*c)*(b^2 - 4*a*c)))*ArcTan[(Sqrt[2]*Sqrt[c]*x)/Sqrt[b - Sqrt[b^2 - 4*a*c]]])/(8*Sqrt[2]*a^3*(b^2 - 4*a*c)^(5/2)*Sqrt[b - Sqrt[b^2 - 4*a*c]]) - (Sqrt[c]*(1 - b/Sqrt[b^2 - 4*a*c])*ArcTan[(Sqrt[2]*Sqrt[c]*x)/Sqrt[b + Sqrt[b^2 - 4*a*c]]])/(Sqrt[2]*a^3*Sqrt[b + Sqrt[b^2 - 4*a*c]]) + (Sqrt[c]*(b*(b^2 - 8*a*c) - Sqrt[b^2 - 4*a*c]*(b^2 - 2*a*c))*ArcTan[(Sqrt[2]*Sqrt[c]*x)/Sqrt[b + Sqrt[b^2 - 4*a*c]]])/(2*Sqrt[2]*a^3*(b^2 - 4*a*c)^(3/2)*Sqrt[b + Sqrt[b^2 - 4*a*c]]) - (Sqrt[c]*(Sqrt[b^2 - 4*a*c]*(3*b^4 - a*c*(23*b^2 - 20*a*c)) + b*(9*b^4 - 71*a*b^2*c + 92*a^2*c^2 - 4*(3*b^2 - 13*a*c)*(b^2 - 4*a*c)))*ArcTan[(Sqrt[2]*Sqrt[c]*x)/Sqrt[b + Sqrt[b^2 - 4*a*c]]])/(8*Sqrt[2]*a^3*(b^2 - 4*a*c)^(5/2)*Sqrt[b + Sqrt[b^2 - 4*a*c]])}
{1/(x^3*(a + b*x^2 + c*x^4)^3), x, 17, -(1/(2*a^3*x^2)) - b/(8*a^2*(a + b*x^2 + c*x^4)^2) - ((b^2 - 2*a*c)*(b + 2*c*x^2))/(8*a^2*(b^2 - 4*a*c)*(a + b*x^2 + c*x^4)^2) - b/(2*a^3*(a + b*x^2 + c*x^4)) + (3*c*(b^2 - 2*a*c)*(b + 2*c*x^2))/(4*a^2*(b^2 - 4*a*c)^2*(a + b*x^2 + c*x^4)) - ((b^2 - a*c)*(b + 2*c*x^2))/(2*a^3*(b^2 - 4*a*c)*(a + b*x^2 + c*x^4)) - (3*c^2*(b^2 - 2*a*c)*ArcTanh[(b + 2*c*x^2)/Sqrt[b^2 - 4*a*c]])/(a^2*(b^2 - 4*a*c)^(5/2)) - ((3*b^2 - 2*a*c)*ArcTanh[(b + 2*c*x^2)/Sqrt[b^2 - 4*a*c]])/(2*a^4*Sqrt[b^2 - 4*a*c]) + (2*c*(b^2 - a*c)*ArcTanh[(b + 2*c*x^2)/Sqrt[b^2 - 4*a*c]])/(a^3*(b^2 - 4*a*c)^(3/2)) - (3*b*Log[x])/a^4 + (3*b*Log[a + b*x^2 + c*x^4])/(4*a^4)}
{1/(x^4*(a + b*x^2 + c*x^4)^3), x, 15, -(1/(3*a^3*x^3)) + (3*b)/(a^4*x) - (x*(a*b^2*c - b^2*(b^2 - a*c) + 2*a*c*(b^2 - a*c) + c*(2*a*b*c - b*(b^2 - a*c))*x^2))/(4*a^3*(b^2 - 4*a*c)*(a + b*x^2 + c*x^4)^2) - (x*(2*a*b^2*c - b^2*(2*b^2 - a*c) + 2*a*c*(2*b^2 - a*c) + c*(4*a*b*c - b*(2*b^2 - a*c))*x^2))/(2*a^4*(b^2 - 4*a*c)*(a + b*x^2 + c*x^4)) - (1/(8*a^4*(b^2 - 4*a*c)^2*(a + b*x^2 + c*x^4)))*(x*(-5*a*b*c*(2*a*b*c - b*(b^2 - a*c)) - b^2*(a*b^2*c - b^2*(b^2 - a*c) + 2*a*c*(b^2 - a*c) + 4*(b^2 - 4*a*c)*(b^2 - a*c)) + 2*a*c*(a*b^2*c - b^2*(b^2 - a*c) + 2*a*c*(b^2 - a*c) + 4*(b^2 - 4*a*c)*(b^2 - a*c)) + c*(-10*a*c*(2*a*b*c - b*(b^2 - a*c)) - b*(a*b^2*c - b^2*(b^2 - a*c) + 2*a*c*(b^2 - a*c) + 4*(b^2 - 4*a*c)*(b^2 - a*c)))*x^2)) + ((3*b*c + (-3*b^2*c + 2*c*(3*b^2 - a*c))/Sqrt[b^2 - 4*a*c])*ArcTan[(Sqrt[2]*Sqrt[c]*x)/Sqrt[b - Sqrt[b^2 - 4*a*c]]])/(Sqrt[2]*a^4*Sqrt[c]*Sqrt[b - Sqrt[b^2 - 4*a*c]]) + (((-c)*(4*a*b*c - b*(2*b^2 - a*c)) + (b*c*(4*a*b*c - b*(2*b^2 - a*c)) + 2*c*(2*a*b^2*c - b^2*(2*b^2 - a*c) + 2*a*c*(2*b^2 - a*c) + 2*(b^2 - 4*a*c)*(2*b^2 - a*c)))/Sqrt[b^2 - 4*a*c])*ArcTan[(Sqrt[2]*Sqrt[c]*x)/Sqrt[b - Sqrt[b^2 - 4*a*c]]])/(2*Sqrt[2]*a^4*Sqrt[c]*(b^2 - 4*a*c)*Sqrt[b - Sqrt[b^2 - 4*a*c]]) + (1/(8*Sqrt[2]*a^4*Sqrt[c]*(b^2 - 4*a*c)^2*Sqrt[b - Sqrt[b^2 - 4*a*c]]))*(((-c)*(-10*a*c*(2*a*b*c - b*(b^2 - a*c)) - b*(a*b^2*c - b^2*(b^2 - a*c) + 2*a*c*(b^2 - a*c) + 4*(b^2 - 4*a*c)*(b^2 - a*c))) + (1/Sqrt[b^2 - 4*a*c])*(b*c*(-10*a*c*(2*a*b*c - b*(b^2 - a*c)) - b*(a*b^2*c - b^2*(b^2 - a*c) + 2*a*c*(b^2 - a*c) + 4*(b^2 - 4*a*c)*(b^2 - a*c))) + 2*c*(-5*a*b*c*(2*a*b*c - b*(b^2 - a*c)) - b^2*(a*b^2*c - b^2*(b^2 - a*c) + 2*a*c*(b^2 - a*c) + 4*(b^2 - 4*a*c)*(b^2 - a*c)) + 2*a*c*(a*b^2*c - b^2*(b^2 - a*c) + 2*a*c*(b^2 - a*c) + 4*(b^2 - 4*a*c)*(b^2 - a*c)) + 2*(b^2 - 4*a*c)*(a*b^2*c - b^2*(b^2 - a*c) + 2*a*c*(b^2 - a*c) + 4*(b^2 - 4*a*c)*(b^2 - a*c)))))*ArcTan[(Sqrt[2]*Sqrt[c]*x)/Sqrt[b - Sqrt[b^2 - 4*a*c]]]) + ((3*b*c - (-3*b^2*c + 2*c*(3*b^2 - a*c))/Sqrt[b^2 - 4*a*c])*ArcTan[(Sqrt[2]*Sqrt[c]*x)/Sqrt[b + Sqrt[b^2 - 4*a*c]]])/(Sqrt[2]*a^4*Sqrt[c]*Sqrt[b + Sqrt[b^2 - 4*a*c]]) + (((-c)*(4*a*b*c - b*(2*b^2 - a*c)) - (b*c*(4*a*b*c - b*(2*b^2 - a*c)) + 2*c*(2*a*b^2*c - b^2*(2*b^2 - a*c) + 2*a*c*(2*b^2 - a*c) + 2*(b^2 - 4*a*c)*(2*b^2 - a*c)))/Sqrt[b^2 - 4*a*c])*ArcTan[(Sqrt[2]*Sqrt[c]*x)/Sqrt[b + Sqrt[b^2 - 4*a*c]]])/(2*Sqrt[2]*a^4*Sqrt[c]*(b^2 - 4*a*c)*Sqrt[b + Sqrt[b^2 - 4*a*c]]) + (1/(8*Sqrt[2]*a^4*Sqrt[c]*(b^2 - 4*a*c)^2*Sqrt[b + Sqrt[b^2 - 4*a*c]]))*(((-c)*(-10*a*c*(2*a*b*c - b*(b^2 - a*c)) - b*(a*b^2*c - b^2*(b^2 - a*c) + 2*a*c*(b^2 - a*c) + 4*(b^2 - 4*a*c)*(b^2 - a*c))) - (1/Sqrt[b^2 - 4*a*c])*(b*c*(-10*a*c*(2*a*b*c - b*(b^2 - a*c)) - b*(a*b^2*c - b^2*(b^2 - a*c) + 2*a*c*(b^2 - a*c) + 4*(b^2 - 4*a*c)*(b^2 - a*c))) + 2*c*(-5*a*b*c*(2*a*b*c - b*(b^2 - a*c)) - b^2*(a*b^2*c - b^2*(b^2 - a*c) + 2*a*c*(b^2 - a*c) + 4*(b^2 - 4*a*c)*(b^2 - a*c)) + 2*a*c*(a*b^2*c - b^2*(b^2 - a*c) + 2*a*c*(b^2 - a*c) + 4*(b^2 - 4*a*c)*(b^2 - a*c)) + 2*(b^2 - 4*a*c)*(a*b^2*c - b^2*(b^2 - a*c) + 2*a*c*(b^2 - a*c) + 4*(b^2 - 4*a*c)*(b^2 - a*c)))))*ArcTan[(Sqrt[2]*Sqrt[c]*x)/Sqrt[b + Sqrt[b^2 - 4*a*c]]])}


(* Integrands of the form x^m/(a+b*x^n+c*x^(2*n)) where m and n>0 are integers *)
{1/(a^2 + b + 2*a*x^2 + x^4), x, 3, ArcTan[x/Sqrt[a - Sqrt[-b]]]/(2*Sqrt[a - Sqrt[-b]]*Sqrt[-b]) - ArcTan[x/Sqrt[a + Sqrt[-b]]]/(2*Sqrt[a + Sqrt[-b]]*Sqrt[-b])}
{1/(-1 + a^2 + 2*a*x^2 + x^4), x, 3, -(ArcTan[x/Sqrt[1 + a]]/(2*Sqrt[1 + a])) - ArcTanh[x/Sqrt[1 - a]]/(2*Sqrt[1 - a])}
(* Tests that NegativeQ[b^2-4*a*c] returns True to avoid I in antiderivative! *)
{1/(1 + a^2 + 2*a*x^2 + x^4), x, 3, ArcTan[(Sqrt[2]*Sqrt[1 + a^2 + a*Sqrt[1 + a^2]]*x)/((1 + a^2)^(1/4)*(Sqrt[1 + a^2] - x^2))]/(2*Sqrt[2]*(1 + a^2)^(1/4)*Sqrt[1 + a^2 + a*Sqrt[1 + a^2]]) + ArcTanh[(Sqrt[2]*Sqrt[1 + a^2 - a*Sqrt[1 + a^2]]*x)/((1 + a^2)^(1/4)*(Sqrt[1 + a^2] + x^2))]/(2*Sqrt[2]*(1 + a^2)^(1/4)*Sqrt[1 + a^2 - a*Sqrt[1 + a^2]])}

{1/(1 + 2*x^2 + x^4), x, 3, x/(2*(1 + x^2)) + ArcTan[x]/2}
{1/(4 - 5*x^2 + x^4), x, 3, (-(1/6))*ArcTanh[x/2] + ArcTanh[x]/3}
{1/(3 + 4*x^2 + x^4), x, 3, ArcTan[x]/2 - ArcTan[x/Sqrt[3]]/(2*Sqrt[3])}
{1/(9 + 5*x^2 + x^4), x, 3, ArcTan[(Sqrt[11]*x)/(3 - x^2)]/(6*Sqrt[11]) + (1/6)*ArcTanh[x/(3 + x^2)]}
{1/(1 - x^2 + x^4), x, 3, (1/2)*ArcTan[x/(1 - x^2)] + ArcTanh[(Sqrt[3]*x)/(1 + x^2)]/(2*Sqrt[3])}
{1/(2 + 2*x^2 + x^4), x, 3, (1/4)*Sqrt[-1 + Sqrt[2]]*ArcTan[(Sqrt[2 + 2*Sqrt[2]]*x)/(Sqrt[2] - x^2)] + (1/4)*Sqrt[1 + Sqrt[2]]*ArcTanh[(Sqrt[-2 + 2*Sqrt[2]]*x)/(Sqrt[2] + x^2)]}

{x/(1 + 2*x^2 + x^4), x, 3, -(1/(2*(1 + x^2)))}
{x/(1 + x^2 + x^4), x, 2, ArcTan[(1 + 2*x^2)/Sqrt[3]]/Sqrt[3]}
{x/(81 - 18*x^2 + x^4), x, 3, 1/(2*(9 - x^2))}
{x/(10 + 2*x^2 + x^4), x, 2, (1/6)*ArcTan[1/3 + x^2/3]}

{x^2/(1 + 2*x^2 + x^4), x, 3, -(x/(2*(1 + x^2))) + ArcTan[x]/2}
{x^2/(20 + 9*x^2 + x^4), x, 3, -2*ArcTan[x/2] + Sqrt[5]*ArcTan[x/Sqrt[5]]}
{x^2/(1 - x^2 + x^4), x, 3, (1/2)*ArcTan[x/(1 - x^2)] - ArcTanh[(Sqrt[3]*x)/(1 + x^2)]/(2*Sqrt[3])}
{x^2/(2 - 2*x^2 + x^4), x, 3, (1/4)*Sqrt[2 + 2*Sqrt[2]]*ArcTan[(Sqrt[-2 + 2*Sqrt[2]]*x)/(Sqrt[2] - x^2)] - (1/4)*Sqrt[-2 + 2*Sqrt[2]]*ArcTanh[(Sqrt[2 + 2*Sqrt[2]]*x)/(Sqrt[2] + x^2)]}
{x^2/(1 + (-1 + x^2)^2), x, 4, (1/4)*Sqrt[2 + 2*Sqrt[2]]*ArcTan[(Sqrt[-2 + 2*Sqrt[2]]*x)/(Sqrt[2] - x^2)] - (1/4)*Sqrt[-2 + 2*Sqrt[2]]*ArcTanh[(Sqrt[2 + 2*Sqrt[2]]*x)/(Sqrt[2] + x^2)]}

{x^3/(1 + 2*x^2 + x^4), x, 6, 1/(2*(1 + x^2)) + (1/2)*Log[1 + x^2]}
{x^3/(16 - 8*x^2 + x^4), x, 6, 2/(4 - x^2) + (1/2)*Log[4 - x^2]}

{(1 - 2*x^2 + x^4)/x^6, x, 2, -(1/(5*x^5)) + 2/(3*x^3) - 1/x}


(* ::Subsubsection::Closed:: *)
(*Integrands of the form (d+e x^2) (a+b x^2+c x^4)^n*)


(* Integrands of the form (d+e*x^2)/(a+b*x^2+c*x^4) *)
{(1 + x^2)/(1 + x^2)^2, x, 1, ArcTan[x]}
{(1 + x^2)/(1 + 2*x^2 + x^4), x, 2, ArcTan[x]}
{(3 + 2*x^2)/(1 - 2*x^2 + x^4), x, 4, (5*x)/(2*(1 - x^2)) + ArcTanh[x]/2}

{(1 + x^2)/(1 + b*x^2 + x^4), x, 1, ArcTan[(Sqrt[2 + b]*x)/(1 - x^2)]/Sqrt[2 + b]}
{(1 - x^2)/(1 + b*x^2 + x^4), x, 1, ArcTanh[(Sqrt[2 - b]*x)/(1 + x^2)]/Sqrt[2 - b]}

{(a + b*x^2)/(1 + x^2 + x^4), x, 3, ((a + b)*ArcTan[(Sqrt[3]*x)/(1 - x^2)])/(2*Sqrt[3]) + (1/2)*(a - b)*ArcTanh[x/(1 + x^2)]}
{(a + b*x^2)/(2 + x^2 + x^4), x, 3, ((Sqrt[2]*a + 2*b)*ArcTan[(Sqrt[1 + 2*Sqrt[2]]*x)/(Sqrt[2] - x^2)])/(4*Sqrt[1 + 2*Sqrt[2]]) + ((Sqrt[2]*a - 2*b)*ArcTanh[(Sqrt[-1 + 2*Sqrt[2]]*x)/(Sqrt[2] + x^2)])/(4*Sqrt[-1 + 2*Sqrt[2]])}

{(Sqrt[2] - x^2)/(1 - Sqrt[2]*x^2 + x^4), x, 3, ArcTan[(Sqrt[2 - Sqrt[2]]*x)/(1 - x^2)]/(2*Sqrt[2 + Sqrt[2]]) + ArcTanh[(Sqrt[2 + Sqrt[2]]*x)/(1 + x^2)]/(2*Sqrt[2 - Sqrt[2]])}
{(Sqrt[2] + x^2)/(1 + Sqrt[2]*x^2 + x^4), x, 3, ArcTan[(Sqrt[2 + Sqrt[2]]*x)/(1 - x^2)]/(2*Sqrt[2 - Sqrt[2]]) + ArcTanh[(Sqrt[2 - Sqrt[2]]*x)/(1 + x^2)]/(2*Sqrt[2 + Sqrt[2]])}
{(Sqrt[2] + x^2)/(1 + b*x^2 + x^4), x, 3, ((1 + Sqrt[2])*ArcTan[(Sqrt[2 + b]*x)/(1 - x^2)])/(2*Sqrt[2 + b]) - ((1 - Sqrt[2])*ArcTanh[(Sqrt[2 - b]*x)/(1 + x^2)])/(2*Sqrt[2 - b])}
{(Sqrt[2] - x^2)/(1 + b*x^2 + x^4), x, 3, -(((1 - Sqrt[2])*ArcTan[(Sqrt[2 + b]*x)/(1 - x^2)])/(2*Sqrt[2 + b])) + ((1 + Sqrt[2])*ArcTanh[(Sqrt[2 - b]*x)/(1 + x^2)])/(2*Sqrt[2 - b])}

{(d + e*x^2)/(a + b*x^2 + c*x^4), x, 3, ((e + (2*c*d - b*e)/Sqrt[b^2 - 4*a*c])*ArcTan[(Sqrt[2]*Sqrt[c]*x)/Sqrt[b - Sqrt[b^2 - 4*a*c]]])/(Sqrt[2]*Sqrt[c]*Sqrt[b - Sqrt[b^2 - 4*a*c]]) + ((e - (2*c*d - b*e)/Sqrt[b^2 - 4*a*c])*ArcTan[(Sqrt[2]*Sqrt[c]*x)/Sqrt[b + Sqrt[b^2 - 4*a*c]]])/(Sqrt[2]*Sqrt[c]*Sqrt[b + Sqrt[b^2 - 4*a*c]])}
{(d + e*x^2)/((c*d^2)/e^2 + b*x^2 + c*x^4), x, 1, (e*ArcTan[(Sqrt[b + (2*c*d)/e]*e*x)/(Sqrt[c]*(d - e*x^2))])/(Sqrt[c]*Sqrt[b + (2*c*d)/e])}
{(d + e*x^2)/(b*x^2 + c*(d^2/e^2 + x^4)), x, 8, (Sqrt[2]*Sqrt[c]*d*ArcTan[(Sqrt[2]*Sqrt[c]*x)/Sqrt[b - Sqrt[b^2 - (4*c^2*d^2)/e^2]]])/(Sqrt[b - Sqrt[b^2 - (4*c^2*d^2)/e^2]]*Sqrt[b^2 - (4*c^2*d^2)/e^2]) - (Sqrt[b - Sqrt[b^2 - (4*c^2*d^2)/e^2]]*e*ArcTan[(Sqrt[2]*Sqrt[c]*x)/Sqrt[b - Sqrt[b^2 - (4*c^2*d^2)/e^2]]])/(Sqrt[2]*Sqrt[c]*Sqrt[b^2 - (4*c^2*d^2)/e^2]) - (Sqrt[2]*Sqrt[c]*d*ArcTan[(Sqrt[2]*Sqrt[c]*x)/Sqrt[b + Sqrt[b^2 - (4*c^2*d^2)/e^2]]])/(Sqrt[b + Sqrt[b^2 - (4*c^2*d^2)/e^2]]*Sqrt[b^2 - (4*c^2*d^2)/e^2]) + (Sqrt[b + Sqrt[b^2 - (4*c^2*d^2)/e^2]]*e*ArcTan[(Sqrt[2]*Sqrt[c]*x)/Sqrt[b + Sqrt[b^2 - (4*c^2*d^2)/e^2]]])/(Sqrt[2]*Sqrt[c]*Sqrt[b^2 - (4*c^2*d^2)/e^2])}


(* Integrands of the form (d+e*x^2)/(a+b*x^2+c*x^4)^2 *)
{(a + b*x^2)/(1 + x^2 + x^4)^2, x, 4, (x*(a + b - (a - 2*b)*x^2))/(6*(1 + x^2 + x^4)) + ((4*a + b)*ArcTan[(Sqrt[3]*x)/(1 - x^2)])/(12*Sqrt[3]) + (1/4)*(2*a - b)*ArcTanh[x/(1 + x^2)]}
{(a + b*x^2)/(2 + x^2 + x^4)^2, x, 4, (x*(3*a + 2*b - (a - 4*b)*x^2))/(28*(2 + x^2 + x^4)) - ((2*(a - 4*b) - Sqrt[2]*(11*a - 2*b))*ArcTan[(Sqrt[1 + 2*Sqrt[2]]*x)/(Sqrt[2] - x^2)])/(112*Sqrt[1 + 2*Sqrt[2]]) + ((2*(a - 4*b) + Sqrt[2]*(11*a - 2*b))*ArcTanh[(Sqrt[-1 + 2*Sqrt[2]]*x)/(Sqrt[2] + x^2)])/(112*Sqrt[-1 + 2*Sqrt[2]])}
{(a + b*x^2)/(c + d*x^2 + e*x^4)^2, x, 4, -((x*(b*c*d - a*d^2 + 2*a*c*e + (2*b*c - a*d)*e*x^2))/(2*c*(d^2 - 4*c*e)*(c + d*x^2 + e*x^4))) + (Sqrt[e]*(d*(4*b*c + a*d) - 12*a*c*e - (2*b*c - a*d)*Sqrt[d^2 - 4*c*e])*ArcTan[(Sqrt[2]*Sqrt[e]*x)/Sqrt[d - Sqrt[d^2 - 4*c*e]]])/(2*Sqrt[2]*c*(d^2 - 4*c*e)^(3/2)*Sqrt[d - Sqrt[d^2 - 4*c*e]]) - (Sqrt[e]*(d*(4*b*c + a*d) - 12*a*c*e + (2*b*c - a*d)*Sqrt[d^2 - 4*c*e])*ArcTan[(Sqrt[2]*Sqrt[e]*x)/Sqrt[d + Sqrt[d^2 - 4*c*e]]])/(2*Sqrt[2]*c*(d^2 - 4*c*e)^(3/2)*Sqrt[d + Sqrt[d^2 - 4*c*e]])}


(* ::Subsubsection::Closed:: *)
(*Integrands involving powers of symmetric higher trinomials*)


{1/(2 + x^3 + x^6), x, 11, (I*ArcTan[(2^(2/3)*(1 - I*Sqrt[7])^(1/3) - 4*x)/(2^(2/3)*Sqrt[3]*(1 - I*Sqrt[7])^(1/3))])/(Sqrt[21]*((1/2)*(1 - I*Sqrt[7]))^(2/3)) - (I*ArcTan[((1 - I*Sqrt[7])^(1/3)*(2^(2/3)*(1 + I*Sqrt[7])^(1/3) - 4*x))/(2*2^(2/3)*Sqrt[3])])/(Sqrt[21]*((1/2)*(1 + I*Sqrt[7]))^(2/3)) - (I*Log[2^(2/3)*(1 - I*Sqrt[7])^(1/3) + 2*x])/(3*Sqrt[7]*((1/2)*(1 - I*Sqrt[7]))^(2/3)) + (I*Log[2^(2/3)*(1 + I*Sqrt[7])^(1/3) + 2*x])/(3*Sqrt[7]*((1/2)*(1 + I*Sqrt[7]))^(2/3)) + (I*Log[2^(1/3)*(1 - I*Sqrt[7])^(2/3) - 2^(2/3)*(1 - I*Sqrt[7])^(1/3)*x + 2*x^2])/(3*2^(1/3)*Sqrt[7]*(1 - I*Sqrt[7])^(2/3)) - (I*Log[(Sqrt[2] + I*Sqrt[14])^(2/3) - 2^(2/3)*(1 + I*Sqrt[7])^(1/3)*x + 2*x^2])/(3*Sqrt[7]*(Sqrt[2] + I*Sqrt[14])^(2/3))}
{x^2/(2 + x^3 + x^6), x, 2, (2*ArcTan[(1 + 2*x^3)/Sqrt[7]])/(3*Sqrt[7])}
{x^3/(2 + x^3 + x^6), x, 11, -(((7 + I*Sqrt[7])*ArcTan[(2^(2/3)*(1 - I*Sqrt[7])^(1/3) - 4*x)/(2^(2/3)*Sqrt[3]*(1 - I*Sqrt[7])^(1/3))])/(7*2^(1/3)*Sqrt[3]*(1 - I*Sqrt[7])^(2/3))) - ((7 - I*Sqrt[7])*ArcTan[((1 - I*Sqrt[7])^(1/3)*(2^(2/3)*(1 + I*Sqrt[7])^(1/3) - 4*x))/(2*2^(2/3)*Sqrt[3])])/(7*Sqrt[3]*(Sqrt[2] + I*Sqrt[14])^(2/3)) + (I*((1/2)*(1 - I*Sqrt[7]))^(1/3)*Log[2^(2/3)*(1 - I*Sqrt[7])^(1/3) + 2*x])/(3*Sqrt[7]) + ((7 - I*Sqrt[7])*Log[2^(2/3)*(1 + I*Sqrt[7])^(1/3) + 2*x])/(21*(Sqrt[2] + I*Sqrt[14])^(2/3)) - ((7 + I*Sqrt[7])*Log[2^(1/3)*(1 - I*Sqrt[7])^(2/3) - 2^(2/3)*(1 - I*Sqrt[7])^(1/3)*x + 2*x^2])/(42*2^(1/3)*(1 - I*Sqrt[7])^(2/3)) - ((7 - I*Sqrt[7])*Log[(Sqrt[2] + I*Sqrt[14])^(2/3) - 2^(2/3)*(1 + I*Sqrt[7])^(1/3)*x + 2*x^2])/(42*(Sqrt[2] + I*Sqrt[14])^(2/3))}

{x^2/(1 + x^3 + x^6), x, 2, (2*ArcTan[(1 + 2*x^3)/Sqrt[3]])/(3*Sqrt[3])}
{1/(x*(1 + x^3 + x^6)), x, 3, -ArcTan[(1 + 2*x^3)/Sqrt[3]]/(3*Sqrt[3]) + Log[x] - Log[1 + x^3 + x^6]/6}


{1/(2 + x^4 + x^8), x, 7, -(((Sqrt[2] - Sqrt[4 - Sqrt[2]])*ArcTan[(Sqrt[2*Sqrt[2] - Sqrt[4 - Sqrt[2]]]*x)/(2^(1/8)*(2^(1/4) - x^2))])/(4*2^(7/8)*Sqrt[(-1 + 2*Sqrt[2])*(2*Sqrt[2] - Sqrt[4 - Sqrt[2]])])) + ((Sqrt[2] + Sqrt[4 - Sqrt[2]])*ArcTan[(Sqrt[2*2^(1/4) + Sqrt[-1 + 2*Sqrt[2]]]*x)/(2^(1/4) - x^2)])/(8*Sqrt[(-1 + 2*Sqrt[2])*(2*2^(1/4) + Sqrt[-1 + 2*Sqrt[2]])]) - ((Sqrt[2] - Sqrt[4 - Sqrt[2]])*ArcTanh[(Sqrt[2*Sqrt[2] - Sqrt[4 - Sqrt[2]]]*x)/(2^(1/8)*(2^(1/4) + x^2))])/(4*2^(7/8)*Sqrt[(-1 + 2*Sqrt[2])*(2*Sqrt[2] - Sqrt[4 - Sqrt[2]])]) + ((Sqrt[2] + Sqrt[4 - Sqrt[2]])*ArcTanh[(Sqrt[2*2^(1/4) + Sqrt[-1 + 2*Sqrt[2]]]*x)/(2^(1/4) + x^2)])/(8*Sqrt[(-1 + 2*Sqrt[2])*(2*2^(1/4) + Sqrt[-1 + 2*Sqrt[2]])])}
{x/(2 + x^4 + x^8), x, 4, ArcTan[(Sqrt[1 + 2*Sqrt[2]]*x^2)/(Sqrt[2] - x^4)]/(4*Sqrt[2 + 4*Sqrt[2]]) + ArcTanh[(Sqrt[-1 + 2*Sqrt[2]]*x^2)/(Sqrt[2] + x^4)]/(4*Sqrt[-2 + 4*Sqrt[2]])}
{x^2/(2 + x^4 + x^8), x, 7, ArcTan[(Sqrt[2*Sqrt[2] - Sqrt[4 - Sqrt[2]]]*x)/(2^(1/8)*(2^(1/4) - x^2))]/(4*2^(1/8)*Sqrt[(-1 + 2*Sqrt[2])*(2*Sqrt[2] - Sqrt[4 - Sqrt[2]])]) - ArcTan[(Sqrt[2*2^(1/4) + Sqrt[-1 + 2*Sqrt[2]]]*x)/(2^(1/4) - x^2)]/(4*2^(1/4)*Sqrt[(-1 + 2*Sqrt[2])*(2*2^(1/4) + Sqrt[-1 + 2*Sqrt[2]])]) - ArcTanh[(Sqrt[2*Sqrt[2] - Sqrt[4 - Sqrt[2]]]*x)/(2^(1/8)*(2^(1/4) + x^2))]/(4*2^(1/8)*Sqrt[(-1 + 2*Sqrt[2])*(2*Sqrt[2] - Sqrt[4 - Sqrt[2]])]) + ArcTanh[(Sqrt[2*2^(1/4) + Sqrt[-1 + 2*Sqrt[2]]]*x)/(2^(1/4) + x^2)]/(4*2^(1/4)*Sqrt[(-1 + 2*Sqrt[2])*(2*2^(1/4) + Sqrt[-1 + 2*Sqrt[2]])])}
{x^3/(2 + x^4 + x^8), x, 2, ArcTan[(1 + 2*x^4)/Sqrt[7]]/(2*Sqrt[7])}
{x^4/(2 + x^4 + x^8), x, 7, ArcTan[(Sqrt[2*Sqrt[2] - Sqrt[4 - Sqrt[2]]]*x)/(2^(1/8)*(2^(1/4) - x^2))]/(2*2^(7/8)*Sqrt[(-1 + 2*Sqrt[2])*(2*Sqrt[2] - Sqrt[4 - Sqrt[2]])]) - ArcTan[(Sqrt[2*2^(1/4) + Sqrt[-1 + 2*Sqrt[2]]]*x)/(2^(1/4) - x^2)]/(4*Sqrt[(-1 + 2*Sqrt[2])*(2*2^(1/4) + Sqrt[-1 + 2*Sqrt[2]])]) + ArcTanh[(Sqrt[2*Sqrt[2] - Sqrt[4 - Sqrt[2]]]*x)/(2^(1/8)*(2^(1/4) + x^2))]/(2*2^(7/8)*Sqrt[(-1 + 2*Sqrt[2])*(2*Sqrt[2] - Sqrt[4 - Sqrt[2]])]) - ArcTanh[(Sqrt[2*2^(1/4) + Sqrt[-1 + 2*Sqrt[2]]]*x)/(2^(1/4) + x^2)]/(4*Sqrt[(-1 + 2*Sqrt[2])*(2*2^(1/4) + Sqrt[-1 + 2*Sqrt[2]])])}

{x^3/(2 + 3*x^4 + x^8), x, 2, -ArcTanh[3 + 2*x^4]/2}


(* {1/(2 + x^5 + x^10), x, 19, (I*2^(3/10)*Sqrt[(1/7)*(5 + Sqrt[5])]*ArcTan[((1 - Sqrt[5])*((1/2)*(1 - I*Sqrt[7]))^(1/5) - 4*x)/(2^(3/10)*Sqrt[5 + Sqrt[5]]*(1 - I*Sqrt[7])^(1/5))])/(5*(1 - I*Sqrt[7])^(4/5)) + (I*2^(3/10)*Sqrt[(1/7)*(5 - Sqrt[5])]*ArcTan[((1 + Sqrt[5])*((1/2)*(1 - I*Sqrt[7]))^(1/5) - 4*x)/(2^(3/10)*Sqrt[5 - Sqrt[5]]*(1 - I*Sqrt[7])^(1/5))])/(5*(1 - I*Sqrt[7])^(4/5)) - (I*2^(3/10)*Sqrt[(1/7)*(5 + Sqrt[5])]*ArcTan[((1 - Sqrt[5])*((1/2)*(1 + I*Sqrt[7]))^(1/5) - 4*x)/(2^(3/10)*Sqrt[5 + Sqrt[5]]*(1 + I*Sqrt[7])^(1/5))])/(5*(1 + I*Sqrt[7])^(4/5)) - (I*2^(3/10)*Sqrt[(1/7)*(5 - Sqrt[5])]*ArcTan[((1 + Sqrt[5])*((1/2)*(1 + I*Sqrt[7]))^(1/5) - 4*x)/(2^(3/10)*Sqrt[5 - Sqrt[5]]*(1 + I*Sqrt[7])^(1/5))])/(5*(1 + I*Sqrt[7])^(4/5)) - (I*Log[((1/2)*(1 - I*Sqrt[7]))^(1/5) + x])/(5*Sqrt[7]*((1/2)*(1 - I*Sqrt[7]))^(4/5)) + (I*Log[((1/2)*(1 + I*Sqrt[7]))^(1/5) + x])/(5*Sqrt[7]*((1/2)*(1 + I*Sqrt[7]))^(4/5)) + (I*(1 - Sqrt[5])*Log[2^(3/5)*(1 - I*Sqrt[7])^(2/5) - (1 - Sqrt[5])*((1/2)*(1 - I*Sqrt[7]))^(1/5)*x + 2*x^2])/(10*2^(1/5)*Sqrt[7]*(1 - I*Sqrt[7])^(4/5)) + (I*(1 + Sqrt[5])*Log[2^(3/5)*(1 - I*Sqrt[7])^(2/5) - (1 + Sqrt[5])*((1/2)*(1 - I*Sqrt[7]))^(1/5)*x + 2*x^2])/(10*2^(1/5)*Sqrt[7]*(1 - I*Sqrt[7])^(4/5)) - (I*(1 - Sqrt[5])*Log[2^(3/5)*(1 + I*Sqrt[7])^(2/5) - (1 - Sqrt[5])*((1/2)*(1 + I*Sqrt[7]))^(1/5)*x + 2*x^2])/(10*2^(1/5)*Sqrt[7]*(1 + I*Sqrt[7])^(4/5)) - (I*(1 + Sqrt[5])*Log[2^(3/5)*(1 + I*Sqrt[7])^(2/5) - (1 + Sqrt[5])*((1/2)*(1 + I*Sqrt[7]))^(1/5)*x + 2*x^2])/(10*2^(1/5)*Sqrt[7]*(1 + I*Sqrt[7])^(4/5))} *)
{x^4/(2 + x^5 + x^10), x, 2, (2*ArcTan[(1 + 2*x^5)/Sqrt[7]])/(5*Sqrt[7])}
(* {x^5/(2 + x^5 + x^10), x, 19, -((I*Sqrt[(1/7)*(5 + Sqrt[5])]*(1 - I*Sqrt[7])^(1/5)*ArcTan[((1 - Sqrt[5])*((1/2)*(1 - I*Sqrt[7]))^(1/5) - 4*x)/(2^(3/10)*Sqrt[5 + Sqrt[5]]*(1 - I*Sqrt[7])^(1/5))])/(5*2^(7/10))) - (I*Sqrt[(1/7)*(5 - Sqrt[5])]*(1 - I*Sqrt[7])^(1/5)*ArcTan[((1 + Sqrt[5])*((1/2)*(1 - I*Sqrt[7]))^(1/5) - 4*x)/(2^(3/10)*Sqrt[5 - Sqrt[5]]*(1 - I*Sqrt[7])^(1/5))])/(5*2^(7/10)) + (I*Sqrt[(1/7)*(5 + Sqrt[5])]*(1 + I*Sqrt[7])^(1/5)*ArcTan[((1 - Sqrt[5])*((1/2)*(1 + I*Sqrt[7]))^(1/5) - 4*x)/(2^(3/10)*Sqrt[5 + Sqrt[5]]*(1 + I*Sqrt[7])^(1/5))])/(5*2^(7/10)) + (I*Sqrt[(1/7)*(5 - Sqrt[5])]*(1 + I*Sqrt[7])^(1/5)*ArcTan[((1 + Sqrt[5])*((1/2)*(1 + I*Sqrt[7]))^(1/5) - 4*x)/(2^(3/10)*Sqrt[5 - Sqrt[5]]*(1 + I*Sqrt[7])^(1/5))])/(5*2^(7/10)) + (I*((1/2)*(1 - I*Sqrt[7]))^(1/5)*Log[((1/2)*(1 - I*Sqrt[7]))^(1/5) + x])/(5*Sqrt[7]) - (I*((1/2)*(1 + I*Sqrt[7]))^(1/5)*Log[((1/2)*(1 + I*Sqrt[7]))^(1/5) + x])/(5*Sqrt[7]) - (I*(1 - Sqrt[5])*((1/2)*(1 - I*Sqrt[7]))^(1/5)*Log[2^(3/5)*(1 - I*Sqrt[7])^(2/5) - (1 - Sqrt[5])*((1/2)*(1 - I*Sqrt[7]))^(1/5)*x + 2*x^2])/(20*Sqrt[7]) - (I*(1 + Sqrt[5])*((1/2)*(1 - I*Sqrt[7]))^(1/5)*Log[2^(3/5)*(1 - I*Sqrt[7])^(2/5) - (1 + Sqrt[5])*((1/2)*(1 - I*Sqrt[7]))^(1/5)*x + 2*x^2])/(20*Sqrt[7]) + (I*(1 - Sqrt[5])*((1/2)*(1 + I*Sqrt[7]))^(1/5)*Log[2^(3/5)*(1 + I*Sqrt[7])^(2/5) - (1 - Sqrt[5])*((1/2)*(1 + I*Sqrt[7]))^(1/5)*x + 2*x^2])/(20*Sqrt[7]) + (I*(1 + Sqrt[5])*((1/2)*(1 + I*Sqrt[7]))^(1/5)*Log[2^(3/5)*(1 + I*Sqrt[7])^(2/5) - (1 + Sqrt[5])*((1/2)*(1 + I*Sqrt[7]))^(1/5)*x + 2*x^2])/(20*Sqrt[7])} *)

{1/(x*(1 + x^5 + x^10)), x, 3, -ArcTan[(1 + 2*x^5)/Sqrt[3]]/(5*Sqrt[3]) + Log[x] - Log[1 + x^5 + x^10]/10}
{1/(x + x^6 + x^11), x, 4, -ArcTan[(1 + 2*x^5)/Sqrt[3]]/(5*Sqrt[3]) + Log[x] - Log[1 + x^5 + x^10]/10}


(* ::Subsection::Closed:: *)
(*Integrands involving quotients of polynomials*)


{(e - 2*f*x^2)/(e^2 + 4*d*f*x^2 + 4*e*f*x^2 + 4*f^2*x^4), x, 1, ArcTan[(2*Sqrt[d]*Sqrt[f]*x)/(e + 2*f*x^2)]/(2*Sqrt[d]*Sqrt[f])}
{(e - 2*f*x^2)/(e^2 - 4*d*f*x^2 + 4*e*f*x^2 + 4*f^2*x^4), x, 1, ArcTanh[(2*Sqrt[d]*Sqrt[f]*x)/(e + 2*f*x^2)]/(2*Sqrt[d]*Sqrt[f])}

{(e - 4*f*x^3)/(e^2 + 4*d*f*x^2 + 4*e*f*x^3 + 4*f^2*x^6), x, 1, ArcTan[(2*Sqrt[d]*Sqrt[f]*x)/(e + 2*f*x^3)]/(2*Sqrt[d]*Sqrt[f])}
{(e - 4*f*x^3)/(e^2 - 4*d*f*x^2 + 4*e*f*x^3 + 4*f^2*x^6), x, 1, ArcTanh[(2*Sqrt[d]*Sqrt[f]*x)/(e + 2*f*x^3)]/(2*Sqrt[d]*Sqrt[f])}

{(e - 2*f*(-1 + n)*x^n)/(e^2 + 4*d*f*x^2 + 4*e*f*x^n + 4*f^2*x^(2*n)), x, 1, ArcTan[(2*Sqrt[d]*Sqrt[f]*(-1 + n)*x)/(e*(-1 + n) + 2*f*(-1 + n)*x^n)]/(2*Sqrt[d]*Sqrt[f])}
{(e - 2*f*(-1 + n)*x^n)/(e^2 - 4*d*f*x^2 + 4*e*f*x^n + 4*f^2*x^(2*n)), x, 1, ArcTanh[(2*Sqrt[d]*Sqrt[f]*(-1 + n)*x)/(e*(-1 + n) + 2*f*(-1 + n)*x^n)]/(2*Sqrt[d]*Sqrt[f])}


{x/(e^2 + 4*e*f*x^2 + 4*d*f*x^4 + 4*f^2*x^4), x, 2, ArcTan[(Sqrt[f]*(e + 2*(d + f)*x^2))/(Sqrt[d]*e)]/(4*Sqrt[d]*e*Sqrt[f])}
{x/(e^2 + 4*e*f*x^2 - 4*d*f*x^4 + 4*f^2*x^4), x, 2, -(ArcTanh[(Sqrt[f]*(e - 2*(d - f)*x^2))/(Sqrt[d]*e)]/(4*Sqrt[d]*e*Sqrt[f]))}

{(x^2*(3*e + 2*f*x^2))/(e^2 + 4*e*f*x^2 + 4*f^2*x^4 + 4*d*f*x^6), x, 1, ArcTan[(2*Sqrt[d]*Sqrt[f]*x^3)/(e + 2*f*x^2)]/(2*Sqrt[d]*Sqrt[f])}
{(x^2*(3*e + 2*f*x^2))/(e^2 + 4*e*f*x^2 + 4*f^2*x^4 - 4*d*f*x^6), x, 1, ArcTanh[(2*Sqrt[d]*Sqrt[f]*x^3)/(e + 2*f*x^2)]/(2*Sqrt[d]*Sqrt[f])}

{(x^m*(e*(1 + m) + 2*f*(-1 + m)*x^2))/(e^2 + 4*e*f*x^2 + 4*f^2*x^4 + 4*d*f*x^(2 + 2*m)), x, 1, ArcTan[(2*Sqrt[d]*Sqrt[f]*(1 - m^2)*x^(1 + m))/(e*(1 - m)*(1 + m) + 2*f*(1 - m^2)*x^2)]/(2*Sqrt[d]*Sqrt[f])}
{(x^m*(e*(1 + m) + 2*f*(-1 + m)*x^2))/(e^2 + 4*e*f*x^2 + 4*f^2*x^4 - 4*d*f*x^(2 + 2*m)), x, 1, ArcTanh[(2*Sqrt[d]*Sqrt[f]*(1 - m^2)*x^(1 + m))/(e*(1 - m)*(1 + m) + 2*f*(1 - m^2)*x^2)]/(2*Sqrt[d]*Sqrt[f])}


{(x*(2*e - 2*f*x^3))/(e^2 + 4*e*f*x^3 + 4*d*f*x^4 + 4*f^2*x^6), x, 1, ArcTan[(2*Sqrt[d]*Sqrt[f]*x^2)/(e + 2*f*x^3)]/(2*Sqrt[d]*Sqrt[f])}
{(x*(2*e - 2*f*x^3))/(e^2 + 4*e*f*x^3 - 4*d*f*x^4 + 4*f^2*x^6), x, 1, ArcTanh[(2*Sqrt[d]*Sqrt[f]*x^2)/(e + 2*f*x^3)]/(2*Sqrt[d]*Sqrt[f])}

{x^2/(e^2 + 4*e*f*x^3 + 4*d*f*x^6 + 4*f^2*x^6), x, 2, ArcTan[(Sqrt[f]*(e + 2*(d + f)*x^3))/(Sqrt[d]*e)]/(6*Sqrt[d]*e*Sqrt[f])}
{x^2/(e^2 + 4*e*f*x^3 - 4*d*f*x^6 + 4*f^2*x^6), x, 2, -(ArcTanh[(Sqrt[f]*(e - 2*(d - f)*x^3))/(Sqrt[d]*e)]/(6*Sqrt[d]*e*Sqrt[f]))}

{(x^m*(e*(1 + m) + 2*f*(-2 + m)*x^3))/(e^2 + 4*e*f*x^3 + 4*f^2*x^6 + 4*d*f*x^(2 + 2*m)), x, 1, ArcTan[(2*Sqrt[d]*Sqrt[f]*x^(1 + m))/(e + 2*f*x^3)]/(2*Sqrt[d]*Sqrt[f])}
{(x^m*(e*(1 + m) + 2*f*(-2 + m)*x^3))/(e^2 + 4*e*f*x^3 + 4*f^2*x^6 - 4*d*f*x^(2 + 2*m)), x, 1, ArcTanh[(2*Sqrt[d]*Sqrt[f]*x^(1 + m))/(e + 2*f*x^3)]/(2*Sqrt[d]*Sqrt[f])}


{(x^m*(e*(1 + m) + 2*f*(1 + m - n)*x^n))/(e^2 + 4*d*f*x^(2 + 2*m) + 4*e*f*x^n + 4*f^2*x^(2*n)), x, 1, ArcTan[(2*Sqrt[d]*Sqrt[f]*(1 + m)*(1 + m - n)*x^(1 + m))/(e*(1 + m)*(1 + m - n) + 2*f*(1 + m)*(1 + m - n)*x^n)]/(2*Sqrt[d]*Sqrt[f])}
{(x^m*(e*(1 + m) + 2*f*(1 + m - n)*x^n))/(e^2 - 4*d*f*x^(2 + 2*m) + 4*e*f*x^n + 4*f^2*x^(2*n)), x, 1, ArcTanh[(2*Sqrt[d]*Sqrt[f]*(1 + m)*(1 + m - n)*x^(1 + m))/(e*(1 + m)*(1 + m - n) + 2*f*(1 + m)*(1 + m - n)*x^n)]/(2*Sqrt[d]*Sqrt[f])}


(* ::Subsection::Closed:: *)
(*Problems from Calculus textbooks*)


(* ::Subsubsection::Closed:: *)
(*Anton Calculus, 4th Edition*)


{(1 - 5*x^2)/(x^3*(1 + x^2)), x, 5, -(1/(2*x^2)) - 6*Log[x] + 3*Log[1 + x^2]}
{(2*x)/((-1 + x)*(5 + x^2)), x, 7, (1/3)*Sqrt[5]*ArcTan[x/Sqrt[5]] + (1/3)*Log[1 - x] - (1/6)*Log[5 + x^2]}
{(-x + 4*x^3)/(5 + x^2)^2, x, 6, 21/(2*(5 + x^2)) + 2*Log[5 + x^2]}
{(1 - 3*x^4)/((-2 + x)*(1 + x^2)^2), x, 9, -(1/(5*(1 + x^2))) + (2*x)/(5*(1 + x^2)) - (46*ArcTan[x])/25 - (47/25)*Log[2 - x] - (14/25)*Log[1 + x^2]}
{(-9 - 9*x + 2*x^2)/(-9*x + x^3), x, 5, -2*ArcTanh[1 - (2*x)/3] + 2*Log[3 + x]}
{(2 + x^2)/(2 + x), x, 4, -2*x + x^2/2 + 6*Log[2 + x]}
{(1 + 2*x^2 + x^5)/(-x + x^3), x, 5, x + x^3/3 + 2*ArcTanh[1 + 2*x] + 2*Log[1 - x]}
{(3 + 2*x^2)/((-1 + x)^2*x), x, 5, 5/(1 - x) - Log[1 - x] + 3*Log[x]}
{(-1 + 2*x^2)/((-1 + 4*x)*(1 + x^2)), x, 6, (3*ArcTan[x])/17 - (7/34)*Log[1 - 4*x] + (6/17)*Log[1 + x^2]}
{(9 + x + 3*x^2 + x^3)/((1 + x^2)*(3 + x^2)), x, 5, 3*ArcTan[x] + (1/2)*Log[3 + x^2]}
{(2 + x + x^2 + x^3)/((1 + x^2)*(2 + x^2)), x, 5, ArcTan[x] + Log[2 + x^2]/2}
{(-3 + 2*x - 3*x^2 + x^3)/(1 + x^2), x, 5, -3*x + x^2/2 + (1/2)*Log[1 + x^2]}
{(x + 10*x^2 + 6*x^3 + x^4)/(10 + 6*x + x^2), x, 5, x^3/3 - 3*ArcTan[3 + x] + Log[10 + 6*x + x^2]/2}
{(4 + 4*x + 4*x^2 + 4*x^3 + x^4 + x^5)/(2 + x^2)^3, x, 6, ArcTan[x/Sqrt[2]]/Sqrt[2] + (1/2)*Log[2 + x^2]}
{1/(-18 + 27*x - 7*x^2 - 3*x^3 + x^4), x, 6, (1/8)*Log[1 - x] - (1/5)*Log[2 - x] + (1/12)*Log[3 - x] - (1/120)*Log[3 + x]}
{1/(-1 + 4*x - 4*x^2 + 16*x^3), x, 6, (-(1/10))*ArcTan[2*x] + (1/5)*Log[1 - 4*x] - (1/10)*Log[1 + 4*x^2]}
{(1 + x^3)/(-2 + x), x, 4, 4*x + x^2 + x^3/3 + 9*Log[2 - x]}
{(-3 + x)/(-1 + x^3), x, 5, (4*ArcTan[(1 + 2*x)/Sqrt[3]])/Sqrt[3] - (2/3)*Log[1 - x] + (1/3)*Log[1 + x + x^2]}
{1/((-3 + x)*(4 + x^2)), x, 6, (-(3/26))*ArcTan[x/2] + (1/13)*Log[3 - x] - (1/26)*Log[4 + x^2]}
{(-2 + 3*x^6)/(x*(5 + 2*x^6)), x, 5, (-2*Log[x])/5 + (19*Log[5 + 2*x^6])/60}


(* ::Subsubsection::Closed:: *)
(*Apostol Calculus, Volume 1, 2nd Edition, Section 6.25*)


{(3 + 2*x)/((-2 + x)*(5 + x)), x, 4, Log[2 - x] + Log[5 + x]}
{x/((1 + x)*(2 + x)*(3 + x)), x, 5, (-(1/2))*Log[1 + x] + 2*Log[2 + x] - (3/2)*Log[3 + x]}
{x/(2 - 3*x + x^3), x, 5, 1/(3*(1 - x)) + (2/9)*Log[1 - x] - (2/9)*Log[2 + x]}
{(-6 + 2*x + x^4)/(-2*x + x^2 + x^3), x, 5, -x + x^2/2 - Log[1 - x] + 3*Log[x] + Log[2 + x]}
{(7 + 8*x^3)/((1 + x)*(1 + 2*x)^3), x, 5, -(3/(1 + 2*x)^2) + 3/(1 + 2*x) + Log[1 + x]}
{(1 + x + 4*x^2)/(-1 + x^3), x, 4, 2*Log[1 - x] + Log[1 + x + x^2]}
{x^4/(4 + 5*x^2 + x^4), x, 4, x - (8/3)*ArcTan[x/2] + ArcTan[x]/3}
{1/((1 + x)*(2 + x)^2*(3 + x)^3), x, 8, 1/(2 + x) + 1/(4*(3 + x)^2) + 5/(4*(3 + x)) + (1/8)*Log[1 + x] + 2*Log[2 + x] - (17/8)*Log[3 + x]}
{x/(-1 + x^2), x, 2, (1/2)*Log[1 - x^2]}
{(-3 + x)/(2*x + 3*x^2 + x^3), x, 5, -((3*Log[x])/2) + 4*Log[1 + x] - (5/2)*Log[2 + x]}
{(-1 + x^2)^(-2), x, 2, x/(2*(1 - x^2)) + ArcTanh[x]/2}
{(1 + x)/(-1 + x^3), x, 4, (2/3)*Log[1 - x] - (1/3)*Log[1 + x + x^2]}
{(1 + x^4)/(x*(1 + x^2)^2), x, 5, (1 + x^2)^(-1) + Log[x]}
{(1 - x^3)/(x*(1 + x^2)), x, 6, -x + ArcTan[x] + Log[x] - Log[1 + x^2]/2}
{(-1 + 4*x^5)/(1 + x + x^5)^2, x, 1, -(x/(1 + x + x^5))}

{x^2/(1 + x^2)^2, x, 2, -(x/(2*(1 + x^2))) + ArcTan[x]/2}
{1/(2 + 3*x), x, 1, Log[2 + 3*x]/3}
{1/(a^2 + x^2), x, 1, ArcTan[x/a]/a}
{1/(a + b*x^2), x, 1, ArcTan[(Sqrt[b]*x)/Sqrt[a]]/(Sqrt[a]*Sqrt[b])}
{1/(2 - x + x^2), x, 1, -((2*ArcTan[(1 - 2*x)/Sqrt[7]])/Sqrt[7])}


(* ::Subsubsection::Closed:: *)
(*Ayres Calculus, 1964 edition*)


{x^2*(4 - x^2)^2, x, 2, (16*x^3)/3 - (8*x^5)/5 + x^7/7}
{x*(1 - x^3)^2, x, 2, x^2/2 - (2*x^5)/5 + x^8/8}


{(-4 + 5*x^2 + x^3)/x^2, x, 2, 4/x + 5*x + x^2/2}
{(3*x - 4*x^2 + 3*x^3)/(1 + x^2), x, 4, -4*x + (3*x^2)/2 + 4*ArcTan[x]}
{(-x^2 + 2*x^4)/(1 + 2*x^2), x, 4, -x + x^3/3 + ArcTan[Sqrt[2]*x]/Sqrt[2]}
{(5 + 3*x)/(1 - x - x^2 + x^3), x, 4, 4/(1 - x) + ArcTanh[x]}
{(-1 - x - x^3 + x^4)/(-x^2 + x^3), x, 5, -(1/x) + x^2/2 - 4*ArcTanh[1 - 2*x]}
{(2 + x + x^2 + x^3)/(2 + 3*x^2 + x^4), x, 5, ArcTan[x] + Log[2 + x^2]/2}
{(-4 + 8*x - 4*x^2 + 4*x^3 - x^4 + x^5)/(2 + x^2)^3, x, 7, -(1/(2 + x^2)^2) - ArcTan[x/Sqrt[2]]/Sqrt[2] + (1/2)*Log[2 + x^2]}
{(-1 + x)/(3 - 4*x + 3*x^2), x, 2, ArcTan[(2 - 3*x)/Sqrt[5]]/(3*Sqrt[5]) + (1/6)*Log[3 - 4*x + 3*x^2]}
{(-1 - 3*x + x^2)/(-2*x + x^2 + x^3), x, 5, -Log[1 - x] + Log[x]/2 + (3/2)*Log[2 + x]}
{(3 + x + x^2 + x^3)/((1 + x^2)*(3 + x^2)), x, 5, ArcTan[x] + Log[3 + x^2]/2}
{(3 - x + 3*x^2 - 2*x^3 + x^4)/(3*x - 2*x^2 + x^3), x, 4, x^2/2 + Log[x] - (1/2)*Log[3 - 2*x + x^2]}
{(-1 + x + x^3)/(1 + x^2)^2, x, 6, -(x/(2*(1 + x^2))) - ArcTan[x]/2 + (1/2)*Log[1 + x^2]}
{(1 + 2*x - x^2 + 8*x^3 + x^4)/((x + x^2)*(1 + x^3)), x, 7, -(3/(1 + x)) - (2*ArcTan[(1 - 2*x)/Sqrt[3]])/Sqrt[3] + Log[x] - 2*Log[1 + x] + Log[1 - x + x^2]}
{(15 - 5*x + x^2 + x^3)/((5 + x^2)*(3 + 2*x + x^2)), x, 5, (-Sqrt[5])*ArcTan[x/Sqrt[5]] + (5*ArcTan[(1 + x)/Sqrt[2]])/Sqrt[2] + (1/2)*Log[3 + 2*x + x^2]}
{(-3 + 25*x + 23*x^2 + 32*x^3 + 15*x^4 + 7*x^5 + x^6)/((1 + x^2)^2*(2 + x + x^2)^2), x, 8, -3/(1 + x^2) + (2 + x + x^2)^(-1) + Log[1 + x^2] - Log[2 + x + x^2]}


(* ::Subsubsection::Closed:: *)
(*Edwards and Penney Calculus*)


{(2 + x^3)^2, x, 2, 4*x + x^4 + x^7/7}


{(-4 + x^2)/(2 + x), x, 2, -2*x + x^2/2}
{(x + 2*x^3)/(x^2 + x^4)^3, x, 2, -(1/(4*x^4*(1 + x^2)^2))}
{(2 - x^2)/(1 - 6*x + x^3)^5, x, 2, 1/(12*(1 - 6*x + x^3)^4)}
{1/((1 + x)*(1 + x^2)), x, 6, ArcTan[x]/2 + (1/2)*Log[1 + x] - (1/4)*Log[1 + x^2]}
{1/((1 + x^2)*(4 + x^2)), x, 4, (-(1/6))*ArcTan[x/2] + ArcTan[x]/3}
{(a + b*x^3)/(1 + x^2), x, 6, (b*x^2)/2 + a*ArcTan[x] - (1/2)*b*Log[1 + x^2]}
{(2*x + x^2)/(1 + x)^2, x, 3, x + (1 + x)^(-1)}
{(x + x^2)/((4 + x)*(-4 + x^2)), x, 4, (-(1/2))*ArcTanh[x/2] + Log[4 + x]}
{x/((1 + x)*(1 + x^2)), x, 6, ArcTan[x]/2 - (1/2)*Log[1 + x] + (1/4)*Log[1 + x^2]}
{(-10 + x^2)/(4 + 9*x^2 + 2*x^4), x, 3, ArcTan[x/2] - (3*ArcTan[Sqrt[2]*x])/Sqrt[2]}
{(4 + x^2)/((1 + x^2)*(2 + x^2)), x, 4, 3*ArcTan[x] - Sqrt[2]*ArcTan[x/Sqrt[2]]}
{(5 - 4*x + 3*x^2 + x^4)/((-1 + x)^2*(1 + x^2)), x, 7, 5/(2*(1 - x)) + x + 2*ArcTan[x] + (1/2)*Log[1 - x] + (3/4)*Log[1 + x^2]}
{(2*x^2 + x^4)/(-1 + x^3), x, 6, x^2/2 + ArcTan[(1 + 2*x)/Sqrt[3]]/Sqrt[3] + Log[1 - x] + (1/2)*Log[1 + x + x^2]}
{(31 + 5*x)/(11 - 4*x + 3*x^2), x, 2, -((103*ArcTan[(2 - 3*x)/Sqrt[29]])/(3*Sqrt[29])) + (5/6)*Log[11 - 4*x + 3*x^2]}
{(1 + x^4)/(2 + x^2), x, 4, -2*x + x^3/3 + (5*ArcTan[x/Sqrt[2]])/Sqrt[2]}
{(1 - x + 4*x^3)/(1 + x^3), x, 5, 4*x + (4*ArcTan[(1 - 2*x)/Sqrt[3]])/Sqrt[3] - (2/3)*Log[1 + x] + (1/3)*Log[1 - x + x^2]}
{(2 + 2*x + x^4)/(x^4 + x^5), x, 4, -2/(3*x^3) + Log[1 + x]}
{(-1 - 5*x + 2*x^2)/(2 - x - 2*x^2 + x^3), x, 5, 2*Log[1 - x] - Log[2 - x] + Log[1 + x]}
{(4 + 3*x^2 + 2*x^3)/(1 + x)^4, x, 5, -5/(3*(1 + x)^3) + 3/(1 + x) + 2*Log[1 + x]}
{(2 + x + x^3)/(1 + 2*x^2 + x^4), x, 6, x/(1 + x^2) + ArcTan[x] + Log[1 + x^2]/2}
{(1 + 2*x + x^2 + x^3)/(1 + 2*x^2 + x^4), x, 7, -(1/(2*(1 + x^2))) + ArcTan[x] + (1/2)*Log[1 + x^2]}


{(3 + 4*x)/((1 + x^2)*(2 + x^2)), x, 8, 3*ArcTan[x] - (3*ArcTan[x/Sqrt[2]])/Sqrt[2] + 2*Log[1 + x^2] - 2*Log[2 + x^2]}
{(2 + x)/((1 + x^2)*(4 + x^2)), x, 8, (-(1/3))*ArcTan[x/2] + (2*ArcTan[x])/3 + (1/6)*Log[1 + x^2] - (1/6)*Log[4 + x^2]}


(* ::Subsubsection::Closed:: *)
(*Grossman Calculus*)


{(-x + x^3)/(6 + 2*x), x, 4, 4*x - (3*x^2)/4 + x^3/6 - 12*Log[3 + x]}
{(7 - 2*x + 3*x^2 - x^3 + x^4)/(2 + x), x, 4, -20*x + (9*x^2)/2 - x^3 + x^4/4 + 47*Log[2 + x]}
{(3 + x^2)/(-3 + x^2), x, 3, x - 2*Sqrt[3]*ArcTanh[x/Sqrt[3]]}
{(-1 + x^2)/(1 + x^2), x, 3, x - 2*ArcTan[x]}
{(2 - x + x^3)/(-7 - 6*x + x^2), x, 5, 6*x + x^2/2 + (169/4)*Log[7 - x] - (1/4)*Log[1 + x]}
{(-1 + x^5)/(-1 + x^2), x, 5, x^2/2 + x^4/4 + Log[1 + x]}
{(5 + 2*x - x^2 + x^3)/(1 + x + x^2), x, 5, -2*x + x^2/2 + (11*ArcTan[(1 + 2*x)/Sqrt[3]])/Sqrt[3] + (3/2)*Log[1 + x + x^2]}
{(-3 + x - 2*x^3 + x^4)/(10 - 8*x + 2*x^2), x, 5, (3*x)/2 + x^2/2 + x^3/6 + 6*ArcTan[2 - x] + (3/4)*Log[5 - 4*x + x^2]}
{(1 + 2*x + 3*x^2 + x^3)/((-3 + x)*(-2 + x)*(-1 + x)), x, 5, x + (7/2)*Log[1 - x] - 25*Log[2 - x] + (61/2)*Log[3 - x]}
{(-2 + x^2 + x^3)/x^4, x, 2, 2/(3*x^3) - x^(-1) + Log[x]}
{(2 - 7*x + x^2 - x^3 + x^4)/(-24 - 14*x + x^2 + x^3), x, 6, -2*x + x^2/2 + (13/3)*Log[4 - x] - (22/3)*Log[2 + x] + 20*Log[3 + x]}
{(2 + x^2)/((-1 + x)^2*x*(1 + x)), x, 6, 3/(2*(1 - x)) - (5/4)*Log[1 - x] + 2*Log[x] - (3/4)*Log[1 + x]}
{1/((2 + x)*(1 + x^2)), x, 6, (2*ArcTan[x])/5 + (1/5)*Log[2 + x] - (1/10)*Log[1 + x^2]}
{(3 + x^2 + x^3)/(2 + x^2)^2, x, 8, 1/(2 + x^2) + x/(4*(2 + x^2)) + (5*ArcTan[x/Sqrt[2]])/(4*Sqrt[2]) + (1/2)*Log[2 + x^2]}
{x/((1 + x)^2*(1 + x^2)), x, 4, 1/(2*(1 + x)) + ArcTan[x]/2}
{(-35 + 70*x - 4*x^2 + 2*x^3)/((26 - 10*x + x^2)*(17 - 2*x + x^2)), x, 6, -((15033*ArcTan[5 - x])/1025) + (4607*ArcTan[1/4 - x/4])/4100 + (1003*Log[26 - 10*x + x^2])/1025 + (22*Log[17 - 2*x + x^2])/1025}
{x^2/((-1 + x)^2*(1 + x)^2), x, 3, x/(2*(1 - x^2)) - ArcTanh[x]/2}
{(2 + x^2)/((-5 + x)*(-3 + x)*(4 + x)), x, 5, (-(11/14))*Log[3 - x] + (3/2)*Log[5 - x] + (2/7)*Log[4 + x]}
{(-3 + x^2)/(-1 + x^3), x, 5, Sqrt[3]*ArcTan[(1 + 2*x)/Sqrt[3]] - (2*Log[1 - x])/3 + (5*Log[1 + x + x^2])/6}
{x^4/((-1 + x)*(2 + x^2)), x, 7, x + x^2/2 - (2/3)*Sqrt[2]*ArcTan[x/Sqrt[2]] + (1/3)*Log[1 - x] - (2/3)*Log[2 + x^2]}


(* ::Subsubsection::Closed:: *)
(*Hughes, Hallet, Gleason, et al Calculus, 2nd Edition*)


{(1 + x + x^3)/x^2, x, 2, -(1/x) + x^2/2 + Log[x]}


(* ::Subsubsection::Closed:: *)
(*Spivak Calculus*)


{(-1 + 7*x + 2*x^2)/(-1 - x + x^2 + x^3), x, 4, -3/(1 + x) + 2*Log[1 - x]}
{(1 + 2*x)/(-1 + 3*x - 3*x^2 + x^3), x, 2, -((1 + 2*x)^2/(6*(1 - x)^2))}
{(5 - 5*x + 7*x^2 + x^3)/((-1 + x)^2*(1 + x)^3), x, 4, (1 - x)^(-1) - 2/(1 + x)^2}
{(1 + 3*x + 3*x^2)/(1 + 2*x + 2*x^2 + x^3), x, 5, (-2*ArcTan[(1 + 2*x)/Sqrt[3]])/Sqrt[3] + Log[1 + x] + Log[1 + x + x^2]}


(* ::Subsubsection::Closed:: *)
(*Stewart Calculus*)


{(x + x^3)/(-1 + x), x, 4, 2*x + x^2/2 + x^3/3 + 2*Log[1 - x]}
{(-1 + 2*x + x^2)/(-2*x + 3*x^2 + 2*x^3), x, 5, (1/10)*Log[1 - 2*x] + Log[x]/2 - (1/10)*Log[2 + x]}
{(1 + 4*x - 2*x^2 + x^4)/(1 - x - x^2 + x^3), x, 5, 2/(1 - x) + x + x^2/2 - 2*ArcTanh[x]}
{(4 - x + 2*x^2)/(4*x + x^3), x, 6, (-(1/2))*ArcTan[x/2] + Log[x] + (1/2)*Log[4 + x^2]}
{(1 + x^2 + x^3)/((-1 + x)*x*(1 + x^2)^3*(1 + x + x^2)), x, 16, 1/(8*(1 + x^2)^2) + x/(8*(1 + x^2)^2) - 3/(8*(1 + x^2)) + (9*x)/(16*(1 + x^2)) + (7*ArcTan[x])/16 - ArcTan[(1 + 2*x)/Sqrt[3]]/Sqrt[3] + (1/8)*Log[1 - x] - Log[x] + (15/16)*Log[1 + x^2] - (1/2)*Log[1 + x + x^2]}
{(1 - 3*x + 2*x^2 - x^3)/(1 + x^2)^2, x, 8, 1/(1 + x^2) - x/(2*(1 + x^2)) + (3*ArcTan[x])/2 - (1/2)*Log[1 + x^2]}
{(1 - 3*x + 2*x^2 - x^3)/(x*(1 + x^2)^2), x, 9, -(1/(2*(1 + x^2))) - x/(1 + x^2) - 2*ArcTan[x] + Log[x] - (1/2)*Log[1 + x^2]}
{(-x^2 + x^3)/((-6 + x)*(3 + 5*x)^3), x, 6, -(12/(1375*(3 + 5*x)^2)) + 201/(15125*(3 + 5*x)) + (20*Log[6 - x])/3993 + (1493*Log[3 + 5*x])/499125}
{(1 - x - x^2 + x^3 + x^4)/(-x + x^3), x, 5, x + x^2/2 + (1/2)*Log[1 - x] - Log[x] + (1/2)*Log[1 + x]}
{(-2 + x^2)/(x*(2 + x^2)), x, 5, -Log[x] + Log[2 + x^2]}
{(2 - 4*x^2 + x^3)/((1 + x^2)*(2 + x^2)), x, 8, 6*ArcTan[x] - 5*Sqrt[2]*ArcTan[x/Sqrt[2]] - Log[1 + x^2]/2 + Log[2 + x^2]}
{(1 + x^2 + x^4)/((1 + x^2)*(4 + x^2)^2), x, 6, -((13*x)/(24*(4 + x^2))) + (25/144)*ArcTan[x/2] + ArcTan[x]/9}
{(1 + x^2 + x^3)/(2*x^2 + x^3 + x^4), x, 5, -(1/(2*x)) + ArcTan[(1 + 2*x)/Sqrt[7]]/(4*Sqrt[7]) - Log[x]/4 + (5/8)*Log[2 + x + x^2]}
{(1 - 12*x + x^2 + x^3)/(-12 + x + x^2), x, 5, x^2/2 - (2/7)*ArcTanh[(1/7)*(1 + 2*x)], x^2/2 + (1/7)*Log[3 - x] - (1/7)*Log[4 + x]}
{(-3 + 5*x + 6*x^2)/(-3*x + 2*x^2 + x^3), x, 5, 2*Log[1 - x] + Log[x] + 3*Log[3 + x]}
{(-2 + 3*x + 5*x^2)/(2*x^2 + x^3), x, 4, x^(-1) + 2*Log[x] + 3*Log[2 + x]}
{(18 - 2*x - 4*x^2)/(-6 + x + 4*x^2 + x^3), x, 5, Log[1 - x] - 2*Log[2 + x] - 3*Log[3 + x]}
{(2*x + x^2)/(4 + 3*x^2 + x^3), x, 2, Log[4 + 3*x^2 + x^3]/3}
{(-x + 2*x^3)/(1 - x^2 + x^4), x, 2, Log[1 - x^2 + x^4]/2}
{(-4 + 6*x - x^2 + 3*x^3)/((1 + x^2)*(2 + x^2)), x, 6, -3*ArcTan[x] + Sqrt[2]*ArcTan[x/Sqrt[2]] + (3*Log[1 + x^2])/2}
{(1 + x - 2*x^2 + x^3)/(4 + 5*x^2 + x^4), x, 6, (-(3/2))*ArcTan[x/2] + ArcTan[x] + (1/2)*Log[4 + x^2]}
{(-32 + 5*x - 27*x^2 + 4*x^3)/(-70 - 299*x - 286*x^2 + 50*x^3 - 13*x^4 + 30*x^5), x, 7, (3988*ArcTan[(1 + 2*x)/Sqrt[19]])/(13685*Sqrt[19]) - (3146*Log[7 - 3*x])/80155 - (334/323)*Log[1 + 2*x] + (4822*Log[2 + 5*x])/4879 + (11049*Log[5 + x + x^2])/260015}
{(8 - 13*x^2 - 7*x^3 + 12*x^5)/(4 - 20*x + 41*x^2 - 80*x^3 + 116*x^4 - 80*x^5 + 100*x^6), x, 10, 5828/(9075*(2 - 5*x)) - 313/(1452*(1 + 2*x^2)) - (251*x)/(726*(1 + 2*x^2)) + (503*ArcTan[Sqrt[2]*x])/(7986*Sqrt[2]) - (59096*Log[2 - 5*x])/99825 + (2843*Log[1 + 2*x^2])/7986}
{(1 + x + x^3)/(4*x + 2*x^2 + x^4), x, 2, (1/4)*Log[4*x + 2*x^2 + x^4]}
{1/(1 + x + x^2 + x^3), x, 6, ArcTan[x]/2 + (1/2)*Log[1 + x] - (1/4)*Log[1 + x^2]}
{x/((1 + x^2)*(4 + x^2)), x, 2, (-(1/3))*ArcTanh[5/3 + (2*x^2)/3]}


(* ::Subsubsection::Closed:: *)
(*Thomas Calculus, 8th Edition*)


{(-3 + x)*(-7 + 4*x^2), x, 2, 21*x - (7*x^2)/2 - 4*x^3 + x^4}
{(-2 + 7*x)^3, x, 1, (1/28)*(2 - 7*x)^4}


{(-1 + x^3)/(-1 + x), x, 2, x + x^2/2 + x^3/3}
{(-7 + 4*x^2)/(3 + 2*x), x, 4, -3*x + x^2 + Log[3 + 2*x]}
{(1 + x)/((-1 + x)*x^2), x, 4, 1/x + 4*ArcTanh[1 - 2*x]}
{(9 + x^4)/(x^2*(9 + x^2)), x, 4, -x^(-1) + x - (10*ArcTan[x/3])/3}
{(4*x^2 + x^3)/(x + x^3), x, 6, x - ArcTan[x] + 2*Log[1 + x^2]}
{(2*x + x^4)/(1 + x^2), x, 6, -x + x^3/3 + ArcTan[x] + Log[1 + x^2]}
{(4 + 4*x)/(x^2*(1 + x^2)), x, 6, -4/x - 4*ArcTan[x] + 4*Log[x] - 2*Log[1 + x^2]}
{(-x + x^3)/((-1 + x)^2*(1 + x^2)), x, 5, ArcTan[x] + Log[1 - x]}
{(2 + 5*x + 3*x^2 + 2*x^3)/(1 + x + x^2), x, 4, x + x^2 + Log[1 + x + x^2]}
{(2 + 2*x)/((-1 + x)^3*(1 + x^2)), x, 5, -(1/(1 - x)^2) - 1/(1 - x) + ArcTan[x]}
{(3 - 4*x - 5*x^2 + 3*x^3)/(x^3*(-1 + x + x^2)), x, 5, 3/(2*x^2) - 1/x - ArcTanh[(1 + 2*x)/Sqrt[5]]/Sqrt[5] + 3*Log[x] - (3/2)*Log[1 - x - x^2]}
{(-4 + x^2)/(2 - 5*x + x^3), x, 3, -(ArcTanh[(1 + x)/Sqrt[2]]/Sqrt[2]) + (1/2)*Log[1 - 2*x - x^2]}
{(2 + x)/(-1 + 2*x + x^2), x, 2, -(ArcTanh[(1 + x)/Sqrt[2]]/Sqrt[2]) + (1/2)*Log[1 - 2*x - x^2]}
{(4 + 8*x + 5*x^2 + 2*x^3)/(2 + 2*x + x^2)^2, x, 5, -(1/(2 + 2*x + x^2)) - ArcTan[1 + x] + Log[2 + 2*x + x^2]}
{(1 - 3*x + 2*x^2 - 4*x^3 + x^4)/(1 + 3*x^2 + 3*x^4 + x^6), x, 7, -(1/(4*(1 + x^2)^2)) + 2/(1 + x^2) + ArcTan[x]}
{((-1 + x)^4*x^4)/(1 + x^2), x, 4, 4*x - (4*x^3)/3 + x^5 - (2*x^6)/3 + x^7/7 - 4*ArcTan[x]}
{(-20*x + 4*x^2)/(9 - 10*x^2 + x^4), x, 6, Log[1 - x] - (1/2)*Log[3 - x] + (3/2)*Log[1 + x] - 2*Log[3 + x]}
{(24 + 8*x)/(x*(-4 + x^2)), x, 5, 5*Log[2 - x] - 6*Log[x] + Log[2 + x]}
{(-1 + x + 4*x^3)/((-1 + x)*x^2*(1 + x^2)), x, 7, -x^(-1) + ArcTan[x] + 2*Log[1 - x] - Log[1 + x^2]}


(* ::Subsection::Closed:: *)
(*Problems from integration competitions*)


(* ::Subsubsection::Closed:: *)
(*MIT Integration Competition*)


{(-1 + 3*x - 3*x^2 + x^3)/(1 + 4*x + 6*x^2 + 4*x^3 + x^4), x, 7, 8/(3*(1 + x)^3) - 6/(1 + x)^2 + 6/(1 + x) + Log[1 + x]}
{1/(4*x^2 + 4*x^3 + x^4), x, 6, -(1/(4*x)) - 1/(4*(2 + x)) + (1/2)*ArcTanh[1 + x]}
{(1 + x^2)/(1 + x), x, 4, -x + x^2/2 + 2*Log[1 + x]}


(* ::Subsubsection::Closed:: *)
(*North Texas University Integration Competition*)


{(-1 + 3*x - 3*x^2 + x^3)/x^2, x, 2, x^(-1) - 3*x + x^2/2 + 3*Log[x]}
{(1 + x + 2*x^2 + 2*x^3)/(x^2 + x^3 + x^4), x, 4, -x^(-1) + Log[1 + x + x^2]}


(* ::Subsubsection::Closed:: *)
(*University of Wisconsin Integration Competition*)


{((3 - Sqrt[37])/2 + x)*((3 + Sqrt[37])/2 + x), x, 2, -7*x + (3*x^2)/2 + x^3/3}
{(3*x + 3*x^2 + x^3)/(1 + 4*x + 6*x^2 + 4*x^3 + x^4), x, 5, 1/(3*(1 + x)^3) + Log[1 + x]}


(* ::Subsection::Closed:: *)
(*Miscellaneous problems*)


{(2 + x)/(x + x^2), x, 4, 2*Log[x] - Log[1 + x]}
{(x^3 + x^4)/(1 + x^2), x, 6, -x + x^2/2 + x^3/3 + ArcTan[x] - (1/2)*Log[1 + x^2]}
{(4 + x^2)/(2 + x), x, 4, -2*x + x^2/2 + 8*Log[2 + x]}
{(-32 + 36*x - 42*x^2 + 21*x^3 - 10*x^4 + 3*x^5)/(x*(1 + x^2)*(4 + x^2)^2), x, 9, (4 + x^2)^(-1) + ArcTan[x/2]/2 + 2*ArcTan[x] - 2*Log[x] + Log[4 + x^2]}


{(-1 + x^4 + 7*x^5 + x^9)/(-7 + 6*x^4 + x^8), x, 12, x^2/2 - ArcTan[(7^(1/4) - Sqrt[2]*x)/7^(1/4)]/(2*Sqrt[2]*7^(3/4)) + ArcTan[(7^(1/4) + Sqrt[2]*x)/7^(1/4)]/(2*Sqrt[2]*7^(3/4)) + (1/4)*Log[1 - x] + (1/4)*Log[1 + x] - (1/4)*Log[1 + x^2] - Log[Sqrt[7] - Sqrt[2]*7^(1/4)*x + x^2]/(4*Sqrt[2]*7^(3/4)) + Log[Sqrt[7] + Sqrt[2]*7^(1/4)*x + x^2]/(4*Sqrt[2]*7^(3/4))}
{(1 + x^3 + x^6)/(x + x^5), x, 12, x^2/2 - ArcTan[x^2]/2 - ArcTan[1 - Sqrt[2]*x]/(2*Sqrt[2]) + ArcTan[1 + Sqrt[2]*x]/(2*Sqrt[2]) + Log[x] + Log[1 - Sqrt[2]*x + x^2]/(4*Sqrt[2]) - Log[1 + Sqrt[2]*x + x^2]/(4*Sqrt[2]) - (1/4)*Log[1 + x^4]}
{1/(-7 + Sqrt[5] - 4*x^2), x, 1, -(ArcTan[(2*x)/Sqrt[7 - Sqrt[5]]]/(2*Sqrt[7 - Sqrt[5]]))}
{(11*x + 2*x^3)/(3 + 2*x^2 + x^4)^2, x, 5, 5/(8*(3 + 2*x^2 + x^4)) + (9*x^2)/(8*(3 + 2*x^2 + x^4)) + (9*ArcTan[(1 + x^2)/Sqrt[2]])/(8*Sqrt[2])}
{(-x + 2*x^3 + 4*x^5)/(3 + 2*x^2 + x^4)^2, x, 6, (5 - 7*x^2)/(8*(3 + 2*x^2 + x^4)) + (9*ArcTan[(1 + x^2)/Sqrt[2]])/(8*Sqrt[2]), 5/(8*(3 + 2*x^2 + x^4)) - (7*x^2)/(8*(3 + 2*x^2 + x^4)) + (9*ArcTan[(1 + x^2)/Sqrt[2]])/(8*Sqrt[2])}
{(x + x^5)/(1 + 2*x^2 + 2*x^4)^3, x, 7, (3 + 4*x^2)/(16*(1 + 2*x^2 + 2*x^4)^2) + (1 + 2*x^2)/(2 + 4*x^2 + 4*x^4) + ArcTan[1 + 2*x^2], 3/(16*(1 + 2*x^2 + 2*x^4)^2) + x^2/(4*(1 + 2*x^2 + 2*x^4)^2) + (1 + 2*x^2)/(2*(1 + 2*x^2 + 2*x^4)) + ArcTan[1 + 2*x^2]}
{1/(1 + Sqrt[5] - x^2 + Sqrt[5]*x^2), x, 2, (-(1/2))*ArcTan[(1/2)*(1 - Sqrt[5])*x]}
{x^11/(2 + 3*x^4 + x^8), x, 6, x^4/4 + (1/4)*Log[1 + x^4] - Log[2 + x^4]}
{(-11 + 6*x)/((-1 + 2*x)*(-1 + x^2)), x, 5, (16/3)*Log[1 - 2*x] - (5/2)*Log[1 - x] - (17/6)*Log[1 + x]}
{(a + b*x)^3/((c + d*x)*(e + f*x)), x, 5, -((b^2*(b*d*e + b*c*f - 3*a*d*f)*x)/(d^2*f^2)) + (b^3*x^2)/(2*d*f) - ((b*c - a*d)^3*Log[c + d*x])/(d^3*(d*e - c*f)) + ((b*e - a*f)^3*Log[e + f*x])/(f^3*(d*e - c*f))}


(* Note: This test problem formerly caused stack overflow because the degree of the polynomial 
	was not properly reduced by the Ostrogradskiy-Hermite method code. *)
(* {(a + 2*b*x - a*x^2)^4/(-1 + x^2)^5, x, 14, -((4*a*b*(3*a^2 - 2*b^2))/(3*(1 - x^2)^4)) + (11*a^4*x)/(5*(1 - x^2)^4) - (48*a^2*b^2*x)/(5*(1 - x^2)^4) + (6*b^4*x)/(5*(1 - x^2)^4) + (4*a*b*(9*a^2 - 8*b^2)*x^2)/(3*(1 - x^2)^4) - ((73*a^4 - 264*a^2*b^2 + 48*b^4)*x^3)/(15*(1 - x^2)^4) - (4*a*b*(3*a^2 - 2*b^2)*x^4)/(1 - x^2)^4 + (a^2*(11*a^2 - 24*b^2)*x^5)/(3*(1 - x^2)^4) + (4*a^3*b*x^6)/(1 - x^2)^4 - (a^4*x^7)/(1 - x^2)^4 - ((8*a^4 - 24*a^2*b^2 + 3*b^4)*x)/(15*(1 - x^2)^3) - ((8*a^4 - 24*a^2*b^2 + 3*b^4)*x)/(12*(1 - x^2)^2) - ((8*a^4 - 24*a^2*b^2 + 3*b^4)*x)/(8*(1 - x^2)) - (1/8)*(8*a^4 - 24*a^2*b^2 + 3*b^4)*ArcTanh[x]} *)


(* Integrands of the form x^m/(a*x+b*x^2)^n where m and are integers *)
{x^3/(a*x + b*x^2), x, 5, -((a*x)/b^2) + x^2/(2*b) + (a^2*Log[a + b*x])/b^3}
{x^2/(a*x + b*x^2), x, 4, x/b - (a*Log[a + b*x])/b^2}
{x/(a*x + b*x^2), x, 2, Log[a + b*x]/b}
{1/(a*x + b*x^2), x, 2, Log[x]/a - Log[a + b*x]/a}
{1/(x*(a*x + b*x^2)), x, 5, -(1/(a*x)) - (b*Log[x])/a^2 + (b*Log[a + b*x])/a^2}
{1/(x^2*(a*x + b*x^2)), x, 5, -(1/(2*a*x^2)) + b/(a^2*x) + (b^2*Log[x])/a^3 - (b^2*Log[a + b*x])/a^3}
{1/(x^3*(a*x + b*x^2)), x, 5, -(1/(3*a*x^3)) + b/(2*a^2*x^2) - b^2/(a^3*x) - (b^3*Log[x])/a^4 + (b^3*Log[a + b*x])/a^4}

{1/(a*x + b*x^2)^2, x, 6, -(1/(a^2*x)) - b/(a^2*(a + b*x)) - (2*b*Log[x])/a^3 + (2*b*Log[a + b*x])/a^3}
{1/(a*x + b*x^2)^3, x, 7, -(1/(2*a^3*x^2)) + (3*b)/(a^4*x) + b^2/(2*a^3*(a + b*x)^2) + (3*b^2)/(a^4*(a + b*x)) + (6*b^2*Log[x])/a^5 - (6*b^2*Log[a + b*x])/a^5}


(* Integrands of the form x^m/(a*x+b*x^2)^n where m and are integers *)
{x^3/(x  + x^2), x, 5, -x + x^2/2 + Log[1 + x]}
{x^2/(x  + x^2), x, 4, x - Log[1 + x]}
{x/(x  + x^2), x, 2, Log[1 + x]}
{1/(x  + x^2), x, 2, -2*ArcTanh[1 + 2*x]}
{1/(x*(x  + x^2)), x, 5, -(1/x) + 2*ArcTanh[1 + 2*x]}
{1/(x^2*(x  + x^2)), x, 5, -(1/(2*x^2)) + 1/x - 2*ArcTanh[1 + 2*x]}
{1/(x^3*(x  + x^2)), x, 5, -(1/(3*x^3)) + 1/(2*x^2) - 1/x + 2*ArcTanh[1 + 2*x]}

{1/(x  + x^2)^2, x, 6, -(1/x) - 1/(1 + x) + 4*ArcTanh[1 + 2*x]}
{1/(x  + x^2)^3, x, 7, -(1/(2*x^2)) + 3/x + 1/(2*(1 + x)^2) + 3/(1 + x) - 12*ArcTanh[1 + 2*x]}


(* Integrands of the form x^m/(a*x+b*x^3) where m is an integer *)
{x^4/(a*x + b*x^3), x, 5, x^2/(2*b) - (a*Log[a + b*x^2])/(2*b^2)}
{x^3/(a*x + b*x^3), x, 4, x/b - (Sqrt[a]*ArcTan[(Sqrt[b]*x)/Sqrt[a]])/b^(3/2)}
{x^2/(a*x + b*x^3), x, 3, Log[a + b*x^2]/(2*b)}
{x/(a*x + b*x^3), x, 2, ArcTan[(Sqrt[b]*x)/Sqrt[a]]/(Sqrt[a]*Sqrt[b])}
{1/(a*x + b*x^3), x, 2, Log[x]/a - Log[a + b*x^2]/(2*a)}
{1/(x*(a*x + b*x^3)), x, 5, -(1/(a*x)) - (Sqrt[b]*ArcTan[(Sqrt[b]*x)/Sqrt[a]])/a^(3/2)}
{1/(x^2*(a*x + b*x^3)), x, 6, -(1/(2*a*x^2)) - (b*Log[x])/a^2 + (b*Log[a + b*x^2])/(2*a^2)}
{1/(x^3*(a*x + b*x^3)), x, 5, -(1/(3*a*x^3)) + b/(a^2*x) + (b^(3/2)*ArcTan[(Sqrt[b]*x)/Sqrt[a]])/a^(5/2)}
{1/(x^4*(a*x + b*x^3)), x, 6, -(1/(4*a*x^4)) + b/(2*a^2*x^2) + (b^2*Log[x])/a^3 - (b^2*Log[a + b*x^2])/(2*a^3)}

(* In some of the following examples gcd cancellation should occur without also partial fraction 
	expansion, since that will result in unnecessary expansion. *)
{x^5/(x - x^3), x, 5, -x - x^3/3 + ArcTanh[x]}
{x^4/(x - x^3), x, 5, -(x^2/2) - (1/2)*Log[1 - x^2]}
{x^3/(x - x^3), x, 4, -x + ArcTanh[x]}
{x^2/(x - x^3), x, 3, (-(1/2))*Log[1 - x^2]}
{x/(x - x^3), x, 2, ArcTanh[x]}
{1/(x - x^3), x, 2, -ArcTanh[1 - 2*x^2]}
{1/(x*(x - x^3)), x, 5, -(1/x) + ArcTanh[x]}
{1/(x^2*(x - x^3)), x, 6, -(1/(2*x^2)) + Log[x] - (1/2)*Log[1 - x^2]}
{1/(x^3*(x - x^3)), x, 5, -(1/(3*x^3)) - 1/x + ArcTanh[x]}
{1/(x^4*(x - x^3)), x, 6, -(1/(4*x^4)) - 1/(2*x^2) + Log[x] - (1/2)*Log[1 - x^2]}


(* Integrands of the form x^m/(a*x^2+b*x^4) where m is an integer *)
{x^4/(a*x^2 + b*x^4), x, 4, x/b - (Sqrt[a]*ArcTan[(Sqrt[b]*x)/Sqrt[a]])/b^(3/2)}
{x^3/(a*x^2 + b*x^4), x, 3, Log[a + b*x^2]/(2*b)}
{x^2/(a*x^2 + b*x^4), x, 2, ArcTan[(Sqrt[b]*x)/Sqrt[a]]/(Sqrt[a]*Sqrt[b])}
{x/(a*x^2 + b*x^4), x, 2, Log[x]/a - Log[a + b*x^2]/(2*a)}
{1/(a*x^2 + b*x^4), x, 5, -(1/(a*x)) - (Sqrt[b]*ArcTan[(Sqrt[b]*x)/Sqrt[a]])/a^(3/2)}
{1/(x*(a*x^2 + b*x^4)), x, 6, -(1/(2*a*x^2)) - (b*Log[x])/a^2 + (b*Log[a + b*x^2])/(2*a^2)}
{1/(x^2*(a*x^2 + b*x^4)), x, 5, -(1/(3*a*x^3)) + b/(a^2*x) + (b^(3/2)*ArcTan[(Sqrt[b]*x)/Sqrt[a]])/a^(5/2)}
{1/(x^3*(a*x^2 + b*x^4)), x, 6, -(1/(4*a*x^4)) + b/(2*a^2*x^2) + (b^2*Log[x])/a^3 - (b^2*Log[a + b*x^2])/(2*a^3)}
{1/(x^4*(a*x^2 + b*x^4)), x, 5, -(1/(5*a*x^5)) + b/(3*a^2*x^3) - b^2/(a^3*x) - (b^(5/2)*ArcTan[(Sqrt[b]*x)/Sqrt[a]])/a^(7/2)}


(* Integrands of the form x^m/(a*x^3+b*x^4) where m is an integer *)
{x/(a*x^3 + b*x^4), x, 5, -(1/(a*x)) - (b*Log[x])/a^2 + (b*Log[a + b*x])/a^2}
{1/(a*x^3 + b*x^4), x, 5, -(1/(2*a*x^2)) + b/(a^2*x) + (b^2*Log[x])/a^3 - (b^2*Log[a + b*x])/a^3}


(* Integrands of the form 1/(a*x^m + b*x^n) where m and n are integers *)
{1/(a*x + b*x), x, 3, Log[x]/(a + b)}
{1/(a*x^2 + b*x^2), x, 3, -(1/((a + b)*x))}

{1/(-x^3 + x^6), x, 8, 1/(2*x^2) - ArcTan[(1 + 2*x)/Sqrt[3]]/Sqrt[3] + (1/3)*Log[1 - x] - (1/6)*Log[1 + x + x^2]}


{1/(a*x + b/x), x, 2, Log[b + a*x^2]/(2*a)}
{1/(a*x + b/x^2), x, 2, Log[b + a*x^3]/(3*a)}
{1/(a*x + b/x^3), x, 2, Log[b + a*x^4]/(4*a)}
{1/(a*x + b/x)^3, x, 2, x^4/(4*b*(b + a*x^2)^2)}
{1/(a*x^2 + b/x^3)^3, x, 2, x^10/(10*b*(b + a*x^5)^2)}
{1/(a*x^3 + b/x^5)^3, x, 2, x^16/(16*b*(b + a*x^8)^2)}


(* Integrands of the form (a+b*x^m)/(c*x^n+d*x^p) where m, n and p are integers *)
{(1 + x)/(2*x + x^2), x, 2, (1/2)*Log[2*x + x^2]}
{(1 + x^2)/(3*x + x^3), x, 2, (1/3)*Log[3*x + x^3]}
{(a + 2*b*x)/(a*x + b*x^2), x, 2, Log[a*x+b*x^2]}
{(a + 3*b*x^2)/(a*x + b*x^3), x, 2, Log[a*x+b*x^3]}

{(6 + 3*x)/(3*x + x^2), x, 4, 2*Log[x] + Log[3 + x]}
{(1 + x^2)/(-x + x^2), x, 4, x + 2*Log[1 - x] - Log[x]}

{(-2 + 4*x)/(-x + x^3), x, 5, Log[1 - x] + 2*Log[x] - 3*Log[1 + x]}
{(4 + x)/(4*x + x^3), x, 6, (1/2)*ArcTan[x/2] + Log[x] - (1/2)*Log[4 + x^2]}
{(-1 + x^2)/(-2*x + x^3), x, 5, Log[x]/2 + (1/4)*Log[2 - x^2]}
{(1 + x^3)/(-x + x^3), x, 4, x + 2*ArcTanh[1 - 2*x]}
{(1 + x^3)/(-x^2 + x^3), x, 4, x^(-1) + x + 2*Log[1 - x] - Log[x]}
{(-1 + x^5)/(-x + x^3), x, 4, x + x^3/3 - 2*ArcTanh[1 + 2*x]}
{(-3 + 2*x)/(-x^2 + x^3), x, 4, -(3/x) - 2*ArcTanh[1 - 2*x]}
{(1 - 2*x^2)/(x^2 - x^4), x, 4, -1/x - ArcTanh[x]}

{(4 + 3*x^4)/(5*x + 2*x^5), x, 5, (4*Log[x])/5 + (7*Log[5 + 2*x^4])/40}
{(1 + x^4)/(x^3 + x^5), x, 5, -1/(2*x^2) - Log[x] + Log[1 + x^2]}
{(1 + x^6)/(x - x^7), x, 5, Log[x] - Log[1 - x^6]/3}
{(8 + 5*x^10)/(2*x - x^11), x, 5, 4*Log[x] - (9/10)*Log[2 - x^10]}
{(8 + 5*x^10)/(x - x^11), x, 5, 8*Log[x] - (13*Log[1 - x^10])/10}


{(1 + x^2)/(x*(3 + x^2)), x, 5, Log[x]/3 + (1/3)*Log[3 + x^2]}
{(1 + x^6)/(x*(1 - x^6)), x, 5, Log[x] - Log[1 - x^6]/3}


(* Integrands of the form (a+b*x^m)/(c*x^n+d*x^p+e*x^q) where m, n, p and q are integers *)
{(x^2*(-2 + x^3))/(1 - x^3 + x^6), x, 3, ArcTan[(1 - 2*x^3)/Sqrt[3]]/Sqrt[3] + (1/6)*Log[1 - x^3 + x^6]}
{(1 + x^3)/(x*(1 - x^3 + x^6)), x, 3, -(ArcTan[(1 - 2*x^3)/Sqrt[3]]/Sqrt[3]) + Log[x] - (1/6)*Log[1 - x^3 + x^6]}
{(1 + x^3)/(x - x^4 + x^7), x, 6, -(ArcTan[(1 - 2*x^3)/Sqrt[3]]/Sqrt[3]) + Log[x] - (1/6)*Log[1 - x^3 + x^6]}
{(1 + x^2)/(x + 2*x^2 + x^3), x, 4, 2/(1 + x) + Log[x]}
{(1 + x)/(-6*x + x^2 + x^3), x, 5, (3/10)*Log[2 - x] - Log[x]/6 - (2/15)*Log[3 + x]}
{(2 + 4*x)/(x^2 + 2*x^3 + x^4), x, 4, -(2/(x*(1 + x)))}
{(1 + x^5)/(-10*x - 3*x^2 + x^3), x, 5, 19*x + (3*x^2)/2 + x^3/3 + (3126*Log[5 - x])/35 - Log[x]/10 - (31*Log[2 + x])/14}


{(a*x^2 + b*x^3)/(c*x^2 + d*x^3), x, 4, (b*x)/d - ((b*c - a*d)*Log[c + d*x])/d^2}
{(x + x^2)/(-2*x - x^2 + x^3), x, 2, Log[2 - x]}


{(x*(-7 + 4*x^2))/(4 - 5*x^2 + x^4), x, 5, (1/2)*Log[1 - x^2] + (3/2)*Log[4 - x^2]}
{(-7*x + 4*x^3)/(4 - 5*x^2 + x^4), x, 6, (3*Log[-4 + x^2] + Log[-1 + x^2])/2, (1/2)*Log[1 - x] + (3/2)*Log[2 - x] + (1/2)*Log[1 + x] + (3/2)*Log[2 + x]}
{(2*x + x^3)/(1 + x^2 + x^4), x, 6, (2*Sqrt[3]*ArcTan[(1 + 2*x^2)/Sqrt[3]] + Log[1 + x^2 + x^4])/4, (-(1/2))*Sqrt[3]*ArcTan[(1 - 2*x)/Sqrt[3]] - (1/2)*Sqrt[3]*ArcTan[(1 + 2*x)/Sqrt[3]] + (1/4)*Log[1 - x + x^2] + (1/4)*Log[1 + x + x^2]}

{(1 + x + 4*x^2)/(-1 + x^3), x, 4, 2*Log[1 - x] + Log[1 + x + x^2]}

{2/(-1 + x) + (1 + 2*x)/(1 + x + x^2), x, 3, 2*Log[1 - x] + Log[1 + x + x^2]}
{(1 + 4*x + 3*x^2)/(4 + 7*x + 2*x^2)^2, x, 2, -(1/(4 + 7*x + 2*x^2)) - (3*x)/(2*(4 + 7*x + 2*x^2))}

{(b*c - a*d - 2*a*e*x - b*e*x^2 - 3*a*f*x^2 - 2*b*f*x^3)/(c + d*x + e*x^2 + f*x^3)^2, x, 3, a/(c + d*x + e*x^2 + f*x^3) + (b*x)/(c + d*x + e*x^2 + f*x^3)}
{(9 - 40*x - 18*x^2 + 174*x^4 + 24*x^5 + 26*x^6 - 39*x^8)/(3 + 2*x^2 + x^4)^3, x, 5, 2/(3 + 2*x^2 + x^4)^2 + (3*x)/(3 + 2*x^2 + x^4)^2 - (4*x^2)/(3 + 2*x^2 + x^4)^2 + (13*x^5)/(3 + 2*x^2 + x^4)^2}
{(-3 + 10*x + 4*x^3 - 30*x^5)/(3 + x + x^4)^3 - (3*(1 + 4*x^3)*(2 - 3*x + 5*x^2 + x^4 - 5*x^6))/(3 + x + x^4)^4, x, -13, (2 - 3*x + 5*x^2 + x^4 - 5*x^6)/(3 + x + x^4)^3}
{(15 - 5*x + x^2 + x^3)/((5 + x^2)*(3 + 2*x + x^2)), x, 5, (-Sqrt[5])*ArcTan[x/Sqrt[5]] + (5*ArcTan[(1 + x)/Sqrt[2]])/Sqrt[2] + (1/2)*Log[3 + 2*x + x^2]}
{1/(1/x^2 + x^3), x, 10, (1/10)*Sqrt[10 - 2*Sqrt[5]]*ArcTan[(1 - Sqrt[5] - 4*x)/Sqrt[10 + 2*Sqrt[5]]] - (1/10)*Sqrt[10 + 2*Sqrt[5]]*ArcTan[(1 + Sqrt[5] - 4*x)/Sqrt[10 - 2*Sqrt[5]]] + (1/5)*Log[1 + x] - (1/20)*(1 + Sqrt[5])*Log[2 - (1 - Sqrt[5])*x + 2*x^2] - (1/20)*(1 - Sqrt[5])*Log[2 - (1 + Sqrt[5])*x + 2*x^2]}

{1/((c + d*x)*(a^2 + 2*a*b*x + b^2*x^2)), x, 6, -(1/((b*c - a*d)*(a + b*x))) - (d*Log[a + b*x])/(b*c - a*d)^2 + (d*Log[c + d*x])/(b*c - a*d)^2}
{(2 - x^2)/(1 - 6*x + x^3)^5, x, 2, 1/(12*(1 - 6*x + x^3)^4)}

{1/((1 + x^2)*(3 + 10*x/(1 + x^2))), x, 2, (-(1/4))*ArcTanh[5/4 + (3*x)/4]}


{(e - 2*f*(-1 + n)*x^n)/(e^2 + 4*d*f*x^2 + 4*e*f*x^n + 4*f^2*x^(2*n)), x, 1, ArcTan[(2*Sqrt[d]*Sqrt[f]*(-1 + n)*x)/(e*(-1 + n) + 2*f*(-1 + n)*x^n)]/(2*Sqrt[d]*Sqrt[f])}
{(e - 2*f*(-1 + n)*x^n)/(e^2 - 4*d*f*x^2 + 4*e*f*x^n + 4*f^2*x^(2*n)), x, 1, ArcTanh[(2*Sqrt[d]*Sqrt[f]*(-1 + n)*x)/(e*(-1 + n) + 2*f*(-1 + n)*x^n)]/(2*Sqrt[d]*Sqrt[f])}


{(x^m*(e*(1 + m) + 2*f*(1 + m - n)*x^n))/(e^2 + 4*d*f*x^(2 + 2*m) + 4*e*f*x^n + 4*f^2*x^(2*n)), x, 1, ArcTan[(2*Sqrt[d]*Sqrt[f]*(1 + m)*(1 + m - n)*x^(1 + m))/(e*(1 + m)*(1 + m - n) + 2*f*(1 + m)*(1 + m - n)*x^n)]/(2*Sqrt[d]*Sqrt[f])}
{(x^m*(e*(1 + m) + 2*f*(1 + m - n)*x^n))/(e^2 - 4*d*f*x^(2 + 2*m) + 4*e*f*x^n + 4*f^2*x^(2*n)), x, 1, ArcTanh[(2*Sqrt[d]*Sqrt[f]*(1 + m)*(1 + m - n)*x^(1 + m))/(e*(1 + m)*(1 + m - n) + 2*f*(1 + m)*(1 + m - n)*x^n)]/(2*Sqrt[d]*Sqrt[f])}
