(* ::Package:: *)

(* ::Title:: *)
(*Integration problems of the form *)
(*Sec[c+d x]^m (A+B Sec[c+d x]+C Sec[c+d x]^2) (b Sec[c+d x])^(n/2)*)


(* ::Section:: *)
(*Sec[c+d x]^m (b Sec[c+d x])^(n/2)*)


(* ::Subsection::Closed:: *)
(*Integrands of the form Sec[c+d x]^m (b Sec[c+d x])^(n/2)*)


(* ::Subsubsection::Closed:: *)
(*n>0*)


{Sec[c + d*x]^4*Sqrt[b*Sec[c + d*x]], x, 5, (10*Sqrt[Cos[c + d*x]]*EllipticF[(1/2)*(c + d*x), 2]*Sqrt[b*Sec[c + d*x]])/(21*d) + (10*(b*Sec[c + d*x])^(3/2)*Sin[c + d*x])/(21*b*d) + (2*(b*Sec[c + d*x])^(7/2)*Sin[c + d*x])/(7*b^3*d)}
{Sec[c + d*x]^3*Sqrt[b*Sec[c + d*x]], x, 5, -((6*b*EllipticE[(1/2)*(c + d*x), 2])/(5*d*Sqrt[Cos[c + d*x]]*Sqrt[b*Sec[c + d*x]])) + (6*Sqrt[b*Sec[c + d*x]]*Sin[c + d*x])/(5*d) + (2*(b*Sec[c + d*x])^(5/2)*Sin[c + d*x])/(5*b^2*d)}
{Sec[c + d*x]^2*Sqrt[b*Sec[c + d*x]], x, 4, (2*Sqrt[Cos[c + d*x]]*EllipticF[(1/2)*(c + d*x), 2]*Sqrt[b*Sec[c + d*x]])/(3*d) + (2*(b*Sec[c + d*x])^(3/2)*Sin[c + d*x])/(3*b*d)}
{Sec[c + d*x]^1*Sqrt[b*Sec[c + d*x]], x, 4, -((2*b*EllipticE[(1/2)*(c + d*x), 2])/(d*Sqrt[Cos[c + d*x]]*Sqrt[b*Sec[c + d*x]])) + (2*Sqrt[b*Sec[c + d*x]]*Sin[c + d*x])/d}
{Sec[c + d*x]^0*Sqrt[b*Sec[c + d*x]], x, 2, (2*Sqrt[Cos[c + d*x]]*EllipticF[(c + d*x)/2, 2]*Sqrt[b*Sec[c + d*x]])/d}
{Cos[c + d*x]^1*Sqrt[b*Sec[c + d*x]], x, 3, (2*b*EllipticE[(c + d*x)/2, 2])/(d*Sqrt[Cos[c + d*x]]*Sqrt[b*Sec[c + d*x]])}
{Cos[c + d*x]^2*Sqrt[b*Sec[c + d*x]], x, 4, (2*Sqrt[Cos[c + d*x]]*EllipticF[(1/2)*(c + d*x), 2]*Sqrt[b*Sec[c + d*x]])/(3*d) + (2*b*Sin[c + d*x])/(3*d*Sqrt[b*Sec[c + d*x]])}
{Cos[c + d*x]^3*Sqrt[b*Sec[c + d*x]], x, 4, (6*b*EllipticE[(1/2)*(c + d*x), 2])/(5*d*Sqrt[Cos[c + d*x]]*Sqrt[b*Sec[c + d*x]]) + (2*b^2*Sin[c + d*x])/(5*d*(b*Sec[c + d*x])^(3/2))}
{Cos[c + d*x]^4*Sqrt[b*Sec[c + d*x]], x, 5, (10*Sqrt[Cos[c + d*x]]*EllipticF[(1/2)*(c + d*x), 2]*Sqrt[b*Sec[c + d*x]])/(21*d) + (2*b^3*Sin[c + d*x])/(7*d*(b*Sec[c + d*x])^(5/2)) + (10*b*Sin[c + d*x])/(21*d*Sqrt[b*Sec[c + d*x]])}
{Cos[c + d*x]^5*Sqrt[b*Sec[c + d*x]], x, 5, (14*b*EllipticE[(1/2)*(c + d*x), 2])/(15*d*Sqrt[Cos[c + d*x]]*Sqrt[b*Sec[c + d*x]]) + (2*b^4*Sin[c + d*x])/(9*d*(b*Sec[c + d*x])^(7/2)) + (14*b^2*Sin[c + d*x])/(45*d*(b*Sec[c + d*x])^(3/2))}


{Sec[c + d*x]^3*(b*Sec[c + d*x])^(3/2), x, 5, (10*b*Sqrt[Cos[c + d*x]]*EllipticF[(1/2)*(c + d*x), 2]*Sqrt[b*Sec[c + d*x]])/(21*d) + (10*(b*Sec[c + d*x])^(3/2)*Sin[c + d*x])/(21*d) + (2*(b*Sec[c + d*x])^(7/2)*Sin[c + d*x])/(7*b^2*d)}
{Sec[c + d*x]^2*(b*Sec[c + d*x])^(3/2), x, 5, -((6*b^2*EllipticE[(1/2)*(c + d*x), 2])/(5*d*Sqrt[Cos[c + d*x]]*Sqrt[b*Sec[c + d*x]])) + (6*b*Sqrt[b*Sec[c + d*x]]*Sin[c + d*x])/(5*d) + (2*(b*Sec[c + d*x])^(5/2)*Sin[c + d*x])/(5*b*d)}
{Sec[c + d*x]^1*(b*Sec[c + d*x])^(3/2), x, 4, (2*b*Sqrt[Cos[c + d*x]]*EllipticF[(1/2)*(c + d*x), 2]*Sqrt[b*Sec[c + d*x]])/(3*d) + (2*(b*Sec[c + d*x])^(3/2)*Sin[c + d*x])/(3*d)}
{Sec[c + d*x]^0*(b*Sec[c + d*x])^(3/2), x, 3, -((2*b^2*EllipticE[(1/2)*(c + d*x), 2])/(d*Sqrt[Cos[c + d*x]]*Sqrt[b*Sec[c + d*x]])) + (2*b*Sqrt[b*Sec[c + d*x]]*Sin[c + d*x])/d}
{Cos[c + d*x]^1*(b*Sec[c + d*x])^(3/2), x, 3, (2*b*Sqrt[Cos[c + d*x]]*EllipticF[(c + d*x)/2, 2]*Sqrt[b*Sec[c + d*x]])/d}
{Cos[c + d*x]^2*(b*Sec[c + d*x])^(3/2), x, 3, (2*b^2*EllipticE[(c + d*x)/2, 2])/(d*Sqrt[Cos[c + d*x]]*Sqrt[b*Sec[c + d*x]])}
{Cos[c + d*x]^3*(b*Sec[c + d*x])^(3/2), x, 4, (2*b*Sqrt[Cos[c + d*x]]*EllipticF[(1/2)*(c + d*x), 2]*Sqrt[b*Sec[c + d*x]])/(3*d) + (2*b^2*Sin[c + d*x])/(3*d*Sqrt[b*Sec[c + d*x]])}
{Cos[c + d*x]^4*(b*Sec[c + d*x])^(3/2), x, 4, (6*b^2*EllipticE[(1/2)*(c + d*x), 2])/(5*d*Sqrt[Cos[c + d*x]]*Sqrt[b*Sec[c + d*x]]) + (2*b^3*Sin[c + d*x])/(5*d*(b*Sec[c + d*x])^(3/2))}
{Cos[c + d*x]^5*(b*Sec[c + d*x])^(3/2), x, 5, (10*b*Sqrt[Cos[c + d*x]]*EllipticF[(1/2)*(c + d*x), 2]*Sqrt[b*Sec[c + d*x]])/(21*d) + (2*b^4*Sin[c + d*x])/(7*d*(b*Sec[c + d*x])^(5/2)) + (10*b^2*Sin[c + d*x])/(21*d*Sqrt[b*Sec[c + d*x]])}
{Cos[c + d*x]^6*(b*Sec[c + d*x])^(3/2), x, 5, (14*b^2*EllipticE[(1/2)*(c + d*x), 2])/(15*d*Sqrt[Cos[c + d*x]]*Sqrt[b*Sec[c + d*x]]) + (2*b^5*Sin[c + d*x])/(9*d*(b*Sec[c + d*x])^(7/2)) + (14*b^3*Sin[c + d*x])/(45*d*(b*Sec[c + d*x])^(3/2))}


{Sec[c + d*x]^2*(b*Sec[c + d*x])^(5/2), x, 5, (10*b^2*Sqrt[Cos[c + d*x]]*EllipticF[(1/2)*(c + d*x), 2]*Sqrt[b*Sec[c + d*x]])/(21*d) + (10*b*(b*Sec[c + d*x])^(3/2)*Sin[c + d*x])/(21*d) + (2*(b*Sec[c + d*x])^(7/2)*Sin[c + d*x])/(7*b*d)}
{Sec[c + d*x]^1*(b*Sec[c + d*x])^(5/2), x, 5, -((6*b^3*EllipticE[(1/2)*(c + d*x), 2])/(5*d*Sqrt[Cos[c + d*x]]*Sqrt[b*Sec[c + d*x]])) + (6*b^2*Sqrt[b*Sec[c + d*x]]*Sin[c + d*x])/(5*d) + (2*(b*Sec[c + d*x])^(5/2)*Sin[c + d*x])/(5*d)}
{Sec[c + d*x]^0*(b*Sec[c + d*x])^(5/2), x, 3, (2*b^2*Sqrt[Cos[c + d*x]]*EllipticF[(1/2)*(c + d*x), 2]*Sqrt[b*Sec[c + d*x]])/(3*d) + (2*b*(b*Sec[c + d*x])^(3/2)*Sin[c + d*x])/(3*d)}
{Cos[c + d*x]^1*(b*Sec[c + d*x])^(5/2), x, 4, -((2*b^3*EllipticE[(1/2)*(c + d*x), 2])/(d*Sqrt[Cos[c + d*x]]*Sqrt[b*Sec[c + d*x]])) + (2*b^2*Sqrt[b*Sec[c + d*x]]*Sin[c + d*x])/d}
{Cos[c + d*x]^2*(b*Sec[c + d*x])^(5/2), x, 3, (2*b^2*Sqrt[Cos[c + d*x]]*EllipticF[(c + d*x)/2, 2]*Sqrt[b*Sec[c + d*x]])/d}
{Cos[c + d*x]^3*(b*Sec[c + d*x])^(5/2), x, 3, (2*b^3*EllipticE[(c + d*x)/2, 2])/(d*Sqrt[Cos[c + d*x]]*Sqrt[b*Sec[c + d*x]])}
{Cos[c + d*x]^4*(b*Sec[c + d*x])^(5/2), x, 4, (2*b^2*Sqrt[Cos[c + d*x]]*EllipticF[(1/2)*(c + d*x), 2]*Sqrt[b*Sec[c + d*x]])/(3*d) + (2*b^3*Sin[c + d*x])/(3*d*Sqrt[b*Sec[c + d*x]])}
{Cos[c + d*x]^5*(b*Sec[c + d*x])^(5/2), x, 4, (6*b^3*EllipticE[(1/2)*(c + d*x), 2])/(5*d*Sqrt[Cos[c + d*x]]*Sqrt[b*Sec[c + d*x]]) + (2*b^4*Sin[c + d*x])/(5*d*(b*Sec[c + d*x])^(3/2))}
{Cos[c + d*x]^6*(b*Sec[c + d*x])^(5/2), x, 5, (10*b^2*Sqrt[Cos[c + d*x]]*EllipticF[(1/2)*(c + d*x), 2]*Sqrt[b*Sec[c + d*x]])/(21*d) + (2*b^5*Sin[c + d*x])/(7*d*(b*Sec[c + d*x])^(5/2)) + (10*b^3*Sin[c + d*x])/(21*d*Sqrt[b*Sec[c + d*x]])}
{Cos[c + d*x]^7*(b*Sec[c + d*x])^(5/2), x, 5, (14*b^3*EllipticE[(1/2)*(c + d*x), 2])/(15*d*Sqrt[Cos[c + d*x]]*Sqrt[b*Sec[c + d*x]]) + (2*b^6*Sin[c + d*x])/(9*d*(b*Sec[c + d*x])^(7/2)) + (14*b^4*Sin[c + d*x])/(45*d*(b*Sec[c + d*x])^(3/2))}


{(b*Sec[c + d*x])^(7/2), x, 4, -((6*b^4*EllipticE[(1/2)*(c + d*x), 2])/(5*d*Sqrt[Cos[c + d*x]]*Sqrt[b*Sec[c + d*x]])) + (6*b^3*Sqrt[b*Sec[c + d*x]]*Sin[c + d*x])/(5*d) + (2*b*(b*Sec[c + d*x])^(5/2)*Sin[c + d*x])/(5*d)}


(* ::Subsubsection::Closed:: *)
(*n<0*)


{Sec[c + d*x]^5/Sqrt[b*Sec[c + d*x]], x, 5, (10*Sqrt[Cos[c + d*x]]*EllipticF[(1/2)*(c + d*x), 2]*Sqrt[b*Sec[c + d*x]])/(21*b*d) + (10*(b*Sec[c + d*x])^(3/2)*Sin[c + d*x])/(21*b^2*d) + (2*(b*Sec[c + d*x])^(7/2)*Sin[c + d*x])/(7*b^4*d)}
{Sec[c + d*x]^4/Sqrt[b*Sec[c + d*x]], x, 5, -((6*EllipticE[(1/2)*(c + d*x), 2])/(5*d*Sqrt[Cos[c + d*x]]*Sqrt[b*Sec[c + d*x]])) + (6*Sqrt[b*Sec[c + d*x]]*Sin[c + d*x])/(5*b*d) + (2*(b*Sec[c + d*x])^(5/2)*Sin[c + d*x])/(5*b^3*d)}
{Sec[c + d*x]^3/Sqrt[b*Sec[c + d*x]], x, 4, (2*Sqrt[Cos[c + d*x]]*EllipticF[(1/2)*(c + d*x), 2]*Sqrt[b*Sec[c + d*x]])/(3*b*d) + (2*(b*Sec[c + d*x])^(3/2)*Sin[c + d*x])/(3*b^2*d)}
{Sec[c + d*x]^2/Sqrt[b*Sec[c + d*x]], x, 4, -((2*EllipticE[(1/2)*(c + d*x), 2])/(d*Sqrt[Cos[c + d*x]]*Sqrt[b*Sec[c + d*x]])) + (2*Sqrt[b*Sec[c + d*x]]*Sin[c + d*x])/(b*d)}
{Sec[c + d*x]^1/Sqrt[b*Sec[c + d*x]], x, 3, (2*Sqrt[Cos[c + d*x]]*EllipticF[(c + d*x)/2, 2]*Sqrt[b*Sec[c + d*x]])/(b*d)}
{Sec[c + d*x]^0/Sqrt[b*Sec[c + d*x]], x, 2, (2*EllipticE[(c + d*x)/2, 2])/(d*Sqrt[Cos[c + d*x]]*Sqrt[b*Sec[c + d*x]])}
{Cos[c + d*x]^1/Sqrt[b*Sec[c + d*x]], x, 4, (2*Sqrt[Cos[c + d*x]]*EllipticF[(1/2)*(c + d*x), 2]*Sqrt[b*Sec[c + d*x]])/(3*b*d) + (2*Sin[c + d*x])/(3*d*Sqrt[b*Sec[c + d*x]])}
{Cos[c + d*x]^2/Sqrt[b*Sec[c + d*x]], x, 4, (6*EllipticE[(1/2)*(c + d*x), 2])/(5*d*Sqrt[Cos[c + d*x]]*Sqrt[b*Sec[c + d*x]]) + (2*b*Sin[c + d*x])/(5*d*(b*Sec[c + d*x])^(3/2))}
{Cos[c + d*x]^3/Sqrt[b*Sec[c + d*x]], x, 5, (10*Sqrt[Cos[c + d*x]]*EllipticF[(1/2)*(c + d*x), 2]*Sqrt[b*Sec[c + d*x]])/(21*b*d) + (2*b^2*Sin[c + d*x])/(7*d*(b*Sec[c + d*x])^(5/2)) + (10*Sin[c + d*x])/(21*d*Sqrt[b*Sec[c + d*x]])}
{Cos[c + d*x]^4/Sqrt[b*Sec[c + d*x]], x, 5, (14*EllipticE[(1/2)*(c + d*x), 2])/(15*d*Sqrt[Cos[c + d*x]]*Sqrt[b*Sec[c + d*x]]) + (2*b^3*Sin[c + d*x])/(9*d*(b*Sec[c + d*x])^(7/2)) + (14*b*Sin[c + d*x])/(45*d*(b*Sec[c + d*x])^(3/2))}


{Sec[c + d*x]^6/(b*Sec[c + d*x])^(3/2), x, 5, (10*Sqrt[Cos[c + d*x]]*EllipticF[(1/2)*(c + d*x), 2]*Sqrt[b*Sec[c + d*x]])/(21*b^2*d) + (10*(b*Sec[c + d*x])^(3/2)*Sin[c + d*x])/(21*b^3*d) + (2*(b*Sec[c + d*x])^(7/2)*Sin[c + d*x])/(7*b^5*d)}
{Sec[c + d*x]^5/(b*Sec[c + d*x])^(3/2), x, 5, -((6*EllipticE[(1/2)*(c + d*x), 2])/(5*b*d*Sqrt[Cos[c + d*x]]*Sqrt[b*Sec[c + d*x]])) + (6*Sqrt[b*Sec[c + d*x]]*Sin[c + d*x])/(5*b^2*d) + (2*(b*Sec[c + d*x])^(5/2)*Sin[c + d*x])/(5*b^4*d)}
{Sec[c + d*x]^4/(b*Sec[c + d*x])^(3/2), x, 4, (2*Sqrt[Cos[c + d*x]]*EllipticF[(1/2)*(c + d*x), 2]*Sqrt[b*Sec[c + d*x]])/(3*b^2*d) + (2*(b*Sec[c + d*x])^(3/2)*Sin[c + d*x])/(3*b^3*d)}
{Sec[c + d*x]^3/(b*Sec[c + d*x])^(3/2), x, 4, -((2*EllipticE[(1/2)*(c + d*x), 2])/(b*d*Sqrt[Cos[c + d*x]]*Sqrt[b*Sec[c + d*x]])) + (2*Sqrt[b*Sec[c + d*x]]*Sin[c + d*x])/(b^2*d)}
{Sec[c + d*x]^2/(b*Sec[c + d*x])^(3/2), x, 3, (2*Sqrt[Cos[c + d*x]]*EllipticF[(c + d*x)/2, 2]*Sqrt[b*Sec[c + d*x]])/(b^2*d)}
{Sec[c + d*x]^1/(b*Sec[c + d*x])^(3/2), x, 3, (2*EllipticE[(c + d*x)/2, 2])/(b*d*Sqrt[Cos[c + d*x]]*Sqrt[b*Sec[c + d*x]])}
{Sec[c + d*x]^0/(b*Sec[c + d*x])^(3/2), x, 3, (2*Sqrt[Cos[c + d*x]]*EllipticF[(1/2)*(c + d*x), 2]*Sqrt[b*Sec[c + d*x]])/(3*b^2*d) + (2*Sin[c + d*x])/(3*b*d*Sqrt[b*Sec[c + d*x]])}
{Cos[c + d*x]^1/(b*Sec[c + d*x])^(3/2), x, 4, (6*EllipticE[(1/2)*(c + d*x), 2])/(5*b*d*Sqrt[Cos[c + d*x]]*Sqrt[b*Sec[c + d*x]]) + (2*Sin[c + d*x])/(5*d*(b*Sec[c + d*x])^(3/2))}
{Cos[c + d*x]^2/(b*Sec[c + d*x])^(3/2), x, 5, (10*Sqrt[Cos[c + d*x]]*EllipticF[(1/2)*(c + d*x), 2]*Sqrt[b*Sec[c + d*x]])/(21*b^2*d) + (2*b*Sin[c + d*x])/(7*d*(b*Sec[c + d*x])^(5/2)) + (10*Sin[c + d*x])/(21*b*d*Sqrt[b*Sec[c + d*x]])}
{Cos[c + d*x]^3/(b*Sec[c + d*x])^(3/2), x, 5, (14*EllipticE[(1/2)*(c + d*x), 2])/(15*b*d*Sqrt[Cos[c + d*x]]*Sqrt[b*Sec[c + d*x]]) + (2*b^2*Sin[c + d*x])/(9*d*(b*Sec[c + d*x])^(7/2)) + (14*Sin[c + d*x])/(45*d*(b*Sec[c + d*x])^(3/2))}


{Sec[c + d*x]^7/(b*Sec[c + d*x])^(5/2), x, 5, (10*Sqrt[Cos[c + d*x]]*EllipticF[(1/2)*(c + d*x), 2]*Sqrt[b*Sec[c + d*x]])/(21*b^3*d) + (10*(b*Sec[c + d*x])^(3/2)*Sin[c + d*x])/(21*b^4*d) + (2*(b*Sec[c + d*x])^(7/2)*Sin[c + d*x])/(7*b^6*d)}
{Sec[c + d*x]^6/(b*Sec[c + d*x])^(5/2), x, 5, -((6*EllipticE[(1/2)*(c + d*x), 2])/(5*b^2*d*Sqrt[Cos[c + d*x]]*Sqrt[b*Sec[c + d*x]])) + (6*Sqrt[b*Sec[c + d*x]]*Sin[c + d*x])/(5*b^3*d) + (2*(b*Sec[c + d*x])^(5/2)*Sin[c + d*x])/(5*b^5*d)}
{Sec[c + d*x]^5/(b*Sec[c + d*x])^(5/2), x, 4, (2*Sqrt[Cos[c + d*x]]*EllipticF[(1/2)*(c + d*x), 2]*Sqrt[b*Sec[c + d*x]])/(3*b^3*d) + (2*(b*Sec[c + d*x])^(3/2)*Sin[c + d*x])/(3*b^4*d)}
{Sec[c + d*x]^4/(b*Sec[c + d*x])^(5/2), x, 4, -((2*EllipticE[(1/2)*(c + d*x), 2])/(b^2*d*Sqrt[Cos[c + d*x]]*Sqrt[b*Sec[c + d*x]])) + (2*Sqrt[b*Sec[c + d*x]]*Sin[c + d*x])/(b^3*d)}
{Sec[c + d*x]^3/(b*Sec[c + d*x])^(5/2), x, 3, (2*Sqrt[Cos[c + d*x]]*EllipticF[(c + d*x)/2, 2]*Sqrt[b*Sec[c + d*x]])/(b^3*d)}
{Sec[c + d*x]^2/(b*Sec[c + d*x])^(5/2), x, 3, (2*EllipticE[(c + d*x)/2, 2])/(b^2*d*Sqrt[Cos[c + d*x]]*Sqrt[b*Sec[c + d*x]])}
{Sec[c + d*x]^1/(b*Sec[c + d*x])^(5/2), x, 4, (2*Sqrt[Cos[c + d*x]]*EllipticF[(1/2)*(c + d*x), 2]*Sqrt[b*Sec[c + d*x]])/(3*b^3*d) + (2*Sin[c + d*x])/(3*b^2*d*Sqrt[b*Sec[c + d*x]])}
{Sec[c + d*x]^0/(b*Sec[c + d*x])^(5/2), x, 3, (6*EllipticE[(1/2)*(c + d*x), 2])/(5*b^2*d*Sqrt[Cos[c + d*x]]*Sqrt[b*Sec[c + d*x]]) + (2*Sin[c + d*x])/(5*b*d*(b*Sec[c + d*x])^(3/2))}
{Cos[c + d*x]^1/(b*Sec[c + d*x])^(5/2), x, 5, (10*Sqrt[Cos[c + d*x]]*EllipticF[(1/2)*(c + d*x), 2]*Sqrt[b*Sec[c + d*x]])/(21*b^3*d) + (2*Sin[c + d*x])/(7*d*(b*Sec[c + d*x])^(5/2)) + (10*Sin[c + d*x])/(21*b^2*d*Sqrt[b*Sec[c + d*x]])}
{Cos[c + d*x]^2/(b*Sec[c + d*x])^(5/2), x, 5, (14*EllipticE[(1/2)*(c + d*x), 2])/(15*b^2*d*Sqrt[Cos[c + d*x]]*Sqrt[b*Sec[c + d*x]]) + (2*b*Sin[c + d*x])/(9*d*(b*Sec[c + d*x])^(7/2)) + (14*Sin[c + d*x])/(45*b*d*(b*Sec[c + d*x])^(3/2))}


{(b*Sec[c + d*x])^(-7/2), x, 4, (10*Sqrt[Cos[c + d*x]]*EllipticF[(1/2)*(c + d*x), 2]*Sqrt[b*Sec[c + d*x]])/(21*b^4*d) + (2*Sin[c + d*x])/(7*b*d*(b*Sec[c + d*x])^(5/2)) + (10*Sin[c + d*x])/(21*b^3*d*Sqrt[b*Sec[c + d*x]])}


(* ::Subsection::Closed:: *)
(*Integrands of the form Sec[c+d x]^(m/2) (b Sec[c+d x])^(n/2)*)


(* ::Subsubsection::Closed:: *)
(*n>0*)


{Sqrt[b*Sec[c + d*x]]*Sec[c + d*x]^(9/2), x, 4, (3*ArcTanh[Sin[c + d*x]]*Sqrt[b*Sec[c + d*x]])/(8*d*Sqrt[Sec[c + d*x]]) + (3*Sec[c + d*x]^(3/2)*Sqrt[b*Sec[c + d*x]]*Sin[c + d*x])/(8*d) + (Sec[c + d*x]^(7/2)*Sqrt[b*Sec[c + d*x]]*Sin[c + d*x])/(4*d)}
{Sqrt[b*Sec[c + d*x]]*Sec[c + d*x]^(7/2), x, 3, (Sqrt[Sec[c + d*x]]*Sqrt[b*Sec[c + d*x]]*Sin[c + d*x])/d + (Sec[c + d*x]^(5/2)*Sqrt[b*Sec[c + d*x]]*Sin[c + d*x]^3)/(3*d)}
{Sqrt[b*Sec[c + d*x]]*Sec[c + d*x]^(5/2), x, 3, (ArcTanh[Sin[c + d*x]]*Sqrt[b*Sec[c + d*x]])/(2*d*Sqrt[Sec[c + d*x]]) + (Sec[c + d*x]^(3/2)*Sqrt[b*Sec[c + d*x]]*Sin[c + d*x])/(2*d)}
{Sqrt[b*Sec[c + d*x]]*Sec[c + d*x]^(3/2), x, 2, (Sqrt[Sec[c + d*x]]*Sqrt[b*Sec[c + d*x]]*Sin[c + d*x])/d}
{Sqrt[b*Sec[c + d*x]]*Sec[c + d*x]^(1/2), x, 2, (ArcTanh[Sin[c + d*x]]*Sqrt[b*Sec[c + d*x]])/(d*Sqrt[Sec[c + d*x]])}
{Sqrt[b*Sec[c + d*x]]/Sec[c + d*x]^(1/2), x, 2, (x*Sqrt[b*Sec[c + d*x]])/Sqrt[Sec[c + d*x]]}
{Sqrt[b*Sec[c + d*x]]/Sec[c + d*x]^(3/2), x, 2, (Sqrt[b*Sec[c + d*x]]*Sin[c + d*x])/(d*Sqrt[Sec[c + d*x]])}
{Sqrt[b*Sec[c + d*x]]/Sec[c + d*x]^(5/2), x, 2, (x*Sqrt[b*Sec[c + d*x]])/(2*Sqrt[Sec[c + d*x]]) + (Sqrt[b*Sec[c + d*x]]*Sin[c + d*x])/(2*d*Sec[c + d*x]^(3/2))}
{Sqrt[b*Sec[c + d*x]]/Sec[c + d*x]^(7/2), x, 3, (Sqrt[b*Sec[c + d*x]]*Sin[c + d*x])/(d*Sqrt[Sec[c + d*x]]) - (Sqrt[b*Sec[c + d*x]]*Sin[c + d*x]^3)/(3*d*Sqrt[Sec[c + d*x]])}
{Sqrt[b*Sec[c + d*x]]/Sec[c + d*x]^(9/2), x, 3, (3*x*Sqrt[b*Sec[c + d*x]])/(8*Sqrt[Sec[c + d*x]]) + (Sqrt[b*Sec[c + d*x]]*Sin[c + d*x])/(4*d*Sec[c + d*x]^(7/2)) + (3*Sqrt[b*Sec[c + d*x]]*Sin[c + d*x])/(8*d*Sec[c + d*x]^(3/2))}


