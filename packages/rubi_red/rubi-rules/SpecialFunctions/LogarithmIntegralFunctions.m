(* ::Package:: *)

(* ::Title::Bold::Closed:: *)
(*\[Integral]LogIntegral[a+b x]^n \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Derivation: Integration by parts*)


(* ::Subsubsection:: *)
(*Rule:*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]LogIntegral[a+b x]\[DifferentialD]x  \[LongRightArrow]  (((a+b x) LogIntegral[a+b x])/b)-ExpIntegralEi[2 Log[a+b x]]/b*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[LogIntegral[a_.+b_.*x_],x_Symbol] :=
  (a+b*x)*LogIntegral[a+b*x]/b - ExpIntegralEi[2*Log[a+b*x]]/b /;
FreeQ[{a,b},x]


(* ::PageBreak:: *)
(**)


(* ::Title::Bold::Closed:: *)
(*\[Integral]x^m LogIntegral[a+b x]^n \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Derivation: Integration by parts*)


(* ::Subsubsection:: *)
(*Rule: If  m+1!=0, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]x^m LogIntegral[a+b x]\[DifferentialD]x  \[LongRightArrow]  ((x^(m+1) LogIntegral[a+b x])/(m+1))-b/(m+1) \[Integral]x^(m+1)/Log[a+b x] \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[x_^m_.*LogIntegral[a_.+b_.*x_],x_Symbol] :=
  x^(m+1)*LogIntegral[a+b*x]/(m+1) -
  Dist[b/(m+1),Int[x^(m+1)/Log[a+b*x],x]] /;
FreeQ[{a,b,m},x] && NonzeroQ[m+1]
