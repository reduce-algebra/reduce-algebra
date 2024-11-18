(* ::Package:: *)

(* ::Section:: *)
(*Simp test problems*)


(* ::Subsection::Closed:: *)
(*Fractional powers of squareroot sums*)


(* {(2 + Sqrt[2])/(2*2^(3/4)), 0},
{(1 + 1/Sqrt[2])/2^(3/4), 0}, *)

{Sqrt[4 + 4*Sqrt[3]], 2*Sqrt[1 + Sqrt[3]]}
{Sqrt[-4 + 4*Sqrt[3]], 2*Sqrt[-1 + Sqrt[3]]}


{Sqrt[1 + 1/Sqrt[2]], 1/Sqrt[2 - Sqrt[2]]}
{Sqrt[(1/2)*(2 + Sqrt[2])], 1/Sqrt[2 - Sqrt[2]]}
{Sqrt[4 + 2*Sqrt[2]], 2/Sqrt[2 - Sqrt[2]]}

{Sqrt[1 - 1/Sqrt[2]], 1/Sqrt[2 + Sqrt[2]]}
{Sqrt[(1/2)*(2 - Sqrt[2])], 1/Sqrt[2 + Sqrt[2]]}
{Sqrt[4 - 2*Sqrt[2]], 2/Sqrt[2 + Sqrt[2]]}


{1/Sqrt[1 + 1/Sqrt[2]], Sqrt[2 - Sqrt[2]]}
{1/Sqrt[(1/2)*(2 + Sqrt[2])], Sqrt[2 - Sqrt[2]]}
{1/Sqrt[4 + 2*Sqrt[2]], Sqrt[2 - Sqrt[2]]/2}

{1/Sqrt[1 - 1/Sqrt[2]], Sqrt[2 + Sqrt[2]]}
{1/Sqrt[(1/2)*(2 - Sqrt[2])], Sqrt[2 + Sqrt[2]]}
{1/Sqrt[4 - 2*Sqrt[2]], Sqrt[2 + Sqrt[2]]/2}


{Sqrt[2 + 4/Sqrt[5]], 2/Sqrt[10 - 4*Sqrt[5]]}
{Sqrt[(2/5)*(5 + 2*Sqrt[5])], 2/Sqrt[10 - 4*Sqrt[5]]}
{Sqrt[50 + 20*Sqrt[5]], 10/Sqrt[10 - 4*Sqrt[5]]}

{Sqrt[2 - 4/Sqrt[5]], 2/Sqrt[10 + 4*Sqrt[5]]}
{Sqrt[(2/5)*(5 - 2*Sqrt[5])], 2/Sqrt[10 + 4*Sqrt[5]]}
{Sqrt[50 - 20*Sqrt[5]], 10/Sqrt[10 + 4*Sqrt[5]]}


{1/Sqrt[2 + 4/Sqrt[5]], Sqrt[10 - 4*Sqrt[5]]/2}
{1/Sqrt[(2/5)*(5 + 2*Sqrt[5])], Sqrt[10 - 4*Sqrt[5]]/2}
{1/Sqrt[50 + 20*Sqrt[5]], Sqrt[10 - 4*Sqrt[5]]/10}

{1/Sqrt[2 - 4/Sqrt[5]], Sqrt[10 + 4*Sqrt[5]]/2}
{1/Sqrt[(2/5)*(5 - 2*Sqrt[5])], Sqrt[10 + 4*Sqrt[5]]/2}
{1/Sqrt[50 - 20*Sqrt[5]], Sqrt[10 + 4*Sqrt[5]]/10}


{Sqrt[1 + 2/Sqrt[3]], 1/Sqrt[-3 + 2*Sqrt[3]]}
{Sqrt[-1 + 2/Sqrt[3]], 1/Sqrt[3 + 2*Sqrt[3]]}


{Sqrt[50 - 10*Sqrt[5]], 20/Sqrt[10 + 2*Sqrt[5]]}
{1/Sqrt[50 - 10*Sqrt[5]], (1/20)*Sqrt[10 + 2*Sqrt[5]]}


{Sqrt[1/2 + 1/(2*Sqrt[2])], Sqrt[2 + Sqrt[2]]/2}
{Sqrt[1/4 + 1/(4*Sqrt[2])], 1/(2*Sqrt[2 - Sqrt[2]])}
{Sqrt[1/8 + 1/(8*Sqrt[2])], Sqrt[2 + Sqrt[2]]/4}
{Sqrt[2/3 + 1/(6*Sqrt[3])], (1/6)*Sqrt[24 + 2*Sqrt[3]]}


