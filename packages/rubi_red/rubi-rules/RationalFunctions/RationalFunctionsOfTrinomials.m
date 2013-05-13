(* ::Package:: *)

(* ::Title::Bold::Closed:: *)
(*\[Integral]1/(a+b x+c x^2) \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Reference: G&R 2.172.2, CRC 110a, A&S 3.3.17*)


(* ::Subsubsection:: *)
(*Derivation: Integration by substitution*)


(* ::Subsubsection:: *)
(*Basis: 1/(a+b x+c x^2)=-(2/Sqrt[b^2-4 a c]) 1/(1-((b+2 c x)/Sqrt[b^2-4 a c])^2) \!\( *)
(*\*SubscriptBox[\(\[PartialD]\), \(x\)]\(( *)
(*\*FractionBox[\(b + 2\ c\ x\), *)
(*SqrtBox[\( *)
(*\*SuperscriptBox[\(b\), \(2\)] - 4\ a\ c\)]])\)\)*)


(* ::Subsubsection:: *)
(*Rule: If  b^2-4 a c>0, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]1/(a+b x+c x^2) \[DifferentialD]x  \[LongRightArrow]  -(2/Sqrt[b^2-4 a c])ArcTanh[(b+2 c x)/Sqrt[b^2-4 a c]]*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[1/(a_+b_.*x_+c_.*x_^2),x_Symbol] :=
  Module[{q=Rt[b^2-4*a*c,2]},
  -2*ArcTanh[b/q+2*c*x/q]/q /;
 RationalQ[q] || SqrtNumberQ[q] && RationalQ[b/q]] /;
FreeQ[{a,b,c},x] && PosQ[b^2-4*a*c]


(* ::Code:: *)
Int[1/(a_+b_.*x_+c_.*x_^2),x_Symbol] :=
  -2*ArcTanh[(b+2*c*x)/Rt[b^2-4*a*c,2]]/Rt[b^2-4*a*c,2] /;
FreeQ[{a,b,c},x] && PosQ[b^2-4*a*c]


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Reference: G&R 2.172.4, CRC 109, A&S 3.3.16*)


(* ::Subsubsection:: *)
(*Derivation: Integration by substitution*)


(* ::Subsubsection:: *)
(*Basis: 1/(a+b x+c x^2)=2/Sqrt[4 a c-b^2] 1/(1+((b+2 c x)/Sqrt[4 a c-b^2])^2) \!\( *)
(*\*SubscriptBox[\(\[PartialD]\), \(x\)]\(( *)
(*\*FractionBox[\(b + 2\ c\ x\), *)
(*SqrtBox[\(4\ a\ c - *)
(*\*SuperscriptBox[\(b\), \(2\)]\)]])\)\)*)


(* ::Subsubsection:: *)
(*Rule: If  \[Not](b^2-4 a c>0), then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]1/(a+b x+c x^2) \[DifferentialD]x  \[LongRightArrow]  (2/Sqrt[4 a c-b^2])ArcTan[(b+2 c x)/Sqrt[4 a c-b^2]]*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[1/(a_+b_.*x_+c_.*x_^2),x_Symbol] :=
  Module[{q=Rt[4*a*c-b^2,2]},
  2*ArcTan[b/q+2*c*x/q]/q /;
 RationalQ[q] || SqrtNumberQ[q] && RationalQ[b/q]] /;
FreeQ[{a,b,c},x] && NegQ[b^2-4*a*c]


(* ::Code:: *)
Int[1/(a_+b_.*x_+c_.*x_^2),x_Symbol] :=
  2*ArcTan[(b+2*c*x)/Rt[4*a*c-b^2,2]]/Rt[4*a*c-b^2,2] /;
FreeQ[{a,b,c},x] && NegQ[b^2-4*a*c]


(* ::PageBreak:: *)
(**)


(* ::Title::Bold::Closed:: *)
(*\[Integral](a+b x+c x^2)^n \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Derivation: Algebraic simplification*)


(* ::Subsubsection:: *)
(*Basis: If  b^2-4 a c=0, then a+b z+c z^2=1/c (b/2+c z)^2*)


(* ::Subsubsection:: *)
(*Rule: If  n\[Element]\[DoubleStruckCapitalZ] \[And] b^2-4 a c=0, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral](a+b x+c x^2)^n \[DifferentialD]x  \[LongRightArrow]  (1/c^n)\[Integral](b/2+c x)^(2 n) \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[(a_+b_.*x_+c_.*x_^2)^n_,x_Symbol] :=
  Int[(b/2+c*x)^(2*n),x]/c^n /;
FreeQ[{a,b,c},x] && IntegerQ[n] && ZeroQ[b^2-4*a*c]


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Reference: G&R 2.171.3, GR5 2.263.3, CRC 113*)


(* ::Subsubsection:: *)
(*Rule: If  n\[Element]\[DoubleStruckCapitalZ] \[And] n<-1 \[And] b^2-4 a c!=0, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral](a+b x+c x^2)^n \[DifferentialD]x  \[LongRightArrow]  (((b+2 c x) (a+b x+c x^2)^(n+1))/((n+1) (b^2-4 a c)))-(2 c (2 n+3))/((n+1) (b^2-4 a c)) \[Integral](a+b x+c x^2)^(n+1) \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[(a_+b_.*x_+c_.*x_^2)^n_,x_Symbol] :=
  (b+2*c*x)*(a+b*x+c*x^2)^(n+1)/((n+1)*(b^2-4*a*c)) -
  Dist[2*c*(2*n+3)/((n+1)*(b^2-4*a*c)),Int[(a+b*x+c*x^2)^(n+1),x]] /;
FreeQ[{a,b,c},x] && IntegerQ[n] && n<-1 && NonzeroQ[b^2-4*a*c]


(* ::PageBreak:: *)
(**)


(* ::Title::Bold::Closed:: *)
(*\[Integral](d+e x)/(a+b x+c x^2) \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Reference: G&R 2.175.1, CRC 114*)


(* ::Subsubsection:: *)
(*Rule: If  2 c d-b e=0, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral](d+e x)/(-a+b x+c x^2) \[DifferentialD]x  \[LongRightArrow]  ((e Log[a-b x-c x^2])/(2 c))*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[(d_.+e_.*x_)/(a_+b_.*x_+c_.*x_^2),x_Symbol] :=
  e*Log[-a-b*x-c*x^2]/(2*c) /;
FreeQ[{a,b,c,d,e},x] && ZeroQ[2*c*d-b*e] && NegativeCoefficientQ[a]


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Reference: G&R 2.175.1, CRC 114*)


(* ::Subsubsection:: *)
(*Rule: If  2 c d-b e=0, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral](d+e x)/(a+b x+c x^2) \[DifferentialD]x  \[LongRightArrow]  ((e Log[a+b x+c x^2])/(2 c))*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[(d_.+e_.*x_)/(a_+b_.*x_+c_.*x_^2),x_Symbol] :=
  e*Log[a+b*x+c*x^2]/(2*c) /;
FreeQ[{a,b,c,d,e},x] && ZeroQ[2*c*d-b*e]


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Reference: A&S 3.3.19*)


(* ::Subsubsection:: *)
(*Rule: If  Sqrt[b^2-4 a c]\[NotElement]\[DoubleStruckCapitalQ] \[And] a e^2+c d^2-b d e!=0, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral](d+e x)/(-a+b x+c x^2) \[DifferentialD]x  \[LongRightArrow]  ((e Log[a-b x-c x^2])/(2 c))+(2 c d-b e)/(2 c) \[Integral]1/(-a+b x+c x^2) \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[(d_.+e_.*x_)/(a_+b_.*x_+c_.*x_^2),x_Symbol] :=
  e*Log[-a-b*x-c*x^2]/(2*c) +
  Dist[Simplify[(2*c*d-b*e)/(2*c)],Int[1/(a+b*x+c*x^2),x]] /;
FreeQ[{a,b,c,d,e},x] && Not[RationalQ[Rt[b^2-4*a*c,2]]] && NonzeroQ[a*e^2+c*d^2-b*d*e] && 
NegativeCoefficientQ[a]


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Reference: A&S 3.3.19*)


(* ::Subsubsection:: *)
(*Rule: If  Sqrt[b^2-4 a c]\[NotElement]\[DoubleStruckCapitalQ] \[And] a e^2+c d^2-b d e!=0, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral](d+e x)/(a+b x+c x^2) \[DifferentialD]x  \[LongRightArrow]  ((e Log[a+b x+c x^2])/(2 c))+(2 c d-b e)/(2 c) Int[1/(a+b x+c x^2),x]*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[(d_.+e_.*x_)/(a_+b_.*x_+c_.*x_^2),x_Symbol] :=
  e*Log[a+b*x+c*x^2]/(2*c) +
  Dist[Simplify[(2*c*d-b*e)/(2*c)],Int[1/(a+b*x+c*x^2),x]] /;
FreeQ[{a,b,c,d,e},x] && Not[RationalQ[Rt[b^2-4*a*c,2]]] && NonzeroQ[a*e^2+c*d^2-b*d*e]


(* ::PageBreak:: *)
(**)


(* ::Title::Bold::Closed:: *)
(*\[Integral](d+e x)^m (a+b x+c x^2)^n \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Derivation: Algebraic simplification*)


(* ::Subsubsection:: *)
(*Basis: If  a e^2-b d e+c d^2=0, then a+b x+c x^2=(d+e x) (a/d+(c x)/e)*)


(* ::Subsubsection:: *)
(*Rule: If  a e^2-b d e+c d^2=0 \[And] n\[Element]\[DoubleStruckCapitalZ], then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral](d+e x)^m (a+b x+c x^2)^n \[DifferentialD]x  \[LongRightArrow]  \[Integral](d+e x)^(m+n) (a/d+(c x)/e)^n \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[(d_+e_.*x_)^m_.*(a_.+b_.*x_+c_.*x_^2)^n_.,x_Symbol] :=
  Int[(d+e*x)^(m+n)*(a/d+c/e*x)^n,x] /;
FreeQ[{a,b,c,d,e,m},x] && ZeroQ[a*e^2-b*d*e+c*d^2] && IntegerQ[n]


(* ::Code:: *)
Int[(d_+e_.*x_)^m_.*(a_+c_.*x_^2)^n_.,x_Symbol] :=
  Int[(d+e*x)^(m+n)*(a/d+c/e*x)^n,x] /;
FreeQ[{a,c,d,e,m},x] && ZeroQ[a*e^2+c*d^2] && IntegerQ[n]


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Rule: If  a e^2+c d^2=0 \[And] m+2 (n+1)=0 \[And] n\[NotElement]\[DoubleStruckCapitalZ], then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral](d+e x)^m (a+c x^2)^n \[DifferentialD]x  \[LongRightArrow]  ((e (d+e x)^m (a+c x^2)^(n+1))/(2 c d (n+1)))*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[(d_+e_.*x_)^m_*(a_+c_.*x_^2)^n_,x_Symbol] :=
  e*(d+e*x)^m*(a+c*x^2)^(n+1)/(2*c*d*(n+1)) /;
FreeQ[{a,c,d,e,m,n},x] && ZeroQ[a*e^2+c*d^2] && ZeroQ[m+2*(n+1)] && Not[IntegerQ[n]]


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Rule: If  a e^2+c d^2=0 \[And] m+n+1!=0 \[And] m+2 (n+1)!=0 \[And] m<-1 \[And] n\[NotElement]\[DoubleStruckCapitalZ], then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral](d+e x)^m (a+c x^2)^n \[DifferentialD]x  \[LongRightArrow]  -((e (d+e x)^m (a+c x^2)^(n+1))/(2 c d (m+n+1)))+(m+2 (n+1))/(2 d (m+n+1)) \[Integral](d+e x)^(m+1) (a+c x^2)^n \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[(d_+e_.*x_)^m_*(a_+c_.*x_^2)^n_,x_Symbol] :=
  -e*(d+e*x)^m*(a+c*x^2)^(n+1)/(2*c*d*(m+n+1)) +
  Dist[(m+2*(n+1))/(2*d*(m+n+1)),Int[(d+e*x)^(m+1)*(a+c*x^2)^n,x]] /;
