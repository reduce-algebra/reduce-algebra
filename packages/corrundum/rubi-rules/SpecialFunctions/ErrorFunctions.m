(* ::Package:: *)

(* ::Title::Bold::Closed:: *)
(*\[Integral]Erf[a+b x]^n \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Reference: G&R 5.41*)


(* ::Subsubsection:: *)
(*Derivation: Integration by parts*)


(* ::Subsubsection:: *)
(*Rule:*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]Erf[a+b x]\[DifferentialD]x  \[LongRightArrow]  (((a+b x) Erf[a+b x])/b)+1/(b Sqrt[\[Pi]] E^(a+b x)^2)*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[Erf[a_.+b_.*x_],x_Symbol] :=
  (a+b*x)*Erf[a+b*x]/b + 1/(b*Sqrt[Pi]*E^(a+b*x)^2) /;
FreeQ[{a,b},x]


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Derivation: Integration by parts*)


(* ::Subsubsection:: *)
(*Rule:*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]Erf[a+b x]^2 \[DifferentialD]x  \[LongRightArrow]  (((a+b x) Erf[a+b x]^2)/b)-4/Sqrt[\[Pi]] \[Integral]((a+b x) Erf[a+b x])/E^(a+b x)^2 \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[Erf[a_.+b_.*x_]^2,x_Symbol] :=
  (a+b*x)*Erf[a+b*x]^2/b -
  Dist[4/Sqrt[Pi],Int[(a+b*x)*Erf[a+b*x]/E^(a+b*x)^2,x]] /;
FreeQ[{a,b},x]


(* ::PageBreak:: *)
(**)


(* ::Title::Bold::Closed:: *)
(*\[Integral]x^m Erf[a+b x]^n \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Derivation: Integration by parts*)


(* ::Subsubsection:: *)
(*Rule: If  m+1!=0, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]x^m Erf[a+b x]\[DifferentialD]x  \[LongRightArrow]  ((x^(m+1) Erf[a+b x])/(m+1))-(2 b)/(Sqrt[\[Pi]] (m+1)) \[Integral]x^(m+1)/E^(a+b x)^2 \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[x_^m_.*Erf[a_.+b_.*x_],x_Symbol] :=
  x^(m+1)*Erf[a+b*x]/(m+1) -
  Dist[2*b/(Sqrt[Pi]*(m+1)),Int[x^(m+1)/E^(a+b*x)^2,x]] /;
FreeQ[{a,b,m},x] && NonzeroQ[m+1]


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Derivation: Integration by parts*)


(* ::Subsubsection:: *)
(*Rule: If  m\[Element]\[DoubleStruckCapitalZ] \[And] m+1!=0 \[And] (m>0 \[Or] (m-1)/2\[Element]\[DoubleStruckCapitalZ]), then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]x^m Erf[b x]^2 \[DifferentialD]x  \[LongRightArrow]  ((x^(m+1) Erf[b x]^2)/(m+1))-(4 b)/(Sqrt[\[Pi]] (m+1)) \[Integral](x^(m+1) Erf[b x])/E^(b^2 x^2) \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[x_^m_.*Erf[b_.*x_]^2,x_Symbol] :=
  x^(m+1)*Erf[b*x]^2/(m+1) -
  Dist[4*b/(Sqrt[Pi]*(m+1)),Int[x^(m+1)*E^(-b^2*x^2)*Erf[b*x],x]] /;
FreeQ[b,x] && IntegerQ[m] && m+1!=0 && (m>0 || OddQ[m])


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Derivation: Integration by substitution*)


(* ::Subsubsection:: *)
(*Basis: x^m f[a+b x]=1/b (-(a/b)+(a+b x)/b)^m f[a+b x] \!\( *)
(*\*SubscriptBox[\(\[PartialD]\), \(x\)]\((a + b\ x)\)\)*)


