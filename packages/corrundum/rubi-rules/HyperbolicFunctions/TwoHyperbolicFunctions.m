(* ::Package:: *)

(* ::Title::Bold::Closed:: *)
(*\[Integral](x (A+B Sinh[c+d x]))/(a+b Sinh[c+d x])^2 \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Derivation: Integration by parts*)


(* ::Subsubsection:: *)
(*Rule: If  a A+b B=0, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral](x (A+B Sinh[c+d x]))/(a+b Sinh[c+d x])^2 \[DifferentialD]x  \[LongRightArrow]  ((B x Cosh[c+d x])/(a d (a+b Sinh[c+d x])))-B/(a d) \[Integral]Cosh[c+d x]/(a+b Sinh[c+d x]) \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[x_*(A_+B_.*Sinh[c_.+d_.*x_])/(a_+b_.*Sinh[c_.+d_.*x_])^2,x_Symbol] :=
  B*x*Cosh[c+d*x]/(a*d*(a+b*Sinh[c+d*x])) -
  Dist[B/(a*d),Int[Cosh[c+d*x]/(a+b*Sinh[c+d*x]),x]] /;
FreeQ[{a,b,c,d,A,B},x] && ZeroQ[a*A+b*B]


(* ::Code:: *)
Int[x_*(A_+B_.*Cosh[c_.+d_.*x_])/(a_+b_.*Cosh[c_.+d_.*x_])^2,x_Symbol] :=
  B*x*Sinh[c+d*x]/(a*d*(a+b*Cosh[c+d*x])) -
  Dist[B/(a*d),Int[Sinh[c+d*x]/(a+b*Cosh[c+d*x]),x]] /;
FreeQ[{a,b,c,d,A,B},x] && ZeroQ[a*A-b*B]


(* ::PageBreak:: *)
(**)


(* ::Title::Bold::Closed:: *)
(*\[Integral]Sinh[a+b x]^m Tanh[a+b x]^n \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Reference: G&R 2.423.18'*)


(* ::Subsubsection:: *)
(*Derivation: Algebraic expansion*)


(* ::Subsubsection:: *)
(*Basis: Sinh[z] Tanh[z]=Cosh[z]-Sech[z]*)


(* ::Subsubsection:: *)
(*Rule:*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]Sinh[a+b x] Tanh[a+b x]\[DifferentialD]x  \[LongRightArrow]  (Sinh[a+b x]/b)-\[Integral]Sech[a+b x]\[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[Sinh[a_.+b_.*x_]*Tanh[a_.+b_.*x_],x_Symbol] :=
  Sinh[a+b*x]/b - Int[Sech[a+b*x],x] /;
FreeQ[{a,b},x]


(* ::Subsubsection:: *)
(*Reference: G&R 2.423.34'*)


(* ::Code:: *)
Int[Cosh[a_.+b_.*x_]*Coth[a_.+b_.*x_],x_Symbol] :=
  Cosh[a+b*x]/b + Int[Csch[a+b*x],x] /;
FreeQ[{a,b},x]


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Rule: If  m+n-1=0, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]Sinh[a+b x]^m Tanh[a+b x]^n \[DifferentialD]x  \[LongRightArrow]  ((Sinh[a+b x]^m Tanh[a+b x]^(n-1))/(b m))*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[Sinh[a_.+b_.*x_]^m_*Tanh[a_.+b_.*x_]^n_,x_Symbol]:=
  Sinh[a+b*x]^m*Tanh[a+b*x]^(n-1)/(b*m) /;
FreeQ[{a,b,m,n},x] && ZeroQ[m+n-1]


(* ::Code:: *)
Int[Cosh[a_.+b_.*x_]^m_*Coth[a_.+b_.*x_]^n_,x_Symbol] :=
  Cosh[a+b*x]^m*Coth[a+b*x]^(n-1)/(b*m) /;
FreeQ[{a,b,m,n},x] && ZeroQ[m+n-1]


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Derivation: Integration by substitution*)


(* ::Subsubsection:: *)
(*Basis: If  m,n,(m+n-1)/2\[Element]\[DoubleStruckCapitalZ], then Sinh[z]^m Tanh[z]^n=(-1+Cosh[z]^2)^((m+n-1)/2)/Cosh[z]^n \!\( *)
(*\*SubscriptBox[\(\[PartialD]\), \(z\)]\(Cosh[z]\)\)*)


(* ::Subsubsection:: *)
(*Note: This rule is used if  m+n  is odd since it requires fewer steps and results in a simpler antiderivative than the other rules in this section.*)


(* ::Subsubsection:: *)
(*Rule: If  m,n,(m+n-1)/2\[Element]\[DoubleStruckCapitalZ], then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]Sinh[a+b x]^m Tanh[a+b x]^n \[DifferentialD]x  \[LongRightArrow]  (1/b)Subst[\[Integral](-1+x^2)^((m+n-1)/2)/x^n \[DifferentialD]x,x,Cosh[a+b x]]*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[Sinh[a_.+b_.*x_]^m_.*Tanh[a_.+b_.*x_]^n_.,x_Symbol] :=
  Dist[1/b,Subst[Int[Regularize[(-1+x^2)^((m+n-1)/2)/x^n,x],x],x,Cosh[a+b*x]]] /;
FreeQ[{a,b},x] && IntegersQ[m,n,(m+n-1)/2]


(* ::Subsubsection:: *)
(*Basis: If  m,n,(m+n-1)/2\[Element]\[DoubleStruckCapitalZ], then Cosh[z]^m Coth[z]^n=(1+Sinh[z]^2)^((m+n-1)/2)/Sinh[z]^n \!\( *)
(*\*SubscriptBox[\(\[PartialD]\), \(z\)]\(Sinh[z]\)\)*)


(* ::Code:: *)
Int[Cosh[a_.+b_.*x_]^m_.*Coth[a_.+b_.*x_]^n_.,x_Symbol] :=
  Dist[1/b,Subst[Int[Regularize[(1+x^2)^((m+n-1)/2)/x^n,x],x],x,Sinh[a+b*x]]] /;
FreeQ[{a,b},x] && IntegersQ[m,n,(m+n-1)/2]


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Reference: G&R 2.411.1, CRC 567a*)