FreeQ[{a,c,d,e,n},x] && ZeroQ[a*e^2+c*d^2] && NonzeroQ[m+n+1] && NonzeroQ[m+2*(n+1)] && 
  RationalQ[m] && m<-1 && Not[IntegerQ[n]]


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Reference: G&R 2.174.2*)


(* ::Subsubsection:: *)
(*Rule: If  n<-1 \[And] m+2n+1=0 \[And] 2c d-b e=0, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral](d+e x)^m (a+b x+c x^2)^n \[DifferentialD]x  \[LongRightArrow]  -((e (d+e x)^(m-1) (a+b x+c x^2)^(n+1))/(c (m-1)))+e^2/c \[Integral](d+e x)^(m-2) (a+b x+c x^2)^(n+1) \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[(d_.+e_.*x_)^m_*(a_.+b_.*x_+c_.*x_^2)^n_,x_Symbol] :=
  -e*(d+e*x)^(m-1)*(a+b*x+c*x^2)^(n+1)/(c*(m-1)) +
  Dist[e^2/c,Int[(d+e*x)^(m-2)*(a+b*x+c*x^2)^(n+1),x]] /;
FreeQ[{a,b,c,d,e},x] && RationalQ[{m,n}] && n<-1 && ZeroQ[m+2*n+1] && ZeroQ[2*c*d-b*e]


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Reference: G&R 2.174.1, CRC 119*)


(* ::Subsubsection:: *)
(*Rule: If  2c d-b e=0 \[And] n+1!=0, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral](d+e x) (a+b x+c x^2)^n \[DifferentialD]x  \[LongRightArrow]  ((e (a+b x+c x^2)^(n+1))/(2 c (n+1)))*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[(d_.+e_.*x_)*(a_.+b_.*x_+c_.*x_^2)^n_,x_Symbol] :=
  e*(a+b*x+c*x^2)^(n+1)/(2*c*(n+1)) /;
FreeQ[{a,b,c,d,e,n},x] && ZeroQ[2*c*d-b*e] && NonzeroQ[n+1]


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Reference: G&R 2.174.1, CRC 119*)


(* ::Subsubsection:: *)
(*Rule: If  n+1!=0 \[And] \[Not](n\[Element]\[DoubleStruckCapitalZ]  \[And] n>0) \[And] 2c d-b e!=0, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral](d+e x) (a+b x+c x^2)^n \[DifferentialD]x  \[LongRightArrow]  ((e (a+b x+c x^2)^(n+1))/(2 c (n+1)))+(2 c d-b e)/(2 c) \[Integral](a+b x+c x^2)^n \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[(d_.+e_.*x_)*(a_.+b_.*x_+c_.*x_^2)^n_,x_Symbol] :=
  e*(a+b*x+c*x^2)^(n+1)/(2*c*(n+1)) +
  Dist[(2*c*d-b*e)/(2*c),Int[(a+b*x+c*x^2)^n,x]] /;
FreeQ[{a,b,c,d,e,n},x] && NonzeroQ[n+1] && Not[IntegerQ[n] && n>0] && NonzeroQ[2*c*d-b*e]


(* ::Code:: *)
Int[(d_+e_.*x_)*(a_.+c_.*x_^2)^n_,x_Symbol] :=
  e*(a+c*x^2)^(n+1)/(2*c*(n+1)) +
  Dist[d,Int[(a+c*x^2)^n,x]] /;
FreeQ[{a,c,d,e,n},x] && NonzeroQ[n+1] && Not[IntegerQ[n] && n>0]


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Reference: G&R 2.174.1, CRC 119*)


(* ::Subsubsection:: *)
(*Rule: If  m>1 \[And] m+2n+1!=0 \[And] \[Not](n\[Element]\[DoubleStruckCapitalZ]  \[And] n>=-1) \[And] (m+n=0 \[Or] 2 c d-b e=0), then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral](d+e x)^m (a+b x+c x^2)^n \[DifferentialD]x  \[LongRightArrow]                                                                                                                        *)
(*            ((e (d+e x)^(m-1) (a+b x+c x^2)^(n+1))/(c (m+2 n+1)))-((a e^2-b d e+c d^2) (m-1))/(c (m+2 n+1)) \[Integral](d+e x)^(m-2) (a+b x+c x^2)^n \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[(d_.+e_.*x_)^m_*(a_.+b_.*x_+c_.*x_^2)^n_,x_Symbol] :=
  e*(d+e*x)^(m-1)*(a+b*x+c*x^2)^(n+1)/(c*(m+2*n+1)) -
  Dist[(a*e^2-b*d*e+c*d^2)*(m-1)/(c*(m+2*n+1)),Int[(d+e*x)^(m-2)*(a+b*x+c*x^2)^n,x]] /;
FreeQ[{a,b,c,d,e,n},x] && RationalQ[m] && m>1 && NonzeroQ[m+2*n+1] && Not[IntegerQ[n] && n>=-1] && 
(ZeroQ[m+n] || ZeroQ[2*c*d-b*e])


(* ::Code:: *)
Int[(d_+e_.*x_)^m_*(a_.+c_.*x_^2)^n_,x_Symbol] :=
  -e*(d+e*x)^(m-1)/(c*(m-1)*(a+c*x^2)^(m-1)) +
  Dist[(a*e^2+c*d^2)/c,Int[(d+e*x)^(m-2)/(a+c*x^2)^m,x]] /;
FreeQ[{a,c,d,e,n},x] && RationalQ[m] && m>1 && ZeroQ[m+n]


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Reference: G&R 2.174.1, CRC 119*)


(* ::Subsubsection:: *)
(*Rule: If  m>1 \[And] m+2n+1!=0 \[And] \[Not](n\[Element]\[DoubleStruckCapitalZ]  \[And] n>=-1) \[And] a e^2-b d e+c d^2=0, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral](d+e x)^m (a+b x+c x^2)^n \[DifferentialD]x  \[LongRightArrow]                                                                                                                     *)
(*                         ((e (d+e x)^(m-1) (a+b x+c x^2)^(n+1))/(c (m+2 n+1)))+((2 c d-b e) (m+n))/(c (m+2 n+1)) \[Integral](d+e x)^(m-1) (a+b x+c x^2)^n \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[(d_.+e_.*x_)^m_.*(a_.+b_.*x_+c_.*x_^2)^n_,x_Symbol] :=
  e*(d+e*x)^(m-1)*(a+b*x+c*x^2)^(n+1)/(c*(m+2*n+1)) +
  Dist[(2*c*d-b*e)*(m+n)/(c*(m+2*n+1)),Int[(d+e*x)^(m-1)*(a+b*x+c*x^2)^n,x]] /;
FreeQ[{a,b,c,d,e,n},x] && RationalQ[m] && m>1 && NonzeroQ[m+2*n+1] && Not[IntegerQ[n] && n>=-1] &&
ZeroQ[a*e^2-b*d*e+c*d^2]


(* ::Code:: *)
Int[(d_+e_.*x_)^m_.*(a_.+c_.*x_^2)^n_,x_Symbol] :=
  e*(d+e*x)^(m-1)*(a+c*x^2)^(n+1)/(c*(m+2*n+1)) +
  Dist[2*c*d*(m+n)/(c*(m+2*n+1)),Int[(d+e*x)^(m-1)*(a+c*x^2)^n,x]] /;
FreeQ[{a,c,d,e,n},x] && RationalQ[m] && m>1 && NonzeroQ[m+2*n+1] && Not[IntegerQ[n] && n>=-1] &&
ZeroQ[a*e^2+c*d^2]


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Reference: G&R 2.265c special case*)


(* ::Subsubsection:: *)
(*Rule: If  m+n+1!=0 \[And] m+2(n+1)=0, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]x^m (b x+c x^2)^n \[DifferentialD]x  \[LongRightArrow]  ((x^m (b x+c x^2)^(n+1))/(b (m+n+1)))*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[x_^m_*(b_.*x_+c_.*x_^2)^n_,x_Symbol] :=
  x^m*(b*x+c*x^2)^(n+1)/(b*(m+n+1)) /;
FreeQ[{b,c,m,n},x] && NonzeroQ[m+n+1] && ZeroQ[m+2*(n+1)]


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Reference: G&R 2.265c*)


(* ::Subsubsection:: *)
(*Rule: If  m<-1 \[And] m+n+1!=0 \[And] \[Not](n\[Element]\[DoubleStruckCapitalZ]  \[And] n>=-1), then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]x^m (b x+c x^2)^n \[DifferentialD]x  \[LongRightArrow]  ((x^m (b x+c x^2)^(n+1))/(b (m+n+1)))-(c (m+2 (n+1)))/(b (m+n+1)) \[Integral]x^(m+1) (b x+c x^2)^n \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[x_^m_*(b_.*x_+c_.*x_^2)^n_,x_Symbol] :=
  x^m*(b*x+c*x^2)^(n+1)/(b*(m+n+1)) -
  Dist[c*(m+2*(n+1))/(b*(m+n+1)),Int[x^(m+1)*(b*x+c*x^2)^n,x]] /;
FreeQ[{b,c,n},x] && RationalQ[m] && m<-1 && NonzeroQ[m+n+1] && Not[IntegerQ[n] && n>=-1]


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Reference: G&R 2.176, CRC 123*)


(* ::Subsubsection:: *)
(*Rule: If  m<-1 \[And] a e^2-b d e+c d^2!=0 \[And] \[Not](n\[Element]\[DoubleStruckCapitalZ]  \[And] n>=-1) \[And] m+2n+3=0, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral](d+e x)^m (a+b x+c x^2)^n \[DifferentialD]x  \[LongRightArrow]                                                                                                            *)
(*                         ((e (d+e x)^(m+1) (a+b x+c x^2)^(n+1))/((m+1) (a e^2-b d e+c d^2)))+((2 c d-b e) (m+n+2))/((m+1) (a e^2-b d e+c d^2)) \[Integral](d+e x)^(m+1) (a+b x+c x^2)^n \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[(d_.+e_.*x_)^m_*(a_+b_.*x_+c_.*x_^2)^n_,x_Symbol] :=
  e*(d+e*x)^(m+1)*(a+b*x+c*x^2)^(n+1)/((m+1)*(a*e^2-b*d*e+c*d^2)) +
  Dist[(2*c*d-b*e)*(m+n+2)/((m+1)*(a*e^2-b*d*e+c*d^2)),Int[(d+e*x)^(m+1)*(a+b*x+c*x^2)^n,x]] /;
FreeQ[{a,b,c,d,e,n},x] && RationalQ[m] && m<-1 && NonzeroQ[a*e^2-b*d*e+c*d^2] && 
Not[IntegerQ[n] && n>=-1] && ZeroQ[m+2*n+3]


(* ::Code:: *)
Int[(d_+e_.*x_)^m_*(a_+c_.*x_^2)^n_,x_Symbol] :=
  e*(d+e*x)^(m+1)*(a+c*x^2)^(n+1)/((m+1)*(a*e^2+c*d^2)) +
  Dist[2*c*d*(m+n+2)/((m+1)*(a*e^2+c*d^2)),Int[(d+e*x)^(m+1)*(a+c*x^2)^n,x]] /;
FreeQ[{a,c,d,e,n},x] && RationalQ[m] && m<-1 && NonzeroQ[a*e^2+c*d^2] && 
Not[IntegerQ[n] && n>=-1] && ZeroQ[m+2*n+3]


(* ::PageBreak:: *)
(**)


(* ::Subsubsection:: *)
(* *)


(* ::Title::Bold::Closed:: *)
(*\[Integral]1/(a+b x^2+c x^4) \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Derivation: Algebraic expansion*)


(* ::Subsubsection:: *)
(*Basis: Let q=Sqrt[a/c], then 1/(a+b x^2+c x^4)=(c q (q+x^2))/(2 a (a+b x^2+c x^4))+(c q (q-x^2))/(2 a (a+b x^2+c x^4))*)


(* ::Subsubsection:: *)
(*Note: Although resulting integrands appear more complicated than the original one, they are of the form required for the first two rules in the next section.*)


(* ::Subsubsection:: *)
(*Rule: If  b^2-4 a c!=0 \[And] a/c>0 \[And] (b^2-4 a c<0 \[Or] (a/c\[Element]\[DoubleStruckCapitalQ] \[And] \[Not](b^2-4 a c>0))), let q=Sqrt[a/c], then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]1/(a+b x^2+c x^4) \[DifferentialD]x  \[LongRightArrow]  ((c q)/(2 a))\[Integral](q+x^2)/(a+b x^2+c x^4) \[DifferentialD]x+(c q)/(2 a) \[Integral](q-x^2)/(a+b x^2+c x^4) \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[1/(a_+b_.*x_^2+c_.*x_^4), x_Symbol] :=
  Module[{q=Rt[a/c,2]},
  Dist[c*q/(2*a),Int[(q+x^2)/(a+b*x^2+c*x^4),x]] +
  Dist[c*q/(2*a),Int[(q-x^2)/(a+b*x^2+c*x^4),x]]] /;
FreeQ[{a,b,c},x] && NonzeroQ[b^2-4*a*c] && PosQ[a/c] && 
(NegativeQ[b^2-4*a*c] || RationalQ[a/c] && Not[PositiveQ[b^2-4*a*c]])


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Derivation: Algebraic expansion*)


