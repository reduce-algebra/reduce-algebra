(* ::Package:: *)

(* ::Title::Bold::Closed:: *)
(*\[Integral](c ProductLog[a+b x])^p \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Rule: If  p<-1, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral](c ProductLog[a+b x])^p \[DifferentialD]x  \[LongRightArrow]                                                                                                               *)
(*             (((a+b x) (c ProductLog[a+b x])^p)/(b (p+1)))+p/(c(p+1)) \[Integral](c ProductLog[a+b x])^(p+1)/(1+ProductLog[a+b x]) \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[(c_.*ProductLog[a_.+b_.*x_])^p_,x_Symbol] :=
  (a+b*x)*(c*ProductLog[a+b*x])^p/(b*(p+1)) +
  Dist[p/(c*(p+1)),Int[(c*ProductLog[a+b*x])^(p+1)/(1+ProductLog[a+b*x]),x]] /;
FreeQ[{a,b,c},x] && RationalQ[p] && p<-1


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Derivation: Integration by parts*)


(* ::Subsubsection:: *)
(*Rule: If  \[Not](p<-1), then*)


(* ::Subsubsection:: *)
(**)


(* ::Subsubtitle::Bold:: *)
(*\[Integral](c ProductLog[a+b x])^p \[DifferentialD]x  \[LongRightArrow]                                                                                                               *)
(*                            (((a+b x) (c ProductLog[a+b x])^p)/b)-p \[Integral](c ProductLog[a+b x])^p/(1+ProductLog[a+b x]) \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[(c_.*ProductLog[a_.+b_.*x_])^p_.,x_Symbol] :=
  (a+b*x)*(c*ProductLog[a+b*x])^p/b -
  Dist[p,Int[(c*ProductLog[a+b*x])^p/(1+ProductLog[a+b*x]),x]] /;
FreeQ[{a,b,c},x] && Not[RationalQ[p] && p<-1]


(* ::PageBreak:: *)
(**)


(* ::Title::Bold::Closed:: *)
(*\[Integral]1/(d+d ProductLog[a+b x]) \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Rule:*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]1/(d+d ProductLog[a+b x]) \[DifferentialD]x  \[LongRightArrow]  ((a+b x)/(b d ProductLog[a+b x]))*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[1/(d_+d_.*ProductLog[a_.+b_.*x_]),x_Symbol] :=
  (a+b*x)/(b*d*ProductLog[a+b*x]) /;
FreeQ[{a,b,d},x]


(* ::PageBreak:: *)
(**)


(* ::Title::Bold::Closed:: *)
(*\[Integral](c ProductLog[a+b x])^p/(d+d ProductLog[a+b x]) \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Derivation: Algebraic simplification*)


(* ::Subsubsection:: *)
(*Basis: z/(1+z)=1-1/(1+z)*)


(* ::Subsubsection:: *)
(*Rule:*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]ProductLog[a+b x]/(d+d ProductLog[a+b x]) \[DifferentialD]x  \[LongRightArrow]  d x-\[Integral]1/(d+d ProductLog[a+b x]) \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[ProductLog[a_.+b_.*x_]/(d_+d_.*ProductLog[a_.+b_.*x_]),x_Symbol] :=
  d*x - 
  Int[1/(d+d*ProductLog[a+b*x]),x] /;
FreeQ[{a,b,d},x]


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Rule:*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]1/(ProductLog[a+b x](d+d ProductLog[a+b x])) \[DifferentialD]x  \[LongRightArrow]  (ExpIntegralEi[ProductLog[a+b x]]/(b d))*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[1/(ProductLog[a_.+b_.*x_]*(d_+d_.*ProductLog[a_.+b_.*x_])),x_Symbol] :=
  ExpIntegralEi[ProductLog[a+b*x]]/(b*d) /;
FreeQ[{a,b,d},x]


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Rule: If  c>0, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]1/(Sqrt[c ProductLog[a+b x]](d+d ProductLog[a+b x])) \[DifferentialD]x  \[LongRightArrow]  (Sqrt[\[Pi] c] /(b c d))Erfi[Sqrt[c ProductLog[a+b x]]/Sqrt[c]]*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[1/(Sqrt[c_.*ProductLog[a_.+b_.*x_]]*(d_+d_.*ProductLog[a_.+b_.*x_])),x_Symbol] :=
  Rt[Pi*c,2]*Erfi[Sqrt[c*ProductLog[a+b*x]]/Rt[c,2]]/(b*c*d) /;
FreeQ[{a,b,c,d},x] && PosQ[c]


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Rule: If  c<0, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]1/(Sqrt[c ProductLog[a+b x]](d+d ProductLog[a+b x])) \[DifferentialD]x  \[LongRightArrow]  (Sqrt[-\[Pi] c] /(b c d))Erf[Sqrt[c ProductLog[a+b x]]/Sqrt[-c]]*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[1/(Sqrt[c_.*ProductLog[a_.+b_.*x_]]*(d_+d_.*ProductLog[a_.+b_.*x_])),x_Symbol] :=
  Rt[-Pi*c,2]*Erf[Sqrt[c*ProductLog[a+b*x]]/Rt[-c,2]]/(b*c*d) /;
