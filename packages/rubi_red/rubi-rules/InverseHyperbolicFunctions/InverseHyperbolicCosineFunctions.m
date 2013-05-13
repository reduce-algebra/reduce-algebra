(* ::Package:: *)

(* ::Title::Bold::Closed:: *)
(*\[Integral]ArcCosh[a+b x]^n \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Reference: CRC 582', A&S 4.6.44*)


(* ::Subsubsection:: *)
(*Derivation: Integration by parts*)


(* ::Subsubsection:: *)
(*Rule:*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]ArcCosh[a+b x]\[DifferentialD]x  \[LongRightArrow]  (((a+b x) ArcCosh[a+b x])/b)-(Sqrt[-1+a+b x] Sqrt[1+a+b x])/b*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[ArcCosh[a_.+b_.*x_],x_Symbol] :=
  (a+b*x)*ArcCosh[a+b*x]/b - Sqrt[-1+a+b*x]*Sqrt[1+a+b*x]/b /;
FreeQ[{a,b},x]


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Derivation: Iterated integration by parts*)


(* ::Subsubsection:: *)
(*Rule: If  n>1, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]ArcCosh[a+b x]^n \[DifferentialD]x  \[LongRightArrow]  (((a+b x) ArcCosh[a+b x]^n)/b)-                                                                *)
(*                                (n Sqrt[-1+a+b x] Sqrt[1+a+b x] ArcCosh[a+b x]^(n-1))/b+n(n-1)\[Integral]ArcCosh[a+b x]^(n-2) \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[ArcCosh[a_.+b_.*x_]^n_,x_Symbol] :=
  (a+b*x)*ArcCosh[a+b*x]^n/b -
  n*Sqrt[-1+a+b*x]*Sqrt[1+a+b*x]*ArcCosh[a+b*x]^(n-1)/b +
  Dist[n*(n-1),Int[ArcCosh[a+b*x]^(n-2),x]] /;
FreeQ[{a,b},x] && RationalQ[n] && n>1


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Derivation: Integration by substitution*)


(* ::Subsubsection:: *)
(*Basis: 1/ArcCosh[z]=Sinh[ArcCosh[z]]/ArcCosh[z] Derivative[1][ArcCosh][z]*)


(* ::Subsubsection:: *)
(*Rule:*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]1/ArcCosh[a+b x] \[DifferentialD]x  \[LongRightArrow]  (SinhIntegral[ArcCosh[a+b x]]/b)*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[1/ArcCosh[a_.+b_.*x_],x_Symbol] :=
  SinhIntegral[ArcCosh[a+b*x]]/b /;
FreeQ[{a,b},x]


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Derivation: Integration by substitution*)


(* ::Subsubsection:: *)
(*Basis: 1/ArcCosh[z]^2=Sinh[ArcCosh[z]]/ArcCosh[z]^2 Derivative[1][ArcCosh][z]*)


(* ::Subsubsection:: *)
(*Rule:*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]1/ArcCosh[a+b x]^2 \[DifferentialD]x  \[LongRightArrow]  -((Sqrt[-1+a+b x] Sqrt[1+a+b x])/(b ArcCosh[a+b x]))+CoshIntegral[ArcCosh[a+b x]]/b*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[1/ArcCosh[a_.+b_.*x_]^2,x_Symbol] :=
  -Sqrt[-1+a+b*x]*Sqrt[1+a+b*x]/(b*ArcCosh[a+b*x]) + CoshIntegral[ArcCosh[a+b*x]]/b /;
FreeQ[{a,b},x]


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Derivation: Integration by substitution*)


(* ::Subsubsection:: *)
(*Basis: 1/Sqrt[ArcCosh[z]]=Sinh[ArcCosh[z]]/Sqrt[ArcCosh[z]] Derivative[1][ArcCosh][z]*)


