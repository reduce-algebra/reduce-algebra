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
{Sec[c + d*x]^0*Sqrt[b*Sec[c + d*x]], x, 2, (2*Sqrt[Cos[c + d*x]]*EllipticF[(1/2)*(c + d*x), 2]*Sqrt[b*Sec[c + d*x]])/d}
{Cos[c + d*x]^1*Sqrt[b*Sec[c + d*x]], x, 3, (2*b*EllipticE[(1/2)*(c + d*x), 2])/(d*Sqrt[Cos[c + d*x]]*Sqrt[b*Sec[c + d*x]])}
{Cos[c + d*x]^2*Sqrt[b*Sec[c + d*x]], x, 4, (2*Sqrt[Cos[c + d*x]]*EllipticF[(1/2)*(c + d*x), 2]*Sqrt[b*Sec[c + d*x]])/(3*d) + (2*b*Sin[c + d*x])/(3*d*Sqrt[b*Sec[c + d*x]])}
{Cos[c + d*x]^3*Sqrt[b*Sec[c + d*x]], x, 4, (6*b*EllipticE[(1/2)*(c + d*x), 2])/(5*d*Sqrt[Cos[c + d*x]]*Sqrt[b*Sec[c + d*x]]) + (2*b^2*Sin[c + d*x])/(5*d*(b*Sec[c + d*x])^(3/2))}
{Cos[c + d*x]^4*Sqrt[b*Sec[c + d*x]], x, 5, (10*Sqrt[Cos[c + d*x]]*EllipticF[(1/2)*(c + d*x), 2]*Sqrt[b*Sec[c + d*x]])/(21*d) + (2*b^3*Sin[c + d*x])/(7*d*(b*Sec[c + d*x])^(5/2)) + (10*b*Sin[c + d*x])/(21*d*Sqrt[b*Sec[c + d*x]])}
{Cos[c + d*x]^5*Sqrt[b*Sec[c + d*x]], x, 5, (14*b*EllipticE[(1/2)*(c + d*x), 2])/(15*d*Sqrt[Cos[c + d*x]]*Sqrt[b*Sec[c + d*x]]) + (2*b^4*Sin[c + d*x])/(9*d*(b*Sec[c + d*x])^(7/2)) + (14*b^2*Sin[c + d*x])/(45*d*(b*Sec[c + d*x])^(3/2))}


{Sec[c + d*x]^3*(b*Sec[c + d*x])^(3/2), x, 5, (10*b*Sqrt[Cos[c + d*x]]*EllipticF[(1/2)*(c + d*x), 2]*Sqrt[b*Sec[c + d*x]])/(21*d) + (10*(b*Sec[c + d*x])^(3/2)*Sin[c + d*x])/(21*d) + (2*(b*Sec[c + d*x])^(7/2)*Sin[c + d*x])/(7*b^2*d)}
{Sec[c + d*x]^2*(b*Sec[c + d*x])^(3/2), x, 5, -((6*b^2*EllipticE[(1/2)*(c + d*x), 2])/(5*d*Sqrt[Cos[c + d*x]]*Sqrt[b*Sec[c + d*x]])) + (6*b*Sqrt[b*Sec[c + d*x]]*Sin[c + d*x])/(5*d) + (2*(b*Sec[c + d*x])^(5/2)*Sin[c + d*x])/(5*b*d)}
{Sec[c + d*x]^1*(b*Sec[c + d*x])^(3/2), x, 4, (2*b*Sqrt[Cos[c + d*x]]*EllipticF[(1/2)*(c + d*x), 2]*Sqrt[b*Sec[c + d*x]])/(3*d) + (2*(b*Sec[c + d*x])^(3/2)*Sin[c + d*x])/(3*d)}
{Sec[c + d*x]^0*(b*Sec[c + d*x])^(3/2), x, 3, -((2*b^2*EllipticE[(1/2)*(c + d*x), 2])/(d*Sqrt[Cos[c + d*x]]*Sqrt[b*Sec[c + d*x]])) + (2*b*Sqrt[b*Sec[c + d*x]]*Sin[c + d*x])/d}
{Cos[c + d*x]^1*(b*Sec[c + d*x])^(3/2), x, 3, (2*b*Sqrt[Cos[c + d*x]]*EllipticF[(1/2)*(c + d*x), 2]*Sqrt[b*Sec[c + d*x]])/d}
{Cos[c + d*x]^2*(b*Sec[c + d*x])^(3/2), x, 3, (2*b^2*EllipticE[(1/2)*(c + d*x), 2])/(d*Sqrt[Cos[c + d*x]]*Sqrt[b*Sec[c + d*x]])}
{Cos[c + d*x]^3*(b*Sec[c + d*x])^(3/2), x, 4, (2*b*Sqrt[Cos[c + d*x]]*EllipticF[(1/2)*(c + d*x), 2]*Sqrt[b*Sec[c + d*x]])/(3*d) + (2*b^2*Sin[c + d*x])/(3*d*Sqrt[b*Sec[c + d*x]])}
{Cos[c + d*x]^4*(b*Sec[c + d*x])^(3/2), x, 4, (6*b^2*EllipticE[(1/2)*(c + d*x), 2])/(5*d*Sqrt[Cos[c + d*x]]*Sqrt[b*Sec[c + d*x]]) + (2*b^3*Sin[c + d*x])/(5*d*(b*Sec[c + d*x])^(3/2))}
{Cos[c + d*x]^5*(b*Sec[c + d*x])^(3/2), x, 5, (10*b*Sqrt[Cos[c + d*x]]*EllipticF[(1/2)*(c + d*x), 2]*Sqrt[b*Sec[c + d*x]])/(21*d) + (2*b^4*Sin[c + d*x])/(7*d*(b*Sec[c + d*x])^(5/2)) + (10*b^2*Sin[c + d*x])/(21*d*Sqrt[b*Sec[c + d*x]])}
{Cos[c + d*x]^6*(b*Sec[c + d*x])^(3/2), x, 5, (14*b^2*EllipticE[(1/2)*(c + d*x), 2])/(15*d*Sqrt[Cos[c + d*x]]*Sqrt[b*Sec[c + d*x]]) + (2*b^5*Sin[c + d*x])/(9*d*(b*Sec[c + d*x])^(7/2)) + (14*b^3*Sin[c + d*x])/(45*d*(b*Sec[c + d*x])^(3/2))}


