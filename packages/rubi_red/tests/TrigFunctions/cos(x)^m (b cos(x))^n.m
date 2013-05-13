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
{Cos[c + d*x]^4*Sqrt[b*Cos[c + d*x]], x, 5, (14*b*Sqrt[Cos[c + d*x]]*EllipticE[(1/2)*(c + d*x), 2])/(15*d*Sqrt[b*Cos[c + d*x]]) + (14*(b*Cos[c + d*x])^(3/2)*Sin[c + d*x])/(45*b*d) + (2*(b*Cos[c + d*x])^(7/2)*Sin[c + d*x])/(9*b^3*d)}
{Cos[c + d*x]^3*Sqrt[b*Cos[c + d*x]], x, 5, (10*b*Sqrt[Cos[c + d*x]]*EllipticF[(1/2)*(c + d*x), 2])/(21*d*Sqrt[b*Cos[c + d*x]]) + (10*Sqrt[b*Cos[c + d*x]]*Sin[c + d*x])/(21*d) + (2*(b*Cos[c + d*x])^(5/2)*Sin[c + d*x])/(7*b^2*d)}
{Cos[c + d*x]^2*Sqrt[b*Cos[c + d*x]], x, 4, (6*b*Sqrt[Cos[c + d*x]]*EllipticE[(1/2)*(c + d*x), 2])/(5*d*Sqrt[b*Cos[c + d*x]]) + (2*(b*Cos[c + d*x])^(3/2)*Sin[c + d*x])/(5*b*d)}
{Cos[c + d*x]^1*Sqrt[b*Cos[c + d*x]], x, 4, (2*b*Sqrt[Cos[c + d*x]]*EllipticF[(1/2)*(c + d*x), 2])/(3*d*Sqrt[b*Cos[c + d*x]]) + (2*Sqrt[b*Cos[c + d*x]]*Sin[c + d*x])/(3*d)}
{Cos[c + d*x]^0*Sqrt[b*Cos[c + d*x]], x, 2, (2*b*Sqrt[Cos[c + d*x]]*EllipticE[(1/2)*(c + d*x), 2])/(d*Sqrt[b*Cos[c + d*x]])}
{Sec[c + d*x]^1*Sqrt[b*Cos[c + d*x]], x, 3, (2*b*Sqrt[Cos[c + d*x]]*EllipticF[(1/2)*(c + d*x), 2])/(d*Sqrt[b*Cos[c + d*x]])}
{Sec[c + d*x]^2*Sqrt[b*Cos[c + d*x]], x, 4, -((2*b*Sqrt[Cos[c + d*x]]*EllipticE[(1/2)*(c + d*x), 2])/(d*Sqrt[b*Cos[c + d*x]])) + (2*b*Sin[c + d*x])/(d*Sqrt[b*Cos[c + d*x]])}
{Sec[c + d*x]^3*Sqrt[b*Cos[c + d*x]], x, 4, (2*b*Sqrt[Cos[c + d*x]]*EllipticF[(1/2)*(c + d*x), 2])/(3*d*Sqrt[b*Cos[c + d*x]]) + (2*b^2*Sin[c + d*x])/(3*d*(b*Cos[c + d*x])^(3/2))}
{Sec[c + d*x]^4*Sqrt[b*Cos[c + d*x]], x, 5, -((6*b*Sqrt[Cos[c + d*x]]*EllipticE[(1/2)*(c + d*x), 2])/(5*d*Sqrt[b*Cos[c + d*x]])) + (2*b^3*Sin[c + d*x])/(5*d*(b*Cos[c + d*x])^(5/2)) + (6*b*Sin[c + d*x])/(5*d*Sqrt[b*Cos[c + d*x]])}
{Sec[c + d*x]^5*Sqrt[b*Cos[c + d*x]], x, 5, (10*b*Sqrt[Cos[c + d*x]]*EllipticF[(1/2)*(c + d*x), 2])/(21*d*Sqrt[b*Cos[c + d*x]]) + (2*b^4*Sin[c + d*x])/(7*d*(b*Cos[c + d*x])^(7/2)) + (10*b^2*Sin[c + d*x])/(21*d*(b*Cos[c + d*x])^(3/2))}
{Sec[c + d*x]^6*Sqrt[b*Cos[c + d*x]], x, 6, -((14*b*Sqrt[Cos[c + d*x]]*EllipticE[(1/2)*(c + d*x), 2])/(15*d*Sqrt[b*Cos[c + d*x]])) + (2*b^5*Sin[c + d*x])/(9*d*(b*Cos[c + d*x])^(9/2)) + (14*b^3*Sin[c + d*x])/(45*d*(b*Cos[c + d*x])^(5/2)) + (14*b*Sin[c + d*x])/(15*d*Sqrt[b*Cos[c + d*x]])}


{Cos[c + d*x]^4*(b*Cos[c + d*x])^(3/2), x, 6, (30*b^2*Sqrt[Cos[c + d*x]]*EllipticF[(1/2)*(c + d*x), 2])/(77*d*Sqrt[b*Cos[c + d*x]]) + (30*b*Sqrt[b*Cos[c + d*x]]*Sin[c + d*x])/(77*d) + (18*(b*Cos[c + d*x])^(5/2)*Sin[c + d*x])/(77*b*d) + (2*(b*Cos[c + d*x])^(9/2)*Sin[c + d*x])/(11*b^3*d)}
{Cos[c + d*x]^3*(b*Cos[c + d*x])^(3/2), x, 5, (14*b^2*Sqrt[Cos[c + d*x]]*EllipticE[(1/2)*(c + d*x), 2])/(15*d*Sqrt[b*Cos[c + d*x]]) + (14*(b*Cos[c + d*x])^(3/2)*Sin[c + d*x])/(45*d) + (2*(b*Cos[c + d*x])^(7/2)*Sin[c + d*x])/(9*b^2*d)}
{Cos[c + d*x]^2*(b*Cos[c + d*x])^(3/2), x, 5, (10*b^2*Sqrt[Cos[c + d*x]]*EllipticF[(1/2)*(c + d*x), 2])/(21*d*Sqrt[b*Cos[c + d*x]]) + (10*b*Sqrt[b*Cos[c + d*x]]*Sin[c + d*x])/(21*d) + (2*(b*Cos[c + d*x])^(5/2)*Sin[c + d*x])/(7*b*d)}
{Cos[c + d*x]^1*(b*Cos[c + d*x])^(3/2), x, 4, (6*b^2*Sqrt[Cos[c + d*x]]*EllipticE[(1/2)*(c + d*x), 2])/(5*d*Sqrt[b*Cos[c + d*x]]) + (2*(b*Cos[c + d*x])^(3/2)*Sin[c + d*x])/(5*d)}
{Cos[c + d*x]^0*(b*Cos[c + d*x])^(3/2), x, 3, (2*b^2*Sqrt[Cos[c + d*x]]*EllipticF[(1/2)*(c + d*x), 2])/(3*d*Sqrt[b*Cos[c + d*x]]) + (2*b*Sqrt[b*Cos[c + d*x]]*Sin[c + d*x])/(3*d)}
{Sec[c + d*x]^1*(b*Cos[c + d*x])^(3/2), x, 3, (2*b^2*Sqrt[Cos[c + d*x]]*EllipticE[(1/2)*(c + d*x), 2])/(d*Sqrt[b*Cos[c + d*x]])}
{Sec[c + d*x]^2*(b*Cos[c + d*x])^(3/2), x, 3, (2*b^2*Sqrt[Cos[c + d*x]]*EllipticF[(1/2)*(c + d*x), 2])/(d*Sqrt[b*Cos[c + d*x]])}
{Sec[c + d*x]^3*(b*Cos[c + d*x])^(3/2), x, 4, -((2*b^2*Sqrt[Cos[c + d*x]]*EllipticE[(1/2)*(c + d*x), 2])/(d*Sqrt[b*Cos[c + d*x]])) + (2*b^2*Sin[c + d*x])/(d*Sqrt[b*Cos[c + d*x]])}
{Sec[c + d*x]^4*(b*Cos[c + d*x])^(3/2), x, 4, (2*b^2*Sqrt[Cos[c + d*x]]*EllipticF[(1/2)*(c + d*x), 2])/(3*d*Sqrt[b*Cos[c + d*x]]) + (2*b^3*Sin[c + d*x])/(3*d*(b*Cos[c + d*x])^(3/2))}
{Sec[c + d*x]^5*(b*Cos[c + d*x])^(3/2), x, 5, -((6*b^2*Sqrt[Cos[c + d*x]]*EllipticE[(1/2)*(c + d*x), 2])/(5*d*Sqrt[b*Cos[c + d*x]])) + (2*b^4*Sin[c + d*x])/(5*d*(b*Cos[c + d*x])^(5/2)) + (6*b^2*Sin[c + d*x])/(5*d*Sqrt[b*Cos[c + d*x]])}
{Sec[c + d*x]^6*(b*Cos[c + d*x])^(3/2), x, 5, (10*b^2*Sqrt[Cos[c + d*x]]*EllipticF[(1/2)*(c + d*x), 2])/(21*d*Sqrt[b*Cos[c + d*x]]) + (2*b^5*Sin[c + d*x])/(7*d*(b*Cos[c + d*x])^(7/2)) + (10*b^3*Sin[c + d*x])/(21*d*(b*Cos[c + d*x])^(3/2))}
{Sec[c + d*x]^7*(b*Cos[c + d*x])^(3/2), x, 6, -((14*b^2*Sqrt[Cos[c + d*x]]*EllipticE[(1/2)*(c + d*x), 2])/(15*d*Sqrt[b*Cos[c + d*x]])) + (2*b^6*Sin[c + d*x])/(9*d*(b*Cos[c + d*x])^(9/2)) + (14*b^4*Sin[c + d*x])/(45*d*(b*Cos[c + d*x])^(5/2)) + (14*b^2*Sin[c + d*x])/(15*d*Sqrt[b*Cos[c + d*x]])}


{Cos[c + d*x]^3*(b*Cos[c + d*x])^(5/2), x, 6, (30*b^3*Sqrt[Cos[c + d*x]]*EllipticF[(1/2)*(c + d*x), 2])/(77*d*Sqrt[b*Cos[c + d*x]]) + (30*b^2*Sqrt[b*Cos[c + d*x]]*Sin[c + d*x])/(77*d) + (18*(b*Cos[c + d*x])^(5/2)*Sin[c + d*x])/(77*d) + (2*(b*Cos[c + d*x])^(9/2)*Sin[c + d*x])/(11*b^2*d)}
{Cos[c + d*x]^2*(b*Cos[c + d*x])^(5/2), x, 5, (14*b^3*Sqrt[Cos[c + d*x]]*EllipticE[(1/2)*(c + d*x), 2])/(15*d*Sqrt[b*Cos[c + d*x]]) + (14*b*(b*Cos[c + d*x])^(3/2)*Sin[c + d*x])/(45*d) + (2*(b*Cos[c + d*x])^(7/2)*Sin[c + d*x])/(9*b*d)}
{Cos[c + d*x]^1*(b*Cos[c + d*x])^(5/2), x, 5, (10*b^3*Sqrt[Cos[c + d*x]]*EllipticF[(1/2)*(c + d*x), 2])/(21*d*Sqrt[b*Cos[c + d*x]]) + (10*b^2*Sqrt[b*Cos[c + d*x]]*Sin[c + d*x])/(21*d) + (2*(b*Cos[c + d*x])^(5/2)*Sin[c + d*x])/(7*d)}
{Cos[c + d*x]^0*(b*Cos[c + d*x])^(5/2), x, 3, (6*b^3*Sqrt[Cos[c + d*x]]*EllipticE[(1/2)*(c + d*x), 2])/(5*d*Sqrt[b*Cos[c + d*x]]) + (2*b*(b*Cos[c + d*x])^(3/2)*Sin[c + d*x])/(5*d)}
{Sec[c + d*x]^1*(b*Cos[c + d*x])^(5/2), x, 4, (2*b^3*Sqrt[Cos[c + d*x]]*EllipticF[(1/2)*(c + d*x), 2])/(3*d*Sqrt[b*Cos[c + d*x]]) + (2*b^2*Sqrt[b*Cos[c + d*x]]*Sin[c + d*x])/(3*d)}
{Sec[c + d*x]^2*(b*Cos[c + d*x])^(5/2), x, 3, (2*b^3*Sqrt[Cos[c + d*x]]*EllipticE[(1/2)*(c + d*x), 2])/(d*Sqrt[b*Cos[c + d*x]])}
{Sec[c + d*x]^3*(b*Cos[c + d*x])^(5/2), x, 3, (2*b^3*Sqrt[Cos[c + d*x]]*EllipticF[(1/2)*(c + d*x), 2])/(d*Sqrt[b*Cos[c + d*x]])}
{Sec[c + d*x]^4*(b*Cos[c + d*x])^(5/2), x, 4, -((2*b^3*Sqrt[Cos[c + d*x]]*EllipticE[(1/2)*(c + d*x), 2])/(d*Sqrt[b*Cos[c + d*x]])) + (2*b^3*Sin[c + d*x])/(d*Sqrt[b*Cos[c + d*x]])}
{Sec[c + d*x]^5*(b*Cos[c + d*x])^(5/2), x, 4, (2*b^3*Sqrt[Cos[c + d*x]]*EllipticF[(1/2)*(c + d*x), 2])/(3*d*Sqrt[b*Cos[c + d*x]]) + (2*b^4*Sin[c + d*x])/(3*d*(b*Cos[c + d*x])^(3/2))}
{Sec[c + d*x]^6*(b*Cos[c + d*x])^(5/2), x, 5, -((6*b^3*Sqrt[Cos[c + d*x]]*EllipticE[(1/2)*(c + d*x), 2])/(5*d*Sqrt[b*Cos[c + d*x]])) + (2*b^5*Sin[c + d*x])/(5*d*(b*Cos[c + d*x])^(5/2)) + (6*b^3*Sin[c + d*x])/(5*d*Sqrt[b*Cos[c + d*x]])}
{Sec[c + d*x]^7*(b*Cos[c + d*x])^(5/2), x, 5, (10*b^3*Sqrt[Cos[c + d*x]]*EllipticF[(1/2)*(c + d*x), 2])/(21*d*Sqrt[b*Cos[c + d*x]]) + (2*b^6*Sin[c + d*x])/(7*d*(b*Cos[c + d*x])^(7/2)) + (10*b^4*Sin[c + d*x])/(21*d*(b*Cos[c + d*x])^(3/2))}
{Sec[c + d*x]^8*(b*Cos[c + d*x])^(5/2), x, 6, -((14*b^3*Sqrt[Cos[c + d*x]]*EllipticE[(1/2)*(c + d*x), 2])/(15*d*Sqrt[b*Cos[c + d*x]])) + (2*b^7*Sin[c + d*x])/(9*d*(b*Cos[c + d*x])^(9/2)) + (14*b^5*Sin[c + d*x])/(45*d*(b*Cos[c + d*x])^(5/2)) + (14*b^3*Sin[c + d*x])/(15*d*Sqrt[b*Cos[c + d*x]])}


{(b*Cos[c + d*x])^(7/2), x, 4, (10*b^4*Sqrt[Cos[c + d*x]]*EllipticF[(1/2)*(c + d*x), 2])/(21*d*Sqrt[b*Cos[c + d*x]]) + (10*b^3*Sqrt[b*Cos[c + d*x]]*Sin[c + d*x])/(21*d) + (2*b*(b*Cos[c + d*x])^(5/2)*Sin[c + d*x])/(7*d)}


(* ::Subsubsection::Closed:: *)
(*n<0*)


{Cos[c + d*x]^6/Sqrt[b*Cos[c + d*x]], x, 6, (30*Sqrt[Cos[c + d*x]]*EllipticF[(1/2)*(c + d*x), 2])/(77*d*Sqrt[b*Cos[c + d*x]]) + (30*Sqrt[b*Cos[c + d*x]]*Sin[c + d*x])/(77*b*d) + (18*(b*Cos[c + d*x])^(5/2)*Sin[c + d*x])/(77*b^3*d) + (2*(b*Cos[c + d*x])^(9/2)*Sin[c + d*x])/(11*b^5*d)}
{Cos[c + d*x]^5/Sqrt[b*Cos[c + d*x]], x, 5, (14*Sqrt[Cos[c + d*x]]*EllipticE[(1/2)*(c + d*x), 2])/(15*d*Sqrt[b*Cos[c + d*x]]) + (14*(b*Cos[c + d*x])^(3/2)*Sin[c + d*x])/(45*b^2*d) + (2*(b*Cos[c + d*x])^(7/2)*Sin[c + d*x])/(9*b^4*d)}
{Cos[c + d*x]^4/Sqrt[b*Cos[c + d*x]], x, 5, (10*Sqrt[Cos[c + d*x]]*EllipticF[(1/2)*(c + d*x), 2])/(21*d*Sqrt[b*Cos[c + d*x]]) + (10*Sqrt[b*Cos[c + d*x]]*Sin[c + d*x])/(21*b*d) + (2*(b*Cos[c + d*x])^(5/2)*Sin[c + d*x])/(7*b^3*d)}
{Cos[c + d*x]^3/Sqrt[b*Cos[c + d*x]], x, 4, (6*Sqrt[Cos[c + d*x]]*EllipticE[(1/2)*(c + d*x), 2])/(5*d*Sqrt[b*Cos[c + d*x]]) + (2*(b*Cos[c + d*x])^(3/2)*Sin[c + d*x])/(5*b^2*d)}
{Cos[c + d*x]^2/Sqrt[b*Cos[c + d*x]], x, 4, (2*Sqrt[Cos[c + d*x]]*EllipticF[(1/2)*(c + d*x), 2])/(3*d*Sqrt[b*Cos[c + d*x]]) + (2*Sqrt[b*Cos[c + d*x]]*Sin[c + d*x])/(3*b*d)}
{Cos[c + d*x]^1/Sqrt[b*Cos[c + d*x]], x, 3, (2*Sqrt[Cos[c + d*x]]*EllipticE[(1/2)*(c + d*x), 2])/(d*Sqrt[b*Cos[c + d*x]])}
{Cos[c + d*x]^0/Sqrt[b*Cos[c + d*x]], x, 2, (2*Sqrt[Cos[c + d*x]]*EllipticF[(1/2)*(c + d*x), 2])/(d*Sqrt[b*Cos[c + d*x]])}
{Sec[c + d*x]^1/Sqrt[b*Cos[c + d*x]], x, 3, (Sqrt[Cos[c + d*x]]*(-((2*EllipticE[(1/2)*(c + d*x), 2])/d) + (2*Sin[c + d*x])/(d*Sqrt[Cos[c + d*x]])))/Sqrt[b*Cos[c + d*x]]}
{Sec[c + d*x]^2/Sqrt[b*Cos[c + d*x]], x, 4, (2*Sqrt[Cos[c + d*x]]*EllipticF[(1/2)*(c + d*x), 2])/(3*d*Sqrt[b*Cos[c + d*x]]) + (2*b*Sin[c + d*x])/(3*d*(b*Cos[c + d*x])^(3/2))}
{Sec[c + d*x]^3/Sqrt[b*Cos[c + d*x]], x, 5, -((6*Sqrt[Cos[c + d*x]]*EllipticE[(1/2)*(c + d*x), 2])/(5*d*Sqrt[b*Cos[c + d*x]])) + (2*b^2*Sin[c + d*x])/(5*d*(b*Cos[c + d*x])^(5/2)) + (6*Sin[c + d*x])/(5*d*Sqrt[b*Cos[c + d*x]])}
{Sec[c + d*x]^4/Sqrt[b*Cos[c + d*x]], x, 5, (10*Sqrt[Cos[c + d*x]]*EllipticF[(1/2)*(c + d*x), 2])/(21*d*Sqrt[b*Cos[c + d*x]]) + (2*b^3*Sin[c + d*x])/(7*d*(b*Cos[c + d*x])^(7/2)) + (10*b*Sin[c + d*x])/(21*d*(b*Cos[c + d*x])^(3/2))}
{Sec[c + d*x]^5/Sqrt[b*Cos[c + d*x]], x, 6, -((14*Sqrt[Cos[c + d*x]]*EllipticE[(1/2)*(c + d*x), 2])/(15*d*Sqrt[b*Cos[c + d*x]])) + (2*b^4*Sin[c + d*x])/(9*d*(b*Cos[c + d*x])^(9/2)) + (14*b^2*Sin[c + d*x])/(45*d*(b*Cos[c + d*x])^(5/2)) + (14*Sin[c + d*x])/(15*d*Sqrt[b*Cos[c + d*x]])}


{Cos[c + d*x]^7/(b*Cos[c + d*x])^(3/2), x, 6, (30*Sqrt[Cos[c + d*x]]*EllipticF[(1/2)*(c + d*x), 2])/(77*b*d*Sqrt[b*Cos[c + d*x]]) + (30*Sqrt[b*Cos[c + d*x]]*Sin[c + d*x])/(77*b^2*d) + (18*(b*Cos[c + d*x])^(5/2)*Sin[c + d*x])/(77*b^4*d) + (2*(b*Cos[c + d*x])^(9/2)*Sin[c + d*x])/(11*b^6*d)}
{Cos[c + d*x]^6/(b*Cos[c + d*x])^(3/2), x, 5, (14*Sqrt[Cos[c + d*x]]*EllipticE[(1/2)*(c + d*x), 2])/(15*b*d*Sqrt[b*Cos[c + d*x]]) + (14*(b*Cos[c + d*x])^(3/2)*Sin[c + d*x])/(45*b^3*d) + (2*(b*Cos[c + d*x])^(7/2)*Sin[c + d*x])/(9*b^5*d)}
{Cos[c + d*x]^5/(b*Cos[c + d*x])^(3/2), x, 5, (10*Sqrt[Cos[c + d*x]]*EllipticF[(1/2)*(c + d*x), 2])/(21*b*d*Sqrt[b*Cos[c + d*x]]) + (10*Sqrt[b*Cos[c + d*x]]*Sin[c + d*x])/(21*b^2*d) + (2*(b*Cos[c + d*x])^(5/2)*Sin[c + d*x])/(7*b^4*d)}
{Cos[c + d*x]^4/(b*Cos[c + d*x])^(3/2), x, 4, (6*Sqrt[Cos[c + d*x]]*EllipticE[(1/2)*(c + d*x), 2])/(5*b*d*Sqrt[b*Cos[c + d*x]]) + (2*(b*Cos[c + d*x])^(3/2)*Sin[c + d*x])/(5*b^3*d)}
{Cos[c + d*x]^3/(b*Cos[c + d*x])^(3/2), x, 4, (2*Sqrt[Cos[c + d*x]]*EllipticF[(1/2)*(c + d*x), 2])/(3*b*d*Sqrt[b*Cos[c + d*x]]) + (2*Sqrt[b*Cos[c + d*x]]*Sin[c + d*x])/(3*b^2*d)}
{Cos[c + d*x]^2/(b*Cos[c + d*x])^(3/2), x, 3, (2*Sqrt[Cos[c + d*x]]*EllipticE[(1/2)*(c + d*x), 2])/(b*d*Sqrt[b*Cos[c + d*x]])}
{Cos[c + d*x]^1/(b*Cos[c + d*x])^(3/2), x, 3, (2*Sqrt[Cos[c + d*x]]*EllipticF[(1/2)*(c + d*x), 2])/(b*d*Sqrt[b*Cos[c + d*x]])}
{Cos[c + d*x]^0/(b*Cos[c + d*x])^(3/2), x, 3, -((2*Sqrt[Cos[c + d*x]]*EllipticE[(1/2)*(c + d*x), 2])/(b*d*Sqrt[b*Cos[c + d*x]])) + (2*Sin[c + d*x])/(b*d*Sqrt[b*Cos[c + d*x]])}
{Sec[c + d*x]^1/(b*Cos[c + d*x])^(3/2), x, 4, (2*Sqrt[Cos[c + d*x]]*EllipticF[(1/2)*(c + d*x), 2])/(3*b*d*Sqrt[b*Cos[c + d*x]]) + (2*Sin[c + d*x])/(3*d*(b*Cos[c + d*x])^(3/2))}
{Sec[c + d*x]^2/(b*Cos[c + d*x])^(3/2), x, 5, -((6*Sqrt[Cos[c + d*x]]*EllipticE[(1/2)*(c + d*x), 2])/(5*b*d*Sqrt[b*Cos[c + d*x]])) + (2*b*Sin[c + d*x])/(5*d*(b*Cos[c + d*x])^(5/2)) + (6*Sin[c + d*x])/(5*b*d*Sqrt[b*Cos[c + d*x]])}
{Sec[c + d*x]^3/(b*Cos[c + d*x])^(3/2), x, 5, (10*Sqrt[Cos[c + d*x]]*EllipticF[(1/2)*(c + d*x), 2])/(21*b*d*Sqrt[b*Cos[c + d*x]]) + (2*b^2*Sin[c + d*x])/(7*d*(b*Cos[c + d*x])^(7/2)) + (10*Sin[c + d*x])/(21*d*(b*Cos[c + d*x])^(3/2))}
{Sec[c + d*x]^4/(b*Cos[c + d*x])^(3/2), x, 6, -((14*Sqrt[Cos[c + d*x]]*EllipticE[(1/2)*(c + d*x), 2])/(15*b*d*Sqrt[b*Cos[c + d*x]])) + (2*b^3*Sin[c + d*x])/(9*d*(b*Cos[c + d*x])^(9/2)) + (14*b*Sin[c + d*x])/(45*d*(b*Cos[c + d*x])^(5/2)) + (14*Sin[c + d*x])/(15*b*d*Sqrt[b*Cos[c + d*x]])}


