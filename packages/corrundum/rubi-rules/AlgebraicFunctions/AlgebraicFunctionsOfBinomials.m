(* ::Package:: *)

(* ::Title::Bold::Closed:: *)
(*\[Integral]1/(a+b x^n) \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Derivation: Algebraic expansion*)


(* ::Subsubsection:: *)
(*Basis: 1/(a+b z^n)=1/a-b/(a (b+a z^-n))*)


(* ::Subsubsection:: *)
(*Rule: If  n\[Element]\[DoubleStruckCapitalF] \[And] n<0, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]1/(a+b x^n) \[DifferentialD]x  \[LongRightArrow]  (x/a)-b/a \[Integral]1/(b+a x^-n) \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[1/(a_+b_.*x_^n_),x_Symbol] :=
  x/a - Dist[b/a,Int[1/(b+a*x^(-n)),x]] /;
FreeQ[{a,b},x] && FractionQ[n] && n<0


(* ::PageBreak:: *)
(**)


(* ::Title::Bold::Closed:: *)
(*\[Integral]1/Sqrt[a+b x^n] \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Reference: CRC 278*)


(* ::Subsubsection:: *)
(*Derivation: Primitive rule*)


(* ::Subsubsection:: *)
(*Basis: Derivative[1][ArcSinh][z]=1/Sqrt[1+z^2]*)


(* ::Subsubsection:: *)
(*Rule: If  a>0 \[And] b>0, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]1/Sqrt[a+b x^2] \[DifferentialD]x  \[LongRightArrow]   ArcSinh[(Sqrt[b] x)/Sqrt[a]]*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[1/Sqrt[a_+b_.*x_^2],x_Symbol] :=
  ArcSinh[Rt[b,2]*x/Sqrt[a]]/Rt[b,2] /;
FreeQ[{a,b},x] && PositiveQ[a] && PosQ[b]


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Reference: G&R 2.271.4b, CRC 279, A&S 3.3.44*)


(* ::Subsubsection:: *)
(*Derivation: Primitive rule*)


(* ::Subsubsection:: *)
(*Basis: Derivative[1][ArcSin][z]=1/Sqrt[1-z^2]*)


(* ::Subsubsection:: *)
(*Rule: If  a>0 \[And] \[Not](b>0), then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]1/Sqrt[a+b x^2] \[DifferentialD]x  \[LongRightArrow]  (1/Sqrt[-b]) ArcSin[(Sqrt[-b] x)/Sqrt[a]]*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[1/Sqrt[a_+b_.*x_^2],x_Symbol] :=
  ArcSin[Rt[-b,2]*x/Sqrt[a]]/Rt[-b,2] /;
FreeQ[{a,b},x] && PositiveQ[a] && NegQ[b]


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Reference: CRC 278'*)


(* ::Subsubsection:: *)
(*Rule: If  \[Not](a>0) \[And] b>0, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]1/Sqrt[a+b x^2] \[DifferentialD]x  \[LongRightArrow]  (1/Sqrt[b])ArcTanh[(Sqrt[b] x)/Sqrt[a+b x^2]]*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[1/Sqrt[a_+b_.*x_^2],x_Symbol] :=
  ArcTanh[Rt[b,2]*x/Sqrt[a+b*x^2]]/Rt[b,2] /;
FreeQ[{a,b},x] && Not[PositiveQ[a]] && PosQ[b]


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Reference: CRC 279'*)


(* ::Subsubsection:: *)
(*Rule: If  \[Not](a>0) \[And] \[Not](b>0), then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]1/Sqrt[a+b x^2] \[DifferentialD]x  \[LongRightArrow]  (1/Sqrt[-b])ArcTan[(Sqrt[-b] x)/Sqrt[a+b x^2]]*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[1/Sqrt[a_+b_.*x_^2],x_Symbol] :=
  ArcTan[Rt[-b,2]*x/Sqrt[a+b*x^2]]/Rt[-b,2] /;
FreeQ[{a,b},x] && Not[PositiveQ[a]] && NegQ[b]


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Rule: If  a>0, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]1/Sqrt[a+b x^4] \[DifferentialD]x  \[LongRightArrow]  (1/(Sqrt[a] (-(b/a))^(1/4))) EllipticF[ArcSin[(-(b/a))^(1/4) x],-1]*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[1/Sqrt[a_+b_.*x_^4],x_Symbol] :=
  EllipticF[ArcSin[Rt[-b/a,4]*x],-1]/(Sqrt[a]*Rt[-b/a,4]) /;
FreeQ[{a,b},x] && PositiveQ[a]


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Basis: \!\( *)
(*\*SubscriptBox[\(\[PartialD]\), \(x\)]*)
(*\*FractionBox[\( *)
(*\*SqrtBox[\(a\)]\ *)
(*\*SqrtBox[*)
(*FractionBox[\(a + b\ *)
(*\*SuperscriptBox[\(x\), \(4\)]\), \(a\)]]\), *)
(*SqrtBox[\(a + b\ *)
(*\*SuperscriptBox[\(x\), \(4\)]\)]]\)=0*)


(* ::Subsubsection:: *)
(*Rule: If  \[Not](a>0), then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]1/Sqrt[a+b x^4] \[DifferentialD]x  \[LongRightArrow]  (Sqrt[((a+b x^4)/a)] /((-(b/a))^(1/4) Sqrt[a+b x^4]))EllipticF[ArcSin[(-(b/a))^(1/4) x],-1]*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[1/Sqrt[a_+b_.*x_^4],x_Symbol] :=
  Sqrt[(a+b*x^4)/a]/(Rt[-b/a,4]*Sqrt[a+b*x^4])*EllipticF[ArcSin[Rt[-b/a,4]*x],-1] /;
FreeQ[{a,b},x] && Not[PositiveQ[a]]


(* ::PageBreak:: *)
(**)


(* ::Title::Bold::Closed:: *)
(*\[Integral]x^m/Sqrt[a+b x^n] \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Rule: If  a>0, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]x^2/Sqrt[a+b x^4] \[DifferentialD]x  \[LongRightArrow]  (1/(Sqrt[a] (-(b/a))^(3/4)))EllipticE[ArcSin[(-(b/a))^(1/4) x],-1]-*)
(*                                       1/(Sqrt[a] (-(b/a))^(3/4)) EllipticF[ArcSin[(-(b/a))^(1/4) x],-1]*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[x_^2/Sqrt[a_+b_.*x_^4],x_Symbol] :=
  1/(Sqrt[a]*Rt[-b/a,4]^3)*EllipticE[ArcSin[Rt[-b/a,4]*x],-1] -
  1/(Sqrt[a]*Rt[-b/a,4]^3)*EllipticF[ArcSin[Rt[-b/a,4]*x],-1] /;
FreeQ[{a,b},x] && PositiveQ[a]


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Basis: \!\( *)
(*\*SubscriptBox[\(\[PartialD]\), \(x\)]*)
(*\*FractionBox[\( *)
(*\*SqrtBox[\(a\)]\ *)
(*\*SqrtBox[*)
(*FractionBox[\(a + b\ *)
(*\*SuperscriptBox[\(x\), \(4\)]\), \(a\)]]\), *)
(*SqrtBox[\(a + b\ *)
(*\*SuperscriptBox[\(x\), \(4\)]\)]]\)=0*)


(* ::Subsubsection:: *)
(*Rule: If  \[Not](a>0), then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]x^2/Sqrt[a+b x^4] \[DifferentialD]x  \[LongRightArrow]  (Sqrt[((a+b x^4)/a)]/((-(b/a))^(3/4) Sqrt[a+b x^4]))EllipticE[ArcSin[(-(b/a))^(1/4) x],-1]-*)
(*                                       Sqrt[(a+b x^4)/a]/((-(b/a))^(3/4) Sqrt[a+b x^4]) EllipticF[ArcSin[(-(b/a))^(1/4) x],-1]*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[x_^2/Sqrt[a_+b_.*x_^4],x_Symbol] :=
  Sqrt[(a+b*x^4)/a]/(Rt[-b/a,4]^3*Sqrt[a+b*x^4])*EllipticE[ArcSin[Rt[-b/a,4]*x],-1] -
  Sqrt[(a+b*x^4)/a]/(Rt[-b/a,4]^3*Sqrt[a+b*x^4])*EllipticF[ArcSin[Rt[-b/a,4]*x],-1] /;
FreeQ[{a,b},x] && Not[PositiveQ[a]]


(* ::PageBreak:: *)
(**)


(* ::Title::Bold::Closed:: *)
(*\[Integral](a+b x^n)^p \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Derivation: Integration by substitution*)


(* ::Subsubsection:: *)
(*Basis: Sqrt[a+b/z^2]=-(Sqrt[a+b (1/z)^2] /(1/z)^2)\!\( *)
(*\*SubscriptBox[\(\[PartialD]\), \(z\)]*)
(*\*FractionBox[\(1\), \(z\)]\)*)


(* ::Subsubsection:: *)
(*Rule:*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]Sqrt[a+b/x^2]\[DifferentialD]x  \[LongRightArrow]  -Subst[\[Integral]Sqrt[a+b x^2]/x^2 \[DifferentialD]x,x,1/x]*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[Sqrt[a_.+b_./x_^2],x_Symbol] :=
  -Subst[Int[Sqrt[a+b*x^2]/x^2,x],x,1/x] /;
FreeQ[{a,b},x]


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Reference: G&R 2.110.2', CRC 88d'*)


(* ::Subsubsection:: *)
(*Rule: If  n (p+1)+1=0, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral](a+b x^n)^p \[DifferentialD]x  \[LongRightArrow]  ((x (a+b x^n)^(p+1))/a)*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[(a_+b_.*x_^n_)^p_,x_Symbol] :=
  x*(a+b*x^n)^(p+1)/a /;
FreeQ[{a,b,n,p},x] && ZeroQ[n*(p+1)+1]


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Reference: G&R 2.110.1, CRC 88b*)


(* ::Subsubsection:: *)
(*Rule: If  p\[Element]\[DoubleStruckCapitalF] \[And] p>0 \[And] n p+1!=0, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral](a+b x^n)^p \[DifferentialD]x  \[LongRightArrow]  ((x (a+b x^n)^p)/(n p+1))+(a n p)/(n p+1) \[Integral](a+b x^n)^(p-1) \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[(a_+b_.*x_^n_)^p_,x_Symbol] :=
  x*(a+b*x^n)^p/(n*p+1) +
  Dist[a*n*p/(n*p+1),Int[(a+b*x^n)^(p-1),x]] /;
