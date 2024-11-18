(* ::Package:: *)

(* ::Title::Bold::Closed:: *)
(*\[Integral](c (a+b x)^n)^m \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Derivation: Reciprocal rule for integration*)


(* ::Subsubsection:: *)
(*Basis: \!\( *)
(*\*SubscriptBox[\(\[PartialD]\), \(x\)]*)
(*\*FractionBox[*)
(*SuperscriptBox[\((a\ *)
(*\*SuperscriptBox[\(f[x]\), \(n\)])\), \(m\)], *)
(*SuperscriptBox[\(f[x]\), \(m\ n\)]]\)=0*)


(* ::Subsubsection:: *)
(*Rule: If  m n+1=0, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral](c (a+b x)^n)^m \[DifferentialD]x  \[LongRightArrow]  (((a+b x) (c (a+b x)^n)^m Log[a+b x])/b)*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[(c_.*(a_.+b_.*x_)^n_.)^m_,x_Symbol] :=
  (a+b*x)*(c*(a+b*x)^n)^m*Log[a+b*x]/b /;
FreeQ[{a,b,c,m,n},x] && ZeroQ[m*n+1]


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Derivation: Power rule for integration*)


(* ::Subsubsection:: *)
(*Basis: \!\( *)
(*\*SubscriptBox[\(\[PartialD]\), \(x\)]*)
(*\*FractionBox[*)
(*SuperscriptBox[\((a\ *)
(*\*SuperscriptBox[\(f[x]\), \(n\)])\), \(m\)], *)
(*SuperscriptBox[\(f[x]\), \(m\ n\)]]\)=0*)


(* ::Subsubsection:: *)
(*Rule: If  m n+1!=0, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral](c (a+b x)^n)^m \[DifferentialD]x  \[LongRightArrow]  (((a+b x) (c (a+b x)^n)^m)/(b (m n+1)))*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[(c_.*(a_.+b_.*x_)^n_)^m_,x_Symbol] :=
  (a+b*x)*(c*(a+b*x)^n)^m/(b*(m*n+1)) /;
FreeQ[{a,b,c,m,n},x] && NonzeroQ[m*n+1]


(* ::PageBreak:: *)
(**)


(* ::Title::Bold::Closed:: *)
(*\[Integral](a x^m+b x^n)^p \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Derivation: Algebraic simplification*)


(* ::Subsubsection:: *)
(*Basis: a z^m+b z^n=z^m (a+b z^(n-m))*)


(* ::Subsubsection:: *)
(*Note: Since  m p+1=n-m, rule for \[Integral]x^(n-1) (a+b x^n)^p\[DifferentialD]x applies.*)


(* ::Subsubsection:: *)
(*Rule: If  p\[Element]\[DoubleStruckCapitalZ] \[And] m p+1=n-m, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral](a x^m+b x^n)^p \[DifferentialD]x  \[LongRightArrow]  \[Integral]x^(m p) (a+b x^(n-m))^p \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[(a_.*x_^m_.+b_.*x_^n_.)^p_,x_Symbol] :=
  Int[x^(m*p)*(a+b*x^(n-m))^p,x] /;
FreeQ[{a,b,m,n},x] && IntegerQ[p] && ZeroQ[m*p+1-n+m] && Not[IntegersQ[m,n]]


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Derivation: Algebraic simplification*)


(* ::Subsubsection:: *)
(*Basis: a z^m+b z^n=z^m (a+b z^(n-m))*)


(* ::Subsubsection:: *)
(*Note: Since  m p+1=n-m, rule for \[Integral](x^((n-1)/p) (a+b x^n))^p \[DifferentialD]x applies.*)


(* ::Subsubsection:: *)
(*Rule: If  p\[Element]\[DoubleStruckCapitalF] \[And] m p+1=n-m, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral](a x^m+b x^n)^p \[DifferentialD]x  \[LongRightArrow]  \[Integral](x^m (a+b x^(n-m)))^p \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[(a_.*x_^m_.+b_.*x_^n_.)^p_,x_Symbol] :=
  Int[(x^m*(a+b*x^(n-m)))^p,x] /;
FreeQ[{a,b,m,n},x] && FractionQ[p] && ZeroQ[m*p+1-n+m]


(* ::PageBreak:: *)
(**)


(* ::Title::Bold::Closed:: *)
(*\[Integral](a x^m+b x^n+c x^q)^p \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Derivation: Algebraic simplification*)


(* ::Subsubsection:: *)
(*Basis: a z^m+b z^n+c z^q=z^m (a+b z^(n-m)+c z^(q-m))*)


(* ::Subsubsection:: *)
(*Rule: If  m,n,q\[Element]\[DoubleStruckCapitalZ] \[And] p\[Element]\[DoubleStruckCapitalF] \[And] n<=m<=q, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral](a x^m+b x^n+c x^q)^p \[DifferentialD]x  \[LongRightArrow]  \[Integral](x^m (a+b x^(n-m)+c x^(q-m)))^p \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[(a_.*x_^m_.+b_.*x_^n_.+c_.*x_^q_.)^p_,x_Symbol] :=
  Int[(x^m*(a+b*x^(n-m)+c*x^(q-m)))^p,x] /;
FreeQ[{a,b,c},x] && IntegersQ[m,n,q] && FractionQ[p] && m<=n<=q


(* ::PageBreak:: *)
(**)


(* ::Title::Bold::Closed:: *)
(*\[Integral](u x^m)/(a x^n+b x^p) \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Derivation: Algebraic simplification*)


(* ::Subsubsection:: *)
(*Basis: x^m/(a x^n+b x^p)=x^(m-n)/(a+b x^(p-n))*)


(* ::Subsubsection:: *)
(*Rule: If  m,n,p\[Element]\[DoubleStruckCapitalF] \[And] 0<n<=p, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral](u x^m)/(a x^n+b x^p) \[DifferentialD]x  \[LongRightArrow]  \[Integral](u x^(m-n))/(a+b x^(p-n)) \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[u_.*x_^m_./(a_.*x_^n_.+b_.*x_^p_),x_Symbol] :=
  Int[u*x^(m-n)/(a+b*x^(p-n)),x] /;
FreeQ[{a,b},x] && FractionQ[{m,n,p}] && 0<n<=p


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Derivation: Algebraic simplification*)


(* ::Subsubsection:: *)
(*Basis: x^m/(a x^n+b x^p)=x^(m-n)/(a+b x^(p-n))*)


(* ::Subsubsection:: *)
(*Rule: If  m,n,p\[Element]\[DoubleStruckCapitalF] \[And] 0<n<=p \[And] v is not a polynomial in x, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral](u x^(m-n)+v)/(a x^n+b x^p) \[DifferentialD]x  \[LongRightArrow]  \[Integral](u x^(m-n))/(a+b x^(p-n)) \[DifferentialD]x+\[Integral]v/(a x^n+b x^p) \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[(u_.*x_^m_.+v_)/(a_.*x_^n_.+b_.*x_^p_),x_Symbol] :=
  Int[u*x^(m-n)/(a+b*x^(p-n)),x] + Int[v/(a*x^n+b*x^p),x] /;
FreeQ[{a,b},x] && FractionQ[{m,n,p}] && 0<n<=p && Not[PolynomialQ[v,x]]


(* ::PageBreak:: *)
(**)


