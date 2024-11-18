(* ::Package:: *)

(* ::Title::Bold::Closed:: *)
(*\[Integral]x^m Sec[a+b x]^n \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Derivation: Integration by parts*)


(* ::Subsubsection:: *)
(*Rule: If  m\[Element]\[DoubleStruckCapitalZ] \[And] m>0, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]x^m Sec[a+b x]\[DifferentialD]x  \[LongRightArrow]  -((2 I x^m ArcTan[E^(I a+I b x)])/b)+(2 I m)/b \[Integral]x^(m-1) ArcTan[E^(I a+I b x)]\[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[x_^m_.*Sec[a_.+b_.*x_],x_Symbol] :=
  -2*I*x^m*ArcTan[E^(I*a+I*b*x)]/b +
  Dist[2*I*m/b,Int[x^(m-1)*ArcTan[E^(I*a+I*b*x)],x]] /;
FreeQ[{a,b},x] && IntegerQ[m] && m>0


(* ::Code:: *)
Int[x_^m_.*Csc[a_.+b_.*x_],x_Symbol] :=
  -2*x^m*ArcTanh[E^(I*a+I*b*x)]/b +
  Dist[2*m/b,Int[x^(m-1)*ArcTanh[E^(I*a+I*b*x)],x]] /;
FreeQ[{a,b},x] && IntegerQ[m] && m>0


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Reference: CRC 430, A&S 4.3.125*)


(* ::Subsubsection:: *)
(*Rule: If  m>0, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]x^m Sec[a+b x]^2 \[DifferentialD]x  \[LongRightArrow]  ((x^m Tan[a+b x])/b)-m/b \[Integral]x^(m-1) Tan[a+b x]\[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[x_^m_.*Sec[a_.+b_.*x_]^2,x_Symbol] :=
  x^m*Tan[a+b*x]/b -
  Dist[m/b,Int[x^(m-1)*Tan[a+b*x],x]] /;
FreeQ[{a,b},x] && RationalQ[m] && m>0


(* ::Subsubsection:: *)
(*Reference: CRC 428, A&S 4.3.121*)


(* ::Code:: *)
Int[x_^m_.*Csc[a_.+b_.*x_]^2,x_Symbol] :=
  -x^m*Cot[a+b*x]/b +
  Dist[m/b,Int[x^(m-1)*Cot[a+b*x],x]] /;
FreeQ[{a,b},x] && RationalQ[m] && m>0


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Reference: G&R 2.643.2 special case when m=1, CRC 431, A&S 4.3.126*)


(* ::Subsubsection:: *)
(*Rule: If  n>1 \[And] n!=2, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]x Sec[a+b x]^n \[DifferentialD]x  \[LongRightArrow]  ((x Tan[a+b x] Sec[a+b x]^(n-2))/(b (n-1)))-Sec[a+b x]^(n-2)/(b^2 (n-1) (n-2))+(n-2)/(n-1) \[Integral]x Sec[a+b x]^(n-2) \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[x_*Sec[a_.+b_.*x_]^n_,x_Symbol] :=
  x*Tan[a+b*x]*Sec[a+b*x]^(n-2)/(b*(n-1)) -
  Sec[a+b*x]^(n-2)/(b^2*(n-1)*(n-2)) +
  Dist[(n-2)/(n-1),Int[x*Sec[a+b*x]^(n-2),x]] /;
FreeQ[{a,b},x] && RationalQ[n] && n>1 && n!=2


(* ::Subsubsection:: *)
(*Reference: G&R 2.643.1 special case when m=1, CRC 429', A&S 4.3.122*)


(* ::Code:: *)
Int[x_*Csc[a_.+b_.*x_]^n_,x_Symbol] :=
  -x*Cot[a+b*x]*Csc[a+b*x]^(n-2)/(b*(n-1)) -
  Csc[a+b*x]^(n-2)/(b^2*(n-1)*(n-2)) +
  Dist[(n-2)/(n-1),Int[x*Csc[a+b*x]^(n-2),x]] /;
FreeQ[{a,b},x] && RationalQ[n] && n>1 && n!=2


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Reference: G&R 2.643.2*)


(* ::Subsubsection:: *)
(*Rule: If  m>1 \[And] n>1 \[And] n!=2, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]x^m Sec[a+b x]^n \[DifferentialD]x  \[LongRightArrow]  ((x^m Tan[a+b x] Sec[a+b x]^(n-2))/(b (n-1)))-(m x^(m-1) Sec[a+b x]^(n-2))/(b^2 (n-1) (n-2))+                          *)
(*                                            (n-2)/(n-1) \[Integral]x^m Sec[a+b x]^(n-2) \[DifferentialD]x+(m (m-1))/(b^2 (n-1) (n-2)) \[Integral]x^(m-2) Sec[a+b x]^(n-2) \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[x_^m_*Sec[a_.+b_.*x_]^n_,x_Symbol] :=
  x^m*Tan[a+b*x]*Sec[a+b*x]^(n-2)/(b*(n-1)) -
  m*x^(m-1)*Sec[a+b*x]^(n-2)/(b^2*(n-1)*(n-2)) +
  Dist[(n-2)/(n-1),Int[x^m*Sec[a+b*x]^(n-2),x]] +
  Dist[m*(m-1)/(b^2*(n-1)*(n-2)),Int[x^(m-2)*Sec[a+b*x]^(n-2),x]] /;
FreeQ[{a,b},x] && RationalQ[{m,n}] && m>1 && n>1 && n!=2


(* ::Subsubsection:: *)
(*Reference: G&R 2.643.1*)


(* ::Code:: *)
Int[x_^m_*Csc[a_.+b_.*x_]^n_,x_Symbol] :=
  -x^m*Cot[a+b*x]*Csc[a+b*x]^(n-2)/(b*(n-1)) -
  m*x^(m-1)*Csc[a+b*x]^(n-2)/(b^2*(n-1)*(n-2)) +
  Dist[(n-2)/(n-1),Int[x^m*Csc[a+b*x]^(n-2),x]] +
  Dist[m*(m-1)/(b^2*(n-1)*(n-2)),Int[x^(m-2)*Csc[a+b*x]^(n-2),x]] /;
FreeQ[{a,b},x] && RationalQ[{m,n}] && m>1 && n>1 && n!=2


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Reference: G&R 2.631.3 special case when m=1*)


(* ::Subsubsection:: *)
(*Rule: If  n<-1, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]x Sec[a+b x]^n \[DifferentialD]x  \[LongRightArrow]  (Sec[a+b x]^n/(b^2 n^2))-(x Sin[a+b x] Sec[a+b x]^(n+1))/(b n)+(n+1)/n \[Integral]x Sec[a+b x]^(n+2) \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[x_*Sec[a_.+b_.*x_]^n_,x_Symbol] :=
  Sec[a+b*x]^n/(b^2*n^2) -
  x*Sin[a+b*x]*Sec[a+b*x]^(n+1)/(b*n) +
  Dist[(n+1)/n,Int[x*Sec[a+b*x]^(n+2),x]] /;
FreeQ[{a,b},x] && RationalQ[n] && n<-1


(* ::Subsubsection:: *)
(*Reference: G&R 2.631.2 special case when m=1*)


(* ::Code:: *)
Int[x_*Csc[a_.+b_.*x_]^n_,x_Symbol] :=
  Csc[a+b*x]^n/(b^2*n^2) +
  x*Cos[a+b*x]*Csc[a+b*x]^(n+1)/(b*n) +
  Dist[(n+1)/n,Int[x*Csc[a+b*x]^(n+2),x]] /;
