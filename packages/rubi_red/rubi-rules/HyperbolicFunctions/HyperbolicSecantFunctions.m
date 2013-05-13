(* ::Package:: *)

(* ::Title::Bold::Closed:: *)
(*\[Integral]Sech[a+b x]^n \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Reference:  G&R 2.423.9, CRC 558, A&S 4.5.81*)


(* ::Subsubsection:: *)
(*Derivation: Integration by substitution*)


(* ::Subsubsection:: *)
(*Basis: Sech[z]=Derivative[1][Sinh][z]/(1+Sinh[z]^2)*)


(* ::Subsubsection:: *)
(*Rule:*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]Sech[a+b x]\[DifferentialD]x  \[LongRightArrow]  (ArcTan[Sinh[a+b x]]/b)*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[Sech[a_.+b_.*x_],x_Symbol] :=
(* -ArcCot[Sinh[a+b*x]]/b *)
  ArcTan[Sinh[a+b*x]]/b /;
FreeQ[{a,b},x]


(* ::Subsubsection:: *)
(*Reference: G&R 2.423.1', CRC 559', A&S 4.5.80'*)


(* ::Code:: *)
Int[Csch[a_.+b_.*x_],x_Symbol] :=
(* -ArcTanh[Cosh[a+b*x]]/b *)
  -ArcCoth[Cosh[a+b*x]]/b /;
FreeQ[{a,b},x]


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Reference: G&R 2.423.10, CRC 571*)


(* ::Subsubsection:: *)
(*Derivation: Primitive rule*)


(* ::Subsubsection:: *)
(*Basis: Derivative[1][Tanh][z]=Sech[z]^2*)


(* ::Subsubsection:: *)
(*Rule:*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]Sech[a+b x]^2 \[DifferentialD]x  \[LongRightArrow]  (Tanh[a+b x]/b)*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[Sech[a_.+b_.*x_]^2,x_Symbol] :=
  Tanh[a+b*x]/b /;
FreeQ[{a,b},x]


(* ::Subsubsection:: *)
(*Reference: G&R 2.423.2, CRC 575*)


(* ::Code:: *)
Int[Csch[a_.+b_.*x_]^2,x_Symbol] :=
  -Coth[a+b*x]/b /;
FreeQ[{a,b},x]


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Derivation: Integration by substitution*)


(* ::Subsubsection:: *)
(*Basis: If n/2\[Element]\[DoubleStruckCapitalZ], then  Sech[z]^n=(1-Tanh[z]^2)^((n-2)/2) Derivative[1][Tanh][z]*)


(* ::Subsubsection:: *)
(*Note: This rule is used for even n since it requires fewer steps and results in a simpler antiderivative than the recursive rule.*)


(* ::Subsubsection:: *)
(*Rule: If n/2\[Element]\[DoubleStruckCapitalZ] \[And] n>1, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]Sech[a+b x]^n \[DifferentialD]x  \[LongRightArrow]  (1/b)Subst[\[Integral](1-x^2)^((n-2)/2) \[DifferentialD]x,x,Cosh[a+b x]]*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[Sech[a_.+b_.*x_]^n_,x_Symbol] :=
  Dist[1/b,Subst[Int[Regularize[(1-x^2)^((n-2)/2),x],x],x,Tanh[a+b*x]]] /;
FreeQ[{a,b},x] && EvenQ[n] && n>1


(* ::Code:: *)
Int[Csch[a_.+b_.*x_]^n_,x_Symbol] :=
  Dist[-1/b,Subst[Int[Regularize[(-1+x^2)^((n-2)/2),x],x],x,Coth[a+b*x]]] /;
FreeQ[{a,b},x] && EvenQ[n] && n>1


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Reference: G&R 2.411.6, CRC 568b*)


(* ::Subsubsection:: *)
(*Derivation: Integration by parts with a double-back flip*)


(* ::Subsubsection:: *)
(*Rule: If n/2\[Element]\[DoubleStruckCapitalZ] \[And] n>1, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]Sech[a+b x]^n \[DifferentialD]x  \[LongRightArrow]  ((Sinh[a+b x] Sech[a+b x]^(n-1))/(b (n-1)))+(n-2)/(n-1) \[Integral]Sech[a+b x]^(n-2) \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[Sech[a_.+b_.*x_]^n_,x_Symbol] :=
  Sinh[a+b*x]*Sech[a+b*x]^(n-1)/(b*(n-1)) + 
  Dist[(n-2)/(n-1),Int[Sech[a+b*x]^(n-2),x]] /;
FreeQ[{a,b},x] && Not[EvenQ[n]] && RationalQ[n] && n>1


(* ::Subsubsection:: *)
(*Reference: G&R 2.411.5, CRC 568a*)


(* ::Code:: *)
Int[Csch[a_.+b_.*x_]^n_,x_Symbol] :=
  -Cosh[a+b*x]*Csch[a+b*x]^(n-1)/(b*(n-1)) - 
  Dist[(n-2)/(n-1),Int[Csch[a+b*x]^(n-2),x]] /;
FreeQ[{a,b},x] && Not[EvenQ[n]] && RationalQ[n] && n>1


(* ::PageBreak:: *)
(**)


(* ::Title::Bold::Closed:: *)
(*\[Integral](c Sech[a+b x])^n \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Derivation: Piecewise constant extraction*)


(* ::Subsubsection:: *)
(*Basis: \!\( *)
(*\*SubscriptBox[\(\[PartialD]\), \(z\)]\(( *)
(*\*SuperscriptBox[\((c/f[z])\), \(n\)]\ *)
(*\*SuperscriptBox[\(f[z]\), \(n\)])\)\)=0*)


(* ::Subsubsection:: *)
(*Note: The special case rules for c=1 and n=-(1/2) are required due to an idem potent problem in Mathematica 6 & 7.*)


(* ::Subsubsection:: *)
(*Rule: If  -1<n<1, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral](c Sech[a+b x])^n \[DifferentialD]x  \[LongRightArrow]  (c Sech[a+b x])^n Cosh[a+b x]^n \[Integral]1/Cosh[a+b x]^n \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[1/Sqrt[Sech[a_.+b_.*x_]],x_Symbol] :=
  Sqrt[Cosh[a+b*x]]*Sqrt[Sech[a+b*x]]*Int[Sqrt[Cosh[a+b*x]],x] /;
FreeQ[{a,b},x]


(* ::Code:: *)
Int[(c_.*Sech[a_.+b_.*x_])^n_,x_Symbol] :=
  (c*Sech[a+b*x])^n*Cosh[a+b*x]^n*Int[1/Cosh[a+b*x]^n,x] /;
FreeQ[{a,b,c},x] && RationalQ[n] && -1<n<1


(* ::Code:: *)
Int[1/Sqrt[Csch[a_.+b_.*x_]],x_Symbol] :=
  Sqrt[Csch[a+b*x]]*Sqrt[Sinh[a+b*x]]*Int[Sqrt[Sinh[a+b*x]],x] /;
FreeQ[{a,b},x]


(* ::Code:: *)
Int[(c_.*Csch[a_.+b_.*x_])^n_,x_Symbol] :=
  (c*Csch[a+b*x])^n*Sinh[a+b*x]^n*Int[1/Sinh[a+b*x]^n,x] /;
FreeQ[{a,b,c},x] && RationalQ[n] && -1<n<1


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Reference: G&R 2.411.6, CRC 568b*)


(* ::Subsubsection:: *)
(*Derivation: Integration by parts with a double-back flip*)


(* ::Subsubsection:: *)
(*Rule: If  n>1, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral](c Sech[a+b x])^n \[DifferentialD]x  \[LongRightArrow]  ((c Sinh[a+b x] (c Sech[a+b x])^(n-1))/(b (n-1)))+(c^2 (n-2))/(n-1) \[Integral](c Sech[a+b x])^(n-2) \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[(c_.*Sech[a_.+b_.*x_])^n_,x_Symbol] :=
  c*Sinh[a+b*x]*(c*Sech[a+b*x])^(n-1)/(b*(n-1)) + 
  Dist[c^2*(n-2)/(n-1),Int[(c*Sech[a+b*x])^(n-2),x]] /;
FreeQ[{a,b,c},x] && FractionQ[n] && n>1


(* ::Subsubsection:: *)
(*Reference: G&R 2.411.5, CRC 568a*)


(* ::Code:: *)
Int[(c_.*Csch[a_.+b_.*x_])^n_,x_Symbol] :=
  -c*Cosh[a+b*x]*(c*Csch[a+b*x])^(n-1)/(b*(n-1)) - 
  Dist[c^2*(n-2)/(n-1),Int[(c*Csch[a+b*x])^(n-2),x]] /;
FreeQ[{a,b,c},x] && FractionQ[n] && n>1


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Reference: G&R 2.411.1, CRC 567a*)