FreeQ[{a,b,c,d},x] && NegQ[c]


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Rule: If  p>0, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral](c ProductLog[a+b x])^p/(d+d ProductLog[a+b x]) \[DifferentialD]x  \[LongRightArrow]                                                                                                                                               *)
(*                                                  ((c(a+b x) (c ProductLog[a+b x])^(p-1))/(b d))-c p \[Integral](c ProductLog[a+b x])^(p-1)/(d+d ProductLog[a+b x]) \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[(c_.*ProductLog[a_.+b_.*x_])^p_/(d_+d_.*ProductLog[a_.+b_.*x_]),x_Symbol] :=
  c*(a+b*x)*(c*ProductLog[a+b*x])^(p-1)/(b*d) -
  Dist[c*p,Int[(c*ProductLog[a+b*x])^(p-1)/(d+d*ProductLog[a+b*x]),x]] /;
FreeQ[{a,b,c,d},x] && RationalQ[p] && p>0


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Rule: If  p<-1, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral](c ProductLog[a+b x])^p/(d+d ProductLog[a+b x]) \[DifferentialD]x  \[LongRightArrow]                                                                                                                                               *)
(*                                         (((a+b x) (c ProductLog[a+b x])^p)/(b  d(p+1)))-1/(c(p+1)) \[Integral](c ProductLog[a+b x])^(p+1)/(d+d ProductLog[a+b x]) \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[(c_.*ProductLog[a_.+b_.*x_])^p_/(d_+d_.*ProductLog[a_.+b_.*x_]),x_Symbol] :=
  (a+b*x)*(c*ProductLog[a+b*x])^p/(b*d*(p+1)) -
  Dist[1/(c*(p+1)),Int[(c*ProductLog[a+b*x])^(p+1)/(d+d*ProductLog[a+b*x]),x]] /;
FreeQ[{a,b,c,d},x] && RationalQ[p] && p<-1


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Rule:*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral](c ProductLog[a+b x])^p/(d+d ProductLog[a+b x]) \[DifferentialD]x  \[LongRightArrow]  ((Gamma[p+1,-ProductLog[a+b x]] (c ProductLog[a+b x])^p)/(b d (-ProductLog[a+b x])^p))*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[(c_.*ProductLog[a_.+b_.*x_])^p_./(d_+d_.*ProductLog[a_.+b_.*x_]),x_Symbol] :=
  Gamma[p+1,-ProductLog[a+b*x]]*(c*ProductLog[a+b*x])^p/(b*d*(-ProductLog[a+b*x])^p) /;
FreeQ[{a,b,c,d,p},x]


(* ::PageBreak:: *)
(**)


(* ::Title::Bold::Closed:: *)
(*\[Integral]x^m (c ProductLog[a+b x])^p \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Derivation: Integration by substitution*)


(* ::Subsubsection:: *)
(*Rule: If  m\[Element]\[DoubleStruckCapitalZ] \[And] m>0, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]x^m (c ProductLog[a+b x])^p \[DifferentialD]x  \[LongRightArrow]  (1/b)Subst[\[Integral](-(a/b)+x/b)^m (c ProductLog[x])^p \[DifferentialD]x,x,a+b x]*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[x_^m_.*(c_.*ProductLog[a_+b_.*x_])^p_.,x_Symbol] :=
  Dist[1/b,Subst[Int[Dist[(c*ProductLog[x])^p,Expand[(-a/b+x/b)^m]],x],x,a+b*x]] /;
FreeQ[{a,b,c,p},x] && IntegerQ[m] && m>0


(* ::PageBreak:: *)
(**)


(* ::Title::Bold::Closed:: *)
(*\[Integral]x^m/(d+d ProductLog[a+b x]) \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Derivation: Integration by substitution*)


(* ::Subsubsection:: *)
(*Rule: If  m\[Element]\[DoubleStruckCapitalZ] \[And] m>0, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]x^m/(d+d ProductLog[a+b x]) \[DifferentialD]x  \[LongRightArrow]  (1/b)Subst[\[Integral](-(a/b)+x/b)^m/(d+d ProductLog[x]) \[DifferentialD]x,x,a+b x]*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[x_^m_./(d_+d_.*ProductLog[a_+b_.*x_]),x_Symbol] :=
  Dist[1/b,Subst[Int[Dist[1/(d+d*ProductLog[x]),Expand[(-a/b+x/b)^m]],x],x,a+b*x]] /;
FreeQ[{a,b,d},x] && IntegerQ[m] && m>0


(* ::PageBreak:: *)
(**)


(* ::Title::Bold::Closed:: *)
(*\[Integral](x^m (c ProductLog[a+b x])^p)/(d+d ProductLog[a+b x]) \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Derivation: Integration by substitution*)