FreeQ[{a,b,n},x] && FractionQ[p] && p>0 && NonzeroQ[n*p+1]


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Reference: G&R 2.110.2, CRC 88d*)


(* ::Subsubsection:: *)
(*Rule: If  p\[Element]\[DoubleStruckCapitalF] \[And] p<-1, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral](a+b x^n)^p \[DifferentialD]x  \[LongRightArrow]  -((x (a+b x^n)^(p+1))/(a n (p+1)))+(n (p+1)+1)/(a n (p+1)) \[Integral](a+b x^n)^(p+1) \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[(a_+b_.*x_^n_)^p_,x_Symbol] :=
  -x*(a+b*x^n)^(p+1)/(n*(p+1)*a) +
  Dist[(n*(p+1)+1)/(a*n*(p+1)),Int[(a+b*x^n)^(p+1),x]] /;
FreeQ[{a,b,n},x] && FractionQ[p] && p<-1


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Reference: G&R 2.110.6, CRC 88c*)


(* ::Subsubsection:: *)
(*Rule: If  p\[NotElement]\[DoubleStruckCapitalZ], then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral](a+b/x)^p \[DifferentialD]x  \[LongRightArrow]  ((x (a+b/x)^(p+1))/a)+(b p)/a \[Integral](a+b/x)^p/x \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[(a_+b_./x_)^p_,x_Symbol] :=
  x*(a+b/x)^(p+1)/a +
  Dist[b*p/a,Int[(a+b/x)^p/x,x]] /;
FreeQ[{a,b,p},x] && Not[IntegerQ[p]]


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Derivation: Integration by substitution*)


(* ::Subsubsection:: *)
(*Note: Transforms p into an integer.*)


(* ::Subsubsection:: *)
(*Rule: If  -1<p<0 \[And] p+1/n\[Element]\[DoubleStruckCapitalZ], let q=Denominator[p], then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral](a+b x^n)^p \[DifferentialD]x  \[LongRightArrow]  ((q a^(p+1/n))/n)Subst[\[Integral]x^(q/n-1)/(1-b x^q)^(p+1/n+1) \[DifferentialD]x,x,x^(n/q)/(a+b x^n)^(1/q)]*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[(a_+b_.*x_^n_)^p_,x_Symbol] :=
  Module[{q=Denominator[p]},
  Dist[q*a^(p+1/n)/n,
	Subst[Int[x^(q/n-1)/(1-b*x^q)^(p+1/n+1),x],x,x^(n/q)/(a+b*x^n)^(1/q)]]] /;
FreeQ[{a,b},x] && RationalQ[{p,n}] && -1<p<0 && IntegerQ[p+1/n]


(* ::PageBreak:: *)
(**)


(* ::Title::Bold::Closed:: *)
(*\[Integral](a+b (c x^n)^m)^p \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Derivation: Integration by substitution*)


(* ::Subsubsection:: *)
(*Basis: f[(c x^n)^(1/n)]=x/(c x^n)^(1/n) f[(c x^n)^(1/n)]\!\( *)
(*\*SubscriptBox[\(\[PartialD]\), \(x\)]*)
(*\*SuperscriptBox[\((c\ *)
(*\*SuperscriptBox[\(x\), \(n\)])\), \(1/n\)]\)*)


(* ::Subsubsection:: *)
(*Basis: \!\( *)
(*\*SubscriptBox[\(\[PartialD]\), \(x\)]*)
(*\*FractionBox[\(x\), *)
(*SuperscriptBox[\((c\ *)
(*\*SuperscriptBox[\(x\), \(n\)])\), \(1/n\)]]\)=0*)


(* ::Subsubsection:: *)
(*Rule: If  m n\[Element]\[DoubleStruckCapitalZ], then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral](a+b (c x^n)^m)^p \[DifferentialD]x  \[LongRightArrow]  (x/(c x^n)^(1/n))Subst[\[Integral](a+b x^(m n))^p \[DifferentialD]x,x,(c x^n)^(1/n)]*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[(a_+b_.*(c_.*x_^n_)^m_)^p_.,x_Symbol] :=
  Dist[x/(c*x^n)^(1/n),Subst[Int[(a+b*x^(m*n))^p,x],x,(c*x^n)^(1/n)]] /;
FreeQ[{a,b,c,m,n,p},x] && IntegerQ[m*n]


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Derivation: Integration by substitution*)


(* ::Subsubsection:: *)
(*Basis: f[(c x^n)^(1/n)]=x/(c x^n)^(1/n) f[(c x^n)^(1/n)]\!\( *)
(*\*SubscriptBox[\(\[PartialD]\), \(x\)]*)
(*\*SuperscriptBox[\((c\ *)
(*\*SuperscriptBox[\(x\), \(n\)])\), \(1/n\)]\)*)


(* ::Subsubsection:: *)
(*Basis: \!\( *)
(*\*SubscriptBox[\(\[PartialD]\), \(x\)]*)
(*\*FractionBox[\(x\), *)
(*SuperscriptBox[\((c\ *)
(*\*SuperscriptBox[\(x\), \(n\)])\), \(1/n\)]]\)=0*)


(* ::Subsubsection:: *)
(*Note: This previously unknown rule not yet implemented.*)


(* ::Subsubsection:: *)
(*Rule:*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]f[(c x^n)^(1/n)]\[DifferentialD]x  \[LongRightArrow]  (x/(c x^n)^(1/n))Subst[\[Integral]f[x]\[DifferentialD]x,x,(c x^n)^(1/n)]*)


(* ::PageBreak:: *)
(**)


(* ::Title::Bold::Closed:: *)
(*\[Integral]x^m (a+b x^n)^p \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Derivation: Integration by substitution*)


(* ::Subsubsection:: *)
(*Basis: If m+1!=0 and n/(m+1)\[Element]\[DoubleStruckCapitalZ], then  x^m (a+b x^n)^p=1/(m+1) (a+b (x^(m+1))^(n/(m+1)))^p \!\( *)
(*\*SubscriptBox[\(\[PartialD]\), \(x\)]*)
(*\*SuperscriptBox[\(x\), \(m + 1\)]\)*)


(* ::Subsubsection:: *)
(*Rule: If  m+1!=0 \[And] n/(m+1)\[Element]\[DoubleStruckCapitalZ] \[And] n/(m+1)>1, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]x^m (a+b x^n)^p \[DifferentialD]x  \[LongRightArrow]  (1/(m+1))Subst[\[Integral](a+b x^(n/(m+1)))^p \[DifferentialD]x,x,x^(m+1)]*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[x_^m_.*(a_.+b_.*x_^n_)^p_.,x_Symbol] :=
  Dist[1/(m+1),Subst[Int[(a+b*x^(n/(m+1)))^p,x],x,x^(m+1)]] /;
FreeQ[{a,b,m,n,p},x] && NonzeroQ[m+1] && IntegerQ[n/(m+1)] && n/(m+1)>1 && Not[IntegersQ[m,n,p]]


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Derivation: Algebraic simplification*)


(* ::Subsubsection:: *)
(*Basis: If p\[Element]\[DoubleStruckCapitalZ], then  x^m (a+b x^n)^p=x^(m+n p) (b+a/x^n)^p*)


(* ::Subsubsection:: *)
(*Rule: If  p\[Element]\[DoubleStruckCapitalZ] \[And] p<0 \[And] n\[Element]\[DoubleStruckCapitalF] \[And] n<0, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]x^m (a+b x^n)^p \[DifferentialD]x  \[LongRightArrow]  \[Integral]x^(m+n p) (b+a/x^n)^p \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[x_^m_.*(a_+b_.*x_^n_)^p_,x_Symbol] :=
  Int[x^(m+n*p)*(b+a/x^n)^p,x] /;
FreeQ[{a,b,m},x] && IntegerQ[p] && p<0 && FractionQ[n] && n<0


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Reference: G&R 2.110.3*)


(* ::Subsubsection:: *)
(*Derivation: Integration by parts*)


(* ::Subsubsection:: *)
(*Rule: If  m,n\[Element]\[DoubleStruckCapitalZ] \[And] p\[Element]\[DoubleStruckCapitalF] \[And] p>0 \[And] ((n>0 \[And] m<-1) \[Or] 0<-n<=m+1), then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]x^m (a+b x^n)^p \[DifferentialD]x  \[LongRightArrow]  ((x^(m+1) (a+b x^n)^p)/(m+1))-(b n p)/(m+1) \[Integral]x^(m+n) (a+b x^n)^(p-1) \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[x_^m_.*(a_+b_.*x_^n_)^p_,x_Symbol] :=
  x^(m+1)*(a+b*x^n)^p/(m+1) -
  Dist[b*n*p/(m+1),Int[x^(m+n)*(a+b*x^n)^(p-1),x]] /;
FreeQ[{a,b},x] && IntegersQ[m,n] && FractionQ[p] && p>0 && (n>0 && m<-1 || 0<-n<=m+1)


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Reference: G&R 2.110.4*)


(* ::Subsubsection:: *)
(*Derivation: Integration by parts*)


(* ::Subsubsection:: *)
(*Basis: x^m (a+b x^n)^p=x^(m-n+1) ((a+b x^n)^p x^(n-1))*)


(* ::Subsubsection:: *)
(*Rule: If  m,n\[Element]\[DoubleStruckCapitalZ] \[And] p\[Element]\[DoubleStruckCapitalF] \[And] p<-1 \[And] (0<n<=m \[Or] m<=n<0) \[And] m-n+1!=0, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]x^m (a+b x^n)^p \[DifferentialD]x  \[LongRightArrow]  ((x^(m-n+1) (a+b x^n)^(p+1))/(b n (p+1)))-(m-n+1)/(b n (p+1)) \[Integral]x^(m-n) (a+b x^n)^(p+1) \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[x_^m_.*(a_+b_.*x_^n_)^p_,x_Symbol] :=
  x^(m-n+1)*(a+b*x^n)^(p+1)/(b*n*(p+1)) -
  Dist[(m-n+1)/(b*n*(p+1)),Int[x^(m-n)*(a+b*x^n)^(p+1),x]] /;
