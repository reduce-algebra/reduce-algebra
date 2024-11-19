(* ::Package:: *)

(* ::Title::Bold::Closed:: *)
(*\[Integral]ExpIntegralE[n,a+b x]\[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Basis: \[PartialD]ExpIntegralE[n,z]/\[PartialD]z==-ExpIntegralE[n-1,z]*)


(* ::Subsubsection:: *)
(*Rule:*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]ExpIntegralE[n,a+b x]\[DifferentialD]x  \[LongRightArrow]  -(ExpIntegralE[n+1,a+b x]/b)*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[ExpIntegralE[n_,a_.+b_.*x_],x_Symbol] :=
  -ExpIntegralE[n+1,a+b*x]/b /;
FreeQ[{a,b,n},x]


(* ::PageBreak:: *)
(**)


(* ::Title::Bold::Closed:: *)
(*\[Integral]x^m ExpIntegralE[n,a+b x]\[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Derivation: Integration by parts*)


(* ::Subsubsection:: *)
(*Rule: If  n\[Element]\[DoubleStruckCapitalZ] \[And] n>0, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]x^m ExpIntegralE[n,a+b x]\[DifferentialD]x  \[LongRightArrow]                                                                                             *)
(*                                 ((x^(m+1) ExpIntegralE[n,a+b x])/(m+1))+b/(m+1) \[Integral]x^(m+1) ExpIntegralE[n-1,a+b x]\[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[x_^m_.*ExpIntegralE[n_,a_.+b_.*x_],x_Symbol] :=
  x^(m+1)*ExpIntegralE[n,a+b*x]/(m+1) +
  Dist[b/(m+1),Int[x^(m+1)*ExpIntegralE[n-1,a+b*x],x]] /;
FreeQ[{a,b,m},x] && IntegerQ[n] && n>0


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Derivation: Inverted integration by parts*)


(* ::Subsubsection:: *)
(*Rule: If  n\[Element]\[DoubleStruckCapitalZ] \[And] n>0, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]x^m ExpIntegralE[n,a+b x]\[DifferentialD]x  \[LongRightArrow]                                                                                           *)
(*                                  -((x^m ExpIntegralE[n+1,a+b x])/b)+m/b \[Integral]x^(m-1) ExpIntegralE[n+1,a+b x]\[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[x_^m_.*ExpIntegralE[n_,a_.+b_.*x_],x_Symbol] :=
  -x^m*ExpIntegralE[n+1,a+b*x]/b +
  Dist[m/b,Int[x^(m-1)*ExpIntegralE[n+1,a+b*x],x]] /;
FreeQ[{a,b,m},x] && IntegerQ[n] && n<0


(* ::PageBreak:: *)
(**)


(* ::Title::Bold::Closed:: *)
(*\[Integral]ExpIntegralEi[a+b x]^n \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Derivation: Integration by parts*)


(* ::Subsubsection:: *)
(*Rule:*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]ExpIntegralEi[a+b x]\[DifferentialD]x  \[LongRightArrow]  (((a+b x) ExpIntegralEi[a+b x])/b)-E^(a+b x)/b*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[ExpIntegralEi[a_.+b_.*x_],x_Symbol] :=
  (a+b*x)*ExpIntegralEi[a+b*x]/b - E^(a+b*x)/b /;
FreeQ[{a,b},x]


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Derivation: Integration by parts*)


(* ::Subsubsection:: *)
(*Rule:*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]ExpIntegralEi[a+b x]^2 \[DifferentialD]x  \[LongRightArrow]  (((a+b x) ExpIntegralEi[a+b x]^2)/b)-2\[Integral]E^(a+b x) ExpIntegralEi[a+b x]\[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[ExpIntegralEi[a_.+b_.*x_]^2,x_Symbol] :=
  (a+b*x)*ExpIntegralEi[a+b*x]^2/b -
  Dist[2,Int[E^(a+b*x)*ExpIntegralEi[a+b*x],x]] /;
FreeQ[{a,b},x]


(* ::PageBreak:: *)
(**)


(* ::Title::Bold::Closed:: *)
(*\[Integral]x^m ExpIntegralEi[a+b x]^n \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Derivation: Integration by parts*)


(* ::Subsubsection:: *)
(*Rule: If  m+1!=0, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]x^m ExpIntegralEi[a+b x]\[DifferentialD]x  \[LongRightArrow]  ((x^(m+1) ExpIntegralEi[a+b x])/(m+1))-b/(m+1) \[Integral](x^(m+1) E^(a+b x))/(a+b x) \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[x_^m_.*ExpIntegralEi[a_.+b_.*x_],x_Symbol] :=
  x^(m+1)*ExpIntegralEi[a+b*x]/(m+1) -
  Dist[b/(m+1),Int[x^(m+1)*E^(a+b*x)/(a+b*x),x]] /;
FreeQ[{a,b,m},x] && NonzeroQ[m+1]


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Derivation: Integration by parts*)


(* ::Subsubsection:: *)
(*Rule: If  m\[Element]\[DoubleStruckCapitalZ] \[And] m>0, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]x^m ExpIntegralEi[b x]^2 \[DifferentialD]x  \[LongRightArrow]  ((x^(m+1) ExpIntegralEi[b x]^2)/(m+1))-2/(m+1) \[Integral]x^m E^(b x) ExpIntegralEi[b x]\[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[x_^m_.*ExpIntegralEi[b_.*x_]^2,x_Symbol] :=
  x^(m+1)*ExpIntegralEi[b*x]^2/(m+1) -
  Dist[2/(m+1),Int[x^m*E^(b*x)*ExpIntegralEi[b*x],x]] /;
FreeQ[b,x] && IntegerQ[m] && m>0


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Derivation: Iterated integration by parts*)


(* ::Subsubsection:: *)
(*Rule: If  m\[Element]\[DoubleStruckCapitalZ] \[And] m>0, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]x^m ExpIntegralEi[a+b x]^2 \[DifferentialD]x  \[LongRightArrow]  ((x^(m+1) ExpIntegralEi[a+b x]^2)/(m+1))+(a x^m ExpIntegralEi[a+b x]^2)/(b (m+1))-*)
(*                                       2/(m+1) \[Integral]x^m E^(a+b x) ExpIntegralEi[a+b x]\[DifferentialD]x-(a m)/(b (m+1)) \[Integral]x^(m-1) ExpIntegralEi[a+b x]^2 \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[x_^m_.*ExpIntegralEi[a_+b_.*x_]^2,x_Symbol] :=
  x^(m+1)*ExpIntegralEi[a+b*x]^2/(m+1) +
  a*x^m*ExpIntegralEi[a+b*x]^2/(b*(m+1)) -
  Dist[2/(m+1),Int[x^m*E^(a+b*x)*ExpIntegralEi[a+b*x],x]] -
  Dist[a*m/(b*(m+1)),Int[x^(m-1)*ExpIntegralEi[a+b*x]^2,x]] /;
FreeQ[{a,b},x] && IntegerQ[m] && m>0


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Derivation: Inverted integration by parts*)


(* ::Subsubsection:: *)
(*Rule: If  m\[Element]\[DoubleStruckCapitalZ] \[And] m<-2, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]x^m ExpIntegralEi[a+b x]^2 \[DifferentialD]x  \[LongRightArrow]  ((b x^(m+2) ExpIntegralEi[a+b x]^2)/(a (m+1)))+(x^(m+1) ExpIntegralEi[a+b x]^2)/(m+1)-        *)
(*                      (2 b)/(a (m+1)) \[Integral]x^(m+1) E^(a+b x) ExpIntegralEi[a+b x]\[DifferentialD]x-(b (m+2))/(a (m+1)) \[Integral]x^(m+1) ExpIntegralEi[a+b x]^2 \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
(* Int[x_^m_.*ExpIntegralEi[a_+b_.*x_]^2,x_Symbol] :=
  b*x^(m+2)*ExpIntegralEi[a+b*x]^2/(a*(m+1)) +
  x^(m+1)*ExpIntegralEi[a+b*x]^2/(m+1) -
  Dist[2*b/(a*(m+1)),Int[x^(m+1)*E^(a+b*x)*ExpIntegralEi[a+b*x],x]] -
  Dist[b*(m+2)/(a*(m+1)),Int[x^(m+1)*ExpIntegralEi[a+b*x]^2,x]] /;
FreeQ[{a,b},x] && IntegerQ[m] && m<-2 *)


(* ::PageBreak:: *)
(**)


(* ::Title::Bold::Closed:: *)
(*\[Integral]E^(a+b x) ExpIntegralEi[c+d x]\[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Derivation: Integration by parts*)


(* ::Subsubsection:: *)
(*Rule:*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]E^(a+b x) ExpIntegralEi[c+d x]\[DifferentialD]x  \[LongRightArrow]  ((E^(a+b x) ExpIntegralEi[c+d x])/b)-d/b \[Integral](E^(a+b x) E^(c+d x))/(c+d x) \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[E^(a_.+b_.*x_)*ExpIntegralEi[c_.+d_.*x_],x_Symbol] :=
  E^(a+b*x)*ExpIntegralEi[c+d*x]/b -
  Dist[d/b,Int[E^(a+b*x)*E^(c+d*x)/(c+d*x),x]] /;
FreeQ[{a,b,c,d},x]


(* ::PageBreak:: *)
(**)


(* ::Title::Bold::Closed:: *)
(*\[Integral]x^m E^(a+b x) ExpIntegralEi[c+d x]\[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Derivation: Integration by parts*)


(* ::Subsubsection:: *)
(*Rule: If  m\[Element]\[DoubleStruckCapitalZ] \[And] m>0, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]x^m E^(a+b x) ExpIntegralEi[c+d x]\[DifferentialD]x  \[LongRightArrow]  ((x^m E^(a+b x) ExpIntegralEi[c+d x])/b)-                   *)
(*                                                                 d/b \[Integral](x^m E^(a+b x) E^(c+d x))/(c+d x) \[DifferentialD]x-m/b \[Integral]x^(m-1) E^(a+b x) ExpIntegralEi[c+d x]\[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[x_^m_.*E^(a_.+b_.*x_)*ExpIntegralEi[c_.+d_.*x_],x_Symbol] :=
  x^m*E^(a+b*x)*ExpIntegralEi[c+d*x]/b -
  Dist[d/b,Int[x^m*E^(a+b*x)*E^(c+d*x)/(c+d*x),x]] -
  Dist[m/b,Int[x^(m-1)*E^(a+b*x)*ExpIntegralEi[c+d*x],x]] /;
FreeQ[{a,b,c,d},x] && IntegerQ[m] && m>0


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Derivation: Inverted integration by parts*)


(* ::Subsubsection:: *)
(*Rule: If  m\[Element]\[DoubleStruckCapitalZ] \[And] m<-1, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]x^m E^(a+b x) ExpIntegralEi[c+d x]\[DifferentialD]x  \[LongRightArrow]  ((x^(m+1) E^(a+b x) ExpIntegralEi[c+d x])/(m+1))-               *)
(*                                               d/(m+1) \[Integral](x^(m+1) E^(a+b x) E^(c+d x))/(c+d x) \[DifferentialD]x-b/(m+1) \[Integral]x^(m+1) E^(a+b x) ExpIntegralEi[c+d x]\[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[x_^m_*E^(a_.+b_.*x_)*ExpIntegralEi[c_.+d_.*x_],x_Symbol] :=
  x^(m+1)*E^(a+b*x)*ExpIntegralEi[c+d*x]/(m+1) -
  Dist[d/(m+1),Int[x^(m+1)*E^(a+b*x)*E^(c+d*x)/(c+d*x),x]] -
  Dist[b/(m+1),Int[x^(m+1)*E^(a+b*x)*ExpIntegralEi[c+d*x],x]] /;
FreeQ[{a,b,c,d},x] && IntegerQ[m] && m<-1


(* ::PageBreak:: *)
(**)
