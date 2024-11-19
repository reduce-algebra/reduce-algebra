(* ::Package:: *)

(* ::Title:: *)
(*Integration Problems Involving Exponentials*)


(* ::Section::Closed:: *)
(*Integrands involving one exponential function*)


(* ::Subsection::Closed:: *)
(*Integrands of the form x^m f^(a+b x^n)*)


(* ::Subsubsection::Closed:: *)
(*n>0*)


{f^(a + b*x)*x^m, x, 1, (-f^a)*x^(1 + m)*Gamma[1 + m, (-b)*x*Log[f]]*((-b)*x*Log[f])^(-1 - m)}

{f^(a + b*x)*x^5, x, 1, -((f^a*Gamma[6, (-b)*x*Log[f]])/(b^6*Log[f]^6))}
{f^(a + b*x)*x^4, x, 1, (f^a*Gamma[5, (-b)*x*Log[f]])/(b^5*Log[f]^5)}
{f^(a + b*x)*x^3, x, 4, -((6*f^(a + b*x))/(b^4*Log[f]^4)) + (6*f^(a + b*x)*x)/(b^3*Log[f]^3) - (3*f^(a + b*x)*x^2)/(b^2*Log[f]^2) + (f^(a + b*x)*x^3)/(b*Log[f])}
{f^(a + b*x)*x^2, x, 3, (2*f^(a + b*x))/(b^3*Log[f]^3) - (2*f^(a + b*x)*x)/(b^2*Log[f]^2) + (f^(a + b*x)*x^2)/(b*Log[f])}
{f^(a + b*x)*x^1, x, 2, -(f^(a + b*x)/(b^2*Log[f]^2)) + (f^(a + b*x)*x)/(b*Log[f])}
{f^(a + b*x)*x^0, x, 1, f^(a + b*x)/(b*Log[f])}
{f^(a + b*x)/x^1, x, 1, f^a*ExpIntegralEi[b*x*Log[f]]}
{f^(a + b*x)/x^2, x, 2, -(f^(a + b*x)/x) + b*f^a*ExpIntegralEi[b*x*Log[f]]*Log[f]}
{f^(a + b*x)/x^3, x, 3, -(f^(a + b*x)/(2*x^2)) - (b*f^(a + b*x)*Log[f])/(2*x) + (1/2)*b^2*f^a*ExpIntegralEi[b*x*Log[f]]*Log[f]^2}
{f^(a + b*x)/x^4, x, 4, -(f^(a + b*x)/(3*x^3)) - (b*f^(a + b*x)*Log[f])/(6*x^2) - (b^2*f^(a + b*x)*Log[f]^2)/(6*x) + (1/6)*b^3*f^a*ExpIntegralEi[b*x*Log[f]]*Log[f]^3}
{f^(a + b*x)/x^5, x, 1, (-b^4)*f^a*Gamma[-4, (-b)*x*Log[f]]*Log[f]^4}
{f^(a + b*x)/x^6, x, 1, b^5*f^a*Gamma[-5, (-b)*x*Log[f]]*Log[f]^5}


{f^(a + b*x^2)*x^m, x, 1, (-(1/2))*f^a*x^(1 + m)*Gamma[(1 + m)/2, (-b)*x^2*Log[f]]*((-b)*x^2*Log[f])^((1/2)*(-1 - m))}

{f^(a + b*x^2)*x^11, x, 1, -((f^a*Gamma[6, (-b)*x^2*Log[f]])/(2*b^6*Log[f]^6))}
{f^(a + b*x^2)*x^9, x, 1, (f^a*Gamma[5, (-b)*x^2*Log[f]])/(2*b^5*Log[f]^5)}
{f^(a + b*x^2)*x^7, x, 4, -((3*f^(a + b*x^2))/(b^4*Log[f]^4)) + (3*f^(a + b*x^2)*x^2)/(b^3*Log[f]^3) - (3*f^(a + b*x^2)*x^4)/(2*b^2*Log[f]^2) + (f^(a + b*x^2)*x^6)/(2*b*Log[f])}
{f^(a + b*x^2)*x^5, x, 3, f^(a + b*x^2)/(b^3*Log[f]^3) - (f^(a + b*x^2)*x^2)/(b^2*Log[f]^2) + (f^(a + b*x^2)*x^4)/(2*b*Log[f])}
{f^(a + b*x^2)*x^3, x, 2, -(f^(a + b*x^2)/(2*b^2*Log[f]^2)) + (f^(a + b*x^2)*x^2)/(2*b*Log[f])}
{f^(a + b*x^2)*x^1, x, 1, f^(a + b*x^2)/(2*b*Log[f])}
{f^(a + b*x^2)/x^1, x, 1, (1/2)*f^a*ExpIntegralEi[b*x^2*Log[f]]}
{f^(a + b*x^2)/x^3, x, 2, -(f^(a + b*x^2)/(2*x^2)) + (1/2)*b*f^a*ExpIntegralEi[b*x^2*Log[f]]*Log[f]}
{f^(a + b*x^2)/x^5, x, 3, -(f^(a + b*x^2)/(4*x^4)) - (b*f^(a + b*x^2)*Log[f])/(4*x^2) + (1/4)*b^2*f^a*ExpIntegralEi[b*x^2*Log[f]]*Log[f]^2}
{f^(a + b*x^2)/x^7, x, 4, -(f^(a + b*x^2)/(6*x^6)) - (b*f^(a + b*x^2)*Log[f])/(12*x^4) - (b^2*f^(a + b*x^2)*Log[f]^2)/(12*x^2) + (1/12)*b^3*f^a*ExpIntegralEi[b*x^2*Log[f]]*Log[f]^3}
{f^(a + b*x^2)/x^9, x, 1, (-(1/2))*b^4*f^a*Gamma[-4, (-b)*x^2*Log[f]]*Log[f]^4}
{f^(a + b*x^2)/x^11, x, 1, (1/2)*b^5*f^a*Gamma[-5, (-b)*x^2*Log[f]]*Log[f]^5}

{f^(a + b*x^2)*x^12, x, 1, -((f^a*x^13*Gamma[13/2, (-b)*x^2*Log[f]])/(2*((-b)*x^2*Log[f])^(13/2)))}
{f^(a + b*x^2)*x^10, x, 1, -((f^a*x^11*Gamma[11/2, (-b)*x^2*Log[f]])/(2*((-b)*x^2*Log[f])^(11/2)))}
{f^(a + b*x^2)*x^8, x, 5, (105*f^a*Sqrt[Pi]*Erfi[Sqrt[b]*x*Sqrt[Log[f]]])/(32*b^(9/2)*Log[f]^(9/2)) - (105*f^(a + b*x^2)*x)/(16*b^4*Log[f]^4) + (35*f^(a + b*x^2)*x^3)/(8*b^3*Log[f]^3) - (7*f^(a + b*x^2)*x^5)/(4*b^2*Log[f]^2) + (f^(a + b*x^2)*x^7)/(2*b*Log[f])}
{f^(a + b*x^2)*x^6, x, 4, -((15*f^a*Sqrt[Pi]*Erfi[Sqrt[b]*x*Sqrt[Log[f]]])/(16*b^(7/2)*Log[f]^(7/2))) + (15*f^(a + b*x^2)*x)/(8*b^3*Log[f]^3) - (5*f^(a + b*x^2)*x^3)/(4*b^2*Log[f]^2) + (f^(a + b*x^2)*x^5)/(2*b*Log[f])}
{f^(a + b*x^2)*x^4, x, 3, (3*f^a*Sqrt[Pi]*Erfi[Sqrt[b]*x*Sqrt[Log[f]]])/(8*b^(5/2)*Log[f]^(5/2)) - (3*f^(a + b*x^2)*x)/(4*b^2*Log[f]^2) + (f^(a + b*x^2)*x^3)/(2*b*Log[f])}
{f^(a + b*x^2)*x^2, x, 2, -((f^a*Sqrt[Pi]*Erfi[Sqrt[b]*x*Sqrt[Log[f]]])/(4*b^(3/2)*Log[f]^(3/2))) + (f^(a + b*x^2)*x)/(2*b*Log[f])}
{f^(a + b*x^2)*x^0, x, 1, (f^a*Sqrt[Pi]*Erfi[Sqrt[b]*x*Sqrt[Log[f]]])/(2*Sqrt[b]*Sqrt[Log[f]])}
{f^(a + b*x^2)/x^2, x, 2, -(f^(a + b*x^2)/x) + Sqrt[b]*f^a*Sqrt[Pi]*Erfi[Sqrt[b]*x*Sqrt[Log[f]]]*Sqrt[Log[f]]}
{f^(a + b*x^2)/x^4, x, 3, -(f^(a + b*x^2)/(3*x^3)) - (2*b*f^(a + b*x^2)*Log[f])/(3*x) + (2/3)*b^(3/2)*f^a*Sqrt[Pi]*Erfi[Sqrt[b]*x*Sqrt[Log[f]]]*Log[f]^(3/2)}
{f^(a + b*x^2)/x^6, x, 4, -(f^(a + b*x^2)/(5*x^5)) - (2*b*f^(a + b*x^2)*Log[f])/(15*x^3) - (4*b^2*f^(a + b*x^2)*Log[f]^2)/(15*x) + (4/15)*b^(5/2)*f^a*Sqrt[Pi]*Erfi[Sqrt[b]*x*Sqrt[Log[f]]]*Log[f]^(5/2)}
{f^(a + b*x^2)/x^8, x, 5, -(f^(a + b*x^2)/(7*x^7)) - (2*b*f^(a + b*x^2)*Log[f])/(35*x^5) - (4*b^2*f^(a + b*x^2)*Log[f]^2)/(105*x^3) - (8*b^3*f^(a + b*x^2)*Log[f]^3)/(105*x) + (8/105)*b^(7/2)*f^a*Sqrt[Pi]*Erfi[Sqrt[b]*x*Sqrt[Log[f]]]*Log[f]^(7/2)}
{f^(a + b*x^2)/x^10, x, 1, -((f^a*Gamma[-(9/2), (-b)*x^2*Log[f]]*((-b)*x^2*Log[f])^(9/2))/(2*x^9))}
{f^(a + b*x^2)/x^12, x, 1, -((f^a*Gamma[-(11/2), (-b)*x^2*Log[f]]*((-b)*x^2*Log[f])^(11/2))/(2*x^11))}


{f^(a + b*x^3)*x^m, x, 1, (-(1/3))*f^a*x^(1 + m)*Gamma[(1 + m)/3, (-b)*x^3*Log[f]]*((-b)*x^3*Log[f])^((1/3)*(-1 - m))}

{f^(a + b*x^3)*x^17, x, 1, -((f^a*Gamma[6, (-b)*x^3*Log[f]])/(3*b^6*Log[f]^6))}
{f^(a + b*x^3)*x^14, x, 1, (f^a*Gamma[5, (-b)*x^3*Log[f]])/(3*b^5*Log[f]^5)}
{f^(a + b*x^3)*x^11, x, 4, -((2*f^(a + b*x^3))/(b^4*Log[f]^4)) + (2*f^(a + b*x^3)*x^3)/(b^3*Log[f]^3) - (f^(a + b*x^3)*x^6)/(b^2*Log[f]^2) + (f^(a + b*x^3)*x^9)/(3*b*Log[f])}
{f^(a + b*x^3)*x^8, x, 3, (2*f^(a + b*x^3))/(3*b^3*Log[f]^3) - (2*f^(a + b*x^3)*x^3)/(3*b^2*Log[f]^2) + (f^(a + b*x^3)*x^6)/(3*b*Log[f])}
{f^(a + b*x^3)*x^5, x, 2, -(f^(a + b*x^3)/(3*b^2*Log[f]^2)) + (f^(a + b*x^3)*x^3)/(3*b*Log[f])}
{f^(a + b*x^3)*x^2, x, 1, f^(a + b*x^3)/(3*b*Log[f])}
{f^(a + b*x^3)/x^1, x, 1, (1/3)*f^a*ExpIntegralEi[b*x^3*Log[f]]}
{f^(a + b*x^3)/x^4, x, 2, -(f^(a + b*x^3)/(3*x^3)) + (1/3)*b*f^a*ExpIntegralEi[b*x^3*Log[f]]*Log[f]}
{f^(a + b*x^3)/x^7, x, 3, -(f^(a + b*x^3)/(6*x^6)) - (b*f^(a + b*x^3)*Log[f])/(6*x^3) + (1/6)*b^2*f^a*ExpIntegralEi[b*x^3*Log[f]]*Log[f]^2}
{f^(a + b*x^3)/x^10, x, 4, -(f^(a + b*x^3)/(9*x^9)) - (b*f^(a + b*x^3)*Log[f])/(18*x^6) - (b^2*f^(a + b*x^3)*Log[f]^2)/(18*x^3) + (1/18)*b^3*f^a*ExpIntegralEi[b*x^3*Log[f]]*Log[f]^3}
{f^(a + b*x^3)/x^13, x, 1, (-(1/3))*b^4*f^a*Gamma[-4, (-b)*x^3*Log[f]]*Log[f]^4}
{f^(a + b*x^3)/x^16, x, 1, (1/3)*b^5*f^a*Gamma[-5, (-b)*x^3*Log[f]]*Log[f]^5}

{f^(a + b*x^3)*x^4, x, 1, -((f^a*x^5*Gamma[5/3, (-b)*x^3*Log[f]])/(3*((-b)*x^3*Log[f])^(5/3)))}
{f^(a + b*x^3)*x^3, x, 1, -((f^a*x^4*Gamma[4/3, (-b)*x^3*Log[f]])/(3*((-b)*x^3*Log[f])^(4/3)))}
{f^(a + b*x^3)*x^1, x, 1, -((f^a*x^2*Gamma[2/3, (-b)*x^3*Log[f]])/(3*((-b)*x^3*Log[f])^(2/3)))}
{f^(a + b*x^3)*x^0, x, 1, -((f^a*x*Gamma[1/3, (-b)*x^3*Log[f]])/(3*((-b)*x^3*Log[f])^(1/3)))}
{f^(a + b*x^3)/x^2, x, 1, -((f^a*Gamma[-(1/3), (-b)*x^3*Log[f]]*((-b)*x^3*Log[f])^(1/3))/(3*x))}
{f^(a + b*x^3)/x^3, x, 1, -((f^a*Gamma[-(2/3), (-b)*x^3*Log[f]]*((-b)*x^3*Log[f])^(2/3))/(3*x^2))}


{x^(13/2)/E^(b*x), x, 1, -((x^(13/2)*Gamma[15/2, b*x])/(b*(b*x)^(13/2)))}


{E^(4*x^3)*x^2, x, 1, E^(4*x^3)/12}


(* ::Subsubsection::Closed:: *)
(*n<0*)


{f^(a + b/x)*x^m, x, 1, f^a*x^(1 + m)*Gamma[-1 - m, -((b*Log[f])/x)]*(-((b*Log[f])/x))^(1 + m)}

{f^(a + b/x)*x^4, x, 1, (-b^5)*f^a*Gamma[-5, -((b*Log[f])/x)]*Log[f]^5}
{f^(a + b/x)*x^3, x, 1, b^4*f^a*Gamma[-4, -((b*Log[f])/x)]*Log[f]^4}
{f^(a + b/x)*x^2, x, 4, (1/3)*f^(a + b/x)*x^3 + (1/6)*b*f^(a + b/x)*x^2*Log[f] + (1/6)*b^2*f^(a + b/x)*x*Log[f]^2 - (1/6)*b^3*f^a*ExpIntegralEi[(b*Log[f])/x]*Log[f]^3}
{f^(a + b/x)*x^1, x, 3, (1/2)*f^(a + b/x)*x^2 + (1/2)*b*f^(a + b/x)*x*Log[f] - (1/2)*b^2*f^a*ExpIntegralEi[(b*Log[f])/x]*Log[f]^2}
{f^(a + b/x)*x^0, x, 2, f^(a + b/x)*x - b*f^a*ExpIntegralEi[(b*Log[f])/x]*Log[f]}
{f^(a + b/x)/x^1, x, 1, (-f^a)*ExpIntegralEi[(b*Log[f])/x]}
{f^(a + b/x)/x^2, x, 1, -(f^(a + b/x)/(b*Log[f]))}
{f^(a + b/x)/x^3, x, 2, f^(a + b/x)/(b^2*Log[f]^2) - f^(a + b/x)/(b*x*Log[f])}
{f^(a + b/x)/x^4, x, 3, -((2*f^(a + b/x))/(b^3*Log[f]^3)) + (2*f^(a + b/x))/(b^2*x*Log[f]^2) - f^(a + b/x)/(b*x^2*Log[f])}
{f^(a + b/x)/x^5, x, 4, (6*f^(a + b/x))/(b^4*Log[f]^4) - (6*f^(a + b/x))/(b^3*x*Log[f]^3) + (3*f^(a + b/x))/(b^2*x^2*Log[f]^2) - f^(a + b/x)/(b*x^3*Log[f])}
{f^(a + b/x)/x^6, x, 1, -((f^a*Gamma[5, -((b*Log[f])/x)])/(b^5*Log[f]^5))}
{f^(a + b/x)/x^7, x, 1, (f^a*Gamma[6, -((b*Log[f])/x)])/(b^6*Log[f]^6)}


{f^(a + b/x^2)*x^m, x, 1, (1/2)*f^a*x^(1 + m)*Gamma[(1/2)*(-1 - m), -((b*Log[f])/x^2)]*(-((b*Log[f])/x^2))^((1 + m)/2)}

{f^(a + b/x^2)*x^9, x, 1, (-(1/2))*b^5*f^a*Gamma[-5, -((b*Log[f])/x^2)]*Log[f]^5}
{f^(a + b/x^2)*x^7, x, 1, (1/2)*b^4*f^a*Gamma[-4, -((b*Log[f])/x^2)]*Log[f]^4}
{f^(a + b/x^2)*x^5, x, 4, (1/6)*f^(a + b/x^2)*x^6 + (1/12)*b*f^(a + b/x^2)*x^4*Log[f] + (1/12)*b^2*f^(a + b/x^2)*x^2*Log[f]^2 - (1/12)*b^3*f^a*ExpIntegralEi[(b*Log[f])/x^2]*Log[f]^3}
{f^(a + b/x^2)*x^3, x, 3, (1/4)*f^(a + b/x^2)*x^4 + (1/4)*b*f^(a + b/x^2)*x^2*Log[f] - (1/4)*b^2*f^a*ExpIntegralEi[(b*Log[f])/x^2]*Log[f]^2}
{f^(a + b/x^2)*x^1, x, 2, (1/2)*f^(a + b/x^2)*x^2 - (1/2)*b*f^a*ExpIntegralEi[(b*Log[f])/x^2]*Log[f]}
{f^(a + b/x^2)/x^1, x, 1, (-(1/2))*f^a*ExpIntegralEi[(b*Log[f])/x^2]}
{f^(a + b/x^2)/x^3, x, 1, -(f^(a + b/x^2)/(2*b*Log[f]))}
{f^(a + b/x^2)/x^5, x, 2, f^(a + b/x^2)/(2*b^2*Log[f]^2) - f^(a + b/x^2)/(2*b*x^2*Log[f])}
{f^(a + b/x^2)/x^7, x, 3, -(f^(a + b/x^2)/(b^3*Log[f]^3)) + f^(a + b/x^2)/(b^2*x^2*Log[f]^2) - f^(a + b/x^2)/(2*b*x^4*Log[f])}
{f^(a + b/x^2)/x^9, x, 4, (3*f^(a + b/x^2))/(b^4*Log[f]^4) - (3*f^(a + b/x^2))/(b^3*x^2*Log[f]^3) + (3*f^(a + b/x^2))/(2*b^2*x^4*Log[f]^2) - f^(a + b/x^2)/(2*b*x^6*Log[f])}
{f^(a + b/x^2)/x^11, x, 1, -((f^a*Gamma[5, -((b*Log[f])/x^2)])/(2*b^5*Log[f]^5))}
{f^(a + b/x^2)/x^13, x, 1, (f^a*Gamma[6, -((b*Log[f])/x^2)])/(2*b^6*Log[f]^6)}

{f^(a + b/x^2)*x^10, x, 1, (1/2)*f^a*x^11*Gamma[-(11/2), -((b*Log[f])/x^2)]*(-((b*Log[f])/x^2))^(11/2)}
{f^(a + b/x^2)*x^8, x, 1, (1/2)*f^a*x^9*Gamma[-(9/2), -((b*Log[f])/x^2)]*(-((b*Log[f])/x^2))^(9/2)}
{f^(a + b/x^2)*x^6, x, 6, (1/7)*f^(a + b/x^2)*x^7 + (2/35)*b*f^(a + b/x^2)*x^5*Log[f] + (4/105)*b^2*f^(a + b/x^2)*x^3*Log[f]^2 + (8/105)*b^3*f^(a + b/x^2)*x*Log[f]^3 - (8/105)*b^(7/2)*f^a*Sqrt[Pi]*Erfi[(Sqrt[b]*Sqrt[Log[f]])/x]*Log[f]^(7/2)}
{f^(a + b/x^2)*x^4, x, 5, (1/5)*f^(a + b/x^2)*x^5 + (2/15)*b*f^(a + b/x^2)*x^3*Log[f] + (4/15)*b^2*f^(a + b/x^2)*x*Log[f]^2 - (4/15)*b^(5/2)*f^a*Sqrt[Pi]*Erfi[(Sqrt[b]*Sqrt[Log[f]])/x]*Log[f]^(5/2)}
{f^(a + b/x^2)*x^2, x, 4, (1/3)*f^(a + b/x^2)*x^3 + (2/3)*b*f^(a + b/x^2)*x*Log[f] - (2/3)*b^(3/2)*f^a*Sqrt[Pi]*Erfi[(Sqrt[b]*Sqrt[Log[f]])/x]*Log[f]^(3/2)}
{f^(a + b/x^2)*x^0, x, 3, f^(a + b/x^2)*x - Sqrt[b]*f^a*Sqrt[Pi]*Erfi[(Sqrt[b]*Sqrt[Log[f]])/x]*Sqrt[Log[f]]}
{f^(a + b/x^2)/x^2, x, 2, -((f^a*Sqrt[Pi]*Erfi[(Sqrt[b]*Sqrt[Log[f]])/x])/(2*Sqrt[b]*Sqrt[Log[f]]))}
{f^(a + b/x^2)/x^4, x, 3, (f^a*Sqrt[Pi]*Erfi[(Sqrt[b]*Sqrt[Log[f]])/x])/(4*b^(3/2)*Log[f]^(3/2)) - f^(a + b/x^2)/(2*b*x*Log[f])}
{f^(a + b/x^2)/x^6, x, 4, -((3*f^a*Sqrt[Pi]*Erfi[(Sqrt[b]*Sqrt[Log[f]])/x])/(8*b^(5/2)*Log[f]^(5/2))) + (3*f^(a + b/x^2))/(4*b^2*x*Log[f]^2) - f^(a + b/x^2)/(2*b*x^3*Log[f])}
{f^(a + b/x^2)/x^8, x, 5, (15*f^a*Sqrt[Pi]*Erfi[(Sqrt[b]*Sqrt[Log[f]])/x])/(16*b^(7/2)*Log[f]^(7/2)) - (15*f^(a + b/x^2))/(8*b^3*x*Log[f]^3) + (5*f^(a + b/x^2))/(4*b^2*x^3*Log[f]^2) - f^(a + b/x^2)/(2*b*x^5*Log[f])}
{f^(a + b/x^2)/x^10, x, 6, -((105*f^a*Sqrt[Pi]*Erfi[(Sqrt[b]*Sqrt[Log[f]])/x])/(32*b^(9/2)*Log[f]^(9/2))) + (105*f^(a + b/x^2))/(16*b^4*x*Log[f]^4) - (35*f^(a + b/x^2))/(8*b^3*x^3*Log[f]^3) + (7*f^(a + b/x^2))/(4*b^2*x^5*Log[f]^2) - f^(a + b/x^2)/(2*b*x^7*Log[f])}
{f^(a + b/x^2)/x^12, x, 1, (f^a*Gamma[11/2, -((b*Log[f])/x^2)])/(2*x^11*(-((b*Log[f])/x^2))^(11/2))}
{f^(a + b/x^2)/x^14, x, 1, (f^a*Gamma[13/2, -((b*Log[f])/x^2)])/(2*x^13*(-((b*Log[f])/x^2))^(13/2))}


{f^(a + b/x^3)*x^m, x, 1, (1/3)*f^a*x^(1 + m)*Gamma[(1/3)*(-1 - m), -((b*Log[f])/x^3)]*(-((b*Log[f])/x^3))^((1 + m)/3)}

{f^(a + b/x^3)*x^14, x, 1, (-(1/3))*b^5*f^a*Gamma[-5, -((b*Log[f])/x^3)]*Log[f]^5}
{f^(a + b/x^3)*x^11, x, 1, (1/3)*b^4*f^a*Gamma[-4, -((b*Log[f])/x^3)]*Log[f]^4}
{f^(a + b/x^3)*x^8, x, 4, (1/9)*f^(a + b/x^3)*x^9 + (1/18)*b*f^(a + b/x^3)*x^6*Log[f] + (1/18)*b^2*f^(a + b/x^3)*x^3*Log[f]^2 - (1/18)*b^3*f^a*ExpIntegralEi[(b*Log[f])/x^3]*Log[f]^3}
{f^(a + b/x^3)*x^5, x, 3, (1/6)*f^(a + b/x^3)*x^6 + (1/6)*b*f^(a + b/x^3)*x^3*Log[f] - (1/6)*b^2*f^a*ExpIntegralEi[(b*Log[f])/x^3]*Log[f]^2}
{f^(a + b/x^3)*x^2, x, 2, (1/3)*f^(a + b/x^3)*x^3 - (1/3)*b*f^a*ExpIntegralEi[(b*Log[f])/x^3]*Log[f]}
{f^(a + b/x^3)/x^1, x, 1, (-(1/3))*f^a*ExpIntegralEi[(b*Log[f])/x^3]}
{f^(a + b/x^3)/x^4, x, 1, -(f^(a + b/x^3)/(3*b*Log[f]))}
{f^(a + b/x^3)/x^7, x, 2, f^(a + b/x^3)/(3*b^2*Log[f]^2) - f^(a + b/x^3)/(3*b*x^3*Log[f])}
{f^(a + b/x^3)/x^10, x, 3, -((2*f^(a + b/x^3))/(3*b^3*Log[f]^3)) + (2*f^(a + b/x^3))/(3*b^2*x^3*Log[f]^2) - f^(a + b/x^3)/(3*b*x^6*Log[f])}
{f^(a + b/x^3)/x^13, x, 4, (2*f^(a + b/x^3))/(b^4*Log[f]^4) - (2*f^(a + b/x^3))/(b^3*x^3*Log[f]^3) + f^(a + b/x^3)/(b^2*x^6*Log[f]^2) - f^(a + b/x^3)/(3*b*x^9*Log[f])}
{f^(a + b/x^3)/x^16, x, 1, -((f^a*Gamma[5, -((b*Log[f])/x^3)])/(3*b^5*Log[f]^5))}
{f^(a + b/x^3)/x^19, x, 1, (f^a*Gamma[6, -((b*Log[f])/x^3)])/(3*b^6*Log[f]^6)}

{f^(a + b/x^3)*x^4, x, 1, (1/3)*f^a*x^5*Gamma[-(5/3), -((b*Log[f])/x^3)]*(-((b*Log[f])/x^3))^(5/3)}
{f^(a + b/x^3)*x^3, x, 1, (1/3)*f^a*x^4*Gamma[-(4/3), -((b*Log[f])/x^3)]*(-((b*Log[f])/x^3))^(4/3)}
{f^(a + b/x^3)*x^1, x, 1, (1/3)*f^a*x^2*Gamma[-(2/3), -((b*Log[f])/x^3)]*(-((b*Log[f])/x^3))^(2/3)}
{f^(a + b/x^3)*x^0, x, 1, (1/3)*f^a*x*Gamma[-(1/3), -((b*Log[f])/x^3)]*(-((b*Log[f])/x^3))^(1/3)}
{f^(a + b/x^3)/x^2, x, 1, (f^a*Gamma[1/3, -((b*Log[f])/x^3)])/(3*x*(-((b*Log[f])/x^3))^(1/3))}
{f^(a + b/x^3)/x^3, x, 1, (f^a*Gamma[2/3, -((b*Log[f])/x^3)])/(3*x^2*(-((b*Log[f])/x^3))^(2/3))}
{f^(a + b/x^3)/x^5, x, 1, (f^a*Gamma[4/3, -((b*Log[f])/x^3)])/(3*x^4*(-((b*Log[f])/x^3))^(4/3))}


(* ::Subsubsection::Closed:: *)
(*n symbolic*)


{f^(a + b*x^n)*x^m, x, 1, -((f^a*x^(1 + m)*Gamma[(1 + m)/n, (-b)*x^n*Log[f]])/(((-b)*x^n*Log[f])^((1 + m)/n)*n))}

{f^(a + b*x^n)*x^3, x, 1, -((f^a*x^4*Gamma[4/n, (-b)*x^n*Log[f]])/(((-b)*x^n*Log[f])^(4/n)*n))}
{f^(a + b*x^n)*x^2, x, 1, -((f^a*x^3*Gamma[3/n, (-b)*x^n*Log[f]])/(((-b)*x^n*Log[f])^(3/n)*n))}
{f^(a + b*x^n)*x^1, x, 1, -((f^a*x^2*Gamma[2/n, (-b)*x^n*Log[f]])/(((-b)*x^n*Log[f])^(2/n)*n))}
{f^(a + b*x^n)*x^0, x, 1, -((f^a*x*Gamma[1/n, (-b)*x^n*Log[f]])/(((-b)*x^n*Log[f])^n^(-1)*n))}
{f^(a + b*x^n)/x^1, x, 1, (f^a*ExpIntegralEi[b*x^n*Log[f]])/n}
{f^(a + b*x^n)/x^2, x, 1, -((f^a*Gamma[-(1/n), (-b)*x^n*Log[f]]*((-b)*x^n*Log[f])^(1/n))/(n*x))}
{f^(a + b*x^n)/x^3, x, 1, -((f^a*Gamma[-(2/n), (-b)*x^n*Log[f]]*((-b)*x^n*Log[f])^(2/n))/(n*x^2))}
{f^(a + b*x^n)/x^4, x, 1, -((f^a*Gamma[-(3/n), (-b)*x^n*Log[f]]*((-b)*x^n*Log[f])^(3/n))/(n*x^3))}


{f^(a + b*x^n)*x^(6*n/2-1), x, 3, (2*f^(a + b*x^n))/(b^3*n*Log[f]^3) - (2*f^(a + b*x^n)*x^n)/(b^2*n*Log[f]^2) + (f^(a + b*x^n)*x^(2*n))/(b*n*Log[f])}
{f^(a + b*x^n)*x^(4*n/2-1), x, 2, -(f^(a + b*x^n)/(b^2*n*Log[f]^2)) + (f^(a + b*x^n)*x^n)/(b*n*Log[f])}
{f^(a + b*x^n)*x^(2*n/2-1), x, 1, f^(a + b*x^n)/(b*n*Log[f])}
{f^(a + b*x^n)*x^(0*n/2-1), x, 1, (f^a*ExpIntegralEi[b*x^n*Log[f]])/n}
{f^(a + b*x^n)*x^(-2*n/2-1), x, 2, -(f^(a + b*x^n)/(x^n*n)) + (b*f^a*ExpIntegralEi[b*x^n*Log[f]]*Log[f])/n}
{f^(a + b*x^n)*x^(-4*n/2-1), x, 3, -(f^(a + b*x^n)/(x^(2*n)*(2*n))) - (b*f^(a + b*x^n)*Log[f])/(x^n*(2*n)) + (b^2*f^a*ExpIntegralEi[b*x^n*Log[f]]*Log[f]^2)/(2*n)}

{f^(a + b*x^n)*x^(5*n/2-1), x, 4, (3*f^a*Sqrt[Pi]*Erfi[Sqrt[b]*x^(n/2)*Sqrt[Log[f]]])/(4*b^(5/2)*n*Log[f]^(5/2)) - (3*f^(a + b*x^n)*x^(n/2))/(2*b^2*n*Log[f]^2) + (f^(a + b*x^n)*x^((3*n)/2))/(b*n*Log[f])}
{f^(a + b*x^n)*x^(3*n/2-1), x, 3, -((f^a*Sqrt[Pi]*Erfi[Sqrt[b]*x^(n/2)*Sqrt[Log[f]]])/(2*b^(3/2)*n*Log[f]^(3/2))) + (f^(a + b*x^n)*x^(n/2))/(b*n*Log[f])}
{f^(a + b*x^n)*x^(1*n/2-1), x, 2, (f^a*Sqrt[Pi]*Erfi[Sqrt[b]*x^(n/2)*Sqrt[Log[f]]])/(Sqrt[b]*n*Sqrt[Log[f]])}
{f^(a + b*x^n)*x^(-1*n/2-1), x, 3, -((2*f^(a + b*x^n))/(x^(n/2)*n)) + (2*Sqrt[b]*f^a*Sqrt[Pi]*Erfi[Sqrt[b]*x^(n/2)*Sqrt[Log[f]]]*Sqrt[Log[f]])/n}
{f^(a + b*x^n)*x^(-3*n/2-1), x, 4, -((2*f^(a + b*x^n))/(x^((3*n)/2)*(3*n))) - (4*b*f^(a + b*x^n)*Log[f])/(x^(n/2)*(3*n)) + (4*b^(3/2)*f^a*Sqrt[Pi]*Erfi[Sqrt[b]*x^(n/2)*Sqrt[Log[f]]]*Log[f]^(3/2))/(3*n)}


{x/E^(0.1*x), x, 2, -100./E^(0.1*x) - (10.*x)/E^(0.1*x)}


(* ::Subsection::Closed:: *)
(*Integrands of the form x^m f^(c (a+b x)^n)*)


(* ::Subsubsection::Closed:: *)
(*n>0*)


{f^(c*(a + b*x))*x^m, x, 1, (-f^(a*c))*x^(1 + m)*Gamma[1 + m, (-b)*c*x*Log[f]]*((-b)*c*x*Log[f])^(-1 - m)}

{f^(c*(a + b*x))*x^5, x, 1, -((f^(a*c)*Gamma[6, (-b)*c*x*Log[f]])/(b^6*c^6*Log[f]^6))}
{f^(c*(a + b*x))*x^4, x, 1, (f^(a*c)*Gamma[5, (-b)*c*x*Log[f]])/(b^5*c^5*Log[f]^5)}
{f^(c*(a + b*x))*x^3, x, 4, -((6*f^(c*(a + b*x)))/(b^4*c^4*Log[f]^4)) + (6*f^(c*(a + b*x))*x)/(b^3*c^3*Log[f]^3) - (3*f^(c*(a + b*x))*x^2)/(b^2*c^2*Log[f]^2) + (f^(c*(a + b*x))*x^3)/(b*c*Log[f])}
{f^(c*(a + b*x))*x^2, x, 3, (2*f^(c*(a + b*x)))/(b^3*c^3*Log[f]^3) - (2*f^(c*(a + b*x))*x)/(b^2*c^2*Log[f]^2) + (f^(c*(a + b*x))*x^2)/(b*c*Log[f])}
{f^(c*(a + b*x))*x^1, x, 2, -(f^(c*(a + b*x))/(b^2*c^2*Log[f]^2)) + (f^(c*(a + b*x))*x)/(b*c*Log[f])}
{f^(c*(a + b*x))*x^0, x, 1, f^(c*(a + b*x))/(b*c*Log[f])}
{f^(c*(a + b*x))/x^1, x, 1, f^(a*c)*ExpIntegralEi[b*c*x*Log[f]]}
{f^(c*(a + b*x))/x^2, x, 2, -(f^(c*(a + b*x))/x) + b*c*f^(a*c)*ExpIntegralEi[b*c*x*Log[f]]*Log[f]}
{f^(c*(a + b*x))/x^3, x, 3, -(f^(c*(a + b*x))/(2*x^2)) - (b*c*f^(c*(a + b*x))*Log[f])/(2*x) + (1/2)*b^2*c^2*f^(a*c)*ExpIntegralEi[b*c*x*Log[f]]*Log[f]^2}
{f^(c*(a + b*x))/x^4, x, 1, b^3*c^3*f^(a*c)*Gamma[-3, (-b)*c*x*Log[f]]*Log[f]^3}
{f^(c*(a + b*x))/x^5, x, 1, (-b^4)*c^4*f^(a*c)*Gamma[-4, (-b)*c*x*Log[f]]*Log[f]^4}


{f^(c*(a + b*x)^2)*x^m, x, 0, Int[f^(c*(a + b*x)^2)*x^m, x]}

{f^(c*(a + b*x)^2)*x^3, x, 7, -(f^(c*(a + b*x)^2)/(2*b^4*c^2*Log[f]^2)) + (3*a*Sqrt[Pi]*Erfi[Sqrt[c]*(a + b*x)*Sqrt[Log[f]]])/(4*b^4*c^(3/2)*Log[f]^(3/2)) + (a^2*f^(c*(a + b*x)^2))/(2*b^4*c*Log[f]) - (a*f^(c*(a + b*x)^2)*x)/(2*b^3*c*Log[f]) + (f^(c*(a + b*x)^2)*x^2)/(2*b^2*c*Log[f]) - (a^3*Sqrt[Pi]*Erfi[Sqrt[c]*(a + b*x)*Sqrt[Log[f]]])/(2*b^4*Sqrt[c]*Sqrt[Log[f]])}
{f^(c*(a + b*x)^2)*x^2, x, 4, -((Sqrt[Pi]*Erfi[Sqrt[c]*(a + b*x)*Sqrt[Log[f]]])/(4*b^3*c^(3/2)*Log[f]^(3/2))) - (a*f^(c*(a + b*x)^2))/(2*b^3*c*Log[f]) + (f^(c*(a + b*x)^2)*x)/(2*b^2*c*Log[f]) + (a^2*Sqrt[Pi]*Erfi[Sqrt[c]*(a + b*x)*Sqrt[Log[f]]])/(2*b^3*Sqrt[c]*Sqrt[Log[f]])}
{f^(c*(a + b*x)^2)*x^1, x, 2, f^(c*(a + b*x)^2)/(2*b^2*c*Log[f]) - (a*Sqrt[Pi]*Erfi[Sqrt[c]*(a + b*x)*Sqrt[Log[f]]])/(2*b^2*Sqrt[c]*Sqrt[Log[f]])}
{f^(c*(a + b*x)^2)*x^0, x, 1, (Sqrt[Pi]*Erfi[Sqrt[c]*(a + b*x)*Sqrt[Log[f]]])/(2*b*Sqrt[c]*Sqrt[Log[f]])}
{f^(c*(a + b*x)^2)/x^1, x, 0, Int[f^(c*(a + b*x)^2)/x, x]}
{f^(c*(a + b*x)^2)/x^2, x, 2, -(f^(c*(a + b*x)^2)/x) + b*Sqrt[c]*Sqrt[Pi]*Erfi[Sqrt[c]*(a + b*x)*Sqrt[Log[f]]]*Sqrt[Log[f]] + 2*a*b*c*Log[f]*Int[f^(c*(a + b*x)^2)/x, x]}
{f^(c*(a + b*x)^2)/x^3, x, 3, -(f^(c*(a + b*x)^2)/(2*x^2)) - (a*b*c*f^(c*(a + b*x)^2)*Log[f])/x + a*b^2*c^(3/2)*Sqrt[Pi]*Erfi[Sqrt[c]*(a + b*x)*Sqrt[Log[f]]]*Log[f]^(3/2) + b^2*c*Log[f]*Int[f^(c*(a + b*x)^2)/x, x] + 2*a^2*b^2*c^2*Log[f]^2*Int[f^(c*(a + b*x)^2)/x, x]}