{(b*Sec[c + d*x])^(3/2)*Sec[c + d*x]^(7/2), x, 4, (3*b*ArcTanh[Sin[c + d*x]]*Sqrt[b*Sec[c + d*x]])/(8*d*Sqrt[Sec[c + d*x]]) + (3*b*Sec[c + d*x]^(3/2)*Sqrt[b*Sec[c + d*x]]*Sin[c + d*x])/(8*d) + (b*Sec[c + d*x]^(7/2)*Sqrt[b*Sec[c + d*x]]*Sin[c + d*x])/(4*d)}
{(b*Sec[c + d*x])^(3/2)*Sec[c + d*x]^(5/2), x, 3, (b*Sqrt[Sec[c + d*x]]*Sqrt[b*Sec[c + d*x]]*Sin[c + d*x])/d + (b*Sec[c + d*x]^(5/2)*Sqrt[b*Sec[c + d*x]]*Sin[c + d*x]^3)/(3*d)}
{(b*Sec[c + d*x])^(3/2)*Sec[c + d*x]^(3/2), x, 3, (b*ArcTanh[Sin[c + d*x]]*Sqrt[b*Sec[c + d*x]])/(2*d*Sqrt[Sec[c + d*x]]) + (b*Sec[c + d*x]^(3/2)*Sqrt[b*Sec[c + d*x]]*Sin[c + d*x])/(2*d)}
{(b*Sec[c + d*x])^(3/2)*Sec[c + d*x]^(1/2), x, 2, (b*Sqrt[Sec[c + d*x]]*Sqrt[b*Sec[c + d*x]]*Sin[c + d*x])/d}
{(b*Sec[c + d*x])^(3/2)/Sec[c + d*x]^(1/2), x, 2, (b*ArcTanh[Sin[c + d*x]]*Sqrt[b*Sec[c + d*x]])/(d*Sqrt[Sec[c + d*x]])}
{(b*Sec[c + d*x])^(3/2)/Sec[c + d*x]^(3/2), x, 2, (b*x*Sqrt[b*Sec[c + d*x]])/Sqrt[Sec[c + d*x]]}
{(b*Sec[c + d*x])^(3/2)/Sec[c + d*x]^(5/2), x, 2, (b*Sqrt[b*Sec[c + d*x]]*Sin[c + d*x])/(d*Sqrt[Sec[c + d*x]])}
{(b*Sec[c + d*x])^(3/2)/Sec[c + d*x]^(7/2), x, 2, (b*x*Sqrt[b*Sec[c + d*x]])/(2*Sqrt[Sec[c + d*x]]) + (b*Sqrt[b*Sec[c + d*x]]*Sin[c + d*x])/(2*d*Sec[c + d*x]^(3/2))}
{(b*Sec[c + d*x])^(3/2)/Sec[c + d*x]^(9/2), x, 3, (b*Sqrt[b*Sec[c + d*x]]*Sin[c + d*x])/(d*Sqrt[Sec[c + d*x]]) - (b*Sqrt[b*Sec[c + d*x]]*Sin[c + d*x]^3)/(3*d*Sqrt[Sec[c + d*x]])}
{(b*Sec[c + d*x])^(3/2)/Sec[c + d*x]^(11/2), x, 3, (3*b*x*Sqrt[b*Sec[c + d*x]])/(8*Sqrt[Sec[c + d*x]]) + (b*Sqrt[b*Sec[c + d*x]]*Sin[c + d*x])/(4*d*Sec[c + d*x]^(7/2)) + (3*b*Sqrt[b*Sec[c + d*x]]*Sin[c + d*x])/(8*d*Sec[c + d*x]^(3/2))}


{(b*Sec[c + d*x])^(5/2)*Sec[c + d*x]^(7/2), x, 3, (b^2*Sqrt[Sec[c + d*x]]*Sqrt[b*Sec[c + d*x]]*Sin[c + d*x])/d + (2*b^2*Sec[c + d*x]^(5/2)*Sqrt[b*Sec[c + d*x]]*Sin[c + d*x]^3)/(3*d) + (b^2*Sec[c + d*x]^(9/2)*Sqrt[b*Sec[c + d*x]]*Sin[c + d*x]^5)/(5*d)}
{(b*Sec[c + d*x])^(5/2)*Sec[c + d*x]^(3/2), x, 3, (b^2*Sqrt[Sec[c + d*x]]*Sqrt[b*Sec[c + d*x]]*Sin[c + d*x])/d + (b^2*Sec[c + d*x]^(5/2)*Sqrt[b*Sec[c + d*x]]*Sin[c + d*x]^3)/(3*d)}
{(b*Sec[c + d*x])^(5/2)*Sec[c + d*x]^(1/2), x, 3, (b^2*ArcTanh[Sin[c + d*x]]*Sqrt[b*Sec[c + d*x]])/(2*d*Sqrt[Sec[c + d*x]]) + (b^2*Sec[c + d*x]^(3/2)*Sqrt[b*Sec[c + d*x]]*Sin[c + d*x])/(2*d)}
{(b*Sec[c + d*x])^(5/2)/Sec[c + d*x]^(1/2), x, 2, (b^2*Sqrt[Sec[c + d*x]]*Sqrt[b*Sec[c + d*x]]*Sin[c + d*x])/d}
{(b*Sec[c + d*x])^(5/2)/Sec[c + d*x]^(3/2), x, 2, (b^2*ArcTanh[Sin[c + d*x]]*Sqrt[b*Sec[c + d*x]])/(d*Sqrt[Sec[c + d*x]])}
{(b*Sec[c + d*x])^(5/2)/Sec[c + d*x]^(5/2), x, 2, (b^2*x*Sqrt[b*Sec[c + d*x]])/Sqrt[Sec[c + d*x]]}
{(b*Sec[c + d*x])^(5/2)/Sec[c + d*x]^(7/2), x, 2, (b^2*Sqrt[b*Sec[c + d*x]]*Sin[c + d*x])/(d*Sqrt[Sec[c + d*x]])}
{(b*Sec[c + d*x])^(5/2)/Sec[c + d*x]^(9/2), x, 2, (b^2*x*Sqrt[b*Sec[c + d*x]])/(2*Sqrt[Sec[c + d*x]]) + (b^2*Sqrt[b*Sec[c + d*x]]*Sin[c + d*x])/(2*d*Sec[c + d*x]^(3/2))}
{(b*Sec[c + d*x])^(5/2)/Sec[c + d*x]^(11/2), x, 3, (b^2*Sqrt[b*Sec[c + d*x]]*Sin[c + d*x])/(d*Sqrt[Sec[c + d*x]]) - (b^2*Sqrt[b*Sec[c + d*x]]*Sin[c + d*x]^3)/(3*d*Sqrt[Sec[c + d*x]])}


(* ::Subsubsection::Closed:: *)
(*n<0*)


{Sec[c + d*x]^(7/2)/Sqrt[b*Sec[c + d*x]], x, 3, (ArcTanh[Sin[c + d*x]]*Sqrt[Sec[c + d*x]])/(2*d*Sqrt[b*Sec[c + d*x]]) + (Sec[c + d*x]^(5/2)*Sin[c + d*x])/(2*d*Sqrt[b*Sec[c + d*x]])}
{Sec[c + d*x]^(5/2)/Sqrt[b*Sec[c + d*x]], x, 2, (Sec[c + d*x]^(3/2)*Sin[c + d*x])/(d*Sqrt[b*Sec[c + d*x]])}
{Sec[c + d*x]^(3/2)/Sqrt[b*Sec[c + d*x]], x, 2, (ArcTanh[Sin[c + d*x]]*Sqrt[Sec[c + d*x]])/(d*Sqrt[b*Sec[c + d*x]])}
{Sec[c + d*x]^(1/2)/Sqrt[b*Sec[c + d*x]], x, 2, (x*Sqrt[Sec[c + d*x]])/Sqrt[b*Sec[c + d*x]]}
{1/(Sec[c + d*x]^(1/2)*Sqrt[b*Sec[c + d*x]]), x, 2, (Sqrt[Sec[c + d*x]]*Sin[c + d*x])/(d*Sqrt[b*Sec[c + d*x]])}
{1/(Sec[c + d*x]^(3/2)*Sqrt[b*Sec[c + d*x]]), x, 2, (x*Sqrt[Sec[c + d*x]])/(2*Sqrt[b*Sec[c + d*x]]) + Sin[c + d*x]/(2*d*Sqrt[Sec[c + d*x]]*Sqrt[b*Sec[c + d*x]])}
{1/(Sec[c + d*x]^(5/2)*Sqrt[b*Sec[c + d*x]]), x, 3, (Sqrt[Sec[c + d*x]]*Sin[c + d*x])/(d*Sqrt[b*Sec[c + d*x]]) - (Sqrt[Sec[c + d*x]]*Sin[c + d*x]^3)/(3*d*Sqrt[b*Sec[c + d*x]])}


{Sec[c + d*x]^(9/2)/(b*Sec[c + d*x])^(3/2), x, 3, (ArcTanh[Sin[c + d*x]]*Sqrt[Sec[c + d*x]])/(2*b*d*Sqrt[b*Sec[c + d*x]]) + (Sec[c + d*x]^(5/2)*Sin[c + d*x])/(2*b*d*Sqrt[b*Sec[c + d*x]])}
{Sec[c + d*x]^(7/2)/(b*Sec[c + d*x])^(3/2), x, 2, (Sec[c + d*x]^(3/2)*Sin[c + d*x])/(b*d*Sqrt[b*Sec[c + d*x]])}
{Sec[c + d*x]^(5/2)/(b*Sec[c + d*x])^(3/2), x, 2, (ArcTanh[Sin[c + d*x]]*Sqrt[Sec[c + d*x]])/(b*d*Sqrt[b*Sec[c + d*x]])}
{Sec[c + d*x]^(3/2)/(b*Sec[c + d*x])^(3/2), x, 2, (x*Sqrt[Sec[c + d*x]])/(b*Sqrt[b*Sec[c + d*x]])}
{Sec[c + d*x]^(1/2)/(b*Sec[c + d*x])^(3/2), x, 2, (Sqrt[Sec[c + d*x]]*Sin[c + d*x])/(b*d*Sqrt[b*Sec[c + d*x]])}
{1/(Sec[c + d*x]^(1/2)*(b*Sec[c + d*x])^(3/2)), x, 2, (x*Sqrt[Sec[c + d*x]])/(2*b*Sqrt[b*Sec[c + d*x]]) + Sin[c + d*x]/(2*b*d*Sqrt[Sec[c + d*x]]*Sqrt[b*Sec[c + d*x]])}
{1/(Sec[c + d*x]^(3/2)*(b*Sec[c + d*x])^(3/2)), x, 3, (Sqrt[Sec[c + d*x]]*Sin[c + d*x])/(b*d*Sqrt[b*Sec[c + d*x]]) - (Sqrt[Sec[c + d*x]]*Sin[c + d*x]^3)/(3*b*d*Sqrt[b*Sec[c + d*x]])}
{1/(Sec[c + d*x]^(5/2)*(b*Sec[c + d*x])^(3/2)), x, 3, (3*x*Sqrt[Sec[c + d*x]])/(8*b*Sqrt[b*Sec[c + d*x]]) + Sin[c + d*x]/(4*b*d*Sec[c + d*x]^(5/2)*Sqrt[b*Sec[c + d*x]]) + (3*Sin[c + d*x])/(8*b*d*Sqrt[Sec[c + d*x]]*Sqrt[b*Sec[c + d*x]])}


{Sec[c + d*x]^(11/2)/(b*Sec[c + d*x])^(5/2), x, 3, (ArcTanh[Sin[c + d*x]]*Sqrt[Sec[c + d*x]])/(2*b^2*d*Sqrt[b*Sec[c + d*x]]) + (Sec[c + d*x]^(5/2)*Sin[c + d*x])/(2*b^2*d*Sqrt[b*Sec[c + d*x]])}
{Sec[c + d*x]^(9/2)/(b*Sec[c + d*x])^(5/2), x, 2, (Sec[c + d*x]^(3/2)*Sin[c + d*x])/(b^2*d*Sqrt[b*Sec[c + d*x]])}
{Sec[c + d*x]^(7/2)/(b*Sec[c + d*x])^(5/2), x, 2, (ArcTanh[Sin[c + d*x]]*Sqrt[Sec[c + d*x]])/(b^2*d*Sqrt[b*Sec[c + d*x]])}
{Sec[c + d*x]^(5/2)/(b*Sec[c + d*x])^(5/2), x, 2, (x*Sqrt[Sec[c + d*x]])/(b^2*Sqrt[b*Sec[c + d*x]])}
{Sec[c + d*x]^(3/2)/(b*Sec[c + d*x])^(5/2), x, 2, (Sqrt[Sec[c + d*x]]*Sin[c + d*x])/(b^2*d*Sqrt[b*Sec[c + d*x]])}
{Sec[c + d*x]^(1/2)/(b*Sec[c + d*x])^(5/2), x, 2, (x*Sqrt[Sec[c + d*x]])/(2*b^2*Sqrt[b*Sec[c + d*x]]) + Sin[c + d*x]/(2*b^2*d*Sqrt[Sec[c + d*x]]*Sqrt[b*Sec[c + d*x]])}
{1/(Sec[c + d*x]^(1/2)*(b*Sec[c + d*x])^(5/2)), x, 3, (Sqrt[Sec[c + d*x]]*Sin[c + d*x])/(b^2*d*Sqrt[b*Sec[c + d*x]]) - (Sqrt[Sec[c + d*x]]*Sin[c + d*x]^3)/(3*b^2*d*Sqrt[b*Sec[c + d*x]])}
{1/(Sec[c + d*x]^(3/2)*(b*Sec[c + d*x])^(5/2)), x, 3, (3*x*Sqrt[Sec[c + d*x]])/(8*b^2*Sqrt[b*Sec[c + d*x]]) + Sin[c + d*x]/(4*b^2*d*Sec[c + d*x]^(5/2)*Sqrt[b*Sec[c + d*x]]) + (3*Sin[c + d*x])/(8*b^2*d*Sqrt[Sec[c + d*x]]*Sqrt[b*Sec[c + d*x]])}


(* ::Subsection::Closed:: *)
(*Integrands of the form Sec[c+d x]^m (b Sec[c+d x])^(n/3)*)


(* ::Subsubsection::Closed:: *)
(*n>0*)


{Sec[c + d*x]^m*(b*Sec[c + d*x])^(1/3), x, 3, ((Cos[c + d*x]^2)^((-2 + 3*m)/6)*Hypergeometric2F1[1/2, (4 + 3*m)/6, 3/2, Sin[c + d*x]^2]*Sec[c + d*x]^(-1 + m)*(b*Sec[c + d*x])^(1/3)*Sin[c + d*x])/d}

{Sec[c + d*x]^2*(b*Sec[c + d*x])^(1/3), x, 4, (b*Hypergeometric2F1[1/2, 2/3, 3/2, Sin[c + d*x]^2]*Sin[c + d*x])/(4*d*(Cos[c + d*x]^2)^(1/3)*(b*Sec[c + d*x])^(2/3)) + (3*(b*Sec[c + d*x])^(4/3)*Sin[c + d*x])/(4*b*d)}
{Sec[c + d*x]*(b*Sec[c + d*x])^(1/3), x, 4, (3*(b*Sec[c + d*x])^(1/3)*Sin[c + d*x])/d - (2*(Cos[c + d*x]^2)^(1/6)*Hypergeometric2F1[1/6, 1/2, 3/2, Sin[c + d*x]^2]*(b*Sec[c + d*x])^(1/3)*Sin[c + d*x])/d}
{(b*Sec[c + d*x])^(1/3), x, 2, (b*Hypergeometric2F1[1/2, 2/3, 3/2, Sin[c + d*x]^2]*Sin[c + d*x])/(d*(Cos[c + d*x]^2)^(1/3)*(b*Sec[c + d*x])^(2/3))}
{Cos[c + d*x]*(b*Sec[c + d*x])^(1/3), x, 3, ((Cos[c + d*x]^2)^(1/6)*Hypergeometric2F1[1/6, 1/2, 3/2, Sin[c + d*x]^2]*(b*Sec[c + d*x])^(1/3)*Sin[c + d*x])/d}
{Cos[c + d*x]^2*(b*Sec[c + d*x])^(1/3), x, 4, (3*b*Sin[c + d*x])/(5*d*(b*Sec[c + d*x])^(2/3)) + (2*b*Hypergeometric2F1[1/2, 2/3, 3/2, Sin[c + d*x]^2]*Sin[c + d*x])/(5*d*(Cos[c + d*x]^2)^(1/3)*(b*Sec[c + d*x])^(2/3))}
{Cos[c + d*x]^3*(b*Sec[c + d*x])^(1/3), x, 4, (3*b^2*Sin[c + d*x])/(8*d*(b*Sec[c + d*x])^(5/3)) + (5*(Cos[c + d*x]^2)^(1/6)*Hypergeometric2F1[1/6, 1/2, 3/2, Sin[c + d*x]^2]*(b*Sec[c + d*x])^(1/3)*Sin[c + d*x])/(8*d)}


{Sec[c + d*x]^m*(b*Sec[c + d*x])^(2/3), x, 3, ((Cos[c + d*x]^2)^((-1 + 3*m)/6)*Hypergeometric2F1[1/2, (5 + 3*m)/6, 3/2, Sin[c + d*x]^2]*Sec[c + d*x]^(-1 + m)*(b*Sec[c + d*x])^(2/3)*Sin[c + d*x])/d}

{Sec[c + d*x]^2*(b*Sec[c + d*x])^(2/3), x, 4, (2*b*Hypergeometric2F1[1/2, 5/6, 3/2, Sin[c + d*x]^2]*Sin[c + d*x])/(5*d*(Cos[c + d*x]^2)^(1/6)*(b*Sec[c + d*x])^(1/3)) + (3*(b*Sec[c + d*x])^(5/3)*Sin[c + d*x])/(5*b*d)}
{Sec[c + d*x]*(b*Sec[c + d*x])^(2/3), x, 4, (3*(b*Sec[c + d*x])^(2/3)*Sin[c + d*x])/(2*d) - ((Cos[c + d*x]^2)^(1/3)*Hypergeometric2F1[1/3, 1/2, 3/2, Sin[c + d*x]^2]*(b*Sec[c + d*x])^(2/3)*Sin[c + d*x])/(2*d)}
{(b*Sec[c + d*x])^(2/3), x, 2, (b*Hypergeometric2F1[1/2, 5/6, 3/2, Sin[c + d*x]^2]*Sin[c + d*x])/(d*(Cos[c + d*x]^2)^(1/6)*(b*Sec[c + d*x])^(1/3))}
{Cos[c + d*x]*(b*Sec[c + d*x])^(2/3), x, 3, ((Cos[c + d*x]^2)^(1/3)*Hypergeometric2F1[1/3, 1/2, 3/2, Sin[c + d*x]^2]*(b*Sec[c + d*x])^(2/3)*Sin[c + d*x])/d}
{Cos[c + d*x]^2*(b*Sec[c + d*x])^(2/3), x, 4, (3*b*Sin[c + d*x])/(4*d*(b*Sec[c + d*x])^(1/3)) + (b*Hypergeometric2F1[1/2, 5/6, 3/2, Sin[c + d*x]^2]*Sin[c + d*x])/(4*d*(Cos[c + d*x]^2)^(1/6)*(b*Sec[c + d*x])^(1/3))}
{Cos[c + d*x]^3*(b*Sec[c + d*x])^(2/3), x, 4, (3*b^2*Sin[c + d*x])/(7*d*(b*Sec[c + d*x])^(4/3)) + (4*(Cos[c + d*x]^2)^(1/3)*Hypergeometric2F1[1/3, 1/2, 3/2, Sin[c + d*x]^2]*(b*Sec[c + d*x])^(2/3)*Sin[c + d*x])/(7*d)}


{Sec[c + d*x]^m*(b*Sec[c + d*x])^(4/3), x, 3, ((Cos[c + d*x]^2)^((1 + 3*m)/6)*Hypergeometric2F1[1/2, (7 + 3*m)/6, 3/2, Sin[c + d*x]^2]*Sec[c + d*x]^(-1 + m)*(b*Sec[c + d*x])^(4/3)*Sin[c + d*x])/d}

{Sec[c + d*x]^2*(b*Sec[c + d*x])^(4/3), x, 5, (12*b*(b*Sec[c + d*x])^(1/3)*Sin[c + d*x])/(7*d) - (8*b*(Cos[c + d*x]^2)^(1/6)*Hypergeometric2F1[1/6, 1/2, 3/2, Sin[c + d*x]^2]*(b*Sec[c + d*x])^(1/3)*Sin[c + d*x])/(7*d) + (3*(b*Sec[c + d*x])^(7/3)*Sin[c + d*x])/(7*b*d)}
{Sec[c + d*x]*(b*Sec[c + d*x])^(4/3), x, 4, (b^2*Hypergeometric2F1[1/2, 2/3, 3/2, Sin[c + d*x]^2]*Sin[c + d*x])/(4*d*(Cos[c + d*x]^2)^(1/3)*(b*Sec[c + d*x])^(2/3)) + (3*(b*Sec[c + d*x])^(4/3)*Sin[c + d*x])/(4*d)}
{(b*Sec[c + d*x])^(4/3), x, 3, (3*b*(b*Sec[c + d*x])^(1/3)*Sin[c + d*x])/d - (2*b*(Cos[c + d*x]^2)^(1/6)*Hypergeometric2F1[1/6, 1/2, 3/2, Sin[c + d*x]^2]*(b*Sec[c + d*x])^(1/3)*Sin[c + d*x])/d}
{Cos[c + d*x]*(b*Sec[c + d*x])^(4/3), x, 3, (b^2*Hypergeometric2F1[1/2, 2/3, 3/2, Sin[c + d*x]^2]*Sin[c + d*x])/(d*(Cos[c + d*x]^2)^(1/3)*(b*Sec[c + d*x])^(2/3))}
{Cos[c + d*x]^2*(b*Sec[c + d*x])^(4/3), x, 3, (b*(Cos[c + d*x]^2)^(1/6)*Hypergeometric2F1[1/6, 1/2, 3/2, Sin[c + d*x]^2]*(b*Sec[c + d*x])^(1/3)*Sin[c + d*x])/d}
{Cos[c + d*x]^3*(b*Sec[c + d*x])^(4/3), x, 4, (3*b^2*Sin[c + d*x])/(5*d*(b*Sec[c + d*x])^(2/3)) + (2*b^2*Hypergeometric2F1[1/2, 2/3, 3/2, Sin[c + d*x]^2]*Sin[c + d*x])/(5*d*(Cos[c + d*x]^2)^(1/3)*(b*Sec[c + d*x])^(2/3))}


(* ::Subsubsection::Closed:: *)
(*n<0*)


{Sec[c + d*x]^m/(b*Sec[c + d*x])^(1/3), x, 3, ((Cos[c + d*x]^2)^((2 + 3*m)/6)*Hypergeometric2F1[1/2, (2 + 3*m)/6, 3/2, Sin[c + d*x]^2]*Sec[c + d*x]^(1 + m)*Sin[c + d*x])/(d*(b*Sec[c + d*x])^(1/3))}

{Sec[c + d*x]^2/(b*Sec[c + d*x])^(1/3), x, 4, (3*(b*Sec[c + d*x])^(2/3)*Sin[c + d*x])/(2*b*d) - ((Cos[c + d*x]^2)^(1/3)*Hypergeometric2F1[1/3, 1/2, 3/2, Sin[c + d*x]^2]*(b*Sec[c + d*x])^(2/3)*Sin[c + d*x])/(2*b*d)}
{Sec[c + d*x]/(b*Sec[c + d*x])^(1/3), x, 3, (Hypergeometric2F1[1/2, 5/6, 3/2, Sin[c + d*x]^2]*Sin[c + d*x])/(d*(Cos[c + d*x]^2)^(1/6)*(b*Sec[c + d*x])^(1/3))}
{(b*Sec[c + d*x])^(-1/3), x, 2, ((Cos[c + d*x]^2)^(1/3)*Hypergeometric2F1[1/3, 1/2, 3/2, Sin[c + d*x]^2]*(b*Sec[c + d*x])^(2/3)*Sin[c + d*x])/(b*d)}
{Cos[c + d*x]/(b*Sec[c + d*x])^(1/3), x, 4, (3*Sin[c + d*x])/(4*d*(b*Sec[c + d*x])^(1/3)) + (Hypergeometric2F1[1/2, 5/6, 3/2, Sin[c + d*x]^2]*Sin[c + d*x])/(4*d*(Cos[c + d*x]^2)^(1/6)*(b*Sec[c + d*x])^(1/3))}
{Cos[c + d*x]^2/(b*Sec[c + d*x])^(1/3), x, 4, (3*b*Sin[c + d*x])/(7*d*(b*Sec[c + d*x])^(4/3)) + (4*(Cos[c + d*x]^2)^(1/3)*Hypergeometric2F1[1/3, 1/2, 3/2, Sin[c + d*x]^2]*(b*Sec[c + d*x])^(2/3)*Sin[c + d*x])/(7*b*d)}
{Cos[c + d*x]^3/(b*Sec[c + d*x])^(1/3), x, 5, (3*b^2*Sin[c + d*x])/(10*d*(b*Sec[c + d*x])^(7/3)) + (21*Sin[c + d*x])/(40*d*(b*Sec[c + d*x])^(1/3)) + (7*Hypergeometric2F1[1/2, 5/6, 3/2, Sin[c + d*x]^2]*Sin[c + d*x])/(40*d*(Cos[c + d*x]^2)^(1/6)*(b*Sec[c + d*x])^(1/3))}


{Sec[c + d*x]^m/(b*Sec[c + d*x])^(2/3), x, 3, ((Cos[c + d*x]^2)^((1 + 3*m)/6)*Hypergeometric2F1[1/2, (1 + 3*m)/6, 3/2, Sin[c + d*x]^2]*Sec[c + d*x]^(1 + m)*Sin[c + d*x])/(d*(b*Sec[c + d*x])^(2/3))}

{Sec[c + d*x]^3/(b*Sec[c + d*x])^(2/3), x, 4, (Hypergeometric2F1[1/2, 2/3, 3/2, Sin[c + d*x]^2]*Sin[c + d*x])/(4*d*(Cos[c + d*x]^2)^(1/3)*(b*Sec[c + d*x])^(2/3)) + (3*(b*Sec[c + d*x])^(4/3)*Sin[c + d*x])/(4*b^2*d)}
{Sec[c + d*x]^2/(b*Sec[c + d*x])^(2/3), x, 4, (3*(b*Sec[c + d*x])^(1/3)*Sin[c + d*x])/(b*d) - (2*(Cos[c + d*x]^2)^(1/6)*Hypergeometric2F1[1/6, 1/2, 3/2, Sin[c + d*x]^2]*(b*Sec[c + d*x])^(1/3)*Sin[c + d*x])/(b*d)}
{Sec[c + d*x]/(b*Sec[c + d*x])^(2/3), x, 3, (Hypergeometric2F1[1/2, 2/3, 3/2, Sin[c + d*x]^2]*Sin[c + d*x])/(d*(Cos[c + d*x]^2)^(1/3)*(b*Sec[c + d*x])^(2/3))}
{(b*Sec[c + d*x])^(-2/3), x, 2, ((Cos[c + d*x]^2)^(1/6)*Hypergeometric2F1[1/6, 1/2, 3/2, Sin[c + d*x]^2]*(b*Sec[c + d*x])^(1/3)*Sin[c + d*x])/(b*d)}
{Cos[c + d*x]/(b*Sec[c + d*x])^(2/3), x, 4, (3*Sin[c + d*x])/(5*d*(b*Sec[c + d*x])^(2/3)) + (2*Hypergeometric2F1[1/2, 2/3, 3/2, Sin[c + d*x]^2]*Sin[c + d*x])/(5*d*(Cos[c + d*x]^2)^(1/3)*(b*Sec[c + d*x])^(2/3))}
{Cos[c + d*x]^2/(b*Sec[c + d*x])^(2/3), x, 4, (3*b*Sin[c + d*x])/(8*d*(b*Sec[c + d*x])^(5/3)) + (5*(Cos[c + d*x]^2)^(1/6)*Hypergeometric2F1[1/6, 1/2, 3/2, Sin[c + d*x]^2]*(b*Sec[c + d*x])^(1/3)*Sin[c + d*x])/(8*b*d)}
{Cos[c + d*x]^3/(b*Sec[c + d*x])^(2/3), x, 5, (3*b^2*Sin[c + d*x])/(11*d*(b*Sec[c + d*x])^(8/3)) + (24*Sin[c + d*x])/(55*d*(b*Sec[c + d*x])^(2/3)) + (16*Hypergeometric2F1[1/2, 2/3, 3/2, Sin[c + d*x]^2]*Sin[c + d*x])/(55*d*(Cos[c + d*x]^2)^(1/3)*(b*Sec[c + d*x])^(2/3))}


{Sec[c + d*x]^m/(b*Sec[c + d*x])^(4/3), x, 3, ((Cos[c + d*x]^2)^((-7 + 3*m)/6)*Hypergeometric2F1[1/2, (-1 + 3*m)/6, 3/2, Sin[c + d*x]^2]*Sec[c + d*x]^(-1 + m)*Sin[c + d*x])/(d*(b*Sec[c + d*x])^(4/3))}