{Sec[c + d*x]^2*(b*Sec[c + d*x])^(5/2), x, 5, (10*b^2*Sqrt[Cos[c + d*x]]*EllipticF[(1/2)*(c + d*x), 2]*Sqrt[b*Sec[c + d*x]])/(21*d) + (10*b*(b*Sec[c + d*x])^(3/2)*Sin[c + d*x])/(21*d) + (2*(b*Sec[c + d*x])^(7/2)*Sin[c + d*x])/(7*b*d)}
{Sec[c + d*x]^1*(b*Sec[c + d*x])^(5/2), x, 5, -((6*b^3*EllipticE[(1/2)*(c + d*x), 2])/(5*d*Sqrt[Cos[c + d*x]]*Sqrt[b*Sec[c + d*x]])) + (6*b^2*Sqrt[b*Sec[c + d*x]]*Sin[c + d*x])/(5*d) + (2*(b*Sec[c + d*x])^(5/2)*Sin[c + d*x])/(5*d)}
{Sec[c + d*x]^0*(b*Sec[c + d*x])^(5/2), x, 3, (2*b^2*Sqrt[Cos[c + d*x]]*EllipticF[(1/2)*(c + d*x), 2]*Sqrt[b*Sec[c + d*x]])/(3*d) + (2*b*(b*Sec[c + d*x])^(3/2)*Sin[c + d*x])/(3*d)}
{Cos[c + d*x]^1*(b*Sec[c + d*x])^(5/2), x, 4, -((2*b^3*EllipticE[(1/2)*(c + d*x), 2])/(d*Sqrt[Cos[c + d*x]]*Sqrt[b*Sec[c + d*x]])) + (2*b^2*Sqrt[b*Sec[c + d*x]]*Sin[c + d*x])/d}
{Cos[c + d*x]^2*(b*Sec[c + d*x])^(5/2), x, 3, (2*b^2*Sqrt[Cos[c + d*x]]*EllipticF[(1/2)*(c + d*x), 2]*Sqrt[b*Sec[c + d*x]])/d}
{Cos[c + d*x]^3*(b*Sec[c + d*x])^(5/2), x, 3, (2*b^3*EllipticE[(1/2)*(c + d*x), 2])/(d*Sqrt[Cos[c + d*x]]*Sqrt[b*Sec[c + d*x]])}
{Cos[c + d*x]^4*(b*Sec[c + d*x])^(5/2), x, 4, (2*b^2*Sqrt[Cos[c + d*x]]*EllipticF[(1/2)*(c + d*x), 2]*Sqrt[b*Sec[c + d*x]])/(3*d) + (2*b^3*Sin[c + d*x])/(3*d*Sqrt[b*Sec[c + d*x]])}
{Cos[c + d*x]^5*(b*Sec[c + d*x])^(5/2), x, 4, (6*b^3*EllipticE[(1/2)*(c + d*x), 2])/(5*d*Sqrt[Cos[c + d*x]]*Sqrt[b*Sec[c + d*x]]) + (2*b^4*Sin[c + d*x])/(5*d*(b*Sec[c + d*x])^(3/2))}
{Cos[c + d*x]^6*(b*Sec[c + d*x])^(5/2), x, 5, (10*b^2*Sqrt[Cos[c + d*x]]*EllipticF[(1/2)*(c + d*x), 2]*Sqrt[b*Sec[c + d*x]])/(21*d) + (2*b^5*Sin[c + d*x])/(7*d*(b*Sec[c + d*x])^(5/2)) + (10*b^3*Sin[c + d*x])/(21*d*Sqrt[b*Sec[c + d*x]])}
{Cos[c + d*x]^7*(b*Sec[c + d*x])^(5/2), x, 5, (14*b^3*EllipticE[(1/2)*(c + d*x), 2])/(15*d*Sqrt[Cos[c + d*x]]*Sqrt[b*Sec[c + d*x]]) + (2*b^6*Sin[c + d*x])/(9*d*(b*Sec[c + d*x])^(7/2)) + (14*b^4*Sin[c + d*x])/(45*d*(b*Sec[c + d*x])^(3/2))}


{Sec[c + d*x]^0*(b*Sec[c + d*x])^(7/2), x, 4, -((6*b^4*EllipticE[(1/2)*(c + d*x), 2])/(5*d*Sqrt[Cos[c + d*x]]*Sqrt[b*Sec[c + d*x]])) + (6*b^3*Sqrt[b*Sec[c + d*x]]*Sin[c + d*x])/(5*d) + (2*b*(b*Sec[c + d*x])^(5/2)*Sin[c + d*x])/(5*d)}


