(* ::Package:: *)

(* ::Title:: *)
(*Piecewise Continuous Function Integration Problems*)


{If[x < 0, -x, x], x, 3, Apply[If, {x < 0, -(1/2)*x^2, (1/2)*x^2}]}


{Piecewise[{{-x, x < 0}, {x, x > 0}}], x, 4, Piecewise[{{-x^2/2, x < 0}, {x^2/2, x > 0}}]}