(* ::Subsubsection:: *)
(*Derivation: Integration by parts with a double-back flip*)


(* ::Subsubsection:: *)
(*Rule: If  n<-1, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral](c Sech[a+b x])^n \[DifferentialD]x  \[LongRightArrow]  -((Sinh[a+b x] (c Sech[a+b x])^(n+1))/(b c n))+(n+1)/(c^2 n) \[Integral](c Sech[a+b x])^(n+2) \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[(c_.*Sech[a_.+b_.*x_])^n_,x_Symbol] :=
  -Sinh[a+b*x]*(c*Sech[a+b*x])^(n+1)/(b*c*n) + 
  Dist[(n+1)/(c^2*n),Int[(c*Sech[a+b*x])^(n+2),x]] /;
FreeQ[{a,b,c},x] && FractionQ[n] && n<-1


(* ::Subsubsection:: *)
(*Reference: G&R 2.411.2, CRC 567b*)


(* ::Code:: *)
Int[(c_.*Csch[a_.+b_.*x_])^n_,x_Symbol] :=
  -Cosh[a+b*x]*(c*Csch[a+b*x])^(n+1)/(b*c*n) - 
  Dist[(n+1)/(c^2*n),Int[(c*Csch[a+b*x])^(n+2),x]] /;
FreeQ[{a,b,c},x] && FractionQ[n] && n<-1


(* ::PageBreak:: *)
(**)


(* ::Title::Bold::Closed:: *)
(*\[Integral](a+b Sech[c+d x])^(n/2) \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Rule: If  a^2-b^2=0, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]Sqrt[a+b Sech[c+d x]]\[DifferentialD]x  \[LongRightArrow]  ((2 a ArcTan[Sqrt[-1+(a Sech[c+d x])/b]] Tanh[c+d x])/(d Sqrt[-1+(a Sech[c+d x])/b] Sqrt[a+b Sech[c+d x]]))*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[Sqrt[a_+b_.*Sech[c_.+d_.*x_]],x_Symbol] :=
  2*a*ArcTan[Sqrt[-1+a/b*Sech[c+d*x]]]*Tanh[c+d*x]/
		(d*Sqrt[-1+a/b*Sech[c+d*x]]*Sqrt[a+b*Sech[c+d*x]]) /;
FreeQ[{a,b,c,d},x] && ZeroQ[a^2-b^2]


(* ::Code:: *)
Int[Sqrt[a_+b_.*Csch[c_.+d_.*x_]],x_Symbol] :=
  2*a*ArcTan[Sqrt[-1-a/b*Csch[c+d*x]]]*Coth[c+d*x]/
		(d*Sqrt[-1-a/b*Csch[c+d*x]]*Sqrt[a+b*Csch[c+d*x]]) /;
FreeQ[{a,b,c,d},x] && ZeroQ[a^2+b^2]


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Note: Is there a simpler antiderivative?*)


(* ::Subsubsection:: *)
(*Rule: If  a^2-b^2=0, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]1/Sqrt[a+b Sech[c+d x]] \[DifferentialD]x  \[LongRightArrow]  *)
(*-((Coth[c+d x] Sqrt[-a+b Sech[c+d x]] Sqrt[a+b Sech[c+d x]])/(a^(3/2) d))(Sqrt[2] ArcTan[Sqrt[2 a]/Sqrt[-a+b Sech[c+d x]]]+2 ArcTan[Sqrt[-a+b Sech[c+d x]]/Sqrt[a]])*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[1/Sqrt[a_+b_.*Sech[c_.+d_.*x_]],x_Symbol] :=
  -Coth[c+d*x]*Sqrt[-a+b*Sech[c+d*x]]*Sqrt[a+b*Sech[c+d*x]]/(a^(3/2)*d)*
    (Sqrt[2]*ArcTan[Sqrt[2*a]/Sqrt[-a+b*Sech[c+d*x]]]+2*ArcTan[Sqrt[-a+b*Sech[c+d*x]]/Sqrt[a]]) /;
FreeQ[{a,b,c,d},x] && ZeroQ[a^2-b^2]


(* ::Code:: *)
Int[1/Sqrt[a_+b_.*Csch[c_.+d_.*x_]],x_Symbol] :=
  -Sqrt[-a+b*Csch[c+d*x]]*Sqrt[a+b*Csch[c+d*x]]*Tanh[c+d*x]/a^(3/2)*
    (Sqrt[2]*ArcTan[Sqrt[2*a]/Sqrt[-a+b*Csch[c+d*x]]]+2*ArcTan[Sqrt[-a+b*Csch[c+d*x]]/Sqrt[a]]) /;
FreeQ[{a,b,c,d},x] && ZeroQ[a^2+b^2]


(* ::PageBreak:: *)
(**)


(* ::Title::Bold::Closed:: *)
(*\[Integral]x^m Sech[a+b x]^n \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Derivation: Integration by parts*)


(* ::Subsubsection:: *)
(*Rule: If  m\[Element]\[DoubleStruckCapitalZ] \[And] m>0, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]x^m Sech[a+b x]\[DifferentialD]x  \[LongRightArrow]  ((2x^m ArcTan[E^(a+b x)])/b)-(2m)/b \[Integral]x^(m-1) ArcTan[E^(a+b x)]\[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[x_^m_.*Sech[a_.+b_.*x_],x_Symbol] :=
  2*x^m*ArcTan[E^(a+b*x)]/b -
  Dist[2*m/b,Int[x^(m-1)*ArcTan[E^(a+b*x)],x]] /;
FreeQ[{a,b},x] && IntegerQ[m] && m>0


(* ::Code:: *)
Int[x_^m_.*Csch[a_.+b_.*x_],x_Symbol] :=
  -2*x^m*ArcTanh[E^(a+b x)]/b +
  Dist[2*m/b,Int[x^(m-1)*ArcTanh[E^(a+b x)],x]] /;
FreeQ[{a,b},x] && IntegerQ[m] && m>0


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Reference: CRC 430h*)


(* ::Subsubsection:: *)
(*Rule: If  m>0, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]x^m Sech[a+b x]^2 \[DifferentialD]x  \[LongRightArrow]  ((x^m Tanh[a+b x])/b)-m/b \[Integral]x^(m-1) Tanh[a+b x]\[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[x_^m_.*Sech[a_.+b_.*x_]^2,x_Symbol] :=
  x^m*Tanh[a+b*x]/b -
  Dist[m/b,Int[x^(m-1)*Tanh[a+b*x],x]] /;
FreeQ[{a,b},x] && RationalQ[m] && m>0


(* ::Subsubsection:: *)
(*Reference:  CRC 428h*)


(* ::Code:: *)
Int[x_^m_.*Csch[a_.+b_.*x_]^2,x_Symbol] :=
  -x^m*Coth[a+b*x]/b +
  Dist[m/b,Int[x^(m-1)*Coth[a+b*x],x]] /;
FreeQ[{a,b},x] && RationalQ[m] && m>0


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Reference: G&R 2.643.2h, CRC 431h*)


(* ::Subsubsection:: *)
(*Rule: If  n>1 \[And] n!=2, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]x Sech[a+b x]^n \[DifferentialD]x  \[LongRightArrow]  ((x Tanh[a+b x] Sech[a+b x]^(n-2))/(b (n-1)))+Sech[a+b x]^(n-2)/(b^2 (n-1) (n-2))+(n-2)/(n-1) \[Integral]x Sech[a+b x]^(n-2) \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[x_*Sech[a_.+b_.*x_]^n_,x_Symbol] :=
  x*Tanh[a+b*x]*Sech[a+b*x]^(n-2)/(b*(n-1)) +
  Sech[a+b*x]^(n-2)/(b^2*(n-1)*(n-2)) +
  Dist[(n-2)/(n-1),Int[x*Sech[a+b*x]^(n-2),x]] /;
FreeQ[{a,b},x] && RationalQ[n] && n>1 && n!=2


(* ::Subsubsection:: *)
(*Reference: G&R 2.643.1h, CRC 429h*)


(* ::Code:: *)
Int[x_*Csch[a_.+b_.*x_]^n_,x_Symbol] :=
  -x*Coth[a+b*x]*Csch[a+b*x]^(n-2)/(b*(n-1)) -
  Csch[a+b*x]^(n-2)/(b^2*(n-1)*(n-2)) -
  Dist[(n-2)/(n-1),Int[x*Csch[a+b*x]^(n-2),x]] /;
FreeQ[{a,b},x] && RationalQ[n] && n>1 && n!=2


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Reference: G&R 2.643.2h*)