(* ::Subsubsection:: *)
(*Rule: If  m\[Element]\[DoubleStruckCapitalZ] \[And] m>0, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]x^m Erf[a+b x]^2 \[DifferentialD]x  \[LongRightArrow]  (1/b) Subst[\[Integral](-(a/b)+x/b)^m Erf[x]^2 \[DifferentialD]x,x,a+b x]*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[x_^m_.*Erf[a_+b_.*x_]^2,x_Symbol] :=
  Dist[1/b,Subst[Int[(-a/b+x/b)^m*Erf[x]^2,x],x,a+b*x]] /;
FreeQ[{a,b},x] && IntegerQ[m] && m>0


(* ::PageBreak:: *)
(**)


(* ::Title::Bold::Closed:: *)
(*\[Integral](x^m Erf[b x])/E^(b^2 x^2) \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Derivation: Integration by parts special case*)


(* ::Subsubsection:: *)
(*Rule:*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral](x Erf[b x])/E^(b^2 x^2) \[DifferentialD]x  \[LongRightArrow]  -(Erf[b x]/(2 b^2 E^(b^2 x^2)))+1/(b Sqrt[\[Pi]]) \[Integral]1/E^(2 b^2 x^2) \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[x_*E^(c_.*x_^2)*Erf[b_.*x_],x_Symbol] :=
  -E^(-b^2*x^2)*Erf[b*x]/(2*b^2) +
  Dist[1/(b*Sqrt[Pi]),Int[E^(-2*b^2*x^2),x]] /;
FreeQ[{b,c},x] && ZeroQ[c+b^2]


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Derivation: Integration by parts*)


(* ::Subsubsection:: *)
(*Rule: If  m\[Element]\[DoubleStruckCapitalZ] \[And] m>1, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral](x^m Erf[b x])/E^(b^2 x^2) \[DifferentialD]x  \[LongRightArrow]  -((x^(m-1) Erf[b x])/(2 b^2 E^(b^2 x^2)))+1/(b Sqrt[\[Pi]]) \[Integral]x^(m-1)/E^(2 b^2 x^2) \[DifferentialD]x+(m-1)/(2 b^2) \[Integral](x^(m-2) Erf[b x])/E^(b^2 x^2) \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[x_^m_*E^(c_.*x_^2)*Erf[b_.*x_],x_Symbol] :=
  -x^(m-1)*E^(-b^2*x^2)*Erf[b*x]/(2*b^2) +
  Dist[1/(b*Sqrt[Pi]),Int[x^(m-1)*E^(-2*b^2*x^2),x]] +
  Dist[(m-1)/(2*b^2),Int[x^(m-2)*E^(-b^2*x^2)*Erf[b*x],x]] /;
FreeQ[{b,c},x] && ZeroQ[c+b^2] && IntegerQ[m] && m>1


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Derivation: Inverted integration by parts*)


(* ::Subsubsection:: *)
(*Rule: If  m/2\[Element]\[DoubleStruckCapitalZ] \[And] m<-1, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral](x^m Erf[b x])/E^(b^2 x^2) \[DifferentialD]x  \[LongRightArrow]  ((x^(m+1) Erf[b x])/(E^(b^2 x^2) (m+1)))-(2 b)/(Sqrt[\[Pi]] (m+1)) \[Integral]x^(m+1)/E^(2 b^2 x^2) \[DifferentialD]x+(2 b^2)/(m+1) \[Integral](x^(m+2) Erf[b x])/E^(b^2 x^2) \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[x_^m_*E^(c_.*x_^2)*Erf[b_.*x_],x_Symbol] :=
  x^(m+1)*E^(-b^2*x^2)*Erf[b*x]/(m+1) -
  Dist[2*b/(Sqrt[Pi]*(m+1)),Int[x^(m+1)*E^(-2*b^2*x^2),x]] +
  Dist[2*b^2/(m+1),Int[x^(m+2)*E^(-b^2*x^2)*Erf[b*x],x]] /;