{Cos[c + d*x]^8/(b*Cos[c + d*x])^(5/2), x, 6, (30*Sqrt[Cos[c + d*x]]*EllipticF[(1/2)*(c + d*x), 2])/(77*b^2*d*Sqrt[b*Cos[c + d*x]]) + (30*Sqrt[b*Cos[c + d*x]]*Sin[c + d*x])/(77*b^3*d) + (18*(b*Cos[c + d*x])^(5/2)*Sin[c + d*x])/(77*b^5*d) + (2*(b*Cos[c + d*x])^(9/2)*Sin[c + d*x])/(11*b^7*d)}
{Cos[c + d*x]^7/(b*Cos[c + d*x])^(5/2), x, 5, (14*Sqrt[Cos[c + d*x]]*EllipticE[(1/2)*(c + d*x), 2])/(15*b^2*d*Sqrt[b*Cos[c + d*x]]) + (14*(b*Cos[c + d*x])^(3/2)*Sin[c + d*x])/(45*b^4*d) + (2*(b*Cos[c + d*x])^(7/2)*Sin[c + d*x])/(9*b^6*d)}
{Cos[c + d*x]^6/(b*Cos[c + d*x])^(5/2), x, 5, (10*Sqrt[Cos[c + d*x]]*EllipticF[(1/2)*(c + d*x), 2])/(21*b^2*d*Sqrt[b*Cos[c + d*x]]) + (10*Sqrt[b*Cos[c + d*x]]*Sin[c + d*x])/(21*b^3*d) + (2*(b*Cos[c + d*x])^(5/2)*Sin[c + d*x])/(7*b^5*d)}
{Cos[c + d*x]^5/(b*Cos[c + d*x])^(5/2), x, 4, (6*Sqrt[Cos[c + d*x]]*EllipticE[(1/2)*(c + d*x), 2])/(5*b^2*d*Sqrt[b*Cos[c + d*x]]) + (2*(b*Cos[c + d*x])^(3/2)*Sin[c + d*x])/(5*b^4*d)}
{Cos[c + d*x]^4/(b*Cos[c + d*x])^(5/2), x, 4, (2*Sqrt[Cos[c + d*x]]*EllipticF[(1/2)*(c + d*x), 2])/(3*b^2*d*Sqrt[b*Cos[c + d*x]]) + (2*Sqrt[b*Cos[c + d*x]]*Sin[c + d*x])/(3*b^3*d)}
{Cos[c + d*x]^3/(b*Cos[c + d*x])^(5/2), x, 3, (2*Sqrt[Cos[c + d*x]]*EllipticE[(1/2)*(c + d*x), 2])/(b^2*d*Sqrt[b*Cos[c + d*x]])}
{Cos[c + d*x]^2/(b*Cos[c + d*x])^(5/2), x, 3, (2*Sqrt[Cos[c + d*x]]*EllipticF[(1/2)*(c + d*x), 2])/(b^2*d*Sqrt[b*Cos[c + d*x]])}
{Cos[c + d*x]^1/(b*Cos[c + d*x])^(5/2), x, 4, -((2*Sqrt[Cos[c + d*x]]*EllipticE[(1/2)*(c + d*x), 2])/(b^2*d*Sqrt[b*Cos[c + d*x]])) + (2*Sin[c + d*x])/(b^2*d*Sqrt[b*Cos[c + d*x]])}
{Cos[c + d*x]^0/(b*Cos[c + d*x])^(5/2), x, 3, (2*Sqrt[Cos[c + d*x]]*EllipticF[(1/2)*(c + d*x), 2])/(3*b^2*d*Sqrt[b*Cos[c + d*x]]) + (2*Sin[c + d*x])/(3*b*d*(b*Cos[c + d*x])^(3/2))}
{Sec[c + d*x]^1/(b*Cos[c + d*x])^(5/2), x, 5, -((6*Sqrt[Cos[c + d*x]]*EllipticE[(1/2)*(c + d*x), 2])/(5*b^2*d*Sqrt[b*Cos[c + d*x]])) + (2*Sin[c + d*x])/(5*d*(b*Cos[c + d*x])^(5/2)) + (6*Sin[c + d*x])/(5*b^2*d*Sqrt[b*Cos[c + d*x]])}
{Sec[c + d*x]^2/(b*Cos[c + d*x])^(5/2), x, 5, (10*Sqrt[Cos[c + d*x]]*EllipticF[(1/2)*(c + d*x), 2])/(21*b^2*d*Sqrt[b*Cos[c + d*x]]) + (2*b*Sin[c + d*x])/(7*d*(b*Cos[c + d*x])^(7/2)) + (10*Sin[c + d*x])/(21*b*d*(b*Cos[c + d*x])^(3/2))}
{Sec[c + d*x]^3/(b*Cos[c + d*x])^(5/2), x, 6, -((14*Sqrt[Cos[c + d*x]]*EllipticE[(1/2)*(c + d*x), 2])/(15*b^2*d*Sqrt[b*Cos[c + d*x]])) + (2*b^2*Sin[c + d*x])/(9*d*(b*Cos[c + d*x])^(9/2)) + (14*Sin[c + d*x])/(45*d*(b*Cos[c + d*x])^(5/2)) + (14*Sin[c + d*x])/(15*b^2*d*Sqrt[b*Cos[c + d*x]])}


{1/(b*Cos[c + d*x])^(7/2), x, 4, -((6*Sqrt[Cos[c + d*x]]*EllipticE[(1/2)*(c + d*x), 2])/(5*b^3*d*Sqrt[b*Cos[c + d*x]])) + (2*Sin[c + d*x])/(5*b*d*(b*Cos[c + d*x])^(5/2)) + (6*Sin[c + d*x])/(5*b^3*d*Sqrt[b*Cos[c + d*x]])}


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


(* ::Section:: *)
(*Cos[c+d x]^m (A+B Cos[c+d x]) (b Cos[c+d x])^(n/2)*)


(* ::Subsection::Closed:: *)
(*Integrands of the form Cos[c+d x]^m (A+B Cos[c+d x]) (b Cos[c+d x])^(n/2)*)


(* ::Subsubsection::Closed:: *)
(*n>0*)


{Cos[c + d*x]^2*(A + B*Cos[c + d*x])*(b*Cos[c + d*x])^(1/2), x, 9, (6*A*b*Sqrt[Cos[c + d*x]]*EllipticE[(1/2)*(c + d*x), 2])/(5*d*Sqrt[b*Cos[c + d*x]]) + (10*b*B*Sqrt[Cos[c + d*x]]*EllipticF[(1/2)*(c + d*x), 2])/(21*d*Sqrt[b*Cos[c + d*x]]) + (10*B*Sqrt[b*Cos[c + d*x]]*Sin[c + d*x])/(21*d) + (2*A*(b*Cos[c + d*x])^(3/2)*Sin[c + d*x])/(5*b*d) + (2*B*(b*Cos[c + d*x])^(5/2)*Sin[c + d*x])/(7*b^2*d)}
{Cos[c + d*x]^1*(A + B*Cos[c + d*x])*(b*Cos[c + d*x])^(1/2), x, 8, (6*b*B*Sqrt[Cos[c + d*x]]*EllipticE[(1/2)*(c + d*x), 2])/(5*d*Sqrt[b*Cos[c + d*x]]) + (2*A*b*Sqrt[Cos[c + d*x]]*EllipticF[(1/2)*(c + d*x), 2])/(3*d*Sqrt[b*Cos[c + d*x]]) + (2*A*Sqrt[b*Cos[c + d*x]]*Sin[c + d*x])/(3*d) + (2*B*(b*Cos[c + d*x])^(3/2)*Sin[c + d*x])/(5*b*d)}
{Cos[c + d*x]^0*(A + B*Cos[c + d*x])*(b*Cos[c + d*x])^(1/2), x, 6, (2*A*b*Sqrt[Cos[c + d*x]]*EllipticE[(1/2)*(c + d*x), 2])/(d*Sqrt[b*Cos[c + d*x]]) + (2*b*B*Sqrt[Cos[c + d*x]]*EllipticF[(1/2)*(c + d*x), 2])/(3*d*Sqrt[b*Cos[c + d*x]]) + (2*B*Sqrt[b*Cos[c + d*x]]*Sin[c + d*x])/(3*d)}
{Sec[c + d*x]^1*(A + B*Cos[c + d*x])*(b*Cos[c + d*x])^(1/2), x, 6, (2*b*B*Sqrt[Cos[c + d*x]]*EllipticE[(1/2)*(c + d*x), 2])/(d*Sqrt[b*Cos[c + d*x]]) + (2*A*b*Sqrt[Cos[c + d*x]]*EllipticF[(1/2)*(c + d*x), 2])/(d*Sqrt[b*Cos[c + d*x]])}
{Sec[c + d*x]^2*(A + B*Cos[c + d*x])*(b*Cos[c + d*x])^(1/2), x, 7, -((2*A*b*Sqrt[Cos[c + d*x]]*EllipticE[(1/2)*(c + d*x), 2])/(d*Sqrt[b*Cos[c + d*x]])) + (2*b*B*Sqrt[Cos[c + d*x]]*EllipticF[(1/2)*(c + d*x), 2])/(d*Sqrt[b*Cos[c + d*x]]) + (2*A*b*Sin[c + d*x])/(d*Sqrt[b*Cos[c + d*x]])}
{Sec[c + d*x]^3*(A + B*Cos[c + d*x])*(b*Cos[c + d*x])^(1/2), x, 8, -((2*b*B*Sqrt[Cos[c + d*x]]*EllipticE[(1/2)*(c + d*x), 2])/(d*Sqrt[b*Cos[c + d*x]])) + (2*A*b*Sqrt[Cos[c + d*x]]*EllipticF[(1/2)*(c + d*x), 2])/(3*d*Sqrt[b*Cos[c + d*x]]) + (2*A*b^2*Sin[c + d*x])/(3*d*(b*Cos[c + d*x])^(3/2)) + (2*b*B*Sin[c + d*x])/(d*Sqrt[b*Cos[c + d*x]])}
{Sec[c + d*x]^4*(A + B*Cos[c + d*x])*(b*Cos[c + d*x])^(1/2), x, 9, -((6*A*b*Sqrt[Cos[c + d*x]]*EllipticE[(1/2)*(c + d*x), 2])/(5*d*Sqrt[b*Cos[c + d*x]])) + (2*b*B*Sqrt[Cos[c + d*x]]*EllipticF[(1/2)*(c + d*x), 2])/(3*d*Sqrt[b*Cos[c + d*x]]) + (2*A*b^3*Sin[c + d*x])/(5*d*(b*Cos[c + d*x])^(5/2)) + (2*b^2*B*Sin[c + d*x])/(3*d*(b*Cos[c + d*x])^(3/2)) + (6*A*b*Sin[c + d*x])/(5*d*Sqrt[b*Cos[c + d*x]])}


{Cos[c + d*x]^1*(A + B*Cos[c + d*x])*(b*Cos[c + d*x])^(3/2), x, 9, (6*A*b^2*Sqrt[Cos[c + d*x]]*EllipticE[(1/2)*(c + d*x), 2])/(5*d*Sqrt[b*Cos[c + d*x]]) + (10*b^2*B*Sqrt[Cos[c + d*x]]*EllipticF[(1/2)*(c + d*x), 2])/(21*d*Sqrt[b*Cos[c + d*x]]) + (10*b*B*Sqrt[b*Cos[c + d*x]]*Sin[c + d*x])/(21*d) + (2*A*(b*Cos[c + d*x])^(3/2)*Sin[c + d*x])/(5*d) + (2*B*(b*Cos[c + d*x])^(5/2)*Sin[c + d*x])/(7*b*d)}
{Cos[c + d*x]^0*(A + B*Cos[c + d*x])*(b*Cos[c + d*x])^(3/2), x, 7, (6*b^2*B*Sqrt[Cos[c + d*x]]*EllipticE[(1/2)*(c + d*x), 2])/(5*d*Sqrt[b*Cos[c + d*x]]) + (2*A*b^2*Sqrt[Cos[c + d*x]]*EllipticF[(1/2)*(c + d*x), 2])/(3*d*Sqrt[b*Cos[c + d*x]]) + (2*A*b*Sqrt[b*Cos[c + d*x]]*Sin[c + d*x])/(3*d) + (2*B*(b*Cos[c + d*x])^(3/2)*Sin[c + d*x])/(5*d)}
{Sec[c + d*x]^1*(A + B*Cos[c + d*x])*(b*Cos[c + d*x])^(3/2), x, 7, (2*A*b^2*Sqrt[Cos[c + d*x]]*EllipticE[(1/2)*(c + d*x), 2])/(d*Sqrt[b*Cos[c + d*x]]) + (2*b^2*B*Sqrt[Cos[c + d*x]]*EllipticF[(1/2)*(c + d*x), 2])/(3*d*Sqrt[b*Cos[c + d*x]]) + (2*b*B*Sqrt[b*Cos[c + d*x]]*Sin[c + d*x])/(3*d)}
{Sec[c + d*x]^2*(A + B*Cos[c + d*x])*(b*Cos[c + d*x])^(3/2), x, 6, (2*b^2*B*Sqrt[Cos[c + d*x]]*EllipticE[(1/2)*(c + d*x), 2])/(d*Sqrt[b*Cos[c + d*x]]) + (2*A*b^2*Sqrt[Cos[c + d*x]]*EllipticF[(1/2)*(c + d*x), 2])/(d*Sqrt[b*Cos[c + d*x]])}
{Sec[c + d*x]^3*(A + B*Cos[c + d*x])*(b*Cos[c + d*x])^(3/2), x, 7, -((2*A*b^2*Sqrt[Cos[c + d*x]]*EllipticE[(1/2)*(c + d*x), 2])/(d*Sqrt[b*Cos[c + d*x]])) + (2*b^2*B*Sqrt[Cos[c + d*x]]*EllipticF[(1/2)*(c + d*x), 2])/(d*Sqrt[b*Cos[c + d*x]]) + (2*A*b^2*Sin[c + d*x])/(d*Sqrt[b*Cos[c + d*x]])}
{Sec[c + d*x]^4*(A + B*Cos[c + d*x])*(b*Cos[c + d*x])^(3/2), x, 8, -((2*b^2*B*Sqrt[Cos[c + d*x]]*EllipticE[(1/2)*(c + d*x), 2])/(d*Sqrt[b*Cos[c + d*x]])) + (2*A*b^2*Sqrt[Cos[c + d*x]]*EllipticF[(1/2)*(c + d*x), 2])/(3*d*Sqrt[b*Cos[c + d*x]]) + (2*A*b^3*Sin[c + d*x])/(3*d*(b*Cos[c + d*x])^(3/2)) + (2*b^2*B*Sin[c + d*x])/(d*Sqrt[b*Cos[c + d*x]])}
{Sec[c + d*x]^5*(A + B*Cos[c + d*x])*(b*Cos[c + d*x])^(3/2), x, 9, -((6*A*b^2*Sqrt[Cos[c + d*x]]*EllipticE[(1/2)*(c + d*x), 2])/(5*d*Sqrt[b*Cos[c + d*x]])) + (2*b^2*B*Sqrt[Cos[c + d*x]]*EllipticF[(1/2)*(c + d*x), 2])/(3*d*Sqrt[b*Cos[c + d*x]]) + (2*A*b^4*Sin[c + d*x])/(5*d*(b*Cos[c + d*x])^(5/2)) + (2*b^3*B*Sin[c + d*x])/(3*d*(b*Cos[c + d*x])^(3/2)) + (6*A*b^2*Sin[c + d*x])/(5*d*Sqrt[b*Cos[c + d*x]])}


{Cos[c + d*x]^0*(A + B*Cos[c + d*x])*(b*Cos[c + d*x])^(5/2), x, 8, (6*A*b^3*Sqrt[Cos[c + d*x]]*EllipticE[(1/2)*(c + d*x), 2])/(5*d*Sqrt[b*Cos[c + d*x]]) + (10*b^3*B*Sqrt[Cos[c + d*x]]*EllipticF[(1/2)*(c + d*x), 2])/(21*d*Sqrt[b*Cos[c + d*x]]) + (10*b^2*B*Sqrt[b*Cos[c + d*x]]*Sin[c + d*x])/(21*d) + (2*A*b*(b*Cos[c + d*x])^(3/2)*Sin[c + d*x])/(5*d) + (2*B*(b*Cos[c + d*x])^(5/2)*Sin[c + d*x])/(7*d)}
{Sec[c + d*x]^1*(A + B*Cos[c + d*x])*(b*Cos[c + d*x])^(5/2), x, 8, (6*b^3*B*Sqrt[Cos[c + d*x]]*EllipticE[(1/2)*(c + d*x), 2])/(5*d*Sqrt[b*Cos[c + d*x]]) + (2*A*b^3*Sqrt[Cos[c + d*x]]*EllipticF[(1/2)*(c + d*x), 2])/(3*d*Sqrt[b*Cos[c + d*x]]) + (2*A*b^2*Sqrt[b*Cos[c + d*x]]*Sin[c + d*x])/(3*d) + (2*b*B*(b*Cos[c + d*x])^(3/2)*Sin[c + d*x])/(5*d)}
{Sec[c + d*x]^2*(A + B*Cos[c + d*x])*(b*Cos[c + d*x])^(5/2), x, 7, (2*A*b^3*Sqrt[Cos[c + d*x]]*EllipticE[(1/2)*(c + d*x), 2])/(d*Sqrt[b*Cos[c + d*x]]) + (2*b^3*B*Sqrt[Cos[c + d*x]]*EllipticF[(1/2)*(c + d*x), 2])/(3*d*Sqrt[b*Cos[c + d*x]]) + (2*b^2*B*Sqrt[b*Cos[c + d*x]]*Sin[c + d*x])/(3*d)}
{Sec[c + d*x]^3*(A + B*Cos[c + d*x])*(b*Cos[c + d*x])^(5/2), x, 6, (2*b^3*B*Sqrt[Cos[c + d*x]]*EllipticE[(1/2)*(c + d*x), 2])/(d*Sqrt[b*Cos[c + d*x]]) + (2*A*b^3*Sqrt[Cos[c + d*x]]*EllipticF[(1/2)*(c + d*x), 2])/(d*Sqrt[b*Cos[c + d*x]])}
{Sec[c + d*x]^4*(A + B*Cos[c + d*x])*(b*Cos[c + d*x])^(5/2), x, 7, -((2*A*b^3*Sqrt[Cos[c + d*x]]*EllipticE[(1/2)*(c + d*x), 2])/(d*Sqrt[b*Cos[c + d*x]])) + (2*b^3*B*Sqrt[Cos[c + d*x]]*EllipticF[(1/2)*(c + d*x), 2])/(d*Sqrt[b*Cos[c + d*x]]) + (2*A*b^3*Sin[c + d*x])/(d*Sqrt[b*Cos[c + d*x]])}
{Sec[c + d*x]^5*(A + B*Cos[c + d*x])*(b*Cos[c + d*x])^(5/2), x, 8, -((2*b^3*B*Sqrt[Cos[c + d*x]]*EllipticE[(1/2)*(c + d*x), 2])/(d*Sqrt[b*Cos[c + d*x]])) + (2*A*b^3*Sqrt[Cos[c + d*x]]*EllipticF[(1/2)*(c + d*x), 2])/(3*d*Sqrt[b*Cos[c + d*x]]) + (2*A*b^4*Sin[c + d*x])/(3*d*(b*Cos[c + d*x])^(3/2)) + (2*b^3*B*Sin[c + d*x])/(d*Sqrt[b*Cos[c + d*x]])}
{Sec[c + d*x]^6*(A + B*Cos[c + d*x])*(b*Cos[c + d*x])^(5/2), x, 9, -((6*A*b^3*Sqrt[Cos[c + d*x]]*EllipticE[(1/2)*(c + d*x), 2])/(5*d*Sqrt[b*Cos[c + d*x]])) + (2*b^3*B*Sqrt[Cos[c + d*x]]*EllipticF[(1/2)*(c + d*x), 2])/(3*d*Sqrt[b*Cos[c + d*x]]) + (2*A*b^5*Sin[c + d*x])/(5*d*(b*Cos[c + d*x])^(5/2)) + (2*b^4*B*Sin[c + d*x])/(3*d*(b*Cos[c + d*x])^(3/2)) + (6*A*b^3*Sin[c + d*x])/(5*d*Sqrt[b*Cos[c + d*x]])}


(* ::Subsubsection::Closed:: *)
(*n<0*)


{Cos[c + d*x]^3*(A + B*Cos[c + d*x])/(b*Cos[c + d*x])^(1/2), x, 9, (6*A*Sqrt[Cos[c + d*x]]*EllipticE[(1/2)*(c + d*x), 2])/(5*d*Sqrt[b*Cos[c + d*x]]) + (10*B*Sqrt[Cos[c + d*x]]*EllipticF[(1/2)*(c + d*x), 2])/(21*d*Sqrt[b*Cos[c + d*x]]) + (10*B*Sqrt[b*Cos[c + d*x]]*Sin[c + d*x])/(21*b*d) + (2*A*(b*Cos[c + d*x])^(3/2)*Sin[c + d*x])/(5*b^2*d) + (2*B*(b*Cos[c + d*x])^(5/2)*Sin[c + d*x])/(7*b^3*d)}
{Cos[c + d*x]^2*(A + B*Cos[c + d*x])/(b*Cos[c + d*x])^(1/2), x, 8, (6*B*Sqrt[Cos[c + d*x]]*EllipticE[(1/2)*(c + d*x), 2])/(5*d*Sqrt[b*Cos[c + d*x]]) + (2*A*Sqrt[Cos[c + d*x]]*EllipticF[(1/2)*(c + d*x), 2])/(3*d*Sqrt[b*Cos[c + d*x]]) + (2*A*Sqrt[b*Cos[c + d*x]]*Sin[c + d*x])/(3*b*d) + (2*B*(b*Cos[c + d*x])^(3/2)*Sin[c + d*x])/(5*b^2*d)}
{Cos[c + d*x]^1*(A + B*Cos[c + d*x])/(b*Cos[c + d*x])^(1/2), x, 7, (2*A*Sqrt[Cos[c + d*x]]*EllipticE[(1/2)*(c + d*x), 2])/(d*Sqrt[b*Cos[c + d*x]]) + (2*B*Sqrt[Cos[c + d*x]]*EllipticF[(1/2)*(c + d*x), 2])/(3*d*Sqrt[b*Cos[c + d*x]]) + (2*B*Sqrt[b*Cos[c + d*x]]*Sin[c + d*x])/(3*b*d)}
{Cos[c + d*x]^0*(A + B*Cos[c + d*x])/(b*Cos[c + d*x])^(1/2), x, 5, (2*B*Sqrt[Cos[c + d*x]]*EllipticE[(1/2)*(c + d*x), 2])/(d*Sqrt[b*Cos[c + d*x]]) + (2*A*Sqrt[Cos[c + d*x]]*EllipticF[(1/2)*(c + d*x), 2])/(d*Sqrt[b*Cos[c + d*x]])}
{Sec[c + d*x]^1*(A + B*Cos[c + d*x])/(b*Cos[c + d*x])^(1/2), x, 7, -((2*A*Sqrt[Cos[c + d*x]]*EllipticE[(1/2)*(c + d*x), 2])/(d*Sqrt[b*Cos[c + d*x]])) + (2*B*Sqrt[Cos[c + d*x]]*EllipticF[(1/2)*(c + d*x), 2])/(d*Sqrt[b*Cos[c + d*x]]) + (2*A*Sin[c + d*x])/(d*Sqrt[b*Cos[c + d*x]])}
{Sec[c + d*x]^2*(A + B*Cos[c + d*x])/(b*Cos[c + d*x])^(1/2), x, 8, -((2*B*Sqrt[Cos[c + d*x]]*EllipticE[(1/2)*(c + d*x), 2])/(d*Sqrt[b*Cos[c + d*x]])) + (2*A*Sqrt[Cos[c + d*x]]*EllipticF[(1/2)*(c + d*x), 2])/(3*d*Sqrt[b*Cos[c + d*x]]) + (2*A*b*Sin[c + d*x])/(3*d*(b*Cos[c + d*x])^(3/2)) + (2*B*Sin[c + d*x])/(d*Sqrt[b*Cos[c + d*x]])}
{Sec[c + d*x]^3*(A + B*Cos[c + d*x])/(b*Cos[c + d*x])^(1/2), x, 9, -((6*A*Sqrt[Cos[c + d*x]]*EllipticE[(1/2)*(c + d*x), 2])/(5*d*Sqrt[b*Cos[c + d*x]])) + (2*B*Sqrt[Cos[c + d*x]]*EllipticF[(1/2)*(c + d*x), 2])/(3*d*Sqrt[b*Cos[c + d*x]]) + (2*A*b^2*Sin[c + d*x])/(5*d*(b*Cos[c + d*x])^(5/2)) + (2*b*B*Sin[c + d*x])/(3*d*(b*Cos[c + d*x])^(3/2)) + (6*A*Sin[c + d*x])/(5*d*Sqrt[b*Cos[c + d*x]])}