(* ::Subsubsection::Closed:: *)
(*n<0*)


{Sec[c + d*x]^5/Sqrt[b*Sec[c + d*x]], x, 5, (10*Sqrt[Cos[c + d*x]]*EllipticF[(1/2)*(c + d*x), 2]*Sqrt[b*Sec[c + d*x]])/(21*b*d) + (10*(b*Sec[c + d*x])^(3/2)*Sin[c + d*x])/(21*b^2*d) + (2*(b*Sec[c + d*x])^(7/2)*Sin[c + d*x])/(7*b^4*d)}
{Sec[c + d*x]^4/Sqrt[b*Sec[c + d*x]], x, 5, -((6*EllipticE[(1/2)*(c + d*x), 2])/(5*d*Sqrt[Cos[c + d*x]]*Sqrt[b*Sec[c + d*x]])) + (6*Sqrt[b*Sec[c + d*x]]*Sin[c + d*x])/(5*b*d) + (2*(b*Sec[c + d*x])^(5/2)*Sin[c + d*x])/(5*b^3*d)}
{Sec[c + d*x]^3/Sqrt[b*Sec[c + d*x]], x, 4, (2*Sqrt[Cos[c + d*x]]*EllipticF[(1/2)*(c + d*x), 2]*Sqrt[b*Sec[c + d*x]])/(3*b*d) + (2*(b*Sec[c + d*x])^(3/2)*Sin[c + d*x])/(3*b^2*d)}
{Sec[c + d*x]^2/Sqrt[b*Sec[c + d*x]], x, 4, -((2*EllipticE[(1/2)*(c + d*x), 2])/(d*Sqrt[Cos[c + d*x]]*Sqrt[b*Sec[c + d*x]])) + (2*Sqrt[b*Sec[c + d*x]]*Sin[c + d*x])/(b*d)}
{Sec[c + d*x]^1/Sqrt[b*Sec[c + d*x]], x, 3, (2*Sqrt[Cos[c + d*x]]*EllipticF[(1/2)*(c + d*x), 2]*Sqrt[b*Sec[c + d*x]])/(b*d)}
{Sec[c + d*x]^0/Sqrt[b*Sec[c + d*x]], x, 2, (2*EllipticE[(1/2)*(c + d*x), 2])/(d*Sqrt[Cos[c + d*x]]*Sqrt[b*Sec[c + d*x]])}
{Cos[c + d*x]^1/Sqrt[b*Sec[c + d*x]], x, 4, (2*Sqrt[Cos[c + d*x]]*EllipticF[(1/2)*(c + d*x), 2]*Sqrt[b*Sec[c + d*x]])/(3*b*d) + (2*Sin[c + d*x])/(3*d*Sqrt[b*Sec[c + d*x]])}
{Cos[c + d*x]^2/Sqrt[b*Sec[c + d*x]], x, 4, (6*EllipticE[(1/2)*(c + d*x), 2])/(5*d*Sqrt[Cos[c + d*x]]*Sqrt[b*Sec[c + d*x]]) + (2*b*Sin[c + d*x])/(5*d*(b*Sec[c + d*x])^(3/2))}
{Cos[c + d*x]^3/Sqrt[b*Sec[c + d*x]], x, 5, (10*Sqrt[Cos[c + d*x]]*EllipticF[(1/2)*(c + d*x), 2]*Sqrt[b*Sec[c + d*x]])/(21*b*d) + (2*b^2*Sin[c + d*x])/(7*d*(b*Sec[c + d*x])^(5/2)) + (10*Sin[c + d*x])/(21*d*Sqrt[b*Sec[c + d*x]])}
{Cos[c + d*x]^4/Sqrt[b*Sec[c + d*x]], x, 5, (14*EllipticE[(1/2)*(c + d*x), 2])/(15*d*Sqrt[Cos[c + d*x]]*Sqrt[b*Sec[c + d*x]]) + (2*b^3*Sin[c + d*x])/(9*d*(b*Sec[c + d*x])^(7/2)) + (14*b*Sin[c + d*x])/(45*d*(b*Sec[c + d*x])^(3/2))}


