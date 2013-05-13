(* ::Package:: *)

(* ::Title::Bold::Closed:: *)
(*\[Integral]1/(a+b x^n) \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Reference: G&R 2.124.1a, CRC 60, A&S 3.3.21*)


(* ::Subsubsection:: *)
(*Derivation: Primitive rule*)


(* ::Subsubsection:: *)
(*Basis: Derivative[1][ArcTan][z]=1/(1+z^2)*)


(* ::Subsubsection:: *)
(*Rule: If  a/b>0, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]1/(a+b x^2) \[DifferentialD]x  \[LongRightArrow]  (Sqrt[(a/b)]/a)ArcTan[x/Sqrt[a/b]]*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[1/(a_+b_.*x_^2),x_Symbol] :=
  Rt[a/b,2]/a*ArcTan[x/Rt[a/b,2]] /;
FreeQ[{a,b},x] && PosQ[a/b]


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Reference: G&R 2.124.1b', CRC 61b, A&S 3.3.23*)


(* ::Subsubsection:: *)
(*Derivation: Primitive rule*)


(* ::Subsubsection:: *)
(*Basis: Derivative[1][ArcTanh][z]=1/(1-z^2)*)


(* ::Subsubsection:: *)
(*Rule: If  \[Not](a/b>0), then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]1/(a+b x^2) \[DifferentialD]x  \[LongRightArrow]  (Sqrt[-(a/b)]/a)ArcTanh[x/Sqrt[-(a/b)]]*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[1/(a_+b_.*x_^2),x_Symbol] :=
  Rt[-a/b,2]/a*ArcTanh[x/Rt[-a/b,2]] /;
FreeQ[{a,b},x] && NegQ[a/b]


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Reference: G&R 2.126.1.2, CRC 74*)


(* ::Subsubsection:: *)
(*Derivation: Algebraic expansion*)


(* ::Subsubsection:: *)
(*Basis: If  r/s=(a/b)^(1/3), then 1/(a+b z^3)=r/(3 a (r+s z))+(r (2 r-s z))/(3 a(r^2-r s z+s^2 z^2))*)


(* ::Subsubsection:: *)
(*Rule: If  a/b>0, let r/s=(a/b)^(1/3), then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]1/(a+b x^3) \[DifferentialD]x  \[LongRightArrow]  (r/(3 a))\[Integral]1/(r+s x) \[DifferentialD]x+r/(3 a) \[Integral](2 r-s x)/(r^2-r s x+s^2 x^2) \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[1/(a_+b_.*x_^3),x_Symbol] :=
  Module[{r=Numerator[Rt[a/b,3]], s=Denominator[Rt[a/b,3]]},
  Dist[r/(3*a),Int[1/(r+s*x),x]] +
  Dist[r/(3*a),Int[(2*r-s*x)/(r^2-r*s*x+s^2*x^2),x]]] /;
FreeQ[{a,b},x] && PosQ[a/b]


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Derivation: Algebraic expansion*)


(* ::Subsubsection:: *)
(*Basis: If  r/s=(-(a/b))^(1/3), then 1/(a+b z^3)=r/(3 a (r-s z))+(r (2 r+s z))/(3 a(r^2+r s z+s^2 z^2))*)


(* ::Subsubsection:: *)
(*Rule: If  \[Not](a/b>0), let r/s=(-(a/b))^(1/3), then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]1/(a+b x^3) \[DifferentialD]x  \[LongRightArrow]  (r/(3 a))\[Integral]1/(r-s x) \[DifferentialD]x+r/(3 a) \[Integral](2 r+s x)/(r^2+r s x+s^2 x^2) \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[1/(a_+b_.*x_^3),x_Symbol] :=
  Module[{r=Numerator[Rt[-a/b,3]], s=Denominator[Rt[-a/b,3]]},
  Dist[r/(3*a),Int[1/(r-s*x),x]] +
  Dist[r/(3*a),Int[(2*r+s*x)/(r^2+r*s*x+s^2*x^2),x]]] /;
FreeQ[{a,b},x] && NegQ[a/b]


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Reference: G&R 2.132.1.1', CRC 77'*)


(* ::Subsubsection:: *)
(*Derivation: Algebraic expansion*)


(* ::Subsubsection:: *)
(*Basis: If  r/s=(a/b)^(1/4), then 1/(a+b z^4)=(r (Sqrt[2] r-s z))/(2Sqrt[2]a(r^2-Sqrt[2] r s z+s^2 z^2))+(r (Sqrt[2] r+s z))/(2Sqrt[2]a(r^2+Sqrt[2] r s z+s^2 z^2))*)


(* ::Subsubsection:: *)
(*Rule: If  n/4\[Element]\[DoubleStruckCapitalZ] \[And] n>2 \[And] a/b>0, let r/s=(a/b)^(1/4), then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]1/(a+b x^n) \[DifferentialD]x  \[LongRightArrow]  (r/(2 Sqrt[2] a))\[Integral](Sqrt[2] r-s x^(n/4))/(r^2-Sqrt[2] r s x^(n/4)+s^2 x^(n/2)) \[DifferentialD]x+r/(2 Sqrt[2] a) \[Integral](Sqrt[2] r+s x^(n/4))/(r^2+Sqrt[2] r s x^(n/4)+s^2 x^(n/2)) \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[1/(a_+b_.*x_^n_),x_Symbol] :=
  Module[{r=Numerator[Rt[a/b,4]], s=Denominator[Rt[a/b,4]]},
  Dist[r/(2*Sqrt[2]*a),Int[(Sqrt[2]*r-s*x^(n/4))/(r^2-Sqrt[2]*r*s*x^(n/4)+s^2*x^(n/2)),x]] +
  Dist[r/(2*Sqrt[2]*a),Int[(Sqrt[2]*r+s*x^(n/4))/(r^2+Sqrt[2]*r*s*x^(n/4)+s^2*x^(n/2)),x]]] /;
FreeQ[{a,b},x] && IntegerQ[n/4] && n>2 && PositiveQ[a/b]


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Reference: G&R 2.132.1.2', CRC 78'*)


(* ::Subsubsection:: *)
(*Derivation: Algebraic expansion*)


(* ::Subsubsection:: *)
(*Basis: If  r/s=(-(a/b))^(1/2), then 1/(a+b z^2)=r/(2a(r-s z))+r/(2a(r+s z))*)


(* ::Subsubsection:: *)
(*Rule: If  n/4\[Element]\[DoubleStruckCapitalZ] \[And] n>2 \[And] \[Not](a/b>0), let r/s=(-(a/b))^(1/2), then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]1/(a+b x^n) \[DifferentialD]x  \[LongRightArrow]  (r/(2 a))\[Integral]1/(r-s x^(n/2)) \[DifferentialD]x+r/(2 a) \[Integral]1/(r+s x^(n/2)) \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[1/(a_+b_.*x_^n_),x_Symbol] :=
  Module[{r=Numerator[Rt[-a/b,2]], s=Denominator[Rt[-a/b,2]]},
  Dist[r/(2*a),Int[1/(r-s*x^(n/2)),x]] +
  Dist[r/(2*a),Int[1/(r+s*x^(n/2)),x]]] /;
FreeQ[{a,b},x] && IntegerQ[n/4] && n>2 && Not[PositiveQ[a/b]]


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Derivation: Algebraic expansion*)