(* ::Subsubsection:: *)
(*Rule: If  m>1 \[And] n<-1, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]Sinh[a+b x]^m Tanh[a+b x]^n \[DifferentialD]x  \[LongRightArrow]  ((Sinh[a+b x]^m Tanh[a+b x]^(n+1))/(b m))-(n+1)/m \[Integral]Sinh[a+b x]^(m-2) Tanh[a+b x]^(n+2) \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[Sinh[a_.+b_.*x_]^m_*Tanh[a_.+b_.*x_]^n_,x_Symbol] :=
  Sinh[a+b*x]^m*Tanh[a+b*x]^(n+1)/(b*m) - 
  Dist[(n+1)/m,Int[Sinh[a+b*x]^(m-2)*Tanh[a+b*x]^(n+2),x]] /;
FreeQ[{a,b},x] && RationalQ[{m,n}] && m>1 && n<-1


(* ::Subsubsection:: *)
(*Reference: G&R 2.411.2, CRC 567b*)


(* ::Code:: *)
Int[Cosh[a_.+b_.*x_]^m_*Coth[a_.+b_.*x_]^n_,x_Symbol] :=
  Cosh[a+b*x]^m*Coth[a+b*x]^(n+1)/(b*m) + 
  Dist[(n+1)/m,Int[Cosh[a+b*x]^(m-2)*Coth[a+b*x]^(n+2),x]] /;
FreeQ[{a,b},x] && RationalQ[{m,n}] && m>1 && n<-1


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Reference: G&R 2.411.6, CRC 568b*)


(* ::Subsubsection:: *)
(*Rule: If  m<-1 \[And] n>1, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]Sinh[a+b x]^m Tanh[a+b x]^n \[DifferentialD]x  \[LongRightArrow]  ((Sinh[a+b x]^(m+2) Tanh[a+b x]^(n-1))/(b (n-1)))-(m+2)/(n-1) \[Integral]Sinh[a+b x]^(m+2) Tanh[a+b x]^(n-2) \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[Sinh[a_.+b_.*x_]^m_*Tanh[a_.+b_.*x_]^n_,x_Symbol] :=
  Sinh[a+b*x]^(m+2)*Tanh[a+b*x]^(n-1)/(b*(n-1)) - 
  Dist[(m+2)/(n-1),Int[Sinh[a+b*x]^(m+2)*Tanh[a+b*x]^(n-2),x]] /;
FreeQ[{a,b},x] && RationalQ[{m,n}] && m<-1 && n>1


(* ::Subsubsection:: *)
(*Reference: G&R 2.411.5, CRC 568a*)


(* ::Code:: *)
Int[Cosh[a_.+b_.*x_]^m_*Coth[a_.+b_.*x_]^n_,x_Symbol] :=
  -Cosh[a+b*x]^(m+2)*Coth[a+b*x]^(n-1)/(b*(n-1)) + 
  Dist[(m+2)/(n-1),Int[Cosh[a+b*x]^(m+2)*Coth[a+b*x]^(n-2),x]] /;
FreeQ[{a,b},x] && RationalQ[{m,n}] && m<-1 && n>1


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Reference: G&R 2.411.2, CRC 567b*)


(* ::Subsubsection:: *)
(*Rule: If  m>1, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]Sinh[a+b x]^m Tanh[a+b x]^n \[DifferentialD]x  \[LongRightArrow]  ((Sinh[a+b x]^m Tanh[a+b x]^(n-1))/(b m))-(m+n-1)/m \[Integral]Sinh[a+b x]^(m-2) Tanh[a+b x]^n \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[Sinh[a_.+b_.*x_]^m_*Tanh[a_.+b_.*x_]^n_.,x_Symbol]:=
  Sinh[a+b*x]^m*Tanh[a+b*x]^(n-1)/(b*m) - 
  Dist[(m+n-1)/m,Int[Sinh[a+b*x]^(m-2)*Tanh[a+b*x]^n,x]] /;
FreeQ[{a,b,n},x] && RationalQ[m] && m>1


(* ::Subsubsection:: *)
(*Reference: G&R 2.411.1, CRC 567a*)


(* ::Code:: *)
Int[Cosh[a_.+b_.*x_]^m_*Coth[a_.+b_.*x_]^n_.,x_Symbol] :=
  Cosh[a+b*x]^m*Coth[a+b*x]^(n-1)/(b*m) + 
  Dist[(m+n-1)/m,Int[Cosh[a+b*x]^(m-2)*Coth[a+b*x]^n,x]] /;
FreeQ[{a,b,n},x] && RationalQ[m] && m>1


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Reference: G&R 2.411.3*)


(* ::Subsubsection:: *)
(*Rule: If  n>1, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]Sinh[a+b x]^m Tanh[a+b x]^n \[DifferentialD]x  \[LongRightArrow]  -((Sinh[a+b x]^m Tanh[a+b x]^(n-1))/(b (n-1)))+(m+n-1)/(n-1) \[Integral]Sinh[a+b x]^m Tanh[a+b x]^(n-2) \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[Sinh[a_.+b_.*x_]^m_.*Tanh[a_.+b_.*x_]^n_,x_Symbol] :=
  -Sinh[a+b*x]^m*Tanh[a+b*x]^(n-1)/(b*(n-1)) + 
  Dist[(m+n-1)/(n-1),Int[Sinh[a+b*x]^m*Tanh[a+b*x]^(n-2),x]] /;
FreeQ[{a,b,m},x] && RationalQ[n] && n>1


(* ::Subsubsection:: *)
(*Reference: G&R 2.411.4*)


(* ::Code:: *)
Int[Cosh[a_.+b_.*x_]^m_.*Coth[a_.+b_.*x_]^n_,x_Symbol] :=
  -Cosh[a+b*x]^m*Coth[a+b*x]^(n-1)/(b*(n-1)) + 
  Dist[(m+n-1)/(n-1),Int[Cosh[a+b*x]^m*Coth[a+b*x]^(n-2),x]] /;
FreeQ[{a,b,m},x] && RationalQ[n] && n>1


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Reference: G&R 2.411.5, CRC 568a*)