(* ::Title::Bold::Closed:: *)
(*\[Integral]x^m (u+v+\[CenterEllipsis])\[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Derivation: Algebraic simplification*)


(* ::Subsubsection:: *)
(*Basis: x^m (u+v+\[CenterEllipsis])=x^m u+x^m v+\[CenterEllipsis]*)


(* ::Subsubsection:: *)
(*Rule:*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]x^m (u+v+\[CenterEllipsis])\[DifferentialD]x  \[LongRightArrow]  \[Integral](x^m u+x^m v+\[CenterEllipsis])\[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
If[ShowSteps,
Int[x_^m_.*u_,x_Symbol] :=
  ShowStep["","Int[x^m*(u+v+\[CenterEllipsis]),x]","Int[x^m*u+x^m*v+\[CenterEllipsis],x]",Hold[
  Int[Map[Function[x^m*#],u],x]]] /;
SimplifyFlag && FreeQ[m,x] && SumQ[u],

Int[x_^m_.*u_,x_Symbol] :=
  Int[Map[Function[x^m*#],u],x] /;
FreeQ[m,x] && SumQ[u]]


(* ::PageBreak:: *)
(**)


(* ::Title::Bold::Closed:: *)
(*\[Integral](a+b x^n)^p/x \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Reference: CRC 276b*)


(* ::Subsubsection:: *)
(*Rule: If  a>0, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]1/(x Sqrt[a+b x^n]) \[DifferentialD]x  \[LongRightArrow]  -(2/(n Sqrt[a])) ArcTanh[Sqrt[a+b x^n]/Sqrt[a]]*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[1/(x_*Sqrt[a_+b_.*x_^n_.]),x_Symbol] :=
  -2*ArcTanh[Sqrt[a+b*x^n]/Rt[a,2]]/(n*Rt[a,2]) /;
FreeQ[{a,b,n},x] && PosQ[a]


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Reference: CRC 277*)


(* ::Subsubsection:: *)
(*Rule: If  \[Not](a>0), then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]1/(x Sqrt[a+b x^n]) \[DifferentialD]x  \[LongRightArrow]  (2/(n Sqrt[-a])) ArcTan[Sqrt[a+b x^n]/Sqrt[-a]]*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[1/(x_*Sqrt[a_+b_.*x_^n_.]),x_Symbol] :=
  2*ArcTan[Sqrt[a+b*x^n]/Rt[-a,2]]/(n*Rt[-a,2]) /;
FreeQ[{a,b,n},x] && NegQ[a]


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Reference: G&R 2.110.1, CRC 88b*)


(* ::Subsubsection:: *)
(*Rule: If  p\[Element]\[DoubleStruckCapitalF] \[And] p>0, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral](a+b x^n)^p/x \[DifferentialD]x  \[LongRightArrow]  ((a+b x^n)^p/(n p))+a \[Integral](a+b x^n)^(p-1)/x \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[(a_+b_.*x_^n_.)^p_/x_,x_Symbol] :=
  (a+b*x^n)^p/(n*p) +
  Dist[a,Int[(a+b*x^n)^(p-1)/x,x]] /;
FreeQ[{a,b,n},x] && FractionQ[p] && p>0


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Reference: G&R 2.110.2, CRC 88d*)


(* ::Subsubsection:: *)
(*Rule: If  p\[Element]\[DoubleStruckCapitalF] \[And] p<-1, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral](a+b x^n)^p/x \[DifferentialD]x  \[LongRightArrow]  -((a+b x^n)^(p+1)/(a n (p+1)))+1/a \[Integral](a+b x^n)^(p+1)/x \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[(a_+b_.*x_^n_.)^p_/x_,x_Symbol] :=
  -(a+b*x^n)^(p+1)/(a*n*(p+1)) +
  Dist[1/a,Int[(a+b*x^n)^(p+1)/x,x]] /;
FreeQ[{a,b,n},x] && FractionQ[p] && p<-1


(* ::PageBreak:: *)
(**)


(* ::Title::Bold::Closed:: *)
(*\[Integral]1/((a+b x) Sqrt[c+d x]) \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Reference: G&R 2.246.1', CRC 147a', A&S 3.3.30'*)


(* ::Subsubsection:: *)
(*Rule: If (b c-a d)/b>0, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]1/((a+b x) Sqrt[c+d x]) \[DifferentialD]x  \[LongRightArrow]  -(2/(b Sqrt[(b c-a d)/b]))ArcTanh[Sqrt[c+d x]/Sqrt[(b c-a d)/b]]*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[1/((a_.+b_.*x_)*Sqrt[c_.+d_.*x_]),x_Symbol] :=
  -2*ArcTanh[Sqrt[c+d*x]/Rt[(b*c-a*d)/b,2]]/(b*Rt[(b*c-a*d)/b,2]) /;
FreeQ[{a,b,c,d},x] && PosQ[(b*c-a*d)/b]


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Reference: G&R 2.246.2, CRC 148, A&S 3.3.29*)


(* ::Subsubsection:: *)
(*Rule: If  \[Not]((b c-a d)/b>0), then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]1/((a+b x) Sqrt[c+d x]) \[DifferentialD]x  \[LongRightArrow]  (2/(b Sqrt[(a d-b c)/b]))ArcTan[Sqrt[c+d x]/Sqrt[(a d-b c)/b]]*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[1/((a_.+b_.*x_)*Sqrt[c_.+d_.*x_]),x_Symbol] :=
  2*ArcTan[Sqrt[c+d*x]/Rt[(a*d-b*c)/b,2]]/(b*Rt[(a*d-b*c)/b,2]) /;
FreeQ[{a,b,c,d},x] && NegQ[(b*c-a*d)/b]


(* ::PageBreak:: *)
(**)


(* ::Title::Bold::Closed:: *)
(*\[Integral]1/(Sqrt[a+b x] Sqrt[c+d x]) \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Rule: If a+c=0 \[And] a>0, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]1/(Sqrt[a+b x] Sqrt[c+b x]) \[DifferentialD]x  \[LongRightArrow]  (1/b)ArcCosh[(b x)/a]*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[1/(Sqrt[a_+b_.*x_]*Sqrt[c_+b_.*x_]),x_Symbol] :=
  ArcCosh[b*x/a]/b /;
FreeQ[{a,b,c},x] && ZeroQ[a+c] && PositiveQ[a]


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Rule: If  b+d=0 \[And] a+c>0, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]1/(Sqrt[a+b x] Sqrt[c+d x]) \[DifferentialD]x  \[LongRightArrow]  (1/b) ArcSin[(a-c+2 b x)/(a+c)]*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[1/(Sqrt[a_+b_.*x_]*Sqrt[c_+d_.*x_]),x_Symbol] :=
  ArcSin[(a-c+2*b*x)/(a+c)]/b /;
FreeQ[{a,b,c,d},x] && ZeroQ[b+d] && PositiveQ[a+c]


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Rule: If  a d-b c>0 \[And] d>0 \[And] b>0, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]1/(Sqrt[a+b x] Sqrt[c+d x]) \[DifferentialD]x  \[LongRightArrow]   (2/(Sqrt[b] Sqrt[d])) ArcSinh[(Sqrt[b] Sqrt[c+d x])/Sqrt[a d-b c]]*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[1/(Sqrt[a_.+b_.*x_]*Sqrt[c_.+d_.*x_]),x_Symbol] :=
  2/(Rt[b,2]*Sqrt[d])*ArcSinh[Rt[b,2]*Sqrt[c+d*x]/Sqrt[a*d-b*c]] /;
FreeQ[{a,b,c,d},x] && NonzeroQ[a*d-b*c] && PositiveQ[d/(a*d-b*c)] && Not[NegativeQ[a*d-b*c]] && PosQ[b]


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Rule: If  a d-b c>0 \[And] d>0 \[And] \[Not](b>0), then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]1/(Sqrt[a+b x] Sqrt[c+d x]) \[DifferentialD]x  \[LongRightArrow]   (2/(Sqrt[-b] Sqrt[d])) ArcSin[(Sqrt[-b] Sqrt[c+d x])/Sqrt[a d-b c]]*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[1/(Sqrt[a_.+b_.*x_]*Sqrt[c_.+d_.*x_]),x_Symbol] :=
  2/(Rt[-b,2]*Sqrt[d])*ArcSin[Rt[-b,2]*Sqrt[c+d*x]/Sqrt[a*d-b*c]] /;
FreeQ[{a,b,c,d},x] && NonzeroQ[a*d-b*c] && PositiveQ[d/(a*d-b*c)] && Not[NegativeQ[a*d-b*c]] && NegQ[b]


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Rule: If  a d-b c!=0 \[And] b d>0, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]1/(Sqrt[a+b x] Sqrt[c+d x]) \[DifferentialD]x  \[LongRightArrow]   (2/Sqrt[b d])ArcTanh[(Sqrt[b d] Sqrt[a+b x])/(b Sqrt[c+d x])]*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[1/(Sqrt[a_.+b_.*x_]*Sqrt[c_.+d_.*x_]),x_Symbol] :=
  2/Rt[b*d,2]*ArcTanh[Rt[b*d,2]*Sqrt[a+b*x]/(b*Sqrt[c+d*x])] /;
FreeQ[{a,b,c,d},x] && NonzeroQ[a*d-b*c] && PosQ[b*d]


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Rule: If  a d-b c!=0 \[And] \[Not](b d>0), then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]1/(Sqrt[a+b x] Sqrt[c+d x]) \[DifferentialD]x  \[LongRightArrow]   (2/Sqrt[-b d])ArcTan[(Sqrt[-b d] Sqrt[a+b x])/(b Sqrt[c+d x])]*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[1/(Sqrt[a_.+b_.*x_]*Sqrt[c_.+d_.*x_]),x_Symbol] :=
  2/Rt[-b*d,2]*ArcTan[Rt[-b*d,2]*Sqrt[a+b*x]/(b*Sqrt[c+d*x])] /;
FreeQ[{a,b,c,d},x] && NonzeroQ[a*d-b*c] && NegQ[b*d]


(* ::PageBreak:: *)
(**)


(* ::Title::Bold::Closed:: *)
(*\[Integral](a+b x)^m (c+d x)^n \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Derivation: Algebraic simplification*)


(* ::Subsubsection:: *)
(*Basis: If  a+c>=0, then (a+z)^m (c-z)^m=(a c-(a-c) z-z^2)^m*)


(* ::Subsubsection:: *)
(*Rule: If  m \[Element]\[DoubleStruckCapitalF] \[And] b+d=0 \[And] a+c>0, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral](a+b x)^m (c+d x)^m \[DifferentialD]x  \[LongRightArrow]  \[Integral](a c+(a d+b c) x+b d x^2)^m \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[(a_.+b_.*x_)^m_*(c_+d_.*x_)^m_,x_Symbol] :=
  Int[(a*c+(a*d+b*c)*x+b*d*x^2)^m,x] /;
FreeQ[{a,b,c,d},x] && FractionQ[m] && ZeroQ[b+d] && PositiveQ[a+c]


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Derivation: Algebraic simplification*)


(* ::Subsubsection:: *)
(*Basis: If  b c-a d=0 and n is an integer, then (a+b x)^m (c+d x)^n=(d/b)^n (a+b x)^(m+n)*)


(* ::Subsubsection:: *)
(*Rule: If  b c-a d=0 \[And] m\[NotElement]\[DoubleStruckCapitalZ] \[And] n\[Element]\[DoubleStruckCapitalZ], then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral](a+b x)^m (c+d x)^n \[DifferentialD]x  \[LongRightArrow]  (d/b)^n\[Integral](a+b x)^(m+n) \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[(a_.+b_.*x_)^m_.*(c_.+d_.*x_)^n_.,x_Symbol] :=
  Dist[(d/b)^n,Int[(a+b*x)^(m+n),x]] /;
FreeQ[{a,b,c,d,m},x] && ZeroQ[b*c-a*d] && Not[IntegerQ[m]] && IntegerQ[n]


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Rule: If  b c-a d=0 \[And] m \[NotElement]\[DoubleStruckCapitalZ] \[And] n\[NotElement]\[DoubleStruckCapitalZ] \[And] m+n+1=0, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral](a+b x)^m (c+d x)^n \[DifferentialD]x  \[LongRightArrow]  (((a+b x)^(m+1) (c+d x)^n Log[a+b x])/b)*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[(a_.+b_.*x_)^m_*(c_.+d_.*x_)^n_,x_Symbol] :=
  (a+b*x)^(m+1)*(c+d*x)^n*Log[a+b*x]/b /;