{Cos[c + d*x]^4*(A + B*Cos[c + d*x])/(b*Cos[c + d*x])^(3/2), x, 9, (6*A*Sqrt[Cos[c + d*x]]*EllipticE[(1/2)*(c + d*x), 2])/(5*b*d*Sqrt[b*Cos[c + d*x]]) + (10*B*Sqrt[Cos[c + d*x]]*EllipticF[(1/2)*(c + d*x), 2])/(21*b*d*Sqrt[b*Cos[c + d*x]]) + (10*B*Sqrt[b*Cos[c + d*x]]*Sin[c + d*x])/(21*b^2*d) + (2*A*(b*Cos[c + d*x])^(3/2)*Sin[c + d*x])/(5*b^3*d) + (2*B*(b*Cos[c + d*x])^(5/2)*Sin[c + d*x])/(7*b^4*d)}
{Cos[c + d*x]^3*(A + B*Cos[c + d*x])/(b*Cos[c + d*x])^(3/2), x, 8, (6*B*Sqrt[Cos[c + d*x]]*EllipticE[(1/2)*(c + d*x), 2])/(5*b*d*Sqrt[b*Cos[c + d*x]]) + (2*A*Sqrt[Cos[c + d*x]]*EllipticF[(1/2)*(c + d*x), 2])/(3*b*d*Sqrt[b*Cos[c + d*x]]) + (2*A*Sqrt[b*Cos[c + d*x]]*Sin[c + d*x])/(3*b^2*d) + (2*B*(b*Cos[c + d*x])^(3/2)*Sin[c + d*x])/(5*b^3*d)}
{Cos[c + d*x]^2*(A + B*Cos[c + d*x])/(b*Cos[c + d*x])^(3/2), x, 7, (2*A*Sqrt[Cos[c + d*x]]*EllipticE[(1/2)*(c + d*x), 2])/(b*d*Sqrt[b*Cos[c + d*x]]) + (2*B*Sqrt[Cos[c + d*x]]*EllipticF[(1/2)*(c + d*x), 2])/(3*b*d*Sqrt[b*Cos[c + d*x]]) + (2*B*Sqrt[b*Cos[c + d*x]]*Sin[c + d*x])/(3*b^2*d)}
{Cos[c + d*x]^1*(A + B*Cos[c + d*x])/(b*Cos[c + d*x])^(3/2), x, 6, (2*B*Sqrt[Cos[c + d*x]]*EllipticE[(1/2)*(c + d*x), 2])/(b*d*Sqrt[b*Cos[c + d*x]]) + (2*A*Sqrt[Cos[c + d*x]]*EllipticF[(1/2)*(c + d*x), 2])/(b*d*Sqrt[b*Cos[c + d*x]])}
{Cos[c + d*x]^0*(A + B*Cos[c + d*x])/(b*Cos[c + d*x])^(3/2), x, 6, -((2*A*Sqrt[Cos[c + d*x]]*EllipticE[(1/2)*(c + d*x), 2])/(b*d*Sqrt[b*Cos[c + d*x]])) + (2*B*Sqrt[Cos[c + d*x]]*EllipticF[(1/2)*(c + d*x), 2])/(b*d*Sqrt[b*Cos[c + d*x]]) + (2*A*Sin[c + d*x])/(b*d*Sqrt[b*Cos[c + d*x]])}
{Sec[c + d*x]^1*(A + B*Cos[c + d*x])/(b*Cos[c + d*x])^(3/2), x, 8, -((2*B*Sqrt[Cos[c + d*x]]*EllipticE[(1/2)*(c + d*x), 2])/(b*d*Sqrt[b*Cos[c + d*x]])) + (2*A*Sqrt[Cos[c + d*x]]*EllipticF[(1/2)*(c + d*x), 2])/(3*b*d*Sqrt[b*Cos[c + d*x]]) + (2*A*Sin[c + d*x])/(3*d*(b*Cos[c + d*x])^(3/2)) + (2*B*Sin[c + d*x])/(b*d*Sqrt[b*Cos[c + d*x]])}
{Sec[c + d*x]^2*(A + B*Cos[c + d*x])/(b*Cos[c + d*x])^(3/2), x, 9, -((6*A*Sqrt[Cos[c + d*x]]*EllipticE[(1/2)*(c + d*x), 2])/(5*b*d*Sqrt[b*Cos[c + d*x]])) + (2*B*Sqrt[Cos[c + d*x]]*EllipticF[(1/2)*(c + d*x), 2])/(3*b*d*Sqrt[b*Cos[c + d*x]]) + (2*A*b*Sin[c + d*x])/(5*d*(b*Cos[c + d*x])^(5/2)) + (2*B*Sin[c + d*x])/(3*d*(b*Cos[c + d*x])^(3/2)) + (6*A*Sin[c + d*x])/(5*b*d*Sqrt[b*Cos[c + d*x]])}


{Cos[c + d*x]^5*(A + B*Cos[c + d*x])/(b*Cos[c + d*x])^(5/2), x, 9, (6*A*Sqrt[Cos[c + d*x]]*EllipticE[(1/2)*(c + d*x), 2])/(5*b^2*d*Sqrt[b*Cos[c + d*x]]) + (10*B*Sqrt[Cos[c + d*x]]*EllipticF[(1/2)*(c + d*x), 2])/(21*b^2*d*Sqrt[b*Cos[c + d*x]]) + (10*B*Sqrt[b*Cos[c + d*x]]*Sin[c + d*x])/(21*b^3*d) + (2*A*(b*Cos[c + d*x])^(3/2)*Sin[c + d*x])/(5*b^4*d) + (2*B*(b*Cos[c + d*x])^(5/2)*Sin[c + d*x])/(7*b^5*d)}
{Cos[c + d*x]^4*(A + B*Cos[c + d*x])/(b*Cos[c + d*x])^(5/2), x, 8, (6*B*Sqrt[Cos[c + d*x]]*EllipticE[(1/2)*(c + d*x), 2])/(5*b^2*d*Sqrt[b*Cos[c + d*x]]) + (2*A*Sqrt[Cos[c + d*x]]*EllipticF[(1/2)*(c + d*x), 2])/(3*b^2*d*Sqrt[b*Cos[c + d*x]]) + (2*A*Sqrt[b*Cos[c + d*x]]*Sin[c + d*x])/(3*b^3*d) + (2*B*(b*Cos[c + d*x])^(3/2)*Sin[c + d*x])/(5*b^4*d)}
{Cos[c + d*x]^3*(A + B*Cos[c + d*x])/(b*Cos[c + d*x])^(5/2), x, 7, (2*A*Sqrt[Cos[c + d*x]]*EllipticE[(1/2)*(c + d*x), 2])/(b^2*d*Sqrt[b*Cos[c + d*x]]) + (2*B*Sqrt[Cos[c + d*x]]*EllipticF[(1/2)*(c + d*x), 2])/(3*b^2*d*Sqrt[b*Cos[c + d*x]]) + (2*B*Sqrt[b*Cos[c + d*x]]*Sin[c + d*x])/(3*b^3*d)}
{Cos[c + d*x]^2*(A + B*Cos[c + d*x])/(b*Cos[c + d*x])^(5/2), x, 6, (2*B*Sqrt[Cos[c + d*x]]*EllipticE[(1/2)*(c + d*x), 2])/(b^2*d*Sqrt[b*Cos[c + d*x]]) + (2*A*Sqrt[Cos[c + d*x]]*EllipticF[(1/2)*(c + d*x), 2])/(b^2*d*Sqrt[b*Cos[c + d*x]])}
{Cos[c + d*x]^1*(A + B*Cos[c + d*x])/(b*Cos[c + d*x])^(5/2), x, 7, -((2*A*Sqrt[Cos[c + d*x]]*EllipticE[(1/2)*(c + d*x), 2])/(b^2*d*Sqrt[b*Cos[c + d*x]])) + (2*B*Sqrt[Cos[c + d*x]]*EllipticF[(1/2)*(c + d*x), 2])/(b^2*d*Sqrt[b*Cos[c + d*x]]) + (2*A*Sin[c + d*x])/(b^2*d*Sqrt[b*Cos[c + d*x]])}
{Cos[c + d*x]^0*(A + B*Cos[c + d*x])/(b*Cos[c + d*x])^(5/2), x, 7, -((2*B*Sqrt[Cos[c + d*x]]*EllipticE[(1/2)*(c + d*x), 2])/(b^2*d*Sqrt[b*Cos[c + d*x]])) + (2*A*Sqrt[Cos[c + d*x]]*EllipticF[(1/2)*(c + d*x), 2])/(3*b^2*d*Sqrt[b*Cos[c + d*x]]) + (2*A*Sin[c + d*x])/(3*b*d*(b*Cos[c + d*x])^(3/2)) + (2*B*Sin[c + d*x])/(b^2*d*Sqrt[b*Cos[c + d*x]])}
{Sec[c + d*x]^1*(A + B*Cos[c + d*x])/(b*Cos[c + d*x])^(5/2), x, 9, -((6*A*Sqrt[Cos[c + d*x]]*EllipticE[(1/2)*(c + d*x), 2])/(5*b^2*d*Sqrt[b*Cos[c + d*x]])) + (2*B*Sqrt[Cos[c + d*x]]*EllipticF[(1/2)*(c + d*x), 2])/(3*b^2*d*Sqrt[b*Cos[c + d*x]]) + (2*A*Sin[c + d*x])/(5*d*(b*Cos[c + d*x])^(5/2)) + (2*B*Sin[c + d*x])/(3*b*d*(b*Cos[c + d*x])^(3/2)) + (6*A*Sin[c + d*x])/(5*b^2*d*Sqrt[b*Cos[c + d*x]])}


{(A + B*Cos[c + d*x])/(b*Cos[c + d*x])^(7/2), x, 8, -((6*A*Sqrt[Cos[c + d*x]]*EllipticE[(1/2)*(c + d*x), 2])/(5*b^3*d*Sqrt[b*Cos[c + d*x]])) + (2*B*Sqrt[Cos[c + d*x]]*EllipticF[(1/2)*(c + d*x), 2])/(3*b^3*d*Sqrt[b*Cos[c + d*x]]) + (2*A*Sin[c + d*x])/(5*b*d*(b*Cos[c + d*x])^(5/2)) + (2*B*Sin[c + d*x])/(3*b^2*d*(b*Cos[c + d*x])^(3/2)) + (6*A*Sin[c + d*x])/(5*b^3*d*Sqrt[b*Cos[c + d*x]])}


(* ::Subsection::Closed:: *)
(*Integrands of the form Cos[c+d x]^(m/2) (A+B Cos[c+d x]) (b Cos[c+d x])^(n/2)*)


(* ::Subsubsection::Closed:: *)
(*n>0*)


{Cos[c + d*x]^(5/2)*(A + B*Cos[c + d*x])*(b*Cos[c + d*x])^(1/2), x, 5, (3*B*x*Sqrt[b*Cos[c + d*x]])/(8*Sqrt[Cos[c + d*x]]) + (2*A*Sqrt[b*Cos[c + d*x]]*Sin[c + d*x])/(3*d*Sqrt[Cos[c + d*x]]) + (3*B*Sqrt[Cos[c + d*x]]*Sqrt[b*Cos[c + d*x]]*Sin[c + d*x])/(8*d) + (A*Cos[c + d*x]^(3/2)*Sqrt[b*Cos[c + d*x]]*Sin[c + d*x])/(3*d) + (B*Cos[c + d*x]^(5/2)*Sqrt[b*Cos[c + d*x]]*Sin[c + d*x])/(4*d)}
{Cos[c + d*x]^(3/2)*(A + B*Cos[c + d*x])*(b*Cos[c + d*x])^(1/2), x, 4, (A*x*Sqrt[b*Cos[c + d*x]])/(2*Sqrt[Cos[c + d*x]]) + (2*B*Sqrt[b*Cos[c + d*x]]*Sin[c + d*x])/(3*d*Sqrt[Cos[c + d*x]]) + (A*Sqrt[Cos[c + d*x]]*Sqrt[b*Cos[c + d*x]]*Sin[c + d*x])/(2*d) + (B*Cos[c + d*x]^(3/2)*Sqrt[b*Cos[c + d*x]]*Sin[c + d*x])/(3*d)}
{Cos[c + d*x]^(1/2)*(A + B*Cos[c + d*x])*(b*Cos[c + d*x])^(1/2), x, 3, (B*x*Sqrt[b*Cos[c + d*x]])/(2*Sqrt[Cos[c + d*x]]) + (A*Sqrt[b*Cos[c + d*x]]*Sin[c + d*x])/(d*Sqrt[Cos[c + d*x]]) + (B*Sqrt[Cos[c + d*x]]*Sqrt[b*Cos[c + d*x]]*Sin[c + d*x])/(2*d)}
{Cos[c + d*x]^(-1/2)*(A + B*Cos[c + d*x])*(b*Cos[c + d*x])^(1/2), x, 4, (A*b*x*Sqrt[Cos[c + d*x]])/Sqrt[b*Cos[c + d*x]] + (b*B*Sqrt[Cos[c + d*x]]*Sin[c + d*x])/(d*Sqrt[b*Cos[c + d*x]])}
{Cos[c + d*x]^(-3/2)*(A + B*Cos[c + d*x])*(b*Cos[c + d*x])^(1/2), x, 3, (B*x*Sqrt[b*Cos[c + d*x]])/Sqrt[Cos[c + d*x]] + (A*ArcTanh[Sin[c + d*x]]*Sqrt[b*Cos[c + d*x]])/(d*Sqrt[Cos[c + d*x]])}
{Cos[c + d*x]^(-5/2)*(A + B*Cos[c + d*x])*(b*Cos[c + d*x])^(1/2), x, 4, (B*ArcTanh[Sin[c + d*x]]*Sqrt[b*Cos[c + d*x]])/(d*Sqrt[Cos[c + d*x]]) + (A*Sqrt[b*Cos[c + d*x]]*Sin[c + d*x])/(d*Cos[c + d*x]^(3/2))}
{Cos[c + d*x]^(-7/2)*(A + B*Cos[c + d*x])*(b*Cos[c + d*x])^(1/2), x, 5, (A*ArcTanh[Sin[c + d*x]]*Sqrt[b*Cos[c + d*x]])/(2*d*Sqrt[Cos[c + d*x]]) + (A*Sqrt[b*Cos[c + d*x]]*Sin[c + d*x])/(2*d*Cos[c + d*x]^(5/2)) + (B*Sqrt[b*Cos[c + d*x]]*Sin[c + d*x])/(d*Cos[c + d*x]^(3/2))}
{Cos[c + d*x]^(-9/2)*(A + B*Cos[c + d*x])*(b*Cos[c + d*x])^(1/2), x, 6, (B*ArcTanh[Sin[c + d*x]]*Sqrt[b*Cos[c + d*x]])/(2*d*Sqrt[Cos[c + d*x]]) + (A*Sqrt[b*Cos[c + d*x]]*Sin[c + d*x])/(3*d*Cos[c + d*x]^(7/2)) + (B*Sqrt[b*Cos[c + d*x]]*Sin[c + d*x])/(2*d*Cos[c + d*x]^(5/2)) + (2*A*Sqrt[b*Cos[c + d*x]]*Sin[c + d*x])/(3*d*Cos[c + d*x]^(3/2))}


{Cos[c + d*x]^(3/2)*(A + B*Cos[c + d*x])*(b*Cos[c + d*x])^(3/2), x, 5, (3*b*B*x*Sqrt[b*Cos[c + d*x]])/(8*Sqrt[Cos[c + d*x]]) + (2*A*b*Sqrt[b*Cos[c + d*x]]*Sin[c + d*x])/(3*d*Sqrt[Cos[c + d*x]]) + (3*b*B*Sqrt[Cos[c + d*x]]*Sqrt[b*Cos[c + d*x]]*Sin[c + d*x])/(8*d) + (A*b*Cos[c + d*x]^(3/2)*Sqrt[b*Cos[c + d*x]]*Sin[c + d*x])/(3*d) + (b*B*Cos[c + d*x]^(5/2)*Sqrt[b*Cos[c + d*x]]*Sin[c + d*x])/(4*d)}
{Cos[c + d*x]^(1/2)*(A + B*Cos[c + d*x])*(b*Cos[c + d*x])^(3/2), x, 4, (A*b*x*Sqrt[b*Cos[c + d*x]])/(2*Sqrt[Cos[c + d*x]]) + (2*b*B*Sqrt[b*Cos[c + d*x]]*Sin[c + d*x])/(3*d*Sqrt[Cos[c + d*x]]) + (A*b*Sqrt[Cos[c + d*x]]*Sqrt[b*Cos[c + d*x]]*Sin[c + d*x])/(2*d) + (b*B*Cos[c + d*x]^(3/2)*Sqrt[b*Cos[c + d*x]]*Sin[c + d*x])/(3*d)}
{Cos[c + d*x]^(-1/2)*(A + B*Cos[c + d*x])*(b*Cos[c + d*x])^(3/2), x, 3, (b*B*x*Sqrt[b*Cos[c + d*x]])/(2*Sqrt[Cos[c + d*x]]) + (A*b*Sqrt[b*Cos[c + d*x]]*Sin[c + d*x])/(d*Sqrt[Cos[c + d*x]]) + (b*B*Sqrt[Cos[c + d*x]]*Sqrt[b*Cos[c + d*x]]*Sin[c + d*x])/(2*d)}
{Cos[c + d*x]^(-3/2)*(A + B*Cos[c + d*x])*(b*Cos[c + d*x])^(3/2), x, 3, (A*b*x*Sqrt[b*Cos[c + d*x]])/Sqrt[Cos[c + d*x]] + (b*B*Sqrt[b*Cos[c + d*x]]*Sin[c + d*x])/(d*Sqrt[Cos[c + d*x]])}
{Cos[c + d*x]^(-5/2)*(A + B*Cos[c + d*x])*(b*Cos[c + d*x])^(3/2), x, 3, (b*B*x*Sqrt[b*Cos[c + d*x]])/Sqrt[Cos[c + d*x]] + (A*b*ArcTanh[Sin[c + d*x]]*Sqrt[b*Cos[c + d*x]])/(d*Sqrt[Cos[c + d*x]])}
{Cos[c + d*x]^(-7/2)*(A + B*Cos[c + d*x])*(b*Cos[c + d*x])^(3/2), x, 4, (b*B*ArcTanh[Sin[c + d*x]]*Sqrt[b*Cos[c + d*x]])/(d*Sqrt[Cos[c + d*x]]) + (A*b*Sqrt[b*Cos[c + d*x]]*Sin[c + d*x])/(d*Cos[c + d*x]^(3/2))}
{Cos[c + d*x]^(-9/2)*(A + B*Cos[c + d*x])*(b*Cos[c + d*x])^(3/2), x, 5, (A*b*ArcTanh[Sin[c + d*x]]*Sqrt[b*Cos[c + d*x]])/(2*d*Sqrt[Cos[c + d*x]]) + (A*b*Sqrt[b*Cos[c + d*x]]*Sin[c + d*x])/(2*d*Cos[c + d*x]^(5/2)) + (b*B*Sqrt[b*Cos[c + d*x]]*Sin[c + d*x])/(d*Cos[c + d*x]^(3/2))}
{Cos[c + d*x]^(-11/2)*(A + B*Cos[c + d*x])*(b*Cos[c + d*x])^(3/2), x, 6, (b*B*ArcTanh[Sin[c + d*x]]*Sqrt[b*Cos[c + d*x]])/(2*d*Sqrt[Cos[c + d*x]]) + (A*b*Sqrt[b*Cos[c + d*x]]*Sin[c + d*x])/(3*d*Cos[c + d*x]^(7/2)) + (b*B*Sqrt[b*Cos[c + d*x]]*Sin[c + d*x])/(2*d*Cos[c + d*x]^(5/2)) + (2*A*b*Sqrt[b*Cos[c + d*x]]*Sin[c + d*x])/(3*d*Cos[c + d*x]^(3/2))}