(* ::Subsubsection:: *)
(*Basis: If (n-2)/4\[Element]\[DoubleStruckCapitalZ] and r/s=(a/b)^(2/n), then 1/(a+b z^n)=(2r)/(a n(r+s z^2))+(4r)/(a n) \!\( *)
(*\*UnderoverscriptBox[\(\[Sum]\), \(k = 1\), *)
(*FractionBox[\(n - 2\), \(4\)]]*)
(*\*FractionBox[\(r - s\ Cos[*)
(*\*FractionBox[\(2\ \((2\ k - 1)\)\ \[Pi]\), \(n\)]]\ *)
(*\*SuperscriptBox[\(z\), \(2\)]\), \( *)
(*\*SuperscriptBox[\(r\), \(2\)] - 2\ r\ s\ Cos[*)
(*\*FractionBox[\(2\ \((2\ k - 1)\)\ \[Pi]\), \(n\)]]\ *)
(*\*SuperscriptBox[\(z\), \(2\)] + *)
(*\*SuperscriptBox[\(s\), \(2\)]\ *)
(*\*SuperscriptBox[\(z\), \(4\)]\)]\)*)


(* ::Subsubsection:: *)
(*Rule: If (n-2)/4\[Element]\[DoubleStruckCapitalZ] \[And] n>2 \[And] a/b>0, let r/s=(a/b)^(2/n), then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]1/(a+b x^n) \[DifferentialD]x  \[LongRightArrow]  ((2 r)/(a n))\[Integral]1/(r+s x^2) \[DifferentialD]x+(4 r)/(a n) \[Integral]\!\( *)
(*\*UnderoverscriptBox[\(\[Sum]\), \(k = 1\), *)
(*FractionBox[\(n - 2\), \(4\)]]\( *)
(*\*FractionBox[\(r - s\ Cos[*)
(*\*FractionBox[\(2\ \((2\ k - 1)\)\ \[Pi]\), \(n\)]]\ *)
(*\*SuperscriptBox[\(x\), \(2\)]\), \( *)
(*\*SuperscriptBox[\(r\), \(2\)] - 2\ r\ s\ Cos[*)
(*\*FractionBox[\(2\ \((2\ k - 1)\)\ \[Pi]\), \(n\)]]\ *)
(*\*SuperscriptBox[\(x\), \(2\)] + *)
(*\*SuperscriptBox[\(s\), \(2\)]\ *)
(*\*SuperscriptBox[\(x\), \(4\)]\)] \[DifferentialD]x\)\)*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[1/(a_+b_.*x_^n_),x_Symbol] :=
  Module[{r=Numerator[Rt[a/b,n/2]], s=Denominator[Rt[a/b,n/2]]},
  Dist[2*r/(a*n),Int[1/(r+s*x^2),x]] +
  Dist[4*r/(a*n),Int[Sum[(r-s*Cos[2*(2*k-1)*Pi/n]*x^2)/(r^2-2*r*s*Cos[2*(2*k-1)*Pi/n]*x^2+s^2*x^4),
    {k,1,(n-2)/4}],x]]] /;
FreeQ[{a,b},x] && IntegerQ[(n-2)/4] && n>2 && PosQ[a/b]


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Derivation: Algebraic expansion*)


(* ::Subsubsection:: *)
(*Basis: If (n-2)/4\[Element]\[DoubleStruckCapitalZ] and r/s=(-(a/b))^(2/n), then 1/(a+b z^n)=(2r)/(a n(r-s z^2))+(4r)/(a n) \!\( *)
(*\*UnderoverscriptBox[\(\[Sum]\), \(k = 1\), *)
(*FractionBox[\(n - 2\), \(4\)]]*)
(*\*FractionBox[\(r - s\ Cos[*)
(*\*FractionBox[\(4\ k\ \[Pi]\), \(n\)]]\ *)
(*\*SuperscriptBox[\(z\), \(2\)]\), \( *)
(*\*SuperscriptBox[\(r\), \(2\)] - 2\ r\ s\ Cos[*)
(*\*FractionBox[\(4\ k\ \[Pi]\), \(n\)]]\ *)
(*\*SuperscriptBox[\(z\), \(2\)] + *)
(*\*SuperscriptBox[\(s\), \(2\)]\ *)
(*\*SuperscriptBox[\(z\), \(4\)]\)]\)*)


(* ::Subsubsection:: *)
(*Rule: If (n-2)/4\[Element]\[DoubleStruckCapitalZ] \[And] n>2 \[And] \[Not](a/b>0), let r/s=(-(a/b))^(2/n), then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]1/(a+b x^n) \[DifferentialD]x  \[LongRightArrow]  ((2 r)/(a n))\[Integral]1/(r-s x^2) \[DifferentialD]x+(4 r)/(a n) \[Integral]\!\( *)
(*\*UnderoverscriptBox[\(\[Sum]\), \(k = 1\), *)
(*FractionBox[\(n - 2\), \(4\)]]\( *)
(*\*FractionBox[\(r - s\ Cos[*)
(*\*FractionBox[\(4\ k\ \[Pi]\), \(n\)]]\ *)
(*\*SuperscriptBox[\(x\), \(2\)]\), \( *)
(*\*SuperscriptBox[\(r\), \(2\)] - 2\ r\ s\ Cos[*)
(*\*FractionBox[\(4\ k\ \[Pi]\), \(n\)]]\ *)
(*\*SuperscriptBox[\(x\), \(2\)] + *)
(*\*SuperscriptBox[\(s\), \(2\)]\ *)
(*\*SuperscriptBox[\(x\), \(4\)]\)] \[DifferentialD]x\)\)*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[1/(a_+b_.*x_^n_),x_Symbol] :=
  Module[{r=Numerator[Rt[-a/b,n/2]], s=Denominator[Rt[-a/b,n/2]]},
  Dist[2*r/(a*n),Int[1/(r-s*x^2),x]] +
  Dist[4*r/(a*n),Int[Sum[(r-s*Cos[4*k*Pi/n]*x^2)/(r^2-2*r*s*Cos[4*k*Pi/n]*x^2+s^2*x^4),
    {k,1,(n-2)/4}],x]]] /;
FreeQ[{a,b},x] && IntegerQ[(n-2)/4] && n>2 && NegQ[a/b]


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Derivation: Algebraic expansion*)


(* ::Subsubsection:: *)
(*Basis: If (n-1)/2\[Element]\[DoubleStruckCapitalZ] and r/s=(a/b)^(1/n), then 1/(a+b z^n)=r/(a n(r+s z))+(2r)/(a n) \!\( *)
(*\*UnderoverscriptBox[\(\[Sum]\), \(k = 1\), *)
(*FractionBox[\(n - 1\), \(2\)]]*)
(*\*FractionBox[\(r - s\ Cos[*)
(*\*FractionBox[\(\((2\ k - 1)\)\ \[Pi]\), \(n\)]]\ z\), \( *)
(*\*SuperscriptBox[\(r\), \(2\)] - 2\ r\ s\ Cos[*)
(*\*FractionBox[\(\((2\ k - 1)\)\ \[Pi]\), \(n\)]]\ z + *)
(*\*SuperscriptBox[\(s\), \(2\)]\ *)
(*\*SuperscriptBox[\(z\), \(2\)]\)]\)*)