FreeQ[{a,b,c,d,m,n},x] && ZeroQ[b*c-a*d] && Not[IntegerQ[m]] && Not[IntegerQ[n]] && ZeroQ[m+n+1] && 
(LeafCount[a+b*x]<LeafCount[c+d*x] || LeafCount[a+b*x]==LeafCount[c+d*x] && PosQ[a])


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Rule: If  b c-a d=0 \[And] m \[NotElement]\[DoubleStruckCapitalZ] \[And] n\[NotElement]\[DoubleStruckCapitalZ] \[And] m+n+1!=0, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral](a+b x)^m (c+d x)^n \[DifferentialD]x  \[LongRightArrow]  (((a+b x)^(m+1) (c+d x)^n)/(b (m+n+1)))*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[(a_.+b_.*x_)^m_*(c_.+d_.*x_)^n_,x_Symbol] :=
  (a+b*x)^(m+1)*(c+d*x)^n/(b*(m+n+1)) /;
FreeQ[{a,b,c,d,m,n},x] && ZeroQ[b*c-a*d] && Not[IntegerQ[m]] && Not[IntegerQ[n]] && 
NonzeroQ[m+n+1]


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Reference: G&R 2.155, CRC 59a*)


(* ::Subsubsection:: *)
(*Rule: If  b c-a d!=0 \[And] m+n+2=0 \[And] n+1!=0, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral](a+b x)^m (c+d x)^n \[DifferentialD]x  \[LongRightArrow]  -(((a+b x)^(m+1) (c+d x)^(n+1))/((n+1) (b c-a d)))*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[(a_.+b_.*x_)^m_.*(c_.+d_.*x_.)^n_,x_Symbol] :=
  -(a+b*x)^(m+1)*(c+d*x)^(n+1)/((n+1)*(b*c-a*d)) /;
FreeQ[{a,b,c,d,m,n},x] && NonzeroQ[b*c-a*d] && ZeroQ[m+n+2] && NonzeroQ[n+1]


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Reference: G&R 2.151, CRC 59b*)


(* ::Subsubsection:: *)
(*Rule: If  b c-a d!=0 \[And] n\[Element]\[DoubleStruckCapitalF] \[And] n>0, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral](c+d x)^n/(a+b x) \[DifferentialD]x  \[LongRightArrow]  ((c+d x)^n/(b n))+(b c-a d)/b \[Integral](c+d x)^(n-1)/(a+b x) \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[(c_.+d_.*x_)^n_./(a_.+b_.*x_),x_Symbol] :=
  (c+d*x)^n/(b*n) +
  Dist[(b*c-a*d)/b,Int[(c+d*x)^(n-1)/(a+b*x),x]] /;
FreeQ[{a,b,c,d},x] && NonzeroQ[b*c-a*d] && FractionQ[n] && n>0


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Reference: G&R 2.151, CRC 59b*)


(* ::Subsubsection:: *)
(*Note: Experimental!*)


(* ::Subsubsection:: *)
(*Rule: If  b c-a d!=0 \[And] m \[NotElement]\[DoubleStruckCapitalZ], then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral](a+b x)^m (c+d x)\[DifferentialD]x  \[LongRightArrow]  (((a+b x)^(m+1) (c+d x))/(b (m+2)))+(b c-a d)/(b (m+2)) \[Integral](a+b x)^m \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[(a_.+b_.*x_)^m_*(c_.+d_.*x_),x_Symbol] :=
  (a+b*x)^(m+1)*(c+d*x)/(b*(m+2)) +
  Dist[(b*c-a*d)/(b*(m+2)),Int[(a+b*x)^m,x]] /;
FreeQ[{a,b,c,d,m},x] && NonzeroQ[b*c-a*d] && Not[IntegerQ[m]]


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Reference: G&R 2.155, CRC 59a*)


(* ::Subsubsection:: *)
(*Rule: If  b c-a d!=0 \[And] m+n+1!=0 \[And] n>0 \[And] m \[NotElement]\[DoubleStruckCapitalZ] \[And] (n\[Element]\[DoubleStruckCapitalZ] \[Or] (m\[Element]\[DoubleStruckCapitalF] \[And] (n<=m \[Or] -1<=m<0))), then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral](a+b x)^m (c+d x)^n \[DifferentialD]x  \[LongRightArrow]  (((a+b x)^(m+1) (c+d x)^n)/(b (m+n+1)))+(n (b c-a d))/(b (m+n+1)) \[Integral](a+b x)^m (c+d x)^(n-1) \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[(a_.+b_.*x_)^m_*(c_.+d_.*x_)^n_,x_Symbol] :=
  (a+b*x)^(m+1)*(c+d*x)^n/(b*(m+n+1)) +
  Dist[n*(b*c-a*d)/(b*(m+n+1)),Int[(a+b*x)^m*(c+d*x)^(n-1),x]] /;