{Sec[c + d*x]^4/(b*Sec[c + d*x])^(4/3), x, 4, (2*Hypergeometric2F1[1/2, 5/6, 3/2, Sin[c + d*x]^2]*Sin[c + d*x])/(5*b*d*(Cos[c + d*x]^2)^(1/6)*(b*Sec[c + d*x])^(1/3)) + (3*(b*Sec[c + d*x])^(5/3)*Sin[c + d*x])/(5*b^3*d)}
{Sec[c + d*x]^3/(b*Sec[c + d*x])^(4/3), x, 4, (3*(b*Sec[c + d*x])^(2/3)*Sin[c + d*x])/(2*b^2*d) - ((Cos[c + d*x]^2)^(1/3)*Hypergeometric2F1[1/3, 1/2, 3/2, Sin[c + d*x]^2]*(b*Sec[c + d*x])^(2/3)*Sin[c + d*x])/(2*b^2*d)}
{Sec[c + d*x]^2/(b*Sec[c + d*x])^(4/3), x, 3, (Hypergeometric2F1[1/2, 5/6, 3/2, Sin[c + d*x]^2]*Sin[c + d*x])/(b*d*(Cos[c + d*x]^2)^(1/6)*(b*Sec[c + d*x])^(1/3))}
{Sec[c + d*x]/(b*Sec[c + d*x])^(4/3), x, 3, ((Cos[c + d*x]^2)^(1/3)*Hypergeometric2F1[1/3, 1/2, 3/2, Sin[c + d*x]^2]*(b*Sec[c + d*x])^(2/3)*Sin[c + d*x])/(b^2*d)}
{(b*Sec[c + d*x])^(-4/3), x, 3, (3*Sin[c + d*x])/(4*b*d*(b*Sec[c + d*x])^(1/3)) + (Hypergeometric2F1[1/2, 5/6, 3/2, Sin[c + d*x]^2]*Sin[c + d*x])/(4*b*d*(Cos[c + d*x]^2)^(1/6)*(b*Sec[c + d*x])^(1/3))}
{Cos[c + d*x]/(b*Sec[c + d*x])^(4/3), x, 4, (3*Sin[c + d*x])/(7*d*(b*Sec[c + d*x])^(4/3)) + (4*(Cos[c + d*x]^2)^(1/3)*Hypergeometric2F1[1/3, 1/2, 3/2, Sin[c + d*x]^2]*(b*Sec[c + d*x])^(2/3)*Sin[c + d*x])/(7*b^2*d)}
{Cos[c + d*x]^2/(b*Sec[c + d*x])^(4/3), x, 5, (3*b*Sin[c + d*x])/(10*d*(b*Sec[c + d*x])^(7/3)) + (21*Sin[c + d*x])/(40*b*d*(b*Sec[c + d*x])^(1/3)) + (7*Hypergeometric2F1[1/2, 5/6, 3/2, Sin[c + d*x]^2]*Sin[c + d*x])/(40*b*d*(Cos[c + d*x]^2)^(1/6)*(b*Sec[c + d*x])^(1/3))}
{Cos[c + d*x]^3/(b*Sec[c + d*x])^(4/3), x, 5, (3*b^2*Sin[c + d*x])/(13*d*(b*Sec[c + d*x])^(10/3)) + (30*Sin[c + d*x])/(91*d*(b*Sec[c + d*x])^(4/3)) + (40*(Cos[c + d*x]^2)^(1/3)*Hypergeometric2F1[1/3, 1/2, 3/2, Sin[c + d*x]^2]*(b*Sec[c + d*x])^(2/3)*Sin[c + d*x])/(91*b^2*d)}


(* ::Subsection::Closed:: *)
(*Integrands of the form Sec[c+d x]^m (b Sec[c+d x])^n when n symbolic*)


{Sec[c + d*x]^m*(b*Sec[c + d*x])^n, x, 3, ((Cos[c + d*x]^2)^((-1 + m + n)/2)*Hypergeometric2F1[1/2, (1 + m + n)/2, 3/2, Sin[c + d*x]^2]*Sec[c + d*x]^(-1 + m)*(b*Sec[c + d*x])^n*Sin[c + d*x])/d}

{Sec[c + d*x]^2*(b*Sec[c + d*x])^n, x, 3, ((Cos[c + d*x]^2)^((1 + n)/2)*Hypergeometric2F1[1/2, (3 + n)/2, 3/2, Sin[c + d*x]^2]*(b*Sec[c + d*x])^(1 + n)*Sin[c + d*x])/(b*d)}
{Sec[c + d*x]*(b*Sec[c + d*x])^n, x, 3, ((Cos[c + d*x]^2)^(n/2)*Hypergeometric2F1[1/2, (2 + n)/2, 3/2, Sin[c + d*x]^2]*(b*Sec[c + d*x])^n*Sin[c + d*x])/d}
{(b*Sec[c + d*x])^n, x, 2, (b*(Cos[c + d*x]^2)^((1/2)*(-1 + n))*Hypergeometric2F1[1/2, (1 + n)/2, 3/2, Sin[c + d*x]^2]*(b*Sec[c + d*x])^(-1 + n)*Sin[c + d*x])/d}
{Cos[c + d*x]*(b*Sec[c + d*x])^n, x, 3, (b^2*(Cos[c + d*x]^2)^((1/2)*(-2 + n))*Hypergeometric2F1[1/2, n/2, 3/2, Sin[c + d*x]^2]*(b*Sec[c + d*x])^(-2 + n)*Sin[c + d*x])/d}
{Cos[c + d*x]^2*(b*Sec[c + d*x])^n, x, 3, (b^3*(Cos[c + d*x]^2)^((1/2)*(-3 + n))*Hypergeometric2F1[1/2, (1/2)*(-1 + n), 3/2, Sin[c + d*x]^2]*(b*Sec[c + d*x])^(-3 + n)*Sin[c + d*x])/d}
{Cos[c + d*x]^3*(b*Sec[c + d*x])^n, x, 3, (b^4*(Cos[c + d*x]^2)^((1/2)*(-4 + n))*Hypergeometric2F1[1/2, (1/2)*(-2 + n), 3/2, Sin[c + d*x]^2]*(b*Sec[c + d*x])^(-4 + n)*Sin[c + d*x])/d}
{Cos[c + d*x]^4*(b*Sec[c + d*x])^n, x, 3, (b^5*(Cos[c + d*x]^2)^((1/2)*(-5 + n))*Hypergeometric2F1[1/2, (1/2)*(-3 + n), 3/2, Sin[c + d*x]^2]*(b*Sec[c + d*x])^(-5 + n)*Sin[c + d*x])/d}


{Sec[c + d*x]^(5/2)*(b*Sec[c + d*x])^n, x, 3, ((Cos[c + d*x]^2)^((3 + 2*n)/4)*Hypergeometric2F1[1/2, (7 + 2*n)/4, 3/2, Sin[c + d*x]^2]*Sec[c + d*x]^(3/2)*(b*Sec[c + d*x])^n*Sin[c + d*x])/d}
{Sec[c + d*x]^(3/2)*(b*Sec[c + d*x])^n, x, 3, ((Cos[c + d*x]^2)^((1 + 2*n)/4)*Hypergeometric2F1[1/2, (5 + 2*n)/4, 3/2, Sin[c + d*x]^2]*Sqrt[Sec[c + d*x]]*(b*Sec[c + d*x])^n*Sin[c + d*x])/d}
{Sqrt[Sec[c + d*x]]*(b*Sec[c + d*x])^n, x, 3, ((Cos[c + d*x]^2)^((-1 + 2*n)/4)*Hypergeometric2F1[1/2, (3 + 2*n)/4, 3/2, Sin[c + d*x]^2]*(b*Sec[c + d*x])^n*Sin[c + d*x])/(d*Sqrt[Sec[c + d*x]])}
{(b*Sec[c + d*x])^n/Sqrt[Sec[c + d*x]], x, 3, ((Cos[c + d*x]^2)^((1 + 2*n)/4)*Hypergeometric2F1[1/2, (1 + 2*n)/4, 3/2, Sin[c + d*x]^2]*Sqrt[Sec[c + d*x]]*(b*Sec[c + d*x])^n*Sin[c + d*x])/d}
{(b*Sec[c + d*x])^n/Sec[c + d*x]^(3/2), x, 3, ((Cos[c + d*x]^2)^((-5 + 2*n)/4)*Hypergeometric2F1[1/2, (-1 + 2*n)/4, 3/2, Sin[c + d*x]^2]*(b*Sec[c + d*x])^n*Sin[c + d*x])/(d*Sec[c + d*x]^(5/2))}
{(b*Sec[c + d*x])^n/Sec[c + d*x]^(5/2), x, 3, ((Cos[c + d*x]^2)^((-7 + 2*n)/4)*Hypergeometric2F1[1/2, (-3 + 2*n)/4, 3/2, Sin[c + d*x]^2]*(b*Sec[c + d*x])^n*Sin[c + d*x])/(d*Sec[c + d*x]^(7/2))}
{(b*Sec[c + d*x])^n/Sec[c + d*x]^(7/2), x, 3, ((Cos[c + d*x]^2)^((-9 + 2*n)/4)*Hypergeometric2F1[1/2, (-5 + 2*n)/4, 3/2, Sin[c + d*x]^2]*(b*Sec[c + d*x])^n*Sin[c + d*x])/(d*Sec[c + d*x]^(9/2))}
{(b*Sec[c + d*x])^n/Sec[c + d*x]^(9/2), x, 3, ((Cos[c + d*x]^2)^((-11 + 2*n)/4)*Hypergeometric2F1[1/2, (-7 + 2*n)/4, 3/2, Sin[c + d*x]^2]*(b*Sec[c + d*x])^n*Sin[c + d*x])/(d*Sec[c + d*x]^(11/2))}


(* ::Section:: *)
(*Sec[c+d x]^m (A+B Sec[c+d x]) (b Sec[c+d x])^(n/2)*)


(* ::Subsection::Closed:: *)
(*Integrands of the form Sec[c+d x]^m (A+B Sec[c+d x]) (b Sec[c+d x])^(n/2)*)


(* ::Subsubsection::Closed:: *)
(*n>0*)


{Sec[c + d*x]^0*(b*Sec[c + d*x])^(5/2)*(A + B*Sec[c + d*x]), x, 8, -((6*b^3*B*EllipticE[(1/2)*(c + d*x), 2])/(5*d*Sqrt[Cos[c + d*x]]*Sqrt[b*Sec[c + d*x]])) + (2*A*b^2*Sqrt[Cos[c + d*x]]*EllipticF[(1/2)*(c + d*x), 2]*Sqrt[b*Sec[c + d*x]])/(3*d) + (6*b^2*B*Sqrt[b*Sec[c + d*x]]*Sin[c + d*x])/(5*d) + (2*A*b*(b*Sec[c + d*x])^(3/2)*Sin[c + d*x])/(3*d) + (2*B*(b*Sec[c + d*x])^(5/2)*Sin[c + d*x])/(5*d)}
{Sec[c + d*x]^0*(b*Sec[c + d*x])^(3/2)*(A + B*Sec[c + d*x]), x, 7, -((2*A*b^2*EllipticE[(1/2)*(c + d*x), 2])/(d*Sqrt[Cos[c + d*x]]*Sqrt[b*Sec[c + d*x]])) + (2*b*B*Sqrt[Cos[c + d*x]]*EllipticF[(1/2)*(c + d*x), 2]*Sqrt[b*Sec[c + d*x]])/(3*d) + (2*A*b*Sqrt[b*Sec[c + d*x]]*Sin[c + d*x])/d + (2*B*(b*Sec[c + d*x])^(3/2)*Sin[c + d*x])/(3*d)}
{Sec[c + d*x]^0*(b*Sec[c + d*x])^(1/2)*(A + B*Sec[c + d*x]), x, 6, -((2*b*B*EllipticE[(1/2)*(c + d*x), 2])/(d*Sqrt[Cos[c + d*x]]*Sqrt[b*Sec[c + d*x]])) + (2*A*Sqrt[Cos[c + d*x]]*EllipticF[(1/2)*(c + d*x), 2]*Sqrt[b*Sec[c + d*x]])/d + (2*B*Sqrt[b*Sec[c + d*x]]*Sin[c + d*x])/d}


(* ::Subsubsection::Closed:: *)
(*n<0*)


{Sec[c + d*x]^0*(A + B*Sec[c + d*x])/(b*Sec[c + d*x])^(1/2), x, 5, (2*A*EllipticE[(1/2)*(c + d*x), 2])/(d*Sqrt[Cos[c + d*x]]*Sqrt[b*Sec[c + d*x]]) + (2*B*Sqrt[Cos[c + d*x]]*EllipticF[(1/2)*(c + d*x), 2]*Sqrt[b*Sec[c + d*x]])/(b*d)}
{Sec[c + d*x]^0*(A + B*Sec[c + d*x])/(b*Sec[c + d*x])^(3/2), x, 6, (2*B*EllipticE[(1/2)*(c + d*x), 2])/(b*d*Sqrt[Cos[c + d*x]]*Sqrt[b*Sec[c + d*x]]) + (2*A*Sqrt[Cos[c + d*x]]*EllipticF[(1/2)*(c + d*x), 2]*Sqrt[b*Sec[c + d*x]])/(3*b^2*d) + (2*A*Sin[c + d*x])/(3*b*d*Sqrt[b*Sec[c + d*x]])}
{Sec[c + d*x]^0*(A + B*Sec[c + d*x])/(b*Sec[c + d*x])^(5/2), x, 7, (6*A*EllipticE[(1/2)*(c + d*x), 2])/(5*b^2*d*Sqrt[Cos[c + d*x]]*Sqrt[b*Sec[c + d*x]]) + (2*B*Sqrt[Cos[c + d*x]]*EllipticF[(1/2)*(c + d*x), 2]*Sqrt[b*Sec[c + d*x]])/(3*b^3*d) + (2*A*Sin[c + d*x])/(5*b*d*(b*Sec[c + d*x])^(3/2)) + (2*B*Sin[c + d*x])/(3*b^2*d*Sqrt[b*Sec[c + d*x]])}


(* ::Subsection:: *)
(*Integrands of the form Sec[c+d x]^(m/2) (A+B Sec[c+d x]) (b Sec[c+d x])^(n/2)*)


(* ::Subsection::Closed:: *)
(*Integrands of the form Sec[c+d x]^m (A+B Sec[c+d x]) (b Sec[c+d x])^(n/3)*)


(* ::Subsubsection::Closed:: *)
(*n>0*)


{Sec[c + d*x]^m*(b*Sec[c + d*x])^(1/3)*(A + B*Sec[c + d*x]), x, 6, (A*(Cos[c + d*x]^2)^((-2 + 3*m)/6)*Hypergeometric2F1[1/2, (4 + 3*m)/6, 3/2, Sin[c + d*x]^2]*Sec[c + d*x]^(-1 + m)*(b*Sec[c + d*x])^(1/3)*Sin[c + d*x])/d + (B*(Cos[c + d*x]^2)^((1 + 3*m)/6)*Hypergeometric2F1[1/2, (7 + 3*m)/6, 3/2, Sin[c + d*x]^2]*Sec[c + d*x]^m*(b*Sec[c + d*x])^(1/3)*Sin[c + d*x])/d}

{Sec[c + d*x]^2*(b*Sec[c + d*x])^(1/3)*(A + B*Sec[c + d*x]), x, 9, (A*b*Hypergeometric2F1[1/2, 2/3, 3/2, Sin[c + d*x]^2]*Sin[c + d*x])/(4*d*(Cos[c + d*x]^2)^(1/3)*(b*Sec[c + d*x])^(2/3)) + (12*B*(b*Sec[c + d*x])^(1/3)*Sin[c + d*x])/(7*d) - (8*B*(Cos[c + d*x]^2)^(1/6)*Hypergeometric2F1[1/6, 1/2, 3/2, Sin[c + d*x]^2]*(b*Sec[c + d*x])^(1/3)*Sin[c + d*x])/(7*d) + (3*A*(b*Sec[c + d*x])^(4/3)*Sin[c + d*x])/(4*b*d) + (3*B*(b*Sec[c + d*x])^(7/3)*Sin[c + d*x])/(7*b^2*d)}
{Sec[c + d*x]*(b*Sec[c + d*x])^(1/3)*(A + B*Sec[c + d*x]), x, 8, (b*B*Hypergeometric2F1[1/2, 2/3, 3/2, Sin[c + d*x]^2]*Sin[c + d*x])/(4*d*(Cos[c + d*x]^2)^(1/3)*(b*Sec[c + d*x])^(2/3)) + (3*A*(b*Sec[c + d*x])^(1/3)*Sin[c + d*x])/d - (2*A*(Cos[c + d*x]^2)^(1/6)*Hypergeometric2F1[1/6, 1/2, 3/2, Sin[c + d*x]^2]*(b*Sec[c + d*x])^(1/3)*Sin[c + d*x])/d + (3*B*(b*Sec[c + d*x])^(4/3)*Sin[c + d*x])/(4*b*d)}
{(b*Sec[c + d*x])^(1/3)*(A + B*Sec[c + d*x]), x, 6, (A*b*Hypergeometric2F1[1/2, 2/3, 3/2, Sin[c + d*x]^2]*Sin[c + d*x])/(d*(Cos[c + d*x]^2)^(1/3)*(b*Sec[c + d*x])^(2/3)) + (3*B*(b*Sec[c + d*x])^(1/3)*Sin[c + d*x])/d - (2*B*(Cos[c + d*x]^2)^(1/6)*Hypergeometric2F1[1/6, 1/2, 3/2, Sin[c + d*x]^2]*(b*Sec[c + d*x])^(1/3)*Sin[c + d*x])/d}
{Cos[c + d*x]*(b*Sec[c + d*x])^(1/3)*(A + B*Sec[c + d*x]), x, 6, (b*B*Hypergeometric2F1[1/2, 2/3, 3/2, Sin[c + d*x]^2]*Sin[c + d*x])/(d*(Cos[c + d*x]^2)^(1/3)*(b*Sec[c + d*x])^(2/3)) + (A*(Cos[c + d*x]^2)^(1/6)*Hypergeometric2F1[1/6, 1/2, 3/2, Sin[c + d*x]^2]*(b*Sec[c + d*x])^(1/3)*Sin[c + d*x])/d}
{Cos[c + d*x]^2*(b*Sec[c + d*x])^(1/3)*(A + B*Sec[c + d*x]), x, 7, (3*A*b*Sin[c + d*x])/(5*d*(b*Sec[c + d*x])^(2/3)) + (2*A*b*Hypergeometric2F1[1/2, 2/3, 3/2, Sin[c + d*x]^2]*Sin[c + d*x])/(5*d*(Cos[c + d*x]^2)^(1/3)*(b*Sec[c + d*x])^(2/3)) + (B*(Cos[c + d*x]^2)^(1/6)*Hypergeometric2F1[1/6, 1/2, 3/2, Sin[c + d*x]^2]*(b*Sec[c + d*x])^(1/3)*Sin[c + d*x])/d}
{Cos[c + d*x]^3*(b*Sec[c + d*x])^(1/3)*(A + B*Sec[c + d*x]), x, 8, (3*A*b^2*Sin[c + d*x])/(8*d*(b*Sec[c + d*x])^(5/3)) + (3*b*B*Sin[c + d*x])/(5*d*(b*Sec[c + d*x])^(2/3)) + (2*b*B*Hypergeometric2F1[1/2, 2/3, 3/2, Sin[c + d*x]^2]*Sin[c + d*x])/(5*d*(Cos[c + d*x]^2)^(1/3)*(b*Sec[c + d*x])^(2/3)) + (5*A*(Cos[c + d*x]^2)^(1/6)*Hypergeometric2F1[1/6, 1/2, 3/2, Sin[c + d*x]^2]*(b*Sec[c + d*x])^(1/3)*Sin[c + d*x])/(8*d)}


{Sec[c + d*x]^m*(b*Sec[c + d*x])^(2/3)*(A + B*Sec[c + d*x]), x, 6, (A*(Cos[c + d*x]^2)^((-1 + 3*m)/6)*Hypergeometric2F1[1/2, (5 + 3*m)/6, 3/2, Sin[c + d*x]^2]*Sec[c + d*x]^(-1 + m)*(b*Sec[c + d*x])^(2/3)*Sin[c + d*x])/d + (B*(Cos[c + d*x]^2)^((2 + 3*m)/6)*Hypergeometric2F1[1/2, (8 + 3*m)/6, 3/2, Sin[c + d*x]^2]*Sec[c + d*x]^m*(b*Sec[c + d*x])^(2/3)*Sin[c + d*x])/d}

{Sec[c + d*x]^2*(b*Sec[c + d*x])^(2/3)*(A + B*Sec[c + d*x]), x, 9, (2*A*b*Hypergeometric2F1[1/2, 5/6, 3/2, Sin[c + d*x]^2]*Sin[c + d*x])/(5*d*(Cos[c + d*x]^2)^(1/6)*(b*Sec[c + d*x])^(1/3)) + (15*B*(b*Sec[c + d*x])^(2/3)*Sin[c + d*x])/(16*d) - (5*B*(Cos[c + d*x]^2)^(1/3)*Hypergeometric2F1[1/3, 1/2, 3/2, Sin[c + d*x]^2]*(b*Sec[c + d*x])^(2/3)*Sin[c + d*x])/(16*d) + (3*A*(b*Sec[c + d*x])^(5/3)*Sin[c + d*x])/(5*b*d) + (3*B*(b*Sec[c + d*x])^(8/3)*Sin[c + d*x])/(8*b^2*d)}
{Sec[c + d*x]*(b*Sec[c + d*x])^(2/3)*(A + B*Sec[c + d*x]), x, 8, (2*b*B*Hypergeometric2F1[1/2, 5/6, 3/2, Sin[c + d*x]^2]*Sin[c + d*x])/(5*d*(Cos[c + d*x]^2)^(1/6)*(b*Sec[c + d*x])^(1/3)) + (3*A*(b*Sec[c + d*x])^(2/3)*Sin[c + d*x])/(2*d) - (A*(Cos[c + d*x]^2)^(1/3)*Hypergeometric2F1[1/3, 1/2, 3/2, Sin[c + d*x]^2]*(b*Sec[c + d*x])^(2/3)*Sin[c + d*x])/(2*d) + (3*B*(b*Sec[c + d*x])^(5/3)*Sin[c + d*x])/(5*b*d)}
{(b*Sec[c + d*x])^(2/3)*(A + B*Sec[c + d*x]), x, 6, (A*b*Hypergeometric2F1[1/2, 5/6, 3/2, Sin[c + d*x]^2]*Sin[c + d*x])/(d*(Cos[c + d*x]^2)^(1/6)*(b*Sec[c + d*x])^(1/3)) + (3*B*(b*Sec[c + d*x])^(2/3)*Sin[c + d*x])/(2*d) - (B*(Cos[c + d*x]^2)^(1/3)*Hypergeometric2F1[1/3, 1/2, 3/2, Sin[c + d*x]^2]*(b*Sec[c + d*x])^(2/3)*Sin[c + d*x])/(2*d)}
{Cos[c + d*x]*(b*Sec[c + d*x])^(2/3)*(A + B*Sec[c + d*x]), x, 6, (b*B*Hypergeometric2F1[1/2, 5/6, 3/2, Sin[c + d*x]^2]*Sin[c + d*x])/(d*(Cos[c + d*x]^2)^(1/6)*(b*Sec[c + d*x])^(1/3)) + (A*(Cos[c + d*x]^2)^(1/3)*Hypergeometric2F1[1/3, 1/2, 3/2, Sin[c + d*x]^2]*(b*Sec[c + d*x])^(2/3)*Sin[c + d*x])/d}
{Cos[c + d*x]^2*(b*Sec[c + d*x])^(2/3)*(A + B*Sec[c + d*x]), x, 7, (3*A*b*Sin[c + d*x])/(4*d*(b*Sec[c + d*x])^(1/3)) + (A*b*Hypergeometric2F1[1/2, 5/6, 3/2, Sin[c + d*x]^2]*Sin[c + d*x])/(4*d*(Cos[c + d*x]^2)^(1/6)*(b*Sec[c + d*x])^(1/3)) + (B*(Cos[c + d*x]^2)^(1/3)*Hypergeometric2F1[1/3, 1/2, 3/2, Sin[c + d*x]^2]*(b*Sec[c + d*x])^(2/3)*Sin[c + d*x])/d}
{Cos[c + d*x]^3*(b*Sec[c + d*x])^(2/3)*(A + B*Sec[c + d*x]), x, 8, (3*A*b^2*Sin[c + d*x])/(7*d*(b*Sec[c + d*x])^(4/3)) + (3*b*B*Sin[c + d*x])/(4*d*(b*Sec[c + d*x])^(1/3)) + (b*B*Hypergeometric2F1[1/2, 5/6, 3/2, Sin[c + d*x]^2]*Sin[c + d*x])/(4*d*(Cos[c + d*x]^2)^(1/6)*(b*Sec[c + d*x])^(1/3)) + (4*A*(Cos[c + d*x]^2)^(1/3)*Hypergeometric2F1[1/3, 1/2, 3/2, Sin[c + d*x]^2]*(b*Sec[c + d*x])^(2/3)*Sin[c + d*x])/(7*d)}


{Sec[c + d*x]^m*(b*Sec[c + d*x])^(4/3)*(A + B*Sec[c + d*x]), x, 6, (A*(Cos[c + d*x]^2)^((1 + 3*m)/6)*Hypergeometric2F1[1/2, (7 + 3*m)/6, 3/2, Sin[c + d*x]^2]*Sec[c + d*x]^(-1 + m)*(b*Sec[c + d*x])^(4/3)*Sin[c + d*x])/d + (B*(Cos[c + d*x]^2)^((4 + 3*m)/6)*Hypergeometric2F1[1/2, (10 + 3*m)/6, 3/2, Sin[c + d*x]^2]*Sec[c + d*x]^m*(b*Sec[c + d*x])^(4/3)*Sin[c + d*x])/d}

{Sec[c + d*x]^2*(b*Sec[c + d*x])^(4/3)*(A + B*Sec[c + d*x]), x, 10, (7*b^2*B*Hypergeometric2F1[1/2, 2/3, 3/2, Sin[c + d*x]^2]*Sin[c + d*x])/(40*d*(Cos[c + d*x]^2)^(1/3)*(b*Sec[c + d*x])^(2/3)) + (12*A*b*(b*Sec[c + d*x])^(1/3)*Sin[c + d*x])/(7*d) - (8*A*b*(Cos[c + d*x]^2)^(1/6)*Hypergeometric2F1[1/6, 1/2, 3/2, Sin[c + d*x]^2]*(b*Sec[c + d*x])^(1/3)*Sin[c + d*x])/(7*d) + (21*B*(b*Sec[c + d*x])^(4/3)*Sin[c + d*x])/(40*d) + (3*A*(b*Sec[c + d*x])^(7/3)*Sin[c + d*x])/(7*b*d) + (3*B*(b*Sec[c + d*x])^(10/3)*Sin[c + d*x])/(10*b^2*d)}
{Sec[c + d*x]*(b*Sec[c + d*x])^(4/3)*(A + B*Sec[c + d*x]), x, 9, (A*b^2*Hypergeometric2F1[1/2, 2/3, 3/2, Sin[c + d*x]^2]*Sin[c + d*x])/(4*d*(Cos[c + d*x]^2)^(1/3)*(b*Sec[c + d*x])^(2/3)) + (12*b*B*(b*Sec[c + d*x])^(1/3)*Sin[c + d*x])/(7*d) - (8*b*B*(Cos[c + d*x]^2)^(1/6)*Hypergeometric2F1[1/6, 1/2, 3/2, Sin[c + d*x]^2]*(b*Sec[c + d*x])^(1/3)*Sin[c + d*x])/(7*d) + (3*A*(b*Sec[c + d*x])^(4/3)*Sin[c + d*x])/(4*d) + (3*B*(b*Sec[c + d*x])^(7/3)*Sin[c + d*x])/(7*b*d)}
{(b*Sec[c + d*x])^(4/3)*(A + B*Sec[c + d*x]), x, 7, (b^2*B*Hypergeometric2F1[1/2, 2/3, 3/2, Sin[c + d*x]^2]*Sin[c + d*x])/(4*d*(Cos[c + d*x]^2)^(1/3)*(b*Sec[c + d*x])^(2/3)) + (3*A*b*(b*Sec[c + d*x])^(1/3)*Sin[c + d*x])/d - (2*A*b*(Cos[c + d*x]^2)^(1/6)*Hypergeometric2F1[1/6, 1/2, 3/2, Sin[c + d*x]^2]*(b*Sec[c + d*x])^(1/3)*Sin[c + d*x])/d + (3*B*(b*Sec[c + d*x])^(4/3)*Sin[c + d*x])/(4*d)}
{Cos[c + d*x]*(b*Sec[c + d*x])^(4/3)*(A + B*Sec[c + d*x]), x, 7, (A*b^2*Hypergeometric2F1[1/2, 2/3, 3/2, Sin[c + d*x]^2]*Sin[c + d*x])/(d*(Cos[c + d*x]^2)^(1/3)*(b*Sec[c + d*x])^(2/3)) + (3*b*B*(b*Sec[c + d*x])^(1/3)*Sin[c + d*x])/d - (2*b*B*(Cos[c + d*x]^2)^(1/6)*Hypergeometric2F1[1/6, 1/2, 3/2, Sin[c + d*x]^2]*(b*Sec[c + d*x])^(1/3)*Sin[c + d*x])/d}
{Cos[c + d*x]^2*(b*Sec[c + d*x])^(4/3)*(A + B*Sec[c + d*x]), x, 6, (b^2*B*Hypergeometric2F1[1/2, 2/3, 3/2, Sin[c + d*x]^2]*Sin[c + d*x])/(d*(Cos[c + d*x]^2)^(1/3)*(b*Sec[c + d*x])^(2/3)) + (A*b*(Cos[c + d*x]^2)^(1/6)*Hypergeometric2F1[1/6, 1/2, 3/2, Sin[c + d*x]^2]*(b*Sec[c + d*x])^(1/3)*Sin[c + d*x])/d}
{Cos[c + d*x]^3*(b*Sec[c + d*x])^(4/3)*(A + B*Sec[c + d*x]), x, 7, (3*A*b^2*Sin[c + d*x])/(5*d*(b*Sec[c + d*x])^(2/3)) + (2*A*b^2*Hypergeometric2F1[1/2, 2/3, 3/2, Sin[c + d*x]^2]*Sin[c + d*x])/(5*d*(Cos[c + d*x]^2)^(1/3)*(b*Sec[c + d*x])^(2/3)) + (b*B*(Cos[c + d*x]^2)^(1/6)*Hypergeometric2F1[1/6, 1/2, 3/2, Sin[c + d*x]^2]*(b*Sec[c + d*x])^(1/3)*Sin[c + d*x])/d}