{f^(c*(a + b*x)^3)*x^m, x, 0, Int[f^(c*(a + b*x)^3)*x^m, x]}

{f^(c*(a + b*x)^3)*x^2, x, 5, f^(c*(a + b*x)^3)/(3*b^3*c*Log[f]) + (2*a*(a + b*x)^2*Gamma[2/3, (-c)*(a + b*x)^3*Log[f]])/(3*b^3*((-c)*(a + b*x)^3*Log[f])^(2/3)) - (a^2*(a + b*x)*Gamma[1/3, (-c)*(a + b*x)^3*Log[f]])/(3*b^3*((-c)*(a + b*x)^3*Log[f])^(1/3))}
{f^(c*(a + b*x)^3)*x^1, x, 4, -(((a + b*x)^2*Gamma[2/3, (-c)*(a + b*x)^3*Log[f]])/(3*b^2*((-c)*(a + b*x)^3*Log[f])^(2/3))) + (a*(a + b*x)*Gamma[1/3, (-c)*(a + b*x)^3*Log[f]])/(3*b^2*((-c)*(a + b*x)^3*Log[f])^(1/3))}
{f^(c*(a + b*x)^3)*x^0, x, 1, -(((a + b*x)*Gamma[1/3, (-c)*(a + b*x)^3*Log[f]])/(3*b*((-c)*(a + b*x)^3*Log[f])^(1/3)))}
{f^(c*(a + b*x)^3)/x^1, x, 0, Int[f^(c*(a + b*x)^3)/x, x]}
{f^(c*(a + b*x)^3)/x^2, x, 5, -(f^(c*(a + b*x)^3)/x) - (b*c*(a + b*x)^2*Gamma[2/3, (-c)*(a + b*x)^3*Log[f]]*Log[f])/((-c)*(a + b*x)^3*Log[f])^(2/3) - (a*b*c*(a + b*x)*Gamma[1/3, (-c)*(a + b*x)^3*Log[f]]*Log[f])/((-c)*(a + b*x)^3*Log[f])^(1/3) + 3*a^2*b*c*Log[f]*Int[f^(c*(a + b*x)^3)/x, x]}
{f^(c*(a + b*x)^3)/x^3, x, 9, -(f^(c*(a + b*x)^3)/(2*x^2)) - (3*a^2*b*c*f^(c*(a + b*x)^3)*Log[f])/(2*x) - (3*a^2*b^2*c^2*(a + b*x)^2*Gamma[2/3, (-c)*(a + b*x)^3*Log[f]]*Log[f]^2)/(2*((-c)*(a + b*x)^3*Log[f])^(2/3)) - (b^2*c*(a + b*x)*Gamma[1/3, (-c)*(a + b*x)^3*Log[f]]*Log[f])/(2*((-c)*(a + b*x)^3*Log[f])^(1/3)) - (3*a^3*b^2*c^2*(a + b*x)*Gamma[1/3, (-c)*(a + b*x)^3*Log[f]]*Log[f]^2)/(2*((-c)*(a + b*x)^3*Log[f])^(1/3)) + 3*a*b^2*c*Log[f]*Int[f^(c*(a + b*x)^3)/x, x] + (9/2)*a^4*b^2*c^2*Log[f]^2*Int[f^(c*(a + b*x)^3)/x, x]}


{f^(2 + 5*x), x, 1, f^(2 + 5*x)/(5*Log[f])}
{f^(a + b*x), x, 1, f^(a + b*x)/(b*Log[f])}
{10^(2 + 5*x), x, 1, (2^(2 + 5*x)*5^(1 + 5*x))/Log[10]}

{E^Sqrt[5 + 3*x], x, 3, (-(2/3))*E^Sqrt[5 + 3*x] + (2/3)*E^Sqrt[5 + 3*x]*Sqrt[5 + 3*x]}


(* ::Subsubsection::Closed:: *)
(*n<0*)


{f^(c/(a + b*x))*x^m, x, 0, Int[f^(c/(a + b*x))*x^m, x]}

{f^(c/(a + b*x))*x^4, x, 8, (a^4*f^(c/(a + b*x))*(a + b*x))/b^5 - (a^4*c*ExpIntegralEi[(c*Log[f])/(a + b*x)]*Log[f])/b^5 - (4*a^3*c^2*Gamma[-2, -((c*Log[f])/(a + b*x))]*Log[f]^2)/b^5 - (6*a^2*c^3*Gamma[-3, -((c*Log[f])/(a + b*x))]*Log[f]^3)/b^5 - (4*a*c^4*Gamma[-4, -((c*Log[f])/(a + b*x))]*Log[f]^4)/b^5 - (c^5*Gamma[-5, -((c*Log[f])/(a + b*x))]*Log[f]^5)/b^5}
{f^(c/(a + b*x))*x^3, x, 7, -((a^3*f^(c/(a + b*x))*(a + b*x))/b^4) + (a^3*c*ExpIntegralEi[(c*Log[f])/(a + b*x)]*Log[f])/b^4 + (3*a^2*c^2*Gamma[-2, -((c*Log[f])/(a + b*x))]*Log[f]^2)/b^4 + (3*a*c^3*Gamma[-3, -((c*Log[f])/(a + b*x))]*Log[f]^3)/b^4 + (c^4*Gamma[-4, -((c*Log[f])/(a + b*x))]*Log[f]^4)/b^4}
{f^(c/(a + b*x))*x^2, x, 6, (a^2*f^(c/(a + b*x))*(a + b*x))/b^3 - (a^2*c*ExpIntegralEi[(c*Log[f])/(a + b*x)]*Log[f])/b^3 - (2*a*c^2*Gamma[-2, -((c*Log[f])/(a + b*x))]*Log[f]^2)/b^3 - (c^3*Gamma[-3, -((c*Log[f])/(a + b*x))]*Log[f]^3)/b^3}
{f^(c/(a + b*x))*x^1, x, 5, -((a*f^(c/(a + b*x))*(a + b*x))/b^2) + (a*c*ExpIntegralEi[(c*Log[f])/(a + b*x)]*Log[f])/b^2 + (c^2*Gamma[-2, -((c*Log[f])/(a + b*x))]*Log[f]^2)/b^2}
{f^(c/(a + b*x))*x^0, x, 2, (f^(c/(a + b*x))*(a + b*x))/b - (c*ExpIntegralEi[(c*Log[f])/(a + b*x)]*Log[f])/b}
{f^(c/(a + b*x))/x^1, x, 4, -ExpIntegralEi[(c*Log[f])/(a + b*x)] + f^(c/a)*ExpIntegralEi[-((b*c*x*Log[f])/(a*(a + b*x)))]}
{f^(c/(a + b*x))/x^2, x, 9, -((b*f^(c/(a + b*x)))/a) - f^(c/(a + b*x))/x - (b*c*f^(c/a)*ExpIntegralEi[-((b*c*x*Log[f])/(a*(a + b*x)))]*Log[f])/a^2}
{f^(c/(a + b*x))/x^3, x, 18, (b^2*f^(c/(a + b*x)))/(2*a^2) - f^(c/(a + b*x))/(2*x^2) + (b^2*c*f^(c/(a + b*x))*Log[f])/(2*a^3) + (b*c*f^(c/(a + b*x))*Log[f])/(2*a^2*x) + (b^2*c*f^(c/a)*ExpIntegralEi[-((b*c*x*Log[f])/(a*(a + b*x)))]*Log[f])/a^3 + (b^2*c^2*f^(c/a)*ExpIntegralEi[-((b*c*x*Log[f])/(a*(a + b*x)))]*Log[f]^2)/(2*a^4)}


{f^(c/(a + b*x)^2)*x^m, x, 0, Int[f^(c/(a + b*x)^2)*x^m, x]}

{f^(c/(a + b*x)^2)*x^4, x, 9, (a^4*f^(c/(a + b*x)^2)*(a + b*x))/b^5 - (a^4*Sqrt[c]*Sqrt[Pi]*Erfi[(Sqrt[c]*Sqrt[Log[f]])/(a + b*x)]*Sqrt[Log[f]])/b^5 + (2*a^3*c*Gamma[-1, -((c*Log[f])/(a + b*x)^2)]*Log[f])/b^5 - (2*a*c^2*Gamma[-2, -((c*Log[f])/(a + b*x)^2)]*Log[f]^2)/b^5 + (3*a^2*(a + b*x)^3*Gamma[-(3/2), -((c*Log[f])/(a + b*x)^2)]*(-((c*Log[f])/(a + b*x)^2))^(3/2))/b^5 + ((a + b*x)^5*Gamma[-(5/2), -((c*Log[f])/(a + b*x)^2)]*(-((c*Log[f])/(a + b*x)^2))^(5/2))/(2*b^5)}
{f^(c/(a + b*x)^2)*x^3, x, 8, -((a^3*f^(c/(a + b*x)^2)*(a + b*x))/b^4) + (a^3*Sqrt[c]*Sqrt[Pi]*Erfi[(Sqrt[c]*Sqrt[Log[f]])/(a + b*x)]*Sqrt[Log[f]])/b^4 - (3*a^2*c*Gamma[-1, -((c*Log[f])/(a + b*x)^2)]*Log[f])/(2*b^4) + (c^2*Gamma[-2, -((c*Log[f])/(a + b*x)^2)]*Log[f]^2)/(2*b^4) - (3*a*(a + b*x)^3*Gamma[-(3/2), -((c*Log[f])/(a + b*x)^2)]*(-((c*Log[f])/(a + b*x)^2))^(3/2))/(2*b^4)}
{f^(c/(a + b*x)^2)*x^2, x, 7, (a^2*f^(c/(a + b*x)^2)*(a + b*x))/b^3 - (a^2*Sqrt[c]*Sqrt[Pi]*Erfi[(Sqrt[c]*Sqrt[Log[f]])/(a + b*x)]*Sqrt[Log[f]])/b^3 + (a*c*Gamma[-1, -((c*Log[f])/(a + b*x)^2)]*Log[f])/b^3 + ((a + b*x)^3*Gamma[-(3/2), -((c*Log[f])/(a + b*x)^2)]*(-((c*Log[f])/(a + b*x)^2))^(3/2))/(2*b^3)}
{f^(c/(a + b*x)^2)*x^1, x, 6, -((a*f^(c/(a + b*x)^2)*(a + b*x))/b^2) + (a*Sqrt[c]*Sqrt[Pi]*Erfi[(Sqrt[c]*Sqrt[Log[f]])/(a + b*x)]*Sqrt[Log[f]])/b^2 - (c*Gamma[-1, -((c*Log[f])/(a + b*x)^2)]*Log[f])/(2*b^2)}
{f^(c/(a + b*x)^2)*x^0, x, 3, (f^(c/(a + b*x)^2)*(a + b*x))/b - (Sqrt[c]*Sqrt[Pi]*Erfi[(Sqrt[c]*Sqrt[Log[f]])/(a + b*x)]*Sqrt[Log[f]])/b}
{f^(c/(a + b*x)^2)/x^1, x, 0, Int[f^(c/(a + b*x)^2)/x, x]}
{f^(c/(a + b*x)^2)/x^2, x, 0, Int[f^(c/(a + b*x)^2)/x^2, x]}
{f^(c/(a + b*x)^2)/x^3, x, 0, Int[f^(c/(a + b*x)^2)/x^3, x]}


{f^(c/(a + b*x)^3)*x^m, x, 0, Int[f^(c/(a + b*x)^3)*x^m, x]}

{f^(c/(a + b*x)^3)*x^4, x, 7, -((2*a^2*c*Gamma[-1, -((c*Log[f])/(a + b*x)^3)]*Log[f])/b^5) + (a^4*(a + b*x)*Gamma[-(1/3), -((c*Log[f])/(a + b*x)^3)]*(-((c*Log[f])/(a + b*x)^3))^(1/3))/(3*b^5) - (4*a^3*(a + b*x)^2*Gamma[-(2/3), -((c*Log[f])/(a + b*x)^3)]*(-((c*Log[f])/(a + b*x)^3))^(2/3))/(3*b^5) - (4*a*(a + b*x)^4*Gamma[-(4/3), -((c*Log[f])/(a + b*x)^3)]*(-((c*Log[f])/(a + b*x)^3))^(4/3))/(3*b^5) + ((a + b*x)^5*Gamma[-(5/3), -((c*Log[f])/(a + b*x)^3)]*(-((c*Log[f])/(a + b*x)^3))^(5/3))/(3*b^5)}
{f^(c/(a + b*x)^3)*x^3, x, 6, (a*c*Gamma[-1, -((c*Log[f])/(a + b*x)^3)]*Log[f])/b^4 - (a^3*(a + b*x)*Gamma[-(1/3), -((c*Log[f])/(a + b*x)^3)]*(-((c*Log[f])/(a + b*x)^3))^(1/3))/(3*b^4) + (a^2*(a + b*x)^2*Gamma[-(2/3), -((c*Log[f])/(a + b*x)^3)]*(-((c*Log[f])/(a + b*x)^3))^(2/3))/b^4 + ((a + b*x)^4*Gamma[-(4/3), -((c*Log[f])/(a + b*x)^3)]*(-((c*Log[f])/(a + b*x)^3))^(4/3))/(3*b^4)}
{f^(c/(a + b*x)^3)*x^2, x, 5, -((c*Gamma[-1, -((c*Log[f])/(a + b*x)^3)]*Log[f])/(3*b^3)) + (a^2*(a + b*x)*Gamma[-(1/3), -((c*Log[f])/(a + b*x)^3)]*(-((c*Log[f])/(a + b*x)^3))^(1/3))/(3*b^3) - (2*a*(a + b*x)^2*Gamma[-(2/3), -((c*Log[f])/(a + b*x)^3)]*(-((c*Log[f])/(a + b*x)^3))^(2/3))/(3*b^3)}
{f^(c/(a + b*x)^3)*x^1, x, 4, -((a*(a + b*x)*Gamma[-(1/3), -((c*Log[f])/(a + b*x)^3)]*(-((c*Log[f])/(a + b*x)^3))^(1/3))/(3*b^2)) + ((a + b*x)^2*Gamma[-(2/3), -((c*Log[f])/(a + b*x)^3)]*(-((c*Log[f])/(a + b*x)^3))^(2/3))/(3*b^2)}
{f^(c/(a + b*x)^3)*x^0, x, 1, ((a + b*x)*Gamma[-(1/3), -((c*Log[f])/(a + b*x)^3)]*(-((c*Log[f])/(a + b*x)^3))^(1/3))/(3*b)}
{f^(c/(a + b*x)^3)/x^1, x, 0, Int[f^(c/(a + b*x)^3)/x, x]}
{f^(c/(a + b*x)^3)/x^2, x, 0, Int[f^(c/(a + b*x)^3)/x^2, x]}
{f^(c/(a + b*x)^3)/x^3, x, 0, Int[f^(c/(a + b*x)^3)/x^3, x]}


(* ::Subsubsection::Closed:: *)
(*n symbolic*)


{f^(c*(a + b*x)^n)*x^m, x, 0, Int[f^(c*(a + b*x)^n)*x^m, x]}

{f^(c*(a + b*x)^n)*x^3, x, 6, -(((a + b*x)^4*Gamma[4/n, (-c)*(a + b*x)^n*Log[f]])/(((-c)*(a + b*x)^n*Log[f])^(4/n)*(b^4*n))) + (3*a*(a + b*x)^3*Gamma[3/n, (-c)*(a + b*x)^n*Log[f]])/(((-c)*(a + b*x)^n*Log[f])^(3/n)*(b^4*n)) - (3*a^2*(a + b*x)^2*Gamma[2/n, (-c)*(a + b*x)^n*Log[f]])/(((-c)*(a + b*x)^n*Log[f])^(2/n)*(b^4*n)) + (a^3*(a + b*x)*Gamma[1/n, (-c)*(a + b*x)^n*Log[f]])/(((-c)*(a + b*x)^n*Log[f])^n^(-1)*(b^4*n))}
{f^(c*(a + b*x)^n)*x^2, x, 5, -(((a + b*x)^3*Gamma[3/n, (-c)*(a + b*x)^n*Log[f]])/(((-c)*(a + b*x)^n*Log[f])^(3/n)*(b^3*n))) + (2*a*(a + b*x)^2*Gamma[2/n, (-c)*(a + b*x)^n*Log[f]])/(((-c)*(a + b*x)^n*Log[f])^(2/n)*(b^3*n)) - (a^2*(a + b*x)*Gamma[1/n, (-c)*(a + b*x)^n*Log[f]])/(((-c)*(a + b*x)^n*Log[f])^n^(-1)*(b^3*n))}
{f^(c*(a + b*x)^n)*x^1, x, 4, -(((a + b*x)^2*Gamma[2/n, (-c)*(a + b*x)^n*Log[f]])/(((-c)*(a + b*x)^n*Log[f])^(2/n)*(b^2*n))) + (a*(a + b*x)*Gamma[1/n, (-c)*(a + b*x)^n*Log[f]])/(((-c)*(a + b*x)^n*Log[f])^n^(-1)*(b^2*n))}
{f^(c*(a + b*x)^n)*x^0, x, 1, -(((a + b*x)*Gamma[1/n, (-c)*(a + b*x)^n*Log[f]])/(((-c)*(a + b*x)^n*Log[f])^n^(-1)*(b*n)))}
{f^(c*(a + b*x)^n)/x^1, x, 0, Int[f^(c*(a + b*x)^n)/x, x]}
{f^(c*(a + b*x)^n)/x^2, x, 0, Int[f^(c*(a + b*x)^n)/x^2, x]}
{f^(c*(a + b*x)^n)/x^3, x, 0, Int[f^(c*(a + b*x)^n)/x^3, x]}


(* ::Subsection::Closed:: *)
(*Integrands of the form (c+d x)^m F^(a+b (c+d x)^n)*)


(* ::Subsubsection::Closed:: *)
(*n>0*)


{F^(a + b*(c + d*x))*(c + d*x)^m, x, 1, -((F^a*(c + d*x)^(1 + m)*Gamma[1 + m, (-b)*(c + d*x)*Log[F]]*((-b)*(c + d*x)*Log[F])^(-1 - m))/d)}

{F^(a + b*(c + d*x))*(c + d*x)^5, x, 1, -((F^a*Gamma[6, (-b)*(c + d*x)*Log[F]])/(b^6*d*Log[F]^6))}
{F^(a + b*(c + d*x))*(c + d*x)^4, x, 1, (F^a*Gamma[5, (-b)*(c + d*x)*Log[F]])/(b^5*d*Log[F]^5)}
{F^(a + b*(c + d*x))*(c + d*x)^3, x, 4, -((6*F^(a + b*(c + d*x)))/(b^4*d*Log[F]^4)) + (6*F^(a + b*(c + d*x))*(c + d*x))/(b^3*d*Log[F]^3) - (3*F^(a + b*(c + d*x))*(c + d*x)^2)/(b^2*d*Log[F]^2) + (F^(a + b*(c + d*x))*(c + d*x)^3)/(b*d*Log[F])}
{F^(a + b*(c + d*x))*(c + d*x)^2, x, 3, (2*F^(a + b*(c + d*x)))/(b^3*d*Log[F]^3) - (2*F^(a + b*(c + d*x))*(c + d*x))/(b^2*d*Log[F]^2) + (F^(a + b*(c + d*x))*(c + d*x)^2)/(b*d*Log[F])}
{F^(a + b*(c + d*x))*(c + d*x)^1, x, 2, -(F^(a + b*(c + d*x))/(b^2*d*Log[F]^2)) + (F^(a + b*(c + d*x))*(c + d*x))/(b*d*Log[F])}
{F^(a + b*(c + d*x))*(c + d*x)^0, x, 1, F^(a + b*(c + d*x))/(b*d*Log[F])}
{F^(a + b*(c + d*x))/(c + d*x)^1, x, 1, (F^a*ExpIntegralEi[b*(c + d*x)*Log[F]])/d}
{F^(a + b*(c + d*x))/(c + d*x)^2, x, 2, -(F^(a + b*(c + d*x))/(d*(c + d*x))) + (b*F^a*ExpIntegralEi[b*(c + d*x)*Log[F]]*Log[F])/d}
{F^(a + b*(c + d*x))/(c + d*x)^3, x, 3, -(F^(a + b*(c + d*x))/(2*d*(c + d*x)^2)) - (b*F^(a + b*(c + d*x))*Log[F])/(2*d*(c + d*x)) + (b^2*F^a*ExpIntegralEi[b*(c + d*x)*Log[F]]*Log[F]^2)/(2*d)}
{F^(a + b*(c + d*x))/(c + d*x)^4, x, 1, (b^3*F^a*Gamma[-3, (-b)*(c + d*x)*Log[F]]*Log[F]^3)/d}
{F^(a + b*(c + d*x))/(c + d*x)^5, x, 1, -((b^4*F^a*Gamma[-4, (-b)*(c + d*x)*Log[F]]*Log[F]^4)/d)}

{F^(a + b*(c + d*x))*(c + d*x)^(11/2), x, 1, -((F^a*(c + d*x)^(13/2)*Gamma[13/2, (-b)*(c + d*x)*Log[F]])/(d*((-b)*(c + d*x)*Log[F])^(13/2)))}
{F^(a + b*(c + d*x))*(c + d*x)^(9/2), x, 1, -((F^a*(c + d*x)^(11/2)*Gamma[11/2, (-b)*(c + d*x)*Log[F]])/(d*((-b)*(c + d*x)*Log[F])^(11/2)))}
{F^(a + b*(c + d*x))*(c + d*x)^(7/2), x, 6, (105*F^a*Sqrt[Pi]*Erfi[Sqrt[b]*Sqrt[c + d*x]*Sqrt[Log[F]]])/(16*b^(9/2)*d*Log[F]^(9/2)) - (105*F^(a + b*(c + d*x))*Sqrt[c + d*x])/(8*b^4*d*Log[F]^4) + (35*F^(a + b*(c + d*x))*(c + d*x)^(3/2))/(4*b^3*d*Log[F]^3) - (7*F^(a + b*(c + d*x))*(c + d*x)^(5/2))/(2*b^2*d*Log[F]^2) + (F^(a + b*(c + d*x))*(c + d*x)^(7/2))/(b*d*Log[F])}
{F^(a + b*(c + d*x))*(c + d*x)^(5/2), x, 5, -((15*F^a*Sqrt[Pi]*Erfi[Sqrt[b]*Sqrt[c + d*x]*Sqrt[Log[F]]])/(8*b^(7/2)*d*Log[F]^(7/2))) + (15*F^(a + b*(c + d*x))*Sqrt[c + d*x])/(4*b^3*d*Log[F]^3) - (5*F^(a + b*(c + d*x))*(c + d*x)^(3/2))/(2*b^2*d*Log[F]^2) + (F^(a + b*(c + d*x))*(c + d*x)^(5/2))/(b*d*Log[F])}
{F^(a + b*(c + d*x))*(c + d*x)^(3/2), x, 4, (3*F^a*Sqrt[Pi]*Erfi[Sqrt[b]*Sqrt[c + d*x]*Sqrt[Log[F]]])/(4*b^(5/2)*d*Log[F]^(5/2)) - (3*F^(a + b*(c + d*x))*Sqrt[c + d*x])/(2*b^2*d*Log[F]^2) + (F^(a + b*(c + d*x))*(c + d*x)^(3/2))/(b*d*Log[F])}
{F^(a + b*(c + d*x))*(c + d*x)^(1/2), x, 3, -((F^a*Sqrt[Pi]*Erfi[Sqrt[b]*Sqrt[c + d*x]*Sqrt[Log[F]]])/(2*b^(3/2)*d*Log[F]^(3/2))) + (F^(a + b*(c + d*x))*Sqrt[c + d*x])/(b*d*Log[F])}
{F^(a + b*(c + d*x))/(c + d*x)^(1/2), x, 2, (F^a*Sqrt[Pi]*Erfi[Sqrt[b]*Sqrt[c + d*x]*Sqrt[Log[F]]])/(Sqrt[b]*d*Sqrt[Log[F]])}
{F^(a + b*(c + d*x))/(c + d*x)^(3/2), x, 3, -((2*F^(a + b*(c + d*x)))/(d*Sqrt[c + d*x])) + (2*Sqrt[b]*F^a*Sqrt[Pi]*Erfi[Sqrt[b]*Sqrt[c + d*x]*Sqrt[Log[F]]]*Sqrt[Log[F]])/d}
{F^(a + b*(c + d*x))/(c + d*x)^(5/2), x, 4, -((2*F^(a + b*(c + d*x)))/(3*d*(c + d*x)^(3/2))) - (4*b*F^(a + b*(c + d*x))*Log[F])/(3*d*Sqrt[c + d*x]) + (4*b^(3/2)*F^a*Sqrt[Pi]*Erfi[Sqrt[b]*Sqrt[c + d*x]*Sqrt[Log[F]]]*Log[F]^(3/2))/(3*d)}
{F^(a + b*(c + d*x))/(c + d*x)^(7/2), x, 5, -((2*F^(a + b*(c + d*x)))/(5*d*(c + d*x)^(5/2))) - (4*b*F^(a + b*(c + d*x))*Log[F])/(15*d*(c + d*x)^(3/2)) - (8*b^2*F^(a + b*(c + d*x))*Log[F]^2)/(15*d*Sqrt[c + d*x]) + (8*b^(5/2)*F^a*Sqrt[Pi]*Erfi[Sqrt[b]*Sqrt[c + d*x]*Sqrt[Log[F]]]*Log[F]^(5/2))/(15*d)}
{F^(a + b*(c + d*x))/(c + d*x)^(9/2), x, 1, -((F^a*Gamma[-(7/2), (-b)*(c + d*x)*Log[F]]*((-b)*(c + d*x)*Log[F])^(7/2))/(d*(c + d*x)^(7/2)))}
{F^(a + b*(c + d*x))/(c + d*x)^(11/2), x, 1, -((F^a*Gamma[-(9/2), (-b)*(c + d*x)*Log[F]]*((-b)*(c + d*x)*Log[F])^(9/2))/(d*(c + d*x)^(9/2)))}


{F^(a + b*(c + d*x)^2)*(c + d*x)^m, x, 1, -((F^a*(c + d*x)^(1 + m)*Gamma[(1 + m)/2, (-b)*(c + d*x)^2*Log[F]]*((-b)*(c + d*x)^2*Log[F])^((1/2)*(-1 - m)))/(2*d))}

{F^(a + b*(c + d*x)^2)*(c + d*x)^11, x, 1, -((F^a*Gamma[6, (-b)*(c + d*x)^2*Log[F]])/(2*b^6*d*Log[F]^6))}
{F^(a + b*(c + d*x)^2)*(c + d*x)^9, x, 1, (F^a*Gamma[5, (-b)*(c + d*x)^2*Log[F]])/(2*b^5*d*Log[F]^5)}
{F^(a + b*(c + d*x)^2)*(c + d*x)^7, x, 4, -((3*F^(a + b*(c + d*x)^2))/(b^4*d*Log[F]^4)) + (3*F^(a + b*(c + d*x)^2)*(c + d*x)^2)/(b^3*d*Log[F]^3) - (3*F^(a + b*(c + d*x)^2)*(c + d*x)^4)/(2*b^2*d*Log[F]^2) + (F^(a + b*(c + d*x)^2)*(c + d*x)^6)/(2*b*d*Log[F])}
{F^(a + b*(c + d*x)^2)*(c + d*x)^5, x, 3, F^(a + b*(c + d*x)^2)/(b^3*d*Log[F]^3) - (F^(a + b*(c + d*x)^2)*(c + d*x)^2)/(b^2*d*Log[F]^2) + (F^(a + b*(c + d*x)^2)*(c + d*x)^4)/(2*b*d*Log[F])}
{F^(a + b*(c + d*x)^2)*(c + d*x)^3, x, 2, -(F^(a + b*(c + d*x)^2)/(2*b^2*d*Log[F]^2)) + (F^(a + b*(c + d*x)^2)*(c + d*x)^2)/(2*b*d*Log[F])}
{F^(a + b*(c + d*x)^2)*(c + d*x)^1, x, 1, F^(a + b*(c + d*x)^2)/(2*b*d*Log[F])}
{F^(a + b*(c + d*x)^2)/(c + d*x)^1, x, 1, (F^a*ExpIntegralEi[b*(c + d*x)^2*Log[F]])/(2*d)}
{F^(a + b*(c + d*x)^2)/(c + d*x)^3, x, 1, (b*F^a*Gamma[-1, (-b)*(c + d*x)^2*Log[F]]*Log[F])/(2*d)}
{F^(a + b*(c + d*x)^2)/(c + d*x)^5, x, 1, -((b^2*F^a*Gamma[-2, (-b)*(c + d*x)^2*Log[F]]*Log[F]^2)/(2*d))}

{F^(a + b*(c + d*x)^2)*(c + d*x)^12, x, 1, -((F^a*(c + d*x)^13*Gamma[13/2, (-b)*(c + d*x)^2*Log[F]])/(2*d*((-b)*(c + d*x)^2*Log[F])^(13/2)))}
{F^(a + b*(c + d*x)^2)*(c + d*x)^10, x, 1, -((F^a*(c + d*x)^11*Gamma[11/2, (-b)*(c + d*x)^2*Log[F]])/(2*d*((-b)*(c + d*x)^2*Log[F])^(11/2)))}
{F^(a + b*(c + d*x)^2)*(c + d*x)^8, x, 5, (105*F^a*Sqrt[Pi]*Erfi[Sqrt[b]*(c + d*x)*Sqrt[Log[F]]])/(32*b^(9/2)*d*Log[F]^(9/2)) - (105*F^(a + b*(c + d*x)^2)*(c + d*x))/(16*b^4*d*Log[F]^4) + (35*F^(a + b*(c + d*x)^2)*(c + d*x)^3)/(8*b^3*d*Log[F]^3) - (7*F^(a + b*(c + d*x)^2)*(c + d*x)^5)/(4*b^2*d*Log[F]^2) + (F^(a + b*(c + d*x)^2)*(c + d*x)^7)/(2*b*d*Log[F])}
{F^(a + b*(c + d*x)^2)*(c + d*x)^6, x, 4, -((15*F^a*Sqrt[Pi]*Erfi[Sqrt[b]*(c + d*x)*Sqrt[Log[F]]])/(16*b^(7/2)*d*Log[F]^(7/2))) + (15*F^(a + b*(c + d*x)^2)*(c + d*x))/(8*b^3*d*Log[F]^3) - (5*F^(a + b*(c + d*x)^2)*(c + d*x)^3)/(4*b^2*d*Log[F]^2) + (F^(a + b*(c + d*x)^2)*(c + d*x)^5)/(2*b*d*Log[F])}
{F^(a + b*(c + d*x)^2)*(c + d*x)^4, x, 3, (3*F^a*Sqrt[Pi]*Erfi[Sqrt[b]*(c + d*x)*Sqrt[Log[F]]])/(8*b^(5/2)*d*Log[F]^(5/2)) - (3*F^(a + b*(c + d*x)^2)*(c + d*x))/(4*b^2*d*Log[F]^2) + (F^(a + b*(c + d*x)^2)*(c + d*x)^3)/(2*b*d*Log[F])}
{F^(a + b*(c + d*x)^2)*(c + d*x)^2, x, 2, -((F^a*Sqrt[Pi]*Erfi[Sqrt[b]*(c + d*x)*Sqrt[Log[F]]])/(4*b^(3/2)*d*Log[F]^(3/2))) + (F^(a + b*(c + d*x)^2)*(c + d*x))/(2*b*d*Log[F])}
{F^(a + b*(c + d*x)^2)*(c + d*x)^0, x, 1, (F^a*Sqrt[Pi]*Erfi[Sqrt[b]*(c + d*x)*Sqrt[Log[F]]])/(2*Sqrt[b]*d*Sqrt[Log[F]])}
{F^(a + b*(c + d*x)^2)/(c + d*x)^2, x, 1, -(F^(a + b*(c + d*x)^2)/(d*(c + d*x))) + (Sqrt[b]*F^a*Sqrt[Pi]*Erfi[Sqrt[b]*(c + d*x)*Sqrt[Log[F]]]*Sqrt[Log[F]])/d, -((F^a*Gamma[-(1/2), (-b)*(c + d*x)^2*Log[F]]*Sqrt[(-b)*(c + d*x)^2*Log[F]])/(2*d*(c + d*x)))}
{F^(a + b*(c + d*x)^2)/(c + d*x)^4, x, 1, -((F^a*Gamma[-(3/2), (-b)*(c + d*x)^2*Log[F]]*((-b)*(c + d*x)^2*Log[F])^(3/2))/(2*d*(c + d*x)^3))}


{F^(a + b*(c + d*x)^3)*(c + d*x)^m, x, 1, -((F^a*(c + d*x)^(1 + m)*Gamma[(1 + m)/3, (-b)*(c + d*x)^3*Log[F]]*((-b)*(c + d*x)^3*Log[F])^((1/3)*(-1 - m)))/(3*d))}

{F^(a + b*(c + d*x)^3)*(c + d*x)^17, x, 1, -((F^a*Gamma[6, (-b)*(c + d*x)^3*Log[F]])/(3*b^6*d*Log[F]^6))}
{F^(a + b*(c + d*x)^3)*(c + d*x)^14, x, 1, (F^a*Gamma[5, (-b)*(c + d*x)^3*Log[F]])/(3*b^5*d*Log[F]^5)}
{F^(a + b*(c + d*x)^3)*(c + d*x)^11, x, 4, -((2*F^(a + b*(c + d*x)^3))/(b^4*d*Log[F]^4)) + (2*F^(a + b*(c + d*x)^3)*(c + d*x)^3)/(b^3*d*Log[F]^3) - (F^(a + b*(c + d*x)^3)*(c + d*x)^6)/(b^2*d*Log[F]^2) + (F^(a + b*(c + d*x)^3)*(c + d*x)^9)/(3*b*d*Log[F])}
{F^(a + b*(c + d*x)^3)*(c + d*x)^8, x, 3, (2*F^(a + b*(c + d*x)^3))/(3*b^3*d*Log[F]^3) - (2*F^(a + b*(c + d*x)^3)*(c + d*x)^3)/(3*b^2*d*Log[F]^2) + (F^(a + b*(c + d*x)^3)*(c + d*x)^6)/(3*b*d*Log[F])}
{F^(a + b*(c + d*x)^3)*(c + d*x)^5, x, 2, -(F^(a + b*(c + d*x)^3)/(3*b^2*d*Log[F]^2)) + (F^(a + b*(c + d*x)^3)*(c + d*x)^3)/(3*b*d*Log[F])}
{F^(a + b*(c + d*x)^3)*(c + d*x)^2, x, 1, F^(a + b*(c + d*x)^3)/(3*b*d*Log[F])}
{F^(a + b*(c + d*x)^3)/(c + d*x)^1, x, 1, (F^a*ExpIntegralEi[b*(c + d*x)^3*Log[F]])/(3*d)}
{F^(a + b*(c + d*x)^3)/(c + d*x)^4, x, 1, (b*F^a*Gamma[-1, (-b)*(c + d*x)^3*Log[F]]*Log[F])/(3*d)}
{F^(a + b*(c + d*x)^3)/(c + d*x)^7, x, 1, -((b^2*F^a*Gamma[-2, (-b)*(c + d*x)^3*Log[F]]*Log[F]^2)/(3*d))}
{F^(a + b*(c + d*x)^3)/(c + d*x)^10, x, 1, (b^3*F^a*Gamma[-3, (-b)*(c + d*x)^3*Log[F]]*Log[F]^3)/(3*d)}

{F^(a + b*(c + d*x)^3)*(c + d*x)^3, x, 1, -((F^a*(c + d*x)^4*Gamma[4/3, (-b)*(c + d*x)^3*Log[F]])/(3*d*((-b)*(c + d*x)^3*Log[F])^(4/3)))}
{F^(a + b*(c + d*x)^3)*(c + d*x)^1, x, 1, -((F^a*(c + d*x)^2*Gamma[2/3, (-b)*(c + d*x)^3*Log[F]])/(3*d*((-b)*(c + d*x)^3*Log[F])^(2/3)))}
{F^(a + b*(c + d*x)^3)*(c + d*x)^0, x, 1, -((F^a*(c + d*x)*Gamma[1/3, (-b)*(c + d*x)^3*Log[F]])/(3*d*((-b)*(c + d*x)^3*Log[F])^(1/3)))}
{F^(a + b*(c + d*x)^3)/(c + d*x)^2, x, 1, -((F^a*Gamma[-(1/3), (-b)*(c + d*x)^3*Log[F]]*((-b)*(c + d*x)^3*Log[F])^(1/3))/(3*d*(c + d*x)))}
{F^(a + b*(c + d*x)^3)/(c + d*x)^3, x, 1, -((F^a*Gamma[-(2/3), (-b)*(c + d*x)^3*Log[F]]*((-b)*(c + d*x)^3*Log[F])^(2/3))/(3*d*(c + d*x)^2))}
{F^(a + b*(c + d*x)^3)/(c + d*x)^5, x, 1, -((F^a*Gamma[-(4/3), (-b)*(c + d*x)^3*Log[F]]*((-b)*(c + d*x)^3*Log[F])^(4/3))/(3*d*(c + d*x)^4))}


{f^(a + b*(c + d*x)^(1/2)), x, 3, -((2*f^(a + b*Sqrt[c + d*x]))/(b^2*d*Log[f]^2)) + (2*f^(a + b*Sqrt[c + d*x])*Sqrt[c + d*x])/(b*d*Log[f])}
{f^(a + b*(c + d*x)^(1/3)), x, 4, (6*f^(a + b*(c + d*x)^(1/3)))/(b^3*d*Log[f]^3) - (6*f^(a + b*(c + d*x)^(1/3))*(c + d*x)^(1/3))/(b^2*d*Log[f]^2) + (3*f^(a + b*(c + d*x)^(1/3))*(c + d*x)^(2/3))/(b*d*Log[f])}


(* ::Subsubsection::Closed:: *)
(*n<0*)


{F^(a + b/(c + d*x))*(c + d*x)^m, x, 1, (F^a*(c + d*x)^(1 + m)*Gamma[-1 - m, -((b*Log[F])/(c + d*x))]*(-((b*Log[F])/(c + d*x)))^(1 + m))/d}