{Cos[c + d*x]^(1/2)*(A + B*Cos[c + d*x])*(b*Cos[c + d*x])^(5/2), x, 5, (3*b^2*B*x*Sqrt[b*Cos[c + d*x]])/(8*Sqrt[Cos[c + d*x]]) + (2*A*b^2*Sqrt[b*Cos[c + d*x]]*Sin[c + d*x])/(3*d*Sqrt[Cos[c + d*x]]) + (3*b^2*B*Sqrt[Cos[c + d*x]]*Sqrt[b*Cos[c + d*x]]*Sin[c + d*x])/(8*d) + (A*b^2*Cos[c + d*x]^(3/2)*Sqrt[b*Cos[c + d*x]]*Sin[c + d*x])/(3*d) + (b^2*B*Cos[c + d*x]^(5/2)*Sqrt[b*Cos[c + d*x]]*Sin[c + d*x])/(4*d)}
{Cos[c + d*x]^(-1/2)*(A + B*Cos[c + d*x])*(b*Cos[c + d*x])^(5/2), x, 4, (A*b^2*x*Sqrt[b*Cos[c + d*x]])/(2*Sqrt[Cos[c + d*x]]) + (2*b^2*B*Sqrt[b*Cos[c + d*x]]*Sin[c + d*x])/(3*d*Sqrt[Cos[c + d*x]]) + (A*b^2*Sqrt[Cos[c + d*x]]*Sqrt[b*Cos[c + d*x]]*Sin[c + d*x])/(2*d) + (b^2*B*Cos[c + d*x]^(3/2)*Sqrt[b*Cos[c + d*x]]*Sin[c + d*x])/(3*d)}
{Cos[c + d*x]^(-3/2)*(A + B*Cos[c + d*x])*(b*Cos[c + d*x])^(5/2), x, 3, (b^2*B*x*Sqrt[b*Cos[c + d*x]])/(2*Sqrt[Cos[c + d*x]]) + (A*b^2*Sqrt[b*Cos[c + d*x]]*Sin[c + d*x])/(d*Sqrt[Cos[c + d*x]]) + (b^2*B*Sqrt[Cos[c + d*x]]*Sqrt[b*Cos[c + d*x]]*Sin[c + d*x])/(2*d)}
{Cos[c + d*x]^(-5/2)*(A + B*Cos[c + d*x])*(b*Cos[c + d*x])^(5/2), x, 3, (A*b^2*x*Sqrt[b*Cos[c + d*x]])/Sqrt[Cos[c + d*x]] + (b^2*B*Sqrt[b*Cos[c + d*x]]*Sin[c + d*x])/(d*Sqrt[Cos[c + d*x]])}
{Cos[c + d*x]^(-7/2)*(A + B*Cos[c + d*x])*(b*Cos[c + d*x])^(5/2), x, 3, (b^2*B*x*Sqrt[b*Cos[c + d*x]])/Sqrt[Cos[c + d*x]] + (A*b^2*ArcTanh[Sin[c + d*x]]*Sqrt[b*Cos[c + d*x]])/(d*Sqrt[Cos[c + d*x]])}
{Cos[c + d*x]^(-9/2)*(A + B*Cos[c + d*x])*(b*Cos[c + d*x])^(5/2), x, 4, (b^2*B*ArcTanh[Sin[c + d*x]]*Sqrt[b*Cos[c + d*x]])/(d*Sqrt[Cos[c + d*x]]) + (A*b^2*Sqrt[b*Cos[c + d*x]]*Sin[c + d*x])/(d*Cos[c + d*x]^(3/2))}
{Cos[c + d*x]^(-11/2)*(A + B*Cos[c + d*x])*(b*Cos[c + d*x])^(5/2), x, 5, (A*b^2*ArcTanh[Sin[c + d*x]]*Sqrt[b*Cos[c + d*x]])/(2*d*Sqrt[Cos[c + d*x]]) + (A*b^2*Sqrt[b*Cos[c + d*x]]*Sin[c + d*x])/(2*d*Cos[c + d*x]^(5/2)) + (b^2*B*Sqrt[b*Cos[c + d*x]]*Sin[c + d*x])/(d*Cos[c + d*x]^(3/2))}
{Cos[c + d*x]^(-13/2)*(A + B*Cos[c + d*x])*(b*Cos[c + d*x])^(5/2), x, 6, (b^2*B*ArcTanh[Sin[c + d*x]]*Sqrt[b*Cos[c + d*x]])/(2*d*Sqrt[Cos[c + d*x]]) + (A*b^2*Sqrt[b*Cos[c + d*x]]*Sin[c + d*x])/(3*d*Cos[c + d*x]^(7/2)) + (b^2*B*Sqrt[b*Cos[c + d*x]]*Sin[c + d*x])/(2*d*Cos[c + d*x]^(5/2)) + (2*A*b^2*Sqrt[b*Cos[c + d*x]]*Sin[c + d*x])/(3*d*Cos[c + d*x]^(3/2))}


(* ::Subsubsection::Closed:: *)
(*n<0*)


{Cos[c + d*x]^(5/2)*(A + B*Cos[c + d*x])/(b*Cos[c + d*x])^(1/2), x, 4, (A*x*Sqrt[Cos[c + d*x]])/(2*Sqrt[b*Cos[c + d*x]]) + (2*B*Sqrt[Cos[c + d*x]]*Sin[c + d*x])/(3*d*Sqrt[b*Cos[c + d*x]]) + (A*Cos[c + d*x]^(3/2)*Sin[c + d*x])/(2*d*Sqrt[b*Cos[c + d*x]]) + (B*Cos[c + d*x]^(5/2)*Sin[c + d*x])/(3*d*Sqrt[b*Cos[c + d*x]])}
{Cos[c + d*x]^(3/2)*(A + B*Cos[c + d*x])/(b*Cos[c + d*x])^(1/2), x, 3, (B*x*Sqrt[Cos[c + d*x]])/(2*Sqrt[b*Cos[c + d*x]]) + (A*Sqrt[Cos[c + d*x]]*Sin[c + d*x])/(d*Sqrt[b*Cos[c + d*x]]) + (B*Cos[c + d*x]^(3/2)*Sin[c + d*x])/(2*d*Sqrt[b*Cos[c + d*x]])}
{Cos[c + d*x]^(1/2)*(A + B*Cos[c + d*x])/(b*Cos[c + d*x])^(1/2), x, 4, (A*x*Sqrt[Cos[c + d*x]])/Sqrt[b*Cos[c + d*x]] + (B*Sqrt[Cos[c + d*x]]*Sin[c + d*x])/(d*Sqrt[b*Cos[c + d*x]])}
{Cos[c + d*x]^(-1/2)*(A + B*Cos[c + d*x])/(b*Cos[c + d*x])^(1/2), x, 3, (B*x*Sqrt[Cos[c + d*x]])/Sqrt[b*Cos[c + d*x]] + (A*ArcTanh[Sin[c + d*x]]*Sqrt[Cos[c + d*x]])/(d*Sqrt[b*Cos[c + d*x]])}
{Cos[c + d*x]^(-3/2)*(A + B*Cos[c + d*x])/(b*Cos[c + d*x])^(1/2), x, 4, (B*ArcTanh[Sin[c + d*x]]*Sqrt[Cos[c + d*x]])/(d*Sqrt[b*Cos[c + d*x]]) + (A*Sin[c + d*x])/(d*Sqrt[Cos[c + d*x]]*Sqrt[b*Cos[c + d*x]])}
{Cos[c + d*x]^(-5/2)*(A + B*Cos[c + d*x])/(b*Cos[c + d*x])^(1/2), x, 5, (A*ArcTanh[Sin[c + d*x]]*Sqrt[Cos[c + d*x]])/(2*d*Sqrt[b*Cos[c + d*x]]) + (A*Sin[c + d*x])/(2*d*Cos[c + d*x]^(3/2)*Sqrt[b*Cos[c + d*x]]) + (B*Sin[c + d*x])/(d*Sqrt[Cos[c + d*x]]*Sqrt[b*Cos[c + d*x]])}
{Cos[c + d*x]^(-7/2)*(A + B*Cos[c + d*x])/(b*Cos[c + d*x])^(1/2), x, 6, (B*ArcTanh[Sin[c + d*x]]*Sqrt[Cos[c + d*x]])/(2*d*Sqrt[b*Cos[c + d*x]]) + (A*Sin[c + d*x])/(3*d*Cos[c + d*x]^(5/2)*Sqrt[b*Cos[c + d*x]]) + (B*Sin[c + d*x])/(2*d*Cos[c + d*x]^(3/2)*Sqrt[b*Cos[c + d*x]]) + (2*A*Sin[c + d*x])/(3*d*Sqrt[Cos[c + d*x]]*Sqrt[b*Cos[c + d*x]])}


{Cos[c + d*x]^(7/2)*(A + B*Cos[c + d*x])/(b*Cos[c + d*x])^(3/2), x, 4, (A*x*Sqrt[Cos[c + d*x]])/(2*b*Sqrt[b*Cos[c + d*x]]) + (2*B*Sqrt[Cos[c + d*x]]*Sin[c + d*x])/(3*b*d*Sqrt[b*Cos[c + d*x]]) + (A*Cos[c + d*x]^(3/2)*Sin[c + d*x])/(2*b*d*Sqrt[b*Cos[c + d*x]]) + (B*Cos[c + d*x]^(5/2)*Sin[c + d*x])/(3*b*d*Sqrt[b*Cos[c + d*x]])}
{Cos[c + d*x]^(5/2)*(A + B*Cos[c + d*x])/(b*Cos[c + d*x])^(3/2), x, 3, (B*x*Sqrt[Cos[c + d*x]])/(2*b*Sqrt[b*Cos[c + d*x]]) + (A*Sqrt[Cos[c + d*x]]*Sin[c + d*x])/(b*d*Sqrt[b*Cos[c + d*x]]) + (B*Cos[c + d*x]^(3/2)*Sin[c + d*x])/(2*b*d*Sqrt[b*Cos[c + d*x]])}
{Cos[c + d*x]^(3/2)*(A + B*Cos[c + d*x])/(b*Cos[c + d*x])^(3/2), x, 3, (A*x*Sqrt[Cos[c + d*x]])/(b*Sqrt[b*Cos[c + d*x]]) + (B*Sqrt[Cos[c + d*x]]*Sin[c + d*x])/(b*d*Sqrt[b*Cos[c + d*x]])}
{Cos[c + d*x]^(1/2)*(A + B*Cos[c + d*x])/(b*Cos[c + d*x])^(3/2), x, 3, (B*x*Sqrt[Cos[c + d*x]])/(b*Sqrt[b*Cos[c + d*x]]) + (A*ArcTanh[Sin[c + d*x]]*Sqrt[Cos[c + d*x]])/(b*d*Sqrt[b*Cos[c + d*x]])}
{Cos[c + d*x]^(-1/2)*(A + B*Cos[c + d*x])/(b*Cos[c + d*x])^(3/2), x, 4, (B*ArcTanh[Sin[c + d*x]]*Sqrt[Cos[c + d*x]])/(b*d*Sqrt[b*Cos[c + d*x]]) + (A*Sin[c + d*x])/(b*d*Sqrt[Cos[c + d*x]]*Sqrt[b*Cos[c + d*x]])}
{Cos[c + d*x]^(-3/2)*(A + B*Cos[c + d*x])/(b*Cos[c + d*x])^(3/2), x, 5, (A*ArcTanh[Sin[c + d*x]]*Sqrt[Cos[c + d*x]])/(2*b*d*Sqrt[b*Cos[c + d*x]]) + (A*Sin[c + d*x])/(2*b*d*Cos[c + d*x]^(3/2)*Sqrt[b*Cos[c + d*x]]) + (B*Sin[c + d*x])/(b*d*Sqrt[Cos[c + d*x]]*Sqrt[b*Cos[c + d*x]])}
{Cos[c + d*x]^(-5/2)*(A + B*Cos[c + d*x])/(b*Cos[c + d*x])^(3/2), x, 6, (B*ArcTanh[Sin[c + d*x]]*Sqrt[Cos[c + d*x]])/(2*b*d*Sqrt[b*Cos[c + d*x]]) + (A*Sin[c + d*x])/(3*b*d*Cos[c + d*x]^(5/2)*Sqrt[b*Cos[c + d*x]]) + (B*Sin[c + d*x])/(2*b*d*Cos[c + d*x]^(3/2)*Sqrt[b*Cos[c + d*x]]) + (2*A*Sin[c + d*x])/(3*b*d*Sqrt[Cos[c + d*x]]*Sqrt[b*Cos[c + d*x]])}


{Cos[c + d*x]^(9/2)*(A + B*Cos[c + d*x])/(b*Cos[c + d*x])^(5/2), x, 4, (A*x*Sqrt[Cos[c + d*x]])/(2*b^2*Sqrt[b*Cos[c + d*x]]) + (2*B*Sqrt[Cos[c + d*x]]*Sin[c + d*x])/(3*b^2*d*Sqrt[b*Cos[c + d*x]]) + (A*Cos[c + d*x]^(3/2)*Sin[c + d*x])/(2*b^2*d*Sqrt[b*Cos[c + d*x]]) + (B*Cos[c + d*x]^(5/2)*Sin[c + d*x])/(3*b^2*d*Sqrt[b*Cos[c + d*x]])}
{Cos[c + d*x]^(7/2)*(A + B*Cos[c + d*x])/(b*Cos[c + d*x])^(5/2), x, 3, (B*x*Sqrt[Cos[c + d*x]])/(2*b^2*Sqrt[b*Cos[c + d*x]]) + (A*Sqrt[Cos[c + d*x]]*Sin[c + d*x])/(b^2*d*Sqrt[b*Cos[c + d*x]]) + (B*Cos[c + d*x]^(3/2)*Sin[c + d*x])/(2*b^2*d*Sqrt[b*Cos[c + d*x]])}
{Cos[c + d*x]^(5/2)*(A + B*Cos[c + d*x])/(b*Cos[c + d*x])^(5/2), x, 3, (A*x*Sqrt[Cos[c + d*x]])/(b^2*Sqrt[b*Cos[c + d*x]]) + (B*Sqrt[Cos[c + d*x]]*Sin[c + d*x])/(b^2*d*Sqrt[b*Cos[c + d*x]])}
{Cos[c + d*x]^(3/2)*(A + B*Cos[c + d*x])/(b*Cos[c + d*x])^(5/2), x, 3, (B*x*Sqrt[Cos[c + d*x]])/(b^2*Sqrt[b*Cos[c + d*x]]) + (A*ArcTanh[Sin[c + d*x]]*Sqrt[Cos[c + d*x]])/(b^2*d*Sqrt[b*Cos[c + d*x]])}
{Cos[c + d*x]^(1/2)*(A + B*Cos[c + d*x])/(b*Cos[c + d*x])^(5/2), x, 4, (B*ArcTanh[Sin[c + d*x]]*Sqrt[Cos[c + d*x]])/(b^2*d*Sqrt[b*Cos[c + d*x]]) + (A*Sin[c + d*x])/(b^2*d*Sqrt[Cos[c + d*x]]*Sqrt[b*Cos[c + d*x]])}
{Cos[c + d*x]^(-1/2)*(A + B*Cos[c + d*x])/(b*Cos[c + d*x])^(5/2), x, 5, (A*ArcTanh[Sin[c + d*x]]*Sqrt[Cos[c + d*x]])/(2*b^2*d*Sqrt[b*Cos[c + d*x]]) + (A*Sin[c + d*x])/(2*b^2*d*Cos[c + d*x]^(3/2)*Sqrt[b*Cos[c + d*x]]) + (B*Sin[c + d*x])/(b^2*d*Sqrt[Cos[c + d*x]]*Sqrt[b*Cos[c + d*x]])}
{Cos[c + d*x]^(-3/2)*(A + B*Cos[c + d*x])/(b*Cos[c + d*x])^(5/2), x, 6, (B*ArcTanh[Sin[c + d*x]]*Sqrt[Cos[c + d*x]])/(2*b^2*d*Sqrt[b*Cos[c + d*x]]) + (A*Sin[c + d*x])/(3*b^2*d*Cos[c + d*x]^(5/2)*Sqrt[b*Cos[c + d*x]]) + (B*Sin[c + d*x])/(2*b^2*d*Cos[c + d*x]^(3/2)*Sqrt[b*Cos[c + d*x]]) + (2*A*Sin[c + d*x])/(3*b^2*d*Sqrt[Cos[c + d*x]]*Sqrt[b*Cos[c + d*x]])}


(* ::Section:: *)
(*Cos[c+d x]^m (A+C Cos[c+d x]^2) (b Cos[c+d x])^(n/2)*)


(* ::Subsection::Closed:: *)
(*Integrands of the form Cos[c+d x]^m (A+C Cos[c+d x]^2) (b Cos[c+d x])^(n/2)*)


(* ::Subsubsection::Closed:: *)
(*n>0*)


{Cos[c + d*x]^2*Sqrt[b*Cos[c + d*x]]*(A + C*Cos[c + d*x]^2), x, 5, (2*b*(9*A + 7*C)*Sqrt[Cos[c + d*x]]*EllipticE[(1/2)*(c + d*x), 2])/(15*d*Sqrt[b*Cos[c + d*x]]) + (2*(9*A + 7*C)*(b*Cos[c + d*x])^(3/2)*Sin[c + d*x])/(45*b*d) + (2*C*(b*Cos[c + d*x])^(7/2)*Sin[c + d*x])/(9*b^3*d)}
{Cos[c + d*x]*Sqrt[b*Cos[c + d*x]]*(A + C*Cos[c + d*x]^2), x, 5, (2*b*(7*A + 5*C)*Sqrt[Cos[c + d*x]]*EllipticF[(c + d*x)/2, 2])/(21*d*Sqrt[b*Cos[c + d*x]]) + (2*(7*A + 5*C)*Sqrt[b*Cos[c + d*x]]*Sin[c + d*x])/(21*d) + (2*C*(b*Cos[c + d*x])^(5/2)*Sin[c + d*x])/(7*b^2*d)}
{Sqrt[b*Cos[c + d*x]]*(A + C*Cos[c + d*x]^2), x, 3, (2*b*(5*A + 3*C)*Sqrt[Cos[c + d*x]]*EllipticE[(c + d*x)/2, 2])/(5*d*Sqrt[b*Cos[c + d*x]]) + (2*C*(b*Cos[c + d*x])^(3/2)*Sin[c + d*x])/(5*b*d)}
{Sqrt[b*Cos[c + d*x]]*(A + C*Cos[c + d*x]^2)*Sec[c + d*x], x, 4, (2*b*(3*A + C)*Sqrt[Cos[c + d*x]]*EllipticF[(c + d*x)/2, 2])/(3*d*Sqrt[b*Cos[c + d*x]]) + (2*C*Sqrt[b*Cos[c + d*x]]*Sin[c + d*x])/(3*d)}
{Sqrt[b*Cos[c + d*x]]*(A + C*Cos[c + d*x]^2)*Sec[c + d*x]^2, x, 4, (-2*b*(A - C)*Sqrt[Cos[c + d*x]]*EllipticE[(c + d*x)/2, 2])/(d*Sqrt[b*Cos[c + d*x]]) + (2*A*b*Sin[c + d*x])/(d*Sqrt[b*Cos[c + d*x]])}
{Sqrt[b*Cos[c + d*x]]*(A + C*Cos[c + d*x]^2)*Sec[c + d*x]^3, x, 4, (2*b*(A + 3*C)*Sqrt[Cos[c + d*x]]*EllipticF[(c + d*x)/2, 2])/(3*d*Sqrt[b*Cos[c + d*x]]) + (2*A*b^2*Sin[c + d*x])/(3*d*(b*Cos[c + d*x])^(3/2))}
{Sqrt[b*Cos[c + d*x]]*(A + C*Cos[c + d*x]^2)*Sec[c + d*x]^4, x, 5, (-2*b*(3*A + 5*C)*Sqrt[Cos[c + d*x]]*EllipticE[(c + d*x)/2, 2])/(5*d*Sqrt[b*Cos[c + d*x]]) + (2*A*b^3*Sin[c + d*x])/(5*d*(b*Cos[c + d*x])^(5/2)) + (2*b*(3*A + 5*C)*Sin[c + d*x])/(5*d*Sqrt[b*Cos[c + d*x]])}
{Sqrt[b*Cos[c + d*x]]*(A + C*Cos[c + d*x]^2)*Sec[c + d*x]^5, x, 5, (2*b*(5*A + 7*C)*Sqrt[Cos[c + d*x]]*EllipticF[(c + d*x)/2, 2])/(21*d*Sqrt[b*Cos[c + d*x]]) + (2*A*b^4*Sin[c + d*x])/(7*d*(b*Cos[c + d*x])^(7/2)) + (2*b^2*(5*A + 7*C)*Sin[c + d*x])/(21*d*(b*Cos[c + d*x])^(3/2))}


{Cos[c + d*x]*(b*Cos[c + d*x])^(3/2)*(A + C*Cos[c + d*x]^2), x, 5, (2*b^2*(9*A + 7*C)*Sqrt[Cos[c + d*x]]*EllipticE[(c + d*x)/2, 2])/(15*d*Sqrt[b*Cos[c + d*x]]) + (2*(9*A + 7*C)*(b*Cos[c + d*x])^(3/2)*Sin[c + d*x])/(45*d) + (2*C*(b*Cos[c + d*x])^(7/2)*Sin[c + d*x])/(9*b^2*d)}
{(b*Cos[c + d*x])^(3/2)*(A + C*Cos[c + d*x]^2), x, 4, (2*b^2*(7*A + 5*C)*Sqrt[Cos[c + d*x]]*EllipticF[(c + d*x)/2, 2])/(21*d*Sqrt[b*Cos[c + d*x]]) + (2*b*(7*A + 5*C)*Sqrt[b*Cos[c + d*x]]*Sin[c + d*x])/(21*d) + (2*C*(b*Cos[c + d*x])^(5/2)*Sin[c + d*x])/(7*b*d)}
{(b*Cos[c + d*x])^(3/2)*(A + C*Cos[c + d*x]^2)*Sec[c + d*x], x, 4, (2*b^2*(5*A + 3*C)*Sqrt[Cos[c + d*x]]*EllipticE[(c + d*x)/2, 2])/(5*d*Sqrt[b*Cos[c + d*x]]) + (2*C*(b*Cos[c + d*x])^(3/2)*Sin[c + d*x])/(5*d)}
{(b*Cos[c + d*x])^(3/2)*(A + C*Cos[c + d*x]^2)*Sec[c + d*x]^2, x, 4, (2*b^2*(3*A + C)*Sqrt[Cos[c + d*x]]*EllipticF[(c + d*x)/2, 2])/(3*d*Sqrt[b*Cos[c + d*x]]) + (2*b*C*Sqrt[b*Cos[c + d*x]]*Sin[c + d*x])/(3*d)}
{(b*Cos[c + d*x])^(3/2)*(A + C*Cos[c + d*x]^2)*Sec[c + d*x]^3, x, 4, (-2*b^2*(A - C)*Sqrt[Cos[c + d*x]]*EllipticE[(c + d*x)/2, 2])/(d*Sqrt[b*Cos[c + d*x]]) + (2*A*b^2*Sin[c + d*x])/(d*Sqrt[b*Cos[c + d*x]])}
{(b*Cos[c + d*x])^(3/2)*(A + C*Cos[c + d*x]^2)*Sec[c + d*x]^4, x, 4, (2*b^2*(A + 3*C)*Sqrt[Cos[c + d*x]]*EllipticF[(c + d*x)/2, 2])/(3*d*Sqrt[b*Cos[c + d*x]]) + (2*A*b^3*Sin[c + d*x])/(3*d*(b*Cos[c + d*x])^(3/2))}
{(b*Cos[c + d*x])^(3/2)*(A + C*Cos[c + d*x]^2)*Sec[c + d*x]^5, x, 5, (-2*b^2*(3*A + 5*C)*Sqrt[Cos[c + d*x]]*EllipticE[(c + d*x)/2, 2])/(5*d*Sqrt[b*Cos[c + d*x]]) + (2*A*b^4*Sin[c + d*x])/(5*d*(b*Cos[c + d*x])^(5/2)) + (2*b^2*(3*A + 5*C)*Sin[c + d*x])/(5*d*Sqrt[b*Cos[c + d*x]])}
{(b*Cos[c + d*x])^(3/2)*(A + C*Cos[c + d*x]^2)*Sec[c + d*x]^6, x, 5, (2*b^2*(5*A + 7*C)*Sqrt[Cos[c + d*x]]*EllipticF[(c + d*x)/2, 2])/(21*d*Sqrt[b*Cos[c + d*x]]) + (2*A*b^5*Sin[c + d*x])/(7*d*(b*Cos[c + d*x])^(7/2)) + (2*b^3*(5*A + 7*C)*Sin[c + d*x])/(21*d*(b*Cos[c + d*x])^(3/2))}