FreeQ[{a,b},x] && RationalQ[n] && n<-1


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Reference: G&R 2.631.3*)


(* ::Subsubsection:: *)
(*Rule: If  m>1 \[And] n<-1, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]x^m Sec[a+b x]^n \[DifferentialD]x  \[LongRightArrow]  ((m x^(m-1) Sec[a+b x]^n)/(b^2 n^2))-(x^m Sin[a+b x] Sec[a+b x]^(n+1))/(b n)+                      *)
(*                                                                      (n+1)/n \[Integral]x^m Sec[a+b x]^(n+2) \[DifferentialD]x-(m (m-1))/(b^2 n^2) \[Integral]x^(m-2) Sec[a+b x]^n \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[x_^m_*Sec[a_.+b_.*x_]^n_,x_Symbol] :=
  m*x^(m-1)*Sec[a+b*x]^n/(b^2*n^2) -
  x^m*Sin[a+b*x]*Sec[a+b*x]^(n+1)/(b*n) +
  Dist[(n+1)/n,Int[x^m*Sec[a+b*x]^(n+2),x]] -
  Dist[m*(m-1)/(b^2*n^2),Int[x^(m-2)*Sec[a+b*x]^n,x]] /;
FreeQ[{a,b},x] && RationalQ[{m,n}] && m>1 && n<-1


(* ::Subsubsection:: *)
(*Reference: G&R 2.631.2*)


(* ::Code:: *)
Int[x_^m_*Csc[a_.+b_.*x_]^n_,x_Symbol] :=
  m*x^(m-1)*Csc[a+b*x]^n/(b^2*n^2) +
  x^m*Cos[a+b*x]*Csc[a+b*x]^(n+1)/(b*n) +
  Dist[(n+1)/n,Int[x^m*Csc[a+b*x]^(n+2),x]] -
  Dist[m*(m-1)/(b^2*n^2),Int[x^(m-2)*Csc[a+b*x]^n,x]] /;
FreeQ[{a,b},x] && RationalQ[{m,n}] && m>1 && n<-1


(* ::PageBreak:: *)
(**)


(* ::Title::Bold::Closed:: *)
(*\[Integral](a+b Sec[c+d x]^n)^m \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Derivation: Algebraic simplification*)


(* ::Subsubsection:: *)
(*Basis: If  a+b=0, then  a+b Sec[z]^2=b Tan[z]^2*)


(* ::Subsubsection:: *)
(*Rule: If  a+b=0 \[And] m\[Element]\[DoubleStruckCapitalZ], then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]u (a+b Sec[v]^2)^m \[DifferentialD]x  \[LongRightArrow]  b^m\[Integral]u Tan[v]^(2m) \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[u_.*(a_+b_.*Sec[v_]^2)^m_,x_Symbol] :=
  Dist[b^m,Int[u*Tan[v]^(2*m),x]] /;
FreeQ[{a,b,m},x] && ZeroQ[a+b] && IntegerQ[m]


(* ::Code:: *)
Int[u_.*(a_+b_.*Csc[v_]^2)^m_,x_Symbol] :=
  Dist[b^m,Int[u*Cot[v]^(2*m),x]] /;
FreeQ[{a,b,m},x] && ZeroQ[a+b] && IntegerQ[m]


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Derivation: Algebraic simplification*)


(* ::Subsubsection:: *)
(*Basis: If  a+b=0, then  a+b Sec[z]^2=b Tan[z]^2*)


(* ::Subsubsection:: *)
(*Rule: If  a+b=0 \[And] m\[NotElement]\[DoubleStruckCapitalZ], then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]u (a+b Sec[v]^2)^m \[DifferentialD]x  \[LongRightArrow]  \[Integral]u (b Tan[v]^2)^m \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[u_.*(a_+b_.*Sec[v_]^2)^m_,x_Symbol] :=
  Int[u*(b*Tan[v]^2)^m,x] /;
FreeQ[{a,b,m},x] && ZeroQ[a+b] && Not[IntegerQ[m]]


(* ::Code:: *)
Int[u_.*(a_+b_.*Csc[v_]^2)^m_,x_Symbol] :=
  Int[u*(b*Cot[v]^2)^m,x] /;
FreeQ[{a,b,m},x] && ZeroQ[a+b] && Not[IntegerQ[m]]


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Derivation: Algebraic simplification*)


(* ::Subsubsection:: *)
(*Basis: If  n\[Element]\[DoubleStruckCapitalZ], then  a+b Sec[z]^n=(b+a Cos[z]^n)/Cos[z]^n*)


(* ::Subsubsection:: *)
(*Rule: If  m,n\[Element]\[DoubleStruckCapitalZ] \[And] m<0 \[And] n>1, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral](a+b Sec[v]^n)^m \[DifferentialD]x  \[LongRightArrow]  \[Integral](b+a Cos[v]^n)^m/Cos[v]^(m n) \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[(a_+b_.*Sec[v_]^n_)^m_,x_Symbol] :=
  Int[(b+a*Cos[v]^n)^m/Cos[v]^(m*n),x] /;
FreeQ[{a,b},x] && IntegersQ[m,n] && m<0 && n>1


(* ::Code:: *)
Int[(a_+b_.*Csc[v_]^n_)^m_,x_Symbol] :=
  Int[(b+a*Sin[v]^n)^m/Sin[v]^(m*n),x] /;
FreeQ[{a,b},x] && IntegersQ[m,n] && m<0 && n>1


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Derivation: Algebraic simplification*)


(* ::Subsubsection:: *)
(*Basis: If  n\[Element]\[DoubleStruckCapitalZ], then  a+b Sec[z]^n=(b+a Cos[z]^n)/Cos[z]^n*)


(* ::Subsubsection:: *)
(*Rule: If  m,n,p\[Element]\[DoubleStruckCapitalZ] \[And] m<0 \[And] n>0, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]Cos[v]^p (a+b Sec[v]^n)^m \[DifferentialD]x  \[LongRightArrow]  \[Integral]Cos[v]^(p-m n) (b+a Cos[v]^n)^m \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
(* Int[Cos[v_]^p_.*(a_+b_.*Sec[v_]^n_.)^m_,x_Symbol] :=
  Int[Cos[v]^(p-m*n)*(b+a*Cos[v]^n)^m,x] /;
FreeQ[{a,b},x] && IntegersQ[m,n,p] && m<0 && n>0 *)


(* ::Code:: *)
(* Int[Sin[v_]^p_.*(a_+b_.*Csc[v_]^n_.)^m_,x_Symbol] :=
  Int[Sin[v]^(p-m*n)*(b+a*Sin[v]^n)^m,x] /;
FreeQ[{a,b},x] && IntegersQ[m,n,p] && m<0 && n>0 *)


(* ::PageBreak:: *)
(**)


(* ::Title::Bold::Closed:: *)
(*\[Integral]Csc[a+b x]^m Sec[a+b x]^n \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Reference: G&R 2.526.49, CRC 329*)


(* ::Subsubsection:: *)
(*Rule: If  b>0, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]Csc[a+b x]Sec[a+b x]\[DifferentialD]x  \[LongRightArrow]  (Log[Tan[a+b x]]/b)*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[Csc[a_.+b_.*x_]*Sec[a_.+b_.*x_],x_Symbol] :=
  Log[Tan[a+b*x]]/b /;