FreeQ[{a,b,c,d,m},x] && NonzeroQ[b*c-a*d] && NonzeroQ[m+n+1] && RationalQ[n] && n>0 &&
Not[IntegerQ[m]] && (IntegerQ[n] || FractionQ[m] && (n<=m || -1<=m<0))


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Reference: G&R 2.155, CRC 59a*)


(* ::Subsubsection:: *)
(*Rule: If  b c-a d!=0 \[And] n<-1 \[And] \[Not](m \[Element]\[DoubleStruckCapitalZ] \[And] n\[Element]\[DoubleStruckCapitalZ]) \[And] (m\[NotElement]\[DoubleStruckCapitalQ] \[Or] n>=m \[Or] -1<=m<0), then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral](a+b x)^m (c+d x)^n \[DifferentialD]x  \[LongRightArrow]  -(((a+b x)^(m+1) (c+d x)^(n+1))/((n+1) (b c-a d)))+(b(m+n+2))/((n+1) (b c-a d)) \[Integral](a+b x)^m (c+d x)^(n+1) \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[(a_.+b_.*x_)^m_.*(c_.+d_.*x_)^n_,x_Symbol] :=
  -(a+b*x)^(m+1)*(c+d*x)^(n+1)/((n+1)*(b*c-a*d)) +
  Dist[b*(m+n+2)/((n+1)*(b*c-a*d)),Int[(a+b*x)^m*(c+d*x)^(n+1),x]] /;
FreeQ[{a,b,c,d,m},x] && NonzeroQ[b*c-a*d] && RationalQ[n] && n<-1 && Not[IntegersQ[m,n]] &&
(Not[RationalQ[m]] || n>=m || -1<=m<0)


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Reference: G&R 2.155, CRC 59a*)


(* ::Subsubsection:: *)
(*Rule: If  b c-a d!=0 \[And] n+1!=0 \[And] n\[NotElement]\[DoubleStruckCapitalQ] \[And] m+n<-1, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral](a+b x)^m (c+d x)^n \[DifferentialD]x  \[LongRightArrow]  -(((a+b x)^(m+1) (c+d x)^(n+1))/((n+1) (b c-a d)))+(b(m+n+2))/((n+1)(b c-a d)) \[Integral](a+b x)^m (c+d x)^(n+1) \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[(a_.+b_.*x_)^m_.*(c_.+d_.*x_)^n_,x_Symbol] :=
  -(a+b*x)^(m+1)*(c+d*x)^(n+1)/((n+1)*(b*c-a*d)) +
  Dist[b*(m+n+2)/((n+1)*(b*c-a*d)),Int[(a+b*x)^m*(c+d*x)^(n+1),x]] /;
FreeQ[{a,b,c,d,m,n},x] && NonzeroQ[b*c-a*d] && NonzeroQ[n+1] && Not[RationalQ[n]] && 
RationalQ[m+n] && Simplify[m+n]<-1


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Reference: G&R 2.153.3, CRC 59c*)


(* ::Subsubsection:: *)
(*Rule: If  n \[NotElement]\[DoubleStruckCapitalZ], then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral](a+b x) (c+d x)^n \[DifferentialD]x  \[LongRightArrow]  (((a+b x) (c+d x)^(n+1))/(d (n+1)))-b/(d (n+1)) \[Integral](c+d x)^(n+1) \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[(a_.+b_.*x_)*(c_.+d_.*x_)^n_,x_Symbol] :=
  (a+b*x)*(c+d*x)^(n+1)/(d*(n+1)) -
  Dist[b/(d*(n+1)),Int[(c+d*x)^(n+1),x]] /;
FreeQ[{a,b,c,d,n},x] && Not[IntegerQ[n]]


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Reference: G&R 2.153.3, CRC 59c*)


(* ::Subsubsection:: *)
(*Rule: If  \[Not](m\[Element]\[DoubleStruckCapitalZ] \[And] n\[Element]\[DoubleStruckCapitalZ])\[And] m>0 \[And] n<-1, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral](a+b x)^m (c+d x)^n \[DifferentialD]x  \[LongRightArrow]  (((a+b x)^m (c+d x)^(n+1))/(d (n+1)))-(b m)/(d (n+1)) \[Integral](a+b x)^(m-1) (c+d x)^(n+1) \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[(a_.+b_.*x_)^m_*(c_.+d_.*x_)^n_,x_Symbol] :=
  (a+b*x)^m*(c+d*x)^(n+1)/(d*(n+1)) -
  Dist[b*m/(d*(n+1)),Int[(a+b*x)^(m-1)*(c+d*x)^(n+1),x]] /;
FreeQ[{a,b,c,d},x] && RationalQ[{m,n}] && Not[IntegersQ[m,n]] && m>0 && n<-1


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Derivation: Integration by substitution*)


(* ::Subsubsection:: *)
(*Basis: If n,p\[Element]\[DoubleStruckCapitalZ], then (a+b x)^(n/p)/(c+d x)=p ((a+b x)^(1/p))^(n+p-1)/(b c-a d+d ((a+b x)^(1/p))^p) \!\( *)
(*\*SubscriptBox[\(\[PartialD]\), \(x\)]*)
(*\*SuperscriptBox[\((a + b\ x)\), \(1/p\)]\)*)


(* ::Subsubsection:: *)
(*Rule: If  -1<m<0, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral](a+b x)^(n/p)/(c+d x) \[DifferentialD]x  \[LongRightArrow]  p Subst[\[Integral]x^(n+p-1)/(b c-a d+d x^p) \[DifferentialD]x,x,(a+b x)^(1/p)]*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[(a_.+b_.*x_)^m_/(c_+d_.*x_),x_Symbol] :=
  Module[{p=Denominator[m]},
  Dist[p,Subst[Int[x^(m*p+p-1)/(b*c-a*d+d*x^p),x],x,(a+b*x)^(1/p)]]] /;
FreeQ[{a,b,c,d},x] && RationalQ[m] && -1<m<0


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Derivation: Integration by substitution*)


(* ::Subsubsection:: *)
(*Basis: If n,p\[Element]\[DoubleStruckCapitalZ], then (a+b x)^(n/p)/(c+d x)=p ((a+b x)^(1/p)/(c+d x)^(1/p))^(m+p-1)/(b -d ((a+b x)^(1/p)/(c+d x)^(1/p))^p) \!\( *)
(*\*SubscriptBox[\(\[PartialD]\), \(x\)]*)
(*\*FractionBox[*)
(*SuperscriptBox[\((a + b\ x)\), \(1/p\)], *)
(*SuperscriptBox[\((c + d\ x)\), \(1/p\)]]\)*)


(* ::Subsubsection:: *)
(*Rule: If  -1<m<0 \[And] m+n=-1, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral](a+b x)^(m/p) (c+d x)^n \[DifferentialD]x  \[LongRightArrow]  p Subst[\[Integral]x^(m+p-1)/(b-d x^p) \[DifferentialD]x,x,(a+b x)^(1/p)/(c+d x)^(1/p)]*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[(a_.+b_.*x_)^m_*(c_.+d_.*x_)^n_,x_Symbol] :=
  Module[{p=Denominator[m]},
  Dist[p,Subst[Int[x^(m*p+p-1)/(b-d*x^p),x],x,(a+b*x)^(1/p)/(c+d*x)^(1/p)]]] /;
FreeQ[{a,b,c,d},x] && RationalQ[{m,n}] && -1<m<0 && m+n==-1


(* ::PageBreak:: *)
(**)


(* ::Title::Bold::Closed:: *)
(*\[Integral]((a+b x)^n (c+d x)^n)/x \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Rule: If  a c>0, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]1/(x Sqrt[a+b x] Sqrt[c+d x]) \[DifferentialD]x  \[LongRightArrow]  -(2/ Sqrt[a c])ArcTanh[(Sqrt[a c] Sqrt[a+b x])/(a Sqrt[c+d x])]*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[1/(x_*Sqrt[a_+b_.*x_]*Sqrt[c_+d_.*x_]),x_Symbol] :=
  -2*ArcTanh[Rt[a*c,2]*Sqrt[a+b*x]/(a*Sqrt[c+d*x])]/Rt[a*c,2] /;