{Sec[c + d*x]^6/(b*Sec[c + d*x])^(3/2), x, 5, (10*Sqrt[Cos[c + d*x]]*EllipticF[(1/2)*(c + d*x), 2]*Sqrt[b*Sec[c + d*x]])/(21*b^2*d) + (10*(b*Sec[c + d*x])^(3/2)*Sin[c + d*x])/(21*b^3*d) + (2*(b*Sec[c + d*x])^(7/2)*Sin[c + d*x])/(7*b^5*d)}
{Sec[c + d*x]^5/(b*Sec[c + d*x])^(3/2), x, 5, -((6*EllipticE[(1/2)*(c + d*x), 2])/(5*b*d*Sqrt[Cos[c + d*x]]*Sqrt[b*Sec[c + d*x]])) + (6*Sqrt[b*Sec[c + d*x]]*Sin[c + d*x])/(5*b^2*d) + (2*(b*Sec[c + d*x])^(5/2)*Sin[c + d*x])/(5*b^4*d)}
{Sec[c + d*x]^4/(b*Sec[c + d*x])^(3/2), x, 4, (2*Sqrt[Cos[c + d*x]]*EllipticF[(1/2)*(c + d*x), 2]*Sqrt[b*Sec[c + d*x]])/(3*b^2*d) + (2*(b*Sec[c + d*x])^(3/2)*Sin[c + d*x])/(3*b^3*d)}
{Sec[c + d*x]^3/(b*Sec[c + d*x])^(3/2), x, 4, -((2*EllipticE[(1/2)*(c + d*x), 2])/(b*d*Sqrt[Cos[c + d*x]]*Sqrt[b*Sec[c + d*x]])) + (2*Sqrt[b*Sec[c + d*x]]*Sin[c + d*x])/(b^2*d)}
{Sec[c + d*x]^2/(b*Sec[c + d*x])^(3/2), x, 3, (2*Sqrt[Cos[c + d*x]]*EllipticF[(1/2)*(c + d*x), 2]*Sqrt[b*Sec[c + d*x]])/(b^2*d)}
{Sec[c + d*x]^1/(b*Sec[c + d*x])^(3/2), x, 3, (2*EllipticE[(c + d*x)/2, 2])/(b*d*Sqrt[Cos[c + d*x]]*Sqrt[b*Sec[c + d*x]])}
{Sec[c + d*x]^0/(b*Sec[c + d*x])^(3/2), x, 3, (2*Sqrt[Cos[c + d*x]]*EllipticF[(1/2)*(c + d*x), 2]*Sqrt[b*Sec[c + d*x]])/(3*b^2*d) + (2*Sin[c + d*x])/(3*b*d*Sqrt[b*Sec[c + d*x]])}
{Cos[c + d*x]^1/(b*Sec[c + d*x])^(3/2), x, 4, (6*EllipticE[(1/2)*(c + d*x), 2])/(5*b*d*Sqrt[Cos[c + d*x]]*Sqrt[b*Sec[c + d*x]]) + (2*Sin[c + d*x])/(5*d*(b*Sec[c + d*x])^(3/2))}
{Cos[c + d*x]^2/(b*Sec[c + d*x])^(3/2), x, 5, (10*Sqrt[Cos[c + d*x]]*EllipticF[(1/2)*(c + d*x), 2]*Sqrt[b*Sec[c + d*x]])/(21*b^2*d) + (2*b*Sin[c + d*x])/(7*d*(b*Sec[c + d*x])^(5/2)) + (10*Sin[c + d*x])/(21*b*d*Sqrt[b*Sec[c + d*x]])}
{Cos[c + d*x]^3/(b*Sec[c + d*x])^(3/2), x, 5, (14*EllipticE[(1/2)*(c + d*x), 2])/(15*b*d*Sqrt[Cos[c + d*x]]*Sqrt[b*Sec[c + d*x]]) + (2*b^2*Sin[c + d*x])/(9*d*(b*Sec[c + d*x])^(7/2)) + (14*Sin[c + d*x])/(45*d*(b*Sec[c + d*x])^(3/2))}


{Sec[c + d*x]^7/(b*Sec[c + d*x])^(5/2), x, 5, (10*Sqrt[Cos[c + d*x]]*EllipticF[(1/2)*(c + d*x), 2]*Sqrt[b*Sec[c + d*x]])/(21*b^3*d) + (10*(b*Sec[c + d*x])^(3/2)*Sin[c + d*x])/(21*b^4*d) + (2*(b*Sec[c + d*x])^(7/2)*Sin[c + d*x])/(7*b^6*d)}
{Sec[c + d*x]^6/(b*Sec[c + d*x])^(5/2), x, 5, -((6*EllipticE[(1/2)*(c + d*x), 2])/(5*b^2*d*Sqrt[Cos[c + d*x]]*Sqrt[b*Sec[c + d*x]])) + (6*Sqrt[b*Sec[c + d*x]]*Sin[c + d*x])/(5*b^3*d) + (2*(b*Sec[c + d*x])^(5/2)*Sin[c + d*x])/(5*b^5*d)}
{Sec[c + d*x]^5/(b*Sec[c + d*x])^(5/2), x, 4, (2*Sqrt[Cos[c + d*x]]*EllipticF[(1/2)*(c + d*x), 2]*Sqrt[b*Sec[c + d*x]])/(3*b^3*d) + (2*(b*Sec[c + d*x])^(3/2)*Sin[c + d*x])/(3*b^4*d)}
{Sec[c + d*x]^4/(b*Sec[c + d*x])^(5/2), x, 4, -((2*EllipticE[(1/2)*(c + d*x), 2])/(b^2*d*Sqrt[Cos[c + d*x]]*Sqrt[b*Sec[c + d*x]])) + (2*Sqrt[b*Sec[c + d*x]]*Sin[c + d*x])/(b^3*d)}
{Sec[c + d*x]^3/(b*Sec[c + d*x])^(5/2), x, 3, (2*Sqrt[Cos[c + d*x]]*EllipticF[(1/2)*(c + d*x), 2]*Sqrt[b*Sec[c + d*x]])/(b^3*d)}
{Sec[c + d*x]^2/(b*Sec[c + d*x])^(5/2), x, 3, (2*EllipticE[(c + d*x)/2, 2])/(b^2*d*Sqrt[Cos[c + d*x]]*Sqrt[b*Sec[c + d*x]])}
{Sec[c + d*x]^1/(b*Sec[c + d*x])^(5/2), x, 4, (2*Sqrt[Cos[c + d*x]]*EllipticF[(1/2)*(c + d*x), 2]*Sqrt[b*Sec[c + d*x]])/(3*b^3*d) + (2*Sin[c + d*x])/(3*b^2*d*Sqrt[b*Sec[c + d*x]])}
{Sec[c + d*x]^0/(b*Sec[c + d*x])^(5/2), x, 3, (6*EllipticE[(1/2)*(c + d*x), 2])/(5*b^2*d*Sqrt[Cos[c + d*x]]*Sqrt[b*Sec[c + d*x]]) + (2*Sin[c + d*x])/(5*b*d*(b*Sec[c + d*x])^(3/2))}
{Cos[c + d*x]^1/(b*Sec[c + d*x])^(5/2), x, 5, (10*Sqrt[Cos[c + d*x]]*EllipticF[(1/2)*(c + d*x), 2]*Sqrt[b*Sec[c + d*x]])/(21*b^3*d) + (2*Sin[c + d*x])/(7*d*(b*Sec[c + d*x])^(5/2)) + (10*Sin[c + d*x])/(21*b^2*d*Sqrt[b*Sec[c + d*x]])}
{Cos[c + d*x]^2/(b*Sec[c + d*x])^(5/2), x, 5, (14*EllipticE[(1/2)*(c + d*x), 2])/(15*b^2*d*Sqrt[Cos[c + d*x]]*Sqrt[b*Sec[c + d*x]]) + (2*b*Sin[c + d*x])/(9*d*(b*Sec[c + d*x])^(7/2)) + (14*Sin[c + d*x])/(45*b*d*(b*Sec[c + d*x])^(3/2))}