{F^(a + b/(c + d*x))*(c + d*x)^3, x, 1, (b^4*F^a*Gamma[-4, -((b*Log[F])/(c + d*x))]*Log[F]^4)/d}
{F^(a + b/(c + d*x))*(c + d*x)^2, x, 1, -((b^3*F^a*Gamma[-3, -((b*Log[F])/(c + d*x))]*Log[F]^3)/d)}
{F^(a + b/(c + d*x))*(c + d*x)^1, x, 1, (b^2*F^a*Gamma[-2, -((b*Log[F])/(c + d*x))]*Log[F]^2)/d}
{F^(a + b/(c + d*x))*(c + d*x)^0, x, 2, (F^(a + b/(c + d*x))*(c + d*x))/d - (b*F^a*ExpIntegralEi[(b*Log[F])/(c + d*x)]*Log[F])/d}
{F^(a + b/(c + d*x))/(c + d*x)^1, x, 1, -((F^a*ExpIntegralEi[(b*Log[F])/(c + d*x)])/d)}
{F^(a + b/(c + d*x))/(c + d*x)^2, x, 1, -(F^(a + b/(c + d*x))/(b*d*Log[F]))}
{F^(a + b/(c + d*x))/(c + d*x)^3, x, 2, F^(a + b/(c + d*x))/(b^2*d*Log[F]^2) - F^(a + b/(c + d*x))/(b*d*(c + d*x)*Log[F])}
{F^(a + b/(c + d*x))/(c + d*x)^4, x, 3, -((2*F^(a + b/(c + d*x)))/(b^3*d*Log[F]^3)) + (2*F^(a + b/(c + d*x)))/(b^2*d*(c + d*x)*Log[F]^2) - F^(a + b/(c + d*x))/(b*d*(c + d*x)^2*Log[F])}
{F^(a + b/(c + d*x))/(c + d*x)^5, x, 4, (6*F^(a + b/(c + d*x)))/(b^4*d*Log[F]^4) - (6*F^(a + b/(c + d*x)))/(b^3*d*(c + d*x)*Log[F]^3) + (3*F^(a + b/(c + d*x)))/(b^2*d*(c + d*x)^2*Log[F]^2) - F^(a + b/(c + d*x))/(b*d*(c + d*x)^3*Log[F])}
{F^(a + b/(c + d*x))/(c + d*x)^6, x, 1, -((F^a*Gamma[5, -((b*Log[F])/(c + d*x))])/(b^5*d*Log[F]^5))}
{F^(a + b/(c + d*x))/(c + d*x)^7, x, 1, (F^a*Gamma[6, -((b*Log[F])/(c + d*x))])/(b^6*d*Log[F]^6)}


{F^(a + b/(c + d*x)^2)*(c + d*x)^m, x, 1, (F^a*(c + d*x)^(1 + m)*Gamma[(1/2)*(-1 - m), -((b*Log[F])/(c + d*x)^2)]*(-((b*Log[F])/(c + d*x)^2))^((1 + m)/2))/(2*d)}

{F^(a + b/(c + d*x)^2)*(c + d*x)^3, x, 1, (b^2*F^a*Gamma[-2, -((b*Log[F])/(c + d*x)^2)]*Log[F]^2)/(2*d)}
{F^(a + b/(c + d*x)^2)*(c + d*x)^1, x, 1, -((b*F^a*Gamma[-1, -((b*Log[F])/(c + d*x)^2)]*Log[F])/(2*d))}
{F^(a + b/(c + d*x)^2)/(c + d*x)^1, x, 1, -((F^a*ExpIntegralEi[(b*Log[F])/(c + d*x)^2])/(2*d))}
{F^(a + b/(c + d*x)^2)/(c + d*x)^3, x, 1, -(F^(a + b/(c + d*x)^2)/(2*b*d*Log[F]))}
{F^(a + b/(c + d*x)^2)/(c + d*x)^5, x, 2, F^(a + b/(c + d*x)^2)/(2*b^2*d*Log[F]^2) - F^(a + b/(c + d*x)^2)/(2*b*d*(c + d*x)^2*Log[F])}
{F^(a + b/(c + d*x)^2)/(c + d*x)^7, x, 3, -(F^(a + b/(c + d*x)^2)/(b^3*d*Log[F]^3)) + F^(a + b/(c + d*x)^2)/(b^2*d*(c + d*x)^2*Log[F]^2) - F^(a + b/(c + d*x)^2)/(2*b*d*(c + d*x)^4*Log[F])}
{F^(a + b/(c + d*x)^2)/(c + d*x)^9, x, 4, (3*F^(a + b/(c + d*x)^2))/(b^4*d*Log[F]^4) - (3*F^(a + b/(c + d*x)^2))/(b^3*d*(c + d*x)^2*Log[F]^3) + (3*F^(a + b/(c + d*x)^2))/(2*b^2*d*(c + d*x)^4*Log[F]^2) - F^(a + b/(c + d*x)^2)/(2*b*d*(c + d*x)^6*Log[F])}
{F^(a + b/(c + d*x)^2)/(c + d*x)^11, x, 1, -((F^a*Gamma[5, -((b*Log[F])/(c + d*x)^2)])/(2*b^5*d*Log[F]^5))}
{F^(a + b/(c + d*x)^2)/(c + d*x)^13, x, 1, (F^a*Gamma[6, -((b*Log[F])/(c + d*x)^2)])/(2*b^6*d*Log[F]^6)}

{F^(a + b/(c + d*x)^2)*(c + d*x)^4, x, 1, (F^a*(c + d*x)^5*Gamma[-(5/2), -((b*Log[F])/(c + d*x)^2)]*(-((b*Log[F])/(c + d*x)^2))^(5/2))/(2*d)}
{F^(a + b/(c + d*x)^2)*(c + d*x)^2, x, 1, (F^a*(c + d*x)^3*Gamma[-(3/2), -((b*Log[F])/(c + d*x)^2)]*(-((b*Log[F])/(c + d*x)^2))^(3/2))/(2*d)}
{F^(a + b/(c + d*x)^2)*(c + d*x)^0, x, 3, (F^(a + b/(c + d*x)^2)*(c + d*x))/d - (Sqrt[b]*F^a*Sqrt[Pi]*Erfi[(Sqrt[b]*Sqrt[Log[F]])/(c + d*x)]*Sqrt[Log[F]])/d}
{F^(a + b/(c + d*x)^2)/(c + d*x)^2, x, 2, -((F^a*Sqrt[Pi]*Erfi[(Sqrt[b]*Sqrt[Log[F]])/(c + d*x)])/(2*Sqrt[b]*d*Sqrt[Log[F]]))}
{F^(a + b/(c + d*x)^2)/(c + d*x)^4, x, 3, (F^a*Sqrt[Pi]*Erfi[(Sqrt[b]*Sqrt[Log[F]])/(c + d*x)])/(4*b^(3/2)*d*Log[F]^(3/2)) - F^(a + b/(c + d*x)^2)/(2*b*d*(c + d*x)*Log[F])}
{F^(a + b/(c + d*x)^2)/(c + d*x)^6, x, 4, -((3*F^a*Sqrt[Pi]*Erfi[(Sqrt[b]*Sqrt[Log[F]])/(c + d*x)])/(8*b^(5/2)*d*Log[F]^(5/2))) + (3*F^(a + b/(c + d*x)^2))/(4*b^2*d*(c + d*x)*Log[F]^2) - F^(a + b/(c + d*x)^2)/(2*b*d*(c + d*x)^3*Log[F])}
{F^(a + b/(c + d*x)^2)/(c + d*x)^8, x, 5, (15*F^a*Sqrt[Pi]*Erfi[(Sqrt[b]*Sqrt[Log[F]])/(c + d*x)])/(16*b^(7/2)*d*Log[F]^(7/2)) - (15*F^(a + b/(c + d*x)^2))/(8*b^3*d*(c + d*x)*Log[F]^3) + (5*F^(a + b/(c + d*x)^2))/(4*b^2*d*(c + d*x)^3*Log[F]^2) - F^(a + b/(c + d*x)^2)/(2*b*d*(c + d*x)^5*Log[F])}
{F^(a + b/(c + d*x)^2)/(c + d*x)^10, x, 6, -((105*F^a*Sqrt[Pi]*Erfi[(Sqrt[b]*Sqrt[Log[F]])/(c + d*x)])/(32*b^(9/2)*d*Log[F]^(9/2))) + (105*F^(a + b/(c + d*x)^2))/(16*b^4*d*(c + d*x)*Log[F]^4) - (35*F^(a + b/(c + d*x)^2))/(8*b^3*d*(c + d*x)^3*Log[F]^3) + (7*F^(a + b/(c + d*x)^2))/(4*b^2*d*(c + d*x)^5*Log[F]^2) - F^(a + b/(c + d*x)^2)/(2*b*d*(c + d*x)^7*Log[F])}
{F^(a + b/(c + d*x)^2)/(c + d*x)^12, x, 1, (F^a*Gamma[11/2, -((b*Log[F])/(c + d*x)^2)])/(2*d*(c + d*x)^11*(-((b*Log[F])/(c + d*x)^2))^(11/2))}
{F^(a + b/(c + d*x)^2)/(c + d*x)^14, x, 1, (F^a*Gamma[13/2, -((b*Log[F])/(c + d*x)^2)])/(2*d*(c + d*x)^13*(-((b*Log[F])/(c + d*x)^2))^(13/2))}


{F^(a + b/(c + d*x)^3)*(c + d*x)^m, x, 1, (F^a*(c + d*x)^(1 + m)*Gamma[(1/3)*(-1 - m), -((b*Log[F])/(c + d*x)^3)]*(-((b*Log[F])/(c + d*x)^3))^((1 + m)/3))/(3*d)}

{F^(a + b/(c + d*x)^3)*(c + d*x)^8, x, 1, -((b^3*F^a*Gamma[-3, -((b*Log[F])/(c + d*x)^3)]*Log[F]^3)/(3*d))}
{F^(a + b/(c + d*x)^3)*(c + d*x)^5, x, 1, (b^2*F^a*Gamma[-2, -((b*Log[F])/(c + d*x)^3)]*Log[F]^2)/(3*d)}
{F^(a + b/(c + d*x)^3)*(c + d*x)^2, x, 1, -((b*F^a*Gamma[-1, -((b*Log[F])/(c + d*x)^3)]*Log[F])/(3*d))}
{F^(a + b/(c + d*x)^3)/(c + d*x)^1, x, 1, -((F^a*ExpIntegralEi[(b*Log[F])/(c + d*x)^3])/(3*d))}
{F^(a + b/(c + d*x)^3)/(c + d*x)^4, x, 1, -(F^(a + b/(c + d*x)^3)/(3*b*d*Log[F]))}
{F^(a + b/(c + d*x)^3)/(c + d*x)^7, x, 2, F^(a + b/(c + d*x)^3)/(3*b^2*d*Log[F]^2) - F^(a + b/(c + d*x)^3)/(3*b*d*(c + d*x)^3*Log[F])}
{F^(a + b/(c + d*x)^3)/(c + d*x)^10, x, 3, -((2*F^(a + b/(c + d*x)^3))/(3*b^3*d*Log[F]^3)) + (2*F^(a + b/(c + d*x)^3))/(3*b^2*d*(c + d*x)^3*Log[F]^2) - F^(a + b/(c + d*x)^3)/(3*b*d*(c + d*x)^6*Log[F])}
{F^(a + b/(c + d*x)^3)/(c + d*x)^13, x, 4, (2*F^(a + b/(c + d*x)^3))/(b^4*d*Log[F]^4) - (2*F^(a + b/(c + d*x)^3))/(b^3*d*(c + d*x)^3*Log[F]^3) + F^(a + b/(c + d*x)^3)/(b^2*d*(c + d*x)^6*Log[F]^2) - F^(a + b/(c + d*x)^3)/(3*b*d*(c + d*x)^9*Log[F])}
{F^(a + b/(c + d*x)^3)/(c + d*x)^16, x, 1, -((F^a*Gamma[5, -((b*Log[F])/(c + d*x)^3)])/(3*b^5*d*Log[F]^5))}
{F^(a + b/(c + d*x)^3)/(c + d*x)^19, x, 1, (F^a*Gamma[6, -((b*Log[F])/(c + d*x)^3)])/(3*b^6*d*Log[F]^6)}

{F^(a + b/(c + d*x)^3)*(c + d*x)^3, x, 1, (F^a*(c + d*x)^4*Gamma[-(4/3), -((b*Log[F])/(c + d*x)^3)]*(-((b*Log[F])/(c + d*x)^3))^(4/3))/(3*d)}
{F^(a + b/(c + d*x)^3)*(c + d*x)^1, x, 1, (F^a*(c + d*x)^2*Gamma[-(2/3), -((b*Log[F])/(c + d*x)^3)]*(-((b*Log[F])/(c + d*x)^3))^(2/3))/(3*d)}
{F^(a + b/(c + d*x)^3)*(c + d*x)^0, x, 1, (F^a*(c + d*x)*Gamma[-(1/3), -((b*Log[F])/(c + d*x)^3)]*(-((b*Log[F])/(c + d*x)^3))^(1/3))/(3*d)}
{F^(a + b/(c + d*x)^3)/(c + d*x)^2, x, 1, (F^a*Gamma[1/3, -((b*Log[F])/(c + d*x)^3)])/(3*d*(c + d*x)*(-((b*Log[F])/(c + d*x)^3))^(1/3))}
{F^(a + b/(c + d*x)^3)/(c + d*x)^3, x, 1, (F^a*Gamma[2/3, -((b*Log[F])/(c + d*x)^3)])/(3*d*(c + d*x)^2*(-((b*Log[F])/(c + d*x)^3))^(2/3))}
{F^(a + b/(c + d*x)^3)/(c + d*x)^5, x, 1, (F^a*Gamma[4/3, -((b*Log[F])/(c + d*x)^3)])/(3*d*(c + d*x)^4*(-((b*Log[F])/(c + d*x)^3))^(4/3))}


(* ::Subsubsection::Closed:: *)
(*n symbolic*)


{F^(a + b*(c + d*x)^n)*(c + d*x)^m, x, 1, -((F^a*(c + d*x)^(1 + m)*Gamma[(1 + m)/n, (-b)*(c + d*x)^n*Log[F]])/(((-b)*(c + d*x)^n*Log[F])^((1 + m)/n)*(d*n)))}

{F^(a + b*(c + d*x)^n)*(c + d*x)^3, x, 1, -((F^a*(c + d*x)^4*Gamma[4/n, (-b)*(c + d*x)^n*Log[F]])/(((-b)*(c + d*x)^n*Log[F])^(4/n)*(d*n)))}
{F^(a + b*(c + d*x)^n)*(c + d*x)^2, x, 1, -((F^a*(c + d*x)^3*Gamma[3/n, (-b)*(c + d*x)^n*Log[F]])/(((-b)*(c + d*x)^n*Log[F])^(3/n)*(d*n)))}
{F^(a + b*(c + d*x)^n)*(c + d*x)^1, x, 1, -((F^a*(c + d*x)^2*Gamma[2/n, (-b)*(c + d*x)^n*Log[F]])/(((-b)*(c + d*x)^n*Log[F])^(2/n)*(d*n)))}
{F^(a + b*(c + d*x)^n)*(c + d*x)^0, x, 1, -((F^a*(c + d*x)*Gamma[1/n, (-b)*(c + d*x)^n*Log[F]])/(((-b)*(c + d*x)^n*Log[F])^n^(-1)*(d*n)))}
{F^(a + b*(c + d*x)^n)/(c + d*x)^1, x, 1, (F^a*ExpIntegralEi[b*(c + d*x)^n*Log[F]])/(d*n)}
{F^(a + b*(c + d*x)^n)/(c + d*x)^2, x, 1, -((F^a*Gamma[-(1/n), (-b)*(c + d*x)^n*Log[F]]*((-b)*(c + d*x)^n*Log[F])^(1/n))/(d*n*(c + d*x)))}
{F^(a + b*(c + d*x)^n)/(c + d*x)^3, x, 1, -((F^a*Gamma[-(2/n), (-b)*(c + d*x)^n*Log[F]]*((-b)*(c + d*x)^n*Log[F])^(2/n))/(d*n*(c + d*x)^2))}
{F^(a + b*(c + d*x)^n)/(c + d*x)^4, x, 1, -((F^a*Gamma[-(3/n), (-b)*(c + d*x)^n*Log[F]]*((-b)*(c + d*x)^n*Log[F])^(3/n))/(d*n*(c + d*x)^3))}


{F^(a + b*(c + d*x)^n)*(c + d*x)^(4*n - 1), x, 4, -((6*F^(a + b*(c + d*x)^n))/(b^4*d*n*Log[F]^4)) + (6*F^(a + b*(c + d*x)^n)*(c + d*x)^n)/(b^3*d*n*Log[F]^3) - (3*F^(a + b*(c + d*x)^n)*(c + d*x)^(2*n))/(b^2*d*n*Log[F]^2) + (F^(a + b*(c + d*x)^n)*(c + d*x)^(3*n))/(b*d*n*Log[F])}
{F^(a + b*(c + d*x)^n)*(c + d*x)^(3*n - 1), x, 3, (2*F^(a + b*(c + d*x)^n))/(b^3*d*n*Log[F]^3) - (2*F^(a + b*(c + d*x)^n)*(c + d*x)^n)/(b^2*d*n*Log[F]^2) + (F^(a + b*(c + d*x)^n)*(c + d*x)^(2*n))/(b*d*n*Log[F])}
{F^(a + b*(c + d*x)^n)*(c + d*x)^(2*n - 1), x, 2, -(F^(a + b*(c + d*x)^n)/(b^2*d*n*Log[F]^2)) + (F^(a + b*(c + d*x)^n)*(c + d*x)^n)/(b*d*n*Log[F])}
{F^(a + b*(c + d*x)^n)*(c + d*x)^(1*n - 1), x, 1, F^(a + b*(c + d*x)^n)/(b*d*n*Log[F])}
{F^(a + b*(c + d*x)^n)*(c + d*x)^(0*n - 1), x, 1, (F^a*ExpIntegralEi[b*(c + d*x)^n*Log[F]])/(d*n)}
{F^(a + b*(c + d*x)^n)*(c + d*x)^(-1*n - 1), x, 1, (b*F^a*Gamma[-1, (-b)*(c + d*x)^n*Log[F]]*Log[F])/(d*n)}
{F^(a + b*(c + d*x)^n)*(c + d*x)^(-2*n - 1), x, 1, -((b^2*F^a*Gamma[-2, (-b)*(c + d*x)^n*Log[F]]*Log[F]^2)/(d*n))}
{F^(a + b*(c + d*x)^n)*(c + d*x)^(-3*n - 1), x, 1, (b^3*F^a*Gamma[-3, (-b)*(c + d*x)^n*Log[F]]*Log[F]^3)/(d*n)}


{(a + b*x)^(n/2 - 1)*F^(c*(a + b*x)^n), x, 2, (Sqrt[Pi]*Erfi[Sqrt[c]*(a + b*x)^(n/2)*Sqrt[Log[F]]])/(b*Sqrt[c]*n*Sqrt[Log[F]])}
{(a + b*x)^(n/2 - 1)*F^(-c*(a + b*x)^n), x, 2, (Sqrt[Pi]*Erf[Sqrt[c]*(a + b*x)^(n/2)*Sqrt[Log[F]]])/(b*Sqrt[c]*n*Sqrt[Log[F]])}


(* ::Subsection::Closed:: *)
(*Integrands of the form (e+f x)^m F^(a+b (c+d x)^n)*)


(* ::Subsubsection::Closed:: *)
(*n>0*)


{E^(e*(c + d*x))*(a + b*x)^m, x, 1, -((E^((c - (a*d)/b)*e)*(a + b*x)^(1 + m)*(-((d*e*(a + b*x))/b))^(-1 - m)*Gamma[1 + m, -((d*e*(a + b*x))/b)])/b)}

{E^(e*(c + d*x))*(a + b*x)^4, x, 1, (b^4*E^((c - (a*d)/b)*e)*Gamma[5, -((d*e*(a + b*x))/b)])/(d^5*e^5)}
{E^(e*(c + d*x))*(a + b*x)^4, x, 1, (b^4*E^((c - (a*d)/b)*e)*Gamma[5, -((d*e*(a + b*x))/b)])/(d^5*e^5)}
{E^(e*(c + d*x))*(a + b*x)^3, x, 4, -((6*b^3*E^(e*(c + d*x)))/(d^4*e^4)) + (6*b^2*E^(e*(c + d*x))*(a + b*x))/(d^3*e^3) - (3*b*E^(e*(c + d*x))*(a + b*x)^2)/(d^2*e^2) + (E^(e*(c + d*x))*(a + b*x)^3)/(d*e)}
{E^(e*(c + d*x))*(a + b*x)^2, x, 3, (2*b^2*E^(e*(c + d*x)))/(d^3*e^3) - (2*b*E^(e*(c + d*x))*(a + b*x))/(d^2*e^2) + (E^(e*(c + d*x))*(a + b*x)^2)/(d*e)}
{E^(e*(c + d*x))*(a + b*x)^1, x, 2, -((b*E^(e*(c + d*x)))/(d^2*e^2)) + (E^(e*(c + d*x))*(a + b*x))/(d*e)}
{E^(e*(c + d*x))*(a + b*x)^0, x, 1, E^(e*(c + d*x))/(d*e)}
{E^(e*(c + d*x))/(a + b*x)^1, x, 1, (E^((c - (a*d)/b)*e)*ExpIntegralEi[(d*e*(a + b*x))/b])/b}
{E^(e*(c + d*x))/(a + b*x)^2, x, 2, -(E^(e*(c + d*x))/(b*(a + b*x))) + (d*e*E^((c - (a*d)/b)*e)*ExpIntegralEi[(d*e*(a + b*x))/b])/b^2}
{E^(e*(c + d*x))/(a + b*x)^3, x, 3, -(E^(e*(c + d*x))/(2*b*(a + b*x)^2)) - (d*e*E^(e*(c + d*x)))/(2*b^2*(a + b*x)) + (d^2*e^2*E^((c - (a*d)/b)*e)*ExpIntegralEi[(d*e*(a + b*x))/b])/(2*b^3)}
{E^(e*(c + d*x))/(a + b*x)^4, x, 1, (d^3*e^3*E^((c - (a*d)/b)*e)*Gamma[-3, -((d*e*(a + b*x))/b)])/b^4}
{E^(e*(c + d*x))/(a + b*x)^5, x, 1, -((d^4*e^4*E^((c - (a*d)/b)*e)*Gamma[-4, -((d*e*(a + b*x))/b)])/b^5)}


{E^(e*(c + d*x)^2)*(a + b*x)^3, x, 7, -((b^3*E^(e*(c + d*x)^2))/(2*d^4*e^2)) + (b*(b*c - a*d)^2*E^(e*(c + d*x)^2))/(2*d^4*e) - (b*(b*c - a*d)*E^(e*(c + d*x)^2)*(a + b*x))/(2*d^3*e) + (b*E^(e*(c + d*x)^2)*(a + b*x)^2)/(2*d^2*e) + (3*b^2*(b*c - a*d)*Sqrt[Pi]*Erfi[Sqrt[e]*(c + d*x)])/(4*d^4*e^(3/2)) - ((b*c - a*d)^3*Sqrt[Pi]*Erfi[Sqrt[e]*(c + d*x)])/(2*d^4*Sqrt[e])}
{E^(e*(c + d*x)^2)*(a + b*x)^2, x, 4, -((b*(b*c - a*d)*E^(e*(c + d*x)^2))/(2*d^3*e)) + (b*E^(e*(c + d*x)^2)*(a + b*x))/(2*d^2*e) - (b^2*Sqrt[Pi]*Erfi[Sqrt[e]*(c + d*x)])/(4*d^3*e^(3/2)) + ((b*c - a*d)^2*Sqrt[Pi]*Erfi[Sqrt[e]*(c + d*x)])/(2*d^3*Sqrt[e])}
{E^(e*(c + d*x)^2)*(a + b*x)^1, x, 2, (b*E^(e*(c + d*x)^2))/(2*d^2*e) - ((b*c - a*d)*Sqrt[Pi]*Erfi[Sqrt[e]*(c + d*x)])/(2*d^2*Sqrt[e])}
{E^(e*(c + d*x)^2)*(a + b*x)^0, x, 1, (Sqrt[Pi]*Erfi[Sqrt[e]*(c + d*x)])/(2*d*Sqrt[e])}
{E^(e*(c + d*x)^2)/(a + b*x)^1, x, 0, Int[E^(e*(c + d*x)^2)/(a + b*x), x]}
{E^(e*(c + d*x)^2)/(a + b*x)^2, x, 2, -(E^(e*(c + d*x)^2)/(b*(a + b*x))) + (d*Sqrt[e]*Sqrt[Pi]*Erfi[Sqrt[e]*(c + d*x)])/b^2 + (2*d*(b*c - a*d)*e*Int[E^(e*(c + d*x)^2)/(a + b*x), x])/b^2}
{E^(e*(c + d*x)^2)/(a + b*x)^3, x, 3, -(E^(e*(c + d*x)^2)/(2*b*(a + b*x)^2)) - (d*(b*c - a*d)*e*E^(e*(c + d*x)^2))/(b^3*(a + b*x)) + (d^2*(b*c - a*d)*e^(3/2)*Sqrt[Pi]*Erfi[Sqrt[e]*(c + d*x)])/b^4 + (d^2*e*Int[E^(e*(c + d*x)^2)/(a + b*x), x])/b^2 + (2*d^2*(b*c - a*d)^2*e^2*Int[E^(e*(c + d*x)^2)/(a + b*x), x])/b^4}


{E^(e*(c + d*x)^3)*(a + b*x)^3, x, 6, -((b^2*(b*c - a*d)*E^(e*(c + d*x)^3))/(d^4*e)) + ((b*c - a*d)^3*(c + d*x)*Gamma[1/3, (-e)*(c + d*x)^3])/(3*d^4*((-e)*(c + d*x)^3)^(1/3)) - (b*(b*c - a*d)^2*(c + d*x)^2*Gamma[2/3, (-e)*(c + d*x)^3])/(d^4*((-e)*(c + d*x)^3)^(2/3)) - (b^3*(c + d*x)^4*Gamma[4/3, (-e)*(c + d*x)^3])/(3*d^4*((-e)*(c + d*x)^3)^(4/3))}
{E^(e*(c + d*x)^3)*(a + b*x)^2, x, 5, (b^2*E^(e*(c + d*x)^3))/(3*d^3*e) - ((b*c - a*d)^2*(c + d*x)*Gamma[1/3, (-e)*(c + d*x)^3])/(3*d^3*((-e)*(c + d*x)^3)^(1/3)) + (2*b*(b*c - a*d)*(c + d*x)^2*Gamma[2/3, (-e)*(c + d*x)^3])/(3*d^3*((-e)*(c + d*x)^3)^(2/3))}
{E^(e*(c + d*x)^3)*(a + b*x)^1, x, 4, ((b*c - a*d)*(c + d*x)*Gamma[1/3, -(e*(c + d*x)^3)])/(3*d^2*(-(e*(c + d*x)^3))^(1/3)) - (b*(c + d*x)^2*Gamma[2/3, -(e*(c + d*x)^3)])/(3*d^2*(-(e*(c + d*x)^3))^(2/3))}
{E^(e*(c + d*x)^3)*(a + b*x)^0, x, 1, -(((c + d*x)*Gamma[1/3, (-e)*(c + d*x)^3])/(3*d*((-e)*(c + d*x)^3)^(1/3)))}
{E^(e*(c + d*x)^3)/(a + b*x)^1, x, 0, Int[E^(e*(c + d*x)^3)/(a + b*x), x]}
{E^(e*(c + d*x)^3)/(a + b*x)^2, x, 5, -(E^(e*(c + d*x)^3)/(b*(a + b*x))) - (d*(b*c - a*d)*e*(c + d*x)*Gamma[1/3, (-e)*(c + d*x)^3])/(b^3*((-e)*(c + d*x)^3)^(1/3)) - (d*e*(c + d*x)^2*Gamma[2/3, (-e)*(c + d*x)^3])/(b^2*((-e)*(c + d*x)^3)^(2/3)) + (3*d*(b*c - a*d)^2*e*Int[E^(e*(c + d*x)^3)/(a + b*x), x])/b^3}


(* ::Subsubsection::Closed:: *)
(*n<0*)


{F^(a + b/(c + d*x))/(e + f*x)^1, x, 4, -((F^a*ExpIntegralEi[(b*Log[F])/(c + d*x)])/f) + (F^(a - (b*f)/(d*e - c*f))*ExpIntegralEi[(d*b*(e + f*x)*Log[F])/((d*e - c*f)*(c + d*x))])/f}
{F^(a + b/(c + d*x))/(e + f*x)^2, x, 9, (d*F^(a + b/(c + d*x)))/(f*(d*e - c*f)) - F^(a + b/(c + d*x))/(f*(e + f*x)) - (b*d*F^(a - (b*f)/(d*e - c*f))*ExpIntegralEi[(b*d*(e + f*x)*Log[F])/((d*e - c*f)*(c + d*x))]*Log[F])/(d*e - c*f)^2}
{F^(a + b/(c + d*x))/(e + f*x)^3, x, 18, (d^2*F^(a + b/(c + d*x)))/(2*f*(d*e - c*f)^2) - F^(a + b/(c + d*x))/(2*f*(e + f*x)^2) - (b*d^2*F^(a + b/(c + d*x))*Log[F])/(2*(d*e - c*f)^3) + (b*d*F^(a + b/(c + d*x))*Log[F])/(2*(d*e - c*f)^2*(e + f*x)) - (b*d^2*F^(a - (b*f)/(d*e - c*f))*ExpIntegralEi[(b*d*(e + f*x)*Log[F])/((d*e - c*f)*(c + d*x))]*Log[F])/(d*e - c*f)^3 + (b^2*d^2*f*F^(a - (b*f)/(d*e - c*f))*ExpIntegralEi[(b*d*(e + f*x)*Log[F])/((d*e - c*f)*(c + d*x))]*Log[F]^2)/(2*(d*e - c*f)^4)}
{F^(a + b/(c + d*x))/(e + f*x)^4, x, 36, (d^3*F^(a + b/(c + d*x)))/(3*f*(d*e - c*f)^3) - F^(a + b/(c + d*x))/(3*f*(e + f*x)^3) - (5*b*d^3*F^(a + b/(c + d*x))*Log[F])/(6*(d*e - c*f)^4) + (b*d*F^(a + b/(c + d*x))*Log[F])/(6*(d*e - c*f)^2*(e + f*x)^2) + (2*b*d^2*F^(a + b/(c + d*x))*Log[F])/(3*(d*e - c*f)^3*(e + f*x)) - (b*d^3*F^(a - (b*f)/(d*e - c*f))*ExpIntegralEi[(b*d*(e + f*x)*Log[F])/((d*e - c*f)*(c + d*x))]*Log[F])/(d*e - c*f)^4 + (b^2*d^3*f*F^(a + b/(c + d*x))*Log[F]^2)/(6*(d*e - c*f)^5) - (b^2*d^2*f*F^(a + b/(c + d*x))*Log[F]^2)/(6*(d*e - c*f)^4*(e + f*x)) + (b^2*d^3*f*F^(a - (b*f)/(d*e - c*f))*ExpIntegralEi[(b*d*(e + f*x)*Log[F])/((d*e - c*f)*(c + d*x))]*Log[F]^2)/(d*e - c*f)^5 - (b^3*d^3*f^2*F^(a - (b*f)/(d*e - c*f))*ExpIntegralEi[(b*d*(e + f*x)*Log[F])/((d*e - c*f)*(c + d*x))]*Log[F]^3)/(6*(d*e - c*f)^6)}


{E^(e/(c + d*x))*(a + b*x)^4, x, 8, ((b*c - a*d)^4*E^(e/(c + d*x))*(c + d*x))/d^5 - ((b*c - a*d)^4*e*ExpIntegralEi[e/(c + d*x)])/d^5 - (b^4*e^5*Gamma[-5, -(e/(c + d*x))])/d^5 - (4*b^3*(b*c - a*d)*e^4*Gamma[-4, -(e/(c + d*x))])/d^5 - (6*b^2*(b*c - a*d)^2*e^3*Gamma[-3, -(e/(c + d*x))])/d^5 - (4*b*(b*c - a*d)^3*e^2*Gamma[-2, -(e/(c + d*x))])/d^5}
{E^(e/(c + d*x))*(a + b*x)^3, x, 7, -(((b*c - a*d)^3*E^(e/(c + d*x))*(c + d*x))/d^4) + ((b*c - a*d)^3*e*ExpIntegralEi[e/(c + d*x)])/d^4 + (b^3*e^4*Gamma[-4, -(e/(c + d*x))])/d^4 + (3*b^2*(b*c - a*d)*e^3*Gamma[-3, -(e/(c + d*x))])/d^4 + (3*b*(b*c - a*d)^2*e^2*Gamma[-2, -(e/(c + d*x))])/d^4}
{E^(e/(c + d*x))*(a + b*x)^2, x, 6, ((b*c - a*d)^2*E^(e/(c + d*x))*(c + d*x))/d^3 - ((b*c - a*d)^2*e*ExpIntegralEi[e/(c + d*x)])/d^3 - (b^2*e^3*Gamma[-3, -(e/(c + d*x))])/d^3 - (2*b*(b*c - a*d)*e^2*Gamma[-2, -(e/(c + d*x))])/d^3}
{E^(e/(c + d*x))*(a + b*x)^1, x, 5, -(((b*c - a*d)*E^(e/(c + d*x))*(c + d*x))/d^2) + ((b*c - a*d)*e*ExpIntegralEi[e/(c + d*x)])/d^2 + (b*e^2*Gamma[-2, -(e/(c + d*x))])/d^2}
{E^(e/(c + d*x))*(a + b*x)^0, x, 2, (E^(e/(c + d*x))*(c + d*x))/d - (e*ExpIntegralEi[e/(c + d*x)])/d}
{E^(e/(c + d*x))/(a + b*x)^1, x, 4, -(ExpIntegralEi[e/(c + d*x)]/b) + (E^((b*e)/(b*c - a*d))*ExpIntegralEi[-((d*e*(a + b*x))/((b*c - a*d)*(c + d*x)))])/b}
{E^(e/(c + d*x))/(a + b*x)^2, x, 9, -((d*E^(e/(c + d*x)))/(b*(b*c - a*d))) - E^(e/(c + d*x))/(b*(a + b*x)) - (d*e*E^((b*e)/(b*c - a*d))*ExpIntegralEi[-((d*e*(a + b*x))/((b*c - a*d)*(c + d*x)))])/(b*c - a*d)^2}
{E^(e/(c + d*x))/(a + b*x)^3, x, 18, (d^2*E^(e/(c + d*x)))/(2*b*(b*c - a*d)^2) + (d^2*e*E^(e/(c + d*x)))/(2*(b*c - a*d)^3) - E^(e/(c + d*x))/(2*b*(a + b*x)^2) + (d*e*E^(e/(c + d*x)))/(2*(b*c - a*d)^2*(a + b*x)) + (d^2*e*E^((b*e)/(b*c - a*d))*ExpIntegralEi[-((d*e*(a + b*x))/((b*c - a*d)*(c + d*x)))])/(b*c - a*d)^3 + (b*d^2*e^2*E^((b*e)/(b*c - a*d))*ExpIntegralEi[-((d*e*(a + b*x))/((b*c - a*d)*(c + d*x)))])/(2*(b*c - a*d)^4)}


{E^(e/(c + d*x)^2)*(a + b*x)^3, x, 8, -(((b*c - a*d)^3*E^(e/(c + d*x)^2)*(c + d*x))/d^4) + ((b*c - a*d)^3*Sqrt[e]*Sqrt[Pi]*Erfi[Sqrt[e]/(c + d*x)])/d^4 + (b^3*e^2*Gamma[-2, -(e/(c + d*x)^2)])/(2*d^4) - (3*b^2*(b*c - a*d)*(-(e/(c + d*x)^2))^(3/2)*(c + d*x)^3*Gamma[-(3/2), -(e/(c + d*x)^2)])/(2*d^4) - (3*b*(b*c - a*d)^2*e*Gamma[-1, -(e/(c + d*x)^2)])/(2*d^4)}
{E^(e/(c + d*x)^2)*(a + b*x)^2, x, 7, ((b*c - a*d)^2*E^(e/(c + d*x)^2)*(c + d*x))/d^3 - ((b*c - a*d)^2*Sqrt[e]*Sqrt[Pi]*Erfi[Sqrt[e]/(c + d*x)])/d^3 + (b^2*(-(e/(c + d*x)^2))^(3/2)*(c + d*x)^3*Gamma[-(3/2), -(e/(c + d*x)^2)])/(2*d^3) + (b*(b*c - a*d)*e*Gamma[-1, -(e/(c + d*x)^2)])/d^3}
{E^(e/(c + d*x)^2)*(a + b*x)^1, x, 6, -(((b*c - a*d)*E^(e/(c + d*x)^2)*(c + d*x))/d^2) + ((b*c - a*d)*Sqrt[e]*Sqrt[Pi]*Erfi[Sqrt[e]/(c + d*x)])/d^2 - (b*e*Gamma[-1, -(e/(c + d*x)^2)])/(2*d^2)}
{E^(e/(c + d*x)^2)*(a + b*x)^0, x, 3, (E^(e/(c + d*x)^2)*(c + d*x))/d - (Sqrt[e]*Sqrt[Pi]*Erfi[Sqrt[e]/(c + d*x)])/d}
{E^(e/(c + d*x)^2)/(a + b*x)^1, x, 0, Int[E^(e/(c + d*x)^2)/(a + b*x), x]}
{E^(e/(c + d*x)^2)/(a + b*x)^2, x, 0, Int[E^(e/(c + d*x)^2)/(a + b*x)^2, x]}
{E^(e/(c + d*x)^2)/(a + b*x)^3, x, 0, Int[E^(e/(c + d*x)^2)/(a + b*x)^3, x]}


