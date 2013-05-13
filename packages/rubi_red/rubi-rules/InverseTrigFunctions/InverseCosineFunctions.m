(* ::Package:: *)

(* ::Title::Bold::Closed:: *)
(*\[Integral]ArcCos[a+b x]^n \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Reference: G&R 2.814.1, CRC 442, A&S 4.4.59*)


(* ::Subsubsection:: *)
(*Derivation: Integration by parts*)


(* ::Subsubsection:: *)
(*Rule:*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]ArcCos[a+b x]\[DifferentialD]x  \[LongRightArrow]  (((a+b x) ArcCos[a+b x])/b)-Sqrt[1-(a+b x)^2]/b*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[ArcCos[a_.+b_.*x_],x_Symbol] :=
  (a+b*x)*ArcCos[a+b*x]/b - Sqrt[1-(a+b*x)^2]/b /;
FreeQ[{a,b},x]


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Reference: CRC 466*)


(* ::Subsubsection:: *)
(*Derivation: Iterated integration by parts*)


(* ::Subsubsection:: *)
(*Rule: If  n>1, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]ArcCos[a+b x]^n \[DifferentialD]x  \[LongRightArrow]  (((a+b x) ArcCos[a+b x]^n)/b)-                                                                *)
(*                                          (n Sqrt[1-(a+b x)^2] ArcCos[a+b x]^(n-1))/b-n(n-1)\[Integral]ArcCos[a+b x]^(n-2) \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[ArcCos[a_.+b_.*x_]^n_,x_Symbol] :=
  (a+b*x)*ArcCos[a+b*x]^n/b -
  n*Sqrt[1-(a+b*x)^2]*ArcCos[a+b*x]^(n-1)/b -
  Dist[n*(n-1),Int[ArcCos[a+b*x]^(n-2),x]] /;
FreeQ[{a,b},x] && RationalQ[n] && n>1


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Derivation: Integration by substitution*)


(* ::Subsubsection:: *)
(*Basis: 1/ArcCos[z]==-(Sin[ArcCos[z]] /ArcCos[z])Derivative[1][ArcCos][z]*)


(* ::Subsubsection:: *)
(*Rule:*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]1/ArcCos[a+b x] \[DifferentialD]x  \[LongRightArrow]  -(SinIntegral[ArcCos[a+b x]]/b)*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[1/ArcCos[a_.+b_.*x_],x_Symbol] :=
  -SinIntegral[ArcCos[a+b*x]]/b /;
FreeQ[{a,b},x]


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Derivation: Integration by substitution*)


(* ::Subsubsection:: *)
(*Basis: 1/ArcCos[z]^2=-(Sin[ArcCos[z]]/ArcCos[z]^2)Derivative[1][ArcCos][z]*)


(* ::Subsubsection:: *)
(*Rule:*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]1/ArcCos[a+b x]^2 \[DifferentialD]x  \[LongRightArrow]  (Sqrt[1-(a+b x)^2]/(b ArcCos[a+b x]))-CosIntegral[ArcCos[a+b x]]/b*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[1/ArcCos[a_.+b_.*x_]^2,x_Symbol] :=
  Sqrt[1-(a+b*x)^2]/(b*ArcCos[a+b*x]) - CosIntegral[ArcCos[a+b*x]]/b /;
FreeQ[{a,b},x]


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Derivation: Integration by substitution*)


(* ::Subsubsection:: *)
(*Basis: 1/Sqrt[ArcCos[z]]=-(Sin[ArcCos[z]] /Sqrt[ArcCos[z]])Derivative[1][ArcCos][z]*)


(* ::Subsubsection:: *)
(*Rule:*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]1/Sqrt[ArcCos[a+b x]] \[DifferentialD]x  \[LongRightArrow]  -(1/b) Sqrt[2 \[Pi]] FresnelS[Sqrt[2/\[Pi]] Sqrt[ArcCos[a+b x]]]*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[1/Sqrt[ArcCos[a_.+b_.*x_]],x_Symbol] :=
  -Sqrt[2*Pi]*FresnelS[Sqrt[2/Pi]*Sqrt[ArcCos[a+b*x]]]/b /;
FreeQ[{a,b},x]


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Derivation: Integration by parts*)


