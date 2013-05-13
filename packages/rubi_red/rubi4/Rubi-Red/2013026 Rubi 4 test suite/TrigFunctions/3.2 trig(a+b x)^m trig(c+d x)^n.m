(* ::Package:: *)

(* ::Title:: *)
(*Problems for integrands of the form trig(a+b x)^m trig(c+d x)^n*)


(* ::Section:: *)
(*Integrands of the form Sin[a+b x]^m Trig[c+d x]^n*)


(* ::Subsection::Closed:: *)
(*Integrands of the form Sin[a+b x]^m Sin[c+d x]^n*)


{Sin[a + b*x]*Sin[c + d*x]^n, x, 0, Int[Sin[a + b*x]*Sin[c + d*x]^n, x]}

{Sin[a + b*x]*Sin[c + d*x]^3, x, 6, -(Sin[a - 3*c + (b - 3*d)*x]/(8*(b - 3*d))) + (3*Sin[a - c + (b - d)*x])/(8*(b - d)) - (3*Sin[a + c + (b + d)*x])/(8*(b + d)) + Sin[a + 3*c + (b + 3*d)*x]/(8*(b + 3*d))}
{Sin[a + b*x]*Sin[c + d*x]^2, x, 5, -(Cos[a + b*x]/(2*b)) + Cos[a - 2*c + (b - 2*d)*x]/(4*(b - 2*d)) + Cos[a + 2*c + (b + 2*d)*x]/(4*(b + 2*d))}
{Sin[a + b*x]*Sin[c + d*x]^1, x, 4, Sin[a - c + (b - d)*x]/(2*(b - d)) - Sin[a + c + (b + d)*x]/(2*(b + d))}
{Sin[a + b*x]*Csc[c + b*x]^1, x, 3, x*Cos[a - c] + (Log[Sin[c + b*x]]*Sin[a - c])/b}
{Sin[a + b*x]*Csc[c + b*x]^2, x, 3, -((ArcTanh[Cos[c + b*x]]*Cos[a - c])/b) - (Csc[c + b*x]*Sin[a - c])/b}
{Sin[a + b*x]*Csc[c + b*x]^3, x, 3, -((Cos[a - c]*Cot[c + b*x])/b) - (Csc[c + b*x]^2*Sin[a - c])/(2*b)}
{Sin[a + b*x]*Csc[c + b*x]^4, x, 4, -((ArcTanh[Cos[c + b*x]]*Cos[a - c])/(2*b)) - (Cos[a - c]*Cot[c + b*x]*Csc[c + b*x])/(2*b) - (Csc[c + b*x]^3*Sin[a - c])/(3*b)}
{Sin[a + b*x]*Csc[c + b*x]^5, x, 4, -((Cos[a - c]*Cot[c + b*x])/b) - (Cos[a - c]*Cot[c + b*x]^3)/(3*b) - (Csc[c + b*x]^4*Sin[a - c])/(4*b)}
{Sin[a + b*x]*Csc[c + b*x]^6, x, 5, -((3*ArcTanh[Cos[c + b*x]]*Cos[a - c])/(8*b)) - (3*Cos[a - c]*Cot[c + b*x]*Csc[c + b*x])/(8*b) - (Cos[a - c]*Cot[c + b*x]*Csc[c + b*x]^3)/(4*b) - (Csc[c + b*x]^5*Sin[a - c])/(5*b)}


{Sin[a + b*x]^2*Sin[c + d*x]^n, x, 0, Int[Sin[a + b*x]^2*Sin[c + d*x]^n, x]}

{Sin[a + b*x]^2*Sin[c + d*x]^1, x, 5, -(Cos[2*a - c + (2*b - d)*x]/(4*(2*b - d))) - Cos[c + d*x]/(2*d) + Cos[2*a + c + (2*b + d)*x]/(4*(2*b + d))}
{Sin[a + b*x]^2*Sin[c + d*x]^2, x, 6, x/4 - Sin[2*a + 2*b*x]/(8*b) + Sin[2*(a - c) + 2*(b - d)*x]/(16*(b - d)) - Sin[2*c + 2*d*x]/(8*d) + Sin[2*(a + c) + 2*(b + d)*x]/(16*(b + d))}
{Sin[a + b*x]^2*Sin[c + d*x]^3, x, 8, Cos[2*a - 3*c + (2*b - 3*d)*x]/(16*(2*b - 3*d)) - (3*Cos[2*a - c + (2*b - d)*x])/(16*(2*b - d)) - (3*Cos[c + d*x])/(8*d) + Cos[3*c + 3*d*x]/(24*d) + (3*Cos[2*a + c + (2*b + d)*x])/(16*(2*b + d)) - Cos[2*a + 3*c + (2*b + 3*d)*x]/(16*(2*b + 3*d))}