{Sec[c + d*x]^0/(b*Sec[c + d*x])^(7/2), x, 4, (10*Sqrt[Cos[c + d*x]]*EllipticF[(1/2)*(c + d*x), 2]*Sqrt[b*Sec[c + d*x]])/(21*b^4*d) + (2*Sin[c + d*x])/(7*b*d*(b*Sec[c + d*x])^(5/2)) + (10*Sin[c + d*x])/(21*b^3*d*Sqrt[b*Sec[c + d*x]])}


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


(* ::Section:: *)
(*Sec[c+d x]^m (A+B Sec[c+d x]) (b Sec[c+d x])^(n/2)*)


(* ::Subsection::Closed:: *)
(*Integrands of the form Sec[c+d x]^m (A+B Sec[c+d x]) (b Sec[c+d x])^(n/2)*)


(* ::Subsubsection::Closed:: *)
(*n>0*)


{Sec[c + d*x]^0*(b*Sec[c + d*x])^(5/2)*(A + B*Sec[c + d*x]), x, 7, -((6*b^3*B*EllipticE[(1/2)*(c + d*x), 2])/(5*d*Sqrt[Cos[c + d*x]]*Sqrt[b*Sec[c + d*x]])) + (2*A*b^3*EllipticF[(1/2)*(c + d*x), 2])/(3*d*Sqrt[Cos[c + d*x]]*Sqrt[b*Sec[c + d*x]]) + (6*b^2*B*Sqrt[b*Sec[c + d*x]]*Sin[c + d*x])/(5*d) + (2*A*b*(b*Sec[c + d*x])^(3/2)*Sin[c + d*x])/(3*d) + (2*B*(b*Sec[c + d*x])^(5/2)*Sin[c + d*x])/(5*d)}
{Sec[c + d*x]^0*(b*Sec[c + d*x])^(3/2)*(A + B*Sec[c + d*x]), x, 6, -((2*A*b^2*EllipticE[(1/2)*(c + d*x), 2])/(d*Sqrt[Cos[c + d*x]]*Sqrt[b*Sec[c + d*x]])) + (2*b^2*B*EllipticF[(1/2)*(c + d*x), 2])/(3*d*Sqrt[Cos[c + d*x]]*Sqrt[b*Sec[c + d*x]]) + (2*A*b*Sqrt[b*Sec[c + d*x]]*Sin[c + d*x])/d + (2*B*(b*Sec[c + d*x])^(3/2)*Sin[c + d*x])/(3*d)}
{Sec[c + d*x]^0*(b*Sec[c + d*x])^(1/2)*(A + B*Sec[c + d*x]), x, 5, -((2*b*B*EllipticE[(1/2)*(c + d*x), 2])/(d*Sqrt[Cos[c + d*x]]*Sqrt[b*Sec[c + d*x]])) + (2*A*b*EllipticF[(1/2)*(c + d*x), 2])/(d*Sqrt[Cos[c + d*x]]*Sqrt[b*Sec[c + d*x]]) + (2*B*Sqrt[b*Sec[c + d*x]]*Sin[c + d*x])/d}


(* ::Subsubsection::Closed:: *)
(*n<0*)


