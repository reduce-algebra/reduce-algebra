(* ::Package:: *)

(* ::Title::Bold::Closed:: *)
(*\[Integral]PolyLog[n,a (b x^p)^q]\[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Derivation:  Integration by parts*)


(* ::Subsubsection:: *)
(*Rule: If  n>0, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]PolyLog[n,a (b x^p)^q]\[DifferentialD]x  \[LongRightArrow]  x PolyLog[n,a (b x^p)^q]-p q \[Integral]PolyLog[n-1,a (b x^p)^q]\[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[PolyLog[n_,a_.*(b_.*x_^p_.)^q_.],x_Symbol] :=
  x*PolyLog[n,a*(b*x^p)^q] -
  Dist[p*q,Int[PolyLog[n-1,a*(b*x^p)^q],x]] /;
FreeQ[{a,b,p,q},x] && RationalQ[n] && n>0


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Derivation: Inverted integration by parts*)


(* ::Subsubsection:: *)
(*Rule: If  n<-1, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]PolyLog[n,a (b x^p)^q]\[DifferentialD]x  \[LongRightArrow]  ((x PolyLog[n+1,a (b x^p)^q])/(p q))-1/(p q) \[Integral]PolyLog[n+1,a (b x^p)^q]\[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[PolyLog[n_,a_.*(b_.*x_^p_.)^q_.],x_Symbol] :=
  x*PolyLog[n+1,a*(b*x^p)^q]/(p*q) -
  Dist[1/(p*q),Int[PolyLog[n+1,a*(b*x^p)^q],x]] /;
FreeQ[{a,b,p,q},x] && RationalQ[n] && n<-1


(* ::PageBreak:: *)
(**)


(* ::Title::Bold::Closed:: *)
(*\[Integral]x^m PolyLog[n,a (b x^p)^q]\[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Derivation: Primitive rule*)


(* ::Subsubsection:: *)
(*Basis: \[PartialD]PolyLog[n,z]/\[PartialD]z=PolyLog[n-1,z]/z*)


(* ::Subsubsection:: *)
(*Rule:*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]PolyLog[n,a (b x^p)^q]/x \[DifferentialD]x  \[LongRightArrow]  (PolyLog[n+1,a (b x^p)^q]/(p q))*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[PolyLog[n_,a_.*(b_.*x_^p_.)^q_.]/x_,x_Symbol] :=
  PolyLog[n+1,a*(b*x^p)^q]/(p*q) /;
FreeQ[{a,b,n,p,q},x]


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Derivation: Integration by parts*)


(* ::Subsubsection:: *)
(*Rule: If  n>0 \[And] m+1!=0, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]x^m PolyLog[n,a (b x^p)^q]\[DifferentialD]x  \[LongRightArrow]  ((x^(m+1) PolyLog[n,a (b x^p)^q])/(m+1))-(p q)/(m+1) \[Integral]x^m PolyLog[n-1,a (b x^p)^q]\[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[x_^m_.*PolyLog[n_,a_.*(b_.*x_^p_.)^q_.],x_Symbol] :=
  x^(m+1)*PolyLog[n,a*(b*x^p)^q]/(m+1) -
  Dist[p*q/(m+1),Int[x^m*PolyLog[n-1,a*(b*x^p)^q],x]] /;
FreeQ[{a,b,m,p,q},x] && RationalQ[n] && n>0 && NonzeroQ[m+1]


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Derivation: Inverted integration by parts*)


(* ::Subsubsection:: *)
(*Rule: If  n<-1 \[And] m+1!=0, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]x^m PolyLog[n,a (b x^p)^q]\[DifferentialD]x  \[LongRightArrow]  ((x^(m+1) PolyLog[n+1,a (b x^p)^q])/(p q))-(m+1)/(p q) \[Integral]x^m PolyLog[n+1,a (b x^p)^q]\[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[x_^m_.*PolyLog[n_,a_.*(b_.*x_^p_.)^q_.],x_Symbol] :=
  x^(m+1)*PolyLog[n+1,a*(b*x^p)^q]/(p*q) -
  Dist[(m+1)/(p*q),Int[x^m*PolyLog[n+1,a*(b*x^p)^q],x]] /;
FreeQ[{a,b,m,p,q},x] && RationalQ[n] && n<-1 && NonzeroQ[m+1]


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Derivation: Integration by substitution*)


(* ::Subsubsection:: *)
(*Rule:*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]PolyLog[n,u]/(a+b x) \[DifferentialD]x  \[LongRightArrow]  (1/b)Subst[\[Integral]PolyLog[n,Regularize[Subst[u,x,-(a/b)+x/b],x]]/x \[DifferentialD]x,x,a+b x]*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[PolyLog[n_,u_]/(a_+b_.*x_),x_Symbol] :=
  Dist[1/b,Subst[Int[PolyLog[n,Regularize[Subst[u,x,-a/b+x/b],x]]/x,x],x,a+b*x]] /;
FreeQ[{a,b,n},x]


(* ::PageBreak:: *)
(**)


(* ::Title::Bold::Closed:: *)
(*\[Integral]PolyLog[n,c (a+b x)^p]\[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Derivation: Integration by parts*)


(* ::Subsubsection:: *)
(*Rule: If  n>0, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]PolyLog[n,c (a+b x)^p]\[DifferentialD]x  \[LongRightArrow]  x PolyLog[n,c (a+b x)^p]-                                               *)
(*                                        p \[Integral]PolyLog[n-1,c (a+b x)^p]\[DifferentialD]x+a p \[Integral]PolyLog[n-1,c (a+b x)^p]/(a+b x) \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[PolyLog[n_,c_.*(a_.+b_.*x_)^p_.],x_Symbol] :=
  x*PolyLog[n,c*(a+b*x)^p] -
  Dist[p,Int[PolyLog[n-1,c*(a+b*x)^p],x]] +
  Dist[a*p,Int[PolyLog[n-1,c*(a+b*x)^p]/(a+b*x),x]] /;
FreeQ[{a,b,c,p},x] && RationalQ[n] && n>0


(* ::PageBreak:: *)
(**)


(* ::Title::Bold::Closed:: *)
(*\[Integral]x^m PolyLog[n,c (a+b x)^p]\[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Derivation: Integration by parts*)


(* ::Subsubsection:: *)
(*Rule: If  n>0 \[And] m\[Element]\[DoubleStruckCapitalZ] \[And] m>0, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]x^m PolyLog[n,c (a+b x)^p]\[DifferentialD]x  \[LongRightArrow]                                                                                                                 *)
(*                              ((x^(m+1) PolyLog[n,c (a+b x)^p])/(m+1))-(b p)/(m+1) \[Integral](x^(m+1) PolyLog[n-1,c (a+b x)^p])/(a+b x) \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[x_^m_.*PolyLog[n_,c_.*(a_.+b_.*x_)^p_.],x_Symbol] :=
  x^(m+1)*PolyLog[n,c*(a+b*x)^p]/(m+1) -
  Dist[b*p/(m+1),Int[x^(m+1)*PolyLog[n-1,c*(a+b*x)^p]/(a+b*x),x]] /;
FreeQ[{a,b,c,m,p},x] && RationalQ[n] && n>0 && IntegerQ[m] && m>0


(* ::PageBreak:: *)
(**)


(* ::Title::Bold::Closed:: *)
(*\[Integral]PolyLog[n,c f^(a+b x)]\[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Derivation: Primitive rule*)


(* ::Subsubsection:: *)
(*Basis: \!\( *)
(*\*SubscriptBox[\(\[PartialD]\), \(z\)]\(PolyLog[n, z]\)\)=PolyLog[n-1,z]/z*)


(* ::Subsubsection:: *)
(*Rule:*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]PolyLog[n,c f^(a+b x)]\[DifferentialD]x  \[LongRightArrow]  (PolyLog[n+1,c f^(a+b x)]/(b Log[f]))*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[PolyLog[n_,c_.*f_^(a_.+b_.*x_)],x_Symbol] :=
  PolyLog[n+1,c*f^(a+b*x)]/(b*Log[f]) /;
FreeQ[{a,b,c,n},x]


(* ::PageBreak:: *)
(**)


(* ::Title::Bold::Closed:: *)
(*\[Integral]x^m PolyLog[n,c f^(a+b x)]\[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Derivation: Integration by parts*)


(* ::Subsubsection:: *)
(*Rule: If  m>0, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]x^m PolyLog[n,c f^(a+b x)]\[DifferentialD]x  \[LongRightArrow]  ((x^m PolyLog[n+1,c f^(a+b x)])/(b Log[f]))-m/(b Log[f]) \[Integral]x^(m-1) PolyLog[n+1,c f^(a+b x)]\[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[x_^m_.*PolyLog[n_,c_.*f_^(a_.+b_.*x_)],x_Symbol] :=
  x^m*PolyLog[n+1,c*f^(a+b*x)]/(b*Log[f]) -
  Dist[m/(b*Log[f]),Int[x^(m-1)*PolyLog[n+1,c*f^(a+b*x)],x]] /;
FreeQ[{a,b,c,n},x] && RationalQ[m] && m>0


(* ::PageBreak:: *)
(**)


(* ::Title::Bold::Closed:: *)
(*\[Integral](Log[a x^n]^p PolyLog[q,b x^m])/x \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Derivation: Integration by parts*)


(* ::Subsubsection:: *)
(*Rule: If  p>0, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral](Log[a x^n]^p PolyLog[q,b x^m])/x \[DifferentialD]x  \[LongRightArrow]                                                                                                       *)
(*                       ((Log[a x^n]^p PolyLog[q+1,b x^m])/m)-(n p)/m \[Integral](Log[a x^n]^(p-1) PolyLog[q+1,b x^m])/x \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[Log[a_.*x_^n_.]^p_.*PolyLog[q_,b_.*x_^m_.]/x_,x_Symbol] :=
  Log[a*x^n]^p*PolyLog[q+1,b*x^m]/m -
  Dist[n*p/m,Int[Log[a*x^n]^(p-1)*PolyLog[q+1,b*x^m]/x,x]] /;
FreeQ[{a,b,m,n,q},x] && RationalQ[p] && p>0