(* ::Subsubsection:: *)
(*Rule:*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]1/Sqrt[ArcCosh[a+b x]] \[DifferentialD]x  \[LongRightArrow]  -((Sqrt[\[Pi]] Erf[Sqrt[ArcCosh[a+b x]]])/(2 b))+(Sqrt[\[Pi]] Erfi[Sqrt[ArcCosh[a+b x]]])/(2 b)*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[1/Sqrt[ArcCosh[a_.+b_.*x_]],x_Symbol] :=
  -Sqrt[Pi]*Erf[Sqrt[ArcCosh[a+b*x]]]/(2*b) +
  Sqrt[Pi]*Erfi[Sqrt[ArcCosh[a+b*x]]]/(2*b) /;
FreeQ[{a,b},x]


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Derivation: Integration by parts*)


(* ::Subsubsection:: *)
(*Rule:*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]Sqrt[ArcCosh[a+b x]]\[DifferentialD]x  \[LongRightArrow]  (((a+b x) Sqrt[ArcCosh[a+b x]])/b)-                                                                         *)
(*                                                                   (Sqrt[\[Pi]] Erf[Sqrt[ArcCosh[a+b x]]])/(4 b)-(Sqrt[\[Pi]] Erfi[Sqrt[ArcCosh[a+b x]]])/(4 b)*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[Sqrt[ArcCosh[a_.+b_.*x_]],x_Symbol] :=
  (a+b*x)*Sqrt[ArcCosh[a+b*x]]/b -
  Sqrt[Pi]*Erf[Sqrt[ArcCosh[a+b*x]]]/(4*b) -
  Sqrt[Pi]*Erfi[Sqrt[ArcCosh[a+b*x]]]/(4*b) /;
FreeQ[{a,b},x]


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Derivation: Inverted iterated integration by parts*)