(* ::Subsubsection:: *)
(*Rule: If  m\[Element]\[DoubleStruckCapitalZ] \[And] m>0, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral](x^m (c ProductLog[a+b x])^p)/(d+d ProductLog[a+b x]) \[DifferentialD]x  \[LongRightArrow]  (1/b)Subst[\[Integral]((-(a/b)+x/b)^m (c ProductLog[x])^p)/(d+d ProductLog[x]) \[DifferentialD]x,x,a+b x]*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[x_^m_.*(c_.*ProductLog[a_+b_.*x_])^p_./(d_+d_.*ProductLog[a_+b_.*x_]),x_Symbol] :=
  Dist[1/b,Subst[Int[Dist[(c*ProductLog[x])^p/(d+d*ProductLog[x]),Expand[(-a/b+x/b)^m]],x],x,a+b*x]] /;
FreeQ[{a,b,c,d,p},x] && IntegerQ[m] && m>0


(* ::PageBreak:: *)
(**)


(* ::Title::Bold::Closed:: *)
(*\[Integral](c ProductLog[a x^n])^p \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Derivation: Integration by parts*)


(* ::Subsubsection:: *)
(*Rule: If  n(p-1)+1=0 \[Or] (p-1/2\[Element]\[DoubleStruckCapitalZ] \[And] n(p-1/2)+1=0), then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral](c ProductLog[a x^n])^p \[DifferentialD]x  \[LongRightArrow]  x (c ProductLog[a x^n])^p-n p \[Integral](c ProductLog[a x^n])^p/(1+ProductLog[a x^n]) \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[(c_.*ProductLog[a_.*x_^n_])^p_.,x_Symbol] :=
  x*(c*ProductLog[a*x^n])^p -
  Dist[n*p,Int[(c*ProductLog[a*x^n])^p/(1+ProductLog[a*x^n]),x]] /;
FreeQ[{a,c,n,p},x] && (ZeroQ[n*(p-1)+1] || IntegerQ[p-1/2] && ZeroQ[n*(p-1/2)+1])


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Rule: If  (p\[Element]\[DoubleStruckCapitalZ] \[And] n(p+1)+1=0) \[Or] (p-1/2\[Element]\[DoubleStruckCapitalZ] \[And] n(p+1/2)+1=0), then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral](c ProductLog[a x^n])^p \[DifferentialD]x  \[LongRightArrow]  ((x (c ProductLog[a x^n])^p)/(n p+1))+(n p)/(c (n p+1)) \[Integral](c ProductLog[a x^n])^(p+1)/(1+ProductLog[a x^n]) \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[(c_.*ProductLog[a_.*x_^n_])^p_.,x_Symbol] :=
  x*(c*ProductLog[a*x^n])^p/(n*p+1) +
  Dist[n*p/(c*(n*p+1)),Int[(c*ProductLog[a*x^n])^(p+1)/(1+ProductLog[a*x^n]),x]] /;
FreeQ[{a,c,n},x] && (IntegerQ[p] && ZeroQ[n*(p+1)+1] || IntegerQ[p-1/2] && ZeroQ[n*(p+1/2)+1])


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Derivation: Integration by substitution*)


(* ::Subsubsection:: *)
(*Basis: \[Integral]f[x]\[DifferentialD]x=-Subst[\[Integral]f[1/x]/x^2 \[DifferentialD]x,x,1/x]*)


(* ::Subsubsection:: *)
(*Rule: If  n\[Element]\[DoubleStruckCapitalZ] \[And] n<0, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral](c ProductLog[a x^n])^p \[DifferentialD]x  \[LongRightArrow]  -Subst[\[Integral](c ProductLog[a x^-n])^p/x^2 \[DifferentialD]x,x,1/x]*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[(c_.*ProductLog[a_.*x_^n_])^p_.,x_Symbol] :=
  -Subst[Int[(c*ProductLog[a*x^(-n)])^p/x^2,x],x,1/x] /;
FreeQ[{a,c,p},x] && IntegerQ[n] && n<0


(* ::PageBreak:: *)
(**)


(* ::Title::Bold::Closed:: *)
(*\[Integral]1/(d+d ProductLog[a x^n]) \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Derivation: Integration by substitution*)


(* ::Subsubsection:: *)
(*Basis: \[Integral]f[x]\[DifferentialD]x=-Subst[\[Integral]f[1/x]/x^2 \[DifferentialD]x,x,1/x]*)


(* ::Subsubsection:: *)
(*Rule: If  n\[Element]\[DoubleStruckCapitalZ] \[And] n<0, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]1/(d+d ProductLog[a x^n]) \[DifferentialD]x  \[LongRightArrow]  -Subst[\[Integral]1/(x^2 (d+d ProductLog[a x^-n])) \[DifferentialD]x,x,1/x]*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[1/(d_+d_.*ProductLog[a_.*x_^n_]),x_Symbol] :=
  -Subst[Int[1/(x^2*(d+d*ProductLog[a*x^(-n)])),x],x,1/x] /;
FreeQ[{a,d},x] && IntegerQ[n] && n<0


(* ::PageBreak:: *)
(**)