(* ::Subsubsection:: *)
(*Rule: If  m>1 \[And] n>1 \[And] n!=2, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]x^m Sech[a+b x]^n \[DifferentialD]x  \[LongRightArrow]  ((x^m Tanh[a+b x] Sech[a+b x]^(n-2))/(b (n-1)))+(m x^(m-1) Sech[a+b x]^(n-2))/(b^2 (n-1) (n-2))+                          *)
(*                                            (n-2)/(n-1) \[Integral]x^m Sech[a+b x]^(n-2) \[DifferentialD]x-(m (m-1))/(b^2 (n-1) (n-2)) \[Integral]x^(m-2) Sech[a+b x]^(n-2) \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[x_^m_*Sech[a_.+b_.*x_]^n_,x_Symbol] :=
  x^m*Tanh[a+b*x]*Sech[a+b*x]^(n-2)/(b*(n-1)) +
  m*x^(m-1)*Sech[a+b*x]^(n-2)/(b^2*(n-1)*(n-2)) +
  Dist[(n-2)/(n-1),Int[x^m*Sech[a+b*x]^(n-2),x]] -
  Dist[m*(m-1)/(b^2*(n-1)*(n-2)),Int[x^(m-2)*Sech[a+b*x]^(n-2),x]] /;
FreeQ[{a,b},x] && RationalQ[{m,n}] && m>1 && n>1 && n!=2


(* ::Subsubsection:: *)
(*Reference: G&R 2.643.1h*)


(* ::Code:: *)
Int[x_^m_*Csch[a_.+b_.*x_]^n_,x_Symbol] :=
  -x^m*Coth[a+b*x]*Csch[a+b*x]^(n-2)/(b*(n-1)) -
  m*x^(m-1)*Csch[a+b*x]^(n-2)/(b^2*(n-1)*(n-2)) -
  Dist[(n-2)/(n-1),Int[x^m*Csch[a+b*x]^(n-2),x]] +
  Dist[m*(m-1)/(b^2*(n-1)*(n-2)),Int[x^(m-2)*Csch[a+b*x]^(n-2),x]] /;
FreeQ[{a,b},x] && RationalQ[{m,n}] && m>1 && n>1 && n!=2


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Reference: G&R 2.631.3h*)


(* ::Subsubsection:: *)
(*Rule: If  n<-1, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]x Sech[a+b x]^n \[DifferentialD]x  \[LongRightArrow]  -(Sech[a+b x]^n/(b^2 n^2))-(x Sinh[a+b x] Sech[a+b x]^(n+1))/(b n)+(n+1)/n \[Integral]x Sech[a+b x]^(n+2) \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[x_*Sech[a_.+b_.*x_]^n_,x_Symbol] :=
  -Sech[a+b*x]^n/(b^2*n^2) -
  x*Sinh[a+b*x]*Sech[a+b*x]^(n+1)/(b*n) +
  Dist[(n+1)/n,Int[x*Sech[a+b*x]^(n+2),x]] /;
FreeQ[{a,b},x] && RationalQ[n] && n<-1


(* ::Subsubsection:: *)
(*Reference: G&R 2.631.2h*)


(* ::Code:: *)
Int[x_*Csch[a_.+b_.*x_]^n_,x_Symbol] :=
  -Csch[a+b*x]^n/(b^2*n^2) -
  x*Cosh[a+b*x]*Csch[a+b*x]^(n+1)/(b*n) -
  Dist[(n+1)/n,Int[x*Csch[a+b*x]^(n+2),x]] /;
FreeQ[{a,b},x] && RationalQ[n] && n<-1


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Reference: G&R 2.631.3h*)


(* ::Subsubsection:: *)
(*Rule: If  m>1 \[And] n<-1, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]x^m Sech[a+b x]^n \[DifferentialD]x  \[LongRightArrow]  -((m x^(m-1) Sech[a+b x]^n)/(b^2 n^2))-(x^m Sinh[a+b x] Sech[a+b x]^(n+1))/(b n)+                      *)
(*                                                                      (n+1)/n \[Integral]x^m Sech[a+b x]^(n+2) \[DifferentialD]x+(m (m-1))/(b^2 n^2) \[Integral]x^(m-2) Sech[a+b x]^n \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[x_^m_*Sech[a_.+b_.*x_]^n_,x_Symbol] :=
  -m*x^(m-1)*Sech[a+b*x]^n/(b^2*n^2) -
  x^m*Sinh[a+b*x]*Sech[a+b*x]^(n+1)/(b*n) +
  Dist[(n+1)/n,Int[x^m*Sech[a+b*x]^(n+2),x]] +
  Dist[m*(m-1)/(b^2*n^2),Int[x^(m-2)*Sech[a+b*x]^n,x]] /;
FreeQ[{a,b},x] && RationalQ[{m,n}] && m>1 && n<-1


(* ::Subsubsection:: *)
(*Reference: G&R 2.631.2h*)


(* ::Code:: *)
Int[x_^m_*Csch[a_.+b_.*x_]^n_,x_Symbol] :=
  -m*x^(m-1)*Csch[a+b*x]^n/(b^2*n^2) -
  x^m*Cosh[a+b*x]*Csch[a+b*x]^(n+1)/(b*n) -
  Dist[(n+1)/n,Int[x^m*Csch[a+b*x]^(n+2),x]] +
  Dist[m*(m-1)/(b^2*n^2),Int[x^(m-2)*Csch[a+b*x]^n,x]] /;
FreeQ[{a,b},x] && RationalQ[{m,n}] && m>1 && n<-1


(* ::PageBreak:: *)
(**)


(* ::Title::Bold::Closed:: *)
(*\[Integral](a+b Sech[c+d x]^n)^m \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Derivation: Algebraic simplification*)


(* ::Subsubsection:: *)
(*Basis: If  n\[Element]\[DoubleStruckCapitalZ], then  a+b Sech[z]^n=(b+a Cosh[z]^n)/Cosh[z]^n*)


(* ::Subsubsection:: *)
(*Rule: If  m,n\[Element]\[DoubleStruckCapitalZ] \[And] m<0 \[And] n>0, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral](a+b Sech[v]^n)^m \[DifferentialD]x  \[LongRightArrow]  \[Integral](b+a Cosh[v]^n)^m/Cosh[v]^(m n) \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[(a_+b_.*Sech[v_]^n_.)^m_,x_Symbol] :=
  Int[(b+a*Cosh[v]^n)^m/Cosh[v]^(m*n),x] /;
FreeQ[{a,b},x] && IntegersQ[m,n] && m<0 && n>0


(* ::Code:: *)
Int[(a_+b_.*Csch[v_]^n_.)^m_,x_Symbol] :=
  Int[(b+a*Sinh[v]^n)^m/Sinh[v]^(m*n),x] /;
FreeQ[{a,b},x] && IntegersQ[m,n] && m<0 && n>0


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Derivation: Algebraic simplification*)


(* ::Subsubsection:: *)
(*Basis: If  n\[Element]\[DoubleStruckCapitalZ], then  a+b Sech[z]^n=(b+a Cosh[z]^n)/Cosh[z]^n*)


(* ::Subsubsection:: *)
(*Rule: If  m,n,p\[Element]\[DoubleStruckCapitalZ] \[And] m<0 \[And] n>0, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]Cosh[v]^p (a+b Sech[v]^n)^m \[DifferentialD]x  \[LongRightArrow]  \[Integral]Cosh[v]^(p-m n) (b+a Cosh[v]^n)^m \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[Cosh[v_]^p_.*(a_+b_.*Sech[v_]^n_.)^m_,x_Symbol] :=
  Int[Cosh[v]^(p-m*n)*(b+a*Cosh[v]^n)^m,x] /;
FreeQ[{a,b},x] && IntegersQ[m,n,p] && m<0 && n>0


(* ::Code:: *)
Int[Sinh[v_]^p_.*(a_+b_.*Csch[v_]^n_.)^m_,x_Symbol] :=
  Int[Sinh[v]^(p-m*n)*(b+a*Sinh[v]^n)^m,x] /;
FreeQ[{a,b},x] && IntegersQ[m,n,p] && m<0 && n>0


(* ::PageBreak:: *)
(**)


(* ::Title::Bold::Closed:: *)
(*\[Integral]Csch[a+b x]^m Sech[a+b x]^n \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Reference: G&R 2.423.49*)


(* ::Subsubsection:: *)
(*Rule: If  b>0, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]Csch[a+b x]Sech[a+b x]\[DifferentialD]x  \[LongRightArrow]  (Log[Tanh[a+b x]]/b)*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[Csch[a_.+b_.*x_]*Sech[a_.+b_.*x_],x_Symbol] :=
  Log[Tanh[a+b*x]]/b /;
FreeQ[{a,b},x] && PosQ[b]


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Rule: If  m+n-2=0 \[And] n-1!=0 \[And] n>0, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]Csch[a+b x]^m Sech[a+b x]^n \[DifferentialD]x  \[LongRightArrow]  ((Csch[a+b x]^(m-1) Sech[a+b x]^(n-1))/(b (n-1)))*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[Csch[a_.+b_.*x_]^m_*Sech[a_.+b_.*x_]^n_,x_Symbol] :=
  Csch[a+b*x]^(m-1)*Sech[a+b*x]^(n-1)/(b*(n-1)) /;