(* ::Subsubsection:: *)
(*Rule: If (n-1)/2\[Element]\[DoubleStruckCapitalZ] \[And] n>1 \[And] a/b>0, let r/s=(a/b)^(1/n), then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]1/(a+b x^n) \[DifferentialD]x  \[LongRightArrow]  \[Integral](r/(a n (r+s x))+\!\( *)
(*\*UnderoverscriptBox[\(\[Sum]\), \(k = 1\), *)
(*FractionBox[\(n - 1\), \(2\)]]*)
(*\*FractionBox[\(2\ r\ \((r - s\ Cos[*)
(*\*FractionBox[\(\((2\ k - 1)\)\ \[Pi]\), \(n\)]]\ x)\)\), \(a\ n\ \(( *)
(*\*SuperscriptBox[\(r\), \(2\)] - 2\ r\ s\ Cos[*)
(*\*FractionBox[\(\((2\ k - 1)\)\ \[Pi]\), \(n\)]]\ x + *)
(*\*SuperscriptBox[\(s\), \(2\)]\ *)
(*\*SuperscriptBox[\(x\), \(2\)])\)\)]\))\[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[1/(a_+b_.*x_^n_),x_Symbol] :=
  Module[{r=Numerator[Rt[a/b,n]], s=Denominator[Rt[a/b,n]]},
  Int[r/(a*n*(r+s*x)) +
	Sum[2*r*(r-s*Cos[(2*k-1)*Pi/n]*x)/(a*n*(r^2-2*r*s*Cos[(2*k-1)*Pi/n]*x+s^2*x^2)),
      {k,1,(n-1)/2}],x]] /;
FreeQ[{a,b},x] && OddQ[n] && n>1 && PosQ[a/b]


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Derivation: Algebraic expansion*)


(* ::Subsubsection:: *)
(*Basis: If (n-1)/2\[Element]\[DoubleStruckCapitalZ] and r/s=(-(a/b))^(1/n), then 1/(a+b z^n)=r/(a n(r-s z))+(2r)/(a n) \!\( *)
(*\*UnderoverscriptBox[\(\[Sum]\), \(k = 1\), *)
(*FractionBox[\(n - 1\), \(2\)]]*)
(*\*FractionBox[\(r + s\ Cos[*)
(*\*FractionBox[\(\((2\ k - 1)\)\ \[Pi]\), \(n\)]]\ z\), \( *)
(*\*SuperscriptBox[\(r\), \(2\)] + 2\ r\ s\ Cos[*)
(*\*FractionBox[\(\((2\ k - 1)\)\ \[Pi]\), \(n\)]]\ z + *)
(*\*SuperscriptBox[\(s\), \(2\)]\ *)
(*\*SuperscriptBox[\(z\), \(2\)]\)]\)*)


(* ::Subsubsection:: *)
(*Rule: If (n-1)/2\[Element]\[DoubleStruckCapitalZ] \[And] n>1 \[And] \[Not](a/b>0), let r/s=(-(a/b))^(1/n), then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]1/(a+b x^n) \[DifferentialD]x  \[LongRightArrow]  \[Integral](r/(a n (r-s x))+\!\( *)
(*\*UnderoverscriptBox[\(\[Sum]\), \(k = 1\), *)
(*FractionBox[\(n - 1\), \(2\)]]*)
(*\*FractionBox[\(2\ r\ \((r + s\ Cos[*)
(*\*FractionBox[\(\((2\ k - 1)\)\ \[Pi]\), \(n\)]]\ x)\)\), \(a\ n\ \(( *)
(*\*SuperscriptBox[\(r\), \(2\)] + 2\ r\ s\ Cos[*)
(*\*FractionBox[\(\((2\ k - 1)\)\ \[Pi]\), \(n\)]]\ x + *)
(*\*SuperscriptBox[\(s\), \(2\)]\ *)
(*\*SuperscriptBox[\(x\), \(2\)])\)\)]\))\[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[1/(a_+b_.*x_^n_),x_Symbol] :=
  Module[{r=Numerator[Rt[-a/b,n]], s=Denominator[Rt[-a/b,n]]},
  Int[r/(a*n*(r-s*x)) +
	Sum[2*r*(r+s*Cos[(2*k-1)*Pi/n]*x)/(a*n*(r^2+2*r*s*Cos[(2*k-1)*Pi/n]*x+s^2*x^2)),
      {k,1,(n-1)/2}],x]] /;
FreeQ[{a,b},x] && OddQ[n] && n>1 && NegQ[a/b]


(* ::PageBreak:: *)
(**)


(* ::Title::Bold::Closed:: *)
(*\[Integral]x^m/(a+b x^n) \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Reference: G&R 2.126.2, CRC 75*)


(* ::Subsubsection:: *)
(*Derivation: Algebraic expansion*)


(* ::Subsubsection:: *)
(*Basis: If  r/s=(a/b)^(1/3), then z/(a+b z^3)=-(r^2/(3 a s(r+s z)))+(r^2 (r+s z))/(3 a s(r^2-r s z+s^2 z^2))*)


(* ::Subsubsection:: *)
(*Rule: If  a/b>0, let r/s=(a/b)^(1/3), then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]x/(a+b x^3) \[DifferentialD]x  \[LongRightArrow]  -(r^2/(3 a s))\[Integral]1/(r+s x) \[DifferentialD]x+r^2/(3 a s) \[Integral](r+s x)/(r^2-r s x+s^2 x^2) \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[x_/(a_+b_.*x_^3),x_Symbol] :=
  Module[{r=Numerator[Rt[a/b,3]], s=Denominator[Rt[a/b,3]]},
  Dist[-r^2/(3*a*s),Int[1/(r+s*x),x]] +
  Dist[r^2/(3*a*s),Int[(r+s*x)/(r^2-r*s*x+s^2*x^2),x]]] /;
FreeQ[{a,b},x] && PosQ[a/b]


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Derivation: Algebraic expansion*)


(* ::Subsubsection:: *)
(*Basis: If  r/s=(-(a/b))^(1/3), then 1/(a+b z^3)=r^2/(3 a s(r-s z))-(r^2 (r-s z))/(3 a s(r^2+r s z+s^2 z^2))*)


(* ::Subsubsection:: *)
(*Rule: If  \[Not](a/b>0), let r/s=(-(a/b))^(1/3), then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]x/(a+b x^3) \[DifferentialD]x  \[LongRightArrow]  (r^2/(3 a s))\[Integral]1/(r-s x) \[DifferentialD]x-r^2/(3 a s) \[Integral](r-s x)/(r^2+r s x+s^2 x^2) \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[x_/(a_+b_.*x_^3),x_Symbol] :=
  Module[{r=Numerator[Rt[-a/b,3]], s=Denominator[Rt[-a/b,3]]},
  Dist[r^2/(3*a*s),Int[1/(r-s*x),x]] -
  Dist[r^2/(3*a*s),Int[(r-s*x)/(r^2+r*s*x+s^2*x^2),x]]] /;
FreeQ[{a,b},x] && NegQ[a/b]


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Derivation: Integration by substitution*)


(* ::Subsubsection:: *)
(*Rule: If  m,n\[Element]\[DoubleStruckCapitalZ] \[And] 0<m+1<n, let g=GCD[m+1,n], if  g>1, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]x^m/(a+b x^n) \[DifferentialD]x  \[LongRightArrow]  (1/g)Subst[\[Integral]x^((m+1)/g-1)/(a+b x^(n/g)) \[DifferentialD]x,x,x^g]*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[x_^m_./(a_+b_.*x_^n_),x_Symbol] :=
  Module[{g=GCD[m+1,n]},
  Dist[1/g,Subst[Int[x^((m+1)/g-1)/(a+b*x^(n/g)),x],x,x^g]] /;
 g>1] /;
FreeQ[{a,b},x] && IntegersQ[m,n] && 0<m+1<n


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Reference: G&R 2.132.3.1', CRC 81'*)


(* ::Subsubsection:: *)
(*Derivation: Algebraic expansion*)


