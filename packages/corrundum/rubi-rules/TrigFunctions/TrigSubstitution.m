(* ::Package:: *)

(* ::Title::Bold::Closed:: *)
(*\[Integral]u (c F[a+b x]^n)^m \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Derivation: Piecewise constant extraction*)


(* ::Subsubsection:: *)
(*Basis: \!\( *)
(*\*SubscriptBox[\(\[PartialD]\), \(z\)]*)
(*\*FractionBox[*)
(*SqrtBox[\(c\ *)
(*\*SuperscriptBox[\(F[z]\), \(n\)]\)], *)
(*SuperscriptBox[\(F[z]\), \(n/2\)]]\)=0*)


(* ::Subsubsection:: *)
(*Rule: If  n/2,m-1/2\[Element]\[DoubleStruckCapitalZ] \[And] m>0, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]u (c F[a+b x]^n)^m \[DifferentialD]x  \[LongRightArrow]  c^(m-1/2) Sqrt[c F[a+b x]^n]/F[a+b x]^(n/2) \[Integral]u F[a+b x]^(m n) \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[u_.*(c_.*F_[a_.+b_.*x_]^n_)^m_,x_Symbol] :=
  Dist[c^(m-1/2)*Sqrt[c*F[a+b*x]^n]/F[a+b*x]^(n/2),Int[u*F[a+b*x]^(m*n),x]] /;
FreeQ[{a,b,c},x] && IntegerQ[n/2] && IntegerQ[m-1/2] && m>0 && 
  MemberQ[{Sin,Cos,Tan,Cot,Sinh,Cosh,Tanh,Coth},F]


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Derivation: Piecewise constant extraction*)


(* ::Subsubsection:: *)
(*Basis: \!\( *)
(*\*SubscriptBox[\(\[PartialD]\), \(z\)]*)
(*\*FractionBox[*)
(*SuperscriptBox[\(F[z]\), \(n/2\)], *)
(*SqrtBox[\(c\ *)
(*\*SuperscriptBox[\(F[z]\), \(n\)]\)]]\)=0*)


(* ::Subsubsection:: *)
(*Rule: If  n/2,m-1/2\[Element]\[DoubleStruckCapitalZ] \[And] m<0, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]u (c F[a+b x]^n)^m \[DifferentialD]x  \[LongRightArrow]  c^(m+1/2) F[a+b x]^(n/2)/Sqrt[c F[a+b x]^n] \[Integral]u F[a+b x]^(m n) \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[u_.*(c_.*F_[a_.+b_.*x_]^n_)^m_,x_Symbol] :=
  Dist[c^(m+1/2)*F[a+b*x]^(n/2)/Sqrt[c*F[a+b*x]^n],Int[u*F[a+b*x]^(m*n),x]] /;
FreeQ[{a,b,c},x] && IntegerQ[n/2] && IntegerQ[m-1/2] && m<0 && 
  MemberQ[{Sin,Cos,Tan,Cot,Sinh,Cosh,Tanh,Coth},F]


(* ::PageBreak:: *)
(**)


(* ::Title::Bold::Closed:: *)
(*\[Integral]f[Sin[u]]\!\( *)
(*\*SubscriptBox[\(\[PartialD]\), \(x\)]\(Sin[u]\)\)\[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Derivation: Integration by substitution*)


(* ::Subsubsection:: *)
(*Basis: f[Sin[z]] Cos[z]=f[Sin[z]] \!\( *)
(*\*SubscriptBox[\(\[PartialD]\), \(z\)]\(Sin[z]\)\)*)


(* ::Subsubsection:: *)
(*Rule:*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]f[Sin[a+b x]]Cos[a+b x]\[DifferentialD]x  \[LongRightArrow]  (1/b)Subst[\[Integral]f[x]\[DifferentialD]x,x,Sin[a+b x]]*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[u_*Cos[c_.*(a_.+b_.*x_)],x_Symbol] :=
  Dist[1/(b*c),Subst[Int[Regularize[SubstFor[Sin[c*(a+b*x)],u,x],x],x],x,Sin[c*(a+b*x)]]] /;
FreeQ[{a,b,c},x] && FunctionOfQ[Sin[c*(a+b*x)],u,x,True]


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Derivation: Integration by substitution*)