FreeQ[{b,c},x] && ZeroQ[c+b^2] && EvenQ[m] && m<-1


(* ::PageBreak:: *)
(**)


(* ::Title::Bold::Closed:: *)
(*\[Integral]Erfc[a+b x]^n \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Derivation: Integration by parts*)


(* ::Subsubsection:: *)
(*Rule:*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]Erfc[a+b x]\[DifferentialD]x  \[LongRightArrow]  (((a+b x) Erfc[a+b x])/b)-1/(b Sqrt[\[Pi]] E^(a+b x)^2)*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[Erfc[a_.+b_.*x_],x_Symbol] :=
  (a+b*x)*Erfc[a+b*x]/b - 1/(b*Sqrt[Pi]*E^(a+b*x)^2) /;
FreeQ[{a,b},x]


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Derivation: Integration by parts*)


(* ::Subsubsection:: *)
(*Rule:*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]Erfc[a+b x]^2 \[DifferentialD]x  \[LongRightArrow]  (((a+b x) Erfc[a+b x]^2)/b)+4/Sqrt[\[Pi]] \[Integral]((a+b x) Erfc[a+b x])/E^(a+b x)^2 \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[Erfc[a_.+b_.*x_]^2,x_Symbol] :=
  (a+b*x)*Erfc[a+b*x]^2/b +
  Dist[4/Sqrt[Pi],Int[(a+b*x)*Erfc[a+b*x]/E^(a+b*x)^2,x]] /;
FreeQ[{a,b},x]


(* ::PageBreak:: *)
(**)


(* ::Title::Bold::Closed:: *)
(*\[Integral]x^m Erfc[a+b x]^n \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Derivation: Integration by parts*)


(* ::Subsubsection:: *)
(*Rule: If  m+1!=0, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]x^m Erfc[a+b x]\[DifferentialD]x  \[LongRightArrow]  ((x^(m+1) Erfc[a+b x])/(m+1))+(2 b)/(Sqrt[\[Pi]] (m+1)) \[Integral]x^(m+1)/E^(a+b x)^2 \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[x_^m_.*Erfc[a_.+b_.*x_],x_Symbol] :=
  x^(m+1)*Erfc[a+b*x]/(m+1) +
  Dist[2*b/(Sqrt[Pi]*(m+1)),Int[x^(m+1)/E^(a+b*x)^2,x]] /;
FreeQ[{a,b,m},x] && NonzeroQ[m+1]


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Derivation: Integration by parts*)


(* ::Subsubsection:: *)
(*Rule: If  m\[Element]\[DoubleStruckCapitalZ] \[And] m+1!=0 \[And] (m>0 \[Or] (m-1)/2\[Element]\[DoubleStruckCapitalZ]), then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]x^m Erfc[b x]^2 \[DifferentialD]x  \[LongRightArrow]  ((x^(m+1) Erfc[b x]^2)/(m+1))+(4 b)/(Sqrt[\[Pi]] (m+1)) \[Integral](x^(m+1) Erfc[b x])/E^(b^2 x^2) \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[x_^m_.*Erfc[b_.*x_]^2,x_Symbol] :=
  x^(m+1)*Erfc[b*x]^2/(m+1) +
  Dist[4*b/(Sqrt[Pi]*(m+1)),Int[x^(m+1)*E^(-b^2*x^2)*Erfc[b*x],x]] /;
FreeQ[b,x] && IntegerQ[m] && m+1!=0 && (m>0 || OddQ[m])


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Derivation: Integration by substitution*)


(* ::Subsubsection:: *)
(*Basis: x^m f[a+b x]=1/b (-(a/b)+(a+b x)/b)^m f[a+b x] \!\( *)
(*\*SubscriptBox[\(\[PartialD]\), \(x\)]\((a + b\ x)\)\)*)


