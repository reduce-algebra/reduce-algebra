(* ::Package:: *)

(* ::Title::Bold::Closed:: *)
(*\[Integral]ArcSinh[a+b x]^n \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Reference: CRC 579, A&S 4.6.43*)


(* ::Subsubsection:: *)
(*Derivation: Integration by parts*)


(* ::Subsubsection:: *)
(*Rule:*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]ArcSinh[a+b x]\[DifferentialD]x  \[LongRightArrow]  (((a+b x) ArcSinh[a+b x])/b)-Sqrt[1+(a+b x)^2]/b*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[ArcSinh[a_.+b_.*x_],x_Symbol] :=
  (a+b*x)*ArcSinh[a+b*x]/b - Sqrt[1+(a+b*x)^2]/b /;
FreeQ[{a,b},x]


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Derivation: Iterated integration by parts*)


(* ::Subsubsection:: *)
(*Rule: If  n>1, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]ArcSinh[a+b x]^n \[DifferentialD]x  \[LongRightArrow]  (((a+b x) ArcSinh[a+b x]^n)/b)-                                                                *)
(*                                          (n Sqrt[1+(a+b x)^2] ArcSinh[a+b x]^(n-1))/b+n(n-1)\[Integral]ArcSinh[a+b x]^(n-2) \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[ArcSinh[a_.+b_.*x_]^n_,x_Symbol] :=
  (a+b*x)*ArcSinh[a+b*x]^n/b -
  n*Sqrt[1+(a+b*x)^2]*ArcSinh[a+b*x]^(n-1)/b +
  Dist[n*(n-1),Int[ArcSinh[a+b*x]^(n-2),x]] /;
FreeQ[{a,b},x] && RationalQ[n] && n>1


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Derivation: Integration by substitution*)


(* ::Subsubsection:: *)
(*Basis: 1/ArcSinh[z]=Cosh[ArcSinh[z]]/ArcSinh[z] Derivative[1][ArcSinh][z]*)


(* ::Subsubsection:: *)
(*Rule:*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]1/ArcSinh[a+b x] \[DifferentialD]x  \[LongRightArrow]  (CoshIntegral[ArcSinh[a+b x]]/b)*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[1/ArcSinh[a_.+b_.*x_],x_Symbol] :=
  CoshIntegral[ArcSinh[a+b*x]]/b /;
FreeQ[{a,b},x]


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Derivation: Integration by substitution*)


(* ::Subsubsection:: *)
(*Basis: 1/ArcSinh[z]^2=Cosh[ArcSinh[z]]/ArcSinh[z]^2 Derivative[1][ArcSinh][z]*)


(* ::Subsubsection:: *)
(*Rule:*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]1/ArcSinh[a+b x]^2 \[DifferentialD]x  \[LongRightArrow]  -(Sqrt[1+(a+b x)^2]/(b ArcSinh[a+b x]))+SinhIntegral[ArcSinh[a+b x]]/b*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[1/ArcSinh[a_.+b_.*x_]^2,x_Symbol] :=
  -Sqrt[1+(a+b*x)^2]/(b*ArcSinh[a+b*x]) + SinhIntegral[ArcSinh[a+b*x]]/b /;
FreeQ[{a,b},x]


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Derivation: Integration by substitution*)


(* ::Subsubsection:: *)
(*Basis: 1/Sqrt[ArcSinh[z]]=Cosh[ArcSinh[z]]/Sqrt[ArcSinh[z]] Derivative[1][ArcSinh][z]*)


(* ::Subsubsection:: *)
(*Rule:*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]1/Sqrt[ArcSinh[a+b x]] \[DifferentialD]x  \[LongRightArrow]  ((Sqrt[\[Pi]] Erf[Sqrt[ArcSinh[a+b x]]])/(2 b))+(Sqrt[\[Pi]] Erfi[Sqrt[ArcSinh[a+b x]]])/(2 b)*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[1/Sqrt[ArcSinh[a_.+b_.*x_]],x_Symbol] :=
  Sqrt[Pi]*Erf[Sqrt[ArcSinh[a+b*x]]]/(2*b) +
  Sqrt[Pi]*Erfi[Sqrt[ArcSinh[a+b*x]]]/(2*b) /;