(* ::Subsubsection:: *)
(*Basis: f[Sin[z]] Cot[z]=f[Sin[z]]/Sin[z] \!\( *)
(*\*SubscriptBox[\(\[PartialD]\), \(z\)]\(Sin[z]\)\)*)


(* ::Subsubsection:: *)
(*Rule:*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]f[Sin[a+b x]]Cot[a+b x]\[DifferentialD]x  \[LongRightArrow]  (1/b)Subst[\[Integral]f[x]/x \[DifferentialD]x,x,Sin[a+b x]]*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[u_*Cot[c_.*(a_.+b_.*x_)],x_Symbol] :=
  Dist[1/(b*c),Subst[Int[Regularize[SubstFor[Sin[c*(a+b*x)],u,x]/x,x],x],x,Sin[c*(a+b*x)]]] /;
FreeQ[{a,b,c},x] && FunctionOfQ[Sin[c*(a+b*x)],u,x,True]


(* ::PageBreak:: *)
(**)


(* ::Title::Bold::Closed:: *)
(*\[Integral]f[Cos[u]]\!\( *)
(*\*SubscriptBox[\(\[PartialD]\), \(x\)]\(Cos[u]\)\)\[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Derivation: Integration by substitution*)


(* ::Subsubsection:: *)
(*Basis: f[Cos[z]] Sin[z]=-f[Cos[z]] \!\( *)
(*\*SubscriptBox[\(\[PartialD]\), \(z\)]\(Cos[z]\)\)*)


(* ::Subsubsection:: *)
(*Rule:*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]f[Cos[a+b x]]Sin[a+b x]\[DifferentialD]x  \[LongRightArrow]  -(1/b)Subst[\[Integral]f[x]\[DifferentialD]x,x,Cos[a+b x]]*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[u_*Sin[c_.*(a_.+b_.*x_)],x_Symbol] :=
  -Dist[1/(b*c),Subst[Int[Regularize[SubstFor[Cos[c*(a+b*x)],u,x],x],x],x,Cos[c*(a+b*x)]]] /;
FreeQ[{a,b,c},x] && FunctionOfQ[Cos[c*(a+b*x)],u,x,True]


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Derivation: Integration by substitution*)


(* ::Subsubsection:: *)
(*Basis: f[Cos[z]] Tan[z]=-(f[Cos[z]]/Cos[z]) \!\( *)
(*\*SubscriptBox[\(\[PartialD]\), \(z\)]\(Cos[z]\)\)*)


(* ::Subsubsection:: *)
(*Rule:*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]f[Cos[a+b x]]Tan[a+b x]\[DifferentialD]x  \[LongRightArrow]  -(1/b)Subst[\[Integral]f[x]/x \[DifferentialD]x,x,Cos[a+b x]]*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[u_*Tan[c_.*(a_.+b_.*x_)],x_Symbol] :=
  -Dist[1/(b*c),Subst[Int[Regularize[SubstFor[Cos[c*(a+b*x)],u,x]/x,x],x],x,Cos[c*(a+b*x)]]] /;
FreeQ[{a,b,c},x] && FunctionOfQ[Cos[c*(a+b*x)],u,x,True]


(* ::PageBreak:: *)
(**)