(* ::Subsubsection:: *)
(*Basis: If  r/s=(a/b)^(1/4), then z^2/(a+b z^4)=(s^3 z)/(2Sqrt[2]b r(r^2-Sqrt[2] r s z+s^2 z^2))-(s^3 z)/(2Sqrt[2]b r(r^2+Sqrt[2] r s z+s^2 z^2))*)


(* ::Subsubsection:: *)
(*Rule: If  m/2\[Element]\[DoubleStruckCapitalZ] \[And] m>0 \[And] a/b>0, let r/s=(a/b)^(1/4), then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]x^m/(a+b x^(2m)) \[DifferentialD]x  \[LongRightArrow]  (s^3/(2 Sqrt[2] b r))\[Integral]x^(m/2)/(r^2-Sqrt[2] r s x^(m/2)+s^2 x^m) \[DifferentialD]x-s^3/(2 Sqrt[2] b r) \[Integral]x^(m/2)/(r^2+Sqrt[2] r s x^(m/2)+s^2 x^m) \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[x_^m_/(a_+b_.*x_^n_),x_Symbol] :=
  Module[{r=Numerator[Rt[a/b,4]], s=Denominator[Rt[a/b,4]]},
  Dist[s^3/(2*Sqrt[2]*b*r),Int[x^(m/2)/(r^2-Sqrt[2]*r*s*x^(m/2)+s^2*x^m),x]] -
  Dist[s^3/(2*Sqrt[2]*b*r),Int[x^(m/2)/(r^2+Sqrt[2]*r*s*x^(m/2)+s^2*x^m),x]]] /;
FreeQ[{a,b},x] && IntegerQ[m/2] && m>0 && ZeroQ[n-2*m] && PositiveQ[a/b]


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Reference: G&R 2.132.3.2', CRC 82'*)


(* ::Subsubsection:: *)
(*Derivation: Algebraic expansion*)


(* ::Subsubsection:: *)
(*Basis: If  r/s=(-(a/b))^(1/2), then z/(a+b z^2)=s/(2b(r+s z))-s/(2b(r-s z))*)


(* ::Subsubsection:: *)
(*Rule: If  m/2\[Element]\[DoubleStruckCapitalZ] \[And] m>0 \[And] \[Not](a/b>0), let r/s=(-(a/b))^(1/2), then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]x^m/(a+b x^(2m)) \[DifferentialD]x  \[LongRightArrow]  (s/(2 b))\[Integral]1/(r+s x^m) \[DifferentialD]x-s/(2 b) \[Integral]1/(r-s x^m) \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[x_^m_/(a_+b_.*x_^n_),x_Symbol] :=
  Module[{r=Numerator[Rt[-a/b,2]], s=Denominator[Rt[-a/b,2]]},
  Dist[s/(2*b),Int[1/(r+s*x^m),x]] -
  Dist[s/(2*b),Int[1/(r-s*x^m),x]]] /;
FreeQ[{a,b},x] && EvenQ[m] && m>0 && ZeroQ[n-2*m] && Not[PositiveQ[a/b]]


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Derivation: Algebraic expansion*)


(* ::Subsubsection:: *)
(*Basis: If (n-2)/4,m/2\[Element]\[DoubleStruckCapitalZ], 0<=m<n and r/s=(a/b)^(2/n), then z^m/(a+b z^n)=-((2 (-r)^(m/2+1))/(a n s^(m/2) (r+s z^2)))+(4 r^(m/2+1))/(a n s^(m/2)) \!\( *)
(*\*UnderoverscriptBox[\(\[Sum]\), \(k = 1\), *)
(*FractionBox[\(n - 2\), \(4\)]]*)
(*\*FractionBox[\(r\ Cos[*)
(*\*FractionBox[\(\((2\ k - 1)\)\ m\ \[Pi]\), \(n\)]] - s\ Cos[*)
(*\*FractionBox[\(\((2\ k - 1)\)\ \((m + 2)\)\ \[Pi]\), \(n\)]]\ *)
(*\*SuperscriptBox[\(z\), \(2\)]\), \( *)
(*\*SuperscriptBox[\(r\), \(2\)] - 2\ r\ s\ Cos[*)
(*\*FractionBox[\(2\ \((2\ k - 1)\)\ \[Pi]\), \(n\)]]\ *)
(*\*SuperscriptBox[\(z\), \(2\)] + *)
(*\*SuperscriptBox[\(s\), \(2\)]\ *)
(*\*SuperscriptBox[\(z\), \(4\)]\)]\)*)


(* ::Subsubsection:: *)
(*Rule: If (n-2)/4,m/2\[Element]\[DoubleStruckCapitalZ] \[And] 0<m<n \[And] CoprimeQ[m+1,n] \[And] a/b>0, let r/s=(a/b)^(2/n), then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]x^m/(a+b x^n) \[DifferentialD]x  \[LongRightArrow]  -((2 (-r)^(m/2+1))/(a n s^(m/2)))\[Integral]1/(r+s x^2) \[DifferentialD]x+(4 r^(m/2+1))/(a n s^(m/2)) \[Integral]\!\( *)
(*\*UnderoverscriptBox[\(\[Sum]\), \(k = 1\), *)
(*FractionBox[\(n - 2\), \(4\)]]\( *)
(*\*FractionBox[\(r\ Cos[*)
(*\*FractionBox[\(\((2\ k - 1)\)\ m\ \[Pi]\), \(n\)]] - s\ Cos[*)
(*\*FractionBox[\(\((2\ k - 1)\)\ \((m + 2)\)\ \[Pi]\), \(n\)]]\ *)
(*\*SuperscriptBox[\(x\), \(2\)]\), \( *)
(*\*SuperscriptBox[\(r\), \(2\)] - 2\ r\ s\ Cos[*)
(*\*FractionBox[\(2\ \((2\ k - 1)\)\ \[Pi]\), \(n\)]]\ *)
(*\*SuperscriptBox[\(x\), \(2\)] + *)
(*\*SuperscriptBox[\(s\), \(2\)]\ *)
(*\*SuperscriptBox[\(x\), \(4\)]\)] \[DifferentialD]x\)\)*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[x_^m_./(a_+b_.*x_^n_),x_Symbol] :=
  Module[{r=Numerator[Rt[a/b,n/2]], s=Denominator[Rt[a/b,n/2]]},
  Dist[-2*(-r)^(m/2+1)/(a*n*s^(m/2)),Int[1/(r+s*x^2),x]] +
  Dist[4*r^(m/2+1)/(a*n*s^(m/2)),
	Int[Sum[(r*Cos[(2*k-1)*m*Pi/n]-s*Cos[(2*k-1)*(m+2)*Pi/n]*x^2)/
      (r^2-2*r*s*Cos[2*(2*k-1)*Pi/n]*x^2+s^2*x^4),{k,1,(n-2)/4}],x]]] /;
 FreeQ[{a,b},x] && IntegersQ[(n-2)/4,m/2] && 0<m<n && CoprimeQ[m+1,n] && PosQ[a/b]


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Derivation: Algebraic expansion*)