FreeQ[{a,b},x]


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Derivation: Integration by parts*)


(* ::Subsubsection:: *)
(*Rule:*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]Sqrt[ArcSinh[a+b x]]\[DifferentialD]x  \[LongRightArrow]  (((a+b x) Sqrt[ArcSinh[a+b x]])/b)+                                                                         *)
(*                                                                   (Sqrt[\[Pi]] Erf[Sqrt[ArcSinh[a+b x]]])/(4 b)-(Sqrt[\[Pi]] Erfi[Sqrt[ArcSinh[a+b x]]])/(4 b)*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[Sqrt[ArcSinh[a_.+b_.*x_]],x_Symbol] :=
  (a+b*x)*Sqrt[ArcSinh[a+b*x]]/b +
  Sqrt[Pi]*Erf[Sqrt[ArcSinh[a+b*x]]]/(4*b) -
  Sqrt[Pi]*Erfi[Sqrt[ArcSinh[a+b*x]]]/(4*b) /;
FreeQ[{a,b},x]


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Derivation: Inverted iterated integration by parts*)


(* ::Subsubsection:: *)
(*Rule: If  n<-1 \[And] n!=-2, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]ArcSinh[a+b x]^n \[DifferentialD]x  \[LongRightArrow]  -(((a+b x) ArcSinh[a+b x]^(n+2))/(b (n+1) (n+2)))+                                                                                   *)
(*                                             (Sqrt[1+(a+b x)^2] ArcSinh[a+b x]^(n+1))/(b (n+1))+1/((n+1) (n+2)) \[Integral]ArcSinh[a+b x]^(n+2) \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[ArcSinh[a_.+b_.*x_]^n_,x_Symbol] :=
  -(a+b*x)*ArcSinh[a+b*x]^(n+2)/(b*(n+1)*(n+2)) +
  Sqrt[1+(a+b*x)^2]*ArcSinh[a+b*x]^(n+1)/(b*(n+1)) +
  Dist[1/((n+1)*(n+2)),Int[ArcSinh[a+b*x]^(n+2),x]] /;
FreeQ[{a,b},x] && RationalQ[n] && n<-1 && n!=-2


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Rule: If  n\[NotElement]\[DoubleStruckCapitalQ] \[Or] -1<n<1, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]ArcSinh[a+b x]^n \[DifferentialD]x  \[LongRightArrow]                                                                                                                                             *)
(*                            ((ArcSinh[a+b x]^n Gamma[n+1,-ArcSinh[a+b x]])/(2 b (-ArcSinh[a+b x])^n))-Gamma[n+1,ArcSinh[a+b x]]/(2 b)*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[ArcSinh[a_.+b_.*x_]^n_,x_Symbol] :=
  ArcSinh[a+b*x]^n*Gamma[n+1,-ArcSinh[a+b*x]]/(2*b*(-ArcSinh[a+b*x])^n) -
  Gamma[n+1,ArcSinh[a+b*x]]/(2*b) /;
FreeQ[{a,b,n},x] && (Not[RationalQ[n]] || -1<n<1)


(* ::PageBreak:: *)
(**)


(* ::Title::Bold::Closed:: *)
(*\[Integral]x^m ArcSinh[a+b x]\[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Reference: CRC 581, A&S 4.6.50*)


(* ::Subsubsection:: *)
(*Derivation: Integration by parts*)


(* ::Subsubsection:: *)
(*Rule: If  m+1!=0, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]x^m ArcSinh[a+b x]\[DifferentialD]x  \[LongRightArrow]  ((x^(m+1) ArcSinh[a+b x])/(m+1))-b/(m+1) \[Integral]x^(m+1)/Sqrt[1+a^2+2 a b x+b^2 x^2] \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[x_^m_.*ArcSinh[a_.+b_.*x_],x_Symbol] :=
  x^(m+1)*ArcSinh[a+b*x]/(m+1) - 
  Dist[b/(m+1),Int[x^(m+1)/Sqrt[1+a^2+2*a*b*x+b^2*x^2],x]] /;
FreeQ[{a,b,m},x] && NonzeroQ[m+1]


(* ::PageBreak:: *)
(**)


(* ::Title::Bold::Closed:: *)
(*\[Integral]x^m ArcSinh[a x]^n \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Rule:*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]x/Sqrt[ArcSinh[a x]] \[DifferentialD]x  \[LongRightArrow]  -(1/(4 a^2)) Sqrt[\[Pi]/2] Erf[Sqrt[2] Sqrt[ArcSinh[a x]]]+1/(4 a^2) Sqrt[\[Pi]/2] Erfi[Sqrt[2] Sqrt[ArcSinh[a x]]]*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[x_/Sqrt[ArcSinh[a_.*x_]],x_Symbol] :=
  -Sqrt[Pi/2]*Erf[Sqrt[2]*Sqrt[ArcSinh[a*x]]]/(4*a^2) + 
  Sqrt[Pi/2]*Erfi[Sqrt[2]*Sqrt[ArcSinh[a*x]]]/(4*a^2) /;
FreeQ[a,x]


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Rule:*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]x/ArcSinh[a x]^(3/2) \[DifferentialD]x  \[LongRightArrow]                                                                                                                                                     *)
(*    -((2 x Sqrt[1+a^2 x^2])/(a Sqrt[ArcSinh[a x]]))+1/a^2 Sqrt[\[Pi]/2] Erf[Sqrt[2] Sqrt[ArcSinh[a x]]]+1/a^2 Sqrt[\[Pi]/2] Erfi[Sqrt[2] Sqrt[ArcSinh[a x]]]*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[x_/ArcSinh[a_.*x_]^(3/2),x_Symbol] :=
  -2*x*Sqrt[1+a^2*x^2]/(a*Sqrt[ArcSinh[a*x]]) +
  Sqrt[Pi/2]*Erf[Sqrt[2]*Sqrt[ArcSinh[a*x]]]/a^2 +
  Sqrt[Pi/2]*Erfi[Sqrt[2]*Sqrt[ArcSinh[a*x]]]/a^2 /;
FreeQ[a,x]


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Rule: If  n>1, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]x ArcSinh[a x]^n \[DifferentialD]x  \[LongRightArrow]  -((n x Sqrt[1+a^2 x^2] ArcSinh[a x]^(n-1))/(4 a))+                                                                     *)
(*                                                        ArcSinh[a x]^n/(4 a^2)+(x^2 ArcSinh[a x]^n)/2+(n (n-1))/4 \[Integral]x ArcSinh[a x]^(n-2) \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[x_*ArcSinh[a_.*x_]^n_,x_Symbol] :=
  -n*x*Sqrt[1+a^2*x^2]*ArcSinh[a*x]^(n-1)/(4*a) +
  ArcSinh[a*x]^n/(4*a^2) + x^2*ArcSinh[a*x]^n/2 +
  Dist[n*(n-1)/4,Int[x*ArcSinh[a*x]^(n-2),x]] /;
FreeQ[a,x] && RationalQ[n] && n>0


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Rule: If  n<-1 \[And] n!=-2, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]x ArcSinh[a x]^n \[DifferentialD]x  \[LongRightArrow]  ((x Sqrt[1+a^2 x^2] ArcSinh[a x]^(n+1))/(a(n+1)))-                                                                        *)
(*                                ArcSinh[a x]^(n+2)/(a^2 (n+1) (n+2))-(2x^2 ArcSinh[a x]^(n+2))/((n+1)(n+2))+4/((n+1) (n+2)) \[Integral]x ArcSinh[a x]^(n+2) \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[x_*ArcSinh[a_.*x_]^n_,x_Symbol] :=
  x*Sqrt[1+a^2*x^2]*ArcSinh[a*x]^(n+1)/(a*(n+1)) -
  ArcSinh[a*x]^(n+2)/(a^2*(n+1)*(n+2)) -
  2*x^2*ArcSinh[a*x]^(n+2)/((n+1)*(n+2)) +
  Dist[4/((n+1)*(n+2)),Int[x*ArcSinh[a*x]^(n+2),x]] /;
FreeQ[a,x] && RationalQ[n] && n<-1 && n!=-2


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Rule: If  n>1, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]ArcSinh[a x]^n/x^3 \[DifferentialD]x  \[LongRightArrow]                                                                                                                                                            *)
(*                                -((a n Sqrt[1+a^2 x^2] ArcSinh[a x]^(n-1))/(2 x))-ArcSinh[a x]^n/(2 x^2)+(a^2 n(n-1))/2 \[Integral]ArcSinh[a x]^(n-2)/x \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[ArcSinh[a_.*x_]^n_/x_^3,x_Symbol] :=
  -a*n*Sqrt[1+a^2*x^2]*ArcSinh[a*x]^(n-1)/(2*x) -
  ArcSinh[a*x]^n/(2*x^2) +
  Dist[a^2*n*(n-1)/2,Int[ArcSinh[a*x]^(n-2)/x,x]] /;
FreeQ[a,x] && RationalQ[n] && n>1


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Rule: If  m\[Element]\[DoubleStruckCapitalZ] \[And] m<-3 \[And] n>1, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]x^m ArcSinh[a x]^n \[DifferentialD]x  \[LongRightArrow]  -((a n x^(m+2) Sqrt[1+a^2 x^2] ArcSinh[a x]^(n-1))/((m+1)(m+2)))+                                                                           *)
(*                  (x^(m+1) ArcSinh[a x]^n)/(m+1)+(a^2 (m+3)x^(m+3) ArcSinh[a x]^n)/((m+1)(m+2))-                   *)
(*                                                      (a^2 (m+3)^2)/((m+1)(m+2)) \[Integral]x^(m+2) ArcSinh[a x]^n \[DifferentialD]x+(a^2 n(n-1))/((m+1)(m+2)) \[Integral]x^(m+2) ArcSinh[a x]^(n-2) \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[x_^m_*ArcSinh[a_.*x_]^n_,x_Symbol] :=
  -a*n*x^(m+2)*Sqrt[1+a^2*x^2]*ArcSinh[a*x]^(n-1)/((m+1)*(m+2)) +
  x^(m+1)*ArcSinh[a*x]^n/(m+1) +
  a^2*(m+3)*x^(m+3)*ArcSinh[a*x]^n/((m+1)*(m+2)) -
  Dist[a^2*(m+3)^2/((m+1)*(m+2)),Int[x^(m+2)*ArcSinh[a*x]^n,x]] +
  Dist[a^2*n*(n-1)/((m+1)*(m+2)),Int[x^(m+2)*ArcSinh[a*x]^(n-2),x]] /;
FreeQ[a,x] && IntegerQ[m] && RationalQ[n] && m<-3 && n>1


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Rule: If  m\[Element]\[DoubleStruckCapitalZ] \[And] m>1 \[And] n<-1 \[And] n!=-2, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]x^m ArcSinh[a x]^n \[DifferentialD]x  \[LongRightArrow]  ((x^m Sqrt[1+a^2 x^2] ArcSinh[a x]^(n+1))/(a(n+1)))-                                                                                        *)
(*(m x^(m-1) ArcSinh[a x]^(n+2))/(a^2 (n+1) (n+2))-((m+1)x^(m+1) ArcSinh[a x]^(n+2))/((n+1) (n+2))+      *)
(*                                               (m+1)^2/((n+1) (n+2)) \[Integral]x^m ArcSinh[a x]^(n+2) \[DifferentialD]x+(m (m-1))/(a^2 (n+1) (n+2)) \[Integral]x^(m-2) ArcSinh[a x]^(n+2) \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[x_^m_*ArcSinh[a_.*x_]^n_,x_Symbol] :=
  x^m*Sqrt[1+a^2*x^2]*ArcSinh[a*x]^(n+1)/(a*(n+1)) -
  m*x^(m-1)*ArcSinh[a*x]^(n+2)/(a^2*(n+1)*(n+2)) -
  (m+1)*x^(m+1)*ArcSinh[a*x]^(n+2)/((n+1)*(n+2)) +
  Dist[(m+1)^2/((n+1)*(n+2)),Int[x^m*ArcSinh[a*x]^(n+2),x]] +
  Dist[m*(m-1)/(a^2*(n+1)*(n+2)),Int[x^(m-2)*ArcSinh[a*x]^(n+2),x]] /;
FreeQ[a,x] && IntegerQ[m] && RationalQ[n] && m>1 && n<-1 && n!=-2


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Derivation: Integration by substitution*)