(* ::Title::Bold::Closed:: *)
(*\[Integral]f[Cot[u]]\!\( *)
(*\*SubscriptBox[\(\[PartialD]\), \(x\)]\(Cot[u]\)\)\[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Derivation: Integration by substitution*)


(* ::Subsubsection:: *)
(*Basis: f[Cot[z]] Csc[z]^2=-f[Cot[z]] \!\( *)
(*\*SubscriptBox[\(\[PartialD]\), \(z\)]\(Cot[z]\)\)*)


(* ::Subsubsection:: *)
(*Rule:*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]f[Cot[a+b x]]Csc[a+b x]^2 \[DifferentialD]x  \[LongRightArrow]  -(1/b)Subst[\[Integral]f[x]\[DifferentialD]x,x,Cot[a+b x]]*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[u_*Csc[c_.*(a_.+b_.*x_)]^2,x_Symbol] :=
  -Dist[1/(b*c),Subst[Int[Regularize[SubstFor[Cot[c*(a+b*x)],u,x],x],x],x,Cot[c*(a+b*x)]]] /;
FreeQ[{a,b,c},x] && FunctionOfQ[Cot[c*(a+b*x)],u,x,True] && NonsumQ[u]


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Derivation: Integration by substitution*)


(* ::Subsubsection:: *)
(*Basis: If  n\[Element]\[DoubleStruckCapitalZ], then f[Cot[z]] Tan[z]^n=-(f[Cot[z]]/(Cot[z]^n (1+Cot[z]^2)))\!\( *)
(*\*SubscriptBox[\(\[PartialD]\), \(z\)]\(Cot[z]\)\)*)


(* ::Subsubsection:: *)
(*Rule: If  n\[Element]\[DoubleStruckCapitalZ], then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]f[Cot[a+b x]]Tan[a+b x]^n \[DifferentialD]x  \[LongRightArrow]  -(1/b)Subst[\[Integral]f[x]/(x^n (1+x^2)) \[DifferentialD]x,x,Cot[a+b x]]*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[u_*Tan[c_.*(a_.+b_.*x_)]^n_.,x_Symbol] :=
  -Dist[1/(b*c),Subst[Int[Regularize[SubstFor[Cot[c*(a+b*x)],u,x]/(x^n*(1+x^2)),x],x],x,Cot[c*(a+b*x)]]] /;
FreeQ[{a,b,c},x] && IntegerQ[n] && FunctionOfQ[Cot[c*(a+b*x)],u,x,True] && TryPureTanSubst[u*Tan[c*(a+b*x)]^n,x]


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Derivation: Integration by substitution*)


(* ::Subsubsection:: *)
(*Basis: f[Cot[z]]=-(f[Cot[z]]/(1+Cot[z]^2))\!\( *)
(*\*SubscriptBox[\(\[PartialD]\), \(z\)]\(Cot[z]\)\)*)


(* ::Subsubsection:: *)
(*Rule:*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]f[Cot[a+b x]]\[DifferentialD]x  \[LongRightArrow]  -(1/b)Subst[\[Integral]f[x]/(1+x^2) \[DifferentialD]x,x,Cot[a+b x]]*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
If[ShowSteps,

Int[u_,x_Symbol] :=
  Module[{v=FunctionOfTrig[u,x]},
  ShowStep["","Int[f[Cot[a+b*x]],x]","Subst[Int[f[x]/(1+x^2),x],x,Cot[a+b*x]]/b",Hold[
  Dist[-1/Coefficient[v,x,1],Subst[Int[Regularize[SubstFor[Cot[v],u,x]/(1+x^2),x],x],x,Cot[v]]]]] /;
 NotFalseQ[v] && FunctionOfQ[Cot[v],u,x,True] && TryPureTanSubst[u,x]] /;
SimplifyFlag,

Int[u_,x_Symbol] :=
  Module[{v=FunctionOfTrig[u,x]},
  Dist[-1/Coefficient[v,x,1],Subst[Int[Regularize[SubstFor[Cot[v],u,x]/(1+x^2),x],x],x,Cot[v]]] /;
 NotFalseQ[v] && FunctionOfQ[Cot[v],u,x,True] && TryPureTanSubst[u,x]]]


(* ::PageBreak:: *)
(**)