FreeQ[{a,b,m,n},x] && ZeroQ[m+n-2] && NonzeroQ[n-1] && PosQ[n]


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Derivation: Integration by substitution*)


(* ::Subsubsection:: *)
(*Basis: If  m,n,(m+n)/2\[Element]\[DoubleStruckCapitalZ], then Csch[z]^m Sech[z]^n==(1-Tanh[z]^2)^((m+n)/2-1)/Tanh[z]^m Derivative[1][Tanh][z]*)


(* ::Subsubsection:: *)
(*Rule: If  m,n,(m+n)/2\[Element]\[DoubleStruckCapitalZ] \[And] 0<m<=n, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]Csch[a+b x]^m Sech[a+b x]^n \[DifferentialD]x  \[LongRightArrow]  (1/b)Subst[\[Integral](1-x^2)^((m+n)/2-1)/x^m \[DifferentialD]x,x,Tanh[a+b x]]*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[Csch[a_.+b_.*x_]^m_.*Sech[a_.+b_.*x_]^n_,x_Symbol] :=
  Dist[1/b,Subst[Int[Regularize[(1-x^2)^((m+n)/2-1)/x^m,x],x],x,Tanh[a+b*x]]] /;
FreeQ[{a,b},x] && IntegersQ[m,n] && EvenQ[m+n] && 0<m<=n


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Reference: G&R 2.411.4*)


(* ::Subsubsection:: *)
(*Rule: If  m<-1 \[And] n>1, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]Csch[a+b x]^m Sech[a+b x]^n \[DifferentialD]x  \[LongRightArrow]  -((Csch[a+b x]^(m+1) Sech[a+b x]^(n-1))/(b (n-1)))-(m+1)/(n-1) \[Integral]Csch[a+b x]^(m+2) Sech[a+b x]^(n-2) \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[Csch[a_.+b_.*x_]^m_*Sech[a_.+b_.*x_]^n_,x_Symbol] :=
  -Csch[a+b*x]^(m+1)*Sech[a+b*x]^(n-1)/(b*(n-1)) -
  Dist[(m+1)/(n-1),Int[Csch[a+b*x]^(m+2)*Sech[a+b*x]^(n-2),x]] /;
FreeQ[{a,b},x] && RationalQ[{m,n}] && m<-1 && n>1


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Reference: G&R 2.411.6, CRC 568b, A&S 4.5.86b*)


(* ::Subsubsection:: *)
(*Rule: If  n>1 \[And] (m+n)/2\[NotElement]\[DoubleStruckCapitalZ] \[And] \[Not](n/2,(m-1)/2\[Element]\[DoubleStruckCapitalZ] \[And] m>1), then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]Csch[a+b x]^m Sech[a+b x]^n \[DifferentialD]x  \[LongRightArrow]  ((Csch[a+b x]^(m-1) Sech[a+b x]^(n-1))/(b (n-1)))+(m+n-2)/(n-1) \[Integral]Csch[a+b x]^m Sech[a+b x]^(n-2) \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[Csch[a_.+b_.*x_]^m_.*Sech[a_.+b_.*x_]^n_,x_Symbol] :=
  Csch[a+b*x]^(m-1)*Sech[a+b*x]^(n-1)/(b*(n-1)) +
  Dist[(m+n-2)/(n-1),Int[Csch[a+b*x]^m*Sech[a+b*x]^(n-2),x]] /;
FreeQ[{a,b,m},x] && RationalQ[n] && n>1 && Not[EvenQ[m+n]] && Not[EvenQ[n] && OddQ[m] && m>1]


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Reference: G&R 2.411.1, CRC 567a, A&S 4.5.85a*)


(* ::Subsubsection:: *)
(*Rule: If  n<-1 \[And] m+n!=0, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]Csch[a+b x]^m Sech[a+b x]^n \[DifferentialD]x  \[LongRightArrow]  -((Csch[a+b x]^(m-1) Sech[a+b x]^(n+1))/(b (m+n)))+(n+1)/(m+n) \[Integral]Csch[a+b x]^m Sech[a+b x]^(n+2) \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[Csch[a_.+b_.*x_]^m_.*Sech[a_.+b_.*x_]^n_,x_Symbol] :=
  -Csch[a+b*x]^(m-1)*Sech[a+b*x]^(n+1)/(b*(m+n)) +
  Dist[(n+1)/(m+n),Int[Csch[a+b*x]^m*Sech[a+b*x]^(n+2),x]] /;
FreeQ[{a,b,m},x] && RationalQ[n] && n<-1 && NonzeroQ[m+n]


(* ::PageBreak:: *)
(**)


(* ::Title::Bold::Closed:: *)
(*\[Integral]Csch[a+b x]^m Sech[a+b x]^n \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Reference: G&R 2.423.49'*)


(* ::Subsubsection:: *)
(*Rule: If  \[Not](b>0), then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]Csch[a+b x]Sech[a+b x]\[DifferentialD]x  \[LongRightArrow]  -(Log[Coth[a+b x]]/b)*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[Csch[a_.+b_.*x_]*Sech[a_.+b_.*x_],x_Symbol] :=
  -Log[Coth[a+b*x]]/b /;
FreeQ[{a,b},x] && NegQ[b]


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Rule: If  m+n-2=0 \[And] m-1!=0 \[And] m>0, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]Csch[a+b x]^m Sech[a+b x]^n \[DifferentialD]x  \[LongRightArrow]  -((Csch[a+b x]^(m-1) Sech[a+b x]^(n-1))/(b (m-1)))*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[Csch[a_.+b_.*x_]^m_*Sech[a_.+b_.*x_]^n_,x_Symbol] :=
  -Csch[a+b*x]^(m-1)*Sech[a+b*x]^(n-1)/(b*(m-1)) /;
FreeQ[{a,b,m,n},x] && ZeroQ[m+n-2] && NonzeroQ[m-1] && PosQ[m]


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Derivation: Integration by substitution*)


(* ::Subsubsection:: *)
(*Basis: If  m,n,(m+n)/2\[Element]\[DoubleStruckCapitalZ], then Csch[z]^m Sech[z]^n=-((-1+Coth[z]^2)^((m+n)/2-1)/Coth[z]^n)Derivative[1][Coth][z]*)


(* ::Subsubsection:: *)
(*Rule: If  m,n,(m+n)/2\[Element]\[DoubleStruckCapitalZ] \[And] 0<n<m, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]Csch[a+b x]^m Sech[a+b x]^n \[DifferentialD]x  \[LongRightArrow]  -(1/b)Subst[Int[(-1+x^2)^((m+n)/2-1)/x^n,x],x,Coth[a+b x]]*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[Csch[a_.+b_.*x_]^m_*Sech[a_.+b_.*x_]^n_.,x_Symbol] :=
  Dist[-1/b,Subst[Int[Regularize[(-1+x^2)^((m+n)/2-1)/x^n,x],x],x,Coth[a+b*x]]] /;
FreeQ[{a,b},x] && IntegersQ[m,n] && EvenQ[m+n] && 0<n<m


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Reference: G&R 2.411.3*)


(* ::Subsubsection:: *)
(*Rule: If  m>1 \[And] n<-1, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]Csch[a+b x]^m Sech[a+b x]^n \[DifferentialD]x  \[LongRightArrow]  -((Csch[a+b x]^(m-1) Sech[a+b x]^(n+1))/(b (m-1)))-(n+1)/(m-1) \[Integral]Csch[a+b x]^(m-2) Sech[a+b x]^(n+2) \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[Csch[a_.+b_.*x_]^m_*Sech[a_.+b_.*x_]^n_,x_Symbol] :=
  -Csch[a+b*x]^(m-1)*Sech[a+b*x]^(n+1)/(b*(m-1)) -
  Dist[(n+1)/(m-1),Int[Csch[a+b*x]^(m-2)*Sech[a+b*x]^(n+2),x]] /;
FreeQ[{a,b},x] && RationalQ[{m,n}] && m>1 && n<-1


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Reference: G&R 2.411.5, CRC 568a, A&S 4.5.86a*)