(* ::Subsubsection:: *)
(*Basis: ArcSinh[a x^p]^n/x=1/p ArcSinh[a x^p]^n Coth[ArcSinh[a x^p]] \!\( *)
(*\*SubscriptBox[\(\[PartialD]\), \(x\)]\(ArcSinh[a\ *)
(*\*SuperscriptBox[\(x\), \(p\)]]\)\)*)


(* ::Subsubsection:: *)
(*Rule: If  n\[Element]\[DoubleStruckCapitalZ] \[And] n>0, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]ArcSinh[a x^p]^n/x \[DifferentialD]x  \[LongRightArrow]  (1/p) Subst[\[Integral]x^n Coth[x]\[DifferentialD]x,x,ArcSinh[a x^p]]*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[ArcSinh[a_.*x_^p_.]^n_./x_,x_Symbol] :=
  Dist[1/p,Subst[Int[x^n*Coth[x],x],x,ArcSinh[a*x^p]]] /;
FreeQ[{a,p},x] && IntegerQ[n] && n>0


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Derivation: Integration by parts and substitution*)


(* ::Subsubsection:: *)
(*Basis: If  m\[Element]\[DoubleStruckCapitalZ], (x^(m+1) ArcSinh[a x]^(n-1))/Sqrt[1+a^2 x^2]=1/a^(m+2) ArcSinh[a x]^(n-1) Sinh[ArcSinh[a x]]^(m+1) \!\( *)
(*\*SubscriptBox[\(\[PartialD]\), \(x\)]\(ArcSinh[a\ x]\)\)*)