{Sin[a + b*x]^3*Sin[c + d*x]^n, x, 0, Int[Sin[a + b*x]^3*Sin[c + d*x]^n, x]}

{Sin[a + b*x]^3*Sin[c + d*x]^1, x, 6, (3*Sin[a - c + (b - d)*x])/(8*(b - d)) - Sin[3*a - c + (3*b - d)*x]/(8*(3*b - d)) - (3*Sin[a + c + (b + d)*x])/(8*(b + d)) + Sin[3*a + c + (3*b + d)*x]/(8*(3*b + d))}
{Sin[a + b*x]^3*Sin[c + d*x]^2, x, 8, -((3*Cos[a + b*x])/(8*b)) + Cos[3*a + 3*b*x]/(24*b) + (3*Cos[a - 2*c + (b - 2*d)*x])/(16*(b - 2*d)) - Cos[3*a - 2*c + (3*b - 2*d)*x]/(16*(3*b - 2*d)) + (3*Cos[a + 2*c + (b + 2*d)*x])/(16*(b + 2*d)) - Cos[3*a + 2*c + (3*b + 2*d)*x]/(16*(3*b + 2*d))}
{Sin[a + b*x]^3*Sin[c + d*x]^3, x, 10, -((3*Sin[a - 3*c + (b - 3*d)*x])/(32*(b - 3*d))) + (9*Sin[a - c + (b - d)*x])/(32*(b - d)) + Sin[3*(a - c) + 3*(b - d)*x]/(96*(b - d)) - (3*Sin[3*a - c + (3*b - d)*x])/(32*(3*b - d)) - (9*Sin[a + c + (b + d)*x])/(32*(b + d)) - Sin[3*(a + c) + 3*(b + d)*x]/(96*(b + d)) + (3*Sin[3*a + c + (3*b + d)*x])/(32*(3*b + d)) + (3*Sin[a + 3*c + (b + 3*d)*x])/(32*(b + 3*d))}


(* ::Subsection::Closed:: *)
(*Integrands of the form Sin[a+b x]^m Cos[c+d x]^n*)


{Sin[a + b*x]*Cos[c + d*x]^n, x, 0, Int[Cos[c + d*x]^n*Sin[a + b*x], x]}

{Sin[a + b*x]*Cos[c + d*x]^3, x, 6, -(Cos[a - 3*c + (b - 3*d)*x]/(8*(b - 3*d))) - (3*Cos[a - c + (b - d)*x])/(8*(b - d)) - (3*Cos[a + c + (b + d)*x])/(8*(b + d)) - Cos[a + 3*c + (b + 3*d)*x]/(8*(b + 3*d))}
{Sin[a + b*x]*Cos[c + d*x]^2, x, 5, -(Cos[a + b*x]/(2*b)) - Cos[a - 2*c + (b - 2*d)*x]/(4*(b - 2*d)) - Cos[a + 2*c + (b + 2*d)*x]/(4*(b + 2*d))}
{Sin[a + b*x]*Cos[c + d*x]^1, x, 4, -(Cos[a - c + (b - d)*x]/(2*(b - d))) - Cos[a + c + (b + d)*x]/(2*(b + d))}
{Sin[a + b*x]*Sec[c + b*x]^1, x, 3, -((Cos[a - c]*Log[Cos[c + b*x]])/b) + x*Sin[a - c]}
{Sin[a + b*x]*Sec[c + b*x]^2, x, 3, (Cos[a - c]*Sec[c + b*x])/b + (ArcTanh[Sin[c + b*x]]*Sin[a - c])/b}
{Sin[a + b*x]*Sec[c + b*x]^3, x, 3, (Cos[a - c]*Sec[c + b*x]^2)/(2*b) + (Sin[a - c]*Tan[c + b*x])/b}
{Sin[a + b*x]*Sec[c + b*x]^4, x, 4, (Cos[a - c]*Sec[c + b*x]^3)/(3*b) + (ArcTanh[Sin[c + b*x]]*Sin[a - c])/(2*b) + (Sec[c + b*x]*Sin[a - c]*Tan[c + b*x])/(2*b)}
{Sin[a + b*x]*Sec[c + b*x]^5, x, 4, (Cos[a - c]*Sec[c + b*x]^4)/(4*b) + (Sin[a - c]*Tan[c + b*x])/b + (Sin[a - c]*Tan[c + b*x]^3)/(3*b)}
{Sin[a + b*x]*Sec[c + b*x]^6, x, 5, (Cos[a - c]*Sec[c + b*x]^5)/(5*b) + (3*ArcTanh[Sin[c + b*x]]*Sin[a - c])/(8*b) + (3*Sec[c + b*x]*Sin[a - c]*Tan[c + b*x])/(8*b) + (Sec[c + b*x]^3*Sin[a - c]*Tan[c + b*x])/(4*b)}