{(b*Cos[c + d*x])^(5/2)*(A + C*Cos[c + d*x]^2), x, 4, (2*b^3*(9*A + 7*C)*Sqrt[Cos[c + d*x]]*EllipticE[(c + d*x)/2, 2])/(15*d*Sqrt[b*Cos[c + d*x]]) + (2*b*(9*A + 7*C)*(b*Cos[c + d*x])^(3/2)*Sin[c + d*x])/(45*d) + (2*C*(b*Cos[c + d*x])^(7/2)*Sin[c + d*x])/(9*b*d)}
{(b*Cos[c + d*x])^(5/2)*(A + C*Cos[c + d*x]^2)*Sec[c + d*x], x, 5, (2*b^3*(7*A + 5*C)*Sqrt[Cos[c + d*x]]*EllipticF[(c + d*x)/2, 2])/(21*d*Sqrt[b*Cos[c + d*x]]) + (2*b^2*(7*A + 5*C)*Sqrt[b*Cos[c + d*x]]*Sin[c + d*x])/(21*d) + (2*C*(b*Cos[c + d*x])^(5/2)*Sin[c + d*x])/(7*d)}
{(b*Cos[c + d*x])^(5/2)*(A + C*Cos[c + d*x]^2)*Sec[c + d*x]^2, x, 4, (2*b^3*(5*A + 3*C)*Sqrt[Cos[c + d*x]]*EllipticE[(c + d*x)/2, 2])/(5*d*Sqrt[b*Cos[c + d*x]]) + (2*b*C*(b*Cos[c + d*x])^(3/2)*Sin[c + d*x])/(5*d)}
{(b*Cos[c + d*x])^(5/2)*(A + C*Cos[c + d*x]^2)*Sec[c + d*x]^3, x, 4, (2*b^3*(3*A + C)*Sqrt[Cos[c + d*x]]*EllipticF[(c + d*x)/2, 2])/(3*d*Sqrt[b*Cos[c + d*x]]) + (2*b^2*C*Sqrt[b*Cos[c + d*x]]*Sin[c + d*x])/(3*d)}
{(b*Cos[c + d*x])^(5/2)*(A + C*Cos[c + d*x]^2)*Sec[c + d*x]^4, x, 4, (-2*b^3*(A - C)*Sqrt[Cos[c + d*x]]*EllipticE[(c + d*x)/2, 2])/(d*Sqrt[b*Cos[c + d*x]]) + (2*A*b^3*Sin[c + d*x])/(d*Sqrt[b*Cos[c + d*x]])}
{(b*Cos[c + d*x])^(5/2)*(A + C*Cos[c + d*x]^2)*Sec[c + d*x]^5, x, 4, (2*b^3*(A + 3*C)*Sqrt[Cos[c + d*x]]*EllipticF[(c + d*x)/2, 2])/(3*d*Sqrt[b*Cos[c + d*x]]) + (2*A*b^4*Sin[c + d*x])/(3*d*(b*Cos[c + d*x])^(3/2))}
{(b*Cos[c + d*x])^(5/2)*(A + C*Cos[c + d*x]^2)*Sec[c + d*x]^6, x, 5, (-2*b^3*(3*A + 5*C)*Sqrt[Cos[c + d*x]]*EllipticE[(c + d*x)/2, 2])/(5*d*Sqrt[b*Cos[c + d*x]]) + (2*A*b^5*Sin[c + d*x])/(5*d*(b*Cos[c + d*x])^(5/2)) + (2*b^3*(3*A + 5*C)*Sin[c + d*x])/(5*d*Sqrt[b*Cos[c + d*x]])}
{(b*Cos[c + d*x])^(5/2)*(A + C*Cos[c + d*x]^2)*Sec[c + d*x]^7, x, 5, (2*b^3*(5*A + 7*C)*Sqrt[Cos[c + d*x]]*EllipticF[(c + d*x)/2, 2])/(21*d*Sqrt[b*Cos[c + d*x]]) + (2*A*b^6*Sin[c + d*x])/(7*d*(b*Cos[c + d*x])^(7/2)) + (2*b^4*(5*A + 7*C)*Sin[c + d*x])/(21*d*(b*Cos[c + d*x])^(3/2))}


(* ::Subsubsection::Closed:: *)
(*n<0*)


{Cos[c + d*x]^4*(A + C*Cos[c + d*x]^2)/(b*Cos[c + d*x])^(1/2), x, 6, (10*(11*A + 9*C)*Sqrt[Cos[c + d*x]]*EllipticF[(1/2)*(c + d*x), 2])/(231*d*Sqrt[b*Cos[c + d*x]]) + (10*(11*A + 9*C)*Sqrt[b*Cos[c + d*x]]*Sin[c + d*x])/(231*b*d) + (2*(11*A + 9*C)*(b*Cos[c + d*x])^(5/2)*Sin[c + d*x])/(77*b^3*d) + (2*C*(b*Cos[c + d*x])^(9/2)*Sin[c + d*x])/(11*b^5*d)}
{Cos[c + d*x]^3*(A + C*Cos[c + d*x]^2)/(b*Cos[c + d*x])^(1/2), x, 5, (2*(9*A + 7*C)*Sqrt[Cos[c + d*x]]*EllipticE[(1/2)*(c + d*x), 2])/(15*d*Sqrt[b*Cos[c + d*x]]) + (2*(9*A + 7*C)*(b*Cos[c + d*x])^(3/2)*Sin[c + d*x])/(45*b^2*d) + (2*C*(b*Cos[c + d*x])^(7/2)*Sin[c + d*x])/(9*b^4*d)}
{Cos[c + d*x]^2*(A + C*Cos[c + d*x]^2)/(b*Cos[c + d*x])^(1/2), x, 5, (2*(7*A + 5*C)*Sqrt[Cos[c + d*x]]*EllipticF[(1/2)*(c + d*x), 2])/(21*d*Sqrt[b*Cos[c + d*x]]) + (2*(7*A + 5*C)*Sqrt[b*Cos[c + d*x]]*Sin[c + d*x])/(21*b*d) + (2*C*(b*Cos[c + d*x])^(5/2)*Sin[c + d*x])/(7*b^3*d)}
{Cos[c + d*x]^1*(A + C*Cos[c + d*x]^2)/(b*Cos[c + d*x])^(1/2), x, 4, (2*(5*A + 3*C)*Sqrt[Cos[c + d*x]]*EllipticE[(1/2)*(c + d*x), 2])/(5*d*Sqrt[b*Cos[c + d*x]]) + (2*C*(b*Cos[c + d*x])^(3/2)*Sin[c + d*x])/(5*b^2*d)}
{Cos[c + d*x]^0*(A + C*Cos[c + d*x]^2)/(b*Cos[c + d*x])^(1/2), x, 3, (2*(3*A + C)*Sqrt[Cos[c + d*x]]*EllipticF[(1/2)*(c + d*x), 2])/(3*d*Sqrt[b*Cos[c + d*x]]) + (2*C*Sqrt[b*Cos[c + d*x]]*Sin[c + d*x])/(3*b*d)}
{Sec[c + d*x]^1*(A + C*Cos[c + d*x]^2)/(b*Cos[c + d*x])^(1/2), x, 4, -((2*(A - C)*Sqrt[Cos[c + d*x]]*EllipticE[(1/2)*(c + d*x), 2])/(d*Sqrt[b*Cos[c + d*x]])) + (2*A*Sin[c + d*x])/(d*Sqrt[b*Cos[c + d*x]])}
{Sec[c + d*x]^2*(A + C*Cos[c + d*x]^2)/(b*Cos[c + d*x])^(1/2), x, 4, (2*(A + 3*C)*Sqrt[Cos[c + d*x]]*EllipticF[(1/2)*(c + d*x), 2])/(3*d*Sqrt[b*Cos[c + d*x]]) + (2*A*b*Sin[c + d*x])/(3*d*(b*Cos[c + d*x])^(3/2))}
{Sec[c + d*x]^3*(A + C*Cos[c + d*x]^2)/(b*Cos[c + d*x])^(1/2), x, 5, -((2*(3*A + 5*C)*Sqrt[Cos[c + d*x]]*EllipticE[(1/2)*(c + d*x), 2])/(5*d*Sqrt[b*Cos[c + d*x]])) + (2*A*b^2*Sin[c + d*x])/(5*d*(b*Cos[c + d*x])^(5/2)) + (2*(3*A + 5*C)*Sin[c + d*x])/(5*d*Sqrt[b*Cos[c + d*x]])}
{Sec[c + d*x]^4*(A + C*Cos[c + d*x]^2)/(b*Cos[c + d*x])^(1/2), x, 5, (2*(5*A + 7*C)*Sqrt[Cos[c + d*x]]*EllipticF[(1/2)*(c + d*x), 2])/(21*d*Sqrt[b*Cos[c + d*x]]) + (2*A*b^3*Sin[c + d*x])/(7*d*(b*Cos[c + d*x])^(7/2)) + (2*b*(5*A + 7*C)*Sin[c + d*x])/(21*d*(b*Cos[c + d*x])^(3/2))}
{Sec[c + d*x]^5*(A + C*Cos[c + d*x]^2)/(b*Cos[c + d*x])^(1/2), x, 6, -((2*(7*A + 9*C)*Sqrt[Cos[c + d*x]]*EllipticE[(1/2)*(c + d*x), 2])/(15*d*Sqrt[b*Cos[c + d*x]])) + (2*A*b^4*Sin[c + d*x])/(9*d*(b*Cos[c + d*x])^(9/2)) + (2*b^2*(7*A + 9*C)*Sin[c + d*x])/(45*d*(b*Cos[c + d*x])^(5/2)) + (2*(7*A + 9*C)*Sin[c + d*x])/(15*d*Sqrt[b*Cos[c + d*x]])}


{Cos[c + d*x]^4*(A + C*Cos[c + d*x]^2)/(b*Cos[c + d*x])^(3/2), x, 5, (2*(9*A + 7*C)*Sqrt[Cos[c + d*x]]*EllipticE[(c + d*x)/2, 2])/(15*b*d*Sqrt[b*Cos[c + d*x]]) + (2*(9*A + 7*C)*(b*Cos[c + d*x])^(3/2)*Sin[c + d*x])/(45*b^3*d) + (2*C*(b*Cos[c + d*x])^(7/2)*Sin[c + d*x])/(9*b^5*d)}
{Cos[c + d*x]^3*(A + C*Cos[c + d*x]^2)/(b*Cos[c + d*x])^(3/2), x, 5, (2*(7*A + 5*C)*Sqrt[Cos[c + d*x]]*EllipticF[(c + d*x)/2, 2])/(21*b*d*Sqrt[b*Cos[c + d*x]]) + (2*(7*A + 5*C)*Sqrt[b*Cos[c + d*x]]*Sin[c + d*x])/(21*b^2*d) + (2*C*(b*Cos[c + d*x])^(5/2)*Sin[c + d*x])/(7*b^4*d)}
{Cos[c + d*x]^2*(A + C*Cos[c + d*x]^2)/(b*Cos[c + d*x])^(3/2), x, 4, (2*(5*A + 3*C)*Sqrt[Cos[c + d*x]]*EllipticE[(c + d*x)/2, 2])/(5*b*d*Sqrt[b*Cos[c + d*x]]) + (2*C*(b*Cos[c + d*x])^(3/2)*Sin[c + d*x])/(5*b^3*d)}
{Cos[c + d*x]^1*(A + C*Cos[c + d*x]^2)/(b*Cos[c + d*x])^(3/2), x, 4, (2*(3*A + C)*Sqrt[Cos[c + d*x]]*EllipticF[(c + d*x)/2, 2])/(3*b*d*Sqrt[b*Cos[c + d*x]]) + (2*C*Sqrt[b*Cos[c + d*x]]*Sin[c + d*x])/(3*b^2*d)}
{Cos[c + d*x]^0*(A + C*Cos[c + d*x]^2)/(b*Cos[c + d*x])^(3/2), x, 3, (-2*(A - C)*Sqrt[Cos[c + d*x]]*EllipticE[(c + d*x)/2, 2])/(b*d*Sqrt[b*Cos[c + d*x]]) + (2*A*Sin[c + d*x])/(b*d*Sqrt[b*Cos[c + d*x]])}
{Sec[c + d*x]^1*(A + C*Cos[c + d*x]^2)/(b*Cos[c + d*x])^(3/2), x, 4, (2*(A + 3*C)*Sqrt[Cos[c + d*x]]*EllipticF[(c + d*x)/2, 2])/(3*b*d*Sqrt[b*Cos[c + d*x]]) + (2*A*Sin[c + d*x])/(3*d*(b*Cos[c + d*x])^(3/2))}
{Sec[c + d*x]^2*(A + C*Cos[c + d*x]^2)/(b*Cos[c + d*x])^(3/2), x, 5, (-2*(3*A + 5*C)*Sqrt[Cos[c + d*x]]*EllipticE[(c + d*x)/2, 2])/(5*b*d*Sqrt[b*Cos[c + d*x]]) + (2*A*b*Sin[c + d*x])/(5*d*(b*Cos[c + d*x])^(5/2)) + (2*(3*A + 5*C)*Sin[c + d*x])/(5*b*d*Sqrt[b*Cos[c + d*x]])}
{Sec[c + d*x]^3*(A + C*Cos[c + d*x]^2)/(b*Cos[c + d*x])^(3/2), x, 5, (2*(5*A + 7*C)*Sqrt[Cos[c + d*x]]*EllipticF[(c + d*x)/2, 2])/(21*b*d*Sqrt[b*Cos[c + d*x]]) + (2*A*b^2*Sin[c + d*x])/(7*d*(b*Cos[c + d*x])^(7/2)) + (2*(5*A + 7*C)*Sin[c + d*x])/(21*d*(b*Cos[c + d*x])^(3/2))}


{Cos[c + d*x]^5*(A + C*Cos[c + d*x]^2)/(b*Cos[c + d*x])^(5/2), x, 5, (2*(9*A + 7*C)*Sqrt[Cos[c + d*x]]*EllipticE[(c + d*x)/2, 2])/(15*b^2*d*Sqrt[b*Cos[c + d*x]]) + (2*(9*A + 7*C)*(b*Cos[c + d*x])^(3/2)*Sin[c + d*x])/(45*b^4*d) + (2*C*(b*Cos[c + d*x])^(7/2)*Sin[c + d*x])/(9*b^6*d)}
{Cos[c + d*x]^4*(A + C*Cos[c + d*x]^2)/(b*Cos[c + d*x])^(5/2), x, 5, (2*(7*A + 5*C)*Sqrt[Cos[c + d*x]]*EllipticF[(c + d*x)/2, 2])/(21*b^2*d*Sqrt[b*Cos[c + d*x]]) + (2*(7*A + 5*C)*Sqrt[b*Cos[c + d*x]]*Sin[c + d*x])/(21*b^3*d) + (2*C*(b*Cos[c + d*x])^(5/2)*Sin[c + d*x])/(7*b^5*d)}
{Cos[c + d*x]^3*(A + C*Cos[c + d*x]^2)/(b*Cos[c + d*x])^(5/2), x, 4, (2*(5*A + 3*C)*Sqrt[Cos[c + d*x]]*EllipticE[(c + d*x)/2, 2])/(5*b^2*d*Sqrt[b*Cos[c + d*x]]) + (2*C*(b*Cos[c + d*x])^(3/2)*Sin[c + d*x])/(5*b^4*d)}
{Cos[c + d*x]^2*(A + C*Cos[c + d*x]^2)/(b*Cos[c + d*x])^(5/2), x, 4, (2*(3*A + C)*Sqrt[Cos[c + d*x]]*EllipticF[(c + d*x)/2, 2])/(3*b^2*d*Sqrt[b*Cos[c + d*x]]) + (2*C*Sqrt[b*Cos[c + d*x]]*Sin[c + d*x])/(3*b^3*d)}
{Cos[c + d*x]^1*(A + C*Cos[c + d*x]^2)/(b*Cos[c + d*x])^(5/2), x, 4, (-2*(A - C)*Sqrt[Cos[c + d*x]]*EllipticE[(c + d*x)/2, 2])/(b^2*d*Sqrt[b*Cos[c + d*x]]) + (2*A*Sin[c + d*x])/(b^2*d*Sqrt[b*Cos[c + d*x]])}
{Cos[c + d*x]^0*(A + C*Cos[c + d*x]^2)/(b*Cos[c + d*x])^(5/2), x, 3, (2*(A + 3*C)*Sqrt[Cos[c + d*x]]*EllipticF[(c + d*x)/2, 2])/(3*b^2*d*Sqrt[b*Cos[c + d*x]]) + (2*A*Sin[c + d*x])/(3*b*d*(b*Cos[c + d*x])^(3/2))}
{Sec[c + d*x]^1*(A + C*Cos[c + d*x]^2)/(b*Cos[c + d*x])^(5/2), x, 5, (-2*(3*A + 5*C)*Sqrt[Cos[c + d*x]]*EllipticE[(c + d*x)/2, 2])/(5*b^2*d*Sqrt[b*Cos[c + d*x]]) + (2*A*Sin[c + d*x])/(5*d*(b*Cos[c + d*x])^(5/2)) + (2*(3*A + 5*C)*Sin[c + d*x])/(5*b^2*d*Sqrt[b*Cos[c + d*x]])}
{Sec[c + d*x]^2*(A + C*Cos[c + d*x]^2)/(b*Cos[c + d*x])^(5/2), x, 5, (2*(5*A + 7*C)*Sqrt[Cos[c + d*x]]*EllipticF[(c + d*x)/2, 2])/(21*b^2*d*Sqrt[b*Cos[c + d*x]]) + (2*A*b*Sin[c + d*x])/(7*d*(b*Cos[c + d*x])^(7/2)) + (2*(5*A + 7*C)*Sin[c + d*x])/(21*b*d*(b*Cos[c + d*x])^(3/2))}


{Cos[c + d*x]^0*(A + C*Cos[c + d*x]^2)/(b*Cos[c + d*x])^(7/2), x, 4, (-2*(3*A + 5*C)*Sqrt[Cos[c + d*x]]*EllipticE[(c + d*x)/2, 2])/(5*b^3*d*Sqrt[b*Cos[c + d*x]]) + (2*A*Sin[c + d*x])/(5*b*d*(b*Cos[c + d*x])^(5/2)) + (2*(3*A + 5*C)*Sin[c + d*x])/(5*b^3*d*Sqrt[b*Cos[c + d*x]])}


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


(* ::Section:: *)
(*Cos[c+d x]^m (A+B Cos[c+d x]+C Cos[c+d x]^2) (b Cos[c+d x])^(n/2)*)


(* ::Subsection::Closed:: *)
(*Integrands of the form Cos[c+d x]^m (A+B Cos[c+d x]+C Cos[c+d x]^2) (b Cos[c+d x])^(n/2)*)


(* ::Subsubsection::Closed:: *)
(*n>0*)


{Cos[c + d*x]^2*Sqrt[b*Cos[c + d*x]]*(A + B*Cos[c + d*x] + C*Cos[c + d*x]^2), x, 10, (2*b*(9*A + 7*C)*Sqrt[Cos[c + d*x]]*EllipticE[(1/2)*(c + d*x), 2])/(15*d*Sqrt[b*Cos[c + d*x]]) + (10*b*B*Sqrt[Cos[c + d*x]]*EllipticF[(1/2)*(c + d*x), 2])/(21*d*Sqrt[b*Cos[c + d*x]]) + (10*B*Sqrt[b*Cos[c + d*x]]*Sin[c + d*x])/(21*d) + (2*(9*A + 7*C)*(b*Cos[c + d*x])^(3/2)*Sin[c + d*x])/(45*b*d) + (2*B*(b*Cos[c + d*x])^(5/2)*Sin[c + d*x])/(7*b^2*d) + (2*C*(b*Cos[c + d*x])^(7/2)*Sin[c + d*x])/(9*b^3*d)}
{Cos[c + d*x]*Sqrt[b*Cos[c + d*x]]*(A + B*Cos[c + d*x] + C*Cos[c + d*x]^2), x, 9, (6*b*B*Sqrt[Cos[c + d*x]]*EllipticE[(c + d*x)/2, 2])/(5*d*Sqrt[b*Cos[c + d*x]]) + (2*b*(7*A + 5*C)*Sqrt[Cos[c + d*x]]*EllipticF[(c + d*x)/2, 2])/(21*d*Sqrt[b*Cos[c + d*x]]) + (2*(7*A + 5*C)*Sqrt[b*Cos[c + d*x]]*Sin[c + d*x])/(21*d) + (2*B*(b*Cos[c + d*x])^(3/2)*Sin[c + d*x])/(5*b*d) + (2*C*(b*Cos[c + d*x])^(5/2)*Sin[c + d*x])/(7*b^2*d)}
{Sqrt[b*Cos[c + d*x]]*(A + B*Cos[c + d*x] + C*Cos[c + d*x]^2), x, 7, (2*b*(5*A + 3*C)*Sqrt[Cos[c + d*x]]*EllipticE[(c + d*x)/2, 2])/(5*d*Sqrt[b*Cos[c + d*x]]) + (2*b*B*Sqrt[Cos[c + d*x]]*EllipticF[(c + d*x)/2, 2])/(3*d*Sqrt[b*Cos[c + d*x]]) + (2*B*Sqrt[b*Cos[c + d*x]]*Sin[c + d*x])/(3*d) + (2*C*(b*Cos[c + d*x])^(3/2)*Sin[c + d*x])/(5*b*d)}
{Sqrt[b*Cos[c + d*x]]*(A + B*Cos[c + d*x] + C*Cos[c + d*x]^2)*Sec[c + d*x], x, 7, (2*b*B*Sqrt[Cos[c + d*x]]*EllipticE[(c + d*x)/2, 2])/(d*Sqrt[b*Cos[c + d*x]]) + (2*b*(3*A + C)*Sqrt[Cos[c + d*x]]*EllipticF[(c + d*x)/2, 2])/(3*d*Sqrt[b*Cos[c + d*x]]) + (2*C*Sqrt[b*Cos[c + d*x]]*Sin[c + d*x])/(3*d)}
{Sqrt[b*Cos[c + d*x]]*(A + B*Cos[c + d*x] + C*Cos[c + d*x]^2)*Sec[c + d*x]^2, x, 7, (-2*b*(A - C)*Sqrt[Cos[c + d*x]]*EllipticE[(c + d*x)/2, 2])/(d*Sqrt[b*Cos[c + d*x]]) + (2*b*B*Sqrt[Cos[c + d*x]]*EllipticF[(c + d*x)/2, 2])/(d*Sqrt[b*Cos[c + d*x]]) + (2*A*b*Sin[c + d*x])/(d*Sqrt[b*Cos[c + d*x]])}
{Sqrt[b*Cos[c + d*x]]*(A + B*Cos[c + d*x] + C*Cos[c + d*x]^2)*Sec[c + d*x]^3, x, 8, (-2*b*B*Sqrt[Cos[c + d*x]]*EllipticE[(c + d*x)/2, 2])/(d*Sqrt[b*Cos[c + d*x]]) + (2*b*(A + 3*C)*Sqrt[Cos[c + d*x]]*EllipticF[(c + d*x)/2, 2])/(3*d*Sqrt[b*Cos[c + d*x]]) + (2*A*b^2*Sin[c + d*x])/(3*d*(b*Cos[c + d*x])^(3/2)) + (2*b*B*Sin[c + d*x])/(d*Sqrt[b*Cos[c + d*x]])}
{Sqrt[b*Cos[c + d*x]]*(A + B*Cos[c + d*x] + C*Cos[c + d*x]^2)*Sec[c + d*x]^4, x, 9, (-2*b*(3*A + 5*C)*Sqrt[Cos[c + d*x]]*EllipticE[(c + d*x)/2, 2])/(5*d*Sqrt[b*Cos[c + d*x]]) + (2*b*B*Sqrt[Cos[c + d*x]]*EllipticF[(c + d*x)/2, 2])/(3*d*Sqrt[b*Cos[c + d*x]]) + (2*A*b^3*Sin[c + d*x])/(5*d*(b*Cos[c + d*x])^(5/2)) + (2*b^2*B*Sin[c + d*x])/(3*d*(b*Cos[c + d*x])^(3/2)) + (2*b*(3*A + 5*C)*Sin[c + d*x])/(5*d*Sqrt[b*Cos[c + d*x]])}
{Sqrt[b*Cos[c + d*x]]*(A + B*Cos[c + d*x] + C*Cos[c + d*x]^2)*Sec[c + d*x]^5, x, 10, -((6*b*B*Sqrt[Cos[c + d*x]]*EllipticE[(1/2)*(c + d*x), 2])/(5*d*Sqrt[b*Cos[c + d*x]])) + (2*b*(5*A + 7*C)*Sqrt[Cos[c + d*x]]*EllipticF[(1/2)*(c + d*x), 2])/(21*d*Sqrt[b*Cos[c + d*x]]) + (2*A*b^4*Sin[c + d*x])/(7*d*(b*Cos[c + d*x])^(7/2)) + (2*b^3*B*Sin[c + d*x])/(5*d*(b*Cos[c + d*x])^(5/2)) + (2*b^2*(5*A + 7*C)*Sin[c + d*x])/(21*d*(b*Cos[c + d*x])^(3/2)) + (6*b*B*Sin[c + d*x])/(5*d*Sqrt[b*Cos[c + d*x]])}