FreeQ[{a,b},x] && PosQ[b]


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Rule: If  m+n-2=0 \[And] n-1!=0 \[And] n>0, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]Csc[a+b x]^m Sec[a+b x]^n \[DifferentialD]x  \[LongRightArrow]  ((Csc[a+b x]^(m-1) Sec[a+b x]^(n-1))/(b (n-1)))*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[Csc[a_.+b_.*x_]^m_*Sec[a_.+b_.*x_]^n_,x_Symbol] :=
  Csc[a+b*x]^(m-1)*Sec[a+b*x]^(n-1)/(b*(n-1)) /;
FreeQ[{a,b,m,n},x] && ZeroQ[m+n-2] && NonzeroQ[n-1] && PosQ[n]


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Derivation: Integration by substitution*)


(* ::Subsubsection:: *)
(*Basis: If  m,n,(m+n)/2\[Element]\[DoubleStruckCapitalZ], then Csc[z]^m Sec[z]^n=(1+Tan[z]^2)^((m+n)/2-1)/Tan[z]^m Derivative[1][Tan][z]*)


(* ::Subsubsection:: *)
(*Rule: If  m,n,(m+n)/2\[Element]\[DoubleStruckCapitalZ] \[And] 0<m<=n, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]Csc[a+b x]^m Sec[a+b x]^n \[DifferentialD]x  \[LongRightArrow]  (1/b)Subst[\[Integral](1+x^2)^((m+n)/2-1)/x^m \[DifferentialD]x,x,Tan[a+b x]]*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[Csc[a_.+b_.*x_]^m_.*Sec[a_.+b_.*x_]^n_,x_Symbol] :=
  Dist[1/b,Subst[Int[Regularize[(1+x^2)^((m+n)/2-1)/x^m,x],x],x,Tan[a+b*x]]] /;
FreeQ[{a,b},x] && IntegersQ[m,n] && EvenQ[m+n] && 0<m<=n


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Reference: G&R 2.510.4*)


(* ::Subsubsection:: *)
(*Rule: If  m<-1 \[And] n>1, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]Csc[a+b x]^m Sec[a+b x]^n \[DifferentialD]x  \[LongRightArrow]  ((Csc[a+b x]^(m+1) Sec[a+b x]^(n-1))/(b (n-1)))+(m+1)/(n-1) \[Integral]Csc[a+b x]^(m+2) Sec[a+b x]^(n-2) \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[Csc[a_.+b_.*x_]^m_*Sec[a_.+b_.*x_]^n_,x_Symbol] :=
  Csc[a+b*x]^(m+1)*Sec[a+b*x]^(n-1)/(b*(n-1)) +
  Dist[(m+1)/(n-1),Int[Csc[a+b*x]^(m+2)*Sec[a+b*x]^(n-2),x]] /;
FreeQ[{a,b},x] && RationalQ[{m,n}] && m<-1 && n>1


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Reference: G&R 2.510.6, CRC 334b, A&S 4.3.128a*)


(* ::Subsubsection:: *)
(*Rule: If  n>1 \[And] (m+n)/2\[NotElement]\[DoubleStruckCapitalZ] \[And] \[Not](n/2,(m-1)/2\[Element]\[DoubleStruckCapitalZ] \[And] m>1), then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]Csc[a+b x]^m Sec[a+b x]^n \[DifferentialD]x  \[LongRightArrow]  ((Csc[a+b x]^(m-1) Sec[a+b x]^(n-1))/(b (n-1)))+(m+n-2)/(n-1) \[Integral]Csc[a+b x]^m Sec[a+b x]^(n-2) \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[Csc[a_.+b_.*x_]^m_.*Sec[a_.+b_.*x_]^n_,x_Symbol] :=
  Csc[a+b*x]^(m-1)*Sec[a+b*x]^(n-1)/(b*(n-1)) +
  Dist[(m+n-2)/(n-1),Int[Csc[a+b*x]^m*Sec[a+b*x]^(n-2),x]] /;
FreeQ[{a,b,m},x] && RationalQ[n] && n>1 && Not[EvenQ[m+n]] && Not[EvenQ[n] && OddQ[m] && m>1]


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Reference: G&R 2.510.5, CRC 323a, A&S 4.3.127a*)


(* ::Subsubsection:: *)
(*Rule: If  n<-1 \[And] m+n!=0, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]Csc[a+b x]^m Sec[a+b x]^n \[DifferentialD]x  \[LongRightArrow]  -((Csc[a+b x]^(m-1) Sec[a+b x]^(n+1))/(b (m+n)))+(n+1)/(m+n) \[Integral]Csc[a+b x]^m Sec[a+b x]^(n+2) \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[Csc[a_.+b_.*x_]^m_.*Sec[a_.+b_.*x_]^n_,x_Symbol] :=
  -Csc[a+b*x]^(m-1)*Sec[a+b*x]^(n+1)/(b*(m+n)) +
  Dist[(n+1)/(m+n),Int[Csc[a+b*x]^m*Sec[a+b*x]^(n+2),x]] /;
FreeQ[{a,b,m},x] && RationalQ[n] && n<-1 && NonzeroQ[m+n]


(* ::PageBreak:: *)
(**)


(* ::Title::Bold::Closed:: *)
(*\[Integral]Csc[a+b x]^m Sec[a+b x]^n \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Reference: G&R 2.526.49', CRC 329'*)


(* ::Subsubsection:: *)
(*Rule: If  \[Not](b>0), then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]Csc[a+b x]Sec[a+b x]\[DifferentialD]x  \[LongRightArrow]  -(Log[Cot[a+b x]]/b)*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[Csc[a_.+b_.*x_]*Sec[a_.+b_.*x_],x_Symbol] :=
  -Log[Cot[a+b*x]]/b /;
FreeQ[{a,b},x] && NegQ[b]


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Rule: If  m+n-2=0 \[And] m-1!=0 \[And] m>0, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]Csc[a+b x]^m Sec[a+b x]^n \[DifferentialD]x  \[LongRightArrow]  -((Csc[a+b x]^(m-1) Sec[a+b x]^(n-1))/(b (m-1)))*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[Csc[a_.+b_.*x_]^m_*Sec[a_.+b_.*x_]^n_,x_Symbol] :=
  -Csc[a+b*x]^(m-1)*Sec[a+b*x]^(n-1)/(b*(m-1)) /;
FreeQ[{a,b,m,n},x] && ZeroQ[m+n-2] && NonzeroQ[m-1] && PosQ[m]


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Derivation: Integration by substitution*)


(* ::Subsubsection:: *)
(*Basis: If  m,n,(m+n)/2\[Element]\[DoubleStruckCapitalZ], then Csc[z]^m Sec[z]^n=-((1+Cot[z]^2)^((m+n)/2-1)/Cot[z]^n)Derivative[1][Cot][z]*)


(* ::Subsubsection:: *)
(*Rule: If  m,n,(m+n)/2\[Element]\[DoubleStruckCapitalZ] \[And] 0<n<m, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]Csc[a+b x]^m Sec[a+b x]^n \[DifferentialD]x  \[LongRightArrow]  -(1/b)Subst[Int[(1+x^2)^((m+n)/2-1)/x^n,x],x,Cot[a+b x]]*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[Csc[a_.+b_.*x_]^m_*Sec[a_.+b_.*x_]^n_.,x_Symbol] :=
  Dist[-1/b,Subst[Int[Regularize[(1+x^2)^((m+n)/2-1)/x^n,x],x],x,Cot[a+b*x]]] /;
FreeQ[{a,b},x] && IntegersQ[m,n] && EvenQ[m+n] && 0<n<m


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Reference: G&R 2.510.1*)


