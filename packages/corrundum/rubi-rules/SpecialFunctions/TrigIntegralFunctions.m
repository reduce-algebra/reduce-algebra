(* ::Package:: *)

(* ::Title::Bold::Closed:: *)
(*\[Integral]SinIntegral[a+b x]^n \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Derivation: Integration by parts*)


(* ::Subsubsection:: *)
(*Rule:*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]SinIntegral[a+b x]\[DifferentialD]x  \[LongRightArrow]  (((a+b x) SinIntegral[a+b x])/b)+Cos[a+b x]/b*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[SinIntegral[a_.+b_.*x_],x_Symbol] :=
  (a+b*x)*SinIntegral[a+b*x]/b + Cos[a+b*x]/b/;
FreeQ[{a,b},x]


(* ::Code:: *)
Int[CosIntegral[a_.+b_.*x_],x_Symbol] :=
  (a+b*x)*CosIntegral[a+b*x]/b - Sin[a+b*x]/b /;
FreeQ[{a,b},x]


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Derivation: Integration by parts*)


(* ::Subsubsection:: *)
(*Rule:*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]SinIntegral[a+b x]^2 \[DifferentialD]x  \[LongRightArrow]  (((a+b x) SinIntegral[a+b x]^2)/b)-2\[Integral]Sin[a+b x] SinIntegral[a+b x]\[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[SinIntegral[a_.+b_.*x_]^2,x_Symbol] :=
  (a+b*x)*SinIntegral[a+b*x]^2/b -
  Dist[2,Int[Sin[a+b*x]*SinIntegral[a+b*x],x]] /;
FreeQ[{a,b},x]


(* ::Code:: *)
Int[CosIntegral[a_.+b_.*x_]^2,x_Symbol] :=
  (a+b*x)*CosIntegral[a+b*x]^2/b -
  Dist[2,Int[Cos[a+b*x]*CosIntegral[a+b*x],x]] /;
FreeQ[{a,b},x]


(* ::PageBreak:: *)
(**)


(* ::Title::Bold::Closed:: *)
(*\[Integral]x^m SinIntegral[a+b x]^n \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Derivation: Integration by parts*)


(* ::Subsubsection:: *)
(*Rule: If  m+1!=0, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]x^m SinIntegral[a+b x]\[DifferentialD]x  \[LongRightArrow]  ((x^(m+1) SinIntegral[a+b x])/(m+1))-b/(m+1) \[Integral](x^(m+1) Sin[a+b x])/(a+b x) \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[x_^m_.*SinIntegral[a_.+b_.*x_],x_Symbol] :=
  x^(m+1)*SinIntegral[a+b*x]/(m+1) -
  Dist[b/(m+1),Int[x^(m+1)*Sin[a+b*x]/(a+b*x),x]] /;
FreeQ[{a,b,m},x] && NonzeroQ[m+1]


(* ::Code:: *)
Int[x_^m_.*CosIntegral[a_.+b_.*x_],x_Symbol] :=
  x^(m+1)*CosIntegral[a+b*x]/(m+1) -
  Dist[b/(m+1),Int[x^(m+1)*Cos[a+b*x]/(a+b*x),x]] /;
FreeQ[{a,b,m},x] && NonzeroQ[m+1]


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Derivation: Integration by parts*)


(* ::Subsubsection:: *)
(*Rule: If  m\[Element]\[DoubleStruckCapitalZ] \[And] m>0, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]x^m SinIntegral[b x]^2 \[DifferentialD]x  \[LongRightArrow]  ((x^(m+1) SinIntegral[b x]^2)/(m+1))-2/(m+1) \[Integral]x^m Sin[b x] SinIntegral[b x]\[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[x_^m_.*SinIntegral[b_.*x_]^2,x_Symbol] :=
  x^(m+1)*SinIntegral[b*x]^2/(m+1) -
  Dist[2/(m+1),Int[x^m*Sin[b*x]*SinIntegral[b*x],x]] /;
FreeQ[b,x] && IntegerQ[m] && m>0


(* ::Code:: *)
Int[x_^m_.*CosIntegral[b_.*x_]^2,x_Symbol] :=
  x^(m+1)*CosIntegral[b*x]^2/(m+1) -
  Dist[2/(m+1),Int[x^m*Cos[b*x]*CosIntegral[b*x],x]] /;
FreeQ[b,x] && IntegerQ[m] && m>0


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Derivation: Iterated integration by parts*)