(* ::Title::Bold::Closed:: *)
(*\[Integral](c ProductLog[a x^n])^p/(d+d ProductLog[a x^n]) \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Rule: If  n(p-1)+1=0, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral](c ProductLog[a x^n])^p/(d+d ProductLog[a x^n]) \[DifferentialD]x  \[LongRightArrow]  ((c x (c ProductLog[a x^n])^(p-1))/d)*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[(c_.*ProductLog[a_.*x_^n_.])^p_./(d_+d_.*ProductLog[a_.*x_^n_.]),x_Symbol] :=
  c*x*(c*ProductLog[a*x^n])^(p-1)/d /;
FreeQ[{a,c,d,n,p},x] && ZeroQ[n*(p-1)+1]


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Rule: If  p\[Element]\[DoubleStruckCapitalZ] \[And] n=-(1/p), then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]ProductLog[a x^n]^p/(d+d ProductLog[a x^n]) \[DifferentialD]x  \[LongRightArrow]  ((a^p ExpIntegralEi[-p ProductLog[a x^n]])/(d n))*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[ProductLog[a_.*x_^n_.]^p_./(d_+d_.*ProductLog[a_.*x_^n_.]),x_Symbol] :=
  a^p*ExpIntegralEi[-p*ProductLog[a*x^n]]/(d*n) /;
FreeQ[{a,d},x] && IntegerQ[1/n] && ZeroQ[p+1/n]


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Rule: If  1/n\[Element]\[DoubleStruckCapitalZ] \[And] p=1/2-1/n \[And] c n>0, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral](c ProductLog[a x^n])^p/(d+d ProductLog[a x^n]) \[DifferentialD]x  \[LongRightArrow]  (Sqrt[\[Pi] c n] /(d n a^(1/n) c^(1/n)))Erfi[Sqrt[c ProductLog[a x^n]]/Sqrt[c n]]*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[(c_.*ProductLog[a_.*x_^n_.])^p_/(d_+d_.*ProductLog[a_.*x_^n_.]),x_Symbol] :=
  Rt[Pi*c*n,2]/(d*n*a^(1/n)*c^(1/n))*Erfi[Sqrt[c*ProductLog[a*x^n]]/Rt[c*n,2]] /;
FreeQ[{a,c,d},x] && IntegerQ[1/n] && ZeroQ[p-1/2+1/n] && PosQ[c*n]


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Rule: If  1/n\[Element]\[DoubleStruckCapitalZ] \[And] p=1/2-1/n \[And] c n<0, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral](c ProductLog[a x^n])^p/(d+d ProductLog[a x^n]) \[DifferentialD]x  \[LongRightArrow]  (Sqrt[-\[Pi] c n]/(d n a^(1/n) c^(1/n))) Erf[Sqrt[c ProductLog[a x^n]]/Sqrt[-c n]]*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[(c_.*ProductLog[a_.*x_^n_.])^p_/(d_+d_.*ProductLog[a_.*x_^n_.]),x_Symbol] :=
  Rt[-Pi*c*n,2]/(d*n*a^(1/n)*c^(1/n))*Erf[Sqrt[c*ProductLog[a*x^n]]/Rt[-c*n,2]] /;
FreeQ[{a,c,d},x] && IntegerQ[1/n] && ZeroQ[p-1/2+1/n] && NegQ[c*n]


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Rule: If  n>0 \[And] n(p-1)+1>0, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral](c ProductLog[a x^n])^p/(d+d ProductLog[a x^n]) \[DifferentialD]x  \[LongRightArrow]  ((c x (c ProductLog[a x^n])^(p-1))/d)-c(n (p-1)+1)\[Integral](c ProductLog[a x^n])^(p-1)/(d+d ProductLog[a x^n]) \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[(c_.*ProductLog[a_.*x_^n_.])^p_./(d_+d_.*ProductLog[a_.*x_^n_.]),x_Symbol] :=
  c*x*(c*ProductLog[a*x^n])^(p-1)/d -
  Dist[c*(n*(p-1)+1),Int[(c*ProductLog[a*x^n])^(p-1)/(d+d*ProductLog[a*x^n]),x]] /;
FreeQ[{a,c,d},x] && RationalQ[{n,p}] && n>0 && n*(p-1)+1>0


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Rule: If  n>0 \[And] n p+1<0, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral](c ProductLog[a x^n])^p/(d+d ProductLog[a x^n]) \[DifferentialD]x  \[LongRightArrow]  ((x (c ProductLog[a x^n])^p)/(d(n p+1)))-1/(c(n p+1)) \[Integral](c ProductLog[a x^n])^(p+1)/(d+d ProductLog[a x^n]) \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[(c_.*ProductLog[a_.*x_^n_.])^p_./(d_+d_.*ProductLog[a_.*x_^n_.]),x_Symbol] :=
  x*(c*ProductLog[a*x^n])^p/(d*(n*p+1)) -
  Dist[1/(c*(n*p+1)),Int[(c*ProductLog[a*x^n])^(p+1)/(d+d*ProductLog[a*x^n]),x]] /;
FreeQ[{a,c,d},x] && RationalQ[{n,p}] && n>0 && n*p+1<0


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Derivation: Integration by substitution*)