(* ::Subsubsection:: *)
(*Rule: If  m<-1 \[And] m+n+1!=0, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]Sinh[a+b x]^m Tanh[a+b x]^n \[DifferentialD]x  \[LongRightArrow]  ((Sinh[a+b x]^(m+2) Tanh[a+b x]^(n-1))/(b (m+n+1)))-(m+2)/(m+n+1) \[Integral]Sinh[a+b x]^(m+2) Tanh[a+b x]^n \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[Sinh[a_.+b_.*x_]^m_*Tanh[a_.+b_.*x_]^n_.,x_Symbol]:=
  Sinh[a+b*x]^(m+2)*Tanh[a+b*x]^(n-1)/(b*(m+n+1)) - 
  Dist[(m+2)/(m+n+1),Int[Sinh[a+b*x]^(m+2)*Tanh[a+b*x]^n,x]] /;
FreeQ[{a,b,n},x] && RationalQ[m] && m<-1 && NonzeroQ[m+n+1]


(* ::Subsubsection:: *)
(*Reference: G&R 2.411.6, CRC 568b*)


(* ::Code:: *)
Int[Cosh[a_.+b_.*x_]^m_*Coth[a_.+b_.*x_]^n_.,x_Symbol] :=
  -Cosh[a+b*x]^(m+2)*Coth[a+b*x]^(n-1)/(b*(m+n+1)) + 
  Dist[(m+2)/(m+n+1),Int[Cosh[a+b*x]^(m+2)*Coth[a+b*x]^n,x]] /;
FreeQ[{a,b,n},x] && RationalQ[m] && m<-1 && NonzeroQ[m+n+1]


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Reference: G&R 2.411.4*)


(* ::Subsubsection:: *)
(*Rule: If  n<-1 \[And] m+n+1!=0, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]Sinh[a+b x]^m Tanh[a+b x]^n \[DifferentialD]x  \[LongRightArrow]  ((Sinh[a+b x]^m Tanh[a+b x]^(n+1))/(b (m+n+1)))+(n+1)/(m+n+1) \[Integral]Sinh[a+b x]^m Tanh[a+b x]^(n+2) \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[Sinh[a_.+b_.*x_]^m_.*Tanh[a_.+b_.*x_]^n_,x_Symbol]:=
  Sinh[a+b*x]^m*Tanh[a+b*x]^(n+1)/(b*(m+n+1)) +
  Dist[(n+1)/(m+n+1),Int[Sinh[a+b*x]^m*Tanh[a+b*x]^(n+2),x]] /;
FreeQ[{a,b,m},x] && RationalQ[n] && n<-1 && NonzeroQ[m+n+1]


(* ::Subsubsection:: *)
(*Reference: G&R 2.411.3*)


(* ::Code:: *)
Int[Cosh[a_.+b_.*x_]^m_.*Coth[a_.+b_.*x_]^n_,x_Symbol] :=
  Cosh[a+b*x]^m*Coth[a+b*x]^(n+1)/(b*(m+n+1)) +
  Dist[(n+1)/(m+n+1),Int[Cosh[a+b*x]^m*Coth[a+b*x]^(n+2),x]] /;
FreeQ[{a,b,m},x] && RationalQ[n] && n<-1 && NonzeroQ[m+n+1]


(* ::PageBreak:: *)
(**)


(* ::Title::Bold::Closed:: *)
(*\[Integral]u Sinh[v] Hyper[w]\[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Derivation: Algebraic expansion*)


(* ::Subsubsection:: *)
(*Basis: Sinh[v] Cosh[w]=1/2 Sinh[v+w]+1/2 Sinh[v-w]*)


(* ::Subsubsection:: *)
(*Rule: If  v,w \[Element]\[DoubleStruckCapitalP]x \[And] v+w!=0 \[And] v-w!=0, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]u Sinh[v] Cosh[w]\[DifferentialD]x  \[LongRightArrow]  (1/2)\[Integral]u Sinh[v+w]\[DifferentialD]x+1/2 \[Integral]u Sinh[v-w]\[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[u_.*Sinh[v_]*Cosh[w_],x_Symbol] :=
  Dist[1/2,Int[u*Regularize[Sinh[v+w],x],x]] + 
  Dist[1/2,Int[u*Regularize[Sinh[v-w],x],x]] /;
(PolynomialQ[v,x] && PolynomialQ[w,x] || IndependentQ[Cancel[v/w],x]) && NonzeroQ[v+w] && NonzeroQ[v-w]


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Derivation: Algebraic expansion*)


(* ::Subsubsection:: *)
(*Basis: Sinh[v] Sinh[w]=1/2 Cosh[v+w]-1/2 Cosh[v-w]*)


(* ::Subsubsection:: *)
(*Rule: If  v,w \[Element]\[DoubleStruckCapitalP]x \[And] v+w!=0 \[And] v-w!=0, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]u Sinh[v] Sinh[w]\[DifferentialD]x  \[LongRightArrow]  (1/2)\[Integral]u Cosh[v+w]\[DifferentialD]x-1/2 \[Integral]u Cosh[v-w]\[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[u_.*Sinh[v_]*Sinh[w_],x_Symbol] :=
  Dist[1/2,Int[u*Regularize[Cosh[v+w],x],x]] - 
  Dist[1/2,Int[u*Regularize[Cosh[v-w],x],x]] /;
(PolynomialQ[v,x] && PolynomialQ[w,x] || IndependentQ[Cancel[v/w],x]) && NonzeroQ[v+w] && NonzeroQ[v-w]


(* ::Subsubsection:: *)
(*Basis: Cosh[v] Cosh[w]=1/2 Cosh[v-w]+1/2 Cosh[v+w]*)


(* ::Code:: *)
Int[u_.*Cosh[v_]*Cosh[w_],x_Symbol] :=
  Dist[1/2,Int[u*Regularize[Cosh[v-w],x],x]] + 
  Dist[1/2,Int[u*Regularize[Cosh[v+w],x],x]] /;
(PolynomialQ[v,x] && PolynomialQ[w,x] || IndependentQ[Cancel[v/w],x]) && NonzeroQ[v+w] && NonzeroQ[v-w]


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Derivation: Algebraic expansion*)


(* ::Subsubsection:: *)
(*Basis: Sinh[v] Tanh[w]=Cosh[v]-Cosh[v-w] Sech[w]*)


(* ::Subsubsection:: *)
(*Rule: If  n>0 \[And] x\[NotElement]v-w!=0, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]u Sinh[v] Tanh[w]^n \[DifferentialD]x  \[LongRightArrow]  \[Integral]u Cosh[v] Tanh[w]^(n-1) \[DifferentialD]x-Cosh[v-w] \[Integral]u Sech[w] Tanh[w]^(n-1) \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[u_.*Sinh[v_]*Tanh[w_]^n_.,x_Symbol] :=
  Int[u*Cosh[v]*Tanh[w]^(n-1),x] - Cosh[v-w]*Int[u*Sech[w]*Tanh[w]^(n-1),x] /;
RationalQ[n] && n>0 && FreeQ[v-w,x] && NonzeroQ[v-w]


(* ::Subsubsection:: *)
(*Basis: Cosh[v] Coth[w]=Sinh[v]+Cosh[v-w] Csch[w]*)


(* ::Code:: *)
Int[u_.*Cosh[v_]*Coth[w_]^n_.,x_Symbol] :=
  Int[u*Sinh[v]*Coth[w]^(n-1),x] + Cosh[v-w]*Int[u*Csch[w]*Coth[w]^(n-1),x] /;
RationalQ[n] && n>0 && FreeQ[v-w,x] && NonzeroQ[v-w]


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Derivation: Algebraic expansion*)