FreeQ[{a,b,c,d},x] && PosQ[a*c]


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Rule: If  \[Not](a c>0), then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]1/(x Sqrt[a+b x] Sqrt[c+d x]) \[DifferentialD]x  \[LongRightArrow]  -(2/Sqrt[-a c])ArcTan[(Sqrt[-a c] Sqrt[a+b x])/(a Sqrt[c+d x])]*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[1/(x_*Sqrt[a_+b_.*x_]*Sqrt[c_+d_.*x_]),x_Symbol] :=
  -2*ArcTan[Rt[-a*c,2]*Sqrt[a+b*x]/(a*Sqrt[c+d*x])]/Rt[-a*c,2] /;
FreeQ[{a,b,c,d},x] && NegQ[a*c]


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Reference: G&R 2.265b*)


(* ::Subsubsection:: *)
(*Rule: If  n\[Element]\[DoubleStruckCapitalF] \[And] n>0 \[And] a d+b c=0, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]((a+b x)^n (c+d x)^n)/x \[DifferentialD]x  \[LongRightArrow]  (((a+b x)^n (c+d x)^n)/(2 n))+a c \[Integral]((a+b x)^(n-1) (c+d x)^(n-1))/x \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[(a_+b_.*x_)^n_*(c_+d_.*x_)^n_/x_,x_Symbol] :=
  (a+b*x)^n*(c+d*x)^n/(2*n) +
  Dist[a*c,Int[(a+b*x)^(n-1)*(c+d*x)^(n-1)/x,x]] /;
FreeQ[{a,b,c,d},x] && FractionQ[n] && n>0 && ZeroQ[a*d+b*c]


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Rule: If  n\[Element]\[DoubleStruckCapitalF] \[And] n>0 \[And] a d+b c!=0, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]((a+b x)^n (c+d x)^n)/x \[DifferentialD]x  \[LongRightArrow]  (((a+b x)^n (c+d x)^n)/(2 n))+                                                                                 *)
(*                                       (a d+b c)/2 \[Integral](a+b x)^(n-1) (c+d x)^(n-1) \[DifferentialD]x+a c \[Integral]((a+b x)^(n-1) (c+d x)^(n-1))/x \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[(a_+b_.*x_)^n_*(c_+d_.*x_)^n_/x_,x_Symbol] :=
  (a+b*x)^n*(c+d*x)^n/(2*n) +
  Dist[(a*d+b*c)/2,Int[(a+b*x)^(n-1)*(c+d*x)^(n-1),x]] +
  Dist[a*c,Int[(a+b*x)^(n-1)*(c+d*x)^(n-1)/x,x]] /;
FreeQ[{a,b,c,d},x] && FractionQ[n] && n>0 && NonzeroQ[a*d+b*c]


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Reference: G&R 2.268b, CRC 122*)


(* ::Subsubsection:: *)
(*Rule: If  n\[Element]\[DoubleStruckCapitalF] \[And] n<-1 \[And] a d+b c=0, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]((a+b x)^n (c+d x)^n)/x \[DifferentialD]x  \[LongRightArrow]  -(((a+b x)^(n+1) (c+d x)^(n+1))/(2 a c (n+1)))+1/(a c) \[Integral]((a+b x)^(n+1) (c+d x)^(n+1))/x \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[(a_+b_.*x_)^n_*(c_+d_.*x_)^n_/x_,x_Symbol] :=
  -(a+b*x)^(n+1)*(c+d*x)^(n+1)/(2*a*c*(n+1)) +
  Dist[1/(a*c),Int[(a+b*x)^(n+1)*(c+d*x)^(n+1)/x,x]] /;
FreeQ[{a,b,c,d},x] && FractionQ[n] && n<-1 && ZeroQ[a*d+b*c]


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Rule: If  n\[Element]\[DoubleStruckCapitalF] \[And] n<-1 \[And] a d+b c!=0, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]((a+b x)^n (c+d x)^n)/x \[DifferentialD]x  \[LongRightArrow]  -(((a+b x)^(n+1) (c+d x)^(n+1))/(2 a c (n+1)))-                                                                 *)
(*                                            (a d+b c)/(2 a c) \[Integral](a+b x)^n (c+d x)^n \[DifferentialD]x+1/(a c) \[Integral]((a+b x)^(n+1) (c+d x)^(n+1))/x \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[(a_+b_.*x_)^n_*(c_+d_.*x_)^n_/x_,x_Symbol] :=
  -(a+b*x)^(n+1)*(c+d*x)^(n+1)/(2*a*c*(n+1)) -
  Dist[(a*d+b*c)/(2*a*c),Int[(a+b*x)^n*(c+d*x)^n,x]] +
  Dist[1/(a*c),Int[(a+b*x)^(n+1)*(c+d*x)^(n+1)/x,x]] /;
FreeQ[{a,b,c,d},x] && FractionQ[n] && n<-1 && NonzeroQ[a*d+b*c]


(* ::PageBreak:: *)
(**)


(* ::Title::Bold::Closed:: *)
(*\[Integral]((a+b x)^n (c+d x)^p)/x \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Derivation: Algebraic expansion*)


(* ::Subsubsection:: *)
(*Basis: (a+b x)^n/x=b (a+b x)^(n-1)+(a (a+b x)^(n-1))/x*)


(* ::Subsubsection:: *)
(*Rule: If  n,p\[Element]\[DoubleStruckCapitalF] \[And] n>0 \[And] n-p\[Element]\[DoubleStruckCapitalZ], then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]((a+b x)^n (c+d x)^p)/x \[DifferentialD]x  \[LongRightArrow]  b\[Integral](a+b x)^(n-1) (c+d x)^p \[DifferentialD]x+a \[Integral]((a+b x)^(n-1) (c+d x)^p)/x \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[(a_+b_.*x_)^n_*(c_+d_.*x_)^p_/x_,x_Symbol] :=
  Dist[b,Int[(a+b*x)^(n-1)*(c+d*x)^p,x]] +
  Dist[a,Int[(a+b*x)^(n-1)*(c+d*x)^p/x,x]] /;
FreeQ[{a,b,c,d},x] && FractionQ[{n,p}] && n>0 && IntegerQ[n-p]


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Derivation: Algebraic expansion*)


(* ::Subsubsection:: *)
(*Basis: (a+b x)^n/x=(a+b x)^(n+1)/(a x)-(b (a+b x)^n)/a*)


(* ::Subsubsection:: *)
(*Rule: If  n,p\[Element]\[DoubleStruckCapitalF] \[And] n<-1 \[And] n-p\[Element]\[DoubleStruckCapitalZ], then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]((a+b x)^n (c+d x)^p)/x \[DifferentialD]x  \[LongRightArrow]  (1/a)\[Integral]((a+b x)^(n+1) (c+d x)^p)/x \[DifferentialD]x-b/a \[Integral](a+b x)^n (c+d x)^p \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[(a_+b_.*x_)^n_*(c_+d_.*x_)^p_/x_,x_Symbol] :=
  Dist[1/a,Int[(a+b*x)^(n+1)*(c+d*x)^p/x,x]] -
  Dist[b/a,Int[(a+b*x)^n*(c+d*x)^p,x]] /;
FreeQ[{a,b,c,d},x] && FractionQ[{n,p}] && n<-1 && IntegerQ[n-p]


(* ::PageBreak:: *)
(**)


(* ::Title::Bold::Closed:: *)
(*\[Integral]x^m (a+b x)^n (c+d x)^n \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Reference: G&R 2.174.2*)