{E^(e/(c + d*x)^3)*(a + b*x)^3, x, 6, (b^3*(-(e/(c + d*x)^3))^(4/3)*(c + d*x)^4*Gamma[-(4/3), -(e/(c + d*x)^3)])/(3*d^4) + (b^2*(b*c - a*d)*e*Gamma[-1, -(e/(c + d*x)^3)])/d^4 + (b*(b*c - a*d)^2*(-(e/(c + d*x)^3))^(2/3)*(c + d*x)^2*Gamma[-(2/3), -(e/(c + d*x)^3)])/d^4 - ((b*c - a*d)^3*(-(e/(c + d*x)^3))^(1/3)*(c + d*x)*Gamma[-(1/3), -(e/(c + d*x)^3)])/(3*d^4)}
{E^(e/(c + d*x)^3)*(a + b*x)^2, x, 5, -((b^2*e*Gamma[-1, -(e/(c + d*x)^3)])/(3*d^3)) - (2*b*(b*c - a*d)*(-(e/(c + d*x)^3))^(2/3)*(c + d*x)^2*Gamma[-(2/3), -(e/(c + d*x)^3)])/(3*d^3) + ((b*c - a*d)^2*(-(e/(c + d*x)^3))^(1/3)*(c + d*x)*Gamma[-(1/3), -(e/(c + d*x)^3)])/(3*d^3)}
{E^(e/(c + d*x)^3)*(a + b*x)^1, x, 4, (b*(-(e/(c + d*x)^3))^(2/3)*(c + d*x)^2*Gamma[-(2/3), -(e/(c + d*x)^3)])/(3*d^2) - ((b*c - a*d)*(-(e/(c + d*x)^3))^(1/3)*(c + d*x)*Gamma[-(1/3), -(e/(c + d*x)^3)])/(3*d^2)}
{E^(e/(c + d*x)^3)*(a + b*x)^0, x, 1, ((-(e/(c + d*x)^3))^(1/3)*(c + d*x)*Gamma[-(1/3), -(e/(c + d*x)^3)])/(3*d)}
{E^(e/(c + d*x)^3)/(a + b*x)^1, x, 0, Int[E^(e/(c + d*x)^3)/(a + b*x), x]}
{E^(e/(c + d*x)^3)/(a + b*x)^2, x, 0, Int[E^(e/(c + d*x)^3)/(a + b*x)^2, x]}


(* ::Subsubsection:: *)
(*n symbolic*)


(* ::Subsection::Closed:: *)
(*Integrands of the form (g+h x)^m F^(e+f (a+b x)/(c+d x))*)


{F^(e + f*(a + b*x)/(c + d*x))/(g + h*x)^1, x, 5, -((F^(e + (b*f)/d)*ExpIntegralEi[-(((b*c - a*d)*f*Log[F])/(d*(c + d*x)))])/h) + (F^(e + (f*(b*g - a*h))/(d*g - c*h))*ExpIntegralEi[-(((b*c - a*d)*f*(g + h*x)*Log[F])/((d*g - c*h)*(c + d*x)))])/h}
{F^(e + f*(a + b*x)/(c + d*x))/(g + h*x)^2, x, 12, (d*F^(e + (b*f)/d - ((b*c - a*d)*f)/(d*(c + d*x))))/(h*(d*g - c*h)) - F^(e + (f*(a + b*x))/(c + d*x))/(h*(g + h*x)) + ((b*c - a*d)*f*F^(e + (f*(b*g - a*h))/(d*g - c*h))*ExpIntegralEi[-(((b*c - a*d)*f*(g + h*x)*Log[F])/((d*g - c*h)*(c + d*x)))]*Log[F])/(d*g - c*h)^2}
{F^(e + f*(a + b*x)/(c + d*x))/(g + h*x)^3, x, 24, (d^2*F^(e + (b*f)/d - ((b*c - a*d)*f)/(d*(c + d*x))))/(2*h*(d*g - c*h)^2) - F^(e + (f*(a + b*x))/(c + d*x))/(2*h*(g + h*x)^2) + (d*(b*c - a*d)*f*F^(e + (b*f)/d - ((b*c - a*d)*f)/(d*(c + d*x)))*Log[F])/(2*(d*g - c*h)^3) - ((b*c - a*d)*f*F^(e + (f*(a + b*x))/(c + d*x))*Log[F])/(2*(d*g - c*h)^2*(g + h*x)) + (d*(b*c - a*d)*f*F^(e + (f*(b*g - a*h))/(d*g - c*h))*ExpIntegralEi[-(((b*c - a*d)*f*(g + h*x)*Log[F])/((d*g - c*h)*(c + d*x)))]*Log[F])/(d*g - c*h)^3 + ((b*c - a*d)^2*f^2*F^(e + (f*(b*g - a*h))/(d*g - c*h))*h*ExpIntegralEi[-(((b*c - a*d)*f*(g + h*x)*Log[F])/((d*g - c*h)*(c + d*x)))]*Log[F]^2)/(2*(d*g - c*h)^4)}
{F^(e + f*(a + b*x)/(c + d*x))/(g + h*x)^4, x, 48, (d^3*F^(e + (b*f)/d - ((b*c - a*d)*f)/(d*(c + d*x))))/(3*h*(d*g - c*h)^3) - F^(e + (f*(a + b*x))/(c + d*x))/(3*h*(g + h*x)^3) + (5*d^2*(b*c - a*d)*f*F^(e + (b*f)/d - ((b*c - a*d)*f)/(d*(c + d*x)))*Log[F])/(6*(d*g - c*h)^4) - ((b*c - a*d)*f*F^(e + (f*(a + b*x))/(c + d*x))*Log[F])/(6*(d*g - c*h)^2*(g + h*x)^2) - (2*d*(b*c - a*d)*f*F^(e + (f*(a + b*x))/(c + d*x))*Log[F])/(3*(d*g - c*h)^3*(g + h*x)) + (d^2*(b*c - a*d)*f*F^(e + (f*(b*g - a*h))/(d*g - c*h))*ExpIntegralEi[-(((b*c - a*d)*f*(g + h*x)*Log[F])/((d*g - c*h)*(c + d*x)))]*Log[F])/(d*g - c*h)^4 + (d*(b*c - a*d)^2*f^2*F^(e + (b*f)/d - ((b*c - a*d)*f)/(d*(c + d*x)))*h*Log[F]^2)/(6*(d*g - c*h)^5) - ((b*c - a*d)^2*f^2*F^(e + (f*(a + b*x))/(c + d*x))*h*Log[F]^2)/(6*(d*g - c*h)^4*(g + h*x)) + (d*(b*c - a*d)^2*f^2*F^(e + (f*(b*g - a*h))/(d*g - c*h))*h*ExpIntegralEi[-(((b*c - a*d)*f*(g + h*x)*Log[F])/((d*g - c*h)*(c + d*x)))]*Log[F]^2)/(d*g - c*h)^5 + ((b*c - a*d)^3*f^3*F^(e + (f*(b*g - a*h))/(d*g - c*h))*h^2*ExpIntegralEi[-(((b*c - a*d)*f*(g + h*x)*Log[F])/((d*g - c*h)*(c + d*x)))]*Log[F]^3)/(6*(d*g - c*h)^6)}


(* ::Subsection::Closed:: *)
(*Integrands of the form x^m (e+f x)^n f^(a+b (c+d x))*)


{x^m*(a + b*x)^4/E^(a + b*x), x, 7, -((a^4*x^m*Gamma[1 + m, b*x])/(E^a*(b*x)^m*b)) - (4*a^3*x^(1 + m)*(b*x)^(-1 - m)*Gamma[2 + m, b*x])/E^a - (6*a^2*b*x^(2 + m)*(b*x)^(-2 - m)*Gamma[3 + m, b*x])/E^a - (4*a*b^2*x^(3 + m)*(b*x)^(-3 - m)*Gamma[4 + m, b*x])/E^a - (b^3*x^(4 + m)*(b*x)^(-4 - m)*Gamma[5 + m, b*x])/E^a}

{x^7*(a + b*x)^4/E^(a + b*x), x, 7, -((a^4*Gamma[8, b*x])/(E^a*b^8)) - (4*a^3*Gamma[9, b*x])/(E^a*b^8) - (6*a^2*Gamma[10, b*x])/(E^a*b^8) - (4*a*Gamma[11, b*x])/(E^a*b^8) - Gamma[12, b*x]/(E^a*b^8)}
{x^6*(a + b*x)^4/E^(a + b*x), x, 7, -((a^4*Gamma[7, b*x])/(E^a*b^7)) - (4*a^3*Gamma[8, b*x])/(E^a*b^7) - (6*a^2*Gamma[9, b*x])/(E^a*b^7) - (4*a*Gamma[10, b*x])/(E^a*b^7) - Gamma[11, b*x]/(E^a*b^7)}
{x^5*(a + b*x)^4/E^(a + b*x), x, 7, -((a^4*Gamma[6, b*x])/(E^a*b^6)) - (4*a^3*Gamma[7, b*x])/(E^a*b^6) - (6*a^2*Gamma[8, b*x])/(E^a*b^6) - (4*a*Gamma[9, b*x])/(E^a*b^6) - Gamma[10, b*x]/(E^a*b^6)}
{x^4*(a + b*x)^4/E^(a + b*x), x, 7, -((a^4*Gamma[5, a + b*x])/b^5) + (4*a^3*Gamma[6, a + b*x])/b^5 - (6*a^2*Gamma[7, a + b*x])/b^5 + (4*a*Gamma[8, a + b*x])/b^5 - Gamma[9, a + b*x]/b^5}
{x^3*(a + b*x)^4/E^(a + b*x), x, 6, (a^3*Gamma[5, a + b*x])/b^4 - (3*a^2*Gamma[6, a + b*x])/b^4 + (3*a*Gamma[7, a + b*x])/b^4 - Gamma[8, a + b*x]/b^4}
{x^2*(a + b*x)^4/E^(a + b*x), x, 5, -((a^2*Gamma[5, a + b*x])/b^3) + (2*a*Gamma[6, a + b*x])/b^3 - Gamma[7, a + b*x]/b^3}
{x^1*(a + b*x)^4/E^(a + b*x), x, 4, (a*Gamma[5, a + b*x])/b^2 - Gamma[6, a + b*x]/b^2}
{x^0*(a + b*x)^4/E^(a + b*x), x, 1, -(Gamma[5, a + b*x]/b)}
{(a + b*x)^4/(x^1*E^(a + b*x)), x, 13, -6*E^(-a - b*x) - 2*a*E^(-a - b*x) - a^2*E^(-a - b*x) - a^3*E^(-a - b*x) - 6*E^(-a - b*x)*(a + b*x) - 2*a*E^(-a - b*x)*(a + b*x) - a^2*E^(-a - b*x)*(a + b*x) - 3*E^(-a - b*x)*(a + b*x)^2 - a*E^(-a - b*x)*(a + b*x)^2 - E^(-a - b*x)*(a + b*x)^3 + (a^4*ExpIntegralEi[(-b)*x])/E^a}
{(a + b*x)^4/(x^2*E^(a + b*x)), x, 11, -2*b*E^(-a - b*x) - 4*a*b*E^(-a - b*x) - 6*a^2*b*E^(-a - b*x) - (a^4*E^(-a - b*x))/x - 2*b^2*E^(-a - b*x)*x - 4*a*b^2*E^(-a - b*x)*x - b^3*E^(-a - b*x)*x^2 + (4*a^3*b*ExpIntegralEi[(-b)*x])/E^a - (a^4*b*ExpIntegralEi[(-b)*x])/E^a}
{(a + b*x)^4/(x^3*E^(a + b*x)), x, 11, (-b^2)*E^(-a - b*x) - 4*a*b^2*E^(-a - b*x) - (a^4*E^(-a - b*x))/(2*x^2) - (4*a^3*b*E^(-a - b*x))/x + (a^4*b*E^(-a - b*x))/(2*x) - b^3*E^(-a - b*x)*x + (6*a^2*b^2*ExpIntegralEi[(-b)*x])/E^a - (4*a^3*b^2*ExpIntegralEi[(-b)*x])/E^a + ((1/2)*a^4*b^2*ExpIntegralEi[(-b)*x])/E^a}
{(a + b*x)^4/(x^4*E^(a + b*x)), x, 13, (-b^3)*E^(-a - b*x) - (a^4*E^(-a - b*x))/(3*x^3) - (2*a^3*b*E^(-a - b*x))/x^2 + (a^4*b*E^(-a - b*x))/(6*x^2) - (6*a^2*b^2*E^(-a - b*x))/x + (2*a^3*b^2*E^(-a - b*x))/x - (a^4*b^2*E^(-a - b*x))/(6*x) + (4*a*b^3*ExpIntegralEi[(-b)*x])/E^a - (6*a^2*b^3*ExpIntegralEi[(-b)*x])/E^a + (2*a^3*b^3*ExpIntegralEi[(-b)*x])/E^a - ((1/6)*a^4*b^3*ExpIntegralEi[(-b)*x])/E^a}
{(a + b*x)^4/(x^5*E^(a + b*x)), x, 13, -((4*a^3*b*E^(-a - b*x))/(3*x^3)) - (3*a^2*b^2*E^(-a - b*x))/x^2 + (2*a^3*b^2*E^(-a - b*x))/(3*x^2) - (4*a*b^3*E^(-a - b*x))/x + (3*a^2*b^3*E^(-a - b*x))/x - (2*a^3*b^3*E^(-a - b*x))/(3*x) + (b^4*ExpIntegralEi[(-b)*x])/E^a - (4*a*b^4*ExpIntegralEi[(-b)*x])/E^a + (3*a^2*b^4*ExpIntegralEi[(-b)*x])/E^a - ((2/3)*a^3*b^4*ExpIntegralEi[(-b)*x])/E^a - (a^4*b^4*Gamma[-4, b*x])/E^a}
{(a + b*x)^4/(x^6*E^(a + b*x)), x, 13, -((2*a^2*b^2*E^(-a - b*x))/x^3) - (2*a*b^3*E^(-a - b*x))/x^2 + (a^2*b^3*E^(-a - b*x))/x^2 - (b^4*E^(-a - b*x))/x + (2*a*b^4*E^(-a - b*x))/x - (a^2*b^4*E^(-a - b*x))/x - (b^5*ExpIntegralEi[(-b)*x])/E^a + (2*a*b^5*ExpIntegralEi[(-b)*x])/E^a - (a^2*b^5*ExpIntegralEi[(-b)*x])/E^a - (a^4*b^5*Gamma[-5, b*x])/E^a - (4*a^3*b^5*Gamma[-4, b*x])/E^a}
{(a + b*x)^4/(x^7*E^(a + b*x)), x, 12, -((4*a*b^3*E^(-a - b*x))/(3*x^3)) - (b^4*E^(-a - b*x))/(2*x^2) + (2*a*b^4*E^(-a - b*x))/(3*x^2) + (b^5*E^(-a - b*x))/(2*x) - (2*a*b^5*E^(-a - b*x))/(3*x) + ((1/2)*b^6*ExpIntegralEi[(-b)*x])/E^a - ((2/3)*a*b^6*ExpIntegralEi[(-b)*x])/E^a - (a^4*b^6*Gamma[-6, b*x])/E^a - (4*a^3*b^6*Gamma[-5, b*x])/E^a - (6*a^2*b^6*Gamma[-4, b*x])/E^a}
{(a + b*x)^4/(x^8*E^(a + b*x)), x, 10, -((b^4*E^(-a - b*x))/(3*x^3)) + (b^5*E^(-a - b*x))/(6*x^2) - (b^6*E^(-a - b*x))/(6*x) - ((1/6)*b^7*ExpIntegralEi[(-b)*x])/E^a - (a^4*b^7*Gamma[-7, b*x])/E^a - (4*a^3*b^7*Gamma[-6, b*x])/E^a - (6*a^2*b^7*Gamma[-5, b*x])/E^a - (4*a*b^7*Gamma[-4, b*x])/E^a}


{x^m*(e + f*x)^4*F^(a + b*(c + d*x)), x, 8, (-f^4)*F^(a + b*c)*x^(5 + m)*Gamma[5 + m, (-b)*d*x*Log[F]]*((-b)*d*x*Log[F])^(-5 - m) - 4*e*f^3*F^(a + b*c)*x^(4 + m)*Gamma[4 + m, (-b)*d*x*Log[F]]*((-b)*d*x*Log[F])^(-4 - m) - 6*e^2*f^2*F^(a + b*c)*x^(3 + m)*Gamma[3 + m, (-b)*d*x*Log[F]]*((-b)*d*x*Log[F])^(-3 - m) - 4*e^3*f*F^(a + b*c)*x^(2 + m)*Gamma[2 + m, (-b)*d*x*Log[F]]*((-b)*d*x*Log[F])^(-2 - m) - e^4*F^(a + b*c)*x^(1 + m)*Gamma[1 + m, (-b)*d*x*Log[F]]*((-b)*d*x*Log[F])^(-1 - m)}

{x^7*(e + f*x)^4*F^(a + b*(c + d*x)), x, 8, -((f^4*F^(a + b*c)*Gamma[12, (-b)*d*x*Log[F]])/(b^12*d^12*Log[F]^12)) + (4*e*f^3*F^(a + b*c)*Gamma[11, (-b)*d*x*Log[F]])/(b^11*d^11*Log[F]^11) - (6*e^2*f^2*F^(a + b*c)*Gamma[10, (-b)*d*x*Log[F]])/(b^10*d^10*Log[F]^10) + (4*e^3*f*F^(a + b*c)*Gamma[9, (-b)*d*x*Log[F]])/(b^9*d^9*Log[F]^9) - (e^4*F^(a + b*c)*Gamma[8, (-b)*d*x*Log[F]])/(b^8*d^8*Log[F]^8)}
{x^6*(e + f*x)^4*F^(a + b*(c + d*x)), x, 8, (f^4*F^(a + b*c)*Gamma[11, (-b)*d*x*Log[F]])/(b^11*d^11*Log[F]^11) - (4*e*f^3*F^(a + b*c)*Gamma[10, (-b)*d*x*Log[F]])/(b^10*d^10*Log[F]^10) + (6*e^2*f^2*F^(a + b*c)*Gamma[9, (-b)*d*x*Log[F]])/(b^9*d^9*Log[F]^9) - (4*e^3*f*F^(a + b*c)*Gamma[8, (-b)*d*x*Log[F]])/(b^8*d^8*Log[F]^8) + (e^4*F^(a + b*c)*Gamma[7, (-b)*d*x*Log[F]])/(b^7*d^7*Log[F]^7)}
{x^5*(e + f*x)^4*F^(a + b*(c + d*x)), x, 8, -((f^4*F^(a + b*c)*Gamma[10, (-b)*d*x*Log[F]])/(b^10*d^10*Log[F]^10)) + (4*e*f^3*F^(a + b*c)*Gamma[9, (-b)*d*x*Log[F]])/(b^9*d^9*Log[F]^9) - (6*e^2*f^2*F^(a + b*c)*Gamma[8, (-b)*d*x*Log[F]])/(b^8*d^8*Log[F]^8) + (4*e^3*f*F^(a + b*c)*Gamma[7, (-b)*d*x*Log[F]])/(b^7*d^7*Log[F]^7) - (e^4*F^(a + b*c)*Gamma[6, (-b)*d*x*Log[F]])/(b^6*d^6*Log[F]^6)}
{x^4*(e + f*x)^4*F^(a + b*(c + d*x)), x, 8, (f^4*F^(a + b*c - (b*d*e)/f)*Gamma[9, -((b*d*(e + f*x)*Log[F])/f)])/(b^9*d^9*Log[F]^9) + (4*e*f^3*F^(a + b*c - (b*d*e)/f)*Gamma[8, -((b*d*(e + f*x)*Log[F])/f)])/(b^8*d^8*Log[F]^8) + (6*e^2*f^2*F^(a + b*c - (b*d*e)/f)*Gamma[7, -((b*d*(e + f*x)*Log[F])/f)])/(b^7*d^7*Log[F]^7) + (4*e^3*f*F^(a + b*c - (b*d*e)/f)*Gamma[6, -((b*d*(e + f*x)*Log[F])/f)])/(b^6*d^6*Log[F]^6) + (e^4*F^(a + b*c - (b*d*e)/f)*Gamma[5, -((b*d*(e + f*x)*Log[F])/f)])/(b^5*d^5*Log[F]^5)}
{x^3*(e + f*x)^4*F^(a + b*(c + d*x)), x, 7, -((f^4*F^(a + b*c - (b*d*e)/f)*Gamma[8, -((b*d*(e + f*x)*Log[F])/f)])/(b^8*d^8*Log[F]^8)) - (3*e*f^3*F^(a + b*c - (b*d*e)/f)*Gamma[7, -((b*d*(e + f*x)*Log[F])/f)])/(b^7*d^7*Log[F]^7) - (3*e^2*f^2*F^(a + b*c - (b*d*e)/f)*Gamma[6, -((b*d*(e + f*x)*Log[F])/f)])/(b^6*d^6*Log[F]^6) - (e^3*f*F^(a + b*c - (b*d*e)/f)*Gamma[5, -((b*d*(e + f*x)*Log[F])/f)])/(b^5*d^5*Log[F]^5)}
{x^2*(e + f*x)^4*F^(a + b*(c + d*x)), x, 6, (f^4*F^(a + b*c - (b*d*e)/f)*Gamma[7, -((b*d*(e + f*x)*Log[F])/f)])/(b^7*d^7*Log[F]^7) + (2*e*f^3*F^(a + b*c - (b*d*e)/f)*Gamma[6, -((b*d*(e + f*x)*Log[F])/f)])/(b^6*d^6*Log[F]^6) + (e^2*f^2*F^(a + b*c - (b*d*e)/f)*Gamma[5, -((b*d*(e + f*x)*Log[F])/f)])/(b^5*d^5*Log[F]^5)}
{x^1*(e + f*x)^4*F^(a + b*(c + d*x)), x, 5, -((f^4*F^(a + b*c - (b*d*e)/f)*Gamma[6, -((b*d*(e + f*x)*Log[F])/f)])/(b^6*d^6*Log[F]^6)) - (e*f^3*F^(a + b*c - (b*d*e)/f)*Gamma[5, -((b*d*(e + f*x)*Log[F])/f)])/(b^5*d^5*Log[F]^5)}
{x^0*(e + f*x)^4*F^(a + b*(c + d*x)), x, 1, (f^4*F^(a + b*(c - (d*e)/f))*Gamma[5, -((b*d*(e + f*x)*Log[F])/f)])/(b^5*d^5*Log[F]^5)}
{(e + f*x)^4*F^(a + b*(c + d*x))/x^1, x, 14, e^4*F^(a + b*c)*ExpIntegralEi[b*d*x*Log[F]] - (6*f^4*F^(a + b*c + b*d*x))/(b^4*d^4*Log[F]^4) + (8*e*f^3*F^(a + b*c + b*d*x))/(b^3*d^3*Log[F]^3) + (6*f^4*F^(a + b*c + b*d*x)*x)/(b^3*d^3*Log[F]^3) - (6*e^2*f^2*F^(a + b*c + b*d*x))/(b^2*d^2*Log[F]^2) - (8*e*f^3*F^(a + b*c + b*d*x)*x)/(b^2*d^2*Log[F]^2) - (3*f^4*F^(a + b*c + b*d*x)*x^2)/(b^2*d^2*Log[F]^2) + (4*e^3*f*F^(a + b*c + b*d*x))/(b*d*Log[F]) + (6*e^2*f^2*F^(a + b*c + b*d*x)*x)/(b*d*Log[F]) + (4*e*f^3*F^(a + b*c + b*d*x)*x^2)/(b*d*Log[F]) + (f^4*F^(a + b*c + b*d*x)*x^3)/(b*d*Log[F])}
{(e + f*x)^4*F^(a + b*(c + d*x))/x^2, x, 12, -((e^4*F^(a + b*c + b*d*x))/x) + 4*e^3*f*F^(a + b*c)*ExpIntegralEi[b*d*x*Log[F]] + (2*f^4*F^(a + b*c + b*d*x))/(b^3*d^3*Log[F]^3) - (4*e*f^3*F^(a + b*c + b*d*x))/(b^2*d^2*Log[F]^2) - (2*f^4*F^(a + b*c + b*d*x)*x)/(b^2*d^2*Log[F]^2) + (6*e^2*f^2*F^(a + b*c + b*d*x))/(b*d*Log[F]) + (4*e*f^3*F^(a + b*c + b*d*x)*x)/(b*d*Log[F]) + (f^4*F^(a + b*c + b*d*x)*x^2)/(b*d*Log[F]) + b*d*e^4*F^(a + b*c)*ExpIntegralEi[b*d*x*Log[F]]*Log[F]}
{(e + f*x)^4*F^(a + b*(c + d*x))/x^3, x, 12, -((e^4*F^(a + b*c + b*d*x))/(2*x^2)) - (4*e^3*f*F^(a + b*c + b*d*x))/x + 6*e^2*f^2*F^(a + b*c)*ExpIntegralEi[b*d*x*Log[F]] - (f^4*F^(a + b*c + b*d*x))/(b^2*d^2*Log[F]^2) + (4*e*f^3*F^(a + b*c + b*d*x))/(b*d*Log[F]) + (f^4*F^(a + b*c + b*d*x)*x)/(b*d*Log[F]) - (b*d*e^4*F^(a + b*c + b*d*x)*Log[F])/(2*x) + 4*b*d*e^3*f*F^(a + b*c)*ExpIntegralEi[b*d*x*Log[F]]*Log[F] + (1/2)*b^2*d^2*e^4*F^(a + b*c)*ExpIntegralEi[b*d*x*Log[F]]*Log[F]^2}
{(e + f*x)^4*F^(a + b*(c + d*x))/x^4, x, 14, -((e^4*F^(a + b*c + b*d*x))/(3*x^3)) - (2*e^3*f*F^(a + b*c + b*d*x))/x^2 - (6*e^2*f^2*F^(a + b*c + b*d*x))/x + 4*e*f^3*F^(a + b*c)*ExpIntegralEi[b*d*x*Log[F]] + (f^4*F^(a + b*c + b*d*x))/(b*d*Log[F]) - (b*d*e^4*F^(a + b*c + b*d*x)*Log[F])/(6*x^2) - (2*b*d*e^3*f*F^(a + b*c + b*d*x)*Log[F])/x + 6*b*d*e^2*f^2*F^(a + b*c)*ExpIntegralEi[b*d*x*Log[F]]*Log[F] - (b^2*d^2*e^4*F^(a + b*c + b*d*x)*Log[F]^2)/(6*x) + 2*b^2*d^2*e^3*f*F^(a + b*c)*ExpIntegralEi[b*d*x*Log[F]]*Log[F]^2 + (1/6)*b^3*d^3*e^4*F^(a + b*c)*ExpIntegralEi[b*d*x*Log[F]]*Log[F]^3}
{(e + f*x)^4*F^(a + b*(c + d*x))/x^5, x, 14, -((4*e^3*f*F^(a + b*c + b*d*x))/(3*x^3)) - (3*e^2*f^2*F^(a + b*c + b*d*x))/x^2 - (4*e*f^3*F^(a + b*c + b*d*x))/x + f^4*F^(a + b*c)*ExpIntegralEi[b*d*x*Log[F]] - (2*b*d*e^3*f*F^(a + b*c + b*d*x)*Log[F])/(3*x^2) - (3*b*d*e^2*f^2*F^(a + b*c + b*d*x)*Log[F])/x + 4*b*d*e*f^3*F^(a + b*c)*ExpIntegralEi[b*d*x*Log[F]]*Log[F] - (2*b^2*d^2*e^3*f*F^(a + b*c + b*d*x)*Log[F]^2)/(3*x) + 3*b^2*d^2*e^2*f^2*F^(a + b*c)*ExpIntegralEi[b*d*x*Log[F]]*Log[F]^2 + (2/3)*b^3*d^3*e^3*f*F^(a + b*c)*ExpIntegralEi[b*d*x*Log[F]]*Log[F]^3 - b^4*d^4*e^4*F^(a + b*c)*Gamma[-4, (-b)*d*x*Log[F]]*Log[F]^4}
{(e + f*x)^4*F^(a + b*(c + d*x))/x^6, x, 14, -((2*e^2*f^2*F^(a + b*c + b*d*x))/x^3) - (2*e*f^3*F^(a + b*c + b*d*x))/x^2 - (f^4*F^(a + b*c + b*d*x))/x - (b*d*e^2*f^2*F^(a + b*c + b*d*x)*Log[F])/x^2 - (2*b*d*e*f^3*F^(a + b*c + b*d*x)*Log[F])/x + b*d*f^4*F^(a + b*c)*ExpIntegralEi[b*d*x*Log[F]]*Log[F] - (b^2*d^2*e^2*f^2*F^(a + b*c + b*d*x)*Log[F]^2)/x + 2*b^2*d^2*e*f^3*F^(a + b*c)*ExpIntegralEi[b*d*x*Log[F]]*Log[F]^2 + b^3*d^3*e^2*f^2*F^(a + b*c)*ExpIntegralEi[b*d*x*Log[F]]*Log[F]^3 - 4*b^4*d^4*e^3*f*F^(a + b*c)*Gamma[-4, (-b)*d*x*Log[F]]*Log[F]^4 + b^5*d^5*e^4*F^(a + b*c)*Gamma[-5, (-b)*d*x*Log[F]]*Log[F]^5}
{(e + f*x)^4*F^(a + b*(c + d*x))/x^7, x, 13, -((4*e*f^3*F^(a + b*c + b*d*x))/(3*x^3)) - (f^4*F^(a + b*c + b*d*x))/(2*x^2) - (2*b*d*e*f^3*F^(a + b*c + b*d*x)*Log[F])/(3*x^2) - (b*d*f^4*F^(a + b*c + b*d*x)*Log[F])/(2*x) - (2*b^2*d^2*e*f^3*F^(a + b*c + b*d*x)*Log[F]^2)/(3*x) + (1/2)*b^2*d^2*f^4*F^(a + b*c)*ExpIntegralEi[b*d*x*Log[F]]*Log[F]^2 + (2/3)*b^3*d^3*e*f^3*F^(a + b*c)*ExpIntegralEi[b*d*x*Log[F]]*Log[F]^3 - 6*b^4*d^4*e^2*f^2*F^(a + b*c)*Gamma[-4, (-b)*d*x*Log[F]]*Log[F]^4 + 4*b^5*d^5*e^3*f*F^(a + b*c)*Gamma[-5, (-b)*d*x*Log[F]]*Log[F]^5 - b^6*d^6*e^4*F^(a + b*c)*Gamma[-6, (-b)*d*x*Log[F]]*Log[F]^6}
{(e + f*x)^4*F^(a + b*(c + d*x))/x^8, x, 11, -((f^4*F^(a + b*c + b*d*x))/(3*x^3)) - (b*d*f^4*F^(a + b*c + b*d*x)*Log[F])/(6*x^2) - (b^2*d^2*f^4*F^(a + b*c + b*d*x)*Log[F]^2)/(6*x) + (1/6)*b^3*d^3*f^4*F^(a + b*c)*ExpIntegralEi[b*d*x*Log[F]]*Log[F]^3 - 4*b^4*d^4*e*f^3*F^(a + b*c)*Gamma[-4, (-b)*d*x*Log[F]]*Log[F]^4 + 6*b^5*d^5*e^2*f^2*F^(a + b*c)*Gamma[-5, (-b)*d*x*Log[F]]*Log[F]^5 - 4*b^6*d^6*e^3*f*F^(a + b*c)*Gamma[-6, (-b)*d*x*Log[F]]*Log[F]^6 + b^7*d^7*e^4*F^(a + b*c)*Gamma[-7, (-b)*d*x*Log[F]]*Log[F]^7}


(* ::Subsection::Closed:: *)
(*Integrands of the form (c+d x)^m (a+b x)^n f^(e (a+b x))*)


{(c + d*x)^6*(a + b*x)^6/E^(a + b*x), x, 9, -(((b*c - a*d)^6*Gamma[7, a + b*x])/b^7) - (6*d*(b*c - a*d)^5*Gamma[8, a + b*x])/b^7 - (15*d^2*(b*c - a*d)^4*Gamma[9, a + b*x])/b^7 - (20*d^3*(b*c - a*d)^3*Gamma[10, a + b*x])/b^7 - (15*d^4*(b*c - a*d)^2*Gamma[11, a + b*x])/b^7 - (6*d^5*(b*c - a*d)*Gamma[12, a + b*x])/b^7 - (d^6*Gamma[13, a + b*x])/b^7}
{(c + d*x)^5*(a + b*x)^6/E^(a + b*x), x, 8, -(((b*c - a*d)^5*Gamma[7, a + b*x])/b^6) - (5*d*(b*c - a*d)^4*Gamma[8, a + b*x])/b^6 - (10*d^2*(b*c - a*d)^3*Gamma[9, a + b*x])/b^6 - (10*d^3*(b*c - a*d)^2*Gamma[10, a + b*x])/b^6 - (5*d^4*(b*c - a*d)*Gamma[11, a + b*x])/b^6 - (d^5*Gamma[12, a + b*x])/b^6}
{(c + d*x)^4*(a + b*x)^6/E^(a + b*x), x, 7, -(((b*c - a*d)^4*Gamma[7, a + b*x])/b^5) - (4*d*(b*c - a*d)^3*Gamma[8, a + b*x])/b^5 - (6*d^2*(b*c - a*d)^2*Gamma[9, a + b*x])/b^5 - (4*d^3*(b*c - a*d)*Gamma[10, a + b*x])/b^5 - (d^4*Gamma[11, a + b*x])/b^5}
{(c + d*x)^3*(a + b*x)^6/E^(a + b*x), x, 6, -(((b*c - a*d)^3*Gamma[7, a + b*x])/b^4) - (3*d*(b*c - a*d)^2*Gamma[8, a + b*x])/b^4 - (3*d^2*(b*c - a*d)*Gamma[9, a + b*x])/b^4 - (d^3*Gamma[10, a + b*x])/b^4}
{(c + d*x)^2*(a + b*x)^6/E^(a + b*x), x, 5, -(((b*c - a*d)^2*Gamma[7, a + b*x])/b^3) - (2*d*(b*c - a*d)*Gamma[8, a + b*x])/b^3 - (d^2*Gamma[9, a + b*x])/b^3}
{(c + d*x)^1*(a + b*x)^6/E^(a + b*x), x, 4, -(((b*c - a*d)*Gamma[7, a + b*x])/b^2) - (d*Gamma[8, a + b*x])/b^2}
{(c + d*x)^0*(a + b*x)^6/E^(a + b*x), x, 1, -(Gamma[7, a + b*x]/b)}
{(a + b*x)^6/((c + d*x)^1*E^(a + b*x)), x, 15, -((6*(b*c - a*d)^2*E^(-a - b*x))/d^3) + (2*(b*c - a*d)^3*E^(-a - b*x))/d^4 - ((b*c - a*d)^4*E^(-a - b*x))/d^5 + ((b*c - a*d)^5*E^(-a - b*x))/d^6 - (6*(b*c - a*d)^2*E^(-a - b*x)*(a + b*x))/d^3 + (2*(b*c - a*d)^3*E^(-a - b*x)*(a + b*x))/d^4 - ((b*c - a*d)^4*E^(-a - b*x)*(a + b*x))/d^5 - (3*(b*c - a*d)^2*E^(-a - b*x)*(a + b*x)^2)/d^3 + ((b*c - a*d)^3*E^(-a - b*x)*(a + b*x)^2)/d^4 - ((b*c - a*d)^2*E^(-a - b*x)*(a + b*x)^3)/d^3 + ((b*c - a*d)^6*E^(-a + (b*c)/d)*ExpIntegralEi[-((b*(c + d*x))/d)])/d^7 + ((b*c - a*d)*Gamma[5, a + b*x])/d^2 - Gamma[6, a + b*x]/d}
{(a + b*x)^6/((c + d*x)^2*E^(a + b*x)), x, 16, (36*b*(b*c - a*d)*E^(-a - b*x))/d^3 - (30*b*(b*c - a*d)^2*E^(-a - b*x))/d^4 + (20*b*(b*c - a*d)^3*E^(-a - b*x))/d^5 - (15*b*(b*c - a*d)^4*E^(-a - b*x))/d^6 - ((b*c - a*d)^6*E^(-a - b*x))/(d^7*(c + d*x)) + (36*b^2*(b*c - a*d)*E^(-a - b*x)*(c + d*x))/d^4 - (30*b^2*(b*c - a*d)^2*E^(-a - b*x)*(c + d*x))/d^5 + (20*b^2*(b*c - a*d)^3*E^(-a - b*x)*(c + d*x))/d^6 + (18*b^3*(b*c - a*d)*E^(-a - b*x)*(c + d*x)^2)/d^5 - (15*b^3*(b*c - a*d)^2*E^(-a - b*x)*(c + d*x)^2)/d^6 + (6*b^4*(b*c - a*d)*E^(-a - b*x)*(c + d*x)^3)/d^6 - (6*b*(b*c - a*d)^5*E^(-a + (b*c)/d)*ExpIntegralEi[-((b*(c + d*x))/d)])/d^7 - (b*(b*c - a*d)^6*E^(-a + (b*c)/d)*ExpIntegralEi[-((b*(c + d*x))/d)])/d^8 - (b*E^(-a + (b*c)/d)*Gamma[5, (b*(c + d*x))/d])/d^2}
{(a + b*x)^6/((c + d*x)^3*E^(a + b*x)), x, 18, -((6*b^2*E^(-a - b*x))/d^3) + (12*b^2*(b*c - a*d)*E^(-a - b*x))/d^4 - (15*b^2*(b*c - a*d)^2*E^(-a - b*x))/d^5 + (20*b^2*(b*c - a*d)^3*E^(-a - b*x))/d^6 - ((b*c - a*d)^6*E^(-a - b*x))/(2*d^7*(c + d*x)^2) + (6*b*(b*c - a*d)^5*E^(-a - b*x))/(d^7*(c + d*x)) + (b*(b*c - a*d)^6*E^(-a - b*x))/(2*d^8*(c + d*x)) - (6*b^3*E^(-a - b*x)*(c + d*x))/d^4 + (12*b^3*(b*c - a*d)*E^(-a - b*x)*(c + d*x))/d^5 - (15*b^3*(b*c - a*d)^2*E^(-a - b*x)*(c + d*x))/d^6 - (3*b^4*E^(-a - b*x)*(c + d*x)^2)/d^5 + (6*b^4*(b*c - a*d)*E^(-a - b*x)*(c + d*x)^2)/d^6 - (b^5*E^(-a - b*x)*(c + d*x)^3)/d^6 + (15*b^2*(b*c - a*d)^4*E^(-a + (b*c)/d)*ExpIntegralEi[-((b*(c + d*x))/d)])/d^7 + (6*b^2*(b*c - a*d)^5*E^(-a + (b*c)/d)*ExpIntegralEi[-((b*(c + d*x))/d)])/d^8 + (b^2*(b*c - a*d)^6*E^(-a + (b*c)/d)*ExpIntegralEi[-((b*(c + d*x))/d)])/(2*d^9)}


(* ::Subsection::Closed:: *)
(*Integrands of the form x^m f^(a+b x+c x^2)*)