(* ::Title::Bold::Closed:: *)
(*\[Integral]f[Tan[u]]\!\( *)
(*\*SubscriptBox[\(\[PartialD]\), \(x\)]\(Tan[u]\)\)\[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Derivation: Integration by substitution*)


(* ::Subsubsection:: *)
(*Basis: f[Tan[z]] Sec[z]^2=f[Tan[z]] \!\( *)
(*\*SubscriptBox[\(\[PartialD]\), \(z\)]\(Tan[z]\)\)*)


(* ::Subsubsection:: *)
(*Rule:*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]f[Tan[a+b x]]Sec[a+b x]^2 \[DifferentialD]x  \[LongRightArrow]  (1/b)Subst[\[Integral]f[x]\[DifferentialD]x,x,Tan[a+b x]]*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[u_*Sec[c_.*(a_.+b_.*x_)]^2,x_Symbol] :=
  Dist[1/(b*c),Subst[Int[Regularize[SubstFor[Tan[c*(a+b*x)],u,x],x],x],x,Tan[c*(a+b*x)]]] /;
FreeQ[{a,b,c},x] && FunctionOfQ[Tan[c*(a+b*x)],u,x,True] && NonsumQ[u]


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Derivation: Integration by substitution*)


(* ::Subsubsection:: *)
(*Basis: If  n\[Element]\[DoubleStruckCapitalZ], then f[Tan[z]] Cot[z]^n=f[Tan[z]]/(Tan[z]^n (1+Tan[z]^2)) \!\( *)
(*\*SubscriptBox[\(\[PartialD]\), \(z\)]\(Tan[z]\)\)*)


(* ::Subsubsection:: *)
(*Rule: If  n\[Element]\[DoubleStruckCapitalZ], then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]f[Tan[a+b x]]Cot[a+b x]^n \[DifferentialD]x  \[LongRightArrow]  (1/b)Subst[\[Integral]f[x]/(x^n (1+x^2)) \[DifferentialD]x,x,Tan[a+b x]]*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[u_*Cot[c_.*(a_.+b_.*x_)]^n_.,x_Symbol] :=
  Dist[1/(b*c),Subst[Int[Regularize[SubstFor[Tan[c*(a+b*x)],u,x]/(x^n*(1+x^2)),x],x],x,Tan[c*(a+b*x)]]] /;
FreeQ[{a,b,c},x] && IntegerQ[n] && FunctionOfQ[Tan[c*(a+b*x)],u,x,True] && TryPureTanSubst[u*Cot[c*(a+b*x)]^n,x]


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Derivation: Integration by substitution*)


(* ::Subsubsection:: *)
(*Basis: f[Tan[z]]=f[Tan[z]]/(1+Tan[z]^2) \!\( *)
(*\*SubscriptBox[\(\[PartialD]\), \(z\)]\(Tan[z]\)\)*)


(* ::Subsubsection:: *)
(*Rule:*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]f[Tan[a+b x]]\[DifferentialD]x  \[LongRightArrow]  (1/b)Subst[\[Integral]f[x]/(1+x^2) \[DifferentialD]x,x,Tan[a+b x]]*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
If[ShowSteps,

Int[u_,x_Symbol] :=
  Module[{v=FunctionOfTrig[u,x]},
  ShowStep["","Int[f[Tan[a+b*x]],x]","Subst[Int[f[x]/(1+x^2),x],x,Tan[a+b*x]]/b",Hold[
  Dist[1/Coefficient[v,x,1],Subst[Int[Regularize[SubstFor[Tan[v],u,x]/(1+x^2),x],x],x,Tan[v]]]]] /;
 NotFalseQ[v] && FunctionOfQ[Tan[v],u,x,True] && TryPureTanSubst[u,x]] /;
SimplifyFlag,

Int[u_,x_Symbol] :=
  Module[{v=FunctionOfTrig[u,x]},
  Dist[1/Coefficient[v,x,1],Subst[Int[Regularize[SubstFor[Tan[v],u,x]/(1+x^2),x],x],x,Tan[v]]] /;
 NotFalseQ[v] && FunctionOfQ[Tan[v],u,x,True] && TryPureTanSubst[u,x]]]


(* ::PageBreak:: *)
(**)