(* ::Subsubsection:: *)
(*Rule: If  m>1 \[And] (m+n)/2\[NotElement]\[DoubleStruckCapitalZ] \[And] \[Not](m/2,(n-1)/2\[Element]\[DoubleStruckCapitalZ] \[And] n>1), then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]Csch[a+b x]^m Sech[a+b x]^n \[DifferentialD]x  \[LongRightArrow]                                                                                                                            *)
(*                                                     -((Csch[a+b x]^(m-1) Sech[a+b x]^(n-1))/(b (m-1)))-(m+n-2)/(m-1) \[Integral]Csch[a+b x]^(m-2) Sech[a+b x]^n \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[Csch[a_.+b_.*x_]^m_*Sech[a_.+b_.*x_]^n_.,x_Symbol] :=
  -Csch[a+b*x]^(m-1)*Sech[a+b*x]^(n-1)/(b*(m-1)) -
  Dist[(m+n-2)/(m-1),Int[Csch[a+b*x]^(m-2)*Sech[a+b*x]^n,x]] /;
FreeQ[{a,b,n},x] && RationalQ[m] && m>1 && Not[EvenQ[m+n]] && Not[EvenQ[m] && OddQ[n] && n>1]


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Reference: G&R 2.411.2, CRC 567b, A&S 4.5.85b*)


(* ::Subsubsection:: *)
(*Rule: If  m<-1 \[And] m+n!=0, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]Csch[a+b x]^m Sech[a+b x]^n \[DifferentialD]x  \[LongRightArrow]  -((Csch[a+b x]^(m+1) Sech[a+b x]^(n-1))/(b (m+n)))-(m+1)/(m+n) \[Integral]Csch[a+b x]^(m+2) Sech[a+b x]^n \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[Csch[a_.+b_.*x_]^m_*Sech[a_.+b_.*x_]^n_.,x_Symbol] :=
  -Csch[a+b*x]^(m+1)*Sech[a+b*x]^(n-1)/(b*(m+n)) -
  Dist[(m+1)/(m+n),Int[Csch[a+b*x]^(m+2)*Sech[a+b*x]^n,x]] /;
FreeQ[{a,b,n},x] && RationalQ[m] && m<-1 && NonzeroQ[m+n]


(* ::PageBreak:: *)
(**)


(* ::Title::Bold::Closed:: *)
(*\[Integral]Sech[a+b x]^m Tanh[a+b x]^n \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Derivation: Power rule for integration*)


(* ::Subsubsection:: *)
(*Rule:*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]Sech[a+b x]^m Tanh[a+b x]\[DifferentialD]x  \[LongRightArrow]  -(Sech[a+b x]^m/(b m))*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[Sech[a_.+b_.*x_]^m_.*Tanh[a_.+b_.*x_]^n_.,x_Symbol] :=
  -Sech[a+b*x]^m/(b*m) /;
FreeQ[{a,b,m},x] && n===1


(* ::Code:: *)
Int[Csch[a_.+b_.*x_]^m_.*Coth[a_.+b_.*x_]^n_.,x_Symbol] :=
  -Csch[a+b*x]^m/(b*m) /;
FreeQ[{a,b,m},x] && n===1


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Derivation: Integration by substitution*)


(* ::Subsubsection:: *)
(*Basis: If m/2\[Element]\[DoubleStruckCapitalZ], then Sech[z]^m=(1-Tanh[z]^2)^((m-2)/2) Derivative[1][Tanh][z]*)


(* ::Subsubsection:: *)
(*Rule: If  m/2\[Element]\[DoubleStruckCapitalZ] \[And] m>2 \[And] \[Not]((n-1)/2\[Element]\[DoubleStruckCapitalZ] \[And] 0<n<m-1), then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]Sech[a+b x]^m Tanh[a+b x]^n \[DifferentialD]x  \[LongRightArrow]  (1/b)Subst[Int[x^n (1-x^2)^((m-2)/2),x],x,Tanh[a+b x]]*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[Sech[a_.+b_.*x_]^m_*Tanh[a_.+b_.*x_]^n_.,x_Symbol] :=
  Dist[1/b,Subst[Int[Regularize[x^n*(1-x^2)^((m-2)/2),x],x],x,Tanh[a+b*x]]] /;
FreeQ[{a,b,n},x] && EvenQ[m] && m>2 && Not[OddQ[n] && 0<n<m-1]


(* ::Code:: *)
Int[Csch[a_.+b_.*x_]^m_*Coth[a_.+b_.*x_]^n_.,x_Symbol] :=
  Dist[-1/b,Subst[Int[Regularize[x^n*(-1+x^2)^((m-2)/2),x],x],x,Coth[a+b*x]]] /;
FreeQ[{a,b,n},x] && EvenQ[m] && m>2 && Not[OddQ[n] && 0<n<m-1]


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Derivation: Integration by substitution*)


(* ::Subsubsection:: *)
(*Basis: If  (n-1)/2\[Element]\[DoubleStruckCapitalZ], then Sech[z]^m Tanh[z]^n=-Sech[z]^(m-1) (1-Sech[z]^2)^((n-1)/2) Derivative[1][Sech][z]*)


(* ::Subsubsection:: *)
(*Rule: If  (n-1)/2\[Element]\[DoubleStruckCapitalZ] \[And] \[Not](m/2\[Element]\[DoubleStruckCapitalZ] \[And] 0<m<=n+1), then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]Sech[a+b x]^m Tanh[a+b x]^n \[DifferentialD]x  \[LongRightArrow]  -(1/b)Subst[\[Integral]x^(m-1) (1-x^2)^((n-1)/2) \[DifferentialD]x,x,Sech[a+b x]]*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[Sech[a_.+b_.*x_]^m_.*Tanh[a_.+b_.*x_]^n_.,x_Symbol] :=
  Dist[-1/b,Subst[Int[Regularize[x^(m-1)*(1-x^2)^((n-1)/2),x],x],x,Sech[a+b*x]]] /;
FreeQ[{a,b,m},x] && OddQ[n] && Not[EvenQ[m] && 0<m<=n+1]


(* ::Code:: *)
Int[Csch[a_.+b_.*x_]^m_.*Coth[a_.+b_.*x_]^n_.,x_Symbol] :=
  Dist[-1/b,Subst[Int[Regularize[x^(m-1)*(1+x^2)^((n-1)/2),x],x],x,Csch[a+b*x]]] /;
FreeQ[{a,b,m},x] && OddQ[n] && Not[EvenQ[m] && 0<m<=n+1]


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Reference: G&R 2.411.5, CRC 568a*)


(* ::Subsubsection:: *)
(*Rule: If  m>1 \[And] n<-1 \[And] m/2\[NotElement]\[DoubleStruckCapitalZ], then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]Sech[a+b x]^m Tanh[a+b x]^n \[DifferentialD]x  \[LongRightArrow]  ((Sech[a+b x]^(m-2) Tanh[a+b x]^(n+1))/(b (n+1)))+(m-2)/(n+1) \[Integral]Sech[a+b x]^(m-2) Tanh[a+b x]^(n+2) \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[Sech[a_.+b_.*x_]^m_*Tanh[a_.+b_.*x_]^n_,x_Symbol] :=
  Sech[a+b*x]^(m-2)*Tanh[a+b*x]^(n+1)/(b*(n+1)) +
  Dist[(m-2)/(n+1),Int[Sech[a+b*x]^(m-2)*Tanh[a+b*x]^(n+2),x]] /;
FreeQ[{a,b},x] && RationalQ[{m,n}] && m>1 && n<-1 && Not[EvenQ[m]]


(* ::Subsubsection:: *)
(*Reference: G&R 2.411.6, CRC 568b*)


(* ::Code:: *)
Int[Csch[a_.+b_.*x_]^m_.*Coth[a_.+b_.*x_]^n_,x_Symbol] :=
  -Csch[a+b*x]^(m-2)*Coth[a+b*x]^(n+1)/(b*(n+1)) -
  Dist[(m-2)/(n+1),Int[Csch[a+b*x]^(m-2)*Coth[a+b*x]^(n+2),x]] /;
FreeQ[{a,b},x] && RationalQ[{m,n}] && m>1 && n<-1 && Not[EvenQ[m]]


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Reference: G&R 2.411.2, CRC 567b*)


(* ::Subsubsection:: *)
(*Rule: If  m<-1 \[And] n>1 \[And] m/2\[NotElement]\[DoubleStruckCapitalZ], then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]Sech[a+b x]^m Tanh[a+b x]^n \[DifferentialD]x  \[LongRightArrow]  -((Sech[a+b x]^m Tanh[a+b x]^(n-1))/(b m))+(n-1)/m \[Integral]Sech[a+b x]^(m+2) Tanh[a+b x]^(n-2) \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[Sech[a_.+b_.*x_]^m_*Tanh[a_.+b_.*x_]^n_,x_Symbol] :=
  -Sech[a+b*x]^m*Tanh[a+b*x]^(n-1)/(b*m) +
  Dist[(n-1)/m,Int[Sech[a+b*x]^(m+2)*Tanh[a+b*x]^(n-2),x]] /;
FreeQ[{a,b},x] && RationalQ[{m,n}] && m<-1 && n>1 && Not[EvenQ[m]]


(* ::Subsubsection:: *)
(*Reference: G&R 2.411.1, CRC 567a*)