{Sec[c + d*x]^0*(A + B*Sec[c + d*x])/(b*Sec[c + d*x])^(1/2), x, 4, (2*A*EllipticE[(1/2)*(c + d*x), 2])/(d*Sqrt[Cos[c + d*x]]*Sqrt[b*Sec[c + d*x]]) + (2*B*EllipticF[(1/2)*(c + d*x), 2])/(d*Sqrt[Cos[c + d*x]]*Sqrt[b*Sec[c + d*x]])}
{Sec[c + d*x]^0*(A + B*Sec[c + d*x])/(b*Sec[c + d*x])^(3/2), x, 5, (2*B*EllipticE[(1/2)*(c + d*x), 2])/(b*d*Sqrt[Cos[c + d*x]]*Sqrt[b*Sec[c + d*x]]) + (2*A*EllipticF[(1/2)*(c + d*x), 2])/(3*b*d*Sqrt[Cos[c + d*x]]*Sqrt[b*Sec[c + d*x]]) + (2*A*Sin[c + d*x])/(3*b*d*Sqrt[b*Sec[c + d*x]])}
{Sec[c + d*x]^0*(A + B*Sec[c + d*x])/(b*Sec[c + d*x])^(5/2), x, 6, (6*A*EllipticE[(1/2)*(c + d*x), 2])/(5*b^2*d*Sqrt[Cos[c + d*x]]*Sqrt[b*Sec[c + d*x]]) + (2*B*EllipticF[(1/2)*(c + d*x), 2])/(3*b^2*d*Sqrt[Cos[c + d*x]]*Sqrt[b*Sec[c + d*x]]) + (2*A*Sin[c + d*x])/(5*b*d*(b*Sec[c + d*x])^(3/2)) + (2*B*Sin[c + d*x])/(3*b^2*d*Sqrt[b*Sec[c + d*x]])}


(* ::Subsection:: *)
(*Integrands of the form Sec[c+d x]^(m/2) (A+B Sec[c+d x]) (b Sec[c+d x])^(n/2)*)


(* ::Section:: *)
(*Sec[c+d x]^m (A+C Sec[c+d x]^2) (b Sec[c+d x])^(n/2)*)


(* ::Subsection::Closed:: *)
(*Integrands of the form Sec[c+d x]^m (A+C Sec[c+d x]^2) (b Sec[c+d x])^(n/2)*)


(* ::Subsubsection::Closed:: *)
(*n>0*)


{Sec[c + d*x]^0*(A + C*Sec[c + d*x]^2)*(b*Sec[c + d*x])^(5/2), x, 4, (2*b^2*(7*A + 5*C)*Sqrt[Cos[c + d*x]]*EllipticF[(1/2)*(c + d*x), 2]*Sqrt[b*Sec[c + d*x]])/(21*d) + (2*b*(7*A + 5*C)*(b*Sec[c + d*x])^(3/2)*Sin[c + d*x])/(21*d) + (2*C*(b*Sec[c + d*x])^(7/2)*Sin[c + d*x])/(7*b*d)}
{Sec[c + d*x]^0*(A + C*Sec[c + d*x]^2)*(b*Sec[c + d*x])^(3/2), x, 4, -((2*b^2*(5*A + 3*C)*EllipticE[(1/2)*(c + d*x), 2])/(5*d*Sqrt[Cos[c + d*x]]*Sqrt[b*Sec[c + d*x]])) + (2*b*(5*A + 3*C)*Sqrt[b*Sec[c + d*x]]*Sin[c + d*x])/(5*d) + (2*C*(b*Sec[c + d*x])^(5/2)*Sin[c + d*x])/(5*b*d)}
{Sec[c + d*x]^0*(A + C*Sec[c + d*x]^2)*(b*Sec[c + d*x])^(1/2), x, 3, (2*(3*A + C)*Sqrt[Cos[c + d*x]]*EllipticF[(1/2)*(c + d*x), 2]*Sqrt[b*Sec[c + d*x]])/(3*d) + (2*C*Sqrt[b*Sec[c + d*x]]*Tan[c + d*x])/(3*d)}


(* ::Subsubsection::Closed:: *)
(*n<0*)


{Sec[c + d*x]^0*(A + C*Sec[c + d*x]^2)/(b*Sec[c + d*x])^(1/2), x, 3, (2*(A - C)*EllipticE[(1/2)*(c + d*x), 2])/(d*Sqrt[Cos[c + d*x]]*Sqrt[b*Sec[c + d*x]]) + (2*C*Tan[c + d*x])/(d*Sqrt[b*Sec[c + d*x]])}
{Sec[c + d*x]^0*(A + C*Sec[c + d*x]^2)/(b*Sec[c + d*x])^(3/2), x, 3, (2*(A + 3*C)*Sqrt[Cos[c + d*x]]*EllipticF[(1/2)*(c + d*x), 2]*Sqrt[b*Sec[c + d*x]])/(3*b^2*d) + (2*A*Sin[c + d*x])/(3*b*d*Sqrt[b*Sec[c + d*x]])}
{Sec[c + d*x]^0*(A + C*Sec[c + d*x]^2)/(b*Sec[c + d*x])^(5/2), x, 3, (2*(3*A + 5*C)*EllipticE[(1/2)*(c + d*x), 2])/(5*b^2*d*Sqrt[Cos[c + d*x]]*Sqrt[b*Sec[c + d*x]]) + (2*A*Sin[c + d*x])/(5*b*d*(b*Sec[c + d*x])^(3/2))}
{Sec[c + d*x]^0*(A + C*Sec[c + d*x]^2)/(b*Sec[c + d*x])^(7/2), x, 4, (2*(5*A + 7*C)*Sqrt[Cos[c + d*x]]*EllipticF[(1/2)*(c + d*x), 2]*Sqrt[b*Sec[c + d*x]])/(21*b^4*d) + (2*A*Sin[c + d*x])/(7*b*d*(b*Sec[c + d*x])^(5/2)) + (2*(5*A + 7*C)*Sin[c + d*x])/(21*b^3*d*Sqrt[b*Sec[c + d*x]])}