{Cos[c + d*x]*(b*Cos[c + d*x])^(3/2)*(A + B*Cos[c + d*x] + C*Cos[c + d*x]^2), x, 10, (2*b^2*(9*A + 7*C)*Sqrt[Cos[c + d*x]]*EllipticE[(c + d*x)/2, 2])/(15*d*Sqrt[b*Cos[c + d*x]]) + (10*b^2*B*Sqrt[Cos[c + d*x]]*EllipticF[(c + d*x)/2, 2])/(21*d*Sqrt[b*Cos[c + d*x]]) + (10*b*B*Sqrt[b*Cos[c + d*x]]*Sin[c + d*x])/(21*d) + (2*(9*A + 7*C)*(b*Cos[c + d*x])^(3/2)*Sin[c + d*x])/(45*d) + (2*B*(b*Cos[c + d*x])^(5/2)*Sin[c + d*x])/(7*b*d) + (2*C*(b*Cos[c + d*x])^(7/2)*Sin[c + d*x])/(9*b^2*d)}
{(b*Cos[c + d*x])^(3/2)*(A + B*Cos[c + d*x] + C*Cos[c + d*x]^2), x, 8, (6*b^2*B*Sqrt[Cos[c + d*x]]*EllipticE[(c + d*x)/2, 2])/(5*d*Sqrt[b*Cos[c + d*x]]) + (2*b^2*(7*A + 5*C)*Sqrt[Cos[c + d*x]]*EllipticF[(c + d*x)/2, 2])/(21*d*Sqrt[b*Cos[c + d*x]]) + (2*b*(7*A + 5*C)*Sqrt[b*Cos[c + d*x]]*Sin[c + d*x])/(21*d) + (2*B*(b*Cos[c + d*x])^(3/2)*Sin[c + d*x])/(5*d) + (2*C*(b*Cos[c + d*x])^(5/2)*Sin[c + d*x])/(7*b*d)}
{(b*Cos[c + d*x])^(3/2)*(A + B*Cos[c + d*x] + C*Cos[c + d*x]^2)*Sec[c + d*x], x, 8, (2*b^2*(5*A + 3*C)*Sqrt[Cos[c + d*x]]*EllipticE[(c + d*x)/2, 2])/(5*d*Sqrt[b*Cos[c + d*x]]) + (2*b^2*B*Sqrt[Cos[c + d*x]]*EllipticF[(c + d*x)/2, 2])/(3*d*Sqrt[b*Cos[c + d*x]]) + (2*b*B*Sqrt[b*Cos[c + d*x]]*Sin[c + d*x])/(3*d) + (2*C*(b*Cos[c + d*x])^(3/2)*Sin[c + d*x])/(5*d)}
{(b*Cos[c + d*x])^(3/2)*(A + B*Cos[c + d*x] + C*Cos[c + d*x]^2)*Sec[c + d*x]^2, x, 7, (2*b^2*B*Sqrt[Cos[c + d*x]]*EllipticE[(c + d*x)/2, 2])/(d*Sqrt[b*Cos[c + d*x]]) + (2*b^2*(3*A + C)*Sqrt[Cos[c + d*x]]*EllipticF[(c + d*x)/2, 2])/(3*d*Sqrt[b*Cos[c + d*x]]) + (2*b*C*Sqrt[b*Cos[c + d*x]]*Sin[c + d*x])/(3*d)}
{(b*Cos[c + d*x])^(3/2)*(A + B*Cos[c + d*x] + C*Cos[c + d*x]^2)*Sec[c + d*x]^3, x, 7, (-2*b^2*(A - C)*Sqrt[Cos[c + d*x]]*EllipticE[(c + d*x)/2, 2])/(d*Sqrt[b*Cos[c + d*x]]) + (2*b^2*B*Sqrt[Cos[c + d*x]]*EllipticF[(c + d*x)/2, 2])/(d*Sqrt[b*Cos[c + d*x]]) + (2*A*b^2*Sin[c + d*x])/(d*Sqrt[b*Cos[c + d*x]])}
{(b*Cos[c + d*x])^(3/2)*(A + B*Cos[c + d*x] + C*Cos[c + d*x]^2)*Sec[c + d*x]^4, x, 8, (-2*b^2*B*Sqrt[Cos[c + d*x]]*EllipticE[(c + d*x)/2, 2])/(d*Sqrt[b*Cos[c + d*x]]) + (2*b^2*(A + 3*C)*Sqrt[Cos[c + d*x]]*EllipticF[(c + d*x)/2, 2])/(3*d*Sqrt[b*Cos[c + d*x]]) + (2*A*b^3*Sin[c + d*x])/(3*d*(b*Cos[c + d*x])^(3/2)) + (2*b^2*B*Sin[c + d*x])/(d*Sqrt[b*Cos[c + d*x]])}
{(b*Cos[c + d*x])^(3/2)*(A + B*Cos[c + d*x] + C*Cos[c + d*x]^2)*Sec[c + d*x]^5, x, 9, (-2*b^2*(3*A + 5*C)*Sqrt[Cos[c + d*x]]*EllipticE[(c + d*x)/2, 2])/(5*d*Sqrt[b*Cos[c + d*x]]) + (2*b^2*B*Sqrt[Cos[c + d*x]]*EllipticF[(c + d*x)/2, 2])/(3*d*Sqrt[b*Cos[c + d*x]]) + (2*A*b^4*Sin[c + d*x])/(5*d*(b*Cos[c + d*x])^(5/2)) + (2*b^3*B*Sin[c + d*x])/(3*d*(b*Cos[c + d*x])^(3/2)) + (2*b^2*(3*A + 5*C)*Sin[c + d*x])/(5*d*Sqrt[b*Cos[c + d*x]])}
{(b*Cos[c + d*x])^(3/2)*(A + B*Cos[c + d*x] + C*Cos[c + d*x]^2)*Sec[c + d*x]^6, x, 10, -((6*b^2*B*Sqrt[Cos[c + d*x]]*EllipticE[(1/2)*(c + d*x), 2])/(5*d*Sqrt[b*Cos[c + d*x]])) + (2*b^2*(5*A + 7*C)*Sqrt[Cos[c + d*x]]*EllipticF[(1/2)*(c + d*x), 2])/(21*d*Sqrt[b*Cos[c + d*x]]) + (2*A*b^5*Sin[c + d*x])/(7*d*(b*Cos[c + d*x])^(7/2)) + (2*b^4*B*Sin[c + d*x])/(5*d*(b*Cos[c + d*x])^(5/2)) + (2*b^3*(5*A + 7*C)*Sin[c + d*x])/(21*d*(b*Cos[c + d*x])^(3/2)) + (6*b^2*B*Sin[c + d*x])/(5*d*Sqrt[b*Cos[c + d*x]])}


{(b*Cos[c + d*x])^(5/2)*(A + B*Cos[c + d*x] + C*Cos[c + d*x]^2), x, 9, (2*b^3*(9*A + 7*C)*Sqrt[Cos[c + d*x]]*EllipticE[(c + d*x)/2, 2])/(15*d*Sqrt[b*Cos[c + d*x]]) + (10*b^3*B*Sqrt[Cos[c + d*x]]*EllipticF[(c + d*x)/2, 2])/(21*d*Sqrt[b*Cos[c + d*x]]) + (10*b^2*B*Sqrt[b*Cos[c + d*x]]*Sin[c + d*x])/(21*d) + (2*b*(9*A + 7*C)*(b*Cos[c + d*x])^(3/2)*Sin[c + d*x])/(45*d) + (2*B*(b*Cos[c + d*x])^(5/2)*Sin[c + d*x])/(7*d) + (2*C*(b*Cos[c + d*x])^(7/2)*Sin[c + d*x])/(9*b*d)}
{(b*Cos[c + d*x])^(5/2)*(A + B*Cos[c + d*x] + C*Cos[c + d*x]^2)*Sec[c + d*x], x, 9, (6*b^3*B*Sqrt[Cos[c + d*x]]*EllipticE[(c + d*x)/2, 2])/(5*d*Sqrt[b*Cos[c + d*x]]) + (2*b^3*(7*A + 5*C)*Sqrt[Cos[c + d*x]]*EllipticF[(c + d*x)/2, 2])/(21*d*Sqrt[b*Cos[c + d*x]]) + (2*b^2*(7*A + 5*C)*Sqrt[b*Cos[c + d*x]]*Sin[c + d*x])/(21*d) + (2*b*B*(b*Cos[c + d*x])^(3/2)*Sin[c + d*x])/(5*d) + (2*C*(b*Cos[c + d*x])^(5/2)*Sin[c + d*x])/(7*d)}
{(b*Cos[c + d*x])^(5/2)*(A + B*Cos[c + d*x] + C*Cos[c + d*x]^2)*Sec[c + d*x]^2, x, 8, (2*b^3*(5*A + 3*C)*Sqrt[Cos[c + d*x]]*EllipticE[(c + d*x)/2, 2])/(5*d*Sqrt[b*Cos[c + d*x]]) + (2*b^3*B*Sqrt[Cos[c + d*x]]*EllipticF[(c + d*x)/2, 2])/(3*d*Sqrt[b*Cos[c + d*x]]) + (2*b^2*B*Sqrt[b*Cos[c + d*x]]*Sin[c + d*x])/(3*d) + (2*b*C*(b*Cos[c + d*x])^(3/2)*Sin[c + d*x])/(5*d)}
{(b*Cos[c + d*x])^(5/2)*(A + B*Cos[c + d*x] + C*Cos[c + d*x]^2)*Sec[c + d*x]^3, x, 7, (2*b^3*B*Sqrt[Cos[c + d*x]]*EllipticE[(c + d*x)/2, 2])/(d*Sqrt[b*Cos[c + d*x]]) + (2*b^3*(3*A + C)*Sqrt[Cos[c + d*x]]*EllipticF[(c + d*x)/2, 2])/(3*d*Sqrt[b*Cos[c + d*x]]) + (2*b^2*C*Sqrt[b*Cos[c + d*x]]*Sin[c + d*x])/(3*d)}
{(b*Cos[c + d*x])^(5/2)*(A + B*Cos[c + d*x] + C*Cos[c + d*x]^2)*Sec[c + d*x]^4, x, 7, (-2*b^3*(A - C)*Sqrt[Cos[c + d*x]]*EllipticE[(c + d*x)/2, 2])/(d*Sqrt[b*Cos[c + d*x]]) + (2*b^3*B*Sqrt[Cos[c + d*x]]*EllipticF[(c + d*x)/2, 2])/(d*Sqrt[b*Cos[c + d*x]]) + (2*A*b^3*Sin[c + d*x])/(d*Sqrt[b*Cos[c + d*x]])}
{(b*Cos[c + d*x])^(5/2)*(A + B*Cos[c + d*x] + C*Cos[c + d*x]^2)*Sec[c + d*x]^5, x, 8, (-2*b^3*B*Sqrt[Cos[c + d*x]]*EllipticE[(c + d*x)/2, 2])/(d*Sqrt[b*Cos[c + d*x]]) + (2*b^3*(A + 3*C)*Sqrt[Cos[c + d*x]]*EllipticF[(c + d*x)/2, 2])/(3*d*Sqrt[b*Cos[c + d*x]]) + (2*A*b^4*Sin[c + d*x])/(3*d*(b*Cos[c + d*x])^(3/2)) + (2*b^3*B*Sin[c + d*x])/(d*Sqrt[b*Cos[c + d*x]])}
{(b*Cos[c + d*x])^(5/2)*(A + B*Cos[c + d*x] + C*Cos[c + d*x]^2)*Sec[c + d*x]^6, x, 9, (-2*b^3*(3*A + 5*C)*Sqrt[Cos[c + d*x]]*EllipticE[(c + d*x)/2, 2])/(5*d*Sqrt[b*Cos[c + d*x]]) + (2*b^3*B*Sqrt[Cos[c + d*x]]*EllipticF[(c + d*x)/2, 2])/(3*d*Sqrt[b*Cos[c + d*x]]) + (2*A*b^5*Sin[c + d*x])/(5*d*(b*Cos[c + d*x])^(5/2)) + (2*b^4*B*Sin[c + d*x])/(3*d*(b*Cos[c + d*x])^(3/2)) + (2*b^3*(3*A + 5*C)*Sin[c + d*x])/(5*d*Sqrt[b*Cos[c + d*x]])}
{(b*Cos[c + d*x])^(5/2)*(A + B*Cos[c + d*x] + C*Cos[c + d*x]^2)*Sec[c + d*x]^7, x, 10, -((6*b^3*B*Sqrt[Cos[c + d*x]]*EllipticE[(1/2)*(c + d*x), 2])/(5*d*Sqrt[b*Cos[c + d*x]])) + (2*b^3*(5*A + 7*C)*Sqrt[Cos[c + d*x]]*EllipticF[(1/2)*(c + d*x), 2])/(21*d*Sqrt[b*Cos[c + d*x]]) + (2*A*b^6*Sin[c + d*x])/(7*d*(b*Cos[c + d*x])^(7/2)) + (2*b^5*B*Sin[c + d*x])/(5*d*(b*Cos[c + d*x])^(5/2)) + (2*b^4*(5*A + 7*C)*Sin[c + d*x])/(21*d*(b*Cos[c + d*x])^(3/2)) + (6*b^3*B*Sin[c + d*x])/(5*d*Sqrt[b*Cos[c + d*x]])}


(* ::Subsubsection::Closed:: *)
(*n<0*)


{(Cos[c + d*x]^3*(A + B*Cos[c + d*x] + C*Cos[c + d*x]^2))/Sqrt[b*Cos[c + d*x]], x, 10, (2*(9*A + 7*C)*Sqrt[Cos[c + d*x]]*EllipticE[(c + d*x)/2, 2])/(15*d*Sqrt[b*Cos[c + d*x]]) + (10*B*Sqrt[Cos[c + d*x]]*EllipticF[(c + d*x)/2, 2])/(21*d*Sqrt[b*Cos[c + d*x]]) + (10*B*Sqrt[b*Cos[c + d*x]]*Sin[c + d*x])/(21*b*d) + (2*(9*A + 7*C)*(b*Cos[c + d*x])^(3/2)*Sin[c + d*x])/(45*b^2*d) + (2*B*(b*Cos[c + d*x])^(5/2)*Sin[c + d*x])/(7*b^3*d) + (2*C*(b*Cos[c + d*x])^(7/2)*Sin[c + d*x])/(9*b^4*d)}
{(Cos[c + d*x]^2*(A + B*Cos[c + d*x] + C*Cos[c + d*x]^2))/Sqrt[b*Cos[c + d*x]], x, 9, (6*B*Sqrt[Cos[c + d*x]]*EllipticE[(c + d*x)/2, 2])/(5*d*Sqrt[b*Cos[c + d*x]]) + (2*(7*A + 5*C)*Sqrt[Cos[c + d*x]]*EllipticF[(c + d*x)/2, 2])/(21*d*Sqrt[b*Cos[c + d*x]]) + (2*(7*A + 5*C)*Sqrt[b*Cos[c + d*x]]*Sin[c + d*x])/(21*b*d) + (2*B*(b*Cos[c + d*x])^(3/2)*Sin[c + d*x])/(5*b^2*d) + (2*C*(b*Cos[c + d*x])^(5/2)*Sin[c + d*x])/(7*b^3*d)}
{(Cos[c + d*x]*(A + B*Cos[c + d*x] + C*Cos[c + d*x]^2))/Sqrt[b*Cos[c + d*x]], x, 8, (2*(5*A + 3*C)*Sqrt[Cos[c + d*x]]*EllipticE[(c + d*x)/2, 2])/(5*d*Sqrt[b*Cos[c + d*x]]) + (2*B*Sqrt[Cos[c + d*x]]*EllipticF[(c + d*x)/2, 2])/(3*d*Sqrt[b*Cos[c + d*x]]) + (2*B*Sqrt[b*Cos[c + d*x]]*Sin[c + d*x])/(3*b*d) + (2*C*(b*Cos[c + d*x])^(3/2)*Sin[c + d*x])/(5*b^2*d)}
{(A + B*Cos[c + d*x] + C*Cos[c + d*x]^2)/Sqrt[b*Cos[c + d*x]], x, 6, (2*B*Sqrt[Cos[c + d*x]]*EllipticE[(c + d*x)/2, 2])/(d*Sqrt[b*Cos[c + d*x]]) + (2*(3*A + C)*Sqrt[Cos[c + d*x]]*EllipticF[(c + d*x)/2, 2])/(3*d*Sqrt[b*Cos[c + d*x]]) + (2*C*Sqrt[b*Cos[c + d*x]]*Sin[c + d*x])/(3*b*d)}
{((A + B*Cos[c + d*x] + C*Cos[c + d*x]^2)*Sec[c + d*x])/Sqrt[b*Cos[c + d*x]], x, 7, -((2*(A - C)*Sqrt[Cos[c + d*x]]*EllipticE[(1/2)*(c + d*x), 2])/(d*Sqrt[b*Cos[c + d*x]])) + (2*B*Sqrt[Cos[c + d*x]]*EllipticF[(1/2)*(c + d*x), 2])/(d*Sqrt[b*Cos[c + d*x]]) + (2*A*Sin[c + d*x])/(d*Sqrt[b*Cos[c + d*x]])}
{((A + B*Cos[c + d*x] + C*Cos[c + d*x]^2)*Sec[c + d*x]^2)/Sqrt[b*Cos[c + d*x]], x, 8, (-2*B*Sqrt[Cos[c + d*x]]*EllipticE[(c + d*x)/2, 2])/(d*Sqrt[b*Cos[c + d*x]]) + (2*(A + 3*C)*Sqrt[Cos[c + d*x]]*EllipticF[(c + d*x)/2, 2])/(3*d*Sqrt[b*Cos[c + d*x]]) + (2*A*b*Sin[c + d*x])/(3*d*(b*Cos[c + d*x])^(3/2)) + (2*B*Sin[c + d*x])/(d*Sqrt[b*Cos[c + d*x]])}
{((A + B*Cos[c + d*x] + C*Cos[c + d*x]^2)*Sec[c + d*x]^3)/Sqrt[b*Cos[c + d*x]], x, 9, (-2*(3*A + 5*C)*Sqrt[Cos[c + d*x]]*EllipticE[(c + d*x)/2, 2])/(5*d*Sqrt[b*Cos[c + d*x]]) + (2*B*Sqrt[Cos[c + d*x]]*EllipticF[(c + d*x)/2, 2])/(3*d*Sqrt[b*Cos[c + d*x]]) + (2*A*b^2*Sin[c + d*x])/(5*d*(b*Cos[c + d*x])^(5/2)) + (2*b*B*Sin[c + d*x])/(3*d*(b*Cos[c + d*x])^(3/2)) + (2*(3*A + 5*C)*Sin[c + d*x])/(5*d*Sqrt[b*Cos[c + d*x]])}
{((A + B*Cos[c + d*x] + C*Cos[c + d*x]^2)*Sec[c + d*x]^4)/Sqrt[b*Cos[c + d*x]], x, 10, -((6*B*Sqrt[Cos[c + d*x]]*EllipticE[(1/2)*(c + d*x), 2])/(5*d*Sqrt[b*Cos[c + d*x]])) + (2*(5*A + 7*C)*Sqrt[Cos[c + d*x]]*EllipticF[(1/2)*(c + d*x), 2])/(21*d*Sqrt[b*Cos[c + d*x]]) + (2*A*b^3*Sin[c + d*x])/(7*d*(b*Cos[c + d*x])^(7/2)) + (2*b^2*B*Sin[c + d*x])/(5*d*(b*Cos[c + d*x])^(5/2)) + (2*b*(5*A + 7*C)*Sin[c + d*x])/(21*d*(b*Cos[c + d*x])^(3/2)) + (6*B*Sin[c + d*x])/(5*d*Sqrt[b*Cos[c + d*x]])}


{(Cos[c + d*x]^4*(A + B*Cos[c + d*x] + C*Cos[c + d*x]^2))/(b*Cos[c + d*x])^(3/2), x, 10, (2*(9*A + 7*C)*Sqrt[Cos[c + d*x]]*EllipticE[(c + d*x)/2, 2])/(15*b*d*Sqrt[b*Cos[c + d*x]]) + (10*B*Sqrt[Cos[c + d*x]]*EllipticF[(c + d*x)/2, 2])/(21*b*d*Sqrt[b*Cos[c + d*x]]) + (10*B*Sqrt[b*Cos[c + d*x]]*Sin[c + d*x])/(21*b^2*d) + (2*(9*A + 7*C)*(b*Cos[c + d*x])^(3/2)*Sin[c + d*x])/(45*b^3*d) + (2*B*(b*Cos[c + d*x])^(5/2)*Sin[c + d*x])/(7*b^4*d) + (2*C*(b*Cos[c + d*x])^(7/2)*Sin[c + d*x])/(9*b^5*d)}
{(Cos[c + d*x]^3*(A + B*Cos[c + d*x] + C*Cos[c + d*x]^2))/(b*Cos[c + d*x])^(3/2), x, 9, (6*B*Sqrt[Cos[c + d*x]]*EllipticE[(c + d*x)/2, 2])/(5*b*d*Sqrt[b*Cos[c + d*x]]) + (2*(7*A + 5*C)*Sqrt[Cos[c + d*x]]*EllipticF[(c + d*x)/2, 2])/(21*b*d*Sqrt[b*Cos[c + d*x]]) + (2*(7*A + 5*C)*Sqrt[b*Cos[c + d*x]]*Sin[c + d*x])/(21*b^2*d) + (2*B*(b*Cos[c + d*x])^(3/2)*Sin[c + d*x])/(5*b^3*d) + (2*C*(b*Cos[c + d*x])^(5/2)*Sin[c + d*x])/(7*b^4*d)}
{(Cos[c + d*x]^2*(A + B*Cos[c + d*x] + C*Cos[c + d*x]^2))/(b*Cos[c + d*x])^(3/2), x, 8, (2*(5*A + 3*C)*Sqrt[Cos[c + d*x]]*EllipticE[(c + d*x)/2, 2])/(5*b*d*Sqrt[b*Cos[c + d*x]]) + (2*B*Sqrt[Cos[c + d*x]]*EllipticF[(c + d*x)/2, 2])/(3*b*d*Sqrt[b*Cos[c + d*x]]) + (2*B*Sqrt[b*Cos[c + d*x]]*Sin[c + d*x])/(3*b^2*d) + (2*C*(b*Cos[c + d*x])^(3/2)*Sin[c + d*x])/(5*b^3*d)}
{(Cos[c + d*x]*(A + B*Cos[c + d*x] + C*Cos[c + d*x]^2))/(b*Cos[c + d*x])^(3/2), x, 7, (2*B*Sqrt[Cos[c + d*x]]*EllipticE[(c + d*x)/2, 2])/(b*d*Sqrt[b*Cos[c + d*x]]) + (2*(3*A + C)*Sqrt[Cos[c + d*x]]*EllipticF[(c + d*x)/2, 2])/(3*b*d*Sqrt[b*Cos[c + d*x]]) + (2*C*Sqrt[b*Cos[c + d*x]]*Sin[c + d*x])/(3*b^2*d)}
{(A + B*Cos[c + d*x] + C*Cos[c + d*x]^2)/(b*Cos[c + d*x])^(3/2), x, 6, (-2*(A - C)*Sqrt[Cos[c + d*x]]*EllipticE[(c + d*x)/2, 2])/(b*d*Sqrt[b*Cos[c + d*x]]) + (2*B*Sqrt[Cos[c + d*x]]*EllipticF[(c + d*x)/2, 2])/(b*d*Sqrt[b*Cos[c + d*x]]) + (2*A*Sin[c + d*x])/(b*d*Sqrt[b*Cos[c + d*x]])}
{((A + B*Cos[c + d*x] + C*Cos[c + d*x]^2)*Sec[c + d*x])/(b*Cos[c + d*x])^(3/2), x, 8, (-2*B*Sqrt[Cos[c + d*x]]*EllipticE[(c + d*x)/2, 2])/(b*d*Sqrt[b*Cos[c + d*x]]) + (2*(A + 3*C)*Sqrt[Cos[c + d*x]]*EllipticF[(c + d*x)/2, 2])/(3*b*d*Sqrt[b*Cos[c + d*x]]) + (2*A*Sin[c + d*x])/(3*d*(b*Cos[c + d*x])^(3/2)) + (2*B*Sin[c + d*x])/(b*d*Sqrt[b*Cos[c + d*x]])}
{((A + B*Cos[c + d*x] + C*Cos[c + d*x]^2)*Sec[c + d*x]^2)/(b*Cos[c + d*x])^(3/2), x, 9, (-2*(3*A + 5*C)*Sqrt[Cos[c + d*x]]*EllipticE[(c + d*x)/2, 2])/(5*b*d*Sqrt[b*Cos[c + d*x]]) + (2*B*Sqrt[Cos[c + d*x]]*EllipticF[(c + d*x)/2, 2])/(3*b*d*Sqrt[b*Cos[c + d*x]]) + (2*A*b*Sin[c + d*x])/(5*d*(b*Cos[c + d*x])^(5/2)) + (2*B*Sin[c + d*x])/(3*d*(b*Cos[c + d*x])^(3/2)) + (2*(3*A + 5*C)*Sin[c + d*x])/(5*b*d*Sqrt[b*Cos[c + d*x]])}
{((A + B*Cos[c + d*x] + C*Cos[c + d*x]^2)*Sec[c + d*x]^3)/(b*Cos[c + d*x])^(3/2), x, 10, -((6*B*Sqrt[Cos[c + d*x]]*EllipticE[(1/2)*(c + d*x), 2])/(5*b*d*Sqrt[b*Cos[c + d*x]])) + (2*(5*A + 7*C)*Sqrt[Cos[c + d*x]]*EllipticF[(1/2)*(c + d*x), 2])/(21*b*d*Sqrt[b*Cos[c + d*x]]) + (2*A*b^2*Sin[c + d*x])/(7*d*(b*Cos[c + d*x])^(7/2)) + (2*b*B*Sin[c + d*x])/(5*d*(b*Cos[c + d*x])^(5/2)) + (2*(5*A + 7*C)*Sin[c + d*x])/(21*d*(b*Cos[c + d*x])^(3/2)) + (6*B*Sin[c + d*x])/(5*b*d*Sqrt[b*Cos[c + d*x]])}