(* ::Subsubsection:: *)
(*Rule: If  m\[Element]\[DoubleStruckCapitalZ] \[And] m>0, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]x^m SinIntegral[a+b x]^2 \[DifferentialD]x  \[LongRightArrow]  ((x^(m+1) SinIntegral[a+b x]^2)/(m+1))+(a x^m SinIntegral[a+b x]^2)/(b (m+1))-  *)
(*                 2/(m+1) \[Integral]x^m Sin[a+b x] SinIntegral[a+b x]\[DifferentialD]x-(a m)/(b (m+1)) \[Integral]x^(m-1) SinIntegral[a+b x]^2 \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[x_^m_.*SinIntegral[a_+b_.*x_]^2,x_Symbol] :=
  x^(m+1)*SinIntegral[a+b*x]^2/(m+1) +
  a*x^m*SinIntegral[a+b*x]^2/(b*(m+1)) -
  Dist[2/(m+1),Int[x^m*Sin[a+b*x]*SinIntegral[a+b*x],x]] -
  Dist[a*m/(b*(m+1)),Int[x^(m-1)*SinIntegral[a+b*x]^2,x]] /;
FreeQ[{a,b},x] && IntegerQ[m] && m>0


(* ::Code:: *)
Int[x_^m_.*CosIntegral[a_+b_.*x_]^2,x_Symbol] :=
  x^(m+1)*CosIntegral[a+b*x]^2/(m+1) +
  a*x^m*CosIntegral[a+b*x]^2/(b*(m+1)) -
  Dist[2/(m+1),Int[x^m*Cos[a+b*x]*CosIntegral[a+b*x],x]] -
  Dist[a*m/(b*(m+1)),Int[x^(m-1)*CosIntegral[a+b*x]^2,x]] /;
FreeQ[{a,b},x] && IntegerQ[m] && m>0


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Derivation: Inverted integration by parts*)