(* ::Title::Bold::Closed:: *)
(*\[Integral]u (a+b Sin[c+d x])^n \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Note: This rule should be moved just before the tangent \[Theta]/2 substitution rules for linear trigonometric expressions*)


(* ::Subsubsection:: *)
(*Derivation: Piecewise constant extraction and algebraic expansion*)


(* ::Subsubsection:: *)
(*Basis: If  a^2-b^2=0, then \!\( *)
(*\*SubscriptBox[\(\[PartialD]\), \(z\)]*)
(*\*FractionBox[*)
(*SqrtBox[\(a + b\ Sin[z]\)], \(Cos[*)
(*\*FractionBox[\(z\), \(2\)]] + *)
(*\*FractionBox[\(a\), \(b\)] Sin[*)
(*\*FractionBox[\(z\), \(2\)]]\)]\)=0*)


(* ::Subsubsection:: *)
(*Rule: If  a^2-b^2=0 \[And] n-1/2\[Element]\[DoubleStruckCapitalZ], then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]u (a+b Sin[c+d x])^n \[DifferentialD]x  \[LongRightArrow]                                                                                               *)
(*(Sqrt[a+b Sin[c+d x]]/(Cos[(c+d x)/2]+a/b Sin[(c+d x)/2]))(\[Integral]u Cos[(c+d x)/2](a+b Sin[c+d x])^(n-1/2) \[DifferentialD]x+a/b \[Integral]u Sin[(c+d x)/2](a+b Sin[c+d x])^(n-1/2) \[DifferentialD]x)*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
(* Int[u_*(a_+b_.*Sin[c_.+d_.*x_])^n_,x_Symbol] :=
  Sqrt[a+b*Sin[c+d*x]]/(Cos[c/2+d*x/2]+a/b*Sin[c/2+d*x/2])*
    (Int[u*Cos[c/2+d*x/2]*(a+b*Sin[c+d*x])^(n-1/2),x] +
     a/b*Int[u*Sin[c/2+d*x/2]*(a+b*Sin[c+d*x])^(n-1/2),x]) /;
FreeQ[{a,b,c,d},x] && ZeroQ[a^2-b^2] && IntegerQ[n-1/2] *)


(* ::PageBreak:: *)
(**)


(* ::Title::Bold::Closed:: *)
(*\[Integral]u (a+b Cos[c+d x])^n \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Note: These rules should be moved just before the tangent \[Theta]/2 substitution rules for linear trigonometric expressions*)


(* ::Subsubsection:: *)
(*Derivation: Piecewise constant extraction*)


(* ::Subsubsection:: *)
(*Basis: \!\( *)
(*\*SubscriptBox[\(\[PartialD]\), \(z\)]*)
(*\*FractionBox[*)
(*SqrtBox[\(a + a\ Cos[z]\)], \(Cos[*)
(*\*FractionBox[\(z\), \(2\)]]\)]\)=0*)


(* ::Subsubsection:: *)
(*Rule: If  n-1/2\[Element]\[DoubleStruckCapitalZ], then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]u (a+a Cos[c+d x])^n \[DifferentialD]x  \[LongRightArrow]  (Sqrt[a+a Cos[c+d x]]/Cos[(c+d x)/2])\[Integral]u Cos[(c+d x)/2](a+a Cos[c+d x])^(n-1/2) \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
(* Int[u_*(a_+b_.*Cos[c_.+d_.*x_])^n_,x_Symbol] :=
  Sqrt[a+b*Cos[c+d*x]]/Cos[c/2+d*x/2]*Int[u*Cos[c/2+d*x/2]*(a+b*Cos[c+d*x])^(n-1/2),x] /;
FreeQ[{a,b,c,d},x] && ZeroQ[a-b] && IntegerQ[n-1/2] *)


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Derivation: Piecewise constant extraction*)


(* ::Subsubsection:: *)
(*Basis: \!\( *)
(*\*SubscriptBox[\(\[PartialD]\), \(z\)]*)
(*\*FractionBox[*)
(*SqrtBox[\(a - a\ Cos[z]\)], \(Sin[*)
(*\*FractionBox[\(z\), \(2\)]]\)]\)=0*)