FreeQ[{a,b},x] && IntegersQ[m,n] && FractionQ[p] && p<-1 && (0<n<=m || m<=n<0) && NonzeroQ[m-n+1]


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Reference: G&R 2.110.1, CRC 88b*)


(* ::Subsubsection:: *)
(*Rule: If  p\[Element]\[DoubleStruckCapitalF] \[And] p>0 \[And] m+n p+1!=0 \[And] \[Not]((m+1)/n\[Element]\[DoubleStruckCapitalZ] \[And] (m+1)/n>0), then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]x^m (a+b x^n)^p \[DifferentialD]x  \[LongRightArrow]  ((x^(m+1) (a+b x^n)^p)/(m+n p+1))+(n p a)/(m+n p+1) \[Integral]x^m (a+b x^n)^(p-1) \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[x_^m_.*(a_+b_.*x_^n_)^p_,x_Symbol] :=
  x^(m+1)*(a+b*x^n)^p/(m+n*p+1) +
  Dist[n*p*a/(m+n*p+1),Int[x^m*(a+b*x^n)^(p-1),x]] /;
FreeQ[{a,b,m,n,p},x] && FractionQ[p] && p>0 && NonzeroQ[m+n*p+1] &&
Not[IntegerQ[(m+1)/n] && (m+1)/n>0]


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Reference: G&R 2.110.2, CRC 88d*)


(* ::Subsubsection:: *)
(*Rule: If  p\[Element]\[DoubleStruckCapitalF] \[And] p<-1 \[And] m+n(p+1)+1!=0 \[And] m-n+1!=0, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]x^m (a+b x^n)^p \[DifferentialD]x  \[LongRightArrow]  -((x^(m+1) (a+b x^n)^(p+1))/(a n (p+1)))+(m+n (p+1)+1)/(a n (p+1)) \[Integral]x^m (a+b x^n)^(p+1) \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[x_^m_.*(a_+b_.*x_^n_)^p_,x_Symbol] :=
  -x^(m+1)*(a+b*x^n)^(p+1)/(a*n*(p+1)) +
  Dist[(m+n*(p+1)+1)/(a*n*(p+1)),Int[x^m*(a+b*x^n)^(p+1),x]] /;
FreeQ[{a,b,m,n},x] && FractionQ[p] && p<-1 && NonzeroQ[m+n*(p+1)+1] && NonzeroQ[m-n+1]


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Reference: G&R 2.110.5, CRC 88a*)


(* ::Subsubsection:: *)
(*Rule: If  m+n p+1!=0 \[And] m-n+1!=0 \[And] m+1!=0, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]x^m (a+b x^n)^p \[DifferentialD]x  \[LongRightArrow]  ((x^(m-n+1) (a+b x^n)^(p+1))/(b (m+n p+1)))-(a (m-n+1))/(b (m+n p+1)) \[Integral]x^(m-n) (a+b x^n)^p \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[x_^m_.*(a_+b_.*x_^n_.)^p_,x_Symbol] :=
  x^(m-n+1)*(a+b*x^n)^(p+1)/(b*(m+n*p+1)) -
  Dist[a*(m-n+1)/(b*(m+n*p+1)),Int[x^(m-n)*(a+b*x^n)^p,x]] /;
FreeQ[{a,b,m,n,p},x] && NonzeroQ[m+n*p+1] && NonzeroQ[m-n+1] && NonzeroQ[m+1] &&
Not[IntegersQ[m,n,p]] && 
	(IntegersQ[m,n] && (0<n<=m || m<=n<0) && (Not[RationalQ[p]] || -1<p<0) || 
 	IntegerQ[(m+1)/n] && 0<(m+1)/n && Not[FractionQ[n]] || 
     Not[RationalQ[m]] && RationalQ[m-n] || 
     RationalQ[n] && MatchQ[m,u_+q_ /; RationalQ[q] && (0<n<=q || n<0 && q<0)] || 
     MatchQ[m,u_+q_.*n /; RationalQ[q] && q>=1])


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Reference: G&R 2.110.6, CRC 88c*)


(* ::Subsubsection:: *)
(*Rule: If  m+1!=0 \[And] m+n (p+1)+1!=0, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]x^m (a+b x^n)^p \[DifferentialD]x  \[LongRightArrow]  ((x^(m+1) (a+b x^n)^(p+1))/(a (m+1)))-(b (m+n (p+1)+1))/(a (m+1)) \[Integral]x^(m+n) (a+b x^n)^p \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[x_^m_.*(a_+b_.*x_^n_.)^p_,x_Symbol] :=
  x^(m+1)*(a+b*x^n)^(p+1)/(a*(m+1)) -
  Dist[b*(m+n*(p+1)+1)/(a*(m+1)),Int[x^(m+n)*(a+b*x^n)^p,x]] /;
FreeQ[{a,b,m,n,p},x] && NonzeroQ[m+1] && NonzeroQ[m+n*(p+1)+1] && Not[IntegersQ[m,n,p]] && 
	(IntegersQ[m,n] && (n>0 && m<-1 || 0<-n<=m+1) ||
     Not[RationalQ[m]] && RationalQ[m+n] ||
     RationalQ[n] && MatchQ[m,u_+q_ /; RationalQ[q] && (n>0 && q<0 || 0<-n<=q)] || 
     MatchQ[m,u_+q_*n /; RationalQ[q] && q<0])


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Derivation: Integration by substitution*)


(* ::Subsubsection:: *)
(*Note: Transforms p into an integer.*)


(* ::Subsubsection:: *)
(*Rule: If  -1<p<0 \[And] p+(m+1)/n\[Element]\[DoubleStruckCapitalZ] \[And] gcd[m+1,n]=1, let q=Denominator[p], then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]x^m (a+b x^n)^p \[DifferentialD]x  \[LongRightArrow]  ((q a^(p+(m+1)/n))/n) Subst[\[Integral]x^((q (m+1))/n-1)/(1-b x^q)^(p+(m+1)/n+1) \[DifferentialD]x,x,x^(n/q)/(a+b x^n)^(1/q)]*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[x_^m_.*(a_+b_.*x_^n_)^p_,x_Symbol] :=
  Module[{q=Denominator[p]},
  q*a^(p+(m+1)/n)/n*
	Subst[Int[x^(q*(m+1)/n-1)/(1-b*x^q)^(p+(m+1)/n+1),x],x,x^(n/q)/(a+b*x^n)^(1/q)]] /;
FreeQ[{a,b},x] && RationalQ[{m,n,p}] && -1<p<0 && IntegerQ[p+(m+1)/n] && GCD[m+1,n]==1


(* ::PageBreak:: *)
(**)


(* ::Title::Bold::Closed:: *)
(*\[Integral](x^m (a+b x^n))^p \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Rule: If  m p-n+1=0 \[And] p+1!=0, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral](x^m (a+b x^n))^p \[DifferentialD]x  \[LongRightArrow]  ((x^m (a+b x^n))^(p+1)/(b n (p+1) x^(m (p+1))))*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[(x_^m_.*(a_+b_.*x_^n_.))^p_,x_Symbol] :=
  (x^m*(a+b*x^n))^(p+1)/(b*n*(p+1)*x^(m*(p+1))) /;
FreeQ[{a,b,m,n,p},x] && ZeroQ[m*p-n+1] && NonzeroQ[p+1]


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Rule: If  m p+n (p+1)+1=0 \[And] p+1!=0, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral](x^m (a+b x^n))^p \[DifferentialD]x  \[LongRightArrow]  -((x^m (a+b x^n))^(p+1)/(a n (p+1) x^(m-1)))*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[(x_^m_.*(a_+b_.*x_^n_.))^p_.,x_Symbol] :=
  -(x^m*(a+b*x^n))^(p+1)/(a*n*(p+1)*x^(m-1)) /;
FreeQ[{a,b,m,n,p},x] && ZeroQ[m*p+n*(p+1)+1] && NonzeroQ[p+1]


(* ::PageBreak:: *)
(**)


(* ::Title::Bold::Closed:: *)
(*\[Integral]x^q (x^m (a+b x^n))^p \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Rule: If  q+m p-n+1=0 \[And] p+1!=0, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]x^q (x^m (a+b x^n))^p \[DifferentialD]x  \[LongRightArrow]  ((x^m (a+b x^n))^(p+1)/(b n (p+1) x^(m (p+1))))*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[x_^q_.*(x_^m_.*(a_+b_.*x_^n_.))^p_,x_Symbol] :=
  (x^m*(a+b*x^n))^(p+1)/(b*n*(p+1)*x^(m*(p+1))) /;
FreeQ[{a,b,m,n,p},x] && ZeroQ[q+m*p-n+1] && NonzeroQ[p+1]


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Rule: If  q+m p+n (p+1)+1=0 \[And] p+1!=0, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]x^q (x^m (a+b x^n))^p \[DifferentialD]x  \[LongRightArrow]  -((x^m (a+b x^n))^(p+1)/(a n (p+1) x^(m-1-q)))*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[x_^q_.*(x_^m_.*(a_+b_.*x_^n_.))^p_.,x_Symbol] :=
  -(x^m*(a+b*x^n))^(p+1)/(a*n*(p+1)*x^(m-1-q)) /;
FreeQ[{a,b,m,n,p,q},x] && ZeroQ[q+m*p+n*(p+1)+1] && NonzeroQ[p+1]


(* ::PageBreak:: *)
(**)


(* ::Title::Bold::Closed:: *)
(*\[Integral](a+b x^2)^m (c+d x^2)^n \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Derivation: Algebraic simplification*)


(* ::Subsubsection:: *)
(*Basis: If  b c-a d=0 and  m\[Element]\[DoubleStruckCapitalZ], then (a+b x^2)^m=(b/d)^m (c+d x^2)^m*)


(* ::Subsubsection:: *)
(*Rule: If  b c-a d=0 \[And] m\[Element]\[DoubleStruckCapitalZ], then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral](a+b x^2)^m (c+d x^2)^n \[DifferentialD]x  \[LongRightArrow] (b/d)^m \[Integral](c+d x^2)^(n+m) \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[(a_+b_.*x_^2)^m_.*(c_+d_.*x_^2)^n_,x_Symbol] :=
  Dist[(b/d)^m,Int[(c+d*x^2)^(n+m),x]] /;