(* ::Subsubsection::Closed:: *)
(*n<0*)


{(Sec[c + d*x]^m*(A + B*Sec[c + d*x]))/(b*Sec[c + d*x])^(1/3), x, 6, (B*(Cos[c + d*x]^2)^((-1 + 3*m)/6)*Hypergeometric2F1[1/2, (5 + 3*m)/6, 3/2, Sin[c + d*x]^2]*Sec[c + d*x]^m*Sin[c + d*x])/(d*(b*Sec[c + d*x])^(1/3)) + (A*(Cos[c + d*x]^2)^((2 + 3*m)/6)*Hypergeometric2F1[1/2, (2 + 3*m)/6, 3/2, Sin[c + d*x]^2]*Sec[c + d*x]^(1 + m)*Sin[c + d*x])/(d*(b*Sec[c + d*x])^(1/3))}

{(Sec[c + d*x]^2*(A + B*Sec[c + d*x]))/(b*Sec[c + d*x])^(1/3), x, 8, (2*B*Hypergeometric2F1[1/2, 5/6, 3/2, Sin[c + d*x]^2]*Sin[c + d*x])/(5*d*(Cos[c + d*x]^2)^(1/6)*(b*Sec[c + d*x])^(1/3)) + (3*A*(b*Sec[c + d*x])^(2/3)*Sin[c + d*x])/(2*b*d) - (A*(Cos[c + d*x]^2)^(1/3)*Hypergeometric2F1[1/3, 1/2, 3/2, Sin[c + d*x]^2]*(b*Sec[c + d*x])^(2/3)*Sin[c + d*x])/(2*b*d) + (3*B*(b*Sec[c + d*x])^(5/3)*Sin[c + d*x])/(5*b^2*d)}
{(Sec[c + d*x]*(A + B*Sec[c + d*x]))/(b*Sec[c + d*x])^(1/3), x, 7, (A*Hypergeometric2F1[1/2, 5/6, 3/2, Sin[c + d*x]^2]*Sin[c + d*x])/(d*(Cos[c + d*x]^2)^(1/6)*(b*Sec[c + d*x])^(1/3)) + (3*B*(b*Sec[c + d*x])^(2/3)*Sin[c + d*x])/(2*b*d) - (B*(Cos[c + d*x]^2)^(1/3)*Hypergeometric2F1[1/3, 1/2, 3/2, Sin[c + d*x]^2]*(b*Sec[c + d*x])^(2/3)*Sin[c + d*x])/(2*b*d)}
{(A + B*Sec[c + d*x])/(b*Sec[c + d*x])^(1/3), x, 5, (B*Hypergeometric2F1[1/2, 5/6, 3/2, Sin[c + d*x]^2]*Sin[c + d*x])/(d*(Cos[c + d*x]^2)^(1/6)*(b*Sec[c + d*x])^(1/3)) + (A*(Cos[c + d*x]^2)^(1/3)*Hypergeometric2F1[1/3, 1/2, 3/2, Sin[c + d*x]^2]*(b*Sec[c + d*x])^(2/3)*Sin[c + d*x])/(b*d)}
{(Sec[c + d*x]*(A + B*Sec[c + d*x]))/(b*Sec[c + d*x])^(1/3), x, 7, (A*Hypergeometric2F1[1/2, 5/6, 3/2, Sin[c + d*x]^2]*Sin[c + d*x])/(d*(Cos[c + d*x]^2)^(1/6)*(b*Sec[c + d*x])^(1/3)) + (3*B*(b*Sec[c + d*x])^(2/3)*Sin[c + d*x])/(2*b*d) - (B*(Cos[c + d*x]^2)^(1/3)*Hypergeometric2F1[1/3, 1/2, 3/2, Sin[c + d*x]^2]*(b*Sec[c + d*x])^(2/3)*Sin[c + d*x])/(2*b*d)}
{(Sec[c + d*x]^2*(A + B*Sec[c + d*x]))/(b*Sec[c + d*x])^(1/3), x, 8, (2*B*Hypergeometric2F1[1/2, 5/6, 3/2, Sin[c + d*x]^2]*Sin[c + d*x])/(5*d*(Cos[c + d*x]^2)^(1/6)*(b*Sec[c + d*x])^(1/3)) + (3*A*(b*Sec[c + d*x])^(2/3)*Sin[c + d*x])/(2*b*d) - (A*(Cos[c + d*x]^2)^(1/3)*Hypergeometric2F1[1/3, 1/2, 3/2, Sin[c + d*x]^2]*(b*Sec[c + d*x])^(2/3)*Sin[c + d*x])/(2*b*d) + (3*B*(b*Sec[c + d*x])^(5/3)*Sin[c + d*x])/(5*b^2*d)}
{(Sec[c + d*x]^3*(A + B*Sec[c + d*x]))/(b*Sec[c + d*x])^(1/3), x, 9, (2*A*Hypergeometric2F1[1/2, 5/6, 3/2, Sin[c + d*x]^2]*Sin[c + d*x])/(5*d*(Cos[c + d*x]^2)^(1/6)*(b*Sec[c + d*x])^(1/3)) + (15*B*(b*Sec[c + d*x])^(2/3)*Sin[c + d*x])/(16*b*d) - (5*B*(Cos[c + d*x]^2)^(1/3)*Hypergeometric2F1[1/3, 1/2, 3/2, Sin[c + d*x]^2]*(b*Sec[c + d*x])^(2/3)*Sin[c + d*x])/(16*b*d) + (3*A*(b*Sec[c + d*x])^(5/3)*Sin[c + d*x])/(5*b^2*d) + (3*B*(b*Sec[c + d*x])^(8/3)*Sin[c + d*x])/(8*b^3*d)}


{(Sec[c + d*x]^m*(A + B*Sec[c + d*x]))/(b*Sec[c + d*x])^(2/3), x, 6, (B*(Cos[c + d*x]^2)^((-2 + 3*m)/6)*Hypergeometric2F1[1/2, (4 + 3*m)/6, 3/2, Sin[c + d*x]^2]*Sec[c + d*x]^m*Sin[c + d*x])/(d*(b*Sec[c + d*x])^(2/3)) + (A*(Cos[c + d*x]^2)^((1 + 3*m)/6)*Hypergeometric2F1[1/2, (1 + 3*m)/6, 3/2, Sin[c + d*x]^2]*Sec[c + d*x]^(1 + m)*Sin[c + d*x])/(d*(b*Sec[c + d*x])^(2/3))}

{(Sec[c + d*x]^2*(A + B*Sec[c + d*x]))/(b*Sec[c + d*x])^(2/3), x, 8, (B*Hypergeometric2F1[1/2, 2/3, 3/2, Sin[c + d*x]^2]*Sin[c + d*x])/(4*d*(Cos[c + d*x]^2)^(1/3)*(b*Sec[c + d*x])^(2/3)) + (3*A*(b*Sec[c + d*x])^(1/3)*Sin[c + d*x])/(b*d) - (2*A*(Cos[c + d*x]^2)^(1/6)*Hypergeometric2F1[1/6, 1/2, 3/2, Sin[c + d*x]^2]*(b*Sec[c + d*x])^(1/3)*Sin[c + d*x])/(b*d) + (3*B*(b*Sec[c + d*x])^(4/3)*Sin[c + d*x])/(4*b^2*d)}
{(Sec[c + d*x]*(A + B*Sec[c + d*x]))/(b*Sec[c + d*x])^(2/3), x, 7, (A*Hypergeometric2F1[1/2, 2/3, 3/2, Sin[c + d*x]^2]*Sin[c + d*x])/(d*(Cos[c + d*x]^2)^(1/3)*(b*Sec[c + d*x])^(2/3)) + (3*B*(b*Sec[c + d*x])^(1/3)*Sin[c + d*x])/(b*d) - (2*B*(Cos[c + d*x]^2)^(1/6)*Hypergeometric2F1[1/6, 1/2, 3/2, Sin[c + d*x]^2]*(b*Sec[c + d*x])^(1/3)*Sin[c + d*x])/(b*d)}
{(A + B*Sec[c + d*x])/(b*Sec[c + d*x])^(2/3), x, 5, (B*Hypergeometric2F1[1/2, 2/3, 3/2, Sin[c + d*x]^2]*Sin[c + d*x])/(d*(Cos[c + d*x]^2)^(1/3)*(b*Sec[c + d*x])^(2/3)) + (A*(Cos[c + d*x]^2)^(1/6)*Hypergeometric2F1[1/6, 1/2, 3/2, Sin[c + d*x]^2]*(b*Sec[c + d*x])^(1/3)*Sin[c + d*x])/(b*d)}
{(Sec[c + d*x]*(A + B*Sec[c + d*x]))/(b*Sec[c + d*x])^(2/3), x, 7, (A*Hypergeometric2F1[1/2, 2/3, 3/2, Sin[c + d*x]^2]*Sin[c + d*x])/(d*(Cos[c + d*x]^2)^(1/3)*(b*Sec[c + d*x])^(2/3)) + (3*B*(b*Sec[c + d*x])^(1/3)*Sin[c + d*x])/(b*d) - (2*B*(Cos[c + d*x]^2)^(1/6)*Hypergeometric2F1[1/6, 1/2, 3/2, Sin[c + d*x]^2]*(b*Sec[c + d*x])^(1/3)*Sin[c + d*x])/(b*d)}
{(Sec[c + d*x]^2*(A + B*Sec[c + d*x]))/(b*Sec[c + d*x])^(2/3), x, 8, (B*Hypergeometric2F1[1/2, 2/3, 3/2, Sin[c + d*x]^2]*Sin[c + d*x])/(4*d*(Cos[c + d*x]^2)^(1/3)*(b*Sec[c + d*x])^(2/3)) + (3*A*(b*Sec[c + d*x])^(1/3)*Sin[c + d*x])/(b*d) - (2*A*(Cos[c + d*x]^2)^(1/6)*Hypergeometric2F1[1/6, 1/2, 3/2, Sin[c + d*x]^2]*(b*Sec[c + d*x])^(1/3)*Sin[c + d*x])/(b*d) + (3*B*(b*Sec[c + d*x])^(4/3)*Sin[c + d*x])/(4*b^2*d)}
{(Sec[c + d*x]^3*(A + B*Sec[c + d*x]))/(b*Sec[c + d*x])^(2/3), x, 9, (A*Hypergeometric2F1[1/2, 2/3, 3/2, Sin[c + d*x]^2]*Sin[c + d*x])/(4*d*(Cos[c + d*x]^2)^(1/3)*(b*Sec[c + d*x])^(2/3)) + (12*B*(b*Sec[c + d*x])^(1/3)*Sin[c + d*x])/(7*b*d) - (8*B*(Cos[c + d*x]^2)^(1/6)*Hypergeometric2F1[1/6, 1/2, 3/2, Sin[c + d*x]^2]*(b*Sec[c + d*x])^(1/3)*Sin[c + d*x])/(7*b*d) + (3*A*(b*Sec[c + d*x])^(4/3)*Sin[c + d*x])/(4*b^2*d) + (3*B*(b*Sec[c + d*x])^(7/3)*Sin[c + d*x])/(7*b^3*d)}


{(Sec[c + d*x]^m*(A + B*Sec[c + d*x]))/(b*Sec[c + d*x])^(4/3), x, 6, (A*(Cos[c + d*x]^2)^((-7 + 3*m)/6)*Hypergeometric2F1[1/2, (-1 + 3*m)/6, 3/2, Sin[c + d*x]^2]*Sec[c + d*x]^(-1 + m)*Sin[c + d*x])/(d*(b*Sec[c + d*x])^(4/3)) + (B*(Cos[c + d*x]^2)^((2 + 3*m)/6)*Hypergeometric2F1[1/2, (2 + 3*m)/6, 3/2, Sin[c + d*x]^2]*Sec[c + d*x]^(2 + m)*Sin[c + d*x])/(d*(b*Sec[c + d*x])^(4/3))}

{(Sec[c + d*x]^2*(A + B*Sec[c + d*x]))/(b*Sec[c + d*x])^(4/3), x, 7, (A*Hypergeometric2F1[1/2, 5/6, 3/2, Sin[c + d*x]^2]*Sin[c + d*x])/(b*d*(Cos[c + d*x]^2)^(1/6)*(b*Sec[c + d*x])^(1/3)) + (3*B*(b*Sec[c + d*x])^(2/3)*Sin[c + d*x])/(2*b^2*d) - (B*(Cos[c + d*x]^2)^(1/3)*Hypergeometric2F1[1/3, 1/2, 3/2, Sin[c + d*x]^2]*(b*Sec[c + d*x])^(2/3)*Sin[c + d*x])/(2*b^2*d)}
{(Sec[c + d*x]*(A + B*Sec[c + d*x]))/(b*Sec[c + d*x])^(4/3), x, 6, (B*Hypergeometric2F1[1/2, 5/6, 3/2, Sin[c + d*x]^2]*Sin[c + d*x])/(b*d*(Cos[c + d*x]^2)^(1/6)*(b*Sec[c + d*x])^(1/3)) + (A*(Cos[c + d*x]^2)^(1/3)*Hypergeometric2F1[1/3, 1/2, 3/2, Sin[c + d*x]^2]*(b*Sec[c + d*x])^(2/3)*Sin[c + d*x])/(b^2*d)}
{(A + B*Sec[c + d*x])/(b*Sec[c + d*x])^(4/3), x, 6, (3*A*Sin[c + d*x])/(4*b*d*(b*Sec[c + d*x])^(1/3)) + (A*Hypergeometric2F1[1/2, 5/6, 3/2, Sin[c + d*x]^2]*Sin[c + d*x])/(4*b*d*(Cos[c + d*x]^2)^(1/6)*(b*Sec[c + d*x])^(1/3)) + (B*(Cos[c + d*x]^2)^(1/3)*Hypergeometric2F1[1/3, 1/2, 3/2, Sin[c + d*x]^2]*(b*Sec[c + d*x])^(2/3)*Sin[c + d*x])/(b^2*d)}
{(Sec[c + d*x]*(A + B*Sec[c + d*x]))/(b*Sec[c + d*x])^(4/3), x, 6, (B*Hypergeometric2F1[1/2, 5/6, 3/2, Sin[c + d*x]^2]*Sin[c + d*x])/(b*d*(Cos[c + d*x]^2)^(1/6)*(b*Sec[c + d*x])^(1/3)) + (A*(Cos[c + d*x]^2)^(1/3)*Hypergeometric2F1[1/3, 1/2, 3/2, Sin[c + d*x]^2]*(b*Sec[c + d*x])^(2/3)*Sin[c + d*x])/(b^2*d)}
{(Sec[c + d*x]^2*(A + B*Sec[c + d*x]))/(b*Sec[c + d*x])^(4/3), x, 7, (A*Hypergeometric2F1[1/2, 5/6, 3/2, Sin[c + d*x]^2]*Sin[c + d*x])/(b*d*(Cos[c + d*x]^2)^(1/6)*(b*Sec[c + d*x])^(1/3)) + (3*B*(b*Sec[c + d*x])^(2/3)*Sin[c + d*x])/(2*b^2*d) - (B*(Cos[c + d*x]^2)^(1/3)*Hypergeometric2F1[1/3, 1/2, 3/2, Sin[c + d*x]^2]*(b*Sec[c + d*x])^(2/3)*Sin[c + d*x])/(2*b^2*d)}
{(Sec[c + d*x]^3*(A + B*Sec[c + d*x]))/(b*Sec[c + d*x])^(4/3), x, 8, (2*B*Hypergeometric2F1[1/2, 5/6, 3/2, Sin[c + d*x]^2]*Sin[c + d*x])/(5*b*d*(Cos[c + d*x]^2)^(1/6)*(b*Sec[c + d*x])^(1/3)) + (3*A*(b*Sec[c + d*x])^(2/3)*Sin[c + d*x])/(2*b^2*d) - (A*(Cos[c + d*x]^2)^(1/3)*Hypergeometric2F1[1/3, 1/2, 3/2, Sin[c + d*x]^2]*(b*Sec[c + d*x])^(2/3)*Sin[c + d*x])/(2*b^2*d) + (3*B*(b*Sec[c + d*x])^(5/3)*Sin[c + d*x])/(5*b^3*d)}


(* ::Subsection::Closed:: *)
(*Integrands of the form Sec[c+d x]^m (A+B Sec[c+d x]) (b Sec[c+d x])^n when n symbolic*)


{Sec[c + d*x]^m*(b*Sec[c + d*x])^n*(A + B*Sec[c + d*x]), x, 6, (A*(Cos[c + d*x]^2)^((-1 + m + n)/2)*Hypergeometric2F1[1/2, (1 + m + n)/2, 3/2, Sin[c + d*x]^2]*Sec[c + d*x]^(-1 + m)*(b*Sec[c + d*x])^n*Sin[c + d*x])/d + (B*(Cos[c + d*x]^2)^((m + n)/2)*Hypergeometric2F1[1/2, (2 + m + n)/2, 3/2, Sin[c + d*x]^2]*Sec[c + d*x]^m*(b*Sec[c + d*x])^n*Sin[c + d*x])/d}

{Sec[c + d*x]^2*(b*Sec[c + d*x])^n*(A + B*Sec[c + d*x]), x, 6, (A*(Cos[c + d*x]^2)^((1 + n)/2)*Hypergeometric2F1[1/2, (3 + n)/2, 3/2, Sin[c + d*x]^2]*(b*Sec[c + d*x])^(1 + n)*Sin[c + d*x])/(b*d) + (B*(Cos[c + d*x]^2)^((2 + n)/2)*Hypergeometric2F1[1/2, (4 + n)/2, 3/2, Sin[c + d*x]^2]*(b*Sec[c + d*x])^(2 + n)*Sin[c + d*x])/(b^2*d)}
{Sec[c + d*x]*(b*Sec[c + d*x])^n*(A + B*Sec[c + d*x]), x, 6, (A*(Cos[c + d*x]^2)^(n/2)*Hypergeometric2F1[1/2, (2 + n)/2, 3/2, Sin[c + d*x]^2]*(b*Sec[c + d*x])^n*Sin[c + d*x])/d + (B*(Cos[c + d*x]^2)^((1 + n)/2)*Hypergeometric2F1[1/2, (3 + n)/2, 3/2, Sin[c + d*x]^2]*(b*Sec[c + d*x])^(1 + n)*Sin[c + d*x])/(b*d)}
{(b*Sec[c + d*x])^n*(A + B*Sec[c + d*x]), x, 5, (A*b*(Cos[c + d*x]^2)^((1/2)*(-1 + n))*Hypergeometric2F1[1/2, (1 + n)/2, 3/2, Sin[c + d*x]^2]*(b*Sec[c + d*x])^(-1 + n)*Sin[c + d*x])/d + (B*(Cos[c + d*x]^2)^(n/2)*Hypergeometric2F1[1/2, (2 + n)/2, 3/2, Sin[c + d*x]^2]*(b*Sec[c + d*x])^n*Sin[c + d*x])/d}
{Cos[c + d*x]*(b*Sec[c + d*x])^n*(A + B*Sec[c + d*x]), x, 6, (A*b^2*(Cos[c + d*x]^2)^((1/2)*(-2 + n))*Hypergeometric2F1[1/2, n/2, 3/2, Sin[c + d*x]^2]*(b*Sec[c + d*x])^(-2 + n)*Sin[c + d*x])/d + (b*B*(Cos[c + d*x]^2)^((1/2)*(-1 + n))*Hypergeometric2F1[1/2, (1 + n)/2, 3/2, Sin[c + d*x]^2]*(b*Sec[c + d*x])^(-1 + n)*Sin[c + d*x])/d}
{Cos[c + d*x]^2*(b*Sec[c + d*x])^n*(A + B*Sec[c + d*x]), x, 6, (A*b^3*(Cos[c + d*x]^2)^((1/2)*(-3 + n))*Hypergeometric2F1[1/2, (1/2)*(-1 + n), 3/2, Sin[c + d*x]^2]*(b*Sec[c + d*x])^(-3 + n)*Sin[c + d*x])/d + (b^2*B*(Cos[c + d*x]^2)^((1/2)*(-2 + n))*Hypergeometric2F1[1/2, n/2, 3/2, Sin[c + d*x]^2]*(b*Sec[c + d*x])^(-2 + n)*Sin[c + d*x])/d}
{Cos[c + d*x]^3*(b*Sec[c + d*x])^n*(A + B*Sec[c + d*x]), x, 6, (A*b^4*(Cos[c + d*x]^2)^((1/2)*(-4 + n))*Hypergeometric2F1[1/2, (1/2)*(-2 + n), 3/2, Sin[c + d*x]^2]*(b*Sec[c + d*x])^(-4 + n)*Sin[c + d*x])/d + (b^3*B*(Cos[c + d*x]^2)^((1/2)*(-3 + n))*Hypergeometric2F1[1/2, (1/2)*(-1 + n), 3/2, Sin[c + d*x]^2]*(b*Sec[c + d*x])^(-3 + n)*Sin[c + d*x])/d}
{Cos[c + d*x]^4*(b*Sec[c + d*x])^n*(A + B*Sec[c + d*x]), x, 6, (A*b^5*(Cos[c + d*x]^2)^((1/2)*(-5 + n))*Hypergeometric2F1[1/2, (1/2)*(-3 + n), 3/2, Sin[c + d*x]^2]*(b*Sec[c + d*x])^(-5 + n)*Sin[c + d*x])/d + (b^4*B*(Cos[c + d*x]^2)^((1/2)*(-4 + n))*Hypergeometric2F1[1/2, (1/2)*(-2 + n), 3/2, Sin[c + d*x]^2]*(b*Sec[c + d*x])^(-4 + n)*Sin[c + d*x])/d}


{Sec[c + d*x]^(5/2)*(b*Sec[c + d*x])^n*(A + B*Sec[c + d*x]), x, 6, (A*(Cos[c + d*x]^2)^((3 + 2*n)/4)*Hypergeometric2F1[1/2, (7 + 2*n)/4, 3/2, Sin[c + d*x]^2]*Sec[c + d*x]^(3/2)*(b*Sec[c + d*x])^n*Sin[c + d*x])/d + (B*(Cos[c + d*x]^2)^((5 + 2*n)/4)*Hypergeometric2F1[1/2, (9 + 2*n)/4, 3/2, Sin[c + d*x]^2]*Sec[c + d*x]^(5/2)*(b*Sec[c + d*x])^n*Sin[c + d*x])/d}
{Sec[c + d*x]^(3/2)*(b*Sec[c + d*x])^n*(A + B*Sec[c + d*x]), x, 6, (A*(Cos[c + d*x]^2)^((1 + 2*n)/4)*Hypergeometric2F1[1/2, (5 + 2*n)/4, 3/2, Sin[c + d*x]^2]*Sqrt[Sec[c + d*x]]*(b*Sec[c + d*x])^n*Sin[c + d*x])/d + (B*(Cos[c + d*x]^2)^((3 + 2*n)/4)*Hypergeometric2F1[1/2, (7 + 2*n)/4, 3/2, Sin[c + d*x]^2]*Sec[c + d*x]^(3/2)*(b*Sec[c + d*x])^n*Sin[c + d*x])/d}
{Sqrt[Sec[c + d*x]]*(b*Sec[c + d*x])^n*(A + B*Sec[c + d*x]), x, 6, (A*(Cos[c + d*x]^2)^((-1 + 2*n)/4)*Hypergeometric2F1[1/2, (3 + 2*n)/4, 3/2, Sin[c + d*x]^2]*(b*Sec[c + d*x])^n*Sin[c + d*x])/(d*Sqrt[Sec[c + d*x]]) + (B*(Cos[c + d*x]^2)^((1 + 2*n)/4)*Hypergeometric2F1[1/2, (5 + 2*n)/4, 3/2, Sin[c + d*x]^2]*Sqrt[Sec[c + d*x]]*(b*Sec[c + d*x])^n*Sin[c + d*x])/d}
{((b*Sec[c + d*x])^n*(A + B*Sec[c + d*x]))/Sqrt[Sec[c + d*x]], x, 6, (B*(Cos[c + d*x]^2)^((-1 + 2*n)/4)*Hypergeometric2F1[1/2, (3 + 2*n)/4, 3/2, Sin[c + d*x]^2]*(b*Sec[c + d*x])^n*Sin[c + d*x])/(d*Sqrt[Sec[c + d*x]]) + (A*(Cos[c + d*x]^2)^((1 + 2*n)/4)*Hypergeometric2F1[1/2, (1 + 2*n)/4, 3/2, Sin[c + d*x]^2]*Sqrt[Sec[c + d*x]]*(b*Sec[c + d*x])^n*Sin[c + d*x])/d}
{((b*Sec[c + d*x])^n*(A + B*Sec[c + d*x]))/Sec[c + d*x]^(3/2), x, 6, (A*(Cos[c + d*x]^2)^((-5 + 2*n)/4)*Hypergeometric2F1[1/2, (-1 + 2*n)/4, 3/2, Sin[c + d*x]^2]*(b*Sec[c + d*x])^n*Sin[c + d*x])/(d*Sec[c + d*x]^(5/2)) + (B*(Cos[c + d*x]^2)^((1 + 2*n)/4)*Hypergeometric2F1[1/2, (1 + 2*n)/4, 3/2, Sin[c + d*x]^2]*Sqrt[Sec[c + d*x]]*(b*Sec[c + d*x])^n*Sin[c + d*x])/d}
{((b*Sec[c + d*x])^n*(A + B*Sec[c + d*x]))/Sec[c + d*x]^(5/2), x, 6, (A*(Cos[c + d*x]^2)^((-7 + 2*n)/4)*Hypergeometric2F1[1/2, (-3 + 2*n)/4, 3/2, Sin[c + d*x]^2]*(b*Sec[c + d*x])^n*Sin[c + d*x])/(d*Sec[c + d*x]^(7/2)) + (B*(Cos[c + d*x]^2)^((-5 + 2*n)/4)*Hypergeometric2F1[1/2, (-1 + 2*n)/4, 3/2, Sin[c + d*x]^2]*(b*Sec[c + d*x])^n*Sin[c + d*x])/(d*Sec[c + d*x]^(5/2))}
{((b*Sec[c + d*x])^n*(A + B*Sec[c + d*x]))/Sec[c + d*x]^(7/2), x, 6, (A*(Cos[c + d*x]^2)^((-9 + 2*n)/4)*Hypergeometric2F1[1/2, (-5 + 2*n)/4, 3/2, Sin[c + d*x]^2]*(b*Sec[c + d*x])^n*Sin[c + d*x])/(d*Sec[c + d*x]^(9/2)) + (B*(Cos[c + d*x]^2)^((-7 + 2*n)/4)*Hypergeometric2F1[1/2, (-3 + 2*n)/4, 3/2, Sin[c + d*x]^2]*(b*Sec[c + d*x])^n*Sin[c + d*x])/(d*Sec[c + d*x]^(7/2))}
{((b*Sec[c + d*x])^n*(A + B*Sec[c + d*x]))/Sec[c + d*x]^(9/2), x, 6, (A*(Cos[c + d*x]^2)^((-11 + 2*n)/4)*Hypergeometric2F1[1/2, (-7 + 2*n)/4, 3/2, Sin[c + d*x]^2]*(b*Sec[c + d*x])^n*Sin[c + d*x])/(d*Sec[c + d*x]^(11/2)) + (B*(Cos[c + d*x]^2)^((-9 + 2*n)/4)*Hypergeometric2F1[1/2, (-5 + 2*n)/4, 3/2, Sin[c + d*x]^2]*(b*Sec[c + d*x])^n*Sin[c + d*x])/(d*Sec[c + d*x]^(9/2))}