(* ::Subsubsection:: *)
(*Rule: If  n\[Element]\[DoubleStruckCapitalF] \[And] m+2n+1=0 \[And] m>1 \[And] a d+b c=0, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]x^m (a+b x)^n (c+d x)^n \[DifferentialD]x  \[LongRightArrow]  ((x^(m-1) (a+b x)^(n+1) (c+d x)^(n+1))/(2 b d (n+1)))+1/(b d) \[Integral]x^(m-2) (a+b x)^(n+1) (c+d x)^(n+1) \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[x_^m_*(a_.+b_.*x_)^n_*(c_.+d_.*x_)^n_,x_Symbol] :=
  x^(m-1)*(a+b*x)^(n+1)*(c+d*x)^(n+1)/(2*b*d*(n+1)) +
  Dist[1/(b*d),Int[x^(m-2)*(a+b*x)^(n+1)*(c+d*x)^(n+1),x]] /;
FreeQ[{a,b,c,d},x] && FractionQ[n] && RationalQ[m] && m+2*n+1==0 && m>1 && ZeroQ[a*d+b*c]


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Rule: If  n\[Element]\[DoubleStruckCapitalF] \[And] m+2n+1=0 \[And] m>1 \[And] a d+b c!=0, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]x^m (a+b x)^n (c+d x)^n \[DifferentialD]x  \[LongRightArrow]  ((x^(m-1) (a+b x)^(n+1) (c+d x)^(n+1))/(2 b d (n+1)))-                                                                 *)
(*                                      (a d+b c)/(2 b d) \[Integral]x^(m-1) (a+b x)^n (c+d x)^n \[DifferentialD]x+1/(b d) \[Integral]x^(m-2) (a+b x)^(n+1) (c+d x)^(n+1) \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[x_^m_*(a_.+b_.*x_)^n_*(c_.+d_.*x_)^n_,x_Symbol] :=
  x^(m-1)*(a+b*x)^(n+1)*(c+d*x)^(n+1)/(2*b*d*(n+1)) -
  Dist[(a*d+b*c)/(2*b*d),Int[x^(m-1)*(a+b*x)^n*(c+d*x)^n,x]] +
  Dist[1/(b*d),Int[x^(m-2)*(a+b*x)^(n+1)*(c+d*x)^(n+1),x]] /;
FreeQ[{a,b,c,d},x] && FractionQ[n] && RationalQ[m] && m+2*n+1==0 && m>1 && NonzeroQ[a*d+b*c]


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Reference: G&R 2.174.1, CRC 119*)


(* ::Subsubsection:: *)
(*Rule: If  n+1!=0 \[And] a d+b c=0, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]x (a+b x)^n (c+d x)^n \[DifferentialD]x  \[LongRightArrow]  (((a+b x)^(n+1) (c+d x)^(n+1))/(2 b d (n+1)))*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[x_*(a_.+b_.*x_)^n_*(c_.+d_.*x_)^n_,x_Symbol] :=
  (a+b*x)^(n+1)*(c+d*x)^(n+1)/(2*b*d*(n+1)) /;
FreeQ[{a,b,c,d,n},x] && NonzeroQ[n+1] && ZeroQ[a*d+b*c]


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Rule: If  n\[Element]\[DoubleStruckCapitalF], then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]x (a+b x)^n (c+d x)^n \[DifferentialD]x  \[LongRightArrow]  (((a+b x)^(n+1) (c+d x)^(n+1))/(2 b d (n+1)))-(a d+b c)/(2 b d) \[Integral](a+b x)^n (c+d x)^n \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[x_*(a_.+b_.*x_)^n_*(c_.+d_.*x_)^n_,x_Symbol] :=
  (a+b*x)^(n+1)*(c+d*x)^(n+1)/(2*b*d*(n+1)) -
  Dist[(a*d+b*c)/(2*b*d),Int[(a+b*x)^n*(c+d*x)^n,x]] /;
FreeQ[{a,b,c,d},x] && FractionQ[n]


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Rule: If  n\[Element]\[DoubleStruckCapitalF] \[And] m+2n+1!=0 \[And] m>1 \[And] (m+n=0 \[Or] a d+b c=0), then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]x^m (a+b x)^n (c+d x)^n \[DifferentialD]x  \[LongRightArrow]  ((x^(m-1) (a+b x)^(n+1) (c+d x)^(n+1))/(b d (m+2 n+1)))-(a c (m-1))/(b d (m+2 n+1)) \[Integral]x^(m-2) (a+b x)^n (c+d x)^n \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[x_^m_*(a_.+b_.*x_)^n_*(c_.+d_.*x_)^n_,x_Symbol] :=
  x^(m-1)*(a+b*x)^(n+1)*(c+d*x)^(n+1)/(b*d*(m+2*n+1)) -
  Dist[a*c*(m-1)/(b*d*(m+2*n+1)),Int[x^(m-2)*(a+b*x)^n*(c+d*x)^n,x]] /;
FreeQ[{a,b,c,d},x] && FractionQ[n] && RationalQ[m] && NonzeroQ[m+2*n+1] && m>1 &&
(ZeroQ[m+n] || ZeroQ[a*d+b*c])


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Rule: If  n\[Element]\[DoubleStruckCapitalF] \[And] m+2n+1!=0 \[And] m>1 \[And] m+n!=0 \[And] a d+b c!=0, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]x^m (a+b x)^n (c+d x)^n \[DifferentialD]x  \[LongRightArrow]  ((x^(m-1) (a+b x)^(n+1) (c+d x)^(n+1))/(b d (m+2 n+1)))-                                                                                        *)
(*                            ((m+n) (a d+b c))/(b d (m+2 n+1)) \[Integral]x^(m-1) (a+b x)^n (c+d x)^n \[DifferentialD]x-(a c (m-1))/(b d (m+2 n+1)) \[Integral]x^(m-2) (a+b x)^n (c+d x)^n \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[x_^m_*(a_.+b_.*x_)^n_*(c_.+d_.*x_)^n_,x_Symbol] :=
  x^(m-1)*(a+b*x)^(n+1)*(c+d*x)^(n+1)/(b*d*(m+2*n+1)) -
  Dist[(m+n)*(a*d+b*c)/(b*d*(m+2*n+1)),Int[x^(m-1)*(a+b*x)^n*(c+d*x)^n,x]] -
  Dist[a*c*(m-1)/(b*d*(m+2*n+1)),Int[x^(m-2)*(a+b*x)^n*(c+d*x)^n,x]] /;
FreeQ[{a,b,c,d},x] && FractionQ[n] && RationalQ[m] && NonzeroQ[m+2*n+1] && m>1 &&
NonzeroQ[m+n] && NonzeroQ[a*d+b*c]


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Reference: G&R 2.176, CRC 123*)


(* ::Subsubsection:: *)
(*Rule: If  m+1!=0 \[And] m+2n+3=0 \[And] a d+b c=0, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]x^m (a+b x)^n (c+d x)^n \[DifferentialD]x  \[LongRightArrow]  ((x^(m+1) (a+b x)^(n+1) (c+d x)^(n+1))/(a c (m+1)))*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[x_^m_*(a_+b_.*x_)^n_*(c_+d_.*x_)^n_,x_Symbol] :=
  x^(m+1)*(a+b*x)^(n+1)*(c+d*x)^(n+1)/(a*c*(m+1)) /;
FreeQ[{a,b,c,d,n},x] && NonzeroQ[m+1] && ZeroQ[m+2*n+3] && ZeroQ[a*d+b*c]


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Rule: If  n\[Element]\[DoubleStruckCapitalF] \[And] m<-1 \[And] m+2n+3=0, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]x^m (a+b x)^n (c+d x)^n \[DifferentialD]x  \[LongRightArrow]                                                                                                                                      *)
(*                               ((x^(m+1) (a+b x)^(n+1) (c+d x)^(n+1))/(a c (m+1)))-((m+n+2) (a d+b c))/(a c (m+1)) \[Integral]x^(m+1) (a+b x)^n (c+d x)^n \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[x_^m_*(a_+b_.*x_)^n_*(c_+d_.*x_)^n_,x_Symbol] :=
  x^(m+1)*(a+b*x)^(n+1)*(c+d*x)^(n+1)/(a*c*(m+1)) -
  Dist[(m+n+2)*(a*d+b*c)/(a*c*(m+1)),Int[x^(m+1)*(a+b*x)^n*(c+d*x)^n,x]] /;
FreeQ[{a,b,c,d},x] && FractionQ[n] && RationalQ[m] && m<-1 && ZeroQ[m+2*n+3]


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Rule: If  n\[Element]\[DoubleStruckCapitalF] \[And] m<-1 \[And] (m+n+2=0 \[Or] a d+b c=0), then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]x^m (a+b x)^n (c+d x)^n \[DifferentialD]x  \[LongRightArrow]  ((x^(m+1) (a+b x)^(n+1) (c+d x)^(n+1))/(a c (m+1)))-(b d (m+2 n+3))/(a c (m+1)) \[Integral]x^(m+2) (a+b x)^n (c+d x)^n \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[x_^m_*(a_+b_.*x_)^n_*(c_+d_.*x_)^n_,x_Symbol] :=
  x^(m+1)*(a+b*x)^(n+1)*(c+d*x)^(n+1)/(a*c*(m+1)) -
  Dist[b*d*(m+2*n+3)/(a*c*(m+1)),Int[x^(m+2)*(a+b*x)^n*(c+d*x)^n,x]] /;