(* ::Subsubsection:: *)
(*Basis: Sinh[v] Coth[w]=Cosh[v]+Sinh[v-w] Csch[w]*)


(* ::Subsubsection:: *)
(*Rule: If  n>0 \[And] x\[NotElement]v-w!=0, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]u Sinh[v] Coth[w]^n \[DifferentialD]x  \[LongRightArrow]  \[Integral]u Cosh[v] Coth[w]^(n-1) \[DifferentialD]x+Sinh[v-w] \[Integral]u Csch[w] Coth[w]^(n-1) \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[u_.*Sinh[v_]*Coth[w_]^n_.,x_Symbol] :=
  Int[u*Cosh[v]*Coth[w]^(n-1),x] + Sinh[v-w]*Int[u*Csch[w]*Coth[w]^(n-1),x] /;
RationalQ[n] && n>0 && FreeQ[v-w,x] && NonzeroQ[v-w]


(* ::Subsubsection:: *)
(*Basis: Cosh[v] Tanh[w]=Sinh[v]-Sinh[v-w] Sech[w]*)


(* ::Code:: *)
Int[u_.*Cosh[v_]*Tanh[w_]^n_.,x_Symbol] :=
  Int[u*Sinh[v]*Tanh[w]^(n-1),x] - Sinh[v-w]*Int[u*Sech[w]*Tanh[w]^(n-1),x] /;
RationalQ[n] && n>0 && FreeQ[v-w,x] && NonzeroQ[v-w]


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Derivation: Algebraic expansion*)


(* ::Subsubsection:: *)
(*Basis: Sinh[v] Sech[w]=Cosh[v-w] Tanh[w]+Sinh[v-w]*)


(* ::Subsubsection:: *)
(*Rule: If  n>0 \[And] x\[NotElement]v-w!=0, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]u Sinh[v] Sech[w]^n \[DifferentialD]x  \[LongRightArrow]  Cosh[v-w] \[Integral]u Tanh[w] Sech[w]^(n-1) \[DifferentialD]x+Sinh[v-w] \[Integral]u Sech[w]^(n-1) \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[u_.*Sinh[v_]*Sech[w_]^n_.,x_Symbol] :=
  Cosh[v-w]*Int[u*Tanh[w]*Sech[w]^(n-1),x] + Sinh[v-w]*Int[u*Sech[w]^(n-1),x] /;
RationalQ[n] && n>0 && FreeQ[v-w,x] && NonzeroQ[v-w]


(* ::Subsubsection:: *)
(*Basis: Cosh[v]*Csch[w]=Cosh[v-w]*Coth[w]+Sinh[v-w]*)


(* ::Code:: *)
Int[u_.*Cosh[v_]*Csch[w_]^n_.,x_Symbol] :=
  Cosh[v-w]*Int[u*Coth[w]*Csch[w]^(n-1),x] + Sinh[v-w]*Int[u*Csch[w]^(n-1),x] /;
RationalQ[n] && n>0 && FreeQ[v-w,x] && NonzeroQ[v-w]


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Derivation: Algebraic expansion*)


(* ::Subsubsection:: *)
(*Basis: Sinh[v] Csch[w]=Sinh[v-w] Coth[w]+Cosh[v-w]*)


(* ::Subsubsection:: *)
(*Rule: If  n>0 \[And] x\[NotElement]v-w!=0, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]u Sinh[v] Csch[w]^n \[DifferentialD]x  \[LongRightArrow]  Sinh[v-w] \[Integral]u Coth[w] Csch[w]^(n-1) \[DifferentialD]x+Cosh[v-w] \[Integral]u Csch[w]^(n-1) \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[u_.*Sinh[v_]*Csch[w_]^n_.,x_Symbol] :=
  Sinh[v-w]*Int[u*Coth[w]*Csch[w]^(n-1),x] + Cosh[v-w]*Int[u*Csch[w]^(n-1),x] /;
RationalQ[n] && n>0 && FreeQ[v-w,x] && NonzeroQ[v-w]


(* ::Subsubsection:: *)
(*Basis: Cosh[v] Sech[w]=Sinh[v-w] Tanh[w]+Cosh[v-w]*)


(* ::Code:: *)
Int[u_.*Cosh[v_]*Sech[w_]^n_.,x_Symbol] :=
  Sinh[v-w]*Int[u*Tanh[w]*Sech[w]^(n-1),x] + Cosh[v-w]*Int[u*Sech[w]^(n-1),x] /;
RationalQ[n] && n>0 && FreeQ[v-w,x] && NonzeroQ[v-w]


(* ::PageBreak:: *)
(**)