(* ::Section:: *)
(*Sec[c+d x]^m (A+C Sec[c+d x]^2) (b Sec[c+d x])^(n/2)*)


(* ::Subsection::Closed:: *)
(*Integrands of the form Sec[c+d x]^m (A+C Sec[c+d x]^2) (b Sec[c+d x])^(n/2)*)


(* ::Subsubsection::Closed:: *)
(*n>0*)


{Sec[c + d*x]^0*(A + C*Sec[c + d*x]^2)*(b*Sec[c + d*x])^(5/2), x, 4, (2*b^2*(7*A + 5*C)*Sqrt[Cos[c + d*x]]*EllipticF[(1/2)*(c + d*x), 2]*Sqrt[b*Sec[c + d*x]])/(21*d) + (2*b*(7*A + 5*C)*(b*Sec[c + d*x])^(3/2)*Sin[c + d*x])/(21*d) + (2*C*(b*Sec[c + d*x])^(5/2)*Tan[c + d*x])/(7*d)}
{Sec[c + d*x]^0*(A + C*Sec[c + d*x]^2)*(b*Sec[c + d*x])^(3/2), x, 4, -((2*b^2*(5*A + 3*C)*EllipticE[(1/2)*(c + d*x), 2])/(5*d*Sqrt[Cos[c + d*x]]*Sqrt[b*Sec[c + d*x]])) + (2*b*(5*A + 3*C)*Sqrt[b*Sec[c + d*x]]*Sin[c + d*x])/(5*d) + (2*C*(b*Sec[c + d*x])^(3/2)*Tan[c + d*x])/(5*d)}
{Sec[c + d*x]^0*(A + C*Sec[c + d*x]^2)*(b*Sec[c + d*x])^(1/2), x, 3, (2*(3*A + C)*Sqrt[Cos[c + d*x]]*EllipticF[(1/2)*(c + d*x), 2]*Sqrt[b*Sec[c + d*x]])/(3*d) + (2*C*Sqrt[b*Sec[c + d*x]]*Tan[c + d*x])/(3*d)}


(* ::Subsubsection::Closed:: *)
(*n<0*)


{Sec[c + d*x]^0*(A + C*Sec[c + d*x]^2)/(b*Sec[c + d*x])^(1/2), x, 3, (2*(A - C)*EllipticE[(1/2)*(c + d*x), 2])/(d*Sqrt[Cos[c + d*x]]*Sqrt[b*Sec[c + d*x]]) + (2*C*Tan[c + d*x])/(d*Sqrt[b*Sec[c + d*x]])}
{Sec[c + d*x]^0*(A + C*Sec[c + d*x]^2)/(b*Sec[c + d*x])^(3/2), x, 3, (2*(A + 3*C)*Sqrt[Cos[c + d*x]]*EllipticF[(1/2)*(c + d*x), 2]*Sqrt[b*Sec[c + d*x]])/(3*b^2*d) + (2*A*Tan[c + d*x])/(3*d*(b*Sec[c + d*x])^(3/2))}
{Sec[c + d*x]^0*(A + C*Sec[c + d*x]^2)/(b*Sec[c + d*x])^(5/2), x, 3, (2*(3*A + 5*C)*EllipticE[(1/2)*(c + d*x), 2])/(5*b^2*d*Sqrt[Cos[c + d*x]]*Sqrt[b*Sec[c + d*x]]) + (2*A*Tan[c + d*x])/(5*d*(b*Sec[c + d*x])^(5/2))}
{Sec[c + d*x]^0*(A + C*Sec[c + d*x]^2)/(b*Sec[c + d*x])^(7/2), x, 4, (2*(5*A + 7*C)*Sqrt[Cos[c + d*x]]*EllipticF[(1/2)*(c + d*x), 2]*Sqrt[b*Sec[c + d*x]])/(21*b^4*d) + (2*(5*A + 7*C)*Sin[c + d*x])/(21*b^3*d*Sqrt[b*Sec[c + d*x]]) + (2*A*Tan[c + d*x])/(7*d*(b*Sec[c + d*x])^(7/2))}


(* ::Subsection:: *)
(*Integrands of the form Sec[c+d x]^(m/2) (A+C Sec[c+d x]^2) (b Sec[c+d x])^(n/2)*)


(* ::Subsection::Closed:: *)
(*Integrands of the form Sec[c+d x]^m (A+C Sec[c+d x]^2) (b Sec[c+d x])^(n/3)*)


(* ::Subsubsection::Closed:: *)
(*n>0*)


{Sec[c + d*x]^m*(b*Sec[c + d*x])^(1/3)*(A + C*Sec[c + d*x]^2), x, 4, ((C + 3*C*m + A*(4 + 3*m))*(Cos[c + d*x]^2)^((-2 + 3*m)/6)*Hypergeometric2F1[1/2, (4 + 3*m)/6, 3/2, Sin[c + d*x]^2]*Sec[c + d*x]^(-1 + m)*(b*Sec[c + d*x])^(1/3)*Sin[c + d*x])/(d*(4 + 3*m)) + (3*C*Sec[c + d*x]^(1 + m)*(b*Sec[c + d*x])^(1/3)*Sin[c + d*x])/(d*(4 + 3*m))}

{Sec[c + d*x]^2*(b*Sec[c + d*x])^(1/3)*(A + C*Sec[c + d*x]^2), x, 5, (b*(10*A + 7*C)*Hypergeometric2F1[1/2, 2/3, 3/2, Sin[c + d*x]^2]*Sin[c + d*x])/(40*d*(Cos[c + d*x]^2)^(1/3)*(b*Sec[c + d*x])^(2/3)) + (3*(10*A + 7*C)*(b*Sec[c + d*x])^(4/3)*Sin[c + d*x])/(40*b*d) + (3*C*(b*Sec[c + d*x])^(7/3)*Tan[c + d*x])/(10*b^2*d)}
{Sec[c + d*x]*(b*Sec[c + d*x])^(1/3)*(A + C*Sec[c + d*x]^2), x, 5, (3*(7*A + 4*C)*(b*Sec[c + d*x])^(1/3)*Sin[c + d*x])/(7*d) - (2*(7*A + 4*C)*(Cos[c + d*x]^2)^(1/6)*Hypergeometric2F1[1/6, 1/2, 3/2, Sin[c + d*x]^2]*(b*Sec[c + d*x])^(1/3)*Sin[c + d*x])/(7*d) + (3*C*(b*Sec[c + d*x])^(4/3)*Tan[c + d*x])/(7*b*d)}
{(b*Sec[c + d*x])^(1/3)*(A + C*Sec[c + d*x]^2), x, 3, (b*(4*A + C)*Hypergeometric2F1[1/2, 2/3, 3/2, Sin[c + d*x]^2]*Sin[c + d*x])/(4*d*(Cos[c + d*x]^2)^(1/3)*(b*Sec[c + d*x])^(2/3)) + (3*C*(b*Sec[c + d*x])^(1/3)*Tan[c + d*x])/(4*d)}
{Cos[c + d*x]*(b*Sec[c + d*x])^(1/3)*(A + C*Sec[c + d*x]^2), x, 4, ((A - 2*C)*(Cos[c + d*x]^2)^(1/6)*Hypergeometric2F1[1/6, 1/2, 3/2, Sin[c + d*x]^2]*(b*Sec[c + d*x])^(1/3)*Sin[c + d*x])/d + (3*b*C*Tan[c + d*x])/(d*(b*Sec[c + d*x])^(2/3))}
{Cos[c + d*x]^2*(b*Sec[c + d*x])^(1/3)*(A + C*Sec[c + d*x]^2), x, 4, (b*(2*A + 5*C)*Hypergeometric2F1[1/2, 2/3, 3/2, Sin[c + d*x]^2]*Sin[c + d*x])/(5*d*(Cos[c + d*x]^2)^(1/3)*(b*Sec[c + d*x])^(2/3)) + (3*A*b^2*Tan[c + d*x])/(5*d*(b*Sec[c + d*x])^(5/3))}
{Cos[c + d*x]^3*(b*Sec[c + d*x])^(1/3)*(A + C*Sec[c + d*x]^2), x, 4, ((5*A + 8*C)*(Cos[c + d*x]^2)^(1/6)*Hypergeometric2F1[1/6, 1/2, 3/2, Sin[c + d*x]^2]*(b*Sec[c + d*x])^(1/3)*Sin[c + d*x])/(8*d) + (3*A*b^3*Tan[c + d*x])/(8*d*(b*Sec[c + d*x])^(8/3))}


{Sec[c + d*x]^m*(b*Sec[c + d*x])^(2/3)*(A + C*Sec[c + d*x]^2), x, 4, ((3*A + (A + C)*(2 + 3*m))*(Cos[c + d*x]^2)^((-1 + 3*m)/6)*Hypergeometric2F1[1/2, (5 + 3*m)/6, 3/2, Sin[c + d*x]^2]*Sec[c + d*x]^(-1 + m)*(b*Sec[c + d*x])^(2/3)*Sin[c + d*x])/(d*(5 + 3*m)) + (3*C*Sec[c + d*x]^(1 + m)*(b*Sec[c + d*x])^(2/3)*Sin[c + d*x])/(d*(5 + 3*m))}

{Sec[c + d*x]^2*(b*Sec[c + d*x])^(2/3)*(A + C*Sec[c + d*x]^2), x, 5, (2*b*(11*A + 8*C)*Hypergeometric2F1[1/2, 5/6, 3/2, Sin[c + d*x]^2]*Sin[c + d*x])/(55*d*(Cos[c + d*x]^2)^(1/6)*(b*Sec[c + d*x])^(1/3)) + (3*(11*A + 8*C)*(b*Sec[c + d*x])^(5/3)*Sin[c + d*x])/(55*b*d) + (3*C*(b*Sec[c + d*x])^(8/3)*Tan[c + d*x])/(11*b^2*d)}
{Sec[c + d*x]*(b*Sec[c + d*x])^(2/3)*(A + C*Sec[c + d*x]^2), x, 5, (3*(8*A + 5*C)*(b*Sec[c + d*x])^(2/3)*Sin[c + d*x])/(16*d) - ((8*A + 5*C)*(Cos[c + d*x]^2)^(1/3)*Hypergeometric2F1[1/3, 1/2, 3/2, Sin[c + d*x]^2]*(b*Sec[c + d*x])^(2/3)*Sin[c + d*x])/(16*d) + (3*C*(b*Sec[c + d*x])^(5/3)*Tan[c + d*x])/(8*b*d)}
{(b*Sec[c + d*x])^(2/3)*(A + C*Sec[c + d*x]^2), x, 3, (b*(5*A + 2*C)*Hypergeometric2F1[1/2, 5/6, 3/2, Sin[c + d*x]^2]*Sin[c + d*x])/(5*d*(Cos[c + d*x]^2)^(1/6)*(b*Sec[c + d*x])^(1/3)) + (3*C*(b*Sec[c + d*x])^(2/3)*Tan[c + d*x])/(5*d)}
{Cos[c + d*x]*(b*Sec[c + d*x])^(2/3)*(A + C*Sec[c + d*x]^2), x, 4, ((2*A - C)*(Cos[c + d*x]^2)^(1/3)*Hypergeometric2F1[1/3, 1/2, 3/2, Sin[c + d*x]^2]*(b*Sec[c + d*x])^(2/3)*Sin[c + d*x])/(2*d) + (3*b*C*Tan[c + d*x])/(2*d*(b*Sec[c + d*x])^(1/3))}
{Cos[c + d*x]^2*(b*Sec[c + d*x])^(2/3)*(A + C*Sec[c + d*x]^2), x, 4, (b*(A + 4*C)*Hypergeometric2F1[1/2, 5/6, 3/2, Sin[c + d*x]^2]*Sin[c + d*x])/(4*d*(Cos[c + d*x]^2)^(1/6)*(b*Sec[c + d*x])^(1/3)) + (3*A*b^2*Tan[c + d*x])/(4*d*(b*Sec[c + d*x])^(4/3))}
{Cos[c + d*x]^3*(b*Sec[c + d*x])^(2/3)*(A + C*Sec[c + d*x]^2), x, 4, ((4*A + 7*C)*(Cos[c + d*x]^2)^(1/3)*Hypergeometric2F1[1/3, 1/2, 3/2, Sin[c + d*x]^2]*(b*Sec[c + d*x])^(2/3)*Sin[c + d*x])/(7*d) + (3*A*b^3*Tan[c + d*x])/(7*d*(b*Sec[c + d*x])^(7/3))}


{Sec[c + d*x]^m*(b*Sec[c + d*x])^(4/3)*(A + C*Sec[c + d*x]^2), x, 4, ((3*A + (A + C)*(4 + 3*m))*(Cos[c + d*x]^2)^((1 + 3*m)/6)*Hypergeometric2F1[1/2, (7 + 3*m)/6, 3/2, Sin[c + d*x]^2]*Sec[c + d*x]^(-1 + m)*(b*Sec[c + d*x])^(4/3)*Sin[c + d*x])/(d*(7 + 3*m)) + (3*C*Sec[c + d*x]^(1 + m)*(b*Sec[c + d*x])^(4/3)*Sin[c + d*x])/(d*(7 + 3*m))}

{Sec[c + d*x]^2*(b*Sec[c + d*x])^(4/3)*(A + C*Sec[c + d*x]^2), x, 6, (12*b*(13*A + 10*C)*(b*Sec[c + d*x])^(1/3)*Sin[c + d*x])/(91*d) - (8*b*(13*A + 10*C)*(Cos[c + d*x]^2)^(1/6)*Hypergeometric2F1[1/6, 1/2, 3/2, Sin[c + d*x]^2]*(b*Sec[c + d*x])^(1/3)*Sin[c + d*x])/(91*d) + (3*(13*A + 10*C)*(b*Sec[c + d*x])^(7/3)*Sin[c + d*x])/(91*b*d) + (3*C*(b*Sec[c + d*x])^(10/3)*Tan[c + d*x])/(13*b^2*d)}
{Sec[c + d*x]*(b*Sec[c + d*x])^(4/3)*(A + C*Sec[c + d*x]^2), x, 5, (b^2*(10*A + 7*C)*Hypergeometric2F1[1/2, 2/3, 3/2, Sin[c + d*x]^2]*Sin[c + d*x])/(40*d*(Cos[c + d*x]^2)^(1/3)*(b*Sec[c + d*x])^(2/3)) + (3*(10*A + 7*C)*(b*Sec[c + d*x])^(4/3)*Sin[c + d*x])/(40*d) + (3*C*(b*Sec[c + d*x])^(7/3)*Tan[c + d*x])/(10*b*d)}
{(b*Sec[c + d*x])^(4/3)*(A + C*Sec[c + d*x]^2), x, 4, (3*b*(7*A + 4*C)*(b*Sec[c + d*x])^(1/3)*Sin[c + d*x])/(7*d) - (2*b*(7*A + 4*C)*(Cos[c + d*x]^2)^(1/6)*Hypergeometric2F1[1/6, 1/2, 3/2, Sin[c + d*x]^2]*(b*Sec[c + d*x])^(1/3)*Sin[c + d*x])/(7*d) + (3*C*(b*Sec[c + d*x])^(4/3)*Tan[c + d*x])/(7*d)}
{Cos[c + d*x]*(b*Sec[c + d*x])^(4/3)*(A + C*Sec[c + d*x]^2), x, 4, (b^2*(4*A + C)*Hypergeometric2F1[1/2, 2/3, 3/2, Sin[c + d*x]^2]*Sin[c + d*x])/(4*d*(Cos[c + d*x]^2)^(1/3)*(b*Sec[c + d*x])^(2/3)) + (3*b*C*(b*Sec[c + d*x])^(1/3)*Tan[c + d*x])/(4*d)}
{Cos[c + d*x]^2*(b*Sec[c + d*x])^(4/3)*(A + C*Sec[c + d*x]^2), x, 4, (b*(A - 2*C)*(Cos[c + d*x]^2)^(1/6)*Hypergeometric2F1[1/6, 1/2, 3/2, Sin[c + d*x]^2]*(b*Sec[c + d*x])^(1/3)*Sin[c + d*x])/d + (3*b^2*C*Tan[c + d*x])/(d*(b*Sec[c + d*x])^(2/3))}
{Cos[c + d*x]^3*(b*Sec[c + d*x])^(4/3)*(A + C*Sec[c + d*x]^2), x, 4, (b^2*(2*A + 5*C)*Hypergeometric2F1[1/2, 2/3, 3/2, Sin[c + d*x]^2]*Sin[c + d*x])/(5*d*(Cos[c + d*x]^2)^(1/3)*(b*Sec[c + d*x])^(2/3)) + (3*A*b^3*Tan[c + d*x])/(5*d*(b*Sec[c + d*x])^(5/3))}


(* ::Subsubsection::Closed:: *)
(*n<0*)


{(Sec[c + d*x]^m*(A + C*Sec[c + d*x]^2))/(b*Sec[c + d*x])^(1/3), x, 4, (3*C*Sec[c + d*x]^(1 + m)*Sin[c + d*x])/(d*(2 + 3*m)*(b*Sec[c + d*x])^(1/3)) - ((C*(1 - 3*m) - A*(2 + 3*m))*(Cos[c + d*x]^2)^((2 + 3*m)/6)*Hypergeometric2F1[1/2, (2 + 3*m)/6, 3/2, Sin[c + d*x]^2]*Sec[c + d*x]^(1 + m)*Sin[c + d*x])/(d*(2 + 3*m)*(b*Sec[c + d*x])^(1/3))}

{(Sec[c + d*x]^2*(A + C*Sec[c + d*x]^2))/(b*Sec[c + d*x])^(1/3), x, 5, (3*(8*A + 5*C)*(b*Sec[c + d*x])^(2/3)*Sin[c + d*x])/(16*b*d) - ((8*A + 5*C)*(Cos[c + d*x]^2)^(1/3)*Hypergeometric2F1[1/3, 1/2, 3/2, Sin[c + d*x]^2]*(b*Sec[c + d*x])^(2/3)*Sin[c + d*x])/(16*b*d) + (3*C*(b*Sec[c + d*x])^(5/3)*Tan[c + d*x])/(8*b^2*d)}
{(Sec[c + d*x]*(A + C*Sec[c + d*x]^2))/(b*Sec[c + d*x])^(1/3), x, 4, ((5*A + 2*C)*Hypergeometric2F1[1/2, 5/6, 3/2, Sin[c + d*x]^2]*Sin[c + d*x])/(5*d*(Cos[c + d*x]^2)^(1/6)*(b*Sec[c + d*x])^(1/3)) + (3*C*(b*Sec[c + d*x])^(2/3)*Tan[c + d*x])/(5*b*d)}
{(A + C*Sec[c + d*x]^2)/(b*Sec[c + d*x])^(1/3), x, 3, ((2*A - C)*(Cos[c + d*x]^2)^(1/3)*Hypergeometric2F1[1/3, 1/2, 3/2, Sin[c + d*x]^2]*(b*Sec[c + d*x])^(2/3)*Sin[c + d*x])/(2*b*d) + (3*C*Tan[c + d*x])/(2*d*(b*Sec[c + d*x])^(1/3))}
{(Sec[c + d*x]*(A + C*Sec[c + d*x]^2))/(b*Sec[c + d*x])^(1/3), x, 4, ((5*A + 2*C)*Hypergeometric2F1[1/2, 5/6, 3/2, Sin[c + d*x]^2]*Sin[c + d*x])/(5*d*(Cos[c + d*x]^2)^(1/6)*(b*Sec[c + d*x])^(1/3)) + (3*C*(b*Sec[c + d*x])^(2/3)*Tan[c + d*x])/(5*b*d)}
{(Sec[c + d*x]^2*(A + C*Sec[c + d*x]^2))/(b*Sec[c + d*x])^(1/3), x, 5, (3*(8*A + 5*C)*(b*Sec[c + d*x])^(2/3)*Sin[c + d*x])/(16*b*d) - ((8*A + 5*C)*(Cos[c + d*x]^2)^(1/3)*Hypergeometric2F1[1/3, 1/2, 3/2, Sin[c + d*x]^2]*(b*Sec[c + d*x])^(2/3)*Sin[c + d*x])/(16*b*d) + (3*C*(b*Sec[c + d*x])^(5/3)*Tan[c + d*x])/(8*b^2*d)}
{(Sec[c + d*x]^3*(A + C*Sec[c + d*x]^2))/(b*Sec[c + d*x])^(1/3), x, 5, (2*(11*A + 8*C)*Hypergeometric2F1[1/2, 5/6, 3/2, Sin[c + d*x]^2]*Sin[c + d*x])/(55*d*(Cos[c + d*x]^2)^(1/6)*(b*Sec[c + d*x])^(1/3)) + (3*(11*A + 8*C)*(b*Sec[c + d*x])^(5/3)*Sin[c + d*x])/(55*b^2*d) + (3*C*(b*Sec[c + d*x])^(8/3)*Tan[c + d*x])/(11*b^3*d)}


{(Sec[c + d*x]^m*(A + C*Sec[c + d*x]^2))/(b*Sec[c + d*x])^(2/3), x, 4, (3*C*Sec[c + d*x]^(1 + m)*Sin[c + d*x])/(d*(1 + 3*m)*(b*Sec[c + d*x])^(2/3)) + ((A - C*(2 - 3*m) + 3*A*m)*(Cos[c + d*x]^2)^((1 + 3*m)/6)*Hypergeometric2F1[1/2, (1 + 3*m)/6, 3/2, Sin[c + d*x]^2]*Sec[c + d*x]^(1 + m)*Sin[c + d*x])/(d*(1 + 3*m)*(b*Sec[c + d*x])^(2/3))}

{(Sec[c + d*x]^2*(A + C*Sec[c + d*x]^2))/(b*Sec[c + d*x])^(2/3), x, 5, (3*(7*A + 4*C)*(b*Sec[c + d*x])^(1/3)*Sin[c + d*x])/(7*b*d) - (2*(7*A + 4*C)*(Cos[c + d*x]^2)^(1/6)*Hypergeometric2F1[1/6, 1/2, 3/2, Sin[c + d*x]^2]*(b*Sec[c + d*x])^(1/3)*Sin[c + d*x])/(7*b*d) + (3*C*(b*Sec[c + d*x])^(4/3)*Tan[c + d*x])/(7*b^2*d)}
{(Sec[c + d*x]*(A + C*Sec[c + d*x]^2))/(b*Sec[c + d*x])^(2/3), x, 4, ((4*A + C)*Hypergeometric2F1[1/2, 2/3, 3/2, Sin[c + d*x]^2]*Sin[c + d*x])/(4*d*(Cos[c + d*x]^2)^(1/3)*(b*Sec[c + d*x])^(2/3)) + (3*C*(b*Sec[c + d*x])^(1/3)*Tan[c + d*x])/(4*b*d)}
{(A + C*Sec[c + d*x]^2)/(b*Sec[c + d*x])^(2/3), x, 3, ((A - 2*C)*(Cos[c + d*x]^2)^(1/6)*Hypergeometric2F1[1/6, 1/2, 3/2, Sin[c + d*x]^2]*(b*Sec[c + d*x])^(1/3)*Sin[c + d*x])/(b*d) + (3*C*Tan[c + d*x])/(d*(b*Sec[c + d*x])^(2/3))}
{(Sec[c + d*x]*(A + C*Sec[c + d*x]^2))/(b*Sec[c + d*x])^(2/3), x, 4, ((4*A + C)*Hypergeometric2F1[1/2, 2/3, 3/2, Sin[c + d*x]^2]*Sin[c + d*x])/(4*d*(Cos[c + d*x]^2)^(1/3)*(b*Sec[c + d*x])^(2/3)) + (3*C*(b*Sec[c + d*x])^(1/3)*Tan[c + d*x])/(4*b*d)}
{(Sec[c + d*x]^2*(A + C*Sec[c + d*x]^2))/(b*Sec[c + d*x])^(2/3), x, 5, (3*(7*A + 4*C)*(b*Sec[c + d*x])^(1/3)*Sin[c + d*x])/(7*b*d) - (2*(7*A + 4*C)*(Cos[c + d*x]^2)^(1/6)*Hypergeometric2F1[1/6, 1/2, 3/2, Sin[c + d*x]^2]*(b*Sec[c + d*x])^(1/3)*Sin[c + d*x])/(7*b*d) + (3*C*(b*Sec[c + d*x])^(4/3)*Tan[c + d*x])/(7*b^2*d)}
{(Sec[c + d*x]^3*(A + C*Sec[c + d*x]^2))/(b*Sec[c + d*x])^(2/3), x, 5, ((10*A + 7*C)*Hypergeometric2F1[1/2, 2/3, 3/2, Sin[c + d*x]^2]*Sin[c + d*x])/(40*d*(Cos[c + d*x]^2)^(1/3)*(b*Sec[c + d*x])^(2/3)) + (3*(10*A + 7*C)*(b*Sec[c + d*x])^(4/3)*Sin[c + d*x])/(40*b^2*d) + (3*C*(b*Sec[c + d*x])^(7/3)*Tan[c + d*x])/(10*b^3*d)}


{(Sec[c + d*x]^m*(A + C*Sec[c + d*x]^2))/(b*Sec[c + d*x])^(4/3), x, 4, -(((3*A - (A + C)*(4 - 3*m))*(Cos[c + d*x]^2)^((-7 + 3*m)/6)*Hypergeometric2F1[1/2, (-1 + 3*m)/6, 3/2, Sin[c + d*x]^2]*Sec[c + d*x]^(-1 + m)*Sin[c + d*x])/(d*(1 - 3*m)*(b*Sec[c + d*x])^(4/3))) - (3*C*Sec[c + d*x]^(1 + m)*Sin[c + d*x])/(d*(1 - 3*m)*(b*Sec[c + d*x])^(4/3))}

{(Sec[c + d*x]^2*(A + C*Sec[c + d*x]^2))/(b*Sec[c + d*x])^(4/3), x, 4, ((5*A + 2*C)*Hypergeometric2F1[1/2, 5/6, 3/2, Sin[c + d*x]^2]*Sin[c + d*x])/(5*b*d*(Cos[c + d*x]^2)^(1/6)*(b*Sec[c + d*x])^(1/3)) + (3*C*(b*Sec[c + d*x])^(2/3)*Tan[c + d*x])/(5*b^2*d)}
{(Sec[c + d*x]*(A + C*Sec[c + d*x]^2))/(b*Sec[c + d*x])^(4/3), x, 4, ((2*A - C)*(Cos[c + d*x]^2)^(1/3)*Hypergeometric2F1[1/3, 1/2, 3/2, Sin[c + d*x]^2]*(b*Sec[c + d*x])^(2/3)*Sin[c + d*x])/(2*b^2*d) + (3*C*Tan[c + d*x])/(2*b*d*(b*Sec[c + d*x])^(1/3))}
{(A + C*Sec[c + d*x]^2)/(b*Sec[c + d*x])^(4/3), x, 3, ((A + 4*C)*Hypergeometric2F1[1/2, 5/6, 3/2, Sin[c + d*x]^2]*Sin[c + d*x])/(4*b*d*(Cos[c + d*x]^2)^(1/6)*(b*Sec[c + d*x])^(1/3)) + (3*A*Tan[c + d*x])/(4*d*(b*Sec[c + d*x])^(4/3))}
{(Sec[c + d*x]*(A + C*Sec[c + d*x]^2))/(b*Sec[c + d*x])^(4/3), x, 4, ((2*A - C)*(Cos[c + d*x]^2)^(1/3)*Hypergeometric2F1[1/3, 1/2, 3/2, Sin[c + d*x]^2]*(b*Sec[c + d*x])^(2/3)*Sin[c + d*x])/(2*b^2*d) + (3*C*Tan[c + d*x])/(2*b*d*(b*Sec[c + d*x])^(1/3))}
{(Sec[c + d*x]^2*(A + C*Sec[c + d*x]^2))/(b*Sec[c + d*x])^(4/3), x, 4, ((5*A + 2*C)*Hypergeometric2F1[1/2, 5/6, 3/2, Sin[c + d*x]^2]*Sin[c + d*x])/(5*b*d*(Cos[c + d*x]^2)^(1/6)*(b*Sec[c + d*x])^(1/3)) + (3*C*(b*Sec[c + d*x])^(2/3)*Tan[c + d*x])/(5*b^2*d)}
{(Sec[c + d*x]^3*(A + C*Sec[c + d*x]^2))/(b*Sec[c + d*x])^(4/3), x, 5, (3*(8*A + 5*C)*(b*Sec[c + d*x])^(2/3)*Sin[c + d*x])/(16*b^2*d) - ((8*A + 5*C)*(Cos[c + d*x]^2)^(1/3)*Hypergeometric2F1[1/3, 1/2, 3/2, Sin[c + d*x]^2]*(b*Sec[c + d*x])^(2/3)*Sin[c + d*x])/(16*b^2*d) + (3*C*(b*Sec[c + d*x])^(5/3)*Tan[c + d*x])/(8*b^3*d)}


(* ::Subsection::Closed:: *)
(*Integrands of the form Sec[c+d x]^m (A+C Sec[c+d x]^2) (b Sec[c+d x])^n when n symbolic*)