{Sin[a + b*x]^2*Cos[c + d*x]^n, x, 0, Int[Cos[c + d*x]^n*Sin[a + b*x]^2, x]}

{Sin[a + b*x]^2*Cos[c + d*x]^1, x, 5, -(Sin[2*a - c + (2*b - d)*x]/(4*(2*b - d))) + Sin[c + d*x]/(2*d) - Sin[2*a + c + (2*b + d)*x]/(4*(2*b + d))}
{Sin[a + b*x]^2*Cos[c + d*x]^2, x, 6, x/4 - Sin[2*a + 2*b*x]/(8*b) - Sin[2*(a - c) + 2*(b - d)*x]/(16*(b - d)) + Sin[2*c + 2*d*x]/(8*d) - Sin[2*(a + c) + 2*(b + d)*x]/(16*(b + d))}
{Sin[a + b*x]^2*Cos[c + d*x]^3, x, 8, -(Sin[2*a - 3*c + (2*b - 3*d)*x]/(16*(2*b - 3*d))) - (3*Sin[2*a - c + (2*b - d)*x])/(16*(2*b - d)) + (3*Sin[c + d*x])/(8*d) + Sin[3*c + 3*d*x]/(24*d) - (3*Sin[2*a + c + (2*b + d)*x])/(16*(2*b + d)) - Sin[2*a + 3*c + (2*b + 3*d)*x]/(16*(2*b + 3*d))}


{Sin[a + b*x]^3*Cos[c + d*x]^n, x, 0, Int[Cos[c + d*x]^n*Sin[a + b*x]^3, x]}

{Sin[a + b*x]^3*Cos[c + d*x]^1, x, 6, -((3*Cos[a - c + (b - d)*x])/(8*(b - d))) + Cos[3*a - c + (3*b - d)*x]/(8*(3*b - d)) - (3*Cos[a + c + (b + d)*x])/(8*(b + d)) + Cos[3*a + c + (3*b + d)*x]/(8*(3*b + d))}
{Sin[a + b*x]^3*Cos[c + d*x]^2, x, 8, -((3*Cos[a + b*x])/(8*b)) + Cos[3*a + 3*b*x]/(24*b) - (3*Cos[a - 2*c + (b - 2*d)*x])/(16*(b - 2*d)) + Cos[3*a - 2*c + (3*b - 2*d)*x]/(16*(3*b - 2*d)) - (3*Cos[a + 2*c + (b + 2*d)*x])/(16*(b + 2*d)) + Cos[3*a + 2*c + (3*b + 2*d)*x]/(16*(3*b + 2*d))}
{Sin[a + b*x]^3*Cos[c + d*x]^3, x, 10, -((3*Cos[a - 3*c + (b - 3*d)*x])/(32*(b - 3*d))) - (9*Cos[a - c + (b - d)*x])/(32*(b - d)) + Cos[3*(a - c) + 3*(b - d)*x]/(96*(b - d)) + (3*Cos[3*a - c + (3*b - d)*x])/(32*(3*b - d)) - (9*Cos[a + c + (b + d)*x])/(32*(b + d)) + Cos[3*(a + c) + 3*(b + d)*x]/(96*(b + d)) + (3*Cos[3*a + c + (3*b + d)*x])/(32*(3*b + d)) - (3*Cos[a + 3*c + (b + 3*d)*x])/(32*(b + 3*d))}


