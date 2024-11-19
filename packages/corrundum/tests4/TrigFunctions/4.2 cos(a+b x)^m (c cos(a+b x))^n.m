(* ::Package:: *)

(* ::Title:: *)
(*Integration problems of the form *)
(*Cos[c+d x]^m (A+B Cos[c+d x]+C Cos[c+d x]^2) (b Cos[c+d x])^(n/2)*)


(* ::Section:: *)
(*Cos[c+d x]^m (b Cos[c+d x])^(n/2)*)


(* ::Subsection::Closed:: *)
(*Integrands of the form Cos[c+d x]^m (b Cos[c+d x])^(n/2)*)


(* ::Subsubsection::Closed:: *)
(*n>0*)


{Cos[c + d*x]^5*Sqrt[b*Cos[c + d*x]], x, 6, (30*b*Sqrt[Cos[c + d*x]]*EllipticF[(1/2)*(c + d*x), 2])/(77*d*Sqrt[b*Cos[c + d*x]]) + (30*Sqrt[b*Cos[c + d*x]]*Sin[c + d*x])/(77*d) + (18*(b*Cos[c + d*x])^(5/2)*Sin[c + d*x])/(77*b^2*d) + (2*(b*Cos[c + d*x])^(9/2)*Sin[c + d*x])/(11*b^4*d)}
{Cos[c + d*x]^4*Sqrt[b*Cos[c + d*x]], x, 5, (14*Sqrt[b*Cos[c + d*x]]*EllipticE[(1/2)*(c + d*x), 2])/(15*d*Sqrt[Cos[c + d*x]]) + (14*(b*Cos[c + d*x])^(3/2)*Sin[c + d*x])/(45*b*d) + (2*(b*Cos[c + d*x])^(7/2)*Sin[c + d*x])/(9*b^3*d)}
{Cos[c + d*x]^3*Sqrt[b*Cos[c + d*x]], x, 5, (10*b*Sqrt[Cos[c + d*x]]*EllipticF[(1/2)*(c + d*x), 2])/(21*d*Sqrt[b*Cos[c + d*x]]) + (10*Sqrt[b*Cos[c + d*x]]*Sin[c + d*x])/(21*d) + (2*(b*Cos[c + d*x])^(5/2)*Sin[c + d*x])/(7*b^2*d)}
{Cos[c + d*x]^2*Sqrt[b*Cos[c + d*x]], x, 4, (6*Sqrt[b*Cos[c + d*x]]*EllipticE[(1/2)*(c + d*x), 2])/(5*d*Sqrt[Cos[c + d*x]]) + (2*(b*Cos[c + d*x])^(3/2)*Sin[c + d*x])/(5*b*d)}
{Cos[c + d*x]^1*Sqrt[b*Cos[c + d*x]], x, 4, (2*b*Sqrt[Cos[c + d*x]]*EllipticF[(1/2)*(c + d*x), 2])/(3*d*Sqrt[b*Cos[c + d*x]]) + (2*Sqrt[b*Cos[c + d*x]]*Sin[c + d*x])/(3*d)}
{Cos[c + d*x]^0*Sqrt[b*Cos[c + d*x]], x, 2, (2*Sqrt[b*Cos[c + d*x]]*EllipticE[(c + d*x)/2, 2])/(d*Sqrt[Cos[c + d*x]])}
{Sqrt[b*Cos[c + d*x]]*Sec[c + d*x]^1, x, 3, (2*b*Sqrt[Cos[c + d*x]]*EllipticF[(c + d*x)/2, 2])/(d*Sqrt[b*Cos[c + d*x]])}
{Sqrt[b*Cos[c + d*x]]*Sec[c + d*x]^2, x, 4, -((2*Sqrt[b*Cos[c + d*x]]*EllipticE[(1/2)*(c + d*x), 2])/(d*Sqrt[Cos[c + d*x]])) + (2*b*Sin[c + d*x])/(d*Sqrt[b*Cos[c + d*x]])}
{Sqrt[b*Cos[c + d*x]]*Sec[c + d*x]^3, x, 4, (2*b*Sqrt[Cos[c + d*x]]*EllipticF[(1/2)*(c + d*x), 2])/(3*d*Sqrt[b*Cos[c + d*x]]) + (2*b^2*Sin[c + d*x])/(3*d*(b*Cos[c + d*x])^(3/2))}
{Sqrt[b*Cos[c + d*x]]*Sec[c + d*x]^4, x, 5, -((6*Sqrt[b*Cos[c + d*x]]*EllipticE[(1/2)*(c + d*x), 2])/(5*d*Sqrt[Cos[c + d*x]])) + (2*b^3*Sin[c + d*x])/(5*d*(b*Cos[c + d*x])^(5/2)) + (6*b*Sin[c + d*x])/(5*d*Sqrt[b*Cos[c + d*x]])}
{Sqrt[b*Cos[c + d*x]]*Sec[c + d*x]^5, x, 5, (10*b*Sqrt[Cos[c + d*x]]*EllipticF[(1/2)*(c + d*x), 2])/(21*d*Sqrt[b*Cos[c + d*x]]) + (2*b^4*Sin[c + d*x])/(7*d*(b*Cos[c + d*x])^(7/2)) + (10*b^2*Sin[c + d*x])/(21*d*(b*Cos[c + d*x])^(3/2))}
{Sqrt[b*Cos[c + d*x]]*Sec[c + d*x]^6, x, 6, -((14*Sqrt[b*Cos[c + d*x]]*EllipticE[(1/2)*(c + d*x), 2])/(15*d*Sqrt[Cos[c + d*x]])) + (2*b^5*Sin[c + d*x])/(9*d*(b*Cos[c + d*x])^(9/2)) + (14*b^3*Sin[c + d*x])/(45*d*(b*Cos[c + d*x])^(5/2)) + (14*b*Sin[c + d*x])/(15*d*Sqrt[b*Cos[c + d*x]])}


{Cos[c + d*x]^4*(b*Cos[c + d*x])^(3/2), x, 6, (30*b^2*Sqrt[Cos[c + d*x]]*EllipticF[(1/2)*(c + d*x), 2])/(77*d*Sqrt[b*Cos[c + d*x]]) + (30*b*Sqrt[b*Cos[c + d*x]]*Sin[c + d*x])/(77*d) + (18*(b*Cos[c + d*x])^(5/2)*Sin[c + d*x])/(77*b*d) + (2*(b*Cos[c + d*x])^(9/2)*Sin[c + d*x])/(11*b^3*d)}
{Cos[c + d*x]^3*(b*Cos[c + d*x])^(3/2), x, 5, (14*b*Sqrt[b*Cos[c + d*x]]*EllipticE[(1/2)*(c + d*x), 2])/(15*d*Sqrt[Cos[c + d*x]]) + (14*(b*Cos[c + d*x])^(3/2)*Sin[c + d*x])/(45*d) + (2*(b*Cos[c + d*x])^(7/2)*Sin[c + d*x])/(9*b^2*d)}
{Cos[c + d*x]^2*(b*Cos[c + d*x])^(3/2), x, 5, (10*b^2*Sqrt[Cos[c + d*x]]*EllipticF[(1/2)*(c + d*x), 2])/(21*d*Sqrt[b*Cos[c + d*x]]) + (10*b*Sqrt[b*Cos[c + d*x]]*Sin[c + d*x])/(21*d) + (2*(b*Cos[c + d*x])^(5/2)*Sin[c + d*x])/(7*b*d)}
{Cos[c + d*x]^1*(b*Cos[c + d*x])^(3/2), x, 4, (6*b*Sqrt[b*Cos[c + d*x]]*EllipticE[(1/2)*(c + d*x), 2])/(5*d*Sqrt[Cos[c + d*x]]) + (2*(b*Cos[c + d*x])^(3/2)*Sin[c + d*x])/(5*d)}
{Cos[c + d*x]^0*(b*Cos[c + d*x])^(3/2), x, 3, (2*b^2*Sqrt[Cos[c + d*x]]*EllipticF[(1/2)*(c + d*x), 2])/(3*d*Sqrt[b*Cos[c + d*x]]) + (2*b*Sqrt[b*Cos[c + d*x]]*Sin[c + d*x])/(3*d)}
{(b*Cos[c + d*x])^(3/2)*Sec[c + d*x]^1, x, 3, (2*b*Sqrt[b*Cos[c + d*x]]*EllipticE[(c + d*x)/2, 2])/(d*Sqrt[Cos[c + d*x]])}
{(b*Cos[c + d*x])^(3/2)*Sec[c + d*x]^2, x, 3, (2*b^2*Sqrt[Cos[c + d*x]]*EllipticF[(c + d*x)/2, 2])/(d*Sqrt[b*Cos[c + d*x]])}
{(b*Cos[c + d*x])^(3/2)*Sec[c + d*x]^3, x, 4, -((2*b*Sqrt[b*Cos[c + d*x]]*EllipticE[(1/2)*(c + d*x), 2])/(d*Sqrt[Cos[c + d*x]])) + (2*b^2*Sin[c + d*x])/(d*Sqrt[b*Cos[c + d*x]])}
{(b*Cos[c + d*x])^(3/2)*Sec[c + d*x]^4, x, 4, (2*b^2*Sqrt[Cos[c + d*x]]*EllipticF[(1/2)*(c + d*x), 2])/(3*d*Sqrt[b*Cos[c + d*x]]) + (2*b^3*Sin[c + d*x])/(3*d*(b*Cos[c + d*x])^(3/2))}
{(b*Cos[c + d*x])^(3/2)*Sec[c + d*x]^5, x, 5, -((6*b*Sqrt[b*Cos[c + d*x]]*EllipticE[(1/2)*(c + d*x), 2])/(5*d*Sqrt[Cos[c + d*x]])) + (2*b^4*Sin[c + d*x])/(5*d*(b*Cos[c + d*x])^(5/2)) + (6*b^2*Sin[c + d*x])/(5*d*Sqrt[b*Cos[c + d*x]])}
{(b*Cos[c + d*x])^(3/2)*Sec[c + d*x]^6, x, 5, (10*b^2*Sqrt[Cos[c + d*x]]*EllipticF[(1/2)*(c + d*x), 2])/(21*d*Sqrt[b*Cos[c + d*x]]) + (2*b^5*Sin[c + d*x])/(7*d*(b*Cos[c + d*x])^(7/2)) + (10*b^3*Sin[c + d*x])/(21*d*(b*Cos[c + d*x])^(3/2))}
{(b*Cos[c + d*x])^(3/2)*Sec[c + d*x]^7, x, 6, -((14*b*Sqrt[b*Cos[c + d*x]]*EllipticE[(1/2)*(c + d*x), 2])/(15*d*Sqrt[Cos[c + d*x]])) + (2*b^6*Sin[c + d*x])/(9*d*(b*Cos[c + d*x])^(9/2)) + (14*b^4*Sin[c + d*x])/(45*d*(b*Cos[c + d*x])^(5/2)) + (14*b^2*Sin[c + d*x])/(15*d*Sqrt[b*Cos[c + d*x]])}


{Cos[c + d*x]^3*(b*Cos[c + d*x])^(5/2), x, 6, (30*b^3*Sqrt[Cos[c + d*x]]*EllipticF[(1/2)*(c + d*x), 2])/(77*d*Sqrt[b*Cos[c + d*x]]) + (30*b^2*Sqrt[b*Cos[c + d*x]]*Sin[c + d*x])/(77*d) + (18*(b*Cos[c + d*x])^(5/2)*Sin[c + d*x])/(77*d) + (2*(b*Cos[c + d*x])^(9/2)*Sin[c + d*x])/(11*b^2*d)}
{Cos[c + d*x]^2*(b*Cos[c + d*x])^(5/2), x, 5, (14*b^2*Sqrt[b*Cos[c + d*x]]*EllipticE[(1/2)*(c + d*x), 2])/(15*d*Sqrt[Cos[c + d*x]]) + (14*b*(b*Cos[c + d*x])^(3/2)*Sin[c + d*x])/(45*d) + (2*(b*Cos[c + d*x])^(7/2)*Sin[c + d*x])/(9*b*d)}
{Cos[c + d*x]^1*(b*Cos[c + d*x])^(5/2), x, 5, (10*b^3*Sqrt[Cos[c + d*x]]*EllipticF[(1/2)*(c + d*x), 2])/(21*d*Sqrt[b*Cos[c + d*x]]) + (10*b^2*Sqrt[b*Cos[c + d*x]]*Sin[c + d*x])/(21*d) + (2*(b*Cos[c + d*x])^(5/2)*Sin[c + d*x])/(7*d)}
{Cos[c + d*x]^0*(b*Cos[c + d*x])^(5/2), x, 3, (6*b^2*Sqrt[b*Cos[c + d*x]]*EllipticE[(1/2)*(c + d*x), 2])/(5*d*Sqrt[Cos[c + d*x]]) + (2*b*(b*Cos[c + d*x])^(3/2)*Sin[c + d*x])/(5*d)}
{(b*Cos[c + d*x])^(5/2)*Sec[c + d*x]^1, x, 4, (2*b^3*Sqrt[Cos[c + d*x]]*EllipticF[(1/2)*(c + d*x), 2])/(3*d*Sqrt[b*Cos[c + d*x]]) + (2*b^2*Sqrt[b*Cos[c + d*x]]*Sin[c + d*x])/(3*d)}
{(b*Cos[c + d*x])^(5/2)*Sec[c + d*x]^2, x, 3, (2*b^2*Sqrt[b*Cos[c + d*x]]*EllipticE[(c + d*x)/2, 2])/(d*Sqrt[Cos[c + d*x]])}
{(b*Cos[c + d*x])^(5/2)*Sec[c + d*x]^3, x, 3, (2*b^3*Sqrt[Cos[c + d*x]]*EllipticF[(c + d*x)/2, 2])/(d*Sqrt[b*Cos[c + d*x]])}
{(b*Cos[c + d*x])^(5/2)*Sec[c + d*x]^4, x, 4, -((2*b^2*Sqrt[b*Cos[c + d*x]]*EllipticE[(1/2)*(c + d*x), 2])/(d*Sqrt[Cos[c + d*x]])) + (2*b^3*Sin[c + d*x])/(d*Sqrt[b*Cos[c + d*x]])}
{(b*Cos[c + d*x])^(5/2)*Sec[c + d*x]^5, x, 4, (2*b^3*Sqrt[Cos[c + d*x]]*EllipticF[(1/2)*(c + d*x), 2])/(3*d*Sqrt[b*Cos[c + d*x]]) + (2*b^4*Sin[c + d*x])/(3*d*(b*Cos[c + d*x])^(3/2))}
{(b*Cos[c + d*x])^(5/2)*Sec[c + d*x]^6, x, 5, -((6*b^2*Sqrt[b*Cos[c + d*x]]*EllipticE[(1/2)*(c + d*x), 2])/(5*d*Sqrt[Cos[c + d*x]])) + (2*b^5*Sin[c + d*x])/(5*d*(b*Cos[c + d*x])^(5/2)) + (6*b^3*Sin[c + d*x])/(5*d*Sqrt[b*Cos[c + d*x]])}
{(b*Cos[c + d*x])^(5/2)*Sec[c + d*x]^7, x, 5, (10*b^3*Sqrt[Cos[c + d*x]]*EllipticF[(1/2)*(c + d*x), 2])/(21*d*Sqrt[b*Cos[c + d*x]]) + (2*b^6*Sin[c + d*x])/(7*d*(b*Cos[c + d*x])^(7/2)) + (10*b^4*Sin[c + d*x])/(21*d*(b*Cos[c + d*x])^(3/2))}
{(b*Cos[c + d*x])^(5/2)*Sec[c + d*x]^8, x, 6, -((14*b^2*Sqrt[b*Cos[c + d*x]]*EllipticE[(1/2)*(c + d*x), 2])/(15*d*Sqrt[Cos[c + d*x]])) + (2*b^7*Sin[c + d*x])/(9*d*(b*Cos[c + d*x])^(9/2)) + (14*b^5*Sin[c + d*x])/(45*d*(b*Cos[c + d*x])^(5/2)) + (14*b^3*Sin[c + d*x])/(15*d*Sqrt[b*Cos[c + d*x]])}


{Cos[c + d*x]^0*(b*Cos[c + d*x])^(7/2), x, 4, (10*b^4*Sqrt[Cos[c + d*x]]*EllipticF[(1/2)*(c + d*x), 2])/(21*d*Sqrt[b*Cos[c + d*x]]) + (10*b^3*Sqrt[b*Cos[c + d*x]]*Sin[c + d*x])/(21*d) + (2*b*(b*Cos[c + d*x])^(5/2)*Sin[c + d*x])/(7*d)}


(* ::Subsubsection::Closed:: *)
(*n<0*)


{Cos[c + d*x]^6/Sqrt[b*Cos[c + d*x]], x, 6, (30*Sqrt[Cos[c + d*x]]*EllipticF[(1/2)*(c + d*x), 2])/(77*d*Sqrt[b*Cos[c + d*x]]) + (30*Sqrt[b*Cos[c + d*x]]*Sin[c + d*x])/(77*b*d) + (18*(b*Cos[c + d*x])^(5/2)*Sin[c + d*x])/(77*b^3*d) + (2*(b*Cos[c + d*x])^(9/2)*Sin[c + d*x])/(11*b^5*d)}
{Cos[c + d*x]^5/Sqrt[b*Cos[c + d*x]], x, 5, (14*Sqrt[b*Cos[c + d*x]]*EllipticE[(1/2)*(c + d*x), 2])/(15*b*d*Sqrt[Cos[c + d*x]]) + (14*(b*Cos[c + d*x])^(3/2)*Sin[c + d*x])/(45*b^2*d) + (2*(b*Cos[c + d*x])^(7/2)*Sin[c + d*x])/(9*b^4*d)}
{Cos[c + d*x]^4/Sqrt[b*Cos[c + d*x]], x, 5, (10*Sqrt[Cos[c + d*x]]*EllipticF[(1/2)*(c + d*x), 2])/(21*d*Sqrt[b*Cos[c + d*x]]) + (10*Sqrt[b*Cos[c + d*x]]*Sin[c + d*x])/(21*b*d) + (2*(b*Cos[c + d*x])^(5/2)*Sin[c + d*x])/(7*b^3*d)}
{Cos[c + d*x]^3/Sqrt[b*Cos[c + d*x]], x, 4, (6*Sqrt[b*Cos[c + d*x]]*EllipticE[(1/2)*(c + d*x), 2])/(5*b*d*Sqrt[Cos[c + d*x]]) + (2*(b*Cos[c + d*x])^(3/2)*Sin[c + d*x])/(5*b^2*d)}
{Cos[c + d*x]^2/Sqrt[b*Cos[c + d*x]], x, 4, (2*Sqrt[Cos[c + d*x]]*EllipticF[(1/2)*(c + d*x), 2])/(3*d*Sqrt[b*Cos[c + d*x]]) + (2*Sqrt[b*Cos[c + d*x]]*Sin[c + d*x])/(3*b*d)}
{Cos[c + d*x]^1/Sqrt[b*Cos[c + d*x]], x, 3, (2*Sqrt[b*Cos[c + d*x]]*EllipticE[(c + d*x)/2, 2])/(b*d*Sqrt[Cos[c + d*x]])}
{Cos[c + d*x]^0/Sqrt[b*Cos[c + d*x]], x, 2, (2*Sqrt[Cos[c + d*x]]*EllipticF[(c + d*x)/2, 2])/(d*Sqrt[b*Cos[c + d*x]])}
{Sec[c + d*x]^1/Sqrt[b*Cos[c + d*x]], x, 4, -((2*Sqrt[b*Cos[c + d*x]]*EllipticE[(1/2)*(c + d*x), 2])/(b*d*Sqrt[Cos[c + d*x]])) + (2*Sin[c + d*x])/(d*Sqrt[b*Cos[c + d*x]])}
{Sec[c + d*x]^2/Sqrt[b*Cos[c + d*x]], x, 4, (2*Sqrt[Cos[c + d*x]]*EllipticF[(1/2)*(c + d*x), 2])/(3*d*Sqrt[b*Cos[c + d*x]]) + (2*b*Sin[c + d*x])/(3*d*(b*Cos[c + d*x])^(3/2))}
{Sec[c + d*x]^3/Sqrt[b*Cos[c + d*x]], x, 5, -((6*Sqrt[b*Cos[c + d*x]]*EllipticE[(1/2)*(c + d*x), 2])/(5*b*d*Sqrt[Cos[c + d*x]])) + (2*b^2*Sin[c + d*x])/(5*d*(b*Cos[c + d*x])^(5/2)) + (6*Sin[c + d*x])/(5*d*Sqrt[b*Cos[c + d*x]])}
{Sec[c + d*x]^4/Sqrt[b*Cos[c + d*x]], x, 5, (10*Sqrt[Cos[c + d*x]]*EllipticF[(1/2)*(c + d*x), 2])/(21*d*Sqrt[b*Cos[c + d*x]]) + (2*b^3*Sin[c + d*x])/(7*d*(b*Cos[c + d*x])^(7/2)) + (10*b*Sin[c + d*x])/(21*d*(b*Cos[c + d*x])^(3/2))}
{Sec[c + d*x]^5/Sqrt[b*Cos[c + d*x]], x, 6, -((14*Sqrt[b*Cos[c + d*x]]*EllipticE[(1/2)*(c + d*x), 2])/(15*b*d*Sqrt[Cos[c + d*x]])) + (2*b^4*Sin[c + d*x])/(9*d*(b*Cos[c + d*x])^(9/2)) + (14*b^2*Sin[c + d*x])/(45*d*(b*Cos[c + d*x])^(5/2)) + (14*Sin[c + d*x])/(15*d*Sqrt[b*Cos[c + d*x]])}


{Cos[c + d*x]^7/(b*Cos[c + d*x])^(3/2), x, 6, (30*Sqrt[Cos[c + d*x]]*EllipticF[(1/2)*(c + d*x), 2])/(77*b*d*Sqrt[b*Cos[c + d*x]]) + (30*Sqrt[b*Cos[c + d*x]]*Sin[c + d*x])/(77*b^2*d) + (18*(b*Cos[c + d*x])^(5/2)*Sin[c + d*x])/(77*b^4*d) + (2*(b*Cos[c + d*x])^(9/2)*Sin[c + d*x])/(11*b^6*d)}
{Cos[c + d*x]^6/(b*Cos[c + d*x])^(3/2), x, 5, (14*Sqrt[b*Cos[c + d*x]]*EllipticE[(1/2)*(c + d*x), 2])/(15*b^2*d*Sqrt[Cos[c + d*x]]) + (14*(b*Cos[c + d*x])^(3/2)*Sin[c + d*x])/(45*b^3*d) + (2*(b*Cos[c + d*x])^(7/2)*Sin[c + d*x])/(9*b^5*d)}
{Cos[c + d*x]^5/(b*Cos[c + d*x])^(3/2), x, 5, (10*Sqrt[Cos[c + d*x]]*EllipticF[(1/2)*(c + d*x), 2])/(21*b*d*Sqrt[b*Cos[c + d*x]]) + (10*Sqrt[b*Cos[c + d*x]]*Sin[c + d*x])/(21*b^2*d) + (2*(b*Cos[c + d*x])^(5/2)*Sin[c + d*x])/(7*b^4*d)}
{Cos[c + d*x]^4/(b*Cos[c + d*x])^(3/2), x, 4, (6*Sqrt[b*Cos[c + d*x]]*EllipticE[(1/2)*(c + d*x), 2])/(5*b^2*d*Sqrt[Cos[c + d*x]]) + (2*(b*Cos[c + d*x])^(3/2)*Sin[c + d*x])/(5*b^3*d)}
{Cos[c + d*x]^3/(b*Cos[c + d*x])^(3/2), x, 4, (2*Sqrt[Cos[c + d*x]]*EllipticF[(1/2)*(c + d*x), 2])/(3*b*d*Sqrt[b*Cos[c + d*x]]) + (2*Sqrt[b*Cos[c + d*x]]*Sin[c + d*x])/(3*b^2*d)}
{Cos[c + d*x]^2/(b*Cos[c + d*x])^(3/2), x, 3, (2*Sqrt[b*Cos[c + d*x]]*EllipticE[(c + d*x)/2, 2])/(b^2*d*Sqrt[Cos[c + d*x]])}
{Cos[c + d*x]^1/(b*Cos[c + d*x])^(3/2), x, 3, (2*Sqrt[Cos[c + d*x]]*EllipticF[(c + d*x)/2, 2])/(b*d*Sqrt[b*Cos[c + d*x]])}
{Cos[c + d*x]^0/(b*Cos[c + d*x])^(3/2), x, 3, -((2*Sqrt[b*Cos[c + d*x]]*EllipticE[(1/2)*(c + d*x), 2])/(b^2*d*Sqrt[Cos[c + d*x]])) + (2*Sin[c + d*x])/(b*d*Sqrt[b*Cos[c + d*x]])}
{Sec[c + d*x]^1/(b*Cos[c + d*x])^(3/2), x, 4, (2*Sqrt[Cos[c + d*x]]*EllipticF[(1/2)*(c + d*x), 2])/(3*b*d*Sqrt[b*Cos[c + d*x]]) + (2*Sin[c + d*x])/(3*d*(b*Cos[c + d*x])^(3/2))}
{Sec[c + d*x]^2/(b*Cos[c + d*x])^(3/2), x, 5, -((6*Sqrt[b*Cos[c + d*x]]*EllipticE[(1/2)*(c + d*x), 2])/(5*b^2*d*Sqrt[Cos[c + d*x]])) + (2*b*Sin[c + d*x])/(5*d*(b*Cos[c + d*x])^(5/2)) + (6*Sin[c + d*x])/(5*b*d*Sqrt[b*Cos[c + d*x]])}
{Sec[c + d*x]^3/(b*Cos[c + d*x])^(3/2), x, 5, (10*Sqrt[Cos[c + d*x]]*EllipticF[(1/2)*(c + d*x), 2])/(21*b*d*Sqrt[b*Cos[c + d*x]]) + (2*b^2*Sin[c + d*x])/(7*d*(b*Cos[c + d*x])^(7/2)) + (10*Sin[c + d*x])/(21*d*(b*Cos[c + d*x])^(3/2))}
{Sec[c + d*x]^4/(b*Cos[c + d*x])^(3/2), x, 6, -((14*Sqrt[b*Cos[c + d*x]]*EllipticE[(1/2)*(c + d*x), 2])/(15*b^2*d*Sqrt[Cos[c + d*x]])) + (2*b^3*Sin[c + d*x])/(9*d*(b*Cos[c + d*x])^(9/2)) + (14*b*Sin[c + d*x])/(45*d*(b*Cos[c + d*x])^(5/2)) + (14*Sin[c + d*x])/(15*b*d*Sqrt[b*Cos[c + d*x]])}


{Cos[c + d*x]^8/(b*Cos[c + d*x])^(5/2), x, 6, (30*Sqrt[Cos[c + d*x]]*EllipticF[(1/2)*(c + d*x), 2])/(77*b^2*d*Sqrt[b*Cos[c + d*x]]) + (30*Sqrt[b*Cos[c + d*x]]*Sin[c + d*x])/(77*b^3*d) + (18*(b*Cos[c + d*x])^(5/2)*Sin[c + d*x])/(77*b^5*d) + (2*(b*Cos[c + d*x])^(9/2)*Sin[c + d*x])/(11*b^7*d)}
{Cos[c + d*x]^7/(b*Cos[c + d*x])^(5/2), x, 5, (14*Sqrt[b*Cos[c + d*x]]*EllipticE[(1/2)*(c + d*x), 2])/(15*b^3*d*Sqrt[Cos[c + d*x]]) + (14*(b*Cos[c + d*x])^(3/2)*Sin[c + d*x])/(45*b^4*d) + (2*(b*Cos[c + d*x])^(7/2)*Sin[c + d*x])/(9*b^6*d)}
{Cos[c + d*x]^6/(b*Cos[c + d*x])^(5/2), x, 5, (10*Sqrt[Cos[c + d*x]]*EllipticF[(1/2)*(c + d*x), 2])/(21*b^2*d*Sqrt[b*Cos[c + d*x]]) + (10*Sqrt[b*Cos[c + d*x]]*Sin[c + d*x])/(21*b^3*d) + (2*(b*Cos[c + d*x])^(5/2)*Sin[c + d*x])/(7*b^5*d)}
{Cos[c + d*x]^5/(b*Cos[c + d*x])^(5/2), x, 4, (6*Sqrt[b*Cos[c + d*x]]*EllipticE[(1/2)*(c + d*x), 2])/(5*b^3*d*Sqrt[Cos[c + d*x]]) + (2*(b*Cos[c + d*x])^(3/2)*Sin[c + d*x])/(5*b^4*d)}
{Cos[c + d*x]^4/(b*Cos[c + d*x])^(5/2), x, 4, (2*Sqrt[Cos[c + d*x]]*EllipticF[(1/2)*(c + d*x), 2])/(3*b^2*d*Sqrt[b*Cos[c + d*x]]) + (2*Sqrt[b*Cos[c + d*x]]*Sin[c + d*x])/(3*b^3*d)}
{Cos[c + d*x]^3/(b*Cos[c + d*x])^(5/2), x, 3, (2*Sqrt[b*Cos[c + d*x]]*EllipticE[(c + d*x)/2, 2])/(b^3*d*Sqrt[Cos[c + d*x]])}
{Cos[c + d*x]^2/(b*Cos[c + d*x])^(5/2), x, 3, (2*Sqrt[Cos[c + d*x]]*EllipticF[(c + d*x)/2, 2])/(b^2*d*Sqrt[b*Cos[c + d*x]])}
{Cos[c + d*x]^1/(b*Cos[c + d*x])^(5/2), x, 4, -((2*Sqrt[b*Cos[c + d*x]]*EllipticE[(1/2)*(c + d*x), 2])/(b^3*d*Sqrt[Cos[c + d*x]])) + (2*Sin[c + d*x])/(b^2*d*Sqrt[b*Cos[c + d*x]])}
{Cos[c + d*x]^0/(b*Cos[c + d*x])^(5/2), x, 3, (2*Sqrt[Cos[c + d*x]]*EllipticF[(1/2)*(c + d*x), 2])/(3*b^2*d*Sqrt[b*Cos[c + d*x]]) + (2*Sin[c + d*x])/(3*b*d*(b*Cos[c + d*x])^(3/2))}
{Sec[c + d*x]^1/(b*Cos[c + d*x])^(5/2), x, 5, -((6*Sqrt[b*Cos[c + d*x]]*EllipticE[(1/2)*(c + d*x), 2])/(5*b^3*d*Sqrt[Cos[c + d*x]])) + (2*Sin[c + d*x])/(5*d*(b*Cos[c + d*x])^(5/2)) + (6*Sin[c + d*x])/(5*b^2*d*Sqrt[b*Cos[c + d*x]])}
{Sec[c + d*x]^2/(b*Cos[c + d*x])^(5/2), x, 5, (10*Sqrt[Cos[c + d*x]]*EllipticF[(1/2)*(c + d*x), 2])/(21*b^2*d*Sqrt[b*Cos[c + d*x]]) + (2*b*Sin[c + d*x])/(7*d*(b*Cos[c + d*x])^(7/2)) + (10*Sin[c + d*x])/(21*b*d*(b*Cos[c + d*x])^(3/2))}
{Sec[c + d*x]^3/(b*Cos[c + d*x])^(5/2), x, 6, -((14*Sqrt[b*Cos[c + d*x]]*EllipticE[(1/2)*(c + d*x), 2])/(15*b^3*d*Sqrt[Cos[c + d*x]])) + (2*b^2*Sin[c + d*x])/(9*d*(b*Cos[c + d*x])^(9/2)) + (14*Sin[c + d*x])/(45*d*(b*Cos[c + d*x])^(5/2)) + (14*Sin[c + d*x])/(15*b^2*d*Sqrt[b*Cos[c + d*x]])}


{Cos[c + d*x]^0/(b*Cos[c + d*x])^(7/2), x, 4, -((6*Sqrt[b*Cos[c + d*x]]*EllipticE[(1/2)*(c + d*x), 2])/(5*b^4*d*Sqrt[Cos[c + d*x]])) + (2*Sin[c + d*x])/(5*b*d*(b*Cos[c + d*x])^(5/2)) + (6*Sin[c + d*x])/(5*b^3*d*Sqrt[b*Cos[c + d*x]])}


(* ::Subsection::Closed:: *)
(*Integrands of the form Cos[c+d x]^(m/2) (b Cos[c+d x])^(n/2)*)


(* ::Subsubsection::Closed:: *)
(*n>0*)


{Cos[c + d*x]^(7/2)*(b*Cos[c + d*x])^(1/2), x, 3, (3*x*Sqrt[b*Cos[c + d*x]])/(8*Sqrt[Cos[c + d*x]]) + (3*Sqrt[Cos[c + d*x]]*Sqrt[b*Cos[c + d*x]]*Sin[c + d*x])/(8*d) + (Cos[c + d*x]^(5/2)*Sqrt[b*Cos[c + d*x]]*Sin[c + d*x])/(4*d)}
{Cos[c + d*x]^(5/2)*(b*Cos[c + d*x])^(1/2), x, 3, (Sqrt[b*Cos[c + d*x]]*Sin[c + d*x])/(d*Sqrt[Cos[c + d*x]]) - (Sqrt[b*Cos[c + d*x]]*Sin[c + d*x]^3)/(3*d*Sqrt[Cos[c + d*x]])}
{Cos[c + d*x]^(3/2)*(b*Cos[c + d*x])^(1/2), x, 2, (x*Sqrt[b*Cos[c + d*x]])/(2*Sqrt[Cos[c + d*x]]) + (Sqrt[Cos[c + d*x]]*Sqrt[b*Cos[c + d*x]]*Sin[c + d*x])/(2*d)}
{Cos[c + d*x]^(1/2)*(b*Cos[c + d*x])^(1/2), x, 2, (Sqrt[b*Cos[c + d*x]]*Sin[c + d*x])/(d*Sqrt[Cos[c + d*x]])}
{Cos[c + d*x]^(-1/2)*(b*Cos[c + d*x])^(1/2), x, 2, (x*Sqrt[b*Cos[c + d*x]])/Sqrt[Cos[c + d*x]]}
{Cos[c + d*x]^(-3/2)*(b*Cos[c + d*x])^(1/2), x, 2, (ArcTanh[Sin[c + d*x]]*Sqrt[b*Cos[c + d*x]])/(d*Sqrt[Cos[c + d*x]])}
{Cos[c + d*x]^(-5/2)*(b*Cos[c + d*x])^(1/2), x, 2, (Sqrt[b*Cos[c + d*x]]*Sin[c + d*x])/(d*Cos[c + d*x]^(3/2))}
{Cos[c + d*x]^(-7/2)*(b*Cos[c + d*x])^(1/2), x, 3, (ArcTanh[Sin[c + d*x]]*Sqrt[b*Cos[c + d*x]])/(2*d*Sqrt[Cos[c + d*x]]) + (Sqrt[b*Cos[c + d*x]]*Sin[c + d*x])/(2*d*Cos[c + d*x]^(5/2))}
{Cos[c + d*x]^(-9/2)*(b*Cos[c + d*x])^(1/2), x, 3, (Sqrt[b*Cos[c + d*x]]*Sin[c + d*x])/(d*Cos[c + d*x]^(3/2)) + (Sqrt[b*Cos[c + d*x]]*Sin[c + d*x]^3)/(3*d*Cos[c + d*x]^(7/2))}
{Cos[c + d*x]^(-11/2)*(b*Cos[c + d*x])^(1/2), x, 4, (3*ArcTanh[Sin[c + d*x]]*Sqrt[b*Cos[c + d*x]])/(8*d*Sqrt[Cos[c + d*x]]) + (Sqrt[b*Cos[c + d*x]]*Sin[c + d*x])/(4*d*Cos[c + d*x]^(9/2)) + (3*Sqrt[b*Cos[c + d*x]]*Sin[c + d*x])/(8*d*Cos[c + d*x]^(5/2))}


{Cos[c + d*x]^(5/2)*(b*Cos[c + d*x])^(3/2), x, 3, (3*b*x*Sqrt[b*Cos[c + d*x]])/(8*Sqrt[Cos[c + d*x]]) + (3*b*Sqrt[Cos[c + d*x]]*Sqrt[b*Cos[c + d*x]]*Sin[c + d*x])/(8*d) + (b*Cos[c + d*x]^(5/2)*Sqrt[b*Cos[c + d*x]]*Sin[c + d*x])/(4*d)}
{Cos[c + d*x]^(3/2)*(b*Cos[c + d*x])^(3/2), x, 3, (b*Sqrt[b*Cos[c + d*x]]*Sin[c + d*x])/(d*Sqrt[Cos[c + d*x]]) - (b*Sqrt[b*Cos[c + d*x]]*Sin[c + d*x]^3)/(3*d*Sqrt[Cos[c + d*x]])}
{Cos[c + d*x]^(1/2)*(b*Cos[c + d*x])^(3/2), x, 2, (b*x*Sqrt[b*Cos[c + d*x]])/(2*Sqrt[Cos[c + d*x]]) + (b*Sqrt[Cos[c + d*x]]*Sqrt[b*Cos[c + d*x]]*Sin[c + d*x])/(2*d)}
{Cos[c + d*x]^(-1/2)*(b*Cos[c + d*x])^(3/2), x, 2, (b*Sqrt[b*Cos[c + d*x]]*Sin[c + d*x])/(d*Sqrt[Cos[c + d*x]])}
{Cos[c + d*x]^(-3/2)*(b*Cos[c + d*x])^(3/2), x, 2, (b*x*Sqrt[b*Cos[c + d*x]])/Sqrt[Cos[c + d*x]]}
{Cos[c + d*x]^(-5/2)*(b*Cos[c + d*x])^(3/2), x, 2, (b*ArcTanh[Sin[c + d*x]]*Sqrt[b*Cos[c + d*x]])/(d*Sqrt[Cos[c + d*x]])}
{Cos[c + d*x]^(-7/2)*(b*Cos[c + d*x])^(3/2), x, 2, (b*Sqrt[b*Cos[c + d*x]]*Sin[c + d*x])/(d*Cos[c + d*x]^(3/2))}
{Cos[c + d*x]^(-9/2)*(b*Cos[c + d*x])^(3/2), x, 3, (b*ArcTanh[Sin[c + d*x]]*Sqrt[b*Cos[c + d*x]])/(2*d*Sqrt[Cos[c + d*x]]) + (b*Sqrt[b*Cos[c + d*x]]*Sin[c + d*x])/(2*d*Cos[c + d*x]^(5/2))}
{Cos[c + d*x]^(-11/2)*(b*Cos[c + d*x])^(3/2), x, 3, (b*Sqrt[b*Cos[c + d*x]]*Sin[c + d*x])/(d*Cos[c + d*x]^(3/2)) + (b*Sqrt[b*Cos[c + d*x]]*Sin[c + d*x]^3)/(3*d*Cos[c + d*x]^(7/2))}
{Cos[c + d*x]^(-13/2)*(b*Cos[c + d*x])^(3/2), x, 4, (3*b*ArcTanh[Sin[c + d*x]]*Sqrt[b*Cos[c + d*x]])/(8*d*Sqrt[Cos[c + d*x]]) + (b*Sqrt[b*Cos[c + d*x]]*Sin[c + d*x])/(4*d*Cos[c + d*x]^(9/2)) + (3*b*Sqrt[b*Cos[c + d*x]]*Sin[c + d*x])/(8*d*Cos[c + d*x]^(5/2))}


{Cos[c + d*x]^(5/2)*(b*Cos[c + d*x])^(5/2), x, 3, (b^2*Sqrt[b*Cos[c + d*x]]*Sin[c + d*x])/(d*Sqrt[Cos[c + d*x]]) - (2*b^2*Sqrt[b*Cos[c + d*x]]*Sin[c + d*x]^3)/(3*d*Sqrt[Cos[c + d*x]]) + (b^2*Sqrt[b*Cos[c + d*x]]*Sin[c + d*x]^5)/(5*d*Sqrt[Cos[c + d*x]])}
{Cos[c + d*x]^(3/2)*(b*Cos[c + d*x])^(5/2), x, 3, (3*b^2*x*Sqrt[b*Cos[c + d*x]])/(8*Sqrt[Cos[c + d*x]]) + (3*b^2*Sqrt[Cos[c + d*x]]*Sqrt[b*Cos[c + d*x]]*Sin[c + d*x])/(8*d) + (b^2*Cos[c + d*x]^(5/2)*Sqrt[b*Cos[c + d*x]]*Sin[c + d*x])/(4*d)}
{Cos[c + d*x]^(1/2)*(b*Cos[c + d*x])^(5/2), x, 3, (b^2*Sqrt[b*Cos[c + d*x]]*Sin[c + d*x])/(d*Sqrt[Cos[c + d*x]]) - (b^2*Sqrt[b*Cos[c + d*x]]*Sin[c + d*x]^3)/(3*d*Sqrt[Cos[c + d*x]])}
{Cos[c + d*x]^(-1/2)*(b*Cos[c + d*x])^(5/2), x, 2, (b^2*x*Sqrt[b*Cos[c + d*x]])/(2*Sqrt[Cos[c + d*x]]) + (b^2*Sqrt[Cos[c + d*x]]*Sqrt[b*Cos[c + d*x]]*Sin[c + d*x])/(2*d)}
{Cos[c + d*x]^(-3/2)*(b*Cos[c + d*x])^(5/2), x, 2, (b^2*Sqrt[b*Cos[c + d*x]]*Sin[c + d*x])/(d*Sqrt[Cos[c + d*x]])}
{Cos[c + d*x]^(-5/2)*(b*Cos[c + d*x])^(5/2), x, 2, (b^2*x*Sqrt[b*Cos[c + d*x]])/Sqrt[Cos[c + d*x]]}
{Cos[c + d*x]^(-7/2)*(b*Cos[c + d*x])^(5/2), x, 2, (b^2*ArcTanh[Sin[c + d*x]]*Sqrt[b*Cos[c + d*x]])/(d*Sqrt[Cos[c + d*x]])}
{Cos[c + d*x]^(-9/2)*(b*Cos[c + d*x])^(5/2), x, 2, (b^2*Sqrt[b*Cos[c + d*x]]*Sin[c + d*x])/(d*Cos[c + d*x]^(3/2))}
{Cos[c + d*x]^(-11/2)*(b*Cos[c + d*x])^(5/2), x, 3, (b^2*ArcTanh[Sin[c + d*x]]*Sqrt[b*Cos[c + d*x]])/(2*d*Sqrt[Cos[c + d*x]]) + (b^2*Sqrt[b*Cos[c + d*x]]*Sin[c + d*x])/(2*d*Cos[c + d*x]^(5/2))}
{Cos[c + d*x]^(-13/2)*(b*Cos[c + d*x])^(5/2), x, 3, (b^2*Sqrt[b*Cos[c + d*x]]*Sin[c + d*x])/(d*Cos[c + d*x]^(3/2)) + (b^2*Sqrt[b*Cos[c + d*x]]*Sin[c + d*x]^3)/(3*d*Cos[c + d*x]^(7/2))}
{Cos[c + d*x]^(-15/2)*(b*Cos[c + d*x])^(5/2), x, 4, (3*b^2*ArcTanh[Sin[c + d*x]]*Sqrt[b*Cos[c + d*x]])/(8*d*Sqrt[Cos[c + d*x]]) + (b^2*Sqrt[b*Cos[c + d*x]]*Sin[c + d*x])/(4*d*Cos[c + d*x]^(9/2)) + (3*b^2*Sqrt[b*Cos[c + d*x]]*Sin[c + d*x])/(8*d*Cos[c + d*x]^(5/2))}


(* ::Subsubsection::Closed:: *)
(*n<0*)


{Cos[c + d*x]^(11/2)/(b*Cos[c + d*x])^(1/2), x, 3, (Sqrt[Cos[c + d*x]]*Sin[c + d*x])/(d*Sqrt[b*Cos[c + d*x]]) - (2*Sqrt[Cos[c + d*x]]*Sin[c + d*x]^3)/(3*d*Sqrt[b*Cos[c + d*x]]) + (Sqrt[Cos[c + d*x]]*Sin[c + d*x]^5)/(5*d*Sqrt[b*Cos[c + d*x]])}
{Cos[c + d*x]^(9/2)/(b*Cos[c + d*x])^(1/2), x, 3, (3*x*Sqrt[Cos[c + d*x]])/(8*Sqrt[b*Cos[c + d*x]]) + (3*Cos[c + d*x]^(3/2)*Sin[c + d*x])/(8*d*Sqrt[b*Cos[c + d*x]]) + (Cos[c + d*x]^(7/2)*Sin[c + d*x])/(4*d*Sqrt[b*Cos[c + d*x]])}
{Cos[c + d*x]^(7/2)/(b*Cos[c + d*x])^(1/2), x, 3, (Sqrt[Cos[c + d*x]]*Sin[c + d*x])/(d*Sqrt[b*Cos[c + d*x]]) - (Sqrt[Cos[c + d*x]]*Sin[c + d*x]^3)/(3*d*Sqrt[b*Cos[c + d*x]])}
{Cos[c + d*x]^(5/2)/(b*Cos[c + d*x])^(1/2), x, 2, (x*Sqrt[Cos[c + d*x]])/(2*Sqrt[b*Cos[c + d*x]]) + (Cos[c + d*x]^(3/2)*Sin[c + d*x])/(2*d*Sqrt[b*Cos[c + d*x]])}
{Cos[c + d*x]^(3/2)/(b*Cos[c + d*x])^(1/2), x, 2, (Sqrt[Cos[c + d*x]]*Sin[c + d*x])/(d*Sqrt[b*Cos[c + d*x]])}
{Cos[c + d*x]^(1/2)/(b*Cos[c + d*x])^(1/2), x, 2, (x*Sqrt[Cos[c + d*x]])/Sqrt[b*Cos[c + d*x]]}
{Cos[c + d*x]^(-1/2)/(b*Cos[c + d*x])^(1/2), x, 2, (ArcTanh[Sin[c + d*x]]*Sqrt[Cos[c + d*x]])/(d*Sqrt[b*Cos[c + d*x]])}
{Cos[c + d*x]^(-3/2)/(b*Cos[c + d*x])^(1/2), x, 2, Sin[c + d*x]/(d*Sqrt[Cos[c + d*x]]*Sqrt[b*Cos[c + d*x]])}
{Cos[c + d*x]^(-5/2)/(b*Cos[c + d*x])^(1/2), x, 3, (ArcTanh[Sin[c + d*x]]*Sqrt[Cos[c + d*x]])/(2*d*Sqrt[b*Cos[c + d*x]]) + Sin[c + d*x]/(2*d*Cos[c + d*x]^(3/2)*Sqrt[b*Cos[c + d*x]])}
{Cos[c + d*x]^(-7/2)/(b*Cos[c + d*x])^(1/2), x, 3, Sin[c + d*x]/(d*Sqrt[Cos[c + d*x]]*Sqrt[b*Cos[c + d*x]]) + Sin[c + d*x]^3/(3*d*Cos[c + d*x]^(5/2)*Sqrt[b*Cos[c + d*x]])}
{Cos[c + d*x]^(-9/2)/(b*Cos[c + d*x])^(1/2), x, 4, (3*ArcTanh[Sin[c + d*x]]*Sqrt[Cos[c + d*x]])/(8*d*Sqrt[b*Cos[c + d*x]]) + Sin[c + d*x]/(4*d*Cos[c + d*x]^(7/2)*Sqrt[b*Cos[c + d*x]]) + (3*Sin[c + d*x])/(8*d*Cos[c + d*x]^(3/2)*Sqrt[b*Cos[c + d*x]])}


{Cos[c + d*x]^(11/2)/(b*Cos[c + d*x])^(3/2), x, 3, (3*x*Sqrt[Cos[c + d*x]])/(8*b*Sqrt[b*Cos[c + d*x]]) + (3*Cos[c + d*x]^(3/2)*Sin[c + d*x])/(8*b*d*Sqrt[b*Cos[c + d*x]]) + (Cos[c + d*x]^(7/2)*Sin[c + d*x])/(4*b*d*Sqrt[b*Cos[c + d*x]])}
{Cos[c + d*x]^(9/2)/(b*Cos[c + d*x])^(3/2), x, 3, (Sqrt[Cos[c + d*x]]*Sin[c + d*x])/(b*d*Sqrt[b*Cos[c + d*x]]) - (Sqrt[Cos[c + d*x]]*Sin[c + d*x]^3)/(3*b*d*Sqrt[b*Cos[c + d*x]])}
{Cos[c + d*x]^(7/2)/(b*Cos[c + d*x])^(3/2), x, 2, (x*Sqrt[Cos[c + d*x]])/(2*b*Sqrt[b*Cos[c + d*x]]) + (Cos[c + d*x]^(3/2)*Sin[c + d*x])/(2*b*d*Sqrt[b*Cos[c + d*x]])}
{Cos[c + d*x]^(5/2)/(b*Cos[c + d*x])^(3/2), x, 2, (Sqrt[Cos[c + d*x]]*Sin[c + d*x])/(b*d*Sqrt[b*Cos[c + d*x]])}
{Cos[c + d*x]^(3/2)/(b*Cos[c + d*x])^(3/2), x, 2, (x*Sqrt[Cos[c + d*x]])/(b*Sqrt[b*Cos[c + d*x]])}
{Cos[c + d*x]^(1/2)/(b*Cos[c + d*x])^(3/2), x, 2, (ArcTanh[Sin[c + d*x]]*Sqrt[Cos[c + d*x]])/(b*d*Sqrt[b*Cos[c + d*x]])}
{Cos[c + d*x]^(-1/2)/(b*Cos[c + d*x])^(3/2), x, 2, Sin[c + d*x]/(b*d*Sqrt[Cos[c + d*x]]*Sqrt[b*Cos[c + d*x]])}
{Cos[c + d*x]^(-3/2)/(b*Cos[c + d*x])^(3/2), x, 3, (ArcTanh[Sin[c + d*x]]*Sqrt[Cos[c + d*x]])/(2*b*d*Sqrt[b*Cos[c + d*x]]) + Sin[c + d*x]/(2*b*d*Cos[c + d*x]^(3/2)*Sqrt[b*Cos[c + d*x]])}
{Cos[c + d*x]^(-5/2)/(b*Cos[c + d*x])^(3/2), x, 3, Sin[c + d*x]/(b*d*Sqrt[Cos[c + d*x]]*Sqrt[b*Cos[c + d*x]]) + Sin[c + d*x]^3/(3*b*d*Cos[c + d*x]^(5/2)*Sqrt[b*Cos[c + d*x]])}
{Cos[c + d*x]^(-7/2)/(b*Cos[c + d*x])^(3/2), x, 4, (3*ArcTanh[Sin[c + d*x]]*Sqrt[Cos[c + d*x]])/(8*b*d*Sqrt[b*Cos[c + d*x]]) + Sin[c + d*x]/(4*b*d*Cos[c + d*x]^(7/2)*Sqrt[b*Cos[c + d*x]]) + (3*Sin[c + d*x])/(8*b*d*Cos[c + d*x]^(3/2)*Sqrt[b*Cos[c + d*x]])}


{Cos[c + d*x]^(13/2)/(b*Cos[c + d*x])^(5/2), x, 3, (3*x*Sqrt[Cos[c + d*x]])/(8*b^2*Sqrt[b*Cos[c + d*x]]) + (3*Cos[c + d*x]^(3/2)*Sin[c + d*x])/(8*b^2*d*Sqrt[b*Cos[c + d*x]]) + (Cos[c + d*x]^(7/2)*Sin[c + d*x])/(4*b^2*d*Sqrt[b*Cos[c + d*x]])}
{Cos[c + d*x]^(11/2)/(b*Cos[c + d*x])^(5/2), x, 3, (Sqrt[Cos[c + d*x]]*Sin[c + d*x])/(b^2*d*Sqrt[b*Cos[c + d*x]]) - (Sqrt[Cos[c + d*x]]*Sin[c + d*x]^3)/(3*b^2*d*Sqrt[b*Cos[c + d*x]])}
{Cos[c + d*x]^(9/2)/(b*Cos[c + d*x])^(5/2), x, 2, (x*Sqrt[Cos[c + d*x]])/(2*b^2*Sqrt[b*Cos[c + d*x]]) + (Cos[c + d*x]^(3/2)*Sin[c + d*x])/(2*b^2*d*Sqrt[b*Cos[c + d*x]])}
{Cos[c + d*x]^(7/2)/(b*Cos[c + d*x])^(5/2), x, 2, (Sqrt[Cos[c + d*x]]*Sin[c + d*x])/(b^2*d*Sqrt[b*Cos[c + d*x]])}
{Cos[c + d*x]^(5/2)/(b*Cos[c + d*x])^(5/2), x, 2, (x*Sqrt[Cos[c + d*x]])/(b^2*Sqrt[b*Cos[c + d*x]])}
{Cos[c + d*x]^(3/2)/(b*Cos[c + d*x])^(5/2), x, 2, (ArcTanh[Sin[c + d*x]]*Sqrt[Cos[c + d*x]])/(b^2*d*Sqrt[b*Cos[c + d*x]])}
{Cos[c + d*x]^(1/2)/(b*Cos[c + d*x])^(5/2), x, 2, Sin[c + d*x]/(b^2*d*Sqrt[Cos[c + d*x]]*Sqrt[b*Cos[c + d*x]])}
{Cos[c + d*x]^(-1/2)/(b*Cos[c + d*x])^(5/2), x, 3, (ArcTanh[Sin[c + d*x]]*Sqrt[Cos[c + d*x]])/(2*b^2*d*Sqrt[b*Cos[c + d*x]]) + Sin[c + d*x]/(2*b^2*d*Cos[c + d*x]^(3/2)*Sqrt[b*Cos[c + d*x]])}
{Cos[c + d*x]^(-3/2)/(b*Cos[c + d*x])^(5/2), x, 3, Sin[c + d*x]/(b^2*d*Sqrt[Cos[c + d*x]]*Sqrt[b*Cos[c + d*x]]) + Sin[c + d*x]^3/(3*b^2*d*Cos[c + d*x]^(5/2)*Sqrt[b*Cos[c + d*x]])}
{Cos[c + d*x]^(-5/2)/(b*Cos[c + d*x])^(5/2), x, 4, (3*ArcTanh[Sin[c + d*x]]*Sqrt[Cos[c + d*x]])/(8*b^2*d*Sqrt[b*Cos[c + d*x]]) + Sin[c + d*x]/(4*b^2*d*Cos[c + d*x]^(7/2)*Sqrt[b*Cos[c + d*x]]) + (3*Sin[c + d*x])/(8*b^2*d*Cos[c + d*x]^(3/2)*Sqrt[b*Cos[c + d*x]])}


(* ::Subsection::Closed:: *)
(*Integrands of the form Cos[c+d x]^m (b Cos[c+d x])^(n/3)*)


(* ::Subsubsection::Closed:: *)
(*n>0*)


{Cos[c + d*x]^m*(b*Cos[c + d*x])^(1/3), x, 2, (Cos[c + d*x]^(1 + m)*(b*Cos[c + d*x])^(1/3)*(Cos[c + d*x]^2)^((-4 - 3*m)/6)*Hypergeometric2F1[1/2, (2 - 3*m)/6, 3/2, Sin[c + d*x]^2]*Sin[c + d*x])/d}

{Cos[c + d*x]^2*(b*Cos[c + d*x])^(1/3), x, 4, (3*(b*Cos[c + d*x])^(4/3)*Sin[c + d*x])/(7*b*d) + (4*b*(Cos[c + d*x]^2)^(1/3)*Hypergeometric2F1[1/3, 1/2, 3/2, Sin[c + d*x]^2]*Sin[c + d*x])/(7*d*(b*Cos[c + d*x])^(2/3))}
{Cos[c + d*x]*(b*Cos[c + d*x])^(1/3), x, 4, (3*(b*Cos[c + d*x])^(1/3)*Sin[c + d*x])/(4*d) + ((b*Cos[c + d*x])^(1/3)*Hypergeometric2F1[1/2, 5/6, 3/2, Sin[c + d*x]^2]*Sin[c + d*x])/(4*d*(Cos[c + d*x]^2)^(1/6))}
{(b*Cos[c + d*x])^(1/3), x, 2, (b*(Cos[c + d*x]^2)^(1/3)*Hypergeometric2F1[1/3, 1/2, 3/2, Sin[c + d*x]^2]*Sin[c + d*x])/(d*(b*Cos[c + d*x])^(2/3))}
{(b*Cos[c + d*x])^(1/3)*Sec[c + d*x], x, 3, ((b*Cos[c + d*x])^(1/3)*Hypergeometric2F1[1/2, 5/6, 3/2, Sin[c + d*x]^2]*Sin[c + d*x])/(d*(Cos[c + d*x]^2)^(1/6))}
{(b*Cos[c + d*x])^(1/3)*Sec[c + d*x]^2, x, 4, (3*b*Sin[c + d*x])/(2*d*(b*Cos[c + d*x])^(2/3)) - (b*(Cos[c + d*x]^2)^(1/3)*Hypergeometric2F1[1/3, 1/2, 3/2, Sin[c + d*x]^2]*Sin[c + d*x])/(2*d*(b*Cos[c + d*x])^(2/3))}
{(b*Cos[c + d*x])^(1/3)*Sec[c + d*x]^3, x, 4, (3*b^2*Sin[c + d*x])/(5*d*(b*Cos[c + d*x])^(5/3)) + (2*(b*Cos[c + d*x])^(1/3)*Hypergeometric2F1[1/2, 5/6, 3/2, Sin[c + d*x]^2]*Sin[c + d*x])/(5*d*(Cos[c + d*x]^2)^(1/6))}


{Cos[c + d*x]^m*(b*Cos[c + d*x])^(2/3), x, 2, (Cos[c + d*x]^(1 + m)*(b*Cos[c + d*x])^(2/3)*(Cos[c + d*x]^2)^((-5 - 3*m)/6)*Hypergeometric2F1[1/2, (1 - 3*m)/6, 3/2, Sin[c + d*x]^2]*Sin[c + d*x])/d}

{Cos[c + d*x]^2*(b*Cos[c + d*x])^(2/3), x, 4, (3*(b*Cos[c + d*x])^(5/3)*Sin[c + d*x])/(8*b*d) + (5*b*(Cos[c + d*x]^2)^(1/6)*Hypergeometric2F1[1/6, 1/2, 3/2, Sin[c + d*x]^2]*Sin[c + d*x])/(8*d*(b*Cos[c + d*x])^(1/3))}
{Cos[c + d*x]*(b*Cos[c + d*x])^(2/3), x, 4, (3*(b*Cos[c + d*x])^(2/3)*Sin[c + d*x])/(5*d) + (2*(b*Cos[c + d*x])^(2/3)*Hypergeometric2F1[1/2, 2/3, 3/2, Sin[c + d*x]^2]*Sin[c + d*x])/(5*d*(Cos[c + d*x]^2)^(1/3))}
{(b*Cos[c + d*x])^(2/3), x, 2, (b*(Cos[c + d*x]^2)^(1/6)*Hypergeometric2F1[1/6, 1/2, 3/2, Sin[c + d*x]^2]*Sin[c + d*x])/(d*(b*Cos[c + d*x])^(1/3))}
{(b*Cos[c + d*x])^(2/3)*Sec[c + d*x], x, 3, ((b*Cos[c + d*x])^(2/3)*Hypergeometric2F1[1/2, 2/3, 3/2, Sin[c + d*x]^2]*Sin[c + d*x])/(d*(Cos[c + d*x]^2)^(1/3))}
{(b*Cos[c + d*x])^(2/3)*Sec[c + d*x]^2, x, 4, (3*b*Sin[c + d*x])/(d*(b*Cos[c + d*x])^(1/3)) - (2*b*(Cos[c + d*x]^2)^(1/6)*Hypergeometric2F1[1/6, 1/2, 3/2, Sin[c + d*x]^2]*Sin[c + d*x])/(d*(b*Cos[c + d*x])^(1/3))}
{(b*Cos[c + d*x])^(2/3)*Sec[c + d*x]^3, x, 4, (3*b^2*Sin[c + d*x])/(4*d*(b*Cos[c + d*x])^(4/3)) + ((b*Cos[c + d*x])^(2/3)*Hypergeometric2F1[1/2, 2/3, 3/2, Sin[c + d*x]^2]*Sin[c + d*x])/(4*d*(Cos[c + d*x]^2)^(1/3))}


{Cos[c + d*x]^m*(b*Cos[c + d*x])^(4/3), x, 2, (Cos[c + d*x]^(1 + m)*(b*Cos[c + d*x])^(4/3)*(Cos[c + d*x]^2)^((-7 - 3*m)/6)*Hypergeometric2F1[1/2, (-1 - 3*m)/6, 3/2, Sin[c + d*x]^2]*Sin[c + d*x])/d}

{Cos[c + d*x]^2*(b*Cos[c + d*x])^(4/3), x, 5, (21*b*(b*Cos[c + d*x])^(1/3)*Sin[c + d*x])/(40*d) + (3*(b*Cos[c + d*x])^(7/3)*Sin[c + d*x])/(10*b*d) + (7*b*(b*Cos[c + d*x])^(1/3)*Hypergeometric2F1[1/2, 5/6, 3/2, Sin[c + d*x]^2]*Sin[c + d*x])/(40*d*(Cos[c + d*x]^2)^(1/6))}
{Cos[c + d*x]*(b*Cos[c + d*x])^(4/3), x, 4, (3*(b*Cos[c + d*x])^(4/3)*Sin[c + d*x])/(7*d) + (4*b^2*(Cos[c + d*x]^2)^(1/3)*Hypergeometric2F1[1/3, 1/2, 3/2, Sin[c + d*x]^2]*Sin[c + d*x])/(7*d*(b*Cos[c + d*x])^(2/3))}
{(b*Cos[c + d*x])^(4/3), x, 3, (3*b*(b*Cos[c + d*x])^(1/3)*Sin[c + d*x])/(4*d) + (b*(b*Cos[c + d*x])^(1/3)*Hypergeometric2F1[1/2, 5/6, 3/2, Sin[c + d*x]^2]*Sin[c + d*x])/(4*d*(Cos[c + d*x]^2)^(1/6))}
{(b*Cos[c + d*x])^(4/3)*Sec[c + d*x], x, 3, (b^2*(Cos[c + d*x]^2)^(1/3)*Hypergeometric2F1[1/3, 1/2, 3/2, Sin[c + d*x]^2]*Sin[c + d*x])/(d*(b*Cos[c + d*x])^(2/3))}
{(b*Cos[c + d*x])^(4/3)*Sec[c + d*x]^2, x, 3, (b*(b*Cos[c + d*x])^(1/3)*Hypergeometric2F1[1/2, 5/6, 3/2, Sin[c + d*x]^2]*Sin[c + d*x])/(d*(Cos[c + d*x]^2)^(1/6))}
{(b*Cos[c + d*x])^(4/3)*Sec[c + d*x]^3, x, 4, (3*b^2*Sin[c + d*x])/(2*d*(b*Cos[c + d*x])^(2/3)) - (b^2*(Cos[c + d*x]^2)^(1/3)*Hypergeometric2F1[1/3, 1/2, 3/2, Sin[c + d*x]^2]*Sin[c + d*x])/(2*d*(b*Cos[c + d*x])^(2/3))}


(* ::Subsubsection::Closed:: *)
(*n<0*)


{Cos[c + d*x]^m/(b*Cos[c + d*x])^(1/3), x, 2, (Cos[c + d*x]^(1 + m)*(Cos[c + d*x]^2)^((-2 - 3*m)/6)*Hypergeometric2F1[1/2, (4 - 3*m)/6, 3/2, Sin[c + d*x]^2]*Sin[c + d*x])/(d*(b*Cos[c + d*x])^(1/3))}

{Cos[c + d*x]^2/(b*Cos[c + d*x])^(1/3), x, 4, (3*(b*Cos[c + d*x])^(2/3)*Sin[c + d*x])/(5*b*d) + (2*(b*Cos[c + d*x])^(2/3)*Hypergeometric2F1[1/2, 2/3, 3/2, Sin[c + d*x]^2]*Sin[c + d*x])/(5*b*d*(Cos[c + d*x]^2)^(1/3))}
{Cos[c + d*x]/(b*Cos[c + d*x])^(1/3), x, 3, ((Cos[c + d*x]^2)^(1/6)*Hypergeometric2F1[1/6, 1/2, 3/2, Sin[c + d*x]^2]*Sin[c + d*x])/(d*(b*Cos[c + d*x])^(1/3))}
{(b*Cos[c + d*x])^(-1/3), x, 2, ((b*Cos[c + d*x])^(2/3)*Hypergeometric2F1[1/2, 2/3, 3/2, Sin[c + d*x]^2]*Sin[c + d*x])/(b*d*(Cos[c + d*x]^2)^(1/3))}
{Sec[c + d*x]/(b*Cos[c + d*x])^(1/3), x, 4, (3*Sin[c + d*x])/(d*(b*Cos[c + d*x])^(1/3)) - (2*(Cos[c + d*x]^2)^(1/6)*Hypergeometric2F1[1/6, 1/2, 3/2, Sin[c + d*x]^2]*Sin[c + d*x])/(d*(b*Cos[c + d*x])^(1/3))}
{Sec[c + d*x]^2/(b*Cos[c + d*x])^(1/3), x, 4, (3*b*Sin[c + d*x])/(4*d*(b*Cos[c + d*x])^(4/3)) + ((b*Cos[c + d*x])^(2/3)*Hypergeometric2F1[1/2, 2/3, 3/2, Sin[c + d*x]^2]*Sin[c + d*x])/(4*b*d*(Cos[c + d*x]^2)^(1/3))}
{Sec[c + d*x]^3/(b*Cos[c + d*x])^(1/3), x, 5, (3*b^2*Sin[c + d*x])/(7*d*(b*Cos[c + d*x])^(7/3)) + (12*Sin[c + d*x])/(7*d*(b*Cos[c + d*x])^(1/3)) - (8*(Cos[c + d*x]^2)^(1/6)*Hypergeometric2F1[1/6, 1/2, 3/2, Sin[c + d*x]^2]*Sin[c + d*x])/(7*d*(b*Cos[c + d*x])^(1/3))}


{Cos[c + d*x]^m/(b*Cos[c + d*x])^(2/3), x, 2, (Cos[c + d*x]^(1 + m)*(Cos[c + d*x]^2)^((-1 - 3*m)/6)*Hypergeometric2F1[1/2, (5 - 3*m)/6, 3/2, Sin[c + d*x]^2]*Sin[c + d*x])/(d*(b*Cos[c + d*x])^(2/3))}

{Cos[c + d*x]^2/(b*Cos[c + d*x])^(2/3), x, 4, (3*(b*Cos[c + d*x])^(1/3)*Sin[c + d*x])/(4*b*d) + ((b*Cos[c + d*x])^(1/3)*Hypergeometric2F1[1/2, 5/6, 3/2, Sin[c + d*x]^2]*Sin[c + d*x])/(4*b*d*(Cos[c + d*x]^2)^(1/6))}
{Cos[c + d*x]/(b*Cos[c + d*x])^(2/3), x, 3, ((Cos[c + d*x]^2)^(1/3)*Hypergeometric2F1[1/3, 1/2, 3/2, Sin[c + d*x]^2]*Sin[c + d*x])/(d*(b*Cos[c + d*x])^(2/3))}
{(b*Cos[c + d*x])^(-2/3), x, 2, ((b*Cos[c + d*x])^(1/3)*Hypergeometric2F1[1/2, 5/6, 3/2, Sin[c + d*x]^2]*Sin[c + d*x])/(b*d*(Cos[c + d*x]^2)^(1/6))}
{Sec[c + d*x]/(b*Cos[c + d*x])^(2/3), x, 4, (3*Sin[c + d*x])/(2*d*(b*Cos[c + d*x])^(2/3)) - ((Cos[c + d*x]^2)^(1/3)*Hypergeometric2F1[1/3, 1/2, 3/2, Sin[c + d*x]^2]*Sin[c + d*x])/(2*d*(b*Cos[c + d*x])^(2/3))}
{Sec[c + d*x]^2/(b*Cos[c + d*x])^(2/3), x, 4, (3*b*Sin[c + d*x])/(5*d*(b*Cos[c + d*x])^(5/3)) + (2*(b*Cos[c + d*x])^(1/3)*Hypergeometric2F1[1/2, 5/6, 3/2, Sin[c + d*x]^2]*Sin[c + d*x])/(5*b*d*(Cos[c + d*x]^2)^(1/6))}
{Sec[c + d*x]^3/(b*Cos[c + d*x])^(2/3), x, 5, (3*b^2*Sin[c + d*x])/(8*d*(b*Cos[c + d*x])^(8/3)) + (15*Sin[c + d*x])/(16*d*(b*Cos[c + d*x])^(2/3)) - (5*(Cos[c + d*x]^2)^(1/3)*Hypergeometric2F1[1/3, 1/2, 3/2, Sin[c + d*x]^2]*Sin[c + d*x])/(16*d*(b*Cos[c + d*x])^(2/3))}


{Cos[c + d*x]^m/(b*Cos[c + d*x])^(4/3), x, 2, (Cos[c + d*x]^(1 + m)*(Cos[c + d*x]^2)^((1 - 3*m)/6)*Hypergeometric2F1[1/2, (7 - 3*m)/6, 3/2, Sin[c + d*x]^2]*Sin[c + d*x])/(d*(b*Cos[c + d*x])^(4/3))}

{Cos[c + d*x]^2/(b*Cos[c + d*x])^(4/3), x, 3, ((Cos[c + d*x]^2)^(1/6)*Hypergeometric2F1[1/6, 1/2, 3/2, Sin[c + d*x]^2]*Sin[c + d*x])/(b*d*(b*Cos[c + d*x])^(1/3))}
{Cos[c + d*x]/(b*Cos[c + d*x])^(4/3), x, 3, ((b*Cos[c + d*x])^(2/3)*Hypergeometric2F1[1/2, 2/3, 3/2, Sin[c + d*x]^2]*Sin[c + d*x])/(b^2*d*(Cos[c + d*x]^2)^(1/3))}
{(b*Cos[c + d*x])^(-4/3), x, 3, (3*Sin[c + d*x])/(b*d*(b*Cos[c + d*x])^(1/3)) - (2*(Cos[c + d*x]^2)^(1/6)*Hypergeometric2F1[1/6, 1/2, 3/2, Sin[c + d*x]^2]*Sin[c + d*x])/(b*d*(b*Cos[c + d*x])^(1/3))}
{Sec[c + d*x]/(b*Cos[c + d*x])^(4/3), x, 4, (3*Sin[c + d*x])/(4*d*(b*Cos[c + d*x])^(4/3)) + ((b*Cos[c + d*x])^(2/3)*Hypergeometric2F1[1/2, 2/3, 3/2, Sin[c + d*x]^2]*Sin[c + d*x])/(4*b^2*d*(Cos[c + d*x]^2)^(1/3))}
{Sec[c + d*x]^2/(b*Cos[c + d*x])^(4/3), x, 5, (3*b*Sin[c + d*x])/(7*d*(b*Cos[c + d*x])^(7/3)) + (12*Sin[c + d*x])/(7*b*d*(b*Cos[c + d*x])^(1/3)) - (8*(Cos[c + d*x]^2)^(1/6)*Hypergeometric2F1[1/6, 1/2, 3/2, Sin[c + d*x]^2]*Sin[c + d*x])/(7*b*d*(b*Cos[c + d*x])^(1/3))}
{Sec[c + d*x]^3/(b*Cos[c + d*x])^(4/3), x, 5, (3*b^2*Sin[c + d*x])/(10*d*(b*Cos[c + d*x])^(10/3)) + (21*Sin[c + d*x])/(40*d*(b*Cos[c + d*x])^(4/3)) + (7*(b*Cos[c + d*x])^(2/3)*Hypergeometric2F1[1/2, 2/3, 3/2, Sin[c + d*x]^2]*Sin[c + d*x])/(40*b^2*d*(Cos[c + d*x]^2)^(1/3))}


(* ::Subsection::Closed:: *)
(*Integrands of the form Cos[c+d x]^m (b Cos[c+d x])^n when n symbolic*)


{Cos[c + d*x]^m*(b*Cos[c + d*x])^n, x, 2, (Cos[c + d*x]^(1 + m)*(b*Cos[c + d*x])^n*(Cos[c + d*x]^2)^((1/2)*(-1 - m - n))*Hypergeometric2F1[1/2, (1/2)*(1 - m - n), 3/2, Sin[c + d*x]^2]*Sin[c + d*x])/d}


{Cos[c + d*x]^2*(b*Cos[c + d*x])^n, x, 3, ((b*Cos[c + d*x])^(3 + n)*(Cos[c + d*x]^2)^((1/2)*(-3 - n))*Hypergeometric2F1[1/2, (1/2)*(-1 - n), 3/2, Sin[c + d*x]^2]*Sin[c + d*x])/(b^3*d)}
{Cos[c + d*x]^1*(b*Cos[c + d*x])^n, x, 3, ((b*Cos[c + d*x])^(2 + n)*(Cos[c + d*x]^2)^((1/2)*(-2 - n))*Hypergeometric2F1[1/2, -(n/2), 3/2, Sin[c + d*x]^2]*Sin[c + d*x])/(b^2*d)}
{Cos[c + d*x]^0*(b*Cos[c + d*x])^n, x, 2, ((b*Cos[c + d*x])^(1 + n)*(Cos[c + d*x]^2)^((1/2)*(-1 - n))*Hypergeometric2F1[1/2, (1 - n)/2, 3/2, Sin[c + d*x]^2]*Sin[c + d*x])/(b*d)}
{Sec[c + d*x]^1*(b*Cos[c + d*x])^n, x, 3, ((b*Cos[c + d*x])^n*Hypergeometric2F1[1/2, (2 - n)/2, 3/2, Sin[c + d*x]^2]*Sin[c + d*x])/((Cos[c + d*x]^2)^(n/2)*d)}
{Sec[c + d*x]^2*(b*Cos[c + d*x])^n, x, 3, (b*(b*Cos[c + d*x])^(-1 + n)*(Cos[c + d*x]^2)^((1 - n)/2)*Hypergeometric2F1[1/2, (3 - n)/2, 3/2, Sin[c + d*x]^2]*Sin[c + d*x])/d}
{Sec[c + d*x]^3*(b*Cos[c + d*x])^n, x, 3, (b^2*(b*Cos[c + d*x])^(-2 + n)*(Cos[c + d*x]^2)^((2 - n)/2)*Hypergeometric2F1[1/2, (4 - n)/2, 3/2, Sin[c + d*x]^2]*Sin[c + d*x])/d}
{Sec[c + d*x]^4*(b*Cos[c + d*x])^n, x, 3, (b^3*(b*Cos[c + d*x])^(-3 + n)*(Cos[c + d*x]^2)^((3 - n)/2)*Hypergeometric2F1[1/2, (5 - n)/2, 3/2, Sin[c + d*x]^2]*Sin[c + d*x])/d}


{Cos[c + d*x]^(5/2)*(b*Cos[c + d*x])^n, x, 2, (Cos[c + d*x]^(7/2)*(b*Cos[c + d*x])^n*(Cos[c + d*x]^2)^((1/4)*(-7 - 2*n))*Hypergeometric2F1[1/2, (1/4)*(-3 - 2*n), 3/2, Sin[c + d*x]^2]*Sin[c + d*x])/d}
{Cos[c + d*x]^(3/2)*(b*Cos[c + d*x])^n, x, 2, (Cos[c + d*x]^(5/2)*(b*Cos[c + d*x])^n*(Cos[c + d*x]^2)^((1/4)*(-5 - 2*n))*Hypergeometric2F1[1/2, (1/4)*(-1 - 2*n), 3/2, Sin[c + d*x]^2]*Sin[c + d*x])/d}
{Cos[c + d*x]^(1/2)*(b*Cos[c + d*x])^n, x, 2, (Cos[c + d*x]^(3/2)*(b*Cos[c + d*x])^n*(Cos[c + d*x]^2)^((1/4)*(-3 - 2*n))*Hypergeometric2F1[1/2, (1/4)*(1 - 2*n), 3/2, Sin[c + d*x]^2]*Sin[c + d*x])/d}
{Cos[c + d*x]^(-1/2)*(b*Cos[c + d*x])^n, x, 2, (Sqrt[Cos[c + d*x]]*(b*Cos[c + d*x])^n*(Cos[c + d*x]^2)^((1/4)*(-1 - 2*n))*Hypergeometric2F1[1/2, (1/4)*(3 - 2*n), 3/2, Sin[c + d*x]^2]*Sin[c + d*x])/d}
{Cos[c + d*x]^(-3/2)*(b*Cos[c + d*x])^n, x, 2, ((b*Cos[c + d*x])^n*(Cos[c + d*x]^2)^((1/4)*(1 - 2*n))*Hypergeometric2F1[1/2, (1/4)*(5 - 2*n), 3/2, Sin[c + d*x]^2]*Sin[c + d*x])/(d*Sqrt[Cos[c + d*x]])}
{Cos[c + d*x]^(-5/2)*(b*Cos[c + d*x])^n, x, 2, ((b*Cos[c + d*x])^n*(Cos[c + d*x]^2)^((1/4)*(3 - 2*n))*Hypergeometric2F1[1/2, (1/4)*(7 - 2*n), 3/2, Sin[c + d*x]^2]*Sin[c + d*x])/(d*Cos[c + d*x]^(3/2))}
{Cos[c + d*x]^(-7/2)*(b*Cos[c + d*x])^n, x, 2, ((b*Cos[c + d*x])^n*(Cos[c + d*x]^2)^((1/4)*(5 - 2*n))*Hypergeometric2F1[1/2, (1/4)*(9 - 2*n), 3/2, Sin[c + d*x]^2]*Sin[c + d*x])/(d*Cos[c + d*x]^(5/2))}
{Cos[c + d*x]^(-9/2)*(b*Cos[c + d*x])^n, x, 2, ((b*Cos[c + d*x])^n*(Cos[c + d*x]^2)^((1/4)*(7 - 2*n))*Hypergeometric2F1[1/2, (1/4)*(11 - 2*n), 3/2, Sin[c + d*x]^2]*Sin[c + d*x])/(d*Cos[c + d*x]^(7/2))}


(* ::Section:: *)
(*Cos[c+d x]^m (A+B Cos[c+d x]) (b Cos[c+d x])^(n/2)*)


(* ::Subsection::Closed:: *)
(*Integrands of the form Cos[c+d x]^m (A+B Cos[c+d x]) (b Cos[c+d x])^(n/2)*)


(* ::Subsubsection::Closed:: *)
(*n>0*)


{Cos[c + d*x]^2*(A + B*Cos[c + d*x])*(b*Cos[c + d*x])^(1/2), x, 9, (6*A*Sqrt[b*Cos[c + d*x]]*EllipticE[(1/2)*(c + d*x), 2])/(5*d*Sqrt[Cos[c + d*x]]) + (10*b*B*Sqrt[Cos[c + d*x]]*EllipticF[(1/2)*(c + d*x), 2])/(21*d*Sqrt[b*Cos[c + d*x]]) + (10*B*Sqrt[b*Cos[c + d*x]]*Sin[c + d*x])/(21*d) + (2*A*(b*Cos[c + d*x])^(3/2)*Sin[c + d*x])/(5*b*d) + (2*B*(b*Cos[c + d*x])^(5/2)*Sin[c + d*x])/(7*b^2*d)}
{Cos[c + d*x]^1*(A + B*Cos[c + d*x])*(b*Cos[c + d*x])^(1/2), x, 8, (6*B*Sqrt[b*Cos[c + d*x]]*EllipticE[(1/2)*(c + d*x), 2])/(5*d*Sqrt[Cos[c + d*x]]) + (2*A*b*Sqrt[Cos[c + d*x]]*EllipticF[(1/2)*(c + d*x), 2])/(3*d*Sqrt[b*Cos[c + d*x]]) + (2*A*Sqrt[b*Cos[c + d*x]]*Sin[c + d*x])/(3*d) + (2*B*(b*Cos[c + d*x])^(3/2)*Sin[c + d*x])/(5*b*d)}
{Cos[c + d*x]^0*(A + B*Cos[c + d*x])*(b*Cos[c + d*x])^(1/2), x, 6, (2*A*Sqrt[b*Cos[c + d*x]]*EllipticE[(1/2)*(c + d*x), 2])/(d*Sqrt[Cos[c + d*x]]) + (2*b*B*Sqrt[Cos[c + d*x]]*EllipticF[(1/2)*(c + d*x), 2])/(3*d*Sqrt[b*Cos[c + d*x]]) + (2*B*Sqrt[b*Cos[c + d*x]]*Sin[c + d*x])/(3*d)}
{Sec[c + d*x]^1*(A + B*Cos[c + d*x])*(b*Cos[c + d*x])^(1/2), x, 6, (2*B*Sqrt[b*Cos[c + d*x]]*EllipticE[(1/2)*(c + d*x), 2])/(d*Sqrt[Cos[c + d*x]]) + (2*A*b*Sqrt[Cos[c + d*x]]*EllipticF[(1/2)*(c + d*x), 2])/(d*Sqrt[b*Cos[c + d*x]])}
{Sec[c + d*x]^2*(A + B*Cos[c + d*x])*(b*Cos[c + d*x])^(1/2), x, 7, -((2*A*Sqrt[b*Cos[c + d*x]]*EllipticE[(1/2)*(c + d*x), 2])/(d*Sqrt[Cos[c + d*x]])) + (2*b*B*Sqrt[Cos[c + d*x]]*EllipticF[(1/2)*(c + d*x), 2])/(d*Sqrt[b*Cos[c + d*x]]) + (2*A*b*Sin[c + d*x])/(d*Sqrt[b*Cos[c + d*x]])}
{Sec[c + d*x]^3*(A + B*Cos[c + d*x])*(b*Cos[c + d*x])^(1/2), x, 8, -((2*B*Sqrt[b*Cos[c + d*x]]*EllipticE[(1/2)*(c + d*x), 2])/(d*Sqrt[Cos[c + d*x]])) + (2*A*b*Sqrt[Cos[c + d*x]]*EllipticF[(1/2)*(c + d*x), 2])/(3*d*Sqrt[b*Cos[c + d*x]]) + (2*A*b^2*Sin[c + d*x])/(3*d*(b*Cos[c + d*x])^(3/2)) + (2*b*B*Sin[c + d*x])/(d*Sqrt[b*Cos[c + d*x]])}
{Sec[c + d*x]^4*(A + B*Cos[c + d*x])*(b*Cos[c + d*x])^(1/2), x, 9, -((6*A*Sqrt[b*Cos[c + d*x]]*EllipticE[(1/2)*(c + d*x), 2])/(5*d*Sqrt[Cos[c + d*x]])) + (2*b*B*Sqrt[Cos[c + d*x]]*EllipticF[(1/2)*(c + d*x), 2])/(3*d*Sqrt[b*Cos[c + d*x]]) + (2*A*b^3*Sin[c + d*x])/(5*d*(b*Cos[c + d*x])^(5/2)) + (2*b^2*B*Sin[c + d*x])/(3*d*(b*Cos[c + d*x])^(3/2)) + (6*A*b*Sin[c + d*x])/(5*d*Sqrt[b*Cos[c + d*x]])}


{Cos[c + d*x]^1*(A + B*Cos[c + d*x])*(b*Cos[c + d*x])^(3/2), x, 9, (6*A*b*Sqrt[b*Cos[c + d*x]]*EllipticE[(1/2)*(c + d*x), 2])/(5*d*Sqrt[Cos[c + d*x]]) + (10*b^2*B*Sqrt[Cos[c + d*x]]*EllipticF[(1/2)*(c + d*x), 2])/(21*d*Sqrt[b*Cos[c + d*x]]) + (10*b*B*Sqrt[b*Cos[c + d*x]]*Sin[c + d*x])/(21*d) + (2*A*(b*Cos[c + d*x])^(3/2)*Sin[c + d*x])/(5*d) + (2*B*(b*Cos[c + d*x])^(5/2)*Sin[c + d*x])/(7*b*d)}
{Cos[c + d*x]^0*(A + B*Cos[c + d*x])*(b*Cos[c + d*x])^(3/2), x, 7, (6*b*B*Sqrt[b*Cos[c + d*x]]*EllipticE[(1/2)*(c + d*x), 2])/(5*d*Sqrt[Cos[c + d*x]]) + (2*A*b^2*Sqrt[Cos[c + d*x]]*EllipticF[(1/2)*(c + d*x), 2])/(3*d*Sqrt[b*Cos[c + d*x]]) + (2*A*b*Sqrt[b*Cos[c + d*x]]*Sin[c + d*x])/(3*d) + (2*B*(b*Cos[c + d*x])^(3/2)*Sin[c + d*x])/(5*d)}
{Sec[c + d*x]^1*(A + B*Cos[c + d*x])*(b*Cos[c + d*x])^(3/2), x, 7, (2*A*b*Sqrt[b*Cos[c + d*x]]*EllipticE[(1/2)*(c + d*x), 2])/(d*Sqrt[Cos[c + d*x]]) + (2*b^2*B*Sqrt[Cos[c + d*x]]*EllipticF[(1/2)*(c + d*x), 2])/(3*d*Sqrt[b*Cos[c + d*x]]) + (2*b*B*Sqrt[b*Cos[c + d*x]]*Sin[c + d*x])/(3*d)}
{Sec[c + d*x]^2*(A + B*Cos[c + d*x])*(b*Cos[c + d*x])^(3/2), x, 6, (2*b*B*Sqrt[b*Cos[c + d*x]]*EllipticE[(1/2)*(c + d*x), 2])/(d*Sqrt[Cos[c + d*x]]) + (2*A*b^2*Sqrt[Cos[c + d*x]]*EllipticF[(1/2)*(c + d*x), 2])/(d*Sqrt[b*Cos[c + d*x]])}
{Sec[c + d*x]^3*(A + B*Cos[c + d*x])*(b*Cos[c + d*x])^(3/2), x, 7, -((2*A*b*Sqrt[b*Cos[c + d*x]]*EllipticE[(1/2)*(c + d*x), 2])/(d*Sqrt[Cos[c + d*x]])) + (2*b^2*B*Sqrt[Cos[c + d*x]]*EllipticF[(1/2)*(c + d*x), 2])/(d*Sqrt[b*Cos[c + d*x]]) + (2*A*b^2*Sin[c + d*x])/(d*Sqrt[b*Cos[c + d*x]])}
{Sec[c + d*x]^4*(A + B*Cos[c + d*x])*(b*Cos[c + d*x])^(3/2), x, 8, -((2*b*B*Sqrt[b*Cos[c + d*x]]*EllipticE[(1/2)*(c + d*x), 2])/(d*Sqrt[Cos[c + d*x]])) + (2*A*b^2*Sqrt[Cos[c + d*x]]*EllipticF[(1/2)*(c + d*x), 2])/(3*d*Sqrt[b*Cos[c + d*x]]) + (2*A*b^3*Sin[c + d*x])/(3*d*(b*Cos[c + d*x])^(3/2)) + (2*b^2*B*Sin[c + d*x])/(d*Sqrt[b*Cos[c + d*x]])}
{Sec[c + d*x]^5*(A + B*Cos[c + d*x])*(b*Cos[c + d*x])^(3/2), x, 9, -((6*A*b*Sqrt[b*Cos[c + d*x]]*EllipticE[(1/2)*(c + d*x), 2])/(5*d*Sqrt[Cos[c + d*x]])) + (2*b^2*B*Sqrt[Cos[c + d*x]]*EllipticF[(1/2)*(c + d*x), 2])/(3*d*Sqrt[b*Cos[c + d*x]]) + (2*A*b^4*Sin[c + d*x])/(5*d*(b*Cos[c + d*x])^(5/2)) + (2*b^3*B*Sin[c + d*x])/(3*d*(b*Cos[c + d*x])^(3/2)) + (6*A*b^2*Sin[c + d*x])/(5*d*Sqrt[b*Cos[c + d*x]])}


{Cos[c + d*x]^0*(A + B*Cos[c + d*x])*(b*Cos[c + d*x])^(5/2), x, 8, (6*A*b^2*Sqrt[b*Cos[c + d*x]]*EllipticE[(1/2)*(c + d*x), 2])/(5*d*Sqrt[Cos[c + d*x]]) + (10*b^3*B*Sqrt[Cos[c + d*x]]*EllipticF[(1/2)*(c + d*x), 2])/(21*d*Sqrt[b*Cos[c + d*x]]) + (10*b^2*B*Sqrt[b*Cos[c + d*x]]*Sin[c + d*x])/(21*d) + (2*A*b*(b*Cos[c + d*x])^(3/2)*Sin[c + d*x])/(5*d) + (2*B*(b*Cos[c + d*x])^(5/2)*Sin[c + d*x])/(7*d)}
{Sec[c + d*x]^1*(A + B*Cos[c + d*x])*(b*Cos[c + d*x])^(5/2), x, 8, (6*b^2*B*Sqrt[b*Cos[c + d*x]]*EllipticE[(1/2)*(c + d*x), 2])/(5*d*Sqrt[Cos[c + d*x]]) + (2*A*b^3*Sqrt[Cos[c + d*x]]*EllipticF[(1/2)*(c + d*x), 2])/(3*d*Sqrt[b*Cos[c + d*x]]) + (2*A*b^2*Sqrt[b*Cos[c + d*x]]*Sin[c + d*x])/(3*d) + (2*b*B*(b*Cos[c + d*x])^(3/2)*Sin[c + d*x])/(5*d)}
{Sec[c + d*x]^2*(A + B*Cos[c + d*x])*(b*Cos[c + d*x])^(5/2), x, 7, (2*A*b^2*Sqrt[b*Cos[c + d*x]]*EllipticE[(1/2)*(c + d*x), 2])/(d*Sqrt[Cos[c + d*x]]) + (2*b^3*B*Sqrt[Cos[c + d*x]]*EllipticF[(1/2)*(c + d*x), 2])/(3*d*Sqrt[b*Cos[c + d*x]]) + (2*b^2*B*Sqrt[b*Cos[c + d*x]]*Sin[c + d*x])/(3*d)}
{Sec[c + d*x]^3*(A + B*Cos[c + d*x])*(b*Cos[c + d*x])^(5/2), x, 6, (2*b^2*B*Sqrt[b*Cos[c + d*x]]*EllipticE[(1/2)*(c + d*x), 2])/(d*Sqrt[Cos[c + d*x]]) + (2*A*b^3*Sqrt[Cos[c + d*x]]*EllipticF[(1/2)*(c + d*x), 2])/(d*Sqrt[b*Cos[c + d*x]])}
{Sec[c + d*x]^4*(A + B*Cos[c + d*x])*(b*Cos[c + d*x])^(5/2), x, 7, -((2*A*b^2*Sqrt[b*Cos[c + d*x]]*EllipticE[(1/2)*(c + d*x), 2])/(d*Sqrt[Cos[c + d*x]])) + (2*b^3*B*Sqrt[Cos[c + d*x]]*EllipticF[(1/2)*(c + d*x), 2])/(d*Sqrt[b*Cos[c + d*x]]) + (2*A*b^3*Sin[c + d*x])/(d*Sqrt[b*Cos[c + d*x]])}
{Sec[c + d*x]^5*(A + B*Cos[c + d*x])*(b*Cos[c + d*x])^(5/2), x, 8, -((2*b^2*B*Sqrt[b*Cos[c + d*x]]*EllipticE[(1/2)*(c + d*x), 2])/(d*Sqrt[Cos[c + d*x]])) + (2*A*b^3*Sqrt[Cos[c + d*x]]*EllipticF[(1/2)*(c + d*x), 2])/(3*d*Sqrt[b*Cos[c + d*x]]) + (2*A*b^4*Sin[c + d*x])/(3*d*(b*Cos[c + d*x])^(3/2)) + (2*b^3*B*Sin[c + d*x])/(d*Sqrt[b*Cos[c + d*x]])}
{Sec[c + d*x]^6*(A + B*Cos[c + d*x])*(b*Cos[c + d*x])^(5/2), x, 9, -((6*A*b^2*Sqrt[b*Cos[c + d*x]]*EllipticE[(1/2)*(c + d*x), 2])/(5*d*Sqrt[Cos[c + d*x]])) + (2*b^3*B*Sqrt[Cos[c + d*x]]*EllipticF[(1/2)*(c + d*x), 2])/(3*d*Sqrt[b*Cos[c + d*x]]) + (2*A*b^5*Sin[c + d*x])/(5*d*(b*Cos[c + d*x])^(5/2)) + (2*b^4*B*Sin[c + d*x])/(3*d*(b*Cos[c + d*x])^(3/2)) + (6*A*b^3*Sin[c + d*x])/(5*d*Sqrt[b*Cos[c + d*x]])}


(* ::Subsubsection::Closed:: *)
(*n<0*)


{Cos[c + d*x]^3*(A + B*Cos[c + d*x])/(b*Cos[c + d*x])^(1/2), x, 9, (6*A*Sqrt[b*Cos[c + d*x]]*EllipticE[(1/2)*(c + d*x), 2])/(5*b*d*Sqrt[Cos[c + d*x]]) + (10*B*Sqrt[Cos[c + d*x]]*EllipticF[(1/2)*(c + d*x), 2])/(21*d*Sqrt[b*Cos[c + d*x]]) + (10*B*Sqrt[b*Cos[c + d*x]]*Sin[c + d*x])/(21*b*d) + (2*A*(b*Cos[c + d*x])^(3/2)*Sin[c + d*x])/(5*b^2*d) + (2*B*(b*Cos[c + d*x])^(5/2)*Sin[c + d*x])/(7*b^3*d)}
{Cos[c + d*x]^2*(A + B*Cos[c + d*x])/(b*Cos[c + d*x])^(1/2), x, 8, (6*B*Sqrt[b*Cos[c + d*x]]*EllipticE[(1/2)*(c + d*x), 2])/(5*b*d*Sqrt[Cos[c + d*x]]) + (2*A*Sqrt[Cos[c + d*x]]*EllipticF[(1/2)*(c + d*x), 2])/(3*d*Sqrt[b*Cos[c + d*x]]) + (2*A*Sqrt[b*Cos[c + d*x]]*Sin[c + d*x])/(3*b*d) + (2*B*(b*Cos[c + d*x])^(3/2)*Sin[c + d*x])/(5*b^2*d)}
{Cos[c + d*x]^1*(A + B*Cos[c + d*x])/(b*Cos[c + d*x])^(1/2), x, 7, (2*A*Sqrt[b*Cos[c + d*x]]*EllipticE[(1/2)*(c + d*x), 2])/(b*d*Sqrt[Cos[c + d*x]]) + (2*B*Sqrt[Cos[c + d*x]]*EllipticF[(1/2)*(c + d*x), 2])/(3*d*Sqrt[b*Cos[c + d*x]]) + (2*B*Sqrt[b*Cos[c + d*x]]*Sin[c + d*x])/(3*b*d)}
{Cos[c + d*x]^0*(A + B*Cos[c + d*x])/(b*Cos[c + d*x])^(1/2), x, 5, (2*B*Sqrt[b*Cos[c + d*x]]*EllipticE[(1/2)*(c + d*x), 2])/(b*d*Sqrt[Cos[c + d*x]]) + (2*A*Sqrt[Cos[c + d*x]]*EllipticF[(1/2)*(c + d*x), 2])/(d*Sqrt[b*Cos[c + d*x]])}
{Sec[c + d*x]^1*(A + B*Cos[c + d*x])/(b*Cos[c + d*x])^(1/2), x, 7, -((2*A*Sqrt[b*Cos[c + d*x]]*EllipticE[(1/2)*(c + d*x), 2])/(b*d*Sqrt[Cos[c + d*x]])) + (2*B*Sqrt[Cos[c + d*x]]*EllipticF[(1/2)*(c + d*x), 2])/(d*Sqrt[b*Cos[c + d*x]]) + (2*A*Sin[c + d*x])/(d*Sqrt[b*Cos[c + d*x]])}
{Sec[c + d*x]^2*(A + B*Cos[c + d*x])/(b*Cos[c + d*x])^(1/2), x, 8, -((2*B*Sqrt[b*Cos[c + d*x]]*EllipticE[(1/2)*(c + d*x), 2])/(b*d*Sqrt[Cos[c + d*x]])) + (2*A*Sqrt[Cos[c + d*x]]*EllipticF[(1/2)*(c + d*x), 2])/(3*d*Sqrt[b*Cos[c + d*x]]) + (2*A*b*Sin[c + d*x])/(3*d*(b*Cos[c + d*x])^(3/2)) + (2*B*Sin[c + d*x])/(d*Sqrt[b*Cos[c + d*x]])}
{Sec[c + d*x]^3*(A + B*Cos[c + d*x])/(b*Cos[c + d*x])^(1/2), x, 9, -((6*A*Sqrt[b*Cos[c + d*x]]*EllipticE[(1/2)*(c + d*x), 2])/(5*b*d*Sqrt[Cos[c + d*x]])) + (2*B*Sqrt[Cos[c + d*x]]*EllipticF[(1/2)*(c + d*x), 2])/(3*d*Sqrt[b*Cos[c + d*x]]) + (2*A*b^2*Sin[c + d*x])/(5*d*(b*Cos[c + d*x])^(5/2)) + (2*b*B*Sin[c + d*x])/(3*d*(b*Cos[c + d*x])^(3/2)) + (6*A*Sin[c + d*x])/(5*d*Sqrt[b*Cos[c + d*x]])}


{Cos[c + d*x]^4*(A + B*Cos[c + d*x])/(b*Cos[c + d*x])^(3/2), x, 9, (6*A*Sqrt[b*Cos[c + d*x]]*EllipticE[(1/2)*(c + d*x), 2])/(5*b^2*d*Sqrt[Cos[c + d*x]]) + (10*B*Sqrt[Cos[c + d*x]]*EllipticF[(1/2)*(c + d*x), 2])/(21*b*d*Sqrt[b*Cos[c + d*x]]) + (10*B*Sqrt[b*Cos[c + d*x]]*Sin[c + d*x])/(21*b^2*d) + (2*A*(b*Cos[c + d*x])^(3/2)*Sin[c + d*x])/(5*b^3*d) + (2*B*(b*Cos[c + d*x])^(5/2)*Sin[c + d*x])/(7*b^4*d)}
{Cos[c + d*x]^3*(A + B*Cos[c + d*x])/(b*Cos[c + d*x])^(3/2), x, 8, (6*B*Sqrt[b*Cos[c + d*x]]*EllipticE[(1/2)*(c + d*x), 2])/(5*b^2*d*Sqrt[Cos[c + d*x]]) + (2*A*Sqrt[Cos[c + d*x]]*EllipticF[(1/2)*(c + d*x), 2])/(3*b*d*Sqrt[b*Cos[c + d*x]]) + (2*A*Sqrt[b*Cos[c + d*x]]*Sin[c + d*x])/(3*b^2*d) + (2*B*(b*Cos[c + d*x])^(3/2)*Sin[c + d*x])/(5*b^3*d)}
{Cos[c + d*x]^2*(A + B*Cos[c + d*x])/(b*Cos[c + d*x])^(3/2), x, 7, (2*A*Sqrt[b*Cos[c + d*x]]*EllipticE[(1/2)*(c + d*x), 2])/(b^2*d*Sqrt[Cos[c + d*x]]) + (2*B*Sqrt[Cos[c + d*x]]*EllipticF[(1/2)*(c + d*x), 2])/(3*b*d*Sqrt[b*Cos[c + d*x]]) + (2*B*Sqrt[b*Cos[c + d*x]]*Sin[c + d*x])/(3*b^2*d)}
{Cos[c + d*x]^1*(A + B*Cos[c + d*x])/(b*Cos[c + d*x])^(3/2), x, 6, (2*B*Sqrt[b*Cos[c + d*x]]*EllipticE[(1/2)*(c + d*x), 2])/(b^2*d*Sqrt[Cos[c + d*x]]) + (2*A*Sqrt[Cos[c + d*x]]*EllipticF[(1/2)*(c + d*x), 2])/(b*d*Sqrt[b*Cos[c + d*x]])}
{Cos[c + d*x]^0*(A + B*Cos[c + d*x])/(b*Cos[c + d*x])^(3/2), x, 6, -((2*A*Sqrt[b*Cos[c + d*x]]*EllipticE[(1/2)*(c + d*x), 2])/(b^2*d*Sqrt[Cos[c + d*x]])) + (2*B*Sqrt[Cos[c + d*x]]*EllipticF[(1/2)*(c + d*x), 2])/(b*d*Sqrt[b*Cos[c + d*x]]) + (2*A*Sin[c + d*x])/(b*d*Sqrt[b*Cos[c + d*x]])}
{Sec[c + d*x]^1*(A + B*Cos[c + d*x])/(b*Cos[c + d*x])^(3/2), x, 8, -((2*B*Sqrt[b*Cos[c + d*x]]*EllipticE[(1/2)*(c + d*x), 2])/(b^2*d*Sqrt[Cos[c + d*x]])) + (2*A*Sqrt[Cos[c + d*x]]*EllipticF[(1/2)*(c + d*x), 2])/(3*b*d*Sqrt[b*Cos[c + d*x]]) + (2*A*Sin[c + d*x])/(3*d*(b*Cos[c + d*x])^(3/2)) + (2*B*Sin[c + d*x])/(b*d*Sqrt[b*Cos[c + d*x]])}
{Sec[c + d*x]^2*(A + B*Cos[c + d*x])/(b*Cos[c + d*x])^(3/2), x, 9, -((6*A*Sqrt[b*Cos[c + d*x]]*EllipticE[(1/2)*(c + d*x), 2])/(5*b^2*d*Sqrt[Cos[c + d*x]])) + (2*B*Sqrt[Cos[c + d*x]]*EllipticF[(1/2)*(c + d*x), 2])/(3*b*d*Sqrt[b*Cos[c + d*x]]) + (2*A*b*Sin[c + d*x])/(5*d*(b*Cos[c + d*x])^(5/2)) + (2*B*Sin[c + d*x])/(3*d*(b*Cos[c + d*x])^(3/2)) + (6*A*Sin[c + d*x])/(5*b*d*Sqrt[b*Cos[c + d*x]])}


{Cos[c + d*x]^5*(A + B*Cos[c + d*x])/(b*Cos[c + d*x])^(5/2), x, 9, (6*A*Sqrt[b*Cos[c + d*x]]*EllipticE[(1/2)*(c + d*x), 2])/(5*b^3*d*Sqrt[Cos[c + d*x]]) + (10*B*Sqrt[Cos[c + d*x]]*EllipticF[(1/2)*(c + d*x), 2])/(21*b^2*d*Sqrt[b*Cos[c + d*x]]) + (10*B*Sqrt[b*Cos[c + d*x]]*Sin[c + d*x])/(21*b^3*d) + (2*A*(b*Cos[c + d*x])^(3/2)*Sin[c + d*x])/(5*b^4*d) + (2*B*(b*Cos[c + d*x])^(5/2)*Sin[c + d*x])/(7*b^5*d)}
{Cos[c + d*x]^4*(A + B*Cos[c + d*x])/(b*Cos[c + d*x])^(5/2), x, 8, (6*B*Sqrt[b*Cos[c + d*x]]*EllipticE[(1/2)*(c + d*x), 2])/(5*b^3*d*Sqrt[Cos[c + d*x]]) + (2*A*Sqrt[Cos[c + d*x]]*EllipticF[(1/2)*(c + d*x), 2])/(3*b^2*d*Sqrt[b*Cos[c + d*x]]) + (2*A*Sqrt[b*Cos[c + d*x]]*Sin[c + d*x])/(3*b^3*d) + (2*B*(b*Cos[c + d*x])^(3/2)*Sin[c + d*x])/(5*b^4*d)}
{Cos[c + d*x]^3*(A + B*Cos[c + d*x])/(b*Cos[c + d*x])^(5/2), x, 7, (2*A*Sqrt[b*Cos[c + d*x]]*EllipticE[(1/2)*(c + d*x), 2])/(b^3*d*Sqrt[Cos[c + d*x]]) + (2*B*Sqrt[Cos[c + d*x]]*EllipticF[(1/2)*(c + d*x), 2])/(3*b^2*d*Sqrt[b*Cos[c + d*x]]) + (2*B*Sqrt[b*Cos[c + d*x]]*Sin[c + d*x])/(3*b^3*d)}
{Cos[c + d*x]^2*(A + B*Cos[c + d*x])/(b*Cos[c + d*x])^(5/2), x, 6, (2*B*Sqrt[b*Cos[c + d*x]]*EllipticE[(1/2)*(c + d*x), 2])/(b^3*d*Sqrt[Cos[c + d*x]]) + (2*A*Sqrt[Cos[c + d*x]]*EllipticF[(1/2)*(c + d*x), 2])/(b^2*d*Sqrt[b*Cos[c + d*x]])}
{Cos[c + d*x]^1*(A + B*Cos[c + d*x])/(b*Cos[c + d*x])^(5/2), x, 7, -((2*A*Sqrt[b*Cos[c + d*x]]*EllipticE[(1/2)*(c + d*x), 2])/(b^3*d*Sqrt[Cos[c + d*x]])) + (2*B*Sqrt[Cos[c + d*x]]*EllipticF[(1/2)*(c + d*x), 2])/(b^2*d*Sqrt[b*Cos[c + d*x]]) + (2*A*Sin[c + d*x])/(b^2*d*Sqrt[b*Cos[c + d*x]])}
{Cos[c + d*x]^0*(A + B*Cos[c + d*x])/(b*Cos[c + d*x])^(5/2), x, 7, -((2*B*Sqrt[b*Cos[c + d*x]]*EllipticE[(1/2)*(c + d*x), 2])/(b^3*d*Sqrt[Cos[c + d*x]])) + (2*A*Sqrt[Cos[c + d*x]]*EllipticF[(1/2)*(c + d*x), 2])/(3*b^2*d*Sqrt[b*Cos[c + d*x]]) + (2*A*Sin[c + d*x])/(3*b*d*(b*Cos[c + d*x])^(3/2)) + (2*B*Sin[c + d*x])/(b^2*d*Sqrt[b*Cos[c + d*x]])}
{Sec[c + d*x]^1*(A + B*Cos[c + d*x])/(b*Cos[c + d*x])^(5/2), x, 9, -((6*A*Sqrt[b*Cos[c + d*x]]*EllipticE[(1/2)*(c + d*x), 2])/(5*b^3*d*Sqrt[Cos[c + d*x]])) + (2*B*Sqrt[Cos[c + d*x]]*EllipticF[(1/2)*(c + d*x), 2])/(3*b^2*d*Sqrt[b*Cos[c + d*x]]) + (2*A*Sin[c + d*x])/(5*d*(b*Cos[c + d*x])^(5/2)) + (2*B*Sin[c + d*x])/(3*b*d*(b*Cos[c + d*x])^(3/2)) + (6*A*Sin[c + d*x])/(5*b^2*d*Sqrt[b*Cos[c + d*x]])}


{(A + B*Cos[c + d*x])/(b*Cos[c + d*x])^(7/2), x, 8, -((6*A*Sqrt[b*Cos[c + d*x]]*EllipticE[(1/2)*(c + d*x), 2])/(5*b^4*d*Sqrt[Cos[c + d*x]])) + (2*B*Sqrt[Cos[c + d*x]]*EllipticF[(1/2)*(c + d*x), 2])/(3*b^3*d*Sqrt[b*Cos[c + d*x]]) + (2*A*Sin[c + d*x])/(5*b*d*(b*Cos[c + d*x])^(5/2)) + (2*B*Sin[c + d*x])/(3*b^2*d*(b*Cos[c + d*x])^(3/2)) + (6*A*Sin[c + d*x])/(5*b^3*d*Sqrt[b*Cos[c + d*x]])}


(* ::Subsection::Closed:: *)
(*Integrands of the form Cos[c+d x]^(m/2) (A+B Cos[c+d x]) (b Cos[c+d x])^(n/2)*)


(* ::Subsubsection::Closed:: *)
(*n>0*)


{Cos[c + d*x]^(5/2)*(A + B*Cos[c + d*x])*(b*Cos[c + d*x])^(1/2), x, 6, (3*B*x*Sqrt[b*Cos[c + d*x]])/(8*Sqrt[Cos[c + d*x]]) + (A*Sqrt[b*Cos[c + d*x]]*Sin[c + d*x])/(d*Sqrt[Cos[c + d*x]]) + (3*B*Sqrt[Cos[c + d*x]]*Sqrt[b*Cos[c + d*x]]*Sin[c + d*x])/(8*d) + (B*Cos[c + d*x]^(5/2)*Sqrt[b*Cos[c + d*x]]*Sin[c + d*x])/(4*d) - (A*Sqrt[b*Cos[c + d*x]]*Sin[c + d*x]^3)/(3*d*Sqrt[Cos[c + d*x]])}
{Cos[c + d*x]^(3/2)*(A + B*Cos[c + d*x])*(b*Cos[c + d*x])^(1/2), x, 5, (A*x*Sqrt[b*Cos[c + d*x]])/(2*Sqrt[Cos[c + d*x]]) + (B*Sqrt[b*Cos[c + d*x]]*Sin[c + d*x])/(d*Sqrt[Cos[c + d*x]]) + (A*Sqrt[Cos[c + d*x]]*Sqrt[b*Cos[c + d*x]]*Sin[c + d*x])/(2*d) - (B*Sqrt[b*Cos[c + d*x]]*Sin[c + d*x]^3)/(3*d*Sqrt[Cos[c + d*x]])}
{Cos[c + d*x]^(1/2)*(A + B*Cos[c + d*x])*(b*Cos[c + d*x])^(1/2), x, 4, (B*x*Sqrt[b*Cos[c + d*x]])/(2*Sqrt[Cos[c + d*x]]) + (A*Sqrt[b*Cos[c + d*x]]*Sin[c + d*x])/(d*Sqrt[Cos[c + d*x]]) + (B*Sqrt[Cos[c + d*x]]*Sqrt[b*Cos[c + d*x]]*Sin[c + d*x])/(2*d)}
{Cos[c + d*x]^(-1/2)*(A + B*Cos[c + d*x])*(b*Cos[c + d*x])^(1/2), x, 3, (A*x*Sqrt[b*Cos[c + d*x]])/Sqrt[Cos[c + d*x]] + (B*Sqrt[b*Cos[c + d*x]]*Sin[c + d*x])/(d*Sqrt[Cos[c + d*x]])}
{Cos[c + d*x]^(-3/2)*(A + B*Cos[c + d*x])*(b*Cos[c + d*x])^(1/2), x, 3, (B*x*Sqrt[b*Cos[c + d*x]])/Sqrt[Cos[c + d*x]] + (A*ArcTanh[Sin[c + d*x]]*Sqrt[b*Cos[c + d*x]])/(d*Sqrt[Cos[c + d*x]])}
{Cos[c + d*x]^(-5/2)*(A + B*Cos[c + d*x])*(b*Cos[c + d*x])^(1/2), x, 4, (B*ArcTanh[Sin[c + d*x]]*Sqrt[b*Cos[c + d*x]])/(d*Sqrt[Cos[c + d*x]]) + (A*Sqrt[b*Cos[c + d*x]]*Sin[c + d*x])/(d*Cos[c + d*x]^(3/2))}
{Cos[c + d*x]^(-7/2)*(A + B*Cos[c + d*x])*(b*Cos[c + d*x])^(1/2), x, 5, (A*ArcTanh[Sin[c + d*x]]*Sqrt[b*Cos[c + d*x]])/(2*d*Sqrt[Cos[c + d*x]]) + (A*Sqrt[b*Cos[c + d*x]]*Sin[c + d*x])/(2*d*Cos[c + d*x]^(5/2)) + (B*Sqrt[b*Cos[c + d*x]]*Sin[c + d*x])/(d*Cos[c + d*x]^(3/2))}
{Cos[c + d*x]^(-9/2)*(A + B*Cos[c + d*x])*(b*Cos[c + d*x])^(1/2), x, 6, (B*ArcTanh[Sin[c + d*x]]*Sqrt[b*Cos[c + d*x]])/(2*d*Sqrt[Cos[c + d*x]]) + (B*Sqrt[b*Cos[c + d*x]]*Sin[c + d*x])/(2*d*Cos[c + d*x]^(5/2)) + (A*Sqrt[b*Cos[c + d*x]]*Sin[c + d*x])/(d*Cos[c + d*x]^(3/2)) + (A*Sqrt[b*Cos[c + d*x]]*Sin[c + d*x]^3)/(3*d*Cos[c + d*x]^(7/2))}


{Cos[c + d*x]^(3/2)*(A + B*Cos[c + d*x])*(b*Cos[c + d*x])^(3/2), x, 6, (3*b*B*x*Sqrt[b*Cos[c + d*x]])/(8*Sqrt[Cos[c + d*x]]) + (A*b*Sqrt[b*Cos[c + d*x]]*Sin[c + d*x])/(d*Sqrt[Cos[c + d*x]]) + (3*b*B*Sqrt[Cos[c + d*x]]*Sqrt[b*Cos[c + d*x]]*Sin[c + d*x])/(8*d) + (b*B*Cos[c + d*x]^(5/2)*Sqrt[b*Cos[c + d*x]]*Sin[c + d*x])/(4*d) - (A*b*Sqrt[b*Cos[c + d*x]]*Sin[c + d*x]^3)/(3*d*Sqrt[Cos[c + d*x]])}
{Cos[c + d*x]^(1/2)*(A + B*Cos[c + d*x])*(b*Cos[c + d*x])^(3/2), x, 5, (A*b*x*Sqrt[b*Cos[c + d*x]])/(2*Sqrt[Cos[c + d*x]]) + (b*B*Sqrt[b*Cos[c + d*x]]*Sin[c + d*x])/(d*Sqrt[Cos[c + d*x]]) + (A*b*Sqrt[Cos[c + d*x]]*Sqrt[b*Cos[c + d*x]]*Sin[c + d*x])/(2*d) - (b*B*Sqrt[b*Cos[c + d*x]]*Sin[c + d*x]^3)/(3*d*Sqrt[Cos[c + d*x]])}
{Cos[c + d*x]^(-1/2)*(A + B*Cos[c + d*x])*(b*Cos[c + d*x])^(3/2), x, 4, (b*B*x*Sqrt[b*Cos[c + d*x]])/(2*Sqrt[Cos[c + d*x]]) + (A*b*Sqrt[b*Cos[c + d*x]]*Sin[c + d*x])/(d*Sqrt[Cos[c + d*x]]) + (b*B*Sqrt[Cos[c + d*x]]*Sqrt[b*Cos[c + d*x]]*Sin[c + d*x])/(2*d)}
{Cos[c + d*x]^(-3/2)*(A + B*Cos[c + d*x])*(b*Cos[c + d*x])^(3/2), x, 3, (A*b*x*Sqrt[b*Cos[c + d*x]])/Sqrt[Cos[c + d*x]] + (b*B*Sqrt[b*Cos[c + d*x]]*Sin[c + d*x])/(d*Sqrt[Cos[c + d*x]])}
{Cos[c + d*x]^(-5/2)*(A + B*Cos[c + d*x])*(b*Cos[c + d*x])^(3/2), x, 3, (b*B*x*Sqrt[b*Cos[c + d*x]])/Sqrt[Cos[c + d*x]] + (A*b*ArcTanh[Sin[c + d*x]]*Sqrt[b*Cos[c + d*x]])/(d*Sqrt[Cos[c + d*x]])}
{Cos[c + d*x]^(-7/2)*(A + B*Cos[c + d*x])*(b*Cos[c + d*x])^(3/2), x, 4, (b*B*ArcTanh[Sin[c + d*x]]*Sqrt[b*Cos[c + d*x]])/(d*Sqrt[Cos[c + d*x]]) + (A*b*Sqrt[b*Cos[c + d*x]]*Sin[c + d*x])/(d*Cos[c + d*x]^(3/2))}
{Cos[c + d*x]^(-9/2)*(A + B*Cos[c + d*x])*(b*Cos[c + d*x])^(3/2), x, 5, (A*b*ArcTanh[Sin[c + d*x]]*Sqrt[b*Cos[c + d*x]])/(2*d*Sqrt[Cos[c + d*x]]) + (A*b*Sqrt[b*Cos[c + d*x]]*Sin[c + d*x])/(2*d*Cos[c + d*x]^(5/2)) + (b*B*Sqrt[b*Cos[c + d*x]]*Sin[c + d*x])/(d*Cos[c + d*x]^(3/2))}
{Cos[c + d*x]^(-11/2)*(A + B*Cos[c + d*x])*(b*Cos[c + d*x])^(3/2), x, 6, (b*B*ArcTanh[Sin[c + d*x]]*Sqrt[b*Cos[c + d*x]])/(2*d*Sqrt[Cos[c + d*x]]) + (b*B*Sqrt[b*Cos[c + d*x]]*Sin[c + d*x])/(2*d*Cos[c + d*x]^(5/2)) + (A*b*Sqrt[b*Cos[c + d*x]]*Sin[c + d*x])/(d*Cos[c + d*x]^(3/2)) + (A*b*Sqrt[b*Cos[c + d*x]]*Sin[c + d*x]^3)/(3*d*Cos[c + d*x]^(7/2))}


{Cos[c + d*x]^(1/2)*(A + B*Cos[c + d*x])*(b*Cos[c + d*x])^(5/2), x, 6, (3*b^2*B*x*Sqrt[b*Cos[c + d*x]])/(8*Sqrt[Cos[c + d*x]]) + (A*b^2*Sqrt[b*Cos[c + d*x]]*Sin[c + d*x])/(d*Sqrt[Cos[c + d*x]]) + (3*b^2*B*Sqrt[Cos[c + d*x]]*Sqrt[b*Cos[c + d*x]]*Sin[c + d*x])/(8*d) + (b^2*B*Cos[c + d*x]^(5/2)*Sqrt[b*Cos[c + d*x]]*Sin[c + d*x])/(4*d) - (A*b^2*Sqrt[b*Cos[c + d*x]]*Sin[c + d*x]^3)/(3*d*Sqrt[Cos[c + d*x]])}
{Cos[c + d*x]^(-1/2)*(A + B*Cos[c + d*x])*(b*Cos[c + d*x])^(5/2), x, 5, (A*b^2*x*Sqrt[b*Cos[c + d*x]])/(2*Sqrt[Cos[c + d*x]]) + (b^2*B*Sqrt[b*Cos[c + d*x]]*Sin[c + d*x])/(d*Sqrt[Cos[c + d*x]]) + (A*b^2*Sqrt[Cos[c + d*x]]*Sqrt[b*Cos[c + d*x]]*Sin[c + d*x])/(2*d) - (b^2*B*Sqrt[b*Cos[c + d*x]]*Sin[c + d*x]^3)/(3*d*Sqrt[Cos[c + d*x]])}
{Cos[c + d*x]^(-3/2)*(A + B*Cos[c + d*x])*(b*Cos[c + d*x])^(5/2), x, 4, (b^2*B*x*Sqrt[b*Cos[c + d*x]])/(2*Sqrt[Cos[c + d*x]]) + (A*b^2*Sqrt[b*Cos[c + d*x]]*Sin[c + d*x])/(d*Sqrt[Cos[c + d*x]]) + (b^2*B*Sqrt[Cos[c + d*x]]*Sqrt[b*Cos[c + d*x]]*Sin[c + d*x])/(2*d)}
{Cos[c + d*x]^(-5/2)*(A + B*Cos[c + d*x])*(b*Cos[c + d*x])^(5/2), x, 3, (A*b^2*x*Sqrt[b*Cos[c + d*x]])/Sqrt[Cos[c + d*x]] + (b^2*B*Sqrt[b*Cos[c + d*x]]*Sin[c + d*x])/(d*Sqrt[Cos[c + d*x]])}
{Cos[c + d*x]^(-7/2)*(A + B*Cos[c + d*x])*(b*Cos[c + d*x])^(5/2), x, 3, (b^2*B*x*Sqrt[b*Cos[c + d*x]])/Sqrt[Cos[c + d*x]] + (A*b^2*ArcTanh[Sin[c + d*x]]*Sqrt[b*Cos[c + d*x]])/(d*Sqrt[Cos[c + d*x]])}
{Cos[c + d*x]^(-9/2)*(A + B*Cos[c + d*x])*(b*Cos[c + d*x])^(5/2), x, 4, (b^2*B*ArcTanh[Sin[c + d*x]]*Sqrt[b*Cos[c + d*x]])/(d*Sqrt[Cos[c + d*x]]) + (A*b^2*Sqrt[b*Cos[c + d*x]]*Sin[c + d*x])/(d*Cos[c + d*x]^(3/2))}
{Cos[c + d*x]^(-11/2)*(A + B*Cos[c + d*x])*(b*Cos[c + d*x])^(5/2), x, 5, (A*b^2*ArcTanh[Sin[c + d*x]]*Sqrt[b*Cos[c + d*x]])/(2*d*Sqrt[Cos[c + d*x]]) + (A*b^2*Sqrt[b*Cos[c + d*x]]*Sin[c + d*x])/(2*d*Cos[c + d*x]^(5/2)) + (b^2*B*Sqrt[b*Cos[c + d*x]]*Sin[c + d*x])/(d*Cos[c + d*x]^(3/2))}
{Cos[c + d*x]^(-13/2)*(A + B*Cos[c + d*x])*(b*Cos[c + d*x])^(5/2), x, 6, (b^2*B*ArcTanh[Sin[c + d*x]]*Sqrt[b*Cos[c + d*x]])/(2*d*Sqrt[Cos[c + d*x]]) + (b^2*B*Sqrt[b*Cos[c + d*x]]*Sin[c + d*x])/(2*d*Cos[c + d*x]^(5/2)) + (A*b^2*Sqrt[b*Cos[c + d*x]]*Sin[c + d*x])/(d*Cos[c + d*x]^(3/2)) + (A*b^2*Sqrt[b*Cos[c + d*x]]*Sin[c + d*x]^3)/(3*d*Cos[c + d*x]^(7/2))}


(* ::Subsubsection::Closed:: *)
(*n<0*)


{Cos[c + d*x]^(5/2)*(A + B*Cos[c + d*x])/(b*Cos[c + d*x])^(1/2), x, 5, (A*x*Sqrt[Cos[c + d*x]])/(2*Sqrt[b*Cos[c + d*x]]) + (B*Sqrt[Cos[c + d*x]]*Sin[c + d*x])/(d*Sqrt[b*Cos[c + d*x]]) + (A*Cos[c + d*x]^(3/2)*Sin[c + d*x])/(2*d*Sqrt[b*Cos[c + d*x]]) - (B*Sqrt[Cos[c + d*x]]*Sin[c + d*x]^3)/(3*d*Sqrt[b*Cos[c + d*x]])}
{Cos[c + d*x]^(3/2)*(A + B*Cos[c + d*x])/(b*Cos[c + d*x])^(1/2), x, 4, (B*x*Sqrt[Cos[c + d*x]])/(2*Sqrt[b*Cos[c + d*x]]) + (A*Sqrt[Cos[c + d*x]]*Sin[c + d*x])/(d*Sqrt[b*Cos[c + d*x]]) + (B*Cos[c + d*x]^(3/2)*Sin[c + d*x])/(2*d*Sqrt[b*Cos[c + d*x]])}
{Cos[c + d*x]^(1/2)*(A + B*Cos[c + d*x])/(b*Cos[c + d*x])^(1/2), x, 3, (A*x*Sqrt[Cos[c + d*x]])/Sqrt[b*Cos[c + d*x]] + (B*Sqrt[Cos[c + d*x]]*Sin[c + d*x])/(d*Sqrt[b*Cos[c + d*x]])}
{Cos[c + d*x]^(-1/2)*(A + B*Cos[c + d*x])/(b*Cos[c + d*x])^(1/2), x, 3, (B*x*Sqrt[Cos[c + d*x]])/Sqrt[b*Cos[c + d*x]] + (A*ArcTanh[Sin[c + d*x]]*Sqrt[Cos[c + d*x]])/(d*Sqrt[b*Cos[c + d*x]])}
{Cos[c + d*x]^(-3/2)*(A + B*Cos[c + d*x])/(b*Cos[c + d*x])^(1/2), x, 4, (B*ArcTanh[Sin[c + d*x]]*Sqrt[Cos[c + d*x]])/(d*Sqrt[b*Cos[c + d*x]]) + (A*Sin[c + d*x])/(d*Sqrt[Cos[c + d*x]]*Sqrt[b*Cos[c + d*x]])}
{Cos[c + d*x]^(-5/2)*(A + B*Cos[c + d*x])/(b*Cos[c + d*x])^(1/2), x, 5, (A*ArcTanh[Sin[c + d*x]]*Sqrt[Cos[c + d*x]])/(2*d*Sqrt[b*Cos[c + d*x]]) + (A*Sin[c + d*x])/(2*d*Cos[c + d*x]^(3/2)*Sqrt[b*Cos[c + d*x]]) + (B*Sin[c + d*x])/(d*Sqrt[Cos[c + d*x]]*Sqrt[b*Cos[c + d*x]])}
{Cos[c + d*x]^(-7/2)*(A + B*Cos[c + d*x])/(b*Cos[c + d*x])^(1/2), x, 6, (B*ArcTanh[Sin[c + d*x]]*Sqrt[Cos[c + d*x]])/(2*d*Sqrt[b*Cos[c + d*x]]) + (B*Sin[c + d*x])/(2*d*Cos[c + d*x]^(3/2)*Sqrt[b*Cos[c + d*x]]) + (A*Sin[c + d*x])/(d*Sqrt[Cos[c + d*x]]*Sqrt[b*Cos[c + d*x]]) + (A*Sin[c + d*x]^3)/(3*d*Cos[c + d*x]^(5/2)*Sqrt[b*Cos[c + d*x]])}


{Cos[c + d*x]^(7/2)*(A + B*Cos[c + d*x])/(b*Cos[c + d*x])^(3/2), x, 5, (A*x*Sqrt[Cos[c + d*x]])/(2*b*Sqrt[b*Cos[c + d*x]]) + (B*Sqrt[Cos[c + d*x]]*Sin[c + d*x])/(b*d*Sqrt[b*Cos[c + d*x]]) + (A*Cos[c + d*x]^(3/2)*Sin[c + d*x])/(2*b*d*Sqrt[b*Cos[c + d*x]]) - (B*Sqrt[Cos[c + d*x]]*Sin[c + d*x]^3)/(3*b*d*Sqrt[b*Cos[c + d*x]])}
{Cos[c + d*x]^(5/2)*(A + B*Cos[c + d*x])/(b*Cos[c + d*x])^(3/2), x, 4, (B*x*Sqrt[Cos[c + d*x]])/(2*b*Sqrt[b*Cos[c + d*x]]) + (A*Sqrt[Cos[c + d*x]]*Sin[c + d*x])/(b*d*Sqrt[b*Cos[c + d*x]]) + (B*Cos[c + d*x]^(3/2)*Sin[c + d*x])/(2*b*d*Sqrt[b*Cos[c + d*x]])}
{Cos[c + d*x]^(3/2)*(A + B*Cos[c + d*x])/(b*Cos[c + d*x])^(3/2), x, 3, (A*x*Sqrt[Cos[c + d*x]])/(b*Sqrt[b*Cos[c + d*x]]) + (B*Sqrt[Cos[c + d*x]]*Sin[c + d*x])/(b*d*Sqrt[b*Cos[c + d*x]])}
{Cos[c + d*x]^(1/2)*(A + B*Cos[c + d*x])/(b*Cos[c + d*x])^(3/2), x, 3, (B*x*Sqrt[Cos[c + d*x]])/(b*Sqrt[b*Cos[c + d*x]]) + (A*ArcTanh[Sin[c + d*x]]*Sqrt[Cos[c + d*x]])/(b*d*Sqrt[b*Cos[c + d*x]])}
{Cos[c + d*x]^(-1/2)*(A + B*Cos[c + d*x])/(b*Cos[c + d*x])^(3/2), x, 4, (B*ArcTanh[Sin[c + d*x]]*Sqrt[Cos[c + d*x]])/(b*d*Sqrt[b*Cos[c + d*x]]) + (A*Sin[c + d*x])/(b*d*Sqrt[Cos[c + d*x]]*Sqrt[b*Cos[c + d*x]])}
{Cos[c + d*x]^(-3/2)*(A + B*Cos[c + d*x])/(b*Cos[c + d*x])^(3/2), x, 5, (A*ArcTanh[Sin[c + d*x]]*Sqrt[Cos[c + d*x]])/(2*b*d*Sqrt[b*Cos[c + d*x]]) + (A*Sin[c + d*x])/(2*b*d*Cos[c + d*x]^(3/2)*Sqrt[b*Cos[c + d*x]]) + (B*Sin[c + d*x])/(b*d*Sqrt[Cos[c + d*x]]*Sqrt[b*Cos[c + d*x]])}
{Cos[c + d*x]^(-5/2)*(A + B*Cos[c + d*x])/(b*Cos[c + d*x])^(3/2), x, 6, (B*ArcTanh[Sin[c + d*x]]*Sqrt[Cos[c + d*x]])/(2*b*d*Sqrt[b*Cos[c + d*x]]) + (B*Sin[c + d*x])/(2*b*d*Cos[c + d*x]^(3/2)*Sqrt[b*Cos[c + d*x]]) + (A*Sin[c + d*x])/(b*d*Sqrt[Cos[c + d*x]]*Sqrt[b*Cos[c + d*x]]) + (A*Sin[c + d*x]^3)/(3*b*d*Cos[c + d*x]^(5/2)*Sqrt[b*Cos[c + d*x]])}


{Cos[c + d*x]^(9/2)*(A + B*Cos[c + d*x])/(b*Cos[c + d*x])^(5/2), x, 5, (A*x*Sqrt[Cos[c + d*x]])/(2*b^2*Sqrt[b*Cos[c + d*x]]) + (B*Sqrt[Cos[c + d*x]]*Sin[c + d*x])/(b^2*d*Sqrt[b*Cos[c + d*x]]) + (A*Cos[c + d*x]^(3/2)*Sin[c + d*x])/(2*b^2*d*Sqrt[b*Cos[c + d*x]]) - (B*Sqrt[Cos[c + d*x]]*Sin[c + d*x]^3)/(3*b^2*d*Sqrt[b*Cos[c + d*x]])}
{Cos[c + d*x]^(7/2)*(A + B*Cos[c + d*x])/(b*Cos[c + d*x])^(5/2), x, 4, (B*x*Sqrt[Cos[c + d*x]])/(2*b^2*Sqrt[b*Cos[c + d*x]]) + (A*Sqrt[Cos[c + d*x]]*Sin[c + d*x])/(b^2*d*Sqrt[b*Cos[c + d*x]]) + (B*Cos[c + d*x]^(3/2)*Sin[c + d*x])/(2*b^2*d*Sqrt[b*Cos[c + d*x]])}
{Cos[c + d*x]^(5/2)*(A + B*Cos[c + d*x])/(b*Cos[c + d*x])^(5/2), x, 3, (A*x*Sqrt[Cos[c + d*x]])/(b^2*Sqrt[b*Cos[c + d*x]]) + (B*Sqrt[Cos[c + d*x]]*Sin[c + d*x])/(b^2*d*Sqrt[b*Cos[c + d*x]])}
{Cos[c + d*x]^(3/2)*(A + B*Cos[c + d*x])/(b*Cos[c + d*x])^(5/2), x, 3, (B*x*Sqrt[Cos[c + d*x]])/(b^2*Sqrt[b*Cos[c + d*x]]) + (A*ArcTanh[Sin[c + d*x]]*Sqrt[Cos[c + d*x]])/(b^2*d*Sqrt[b*Cos[c + d*x]])}
{Cos[c + d*x]^(1/2)*(A + B*Cos[c + d*x])/(b*Cos[c + d*x])^(5/2), x, 4, (B*ArcTanh[Sin[c + d*x]]*Sqrt[Cos[c + d*x]])/(b^2*d*Sqrt[b*Cos[c + d*x]]) + (A*Sin[c + d*x])/(b^2*d*Sqrt[Cos[c + d*x]]*Sqrt[b*Cos[c + d*x]])}
{Cos[c + d*x]^(-1/2)*(A + B*Cos[c + d*x])/(b*Cos[c + d*x])^(5/2), x, 5, (A*ArcTanh[Sin[c + d*x]]*Sqrt[Cos[c + d*x]])/(2*b^2*d*Sqrt[b*Cos[c + d*x]]) + (A*Sin[c + d*x])/(2*b^2*d*Cos[c + d*x]^(3/2)*Sqrt[b*Cos[c + d*x]]) + (B*Sin[c + d*x])/(b^2*d*Sqrt[Cos[c + d*x]]*Sqrt[b*Cos[c + d*x]])}
{Cos[c + d*x]^(-3/2)*(A + B*Cos[c + d*x])/(b*Cos[c + d*x])^(5/2), x, 6, (B*ArcTanh[Sin[c + d*x]]*Sqrt[Cos[c + d*x]])/(2*b^2*d*Sqrt[b*Cos[c + d*x]]) + (B*Sin[c + d*x])/(2*b^2*d*Cos[c + d*x]^(3/2)*Sqrt[b*Cos[c + d*x]]) + (A*Sin[c + d*x])/(b^2*d*Sqrt[Cos[c + d*x]]*Sqrt[b*Cos[c + d*x]]) + (A*Sin[c + d*x]^3)/(3*b^2*d*Cos[c + d*x]^(5/2)*Sqrt[b*Cos[c + d*x]])}


(* ::Subsection::Closed:: *)
(*Integrands of the form Cos[c+d x]^m (A+B Cos[c+d x]) (b Cos[c+d x])^(n/3)*)


(* ::Subsubsection::Closed:: *)
(*n>0*)


{Cos[c + d*x]^m*(b*Cos[c + d*x])^(1/3)*(A + B*Cos[c + d*x]), x, 4, (B*Cos[c + d*x]^(2 + m)*(b*Cos[c + d*x])^(1/3)*(Cos[c + d*x]^2)^((-7 - 3*m)/6)*Hypergeometric2F1[1/2, (-1 - 3*m)/6, 3/2, Sin[c + d*x]^2]*Sin[c + d*x])/d + (A*Cos[c + d*x]^(1 + m)*(b*Cos[c + d*x])^(1/3)*(Cos[c + d*x]^2)^((-4 - 3*m)/6)*Hypergeometric2F1[1/2, (2 - 3*m)/6, 3/2, Sin[c + d*x]^2]*Sin[c + d*x])/d}

{Cos[c + d*x]^2*(b*Cos[c + d*x])^(1/3)*(A + B*Cos[c + d*x]), x, 9, (21*B*(b*Cos[c + d*x])^(1/3)*Sin[c + d*x])/(40*d) + (3*A*(b*Cos[c + d*x])^(4/3)*Sin[c + d*x])/(7*b*d) + (3*B*(b*Cos[c + d*x])^(7/3)*Sin[c + d*x])/(10*b^2*d) + (4*A*b*(Cos[c + d*x]^2)^(1/3)*Hypergeometric2F1[1/3, 1/2, 3/2, Sin[c + d*x]^2]*Sin[c + d*x])/(7*d*(b*Cos[c + d*x])^(2/3)) + (7*B*(b*Cos[c + d*x])^(1/3)*Hypergeometric2F1[1/2, 5/6, 3/2, Sin[c + d*x]^2]*Sin[c + d*x])/(40*d*(Cos[c + d*x]^2)^(1/6))}
{Cos[c + d*x]*(b*Cos[c + d*x])^(1/3)*(A + B*Cos[c + d*x]), x, 8, (3*A*(b*Cos[c + d*x])^(1/3)*Sin[c + d*x])/(4*d) + (3*B*(b*Cos[c + d*x])^(4/3)*Sin[c + d*x])/(7*b*d) + (4*b*B*(Cos[c + d*x]^2)^(1/3)*Hypergeometric2F1[1/3, 1/2, 3/2, Sin[c + d*x]^2]*Sin[c + d*x])/(7*d*(b*Cos[c + d*x])^(2/3)) + (A*(b*Cos[c + d*x])^(1/3)*Hypergeometric2F1[1/2, 5/6, 3/2, Sin[c + d*x]^2]*Sin[c + d*x])/(4*d*(Cos[c + d*x]^2)^(1/6))}
{(b*Cos[c + d*x])^(1/3)*(A + B*Cos[c + d*x]), x, 6, (3*B*(b*Cos[c + d*x])^(1/3)*Sin[c + d*x])/(4*d) + (A*b*(Cos[c + d*x]^2)^(1/3)*Hypergeometric2F1[1/3, 1/2, 3/2, Sin[c + d*x]^2]*Sin[c + d*x])/(d*(b*Cos[c + d*x])^(2/3)) + (B*(b*Cos[c + d*x])^(1/3)*Hypergeometric2F1[1/2, 5/6, 3/2, Sin[c + d*x]^2]*Sin[c + d*x])/(4*d*(Cos[c + d*x]^2)^(1/6))}
{(b*Cos[c + d*x])^(1/3)*(A + B*Cos[c + d*x])*Sec[c + d*x], x, 6, (b*B*(Cos[c + d*x]^2)^(1/3)*Hypergeometric2F1[1/3, 1/2, 3/2, Sin[c + d*x]^2]*Sin[c + d*x])/(d*(b*Cos[c + d*x])^(2/3)) + (A*(b*Cos[c + d*x])^(1/3)*Hypergeometric2F1[1/2, 5/6, 3/2, Sin[c + d*x]^2]*Sin[c + d*x])/(d*(Cos[c + d*x]^2)^(1/6))}
{(b*Cos[c + d*x])^(1/3)*(A + B*Cos[c + d*x])*Sec[c + d*x]^2, x, 7, (3*A*b*Sin[c + d*x])/(2*d*(b*Cos[c + d*x])^(2/3)) - (A*b*(Cos[c + d*x]^2)^(1/3)*Hypergeometric2F1[1/3, 1/2, 3/2, Sin[c + d*x]^2]*Sin[c + d*x])/(2*d*(b*Cos[c + d*x])^(2/3)) + (B*(b*Cos[c + d*x])^(1/3)*Hypergeometric2F1[1/2, 5/6, 3/2, Sin[c + d*x]^2]*Sin[c + d*x])/(d*(Cos[c + d*x]^2)^(1/6))}
{(b*Cos[c + d*x])^(1/3)*(A + B*Cos[c + d*x])*Sec[c + d*x]^3, x, 8, (3*A*b^2*Sin[c + d*x])/(5*d*(b*Cos[c + d*x])^(5/3)) + (3*b*B*Sin[c + d*x])/(2*d*(b*Cos[c + d*x])^(2/3)) - (b*B*(Cos[c + d*x]^2)^(1/3)*Hypergeometric2F1[1/3, 1/2, 3/2, Sin[c + d*x]^2]*Sin[c + d*x])/(2*d*(b*Cos[c + d*x])^(2/3)) + (2*A*(b*Cos[c + d*x])^(1/3)*Hypergeometric2F1[1/2, 5/6, 3/2, Sin[c + d*x]^2]*Sin[c + d*x])/(5*d*(Cos[c + d*x]^2)^(1/6))}


{Cos[c + d*x]^m*(b*Cos[c + d*x])^(2/3)*(A + B*Cos[c + d*x]), x, 4, (B*Cos[c + d*x]^(2 + m)*(b*Cos[c + d*x])^(2/3)*(Cos[c + d*x]^2)^((-8 - 3*m)/6)*Hypergeometric2F1[1/2, (-2 - 3*m)/6, 3/2, Sin[c + d*x]^2]*Sin[c + d*x])/d + (A*Cos[c + d*x]^(1 + m)*(b*Cos[c + d*x])^(2/3)*(Cos[c + d*x]^2)^((-5 - 3*m)/6)*Hypergeometric2F1[1/2, (1 - 3*m)/6, 3/2, Sin[c + d*x]^2]*Sin[c + d*x])/d}

{Cos[c + d*x]^2*(b*Cos[c + d*x])^(2/3)*(A + B*Cos[c + d*x]), x, 9, (24*B*(b*Cos[c + d*x])^(2/3)*Sin[c + d*x])/(55*d) + (3*A*(b*Cos[c + d*x])^(5/3)*Sin[c + d*x])/(8*b*d) + (3*B*(b*Cos[c + d*x])^(8/3)*Sin[c + d*x])/(11*b^2*d) + (5*A*b*(Cos[c + d*x]^2)^(1/6)*Hypergeometric2F1[1/6, 1/2, 3/2, Sin[c + d*x]^2]*Sin[c + d*x])/(8*d*(b*Cos[c + d*x])^(1/3)) + (16*B*(b*Cos[c + d*x])^(2/3)*Hypergeometric2F1[1/2, 2/3, 3/2, Sin[c + d*x]^2]*Sin[c + d*x])/(55*d*(Cos[c + d*x]^2)^(1/3))}
{Cos[c + d*x]*(b*Cos[c + d*x])^(2/3)*(A + B*Cos[c + d*x]), x, 8, (3*A*(b*Cos[c + d*x])^(2/3)*Sin[c + d*x])/(5*d) + (3*B*(b*Cos[c + d*x])^(5/3)*Sin[c + d*x])/(8*b*d) + (5*b*B*(Cos[c + d*x]^2)^(1/6)*Hypergeometric2F1[1/6, 1/2, 3/2, Sin[c + d*x]^2]*Sin[c + d*x])/(8*d*(b*Cos[c + d*x])^(1/3)) + (2*A*(b*Cos[c + d*x])^(2/3)*Hypergeometric2F1[1/2, 2/3, 3/2, Sin[c + d*x]^2]*Sin[c + d*x])/(5*d*(Cos[c + d*x]^2)^(1/3))}
{(b*Cos[c + d*x])^(2/3)*(A + B*Cos[c + d*x]), x, 6, (3*B*(b*Cos[c + d*x])^(2/3)*Sin[c + d*x])/(5*d) + (A*b*(Cos[c + d*x]^2)^(1/6)*Hypergeometric2F1[1/6, 1/2, 3/2, Sin[c + d*x]^2]*Sin[c + d*x])/(d*(b*Cos[c + d*x])^(1/3)) + (2*B*(b*Cos[c + d*x])^(2/3)*Hypergeometric2F1[1/2, 2/3, 3/2, Sin[c + d*x]^2]*Sin[c + d*x])/(5*d*(Cos[c + d*x]^2)^(1/3))}
{(b*Cos[c + d*x])^(2/3)*(A + B*Cos[c + d*x])*Sec[c + d*x], x, 6, (b*B*(Cos[c + d*x]^2)^(1/6)*Hypergeometric2F1[1/6, 1/2, 3/2, Sin[c + d*x]^2]*Sin[c + d*x])/(d*(b*Cos[c + d*x])^(1/3)) + (A*(b*Cos[c + d*x])^(2/3)*Hypergeometric2F1[1/2, 2/3, 3/2, Sin[c + d*x]^2]*Sin[c + d*x])/(d*(Cos[c + d*x]^2)^(1/3))}
{(b*Cos[c + d*x])^(2/3)*(A + B*Cos[c + d*x])*Sec[c + d*x]^2, x, 7, (3*A*b*Sin[c + d*x])/(d*(b*Cos[c + d*x])^(1/3)) - (2*A*b*(Cos[c + d*x]^2)^(1/6)*Hypergeometric2F1[1/6, 1/2, 3/2, Sin[c + d*x]^2]*Sin[c + d*x])/(d*(b*Cos[c + d*x])^(1/3)) + (B*(b*Cos[c + d*x])^(2/3)*Hypergeometric2F1[1/2, 2/3, 3/2, Sin[c + d*x]^2]*Sin[c + d*x])/(d*(Cos[c + d*x]^2)^(1/3))}
{(b*Cos[c + d*x])^(2/3)*(A + B*Cos[c + d*x])*Sec[c + d*x]^3, x, 8, (3*A*b^2*Sin[c + d*x])/(4*d*(b*Cos[c + d*x])^(4/3)) + (3*b*B*Sin[c + d*x])/(d*(b*Cos[c + d*x])^(1/3)) - (2*b*B*(Cos[c + d*x]^2)^(1/6)*Hypergeometric2F1[1/6, 1/2, 3/2, Sin[c + d*x]^2]*Sin[c + d*x])/(d*(b*Cos[c + d*x])^(1/3)) + (A*(b*Cos[c + d*x])^(2/3)*Hypergeometric2F1[1/2, 2/3, 3/2, Sin[c + d*x]^2]*Sin[c + d*x])/(4*d*(Cos[c + d*x]^2)^(1/3))}


{Cos[c + d*x]^m*(b*Cos[c + d*x])^(4/3)*(A + B*Cos[c + d*x]), x, 4, (B*Cos[c + d*x]^(2 + m)*(b*Cos[c + d*x])^(4/3)*(Cos[c + d*x]^2)^((-10 - 3*m)/6)*Hypergeometric2F1[1/2, (-4 - 3*m)/6, 3/2, Sin[c + d*x]^2]*Sin[c + d*x])/d + (A*Cos[c + d*x]^(1 + m)*(b*Cos[c + d*x])^(4/3)*(Cos[c + d*x]^2)^((-7 - 3*m)/6)*Hypergeometric2F1[1/2, (-1 - 3*m)/6, 3/2, Sin[c + d*x]^2]*Sin[c + d*x])/d}

{Cos[c + d*x]^2*(b*Cos[c + d*x])^(4/3)*(A + B*Cos[c + d*x]), x, 10, (21*A*b*(b*Cos[c + d*x])^(1/3)*Sin[c + d*x])/(40*d) + (30*B*(b*Cos[c + d*x])^(4/3)*Sin[c + d*x])/(91*d) + (3*A*(b*Cos[c + d*x])^(7/3)*Sin[c + d*x])/(10*b*d) + (3*B*(b*Cos[c + d*x])^(10/3)*Sin[c + d*x])/(13*b^2*d) + (40*b^2*B*(Cos[c + d*x]^2)^(1/3)*Hypergeometric2F1[1/3, 1/2, 3/2, Sin[c + d*x]^2]*Sin[c + d*x])/(91*d*(b*Cos[c + d*x])^(2/3)) + (7*A*b*(b*Cos[c + d*x])^(1/3)*Hypergeometric2F1[1/2, 5/6, 3/2, Sin[c + d*x]^2]*Sin[c + d*x])/(40*d*(Cos[c + d*x]^2)^(1/6))}
{Cos[c + d*x]*(b*Cos[c + d*x])^(4/3)*(A + B*Cos[c + d*x]), x, 9, (21*b*B*(b*Cos[c + d*x])^(1/3)*Sin[c + d*x])/(40*d) + (3*A*(b*Cos[c + d*x])^(4/3)*Sin[c + d*x])/(7*d) + (3*B*(b*Cos[c + d*x])^(7/3)*Sin[c + d*x])/(10*b*d) + (4*A*b^2*(Cos[c + d*x]^2)^(1/3)*Hypergeometric2F1[1/3, 1/2, 3/2, Sin[c + d*x]^2]*Sin[c + d*x])/(7*d*(b*Cos[c + d*x])^(2/3)) + (7*b*B*(b*Cos[c + d*x])^(1/3)*Hypergeometric2F1[1/2, 5/6, 3/2, Sin[c + d*x]^2]*Sin[c + d*x])/(40*d*(Cos[c + d*x]^2)^(1/6))}
{(b*Cos[c + d*x])^(4/3)*(A + B*Cos[c + d*x]), x, 7, (3*A*b*(b*Cos[c + d*x])^(1/3)*Sin[c + d*x])/(4*d) + (3*B*(b*Cos[c + d*x])^(4/3)*Sin[c + d*x])/(7*d) + (4*b^2*B*(Cos[c + d*x]^2)^(1/3)*Hypergeometric2F1[1/3, 1/2, 3/2, Sin[c + d*x]^2]*Sin[c + d*x])/(7*d*(b*Cos[c + d*x])^(2/3)) + (A*b*(b*Cos[c + d*x])^(1/3)*Hypergeometric2F1[1/2, 5/6, 3/2, Sin[c + d*x]^2]*Sin[c + d*x])/(4*d*(Cos[c + d*x]^2)^(1/6))}
{(b*Cos[c + d*x])^(4/3)*(A + B*Cos[c + d*x])*Sec[c + d*x], x, 7, (3*b*B*(b*Cos[c + d*x])^(1/3)*Sin[c + d*x])/(4*d) + (A*b^2*(Cos[c + d*x]^2)^(1/3)*Hypergeometric2F1[1/3, 1/2, 3/2, Sin[c + d*x]^2]*Sin[c + d*x])/(d*(b*Cos[c + d*x])^(2/3)) + (b*B*(b*Cos[c + d*x])^(1/3)*Hypergeometric2F1[1/2, 5/6, 3/2, Sin[c + d*x]^2]*Sin[c + d*x])/(4*d*(Cos[c + d*x]^2)^(1/6))}
{(b*Cos[c + d*x])^(4/3)*(A + B*Cos[c + d*x])*Sec[c + d*x]^2, x, 6, (b^2*B*(Cos[c + d*x]^2)^(1/3)*Hypergeometric2F1[1/3, 1/2, 3/2, Sin[c + d*x]^2]*Sin[c + d*x])/(d*(b*Cos[c + d*x])^(2/3)) + (A*b*(b*Cos[c + d*x])^(1/3)*Hypergeometric2F1[1/2, 5/6, 3/2, Sin[c + d*x]^2]*Sin[c + d*x])/(d*(Cos[c + d*x]^2)^(1/6))}
{(b*Cos[c + d*x])^(4/3)*(A + B*Cos[c + d*x])*Sec[c + d*x]^3, x, 7, (3*A*b^2*Sin[c + d*x])/(2*d*(b*Cos[c + d*x])^(2/3)) - (A*b^2*(Cos[c + d*x]^2)^(1/3)*Hypergeometric2F1[1/3, 1/2, 3/2, Sin[c + d*x]^2]*Sin[c + d*x])/(2*d*(b*Cos[c + d*x])^(2/3)) + (b*B*(b*Cos[c + d*x])^(1/3)*Hypergeometric2F1[1/2, 5/6, 3/2, Sin[c + d*x]^2]*Sin[c + d*x])/(d*(Cos[c + d*x]^2)^(1/6))}


(* ::Subsubsection::Closed:: *)
(*n<0*)


{(Cos[c + d*x]^m*(A + B*Cos[c + d*x]))/(b*Cos[c + d*x])^(1/3), x, 4, (B*Cos[c + d*x]^(2 + m)*(Cos[c + d*x]^2)^((-5 - 3*m)/6)*Hypergeometric2F1[1/2, (1 - 3*m)/6, 3/2, Sin[c + d*x]^2]*Sin[c + d*x])/(d*(b*Cos[c + d*x])^(1/3)) + (A*Cos[c + d*x]^(1 + m)*(Cos[c + d*x]^2)^((-2 - 3*m)/6)*Hypergeometric2F1[1/2, (4 - 3*m)/6, 3/2, Sin[c + d*x]^2]*Sin[c + d*x])/(d*(b*Cos[c + d*x])^(1/3))}

{(Cos[c + d*x]^2*(A + B*Cos[c + d*x]))/(b*Cos[c + d*x])^(1/3), x, 8, (3*A*(b*Cos[c + d*x])^(2/3)*Sin[c + d*x])/(5*b*d) + (3*B*(b*Cos[c + d*x])^(5/3)*Sin[c + d*x])/(8*b^2*d) + (5*B*(Cos[c + d*x]^2)^(1/6)*Hypergeometric2F1[1/6, 1/2, 3/2, Sin[c + d*x]^2]*Sin[c + d*x])/(8*d*(b*Cos[c + d*x])^(1/3)) + (2*A*(b*Cos[c + d*x])^(2/3)*Hypergeometric2F1[1/2, 2/3, 3/2, Sin[c + d*x]^2]*Sin[c + d*x])/(5*b*d*(Cos[c + d*x]^2)^(1/3))}
{(Cos[c + d*x]*(A + B*Cos[c + d*x]))/(b*Cos[c + d*x])^(1/3), x, 7, (3*B*(b*Cos[c + d*x])^(2/3)*Sin[c + d*x])/(5*b*d) + (A*(Cos[c + d*x]^2)^(1/6)*Hypergeometric2F1[1/6, 1/2, 3/2, Sin[c + d*x]^2]*Sin[c + d*x])/(d*(b*Cos[c + d*x])^(1/3)) + (2*B*(b*Cos[c + d*x])^(2/3)*Hypergeometric2F1[1/2, 2/3, 3/2, Sin[c + d*x]^2]*Sin[c + d*x])/(5*b*d*(Cos[c + d*x]^2)^(1/3))}
{(A + B*Cos[c + d*x])/(b*Cos[c + d*x])^(1/3), x, 5, (B*(Cos[c + d*x]^2)^(1/6)*Hypergeometric2F1[1/6, 1/2, 3/2, Sin[c + d*x]^2]*Sin[c + d*x])/(d*(b*Cos[c + d*x])^(1/3)) + (A*(b*Cos[c + d*x])^(2/3)*Hypergeometric2F1[1/2, 2/3, 3/2, Sin[c + d*x]^2]*Sin[c + d*x])/(b*d*(Cos[c + d*x]^2)^(1/3))}
{((A + B*Cos[c + d*x])*Sec[c + d*x])/(b*Cos[c + d*x])^(1/3), x, 7, (3*A*Sin[c + d*x])/(d*(b*Cos[c + d*x])^(1/3)) - (2*A*(Cos[c + d*x]^2)^(1/6)*Hypergeometric2F1[1/6, 1/2, 3/2, Sin[c + d*x]^2]*Sin[c + d*x])/(d*(b*Cos[c + d*x])^(1/3)) + (B*(b*Cos[c + d*x])^(2/3)*Hypergeometric2F1[1/2, 2/3, 3/2, Sin[c + d*x]^2]*Sin[c + d*x])/(b*d*(Cos[c + d*x]^2)^(1/3))}
{((A + B*Cos[c + d*x])*Sec[c + d*x]^2)/(b*Cos[c + d*x])^(1/3), x, 8, (3*A*b*Sin[c + d*x])/(4*d*(b*Cos[c + d*x])^(4/3)) + (3*B*Sin[c + d*x])/(d*(b*Cos[c + d*x])^(1/3)) - (2*B*(Cos[c + d*x]^2)^(1/6)*Hypergeometric2F1[1/6, 1/2, 3/2, Sin[c + d*x]^2]*Sin[c + d*x])/(d*(b*Cos[c + d*x])^(1/3)) + (A*(b*Cos[c + d*x])^(2/3)*Hypergeometric2F1[1/2, 2/3, 3/2, Sin[c + d*x]^2]*Sin[c + d*x])/(4*b*d*(Cos[c + d*x]^2)^(1/3))}
{((A + B*Cos[c + d*x])*Sec[c + d*x]^3)/(b*Cos[c + d*x])^(1/3), x, 9, (3*A*b^2*Sin[c + d*x])/(7*d*(b*Cos[c + d*x])^(7/3)) + (3*b*B*Sin[c + d*x])/(4*d*(b*Cos[c + d*x])^(4/3)) + (12*A*Sin[c + d*x])/(7*d*(b*Cos[c + d*x])^(1/3)) - (8*A*(Cos[c + d*x]^2)^(1/6)*Hypergeometric2F1[1/6, 1/2, 3/2, Sin[c + d*x]^2]*Sin[c + d*x])/(7*d*(b*Cos[c + d*x])^(1/3)) + (B*(b*Cos[c + d*x])^(2/3)*Hypergeometric2F1[1/2, 2/3, 3/2, Sin[c + d*x]^2]*Sin[c + d*x])/(4*b*d*(Cos[c + d*x]^2)^(1/3))}


{(Cos[c + d*x]^m*(A + B*Cos[c + d*x]))/(b*Cos[c + d*x])^(2/3), x, 4, (B*Cos[c + d*x]^(2 + m)*(Cos[c + d*x]^2)^((-4 - 3*m)/6)*Hypergeometric2F1[1/2, (2 - 3*m)/6, 3/2, Sin[c + d*x]^2]*Sin[c + d*x])/(d*(b*Cos[c + d*x])^(2/3)) + (A*Cos[c + d*x]^(1 + m)*(Cos[c + d*x]^2)^((-1 - 3*m)/6)*Hypergeometric2F1[1/2, (5 - 3*m)/6, 3/2, Sin[c + d*x]^2]*Sin[c + d*x])/(d*(b*Cos[c + d*x])^(2/3))}

{(Cos[c + d*x]^2*(A + B*Cos[c + d*x]))/(b*Cos[c + d*x])^(2/3), x, 8, (3*A*(b*Cos[c + d*x])^(1/3)*Sin[c + d*x])/(4*b*d) + (3*B*(b*Cos[c + d*x])^(4/3)*Sin[c + d*x])/(7*b^2*d) + (4*B*(Cos[c + d*x]^2)^(1/3)*Hypergeometric2F1[1/3, 1/2, 3/2, Sin[c + d*x]^2]*Sin[c + d*x])/(7*d*(b*Cos[c + d*x])^(2/3)) + (A*(b*Cos[c + d*x])^(1/3)*Hypergeometric2F1[1/2, 5/6, 3/2, Sin[c + d*x]^2]*Sin[c + d*x])/(4*b*d*(Cos[c + d*x]^2)^(1/6))}
{(Cos[c + d*x]*(A + B*Cos[c + d*x]))/(b*Cos[c + d*x])^(2/3), x, 7, (3*B*(b*Cos[c + d*x])^(1/3)*Sin[c + d*x])/(4*b*d) + (A*(Cos[c + d*x]^2)^(1/3)*Hypergeometric2F1[1/3, 1/2, 3/2, Sin[c + d*x]^2]*Sin[c + d*x])/(d*(b*Cos[c + d*x])^(2/3)) + (B*(b*Cos[c + d*x])^(1/3)*Hypergeometric2F1[1/2, 5/6, 3/2, Sin[c + d*x]^2]*Sin[c + d*x])/(4*b*d*(Cos[c + d*x]^2)^(1/6))}
{(A + B*Cos[c + d*x])/(b*Cos[c + d*x])^(2/3), x, 5, (B*(Cos[c + d*x]^2)^(1/3)*Hypergeometric2F1[1/3, 1/2, 3/2, Sin[c + d*x]^2]*Sin[c + d*x])/(d*(b*Cos[c + d*x])^(2/3)) + (A*(b*Cos[c + d*x])^(1/3)*Hypergeometric2F1[1/2, 5/6, 3/2, Sin[c + d*x]^2]*Sin[c + d*x])/(b*d*(Cos[c + d*x]^2)^(1/6))}
{((A + B*Cos[c + d*x])*Sec[c + d*x])/(b*Cos[c + d*x])^(2/3), x, 7, (3*A*Sin[c + d*x])/(2*d*(b*Cos[c + d*x])^(2/3)) - (A*(Cos[c + d*x]^2)^(1/3)*Hypergeometric2F1[1/3, 1/2, 3/2, Sin[c + d*x]^2]*Sin[c + d*x])/(2*d*(b*Cos[c + d*x])^(2/3)) + (B*(b*Cos[c + d*x])^(1/3)*Hypergeometric2F1[1/2, 5/6, 3/2, Sin[c + d*x]^2]*Sin[c + d*x])/(b*d*(Cos[c + d*x]^2)^(1/6))}
{((A + B*Cos[c + d*x])*Sec[c + d*x]^2)/(b*Cos[c + d*x])^(2/3), x, 8, (3*A*b*Sin[c + d*x])/(5*d*(b*Cos[c + d*x])^(5/3)) + (3*B*Sin[c + d*x])/(2*d*(b*Cos[c + d*x])^(2/3)) - (B*(Cos[c + d*x]^2)^(1/3)*Hypergeometric2F1[1/3, 1/2, 3/2, Sin[c + d*x]^2]*Sin[c + d*x])/(2*d*(b*Cos[c + d*x])^(2/3)) + (2*A*(b*Cos[c + d*x])^(1/3)*Hypergeometric2F1[1/2, 5/6, 3/2, Sin[c + d*x]^2]*Sin[c + d*x])/(5*b*d*(Cos[c + d*x]^2)^(1/6))}
{((A + B*Cos[c + d*x])*Sec[c + d*x]^3)/(b*Cos[c + d*x])^(2/3), x, 9, (3*A*b^2*Sin[c + d*x])/(8*d*(b*Cos[c + d*x])^(8/3)) + (3*b*B*Sin[c + d*x])/(5*d*(b*Cos[c + d*x])^(5/3)) + (15*A*Sin[c + d*x])/(16*d*(b*Cos[c + d*x])^(2/3)) - (5*A*(Cos[c + d*x]^2)^(1/3)*Hypergeometric2F1[1/3, 1/2, 3/2, Sin[c + d*x]^2]*Sin[c + d*x])/(16*d*(b*Cos[c + d*x])^(2/3)) + (2*B*(b*Cos[c + d*x])^(1/3)*Hypergeometric2F1[1/2, 5/6, 3/2, Sin[c + d*x]^2]*Sin[c + d*x])/(5*b*d*(Cos[c + d*x]^2)^(1/6))}


{(Cos[c + d*x]^m*(A + B*Cos[c + d*x]))/(b*Cos[c + d*x])^(4/3), x, 4, (B*Cos[c + d*x]^(2 + m)*(Cos[c + d*x]^2)^((-2 - 3*m)/6)*Hypergeometric2F1[1/2, (4 - 3*m)/6, 3/2, Sin[c + d*x]^2]*Sin[c + d*x])/(d*(b*Cos[c + d*x])^(4/3)) + (A*Cos[c + d*x]^(1 + m)*(Cos[c + d*x]^2)^((1 - 3*m)/6)*Hypergeometric2F1[1/2, (7 - 3*m)/6, 3/2, Sin[c + d*x]^2]*Sin[c + d*x])/(d*(b*Cos[c + d*x])^(4/3))}

{(Cos[c + d*x]^2*(A + B*Cos[c + d*x]))/(b*Cos[c + d*x])^(4/3), x, 7, (3*B*(b*Cos[c + d*x])^(2/3)*Sin[c + d*x])/(5*b^2*d) + (A*(Cos[c + d*x]^2)^(1/6)*Hypergeometric2F1[1/6, 1/2, 3/2, Sin[c + d*x]^2]*Sin[c + d*x])/(b*d*(b*Cos[c + d*x])^(1/3)) + (2*B*(b*Cos[c + d*x])^(2/3)*Hypergeometric2F1[1/2, 2/3, 3/2, Sin[c + d*x]^2]*Sin[c + d*x])/(5*b^2*d*(Cos[c + d*x]^2)^(1/3))}
{(Cos[c + d*x]*(A + B*Cos[c + d*x]))/(b*Cos[c + d*x])^(4/3), x, 6, (B*(Cos[c + d*x]^2)^(1/6)*Hypergeometric2F1[1/6, 1/2, 3/2, Sin[c + d*x]^2]*Sin[c + d*x])/(b*d*(b*Cos[c + d*x])^(1/3)) + (A*(b*Cos[c + d*x])^(2/3)*Hypergeometric2F1[1/2, 2/3, 3/2, Sin[c + d*x]^2]*Sin[c + d*x])/(b^2*d*(Cos[c + d*x]^2)^(1/3))}
{(A + B*Cos[c + d*x])/(b*Cos[c + d*x])^(4/3), x, 6, (3*A*Sin[c + d*x])/(b*d*(b*Cos[c + d*x])^(1/3)) - (2*A*(Cos[c + d*x]^2)^(1/6)*Hypergeometric2F1[1/6, 1/2, 3/2, Sin[c + d*x]^2]*Sin[c + d*x])/(b*d*(b*Cos[c + d*x])^(1/3)) + (B*(b*Cos[c + d*x])^(2/3)*Hypergeometric2F1[1/2, 2/3, 3/2, Sin[c + d*x]^2]*Sin[c + d*x])/(b^2*d*(Cos[c + d*x]^2)^(1/3))}
{((A + B*Cos[c + d*x])*Sec[c + d*x])/(b*Cos[c + d*x])^(4/3), x, 8, (3*A*Sin[c + d*x])/(4*d*(b*Cos[c + d*x])^(4/3)) + (3*B*Sin[c + d*x])/(b*d*(b*Cos[c + d*x])^(1/3)) - (2*B*(Cos[c + d*x]^2)^(1/6)*Hypergeometric2F1[1/6, 1/2, 3/2, Sin[c + d*x]^2]*Sin[c + d*x])/(b*d*(b*Cos[c + d*x])^(1/3)) + (A*(b*Cos[c + d*x])^(2/3)*Hypergeometric2F1[1/2, 2/3, 3/2, Sin[c + d*x]^2]*Sin[c + d*x])/(4*b^2*d*(Cos[c + d*x]^2)^(1/3))}
{((A + B*Cos[c + d*x])*Sec[c + d*x]^2)/(b*Cos[c + d*x])^(4/3), x, 9, (3*A*b*Sin[c + d*x])/(7*d*(b*Cos[c + d*x])^(7/3)) + (3*B*Sin[c + d*x])/(4*d*(b*Cos[c + d*x])^(4/3)) + (12*A*Sin[c + d*x])/(7*b*d*(b*Cos[c + d*x])^(1/3)) - (8*A*(Cos[c + d*x]^2)^(1/6)*Hypergeometric2F1[1/6, 1/2, 3/2, Sin[c + d*x]^2]*Sin[c + d*x])/(7*b*d*(b*Cos[c + d*x])^(1/3)) + (B*(b*Cos[c + d*x])^(2/3)*Hypergeometric2F1[1/2, 2/3, 3/2, Sin[c + d*x]^2]*Sin[c + d*x])/(4*b^2*d*(Cos[c + d*x]^2)^(1/3))}
{((A + B*Cos[c + d*x])*Sec[c + d*x]^3)/(b*Cos[c + d*x])^(4/3), x, 10, (3*A*b^2*Sin[c + d*x])/(10*d*(b*Cos[c + d*x])^(10/3)) + (3*b*B*Sin[c + d*x])/(7*d*(b*Cos[c + d*x])^(7/3)) + (21*A*Sin[c + d*x])/(40*d*(b*Cos[c + d*x])^(4/3)) + (12*B*Sin[c + d*x])/(7*b*d*(b*Cos[c + d*x])^(1/3)) - (8*B*(Cos[c + d*x]^2)^(1/6)*Hypergeometric2F1[1/6, 1/2, 3/2, Sin[c + d*x]^2]*Sin[c + d*x])/(7*b*d*(b*Cos[c + d*x])^(1/3)) + (7*A*(b*Cos[c + d*x])^(2/3)*Hypergeometric2F1[1/2, 2/3, 3/2, Sin[c + d*x]^2]*Sin[c + d*x])/(40*b^2*d*(Cos[c + d*x]^2)^(1/3))}


(* ::Subsection::Closed:: *)
(*Integrands of the form Cos[c+d x]^m (A+B Cos[c+d x]) (b Cos[c+d x])^n when n symbolic*)


{Cos[c + d*x]^m*(A + B*Cos[c + d*x])*(b*Cos[c + d*x])^n, x, 4, (B*Cos[c + d*x]^(2 + m)*(b*Cos[c + d*x])^n*(Cos[c + d*x]^2)^((1/2)*(-2 - m - n))*Hypergeometric2F1[1/2, (1/2)*(-m - n), 3/2, Sin[c + d*x]^2]*Sin[c + d*x])/d + (A*Cos[c + d*x]^(1 + m)*(b*Cos[c + d*x])^n*(Cos[c + d*x]^2)^((1/2)*(-1 - m - n))*Hypergeometric2F1[1/2, (1/2)*(1 - m - n), 3/2, Sin[c + d*x]^2]*Sin[c + d*x])/d}


{Cos[c + d*x]^2*(A + B*Cos[c + d*x])*(b*Cos[c + d*x])^n, x, 6, (B*(b*Cos[c + d*x])^(4 + n)*(Cos[c + d*x]^2)^((1/2)*(-4 - n))*Hypergeometric2F1[1/2, (1/2)*(-2 - n), 3/2, Sin[c + d*x]^2]*Sin[c + d*x])/(b^4*d) + (A*(b*Cos[c + d*x])^(3 + n)*(Cos[c + d*x]^2)^((1/2)*(-3 - n))*Hypergeometric2F1[1/2, (1/2)*(-1 - n), 3/2, Sin[c + d*x]^2]*Sin[c + d*x])/(b^3*d)}
{Cos[c + d*x]^1*(A + B*Cos[c + d*x])*(b*Cos[c + d*x])^n, x, 6, (B*(b*Cos[c + d*x])^(3 + n)*(Cos[c + d*x]^2)^((1/2)*(-3 - n))*Hypergeometric2F1[1/2, (1/2)*(-1 - n), 3/2, Sin[c + d*x]^2]*Sin[c + d*x])/(b^3*d) + (A*(b*Cos[c + d*x])^(2 + n)*(Cos[c + d*x]^2)^((1/2)*(-2 - n))*Hypergeometric2F1[1/2, -(n/2), 3/2, Sin[c + d*x]^2]*Sin[c + d*x])/(b^2*d)}
{Cos[c + d*x]^0*(A + B*Cos[c + d*x])*(b*Cos[c + d*x])^n, x, 5, (A*(b*Cos[c + d*x])^(1 + n)*(Cos[c + d*x]^2)^((1/2)*(-1 - n))*Hypergeometric2F1[1/2, (1 - n)/2, 3/2, Sin[c + d*x]^2]*Sin[c + d*x])/(b*d) + (B*(b*Cos[c + d*x])^(2 + n)*(Cos[c + d*x]^2)^((1/2)*(-2 - n))*Hypergeometric2F1[1/2, -(n/2), 3/2, Sin[c + d*x]^2]*Sin[c + d*x])/(b^2*d)}
{Sec[c + d*x]^1*(A + B*Cos[c + d*x])*(b*Cos[c + d*x])^n, x, 6, (B*(b*Cos[c + d*x])^(1 + n)*(Cos[c + d*x]^2)^((1/2)*(-1 - n))*Hypergeometric2F1[1/2, (1 - n)/2, 3/2, Sin[c + d*x]^2]*Sin[c + d*x])/(b*d) + (A*(b*Cos[c + d*x])^n*Hypergeometric2F1[1/2, (2 - n)/2, 3/2, Sin[c + d*x]^2]*Sin[c + d*x])/((Cos[c + d*x]^2)^(n/2)*d)}
{Sec[c + d*x]^2*(A + B*Cos[c + d*x])*(b*Cos[c + d*x])^n, x, 6, (B*(b*Cos[c + d*x])^n*Hypergeometric2F1[1/2, (2 - n)/2, 3/2, Sin[c + d*x]^2]*Sin[c + d*x])/((Cos[c + d*x]^2)^(n/2)*d) + (A*b*(b*Cos[c + d*x])^(-1 + n)*(Cos[c + d*x]^2)^((1 - n)/2)*Hypergeometric2F1[1/2, (3 - n)/2, 3/2, Sin[c + d*x]^2]*Sin[c + d*x])/d}
{Sec[c + d*x]^3*(A + B*Cos[c + d*x])*(b*Cos[c + d*x])^n, x, 6, (b*B*(b*Cos[c + d*x])^(-1 + n)*(Cos[c + d*x]^2)^((1 - n)/2)*Hypergeometric2F1[1/2, (3 - n)/2, 3/2, Sin[c + d*x]^2]*Sin[c + d*x])/d + (A*b^2*(b*Cos[c + d*x])^(-2 + n)*(Cos[c + d*x]^2)^((2 - n)/2)*Hypergeometric2F1[1/2, (4 - n)/2, 3/2, Sin[c + d*x]^2]*Sin[c + d*x])/d}
{Sec[c + d*x]^4*(A + B*Cos[c + d*x])*(b*Cos[c + d*x])^n, x, 6, (b^2*B*(b*Cos[c + d*x])^(-2 + n)*(Cos[c + d*x]^2)^((2 - n)/2)*Hypergeometric2F1[1/2, (4 - n)/2, 3/2, Sin[c + d*x]^2]*Sin[c + d*x])/d + (A*b^3*(b*Cos[c + d*x])^(-3 + n)*(Cos[c + d*x]^2)^((3 - n)/2)*Hypergeometric2F1[1/2, (5 - n)/2, 3/2, Sin[c + d*x]^2]*Sin[c + d*x])/d}


{Cos[c + d*x]^(5/2)*(A + B*Cos[c + d*x])*(b*Cos[c + d*x])^n, x, 4, (B*Cos[c + d*x]^(9/2)*(b*Cos[c + d*x])^n*(Cos[c + d*x]^2)^((1/4)*(-9 - 2*n))*Hypergeometric2F1[1/2, (1/4)*(-5 - 2*n), 3/2, Sin[c + d*x]^2]*Sin[c + d*x])/d + (A*Cos[c + d*x]^(7/2)*(b*Cos[c + d*x])^n*(Cos[c + d*x]^2)^((1/4)*(-7 - 2*n))*Hypergeometric2F1[1/2, (1/4)*(-3 - 2*n), 3/2, Sin[c + d*x]^2]*Sin[c + d*x])/d}
{Cos[c + d*x]^(3/2)*(A + B*Cos[c + d*x])*(b*Cos[c + d*x])^n, x, 4, (B*Cos[c + d*x]^(7/2)*(b*Cos[c + d*x])^n*(Cos[c + d*x]^2)^((1/4)*(-7 - 2*n))*Hypergeometric2F1[1/2, (1/4)*(-3 - 2*n), 3/2, Sin[c + d*x]^2]*Sin[c + d*x])/d + (A*Cos[c + d*x]^(5/2)*(b*Cos[c + d*x])^n*(Cos[c + d*x]^2)^((1/4)*(-5 - 2*n))*Hypergeometric2F1[1/2, (1/4)*(-1 - 2*n), 3/2, Sin[c + d*x]^2]*Sin[c + d*x])/d}
{Cos[c + d*x]^(1/2)*(A + B*Cos[c + d*x])*(b*Cos[c + d*x])^n, x, 4, (B*Cos[c + d*x]^(5/2)*(b*Cos[c + d*x])^n*(Cos[c + d*x]^2)^((1/4)*(-5 - 2*n))*Hypergeometric2F1[1/2, (1/4)*(-1 - 2*n), 3/2, Sin[c + d*x]^2]*Sin[c + d*x])/d + (A*Cos[c + d*x]^(3/2)*(b*Cos[c + d*x])^n*(Cos[c + d*x]^2)^((1/4)*(-3 - 2*n))*Hypergeometric2F1[1/2, (1/4)*(1 - 2*n), 3/2, Sin[c + d*x]^2]*Sin[c + d*x])/d}
{Cos[c + d*x]^(-1/2)*(A + B*Cos[c + d*x])*(b*Cos[c + d*x])^n, x, 4, (B*Cos[c + d*x]^(3/2)*(b*Cos[c + d*x])^n*(Cos[c + d*x]^2)^((1/4)*(-3 - 2*n))*Hypergeometric2F1[1/2, (1/4)*(1 - 2*n), 3/2, Sin[c + d*x]^2]*Sin[c + d*x])/d + (A*Sqrt[Cos[c + d*x]]*(b*Cos[c + d*x])^n*(Cos[c + d*x]^2)^((1/4)*(-1 - 2*n))*Hypergeometric2F1[1/2, (1/4)*(3 - 2*n), 3/2, Sin[c + d*x]^2]*Sin[c + d*x])/d}
{Cos[c + d*x]^(-3/2)*(A + B*Cos[c + d*x])*(b*Cos[c + d*x])^n, x, 4, (B*Sqrt[Cos[c + d*x]]*(b*Cos[c + d*x])^n*(Cos[c + d*x]^2)^((1/4)*(-1 - 2*n))*Hypergeometric2F1[1/2, (1/4)*(3 - 2*n), 3/2, Sin[c + d*x]^2]*Sin[c + d*x])/d + (A*(b*Cos[c + d*x])^n*(Cos[c + d*x]^2)^((1/4)*(1 - 2*n))*Hypergeometric2F1[1/2, (1/4)*(5 - 2*n), 3/2, Sin[c + d*x]^2]*Sin[c + d*x])/(d*Sqrt[Cos[c + d*x]])}
{Cos[c + d*x]^(-5/2)*(A + B*Cos[c + d*x])*(b*Cos[c + d*x])^n, x, 4, (B*(b*Cos[c + d*x])^n*(Cos[c + d*x]^2)^((1/4)*(1 - 2*n))*Hypergeometric2F1[1/2, (1/4)*(5 - 2*n), 3/2, Sin[c + d*x]^2]*Sin[c + d*x])/(d*Sqrt[Cos[c + d*x]]) + (A*(b*Cos[c + d*x])^n*(Cos[c + d*x]^2)^((1/4)*(3 - 2*n))*Hypergeometric2F1[1/2, (1/4)*(7 - 2*n), 3/2, Sin[c + d*x]^2]*Sin[c + d*x])/(d*Cos[c + d*x]^(3/2))}
{Cos[c + d*x]^(-7/2)*(A + B*Cos[c + d*x])*(b*Cos[c + d*x])^n, x, 4, (B*(b*Cos[c + d*x])^n*(Cos[c + d*x]^2)^((1/4)*(3 - 2*n))*Hypergeometric2F1[1/2, (1/4)*(7 - 2*n), 3/2, Sin[c + d*x]^2]*Sin[c + d*x])/(d*Cos[c + d*x]^(3/2)) + (A*(b*Cos[c + d*x])^n*(Cos[c + d*x]^2)^((1/4)*(5 - 2*n))*Hypergeometric2F1[1/2, (1/4)*(9 - 2*n), 3/2, Sin[c + d*x]^2]*Sin[c + d*x])/(d*Cos[c + d*x]^(5/2))}
{Cos[c + d*x]^(-9/2)*(A + B*Cos[c + d*x])*(b*Cos[c + d*x])^n, x, 4, (B*(b*Cos[c + d*x])^n*(Cos[c + d*x]^2)^((1/4)*(5 - 2*n))*Hypergeometric2F1[1/2, (1/4)*(9 - 2*n), 3/2, Sin[c + d*x]^2]*Sin[c + d*x])/(d*Cos[c + d*x]^(5/2)) + (A*(b*Cos[c + d*x])^n*(Cos[c + d*x]^2)^((1/4)*(7 - 2*n))*Hypergeometric2F1[1/2, (1/4)*(11 - 2*n), 3/2, Sin[c + d*x]^2]*Sin[c + d*x])/(d*Cos[c + d*x]^(7/2))}


(* ::Section:: *)
(*Cos[c+d x]^m (A+C Cos[c+d x]^2) (b Cos[c+d x])^(n/2)*)


(* ::Subsection::Closed:: *)
(*Integrands of the form Cos[c+d x]^m (A+C Cos[c+d x]^2) (b Cos[c+d x])^(n/2)*)


(* ::Subsubsection::Closed:: *)
(*n>0*)


{Cos[c + d*x]^2*Sqrt[b*Cos[c + d*x]]*(A + C*Cos[c + d*x]^2), x, 5, (2*(9*A + 7*C)*Sqrt[b*Cos[c + d*x]]*EllipticE[(1/2)*(c + d*x), 2])/(15*d*Sqrt[Cos[c + d*x]]) + (2*(9*A + 7*C)*(b*Cos[c + d*x])^(3/2)*Sin[c + d*x])/(45*b*d) + (2*C*(b*Cos[c + d*x])^(7/2)*Sin[c + d*x])/(9*b^3*d)}
{Cos[c + d*x]*Sqrt[b*Cos[c + d*x]]*(A + C*Cos[c + d*x]^2), x, 5, (2*b*(7*A + 5*C)*Sqrt[Cos[c + d*x]]*EllipticF[(1/2)*(c + d*x), 2])/(21*d*Sqrt[b*Cos[c + d*x]]) + (2*(7*A + 5*C)*Sqrt[b*Cos[c + d*x]]*Sin[c + d*x])/(21*d) + (2*C*(b*Cos[c + d*x])^(5/2)*Sin[c + d*x])/(7*b^2*d)}
{Sqrt[b*Cos[c + d*x]]*(A + C*Cos[c + d*x]^2), x, 3, (2*(5*A + 3*C)*Sqrt[b*Cos[c + d*x]]*EllipticE[(1/2)*(c + d*x), 2])/(5*d*Sqrt[Cos[c + d*x]]) + (2*C*(b*Cos[c + d*x])^(3/2)*Sin[c + d*x])/(5*b*d)}
{Sqrt[b*Cos[c + d*x]]*(A + C*Cos[c + d*x]^2)*Sec[c + d*x], x, 4, (2*b*(3*A + C)*Sqrt[Cos[c + d*x]]*EllipticF[(1/2)*(c + d*x), 2])/(3*d*Sqrt[b*Cos[c + d*x]]) + (2*C*Sqrt[b*Cos[c + d*x]]*Sin[c + d*x])/(3*d)}
{Sqrt[b*Cos[c + d*x]]*(A + C*Cos[c + d*x]^2)*Sec[c + d*x]^2, x, 4, -((2*(A - C)*Sqrt[b*Cos[c + d*x]]*EllipticE[(1/2)*(c + d*x), 2])/(d*Sqrt[Cos[c + d*x]])) + (2*A*b*Sin[c + d*x])/(d*Sqrt[b*Cos[c + d*x]])}
{Sqrt[b*Cos[c + d*x]]*(A + C*Cos[c + d*x]^2)*Sec[c + d*x]^3, x, 4, (2*b*(A + 3*C)*Sqrt[Cos[c + d*x]]*EllipticF[(c + d*x)/2, 2])/(3*d*Sqrt[b*Cos[c + d*x]]) + (2*A*b^2*Sin[c + d*x])/(3*d*(b*Cos[c + d*x])^(3/2))}
{Sqrt[b*Cos[c + d*x]]*(A + C*Cos[c + d*x]^2)*Sec[c + d*x]^4, x, 5, -((2*(3*A + 5*C)*Sqrt[b*Cos[c + d*x]]*EllipticE[(1/2)*(c + d*x), 2])/(5*d*Sqrt[Cos[c + d*x]])) + (2*A*b^3*Sin[c + d*x])/(5*d*(b*Cos[c + d*x])^(5/2)) + (2*b*(3*A + 5*C)*Sin[c + d*x])/(5*d*Sqrt[b*Cos[c + d*x]])}
{Sqrt[b*Cos[c + d*x]]*(A + C*Cos[c + d*x]^2)*Sec[c + d*x]^5, x, 5, (2*b*(5*A + 7*C)*Sqrt[Cos[c + d*x]]*EllipticF[(1/2)*(c + d*x), 2])/(21*d*Sqrt[b*Cos[c + d*x]]) + (2*A*b^4*Sin[c + d*x])/(7*d*(b*Cos[c + d*x])^(7/2)) + (2*b^2*(5*A + 7*C)*Sin[c + d*x])/(21*d*(b*Cos[c + d*x])^(3/2))}


{Cos[c + d*x]*(b*Cos[c + d*x])^(3/2)*(A + C*Cos[c + d*x]^2), x, 5, (2*b*(9*A + 7*C)*Sqrt[b*Cos[c + d*x]]*EllipticE[(1/2)*(c + d*x), 2])/(15*d*Sqrt[Cos[c + d*x]]) + (2*(9*A + 7*C)*(b*Cos[c + d*x])^(3/2)*Sin[c + d*x])/(45*d) + (2*C*(b*Cos[c + d*x])^(7/2)*Sin[c + d*x])/(9*b^2*d)}
{(b*Cos[c + d*x])^(3/2)*(A + C*Cos[c + d*x]^2), x, 4, (2*b^2*(7*A + 5*C)*Sqrt[Cos[c + d*x]]*EllipticF[(1/2)*(c + d*x), 2])/(21*d*Sqrt[b*Cos[c + d*x]]) + (2*b*(7*A + 5*C)*Sqrt[b*Cos[c + d*x]]*Sin[c + d*x])/(21*d) + (2*C*(b*Cos[c + d*x])^(5/2)*Sin[c + d*x])/(7*b*d)}
{(b*Cos[c + d*x])^(3/2)*(A + C*Cos[c + d*x]^2)*Sec[c + d*x], x, 4, (2*b*(5*A + 3*C)*Sqrt[b*Cos[c + d*x]]*EllipticE[(1/2)*(c + d*x), 2])/(5*d*Sqrt[Cos[c + d*x]]) + (2*C*(b*Cos[c + d*x])^(3/2)*Sin[c + d*x])/(5*d)}
{(b*Cos[c + d*x])^(3/2)*(A + C*Cos[c + d*x]^2)*Sec[c + d*x]^2, x, 4, (2*b^2*(3*A + C)*Sqrt[Cos[c + d*x]]*EllipticF[(c + d*x)/2, 2])/(3*d*Sqrt[b*Cos[c + d*x]]) + (2*b*C*Sqrt[b*Cos[c + d*x]]*Sin[c + d*x])/(3*d)}
{(b*Cos[c + d*x])^(3/2)*(A + C*Cos[c + d*x]^2)*Sec[c + d*x]^3, x, 4, -((2*b*(A - C)*Sqrt[b*Cos[c + d*x]]*EllipticE[(1/2)*(c + d*x), 2])/(d*Sqrt[Cos[c + d*x]])) + (2*A*b^2*Sin[c + d*x])/(d*Sqrt[b*Cos[c + d*x]])}
{(b*Cos[c + d*x])^(3/2)*(A + C*Cos[c + d*x]^2)*Sec[c + d*x]^4, x, 4, (2*b^2*(A + 3*C)*Sqrt[Cos[c + d*x]]*EllipticF[(c + d*x)/2, 2])/(3*d*Sqrt[b*Cos[c + d*x]]) + (2*A*b^3*Sin[c + d*x])/(3*d*(b*Cos[c + d*x])^(3/2))}
{(b*Cos[c + d*x])^(3/2)*(A + C*Cos[c + d*x]^2)*Sec[c + d*x]^5, x, 5, -((2*b*(3*A + 5*C)*Sqrt[b*Cos[c + d*x]]*EllipticE[(1/2)*(c + d*x), 2])/(5*d*Sqrt[Cos[c + d*x]])) + (2*A*b^4*Sin[c + d*x])/(5*d*(b*Cos[c + d*x])^(5/2)) + (2*b^2*(3*A + 5*C)*Sin[c + d*x])/(5*d*Sqrt[b*Cos[c + d*x]])}
{(b*Cos[c + d*x])^(3/2)*(A + C*Cos[c + d*x]^2)*Sec[c + d*x]^6, x, 5, (2*b^2*(5*A + 7*C)*Sqrt[Cos[c + d*x]]*EllipticF[(1/2)*(c + d*x), 2])/(21*d*Sqrt[b*Cos[c + d*x]]) + (2*A*b^5*Sin[c + d*x])/(7*d*(b*Cos[c + d*x])^(7/2)) + (2*b^3*(5*A + 7*C)*Sin[c + d*x])/(21*d*(b*Cos[c + d*x])^(3/2))}


{(b*Cos[c + d*x])^(5/2)*(A + C*Cos[c + d*x]^2), x, 4, (2*b^2*(9*A + 7*C)*Sqrt[b*Cos[c + d*x]]*EllipticE[(1/2)*(c + d*x), 2])/(15*d*Sqrt[Cos[c + d*x]]) + (2*b*(9*A + 7*C)*(b*Cos[c + d*x])^(3/2)*Sin[c + d*x])/(45*d) + (2*C*(b*Cos[c + d*x])^(7/2)*Sin[c + d*x])/(9*b*d)}
{(b*Cos[c + d*x])^(5/2)*(A + C*Cos[c + d*x]^2)*Sec[c + d*x], x, 5, (2*b^3*(7*A + 5*C)*Sqrt[Cos[c + d*x]]*EllipticF[(1/2)*(c + d*x), 2])/(21*d*Sqrt[b*Cos[c + d*x]]) + (2*b^2*(7*A + 5*C)*Sqrt[b*Cos[c + d*x]]*Sin[c + d*x])/(21*d) + (2*C*(b*Cos[c + d*x])^(5/2)*Sin[c + d*x])/(7*d)}
{(b*Cos[c + d*x])^(5/2)*(A + C*Cos[c + d*x]^2)*Sec[c + d*x]^2, x, 4, (2*b^2*(5*A + 3*C)*Sqrt[b*Cos[c + d*x]]*EllipticE[(1/2)*(c + d*x), 2])/(5*d*Sqrt[Cos[c + d*x]]) + (2*b*C*(b*Cos[c + d*x])^(3/2)*Sin[c + d*x])/(5*d)}
{(b*Cos[c + d*x])^(5/2)*(A + C*Cos[c + d*x]^2)*Sec[c + d*x]^3, x, 4, (2*b^3*(3*A + C)*Sqrt[Cos[c + d*x]]*EllipticF[(c + d*x)/2, 2])/(3*d*Sqrt[b*Cos[c + d*x]]) + (2*b^2*C*Sqrt[b*Cos[c + d*x]]*Sin[c + d*x])/(3*d)}
{(b*Cos[c + d*x])^(5/2)*(A + C*Cos[c + d*x]^2)*Sec[c + d*x]^4, x, 4, -((2*b^2*(A - C)*Sqrt[b*Cos[c + d*x]]*EllipticE[(1/2)*(c + d*x), 2])/(d*Sqrt[Cos[c + d*x]])) + (2*A*b^3*Sin[c + d*x])/(d*Sqrt[b*Cos[c + d*x]])}
{(b*Cos[c + d*x])^(5/2)*(A + C*Cos[c + d*x]^2)*Sec[c + d*x]^5, x, 4, (2*b^3*(A + 3*C)*Sqrt[Cos[c + d*x]]*EllipticF[(c + d*x)/2, 2])/(3*d*Sqrt[b*Cos[c + d*x]]) + (2*A*b^4*Sin[c + d*x])/(3*d*(b*Cos[c + d*x])^(3/2))}
{(b*Cos[c + d*x])^(5/2)*(A + C*Cos[c + d*x]^2)*Sec[c + d*x]^6, x, 5, -((2*b^2*(3*A + 5*C)*Sqrt[b*Cos[c + d*x]]*EllipticE[(1/2)*(c + d*x), 2])/(5*d*Sqrt[Cos[c + d*x]])) + (2*A*b^5*Sin[c + d*x])/(5*d*(b*Cos[c + d*x])^(5/2)) + (2*b^3*(3*A + 5*C)*Sin[c + d*x])/(5*d*Sqrt[b*Cos[c + d*x]])}
{(b*Cos[c + d*x])^(5/2)*(A + C*Cos[c + d*x]^2)*Sec[c + d*x]^7, x, 5, (2*b^3*(5*A + 7*C)*Sqrt[Cos[c + d*x]]*EllipticF[(1/2)*(c + d*x), 2])/(21*d*Sqrt[b*Cos[c + d*x]]) + (2*A*b^6*Sin[c + d*x])/(7*d*(b*Cos[c + d*x])^(7/2)) + (2*b^4*(5*A + 7*C)*Sin[c + d*x])/(21*d*(b*Cos[c + d*x])^(3/2))}


(* ::Subsubsection::Closed:: *)
(*n<0*)


{Cos[c + d*x]^4*(A + C*Cos[c + d*x]^2)/(b*Cos[c + d*x])^(1/2), x, 6, (10*(11*A + 9*C)*Sqrt[Cos[c + d*x]]*EllipticF[(1/2)*(c + d*x), 2])/(231*d*Sqrt[b*Cos[c + d*x]]) + (10*(11*A + 9*C)*Sqrt[b*Cos[c + d*x]]*Sin[c + d*x])/(231*b*d) + (2*(11*A + 9*C)*(b*Cos[c + d*x])^(5/2)*Sin[c + d*x])/(77*b^3*d) + (2*C*(b*Cos[c + d*x])^(9/2)*Sin[c + d*x])/(11*b^5*d)}
{Cos[c + d*x]^3*(A + C*Cos[c + d*x]^2)/(b*Cos[c + d*x])^(1/2), x, 5, (2*(9*A + 7*C)*Sqrt[b*Cos[c + d*x]]*EllipticE[(1/2)*(c + d*x), 2])/(15*b*d*Sqrt[Cos[c + d*x]]) + (2*(9*A + 7*C)*(b*Cos[c + d*x])^(3/2)*Sin[c + d*x])/(45*b^2*d) + (2*C*(b*Cos[c + d*x])^(7/2)*Sin[c + d*x])/(9*b^4*d)}
{Cos[c + d*x]^2*(A + C*Cos[c + d*x]^2)/(b*Cos[c + d*x])^(1/2), x, 5, (2*(7*A + 5*C)*Sqrt[Cos[c + d*x]]*EllipticF[(1/2)*(c + d*x), 2])/(21*d*Sqrt[b*Cos[c + d*x]]) + (2*(7*A + 5*C)*Sqrt[b*Cos[c + d*x]]*Sin[c + d*x])/(21*b*d) + (2*C*(b*Cos[c + d*x])^(5/2)*Sin[c + d*x])/(7*b^3*d)}
{Cos[c + d*x]^1*(A + C*Cos[c + d*x]^2)/(b*Cos[c + d*x])^(1/2), x, 4, (2*(5*A + 3*C)*Sqrt[b*Cos[c + d*x]]*EllipticE[(1/2)*(c + d*x), 2])/(5*b*d*Sqrt[Cos[c + d*x]]) + (2*C*(b*Cos[c + d*x])^(3/2)*Sin[c + d*x])/(5*b^2*d)}
{Cos[c + d*x]^0*(A + C*Cos[c + d*x]^2)/(b*Cos[c + d*x])^(1/2), x, 3, (2*(3*A + C)*Sqrt[Cos[c + d*x]]*EllipticF[(1/2)*(c + d*x), 2])/(3*d*Sqrt[b*Cos[c + d*x]]) + (2*C*Sqrt[b*Cos[c + d*x]]*Sin[c + d*x])/(3*b*d)}
{Sec[c + d*x]^1*(A + C*Cos[c + d*x]^2)/(b*Cos[c + d*x])^(1/2), x, 4, -((2*(A - C)*Sqrt[b*Cos[c + d*x]]*EllipticE[(1/2)*(c + d*x), 2])/(b*d*Sqrt[Cos[c + d*x]])) + (2*A*Sin[c + d*x])/(d*Sqrt[b*Cos[c + d*x]])}
{Sec[c + d*x]^2*(A + C*Cos[c + d*x]^2)/(b*Cos[c + d*x])^(1/2), x, 4, (2*(A + 3*C)*Sqrt[Cos[c + d*x]]*EllipticF[(1/2)*(c + d*x), 2])/(3*d*Sqrt[b*Cos[c + d*x]]) + (2*A*b*Sin[c + d*x])/(3*d*(b*Cos[c + d*x])^(3/2))}
{Sec[c + d*x]^3*(A + C*Cos[c + d*x]^2)/(b*Cos[c + d*x])^(1/2), x, 5, -((2*(3*A + 5*C)*Sqrt[b*Cos[c + d*x]]*EllipticE[(1/2)*(c + d*x), 2])/(5*b*d*Sqrt[Cos[c + d*x]])) + (2*A*b^2*Sin[c + d*x])/(5*d*(b*Cos[c + d*x])^(5/2)) + (2*(3*A + 5*C)*Sin[c + d*x])/(5*d*Sqrt[b*Cos[c + d*x]])}
{Sec[c + d*x]^4*(A + C*Cos[c + d*x]^2)/(b*Cos[c + d*x])^(1/2), x, 5, (2*(5*A + 7*C)*Sqrt[Cos[c + d*x]]*EllipticF[(1/2)*(c + d*x), 2])/(21*d*Sqrt[b*Cos[c + d*x]]) + (2*A*b^3*Sin[c + d*x])/(7*d*(b*Cos[c + d*x])^(7/2)) + (2*b*(5*A + 7*C)*Sin[c + d*x])/(21*d*(b*Cos[c + d*x])^(3/2))}
{Sec[c + d*x]^5*(A + C*Cos[c + d*x]^2)/(b*Cos[c + d*x])^(1/2), x, 6, -((2*(7*A + 9*C)*Sqrt[b*Cos[c + d*x]]*EllipticE[(1/2)*(c + d*x), 2])/(15*b*d*Sqrt[Cos[c + d*x]])) + (2*A*b^4*Sin[c + d*x])/(9*d*(b*Cos[c + d*x])^(9/2)) + (2*b^2*(7*A + 9*C)*Sin[c + d*x])/(45*d*(b*Cos[c + d*x])^(5/2)) + (2*(7*A + 9*C)*Sin[c + d*x])/(15*d*Sqrt[b*Cos[c + d*x]])}


{Cos[c + d*x]^4*(A + C*Cos[c + d*x]^2)/(b*Cos[c + d*x])^(3/2), x, 5, (2*(9*A + 7*C)*Sqrt[b*Cos[c + d*x]]*EllipticE[(1/2)*(c + d*x), 2])/(15*b^2*d*Sqrt[Cos[c + d*x]]) + (2*(9*A + 7*C)*(b*Cos[c + d*x])^(3/2)*Sin[c + d*x])/(45*b^3*d) + (2*C*(b*Cos[c + d*x])^(7/2)*Sin[c + d*x])/(9*b^5*d)}
{Cos[c + d*x]^3*(A + C*Cos[c + d*x]^2)/(b*Cos[c + d*x])^(3/2), x, 5, (2*(7*A + 5*C)*Sqrt[Cos[c + d*x]]*EllipticF[(1/2)*(c + d*x), 2])/(21*b*d*Sqrt[b*Cos[c + d*x]]) + (2*(7*A + 5*C)*Sqrt[b*Cos[c + d*x]]*Sin[c + d*x])/(21*b^2*d) + (2*C*(b*Cos[c + d*x])^(5/2)*Sin[c + d*x])/(7*b^4*d)}
{Cos[c + d*x]^2*(A + C*Cos[c + d*x]^2)/(b*Cos[c + d*x])^(3/2), x, 4, (2*(5*A + 3*C)*Sqrt[b*Cos[c + d*x]]*EllipticE[(1/2)*(c + d*x), 2])/(5*b^2*d*Sqrt[Cos[c + d*x]]) + (2*C*(b*Cos[c + d*x])^(3/2)*Sin[c + d*x])/(5*b^3*d)}
{Cos[c + d*x]^1*(A + C*Cos[c + d*x]^2)/(b*Cos[c + d*x])^(3/2), x, 4, (2*(3*A + C)*Sqrt[Cos[c + d*x]]*EllipticF[(c + d*x)/2, 2])/(3*b*d*Sqrt[b*Cos[c + d*x]]) + (2*C*Sqrt[b*Cos[c + d*x]]*Sin[c + d*x])/(3*b^2*d)}
{Cos[c + d*x]^0*(A + C*Cos[c + d*x]^2)/(b*Cos[c + d*x])^(3/2), x, 3, -((2*(A - C)*Sqrt[b*Cos[c + d*x]]*EllipticE[(1/2)*(c + d*x), 2])/(b^2*d*Sqrt[Cos[c + d*x]])) + (2*A*Sin[c + d*x])/(b*d*Sqrt[b*Cos[c + d*x]])}
{Sec[c + d*x]^1*(A + C*Cos[c + d*x]^2)/(b*Cos[c + d*x])^(3/2), x, 4, (2*(A + 3*C)*Sqrt[Cos[c + d*x]]*EllipticF[(c + d*x)/2, 2])/(3*b*d*Sqrt[b*Cos[c + d*x]]) + (2*A*Sin[c + d*x])/(3*d*(b*Cos[c + d*x])^(3/2))}
{Sec[c + d*x]^2*(A + C*Cos[c + d*x]^2)/(b*Cos[c + d*x])^(3/2), x, 5, -((2*(3*A + 5*C)*Sqrt[b*Cos[c + d*x]]*EllipticE[(1/2)*(c + d*x), 2])/(5*b^2*d*Sqrt[Cos[c + d*x]])) + (2*A*b*Sin[c + d*x])/(5*d*(b*Cos[c + d*x])^(5/2)) + (2*(3*A + 5*C)*Sin[c + d*x])/(5*b*d*Sqrt[b*Cos[c + d*x]])}
{Sec[c + d*x]^3*(A + C*Cos[c + d*x]^2)/(b*Cos[c + d*x])^(3/2), x, 5, (2*(5*A + 7*C)*Sqrt[Cos[c + d*x]]*EllipticF[(1/2)*(c + d*x), 2])/(21*b*d*Sqrt[b*Cos[c + d*x]]) + (2*A*b^2*Sin[c + d*x])/(7*d*(b*Cos[c + d*x])^(7/2)) + (2*(5*A + 7*C)*Sin[c + d*x])/(21*d*(b*Cos[c + d*x])^(3/2))}


{Cos[c + d*x]^5*(A + C*Cos[c + d*x]^2)/(b*Cos[c + d*x])^(5/2), x, 5, (2*(9*A + 7*C)*Sqrt[b*Cos[c + d*x]]*EllipticE[(1/2)*(c + d*x), 2])/(15*b^3*d*Sqrt[Cos[c + d*x]]) + (2*(9*A + 7*C)*(b*Cos[c + d*x])^(3/2)*Sin[c + d*x])/(45*b^4*d) + (2*C*(b*Cos[c + d*x])^(7/2)*Sin[c + d*x])/(9*b^6*d)}
{Cos[c + d*x]^4*(A + C*Cos[c + d*x]^2)/(b*Cos[c + d*x])^(5/2), x, 5, (2*(7*A + 5*C)*Sqrt[Cos[c + d*x]]*EllipticF[(1/2)*(c + d*x), 2])/(21*b^2*d*Sqrt[b*Cos[c + d*x]]) + (2*(7*A + 5*C)*Sqrt[b*Cos[c + d*x]]*Sin[c + d*x])/(21*b^3*d) + (2*C*(b*Cos[c + d*x])^(5/2)*Sin[c + d*x])/(7*b^5*d)}
{Cos[c + d*x]^3*(A + C*Cos[c + d*x]^2)/(b*Cos[c + d*x])^(5/2), x, 4, (2*(5*A + 3*C)*Sqrt[b*Cos[c + d*x]]*EllipticE[(1/2)*(c + d*x), 2])/(5*b^3*d*Sqrt[Cos[c + d*x]]) + (2*C*(b*Cos[c + d*x])^(3/2)*Sin[c + d*x])/(5*b^4*d)}
{Cos[c + d*x]^2*(A + C*Cos[c + d*x]^2)/(b*Cos[c + d*x])^(5/2), x, 4, (2*(3*A + C)*Sqrt[Cos[c + d*x]]*EllipticF[(c + d*x)/2, 2])/(3*b^2*d*Sqrt[b*Cos[c + d*x]]) + (2*C*Sqrt[b*Cos[c + d*x]]*Sin[c + d*x])/(3*b^3*d)}
{Cos[c + d*x]^1*(A + C*Cos[c + d*x]^2)/(b*Cos[c + d*x])^(5/2), x, 4, -((2*(A - C)*Sqrt[b*Cos[c + d*x]]*EllipticE[(1/2)*(c + d*x), 2])/(b^3*d*Sqrt[Cos[c + d*x]])) + (2*A*Sin[c + d*x])/(b^2*d*Sqrt[b*Cos[c + d*x]])}
{Cos[c + d*x]^0*(A + C*Cos[c + d*x]^2)/(b*Cos[c + d*x])^(5/2), x, 3, (2*(A + 3*C)*Sqrt[Cos[c + d*x]]*EllipticF[(c + d*x)/2, 2])/(3*b^2*d*Sqrt[b*Cos[c + d*x]]) + (2*A*Sin[c + d*x])/(3*b*d*(b*Cos[c + d*x])^(3/2))}
{Sec[c + d*x]^1*(A + C*Cos[c + d*x]^2)/(b*Cos[c + d*x])^(5/2), x, 5, -((2*(3*A + 5*C)*Sqrt[b*Cos[c + d*x]]*EllipticE[(1/2)*(c + d*x), 2])/(5*b^3*d*Sqrt[Cos[c + d*x]])) + (2*A*Sin[c + d*x])/(5*d*(b*Cos[c + d*x])^(5/2)) + (2*(3*A + 5*C)*Sin[c + d*x])/(5*b^2*d*Sqrt[b*Cos[c + d*x]])}
{Sec[c + d*x]^2*(A + C*Cos[c + d*x]^2)/(b*Cos[c + d*x])^(5/2), x, 5, (2*(5*A + 7*C)*Sqrt[Cos[c + d*x]]*EllipticF[(1/2)*(c + d*x), 2])/(21*b^2*d*Sqrt[b*Cos[c + d*x]]) + (2*A*b*Sin[c + d*x])/(7*d*(b*Cos[c + d*x])^(7/2)) + (2*(5*A + 7*C)*Sin[c + d*x])/(21*b*d*(b*Cos[c + d*x])^(3/2))}


{Cos[c + d*x]^0*(A + C*Cos[c + d*x]^2)/(b*Cos[c + d*x])^(7/2), x, 4, -((2*(3*A + 5*C)*Sqrt[b*Cos[c + d*x]]*EllipticE[(1/2)*(c + d*x), 2])/(5*b^4*d*Sqrt[Cos[c + d*x]])) + (2*A*Sin[c + d*x])/(5*b*d*(b*Cos[c + d*x])^(5/2)) + (2*(3*A + 5*C)*Sin[c + d*x])/(5*b^3*d*Sqrt[b*Cos[c + d*x]])}


{Cos[c + d*x]^0*(A + C*Cos[c + d*x]^2)/(b*Cos[c + d*x])^(9/2), x, 4, (2*(5*A + 7*C)*Sqrt[Cos[c + d*x]]*EllipticF[(1/2)*(c + d*x), 2])/(21*b^4*d*Sqrt[b*Cos[c + d*x]]) + (2*A*Sin[c + d*x])/(7*b*d*(b*Cos[c + d*x])^(7/2)) + (2*(5*A + 7*C)*Sin[c + d*x])/(21*b^3*d*(b*Cos[c + d*x])^(3/2))}


(* ::Subsection::Closed:: *)
(*Integrands of the form Cos[c+d x]^(m/2) (A+C Cos[c+d x]^2) (b Cos[c+d x])^(n/2)*)


(* ::Subsubsection::Closed:: *)
(*n>0*)


{Cos[c + d*x]^(5/2)*Sqrt[b*Cos[c + d*x]]*(A + C*Cos[c + d*x]^2), x, 4, ((5*A + 4*C)*Sqrt[b*Cos[c + d*x]]*Sin[c + d*x])/(5*d*Sqrt[Cos[c + d*x]]) + (C*Cos[c + d*x]^(7/2)*Sqrt[b*Cos[c + d*x]]*Sin[c + d*x])/(5*d) - ((5*A + 4*C)*Sqrt[b*Cos[c + d*x]]*Sin[c + d*x]^3)/(15*d*Sqrt[Cos[c + d*x]])}
{Cos[c + d*x]^(3/2)*Sqrt[b*Cos[c + d*x]]*(A + C*Cos[c + d*x]^2), x, 3, ((4*A + 3*C)*x*Sqrt[b*Cos[c + d*x]])/(8*Sqrt[Cos[c + d*x]]) + ((4*A + 3*C)*Sqrt[Cos[c + d*x]]*Sqrt[b*Cos[c + d*x]]*Sin[c + d*x])/(8*d) + (C*Cos[c + d*x]^(5/2)*Sqrt[b*Cos[c + d*x]]*Sin[c + d*x])/(4*d)}
{Sqrt[Cos[c + d*x]]*Sqrt[b*Cos[c + d*x]]*(A + C*Cos[c + d*x]^2), x, 3, ((3*A + 2*C)*Sqrt[b*Cos[c + d*x]]*Sin[c + d*x])/(3*d*Sqrt[Cos[c + d*x]]) + (C*Cos[c + d*x]^(3/2)*Sqrt[b*Cos[c + d*x]]*Sin[c + d*x])/(3*d)}
{(Sqrt[b*Cos[c + d*x]]*(A + C*Cos[c + d*x]^2))/Sqrt[Cos[c + d*x]], x, 3, (A*x*Sqrt[b*Cos[c + d*x]])/Sqrt[Cos[c + d*x]] + (C*x*Sqrt[b*Cos[c + d*x]])/(2*Sqrt[Cos[c + d*x]]) + (C*Sqrt[Cos[c + d*x]]*Sqrt[b*Cos[c + d*x]]*Sin[c + d*x])/(2*d)}
{(Sqrt[b*Cos[c + d*x]]*(A + C*Cos[c + d*x]^2))/Cos[c + d*x]^(3/2), x, 3, (A*ArcTanh[Sin[c + d*x]]*Sqrt[b*Cos[c + d*x]])/(d*Sqrt[Cos[c + d*x]]) + (C*Sqrt[b*Cos[c + d*x]]*Sin[c + d*x])/(d*Sqrt[Cos[c + d*x]])}
{(Sqrt[b*Cos[c + d*x]]*(A + C*Cos[c + d*x]^2))/Cos[c + d*x]^(5/2), x, 3, (C*x*Sqrt[b*Cos[c + d*x]])/Sqrt[Cos[c + d*x]] + (A*Sqrt[b*Cos[c + d*x]]*Sin[c + d*x])/(d*Cos[c + d*x]^(3/2))}
{(Sqrt[b*Cos[c + d*x]]*(A + C*Cos[c + d*x]^2))/Cos[c + d*x]^(7/2), x, 3, ((A + 2*C)*ArcTanh[Sin[c + d*x]]*Sqrt[b*Cos[c + d*x]])/(2*d*Sqrt[Cos[c + d*x]]) + (A*Sqrt[b*Cos[c + d*x]]*Sin[c + d*x])/(2*d*Cos[c + d*x]^(5/2))}
{(Sqrt[b*Cos[c + d*x]]*(A + C*Cos[c + d*x]^2))/Cos[c + d*x]^(9/2), x, 3, (A*Sqrt[b*Cos[c + d*x]]*Sin[c + d*x])/(3*d*Cos[c + d*x]^(7/2)) + ((2*A + 3*C)*Sqrt[b*Cos[c + d*x]]*Sin[c + d*x])/(3*d*Cos[c + d*x]^(3/2))}
{(Sqrt[b*Cos[c + d*x]]*(A + C*Cos[c + d*x]^2))/Cos[c + d*x]^(11/2), x, 4, ((3*A + 4*C)*ArcTanh[Sin[c + d*x]]*Sqrt[b*Cos[c + d*x]])/(8*d*Sqrt[Cos[c + d*x]]) + (A*Sqrt[b*Cos[c + d*x]]*Sin[c + d*x])/(4*d*Cos[c + d*x]^(9/2)) + ((3*A + 4*C)*Sqrt[b*Cos[c + d*x]]*Sin[c + d*x])/(8*d*Cos[c + d*x]^(5/2))}


{Cos[c + d*x]^(3/2)*(b*Cos[c + d*x])^(3/2)*(A + C*Cos[c + d*x]^2), x, 4, (b*(5*A + 4*C)*Sqrt[b*Cos[c + d*x]]*Sin[c + d*x])/(5*d*Sqrt[Cos[c + d*x]]) + (b*C*Cos[c + d*x]^(7/2)*Sqrt[b*Cos[c + d*x]]*Sin[c + d*x])/(5*d) - (b*(5*A + 4*C)*Sqrt[b*Cos[c + d*x]]*Sin[c + d*x]^3)/(15*d*Sqrt[Cos[c + d*x]])}
{Sqrt[Cos[c + d*x]]*(b*Cos[c + d*x])^(3/2)*(A + C*Cos[c + d*x]^2), x, 3, (b*(4*A + 3*C)*x*Sqrt[b*Cos[c + d*x]])/(8*Sqrt[Cos[c + d*x]]) + (b*(4*A + 3*C)*Sqrt[Cos[c + d*x]]*Sqrt[b*Cos[c + d*x]]*Sin[c + d*x])/(8*d) + (b*C*Cos[c + d*x]^(5/2)*Sqrt[b*Cos[c + d*x]]*Sin[c + d*x])/(4*d)}
{((b*Cos[c + d*x])^(3/2)*(A + C*Cos[c + d*x]^2))/Sqrt[Cos[c + d*x]], x, 3, (b*(3*A + 2*C)*Sqrt[b*Cos[c + d*x]]*Sin[c + d*x])/(3*d*Sqrt[Cos[c + d*x]]) + (b*C*Cos[c + d*x]^(3/2)*Sqrt[b*Cos[c + d*x]]*Sin[c + d*x])/(3*d)}
{((b*Cos[c + d*x])^(3/2)*(A + C*Cos[c + d*x]^2))/Cos[c + d*x]^(3/2), x, 3, (A*b*x*Sqrt[b*Cos[c + d*x]])/Sqrt[Cos[c + d*x]] + (b*C*x*Sqrt[b*Cos[c + d*x]])/(2*Sqrt[Cos[c + d*x]]) + (b*C*Sqrt[Cos[c + d*x]]*Sqrt[b*Cos[c + d*x]]*Sin[c + d*x])/(2*d)}
{((b*Cos[c + d*x])^(3/2)*(A + C*Cos[c + d*x]^2))/Cos[c + d*x]^(5/2), x, 3, (A*b*ArcTanh[Sin[c + d*x]]*Sqrt[b*Cos[c + d*x]])/(d*Sqrt[Cos[c + d*x]]) + (b*C*Sqrt[b*Cos[c + d*x]]*Sin[c + d*x])/(d*Sqrt[Cos[c + d*x]])}
{((b*Cos[c + d*x])^(3/2)*(A + C*Cos[c + d*x]^2))/Cos[c + d*x]^(7/2), x, 3, (b*C*x*Sqrt[b*Cos[c + d*x]])/Sqrt[Cos[c + d*x]] + (A*b*Sqrt[b*Cos[c + d*x]]*Sin[c + d*x])/(d*Cos[c + d*x]^(3/2))}
{((b*Cos[c + d*x])^(3/2)*(A + C*Cos[c + d*x]^2))/Cos[c + d*x]^(9/2), x, 3, (b*(A + 2*C)*ArcTanh[Sin[c + d*x]]*Sqrt[b*Cos[c + d*x]])/(2*d*Sqrt[Cos[c + d*x]]) + (A*b*Sqrt[b*Cos[c + d*x]]*Sin[c + d*x])/(2*d*Cos[c + d*x]^(5/2))}
{((b*Cos[c + d*x])^(3/2)*(A + C*Cos[c + d*x]^2))/Cos[c + d*x]^(11/2), x, 3, (A*b*Sqrt[b*Cos[c + d*x]]*Sin[c + d*x])/(3*d*Cos[c + d*x]^(7/2)) + (b*(2*A + 3*C)*Sqrt[b*Cos[c + d*x]]*Sin[c + d*x])/(3*d*Cos[c + d*x]^(3/2))}
{((b*Cos[c + d*x])^(3/2)*(A + C*Cos[c + d*x]^2))/Cos[c + d*x]^(13/2), x, 4, (b*(3*A + 4*C)*ArcTanh[Sin[c + d*x]]*Sqrt[b*Cos[c + d*x]])/(8*d*Sqrt[Cos[c + d*x]]) + (A*b*Sqrt[b*Cos[c + d*x]]*Sin[c + d*x])/(4*d*Cos[c + d*x]^(9/2)) + (b*(3*A + 4*C)*Sqrt[b*Cos[c + d*x]]*Sin[c + d*x])/(8*d*Cos[c + d*x]^(5/2))}


{Sqrt[Cos[c + d*x]]*(b*Cos[c + d*x])^(5/2)*(A + C*Cos[c + d*x]^2), x, 4, (b^2*(5*A + 4*C)*Sqrt[b*Cos[c + d*x]]*Sin[c + d*x])/(5*d*Sqrt[Cos[c + d*x]]) + (b^2*C*Cos[c + d*x]^(7/2)*Sqrt[b*Cos[c + d*x]]*Sin[c + d*x])/(5*d) - (b^2*(5*A + 4*C)*Sqrt[b*Cos[c + d*x]]*Sin[c + d*x]^3)/(15*d*Sqrt[Cos[c + d*x]])}
{((b*Cos[c + d*x])^(5/2)*(A + C*Cos[c + d*x]^2))/Sqrt[Cos[c + d*x]], x, 3, (b^2*(4*A + 3*C)*x*Sqrt[b*Cos[c + d*x]])/(8*Sqrt[Cos[c + d*x]]) + (b^2*(4*A + 3*C)*Sqrt[Cos[c + d*x]]*Sqrt[b*Cos[c + d*x]]*Sin[c + d*x])/(8*d) + (b^2*C*Cos[c + d*x]^(5/2)*Sqrt[b*Cos[c + d*x]]*Sin[c + d*x])/(4*d)}
{((b*Cos[c + d*x])^(5/2)*(A + C*Cos[c + d*x]^2))/Cos[c + d*x]^(3/2), x, 3, (b^2*(3*A + 2*C)*Sqrt[b*Cos[c + d*x]]*Sin[c + d*x])/(3*d*Sqrt[Cos[c + d*x]]) + (b^2*C*Cos[c + d*x]^(3/2)*Sqrt[b*Cos[c + d*x]]*Sin[c + d*x])/(3*d)}
{((b*Cos[c + d*x])^(5/2)*(A + C*Cos[c + d*x]^2))/Cos[c + d*x]^(5/2), x, 3, (A*b^2*x*Sqrt[b*Cos[c + d*x]])/Sqrt[Cos[c + d*x]] + (b^2*C*x*Sqrt[b*Cos[c + d*x]])/(2*Sqrt[Cos[c + d*x]]) + (b^2*C*Sqrt[Cos[c + d*x]]*Sqrt[b*Cos[c + d*x]]*Sin[c + d*x])/(2*d)}
{((b*Cos[c + d*x])^(5/2)*(A + C*Cos[c + d*x]^2))/Cos[c + d*x]^(7/2), x, 3, (A*b^2*ArcTanh[Sin[c + d*x]]*Sqrt[b*Cos[c + d*x]])/(d*Sqrt[Cos[c + d*x]]) + (b^2*C*Sqrt[b*Cos[c + d*x]]*Sin[c + d*x])/(d*Sqrt[Cos[c + d*x]])}
{((b*Cos[c + d*x])^(5/2)*(A + C*Cos[c + d*x]^2))/Cos[c + d*x]^(9/2), x, 3, (b^2*C*x*Sqrt[b*Cos[c + d*x]])/Sqrt[Cos[c + d*x]] + (A*b^2*Sqrt[b*Cos[c + d*x]]*Sin[c + d*x])/(d*Cos[c + d*x]^(3/2))}
{((b*Cos[c + d*x])^(5/2)*(A + C*Cos[c + d*x]^2))/Cos[c + d*x]^(11/2), x, 3, (b^2*(A + 2*C)*ArcTanh[Sin[c + d*x]]*Sqrt[b*Cos[c + d*x]])/(2*d*Sqrt[Cos[c + d*x]]) + (A*b^2*Sqrt[b*Cos[c + d*x]]*Sin[c + d*x])/(2*d*Cos[c + d*x]^(5/2))}
{((b*Cos[c + d*x])^(5/2)*(A + C*Cos[c + d*x]^2))/Cos[c + d*x]^(13/2), x, 3, (A*b^2*Sqrt[b*Cos[c + d*x]]*Sin[c + d*x])/(3*d*Cos[c + d*x]^(7/2)) + (b^2*(2*A + 3*C)*Sqrt[b*Cos[c + d*x]]*Sin[c + d*x])/(3*d*Cos[c + d*x]^(3/2))}
{((b*Cos[c + d*x])^(5/2)*(A + C*Cos[c + d*x]^2))/Cos[c + d*x]^(15/2), x, 4, (b^2*(3*A + 4*C)*ArcTanh[Sin[c + d*x]]*Sqrt[b*Cos[c + d*x]])/(8*d*Sqrt[Cos[c + d*x]]) + (A*b^2*Sqrt[b*Cos[c + d*x]]*Sin[c + d*x])/(4*d*Cos[c + d*x]^(9/2)) + (b^2*(3*A + 4*C)*Sqrt[b*Cos[c + d*x]]*Sin[c + d*x])/(8*d*Cos[c + d*x]^(5/2))}


(* ::Subsubsection::Closed:: *)
(*n<0*)


{(Cos[c + d*x]^(5/2)*(A + C*Cos[c + d*x]^2))/Sqrt[b*Cos[c + d*x]], x, 3, ((4*A + 3*C)*x*Sqrt[Cos[c + d*x]])/(8*Sqrt[b*Cos[c + d*x]]) + ((4*A + 3*C)*Cos[c + d*x]^(3/2)*Sin[c + d*x])/(8*d*Sqrt[b*Cos[c + d*x]]) + (C*Cos[c + d*x]^(7/2)*Sin[c + d*x])/(4*d*Sqrt[b*Cos[c + d*x]])}
{(Cos[c + d*x]^(3/2)*(A + C*Cos[c + d*x]^2))/Sqrt[b*Cos[c + d*x]], x, 3, ((3*A + 2*C)*Sqrt[Cos[c + d*x]]*Sin[c + d*x])/(3*d*Sqrt[b*Cos[c + d*x]]) + (C*Cos[c + d*x]^(5/2)*Sin[c + d*x])/(3*d*Sqrt[b*Cos[c + d*x]])}
{(Sqrt[Cos[c + d*x]]*(A + C*Cos[c + d*x]^2))/Sqrt[b*Cos[c + d*x]], x, 3, (A*x*Sqrt[Cos[c + d*x]])/Sqrt[b*Cos[c + d*x]] + (C*x*Sqrt[Cos[c + d*x]])/(2*Sqrt[b*Cos[c + d*x]]) + (C*Cos[c + d*x]^(3/2)*Sin[c + d*x])/(2*d*Sqrt[b*Cos[c + d*x]])}
{(A + C*Cos[c + d*x]^2)/(Sqrt[Cos[c + d*x]]*Sqrt[b*Cos[c + d*x]]), x, 3, (A*ArcTanh[Sin[c + d*x]]*Sqrt[Cos[c + d*x]])/(d*Sqrt[b*Cos[c + d*x]]) + (C*Sqrt[Cos[c + d*x]]*Sin[c + d*x])/(d*Sqrt[b*Cos[c + d*x]])}
{(A + C*Cos[c + d*x]^2)/(Cos[c + d*x]^(3/2)*Sqrt[b*Cos[c + d*x]]), x, 3, (C*x*Sqrt[Cos[c + d*x]])/Sqrt[b*Cos[c + d*x]] + (A*Sin[c + d*x])/(d*Sqrt[Cos[c + d*x]]*Sqrt[b*Cos[c + d*x]])}
{(A + C*Cos[c + d*x]^2)/(Cos[c + d*x]^(5/2)*Sqrt[b*Cos[c + d*x]]), x, 3, ((A + 2*C)*ArcTanh[Sin[c + d*x]]*Sqrt[Cos[c + d*x]])/(2*d*Sqrt[b*Cos[c + d*x]]) + (A*Sin[c + d*x])/(2*d*Cos[c + d*x]^(3/2)*Sqrt[b*Cos[c + d*x]])}
{(A + C*Cos[c + d*x]^2)/(Cos[c + d*x]^(7/2)*Sqrt[b*Cos[c + d*x]]), x, 3, (A*Sin[c + d*x])/(3*d*Cos[c + d*x]^(5/2)*Sqrt[b*Cos[c + d*x]]) + ((2*A + 3*C)*Sin[c + d*x])/(3*d*Sqrt[Cos[c + d*x]]*Sqrt[b*Cos[c + d*x]])}
{(A + C*Cos[c + d*x]^2)/(Cos[c + d*x]^(9/2)*Sqrt[b*Cos[c + d*x]]), x, 4, ((3*A + 4*C)*ArcTanh[Sin[c + d*x]]*Sqrt[Cos[c + d*x]])/(8*d*Sqrt[b*Cos[c + d*x]]) + (A*Sin[c + d*x])/(4*d*Cos[c + d*x]^(7/2)*Sqrt[b*Cos[c + d*x]]) + ((3*A + 4*C)*Sin[c + d*x])/(8*d*Cos[c + d*x]^(3/2)*Sqrt[b*Cos[c + d*x]])}


{(Cos[c + d*x]^(7/2)*(A + C*Cos[c + d*x]^2))/(b*Cos[c + d*x])^(3/2), x, 3, ((4*A + 3*C)*x*Sqrt[Cos[c + d*x]])/(8*b*Sqrt[b*Cos[c + d*x]]) + ((4*A + 3*C)*Cos[c + d*x]^(3/2)*Sin[c + d*x])/(8*b*d*Sqrt[b*Cos[c + d*x]]) + (C*Cos[c + d*x]^(7/2)*Sin[c + d*x])/(4*b*d*Sqrt[b*Cos[c + d*x]])}
{(Cos[c + d*x]^(5/2)*(A + C*Cos[c + d*x]^2))/(b*Cos[c + d*x])^(3/2), x, 3, ((3*A + 2*C)*Sqrt[Cos[c + d*x]]*Sin[c + d*x])/(3*b*d*Sqrt[b*Cos[c + d*x]]) + (C*Cos[c + d*x]^(5/2)*Sin[c + d*x])/(3*b*d*Sqrt[b*Cos[c + d*x]])}
{(Cos[c + d*x]^(3/2)*(A + C*Cos[c + d*x]^2))/(b*Cos[c + d*x])^(3/2), x, 3, (A*x*Sqrt[Cos[c + d*x]])/(b*Sqrt[b*Cos[c + d*x]]) + (C*x*Sqrt[Cos[c + d*x]])/(2*b*Sqrt[b*Cos[c + d*x]]) + (C*Cos[c + d*x]^(3/2)*Sin[c + d*x])/(2*b*d*Sqrt[b*Cos[c + d*x]])}
{(Sqrt[Cos[c + d*x]]*(A + C*Cos[c + d*x]^2))/(b*Cos[c + d*x])^(3/2), x, 3, (A*ArcTanh[Sin[c + d*x]]*Sqrt[Cos[c + d*x]])/(b*d*Sqrt[b*Cos[c + d*x]]) + (C*Sqrt[Cos[c + d*x]]*Sin[c + d*x])/(b*d*Sqrt[b*Cos[c + d*x]])}
{(A + C*Cos[c + d*x]^2)/(Sqrt[Cos[c + d*x]]*(b*Cos[c + d*x])^(3/2)), x, 3, (C*x*Sqrt[Cos[c + d*x]])/(b*Sqrt[b*Cos[c + d*x]]) + (A*Sin[c + d*x])/(b*d*Sqrt[Cos[c + d*x]]*Sqrt[b*Cos[c + d*x]])}
{(A + C*Cos[c + d*x]^2)/(Cos[c + d*x]^(3/2)*(b*Cos[c + d*x])^(3/2)), x, 3, ((A + 2*C)*ArcTanh[Sin[c + d*x]]*Sqrt[Cos[c + d*x]])/(2*b*d*Sqrt[b*Cos[c + d*x]]) + (A*Sin[c + d*x])/(2*b*d*Cos[c + d*x]^(3/2)*Sqrt[b*Cos[c + d*x]])}
{(A + C*Cos[c + d*x]^2)/(Cos[c + d*x]^(5/2)*(b*Cos[c + d*x])^(3/2)), x, 3, (A*Sin[c + d*x])/(3*b*d*Cos[c + d*x]^(5/2)*Sqrt[b*Cos[c + d*x]]) + ((2*A + 3*C)*Sin[c + d*x])/(3*b*d*Sqrt[Cos[c + d*x]]*Sqrt[b*Cos[c + d*x]])}
{(A + C*Cos[c + d*x]^2)/(Cos[c + d*x]^(7/2)*(b*Cos[c + d*x])^(3/2)), x, 4, ((3*A + 4*C)*ArcTanh[Sin[c + d*x]]*Sqrt[Cos[c + d*x]])/(8*b*d*Sqrt[b*Cos[c + d*x]]) + (A*Sin[c + d*x])/(4*b*d*Cos[c + d*x]^(7/2)*Sqrt[b*Cos[c + d*x]]) + ((3*A + 4*C)*Sin[c + d*x])/(8*b*d*Cos[c + d*x]^(3/2)*Sqrt[b*Cos[c + d*x]])}


{(Cos[c + d*x]^(9/2)*(A + C*Cos[c + d*x]^2))/(b*Cos[c + d*x])^(5/2), x, 3, ((4*A + 3*C)*x*Sqrt[Cos[c + d*x]])/(8*b^2*Sqrt[b*Cos[c + d*x]]) + ((4*A + 3*C)*Cos[c + d*x]^(3/2)*Sin[c + d*x])/(8*b^2*d*Sqrt[b*Cos[c + d*x]]) + (C*Cos[c + d*x]^(7/2)*Sin[c + d*x])/(4*b^2*d*Sqrt[b*Cos[c + d*x]])}
{(Cos[c + d*x]^(7/2)*(A + C*Cos[c + d*x]^2))/(b*Cos[c + d*x])^(5/2), x, 3, ((3*A + 2*C)*Sqrt[Cos[c + d*x]]*Sin[c + d*x])/(3*b^2*d*Sqrt[b*Cos[c + d*x]]) + (C*Cos[c + d*x]^(5/2)*Sin[c + d*x])/(3*b^2*d*Sqrt[b*Cos[c + d*x]])}
{(Cos[c + d*x]^(5/2)*(A + C*Cos[c + d*x]^2))/(b*Cos[c + d*x])^(5/2), x, 3, (A*x*Sqrt[Cos[c + d*x]])/(b^2*Sqrt[b*Cos[c + d*x]]) + (C*x*Sqrt[Cos[c + d*x]])/(2*b^2*Sqrt[b*Cos[c + d*x]]) + (C*Cos[c + d*x]^(3/2)*Sin[c + d*x])/(2*b^2*d*Sqrt[b*Cos[c + d*x]])}
{(Cos[c + d*x]^(3/2)*(A + C*Cos[c + d*x]^2))/(b*Cos[c + d*x])^(5/2), x, 3, (A*ArcTanh[Sin[c + d*x]]*Sqrt[Cos[c + d*x]])/(b^2*d*Sqrt[b*Cos[c + d*x]]) + (C*Sqrt[Cos[c + d*x]]*Sin[c + d*x])/(b^2*d*Sqrt[b*Cos[c + d*x]])}
{(Sqrt[Cos[c + d*x]]*(A + C*Cos[c + d*x]^2))/(b*Cos[c + d*x])^(5/2), x, 3, (C*x*Sqrt[Cos[c + d*x]])/(b^2*Sqrt[b*Cos[c + d*x]]) + (A*Sin[c + d*x])/(b^2*d*Sqrt[Cos[c + d*x]]*Sqrt[b*Cos[c + d*x]])}
{(A + C*Cos[c + d*x]^2)/(Sqrt[Cos[c + d*x]]*(b*Cos[c + d*x])^(5/2)), x, 3, ((A + 2*C)*ArcTanh[Sin[c + d*x]]*Sqrt[Cos[c + d*x]])/(2*b^2*d*Sqrt[b*Cos[c + d*x]]) + (A*Sin[c + d*x])/(2*b^2*d*Cos[c + d*x]^(3/2)*Sqrt[b*Cos[c + d*x]])}
{(A + C*Cos[c + d*x]^2)/(Cos[c + d*x]^(3/2)*(b*Cos[c + d*x])^(5/2)), x, 3, (A*Sin[c + d*x])/(3*b^2*d*Cos[c + d*x]^(5/2)*Sqrt[b*Cos[c + d*x]]) + ((2*A + 3*C)*Sin[c + d*x])/(3*b^2*d*Sqrt[Cos[c + d*x]]*Sqrt[b*Cos[c + d*x]])}
{(A + C*Cos[c + d*x]^2)/(Cos[c + d*x]^(5/2)*(b*Cos[c + d*x])^(5/2)), x, 4, ((3*A + 4*C)*ArcTanh[Sin[c + d*x]]*Sqrt[Cos[c + d*x]])/(8*b^2*d*Sqrt[b*Cos[c + d*x]]) + (A*Sin[c + d*x])/(4*b^2*d*Cos[c + d*x]^(7/2)*Sqrt[b*Cos[c + d*x]]) + ((3*A + 4*C)*Sin[c + d*x])/(8*b^2*d*Cos[c + d*x]^(3/2)*Sqrt[b*Cos[c + d*x]])}


(* ::Subsection::Closed:: *)
(*Integrands of the form Cos[c+d x]^m (A+C Cos[c+d x]^2) (b Cos[c+d x])^(n/3)*)


(* ::Subsubsection::Closed:: *)
(*n>0*)


{Cos[c + d*x]^m*(b*Cos[c + d*x])^(1/3)*(A + C*Cos[c + d*x]^2), x, 3, (3*C*Cos[c + d*x]^(1 + m)*(b*Cos[c + d*x])^(1/3)*Sin[c + d*x])/(d*(7 + 3*m)) + ((C*(4 + 3*m) + A*(7 + 3*m))*Cos[c + d*x]^(1 + m)*(b*Cos[c + d*x])^(1/3)*(Cos[c + d*x]^2)^((1/6)*(-4 - 3*m))*Hypergeometric2F1[1/2, (1/6)*(2 - 3*m), 3/2, Sin[c + d*x]^2]*Sin[c + d*x])/(d*(7 + 3*m))}

{Cos[c + d*x]^2*(b*Cos[c + d*x])^(1/3)*(A + C*Cos[c + d*x]^2), x, 5, (3*(13*A + 10*C)*(b*Cos[c + d*x])^(4/3)*Sin[c + d*x])/(91*b*d) + (3*C*(b*Cos[c + d*x])^(10/3)*Sin[c + d*x])/(13*b^3*d) + (4*b*(13*A + 10*C)*(Cos[c + d*x]^2)^(1/3)*Hypergeometric2F1[1/3, 1/2, 3/2, Sin[c + d*x]^2]*Sin[c + d*x])/(91*d*(b*Cos[c + d*x])^(2/3))}
{Cos[c + d*x]*(b*Cos[c + d*x])^(1/3)*(A + C*Cos[c + d*x]^2), x, 5, (3*(10*A + 7*C)*(b*Cos[c + d*x])^(1/3)*Sin[c + d*x])/(40*d) + (3*C*(b*Cos[c + d*x])^(7/3)*Sin[c + d*x])/(10*b^2*d) + ((10*A + 7*C)*(b*Cos[c + d*x])^(1/3)*Hypergeometric2F1[1/2, 5/6, 3/2, Sin[c + d*x]^2]*Sin[c + d*x])/(40*d*(Cos[c + d*x]^2)^(1/6))}
{(b*Cos[c + d*x])^(1/3)*(A + C*Cos[c + d*x]^2), x, 3, (3*C*(b*Cos[c + d*x])^(4/3)*Sin[c + d*x])/(7*b*d) + (b*(7*A + 4*C)*(Cos[c + d*x]^2)^(1/3)*Hypergeometric2F1[1/3, 1/2, 3/2, Sin[c + d*x]^2]*Sin[c + d*x])/(7*d*(b*Cos[c + d*x])^(2/3))}
{(b*Cos[c + d*x])^(1/3)*(A + C*Cos[c + d*x]^2)*Sec[c + d*x], x, 4, (3*C*(b*Cos[c + d*x])^(1/3)*Sin[c + d*x])/(4*d) + ((4*A + C)*(b*Cos[c + d*x])^(1/3)*Hypergeometric2F1[1/2, 5/6, 3/2, Sin[c + d*x]^2]*Sin[c + d*x])/(4*d*(Cos[c + d*x]^2)^(1/6))}
{(b*Cos[c + d*x])^(1/3)*(A + C*Cos[c + d*x]^2)*Sec[c + d*x]^2, x, 4, (3*A*b*Sin[c + d*x])/(2*d*(b*Cos[c + d*x])^(2/3)) - (b*(A - 2*C)*(Cos[c + d*x]^2)^(1/3)*Hypergeometric2F1[1/3, 1/2, 3/2, Sin[c + d*x]^2]*Sin[c + d*x])/(2*d*(b*Cos[c + d*x])^(2/3))}
{(b*Cos[c + d*x])^(1/3)*(A + C*Cos[c + d*x]^2)*Sec[c + d*x]^3, x, 4, (3*A*b^2*Sin[c + d*x])/(5*d*(b*Cos[c + d*x])^(5/3)) + ((2*A + 5*C)*(b*Cos[c + d*x])^(1/3)*Hypergeometric2F1[1/2, 5/6, 3/2, Sin[c + d*x]^2]*Sin[c + d*x])/(5*d*(Cos[c + d*x]^2)^(1/6))}


{Cos[c + d*x]^m*(b*Cos[c + d*x])^(2/3)*(A + C*Cos[c + d*x]^2), x, 3, (3*C*Cos[c + d*x]^(1 + m)*(b*Cos[c + d*x])^(2/3)*Sin[c + d*x])/(d*(8 + 3*m)) + ((C*(5 + 3*m) + A*(8 + 3*m))*Cos[c + d*x]^(1 + m)*(b*Cos[c + d*x])^(2/3)*(Cos[c + d*x]^2)^((1/6)*(-5 - 3*m))*Hypergeometric2F1[1/2, (1/6)*(1 - 3*m), 3/2, Sin[c + d*x]^2]*Sin[c + d*x])/(d*(8 + 3*m))}

{Cos[c + d*x]^2*(b*Cos[c + d*x])^(2/3)*(A + C*Cos[c + d*x]^2), x, 5, (3*(14*A + 11*C)*(b*Cos[c + d*x])^(5/3)*Sin[c + d*x])/(112*b*d) + (3*C*(b*Cos[c + d*x])^(11/3)*Sin[c + d*x])/(14*b^3*d) + (5*b*(14*A + 11*C)*(Cos[c + d*x]^2)^(1/6)*Hypergeometric2F1[1/6, 1/2, 3/2, Sin[c + d*x]^2]*Sin[c + d*x])/(112*d*(b*Cos[c + d*x])^(1/3))}
{Cos[c + d*x]*(b*Cos[c + d*x])^(2/3)*(A + C*Cos[c + d*x]^2), x, 5, (3*(11*A + 8*C)*(b*Cos[c + d*x])^(2/3)*Sin[c + d*x])/(55*d) + (3*C*(b*Cos[c + d*x])^(8/3)*Sin[c + d*x])/(11*b^2*d) + (2*(11*A + 8*C)*(b*Cos[c + d*x])^(2/3)*Hypergeometric2F1[1/2, 2/3, 3/2, Sin[c + d*x]^2]*Sin[c + d*x])/(55*d*(Cos[c + d*x]^2)^(1/3))}
{(b*Cos[c + d*x])^(2/3)*(A + C*Cos[c + d*x]^2), x, 3, (3*C*(b*Cos[c + d*x])^(5/3)*Sin[c + d*x])/(8*b*d) + (b*(8*A + 5*C)*(Cos[c + d*x]^2)^(1/6)*Hypergeometric2F1[1/6, 1/2, 3/2, Sin[c + d*x]^2]*Sin[c + d*x])/(8*d*(b*Cos[c + d*x])^(1/3))}
{(b*Cos[c + d*x])^(2/3)*(A + C*Cos[c + d*x]^2)*Sec[c + d*x], x, 4, (3*C*(b*Cos[c + d*x])^(2/3)*Sin[c + d*x])/(5*d) + ((5*A + 2*C)*(b*Cos[c + d*x])^(2/3)*Hypergeometric2F1[1/2, 2/3, 3/2, Sin[c + d*x]^2]*Sin[c + d*x])/(5*d*(Cos[c + d*x]^2)^(1/3))}
{(b*Cos[c + d*x])^(2/3)*(A + C*Cos[c + d*x]^2)*Sec[c + d*x]^2, x, 4, (3*A*b*Sin[c + d*x])/(d*(b*Cos[c + d*x])^(1/3)) - (b*(2*A - C)*(Cos[c + d*x]^2)^(1/6)*Hypergeometric2F1[1/6, 1/2, 3/2, Sin[c + d*x]^2]*Sin[c + d*x])/(d*(b*Cos[c + d*x])^(1/3))}
{(b*Cos[c + d*x])^(2/3)*(A + C*Cos[c + d*x]^2)*Sec[c + d*x]^3, x, 4, (3*A*b^2*Sin[c + d*x])/(4*d*(b*Cos[c + d*x])^(4/3)) + ((A + 4*C)*(b*Cos[c + d*x])^(2/3)*Hypergeometric2F1[1/2, 2/3, 3/2, Sin[c + d*x]^2]*Sin[c + d*x])/(4*d*(Cos[c + d*x]^2)^(1/3))}


{Cos[c + d*x]^m*(b*Cos[c + d*x])^(4/3)*(A + C*Cos[c + d*x]^2), x, 3, (3*C*Cos[c + d*x]^(1 + m)*(b*Cos[c + d*x])^(4/3)*Sin[c + d*x])/(d*(10 + 3*m)) + ((C*(7 + 3*m) + A*(10 + 3*m))*Cos[c + d*x]^(1 + m)*(b*Cos[c + d*x])^(4/3)*(Cos[c + d*x]^2)^((1/6)*(-7 - 3*m))*Hypergeometric2F1[1/2, (1/6)*(-1 - 3*m), 3/2, Sin[c + d*x]^2]*Sin[c + d*x])/(d*(10 + 3*m))}

{Cos[c + d*x]^2*(b*Cos[c + d*x])^(4/3)*(A + C*Cos[c + d*x]^2), x, 6, (21*b*(16*A + 13*C)*(b*Cos[c + d*x])^(1/3)*Sin[c + d*x])/(640*d) + (3*(16*A + 13*C)*(b*Cos[c + d*x])^(7/3)*Sin[c + d*x])/(160*b*d) + (3*C*(b*Cos[c + d*x])^(13/3)*Sin[c + d*x])/(16*b^3*d) + (7*b*(16*A + 13*C)*(b*Cos[c + d*x])^(1/3)*Hypergeometric2F1[1/2, 5/6, 3/2, Sin[c + d*x]^2]*Sin[c + d*x])/(640*d*(Cos[c + d*x]^2)^(1/6))}
{Cos[c + d*x]*(b*Cos[c + d*x])^(4/3)*(A + C*Cos[c + d*x]^2), x, 5, (3*(13*A + 10*C)*(b*Cos[c + d*x])^(4/3)*Sin[c + d*x])/(91*d) + (3*C*(b*Cos[c + d*x])^(10/3)*Sin[c + d*x])/(13*b^2*d) + (4*b^2*(13*A + 10*C)*(Cos[c + d*x]^2)^(1/3)*Hypergeometric2F1[1/3, 1/2, 3/2, Sin[c + d*x]^2]*Sin[c + d*x])/(91*d*(b*Cos[c + d*x])^(2/3))}
{(b*Cos[c + d*x])^(4/3)*(A + C*Cos[c + d*x]^2), x, 4, (3*b*(10*A + 7*C)*(b*Cos[c + d*x])^(1/3)*Sin[c + d*x])/(40*d) + (3*C*(b*Cos[c + d*x])^(7/3)*Sin[c + d*x])/(10*b*d) + (b*(10*A + 7*C)*(b*Cos[c + d*x])^(1/3)*Hypergeometric2F1[1/2, 5/6, 3/2, Sin[c + d*x]^2]*Sin[c + d*x])/(40*d*(Cos[c + d*x]^2)^(1/6))}
{(b*Cos[c + d*x])^(4/3)*(A + C*Cos[c + d*x]^2)*Sec[c + d*x], x, 4, (3*C*(b*Cos[c + d*x])^(4/3)*Sin[c + d*x])/(7*d) + (b^2*(7*A + 4*C)*(Cos[c + d*x]^2)^(1/3)*Hypergeometric2F1[1/3, 1/2, 3/2, Sin[c + d*x]^2]*Sin[c + d*x])/(7*d*(b*Cos[c + d*x])^(2/3))}
{(b*Cos[c + d*x])^(4/3)*(A + C*Cos[c + d*x]^2)*Sec[c + d*x]^2, x, 4, (3*b*C*(b*Cos[c + d*x])^(1/3)*Sin[c + d*x])/(4*d) + (b*(4*A + C)*(b*Cos[c + d*x])^(1/3)*Hypergeometric2F1[1/2, 5/6, 3/2, Sin[c + d*x]^2]*Sin[c + d*x])/(4*d*(Cos[c + d*x]^2)^(1/6))}
{(b*Cos[c + d*x])^(4/3)*(A + C*Cos[c + d*x]^2)*Sec[c + d*x]^3, x, 4, (3*A*b^2*Sin[c + d*x])/(2*d*(b*Cos[c + d*x])^(2/3)) - (b^2*(A - 2*C)*(Cos[c + d*x]^2)^(1/3)*Hypergeometric2F1[1/3, 1/2, 3/2, Sin[c + d*x]^2]*Sin[c + d*x])/(2*d*(b*Cos[c + d*x])^(2/3))}


(* ::Subsubsection::Closed:: *)
(*n<0*)


{(Cos[c + d*x]^m*(A + C*Cos[c + d*x]^2))/(b*Cos[c + d*x])^(1/3), x, 3, (3*C*Cos[c + d*x]^(1 + m)*Sin[c + d*x])/(d*(5 + 3*m)*(b*Cos[c + d*x])^(1/3)) + ((C*(2 + 3*m) + A*(5 + 3*m))*Cos[c + d*x]^(1 + m)*(Cos[c + d*x]^2)^((1/6)*(-2 - 3*m))*Hypergeometric2F1[1/2, (1/6)*(4 - 3*m), 3/2, Sin[c + d*x]^2]*Sin[c + d*x])/(d*(5 + 3*m)*(b*Cos[c + d*x])^(1/3))}

{(Cos[c + d*x]^2*(A + C*Cos[c + d*x]^2))/(b*Cos[c + d*x])^(1/3), x, 5, (3*(11*A + 8*C)*(b*Cos[c + d*x])^(2/3)*Sin[c + d*x])/(55*b*d) + (3*C*(b*Cos[c + d*x])^(8/3)*Sin[c + d*x])/(11*b^3*d) + (2*(11*A + 8*C)*(b*Cos[c + d*x])^(2/3)*Hypergeometric2F1[1/2, 2/3, 3/2, Sin[c + d*x]^2]*Sin[c + d*x])/(55*b*d*(Cos[c + d*x]^2)^(1/3))}
{(Cos[c + d*x]*(A + C*Cos[c + d*x]^2))/(b*Cos[c + d*x])^(1/3), x, 4, (3*C*(b*Cos[c + d*x])^(5/3)*Sin[c + d*x])/(8*b^2*d) + ((8*A + 5*C)*(Cos[c + d*x]^2)^(1/6)*Hypergeometric2F1[1/6, 1/2, 3/2, Sin[c + d*x]^2]*Sin[c + d*x])/(8*d*(b*Cos[c + d*x])^(1/3))}
{(A + C*Cos[c + d*x]^2)/(b*Cos[c + d*x])^(1/3), x, 3, (3*C*(b*Cos[c + d*x])^(2/3)*Sin[c + d*x])/(5*b*d) + ((5*A + 2*C)*(b*Cos[c + d*x])^(2/3)*Hypergeometric2F1[1/2, 2/3, 3/2, Sin[c + d*x]^2]*Sin[c + d*x])/(5*b*d*(Cos[c + d*x]^2)^(1/3))}
{((A + C*Cos[c + d*x]^2)*Sec[c + d*x])/(b*Cos[c + d*x])^(1/3), x, 4, (3*A*Sin[c + d*x])/(d*(b*Cos[c + d*x])^(1/3)) - ((2*A - C)*(Cos[c + d*x]^2)^(1/6)*Hypergeometric2F1[1/6, 1/2, 3/2, Sin[c + d*x]^2]*Sin[c + d*x])/(d*(b*Cos[c + d*x])^(1/3))}
{((A + C*Cos[c + d*x]^2)*Sec[c + d*x]^2)/(b*Cos[c + d*x])^(1/3), x, 4, (3*A*b*Sin[c + d*x])/(4*d*(b*Cos[c + d*x])^(4/3)) + ((A + 4*C)*(b*Cos[c + d*x])^(2/3)*Hypergeometric2F1[1/2, 2/3, 3/2, Sin[c + d*x]^2]*Sin[c + d*x])/(4*b*d*(Cos[c + d*x]^2)^(1/3))}
{((A + C*Cos[c + d*x]^2)*Sec[c + d*x]^3)/(b*Cos[c + d*x])^(1/3), x, 5, (3*A*b^2*Sin[c + d*x])/(7*d*(b*Cos[c + d*x])^(7/3)) + (3*(4*A + 7*C)*Sin[c + d*x])/(7*d*(b*Cos[c + d*x])^(1/3)) - (2*(4*A + 7*C)*(Cos[c + d*x]^2)^(1/6)*Hypergeometric2F1[1/6, 1/2, 3/2, Sin[c + d*x]^2]*Sin[c + d*x])/(7*d*(b*Cos[c + d*x])^(1/3))}


{(Cos[c + d*x]^m*(A + C*Cos[c + d*x]^2))/(b*Cos[c + d*x])^(2/3), x, 3, (3*C*Cos[c + d*x]^(1 + m)*Sin[c + d*x])/(d*(4 + 3*m)*(b*Cos[c + d*x])^(2/3)) + ((C + 3*C*m + A*(4 + 3*m))*Cos[c + d*x]^(1 + m)*(Cos[c + d*x]^2)^((-1 - 3*m)/6)*Hypergeometric2F1[1/2, (5 - 3*m)/6, 3/2, Sin[c + d*x]^2]*Sin[c + d*x])/(d*(4 + 3*m)*(b*Cos[c + d*x])^(2/3))}

{(Cos[c + d*x]^2*(A + C*Cos[c + d*x]^2))/(b*Cos[c + d*x])^(2/3), x, 5, (3*(10*A + 7*C)*(b*Cos[c + d*x])^(1/3)*Sin[c + d*x])/(40*b*d) + (3*C*(b*Cos[c + d*x])^(7/3)*Sin[c + d*x])/(10*b^3*d) + ((10*A + 7*C)*(b*Cos[c + d*x])^(1/3)*Hypergeometric2F1[1/2, 5/6, 3/2, Sin[c + d*x]^2]*Sin[c + d*x])/(40*b*d*(Cos[c + d*x]^2)^(1/6))}
{(Cos[c + d*x]*(A + C*Cos[c + d*x]^2))/(b*Cos[c + d*x])^(2/3), x, 4, (3*C*(b*Cos[c + d*x])^(4/3)*Sin[c + d*x])/(7*b^2*d) + ((7*A + 4*C)*(Cos[c + d*x]^2)^(1/3)*Hypergeometric2F1[1/3, 1/2, 3/2, Sin[c + d*x]^2]*Sin[c + d*x])/(7*d*(b*Cos[c + d*x])^(2/3))}
{(A + C*Cos[c + d*x]^2)/(b*Cos[c + d*x])^(2/3), x, 3, (3*C*(b*Cos[c + d*x])^(1/3)*Sin[c + d*x])/(4*b*d) + ((4*A + C)*(b*Cos[c + d*x])^(1/3)*Hypergeometric2F1[1/2, 5/6, 3/2, Sin[c + d*x]^2]*Sin[c + d*x])/(4*b*d*(Cos[c + d*x]^2)^(1/6))}
{((A + C*Cos[c + d*x]^2)*Sec[c + d*x])/(b*Cos[c + d*x])^(2/3), x, 4, (3*A*Sin[c + d*x])/(2*d*(b*Cos[c + d*x])^(2/3)) - ((A - 2*C)*(Cos[c + d*x]^2)^(1/3)*Hypergeometric2F1[1/3, 1/2, 3/2, Sin[c + d*x]^2]*Sin[c + d*x])/(2*d*(b*Cos[c + d*x])^(2/3))}
{((A + C*Cos[c + d*x]^2)*Sec[c + d*x]^2)/(b*Cos[c + d*x])^(2/3), x, 4, (3*A*b*Sin[c + d*x])/(5*d*(b*Cos[c + d*x])^(5/3)) + ((2*A + 5*C)*(b*Cos[c + d*x])^(1/3)*Hypergeometric2F1[1/2, 5/6, 3/2, Sin[c + d*x]^2]*Sin[c + d*x])/(5*b*d*(Cos[c + d*x]^2)^(1/6))}
{((A + C*Cos[c + d*x]^2)*Sec[c + d*x]^3)/(b*Cos[c + d*x])^(2/3), x, 5, (3*A*b^2*Sin[c + d*x])/(8*d*(b*Cos[c + d*x])^(8/3)) + (3*(5*A + 8*C)*Sin[c + d*x])/(16*d*(b*Cos[c + d*x])^(2/3)) - ((5*A + 8*C)*(Cos[c + d*x]^2)^(1/3)*Hypergeometric2F1[1/3, 1/2, 3/2, Sin[c + d*x]^2]*Sin[c + d*x])/(16*d*(b*Cos[c + d*x])^(2/3))}


{(Cos[c + d*x]^m*(A + C*Cos[c + d*x]^2))/(b*Cos[c + d*x])^(4/3), x, 3, (3*C*Cos[c + d*x]^(1 + m)*Sin[c + d*x])/(d*(2 + 3*m)*(b*Cos[c + d*x])^(4/3)) - ((C*(1 - 3*m) - A*(2 + 3*m))*Cos[c + d*x]^(1 + m)*(Cos[c + d*x]^2)^((1 - 3*m)/6)*Hypergeometric2F1[1/2, (7 - 3*m)/6, 3/2, Sin[c + d*x]^2]*Sin[c + d*x])/(d*(2 + 3*m)*(b*Cos[c + d*x])^(4/3))}

{(Cos[c + d*x]^2*(A + C*Cos[c + d*x]^2))/(b*Cos[c + d*x])^(4/3), x, 4, (3*C*(b*Cos[c + d*x])^(5/3)*Sin[c + d*x])/(8*b^3*d) + ((8*A + 5*C)*(Cos[c + d*x]^2)^(1/6)*Hypergeometric2F1[1/6, 1/2, 3/2, Sin[c + d*x]^2]*Sin[c + d*x])/(8*b*d*(b*Cos[c + d*x])^(1/3))}
{(Cos[c + d*x]*(A + C*Cos[c + d*x]^2))/(b*Cos[c + d*x])^(4/3), x, 4, (3*C*(b*Cos[c + d*x])^(2/3)*Sin[c + d*x])/(5*b^2*d) + ((5*A + 2*C)*(b*Cos[c + d*x])^(2/3)*Hypergeometric2F1[1/2, 2/3, 3/2, Sin[c + d*x]^2]*Sin[c + d*x])/(5*b^2*d*(Cos[c + d*x]^2)^(1/3))}
{(A + C*Cos[c + d*x]^2)/(b*Cos[c + d*x])^(4/3), x, 3, (3*A*Sin[c + d*x])/(b*d*(b*Cos[c + d*x])^(1/3)) - ((2*A - C)*(Cos[c + d*x]^2)^(1/6)*Hypergeometric2F1[1/6, 1/2, 3/2, Sin[c + d*x]^2]*Sin[c + d*x])/(b*d*(b*Cos[c + d*x])^(1/3))}
{((A + C*Cos[c + d*x]^2)*Sec[c + d*x])/(b*Cos[c + d*x])^(4/3), x, 4, (3*A*Sin[c + d*x])/(4*d*(b*Cos[c + d*x])^(4/3)) + ((A + 4*C)*(b*Cos[c + d*x])^(2/3)*Hypergeometric2F1[1/2, 2/3, 3/2, Sin[c + d*x]^2]*Sin[c + d*x])/(4*b^2*d*(Cos[c + d*x]^2)^(1/3))}
{((A + C*Cos[c + d*x]^2)*Sec[c + d*x]^2)/(b*Cos[c + d*x])^(4/3), x, 5, (3*A*b*Sin[c + d*x])/(7*d*(b*Cos[c + d*x])^(7/3)) + (3*(4*A + 7*C)*Sin[c + d*x])/(7*b*d*(b*Cos[c + d*x])^(1/3)) - (2*(4*A + 7*C)*(Cos[c + d*x]^2)^(1/6)*Hypergeometric2F1[1/6, 1/2, 3/2, Sin[c + d*x]^2]*Sin[c + d*x])/(7*b*d*(b*Cos[c + d*x])^(1/3))}
{((A + C*Cos[c + d*x]^2)*Sec[c + d*x]^3)/(b*Cos[c + d*x])^(4/3), x, 5, (3*A*b^2*Sin[c + d*x])/(10*d*(b*Cos[c + d*x])^(10/3)) + (3*(7*A + 10*C)*Sin[c + d*x])/(40*d*(b*Cos[c + d*x])^(4/3)) + ((7*A + 10*C)*(b*Cos[c + d*x])^(2/3)*Hypergeometric2F1[1/2, 2/3, 3/2, Sin[c + d*x]^2]*Sin[c + d*x])/(40*b^2*d*(Cos[c + d*x]^2)^(1/3))}


(* ::Subsection::Closed:: *)
(*Integrands of the form Cos[c+d x]^m (A+C Cos[c+d x]^2) (b Cos[c+d x])^n when n symbolic*)


{Cos[c + d*x]^m*(b*Cos[c + d*x])^n*(A + C*Cos[c + d*x]^2), x, 3, (C*Cos[c + d*x]^(1 + m)*(b*Cos[c + d*x])^n*Sin[c + d*x])/(d*(2 + m + n)) + ((C*(1 + m + n) + A*(2 + m + n))*Cos[c + d*x]^(1 + m)*(b*Cos[c + d*x])^n*(Cos[c + d*x]^2)^((1/2)*(-1 - m - n))*Hypergeometric2F1[1/2, (1/2)*(1 - m - n), 3/2, Sin[c + d*x]^2]*Sin[c + d*x])/(d*(2 + m + n))}


{Cos[c + d*x]^2*(b*Cos[c + d*x])^n*(A + C*Cos[c + d*x]^2), x, 4, (C*(b*Cos[c + d*x])^(3 + n)*Sin[c + d*x])/(b^3*d*(4 + n)) + ((C*(3 + n) + A*(4 + n))*(b*Cos[c + d*x])^(3 + n)*(Cos[c + d*x]^2)^((1/2)*(-3 - n))*Hypergeometric2F1[1/2, (1/2)*(-1 - n), 3/2, Sin[c + d*x]^2]*Sin[c + d*x])/(b^3*d*(4 + n))}
{Cos[c + d*x]^1*(b*Cos[c + d*x])^n*(A + C*Cos[c + d*x]^2), x, 4, (C*(b*Cos[c + d*x])^(2 + n)*Sin[c + d*x])/(b^2*d*(3 + n)) + ((C*(2 + n) + A*(3 + n))*(b*Cos[c + d*x])^(2 + n)*(Cos[c + d*x]^2)^((1/2)*(-2 - n))*Hypergeometric2F1[1/2, -(n/2), 3/2, Sin[c + d*x]^2]*Sin[c + d*x])/(b^2*d*(3 + n))}
{Cos[c + d*x]^0*(b*Cos[c + d*x])^n*(A + C*Cos[c + d*x]^2), x, 3, (C*(b*Cos[c + d*x])^(1 + n)*Sin[c + d*x])/(b*d*(2 + n)) + ((C*(1 + n) + A*(2 + n))*(b*Cos[c + d*x])^(1 + n)*(Cos[c + d*x]^2)^((1/2)*(-1 - n))*Hypergeometric2F1[1/2, (1 - n)/2, 3/2, Sin[c + d*x]^2]*Sin[c + d*x])/(b*d*(2 + n))}
{(b*Cos[c + d*x])^n*(A + C*Cos[c + d*x]^2)*Sec[c + d*x]^1, x, 4, (C*(b*Cos[c + d*x])^n*Sin[c + d*x])/(d*(1 + n)) + ((A + A*n + C*n)*(b*Cos[c + d*x])^n*Hypergeometric2F1[1/2, (2 - n)/2, 3/2, Sin[c + d*x]^2]*Sin[c + d*x])/((Cos[c + d*x]^2)^(n/2)*(d*(1 + n)))}
{(b*Cos[c + d*x])^n*(A + C*Cos[c + d*x]^2)*Sec[c + d*x]^2, x, 4, (b*C*(b*Cos[c + d*x])^(-1 + n)*Sin[c + d*x])/(d*n) - (b*(C*(1 - n) - A*n)*(b*Cos[c + d*x])^(-1 + n)*(Cos[c + d*x]^2)^((1 - n)/2)*Hypergeometric2F1[1/2, (3 - n)/2, 3/2, Sin[c + d*x]^2]*Sin[c + d*x])/(d*n)}
{(b*Cos[c + d*x])^n*(A + C*Cos[c + d*x]^2)*Sec[c + d*x]^3, x, 4, -((b^2*C*(b*Cos[c + d*x])^(-2 + n)*Sin[c + d*x])/(d*(1 - n))) + (b^2*(A*(1 - n) + C*(2 - n))*(b*Cos[c + d*x])^(-2 + n)*(Cos[c + d*x]^2)^((2 - n)/2)*Hypergeometric2F1[1/2, (4 - n)/2, 3/2, Sin[c + d*x]^2]*Sin[c + d*x])/(d*(1 - n))}
{(b*Cos[c + d*x])^n*(A + C*Cos[c + d*x]^2)*Sec[c + d*x]^4, x, 4, -((b^3*C*(b*Cos[c + d*x])^(-3 + n)*Sin[c + d*x])/(d*(2 - n))) + (b^3*(A*(2 - n) + C*(3 - n))*(b*Cos[c + d*x])^(-3 + n)*(Cos[c + d*x]^2)^((3 - n)/2)*Hypergeometric2F1[1/2, (5 - n)/2, 3/2, Sin[c + d*x]^2]*Sin[c + d*x])/(d*(2 - n))}


{Cos[c + d*x]^(5/2)*(b*Cos[c + d*x])^n*(A + C*Cos[c + d*x]^2), x, 3, (2*C*Cos[c + d*x]^(7/2)*(b*Cos[c + d*x])^n*Sin[c + d*x])/(d*(9 + 2*n)) + ((C*(7 + 2*n) + A*(9 + 2*n))*Cos[c + d*x]^(7/2)*(b*Cos[c + d*x])^n*(Cos[c + d*x]^2)^((1/4)*(-7 - 2*n))*Hypergeometric2F1[1/2, (1/4)*(-3 - 2*n), 3/2, Sin[c + d*x]^2]*Sin[c + d*x])/(d*(9 + 2*n))}
{Cos[c + d*x]^(3/2)*(b*Cos[c + d*x])^n*(A + C*Cos[c + d*x]^2), x, 3, (2*C*Cos[c + d*x]^(5/2)*(b*Cos[c + d*x])^n*Sin[c + d*x])/(d*(7 + 2*n)) + ((C*(5 + 2*n) + A*(7 + 2*n))*Cos[c + d*x]^(5/2)*(b*Cos[c + d*x])^n*(Cos[c + d*x]^2)^((1/4)*(-5 - 2*n))*Hypergeometric2F1[1/2, (1/4)*(-1 - 2*n), 3/2, Sin[c + d*x]^2]*Sin[c + d*x])/(d*(7 + 2*n))}
{Sqrt[Cos[c + d*x]]*(b*Cos[c + d*x])^n*(A + C*Cos[c + d*x]^2), x, 3, (2*C*Cos[c + d*x]^(3/2)*(b*Cos[c + d*x])^n*Sin[c + d*x])/(d*(5 + 2*n)) + ((C*(3 + 2*n) + A*(5 + 2*n))*Cos[c + d*x]^(3/2)*(b*Cos[c + d*x])^n*(Cos[c + d*x]^2)^((1/4)*(-3 - 2*n))*Hypergeometric2F1[1/2, (1/4)*(1 - 2*n), 3/2, Sin[c + d*x]^2]*Sin[c + d*x])/(d*(5 + 2*n))}
{((b*Cos[c + d*x])^n*(A + C*Cos[c + d*x]^2))/Sqrt[Cos[c + d*x]], x, 3, (2*C*Sqrt[Cos[c + d*x]]*(b*Cos[c + d*x])^n*Sin[c + d*x])/(d*(3 + 2*n)) + ((C + 2*C*n + A*(3 + 2*n))*Sqrt[Cos[c + d*x]]*(b*Cos[c + d*x])^n*(Cos[c + d*x]^2)^((1/4)*(-1 - 2*n))*Hypergeometric2F1[1/2, (1/4)*(3 - 2*n), 3/2, Sin[c + d*x]^2]*Sin[c + d*x])/(d*(3 + 2*n))}
{((b*Cos[c + d*x])^n*(A + C*Cos[c + d*x]^2))/Cos[c + d*x]^(3/2), x, 3, (2*C*(b*Cos[c + d*x])^n*Sin[c + d*x])/(d*(1 + 2*n)*Sqrt[Cos[c + d*x]]) + ((A - C*(1 - 2*n) + 2*A*n)*(b*Cos[c + d*x])^n*(Cos[c + d*x]^2)^((1/4)*(1 - 2*n))*Hypergeometric2F1[1/2, (1/4)*(5 - 2*n), 3/2, Sin[c + d*x]^2]*Sin[c + d*x])/(d*(1 + 2*n)*Sqrt[Cos[c + d*x]])}
{((b*Cos[c + d*x])^n*(A + C*Cos[c + d*x]^2))/Cos[c + d*x]^(5/2), x, 3, -((2*C*(b*Cos[c + d*x])^n*Sin[c + d*x])/(d*(1 - 2*n)*Cos[c + d*x]^(3/2))) + ((A*(1 - 2*n) + C*(3 - 2*n))*(b*Cos[c + d*x])^n*(Cos[c + d*x]^2)^((1/4)*(3 - 2*n))*Hypergeometric2F1[1/2, (1/4)*(7 - 2*n), 3/2, Sin[c + d*x]^2]*Sin[c + d*x])/(d*(1 - 2*n)*Cos[c + d*x]^(3/2))}
{((b*Cos[c + d*x])^n*(A + C*Cos[c + d*x]^2))/Cos[c + d*x]^(7/2), x, 3, -((2*C*(b*Cos[c + d*x])^n*Sin[c + d*x])/(d*(3 - 2*n)*Cos[c + d*x]^(5/2))) + ((A*(3 - 2*n) + C*(5 - 2*n))*(b*Cos[c + d*x])^n*(Cos[c + d*x]^2)^((1/4)*(5 - 2*n))*Hypergeometric2F1[1/2, (1/4)*(9 - 2*n), 3/2, Sin[c + d*x]^2]*Sin[c + d*x])/(d*(3 - 2*n)*Cos[c + d*x]^(5/2))}
{((b*Cos[c + d*x])^n*(A + C*Cos[c + d*x]^2))/Cos[c + d*x]^(9/2), x, 3, -((2*C*(b*Cos[c + d*x])^n*Sin[c + d*x])/(d*(5 - 2*n)*Cos[c + d*x]^(7/2))) + ((A*(5 - 2*n) + C*(7 - 2*n))*(b*Cos[c + d*x])^n*(Cos[c + d*x]^2)^((1/4)*(7 - 2*n))*Hypergeometric2F1[1/2, (1/4)*(11 - 2*n), 3/2, Sin[c + d*x]^2]*Sin[c + d*x])/(d*(5 - 2*n)*Cos[c + d*x]^(7/2))}


(* ::Section:: *)
(*Cos[c+d x]^m (B Cos[c+d x]+C Cos[c+d x]^2) (b Cos[c+d x])^(n/2)*)


(* ::Subsection::Closed:: *)
(*Integrands of the form Cos[c+d x]^m (B Cos[c+d x]+C Cos[c+d x]^2) (b Cos[c+d x])^(n/2)*)


(* ::Subsubsection:: *)
(*n>0*)


(* ::Subsubsection:: *)
(*n<0*)


(* ::Subsection::Closed:: *)
(*Integrands of the form Cos[c+d x]^(m/2) (B Cos[c+d x]+C Cos[c+d x]^2) (b Cos[c+d x])^(n/2)*)


(* ::Subsubsection:: *)
(*n>0*)


(* ::Subsubsection:: *)
(*n<0*)


(* ::Subsection::Closed:: *)
(*Integrands of the form Cos[c+d x]^m (B Cos[c+d x]+C Cos[c+d x]^2) (b Cos[c+d x])^(n/3)*)


(* ::Subsubsection::Closed:: *)
(*n>0*)


{Cos[c + d*x]^m*(b*Cos[c + d*x])^(1/3)*(B*Cos[c + d*x] + C*Cos[c + d*x]^2), x, 5, (C*Cos[c + d*x]^(3 + m)*(b*Cos[c + d*x])^(1/3)*(Cos[c + d*x]^2)^((-10 - 3*m)/6)*Hypergeometric2F1[1/2, (-4 - 3*m)/6, 3/2, Sin[c + d*x]^2]*Sin[c + d*x])/d + (B*Cos[c + d*x]^(2 + m)*(b*Cos[c + d*x])^(1/3)*(Cos[c + d*x]^2)^((-7 - 3*m)/6)*Hypergeometric2F1[1/2, (-1 - 3*m)/6, 3/2, Sin[c + d*x]^2]*Sin[c + d*x])/d}

{Cos[c + d*x]^2*(b*Cos[c + d*x])^(1/3)*(B*Cos[c + d*x] + C*Cos[c + d*x]^2), x, 11, (21*B*(b*Cos[c + d*x])^(1/3)*Sin[c + d*x])/(40*d) + (30*C*(b*Cos[c + d*x])^(4/3)*Sin[c + d*x])/(91*b*d) + (3*B*(b*Cos[c + d*x])^(7/3)*Sin[c + d*x])/(10*b^2*d) + (3*C*(b*Cos[c + d*x])^(10/3)*Sin[c + d*x])/(13*b^3*d) + (40*b*C*(Cos[c + d*x]^2)^(1/3)*Hypergeometric2F1[1/3, 1/2, 3/2, Sin[c + d*x]^2]*Sin[c + d*x])/(91*d*(b*Cos[c + d*x])^(2/3)) + (7*B*(b*Cos[c + d*x])^(1/3)*Hypergeometric2F1[1/2, 5/6, 3/2, Sin[c + d*x]^2]*Sin[c + d*x])/(40*d*(Cos[c + d*x]^2)^(1/6))}
{Cos[c + d*x]*(b*Cos[c + d*x])^(1/3)*(B*Cos[c + d*x] + C*Cos[c + d*x]^2), x, 10, (21*C*(b*Cos[c + d*x])^(1/3)*Sin[c + d*x])/(40*d) + (3*B*(b*Cos[c + d*x])^(4/3)*Sin[c + d*x])/(7*b*d) + (3*C*(b*Cos[c + d*x])^(7/3)*Sin[c + d*x])/(10*b^2*d) + (4*b*B*(Cos[c + d*x]^2)^(1/3)*Hypergeometric2F1[1/3, 1/2, 3/2, Sin[c + d*x]^2]*Sin[c + d*x])/(7*d*(b*Cos[c + d*x])^(2/3)) + (7*C*(b*Cos[c + d*x])^(1/3)*Hypergeometric2F1[1/2, 5/6, 3/2, Sin[c + d*x]^2]*Sin[c + d*x])/(40*d*(Cos[c + d*x]^2)^(1/6))}
{(b*Cos[c + d*x])^(1/3)*(B*Cos[c + d*x] + C*Cos[c + d*x]^2), x, 9, (3*B*(b*Cos[c + d*x])^(1/3)*Sin[c + d*x])/(4*d) + (3*C*(b*Cos[c + d*x])^(4/3)*Sin[c + d*x])/(7*b*d) + (4*b*C*(Cos[c + d*x]^2)^(1/3)*Hypergeometric2F1[1/3, 1/2, 3/2, Sin[c + d*x]^2]*Sin[c + d*x])/(7*d*(b*Cos[c + d*x])^(2/3)) + (B*(b*Cos[c + d*x])^(1/3)*Hypergeometric2F1[1/2, 5/6, 3/2, Sin[c + d*x]^2]*Sin[c + d*x])/(4*d*(Cos[c + d*x]^2)^(1/6))}
{(b*Cos[c + d*x])^(1/3)*(B*Cos[c + d*x] + C*Cos[c + d*x]^2)*Sec[c + d*x], x, 7, (3*C*(b*Cos[c + d*x])^(1/3)*Sin[c + d*x])/(4*d) + (b*B*(Cos[c + d*x]^2)^(1/3)*Hypergeometric2F1[1/3, 1/2, 3/2, Sin[c + d*x]^2]*Sin[c + d*x])/(d*(b*Cos[c + d*x])^(2/3)) + (C*(b*Cos[c + d*x])^(1/3)*Hypergeometric2F1[1/2, 5/6, 3/2, Sin[c + d*x]^2]*Sin[c + d*x])/(4*d*(Cos[c + d*x]^2)^(1/6))}
{(b*Cos[c + d*x])^(1/3)*(B*Cos[c + d*x] + C*Cos[c + d*x]^2)*Sec[c + d*x]^2, x, 7, (b*C*(Cos[c + d*x]^2)^(1/3)*Hypergeometric2F1[1/3, 1/2, 3/2, Sin[c + d*x]^2]*Sin[c + d*x])/(d*(b*Cos[c + d*x])^(2/3)) + (B*(b*Cos[c + d*x])^(1/3)*Hypergeometric2F1[1/2, 5/6, 3/2, Sin[c + d*x]^2]*Sin[c + d*x])/(d*(Cos[c + d*x]^2)^(1/6))}
{(b*Cos[c + d*x])^(1/3)*(B*Cos[c + d*x] + C*Cos[c + d*x]^2)*Sec[c + d*x]^3, x, 8, (3*b*B*Sin[c + d*x])/(2*d*(b*Cos[c + d*x])^(2/3)) - (b*B*(Cos[c + d*x]^2)^(1/3)*Hypergeometric2F1[1/3, 1/2, 3/2, Sin[c + d*x]^2]*Sin[c + d*x])/(2*d*(b*Cos[c + d*x])^(2/3)) + (C*(b*Cos[c + d*x])^(1/3)*Hypergeometric2F1[1/2, 5/6, 3/2, Sin[c + d*x]^2]*Sin[c + d*x])/(d*(Cos[c + d*x]^2)^(1/6))}


{Cos[c + d*x]^m*(b*Cos[c + d*x])^(2/3)*(B*Cos[c + d*x] + C*Cos[c + d*x]^2), x, 5, (C*Cos[c + d*x]^(3 + m)*(b*Cos[c + d*x])^(2/3)*(Cos[c + d*x]^2)^((-11 - 3*m)/6)*Hypergeometric2F1[1/2, (-5 - 3*m)/6, 3/2, Sin[c + d*x]^2]*Sin[c + d*x])/d + (B*Cos[c + d*x]^(2 + m)*(b*Cos[c + d*x])^(2/3)*(Cos[c + d*x]^2)^((-8 - 3*m)/6)*Hypergeometric2F1[1/2, (-2 - 3*m)/6, 3/2, Sin[c + d*x]^2]*Sin[c + d*x])/d}

{Cos[c + d*x]^2*(b*Cos[c + d*x])^(2/3)*(B*Cos[c + d*x] + C*Cos[c + d*x]^2), x, 11, (24*B*(b*Cos[c + d*x])^(2/3)*Sin[c + d*x])/(55*d) + (33*C*(b*Cos[c + d*x])^(5/3)*Sin[c + d*x])/(112*b*d) + (3*B*(b*Cos[c + d*x])^(8/3)*Sin[c + d*x])/(11*b^2*d) + (3*C*(b*Cos[c + d*x])^(11/3)*Sin[c + d*x])/(14*b^3*d) + (55*b*C*(Cos[c + d*x]^2)^(1/6)*Hypergeometric2F1[1/6, 1/2, 3/2, Sin[c + d*x]^2]*Sin[c + d*x])/(112*d*(b*Cos[c + d*x])^(1/3)) + (16*B*(b*Cos[c + d*x])^(2/3)*Hypergeometric2F1[1/2, 2/3, 3/2, Sin[c + d*x]^2]*Sin[c + d*x])/(55*d*(Cos[c + d*x]^2)^(1/3))}
{Cos[c + d*x]*(b*Cos[c + d*x])^(2/3)*(B*Cos[c + d*x] + C*Cos[c + d*x]^2), x, 10, (24*C*(b*Cos[c + d*x])^(2/3)*Sin[c + d*x])/(55*d) + (3*B*(b*Cos[c + d*x])^(5/3)*Sin[c + d*x])/(8*b*d) + (3*C*(b*Cos[c + d*x])^(8/3)*Sin[c + d*x])/(11*b^2*d) + (5*b*B*(Cos[c + d*x]^2)^(1/6)*Hypergeometric2F1[1/6, 1/2, 3/2, Sin[c + d*x]^2]*Sin[c + d*x])/(8*d*(b*Cos[c + d*x])^(1/3)) + (16*C*(b*Cos[c + d*x])^(2/3)*Hypergeometric2F1[1/2, 2/3, 3/2, Sin[c + d*x]^2]*Sin[c + d*x])/(55*d*(Cos[c + d*x]^2)^(1/3))}
{(b*Cos[c + d*x])^(2/3)*(B*Cos[c + d*x] + C*Cos[c + d*x]^2), x, 9, (3*B*(b*Cos[c + d*x])^(2/3)*Sin[c + d*x])/(5*d) + (3*C*(b*Cos[c + d*x])^(5/3)*Sin[c + d*x])/(8*b*d) + (5*b*C*(Cos[c + d*x]^2)^(1/6)*Hypergeometric2F1[1/6, 1/2, 3/2, Sin[c + d*x]^2]*Sin[c + d*x])/(8*d*(b*Cos[c + d*x])^(1/3)) + (2*B*(b*Cos[c + d*x])^(2/3)*Hypergeometric2F1[1/2, 2/3, 3/2, Sin[c + d*x]^2]*Sin[c + d*x])/(5*d*(Cos[c + d*x]^2)^(1/3))}
{(b*Cos[c + d*x])^(2/3)*(B*Cos[c + d*x] + C*Cos[c + d*x]^2)*Sec[c + d*x], x, 7, (3*C*(b*Cos[c + d*x])^(2/3)*Sin[c + d*x])/(5*d) + (b*B*(Cos[c + d*x]^2)^(1/6)*Hypergeometric2F1[1/6, 1/2, 3/2, Sin[c + d*x]^2]*Sin[c + d*x])/(d*(b*Cos[c + d*x])^(1/3)) + (2*C*(b*Cos[c + d*x])^(2/3)*Hypergeometric2F1[1/2, 2/3, 3/2, Sin[c + d*x]^2]*Sin[c + d*x])/(5*d*(Cos[c + d*x]^2)^(1/3))}
{(b*Cos[c + d*x])^(2/3)*(B*Cos[c + d*x] + C*Cos[c + d*x]^2)*Sec[c + d*x]^2, x, 7, (b*C*(Cos[c + d*x]^2)^(1/6)*Hypergeometric2F1[1/6, 1/2, 3/2, Sin[c + d*x]^2]*Sin[c + d*x])/(d*(b*Cos[c + d*x])^(1/3)) + (B*(b*Cos[c + d*x])^(2/3)*Hypergeometric2F1[1/2, 2/3, 3/2, Sin[c + d*x]^2]*Sin[c + d*x])/(d*(Cos[c + d*x]^2)^(1/3))}
{(b*Cos[c + d*x])^(2/3)*(B*Cos[c + d*x] + C*Cos[c + d*x]^2)*Sec[c + d*x]^3, x, 8, (3*b*B*Sin[c + d*x])/(d*(b*Cos[c + d*x])^(1/3)) - (2*b*B*(Cos[c + d*x]^2)^(1/6)*Hypergeometric2F1[1/6, 1/2, 3/2, Sin[c + d*x]^2]*Sin[c + d*x])/(d*(b*Cos[c + d*x])^(1/3)) + (C*(b*Cos[c + d*x])^(2/3)*Hypergeometric2F1[1/2, 2/3, 3/2, Sin[c + d*x]^2]*Sin[c + d*x])/(d*(Cos[c + d*x]^2)^(1/3))}


{Cos[c + d*x]^m*(b*Cos[c + d*x])^(4/3)*(B*Cos[c + d*x] + C*Cos[c + d*x]^2), x, 5, (C*Cos[c + d*x]^(3 + m)*(b*Cos[c + d*x])^(4/3)*(Cos[c + d*x]^2)^((-13 - 3*m)/6)*Hypergeometric2F1[1/2, (-7 - 3*m)/6, 3/2, Sin[c + d*x]^2]*Sin[c + d*x])/d + (B*Cos[c + d*x]^(2 + m)*(b*Cos[c + d*x])^(4/3)*(Cos[c + d*x]^2)^((-10 - 3*m)/6)*Hypergeometric2F1[1/2, (-4 - 3*m)/6, 3/2, Sin[c + d*x]^2]*Sin[c + d*x])/d}

{Cos[c + d*x]^2*(b*Cos[c + d*x])^(4/3)*(B*Cos[c + d*x] + C*Cos[c + d*x]^2), x, 12, (273*b*C*(b*Cos[c + d*x])^(1/3)*Sin[c + d*x])/(640*d) + (30*B*(b*Cos[c + d*x])^(4/3)*Sin[c + d*x])/(91*d) + (39*C*(b*Cos[c + d*x])^(7/3)*Sin[c + d*x])/(160*b*d) + (3*B*(b*Cos[c + d*x])^(10/3)*Sin[c + d*x])/(13*b^2*d) + (3*C*(b*Cos[c + d*x])^(13/3)*Sin[c + d*x])/(16*b^3*d) + (40*b^2*B*(Cos[c + d*x]^2)^(1/3)*Hypergeometric2F1[1/3, 1/2, 3/2, Sin[c + d*x]^2]*Sin[c + d*x])/(91*d*(b*Cos[c + d*x])^(2/3)) + (91*b*C*(b*Cos[c + d*x])^(1/3)*Hypergeometric2F1[1/2, 5/6, 3/2, Sin[c + d*x]^2]*Sin[c + d*x])/(640*d*(Cos[c + d*x]^2)^(1/6))}
{Cos[c + d*x]*(b*Cos[c + d*x])^(4/3)*(B*Cos[c + d*x] + C*Cos[c + d*x]^2), x, 11, (21*b*B*(b*Cos[c + d*x])^(1/3)*Sin[c + d*x])/(40*d) + (30*C*(b*Cos[c + d*x])^(4/3)*Sin[c + d*x])/(91*d) + (3*B*(b*Cos[c + d*x])^(7/3)*Sin[c + d*x])/(10*b*d) + (3*C*(b*Cos[c + d*x])^(10/3)*Sin[c + d*x])/(13*b^2*d) + (40*b^2*C*(Cos[c + d*x]^2)^(1/3)*Hypergeometric2F1[1/3, 1/2, 3/2, Sin[c + d*x]^2]*Sin[c + d*x])/(91*d*(b*Cos[c + d*x])^(2/3)) + (7*b*B*(b*Cos[c + d*x])^(1/3)*Hypergeometric2F1[1/2, 5/6, 3/2, Sin[c + d*x]^2]*Sin[c + d*x])/(40*d*(Cos[c + d*x]^2)^(1/6))}
{(b*Cos[c + d*x])^(4/3)*(B*Cos[c + d*x] + C*Cos[c + d*x]^2), x, 10, (21*b*C*(b*Cos[c + d*x])^(1/3)*Sin[c + d*x])/(40*d) + (3*B*(b*Cos[c + d*x])^(4/3)*Sin[c + d*x])/(7*d) + (3*C*(b*Cos[c + d*x])^(7/3)*Sin[c + d*x])/(10*b*d) + (4*b^2*B*(Cos[c + d*x]^2)^(1/3)*Hypergeometric2F1[1/3, 1/2, 3/2, Sin[c + d*x]^2]*Sin[c + d*x])/(7*d*(b*Cos[c + d*x])^(2/3)) + (7*b*C*(b*Cos[c + d*x])^(1/3)*Hypergeometric2F1[1/2, 5/6, 3/2, Sin[c + d*x]^2]*Sin[c + d*x])/(40*d*(Cos[c + d*x]^2)^(1/6))}
{(b*Cos[c + d*x])^(4/3)*(B*Cos[c + d*x] + C*Cos[c + d*x]^2)*Sec[c + d*x], x, 8, (3*b*B*(b*Cos[c + d*x])^(1/3)*Sin[c + d*x])/(4*d) + (3*C*(b*Cos[c + d*x])^(4/3)*Sin[c + d*x])/(7*d) + (4*b^2*C*(Cos[c + d*x]^2)^(1/3)*Hypergeometric2F1[1/3, 1/2, 3/2, Sin[c + d*x]^2]*Sin[c + d*x])/(7*d*(b*Cos[c + d*x])^(2/3)) + (b*B*(b*Cos[c + d*x])^(1/3)*Hypergeometric2F1[1/2, 5/6, 3/2, Sin[c + d*x]^2]*Sin[c + d*x])/(4*d*(Cos[c + d*x]^2)^(1/6))}
{(b*Cos[c + d*x])^(4/3)*(B*Cos[c + d*x] + C*Cos[c + d*x]^2)*Sec[c + d*x]^2, x, 8, (3*b*C*(b*Cos[c + d*x])^(1/3)*Sin[c + d*x])/(4*d) + (b^2*B*(Cos[c + d*x]^2)^(1/3)*Hypergeometric2F1[1/3, 1/2, 3/2, Sin[c + d*x]^2]*Sin[c + d*x])/(d*(b*Cos[c + d*x])^(2/3)) + (b*C*(b*Cos[c + d*x])^(1/3)*Hypergeometric2F1[1/2, 5/6, 3/2, Sin[c + d*x]^2]*Sin[c + d*x])/(4*d*(Cos[c + d*x]^2)^(1/6))}
{(b*Cos[c + d*x])^(4/3)*(B*Cos[c + d*x] + C*Cos[c + d*x]^2)*Sec[c + d*x]^3, x, 7, (b^2*C*(Cos[c + d*x]^2)^(1/3)*Hypergeometric2F1[1/3, 1/2, 3/2, Sin[c + d*x]^2]*Sin[c + d*x])/(d*(b*Cos[c + d*x])^(2/3)) + (b*B*(b*Cos[c + d*x])^(1/3)*Hypergeometric2F1[1/2, 5/6, 3/2, Sin[c + d*x]^2]*Sin[c + d*x])/(d*(Cos[c + d*x]^2)^(1/6))}


(* ::Subsubsection::Closed:: *)
(*n<0*)


{(Cos[c + d*x]^m*(B*Cos[c + d*x] + C*Cos[c + d*x]^2))/(b*Cos[c + d*x])^(1/3), x, 5, (C*Cos[c + d*x]^(3 + m)*(Cos[c + d*x]^2)^((-8 - 3*m)/6)*Hypergeometric2F1[1/2, (-2 - 3*m)/6, 3/2, Sin[c + d*x]^2]*Sin[c + d*x])/(d*(b*Cos[c + d*x])^(1/3)) + (B*Cos[c + d*x]^(2 + m)*(Cos[c + d*x]^2)^((-5 - 3*m)/6)*Hypergeometric2F1[1/2, (1 - 3*m)/6, 3/2, Sin[c + d*x]^2]*Sin[c + d*x])/(d*(b*Cos[c + d*x])^(1/3))}

{(Cos[c + d*x]^2*(B*Cos[c + d*x] + C*Cos[c + d*x]^2))/(b*Cos[c + d*x])^(1/3), x, 10, (24*C*(b*Cos[c + d*x])^(2/3)*Sin[c + d*x])/(55*b*d) + (3*B*(b*Cos[c + d*x])^(5/3)*Sin[c + d*x])/(8*b^2*d) + (3*C*(b*Cos[c + d*x])^(8/3)*Sin[c + d*x])/(11*b^3*d) + (5*B*(Cos[c + d*x]^2)^(1/6)*Hypergeometric2F1[1/6, 1/2, 3/2, Sin[c + d*x]^2]*Sin[c + d*x])/(8*d*(b*Cos[c + d*x])^(1/3)) + (16*C*(b*Cos[c + d*x])^(2/3)*Hypergeometric2F1[1/2, 2/3, 3/2, Sin[c + d*x]^2]*Sin[c + d*x])/(55*b*d*(Cos[c + d*x]^2)^(1/3))}
{(Cos[c + d*x]*(B*Cos[c + d*x] + C*Cos[c + d*x]^2))/(b*Cos[c + d*x])^(1/3), x, 9, (3*B*(b*Cos[c + d*x])^(2/3)*Sin[c + d*x])/(5*b*d) + (3*C*(b*Cos[c + d*x])^(5/3)*Sin[c + d*x])/(8*b^2*d) + (5*C*(Cos[c + d*x]^2)^(1/6)*Hypergeometric2F1[1/6, 1/2, 3/2, Sin[c + d*x]^2]*Sin[c + d*x])/(8*d*(b*Cos[c + d*x])^(1/3)) + (2*B*(b*Cos[c + d*x])^(2/3)*Hypergeometric2F1[1/2, 2/3, 3/2, Sin[c + d*x]^2]*Sin[c + d*x])/(5*b*d*(Cos[c + d*x]^2)^(1/3))}
{(B*Cos[c + d*x] + C*Cos[c + d*x]^2)/(b*Cos[c + d*x])^(1/3), x, 8, (3*C*(b*Cos[c + d*x])^(2/3)*Sin[c + d*x])/(5*b*d) + (B*(Cos[c + d*x]^2)^(1/6)*Hypergeometric2F1[1/6, 1/2, 3/2, Sin[c + d*x]^2]*Sin[c + d*x])/(d*(b*Cos[c + d*x])^(1/3)) + (2*C*(b*Cos[c + d*x])^(2/3)*Hypergeometric2F1[1/2, 2/3, 3/2, Sin[c + d*x]^2]*Sin[c + d*x])/(5*b*d*(Cos[c + d*x]^2)^(1/3))}
{((B*Cos[c + d*x] + C*Cos[c + d*x]^2)*Sec[c + d*x])/(b*Cos[c + d*x])^(1/3), x, 6, (C*(Cos[c + d*x]^2)^(1/6)*Hypergeometric2F1[1/6, 1/2, 3/2, Sin[c + d*x]^2]*Sin[c + d*x])/(d*(b*Cos[c + d*x])^(1/3)) + (B*(b*Cos[c + d*x])^(2/3)*Hypergeometric2F1[1/2, 2/3, 3/2, Sin[c + d*x]^2]*Sin[c + d*x])/(b*d*(Cos[c + d*x]^2)^(1/3))}
{((B*Cos[c + d*x] + C*Cos[c + d*x]^2)*Sec[c + d*x]^2)/(b*Cos[c + d*x])^(1/3), x, 8, (3*B*Sin[c + d*x])/(d*(b*Cos[c + d*x])^(1/3)) - (2*B*(Cos[c + d*x]^2)^(1/6)*Hypergeometric2F1[1/6, 1/2, 3/2, Sin[c + d*x]^2]*Sin[c + d*x])/(d*(b*Cos[c + d*x])^(1/3)) + (C*(b*Cos[c + d*x])^(2/3)*Hypergeometric2F1[1/2, 2/3, 3/2, Sin[c + d*x]^2]*Sin[c + d*x])/(b*d*(Cos[c + d*x]^2)^(1/3))}
{((B*Cos[c + d*x] + C*Cos[c + d*x]^2)*Sec[c + d*x]^3)/(b*Cos[c + d*x])^(1/3), x, 9, (3*b*B*Sin[c + d*x])/(4*d*(b*Cos[c + d*x])^(4/3)) + (3*C*Sin[c + d*x])/(d*(b*Cos[c + d*x])^(1/3)) - (2*C*(Cos[c + d*x]^2)^(1/6)*Hypergeometric2F1[1/6, 1/2, 3/2, Sin[c + d*x]^2]*Sin[c + d*x])/(d*(b*Cos[c + d*x])^(1/3)) + (B*(b*Cos[c + d*x])^(2/3)*Hypergeometric2F1[1/2, 2/3, 3/2, Sin[c + d*x]^2]*Sin[c + d*x])/(4*b*d*(Cos[c + d*x]^2)^(1/3))}


{(Cos[c + d*x]^m*(B*Cos[c + d*x] + C*Cos[c + d*x]^2))/(b*Cos[c + d*x])^(2/3), x, 5, (C*Cos[c + d*x]^(3 + m)*(Cos[c + d*x]^2)^((-7 - 3*m)/6)*Hypergeometric2F1[1/2, (-1 - 3*m)/6, 3/2, Sin[c + d*x]^2]*Sin[c + d*x])/(d*(b*Cos[c + d*x])^(2/3)) + (B*Cos[c + d*x]^(2 + m)*(Cos[c + d*x]^2)^((-4 - 3*m)/6)*Hypergeometric2F1[1/2, (2 - 3*m)/6, 3/2, Sin[c + d*x]^2]*Sin[c + d*x])/(d*(b*Cos[c + d*x])^(2/3))}

{(Cos[c + d*x]^2*(B*Cos[c + d*x] + C*Cos[c + d*x]^2))/(b*Cos[c + d*x])^(2/3), x, 10, (21*C*(b*Cos[c + d*x])^(1/3)*Sin[c + d*x])/(40*b*d) + (3*B*(b*Cos[c + d*x])^(4/3)*Sin[c + d*x])/(7*b^2*d) + (3*C*(b*Cos[c + d*x])^(7/3)*Sin[c + d*x])/(10*b^3*d) + (4*B*(Cos[c + d*x]^2)^(1/3)*Hypergeometric2F1[1/3, 1/2, 3/2, Sin[c + d*x]^2]*Sin[c + d*x])/(7*d*(b*Cos[c + d*x])^(2/3)) + (7*C*(b*Cos[c + d*x])^(1/3)*Hypergeometric2F1[1/2, 5/6, 3/2, Sin[c + d*x]^2]*Sin[c + d*x])/(40*b*d*(Cos[c + d*x]^2)^(1/6))}
{(Cos[c + d*x]*(B*Cos[c + d*x] + C*Cos[c + d*x]^2))/(b*Cos[c + d*x])^(2/3), x, 9, (3*B*(b*Cos[c + d*x])^(1/3)*Sin[c + d*x])/(4*b*d) + (3*C*(b*Cos[c + d*x])^(4/3)*Sin[c + d*x])/(7*b^2*d) + (4*C*(Cos[c + d*x]^2)^(1/3)*Hypergeometric2F1[1/3, 1/2, 3/2, Sin[c + d*x]^2]*Sin[c + d*x])/(7*d*(b*Cos[c + d*x])^(2/3)) + (B*(b*Cos[c + d*x])^(1/3)*Hypergeometric2F1[1/2, 5/6, 3/2, Sin[c + d*x]^2]*Sin[c + d*x])/(4*b*d*(Cos[c + d*x]^2)^(1/6))}
{(B*Cos[c + d*x] + C*Cos[c + d*x]^2)/(b*Cos[c + d*x])^(2/3), x, 8, (3*C*(b*Cos[c + d*x])^(1/3)*Sin[c + d*x])/(4*b*d) + (B*(Cos[c + d*x]^2)^(1/3)*Hypergeometric2F1[1/3, 1/2, 3/2, Sin[c + d*x]^2]*Sin[c + d*x])/(d*(b*Cos[c + d*x])^(2/3)) + (C*(b*Cos[c + d*x])^(1/3)*Hypergeometric2F1[1/2, 5/6, 3/2, Sin[c + d*x]^2]*Sin[c + d*x])/(4*b*d*(Cos[c + d*x]^2)^(1/6))}
{((B*Cos[c + d*x] + C*Cos[c + d*x]^2)*Sec[c + d*x])/(b*Cos[c + d*x])^(2/3), x, 6, (C*(Cos[c + d*x]^2)^(1/3)*Hypergeometric2F1[1/3, 1/2, 3/2, Sin[c + d*x]^2]*Sin[c + d*x])/(d*(b*Cos[c + d*x])^(2/3)) + (B*(b*Cos[c + d*x])^(1/3)*Hypergeometric2F1[1/2, 5/6, 3/2, Sin[c + d*x]^2]*Sin[c + d*x])/(b*d*(Cos[c + d*x]^2)^(1/6))}
{((B*Cos[c + d*x] + C*Cos[c + d*x]^2)*Sec[c + d*x]^2)/(b*Cos[c + d*x])^(2/3), x, 8, (3*B*Sin[c + d*x])/(2*d*(b*Cos[c + d*x])^(2/3)) - (B*(Cos[c + d*x]^2)^(1/3)*Hypergeometric2F1[1/3, 1/2, 3/2, Sin[c + d*x]^2]*Sin[c + d*x])/(2*d*(b*Cos[c + d*x])^(2/3)) + (C*(b*Cos[c + d*x])^(1/3)*Hypergeometric2F1[1/2, 5/6, 3/2, Sin[c + d*x]^2]*Sin[c + d*x])/(b*d*(Cos[c + d*x]^2)^(1/6))}
{((B*Cos[c + d*x] + C*Cos[c + d*x]^2)*Sec[c + d*x]^3)/(b*Cos[c + d*x])^(2/3), x, 9, (3*b*B*Sin[c + d*x])/(5*d*(b*Cos[c + d*x])^(5/3)) + (3*C*Sin[c + d*x])/(2*d*(b*Cos[c + d*x])^(2/3)) - (C*(Cos[c + d*x]^2)^(1/3)*Hypergeometric2F1[1/3, 1/2, 3/2, Sin[c + d*x]^2]*Sin[c + d*x])/(2*d*(b*Cos[c + d*x])^(2/3)) + (2*B*(b*Cos[c + d*x])^(1/3)*Hypergeometric2F1[1/2, 5/6, 3/2, Sin[c + d*x]^2]*Sin[c + d*x])/(5*b*d*(Cos[c + d*x]^2)^(1/6))}


{(Cos[c + d*x]^m*(B*Cos[c + d*x] + C*Cos[c + d*x]^2))/(b*Cos[c + d*x])^(4/3), x, 5, (C*Cos[c + d*x]^(3 + m)*(Cos[c + d*x]^2)^((-5 - 3*m)/6)*Hypergeometric2F1[1/2, (1 - 3*m)/6, 3/2, Sin[c + d*x]^2]*Sin[c + d*x])/(d*(b*Cos[c + d*x])^(4/3)) + (B*Cos[c + d*x]^(2 + m)*(Cos[c + d*x]^2)^((-2 - 3*m)/6)*Hypergeometric2F1[1/2, (4 - 3*m)/6, 3/2, Sin[c + d*x]^2]*Sin[c + d*x])/(d*(b*Cos[c + d*x])^(4/3))}

{(Cos[c + d*x]^2*(B*Cos[c + d*x] + C*Cos[c + d*x]^2))/(b*Cos[c + d*x])^(4/3), x, 9, (3*B*(b*Cos[c + d*x])^(2/3)*Sin[c + d*x])/(5*b^2*d) + (3*C*(b*Cos[c + d*x])^(5/3)*Sin[c + d*x])/(8*b^3*d) + (5*C*(Cos[c + d*x]^2)^(1/6)*Hypergeometric2F1[1/6, 1/2, 3/2, Sin[c + d*x]^2]*Sin[c + d*x])/(8*b*d*(b*Cos[c + d*x])^(1/3)) + (2*B*(b*Cos[c + d*x])^(2/3)*Hypergeometric2F1[1/2, 2/3, 3/2, Sin[c + d*x]^2]*Sin[c + d*x])/(5*b^2*d*(Cos[c + d*x]^2)^(1/3))}
{(Cos[c + d*x]*(B*Cos[c + d*x] + C*Cos[c + d*x]^2))/(b*Cos[c + d*x])^(4/3), x, 8, (3*C*(b*Cos[c + d*x])^(2/3)*Sin[c + d*x])/(5*b^2*d) + (B*(Cos[c + d*x]^2)^(1/6)*Hypergeometric2F1[1/6, 1/2, 3/2, Sin[c + d*x]^2]*Sin[c + d*x])/(b*d*(b*Cos[c + d*x])^(1/3)) + (2*C*(b*Cos[c + d*x])^(2/3)*Hypergeometric2F1[1/2, 2/3, 3/2, Sin[c + d*x]^2]*Sin[c + d*x])/(5*b^2*d*(Cos[c + d*x]^2)^(1/3))}
{(B*Cos[c + d*x] + C*Cos[c + d*x]^2)/(b*Cos[c + d*x])^(4/3), x, 7, (C*(Cos[c + d*x]^2)^(1/6)*Hypergeometric2F1[1/6, 1/2, 3/2, Sin[c + d*x]^2]*Sin[c + d*x])/(b*d*(b*Cos[c + d*x])^(1/3)) + (B*(b*Cos[c + d*x])^(2/3)*Hypergeometric2F1[1/2, 2/3, 3/2, Sin[c + d*x]^2]*Sin[c + d*x])/(b^2*d*(Cos[c + d*x]^2)^(1/3))}
{((B*Cos[c + d*x] + C*Cos[c + d*x]^2)*Sec[c + d*x])/(b*Cos[c + d*x])^(4/3), x, 7, (3*B*Sin[c + d*x])/(b*d*(b*Cos[c + d*x])^(1/3)) - (2*B*(Cos[c + d*x]^2)^(1/6)*Hypergeometric2F1[1/6, 1/2, 3/2, Sin[c + d*x]^2]*Sin[c + d*x])/(b*d*(b*Cos[c + d*x])^(1/3)) + (C*(b*Cos[c + d*x])^(2/3)*Hypergeometric2F1[1/2, 2/3, 3/2, Sin[c + d*x]^2]*Sin[c + d*x])/(b^2*d*(Cos[c + d*x]^2)^(1/3))}
{((B*Cos[c + d*x] + C*Cos[c + d*x]^2)*Sec[c + d*x]^2)/(b*Cos[c + d*x])^(4/3), x, 9, (3*B*Sin[c + d*x])/(4*d*(b*Cos[c + d*x])^(4/3)) + (3*C*Sin[c + d*x])/(b*d*(b*Cos[c + d*x])^(1/3)) - (2*C*(Cos[c + d*x]^2)^(1/6)*Hypergeometric2F1[1/6, 1/2, 3/2, Sin[c + d*x]^2]*Sin[c + d*x])/(b*d*(b*Cos[c + d*x])^(1/3)) + (B*(b*Cos[c + d*x])^(2/3)*Hypergeometric2F1[1/2, 2/3, 3/2, Sin[c + d*x]^2]*Sin[c + d*x])/(4*b^2*d*(Cos[c + d*x]^2)^(1/3))}
{((B*Cos[c + d*x] + C*Cos[c + d*x]^2)*Sec[c + d*x]^3)/(b*Cos[c + d*x])^(4/3), x, 10, (3*b*B*Sin[c + d*x])/(7*d*(b*Cos[c + d*x])^(7/3)) + (3*C*Sin[c + d*x])/(4*d*(b*Cos[c + d*x])^(4/3)) + (12*B*Sin[c + d*x])/(7*b*d*(b*Cos[c + d*x])^(1/3)) - (8*B*(Cos[c + d*x]^2)^(1/6)*Hypergeometric2F1[1/6, 1/2, 3/2, Sin[c + d*x]^2]*Sin[c + d*x])/(7*b*d*(b*Cos[c + d*x])^(1/3)) + (C*(b*Cos[c + d*x])^(2/3)*Hypergeometric2F1[1/2, 2/3, 3/2, Sin[c + d*x]^2]*Sin[c + d*x])/(4*b^2*d*(Cos[c + d*x]^2)^(1/3))}


(* ::Subsection::Closed:: *)
(*Integrands of the form Cos[c+d x]^m (B Cos[c+d x]+C Cos[c+d x]^2) (b Cos[c+d x])^n when n symbolic*)


{Cos[c + d*x]^m*(b*Cos[c + d*x])^n*(B*Cos[c + d*x] + C*Cos[c + d*x]^2), x, 5, (C*Cos[c + d*x]^(3 + m)*(b*Cos[c + d*x])^n*(Cos[c + d*x]^2)^((1/2)*(-3 - m - n))*Hypergeometric2F1[1/2, (1/2)*(-1 - m - n), 3/2, Sin[c + d*x]^2]*Sin[c + d*x])/d + (B*Cos[c + d*x]^(2 + m)*(b*Cos[c + d*x])^n*(Cos[c + d*x]^2)^((1/2)*(-2 - m - n))*Hypergeometric2F1[1/2, (1/2)*(-m - n), 3/2, Sin[c + d*x]^2]*Sin[c + d*x])/d}


{Cos[c + d*x]^2*(b*Cos[c + d*x])^n*(B*Cos[c + d*x] + C*Cos[c + d*x]^2), x, 7, (C*(b*Cos[c + d*x])^(5 + n)*(Cos[c + d*x]^2)^((1/2)*(-5 - n))*Hypergeometric2F1[1/2, (1/2)*(-3 - n), 3/2, Sin[c + d*x]^2]*Sin[c + d*x])/(b^5*d) + (B*(b*Cos[c + d*x])^(4 + n)*(Cos[c + d*x]^2)^((1/2)*(-4 - n))*Hypergeometric2F1[1/2, (1/2)*(-2 - n), 3/2, Sin[c + d*x]^2]*Sin[c + d*x])/(b^4*d)}
{Cos[c + d*x]^1*(b*Cos[c + d*x])^n*(B*Cos[c + d*x] + C*Cos[c + d*x]^2), x, 7, (C*(b*Cos[c + d*x])^(4 + n)*(Cos[c + d*x]^2)^((1/2)*(-4 - n))*Hypergeometric2F1[1/2, (1/2)*(-2 - n), 3/2, Sin[c + d*x]^2]*Sin[c + d*x])/(b^4*d) + (B*(b*Cos[c + d*x])^(3 + n)*(Cos[c + d*x]^2)^((1/2)*(-3 - n))*Hypergeometric2F1[1/2, (1/2)*(-1 - n), 3/2, Sin[c + d*x]^2]*Sin[c + d*x])/(b^3*d)}
{Cos[c + d*x]^0*(b*Cos[c + d*x])^n*(B*Cos[c + d*x] + C*Cos[c + d*x]^2), x, 7, (C*(b*Cos[c + d*x])^(3 + n)*(Cos[c + d*x]^2)^((1/2)*(-3 - n))*Hypergeometric2F1[1/2, (1/2)*(-1 - n), 3/2, Sin[c + d*x]^2]*Sin[c + d*x])/(b^3*d) + (B*(b*Cos[c + d*x])^(2 + n)*(Cos[c + d*x]^2)^((1/2)*(-2 - n))*Hypergeometric2F1[1/2, -(n/2), 3/2, Sin[c + d*x]^2]*Sin[c + d*x])/(b^2*d)}
{(b*Cos[c + d*x])^n*(B*Cos[c + d*x] + C*Cos[c + d*x]^2)*Sec[c + d*x]^1, x, 6, (B*(b*Cos[c + d*x])^(1 + n)*(Cos[c + d*x]^2)^((1/2)*(-1 - n))*Hypergeometric2F1[1/2, (1 - n)/2, 3/2, Sin[c + d*x]^2]*Sin[c + d*x])/(b*d) + (C*(b*Cos[c + d*x])^(2 + n)*(Cos[c + d*x]^2)^((1/2)*(-2 - n))*Hypergeometric2F1[1/2, -(n/2), 3/2, Sin[c + d*x]^2]*Sin[c + d*x])/(b^2*d)}
{(b*Cos[c + d*x])^n*(B*Cos[c + d*x] + C*Cos[c + d*x]^2)*Sec[c + d*x]^2, x, 7, (C*(b*Cos[c + d*x])^(1 + n)*(Cos[c + d*x]^2)^((1/2)*(-1 - n))*Hypergeometric2F1[1/2, (1 - n)/2, 3/2, Sin[c + d*x]^2]*Sin[c + d*x])/(b*d) + (B*(b*Cos[c + d*x])^n*Hypergeometric2F1[1/2, (2 - n)/2, 3/2, Sin[c + d*x]^2]*Sin[c + d*x])/((Cos[c + d*x]^2)^(n/2)*d)}
{(b*Cos[c + d*x])^n*(B*Cos[c + d*x] + C*Cos[c + d*x]^2)*Sec[c + d*x]^3, x, 7, (C*(b*Cos[c + d*x])^n*Hypergeometric2F1[1/2, (2 - n)/2, 3/2, Sin[c + d*x]^2]*Sin[c + d*x])/((Cos[c + d*x]^2)^(n/2)*d) + (b*B*(b*Cos[c + d*x])^(-1 + n)*(Cos[c + d*x]^2)^((1 - n)/2)*Hypergeometric2F1[1/2, (3 - n)/2, 3/2, Sin[c + d*x]^2]*Sin[c + d*x])/d}
{(b*Cos[c + d*x])^n*(B*Cos[c + d*x] + C*Cos[c + d*x]^2)*Sec[c + d*x]^4, x, 7, (b*C*(b*Cos[c + d*x])^(-1 + n)*(Cos[c + d*x]^2)^((1 - n)/2)*Hypergeometric2F1[1/2, (3 - n)/2, 3/2, Sin[c + d*x]^2]*Sin[c + d*x])/d + (b^2*B*(b*Cos[c + d*x])^(-2 + n)*(Cos[c + d*x]^2)^((2 - n)/2)*Hypergeometric2F1[1/2, (4 - n)/2, 3/2, Sin[c + d*x]^2]*Sin[c + d*x])/d}


{Cos[c + d*x]^(5/2)*(b*Cos[c + d*x])^n*(B*Cos[c + d*x] + C*Cos[c + d*x]^2), x, 5, (C*Cos[c + d*x]^(11/2)*(b*Cos[c + d*x])^n*(Cos[c + d*x]^2)^((1/4)*(-11 - 2*n))*Hypergeometric2F1[1/2, (1/4)*(-7 - 2*n), 3/2, Sin[c + d*x]^2]*Sin[c + d*x])/d + (B*Cos[c + d*x]^(9/2)*(b*Cos[c + d*x])^n*(Cos[c + d*x]^2)^((1/4)*(-9 - 2*n))*Hypergeometric2F1[1/2, (1/4)*(-5 - 2*n), 3/2, Sin[c + d*x]^2]*Sin[c + d*x])/d}
{Cos[c + d*x]^(3/2)*(b*Cos[c + d*x])^n*(B*Cos[c + d*x] + C*Cos[c + d*x]^2), x, 5, (C*Cos[c + d*x]^(9/2)*(b*Cos[c + d*x])^n*(Cos[c + d*x]^2)^((1/4)*(-9 - 2*n))*Hypergeometric2F1[1/2, (1/4)*(-5 - 2*n), 3/2, Sin[c + d*x]^2]*Sin[c + d*x])/d + (B*Cos[c + d*x]^(7/2)*(b*Cos[c + d*x])^n*(Cos[c + d*x]^2)^((1/4)*(-7 - 2*n))*Hypergeometric2F1[1/2, (1/4)*(-3 - 2*n), 3/2, Sin[c + d*x]^2]*Sin[c + d*x])/d}
{Sqrt[Cos[c + d*x]]*(b*Cos[c + d*x])^n*(B*Cos[c + d*x] + C*Cos[c + d*x]^2), x, 5, (C*Cos[c + d*x]^(7/2)*(b*Cos[c + d*x])^n*(Cos[c + d*x]^2)^((1/4)*(-7 - 2*n))*Hypergeometric2F1[1/2, (1/4)*(-3 - 2*n), 3/2, Sin[c + d*x]^2]*Sin[c + d*x])/d + (B*Cos[c + d*x]^(5/2)*(b*Cos[c + d*x])^n*(Cos[c + d*x]^2)^((1/4)*(-5 - 2*n))*Hypergeometric2F1[1/2, (1/4)*(-1 - 2*n), 3/2, Sin[c + d*x]^2]*Sin[c + d*x])/d}
{((b*Cos[c + d*x])^n*(B*Cos[c + d*x] + C*Cos[c + d*x]^2))/Sqrt[Cos[c + d*x]], x, 5, (C*Cos[c + d*x]^(5/2)*(b*Cos[c + d*x])^n*(Cos[c + d*x]^2)^((1/4)*(-5 - 2*n))*Hypergeometric2F1[1/2, (1/4)*(-1 - 2*n), 3/2, Sin[c + d*x]^2]*Sin[c + d*x])/d + (B*Cos[c + d*x]^(3/2)*(b*Cos[c + d*x])^n*(Cos[c + d*x]^2)^((1/4)*(-3 - 2*n))*Hypergeometric2F1[1/2, (1/4)*(1 - 2*n), 3/2, Sin[c + d*x]^2]*Sin[c + d*x])/d}
{((b*Cos[c + d*x])^n*(B*Cos[c + d*x] + C*Cos[c + d*x]^2))/Cos[c + d*x]^(3/2), x, 5, (C*Cos[c + d*x]^(3/2)*(b*Cos[c + d*x])^n*(Cos[c + d*x]^2)^((1/4)*(-3 - 2*n))*Hypergeometric2F1[1/2, (1/4)*(1 - 2*n), 3/2, Sin[c + d*x]^2]*Sin[c + d*x])/d + (B*Sqrt[Cos[c + d*x]]*(b*Cos[c + d*x])^n*(Cos[c + d*x]^2)^((1/4)*(-1 - 2*n))*Hypergeometric2F1[1/2, (1/4)*(3 - 2*n), 3/2, Sin[c + d*x]^2]*Sin[c + d*x])/d}
{((b*Cos[c + d*x])^n*(B*Cos[c + d*x] + C*Cos[c + d*x]^2))/Cos[c + d*x]^(5/2), x, 5, (C*Sqrt[Cos[c + d*x]]*(b*Cos[c + d*x])^n*(Cos[c + d*x]^2)^((1/4)*(-1 - 2*n))*Hypergeometric2F1[1/2, (1/4)*(3 - 2*n), 3/2, Sin[c + d*x]^2]*Sin[c + d*x])/d + (B*(b*Cos[c + d*x])^n*(Cos[c + d*x]^2)^((1/4)*(1 - 2*n))*Hypergeometric2F1[1/2, (1/4)*(5 - 2*n), 3/2, Sin[c + d*x]^2]*Sin[c + d*x])/(d*Sqrt[Cos[c + d*x]])}
{((b*Cos[c + d*x])^n*(B*Cos[c + d*x] + C*Cos[c + d*x]^2))/Cos[c + d*x]^(7/2), x, 5, (C*(b*Cos[c + d*x])^n*(Cos[c + d*x]^2)^((1/4)*(1 - 2*n))*Hypergeometric2F1[1/2, (1/4)*(5 - 2*n), 3/2, Sin[c + d*x]^2]*Sin[c + d*x])/(d*Sqrt[Cos[c + d*x]]) + (B*(b*Cos[c + d*x])^n*(Cos[c + d*x]^2)^((1/4)*(3 - 2*n))*Hypergeometric2F1[1/2, (1/4)*(7 - 2*n), 3/2, Sin[c + d*x]^2]*Sin[c + d*x])/(d*Cos[c + d*x]^(3/2))}
{((b*Cos[c + d*x])^n*(B*Cos[c + d*x] + C*Cos[c + d*x]^2))/Cos[c + d*x]^(9/2), x, 5, (C*(b*Cos[c + d*x])^n*(Cos[c + d*x]^2)^((1/4)*(3 - 2*n))*Hypergeometric2F1[1/2, (1/4)*(7 - 2*n), 3/2, Sin[c + d*x]^2]*Sin[c + d*x])/(d*Cos[c + d*x]^(3/2)) + (B*(b*Cos[c + d*x])^n*(Cos[c + d*x]^2)^((1/4)*(5 - 2*n))*Hypergeometric2F1[1/2, (1/4)*(9 - 2*n), 3/2, Sin[c + d*x]^2]*Sin[c + d*x])/(d*Cos[c + d*x]^(5/2))}


(* ::Section:: *)
(*Cos[c+d x]^m (A+B Cos[c+d x]+C Cos[c+d x]^2) (b Cos[c+d x])^(n/2)*)


(* ::Subsection::Closed:: *)
(*Integrands of the form Cos[c+d x]^m (A+B Cos[c+d x]+C Cos[c+d x]^2) (b Cos[c+d x])^(n/2)*)


(* ::Subsubsection::Closed:: *)
(*n>0*)


{Cos[c + d*x]^2*Sqrt[b*Cos[c + d*x]]*(A + B*Cos[c + d*x] + C*Cos[c + d*x]^2), x, 10, (2*(9*A + 7*C)*Sqrt[b*Cos[c + d*x]]*EllipticE[(1/2)*(c + d*x), 2])/(15*d*Sqrt[Cos[c + d*x]]) + (10*b*B*Sqrt[Cos[c + d*x]]*EllipticF[(1/2)*(c + d*x), 2])/(21*d*Sqrt[b*Cos[c + d*x]]) + (10*B*Sqrt[b*Cos[c + d*x]]*Sin[c + d*x])/(21*d) + (2*(9*A + 7*C)*(b*Cos[c + d*x])^(3/2)*Sin[c + d*x])/(45*b*d) + (2*B*(b*Cos[c + d*x])^(5/2)*Sin[c + d*x])/(7*b^2*d) + (2*C*(b*Cos[c + d*x])^(7/2)*Sin[c + d*x])/(9*b^3*d)}
{Cos[c + d*x]*Sqrt[b*Cos[c + d*x]]*(A + B*Cos[c + d*x] + C*Cos[c + d*x]^2), x, 9, (6*B*Sqrt[b*Cos[c + d*x]]*EllipticE[(1/2)*(c + d*x), 2])/(5*d*Sqrt[Cos[c + d*x]]) + (2*b*(7*A + 5*C)*Sqrt[Cos[c + d*x]]*EllipticF[(1/2)*(c + d*x), 2])/(21*d*Sqrt[b*Cos[c + d*x]]) + (2*(7*A + 5*C)*Sqrt[b*Cos[c + d*x]]*Sin[c + d*x])/(21*d) + (2*B*(b*Cos[c + d*x])^(3/2)*Sin[c + d*x])/(5*b*d) + (2*C*(b*Cos[c + d*x])^(5/2)*Sin[c + d*x])/(7*b^2*d)}
{Sqrt[b*Cos[c + d*x]]*(A + B*Cos[c + d*x] + C*Cos[c + d*x]^2), x, 7, (2*(5*A + 3*C)*Sqrt[b*Cos[c + d*x]]*EllipticE[(1/2)*(c + d*x), 2])/(5*d*Sqrt[Cos[c + d*x]]) + (2*b*B*Sqrt[Cos[c + d*x]]*EllipticF[(1/2)*(c + d*x), 2])/(3*d*Sqrt[b*Cos[c + d*x]]) + (2*B*Sqrt[b*Cos[c + d*x]]*Sin[c + d*x])/(3*d) + (2*C*(b*Cos[c + d*x])^(3/2)*Sin[c + d*x])/(5*b*d)}
{Sqrt[b*Cos[c + d*x]]*(A + B*Cos[c + d*x] + C*Cos[c + d*x]^2)*Sec[c + d*x], x, 7, (2*B*Sqrt[b*Cos[c + d*x]]*EllipticE[(1/2)*(c + d*x), 2])/(d*Sqrt[Cos[c + d*x]]) + (2*b*(3*A + C)*Sqrt[Cos[c + d*x]]*EllipticF[(1/2)*(c + d*x), 2])/(3*d*Sqrt[b*Cos[c + d*x]]) + (2*C*Sqrt[b*Cos[c + d*x]]*Sin[c + d*x])/(3*d)}
{Sqrt[b*Cos[c + d*x]]*(A + B*Cos[c + d*x] + C*Cos[c + d*x]^2)*Sec[c + d*x]^2, x, 7, -((2*(A - C)*Sqrt[b*Cos[c + d*x]]*EllipticE[(1/2)*(c + d*x), 2])/(d*Sqrt[Cos[c + d*x]])) + (2*b*B*Sqrt[Cos[c + d*x]]*EllipticF[(1/2)*(c + d*x), 2])/(d*Sqrt[b*Cos[c + d*x]]) + (2*A*b*Sin[c + d*x])/(d*Sqrt[b*Cos[c + d*x]])}
{Sqrt[b*Cos[c + d*x]]*(A + B*Cos[c + d*x] + C*Cos[c + d*x]^2)*Sec[c + d*x]^3, x, 8, -((2*B*Sqrt[b*Cos[c + d*x]]*EllipticE[(1/2)*(c + d*x), 2])/(d*Sqrt[Cos[c + d*x]])) + (2*b*(A + 3*C)*Sqrt[Cos[c + d*x]]*EllipticF[(1/2)*(c + d*x), 2])/(3*d*Sqrt[b*Cos[c + d*x]]) + (2*A*b^2*Sin[c + d*x])/(3*d*(b*Cos[c + d*x])^(3/2)) + (2*b*B*Sin[c + d*x])/(d*Sqrt[b*Cos[c + d*x]])}
{Sqrt[b*Cos[c + d*x]]*(A + B*Cos[c + d*x] + C*Cos[c + d*x]^2)*Sec[c + d*x]^4, x, 9, -((2*(3*A + 5*C)*Sqrt[b*Cos[c + d*x]]*EllipticE[(1/2)*(c + d*x), 2])/(5*d*Sqrt[Cos[c + d*x]])) + (2*b*B*Sqrt[Cos[c + d*x]]*EllipticF[(1/2)*(c + d*x), 2])/(3*d*Sqrt[b*Cos[c + d*x]]) + (2*A*b^3*Sin[c + d*x])/(5*d*(b*Cos[c + d*x])^(5/2)) + (2*b^2*B*Sin[c + d*x])/(3*d*(b*Cos[c + d*x])^(3/2)) + (2*b*(3*A + 5*C)*Sin[c + d*x])/(5*d*Sqrt[b*Cos[c + d*x]])}
{Sqrt[b*Cos[c + d*x]]*(A + B*Cos[c + d*x] + C*Cos[c + d*x]^2)*Sec[c + d*x]^5, x, 10, -((6*B*Sqrt[b*Cos[c + d*x]]*EllipticE[(1/2)*(c + d*x), 2])/(5*d*Sqrt[Cos[c + d*x]])) + (2*b*(5*A + 7*C)*Sqrt[Cos[c + d*x]]*EllipticF[(1/2)*(c + d*x), 2])/(21*d*Sqrt[b*Cos[c + d*x]]) + (2*A*b^4*Sin[c + d*x])/(7*d*(b*Cos[c + d*x])^(7/2)) + (2*b^3*B*Sin[c + d*x])/(5*d*(b*Cos[c + d*x])^(5/2)) + (2*b^2*(5*A + 7*C)*Sin[c + d*x])/(21*d*(b*Cos[c + d*x])^(3/2)) + (6*b*B*Sin[c + d*x])/(5*d*Sqrt[b*Cos[c + d*x]])}


{Cos[c + d*x]*(b*Cos[c + d*x])^(3/2)*(A + B*Cos[c + d*x] + C*Cos[c + d*x]^2), x, 10, (2*b*(9*A + 7*C)*Sqrt[b*Cos[c + d*x]]*EllipticE[(1/2)*(c + d*x), 2])/(15*d*Sqrt[Cos[c + d*x]]) + (10*b^2*B*Sqrt[Cos[c + d*x]]*EllipticF[(1/2)*(c + d*x), 2])/(21*d*Sqrt[b*Cos[c + d*x]]) + (10*b*B*Sqrt[b*Cos[c + d*x]]*Sin[c + d*x])/(21*d) + (2*(9*A + 7*C)*(b*Cos[c + d*x])^(3/2)*Sin[c + d*x])/(45*d) + (2*B*(b*Cos[c + d*x])^(5/2)*Sin[c + d*x])/(7*b*d) + (2*C*(b*Cos[c + d*x])^(7/2)*Sin[c + d*x])/(9*b^2*d)}
{(b*Cos[c + d*x])^(3/2)*(A + B*Cos[c + d*x] + C*Cos[c + d*x]^2), x, 8, (6*b*B*Sqrt[b*Cos[c + d*x]]*EllipticE[(1/2)*(c + d*x), 2])/(5*d*Sqrt[Cos[c + d*x]]) + (2*b^2*(7*A + 5*C)*Sqrt[Cos[c + d*x]]*EllipticF[(1/2)*(c + d*x), 2])/(21*d*Sqrt[b*Cos[c + d*x]]) + (2*b*(7*A + 5*C)*Sqrt[b*Cos[c + d*x]]*Sin[c + d*x])/(21*d) + (2*B*(b*Cos[c + d*x])^(3/2)*Sin[c + d*x])/(5*d) + (2*C*(b*Cos[c + d*x])^(5/2)*Sin[c + d*x])/(7*b*d)}
{(b*Cos[c + d*x])^(3/2)*(A + B*Cos[c + d*x] + C*Cos[c + d*x]^2)*Sec[c + d*x], x, 8, (2*b*(5*A + 3*C)*Sqrt[b*Cos[c + d*x]]*EllipticE[(1/2)*(c + d*x), 2])/(5*d*Sqrt[Cos[c + d*x]]) + (2*b^2*B*Sqrt[Cos[c + d*x]]*EllipticF[(1/2)*(c + d*x), 2])/(3*d*Sqrt[b*Cos[c + d*x]]) + (2*b*B*Sqrt[b*Cos[c + d*x]]*Sin[c + d*x])/(3*d) + (2*C*(b*Cos[c + d*x])^(3/2)*Sin[c + d*x])/(5*d)}
{(b*Cos[c + d*x])^(3/2)*(A + B*Cos[c + d*x] + C*Cos[c + d*x]^2)*Sec[c + d*x]^2, x, 7, (2*b*B*Sqrt[b*Cos[c + d*x]]*EllipticE[(1/2)*(c + d*x), 2])/(d*Sqrt[Cos[c + d*x]]) + (2*b^2*(3*A + C)*Sqrt[Cos[c + d*x]]*EllipticF[(1/2)*(c + d*x), 2])/(3*d*Sqrt[b*Cos[c + d*x]]) + (2*b*C*Sqrt[b*Cos[c + d*x]]*Sin[c + d*x])/(3*d)}
{(b*Cos[c + d*x])^(3/2)*(A + B*Cos[c + d*x] + C*Cos[c + d*x]^2)*Sec[c + d*x]^3, x, 7, -((2*b*(A - C)*Sqrt[b*Cos[c + d*x]]*EllipticE[(1/2)*(c + d*x), 2])/(d*Sqrt[Cos[c + d*x]])) + (2*b^2*B*Sqrt[Cos[c + d*x]]*EllipticF[(1/2)*(c + d*x), 2])/(d*Sqrt[b*Cos[c + d*x]]) + (2*A*b^2*Sin[c + d*x])/(d*Sqrt[b*Cos[c + d*x]])}
{(b*Cos[c + d*x])^(3/2)*(A + B*Cos[c + d*x] + C*Cos[c + d*x]^2)*Sec[c + d*x]^4, x, 8, -((2*b*B*Sqrt[b*Cos[c + d*x]]*EllipticE[(1/2)*(c + d*x), 2])/(d*Sqrt[Cos[c + d*x]])) + (2*b^2*(A + 3*C)*Sqrt[Cos[c + d*x]]*EllipticF[(1/2)*(c + d*x), 2])/(3*d*Sqrt[b*Cos[c + d*x]]) + (2*A*b^3*Sin[c + d*x])/(3*d*(b*Cos[c + d*x])^(3/2)) + (2*b^2*B*Sin[c + d*x])/(d*Sqrt[b*Cos[c + d*x]])}
{(b*Cos[c + d*x])^(3/2)*(A + B*Cos[c + d*x] + C*Cos[c + d*x]^2)*Sec[c + d*x]^5, x, 9, -((2*b*(3*A + 5*C)*Sqrt[b*Cos[c + d*x]]*EllipticE[(1/2)*(c + d*x), 2])/(5*d*Sqrt[Cos[c + d*x]])) + (2*b^2*B*Sqrt[Cos[c + d*x]]*EllipticF[(1/2)*(c + d*x), 2])/(3*d*Sqrt[b*Cos[c + d*x]]) + (2*A*b^4*Sin[c + d*x])/(5*d*(b*Cos[c + d*x])^(5/2)) + (2*b^3*B*Sin[c + d*x])/(3*d*(b*Cos[c + d*x])^(3/2)) + (2*b^2*(3*A + 5*C)*Sin[c + d*x])/(5*d*Sqrt[b*Cos[c + d*x]])}
{(b*Cos[c + d*x])^(3/2)*(A + B*Cos[c + d*x] + C*Cos[c + d*x]^2)*Sec[c + d*x]^6, x, 10, -((6*b*B*Sqrt[b*Cos[c + d*x]]*EllipticE[(1/2)*(c + d*x), 2])/(5*d*Sqrt[Cos[c + d*x]])) + (2*b^2*(5*A + 7*C)*Sqrt[Cos[c + d*x]]*EllipticF[(1/2)*(c + d*x), 2])/(21*d*Sqrt[b*Cos[c + d*x]]) + (2*A*b^5*Sin[c + d*x])/(7*d*(b*Cos[c + d*x])^(7/2)) + (2*b^4*B*Sin[c + d*x])/(5*d*(b*Cos[c + d*x])^(5/2)) + (2*b^3*(5*A + 7*C)*Sin[c + d*x])/(21*d*(b*Cos[c + d*x])^(3/2)) + (6*b^2*B*Sin[c + d*x])/(5*d*Sqrt[b*Cos[c + d*x]])}


{(b*Cos[c + d*x])^(5/2)*(A + B*Cos[c + d*x] + C*Cos[c + d*x]^2), x, 9, (2*b^2*(9*A + 7*C)*Sqrt[b*Cos[c + d*x]]*EllipticE[(1/2)*(c + d*x), 2])/(15*d*Sqrt[Cos[c + d*x]]) + (10*b^3*B*Sqrt[Cos[c + d*x]]*EllipticF[(1/2)*(c + d*x), 2])/(21*d*Sqrt[b*Cos[c + d*x]]) + (10*b^2*B*Sqrt[b*Cos[c + d*x]]*Sin[c + d*x])/(21*d) + (2*b*(9*A + 7*C)*(b*Cos[c + d*x])^(3/2)*Sin[c + d*x])/(45*d) + (2*B*(b*Cos[c + d*x])^(5/2)*Sin[c + d*x])/(7*d) + (2*C*(b*Cos[c + d*x])^(7/2)*Sin[c + d*x])/(9*b*d)}
{(b*Cos[c + d*x])^(5/2)*(A + B*Cos[c + d*x] + C*Cos[c + d*x]^2)*Sec[c + d*x], x, 9, (6*b^2*B*Sqrt[b*Cos[c + d*x]]*EllipticE[(1/2)*(c + d*x), 2])/(5*d*Sqrt[Cos[c + d*x]]) + (2*b^3*(7*A + 5*C)*Sqrt[Cos[c + d*x]]*EllipticF[(1/2)*(c + d*x), 2])/(21*d*Sqrt[b*Cos[c + d*x]]) + (2*b^2*(7*A + 5*C)*Sqrt[b*Cos[c + d*x]]*Sin[c + d*x])/(21*d) + (2*b*B*(b*Cos[c + d*x])^(3/2)*Sin[c + d*x])/(5*d) + (2*C*(b*Cos[c + d*x])^(5/2)*Sin[c + d*x])/(7*d)}
{(b*Cos[c + d*x])^(5/2)*(A + B*Cos[c + d*x] + C*Cos[c + d*x]^2)*Sec[c + d*x]^2, x, 8, (2*b^2*(5*A + 3*C)*Sqrt[b*Cos[c + d*x]]*EllipticE[(1/2)*(c + d*x), 2])/(5*d*Sqrt[Cos[c + d*x]]) + (2*b^3*B*Sqrt[Cos[c + d*x]]*EllipticF[(1/2)*(c + d*x), 2])/(3*d*Sqrt[b*Cos[c + d*x]]) + (2*b^2*B*Sqrt[b*Cos[c + d*x]]*Sin[c + d*x])/(3*d) + (2*b*C*(b*Cos[c + d*x])^(3/2)*Sin[c + d*x])/(5*d)}
{(b*Cos[c + d*x])^(5/2)*(A + B*Cos[c + d*x] + C*Cos[c + d*x]^2)*Sec[c + d*x]^3, x, 7, (2*b^2*B*Sqrt[b*Cos[c + d*x]]*EllipticE[(1/2)*(c + d*x), 2])/(d*Sqrt[Cos[c + d*x]]) + (2*b^3*(3*A + C)*Sqrt[Cos[c + d*x]]*EllipticF[(1/2)*(c + d*x), 2])/(3*d*Sqrt[b*Cos[c + d*x]]) + (2*b^2*C*Sqrt[b*Cos[c + d*x]]*Sin[c + d*x])/(3*d)}
{(b*Cos[c + d*x])^(5/2)*(A + B*Cos[c + d*x] + C*Cos[c + d*x]^2)*Sec[c + d*x]^4, x, 7, -((2*b^2*(A - C)*Sqrt[b*Cos[c + d*x]]*EllipticE[(1/2)*(c + d*x), 2])/(d*Sqrt[Cos[c + d*x]])) + (2*b^3*B*Sqrt[Cos[c + d*x]]*EllipticF[(1/2)*(c + d*x), 2])/(d*Sqrt[b*Cos[c + d*x]]) + (2*A*b^3*Sin[c + d*x])/(d*Sqrt[b*Cos[c + d*x]])}
{(b*Cos[c + d*x])^(5/2)*(A + B*Cos[c + d*x] + C*Cos[c + d*x]^2)*Sec[c + d*x]^5, x, 8, -((2*b^2*B*Sqrt[b*Cos[c + d*x]]*EllipticE[(1/2)*(c + d*x), 2])/(d*Sqrt[Cos[c + d*x]])) + (2*b^3*(A + 3*C)*Sqrt[Cos[c + d*x]]*EllipticF[(1/2)*(c + d*x), 2])/(3*d*Sqrt[b*Cos[c + d*x]]) + (2*A*b^4*Sin[c + d*x])/(3*d*(b*Cos[c + d*x])^(3/2)) + (2*b^3*B*Sin[c + d*x])/(d*Sqrt[b*Cos[c + d*x]])}
{(b*Cos[c + d*x])^(5/2)*(A + B*Cos[c + d*x] + C*Cos[c + d*x]^2)*Sec[c + d*x]^6, x, 9, -((2*b^2*(3*A + 5*C)*Sqrt[b*Cos[c + d*x]]*EllipticE[(1/2)*(c + d*x), 2])/(5*d*Sqrt[Cos[c + d*x]])) + (2*b^3*B*Sqrt[Cos[c + d*x]]*EllipticF[(1/2)*(c + d*x), 2])/(3*d*Sqrt[b*Cos[c + d*x]]) + (2*A*b^5*Sin[c + d*x])/(5*d*(b*Cos[c + d*x])^(5/2)) + (2*b^4*B*Sin[c + d*x])/(3*d*(b*Cos[c + d*x])^(3/2)) + (2*b^3*(3*A + 5*C)*Sin[c + d*x])/(5*d*Sqrt[b*Cos[c + d*x]])}
{(b*Cos[c + d*x])^(5/2)*(A + B*Cos[c + d*x] + C*Cos[c + d*x]^2)*Sec[c + d*x]^7, x, 10, -((6*b^2*B*Sqrt[b*Cos[c + d*x]]*EllipticE[(1/2)*(c + d*x), 2])/(5*d*Sqrt[Cos[c + d*x]])) + (2*b^3*(5*A + 7*C)*Sqrt[Cos[c + d*x]]*EllipticF[(1/2)*(c + d*x), 2])/(21*d*Sqrt[b*Cos[c + d*x]]) + (2*A*b^6*Sin[c + d*x])/(7*d*(b*Cos[c + d*x])^(7/2)) + (2*b^5*B*Sin[c + d*x])/(5*d*(b*Cos[c + d*x])^(5/2)) + (2*b^4*(5*A + 7*C)*Sin[c + d*x])/(21*d*(b*Cos[c + d*x])^(3/2)) + (6*b^3*B*Sin[c + d*x])/(5*d*Sqrt[b*Cos[c + d*x]])}


(* ::Subsubsection::Closed:: *)
(*n<0*)


{(Cos[c + d*x]^3*(A + B*Cos[c + d*x] + C*Cos[c + d*x]^2))/Sqrt[b*Cos[c + d*x]], x, 10, (2*(9*A + 7*C)*Sqrt[b*Cos[c + d*x]]*EllipticE[(1/2)*(c + d*x), 2])/(15*b*d*Sqrt[Cos[c + d*x]]) + (10*B*Sqrt[Cos[c + d*x]]*EllipticF[(1/2)*(c + d*x), 2])/(21*d*Sqrt[b*Cos[c + d*x]]) + (10*B*Sqrt[b*Cos[c + d*x]]*Sin[c + d*x])/(21*b*d) + (2*(9*A + 7*C)*(b*Cos[c + d*x])^(3/2)*Sin[c + d*x])/(45*b^2*d) + (2*B*(b*Cos[c + d*x])^(5/2)*Sin[c + d*x])/(7*b^3*d) + (2*C*(b*Cos[c + d*x])^(7/2)*Sin[c + d*x])/(9*b^4*d)}
{(Cos[c + d*x]^2*(A + B*Cos[c + d*x] + C*Cos[c + d*x]^2))/Sqrt[b*Cos[c + d*x]], x, 9, (6*B*Sqrt[b*Cos[c + d*x]]*EllipticE[(1/2)*(c + d*x), 2])/(5*b*d*Sqrt[Cos[c + d*x]]) + (2*(7*A + 5*C)*Sqrt[Cos[c + d*x]]*EllipticF[(1/2)*(c + d*x), 2])/(21*d*Sqrt[b*Cos[c + d*x]]) + (2*(7*A + 5*C)*Sqrt[b*Cos[c + d*x]]*Sin[c + d*x])/(21*b*d) + (2*B*(b*Cos[c + d*x])^(3/2)*Sin[c + d*x])/(5*b^2*d) + (2*C*(b*Cos[c + d*x])^(5/2)*Sin[c + d*x])/(7*b^3*d)}
{(Cos[c + d*x]*(A + B*Cos[c + d*x] + C*Cos[c + d*x]^2))/Sqrt[b*Cos[c + d*x]], x, 8, (2*(5*A + 3*C)*Sqrt[b*Cos[c + d*x]]*EllipticE[(1/2)*(c + d*x), 2])/(5*b*d*Sqrt[Cos[c + d*x]]) + (2*B*Sqrt[Cos[c + d*x]]*EllipticF[(1/2)*(c + d*x), 2])/(3*d*Sqrt[b*Cos[c + d*x]]) + (2*B*Sqrt[b*Cos[c + d*x]]*Sin[c + d*x])/(3*b*d) + (2*C*(b*Cos[c + d*x])^(3/2)*Sin[c + d*x])/(5*b^2*d)}
{(A + B*Cos[c + d*x] + C*Cos[c + d*x]^2)/Sqrt[b*Cos[c + d*x]], x, 6, (2*B*Sqrt[b*Cos[c + d*x]]*EllipticE[(1/2)*(c + d*x), 2])/(b*d*Sqrt[Cos[c + d*x]]) + (2*(3*A + C)*Sqrt[Cos[c + d*x]]*EllipticF[(1/2)*(c + d*x), 2])/(3*d*Sqrt[b*Cos[c + d*x]]) + (2*C*Sqrt[b*Cos[c + d*x]]*Sin[c + d*x])/(3*b*d)}
{((A + B*Cos[c + d*x] + C*Cos[c + d*x]^2)*Sec[c + d*x])/Sqrt[b*Cos[c + d*x]], x, 7, -((2*(A - C)*Sqrt[b*Cos[c + d*x]]*EllipticE[(1/2)*(c + d*x), 2])/(b*d*Sqrt[Cos[c + d*x]])) + (2*B*Sqrt[Cos[c + d*x]]*EllipticF[(1/2)*(c + d*x), 2])/(d*Sqrt[b*Cos[c + d*x]]) + (2*A*Sin[c + d*x])/(d*Sqrt[b*Cos[c + d*x]])}
{((A + B*Cos[c + d*x] + C*Cos[c + d*x]^2)*Sec[c + d*x]^2)/Sqrt[b*Cos[c + d*x]], x, 8, -((2*B*Sqrt[b*Cos[c + d*x]]*EllipticE[(1/2)*(c + d*x), 2])/(b*d*Sqrt[Cos[c + d*x]])) + (2*(A + 3*C)*Sqrt[Cos[c + d*x]]*EllipticF[(1/2)*(c + d*x), 2])/(3*d*Sqrt[b*Cos[c + d*x]]) + (2*A*b*Sin[c + d*x])/(3*d*(b*Cos[c + d*x])^(3/2)) + (2*B*Sin[c + d*x])/(d*Sqrt[b*Cos[c + d*x]])}
{((A + B*Cos[c + d*x] + C*Cos[c + d*x]^2)*Sec[c + d*x]^3)/Sqrt[b*Cos[c + d*x]], x, 9, -((2*(3*A + 5*C)*Sqrt[b*Cos[c + d*x]]*EllipticE[(1/2)*(c + d*x), 2])/(5*b*d*Sqrt[Cos[c + d*x]])) + (2*B*Sqrt[Cos[c + d*x]]*EllipticF[(1/2)*(c + d*x), 2])/(3*d*Sqrt[b*Cos[c + d*x]]) + (2*A*b^2*Sin[c + d*x])/(5*d*(b*Cos[c + d*x])^(5/2)) + (2*b*B*Sin[c + d*x])/(3*d*(b*Cos[c + d*x])^(3/2)) + (2*(3*A + 5*C)*Sin[c + d*x])/(5*d*Sqrt[b*Cos[c + d*x]])}
{((A + B*Cos[c + d*x] + C*Cos[c + d*x]^2)*Sec[c + d*x]^4)/Sqrt[b*Cos[c + d*x]], x, 10, -((6*B*Sqrt[b*Cos[c + d*x]]*EllipticE[(1/2)*(c + d*x), 2])/(5*b*d*Sqrt[Cos[c + d*x]])) + (2*(5*A + 7*C)*Sqrt[Cos[c + d*x]]*EllipticF[(1/2)*(c + d*x), 2])/(21*d*Sqrt[b*Cos[c + d*x]]) + (2*A*b^3*Sin[c + d*x])/(7*d*(b*Cos[c + d*x])^(7/2)) + (2*b^2*B*Sin[c + d*x])/(5*d*(b*Cos[c + d*x])^(5/2)) + (2*b*(5*A + 7*C)*Sin[c + d*x])/(21*d*(b*Cos[c + d*x])^(3/2)) + (6*B*Sin[c + d*x])/(5*d*Sqrt[b*Cos[c + d*x]])}


{(Cos[c + d*x]^4*(A + B*Cos[c + d*x] + C*Cos[c + d*x]^2))/(b*Cos[c + d*x])^(3/2), x, 10, (2*(9*A + 7*C)*Sqrt[b*Cos[c + d*x]]*EllipticE[(1/2)*(c + d*x), 2])/(15*b^2*d*Sqrt[Cos[c + d*x]]) + (10*B*Sqrt[Cos[c + d*x]]*EllipticF[(1/2)*(c + d*x), 2])/(21*b*d*Sqrt[b*Cos[c + d*x]]) + (10*B*Sqrt[b*Cos[c + d*x]]*Sin[c + d*x])/(21*b^2*d) + (2*(9*A + 7*C)*(b*Cos[c + d*x])^(3/2)*Sin[c + d*x])/(45*b^3*d) + (2*B*(b*Cos[c + d*x])^(5/2)*Sin[c + d*x])/(7*b^4*d) + (2*C*(b*Cos[c + d*x])^(7/2)*Sin[c + d*x])/(9*b^5*d)}
{(Cos[c + d*x]^3*(A + B*Cos[c + d*x] + C*Cos[c + d*x]^2))/(b*Cos[c + d*x])^(3/2), x, 9, (6*B*Sqrt[b*Cos[c + d*x]]*EllipticE[(1/2)*(c + d*x), 2])/(5*b^2*d*Sqrt[Cos[c + d*x]]) + (2*(7*A + 5*C)*Sqrt[Cos[c + d*x]]*EllipticF[(1/2)*(c + d*x), 2])/(21*b*d*Sqrt[b*Cos[c + d*x]]) + (2*(7*A + 5*C)*Sqrt[b*Cos[c + d*x]]*Sin[c + d*x])/(21*b^2*d) + (2*B*(b*Cos[c + d*x])^(3/2)*Sin[c + d*x])/(5*b^3*d) + (2*C*(b*Cos[c + d*x])^(5/2)*Sin[c + d*x])/(7*b^4*d)}
{(Cos[c + d*x]^2*(A + B*Cos[c + d*x] + C*Cos[c + d*x]^2))/(b*Cos[c + d*x])^(3/2), x, 8, (2*(5*A + 3*C)*Sqrt[b*Cos[c + d*x]]*EllipticE[(1/2)*(c + d*x), 2])/(5*b^2*d*Sqrt[Cos[c + d*x]]) + (2*B*Sqrt[Cos[c + d*x]]*EllipticF[(1/2)*(c + d*x), 2])/(3*b*d*Sqrt[b*Cos[c + d*x]]) + (2*B*Sqrt[b*Cos[c + d*x]]*Sin[c + d*x])/(3*b^2*d) + (2*C*(b*Cos[c + d*x])^(3/2)*Sin[c + d*x])/(5*b^3*d)}
{(Cos[c + d*x]*(A + B*Cos[c + d*x] + C*Cos[c + d*x]^2))/(b*Cos[c + d*x])^(3/2), x, 7, (2*B*Sqrt[b*Cos[c + d*x]]*EllipticE[(1/2)*(c + d*x), 2])/(b^2*d*Sqrt[Cos[c + d*x]]) + (2*(3*A + C)*Sqrt[Cos[c + d*x]]*EllipticF[(1/2)*(c + d*x), 2])/(3*b*d*Sqrt[b*Cos[c + d*x]]) + (2*C*Sqrt[b*Cos[c + d*x]]*Sin[c + d*x])/(3*b^2*d)}
{(A + B*Cos[c + d*x] + C*Cos[c + d*x]^2)/(b*Cos[c + d*x])^(3/2), x, 6, -((2*(A - C)*Sqrt[b*Cos[c + d*x]]*EllipticE[(1/2)*(c + d*x), 2])/(b^2*d*Sqrt[Cos[c + d*x]])) + (2*B*Sqrt[Cos[c + d*x]]*EllipticF[(1/2)*(c + d*x), 2])/(b*d*Sqrt[b*Cos[c + d*x]]) + (2*A*Sin[c + d*x])/(b*d*Sqrt[b*Cos[c + d*x]])}
{((A + B*Cos[c + d*x] + C*Cos[c + d*x]^2)*Sec[c + d*x])/(b*Cos[c + d*x])^(3/2), x, 8, -((2*B*Sqrt[b*Cos[c + d*x]]*EllipticE[(1/2)*(c + d*x), 2])/(b^2*d*Sqrt[Cos[c + d*x]])) + (2*(A + 3*C)*Sqrt[Cos[c + d*x]]*EllipticF[(1/2)*(c + d*x), 2])/(3*b*d*Sqrt[b*Cos[c + d*x]]) + (2*A*Sin[c + d*x])/(3*d*(b*Cos[c + d*x])^(3/2)) + (2*B*Sin[c + d*x])/(b*d*Sqrt[b*Cos[c + d*x]])}
{((A + B*Cos[c + d*x] + C*Cos[c + d*x]^2)*Sec[c + d*x]^2)/(b*Cos[c + d*x])^(3/2), x, 9, -((2*(3*A + 5*C)*Sqrt[b*Cos[c + d*x]]*EllipticE[(1/2)*(c + d*x), 2])/(5*b^2*d*Sqrt[Cos[c + d*x]])) + (2*B*Sqrt[Cos[c + d*x]]*EllipticF[(1/2)*(c + d*x), 2])/(3*b*d*Sqrt[b*Cos[c + d*x]]) + (2*A*b*Sin[c + d*x])/(5*d*(b*Cos[c + d*x])^(5/2)) + (2*B*Sin[c + d*x])/(3*d*(b*Cos[c + d*x])^(3/2)) + (2*(3*A + 5*C)*Sin[c + d*x])/(5*b*d*Sqrt[b*Cos[c + d*x]])}
{((A + B*Cos[c + d*x] + C*Cos[c + d*x]^2)*Sec[c + d*x]^3)/(b*Cos[c + d*x])^(3/2), x, 10, -((6*B*Sqrt[b*Cos[c + d*x]]*EllipticE[(1/2)*(c + d*x), 2])/(5*b^2*d*Sqrt[Cos[c + d*x]])) + (2*(5*A + 7*C)*Sqrt[Cos[c + d*x]]*EllipticF[(1/2)*(c + d*x), 2])/(21*b*d*Sqrt[b*Cos[c + d*x]]) + (2*A*b^2*Sin[c + d*x])/(7*d*(b*Cos[c + d*x])^(7/2)) + (2*b*B*Sin[c + d*x])/(5*d*(b*Cos[c + d*x])^(5/2)) + (2*(5*A + 7*C)*Sin[c + d*x])/(21*d*(b*Cos[c + d*x])^(3/2)) + (6*B*Sin[c + d*x])/(5*b*d*Sqrt[b*Cos[c + d*x]])}


{(Cos[c + d*x]^5*(A + B*Cos[c + d*x] + C*Cos[c + d*x]^2))/(b*Cos[c + d*x])^(5/2), x, 10, (2*(9*A + 7*C)*Sqrt[b*Cos[c + d*x]]*EllipticE[(1/2)*(c + d*x), 2])/(15*b^3*d*Sqrt[Cos[c + d*x]]) + (10*B*Sqrt[Cos[c + d*x]]*EllipticF[(1/2)*(c + d*x), 2])/(21*b^2*d*Sqrt[b*Cos[c + d*x]]) + (10*B*Sqrt[b*Cos[c + d*x]]*Sin[c + d*x])/(21*b^3*d) + (2*(9*A + 7*C)*(b*Cos[c + d*x])^(3/2)*Sin[c + d*x])/(45*b^4*d) + (2*B*(b*Cos[c + d*x])^(5/2)*Sin[c + d*x])/(7*b^5*d) + (2*C*(b*Cos[c + d*x])^(7/2)*Sin[c + d*x])/(9*b^6*d)}
{(Cos[c + d*x]^4*(A + B*Cos[c + d*x] + C*Cos[c + d*x]^2))/(b*Cos[c + d*x])^(5/2), x, 9, (6*B*Sqrt[b*Cos[c + d*x]]*EllipticE[(1/2)*(c + d*x), 2])/(5*b^3*d*Sqrt[Cos[c + d*x]]) + (2*(7*A + 5*C)*Sqrt[Cos[c + d*x]]*EllipticF[(1/2)*(c + d*x), 2])/(21*b^2*d*Sqrt[b*Cos[c + d*x]]) + (2*(7*A + 5*C)*Sqrt[b*Cos[c + d*x]]*Sin[c + d*x])/(21*b^3*d) + (2*B*(b*Cos[c + d*x])^(3/2)*Sin[c + d*x])/(5*b^4*d) + (2*C*(b*Cos[c + d*x])^(5/2)*Sin[c + d*x])/(7*b^5*d)}
{(Cos[c + d*x]^3*(A + B*Cos[c + d*x] + C*Cos[c + d*x]^2))/(b*Cos[c + d*x])^(5/2), x, 8, (2*(5*A + 3*C)*Sqrt[b*Cos[c + d*x]]*EllipticE[(1/2)*(c + d*x), 2])/(5*b^3*d*Sqrt[Cos[c + d*x]]) + (2*B*Sqrt[Cos[c + d*x]]*EllipticF[(1/2)*(c + d*x), 2])/(3*b^2*d*Sqrt[b*Cos[c + d*x]]) + (2*B*Sqrt[b*Cos[c + d*x]]*Sin[c + d*x])/(3*b^3*d) + (2*C*(b*Cos[c + d*x])^(3/2)*Sin[c + d*x])/(5*b^4*d)}
{(Cos[c + d*x]^2*(A + B*Cos[c + d*x] + C*Cos[c + d*x]^2))/(b*Cos[c + d*x])^(5/2), x, 7, (2*B*Sqrt[b*Cos[c + d*x]]*EllipticE[(1/2)*(c + d*x), 2])/(b^3*d*Sqrt[Cos[c + d*x]]) + (2*(3*A + C)*Sqrt[Cos[c + d*x]]*EllipticF[(1/2)*(c + d*x), 2])/(3*b^2*d*Sqrt[b*Cos[c + d*x]]) + (2*C*Sqrt[b*Cos[c + d*x]]*Sin[c + d*x])/(3*b^3*d)}
{(Cos[c + d*x]*(A + B*Cos[c + d*x] + C*Cos[c + d*x]^2))/(b*Cos[c + d*x])^(5/2), x, 7, -((2*(A - C)*Sqrt[b*Cos[c + d*x]]*EllipticE[(1/2)*(c + d*x), 2])/(b^3*d*Sqrt[Cos[c + d*x]])) + (2*B*Sqrt[Cos[c + d*x]]*EllipticF[(1/2)*(c + d*x), 2])/(b^2*d*Sqrt[b*Cos[c + d*x]]) + (2*A*Sin[c + d*x])/(b^2*d*Sqrt[b*Cos[c + d*x]])}
{(A + B*Cos[c + d*x] + C*Cos[c + d*x]^2)/(b*Cos[c + d*x])^(5/2), x, 7, -((2*B*Sqrt[b*Cos[c + d*x]]*EllipticE[(1/2)*(c + d*x), 2])/(b^3*d*Sqrt[Cos[c + d*x]])) + (2*(A + 3*C)*Sqrt[Cos[c + d*x]]*EllipticF[(1/2)*(c + d*x), 2])/(3*b^2*d*Sqrt[b*Cos[c + d*x]]) + (2*A*Sin[c + d*x])/(3*b*d*(b*Cos[c + d*x])^(3/2)) + (2*B*Sin[c + d*x])/(b^2*d*Sqrt[b*Cos[c + d*x]])}
{((A + B*Cos[c + d*x] + C*Cos[c + d*x]^2)*Sec[c + d*x])/(b*Cos[c + d*x])^(5/2), x, 9, -((2*(3*A + 5*C)*Sqrt[b*Cos[c + d*x]]*EllipticE[(1/2)*(c + d*x), 2])/(5*b^3*d*Sqrt[Cos[c + d*x]])) + (2*B*Sqrt[Cos[c + d*x]]*EllipticF[(1/2)*(c + d*x), 2])/(3*b^2*d*Sqrt[b*Cos[c + d*x]]) + (2*A*Sin[c + d*x])/(5*d*(b*Cos[c + d*x])^(5/2)) + (2*B*Sin[c + d*x])/(3*b*d*(b*Cos[c + d*x])^(3/2)) + (2*(3*A + 5*C)*Sin[c + d*x])/(5*b^2*d*Sqrt[b*Cos[c + d*x]])}
{((A + B*Cos[c + d*x] + C*Cos[c + d*x]^2)*Sec[c + d*x]^2)/(b*Cos[c + d*x])^(5/2), x, 10, -((6*B*Sqrt[b*Cos[c + d*x]]*EllipticE[(1/2)*(c + d*x), 2])/(5*b^3*d*Sqrt[Cos[c + d*x]])) + (2*(5*A + 7*C)*Sqrt[Cos[c + d*x]]*EllipticF[(1/2)*(c + d*x), 2])/(21*b^2*d*Sqrt[b*Cos[c + d*x]]) + (2*A*b*Sin[c + d*x])/(7*d*(b*Cos[c + d*x])^(7/2)) + (2*B*Sin[c + d*x])/(5*d*(b*Cos[c + d*x])^(5/2)) + (2*(5*A + 7*C)*Sin[c + d*x])/(21*b*d*(b*Cos[c + d*x])^(3/2)) + (6*B*Sin[c + d*x])/(5*b^2*d*Sqrt[b*Cos[c + d*x]])}


{(A + B*Cos[c + d*x] + C*Cos[c + d*x]^2)/(b*Cos[c + d*x])^(7/2), x, 8, -((2*(3*A + 5*C)*Sqrt[b*Cos[c + d*x]]*EllipticE[(1/2)*(c + d*x), 2])/(5*b^4*d*Sqrt[Cos[c + d*x]])) + (2*B*Sqrt[Cos[c + d*x]]*EllipticF[(1/2)*(c + d*x), 2])/(3*b^3*d*Sqrt[b*Cos[c + d*x]]) + (2*A*Sin[c + d*x])/(5*b*d*(b*Cos[c + d*x])^(5/2)) + (2*B*Sin[c + d*x])/(3*b^2*d*(b*Cos[c + d*x])^(3/2)) + (2*(3*A + 5*C)*Sin[c + d*x])/(5*b^3*d*Sqrt[b*Cos[c + d*x]])}


(* ::Subsection::Closed:: *)
(*Integrands of the form Cos[c+d x]^(m/2) (A+B Cos[c+d x]+C Cos[c+d x]^2) (b Cos[c+d x])^(n/2)*)


(* ::Subsubsection::Closed:: *)
(*n>0*)


{Cos[c + d*x]^(5/2)*Sqrt[b*Cos[c + d*x]]*(A + B*Cos[c + d*x] + C*Cos[c + d*x]^2), x, 7, (3*B*x*Sqrt[b*Cos[c + d*x]])/(8*Sqrt[Cos[c + d*x]]) + ((5*A + 4*C)*Sqrt[b*Cos[c + d*x]]*Sin[c + d*x])/(5*d*Sqrt[Cos[c + d*x]]) + (3*B*Sqrt[Cos[c + d*x]]*Sqrt[b*Cos[c + d*x]]*Sin[c + d*x])/(8*d) + (B*Cos[c + d*x]^(5/2)*Sqrt[b*Cos[c + d*x]]*Sin[c + d*x])/(4*d) + (C*Cos[c + d*x]^(7/2)*Sqrt[b*Cos[c + d*x]]*Sin[c + d*x])/(5*d) - ((5*A + 4*C)*Sqrt[b*Cos[c + d*x]]*Sin[c + d*x]^3)/(15*d*Sqrt[Cos[c + d*x]])}
{Cos[c + d*x]^(3/2)*Sqrt[b*Cos[c + d*x]]*(A + B*Cos[c + d*x] + C*Cos[c + d*x]^2), x, 6, ((4*A + 3*C)*x*Sqrt[b*Cos[c + d*x]])/(8*Sqrt[Cos[c + d*x]]) + (B*Sqrt[b*Cos[c + d*x]]*Sin[c + d*x])/(d*Sqrt[Cos[c + d*x]]) + ((4*A + 3*C)*Sqrt[Cos[c + d*x]]*Sqrt[b*Cos[c + d*x]]*Sin[c + d*x])/(8*d) + (C*Cos[c + d*x]^(5/2)*Sqrt[b*Cos[c + d*x]]*Sin[c + d*x])/(4*d) - (B*Sqrt[b*Cos[c + d*x]]*Sin[c + d*x]^3)/(3*d*Sqrt[Cos[c + d*x]])}
{Sqrt[Cos[c + d*x]]*Sqrt[b*Cos[c + d*x]]*(A + B*Cos[c + d*x] + C*Cos[c + d*x]^2), x, 5, (B*x*Sqrt[b*Cos[c + d*x]])/(2*Sqrt[Cos[c + d*x]]) + ((3*A + 2*C)*Sqrt[b*Cos[c + d*x]]*Sin[c + d*x])/(3*d*Sqrt[Cos[c + d*x]]) + (B*Sqrt[Cos[c + d*x]]*Sqrt[b*Cos[c + d*x]]*Sin[c + d*x])/(2*d) + (C*Cos[c + d*x]^(3/2)*Sqrt[b*Cos[c + d*x]]*Sin[c + d*x])/(3*d)}
{(Sqrt[b*Cos[c + d*x]]*(A + B*Cos[c + d*x] + C*Cos[c + d*x]^2))/Sqrt[Cos[c + d*x]], x, 4, (A*x*Sqrt[b*Cos[c + d*x]])/Sqrt[Cos[c + d*x]] + (C*x*Sqrt[b*Cos[c + d*x]])/(2*Sqrt[Cos[c + d*x]]) + (B*Sqrt[b*Cos[c + d*x]]*Sin[c + d*x])/(d*Sqrt[Cos[c + d*x]]) + (C*Sqrt[Cos[c + d*x]]*Sqrt[b*Cos[c + d*x]]*Sin[c + d*x])/(2*d)}
{(Sqrt[b*Cos[c + d*x]]*(A + B*Cos[c + d*x] + C*Cos[c + d*x]^2))/Cos[c + d*x]^(3/2), x, 4, (B*x*Sqrt[b*Cos[c + d*x]])/Sqrt[Cos[c + d*x]] + (A*ArcTanh[Sin[c + d*x]]*Sqrt[b*Cos[c + d*x]])/(d*Sqrt[Cos[c + d*x]]) + (C*Sqrt[b*Cos[c + d*x]]*Sin[c + d*x])/(d*Sqrt[Cos[c + d*x]])}
{(Sqrt[b*Cos[c + d*x]]*(A + B*Cos[c + d*x] + C*Cos[c + d*x]^2))/Cos[c + d*x]^(5/2), x, 5, (C*x*Sqrt[b*Cos[c + d*x]])/Sqrt[Cos[c + d*x]] + (B*ArcTanh[Sin[c + d*x]]*Sqrt[b*Cos[c + d*x]])/(d*Sqrt[Cos[c + d*x]]) + (A*Sqrt[b*Cos[c + d*x]]*Sin[c + d*x])/(d*Cos[c + d*x]^(3/2))}
{(Sqrt[b*Cos[c + d*x]]*(A + B*Cos[c + d*x] + C*Cos[c + d*x]^2))/Cos[c + d*x]^(7/2), x, 5, ((A + 2*C)*ArcTanh[Sin[c + d*x]]*Sqrt[b*Cos[c + d*x]])/(2*d*Sqrt[Cos[c + d*x]]) + (A*Sqrt[b*Cos[c + d*x]]*Sin[c + d*x])/(2*d*Cos[c + d*x]^(5/2)) + (B*Sqrt[b*Cos[c + d*x]]*Sin[c + d*x])/(d*Cos[c + d*x]^(3/2))}
{(Sqrt[b*Cos[c + d*x]]*(A + B*Cos[c + d*x] + C*Cos[c + d*x]^2))/Cos[c + d*x]^(9/2), x, 6, (B*ArcTanh[Sin[c + d*x]]*Sqrt[b*Cos[c + d*x]])/(2*d*Sqrt[Cos[c + d*x]]) + (A*Sqrt[b*Cos[c + d*x]]*Sin[c + d*x])/(3*d*Cos[c + d*x]^(7/2)) + (B*Sqrt[b*Cos[c + d*x]]*Sin[c + d*x])/(2*d*Cos[c + d*x]^(5/2)) + ((2*A + 3*C)*Sqrt[b*Cos[c + d*x]]*Sin[c + d*x])/(3*d*Cos[c + d*x]^(3/2))}
{(Sqrt[b*Cos[c + d*x]]*(A + B*Cos[c + d*x] + C*Cos[c + d*x]^2))/Cos[c + d*x]^(11/2), x, 7, ((3*A + 4*C)*ArcTanh[Sin[c + d*x]]*Sqrt[b*Cos[c + d*x]])/(8*d*Sqrt[Cos[c + d*x]]) + (A*Sqrt[b*Cos[c + d*x]]*Sin[c + d*x])/(4*d*Cos[c + d*x]^(9/2)) + ((3*A + 4*C)*Sqrt[b*Cos[c + d*x]]*Sin[c + d*x])/(8*d*Cos[c + d*x]^(5/2)) + (B*Sqrt[b*Cos[c + d*x]]*Sin[c + d*x])/(d*Cos[c + d*x]^(3/2)) + (B*Sqrt[b*Cos[c + d*x]]*Sin[c + d*x]^3)/(3*d*Cos[c + d*x]^(7/2))}


{Cos[c + d*x]^(3/2)*(b*Cos[c + d*x])^(3/2)*(A + B*Cos[c + d*x] + C*Cos[c + d*x]^2), x, 7, (3*b*B*x*Sqrt[b*Cos[c + d*x]])/(8*Sqrt[Cos[c + d*x]]) + (b*(5*A + 4*C)*Sqrt[b*Cos[c + d*x]]*Sin[c + d*x])/(5*d*Sqrt[Cos[c + d*x]]) + (3*b*B*Sqrt[Cos[c + d*x]]*Sqrt[b*Cos[c + d*x]]*Sin[c + d*x])/(8*d) + (b*B*Cos[c + d*x]^(5/2)*Sqrt[b*Cos[c + d*x]]*Sin[c + d*x])/(4*d) + (b*C*Cos[c + d*x]^(7/2)*Sqrt[b*Cos[c + d*x]]*Sin[c + d*x])/(5*d) - (b*(5*A + 4*C)*Sqrt[b*Cos[c + d*x]]*Sin[c + d*x]^3)/(15*d*Sqrt[Cos[c + d*x]])}
{Sqrt[Cos[c + d*x]]*(b*Cos[c + d*x])^(3/2)*(A + B*Cos[c + d*x] + C*Cos[c + d*x]^2), x, 6, (b*(4*A + 3*C)*x*Sqrt[b*Cos[c + d*x]])/(8*Sqrt[Cos[c + d*x]]) + (b*B*Sqrt[b*Cos[c + d*x]]*Sin[c + d*x])/(d*Sqrt[Cos[c + d*x]]) + (b*(4*A + 3*C)*Sqrt[Cos[c + d*x]]*Sqrt[b*Cos[c + d*x]]*Sin[c + d*x])/(8*d) + (b*C*Cos[c + d*x]^(5/2)*Sqrt[b*Cos[c + d*x]]*Sin[c + d*x])/(4*d) - (b*B*Sqrt[b*Cos[c + d*x]]*Sin[c + d*x]^3)/(3*d*Sqrt[Cos[c + d*x]])}
{((b*Cos[c + d*x])^(3/2)*(A + B*Cos[c + d*x] + C*Cos[c + d*x]^2))/Sqrt[Cos[c + d*x]], x, 5, (b*B*x*Sqrt[b*Cos[c + d*x]])/(2*Sqrt[Cos[c + d*x]]) + (b*(3*A + 2*C)*Sqrt[b*Cos[c + d*x]]*Sin[c + d*x])/(3*d*Sqrt[Cos[c + d*x]]) + (b*B*Sqrt[Cos[c + d*x]]*Sqrt[b*Cos[c + d*x]]*Sin[c + d*x])/(2*d) + (b*C*Cos[c + d*x]^(3/2)*Sqrt[b*Cos[c + d*x]]*Sin[c + d*x])/(3*d)}
{((b*Cos[c + d*x])^(3/2)*(A + B*Cos[c + d*x] + C*Cos[c + d*x]^2))/Cos[c + d*x]^(3/2), x, 4, (A*b*x*Sqrt[b*Cos[c + d*x]])/Sqrt[Cos[c + d*x]] + (b*C*x*Sqrt[b*Cos[c + d*x]])/(2*Sqrt[Cos[c + d*x]]) + (b*B*Sqrt[b*Cos[c + d*x]]*Sin[c + d*x])/(d*Sqrt[Cos[c + d*x]]) + (b*C*Sqrt[Cos[c + d*x]]*Sqrt[b*Cos[c + d*x]]*Sin[c + d*x])/(2*d)}
{((b*Cos[c + d*x])^(3/2)*(A + B*Cos[c + d*x] + C*Cos[c + d*x]^2))/Cos[c + d*x]^(5/2), x, 4, (b*B*x*Sqrt[b*Cos[c + d*x]])/Sqrt[Cos[c + d*x]] + (A*b*ArcTanh[Sin[c + d*x]]*Sqrt[b*Cos[c + d*x]])/(d*Sqrt[Cos[c + d*x]]) + (b*C*Sqrt[b*Cos[c + d*x]]*Sin[c + d*x])/(d*Sqrt[Cos[c + d*x]])}
{((b*Cos[c + d*x])^(3/2)*(A + B*Cos[c + d*x] + C*Cos[c + d*x]^2))/Cos[c + d*x]^(7/2), x, 5, (b*C*x*Sqrt[b*Cos[c + d*x]])/Sqrt[Cos[c + d*x]] + (b*B*ArcTanh[Sin[c + d*x]]*Sqrt[b*Cos[c + d*x]])/(d*Sqrt[Cos[c + d*x]]) + (A*b*Sqrt[b*Cos[c + d*x]]*Sin[c + d*x])/(d*Cos[c + d*x]^(3/2))}
{((b*Cos[c + d*x])^(3/2)*(A + B*Cos[c + d*x] + C*Cos[c + d*x]^2))/Cos[c + d*x]^(9/2), x, 5, (b*(A + 2*C)*ArcTanh[Sin[c + d*x]]*Sqrt[b*Cos[c + d*x]])/(2*d*Sqrt[Cos[c + d*x]]) + (A*b*Sqrt[b*Cos[c + d*x]]*Sin[c + d*x])/(2*d*Cos[c + d*x]^(5/2)) + (b*B*Sqrt[b*Cos[c + d*x]]*Sin[c + d*x])/(d*Cos[c + d*x]^(3/2))}
{((b*Cos[c + d*x])^(3/2)*(A + B*Cos[c + d*x] + C*Cos[c + d*x]^2))/Cos[c + d*x]^(11/2), x, 6, (b*B*ArcTanh[Sin[c + d*x]]*Sqrt[b*Cos[c + d*x]])/(2*d*Sqrt[Cos[c + d*x]]) + (A*b*Sqrt[b*Cos[c + d*x]]*Sin[c + d*x])/(3*d*Cos[c + d*x]^(7/2)) + (b*B*Sqrt[b*Cos[c + d*x]]*Sin[c + d*x])/(2*d*Cos[c + d*x]^(5/2)) + (b*(2*A + 3*C)*Sqrt[b*Cos[c + d*x]]*Sin[c + d*x])/(3*d*Cos[c + d*x]^(3/2))}
{((b*Cos[c + d*x])^(3/2)*(A + B*Cos[c + d*x] + C*Cos[c + d*x]^2))/Cos[c + d*x]^(13/2), x, 7, (b*(3*A + 4*C)*ArcTanh[Sin[c + d*x]]*Sqrt[b*Cos[c + d*x]])/(8*d*Sqrt[Cos[c + d*x]]) + (A*b*Sqrt[b*Cos[c + d*x]]*Sin[c + d*x])/(4*d*Cos[c + d*x]^(9/2)) + (b*(3*A + 4*C)*Sqrt[b*Cos[c + d*x]]*Sin[c + d*x])/(8*d*Cos[c + d*x]^(5/2)) + (b*B*Sqrt[b*Cos[c + d*x]]*Sin[c + d*x])/(d*Cos[c + d*x]^(3/2)) + (b*B*Sqrt[b*Cos[c + d*x]]*Sin[c + d*x]^3)/(3*d*Cos[c + d*x]^(7/2))}


{Sqrt[Cos[c + d*x]]*(b*Cos[c + d*x])^(5/2)*(A + B*Cos[c + d*x] + C*Cos[c + d*x]^2), x, 7, (3*b^2*B*x*Sqrt[b*Cos[c + d*x]])/(8*Sqrt[Cos[c + d*x]]) + (b^2*(5*A + 4*C)*Sqrt[b*Cos[c + d*x]]*Sin[c + d*x])/(5*d*Sqrt[Cos[c + d*x]]) + (3*b^2*B*Sqrt[Cos[c + d*x]]*Sqrt[b*Cos[c + d*x]]*Sin[c + d*x])/(8*d) + (b^2*B*Cos[c + d*x]^(5/2)*Sqrt[b*Cos[c + d*x]]*Sin[c + d*x])/(4*d) + (b^2*C*Cos[c + d*x]^(7/2)*Sqrt[b*Cos[c + d*x]]*Sin[c + d*x])/(5*d) - (b^2*(5*A + 4*C)*Sqrt[b*Cos[c + d*x]]*Sin[c + d*x]^3)/(15*d*Sqrt[Cos[c + d*x]])}
{((b*Cos[c + d*x])^(5/2)*(A + B*Cos[c + d*x] + C*Cos[c + d*x]^2))/Sqrt[Cos[c + d*x]], x, 6, (b^2*(4*A + 3*C)*x*Sqrt[b*Cos[c + d*x]])/(8*Sqrt[Cos[c + d*x]]) + (b^2*B*Sqrt[b*Cos[c + d*x]]*Sin[c + d*x])/(d*Sqrt[Cos[c + d*x]]) + (b^2*(4*A + 3*C)*Sqrt[Cos[c + d*x]]*Sqrt[b*Cos[c + d*x]]*Sin[c + d*x])/(8*d) + (b^2*C*Cos[c + d*x]^(5/2)*Sqrt[b*Cos[c + d*x]]*Sin[c + d*x])/(4*d) - (b^2*B*Sqrt[b*Cos[c + d*x]]*Sin[c + d*x]^3)/(3*d*Sqrt[Cos[c + d*x]])}
{((b*Cos[c + d*x])^(5/2)*(A + B*Cos[c + d*x] + C*Cos[c + d*x]^2))/Cos[c + d*x]^(3/2), x, 5, (b^2*B*x*Sqrt[b*Cos[c + d*x]])/(2*Sqrt[Cos[c + d*x]]) + (b^2*(3*A + 2*C)*Sqrt[b*Cos[c + d*x]]*Sin[c + d*x])/(3*d*Sqrt[Cos[c + d*x]]) + (b^2*B*Sqrt[Cos[c + d*x]]*Sqrt[b*Cos[c + d*x]]*Sin[c + d*x])/(2*d) + (b^2*C*Cos[c + d*x]^(3/2)*Sqrt[b*Cos[c + d*x]]*Sin[c + d*x])/(3*d)}
{((b*Cos[c + d*x])^(5/2)*(A + B*Cos[c + d*x] + C*Cos[c + d*x]^2))/Cos[c + d*x]^(5/2), x, 4, (A*b^2*x*Sqrt[b*Cos[c + d*x]])/Sqrt[Cos[c + d*x]] + (b^2*C*x*Sqrt[b*Cos[c + d*x]])/(2*Sqrt[Cos[c + d*x]]) + (b^2*B*Sqrt[b*Cos[c + d*x]]*Sin[c + d*x])/(d*Sqrt[Cos[c + d*x]]) + (b^2*C*Sqrt[Cos[c + d*x]]*Sqrt[b*Cos[c + d*x]]*Sin[c + d*x])/(2*d)}
{((b*Cos[c + d*x])^(5/2)*(A + B*Cos[c + d*x] + C*Cos[c + d*x]^2))/Cos[c + d*x]^(7/2), x, 4, (b^2*B*x*Sqrt[b*Cos[c + d*x]])/Sqrt[Cos[c + d*x]] + (A*b^2*ArcTanh[Sin[c + d*x]]*Sqrt[b*Cos[c + d*x]])/(d*Sqrt[Cos[c + d*x]]) + (b^2*C*Sqrt[b*Cos[c + d*x]]*Sin[c + d*x])/(d*Sqrt[Cos[c + d*x]])}
{((b*Cos[c + d*x])^(5/2)*(A + B*Cos[c + d*x] + C*Cos[c + d*x]^2))/Cos[c + d*x]^(9/2), x, 5, (b^2*C*x*Sqrt[b*Cos[c + d*x]])/Sqrt[Cos[c + d*x]] + (b^2*B*ArcTanh[Sin[c + d*x]]*Sqrt[b*Cos[c + d*x]])/(d*Sqrt[Cos[c + d*x]]) + (A*b^2*Sqrt[b*Cos[c + d*x]]*Sin[c + d*x])/(d*Cos[c + d*x]^(3/2))}
{((b*Cos[c + d*x])^(5/2)*(A + B*Cos[c + d*x] + C*Cos[c + d*x]^2))/Cos[c + d*x]^(11/2), x, 5, (b^2*(A + 2*C)*ArcTanh[Sin[c + d*x]]*Sqrt[b*Cos[c + d*x]])/(2*d*Sqrt[Cos[c + d*x]]) + (A*b^2*Sqrt[b*Cos[c + d*x]]*Sin[c + d*x])/(2*d*Cos[c + d*x]^(5/2)) + (b^2*B*Sqrt[b*Cos[c + d*x]]*Sin[c + d*x])/(d*Cos[c + d*x]^(3/2))}
{((b*Cos[c + d*x])^(5/2)*(A + B*Cos[c + d*x] + C*Cos[c + d*x]^2))/Cos[c + d*x]^(13/2), x, 6, (b^2*B*ArcTanh[Sin[c + d*x]]*Sqrt[b*Cos[c + d*x]])/(2*d*Sqrt[Cos[c + d*x]]) + (A*b^2*Sqrt[b*Cos[c + d*x]]*Sin[c + d*x])/(3*d*Cos[c + d*x]^(7/2)) + (b^2*B*Sqrt[b*Cos[c + d*x]]*Sin[c + d*x])/(2*d*Cos[c + d*x]^(5/2)) + (b^2*(2*A + 3*C)*Sqrt[b*Cos[c + d*x]]*Sin[c + d*x])/(3*d*Cos[c + d*x]^(3/2))}
{((b*Cos[c + d*x])^(5/2)*(A + B*Cos[c + d*x] + C*Cos[c + d*x]^2))/Cos[c + d*x]^(15/2), x, 7, (b^2*(3*A + 4*C)*ArcTanh[Sin[c + d*x]]*Sqrt[b*Cos[c + d*x]])/(8*d*Sqrt[Cos[c + d*x]]) + (A*b^2*Sqrt[b*Cos[c + d*x]]*Sin[c + d*x])/(4*d*Cos[c + d*x]^(9/2)) + (b^2*(3*A + 4*C)*Sqrt[b*Cos[c + d*x]]*Sin[c + d*x])/(8*d*Cos[c + d*x]^(5/2)) + (b^2*B*Sqrt[b*Cos[c + d*x]]*Sin[c + d*x])/(d*Cos[c + d*x]^(3/2)) + (b^2*B*Sqrt[b*Cos[c + d*x]]*Sin[c + d*x]^3)/(3*d*Cos[c + d*x]^(7/2))}


(* ::Subsubsection::Closed:: *)
(*n<0*)


{(Cos[c + d*x]^(5/2)*(A + B*Cos[c + d*x] + C*Cos[c + d*x]^2))/Sqrt[b*Cos[c + d*x]], x, 6, ((4*A + 3*C)*x*Sqrt[Cos[c + d*x]])/(8*Sqrt[b*Cos[c + d*x]]) + (B*Sqrt[Cos[c + d*x]]*Sin[c + d*x])/(d*Sqrt[b*Cos[c + d*x]]) + ((4*A + 3*C)*Cos[c + d*x]^(3/2)*Sin[c + d*x])/(8*d*Sqrt[b*Cos[c + d*x]]) + (C*Cos[c + d*x]^(7/2)*Sin[c + d*x])/(4*d*Sqrt[b*Cos[c + d*x]]) - (B*Sqrt[Cos[c + d*x]]*Sin[c + d*x]^3)/(3*d*Sqrt[b*Cos[c + d*x]])}
{(Cos[c + d*x]^(3/2)*(A + B*Cos[c + d*x] + C*Cos[c + d*x]^2))/Sqrt[b*Cos[c + d*x]], x, 5, (B*x*Sqrt[Cos[c + d*x]])/(2*Sqrt[b*Cos[c + d*x]]) + ((3*A + 2*C)*Sqrt[Cos[c + d*x]]*Sin[c + d*x])/(3*d*Sqrt[b*Cos[c + d*x]]) + (B*Cos[c + d*x]^(3/2)*Sin[c + d*x])/(2*d*Sqrt[b*Cos[c + d*x]]) + (C*Cos[c + d*x]^(5/2)*Sin[c + d*x])/(3*d*Sqrt[b*Cos[c + d*x]])}
{(Sqrt[Cos[c + d*x]]*(A + B*Cos[c + d*x] + C*Cos[c + d*x]^2))/Sqrt[b*Cos[c + d*x]], x, 4, (A*x*Sqrt[Cos[c + d*x]])/Sqrt[b*Cos[c + d*x]] + (C*x*Sqrt[Cos[c + d*x]])/(2*Sqrt[b*Cos[c + d*x]]) + (B*Sqrt[Cos[c + d*x]]*Sin[c + d*x])/(d*Sqrt[b*Cos[c + d*x]]) + (C*Cos[c + d*x]^(3/2)*Sin[c + d*x])/(2*d*Sqrt[b*Cos[c + d*x]])}
{(A + B*Cos[c + d*x] + C*Cos[c + d*x]^2)/(Sqrt[Cos[c + d*x]]*Sqrt[b*Cos[c + d*x]]), x, 4, (B*x*Sqrt[Cos[c + d*x]])/Sqrt[b*Cos[c + d*x]] + (A*ArcTanh[Sin[c + d*x]]*Sqrt[Cos[c + d*x]])/(d*Sqrt[b*Cos[c + d*x]]) + (C*Sqrt[Cos[c + d*x]]*Sin[c + d*x])/(d*Sqrt[b*Cos[c + d*x]])}
{(A + B*Cos[c + d*x] + C*Cos[c + d*x]^2)/(Cos[c + d*x]^(3/2)*Sqrt[b*Cos[c + d*x]]), x, 5, (C*x*Sqrt[Cos[c + d*x]])/Sqrt[b*Cos[c + d*x]] + (B*ArcTanh[Sin[c + d*x]]*Sqrt[Cos[c + d*x]])/(d*Sqrt[b*Cos[c + d*x]]) + (A*Sin[c + d*x])/(d*Sqrt[Cos[c + d*x]]*Sqrt[b*Cos[c + d*x]])}
{(A + B*Cos[c + d*x] + C*Cos[c + d*x]^2)/(Cos[c + d*x]^(5/2)*Sqrt[b*Cos[c + d*x]]), x, 5, ((A + 2*C)*ArcTanh[Sin[c + d*x]]*Sqrt[Cos[c + d*x]])/(2*d*Sqrt[b*Cos[c + d*x]]) + (A*Sin[c + d*x])/(2*d*Cos[c + d*x]^(3/2)*Sqrt[b*Cos[c + d*x]]) + (B*Sin[c + d*x])/(d*Sqrt[Cos[c + d*x]]*Sqrt[b*Cos[c + d*x]])}
{(A + B*Cos[c + d*x] + C*Cos[c + d*x]^2)/(Cos[c + d*x]^(7/2)*Sqrt[b*Cos[c + d*x]]), x, 6, (B*ArcTanh[Sin[c + d*x]]*Sqrt[Cos[c + d*x]])/(2*d*Sqrt[b*Cos[c + d*x]]) + (A*Sin[c + d*x])/(3*d*Cos[c + d*x]^(5/2)*Sqrt[b*Cos[c + d*x]]) + (B*Sin[c + d*x])/(2*d*Cos[c + d*x]^(3/2)*Sqrt[b*Cos[c + d*x]]) + ((2*A + 3*C)*Sin[c + d*x])/(3*d*Sqrt[Cos[c + d*x]]*Sqrt[b*Cos[c + d*x]])}
{(A + B*Cos[c + d*x] + C*Cos[c + d*x]^2)/(Cos[c + d*x]^(9/2)*Sqrt[b*Cos[c + d*x]]), x, 7, ((3*A + 4*C)*ArcTanh[Sin[c + d*x]]*Sqrt[Cos[c + d*x]])/(8*d*Sqrt[b*Cos[c + d*x]]) + (A*Sin[c + d*x])/(4*d*Cos[c + d*x]^(7/2)*Sqrt[b*Cos[c + d*x]]) + ((3*A + 4*C)*Sin[c + d*x])/(8*d*Cos[c + d*x]^(3/2)*Sqrt[b*Cos[c + d*x]]) + (B*Sin[c + d*x])/(d*Sqrt[Cos[c + d*x]]*Sqrt[b*Cos[c + d*x]]) + (B*Sin[c + d*x]^3)/(3*d*Cos[c + d*x]^(5/2)*Sqrt[b*Cos[c + d*x]])}


{(Cos[c + d*x]^(7/2)*(A + B*Cos[c + d*x] + C*Cos[c + d*x]^2))/(b*Cos[c + d*x])^(3/2), x, 6, ((4*A + 3*C)*x*Sqrt[Cos[c + d*x]])/(8*b*Sqrt[b*Cos[c + d*x]]) + (B*Sqrt[Cos[c + d*x]]*Sin[c + d*x])/(b*d*Sqrt[b*Cos[c + d*x]]) + ((4*A + 3*C)*Cos[c + d*x]^(3/2)*Sin[c + d*x])/(8*b*d*Sqrt[b*Cos[c + d*x]]) + (C*Cos[c + d*x]^(7/2)*Sin[c + d*x])/(4*b*d*Sqrt[b*Cos[c + d*x]]) - (B*Sqrt[Cos[c + d*x]]*Sin[c + d*x]^3)/(3*b*d*Sqrt[b*Cos[c + d*x]])}
{(Cos[c + d*x]^(5/2)*(A + B*Cos[c + d*x] + C*Cos[c + d*x]^2))/(b*Cos[c + d*x])^(3/2), x, 5, (B*x*Sqrt[Cos[c + d*x]])/(2*b*Sqrt[b*Cos[c + d*x]]) + ((3*A + 2*C)*Sqrt[Cos[c + d*x]]*Sin[c + d*x])/(3*b*d*Sqrt[b*Cos[c + d*x]]) + (B*Cos[c + d*x]^(3/2)*Sin[c + d*x])/(2*b*d*Sqrt[b*Cos[c + d*x]]) + (C*Cos[c + d*x]^(5/2)*Sin[c + d*x])/(3*b*d*Sqrt[b*Cos[c + d*x]])}
{(Cos[c + d*x]^(3/2)*(A + B*Cos[c + d*x] + C*Cos[c + d*x]^2))/(b*Cos[c + d*x])^(3/2), x, 4, (A*x*Sqrt[Cos[c + d*x]])/(b*Sqrt[b*Cos[c + d*x]]) + (C*x*Sqrt[Cos[c + d*x]])/(2*b*Sqrt[b*Cos[c + d*x]]) + (B*Sqrt[Cos[c + d*x]]*Sin[c + d*x])/(b*d*Sqrt[b*Cos[c + d*x]]) + (C*Cos[c + d*x]^(3/2)*Sin[c + d*x])/(2*b*d*Sqrt[b*Cos[c + d*x]])}
{(Sqrt[Cos[c + d*x]]*(A + B*Cos[c + d*x] + C*Cos[c + d*x]^2))/(b*Cos[c + d*x])^(3/2), x, 4, (B*x*Sqrt[Cos[c + d*x]])/(b*Sqrt[b*Cos[c + d*x]]) + (A*ArcTanh[Sin[c + d*x]]*Sqrt[Cos[c + d*x]])/(b*d*Sqrt[b*Cos[c + d*x]]) + (C*Sqrt[Cos[c + d*x]]*Sin[c + d*x])/(b*d*Sqrt[b*Cos[c + d*x]])}
{(A + B*Cos[c + d*x] + C*Cos[c + d*x]^2)/(Sqrt[Cos[c + d*x]]*(b*Cos[c + d*x])^(3/2)), x, 5, (C*x*Sqrt[Cos[c + d*x]])/(b*Sqrt[b*Cos[c + d*x]]) + (B*ArcTanh[Sin[c + d*x]]*Sqrt[Cos[c + d*x]])/(b*d*Sqrt[b*Cos[c + d*x]]) + (A*Sin[c + d*x])/(b*d*Sqrt[Cos[c + d*x]]*Sqrt[b*Cos[c + d*x]])}
{(A + B*Cos[c + d*x] + C*Cos[c + d*x]^2)/(Cos[c + d*x]^(3/2)*(b*Cos[c + d*x])^(3/2)), x, 5, ((A + 2*C)*ArcTanh[Sin[c + d*x]]*Sqrt[Cos[c + d*x]])/(2*b*d*Sqrt[b*Cos[c + d*x]]) + (A*Sin[c + d*x])/(2*b*d*Cos[c + d*x]^(3/2)*Sqrt[b*Cos[c + d*x]]) + (B*Sin[c + d*x])/(b*d*Sqrt[Cos[c + d*x]]*Sqrt[b*Cos[c + d*x]])}
{(A + B*Cos[c + d*x] + C*Cos[c + d*x]^2)/(Cos[c + d*x]^(5/2)*(b*Cos[c + d*x])^(3/2)), x, 6, (B*ArcTanh[Sin[c + d*x]]*Sqrt[Cos[c + d*x]])/(2*b*d*Sqrt[b*Cos[c + d*x]]) + (A*Sin[c + d*x])/(3*b*d*Cos[c + d*x]^(5/2)*Sqrt[b*Cos[c + d*x]]) + (B*Sin[c + d*x])/(2*b*d*Cos[c + d*x]^(3/2)*Sqrt[b*Cos[c + d*x]]) + ((2*A + 3*C)*Sin[c + d*x])/(3*b*d*Sqrt[Cos[c + d*x]]*Sqrt[b*Cos[c + d*x]])}
{(A + B*Cos[c + d*x] + C*Cos[c + d*x]^2)/(Cos[c + d*x]^(7/2)*(b*Cos[c + d*x])^(3/2)), x, 7, ((3*A + 4*C)*ArcTanh[Sin[c + d*x]]*Sqrt[Cos[c + d*x]])/(8*b*d*Sqrt[b*Cos[c + d*x]]) + (A*Sin[c + d*x])/(4*b*d*Cos[c + d*x]^(7/2)*Sqrt[b*Cos[c + d*x]]) + ((3*A + 4*C)*Sin[c + d*x])/(8*b*d*Cos[c + d*x]^(3/2)*Sqrt[b*Cos[c + d*x]]) + (B*Sin[c + d*x])/(b*d*Sqrt[Cos[c + d*x]]*Sqrt[b*Cos[c + d*x]]) + (B*Sin[c + d*x]^3)/(3*b*d*Cos[c + d*x]^(5/2)*Sqrt[b*Cos[c + d*x]])}


{(Cos[c + d*x]^(9/2)*(A + B*Cos[c + d*x] + C*Cos[c + d*x]^2))/(b*Cos[c + d*x])^(5/2), x, 6, ((4*A + 3*C)*x*Sqrt[Cos[c + d*x]])/(8*b^2*Sqrt[b*Cos[c + d*x]]) + (B*Sqrt[Cos[c + d*x]]*Sin[c + d*x])/(b^2*d*Sqrt[b*Cos[c + d*x]]) + ((4*A + 3*C)*Cos[c + d*x]^(3/2)*Sin[c + d*x])/(8*b^2*d*Sqrt[b*Cos[c + d*x]]) + (C*Cos[c + d*x]^(7/2)*Sin[c + d*x])/(4*b^2*d*Sqrt[b*Cos[c + d*x]]) - (B*Sqrt[Cos[c + d*x]]*Sin[c + d*x]^3)/(3*b^2*d*Sqrt[b*Cos[c + d*x]])}
{(Cos[c + d*x]^(7/2)*(A + B*Cos[c + d*x] + C*Cos[c + d*x]^2))/(b*Cos[c + d*x])^(5/2), x, 5, (B*x*Sqrt[Cos[c + d*x]])/(2*b^2*Sqrt[b*Cos[c + d*x]]) + ((3*A + 2*C)*Sqrt[Cos[c + d*x]]*Sin[c + d*x])/(3*b^2*d*Sqrt[b*Cos[c + d*x]]) + (B*Cos[c + d*x]^(3/2)*Sin[c + d*x])/(2*b^2*d*Sqrt[b*Cos[c + d*x]]) + (C*Cos[c + d*x]^(5/2)*Sin[c + d*x])/(3*b^2*d*Sqrt[b*Cos[c + d*x]])}
{(Cos[c + d*x]^(5/2)*(A + B*Cos[c + d*x] + C*Cos[c + d*x]^2))/(b*Cos[c + d*x])^(5/2), x, 4, (A*x*Sqrt[Cos[c + d*x]])/(b^2*Sqrt[b*Cos[c + d*x]]) + (C*x*Sqrt[Cos[c + d*x]])/(2*b^2*Sqrt[b*Cos[c + d*x]]) + (B*Sqrt[Cos[c + d*x]]*Sin[c + d*x])/(b^2*d*Sqrt[b*Cos[c + d*x]]) + (C*Cos[c + d*x]^(3/2)*Sin[c + d*x])/(2*b^2*d*Sqrt[b*Cos[c + d*x]])}
{(Cos[c + d*x]^(3/2)*(A + B*Cos[c + d*x] + C*Cos[c + d*x]^2))/(b*Cos[c + d*x])^(5/2), x, 4, (B*x*Sqrt[Cos[c + d*x]])/(b^2*Sqrt[b*Cos[c + d*x]]) + (A*ArcTanh[Sin[c + d*x]]*Sqrt[Cos[c + d*x]])/(b^2*d*Sqrt[b*Cos[c + d*x]]) + (C*Sqrt[Cos[c + d*x]]*Sin[c + d*x])/(b^2*d*Sqrt[b*Cos[c + d*x]])}
{(Sqrt[Cos[c + d*x]]*(A + B*Cos[c + d*x] + C*Cos[c + d*x]^2))/(b*Cos[c + d*x])^(5/2), x, 5, (C*x*Sqrt[Cos[c + d*x]])/(b^2*Sqrt[b*Cos[c + d*x]]) + (B*ArcTanh[Sin[c + d*x]]*Sqrt[Cos[c + d*x]])/(b^2*d*Sqrt[b*Cos[c + d*x]]) + (A*Sin[c + d*x])/(b^2*d*Sqrt[Cos[c + d*x]]*Sqrt[b*Cos[c + d*x]])}
{(A + B*Cos[c + d*x] + C*Cos[c + d*x]^2)/(Sqrt[Cos[c + d*x]]*(b*Cos[c + d*x])^(5/2)), x, 5, ((A + 2*C)*ArcTanh[Sin[c + d*x]]*Sqrt[Cos[c + d*x]])/(2*b^2*d*Sqrt[b*Cos[c + d*x]]) + (A*Sin[c + d*x])/(2*b^2*d*Cos[c + d*x]^(3/2)*Sqrt[b*Cos[c + d*x]]) + (B*Sin[c + d*x])/(b^2*d*Sqrt[Cos[c + d*x]]*Sqrt[b*Cos[c + d*x]])}
{(A + B*Cos[c + d*x] + C*Cos[c + d*x]^2)/(Cos[c + d*x]^(3/2)*(b*Cos[c + d*x])^(5/2)), x, 6, (B*ArcTanh[Sin[c + d*x]]*Sqrt[Cos[c + d*x]])/(2*b^2*d*Sqrt[b*Cos[c + d*x]]) + (A*Sin[c + d*x])/(3*b^2*d*Cos[c + d*x]^(5/2)*Sqrt[b*Cos[c + d*x]]) + (B*Sin[c + d*x])/(2*b^2*d*Cos[c + d*x]^(3/2)*Sqrt[b*Cos[c + d*x]]) + ((2*A + 3*C)*Sin[c + d*x])/(3*b^2*d*Sqrt[Cos[c + d*x]]*Sqrt[b*Cos[c + d*x]])}
{(A + B*Cos[c + d*x] + C*Cos[c + d*x]^2)/(Cos[c + d*x]^(5/2)*(b*Cos[c + d*x])^(5/2)), x, 7, ((3*A + 4*C)*ArcTanh[Sin[c + d*x]]*Sqrt[Cos[c + d*x]])/(8*b^2*d*Sqrt[b*Cos[c + d*x]]) + (A*Sin[c + d*x])/(4*b^2*d*Cos[c + d*x]^(7/2)*Sqrt[b*Cos[c + d*x]]) + ((3*A + 4*C)*Sin[c + d*x])/(8*b^2*d*Cos[c + d*x]^(3/2)*Sqrt[b*Cos[c + d*x]]) + (B*Sin[c + d*x])/(b^2*d*Sqrt[Cos[c + d*x]]*Sqrt[b*Cos[c + d*x]]) + (B*Sin[c + d*x]^3)/(3*b^2*d*Cos[c + d*x]^(5/2)*Sqrt[b*Cos[c + d*x]])}


(* ::Subsection::Closed:: *)
(*Integrands of the form Cos[c+d x]^m (A+B Cos[c+d x]+C Cos[c+d x]^2) (b Cos[c+d x])^(n/3)*)


(* ::Subsubsection::Closed:: *)
(*n>0*)


{Cos[c + d*x]^m*(b*Cos[c + d*x])^(1/3)*(A + B*Cos[c + d*x] + C*Cos[c + d*x]^2), x, 5, (3*C*Cos[c + d*x]^(1 + m)*(b*Cos[c + d*x])^(1/3)*Sin[c + d*x])/(d*(7 + 3*m)) + (B*Cos[c + d*x]^(2 + m)*(b*Cos[c + d*x])^(1/3)*(Cos[c + d*x]^2)^((1/6)*(-7 - 3*m))*Hypergeometric2F1[1/2, (1/6)*(-1 - 3*m), 3/2, Sin[c + d*x]^2]*Sin[c + d*x])/d + ((C*(4 + 3*m) + A*(7 + 3*m))*Cos[c + d*x]^(1 + m)*(b*Cos[c + d*x])^(1/3)*(Cos[c + d*x]^2)^((1/6)*(-4 - 3*m))*Hypergeometric2F1[1/2, (1/6)*(2 - 3*m), 3/2, Sin[c + d*x]^2]*Sin[c + d*x])/(d*(7 + 3*m))}

{Cos[c + d*x]^2*(b*Cos[c + d*x])^(1/3)*(A + B*Cos[c + d*x] + C*Cos[c + d*x]^2), x, 10, (21*B*(b*Cos[c + d*x])^(1/3)*Sin[c + d*x])/(40*d) + (3*(13*A + 10*C)*(b*Cos[c + d*x])^(4/3)*Sin[c + d*x])/(91*b*d) + (3*B*(b*Cos[c + d*x])^(7/3)*Sin[c + d*x])/(10*b^2*d) + (3*C*(b*Cos[c + d*x])^(10/3)*Sin[c + d*x])/(13*b^3*d) + (4*b*(13*A + 10*C)*(Cos[c + d*x]^2)^(1/3)*Hypergeometric2F1[1/3, 1/2, 3/2, Sin[c + d*x]^2]*Sin[c + d*x])/(91*d*(b*Cos[c + d*x])^(2/3)) + (7*B*(b*Cos[c + d*x])^(1/3)*Hypergeometric2F1[1/2, 5/6, 3/2, Sin[c + d*x]^2]*Sin[c + d*x])/(40*d*(Cos[c + d*x]^2)^(1/6))}
{Cos[c + d*x]*(b*Cos[c + d*x])^(1/3)*(A + B*Cos[c + d*x] + C*Cos[c + d*x]^2), x, 9, (3*(10*A + 7*C)*(b*Cos[c + d*x])^(1/3)*Sin[c + d*x])/(40*d) + (3*B*(b*Cos[c + d*x])^(4/3)*Sin[c + d*x])/(7*b*d) + (3*C*(b*Cos[c + d*x])^(7/3)*Sin[c + d*x])/(10*b^2*d) + (4*b*B*(Cos[c + d*x]^2)^(1/3)*Hypergeometric2F1[1/3, 1/2, 3/2, Sin[c + d*x]^2]*Sin[c + d*x])/(7*d*(b*Cos[c + d*x])^(2/3)) + ((10*A + 7*C)*(b*Cos[c + d*x])^(1/3)*Hypergeometric2F1[1/2, 5/6, 3/2, Sin[c + d*x]^2]*Sin[c + d*x])/(40*d*(Cos[c + d*x]^2)^(1/6))}
{(b*Cos[c + d*x])^(1/3)*(A + B*Cos[c + d*x] + C*Cos[c + d*x]^2), x, 7, (3*B*(b*Cos[c + d*x])^(1/3)*Sin[c + d*x])/(4*d) + (3*C*(b*Cos[c + d*x])^(4/3)*Sin[c + d*x])/(7*b*d) + (b*(7*A + 4*C)*(Cos[c + d*x]^2)^(1/3)*Hypergeometric2F1[1/3, 1/2, 3/2, Sin[c + d*x]^2]*Sin[c + d*x])/(7*d*(b*Cos[c + d*x])^(2/3)) + (B*(b*Cos[c + d*x])^(1/3)*Hypergeometric2F1[1/2, 5/6, 3/2, Sin[c + d*x]^2]*Sin[c + d*x])/(4*d*(Cos[c + d*x]^2)^(1/6))}
{(b*Cos[c + d*x])^(1/3)*(A + B*Cos[c + d*x] + C*Cos[c + d*x]^2)*Sec[c + d*x], x, 7, (3*C*(b*Cos[c + d*x])^(1/3)*Sin[c + d*x])/(4*d) + (b*B*(Cos[c + d*x]^2)^(1/3)*Hypergeometric2F1[1/3, 1/2, 3/2, Sin[c + d*x]^2]*Sin[c + d*x])/(d*(b*Cos[c + d*x])^(2/3)) + ((4*A + C)*(b*Cos[c + d*x])^(1/3)*Hypergeometric2F1[1/2, 5/6, 3/2, Sin[c + d*x]^2]*Sin[c + d*x])/(4*d*(Cos[c + d*x]^2)^(1/6))}
{(b*Cos[c + d*x])^(1/3)*(A + B*Cos[c + d*x] + C*Cos[c + d*x]^2)*Sec[c + d*x]^2, x, 7, (3*A*b*Sin[c + d*x])/(2*d*(b*Cos[c + d*x])^(2/3)) - (b*(A - 2*C)*(Cos[c + d*x]^2)^(1/3)*Hypergeometric2F1[1/3, 1/2, 3/2, Sin[c + d*x]^2]*Sin[c + d*x])/(2*d*(b*Cos[c + d*x])^(2/3)) + (B*(b*Cos[c + d*x])^(1/3)*Hypergeometric2F1[1/2, 5/6, 3/2, Sin[c + d*x]^2]*Sin[c + d*x])/(d*(Cos[c + d*x]^2)^(1/6))}
{(b*Cos[c + d*x])^(1/3)*(A + B*Cos[c + d*x] + C*Cos[c + d*x]^2)*Sec[c + d*x]^3, x, 8, (3*A*b^2*Sin[c + d*x])/(5*d*(b*Cos[c + d*x])^(5/3)) + (3*b*B*Sin[c + d*x])/(2*d*(b*Cos[c + d*x])^(2/3)) - (b*B*(Cos[c + d*x]^2)^(1/3)*Hypergeometric2F1[1/3, 1/2, 3/2, Sin[c + d*x]^2]*Sin[c + d*x])/(2*d*(b*Cos[c + d*x])^(2/3)) + ((2*A + 5*C)*(b*Cos[c + d*x])^(1/3)*Hypergeometric2F1[1/2, 5/6, 3/2, Sin[c + d*x]^2]*Sin[c + d*x])/(5*d*(Cos[c + d*x]^2)^(1/6))}


{Cos[c + d*x]^m*(b*Cos[c + d*x])^(2/3)*(A + B*Cos[c + d*x] + C*Cos[c + d*x]^2), x, 5, (3*C*Cos[c + d*x]^(1 + m)*(b*Cos[c + d*x])^(2/3)*Sin[c + d*x])/(d*(8 + 3*m)) + (B*Cos[c + d*x]^(2 + m)*(b*Cos[c + d*x])^(2/3)*(Cos[c + d*x]^2)^((1/6)*(-8 - 3*m))*Hypergeometric2F1[1/2, (1/6)*(-2 - 3*m), 3/2, Sin[c + d*x]^2]*Sin[c + d*x])/d + ((C*(5 + 3*m) + A*(8 + 3*m))*Cos[c + d*x]^(1 + m)*(b*Cos[c + d*x])^(2/3)*(Cos[c + d*x]^2)^((1/6)*(-5 - 3*m))*Hypergeometric2F1[1/2, (1/6)*(1 - 3*m), 3/2, Sin[c + d*x]^2]*Sin[c + d*x])/(d*(8 + 3*m))}

{Cos[c + d*x]^2*(b*Cos[c + d*x])^(2/3)*(A + B*Cos[c + d*x] + C*Cos[c + d*x]^2), x, 10, (24*B*(b*Cos[c + d*x])^(2/3)*Sin[c + d*x])/(55*d) + (3*(14*A + 11*C)*(b*Cos[c + d*x])^(5/3)*Sin[c + d*x])/(112*b*d) + (3*B*(b*Cos[c + d*x])^(8/3)*Sin[c + d*x])/(11*b^2*d) + (3*C*(b*Cos[c + d*x])^(11/3)*Sin[c + d*x])/(14*b^3*d) + (5*b*(14*A + 11*C)*(Cos[c + d*x]^2)^(1/6)*Hypergeometric2F1[1/6, 1/2, 3/2, Sin[c + d*x]^2]*Sin[c + d*x])/(112*d*(b*Cos[c + d*x])^(1/3)) + (16*B*(b*Cos[c + d*x])^(2/3)*Hypergeometric2F1[1/2, 2/3, 3/2, Sin[c + d*x]^2]*Sin[c + d*x])/(55*d*(Cos[c + d*x]^2)^(1/3))}
{Cos[c + d*x]*(b*Cos[c + d*x])^(2/3)*(A + B*Cos[c + d*x] + C*Cos[c + d*x]^2), x, 9, (3*(11*A + 8*C)*(b*Cos[c + d*x])^(2/3)*Sin[c + d*x])/(55*d) + (3*B*(b*Cos[c + d*x])^(5/3)*Sin[c + d*x])/(8*b*d) + (3*C*(b*Cos[c + d*x])^(8/3)*Sin[c + d*x])/(11*b^2*d) + (5*b*B*(Cos[c + d*x]^2)^(1/6)*Hypergeometric2F1[1/6, 1/2, 3/2, Sin[c + d*x]^2]*Sin[c + d*x])/(8*d*(b*Cos[c + d*x])^(1/3)) + (2*(11*A + 8*C)*(b*Cos[c + d*x])^(2/3)*Hypergeometric2F1[1/2, 2/3, 3/2, Sin[c + d*x]^2]*Sin[c + d*x])/(55*d*(Cos[c + d*x]^2)^(1/3))}
{(b*Cos[c + d*x])^(2/3)*(A + B*Cos[c + d*x] + C*Cos[c + d*x]^2), x, 7, (3*B*(b*Cos[c + d*x])^(2/3)*Sin[c + d*x])/(5*d) + (3*C*(b*Cos[c + d*x])^(5/3)*Sin[c + d*x])/(8*b*d) + (b*(8*A + 5*C)*(Cos[c + d*x]^2)^(1/6)*Hypergeometric2F1[1/6, 1/2, 3/2, Sin[c + d*x]^2]*Sin[c + d*x])/(8*d*(b*Cos[c + d*x])^(1/3)) + (2*B*(b*Cos[c + d*x])^(2/3)*Hypergeometric2F1[1/2, 2/3, 3/2, Sin[c + d*x]^2]*Sin[c + d*x])/(5*d*(Cos[c + d*x]^2)^(1/3))}
{(b*Cos[c + d*x])^(2/3)*(A + B*Cos[c + d*x] + C*Cos[c + d*x]^2)*Sec[c + d*x], x, 7, (3*C*(b*Cos[c + d*x])^(2/3)*Sin[c + d*x])/(5*d) + (b*B*(Cos[c + d*x]^2)^(1/6)*Hypergeometric2F1[1/6, 1/2, 3/2, Sin[c + d*x]^2]*Sin[c + d*x])/(d*(b*Cos[c + d*x])^(1/3)) + ((5*A + 2*C)*(b*Cos[c + d*x])^(2/3)*Hypergeometric2F1[1/2, 2/3, 3/2, Sin[c + d*x]^2]*Sin[c + d*x])/(5*d*(Cos[c + d*x]^2)^(1/3))}
{(b*Cos[c + d*x])^(2/3)*(A + B*Cos[c + d*x] + C*Cos[c + d*x]^2)*Sec[c + d*x]^2, x, 7, (3*A*b*Sin[c + d*x])/(d*(b*Cos[c + d*x])^(1/3)) - (b*(2*A - C)*(Cos[c + d*x]^2)^(1/6)*Hypergeometric2F1[1/6, 1/2, 3/2, Sin[c + d*x]^2]*Sin[c + d*x])/(d*(b*Cos[c + d*x])^(1/3)) + (B*(b*Cos[c + d*x])^(2/3)*Hypergeometric2F1[1/2, 2/3, 3/2, Sin[c + d*x]^2]*Sin[c + d*x])/(d*(Cos[c + d*x]^2)^(1/3))}
{(b*Cos[c + d*x])^(2/3)*(A + B*Cos[c + d*x] + C*Cos[c + d*x]^2)*Sec[c + d*x]^3, x, 8, (3*A*b^2*Sin[c + d*x])/(4*d*(b*Cos[c + d*x])^(4/3)) + (3*b*B*Sin[c + d*x])/(d*(b*Cos[c + d*x])^(1/3)) - (2*b*B*(Cos[c + d*x]^2)^(1/6)*Hypergeometric2F1[1/6, 1/2, 3/2, Sin[c + d*x]^2]*Sin[c + d*x])/(d*(b*Cos[c + d*x])^(1/3)) + ((A + 4*C)*(b*Cos[c + d*x])^(2/3)*Hypergeometric2F1[1/2, 2/3, 3/2, Sin[c + d*x]^2]*Sin[c + d*x])/(4*d*(Cos[c + d*x]^2)^(1/3))}


{Cos[c + d*x]^m*(b*Cos[c + d*x])^(4/3)*(A + B*Cos[c + d*x] + C*Cos[c + d*x]^2), x, 5, (3*C*Cos[c + d*x]^(1 + m)*(b*Cos[c + d*x])^(4/3)*Sin[c + d*x])/(d*(10 + 3*m)) + (B*Cos[c + d*x]^(2 + m)*(b*Cos[c + d*x])^(4/3)*(Cos[c + d*x]^2)^((1/6)*(-10 - 3*m))*Hypergeometric2F1[1/2, (1/6)*(-4 - 3*m), 3/2, Sin[c + d*x]^2]*Sin[c + d*x])/d + ((C*(7 + 3*m) + A*(10 + 3*m))*Cos[c + d*x]^(1 + m)*(b*Cos[c + d*x])^(4/3)*(Cos[c + d*x]^2)^((1/6)*(-7 - 3*m))*Hypergeometric2F1[1/2, (1/6)*(-1 - 3*m), 3/2, Sin[c + d*x]^2]*Sin[c + d*x])/(d*(10 + 3*m))}

{Cos[c + d*x]^2*(b*Cos[c + d*x])^(4/3)*(A + B*Cos[c + d*x] + C*Cos[c + d*x]^2), x, 11, (21*b*(16*A + 13*C)*(b*Cos[c + d*x])^(1/3)*Sin[c + d*x])/(640*d) + (30*B*(b*Cos[c + d*x])^(4/3)*Sin[c + d*x])/(91*d) + (3*(16*A + 13*C)*(b*Cos[c + d*x])^(7/3)*Sin[c + d*x])/(160*b*d) + (3*B*(b*Cos[c + d*x])^(10/3)*Sin[c + d*x])/(13*b^2*d) + (3*C*(b*Cos[c + d*x])^(13/3)*Sin[c + d*x])/(16*b^3*d) + (40*b^2*B*(Cos[c + d*x]^2)^(1/3)*Hypergeometric2F1[1/3, 1/2, 3/2, Sin[c + d*x]^2]*Sin[c + d*x])/(91*d*(b*Cos[c + d*x])^(2/3)) + (7*b*(16*A + 13*C)*(b*Cos[c + d*x])^(1/3)*Hypergeometric2F1[1/2, 5/6, 3/2, Sin[c + d*x]^2]*Sin[c + d*x])/(640*d*(Cos[c + d*x]^2)^(1/6))}
{Cos[c + d*x]*(b*Cos[c + d*x])^(4/3)*(A + B*Cos[c + d*x] + C*Cos[c + d*x]^2), x, 10, (21*b*B*(b*Cos[c + d*x])^(1/3)*Sin[c + d*x])/(40*d) + (3*(13*A + 10*C)*(b*Cos[c + d*x])^(4/3)*Sin[c + d*x])/(91*d) + (3*B*(b*Cos[c + d*x])^(7/3)*Sin[c + d*x])/(10*b*d) + (3*C*(b*Cos[c + d*x])^(10/3)*Sin[c + d*x])/(13*b^2*d) + (4*b^2*(13*A + 10*C)*(Cos[c + d*x]^2)^(1/3)*Hypergeometric2F1[1/3, 1/2, 3/2, Sin[c + d*x]^2]*Sin[c + d*x])/(91*d*(b*Cos[c + d*x])^(2/3)) + (7*b*B*(b*Cos[c + d*x])^(1/3)*Hypergeometric2F1[1/2, 5/6, 3/2, Sin[c + d*x]^2]*Sin[c + d*x])/(40*d*(Cos[c + d*x]^2)^(1/6))}
{(b*Cos[c + d*x])^(4/3)*(A + B*Cos[c + d*x] + C*Cos[c + d*x]^2), x, 8, (3*b*(10*A + 7*C)*(b*Cos[c + d*x])^(1/3)*Sin[c + d*x])/(40*d) + (3*B*(b*Cos[c + d*x])^(4/3)*Sin[c + d*x])/(7*d) + (3*C*(b*Cos[c + d*x])^(7/3)*Sin[c + d*x])/(10*b*d) + (4*b^2*B*(Cos[c + d*x]^2)^(1/3)*Hypergeometric2F1[1/3, 1/2, 3/2, Sin[c + d*x]^2]*Sin[c + d*x])/(7*d*(b*Cos[c + d*x])^(2/3)) + (b*(10*A + 7*C)*(b*Cos[c + d*x])^(1/3)*Hypergeometric2F1[1/2, 5/6, 3/2, Sin[c + d*x]^2]*Sin[c + d*x])/(40*d*(Cos[c + d*x]^2)^(1/6))}
{(b*Cos[c + d*x])^(4/3)*(A + B*Cos[c + d*x] + C*Cos[c + d*x]^2)*Sec[c + d*x], x, 8, (3*b*B*(b*Cos[c + d*x])^(1/3)*Sin[c + d*x])/(4*d) + (3*C*(b*Cos[c + d*x])^(4/3)*Sin[c + d*x])/(7*d) + (b^2*(7*A + 4*C)*(Cos[c + d*x]^2)^(1/3)*Hypergeometric2F1[1/3, 1/2, 3/2, Sin[c + d*x]^2]*Sin[c + d*x])/(7*d*(b*Cos[c + d*x])^(2/3)) + (b*B*(b*Cos[c + d*x])^(1/3)*Hypergeometric2F1[1/2, 5/6, 3/2, Sin[c + d*x]^2]*Sin[c + d*x])/(4*d*(Cos[c + d*x]^2)^(1/6))}
{(b*Cos[c + d*x])^(4/3)*(A + B*Cos[c + d*x] + C*Cos[c + d*x]^2)*Sec[c + d*x]^2, x, 7, (3*b*C*(b*Cos[c + d*x])^(1/3)*Sin[c + d*x])/(4*d) + (b^2*B*(Cos[c + d*x]^2)^(1/3)*Hypergeometric2F1[1/3, 1/2, 3/2, Sin[c + d*x]^2]*Sin[c + d*x])/(d*(b*Cos[c + d*x])^(2/3)) + (b*(4*A + C)*(b*Cos[c + d*x])^(1/3)*Hypergeometric2F1[1/2, 5/6, 3/2, Sin[c + d*x]^2]*Sin[c + d*x])/(4*d*(Cos[c + d*x]^2)^(1/6))}
{(b*Cos[c + d*x])^(4/3)*(A + B*Cos[c + d*x] + C*Cos[c + d*x]^2)*Sec[c + d*x]^3, x, 7, (3*A*b^2*Sin[c + d*x])/(2*d*(b*Cos[c + d*x])^(2/3)) - (b^2*(A - 2*C)*(Cos[c + d*x]^2)^(1/3)*Hypergeometric2F1[1/3, 1/2, 3/2, Sin[c + d*x]^2]*Sin[c + d*x])/(2*d*(b*Cos[c + d*x])^(2/3)) + (b*B*(b*Cos[c + d*x])^(1/3)*Hypergeometric2F1[1/2, 5/6, 3/2, Sin[c + d*x]^2]*Sin[c + d*x])/(d*(Cos[c + d*x]^2)^(1/6))}


(* ::Subsubsection::Closed:: *)
(*n<0*)


{(Cos[c + d*x]^m*(A + B*Cos[c + d*x] + C*Cos[c + d*x]^2))/(b*Cos[c + d*x])^(1/3), x, 5, (3*C*Cos[c + d*x]^(1 + m)*Sin[c + d*x])/(d*(5 + 3*m)*(b*Cos[c + d*x])^(1/3)) + (B*Cos[c + d*x]^(2 + m)*(Cos[c + d*x]^2)^((1/6)*(-5 - 3*m))*Hypergeometric2F1[1/2, (1/6)*(1 - 3*m), 3/2, Sin[c + d*x]^2]*Sin[c + d*x])/(d*(b*Cos[c + d*x])^(1/3)) + ((C*(2 + 3*m) + A*(5 + 3*m))*Cos[c + d*x]^(1 + m)*(Cos[c + d*x]^2)^((1/6)*(-2 - 3*m))*Hypergeometric2F1[1/2, (1/6)*(4 - 3*m), 3/2, Sin[c + d*x]^2]*Sin[c + d*x])/(d*(5 + 3*m)*(b*Cos[c + d*x])^(1/3))}

{(Cos[c + d*x]^2*(A + B*Cos[c + d*x] + C*Cos[c + d*x]^2))/(b*Cos[c + d*x])^(1/3), x, 9, (3*(11*A + 8*C)*(b*Cos[c + d*x])^(2/3)*Sin[c + d*x])/(55*b*d) + (3*B*(b*Cos[c + d*x])^(5/3)*Sin[c + d*x])/(8*b^2*d) + (3*C*(b*Cos[c + d*x])^(8/3)*Sin[c + d*x])/(11*b^3*d) + (5*B*(Cos[c + d*x]^2)^(1/6)*Hypergeometric2F1[1/6, 1/2, 3/2, Sin[c + d*x]^2]*Sin[c + d*x])/(8*d*(b*Cos[c + d*x])^(1/3)) + (2*(11*A + 8*C)*(b*Cos[c + d*x])^(2/3)*Hypergeometric2F1[1/2, 2/3, 3/2, Sin[c + d*x]^2]*Sin[c + d*x])/(55*b*d*(Cos[c + d*x]^2)^(1/3))}
{(Cos[c + d*x]*(A + B*Cos[c + d*x] + C*Cos[c + d*x]^2))/(b*Cos[c + d*x])^(1/3), x, 8, (3*B*(b*Cos[c + d*x])^(2/3)*Sin[c + d*x])/(5*b*d) + (3*C*(b*Cos[c + d*x])^(5/3)*Sin[c + d*x])/(8*b^2*d) + ((8*A + 5*C)*(Cos[c + d*x]^2)^(1/6)*Hypergeometric2F1[1/6, 1/2, 3/2, Sin[c + d*x]^2]*Sin[c + d*x])/(8*d*(b*Cos[c + d*x])^(1/3)) + (2*B*(b*Cos[c + d*x])^(2/3)*Hypergeometric2F1[1/2, 2/3, 3/2, Sin[c + d*x]^2]*Sin[c + d*x])/(5*b*d*(Cos[c + d*x]^2)^(1/3))}
{(A + B*Cos[c + d*x] + C*Cos[c + d*x]^2)/(b*Cos[c + d*x])^(1/3), x, 6, (3*C*(b*Cos[c + d*x])^(2/3)*Sin[c + d*x])/(5*b*d) + (B*(Cos[c + d*x]^2)^(1/6)*Hypergeometric2F1[1/6, 1/2, 3/2, Sin[c + d*x]^2]*Sin[c + d*x])/(d*(b*Cos[c + d*x])^(1/3)) + ((5*A + 2*C)*(b*Cos[c + d*x])^(2/3)*Hypergeometric2F1[1/2, 2/3, 3/2, Sin[c + d*x]^2]*Sin[c + d*x])/(5*b*d*(Cos[c + d*x]^2)^(1/3))}
{((A + B*Cos[c + d*x] + C*Cos[c + d*x]^2)*Sec[c + d*x])/(b*Cos[c + d*x])^(1/3), x, 7, (3*A*Sin[c + d*x])/(d*(b*Cos[c + d*x])^(1/3)) - ((2*A - C)*(Cos[c + d*x]^2)^(1/6)*Hypergeometric2F1[1/6, 1/2, 3/2, Sin[c + d*x]^2]*Sin[c + d*x])/(d*(b*Cos[c + d*x])^(1/3)) + (B*(b*Cos[c + d*x])^(2/3)*Hypergeometric2F1[1/2, 2/3, 3/2, Sin[c + d*x]^2]*Sin[c + d*x])/(b*d*(Cos[c + d*x]^2)^(1/3))}
{((A + B*Cos[c + d*x] + C*Cos[c + d*x]^2)*Sec[c + d*x]^2)/(b*Cos[c + d*x])^(1/3), x, 8, (3*A*b*Sin[c + d*x])/(4*d*(b*Cos[c + d*x])^(4/3)) + (3*B*Sin[c + d*x])/(d*(b*Cos[c + d*x])^(1/3)) - (2*B*(Cos[c + d*x]^2)^(1/6)*Hypergeometric2F1[1/6, 1/2, 3/2, Sin[c + d*x]^2]*Sin[c + d*x])/(d*(b*Cos[c + d*x])^(1/3)) + ((A + 4*C)*(b*Cos[c + d*x])^(2/3)*Hypergeometric2F1[1/2, 2/3, 3/2, Sin[c + d*x]^2]*Sin[c + d*x])/(4*b*d*(Cos[c + d*x]^2)^(1/3))}
{((A + B*Cos[c + d*x] + C*Cos[c + d*x]^2)*Sec[c + d*x]^3)/(b*Cos[c + d*x])^(1/3), x, 9, (3*A*b^2*Sin[c + d*x])/(7*d*(b*Cos[c + d*x])^(7/3)) + (3*b*B*Sin[c + d*x])/(4*d*(b*Cos[c + d*x])^(4/3)) + (3*(4*A + 7*C)*Sin[c + d*x])/(7*d*(b*Cos[c + d*x])^(1/3)) - (2*(4*A + 7*C)*(Cos[c + d*x]^2)^(1/6)*Hypergeometric2F1[1/6, 1/2, 3/2, Sin[c + d*x]^2]*Sin[c + d*x])/(7*d*(b*Cos[c + d*x])^(1/3)) + (B*(b*Cos[c + d*x])^(2/3)*Hypergeometric2F1[1/2, 2/3, 3/2, Sin[c + d*x]^2]*Sin[c + d*x])/(4*b*d*(Cos[c + d*x]^2)^(1/3))}


{(Cos[c + d*x]^m*(A + B*Cos[c + d*x] + C*Cos[c + d*x]^2))/(b*Cos[c + d*x])^(2/3), x, 5, (3*C*Cos[c + d*x]^(1 + m)*Sin[c + d*x])/(d*(4 + 3*m)*(b*Cos[c + d*x])^(2/3)) + (B*Cos[c + d*x]^(2 + m)*(Cos[c + d*x]^2)^((-4 - 3*m)/6)*Hypergeometric2F1[1/2, (2 - 3*m)/6, 3/2, Sin[c + d*x]^2]*Sin[c + d*x])/(d*(b*Cos[c + d*x])^(2/3)) + ((C + 3*C*m + A*(4 + 3*m))*Cos[c + d*x]^(1 + m)*(Cos[c + d*x]^2)^((-1 - 3*m)/6)*Hypergeometric2F1[1/2, (5 - 3*m)/6, 3/2, Sin[c + d*x]^2]*Sin[c + d*x])/(d*(4 + 3*m)*(b*Cos[c + d*x])^(2/3))}

{(Cos[c + d*x]^2*(A + B*Cos[c + d*x] + C*Cos[c + d*x]^2))/(b*Cos[c + d*x])^(2/3), x, 9, (3*(10*A + 7*C)*(b*Cos[c + d*x])^(1/3)*Sin[c + d*x])/(40*b*d) + (3*B*(b*Cos[c + d*x])^(4/3)*Sin[c + d*x])/(7*b^2*d) + (3*C*(b*Cos[c + d*x])^(7/3)*Sin[c + d*x])/(10*b^3*d) + (4*B*(Cos[c + d*x]^2)^(1/3)*Hypergeometric2F1[1/3, 1/2, 3/2, Sin[c + d*x]^2]*Sin[c + d*x])/(7*d*(b*Cos[c + d*x])^(2/3)) + ((10*A + 7*C)*(b*Cos[c + d*x])^(1/3)*Hypergeometric2F1[1/2, 5/6, 3/2, Sin[c + d*x]^2]*Sin[c + d*x])/(40*b*d*(Cos[c + d*x]^2)^(1/6))}
{(Cos[c + d*x]*(A + B*Cos[c + d*x] + C*Cos[c + d*x]^2))/(b*Cos[c + d*x])^(2/3), x, 8, (3*B*(b*Cos[c + d*x])^(1/3)*Sin[c + d*x])/(4*b*d) + (3*C*(b*Cos[c + d*x])^(4/3)*Sin[c + d*x])/(7*b^2*d) + ((7*A + 4*C)*(Cos[c + d*x]^2)^(1/3)*Hypergeometric2F1[1/3, 1/2, 3/2, Sin[c + d*x]^2]*Sin[c + d*x])/(7*d*(b*Cos[c + d*x])^(2/3)) + (B*(b*Cos[c + d*x])^(1/3)*Hypergeometric2F1[1/2, 5/6, 3/2, Sin[c + d*x]^2]*Sin[c + d*x])/(4*b*d*(Cos[c + d*x]^2)^(1/6))}
{(A + B*Cos[c + d*x] + C*Cos[c + d*x]^2)/(b*Cos[c + d*x])^(2/3), x, 6, (3*C*(b*Cos[c + d*x])^(1/3)*Sin[c + d*x])/(4*b*d) + (B*(Cos[c + d*x]^2)^(1/3)*Hypergeometric2F1[1/3, 1/2, 3/2, Sin[c + d*x]^2]*Sin[c + d*x])/(d*(b*Cos[c + d*x])^(2/3)) + ((4*A + C)*(b*Cos[c + d*x])^(1/3)*Hypergeometric2F1[1/2, 5/6, 3/2, Sin[c + d*x]^2]*Sin[c + d*x])/(4*b*d*(Cos[c + d*x]^2)^(1/6))}
{((A + B*Cos[c + d*x] + C*Cos[c + d*x]^2)*Sec[c + d*x])/(b*Cos[c + d*x])^(2/3), x, 7, (3*A*Sin[c + d*x])/(2*d*(b*Cos[c + d*x])^(2/3)) - ((A - 2*C)*(Cos[c + d*x]^2)^(1/3)*Hypergeometric2F1[1/3, 1/2, 3/2, Sin[c + d*x]^2]*Sin[c + d*x])/(2*d*(b*Cos[c + d*x])^(2/3)) + (B*(b*Cos[c + d*x])^(1/3)*Hypergeometric2F1[1/2, 5/6, 3/2, Sin[c + d*x]^2]*Sin[c + d*x])/(b*d*(Cos[c + d*x]^2)^(1/6))}
{((A + B*Cos[c + d*x] + C*Cos[c + d*x]^2)*Sec[c + d*x]^2)/(b*Cos[c + d*x])^(2/3), x, 8, (3*A*b*Sin[c + d*x])/(5*d*(b*Cos[c + d*x])^(5/3)) + (3*B*Sin[c + d*x])/(2*d*(b*Cos[c + d*x])^(2/3)) - (B*(Cos[c + d*x]^2)^(1/3)*Hypergeometric2F1[1/3, 1/2, 3/2, Sin[c + d*x]^2]*Sin[c + d*x])/(2*d*(b*Cos[c + d*x])^(2/3)) + ((2*A + 5*C)*(b*Cos[c + d*x])^(1/3)*Hypergeometric2F1[1/2, 5/6, 3/2, Sin[c + d*x]^2]*Sin[c + d*x])/(5*b*d*(Cos[c + d*x]^2)^(1/6))}
{((A + B*Cos[c + d*x] + C*Cos[c + d*x]^2)*Sec[c + d*x]^3)/(b*Cos[c + d*x])^(2/3), x, 9, (3*A*b^2*Sin[c + d*x])/(8*d*(b*Cos[c + d*x])^(8/3)) + (3*b*B*Sin[c + d*x])/(5*d*(b*Cos[c + d*x])^(5/3)) + (3*(5*A + 8*C)*Sin[c + d*x])/(16*d*(b*Cos[c + d*x])^(2/3)) - ((5*A + 8*C)*(Cos[c + d*x]^2)^(1/3)*Hypergeometric2F1[1/3, 1/2, 3/2, Sin[c + d*x]^2]*Sin[c + d*x])/(16*d*(b*Cos[c + d*x])^(2/3)) + (2*B*(b*Cos[c + d*x])^(1/3)*Hypergeometric2F1[1/2, 5/6, 3/2, Sin[c + d*x]^2]*Sin[c + d*x])/(5*b*d*(Cos[c + d*x]^2)^(1/6))}


{(Cos[c + d*x]^m*(A + B*Cos[c + d*x] + C*Cos[c + d*x]^2))/(b*Cos[c + d*x])^(4/3), x, 5, (3*C*Cos[c + d*x]^(1 + m)*Sin[c + d*x])/(d*(2 + 3*m)*(b*Cos[c + d*x])^(4/3)) + (B*Cos[c + d*x]^(2 + m)*(Cos[c + d*x]^2)^((-2 - 3*m)/6)*Hypergeometric2F1[1/2, (4 - 3*m)/6, 3/2, Sin[c + d*x]^2]*Sin[c + d*x])/(d*(b*Cos[c + d*x])^(4/3)) - ((C*(1 - 3*m) - A*(2 + 3*m))*Cos[c + d*x]^(1 + m)*(Cos[c + d*x]^2)^((1 - 3*m)/6)*Hypergeometric2F1[1/2, (7 - 3*m)/6, 3/2, Sin[c + d*x]^2]*Sin[c + d*x])/(d*(2 + 3*m)*(b*Cos[c + d*x])^(4/3))}

{(Cos[c + d*x]^2*(A + B*Cos[c + d*x] + C*Cos[c + d*x]^2))/(b*Cos[c + d*x])^(4/3), x, 8, (3*B*(b*Cos[c + d*x])^(2/3)*Sin[c + d*x])/(5*b^2*d) + (3*C*(b*Cos[c + d*x])^(5/3)*Sin[c + d*x])/(8*b^3*d) + ((8*A + 5*C)*(Cos[c + d*x]^2)^(1/6)*Hypergeometric2F1[1/6, 1/2, 3/2, Sin[c + d*x]^2]*Sin[c + d*x])/(8*b*d*(b*Cos[c + d*x])^(1/3)) + (2*B*(b*Cos[c + d*x])^(2/3)*Hypergeometric2F1[1/2, 2/3, 3/2, Sin[c + d*x]^2]*Sin[c + d*x])/(5*b^2*d*(Cos[c + d*x]^2)^(1/3))}
{(Cos[c + d*x]*(A + B*Cos[c + d*x] + C*Cos[c + d*x]^2))/(b*Cos[c + d*x])^(4/3), x, 7, (3*C*(b*Cos[c + d*x])^(2/3)*Sin[c + d*x])/(5*b^2*d) + (B*(Cos[c + d*x]^2)^(1/6)*Hypergeometric2F1[1/6, 1/2, 3/2, Sin[c + d*x]^2]*Sin[c + d*x])/(b*d*(b*Cos[c + d*x])^(1/3)) + ((5*A + 2*C)*(b*Cos[c + d*x])^(2/3)*Hypergeometric2F1[1/2, 2/3, 3/2, Sin[c + d*x]^2]*Sin[c + d*x])/(5*b^2*d*(Cos[c + d*x]^2)^(1/3))}
{(A + B*Cos[c + d*x] + C*Cos[c + d*x]^2)/(b*Cos[c + d*x])^(4/3), x, 6, (3*A*Sin[c + d*x])/(b*d*(b*Cos[c + d*x])^(1/3)) - ((2*A - C)*(Cos[c + d*x]^2)^(1/6)*Hypergeometric2F1[1/6, 1/2, 3/2, Sin[c + d*x]^2]*Sin[c + d*x])/(b*d*(b*Cos[c + d*x])^(1/3)) + (B*(b*Cos[c + d*x])^(2/3)*Hypergeometric2F1[1/2, 2/3, 3/2, Sin[c + d*x]^2]*Sin[c + d*x])/(b^2*d*(Cos[c + d*x]^2)^(1/3))}
{((A + B*Cos[c + d*x] + C*Cos[c + d*x]^2)*Sec[c + d*x])/(b*Cos[c + d*x])^(4/3), x, 8, (3*A*Sin[c + d*x])/(4*d*(b*Cos[c + d*x])^(4/3)) + (3*B*Sin[c + d*x])/(b*d*(b*Cos[c + d*x])^(1/3)) - (2*B*(Cos[c + d*x]^2)^(1/6)*Hypergeometric2F1[1/6, 1/2, 3/2, Sin[c + d*x]^2]*Sin[c + d*x])/(b*d*(b*Cos[c + d*x])^(1/3)) + ((A + 4*C)*(b*Cos[c + d*x])^(2/3)*Hypergeometric2F1[1/2, 2/3, 3/2, Sin[c + d*x]^2]*Sin[c + d*x])/(4*b^2*d*(Cos[c + d*x]^2)^(1/3))}
{((A + B*Cos[c + d*x] + C*Cos[c + d*x]^2)*Sec[c + d*x]^2)/(b*Cos[c + d*x])^(4/3), x, 9, (3*A*b*Sin[c + d*x])/(7*d*(b*Cos[c + d*x])^(7/3)) + (3*B*Sin[c + d*x])/(4*d*(b*Cos[c + d*x])^(4/3)) + (3*(4*A + 7*C)*Sin[c + d*x])/(7*b*d*(b*Cos[c + d*x])^(1/3)) - (2*(4*A + 7*C)*(Cos[c + d*x]^2)^(1/6)*Hypergeometric2F1[1/6, 1/2, 3/2, Sin[c + d*x]^2]*Sin[c + d*x])/(7*b*d*(b*Cos[c + d*x])^(1/3)) + (B*(b*Cos[c + d*x])^(2/3)*Hypergeometric2F1[1/2, 2/3, 3/2, Sin[c + d*x]^2]*Sin[c + d*x])/(4*b^2*d*(Cos[c + d*x]^2)^(1/3))}
{((A + B*Cos[c + d*x] + C*Cos[c + d*x]^2)*Sec[c + d*x]^3)/(b*Cos[c + d*x])^(4/3), x, 10, (3*A*b^2*Sin[c + d*x])/(10*d*(b*Cos[c + d*x])^(10/3)) + (3*b*B*Sin[c + d*x])/(7*d*(b*Cos[c + d*x])^(7/3)) + (3*(7*A + 10*C)*Sin[c + d*x])/(40*d*(b*Cos[c + d*x])^(4/3)) + (12*B*Sin[c + d*x])/(7*b*d*(b*Cos[c + d*x])^(1/3)) - (8*B*(Cos[c + d*x]^2)^(1/6)*Hypergeometric2F1[1/6, 1/2, 3/2, Sin[c + d*x]^2]*Sin[c + d*x])/(7*b*d*(b*Cos[c + d*x])^(1/3)) + ((7*A + 10*C)*(b*Cos[c + d*x])^(2/3)*Hypergeometric2F1[1/2, 2/3, 3/2, Sin[c + d*x]^2]*Sin[c + d*x])/(40*b^2*d*(Cos[c + d*x]^2)^(1/3))}


(* ::Subsection::Closed:: *)
(*Integrands of the form Cos[c+d x]^m (A+B Cos[c+d x]+C Cos[c+d x]^2) (b Cos[c+d x])^n when n symbolic*)


{Cos[c + d*x]^m*(b*Cos[c + d*x])^n*(A + B*Cos[c + d*x] + C*Cos[c + d*x]^2), x, 5, (C*Cos[c + d*x]^(1 + m)*(b*Cos[c + d*x])^n*Sin[c + d*x])/(d*(2 + m + n)) + (B*Cos[c + d*x]^(2 + m)*(b*Cos[c + d*x])^n*(Cos[c + d*x]^2)^((1/2)*(-2 - m - n))*Hypergeometric2F1[1/2, (1/2)*(-m - n), 3/2, Sin[c + d*x]^2]*Sin[c + d*x])/d + ((C*(1 + m + n) + A*(2 + m + n))*Cos[c + d*x]^(1 + m)*(b*Cos[c + d*x])^n*(Cos[c + d*x]^2)^((1/2)*(-1 - m - n))*Hypergeometric2F1[1/2, (1/2)*(1 - m - n), 3/2, Sin[c + d*x]^2]*Sin[c + d*x])/(d*(2 + m + n))}


{Cos[c + d*x]^2*(b*Cos[c + d*x])^n*(A + B*Cos[c + d*x] + C*Cos[c + d*x]^2), x, 7, (C*(b*Cos[c + d*x])^(3 + n)*Sin[c + d*x])/(b^3*d*(4 + n)) + (B*(b*Cos[c + d*x])^(4 + n)*(Cos[c + d*x]^2)^((1/2)*(-4 - n))*Hypergeometric2F1[1/2, (1/2)*(-2 - n), 3/2, Sin[c + d*x]^2]*Sin[c + d*x])/(b^4*d) + ((C*(3 + n) + A*(4 + n))*(b*Cos[c + d*x])^(3 + n)*(Cos[c + d*x]^2)^((1/2)*(-3 - n))*Hypergeometric2F1[1/2, (1/2)*(-1 - n), 3/2, Sin[c + d*x]^2]*Sin[c + d*x])/(b^3*d*(4 + n))}
{Cos[c + d*x]^1*(b*Cos[c + d*x])^n*(A + B*Cos[c + d*x] + C*Cos[c + d*x]^2), x, 7, (C*(b*Cos[c + d*x])^(2 + n)*Sin[c + d*x])/(b^2*d*(3 + n)) + (B*(b*Cos[c + d*x])^(3 + n)*(Cos[c + d*x]^2)^((1/2)*(-3 - n))*Hypergeometric2F1[1/2, (1/2)*(-1 - n), 3/2, Sin[c + d*x]^2]*Sin[c + d*x])/(b^3*d) + ((C*(2 + n) + A*(3 + n))*(b*Cos[c + d*x])^(2 + n)*(Cos[c + d*x]^2)^((1/2)*(-2 - n))*Hypergeometric2F1[1/2, -(n/2), 3/2, Sin[c + d*x]^2]*Sin[c + d*x])/(b^2*d*(3 + n))}
{Cos[c + d*x]^0*(b*Cos[c + d*x])^n*(A + B*Cos[c + d*x] + C*Cos[c + d*x]^2), x, 6, (C*(b*Cos[c + d*x])^(1 + n)*Sin[c + d*x])/(b*d*(2 + n)) + ((C*(1 + n) + A*(2 + n))*(b*Cos[c + d*x])^(1 + n)*(Cos[c + d*x]^2)^((1/2)*(-1 - n))*Hypergeometric2F1[1/2, (1 - n)/2, 3/2, Sin[c + d*x]^2]*Sin[c + d*x])/(b*d*(2 + n)) + (B*(b*Cos[c + d*x])^(2 + n)*(Cos[c + d*x]^2)^((1/2)*(-2 - n))*Hypergeometric2F1[1/2, -(n/2), 3/2, Sin[c + d*x]^2]*Sin[c + d*x])/(b^2*d)}
{(b*Cos[c + d*x])^n*(A + B*Cos[c + d*x] + C*Cos[c + d*x]^2)*Sec[c + d*x]^1, x, 7, (C*(b*Cos[c + d*x])^n*Sin[c + d*x])/(d*(1 + n)) + (B*(b*Cos[c + d*x])^(1 + n)*(Cos[c + d*x]^2)^((1/2)*(-1 - n))*Hypergeometric2F1[1/2, (1 - n)/2, 3/2, Sin[c + d*x]^2]*Sin[c + d*x])/(b*d) + ((A + A*n + C*n)*(b*Cos[c + d*x])^n*Hypergeometric2F1[1/2, (2 - n)/2, 3/2, Sin[c + d*x]^2]*Sin[c + d*x])/((Cos[c + d*x]^2)^(n/2)*(d*(1 + n)))}
{(b*Cos[c + d*x])^n*(A + B*Cos[c + d*x] + C*Cos[c + d*x]^2)*Sec[c + d*x]^2, x, 7, (b*C*(b*Cos[c + d*x])^(-1 + n)*Sin[c + d*x])/(d*n) + (B*(b*Cos[c + d*x])^n*Hypergeometric2F1[1/2, (2 - n)/2, 3/2, Sin[c + d*x]^2]*Sin[c + d*x])/((Cos[c + d*x]^2)^(n/2)*d) - (b*(C*(1 - n) - A*n)*(b*Cos[c + d*x])^(-1 + n)*(Cos[c + d*x]^2)^((1 - n)/2)*Hypergeometric2F1[1/2, (3 - n)/2, 3/2, Sin[c + d*x]^2]*Sin[c + d*x])/(d*n)}
{(b*Cos[c + d*x])^n*(A + B*Cos[c + d*x] + C*Cos[c + d*x]^2)*Sec[c + d*x]^3, x, 7, -((b^2*C*(b*Cos[c + d*x])^(-2 + n)*Sin[c + d*x])/(d*(1 - n))) + (b*B*(b*Cos[c + d*x])^(-1 + n)*(Cos[c + d*x]^2)^((1 - n)/2)*Hypergeometric2F1[1/2, (3 - n)/2, 3/2, Sin[c + d*x]^2]*Sin[c + d*x])/d + (b^2*(A*(1 - n) + C*(2 - n))*(b*Cos[c + d*x])^(-2 + n)*(Cos[c + d*x]^2)^((2 - n)/2)*Hypergeometric2F1[1/2, (4 - n)/2, 3/2, Sin[c + d*x]^2]*Sin[c + d*x])/(d*(1 - n))}
{(b*Cos[c + d*x])^n*(A + B*Cos[c + d*x] + C*Cos[c + d*x]^2)*Sec[c + d*x]^4, x, 7, -((b^3*C*(b*Cos[c + d*x])^(-3 + n)*Sin[c + d*x])/(d*(2 - n))) + (b^2*B*(b*Cos[c + d*x])^(-2 + n)*(Cos[c + d*x]^2)^((2 - n)/2)*Hypergeometric2F1[1/2, (4 - n)/2, 3/2, Sin[c + d*x]^2]*Sin[c + d*x])/d + (b^3*(A*(2 - n) + C*(3 - n))*(b*Cos[c + d*x])^(-3 + n)*(Cos[c + d*x]^2)^((3 - n)/2)*Hypergeometric2F1[1/2, (5 - n)/2, 3/2, Sin[c + d*x]^2]*Sin[c + d*x])/(d*(2 - n))}


{Cos[c + d*x]^(5/2)*(b*Cos[c + d*x])^n*(A + B*Cos[c + d*x] + C*Cos[c + d*x]^2), x, 5, (2*C*Cos[c + d*x]^(7/2)*(b*Cos[c + d*x])^n*Sin[c + d*x])/(d*(9 + 2*n)) + (B*Cos[c + d*x]^(9/2)*(b*Cos[c + d*x])^n*(Cos[c + d*x]^2)^((1/4)*(-9 - 2*n))*Hypergeometric2F1[1/2, (1/4)*(-5 - 2*n), 3/2, Sin[c + d*x]^2]*Sin[c + d*x])/d + ((C*(7 + 2*n) + A*(9 + 2*n))*Cos[c + d*x]^(7/2)*(b*Cos[c + d*x])^n*(Cos[c + d*x]^2)^((1/4)*(-7 - 2*n))*Hypergeometric2F1[1/2, (1/4)*(-3 - 2*n), 3/2, Sin[c + d*x]^2]*Sin[c + d*x])/(d*(9 + 2*n))}
{Cos[c + d*x]^(3/2)*(b*Cos[c + d*x])^n*(A + B*Cos[c + d*x] + C*Cos[c + d*x]^2), x, 5, (2*C*Cos[c + d*x]^(5/2)*(b*Cos[c + d*x])^n*Sin[c + d*x])/(d*(7 + 2*n)) + (B*Cos[c + d*x]^(7/2)*(b*Cos[c + d*x])^n*(Cos[c + d*x]^2)^((1/4)*(-7 - 2*n))*Hypergeometric2F1[1/2, (1/4)*(-3 - 2*n), 3/2, Sin[c + d*x]^2]*Sin[c + d*x])/d + ((C*(5 + 2*n) + A*(7 + 2*n))*Cos[c + d*x]^(5/2)*(b*Cos[c + d*x])^n*(Cos[c + d*x]^2)^((1/4)*(-5 - 2*n))*Hypergeometric2F1[1/2, (1/4)*(-1 - 2*n), 3/2, Sin[c + d*x]^2]*Sin[c + d*x])/(d*(7 + 2*n))}
{Sqrt[Cos[c + d*x]]*(b*Cos[c + d*x])^n*(A + B*Cos[c + d*x] + C*Cos[c + d*x]^2), x, 5, (2*C*Cos[c + d*x]^(3/2)*(b*Cos[c + d*x])^n*Sin[c + d*x])/(d*(5 + 2*n)) + (B*Cos[c + d*x]^(5/2)*(b*Cos[c + d*x])^n*(Cos[c + d*x]^2)^((1/4)*(-5 - 2*n))*Hypergeometric2F1[1/2, (1/4)*(-1 - 2*n), 3/2, Sin[c + d*x]^2]*Sin[c + d*x])/d + ((C*(3 + 2*n) + A*(5 + 2*n))*Cos[c + d*x]^(3/2)*(b*Cos[c + d*x])^n*(Cos[c + d*x]^2)^((1/4)*(-3 - 2*n))*Hypergeometric2F1[1/2, (1/4)*(1 - 2*n), 3/2, Sin[c + d*x]^2]*Sin[c + d*x])/(d*(5 + 2*n))}
{((b*Cos[c + d*x])^n*(A + B*Cos[c + d*x] + C*Cos[c + d*x]^2))/Sqrt[Cos[c + d*x]], x, 5, (2*C*Sqrt[Cos[c + d*x]]*(b*Cos[c + d*x])^n*Sin[c + d*x])/(d*(3 + 2*n)) + (B*Cos[c + d*x]^(3/2)*(b*Cos[c + d*x])^n*(Cos[c + d*x]^2)^((1/4)*(-3 - 2*n))*Hypergeometric2F1[1/2, (1/4)*(1 - 2*n), 3/2, Sin[c + d*x]^2]*Sin[c + d*x])/d + ((C + 2*C*n + A*(3 + 2*n))*Sqrt[Cos[c + d*x]]*(b*Cos[c + d*x])^n*(Cos[c + d*x]^2)^((1/4)*(-1 - 2*n))*Hypergeometric2F1[1/2, (1/4)*(3 - 2*n), 3/2, Sin[c + d*x]^2]*Sin[c + d*x])/(d*(3 + 2*n))}
{((b*Cos[c + d*x])^n*(A + B*Cos[c + d*x] + C*Cos[c + d*x]^2))/Cos[c + d*x]^(3/2), x, 5, (2*C*(b*Cos[c + d*x])^n*Sin[c + d*x])/(d*(1 + 2*n)*Sqrt[Cos[c + d*x]]) + (B*Sqrt[Cos[c + d*x]]*(b*Cos[c + d*x])^n*(Cos[c + d*x]^2)^((1/4)*(-1 - 2*n))*Hypergeometric2F1[1/2, (1/4)*(3 - 2*n), 3/2, Sin[c + d*x]^2]*Sin[c + d*x])/d + ((A - C*(1 - 2*n) + 2*A*n)*(b*Cos[c + d*x])^n*(Cos[c + d*x]^2)^((1/4)*(1 - 2*n))*Hypergeometric2F1[1/2, (1/4)*(5 - 2*n), 3/2, Sin[c + d*x]^2]*Sin[c + d*x])/(d*(1 + 2*n)*Sqrt[Cos[c + d*x]])}
{((b*Cos[c + d*x])^n*(A + B*Cos[c + d*x] + C*Cos[c + d*x]^2))/Cos[c + d*x]^(5/2), x, 5, -((2*C*(b*Cos[c + d*x])^n*Sin[c + d*x])/(d*(1 - 2*n)*Cos[c + d*x]^(3/2))) + (B*(b*Cos[c + d*x])^n*(Cos[c + d*x]^2)^((1/4)*(1 - 2*n))*Hypergeometric2F1[1/2, (1/4)*(5 - 2*n), 3/2, Sin[c + d*x]^2]*Sin[c + d*x])/(d*Sqrt[Cos[c + d*x]]) + ((A*(1 - 2*n) + C*(3 - 2*n))*(b*Cos[c + d*x])^n*(Cos[c + d*x]^2)^((1/4)*(3 - 2*n))*Hypergeometric2F1[1/2, (1/4)*(7 - 2*n), 3/2, Sin[c + d*x]^2]*Sin[c + d*x])/(d*(1 - 2*n)*Cos[c + d*x]^(3/2))}
{((b*Cos[c + d*x])^n*(A + B*Cos[c + d*x] + C*Cos[c + d*x]^2))/Cos[c + d*x]^(7/2), x, 5, -((2*C*(b*Cos[c + d*x])^n*Sin[c + d*x])/(d*(3 - 2*n)*Cos[c + d*x]^(5/2))) + (B*(b*Cos[c + d*x])^n*(Cos[c + d*x]^2)^((1/4)*(3 - 2*n))*Hypergeometric2F1[1/2, (1/4)*(7 - 2*n), 3/2, Sin[c + d*x]^2]*Sin[c + d*x])/(d*Cos[c + d*x]^(3/2)) + ((A*(3 - 2*n) + C*(5 - 2*n))*(b*Cos[c + d*x])^n*(Cos[c + d*x]^2)^((1/4)*(5 - 2*n))*Hypergeometric2F1[1/2, (1/4)*(9 - 2*n), 3/2, Sin[c + d*x]^2]*Sin[c + d*x])/(d*(3 - 2*n)*Cos[c + d*x]^(5/2))}
{((b*Cos[c + d*x])^n*(A + B*Cos[c + d*x] + C*Cos[c + d*x]^2))/Cos[c + d*x]^(9/2), x, 5, -((2*C*(b*Cos[c + d*x])^n*Sin[c + d*x])/(d*(5 - 2*n)*Cos[c + d*x]^(7/2))) + (B*(b*Cos[c + d*x])^n*(Cos[c + d*x]^2)^((1/4)*(5 - 2*n))*Hypergeometric2F1[1/2, (1/4)*(9 - 2*n), 3/2, Sin[c + d*x]^2]*Sin[c + d*x])/(d*Cos[c + d*x]^(5/2)) + ((A*(5 - 2*n) + C*(7 - 2*n))*(b*Cos[c + d*x])^n*(Cos[c + d*x]^2)^((1/4)*(7 - 2*n))*Hypergeometric2F1[1/2, (1/4)*(11 - 2*n), 3/2, Sin[c + d*x]^2]*Sin[c + d*x])/(d*(5 - 2*n)*Cos[c + d*x]^(7/2))}