(* ::Code:: *)
Int[Csch[a_.+b_.*x_]^m_*Coth[a_.+b_.*x_]^n_,x_Symbol] :=
  -Csch[a+b*x]^m*Coth[a+b*x]^(n-1)/(b*m) -
  Dist[(n-1)/m,Int[Csch[a+b*x]^(m+2)*Coth[a+b*x]^(n-2),x]] /;
FreeQ[{a,b},x] && RationalQ[{m,n}] && m<-1 && n>1 && Not[EvenQ[m]]


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Reference: G&R 2.411.1, CRC 567a*)


(* ::Subsubsection:: *)
(*Rule: If  m+n+1=0, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]Sech[a+b x]^m Tanh[a+b x]^n \[DifferentialD]x  \[LongRightArrow]  -((Sech[a+b x]^m Tanh[a+b x]^(n+1))/(b m))*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[Sech[a_.+b_.*x_]^m_*Tanh[a_.+b_.*x_]^n_,x_Symbol] :=
  -Sech[a+b*x]^m*Tanh[a+b*x]^(n+1)/(b*m) /;
FreeQ[{a,b,m,n},x] && ZeroQ[m+n+1]


(* ::Subsubsection:: *)
(*Reference: G&R 2.411.2, CRC 567b*)


(* ::Code:: *)
Int[Csch[a_.+b_.*x_]^m_.*Coth[a_.+b_.*x_]^n_,x_Symbol] :=
  -Csch[a+b*x]^m*Coth[a+b*x]^(n+1)/(b*m) /;
FreeQ[{a,b,m,n},x] && ZeroQ[m+n+1]


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Rule: If  m<-1 \[And] m/2\[NotElement]\[DoubleStruckCapitalZ], then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]Sech[a+b x]^m Tanh[a+b x]^n \[DifferentialD]x  \[LongRightArrow]  -((Sech[a+b x]^m Tanh[a+b x]^(n+1))/(b m))+(m+n+1)/m \[Integral]Sech[a+b x]^(m+2) Tanh[a+b x]^n \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Inth[Sech[a_.+b_.*x_]^m_*Tanh[a_.+b_.*x_]^n_,x_Symbol] :=
  -Sech[a+b*x]^m*Tanh[a+b*x]^(n+1)/(b*m) +
  Dist[(m+n+1)/m,Int[Sech[a+b*x]^(m+2)*Tanh[a+b*x]^n,x]] /;
FreeQ[{a,b,n},x] && RationalQ[m] && m<-1 && Not[EvenQ[m]]


(* ::Code:: *)
Int[Csch[a_.+b_.*x_]^m_*Coth[a_.+b_.*x_]^n_,x_Symbol] :=
  -Csch[a+b*x]^m*Coth[a+b*x]^(n+1)/(b*m) -
  Dist[(m+n+1)/m,Int[Csch[a+b*x]^(m+2)*Coth[a+b*x]^n,x]] /;
FreeQ[{a,b,n},x] && RationalQ[m] && m<-1 && Not[EvenQ[m]]


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Reference: G&R 2.411.6, CRC 568b*)


(* ::Subsubsection:: *)
(*Rule: If  m>1 \[And] m+n-1!=0 \[And] m/2\[NotElement]\[DoubleStruckCapitalZ] \[And] (n-1)/2\[NotElement]\[DoubleStruckCapitalZ], then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]Sech[a+b x]^m Tanh[a+b x]^n \[DifferentialD]x  \[LongRightArrow]  ((Sech[a+b x]^(m-2) Tanh[a+b x]^(n+1))/(b (m+n-1)))+(m-2)/(m+n-1) \[Integral]Sech[a+b x]^(m-2) Tanh[a+b x]^n \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[Sech[a_.+b_.*x_]^m_*Tanh[a_.+b_.*x_]^n_,x_Symbol] :=
  Sech[a+b*x]^(m-2)*Tanh[a+b*x]^(n+1)/(b*(m+n-1)) +
  Dist[(m-2)/(m+n-1),Int[Sech[a+b*x]^(m-2)*Tanh[a+b*x]^n,x]] /;
FreeQ[{a,b,n},x] && RationalQ[m] && m>1 && NonzeroQ[m+n-1] && Not[EvenQ[m]] && Not[OddQ[n]]


(* ::Subsubsection:: *)
(*Reference: G&R 2.411.5, CRC 568a*)


(* ::Code:: *)
Int[Csch[a_.+b_.*x_]^m_*Coth[a_.+b_.*x_]^n_,x_Symbol] :=
  -Csch[a+b*x]^(m-2)*Coth[a+b*x]^(n+1)/(b*(m+n-1)) -
  Dist[(m-2)/(m+n-1),Int[Csch[a+b*x]^(m-2)*Coth[a+b*x]^n,x]] /;
FreeQ[{a,b,n},x] && RationalQ[m] && m>1 && NonzeroQ[m+n-1] && Not[EvenQ[m]] && Not[OddQ[n]]


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Reference: G&R 2.411.3*)


(* ::Subsubsection:: *)
(*Rule: If  n>1 \[And] m+n-1!=0 \[And] m/2\[NotElement]\[DoubleStruckCapitalZ] \[And] (n-1)/2\[NotElement]\[DoubleStruckCapitalZ], then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]Sech[a+b x]^m Tanh[a+b x]^n \[DifferentialD]x  \[LongRightArrow]  -((Sech[a+b x]^m Tanh[a+b x]^(n-1))/(b (m+n-1)))+(n-1)/(m+n-1) \[Integral]Sech[a+b x]^m Tanh[a+b x]^(n-2) \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[Sech[a_.+b_.*x_]^m_.*Tanh[a_.+b_.*x_]^n_,x_Symbol] :=
  -Sech[a+b*x]^m*Tanh[a+b*x]^(n-1)/(b*(m+n-1)) +
  Dist[(n-1)/(m+n-1),Int[Sech[a+b*x]^m*Tanh[a+b*x]^(n-2),x]] /;
FreeQ[{a,b,m},x] && RationalQ[n] && n>1 && NonzeroQ[m+n-1] && Not[EvenQ[m]] && Not[OddQ[n]]


(* ::Subsubsection:: *)
(*Reference: G&R 2.411.4*)


(* ::Code:: *)
Int[Csch[a_.+b_.*x_]^m_.*Coth[a_.+b_.*x_]^n_,x_Symbol] :=
  -Csch[a+b*x]^m*Coth[a+b*x]^(n-1)/(b*(m+n-1)) +
  Dist[(n-1)/(m+n-1),Int[Csch[a+b*x]^m*Coth[a+b*x]^(n-2),x]] /;
FreeQ[{a,b,m},x] && RationalQ[n] && n>1 && NonzeroQ[m+n-1] && Not[EvenQ[m]] && Not[OddQ[n]]


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Reference: G&R 2.411.4*)


(* ::Subsubsection:: *)
(*Rule: If  n<-1 \[And] m/2\[NotElement]\[DoubleStruckCapitalZ], then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]Sech[a+b x]^m Tanh[a+b x]^n \[DifferentialD]x  \[LongRightArrow]  ((Sech[a+b x]^m Tanh[a+b x]^(n+1))/(b (n+1)))+(m+n+1)/(n+1) \[Integral]Sech[a+b x]^m Tanh[a+b x]^(n+2) \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[Sech[a_.+b_.*x_]^m_*Tanh[a_.+b_.*x_]^n_,x_Symbol] :=
  Sech[a+b*x]^m*Tanh[a+b*x]^(n+1)/(b*(n+1)) +
  Dist[(m+n+1)/(n+1),Int[Sech[a+b*x]^m*Tanh[a+b*x]^(n+2),x]] /;
FreeQ[{a,b,m},x] && RationalQ[n] && n<-1 && Not[EvenQ[m]]


(* ::Subsubsection:: *)
(*Reference: G&R 2.411.3*)


(* ::Code:: *)
Int[Csch[a_.+b_.*x_]^m_.*Coth[a_.+b_.*x_]^n_,x_Symbol] :=
  Csch[a+b*x]^m*Coth[a+b*x]^(n+1)/(b*(n+1)) +
  Dist[(m+n+1)/(n+1),Int[Csch[a+b*x]^m*Coth[a+b*x]^(n+2),x]] /;
FreeQ[{a,b,m},x] && RationalQ[n] && n<-1 && Not[EvenQ[m]]


(* ::PageBreak:: *)
(**)


