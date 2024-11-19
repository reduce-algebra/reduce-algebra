(* ::Package:: *)

(* ::Title::Bold::Closed:: *)
(*\[Integral]Zeta[s,a+b x]\[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Derivation: Algebraic simplification*)


(* ::Subsubsection:: *)
(*Basis: Zeta[2,z]=PolyGamma[1,z]*)


(* ::Subsubsection:: *)
(*Rule:*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]Zeta[2,a+b x]\[DifferentialD]x  \[LongRightArrow]  \[Integral]PolyGamma[1,a+b x]\[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[Zeta[2,a_.+b_.*x_],x_Symbol] :=
  Int[PolyGamma[1,a+b*x],x] /;
FreeQ[{a,b},x]


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Derivation: Primitive rule*)


(* ::Subsubsection:: *)
(*Basis: \[PartialD]Zeta[s,z]/\[PartialD]z=-s Zeta[s+1,z]*)


(* ::Subsubsection:: *)
(*Rule: If  s!=1 \[And] s!=2, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]Zeta[s,a+b x]\[DifferentialD]x  \[LongRightArrow]  -(Zeta[s-1,a+b x]/(b (s-1)))*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[Zeta[s_,a_.+b_.*x_],x_Symbol] :=
  -Zeta[s-1,a+b*x]/(b*(s-1)) /;
FreeQ[{a,b,s},x] && NonzeroQ[s-1] && NonzeroQ[s-2]


(* ::PageBreak:: *)
(**)


(* ::Title::Bold::Closed:: *)
(*\[Integral]x^m Zeta[s,a+b x]\[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Derivation: Algebraic simplification*)


(* ::Subsubsection:: *)
(*Basis: Zeta[2,z]=PolyGamma[1,z]*)


(* ::Subsubsection:: *)
(*Rule: If  m\[Element]\[DoubleStruckCapitalQ], then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]x^m Zeta[2,a+b x]\[DifferentialD]x  \[LongRightArrow]  \[Integral]x^m PolyGamma[1,a+b x]\[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[x_^m_.*Zeta[2,a_.+b_.*x_],x_Symbol] :=
  Int[x^m*PolyGamma[1,a+b*x],x] /;
FreeQ[{a,b},x] && RationalQ[m]


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Derivation: Integration by parts*)


(* ::Subsubsection:: *)
(*Rule: If  m>0 \[And] s!=1 \[And] s!=2, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]x^m Zeta[s,a+b x]\[DifferentialD]x  \[LongRightArrow]  -((x^m Zeta[s-1,a+b x])/(b (s-1)))+m/(b (s-1)) \[Integral]x^(m-1) Zeta[s-1,a+b x]\[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[x_^m_.*Zeta[s_,a_.+b_.*x_],x_Symbol] :=
  -x^m*Zeta[s-1,a+b*x]/(b*(s-1)) +
  Dist[m/(b*(s-1)),Int[x^(m-1)*Zeta[s-1,a+b*x],x]] /;
FreeQ[{a,b,s},x] && RationalQ[m] && m>0 && NonzeroQ[s-1] && NonzeroQ[s-2]


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Derivation: Inverted integration by parts*)


(* ::Subsubsection:: *)
(*Rule: If  m<-1 \[And] s!=1 \[And] s!=2, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]x^m Zeta[s,a+b x]\[DifferentialD]x  \[LongRightArrow]  ((x^(m+1) Zeta[s,a+b x])/(m+1))+(b s)/(m+1) \[Integral]x^(m+1) Zeta[s+1,a+b x]\[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[x_^m_.*Zeta[s_,a_.+b_.*x_],x_Symbol] :=
  x^(m+1)*Zeta[s,a+b*x]/(m+1) +
  Dist[b*s/(m+1),Int[x^(m+1)*Zeta[s+1,a+b*x],x]] /;
FreeQ[{a,b,s},x] && RationalQ[m] && m<-1 && NonzeroQ[s-1] && NonzeroQ[s-2]


(* ::PageBreak:: *)
(**)