(* ::Subsubsection:: *)
(*Basis: If (n-2)/4,m/2\[Element]\[DoubleStruckCapitalZ], 0<=m<n and r/s=(-(a/b))^(2/n), then z^m/(a+b z^n)=(2 r^(m/2+1))/(a n s^(m/2) (r-s z^2))+(4 r^(m/2+1))/(a n s^(m/2)) \!\( *)
(*\*UnderoverscriptBox[\(\[Sum]\), \(k = 1\), *)
(*FractionBox[\(n - 2\), \(4\)]]*)
(*\*FractionBox[\(r\ Cos[*)
(*\*FractionBox[\(2\ k\ m\ \[Pi]\), \(n\)]] - s\ Cos[*)
(*\*FractionBox[\(2\ k\ \((m + 2)\)\ \[Pi]\), \(n\)]]\ *)
(*\*SuperscriptBox[\(z\), \(2\)]\), \( *)
(*\*SuperscriptBox[\(r\), \(2\)] - 2\ r\ s\ Cos[*)
(*\*FractionBox[\(4\ k\ \[Pi]\), \(n\)]]\ *)
(*\*SuperscriptBox[\(z\), \(2\)] + *)
(*\*SuperscriptBox[\(s\), \(2\)]\ *)
(*\*SuperscriptBox[\(z\), \(4\)]\)]\)*)


(* ::Subsubsection:: *)
(*Rule: If (n-2)/4,m/2\[Element]\[DoubleStruckCapitalZ] \[And] 0<m<n \[And] CoprimeQ[m+1,n] \[And] \[Not](a/b>0), let r/s=(-(a/b))^(2/n), then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]x^m/(a+b x^n) \[DifferentialD]x  \[LongRightArrow]  ((2 r^(m/2+1))/(a n s^(m/2)))\[Integral]1/(r-s x^2) \[DifferentialD]x+(4 r^(m/2+1))/(a n s^(m/2)) \[Integral]\!\( *)
(*\*UnderoverscriptBox[\(\[Sum]\), \(k = 1\), *)
(*FractionBox[\(n - 2\), \(4\)]]\( *)
(*\*FractionBox[\(r\ Cos[*)
(*\*FractionBox[\(2\ k\ m\ \[Pi]\), \(n\)]] - s\ Cos[*)
(*\*FractionBox[\(2\ k\ \((m + 2)\)\ \[Pi]\), \(n\)]]\ *)
(*\*SuperscriptBox[\(x\), \(2\)]\), \( *)
(*\*SuperscriptBox[\(r\), \(2\)] - 2\ r\ s\ Cos[*)
(*\*FractionBox[\(4\ k\ \[Pi]\), \(n\)]]\ *)
(*\*SuperscriptBox[\(x\), \(2\)] + *)
(*\*SuperscriptBox[\(s\), \(2\)]\ *)
(*\*SuperscriptBox[\(x\), \(4\)]\)] \[DifferentialD]x\)\)*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[x_^m_./(a_+b_.*x_^n_),x_Symbol] :=
  Module[{r=Numerator[Rt[-a/b,n/2]], s=Denominator[Rt[-a/b,n/2]]},
  Dist[2*r^(m/2+1)/(a*n*s^(m/2)),Int[1/(r-s*x^2),x]] +
  Dist[4*r^(m/2+1)/(a*n*s^(m/2)),
	Int[Sum[(r*Cos[2*k*m*Pi/n]-s*Cos[2*k*(m+2)*Pi/n]*x^2)/
      (r^2-2*r*s*Cos[4*k*Pi/n]*x^2+s^2*x^4),{k,1,(n-2)/4}],x]]] /;
 FreeQ[{a,b},x] && IntegersQ[(n-2)/4,m/2] && 0<m<n && CoprimeQ[m+1,n] && NegQ[a/b]


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Derivation: Algebraic expansion*)


(* ::Subsubsection:: *)
(*Basis: If (n-1)/2,m\[Element]\[DoubleStruckCapitalZ], 0<=m<n and r/s=(a/b)^(1/n), then z^m/(a+b z^n)=-((-r)^(m+1)/(a n s^m (r+s z)))+\!\( *)
(*\*UnderoverscriptBox[\(\[Sum]\), \(k = 1\), *)
(*FractionBox[\(n - 1\), \(2\)]]*)
(*\*FractionBox[\(2\ *)
(*\*SuperscriptBox[\(r\), \(m + 1\)]\ \((r\ Cos[*)
(*\*FractionBox[\(\((2\ k - 1)\)\ m\ \[Pi]\), \(n\)]] - s\ Cos[*)
(*\*FractionBox[\(\((2\ k - 1)\)\ \((m + 1)\)\ \[Pi]\), \(n\)]]\ z)\)\), \(a\ n\ *)
(*\*SuperscriptBox[\(s\), \(m\)]\ \(( *)
(*\*SuperscriptBox[\(r\), \(2\)] - 2\ r\ s\ Cos[*)
(*\*FractionBox[\(\((2\ k - 1)\)\ \[Pi]\), \(n\)]]\ z + *)
(*\*SuperscriptBox[\(s\), \(2\)]\ *)
(*\*SuperscriptBox[\(z\), \(2\)])\)\)]\)*)


(* ::Subsubsection:: *)
(*Rule: If (n-1)/2,m\[Element]\[DoubleStruckCapitalZ] \[And] 0<m<n \[And] CoprimeQ[m+1,n] \[And] a/b>0, let r/s=(a/b)^(1/n), then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]x^m/(a+b x^n) \[DifferentialD]x  \[LongRightArrow]  \[Integral]-((-r)^(m+1)/(a n s^m (r+s x)))+\!\( *)
(*\*UnderoverscriptBox[\(\[Sum]\), \(k = 1\), *)
(*FractionBox[\(n - 1\), \(2\)]]\( *)
(*\*FractionBox[\(2\ *)
(*\*SuperscriptBox[\(r\), \(m + 1\)]\ \((r\ Cos[*)
(*\*FractionBox[\(\((2\ k - 1)\)\ m\ \[Pi]\), \(n\)]] - s\ Cos[*)
(*\*FractionBox[\(\((2\ k - 1)\)\ \((m + 1)\)\ \[Pi]\), \(n\)]]\ x)\)\), \(a\ n\ *)
(*\*SuperscriptBox[\(s\), \(m\)]\ \(( *)
(*\*SuperscriptBox[\(r\), \(2\)] - 2\ r\ s\ Cos[*)
(*\*FractionBox[\(\((2\ k - 1)\)\ \[Pi]\), \(n\)]]\ x + *)
(*\*SuperscriptBox[\(s\), \(2\)]\ *)
(*\*SuperscriptBox[\(x\), \(2\)])\)\)] \[DifferentialD]x\)\)*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[x_^m_./(a_+b_.*x_^n_),x_Symbol] :=
  Module[{r=Numerator[Rt[a/b,n]], s=Denominator[Rt[a/b,n]]},
  Int[-(-r)^(m+1)/(a*n*s^m*(r+s*x)) +
    Sum[2*r^(m+1)*(r*Cos[(2*k-1)*m*Pi/n]-s*Cos[(2*k-1)*(m+1)*Pi/n]*x)/
      (a*n*s^m*(r^2-2*r*s*Cos[(2*k-1)*Pi/n]*x+s^2*x^2)),{k,1,(n-1)/2}],x]] /;
FreeQ[{a,b},x] && IntegersQ[(n-1)/2,m] && 0<m<n && CoprimeQ[m+1,n] && PosQ[a/b]


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Derivation: Algebraic expansion*)