(* ::Subsubsection:: *)
(*Rule: If  n<-1 \[And] n!=-2, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]ArcCosh[a+b x]^n \[DifferentialD]x  \[LongRightArrow]  -(((a+b x) ArcCosh[a+b x]^(n+2))/(b (n+1) (n+2)))+                                                                                   *)
(*                         (Sqrt[-1+a+b x] Sqrt[1+a+b x] ArcCosh[a+b x]^(n+1))/(b (n+1))+1/((n+1) (n+2)) \[Integral]ArcCosh[a+b x]^(n+2) \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[ArcCosh[a_.+b_.*x_]^n_,x_Symbol] :=
  -(a+b*x)*ArcCosh[a+b*x]^(n+2)/(b*(n+1)*(n+2)) +
  Sqrt[-1+a+b*x]*Sqrt[1+a+b*x]*ArcCosh[a+b*x]^(n+1)/(b*(n+1)) +
  Dist[1/((n+1)*(n+2)),Int[ArcCosh[a+b*x]^(n+2),x]] /;
FreeQ[{a,b},x] && RationalQ[n] && n<-1 && n!=-2


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Rule: If  n\[NotElement]\[DoubleStruckCapitalQ] \[Or] -1<n<1, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]ArcCosh[a+b x]^n \[DifferentialD]x  \[LongRightArrow]                                                                                                                                             *)
(*                            ((ArcCosh[a+b x]^n Gamma[n+1,-ArcCosh[a+b x]])/(2 b (-ArcCosh[a+b x])^n))+Gamma[n+1,ArcCosh[a+b x]]/(2 b)*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[ArcCosh[a_.+b_.*x_]^n_,x_Symbol] :=
  ArcCosh[a+b*x]^n*Gamma[n+1,-ArcCosh[a+b*x]]/(2*b*(-ArcCosh[a+b*x])^n) +
  Gamma[n+1,ArcCosh[a+b*x]]/(2*b) /;
FreeQ[{a,b,n},x] && (Not[RationalQ[n]] || -1<n<1)


(* ::PageBreak:: *)
(**)


(* ::Title::Bold::Closed:: *)
(*\[Integral]x^m ArcCosh[a+b x]\[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Reference: CRC 584, A&S 4.6.52*)


(* ::Subsubsection:: *)
(*Derivation: Integration by parts*)


(* ::Subsubsection:: *)
(*Rule: If  m+1!=0, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]x^m ArcCosh[a+b x]\[DifferentialD]x  \[LongRightArrow]  ((x^(m+1) ArcCosh[a+b x])/(m+1))-b/(m+1) \[Integral]x^(m+1)/(Sqrt[-1+a+b x] Sqrt[1+a+b x]) \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[x_^m_.*ArcCosh[a_.+b_.*x_],x_Symbol] :=
  x^(m+1)*ArcCosh[a+b*x]/(m+1) - 
  Dist[b/(m+1),Int[x^(m+1)/(Sqrt[-1+a+b*x]*Sqrt[1+a+b*x]),x]] /;
FreeQ[{a,b,m},x] && NonzeroQ[m+1]


(* ::PageBreak:: *)
(**)


(* ::Title::Bold::Closed:: *)
(*\[Integral]x^m ArcCosh[a x]^n \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Rule:*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]x/Sqrt[ArcCosh[a x]] \[DifferentialD]x  \[LongRightArrow]  -(1/(4 a^2)) Sqrt[\[Pi]/2] Erf[Sqrt[2] Sqrt[ArcCosh[a x]]]+1/(4 a^2) Sqrt[\[Pi]/2] Erfi[Sqrt[2] Sqrt[ArcCosh[a x]]]*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[x_/Sqrt[ArcCosh[a_.*x_]],x_Symbol] :=
  -Sqrt[Pi/2]*Erf[Sqrt[2]*Sqrt[ArcCosh[a*x]]]/(4*a^2) + 
  Sqrt[Pi/2]*Erfi[Sqrt[2]*Sqrt[ArcCosh[a*x]]]/(4*a^2) /;
FreeQ[a,x]


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Rule:*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]x/ArcCosh[a x]^(3/2) \[DifferentialD]x  \[LongRightArrow]                                                                                                                                                     *)
(*    -((2 x Sqrt[-1+a x] Sqrt[1+a x])/(a Sqrt[ArcCosh[a x]]))+1/a^2 Sqrt[\[Pi]/2] Erf[Sqrt[2] Sqrt[ArcCosh[a x]]]+1/a^2 Sqrt[\[Pi]/2] Erfi[Sqrt[2] Sqrt[ArcCosh[a x]]]*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[x_/ArcCosh[a_.*x_]^(3/2),x_Symbol] :=
  -2*x*Sqrt[-1+a*x]*Sqrt[1+a*x]/(a*Sqrt[ArcCosh[a*x]]) +
  Sqrt[Pi/2]*Erf[Sqrt[2]*Sqrt[ArcCosh[a*x]]]/a^2 +
  Sqrt[Pi/2]*Erfi[Sqrt[2]*Sqrt[ArcCosh[a*x]]]/a^2 /;
FreeQ[a,x]


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Rule: If  n>1, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]x ArcCosh[a x]^n \[DifferentialD]x  \[LongRightArrow]  -((n x Sqrt[-1+a x] Sqrt[1+a x] ArcCosh[a x]^(n-1))/(4 a))-                                                                     *)
(*                                                        ArcCosh[a x]^n/(4 a^2)+(x^2 ArcCosh[a x]^n)/2+(n (n-1))/4 \[Integral]x ArcCosh[a x]^(n-2) \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[x_*ArcCosh[a_.*x_]^n_,x_Symbol] :=
  -n*x*Sqrt[-1+a*x]*Sqrt[1+a*x]*ArcCosh[a*x]^(n-1)/(4*a) -
  ArcCosh[a*x]^n/(4*a^2) + x^2*ArcCosh[a*x]^n/2 +
  Dist[n*(n-1)/4,Int[x*ArcCosh[a*x]^(n-2),x]] /;
FreeQ[a,x] && RationalQ[n] && n>0


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Rule: If  n<-1 \[And] n!=-2, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]x ArcCosh[a x]^n \[DifferentialD]x  \[LongRightArrow]  ((x Sqrt[-1+a x] Sqrt[1+a x] ArcCosh[a x]^(n+1))/(a(n+1)))+                                                                        *)
(*                                ArcCosh[a x]^(n+2)/(a^2 (n+1) (n+2))-(2x^2 ArcCosh[a x]^(n+2))/((n+1)(n+2))+4/((n+1) (n+2)) \[Integral]x ArcCosh[a x]^(n+2) \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[x_*ArcCosh[a_.*x_]^n_,x_Symbol] :=
  x*Sqrt[-1+a*x]*Sqrt[1+a*x]*ArcCosh[a*x]^(n+1)/(a*(n+1)) +
  ArcCosh[a*x]^(n+2)/(a^2*(n+1)*(n+2)) -
  2*x^2*ArcCosh[a*x]^(n+2)/((n+1)*(n+2)) +
  Dist[4/((n+1)*(n+2)),Int[x*ArcCosh[a*x]^(n+2),x]] /;
FreeQ[a,x] && RationalQ[n] && n<-1 && n!=-2


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Rule: If  n>1, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]ArcCosh[a x]^n/x^3 \[DifferentialD]x  \[LongRightArrow]                                                                                                                                                            *)
(*                                ((a n Sqrt[-1+a x] Sqrt[1+a x] ArcCosh[a x]^(n-1))/(2 x))-ArcCosh[a x]^n/(2 x^2)-(a^2 n(n-1))/2 \[Integral]ArcCosh[a x]^(n-2)/x \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[ArcCosh[a_.*x_]^n_/x_^3,x_Symbol] :=
  a*n*Sqrt[-1+a*x]*Sqrt[1+a*x]*ArcCosh[a*x]^(n-1)/(2*x) -
  ArcCosh[a*x]^n/(2*x^2) -
  Dist[a^2*n*(n-1)/2,Int[ArcCosh[a*x]^(n-2)/x,x]] /;
FreeQ[a,x] && RationalQ[n] && n>1


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Rule: If  m\[Element]\[DoubleStruckCapitalZ] \[And] m<-3 \[And] n>1, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]x^m ArcCosh[a x]^n \[DifferentialD]x  \[LongRightArrow]  ((a n x^(m+2) Sqrt[-1+a x] Sqrt[1+a x] ArcCosh[a x]^(n-1))/((m+1)(m+2)))+                                                                           *)
(*                  (x^(m+1) ArcCosh[a x]^n)/(m+1)-(a^2 (m+3)x^(m+3) ArcCosh[a x]^n)/((m+1)(m+2))+                   *)
(*                                                      (a^2 (m+3)^2)/((m+1)(m+2)) \[Integral]x^(m+2) ArcCosh[a x]^n \[DifferentialD]x-(a^2 n(n-1))/((m+1)(m+2)) \[Integral]x^(m+2) ArcCosh[a x]^(n-2) \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[x_^m_*ArcCosh[a_.*x_]^n_,x_Symbol] :=
  a*n*x^(m+2)*Sqrt[-1+a*x]*Sqrt[1+a*x]*ArcCosh[a*x]^(n-1)/((m+1)*(m+2)) +
  x^(m+1)*ArcCosh[a*x]^n/(m+1) -
  a^2*(m+3)*x^(m+3)*ArcCosh[a*x]^n/((m+1)*(m+2)) +
  Dist[a^2*(m+3)^2/((m+1)*(m+2)),Int[x^(m+2)*ArcCosh[a*x]^n,x]] -
  Dist[a^2*n*(n-1)/((m+1)*(m+2)),Int[x^(m+2)*ArcCosh[a*x]^(n-2),x]] /;
FreeQ[a,x] && IntegerQ[m] && RationalQ[n] && m<-3 && n>1


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Rule: If  m\[Element]\[DoubleStruckCapitalZ] \[And] m>1 \[And] n<-1 \[And] n!=-2, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]x^m ArcCosh[a x]^n \[DifferentialD]x  \[LongRightArrow]  ((x^m Sqrt[-1+a x] Sqrt[1+a x] ArcCosh[a x]^(n+1))/(a(n+1)))+                                                                                        *)
(*(m x^(m-1) ArcCosh[a x]^(n+2))/(a^2 (n+1) (n+2))-((m+1)x^(m+1) ArcCosh[a x]^(n+2))/((n+1) (n+2))+      *)
(*                                               (m+1)^2/((n+1) (n+2)) \[Integral]x^m ArcCosh[a x]^(n+2) \[DifferentialD]x-(m (m-1))/(a^2 (n+1) (n+2)) \[Integral]x^(m-2) ArcCosh[a x]^(n+2) \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[x_^m_*ArcCosh[a_.*x_]^n_,x_Symbol] :=
  x^m*Sqrt[-1+a*x]*Sqrt[1+a*x]*ArcCosh[a*x]^(n+1)/(a*(n+1)) +
  m*x^(m-1)*ArcCosh[a*x]^(n+2)/(a^2*(n+1)*(n+2)) -
  (m+1)*x^(m+1)*ArcCosh[a*x]^(n+2)/((n+1)*(n+2)) +
  Dist[(m+1)^2/((n+1)*(n+2)),Int[x^m*ArcCosh[a*x]^(n+2),x]] -
  Dist[m*(m-1)/(a^2*(n+1)*(n+2)),Int[x^(m-2)*ArcCosh[a*x]^(n+2),x]] /;
FreeQ[a,x] && IntegerQ[m] && RationalQ[n] && m>1 && n<-1 && n!=-2


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Derivation: Integration by substitution*)