FreeQ[{a,b,c,d},x] && FractionQ[n] && RationalQ[m] && m<-1 && (ZeroQ[m+n+2] || ZeroQ[a*d+b*c])


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Rule: If  n\[Element]\[DoubleStruckCapitalF] \[And] m<-1 \[And] m+n+2!=0 \[And] m+2n+3!=0 \[And] a d+b c!=0, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]x^m (a+b x)^n (c+d x)^n \[DifferentialD]x  \[LongRightArrow]  ((x^(m+1) (a+b x)^(n+1) (c+d x)^(n+1))/(a c (m+1)))-                                                                                              *)
(*                    ((m+n+2) (a d+b c))/(a c (m+1)) \[Integral]x^(m+1) (a+b x)^n (c+d x)^n \[DifferentialD]x-(b d (m+2 n+3))/(a c (m+1)) \[Integral]x^(m+2) (a+b x)^n (c+d x)^n \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[x_^m_*(a_+b_.*x_)^n_*(c_+d_.*x_)^n_,x_Symbol] :=
  x^(m+1)*(a+b*x)^(n+1)*(c+d*x)^(n+1)/(a*c*(m+1)) -
  Dist[(m+n+2)*(a*d+b*c)/(a*c*(m+1)),Int[x^(m+1)*(a+b*x)^n*(c+d*x)^n,x]] -
  Dist[b*d*(m+2*n+3)/(a*c*(m+1)),Int[x^(m+2)*(a+b*x)^n*(c+d*x)^n,x]] /;
FreeQ[{a,b,c,d},x] && FractionQ[n] && RationalQ[m] && m<-1 && NonzeroQ[m+n+2] &&
NonzeroQ[m+2*n+3] && NonzeroQ[a*d+b*c]


(* ::PageBreak:: *)
(**)


(* ::Title::Bold::Closed:: *)
(*\[Integral]x^m (a+b x)^n (c+d x)^p \[DifferentialD]x*)


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Rule: If  m\[Element]\[DoubleStruckCapitalZ] \[And] m>0, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral](x^m Sqrt[a+b x])/Sqrt[c+d x] \[DifferentialD]x  \[LongRightArrow]  ((x^m Sqrt[a+b x] Sqrt[c+d x])/(d (m+1)))-                                                                       *)
(*        (a c m)/(d(m+1)) \[Integral]x^(m-1)/(Sqrt[a+b x] Sqrt[c+d x]) \[DifferentialD]x+(a d-b c (2 m+1))/(2 d (m+1)) \[Integral]x^m/(Sqrt[a+b x] Sqrt[c+d x]) \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[x_^m_.*Sqrt[a_+b_.*x_]/Sqrt[c_.+d_.*x_],x_Symbol] :=
  x^m*Sqrt[a+b*x]*Sqrt[c+d*x]/(d*(m+1)) -
  Dist[a*c*m/(d*(m+1)),Int[x^(m-1)/(Sqrt[a+b*x]*Sqrt[c+d*x]),x]] +
  Dist[(a*d-b*c*(2*m+1))/(2*d*(m+1)),Int[x^m/(Sqrt[a+b*x]*Sqrt[c+d*x]),x]] /;
FreeQ[{a,b,c,d},x] && IntegerQ[m] && m>0


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Rule:*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]Sqrt[a+b x]/(x^2 Sqrt[c+d x]) \[DifferentialD]x  \[LongRightArrow]  -((Sqrt[a+b x] Sqrt[c+d x])/(c x))+(b c-a d)/(2 c) \[Integral]1/(x Sqrt[a+b x] Sqrt[c+d x]) \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[Sqrt[a_+b_.*x_]/(x_^2*Sqrt[c_.+d_.*x_]),x_Symbol] :=
  -Sqrt[a+b*x]*Sqrt[c+d*x]/(c*x) +
  Dist[(b*c-a*d)/(2*c),Int[1/(x*Sqrt[a+b*x]*Sqrt[c+d*x]),x]] /;
FreeQ[{a,b,c,d},x]


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Rule: If  m\[Element]\[DoubleStruckCapitalZ] \[And] m<-2, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral](x^m Sqrt[a+b x])/Sqrt[c+d x] \[DifferentialD]x  \[LongRightArrow]  ((x^(m+1) Sqrt[a+b x] Sqrt[c+d x])/(c (m+1)))-                                                                                        *)
(*                      (b c+a d (2 m+3))/(2 c (m+1)) \[Integral]x^(m+1)/(Sqrt[a+b x] Sqrt[c+d x]) \[DifferentialD]x-(b d (m+2))/(c (m+1)) \[Integral]x^(m+2)/(Sqrt[a+b x] Sqrt[c+d x]) \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[x_^m_.*Sqrt[a_+b_.*x_]/Sqrt[c_.+d_.*x_],x_Symbol] :=
  x^(m+1)*Sqrt[a+b*x]*Sqrt[c+d*x]/(c*(m+1)) -
  Dist[(b*c+a*d*(2*m+3))/(2*c*(m+1)),Int[x^(m+1)/(Sqrt[a+b*x]*Sqrt[c+d*x]),x]] -
  Dist[b*d*(m+2)/(c*(m+1)),Int[x^(m+2)/(Sqrt[a+b*x]*Sqrt[c+d*x]),x]] /;
FreeQ[{a,b,c,d},x] && IntegerQ[m] && m<-2


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Derivation: Algebraic expansion*)


(* ::Subsubsection:: *)
(*Basis: x^m (a+b x)^n=(x^(m-1) (a+b x)^(n+1))/b-(a x^(m-1) (a+b x)^n)/b*)


(* ::Subsubsection:: *)
(*Basis: If  m>=0 is an integer, then  x^m=\!\( *)
(*\*UnderoverscriptBox[\(\[Sum]\), \(k = 0\), \(m\)]\( *)
(*\*FractionBox[\( *)
(*\*SuperscriptBox[\((\(-a\))\), \(m - k\)]\ Binomial[m, m - k]\), *)
(*SuperscriptBox[\(b\), \(m\)]] *)
(*\*SuperscriptBox[\((a + b\ x)\), \(k\)]\)\)*)


(* ::Subsubsection:: *)
(*Rule: If  m,p-n\[Element]\[DoubleStruckCapitalZ] \[And] m>0 \[And] p-n<0 \[And] (m>3 \[Or] n!=-(1/2)), then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]x^m (a+b x)^n (c+d x)^p \[DifferentialD]x  \[LongRightArrow]  \!\( *)
(*\*UnderoverscriptBox[\(\[Sum]\), \(k = 0\), \(m\)]\( *)
(*\*FractionBox[\( *)
(*\*SuperscriptBox[\((\(-a\))\), \(m - k\)]\ Binomial[m, m - k]\), *)
(*SuperscriptBox[\(b\), \(m\)]] \(\[Integral]*)
(*\*SuperscriptBox[\((a + b\ x)\), \(n + k\)]\ *)
(*\*SuperscriptBox[\((c + d\ x)\), \(p\)] \[DifferentialD]x\)\)\)*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[x_^m_.*(a_+b_.*x_)^n_*(c_.+d_.*x_)^p_.,x_Symbol] :=
  Sum[Dist[(-a)^(m-k)/b^m*Binomial[m,m-k],Int[(a+b*x)^(n+k)*(c+d*x)^p,x]],{k,0,m}] /;