(* ::Subsubsection:: *)
(*Basis: If (n-1)/2,m\[Element]\[DoubleStruckCapitalZ], 0<=m<n and r/s=(-(a/b))^(1/n), then z^m/(a+b z^n)=r^(m+1)/(a n s^m (r-s z))-\!\( *)
(*\*UnderoverscriptBox[\(\[Sum]\), \(k = 1\), *)
(*FractionBox[\(n - 1\), \(2\)]]*)
(*\*FractionBox[\(2\ *)
(*\*SuperscriptBox[\((\(-r\))\), \(m + 1\)]\ \((r\ Cos[*)
(*\*FractionBox[\(\((2\ k - 1)\)\ m\ \[Pi]\), \(n\)]] + s\ Cos[*)
(*\*FractionBox[\(\((2\ k - 1)\)\ \((m + 1)\)\ \[Pi]\), \(n\)]]\ z)\)\), \(a\ n\ *)
(*\*SuperscriptBox[\(s\), \(m\)]\ \(( *)
(*\*SuperscriptBox[\(r\), \(2\)] + 2\ r\ s\ Cos[*)
(*\*FractionBox[\(\((2\ k - 1)\)\ \[Pi]\), \(n\)]]\ z + *)
(*\*SuperscriptBox[\(s\), \(2\)]\ *)
(*\*SuperscriptBox[\(z\), \(2\)])\)\)]\)*)


(* ::Subsubsection:: *)
(*Rule: If (n-1)/2,m\[Element]\[DoubleStruckCapitalZ] \[And] 0<m<n \[And] CoprimeQ[m+1,n] \[And] \[Not](a/b>0), let r/s=(-(a/b))^(1/n), then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]x^m/(a+b x^n) \[DifferentialD]x  \[LongRightArrow]  \[Integral]r^(m+1)/(a n s^m (r-s x))-\!\( *)
(*\*UnderoverscriptBox[\(\[Sum]\), \(k = 1\), *)
(*FractionBox[\(n - 1\), \(2\)]]\( *)
(*\*FractionBox[\(2\ *)
(*\*SuperscriptBox[\((\(-r\))\), \(m + 1\)]\ \((r\ Cos[*)
(*\*FractionBox[\(\((2\ k - 1)\)\ m\ \[Pi]\), \(n\)]] + s\ Cos[*)
(*\*FractionBox[\(\((2\ k - 1)\)\ \((m + 1)\)\ \[Pi]\), \(n\)]]\ x)\)\), \(a\ n\ *)
(*\*SuperscriptBox[\(s\), \(m\)]\ \(( *)
(*\*SuperscriptBox[\(r\), \(2\)] + 2\ r\ s\ Cos[*)
(*\*FractionBox[\(\((2\ k - 1)\)\ \[Pi]\), \(n\)]]\ x + *)
(*\*SuperscriptBox[\(s\), \(2\)]\ *)
(*\*SuperscriptBox[\(x\), \(2\)])\)\)] \[DifferentialD]x\)\)*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[x_^m_./(a_+b_.*x_^n_),x_Symbol] :=
  Module[{r=Numerator[Rt[-a/b,n]], s=Denominator[Rt[-a/b,n]]},
  Int[r^(m+1)/(a*n*s^m*(r-s*x)) -
    Sum[2*(-r)^(m+1)*(r*Cos[(2*k-1)*m*Pi/n]+s*Cos[(2*k-1)*(m+1)*Pi/n]*x)/
      (a*n*s^m*(r^2+2*r*s*Cos[(2*k-1)*Pi/n]*x+s^2*x^2)),{k,1,(n-1)/2}],x]] /;
FreeQ[{a,b},x] && IntegersQ[(n-1)/2,m] && 0<m<n && CoprimeQ[m+1,n] && NegQ[a/b]


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Note: An integration rule for the following algebraic expansion is not needed since m+1 and n are not coprime when m is odd and n even:*)


(* ::Subsubsection:: *)
(*Basis: If n/2,(m+1)/2\[Element]\[DoubleStruckCapitalZ], 0<=m<n and r/s=(-(a/b))^(1/n), then z^m/(a+b z^n)=(2r^(m+1) z)/(a n s^(m-1) (r^2-s^2 z^2))+\!\( *)
(*\*UnderoverscriptBox[\(\[Sum]\), \(k = 1\), \( *)
(*\*FractionBox[\(n\), \(2\)] - 1\)]*)
(*\*FractionBox[\(2\ *)
(*\*SuperscriptBox[\(r\), \(m + 1\)]\ \((r\ Cos[*)
(*\*FractionBox[\(2\ k\ m\ \[Pi]\), \(n\)]] - s\ Cos[*)
(*\*FractionBox[\(2\ k\ \((m + 1)\)\ \[Pi]\), \(n\)]]\ z)\)\), \(a\ n\ *)
(*\*SuperscriptBox[\(s\), \(m\)]\ \(( *)
(*\*SuperscriptBox[\(r\), \(2\)] - 2\ r\ s\ Cos[*)
(*\*FractionBox[\(2\ k\ \[Pi]\), \(n\)]]\ z + *)
(*\*SuperscriptBox[\(s\), \(2\)]\ *)
(*\*SuperscriptBox[\(z\), \(2\)])\)\)]\)*)


(* ::PageBreak:: *)
(**)


(* ::Title::Bold::Closed:: *)
(*\[Integral](c+d x^m)/(a+b x^(2m)) \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Derivation: Algebraic expansion*)


(* ::Subsubsection:: *)
(*Basis: If  r/s=(a/b)^(1/4), then (c+d z^m)/(a+b z^(2m))=(r (Sqrt[2] c r s+(c s^2-d r^2) z^(m/2)))/(2 Sqrt[2] a s (r^2+Sqrt[2] r s z^(m/2)+s^2 z^m))+(r (Sqrt[2] c r s-(c s^2-d r^2) z^(m/2)))/(2 Sqrt[2] a s (r^2-Sqrt[2] r s z^(m/2)+s^2 z^m))*)


(* ::Subsubsection:: *)
(*Rule: If  m/2\[Element]\[DoubleStruckCapitalZ] \[And] m>0 \[And] a/b>0, let r/s=(a/b)^(1/4), then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral](c+d x^m)/(a+b x^(2m)) \[DifferentialD]x  \[LongRightArrow]  (r/(2 Sqrt[2] a s))\[Integral](Sqrt[2] c r s+(c s^2-d r^2) x^(m/2))/(r^2+Sqrt[2] r s x^(m/2)+s^2 x^m) \[DifferentialD]x+r/(2 Sqrt[2] a s) \[Integral](Sqrt[2] c r s-(c s^2-d r^2) x^(m/2))/(r^2-Sqrt[2] r s x^(m/2)+s^2 x^m) \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[(c_.+d_.*x_^m_)/(a_+b_.*x_^n_),x_Symbol] :=
  Module[{r=Numerator[Rt[a/b,4]], s=Denominator[Rt[a/b,4]]},
  Dist[r/(2*Sqrt[2]*a*s),
    Int[(Sqrt[2]*c*r*s+(c*s^2-d*r^2)*x^(m/2))/(r^2+Sqrt[2]*r*s*x^(m/2)+s^2*x^m),x]] +
  Dist[r/(2*Sqrt[2]*a*s),
    Int[(Sqrt[2]*c*r*s-(c*s^2-d*r^2)*x^(m/2))/(r^2-Sqrt[2]*r*s*x^(m/2)+s^2*x^m),x]]] /;
FreeQ[{a,b,c,d},x] && IntegerQ[m/2] && m>0 && ZeroQ[n-2*m] && PosQ[a/b]


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Derivation: Algebraic expansion*)


(* ::Subsubsection:: *)
(*Basis: If  r/s=(-(a/b))^(1/2), then (c+d z^m)/(a+b z^(2m))=(c s+d r)/(2 (a s+b r z^m))+(c s-d r)/(2 (a s-b r z^m))*)


