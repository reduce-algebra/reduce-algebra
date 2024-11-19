(* ::Package:: *)

(* ::Title::Bold::Closed:: *)
(*\[Integral](x (A+B Sin[c+d x]))/(a+b Sin[c+d x])^2 \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Derivation: Integration by parts*)


(* ::Subsubsection:: *)
(*Rule: If  a A-b B=0, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral](x (A+B Sin[c+d x]))/(a+b Sin[c+d x])^2 \[DifferentialD]x  \[LongRightArrow]  -((B x Cos[c+d x])/(a d (a+b Sin[c+d x])))+B/(a d) \[Integral]Cos[c+d x]/(a+b Sin[c+d x]) \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[x_*(A_+B_.*Sin[c_.+d_.*x_])/(a_+b_.*Sin[c_.+d_.*x_])^2,x_Symbol] :=
  -B*x*Cos[c+d*x]/(a*d*(a+b*Sin[c+d*x])) +
  Dist[B/(a*d),Int[Cos[c+d*x]/(a+b*Sin[c+d*x]),x]] /;
FreeQ[{a,b,c,d,A,B},x] && ZeroQ[a*A-b*B]


(* ::Code:: *)
Int[x_*(A_+B_.*Cos[c_.+d_.*x_])/(a_+b_.*Cos[c_.+d_.*x_])^2,x_Symbol] :=
  B*x*Sin[c+d*x]/(a*d*(a+b*Cos[c+d*x])) -
  Dist[B/(a*d),Int[Sin[c+d*x]/(a+b*Cos[c+d*x]),x]] /;
FreeQ[{a,b,c,d,A,B},x] && ZeroQ[a*A-b*B]


(* ::PageBreak:: *)
(**)


(* ::Title::Bold::Closed:: *)
(*\[Integral]Sin[a+b x]^m Tan[a+b x]^n \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Reference: G&R 2.526.18', CRC 327'*)


(* ::Subsubsection:: *)
(*Derivation: Algebraic expansion*)


(* ::Subsubsection:: *)
(*Basis: Sin[z] Tan[z]=-Cos[z]+Sec[z]*)


(* ::Subsubsection:: *)
(*Rule:*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]Sin[a+b x] Tan[a+b x]\[DifferentialD]x  \[LongRightArrow]  -(Sin[a+b x]/b)+\[Integral]Sec[a+b x]\[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[Sin[a_.+b_.*x_]*Tan[a_.+b_.*x_],x_Symbol] :=
  -Sin[a+b*x]/b + Int[Sec[a+b*x],x] /;
FreeQ[{a,b},x]


(* ::Subsubsection:: *)
(*Reference: G&R 2.526.34'*)


(* ::Code:: *)
Int[Cos[a_.+b_.*x_]*Cot[a_.+b_.*x_],x_Symbol] :=
  Cos[a+b*x]/b + Int[Csc[a+b*x],x] /;
FreeQ[{a,b},x]


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Rule: If  m+n-1=0, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]Sin[a+b x]^m Tan[a+b x]^n \[DifferentialD]x  \[LongRightArrow]  -((Sin[a+b x]^m Tan[a+b x]^(n-1))/(b m))*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[Sin[a_.+b_.*x_]^m_*Tan[a_.+b_.*x_]^n_,x_Symbol] :=
  -Sin[a+b*x]^m*Tan[a+b*x]^(n-1)/(b*m) /;
FreeQ[{a,b,m,n},x] && ZeroQ[m+n-1]


(* ::Code:: *)
Int[Cos[a_.+b_.*x_]^m_*Cot[a_.+b_.*x_]^n_,x_Symbol] :=
  Cos[a+b*x]^m*Cot[a+b*x]^(n-1)/(b*m) /;
FreeQ[{a,b,m,n},x] && ZeroQ[m+n-1]


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Derivation: Integration by substitution*)


(* ::Subsubsection:: *)
(*Basis: If  m,n,(m+n-1)/2\[Element]\[DoubleStruckCapitalZ], then Sin[z]^m Tan[z]^n=-((1-Cos[z]^2)^(((m+n-1)/2))/Cos[z]^n)\!\( *)
(*\*SubscriptBox[\(\[PartialD]\), \(z\)]\(Cos[z]\)\)*)


(* ::Subsubsection:: *)
(*Note: This rule is used if  m+n  is odd since it requires fewer steps and results in a simpler antiderivative than the other rules in this section.*)


(* ::Subsubsection:: *)
(*Rule: If  m,n,(m+n-1)/2\[Element]\[DoubleStruckCapitalZ], then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]Sin[a+b x]^m Tan[a+b x]^n \[DifferentialD]x  \[LongRightArrow]  -(1/b)Subst[\[Integral](1-x^2)^((m+n-1)/2)/x^n \[DifferentialD]x,x,Cos[a+b x]]*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[Sin[a_.+b_.*x_]^m_.*Tan[a_.+b_.*x_]^n_.,x_Symbol] :=
  Dist[-1/b,Subst[Int[Regularize[(1-x^2)^((m+n-1)/2)/x^n,x],x],x,Cos[a+b*x]]] /;
FreeQ[{a,b},x] && IntegersQ[m,n,(m+n-1)/2]


(* ::Subsubsection:: *)
(*Basis: If  m,n,(m+n-1)/2\[Element]\[DoubleStruckCapitalZ], then Cos[z]^m Cot[z]^n=(1-Sin[z]^2)^((m+n-1)/2)/Sin[z]^n \!\( *)
(*\*SubscriptBox[\(\[PartialD]\), \(z\)]\(Sin[z]\)\)*)


(* ::Code:: *)
Int[Cos[a_.+b_.*x_]^m_.*Cot[a_.+b_.*x_]^n_.,x_Symbol] :=
  Dist[1/b,Subst[Int[Regularize[(1-x^2)^((m+n-1)/2)/x^n,x],x],x,Sin[a+b*x]]] /;
FreeQ[{a,b},x] && IntegersQ[m,n,(m+n-1)/2]


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Reference: G&R 2.510.5, CRC 323a*)


(* ::Subsubsection:: *)
(*Rule: If  m>1 \[And] n<-1, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]Sin[a+b x]^m Tan[a+b x]^n \[DifferentialD]x  \[LongRightArrow]  ((Sin[a+b x]^m Tan[a+b x]^(n+1))/(b m))-(n+1)/m \[Integral]Sin[a+b x]^(m-2) Tan[a+b x]^(n+2) \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[Sin[a_.+b_.*x_]^m_*Tan[a_.+b_.*x_]^n_,x_Symbol] :=
  Sin[a+b*x]^m*Tan[a+b*x]^(n+1)/(b*m) -
  Dist[(n+1)/m,Int[Sin[a+b*x]^(m-2)*Tan[a+b*x]^(n+2),x]] /;