(* ::Subsubsection:: *)
(*Rule: If  m\[Element]\[DoubleStruckCapitalZ] \[And] m>0, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]x^m Erfc[a+b x]^2 \[DifferentialD]x  \[LongRightArrow]  (1/b) Subst[\[Integral](-(a/b)+x/b)^m Erfc[x]^2 \[DifferentialD]x,x,a+b x]*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[x_^m_.*Erfc[a_+b_.*x_]^2,x_Symbol] :=
  Dist[1/b,Subst[Int[(-a/b+x/b)^m*Erfc[x]^2,x],x,a+b*x]] /;
FreeQ[{a,b},x] && IntegerQ[m] && m>0


(* ::PageBreak:: *)
(**)


(* ::Title::Bold::Closed:: *)
(*\[Integral](x^m Erfc[b x])/E^(b^2 x^2) \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Derivation: Integration by parts special case*)


(* ::Subsubsection:: *)
(*Rule:*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral](x Erfc[b x])/E^(b^2 x^2) \[DifferentialD]x  \[LongRightArrow]  -(Erfc[b x]/(2 b^2 E^(b^2 x^2)))-1/(b Sqrt[\[Pi]]) \[Integral]1/E^(2 b^2 x^2) \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[x_*E^(c_.*x_^2)*Erfc[b_.*x_],x_Symbol] :=
  -E^(-b^2*x^2)*Erfc[b*x]/(2*b^2) -
  Dist[1/(b*Sqrt[Pi]),Int[E^(-2*b^2*x^2),x]] /;
FreeQ[{b,c},x] && ZeroQ[c+b^2]


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Derivation: Integration by parts*)


(* ::Subsubsection:: *)
(*Rule: If  m\[Element]\[DoubleStruckCapitalZ] \[And] m>1, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral](x^m Erfc[b x])/E^(b^2 x^2) \[DifferentialD]x  \[LongRightArrow]  -((x^(m-1) Erfc[b x])/(2 b^2 E^(b^2 x^2)))-1/(b Sqrt[\[Pi]]) \[Integral]x^(m-1)/E^(2 b^2 x^2) \[DifferentialD]x+(m-1)/(2 b^2) \[Integral](x^(m-2) Erfc[b x])/E^(b^2 x^2) \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[x_^m_*E^(c_.*x_^2)*Erfc[b_.*x_],x_Symbol] :=
  -x^(m-1)*E^(-b^2*x^2)*Erfc[b*x]/(2*b^2) -
  Dist[1/(b*Sqrt[Pi]),Int[x^(m-1)*E^(-2*b^2*x^2),x]] +
  Dist[(m-1)/(2*b^2),Int[x^(m-2)*E^(-b^2*x^2)*Erfc[b*x],x]] /;
FreeQ[{b,c},x] && ZeroQ[c+b^2] && IntegerQ[m] && m>1


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Derivation: Inverted integration by parts*)


(* ::Subsubsection:: *)
(*Rule: If  m/2\[Element]\[DoubleStruckCapitalZ] \[And] m<-1, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral](x^m Erfc[b x])/E^(b^2 x^2) \[DifferentialD]x  \[LongRightArrow]  ((x^(m+1) Erfc[b x])/(E^(b^2 x^2) (m+1)))+(2 b)/(Sqrt[\[Pi]] (m+1)) \[Integral]x^(m+1)/E^(2 b^2 x^2) \[DifferentialD]x+(2 b^2)/(m+1) \[Integral](x^(m+2) Erfc[b x])/E^(b^2 x^2) \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[x_^m_*E^(c_.*x_^2)*Erfc[b_.*x_],x_Symbol] :=
  x^(m+1)*E^(-b^2*x^2)*Erfc[b*x]/(m+1) +
  Dist[2*b/(Sqrt[Pi]*(m+1)),Int[x^(m+1)*E^(-2*b^2*x^2),x]] +
  Dist[2*b^2/(m+1),Int[x^(m+2)*E^(-b^2*x^2)*Erfc[b*x],x]] /;
