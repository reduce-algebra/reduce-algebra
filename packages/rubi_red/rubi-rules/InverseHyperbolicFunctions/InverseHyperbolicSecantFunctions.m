(* ::Package:: *)

(* ::Title::Bold::Closed:: *)
(*\[Integral]ArcSech[a+b x]^n \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Reference: CRC 591', A&S 4.6.47'*)


(* ::Subsubsection:: *)
(*Derivation: Integration by parts*)


(* ::Subsubsection:: *)
(*Rule:*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]ArcSech[a+b x]\[DifferentialD]x  \[LongRightArrow]  (((a+b x) ArcSech[a+b x])/b)-2/b ArcTan[Sqrt[(1-a-b x)/(1+a+b x)]]*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[ArcSech[a_.+b_.*x_],x_Symbol] :=
  (a+b*x)*ArcSech[a+b*x]/b - 2*ArcTan[Sqrt[(1-a-b*x)/(1+a+b*x)]]/b /;
FreeQ[{a,b},x]


(* ::PageBreak:: *)
(**)


(* ::Title::Bold::Closed:: *)
(*\[Integral]x^m ArcSech[a+b x]\[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Derivation: Integration by substitution*)


(* ::Subsubsection:: *)
(*Rule: If  m\[Element]\[DoubleStruckCapitalZ] \[And] m>0, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]x^m ArcSech[a+b x]\[DifferentialD]x  \[LongRightArrow]  (1/b)Subst[\[Integral](-(a/b)+x/b)^m ArcSech[x]\[DifferentialD]x,x,a+b x]*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[x_^m_.*ArcSech[a_+b_.*x_],x_Symbol] :=
  Dist[1/b,Subst[Int[(-a/b+x/b)^m*ArcSech[x],x],x,a+b*x]] /;
FreeQ[{a,b},x] && IntegerQ[m] && m>0


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Reference: CRC 593', A&S 4.6.58'*)


(* ::Subsubsection:: *)
(*Derivation: Integration by parts*)


(* ::Subsubsection:: *)
(*Basis: \!\( *)
(*\*SubscriptBox[\(\[PartialD]\), \(x\)]\(ArcSech[x]\)\)=-((Sqrt[1/(1+x)] Sqrt[1+x])/(x Sqrt[1+x] Sqrt[1-x]))*)


(* ::Subsubsection:: *)
(*Basis: \!\( *)
(*\*SubscriptBox[\(\[PartialD]\), \(x\)]\(( *)
(*\*SqrtBox[*)
(*FractionBox[\(1\), \(1 + a + b\ *)
(*\*SuperscriptBox[\(x\), \(n\)]\)]]\ *)
(*\*SqrtBox[\(1 + a + b\ *)
(*\*SuperscriptBox[\(x\), \(n\)]\)])\)\)=0*)


(* ::Subsubsection:: *)
(*Rule: If  m+1!=0, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]x^m ArcSech[a x]\[DifferentialD]x  \[LongRightArrow]  ((x^(m+1) ArcSech[a x])/(m+1))+1/(m+1) \[Integral]x^m/(Sqrt[(1-a x)/(1+a x)] (1+a x)) \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[x_^m_.*ArcSech[a_.*x_],x_Symbol] :=
  x^(m+1)*ArcSech[a*x]/(m+1) + 
  Dist[1/(m+1),Int[x^m/(Sqrt[(1-a*x)/(1+a*x)]*(1+a*x)),x]] /;
FreeQ[{a,m},x] && NonzeroQ[m+1]


(* Int[ArcSech[a_.*x_^n_.]/x_,x_Symbol] :=
(*   Int[ArcCosh[1/a*x^(-n)]/x,x] /; *)
  -ArcSech[a*x^n]^2/(2*n) - 
  ArcSech[a*x^n]*Log[1+E^(-2*ArcSech[a*x^n])]/n + 
  PolyLog[2,-E^(-2*ArcSech[a*x^n])]/(2*n) /;
(* -ArcSech[a*x^n]^2/(2*n) - 
  ArcSech[a*x^n]*Log[1+1/(1/(a*x^n)+Sqrt[-1+1/(a*x^n)]*Sqrt[1+1/(a*x^n)])^2]/n + 
  PolyLog[2,-1/(1/(a*x^n)+Sqrt[-1+1/(a*x^n)]*Sqrt[1+1/(a*x^n)])^2]/(2*n) /; *)
FreeQ[{a,n},x] *)