FreeQ[{a,b,c,d,n},x] && ZeroQ[b*c-a*d] && IntegerQ[m]


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Reference: CRC 232, A&S 3.3.50'*)


(* ::Subsubsection:: *)
(*Rule: If  (a d-b c)/a>0, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]1/((a+b x^2) Sqrt[c+d x^2]) \[DifferentialD]x  \[LongRightArrow]  (1/(a Sqrt[(a d-b c)/a]))ArcTanh[(x Sqrt[(a d-b c)/a])/Sqrt[c+d x^2]]*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[1/((a_+b_.*x_^2)*Sqrt[c_+d_.*x_^2]),x_Symbol] :=
  ArcTanh[x*Rt[(a*d-b*c)/a,2]/Sqrt[c+d*x^2]]/(a*Rt[(a*d-b*c)/a,2]) /;
FreeQ[{a,b,c,d},x] && PosQ[(a*d-b*c)/a]


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Reference: CRC 233, A&S 3.3.49*)


(* ::Subsubsection:: *)
(*Rule: If  \[Not]((a d-b c)/a>0), then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]1/((a+b x^2) Sqrt[c+d x^2]) \[DifferentialD]x  \[LongRightArrow]  (1/(a Sqrt[(b c-a d)/a]))ArcTan[(x Sqrt[(b c-a d)/a])/Sqrt[c+d x^2]]*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[1/((a_+b_.*x_^2)*Sqrt[c_+d_.*x_^2]),x_Symbol] :=
  ArcTan[x*Rt[(b*c-a*d)/a,2]/Sqrt[c+d*x^2]]/(a*Rt[(b*c-a*d)/a,2]) /;
FreeQ[{a,b,c,d},x] && NegQ[(a*d-b*c)/a]


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Rule: If  a>0 \[And] c>0, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]1/(Sqrt[a+b x^2] Sqrt[c+d x^2]) \[DifferentialD]x  \[LongRightArrow]  (1/(Sqrt[a] Sqrt[c] Sqrt[-(d/c)]))  EllipticF[ArcSin[Sqrt[-(d/c)] x],(b c)/(a d)]*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[1/(Sqrt[a_+b_.*x_^2]*Sqrt[c_+d_.*x_^2]),x_Symbol] :=
  1/(Sqrt[a]*Sqrt[c]*Rt[-d/c,2])*EllipticF[ArcSin[Rt[-d/c,2]*x], b*c/(a*d)] /;
FreeQ[{a,b,c,d},x] && PositiveQ[a] && PositiveQ[c] &&
(PosQ[-c*d] && (NegQ[-a*b] || Not[RationalQ[Rt[-a*b,2]]]) || NegQ[-c*d] && NegQ[-a*b] &&
Not[RationalQ[Rt[a*b,2]]])


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Derivation: Piecewise constant extraction*)


(* ::Subsubsection:: *)
(*Basis: \!\( *)
(*\*SubscriptBox[\(\[PartialD]\), \(x\)]*)
(*\*FractionBox[*)
(*SqrtBox[*)
(*FractionBox[\(a + b\ *)
(*\*SuperscriptBox[\(x\), \(2\)]\), \(a\)]], *)
(*SqrtBox[\(a + b\ *)
(*\*SuperscriptBox[\(x\), \(2\)]\)]]\)=0*)


(* ::Subsubsection:: *)
(*Rule: If  \[Not](a>0 \[And] c>0), then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]1/(Sqrt[a+b x^2] Sqrt[c+d x^2]) \[DifferentialD]x  \[LongRightArrow]  ((Sqrt[(a+b x^2)/a] Sqrt[(c+d x^2)/c])/(Sqrt[a+b x^2] Sqrt[c+d x^2]))\[Integral]1/(Sqrt[1+b/a x^2] Sqrt[1+d/c x^2]) \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[1/(Sqrt[a_+b_.*x_^2]*Sqrt[c_+d_.*x_^2]),x_Symbol] :=
  Sqrt[(a+b*x^2)/a]*Sqrt[(c+d*x^2)/c]/(Sqrt[a+b*x^2]*Sqrt[c+d*x^2])*Int[1/(Sqrt[1+b/a*x^2]*Sqrt[1+d/c*x^2]),x] /;
FreeQ[{a,b,c,d},x] && Not[PositiveQ[a] && PositiveQ[c]] &&
(PosQ[-c*d] && (NegQ[-a*b] || Not[RationalQ[Rt[-a*b,2]]]) || NegQ[-c*d] && NegQ[-a*b] &&
Not[RationalQ[Rt[a*b,2]]])


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Rule: If  a>0 \[And] c>0, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]Sqrt[a+b x^2]/Sqrt[c+d x^2] \[DifferentialD]x  \[LongRightArrow]  (Sqrt[a]/(Sqrt[c] Sqrt[-(d/c)]))EllipticE[ArcSin[Sqrt[-(d/c)] x],(b c)/(a d)]*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[Sqrt[a_+b_.*x_^2]/Sqrt[c_+d_.*x_^2],x_Symbol] :=
  Sqrt[a]/(Sqrt[c]*Rt[-d/c,2])*EllipticE[ArcSin[Rt[-d/c,2]*x], b*c/(a*d)] /;
FreeQ[{a,b,c,d},x] && PositiveQ[a] && PositiveQ[c]


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Derivation: Piecewise constant extraction*)


(* ::Subsubsection:: *)
(*Basis: \!\( *)
(*\*SubscriptBox[\(\[PartialD]\), \(x\)]*)
(*\*FractionBox[*)
(*SqrtBox[\(a + b\ *)
(*\*SuperscriptBox[\(x\), \(2\)]\)], *)
(*SqrtBox[*)
(*FractionBox[\(a + b\ *)
(*\*SuperscriptBox[\(x\), \(2\)]\), \(a\)]]]\)=0*)


(* ::Subsubsection:: *)
(*Rule: If  \[Not](a>0 \[And] c>0), then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]Sqrt[a+b x^2]/Sqrt[c+d x^2] \[DifferentialD]x  \[LongRightArrow]  ((Sqrt[a+b x^2] Sqrt[((c+d x^2)/c)] )/(Sqrt[c+d x^2] Sqrt[(a+b x^2)/a]))\[Integral]Sqrt[1+b/a x^2]/Sqrt[1+d/c x^2] \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[Sqrt[a_+b_.*x_^2]/Sqrt[c_+d_.*x_^2],x_Symbol] :=
  Sqrt[a+b*x^2]*Sqrt[(c+d*x^2)/c]/(Sqrt[c+d*x^2]*Sqrt[(a+b*x^2)/a])*Int[Sqrt[1+b/a*x^2]/Sqrt[1+d/c*x^2],x] /;
FreeQ[{a,b,c,d},x] && Not[PositiveQ[a] && PositiveQ[c]]


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Rule:*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]Sqrt[a+b x^2] Sqrt[c+d x^2]\[DifferentialD]x  \[LongRightArrow]                                                                                                                                                  *)
(*          (x/3) Sqrt[a+b x^2] Sqrt[c+d x^2]+(c b+a d)/(3 d) \[Integral]Sqrt[c+d x^2]/Sqrt[a+b x^2] \[DifferentialD]x-(c(c b-a d))/(3d) \[Integral]1/(Sqrt[a+b x^2] Sqrt[c+d x^2]) \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[Sqrt[a_+b_.*x_^2]*Sqrt[c_+d_.*x_^2],x_Symbol] :=
  x/3*Sqrt[a+b*x^2]*Sqrt[c+d*x^2] + 
  Dist[(c*b+a*d)/(3*d),Int[Sqrt[c+d*x^2]/Sqrt[a+b*x^2],x]] - 
  Dist[c*(c*b-a*d)/(3*d),Int[1/(Sqrt[a+b*x^2]*Sqrt[c+d*x^2]),x]] /;
FreeQ[{a,b,c,d},x] && NonzeroQ[c*b+a*d] && NonzeroQ[c*b-a*d]


(* ::PageBreak:: *)
(**)


(* ::Title::Bold::Closed:: *)
(*\[Integral](a+b x^2)^m (c+d x^2)^n (e+f x^2)^p \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Derivation: Algebraic simplification*)


(* ::Subsubsection:: *)
(*Basis: If  b c-a d=0 and  m\[Element]\[DoubleStruckCapitalZ], then (a+b x^2)^m=(b/d)^m (c+d x^2)^m*)


(* ::Subsubsection:: *)
(*Rule: If  b c-a d=0 \[And] m\[Element]\[DoubleStruckCapitalZ], then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral](a+b x^2)^m (c+d x^2)^n (e+f x^2)^p \[DifferentialD]x  \[LongRightArrow] (b/d)^m \[Integral](c+d x^2)^(m+n) (e+f x^2)^p \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[(a_+b_.*x_^2)^m_.*(c_+d_.*x_^2)^n_*(e_+f_.*x_^2)^p_,x_Symbol] :=
  Dist[(b/d)^m,Int[(c+d*x^2)^(m+n)*(e+f*x^2)^p,x]] /;
FreeQ[{a,b,c,d,e,f,n,p},x] && ZeroQ[b*c-a*d] && IntegerQ[m]


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Rule: If  c>0 \[And] e>0, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]1/((a+b x^2)Sqrt[c+d x^2] Sqrt[e+f x^2]) \[DifferentialD]x  \[LongRightArrow]  (1/(a  Sqrt[c] Sqrt[e] Sqrt[-(d/c)]))EllipticPi[(b c)/(a d),ArcSin[Sqrt[-(d/c)] x],(c f)/(e d)]*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[1/((a_+b_.*x_^2)*Sqrt[c_+d_.*x_^2]*Sqrt[e_+f_.*x_^2]),x_Symbol] :=
  1/(a*Sqrt[c]*Sqrt[e]*Rt[-d/c,2])*EllipticPi[b*c/(a*d), ArcSin[Rt[-d/c,2]*x], c*f/(e*d)] /;
FreeQ[{a,b,c,d,e,f},x] && PositiveQ[c] && PositiveQ[e] &&
(PosQ[-e*f] && (NegQ[-c*d] || Not[RationalQ[Rt[-c*d,2]]]) || NegQ[-e*f] && NegQ[-c*d] &&
Not[RationalQ[Rt[c*d,2]]])


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Derivation: Piecewise constant extraction*)