(* ::Subsubsection:: *)
(*Rule: If  m\[Element]\[DoubleStruckCapitalZ] \[And] m!=-1, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]x^m ArcSinh[a x]^n \[DifferentialD]x  \[LongRightArrow]  ((x^(m+1) ArcSinh[a x]^n)/(m+1))-n/(a^(m+1) (m+1)) Subst[\[Integral]x^(n-1) Sinh[x]^(m+1) \[DifferentialD]x,x,ArcSinh[a x]]*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[x_^m_.*ArcSinh[a_.*x_]^n_,x_Symbol] :=
  x^(m+1)*ArcSinh[a*x]^n/(m+1) -
  Dist[n/(a^(m+1)*(m+1)),Subst[Int[x^(n-1)*Sinh[x]^(m+1),x],x,ArcSinh[a*x]]] /;
FreeQ[{a,n},x] && IntegerQ[m] && m!=-1


(* ::PageBreak:: *)
(**)


(* ::Title::Bold::Closed:: *)
(*\[Integral](a+b ArcSinh[c+d x])^n \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Derivation: Integration by substitution*)


(* ::Subsubsection:: *)
(*Basis: (a+b ArcSinh[c+d x])^n=1/d (a+b ArcSinh[c+d x])^n Cosh[ArcSinh[c+d x]]\!\( *)
(*\*SubscriptBox[\(\[PartialD]\), \(x\)]\(ArcSinh[c + d\ x]\)\)*)