(* ::Subsubsection:: *)
(*Basis: ArcCosh[a x^p]^n/x=1/p ArcCosh[a x^p]^n Tanh[ArcCosh[a x^p]] \!\( *)
(*\*SubscriptBox[\(\[PartialD]\), \(x\)]\(ArcCosh[a\ *)
(*\*SuperscriptBox[\(x\), \(p\)]]\)\)*)


(* ::Subsubsection:: *)
(*Rule: If  n\[Element]\[DoubleStruckCapitalZ] \[And] n>0, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]ArcCosh[a x^p]^n/x \[DifferentialD]x  \[LongRightArrow]  (1/p) Subst[\[Integral]x^n Tanh[x]\[DifferentialD]x,x,ArcCosh[a x^p]]*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[ArcCosh[a_.*x_^p_.]^n_./x_,x_Symbol] :=
  Dist[1/p,Subst[Int[x^n*Tanh[x],x],x,ArcCosh[a*x^p]]] /;
FreeQ[{a,p},x] && IntegerQ[n] && n>0


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Derivation: Integration by parts and substitution*)


(* ::Subsubsection:: *)
(*Basis: If  m\[Element]\[DoubleStruckCapitalZ], (x^(m+1) ArcCosh[a x]^(n-1))/(Sqrt[-1+a x] Sqrt[1+a x])=1/a^(m+2) ArcCosh[a x]^(n-1) Cosh[ArcCosh[a x]]^(m+1) \!\( *)
(*\*SubscriptBox[\(\[PartialD]\), \(x\)]\(ArcCosh[a\ x]\)\)*)