(* ::Subsubsection:: *)
(*Basis: \!\( *)
(*\*SubscriptBox[\(\[PartialD]\), \(x\)]*)
(*\*FractionBox[*)
(*SqrtBox[*)
(*FractionBox[\(c + d\ *)
(*\*SuperscriptBox[\(x\), \(2\)]\), \(c\)]], *)
(*SqrtBox[\(c + d\ *)
(*\*SuperscriptBox[\(x\), \(2\)]\)]]\)=0*)


(* ::Subsubsection:: *)
(*Rule: If  \[Not](c>0 \[And] e>0), then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]1/((a+b x^2)Sqrt[c+d x^2] Sqrt[e+f x^2]) \[DifferentialD]x  \[LongRightArrow]  ((Sqrt[(c+d x^2)/c] Sqrt[(e+f x^2)/e])/(Sqrt[c+d x^2] Sqrt[e+f x^2]))\[Integral]1/((a+b x^2)Sqrt[1+d/c x^2] Sqrt[1+f/e x^2]) \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[1/((a_+b_.*x_^2)*Sqrt[c_+d_.*x_^2]*Sqrt[e_+f_.*x_^2]),x_Symbol] :=
  Sqrt[(c+d*x^2)/c]*Sqrt[(e+f*x^2)/e]/(Sqrt[c+d*x^2]*Sqrt[e+f*x^2])*
    Int[1/((a+b*x^2)*Sqrt[1+d/c*x^2]*Sqrt[1+f/e*x^2]),x] /;
FreeQ[{a,b,c,d,e,f},x] && Not[PositiveQ[c] && PositiveQ[e]] &&
(PosQ[-e*f] && (NegQ[-c*d] || Not[RationalQ[Rt[-c*d,2]]]) || NegQ[-e*f] && NegQ[-c*d] &&
Not[RationalQ[Rt[c*d,2]]])


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Derivation: Algebraic expansion*)


(* ::Subsubsection:: *)
(*Basis: Sqrt[e+f z]/(a+b z)=f/(b Sqrt[e+f z])+(b e-a f)/(b (a+b z) Sqrt[e+f z])*)


(* ::Subsubsection:: *)
(*Rule: If  b e-a f!=0, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]Sqrt[e+f x^2]/((a+b x^2)Sqrt[c+d x^2]) \[DifferentialD]x  \[LongRightArrow]  (f/b)\[Integral]1/(Sqrt[c+d x^2] Sqrt[e+f x^2]) \[DifferentialD]x+(b e-a f)/b \[Integral]1/((a+b x^2) Sqrt[c+d x^2] Sqrt[e+f x^2]) \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[Sqrt[e_+f_.*x_^2]/((a_+b_.*x_^2)*Sqrt[c_+d_.*x_^2]),x_Symbol] :=
  Dist[f/b,Int[1/(Sqrt[c+d*x^2]*Sqrt[e+f*x^2]),x]] + 
  Dist[(b*e-a*f)/b,Int[1/((a+b*x^2)*Sqrt[c+d*x^2]*Sqrt[e+f*x^2]),x]] /;
FreeQ[{a,b,c,d,e,f},x] && NonzeroQ[b*e-a*f]


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Derivation: Algebraic expansion*)


(* ::Subsubsection:: *)
(*Basis: (Sqrt[c+d x^2] Sqrt[e+f x^2])/(a+b x^2)=(d Sqrt[e+f x^2])/(b Sqrt[c+d x^2])+((b c-a d) Sqrt[e+f x^2])/(b (a+b x^2) Sqrt[c+d x^2])*)


(* ::Subsubsection:: *)
(*Rule: If  b c-a d!=0, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral](Sqrt[c+d x^2] Sqrt[e+f x^2])/(a+b x^2) \[DifferentialD]x  \[LongRightArrow]  (d/b)\[Integral]Sqrt[e+f x^2]/Sqrt[c+d x^2] \[DifferentialD]x+(b c-a d)/b \[Integral]Sqrt[e+f x^2]/((a+b x^2) Sqrt[c+d x^2] ) \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[Sqrt[c_+d_.*x_^2]*Sqrt[e_+f_.*x_^2]/(a_+b_.*x_^2),x_Symbol] :=
  Dist[d/b,Int[Sqrt[e+f*x^2]/Sqrt[c+d*x^2],x]] + 
  Dist[(b*c-a*d)/b,Int[Sqrt[e+f*x^2]/((a+b*x^2)*Sqrt[c+d*x^2]),x]] /;
FreeQ[{a,b,c,d,e,f},x] && NonzeroQ[b*c-a*d]


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Derivation: Algebraic expansion*)


(* ::Subsubsection:: *)
(*Basis: (e+f z)/Sqrt[a+b z]=(f Sqrt[a+b z])/b+(b e-a f)/(b Sqrt[a+b z])*)


(* ::Subsubsection:: *)
(*Rule: If  b e-a f!=0, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral](e+f x^2)/(Sqrt[a+b x^2] Sqrt[c+d x^2]) \[DifferentialD]x  \[LongRightArrow]  (f/b)\[Integral]Sqrt[a+b x^2]/Sqrt[c+d x^2] \[DifferentialD]x+(b e-a f)/b \[Integral]1/(Sqrt[a+b x^2] Sqrt[c+d x^2]) \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[(e_.+f_.*x_^2)/(Sqrt[a_+b_.*x_^2]*Sqrt[c_+d_.*x_^2]),x_Symbol] :=
  Dist[f/b,Int[Sqrt[a+b*x^2]/Sqrt[c+d*x^2],x]] +
  Dist[(b*e-a*f)/b,Int[1/(Sqrt[a+b*x^2]*Sqrt[c+d*x^2]),x]] /;
FreeQ[{a,b,c,d,e,f},x] && NonzeroQ[b*e-a*f] &&
(PosQ[-c*d] && (NegQ[-a*b] || Not[RationalQ[Rt[-a*b,2]]]) || NegQ[-c*d] && NegQ[-a*b] &&
Not[RationalQ[Rt[a*b,2]]])


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Rule:*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral](x^2 Sqrt[a+b x^2])/Sqrt[c+d x^2] \[DifferentialD]x  \[LongRightArrow]  ((x Sqrt[a+b x^2] Sqrt[c+d x^2])/(3 d))-1/(3 d) \[Integral](a c+(2 b c-a d) x^2)/(Sqrt[a+b x^2] Sqrt[c+d x^2]) \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[x_^2*Sqrt[a_+b_.*x_^2]/Sqrt[c_+d_.*x_^2],x_Symbol] :=
  x*Sqrt[a+b*x^2]*Sqrt[c+d*x^2]/(3*d) -
  Dist[1/(3*d),Int[(a*c+(2*b*c-a*d)*x^2)/(Sqrt[a+b*x^2]*Sqrt[c+d*x^2]),x]] /;
FreeQ[{a,b,c,d},x]


(* ::PageBreak:: *)
(**)


(* ::Title::Bold::Closed:: *)
(*\[Integral](a+b x^n)^p (c+d x^n)^q \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Derivation: Algebraic simplification*)


(* ::Subsubsection:: *)
(*Basis: If a d-b c =0, then (a+b z)/(c+d z)=b/d*)


(* ::Subsubsection:: *)
(*Rule: If  a d-b c =0 \[And] p>0 \[And] q<-1, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral](a+b x^n)^p (c+d x^n)^q \[DifferentialD]x  \[LongRightArrow]  (b/d)\[Integral](a+b x^n)^(p-1) (c+d x^n)^(q+1) \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[(a_.+b_.*x_^n_)^p_*(c_.+d_.*x_^n_)^q_.,x_Symbol] :=
  Dist[b/d,Int[(a+b*x^n)^(p-1)*(c+d*x^n)^(q+1),x]] /;
FreeQ[{a,b,c,d,n},x] && ZeroQ[a*d-b*c] && RationalQ[{p,q}] && p>0 && q<=-1


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Derivation: Algebraic expansion*)


(* ::Subsubsection:: *)
(*Basis: (a+b z)/(c+d z)=b/d+(a d-b c)/(d (c+d z))*)


(* ::Subsubsection:: *)
(*Rule: If  a d-b c !=0 \[And] p>0 \[And] q<-1 \[And] n\[Element]\[DoubleStruckCapitalZ] \[And] n>0, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral](a+b x^n)^p (c+d x^n)^q \[DifferentialD]x  \[LongRightArrow]  ((a d-b c)/d)\[Integral](a+b x^n)^(p-1) (c+d x^n)^q \[DifferentialD]x+b/d \[Integral](a+b x^n)^(p-1) (c+d x^n)^(q+1) \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[(a_.+b_.*x_^n_)^p_*(c_.+d_.*x_^n_)^q_.,x_Symbol] :=
  Dist[(a*d-b*c)/d,Int[(a+b*x^n)^(p-1)*(c+d*x^n)^q,x]] +
  Dist[b/d,Int[(a+b*x^n)^(p-1)*(c+d*x^n)^(q+1),x]] /;
FreeQ[{a,b,c,d,n},x] && NonzeroQ[a*d-b*c] && RationalQ[{p,q}] && p>0 && q<=-1 && 
IntegerQ[n] && n>0


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Derivation: Algebraic expansion*)


(* ::Subsubsection:: *)
(*Basis: 1/((a+b z) (c+d z))=b/((b c-a d) (a+b z))-d/((b c-a d) (c+d z))*)