(* ::Subsection:: *)
(*Integrands of the form Sec[c+d x]^(m/2) (A+C Sec[c+d x]^2) (b Sec[c+d x])^(n/2)*)


(* ::Section:: *)
(*Sec[c+d x]^m (B Sec[c+d x]+C Sec[c+d x]^2) (b Sec[c+d x])^(n/2)*)


(* ::Subsection::Closed:: *)
(*Integrands of the form Sec[c+d x]^m (B Sec[c+d x]+C Sec[c+d x]^2) (b Sec[c+d x])^(n/2)*)


(* ::Subsubsection::Closed:: *)
(*n>0*)


{Sec[c + d*x]^0*(B*Sec[c + d*x] + C*Sec[c + d*x]^2)*(b*Sec[c + d*x])^(3/2), x, 7, -((6*b^2*C*EllipticE[(1/2)*(c + d*x), 2])/(5*d*Sqrt[Cos[c + d*x]]*Sqrt[b*Sec[c + d*x]])) + (2*b^2*B*EllipticF[(1/2)*(c + d*x), 2])/(3*d*Sqrt[Cos[c + d*x]]*Sqrt[b*Sec[c + d*x]]) + (6*b*C*Sqrt[b*Sec[c + d*x]]*Sin[c + d*x])/(5*d) + (2*B*(b*Sec[c + d*x])^(3/2)*Sin[c + d*x])/(3*d) + (2*C*(b*Sec[c + d*x])^(5/2)*Sin[c + d*x])/(5*b*d)}
{Sec[c + d*x]^0*(B*Sec[c + d*x] + C*Sec[c + d*x]^2)*(b*Sec[c + d*x])^(1/2), x, 6, -((2*b*B*EllipticE[(1/2)*(c + d*x), 2])/(d*Sqrt[Cos[c + d*x]]*Sqrt[b*Sec[c + d*x]])) + (2*b*C*EllipticF[(1/2)*(c + d*x), 2])/(3*d*Sqrt[Cos[c + d*x]]*Sqrt[b*Sec[c + d*x]]) + (2*B*Sqrt[b*Sec[c + d*x]]*Sin[c + d*x])/d + (2*C*(b*Sec[c + d*x])^(3/2)*Sin[c + d*x])/(3*b*d)}


(* ::Subsubsection::Closed:: *)
(*n<0*)


{Sec[c + d*x]^0*(B*Sec[c + d*x] + C*Sec[c + d*x]^2)/(b*Sec[c + d*x])^(1/2), x, 6, -((2*C*EllipticE[(1/2)*(c + d*x), 2])/(d*Sqrt[Cos[c + d*x]]*Sqrt[b*Sec[c + d*x]])) + (2*B*EllipticF[(1/2)*(c + d*x), 2])/(d*Sqrt[Cos[c + d*x]]*Sqrt[b*Sec[c + d*x]]) + (2*C*Tan[c + d*x])/(d*Sqrt[b*Sec[c + d*x]])}
{Sec[c + d*x]^0*(B*Sec[c + d*x] + C*Sec[c + d*x]^2)/(b*Sec[c + d*x])^(3/2), x, 5, (2*B*EllipticE[(1/2)*(c + d*x), 2])/(b*d*Sqrt[Cos[c + d*x]]*Sqrt[b*Sec[c + d*x]]) + (2*C*EllipticF[(1/2)*(c + d*x), 2])/(b*d*Sqrt[Cos[c + d*x]]*Sqrt[b*Sec[c + d*x]])}
{Sec[c + d*x]^0*(B*Sec[c + d*x] + C*Sec[c + d*x]^2)/(b*Sec[c + d*x])^(5/2), x, 6, (2*C*EllipticE[(1/2)*(c + d*x), 2])/(b^2*d*Sqrt[Cos[c + d*x]]*Sqrt[b*Sec[c + d*x]]) + (2*B*EllipticF[(1/2)*(c + d*x), 2])/(3*b^2*d*Sqrt[Cos[c + d*x]]*Sqrt[b*Sec[c + d*x]]) + (2*B*Sin[c + d*x])/(3*b^2*d*Sqrt[b*Sec[c + d*x]])}
{Sec[c + d*x]^0*(B*Sec[c + d*x] + C*Sec[c + d*x]^2)/(b*Sec[c + d*x])^(7/2), x, 7, (6*B*EllipticE[(1/2)*(c + d*x), 2])/(5*b^3*d*Sqrt[Cos[c + d*x]]*Sqrt[b*Sec[c + d*x]]) + (2*C*EllipticF[(1/2)*(c + d*x), 2])/(3*b^3*d*Sqrt[Cos[c + d*x]]*Sqrt[b*Sec[c + d*x]]) + (2*B*Sin[c + d*x])/(5*b^2*d*(b*Sec[c + d*x])^(3/2)) + (2*C*Sin[c + d*x])/(3*b^3*d*Sqrt[b*Sec[c + d*x]])}


(* ::Subsection:: *)
(*Integrands of the form Sec[c+d x]^(m/2) (B Sec[c+d x]+C Sec[c+d x]^2) (b Sec[c+d x])^(n/2)*)