FreeQ[{a,b},x] && RationalQ[{m,n}] && m>1 && n<-1


(* ::Subsubsection:: *)
(*Reference: G&R 2.510.2, CRC 323b*)


(* ::Code:: *)
Int[Cos[a_.+b_.*x_]^m_*Cot[a_.+b_.*x_]^n_,x_Symbol] :=
  -Cos[a+b*x]^m*Cot[a+b*x]^(n+1)/(b*m) -
  Dist[(n+1)/m,Int[Cos[a+b*x]^(m-2)*Cot[a+b*x]^(n+2),x]] /;
FreeQ[{a,b},x] && RationalQ[{m,n}] && m>1 && n<-1


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Reference: G&R 2.510.6, CRC 334b*)


(* ::Subsubsection:: *)
(*Rule: If  m<-1 \[And] n>1, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]Sin[a+b x]^m Tan[a+b x]^n \[DifferentialD]x  \[LongRightArrow]  ((Sin[a+b x]^(m+2) Tan[a+b x]^(n-1))/(b (n-1)))-(m+2)/(n-1) \[Integral]Sin[a+b x]^(m+2) Tan[a+b x]^(n-2) \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[Sin[a_.+b_.*x_]^m_*Tan[a_.+b_.*x_]^n_,x_Symbol] :=
  Sin[a+b*x]^(m+2)*Tan[a+b*x]^(n-1)/(b*(n-1)) -
  Dist[(m+2)/(n-1),Int[Sin[a+b*x]^(m+2)*Tan[a+b*x]^(n-2),x]] /;
FreeQ[{a,b},x] && RationalQ[{m,n}] && m<-1 && n>1


(* ::Subsubsection:: *)
(*Reference: G&R 2.510.3, CRC 334a*)


(* ::Code:: *)
Int[Cos[a_.+b_.*x_]^m_*Cot[a_.+b_.*x_]^n_,x_Symbol] :=
  -Cos[a+b*x]^(m+2)*Cot[a+b*x]^(n-1)/(b*(n-1)) -
  Dist[(m+2)/(n-1),Int[Cos[a+b*x]^(m+2)*Cot[a+b*x]^(n-2),x]] /;
FreeQ[{a,b},x] && RationalQ[{m,n}] && m<-1 && n>1


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Reference: G&R 2.510.2, CRC 323b*)


(* ::Subsubsection:: *)
(*Rule: If  m>1, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]Sin[a+b x]^m Tan[a+b x]^n \[DifferentialD]x  \[LongRightArrow]  -((Sin[a+b x]^m Tan[a+b x]^(n-1))/(b m))+(m+n-1)/m \[Integral]Sin[a+b x]^(m-2) Tan[a+b x]^n \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[Sin[a_.+b_.*x_]^m_*Tan[a_.+b_.*x_]^n_.,x_Symbol]:=
  -Sin[a+b*x]^m*Tan[a+b*x]^(n-1)/(b*m) +
  Dist[(m+n-1)/m,Int[Sin[a+b*x]^(m-2)*Tan[a+b*x]^n,x]] /;
FreeQ[{a,b,n},x] && RationalQ[m] && m>1


(* ::Subsubsection:: *)
(*Reference: G&R 2.510.5, CRC 323a*)


(* ::Code:: *)
Int[Cos[a_.+b_.*x_]^m_*Cot[a_.+b_.*x_]^n_.,x_Symbol] :=
  Cos[a+b*x]^m*Cot[a+b*x]^(n-1)/(b*m) +
  Dist[(m+n-1)/m,Int[Cos[a+b*x]^(m-2)*Cot[a+b*x]^n,x]] /;
FreeQ[{a,b,n},x] && RationalQ[m] && m>1


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Reference: G&R 2.510.1*)


(* ::Subsubsection:: *)
(*Rule: If  n>1, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]Sin[a+b x]^m Tan[a+b x]^n \[DifferentialD]x  \[LongRightArrow]  ((Sin[a+b x]^m Tan[a+b x]^(n-1))/(b (n-1)))-(m+n-1)/(n-1) \[Integral]Sin[a+b x]^m Tan[a+b x]^(n-2) \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[Sin[a_.+b_.*x_]^m_.*Tan[a_.+b_.*x_]^n_,x_Symbol] :=
  Sin[a+b*x]^m*Tan[a+b*x]^(n-1)/(b*(n-1)) -
  Dist[(m+n-1)/(n-1),Int[Sin[a+b*x]^m*Tan[a+b*x]^(n-2),x]] /;
FreeQ[{a,b,m},x] && RationalQ[n] && n>1


(* ::Subsubsection:: *)
(*Reference: G&R 2.510.4*)


(* ::Code:: *)
Int[Cos[a_.+b_.*x_]^m_.*Cot[a_.+b_.*x_]^n_,x_Symbol] :=
  -Cos[a+b*x]^m*Cot[a+b*x]^(n-1)/(b*(n-1)) -
  Dist[(m+n-1)/(n-1),Int[Cos[a+b*x]^m*Cot[a+b*x]^(n-2),x]] /;
FreeQ[{a,b,m},x] && RationalQ[n] && n>1


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Reference: G&R 2.510.3, CRC 334a*)


(* ::Subsubsection:: *)
(*Rule: If  m<-1 \[And] m+n+1!=0, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]Sin[a+b x]^m Tan[a+b x]^n \[DifferentialD]x  \[LongRightArrow]  ((Sin[a+b x]^(m+2) Tan[a+b x]^(n-1))/(b (m+n+1)))+(m+2)/(m+n+1) \[Integral]Sin[a+b x]^(m+2) Tan[a+b x]^n \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[Sin[a_.+b_.*x_]^m_*Tan[a_.+b_.*x_]^n_.,x_Symbol]:=
  Sin[a+b*x]^(m+2)*Tan[a+b*x]^(n-1)/(b*(m+n+1)) +
  Dist[(m+2)/(m+n+1),Int[Sin[a+b*x]^(m+2)*Tan[a+b*x]^n,x]] /;
FreeQ[{a,b,n},x] && RationalQ[m] && m<-1 && NonzeroQ[m+n+1]


(* ::Subsubsection:: *)
(*Reference: G&R 2.510.6, CRC 334b*)


(* ::Code:: *)
Int[Cos[a_.+b_.*x_]^m_*Cot[a_.+b_.*x_]^n_.,x_Symbol] :=
  -Cos[a+b*x]^(m+2)*Cot[a+b*x]^(n-1)/(b*(m+n+1)) +
  Dist[(m+2)/(m+n+1),Int[Cos[a+b*x]^(m+2)*Cot[a+b*x]^n,x]] /;