(* ::Subsubsection:: *)
(*Basis: \[Integral]f[x]\[DifferentialD]x=-Subst[\[Integral]f[1/x]/x^2 \[DifferentialD]x,x,1/x]*)


(* ::Subsubsection:: *)
(*Rule: If  n\[Element]\[DoubleStruckCapitalZ] \[And] n<0, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral](c ProductLog[a x^n])^p/(d+d ProductLog[a x^n]) \[DifferentialD]x  \[LongRightArrow]  -Subst[\[Integral](c ProductLog[a x^-n])^p/(x^2 (d+d ProductLog[a x^-n])) \[DifferentialD]x,x,1/x]*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[(c_.*ProductLog[a_.*x_^n_])^p_./(d_+d_.*ProductLog[a_.*x_^n_]),x_Symbol] :=
  -Subst[Int[(c*ProductLog[a*x^(-n)])^p/(x^2*(d+d*ProductLog[a*x^(-n)])),x],x,1/x] /;
FreeQ[{a,c,d,p},x] && IntegerQ[n] && n<0


(* ::PageBreak:: *)
(**)


(* ::Title::Bold::Closed:: *)
(*\[Integral]x^m (c ProductLog[a x^n])^p \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Subsubsection:: *)
(*Derivation: Integration by parts*)


(* ::Subsubsection:: *)
(*Rule: If  m+1!=0 \[And] (p-1/2\[Element]\[DoubleStruckCapitalZ] \[And] 2(p+(m+1)/n)\[Element]\[DoubleStruckCapitalZ] \[And]  p+(m+1)/n>0) \[Or] (\[Not](p-1/2\[Element]\[DoubleStruckCapitalZ]) \[And] p+(m+1)/n\[Element]\[DoubleStruckCapitalZ] \[And] p+(m+1)/n>=0), then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]x^m (c ProductLog[a x^n])^p \[DifferentialD]x  \[LongRightArrow]                                                                                                          *)
(*                                         ((x^(m+1) (c ProductLog[a x^n])^p)/(m+1))-(n p)/(m+1) \[Integral](x^m (c ProductLog[a x^n])^p)/(1+ProductLog[a x^n]) \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[x_^m_.*(c_.*ProductLog[a_.*x_^n_.])^p_.,x_Symbol] :=
  x^(m+1)*(c*ProductLog[a*x^n])^p/(m+1) -
  Dist[n*p/(m+1),Int[x^m*(c*ProductLog[a*x^n])^p/(1+ProductLog[a*x^n]),x]] /;
FreeQ[{a,c,m,n,p},x] && NonzeroQ[m+1] &&
(IntegerQ[p-1/2] && IntegerQ[2*Simplify[p+(m+1)/n]] && Simplify[p+(m+1)/n]>0 ||
 Not[IntegerQ[p-1/2]] && IntegerQ[Simplify[p+(m+1)/n]] && Simplify[p+(m+1)/n]>=0)


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Rule: If  m+1=0 \[Or] (p-1/2\[Element]\[DoubleStruckCapitalZ] \[And] p+(m+1)/n-1/2\[Element]\[DoubleStruckCapitalZ] \[And]  p+(m+1)/n<0) \[Or] (\[Not](p-1/2\[Element]\[DoubleStruckCapitalZ]) \[And] p+(m+1)/n\[Element]\[DoubleStruckCapitalZ] \[And] p+(m+1)/n<0), then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]x^m (c ProductLog[a x^n])^p \[DifferentialD]x  \[LongRightArrow]                                                                                                       *)
(*                 ((x^(m+1) (c ProductLog[a x^n])^p)/(m+n p+1))+(n p)/(c(m+n p+1)) \[Integral](x^m (c ProductLog[a x^n])^(p+1))/(1+ProductLog[a x^n]) \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[x_^m_.*(c_.*ProductLog[a_.*x_^n_.])^p_.,x_Symbol] :=
  x^(m+1)*(c*ProductLog[a*x^n])^p/(m+n*p+1) +
  Dist[n*p/(c*(m+n*p+1)),Int[x^m*(c*ProductLog[a*x^n])^(p+1)/(1+ProductLog[a*x^n]),x]] /;
FreeQ[{a,c,m,n,p},x] &&
(ZeroQ[m+1] ||
 IntegerQ[p-1/2] && IntegerQ[Simplify[p+(m+1)/n]-1/2] && Simplify[p+(m+1)/n]<0 ||
 Not[IntegerQ[p-1/2]] && IntegerQ[Simplify[p+(m+1)/n]] && Simplify[p+(m+1)/n]<0)


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Derivation: Algebraic simplification*)


(* ::Subsubsection:: *)
(*Basis: 1=1/(1+z)+z/(1+z)*)