{Cos[a + b*x]/Sin[c + b*x]^1, x, 3, (Cos[a - c]*Log[Sin[c + b*x]])/b - x*Sin[a - c]}
{Cos[a + b*x]/Sin[c + b*x]^2, x, 3, -((Cos[a - c]*Csc[c + b*x])/b) + (ArcTanh[Cos[c + b*x]]*Sin[a - c])/b}
{Cos[a + b*x]/Sin[c + b*x]^3, x, 3, -((Cos[a - c]*Csc[c + b*x]^2)/(2*b)) + (Cot[c + b*x]*Sin[a - c])/b}


(* ::Subsection::Closed:: *)
(*Integrands of the form Sin[a+b x]^m Tan[c+d x]^n*)


(* ::Subsubsection::Closed:: *)
(*m>0*)


{Sin[a + b*x]*Tan[c + b*x]^3, x, 8, -((3*ArcTanh[Sin[c + b*x]]*Cos[a - c])/(2*b)) + (Sec[c + b*x]*Sin[a - c])/b + Sin[a + b*x]/b + (Cos[a - c]*Sec[c + b*x]*Tan[c + b*x])/(2*b)}
{Sin[a + b*x]*Tan[c + b*x]^2, x, 5, Cos[a + b*x]/b + (Cos[a - c]*Sec[c + b*x])/b + (ArcTanh[Sin[c + b*x]]*Sin[a - c])/b}
{Sin[a + b*x]*Tan[c + b*x]^1, x, 3, (ArcTanh[Sin[c + b*x]]*Cos[a - c])/b - Sin[a + b*x]/b}
{Sin[a + b*x]*Cot[c + b*x]^1, x, 3, -((ArcTanh[Cos[c + b*x]]*Sin[a - c])/b) + Sin[a + b*x]/b}
{Sin[a + b*x]*Cot[c + b*x]^2, x, 5, -((ArcTanh[Cos[c + b*x]]*Cos[a - c])/b) + Cos[a + b*x]/b - (Csc[c + b*x]*Sin[a - c])/b}
{Sin[a + b*x]*Cot[c + b*x]^3, x, 8, -((Cos[a - c]*Csc[c + b*x])/b) + (3*ArcTanh[Cos[c + b*x]]*Sin[a - c])/(2*b) - (Cot[c + b*x]*Csc[c + b*x]*Sin[a - c])/(2*b) - Sin[a + b*x]/b}


(* ::Subsubsection:: *)
(*m<0*)


(* ::Section:: *)
(*Integrands of the form Cos[a+b x]^m Trig[c+d x]^n*)


(* ::Subsection::Closed:: *)
(*Integrands of the form Cos[a+b x]^m Cos[c+d x]^n*)


(* ::Subsubsection::Closed:: *)
(*m>0*)


{Cos[a + b*x]*Cos[c + d*x]^3, x, 6, Sin[a - 3*c + (b - 3*d)*x]/(8*(b - 3*d)) + (3*Sin[a - c + (b - d)*x])/(8*(b - d)) + (3*Sin[a + c + (b + d)*x])/(8*(b + d)) + Sin[a + 3*c + (b + 3*d)*x]/(8*(b + 3*d))}
{Cos[a + b*x]*Cos[c + d*x]^2, x, 5, Sin[a + b*x]/(2*b) + Sin[a - 2*c + (b - 2*d)*x]/(4*(b - 2*d)) + Sin[a + 2*c + (b + 2*d)*x]/(4*(b + 2*d))}
{Cos[a + b*x]*Cos[c + d*x]^1, x, 4, Sin[a - c + (b - d)*x]/(2*(b - d)) + Sin[a + c + (b + d)*x]/(2*(b + d))}
{Cos[a + b*x]*Sec[c + b*x]^1, x, 3, x*Cos[a - c] + (Log[Cos[c + b*x]]*Sin[a - c])/b}
{Cos[a + b*x]*Sec[c + b*x]^2, x, 3, (ArcTanh[Sin[c + b*x]]*Cos[a - c])/b - (Sec[c + b*x]*Sin[a - c])/b}
{Cos[a + b*x]*Sec[c + b*x]^3, x, 3, -((Sec[c + b*x]^2*Sin[a - c])/(2*b)) + (Cos[a - c]*Tan[c + b*x])/b}


