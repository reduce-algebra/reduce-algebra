(* ::Package:: *)

(* ::Title::Bold::Closed:: *)
(*\[Integral]Gamma[n,a+b x]\[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Derivation: Integration by parts*)


(* ::Subsubsection:: *)
(*Rule:*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]Gamma[n,a+b x]\[DifferentialD]x  \[LongRightArrow]  (((a+b x) Gamma[n,a+b x])/b)-Gamma[n+1,a+b x]/b*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[Gamma[n_,a_.+b_.*x_],x_Symbol] :=
  (a+b*x)*Gamma[n,a+b*x]/b -
  Gamma[n+1,a+b*x]/b /;
FreeQ[{a,b},x]


(* ::PageBreak:: *)
(**)


(* ::Title::Bold::Closed:: *)
(*\[Integral]x^m Gamma[n,a+b x]\[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Derivation: Integration by parts*)


(* ::Subsubsection:: *)
(*Rule: If  m\[Element]\[DoubleStruckCapitalZ] \[Or] a>0, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]x^m Gamma[n,a x]\[DifferentialD]x  \[LongRightArrow]  ((x^(m+1) Gamma[n,a x])/(m+1))-Gamma[m+n+1,a x]/((m+1) a^(m+1))*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[x_^m_.*Gamma[n_,a_.*x_],x_Symbol] :=
  x^(m+1)*Gamma[n,a*x]/(m+1) -
  Gamma[m+n+1,a*x]/((m+1)*a^(m+1)) /;
FreeQ[{a,n},x] && (IntegerQ[m] || PositiveQ[a])


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Derivation: Integration by parts*)


(* ::Subsubsection:: *)
(*Rule:*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]x^m Gamma[n,a x]\[DifferentialD]x  \[LongRightArrow]  ((x^(m+1) Gamma[n,a x])/(m+1))-(x^(m+1) Gamma[m+n+1,a x])/((m+1) (a x)^(m+1))*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[x_^m_.*Gamma[n_,a_*x_],x_Symbol] :=
  x^(m+1)*Gamma[n,a*x]/(m+1) -
  x^(m+1)*Gamma[m+n+1,a*x]/((m+1)*(a*x)^(m+1)) /;
FreeQ[{a,m,n},x]


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Derivation: Integration by parts*)