FreeQ[{a,b,n},x] && RationalQ[m] && m<-1 && NonzeroQ[m+n+1]


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Reference: G&R 2.510.4*)


(* ::Subsubsection:: *)
(*Rule: If  n<-1 \[And] m+n+1!=0, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]Sin[a+b x]^m Tan[a+b x]^n \[DifferentialD]x  \[LongRightArrow]  ((Sin[a+b x]^m Tan[a+b x]^(n+1))/(b (m+n+1)))-(n+1)/(m+n+1) \[Integral]Sin[a+b x]^m Tan[a+b x]^(n+2) \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[Sin[a_.+b_.*x_]^m_.*Tan[a_.+b_.*x_]^n_,x_Symbol]:=
  Sin[a+b*x]^m*Tan[a+b*x]^(n+1)/(b*(m+n+1)) -
  Dist[(n+1)/(m+n+1),Int[Sin[a+b*x]^m*Tan[a+b*x]^(n+2),x]] /;
FreeQ[{a,b,m},x] && RationalQ[n] && n<-1 && NonzeroQ[m+n+1]


(* ::Subsubsection:: *)
(*Reference: G&R 2.510.1*)


(* ::Code:: *)
Int[Cos[a_.+b_.*x_]^m_.*Cot[a_.+b_.*x_]^n_,x_Symbol] :=
  -Cos[a+b*x]^m*Cot[a+b*x]^(n+1)/(b*(m+n+1)) -
  Dist[(n+1)/(m+n+1),Int[Cos[a+b*x]^m*Cot[a+b*x]^(n+2),x]] /;
FreeQ[{a,b,m},x] && RationalQ[n] && n<-1 && NonzeroQ[m+n+1]


(* ::PageBreak:: *)
(**)


(* ::Title::Bold::Closed:: *)
(*\[Integral]Sin[a+b x] Sin[2(a+b x)]^n \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Rule:*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]Sin[a+b x]/Sqrt[Sin[2 (a+b x)]] \[DifferentialD]x  \[LongRightArrow]                                                                                                                                           *)
(*                     -(ArcSin[Cos[a+b x]-Sin[a+b x]]/(2 b))-Log[Cos[a+b x]+Sin[a+b x]+Sqrt[Sin[2 (a+b x)]]]/(2 b)*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[Sin[a_.+b_.*x_]/Sqrt[Sin[c_.+d_.*x_]],x_Symbol] :=
  -ArcSin[Cos[a+b*x]-Sin[a+b*x]]/(2*b) - Log[Cos[a+b*x]+Sin[a+b*x]+Sqrt[Sin[c+d*x]]]/(2*b) /;
FreeQ[{a,b,c,d},x] && ZeroQ[c-2*a] && ZeroQ[d-2*b]


(* ::Code:: *)
Int[Cos[a_.+b_.*x_]/Sqrt[Sin[c_.+d_.*x_]],x_Symbol] :=
  -ArcSin[Cos[a+b*x]-Sin[a+b*x]]/(2*b) + Log[Cos[a+b*x]+Sin[a+b*x]+Sqrt[Sin[c+d*x]]]/(2*b) /;
FreeQ[{a,b,c,d},x] && ZeroQ[c-2*a] && ZeroQ[d-2*b]


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Rule:*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]Sin[a+b x]/Sin[2 (a+b x)]^(3/2) \[DifferentialD]x  \[LongRightArrow]  (Sin[a+b x]/(b Sqrt[Sin[2 (a+b x)]]))*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[Sin[a_.+b_.*x_]/Sin[c_.+d_.*x_]^(3/2),x_Symbol] :=
  Sin[a+b*x]/(b*Sqrt[Sin[c+d*x]]) /;
FreeQ[{a,b,c,d},x] && ZeroQ[c-2*a] && ZeroQ[d-2*b]


(* ::Code:: *)
Int[Cos[a_.+b_.*x_]/Sin[c_.+d_.*x_]^(3/2),x_Symbol] :=
  -Cos[a+b*x]/(b*Sqrt[Sin[c+d*x]]) /;