(* ::Subsubsection:: *)
(*Rule:*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]Sqrt[ArcCos[a+b x]]\[DifferentialD]x  \[LongRightArrow]  (((a+b x) Sqrt[ArcCos[a+b x]])/b)-1/b Sqrt[\[Pi]/2] FresnelC[Sqrt[2/\[Pi]] Sqrt[ArcCos[a+b x]]]*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[Sqrt[ArcCos[a_.+b_.*x_]],x_Symbol] :=
  (a+b*x)*Sqrt[ArcCos[a+b*x]]/b - Sqrt[Pi/2]*FresnelC[Sqrt[2/Pi]*Sqrt[ArcCos[a+b*x]]]/b /;
FreeQ[{a,b},x]


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Derivation: Inverted iterated integration by parts*)


(* ::Subsubsection:: *)
(*Rule: If  n<-1 \[And] n!=-2, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]ArcCos[a+b x]^n \[DifferentialD]x  \[LongRightArrow]  (((a+b x) ArcCos[a+b x]^(n+2))/(b (n+1) (n+2)))-                                                                                   *)
(*                                             (Sqrt[1-(a+b x)^2] ArcCos[a+b x]^(n+1))/(b (n+1))-1/((n+1) (n+2)) \[Integral]ArcCos[a+b x]^(n+2) \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[ArcCos[a_.+b_.*x_]^n_,x_Symbol] :=
  (a+b*x)*ArcCos[a+b*x]^(n+2)/(b*(n+1)*(n+2)) -
  Sqrt[1-(a+b*x)^2]*ArcCos[a+b*x]^(n+1)/(b*(n+1)) -
  Dist[1/((n+1)*(n+2)),Int[ArcCos[a+b*x]^(n+2),x]] /;
FreeQ[{a,b},x] && RationalQ[n] && n<-1 && n!=-2


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Rule: If  n\[NotElement]\[DoubleStruckCapitalQ] \[Or] -1<n<1, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]ArcCos[a+b x]^n \[DifferentialD]x  \[LongRightArrow]  (ArcCos[a+b x]^n/(2 b))(\[CapitalGamma][n+1,I ArcCos[a+b x]]/(I ArcCos[a+b x])^n+\[CapitalGamma][n+1,-I ArcCos[a+b x]]/(-I ArcCos[a+b x])^n)*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[ArcCos[a_.+b_.*x_]^n_,x_Symbol] :=
  ArcCos[a+b*x]^n/(2*b)*
    (Gamma[n+1,I*ArcCos[a+b*x]]/(I*ArcCos[a+b*x])^n + 
     Gamma[n+1,-I*ArcCos[a+b*x]]/(-I*ArcCos[a+b*x])^n) /;
FreeQ[{a,b,n},x] && (Not[RationalQ[n]] || -1<n<1)


(* ::PageBreak:: *)
(**)


(* ::Title::Bold::Closed:: *)
(*\[Integral]x^m ArcCos[a+b x]\[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Reference: G&R 2.832, CRC 454, A&S 4.4.67*)


(* ::Subsubsection:: *)
(*Derivation: Integration by parts*)


(* ::Subsubsection:: *)
(*Rule: If  m+1!=0, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]x^m ArcCos[a+b x]\[DifferentialD]x  \[LongRightArrow]  ((x^(m+1) ArcCos[a+b x])/(m+1))+b/(m+1) \[Integral]x^(m+1)/Sqrt[1-a^2-2 a b x-b^2 x^2] \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[x_^m_.*ArcCos[a_.+b_.*x_],x_Symbol] :=
  x^(m+1)*ArcCos[a+b*x]/(m+1) +
  Dist[b/(m+1),Int[x^(m+1)/Sqrt[1-a^2-2*a*b*x-b^2*x^2],x]] /;
FreeQ[{a,b,m},x] && NonzeroQ[m+1]


(* ::PageBreak:: *)
(**)


(* ::Title::Bold::Closed:: *)
(*\[Integral]x^m ArcCos[a x]^n \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Rule:*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]x/Sqrt[ArcCos[a x]] \[DifferentialD]x  \[LongRightArrow]  -(Sqrt[\[Pi]]/(2 a^2))  FresnelS[(2 Sqrt[ArcCos[a x]])/Sqrt[\[Pi]]]*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[x_/Sqrt[ArcCos[a_.*x_]],x_Symbol] :=
  -Sqrt[Pi]/(2*a^2)*FresnelS[2*Sqrt[ArcCos[a*x]]/Sqrt[Pi]] /;
FreeQ[a,x]


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Rule:*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]x/ArcCos[a x]^(3/2) \[DifferentialD]x  \[LongRightArrow]  ((2 x Sqrt[1-a^2 x^2])/(a Sqrt[ArcCos[a x]]))-(2 Sqrt[\[Pi]])/a^2  FresnelC[(2 Sqrt[ArcCos[a x]])/Sqrt[\[Pi]]]*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[x_/ArcCos[a_.*x_]^(3/2),x_Symbol] :=
  2*x*Sqrt[1-a^2*x^2]/(a*Sqrt[ArcCos[a*x]]) - 2*Sqrt[Pi]/a^2*FresnelC[2*Sqrt[ArcCos[a*x]]/Sqrt[Pi]] /;