{Sqrt[6 + 2*Sqrt[5]], 1 + Sqrt[5]}
{Sqrt[6 - 2*Sqrt[5]], -1 + Sqrt[5]}
{(6 + 2*Sqrt[5])^(1/6), (1 + Sqrt[5])^(1/3)}
{(6 - 2*Sqrt[5])^(1/6), (-1 + Sqrt[5])^(1/3)}


{1/Sqrt[1 + Sqrt[2]], Sqrt[-1 + Sqrt[2]]}
{1/Sqrt[-1 + Sqrt[2]], Sqrt[1 + Sqrt[2]]}


(* ::Subsection::Closed:: *)
(*Products involving squareroot sums*)


(* Content factor products but not sums *)
{(1/5)*(1 + Sqrt[5]), 1/5 + 1/Sqrt[5]}
{(1/5 + 1/Sqrt[5])*x, (1/5)*(1 + Sqrt[5])*x}
{(1/5)*(1 + Sqrt[5])*x, (1/5)*(1 + Sqrt[5])*x}

{2*Sqrt[5] + 2*(3 + 1/Sqrt[5]), 6 + 12/Sqrt[5]}
{2*(3 - Sqrt[5]) + 2*(1 + 3/Sqrt[5]), 8 - 4/Sqrt[5]}
{(1/4 + Sqrt[3]/4)*(1 + Sqrt[3]), 1 + Sqrt[3]/2}
{(-1 + Sqrt[5])/(1 + Sqrt[5]), 3/2 - Sqrt[5]/2}
{(Sqrt[2] - Sqrt[7])*(Sqrt[2] + Sqrt[7]), -5}
{(3 - Sqrt[3])*(2 + 2*Sqrt[3]), 4*Sqrt[3]}
{(3 - Sqrt[2])*(2 + 2*Sqrt[3]), 2*(3 - Sqrt[2])*(1 + Sqrt[3])}
{1/(Sqrt[2] + 3*Sqrt[7]), -(Sqrt[2]/61) + (3*Sqrt[7])/61}
{1/(2 + Sqrt[2]), 1 - 1/Sqrt[2]}
{2/(2 - Sqrt[2]), 2 + Sqrt[2]}
{(1 + Sqrt[2])^3, 7 + 5*Sqrt[2]}
{(1 + Sqrt[2])^(3/2), Sqrt[7 + 5*Sqrt[2]]}
{(1 + Sqrt[2])^(2/3), (3 + 2*Sqrt[2])^(1/3)}
{(3 + 1/Sqrt[2])^(3/2), (1/2)*Sqrt[126 + 55*Sqrt[2]]}
{(Sqrt[3] + Sqrt[2])^2, 5 + 2*Sqrt[6]}
{(Sqrt[2] + Sqrt[3])^3, 11*Sqrt[2] + 9*Sqrt[3]}
{(7 - 2*Sqrt[2])*(5 + 2*Sqrt[2]), 27 + 4*Sqrt[2]}
{(7 - 2*Sqrt[2])*(5 + 2*Sqrt[3]), (7 - 2*Sqrt[2])*(5 + 2*Sqrt[3])}
{(3 - 2*Sqrt[2])^5*(5 + Sqrt[2])^3, 155053 - 109639*Sqrt[2]}
{(3 - 2*Sqrt[2])^5*(5 + Sqrt[3])^3, 2*(3363 - 2378*Sqrt[2])*(85 + 39*Sqrt[3])}
{(1 + Sqrt[2])*Sqrt[-1 + Sqrt[2]], Sqrt[1 + Sqrt[2]]}
{(1 - Sqrt[2])*Sqrt[1 + Sqrt[2]], -Sqrt[-1 + Sqrt[2]]}
{(Sqrt[2] - 1)*Sqrt[1 + Sqrt[2]], Sqrt[-1 + Sqrt[2]]}
{(Sqrt[2] - 1)*Sqrt[2 + Sqrt[2]], Sqrt[2 - Sqrt[2]]}
{(Sqrt[2] - 1)*Sqrt[2/(2 - Sqrt[2])], Sqrt[2 - Sqrt[2]]}
{2^(1/2)*Sqrt[-1 + Sqrt[2]], Sqrt[-2 + 2*Sqrt[2]]}
{2^(1/4)*Sqrt[-1 + Sqrt[2]], Sqrt[2 - Sqrt[2]]}
{2^(1/6)*(-1 + Sqrt[2])^(1/3), (2 - Sqrt[2])^(1/3)}
{Sqrt[1 - 1/Sqrt[5]]*(1 + Sqrt[5]), 4/Sqrt[5 - Sqrt[5]]}
{(-1 + Sqrt[5])*Sqrt[(1/20)*(5 - Sqrt[5])], 2/Sqrt[10 + 4*Sqrt[5]]}
{(-1 + Sqrt[5])/Sqrt[5 + Sqrt[5]], 2/Sqrt[10 + 4*Sqrt[5]]}
{(-1 + Sqrt[5])/Sqrt[2*(5 + Sqrt[5])], 1/Sqrt[5 + 2*Sqrt[5]]}
(*Following deficiency due to Mathematica evaluator collecting simplified factors making the result not fully simplified: *)
{(5 - Sqrt[5])^(3/2)/Sqrt[5], 2*Sqrt[10 - 4*Sqrt[5]]}
{Sqrt[5 - Sqrt[5]]*(-1 + Sqrt[5]), 2*Sqrt[10 - 4*Sqrt[5]]}
{Sqrt[2 - 2/Sqrt[5]]*(-1 + Sqrt[5]), 4/Sqrt[5 + 2*Sqrt[5]]}
{(1 - Sqrt[2])^(1/3)*(2 + 3*Sqrt[2])^(1/2), (-1)^(1/3)*(-12 + 38*Sqrt[2])^(1/6)}
{(1/2^(3/4))*Sqrt[5 + 3/Sqrt[2]], (1/2)*Sqrt[3 + 5*Sqrt[2]]}
{1/(2^(3/4)*Sqrt[4 + Sqrt[2]]), 1/(2*Sqrt[1 + 2*Sqrt[2]])}