(* ::Subsubsection:: *)
(*Rule: If  a d-b c !=0 \[And] p<-1 \[And] q<-1 \[And] n\[Element]\[DoubleStruckCapitalZ] \[And] n>0, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral](a+b x^n)^p (c+d x^n)^q \[DifferentialD]x  \[LongRightArrow]                                                                                                                                     *)
(*                            (b/(b c-a d))\[Integral](a+b x^n)^p (c+d x^n)^(q+1) \[DifferentialD]x-d/(b c-a d) \[Integral](a+b x^n)^(p+1) (c+d x^n)^q \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[(a_.+b_.*x_^n_)^p_.*(c_.+d_.*x_^n_)^q_.,x_Symbol] :=
  Dist[b/(b*c-a*d),Int[(a+b*x^n)^p*(c+d*x^n)^(q+1),x]] -
  Dist[d/(b*c-a*d),Int[(a+b*x^n)^(p+1)*(c+d*x^n)^q,x]] /;
FreeQ[{a,b,c,d,n},x] && NonzeroQ[b*c-a*d] && RationalQ[{p,q}] && p<-1 && q<=-1 && 
IntegerQ[n] && n>0


(* ::PageBreak:: *)
(**)


(* ::Title::Bold::Closed:: *)
(*\[Integral](x^m (a+b x^n))/(c+d x^p) \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Derivation: Algebraic expansion*)


(* ::Subsubsection:: *)
(*Basis: (a+b x^n)/(x(c+d x^p))=a/(c x)+(x^(n-1) (b c-a d x^(p-n)))/(c(c+d x^p))*)


(* ::Subsubsection:: *)
(*Rule: If  n,p\[Element]\[DoubleStruckCapitalF] \[And] 0<n<=p, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral](a+b x^n)/(x(c+d x^p)) \[DifferentialD]x  \[LongRightArrow]  ((a Log[x])/c)+1/c \[Integral](x^(n-1) (b c-a d x^(p-n)))/(c+d x^p) \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[(a_.+b_.*x_^n_.)/(x_*(c_+d_.*x_^p_.)),x_Symbol] :=
  a*Log[x]/c +
  Dist[1/c,Int[x^(n-1)*(b*c-a*d*x^(p-n))/(c+d*x^p),x]] /;
FreeQ[{a,b,c,d},x] && FractionQ[{n,p}] && 0<n<=p


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Derivation: Algebraic expansion*)


(* ::Subsubsection:: *)
(*Basis: (a+b x^n)/(x(c+d x^p))=a/(c x)+(x^(p-1) (-a d+b c x^(n-p)))/(c(c+d x^p))*)


(* ::Subsubsection:: *)
(*Rule: If  n,p\[Element]\[DoubleStruckCapitalF] \[And] 0<p<n, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral](a+b x^n)/(x(c+d x^p)) \[DifferentialD]x  \[LongRightArrow]  ((a Log[x])/c)+1/c \[Integral](x^(p-1) (-a d+b c x^(n-p)))/(c+d x^p) \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[(a_.+b_.*x_^n_.)/(x_*(c_+d_.*x_^p_.)),x_Symbol] :=
  a*Log[x]/c +
  Dist[1/c,Int[x^(p-1)*(-a*d+b*c*x^(n-p))/(c+d*x^p),x]] /;
FreeQ[{a,b,c,d},x] && FractionQ[{n,p}] && 0<p<n


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Derivation: Algebraic expansion*)


(* ::Subsubsection:: *)
(*Basis: (x^m (a+b x^n))/(c+d x^p)=(a x^m)/c+(x^(m+n) (b c-a d x^(p-n)))/(c (c+d x^p))*)


(* ::Subsubsection:: *)
(*Rule: If  m,n,p\[Element]\[DoubleStruckCapitalF] \[And] m<-1 \[And] 0<n<=p, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral](x^m (a+b x^n))/(c+d x^p) \[DifferentialD]x  \[LongRightArrow]  ((a x^(m+1))/(c (m+1)))+1/c \[Integral](x^(m+n) (b c-a d x^(p-n)))/(c+d x^p) \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[x_^m_*(a_.+b_.*x_^n_.)/(c_+d_.*x_^p_.),x_Symbol] :=
  a*x^(m+1)/(c*(m+1)) +
  Dist[1/c,Int[x^(m+n)*(b*c-a*d*x^(p-n))/(c+d*x^p),x]] /;
FreeQ[{a,b,c,d},x] && FractionQ[{m,n,p}] && m<-1 && 0<n<=p


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Derivation: Algebraic expansion*)


(* ::Subsubsection:: *)
(*Basis: (x^m (a+b x^n))/(c+d x^p)=(a x^m)/c+(x^(m+p) (-a d+b c x^(n-p)))/(c (c+d x^p))*)


(* ::Subsubsection:: *)
(*Rule: If  m,n,p\[Element]\[DoubleStruckCapitalF] \[And] m<-1 \[And] 0<p<n, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral](x^m (a+b x^n))/(c+d x^p) \[DifferentialD]x  \[LongRightArrow]  ((a x^(m+1))/(c (m+1)))+1/c \[Integral](x^(m+p) (-a d+b c x^(n-p)))/(c+d x^p) \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[x_^m_*(a_.+b_.*x_^n_.)/(c_+d_.*x_^p_.),x_Symbol] :=
  a*x^(m+1)/(c*(m+1)) +
  Dist[1/c,Int[x^(m+p)*(-a*d+b*c*x^(n-p))/(c+d*x^p),x]] /;
FreeQ[{a,b,c,d},x] && FractionQ[{m,n,p}] && m<-1 && 0<p<n


(* ::PageBreak:: *)
(**)


(* ::Title::Bold::Closed:: *)
(*\[Integral]1/Sqrt[c x^2 (a+b x^n)] \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Derivation: Algebraic simplification*)


(* ::Subsubsection:: *)
(*Note: If (b^2 c)/a<0, antiderivative can be expressed more simply as the arcsine or hyperbolic arcsine of a linear term*)


(* ::Subsubsection:: *)
(*Rule: If (b^2 c)/a<0, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]1/Sqrt[c x^2 (a+b/x)] \[DifferentialD]x  \[LongRightArrow]  \[Integral]1/Sqrt[b c x+a c x^2] \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[1/Sqrt[c_.*x_^2*(a_.+b_./x_)],x_Symbol] :=
  Int[1/Sqrt[b*c*x+a*c*x^2],x] /;
FreeQ[{a,b,c},x] && NegativeQ[b^2*c/a]


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Rule: If  a c>0, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]1/Sqrt[c x^2 (a+b x^n)] \[DifferentialD]x  \[LongRightArrow]  -(2/(n Sqrt[a c]))  ArcTanh[(Sqrt[a c] x)/Sqrt[c x^2 (a+b x^n)]]*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[1/Sqrt[c_.*x_^2*(a_.+b_.*x_^n_.)],x_Symbol] :=
  -2/(n*Rt[a*c,2])*ArcTanh[Rt[a*c,2]*x/Sqrt[c*x^2*(a+b*x^n)]] /;
FreeQ[{a,b,c,n},x] && PosQ[a*c]


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Rule: If  \[Not](a c>0), then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]1/Sqrt[c x^2 (a+b x^n)] \[DifferentialD]x  \[LongRightArrow]  -(2/(n Sqrt[-a c])) ArcTan[(Sqrt[-a c] x)/Sqrt[c x^2 (a+b x^n)]]*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[1/Sqrt[c_.*x_^2*(a_.+b_.*x_^n_.)],x_Symbol] :=
  -2/(n*Rt[-a*c,2])*ArcTan[Rt[-a*c,2]*x/Sqrt[c*x^2*(a+b*x^n)]] /;
FreeQ[{a,b,c,n},x] && NegQ[a*c]


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Derivation: Algebraic simplification*)


(* ::Subsubsection:: *)
(*Rule: If  m+n=2, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]1/Sqrt[c x^m (a+b x^n)] \[DifferentialD]x  \[LongRightArrow]  \[Integral]1/Sqrt[c x^2 (b+a x^(m-2))] \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[1/Sqrt[c_.*x_^m_.*(a_.+b_.*x_^n_.)],x_Symbol] :=
  Int[1/Sqrt[c*x^2*(b+a*x^(m-2))],x] /;
FreeQ[{a,b,c,m,n},x] && ZeroQ[m+n-2]


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Derivation: Algebraic simplification*)


(* ::Subsubsection:: *)
(*Rule:*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]1/Sqrt[c(a x^p+b x^2)] \[DifferentialD]x  \[LongRightArrow]  \[Integral]1/Sqrt[c x^2 (b+a x^(p-2))] \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[1/Sqrt[c_.*(a_.*x_^p_+b_.*x_^2)],x_Symbol] :=
  Int[1/Sqrt[c*x^2*(b+a*x^(p-2))],x] /;
FreeQ[{a,b,c,p},x]


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Derivation: Algebraic simplification*)


(* ::Subsubsection:: *)
(*Basis: x^m (a x^p+b x^(2-m))=x^2 (b+a x^(m+p-2))*)


(* ::Subsubsection:: *)
(*Rule: If  m+n=2, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]1/Sqrt[c x^m (a x^p+b x^n)] \[DifferentialD]x  \[LongRightArrow]  \[Integral]1/Sqrt[c x^2 (b+a x^(m+p-2))] \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[1/Sqrt[c_.*x_^m_.*(a_.*x_^p_.+b_.*x_^n_.)],x_Symbol] :=
  Int[1/Sqrt[c*x^2*(b+a*x^(m+p-2))],x] /;
FreeQ[{a,b,c,m,n,p},x] && ZeroQ[m+n-2]


(* ::PageBreak:: *)
(**)