(* ::Subsubsection:: *)
(*Rule: If  n\[NotElement]\[DoubleStruckCapitalZ], then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral](a+b ArcSinh[c+d x])^n \[DifferentialD]x  \[LongRightArrow]  (1/d) Subst[\[Integral](a+b x)^n Cosh[x]\[DifferentialD]x,x,ArcSinh[c+d x]]*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[(a_+b_.*ArcSinh[c_.+d_.*x_])^n_,x_Symbol] :=
  Dist[1/d,Subst[Int[(a+b*x)^n*Cosh[x],x],x,ArcSinh[c+d*x]]] /;
FreeQ[{a,b,c,d},x] && Not[IntegerQ[n]]


(* ::PageBreak:: *)
(**)


(* ::Title::Bold::Closed:: *)
(*\[Integral]x^m (a+b ArcSinh[c+d x])^n \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Derivation: Integration by substitution*)


(* ::Subsubsection:: *)
(*Basis: If m\[Element]\[DoubleStruckCapitalZ],  x^m (a+b ArcSinh[c+d x])^n=1/d^(m+1) (a+b ArcSinh[c+d x])^n (Sinh[ArcSinh[c+d x]]-c)^m Cosh[ArcSinh[c+d x]]\!\( *)
(*\*SubscriptBox[\(\[PartialD]\), \(x\)]\(ArcSinh[c + d\ x]\)\)*)