(* ::Subsubsection:: *)
(*Basis: Let q=Sqrt[-(a/c)], then 1/(a+b x^2+c x^4)=-((c q (q+x^2))/(2 a(a+b x^2+c x^4)))-(c q (q-x^2))/(2 a(a+b x^2+c x^4))*)


(* ::Subsubsection:: *)
(*Note: Although resulting integrands appear more complicated than the original one, they are of the form required for the first two rules in the next section.*)


(* ::Subsubsection:: *)
(*Rule: If  b^2-4 a c!=0 \[And] \[Not](a/c>0) \[And] (b^2-4 a c<0 \[Or] (a/c\[Element]\[DoubleStruckCapitalQ] \[And] \[Not](b^2-4 a c>0))), let q=Sqrt[-(a/c)], then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]1/(a+b x^2+c x^4) \[DifferentialD]x  \[LongRightArrow]  -((c q)/(2 a))\[Integral](q+x^2)/(a+b x^2+c x^4) \[DifferentialD]x-(c q)/(2 a) \[Integral](q-x^2)/(a+b x^2+c x^4) \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[1/(a_+b_.*x_^2+c_.*x_^4), x_Symbol] :=
  Module[{q=Rt[-a/c,2]},
  -Dist[c*q/(2*a),Int[(q+x^2)/(a+b*x^2+c*x^4),x]] -
  Dist[c*q/(2*a),Int[(q-x^2)/(a+b*x^2+c*x^4),x]]] /;
FreeQ[{a,b,c},x] && NonzeroQ[b^2-4*a*c] && NegQ[a/c] &&
(NegativeQ[b^2-4*a*c] || RationalQ[a/c] && Not[PositiveQ[b^2-4*a*c]])


(* ::PageBreak:: *)
(**)


(* ::Title::Bold::Closed:: *)
(*\[Integral](d+e x^2)/(a+b x^2+c x^4) \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Note: Previously undiscovered rule?*)


(* ::Subsubsection:: *)
(*Rule: If  b^2-4 a c!=0 \[And] c d^2-a e^2=0 \[And] \[Not]((b d+2 a e)/(a d)>0), then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral](d+e x^2)/(a+b x^2+c x^4) \[DifferentialD]x  \[LongRightArrow]  (d/(a Sqrt[-((b d+2 a e)/(a d))]))ArcTanh[(d Sqrt[-((b d+2 a e)/(a d))] x)/(d-e x^2)]*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[(d_+e_.*x_^2)/(a_+b_.*x_^2+c_.*x_^4), x_Symbol] :=
  d/(a*Rt[-(b*d+2*a*e)/(a*d),2])*ArcTanh[d*Rt[-(b*d+2*a*e)/(a*d),2]*x/(d-e*x^2)] /;
FreeQ[{a,b,c,d,e},x] && NonzeroQ[b^2-4*a*c] && ZeroQ[c*d^2-a*e^2] && NegQ[(b*d+2*a*e)/(a*d)]


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Note: Although this rule would produce superficially simpler antiderivatives than the following rule, unfortunately they are discontinuous at the points x=a/c and x=-(a/c).*)


(* ::Subsubsection:: *)
(*Rule: If  b^2-4 a c!=0 \[And] c d^2-a e^2=0 \[And] (b d+2 a e)/(a d)>0, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral](d+e x^2)/(a+b x^2+c x^4) \[DifferentialD]x  \[LongRightArrow]  (d/(a Sqrt[(b d+2 a e)/(a d)]))ArcTan[(d Sqrt[(b d+2 a e)/(a d)] x)/(d-e x^2)]*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
(* Int[(d_+e_.*x_^2)/(a_+b_.*x_^2+c_.*x_^4), x_Symbol] :=
  d/(a*Rt[(b*d+2*a*e)/(a*d),2])*ArcTan[d*Rt[(b*d+2*a*e)/(a*d),2]*x/(d-e*x^2)] /;
FreeQ[{a,b,c,d,e},x] && NonzeroQ[b^2-4*a*c] && ZeroQ[c*d^2-a*e^2] && PosQ[(b*d+2*a*e)/(a*d)] *)


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Derivation: Algebraic expansion*)


(* ::Subsubsection:: *)
(*Basis: If  c d^2-a e^2=0, let q=(c d)/e and r=Sqrt[2c q-b c], then (d+e x^2)/(a+b x^2+c x^4)=e/(2(q+r x+c x^2))+e/(2(q-r x+c x^2))*)


(* ::Subsubsection:: *)
(*Rule: If  b^2-4 a c!=0 \[And] c d^2-a e^2=0, let q=(c d)/e, if  2c q-b c>0, let r=Sqrt[2c q-b c], then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral](d+e x^2)/(a+b x^2+c x^4) \[DifferentialD]x  \[LongRightArrow]  (e/2)\[Integral]1/(q-r x+c x^2) \[DifferentialD]x+e/2 \[Integral]1/(q+r x+c x^2) \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[(d_+e_.*x_^2)/(a_+b_.*x_^2+c_.*x_^4), x_Symbol] :=
  Module[{q=c*d/e},
  Module[{r=Rt[2*c*q-b*c,2]},
  Dist[e/2,Int[1/(q-r*x+c*x^2),x]] + 
  Dist[e/2,Int[1/(q+r*x+c*x^2),x]]] /;
 Not[NegativeQ[2*c*q-b*c]]] /;
FreeQ[{a,b,c,d,e},x] && NonzeroQ[b^2-4*a*c] && ZeroQ[c*d^2-a*e^2] && PosQ[(b*d+2*a*e)/(a*d)]


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Derivation: Algebraic expansion*)


(* ::Subsubsection:: *)
(*Basis: Let q=Sqrt[a/c], then (d+e x^2)/(a+b x^2+c x^4)=((q c d+a e) (q+x^2))/(2 a(a+b x^2+c x^4))+((q c d-a e) (q-x^2))/(2 a(a+b x^2+c x^4))*)


(* ::Subsubsection:: *)
(*Note: Resulting integrands are of the form of the first two rules in this section.*)


(* ::Subsubsection:: *)
(*Rule: If  b^2-4 a c!=0 \[And] c d^2-a e^2!=0\[And] a/c>0 \[And] (b^2-4 a c<0 \[Or] (a/c\[Element]\[DoubleStruckCapitalQ] \[And] \[Not](b^2-4 a c>0))), let q=Sqrt[a/c], then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral](d+e x^2)/(a+b x^2+c x^4) \[DifferentialD]x  \[LongRightArrow]  ((q c d+a e)/(2 a))\[Integral](q+x^2)/(a+b x^2+c x^4) \[DifferentialD]x+(q c d-a e)/(2 a) \[Integral](q-x^2)/(a+b x^2+c x^4) \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[(d_.+e_.*x_^2)/(a_+b_.*x_^2+c_.*x_^4), x_Symbol] :=
  Module[{q=Rt[a/c,2]},
  Dist[(q*c*d+a*e)/(2*a),Int[(q+x^2)/(a+b*x^2+c*x^4),x]] +
  Dist[(q*c*d-a*e)/(2*a),Int[(q-x^2)/(a+b*x^2+c*x^4),x]]] /;
FreeQ[{a,b,c,d,e},x] && NonzeroQ[b^2-4*a*c] && NonzeroQ[c*d^2-a*e^2] && PosQ[a/c] &&
(NegativeQ[b^2-4*a*c] || RationalQ[a/c] && Not[PositiveQ[b^2-4*a*c]])


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Derivation: Algebraic expansion*)


(* ::Subsubsection:: *)
(*Basis: Let q=Sqrt[-(a/c)], then (d+e x^2)/(a+b x^2+c x^4)=-(((q c d-a e) (q+x^2))/(2 a(a+b x^2+c x^4)))-((q c d+a e) (q-x^2))/(2 a(a+b x^2+c x^4))*)


(* ::Subsubsection:: *)
(*Note: Resulting integrands are of the form of the first two rules in this section.*)


(* ::Subsubsection:: *)
(*Rule: If  b^2-4 a c!=0 \[And] c d^2-a e^2!=0\[And] \[Not](a/c>0) \[And] (b^2-4 a c<0 \[Or] (a/c\[Element]\[DoubleStruckCapitalQ] \[And] \[Not](b^2-4 a c>0))), let q=Sqrt[-(a/c)], then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral](d+e x^2)/(a+b x^2+c x^4) \[DifferentialD]x  \[LongRightArrow]  -((q c d-a e)/(2 a))\[Integral](q+x^2)/(a+b x^2+c x^4) \[DifferentialD]x-(q c d+a e)/(2 a) \[Integral](q-x^2)/(a+b x^2+c x^4) \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[(d_+e_.*x_^2)/(a_+b_.*x_^2+c_.*x_^4), x_Symbol] :=
  Module[{q=Rt[-a/c,2]},
  Dist[-(q*c*d-a*e)/(2*a),Int[(q+x^2)/(a+b*x^2+c*x^4),x]] -
  Dist[(q*c*d+a*e)/(2*a),Int[(q-x^2)/(a+b*x^2+c*x^4),x]]] /;
FreeQ[{a,b,c,d,e},x] && NonzeroQ[b^2-4*a*c] && NonzeroQ[c*d^2-a*e^2] && NegQ[a/c] &&
(NegativeQ[b^2-4*a*c] || RationalQ[a/c] && Not[PositiveQ[b^2-4*a*c]])


(* ::PageBreak:: *)
(**)


(* ::Subsubsection:: *)
(* *)


(* ::Title::Bold::Closed:: *)
(*\[Integral]1/(a+b x^n+c x^(2n)) \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Reference: G&R 2.161.1b?*)


(* ::Subsubsection:: *)
(*Derivation: Algebraic expansion*)


(* ::Subsubsection:: *)
(*Basis: Let q=Sqrt[a c] and r=Sqrt[2c q-b c], then 1/(a+b z^2+c z^4)=q/(2a  r) (r-c z)/(q-r z+c z^2)+q/(2a  r) (r+c z)/(q+r z+c z^2)*)


(* ::Subsubsection:: *)
(*Rule: If  b^2-4 a c<0 \[And] n/2\[Element]\[DoubleStruckCapitalZ] \[And] n>2 \[And] a c>0, let q=Sqrt[a c], if  2c q-b c>0, let r=Sqrt[2c q-b c], then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]1/(a+b x^n+c x^(2n)) \[DifferentialD]x  \[LongRightArrow]  (q/(2a  r))\[Integral](r-c x^(n/2))/(q-r x^(n/2)+c x^n) \[DifferentialD]x+q/(2a  r) \[Integral](r+c x^(n/2))/(q+r x^(n/2)+c x^n) \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[1/(a_+b_.*x_^n_+c_.*x_^j_),x_Symbol] :=
  Module[{q=Rt[a*c,2]},
  Module[{r=Rt[2*c*q-b*c,2]},
  Dist[q/(2*a*r),Int[(r-c*x^(n/2))/(q-r*x^(n/2)+c*x^n),x]] + 
  Dist[q/(2*a*r),Int[(r+c*x^(n/2))/(q+r*x^(n/2)+c*x^n),x]]] /;
 Not[NegativeQ[2*c*q-b*c]]] /;
FreeQ[{a,b,c},x] && NegativeQ[b^2-4*a*c] && ZeroQ[j-2*n] && IntegerQ[n/2] && n>2 && 
  NegativeQ[b^2-4*a*c] && PosQ[a*c]


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Reference: G&R 2.161.1a*)