FreeQ[a,x]


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Rule: If  n>1, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]x ArcCos[a x]^n \[DifferentialD]x  \[LongRightArrow]  -((n x Sqrt[1-a^2 x^2] ArcCos[a x]^(n-1))/(4 a))-                                                                     *)
(*                                                        ArcCos[a x]^n/(4 a^2)+(x^2 ArcCos[a x]^n)/2-(n (n-1))/4 \[Integral]x ArcCos[a x]^(n-2) \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[x_*ArcCos[a_.*x_]^n_,x_Symbol] :=
  -n*x*Sqrt[1-a^2*x^2]*ArcCos[a*x]^(n-1)/(4*a) -
  ArcCos[a*x]^n/(4*a^2) + x^2*ArcCos[a*x]^n/2 -
  Dist[n*(n-1)/4,Int[x*ArcCos[a*x]^(n-2),x]] /;
FreeQ[a,x] && RationalQ[n] && n>0


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Rule: If  n<-1 \[And] n!=-2, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]x ArcCos[a x]^n \[DifferentialD]x  \[LongRightArrow]  -((x Sqrt[1-a^2 x^2] ArcCos[a x]^(n+1))/(a(n+1)))-                                                                        *)
(*                                ArcCos[a x]^(n+2)/(a^2 (n+1) (n+2))+(2x^2 ArcCos[a x]^(n+2))/((n+1)(n+2))-4/((n+1) (n+2)) \[Integral]x ArcCos[a x]^(n+2) \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[x_*ArcCos[a_.*x_]^n_,x_Symbol] :=
  -x*Sqrt[1-a^2*x^2]*ArcCos[a*x]^(n+1)/(a*(n+1)) -
  ArcCos[a*x]^(n+2)/(a^2*(n+1)*(n+2)) +
  2*x^2*ArcCos[a*x]^(n+2)/((n+1)*(n+2)) -
  Dist[4/((n+1)*(n+2)),Int[x*ArcCos[a*x]^(n+2),x]] /;
FreeQ[a,x] && RationalQ[n] && n<-1 && n!=-2


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Rule: If  n>1, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]ArcCos[a x]^n/x^3 \[DifferentialD]x  \[LongRightArrow]  ((a n Sqrt[1-a^2 x^2] ArcCos[a x]^(n-1))/(2 x))-ArcCos[a x]^n/(2 x^2)+(a^2 n(n-1))/2 \[Integral]ArcCos[a x]^(n-2)/x \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[ArcCos[a_.*x_]^n_/x_^3,x_Symbol] :=
  a*n*Sqrt[1-a^2*x^2]*ArcCos[a*x]^(n-1)/(2*x) -
  ArcCos[a*x]^n/(2*x^2) +
  Dist[a^2*n*(n-1)/2,Int[ArcCos[a*x]^(n-2)/x,x]] /;