FreeQ[{a,b,c,d},x] && ZeroQ[c-2*a] && ZeroQ[d-2*b]


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Rule: If  n>0, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]Sin[a+b x] Sin[2(a+b x)]^n \[DifferentialD]x  \[LongRightArrow]                                                                                          *)
(*                     -((Cos[a+b x] Sin[2(a+b x)]^n)/(b(2n+1)))+(2n)/(2n+1) \[Integral]Cos[a+b x]Sin[2(a+b x)]^(n-1) \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[Sin[a_.+b_.*x_]*Sin[c_.+d_.*x_]^n_.,x_Symbol] :=
  -Cos[a+b*x]*Sin[c+d*x]^n/(b*(2*n+1)) + 
  Dist[2*n/(2*n+1),Int[Cos[a+b*x]*Sin[c+d*x]^(n-1),x]] /;
FreeQ[{a,b,c,d},x] && ZeroQ[c-2*a] && ZeroQ[d-2*b] && FractionQ[n] && n>0


(* ::Code:: *)
Int[Cos[a_.+b_.*x_]*Sin[c_.+d_.*x_]^n_.,x_Symbol] :=
  Sin[a+b*x]*Sin[c+d*x]^n/(b*(2*n+1)) + 
  Dist[2*n/(2*n+1),Int[Sin[a+b*x]*Sin[c+d*x]^(n-1),x]] /;
FreeQ[{a,b,c,d},x] && ZeroQ[c-2*a] && ZeroQ[d-2*b] && FractionQ[n] && n>0


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Rule: If  n<-1 \[And] n!=-(3/2), then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]Sin[a+b x] Sin[2(a+b x)]^n \[DifferentialD]x  \[LongRightArrow]                                                                                          *)
(*                     -((Sin[a+b x] Sin[2(a+b x)]^(n+1))/(2b(n+1)))+(2n+3)/(2(n+1)) \[Integral]Cos[a+b x] Sin[2(a+b x)]^(n+1) \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[Sin[a_.+b_.*x_]*Sin[c_.+d_.*x_]^n_,x_Symbol] :=
  -Sin[a+b*x]*Sin[c+d*x]^(n+1)/(2*b*(n+1)) + 
  Dist[(2*n+3)/(2*(n+1)),Int[Cos[a+b*x]*Sin[c+d*x]^(n+1),x]] /;
FreeQ[{a,b,c,d},x] && ZeroQ[c-2*a] && ZeroQ[d-2*b] && FractionQ[n] && n<-1 && n!=-3/2


(* ::Code:: *)
Int[Cos[a_.+b_.*x_]*Sin[c_.+d_.*x_]^n_,x_Symbol] :=
  Cos[a+b*x]*Sin[c+d*x]^(n+1)/(2*b*(n+1)) + 
  Dist[(2*n+3)/(2*(n+1)),Int[Sin[a+b*x]*Sin[c+d*x]^(n+1),x]] /;
FreeQ[{a,b,c,d},x] && ZeroQ[c-2*a] && ZeroQ[d-2*b] && FractionQ[n] && n<-1 && n!=-3/2


(* ::PageBreak:: *)
(**)


(* ::Title::Bold::Closed:: *)
(*\[Integral]u Sin[v] Trig[w]\[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Derivation: Algebraic expansion*)


(* ::Subsubsection:: *)
(*Basis: Sin[v] Cos[w]=1/2 Sin[v+w]+1/2 Sin[v-w]*)


(* ::Subsubsection:: *)
(*Rule: If  v,w \[Element]\[DoubleStruckCapitalP]x \[And] v+w!=0 \[And] v-w!=0, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]u Sin[v] Cos[w]\[DifferentialD]x  \[LongRightArrow]  (1/2)\[Integral]u Sin[v+w]\[DifferentialD]x+1/2 \[Integral]u Sin[v-w]\[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[u_.*Sin[v_]*Cos[w_],x_Symbol] :=
  Dist[1/2,Int[u*Regularize[Sin[v+w],x],x]] + 
  Dist[1/2,Int[u*Regularize[Sin[v-w],x],x]] /;
(PolynomialQ[v,x] && PolynomialQ[w,x] || IndependentQ[Cancel[v/w],x]) && NonzeroQ[v+w] && NonzeroQ[v-w]


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Derivation: Algebraic expansion*)


(* ::Subsubsection:: *)
(*Basis: Sin[v] Sin[w]=1/2 Cos[v-w]-1/2 Cos[v+w]*)


(* ::Subsubsection:: *)
(*Rule: If  v,w \[Element]\[DoubleStruckCapitalP]x \[And] v+w!=0 \[And] v-w!=0, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]u Sin[v] Sin[w]\[DifferentialD]x  \[LongRightArrow]  (1/2)\[Integral]u Cos[v-w]\[DifferentialD]x-1/2 \[Integral]u Cos[v+w]\[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[u_.*Sin[v_]*Sin[w_],x_Symbol] :=
  Dist[1/2,Int[u*Regularize[Cos[v-w],x],x]] - 
  Dist[1/2,Int[u*Regularize[Cos[v+w],x],x]] /;
(PolynomialQ[v,x] && PolynomialQ[w,x] || IndependentQ[Cancel[v/w],x]) && NonzeroQ[v+w] && NonzeroQ[v-w]


(* ::Subsubsection:: *)
(*Basis: Cos[v] Cos[w]=1/2 Cos[v-w]+1/2 Cos[v+w]*)


(* ::Code:: *)
Int[u_.*Cos[v_]*Cos[w_],x_Symbol] :=
  Dist[1/2,Int[u*Regularize[Cos[v-w],x],x]] + 
  Dist[1/2,Int[u*Regularize[Cos[v+w],x],x]] /;
(PolynomialQ[v,x] && PolynomialQ[w,x] || IndependentQ[Cancel[v/w],x]) && NonzeroQ[v+w] && NonzeroQ[v-w]


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Derivation: Algebraic expansion*)


(* ::Subsubsection:: *)
(*Basis: Sin[v] Tan[w]=-Cos[v]+Cos[v-w] Sec[w]*)


(* ::Subsubsection:: *)
(*Rule: If  n>0 \[And] x\[NotElement]v-w!=0, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]u Sin[v] Tan[w]^n \[DifferentialD]x  \[LongRightArrow]  -\[Integral]u Cos[v] Tan[w]^(n-1) \[DifferentialD]x+Cos[v-w] \[Integral]u Sec[w] Tan[w]^(n-1) \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[u_.*Sin[v_]*Tan[w_]^n_.,x_Symbol] :=
  -Int[u*Cos[v]*Tan[w]^(n-1),x] + Cos[v-w]*Int[u*Sec[w]*Tan[w]^(n-1),x] /;
RationalQ[n] && n>0 && FreeQ[v-w,x] && NonzeroQ[v-w]


(* ::Subsubsection:: *)
(*Basis: Cos[v] Cot[w]=-Sin[v]+Cos[v-w] Csc[w]*)


(* ::Code:: *)
Int[u_.*Cos[v_]*Cot[w_]^n_.,x_Symbol] :=
  -Int[u*Sin[v]*Cot[w]^(n-1),x] + Cos[v-w]*Int[u*Csc[w]*Cot[w]^(n-1),x] /;
RationalQ[n] && n>0 && FreeQ[v-w,x] && NonzeroQ[v-w]


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Derivation: Algebraic expansion*)


(* ::Subsubsection:: *)
(*Basis: Sin[v] Cot[w]=Cos[v]+Sin[v-w] Csc[w]*)


(* ::Subsubsection:: *)
(*Rule: If  n>0 \[And] x\[NotElement]v-w!=0, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]u Sin[v] Cot[w]^n \[DifferentialD]x  \[LongRightArrow]  \[Integral]u Cos[v] Cot[w]^(n-1) \[DifferentialD]x+Sin[v-w] \[Integral]u Csc[w] Cot[w]^(n-1) \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[u_.*Sin[v_]*Cot[w_]^n_.,x_Symbol] :=
  Int[u*Cos[v]*Cot[w]^(n-1),x] + Sin[v-w]*Int[u*Csc[w]*Cot[w]^(n-1),x] /;
RationalQ[n] && n>0 && FreeQ[v-w,x] && NonzeroQ[v-w]


(* ::Subsubsection:: *)
(*Basis: Cos[v] Tan[w]=Sin[v]-Sin[v-w] Sec[w]*)


(* ::Code:: *)
Int[u_.*Cos[v_]*Tan[w_]^n_.,x_Symbol] :=
  Int[u*Sin[v]*Tan[w]^(n-1),x] - Sin[v-w]*Int[u*Sec[w]*Tan[w]^(n-1),x] /;
RationalQ[n] && n>0 && FreeQ[v-w,x] && NonzeroQ[v-w]


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Derivation: Algebraic expansion*)


(* ::Subsubsection:: *)
(*Basis: Sin[v] Sec[w]=Cos[v-w] Tan[w]+Sin[v-w]*)