{x^3*f^(a + b*x + c*x^2), x, 10, -(f^(a + b*x + c*x^2)/(2*c^2*Log[f]^2)) + (3*b*f^(a - b^2/(4*c))*Sqrt[Pi]*Erfi[((b + 2*c*x)*Sqrt[Log[f]])/(2*Sqrt[c])])/(8*c^(5/2)*Log[f]^(3/2)) + (b^2*f^(a + b*x + c*x^2))/(8*c^3*Log[f]) - (b*f^(a + b*x + c*x^2)*x)/(4*c^2*Log[f]) + (f^(a + b*x + c*x^2)*x^2)/(2*c*Log[f]) - (b^3*f^(a - b^2/(4*c))*Sqrt[Pi]*Erfi[((b + 2*c*x)*Sqrt[Log[f]])/(2*Sqrt[c])])/(16*c^(7/2)*Sqrt[Log[f]])}
{x^2*f^(a + b*x + c*x^2), x, 6, -((f^(a - b^2/(4*c))*Sqrt[Pi]*Erfi[((b + 2*c*x)*Sqrt[Log[f]])/(2*Sqrt[c])])/(4*c^(3/2)*Log[f]^(3/2))) - (b*f^(a + b*x + c*x^2))/(4*c^2*Log[f]) + (f^(a + b*x + c*x^2)*x)/(2*c*Log[f]) + (b^2*f^(a - b^2/(4*c))*Sqrt[Pi]*Erfi[((b + 2*c*x)*Sqrt[Log[f]])/(2*Sqrt[c])])/(8*c^(5/2)*Sqrt[Log[f]])}
{x*f^(a + b*x + c*x^2), x, 3, f^(a + b*x + c*x^2)/(2*c*Log[f]) - (b*f^(a - b^2/(4*c))*Sqrt[Pi]*Erfi[((b + 2*c*x)*Sqrt[Log[f]])/(2*Sqrt[c])])/(4*c^(3/2)*Sqrt[Log[f]])}
{f^(a + b*x + c*x^2), x, 2, (f^(a - b^2/(4*c))*Sqrt[Pi]*Erfi[((b + 2*c*x)*Sqrt[Log[f]])/(2*Sqrt[c])])/(2*Sqrt[c]*Sqrt[Log[f]])}
{f^(a + b*x + c*x^2)/x, x, 0, Int[f^(a + b*x + c*x^2)/x, x]}
{f^(a + b*x + c*x^2)/x^2, x, 3, -(f^(a + b*x + c*x^2)/x) + Sqrt[c]*f^(a - b^2/(4*c))*Sqrt[Pi]*Erfi[((b + 2*c*x)*Sqrt[Log[f]])/(2*Sqrt[c])]*Sqrt[Log[f]] + b*Int[f^(a + b*x + c*x^2)/x, x]*Log[f]}


{x^3*E^(a + b*x - c*x^2), x, 10, -((b^2*E^(a + b*x - c*x^2))/(8*c^3)) - E^(a + b*x - c*x^2)/(2*c^2) - (b*E^(a + b*x - c*x^2)*x)/(4*c^2) - (E^(a + b*x - c*x^2)*x^2)/(2*c) - (b^3*E^(a + b^2/(4*c))*Sqrt[Pi]*Erf[(b - 2*c*x)/(2*Sqrt[c])])/(16*c^(7/2)) - (3*b*E^(a + b^2/(4*c))*Sqrt[Pi]*Erf[(b - 2*c*x)/(2*Sqrt[c])])/(8*c^(5/2))}
{x^2*E^(a + b*x - c*x^2), x, 6, -((b*E^(a + b*x - c*x^2))/(4*c^2)) - (E^(a + b*x - c*x^2)*x)/(2*c) - (b^2*E^(a + b^2/(4*c))*Sqrt[Pi]*Erf[(b - 2*c*x)/(2*Sqrt[c])])/(8*c^(5/2)) - (E^(a + b^2/(4*c))*Sqrt[Pi]*Erf[(b - 2*c*x)/(2*Sqrt[c])])/(4*c^(3/2))}
{x*E^(a + b*x - c*x^2), x, 3, -(E^(a + b*x - c*x^2)/(2*c)) - (b*E^(a + b^2/(4*c))*Sqrt[Pi]*Erf[(b - 2*c*x)/(2*Sqrt[c])])/(4*c^(3/2))}
{E^(a + b*x - c*x^2), x, 2, -((E^(a + b^2/(4*c))*Sqrt[Pi]*Erf[(b - 2*c*x)/(2*Sqrt[c])])/(2*Sqrt[c]))}
{E^(a + b*x - c*x^2)/x, x, 0, Int[E^(a + b*x - c*x^2)/x, x]}
{E^(a + b*x - c*x^2)/x^2, x, 3, -(E^(a + b*x - c*x^2)/x) + Sqrt[c]*E^(a + b^2/(4*c))*Sqrt[Pi]*Erf[(b - 2*c*x)/(2*Sqrt[c])] + b*Int[E^(a + b*x - c*x^2)/x, x]}


{x^3*E^((a + b*x)*(c + d*x)), x, 11, -(E^(a*c + (b*c + a*d)*x + b*d*x^2)/(2*b^2*d^2)) + ((b*c + a*d)^2*E^(a*c + (b*c + a*d)*x + b*d*x^2))/(8*b^3*d^3) - ((b*c + a*d)*E^(a*c + (b*c + a*d)*x + b*d*x^2)*x)/(4*b^2*d^2) + (E^(a*c + (b*c + a*d)*x + b*d*x^2)*x^2)/(2*b*d) + (3*(b*c + a*d)*Sqrt[Pi]*Erfi[(b*c + a*d + 2*b*d*x)/(2*Sqrt[b]*Sqrt[d])])/(E^((b*c - a*d)^2/(4*b*d))*(8*b^(5/2)*d^(5/2))) - ((b*c + a*d)^3*Sqrt[Pi]*Erfi[(b*c + a*d + 2*b*d*x)/(2*Sqrt[b]*Sqrt[d])])/(E^((b*c - a*d)^2/(4*b*d))*(16*b^(7/2)*d^(7/2)))}
{x^2*E^((a + b*x)*(c + d*x)), x, 7, -(((b*c + a*d)*E^(a*c + (b*c + a*d)*x + b*d*x^2))/(4*b^2*d^2)) + (E^(a*c + (b*c + a*d)*x + b*d*x^2)*x)/(2*b*d) - (Sqrt[Pi]*Erfi[(b*c + a*d + 2*b*d*x)/(2*Sqrt[b]*Sqrt[d])])/(E^((b*c - a*d)^2/(4*b*d))*(4*b^(3/2)*d^(3/2))) + ((b*c + a*d)^2*Sqrt[Pi]*Erfi[(b*c + a*d + 2*b*d*x)/(2*Sqrt[b]*Sqrt[d])])/(E^((b*c - a*d)^2/(4*b*d))*(8*b^(5/2)*d^(5/2)))}
{x*E^((a + b*x)*(c + d*x)), x, 4, E^(a*c + (b*c + a*d)*x + b*d*x^2)/(2*b*d) - ((b*c + a*d)*Sqrt[Pi]*Erfi[(b*c + a*d + 2*b*d*x)/(2*Sqrt[b]*Sqrt[d])])/(E^((b*c - a*d)^2/(4*b*d))*(4*b^(3/2)*d^(3/2)))}
{E^((a + b*x)*(c + d*x)), x, 3, (Sqrt[Pi]*Erfi[(b*c + a*d + 2*b*d*x)/(2*Sqrt[b]*Sqrt[d])])/(E^((b*c - a*d)^2/(4*b*d))*(2*Sqrt[b]*Sqrt[d]))}
{E^((a + b*x)*(c + d*x))/x, x, 1, Int[E^(a*c + (b*c + a*d)*x + b*d*x^2)/x, x]}
{E^((a + b*x)*(c + d*x))/x^2, x, 4, -(E^(a*c + (b*c + a*d)*x + b*d*x^2)/x) + (Sqrt[b]*Sqrt[d]*Sqrt[Pi]*Erfi[(b*c + a*d + 2*b*d*x)/(2*Sqrt[b]*Sqrt[d])])/E^((b*c - a*d)^2/(4*b*d)) + (b*c + a*d)*Int[E^(a*c + (b*c + a*d)*x + b*d*x^2)/x, x]}


(* ::Subsection::Closed:: *)
(*Integrands of the form (d+e x)^m f^(a+b x+c x^2)*)


{(d + e*x)^3*f^(a + b*x + c*x^2), x, 10, -((e^3*f^(a + b*x + c*x^2))/(2*c^2*Log[f]^2)) - (3*e^2*(2*c*d - b*e)*f^(a - b^2/(4*c))*Sqrt[Pi]*Erfi[((b + 2*c*x)*Sqrt[Log[f]])/(2*Sqrt[c])])/(8*c^(5/2)*Log[f]^(3/2)) + (e*(2*c*d - b*e)^2*f^(a + b*x + c*x^2))/(8*c^3*Log[f]) + (e*(2*c*d - b*e)*f^(a + b*x + c*x^2)*(d + e*x))/(4*c^2*Log[f]) + (e*f^(a + b*x + c*x^2)*(d + e*x)^2)/(2*c*Log[f]) + ((2*c*d - b*e)^3*f^(a - b^2/(4*c))*Sqrt[Pi]*Erfi[((b + 2*c*x)*Sqrt[Log[f]])/(2*Sqrt[c])])/(16*c^(7/2)*Sqrt[Log[f]])}
{(d + e*x)^2*f^(a + b*x + c*x^2), x, 6, -((e^2*f^(a - b^2/(4*c))*Sqrt[Pi]*Erfi[((b + 2*c*x)*Sqrt[Log[f]])/(2*Sqrt[c])])/(4*c^(3/2)*Log[f]^(3/2))) + (e*(2*c*d - b*e)*f^(a + b*x + c*x^2))/(4*c^2*Log[f]) + (e*f^(a + b*x + c*x^2)*(d + e*x))/(2*c*Log[f]) + ((2*c*d - b*e)^2*f^(a - b^2/(4*c))*Sqrt[Pi]*Erfi[((b + 2*c*x)*Sqrt[Log[f]])/(2*Sqrt[c])])/(8*c^(5/2)*Sqrt[Log[f]])}
{(d + e*x)*f^(a + b*x + c*x^2), x, 3, (e*f^(a + b*x + c*x^2))/(2*c*Log[f]) + ((2*c*d - b*e)*f^(a - b^2/(4*c))*Sqrt[Pi]*Erfi[((b + 2*c*x)*Sqrt[Log[f]])/(2*Sqrt[c])])/(4*c^(3/2)*Sqrt[Log[f]])}
{f^(a + b*x + c*x^2)/(d + e*x), x, 0, Int[f^(a + b*x + c*x^2)/(d + e*x), x]}
{f^(a + b*x + c*x^2)/(d + e*x)^2, x, 3, -(f^(a + b*x + c*x^2)/(e*(d + e*x))) + (Sqrt[c]*f^(a - b^2/(4*c))*Sqrt[Pi]*Erfi[((b + 2*c*x)*Sqrt[Log[f]])/(2*Sqrt[c])]*Sqrt[Log[f]])/e^2 - ((2*c*d - b*e)*Int[f^(a + b*x + c*x^2)/(d + e*x), x]*Log[f])/e^2}
{f^(a + b*x + c*x^2)/(d + e*x)^3, x, 4, -(f^(a + b*x + c*x^2)/(2*e*(d + e*x)^2)) + ((2*c*d - b*e)*f^(a + b*x + c*x^2)*Log[f])/(2*e^3*(d + e*x)) + (c*Int[f^(a + b*x + c*x^2)/(d + e*x), x]*Log[f])/e^2 - (Sqrt[c]*(2*c*d - b*e)*f^(a - b^2/(4*c))*Sqrt[Pi]*Erfi[((b + 2*c*x)*Sqrt[Log[f]])/(2*Sqrt[c])]*Log[f]^(3/2))/(2*e^4) + ((2*c*d - b*e)^2*Int[f^(a + b*x + c*x^2)/(d + e*x), x]*Log[f]^2)/(2*e^4)}


{(b + 2*c*x)^3*f^(a + b*x + c*x^2), x, 2, -((4*c*f^(a + b*x + c*x^2))/Log[f]^2) + (f^(a + b*x + c*x^2)*(b + 2*c*x)^2)/Log[f]}
{(b + 2*c*x)^2*f^(a + b*x + c*x^2), x, 3, -((Sqrt[c]*f^(a - b^2/(4*c))*Sqrt[Pi]*Erfi[((b + 2*c*x)*Sqrt[Log[f]])/(2*Sqrt[c])])/Log[f]^(3/2)) + (f^(a + b*x + c*x^2)*(b + 2*c*x))/Log[f]}
{(b + 2*c*x)*f^(a + b*x + c*x^2), x, 1, f^(a + b*x + c*x^2)/Log[f]}
{f^(a + b*x + c*x^2)/(b + 2*c*x), x, 1, (f^(a - b^2/(4*c))*ExpIntegralEi[((b + 2*c*x)^2*Log[f])/(4*c)])/(4*c)}
{f^(a + b*x + c*x^2)/(b + 2*c*x)^2, x, 3, -(f^(a + b*x + c*x^2)/(2*c*(b + 2*c*x))) + (f^(a - b^2/(4*c))*Sqrt[Pi]*Erfi[((b + 2*c*x)*Sqrt[Log[f]])/(2*Sqrt[c])]*Sqrt[Log[f]])/(4*c^(3/2))}
{f^(a + b*x + c*x^2)/(b + 2*c*x)^3, x, 2, -(f^(a + b*x + c*x^2)/(4*c*(b + 2*c*x)^2)) + (f^(a - b^2/(4*c))*ExpIntegralEi[((b + 2*c*x)^2*Log[f])/(4*c)]*Log[f])/(16*c^2)}


{(b + 2*c*x)^3*f^(b*x + c*x^2), x, 2, -((4*c*f^(b*x + c*x^2))/Log[f]^2) + (f^(b*x + c*x^2)*(b + 2*c*x)^2)/Log[f]}
{(b + 2*c*x)^2*f^(b*x + c*x^2), x, 3, -((Sqrt[c]*Sqrt[Pi]*Erfi[((b + 2*c*x)*Sqrt[Log[f]])/(2*Sqrt[c])])/(f^(b^2/(4*c))*Log[f]^(3/2))) + (f^(b*x + c*x^2)*(b + 2*c*x))/Log[f]}
{(b + 2*c*x)*f^(b*x + c*x^2), x, 1, f^(b*x + c*x^2)/Log[f]}
{f^(b*x + c*x^2)/(b + 2*c*x), x, 1, ExpIntegralEi[((b + 2*c*x)^2*Log[f])/(4*c)]/(f^(b^2/(4*c))*(4*c))}
{f^(b*x + c*x^2)/(b + 2*c*x)^2, x, 3, -(f^(b*x + c*x^2)/(2*c*(b + 2*c*x))) + (Sqrt[Pi]*Erfi[((b + 2*c*x)*Sqrt[Log[f]])/(2*Sqrt[c])]*Sqrt[Log[f]])/(f^(b^2/(4*c))*(4*c^(3/2)))}
{f^(b*x + c*x^2)/(b + 2*c*x)^3, x, 2, -(f^(b*x + c*x^2)/(4*c*(b + 2*c*x)^2)) + (ExpIntegralEi[((b + 2*c*x)^2*Log[f])/(4*c)]*Log[f])/(f^(b^2/(4*c))*(16*c^2))}


(* ::Subsection::Closed:: *)
(*Integrands of the form x^m (f^(c (a+b x)))^n*)


{Sqrt[E^(a + b*x)]*x^3, x, 5, -((96*Sqrt[E^(a + b*x)])/b^4) + (48*Sqrt[E^(a + b*x)]*x)/b^3 - (12*Sqrt[E^(a + b*x)]*x^2)/b^2 + (2*Sqrt[E^(a + b*x)]*x^3)/b}
{Sqrt[E^(a + b*x)]*x^2, x, 4, (16*Sqrt[E^(a + b*x)])/b^3 - (8*Sqrt[E^(a + b*x)]*x)/b^2 + (2*Sqrt[E^(a + b*x)]*x^2)/b}
{Sqrt[E^(a + b*x)]*x^1, x, 3, -((4*Sqrt[E^(a + b*x)])/b^2) + (2*Sqrt[E^(a + b*x)]*x)/b}
{Sqrt[E^(a + b*x)]*x^0, x, 2, (2*Sqrt[E^(a + b*x)])/b}
{Sqrt[E^(a + b*x)]/x^1, x, 2, (Sqrt[E^(a + b*x)]*ExpIntegralEi[(b*x)/2])/E^((b*x)/2)}
{Sqrt[E^(a + b*x)]/x^2, x, 3, -(Sqrt[E^(a + b*x)]/x) + ((1/2)*b*Sqrt[E^(a + b*x)]*ExpIntegralEi[(b*x)/2])/E^((b*x)/2)}
{Sqrt[E^(a + b*x)]/x^3, x, 4, -(Sqrt[E^(a + b*x)]/(2*x^2)) - (b*Sqrt[E^(a + b*x)])/(4*x) + ((1/8)*b^2*Sqrt[E^(a + b*x)]*ExpIntegralEi[(b*x)/2])/E^((b*x)/2)}


(* ::Subsection::Closed:: *)
(*Integrands of the form x^m (a+b f^(c+d x))^n*)


(* Integrands of the form x^m/(a+b*E^(c+d*x))^n where m and n are positive integers *)
{x/(a + b*E^(c + d*x)), x, 3, x^2/(2*a) - (x*Log[1 + (b*E^(c + d*x))/a])/(a*d) - PolyLog[2, -((b*E^(c + d*x))/a)]/(a*d^2)}
{x^2/(a + b*E^(c + d*x)), x, 4, x^3/(3*a) - (x^2*Log[1 + (b*E^(c + d*x))/a])/(a*d) - (2*x*PolyLog[2, -((b*E^(c + d*x))/a)])/(a*d^2) + (2*PolyLog[3, -((b*E^(c + d*x))/a)])/(a*d^3)}
{x^3/(a + b*E^(c + d*x)), x, 5, x^4/(4*a) - (x^3*Log[1 + (b*E^(c + d*x))/a])/(a*d) - (3*x^2*PolyLog[2, -((b*E^(c + d*x))/a)])/(a*d^2) + (6*x*PolyLog[3, -((b*E^(c + d*x))/a)])/(a*d^3) - (6*PolyLog[4, -((b*E^(c + d*x))/a)])/(a*d^4)}

{x/(a + b*E^(c + d*x))^2, x, 5, -(x/(a^2*d)) + x/(a*d*(a + b*E^(c + d*x))) + x^2/(2*a^2) + Log[a + b*E^(c + d*x)]/(a^2*d^2) - (x*Log[1 + (b*E^(c + d*x))/a])/(a^2*d) - PolyLog[2, -((b*E^(c + d*x))/a)]/(a^2*d^2)}
{x^2/(a + b*E^(c + d*x))^2, x, 11, -(x^2/(a^2*d)) + x^2/(a*d*(a + b*E^(c + d*x))) + x^3/(3*a^2) + (2*x*Log[1 + (b*E^(c + d*x))/a])/(a^2*d^2) - (x^2*Log[1 + (b*E^(c + d*x))/a])/(a^2*d) + (2*PolyLog[2, -((b*E^(c + d*x))/a)])/(a^2*d^3) - (2*x*PolyLog[2, -((b*E^(c + d*x))/a)])/(a^2*d^2) + (2*PolyLog[3, -((b*E^(c + d*x))/a)])/(a^2*d^3)}
{x^3/(a + b*E^(c + d*x))^2, x, 13, -(x^3/(a^2*d)) + x^3/(a*d*(a + b*E^(c + d*x))) + x^4/(4*a^2) + (3*x^2*Log[1 + (b*E^(c + d*x))/a])/(a^2*d^2) - (x^3*Log[1 + (b*E^(c + d*x))/a])/(a^2*d) + (6*x*PolyLog[2, -((b*E^(c + d*x))/a)])/(a^2*d^3) - (3*x^2*PolyLog[2, -((b*E^(c + d*x))/a)])/(a^2*d^2) - (6*PolyLog[3, -((b*E^(c + d*x))/a)])/(a^2*d^4) + (6*x*PolyLog[3, -((b*E^(c + d*x))/a)])/(a^2*d^3) - (6*PolyLog[4, -((b*E^(c + d*x))/a)])/(a^2*d^4)}

{x/(a + b*E^(c + d*x))^3, x, 7, -(1/(2*a^2*d^2*(a + b*E^(c + d*x)))) - (3*x)/(2*a^3*d) + x/(2*a*d*(a + b*E^(c + d*x))^2) + x/(a^2*d*(a + b*E^(c + d*x))) + x^2/(2*a^3) + (3*Log[a + b*E^(c + d*x)])/(2*a^3*d^2) - (x*Log[1 + (b*E^(c + d*x))/a])/(a^3*d) - PolyLog[2, -((b*E^(c + d*x))/a)]/(a^3*d^2)}
{x^2/(a + b*E^(c + d*x))^3, x, 16, x/(a^3*d^2) - x/(a^2*d^2*(a + b*E^(c + d*x))) - (3*x^2)/(2*a^3*d) + x^2/(2*a*d*(a + b*E^(c + d*x))^2) + x^2/(a^2*d*(a + b*E^(c + d*x))) + x^3/(3*a^3) - Log[a + b*E^(c + d*x)]/(a^3*d^3) + (3*x*Log[1 + (b*E^(c + d*x))/a])/(a^3*d^2) - (x^2*Log[1 + (b*E^(c + d*x))/a])/(a^3*d) + (3*PolyLog[2, -((b*E^(c + d*x))/a)])/(a^3*d^3) - (2*x*PolyLog[2, -((b*E^(c + d*x))/a)])/(a^3*d^2) + (2*PolyLog[3, -((b*E^(c + d*x))/a)])/(a^3*d^3)}
(* {x^3/(a + b*E^(c + d*x))^3, x, 30, (1/(4*a^3*d^4*(a + b*E^(c + d*x))^2))*(6*a*b*d^2*E^(c + d*x)*x^2 + 6*b^2*d^2*E^(2*(c + d*x))*x^2 - 8*a*b*d^3*E^(c + d*x)*x^3 - 6*b^2*d^3*E^(2*(c + d*x))*x^3 + a^2*d^4*x^4 + 2*a*b*d^4*E^(c + d*x)*x^4 + b^2*d^4*E^(2*(c + d*x))*x^4 - 12*a^2*d*x*Log[1 + (b*E^(c + d*x))/a] - 24*a*b*d*E^(c + d*x)*x*Log[1 + (b*E^(c + d*x))/a] - 12*b^2*d*E^(2*(c + d*x))*x*Log[1 + (b*E^(c + d*x))/a] + 18*a^2*d^2*x^2*Log[1 + (b*E^(c + d*x))/a] + 36*a*b*d^2*E^(c + d*x)*x^2*Log[1 + (b*E^(c + d*x))/a] + 18*b^2*d^2*E^(2*(c + d*x))*x^2*Log[1 + (b*E^(c + d*x))/a] - 4*a^2*d^3*x^3*Log[1 + (b*E^(c + d*x))/a] - 8*a*b*d^3*E^(c + d*x)*x^3*Log[1 + (b*E^(c + d*x))/a] - 4*b^2*d^3*E^(2*(c + d*x))*x^3*Log[1 + (b*E^(c + d*x))/a] - 12*(a + b*E^(c + d*x))^2*(1 - 3*d*x + d^2*x^2)*PolyLog[2, -((b*E^(c + d*x))/a)] + 12*(a + b*E^(c + d*x))^2*(-3 + 2*d*x)*PolyLog[3, -((b*E^(c + d*x))/a)] - 24*a^2*PolyLog[4, -((b*E^(c + d*x))/a)] - 48*a*b*E^(c + d*x)*PolyLog[4, -((b*E^(c + d*x))/a)] - 24*b^2*E^(2*(c + d*x))*PolyLog[4, -((b*E^(c + d*x))/a)])} *)


(* ::Subsection::Closed:: *)
(*Miscellaneous integrands involving one exponential function*)


(* Integrands of the form (a + b*x)^m*f ((a + b*x)^n) *)
{x^m*E^(x^n), x, 1, -((x^(1 + m)*Gamma[(1 + m)/n, -x^n])/((-x^n)^((1 + m)/n)*n))}
{x^m*f^(x^n), x, 1, -((x^(1 + m)*Gamma[(1 + m)/n, (-x^n)*Log[f]])/(((-x^n)*Log[f])^((1 + m)/n)*n))}

{(a + b*x)^m*E^((a + b*x)^n), x, 1, -(((a + b*x)^(1 + m)*Gamma[(1 + m)/n, -(a + b*x)^n])/((-(a + b*x)^n)^((1 + m)/n)*(b*n)))}
{(a + b*x)^m*f^((a + b*x)^n), x, 1, -(((a + b*x)^(1 + m)*Gamma[(1 + m)/n, (-(a + b*x)^n)*Log[f]])/(((-(a + b*x)^n)*Log[f])^((1 + m)/n)*(b*n)))}


{E^(a + b*x)/(c + d*x^2), x, 3, -((E^(a - (b*Sqrt[-c])/Sqrt[d])*ExpIntegralEi[(b*(Sqrt[-c] + Sqrt[d]*x))/Sqrt[d]])/(2*Sqrt[-c]*Sqrt[d])) + (E^(a + (b*Sqrt[-c])/Sqrt[d])*ExpIntegralEi[(b*(c + Sqrt[-c]*Sqrt[d]*x))/(Sqrt[-c]*Sqrt[d])])/(2*Sqrt[-c]*Sqrt[d])}
{x*E^(a + b*x)/(c + d*x^2), x, 3, (E^(a - (b*Sqrt[-c])/Sqrt[d])*ExpIntegralEi[(b*(Sqrt[-c] + Sqrt[d]*x))/Sqrt[d]])/(2*d) + (E^(a + (b*Sqrt[-c])/Sqrt[d])*ExpIntegralEi[(b*(c + Sqrt[-c]*Sqrt[d]*x))/(Sqrt[-c]*Sqrt[d])])/(2*d)}
{x^2*E^(a + b*x)/(c + d*x^2), x, 6, E^(a + b*x)/(b*d) - (Sqrt[-c]*E^(a - (b*Sqrt[-c])/Sqrt[d])*ExpIntegralEi[(b*(Sqrt[-c] + Sqrt[d]*x))/Sqrt[d]])/(2*d^(3/2)) + (Sqrt[-c]*E^(a + (b*Sqrt[-c])/Sqrt[d])*ExpIntegralEi[(b*(c + Sqrt[-c]*Sqrt[d]*x))/(Sqrt[-c]*Sqrt[d])])/(2*d^(3/2))}


(* Integrands of the form E^(a+b*x)/(c+d*x+e*x^2) *)
{E^(a + b*x)/(c + d*x + e*x^2), x, 3, (E^(a - (b*(d - Sqrt[d^2 - 4*c*e]))/(2*e))*ExpIntegralEi[(b*(d - Sqrt[d^2 - 4*c*e] + 2*e*x))/(2*e)])/Sqrt[d^2 - 4*c*e] - (E^(a - (b*(d + Sqrt[d^2 - 4*c*e]))/(2*e))*ExpIntegralEi[(b*(d + Sqrt[d^2 - 4*c*e] + 2*e*x))/(2*e)])/Sqrt[d^2 - 4*c*e]}


(* Integrands of the form 1/(a+b*E^(c+d*x))^m where m is an integer *)
{1/(a + b*E^(c + d*x)), x, 1, x/a - Log[a + b*E^(c + d*x)]/(a*d)}
{1/(a + b*E^(c + d*x))^2, x, 2, 1/(a*d*(a + b*E^(c + d*x))) + x/a^2 - Log[a + b*E^(c + d*x)]/(a^2*d)}
{1/(a + b*E^(c + d*x))^3, x, 3, 1/(2*a*d*(a + b*E^(c + d*x))^2) + 1/(a^2*d*(a + b*E^(c + d*x))) + x/a^3 - Log[a + b*E^(c + d*x)]/(a^3*d)}

{1/(a + b*E^(c - d*x)), x, 1, Log[b + a*E^(-c + d*x)]/(a*d)}
{1/(a + b*E^(c - d*x))^2, x, 2, -(1/(a*d*(a + b*E^(c - d*x)))) + Log[b + a*E^(-c + d*x)]/(a^2*d)}
{1/(a + b*E^(c - d*x))^3, x, 3, -(1/(2*a*d*(a + b*E^(c - d*x))^2)) - 1/(a^2*d*(a + b*E^(c - d*x))) + Log[b + a*E^(-c + d*x)]/(a^3*d)}

{1/(a + b*E^(-c - d*x)), x, 1, Log[b + a*E^(c + d*x)]/(a*d)}
{1/(a + b*E^(-c - d*x))^2, x, 2, -(1/(a*d*(a + b*E^(-c - d*x)))) + Log[b + a*E^(c + d*x)]/(a^2*d)}
{1/(a + b*E^(-c - d*x))^3, x, 3, -(1/(2*a*d*(a + b*E^(-c - d*x))^2)) - 1/(a^2*d*(a + b*E^(-c - d*x))) + Log[b + a*E^(c + d*x)]/(a^3*d)}


(* Integrands of the form (a+b*E^(c+d*x))^n *)
(* Note: Apart should NOT be used to expand integrands of this form! *)
{(a + b*E^x)^2, x, 4, 2*a*b*E^x + (1/2)*b^2*E^(2*x) + a^2*x}
{(a + b*E^x)^3, x, 5, 3*a^2*b*E^x + (3/2)*a*b^2*E^(2*x) + (1/3)*b^3*E^(3*x) + a^3*x}
{(a + b*E^x)^4, x, 6, 4*a^3*b*E^x + 3*a^2*b^2*E^(2*x) + (4/3)*a*b^3*E^(3*x) + (1/4)*b^4*E^(4*x) + a^4*x}

{1/Sqrt[a + b*E^(c + d*x)], x, 1, -((2*ArcTanh[Sqrt[a + b*E^(c + d*x)]/Sqrt[a]])/(Sqrt[a]*d))}
{1/Sqrt[-a + b*E^(c + d*x)], x, 1, (2*ArcTan[Sqrt[-a + b*E^(c + d*x)]/Sqrt[a]])/(Sqrt[a]*d)}

{Sqrt[a + b*E^(c + d*x)], x, 2, (2*Sqrt[a + b*E^(c + d*x)])/d - (2*Sqrt[a]*ArcTanh[Sqrt[a + b*E^(c + d*x)]/Sqrt[a]])/d}
{Sqrt[-a + b*E^(c + d*x)], x, 2, (2*Sqrt[-a + b*E^(c + d*x)])/d - (2*Sqrt[a]*ArcTan[Sqrt[-a + b*E^(c + d*x)]/Sqrt[a]])/d}


(* Integrands of the form x^m*f^(a+b*x) where m is a half integer *)
{x^(3/2)*f^(a + b*x), x, 4, (3*f^a*Sqrt[Pi]*Erfi[Sqrt[b]*Sqrt[x]*Sqrt[Log[f]]])/(4*b^(5/2)*Log[f]^(5/2)) - (3*f^(a + b*x)*Sqrt[x])/(2*b^2*Log[f]^2) + (f^(a + b*x)*x^(3/2))/(b*Log[f])}
{x^(1/2)*f^(a + b*x), x, 3, -((f^a*Sqrt[Pi]*Erfi[Sqrt[b]*Sqrt[x]*Sqrt[Log[f]]])/(2*b^(3/2)*Log[f]^(3/2))) + (f^(a + b*x)*Sqrt[x])/(b*Log[f])}
{f^(a + b*x)/x^(1/2), x, 2, (f^a*Sqrt[Pi]*Erfi[Sqrt[b]*Sqrt[x]*Sqrt[Log[f]]])/(Sqrt[b]*Sqrt[Log[f]])}
{f^(a + b*x)/x^(3/2), x, 3, -((2*f^(a + b*x))/Sqrt[x]) + 2*Sqrt[b]*f^a*Sqrt[Pi]*Erfi[Sqrt[b]*Sqrt[x]*Sqrt[Log[f]]]*Sqrt[Log[f]]}


(* ::Section::Closed:: *)
(*Integrands involving two exponential functions*)


(* ::Subsection::Closed:: *)
(*Integrands of the form f^x / (a+b g^x)*)


{4^x/(a + b*2^x), x, 4, 2^x/(b*Log[2]) - (a*Log[a + 2^x*b])/(b^2*Log[2])}
{2^(2*x)/(a + b*2^x), x, 5, 2^x/(b*Log[2]) - (a*Log[a + 2^x*b])/(b^2*Log[2])}

{4^x/(a - b*2^x), x, 4, -(2^x/(b*Log[2])) - (a*Log[a - 2^x*b])/(b^2*Log[2])}
{2^(2*x)/(a - b*2^x), x, 5, -(2^x/(b*Log[2])) - (a*Log[a - 2^x*b])/(b^2*Log[2])}


{4^x/(a + b/2^x), x, 4, 2^(-1 + 2*x)/(a*Log[2]) - (2^x*b)/(a^2*Log[2]) + (b^2*Log[2^x*a + b])/(a^3*Log[2])}
{2^(2*x)/(a + b/2^x), x, 3, 2^(-1 + 2*x)/(a*Log[2]) - (2^x*b)/(a^2*Log[2]) + (b^2*Log[2^x*a + b])/(a^3*Log[2])}

{4^x/(a - b/2^x), x, 4, 2^(-1 + 2*x)/(a*Log[2]) + (2^x*b)/(a^2*Log[2]) + (b^2*Log[2^x*a - b])/(a^3*Log[2])}
{2^(2*x)/(a - b/2^x), x, 3, 2^(-1 + 2*x)/(a*Log[2]) + (2^x*b)/(a^2*Log[2]) + (b^2*Log[2^x*a - b])/(a^3*Log[2])}


{2^x/(a + b*4^x), x, 3, ArcTan[(2^x*Sqrt[b])/Sqrt[a]]/(Sqrt[a]*Sqrt[b]*Log[2])}
{2^x/(a + b*2^(2*x)), x, 2, ArcTan[(2^x*Sqrt[b])/Sqrt[a]]/(Sqrt[a]*Sqrt[b]*Log[2])}

{2^x/(a - b*4^x), x, 3, ArcTanh[(2^x*Sqrt[b])/Sqrt[a]]/(Sqrt[a]*Sqrt[b]*Log[2])}
{2^x/(a - b*2^(2*x)), x, 2, ArcTanh[(2^x*Sqrt[b])/Sqrt[a]]/(Sqrt[a]*Sqrt[b]*Log[2])}


{2^x/(a + b/4^x), x, 5, 2^x/(a*Log[2]) - (Sqrt[b]*ArcTan[(2^x*Sqrt[a])/Sqrt[b]])/(a^(3/2)*Log[2])}
{2^x/(a + b/2^(2*x)), x, 4, 2^x/(a*Log[2]) - (Sqrt[b]*ArcTan[(2^x*Sqrt[a])/Sqrt[b]])/(a^(3/2)*Log[2])}

{2^x/(a - b/4^x), x, 5, 2^x/(a*Log[2]) - (Sqrt[b]*ArcTanh[(2^x*Sqrt[a])/Sqrt[b]])/(a^(3/2)*Log[2])}
{2^x/(a - b/2^(2*x)), x, 4, 2^x/(a*Log[2]) - (Sqrt[b]*ArcTanh[(2^x*Sqrt[a])/Sqrt[b]])/(a^(3/2)*Log[2])}


(* ::Subsection::Closed:: *)
(*Integrands of the form f^x / Sqrt[a+b g^x]*)


(* Contributed by Robert Israel in sci.math.symbolic *)
{2^x/Sqrt[a + b*4^x], x, 3, ArcTanh[(2^x*Sqrt[b])/Sqrt[a + 2^(2*x)*b]]/(Sqrt[b]*Log[2])}
{2^x/Sqrt[a + b*2^(2*x)], x, 2, ArcTanh[(2^x*Sqrt[b])/Sqrt[a + 2^(2*x)*b]]/(Sqrt[b]*Log[2])}

{2^x/Sqrt[a - b*4^x], x, 3, ArcTan[(2^x*Sqrt[b])/Sqrt[a - 2^(2*x)*b]]/(Sqrt[b]*Log[2])}
{2^x/Sqrt[a - b*2^(2*x)], x, 2, ArcTan[(2^x*Sqrt[b])/Sqrt[a - 2^(2*x)*b]]/(Sqrt[b]*Log[2])}


{2^x/Sqrt[a + b/4^x], x, 3, (2^x*Sqrt[a + b/2^(2*x)])/(a*Log[2])}
{2^x/Sqrt[a + b/2^(2*x)], x, 2, (2^x*Sqrt[a + b/2^(2*x)])/(a*Log[2])}

{2^x/Sqrt[a - b/4^x], x, 3, (2^x*Sqrt[a - b/2^(2*x)])/(a*Log[2])}
{2^x/Sqrt[a - b/2^(2*x)], x, 2, (2^x*Sqrt[a - b/2^(2*x)])/(a*Log[2])}


{4^x/Sqrt[a + b*2^x], x, 4, -((2*a*Sqrt[a + 2^x*b])/(b^2*Log[2])) + (2*(a + 2^x*b)^(3/2))/(3*b^2*Log[2])}
{2^(2*x)/Sqrt[a + b*2^x], x, 5, -((2*a*Sqrt[a + 2^x*b])/(b^2*Log[2])) + (2*(a + 2^x*b)^(3/2))/(3*b^2*Log[2])}

{4^x/Sqrt[a - b*2^x], x, 4, -((2*a*Sqrt[a - 2^x*b])/(b^2*Log[2])) + (2*(a - 2^x*b)^(3/2))/(3*b^2*Log[2])}
{2^(2*x)/Sqrt[a - b*2^x], x, 5, -((2*a*Sqrt[a - 2^x*b])/(b^2*Log[2])) + (2*(a - 2^x*b)^(3/2))/(3*b^2*Log[2])}


{4^x/Sqrt[a + b/2^x], x, 6, (2^(-1 + 2*x)*Sqrt[a + b/2^x])/(a*Log[2]) - (3*2^(-2 + x)*b*Sqrt[a + b/2^x])/(a^2*Log[2]) + (3*b^2*ArcTanh[Sqrt[a + b/2^x]/Sqrt[a]])/(4*a^(5/2)*Log[2])}
{2^(2*x)/Sqrt[a + b/2^x], x, 7, (2^(-1 + 2*x)*Sqrt[a + b/2^x])/(a*Log[2]) - (3*2^(-2 + x)*b*Sqrt[a + b/2^x])/(a^2*Log[2]) + (3*b^2*ArcTanh[Sqrt[a + b/2^x]/Sqrt[a]])/(4*a^(5/2)*Log[2])}

{4^x/Sqrt[a - b/2^x], x, 6, (2^(-1 + 2*x)*Sqrt[a - b/2^x])/(a*Log[2]) + (3*2^(-2 + x)*b*Sqrt[a - b/2^x])/(a^2*Log[2]) + (3*b^2*ArcTanh[Sqrt[a - b/2^x]/Sqrt[a]])/(4*a^(5/2)*Log[2])}
{2^(2*x)/Sqrt[a - b/2^x], x, 7, (2^(-1 + 2*x)*Sqrt[a - b/2^x])/(a*Log[2]) + (3*2^(-2 + x)*b*Sqrt[a - b/2^x])/(a^2*Log[2]) + (3*b^2*ArcTanh[Sqrt[a - b/2^x]/Sqrt[a]])/(4*a^(5/2)*Log[2])}