(* ::Title::Bold::Closed:: *)
(*\[Integral]x^m Sech[a+b x^n]^p Sinh[a+b x^n]\[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Derivation: Integration by parts*)


(* ::Subsubsection:: *)
(*Rule: If  n\[Element]\[DoubleStruckCapitalZ] \[And] m-n>=0 \[And] p-1!=0, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]x^m Sech[a+b x^n]^p Sinh[a+b x^n]\[DifferentialD]x  \[LongRightArrow]  -((x^(m-n+1) Sech[a+b x^n]^(p-1))/(b n (p-1)))+(m-n+1)/(b n (p-1)) \[Integral]x^(m-n) Sech[a+b x^n]^(p-1) \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[x_^m_.*Sech[a_.+b_.*x_^n_.]^p_*Sinh[a_.+b_.*x_^n_.],x_Symbol] :=
  -x^(m-n+1)*Sech[a+b*x^n]^(p-1)/(b*n*(p-1)) +
  Dist[(m-n+1)/(b*n*(p-1)),Int[x^(m-n)*Sech[a+b*x^n]^(p-1),x]] /;
FreeQ[{a,b,p},x] && RationalQ[m] && IntegerQ[n] && m-n>=0 && NonzeroQ[p-1]


(* ::Code:: *)
Int[x_^m_.*Csch[a_.+b_.*x_^n_.]^p_*Cosh[a_.+b_.*x_^n_.],x_Symbol] :=
  -x^(m-n+1)*Csch[a+b*x^n]^(p-1)/(b*n*(p-1)) +
  Dist[(m-n+1)/(b*n*(p-1)),Int[x^(m-n)*Csch[a+b*x^n]^(p-1),x]] /;
FreeQ[{a,b,p},x] && RationalQ[m] && IntegerQ[n] && m-n>=0 && NonzeroQ[p-1]


(* ::PageBreak:: *)
(**)


(* ::Title::Bold::Closed:: *)
(*\[Integral]x^m Sech[a+b x^n]^p Tanh[a+b x^n]\[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Derivation: Integration by parts*)


(* ::Subsubsection:: *)
(*Note: Dummy exponent q=1 required in program code so InputForm of integrand is recognized.*)


(* ::Subsubsection:: *)
(*Rule: If  n\[Element]\[DoubleStruckCapitalZ] \[And] m-n>=0, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]x^m Sech[a+b x^n]^p Tanh[a+b x^n]\[DifferentialD]x  \[LongRightArrow]  -((x^(m-n+1) Sech[a+b x^n]^p)/(b n p))+(m-n+1)/(b n p) \[Integral]x^(m-n) Sech[a+b x^n]^p \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[x_^m_.*Sech[a_.+b_.*x_^n_.]^p_.*Tanh[a_.+b_.*x_^n_.]^q_.,x_Symbol] :=
  -x^(m-n+1)*Sech[a+b*x^n]^p/(b*n*p) +
  Dist[(m-n+1)/(b*n*p),Int[x^(m-n)*Sech[a+b*x^n]^p,x]] /;
FreeQ[{a,b,p},x] && RationalQ[m] && IntegerQ[n] && m-n>=0 && q===1


(* ::Code:: *)
Int[x_^m_.*Csch[a_.+b_.*x_^n_.]^p_.*Coth[a_.+b_.*x_^n_.]^q_.,x_Symbol] :=
  -x^(m-n+1)*Csch[a+b*x^n]^p/(b*n*p) +
  Dist[(m-n+1)/(b*n*p),Int[x^(m-n)*Csch[a+b*x^n]^p,x]] /;
FreeQ[{a,b,p},x] && RationalQ[m] && IntegerQ[n] && m-n>=0 && q===1


(* ::PageBreak:: *)
(**)


(* ::Title::Bold::Closed:: *)
(*\[Integral]Sech[a+b Log[c x^n]]^p \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Derivation: Algebraic simplification*)


(* ::Subsubsection:: *)
(*Basis: Sech[b Log[c x^n]]=2/((c x^n)^b+1/(c x^n)^b)*)


(* ::Subsubsection:: *)
(*Rule:*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]Sech[b Log[c x^n]]^p \[DifferentialD]x  \[LongRightArrow]  \[Integral](2/((c x^n)^b+1/(c x^n)^b))^p \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[Sech[b_.*Log[c_.*x_^n_.]]^p_.,x_Symbol] :=
  Int[(2/((c*x^n)^b+1/(c*x^n)^b))^p,x] /;
FreeQ[c,x] && RationalQ[{b,n,p}]


(* ::Code:: *)
Int[Csch[b_.*Log[c_.*x_^n_.]]^p_.,x_Symbol] :=
  Int[(2/((c*x^n)^b - 1/(c*x^n)^b))^p,x] /;
FreeQ[c,x] && RationalQ[{b,n,p}]


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Rule: If  p-1!=0 \[And] b^2 n^2 (p-2)^2-1=0, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]Sech[a+b Log[c x^n]]^p \[DifferentialD]x  \[LongRightArrow]  *)
(*((x Tanh[a+b Log[c x^n]] Sech[a+b Log[c x^n]]^(p-2))/(b n (p-1)))+(x Sech[a+b Log[c x^n]]^(p-2))/(b^2 n^2 (p-1) (p-2))*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[Sech[a_.+b_.*Log[c_.*x_^n_.]]^p_,x_Symbol] :=
  x*Tanh[a+b*Log[c*x^n]]*Sech[a+b*Log[c*x^n]]^(p-2)/(b*n*(p-1)) + 
  x*Sech[a+b*Log[c*x^n]]^(p-2)/(b^2*n^2*(p-1)*(p-2)) /;
FreeQ[{a,b,c,n,p},x] && NonzeroQ[p-1] && ZeroQ[b^2*n^2*(p-2)^2-1]


(* ::Code:: *)
Int[Csch[a_.+b_.*Log[c_.*x_^n_.]]^p_,x_Symbol] :=
  -x*Coth[a+b*Log[c*x^n]]*Csch[a+b*Log[c*x^n]]^(p-2)/(b*n*(p-1)) -
  x*Csch[a+b*Log[c*x^n]]^(p-2)/(b^2*n^2*(p-1)*(p-2)) /;
FreeQ[{a,b,c,n,p},x] && NonzeroQ[p-1] && ZeroQ[b^2*n^2*(p-2)^2-1]


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Rule: If  p>1 \[And] p!=2 \[And] b^2 n^2 (p-2)^2-1!=0, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]Sech[a+b Log[c x^n]]^p \[DifferentialD]x  \[LongRightArrow]  ((x Tanh[a+b Log[c x^n]] Sech[a+b Log[c x^n]]^(p-2))/(b n (p-1)))+*)
(*(x Sech[a+b Log[c x^n]]^(p-2))/(b^2 n^2 (p-1) (p-2))+(b^2 n^2 (p-2)^2-1)/(b^2 n^2 (p-1) (p-2)) \[Integral]Sech[a+b Log[c x^n]]^(p-2) \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[Sech[a_.+b_.*Log[c_.*x_^n_.]]^p_,x_Symbol] :=
  x*Tanh[a+b*Log[c*x^n]]*Sech[a+b*Log[c*x^n]]^(p-2)/(b*n*(p-1)) +
  x*Sech[a+b*Log[c*x^n]]^(p-2)/(b^2*n^2*(p-1)*(p-2)) +
  Dist[(b^2*n^2*(p-2)^2-1)/(b^2*n^2*(p-1)*(p-2)),Int[Sech[a+b*Log[c*x^n]]^(p-2),x]] /;
FreeQ[{a,b,c,n},x] && RationalQ[p] && p>1 && p!=2 && NonzeroQ[b^2*n^2*(p-2)^2-1]


(* ::Code:: *)
Int[Csch[a_.+b_.*Log[c_.*x_^n_.]]^p_,x_Symbol] :=
  -x*Coth[a+b*Log[c*x^n]]*Csch[a+b*Log[c*x^n]]^(p-2)/(b*n*(p-1)) -
  x*Csch[a+b*Log[c*x^n]]^(p-2)/(b^2*n^2*(p-1)*(p-2)) -
  Dist[(b^2*n^2*(p-2)^2-1)/(b^2*n^2*(p-1)*(p-2)),Int[Csch[a+b*Log[c*x^n]]^(p-2),x]] /;
FreeQ[{a,b,c,n},x] && RationalQ[p] && p>1 && p!=2 && NonzeroQ[b^2*n^2*(p-2)^2-1]


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Rule: If  p<-1 \[And] b^2 n^2 p^2-1!=0, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]Sech[a+b Log[c x^n]]^p \[DifferentialD]x  \[LongRightArrow]  -((b n p x Sinh[a+b Log[c x^n]]Sech[a+b Log[c x^n]]^(p+1))/(b^2 n^2 p^2-1))-*)
(*(x Sech[a+b Log[c x^n]]^p)/(b^2 n^2 p^2-1)+(b^2 n^2 p (p+1))/(b^2 n^2 p^2-1) \[Integral]Sech[a+b Log[c x^n]]^(p+2) \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[Sech[a_.+b_.*Log[c_.*x_^n_.]]^p_,x_Symbol] :=
  -b*n*p*x*Sech[a+b*Log[c*x^n]]^(p+1)*Sinh[a+b*Log[c*x^n]]/(b^2*n^2*p^2-1) -
  x*Sech[a+b*Log[c*x^n]]^p/(b^2*n^2*p^2-1) +
  Dist[b^2*n^2*p*(p+1)/(b^2*n^2*p^2-1),Int[Sech[a+b*Log[c*x^n]]^(p+2),x]] /;
FreeQ[{a,b,c,n},x] && RationalQ[p] && p<-1 && NonzeroQ[b^2*n^2*p^2-1]


(* ::Code:: *)
Int[Csch[a_.+b_.*Log[c_.*x_^n_.]]^p_,x_Symbol] :=
  -b*n*p*x*Cosh[a+b*Log[c*x^n]]*Csch[a+b*Log[c*x^n]]^(p+1)/(b^2*n^2*p^2-1) - 
  x*Csch[a+b*Log[c*x^n]]^p/(b^2*n^2*p^2-1) -
  Dist[b^2*n^2*p*(p+1)/(b^2*n^2*p^2-1),Int[Csch[a+b*Log[c*x^n]]^(p+2),x]] /;
FreeQ[{a,b,c,n},x] && RationalQ[p] && p<-1 && NonzeroQ[b^2*n^2*p^2-1]


(* ::PageBreak:: *)
(**)


(* ::Title::Bold::Closed:: *)
(*\[Integral]x^m Sech[a+b Log[c x^n]]^p \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Derivation: Algebraic simplification*)


(* ::Subsubsection:: *)
(*Basis: Sech[b Log[c x^n]]=2/((c x^n)^b+1/(c x^n)^b)*)


(* ::Subsubsection:: *)
(*Rule:*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]x^m Sech[b Log[c x^n]]^p \[DifferentialD]x  \[LongRightArrow]  \[Integral]x^m (2/((c x^n)^b+1/(c x^n)^b))^p \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[x_^m_.Sech[b_.*Log[c_.*x_^n_.]]^p_.,x_Symbol] :=
  Int[x^m*(2/((c*x^n)^b+1/(c*x^n)^b))^p,x] /;
FreeQ[c,x] && RationalQ[{b,m,n,p}]


(* ::Code:: *)
Int[x_^m_.*Csch[b_.*Log[c_.*x_^n_.]]^p_.,x_Symbol] :=
  Int[x^m*(2/((c*x^n)^b - 1/(c*x^n)^b))^p,x] /;
FreeQ[c,x] && RationalQ[{b,m,n,p}]


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Rule: If  m+1!=0 \[And] p-1!=0 \[And] b^2 n^2 (p-2)^2+(m+1)^2=0, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]x^m Sech[a+b Log[c x^n]]^p \[DifferentialD]x  \[LongRightArrow]  ((x^(m+1) (b n (p-2)+(m+1) Tanh[a+b Log[c x^n]])Sech[a+b Log[c x^n]]^(p-2))/(b n(m+1)(p-1)))*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[x_^m_.*Sec[a_.+b_.*Log[c_.*x_^n_.]]^p_,x_Symbol] :=
  x^(m+1)*(b*n*(p-2)+(m+1)*Tan[a+b*Log[c*x^n]])*Sec[a+b*Log[c*x^n]]^(p-2)/(b*n*(m+1)*(p-1)) /;