(* ::Subsubsection:: *)
(*Rule:*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]x^m (c ProductLog[a x])^p \[DifferentialD]x  \[LongRightArrow]  \[Integral](x^m (c ProductLog[a x])^p)/(1+ProductLog[a x]) \[DifferentialD]x+1/c \[Integral](x^m (c ProductLog[a x])^(p+1))/(1+ProductLog[a x]) \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[x_^m_.*(c_.*ProductLog[a_.*x_])^p_.,x_Symbol] :=
  Int[x^m*(c*ProductLog[a*x])^p/(1+ProductLog[a*x]),x] +
  Dist[1/c,Int[x^m*(c*ProductLog[a*x])^(p+1)/(1+ProductLog[a*x]),x]] /;
FreeQ[{a,c,m},x]


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Derivation: Integration by substitution*)


(* ::Subsubsection:: *)
(*Basis: \[Integral]f[x]\[DifferentialD]x=-Subst[\[Integral]f[1/x]/x^2 \[DifferentialD]x,x,1/x]*)


(* ::Subsubsection:: *)
(*Rule: If  m,n\[Element]\[DoubleStruckCapitalZ] \[And] n<0 \[And] m+1!=0, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]x^m (c ProductLog[a x^n])^p \[DifferentialD]x  \[LongRightArrow]  -Subst[\[Integral](c ProductLog[a x^-n])^p/x^(m+2) \[DifferentialD]x,x,1/x]*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[x_^m_.*(c_.*ProductLog[a_.*x_^n_])^p_.,x_Symbol] :=
  -Subst[Int[(c*ProductLog[a*x^(-n)])^p/x^(m+2),x],x,1/x] /;
FreeQ[{a,c,p},x] && IntegersQ[m,n] && n<0 && NonzeroQ[m+1]


(* ::PageBreak:: *)
(**)


(* ::Title::Bold::Closed:: *)
(*\[Integral]x^m/(d+d ProductLog[a x^n]) \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Rule:*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]1/(x(d+d ProductLog[a x^n])) \[DifferentialD]x  \[LongRightArrow]  (Log[ProductLog[a x^n]]/(d n))*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[1/(x_*(d_+d_.*ProductLog[a_.*x_^n_.])),x_Symbol] :=
  Log[ProductLog[a*x^n]]/(d*n) /;
FreeQ[{a,d,n},x]


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Rule: If  m>0, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]x^m/(d+d ProductLog[a x]) \[DifferentialD]x  \[LongRightArrow]                                                                                                               *)
(*       (x^(m+1)/(d(m+1) ProductLog[a x]))-m/(m+1) \[Integral]x^m/(ProductLog[a x] (d+d ProductLog[a x])) \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[x_^m_./(d_+d_.*ProductLog[a_.*x_]),x_Symbol] :=
  x^(m+1)/(d*(m+1)*ProductLog[a*x]) -
  Dist[m/(m+1),Int[x^m/(ProductLog[a*x]*(d+d*ProductLog[a*x])),x]] /;
FreeQ[{a,d},x] && RationalQ[m] && m>0


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Rule: If  m<-1, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]x^m/(d+d ProductLog[a x]) \[DifferentialD]x  \[LongRightArrow]  (x^(m+1)/(d(m+1)))-\[Integral](x^m ProductLog[a x])/(d+d ProductLog[a x]) \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[x_^m_./(d_+d_.*ProductLog[a_.*x_]),x_Symbol] :=
  x^(m+1)/(d*(m+1)) -
  Int[x^m*ProductLog[a*x]/(d+d*ProductLog[a*x]),x] /;
FreeQ[{a,d},x] && RationalQ[m] && m<-1


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Rule: If  m+1!=0, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]x^m/(d+d ProductLog[a x]) \[DifferentialD]x  \[LongRightArrow]  ((x^m Gamma[m+1,-(m+1) ProductLog[a x]])/(a d(m+1) E^(m ProductLog[a x]) (-(m+1) ProductLog[a x])^m))*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[x_^m_./(d_+d_.*ProductLog[a_.*x_]),x_Symbol] :=
  x^m*Gamma[m+1,-(m+1)*ProductLog[a*x]]/
	(a*d*(m+1)*E^(m*ProductLog[a*x])*(-(m+1)*ProductLog[a*x])^m) /;
FreeQ[{a,d},x] && NonzeroQ[m+1]


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Derivation: Integration by substitution*)


(* ::Subsubsection:: *)
(*Basis: \[Integral]f[x]\[DifferentialD]x=-Subst[\[Integral]f[1/x]/x^2 \[DifferentialD]x,x,1/x]*)


(* ::Subsubsection:: *)
(*Rule: If  m,n\[Element]\[DoubleStruckCapitalZ] \[And] n<0 \[And] m+1!=0, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]x^m/(d+d ProductLog[a x^n]) \[DifferentialD]x  \[LongRightArrow]  -Subst[\[Integral]1/(x^(m+2) (d+d ProductLog[a x^-n])) \[DifferentialD]x,x,1/x]*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[x_^m_./(d_+d_.*ProductLog[a_.*x_^n_]),x_Symbol] :=
  -Subst[Int[1/(x^(m+2)*(d+d*ProductLog[a*x^(-n)])),x],x,1/x] /;
FreeQ[{a,d},x] && IntegersQ[m,n] && n<0 && NonzeroQ[m+1]


(* ::PageBreak:: *)
(**)