(* ::Title::Bold::Closed:: *)
(*\[Integral]x^m Sinh[a+b x^n]^p Cosh[a+b x^n]\[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Reference: G&R 2.479.6*)


(* ::Subsubsection:: *)
(*Rule: If  m,n,p\[Element]\[DoubleStruckCapitalZ] \[And] p!=-1 \[And] 0<n<=m, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]x^m Sinh[a+b x^n]^p Cosh[a+b x^n]\[DifferentialD]x  \[LongRightArrow]  ((x^(m-n+1) Sinh[a+b x^n]^(p+1))/(b n (p+1)))-(m-n+1)/(b n (p+1)) \[Integral]x^(m-n) Sinh[a+b x^n]^(p+1) \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[x_^m_.*Sinh[a_.+b_.*x_^n_.]^p_.*Cosh[a_.+b_.*x_^n_.],x_Symbol] :=
  x^(m-n+1)*Sinh[a+b*x^n]^(p+1)/(b*n*(p+1)) -
  Dist[(m-n+1)/(b*n*(p+1)),Int[x^(m-n)*Sinh[a+b*x^n]^(p+1),x]] /;
FreeQ[{a,b},x] && IntegersQ[m,n,p] && p!=-1 && 0<n<=m


(* ::Subsubsection:: *)
(*Reference: G&R 2.479.3*)


(* ::Code:: *)
Int[x_^m_.*Cosh[a_.+b_.*x_^n_.]^p_.*Sinh[a_.+b_.*x_^n_.],x_Symbol] :=
  x^(m-n+1)*Cosh[a+b*x^n]^(p+1)/(b*n*(p+1)) -
  Dist[(m-n+1)/(b*n*(p+1)),Int[x^(m-n)*Cosh[a+b*x^n]^(p+1),x]] /;
FreeQ[{a,b},x] && IntegersQ[m,n,p] && p!=-1 && 0<n<=m


(* ::PageBreak:: *)
(**)


(* ::Subsubsection:: *)
(**)


(* ::Title::Bold::Closed:: *)
(*\[Integral]Sinh[a+b x]^m Cosh[a+b x]^n \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Reference: G&R 2.411.5, CRC 568a, A&S 4.5.86a with m+n+2=0*)


(* ::Subsubsection:: *)
(*Rule: If  m+n+2=0 \[And] m+1!=0, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]Sinh[a+b x]^m Cosh[a+b x]^n \[DifferentialD]x  \[LongRightArrow]  ((Sinh[a+b x]^(m+1) Cosh[a+b x]^(n+1))/(b (m+1)))*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[Sinh[a_.+b_.*x_]^m_.*Cosh[a_.+b_.*x_]^n_,x_Symbol] :=
  Sinh[a+b*x]^(m+1)*Cosh[a+b*x]^(n+1)/(b*(m+1)) /;
FreeQ[{a,b,m,n},x] && ZeroQ[m+n+2] && NonzeroQ[m+1]


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Derivation: Integration by substitution*)


(* ::Subsubsection:: *)
(*Basis: If (n-1)/2\[Element]\[DoubleStruckCapitalZ], then Sinh[z]^m Cosh[z]^n=Sinh[z]^m (1+Sinh[z]^2)^((n-1)/2) Derivative[1][Sinh][z]*)


(* ::Subsubsection:: *)
(*Note: This rule is used for odd n since it requires fewer steps and results in a simpler antiderivative than the other rules in this section.*)


(* ::Subsubsection:: *)
(*Rule: If (n-1)/2\[Element]\[DoubleStruckCapitalZ] \[And] \[Not]((m-1)/2\[Element]\[DoubleStruckCapitalZ] \[And] 0<m<n), then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]Sinh[a+b x]^m Cosh[a+b x]^n \[DifferentialD]x  \[LongRightArrow]  (1/b)Subst[\[Integral]x^m (1+x^2)^((n-1)/2) \[DifferentialD]x,x,Sinh[a+b x]]*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[Sinh[a_.+b_.*x_]^m_*Cosh[a_.+b_.*x_]^n_,x_Symbol] :=
  Dist[1/b,Subst[Int[Regularize[x^m*(1+x^2)^((n-1)/2),x],x],x,Sinh[a+b*x]]] /;
FreeQ[{a,b,m},x] && OddQ[n] && Not[OddQ[m] && 0<m<n]


(* ::Subsubsection:: *)
(*Basis: If (m-1)/2\[Element]\[DoubleStruckCapitalZ], then Sinh[z]^m Cosh[z]^n=Cosh[z]^n (-1+Cosh[z]^2)^((m-1)/2) Derivative[1][Cosh][z]*)


(* ::Code:: *)
Int[Sinh[a_.+b_.*x_]^m_*Cosh[a_.+b_.*x_]^n_,x_Symbol] :=
  Dist[1/b,Subst[Int[Regularize[x^n*(-1+x^2)^((m-1)/2),x],x],x,Cosh[a+b*x]]] /;
FreeQ[{a,b,n},x] && OddQ[m] && Not[OddQ[n] && 0<n<=m]


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Reference: G&R 2.411.3*)


(* ::Subsubsection:: *)
(*Rule: If  m>1 \[And] n<-1, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]Sinh[a+b x]^m Cosh[a+b x]^n \[DifferentialD]x  \[LongRightArrow]  ((Sinh[a+b x]^(m-1) Cosh[a+b x]^(n+1))/(b (n+1)))-(m-1)/(n+1) \[Integral]Sinh[a+b x]^(m-2) Cosh[a+b x]^(n+2) \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[Sinh[a_.+b_.*x_]^m_*Cosh[a_.+b_.*x_]^n_,x_Symbol] :=
  Sinh[a+b*x]^(m-1)*Cosh[a+b*x]^(n+1)/(b*(n+1)) - 
  Dist[(m-1)/(n+1),Int[Sinh[a+b*x]^(m-2)*Cosh[a+b*x]^(n+2),x]] /;
FreeQ[{a,b},x] && RationalQ[{m,n}] && m>1 && n<-1


(* ::Subsubsection:: *)
(*Reference: G&R 2.411.4*)


(* ::Code:: *)
Int[Sinh[a_.+b_.*x_]^m_*Cosh[a_.+b_.*x_]^n_,x_Symbol] :=
  Sinh[a+b*x]^(m+1)*Cosh[a+b*x]^(n-1)/(b*(m+1)) - 
  Dist[(n-1)/(m+1),Int[Sinh[a+b*x]^(m+2)*Cosh[a+b*x]^(n-2),x]] /;