(* ::Subsubsection:: *)
(*Rule: If  m>1 \[And] n<-1, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]Csc[a+b x]^m Sec[a+b x]^n \[DifferentialD]x  \[LongRightArrow]  -((Csc[a+b x]^(m-1) Sec[a+b x]^(n+1))/(b (m-1)))+(n+1)/(m-1) \[Integral]Csc[a+b x]^(m-2) Sec[a+b x]^(n+2) \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[Csc[a_.+b_.*x_]^m_*Sec[a_.+b_.*x_]^n_,x_Symbol] :=
  -Csc[a+b*x]^(m-1)*Sec[a+b*x]^(n+1)/(b*(m-1)) +
  Dist[(n+1)/(m-1),Int[Csc[a+b*x]^(m-2)*Sec[a+b*x]^(n+2),x]] /;
FreeQ[{a,b},x] && RationalQ[{m,n}] && m>1 && n<-1


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Reference: G&R 2.510.3, CRC 334a, A&S 4.3.128b*)


(* ::Subsubsection:: *)
(*Rule: If  m>1 \[And] (m+n)/2\[NotElement]\[DoubleStruckCapitalZ] \[And] \[Not](m/2,(n-1)/2\[Element]\[DoubleStruckCapitalZ] \[And] n>1), then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]Csc[a+b x]^m Sec[a+b x]^n \[DifferentialD]x  \[LongRightArrow]                                                                                                                            *)
(*                                                     -((Csc[a+b x]^(m-1) Sec[a+b x]^(n-1))/(b (m-1)))+(m+n-2)/(m-1) \[Integral]Csc[a+b x]^(m-2) Sec[a+b x]^n \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[Csc[a_.+b_.*x_]^m_*Sec[a_.+b_.*x_]^n_.,x_Symbol] :=
  -Csc[a+b*x]^(m-1)*Sec[a+b*x]^(n-1)/(b*(m-1)) +
  Dist[(m+n-2)/(m-1),Int[Csc[a+b*x]^(m-2)*Sec[a+b*x]^n,x]] /;
FreeQ[{a,b,n},x] && RationalQ[m] && m>1 && Not[EvenQ[m+n]] && Not[EvenQ[m] && OddQ[n] && n>1]


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Reference: G&R 2.510.2, CRC 323b, A&S 4.3.127b*)


(* ::Subsubsection:: *)
(*Rule: If  m<-1 \[And] m+n!=0, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]Csc[a+b x]^m Sec[a+b x]^n \[DifferentialD]x  \[LongRightArrow]  ((Csc[a+b x]^(m+1) Sec[a+b x]^(n-1))/(b (m+n)))+(m+1)/(m+n) \[Integral]Csc[a+b x]^(m+2) Sec[a+b x]^n \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[Csc[a_.+b_.*x_]^m_*Sec[a_.+b_.*x_]^n_.,x_Symbol] :=
  Csc[a+b*x]^(m+1)*Sec[a+b*x]^(n-1)/(b*(m+n)) +
  Dist[(m+1)/(m+n),Int[Csc[a+b*x]^(m+2)*Sec[a+b*x]^n,x]] /;
FreeQ[{a,b,n},x] && RationalQ[m] && m<-1 && NonzeroQ[m+n]


(* ::PageBreak:: *)
(**)


(* ::Title::Bold::Closed:: *)
(*\[Integral]Sec[a+b x]^m Tan[a+b x]^n \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Derivation: Power rule for integration*)


(* ::Subsubsection:: *)
(*Rule:*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]Sec[a+b x]^m Tan[a+b x]\[DifferentialD]x  \[LongRightArrow]  (Sec[a+b x]^m/(b m))*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[Sec[a_.+b_.*x_]^m_.*Tan[a_.+b_.*x_]^n_.,x_Symbol] :=
  Sec[a+b*x]^m/(b*m) /;
FreeQ[{a,b,m},x] && n===1


(* ::Code:: *)
Int[Csc[a_.+b_.*x_]^m_.*Cot[a_.+b_.*x_]^n_.,x_Symbol] :=
  -Csc[a+b*x]^m/(b*m) /;
FreeQ[{a,b,m},x] && n===1


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Derivation: Integration by substitution*)


(* ::Subsubsection:: *)
(*Basis: If m/2\[Element]\[DoubleStruckCapitalZ], then Sec[z]^m=(1+Tan[z]^2)^((m-2)/2) Derivative[1][Tan][z]*)


(* ::Subsubsection:: *)
(*Rule: If  m/2\[Element]\[DoubleStruckCapitalZ] \[And] m>2 \[And] \[Not]((n-1)/2\[Element]\[DoubleStruckCapitalZ] \[And] 0<n<m-1), then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]Sec[a+b x]^m Tan[a+b x]^n \[DifferentialD]x  \[LongRightArrow]  (1/b)Subst[Int[x^n (1+x^2)^((m-2)/2),x],x,Tan[a+b x]]*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[Sec[a_.+b_.*x_]^m_*Tan[a_.+b_.*x_]^n_.,x_Symbol] :=
  Dist[1/b,Subst[Int[Regularize[x^n*(1+x^2)^((m-2)/2),x],x],x,Tan[a+b*x]]] /;
FreeQ[{a,b,n},x] && EvenQ[m] && m>2 && Not[OddQ[n] && 0<n<m-1]


(* ::Code:: *)
Int[Csc[a_.+b_.*x_]^m_*Cot[a_.+b_.*x_]^n_.,x_Symbol] :=
  Dist[-1/b,Subst[Int[Regularize[x^n*(1+x^2)^((m-2)/2),x],x],x,Cot[a+b*x]]] /;
FreeQ[{a,b,n},x] && EvenQ[m] && m>2 && Not[OddQ[n] && 0<n<m-1]


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Derivation: Integration by substitution*)


(* ::Subsubsection:: *)
(*Basis: If  (n-1)/2\[Element]\[DoubleStruckCapitalZ], then Sec[z]^m Tan[z]^n=Sec[z]^(m-1) (-1+Sec[z]^2)^((n-1)/2) Derivative[1][Sec][z]*)


(* ::Subsubsection:: *)
(*Rule: If  (n-1)/2\[Element]\[DoubleStruckCapitalZ] \[And] \[Not](m/2\[Element]\[DoubleStruckCapitalZ] \[And] 0<m<=n+1), then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]Sec[a+b x]^m Tan[a+b x]^n \[DifferentialD]x  \[LongRightArrow]  (1/b)Subst[\[Integral]x^(m-1) (-1+x^2)^((n-1)/2) \[DifferentialD]x,x,Sec[a+b x]]*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[Sec[a_.+b_.*x_]^m_.*Tan[a_.+b_.*x_]^n_.,x_Symbol] :=
  Dist[1/b,Subst[Int[Regularize[x^(m-1)*(-1+x^2)^((n-1)/2),x],x],x,Sec[a+b*x]]] /;
FreeQ[{a,b,m},x] && OddQ[n] && Not[EvenQ[m] && 0<m<=n+1]


(* ::Code:: *)
Int[Csc[a_.+b_.*x_]^m_.*Cot[a_.+b_.*x_]^n_.,x_Symbol] :=
  Dist[-1/b,Subst[Int[Regularize[x^(m-1)*(-1+x^2)^((n-1)/2),x],x],x,Csc[a+b*x]]] /;
FreeQ[{a,b,m},x] && OddQ[n] && Not[EvenQ[m] && 0<m<=n+1]


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Reference: G&R 2.510.3, CRC 334a*)