FreeQ[{a,b,c,m,n,p},x] && NonzeroQ[m+1] && NonzeroQ[p-1] && ZeroQ[b^2*n^2*(p-2)^2+(m+1)^2]


(* ::Code:: *)
Int[x_^m_.*Csc[a_.+b_.*Log[c_.*x_^n_.]]^p_,x_Symbol] :=
  x^(m+1)*(b*n*(p-2)-(m+1)*Cot[a+b*Log[c*x^n]])*Csc[a+b*Log[c*x^n]]^(p-2)/(b*n*(m+1)*(p-1)) /;
FreeQ[{a,b,c,m,n,p},x] && NonzeroQ[m+1] && NonzeroQ[p-1] && ZeroQ[b^2*n^2*(p-2)^2+(m+1)^2]


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Rule: If  p>1 \[And] p!=2 \[And] b^2 n^2 (p-2)^2-(m+1)^2!=0, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]x^m Sech[a+b Log[c x^n]]^p \[DifferentialD]x  \[LongRightArrow]  ((x^(m+1) Tanh[a+b Log[c x^n]] Sech[a+b Log[c x^n]]^(p-2))/(b n (p-1)))+*)
(*((m+1) x^(m+1) Sech[a+b Log[c x^n]]^(p-2))/(b^2 n^2 (p-1) (p-2))+(b^2 n^2 (p-2)^2-(m+1)^2)/(b^2 n^2 (p-1)(p-2)) \[Integral]x^m Sech[a+b Log[c x^n]]^(p-2) \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[x_^m_.*Sech[a_.+b_.*Log[c_.*x_^n_.]]^p_,x_Symbol] :=
  x^(m+1)*Tanh[a+b*Log[c*x^n]]*Sech[a+b*Log[c*x^n]]^(p-2)/(b*n*(p-1)) +
  (m+1)*x^(m+1)*Sech[a+b*Log[c*x^n]]^(p-2)/(b^2*n^2*(p-1)*(p-2)) +
  Dist[(b^2*n^2*(p-2)^2-(m+1)^2)/(b^2*n^2*(p-1)*(p-2)),Int[x^m*Sech[a+b*Log[c*x^n]]^(p-2),x]] /;
FreeQ[{a,b,c,m,n},x] && RationalQ[p] && p>1 && p!=2 && NonzeroQ[b^2*n^2*(p-2)^2-(m+1)^2]


(* ::Code:: *)
Int[x_^m_.*Csch[a_.+b_.*Log[c_.*x_^n_.]]^p_,x_Symbol] :=
  -x^(m+1)*Coth[a+b*Log[c*x^n]]*Csch[a+b*Log[c*x^n]]^(p-2)/(b*n*(p-1)) -
  (m+1)*x^(m+1)*Csch[a+b*Log[c*x^n]]^(p-2)/(b^2*n^2*(p-1)*(p-2)) -
  Dist[(b^2*n^2*(p-2)^2-(m+1)^2)/(b^2*n^2*(p-1)*(p-2)),Int[x^m*Csch[a+b*Log[c*x^n]]^(p-2),x]] /;
FreeQ[{a,b,c,m,n},x] && RationalQ[p] && p>1 && p!=2 && NonzeroQ[b^2*n^2*(p-2)^2-(m+1)^2]


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Rule: If  p<-1 \[And] b^2 n^2 p^2-(m+1)^2!=0, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]x^m Sech[a+b Log[c x^n]]^p \[DifferentialD]x  \[LongRightArrow]  -((b n p x^(m+1) Sinh[a+b Log[c x^n]]Sech[a+b Log[c x^n]]^(p+1))/(b^2 n^2 p^2-(m+1)^2))-*)
(* ((m+1) x^(m+1) Sech[a+b Log[c x^n]]^p)/(b^2 n^2 p^2-(m+1)^2)+(b^2 n^2 p (p+1))/(b^2 n^2 p^2-(m+1)^2) \[Integral]x^m Sech[a+b Log[c x^n]]^(p+2) \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[x_^m_.*Sech[a_.+b_.*Log[c_.*x_^n_.]]^p_,x_Symbol] :=
  -(m+1)*x^(m+1)*Sech[a+b*Log[c*x^n]]^p/(b^2*n^2*p^2-(m+1)^2) -
  b*n*p*x^(m+1)*Sech[a+b*Log[c*x^n]]^(p+1)*Sinh[a+b*Log[c*x^n]]/(b^2*n^2*p^2-(m+1)^2) +
  Dist[b^2*n^2*p*(p+1)/(b^2*n^2*p^2-(m+1)^2),Int[x^m*Sech[a+b*Log[c*x^n]]^(p+2),x]] /;
FreeQ[{a,b,c,m,n},x] && RationalQ[p] && p<-1 && NonzeroQ[b^2*n^2*p^2-(m+1)^2]


(* ::Code:: *)
Int[x_^m_.*Csch[a_.+b_.*Log[c_.*x_^n_.]]^p_,x_Symbol] :=
  -(m+1)*x^(m+1)*Csch[a+b*Log[c*x^n]]^p/(b^2*n^2*p^2-(m+1)^2) -
  b*n*p*x^(m+1)*Cosh[a+b*Log[c*x^n]]*Csch[a+b*Log[c*x^n]]^(p+1)/(b^2*n^2*p^2-(m+1)^2) -
  Dist[b^2*n^2*p*(p+1)/(b^2*n^2*p^2-(m+1)^2),Int[x^m*Csch[a+b*Log[c*x^n]]^(p+2),x]] /;
FreeQ[{a,b,c,m,n},x] && RationalQ[p] && p<-1 && NonzeroQ[b^2*n^2*p^2-(m+1)^2]


(* ::PageBreak:: *)
(**)