(* ::Subsubsection:: *)
(*Rule: If  m>0, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]x^m Gamma[n,a+b x]\[DifferentialD]x  \[LongRightArrow]  ((x^m (a+b x) Gamma[n,a+b x])/(b (m+1)))-(x^m Gamma[n+1,a+b x])/(b (m+1))-*)
(*                                         (a m)/(b (m+1)) \[Integral]x^(m-1) Gamma[n,a+b x]\[DifferentialD]x+m/(b (m+1)) \[Integral]x^(m-1) Gamma[n+1,a+b x]\[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[x_^m_.*Gamma[n_,a_+b_.*x_],x_Symbol] :=
  x^m*(a+b*x)*Gamma[n,a+b*x]/(b*(m+1)) -
  x^m*Gamma[n+1,a+b*x]/(b*(m+1)) -
  Dist[a*m/(b*(m+1)),Int[x^(m-1)*Gamma[n,a+b*x],x]] +
  Dist[m/(b*(m+1)),Int[x^(m-1)*Gamma[n+1,a+b*x],x]] /;
FreeQ[{a,b,n},x] && RationalQ[m] && m>0


(* ::Title::Bold::Closed:: *)
(*\[Integral]LogGamma[a+b x]\[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Derivation: Primitive rule*)


(* ::Subsubsection:: *)
(*Basis: \[PartialD]PolyGamma[-2,z]/\[PartialD]z==LogGamma[z]*)


(* ::Subsubsection:: *)
(*Rule:*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]LogGamma[a+b x]\[DifferentialD]x  \[LongRightArrow]  (PolyGamma[-2,a+b x]/b)*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[LogGamma[a_.+b_.*x_],x_Symbol] :=
  PolyGamma[-2,a+b*x]/b /;
FreeQ[{a,b},x]


(* ::PageBreak:: *)
(**)


(* ::Title::Bold::Closed:: *)
(*\[Integral]x^m LogGamma[a+b x]\[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Derivation: Integration by parts*)


(* ::Subsubsection:: *)
(*Rule: If  m>0, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]x^m LogGamma[a+b x]\[DifferentialD]x  \[LongRightArrow]  ((x^m PolyGamma[-2,a+b x])/b)-m/b \[Integral]x^(m-1) PolyGamma[-2,a+b x]\[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[x_^m_.*LogGamma[a_.+b_.*x_],x_Symbol] :=
  x^m*PolyGamma[-2,a+b*x]/b -
  Dist[m/b,Int[x^(m-1)*PolyGamma[-2,a+b*x],x]] /;
FreeQ[{a,b},x] && RationalQ[m] && m>0


(* ::PageBreak:: *)
(**)


(* ::Title::Bold::Closed:: *)
(*\[Integral]PolyGamma[n,a+b x]\[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Derivation: Primitive rule*)


(* ::Subsubsection:: *)
(*Basis: \[PartialD]PolyGamma[n,z]/\[PartialD]z==PolyGamma[n+1,z]*)


(* ::Subsubsection:: *)
(*Rule:*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]PolyGamma[n,a+b x]\[DifferentialD]x  \[LongRightArrow]  (PolyGamma[n-1,a+b x]/b)*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[PolyGamma[n_,a_.+b_.*x_],x_Symbol] :=
  PolyGamma[n-1,a+b*x]/b /;
FreeQ[{a,b,n},x]


(* ::PageBreak:: *)
(**)


(* ::Title::Bold::Closed:: *)
(*\[Integral]x^m PolyGamma[n,a+b x]\[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Derivation: Integration by parts*)


(* ::Subsubsection:: *)
(*Rule: If  m>0, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]x^m PolyGamma[n,a+b x]\[DifferentialD]x  \[LongRightArrow]  ((x^m PolyGamma[n-1,a+b x])/b)-m/b \[Integral]x^(m-1) PolyGamma[n-1,a+b x]\[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[x_^m_.*PolyGamma[n_,a_.+b_.*x_],x_Symbol] :=
  x^m*PolyGamma[n-1,a+b*x]/b -
  Dist[m/b,Int[x^(m-1)*PolyGamma[n-1,a+b*x],x]] /;
FreeQ[{a,b,n},x] && RationalQ[m] && m>0


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Derivation: Inverted integration by parts*)


(* ::Subsubsection:: *)
(*Rule: If  m<-1, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]x^m PolyGamma[n,a+b x]\[DifferentialD]x  \[LongRightArrow]  ((x^(m+1) PolyGamma[n,a+b x])/(m+1))-b/(m+1) \[Integral]x^(m+1) PolyGamma[n+1,a+b x]\[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[x_^m_.*PolyGamma[n_,a_.+b_.*x_],x_Symbol] :=
  x^(m+1)*PolyGamma[n,a+b*x]/(m+1) -
  Dist[b/(m+1),Int[x^(m+1)*PolyGamma[n+1,a+b*x],x]] /;
FreeQ[{a,b,n},x] && RationalQ[m] && m<-1


(* ::PageBreak:: *)
(**)


(* ::Title::Bold::Closed:: *)
(*\[Integral]Gamma[a+b x]^n PolyGamma[0,a+b x]\[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Derivation: Primitive rule*)


(* ::Subsubsection:: *)
(*Basis: \[PartialD]Gamma[z]^n/\[PartialD]z=n PolyGamma[0,z] Gamma[z]^n*)


(* ::Subsubsection:: *)
(*Rule:*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]Gamma[a+b x]^n PolyGamma[0,a+b x]\[DifferentialD]x  \[LongRightArrow]  (Gamma[a+b x]^n/(b n))*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[Gamma[a_.+b_.*x_]^n_.*PolyGamma[0,a_.+b_.*x_],x_Symbol] :=
  Gamma[a+b*x]^n/(b*n) /;
FreeQ[{a,b,n},x]


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Derivation: Primitive rule*)


(* ::Subsubsection:: *)
(*Basis: \[PartialD](z!)^n/\[PartialD]z=n PolyGamma[0,z+1] (z!)^n*)


(* ::Subsubsection:: *)
(*Rule:*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]((a+b x)!)^n PolyGamma[0,1+a+b x]\[DifferentialD]x  \[LongRightArrow]  (((a+b x)!)^n/(b n))*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[((a_.+b_.*x_)!)^n_.*PolyGamma[0,c_.+b_.*x_],x_Symbol] :=
  ((a+b*x)!)^n/(b*n) /;
FreeQ[{a,b,c,n},x] && ZeroQ[a-c+1]


(* ::PageBreak:: *)
(**)