(* ::Subsubsection:: *)
(*Rule: If  n>0 \[And] x\[NotElement]v-w!=0, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]u Sin[v] Sec[w]^n \[DifferentialD]x  \[LongRightArrow]  Cos[v-w] \[Integral]u Tan[w] Sec[w]^(n-1) \[DifferentialD]x+Sin[v-w] \[Integral]u Sec[w]^(n-1) \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[u_.*Sin[v_]*Sec[w_]^n_.,x_Symbol] :=
  Cos[v-w]*Int[u*Tan[w]*Sec[w]^(n-1),x] + Sin[v-w]*Int[u*Sec[w]^(n-1),x] /;
RationalQ[n] && n>0 && FreeQ[v-w,x] && NonzeroQ[v-w]


(* ::Subsubsection:: *)
(*Basis: Cos[v]*Csc[w]=Cos[v-w]*Cot[w]-Sin[v-w]*)


(* ::Code:: *)
Int[u_.*Cos[v_]*Csc[w_]^n_.,x_Symbol] :=
  Cos[v-w]*Int[u*Cot[w]*Csc[w]^(n-1),x] - Sin[v-w]*Int[u*Csc[w]^(n-1),x] /;
RationalQ[n] && n>0 && FreeQ[v-w,x] && NonzeroQ[v-w]


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Derivation: Algebraic expansion*)


(* ::Subsubsection:: *)
(*Basis: Sin[v] Csc[w]=Sin[v-w] Cot[w]+Cos[v-w]*)


(* ::Subsubsection:: *)
(*Rule: If  n>0 \[And] x\[NotElement]v-w!=0, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]u Sin[v] Csc[w]^n \[DifferentialD]x  \[LongRightArrow]  Sin[v-w] \[Integral]u Cot[w] Csc[w]^(n-1) \[DifferentialD]x+Cos[v-w] \[Integral]u Csc[w]^(n-1) \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[u_.*Sin[v_]*Csc[w_]^n_.,x_Symbol] :=
  Sin[v-w]*Int[u*Cot[w]*Csc[w]^(n-1),x] + Cos[v-w]*Int[u*Csc[w]^(n-1),x] /;
RationalQ[n] && n>0 && FreeQ[v-w,x] && NonzeroQ[v-w]


(* ::Subsubsection:: *)
(*Basis: Cos[v] Sec[w]=-Sin[v-w] Tan[w]+Cos[v-w]*)


(* ::Code:: *)
Int[u_.*Cos[v_]*Sec[w_]^n_.,x_Symbol] :=
  -Sin[v-w]*Int[u*Tan[w]*Sec[w]^(n-1),x] + Cos[v-w]*Int[u*Sec[w]^(n-1),x] /;
RationalQ[n] && n>0 && FreeQ[v-w,x] && NonzeroQ[v-w]


(* ::PageBreak:: *)
(**)


(* ::Title::Bold::Closed:: *)
(*\[Integral]x^m Sin[a+b x^n]^p Cos[a+b x^n]\[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Reference: G&R 2.645.6*)


(* ::Subsubsection:: *)
(*Rule: If  m,n,p\[Element]\[DoubleStruckCapitalZ] \[And] p!=-1 \[And] 0<n<=m, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]x^m Sin[a+b x^n]^p Cos[a+b x^n]\[DifferentialD]x  \[LongRightArrow]  ((x^(m-n+1) Sin[a+b x^n]^(p+1))/(b n (p+1)))-(m-n+1)/(b n (p+1)) \[Integral]x^(m-n) Sin[a+b x^n]^(p+1) \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[x_^m_.*Sin[a_.+b_.*x_^n_.]^p_.*Cos[a_.+b_.*x_^n_.],x_Symbol] :=
  x^(m-n+1)*Sin[a+b*x^n]^(p+1)/(b*n*(p+1)) -
  Dist[(m-n+1)/(b*n*(p+1)),Int[x^(m-n)*Sin[a+b*x^n]^(p+1),x]] /;
FreeQ[{a,b},x] && IntegersQ[m,n,p] && p!=-1 && 0<n<=m


(* ::Subsubsection:: *)
(*Reference: G&R 2.645.3*)


(* ::Code:: *)
Int[x_^m_.*Cos[a_.+b_.*x_^n_.]^p_.*Sin[a_.+b_.*x_^n_.],x_Symbol] :=
  -x^(m-n+1)*Cos[a+b*x^n]^(p+1)/(b*n*(p+1)) +
  Dist[(m-n+1)/(b*n*(p+1)),Int[x^(m-n)*Cos[a+b*x^n]^(p+1),x]] /;
FreeQ[{a,b},x] && IntegersQ[m,n,p] && p!=-1 && 0<n<=m


(* ::PageBreak:: *)
(**)


(* ::Subsubsection:: *)
(**)


(* ::Title::Bold::Closed:: *)
(*\[Integral]Sin[a+b x]^m Cos[a+b x]^n \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Rule: If  m+n+2=0 \[And] m+1!=0, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]Sin[a+b x]^m Cos[a+b x]^n \[DifferentialD]x  \[LongRightArrow]  ((Sin[a+b x]^(m+1) Cos[a+b x]^(n+1))/(b (m+1)))*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[Sin[a_.+b_.*x_]^m_.*Cos[a_.+b_.*x_]^n_,x_Symbol] :=
  Sin[a+b*x]^(m+1)*Cos[a+b*x]^(n+1)/(b*(m+1)) /;
FreeQ[{a,b,m,n},x] && ZeroQ[m+n+2] && NonzeroQ[m+1]


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Derivation: Integration by substitution*)


(* ::Subsubsection:: *)
(*Basis: If (n-1)/2\[Element]\[DoubleStruckCapitalZ], then Sin[z]^m Cos[z]^n=Sin[z]^m (1-Sin[z]^2)^((n-1)/2) Derivative[1][Sin][z]*)


(* ::Subsubsection:: *)
(*Note: This rule is used for odd n since it requires fewer steps and results in a simpler antiderivative than the other rules in this section.*)


(* ::Subsubsection:: *)
(*Rule: If (n-1)/2\[Element]\[DoubleStruckCapitalZ] \[And] \[Not]((m-1)/2\[Element]\[DoubleStruckCapitalZ] \[And] 0<m<n), then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]Sin[a+b x]^m Cos[a+b x]^n \[DifferentialD]x  \[LongRightArrow]  (1/b)Subst[\[Integral]x^m (1-x^2)^((n-1)/2) \[DifferentialD]x,x,Sin[a+b x]]*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[Sin[a_.+b_.*x_]^m_*Cos[a_.+b_.*x_]^n_,x_Symbol] :=
  Dist[1/b,Subst[Int[Regularize[x^m*(1-x^2)^((n-1)/2),x],x],x,Sin[a+b*x]]] /;
FreeQ[{a,b,m},x] && OddQ[n] && Not[OddQ[m] && 0<m<n]