(* ::Subsubsection:: *)
(*Derivation: Algebraic expansion*)


(* ::Subsubsection:: *)
(*Basis: Let q=Sqrt[b^2-4 a c], then 1/(a+b z+c z^2)=(2 c)/q 1/(b-q+2 c z)-(2 c)/q 1/(b+q+2 c z)*)


(* ::Subsubsection:: *)
(*Rule: If  b^2-4 a c!=0 \[And] n\[Element]\[DoubleStruckCapitalZ] \[And] n>1 \[And] \[Not](n/2\[Element]\[DoubleStruckCapitalZ] \[And] b^2-4 a c<0 \[And] a c>0), let q=Sqrt[b^2-4 a c], then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]1/(a+b x^n+c x^(2n)) \[DifferentialD]x  \[LongRightArrow]  ((2 c)/q)\[Integral]1/(b-q+2 c x^n) \[DifferentialD]x-(2 c)/q \[Integral]1/(b+q+2 c x^n) \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[1/(a_+b_.*x_^n_+c_.*x_^j_),x_Symbol] :=
  Module[{q=Rt[b^2-4*a*c,2]},
  Dist[2*c/q,Int[1/(b-q+2*c*x^n),x]] -
  Dist[2*c/q,Int[1/(b+q+2*c*x^n),x]]] /;
FreeQ[{a,b,c},x] && NonzeroQ[b^2-4*a*c] && ZeroQ[j-2*n] && IntegerQ[n] && n>1 && 
  Not[IntegerQ[n/2] && NegativeQ[b^2-4*a*c] && PosQ[a*c]]


(* ::PageBreak:: *)
(**)


(* ::Title::Bold::Closed:: *)
(*\[Integral]x^m/(a+b x^n+c x^(2 n)) \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Reference: G&R 2.177.1, CRC 120*)


(* ::Subsubsection:: *)
(*Derivation: Algebraic expansion*)


(* ::Subsubsection:: *)
(*Basis: 1/(x (a+b x^n+c x^(2n)))=1/(a x)-1/a (x^(n-1) (b+c x^n))/(a+b x^n+c x^(2n))*)


(* ::Subsubsection:: *)
(*Note: Although the resulting integrand appears more complicated than the original one, it is easily integrated by the substitution u=x^n.*)


(* ::Subsubsection:: *)
(*Rule: If  b^2-4 a c!=0 \[And] \[Not](n<0), then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]1/(x(a+b x^n+c x^(2n))) \[DifferentialD]x  \[LongRightArrow]  (Log[x]/a)-1/a \[Integral](x^(n-1) (b+c x^n))/(a+b x^n+c x^(2n)) \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[1/(x_*(a_+b_.*x_^n_+c_.*x_^j_)),x_Symbol] :=
  Log[x]/a - Dist[1/a,Int[x^(n-1)*(b+c*x^n)/(a+b*x^n+c*x^(2*n)),x]] /;
FreeQ[{a,b,c,n},x] && NonzeroQ[b^2-4*a*c] && ZeroQ[j-2*n] && Not[NegativeQ[n]]


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Reference: G&R 2.176, CRC 123*)


(* ::Subsubsection:: *)
(*Derivation: Algebraic expansion*)


(* ::Subsubsection:: *)
(*Basis: x^m/(a+b x^n+c x^(2n))=x^m/a-1/a (x^(m+n) (b+c x^n))/(a+b x^n+c x^(2n))*)


(* ::Subsubsection:: *)
(*Rule: If  b^2-4 a c!=0 \[And] m,n\[Element]\[DoubleStruckCapitalZ] \[And] n>0 \[And] m<-1, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]x^m/(a+b x^n+c x^(2n)) \[DifferentialD]x  \[LongRightArrow]  (x^(m+1)/(a (m+1)))-1/a \[Integral](x^(m+n) (b+c x^n))/(a+b x^n+c x^(2n)) \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[x_^m_/(a_+b_.*x_^n_+c_.*x_^j_),x_Symbol] :=
  x^(m+1)/(a*(m+1)) -
  Dist[1/a,Int[x^(m+n)*(b+c*x^n)/(a+b*x^n+c*x^(2*n)),x]] /;
FreeQ[{a,b,c},x] && NonzeroQ[b^2-4*a*c] && ZeroQ[j-2*n] && IntegersQ[m,n] && n>0 && m<-1


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Reference: G&R 2.174.1, CRC 119*)


(* ::Subsubsection:: *)
(*Derivation: Algebraic expansion*)


(* ::Subsubsection:: *)
(*Basis: x^m/(a+b x^n+c x^(2n))=x^(m-2 n)/c-1/c (x^(m-2n) (a+b x^n))/(a+b x^n+c x^(2 n))*)


(* ::Subsubsection:: *)
(*Rule: If  b^2-4 a c!=0 \[And] m,2n\[Element]\[DoubleStruckCapitalZ] \[And] 0<2 n<=m, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]x^m/(a+b x^n+c x^(2n)) \[DifferentialD]x  \[LongRightArrow]  (x^(m-2n+1)/(c (m-2n+1)))-1/c \[Integral](x^(m-2n) (a+b x^n))/(a+b x^n+c x^(2 n)) \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[x_^m_./(a_+b_.*x_^n_+c_.*x_^j_),x_Symbol] :=
  x^(m-2*n+1)/(c*(m-2*n+1)) -
  Dist[1/c,Int[x^(m-2*n)*(a+b*x^n)/(a+b*x^n+c*x^(2*n)),x]] /;
FreeQ[{a,b,c},x] && NonzeroQ[b^2-4*a*c] && ZeroQ[j-2*n] && IntegersQ[m,n] && 0<2*n<=m


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Derivation: Algebraic expansion*)


(* ::Subsubsection:: *)
(*Basis: Let q=Sqrt[a c] and r=Sqrt[2c q-b c], then z^m/(a+b z^2+c z^4)=c/(2r) z^(m-1)/(q-r z+c z^2)-c/(2r) z^(m-1)/(q+r z+c z^2)*)


(* ::Subsubsection:: *)
(*Rule: If  b^2-4 a c<0 \[And] m,n/2\[Element]\[DoubleStruckCapitalZ] \[And] 1<n/2<=m<2n \[And] CoprimeQ[m+1,n] \[And] a c>0, let q=Sqrt[a c], if  2c q-b c>0, let r=Sqrt[2c q-b c], then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]x^m/(a+b x^n+c x^(2n)) \[DifferentialD]x  \[LongRightArrow]  (c/(2r))\[Integral]x^(m-n/2)/(q-r x^(n/2)+c x^n) \[DifferentialD]x-c/(2r) \[Integral]x^(m-n/2)/(q+r x^(n/2)+c x^n) \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[x_^m_./(a_+b_.*x_^n_+c_.*x_^j_),x_Symbol] :=
  Module[{q=Rt[a*c,2]},
  Module[{r=Rt[2*c*q-b*c,2]},
  Dist[c/(2*r),Int[x^(m-n/2)/(q-r*x^(n/2)+c*x^n),x]] - 
  Dist[c/(2*r),Int[x^(m-n/2)/(q+r*x^(n/2)+c*x^n),x]]] /;
 Not[NegativeQ[2*c*q-b*c]]] /;
FreeQ[{a,b,c},x] && NegativeQ[b^2-4*a*c] && ZeroQ[j-2*n] && IntegersQ[m,n/2] && 
  1<n/2<=m<2*n && CoprimeQ[m+1,n] && PosQ[a*c]


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Reference: G&R 2.161.1a*)


(* ::Subsubsection:: *)
(*Derivation: Algebraic expansion*)


(* ::Subsubsection:: *)
(*Basis: Let q=Sqrt[b^2-4 a c], then z^m/(a+b z+c z^2)=(2 c)/q z^m/(b-q+2 c z)-(2 c)/q z^m/(b+q+2 c z)*)


(* ::Subsubsection:: *)
(*Rule: If  b^2-4 a c!=0 \[And] m,n\[Element]\[DoubleStruckCapitalZ] \[And] 0<m<n \[And] CoprimeQ[m+1,n] \[And] \[Not](n/2\[Element]\[DoubleStruckCapitalZ] \[And] b^2-4 a c<0 \[And] a c>0), let q=Sqrt[b^2-4 a c], then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]x^m/(a+b x^n+c x^(2n)) \[DifferentialD]x  \[LongRightArrow]  ((2 c)/q)\[Integral]x^m/(b-q+2 c x^n) \[DifferentialD]x-(2 c)/q \[Integral]x^m/(b+q+2 c x^n) \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[x_^m_./(a_+b_.*x_^n_+c_.*x_^j_),x_Symbol] :=
  Module[{q=Rt[b^2-4*a*c,2]},
  Dist[2*c/q,Int[x^m/(b-q+2*c*x^n),x]] -
  Dist[2*c/q,Int[x^m/(b+q+2*c*x^n),x]]] /;
FreeQ[{a,b,c},x] && NonzeroQ[b^2-4*a*c] && ZeroQ[j-2*n] && IntegersQ[m,n] && 0<m<n && 
  CoprimeQ[m+1,n] && Not[IntegerQ[n/2] && NegativeQ[b^2-4*a*c] && PosQ[a*c]]


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Derivation: Algebraic expansion*)


(* ::Subsubsection:: *)
(*Basis: Let q=Sqrt[b^2-4 a c], then z^m/(a+b z+c z^2)=(1-b/q) z^(m-1)/(b-q+2 c z)+(1+b/q) z^(m-1)/(b+q+2 c z)*)


(* ::Subsubsection:: *)
(*Rule: If  b^2-4 a c!=0 \[And] m,n\[Element]\[DoubleStruckCapitalZ] \[And] n<m<2n \[And] CoprimeQ[m+1,n] \[And] \[Not](n/2\[Element]\[DoubleStruckCapitalZ] \[And] b^2-4 a c<0 \[And] a c>0), let q=Sqrt[b^2-4 a c], then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]x^m/(a+b x^n+c x^(2 n)) \[DifferentialD]x  \[LongRightArrow]  (1-b/q)\[Integral]x^(m-n)/(b-q+2 c x^n) \[DifferentialD]x+(1+b/q)\[Integral]x^(m-n)/(b+q+2 c x^n) \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[x_^m_/(a_+b_.*x_^n_+c_.*x_^j_),x_Symbol] :=
  Module[{q=Rt[b^2-4*a*c,2]},
  Dist[1-b/q,Int[x^(m-n)/(b-q+2*c*x^n),x]] +
  Dist[1+b/q,Int[x^(m-n)/(b+q+2*c*x^n),x]]] /;
FreeQ[{a,b,c},x] && NonzeroQ[b^2-4*a*c] && ZeroQ[j-2*n] && IntegersQ[m,n] && n<m<2*n && 
  CoprimeQ[m+1,n] && Not[IntegerQ[n/2] && NegativeQ[b^2-4*a*c] && PosQ[a*c]]


(* ::PageBreak:: *)
(**)


(* ::Title::Bold::Closed:: *)
(*\[Integral](d+e x^n)/(a+b x^n+c x^(2 n)) \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Derivation: Algebraic expansion*)


(* ::Subsubsection:: *)
(*Basis: Let q=Sqrt[a c] and r=Sqrt[2c q-b c], then (d+e z^2)/(a+b z^2+c z^4)=c/(2 q r) (d r-(c d-e q) z)/(q-r z+c z^2)+c/(2 q r) (d r+(c d-e q) z)/(q+r z+c z^2)*)


(* ::Subsubsection:: *)
(*Rule: If  b^2-4 a c<0 \[And] n/2\[Element]\[DoubleStruckCapitalZ] \[And] n>2 \[And] a c>0, let q=Sqrt[a c], if  2c q-b c>0, let r=Sqrt[2c q-b c], then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral](d+e x^n)/(a+b x^n+c x^(2n)) \[DifferentialD]x  \[LongRightArrow]  (c/(2 q r))\[Integral](d r-(c d-e q) x^(n/2))/(q-r x^(n/2)+c x^n) \[DifferentialD]x+c/(2 q r) \[Integral](d r+(c d-e q) x^(n/2))/(q+r x^(n/2)+c x^n) \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[(d_.+e_.*x_^n_)/(a_+b_.*x_^n_+c_.*x_^j_),x_Symbol] :=
  Module[{q=Rt[a*c,2]},
  Module[{r=Rt[2*c*q-b*c,2]},
  Dist[c/(2*q*r),Int[(d*r-(c*d-e*q)*x^(n/2))/(q-r*x^(n/2)+c*x^n),x]] + 
  Dist[c/(2*q*r),Int[(d*r+(c*d-e*q)*x^(n/2))/(q+r*x^(n/2)+c*x^n),x]]] /;
 Not[NegativeQ[2*c*q-b*c]]] /;