{Sec[c + d*x]^m*(b*Sec[c + d*x])^n*(A + C*Sec[c + d*x]^2), x, 4, ((A + (A + C)*(m + n))*(Cos[c + d*x]^2)^((-1 + m + n)/2)*Hypergeometric2F1[1/2, (1 + m + n)/2, 3/2, Sin[c + d*x]^2]*Sec[c + d*x]^(-1 + m)*(b*Sec[c + d*x])^n*Sin[c + d*x])/(d*(1 + m + n)) + (C*Sec[c + d*x]^(1 + m)*(b*Sec[c + d*x])^n*Sin[c + d*x])/(d*(1 + m + n))}

{Sec[c + d*x]^2*(b*Sec[c + d*x])^n*(A + C*Sec[c + d*x]^2), x, 4, ((A + (A + C)*(2 + n))*(Cos[c + d*x]^2)^((1 + n)/2)*Hypergeometric2F1[1/2, (3 + n)/2, 3/2, Sin[c + d*x]^2]*(b*Sec[c + d*x])^(1 + n)*Sin[c + d*x])/(b*d*(3 + n)) + (C*(b*Sec[c + d*x])^(2 + n)*Tan[c + d*x])/(b^2*d*(3 + n))}
{Sec[c + d*x]*(b*Sec[c + d*x])^n*(A + C*Sec[c + d*x]^2), x, 4, ((A + (A + C)*(1 + n))*(Cos[c + d*x]^2)^(n/2)*Hypergeometric2F1[1/2, (2 + n)/2, 3/2, Sin[c + d*x]^2]*(b*Sec[c + d*x])^n*Sin[c + d*x])/(d*(2 + n)) + (C*(b*Sec[c + d*x])^(1 + n)*Tan[c + d*x])/(b*d*(2 + n))}
{(b*Sec[c + d*x])^n*(A + C*Sec[c + d*x]^2), x, 3, (b*(A + (A + C)*n)*(Cos[c + d*x]^2)^((1/2)*(-1 + n))*Hypergeometric2F1[1/2, (1 + n)/2, 3/2, Sin[c + d*x]^2]*(b*Sec[c + d*x])^(-1 + n)*Sin[c + d*x])/(d*(1 + n)) + (C*(b*Sec[c + d*x])^n*Tan[c + d*x])/(d*(1 + n))}
{Cos[c + d*x]*(b*Sec[c + d*x])^n*(A + C*Sec[c + d*x]^2), x, 4, -((b^2*(C*(1 - n) - A*n)*(Cos[c + d*x]^2)^((1/2)*(-2 + n))*Hypergeometric2F1[1/2, n/2, 3/2, Sin[c + d*x]^2]*(b*Sec[c + d*x])^(-2 + n)*Sin[c + d*x])/(d*n)) + (b*C*(b*Sec[c + d*x])^(-1 + n)*Tan[c + d*x])/(d*n)}
{Cos[c + d*x]^2*(b*Sec[c + d*x])^n*(A + C*Sec[c + d*x]^2), x, 4, (b^3*(A*(1 - n) + C*(2 - n))*(Cos[c + d*x]^2)^((1/2)*(-3 + n))*Hypergeometric2F1[1/2, (1/2)*(-1 + n), 3/2, Sin[c + d*x]^2]*(b*Sec[c + d*x])^(-3 + n)*Sin[c + d*x])/(d*(1 - n)) - (b^2*C*(b*Sec[c + d*x])^(-2 + n)*Tan[c + d*x])/(d*(1 - n))}
{Cos[c + d*x]^3*(b*Sec[c + d*x])^n*(A + C*Sec[c + d*x]^2), x, 4, (b^4*(A*(2 - n) + C*(3 - n))*(Cos[c + d*x]^2)^((1/2)*(-4 + n))*Hypergeometric2F1[1/2, (1/2)*(-2 + n), 3/2, Sin[c + d*x]^2]*(b*Sec[c + d*x])^(-4 + n)*Sin[c + d*x])/(d*(2 - n)) - (b^3*C*(b*Sec[c + d*x])^(-3 + n)*Tan[c + d*x])/(d*(2 - n))}
{Cos[c + d*x]^4*(b*Sec[c + d*x])^n*(A + C*Sec[c + d*x]^2), x, 4, (b^5*(A*(3 - n) + C*(4 - n))*(Cos[c + d*x]^2)^((1/2)*(-5 + n))*Hypergeometric2F1[1/2, (1/2)*(-3 + n), 3/2, Sin[c + d*x]^2]*(b*Sec[c + d*x])^(-5 + n)*Sin[c + d*x])/(d*(3 - n)) - (b^4*C*(b*Sec[c + d*x])^(-4 + n)*Tan[c + d*x])/(d*(3 - n))}


{Sec[c + d*x]^(5/2)*(b*Sec[c + d*x])^n*(A + C*Sec[c + d*x]^2), x, 4, ((2*A + (A + C)*(5 + 2*n))*(Cos[c + d*x]^2)^((3 + 2*n)/4)*Hypergeometric2F1[1/2, (7 + 2*n)/4, 3/2, Sin[c + d*x]^2]*Sec[c + d*x]^(3/2)*(b*Sec[c + d*x])^n*Sin[c + d*x])/(d*(7 + 2*n)) + (2*C*Sec[c + d*x]^(7/2)*(b*Sec[c + d*x])^n*Sin[c + d*x])/(d*(7 + 2*n))}
{Sec[c + d*x]^(3/2)*(b*Sec[c + d*x])^n*(A + C*Sec[c + d*x]^2), x, 4, ((2*A + (A + C)*(3 + 2*n))*(Cos[c + d*x]^2)^((1 + 2*n)/4)*Hypergeometric2F1[1/2, (5 + 2*n)/4, 3/2, Sin[c + d*x]^2]*Sqrt[Sec[c + d*x]]*(b*Sec[c + d*x])^n*Sin[c + d*x])/(d*(5 + 2*n)) + (2*C*Sec[c + d*x]^(5/2)*(b*Sec[c + d*x])^n*Sin[c + d*x])/(d*(5 + 2*n))}
{Sqrt[Sec[c + d*x]]*(b*Sec[c + d*x])^n*(A + C*Sec[c + d*x]^2), x, 4, ((C + 2*C*n + A*(3 + 2*n))*(Cos[c + d*x]^2)^((-1 + 2*n)/4)*Hypergeometric2F1[1/2, (3 + 2*n)/4, 3/2, Sin[c + d*x]^2]*(b*Sec[c + d*x])^n*Sin[c + d*x])/(d*(3 + 2*n)*Sqrt[Sec[c + d*x]]) + (2*C*Sec[c + d*x]^(3/2)*(b*Sec[c + d*x])^n*Sin[c + d*x])/(d*(3 + 2*n))}
{((b*Sec[c + d*x])^n*(A + C*Sec[c + d*x]^2))/Sqrt[Sec[c + d*x]], x, 4, (2*C*Sqrt[Sec[c + d*x]]*(b*Sec[c + d*x])^n*Sin[c + d*x])/(d*(1 + 2*n)) + ((A - C*(1 - 2*n) + 2*A*n)*(Cos[c + d*x]^2)^((1 + 2*n)/4)*Hypergeometric2F1[1/2, (1 + 2*n)/4, 3/2, Sin[c + d*x]^2]*Sqrt[Sec[c + d*x]]*(b*Sec[c + d*x])^n*Sin[c + d*x])/(d*(1 + 2*n))}
{((b*Sec[c + d*x])^n*(A + C*Sec[c + d*x]^2))/Sec[c + d*x]^(3/2), x, 4, -(((2*A - (A + C)*(3 - 2*n))*(Cos[c + d*x]^2)^((-5 + 2*n)/4)*Hypergeometric2F1[1/2, (-1 + 2*n)/4, 3/2, Sin[c + d*x]^2]*(b*Sec[c + d*x])^n*Sin[c + d*x])/(d*(1 - 2*n)*Sec[c + d*x]^(5/2))) - (2*C*(b*Sec[c + d*x])^n*Sin[c + d*x])/(d*(1 - 2*n)*Sqrt[Sec[c + d*x]])}
{((b*Sec[c + d*x])^n*(A + C*Sec[c + d*x]^2))/Sec[c + d*x]^(5/2), x, 4, -(((2*A - (A + C)*(5 - 2*n))*(Cos[c + d*x]^2)^((-7 + 2*n)/4)*Hypergeometric2F1[1/2, (-3 + 2*n)/4, 3/2, Sin[c + d*x]^2]*(b*Sec[c + d*x])^n*Sin[c + d*x])/(d*(3 - 2*n)*Sec[c + d*x]^(7/2))) - (2*C*(b*Sec[c + d*x])^n*Sin[c + d*x])/(d*(3 - 2*n)*Sec[c + d*x]^(3/2))}
{((b*Sec[c + d*x])^n*(A + C*Sec[c + d*x]^2))/Sec[c + d*x]^(7/2), x, 4, -(((2*A - (A + C)*(7 - 2*n))*(Cos[c + d*x]^2)^((-9 + 2*n)/4)*Hypergeometric2F1[1/2, (-5 + 2*n)/4, 3/2, Sin[c + d*x]^2]*(b*Sec[c + d*x])^n*Sin[c + d*x])/(d*(5 - 2*n)*Sec[c + d*x]^(9/2))) - (2*C*(b*Sec[c + d*x])^n*Sin[c + d*x])/(d*(5 - 2*n)*Sec[c + d*x]^(5/2))}
{((b*Sec[c + d*x])^n*(A + C*Sec[c + d*x]^2))/Sec[c + d*x]^(9/2), x, 4, -(((2*A - (A + C)*(9 - 2*n))*(Cos[c + d*x]^2)^((-11 + 2*n)/4)*Hypergeometric2F1[1/2, (-7 + 2*n)/4, 3/2, Sin[c + d*x]^2]*(b*Sec[c + d*x])^n*Sin[c + d*x])/(d*(7 - 2*n)*Sec[c + d*x]^(11/2))) - (2*C*(b*Sec[c + d*x])^n*Sin[c + d*x])/(d*(7 - 2*n)*Sec[c + d*x]^(7/2))}


(* ::Section:: *)
(*Sec[c+d x]^m (B Sec[c+d x]+C Sec[c+d x]^2) (b Sec[c+d x])^(n/2)*)


(* ::Subsection::Closed:: *)
(*Integrands of the form Sec[c+d x]^m (B Sec[c+d x]+C Sec[c+d x]^2) (b Sec[c+d x])^(n/2)*)


(* ::Subsubsection::Closed:: *)
(*n>0*)


{Sec[c + d*x]^0*(B*Sec[c + d*x] + C*Sec[c + d*x]^2)*(b*Sec[c + d*x])^(3/2), x, 10, -((6*b^2*C*EllipticE[(1/2)*(c + d*x), 2])/(5*d*Sqrt[Cos[c + d*x]]*Sqrt[b*Sec[c + d*x]])) + (2*b*B*Sqrt[Cos[c + d*x]]*EllipticF[(1/2)*(c + d*x), 2]*Sqrt[b*Sec[c + d*x]])/(3*d) + (6*b*C*Sqrt[b*Sec[c + d*x]]*Sin[c + d*x])/(5*d) + (2*B*(b*Sec[c + d*x])^(3/2)*Sin[c + d*x])/(3*d) + (2*C*(b*Sec[c + d*x])^(5/2)*Sin[c + d*x])/(5*b*d)}
{Sec[c + d*x]^0*(B*Sec[c + d*x] + C*Sec[c + d*x]^2)*(b*Sec[c + d*x])^(1/2), x, 9, -((2*b*B*EllipticE[(1/2)*(c + d*x), 2])/(d*Sqrt[Cos[c + d*x]]*Sqrt[b*Sec[c + d*x]])) + (2*C*Sqrt[Cos[c + d*x]]*EllipticF[(1/2)*(c + d*x), 2]*Sqrt[b*Sec[c + d*x]])/(3*d) + (2*B*Sqrt[b*Sec[c + d*x]]*Sin[c + d*x])/d + (2*C*(b*Sec[c + d*x])^(3/2)*Sin[c + d*x])/(3*b*d)}


(* ::Subsubsection::Closed:: *)
(*n<0*)


{Sec[c + d*x]^0*(B*Sec[c + d*x] + C*Sec[c + d*x]^2)/(b*Sec[c + d*x])^(1/2), x, 8, -((2*C*EllipticE[(1/2)*(c + d*x), 2])/(d*Sqrt[Cos[c + d*x]]*Sqrt[b*Sec[c + d*x]])) + (2*B*Sqrt[Cos[c + d*x]]*EllipticF[(1/2)*(c + d*x), 2]*Sqrt[b*Sec[c + d*x]])/(b*d) + (2*C*Sqrt[b*Sec[c + d*x]]*Sin[c + d*x])/(b*d)}
{Sec[c + d*x]^0*(B*Sec[c + d*x] + C*Sec[c + d*x]^2)/(b*Sec[c + d*x])^(3/2), x, 7, (2*B*EllipticE[(1/2)*(c + d*x), 2])/(b*d*Sqrt[Cos[c + d*x]]*Sqrt[b*Sec[c + d*x]]) + (2*C*Sqrt[Cos[c + d*x]]*EllipticF[(1/2)*(c + d*x), 2]*Sqrt[b*Sec[c + d*x]])/(b^2*d)}
{Sec[c + d*x]^0*(B*Sec[c + d*x] + C*Sec[c + d*x]^2)/(b*Sec[c + d*x])^(5/2), x, 8, (2*C*EllipticE[(1/2)*(c + d*x), 2])/(b^2*d*Sqrt[Cos[c + d*x]]*Sqrt[b*Sec[c + d*x]]) + (2*B*Sqrt[Cos[c + d*x]]*EllipticF[(1/2)*(c + d*x), 2]*Sqrt[b*Sec[c + d*x]])/(3*b^3*d) + (2*B*Sin[c + d*x])/(3*b^2*d*Sqrt[b*Sec[c + d*x]])}
{Sec[c + d*x]^0*(B*Sec[c + d*x] + C*Sec[c + d*x]^2)/(b*Sec[c + d*x])^(7/2), x, 9, (6*B*EllipticE[(1/2)*(c + d*x), 2])/(5*b^3*d*Sqrt[Cos[c + d*x]]*Sqrt[b*Sec[c + d*x]]) + (2*C*Sqrt[Cos[c + d*x]]*EllipticF[(1/2)*(c + d*x), 2]*Sqrt[b*Sec[c + d*x]])/(3*b^4*d) + (2*B*Sin[c + d*x])/(5*b^2*d*(b*Sec[c + d*x])^(3/2)) + (2*C*Sin[c + d*x])/(3*b^3*d*Sqrt[b*Sec[c + d*x]])}


(* ::Subsection:: *)
(*Integrands of the form Sec[c+d x]^(m/2) (B Sec[c+d x]+C Sec[c+d x]^2) (b Sec[c+d x])^(n/2)*)


(* ::Subsection::Closed:: *)
(*Integrands of the form Sec[c+d x]^m (B Sec[c+d x]+C Sec[c+d x]^2) (b Sec[c+d x])^n when n symbolic*)


{Sec[c + d*x]^m*(b*Sec[c + d*x])^n*(B*Sec[c + d*x] + C*Sec[c + d*x]^2), x, 7, (B*(Cos[c + d*x]^2)^((m + n)/2)*Hypergeometric2F1[1/2, (2 + m + n)/2, 3/2, Sin[c + d*x]^2]*Sec[c + d*x]^m*(b*Sec[c + d*x])^n*Sin[c + d*x])/d + (C*(Cos[c + d*x]^2)^((1 + m + n)/2)*Hypergeometric2F1[1/2, (3 + m + n)/2, 3/2, Sin[c + d*x]^2]*Sec[c + d*x]^(1 + m)*(b*Sec[c + d*x])^n*Sin[c + d*x])/d}

{Sec[c + d*x]^2*(b*Sec[c + d*x])^n*(B*Sec[c + d*x] + C*Sec[c + d*x]^2), x, 7, (B*(Cos[c + d*x]^2)^((2 + n)/2)*Hypergeometric2F1[1/2, (4 + n)/2, 3/2, Sin[c + d*x]^2]*(b*Sec[c + d*x])^(2 + n)*Sin[c + d*x])/(b^2*d) + (C*(Cos[c + d*x]^2)^((3 + n)/2)*Hypergeometric2F1[1/2, (5 + n)/2, 3/2, Sin[c + d*x]^2]*(b*Sec[c + d*x])^(3 + n)*Sin[c + d*x])/(b^3*d)}
{Sec[c + d*x]*(b*Sec[c + d*x])^n*(B*Sec[c + d*x] + C*Sec[c + d*x]^2), x, 7, (B*(Cos[c + d*x]^2)^((1 + n)/2)*Hypergeometric2F1[1/2, (3 + n)/2, 3/2, Sin[c + d*x]^2]*(b*Sec[c + d*x])^(1 + n)*Sin[c + d*x])/(b*d) + (C*(Cos[c + d*x]^2)^((2 + n)/2)*Hypergeometric2F1[1/2, (4 + n)/2, 3/2, Sin[c + d*x]^2]*(b*Sec[c + d*x])^(2 + n)*Sin[c + d*x])/(b^2*d)}
{(b*Sec[c + d*x])^n*(B*Sec[c + d*x] + C*Sec[c + d*x]^2), x, 7, (B*(Cos[c + d*x]^2)^(n/2)*Hypergeometric2F1[1/2, (2 + n)/2, 3/2, Sin[c + d*x]^2]*(b*Sec[c + d*x])^n*Sin[c + d*x])/d + (C*(Cos[c + d*x]^2)^((1 + n)/2)*Hypergeometric2F1[1/2, (3 + n)/2, 3/2, Sin[c + d*x]^2]*(b*Sec[c + d*x])^(1 + n)*Sin[c + d*x])/(b*d)}
{Cos[c + d*x]*(b*Sec[c + d*x])^n*(B*Sec[c + d*x] + C*Sec[c + d*x]^2), x, 6, (b*B*(Cos[c + d*x]^2)^((1/2)*(-1 + n))*Hypergeometric2F1[1/2, (1 + n)/2, 3/2, Sin[c + d*x]^2]*(b*Sec[c + d*x])^(-1 + n)*Sin[c + d*x])/d + (C*(Cos[c + d*x]^2)^(n/2)*Hypergeometric2F1[1/2, (2 + n)/2, 3/2, Sin[c + d*x]^2]*(b*Sec[c + d*x])^n*Sin[c + d*x])/d}
{Cos[c + d*x]^2*(b*Sec[c + d*x])^n*(B*Sec[c + d*x] + C*Sec[c + d*x]^2), x, 7, (b^2*B*(Cos[c + d*x]^2)^((1/2)*(-2 + n))*Hypergeometric2F1[1/2, n/2, 3/2, Sin[c + d*x]^2]*(b*Sec[c + d*x])^(-2 + n)*Sin[c + d*x])/d + (b*C*(Cos[c + d*x]^2)^((1/2)*(-1 + n))*Hypergeometric2F1[1/2, (1 + n)/2, 3/2, Sin[c + d*x]^2]*(b*Sec[c + d*x])^(-1 + n)*Sin[c + d*x])/d}
{Cos[c + d*x]^3*(b*Sec[c + d*x])^n*(B*Sec[c + d*x] + C*Sec[c + d*x]^2), x, 7, (b^3*B*(Cos[c + d*x]^2)^((1/2)*(-3 + n))*Hypergeometric2F1[1/2, (1/2)*(-1 + n), 3/2, Sin[c + d*x]^2]*(b*Sec[c + d*x])^(-3 + n)*Sin[c + d*x])/d + (b^2*C*(Cos[c + d*x]^2)^((1/2)*(-2 + n))*Hypergeometric2F1[1/2, n/2, 3/2, Sin[c + d*x]^2]*(b*Sec[c + d*x])^(-2 + n)*Sin[c + d*x])/d}
{Cos[c + d*x]^4*(b*Sec[c + d*x])^n*(B*Sec[c + d*x] + C*Sec[c + d*x]^2), x, 7, (b^4*B*(Cos[c + d*x]^2)^((1/2)*(-4 + n))*Hypergeometric2F1[1/2, (1/2)*(-2 + n), 3/2, Sin[c + d*x]^2]*(b*Sec[c + d*x])^(-4 + n)*Sin[c + d*x])/d + (b^3*C*(Cos[c + d*x]^2)^((1/2)*(-3 + n))*Hypergeometric2F1[1/2, (1/2)*(-1 + n), 3/2, Sin[c + d*x]^2]*(b*Sec[c + d*x])^(-3 + n)*Sin[c + d*x])/d}


{Sec[c + d*x]^(5/2)*(b*Sec[c + d*x])^n*(B*Sec[c + d*x] + C*Sec[c + d*x]^2), x, 7, (B*(Cos[c + d*x]^2)^((5 + 2*n)/4)*Hypergeometric2F1[1/2, (9 + 2*n)/4, 3/2, Sin[c + d*x]^2]*Sec[c + d*x]^(5/2)*(b*Sec[c + d*x])^n*Sin[c + d*x])/d + (C*(Cos[c + d*x]^2)^((7 + 2*n)/4)*Hypergeometric2F1[1/2, (11 + 2*n)/4, 3/2, Sin[c + d*x]^2]*Sec[c + d*x]^(7/2)*(b*Sec[c + d*x])^n*Sin[c + d*x])/d}
{Sec[c + d*x]^(3/2)*(b*Sec[c + d*x])^n*(B*Sec[c + d*x] + C*Sec[c + d*x]^2), x, 7, (B*(Cos[c + d*x]^2)^((3 + 2*n)/4)*Hypergeometric2F1[1/2, (7 + 2*n)/4, 3/2, Sin[c + d*x]^2]*Sec[c + d*x]^(3/2)*(b*Sec[c + d*x])^n*Sin[c + d*x])/d + (C*(Cos[c + d*x]^2)^((5 + 2*n)/4)*Hypergeometric2F1[1/2, (9 + 2*n)/4, 3/2, Sin[c + d*x]^2]*Sec[c + d*x]^(5/2)*(b*Sec[c + d*x])^n*Sin[c + d*x])/d}
{Sqrt[Sec[c + d*x]]*(b*Sec[c + d*x])^n*(B*Sec[c + d*x] + C*Sec[c + d*x]^2), x, 7, (B*(Cos[c + d*x]^2)^((1 + 2*n)/4)*Hypergeometric2F1[1/2, (5 + 2*n)/4, 3/2, Sin[c + d*x]^2]*Sqrt[Sec[c + d*x]]*(b*Sec[c + d*x])^n*Sin[c + d*x])/d + (C*(Cos[c + d*x]^2)^((3 + 2*n)/4)*Hypergeometric2F1[1/2, (7 + 2*n)/4, 3/2, Sin[c + d*x]^2]*Sec[c + d*x]^(3/2)*(b*Sec[c + d*x])^n*Sin[c + d*x])/d}
{((b*Sec[c + d*x])^n*(B*Sec[c + d*x] + C*Sec[c + d*x]^2))/Sqrt[Sec[c + d*x]], x, 7, (B*(Cos[c + d*x]^2)^((-1 + 2*n)/4)*Hypergeometric2F1[1/2, (3 + 2*n)/4, 3/2, Sin[c + d*x]^2]*(b*Sec[c + d*x])^n*Sin[c + d*x])/(d*Sqrt[Sec[c + d*x]]) + (C*(Cos[c + d*x]^2)^((1 + 2*n)/4)*Hypergeometric2F1[1/2, (5 + 2*n)/4, 3/2, Sin[c + d*x]^2]*Sqrt[Sec[c + d*x]]*(b*Sec[c + d*x])^n*Sin[c + d*x])/d}
{((b*Sec[c + d*x])^n*(B*Sec[c + d*x] + C*Sec[c + d*x]^2))/Sec[c + d*x]^(3/2), x, 7, (C*(Cos[c + d*x]^2)^((-1 + 2*n)/4)*Hypergeometric2F1[1/2, (3 + 2*n)/4, 3/2, Sin[c + d*x]^2]*(b*Sec[c + d*x])^n*Sin[c + d*x])/(d*Sqrt[Sec[c + d*x]]) + (B*(Cos[c + d*x]^2)^((1 + 2*n)/4)*Hypergeometric2F1[1/2, (1 + 2*n)/4, 3/2, Sin[c + d*x]^2]*Sqrt[Sec[c + d*x]]*(b*Sec[c + d*x])^n*Sin[c + d*x])/d}
{((b*Sec[c + d*x])^n*(B*Sec[c + d*x] + C*Sec[c + d*x]^2))/Sec[c + d*x]^(5/2), x, 7, (B*(Cos[c + d*x]^2)^((-5 + 2*n)/4)*Hypergeometric2F1[1/2, (-1 + 2*n)/4, 3/2, Sin[c + d*x]^2]*(b*Sec[c + d*x])^n*Sin[c + d*x])/(d*Sec[c + d*x]^(5/2)) + (C*(Cos[c + d*x]^2)^((1 + 2*n)/4)*Hypergeometric2F1[1/2, (1 + 2*n)/4, 3/2, Sin[c + d*x]^2]*Sqrt[Sec[c + d*x]]*(b*Sec[c + d*x])^n*Sin[c + d*x])/d}
{((b*Sec[c + d*x])^n*(B*Sec[c + d*x] + C*Sec[c + d*x]^2))/Sec[c + d*x]^(7/2), x, 7, (B*(Cos[c + d*x]^2)^((-7 + 2*n)/4)*Hypergeometric2F1[1/2, (-3 + 2*n)/4, 3/2, Sin[c + d*x]^2]*(b*Sec[c + d*x])^n*Sin[c + d*x])/(d*Sec[c + d*x]^(7/2)) + (C*(Cos[c + d*x]^2)^((-5 + 2*n)/4)*Hypergeometric2F1[1/2, (-1 + 2*n)/4, 3/2, Sin[c + d*x]^2]*(b*Sec[c + d*x])^n*Sin[c + d*x])/(d*Sec[c + d*x]^(5/2))}
{((b*Sec[c + d*x])^n*(B*Sec[c + d*x] + C*Sec[c + d*x]^2))/Sec[c + d*x]^(9/2), x, 7, (B*(Cos[c + d*x]^2)^((-9 + 2*n)/4)*Hypergeometric2F1[1/2, (-5 + 2*n)/4, 3/2, Sin[c + d*x]^2]*(b*Sec[c + d*x])^n*Sin[c + d*x])/(d*Sec[c + d*x]^(9/2)) + (C*(Cos[c + d*x]^2)^((-7 + 2*n)/4)*Hypergeometric2F1[1/2, (-3 + 2*n)/4, 3/2, Sin[c + d*x]^2]*(b*Sec[c + d*x])^n*Sin[c + d*x])/(d*Sec[c + d*x]^(7/2))}


(* ::Section:: *)
(*Sec[c+d x]^m (A+B Sec[c+d x]+C Sec[c+d x]^2) (b Sec[c+d x])^(n/2)*)


(* ::Subsection::Closed:: *)
(*Integrands of the form Sec[c+d x]^m (A+B Sec[c+d x]+C Sec[c+d x]^2) (b Sec[c+d x])^(n/2)*)


(* ::Subsubsection::Closed:: *)
(*n>0*)


{Sec[c + d*x]^0*(A + B*Sec[c + d*x] + C*Sec[c + d*x]^2)*(b*Sec[c + d*x])^(3/2), x, 8, -((2*b^2*(5*A + 3*C)*EllipticE[(1/2)*(c + d*x), 2])/(5*d*Sqrt[Cos[c + d*x]]*Sqrt[b*Sec[c + d*x]])) + (2*b*B*Sqrt[Cos[c + d*x]]*EllipticF[(1/2)*(c + d*x), 2]*Sqrt[b*Sec[c + d*x]])/(3*d) + (2*b*(5*A + 3*C)*Sqrt[b*Sec[c + d*x]]*Sin[c + d*x])/(5*d) + (2*B*(b*Sec[c + d*x])^(3/2)*Sin[c + d*x])/(3*d) + (2*C*(b*Sec[c + d*x])^(3/2)*Tan[c + d*x])/(5*d)}
{Sec[c + d*x]^0*(A + B*Sec[c + d*x] + C*Sec[c + d*x]^2)*(b*Sec[c + d*x])^(1/2), x, 7, -((2*b*B*EllipticE[(1/2)*(c + d*x), 2])/(d*Sqrt[Cos[c + d*x]]*Sqrt[b*Sec[c + d*x]])) + (2*(3*A + C)*Sqrt[Cos[c + d*x]]*EllipticF[(1/2)*(c + d*x), 2]*Sqrt[b*Sec[c + d*x]])/(3*d) + (2*B*Sqrt[b*Sec[c + d*x]]*Sin[c + d*x])/d + (2*C*Sqrt[b*Sec[c + d*x]]*Tan[c + d*x])/(3*d)}


(* ::Subsubsection::Closed:: *)
(*n<0*)