(* ::Subsubsection:: *)
(*Rule: If  m\[Element]\[DoubleStruckCapitalZ] \[And] m!=-1, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]x^m ArcCosh[a x]^n \[DifferentialD]x  \[LongRightArrow]  ((x^(m+1) ArcCosh[a x]^n)/(m+1))-n/(a^(m+1) (m+1)) Subst[\[Integral]x^(n-1) Cosh[x]^(m+1) \[DifferentialD]x,x,ArcCosh[a x]]*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[x_^m_.*ArcCosh[a_.*x_]^n_,x_Symbol] :=
  x^(m+1)*ArcCosh[a*x]^n/(m+1) -
  Dist[n/(a^(m+1)*(m+1)),Subst[Int[x^(n-1)*Cosh[x]^(m+1),x],x,ArcCosh[a*x]]] /;
FreeQ[{a,n},x] && IntegerQ[m] && m!=-1


(* ::PageBreak:: *)
(**)


(* ::Title::Bold::Closed:: *)
(*\[Integral](a+b ArcCosh[c+d x])^n \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Derivation: Integration by substitution*)


(* ::Subsubsection:: *)
(*Basis: (a+b ArcCosh[c+d x])^n=1/d (a+b ArcCosh[c+d x])^n Sinh[ArcCosh[c+d x]]\!\( *)
(*\*SubscriptBox[\(\[PartialD]\), \(x\)]\(ArcCosh[c + d\ x]\)\)*)