(* ::Subsubsection:: *)
(*Rule: If  m>1 \[And] n<-1 \[And] m/2\[NotElement]\[DoubleStruckCapitalZ], then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]Sec[a+b x]^m Tan[a+b x]^n \[DifferentialD]x  \[LongRightArrow]  ((Sec[a+b x]^(m-2) Tan[a+b x]^(n+1))/(b (n+1)))-(m-2)/(n+1) \[Integral]Sec[a+b x]^(m-2) Tan[a+b x]^(n+2) \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[Sec[a_.+b_.*x_]^m_*Tan[a_.+b_.*x_]^n_,x_Symbol] :=
  Sec[a+b*x]^(m-2)*Tan[a+b*x]^(n+1)/(b*(n+1)) -
  Dist[(m-2)/(n+1),Int[Sec[a+b*x]^(m-2)*Tan[a+b*x]^(n+2),x]] /;
FreeQ[{a,b},x] && RationalQ[{m,n}] && m>1 && n<-1 && Not[EvenQ[m]]


(* ::Subsubsection:: *)
(*Reference: G&R 2.510.6, CRC 334b*)


(* ::Code:: *)
Int[Csc[a_.+b_.*x_]^m_*Cot[a_.+b_.*x_]^n_,x_Symbol] :=
  -Csc[a+b*x]^(m-2)*Cot[a+b*x]^(n+1)/(b*(n+1)) -
  Dist[(m-2)/(n+1),Int[Csc[a+b*x]^(m-2)*Cot[a+b*x]^(n+2),x]] /;
FreeQ[{a,b},x] && RationalQ[{m,n}] && m>1 && n<-1 && Not[EvenQ[m]]


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Reference: G&R 2.510.2, CRC 323b*)


(* ::Subsubsection:: *)
(*Rule: If  m<-1 \[And] n>1 \[And] m/2\[NotElement]\[DoubleStruckCapitalZ], then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]Sec[a+b x]^m Tan[a+b x]^n \[DifferentialD]x  \[LongRightArrow]  ((Sec[a+b x]^m Tan[a+b x]^(n-1))/(b m))-(n-1)/m \[Integral]Sec[a+b x]^(m+2) Tan[a+b x]^(n-2) \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[Sec[a_.+b_.*x_]^m_*Tan[a_.+b_.*x_]^n_,x_Symbol] :=
  Sec[a+b*x]^m*Tan[a+b*x]^(n-1)/(b*m) -
  Dist[(n-1)/m,Int[Sec[a+b*x]^(m+2)*Tan[a+b*x]^(n-2),x]] /;
FreeQ[{a,b},x] && RationalQ[{m,n}] && m<-1 && n>1 && Not[EvenQ[m]]


(* ::Subsubsection:: *)
(*Reference: G&R 2.510.5, CRC 323a*)


(* ::Code:: *)
Int[Csc[a_.+b_.*x_]^m_*Cot[a_.+b_.*x_]^n_,x_Symbol] :=
  -Csc[a+b*x]^m*Cot[a+b*x]^(n-1)/(b*m) -
  Dist[(n-1)/m,Int[Csc[a+b*x]^(m+2)*Cot[a+b*x]^(n-2),x]] /;
FreeQ[{a,b},x] && RationalQ[{m,n}] && m<-1 && n>1 && Not[EvenQ[m]]


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Reference: G&R 2.510.5, CRC 323a*)


(* ::Subsubsection:: *)
(*Rule: If  m+n+1=0, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]Sec[a+b x]^m Tan[a+b x]^n \[DifferentialD]x  \[LongRightArrow]  -((Sec[a+b x]^m Tan[a+b x]^(n+1))/(b m))*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[Sec[a_.+b_.*x_]^m_*Tan[a_.+b_.*x_]^n_,x_Symbol] :=
  -Sec[a+b*x]^m*Tan[a+b*x]^(n+1)/(b*m) /;
FreeQ[{a,b,m,n},x] && ZeroQ[m+n+1]


(* ::Subsubsection:: *)
(*Reference: G&R 2.510.2, CRC 323b*)


(* ::Code:: *)
Int[Csc[a_.+b_.*x_]^m_.*Cot[a_.+b_.*x_]^n_,x_Symbol] :=
  Csc[a+b*x]^m*Cot[a+b*x]^(n+1)/(b*m) /;
FreeQ[{a,b,m,n},x] && ZeroQ[m+n+1]


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Rule: If  m<-1 \[And] m/2\[NotElement]\[DoubleStruckCapitalZ], then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]Sec[a+b x]^m Tan[a+b x]^n \[DifferentialD]x  \[LongRightArrow]  -((Sec[a+b x]^m Tan[a+b x]^(n+1))/(b m))+(m+n+1)/m \[Integral]Sec[a+b x]^(m+2) Tan[a+b x]^n \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[Sec[a_.+b_.*x_]^m_*Tan[a_.+b_.*x_]^n_,x_Symbol] :=
  -Sec[a+b*x]^m*Tan[a+b*x]^(n+1)/(b*m) +
  Dist[(m+n+1)/m,Int[Sec[a+b*x]^(m+2)*Tan[a+b*x]^n,x]] /;
FreeQ[{a,b,n},x] && RationalQ[m] && m<-1 && Not[EvenQ[m]]


(* ::Code:: *)
Int[Csc[a_.+b_.*x_]^m_*Cot[a_.+b_.*x_]^n_,x_Symbol] :=
  Csc[a+b*x]^m*Cot[a+b*x]^(n+1)/(b*m) +
  Dist[(m+n+1)/m,Int[Csc[a+b*x]^(m+2)*Cot[a+b*x]^n,x]] /;
FreeQ[{a,b,n},x] && RationalQ[m] && m<-1 && Not[EvenQ[m]]


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Reference: G&R 2.510.6, CRC 334b*)


(* ::Subsubsection:: *)
(*Rule: If  m>1 \[And] m+n-1!=0 \[And] m/2\[NotElement]\[DoubleStruckCapitalZ] \[And] (n-1)/2\[NotElement]\[DoubleStruckCapitalZ], then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]Sec[a+b x]^m Tan[a+b x]^n \[DifferentialD]x  \[LongRightArrow]  ((Sec[a+b x]^(m-2) Tan[a+b x]^(n+1))/(b (m+n-1)))+(m-2)/(m+n-1) \[Integral]Sec[a+b x]^(m-2) Tan[a+b x]^n \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[Sec[a_.+b_.*x_]^m_*Tan[a_.+b_.*x_]^n_,x_Symbol] :=
  Sec[a+b*x]^(m-2)*Tan[a+b*x]^(n+1)/(b*(m+n-1)) +
  Dist[(m-2)/(m+n-1),Int[Sec[a+b*x]^(m-2)*Tan[a+b*x]^n,x]] /;
FreeQ[{a,b,n},x] && RationalQ[m] && m>1 && NonzeroQ[m+n-1] && Not[EvenQ[m]] && Not[OddQ[n]]


(* ::Subsubsection:: *)
(*Reference: G&R 2.510.3, CRC 334a*)


(* ::Code:: *)
Int[Csc[a_.+b_.*x_]^m_*Cot[a_.+b_.*x_]^n_,x_Symbol] :=
  -Csc[a+b*x]^(m-2)*Cot[a+b*x]^(n+1)/(b*(m+n-1)) +
  Dist[(m-2)/(m+n-1),Int[Csc[a+b*x]^(m-2)*Cot[a+b*x]^n,x]] /;