(* ::Subsubsection:: *)
(*Rule: If  n-1/2\[Element]\[DoubleStruckCapitalZ], then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]u (a-a Cos[c+d x])^n \[DifferentialD]x  \[LongRightArrow]  (Sqrt[a-a Cos[c+d x]]/Sin[(c+d x)/2])\[Integral]u Sin[(c+d x)/2](a-a Cos[c+d x])^(n-1/2) \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
(* Int[u_*(a_+b_.*Cos[c_.+d_.*x_])^n_,x_Symbol] :=
  Sqrt[a+b*Cos[c+d*x]]/Sin[c/2+d*x/2]*Int[u*Sin[c/2+d*x/2]*(a+b*Cos[c+d*x])^(n-1/2),x] /;
FreeQ[{a,b,c,d},x] && ZeroQ[a+b] && IntegerQ[n-1/2] *)


(* ::PageBreak:: *)
(**)


(* ::Title::Bold::Closed:: *)
(*\[Integral]u (a+b Cos[d+e x]+c Sin[d+e x])^n \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Note: This rule should be moved just before the tangent \[Theta]/2 substitution rules for linear trigonometric expressions*)


(* ::Subsubsection:: *)
(*Derivation: Piecewise constant extraction and algebraic expansion*)


(* ::Subsubsection:: *)
(*Basis: If  a^2-b^2-c^2=0, then \!\( *)
(*\*SubscriptBox[\(\[PartialD]\), \(z\)]*)
(*\*FractionBox[*)
(*SqrtBox[\(a + b\ Cos[z] + c\ Sin[z]\)], \(c\ Cos[*)
(*\*FractionBox[\(z\), \(2\)]] + \((a - b)\)\ Sin[*)
(*\*FractionBox[\(z\), \(2\)]]\)]\)=0*)


(* ::Subsubsection:: *)
(*Rule: If  a^2-b^2-c^2=0 \[And] n-1/2\[Element]\[DoubleStruckCapitalZ], then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]u (a+b Cos[d+e x]+c Sin[d+e x])^n \[DifferentialD]x  \[LongRightArrow]                                                                                                                             *)
(*((c Sqrt[a+b Cos[d+e x]+c Sin[d+e x]])/(c Cos[(d+e x)/2]+(a-b)Sin[(d+e x)/2]))\[Integral]u Cos[(d+e x)/2](a+b Cos[d+e x]+c Sin[d+e x])^(n-1/2) \[DifferentialD]x+*)
(*     ((a-b)Sqrt[a+b Cos[d+e x]+c Sin[d+e x]])/(c Cos[(d+e x)/2]+(a-b)Sin[(d+e x)/2]) \[Integral]u Sin[(d+e x)/2](a+b Cos[d+e x]+c Sin[d+e x])^(n-1/2) \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
(* Int[u_*(a_+b_.*Cos[d_.+e_.*x_]+c_.*Sin[d_.+e_.*x_])^n_,x_Symbol] :=
  Sqrt[a+b*Cos[d+e*x]+c*Sin[d+e*x]]/(c*Cos[(d+e*x)/2]+(a-b)*Sin[(d+e*x)/2])*
    Dist[c,Int[u*Cos[(d+e*x)/2]*(a+b*Cos[d+e*x]+c*Sin[d+e*x])^(n-1/2),x]] + 
  Sqrt[a+b*Cos[d+e*x]+c*Sin[d+e*x]]/(c*Cos[(d+e*x)/2]+(a-b)*Sin[(d+e*x)/2])*
    Dist[a-b,Int[u*Sin[(d+e*x)/2]*(a+b*Cos[d+e*x]+c*Sin[d+e*x])^(n-1/2),x]] /;
FreeQ[{a,b,c,d,e},x] && ZeroQ[a^2-b^2-c^2] && IntegerQ[n-1/2] *)


(* ::PageBreak:: *)
(**)