FreeQ[{a,b,c,d,e},x] && NegativeQ[b^2-4*a*c] && ZeroQ[j-2*n] && IntegerQ[n/2] && n>2 && PosQ[a*c]


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Reference: G&R 2.161.1a & G&R 2.161.3*)


(* ::Subsubsection:: *)
(*Derivation: Algebraic expansion*)


(* ::Subsubsection:: *)
(*Basis: Let q=Sqrt[b^2-4 a c], then (d+e z)/(a+b z+c z^2)=(e+(2 c d-b e)/q) 1/(b-q+2 c z)+(e-(2 c d-b e)/q) 1/(b+q+2 c z)*)


(* ::Subsubsection:: *)
(*Rule: If  b^2-4 a c!=0 \[And] n\[Element]\[DoubleStruckCapitalZ] \[And] n>1 \[And] \[Not](n/2\[Element]\[DoubleStruckCapitalZ] \[And] b^2-4 a c<0 \[And] a c>0), let q=Sqrt[b^2-4 a c], then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral](d+e x^n)/(a+b x^n+c x^(2 n)) \[DifferentialD]x  \[LongRightArrow]  (e+(2 c d-b e)/q)\[Integral]1/(b-q+2 c x^n) \[DifferentialD]x+(e-(2 c d-b e)/q)\[Integral]1/(b+q+2 c x^n) \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[(d_.+e_.*x_^n_)/(a_+b_.*x_^n_+c_.*x_^j_),x_Symbol] :=
  Module[{q=Rt[b^2-4*a*c,2]},
  Dist[(e+(2*c*d-b*e)/q),Int[1/(b-q+2*c*x^n),x]] +
  Dist[(e-(2*c*d-b*e)/q),Int[1/(b+q+2*c*x^n),x]]] /;
FreeQ[{a,b,c,d,e},x] && NonzeroQ[b^2-4*a*c] && ZeroQ[j-2*n] && IntegerQ[n] && n>1 && 
  Not[IntegerQ[n/2] && NegativeQ[b^2-4*a*c] && PosQ[a*c]]


(* ::PageBreak:: *)
(**)


(* ::Title::Bold::Closed:: *)
(*\[Integral](x^m (d+e x^n))/(a+b x^n+c x^(2 n)) \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Derivation: Algebraic expansion*)


(* ::Subsubsection:: *)
(*Basis: (d+e x^n)/(x (a+b x^n+c x^(2n)))=d/(a x)-1/a (x^(n-1) (b d-a e+c d x^n))/(a+b x^n+c x^(2n))*)


(* ::Subsubsection:: *)
(*Note: Although resulting integrand appears more complicated than the original one, it is easily integrated by the substitution u=x^n.*)


(* ::Subsubsection:: *)
(*Rule: If  b^2-4 a c!=0, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral](d+e x^n)/(x(a+b x^n+c x^(2 n))) \[DifferentialD]x  \[LongRightArrow]  ((d Log[x])/a)-1/a \[Integral](x^(n-1) (b d-a e+c d x^n))/(a+b x^n+c x^(2n)) \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[(d_+e_.*x_^n_)/(x_*(a_+b_.*x_^n_+c_.*x_^j_)),x_Symbol] :=
  d*Log[x]/a - Dist[1/a,Int[x^(n-1)*(b*d-a*e+c*d*x^n)/(a+b*x^n+c*x^(2*n)),x]] /;
FreeQ[{a,b,c,d,e,n},x] && NonzeroQ[b^2-4*a*c] && ZeroQ[j-2*n]


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Derivation: Algebraic expansion*)


(* ::Subsubsection:: *)
(*Basis: (x^m (d+e x^n))/(a+b x^n+c x^(2n))=(d x^m)/a-1/a (x^(m+n) (b d-a e+c d x^n))/(a+b x^n+c x^(2n))*)


(* ::Subsubsection:: *)
(*Note: Resulting integrand has the same form as the original one so recursion can occur. *)


(* ::Subsubsection:: *)
(*Rule: If  b^2-4 a c!=0 \[And] m,n\[Element]\[DoubleStruckCapitalZ] \[And] n>0 \[And] m<-1, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral](x^m (d+e x^n))/(a+b x^n+c x^(2 n)) \[DifferentialD]x  \[LongRightArrow]  ((d x^(m+1))/(a (m+1)))-1/a \[Integral](x^(m+n) (b d-a e+c d x^n))/(a+b x^n+c x^(2n)) \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[x_^m_*(d_+e_.*x_^n_)/(a_+b_.*x_^n_+c_.*x_^j_),x_Symbol] :=
  d*x^(m+1)/(a*(m+1)) -
  Dist[1/a,Int[x^(m+n)*(b*d-a*e+c*d*x^n)/(a+b*x^n+c*x^(2*n)),x]] /;
FreeQ[{a,b,c,d,e},x] && NonzeroQ[b^2-4*a*c] && ZeroQ[j-2*n] && IntegersQ[m,n] && n>0 && m<-1


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Derivation: Algebraic expansion*)


(* ::Subsubsection:: *)
(*Basis: (x^m (d+e x^n))/(a+b x^n+c x^(2n))=(e x^(m-n))/c-1/c (x^(m-n) (a e+(b e-c d) x^n))/(a+b x^n+c x^(2n))*)


(* ::Subsubsection:: *)
(*Note: Resulting integrand has the same form as the original one so recursion can occur. *)


(* ::Subsubsection:: *)
(*Rule: If  b^2-4 a c!=0 \[And] m,n\[Element]\[DoubleStruckCapitalZ] \[And] 0<n<=m, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral](x^m (d+e x^n))/(a+b x^n+c x^(2 n)) \[DifferentialD]x  \[LongRightArrow]  ((e x^(m-n+1))/(c (m-n+1)))-1/c \[Integral](x^(m-n) (a e+(b e-c d) x^n))/(a+b x^n+c x^(2n)) \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[x_^m_.*(d_+e_.*x_^n_)/(a_+b_.*x_^n_+c_.*x_^j_),x_Symbol] :=
  e*x^(m-n+1)/(c*(m-n+1)) -
  Dist[1/c,Int[x^(m-n)*(a*e+(b*e-c*d)*x^n)/(a+b*x^n+c*x^(2*n)),x]] /;
FreeQ[{a,b,c,d,e},x] && NonzeroQ[b^2-4*a*c] && ZeroQ[j-2*n] && IntegersQ[m,n] && 0<n<=m


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Derivation: Algebraic expansion*)


(* ::Subsubsection:: *)
(*Basis: Let q=Sqrt[a c] and r=Sqrt[2c q-b c], then (d+e z^2)/(a+b z^2+c z^4)=c/(2 q r) (d r-(c d-e q) z)/(q-r z+c z^2)+c/(2 q r) (d r+(c d-e q) z)/(q+r z+c z^2)*)


(* ::Subsubsection:: *)
(*Rule: If  b^2-4 a c<0 \[And] m,n/2\[Element]\[DoubleStruckCapitalZ] \[And] 0<m<n \[And] CoprimeQ[m+1,n] \[And] a c>0, let q=Sqrt[a c], if  2c q-b c>0, let r=Sqrt[2c q-b c], then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral](x^m (d+e x^n))/(a+b x^n+c x^(2n)) \[DifferentialD]x  \[LongRightArrow]  (c/(2 q r))\[Integral](x^m (d r-(c d-e q) x^(n/2)))/(q-r x^(n/2)+c x^n) \[DifferentialD]x+c/(2 q r) \[Integral](x^m (d r+(c d-e q) x^(n/2)))/(q+r x^(n/2)+c x^n) \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[x_^m_*(d_+e_.*x_^n_)/(a_+b_.*x_^n_+c_.*x_^j_),x_Symbol] :=
  Module[{q=Rt[a*c,2]},
  Module[{r=Rt[2*c*q-b*c,2]},
  Dist[c/(2*q*r),Int[x^m*(d*r-(c*d-e*q)*x^(n/2))/(q-r*x^(n/2)+c*x^n),x]] + 
  Dist[c/(2*q*r),Int[x^m*(d*r+(c*d-e*q)*x^(n/2))/(q+r*x^(n/2)+c*x^n),x]]] /;
 Not[NegativeQ[2*c*q-b*c]]] /;
FreeQ[{a,b,c,d,e},x] && NegativeQ[b^2-4*a*c] && ZeroQ[j-2*n] && IntegersQ[m,n/2] && 
  0<m<n && CoprimeQ[m+1,n] && PosQ[a*c]


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Derivation: Algebraic expansion*)


(* ::Subsubsection:: *)
(*Basis: Let q=Sqrt[b^2-4 a c], then (z^m (d+e z))/(a+b z+c z^2)=(e+(2 c d-b e)/q) z^m/(b-q+2 c z)+(e-(2 c d-b e)/q) z^m/(b+q+2 c z)*)


(* ::Subsubsection:: *)
(*Rule: If  b^2-4 a c!=0 \[And] m,n\[Element]\[DoubleStruckCapitalZ] \[And] 0<m<n \[And] CoprimeQ[m+1,n] \[And] \[Not](n/2\[Element]\[DoubleStruckCapitalZ] \[And] b^2-4 a c<0 \[And] a c>0), let q=Sqrt[b^2-4 a c], then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral](x^m (d+e x^n))/(a+b x^n+c x^(2 n)) \[DifferentialD]x  \[LongRightArrow]  (e+(2 c d-b e)/q)\[Integral]x^m/(b-q+2 c x^n) \[DifferentialD]x+(e-(2 c d-b e)/q)\[Integral]x^m/(b+q+2 c x^n) \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[x_^m_.*(d_+e_.*x_^n_)/(a_+b_.*x_^n_+c_.*x_^j_),x_Symbol] :=
  Module[{q=Rt[b^2-4*a*c,2]},
  Dist[(e+(2*c*d-b*e)/q),Int[x^m/(b-q+2*c*x^n),x]] +
  Dist[(e-(2*c*d-b*e)/q),Int[x^m/(b+q+2*c*x^n),x]]] /;
FreeQ[{a,b,c,d,e},x] && NonzeroQ[b^2-4*a*c] && ZeroQ[j-2*n] && IntegersQ[m,n] && 
  0<m<n && CoprimeQ[m+1,n] && Not[IntegerQ[n/2] && NegativeQ[b^2-4*a*c] && PosQ[a*c]]


(* ::PageBreak:: *)
(**)


(* ::Subsubsection:: *)
(* *)


(* ::Title::Bold::Closed:: *)
(*\[Integral](a+b x^n+c x^(2 n))^p \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Derivation: Algebraic simplification*)


(* ::Subsubsection:: *)
(*Basis: If  b^2-4 a c=0, then  a+b z^n+c z^(2n)=1/c (b/2+c z^n)^2*)


(* ::Subsubsection:: *)
(*Rule: If  n,p\[Element]\[DoubleStruckCapitalZ] \[And] n>1 \[And] p<0 \[And] b^2-4 a c=0, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral](a+b x^n+c x^(2 n))^p \[DifferentialD]x  \[LongRightArrow]  (1/c^p)\[Integral](b/2+c x^n)^(2p) \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[(a_+b_.*x_^n_+c_.*x_^j_)^p_,x_Symbol] :=
  Dist[1/c^p,Int[(b/2+c*x^n)^(2*p),x]] /;
FreeQ[{a,b,c},x] && ZeroQ[j-2*n] && IntegersQ[n,p] && n>1 && p<0 && ZeroQ[b^2-4*a*c]


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Reference: G&R 2.161.5*)


(* ::Subsubsection:: *)
(*Note: G&R 2.161.4 is a special case of G&R 2.161.5.*)


(* ::Subsubsection:: *)
(*Note: Previously undiscovered rule?*)