{Cos[a + b*x]^2*Cos[c + d*x]^3, x, 8, Sin[2*a - 3*c + (2*b - 3*d)*x]/(16*(2*b - 3*d)) + (3*Sin[2*a - c + (2*b - d)*x])/(16*(2*b - d)) + (3*Sin[c + d*x])/(8*d) + Sin[3*c + 3*d*x]/(24*d) + (3*Sin[2*a + c + (2*b + d)*x])/(16*(2*b + d)) + Sin[2*a + 3*c + (2*b + 3*d)*x]/(16*(2*b + 3*d))}
{Cos[a + b*x]^2*Cos[c + d*x]^2, x, 6, x/4 + Sin[2*a + 2*b*x]/(8*b) + Sin[2*(a - c) + 2*(b - d)*x]/(16*(b - d)) + Sin[2*c + 2*d*x]/(8*d) + Sin[2*(a + c) + 2*(b + d)*x]/(16*(b + d))}


{Cos[a + b*x]^3*Cos[c + d*x]^3, x, 10, (3*Sin[a - 3*c + (b - 3*d)*x])/(32*(b - 3*d)) + (9*Sin[a - c + (b - d)*x])/(32*(b - d)) + Sin[3*(a - c) + 3*(b - d)*x]/(96*(b - d)) + (3*Sin[3*a - c + (3*b - d)*x])/(32*(3*b - d)) + (9*Sin[a + c + (b + d)*x])/(32*(b + d)) + Sin[3*(a + c) + 3*(b + d)*x]/(96*(b + d)) + (3*Sin[3*a + c + (3*b + d)*x])/(32*(3*b + d)) + (3*Sin[a + 3*c + (b + 3*d)*x])/(32*(b + 3*d))}


(* ::Subsubsection:: *)
(*m<0*)


(* ::Subsection::Closed:: *)
(*Integrands of the form Cos[a+b x]^m Tan[c+d x]^n*)


(* ::Subsubsection::Closed:: *)
(*m>0*)


{Cos[a + b*x]*Tan[c + b*x]^3, x, 8, Cos[a + b*x]/b + (Cos[a - c]*Sec[c + b*x])/b + (3*ArcTanh[Sin[c + b*x]]*Sin[a - c])/(2*b) - (Sec[c + b*x]*Sin[a - c]*Tan[c + b*x])/(2*b)}
{Cos[a + b*x]*Tan[c + b*x]^2, x, 5, (ArcTanh[Sin[c + b*x]]*Cos[a - c])/b - (Sec[c + b*x]*Sin[a - c])/b - Sin[a + b*x]/b}
{Cos[a + b*x]*Tan[c + b*x]^1, x, 3, -(Cos[a + b*x]/b) - (ArcTanh[Sin[c + b*x]]*Sin[a - c])/b}
{Cos[a + b*x]*Cot[c + b*x]^1, x, 3, -((ArcTanh[Cos[c + b*x]]*Cos[a - c])/b) + Cos[a + b*x]/b}
{Cos[a + b*x]*Cot[c + b*x]^2, x, 5, -((Cos[a - c]*Csc[c + b*x])/b) + (ArcTanh[Cos[c + b*x]]*Sin[a - c])/b - Sin[a + b*x]/b}
{Cos[a + b*x]*Cot[c + b*x]^3, x, 8, (3*ArcTanh[Cos[c + b*x]]*Cos[a - c])/(2*b) - Cos[a + b*x]/b - (Cos[a - c]*Cot[c + b*x]*Csc[c + b*x])/(2*b) + (Csc[c + b*x]*Sin[a - c])/b}


(* ::Subsubsection:: *)
(*m<0*)


(* ::Section:: *)
(*Integrands of the form Tan[a+b x]^m Trig[c+d x]^n*)


(* ::Subsection::Closed:: *)
(*Integrands of the form Tan[a+b x]^m Tan[c+d x]^n*)


(* ::Subsubsection:: *)
(*m>0*)


(* ::Subsubsection:: *)
(*m<0*)