FreeQ[{a,b,c,d,n,p},x] && IntegersQ[m,p-n] && m>0 && Not[IntegerQ[n]] && p-n<0 &&
(m>3 || n=!=-1/2)


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Derivation: Algebraic expansion*)


(* ::Subsubsection:: *)
(*Basis: x^m (a+b x)^n=(x^(m-1) (a+b x)^(n+1))/b-(a x^(m-1) (a+b x)^n)/b*)


(* ::Subsubsection:: *)
(*Basis: If  m and p-n are integers and 0<p-n<=m, then*)
(*	x^m (a+b x)^n=\!\( *)
(*\*UnderoverscriptBox[\(\[Sum]\), \(k = 0\), \(p - n - 1\)]\( *)
(*\*FractionBox[\( *)
(*\*SuperscriptBox[\((\(-a\))\), \(m - k\)]\ Binomial[m, m - k]\), *)
(*SuperscriptBox[\(b\), \(m\)]] *)
(*\*SuperscriptBox[\((a + b\ x)\), \(n + k\)]\)\)+\!\( *)
(*\*UnderoverscriptBox[\(\[Sum]\), \(k = 0\), \(m - p + n\)]\( *)
(*\*FractionBox[\( *)
(*\*SuperscriptBox[\((\(-*)
(*\*FractionBox[\(a\), \(b\)]\))\), \(m - k\)]\ Binomial[m - k - 1, p - n - 1]\), *)
(*SuperscriptBox[\((\(-a\))\), \(p - n\)]]\ *)
(*\*SuperscriptBox[\(x\), \(k\)]\ *)
(*\*SuperscriptBox[\((a + b\ x)\), \(p\)]\)\)*)


(* ::Subsubsection:: *)
(*Rule: If  m,p-n\[Element]\[DoubleStruckCapitalZ] \[And] 0<p-n<=m, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]x^m (a+b x)^n (c+d x)^p \[DifferentialD]x  \[LongRightArrow]  \!\( *)
(*\*UnderoverscriptBox[\(\[Sum]\), \(k = 0\), \(p - n - 1\)]\( *)
(*\*FractionBox[\( *)
(*\*SuperscriptBox[\((\(-a\))\), \(m - k\)]\ Binomial[m, m - k]\), *)
(*SuperscriptBox[\(b\), \(m\)]] \(\[Integral]*)
(*\*SuperscriptBox[\((a + b\ x)\), \(n + k\)]\ *)
(*\*SuperscriptBox[\((c + d\ x)\), \(p\)] \[DifferentialD]x\)\)\)+                 *)
(*                                                              \!\( *)
(*\*UnderoverscriptBox[\(\[Sum]\), \(k = 0\), \(m - p + n\)]\( *)
(*\*FractionBox[\( *)
(*\*SuperscriptBox[\((\(-*)
(*\*FractionBox[\(a\), \(b\)]\))\), \(m - k\)]\ Binomial[m - k - 1, p - n - 1]\), *)
(*SuperscriptBox[\((\(-a\))\), \(p - n\)]] \(\[Integral]*)
(*\*SuperscriptBox[\(x\), \(k\)]\ *)
(*\*SuperscriptBox[\((a + b\ x)\), \(p\)]\ *)
(*\*SuperscriptBox[\((c + d\ x)\), \(p\)] \[DifferentialD]x\)\)\)*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[x_^m_.*(a_+b_.*x_)^n_*(c_.+d_.*x_)^p_,x_Symbol] :=
  Sum[Dist[(-a)^(m-k)/b^m*Binomial[m,m-k],Int[(a+b*x)^(n+k)*(c+d*x)^p,x]],{k,0,p-n-1}] + 
  Sum[Dist[(-a/b)^(m-k)/(-a)^(p-n)*Binomial[m-k-1,p-n-1],Int[x^k*(a+b*x)^p*(c+d*x)^p,x]],{k,0,m-p+n}] /;
FreeQ[{a,b,c,d,n,p},x] && IntegersQ[m,p-n] && 0<p-n<=m && Not[IntegerQ[n]]


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Derivation: Algebraic expansion*)


(* ::Subsubsection:: *)
(*Basis: x^m (a+b x)^n=(x^m (a+b x)^(n+1))/a-(b x^(m+1) (a+b x)^n)/a*)


(* ::Subsubsection:: *)
(*Basis: If  m and p-n are integers, m<0 and p-n>0, then*)
(*	x^m (a+b x)^n=\!\( *)
(*\*UnderoverscriptBox[\(\[Sum]\), \(k = 0\), \(p - n - 1\)]\( *)
(*\*FractionBox[\( *)
(*\*SuperscriptBox[\(a\), \(m - k\)]\(\ \)\(Binomial[k - m - 1, \(-m\) - 1]\)\(\ \)\), *)
(*SuperscriptBox[\((\(-b\))\), \(m\)]] *)
(*\*SuperscriptBox[\((a + b\ x)\), \(n + k\)]\)\)+\!\( *)
(*\*UnderoverscriptBox[\(\[Sum]\), \(k = 0\), \(\(-m\) - 1\)]\( *)
(*\*FractionBox[\( *)
(*\*SuperscriptBox[\((\(-*)
(*\*FractionBox[\(b\), \(a\)]\))\), \(k\)]\ Binomial[p - n + k - 1, p - n - 1]\), *)
(*SuperscriptBox[\(a\), \(p - n\)]] *)
(*\*SuperscriptBox[\(x\), \(m + k\)] *)
(*\*SuperscriptBox[\((a + b\ x)\), \(p\)]\)\)*)


(* ::Subsubsection:: *)
(*Rule: If  m,p-n\[Element]\[DoubleStruckCapitalZ] \[And] m<0 \[And] p-n>0, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]x^m (a+b x)^n (c+d x)^p \[DifferentialD]x  \[LongRightArrow]  \!\( *)
(*\*UnderoverscriptBox[\(\[Sum]\), \(k = 0\), \(p - n - 1\)]\( *)
(*\*FractionBox[\( *)
(*\*SuperscriptBox[\(a\), \(m - k\)]\ Binomial[k - m - 1, \(-m\) - 1]\), *)
(*SuperscriptBox[\((\(-b\))\), \(m\)]] \(\[Integral]*)
(*\*SuperscriptBox[\((a + b\ x)\), \(n + k\)]\ *)
(*\*SuperscriptBox[\((c + d\ x)\), \(p\)] \[DifferentialD]x\)\)\)+         *)
(*                                                                    \!\( *)
(*\*UnderoverscriptBox[\(\[Sum]\), \(k = 0\), \(\(-m\) - 1\)]\( *)
(*\*FractionBox[\( *)
(*\*SuperscriptBox[\((\(-*)
(*\*FractionBox[\(b\), \(a\)]\))\), \(k\)]\ Binomial[p - n + k - 1, p - n - 1]\), *)
(*SuperscriptBox[\(a\), \(p - n\)]] \(\[Integral]*)
(*\*SuperscriptBox[\(x\), \(m + k\)]\ *)
(*\*SuperscriptBox[\((a + b\ x)\), \(p\)]\ *)
(*\*SuperscriptBox[\((c + d\ x)\), \(p\)] \[DifferentialD]x\)\)\)*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[x_^m_.*(a_+b_.*x_)^n_*(c_.+d_.*x_)^p_,x_Symbol] :=
  Sum[Dist[a^(m-k)/(-b)^m*Binomial[k-m-1,-m-1],Int[(a+b*x)^(n+k)*(c+d*x)^p,x]],{k,0,p-n-1}] + 
  Sum[Dist[(-b/a)^k/a^(p-n)*Binomial[p-n+k-1,p-n-1],Int[x^(m+k)*(a+b*x)^p*(c+d*x)^p,x]],{k,0,-m-1}] /;
FreeQ[{a,b,c,d,n,p},x] && IntegersQ[m,p-n] && m<0 && p-n>0 && Not[IntegerQ[n]]


(* ::PageBreak:: *)
(**)