(* ::Subsection::Closed:: *)
(*Integrands of the form x^m f^(c+d x) (a+b f^(c+d x))^n*)


{x^3*f^(c + d*x)/(a + b*f^(c + d*x)), x, 4, (x^3*Log[1 + (b*f^(c + d*x))/a])/(b*d*Log[f]) + (3*x^2*PolyLog[2, -((b*f^(c + d*x))/a)])/(b*d^2*Log[f]^2) - (6*x*PolyLog[3, -((b*f^(c + d*x))/a)])/(b*d^3*Log[f]^3) + (6*PolyLog[4, -((b*f^(c + d*x))/a)])/(b*d^4*Log[f]^4)}
{x^2*f^(c + d*x)/(a + b*f^(c + d*x)), x, 3, (x^2*Log[1 + (b*f^(c + d*x))/a])/(b*d*Log[f]) + (2*x*PolyLog[2, -((b*f^(c + d*x))/a)])/(b*d^2*Log[f]^2) - (2*PolyLog[3, -((b*f^(c + d*x))/a)])/(b*d^3*Log[f]^3)}
{x^1*f^(c + d*x)/(a + b*f^(c + d*x)), x, 2, (x*Log[1 + (b*f^(c + d*x))/a])/(b*d*Log[f]) + PolyLog[2, -((b*f^(c + d*x))/a)]/(b*d^2*Log[f]^2)}
{x^0*f^(c + d*x)/(a + b*f^(c + d*x)), x, 1, Log[a + b*f^(c + d*x)]/(b*d*Log[f])}
{1/x^1*f^(c + d*x)/(a + b*f^(c + d*x)), x, 0, Int[f^(c + d*x)/((a + b*f^(c + d*x))*x), x]}
{1/x^2*f^(c + d*x)/(a + b*f^(c + d*x)), x, 0, Int[f^(c + d*x)/((a + b*f^(c + d*x))*x^2), x]}


{x^3*f^(c + d*x)/(a + b*f^(c + d*x))^2, x, 5, x^3/(a*b*d*Log[f]) - x^3/(b*d*(a + b*f^(c + d*x))*Log[f]) - (3*x^2*Log[1 + (b*f^(c + d*x))/a])/(a*b*d^2*Log[f]^2) - (6*x*PolyLog[2, -((b*f^(c + d*x))/a)])/(a*b*d^3*Log[f]^3) + (6*PolyLog[3, -((b*f^(c + d*x))/a)])/(a*b*d^4*Log[f]^4)}
{x^2*f^(c + d*x)/(a + b*f^(c + d*x))^2, x, 4, x^2/(a*b*d*Log[f]) - x^2/(b*d*(a + b*f^(c + d*x))*Log[f]) - (2*x*Log[1 + (b*f^(c + d*x))/a])/(a*b*d^2*Log[f]^2) - (2*PolyLog[2, -((b*f^(c + d*x))/a)])/(a*b*d^3*Log[f]^3)}
{x^1*f^(c + d*x)/(a + b*f^(c + d*x))^2, x, 2, x/(a*b*d*Log[f]) - x/(b*d*(a + b*f^(c + d*x))*Log[f]) - Log[a + b*f^(c + d*x)]/(a*b*d^2*Log[f]^2)}
{x^0*f^(c + d*x)/(a + b*f^(c + d*x))^2, x, 1, -(1/(b*d*(a + b*f^(c + d*x))*Log[f]))}
{1/x^1*f^(c + d*x)/(a + b*f^(c + d*x))^2, x, 1, -(1/(b*d*(a + b*f^(c + d*x))*x*Log[f])) - Int[1/((a + b*f^(c + d*x))*x^2), x]/(b*d*Log[f])}
{1/x^2*f^(c + d*x)/(a + b*f^(c + d*x))^2, x, 1, -(1/(b*d*(a + b*f^(c + d*x))*x^2*Log[f])) - (2*Int[1/((a + b*f^(c + d*x))*x^3), x])/(b*d*Log[f])}


{x^3*f^(c + d*x)/(a + b*f^(c + d*x))^3, x, 12, -((3*x^2)/(2*a^2*b*d^2*Log[f]^2)) + (3*x^2)/(2*a*b*d^2*(a + b*f^(c + d*x))*Log[f]^2) + x^3/(2*a^2*b*d*Log[f]) - x^3/(2*b*d*(a + b*f^(c + d*x))^2*Log[f]) + (3*x*Log[1 + (b*f^(c + d*x))/a])/(a^2*b*d^3*Log[f]^3) - (3*x^2*Log[1 + (b*f^(c + d*x))/a])/(2*a^2*b*d^2*Log[f]^2) + (3*PolyLog[2, -((b*f^(c + d*x))/a)])/(a^2*b*d^4*Log[f]^4) - (3*x*PolyLog[2, -((b*f^(c + d*x))/a)])/(a^2*b*d^3*Log[f]^3) + (3*PolyLog[3, -((b*f^(c + d*x))/a)])/(a^2*b*d^4*Log[f]^4)}
{x^2*f^(c + d*x)/(a + b*f^(c + d*x))^3, x, 6, -(x/(a^2*b*d^2*Log[f]^2)) + x/(a*b*d^2*(a + b*f^(c + d*x))*Log[f]^2) + x^2/(2*a^2*b*d*Log[f]) - x^2/(2*b*d*(a + b*f^(c + d*x))^2*Log[f]) + Log[a + b*f^(c + d*x)]/(a^2*b*d^3*Log[f]^3) - (x*Log[1 + (b*f^(c + d*x))/a])/(a^2*b*d^2*Log[f]^2) - PolyLog[2, -((b*f^(c + d*x))/a)]/(a^2*b*d^3*Log[f]^3)}
{x^1*f^(c + d*x)/(a + b*f^(c + d*x))^3, x, 3, 1/(2*a*b*d^2*(a + b*f^(c + d*x))*Log[f]^2) + x/(2*a^2*b*d*Log[f]) - x/(2*b*d*(a + b*f^(c + d*x))^2*Log[f]) - Log[a + b*f^(c + d*x)]/(2*a^2*b*d^2*Log[f]^2)}
{x^0*f^(c + d*x)/(a + b*f^(c + d*x))^3, x, 1, -(1/(2*b*d*(a + b*f^(c + d*x))^2*Log[f]))}
{1/x^1*f^(c + d*x)/(a + b*f^(c + d*x))^3, x, 1, -(1/(2*b*d*(a + b*f^(c + d*x))^2*x*Log[f])) - Int[1/((a + b*f^(c + d*x))^2*x^2), x]/(2*b*d*Log[f])}
{1/x^2*f^(c + d*x)/(a + b*f^(c + d*x))^3, x, 1, -(1/(2*b*d*(a + b*f^(c + d*x))^2*x^2*Log[f])) - Int[1/((a + b*f^(c + d*x))^2*x^3), x]/(b*d*Log[f])}


(* Integrands of the form f^(c+d*x)*(a+b*f^(c+d*x))^n *)
{E^x/(4 + 6*E^x), x, 1, (1/6)*Log[4 + 6*E^x]}
{E^x/(a + b*E^x), x, 1, Log[a + b*E^x]/b}
{E^(d*x)/(a + b*E^(c + d*x)), x, 1, Log[a + b*E^(c + d*x)]/(E^c*(b*d))}
{E^(c + d*x)/(a + b*E^(c + d*x)), x, 1, Log[a + b*E^(c + d*x)]/(b*d)}

{E^x*(a + b*E^x)^n, x, 1, (a + b*E^x)^(1 + n)/(b*(1 + n))}
{E^(d*x)*(a + b*E^(c + d*x))^n, x, 1, (a + b*E^(c + d*x))^(1 + n)/(E^c*(b*d*(1 + n)))}
{E^(c + d*x)*(a + b*E^(c + d*x))^n, x, 1, (a + b*E^(c + d*x))^(1 + n)/(b*d*(1 + n))}

{f^x/(a + b*f^x), x, 1, Log[a + b*f^x]/(b*Log[f])}
{f^(d*x)/(a + b*f^(c + d*x)), x, 1, Log[a + b*f^(c + d*x)]/(f^c*(b*d*Log[f]))}
{f^(c + d*x)/(a + b*f^(c + d*x)), x, 1, Log[a + b*f^(c + d*x)]/(b*d*Log[f])}

{f^x*(a + b*f^x)^n, x, 1, (a + b*f^x)^(1 + n)/(b*(1 + n)*Log[f])}
{f^(d*x)*(a + b*f^(c + d*x))^n, x, 1, (a + b*f^(c + d*x))^(1 + n)/(f^c*(b*d*(1 + n)*Log[f]))}
{f^(c + d*x)*(a + b*f^(c + d*x))^n, x, 1, (a + b*f^(c + d*x))^(1 + n)/(b*d*(1 + n)*Log[f])}


(* ::Subsection::Closed:: *)
(*Integrands of the form x^m (a+b f^(d+e x)+c f^(2 (d+e x)))^n*)


(* Integrands of the form x^m/(a+b*E^x+c*E^(2*x)) where m is an integer *)
{1/(1 + 2*E^x + E^(2*x)), x, 3, 1/(1 + E^x) + x - Log[1 + E^x]}
{1/(2 + 3*E^x + E^(2*x)), x, 4, x/2 - Log[1 + E^x] + (1/2)*Log[2 + E^x]}
{1/(-1 + E^x + E^(2*x)), x, 5, -x + (1/10)*(5 + Sqrt[5])*Log[1 - Sqrt[5] + 2*E^x] - ((1 - Sqrt[5])*Log[1 + Sqrt[5] + 2*E^x])/(2*Sqrt[5])}
{1/(3 + 3*E^x + E^(2*x)), x, 5, x/3 - ArcTan[(3 + 2*E^x)/Sqrt[3]]/Sqrt[3] - (1/6)*Log[3 + 3*E^x + E^(2*x)]}
{1/(a + b*E^x + c*E^(2*x)), x, 5, x/a + (b*ArcTanh[(b + 2*c*E^x)/Sqrt[b^2 - 4*a*c]])/(a*Sqrt[b^2 - 4*a*c]) - Log[a + b*E^x + c*E^(2*x)]/(2*a)}

{x/(1 + 2*E^x + E^(2*x)), x, 5, -x + x/(1 + E^x) + x^2/2 + Log[1 + E^x] - x*Log[1 + E^x] - PolyLog[2, -E^x]}
{x/(2 + 3*E^x + E^(2*x)), x, 7, x^2/4 + (1/2)*x*Log[1 + E^x/2] - x*Log[1 + E^x] - PolyLog[2, -E^x] + (1/2)*PolyLog[2, -(E^x/2)]}
{x/(-1 + E^x + E^(2*x)), x, 7, x^2/(Sqrt[5]*(1 - Sqrt[5])) - x^2/(Sqrt[5]*(1 + Sqrt[5])) - (2*x*Log[1 + (2*E^x)/(1 - Sqrt[5])])/(Sqrt[5]*(1 - Sqrt[5])) + (2*x*Log[1 + (2*E^x)/(1 + Sqrt[5])])/(Sqrt[5]*(1 + Sqrt[5])) - (2*PolyLog[2, -((2*E^x)/(1 - Sqrt[5]))])/(Sqrt[5]*(1 - Sqrt[5])) + (2*PolyLog[2, -((2*E^x)/(1 + Sqrt[5]))])/(Sqrt[5]*(1 + Sqrt[5]))}
{x/(3 + 3*E^x + E^(2*x)), x, 7, -(x^2/(Sqrt[3]*(3*I - Sqrt[3]))) + x^2/(Sqrt[3]*(3*I + Sqrt[3])) + (2*x*Log[1 + (2*E^x)/(3 + I*Sqrt[3])])/(Sqrt[3]*(3*I - Sqrt[3])) - (2*x*Log[1 + (2*I*E^x)/(3*I + Sqrt[3])])/(Sqrt[3]*(3*I + Sqrt[3])) + (2*PolyLog[2, -((2*E^x)/(3 + I*Sqrt[3]))])/(Sqrt[3]*(3*I - Sqrt[3])) - (2*PolyLog[2, -((2*I*E^x)/(3*I + Sqrt[3]))])/(Sqrt[3]*(3*I + Sqrt[3]))}
{x/(a + b*E^x + c*E^(2*x)), x, 7, -((c*x^2)/(b^2 - 4*a*c - b*Sqrt[b^2 - 4*a*c])) - (c*x^2)/(b^2 - 4*a*c + b*Sqrt[b^2 - 4*a*c]) + (2*c*x*Log[1 + (2*c*E^x)/(b - Sqrt[b^2 - 4*a*c])])/(b^2 - 4*a*c - b*Sqrt[b^2 - 4*a*c]) + (2*c*x*Log[1 + (2*c*E^x)/(b + Sqrt[b^2 - 4*a*c])])/(b^2 - 4*a*c + b*Sqrt[b^2 - 4*a*c]) + (2*c*PolyLog[2, -((2*c*E^x)/(b - Sqrt[b^2 - 4*a*c]))])/(b^2 - 4*a*c - b*Sqrt[b^2 - 4*a*c]) + (2*c*PolyLog[2, -((2*c*E^x)/(b + Sqrt[b^2 - 4*a*c]))])/(b^2 - 4*a*c + b*Sqrt[b^2 - 4*a*c])}

{x^2/(1 + 2*E^x + E^(2*x)), x, 11, -x^2 + x^2/(1 + E^x) + x^3/3 + 2*x*Log[1 + E^x] - x^2*Log[1 + E^x] + 2*PolyLog[2, -E^x] - 2*x*PolyLog[2, -E^x] + 2*PolyLog[3, -E^x]}
{x^2/(2 + 3*E^x + E^(2*x)), x, 9, x^3/6 + (1/2)*x^2*Log[1 + E^x/2] - x^2*Log[1 + E^x] - 2*x*PolyLog[2, -E^x] + x*PolyLog[2, -(E^x/2)] + 2*PolyLog[3, -E^x] - PolyLog[3, -(E^x/2)]}
{x^2/(-1 + E^x + E^(2*x)), x, 9, (2*x^3)/(3*Sqrt[5]*(1 - Sqrt[5])) - (2*x^3)/(3*Sqrt[5]*(1 + Sqrt[5])) - (2*x^2*Log[1 + (2*E^x)/(1 - Sqrt[5])])/(Sqrt[5]*(1 - Sqrt[5])) + (2*x^2*Log[1 + (2*E^x)/(1 + Sqrt[5])])/(Sqrt[5]*(1 + Sqrt[5])) - (4*x*PolyLog[2, -((2*E^x)/(1 - Sqrt[5]))])/(Sqrt[5]*(1 - Sqrt[5])) + (4*x*PolyLog[2, -((2*E^x)/(1 + Sqrt[5]))])/(Sqrt[5]*(1 + Sqrt[5])) + (4*PolyLog[3, -((2*E^x)/(1 - Sqrt[5]))])/(Sqrt[5]*(1 - Sqrt[5])) - (4*PolyLog[3, -((2*E^x)/(1 + Sqrt[5]))])/(Sqrt[5]*(1 + Sqrt[5]))}
{x^2/(3 + 3*E^x + E^(2*x)), x, 9, -((2*x^3)/(3*Sqrt[3]*(3*I - Sqrt[3]))) + (2*x^3)/(3*Sqrt[3]*(3*I + Sqrt[3])) + (2*x^2*Log[1 + (2*E^x)/(3 + I*Sqrt[3])])/(Sqrt[3]*(3*I - Sqrt[3])) - (2*x^2*Log[1 + (2*I*E^x)/(3*I + Sqrt[3])])/(Sqrt[3]*(3*I + Sqrt[3])) + (4*x*PolyLog[2, -((2*E^x)/(3 + I*Sqrt[3]))])/(Sqrt[3]*(3*I - Sqrt[3])) - (4*x*PolyLog[2, -((2*I*E^x)/(3*I + Sqrt[3]))])/(Sqrt[3]*(3*I + Sqrt[3])) - (4*PolyLog[3, -((2*E^x)/(3 + I*Sqrt[3]))])/(Sqrt[3]*(3*I - Sqrt[3])) + (4*PolyLog[3, -((2*I*E^x)/(3*I + Sqrt[3]))])/(Sqrt[3]*(3*I + Sqrt[3]))}
{x^2/(a + b*E^x + c*E^(2*x)), x, 9, -((2*c*x^3)/(3*(b^2 - 4*a*c - b*Sqrt[b^2 - 4*a*c]))) - (2*c*x^3)/(3*(b^2 - 4*a*c + b*Sqrt[b^2 - 4*a*c])) + (2*c*x^2*Log[1 + (2*c*E^x)/(b - Sqrt[b^2 - 4*a*c])])/(b^2 - 4*a*c - b*Sqrt[b^2 - 4*a*c]) + (2*c*x^2*Log[1 + (2*c*E^x)/(b + Sqrt[b^2 - 4*a*c])])/(b^2 - 4*a*c + b*Sqrt[b^2 - 4*a*c]) + (4*c*x*PolyLog[2, -((2*c*E^x)/(b - Sqrt[b^2 - 4*a*c]))])/(b^2 - 4*a*c - b*Sqrt[b^2 - 4*a*c]) + (4*c*x*PolyLog[2, -((2*c*E^x)/(b + Sqrt[b^2 - 4*a*c]))])/(b^2 - 4*a*c + b*Sqrt[b^2 - 4*a*c]) - (4*c*PolyLog[3, -((2*c*E^x)/(b - Sqrt[b^2 - 4*a*c]))])/(b^2 - 4*a*c - b*Sqrt[b^2 - 4*a*c]) - (4*c*PolyLog[3, -((2*c*E^x)/(b + Sqrt[b^2 - 4*a*c]))])/(b^2 - 4*a*c + b*Sqrt[b^2 - 4*a*c])}


(* Integrands of the form x^m/(a+b*f^(c+d*x)+c*f^(2*c+2*d*x)) where m is an integer *)
{1/(1 + 2*f^(c + d*x) + f^(2*c + 2*d*x)), x, 3, x + 1/(d*(1 + f^(c + d*x))*Log[f]) - Log[1 + f^(c + d*x)]/(d*Log[f])}
{1/(a + b*f^(c + d*x) + c*f^(2*c + 2*d*x)), x, 5, x/a + (b*ArcTanh[(b + 2*c*f^(c + d*x))/Sqrt[b^2 - 4*a*c]])/(a*Sqrt[b^2 - 4*a*c]*d*Log[f]) - Log[a + b*f^(c + d*x) + c*f^(2*c + 2*d*x)]/(2*a*d*Log[f])}
{1/(a + b*f^(g + h*x) + c*f^(2*(g + h*x))), x, 5, x/a + (b*ArcTanh[(b + 2*c*f^(g + h*x))/Sqrt[b^2 - 4*a*c]])/(a*Sqrt[b^2 - 4*a*c]*h*Log[f]) - Log[a + b*f^(g + h*x) + c*f^(2*g + 2*h*x)]/(2*a*h*Log[f])}

{x/(1 + 2*f^(c + d*x) + f^(2*c + 2*d*x)), x, 5, x^2/2 - x/(d*Log[f]) + x/(d*(1 + f^(c + d*x))*Log[f]) + Log[1 + f^(c + d*x)]/(d^2*Log[f]^2) - (x*Log[1 + f^(c + d*x)])/(d*Log[f]) - PolyLog[2, -f^(c + d*x)]/(d^2*Log[f]^2)}
{x/(a + b*f^(c + d*x) + c*f^(2*c + 2*d*x)), x, 7, -((c*x^2)/(b^2 - 4*a*c - b*Sqrt[b^2 - 4*a*c])) - (c*x^2)/(b^2 - 4*a*c + b*Sqrt[b^2 - 4*a*c]) - (2*c*x*Log[1 + (2*c*f^(c + d*x))/(b - Sqrt[b^2 - 4*a*c])])/(Sqrt[b^2 - 4*a*c]*(b - Sqrt[b^2 - 4*a*c])*d*Log[f]) + (2*c*x*Log[1 + (2*c*f^(c + d*x))/(b + Sqrt[b^2 - 4*a*c])])/(Sqrt[b^2 - 4*a*c]*(b + Sqrt[b^2 - 4*a*c])*d*Log[f]) - (2*c*PolyLog[2, -((2*c*f^(c + d*x))/(b - Sqrt[b^2 - 4*a*c]))])/(Sqrt[b^2 - 4*a*c]*(b - Sqrt[b^2 - 4*a*c])*d^2*Log[f]^2) + (2*c*PolyLog[2, -((2*c*f^(c + d*x))/(b + Sqrt[b^2 - 4*a*c]))])/(Sqrt[b^2 - 4*a*c]*(b + Sqrt[b^2 - 4*a*c])*d^2*Log[f]^2)}

{x^2/(1 + 2*f^(c + d*x) + f^(2*c + 2*d*x)), x, 11, x^3/3 - x^2/(d*Log[f]) + x^2/(d*(1 + f^(c + d*x))*Log[f]) + (2*x*Log[1 + f^(c + d*x)])/(d^2*Log[f]^2) - (x^2*Log[1 + f^(c + d*x)])/(d*Log[f]) + (2*PolyLog[2, -f^(c + d*x)])/(d^3*Log[f]^3) - (2*x*PolyLog[2, -f^(c + d*x)])/(d^2*Log[f]^2) + (2*PolyLog[3, -f^(c + d*x)])/(d^3*Log[f]^3)}
{x^2/(a + b*f^(c + d*x) + c*f^(2*c + 2*d*x)), x, 9, -((2*c*x^3)/(3*(b^2 - 4*a*c - b*Sqrt[b^2 - 4*a*c]))) - (2*c*x^3)/(3*(b^2 - 4*a*c + b*Sqrt[b^2 - 4*a*c])) - (2*c*x^2*Log[1 + (2*c*f^(c + d*x))/(b - Sqrt[b^2 - 4*a*c])])/(Sqrt[b^2 - 4*a*c]*(b - Sqrt[b^2 - 4*a*c])*d*Log[f]) + (2*c*x^2*Log[1 + (2*c*f^(c + d*x))/(b + Sqrt[b^2 - 4*a*c])])/(Sqrt[b^2 - 4*a*c]*(b + Sqrt[b^2 - 4*a*c])*d*Log[f]) - (4*c*x*PolyLog[2, -((2*c*f^(c + d*x))/(b - Sqrt[b^2 - 4*a*c]))])/(Sqrt[b^2 - 4*a*c]*(b - Sqrt[b^2 - 4*a*c])*d^2*Log[f]^2) + (4*c*x*PolyLog[2, -((2*c*f^(c + d*x))/(b + Sqrt[b^2 - 4*a*c]))])/(Sqrt[b^2 - 4*a*c]*(b + Sqrt[b^2 - 4*a*c])*d^2*Log[f]^2) + (4*c*PolyLog[3, -((2*c*f^(c + d*x))/(b - Sqrt[b^2 - 4*a*c]))])/(Sqrt[b^2 - 4*a*c]*(b - Sqrt[b^2 - 4*a*c])*d^3*Log[f]^3) - (4*c*PolyLog[3, -((2*c*f^(c + d*x))/(b + Sqrt[b^2 - 4*a*c]))])/(Sqrt[b^2 - 4*a*c]*(b + Sqrt[b^2 - 4*a*c])*d^3*Log[f]^3)}


{(d + e*f^(g + h*x))/(a + b*f^(g + h*x) + c*f^(2*g + 2*h*x)), x, 5, (d*x)/a + ((b*d - 2*a*e)*ArcTanh[(b + 2*c*f^(g + h*x))/Sqrt[b^2 - 4*a*c]])/(a*Sqrt[b^2 - 4*a*c]*h*Log[f]) - (d*Log[a + b*f^(g + h*x) + c*f^(2*g + 2*h*x)])/(2*a*h*Log[f])}
{(d + e*f^(g + h*x))/(a + b*f^(g + h*x) + c*f^(2*(g + h*x))), x, 5, (d*x)/a + ((b*d - 2*a*e)*ArcTanh[(b + 2*c*f^(g + h*x))/Sqrt[b^2 - 4*a*c]])/(a*Sqrt[b^2 - 4*a*c]*h*Log[f]) - (d*Log[a + b*f^(g + h*x) + c*f^(2*g + 2*h*x)])/(2*a*h*Log[f])}


(* Integrands of the form x^m/(a+b*f^(c+d*x)+c*f^(2*c+2*d*x)) where b^2-4*a*c == 0 *)
{1/(2 + E^(-x) + E^x), x, 2, -(1/(1 + E^x))}
{x/(2 + E^(-x) + E^x), x, 4, x - x/(1 + E^x) - Log[1 + E^x]}
{x^2/(2 + E^(-x) + E^x), x, 6, x^2 - x^2/(1 + E^x) - 2*x*Log[1 + E^x] - 2*PolyLog[2, -E^x]}

{1/(2 + f^(-c - d*x) + f^(c + d*x)), x, 2, -(1/(d*(1 + f^(c + d*x))*Log[f]))}
{x/(2 + f^(-c - d*x) + f^(c + d*x)), x, 4, x/(d*Log[f]) - x/(d*(1 + f^(c + d*x))*Log[f]) - Log[1 + f^(c + d*x)]/(d^2*Log[f]^2)}
{x^2/(2 + f^(-c - d*x) + f^(c + d*x)), x, 6, x^2/(d*Log[f]) - x^2/(d*(1 + f^(c + d*x))*Log[f]) - (2*x*Log[1 + f^(c + d*x)])/(d^2*Log[f]^2) - (2*PolyLog[2, -f^(c + d*x)])/(d^3*Log[f]^3)}


(* Integrands of the form x^m/(a+b*f^(c+d*x)+c*f^(2*c+2*d*x)) where b^2-4*a*c != 0 *)
{1/(2 + 3^(-x) + 3^x), x, 2, -(1/((1 + 3^x)*Log[3]))}
{1/(1 - E^(-x) + 2*E^x), x, 4, (1/3)*Log[1 - 2*E^x] - (1/3)*Log[1 + E^x]}

{1/(a + b*E^(-x) + c*E^x), x, 2, -((2*ArcTanh[(a + 2*c*E^x)/Sqrt[a^2 - 4*b*c]])/Sqrt[a^2 - 4*b*c])}
{x/(a + b*E^(-x) + c*E^x), x, 8, (x*Log[1 + (2*c*E^x)/(a - Sqrt[a^2 - 4*b*c])])/Sqrt[a^2 - 4*b*c] - (x*Log[1 + (2*c*E^x)/(a + Sqrt[a^2 - 4*b*c])])/Sqrt[a^2 - 4*b*c] + PolyLog[2, -((2*c*E^x)/(a - Sqrt[a^2 - 4*b*c]))]/Sqrt[a^2 - 4*b*c] - PolyLog[2, -((2*c*E^x)/(a + Sqrt[a^2 - 4*b*c]))]/Sqrt[a^2 - 4*b*c]}
{x^2/(a + b*E^(-x) + c*E^x), x, 10, (x^2*Log[1 + (2*c*E^x)/(a - Sqrt[a^2 - 4*b*c])])/Sqrt[a^2 - 4*b*c] - (x^2*Log[1 + (2*c*E^x)/(a + Sqrt[a^2 - 4*b*c])])/Sqrt[a^2 - 4*b*c] + (2*x*PolyLog[2, -((2*c*E^x)/(a - Sqrt[a^2 - 4*b*c]))])/Sqrt[a^2 - 4*b*c] - (2*x*PolyLog[2, -((2*c*E^x)/(a + Sqrt[a^2 - 4*b*c]))])/Sqrt[a^2 - 4*b*c] - (2*PolyLog[3, -((2*c*E^x)/(a - Sqrt[a^2 - 4*b*c]))])/Sqrt[a^2 - 4*b*c] + (2*PolyLog[3, -((2*c*E^x)/(a + Sqrt[a^2 - 4*b*c]))])/Sqrt[a^2 - 4*b*c]}

{1/(a + b*f^(-c - d*x) + c*f^(c + d*x)), x, 2, -((2*ArcTanh[(a + 2*c*f^(c + d*x))/Sqrt[a^2 - 4*b*c]])/(Sqrt[a^2 - 4*b*c]*d*Log[f]))}
{x/(a + b*f^(-c - d*x) + c*f^(c + d*x)), x, 8, (x*Log[1 + (2*c*f^(c + d*x))/(a - Sqrt[a^2 - 4*b*c])])/(Sqrt[a^2 - 4*b*c]*d*Log[f]) - (x*Log[1 + (2*c*f^(c + d*x))/(a + Sqrt[a^2 - 4*b*c])])/(Sqrt[a^2 - 4*b*c]*d*Log[f]) + PolyLog[2, -((2*c*f^(c + d*x))/(a - Sqrt[a^2 - 4*b*c]))]/(Sqrt[a^2 - 4*b*c]*d^2*Log[f]^2) - PolyLog[2, -((2*c*f^(c + d*x))/(a + Sqrt[a^2 - 4*b*c]))]/(Sqrt[a^2 - 4*b*c]*d^2*Log[f]^2)}
{x^2/(a + b*f^(-c - d*x) + c*f^(c + d*x)), x, 10, (x^2*Log[1 + (2*c*f^(c + d*x))/(a - Sqrt[a^2 - 4*b*c])])/(Sqrt[a^2 - 4*b*c]*d*Log[f]) - (x^2*Log[1 + (2*c*f^(c + d*x))/(a + Sqrt[a^2 - 4*b*c])])/(Sqrt[a^2 - 4*b*c]*d*Log[f]) + (2*x*PolyLog[2, -((2*c*f^(c + d*x))/(a - Sqrt[a^2 - 4*b*c]))])/(Sqrt[a^2 - 4*b*c]*d^2*Log[f]^2) - (2*x*PolyLog[2, -((2*c*f^(c + d*x))/(a + Sqrt[a^2 - 4*b*c]))])/(Sqrt[a^2 - 4*b*c]*d^2*Log[f]^2) - (2*PolyLog[3, -((2*c*f^(c + d*x))/(a - Sqrt[a^2 - 4*b*c]))])/(Sqrt[a^2 - 4*b*c]*d^3*Log[f]^3) + (2*PolyLog[3, -((2*c*f^(c + d*x))/(a + Sqrt[a^2 - 4*b*c]))])/(Sqrt[a^2 - 4*b*c]*d^3*Log[f]^3)}


(* ::Subsection::Closed:: *)
(*Integrands involving products of exponentials*)


(* Integrands of the form x^m*a^x*b^x where m is an integer *)
{x^2*a^x*b^x, x, 4, (2*a^x*b^x)/(Log[a] + Log[b])^3 - (2*a^x*b^x*x)/(Log[a] + Log[b])^2 + (a^x*b^x*x^2)/(Log[a] + Log[b])}
{x*a^x*b^x, x, 3, -((a^x*b^x)/(Log[a] + Log[b])^2) + (a^x*b^x*x)/(Log[a] + Log[b])}
{a^x*b^x, x, 2, (a^x*b^x)/(Log[a] + Log[b])}
{a^x*b^x/x, x, 2, ExpIntegralEi[x*(Log[a] + Log[b])]}
{a^x*b^x/x^2, x, 3, -((a^x*b^x)/x) + ExpIntegralEi[x*(Log[a] + Log[b])]*(Log[a] + Log[b])}
{a^x*b^x/x^3, x, 4, -((a^x*b^x)/(2*x^2)) - (a^x*b^x*(Log[a] + Log[b]))/(2*x) + (1/2)*ExpIntegralEi[x*(Log[a] + Log[b])]*(Log[a] + Log[b])^2}


{a^x*b^x*c^x, x, 3, (a^x*b^x*c^x)/(Log[a] + Log[b] + Log[c])}
{a^x/b^x, x, 2, a^x/(b^x*(Log[a] - Log[b]))}

{(a^x*x^2)/b^x, x, 4, (2*a^x)/(b^x*(Log[a] - Log[b])^3) - (2*a^x*x)/(b^x*(Log[a] - Log[b])^2) + (a^x*x^2)/(b^x*(Log[a] - Log[b]))}


{E^(a + b*x^n)*E^(c + d*x^n), x, 2, -((E^(a + c)*x*Gamma[1/n, -((b + d)*x^n)])/((-((b + d)*x^n))^n^(-1)*n))}
{f^(a + b*x^n)*g^(c + d*x^n), x, 2, -((f^a*g^c*x*Gamma[1/n, (-x^n)*(b*Log[f] + d*Log[g])])/(((-x^n)*(b*Log[f] + d*Log[g]))^n^(-1)*n))}


(* ::Subsection::Closed:: *)
(*Integrands involving binomials of exponentials of linears*)


(* Integrands of the form E^(2*n*x)/(a+b*E^(n*x))^m where m is an integer *)
{E^(2*x)/(a + b*E^x), x, 3, E^x/b - (a*Log[a + b*E^x])/b^2}
{E^(2*x)/(a + b*E^x)^2, x, 3, a/(b^2*(a + b*E^x)) + Log[a + b*E^x]/b^2}
{E^(2*x)/(a + b*E^x)^3, x, 2, E^(2*x)/(2*a*(a + b*E^x)^2)}
{E^(2*x)/(a + b*E^x)^4, x, 3, a/(3*b^2*(a + b*E^x)^3) - 1/(2*b^2*(a + b*E^x)^2)}

{E^(4*x)/(a + b*E^(2*x)), x, 3, E^(2*x)/(2*b) - (a*Log[a + b*E^(2*x)])/(2*b^2)}
{E^(4*x)/(a + b*E^(2*x))^2, x, 3, a/(2*b^2*(a + b*E^(2*x))) + Log[a + b*E^(2*x)]/(2*b^2)}
{E^(4*x)/(a + b*E^(2*x))^3, x, 2, E^(4*x)/(4*a*(a + b*E^(2*x))^2)}
{E^(4*x)/(a + b*E^(2*x))^4, x, 3, a/(6*b^2*(a + b*E^(2*x))^3) - 1/(4*b^2*(a + b*E^(2*x))^2)}

{E^(4*x)/(a + b*E^(2*x))^(2/3), x, 3, -((3*a*(a + b*E^(2*x))^(1/3))/(2*b^2)) + (3*(a + b*E^(2*x))^(4/3))/(8*b^2)}


(* Integrands of the form E^(-n*x)*(a+b*E^(n*x))^m where m is an integer *)
{E^(-n*x)*(a + b*E^(n*x)), x, 3, -(a/(E^(n*x)*n)) + b*x}
{E^(-n*x)*(a + b*E^(n*x))^2, x, 5, -(a^2/(E^(n*x)*n)) + (b^2*E^(n*x))/n + 2*a*b*x}
{E^(-n*x)*(a + b*E^(n*x))^3, x, 6, -(a^3/(E^(n*x)*n)) + (3*a*b^2*E^(n*x))/n + (b^3*E^(2*n*x))/(2*n) + 3*a^2*b*x}

{E^(-n*x)/(a + b*E^(n*x)), x, 3, -(1/(E^(n*x)*(a*n))) + (b*Log[b + a/E^(n*x)])/(a^2*n)}
{E^(-n*x)/(a + b*E^(n*x))^2, x, 4, -(1/(E^(n*x)*(a^2*n))) + b^2/(a^3*(b + a/E^(n*x))*n) + (2*b*Log[b + a/E^(n*x)])/(a^3*n)}
{E^(-n*x)/(a + b*E^(n*x))^3, x, 4, -(1/(E^(n*x)*(a^3*n))) - b^3/(2*a^4*(b + a/E^(n*x))^2*n) + (3*b^2)/(a^4*(b + a/E^(n*x))*n) + (3*b*Log[b + a/E^(n*x)])/(a^4*n)}


(* Integrands of the form f^(a+n*b*x)/(c+d*f^(e+2*b*x)) where n is an integer *)
{f^(a + b*x)/(c + d*f^(e + 2*b*x)), x, 2, (f^(a - e/2)*ArcTan[(Sqrt[d]*f^(e/2 + b*x))/Sqrt[c]])/(b*Sqrt[c]*Sqrt[d]*Log[f]), (Sqrt[f^(2*a - e)]*ArcTan[(Sqrt[d]*f^(a + b*x))/(Sqrt[c]*Sqrt[f^(2*a - e)])])/(b*Sqrt[c]*Sqrt[d]*Log[f])}
{f^(a + 2*b*x)/(c + d*f^(e + 2*b*x)), x, 1, (f^(a - e)*Log[c + d*f^(e + 2*b*x)])/(2*b*d*Log[f])}
{f^(a + 3*b*x)/(c + d*f^(e + 2*b*x)), x, 4, f^(a - e + b*x)/(b*d*Log[f]) - (Sqrt[c]*f^a*(f^(-e))^(3/2)*ArcTan[(Sqrt[d]*f^(b*x))/(Sqrt[c]*Sqrt[f^(-e)])])/(b*d^(3/2)*Log[f])}
{f^(a + 4*b*x)/(c + d*f^(e + 2*b*x)), x, 4, f^(a - e + 2*b*x)/(2*b*d*Log[f]) - (c*f^(a - 2*e)*Log[c + d*f^(e + 2*b*x)])/(2*b*d^2*Log[f])}
{f^(a + 5*b*x)/(c + d*f^(e + 2*b*x)), x, 5, -((c*f^(a - 2*e + b*x))/(b*d^2*Log[f])) + f^(a - e + 3*b*x)/(3*b*d*Log[f]) + (c^(3/2)*f^a*(f^(-e))^(5/2)*ArcTan[(Sqrt[d]*f^(b*x))/(Sqrt[c]*Sqrt[f^(-e)])])/(b*d^(5/2)*Log[f])}


{x^0*E^x/(1 - E^(2*x)), x, 2, ArcTanh[E^x]}
{x^1*E^x/(1 - E^(2*x)), x, 4, x*ArcTanh[E^x] + (1/2)*PolyLog[2, -E^x] - (1/2)*PolyLog[2, E^x]}
{x^2*E^x/(1 - E^(2*x)), x, 6, x^2*ArcTanh[E^x] + x*PolyLog[2, -E^x] - x*PolyLog[2, E^x] - PolyLog[3, -E^x] + PolyLog[3, E^x]}
{x^3*E^x/(1 - E^(2*x)), x, 8, x^3*ArcTanh[E^x] + (3/2)*x^2*PolyLog[2, -E^x] - (3/2)*x^2*PolyLog[2, E^x] - 3*x*PolyLog[3, -E^x] + 3*x*PolyLog[3, E^x] + 3*PolyLog[4, -E^x] - 3*PolyLog[4, E^x]}