FreeQ[{a,b,n},x] && RationalQ[m] && m>1 && NonzeroQ[m+n-1] && Not[EvenQ[m]] && Not[OddQ[n]]


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Reference: G&R 2.510.1*)


(* ::Subsubsection:: *)
(*Rule: If  n>1 \[And] m+n-1!=0 \[And] m/2\[NotElement]\[DoubleStruckCapitalZ] \[And] (n-1)/2\[NotElement]\[DoubleStruckCapitalZ], then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]Sec[a+b x]^m Tan[a+b x]^n \[DifferentialD]x  \[LongRightArrow]  ((Sec[a+b x]^m Tan[a+b x]^(n-1))/(b (m+n-1)))-(n-1)/(m+n-1) \[Integral]Sec[a+b x]^m Tan[a+b x]^(n-2) \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[Sec[a_.+b_.*x_]^m_.*Tan[a_.+b_.*x_]^n_,x_Symbol] :=
  Sec[a+b*x]^m*Tan[a+b*x]^(n-1)/(b*(m+n-1)) -
  Dist[(n-1)/(m+n-1),Int[Sec[a+b*x]^m*Tan[a+b*x]^(n-2),x]] /;
FreeQ[{a,b,m},x] && RationalQ[n] && n>1 && NonzeroQ[m+n-1] && Not[EvenQ[m]] && Not[OddQ[n]]


(* ::Subsubsection:: *)
(*Reference: G&R 2.510.4*)


(* ::Code:: *)
Int[Csc[a_.+b_.*x_]^m_.*Cot[a_.+b_.*x_]^n_,x_Symbol] :=
  -Csc[a+b*x]^m*Cot[a+b*x]^(n-1)/(b*(m+n-1)) -
  Dist[(n-1)/(m+n-1),Int[Csc[a+b*x]^m*Cot[a+b*x]^(n-2),x]] /;
FreeQ[{a,b,m},x] && RationalQ[n] && n>1 && NonzeroQ[m+n-1] && Not[EvenQ[m]] && Not[OddQ[n]]


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Reference: G&R 2.510.4*)


(* ::Subsubsection:: *)
(*Rule: If  n<-1 \[And] m/2\[NotElement]\[DoubleStruckCapitalZ], then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]Sec[a+b x]^m Tan[a+b x]^n \[DifferentialD]x  \[LongRightArrow]  ((Sec[a+b x]^m Tan[a+b x]^(n+1))/(b (n+1)))-(m+n+1)/(n+1) \[Integral]Sec[a+b x]^m Tan[a+b x]^(n+2) \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[Sec[a_.+b_.*x_]^m_*Tan[a_.+b_.*x_]^n_,x_Symbol] :=
  Sec[a+b*x]^m*Tan[a+b*x]^(n+1)/(b*(n+1)) -
  Dist[(m+n+1)/(n+1),Int[Sec[a+b*x]^m*Tan[a+b*x]^(n+2),x]] /;
FreeQ[{a,b,m},x] && RationalQ[n] && n<-1 && Not[EvenQ[m]]


(* ::Subsubsection:: *)
(*Reference: G&R 2.510.1*)


(* ::Code:: *)
Int[Csc[a_.+b_.*x_]^m_.*Cot[a_.+b_.*x_]^n_,x_Symbol] :=
  -Csc[a+b*x]^m*Cot[a+b*x]^(n+1)/(b*(n+1)) -
  Dist[(m+n+1)/(n+1),Int[Csc[a+b*x]^m*Cot[a+b*x]^(n+2),x]] /;
FreeQ[{a,b,m},x] && RationalQ[n] && n<-1 && Not[EvenQ[m]]


(* ::PageBreak:: *)
(**)