FreeQ[a,x] && RationalQ[n] && n>1


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Rule: If  m\[Element]\[DoubleStruckCapitalZ] \[And] m<-3 \[And] n>1, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]x^m ArcCos[a x]^n \[DifferentialD]x  \[LongRightArrow]  ((a n x^(m+2) Sqrt[1-a^2 x^2] ArcCos[a x]^(n-1))/((m+1)(m+2)))+                                                                           *)
(*                  (x^(m+1) ArcCos[a x]^n)/(m+1)-(a^2 (m+3)x^(m+3) ArcCos[a x]^n)/((m+1)(m+2))+                   *)
(*                                                      (a^2 (m+3)^2)/((m+1)(m+2)) \[Integral]x^(m+2) ArcCos[a x]^n \[DifferentialD]x+(a^2 n(n-1))/((m+1)(m+2)) \[Integral]x^(m+2) ArcCos[a x]^(n-2) \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[x_^m_*ArcCos[a_.*x_]^n_,x_Symbol] :=
  a*n*x^(m+2)*Sqrt[1-a^2*x^2]*ArcCos[a*x]^(n-1)/((m+1)*(m+2)) +
  x^(m+1)*ArcCos[a*x]^n/(m+1) -
  a^2*(m+3)*x^(m+3)*ArcCos[a*x]^n/((m+1)*(m+2)) +
  Dist[a^2*(m+3)^2/((m+1)*(m+2)),Int[x^(m+2)*ArcCos[a*x]^n,x]] +
  Dist[a^2*n*(n-1)/((m+1)*(m+2)),Int[x^(m+2)*ArcCos[a*x]^(n-2),x]] /;
FreeQ[a,x] && IntegerQ[m] && RationalQ[n] && m<-3 && n>1


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Rule: If  m\[Element]\[DoubleStruckCapitalZ] \[And] m>1 \[And] n<-1 \[And] n!=-2, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]x^m ArcCos[a x]^n \[DifferentialD]x  \[LongRightArrow]  -((x^m Sqrt[1-a^2 x^2] ArcCos[a x]^(n+1))/(a(n+1)))-                                                                                        *)
(*(m x^(m-1) ArcCos[a x]^(n+2))/(a^2 (n+1) (n+2))+((m+1)x^(m+1) ArcCos[a x]^(n+2))/((n+1) (n+2))-      *)
(*                                               (m+1)^2/((n+1) (n+2)) \[Integral]x^m ArcCos[a x]^(n+2) \[DifferentialD]x+(m (m-1))/(a^2 (n+1) (n+2)) \[Integral]x^(m-2) ArcCos[a x]^(n+2) \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[x_^m_*ArcCos[a_.*x_]^n_,x_Symbol] :=
  -x^m*Sqrt[1-a^2*x^2]*ArcCos[a*x]^(n+1)/(a*(n+1)) -
  m*x^(m-1)*ArcCos[a*x]^(n+2)/(a^2*(n+1)*(n+2)) +
  (m+1)*x^(m+1)*ArcCos[a*x]^(n+2)/((n+1)*(n+2)) -
  Dist[(m+1)^2/((n+1)*(n+2)),Int[x^m*ArcCos[a*x]^(n+2),x]] +
  Dist[m*(m-1)/(a^2*(n+1)*(n+2)),Int[x^(m-2)*ArcCos[a*x]^(n+2),x]] /;
FreeQ[a,x] && IntegerQ[m] && RationalQ[n] && m>1 && n<-1 && n!=-2


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Derivation: Integration by substitution*)


(* ::Subsubsection:: *)
(*Basis: ArcCos[a x^p]^n/x=-(1/p) ArcCos[a x^p]^n Tan[ArcCos[a x^p]] \!\( *)
(*\*SubscriptBox[\(\[PartialD]\), \(x\)]\(ArcCos[a\ *)
(*\*SuperscriptBox[\(x\), \(p\)]]\)\)*)


(* ::Subsubsection:: *)
(*Rule: If  n\[Element]\[DoubleStruckCapitalZ] \[And] n>0, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]ArcCos[a x^p]^n/x \[DifferentialD]x  \[LongRightArrow]  -(1/p) Subst[\[Integral]x^n Tan[x]\[DifferentialD]x,x,ArcCos[a x^p]]*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[ArcCos[a_.*x_^p_.]^n_./x_,x_Symbol] :=
  -Dist[1/p,Subst[Int[x^n*Tan[x],x],x,ArcCos[a*x^p]]] /;
FreeQ[{a,p},x] && IntegerQ[n] && n>0


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Derivation: Integration by parts and substitution*)


(* ::Subsubsection:: *)
(*Basis: If  m\[Element]\[DoubleStruckCapitalZ], (x^(m+1) ArcCos[a x]^(n-1))/Sqrt[1-a^2 x^2]=-(1/a^(m+2)) ArcCos[a x]^(n-1) Cos[ArcCos[a x]]^(m+1) \!\( *)
(*\*SubscriptBox[\(\[PartialD]\), \(x\)]\(ArcCos[a\ x]\)\)*)