(* ::Subsubsection:: *)
(*Basis: If (m-1)/2\[Element]\[DoubleStruckCapitalZ], then Sin[z]^m Cos[z]^n=-Cos[z]^n (1-Cos[z]^2)^((m-1)/2) Derivative[1][Cos][z]*)


(* ::Code:: *)
Int[Sin[a_.+b_.*x_]^m_*Cos[a_.+b_.*x_]^n_,x_Symbol] :=
  Dist[-1/b,Subst[Int[Regularize[x^n*(1-x^2)^((m-1)/2),x],x],x,Cos[a+b*x]]] /;
FreeQ[{a,b,n},x] && OddQ[m] && Not[OddQ[n] && 0<n<=m]


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Reference: G&R 2.510.1*)


(* ::Subsubsection:: *)
(*Rule: If  m>1 \[And] n<-1, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]Sin[a+b x]^m Cos[a+b x]^n \[DifferentialD]x  \[LongRightArrow]  -((Sin[a+b x]^(m-1) Cos[a+b x]^(n+1))/(b (n+1)))+(m-1)/(n+1) \[Integral]Sin[a+b x]^(m-2) Cos[a+b x]^(n+2) \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[Sin[a_.+b_.*x_]^m_*Cos[a_.+b_.*x_]^n_,x_Symbol] :=
  -Sin[a+b*x]^(m-1)*Cos[a+b*x]^(n+1)/(b*(n+1)) +
  Dist[(m-1)/(n+1),Int[Sin[a+b*x]^(m-2)*Cos[a+b*x]^(n+2),x]] /;
FreeQ[{a,b},x] && RationalQ[{m,n}] && m>1 && n<-1


(* ::Subsubsection:: *)
(*Reference: G&R 2.510.4*)


(* ::Code:: *)
Int[Sin[a_.+b_.*x_]^m_*Cos[a_.+b_.*x_]^n_,x_Symbol] :=
  Sin[a+b*x]^(m+1)*Cos[a+b*x]^(n-1)/(b*(m+1)) +
  Dist[(n-1)/(m+1),Int[Sin[a+b*x]^(m+2)*Cos[a+b*x]^(n-2),x]] /;
FreeQ[{a,b},x] && RationalQ[{m,n}] && m<-1 && n>1


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Reference: G&R 2.510.2, CRC 323b, A&S 4.3.127b*)


(* ::Subsubsection:: *)
(*Rule: If  m>1 \[And] (m-1)/2\[NotElement]\[DoubleStruckCapitalZ] \[And] m+n!=0 \[And] \[Not]((n-1)/2\[Element]\[DoubleStruckCapitalZ] \[And] n>1), then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]Sin[a+b x]^m Cos[a+b x]^n \[DifferentialD]x  \[LongRightArrow]  -((Sin[a+b x]^(m-1) Cos[a+b x]^(n+1))/(b (m+n)))+(m-1)/(m+n) \[Integral]Sin[a+b x]^(m-2) Cos[a+b x]^n \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[Sin[a_.+b_.*x_]^m_*Cos[a_.+b_.*x_]^n_,x_Symbol] :=
  -Sin[a+b*x]^(m-1)*Cos[a+b*x]^(n+1)/(b*(m+n)) +
  Dist[(m-1)/(m+n),Int[Sin[a+b*x]^(m-2)*Cos[a+b*x]^n,x]] /;
FreeQ[{a,b,n},x] && RationalQ[m] && m>1 && NonzeroQ[m+n]


(* ::Subsubsection:: *)
(*Reference: G&R 2.510.5, CRC 323a, A&S 4.3.127a*)


(* ::Code:: *)
Int[Sin[a_.+b_.*x_]^m_*Cos[a_.+b_.*x_]^n_,x_Symbol] :=
  Sin[a+b*x]^(m+1)*Cos[a+b*x]^(n-1)/(b*(m+n)) +
  Dist[(n-1)/(m+n),Int[Sin[a+b*x]^m*Cos[a+b*x]^(n-2),x]] /;
FreeQ[{a,b,m},x] && RationalQ[n] && n>1 && NonzeroQ[m+n]


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Reference: G&R 2.510.3, CRC 334a, A&S 4.3.128b*)


(* ::Subsubsection:: *)
(*Rule: If  m<-1 \[And] m+n+2!=0, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]Sin[a+b x]^m Cos[a+b x]^n \[DifferentialD]x  \[LongRightArrow]  ((Sin[a+b x]^(m+1) Cos[a+b x]^(n+1))/(b (m+1)))+(m+n+2)/(m+1) \[Integral]Sin[a+b x]^(m+2) Cos[a+b x]^n \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[Sin[a_.+b_.*x_]^m_*Cos[a_.+b_.*x_]^n_,x_Symbol] :=
  Sin[a+b*x]^(m+1)*Cos[a+b*x]^(n+1)/(b*(m+1)) +
  Dist[(m+n+2)/(m+1),Int[Sin[a+b*x]^(m+2)*Cos[a+b*x]^n,x]] /;
FreeQ[{a,b,n},x] && RationalQ[m] && m<-1 && NonzeroQ[m+n+2]


(* ::Subsubsection:: *)
(*Reference: G&R 2.510.6, CRC 334b, A&S 4.3.128a*)


(* ::Code:: *)
Int[Sin[a_.+b_.*x_]^m_*Cos[a_.+b_.*x_]^n_,x_Symbol] :=
  -Sin[a+b*x]^(m+1)*Cos[a+b*x]^(n+1)/(b*(n+1)) +
  Dist[(m+n+2)/(n+1),Int[Sin[a+b*x]^m*Cos[a+b*x]^(n+2),x]] /;
FreeQ[{a,b,m},x] && RationalQ[n] && n<-1 && NonzeroQ[m+n+2]


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Derivation: Integration by substitution*)


(* ::Subsubsection:: *)
(*Basis: If 1/m\[Element]\[DoubleStruckCapitalZ], then Sin[z]^m/Cos[z]^m=(Sin[z]^m/Cos[z]^m)^(1/m)/(m (1+(Sin[z]^m/Cos[z]^m)^(2/m))) \!\( *)
(*\*SubscriptBox[\(\[PartialD]\), \(z\)]*)
(*\*FractionBox[*)
(*SuperscriptBox[\(Sin[z]\), \(m\)], *)
(*SuperscriptBox[\(Cos[z]\), \(m\)]]\)*)


(* ::Subsubsection:: *)
(*Note: This rule should be replaced with a more general one.*)