(* ::Subsubsection:: *)
(*Rule: If  m\[Element]\[DoubleStruckCapitalZ] \[And] m<-2, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]x^m SinIntegral[a+b x]^2 \[DifferentialD]x  \[LongRightArrow]  ((b x^(m+2) SinIntegral[a+b x]^2)/(a (m+1)))+(x^(m+1) SinIntegral[a+b x]^2)/(m+1)-   *)
(*    (2 b)/(a (m+1)) \[Integral]x^(m+1) Sin[a+b x] SinIntegral[a+b x]\[DifferentialD]x-(b (m+2))/(a (m+1)) \[Integral]x^(m+1) SinIntegral[a+b x]^2 \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
(* Int[x_^m_.*SinIntegral[a_+b_.*x_]^2,x_Symbol] :=
  b*x^(m+2)*SinIntegral[a+b*x]^2/(a*(m+1)) +
  x^(m+1)*SinIntegral[a+b*x]^2/(m+1) -
  Dist[2*b/(a*(m+1)),Int[x^(m+1)*Sin[a+b*x]*SinIntegral[a+b*x],x]] -
  Dist[b*(m+2)/(a*(m+1)),Int[x^(m+1)*SinIntegral[a+b*x]^2,x]] /;
FreeQ[{a,b},x] && IntegerQ[m] && m<-2 *)


(* ::Code:: *)
(* Int[x_^m_.*CosIntegral[a_+b_.*x_]^2,x_Symbol] :=
  b*x^(m+2)*CosIntegral[a+b*x]^2/(a*(m+1)) +
  x^(m+1)*CosIntegral[a+b*x]^2/(m+1) -
  Dist[2*b/(a*(m+1)),Int[x^(m+1)*Cos[a+b*x]*CosIntegral[a+b*x],x]] -
  Dist[b*(m+2)/(a*(m+1)),Int[x^(m+1)*CosIntegral[a+b*x]^2,x]] /;
FreeQ[{a,b},x] && IntegerQ[m] && m<-2 *)


(* ::PageBreak:: *)
(**)


(* ::Title::Bold::Closed:: *)
(*\[Integral]Sin[a+b x] SinIntegral[c+d x]\[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Reference:  G&R 5.32.2*)


(* ::Subsubsection:: *)
(*Derivation: Integration by parts*)


(* ::Subsubsection:: *)
(*Rule:*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]Sin[a+b x] SinIntegral[c+d x]\[DifferentialD]x  \[LongRightArrow]                                                                                    *)
(*                                          -((Cos[a+b x] SinIntegral[c+d x])/b)+d/b \[Integral](Cos[a+b x] Sin[c+d x])/(c+d x) \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[Sin[a_.+b_.*x_]*SinIntegral[c_.+d_.*x_],x_Symbol] :=
  -Cos[a+b*x]*SinIntegral[c+d*x]/b +
  Dist[d/b,Int[Cos[a+b*x]*Sin[c+d*x]/(c+d*x),x]] /;
FreeQ[{a,b,c,d},x]


(* ::Subsubsection:: *)
(*Reference:  G&R 5.31.1*)


(* ::Code:: *)
Int[Cos[a_.+b_.*x_]*CosIntegral[c_.+d_.*x_],x_Symbol] :=
  Sin[a+b*x]*CosIntegral[c+d*x]/b -
  Dist[d/b,Int[Sin[a+b*x]*Cos[c+d*x]/(c+d*x),x]] /;
FreeQ[{a,b,c,d},x]


(* ::PageBreak:: *)
(**)


(* ::Title::Bold::Closed:: *)
(*\[Integral]x^m Sin[a+b x] SinIntegral[c+d x]\[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Derivation: Integration by parts*)


(* ::Subsubsection:: *)
(*Rule: If  m\[Element]\[DoubleStruckCapitalZ] \[And] m>0, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]x^m Sin[a+b x] SinIntegral[c+d x]\[DifferentialD]x  \[LongRightArrow]  -((x^m Cos[a+b x] SinIntegral[c+d x])/b)+                              *)
(*                              d/b \[Integral](x^m Cos[a+b x] Sin[c+d x])/(c+d x) \[DifferentialD]x+m/b \[Integral]x^(m-1) Cos[a+b x] SinIntegral[c+d x]\[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[x_^m_.*Sin[a_.+b_.*x_]*SinIntegral[c_.+d_.*x_],x_Symbol] :=
  -x^m*Cos[a+b*x]*SinIntegral[c+d*x]/b +
  Dist[d/b,Int[x^m*Cos[a+b*x]*Sin[c+d*x]/(c+d*x),x]] +
  Dist[m/b,Int[x^(m-1)*Cos[a+b*x]*SinIntegral[c+d*x],x]] /;
FreeQ[{a,b,c,d},x] && IntegerQ[m] && m>0


(* ::Code:: *)
Int[x_^m_.*Cos[a_.+b_.*x_]*CosIntegral[c_.+d_.*x_],x_Symbol] :=
  x^m*Sin[a+b*x]*CosIntegral[c+d*x]/b -
  Dist[d/b,Int[x^m*Sin[a+b*x]*Cos[c+d*x]/(c+d*x),x]] -
  Dist[m/b,Int[x^(m-1)*Sin[a+b*x]*CosIntegral[c+d*x],x]] /;
FreeQ[{a,b,c,d},x] && IntegerQ[m] && m>0


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Derivation: Inverted integration by parts*)


(* ::Subsubsection:: *)
(*Rule: If  m\[Element]\[DoubleStruckCapitalZ] \[And] m<-1, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]x^m Sin[a+b x] SinIntegral[c+d x]\[DifferentialD]x  \[LongRightArrow]  ((x^(m+1) Sin[a+b x] SinIntegral[c+d x])/(m+1))-                         *)
(*               d/(m+1) \[Integral](x^(m+1) Sin[a+b x] Sin[c+d x])/(c+d x) \[DifferentialD]x-b/(m+1) \[Integral]x^(m+1) Cos[a+b x] SinIntegral[c+d x]\[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[x_^m_*Sin[a_.+b_.*x_]*SinIntegral[c_.+d_.*x_],x_Symbol] :=
  x^(m+1)*Sin[a+b*x]*SinIntegral[c+d*x]/(m+1) -
  Dist[d/(m+1),Int[x^(m+1)*Sin[a+b*x]*Sin[c+d*x]/(c+d*x),x]] -
  Dist[b/(m+1),Int[x^(m+1)*Cos[a+b*x]*SinIntegral[c+d*x],x]] /;
FreeQ[{a,b,c,d},x] && IntegerQ[m] && m<-1


(* ::Code:: *)
Int[x_^m_.*Cos[a_.+b_.*x_]*CosIntegral[c_.+d_.*x_],x_Symbol] :=
  x^(m+1)*Cos[a+b*x]*CosIntegral[c+d*x]/(m+1) -
  Dist[d/(m+1),Int[x^(m+1)*Cos[a+b*x]*Cos[c+d*x]/(c+d*x),x]] +
  Dist[b/(m+1),Int[x^(m+1)*Sin[a+b*x]*CosIntegral[c+d*x],x]] /;
FreeQ[{a,b,c,d},x] && IntegerQ[m] && m<-1


(* ::PageBreak:: *)
(**)


(* ::Title::Bold::Closed:: *)
(*\[Integral]Cos[a+b x] SinIntegral[c+d x]\[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Reference:  G&R 5.32.1*)


(* ::Subsubsection:: *)
(*Derivation: Integration by parts*)


(* ::Subsubsection:: *)
(*Rule:*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]Cos[a+b x] SinIntegral[c+d x]\[DifferentialD]x  \[LongRightArrow]                                                                                 *)
(*                                     ((Sin[a+b x] SinIntegral[c+d x])/b)-d/b \[Integral](Sin[a+b x] Sin[c+d x])/(c+d x) \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[Cos[a_.+b_.*x_]*SinIntegral[c_.+d_.*x_],x_Symbol] :=
  Sin[a+b*x]*SinIntegral[c+d*x]/b -
  Dist[d/b,Int[Sin[a+b*x]*Sin[c+d*x]/(c+d*x),x]] /;
FreeQ[{a,b,c,d},x]


(* ::Subsubsection:: *)
(*Reference:  G&R 5.31.2*)


(* ::Code:: *)
Int[Sin[a_.+b_.*x_]*CosIntegral[c_.+d_.*x_],x_Symbol] :=
  -Cos[a+b*x]*CosIntegral[c+d*x]/b +
  Dist[d/b,Int[Cos[a+b*x]*Cos[c+d*x]/(c+d*x),x]] /;
FreeQ[{a,b,c,d},x]


(* ::PageBreak:: *)
(**)


(* ::Title::Bold::Closed:: *)
(*\[Integral]x^m Cos[a+b x] SinIntegral[c+d x]\[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Derivation: Integration by parts*)


(* ::Subsubsection:: *)
(*Rule: If  m\[Element]\[DoubleStruckCapitalZ] \[And] m>0, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]x^m Cos[a+b x] SinIntegral[c+d x]\[DifferentialD]x  \[LongRightArrow]  ((x^m Sin[a+b x] SinIntegral[c+d x])/b)-                        *)
(*                    d/b \[Integral](x^m Sin[a+b x] Sin[c+d x])/(c+d x) \[DifferentialD]x-m/b \[Integral]x^(m-1) Sin[a+b x] SinIntegral[c+d x]\[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[x_^m_.*Cos[a_.+b_.*x_]*SinIntegral[c_.+d_.*x_],x_Symbol] :=
  x^m*Sin[a+b*x]*SinIntegral[c+d*x]/b -
  Dist[d/b,Int[x^m*Sin[a+b*x]*Sin[c+d*x]/(c+d*x),x]] -
  Dist[m/b,Int[x^(m-1)*Sin[a+b*x]*SinIntegral[c+d*x],x]] /;
FreeQ[{a,b,c,d},x] && IntegerQ[m] && m>0


(* ::Code:: *)
Int[x_^m_.*Sin[a_.+b_.*x_]*CosIntegral[c_.+d_.*x_],x_Symbol] :=
  -x^m*Cos[a+b*x]*CosIntegral[c+d*x]/b +
  Dist[d/b,Int[x^m*Cos[a+b*x]*Cos[c+d*x]/(c+d*x),x]] +
  Dist[m/b,Int[x^(m-1)*Cos[a+b*x]*CosIntegral[c+d*x],x]] /;
FreeQ[{a,b,c,d},x] && IntegerQ[m] && m>0


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Derivation: Inverted integration by parts*)


(* ::Subsubsection:: *)
(*Rule: If  m\[Element]\[DoubleStruckCapitalZ] \[And] m<-1, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]x^m Cos[a+b x] SinIntegral[c+d x]\[DifferentialD]x  \[LongRightArrow]  ((x^(m+1) Cos[a+b x] SinIntegral[c+d x])/(m+1))-                   *)
(*       d/(m+1) \[Integral](x^(m+1) Cos[a+b x] Sin[c+d x])/(c+d x) \[DifferentialD]x+b/(m+1) \[Integral]x^(m+1) Sin[a+b x] SinIntegral[c+d x]\[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[x_^m_.*Cos[a_.+b_.*x_]*SinIntegral[c_.+d_.*x_],x_Symbol] :=
  x^(m+1)*Cos[a+b*x]*SinIntegral[c+d*x]/(m+1) -
  Dist[d/(m+1),Int[x^(m+1)*Cos[a+b*x]*Sin[c+d*x]/(c+d*x),x]] +
  Dist[b/(m+1),Int[x^(m+1)*Sin[a+b*x]*SinIntegral[c+d*x],x]] /;
FreeQ[{a,b,c,d},x] && IntegerQ[m] && m<-1


(* ::Code:: *)
Int[x_^m_*Sin[a_.+b_.*x_]*CosIntegral[c_.+d_.*x_],x_Symbol] :=
  x^(m+1)*Sin[a+b*x]*CosIntegral[c+d*x]/(m+1) -
  Dist[d/(m+1),Int[x^(m+1)*Sin[a+b*x]*Cos[c+d*x]/(c+d*x),x]] -
  Dist[b/(m+1),Int[x^(m+1)*Cos[a+b*x]*CosIntegral[c+d*x],x]] /;
FreeQ[{a,b,c,d},x] && IntegerQ[m] && m<-1


(* ::PageBreak:: *)
(**)