(* ::Title::Bold::Closed:: *)
(*\[Integral]x^m Sec[a+b x^n]^p Sin[a+b x^n]\[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Derivation: Integration by parts*)


(* ::Subsubsection:: *)
(*Rule: If  n\[Element]\[DoubleStruckCapitalZ] \[And] m-n>=0 \[And] p-1!=0, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]x^m Sec[a+b x^n]^p Sin[a+b x^n]\[DifferentialD]x  \[LongRightArrow]  ((x^(m-n+1) Sec[a+b x^n]^(p-1))/(b n (p-1)))-(m-n+1)/(b n (p-1)) \[Integral]x^(m-n) Sec[a+b x^n]^(p-1) \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[x_^m_.*Sec[a_.+b_.*x_^n_.]^p_*Sin[a_.+b_.*x_^n_.],x_Symbol] :=
  x^(m-n+1)*Sec[a+b*x^n]^(p-1)/(b*n*(p-1)) -
  Dist[(m-n+1)/(b*n*(p-1)),Int[x^(m-n)*Sec[a+b*x^n]^(p-1),x]] /;
FreeQ[{a,b,p},x] && RationalQ[m] && IntegerQ[n] && m-n>=0 && NonzeroQ[p-1]


(* ::Code:: *)
Int[x_^m_.*Csc[a_.+b_.*x_^n_.]^p_*Cos[a_.+b_.*x_^n_.],x_Symbol] :=
  -x^(m-n+1)*Csc[a+b*x^n]^(p-1)/(b*n*(p-1)) +
  Dist[(m-n+1)/(b*n*(p-1)),Int[x^(m-n)*Csc[a+b*x^n]^(p-1),x]] /;
FreeQ[{a,b,p},x] && RationalQ[m] && IntegerQ[n] && m-n>=0 && NonzeroQ[p-1]


(* ::PageBreak:: *)
(**)


(* ::Title::Bold::Closed:: *)
(*\[Integral]x^m Sec[a+b x^n]^p Tan[a+b x^n]\[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Derivation: Integration by parts*)


(* ::Subsubsection:: *)
(*Note: Dummy exponent q=1 required in program code so InputForm of integrand is recognized.*)


(* ::Subsubsection:: *)
(*Rule: If  n\[Element]\[DoubleStruckCapitalZ] \[And] m-n>=0, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]x^m Sec[a+b x^n]^p Tan[a+b x^n]\[DifferentialD]x  \[LongRightArrow]  ((x^(m-n+1) Sec[a+b x^n]^p)/(b n p))-(m-n+1)/(b n p) \[Integral]x^(m-n) Sec[a+b x^n]^p \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[x_^m_.*Sec[a_.+b_.*x_^n_.]^p_.*Tan[a_.+b_.*x_^n_.]^q_.,x_Symbol] :=
  x^(m-n+1)*Sec[a+b*x^n]^p/(b*n*p) -
  Dist[(m-n+1)/(b*n*p),Int[x^(m-n)*Sec[a+b*x^n]^p,x]] /;
FreeQ[{a,b,p},x] && RationalQ[m] && IntegerQ[n] && m-n>=0 && q===1


(* ::Code:: *)
Int[x_^m_.*Csc[a_.+b_.*x_^n_.]^p_.*Cot[a_.+b_.*x_^n_.]^q_.,x_Symbol] :=
  -x^(m-n+1)*Csc[a+b*x^n]^p/(b*n*p) +
  Dist[(m-n+1)/(b*n*p),Int[x^(m-n)*Csc[a+b*x^n]^p,x]] /;
FreeQ[{a,b,p},x] && RationalQ[m] && IntegerQ[n] && m-n>=0 && q===1


(* ::PageBreak:: *)
(**)


(* ::Title::Bold::Closed:: *)
(*\[Integral]Sec[a+b Log[c x^n]]^p \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Rule: If  p-1!=0 \[And] b^2 n^2 (p-2)^2+1=0, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]Sec[a+b Log[c x^n]]^p \[DifferentialD]x  \[LongRightArrow]  ((x (b n (p-2)+Tan[a+b Log[c x^n]])Sec[a+b Log[c x^n]]^(p-2))/(b n (p-1)))*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[Sec[a_.+b_.*Log[c_.*x_^n_.]]^p_,x_Symbol] :=
  x*(b*n*(p-2)+Tan[a+b*Log[c*x^n]])*Sec[a+b*Log[c*x^n]]^(p-2)/(b*n*(p-1)) /;
FreeQ[{a,b,c,n,p},x] && NonzeroQ[p-1] && ZeroQ[b^2*n^2*(p-2)^2+1]


(* ::Code:: *)
Int[Csc[a_.+b_.*Log[c_.*x_^n_.]]^p_,x_Symbol] :=
  x*(b*n*(p-2)-Cot[a+b*Log[c*x^n]])*Csc[a+b*Log[c*x^n]]^(p-2)/(b*n*(p-1)) /;
FreeQ[{a,b,c,n,p},x] && NonzeroQ[p-1] && ZeroQ[b^2*n^2*(p-2)^2+1]


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Rule: If  p>1 \[And] p!=2 \[And] b^2 n^2 (p-2)^2+1!=0, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]Sec[a+b Log[c x^n]]^p \[DifferentialD]x  \[LongRightArrow]  ((x Tan[a+b Log[c x^n]] Sec[a+b Log[c x^n]]^(p-2))/(b n (p-1)))-                           *)
(*                                     (x Sec[a+b Log[c x^n]]^(p-2))/(b^2 n^2 (p-1) (p-2))+(b^2 n^2 (p-2)^2+1)/(b^2 n^2 (p-1) (p-2)) \[Integral]Sec[a+b Log[c x^n]]^(p-2) \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[Sec[a_.+b_.*Log[c_.*x_^n_.]]^p_,x_Symbol] :=
  x*Tan[a+b*Log[c*x^n]]*Sec[a+b*Log[c*x^n]]^(p-2)/(b*n*(p-1)) -
  x*Sec[a+b*Log[c*x^n]]^(p-2)/(b^2*n^2*(p-1)*(p-2)) +
  Dist[(b^2*n^2*(p-2)^2+1)/(b^2*n^2*(p-1)*(p-2)),Int[Sec[a+b*Log[c*x^n]]^(p-2),x]] /;
FreeQ[{a,b,c,n},x] && RationalQ[p] && p>1 && p!=2 && NonzeroQ[b^2*n^2*(p-2)^2+1]


(* ::Code:: *)
Int[Csc[a_.+b_.*Log[c_.*x_^n_.]]^p_,x_Symbol] :=
  -x*Cot[a+b*Log[c*x^n]]*Csc[a+b*Log[c*x^n]]^(p-2)/(b*n*(p-1)) -
  x*Csc[a+b*Log[c*x^n]]^(p-2)/(b^2*n^2*(p-1)*(p-2)) +
  Dist[(b^2*n^2*(p-2)^2+1)/(b^2*n^2*(p-1)*(p-2)),Int[Csc[a+b*Log[c*x^n]]^(p-2),x]] /;
FreeQ[{a,b,c,n},x] && RationalQ[p] && p>1 && p!=2 && NonzeroQ[b^2*n^2*(p-2)^2+1]


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Rule: If  p<-1 \[And] b^2 n^2 p^2+1!=0, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]Sec[a+b Log[c x^n]]^p \[DifferentialD]x  \[LongRightArrow]  -((b n p x Sin[a+b Log[c x^n]]Sec[a+b Log[c x^n]]^(p+1))/(b^2 n^2 p^2+1))+         *)
(*                                                      (x Sec[a+b Log[c x^n]]^p)/(b^2 n^2 p^2+1)+(b^2 n^2 p (p+1))/(b^2 n^2 p^2+1) \[Integral]Sec[a+b Log[c x^n]]^(p+2) \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[Sec[a_.+b_.*Log[c_.*x_^n_.]]^p_,x_Symbol] :=
  -b*n*p*x*Sin[a+b*Log[c*x^n]]*Sec[a+b*Log[c*x^n]]^(p+1)/(b^2*n^2*p^2+1) +
  x*Sec[a+b*Log[c*x^n]]^p/(b^2*n^2*p^2+1) +
  Dist[b^2*n^2*p*(p+1)/(b^2*n^2*p^2+1),Int[Sec[a+b*Log[c*x^n]]^(p+2),x]] /;
FreeQ[{a,b,c,n},x] && RationalQ[p] && p<-1 && NonzeroQ[b^2*n^2*p^2+1]


(* ::Code:: *)
Int[Csc[a_.+b_.*Log[c_.*x_^n_.]]^p_,x_Symbol] :=
  b*n*p*x*Cos[a+b*Log[c*x^n]]*Csc[a+b*Log[c*x^n]]^(p+1)/(b^2*n^2*p^2+1) +
  x*Csc[a+b*Log[c*x^n]]^p/(b^2*n^2*p^2+1) +
  Dist[b^2*n^2*p*(p+1)/(b^2*n^2*p^2+1),Int[Csc[a+b*Log[c*x^n]]^(p+2),x]] /;
FreeQ[{a,b,c,n},x] && RationalQ[p] && p<-1 && NonzeroQ[b^2*n^2*p^2+1]


(* ::PageBreak:: *)
(**)


(* ::Title::Bold::Closed:: *)
(*\[Integral]x^m Sec[a+b Log[c x^n]]^p \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Rule: If  m+1!=0 \[And] p-1!=0 \[And] b^2 n^2 (p-2)^2+(m+1)^2=0, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]x^m Sec[a+b Log[c x^n]]^p \[DifferentialD]x  \[LongRightArrow]  ((x^(m+1) (b n (p-2)+(m+1) Tan[a+b Log[c x^n]])Sec[a+b Log[c x^n]]^(p-2))/(b n(m+1)(p-1)))*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[x_^m_.*Sec[a_.+b_.*Log[c_.*x_^n_.]]^p_,x_Symbol] :=
  x^(m+1)*(b*n*(p-2)+(m+1)*Tan[a+b*Log[c*x^n]])*Sec[a+b*Log[c*x^n]]^(p-2)/(b*n*(m+1)*(p-1)) /;
FreeQ[{a,b,c,m,n,p},x] && NonzeroQ[m+1] && NonzeroQ[p-1] && ZeroQ[b^2*n^2*(p-2)^2+(m+1)^2]


(* ::Code:: *)
Int[x_^m_.*Csc[a_.+b_.*Log[c_.*x_^n_.]]^p_,x_Symbol] :=
  x^(m+1)*(b*n*(p-2)-(m+1)*Cot[a+b*Log[c*x^n]])*Csc[a+b*Log[c*x^n]]^(p-2)/(b*n*(m+1)*(p-1)) /;
FreeQ[{a,b,c,m,n,p},x] && NonzeroQ[m+1] && NonzeroQ[p-1] && ZeroQ[b^2*n^2*(p-2)^2+(m+1)^2]


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Rule: If  p>1 \[And] p!=2 \[And] b^2 n^2 (p-2)^2+(m+1)^2!=0, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]x^m Sec[a+b Log[c x^n]]^p \[DifferentialD]x  \[LongRightArrow]  ((x^(m+1) Tan[a+b Log[c x^n]] Sec[a+b Log[c x^n]]^(p-2))/(b n (p-1)))-                             *)
(*               ((m+1) x^(m+1) Sec[a+b Log[c x^n]]^(p-2))/(b^2 n^2 (p-1) (p-2))+(b^2 n^2 (p-2)^2+(m+1)^2)/(b^2 n^2 (p-1)(p-2)) \[Integral]x^m Sec[a+b Log[c x^n]]^(p-2) \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[x_^m_.*Sec[a_.+b_.*Log[c_.*x_^n_.]]^p_,x_Symbol] :=
  x^(m+1)*Tan[a+b*Log[c*x^n]]*Sec[a+b*Log[c*x^n]]^(p-2)/(b*n*(p-1)) -
  (m+1)*x^(m+1)*Sec[a+b*Log[c*x^n]]^(p-2)/(b^2*n^2*(p-1)*(p-2)) +
  Dist[(b^2*n^2*(p-2)^2+(m+1)^2)/(b^2*n^2*(p-1)*(p-2)),Int[x^m*Sec[a+b*Log[c*x^n]]^(p-2),x]] /;
FreeQ[{a,b,c,m,n},x] && RationalQ[p] && p>1 && p!=2 && NonzeroQ[b^2*n^2*(p-2)^2+(m+1)^2]


(* ::Code:: *)
Int[x_^m_.*Csc[a_.+b_.*Log[c_.*x_^n_.]]^p_,x_Symbol] :=
  -x^(m+1)*Cot[a+b*Log[c*x^n]]*Csc[a+b*Log[c*x^n]]^(p-2)/(b*n*(p-1)) -
  (m+1)*x^(m+1)*Csc[a+b*Log[c*x^n]]^(p-2)/(b^2*n^2*(p-1)*(p-2)) +
  Dist[(b^2*n^2*(p-2)^2+(m+1)^2)/(b^2*n^2*(p-1)*(p-2)),Int[x^m*Csc[a+b*Log[c*x^n]]^(p-2),x]] /;
FreeQ[{a,b,c,m,n},x] && RationalQ[p] && p>1 && p!=2 && NonzeroQ[b^2*n^2*(p-2)^2+(m+1)^2]


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Rule: If  p<-1 \[And] b^2 n^2 p^2+(m+1)^2!=0, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]x^m Sec[a+b Log[c x^n]]^p \[DifferentialD]x  \[LongRightArrow]  -((b n p x^(m+1) Sin[a+b Log[c x^n]]Sec[a+b Log[c x^n]]^(p+1))/(b^2 n^2 p^2+(m+1)^2))+             *)
(*                         ((m+1) x^(m+1) Sec[a+b Log[c x^n]]^p)/(b^2 n^2 p^2+(m+1)^2)+(b^2 n^2 p (p+1))/(b^2 n^2 p^2+(m+1)^2) \[Integral]x^m Sec[a+b Log[c x^n]]^(p+2) \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[x_^m_.*Sec[a_.+b_.*Log[c_.*x_^n_.]]^p_,x_Symbol] :=
  -b*n*p*x^(m+1)*Sin[a+b*Log[c*x^n]]*Sec[a+b*Log[c*x^n]]^(p+1)/(b^2*n^2*p^2+(m+1)^2) +
  (m+1)*x^(m+1)*Sec[a+b*Log[c*x^n]]^p/(b^2*n^2*p^2+(m+1)^2) +
  Dist[b^2*n^2*p*(p+1)/(b^2*n^2*p^2+(m+1)^2),Int[x^m*Sec[a+b*Log[c*x^n]]^(p+2),x]] /;
FreeQ[{a,b,c,m,n},x] && RationalQ[p] && p<-1 && NonzeroQ[b^2*n^2*p^2+(m+1)^2]


(* ::Code:: *)
Int[x_^m_.*Csc[a_.+b_.*Log[c_.*x_^n_.]]^p_,x_Symbol] :=
  b*n*p*x^(m+1)*Cos[a+b*Log[c*x^n]]*Csc[a+b*Log[c*x^n]]^(p+1)/(b^2*n^2*p^2+(m+1)^2) +
  (m+1)*x^(m+1)*Csc[a+b*Log[c*x^n]]^p/(b^2*n^2*p^2+(m+1)^2) +
  Dist[b^2*n^2*p*(p+1)/(b^2*n^2*p^2+(m+1)^2),Int[x^m*Csc[a+b*Log[c*x^n]]^(p+2),x]] /;
FreeQ[{a,b,c,m,n},x] && RationalQ[p] && p<-1 && NonzeroQ[b^2*n^2*p^2+(m+1)^2]


(* ::PageBreak:: *)
(**)


(* ::Title::Bold::Closed:: *)
(*\[Integral]u Csc[a+b x]^n \[DifferentialD]x   Sec ???*)


(* ::Subsubsection:: *)
(*Derivation: Algebraic simplification*)


(* ::Subsubsection:: *)
(*Basis: Csc[2 z]=1/2 Csc[z] Sec[z]*)


(* ::Subsubsection:: *)
(*Rule: If  n\[Element]\[DoubleStruckCapitalZ] and u is a function of trig functions of a/2+(b x)/2, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]u Csc[a+b x]^n \[DifferentialD]x  \[LongRightArrow]  (1/2^n)\[Integral]u Csc[a/2+(b x)/2]^n Sec[a/2+(b x)/2]^n \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[u_*Csc[a_.+b_.*x_]^n_.,x_Symbol] :=
  Dist[1/2^n,Int[u*Csc[a/2+b*x/2]^n*Sec[a/2+b*x/2]^n,x]] /;
FreeQ[{a,b},x] && IntegerQ[n] && ZeroQ[a/2+b*x/2-FunctionOfTrig[u,x]]


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Derivation: Algebraic simplification and piecewise constant extraction*)