{(Cos[c + d*x]^5*(A + B*Cos[c + d*x] + C*Cos[c + d*x]^2))/(b*Cos[c + d*x])^(5/2), x, 10, (2*(9*A + 7*C)*Sqrt[Cos[c + d*x]]*EllipticE[(c + d*x)/2, 2])/(15*b^2*d*Sqrt[b*Cos[c + d*x]]) + (10*B*Sqrt[Cos[c + d*x]]*EllipticF[(c + d*x)/2, 2])/(21*b^2*d*Sqrt[b*Cos[c + d*x]]) + (10*B*Sqrt[b*Cos[c + d*x]]*Sin[c + d*x])/(21*b^3*d) + (2*(9*A + 7*C)*(b*Cos[c + d*x])^(3/2)*Sin[c + d*x])/(45*b^4*d) + (2*B*(b*Cos[c + d*x])^(5/2)*Sin[c + d*x])/(7*b^5*d) + (2*C*(b*Cos[c + d*x])^(7/2)*Sin[c + d*x])/(9*b^6*d)}
{(Cos[c + d*x]^4*(A + B*Cos[c + d*x] + C*Cos[c + d*x]^2))/(b*Cos[c + d*x])^(5/2), x, 9, (6*B*Sqrt[Cos[c + d*x]]*EllipticE[(c + d*x)/2, 2])/(5*b^2*d*Sqrt[b*Cos[c + d*x]]) + (2*(7*A + 5*C)*Sqrt[Cos[c + d*x]]*EllipticF[(c + d*x)/2, 2])/(21*b^2*d*Sqrt[b*Cos[c + d*x]]) + (2*(7*A + 5*C)*Sqrt[b*Cos[c + d*x]]*Sin[c + d*x])/(21*b^3*d) + (2*B*(b*Cos[c + d*x])^(3/2)*Sin[c + d*x])/(5*b^4*d) + (2*C*(b*Cos[c + d*x])^(5/2)*Sin[c + d*x])/(7*b^5*d)}
{(Cos[c + d*x]^3*(A + B*Cos[c + d*x] + C*Cos[c + d*x]^2))/(b*Cos[c + d*x])^(5/2), x, 8, (2*(5*A + 3*C)*Sqrt[Cos[c + d*x]]*EllipticE[(c + d*x)/2, 2])/(5*b^2*d*Sqrt[b*Cos[c + d*x]]) + (2*B*Sqrt[Cos[c + d*x]]*EllipticF[(c + d*x)/2, 2])/(3*b^2*d*Sqrt[b*Cos[c + d*x]]) + (2*B*Sqrt[b*Cos[c + d*x]]*Sin[c + d*x])/(3*b^3*d) + (2*C*(b*Cos[c + d*x])^(3/2)*Sin[c + d*x])/(5*b^4*d)}
{(Cos[c + d*x]^2*(A + B*Cos[c + d*x] + C*Cos[c + d*x]^2))/(b*Cos[c + d*x])^(5/2), x, 7, (2*B*Sqrt[Cos[c + d*x]]*EllipticE[(c + d*x)/2, 2])/(b^2*d*Sqrt[b*Cos[c + d*x]]) + (2*(3*A + C)*Sqrt[Cos[c + d*x]]*EllipticF[(c + d*x)/2, 2])/(3*b^2*d*Sqrt[b*Cos[c + d*x]]) + (2*C*Sqrt[b*Cos[c + d*x]]*Sin[c + d*x])/(3*b^3*d)}
{(Cos[c + d*x]*(A + B*Cos[c + d*x] + C*Cos[c + d*x]^2))/(b*Cos[c + d*x])^(5/2), x, 7, (-2*(A - C)*Sqrt[Cos[c + d*x]]*EllipticE[(c + d*x)/2, 2])/(b^2*d*Sqrt[b*Cos[c + d*x]]) + (2*B*Sqrt[Cos[c + d*x]]*EllipticF[(c + d*x)/2, 2])/(b^2*d*Sqrt[b*Cos[c + d*x]]) + (2*A*Sin[c + d*x])/(b^2*d*Sqrt[b*Cos[c + d*x]])}
{(A + B*Cos[c + d*x] + C*Cos[c + d*x]^2)/(b*Cos[c + d*x])^(5/2), x, 7, (-2*B*Sqrt[Cos[c + d*x]]*EllipticE[(c + d*x)/2, 2])/(b^2*d*Sqrt[b*Cos[c + d*x]]) + (2*(A + 3*C)*Sqrt[Cos[c + d*x]]*EllipticF[(c + d*x)/2, 2])/(3*b^2*d*Sqrt[b*Cos[c + d*x]]) + (2*A*Sin[c + d*x])/(3*b*d*(b*Cos[c + d*x])^(3/2)) + (2*B*Sin[c + d*x])/(b^2*d*Sqrt[b*Cos[c + d*x]])}
{((A + B*Cos[c + d*x] + C*Cos[c + d*x]^2)*Sec[c + d*x])/(b*Cos[c + d*x])^(5/2), x, 9, (-2*(3*A + 5*C)*Sqrt[Cos[c + d*x]]*EllipticE[(c + d*x)/2, 2])/(5*b^2*d*Sqrt[b*Cos[c + d*x]]) + (2*B*Sqrt[Cos[c + d*x]]*EllipticF[(c + d*x)/2, 2])/(3*b^2*d*Sqrt[b*Cos[c + d*x]]) + (2*A*Sin[c + d*x])/(5*d*(b*Cos[c + d*x])^(5/2)) + (2*B*Sin[c + d*x])/(3*b*d*(b*Cos[c + d*x])^(3/2)) + (2*(3*A + 5*C)*Sin[c + d*x])/(5*b^2*d*Sqrt[b*Cos[c + d*x]])}
{((A + B*Cos[c + d*x] + C*Cos[c + d*x]^2)*Sec[c + d*x]^2)/(b*Cos[c + d*x])^(5/2), x, 10, -((6*B*Sqrt[Cos[c + d*x]]*EllipticE[(1/2)*(c + d*x), 2])/(5*b^2*d*Sqrt[b*Cos[c + d*x]])) + (2*(5*A + 7*C)*Sqrt[Cos[c + d*x]]*EllipticF[(1/2)*(c + d*x), 2])/(21*b^2*d*Sqrt[b*Cos[c + d*x]]) + (2*A*b*Sin[c + d*x])/(7*d*(b*Cos[c + d*x])^(7/2)) + (2*B*Sin[c + d*x])/(5*d*(b*Cos[c + d*x])^(5/2)) + (2*(5*A + 7*C)*Sin[c + d*x])/(21*b*d*(b*Cos[c + d*x])^(3/2)) + (6*B*Sin[c + d*x])/(5*b^2*d*Sqrt[b*Cos[c + d*x]])}


{(A + B*Cos[c + d*x] + C*Cos[c + d*x]^2)/(b*Cos[c + d*x])^(7/2), x, 8, (-2*(3*A + 5*C)*Sqrt[Cos[c + d*x]]*EllipticE[(c + d*x)/2, 2])/(5*b^3*d*Sqrt[b*Cos[c + d*x]]) + (2*B*Sqrt[Cos[c + d*x]]*EllipticF[(c + d*x)/2, 2])/(3*b^3*d*Sqrt[b*Cos[c + d*x]]) + (2*A*Sin[c + d*x])/(5*b*d*(b*Cos[c + d*x])^(5/2)) + (2*B*Sin[c + d*x])/(3*b^2*d*(b*Cos[c + d*x])^(3/2)) + (2*(3*A + 5*C)*Sin[c + d*x])/(5*b^3*d*Sqrt[b*Cos[c + d*x]])}


(* ::Subsection::Closed:: *)
(*Integrands of the form Cos[c+d x]^(m/2) (A+B Cos[c+d x]+C Cos[c+d x]^2) (b Cos[c+d x])^(n/2)*)


(* ::Subsubsection::Closed:: *)
(*n>0*)


{Cos[c + d*x]^(5/2)*Sqrt[b*Cos[c + d*x]]*(A + B*Cos[c + d*x] + C*Cos[c + d*x]^2), x, 6, (3*B*x*Sqrt[b*Cos[c + d*x]])/(8*Sqrt[Cos[c + d*x]]) + (2*(5*A + 4*C)*Sqrt[b*Cos[c + d*x]]*Sin[c + d*x])/(15*d*Sqrt[Cos[c + d*x]]) + (3*B*Sqrt[Cos[c + d*x]]*Sqrt[b*Cos[c + d*x]]*Sin[c + d*x])/(8*d) + ((5*A + 4*C)*Cos[c + d*x]^(3/2)*Sqrt[b*Cos[c + d*x]]*Sin[c + d*x])/(15*d) + (B*Cos[c + d*x]^(5/2)*Sqrt[b*Cos[c + d*x]]*Sin[c + d*x])/(4*d) + (C*Cos[c + d*x]^(7/2)*Sqrt[b*Cos[c + d*x]]*Sin[c + d*x])/(5*d)}
{Cos[c + d*x]^(3/2)*Sqrt[b*Cos[c + d*x]]*(A + B*Cos[c + d*x] + C*Cos[c + d*x]^2), x, 5, ((4*A + 3*C)*x*Sqrt[b*Cos[c + d*x]])/(8*Sqrt[Cos[c + d*x]]) + (2*B*Sqrt[b*Cos[c + d*x]]*Sin[c + d*x])/(3*d*Sqrt[Cos[c + d*x]]) + ((4*A + 3*C)*Sqrt[Cos[c + d*x]]*Sqrt[b*Cos[c + d*x]]*Sin[c + d*x])/(8*d) + (B*Cos[c + d*x]^(3/2)*Sqrt[b*Cos[c + d*x]]*Sin[c + d*x])/(3*d) + (C*Cos[c + d*x]^(5/2)*Sqrt[b*Cos[c + d*x]]*Sin[c + d*x])/(4*d)}
{Sqrt[Cos[c + d*x]]*Sqrt[b*Cos[c + d*x]]*(A + B*Cos[c + d*x] + C*Cos[c + d*x]^2), x, 4, (B*x*Sqrt[b*Cos[c + d*x]])/(2*Sqrt[Cos[c + d*x]]) + ((3*A + 2*C)*Sqrt[b*Cos[c + d*x]]*Sin[c + d*x])/(3*d*Sqrt[Cos[c + d*x]]) + (B*Sqrt[Cos[c + d*x]]*Sqrt[b*Cos[c + d*x]]*Sin[c + d*x])/(2*d) + (C*Cos[c + d*x]^(3/2)*Sqrt[b*Cos[c + d*x]]*Sin[c + d*x])/(3*d)}
{(Sqrt[b*Cos[c + d*x]]*(A + B*Cos[c + d*x] + C*Cos[c + d*x]^2))/Sqrt[Cos[c + d*x]], x, 4, (A*x*Sqrt[b*Cos[c + d*x]])/Sqrt[Cos[c + d*x]] + (C*x*Sqrt[b*Cos[c + d*x]])/(2*Sqrt[Cos[c + d*x]]) + (B*Sqrt[b*Cos[c + d*x]]*Sin[c + d*x])/(d*Sqrt[Cos[c + d*x]]) + (C*Sqrt[Cos[c + d*x]]*Sqrt[b*Cos[c + d*x]]*Sin[c + d*x])/(2*d)}
{(Sqrt[b*Cos[c + d*x]]*(A + B*Cos[c + d*x] + C*Cos[c + d*x]^2))/Cos[c + d*x]^(3/2), x, 4, (B*x*Sqrt[b*Cos[c + d*x]])/Sqrt[Cos[c + d*x]] + (A*ArcTanh[Sin[c + d*x]]*Sqrt[b*Cos[c + d*x]])/(d*Sqrt[Cos[c + d*x]]) + (C*Sqrt[b*Cos[c + d*x]]*Sin[c + d*x])/(d*Sqrt[Cos[c + d*x]])}
{(Sqrt[b*Cos[c + d*x]]*(A + B*Cos[c + d*x] + C*Cos[c + d*x]^2))/Cos[c + d*x]^(5/2), x, 4, (C*x*Sqrt[b*Cos[c + d*x]])/Sqrt[Cos[c + d*x]] + (B*ArcTanh[Sin[c + d*x]]*Sqrt[b*Cos[c + d*x]])/(d*Sqrt[Cos[c + d*x]]) + (A*Sqrt[b*Cos[c + d*x]]*Sin[c + d*x])/(d*Cos[c + d*x]^(3/2))}
{(Sqrt[b*Cos[c + d*x]]*(A + B*Cos[c + d*x] + C*Cos[c + d*x]^2))/Cos[c + d*x]^(7/2), x, 5, ((A + 2*C)*ArcTanh[Sin[c + d*x]]*Sqrt[b*Cos[c + d*x]])/(2*d*Sqrt[Cos[c + d*x]]) + (A*Sqrt[b*Cos[c + d*x]]*Sin[c + d*x])/(2*d*Cos[c + d*x]^(5/2)) + (B*Sqrt[b*Cos[c + d*x]]*Sin[c + d*x])/(d*Cos[c + d*x]^(3/2))}
{(Sqrt[b*Cos[c + d*x]]*(A + B*Cos[c + d*x] + C*Cos[c + d*x]^2))/Cos[c + d*x]^(9/2), x, 6, (B*ArcTanh[Sin[c + d*x]]*Sqrt[b*Cos[c + d*x]])/(2*d*Sqrt[Cos[c + d*x]]) + (A*Sqrt[b*Cos[c + d*x]]*Sin[c + d*x])/(3*d*Cos[c + d*x]^(7/2)) + (B*Sqrt[b*Cos[c + d*x]]*Sin[c + d*x])/(2*d*Cos[c + d*x]^(5/2)) + ((2*A + 3*C)*Sqrt[b*Cos[c + d*x]]*Sin[c + d*x])/(3*d*Cos[c + d*x]^(3/2))}
{(Sqrt[b*Cos[c + d*x]]*(A + B*Cos[c + d*x] + C*Cos[c + d*x]^2))/Cos[c + d*x]^(11/2), x, 7, ((3*A + 4*C)*ArcTanh[Sin[c + d*x]]*Sqrt[b*Cos[c + d*x]])/(8*d*Sqrt[Cos[c + d*x]]) + (A*Sqrt[b*Cos[c + d*x]]*Sin[c + d*x])/(4*d*Cos[c + d*x]^(9/2)) + (B*Sqrt[b*Cos[c + d*x]]*Sin[c + d*x])/(3*d*Cos[c + d*x]^(7/2)) + ((3*A + 4*C)*Sqrt[b*Cos[c + d*x]]*Sin[c + d*x])/(8*d*Cos[c + d*x]^(5/2)) + (2*B*Sqrt[b*Cos[c + d*x]]*Sin[c + d*x])/(3*d*Cos[c + d*x]^(3/2))}


{Cos[c + d*x]^(3/2)*(b*Cos[c + d*x])^(3/2)*(A + B*Cos[c + d*x] + C*Cos[c + d*x]^2), x, 6, (3*b*B*x*Sqrt[b*Cos[c + d*x]])/(8*Sqrt[Cos[c + d*x]]) + (2*b*(5*A + 4*C)*Sqrt[b*Cos[c + d*x]]*Sin[c + d*x])/(15*d*Sqrt[Cos[c + d*x]]) + (3*b*B*Sqrt[Cos[c + d*x]]*Sqrt[b*Cos[c + d*x]]*Sin[c + d*x])/(8*d) + (b*(5*A + 4*C)*Cos[c + d*x]^(3/2)*Sqrt[b*Cos[c + d*x]]*Sin[c + d*x])/(15*d) + (b*B*Cos[c + d*x]^(5/2)*Sqrt[b*Cos[c + d*x]]*Sin[c + d*x])/(4*d) + (b*C*Cos[c + d*x]^(7/2)*Sqrt[b*Cos[c + d*x]]*Sin[c + d*x])/(5*d)}
{Sqrt[Cos[c + d*x]]*(b*Cos[c + d*x])^(3/2)*(A + B*Cos[c + d*x] + C*Cos[c + d*x]^2), x, 5, (b*(4*A + 3*C)*x*Sqrt[b*Cos[c + d*x]])/(8*Sqrt[Cos[c + d*x]]) + (2*b*B*Sqrt[b*Cos[c + d*x]]*Sin[c + d*x])/(3*d*Sqrt[Cos[c + d*x]]) + (b*(4*A + 3*C)*Sqrt[Cos[c + d*x]]*Sqrt[b*Cos[c + d*x]]*Sin[c + d*x])/(8*d) + (b*B*Cos[c + d*x]^(3/2)*Sqrt[b*Cos[c + d*x]]*Sin[c + d*x])/(3*d) + (b*C*Cos[c + d*x]^(5/2)*Sqrt[b*Cos[c + d*x]]*Sin[c + d*x])/(4*d)}
{((b*Cos[c + d*x])^(3/2)*(A + B*Cos[c + d*x] + C*Cos[c + d*x]^2))/Sqrt[Cos[c + d*x]], x, 4, (b*B*x*Sqrt[b*Cos[c + d*x]])/(2*Sqrt[Cos[c + d*x]]) + (b*(3*A + 2*C)*Sqrt[b*Cos[c + d*x]]*Sin[c + d*x])/(3*d*Sqrt[Cos[c + d*x]]) + (b*B*Sqrt[Cos[c + d*x]]*Sqrt[b*Cos[c + d*x]]*Sin[c + d*x])/(2*d) + (b*C*Cos[c + d*x]^(3/2)*Sqrt[b*Cos[c + d*x]]*Sin[c + d*x])/(3*d)}
{((b*Cos[c + d*x])^(3/2)*(A + B*Cos[c + d*x] + C*Cos[c + d*x]^2))/Cos[c + d*x]^(3/2), x, 4, (A*b*x*Sqrt[b*Cos[c + d*x]])/Sqrt[Cos[c + d*x]] + (b*C*x*Sqrt[b*Cos[c + d*x]])/(2*Sqrt[Cos[c + d*x]]) + (b*B*Sqrt[b*Cos[c + d*x]]*Sin[c + d*x])/(d*Sqrt[Cos[c + d*x]]) + (b*C*Sqrt[Cos[c + d*x]]*Sqrt[b*Cos[c + d*x]]*Sin[c + d*x])/(2*d)}
{((b*Cos[c + d*x])^(3/2)*(A + B*Cos[c + d*x] + C*Cos[c + d*x]^2))/Cos[c + d*x]^(5/2), x, 4, (b*B*x*Sqrt[b*Cos[c + d*x]])/Sqrt[Cos[c + d*x]] + (A*b*ArcTanh[Sin[c + d*x]]*Sqrt[b*Cos[c + d*x]])/(d*Sqrt[Cos[c + d*x]]) + (b*C*Sqrt[b*Cos[c + d*x]]*Sin[c + d*x])/(d*Sqrt[Cos[c + d*x]])}
{((b*Cos[c + d*x])^(3/2)*(A + B*Cos[c + d*x] + C*Cos[c + d*x]^2))/Cos[c + d*x]^(7/2), x, 4, (b*C*x*Sqrt[b*Cos[c + d*x]])/Sqrt[Cos[c + d*x]] + (b*B*ArcTanh[Sin[c + d*x]]*Sqrt[b*Cos[c + d*x]])/(d*Sqrt[Cos[c + d*x]]) + (A*b*Sqrt[b*Cos[c + d*x]]*Sin[c + d*x])/(d*Cos[c + d*x]^(3/2))}
{((b*Cos[c + d*x])^(3/2)*(A + B*Cos[c + d*x] + C*Cos[c + d*x]^2))/Cos[c + d*x]^(9/2), x, 5, (b*(A + 2*C)*ArcTanh[Sin[c + d*x]]*Sqrt[b*Cos[c + d*x]])/(2*d*Sqrt[Cos[c + d*x]]) + (A*b*Sqrt[b*Cos[c + d*x]]*Sin[c + d*x])/(2*d*Cos[c + d*x]^(5/2)) + (b*B*Sqrt[b*Cos[c + d*x]]*Sin[c + d*x])/(d*Cos[c + d*x]^(3/2))}
{((b*Cos[c + d*x])^(3/2)*(A + B*Cos[c + d*x] + C*Cos[c + d*x]^2))/Cos[c + d*x]^(11/2), x, 6, (b*B*ArcTanh[Sin[c + d*x]]*Sqrt[b*Cos[c + d*x]])/(2*d*Sqrt[Cos[c + d*x]]) + (A*b*Sqrt[b*Cos[c + d*x]]*Sin[c + d*x])/(3*d*Cos[c + d*x]^(7/2)) + (b*B*Sqrt[b*Cos[c + d*x]]*Sin[c + d*x])/(2*d*Cos[c + d*x]^(5/2)) + (b*(2*A + 3*C)*Sqrt[b*Cos[c + d*x]]*Sin[c + d*x])/(3*d*Cos[c + d*x]^(3/2))}
{((b*Cos[c + d*x])^(3/2)*(A + B*Cos[c + d*x] + C*Cos[c + d*x]^2))/Cos[c + d*x]^(13/2), x, 7, (b*(3*A + 4*C)*ArcTanh[Sin[c + d*x]]*Sqrt[b*Cos[c + d*x]])/(8*d*Sqrt[Cos[c + d*x]]) + (A*b*Sqrt[b*Cos[c + d*x]]*Sin[c + d*x])/(4*d*Cos[c + d*x]^(9/2)) + (b*B*Sqrt[b*Cos[c + d*x]]*Sin[c + d*x])/(3*d*Cos[c + d*x]^(7/2)) + (b*(3*A + 4*C)*Sqrt[b*Cos[c + d*x]]*Sin[c + d*x])/(8*d*Cos[c + d*x]^(5/2)) + (2*b*B*Sqrt[b*Cos[c + d*x]]*Sin[c + d*x])/(3*d*Cos[c + d*x]^(3/2))}