{(5 - Sqrt[5])/(5*Sqrt[10 - 2*Sqrt[5]]), (1/10)*Sqrt[10 - 2*Sqrt[5]]}
{(-5 + Sqrt[5])/(5*Sqrt[10 - 2*Sqrt[5]]), (-(1/10))*Sqrt[10 - 2*Sqrt[5]]}


{(1 - Sqrt[2])/(2*2^(1/4)), (1 - Sqrt[2])/(2*2^(1/4))}
{(2 - Sqrt[2])/(2^(3/4)*Sqrt[4 - 2*Sqrt[2]]), (1/2)*Sqrt[-1 + Sqrt[2]]}
{-(((2 - Sqrt[2])*Sqrt[2 + Sqrt[2]])/2^(3/4)), -Sqrt[-1 + Sqrt[2]]}
{-(((2 - Sqrt[2])*Sqrt[2 + Sqrt[2]])/(2*2^(3/4))), (-(1/2))*Sqrt[-1 + Sqrt[2]]}


{-(((1 - Sqrt[5])*x)/(2*Sqrt[5])), (1/10)*(5 - Sqrt[5])*x}


{14/Sqrt[10 - Sqrt[2]] - 6/Sqrt[2 + Sqrt[2]], 2*Sqrt[2 - Sqrt[2]]}


(* ::Subsection:: *)
(*Algebraic expressions*)


{(-a)*(1 - 1/b)*b, a*(1 - b)}


{1 - (1 + x)/(3 + x), 2/(3 + x)}
{Log[1 - (1 + x)/(3 + x)], Log[2/(3 + x)]}


{(2*c - 2*b)/(a*Sqrt[-b + c]), (2*Sqrt[-b + c])/a}
{((-e)^(3/2) + e - e^2)/Sqrt[-1 + Sqrt[-e] + e], (-e)*Sqrt[-1 + Sqrt[-e] + e]}
{(b*Sqrt[d]*(-e)^(3/2) + c*d*e - e^2)/Sqrt[(-c)*d + b*Sqrt[d]*Sqrt[-e] + e], (-e)*Sqrt[(-c)*d + b*Sqrt[d]*Sqrt[-e] + e]}
{(-e + Sqrt[-e]*e + e^2)/(a*Sqrt[-1 + Sqrt[-e] + e]), (e*Sqrt[-1 + Sqrt[-e] + e])/a}


{x - (b*x)/a + (b^2*x)/(a*(a + b)), (a*x)/(a + b)}