{Sec[c + d*x]^0*(A + B*Sec[c + d*x] + C*Sec[c + d*x]^2)/(b*Sec[c + d*x])^(1/2), x, 6, (2*(A - C)*EllipticE[(1/2)*(c + d*x), 2])/(d*Sqrt[Cos[c + d*x]]*Sqrt[b*Sec[c + d*x]]) + (2*B*Sqrt[Cos[c + d*x]]*EllipticF[(1/2)*(c + d*x), 2]*Sqrt[b*Sec[c + d*x]])/(b*d) + (2*C*Tan[c + d*x])/(d*Sqrt[b*Sec[c + d*x]])}
{Sec[c + d*x]^0*(A + B*Sec[c + d*x] + C*Sec[c + d*x]^2)/(b*Sec[c + d*x])^(3/2), x, 6, (2*B*EllipticE[(1/2)*(c + d*x), 2])/(b*d*Sqrt[Cos[c + d*x]]*Sqrt[b*Sec[c + d*x]]) + (2*(A + 3*C)*Sqrt[Cos[c + d*x]]*EllipticF[(1/2)*(c + d*x), 2]*Sqrt[b*Sec[c + d*x]])/(3*b^2*d) + (2*A*Tan[c + d*x])/(3*d*(b*Sec[c + d*x])^(3/2))}
{Sec[c + d*x]^0*(A + B*Sec[c + d*x] + C*Sec[c + d*x]^2)/(b*Sec[c + d*x])^(5/2), x, 7, (2*(3*A + 5*C)*EllipticE[(1/2)*(c + d*x), 2])/(5*b^2*d*Sqrt[Cos[c + d*x]]*Sqrt[b*Sec[c + d*x]]) + (2*B*Sqrt[Cos[c + d*x]]*EllipticF[(1/2)*(c + d*x), 2]*Sqrt[b*Sec[c + d*x]])/(3*b^3*d) + (2*B*Sin[c + d*x])/(3*b^2*d*Sqrt[b*Sec[c + d*x]]) + (2*A*Tan[c + d*x])/(5*d*(b*Sec[c + d*x])^(5/2))}
{Sec[c + d*x]^0*(A + B*Sec[c + d*x] + C*Sec[c + d*x]^2)/(b*Sec[c + d*x])^(7/2), x, 8, (6*B*EllipticE[(1/2)*(c + d*x), 2])/(5*b^3*d*Sqrt[Cos[c + d*x]]*Sqrt[b*Sec[c + d*x]]) + (2*(5*A + 7*C)*Sqrt[Cos[c + d*x]]*EllipticF[(1/2)*(c + d*x), 2]*Sqrt[b*Sec[c + d*x]])/(21*b^4*d) + (2*B*Sin[c + d*x])/(5*b^2*d*(b*Sec[c + d*x])^(3/2)) + (2*(5*A + 7*C)*Sin[c + d*x])/(21*b^3*d*Sqrt[b*Sec[c + d*x]]) + (2*A*Tan[c + d*x])/(7*d*(b*Sec[c + d*x])^(7/2))}


(* ::Subsection:: *)
(*Integrands of the form Sec[c+d x]^(m/2) (A+B Sec[c+d x]+C Sec[c+d x]^2) (b Sec[c+d x])^(n/2)*)


(* ::Subsection::Closed:: *)
(*Integrands of the form Sec[c+d x]^m (A+B Sec[c+d x]+C Sec[c+d x]^2) (b Sec[c+d x])^(n/3)*)


(* ::Subsubsection::Closed:: *)
(*n>0*)


{Sec[c + d*x]^m*(b*Sec[c + d*x])^(1/3)*(A + B*Sec[c + d*x] + C*Sec[c + d*x]^2), x, 7, ((C + 3*C*m + A*(4 + 3*m))*(Cos[c + d*x]^2)^((-2 + 3*m)/6)*Hypergeometric2F1[1/2, (4 + 3*m)/6, 3/2, Sin[c + d*x]^2]*Sec[c + d*x]^(-1 + m)*(b*Sec[c + d*x])^(1/3)*Sin[c + d*x])/(d*(4 + 3*m)) + (B*(Cos[c + d*x]^2)^((1 + 3*m)/6)*Hypergeometric2F1[1/2, (7 + 3*m)/6, 3/2, Sin[c + d*x]^2]*Sec[c + d*x]^m*(b*Sec[c + d*x])^(1/3)*Sin[c + d*x])/d + (3*C*Sec[c + d*x]^(1 + m)*(b*Sec[c + d*x])^(1/3)*Sin[c + d*x])/(d*(4 + 3*m))}

{Sec[c + d*x]^2*(b*Sec[c + d*x])^(1/3)*(A + B*Sec[c + d*x] + C*Sec[c + d*x]^2), x, 10, (b*(10*A + 7*C)*Hypergeometric2F1[1/2, 2/3, 3/2, Sin[c + d*x]^2]*Sin[c + d*x])/(40*d*(Cos[c + d*x]^2)^(1/3)*(b*Sec[c + d*x])^(2/3)) + (12*B*(b*Sec[c + d*x])^(1/3)*Sin[c + d*x])/(7*d) - (8*B*(Cos[c + d*x]^2)^(1/6)*Hypergeometric2F1[1/6, 1/2, 3/2, Sin[c + d*x]^2]*(b*Sec[c + d*x])^(1/3)*Sin[c + d*x])/(7*d) + (3*(10*A + 7*C)*(b*Sec[c + d*x])^(4/3)*Sin[c + d*x])/(40*b*d) + (3*B*(b*Sec[c + d*x])^(7/3)*Sin[c + d*x])/(7*b^2*d) + (3*C*(b*Sec[c + d*x])^(7/3)*Tan[c + d*x])/(10*b^2*d)}
{Sec[c + d*x]*(b*Sec[c + d*x])^(1/3)*(A + B*Sec[c + d*x] + C*Sec[c + d*x]^2), x, 9, (b*B*Hypergeometric2F1[1/2, 2/3, 3/2, Sin[c + d*x]^2]*Sin[c + d*x])/(4*d*(Cos[c + d*x]^2)^(1/3)*(b*Sec[c + d*x])^(2/3)) + (3*(7*A + 4*C)*(b*Sec[c + d*x])^(1/3)*Sin[c + d*x])/(7*d) - (2*(7*A + 4*C)*(Cos[c + d*x]^2)^(1/6)*Hypergeometric2F1[1/6, 1/2, 3/2, Sin[c + d*x]^2]*(b*Sec[c + d*x])^(1/3)*Sin[c + d*x])/(7*d) + (3*B*(b*Sec[c + d*x])^(4/3)*Sin[c + d*x])/(4*b*d) + (3*C*(b*Sec[c + d*x])^(4/3)*Tan[c + d*x])/(7*b*d)}
{(b*Sec[c + d*x])^(1/3)*(A + B*Sec[c + d*x] + C*Sec[c + d*x]^2), x, 7, (b*(4*A + C)*Hypergeometric2F1[1/2, 2/3, 3/2, Sin[c + d*x]^2]*Sin[c + d*x])/(4*d*(Cos[c + d*x]^2)^(1/3)*(b*Sec[c + d*x])^(2/3)) + (3*B*(b*Sec[c + d*x])^(1/3)*Sin[c + d*x])/d - (2*B*(Cos[c + d*x]^2)^(1/6)*Hypergeometric2F1[1/6, 1/2, 3/2, Sin[c + d*x]^2]*(b*Sec[c + d*x])^(1/3)*Sin[c + d*x])/d + (3*C*(b*Sec[c + d*x])^(1/3)*Tan[c + d*x])/(4*d)}
{Cos[c + d*x]*(b*Sec[c + d*x])^(1/3)*(A + B*Sec[c + d*x] + C*Sec[c + d*x]^2), x, 7, (b*B*Hypergeometric2F1[1/2, 2/3, 3/2, Sin[c + d*x]^2]*Sin[c + d*x])/(d*(Cos[c + d*x]^2)^(1/3)*(b*Sec[c + d*x])^(2/3)) + ((A - 2*C)*(Cos[c + d*x]^2)^(1/6)*Hypergeometric2F1[1/6, 1/2, 3/2, Sin[c + d*x]^2]*(b*Sec[c + d*x])^(1/3)*Sin[c + d*x])/d + (3*b*C*Tan[c + d*x])/(d*(b*Sec[c + d*x])^(2/3))}
{Cos[c + d*x]^2*(b*Sec[c + d*x])^(1/3)*(A + B*Sec[c + d*x] + C*Sec[c + d*x]^2), x, 7, (b*(2*A + 5*C)*Hypergeometric2F1[1/2, 2/3, 3/2, Sin[c + d*x]^2]*Sin[c + d*x])/(5*d*(Cos[c + d*x]^2)^(1/3)*(b*Sec[c + d*x])^(2/3)) + (B*(Cos[c + d*x]^2)^(1/6)*Hypergeometric2F1[1/6, 1/2, 3/2, Sin[c + d*x]^2]*(b*Sec[c + d*x])^(1/3)*Sin[c + d*x])/d + (3*A*b^2*Tan[c + d*x])/(5*d*(b*Sec[c + d*x])^(5/3))}
{Cos[c + d*x]^3*(b*Sec[c + d*x])^(1/3)*(A + B*Sec[c + d*x] + C*Sec[c + d*x]^2), x, 8, (3*b*B*Sin[c + d*x])/(5*d*(b*Sec[c + d*x])^(2/3)) + (2*b*B*Hypergeometric2F1[1/2, 2/3, 3/2, Sin[c + d*x]^2]*Sin[c + d*x])/(5*d*(Cos[c + d*x]^2)^(1/3)*(b*Sec[c + d*x])^(2/3)) + ((5*A + 8*C)*(Cos[c + d*x]^2)^(1/6)*Hypergeometric2F1[1/6, 1/2, 3/2, Sin[c + d*x]^2]*(b*Sec[c + d*x])^(1/3)*Sin[c + d*x])/(8*d) + (3*A*b^3*Tan[c + d*x])/(8*d*(b*Sec[c + d*x])^(8/3))}


{Sec[c + d*x]^m*(b*Sec[c + d*x])^(2/3)*(A + B*Sec[c + d*x] + C*Sec[c + d*x]^2), x, 7, ((3*A + (A + C)*(2 + 3*m))*(Cos[c + d*x]^2)^((-1 + 3*m)/6)*Hypergeometric2F1[1/2, (5 + 3*m)/6, 3/2, Sin[c + d*x]^2]*Sec[c + d*x]^(-1 + m)*(b*Sec[c + d*x])^(2/3)*Sin[c + d*x])/(d*(5 + 3*m)) + (B*(Cos[c + d*x]^2)^((2 + 3*m)/6)*Hypergeometric2F1[1/2, (8 + 3*m)/6, 3/2, Sin[c + d*x]^2]*Sec[c + d*x]^m*(b*Sec[c + d*x])^(2/3)*Sin[c + d*x])/d + (3*C*Sec[c + d*x]^(1 + m)*(b*Sec[c + d*x])^(2/3)*Sin[c + d*x])/(d*(5 + 3*m))}

{Sec[c + d*x]^2*(b*Sec[c + d*x])^(2/3)*(A + B*Sec[c + d*x] + C*Sec[c + d*x]^2), x, 10, (2*b*(11*A + 8*C)*Hypergeometric2F1[1/2, 5/6, 3/2, Sin[c + d*x]^2]*Sin[c + d*x])/(55*d*(Cos[c + d*x]^2)^(1/6)*(b*Sec[c + d*x])^(1/3)) + (15*B*(b*Sec[c + d*x])^(2/3)*Sin[c + d*x])/(16*d) - (5*B*(Cos[c + d*x]^2)^(1/3)*Hypergeometric2F1[1/3, 1/2, 3/2, Sin[c + d*x]^2]*(b*Sec[c + d*x])^(2/3)*Sin[c + d*x])/(16*d) + (3*(11*A + 8*C)*(b*Sec[c + d*x])^(5/3)*Sin[c + d*x])/(55*b*d) + (3*B*(b*Sec[c + d*x])^(8/3)*Sin[c + d*x])/(8*b^2*d) + (3*C*(b*Sec[c + d*x])^(8/3)*Tan[c + d*x])/(11*b^2*d)}
{Sec[c + d*x]*(b*Sec[c + d*x])^(2/3)*(A + B*Sec[c + d*x] + C*Sec[c + d*x]^2), x, 9, (2*b*B*Hypergeometric2F1[1/2, 5/6, 3/2, Sin[c + d*x]^2]*Sin[c + d*x])/(5*d*(Cos[c + d*x]^2)^(1/6)*(b*Sec[c + d*x])^(1/3)) + (3*(8*A + 5*C)*(b*Sec[c + d*x])^(2/3)*Sin[c + d*x])/(16*d) - ((8*A + 5*C)*(Cos[c + d*x]^2)^(1/3)*Hypergeometric2F1[1/3, 1/2, 3/2, Sin[c + d*x]^2]*(b*Sec[c + d*x])^(2/3)*Sin[c + d*x])/(16*d) + (3*B*(b*Sec[c + d*x])^(5/3)*Sin[c + d*x])/(5*b*d) + (3*C*(b*Sec[c + d*x])^(5/3)*Tan[c + d*x])/(8*b*d)}
{(b*Sec[c + d*x])^(2/3)*(A + B*Sec[c + d*x] + C*Sec[c + d*x]^2), x, 7, (b*(5*A + 2*C)*Hypergeometric2F1[1/2, 5/6, 3/2, Sin[c + d*x]^2]*Sin[c + d*x])/(5*d*(Cos[c + d*x]^2)^(1/6)*(b*Sec[c + d*x])^(1/3)) + (3*B*(b*Sec[c + d*x])^(2/3)*Sin[c + d*x])/(2*d) - (B*(Cos[c + d*x]^2)^(1/3)*Hypergeometric2F1[1/3, 1/2, 3/2, Sin[c + d*x]^2]*(b*Sec[c + d*x])^(2/3)*Sin[c + d*x])/(2*d) + (3*C*(b*Sec[c + d*x])^(2/3)*Tan[c + d*x])/(5*d)}
{Cos[c + d*x]*(b*Sec[c + d*x])^(2/3)*(A + B*Sec[c + d*x] + C*Sec[c + d*x]^2), x, 7, (b*B*Hypergeometric2F1[1/2, 5/6, 3/2, Sin[c + d*x]^2]*Sin[c + d*x])/(d*(Cos[c + d*x]^2)^(1/6)*(b*Sec[c + d*x])^(1/3)) + ((2*A - C)*(Cos[c + d*x]^2)^(1/3)*Hypergeometric2F1[1/3, 1/2, 3/2, Sin[c + d*x]^2]*(b*Sec[c + d*x])^(2/3)*Sin[c + d*x])/(2*d) + (3*b*C*Tan[c + d*x])/(2*d*(b*Sec[c + d*x])^(1/3))}
{Cos[c + d*x]^2*(b*Sec[c + d*x])^(2/3)*(A + B*Sec[c + d*x] + C*Sec[c + d*x]^2), x, 7, (b*(A + 4*C)*Hypergeometric2F1[1/2, 5/6, 3/2, Sin[c + d*x]^2]*Sin[c + d*x])/(4*d*(Cos[c + d*x]^2)^(1/6)*(b*Sec[c + d*x])^(1/3)) + (B*(Cos[c + d*x]^2)^(1/3)*Hypergeometric2F1[1/3, 1/2, 3/2, Sin[c + d*x]^2]*(b*Sec[c + d*x])^(2/3)*Sin[c + d*x])/d + (3*A*b^2*Tan[c + d*x])/(4*d*(b*Sec[c + d*x])^(4/3))}
{Cos[c + d*x]^3*(b*Sec[c + d*x])^(2/3)*(A + B*Sec[c + d*x] + C*Sec[c + d*x]^2), x, 8, (3*b*B*Sin[c + d*x])/(4*d*(b*Sec[c + d*x])^(1/3)) + (b*B*Hypergeometric2F1[1/2, 5/6, 3/2, Sin[c + d*x]^2]*Sin[c + d*x])/(4*d*(Cos[c + d*x]^2)^(1/6)*(b*Sec[c + d*x])^(1/3)) + ((4*A + 7*C)*(Cos[c + d*x]^2)^(1/3)*Hypergeometric2F1[1/3, 1/2, 3/2, Sin[c + d*x]^2]*(b*Sec[c + d*x])^(2/3)*Sin[c + d*x])/(7*d) + (3*A*b^3*Tan[c + d*x])/(7*d*(b*Sec[c + d*x])^(7/3))}


{Sec[c + d*x]^m*(b*Sec[c + d*x])^(4/3)*(A + B*Sec[c + d*x] + C*Sec[c + d*x]^2), x, 7, ((3*A + (A + C)*(4 + 3*m))*(Cos[c + d*x]^2)^((1 + 3*m)/6)*Hypergeometric2F1[1/2, (7 + 3*m)/6, 3/2, Sin[c + d*x]^2]*Sec[c + d*x]^(-1 + m)*(b*Sec[c + d*x])^(4/3)*Sin[c + d*x])/(d*(7 + 3*m)) + (B*(Cos[c + d*x]^2)^((4 + 3*m)/6)*Hypergeometric2F1[1/2, (10 + 3*m)/6, 3/2, Sin[c + d*x]^2]*Sec[c + d*x]^m*(b*Sec[c + d*x])^(4/3)*Sin[c + d*x])/d + (3*C*Sec[c + d*x]^(1 + m)*(b*Sec[c + d*x])^(4/3)*Sin[c + d*x])/(d*(7 + 3*m))}

{Sec[c + d*x]^2*(b*Sec[c + d*x])^(4/3)*(A + B*Sec[c + d*x] + C*Sec[c + d*x]^2), x, 11, (7*b^2*B*Hypergeometric2F1[1/2, 2/3, 3/2, Sin[c + d*x]^2]*Sin[c + d*x])/(40*d*(Cos[c + d*x]^2)^(1/3)*(b*Sec[c + d*x])^(2/3)) + (12*b*(13*A + 10*C)*(b*Sec[c + d*x])^(1/3)*Sin[c + d*x])/(91*d) - (8*b*(13*A + 10*C)*(Cos[c + d*x]^2)^(1/6)*Hypergeometric2F1[1/6, 1/2, 3/2, Sin[c + d*x]^2]*(b*Sec[c + d*x])^(1/3)*Sin[c + d*x])/(91*d) + (21*B*(b*Sec[c + d*x])^(4/3)*Sin[c + d*x])/(40*d) + (3*(13*A + 10*C)*(b*Sec[c + d*x])^(7/3)*Sin[c + d*x])/(91*b*d) + (3*B*(b*Sec[c + d*x])^(10/3)*Sin[c + d*x])/(10*b^2*d) + (3*C*(b*Sec[c + d*x])^(10/3)*Tan[c + d*x])/(13*b^2*d)}
{Sec[c + d*x]*(b*Sec[c + d*x])^(4/3)*(A + B*Sec[c + d*x] + C*Sec[c + d*x]^2), x, 10, (b^2*(10*A + 7*C)*Hypergeometric2F1[1/2, 2/3, 3/2, Sin[c + d*x]^2]*Sin[c + d*x])/(40*d*(Cos[c + d*x]^2)^(1/3)*(b*Sec[c + d*x])^(2/3)) + (12*b*B*(b*Sec[c + d*x])^(1/3)*Sin[c + d*x])/(7*d) - (8*b*B*(Cos[c + d*x]^2)^(1/6)*Hypergeometric2F1[1/6, 1/2, 3/2, Sin[c + d*x]^2]*(b*Sec[c + d*x])^(1/3)*Sin[c + d*x])/(7*d) + (3*(10*A + 7*C)*(b*Sec[c + d*x])^(4/3)*Sin[c + d*x])/(40*d) + (3*B*(b*Sec[c + d*x])^(7/3)*Sin[c + d*x])/(7*b*d) + (3*C*(b*Sec[c + d*x])^(7/3)*Tan[c + d*x])/(10*b*d)}
{(b*Sec[c + d*x])^(4/3)*(A + B*Sec[c + d*x] + C*Sec[c + d*x]^2), x, 8, (b^2*B*Hypergeometric2F1[1/2, 2/3, 3/2, Sin[c + d*x]^2]*Sin[c + d*x])/(4*d*(Cos[c + d*x]^2)^(1/3)*(b*Sec[c + d*x])^(2/3)) + (3*b*(7*A + 4*C)*(b*Sec[c + d*x])^(1/3)*Sin[c + d*x])/(7*d) - (2*b*(7*A + 4*C)*(Cos[c + d*x]^2)^(1/6)*Hypergeometric2F1[1/6, 1/2, 3/2, Sin[c + d*x]^2]*(b*Sec[c + d*x])^(1/3)*Sin[c + d*x])/(7*d) + (3*B*(b*Sec[c + d*x])^(4/3)*Sin[c + d*x])/(4*d) + (3*C*(b*Sec[c + d*x])^(4/3)*Tan[c + d*x])/(7*d)}
{Cos[c + d*x]*(b*Sec[c + d*x])^(4/3)*(A + B*Sec[c + d*x] + C*Sec[c + d*x]^2), x, 8, (b^2*(4*A + C)*Hypergeometric2F1[1/2, 2/3, 3/2, Sin[c + d*x]^2]*Sin[c + d*x])/(4*d*(Cos[c + d*x]^2)^(1/3)*(b*Sec[c + d*x])^(2/3)) + (3*b*B*(b*Sec[c + d*x])^(1/3)*Sin[c + d*x])/d - (2*b*B*(Cos[c + d*x]^2)^(1/6)*Hypergeometric2F1[1/6, 1/2, 3/2, Sin[c + d*x]^2]*(b*Sec[c + d*x])^(1/3)*Sin[c + d*x])/d + (3*b*C*(b*Sec[c + d*x])^(1/3)*Tan[c + d*x])/(4*d)}
{Cos[c + d*x]^2*(b*Sec[c + d*x])^(4/3)*(A + B*Sec[c + d*x] + C*Sec[c + d*x]^2), x, 7, (b^2*B*Hypergeometric2F1[1/2, 2/3, 3/2, Sin[c + d*x]^2]*Sin[c + d*x])/(d*(Cos[c + d*x]^2)^(1/3)*(b*Sec[c + d*x])^(2/3)) + (b*(A - 2*C)*(Cos[c + d*x]^2)^(1/6)*Hypergeometric2F1[1/6, 1/2, 3/2, Sin[c + d*x]^2]*(b*Sec[c + d*x])^(1/3)*Sin[c + d*x])/d + (3*b^2*C*Tan[c + d*x])/(d*(b*Sec[c + d*x])^(2/3))}
{Cos[c + d*x]^3*(b*Sec[c + d*x])^(4/3)*(A + B*Sec[c + d*x] + C*Sec[c + d*x]^2), x, 7, (b^2*(2*A + 5*C)*Hypergeometric2F1[1/2, 2/3, 3/2, Sin[c + d*x]^2]*Sin[c + d*x])/(5*d*(Cos[c + d*x]^2)^(1/3)*(b*Sec[c + d*x])^(2/3)) + (b*B*(Cos[c + d*x]^2)^(1/6)*Hypergeometric2F1[1/6, 1/2, 3/2, Sin[c + d*x]^2]*(b*Sec[c + d*x])^(1/3)*Sin[c + d*x])/d + (3*A*b^3*Tan[c + d*x])/(5*d*(b*Sec[c + d*x])^(5/3))}


(* ::Subsubsection::Closed:: *)
(*n<0*)


{(Sec[c + d*x]^m*(A + B*Sec[c + d*x] + C*Sec[c + d*x]^2))/(b*Sec[c + d*x])^(1/3), x, 7, (B*(Cos[c + d*x]^2)^((-1 + 3*m)/6)*Hypergeometric2F1[1/2, (5 + 3*m)/6, 3/2, Sin[c + d*x]^2]*Sec[c + d*x]^m*Sin[c + d*x])/(d*(b*Sec[c + d*x])^(1/3)) + (3*C*Sec[c + d*x]^(1 + m)*Sin[c + d*x])/(d*(2 + 3*m)*(b*Sec[c + d*x])^(1/3)) - ((C*(1 - 3*m) - A*(2 + 3*m))*(Cos[c + d*x]^2)^((2 + 3*m)/6)*Hypergeometric2F1[1/2, (2 + 3*m)/6, 3/2, Sin[c + d*x]^2]*Sec[c + d*x]^(1 + m)*Sin[c + d*x])/(d*(2 + 3*m)*(b*Sec[c + d*x])^(1/3))}

{(Sec[c + d*x]^2*(A + B*Sec[c + d*x] + C*Sec[c + d*x]^2))/(b*Sec[c + d*x])^(1/3), x, 9, (2*B*Hypergeometric2F1[1/2, 5/6, 3/2, Sin[c + d*x]^2]*Sin[c + d*x])/(5*d*(Cos[c + d*x]^2)^(1/6)*(b*Sec[c + d*x])^(1/3)) + (3*(8*A + 5*C)*(b*Sec[c + d*x])^(2/3)*Sin[c + d*x])/(16*b*d) - ((8*A + 5*C)*(Cos[c + d*x]^2)^(1/3)*Hypergeometric2F1[1/3, 1/2, 3/2, Sin[c + d*x]^2]*(b*Sec[c + d*x])^(2/3)*Sin[c + d*x])/(16*b*d) + (3*B*(b*Sec[c + d*x])^(5/3)*Sin[c + d*x])/(5*b^2*d) + (3*C*(b*Sec[c + d*x])^(5/3)*Tan[c + d*x])/(8*b^2*d)}
{(Sec[c + d*x]*(A + B*Sec[c + d*x] + C*Sec[c + d*x]^2))/(b*Sec[c + d*x])^(1/3), x, 8, ((5*A + 2*C)*Hypergeometric2F1[1/2, 5/6, 3/2, Sin[c + d*x]^2]*Sin[c + d*x])/(5*d*(Cos[c + d*x]^2)^(1/6)*(b*Sec[c + d*x])^(1/3)) + (3*B*(b*Sec[c + d*x])^(2/3)*Sin[c + d*x])/(2*b*d) - (B*(Cos[c + d*x]^2)^(1/3)*Hypergeometric2F1[1/3, 1/2, 3/2, Sin[c + d*x]^2]*(b*Sec[c + d*x])^(2/3)*Sin[c + d*x])/(2*b*d) + (3*C*(b*Sec[c + d*x])^(2/3)*Tan[c + d*x])/(5*b*d)}
{(A + B*Sec[c + d*x] + C*Sec[c + d*x]^2)/(b*Sec[c + d*x])^(1/3), x, 6, (B*Hypergeometric2F1[1/2, 5/6, 3/2, Sin[c + d*x]^2]*Sin[c + d*x])/(d*(Cos[c + d*x]^2)^(1/6)*(b*Sec[c + d*x])^(1/3)) + ((2*A - C)*(Cos[c + d*x]^2)^(1/3)*Hypergeometric2F1[1/3, 1/2, 3/2, Sin[c + d*x]^2]*(b*Sec[c + d*x])^(2/3)*Sin[c + d*x])/(2*b*d) + (3*C*Tan[c + d*x])/(2*d*(b*Sec[c + d*x])^(1/3))}
{(Sec[c + d*x]*(A + B*Sec[c + d*x] + C*Sec[c + d*x]^2))/(b*Sec[c + d*x])^(1/3), x, 8, ((5*A + 2*C)*Hypergeometric2F1[1/2, 5/6, 3/2, Sin[c + d*x]^2]*Sin[c + d*x])/(5*d*(Cos[c + d*x]^2)^(1/6)*(b*Sec[c + d*x])^(1/3)) + (3*B*(b*Sec[c + d*x])^(2/3)*Sin[c + d*x])/(2*b*d) - (B*(Cos[c + d*x]^2)^(1/3)*Hypergeometric2F1[1/3, 1/2, 3/2, Sin[c + d*x]^2]*(b*Sec[c + d*x])^(2/3)*Sin[c + d*x])/(2*b*d) + (3*C*(b*Sec[c + d*x])^(2/3)*Tan[c + d*x])/(5*b*d)}
{(Sec[c + d*x]^2*(A + B*Sec[c + d*x] + C*Sec[c + d*x]^2))/(b*Sec[c + d*x])^(1/3), x, 9, (2*B*Hypergeometric2F1[1/2, 5/6, 3/2, Sin[c + d*x]^2]*Sin[c + d*x])/(5*d*(Cos[c + d*x]^2)^(1/6)*(b*Sec[c + d*x])^(1/3)) + (3*(8*A + 5*C)*(b*Sec[c + d*x])^(2/3)*Sin[c + d*x])/(16*b*d) - ((8*A + 5*C)*(Cos[c + d*x]^2)^(1/3)*Hypergeometric2F1[1/3, 1/2, 3/2, Sin[c + d*x]^2]*(b*Sec[c + d*x])^(2/3)*Sin[c + d*x])/(16*b*d) + (3*B*(b*Sec[c + d*x])^(5/3)*Sin[c + d*x])/(5*b^2*d) + (3*C*(b*Sec[c + d*x])^(5/3)*Tan[c + d*x])/(8*b^2*d)}
{(Sec[c + d*x]^3*(A + B*Sec[c + d*x] + C*Sec[c + d*x]^2))/(b*Sec[c + d*x])^(1/3), x, 10, (2*(11*A + 8*C)*Hypergeometric2F1[1/2, 5/6, 3/2, Sin[c + d*x]^2]*Sin[c + d*x])/(55*d*(Cos[c + d*x]^2)^(1/6)*(b*Sec[c + d*x])^(1/3)) + (15*B*(b*Sec[c + d*x])^(2/3)*Sin[c + d*x])/(16*b*d) - (5*B*(Cos[c + d*x]^2)^(1/3)*Hypergeometric2F1[1/3, 1/2, 3/2, Sin[c + d*x]^2]*(b*Sec[c + d*x])^(2/3)*Sin[c + d*x])/(16*b*d) + (3*(11*A + 8*C)*(b*Sec[c + d*x])^(5/3)*Sin[c + d*x])/(55*b^2*d) + (3*B*(b*Sec[c + d*x])^(8/3)*Sin[c + d*x])/(8*b^3*d) + (3*C*(b*Sec[c + d*x])^(8/3)*Tan[c + d*x])/(11*b^3*d)}