(* ::Section:: *)
(*Sec[c+d x]^m (A+B Sec[c+d x]+C Sec[c+d x]^2) (b Sec[c+d x])^(n/2)*)


(* ::Subsection::Closed:: *)
(*Integrands of the form Sec[c+d x]^m (A+B Sec[c+d x]+C Sec[c+d x]^2) (b Sec[c+d x])^(n/2)*)


(* ::Subsubsection::Closed:: *)
(*n>0*)


{Sec[c + d*x]^0*(A + B*Sec[c + d*x] + C*Sec[c + d*x]^2)*(b*Sec[c + d*x])^(3/2), x, 7, -((2*b^2*(5*A + 3*C)*EllipticE[(1/2)*(c + d*x), 2])/(5*d*Sqrt[Cos[c + d*x]]*Sqrt[b*Sec[c + d*x]])) + (2*b^2*B*EllipticF[(1/2)*(c + d*x), 2])/(3*d*Sqrt[Cos[c + d*x]]*Sqrt[b*Sec[c + d*x]]) + (2*b*(5*A + 3*C)*Sqrt[b*Sec[c + d*x]]*Sin[c + d*x])/(5*d) + (2*B*(b*Sec[c + d*x])^(3/2)*Sin[c + d*x])/(3*d) + (2*C*(b*Sec[c + d*x])^(5/2)*Sin[c + d*x])/(5*b*d)}
{Sec[c + d*x]^0*(A + B*Sec[c + d*x] + C*Sec[c + d*x]^2)*(b*Sec[c + d*x])^(1/2), x, 6, -((2*B*Sqrt[Cos[c + d*x]]*EllipticE[(1/2)*(c + d*x), 2]*Sqrt[b*Sec[c + d*x]])/d) + (2*(3*A + C)*Sqrt[Cos[c + d*x]]*EllipticF[(1/2)*(c + d*x), 2]*Sqrt[b*Sec[c + d*x]])/(3*d) + (2*B*Sqrt[b*Sec[c + d*x]]*Sin[c + d*x])/d + (2*C*Sqrt[b*Sec[c + d*x]]*Tan[c + d*x])/(3*d)}


(* ::Subsubsection::Closed:: *)
(*n<0*)


{Sec[c + d*x]^0*(A + B*Sec[c + d*x] + C*Sec[c + d*x]^2)/(b*Sec[c + d*x])^(1/2), x, 5, (2*(A - C)*EllipticE[(1/2)*(c + d*x), 2])/(d*Sqrt[Cos[c + d*x]]*Sqrt[b*Sec[c + d*x]]) + (2*B*EllipticF[(1/2)*(c + d*x), 2])/(d*Sqrt[Cos[c + d*x]]*Sqrt[b*Sec[c + d*x]]) + (2*C*Tan[c + d*x])/(d*Sqrt[b*Sec[c + d*x]])}
{Sec[c + d*x]^0*(A + B*Sec[c + d*x] + C*Sec[c + d*x]^2)/(b*Sec[c + d*x])^(3/2), x, 6, (2*B*EllipticE[(1/2)*(c + d*x), 2])/(b*d*Sqrt[Cos[c + d*x]]*Sqrt[b*Sec[c + d*x]]) + (2*(A + 3*C)*EllipticF[(1/2)*(c + d*x), 2])/(3*b*d*Sqrt[Cos[c + d*x]]*Sqrt[b*Sec[c + d*x]]) + (2*A*Sin[c + d*x])/(3*b*d*Sqrt[b*Sec[c + d*x]])}
{Sec[c + d*x]^0*(A + B*Sec[c + d*x] + C*Sec[c + d*x]^2)/(b*Sec[c + d*x])^(5/2), x, 6, (2*(3*A + 5*C)*EllipticE[(1/2)*(c + d*x), 2])/(5*b^2*d*Sqrt[Cos[c + d*x]]*Sqrt[b*Sec[c + d*x]]) + (2*B*EllipticF[(1/2)*(c + d*x), 2])/(3*b^2*d*Sqrt[Cos[c + d*x]]*Sqrt[b*Sec[c + d*x]]) + (2*A*Sin[c + d*x])/(5*b*d*(b*Sec[c + d*x])^(3/2)) + (2*B*Sin[c + d*x])/(3*b^2*d*Sqrt[b*Sec[c + d*x]])}
{Sec[c + d*x]^0*(A + B*Sec[c + d*x] + C*Sec[c + d*x]^2)/(b*Sec[c + d*x])^(7/2), x, 7, (6*B*EllipticE[(1/2)*(c + d*x), 2])/(5*b^3*d*Sqrt[Cos[c + d*x]]*Sqrt[b*Sec[c + d*x]]) + (2*(5*A + 7*C)*EllipticF[(1/2)*(c + d*x), 2])/(21*b^3*d*Sqrt[Cos[c + d*x]]*Sqrt[b*Sec[c + d*x]]) + (2*A*Sin[c + d*x])/(7*b*d*(b*Sec[c + d*x])^(5/2)) + (2*B*Sin[c + d*x])/(5*b^2*d*(b*Sec[c + d*x])^(3/2)) + (2*(5*A + 7*C)*Sin[c + d*x])/(21*b^3*d*Sqrt[b*Sec[c + d*x]])}


(* ::Subsection:: *)
(*Integrands of the form Sec[c+d x]^(m/2) (A+B Sec[c+d x]+C Sec[c+d x]^2) (b Sec[c+d x])^(n/2)*)