FreeQ[{a,b},x] && RationalQ[{m,n}] && m<-1 && n>1


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Reference: G&R 2.411.2, CRC 567b, A&S 4.5.85b*)


(* ::Subsubsection:: *)
(*Rule: If  m>1 \[And] (m-1)/2\[NotElement]\[DoubleStruckCapitalZ] \[And] m+n!=0 \[And] \[Not]((n-1)/2\[Element]\[DoubleStruckCapitalZ] \[And] n>1), then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]Sinh[a+b x]^m Cosh[a+b x]^n \[DifferentialD]x  \[LongRightArrow]  ((Sinh[a+b x]^(m-1) Cosh[a+b x]^(n+1))/(b (m+n)))-(m-1)/(m+n) \[Integral]Sinh[a+b x]^(m-2) Cosh[a+b x]^n \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[Sinh[a_.+b_.*x_]^m_*Cosh[a_.+b_.*x_]^n_,x_Symbol] :=
  Sinh[a+b*x]^(m-1)*Cosh[a+b*x]^(n+1)/(b*(m+n)) -
  Dist[(m-1)/(m+n),Int[Sinh[a+b*x]^(m-2)*Cosh[a+b*x]^n,x]] /;
FreeQ[{a,b,n},x] && RationalQ[m] && m>1 && NonzeroQ[m+n]


(* ::Subsubsection:: *)
(*Reference: G&R 2.411.1, CRC 567a, A&S 4.5.85a*)


(* ::Code:: *)
Int[Sinh[a_.+b_.*x_]^m_*Cosh[a_.+b_.*x_]^n_,x_Symbol] :=
  Sinh[a+b*x]^(m+1)*Cosh[a+b*x]^(n-1)/(b*(m+n)) +
  Dist[(n-1)/(m+n),Int[Sinh[a+b*x]^m*Cosh[a+b*x]^(n-2),x]] /;
FreeQ[{a,b,m},x] && RationalQ[n] && n>1 && NonzeroQ[m+n]


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Reference: G&R 2.411.5, CRC 568a, A&S 4.5.86a*)


(* ::Subsubsection:: *)
(*Rule: If  m<-1 \[And] m+n+2!=0, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]Sinh[a+b x]^m Cosh[a+b x]^n \[DifferentialD]x  \[LongRightArrow]  ((Sinh[a+b x]^(m+1) Cosh[a+b x]^(n+1))/(b (m+1)))-(m+n+2)/(m+1) \[Integral]Sinh[a+b x]^(m+2) Cosh[a+b x]^n \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[Sinh[a_.+b_.*x_]^m_*Cosh[a_.+b_.*x_]^n_,x_Symbol] :=
  Sinh[a+b*x]^(m+1)*Cosh[a+b*x]^(n+1)/(b*(m+1)) - 
  Dist[(m+n+2)/(m+1),Int[Sinh[a+b*x]^(m+2)*Cosh[a+b*x]^n,x]] /;
FreeQ[{a,b,n},x] && RationalQ[m] && m<-1 && NonzeroQ[m+n+2]


(* ::Subsubsection:: *)
(*Reference: G&R 2.411.6, CRC 568b, A&S 4.5.86b*)


(* ::Code:: *)
Int[Sinh[a_.+b_.*x_]^m_*Cosh[a_.+b_.*x_]^n_,x_Symbol] :=
  -Sinh[a+b*x]^(m+1)*Cosh[a+b*x]^(n+1)/(b*(n+1)) +
  Dist[(m+n+2)/(n+1),Int[Sinh[a+b*x]^m*Cosh[a+b*x]^(n+2),x]] /;
FreeQ[{a,b,m},x] && RationalQ[n] && n<-1 && NonzeroQ[m+n+2]


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Derivation: Integration by substitution*)


(* ::Subsubsection:: *)
(*Basis: If 1/m\[Element]\[DoubleStruckCapitalZ], then Sinh[z]^m/Cosh[z]^m=(Sinh[z]^m/Cosh[z]^m)^(1/m)/(m (1-(Sinh[z]^m/Cosh[z]^m)^(2/m))) \!\( *)
(*\*SubscriptBox[\(\[PartialD]\), \(z\)]*)
(*\*FractionBox[*)
(*SuperscriptBox[\(Sinh[z]\), \(m\)], *)
(*SuperscriptBox[\(Cosh[z]\), \(m\)]]\)*)


(* ::Subsubsection:: *)
(*Note: This rule should be replaced with a more general one.*)


(* ::Subsubsection:: *)
(*Rule: If  1/m\[Element]\[DoubleStruckCapitalZ] \[And] 1/m>1, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]Sinh[a+b x]^m/Cosh[a+b x]^m \[DifferentialD]x  \[LongRightArrow]  (1/(b m))Subst[\[Integral]x^(1/m)/(1-x^(2/m)) \[DifferentialD]x,x,Sinh[a+b x]^m/Cosh[a+b x]^m]*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[Sinh[a_.+b_.*x_]^m_*Cosh[a_.+b_.*x_]^n_,x_Symbol] :=
  Dist[1/(b*m),Subst[Int[x^(1/m)/(1-x^(2/m)),x],x,Sinh[a+b*x]^m/Cosh[a+b*x]^m]] /;
FreeQ[{a,b},x] && ZeroQ[m+n] && IntegerQ[1/m] && 1/m>1


(* ::Subsubsection:: *)
(*Basis: If 1/n\[Element]\[DoubleStruckCapitalZ], then Cosh[z]^n/Sinh[z]^n=(Cosh[z]^n/Sinh[z]^n)^(1/n)/(n (1-(Cosh[z]^n/Sinh[z]^n)^(2/n))) \!\( *)
(*\*SubscriptBox[\(\[PartialD]\), \(z\)]*)
(*\*FractionBox[*)
(*SuperscriptBox[\(Cosh[z]\), \(n\)], *)
(*SuperscriptBox[\(Sinh[z]\), \(n\)]]\)*)