(* ::Subsubsection:: *)
(*Rule: If  m\[Element]\[DoubleStruckCapitalZ] \[And] m!=-1, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]x^m ArcCos[a x]^n \[DifferentialD]x  \[LongRightArrow]  ((x^(m+1) ArcCos[a x]^n)/(m+1))-n/(a^(m+1) (m+1)) Subst[\[Integral]x^(n-1) Cos[x]^(m+1) \[DifferentialD]x,x,ArcCos[a x]]*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[x_^m_.*ArcCos[a_.*x_]^n_,x_Symbol] :=
  x^(m+1)*ArcCos[a*x]^n/(m+1) -
  Dist[n/(a^(m+1)*(m+1)),Subst[Int[x^(n-1)*Cos[x]^(m+1),x],x,ArcCos[a*x]]] /;
FreeQ[{a,n},x] && IntegerQ[m] && m!=-1


(* ::PageBreak:: *)
(**)


(* ::Title::Bold::Closed:: *)
(*\[Integral](a+b ArcCos[c+d x])^n \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Derivation: Integration by substitution*)


(* ::Subsubsection:: *)
(*Basis: (a+b ArcCos[c+d x])^n=-(1/d) (a+b ArcCos[c+d x])^n Sin[ArcCos[c+d x]]\!\( *)
(*\*SubscriptBox[\(\[PartialD]\), \(x\)]\(ArcCos[c + d\ x]\)\)*)


(* ::Subsubsection:: *)
(*Rule: If  n\[NotElement]\[DoubleStruckCapitalZ], then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral](a+b ArcCos[c+d x])^n \[DifferentialD]x  \[LongRightArrow]  -(1/d) Subst[\[Integral](a+b x)^n Sin[x]\[DifferentialD]x,x,ArcCos[c+d x]]*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[(a_+b_.*ArcCos[c_.+d_.*x_])^n_,x_Symbol] :=
  -Dist[1/d,Subst[Int[(a+b*x)^n*Sin[x],x],x,ArcCos[c+d*x]]] /;
FreeQ[{a,b,c,d},x] && Not[IntegerQ[n]]


(* ::PageBreak:: *)
(**)


(* ::Title::Bold::Closed:: *)
(*\[Integral]x^m (a+b ArcCos[c+d x])^n \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Derivation: Integration by substitution*)


(* ::Subsubsection:: *)
(*Basis: If m\[Element]\[DoubleStruckCapitalZ], x^m (a+b ArcCos[c+d x])^n=-(1/d^(m+1)) (a+b ArcCos[c+d x])^n (Cos[ArcCos[c+d x]]-c)^m Sin[ArcCos[c+d x]]\!\( *)
(*\*SubscriptBox[\(\[PartialD]\), \(x\)]\(ArcCos[c + d\ x]\)\)*)


(* ::Subsubsection:: *)
(*Rule: If  m\[Element]\[DoubleStruckCapitalZ] \[And] n\[NotElement]\[DoubleStruckCapitalZ] \[And] m>0, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]x^m (a+b ArcCos[c+d x])^n \[DifferentialD]x  \[LongRightArrow]  -(1/d^(m+1)) Subst[\[Integral](a+b x)^n (Cos[x]-c)^m Sin[x]\[DifferentialD]x,x,ArcCos[c+d x]]*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[x_^m_.*(a_+b_.*ArcCos[c_.+d_.*x_])^n_,x_Symbol] :=
  -Dist[1/d^(m+1),Subst[Int[(a+b*x)^n*(Cos[x]-c)^m*Sin[x],x],x,ArcCos[c+d*x]]] /;
FreeQ[{a,b,c,d},x] && IntegerQ[m] && Not[IntegerQ[n]] && m>0


(* ::PageBreak:: *)
(**)


(* ::Title::Bold::Closed:: *)
(*\[Integral](x ArcCos[a+b x]^n)/Sqrt[1-(a+b x)^2] \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Derivation: Integration by parts*)