FreeQ[{b,c},x] && ZeroQ[c+b^2] && EvenQ[m] && m<-1


(* ::PageBreak:: *)
(**)


(* ::Title::Bold::Closed:: *)
(*\[Integral]Erfi[a+b x]^n \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Derivation: Integration by parts*)


(* ::Subsubsection:: *)
(*Rule:*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]Erfi[a+b x]\[DifferentialD]x  \[LongRightArrow]  (((a+b x) Erfi[a+b x])/b)-E^(a+b x)^2/(b Sqrt[\[Pi]])*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[Erfi[a_.+b_.*x_],x_Symbol] :=
  (a+b*x)*Erfi[a+b*x]/b - E^(a+b*x)^2/(b*Sqrt[Pi]) /;
FreeQ[{a,b},x]


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Derivation: Integration by parts*)


(* ::Subsubsection:: *)
(*Rule:*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]Erfi[a+b x]^2 \[DifferentialD]x  \[LongRightArrow]  (((a+b x) Erfi[a+b x]^2)/b)-4/Sqrt[\[Pi]] \[Integral](a+b x) E^(a+b x)^2 Erfi[a+b x]\[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[Erfi[a_.+b_.*x_]^2,x_Symbol] :=
  (a+b*x)*Erfi[a+b*x]^2/b -
  Dist[4/Sqrt[Pi],Int[(a+b*x)*E^(a+b*x)^2*Erfi[a+b*x],x]] /;
FreeQ[{a,b},x]


(* ::PageBreak:: *)
(**)


(* ::Title::Bold::Closed:: *)
(*\[Integral]x^m Erfi[a+b x]^n \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Derivation: Integration by parts*)


(* ::Subsubsection:: *)
(*Rule: If  m+1!=0, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]x^m Erfi[a+b x]\[DifferentialD]x  \[LongRightArrow]  ((x^(m+1) Erfi[a+b x])/(m+1))-(2 b)/(Sqrt[\[Pi]] (m+1)) \[Integral]x^(m+1) E^(a+b x)^2 \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[x_^m_.*Erfi[a_.+b_.*x_],x_Symbol] :=
  x^(m+1)*Erfi[a+b*x]/(m+1) -
  Dist[2*b/(Sqrt[Pi]*(m+1)),Int[x^(m+1)*E^(a+b*x)^2,x]] /;
FreeQ[{a,b,m},x] && NonzeroQ[m+1]


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Derivation: Integration by parts*)


(* ::Subsubsection:: *)
(*Rule: If  m\[Element]\[DoubleStruckCapitalZ] \[And] m+1!=0 \[And] (m>0 \[Or] (m-1)/2\[Element]\[DoubleStruckCapitalZ]), then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]x^m Erfi[b x]^2 \[DifferentialD]x  \[LongRightArrow]  ((x^(m+1) Erfi[b x]^2)/(m+1))-(4 b)/(Sqrt[\[Pi]] (m+1)) \[Integral]x^(m+1) E^(b^2 x^2) Erfi[b x]\[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[x_^m_.*Erfi[b_.*x_]^2,x_Symbol] :=
  x^(m+1)*Erfi[b*x]^2/(m+1) -
  Dist[4*b/(Sqrt[Pi]*(m+1)),Int[x^(m+1)*E^(b^2*x^2)*Erfi[b*x],x]] /;
FreeQ[b,x] && IntegerQ[m] && m+1!=0 && (m>0 || OddQ[m])


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Derivation: Integration by substitution*)


(* ::Subsubsection:: *)
(*Basis: x^m f[a+b x]=1/b (-(a/b)+(a+b x)/b)^m f[a+b x] \!\( *)
(*\*SubscriptBox[\(\[PartialD]\), \(x\)]\((a + b\ x)\)\)*)