(* ::Code:: *)
Int[Sinh[a_.+b_.*x_]^m_*Cosh[a_.+b_.*x_]^n_,x_Symbol] :=
  Dist[1/(b*n),Subst[Int[x^(1/n)/(1-x^(2/n)),x],x,Cosh[a+b*x]^n/Sinh[a+b*x]^n]] /;
FreeQ[{a,b},x] && ZeroQ[m+n] && IntegerQ[1/n] && 1/n>1


(* ::PageBreak:: *)
(**)


(* ::Title::Bold::Closed:: *)
(*\[Integral]x^m (a+b Cosh[d+e x]^2+c Sinh[d+e x]^2)^n \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Derivation: Algebraic simplification*)


(* ::Subsubsection:: *)
(*Basis: a+b Cosh[z]^2+c Sinh[z]^2=1/2 (2 a+b-c+(b+c) Cosh[2 z])*)


(* ::Subsubsection:: *)
(*Rule: If  m\[Element]\[DoubleStruckCapitalZ] \[And] m>0 \[And] a+b!=0 \[And] a+c!=0, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]x^m/(a+b Cosh[d+e x]^2+c Sinh[d+e x]^2) \[DifferentialD]x  \[LongRightArrow]  2\[Integral]x^m/(2 a+b-c+(b+c) Cosh[2 d+2 e x]) \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[x_^m_./(a_.+b_.*Cosh[d_.+e_.*x_]^2+c_.*Sinh[d_.+e_.*x_]^2),x_Symbol] :=
  Dist[2,Int[x^m/(2*a+b-c+(b+c)*Cosh[2*d+2*e*x]),x]] /;
FreeQ[{a,b,c,d,e},x] && IntegerQ[m] && m>0 && NonzeroQ[a+b] && NonzeroQ[a+c]


(* ::PageBreak:: *)
(**)


(* ::Title::Bold::Closed:: *)
(*\[Integral]x^m (a+b Sinh[c+d x] Cosh[c+d x])^n \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Derivation: Algebraic simplification*)


(* ::Subsubsection:: *)
(*Basis: Sinh[z] Cosh[z]=1/2 Sinh[2 z]*)


(* ::Subsubsection:: *)
(*Rule: If  m\[Element]\[DoubleStruckCapitalZ] \[And] m>0, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]x^m/(a+b Sinh[c+d x] Cosh[c+d x]) \[DifferentialD]x  \[LongRightArrow]  \[Integral]x^m/(a+1/2 b Sinh[2 c+2 d x]) \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[x_^m_./(a_+b_.*Sinh[c_.+d_.*x_]*Cosh[c_.+d_.*x_]),x_Symbol] :=
  Int[x^m/(a+b*Sinh[2*c+2*d*x]/2),x] /;
FreeQ[{a,b,c,d},x] && IntegerQ[m] && m>0


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Derivation: Algebraic simplification*)


(* ::Subsubsection:: *)
(*Basis: Sinh[z] Cosh[z]=1/2 Sinh[2 z]*)


(* ::Subsubsection:: *)
(*Rule: If  n-1/2\[Element]\[DoubleStruckCapitalZ], then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral](a+b Sinh[c+d x] Cosh[c+d x])^n \[DifferentialD]x  \[LongRightArrow]  \[Integral](a+1/2 b Sinh[2 c+2 d x])^n \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[(a_+b_.*Sinh[c_.+d_.*x_]*Cosh[c_.+d_.*x_])^n_,x_Symbol] :=
  Int[(a+b*Sinh[2*c+2*d*x]/2)^n,x] /;
FreeQ[{a,b,c,d},x] && HalfIntegerQ[n]


(* ::PageBreak:: *)
(**)


(* ::Title::Bold::Closed:: *)
(*\[Integral]Sinh[a+b x^n]^p Cosh[a+b x^n]^p \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Derivation: Algebraic simplification*)


(* ::Subsubsection:: *)
(*Basis: Sinh[z] Cosh[z]=1/2 Sinh[2 z]*)


(* ::Subsubsection:: *)
(*Rule: If  n,p\[Element]\[DoubleStruckCapitalZ], then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]Sinh[a+b x^n]^p Cosh[a+b x^n]^p \[DifferentialD]x  \[LongRightArrow]  (1/2)\[Integral]Sinh[2 a+2 b x^n]^p \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[Sinh[a_.+b_.*x_^n_]^p_.*Cosh[a_.+b_.*x_^n_]^p_.,x_Symbol] :=
  Dist[1/2,Int[Sinh[2*a+2*b*x^n]^p,x]] /;
FreeQ[{a,b},x] && IntegersQ[n,p]


(* ::PageBreak:: *)
(**)


(* ::Subsubsection:: *)
(**)


(* ::Title::Bold::Closed:: *)
(*\[Integral](a Csch[c+d x]+a Sinh[c+d x])^n \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Derivation: Algebraic simplification*)


(* ::Subsubsection:: *)
(*Basis: Csch[z]+Sinh[z]=Cosh[z] Coth[z]*)


(* ::Subsubsection:: *)
(*Rule:*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral](a Csch[c+d x]+a Sinh[c+d x])^n \[DifferentialD]x  \[LongRightArrow]  \[Integral](a Cosh[c+d x] Coth[c+d x])^n \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[(a_.*Csch[c_.+d_.*x_]+b_.*Sinh[c_.+d_.*x_])^n_,x_Symbol] :=
  Int[(a*Cosh[c+d*x]*Coth[c+d*x])^n,x] /;
FreeQ[{a,b,c,d,n},x] && ZeroQ[a-b]


(* ::Code:: *)
Int[(a_.*Sech[c_.+d_.*x_]+b_.*Cosh[c_.+d_.*x_])^n_,x_Symbol] :=
  Int[(-a*Sinh[c+d*x]*Tanh[c+d*x])^n,x] /;
FreeQ[{a,b,c,d,n},x] && ZeroQ[a+b]


(* ::PageBreak:: *)
(**)


(* ::Title::Bold::Closed:: *)
(*\[Integral]Sech[v]^m (a+b Tanh[v])^n \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Derivation: Algebraic simplification*)


(* ::Subsubsection:: *)
(*Basis: (a+b Tanh[z])/Sech[z]=a Cosh[z]+b Sinh[z]*)