(* ::Subsubsection:: *)
(*Basis: Csc[2 z]=1/2 Csc[z] Sec[z]*)


(* ::Subsubsection:: *)
(*Basis: \!\( *)
(*\*SubscriptBox[\(\[PartialD]\), \(x\)]*)
(*\*FractionBox[*)
(*SuperscriptBox[\(Csc[a + b\ x]\), \(n\)], \( *)
(*\*SuperscriptBox[\(Csc[*)
(*\*FractionBox[\(a\), \(2\)] + *)
(*\*FractionBox[\(b\ x\), \(2\)]]\), \(n\)]\ *)
(*\*SuperscriptBox[\(Sec[*)
(*\*FractionBox[\(a\), \(2\)] + *)
(*\*FractionBox[\(b\ x\), \(2\)]]\), \(n\)]\)]\)=0*)


(* ::Subsubsection:: *)
(*Rule: If  n\[Element]\[DoubleStruckCapitalF] and u is a function of trig functions of a/2+(b x)/2, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]u Csc[a+b x]^n \[DifferentialD]x  \[LongRightArrow]  (Csc[a+b x]^n/(Csc[a/2+(b x)/2]^n Sec[a/2+(b x)/2]^n))\[Integral]u Csc[a/2+(b x)/2]^n Sec[a/2+(b x)/2]^n \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
(* Int[u_*Csc[a_.+b_.*x_]^n_,x_Symbol] :=
  Csc[a+b*x]^n/(Csc[a/2+b*x/2]^n*Sec[a/2+b*x/2]^n)*Int[u*Csc[a/2+b*x/2]^n*Sec[a/2+b*x/2]^n,x] /;
FreeQ[{a,b},x] && FractionQ[n] && ZeroQ[a/2+b*x/2-FunctionOfTrig[u,x]] *)


(* ::PageBreak:: *)
(**)