(* ::Subsubsection:: *)
(*Rule: If  1/m\[Element]\[DoubleStruckCapitalZ] \[And] 1/m>1, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]Sin[a+b x]^m/Cos[a+b x]^m \[DifferentialD]x  \[LongRightArrow]  (1/(b m))Subst[\[Integral]x^(1/m)/(1+x^(2/m)) \[DifferentialD]x,x,Sin[a+b x]^m/Cos[a+b x]^m]*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[Sin[a_.+b_.*x_]^m_*Cos[a_.+b_.*x_]^n_,x_Symbol] :=
  Dist[1/(b*m),Subst[Int[x^(1/m)/(1+x^(2/m)),x],x,Sin[a+b*x]^m/Cos[a+b*x]^m]] /;
FreeQ[{a,b},x] && ZeroQ[m+n] && IntegerQ[1/m] && 1/m>1


(* ::Subsubsection:: *)
(*Basis: If 1/n\[Element]\[DoubleStruckCapitalZ], then Cos[z]^n/Sin[z]^n=-((Cos[z]^n/Sin[z]^n)^(1/n)/(n (1+(Cos[z]^n/Sin[z]^n)^(2/n))))\!\( *)
(*\*SubscriptBox[\(\[PartialD]\), \(z\)]*)
(*\*FractionBox[*)
(*SuperscriptBox[\(Cos[z]\), \(n\)], *)
(*SuperscriptBox[\(Sin[z]\), \(n\)]]\)*)


(* ::Code:: *)
Int[Sin[a_.+b_.*x_]^m_*Cos[a_.+b_.*x_]^n_,x_Symbol] :=
  Dist[-1/(b*n),Subst[Int[x^(1/n)/(1+x^(2/n)),x],x,Cos[a+b*x]^n/Sin[a+b*x]^n]] /;
FreeQ[{a,b},x] && ZeroQ[m+n] && IntegerQ[1/n] && 1/n>1


(* ::PageBreak:: *)
(**)


(* ::Title::Bold::Closed:: *)
(*\[Integral]x^m (a+b Cos[d+e x]^2+c Sin[d+e x]^2)^n \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Derivation: Algebraic simplification*)


(* ::Subsubsection:: *)
(*Basis: a+b Cos[z]^2+c Sin[z]^2=1/2 (2 a+b+c+(b-c) Cos[2 z])*)


(* ::Subsubsection:: *)
(*Rule: If  m\[Element]\[DoubleStruckCapitalZ] \[And] m>0 \[And] a+b!=0 \[And] a+c!=0, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]x^m/(a+b Cos[d+e x]^2+c Sin[d+e x]^2) \[DifferentialD]x  \[LongRightArrow]  2\[Integral]x^m/(2 a+b+c+(b-c) Cos[2 d+2 e x]) \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[x_^m_./(a_.+b_.*Cos[d_.+e_.*x_]^2+c_.*Sin[d_.+e_.*x_]^2),x_Symbol] :=
  Dist[2,Int[x^m/(2*a+b+c+(b-c)*Cos[2*d+2*e*x]),x]] /;
FreeQ[{a,b,c,d,e},x] && IntegerQ[m] && m>0 && NonzeroQ[a+b] && NonzeroQ[a+c]


(* ::PageBreak:: *)
(**)


(* ::Title::Bold::Closed:: *)
(*\[Integral]x^m (a+b Sin[c+d x] Cos[c+d x])^n \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Derivation: Algebraic simplification*)


(* ::Subsubsection:: *)
(*Basis: Sin[z] Cos[z]=1/2 Sin[2 z]*)


(* ::Subsubsection:: *)
(*Rule: If  m\[Element]\[DoubleStruckCapitalZ] \[And] m>0, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]x^m/(a+b Sin[c+d x] Cos[c+d x]) \[DifferentialD]x  \[LongRightArrow]  \[Integral]x^m/(a+1/2 b Sin[2 c+2 d x]) \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[x_^m_./(a_+b_.*Sin[c_.+d_.*x_]*Cos[c_.+d_.*x_]),x_Symbol] :=
  Int[x^m/(a+b*Sin[2*c+2*d*x]/2),x] /;
FreeQ[{a,b,c,d},x] && IntegerQ[m] && m>0


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Derivation: Algebraic simplification*)


(* ::Subsubsection:: *)
(*Basis: Sin[z] Cos[z]=1/2 Sin[2 z]*)


(* ::Subsubsection:: *)
(*Rule: If  n-1/2\[Element]\[DoubleStruckCapitalZ], then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral](a+b Sin[c+d x] Cos[c+d x])^n \[DifferentialD]x  \[LongRightArrow]  \[Integral](a+1/2 b Sin[2 c+2 d x])^n \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[(a_+b_.*Sin[c_.+d_.*x_]*Cos[c_.+d_.*x_])^n_,x_Symbol] :=
  Int[(a+b*Sin[2*c+2*d*x]/2)^n,x] /;
FreeQ[{a,b,c,d},x] && HalfIntegerQ[n]


(* ::PageBreak:: *)
(**)


(* ::Title::Bold::Closed:: *)
(*\[Integral]Sin[a+b x^n]^p Cos[a+b x^n]^p \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Derivation: Algebraic simplification*)


(* ::Subsubsection:: *)
(*Basis: Sin[z] Cos[z]=1/2 Sin[2 z]*)


(* ::Subsubsection:: *)
(*Rule: If  n,p\[Element]\[DoubleStruckCapitalZ], then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]Sin[a+b x^n]^p Cos[a+b x^n]^p \[DifferentialD]x  \[LongRightArrow]  (1/2)\[Integral]Sin[2 a+2 b x^n]^p \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[Sin[a_.+b_.*x_^n_]^p_.*Cos[a_.+b_.*x_^n_]^p_.,x_Symbol] :=
  Dist[1/2,Int[Sin[2*a+2*b*x^n]^p,x]] /;
FreeQ[{a,b},x] && IntegersQ[n,p]


(* ::PageBreak:: *)
(**)


(* ::Subsubsection:: *)
(**)


(* ::Title::Bold::Closed:: *)
(*\[Integral](a Csc[c+d x]+b Sin[c+d x])^n \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Derivation: Algebraic simplification*)


(* ::Subsubsection:: *)
(*Basis: Csc[z]-Sin[z]=Cos[z] Cot[z]*)


(* ::Subsubsection:: *)
(*Rule: If  a+b=0, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral](a Csc[c+d x]+b Sin[c+d x])^n \[DifferentialD]x  \[LongRightArrow]  \[Integral](a Cos[c+d x] Cot[c+d x])^n \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[(a_.*Csc[c_.+d_.*x_]+b_.*Sin[c_.+d_.*x_])^n_,x_Symbol] :=
  Int[(a*Cos[c+d*x]*Cot[c+d*x])^n,x] /;
FreeQ[{a,b,c,d,n},x] && ZeroQ[a+b]