(* ::Title::Bold::Closed:: *)
(*\[Integral](x^m (c ProductLog[a x^n])^p)/(d+d ProductLog[a x^n]) \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Rule:*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral](c ProductLog[a x^n])^p/(x(d+d ProductLog[a x^n])) \[DifferentialD]x  \[LongRightArrow]  ((c ProductLog[a x^n])^p/(d n p))*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[(c_.*ProductLog[a_.*x_^n_.])^p_./(x_*(d_+d_.*ProductLog[a_.*x_^n_.])),x_Symbol] :=
  (c*ProductLog[a*x^n])^p/(d*n*p) /;
FreeQ[{a,c,d,n,p},x]


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Rule: If  m+n(p-1)+1=0 \[And] m+1!=0, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral](x^m (c ProductLog[a x^n])^p)/(d+d ProductLog[a x^n]) \[DifferentialD]x  \[LongRightArrow]  ((c x^(m+1) (c ProductLog[a x^n])^(p-1))/(d (m+1)))*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[x_^m_.*(c_.*ProductLog[a_.*x_^n_.])^p_./(d_+d_.*ProductLog[a_.*x_^n_.]),x_Symbol] :=
  c*x^(m+1)*(c*ProductLog[a*x^n])^(p-1)/(d*(m+1)) /;
FreeQ[{a,c,d,m,n,p},x] && ZeroQ[m+n*(p-1)+1] && NonzeroQ[m+1]


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Rule: If  p\[Element]\[DoubleStruckCapitalZ] \[And] m+n p+1=0, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral](x^m ProductLog[a x^n]^p)/(d+d ProductLog[a x^n]) \[DifferentialD]x  \[LongRightArrow]  ((a^p ExpIntegralEi[-p ProductLog[a x^n]])/(d n))*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[x_^m_.*ProductLog[a_.*x_^n_.]^p_./(d_+d_.*ProductLog[a_.*x_^n_.]),x_Symbol] :=
  a^p*ExpIntegralEi[-p*ProductLog[a*x^n]]/(d*n) /;
FreeQ[{a,d,m,n},x] && IntegerQ[p] && ZeroQ[m+n*p+1]


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Rule: If  p-1/2\[Element]\[DoubleStruckCapitalZ] \[And] p-1/2!=0 \[And] m+n(p-1/2)+1=0 \[And] c/(p-1/2)>0, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral](x^m (c ProductLog[a x^n])^p)/(d+d ProductLog[a x^n]) \[DifferentialD]x  \[LongRightArrow]  (((a^(p-1/2)) (c^(p-1/2)) )/(d n )) Sqrt[(\[Pi] c)/(p-1/2)]Erf[Sqrt[c ProductLog[a x^n]]/Sqrt[c/(p-1/2)]]*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[x_^m_.*(c_.*ProductLog[a_.*x_^n_.])^p_/(d_+d_.*ProductLog[a_.*x_^n_.]),x_Symbol] :=
  a^(p-1/2)*c^(p-1/2)*Rt[Pi*c/(p-1/2),2]*Erf[Sqrt[c*ProductLog[a*x^n]]/Rt[c/(p-1/2),2]]/(d*n) /;
FreeQ[{a,c,d,m,n},x] && IntegerQ[p-1/2] && p-1/2!=0 && ZeroQ[m+n*(p-1/2)+1] && PosQ[c/(p-1/2)]


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Rule: If  p-1/2\[Element]\[DoubleStruckCapitalZ] \[And] p-1/2!=0 \[And] m+n(p-1/2)+1=0 \[And] c/(p-1/2)<0, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral](x^m (c ProductLog[a x^n])^p)/(d+d ProductLog[a x^n]) \[DifferentialD]x  \[LongRightArrow]  (((a^(p-1/2)) (c^(p-1/2)) )/(d n )) Sqrt[-((\[Pi] c)/(p-1/2))]Erfi[Sqrt[c ProductLog[a x^n]]/Sqrt[-(c/(p-1/2))]]*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[x_^m_.*(c_.*ProductLog[a_.*x_^n_.])^p_/(d_+d_.*ProductLog[a_.*x_^n_.]),x_Symbol] :=
  a^(p-1/2)*c^(p-1/2)*Rt[-Pi*c/(p-1/2),2]*Erfi[Sqrt[c*ProductLog[a*x^n]]/Rt[-c/(p-1/2),2]]/(d*n) /;