{Sqrt[Cos[c + d*x]]*(b*Cos[c + d*x])^(5/2)*(A + B*Cos[c + d*x] + C*Cos[c + d*x]^2), x, 6, (3*b^2*B*x*Sqrt[b*Cos[c + d*x]])/(8*Sqrt[Cos[c + d*x]]) + (2*b^2*(5*A + 4*C)*Sqrt[b*Cos[c + d*x]]*Sin[c + d*x])/(15*d*Sqrt[Cos[c + d*x]]) + (3*b^2*B*Sqrt[Cos[c + d*x]]*Sqrt[b*Cos[c + d*x]]*Sin[c + d*x])/(8*d) + (b^2*(5*A + 4*C)*Cos[c + d*x]^(3/2)*Sqrt[b*Cos[c + d*x]]*Sin[c + d*x])/(15*d) + (b^2*B*Cos[c + d*x]^(5/2)*Sqrt[b*Cos[c + d*x]]*Sin[c + d*x])/(4*d) + (b^2*C*Cos[c + d*x]^(7/2)*Sqrt[b*Cos[c + d*x]]*Sin[c + d*x])/(5*d)}
{((b*Cos[c + d*x])^(5/2)*(A + B*Cos[c + d*x] + C*Cos[c + d*x]^2))/Sqrt[Cos[c + d*x]], x, 5, (b^2*(4*A + 3*C)*x*Sqrt[b*Cos[c + d*x]])/(8*Sqrt[Cos[c + d*x]]) + (2*b^2*B*Sqrt[b*Cos[c + d*x]]*Sin[c + d*x])/(3*d*Sqrt[Cos[c + d*x]]) + (b^2*(4*A + 3*C)*Sqrt[Cos[c + d*x]]*Sqrt[b*Cos[c + d*x]]*Sin[c + d*x])/(8*d) + (b^2*B*Cos[c + d*x]^(3/2)*Sqrt[b*Cos[c + d*x]]*Sin[c + d*x])/(3*d) + (b^2*C*Cos[c + d*x]^(5/2)*Sqrt[b*Cos[c + d*x]]*Sin[c + d*x])/(4*d)}
{((b*Cos[c + d*x])^(5/2)*(A + B*Cos[c + d*x] + C*Cos[c + d*x]^2))/Cos[c + d*x]^(3/2), x, 4, (b^2*B*x*Sqrt[b*Cos[c + d*x]])/(2*Sqrt[Cos[c + d*x]]) + (b^2*(3*A + 2*C)*Sqrt[b*Cos[c + d*x]]*Sin[c + d*x])/(3*d*Sqrt[Cos[c + d*x]]) + (b^2*B*Sqrt[Cos[c + d*x]]*Sqrt[b*Cos[c + d*x]]*Sin[c + d*x])/(2*d) + (b^2*C*Cos[c + d*x]^(3/2)*Sqrt[b*Cos[c + d*x]]*Sin[c + d*x])/(3*d)}
{((b*Cos[c + d*x])^(5/2)*(A + B*Cos[c + d*x] + C*Cos[c + d*x]^2))/Cos[c + d*x]^(5/2), x, 4, (A*b^2*x*Sqrt[b*Cos[c + d*x]])/Sqrt[Cos[c + d*x]] + (b^2*C*x*Sqrt[b*Cos[c + d*x]])/(2*Sqrt[Cos[c + d*x]]) + (b^2*B*Sqrt[b*Cos[c + d*x]]*Sin[c + d*x])/(d*Sqrt[Cos[c + d*x]]) + (b^2*C*Sqrt[Cos[c + d*x]]*Sqrt[b*Cos[c + d*x]]*Sin[c + d*x])/(2*d)}
{((b*Cos[c + d*x])^(5/2)*(A + B*Cos[c + d*x] + C*Cos[c + d*x]^2))/Cos[c + d*x]^(7/2), x, 4, (b^2*B*x*Sqrt[b*Cos[c + d*x]])/Sqrt[Cos[c + d*x]] + (A*b^2*ArcTanh[Sin[c + d*x]]*Sqrt[b*Cos[c + d*x]])/(d*Sqrt[Cos[c + d*x]]) + (b^2*C*Sqrt[b*Cos[c + d*x]]*Sin[c + d*x])/(d*Sqrt[Cos[c + d*x]])}
{((b*Cos[c + d*x])^(5/2)*(A + B*Cos[c + d*x] + C*Cos[c + d*x]^2))/Cos[c + d*x]^(9/2), x, 4, (b^2*C*x*Sqrt[b*Cos[c + d*x]])/Sqrt[Cos[c + d*x]] + (b^2*B*ArcTanh[Sin[c + d*x]]*Sqrt[b*Cos[c + d*x]])/(d*Sqrt[Cos[c + d*x]]) + (A*b^2*Sqrt[b*Cos[c + d*x]]*Sin[c + d*x])/(d*Cos[c + d*x]^(3/2))}
{((b*Cos[c + d*x])^(5/2)*(A + B*Cos[c + d*x] + C*Cos[c + d*x]^2))/Cos[c + d*x]^(11/2), x, 5, (b^2*(A + 2*C)*ArcTanh[Sin[c + d*x]]*Sqrt[b*Cos[c + d*x]])/(2*d*Sqrt[Cos[c + d*x]]) + (A*b^2*Sqrt[b*Cos[c + d*x]]*Sin[c + d*x])/(2*d*Cos[c + d*x]^(5/2)) + (b^2*B*Sqrt[b*Cos[c + d*x]]*Sin[c + d*x])/(d*Cos[c + d*x]^(3/2))}
{((b*Cos[c + d*x])^(5/2)*(A + B*Cos[c + d*x] + C*Cos[c + d*x]^2))/Cos[c + d*x]^(13/2), x, 6, (b^2*B*ArcTanh[Sin[c + d*x]]*Sqrt[b*Cos[c + d*x]])/(2*d*Sqrt[Cos[c + d*x]]) + (A*b^2*Sqrt[b*Cos[c + d*x]]*Sin[c + d*x])/(3*d*Cos[c + d*x]^(7/2)) + (b^2*B*Sqrt[b*Cos[c + d*x]]*Sin[c + d*x])/(2*d*Cos[c + d*x]^(5/2)) + (b^2*(2*A + 3*C)*Sqrt[b*Cos[c + d*x]]*Sin[c + d*x])/(3*d*Cos[c + d*x]^(3/2))}
{((b*Cos[c + d*x])^(5/2)*(A + B*Cos[c + d*x] + C*Cos[c + d*x]^2))/Cos[c + d*x]^(15/2), x, 7, (b^2*(3*A + 4*C)*ArcTanh[Sin[c + d*x]]*Sqrt[b*Cos[c + d*x]])/(8*d*Sqrt[Cos[c + d*x]]) + (A*b^2*Sqrt[b*Cos[c + d*x]]*Sin[c + d*x])/(4*d*Cos[c + d*x]^(9/2)) + (b^2*B*Sqrt[b*Cos[c + d*x]]*Sin[c + d*x])/(3*d*Cos[c + d*x]^(7/2)) + (b^2*(3*A + 4*C)*Sqrt[b*Cos[c + d*x]]*Sin[c + d*x])/(8*d*Cos[c + d*x]^(5/2)) + (2*b^2*B*Sqrt[b*Cos[c + d*x]]*Sin[c + d*x])/(3*d*Cos[c + d*x]^(3/2))}


(* ::Subsubsection::Closed:: *)
(*n<0*)


{(Cos[c + d*x]^(5/2)*(A + B*Cos[c + d*x] + C*Cos[c + d*x]^2))/Sqrt[b*Cos[c + d*x]], x, 5, ((4*A + 3*C)*x*Sqrt[Cos[c + d*x]])/(8*Sqrt[b*Cos[c + d*x]]) + (2*B*Sqrt[Cos[c + d*x]]*Sin[c + d*x])/(3*d*Sqrt[b*Cos[c + d*x]]) + ((4*A + 3*C)*Cos[c + d*x]^(3/2)*Sin[c + d*x])/(8*d*Sqrt[b*Cos[c + d*x]]) + (B*Cos[c + d*x]^(5/2)*Sin[c + d*x])/(3*d*Sqrt[b*Cos[c + d*x]]) + (C*Cos[c + d*x]^(7/2)*Sin[c + d*x])/(4*d*Sqrt[b*Cos[c + d*x]])}
{(Cos[c + d*x]^(3/2)*(A + B*Cos[c + d*x] + C*Cos[c + d*x]^2))/Sqrt[b*Cos[c + d*x]], x, 4, (B*x*Sqrt[Cos[c + d*x]])/(2*Sqrt[b*Cos[c + d*x]]) + ((3*A + 2*C)*Sqrt[Cos[c + d*x]]*Sin[c + d*x])/(3*d*Sqrt[b*Cos[c + d*x]]) + (B*Cos[c + d*x]^(3/2)*Sin[c + d*x])/(2*d*Sqrt[b*Cos[c + d*x]]) + (C*Cos[c + d*x]^(5/2)*Sin[c + d*x])/(3*d*Sqrt[b*Cos[c + d*x]])}
{(Sqrt[Cos[c + d*x]]*(A + B*Cos[c + d*x] + C*Cos[c + d*x]^2))/Sqrt[b*Cos[c + d*x]], x, 4, (A*x*Sqrt[Cos[c + d*x]])/Sqrt[b*Cos[c + d*x]] + (C*x*Sqrt[Cos[c + d*x]])/(2*Sqrt[b*Cos[c + d*x]]) + (B*Sqrt[Cos[c + d*x]]*Sin[c + d*x])/(d*Sqrt[b*Cos[c + d*x]]) + (C*Cos[c + d*x]^(3/2)*Sin[c + d*x])/(2*d*Sqrt[b*Cos[c + d*x]])}
{(A + B*Cos[c + d*x] + C*Cos[c + d*x]^2)/(Sqrt[Cos[c + d*x]]*Sqrt[b*Cos[c + d*x]]), x, 4, (B*x*Sqrt[Cos[c + d*x]])/Sqrt[b*Cos[c + d*x]] + (A*ArcTanh[Sin[c + d*x]]*Sqrt[Cos[c + d*x]])/(d*Sqrt[b*Cos[c + d*x]]) + (C*Sqrt[Cos[c + d*x]]*Sin[c + d*x])/(d*Sqrt[b*Cos[c + d*x]])}
{(A + B*Cos[c + d*x] + C*Cos[c + d*x]^2)/(Cos[c + d*x]^(3/2)*Sqrt[b*Cos[c + d*x]]), x, 4, (C*x*Sqrt[Cos[c + d*x]])/Sqrt[b*Cos[c + d*x]] + (B*ArcTanh[Sin[c + d*x]]*Sqrt[Cos[c + d*x]])/(d*Sqrt[b*Cos[c + d*x]]) + (A*Sin[c + d*x])/(d*Sqrt[Cos[c + d*x]]*Sqrt[b*Cos[c + d*x]])}
{(A + B*Cos[c + d*x] + C*Cos[c + d*x]^2)/(Cos[c + d*x]^(5/2)*Sqrt[b*Cos[c + d*x]]), x, 5, ((A + 2*C)*ArcTanh[Sin[c + d*x]]*Sqrt[Cos[c + d*x]])/(2*d*Sqrt[b*Cos[c + d*x]]) + (A*Sin[c + d*x])/(2*d*Cos[c + d*x]^(3/2)*Sqrt[b*Cos[c + d*x]]) + (B*Sin[c + d*x])/(d*Sqrt[Cos[c + d*x]]*Sqrt[b*Cos[c + d*x]])}
{(A + B*Cos[c + d*x] + C*Cos[c + d*x]^2)/(Cos[c + d*x]^(7/2)*Sqrt[b*Cos[c + d*x]]), x, 6, (B*ArcTanh[Sin[c + d*x]]*Sqrt[Cos[c + d*x]])/(2*d*Sqrt[b*Cos[c + d*x]]) + (A*Sin[c + d*x])/(3*d*Cos[c + d*x]^(5/2)*Sqrt[b*Cos[c + d*x]]) + (B*Sin[c + d*x])/(2*d*Cos[c + d*x]^(3/2)*Sqrt[b*Cos[c + d*x]]) + ((2*A + 3*C)*Sin[c + d*x])/(3*d*Sqrt[Cos[c + d*x]]*Sqrt[b*Cos[c + d*x]])}
{(A + B*Cos[c + d*x] + C*Cos[c + d*x]^2)/(Cos[c + d*x]^(9/2)*Sqrt[b*Cos[c + d*x]]), x, 7, ((3*A + 4*C)*ArcTanh[Sin[c + d*x]]*Sqrt[Cos[c + d*x]])/(8*d*Sqrt[b*Cos[c + d*x]]) + (A*Sin[c + d*x])/(4*d*Cos[c + d*x]^(7/2)*Sqrt[b*Cos[c + d*x]]) + (B*Sin[c + d*x])/(3*d*Cos[c + d*x]^(5/2)*Sqrt[b*Cos[c + d*x]]) + ((3*A + 4*C)*Sin[c + d*x])/(8*d*Cos[c + d*x]^(3/2)*Sqrt[b*Cos[c + d*x]]) + (2*B*Sin[c + d*x])/(3*d*Sqrt[Cos[c + d*x]]*Sqrt[b*Cos[c + d*x]])}


{(Cos[c + d*x]^(7/2)*(A + B*Cos[c + d*x] + C*Cos[c + d*x]^2))/(b*Cos[c + d*x])^(3/2), x, 5, ((4*A + 3*C)*x*Sqrt[Cos[c + d*x]])/(8*b*Sqrt[b*Cos[c + d*x]]) + (2*B*Sqrt[Cos[c + d*x]]*Sin[c + d*x])/(3*b*d*Sqrt[b*Cos[c + d*x]]) + ((4*A + 3*C)*Cos[c + d*x]^(3/2)*Sin[c + d*x])/(8*b*d*Sqrt[b*Cos[c + d*x]]) + (B*Cos[c + d*x]^(5/2)*Sin[c + d*x])/(3*b*d*Sqrt[b*Cos[c + d*x]]) + (C*Cos[c + d*x]^(7/2)*Sin[c + d*x])/(4*b*d*Sqrt[b*Cos[c + d*x]])}
{(Cos[c + d*x]^(5/2)*(A + B*Cos[c + d*x] + C*Cos[c + d*x]^2))/(b*Cos[c + d*x])^(3/2), x, 4, (B*x*Sqrt[Cos[c + d*x]])/(2*b*Sqrt[b*Cos[c + d*x]]) + ((3*A + 2*C)*Sqrt[Cos[c + d*x]]*Sin[c + d*x])/(3*b*d*Sqrt[b*Cos[c + d*x]]) + (B*Cos[c + d*x]^(3/2)*Sin[c + d*x])/(2*b*d*Sqrt[b*Cos[c + d*x]]) + (C*Cos[c + d*x]^(5/2)*Sin[c + d*x])/(3*b*d*Sqrt[b*Cos[c + d*x]])}
{(Cos[c + d*x]^(3/2)*(A + B*Cos[c + d*x] + C*Cos[c + d*x]^2))/(b*Cos[c + d*x])^(3/2), x, 4, (A*x*Sqrt[Cos[c + d*x]])/(b*Sqrt[b*Cos[c + d*x]]) + (C*x*Sqrt[Cos[c + d*x]])/(2*b*Sqrt[b*Cos[c + d*x]]) + (B*Sqrt[Cos[c + d*x]]*Sin[c + d*x])/(b*d*Sqrt[b*Cos[c + d*x]]) + (C*Cos[c + d*x]^(3/2)*Sin[c + d*x])/(2*b*d*Sqrt[b*Cos[c + d*x]])}
{(Sqrt[Cos[c + d*x]]*(A + B*Cos[c + d*x] + C*Cos[c + d*x]^2))/(b*Cos[c + d*x])^(3/2), x, 4, (B*x*Sqrt[Cos[c + d*x]])/(b*Sqrt[b*Cos[c + d*x]]) + (A*ArcTanh[Sin[c + d*x]]*Sqrt[Cos[c + d*x]])/(b*d*Sqrt[b*Cos[c + d*x]]) + (C*Sqrt[Cos[c + d*x]]*Sin[c + d*x])/(b*d*Sqrt[b*Cos[c + d*x]])}
{(A + B*Cos[c + d*x] + C*Cos[c + d*x]^2)/(Sqrt[Cos[c + d*x]]*(b*Cos[c + d*x])^(3/2)), x, 4, (C*x*Sqrt[Cos[c + d*x]])/(b*Sqrt[b*Cos[c + d*x]]) + (B*ArcTanh[Sin[c + d*x]]*Sqrt[Cos[c + d*x]])/(b*d*Sqrt[b*Cos[c + d*x]]) + (A*Sin[c + d*x])/(b*d*Sqrt[Cos[c + d*x]]*Sqrt[b*Cos[c + d*x]])}
{(A + B*Cos[c + d*x] + C*Cos[c + d*x]^2)/(Cos[c + d*x]^(3/2)*(b*Cos[c + d*x])^(3/2)), x, 5, ((A + 2*C)*ArcTanh[Sin[c + d*x]]*Sqrt[Cos[c + d*x]])/(2*b*d*Sqrt[b*Cos[c + d*x]]) + (A*Sin[c + d*x])/(2*b*d*Cos[c + d*x]^(3/2)*Sqrt[b*Cos[c + d*x]]) + (B*Sin[c + d*x])/(b*d*Sqrt[Cos[c + d*x]]*Sqrt[b*Cos[c + d*x]])}
{(A + B*Cos[c + d*x] + C*Cos[c + d*x]^2)/(Cos[c + d*x]^(5/2)*(b*Cos[c + d*x])^(3/2)), x, 6, (B*ArcTanh[Sin[c + d*x]]*Sqrt[Cos[c + d*x]])/(2*b*d*Sqrt[b*Cos[c + d*x]]) + (A*Sin[c + d*x])/(3*b*d*Cos[c + d*x]^(5/2)*Sqrt[b*Cos[c + d*x]]) + (B*Sin[c + d*x])/(2*b*d*Cos[c + d*x]^(3/2)*Sqrt[b*Cos[c + d*x]]) + ((2*A + 3*C)*Sin[c + d*x])/(3*b*d*Sqrt[Cos[c + d*x]]*Sqrt[b*Cos[c + d*x]])}
{(A + B*Cos[c + d*x] + C*Cos[c + d*x]^2)/(Cos[c + d*x]^(7/2)*(b*Cos[c + d*x])^(3/2)), x, 7, ((3*A + 4*C)*ArcTanh[Sin[c + d*x]]*Sqrt[Cos[c + d*x]])/(8*b*d*Sqrt[b*Cos[c + d*x]]) + (A*Sin[c + d*x])/(4*b*d*Cos[c + d*x]^(7/2)*Sqrt[b*Cos[c + d*x]]) + (B*Sin[c + d*x])/(3*b*d*Cos[c + d*x]^(5/2)*Sqrt[b*Cos[c + d*x]]) + ((3*A + 4*C)*Sin[c + d*x])/(8*b*d*Cos[c + d*x]^(3/2)*Sqrt[b*Cos[c + d*x]]) + (2*B*Sin[c + d*x])/(3*b*d*Sqrt[Cos[c + d*x]]*Sqrt[b*Cos[c + d*x]])}


{(Cos[c + d*x]^(9/2)*(A + B*Cos[c + d*x] + C*Cos[c + d*x]^2))/(b*Cos[c + d*x])^(5/2), x, 5, ((4*A + 3*C)*x*Sqrt[Cos[c + d*x]])/(8*b^2*Sqrt[b*Cos[c + d*x]]) + (2*B*Sqrt[Cos[c + d*x]]*Sin[c + d*x])/(3*b^2*d*Sqrt[b*Cos[c + d*x]]) + ((4*A + 3*C)*Cos[c + d*x]^(3/2)*Sin[c + d*x])/(8*b^2*d*Sqrt[b*Cos[c + d*x]]) + (B*Cos[c + d*x]^(5/2)*Sin[c + d*x])/(3*b^2*d*Sqrt[b*Cos[c + d*x]]) + (C*Cos[c + d*x]^(7/2)*Sin[c + d*x])/(4*b^2*d*Sqrt[b*Cos[c + d*x]])}
{(Cos[c + d*x]^(7/2)*(A + B*Cos[c + d*x] + C*Cos[c + d*x]^2))/(b*Cos[c + d*x])^(5/2), x, 4, (B*x*Sqrt[Cos[c + d*x]])/(2*b^2*Sqrt[b*Cos[c + d*x]]) + ((3*A + 2*C)*Sqrt[Cos[c + d*x]]*Sin[c + d*x])/(3*b^2*d*Sqrt[b*Cos[c + d*x]]) + (B*Cos[c + d*x]^(3/2)*Sin[c + d*x])/(2*b^2*d*Sqrt[b*Cos[c + d*x]]) + (C*Cos[c + d*x]^(5/2)*Sin[c + d*x])/(3*b^2*d*Sqrt[b*Cos[c + d*x]])}
{(Cos[c + d*x]^(5/2)*(A + B*Cos[c + d*x] + C*Cos[c + d*x]^2))/(b*Cos[c + d*x])^(5/2), x, 4, (A*x*Sqrt[Cos[c + d*x]])/(b^2*Sqrt[b*Cos[c + d*x]]) + (C*x*Sqrt[Cos[c + d*x]])/(2*b^2*Sqrt[b*Cos[c + d*x]]) + (B*Sqrt[Cos[c + d*x]]*Sin[c + d*x])/(b^2*d*Sqrt[b*Cos[c + d*x]]) + (C*Cos[c + d*x]^(3/2)*Sin[c + d*x])/(2*b^2*d*Sqrt[b*Cos[c + d*x]])}
{(Cos[c + d*x]^(3/2)*(A + B*Cos[c + d*x] + C*Cos[c + d*x]^2))/(b*Cos[c + d*x])^(5/2), x, 4, (B*x*Sqrt[Cos[c + d*x]])/(b^2*Sqrt[b*Cos[c + d*x]]) + (A*ArcTanh[Sin[c + d*x]]*Sqrt[Cos[c + d*x]])/(b^2*d*Sqrt[b*Cos[c + d*x]]) + (C*Sqrt[Cos[c + d*x]]*Sin[c + d*x])/(b^2*d*Sqrt[b*Cos[c + d*x]])}
{(Sqrt[Cos[c + d*x]]*(A + B*Cos[c + d*x] + C*Cos[c + d*x]^2))/(b*Cos[c + d*x])^(5/2), x, 4, (C*x*Sqrt[Cos[c + d*x]])/(b^2*Sqrt[b*Cos[c + d*x]]) + (B*ArcTanh[Sin[c + d*x]]*Sqrt[Cos[c + d*x]])/(b^2*d*Sqrt[b*Cos[c + d*x]]) + (A*Sin[c + d*x])/(b^2*d*Sqrt[Cos[c + d*x]]*Sqrt[b*Cos[c + d*x]])}
{(A + B*Cos[c + d*x] + C*Cos[c + d*x]^2)/(Sqrt[Cos[c + d*x]]*(b*Cos[c + d*x])^(5/2)), x, 5, ((A + 2*C)*ArcTanh[Sin[c + d*x]]*Sqrt[Cos[c + d*x]])/(2*b^2*d*Sqrt[b*Cos[c + d*x]]) + (A*Sin[c + d*x])/(2*b^2*d*Cos[c + d*x]^(3/2)*Sqrt[b*Cos[c + d*x]]) + (B*Sin[c + d*x])/(b^2*d*Sqrt[Cos[c + d*x]]*Sqrt[b*Cos[c + d*x]])}
{(A + B*Cos[c + d*x] + C*Cos[c + d*x]^2)/(Cos[c + d*x]^(3/2)*(b*Cos[c + d*x])^(5/2)), x, 6, (B*ArcTanh[Sin[c + d*x]]*Sqrt[Cos[c + d*x]])/(2*b^2*d*Sqrt[b*Cos[c + d*x]]) + (A*Sin[c + d*x])/(3*b^2*d*Cos[c + d*x]^(5/2)*Sqrt[b*Cos[c + d*x]]) + (B*Sin[c + d*x])/(2*b^2*d*Cos[c + d*x]^(3/2)*Sqrt[b*Cos[c + d*x]]) + ((2*A + 3*C)*Sin[c + d*x])/(3*b^2*d*Sqrt[Cos[c + d*x]]*Sqrt[b*Cos[c + d*x]])}
{(A + B*Cos[c + d*x] + C*Cos[c + d*x]^2)/(Cos[c + d*x]^(5/2)*(b*Cos[c + d*x])^(5/2)), x, 7, ((3*A + 4*C)*ArcTanh[Sin[c + d*x]]*Sqrt[Cos[c + d*x]])/(8*b^2*d*Sqrt[b*Cos[c + d*x]]) + (A*Sin[c + d*x])/(4*b^2*d*Cos[c + d*x]^(7/2)*Sqrt[b*Cos[c + d*x]]) + (B*Sin[c + d*x])/(3*b^2*d*Cos[c + d*x]^(5/2)*Sqrt[b*Cos[c + d*x]]) + ((3*A + 4*C)*Sin[c + d*x])/(8*b^2*d*Cos[c + d*x]^(3/2)*Sqrt[b*Cos[c + d*x]]) + (2*B*Sin[c + d*x])/(3*b^2*d*Sqrt[Cos[c + d*x]]*Sqrt[b*Cos[c + d*x]])}