(* ::Subsubsection:: *)
(*Rule: If  m\[Element]\[DoubleStruckCapitalZ] \[And] n\[NotElement]\[DoubleStruckCapitalZ] \[And] m>0, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]x^m (a+b ArcSinh[c+d x])^n \[DifferentialD]x  \[LongRightArrow]  (1/d^(m+1)) Subst[\[Integral](a+b x)^n (Sinh[x]-c)^m Cosh[x]\[DifferentialD]x,x,ArcSinh[c+d x]]*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[x_^m_.*(a_+b_.*ArcSinh[c_.+d_.*x_])^n_,x_Symbol] :=
  Dist[1/d^(m+1),Subst[Int[(a+b*x)^n*(Sinh[x]-c)^m*Cosh[x],x],x,ArcSinh[c+d*x]]] /;
FreeQ[{a,b,c,d},x] && IntegerQ[m] && Not[IntegerQ[n]] && m>0


(* ::PageBreak:: *)
(**)


(* ::Title::Bold::Closed:: *)
(*\[Integral](x ArcSinh[a+b x]^n)/Sqrt[1+(a+b x)^2] \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Derivation: Integration by parts*)


(* ::Subsubsection:: *)
(*Rule: If  n>1, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral](x ArcSinh[a+b x]^n)/Sqrt[1+(a+b x)^2] \[DifferentialD]x  \[LongRightArrow]                                                                                                                                 *)
(*               ((Sqrt[1+(a+b x)^2] ArcSinh[a+b x]^n)/b^2)-n/b \[Integral]ArcSinh[a+b x]^(n-1) \[DifferentialD]x-a/b \[Integral]ArcSinh[a+b x]^n/Sqrt[1+(a+b x)^2] \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[x_*ArcSinh[a_.+b_.*x_]^n_/Sqrt[u_],x_Symbol] :=
  Sqrt[u]*ArcSinh[a+b*x]^n/b^2 -
  Dist[n/b,Int[ArcSinh[a+b*x]^(n-1),x]] -
  Dist[a/b,Int[ArcSinh[a+b*x]^n/Sqrt[u],x]] /;
FreeQ[{a,b},x] && ZeroQ[u-1-(a+b*x)^2] && RationalQ[n] && n>1


(* ::PageBreak:: *)
(**)


(* ::Title::Bold::Closed:: *)
(*\[Integral]u ArcSinh[c/(a+b x^n)]^m \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Derivation:  Algebraic simplification*)


(* ::Subsubsection:: *)
(*Basis: ArcSinh[z]=ArcCsch[1/z]*)


(* ::Subsubsection:: *)
(*Rule:*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]u ArcSinh[c/(a+b x^n)]^m \[DifferentialD]x  \[LongRightArrow]  \[Integral]u ArcCsch[a/c+(b x^n)/c]^m \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[u_.*ArcSinh[c_./(a_.+b_.*x_^n_.)]^m_.,x_Symbol] :=
  Int[u*ArcCsch[a/c+b*x^n/c]^m,x] /;
FreeQ[{a,b,c,n,m},x]


(* ::PageBreak:: *)
(**)


(* ::Title::Bold::Closed:: *)
(*\[Integral]f^(c ArcSinh[a+b x]) \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Rule: If  1-c^2 Log[f]^2!=0, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]f^(c ArcSinh[a+b x]) \[DifferentialD]x  \[LongRightArrow]  ((a+b x-c Sqrt[1+(a+b x)^2] Log[f])/(b (1-c^2 Log[f]^2))) f^(c ArcSinh[a+b x])*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[f_^(c_.*ArcSinh[a_.+b_.*x_]),x_Symbol] :=
  f^(c*ArcSinh[a+b*x])*(a+b*x-c*Sqrt[1+(a+b*x)^2]*Log[f])/(b*(1-c^2*Log[f]^2)) /;
FreeQ[{a,b,c,f},x] && NonzeroQ[1-c^2*Log[f]^2]


(* ::PageBreak:: *)
(**)


(* ::Title::Bold::Closed:: *)
(*\[Integral]ArcSinh[u]\[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Derivation: Integration by parts*)


(* ::Subsubsection:: *)
(*Rule: If u is free of inverse functions, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]ArcSinh[u]\[DifferentialD]x  \[LongRightArrow]  x ArcSinh[u]-\[Integral](x \!\( *)
(*\*SubscriptBox[\(\[PartialD]\), \(x\)]u\))/Sqrt[1+u^2] \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[ArcSinh[u_],x_Symbol] :=
  x*ArcSinh[u] -
  Int[Regularize[x*D[u,x]/Sqrt[1+u^2],x],x] /;
InverseFunctionFreeQ[u,x] && Not[FunctionOfExponentialOfLinear[u,x]]


(* ::PageBreak:: *)
(**)


(* ::Title::Bold::Closed:: *)
(*\[Integral]x^m E^(n ArcSinh[u]) \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Derivation: Algebraic simplification*)


(* ::Subsubsection:: *)
(*Basis: E^(n ArcSinh[z])=(z+Sqrt[1+z^2])^n*)


(* ::Subsubsection:: *)
(*Rule: If  n\[Element]\[DoubleStruckCapitalZ] \[And] u is a polynomial in x, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]E^(n ArcSinh[u]) \[DifferentialD]x  \[LongRightArrow]  \[Integral](u+Sqrt[1+u^2])^n \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[E^(n_.*ArcSinh[u_]), x_Symbol] :=
  Int[(u+Sqrt[1+u^2])^n,x] /;
IntegerQ[n] && PolynomialQ[u,x]


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Derivation: Algebraic simplification*)


(* ::Subsubsection:: *)
(*Basis: E^(n ArcSinh[z])=(z+Sqrt[1+z^2])^n*)


(* ::Subsubsection:: *)
(*Rule: If  n\[Element]\[DoubleStruckCapitalZ] \[And] u is a polynomial in x, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]x^m E^(n ArcSinh[u]) \[DifferentialD]x  \[LongRightArrow]  \[Integral]x^m (u+Sqrt[1+u^2])^n \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[x_^m_.*E^(n_.*ArcSinh[u_]), x_Symbol] :=
  Int[x^m*(u+Sqrt[1+u^2])^n,x] /;
RationalQ[m] && IntegerQ[n] && PolynomialQ[u,x]