{x^0*f^x/(a + b*f^(2*x)), x, 2, ArcTan[(Sqrt[b]*f^x)/Sqrt[a]]/(Sqrt[a]*Sqrt[b]*Log[f])}
{x^1*f^x/(a + b*f^(2*x)), x, 5, (x*ArcTan[(Sqrt[b]*f^x)/Sqrt[a]])/(Sqrt[a]*Sqrt[b]*Log[f]) - (I*PolyLog[2, -((I*Sqrt[b]*f^x)/Sqrt[a])])/(2*Sqrt[a]*Sqrt[b]*Log[f]^2) + (I*PolyLog[2, (I*Sqrt[b]*f^x)/Sqrt[a]])/(2*Sqrt[a]*Sqrt[b]*Log[f]^2)}
{x^2*f^x/(a + b*f^(2*x)), x, 7, (x^2*ArcTan[(Sqrt[b]*f^x)/Sqrt[a]])/(Sqrt[a]*Sqrt[b]*Log[f]) - (I*x*PolyLog[2, -((I*Sqrt[b]*f^x)/Sqrt[a])])/(Sqrt[a]*Sqrt[b]*Log[f]^2) + (I*x*PolyLog[2, (I*Sqrt[b]*f^x)/Sqrt[a]])/(Sqrt[a]*Sqrt[b]*Log[f]^2) + (I*PolyLog[3, -((I*Sqrt[b]*f^x)/Sqrt[a])])/(Sqrt[a]*Sqrt[b]*Log[f]^3) - (I*PolyLog[3, (I*Sqrt[b]*f^x)/Sqrt[a]])/(Sqrt[a]*Sqrt[b]*Log[f]^3)}
{x^3*f^x/(a + b*f^(2*x)), x, 9, (x^3*ArcTan[(Sqrt[b]*f^x)/Sqrt[a]])/(Sqrt[a]*Sqrt[b]*Log[f]) - (3*I*x^2*PolyLog[2, -((I*Sqrt[b]*f^x)/Sqrt[a])])/(2*Sqrt[a]*Sqrt[b]*Log[f]^2) + (3*I*x^2*PolyLog[2, (I*Sqrt[b]*f^x)/Sqrt[a]])/(2*Sqrt[a]*Sqrt[b]*Log[f]^2) + (3*I*x*PolyLog[3, -((I*Sqrt[b]*f^x)/Sqrt[a])])/(Sqrt[a]*Sqrt[b]*Log[f]^3) - (3*I*x*PolyLog[3, (I*Sqrt[b]*f^x)/Sqrt[a]])/(Sqrt[a]*Sqrt[b]*Log[f]^3) - (3*I*PolyLog[4, -((I*Sqrt[b]*f^x)/Sqrt[a])])/(Sqrt[a]*Sqrt[b]*Log[f]^4) + (3*I*PolyLog[4, (I*Sqrt[b]*f^x)/Sqrt[a]])/(Sqrt[a]*Sqrt[b]*Log[f]^4)}


{x^0*f^x/(a + b*f^(2*x))^2, x, 3, f^x/(2*a*(a + b*f^(2*x))*Log[f]) + ArcTan[(Sqrt[b]*f^x)/Sqrt[a]]/(2*a^(3/2)*Sqrt[b]*Log[f])}
{x^1*f^x/(a + b*f^(2*x))^2, x, 7, -(ArcTan[(Sqrt[b]*f^x)/Sqrt[a]]/(2*a^(3/2)*Sqrt[b]*Log[f]^2)) + (f^x*x)/(2*a*(a + b*f^(2*x))*Log[f]) + (x*ArcTan[(Sqrt[b]*f^x)/Sqrt[a]])/(2*a^(3/2)*Sqrt[b]*Log[f]) - (I*PolyLog[2, -((I*Sqrt[b]*f^x)/Sqrt[a])])/(4*a^(3/2)*Sqrt[b]*Log[f]^2) + (I*PolyLog[2, (I*Sqrt[b]*f^x)/Sqrt[a]])/(4*a^(3/2)*Sqrt[b]*Log[f]^2)}
{x^2*f^x/(a + b*f^(2*x))^2, x, 13, -((x*ArcTan[(Sqrt[b]*f^x)/Sqrt[a]])/(a^(3/2)*Sqrt[b]*Log[f]^2)) + (f^x*x^2)/(2*a*(a + b*f^(2*x))*Log[f]) + (x^2*ArcTan[(Sqrt[b]*f^x)/Sqrt[a]])/(2*a^(3/2)*Sqrt[b]*Log[f]) + (I*PolyLog[2, -((I*Sqrt[b]*f^x)/Sqrt[a])])/(2*a^(3/2)*Sqrt[b]*Log[f]^3) - (I*x*PolyLog[2, -((I*Sqrt[b]*f^x)/Sqrt[a])])/(2*a^(3/2)*Sqrt[b]*Log[f]^2) - (I*PolyLog[2, (I*Sqrt[b]*f^x)/Sqrt[a]])/(2*a^(3/2)*Sqrt[b]*Log[f]^3) + (I*x*PolyLog[2, (I*Sqrt[b]*f^x)/Sqrt[a]])/(2*a^(3/2)*Sqrt[b]*Log[f]^2) + (I*PolyLog[3, -((I*Sqrt[b]*f^x)/Sqrt[a])])/(2*a^(3/2)*Sqrt[b]*Log[f]^3) - (I*PolyLog[3, (I*Sqrt[b]*f^x)/Sqrt[a]])/(2*a^(3/2)*Sqrt[b]*Log[f]^3)}
{x^3*f^x/(a + b*f^(2*x))^2, x, 17, -((3*x^2*ArcTan[(Sqrt[b]*f^x)/Sqrt[a]])/(2*a^(3/2)*Sqrt[b]*Log[f]^2)) + (f^x*x^3)/(2*a*(a + b*f^(2*x))*Log[f]) + (x^3*ArcTan[(Sqrt[b]*f^x)/Sqrt[a]])/(2*a^(3/2)*Sqrt[b]*Log[f]) + (3*I*x*PolyLog[2, -((I*Sqrt[b]*f^x)/Sqrt[a])])/(2*a^(3/2)*Sqrt[b]*Log[f]^3) - (3*I*x^2*PolyLog[2, -((I*Sqrt[b]*f^x)/Sqrt[a])])/(4*a^(3/2)*Sqrt[b]*Log[f]^2) - (3*I*x*PolyLog[2, (I*Sqrt[b]*f^x)/Sqrt[a]])/(2*a^(3/2)*Sqrt[b]*Log[f]^3) + (3*I*x^2*PolyLog[2, (I*Sqrt[b]*f^x)/Sqrt[a]])/(4*a^(3/2)*Sqrt[b]*Log[f]^2) - (3*I*PolyLog[3, -((I*Sqrt[b]*f^x)/Sqrt[a])])/(2*a^(3/2)*Sqrt[b]*Log[f]^4) + (3*I*x*PolyLog[3, -((I*Sqrt[b]*f^x)/Sqrt[a])])/(2*a^(3/2)*Sqrt[b]*Log[f]^3) + (3*I*PolyLog[3, (I*Sqrt[b]*f^x)/Sqrt[a]])/(2*a^(3/2)*Sqrt[b]*Log[f]^4) - (3*I*x*PolyLog[3, (I*Sqrt[b]*f^x)/Sqrt[a]])/(2*a^(3/2)*Sqrt[b]*Log[f]^3) - (3*I*PolyLog[4, -((I*Sqrt[b]*f^x)/Sqrt[a])])/(2*a^(3/2)*Sqrt[b]*Log[f]^4) + (3*I*PolyLog[4, (I*Sqrt[b]*f^x)/Sqrt[a]])/(2*a^(3/2)*Sqrt[b]*Log[f]^4)}


{x^0*f^x/(a + b*f^(2*x))^3, x, 4, f^x/(4*a*(a + b*f^(2*x))^2*Log[f]) + (3*f^x)/(8*a^2*(a + b*f^(2*x))*Log[f]) + (3*ArcTan[(Sqrt[b]*f^x)/Sqrt[a]])/(8*a^(5/2)*Sqrt[b]*Log[f])}
{x^1*f^x/(a + b*f^(2*x))^3, x, 10, -(f^x/(8*a^2*(a + b*f^(2*x))*Log[f]^2)) - ArcTan[(Sqrt[b]*f^x)/Sqrt[a]]/(2*a^(5/2)*Sqrt[b]*Log[f]^2) + (f^x*x)/(4*a*(a + b*f^(2*x))^2*Log[f]) + (3*f^x*x)/(8*a^2*(a + b*f^(2*x))*Log[f]) + (3*x*ArcTan[(Sqrt[b]*f^x)/Sqrt[a]])/(8*a^(5/2)*Sqrt[b]*Log[f]) - (3*I*PolyLog[2, -((I*Sqrt[b]*f^x)/Sqrt[a])])/(16*a^(5/2)*Sqrt[b]*Log[f]^2) + (3*I*PolyLog[2, (I*Sqrt[b]*f^x)/Sqrt[a]])/(16*a^(5/2)*Sqrt[b]*Log[f]^2)}
{x^2*f^x/(a + b*f^(2*x))^3, x, 20, ArcTan[(Sqrt[b]*f^x)/Sqrt[a]]/(4*a^(5/2)*Sqrt[b]*Log[f]^3) - (f^x*x)/(4*a^2*(a + b*f^(2*x))*Log[f]^2) - (x*ArcTan[(Sqrt[b]*f^x)/Sqrt[a]])/(a^(5/2)*Sqrt[b]*Log[f]^2) + (f^x*x^2)/(4*a*(a + b*f^(2*x))^2*Log[f]) + (3*f^x*x^2)/(8*a^2*(a + b*f^(2*x))*Log[f]) + (3*x^2*ArcTan[(Sqrt[b]*f^x)/Sqrt[a]])/(8*a^(5/2)*Sqrt[b]*Log[f]) + (I*PolyLog[2, -((I*Sqrt[b]*f^x)/Sqrt[a])])/(2*a^(5/2)*Sqrt[b]*Log[f]^3) - (3*I*x*PolyLog[2, -((I*Sqrt[b]*f^x)/Sqrt[a])])/(8*a^(5/2)*Sqrt[b]*Log[f]^2) - (I*PolyLog[2, (I*Sqrt[b]*f^x)/Sqrt[a]])/(2*a^(5/2)*Sqrt[b]*Log[f]^3) + (3*I*x*PolyLog[2, (I*Sqrt[b]*f^x)/Sqrt[a]])/(8*a^(5/2)*Sqrt[b]*Log[f]^2) + (3*I*PolyLog[3, -((I*Sqrt[b]*f^x)/Sqrt[a])])/(8*a^(5/2)*Sqrt[b]*Log[f]^3) - (3*I*PolyLog[3, (I*Sqrt[b]*f^x)/Sqrt[a]])/(8*a^(5/2)*Sqrt[b]*Log[f]^3)}
(* {x^3*f^x/(a + b*f^(2*x))^3, x, 30, (3*x*ArcTan[(Sqrt[b]*f^x)/Sqrt[a]])/(4*a^(5/2)*Sqrt[b]*Log[f]^3) - (3*f^x*x^2)/(8*a^2*(a + b*f^(2*x))*Log[f]^2) - (3*x^2*ArcTan[(Sqrt[b]*f^x)/Sqrt[a]])/(2*a^(5/2)*Sqrt[b]*Log[f]^2) + (x^3*((2*a^(3/2)*f^x)/(a + b*f^(2*x))^2 + (3*Sqrt[a]*f^x)/(a + b*f^(2*x)) + (3*ArcTan[(Sqrt[b]*f^x)/Sqrt[a]])/Sqrt[b]))/(8*a^(5/2)*Log[f]) - (3*I*(2 - 8*x*Log[f] + 3*x^2*Log[f]^2)*PolyLog[2, -((I*Sqrt[b]*f^x)/Sqrt[a])])/(16*a^(5/2)*Sqrt[b]*Log[f]^4) + (3*I*(2 - 8*x*Log[f] + 3*x^2*Log[f]^2)*PolyLog[2, (I*Sqrt[b]*f^x)/Sqrt[a]])/(16*a^(5/2)*Sqrt[b]*Log[f]^4) - (3*I*(4 - 3*x*Log[f])*PolyLog[3, -((I*Sqrt[b]*f^x)/Sqrt[a])])/(8*a^(5/2)*Sqrt[b]*Log[f]^4) + (3*I*(4 - 3*x*Log[f])*PolyLog[3, (I*Sqrt[b]*f^x)/Sqrt[a]])/(8*a^(5/2)*Sqrt[b]*Log[f]^4) - (9*I*PolyLog[4, -((I*Sqrt[b]*f^x)/Sqrt[a])])/(8*a^(5/2)*Sqrt[b]*Log[f]^4) + (9*I*PolyLog[4, (I*Sqrt[b]*f^x)/Sqrt[a]])/(8*a^(5/2)*Sqrt[b]*Log[f]^4)} *)


{x^0/(a*f^x + b*f^(-x)), x, 2, ArcTan[(Sqrt[a]*f^x)/Sqrt[b]]/(Sqrt[a]*Sqrt[b]*Log[f])}
{x^1/(a*f^x + b*f^(-x)), x, 5, (x*ArcTan[(Sqrt[a]*f^x)/Sqrt[b]])/(Sqrt[a]*Sqrt[b]*Log[f]) - (I*PolyLog[2, -((I*Sqrt[a]*f^x)/Sqrt[b])])/(2*Sqrt[a]*Sqrt[b]*Log[f]^2) + (I*PolyLog[2, (I*Sqrt[a]*f^x)/Sqrt[b]])/(2*Sqrt[a]*Sqrt[b]*Log[f]^2)}
{x^2/(a*f^x + b*f^(-x)), x, 7, (x^2*ArcTan[(Sqrt[a]*f^x)/Sqrt[b]])/(Sqrt[a]*Sqrt[b]*Log[f]) - (I*x*PolyLog[2, -((I*Sqrt[a]*f^x)/Sqrt[b])])/(Sqrt[a]*Sqrt[b]*Log[f]^2) + (I*x*PolyLog[2, (I*Sqrt[a]*f^x)/Sqrt[b]])/(Sqrt[a]*Sqrt[b]*Log[f]^2) + (I*PolyLog[3, -((I*Sqrt[a]*f^x)/Sqrt[b])])/(Sqrt[a]*Sqrt[b]*Log[f]^3) - (I*PolyLog[3, (I*Sqrt[a]*f^x)/Sqrt[b]])/(Sqrt[a]*Sqrt[b]*Log[f]^3)}
{x^3/(a*f^x + b*f^(-x)), x, 9, (x^3*ArcTan[(Sqrt[a]*f^x)/Sqrt[b]])/(Sqrt[a]*Sqrt[b]*Log[f]) - (3*I*x^2*PolyLog[2, -((I*Sqrt[a]*f^x)/Sqrt[b])])/(2*Sqrt[a]*Sqrt[b]*Log[f]^2) + (3*I*x^2*PolyLog[2, (I*Sqrt[a]*f^x)/Sqrt[b]])/(2*Sqrt[a]*Sqrt[b]*Log[f]^2) + (3*I*x*PolyLog[3, -((I*Sqrt[a]*f^x)/Sqrt[b])])/(Sqrt[a]*Sqrt[b]*Log[f]^3) - (3*I*x*PolyLog[3, (I*Sqrt[a]*f^x)/Sqrt[b]])/(Sqrt[a]*Sqrt[b]*Log[f]^3) - (3*I*PolyLog[4, -((I*Sqrt[a]*f^x)/Sqrt[b])])/(Sqrt[a]*Sqrt[b]*Log[f]^4) + (3*I*PolyLog[4, (I*Sqrt[a]*f^x)/Sqrt[b]])/(Sqrt[a]*Sqrt[b]*Log[f]^4)}


{x^0/(a*f^x + b*f^(-x))^2, x, 2, -(1/(2*a*(b + a*f^(2*x))*Log[f]))}
{x^1/(a*f^x + b*f^(-x))^2, x, 3, x/(2*a*b*Log[f]) - x/(2*a*(b + a*f^(2*x))*Log[f]) - Log[b + a*f^(2*x)]/(4*a*b*Log[f]^2)}
{x^2/(a*f^x + b*f^(-x))^2, x, 5, x^2/(2*a*b*Log[f]) - x^2/(2*a*(b + a*f^(2*x))*Log[f]) - (x*Log[1 + (a*f^(2*x))/b])/(2*a*b*Log[f]^2) - PolyLog[2, -((a*f^(2*x))/b)]/(4*a*b*Log[f]^3)}
{x^3/(a*f^x + b*f^(-x))^2, x, 6, x^3/(2*a*b*Log[f]) - x^3/(2*a*(b + a*f^(2*x))*Log[f]) - (3*x^2*Log[1 + (a*f^(2*x))/b])/(4*a*b*Log[f]^2) - (3*x*PolyLog[2, -((a*f^(2*x))/b)])/(4*a*b*Log[f]^3) + (3*PolyLog[3, -((a*f^(2*x))/b)])/(8*a*b*Log[f]^4)}


{x^0/(a*f^x + b*f^(-x))^3, x, 4, -(f^x/(4*a*(b + a*f^(2*x))^2*Log[f])) + f^x/(8*a*b*(b + a*f^(2*x))*Log[f]) + ArcTan[(Sqrt[a]*f^x)/Sqrt[b]]/(8*a^(3/2)*b^(3/2)*Log[f])}
{x^1/(a*f^x + b*f^(-x))^3, x, 19, f^x/(8*a*b*(b + a*f^(2*x))*Log[f]^2) - (f^x*x)/(4*a*(b + a*f^(2*x))^2*Log[f]) + (f^x*x)/(8*a*b*(b + a*f^(2*x))*Log[f]) + (x*ArcTan[(Sqrt[a]*f^x)/Sqrt[b]])/(8*a^(3/2)*b^(3/2)*Log[f]) - (I*PolyLog[2, -((I*Sqrt[a]*f^x)/Sqrt[b])])/(16*a^(3/2)*b^(3/2)*Log[f]^2) + (I*PolyLog[2, (I*Sqrt[a]*f^x)/Sqrt[b]])/(16*a^(3/2)*b^(3/2)*Log[f]^2)}
{x^2/(a*f^x + b*f^(-x))^3, x, 35, -(ArcTan[(Sqrt[a]*f^x)/Sqrt[b]]/(4*a^(3/2)*b^(3/2)*Log[f]^3)) + (f^x*x)/(4*a*b*(b + a*f^(2*x))*Log[f]^2) - (f^x*x^2)/(4*a*(b + a*f^(2*x))^2*Log[f]) + (f^x*x^2)/(8*a*b*(b + a*f^(2*x))*Log[f]) + (x^2*ArcTan[(Sqrt[a]*f^x)/Sqrt[b]])/(8*a^(3/2)*b^(3/2)*Log[f]) - (I*x*PolyLog[2, -((I*Sqrt[a]*f^x)/Sqrt[b])])/(8*a^(3/2)*b^(3/2)*Log[f]^2) + (I*x*PolyLog[2, (I*Sqrt[a]*f^x)/Sqrt[b]])/(8*a^(3/2)*b^(3/2)*Log[f]^2) + (I*PolyLog[3, -((I*Sqrt[a]*f^x)/Sqrt[b])])/(8*a^(3/2)*b^(3/2)*Log[f]^3) - (I*PolyLog[3, (I*Sqrt[a]*f^x)/Sqrt[b]])/(8*a^(3/2)*b^(3/2)*Log[f]^3)}
(* {x^3/(a*f^x + b*f^(-x))^3, x, 49, -((3*x*ArcTan[(Sqrt[a]*f^x)/Sqrt[b]])/(4*a^(3/2)*b^(3/2)*Log[f]^3)) + (3*f^x*x^2)/(8*a*b*(b + a*f^(2*x))*Log[f]^2) - (f^x*(5 + (3*a*f^(2*x))/b)*x^3)/(8*a*(b + a*f^(2*x))^2*Log[f]) + (x^3*((4*Sqrt[a]*Sqrt[b]*f^x)/(b + a*f^(2*x)) + ArcTan[(Sqrt[a]*f^x)/Sqrt[b]]))/(8*a^(3/2)*b^(3/2)*Log[f]) + (3*I*(2 - x^2*Log[f]^2)*PolyLog[2, -((I*Sqrt[a]*f^x)/Sqrt[b])])/(16*a^(3/2)*b^(3/2)*Log[f]^4) - (3*I*(2 - x^2*Log[f]^2)*PolyLog[2, (I*Sqrt[a]*f^x)/Sqrt[b]])/(16*a^(3/2)*b^(3/2)*Log[f]^4) + (3*I*x*PolyLog[3, -((I*Sqrt[a]*f^x)/Sqrt[b])])/(8*a^(3/2)*b^(3/2)*Log[f]^3) - (3*I*x*PolyLog[3, (I*Sqrt[a]*f^x)/Sqrt[b]])/(8*a^(3/2)*b^(3/2)*Log[f]^3) - (3*I*PolyLog[4, -((I*Sqrt[a]*f^x)/Sqrt[b])])/(8*a^(3/2)*b^(3/2)*Log[f]^4) + (3*I*PolyLog[4, (I*Sqrt[a]*f^x)/Sqrt[b]])/(8*a^(3/2)*b^(3/2)*Log[f]^4)} *)


{f^(a + b*x + c*x^2)*g^(d + e*x + f*x^2), x, 3, (f^a*g^d*Sqrt[Pi]*Erfi[(b*Log[f] + e*Log[g] + 2*x*(c*Log[f] + f*Log[g]))/(2*Sqrt[c*Log[f] + f*Log[g]])])/(E^((b*Log[f] + e*Log[g])^2/(4*(c*Log[f] + f*Log[g])))*(2*Sqrt[c*Log[f] + f*Log[g]]))}


(* ::Section::Closed:: *)
(*Integrands involving exponential and trig functions*)


(* ::Subsection::Closed:: *)
(*Integrands involving products of exponential and trig functions*)


(* Integrands of the form E^x*Cos[a+b*x]^m*Sin[a+b*x]^n where m and n are positive integers *)
{E^x*Cos[a + b*x]*Sin[a + b*x], x, 3, -((b*E^x*Cos[2*a + 2*b*x])/(1 + 4*b^2)) + (E^x*Sin[2*a + 2*b*x])/(2*(1 + 4*b^2))}
{E^x*Cos[a + b*x]*Sin[a + b*x]^2, x, 4, (E^x*Cos[a + b*x])/(4*(1 + b^2)) - (E^x*Cos[3*a + 3*b*x])/(4*(1 + 9*b^2)) + (b*E^x*Sin[a + b*x])/(4*(1 + b^2)) - (3*b*E^x*Sin[3*a + 3*b*x])/(4*(1 + 9*b^2))}
{E^x*Cos[a + b*x]*Sin[a + b*x]^3, x, 4, -((b*E^x*Cos[2*a + 2*b*x])/(2*(1 + 4*b^2))) + (b*E^x*Cos[4*a + 4*b*x])/(2*(1 + 16*b^2)) + (E^x*Sin[2*a + 2*b*x])/(4*(1 + 4*b^2)) - (E^x*Sin[4*a + 4*b*x])/(8*(1 + 16*b^2))}

{E^x*Cos[a + b*x]^2*Sin[a + b*x], x, 4, -((b*E^x*Cos[a + b*x])/(4*(1 + b^2))) - (3*b*E^x*Cos[3*a + 3*b*x])/(4*(1 + 9*b^2)) + (E^x*Sin[a + b*x])/(4*(1 + b^2)) + (E^x*Sin[3*a + 3*b*x])/(4*(1 + 9*b^2))}
{E^x*Cos[a + b*x]^2*Sin[a + b*x]^2, x, 4, E^x/8 - (E^x*Cos[4*a + 4*b*x])/(8*(1 + 16*b^2)) - (b*E^x*Sin[4*a + 4*b*x])/(2*(1 + 16*b^2))}
{E^x*Cos[a + b*x]^2*Sin[a + b*x]^3, x, 5, -((b*E^x*Cos[a + b*x])/(8*(1 + b^2))) - (3*b*E^x*Cos[3*a + 3*b*x])/(16*(1 + 9*b^2)) + (5*b*E^x*Cos[5*a + 5*b*x])/(16*(1 + 25*b^2)) + (E^x*Sin[a + b*x])/(8*(1 + b^2)) + (E^x*Sin[3*a + 3*b*x])/(16*(1 + 9*b^2)) - (E^x*Sin[5*a + 5*b*x])/(16*(1 + 25*b^2))}

{E^x*Cos[a + b*x]^3*Sin[a + b*x], x, 4, -((b*E^x*Cos[2*a + 2*b*x])/(2*(1 + 4*b^2))) - (b*E^x*Cos[4*a + 4*b*x])/(2*(1 + 16*b^2)) + (E^x*Sin[2*a + 2*b*x])/(4*(1 + 4*b^2)) + (E^x*Sin[4*a + 4*b*x])/(8*(1 + 16*b^2))}
{E^x*Cos[a + b*x]^3*Sin[a + b*x]^2, x, 5, (E^x*Cos[a + b*x])/(8*(1 + b^2)) - (E^x*Cos[3*a + 3*b*x])/(16*(1 + 9*b^2)) - (E^x*Cos[5*a + 5*b*x])/(16*(1 + 25*b^2)) + (b*E^x*Sin[a + b*x])/(8*(1 + b^2)) - (3*b*E^x*Sin[3*a + 3*b*x])/(16*(1 + 9*b^2)) - (5*b*E^x*Sin[5*a + 5*b*x])/(16*(1 + 25*b^2))}
{E^x*Cos[a + b*x]^3*Sin[a + b*x]^3, x, 4, -((3*b*E^x*Cos[2*a + 2*b*x])/(16*(1 + 4*b^2))) + (3*b*E^x*Cos[6*a + 6*b*x])/(16*(1 + 36*b^2)) + (3*E^x*Sin[2*a + 2*b*x])/(32*(1 + 4*b^2)) - (E^x*Sin[6*a + 6*b*x])/(32*(1 + 36*b^2))}


(* Integrands involving products of exponential and trig functions of quadratics *)
{E^x*Sin[a + b*x + c*x^2], x, 7, ((-1)^(3/4)*E^((1/4)*I*(4*a + (1 + I*b)^2/c))*Sqrt[Pi]*Erf[((-1)^(1/4)*(1 + I*b + 2*I*c*x))/(2*Sqrt[c])])/(4*Sqrt[c]) + ((-1)^(3/4)*E^((-I)*a + (I*(I + b)^2)/(4*c))*Sqrt[Pi]*Erfi[((-1)^(1/4)*(1 - I*b - 2*I*c*x))/(2*Sqrt[c])])/(4*Sqrt[c])}
{E^x*Cos[a + b*x + c*x^2], x, 7, -(((-1)^(1/4)*E^((1/4)*I*(4*a + (1 + I*b)^2/c))*Sqrt[Pi]*Erf[((-1)^(1/4)*(1 + I*b + 2*I*c*x))/(2*Sqrt[c])])/(4*Sqrt[c])) + ((-1)^(1/4)*E^((-I)*a + (I*(I + b)^2)/(4*c))*Sqrt[Pi]*Erfi[((-1)^(1/4)*(1 - I*b - 2*I*c*x))/(2*Sqrt[c])])/(4*Sqrt[c])}


{f^(a + b*x + c*x^2)*Sin[c + d*x + e*x^2], x, 7, -((I*E^((-I)*c - (d + I*b*Log[f])^2/(4*I*e - 4*c*Log[f]))*f^a*Sqrt[Pi]*Erfi[(I*d - b*Log[f] + 2*I*x*(e + I*c*Log[f]))/(2*Sqrt[(-I)*e + c*Log[f]])])/(4*Sqrt[(-I)*e + c*Log[f]])) - (I*E^(I*c + (d - I*b*Log[f])^2/(4*I*e + 4*c*Log[f]))*f^a*Sqrt[Pi]*Erfi[(I*d + b*Log[f] + 2*x*(I*e + c*Log[f]))/(2*Sqrt[I*e + c*Log[f]])])/(4*Sqrt[I*e + c*Log[f]])}
{f^(a + b*x + c*x^2)*Cos[c + d*x + e*x^2], x, 7, -((E^((-I)*c - (d + I*b*Log[f])^2/(4*I*e - 4*c*Log[f]))*f^a*Sqrt[Pi]*Erfi[(I*d - b*Log[f] + 2*I*x*(e + I*c*Log[f]))/(2*Sqrt[(-I)*e + c*Log[f]])])/(4*Sqrt[(-I)*e + c*Log[f]])) + (E^(I*c + (d - I*b*Log[f])^2/(4*I*e + 4*c*Log[f]))*f^a*Sqrt[Pi]*Erfi[(I*d + b*Log[f] + 2*x*(I*e + c*Log[f]))/(2*Sqrt[I*e + c*Log[f]])])/(4*Sqrt[I*e + c*Log[f]])}


{E^(a*x)*Sin[b*x], x, 1, -((b*E^(a*x)*Cos[b*x])/(a^2 + b^2)) + (a*E^(a*x)*Sin[b*x])/(a^2 + b^2)}
{E^x*Sin[7 + 5*x], x, 1, (-(5/26))*E^x*Cos[7 + 5*x] + (1/26)*E^x*Sin[7 + 5*x]}
{E^(5*x)*Sin[3*x], x, 1, (-(3/34))*E^(5*x)*Cos[3*x] + (5/34)*E^(5*x)*Sin[3*x]}

{E^(a*x)*Cos[b*x], x, 1, (a*E^(a*x)*Cos[b*x])/(a^2 + b^2) + (b*E^(a*x)*Sin[b*x])/(a^2 + b^2)}
{E^(2*x^2)*x*Cos[2*x^2], x, 2, (1/8)*E^(2*x^2)*Cos[2*x^2] + (1/8)*E^(2*x^2)*Sin[2*x^2]}

{E^(3*x)*(-5*Cos[4*x] + 2*Sin[4*x]), x, 4, (-(23/25))*E^(3*x)*Cos[4*x] - (14/25)*E^(3*x)*Sin[4*x]}

{E^x*x*Sin[x], x, 4, (1/2)*E^x*Cos[x] - (1/2)*E^x*x*Cos[x] + (1/2)*E^x*x*Sin[x]}
{E^x*x*Cos[x], x, 4, (1/2)*E^x*x*Cos[x] - (1/2)*E^x*Sin[x] + (1/2)*E^x*x*Sin[x]}

{E^x*x^2*Sin[x], x, 13, (-(1/2))*E^x*Cos[x] + E^x*x*Cos[x] - (1/2)*E^x*x^2*Cos[x] - (1/2)*E^x*Sin[x] + (1/2)*E^x*x^2*Sin[x]}
{E^x*x^2*Cos[x], x, 13, (-(1/2))*E^x*Cos[x] + (1/2)*E^x*x^2*Cos[x] + (1/2)*E^x*Sin[x] - E^x*x*Sin[x] + (1/2)*E^x*x^2*Sin[x]}
{E^(3*x)*x^2*Sin[x], x, 13, (-(13/250))*E^(3*x)*Cos[x] + (3/25)*E^(3*x)*x*Cos[x] - (1/10)*E^(3*x)*x^2*Cos[x] + (9/250)*E^(3*x)*Sin[x] - (4/25)*E^(3*x)*x*Sin[x] + (3/10)*E^(3*x)*x^2*Sin[x]}

{E^x*Sin[x]^2, x, 2, (2*E^x)/5 - (2/5)*E^x*Cos[x]*Sin[x] + (1/5)*E^x*Sin[x]^2}
{E^x*Cos[x]^2, x, 2, (2*E^x)/5 + (1/5)*E^x*Cos[x]^2 + (2/5)*E^x*Cos[x]*Sin[x]}
{E^x*Sin[x]^4, x, 3, (24*E^x)/85 - (24/85)*E^x*Cos[x]*Sin[x] + (12/85)*E^x*Sin[x]^2 - (4/17)*E^x*Cos[x]*Sin[x]^3 + (1/17)*E^x*Sin[x]^4}
{E^x*Cos[x]^4, x, 3, (24*E^x)/85 + (12/85)*E^x*Cos[x]^2 + (1/17)*E^x*Cos[x]^4 + (24/85)*E^x*Cos[x]*Sin[x] + (4/17)*E^x*Cos[x]^3*Sin[x]}

{(Cos[x] + Sin[x])/(E^(-x) + Sin[x]), x, -5, Log[1 + E^x*Sin[x]]}

{Sin[x]/E^x + E^x*Sin[x], x, 3, ((-(1/2))*Cos[x])/E^x - (1/2)*E^x*Cos[x] - ((1/2)*Sin[x])/E^x + (1/2)*E^x*Sin[x]}


{E^x*Sin[x], x, 1, (-(1/2))*E^x*Cos[x] + (1/2)*E^x*Sin[x]}
{E^(2*x)*Sin[3*x], x, 1, (-(3/13))*E^(2*x)*Cos[3*x] + (2/13)*E^(2*x)*Sin[3*x]}
{E^(2*x)*Cos[x], x, 1, (2/5)*E^(2*x)*Cos[x] + (1/5)*E^(2*x)*Sin[x]}
{Cos[5*x]/E^x, x, 1, ((-(1/26))*Cos[5*x])/E^x + ((5/26)*Sin[5*x])/E^x}

{E^(3*x)*Sin[4 + x], x, 1, (-(1/10))*E^(3*x)*Cos[4 + x] + (3/10)*E^(3*x)*Sin[4 + x]}
{E^(3*x)*Cos[4 + x], x, 1, (3/10)*E^(3*x)*Cos[4 + x] + (1/10)*E^(3*x)*Sin[4 + x]}

{E^x*Sin[x]^3, x, 2, (-(3/10))*E^x*Cos[x] + (3/10)*E^x*Sin[x] - (3/10)*E^x*Cos[x]*Sin[x]^2 + (1/10)*E^x*Sin[x]^3}
{E^x*Cos[x]^3, x, 2, (3/10)*E^x*Cos[x] + (1/10)*E^x*Cos[x]^3 + (3/10)*E^x*Sin[x] + (3/10)*E^x*Cos[x]^2*Sin[x]}

{E^(x^2)*Sin[b*x], x, 5, (1/4)*I*E^(b^2/4)*Sqrt[Pi]*Erfi[(1/2)*((-I)*b + 2*x)] - (1/4)*I*E^(b^2/4)*Sqrt[Pi]*Erfi[(1/2)*(I*b + 2*x)]}
{E^(x^2)*Cos[b*x], x, 5, (1/4)*E^(b^2/4)*Sqrt[Pi]*Erfi[(1/2)*((-I)*b + 2*x)] + (1/4)*E^(b^2/4)*Sqrt[Pi]*Erfi[(1/2)*(I*b + 2*x)]}
{E^(x^2)*Sin[a + b*x], x, 7, (1/4)*I*E^((-I)*a + b^2/4)*Sqrt[Pi]*Erfi[(1/2)*((-I)*b + 2*x)] - (1/4)*I*E^(I*a + b^2/4)*Sqrt[Pi]*Erfi[(1/2)*(I*b + 2*x)]}
{E^(x^2)*Cos[a + b*x], x, 7, (1/4)*E^((-I)*a + b^2/4)*Sqrt[Pi]*Erfi[(1/2)*((-I)*b + 2*x)] + (1/4)*E^(I*a + b^2/4)*Sqrt[Pi]*Erfi[(1/2)*(I*b + 2*x)]}


(* ::Subsection::Closed:: *)
(*Integrands involving exponentials of trig functions*)


(* Integrands of the form E^(n*Sin[a+b*x])*Sin[2*(a+b*x)] *)
{E^(n*Sin[a+b*x])*Sin[2*a+2*b*x], x, 4, -((2*E^(n*Sin[a + b*x]))/(b*n^2)) + (2*E^(n*Sin[a + b*x])*Sin[a + b*x])/(b*n)}
{E^(n*Sin[a+b*x])*Sin[2*(a+b*x)], x, 4, -((2*E^(n*Sin[a + b*x]))/(b*n^2)) + (2*E^(n*Sin[a + b*x])*Sin[a + b*x])/(b*n)}
{E^(n*Sin[a/2+b/2*x])*Sin[a+b*x], x, 4, -((4*E^(n*Sin[a/2 + (b*x)/2]))/(b*n^2)) + (4*E^(n*Sin[a/2 + (b*x)/2])*Sin[a/2 + (b*x)/2])/(b*n)}
{E^(n*Sin[(a+b*x)/2])*Sin[a+b*x], x, 4, -((4*E^(n*Sin[a/2 + (b*x)/2]))/(b*n^2)) + (4*E^(n*Sin[a/2 + (b*x)/2])*Sin[a/2 + (b*x)/2])/(b*n)}


(* Integrands of the form E^(n*Cos[a+b*x])*Sin[2*(a+b*x)] *)
{E^(n*Cos[a+b*x])*Sin[2*a+2*b*x], x, 4, (2*E^(n*Cos[a + b*x]))/(b*n^2) - (2*E^(n*Cos[a + b*x])*Cos[a + b*x])/(b*n)}
{E^(n*Cos[a+b*x])*Sin[2*(a+b*x)], x, 4, (2*E^(n*Cos[a + b*x]))/(b*n^2) - (2*E^(n*Cos[a + b*x])*Cos[a + b*x])/(b*n)}
{E^(n*Cos[a/2+b/2*x])*Sin[a+b*x], x, 4, (4*E^(n*Cos[a/2 + (b*x)/2]))/(b*n^2) - (4*E^(n*Cos[a/2 + (b*x)/2])*Cos[a/2 + (b*x)/2])/(b*n)}
{E^(n*Cos[(a+b*x)/2])*Sin[a+b*x], x, 4, (4*E^(n*Cos[a/2 + (b*x)/2]))/(b*n^2) - (4*E^(n*Cos[a/2 + (b*x)/2])*Cos[a/2 + (b*x)/2])/(b*n)}


(* Integrands of the form E^(n*Cos[a+b*x])*Sin[a+b*x] *)
{E^(n*Cos[a+b*x])*Sin[a+b*x], x, 2, -(E^(n*Cos[a + b*x])/(b*n))}
{E^(n*Cos[a*c+b*c*x])*Sin[c*(a+b*x)], x, 3, -(E^(n*Cos[a*c + b*c*x])/(b*c*n))}
{E^(n*Cos[c*(a+b*x)])*Sin[a*c+b*c*x], x, 2, -(E^(n*Cos[a*c + b*c*x])/(b*c*n))}


(* Integrands of the form E^(n*Sin[a+b*x])*Cos[a+b*x] *)
{E^(n*Sin[a+b*x])*Cos[a+b*x], x, 2, E^(n*Sin[a + b*x])/(b*n)}
{E^(n*Sin[a*c+b*c*x])*Cos[c*(a+b*x)], x, 3, E^(n*Sin[a*c + b*c*x])/(b*c*n)}
{E^(n*Sin[c*(a+b*x)])*Cos[a*c+b*c*x], x, 2, E^(n*Sin[a*c + b*c*x])/(b*c*n)}


(* Integrands of the form E^(n*Cos[a+b*x])*Sin[a+b*x] *)
{E^(n*Cos[a+b*x])*Tan[a+b*x], x, 2, -(ExpIntegralEi[n*Cos[a + b*x]]/b)}
{E^(n*Cos[a*c+b*c*x])*Tan[c*(a+b*x)], x, 2, -(ExpIntegralEi[n*Cos[a*c + b*c*x]]/(b*c))}
{E^(n*Cos[c*(a+b*x)])*Tan[a*c+b*c*x], x, 2, -(ExpIntegralEi[n*Cos[a*c + b*c*x]]/(b*c))}