(* ::Subsubsection:: *)
(*Rule: If  m,n\[Element]\[DoubleStruckCapitalZ] \[And] m+n=0 \[And] (m-1)/2\[Element]\[DoubleStruckCapitalZ], then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]Sech[v]^m (a+b Tanh[v])^n \[DifferentialD]x  \[LongRightArrow]  \[Integral](a Cosh[v]+b Sinh[v])^n \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[Sech[v_]^m_.*(a_+b_.*Tanh[v_])^n_., x_Symbol] :=
  Int[(a*Cosh[v]+b*Sinh[v])^n,x] /;
FreeQ[{a,b},x] && IntegersQ[m,n] && m+n==0 && OddQ[m]


(* ::Code:: *)
Int[Csch[v_]^m_.*(a_+b_.*Coth[v_])^n_., x_Symbol] :=
  Int[(b*Cosh[v]+a*Sinh[v])^n,x] /;
FreeQ[{a,b},x] && IntegersQ[m,n] && m+n==0 && OddQ[m]


(* ::PageBreak:: *)
(**)


(* ::Title::Bold::Closed:: *)
(*\[Integral]x^m Csch[a+b x]^n Sech[a+b x]^p \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Derivation: Algebraic simplification*)


(* ::Subsubsection:: *)
(*Basis: Csch[z]Sech[z]=2 Csch[2 z]*)


(* ::Subsubsection:: *)
(*Rule: If  n\[Element]\[DoubleStruckCapitalZ], then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]x^m Csch[a+b x]^n Sech[a+b x]^n \[DifferentialD]x  \[LongRightArrow]  2^n\[Integral] x^m Csch[2a+2b x]^n \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[x_^m_.*Csch[a_.+b_.*x_]^n_.*Sech[a_.+b_.*x_]^n_., x_Symbol] :=
  Dist[2^n,Int[x^m*Csch[2*a+2*b*x]^n,x]] /;
FreeQ[{a,b},x] && RationalQ[m] && IntegerQ[n]


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Derivation: Integration by parts*)


(* ::Subsubsection:: *)
(*Rule: If  n,p\[Element]\[DoubleStruckCapitalZ] \[And] m>0 \[And] n!=p, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]x^m Csch[a+b x]^n Sech[a+b x]^p \[DifferentialD]x  \[LongRightArrow]  *)
(*x^m \[Integral]Csch[a+b x]^n Sech[a+b x]^p \[DifferentialD]x-m \[Integral]x^(m-1) (\[Integral]Csch[a+b x]^n Sech[a+b x]^p \[DifferentialD]x)\[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[x_^m_.*Csch[a_.+b_.*x_]^n_.*Sech[a_.+b_.*x_]^p_., x_Symbol] :=
  Module[{u=Block[{ShowSteps=False,StepCounter=Null}, Int[Csch[a+b*x]^n*Sech[a+b*x]^p,x]]},
  x^m*u - Dist[m,Int[x^(m-1)*u,x]]] /;
FreeQ[{a,b},x] && RationalQ[m] && IntegersQ[n,p] && m>0 && n!=p


(* ::PageBreak:: *)
(**)


(* ::Title::Bold::Closed:: *)
(*\[Integral]u (a Tanh[v]^m+b Sech[v]^m)^n \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Derivation: Algebraic simplification*)


(* ::Subsubsection:: *)
(*Basis: If  a^2+b^2=0, then a Tanh[z]+b Sech[z]=a Tanh[z/2-\[Pi]/4 a/b]*)


(* ::Subsubsection:: *)
(*Rule: If  a^2-b^2=0 \[And] n/2\[Element]\[DoubleStruckCapitalZ], then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral](a Tanh[v]+b Sech[v])^n \[DifferentialD]x  \[LongRightArrow]  a^n \[Integral]Tanh[v/2-\[Pi]/4 a/b]^n \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[(a_.*Tanh[v_]+b_.*Sech[v_])^n_,x_Symbol] :=
  Dist[a^n,Int[Tanh[v/2-Pi/4*a/b]^n,x]] /;
FreeQ[{a,b},x] && ZeroQ[a^2+b^2] && EvenQ[n]


(* ::Subsubsection:: *)
(*Basis: If  a^2-b^2=0, then a Coth[z]+b Csch[z]=a Coth[z/2+( \[Pi] I)/4 (a-b)/b]*)


(* ::Code:: *)
Int[(a_.*Coth[v_]+b_.*Csch[v_])^n_,x_Symbol] :=
  Dist[a^n,Int[Coth[v/2+Pi*I/4*(a-b)/b]^n,x]] /;
FreeQ[{a,b},x] && ZeroQ[a^2-b^2] && EvenQ[n]


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Derivation: Algebraic simplification*)


(* ::Subsubsection:: *)
(*Basis: a Sech[z]+b Tanh[z]=(a+b Sinh[z])/Cosh[z]*)


(* ::Subsubsection:: *)
(*Rule: If  m,n\[Element]\[DoubleStruckCapitalZ] \[And] ((m n-1)/2\[Element]\[DoubleStruckCapitalZ] \[Or] m n<0) \[And] \[Not](m=2 \[And] a-b=0), then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]u (a Tanh[v]^m+b Sech[v]^m)^n \[DifferentialD]x  \[LongRightArrow]  \[Integral](u (a+b Sinh[v]^m)^n)/Cosh[v]^(m n) \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[u_.*(a_.*Sech[v_]^m_.+b_.*Tanh[v_]^m_.)^n_.,x_Symbol] :=
  Int[u*(a+b*Sinh[v]^m)^n/Cosh[v]^(m*n),x] /;
FreeQ[{a,b},x] && IntegersQ[m,n] && (OddQ[m*n] || m*n<0) && Not[m==2 && ZeroQ[a-b]]


(* ::Code:: *)
Int[u_.*(a_.*Csch[v_]^m_.+b_.*Coth[v_]^m_.)^n_.,x_Symbol] :=
  Int[u*(a+b*Cosh[v]^m)^n/Sinh[v]^(m*n),x] /;
FreeQ[{a,b},x] && IntegersQ[m,n] && (OddQ[m*n] || m*n<0) && Not[m==2 && ZeroQ[a+b]]


(* ::PageBreak:: *)
(**)