(* ::Title::Bold::Closed:: *)
(*\[Integral]x^m ((a+b x)/(c+d x))^n \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
(* Int[(e_.*(a_.+b_.*x_)/(c_.+d_.*x_))^n_,x_Symbol] :=
  Dist[e*(b*c-a*d),Subst[Int[x^n/(b*e-d*x)^2,x],x,e*(a+b*x)/(c+d*x)]] /;
FreeQ[{a,b,c,d,e},x] && FractionQ[n] && NonzeroQ[b*c-a*d] *)


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
(* Int[x_^m_.*(e_.*(a_.+b_.*x_)/(c_.+d_.*x_))^n_,x_Symbol] :=
  Dist[e*(b*c-a*d),Subst[Int[x^n*(-a*e+c*x)^m/(b*e-d*x)^(m+2),x],x,e*(a+b*x)/(c+d*x)]] /;
FreeQ[{a,b,c,d,e},x] && IntegerQ[m] && FractionQ[n] && NonzeroQ[b*c-a*d] *)


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
(* Int[(f_+g_.*x_)^m_*(e_.*(a_.+b_.*x_)/(c_.+d_.*x_))^n_,x_Symbol] :=
  Dist[1/g,Subst[Int[x^m*(e*(a-b*f/g+b/g*x)/(c-d*f/g+d/g*x))^n,x],x,f+g*x]] /;
FreeQ[{a,b,c,d,e,f,g},x] && IntegerQ[m] && m<0 && FractionQ[n] && NonzeroQ[b*c-a*d] *)


(* ::PageBreak:: *)
(**)


(* ::Title::Bold::Closed:: *)
(*\[Integral]Sqrt[a x+Sqrt[b+a^2 x^2]]\[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Rule:*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]Sqrt[a x+Sqrt[b+a^2 x^2]]\[DifferentialD]x  \[LongRightArrow]  (2/(3 a))(2 a x-Sqrt[b+c x^2]) Sqrt[a x+Sqrt[b+c x^2]]*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[Sqrt[a_.*x_+Sqrt[b_+c_.*x_^2]], x_Symbol] :=
  2*(2*a*x-Sqrt[b+c*x^2])*Sqrt[a*x+Sqrt[b+c*x^2]]/(3*a) /;
FreeQ[{a,b,c},x] && ZeroQ[c-a^2]


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Rule:*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]Sqrt[a x-Sqrt[b+a^2 x^2]]\[DifferentialD]x  \[LongRightArrow]  (2/(3 a))(2 a x+Sqrt[b+c x^2]) Sqrt[a x-Sqrt[b+c x^2]]*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[Sqrt[a_.*x_-Sqrt[b_+c_.*x_^2]], x_Symbol] :=
  2*(2*a*x+Sqrt[b+c*x^2])*Sqrt[a*x-Sqrt[b+c*x^2]]/(3*a) /;
FreeQ[{a,b,c},x] && ZeroQ[c-a^2]


(* ::PageBreak:: *)
(**)


(* ::Title::Bold::Closed:: *)
(*\[Integral]Sqrt[a+Sqrt[a^2+b x^2]]\[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Rule:*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]Sqrt[a+Sqrt[a^2+b x^2]]\[DifferentialD]x  \[LongRightArrow]  (2/(3 b x))(-a^2+b x^2+a Sqrt[a^2+b x^2])Sqrt[a+Sqrt[a^2+b x^2]]*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[Sqrt[a_+Sqrt[c_+b_.*x_^2]], x_Symbol] :=
  2*(-a^2+b*x^2+a*Sqrt[a^2+b*x^2])*Sqrt[a+Sqrt[a^2+b*x^2]]/(3*b*x) /;
FreeQ[{a,b,c},x] && ZeroQ[c-a^2]


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Rule:*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]Sqrt[a-Sqrt[a^2+b x^2]]\[DifferentialD]x  \[LongRightArrow]  (2/(3 b x))(-a^2+b x^2-a Sqrt[a^2+b x^2]) Sqrt[a-Sqrt[a^2+b x^2]]*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[Sqrt[a_-Sqrt[c_+b_.*x_^2]], x_Symbol] :=
  2*(-a^2+b*x^2-a*Sqrt[a^2+b*x^2])*Sqrt[a-Sqrt[a^2+b*x^2]]/(3*b*x) /;
FreeQ[{a,b,c},x] && ZeroQ[c-a^2]


(* ::PageBreak:: *)
(**)


(* ::Title::Bold::Closed:: *)
(*\[Integral]u/(v+Sqrt[w]) \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Derivation: Algebraic simplification*)


(* ::Subsubsection:: *)
(*Basis: 1/(z+w)=(z-w)/(z^2-w^2)*)


(* ::Subsubsection:: *)
(*Rule:*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]u/(a x^m+b Sqrt[c x^n]) \[DifferentialD]x  \[LongRightArrow]  \[Integral](u (a x^m-b Sqrt[c x^n]))/(a^2 x^(2 m)-b^2 c x^n) \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[u_./(a_.*x_^m_.+b_.*Sqrt[c_.*x_^n_]),x_Symbol] :=
  Int[u*(a*x^m-b*Sqrt[c*x^n])/(a^2*x^(2*m)-b^2*c*x^n),x] /;
FreeQ[{a,b,c,m,n},x]


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Derivation: Algebraic simplification*)


(* ::Subsubsection:: *)
(*Basis: If  b e^2=d f^2, then 1/(e Sqrt[a+b z]+f Sqrt[c+d z])=(e Sqrt[a+b z]-f Sqrt[c+d z])/(a e^2-c f^2)*)


(* ::Subsubsection:: *)
(*Rule: If  m\[Element]\[DoubleStruckCapitalZ] \[And] m<0 \[And] b e^2=d f^2, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]u (e Sqrt[a+b x^n]+f Sqrt[c+d x^n])^m \[DifferentialD]x  \[LongRightArrow]  (a e^2-c f^2)^m\[Integral]u/(e Sqrt[a+b x^n]-f Sqrt[c+d x^n])^m \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[u_.*(e_.*Sqrt[a_.+b_.*x_^n_.]+f_.*Sqrt[c_.+d_.*x_^n_.])^m_,x_Symbol] :=
  Dist[(a*e^2-c*f^2)^m,Int[u*(e*Sqrt[a+b*x^n]-f*Sqrt[c+d*x^n])^(-m),x]] /;
FreeQ[{a,b,c,d,e,f,n},x] && IntegerQ[m] && m<0 && ZeroQ[b*e^2-d*f^2]


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Derivation: Algebraic simplification*)


(* ::Subsubsection:: *)
(*Basis: If  a e^2=c f^2, then 1/(e Sqrt[a+b z]+f Sqrt[c+d z])=(e Sqrt[a+b z]-f Sqrt[c+d z])/((b e^2-d f^2) z)*)


(* ::Subsubsection:: *)
(*Rule: If  m\[Element]\[DoubleStruckCapitalZ] \[And] m<0 \[And] a e^2=c f^2, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]u (e Sqrt[a+b x^n]+f Sqrt[c+d x^n])^m \[DifferentialD]x  \[LongRightArrow]  (b e^2-d f^2)^m\[Integral](u x^(m n))/(e Sqrt[a+b x^n]-f Sqrt[c+d x^n])^m \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[u_.*(e_.*Sqrt[a_.+b_.*x_^n_.]+f_.*Sqrt[c_.+d_.*x_^n_.])^m_,x_Symbol] :=
  Dist[(b*e^2-d*f^2)^m,Int[u*x^(m*n)*(e*Sqrt[a+b*x^n]-f*Sqrt[c+d*x^n])^(-m),x]] /;
FreeQ[{a,b,c,d,e,f,n},x] && IntegerQ[m] && m<0 && ZeroQ[a*e^2-c*f^2]


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Derivation: Algebraic simplification*)


(* ::Subsubsection:: *)
(*Basis: If  a^2=b^2 c, then 1/(a+b Sqrt[c+d z])=-(a/(b^2 d z))+Sqrt[c+d z]/(b d z)*)


(* ::Subsubsection:: *)
(*Rule: If  a^2=b^2 c, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]u/(a+b Sqrt[c+d x^n]) \[DifferentialD]x  \[LongRightArrow]  -(a/(b^2 d))\[Integral]u/x^n \[DifferentialD]x+1/(b d) \[Integral](u Sqrt[c+d x^n])/x^n \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[u_./(a_+b_.*Sqrt[c_+d_.*x_^n_]),x_Symbol] :=
  Dist[-a/(b^2*d),Int[u/x^n,x]] +
  Dist[1/(b*d),Int[u*Sqrt[c+d*x^n]/x^n,x]] /;
FreeQ[{a,b,c,d,n},x] && ZeroQ[a^2-b^2*c]


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Derivation: Algebraic simplification*)


(* ::Subsubsection:: *)
(*Basis: If  a^2=b^2 d, then 1/(a z+b Sqrt[c+d z^2])=(-a z+b Sqrt[c+d z^2])/(b^2 c)*)


(* ::Subsubsection:: *)
(*Rule: If  a^2=b^2 d, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]u/(a x^m+b Sqrt[c+d x^(2 m)]) \[DifferentialD]x  \[LongRightArrow]  -(a/(b^2 c))\[Integral]u x^m \[DifferentialD]x+1/(b c) \[Integral]u Sqrt[c+d x^(2 m)]\[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[u_./(a_.*x_^m_.+b_.*Sqrt[c_+d_.*x_^n_]),x_Symbol] :=
  Dist[-a/(b^2*c),Int[u*x^m,x]] +
  Dist[1/(b*c),Int[u*Sqrt[c+d*x^n],x]] /;
FreeQ[{a,b,c,d,m,n},x] && ZeroQ[n-2*m] && ZeroQ[a^2-b^2*d]


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Derivation: Algebraic simplification*)


(* ::Subsubsection:: *)
(*Basis: If  a^2=c^2 d \[And] b^2=c^2 e, then 1/(a+b z+c Sqrt[d+e z^2])=1/(2 a)+1/(2 b z)-(c Sqrt[d+e z^2])/(2 a b z)*)


(* ::Subsubsection:: *)
(*Rule: If  a^2=c^2 d \[And] b^2=c^2 e, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]u/(a+b x^m+c Sqrt[d+e x^(2 m)]) \[DifferentialD]x  \[LongRightArrow]  (1/(2 a))\[Integral]u \[DifferentialD]x+1/(2 b) \[Integral]u/x^m \[DifferentialD]x-c/(2 a b) \[Integral](u Sqrt[d+e x^(2m)])/x^m \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[u_./(a_+b_.*x_^m_.+c_.*Sqrt[d_+e_.*x_^n_]),x_Symbol] :=
  Dist[1/(2*a),Int[u,x]] +
  Dist[1/(2*b),Int[u/x^m,x]] -
  Dist[c/(2*a*b),Int[u*Sqrt[d+e*x^n]/x^m,x]] /;
FreeQ[{a,b,c,d,m,n},x] && ZeroQ[n-2*m] && ZeroQ[a^2-c^2*d] && ZeroQ[b^2-c^2*e]


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Derivation: Algebraic simplification*)


(* ::Subsubsection:: *)
(*Basis: If  a^2=c^2 d \[And] 2a b=c^2 e, then 1/(a+b z+c Sqrt[d+e z])=1/(b z)+a/(b^2 z^2)-(c Sqrt[d+e z])/(b^2 z^2)*)