(* ::PageBreak:: *)
(**)


(* ::Title::Bold::Closed:: *)
(*\[Integral]u ArcSech[c/(a+b x^n)]^m \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Derivation:  Algebraic simplification*)


(* ::Subsubsection:: *)
(*Basis: ArcSech[z]=ArcCosh[1/z]*)


(* ::Subsubsection:: *)
(*Rule:*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]u ArcSech[c/(a+b x^n)]^m \[DifferentialD]x  \[LongRightArrow]  \[Integral]u ArcCosh[a/c+(b x^n)/c]^m \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[u_.*ArcSech[c_./(a_.+b_.*x_^n_.)]^m_.,x_Symbol] :=
  Int[u*ArcCosh[a/c+b*x^n/c]^m,x] /;
FreeQ[{a,b,c,n,m},x]


(* ::PageBreak:: *)
(**)


(* ::Title::Bold::Closed:: *)
(*\[Integral]ArcSech[u]\[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Derivation: Integration by parts*)


(* ::Subsubsection:: *)
(*Rule: If u is free of inverse functions, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]ArcSech[u]\[DifferentialD]x  \[LongRightArrow]  x ArcSech[u]+\[Integral](x \!\( *)
(*\*SubscriptBox[\(\[PartialD]\), \(x\)]u\))/(u^2 Sqrt[-1+1/u] Sqrt[1+1/u]) \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
(* Int[ArcSech[u_],x_Symbol] :=
  x*ArcSech[u] +
  Int[Regularize[x*D[u,x]/(u^2*Sqrt[-1+1/u]*Sqrt[1+1/u]),x],x] /;
InverseFunctionFreeQ[u,x] && Not[FunctionOfExponentialOfLinear[u,x]] *)


(* ::PageBreak:: *)
(**)


(* ::Title::Bold::Closed:: *)
(*\[Integral]x^m E^(n ArcSech[u]) \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Derivation: Algebraic simplification*)


(* ::Subsubsection:: *)
(*Basis: E^(n ArcSech[z])=(Sqrt[-1+1/z] Sqrt[1+1/z]+1/z)^n*)


(* ::Subsubsection:: *)
(*Basis: If n\[Element]\[DoubleStruckCapitalZ],  E^(n ArcSech[z])=(1/z+Sqrt[(1-z)/(1+z)]+Sqrt[(1-z)/(1+z)]/z)^n*)


(* ::Subsubsection:: *)
(*Basis: If n\[Element]\[DoubleStruckCapitalZ],  E^(n ArcSech[z])=((1+Sqrt[1-z]/Sqrt[1/(1+z)])/z)^n*)


(* ::Subsubsection:: *)
(*Rule: If  n\[Element]\[DoubleStruckCapitalZ] \[And] u is a polynomial in x, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]E^(n ArcSech[u]) \[DifferentialD]x  \[LongRightArrow]  \[Integral](1/u+Sqrt[(1-u)/(1+u)]+Sqrt[(1-u)/(1+u)]/u)^n \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[E^(n_.*ArcSech[u_]), x_Symbol] :=
  Int[(1/u + Sqrt[(1-u)/(1+u)] + Sqrt[(1-u)/(1+u)]/u)^n,x] /;
IntegerQ[n] && PolynomialQ[u,x]


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Derivation: Algebraic simplification*)


(* ::Subsubsection:: *)
(*Basis: E^(n ArcSech[z])=(Sqrt[-1+1/z] Sqrt[1+1/z]+1/z)^n*)


(* ::Subsubsection:: *)
(*Rule: If  n\[Element]\[DoubleStruckCapitalZ] \[And] u is a polynomial in x, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]x^m E^(n ArcSech[u]) \[DifferentialD]x  \[LongRightArrow]  \[Integral]x^m (1/u+Sqrt[(1-u)/(1+u)]+Sqrt[(1-u)/(1+u)]/u)^n \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[x_^m_.*E^(n_.*ArcSech[u_]), x_Symbol] :=
  Int[x^m*(1/u + Sqrt[(1-u)/(1+u)] + Sqrt[(1-u)/(1+u)]/u)^n,x] /;
RationalQ[m] && IntegerQ[n] && PolynomialQ[u,x]