(* ::Subsubsection:: *)
(*Rule: If  n\[Element]\[DoubleStruckCapitalZ] \[And] n>1 \[And] p<-1 \[And] b^2-4a c!=0, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral](a+b x^n+c x^(2 n))^p \[DifferentialD]x  \[LongRightArrow]  -((x (b^2-2 a c+b c x^n)(a+b x^n+c x^(2 n))^(p+1))/(a n (p+1) (b^2-4 a c)))+                                                             *)
(*   1/(a n(p+1) (b^2-4 a c)) \[Integral](b^2-2 a c+n(p+1) (b^2-4 a c)+b c(n (2 p+3)+1)x^n) (a+b x^n+c x^(2 n))^(p+1) \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[(a_+b_.*x_^n_+c_.*x_^j_)^p_,x_Symbol] :=
  -x*(b^2-2*a*c+b*c*x^n)*(a+b*x^n+c*x^j)^(p+1)/(a*n*(p+1)*(b^2-4*a*c)) +
  Dist[1/(a*n*(p+1)*(b^2-4*a*c)),
    Int[(b^2-2*a*c+n*(p+1)*(b^2-4*a*c)+b*c*(n*(2*p+3)+1)*x^n)*(a+b*x^n+c*x^(2*n))^(p+1),x]] /;
FreeQ[{a,b,c},x] && ZeroQ[j-2*n] && IntegerQ[n] && n>1 && RationalQ[p] && p<-1 && 
NonzeroQ[b^2-4*a*c]


(* ::PageBreak:: *)
(**)


(* ::Title::Bold::Closed:: *)
(*\[Integral]x^m (a+b x^n+c x^(2 n))^p \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Derivation: Algebraic simplification*)


(* ::Subsubsection:: *)
(*Basis: If  b^2-4 a c=0, then a+b z^n+c z^(2n)=1/c (b/2+c z^n)^2*)


(* ::Subsubsection:: *)
(*Rule: If  n,p\[Element]\[DoubleStruckCapitalZ] \[And] n>1 \[And] p<0 \[And] b^2-4 a c=0, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]x^m (a+b x^n+c x^(2 n))^p \[DifferentialD]x  \[LongRightArrow]  (1/c^p)\[Integral]x^m (b/2+c x^n)^(2p) \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[x_^m_.*(a_+b_.*x_^n_+c_.*x_^j_)^p_,x_Symbol] :=
  Dist[1/c^p,Int[x^m*(b/2+c*x^n)^(2*p),x]] /;
FreeQ[{a,b,c},x] && ZeroQ[j-2*n] && IntegersQ[m,n,p] && n>1 && p<0 && ZeroQ[b^2-4*a*c]


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Derivation: Trinomial recurrence 2 with d=0 and e=1*)


(* ::Subsubsection:: *)
(*Rule: If  b^2-4 a c!=0 \[And] m,n\[Element]\[DoubleStruckCapitalZ] \[And] 0<n<=m, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]x^m (a+b x^n+c x^(2 n))^p \[DifferentialD]x  \[LongRightArrow]  ((x^(m-2n+1) (a+b x^n+c x^(2 n))^(p+1))/(c (2 n p+m+1)))-*)
(*1/(c (2 n p+m+1)) \[Integral]x^(m-2n) (a(m-2n+1)+(b(n p-n+m+1)) x^n) (a+b x^n+c x^(2 n))^p \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[x_^m_.*(a_+b_.*x_^n_.+c_.*x_^j_)^p_.,x_Symbol] :=
  x^(m-2*n+1)*(a+b*x^n+c*x^(2*n))^(p+1)/(c*(2*n*p+m+1)) - 
  Dist[1/(c*(2*n*p+m+1)),
    Int[x^(m-2*n)*Sim[a*(m-2*n+1)+(b*(n*p-n+m+1))*x^n,x]*(a+b*x^n+c*x^(2*n))^p,x]] /;
FreeQ[{a,b,c,p},x] && NonzeroQ[b^2-4*a*c] && ZeroQ[j-2*n] && IntegersQ[m,n] && 0<n<=m


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Reference: G&R 2.160.1 special case*)


(* ::Subsubsection:: *)
(*Rule: If  m,n\[Element]\[DoubleStruckCapitalZ] \[And] m<-1 \[And] n>0 \[And] m+n(p+1)+1=0 \[And] \[Not](p\[Element]\[DoubleStruckCapitalZ] \[And] p>0), then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]x^m (a+b x^n+c x^(2 n))^p \[DifferentialD]x  \[LongRightArrow]  ((x^(m+1) (a+b x^n+c x^(2n))^(p+1))/(a (m+1)))+c/a \[Integral]x^(m+2 n) (a+b x^n+c x^(2n))^p \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[x_^m_*(a_+b_.*x_^n_.+c_.*x_^j_.)^p_,x_Symbol] :=
  x^(m+1)*(a+b*x^n+c*x^j)^(p+1)/(a*(m+1)) +
  Dist[c/a,Int[x^(m+2*n)*(a+b*x^n+c*x^j)^p,x]] /;
FreeQ[{a,b,c,p},x] && ZeroQ[j-2*n] && IntegersQ[m,n] && m<-1 && n>0 && ZeroQ[m+n*(p+1)+1] &&
Not[IntegerQ[p] && p>0]


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Reference: G&R 2.160.1 special case*)


(* ::Subsubsection:: *)
(*Rule: If  m,n\[Element]\[DoubleStruckCapitalZ] \[And] m<-1 \[And] n>0 \[And] m+2n(p+1)+1=0 \[And] \[Not](p\[Element]\[DoubleStruckCapitalZ] \[And] p>0), then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]x^m (a+b x^n+c x^(2 n))^p \[DifferentialD]x  \[LongRightArrow]  ((x^(m+1) (a+b x^n+c x^(2n))^(p+1))/(a (m+1)))-b/(2 a) \[Integral]x^(m+n) (a+b x^n+c x^(2n))^p \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[x_^m_*(a_+b_.*x_^n_.+c_.*x_^j_.)^p_,x_Symbol] :=
  x^(m+1)*(a+b*x^n+c*x^j)^(p+1)/(a*(m+1)) -
  Dist[b/(2*a),Int[x^(m+n)*(a+b*x^n+c*x^j)^p,x]] /;
FreeQ[{a,b,c,p},x] && ZeroQ[j-2*n] && IntegersQ[m,n] && m<-1 && n>0 && ZeroQ[m+2*n*(p+1)+1] &&
Not[IntegerQ[p] && p>0]


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Derivation: Integration by substitution*)


(* ::Subsubsection:: *)
(*Basis: If n/(m+1)\[Element]\[DoubleStruckCapitalZ], then x^m f[x^n]=1/(m+1) f[(x^(m+1))^(n/(m+1))]\!\( *)
(*\*SubscriptBox[\(\[PartialD]\), \(x\)]*)
(*\*SuperscriptBox[\(x\), \(m + 1\)]\)*)


(* ::Subsubsection:: *)
(*Rule: If  b^2-4 a c!=0 \[And] m+1!=0 \[And] p,n/(m+1)\[Element]\[DoubleStruckCapitalZ] \[And] \[Not](m+1<0) \[And] p<0, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]x^m (a+b x^n+c x^(2 n))^p \[DifferentialD]x  \[LongRightArrow]  (1/(m+1))Subst[\[Integral](a+b x^(n/(m+1))+c x^((2n)/(m+1)))^p \[DifferentialD]x,x,x^(m+1)]*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[x_^m_.*(a_+b_.*x_^n_+c_.*x_^j_)^p_,x_Symbol] :=
  Dist[1/(m+1),Subst[Int[(a+b*x^(n/(m+1))+c*x^(2*n/(m+1)))^p,x],x,x^(m+1)]] /;
FreeQ[{a,b,c,m,n},x] && NonzeroQ[b^2-4*a*c] && ZeroQ[j-2*n] && NonzeroQ[m+1] && 
  IntegersQ[p,n/(m+1)] && Not[NegativeQ[m+1]] && p<0


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Derivation: Integration by substitution*)


(* ::Subsubsection:: *)
(*Basis: If (m+1)/n\[Element]\[DoubleStruckCapitalZ], then x^m f[x^n]=1/n (x^n)^((m+1)/n-1) f[x^n]\!\( *)
(*\*SubscriptBox[\(\[PartialD]\), \(x\)]*)
(*\*SuperscriptBox[\(x\), \(n\)]\)*)


(* ::Subsubsection:: *)
(*Note: Requirement that (m+1)/n>0 ensures Log[x] rather than Log[x^n]/n occurs in the antiderivative.*)


(* ::Subsubsection:: *)
(*Rule: If  b^2-4 a c!=0 \[And] p,(m+1)/n\[Element]\[DoubleStruckCapitalZ] \[And] n!=1 \[And] \[Not](n<0) \[And] p<0 \[And] ((m+1)/n>0 \[Or] m\[NotElement]\[DoubleStruckCapitalZ]), then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]x^m (a+b x^n+c x^(2 n))^p \[DifferentialD]x  \[LongRightArrow]  (1/n)Subst[\[Integral]x^((m+1)/n-1) (a+b x+c x^2)^p \[DifferentialD]x,x,x^n]*)


(* ::Code:: *)
Int[x_^m_.*(a_+b_.*x_^n_+c_.*x_^j_)^p_,x_Symbol] :=
  Dist[1/n,Subst[Int[x^((m+1)/n-1)*(a+b*x+c*x^2)^p,x],x,x^n]] /;
FreeQ[{a,b,c,m,n},x] && NonzeroQ[b^2-4*a*c] && ZeroQ[j-2*n] && IntegersQ[p,(m+1)/n] && 
  Not[NegativeQ[n]] && p<0 && ((m+1)/n>0 || Not[IntegerQ[m]])


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Derivation: Integration by substitution*)


(* ::Subsubsection:: *)
(*Rule: If  b^2-4 a c!=0 \[And] m+1!=0 \[And] n!=1 \[And] m,n,p\[Element]\[DoubleStruckCapitalZ] \[And] \[Not]CoprimeQ[m+1,n] \[And] p<0 \[And] (m+1)/n>0, let g=GCD[m+1,n], then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]x^m (a+b x^n+c x^(2 n))^p \[DifferentialD]x  \[LongRightArrow]  (1/g)Subst[\[Integral]x^((m+1)/g-1) (a+b x^(n/g)+c x^((2n)/g))^p \[DifferentialD]x,x,x^g]*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[x_^m_.*(a_+b_.*x_^n_+c_.*x_^j_)^p_,x_Symbol] :=
  Module[{g=GCD[m+1,n]},
  Dist[1/g,Subst[Int[x^((m+1)/g-1)*(a+b*x^(n/g)+c*x^(2*n/g))^p,x],x,x^g]]] /; 
FreeQ[{a,b,c,m,n},x] && NonzeroQ[b^2-4*a*c] && ZeroQ[j-2*n] && NonzeroQ[m+1] && 
  IntegersQ[m,n,p] && Not[CoprimeQ[m+1,n]] && p<0 && (m+1)/n>0


(* ::PageBreak:: *)
(**)


(* ::Title::Bold::Closed:: *)
(*\[Integral](d+e x^n) (a+b x^n+c x^(2 n))^p \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Derivation: Algebraic simplification*)


(* ::Subsubsection:: *)
(*Basis: If  b^2-4 a c=0, then a+b z^n+c z^(2n)=1/c (b/2+c z^n)^2*)


(* ::Subsubsection:: *)
(*Rule: If  n,p\[Element]\[DoubleStruckCapitalZ] \[And] n>1 \[And] p<0 \[And] b^2-4 a c=0, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral](d+e x^n)(a+b x^n+c x^(2 n))^p \[DifferentialD]x  \[LongRightArrow]  (1/c^p)\[Integral](d+e x^n)(b/2+c x^n)^(2p) \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[(d_.+e_.*x_^n_)*(a_+b_.*x_^n_+c_.*x_^j_)^p_,x_Symbol] :=
  Dist[1/c^p,Int[(d+e*x^n)*(b/2+c*x^n)^(2*p),x]] /;
FreeQ[{a,b,c,d,e},x] && ZeroQ[j-2*n] && IntegersQ[n,p] && n>1 && p<0 && ZeroQ[b^2-4*a*c]


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Note: Previously undiscovered rule?*)


(* ::Subsubsection:: *)
(*Note: Since the resulting integrand has the same form as the original one, recursion can occur. *)