(* ::Subsubsection:: *)
(*Rule: If  m\[Element]\[DoubleStruckCapitalZ] \[And] m>0, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]x^m Erfi[a+b x]^2 \[DifferentialD]x  \[LongRightArrow]  (1/b) Subst[\[Integral](-(a/b)+x/b)^m Erfi[x]^2 \[DifferentialD]x,x,a+b x]*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[x_^m_.*Erfi[a_+b_.*x_]^2,x_Symbol] :=
  Dist[1/b,Subst[Int[(-a/b+x/b)^m*Erfi[x]^2,x],x,a+b*x]] /;
FreeQ[{a,b},x] && IntegerQ[m] && m>0


(* ::PageBreak:: *)
(**)


(* ::Title::Bold::Closed:: *)
(*\[Integral](x^m Erfi[b x])/E^(b^2 x^2) \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Derivation: Integration by parts special case*)


(* ::Subsubsection:: *)
(*Rule:*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]x E^(b^2 x^2) Erfi[b x]\[DifferentialD]x  \[LongRightArrow]  ((E^(b^2 x^2) Erfi[b x])/(2 b^2))-1/(b Sqrt[\[Pi]]) \[Integral]E^(2 b^2 x^2) \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[x_*E^(c_.*x_^2)*Erfi[b_.*x_],x_Symbol] :=
  E^(b^2*x^2)*Erfi[b*x]/(2*b^2) -
  Dist[1/(b*Sqrt[Pi]),Int[E^(2*b^2*x^2),x]] /;
FreeQ[{b,c},x] && ZeroQ[c-b^2]


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Derivation: Integration by parts*)


(* ::Subsubsection:: *)
(*Rule: If  m\[Element]\[DoubleStruckCapitalZ] \[And] m>1, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]x^m E^(b^2 x^2) Erfi[b x]\[DifferentialD]x  \[LongRightArrow]  ((x^(m-1) E^(b^2 x^2) Erfi[b x])/(2 b^2))-1/(b Sqrt[\[Pi]]) \[Integral]x^(m-1) E^(2 b^2 x^2) \[DifferentialD]x-(m-1)/(2 b^2) \[Integral]x^(m-2) E^(b^2 x^2) Erfi[b x]\[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[x_^m_*E^(c_.*x_^2)*Erfi[b_.*x_],x_Symbol] :=
  x^(m-1)*E^(b^2*x^2)*Erfi[b*x]/(2*b^2) -
  Dist[1/(b*Sqrt[Pi]),Int[x^(m-1)*E^(2*b^2*x^2),x]] -
  Dist[(m-1)/(2*b^2),Int[x^(m-2)*E^(b^2*x^2)*Erfi[b*x],x]] /;
FreeQ[{b,c},x] && ZeroQ[c-b^2] && IntegerQ[m] && m>1


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Derivation: Inverted integration by parts*)


(* ::Subsubsection:: *)
(*Rule: If  m/2\[Element]\[DoubleStruckCapitalZ] \[And] m<-1, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]x^m E^(b^2 x^2) Erfi[b x]\[DifferentialD]x  \[LongRightArrow]  ((x^(m+1) E^(b^2 x^2) Erfi[b x])/(m+1))-(2 b)/(Sqrt[\[Pi]] (m+1)) \[Integral]x^(m+1) E^(2 b^2 x^2) \[DifferentialD]x-(2 b^2)/(m+1) \[Integral]x^(m+2) E^(b^2 x^2) Erfi[b x]\[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[x_^m_*E^(c_.*x_^2)*Erfi[b_.*x_],x_Symbol] :=
  x^(m+1)*E^(b^2*x^2)*Erfi[b*x]/(m+1) -
  Dist[2*b/(Sqrt[Pi]*(m+1)),Int[x^(m+1)*E^(2*b^2*x^2),x]] -
  Dist[2*b^2/(m+1),Int[x^(m+2)*E^(b^2*x^2)*Erfi[b*x],x]] /;
FreeQ[{b,c},x] && ZeroQ[c-b^2] && EvenQ[m] && m<-1


(* ::PageBreak:: *)
(**)