{(Sec[c + d*x]^m*(A + B*Sec[c + d*x] + C*Sec[c + d*x]^2))/(b*Sec[c + d*x])^(2/3), x, 7, (B*(Cos[c + d*x]^2)^((-2 + 3*m)/6)*Hypergeometric2F1[1/2, (4 + 3*m)/6, 3/2, Sin[c + d*x]^2]*Sec[c + d*x]^m*Sin[c + d*x])/(d*(b*Sec[c + d*x])^(2/3)) + (3*C*Sec[c + d*x]^(1 + m)*Sin[c + d*x])/(d*(1 + 3*m)*(b*Sec[c + d*x])^(2/3)) + ((A - C*(2 - 3*m) + 3*A*m)*(Cos[c + d*x]^2)^((1 + 3*m)/6)*Hypergeometric2F1[1/2, (1 + 3*m)/6, 3/2, Sin[c + d*x]^2]*Sec[c + d*x]^(1 + m)*Sin[c + d*x])/(d*(1 + 3*m)*(b*Sec[c + d*x])^(2/3))}

{(Sec[c + d*x]^2*(A + B*Sec[c + d*x] + C*Sec[c + d*x]^2))/(b*Sec[c + d*x])^(2/3), x, 9, (B*Hypergeometric2F1[1/2, 2/3, 3/2, Sin[c + d*x]^2]*Sin[c + d*x])/(4*d*(Cos[c + d*x]^2)^(1/3)*(b*Sec[c + d*x])^(2/3)) + (3*(7*A + 4*C)*(b*Sec[c + d*x])^(1/3)*Sin[c + d*x])/(7*b*d) - (2*(7*A + 4*C)*(Cos[c + d*x]^2)^(1/6)*Hypergeometric2F1[1/6, 1/2, 3/2, Sin[c + d*x]^2]*(b*Sec[c + d*x])^(1/3)*Sin[c + d*x])/(7*b*d) + (3*B*(b*Sec[c + d*x])^(4/3)*Sin[c + d*x])/(4*b^2*d) + (3*C*(b*Sec[c + d*x])^(4/3)*Tan[c + d*x])/(7*b^2*d)}
{(Sec[c + d*x]*(A + B*Sec[c + d*x] + C*Sec[c + d*x]^2))/(b*Sec[c + d*x])^(2/3), x, 8, ((4*A + C)*Hypergeometric2F1[1/2, 2/3, 3/2, Sin[c + d*x]^2]*Sin[c + d*x])/(4*d*(Cos[c + d*x]^2)^(1/3)*(b*Sec[c + d*x])^(2/3)) + (3*B*(b*Sec[c + d*x])^(1/3)*Sin[c + d*x])/(b*d) - (2*B*(Cos[c + d*x]^2)^(1/6)*Hypergeometric2F1[1/6, 1/2, 3/2, Sin[c + d*x]^2]*(b*Sec[c + d*x])^(1/3)*Sin[c + d*x])/(b*d) + (3*C*(b*Sec[c + d*x])^(1/3)*Tan[c + d*x])/(4*b*d)}
{(A + B*Sec[c + d*x] + C*Sec[c + d*x]^2)/(b*Sec[c + d*x])^(2/3), x, 6, (B*Hypergeometric2F1[1/2, 2/3, 3/2, Sin[c + d*x]^2]*Sin[c + d*x])/(d*(Cos[c + d*x]^2)^(1/3)*(b*Sec[c + d*x])^(2/3)) + ((A - 2*C)*(Cos[c + d*x]^2)^(1/6)*Hypergeometric2F1[1/6, 1/2, 3/2, Sin[c + d*x]^2]*(b*Sec[c + d*x])^(1/3)*Sin[c + d*x])/(b*d) + (3*C*Tan[c + d*x])/(d*(b*Sec[c + d*x])^(2/3))}
{(Sec[c + d*x]*(A + B*Sec[c + d*x] + C*Sec[c + d*x]^2))/(b*Sec[c + d*x])^(2/3), x, 8, ((4*A + C)*Hypergeometric2F1[1/2, 2/3, 3/2, Sin[c + d*x]^2]*Sin[c + d*x])/(4*d*(Cos[c + d*x]^2)^(1/3)*(b*Sec[c + d*x])^(2/3)) + (3*B*(b*Sec[c + d*x])^(1/3)*Sin[c + d*x])/(b*d) - (2*B*(Cos[c + d*x]^2)^(1/6)*Hypergeometric2F1[1/6, 1/2, 3/2, Sin[c + d*x]^2]*(b*Sec[c + d*x])^(1/3)*Sin[c + d*x])/(b*d) + (3*C*(b*Sec[c + d*x])^(1/3)*Tan[c + d*x])/(4*b*d)}
{(Sec[c + d*x]^2*(A + B*Sec[c + d*x] + C*Sec[c + d*x]^2))/(b*Sec[c + d*x])^(2/3), x, 9, (B*Hypergeometric2F1[1/2, 2/3, 3/2, Sin[c + d*x]^2]*Sin[c + d*x])/(4*d*(Cos[c + d*x]^2)^(1/3)*(b*Sec[c + d*x])^(2/3)) + (3*(7*A + 4*C)*(b*Sec[c + d*x])^(1/3)*Sin[c + d*x])/(7*b*d) - (2*(7*A + 4*C)*(Cos[c + d*x]^2)^(1/6)*Hypergeometric2F1[1/6, 1/2, 3/2, Sin[c + d*x]^2]*(b*Sec[c + d*x])^(1/3)*Sin[c + d*x])/(7*b*d) + (3*B*(b*Sec[c + d*x])^(4/3)*Sin[c + d*x])/(4*b^2*d) + (3*C*(b*Sec[c + d*x])^(4/3)*Tan[c + d*x])/(7*b^2*d)}
{(Sec[c + d*x]^3*(A + B*Sec[c + d*x] + C*Sec[c + d*x]^2))/(b*Sec[c + d*x])^(2/3), x, 10, ((10*A + 7*C)*Hypergeometric2F1[1/2, 2/3, 3/2, Sin[c + d*x]^2]*Sin[c + d*x])/(40*d*(Cos[c + d*x]^2)^(1/3)*(b*Sec[c + d*x])^(2/3)) + (12*B*(b*Sec[c + d*x])^(1/3)*Sin[c + d*x])/(7*b*d) - (8*B*(Cos[c + d*x]^2)^(1/6)*Hypergeometric2F1[1/6, 1/2, 3/2, Sin[c + d*x]^2]*(b*Sec[c + d*x])^(1/3)*Sin[c + d*x])/(7*b*d) + (3*(10*A + 7*C)*(b*Sec[c + d*x])^(4/3)*Sin[c + d*x])/(40*b^2*d) + (3*B*(b*Sec[c + d*x])^(7/3)*Sin[c + d*x])/(7*b^3*d) + (3*C*(b*Sec[c + d*x])^(7/3)*Tan[c + d*x])/(10*b^3*d)}


{(Sec[c + d*x]^m*(A + B*Sec[c + d*x] + C*Sec[c + d*x]^2))/(b*Sec[c + d*x])^(4/3), x, 7, -(((3*A - (A + C)*(4 - 3*m))*(Cos[c + d*x]^2)^((-7 + 3*m)/6)*Hypergeometric2F1[1/2, (-1 + 3*m)/6, 3/2, Sin[c + d*x]^2]*Sec[c + d*x]^(-1 + m)*Sin[c + d*x])/(d*(1 - 3*m)*(b*Sec[c + d*x])^(4/3))) - (3*C*Sec[c + d*x]^(1 + m)*Sin[c + d*x])/(d*(1 - 3*m)*(b*Sec[c + d*x])^(4/3)) + (B*(Cos[c + d*x]^2)^((2 + 3*m)/6)*Hypergeometric2F1[1/2, (2 + 3*m)/6, 3/2, Sin[c + d*x]^2]*Sec[c + d*x]^(2 + m)*Sin[c + d*x])/(d*(b*Sec[c + d*x])^(4/3))}

{(Sec[c + d*x]^2*(A + B*Sec[c + d*x] + C*Sec[c + d*x]^2))/(b*Sec[c + d*x])^(4/3), x, 8, ((5*A + 2*C)*Hypergeometric2F1[1/2, 5/6, 3/2, Sin[c + d*x]^2]*Sin[c + d*x])/(5*b*d*(Cos[c + d*x]^2)^(1/6)*(b*Sec[c + d*x])^(1/3)) + (3*B*(b*Sec[c + d*x])^(2/3)*Sin[c + d*x])/(2*b^2*d) - (B*(Cos[c + d*x]^2)^(1/3)*Hypergeometric2F1[1/3, 1/2, 3/2, Sin[c + d*x]^2]*(b*Sec[c + d*x])^(2/3)*Sin[c + d*x])/(2*b^2*d) + (3*C*(b*Sec[c + d*x])^(2/3)*Tan[c + d*x])/(5*b^2*d)}
{(Sec[c + d*x]*(A + B*Sec[c + d*x] + C*Sec[c + d*x]^2))/(b*Sec[c + d*x])^(4/3), x, 7, (B*Hypergeometric2F1[1/2, 5/6, 3/2, Sin[c + d*x]^2]*Sin[c + d*x])/(b*d*(Cos[c + d*x]^2)^(1/6)*(b*Sec[c + d*x])^(1/3)) + ((2*A - C)*(Cos[c + d*x]^2)^(1/3)*Hypergeometric2F1[1/3, 1/2, 3/2, Sin[c + d*x]^2]*(b*Sec[c + d*x])^(2/3)*Sin[c + d*x])/(2*b^2*d) + (3*C*Tan[c + d*x])/(2*b*d*(b*Sec[c + d*x])^(1/3))}
{(A + B*Sec[c + d*x] + C*Sec[c + d*x]^2)/(b*Sec[c + d*x])^(4/3), x, 6, ((A + 4*C)*Hypergeometric2F1[1/2, 5/6, 3/2, Sin[c + d*x]^2]*Sin[c + d*x])/(4*b*d*(Cos[c + d*x]^2)^(1/6)*(b*Sec[c + d*x])^(1/3)) + (B*(Cos[c + d*x]^2)^(1/3)*Hypergeometric2F1[1/3, 1/2, 3/2, Sin[c + d*x]^2]*(b*Sec[c + d*x])^(2/3)*Sin[c + d*x])/(b^2*d) + (3*A*Tan[c + d*x])/(4*d*(b*Sec[c + d*x])^(4/3))}
{(Sec[c + d*x]*(A + B*Sec[c + d*x] + C*Sec[c + d*x]^2))/(b*Sec[c + d*x])^(4/3), x, 7, (B*Hypergeometric2F1[1/2, 5/6, 3/2, Sin[c + d*x]^2]*Sin[c + d*x])/(b*d*(Cos[c + d*x]^2)^(1/6)*(b*Sec[c + d*x])^(1/3)) + ((2*A - C)*(Cos[c + d*x]^2)^(1/3)*Hypergeometric2F1[1/3, 1/2, 3/2, Sin[c + d*x]^2]*(b*Sec[c + d*x])^(2/3)*Sin[c + d*x])/(2*b^2*d) + (3*C*Tan[c + d*x])/(2*b*d*(b*Sec[c + d*x])^(1/3))}
{(Sec[c + d*x]^2*(A + B*Sec[c + d*x] + C*Sec[c + d*x]^2))/(b*Sec[c + d*x])^(4/3), x, 8, ((5*A + 2*C)*Hypergeometric2F1[1/2, 5/6, 3/2, Sin[c + d*x]^2]*Sin[c + d*x])/(5*b*d*(Cos[c + d*x]^2)^(1/6)*(b*Sec[c + d*x])^(1/3)) + (3*B*(b*Sec[c + d*x])^(2/3)*Sin[c + d*x])/(2*b^2*d) - (B*(Cos[c + d*x]^2)^(1/3)*Hypergeometric2F1[1/3, 1/2, 3/2, Sin[c + d*x]^2]*(b*Sec[c + d*x])^(2/3)*Sin[c + d*x])/(2*b^2*d) + (3*C*(b*Sec[c + d*x])^(2/3)*Tan[c + d*x])/(5*b^2*d)}
{(Sec[c + d*x]^3*(A + B*Sec[c + d*x] + C*Sec[c + d*x]^2))/(b*Sec[c + d*x])^(4/3), x, 9, (2*B*Hypergeometric2F1[1/2, 5/6, 3/2, Sin[c + d*x]^2]*Sin[c + d*x])/(5*b*d*(Cos[c + d*x]^2)^(1/6)*(b*Sec[c + d*x])^(1/3)) + (3*(8*A + 5*C)*(b*Sec[c + d*x])^(2/3)*Sin[c + d*x])/(16*b^2*d) - ((8*A + 5*C)*(Cos[c + d*x]^2)^(1/3)*Hypergeometric2F1[1/3, 1/2, 3/2, Sin[c + d*x]^2]*(b*Sec[c + d*x])^(2/3)*Sin[c + d*x])/(16*b^2*d) + (3*B*(b*Sec[c + d*x])^(5/3)*Sin[c + d*x])/(5*b^3*d) + (3*C*(b*Sec[c + d*x])^(5/3)*Tan[c + d*x])/(8*b^3*d)}


(* ::Subsection::Closed:: *)
(*Integrands of the form Sec[c+d x]^m (A+B Sec[c+d x]+C Sec[c+d x]^2) (b Sec[c+d x])^n when n symbolic*)


{Sec[c + d*x]^m*(b*Sec[c + d*x])^n*(A + B*Sec[c + d*x] + C*Sec[c + d*x]^2), x, 7, ((A + (A + C)*(m + n))*(Cos[c + d*x]^2)^((-1 + m + n)/2)*Hypergeometric2F1[1/2, (1 + m + n)/2, 3/2, Sin[c + d*x]^2]*Sec[c + d*x]^(-1 + m)*(b*Sec[c + d*x])^n*Sin[c + d*x])/(d*(1 + m + n)) + (B*(Cos[c + d*x]^2)^((m + n)/2)*Hypergeometric2F1[1/2, (2 + m + n)/2, 3/2, Sin[c + d*x]^2]*Sec[c + d*x]^m*(b*Sec[c + d*x])^n*Sin[c + d*x])/d + (C*Sec[c + d*x]^(1 + m)*(b*Sec[c + d*x])^n*Sin[c + d*x])/(d*(1 + m + n))}

{Sec[c + d*x]^2*(b*Sec[c + d*x])^n*(A + B*Sec[c + d*x] + C*Sec[c + d*x]^2), x, 7, ((A + (A + C)*(2 + n))*(Cos[c + d*x]^2)^((1 + n)/2)*Hypergeometric2F1[1/2, (3 + n)/2, 3/2, Sin[c + d*x]^2]*(b*Sec[c + d*x])^(1 + n)*Sin[c + d*x])/(b*d*(3 + n)) + (B*(Cos[c + d*x]^2)^((2 + n)/2)*Hypergeometric2F1[1/2, (4 + n)/2, 3/2, Sin[c + d*x]^2]*(b*Sec[c + d*x])^(2 + n)*Sin[c + d*x])/(b^2*d) + (C*(b*Sec[c + d*x])^(2 + n)*Tan[c + d*x])/(b^2*d*(3 + n))}
{Sec[c + d*x]*(b*Sec[c + d*x])^n*(A + B*Sec[c + d*x] + C*Sec[c + d*x]^2), x, 7, ((A + (A + C)*(1 + n))*(Cos[c + d*x]^2)^(n/2)*Hypergeometric2F1[1/2, (2 + n)/2, 3/2, Sin[c + d*x]^2]*(b*Sec[c + d*x])^n*Sin[c + d*x])/(d*(2 + n)) + (B*(Cos[c + d*x]^2)^((1 + n)/2)*Hypergeometric2F1[1/2, (3 + n)/2, 3/2, Sin[c + d*x]^2]*(b*Sec[c + d*x])^(1 + n)*Sin[c + d*x])/(b*d) + (C*(b*Sec[c + d*x])^(1 + n)*Tan[c + d*x])/(b*d*(2 + n))}
{(b*Sec[c + d*x])^n*(A + B*Sec[c + d*x] + C*Sec[c + d*x]^2), x, 6, (b*(A + (A + C)*n)*(Cos[c + d*x]^2)^((1/2)*(-1 + n))*Hypergeometric2F1[1/2, (1 + n)/2, 3/2, Sin[c + d*x]^2]*(b*Sec[c + d*x])^(-1 + n)*Sin[c + d*x])/(d*(1 + n)) + (B*(Cos[c + d*x]^2)^(n/2)*Hypergeometric2F1[1/2, (2 + n)/2, 3/2, Sin[c + d*x]^2]*(b*Sec[c + d*x])^n*Sin[c + d*x])/d + (C*(b*Sec[c + d*x])^n*Tan[c + d*x])/(d*(1 + n))}
{Cos[c + d*x]*(b*Sec[c + d*x])^n*(A + B*Sec[c + d*x] + C*Sec[c + d*x]^2), x, 7, -((b^2*(C*(1 - n) - A*n)*(Cos[c + d*x]^2)^((1/2)*(-2 + n))*Hypergeometric2F1[1/2, n/2, 3/2, Sin[c + d*x]^2]*(b*Sec[c + d*x])^(-2 + n)*Sin[c + d*x])/(d*n)) + (b*B*(Cos[c + d*x]^2)^((1/2)*(-1 + n))*Hypergeometric2F1[1/2, (1 + n)/2, 3/2, Sin[c + d*x]^2]*(b*Sec[c + d*x])^(-1 + n)*Sin[c + d*x])/d + (b*C*(b*Sec[c + d*x])^(-1 + n)*Tan[c + d*x])/(d*n)}
{Cos[c + d*x]^2*(b*Sec[c + d*x])^n*(A + B*Sec[c + d*x] + C*Sec[c + d*x]^2), x, 7, (b^3*(A*(1 - n) + C*(2 - n))*(Cos[c + d*x]^2)^((1/2)*(-3 + n))*Hypergeometric2F1[1/2, (1/2)*(-1 + n), 3/2, Sin[c + d*x]^2]*(b*Sec[c + d*x])^(-3 + n)*Sin[c + d*x])/(d*(1 - n)) + (b^2*B*(Cos[c + d*x]^2)^((1/2)*(-2 + n))*Hypergeometric2F1[1/2, n/2, 3/2, Sin[c + d*x]^2]*(b*Sec[c + d*x])^(-2 + n)*Sin[c + d*x])/d - (b^2*C*(b*Sec[c + d*x])^(-2 + n)*Tan[c + d*x])/(d*(1 - n))}
{Cos[c + d*x]^3*(b*Sec[c + d*x])^n*(A + B*Sec[c + d*x] + C*Sec[c + d*x]^2), x, 7, (b^4*(A*(2 - n) + C*(3 - n))*(Cos[c + d*x]^2)^((1/2)*(-4 + n))*Hypergeometric2F1[1/2, (1/2)*(-2 + n), 3/2, Sin[c + d*x]^2]*(b*Sec[c + d*x])^(-4 + n)*Sin[c + d*x])/(d*(2 - n)) + (b^3*B*(Cos[c + d*x]^2)^((1/2)*(-3 + n))*Hypergeometric2F1[1/2, (1/2)*(-1 + n), 3/2, Sin[c + d*x]^2]*(b*Sec[c + d*x])^(-3 + n)*Sin[c + d*x])/d - (b^3*C*(b*Sec[c + d*x])^(-3 + n)*Tan[c + d*x])/(d*(2 - n))}
{Cos[c + d*x]^4*(b*Sec[c + d*x])^n*(A + B*Sec[c + d*x] + C*Sec[c + d*x]^2), x, 7, (b^5*(A*(3 - n) + C*(4 - n))*(Cos[c + d*x]^2)^((1/2)*(-5 + n))*Hypergeometric2F1[1/2, (1/2)*(-3 + n), 3/2, Sin[c + d*x]^2]*(b*Sec[c + d*x])^(-5 + n)*Sin[c + d*x])/(d*(3 - n)) + (b^4*B*(Cos[c + d*x]^2)^((1/2)*(-4 + n))*Hypergeometric2F1[1/2, (1/2)*(-2 + n), 3/2, Sin[c + d*x]^2]*(b*Sec[c + d*x])^(-4 + n)*Sin[c + d*x])/d - (b^4*C*(b*Sec[c + d*x])^(-4 + n)*Tan[c + d*x])/(d*(3 - n))}


{Sec[c + d*x]^(5/2)*(b*Sec[c + d*x])^n*(A + B*Sec[c + d*x] + C*Sec[c + d*x]^2), x, 7, ((2*A + (A + C)*(5 + 2*n))*(Cos[c + d*x]^2)^((3 + 2*n)/4)*Hypergeometric2F1[1/2, (7 + 2*n)/4, 3/2, Sin[c + d*x]^2]*Sec[c + d*x]^(3/2)*(b*Sec[c + d*x])^n*Sin[c + d*x])/(d*(7 + 2*n)) + (B*(Cos[c + d*x]^2)^((5 + 2*n)/4)*Hypergeometric2F1[1/2, (9 + 2*n)/4, 3/2, Sin[c + d*x]^2]*Sec[c + d*x]^(5/2)*(b*Sec[c + d*x])^n*Sin[c + d*x])/d + (2*C*Sec[c + d*x]^(7/2)*(b*Sec[c + d*x])^n*Sin[c + d*x])/(d*(7 + 2*n))}
{Sec[c + d*x]^(3/2)*(b*Sec[c + d*x])^n*(A + B*Sec[c + d*x] + C*Sec[c + d*x]^2), x, 7, ((2*A + (A + C)*(3 + 2*n))*(Cos[c + d*x]^2)^((1 + 2*n)/4)*Hypergeometric2F1[1/2, (5 + 2*n)/4, 3/2, Sin[c + d*x]^2]*Sqrt[Sec[c + d*x]]*(b*Sec[c + d*x])^n*Sin[c + d*x])/(d*(5 + 2*n)) + (B*(Cos[c + d*x]^2)^((3 + 2*n)/4)*Hypergeometric2F1[1/2, (7 + 2*n)/4, 3/2, Sin[c + d*x]^2]*Sec[c + d*x]^(3/2)*(b*Sec[c + d*x])^n*Sin[c + d*x])/d + (2*C*Sec[c + d*x]^(5/2)*(b*Sec[c + d*x])^n*Sin[c + d*x])/(d*(5 + 2*n))}
{Sqrt[Sec[c + d*x]]*(b*Sec[c + d*x])^n*(A + B*Sec[c + d*x] + C*Sec[c + d*x]^2), x, 7, ((C + 2*C*n + A*(3 + 2*n))*(Cos[c + d*x]^2)^((-1 + 2*n)/4)*Hypergeometric2F1[1/2, (3 + 2*n)/4, 3/2, Sin[c + d*x]^2]*(b*Sec[c + d*x])^n*Sin[c + d*x])/(d*(3 + 2*n)*Sqrt[Sec[c + d*x]]) + (B*(Cos[c + d*x]^2)^((1 + 2*n)/4)*Hypergeometric2F1[1/2, (5 + 2*n)/4, 3/2, Sin[c + d*x]^2]*Sqrt[Sec[c + d*x]]*(b*Sec[c + d*x])^n*Sin[c + d*x])/d + (2*C*Sec[c + d*x]^(3/2)*(b*Sec[c + d*x])^n*Sin[c + d*x])/(d*(3 + 2*n))}
{((b*Sec[c + d*x])^n*(A + B*Sec[c + d*x] + C*Sec[c + d*x]^2))/Sqrt[Sec[c + d*x]], x, 7, (B*(Cos[c + d*x]^2)^((-1 + 2*n)/4)*Hypergeometric2F1[1/2, (3 + 2*n)/4, 3/2, Sin[c + d*x]^2]*(b*Sec[c + d*x])^n*Sin[c + d*x])/(d*Sqrt[Sec[c + d*x]]) + (2*C*Sqrt[Sec[c + d*x]]*(b*Sec[c + d*x])^n*Sin[c + d*x])/(d*(1 + 2*n)) + ((A - C*(1 - 2*n) + 2*A*n)*(Cos[c + d*x]^2)^((1 + 2*n)/4)*Hypergeometric2F1[1/2, (1 + 2*n)/4, 3/2, Sin[c + d*x]^2]*Sqrt[Sec[c + d*x]]*(b*Sec[c + d*x])^n*Sin[c + d*x])/(d*(1 + 2*n))}
{((b*Sec[c + d*x])^n*(A + B*Sec[c + d*x] + C*Sec[c + d*x]^2))/Sec[c + d*x]^(3/2), x, 7, -(((2*A - (A + C)*(3 - 2*n))*(Cos[c + d*x]^2)^((-5 + 2*n)/4)*Hypergeometric2F1[1/2, (-1 + 2*n)/4, 3/2, Sin[c + d*x]^2]*(b*Sec[c + d*x])^n*Sin[c + d*x])/(d*(1 - 2*n)*Sec[c + d*x]^(5/2))) - (2*C*(b*Sec[c + d*x])^n*Sin[c + d*x])/(d*(1 - 2*n)*Sqrt[Sec[c + d*x]]) + (B*(Cos[c + d*x]^2)^((1 + 2*n)/4)*Hypergeometric2F1[1/2, (1 + 2*n)/4, 3/2, Sin[c + d*x]^2]*Sqrt[Sec[c + d*x]]*(b*Sec[c + d*x])^n*Sin[c + d*x])/d}
{((b*Sec[c + d*x])^n*(A + B*Sec[c + d*x] + C*Sec[c + d*x]^2))/Sec[c + d*x]^(5/2), x, 7, -(((2*A - (A + C)*(5 - 2*n))*(Cos[c + d*x]^2)^((-7 + 2*n)/4)*Hypergeometric2F1[1/2, (-3 + 2*n)/4, 3/2, Sin[c + d*x]^2]*(b*Sec[c + d*x])^n*Sin[c + d*x])/(d*(3 - 2*n)*Sec[c + d*x]^(7/2))) + (B*(Cos[c + d*x]^2)^((-5 + 2*n)/4)*Hypergeometric2F1[1/2, (-1 + 2*n)/4, 3/2, Sin[c + d*x]^2]*(b*Sec[c + d*x])^n*Sin[c + d*x])/(d*Sec[c + d*x]^(5/2)) - (2*C*(b*Sec[c + d*x])^n*Sin[c + d*x])/(d*(3 - 2*n)*Sec[c + d*x]^(3/2))}
{((b*Sec[c + d*x])^n*(A + B*Sec[c + d*x] + C*Sec[c + d*x]^2))/Sec[c + d*x]^(7/2), x, 7, -(((2*A - (A + C)*(7 - 2*n))*(Cos[c + d*x]^2)^((-9 + 2*n)/4)*Hypergeometric2F1[1/2, (-5 + 2*n)/4, 3/2, Sin[c + d*x]^2]*(b*Sec[c + d*x])^n*Sin[c + d*x])/(d*(5 - 2*n)*Sec[c + d*x]^(9/2))) + (B*(Cos[c + d*x]^2)^((-7 + 2*n)/4)*Hypergeometric2F1[1/2, (-3 + 2*n)/4, 3/2, Sin[c + d*x]^2]*(b*Sec[c + d*x])^n*Sin[c + d*x])/(d*Sec[c + d*x]^(7/2)) - (2*C*(b*Sec[c + d*x])^n*Sin[c + d*x])/(d*(5 - 2*n)*Sec[c + d*x]^(5/2))}
{((b*Sec[c + d*x])^n*(A + B*Sec[c + d*x] + C*Sec[c + d*x]^2))/Sec[c + d*x]^(9/2), x, 7, -(((2*A - (A + C)*(9 - 2*n))*(Cos[c + d*x]^2)^((-11 + 2*n)/4)*Hypergeometric2F1[1/2, (-7 + 2*n)/4, 3/2, Sin[c + d*x]^2]*(b*Sec[c + d*x])^n*Sin[c + d*x])/(d*(7 - 2*n)*Sec[c + d*x]^(11/2))) + (B*(Cos[c + d*x]^2)^((-9 + 2*n)/4)*Hypergeometric2F1[1/2, (-5 + 2*n)/4, 3/2, Sin[c + d*x]^2]*(b*Sec[c + d*x])^n*Sin[c + d*x])/(d*Sec[c + d*x]^(9/2)) - (2*C*(b*Sec[c + d*x])^n*Sin[c + d*x])/(d*(7 - 2*n)*Sec[c + d*x]^(7/2))}