(* ::Subsubsection:: *)
(*Rule: If  a^2=c^2 d \[And] 2a b=c^2 e, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]u/(a+b x^n+c Sqrt[d+e x^n]) \[DifferentialD]x  \[LongRightArrow]  (1/b)\[Integral]u/x^n \[DifferentialD]x+a/b^2 \[Integral]u/x^(2 n) \[DifferentialD]x-c/b^2 \[Integral](u Sqrt[d+e x^n])/x^(2 n) \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[u_./(a_+b_.*x_^n_.+c_.*Sqrt[d_+e_.*x_^n_.]),x_Symbol] :=
  Dist[1/b,Int[u/x^n,x]] +
  Dist[a/b^2,Int[u/x^(2*n),x]] -
  Dist[c/b^2,Int[u*Sqrt[d+e*x^n]/x^(2*n),x]] /;
FreeQ[{a,b,c,d,n},x] && ZeroQ[a^2-c^2*d] && ZeroQ[2*a*b-c^2*e]


(* ::Code:: *)
(* Int[u_./(e_.*Sqrt[a_.+b_.*x_]+f_.*Sqrt[c_.+d_.*x_]),x_Symbol] :=
  Int[u*(e*Sqrt[a+b*x]-f*Sqrt[c+d*x])/(a*e^2-c*f^2+(b*e^2-d*f^2)*x),x] /;
FreeQ[{a,b,c,d,e,f},x] *)


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Derivation: Algebraic simplification*)


(* ::Subsubsection:: *)
(*Basis: 1/(a x+b Sqrt[c+d x^2])=(a x)/(-b^2 c+(a^2-b^2 d) x^2)-(b Sqrt[c+d x^2])/(-b^2 c+(a^2-b^2 d) x^2)*)


(* ::Subsubsection:: *)
(*Rule:*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]u/(a x+b Sqrt[c+d x^2]) \[DifferentialD]x  \[LongRightArrow]  a\[Integral](x u)/(-b^2 c+(a^2-b^2 d) x^2) \[DifferentialD]x-b \[Integral](u Sqrt[c+d x^2])/(-b^2 c+(a^2-b^2 d) x^2) \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[u_./(a_.*x_+b_.*Sqrt[c_.+d_.*x_^2]),x_Symbol] :=
  Dist[a,Int[x*u/(-b^2*c+(a^2-b^2*d)*x^2),x]] -
  Dist[b,Int[u*Sqrt[c+d*x^2]/(-b^2*c+(a^2-b^2*d)*x^2),x]] /;
FreeQ[{a,b,c,d},x]


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Derivation: Algebraic simplification*)


(* ::Subsubsection:: *)
(*Basis: 1/(z+w)=(z-w)/(z^2-w^2)*)


(* ::Subsubsection:: *)
(*Rule:*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]u/(e Sqrt[(a+b x^n)^p]+f Sqrt[(a+b x^n)^q]) \[DifferentialD]x  \[LongRightArrow]  \[Integral](u (e Sqrt[(a+b x^n)^p]-f Sqrt[(a+b x^n)^q]))/(e^2 (a+b x^n)^p-f^2 (a+b x^n)^q) \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[u_./(e_.*Sqrt[(a_.+b_.*x_^n_.)^p_.]+f_.*Sqrt[(a_.+b_.*x_^n_.)^q_.]),x_Symbol] :=
  Int[u*(e*Sqrt[(a+b*x^n)^p]-f*Sqrt[(a+b*x^n)^q])/(e^2*(a+b*x^n)^p-f^2*(a+b*x^n)^q),x] /;
FreeQ[{a,b,e,f},x] && IntegersQ[n,p,q]


(* ::Code:: *)
(* Int[u_./(v_+a_.*Sqrt[w_]),x_Symbol] :=
  Int[u*v/(v^2-a^2*w),x] -
  Dist[a,Int[u*Sqrt[w]/(v^2-a^2*w),x]] /;
FreeQ[a,x] && PolynomialQ[v,x] *)


(* ::Code:: *)
(* Int[u_./(a_.*x_+b_.*Sqrt[c_+d_.*x_]),x_Symbol] :=
  Int[(a*x*u-b*u*Sqrt[c+d*x])/(-b^2*c-b^2*d*x+a^2*x^2),x] /;
FreeQ[{a,b,c,d},x] *)


(* ::PageBreak:: *)
(**)


(* ::Title::Bold::Closed:: *)
(*\[Integral](u Sqrt[a^2-b^2 x^2])/(a+b x) \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Derivation: Algebraic simplification*)


(* ::Subsubsection:: *)
(*Basis: Sqrt[z^2-w^2]/(z+w)=z/Sqrt[z^2-w^2]-w/Sqrt[z^2-w^2]*)


(* ::Subsubsection:: *)
(*Rule: If  m n+1=0, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral](u Sqrt[a^2-b^2 x^2])/(a+b x) \[DifferentialD]x  \[LongRightArrow]  a \[Integral]u/Sqrt[a^2-b^2 x^2] \[DifferentialD]x-b \[Integral](x u)/Sqrt[a^2-b^2 x^2] \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[u_.*Sqrt[c_+d_.*x_^2]/(a_+b_.*x_),x_Symbol] :=
  a*Int[u/Sqrt[c+d*x^2],x] -
  b*Int[x*u/Sqrt[c+d*x^2],x] /;
FreeQ[{a,b,c,d},x] && ZeroQ[c-a^2] && ZeroQ[d+b^2]


(* ::PageBreak:: *)
(**)


(* ::Title::Bold::Closed:: *)
(*\[Integral]Sqrt[b x^2+Sqrt[a+b^2 x^4]]/Sqrt[a+b^2 x^4] \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Rule: If  b>0, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]Sqrt[b x^2+Sqrt[a+b^2 x^4]]/Sqrt[a+b^2 x^4] \[DifferentialD]x  \[LongRightArrow]  (1/Sqrt[2 b])ArcTanh[(Sqrt[2 b] x)/Sqrt[b x^2+Sqrt[a+b^2 x^4]]]*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[Sqrt[b_.*x_^2+Sqrt[a_+c_.*x_^4]]/Sqrt[a_+c_.*x_^4],x_Symbol] :=
  ArcTanh[Rt[2*b,2]*x/Sqrt[b*x^2+Sqrt[a+c*x^4]]]/Rt[2*b,2] /;
FreeQ[{a,b,c},x] && ZeroQ[c-b^2] && PosQ[b]


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Rule: If  \[Not](b>0), then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]Sqrt[b x^2+Sqrt[a+b^2 x^4]]/Sqrt[a+b^2 x^4] \[DifferentialD]x  \[LongRightArrow]  (1/Sqrt[-2 b])ArcTan[(Sqrt[-2 b] x)/Sqrt[b x^2+Sqrt[a+b^2 x^4]]]*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[Sqrt[b_.*x_^2+Sqrt[a_+c_.*x_^4]]/Sqrt[a_+c_.*x_^4],x_Symbol] :=
  ArcTan[Rt[-2*b,2]*x/Sqrt[b*x^2+Sqrt[a+c*x^4]]]/Rt[-2*b,2] /;
FreeQ[{a,b,c},x] && ZeroQ[c-b^2] && NegQ[b]


(* ::PageBreak:: *)
(**)


(* ::Title::Bold::Closed:: *)
(*\[Integral](u Sqrt[v+Sqrt[a+v^2]])/Sqrt[a+v^2] \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Author: Martin*)


(* ::Subsubsection:: *)
(*Derivation: Algebraic expansion*)


(* ::Subsubsection:: *)
(*Basis: If  a>0, then Sqrt[a+z^2]=Sqrt[Sqrt[a]+I z] Sqrt[Sqrt[a]-I z]*)


(* ::Subsubsection:: *)
(*Basis: If  a>0, then Sqrt[z+Sqrt[a+z^2]]/Sqrt[a+z^2]=(1-I)/(2 Sqrt[Sqrt[a]-I z])+(1+I)/(2 Sqrt[Sqrt[a]+I z])*)


(* ::Subsubsection:: *)
(*Rule: If  a>0, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral](u Sqrt[v+Sqrt[a+v^2]])/Sqrt[a+v^2] \[DifferentialD]x  \[LongRightArrow]  ((1-I)/2)\[Integral]u/Sqrt[Sqrt[a]-I v] \[DifferentialD]x+(1+I)/2 \[Integral]u/Sqrt[Sqrt[a]+I v] \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[u_.*Sqrt[v_+Sqrt[a_+w_]]/Sqrt[a_+w_],x_Symbol] :=
  Dist[(1-I)/2, Int[u/Sqrt[Sqrt[a]-I*v],x]] +
  Dist[(1+I)/2, Int[u/Sqrt[Sqrt[a]+I*v],x]] /;
FreeQ[a,x] && ZeroQ[w-v^2] && PositiveQ[a] && Not[LinearQ[v,x]]


(* ::PageBreak:: *)
(**)


(* ::Title::Bold::Closed:: *)
(*\[Integral]1/(a c+b c u) \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Note: Constant factors in denominator are aggressively factored out to prevent them occurring unnecessarily in logarithm of antiderivative!*)


(* ::Subsubsection:: *)
(*Rule:*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]1/(a c+b c u) \[DifferentialD]x  \[LongRightArrow]  (1/c)\[Integral]1/(a+b u) \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
If[ShowSteps,

Int[1/(a_+b_.*u_),x_Symbol] :=
  Module[{lst=ConstantFactor[a+b*u,x]},
  ShowStep["","Int[1/(a*c+b*c*u),x]","Int[1/(a+b*u),x]/c",Hold[
  Dist[1/lst[[1]],Int[1/lst[[2]],x]]]] /;
 lst[[1]]=!=1] /;
SimplifyFlag && FreeQ[{a,b},x] && (
	MatchQ[u,f_^(c_.+d_.*x) /; FreeQ[{c,d,f},x]] ||
	MatchQ[u,f_[c_.+d_.*x] /; FreeQ[{c,d},x] && MemberQ[{Tan,Cot,Tanh,Coth},f]]),

Int[1/(a_+b_.*u_),x_Symbol] :=
  Module[{lst=ConstantFactor[a+b*u,x]},
  Dist[1/lst[[1]],Int[1/lst[[2]],x]] /;
 lst[[1]]=!=1] /;
FreeQ[{a,b},x] && (
	MatchQ[u,f_^(c_.+d_.*x) /; FreeQ[{c,d,f},x]] ||
	MatchQ[u,f_[c_.+d_.*x] /; FreeQ[{c,d},x] && MemberQ[{Tan,Cot,Tanh,Coth},f]])]
