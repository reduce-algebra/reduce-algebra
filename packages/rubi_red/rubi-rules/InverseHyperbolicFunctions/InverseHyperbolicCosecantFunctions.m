(* ::Package:: *)

(* ::Title::Bold::Closed:: *)
(*\[Integral]ArcCsch[a+b x]^n \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Reference: CRC 594', A&S 4.6.46'*)


(* ::Subsubsection:: *)
(*Derivation: Integration by parts*)


(* ::Subsubsection:: *)
(*Rule:*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]ArcCsch[a+b x]\[DifferentialD]x  \[LongRightArrow]  (((a+b x) ArcCsch[a+b x])/b)+1/b ArcTanh[Sqrt[1+1/(a+b x)^2]]*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[ArcCsch[a_.+b_.*x_],x_Symbol] :=
  (a+b*x)*ArcCsch[a+b*x]/b + ArcTanh[Sqrt[1+1/(a+b*x)^2]]/b /;
FreeQ[{a,b},x]


(* ::PageBreak:: *)
(**)


(* ::Title::Bold::Closed:: *)
(*\[Integral]x^m ArcCsch[a+b x]\[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Derivation: Integration by substitution*)


(* ::Subsubsection:: *)
(*Rule: If  m\[Element]\[DoubleStruckCapitalZ] \[And] m>0, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]x^m ArcCsch[a+b x]\[DifferentialD]x  \[LongRightArrow]  (1/b)Subst[\[Integral](-(a/b)+x/b)^m ArcCsch[x]\[DifferentialD]x,x,a+b x]*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[x_^m_.*ArcCsch[a_+b_.*x_],x_Symbol] :=
  Dist[1/b,Subst[Int[(-a/b+x/b)^m*ArcCsch[x],x],x,a+b*x]] /;
FreeQ[{a,b},x] && IntegerQ[m] && m>0


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Reference: CRC 596, A&S 4.6.56*)


(* ::Subsubsection:: *)
(*Derivation: Integration by parts*)


(* ::Subsubsection:: *)
(*Rule: If  m+1!=0, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]x^m ArcCsch[a+b x]\[DifferentialD]x  \[LongRightArrow]  ((x^(m+1) ArcCsch[a+b x])/(m+1))+b/(m+1) \[Integral]x^(m+1)/((a+b x)^2 Sqrt[1+1/(a+b x)^2]) \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[x_^m_.*ArcCsch[a_.+b_.*x_],x_Symbol] :=
  x^(m+1)*ArcCsch[a+b*x]/(m+1) + 
  Dist[b/(m+1),Int[x^(m+1)/((a+b*x)^2*Sqrt[1+1/(a+b*x)^2]),x]] /;
FreeQ[{a,b,m},x] && NonzeroQ[m+1]


(* Int[ArcCsch[a_.*x_^n_.]/x_,x_Symbol] :=
(* Int[ArcCsch[1/a*x^(-n)]/x,x] /; *)
  -ArcCsch[a*x^n]^2/(2*n) - 
  ArcCsch[a*x^n]*Log[1-E^(-2*ArcCsch[a*x^n])]/n + 
  PolyLog[2,E^(-2*ArcCsch[a*x^n])]/(2*n) /;
(* -ArcCsch[a*x^n]^2/(2*n) - 
  ArcCsch[a*x^n]*Log[1-1/(1/(a*x^n)+Sqrt[1+1/(a^2*x^(2*n))])^2]/n + 
  PolyLog[2,1/(1/(a*x^n)+Sqrt[1+1/(a^2*x^(2*n))])^2]/(2*n) /; *)
FreeQ[{a,n},x] *)


(* ::PageBreak:: *)
(**)


(* ::Title::Bold::Closed:: *)
(*\[Integral]u ArcCsch[c/(a+b x^n)]^m \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Derivation:  Algebraic simplification*)


(* ::Subsubsection:: *)
(*Basis: ArcCsch[z]=ArcSinh[1/z]*)


(* ::Subsubsection:: *)
(*Rule:*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]u ArcCsch[c/(a+b x^n)]^m \[DifferentialD]x  \[LongRightArrow]  \[Integral]u ArcSinh[a/c+(b x^n)/c]^m \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[u_.*ArcCsch[c_./(a_.+b_.*x_^n_.)]^m_.,x_Symbol] :=
  Int[u*ArcSinh[a/c+b*x^n/c]^m,x] /;
FreeQ[{a,b,c,n,m},x]


(* ::PageBreak:: *)
(**)


(* ::Title::Bold::Closed:: *)
(*\[Integral]ArcCsch[u]\[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Derivation: Integration by parts*)


(* ::Subsubsection:: *)
(*Rule: If u is free of inverse functions, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]ArcCsch[u]\[DifferentialD]x  \[LongRightArrow]  x ArcCsch[u]+\[Integral](x \!\( *)
(*\*SubscriptBox[\(\[PartialD]\), \(x\)]u\))/(u^2 Sqrt[1+1/u^2]) \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[ArcCsch[u_],x_Symbol] :=
  x*ArcCsch[u] +
  Int[Regularize[x*D[u,x]/(u^2*Sqrt[1+1/u^2]),x],x] /;
InverseFunctionFreeQ[u,x] && Not[FunctionOfExponentialOfLinear[u,x]]


(* ::PageBreak:: *)
(**)


(* ::Title::Bold::Closed:: *)
(*\[Integral]x^m E^(n ArcCsch[u]) \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Derivation: Algebraic simplification*)


(* ::Subsubsection:: *)
(*Basis: E^(n ArcCsch[z])=(1/z+Sqrt[1+1/z^2])^n*)


(* ::Subsubsection:: *)
(*Rule: If  n\[Element]\[DoubleStruckCapitalZ] \[And] u is a polynomial in x, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]E^(n ArcCsch[u]) \[DifferentialD]x  \[LongRightArrow]  \[Integral](1/u+Sqrt[1+1/u^2])^n \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[E^(n_.*ArcCsch[u_]), x_Symbol] :=
  Int[(1/u+Sqrt[1+1/u^2])^n,x] /;
IntegerQ[n] && PolynomialQ[u,x]


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Derivation: Algebraic simplification*)


(* ::Subsubsection:: *)
(*Basis: E^(n ArcCsch[z])=(1/z+Sqrt[1+1/z^2])^n*)


(* ::Subsubsection:: *)
(*Rule: If  n\[Element]\[DoubleStruckCapitalZ] \[And] u is a polynomial in x, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]x^m E^(n ArcCsch[u]) \[DifferentialD]x  \[LongRightArrow]  \[Integral]x^m (1/u+Sqrt[1+1/u^2])^n \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[x_^m_.*E^(n_.*ArcCsch[u_]), x_Symbol] :=
  Int[x^m*(1/u+Sqrt[1+1/u^2])^n,x] /;
RationalQ[m] && IntegerQ[n] && PolynomialQ[u,x]