(* ::Code:: *)
Int[(a_.*Sec[c_.+d_.*x_]+b_.*Cos[c_.+d_.*x_])^n_,x_Symbol] :=
  Int[(a*Sin[c+d*x]*Tan[c+d*x])^n,x] /;
FreeQ[{a,b,c,d,n},x] && ZeroQ[a+b]


(* ::PageBreak:: *)
(**)


(* ::Title::Bold::Closed:: *)
(*\[Integral]Sec[v]^m (a+b Tan[v])^n \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Derivation: Algebraic simplification*)


(* ::Subsubsection:: *)
(*Basis: (a+b Tan[z])/Sec[z]=a Cos[z]+b Sin[z]*)


(* ::Subsubsection:: *)
(*Rule: If  m,n\[Element]\[DoubleStruckCapitalZ] \[And] m+n=0 \[And] (m-1)/2\[Element]\[DoubleStruckCapitalZ], then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]Sec[v]^m (a+b Tan[v])^n \[DifferentialD]x  \[LongRightArrow]  \[Integral](a Cos[v]+b Sin[v])^n \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[Sec[v_]^m_.*(a_+b_.*Tan[v_])^n_., x_Symbol] :=
  Int[(a*Cos[v]+b*Sin[v])^n,x] /;
FreeQ[{a,b},x] && IntegersQ[m,n] && m+n==0 && OddQ[m]


(* ::Code:: *)
Int[Csc[v_]^m_.*(a_+b_.*Cot[v_])^n_., x_Symbol] :=
  Int[(b*Cos[v]+a*Sin[v])^n,x] /;
FreeQ[{a,b},x] && IntegersQ[m,n] && m+n==0 && OddQ[m]


(* ::PageBreak:: *)
(**)


(* ::Title::Bold::Closed:: *)
(*\[Integral]x^m Csc[a+b x]^n Sec[a+b x]^p \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Derivation: Algebraic simplification*)


(* ::Subsubsection:: *)
(*Basis: Csc[z]Sec[z]=2 Csc[2 z]*)


(* ::Subsubsection:: *)
(*Rule: If  n\[Element]\[DoubleStruckCapitalZ], then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]x^m Csc[a+b x]^n Sec[a+b x]^n \[DifferentialD]x  \[LongRightArrow]  2^n\[Integral] x^m Csc[2a+2b x]^n \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[x_^m_.*Csc[a_.+b_.*x_]^n_.*Sec[a_.+b_.*x_]^n_., x_Symbol] :=
  Dist[2^n,Int[x^m*Csc[2*a+2*b*x]^n,x]] /;
FreeQ[{a,b},x] && RationalQ[m] && IntegerQ[n]


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Derivation: Integration by parts*)


(* ::Subsubsection:: *)
(*Rule: If  n,p\[Element]\[DoubleStruckCapitalZ] \[And] m>0 \[And] n!=p, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]x^m Csc[a+b x]^n Sec[a+b x]^p \[DifferentialD]x  \[LongRightArrow]  *)
(*x^m \[Integral]Csc[a+b x]^n Sec[a+b x]^p \[DifferentialD]x-m \[Integral]x^(m-1) (\[Integral]Csc[a+b x]^n Sec[a+b x]^p \[DifferentialD]x)\[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[x_^m_.*Csc[a_.+b_.*x_]^n_.*Sec[a_.+b_.*x_]^p_., x_Symbol] :=
  Module[{u=Block[{ShowSteps=False,StepCounter=Null}, Int[Csc[a+b*x]^n*Sec[a+b*x]^p,x]]},
  x^m*u - Dist[m,Int[x^(m-1)*u,x]]] /;
FreeQ[{a,b},x] && RationalQ[m] && IntegersQ[n,p] && m>0 && n!=p


(* ::PageBreak:: *)
(**)


(* ::Title::Bold::Closed:: *)
(*\[Integral]u (a Tan[v]^m+b Sec[v]^m)^n \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Derivation: Algebraic simplification*)


(* ::Subsubsection:: *)
(*Basis: If  a^2-b^2=0, then a Tan[z]+b Sec[z]=a Tan[z/2+(a \[Pi])/(b 4)]*)


(* ::Subsubsection:: *)
(*Rule: If  a^2-b^2=0 \[And] n/2\[Element]\[DoubleStruckCapitalZ], then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral](a Tan[v]+b Sec[v])^n \[DifferentialD]x  \[LongRightArrow]  a^n \[Integral]Tan[v/2+\[Pi]/4 a/b]^n \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[(a_.*Tan[v_]+b_.*Sec[v_])^n_,x_Symbol] :=
  Dist[a^n,Int[Tan[v/2+Pi/4*a/b]^n,x]] /;
FreeQ[{a,b},x] && ZeroQ[a^2-b^2] && EvenQ[n]


(* ::Code:: *)
Int[(a_.*Cot[v_]+b_.*Csc[v_])^n_,x_Symbol] :=
  Dist[a^n,Int[Cot[v/2+(a/b-1)*Pi/4]^n,x]] /;
FreeQ[{a,b},x] && ZeroQ[a^2-b^2] && EvenQ[n]


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Derivation: Algebraic simplification*)


(* ::Subsubsection:: *)
(*Basis: a Sec[z]+b Tan[z]=(a+b Sin[z])/Cos[z]*)


(* ::Subsubsection:: *)
(*Rule: If  m,n\[Element]\[DoubleStruckCapitalZ] \[And] ((m n-1)/2\[Element]\[DoubleStruckCapitalZ] \[Or] m n<0) \[And] \[Not](m=2 \[And] a+b=0), then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]u (a Tan[v]^m+b Sec[v]^m)^n \[DifferentialD]x  \[LongRightArrow]  \[Integral](u (a+b Sin[v]^m)^n)/Cos[v]^(m n) \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[u_.*(a_.*Sec[v_]^m_.+b_.*Tan[v_]^m_.)^n_.,x_Symbol] :=
  Int[u*(a+b*Sin[v]^m)^n/Cos[v]^(m*n),x] /;
FreeQ[{a,b},x] && IntegersQ[m,n] && (OddQ[m*n] || m*n<0) && Not[m==2 && ZeroQ[a+b]]


(* ::Code:: *)
Int[u_.*(a_.*Csc[v_]^m_.+b_.*Cot[v_]^m_.)^n_.,x_Symbol] :=
  Int[u*(a+b*Cos[v]^m)^n/Sin[v]^(m*n),x] /;
FreeQ[{a,b},x] && IntegersQ[m,n] && (OddQ[m*n] || m*n<0) && Not[m==2 && ZeroQ[a+b]]


(* ::PageBreak:: *)
(**)
