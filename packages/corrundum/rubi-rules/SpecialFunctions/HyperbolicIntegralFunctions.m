(* ::Package:: *)

(* ::Title::Bold::Closed:: *)
(*\[Integral]SinhIntegral[a+b x]^n \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Derivation: Integration by parts*)


(* ::Subsubsection:: *)
(*Rule:*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]SinhIntegral[a+b x]\[DifferentialD]x  \[LongRightArrow]  (((a+b x) SinhIntegral[a+b x])/b)-Cosh[a+b x]/b*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[SinhIntegral[a_.+b_.*x_],x_Symbol] :=
  (a+b*x)*SinhIntegral[a+b*x]/b - Cosh[a+b*x]/b/;
FreeQ[{a,b},x]


(* ::Code:: *)
Int[CoshIntegral[a_.+b_.*x_],x_Symbol] :=
  (a+b*x)*CoshIntegral[a+b*x]/b - Sinh[a+b*x]/b /;
FreeQ[{a,b},x]


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Derivation: Integration by parts*)


(* ::Subsubsection:: *)
(*Rule:*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]SinhIntegral[a+b x]^2 \[DifferentialD]x  \[LongRightArrow]                                                                                                          *)
(*                  (((a+b x) SinhIntegral[a+b x]^2)/b)-2\[Integral]Sinh[a+b x] SinhIntegral[a+b x]\[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[SinhIntegral[a_.+b_.*x_]^2,x_Symbol] :=
  (a+b*x)*SinhIntegral[a+b*x]^2/b -
  Dist[2,Int[Sinh[a+b*x]*SinhIntegral[a+b*x],x]] /;
FreeQ[{a,b},x]


(* ::Code:: *)
Int[CoshIntegral[a_.+b_.*x_]^2,x_Symbol] :=
  (a+b*x)*CoshIntegral[a+b*x]^2/b -
  Dist[2,Int[Cosh[a+b*x]*CoshIntegral[a+b*x],x]] /;
FreeQ[{a,b},x]


(* ::PageBreak:: *)
(**)


(* ::Title::Bold::Closed:: *)
(*\[Integral]x^m SinhIntegral[a+b x]^n \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Derivation: Integration by parts*)


(* ::Subsubsection:: *)
(*Rule: If  m+1!=0, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]x^m SinhIntegral[a+b x]\[DifferentialD]x  \[LongRightArrow]  ((x^(m+1) SinhIntegral[a+b x])/(m+1))-b/(m+1) \[Integral](x^(m+1) Sinh[a+b x])/(a+b x) \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[x_^m_.*SinhIntegral[a_.+b_.*x_],x_Symbol] :=
  x^(m+1)*SinhIntegral[a+b*x]/(m+1) -
  Dist[b/(m+1),Int[x^(m+1)*Sinh[a+b*x]/(a+b*x),x]] /;
FreeQ[{a,b,m},x] && NonzeroQ[m+1]


(* ::Code:: *)
Int[x_^m_.*CoshIntegral[a_.+b_.*x_],x_Symbol] :=
  x^(m+1)*CoshIntegral[a+b*x]/(m+1) -
  Dist[b/(m+1),Int[x^(m+1)*Cosh[a+b*x]/(a+b*x),x]] /;
FreeQ[{a,b,m},x] && NonzeroQ[m+1]


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Derivation: Integration by parts*)


(* ::Subsubsection:: *)
(*Rule: If  m\[Element]\[DoubleStruckCapitalZ] \[And] m>0, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]x^m SinhIntegral[b x]^2 \[DifferentialD]x  \[LongRightArrow]  ((x^(m+1) SinhIntegral[b x]^2)/(m+1))-2/(m+1) \[Integral]x^m Sinh[b x] SinhIntegral[b x]\[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[x_^m_.*SinhIntegral[b_.*x_]^2,x_Symbol] :=
  x^(m+1)*SinhIntegral[b*x]^2/(m+1) -
  Dist[2/(m+1),Int[x^m*Sinh[b*x]*SinhIntegral[b*x],x]] /;
FreeQ[b,x] && IntegerQ[m] && m>0


(* ::Code:: *)
Int[x_^m_.*CoshIntegral[b_.*x_]^2,x_Symbol] :=
  x^(m+1)*CoshIntegral[b*x]^2/(m+1) -
  Dist[2/(m+1),Int[x^m*Cosh[b*x]*CoshIntegral[b*x],x]] /;
FreeQ[b,x] && IntegerQ[m] && m>0


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Derivation: Iterated integration by parts*)


(* ::Subsubsection:: *)
(*Rule: If  m\[Element]\[DoubleStruckCapitalZ] \[And] m>0, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]x^m SinhIntegral[a+b x]^2 \[DifferentialD]x  \[LongRightArrow]  ((x^(m+1) SinhIntegral[a+b x]^2)/(m+1))+(a x^m SinhIntegral[a+b x]^2)/(b (m+1))-  *)
(*               2/(m+1) \[Integral]x^m Sinh[a+b x] SinhIntegral[a+b x]\[DifferentialD]x-(a m)/(b (m+1)) \[Integral]x^(m-1) SinhIntegral[a+b x]^2 \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[x_^m_.*SinhIntegral[a_+b_.*x_]^2,x_Symbol] :=
  x^(m+1)*SinhIntegral[a+b*x]^2/(m+1) +
  a*x^m*SinhIntegral[a+b*x]^2/(b*(m+1)) -
  Dist[2/(m+1),Int[x^m*Sinh[a+b*x]*SinhIntegral[a+b*x],x]] -
  Dist[a*m/(b*(m+1)),Int[x^(m-1)*SinhIntegral[a+b*x]^2,x]] /;
FreeQ[{a,b},x] && IntegerQ[m] && m>0


(* ::Code:: *)
Int[x_^m_.*CoshIntegral[a_+b_.*x_]^2,x_Symbol] :=
  x^(m+1)*CoshIntegral[a+b*x]^2/(m+1) +
  a*x^m*CoshIntegral[a+b*x]^2/(b*(m+1)) -
  Dist[2/(m+1),Int[x^m*Cosh[a+b*x]*CoshIntegral[a+b*x],x]] -
  Dist[a*m/(b*(m+1)),Int[x^(m-1)*CoshIntegral[a+b*x]^2,x]] /;
FreeQ[{a,b},x] && IntegerQ[m] && m>0


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Derivation: Inverted integration by parts*)