(* Integrands of the form E^(n*Sin[a+b*x])*Cos[a+b*x] *)
{E^(n*Sin[a+b*x])*Cot[a+b*x], x, 2, ExpIntegralEi[n*Sin[a + b*x]]/b}
{E^(n*Sin[a*c+b*c*x])*Cot[c*(a+b*x)], x, 2, ExpIntegralEi[n*Sin[a*c + b*c*x]]/(b*c)}
{E^(n*Sin[c*(a+b*x)])*Cot[a*c+b*c*x], x, 2, ExpIntegralEi[n*Sin[a*c + b*c*x]]/(b*c)}


{E^(Cos[x]*Sin[x])*Cos[2*x], x, 2, E^(Cos[x]*Sin[x])}
{E^(Cos[x/2]*Sin[x/2])*Cos[x], x, 2, 2*E^(Cos[x/2]*Sin[x/2])}

{E^Sin[x]*Cos[x]*Sin[x], x, 3, -E^Sin[x] + E^Sin[x]*Sin[x]}
{E^Cos[1 + 3*x]*Cos[1 + 3*x]*Sin[1 + 3*x], x, 3, (1/3)*E^Cos[1 + 3*x] - (1/3)*E^Cos[1 + 3*x]*Cos[1 + 3*x]}

{Sec[x]^2*E^Tan[x], x, 2, E^Tan[x]}
{Csc[x]^2/E^Cot[x], x, 2, E^(-Cot[x])}
{E^Sec[x]*Sec[x]*Tan[x], x, 2, E^Sec[x]}
{2^Sec[x]*Sec[x]*Tan[x], x, 2, 2^Sec[x]/Log[2]}


(* ::Subsection::Closed:: *)
(*Integrands involving trig functions of exponentials*)


(* Integrands involving products of exponential and trig functions of exponentials *)
{E^x*Sin[E^x], x, 2, -Cos[E^x]}

{E^x*Csc[E^x]*Sec[E^x], x, 3, Log[Tan[E^x]]}
{E^x*Cos[E^x], x, 2, Sin[E^x]}
{E^(2*x)*Cos[E^(2*x)], x, 2, Sin[E^(2*x)]/2}
{Cos[E^(-2*x)]/E^(2*x), x, 2, -Sin[E^(-2*x)]/2}
{E^(2*x)*Cos[E^x], x, 3, Cos[E^x] + E^x*Sin[E^x]}
{E^(-1 + 3*x)*Cos[E^(-1 + 3*x)]*Sin[1 + E^(-1 + 3*x)], x, 4, -Cos[1 + 2*E^(-1 + 3*x)]/12 + (E^(-1 + 3*x)*Sin[1])/6}

{E^x*Tan[E^x], x, 2, -Log[Cos[E^x]]}

{E^x*Sec[E^x], x, 2, ArcTanh[Sin[E^x]]}
{E^x*Sec[E^x]*Tan[E^x], x, 2, Sec[E^x]}

{E^x*Csc[E^x]^2, x, 2, -Cot[E^x]}


(* ::Section::Closed:: *)
(*Integrands involving exponential and hyperbolic functions*)


(* ::Subsection::Closed:: *)
(*Integrands involving products of exponential and hyperbolic functions*)


(* Integrands of the form E^x*Cosh[a+b*x]^m*Sinh[a+b*x]^n where m and n are positive integers *)
{E^x*Cosh[a + b*x]*Sinh[a + b*x], x, 3, -((b*E^x*Cosh[2*a + 2*b*x])/(1 - 4*b^2)) + (E^x*Sinh[2*a + 2*b*x])/(2*(1 - 4*b^2))}
{E^x*Cosh[a + b*x]*Sinh[a + b*x]^2, x, 4, -((E^x*Cosh[a + b*x])/(4*(1 - b^2))) + (E^x*Cosh[3*a + 3*b*x])/(4*(1 - 9*b^2)) + (b*E^x*Sinh[a + b*x])/(4*(1 - b^2)) - (3*b*E^x*Sinh[3*a + 3*b*x])/(4*(1 - 9*b^2))}
{E^x*Cosh[a + b*x]*Sinh[a + b*x]^3, x, 4, (b*E^x*Cosh[2*a + 2*b*x])/(2*(1 - 4*b^2)) - (b*E^x*Cosh[4*a + 4*b*x])/(2*(1 - 16*b^2)) - (E^x*Sinh[2*a + 2*b*x])/(4*(1 - 4*b^2)) + (E^x*Sinh[4*a + 4*b*x])/(8*(1 - 16*b^2))}

{E^x*Cosh[a + b*x]^2*Sinh[a + b*x], x, 4, -((b*E^x*Cosh[a + b*x])/(4*(1 - b^2))) - (3*b*E^x*Cosh[3*a + 3*b*x])/(4*(1 - 9*b^2)) + (E^x*Sinh[a + b*x])/(4*(1 - b^2)) + (E^x*Sinh[3*a + 3*b*x])/(4*(1 - 9*b^2))}
{E^x*Cosh[a + b*x]^2*Sinh[a + b*x]^2, x, 4, -(E^x/8) + (E^x*Cosh[4*a + 4*b*x])/(8*(1 - 16*b^2)) - (b*E^x*Sinh[4*a + 4*b*x])/(2*(1 - 16*b^2))}
{E^x*Cosh[a + b*x]^2*Sinh[a + b*x]^3, x, 5, (b*E^x*Cosh[a + b*x])/(8*(1 - b^2)) + (3*b*E^x*Cosh[3*a + 3*b*x])/(16*(1 - 9*b^2)) - (5*b*E^x*Cosh[5*a + 5*b*x])/(16*(1 - 25*b^2)) - (E^x*Sinh[a + b*x])/(8*(1 - b^2)) - (E^x*Sinh[3*a + 3*b*x])/(16*(1 - 9*b^2)) + (E^x*Sinh[5*a + 5*b*x])/(16*(1 - 25*b^2))}

{E^x*Cosh[a + b*x]^3*Sinh[a + b*x], x, 4, -((b*E^x*Cosh[2*a + 2*b*x])/(2*(1 - 4*b^2))) - (b*E^x*Cosh[4*a + 4*b*x])/(2*(1 - 16*b^2)) + (E^x*Sinh[2*a + 2*b*x])/(4*(1 - 4*b^2)) + (E^x*Sinh[4*a + 4*b*x])/(8*(1 - 16*b^2))}
{E^x*Cosh[a + b*x]^3*Sinh[a + b*x]^2, x, 5, -((E^x*Cosh[a + b*x])/(8*(1 - b^2))) + (E^x*Cosh[3*a + 3*b*x])/(16*(1 - 9*b^2)) + (E^x*Cosh[5*a + 5*b*x])/(16*(1 - 25*b^2)) + (b*E^x*Sinh[a + b*x])/(8*(1 - b^2)) - (3*b*E^x*Sinh[3*a + 3*b*x])/(16*(1 - 9*b^2)) - (5*b*E^x*Sinh[5*a + 5*b*x])/(16*(1 - 25*b^2))}
{E^x*Cosh[a + b*x]^3*Sinh[a + b*x]^3, x, 4, (3*b*E^x*Cosh[2*a + 2*b*x])/(16*(1 - 4*b^2)) - (3*b*E^x*Cosh[6*a + 6*b*x])/(16*(1 - 36*b^2)) - (3*E^x*Sinh[2*a + 2*b*x])/(32*(1 - 4*b^2)) + (E^x*Sinh[6*a + 6*b*x])/(32*(1 - 36*b^2))}


(* Integrands of the form E^x*Cosh[x]^m*Sinh[x]^n where m and n are positive integers *)
{E^x*Cosh[x]*Sinh[x], x, 3, (1/3)*E^x*Cosh[2*x] - (1/6)*E^x*Sinh[2*x]}
{E^x*Cosh[x]*Sinh[x]^2, x, 6, -(E^(2*x)/16) - x/8 - (1/32)*E^x*Cosh[3*x] + (3/32)*E^x*Sinh[3*x]}
{E^x*Cosh[x]*Sinh[x]^3, x, 4, (-(1/6))*E^x*Cosh[2*x] + (1/30)*E^x*Cosh[4*x] + (1/12)*E^x*Sinh[2*x] - (1/120)*E^x*Sinh[4*x]}

{E^x*Cosh[x]^2*Sinh[x], x, 6, E^(2*x)/16 - x/8 + (3/32)*E^x*Cosh[3*x] - (1/32)*E^x*Sinh[3*x]}
{E^x*Cosh[x]^2*Sinh[x]^2, x, 4, -(E^x/8) - (1/120)*E^x*Cosh[4*x] + (1/30)*E^x*Sinh[4*x]}
{E^x*Cosh[x]^2*Sinh[x]^3, x, 7, -(E^(2*x)/32) + x/16 - (3/128)*E^x*Cosh[3*x] + (5/384)*E^x*Cosh[5*x] + (1/128)*E^x*Sinh[3*x] - (1/384)*E^x*Sinh[5*x]}

{E^x*Cosh[x]^3*Sinh[x], x, 4, (1/6)*E^x*Cosh[2*x] + (1/30)*E^x*Cosh[4*x] - (1/12)*E^x*Sinh[2*x] - (1/120)*E^x*Sinh[4*x]}
{E^x*Cosh[x]^3*Sinh[x]^2, x, 7, -(E^(2*x)/32) - x/16 - (1/128)*E^x*Cosh[3*x] - (1/384)*E^x*Cosh[5*x] + (3/128)*E^x*Sinh[3*x] + (5/384)*E^x*Sinh[5*x]}
{E^x*Cosh[x]^3*Sinh[x]^3, x, 4, (-(1/16))*E^x*Cosh[2*x] + (3/560)*E^x*Cosh[6*x] + (1/32)*E^x*Sinh[2*x] - (E^x*Sinh[6*x])/1120}


(* Integrands involving products of exponential and trig functions of quadratics *)
{E^x*Sinh[a + b*x + c*x^2], x, 7, (E^(-a + (1 - b)^2/(4*c))*Sqrt[Pi]*Erf[(1 - b - 2*c*x)/(2*Sqrt[c])])/(4*Sqrt[c]) + (E^(a - (1 + b)^2/(4*c))*Sqrt[Pi]*Erfi[(1 + b + 2*c*x)/(2*Sqrt[c])])/(4*Sqrt[c])}
{E^x*Cosh[a + b*x + c*x^2], x, 7, -((E^(-a + (1 - b)^2/(4*c))*Sqrt[Pi]*Erf[(1 - b - 2*c*x)/(2*Sqrt[c])])/(4*Sqrt[c])) + (E^(a - (1 + b)^2/(4*c))*Sqrt[Pi]*Erfi[(1 + b + 2*c*x)/(2*Sqrt[c])])/(4*Sqrt[c])}


{f^(a + b*x + c*x^2)*Sinh[c + d*x + e*x^2], x, 7, (E^(-c + (d - b*Log[f])^2/(4*(e - c*Log[f])))*f^a*Sqrt[Pi]*Erfi[(d - b*Log[f] + 2*x*(e - c*Log[f]))/(2*Sqrt[-e + c*Log[f]])])/(4*Sqrt[-e + c*Log[f]]) + (E^(c - (d + b*Log[f])^2/(4*(e + c*Log[f])))*f^a*Sqrt[Pi]*Erfi[(d + b*Log[f] + 2*x*(e + c*Log[f]))/(2*Sqrt[e + c*Log[f]])])/(4*Sqrt[e + c*Log[f]])}
{f^(a + b*x + c*x^2)*Cosh[c + d*x + e*x^2], x, 7, -((E^(-c + (d - b*Log[f])^2/(4*(e - c*Log[f])))*f^a*Sqrt[Pi]*Erfi[(d - b*Log[f] + 2*x*(e - c*Log[f]))/(2*Sqrt[-e + c*Log[f]])])/(4*Sqrt[-e + c*Log[f]])) + (E^(c - (d + b*Log[f])^2/(4*(e + c*Log[f])))*f^a*Sqrt[Pi]*Erfi[(d + b*Log[f] + 2*x*(e + c*Log[f]))/(2*Sqrt[e + c*Log[f]])])/(4*Sqrt[e + c*Log[f]])}


(* Integrands of the form E^(a+b*x^n)*Trig[c+d*x]^m where m and n are integers *)
{E^(x^2)*Sinh[a + b*x], x, 5, (-(1/4))*E^(-a - b^2/4)*Sqrt[Pi]*Erfi[(1/2)*(-b + 2*x)] + (1/4)*E^(a - b^2/4)*Sqrt[Pi]*Erfi[(1/2)*(b + 2*x)]}
{E^(x^2)*Cosh[a + b*x], x, 5, (1/4)*E^(-a - b^2/4)*Sqrt[Pi]*Erfi[(1/2)*(-b + 2*x)] + (1/4)*E^(a - b^2/4)*Sqrt[Pi]*Erfi[(1/2)*(b + 2*x)]}


(* ::Subsection::Closed:: *)
(*Integrands involving exponentials of hyperbolic functions*)


(* Integrands of the form E^(n*Sinh[a+b*x])*Sinh[2*(a+b*x)] *)
{E^(n*Sinh[a+b*x])*Sinh[2*a+2*b*x], x, 4, -((2*E^(n*Sinh[a + b*x]))/(b*n^2)) + (2*E^(n*Sinh[a + b*x])*Sinh[a + b*x])/(b*n)}
{E^(n*Sinh[a+b*x])*Sinh[2*(a+b*x)], x, 5, -((2*E^(n*Sinh[a + b*x]))/(b*n^2)) + (2*E^(n*Sinh[a + b*x])*Sinh[a + b*x])/(b*n)}
{E^(n*Sinh[a/2+b/2*x])*Sinh[a+b*x], x, 4, -((4*E^(n*Sinh[a/2 + (b*x)/2]))/(b*n^2)) + (4*E^(n*Sinh[a/2 + (b*x)/2])*Sinh[a/2 + (b*x)/2])/(b*n)}
{E^(n*Sinh[(a+b*x)/2])*Sinh[a+b*x], x, 4, -((4*E^(n*Sinh[a/2 + (b*x)/2]))/(b*n^2)) + (4*E^(n*Sinh[a/2 + (b*x)/2])*Sinh[a/2 + (b*x)/2])/(b*n)}


(* Integrands of the form E^(n*Cosh[a+b*x])*Sinh[2*(a+b*x)] *)
{E^(n*Cosh[a+b*x])*Sinh[2*a+2*b*x], x, 4, -((2*E^(n*Cosh[a + b*x]))/(b*n^2)) + (2*E^(n*Cosh[a + b*x])*Cosh[a + b*x])/(b*n)}
{E^(n*Cosh[a+b*x])*Sinh[2*(a+b*x)], x, 4, -((2*E^(n*Cosh[a + b*x]))/(b*n^2)) + (2*E^(n*Cosh[a + b*x])*Cosh[a + b*x])/(b*n)}
{E^(n*Cosh[a/2+b/2*x])*Sinh[a+b*x], x, 4, -((4*E^(n*Cosh[a/2 + (b*x)/2]))/(b*n^2)) + (4*E^(n*Cosh[a/2 + (b*x)/2])*Cosh[a/2 + (b*x)/2])/(b*n)}
{E^(n*Cosh[(a+b*x)/2])*Sinh[a+b*x], x, 4, -((4*E^(n*Cosh[a/2 + (b*x)/2]))/(b*n^2)) + (4*E^(n*Cosh[a/2 + (b*x)/2])*Cosh[a/2 + (b*x)/2])/(b*n)}


(* Integrands of the form E^(n*Cosh[a+b*x])*Sinh[a+b*x] *)
{E^(n*Cosh[a+b*x])*Sinh[a+b*x], x, 3, E^(n*Cosh[a + b*x])/(b*n)}
{E^(n*Cosh[a*c+b*c*x])*Sinh[c*(a+b*x)], x, 4, E^(n*Cosh[a*c + b*c*x])/(b*c*n)}
{E^(n*Cosh[c*(a+b*x)])*Sinh[a*c+b*c*x], x, 3, E^(n*Cosh[a*c + b*c*x])/(b*c*n)}


(* Integrands of the form E^(n*Sinh[a+b*x])*Cosh[a+b*x] *)
{E^(n*Sinh[a+b*x])*Cosh[a+b*x], x, 2, E^(n*Sinh[a + b*x])/(b*n)}
{E^(n*Sinh[a*c+b*c*x])*Cosh[c*(a+b*x)], x, 2, E^(n*Sinh[c*(a + b*x)])/(b*c*n)}
{E^(n*Sinh[c*(a+b*x)])*Cosh[a*c+b*c*x], x, 2, E^(n*Sinh[a*c + b*c*x])/(b*c*n)}


(* Integrands of the form E^(n*Cosh[a+b*x])*Sinh[a+b*x] *)
{E^(n*Cosh[a+b*x])*Tanh[a+b*x], x, 3, ExpIntegralEi[n*Cosh[a + b*x]]/b}
{E^(n*Cosh[a*c+b*c*x])*Tanh[c*(a+b*x)], x, 2, ExpIntegralEi[n*Cosh[c*(a + b*x)]]/(b*c)}
{E^(n*Cosh[c*(a+b*x)])*Tanh[a*c+b*c*x], x, 3, ExpIntegralEi[n*Cosh[a*c + b*c*x]]/(b*c)}


(* Integrands of the form E^(n*Sinh[a+b*x])*Cosh[a+b*x] *)
{E^(n*Sinh[a+b*x])*Coth[a+b*x], x, 2, ExpIntegralEi[n*Sinh[a + b*x]]/b}
{E^(n*Sinh[a*c+b*c*x])*Coth[c*(a+b*x)], x, 2, ExpIntegralEi[n*Sinh[c*(a + b*x)]]/(b*c)}
{E^(n*Sinh[c*(a+b*x)])*Coth[a*c+b*c*x], x, 2, ExpIntegralEi[n*Sinh[a*c + b*c*x]]/(b*c)}


(* ::Subsection:: *)
(*Integrands involving hyperbolic functions of exponentials*)


(* ::Section::Closed:: *)
(*Problems from Calculus textbooks*)


(* ::Subsection::Closed:: *)
(*Anton Calculus, 4th Edition*)


{1/(E^x*Sqrt[1 - E^(-2*x)]), x, 2, -ArcSin[E^(-x)]}
{E^x/(4 + E^(2*x)), x, 2, ArcTan[E^x/2]/2}
{E^x/(1 - E^(2*x)), x, 2, ArcTanh[E^x]}
{E^x/(3 - 4*E^(2*x)), x, 2, ArcTanh[(2*E^x)/Sqrt[3]]/(2*Sqrt[3])}
{E^x*Sqrt[3 - 4*E^(2*x)], x, 3, (1/2)*E^x*Sqrt[3 - 4*E^(2*x)] + (3/4)*ArcSin[(2*E^x)/Sqrt[3]]}
{E^x^2*x^3, x, 2, -(E^x^2/2) + (1/2)*E^x^2*x^2}
{E^x*Sqrt[1 - E^(2*x)], x, 3, (1/2)*E^x*Sqrt[1 - E^(2*x)] + ArcSin[E^x]/2}
{E^x/Sqrt[1 + E^x + E^(2*x)], x, 2, ArcSinh[(1 + 2*E^x)/Sqrt[3]]}
{E^x/(-4 + E^(2*x)), x, 2, -ArcTanh[E^x/2]/2}


(* ::Subsection::Closed:: *)
(*Apostol Calculus, Volume 1, 2nd Edition, Section 6.17*)


{E^Sqrt[x], x, 3, -2*E^Sqrt[x] + 2*E^Sqrt[x]*Sqrt[x]}
{E^x/(1 + E^(2*x)), x, 2, ArcTan[E^x]}


(* ::Subsection::Closed:: *)
(*Ayres Calculus, 1964 edition*)


{E^(2 - x^2)*x, x, 1, -E^(2 - x^2)/2}
{E^x - x^E, x, 2, E^x - x^(1 + E)/(1 + E)}
{(-1 + E^(2*x))/(3 + E^(2*x)), x, 3, -(x/3) + (2/3)*Log[3 + E^(2*x)], (-(1/6))*Log[E^(2*x)] + (2/3)*Log[3 + E^(2*x)]}
{E^x/Sqrt[1 - E^(2*x)], x, 2, ArcSin[E^x]}
{E^(2*x)/(1 + E^(4*x)), x, 2, ArcTan[E^(2*x)]/2}
{1/(-3*E^x + E^(2*x)), x, 5, 1/(E^x*3) + (1/9)*Log[1 - 3/E^x]}
{(E^x*(-2 + E^x))/(1 + E^x), x, 3, E^x - 3*Log[1 + E^x]}


(* ::Subsection::Closed:: *)
(*Edwards and Penney Calculus*)


{E^x/(-1 + E^(2*x)), x, 2, -ArcTanh[E^x]}
{E^x/(1 + E^(2*x)), x, 2, ArcTan[E^x]}
{(E^(-x) + E^x)/(-E^(-x) + E^x), x, 1, Log[E^(-x) - E^x]}
{(-E^(-x) + E^x)/(E^(-x) + E^x), x, 4, (-(1/2))*Log[E^(2*x)] + Log[1 + E^(2*x)]}
{(E^(-2*x) + E^(2*x))/(-E^(-2*x) + E^(2*x)), x, 1, (1/2)*Log[E^(-2*x) - E^(2*x)]}
{E^x/Sqrt[1 + E^(2*x)], x, 2, ArcSinh[E^x]}
{E^Sqrt[4 + x]/Sqrt[4 + x], x, 1, 2*E^Sqrt[4 + x]}
{x/Sqrt[-1 + E^(2*x^2)], x, 2, ArcTan[Sqrt[-1 + E^(2*x^2)]]/2}
{E^x*Sqrt[9 + E^(2*x)], x, 3, (1/2)*E^x*Sqrt[9 + E^(2*x)] + (9/2)*ArcSinh[E^x/3]}
{E^x*Sqrt[1 + E^(2*x)], x, 3, (1/2)*E^x*Sqrt[1 + E^(2*x)] + ArcSinh[E^x]/2}
{(E^x^2*x)/(1 + E^(2*x^2)), x, 3, ArcTan[E^x^2]/2}
{(E^Sqrt[Sin[x]]*Cos[x])/Sqrt[Sin[x]], x, 2, 2*E^Sqrt[Sin[x]]}
{E^x^(3/2)*x^2, x, 3, (-(2/3))*E^x^(3/2) + (2/3)*E^x^(3/2)*x^(3/2)}


(* ::Subsection::Closed:: *)
(*Grossman Calculus*)


{E^x/Sqrt[-3 + E^(2*x)], x, 2, ArcTanh[E^x/Sqrt[-3 + E^(2*x)]]}
{E^x/(16 - E^(2*x)), x, 2, ArcTanh[E^x/4]/4}
{E^(5*x)/(1 + E^(10*x)), x, 2, ArcTan[E^(5*x)]/5}
{E^(4*x)/Sqrt[16 + E^(8*x)], x, 2, ArcSinh[E^(4*x)/4]/4}
{E^(4*x^3)*x^2*Cos[7*x^3], x, 2, (4/195)*E^(4*x^3)*Cos[7*x^3] + (7/195)*E^(4*x^3)*Sin[7*x^3]}


(* ::Subsection::Closed:: *)
(*Hughes, Hallet, Gleason, et al Calculus, 2nd Edition*)


{E^(1 + x^2)*x, x, 1, E^(1 + x^2)/2}
{E^(1 + x^3)*x^2, x, 1, E^(1 + x^3)/3}
{E^Sqrt[x]/Sqrt[x], x, 1, 2*E^Sqrt[x]}
{E^x^(1/3)/x^(2/3), x, 1, 3*E^x^(1/3)}
{E^(3*x)*(-8 + 2*x^3 + x^5), x, 8, -((76*E^(3*x))/27) + (4/9)*E^(3*x)*x - (2/3)*E^(3*x)*x^2 + (2/3)*E^(3*x)*x^3 - (1/729)*Gamma[6, -3*x]}
{(E^x + x)^2, x, 5, -2*E^x + E^(2*x)/2 + 2*E^x*x + x^3/3}


(* ::Subsection::Closed:: *)
(*Spivak Calculus*)


{(E^x + E^(2*x) + E^(3*x))/E^(4*x), x, 6, -(1/3)/E^(3*x) - 1/(E^(2*x)*2) - E^(-x)}
{E^x/(1 + 2*E^x + E^(2*x)), x, 2, -(1 + E^x)^(-1)}
{E^Sin[x]*Sec[x]^2*(x*Cos[x]^3 - Sin[x]), x, -7, E^Sin[x]*(-1 + x*Cos[x])*Sec[x]}


(* ::Subsection::Closed:: *)
(*Stewart Calculus*)


{Cos[3*x]/E^x, x, 1, ((-(1/10))*Cos[3*x])/E^x + ((3/10)*Sin[3*x])/E^x}
{E^(2*x)/(2 + 3*E^x + E^(2*x)), x, 4, -Log[1 + E^x] + 2*Log[2 + E^x]}
{E^(2*x)/(1 + E^x), x, 3, E^x - Log[1 + E^x]}
{E^(3*x)*Cos[5*x], x, 1, (3/34)*E^(3*x)*Cos[5*x] + (5/34)*E^(3*x)*Sin[5*x]}
{E^x*Sech[E^x], x, 2, ArcTan[Sinh[E^x]]}
{1/(E^x*(1 + 2*E^x)), x, 3, -E^(-x) + 2*Log[2 + E^(-x)]}
{E^x*Cos[4 + 3*x], x, 1, (1/10)*E^x*Cos[4 + 3*x] + (3/10)*E^x*Sin[4 + 3*x]}


(* ::Subsection::Closed:: *)
(*Thomas Calculus, 8th Edition*)


{E^x*Sec[1 - E^x]^3, x, 3, (-(1/2))*ArcTanh[Sin[1 - E^x]] - (1/2)*Sec[1 - E^x]*Tan[1 - E^x]}
{(E^(-x) + E^x)*x, x, 6, -E^(-x) - E^x - x/E^x + E^x*x}
{E^x/(2 + 3*E^x + E^(2*x)), x, 2, -2*ArcTanh[3 + 2*E^x]}
{E^(2*x)/(1 + E^x)^(1/3), x, 3, (-(3/2))*(1 + E^x)^(2/3) + (3/5)*(1 + E^x)^(5/3)}
{E^(2*x)/(1 + E^x)^(1/4), x, 3, (-(4/3))*(1 + E^x)^(3/4) + (4/7)*(1 + E^x)^(7/4)}
{(-E^x + 2*E^(2*x))/Sqrt[-1 - 6*E^x + 3*E^(2*x)], x, 3, (2/3)*Sqrt[-1 - 6*E^x + 3*E^(2*x)] - ArcTanh[(Sqrt[3]*(1 - E^x))/Sqrt[-1 - 6*E^x + 3*E^(2*x)]]/Sqrt[3]}


(* ::Section::Closed:: *)
(*Problems from integration competitions*)


(* ::Subsection::Closed:: *)
(*MIT Integration Competition*)


{E^x*(-5*x + x^2), x, 8, 7*E^x - 7*E^x*x + E^x*x^2, -3*E^x - 3*E^x*(5 - x) + E^x*(5 - x)^2}
{E^(3*x)*(-x + x^2), x, 9, (5*E^(3*x))/27 - (5/9)*E^(3*x)*x + (1/3)*E^(3*x)*x^2, -((10*E^(3*x))/27) + (2/9)*E^(3*x)*(1 - x) + (1/3)*E^(3*x)*(1 - x)^2 + (1/3)*E^(3*x)*x}


(* ::Subsection::Closed:: *)
(*University of Wisconsin Integration Competition*)


{E^(Cos[x]^2 + Sin[x]^2), x, 2, E*x}
{E^x^x*x^(2*x)*(1 + Log[x]), x, -3, E^x^x*(-1 + x^x)}
{(E^(5*x) + E^(7*x))/(E^(-x) + E^x), x, 2, E^(6*x)/6}
{x^(-2 - x^(-1))*(1 - Log[x]), x, -3, -x^(-x^(-1))}


(* ::Section::Closed:: *)
(*Miscellaneous problems*)


(*  Problems contributed by Michael Wester *)

(* => 1/[2 m sqrt (10)] log ([-5 + e^(m x) sqrt (10)]/[-5 - e^(m x) sqrt (10)])
      [Gradshteyn and Ryzhik 2.314] *)
{1/(-5/E^(m*x) + 2*E^(m*x)), x, 2, -(ArcTanh[Sqrt[2/5]*E^(m*x)]/(Sqrt[10]*m))}


{E^(6*x)*Sin[3*x], x, 1, (-(1/15))*E^(6*x)*Cos[3*x] + (2/15)*E^(6*x)*Sin[3*x]}
{E^(3*x)/(1 + E^(2*x)), x, 3, E^x - ArcTan[E^x]}
{E^(3*x)/(-1 + E^(2*x)), x, 3, E^x - ArcTanh[E^x]}
{E^(4 + Sin[x])*Cos[x], x, 2, E^(4 + Sin[x])}
{1/(E^x*Sqrt[1 + E^(2*x)]), x, 2, -(Sqrt[1 + E^(2*x)]/E^x)}


{E^x/(-1 - 8*E^x + E^(2*x)), x, 2, ArcTanh[(4 - E^x)/Sqrt[17]]/Sqrt[17]}
{E^(7*x)*x^3, x, 4, -((6*E^(7*x))/2401) + (6/343)*E^(7*x)*x - (3/49)*E^(7*x)*x^2 + (1/7)*E^(7*x)*x^3}
{E^(8 - 2*x)*x^3, x, 4, (-(3/8))*E^(8 - 2*x) - (3/4)*E^(8 - 2*x)*x - (3/4)*E^(8 - 2*x)*x^2 - (1/2)*E^(8 - 2*x)*x^3}
{E^x*Sqrt[9 - E^(2*x)], x, 3, (1/2)*E^x*Sqrt[9 - E^(2*x)] + (9/2)*ArcSin[E^x/3]}
{E^(6*x)*Sqrt[9 - E^(2*x)], x, 3, -27*(9 - E^(2*x))^(3/2) + (18/5)*(9 - E^(2*x))^(5/2) - (1/7)*(9 - E^(2*x))^(7/2)}
{E^(6*x)/(9 - E^x)^(5/2), x, 3, 39366/(9 - E^x)^(3/2) - 65610/Sqrt[9 - E^x] - 14580*Sqrt[9 - E^x] + 540*(9 - E^x)^(3/2) - 18*(9 - E^x)^(5/2) + (2/7)*(9 - E^x)^(7/2)}
{(2 - 7*E^x^4)^5*x^3, x, 8, -140*E^x^4 + 490*E^(2*x^4) - (3430*E^(3*x^4))/3 + (12005*E^(4*x^4))/8 - (16807*E^(5*x^4))/20 + 8*x^4}
{E^x^2*Sqrt[1 - E^(2*x^2)]*x, x, 4, (1/4)*E^x^2*Sqrt[1 - E^(2*x^2)] + (1/4)*ArcSin[E^x^2]}
{E^x^3*(1 - E^(4*x^3))^2*x^2, x, 6, E^x^3/3 - (2*E^(5*x^3))/15 + E^(9*x^3)/27}
{E^(E^x + x), x, 2, E^E^x}
{E^(E^E^x + E^x + x), x, 3, E^E^E^x}


{(E^(-x) + E^x)^2, x, 4, -(1/2)/E^(2*x) + E^(2*x)/2 + 2*x}
{1/(E^(-x) + E^x), x, 2, ArcTan[E^x]}
{1/(E^(-x) + E^x)^2, x, 2, -1/(2*(1 + E^(2*x)))}


{1/(-E^(-x) + E^x), x, 2, -ArcTanh[E^x]}
{1/(-E^(-x) + E^x)^2, x, 2, 1/(2*(1 - E^(2*x)))}


{E^x*(-E^(-x) + E^x)^2, x, 6, -E^(-x) - 2*E^x + E^(3*x)/3}
{E^x*(-E^(-x) + E^x)^3, x, 7, 1/(E^(2*x)*2) - (3*E^(2*x))/2 + E^(4*x)/4 + 3*x}


{(1 + 4^x)/(1 + 2^x), x, 4, x + 2^x/Log[2] - (2*Log[1 + 2^x])/Log[2]}
{(1 + 4^x)/(1 + 2^(-x)), x, 4, -(2^x/Log[2]) + 2^(-1 + 2*x)/Log[2] + (2*Log[1 + 2^x])/Log[2]}

{E^(a + x)^2/x^2 - (2*a*E^(a + x)^2)/x, x, 3, -(E^(a + x)^2/x) + Sqrt[Pi]*Erfi[a + x]}
{(x^4 + x^6 + x^8)/E^x^2, x, 15, ((-(147/16))*x)/E^x^2 - ((49/8)*x^3)/E^x^2 - ((9/4)*x^5)/E^x^2 - ((1/2)*x^7)/E^x^2 + (147/32)*Sqrt[Pi]*Erf[x]}

{(E^x*(-5 + x + x^2))/(-1 + x)^2, x, 6, E^x - (3*E^x)/(1 - x)}
{(E^x*x)/(1 + x)^2, x, 5, E^x/(1 + x)}

{1/(-E^x + E^(3*x)), x, 3, E^(-x) - ArcTanh[E^x]}
{(E^x^2*x^3)/(1 + x^2)^2, x, 6, E^x^2/(2*(1 + x^2))}
{E^(3*x)/Sqrt[25 + 16*E^(2*x)], x, 3, (1/32)*E^x*Sqrt[25 + 16*E^(2*x)] - (25/128)*ArcSinh[(4*E^x)/5]}

(* {E^(a + b*x + c*x^2)/(d + e*x)^2, x, 0} *)
{(1 + E^x)/Sqrt[E^x + x], x, 1, 2*Sqrt[E^x + x]}
{(1 + E^x)/(E^x + x), x, 1, Log[E^x + x]}
{E^x^2/x^2, x, 2, -(E^x^2/x) + Sqrt[Pi]*Erfi[x]}
{(E^x^2*(1 + 4*x^4))/x^2, x, 6, -(E^x^2/x) + 2*E^x^2*x}

{Sqrt[f^x]*(a + b*x)^2, x, 4, (16*b^2*Sqrt[f^x])/Log[f]^3 - (8*b*Sqrt[f^x]*(a + b*x))/Log[f]^2 + (2*Sqrt[f^x]*(a + b*x)^2)/Log[f]}

{3^(1 + x^2)*x, x, 1, 3^(1 + x^2)/(2*Log[3])}
{2^Sqrt[x]/Sqrt[x], x, 1, 2^(1 + Sqrt[x])/Log[2]}
{2^x^(-1)/x^2, x, 1, -(2^x^(-1)/Log[2])}
{2^(-x) + 2^x, x, 3, -(1/(2^x*Log[2])) + 2^x/Log[2]}
{(2 - 3*x + x^2)/E^(4*x), x, 8, -(11/32)/E^(4*x) + ((5/8)*x)/E^(4*x) - ((1/4)*x^2)/E^(4*x)}
{k^(x/2) + x^Sqrt[k], x, 2, x^(1 + Sqrt[k])/(1 + Sqrt[k]) + (2*k^(x/2))/Log[k]}
{10^Sqrt[x]/Sqrt[x], x, 1, (2^(1 + Sqrt[x])*5^Sqrt[x])/Log[10]}


(* Problems requiring simplification of irreducible integrands *)
{E^x/(E^x + x)^(1/2) + 1/Sqrt[E^x + x], x, 2, 2*Sqrt[E^x + x]}
{((1 + E^x)*x)/Sqrt[E^x + x] + 2*Sqrt[E^x + x], x, 6, 2*x*Sqrt[E^x + x]}
{x/Sqrt[E^x + x] + (E^x*x)/Sqrt[E^x + x] + 2*Sqrt[E^x + x], x, 4, 2*x*Sqrt[E^x + x]}
{((1 + E^x)*x)/Sqrt[E^x + x], x, 5, 2*x*Sqrt[E^x + x] - 2*Int[Sqrt[E^x + x], x]}
{x/Sqrt[E^x + x] + (E^x*x)/Sqrt[E^x + x], x, 4, 2*x*Sqrt[E^x + x] - 2*Int[Sqrt[E^x + x], x]}
{x*E^x/Sqrt[E^x + x], x, 2, 2*Sqrt[E^x + x] + 2*x*Sqrt[E^x + x] - Int[1/Sqrt[E^x + x], x] - 3*Int[Sqrt[E^x + x], x]}

{(x^2*(5*E^x + 3*x^2))/(5*Sqrt[5*E^x + x^3]) + (4/5)*x*Sqrt[5*E^x + x^3], x, 4, (2/5)*x^2*Sqrt[5*E^x + x^3]}
{x^2*E^x/Sqrt[5*E^x + x^3], x, 1, (2/5)*x^2*Sqrt[5*E^x + x^3] - (3/5)*Int[x^4/Sqrt[5*E^x + x^3], x] - (4/5)*Int[x*Sqrt[5*E^x + x^3], x]}

{-((1 + E^x)/(E^x + x)^(1/3)), x, 2, (-(3/2))*(E^x + x)^(2/3)}
{-(1/(E^x + x)^(1/3)) + x/(E^x + x)^(1/3) - (E^x + x)^(2/3), x, 2, (-(3/2))*(E^x + x)^(2/3)}
{x/(E^x + x)^(1/3), x, 1, (-(3/2))*(E^x + x)^(2/3) + Int[1/(E^x + x)^(1/3), x] + Int[(E^x + x)^(2/3), x]}

{(5*x + E^x*(3 + 2*x))/(E^x + x)^(1/3), x, 8, 3*x*(E^x + x)^(2/3)}
{(2*x)/(E^x + x)^(1/3) + (2*E^x*x)/(E^x + x)^(1/3) + 3*(E^x + x)^(2/3), x, 4, 3*x*(E^x + x)^(2/3)}


(* The substitution u=E^x will lead to a Log[E^x] term in antiderivative. *)
{E^x*(-E^(-x) + E^x)*(E^(-x) + E^x)^2, x, 5, 1/(E^(2*x)*2) + E^(2*x)/2 + E^(4*x)/4 - x}


(* Unwise expansion leads to infinite recursion *)
{x/(E^x + x), x, 2, Int[x/(E^x + x), x]}
{E^x/(E^x + x), x, 0, x - Int[x/(E^x + x), x]}
{E^x/(E^x + x^2), x, 0, x - Int[x^2/(E^x + x^2), x]}

(* {f[x]/(f[x] + x), x, 2, x - Int[x/(x + f[x]), x]}
{f[x]/(f[x] + x^2), x, 2, x - Int[x^2/(x^2 + f[x]), x]}
{f[x]/(f[x] + x)^2, x, 2, -Int[x/(x + f[x])^2, x] + Int[1/(x + f[x]), x]}
{f[x]/(f[x] + x^2)^2, x, 2, -Int[x^2/(x^2 + f[x])^2, x] + Int[1/(x^2 + f[x]), x]} *)