(* ::Subsubsection:: *)
(*Rule: If  m/2\[Element]\[DoubleStruckCapitalZ] \[And] m>0 \[And] \[Not](a/b>0) \[And] b c^2+a d^2!=0, let r/s=(-(a/b))^(1/2), then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral](c+d x^m)/(a+b x^(2m)) \[DifferentialD]x  \[LongRightArrow]  ((c s+d r)/2) \[Integral]1/(a s+b r x^m) \[DifferentialD]x+(c s-d r)/2 \[Integral]1/(a s-b r x^m) \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[(c_.+d_.*x_^m_)/(a_+b_.*x_^n_),x_Symbol] :=
  Module[{r=Numerator[Rt[-a/b,2]], s=Denominator[Rt[-a/b,2]]},
  Dist[(c*s+d*r)/2, Int[1/(a*s+b*r*x^m),x]] +
  Dist[(c*s-d*r)/2, Int[1/(a*s-b*r*x^m),x]]] /;
FreeQ[{a,b,c,d},x] && IntegerQ[m/2] && m>0 && ZeroQ[n-2*m] && NegQ[a/b] && NonzeroQ[b*c^2+a*d^2]


(* ::PageBreak:: *)
(**)


(* ::Title::Bold::Closed:: *)
(*\[Integral](a+b x^n)^p \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Reference: G&R 2.110.2, CRC 88d special case when n (p+1)+1=0*)


(* ::Subsubsection:: *)
(*Rule: If  n(p+1)+1=0, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral](a+b x^n)^p \[DifferentialD]x  \[LongRightArrow]  ((x (a+b x^n)^(p+1))/a)*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[(a_+b_.*x_^n_)^p_,x_Symbol] :=
  x*(a+b*x^n)^(p+1)/a /;
FreeQ[{a,b,n,p},x] && ZeroQ[n*(p+1)+1]


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Reference: G&R 2.110.2, CRC 88d*)


(* ::Subsubsection:: *)
(*Derivation: Integration by parts*)


(* ::Subsubsection:: *)
(*Basis: (a+b x^n)^p=x^(n (p+1)+1) (a+b x^n)^p/x^(n (p+1)+1)*)


(* ::Subsubsection:: *)
(*Basis: \[Integral](a+b x^n)^p/x^(n (p+1)+1) \[DifferentialD]x=-((a+b x^n)^(p+1)/(x^(n (p+1)) a n (p+1)))*)


(* ::Subsubsection:: *)
(*Note: Requirement that n>1 ensures new term is a proper fraction.*)


(* ::Subsubsection:: *)
(*Rule: If  n,p\[Element]\[DoubleStruckCapitalZ] \[And] n>1 \[And] p<-1, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral](a+b x^n)^p \[DifferentialD]x  \[LongRightArrow]  -((x (a+b x^n)^(p+1))/(a n (p+1)))+(n (p+1)+1)/(a n (p+1)) \[Integral](a+b x^n)^(p+1) \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[(a_+b_.*x_^n_)^p_,x_Symbol] :=
  -x*(a+b*x^n)^(p+1)/(a*n*(p+1)) +
  Dist[(n*(p+1)+1)/(a*n*(p+1)),Int[(a+b*x^n)^(p+1),x]] /;
FreeQ[{a,b},x] && IntegersQ[n,p] && n>1 && p<-1


(* ::PageBreak:: *)
(**)


(* ::Title::Bold::Closed:: *)
(*\[Integral]x^m (a+b x^n)^p \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Reference: G&R 2.110.6, CRC 88c special case when m+n (p+1)+1=0*)


(* ::Subsubsection:: *)
(*Rule: If  m+n(p+1)+1=0 \[And] m+1!=0 \[And] p!=-2, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]x^m (a+b x^n)^p \[DifferentialD]x  \[LongRightArrow]  ((x^(m+1) (a+b x^n)^(p+1))/(a (m+1)))*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[x_^m_.*(a_+b_.*x_^n_)^p_,x_Symbol] :=
  x^(m+1)*(a+b*x^n)^(p+1)/(a*(m+1)) /;
FreeQ[{a,b,m,n,p},x] && ZeroQ[m+n*(p+1)+1] && NonzeroQ[m+1] && NonzeroQ[p+2]


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Reference: G&R 2.110.4*)


(* ::Subsubsection:: *)
(*Derivation: Integration by parts*)


(* ::Subsubsection:: *)
(*Basis: x^m (a+b x^n)^p=x^(m-n+1) (a+b x^n)^p x^(n-1)*)


(* ::Subsubsection:: *)
(*Basis: \[Integral](a+b x^n)^p x^(n-1) \[DifferentialD]x=(a+b x^n)^(p+1)/(b n (p+1))*)


(* ::Subsubsection:: *)
(*Note: Requirement that m<2 n-1 ensures new term is a proper fraction.*)


(* ::Subsubsection:: *)
(*Rule: If  m,n,p\[Element]\[DoubleStruckCapitalZ] \[And] 1<n<=m<2n-1 \[And] p<-1, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]x^m (a+b x^n)^p \[DifferentialD]x  \[LongRightArrow]  ((x^(m-n+1) (a+b x^n)^(p+1))/(b n (p+1)))-(m-n+1)/(b n (p+1)) \[Integral]x^(m-n) (a+b x^n)^(p+1) \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[x_^m_.*(a_+b_.*x_^n_)^p_,x_Symbol] :=
  x^(m-n+1)*(a+b*x^n)^(p+1)/(b*n*(p+1)) -
  Dist[(m-n+1)/(b*n*(p+1)),Int[x^(m-n)*(a+b*x^n)^(p+1),x]] /;
FreeQ[{a,b},x] && IntegersQ[m,n,p] && 1<n<=m<2*n-1 && p<-1


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Reference: G&R 2.110.2, CRC 88d*)


(* ::Subsubsection:: *)
(*Derivation: Integration by parts*)


(* ::Subsubsection:: *)
(*Basis: x^m (a+b x^n)^p=x^(m+n (p+1)+1) (a+b x^n)^p/x^(n (p+1)+1)*)


(* ::Subsubsection:: *)
(*Basis: \[Integral](a+b x^n)^p/x^(n (p+1)+1) \[DifferentialD]x=-((a+b x^n)^(p+1)/(x^(n (p+1)) a n (p+1)))*)


(* ::Subsubsection:: *)
(*Note: Requirement that m+1<n ensures new term is a proper fraction.*)


(* ::Subsubsection:: *)
(*Rule: If  m,n,p\[Element]\[DoubleStruckCapitalZ] \[And] n>1 \[And] 0<m+1<n \[And] p<-1 \[And] m+n (p+1)+1!=0, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]x^m (a+b x^n)^p \[DifferentialD]x  \[LongRightArrow]  -((x^(m+1) (a+b x^n)^(p+1))/(a n (p+1)))+(m+n (p+1)+1)/(a n (p+1)) \[Integral]x^m (a+b x^n)^(p+1) \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[x_^m_.*(a_+b_.*x_^n_)^p_,x_Symbol] :=
  -x^(m+1)*(a+b*x^n)^(p+1)/(a*n*(p+1)) +
  Dist[(m+n*(p+1)+1)/(a*n*(p+1)),Int[x^m*(a+b*x^n)^(p+1),x]] /;
FreeQ[{a,b},x] && IntegersQ[m,n,p] && n>1 && 0<m+1<n && p<-1 && NonzeroQ[m+n*(p+1)+1]


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Reference: G&R 2.110.6, CRC 88c*)


(* ::Subsubsection:: *)
(*Derivation: Integration by parts*)