(* ::Subsubsection:: *)
(*Rule: If  m\[Element]\[DoubleStruckCapitalZ] \[And] m<-2, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]x^m SinhIntegral[a+b x]^2 \[DifferentialD]x  \[LongRightArrow]  ((b x^(m+2) SinhIntegral[a+b x]^2)/(a (m+1)))+(x^(m+1) SinhIntegral[a+b x]^2)/(m+1)-    *)
(*   (2 b)/(a (m+1)) \[Integral]x^(m+1) Sinh[a+b x] SinhIntegral[a+b x]\[DifferentialD]x-(b (m+2))/(a (m+1)) \[Integral]x^(m+1) SinhIntegral[a+b x]^2 \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
(* Int[x_^m_.*SinhIntegral[a_+b_.*x_]^2,x_Symbol] :=
  b*x^(m+2)*SinhIntegral[a+b*x]^2/(a*(m+1)) +
  x^(m+1)*SinhIntegral[a+b*x]^2/(m+1) -
  Dist[2*b/(a*(m+1)),Int[x^(m+1)*Sinh[a+b*x]*SinhIntegral[a+b*x],x]] -
  Dist[b*(m+2)/(a*(m+1)),Int[x^(m+1)*SinhIntegral[a+b*x]^2,x]] /;
FreeQ[{a,b},x] && IntegerQ[m] && m<-2 *)


(* ::Code:: *)
(* Int[x_^m_.*CoshIntegral[a_+b_.*x_]^2,x_Symbol] :=
  b*x^(m+2)*CoshIntegral[a+b*x]^2/(a*(m+1)) +
  x^(m+1)*CoshIntegral[a+b*x]^2/(m+1) -
  Dist[2*b/(a*(m+1)),Int[x^(m+1)*Cosh[a+b*x]*CoshIntegral[a+b*x],x]] -
  Dist[b*(m+2)/(a*(m+1)),Int[x^(m+1)*CoshIntegral[a+b*x]^2,x]] /;
FreeQ[{a,b},x] && IntegerQ[m] && m<-2 *)


(* ::PageBreak:: *)
(**)


(* ::Title::Bold::Closed:: *)
(*\[Integral]Sinh[a+b x] SinhIntegral[c+d x]\[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Derivation: Integration by parts*)


(* ::Subsubsection:: *)
(*Rule:*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]Sinh[a+b x] SinhIntegral[c+d x]\[DifferentialD]x  \[LongRightArrow]                                                                               *)
(*                         ((Cosh[a+b x] SinhIntegral[c+d x])/b)-d/b \[Integral](Cosh[a+b x] Sinh[c+d x])/(c+d x) \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[Sinh[a_.+b_.*x_]*SinhIntegral[c_.+d_.*x_],x_Symbol] :=
  Cosh[a+b*x]*SinhIntegral[c+d*x]/b -
  Dist[d/b,Int[Cosh[a+b*x]*Sinh[c+d*x]/(c+d*x),x]] /;
FreeQ[{a,b,c,d},x]


(* ::Code:: *)
Int[Cosh[a_.+b_.*x_]*CoshIntegral[c_.+d_.*x_],x_Symbol] :=
  Sinh[a+b*x]*CoshIntegral[c+d*x]/b -
  Dist[d/b,Int[Sinh[a+b*x]*Cosh[c+d*x]/(c+d*x),x]] /;
FreeQ[{a,b,c,d},x]


(* ::PageBreak:: *)
(**)


(* ::Title::Bold::Closed:: *)
(*\[Integral]x^m Sinh[a+b x] SinhIntegral[c+d x]\[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Derivation: Integration by parts*)


(* ::Subsubsection:: *)
(*Rule: If  m\[Element]\[DoubleStruckCapitalZ] \[And] m>0, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]x^m Sinh[a+b x] SinhIntegral[c+d x]\[DifferentialD]x  \[LongRightArrow]  ((x^m Cosh[a+b x] SinhIntegral[c+d x])/b)-          *)
(*         d/b \[Integral](x^m Cosh[a+b x] Sinh[c+d x])/(c+d x) \[DifferentialD]x-m/b \[Integral]x^(m-1) Cosh[a+b x] SinhIntegral[c+d x]\[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[x_^m_.*Sinh[a_.+b_.*x_]*SinhIntegral[c_.+d_.*x_],x_Symbol] :=
  x^m*Cosh[a+b*x]*SinhIntegral[c+d*x]/b -
  Dist[d/b,Int[x^m*Cosh[a+b*x]*Sinh[c+d*x]/(c+d*x),x]] -
  Dist[m/b,Int[x^(m-1)*Cosh[a+b*x]*SinhIntegral[c+d*x],x]] /;
FreeQ[{a,b,c,d},x] && IntegerQ[m] && m>0


(* ::Code:: *)
Int[x_^m_.*Cosh[a_.+b_.*x_]*CoshIntegral[c_.+d_.*x_],x_Symbol] :=
  x^m*Sinh[a+b*x]*CoshIntegral[c+d*x]/b -
  Dist[d/b,Int[x^m*Sinh[a+b*x]*Cosh[c+d*x]/(c+d*x),x]] -
  Dist[m/b,Int[x^(m-1)*Sinh[a+b*x]*CoshIntegral[c+d*x],x]] /;
FreeQ[{a,b,c,d},x] && IntegerQ[m] && m>0


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Derivation: Inverted integration by parts*)


(* ::Subsubsection:: *)
(*Rule: If  m\[Element]\[DoubleStruckCapitalZ] \[And] m<-1, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]x^m Sinh[a+b x] SinhIntegral[c+d x]\[DifferentialD]x  \[LongRightArrow]  ((x^(m+1) Sinh[a+b x] SinhIntegral[c+d x])/(m+1))-              *)
(*   d/(m+1) \[Integral](x^(m+1) Sinh[a+b x] Sinh[c+d x])/(c+d x) \[DifferentialD]x-b/(m+1) \[Integral]x^(m+1) Cosh[a+b x] SinhIntegral[c+d x]\[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[x_^m_*Sinh[a_.+b_.*x_]*SinhIntegral[c_.+d_.*x_],x_Symbol] :=
  x^(m+1)*Sinh[a+b*x]*SinhIntegral[c+d*x]/(m+1) -
  Dist[d/(m+1),Int[x^(m+1)*Sinh[a+b*x]*Sinh[c+d*x]/(c+d*x),x]] -
  Dist[b/(m+1),Int[x^(m+1)*Cosh[a+b*x]*SinhIntegral[c+d*x],x]] /;
FreeQ[{a,b,c,d},x] && IntegerQ[m] && m<-1


(* ::Code:: *)
Int[x_^m_.*Cosh[a_.+b_.*x_]*CoshIntegral[c_.+d_.*x_],x_Symbol] :=
  x^(m+1)*Cosh[a+b*x]*CoshIntegral[c+d*x]/(m+1) -
  Dist[d/(m+1),Int[x^(m+1)*Cosh[a+b*x]*Cosh[c+d*x]/(c+d*x),x]] -
  Dist[b/(m+1),Int[x^(m+1)*Sinh[a+b*x]*CoshIntegral[c+d*x],x]] /;
FreeQ[{a,b,c,d},x] && IntegerQ[m] && m<-1


(* ::PageBreak:: *)
(**)


(* ::Title::Bold::Closed:: *)
(*\[Integral]Cosh[a+b x] SinhIntegral[c+d x]\[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Derivation: Integration by parts*)


(* ::Subsubsection:: *)
(*Rule:*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]Cosh[a+b x] SinhIntegral[c+d x]\[DifferentialD]x  \[LongRightArrow]                                                                               *)
(*                             ((Sinh[a+b x] SinhIntegral[c+d x])/b)-d/b \[Integral](Sinh[a+b x] Sinh[c+d x])/(c+d x) \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[Cosh[a_.+b_.*x_]*SinhIntegral[c_.+d_.*x_],x_Symbol] :=
  Sinh[a+b*x]*SinhIntegral[c+d*x]/b -
  Dist[d/b,Int[Sinh[a+b*x]*Sinh[c+d*x]/(c+d*x),x]] /;
FreeQ[{a,b,c,d},x]


(* ::Code:: *)
Int[Sinh[a_.+b_.*x_]*CoshIntegral[c_.+d_.*x_],x_Symbol] :=
  Cosh[a+b*x]*CoshIntegral[c+d*x]/b -
  Dist[d/b,Int[Cosh[a+b*x]*Cosh[c+d*x]/(c+d*x),x]] /;
FreeQ[{a,b,c,d},x]


(* ::PageBreak:: *)
(**)


(* ::Title::Bold::Closed:: *)
(*\[Integral]x^m Cosh[a+b x] SinhIntegral[c+d x]\[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Derivation: Integration by parts*)


(* ::Subsubsection:: *)
(*Rule: If  m\[Element]\[DoubleStruckCapitalZ] \[And] m>0, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]x^m Cosh[a+b x] SinhIntegral[c+d x]\[DifferentialD]x  \[LongRightArrow]  ((x^m Sinh[a+b x] SinhIntegral[c+d x])/b)-             *)
(*            d/b \[Integral](x^m Sinh[a+b x] Sinh[c+d x])/(c+d x) \[DifferentialD]x-m/b \[Integral]x^(m-1) Sinh[a+b x] SinhIntegral[c+d x]\[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[x_^m_.*Cosh[a_.+b_.*x_]*SinhIntegral[c_.+d_.*x_],x_Symbol] :=
  x^m*Sinh[a+b*x]*SinhIntegral[c+d*x]/b -
  Dist[d/b,Int[x^m*Sinh[a+b*x]*Sinh[c+d*x]/(c+d*x),x]] -
  Dist[m/b,Int[x^(m-1)*Sinh[a+b*x]*SinhIntegral[c+d*x],x]] /;
FreeQ[{a,b,c,d},x] && IntegerQ[m] && m>0


(* ::Code:: *)
Int[x_^m_.*Sinh[a_.+b_.*x_]*CoshIntegral[c_.+d_.*x_],x_Symbol] :=
  x^m*Cosh[a+b*x]*CoshIntegral[c+d*x]/b -
  Dist[d/b,Int[x^m*Cosh[a+b*x]*Cosh[c+d*x]/(c+d*x),x]] -
  Dist[m/b,Int[x^(m-1)*Cosh[a+b*x]*CoshIntegral[c+d*x],x]] /;
FreeQ[{a,b,c,d},x] && IntegerQ[m] && m>0


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Derivation: Inverted integration by parts*)


(* ::Subsubsection:: *)
(*Rule: If  m\[Element]\[DoubleStruckCapitalZ] \[And] m<-1, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]x^m Cosh[a+b x] SinhIntegral[c+d x]\[DifferentialD]x  \[LongRightArrow]  ((x^(m+1) Cosh[a+b x] SinhIntegral[c+d x])/(m+1))-            *)
(*  d/(m+1) \[Integral](x^(m+1) Cosh[a+b x] Sinh[c+d x])/(c+d x) \[DifferentialD]x-b/(m+1) \[Integral]x^(m+1) Sinh[a+b x] SinhIntegral[c+d x]\[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[x_^m_.*Cosh[a_.+b_.*x_]*SinhIntegral[c_.+d_.*x_],x_Symbol] :=
  x^(m+1)*Cosh[a+b*x]*SinhIntegral[c+d*x]/(m+1) -
  Dist[d/(m+1),Int[x^(m+1)*Cosh[a+b*x]*Sinh[c+d*x]/(c+d*x),x]] -
  Dist[b/(m+1),Int[x^(m+1)*Sinh[a+b*x]*SinhIntegral[c+d*x],x]] /;
FreeQ[{a,b,c,d},x] && IntegerQ[m] && m<-1


(* ::Code:: *)
Int[x_^m_*Sinh[a_.+b_.*x_]*CoshIntegral[c_.+d_.*x_],x_Symbol] :=
  x^(m+1)*Sinh[a+b*x]*CoshIntegral[c+d*x]/(m+1) -
  Dist[d/(m+1),Int[x^(m+1)*Sinh[a+b*x]*Cosh[c+d*x]/(c+d*x),x]] -
  Dist[b/(m+1),Int[x^(m+1)*Cosh[a+b*x]*CoshIntegral[c+d*x],x]] /;
FreeQ[{a,b,c,d},x] && IntegerQ[m] && m<-1


(* ::PageBreak:: *)
(**)