(* ::Subsubsection:: *)
(*Rule: If  n\[NotElement]\[DoubleStruckCapitalZ], then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral](a+b ArcCosh[c+d x])^n \[DifferentialD]x  \[LongRightArrow]  (1/d) Subst[\[Integral](a+b x)^n Sinh[x]\[DifferentialD]x,x,ArcCosh[c+d x]]*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[(a_+b_.*ArcCosh[c_.+d_.*x_])^n_,x_Symbol] :=
  Dist[1/d,Subst[Int[(a+b*x)^n*Sinh[x],x],x,ArcCosh[c+d*x]]] /;
FreeQ[{a,b,c,d},x] && Not[IntegerQ[n]]


(* ::PageBreak:: *)
(**)


(* ::Title::Bold::Closed:: *)
(*\[Integral]x^m (a+b ArcCosh[c+d x])^n \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Derivation: Integration by substitution*)


(* ::Subsubsection:: *)
(*Basis: If m\[Element]\[DoubleStruckCapitalZ],  x^m (a+b ArcCosh[c+d x])^n=1/d^(m+1) (a+b ArcCosh[c+d x])^n (Cosh[ArcCosh[c+d x]]-c)^m Sinh[ArcCosh[c+d x]]\!\( *)
(*\*SubscriptBox[\(\[PartialD]\), \(x\)]\(ArcCosh[c + d\ x]\)\)*)


(* ::Subsubsection:: *)
(*Rule: If  m\[Element]\[DoubleStruckCapitalZ] \[And] n\[NotElement]\[DoubleStruckCapitalZ] \[And] m>0, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]x^m (a+b ArcCosh[c+d x])^n \[DifferentialD]x  \[LongRightArrow]  (1/d^(m+1)) Subst[\[Integral](a+b x)^n (Cosh[x]-c)^m Sinh[x]\[DifferentialD]x,x,ArcCosh[c+d x]]*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[x_^m_.*(a_+b_.*ArcCosh[c_.+d_.*x_])^n_,x_Symbol] :=
  Dist[1/d^(m+1),Subst[Int[(a+b*x)^n*(Cosh[x]-c)^m*Sinh[x],x],x,ArcCosh[c+d*x]]] /;
FreeQ[{a,b,c,d},x] && IntegerQ[m] && Not[IntegerQ[n]] && m>0


(* ::PageBreak:: *)
(**)


(* ::Title::Bold::Closed:: *)
(*\[Integral]u ArcCosh[c/(a+b x^n)]^m \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Derivation:  Algebraic simplification*)


(* ::Subsubsection:: *)
(*Basis: ArcCosh[z]=ArcSech[1/z]*)


(* ::Subsubsection:: *)
(*Rule:*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]u ArcCosh[c/(a+b x^n)]^m \[DifferentialD]x  \[LongRightArrow]  \[Integral]u ArcSech[a/c+(b x^n)/c]^m \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[u_.*ArcCosh[c_./(a_.+b_.*x_^n_.)]^m_.,x_Symbol] :=
  Int[u*ArcSech[a/c+b*x^n/c]^m,x] /;