(* ::Subsubsection:: *)
(*Rule: If  n\[Element]\[DoubleStruckCapitalZ] \[And] n>1 \[And] p<-1 \[And] b^2-4a c!=0, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral](d+e x^n) (a+b x^n+c x^(2 n))^p \[DifferentialD]x  \[LongRightArrow]  *)
(*((x (a b e-b^2 d+2 a c d+c (2 a e-b d) x^n))/(a n (p+1) (b^2-4 a c))) (a+b x^n+c x^(2 n))^(p+1)-1/(a n(p+1) (b^2-4 a c))\[CenterDot]*)
(*\[Integral](a b e-b^2 d+2 a c d-d n(p+1) (b^2-4 a c)+c (2 a e-b d) (n (2 p+3)+1)x^n) (a+b x^n+c x^(2 n))^(p+1) \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[(d_.+e_.*x_^n_)*(a_+b_.*x_^n_+c_.*x_^j_)^p_,x_Symbol] :=
  x*(a*b*e-b^2*d+2*a*c*d+c*(2*a*e-b*d)*x^n)*(a+b*x^n+c*x^(2*n))^(p+1)/(a*n*(p+1)*(b^2-4*a*c)) -
  Dist[1/(a*n*(p+1)*(b^2-4*a*c)),
    Int[(a*b*e-b^2*d+2*a*c*d-d*n*(p+1)*(b^2-4*a*c)+c*(2*a*e-b*d)*(n*(2*p+3)+1)*x^n)*
      (a+b*x^n+c*x^(2*n))^(p+1),x]] /;
FreeQ[{a,b,c,d,e},x] && ZeroQ[j-2*n] && IntegerQ[n] && n>1 && RationalQ[p] && p<-1 && 
NonzeroQ[b^2-4*a*c]


(* ::PageBreak:: *)
(**)


(* ::Title::Bold::Closed:: *)
(*\[Integral]x^m (d+e x^n)(a+b x^n+c x^(2 n))^p \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Derivation: Trinomial recurrence 2*)


(* ::Subsubsection:: *)
(*Rule: If  b^2-4 a c!=0 \[And] m,n\[Element]\[DoubleStruckCapitalZ] \[And] 0<n<=m, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]x^m (d+e x^n)(a+b x^n+c x^(2 n))^p \[DifferentialD]x  \[LongRightArrow]  ((e x^(m-n+1) (a+b x^n+c x^(2 n))^(p+1))/(c (2 n p+n+m+1)))-*)
(*1/(c (2 n p+n+m+1)) \[Integral]x^(m-n) (a e (m-n+1)+(b e (n p+m+1)-c d (2 n p+n+m+1)) x^n) (a+b x^n+c x^(2 n))^p \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[x_^m_.*(d_+e_.*x_^n_.)*(a_+b_.*x_^n_.+c_.*x_^j_)^p_.,x_Symbol] :=
  e*x^(m-n+1)*(a+b*x^n+c*x^(2*n))^(p+1)/(c*(2*n*p+n+m+1)) - 
  Dist[1/(c*(2*n*p+n+m+1)),
    Int[x^(m-n)*Sim[a*e*(m-n+1)+(b*e*(n*p+m+1)-c*d*(2*n*p+n+m+1))*x^n,x]*(a+b*x^n+c*x^(2*n))^p,x]] /;
FreeQ[{a,b,c,d,e,p},x] && NonzeroQ[b^2-4*a*c] && ZeroQ[j-2*n] && IntegersQ[m,n] && 0<n<=m


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Derivation: Integration by substitution*)


(* ::Subsubsection:: *)
(*Basis: If n/(m+1)\[Element]\[DoubleStruckCapitalZ], then x^m f[x^n]=1/(m+1) f[(x^(m+1))^(n/(m+1))]\!\( *)
(*\*SubscriptBox[\(\[PartialD]\), \(x\)]*)
(*\*SuperscriptBox[\(x\), \(m + 1\)]\)*)


(* ::Subsubsection:: *)
(*Rule: If  b^2-4 a c!=0 \[And] m+1!=0 \[And] p,n/(m+1)\[Element]\[DoubleStruckCapitalZ] \[And] \[Not](m+1<0) \[And] p<0, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]x^m (d+e x^n)(a+b x^n+c x^(2 n))^p \[DifferentialD]x  \[LongRightArrow]  (1/(m+1))Subst[\[Integral](d+e x^(n/(m+1)))(a+b x^(n/(m+1))+c x^((2n)/(m+1)))^p \[DifferentialD]x,x,x^(m+1)]*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[x_^m_.*(d_+e_.*x_^n_)*(a_+b_.*x_^n_+c_.*x_^j_)^p_,x_Symbol] :=
  Dist[1/(m+1),Subst[Int[(d+e*x^(n/(m+1)))*(a+b*x^(n/(m+1))+c*x^(2*n/(m+1)))^p,x],x,x^(m+1)]] /;
FreeQ[{a,b,c,d,e,m,n},x] && NonzeroQ[b^2-4*a*c] && ZeroQ[j-2*n] && NonzeroQ[m+1] && 
  IntegersQ[p,n/(m+1)] && Not[NegativeQ[m+1]] && p<0


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Derivation: Integration by substitution*)


(* ::Subsubsection:: *)
(*Basis: If (m+1)/n\[Element]\[DoubleStruckCapitalZ], then x^m f[x^n]=1/n (x^n)^((m+1)/n-1) f[x^n]\!\( *)
(*\*SubscriptBox[\(\[PartialD]\), \(x\)]*)
(*\*SuperscriptBox[\(x\), \(n\)]\)*)


(* ::Subsubsection:: *)
(*Note: Requirement that (m+1)/n>0 ensures Log[x] rather than Log[x^n]/n occurs in the antiderivative.*)


(* ::Subsubsection:: *)
(*Rule: If  b^2-4 a c!=0 \[And] p,(m+1)/n\[Element]\[DoubleStruckCapitalZ] \[And] n!=1 \[And] \[Not](n<0) \[And] p<0 \[And] ((m+1)/n>0 \[Or] m\[NotElement]\[DoubleStruckCapitalZ]), then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]x^m (d+e x^n)(a+b x^n+c x^(2 n))^p \[DifferentialD]x  \[LongRightArrow]  (1/n)Subst[\[Integral]x^((m+1)/n-1) (d+e x)(a+b x+c x^2)^p \[DifferentialD]x,x,x^n]*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[x_^m_.*(d_+e_.*x_^n_)*(a_+b_.*x_^n_+c_.*x_^j_)^p_,x_Symbol] :=
  Dist[1/n,Subst[Int[x^((m+1)/n-1)*(d+e*x)*(a+b*x+c*x^2)^p,x],x,x^n]] /;
FreeQ[{a,b,c,d,e,m,n},x] && NonzeroQ[b^2-4*a*c] && ZeroQ[j-2*n] && IntegersQ[p,(m+1)/n] && 
  Not[NegativeQ[n]] && p<0 && ((m+1)/n>0 || Not[IntegerQ[m]])


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Derivation: Integration by substitution*)


(* ::Subsubsection:: *)
(*Rule: If  b^2-4 a c!=0 \[And] m+1!=0 \[And] n!=1 \[And] m,n,p\[Element]\[DoubleStruckCapitalZ] \[And] \[Not]CoprimeQ[m+1,n] \[And] p<0 \[And] (m+1)/n>0, let g=GCD[m+1,n], then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]x^m (d+e x^n)(a+b x^n+c x^(2 n))^p \[DifferentialD]x  \[LongRightArrow]  (1/g)Subst[\[Integral]x^((m+1)/g-1) (d+e x^(n/g))(a+b x^(n/g)+c x^((2n)/g))^p \[DifferentialD]x,x,x^g]*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[x_^m_.*(d_+e_.*x_^n_)*(a_+b_.*x_^n_+c_.*x_^j_)^p_,x_Symbol] :=
  Module[{g=GCD[m+1,n]},
  Dist[1/g,Subst[Int[x^((m+1)/g-1)*(d+e*x^(n/g))*(a+b*x^(n/g)+c*x^(2*n/g))^p,x],x,x^g]]] /; 
FreeQ[{a,b,c,d,e,m,n},x] && NonzeroQ[b^2-4*a*c] && ZeroQ[j-2*n] && NonzeroQ[m+1] && 
  IntegersQ[m,n,p] && Not[CoprimeQ[m+1,n]] && p<0 && (m+1)/n>0


(* ::PageBreak:: *)
(**)


(* ::Subsubsection:: *)
(* *)


(* ::Title::Bold::Closed:: *)
(*\[Integral](a+b x^n)/(c+d x^2+e x^n+f x^(2n)) \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Note: Previously undiscovered rule?*)


(* ::Subsubsection:: *)
(*Rule: If  b^2 c-a^2 f (n-1)^2=0 \[And] b e+2 a f(n-1)=0 \[And] c d>0, then*)


(* ::Subsubsection:: *)
(**)


(* ::Subsubtitle::Bold:: *)
(*\[Integral](a+b x^n)/(c+d x^2+e x^n+f x^(2n)) \[DifferentialD]x  \[LongRightArrow]  (a/Sqrt[c d])ArcTan[(a (n-1) Sqrt[c d] x)/(c (a (n-1)-b x^n))]*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[(a_+b_.*x_^n_)/(c_+d_.*x_^2+e_.*x_^n_+f_.*x_^j_), x_Symbol] :=
  a/Rt[c*d,2]*ArcTan[(n-1)*a*Rt[c*d,2]*x/(c*(a*(n-1)-b*x^n))] /;
FreeQ[{a,b,c,d,e,f,n},x] && ZeroQ[j-2*n] &&
ZeroQ[b^2*c-a^2*f*(n-1)^2] && ZeroQ[b*e+2*a*f*(n-1)] && PosQ[c*d]


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Note: Previously undiscovered rule?*)


(* ::Subsubsection:: *)
(*Rule: If  b^2 c-a^2 f (n-1)^2=0 \[And] b e+2 a f(n-1)=0 \[And] \[Not](c d>0), then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral](a+b x^n)/(c+d x^2+e x^n+f x^(2n)) \[DifferentialD]x  \[LongRightArrow]  (a/Sqrt[-c d])ArcTanh[(a (n-1) Sqrt[-c d] x)/(c (a (n-1)-b x^n))]*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[(a_+b_.*x_^n_)/(c_+d_.*x_^2+e_.*x_^n_+f_.*x_^j_), x_Symbol] :=
  a/Rt[-c*d,2]*ArcTanh[a*(n-1)*Rt[-c*d,2]*x/(c*(a*(n-1)-b*x^n))] /;
FreeQ[{a,b,c,d,e,f,n},x] && ZeroQ[j-2*n] &&
ZeroQ[b^2*c-a^2*f*(n-1)^2] && ZeroQ[b*e+2*a*f*(n-1)] && NegQ[c*d]


(* ::PageBreak:: *)
(**)


(* ::Title::Bold::Closed:: *)
(*\[Integral](x^m (a+b x^n))/(c+d x^(2(m+1))+e x^n+f x^(2n)) \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Note: Previously undiscovered rule?*)


(* ::Subsubsection:: *)
(*Rule: If  a^2 f (m-n+1)^2-b^2 c (m+1)^2=0 \[And] b e(m+1)-2a f(m-n+1)=0 \[And] c d>0, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral](x^m (a+b x^n))/(c+d x^(2(m+1))+e x^n+f x^(2n)) \[DifferentialD]x  \[LongRightArrow]  (a/((m+1) Sqrt[c d]))ArcTan[(a(m-n+1) Sqrt[c d] x^(m+1))/(c (a(m-n+1)+b(m+1)x^n))]*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[x_^m_.*(a_+b_.*x_^n_.)/(c_+d_.*x_^k_.+e_.*x_^n_.+f_.*x_^j_), x_Symbol] :=
  a*ArcTan[a*(m-n+1)*Rt[c*d,2]*x^(m+1)/(c*(a*(m-n+1)+b*(m+1)*x^n))]/((m+1)*Rt[c*d,2]) /;
FreeQ[{a,b,c,d,e,f,m,n},x] && ZeroQ[j-2*n] && ZeroQ[k-2*(m+1)] &&
ZeroQ[a^2*f*(m-n+1)^2-b^2*c*(m+1)^2] && ZeroQ[b*e*(m+1)-2*a*f*(m-n+1)] && PosQ[c*d]


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Note: Previously undiscovered rule?*)