(* ::Subsubsection:: *)
(*Rule: If  n>1, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral](x ArcCos[a+b x]^n)/Sqrt[1-(a+b x)^2] \[DifferentialD]x  \[LongRightArrow]                                                                                                                                 *)
(*               -((Sqrt[1-(a+b x)^2] ArcCos[a+b x]^n)/b^2)-n/b \[Integral]ArcCos[a+b x]^(n-1) \[DifferentialD]x-a/b \[Integral]ArcCos[a+b x]^n/Sqrt[1-(a+b x)^2] \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[x_*ArcCos[a_.+b_.*x_]^n_/Sqrt[u_],x_Symbol] :=
  -Sqrt[u]*ArcCos[a+b*x]^n/b^2 -
  Dist[n/b,Int[ArcCos[a+b*x]^(n-1),x]] -
  Dist[a/b,Int[ArcCos[a+b*x]^n/Sqrt[u],x]] /;
FreeQ[{a,b},x] && ZeroQ[u-1+(a+b*x)^2] && RationalQ[n] && n>1


(* ::PageBreak:: *)
(**)


(* ::Title::Bold::Closed:: *)
(*\[Integral]u ArcCos[c/(a+b x^n)]^m \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Derivation:  Algebraic simplification*)


(* ::Subsubsection:: *)
(*Basis: ArcCos[z]=ArcSec[1/z]*)


(* ::Subsubsection:: *)
(*Rule:*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]u ArcCos[c/(a+b x^n)]^m \[DifferentialD]x  \[LongRightArrow]  \[Integral]u ArcSec[a/c+(b x^n)/c]^m \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[u_.*ArcCos[c_./(a_.+b_.*x_^n_.)]^m_.,x_Symbol] :=
  Int[u*ArcSec[a/c+b*x^n/c]^m,x] /;
FreeQ[{a,b,c,n,m},x]


(* ::PageBreak:: *)
(**)


(* ::Title::Bold::Closed:: *)
(*\[Integral]f^(c ArcCos[a+b x]) \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Rule: If  1+c^2 Log[f]^2!=0, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]f^(c ArcCos[a+b x]) \[DifferentialD]x  \[LongRightArrow]  ((a+b x-c Sqrt[1-(a+b x)^2] Log[f])/(b (1+c^2 Log[f]^2))) f^(c ArcCos[a+b x])*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[f_^(c_.*ArcCos[a_.+b_.*x_]),x_Symbol] :=
  f^(c*ArcCos[a+b*x])*(a+b*x-c*Sqrt[1-(a+b*x)^2]*Log[f])/(b*(1+c^2*Log[f]^2)) /;
FreeQ[{a,b,c,f},x] && NonzeroQ[1+c^2*Log[f]^2]


(* ::PageBreak:: *)
(**)


(* ::Title::Bold::Closed:: *)
(*\[Integral]v ArcCos[u]\[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Derivation: Integration by parts*)


(* ::Subsubsection:: *)
(*Rule: If u is free of inverse functions, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]ArcCos[u]\[DifferentialD]x  \[LongRightArrow]  x ArcCos[u]+\[Integral](x \!\( *)
(*\*SubscriptBox[\(\[PartialD]\), \(x\)]u\))/Sqrt[1-u^2] \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[ArcCos[u_],x_Symbol] :=
  x*ArcCos[u] +
  Int[Regularize[x*D[u,x]/Sqrt[1-u^2],x],x] /;
InverseFunctionFreeQ[u,x] && Not[FunctionOfExponentialOfLinear[u,x]]


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Derivation: Integration by parts*)


(* ::Subsubsection:: *)
(*Rule: If  m+1!=0\[And] u is free of inverse functions, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]x^m ArcCos[u]\[DifferentialD]x  \[LongRightArrow]  ((x^(m+1) ArcCos[u])/(m+1))+1/(m+1) \[Integral](x^(m+1) \!\( *)
(*\*SubscriptBox[\(\[PartialD]\), \(x\)]u\))/Sqrt[1-u^2] \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[x_^m_.*ArcCos[u_],x_Symbol] :=
  x^(m+1)*ArcCos[u]/(m+1) +
  Dist[1/(m+1),Int[Regularize[x^(m+1)*D[u,x]/Sqrt[1-u^2],x],x]] /;
FreeQ[m,x] && NonzeroQ[m+1] && InverseFunctionFreeQ[u,x] && 
	Not[FunctionOfQ[x^(m+1),u,x]] && 
	Not[FunctionOfExponentialOfLinear[u,x]]