FreeQ[{a,c,d,m,n},x] && IntegerQ[p-1/2] && p-1/2!=0 && ZeroQ[m+n*(p-1/2)+1] && NegQ[c/(p-1/2)]


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Rule: If  m+1!=0 \[And] p+(m+1)/n>1, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral](x^m (c ProductLog[a x^n])^p)/(d+d ProductLog[a x^n]) \[DifferentialD]x  \[LongRightArrow]                                                                                                                                     *)
(*                  ((c x^(m+1) (c ProductLog[a x^n])^(p-1))/(d(m+1)))-(c(m+n (p-1)+1))/(m+1) \[Integral](x^m (c ProductLog[a x^n])^(p-1))/(d+d ProductLog[a x^n]) \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[x_^m_.*(c_.*ProductLog[a_.*x_^n_.])^p_./(d_+d_.*ProductLog[a_.*x_^n_.]),x_Symbol] :=
  c*x^(m+1)*(c*ProductLog[a*x^n])^(p-1)/(d*(m+1)) -
  Dist[c*(m+n*(p-1)+1)/(m+1),Int[x^m*(c*ProductLog[a*x^n])^(p-1)/(d+d*ProductLog[a*x^n]),x]] /;
FreeQ[{a,c,d,m,n,p},x] && NonzeroQ[m+1] && RationalQ[Simplify[p+(m+1)/n]] && Simplify[p+(m+1)/n]>1


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Rule: If  m+1!=0 \[And] p+(m+1)/n<0, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral](x^m (c ProductLog[a x^n])^p)/(d+d ProductLog[a x^n]) \[DifferentialD]x  \[LongRightArrow]                                                                                                                                      *)
(*                                        ((x^(m+1) (c ProductLog[a x^n])^p)/(d(m+n p+1)))-(m+1)/(c(m+n p+1)) \[Integral](x^m (c ProductLog[a x^n])^(p+1))/(d+d ProductLog[a x^n]) \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[x_^m_.*(c_.*ProductLog[a_.*x_^n_.])^p_./(d_+d_.*ProductLog[a_.*x_^n_.]),x_Symbol] :=
  x^(m+1)*(c*ProductLog[a*x^n])^p/(d*(m+n*p+1)) -
  Dist[(m+1)/(c*(m+n*p+1)),Int[x^m*(c*ProductLog[a*x^n])^(p+1)/(d+d*ProductLog[a*x^n]),x]] /;
FreeQ[{a,c,d,m,n,p},x] && NonzeroQ[m+1] && RationalQ[Simplify[p+(m+1)/n]] && Simplify[p+(m+1)/n]<0


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Rule: If  m+1!=0, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral](x^m (c ProductLog[a x])^p)/(d+d ProductLog[a x]) \[DifferentialD]x  \[LongRightArrow]  ((x^m Gamma[m+p+1,-(m+1) ProductLog[a x]] (c ProductLog[a x])^p)/(a d(m+1) E^(m ProductLog[a x]) (-(m+1) ProductLog[a x])^(m+p)))*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[x_^m_.*(c_.*ProductLog[a_.*x_])^p_./(d_+d_.*ProductLog[a_.*x_]),x_Symbol] :=
  x^m*Gamma[m+p+1,-(m+1)*ProductLog[a*x]]*(c*ProductLog[a*x])^p/
	(a*d*(m+1)*E^(m*ProductLog[a*x])*(-(m+1)*ProductLog[a*x])^(m+p)) /;
FreeQ[{a,c,d,m,p},x] && NonzeroQ[m+1]


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Derivation: Integration by substitution*)


(* ::Subsubsection:: *)
(*Basis: \[Integral]f[x]\[DifferentialD]x=-Subst[\[Integral]f[1/x]/x^2 \[DifferentialD]x,x,1/x]*)


(* ::Subsubsection:: *)
(*Rule: If  m,n\[Element]\[DoubleStruckCapitalZ] \[And] n<0 \[And] m+1!=0, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral](x^m (c ProductLog[a x^n])^p)/(d+d ProductLog[a x^n]) \[DifferentialD]x  \[LongRightArrow]  -Subst[\[Integral](c ProductLog[a x^-n])^p/(x^(m+2) (d+d ProductLog[a x^-n])) \[DifferentialD]x,x,1/x]*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[x_^m_.*(c_.*ProductLog[a_.*x_^n_.])^p_./(d_+d_.*ProductLog[a_.*x_^n_.]),x_Symbol] :=
  -Subst[Int[(c*ProductLog[a*x^(-n)])^p/(x^(m+2)*(d+d*ProductLog[a*x^(-n)])),x],x,1/x] /;
FreeQ[{a,c,d,p},x] && IntegersQ[m,n] && n<0 && NonzeroQ[m+1]


(* ::PageBreak:: *)
(**)


(* ::Title::Bold::Closed:: *)
(*\[Integral]f[ProductLog[a+b x]]\[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Author: Rob Corless 2009-07-10*)


(* ::Subsubsection:: *)
(*Derivation:  Legendre substitution for inverse functions*)


(* ::Subsubsection:: *)
(*Basis: f[ProductLog[x]]=(ProductLog[z]+1) E^ProductLog[z] f[ProductLog[x]] Derivative[1][ProductLog][z]*)


(* ::Subsubsection:: *)
(*Rule:*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]f[ProductLog[x]]\[DifferentialD]x  \[LongRightArrow]  Subst[\[Integral](x+1) E^x f[x]\[DifferentialD]x,x,ProductLog[x]]*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[u_,x_Symbol] :=
  Subst[Int[Regularize[(x+1)*E^x*SubstFor[ProductLog[x],u,x],x],x],x,ProductLog[x]] /;
FunctionOfQ[ProductLog[x],u,x]