(* ::Subsubsection:: *)
(*Basis: x^m (a+b x^n)^p=x^m/(a+b x^n)^((m+n+1)/n) (a+b x^n)^((m+n (p+1)+1)/n)*)


(* ::Subsubsection:: *)
(*Basis: \[Integral]x^m/(a+b x^n)^((m+n+1)/n) \[DifferentialD]x=x^(m+1)/((a+b x^n)^((m+1)/n) (a (m+1)))*)


(* ::Subsubsection:: *)
(*Note: Requirement that m+1<n ensures new term is a proper fraction.*)


(* ::Subsubsection:: *)
(*Rule: If  m,n,p,(m+n (p+1)+1)/n\[Element]\[DoubleStruckCapitalZ] \[And] m<-1 \[And] n>0 \[And] 0<n-2 (m+n (p+1)+1)<n p, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]x^m (a+b x^n)^p \[DifferentialD]x  \[LongRightArrow]  ((x^(m+1) (a+b x^n)^(p+1))/(a (m+1)))-(b (m+n (p+1)+1))/(a (m+1)) \[Integral]x^(m+n) (a+b x^n)^p \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[x_^m_.*(a_+b_.*x_^n_)^p_,x_Symbol] :=
  x^(m+1)*(a+b*x^n)^(p+1)/(a*(m+1)) -
  Dist[b*(m+n*(p+1)+1)/(a*(m+1)),Int[x^(m+n)*(a+b*x^n)^p,x]] /;
FreeQ[{a,b},x] && IntegersQ[m,n,p,(m+n*(p+1)+1)/n] && m<-1 && n>0 &&
0<n-2(m+n*(p+1)+1)<n*p


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Reference: G&R 2.110.5, CRC 88a*)


(* ::Subsubsection:: *)
(*Derivation: Inverted integration by parts*)


(* ::Subsubsection:: *)
(*Rule: If  m,n,p,(m+1)/n\[Element]\[DoubleStruckCapitalZ] \[And] m+n p+1!=0 \[And] (m+1)/n>0 \[And] (2 m)/n<p+1 \[And] 0<n<=m, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]x^m (a+b x^n)^p \[DifferentialD]x  \[LongRightArrow]  ((x^(m-n+1) (a+b x^n)^(p+1))/(b (m+n p+1)))-(a (m-n+1))/(b (m+n p+1)) \[Integral]x^(m-n) (a+b x^n)^p \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[x_^m_.*(a_+b_.*x_^n_)^p_,x_Symbol] :=
  x^(m-n+1)*(a+b*x^n)^(p+1)/(b*(m+n*p+1)) -
  Dist[a*(m-n+1)/(b*(m+n*p+1)),Int[x^(m-n)*(a+b*x^n)^p,x]] /;
FreeQ[{a,b},x] && IntegersQ[m,n,p,(m+1)/n] && NonzeroQ[m+n*p+1] && 
(m+1)/n>0 && 2*m/n<p+1 && 0<n<=m


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Derivation: Algebraic expansion*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[x_^m_.*(a_+b_.*x_^n_.)^p_.,x_Symbol] :=
  Int[Expand[x^m*(a+b*x^n)^p],x] /;
FreeQ[{a,b,m,n},x] && IntegerQ[p] && p>0 && ExpandIntegrandQ[m,n,p]


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Reference: G&R 2.110.4*)


(* ::Subsubsection:: *)
(*Derivation: Integration by parts*)


(* ::Subsubsection:: *)
(*Basis: x^m (a+b x^n)^p=x^(m-n+1) (a+b x^n)^p x^(n-1)*)


(* ::Subsubsection:: *)
(*Note: Requirement that m<2 n-1 ensures new term is a proper fraction.*)


(* ::Subsubsection:: *)
(*Note: Unfortunately this rule is necessary to prevent the Ostrogradskiy-Hermite method from being applied instead of substituting for c+d x.*)


(* ::Subsubsection:: *)
(*Rule: If  m,n,p\[Element]\[DoubleStruckCapitalZ] \[And] n>1 \[And] p<-1 \[And] n<=m<2n-1, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral](c+d x)^m (a+b (c+d x)^n)^p \[DifferentialD]x  \[LongRightArrow]                                                                                            *)
(*                (((c+d x)^(m-n+1) (a+b (c+d x)^n)^(p+1))/(b d n (p+1)))-(m-n+1)/(b n (p+1)) \[Integral](c+d x)^(m-n) (a+b (c+d x)^n)^(p+1) \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[(c_+d_.*x_)^m_.*(a_+b_.*(c_+d_.*x_)^n_)^p_,x_Symbol] :=
  (c+d*x)^(m-n+1)*(a+b*(c+d*x)^n)^(p+1)/(b*d*n*(p+1)) -
  Dist[(m-n+1)/(b*n*(p+1)),Int[(c+d*x)^(m-n)*(a+b*(c+d*x)^n)^(p+1),x]] /;
FreeQ[{a,b,c,d},x] && IntegersQ[m,n,p] && n>1 && p<-1 && n<=m<2*n-1


(* ::PageBreak:: *)
(**)


(* ::Title::Bold::Closed:: *)
(*\[Integral](a+b x^n)^m/(b+a/x^n) \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Derivation: Algebraic simplification*)


(* ::Subsubsection:: *)
(*Basis: (a+b x^n)/(b+a/x^n)=x^n*)


(* ::Subsubsection:: *)
(*Rule:*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral](a+b x^n)^m/(b+a/x^n) \[DifferentialD]x  \[LongRightArrow]  \[Integral]x^n (a+b x^n)^(m-1) \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[(a_+b_.*x_^n_.)^m_/(b_+a_.*x_^p_.),x_Symbol] :=
  Int[x^n*(a+b*x^n)^(m-1), x] /;
FreeQ[{a,b,m,n,p},x] && ZeroQ[n+p]


(* ::PageBreak:: *)
(**)


(* ::Title::Bold::Closed:: *)
(*\[Integral](a x^p+b x^q)^n \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Derivation: Algebraic simplification*)


(* ::Subsubsection:: *)
(*Basis: a z^p+b z^q=z^p (a+b z^(q-p))*)


(* ::Subsubsection:: *)
(*Rule: If  n\[Element]\[DoubleStruckCapitalZ], then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral](a x^p+b x^q)^n \[DifferentialD]x  \[LongRightArrow]  \[Integral]x^(n p) (a+b x^(q-p))^n \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[(a_.*x_^p_.+b_.*x_^q_.)^n_,x_Symbol] :=
  Int[x^(n*p)*(a+b*x^(q-p))^n,x] /;
FreeQ[{a,b,p,q},x] && IntegerQ[n] && Not[FractionQ[p]] && Not[FractionQ[q]] && Not[NegativeQ[q-p]]


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Derivation: Algebraic simplification*)


(* ::Subsubsection:: *)
(*Basis: a z^p+b z^q=z^p (a+b z^(q-p))*)


(* ::Subsubsection:: *)
(*Rule: If  n\[Element]\[DoubleStruckCapitalZ], then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]x^m (a x^p+b x^q)^n \[DifferentialD]x  \[LongRightArrow]  \[Integral]x^(m+n p) (a+b x^(q-p))^n \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[x_^m_.*(a_.*x_^p_.+b_.*x_^q_.)^n_,x_Symbol] :=
  Int[x^(m+n*p)*(a+b*x^(q-p))^n,x] /;
FreeQ[{a,b,m,p,q},x] && IntegerQ[n] && 
Not[FractionQ[p]] && Not[FractionQ[q]] && Not[FractionQ[m]] && Not[NegativeQ[q-p]]