(* ::Subsubsection:: *)
(*Rule: If  a^2 f (m-n+1)^2-b^2 c (m+1)^2=0 \[And] b e (m+1)-2 a f (m-n+1)=0 \[And] \[Not](c d>0), then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral](x^m (a+b x^n))/(c+d x^(2(m+1))+e x^n+f x^(2n)) \[DifferentialD]x  \[LongRightArrow]  (a/((m+1) Sqrt[-c d]))ArcTanh[(a(m-n+1)Sqrt[-c d] x^(m+1))/(c (a(m-n+1)+b(m+1)x^n))]*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[x_^m_.*(a_+b_.*x_^n_.)/(c_+d_.*x_^k_.+e_.*x_^n_.+f_.*x_^j_), x_Symbol] :=
  a*ArcTanh[a*(m-n+1)*Rt[-c*d,2]*x^(m+1)/(c*(a*(m-n+1)+b*(m+1)*x^n))]/((m+1)*Rt[-c*d,2]) /;
FreeQ[{a,b,c,d,e,f,m,n},x] && ZeroQ[j-2*n] && ZeroQ[k-2*(m+1)] &&
ZeroQ[a^2*f*(m-n+1)^2-b^2*c*(m+1)^2] && ZeroQ[b*e*(m+1)-2*a*f*(m-n+1)] && NegQ[c*d]


(* ::PageBreak:: *)
(**)


(* ::Title::Bold::Closed:: *)
(*\[Integral](d+e x+f x^2+g x^3)/(a+b x+c x^2+b x^3+a x^4) \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Derivation: Algebraic expansion*)


(* ::Subsubsection:: *)
(*Basis: If  q=Sqrt[8 a^2+b^2-4 a c], then  a+b x+c x^2+b x^3+a x^4=a (1+((b-q) x)/(2 a)+x^2) (1+((b+q) x)/(2 a)+x^2)*)


(* ::Subsubsection:: *)
(*Basis: If  q=Sqrt[8 a^2+b^2-4 a c], then (d+e x+f x^2+g x^3)/(a+b x+c x^2+b x^3+a x^4)=(b d-2 a e+2 a g+d q+(2 a d-2 a f+b g+g q) x)/(q (2 a+(b+q) x+2 a x^2))-(b d-2 a e+2 a g-d q+(2 a d-2 a f+b g-g q) x)/(q (2 a+(b-q) x+2 a x^2))*)


(* ::Subsubsection:: *)
(*Rule: If  8 a^2+b^2-4 a c>0, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral](d+e x+f x^2+g x^3)/(a+b x+c x^2+b x^3+a x^4) \[DifferentialD]x  \[LongRightArrow]  (1/q)\[Integral](b d-2 a e+2 a g+d q+(2 a d-2 a f+b g+g q) x)/(2 a+(b+q) x+2 a x^2) \[DifferentialD]x-*)
(*                                                             1/q \[Integral](b d-2 a e+2 a g-d q+(2 a d-2 a f+b g-g q) x)/(2 a+(b-q) x+2 a x^2) \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[(d_.+e_.*x_+f_.*x_^2+g_.*x_^3)/(a_+b_.*x_+c_.*x_^2+b_.*x_^3+a_.*x_^4),x_Symbol] :=
  Module[{q=Sqrt[8*a^2+b^2-4*a*c]},
  Dist[1/q,Int[(b*d-2*a*e+2*a*g+d*q+(2*a*d-2*a*f+b*g+g*q)*x)/(2*a+(b+q)*x+2*a*x^2),x]] -
  Dist[1/q,Int[(b*d-2*a*e+2*a*g-d*q+(2*a*d-2*a*f+b*g-g*q)*x)/(2*a+(b-q)*x+2*a*x^2),x]]] /;
FreeQ[{a,b,c,d,e,f,g},x] && PosQ[8*a^2+b^2-4*a*c]


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Derivation: Algebraic expansion*)


(* ::Subsubsection:: *)
(*Basis: If  q=Sqrt[8 a^2+b^2-4 a c], then (d+e x+g x^3)/(a+b x+c x^2+b x^3+a x^4)=(b d-2 a e+2 a g+d q+(2 a d+b g+g q) x)/(q (2 a+(b+q) x+2 a x^2))-(b d-2 a e+2 a g-d q+(2 a d+b g-g q) x)/(q (2 a+(b-q) x+2 a x^2))*)


(* ::Subsubsection:: *)
(*Rule: If  8 a^2+b^2-4 a c>0, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral](d+e x+g x^3)/(a+b x+c x^2+b x^3+a x^4) \[DifferentialD]x  \[LongRightArrow]  (1/q)\[Integral](b d-2 a e+2 a g+d q+(2 a d+b g+g q) x)/(2 a+(b+q) x+2 a x^2) \[DifferentialD]x-*)
(*                                                              1/q \[Integral](b d-2 a e+2 a g-d q+(2 a d+b g-g q) x)/(2 a+(b-q) x+2 a x^2) \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[(d_.+e_.*x_+g_.*x_^3)/(a_+b_.*x_+c_.*x_^2+b_.*x_^3+a_.*x_^4),x_Symbol] :=
  Module[{q=Sqrt[8*a^2+b^2-4*a*c]},
  Dist[1/q,Int[(b*d-2*a*e+2*a*g+d*q+(2*a*d+b*g+g*q)*x)/(2*a+(b+q)*x+2*a*x^2),x]] -
  Dist[1/q,Int[(b*d-2*a*e+2*a*g-d*q+(2*a*d+b*g-g*q)*x)/(2*a+(b-q)*x+2*a*x^2),x]]] /;
FreeQ[{a,b,c,d,e,g},x] && PosQ[8*a^2+b^2-4*a*c]


(* ::PageBreak:: *)
(**)


(* ::Title::Bold::Closed:: *)
(*\[Integral]Pm[x]/Qn[x]^p \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Reference: G&R 2.104*)


(* ::Subsubsection:: *)
(*Note: Equivalent to the Ostrogradskiy-Hermite method but without the need to solve a system of linear equations.*)


(* ::Subsubsection:: *)
(*Note: Finds one term of the rational part of the antiderivative, thereby reducing the degree of the polynomial in the numerator of the integrand.*)


(* ::Subsubsection:: *)
(*Note: Requirement that m<2n-1 ensures new term is a proper fraction.*)


(* ::Subsubsection:: *)
(*Rule: If  p>1 \[And] 1<n<=m+1 \[And] m+1-n p<0, let c=pm/(qn (m+1-n p)), then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]Pm[x]/Qn[x]^p \[DifferentialD]x  \[LongRightArrow]  ((c x^(m-n+1))/Qn[x]^(p-1))+\[Integral](Pm[x]-c x^(m-n) ((m-n+1) Qn[x]+(1-p) x \!\( *)
(*\*SubscriptBox[\(\[PartialD]\), \(x\)]\(Qn[x]\)\)))/Qn[x]^p \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
If[ShowSteps,

Int[u_*v_^p_,x_Symbol] :=
  Module[{m=Exponent[u,x],n=Exponent[v,x]},
  Module[{c=Coefficient[u,x,m]/(Coefficient[v,x,n]*(m+1+n*p)),w},
  w=Apart[u-c*x^(m-n)*((m-n+1)*v+(p+1)*x*D[v,x]),x];
  If[ZeroQ[w],
    ShowStep["
If p>1, 1<n<=m+1, and m+1-n*p<0, let c=pm/(qn*(m+1-n*p)), then if (Pm[x]-c*x^(m-n)*((m-n+1)*Qn[x]+(1-p)*x*D[Qn[x],x]))==0,",
	  "Int[Pm[x]/Qn[x]^p,x]", "c*x^(m-n+1)/Qn[x]^(p-1)",
      Hold[c*x^(m-n+1)*v^(p+1)]],
  ShowStep["If p>1, 1<n<=m+1, and m+1-n*p<0, let c=pm/(qn*(m+1-n*p)), then",
	"Int[Pm[x]/Qn[x]^p,x]",
	"c*x^(m-n+1)/Qn[x]^(p-1)+Int[(Pm[x]-c*x^(m-n)*((m-n+1)*Qn[x]+(1-p)*x*D[Qn[x],x]))/Qn[x]^p,x]",
	Hold[c*x^(m-n+1)*v^(p+1) + Int[w*v^p,x]]]]] /;
 m+1>=n>1 && m+n*p<-1 && FalseQ[DerivativeDivides[v,u,x]]] /;
SimplifyFlag && RationalQ[p] && p<-1 && PolynomialQ[u,x] && PolynomialQ[v,x] && SumQ[v] && 
Not[MonomialQ[u,x] && BinomialQ[v,x]] && 
Not[ZeroQ[Coefficient[u,x,0]] && ZeroQ[Coefficient[v,x,0]]],

Int[u_*v_^p_,x_Symbol] :=
  Module[{m=Exponent[u,x],n=Exponent[v,x]},
  Module[{c=Coefficient[u,x,m]/(Coefficient[v,x,n]*(m+1+n*p)),w},
  c=Coefficient[u,x,m]/(Coefficient[v,x,n]*(m+1+n*p));
  w=Apart[u-c*x^(m-n)*((m-n+1)*v+(p+1)*x*D[v,x]),x];
  If[ZeroQ[w],
    c*x^(m-n+1)*v^(p+1),
  c*x^(m-n+1)*v^(p+1) + Int[w*v^p,x]]] /;
 m+1>=n>1 && m+n*p<-1 && FalseQ[DerivativeDivides[v,u,x]]] /;
RationalQ[p] && p<-1 && PolynomialQ[u,x] && PolynomialQ[v,x] && SumQ[v] && 
Not[MonomialQ[u,x] && BinomialQ[v,x]] && 
Not[ZeroQ[Coefficient[u,x,0]] && ZeroQ[Coefficient[v,x,0]]]]


(* ::PageBreak:: *)
(**)


(* ::Title::Bold::Closed:: *)
(*\[Integral]u+v \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Reference: G&R 2.02.5*)


(* ::Subsubsection:: *)
(*Rule:*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]f'[u] g[v]\!\( *)
(*\*SubscriptBox[\(\[PartialD]\), \(x\)]u\)+f[u] g'[v]\!\( *)
(*\*SubscriptBox[\(\[PartialD]\), \(x\)]v\)\[DifferentialD]x  \[LongRightArrow]  f[u] g[v]*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[f_'[u_]*g_[v_]*w_. + f_[u_]*g_'[v_]*t_.,x_Symbol] :=
  f[u]*g[v] /;
FreeQ[{f,g},x] && ZeroQ[w-D[u,x]] && ZeroQ[t-D[v,x]]


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Reference: G&R 2.02.2, CRC 2,4*)


(* ::Subsubsection:: *)
(*Rule:*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]a+b u+c v+\[CenterEllipsis] \[DifferentialD]x  \[LongRightArrow]  a x+b \[Integral]u \[DifferentialD]x+c \[Integral]v \[DifferentialD]x+\[CenterEllipsis]*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
If[ShowSteps,

Int[u_,x_Symbol] :=
  If[SplitFreeTerms[u,x][[1]]===0,
    ShowStep["","Int[a*u+b*v+\[CenterEllipsis],x]","a*Int[u,x]+b*Int[v,x]+\[CenterEllipsis]",Hold[
    SplitFreeIntegrate[u,x]]],
  ShowStep["","Int[a+b*u+c*v+\[CenterEllipsis],x]","a*x+b*Int[u,x]+c*Int[v,x]+\[CenterEllipsis]",Hold[
  SplitFreeIntegrate[u,x]]]] /;
SimplifyFlag && SumQ[u],

Int[u_,x_Symbol] :=
  SplitFreeIntegrate[u,x] /;
SumQ[u]]


(* ::Code:: *)
SplitFreeIntegrate[u_,x_Symbol] :=
  If[SumQ[u],
    Map[Function[SplitFreeIntegrate[#,x]],u],
  If[FreeQ[u,x],
    u*x,
  If[MatchQ[u,c_*(a_+b_.*x) /; FreeQ[{a,b,c},x]],
    Int[u,x],
  Module[{lst=SplitFreeFactors[u,x]},
  Dist[lst[[1]], Int[lst[[2]],x]]]]]]