FreeQ[{a,b,c,n,m},x]


(* ::PageBreak:: *)
(**)


(* ::Title::Bold::Closed:: *)
(*\[Integral]f^(c ArcCosh[a+b x]) \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Rule: If  1-c^2 Log[f]^2!=0, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]f^(c ArcCosh[a+b x]) \[DifferentialD]x  \[LongRightArrow]  ((a+b x-c Sqrt[((-1+a+b x)/(1+a+b x))] (1+a+b x) Log[f] )/(b (1-c^2 Log[f]^2))) f^(c ArcCosh[a+b x])*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[f_^(c_.*ArcCosh[a_.+b_.*x_]),x_Symbol] :=
  (a+b*x-c*Sqrt[(-1+a+b*x)/(1+a+b*x)]*(1+a+b*x)*Log[f])/(b*(1-c^2*Log[f]^2))*
    f^(c*ArcCosh[a+b*x]) /;
FreeQ[{a,b,c,f},x] && NonzeroQ[1-c^2*Log[f]^2]


(* ::PageBreak:: *)
(**)


(* ::Title::Bold::Closed:: *)
(*\[Integral]ArcCosh[u]\[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Derivation: Integration by parts*)


(* ::Subsubsection:: *)
(*Rule: If u is free of inverse functions, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]ArcCosh[u]\[DifferentialD]x  \[LongRightArrow]  x ArcCosh[u]-\[Integral](x \!\( *)
(*\*SubscriptBox[\(\[PartialD]\), \(x\)]u\))/(Sqrt[-1+u] Sqrt[1+u]) \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[ArcCosh[u_],x_Symbol] :=
  x*ArcCosh[u] - 
  Int[Regularize[x*D[u,x]/(Sqrt[-1+u]*Sqrt[1+u]),x],x] /;
InverseFunctionFreeQ[u,x] && Not[FunctionOfExponentialOfLinear[u,x]]


(* ::PageBreak:: *)
(**)


(* ::Title::Bold::Closed:: *)
(*\[Integral]x^m E^(n ArcCosh[u]) \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Derivation: Algebraic simplification*)


(* ::Subsubsection:: *)
(*Basis: E^(n ArcCosh[z])=(z+Sqrt[-1+z] Sqrt[1+z])^n*)


(* ::Subsubsection:: *)
(*Basis: If n\[Element]\[DoubleStruckCapitalZ],  E^(n ArcCosh[z])==(z+Sqrt[(-1+z)/(1+z)]+z Sqrt[(-1+z)/(1+z)])^n*)


(* ::Subsubsection:: *)
(*Rule: If  n\[Element]\[DoubleStruckCapitalZ] \[And] u is a polynomial in x, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]E^(n ArcCosh[u]) \[DifferentialD]x  \[LongRightArrow]  \[Integral](u+Sqrt[-1+u] Sqrt[1+u])^n \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[E^(n_.*ArcCosh[u_]), x_Symbol] :=
  Int[(u+Sqrt[-1+u]*Sqrt[1+u])^n,x] /;
IntegerQ[n] && PolynomialQ[u,x]


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Derivation: Algebraic simplification*)


(* ::Subsubsection:: *)
(*Basis: E^(n ArcCosh[z])=(z+Sqrt[-1+z] Sqrt[1+z])^n*)


(* ::Subsubsection:: *)
(*Rule: If  n\[Element]\[DoubleStruckCapitalZ] \[And] u is a polynomial in x, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]x^m E^(n ArcCosh[u]) \[DifferentialD]x  \[LongRightArrow]  \[Integral]x^m (u+Sqrt[-1+u] Sqrt[1+u])^n \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[x_^m_.*E^(n_.*ArcCosh[u_]), x_Symbol] :=
  Int[x^m*(u+Sqrt[-1+u]*Sqrt[1+u])^n,x] /;
RationalQ[m] && IntegerQ[n] && PolynomialQ[u,x]
