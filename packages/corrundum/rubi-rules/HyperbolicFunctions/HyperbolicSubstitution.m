(* ::Package:: *)

(* ::Title::Bold::Closed:: *)
(*\[Integral]f[Sinh[u]]\!\( *)
(*\*SubscriptBox[\(\[PartialD]\), \(x\)]\(Sinh[u]\)\)\[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Derivation: Integration by substitution*)


(* ::Subsubsection:: *)
(*Basis: f[Sinh[z]] Cosh[z]=f[Sinh[z]] \!\( *)
(*\*SubscriptBox[\(\[PartialD]\), \(z\)]\(Sinh[z]\)\)*)


(* ::Subsubsection:: *)
(*Rule:*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]f[Sinh[a+b x]]Cosh[a+b x]\[DifferentialD]x  \[LongRightArrow]  (1/b)Subst[\[Integral]f[x]\[DifferentialD]x,x,Sinh[a+b x]]*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[u_*Cosh[c_.*(a_.+b_.*x_)],x_Symbol] :=
  Dist[1/(b*c),Subst[Int[Regularize[SubstFor[Sinh[c*(a+b*x)],u,x],x],x],x,Sinh[c*(a+b*x)]]] /;
FreeQ[{a,b,c},x] && FunctionOfQ[Sinh[c*(a+b*x)],u,x,True]


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Derivation: Integration by substitution*)


(* ::Subsubsection:: *)
(*Basis: f[Sinh[z]] Coth[z]=f[Sinh[z]]/Sinh[z] \!\( *)
(*\*SubscriptBox[\(\[PartialD]\), \(z\)]\(Sinh[z]\)\)*)


(* ::Subsubsection:: *)
(*Rule:*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]f[Sinh[a+b x]]Coth[a+b x]\[DifferentialD]x  \[LongRightArrow]  (1/b)Subst[\[Integral]f[x]/x \[DifferentialD]x,x,Sinh[a+b x]]*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[u_*Coth[c_.*(a_.+b_.*x_)],x_Symbol] :=
  Dist[1/(b*c),Subst[Int[Regularize[SubstFor[Sinh[c*(a+b*x)],u,x]/x,x],x],x,Sinh[c*(a+b*x)]]] /;
FreeQ[{a,b,c},x] && FunctionOfQ[Sinh[c*(a+b*x)],u,x,True]


(* ::PageBreak:: *)
(**)


(* ::Title::Bold::Closed:: *)
(*\[Integral]f[Cosh[u]]\!\( *)
(*\*SubscriptBox[\(\[PartialD]\), \(x\)]\(Cosh[u]\)\)\[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Derivation: Integration by substitution*)


(* ::Subsubsection:: *)
(*Basis: f[Cosh[z]] Sinh[z]=f[Cosh[z]] \!\( *)
(*\*SubscriptBox[\(\[PartialD]\), \(z\)]\(Cosh[z]\)\)*)


(* ::Subsubsection:: *)
(*Rule:*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]f[Cosh[a+b x]]Sinh[a+b x]\[DifferentialD]x  \[LongRightArrow]  (1/b)Subst[\[Integral]f[x]\[DifferentialD]x,x,Cosh[a+b x]]*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[u_*Sinh[c_.*(a_.+b_.*x_)],x_Symbol] :=
  Dist[1/(b*c),Subst[Int[Regularize[SubstFor[Cosh[c*(a+b*x)],u,x],x],x],x,Cosh[c*(a+b*x)]]] /;
FreeQ[{a,b,c},x] && FunctionOfQ[Cosh[c*(a+b*x)],u,x,True]


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Derivation: Integration by substitution*)


(* ::Subsubsection:: *)
(*Basis: f[Cosh[z]] Tanh[z]=f[Cosh[z]]/Cosh[z] \!\( *)
(*\*SubscriptBox[\(\[PartialD]\), \(z\)]\(Cosh[z]\)\)*)


(* ::Subsubsection:: *)
(*Rule:*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]f[Cosh[a+b x]]Tanh[a+b x]\[DifferentialD]x  \[LongRightArrow]  (1/b)Subst[\[Integral]f[x]/x \[DifferentialD]x,x,Cosh[a+b x]]*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[u_*Tanh[c_.*(a_.+b_.*x_)],x_Symbol] :=
  Dist[1/(b*c),Subst[Int[Regularize[SubstFor[Cosh[c*(a+b*x)],u,x]/x,x],x],x,Cosh[c*(a+b*x)]]] /;
FreeQ[{a,b,c},x] && FunctionOfQ[Cosh[c*(a+b*x)],u,x,True]


(* ::PageBreak:: *)
(**)


(* ::Title::Bold::Closed:: *)
(*\[Integral]f[Coth[u]]\!\( *)
(*\*SubscriptBox[\(\[PartialD]\), \(x\)]\(Coth[u]\)\)\[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Derivation: Integration by substitution*)


(* ::Subsubsection:: *)
(*Basis: f[Coth[z]] Csch[z]^2=-f[Coth[z]] \!\( *)
(*\*SubscriptBox[\(\[PartialD]\), \(z\)]\(Coth[z]\)\)*)


(* ::Subsubsection:: *)
(*Rule:*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]f[Coth[a+b x]]Csch[a+b x]^2 \[DifferentialD]x  \[LongRightArrow]  -(1/b)Subst[\[Integral]f[x]\[DifferentialD]x,x,Coth[a+b x]]*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[u_*Csch[c_.*(a_.+b_.*x_)]^2,x_Symbol] :=
  -Dist[1/(b*c),Subst[Int[Regularize[SubstFor[Coth[c*(a+b*x)],u,x],x],x],x,Coth[c*(a+b*x)]]] /;
FreeQ[{a,b,c},x] && FunctionOfQ[Coth[c*(a+b*x)],u,x,True] && NonsumQ[u]


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Derivation: Integration by substitution*)


(* ::Subsubsection:: *)
(*Basis: If  n\[Element]\[DoubleStruckCapitalZ], then f[Coth[z]] Tanh[z]^n=f[Coth[z]]/(Coth[z]^n (1-Coth[z]^2)) \!\( *)
(*\*SubscriptBox[\(\[PartialD]\), \(z\)]\(Coth[z]\)\)*)


(* ::Subsubsection:: *)
(*Rule: If  n\[Element]\[DoubleStruckCapitalZ], then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]f[Coth[a+b x]]Tanh[a+b x]^n \[DifferentialD]x  \[LongRightArrow]  (1/b)Subst[\[Integral]f[x]/(x^n (1-x^2)) \[DifferentialD]x,x,Coth[a+b x]]*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[u_*Tanh[c_.*(a_.+b_.*x_)]^n_.,x_Symbol] :=
  Dist[1/(b*c),Subst[Int[Regularize[SubstFor[Coth[c*(a+b*x)],u,x]/(x^n*(1-x^2)),x],x],x,Coth[c*(a+b*x)]]] /;
FreeQ[{a,b,c},x] && IntegerQ[n] && FunctionOfQ[Coth[c*(a+b*x)],u,x,True] && TryPureTanhSubst[u*Tanh[c*(a+b*x)]^n,x]


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Derivation: Integration by substitution*)


(* ::Subsubsection:: *)
(*Basis: f[Coth[z]]=f[Coth[z]]/(1-Coth[z]^2) \!\( *)
(*\*SubscriptBox[\(\[PartialD]\), \(z\)]\(Coth[z]\)\)*)


(* ::Subsubsection:: *)
(*Rule:*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]f[Coth[a+b x]]\[DifferentialD]x  \[LongRightArrow]  (1/b)Subst[\[Integral]f[x]/(1-x^2) \[DifferentialD]x,x,Coth[a+b x]]*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
If[ShowSteps,

Int[u_,x_Symbol] :=
  Module[{v=FunctionOfHyperbolic[u,x]},
  ShowStep["","Int[f[Coth[a+b*x]],x]","Subst[Int[f[x]/(1-x^2),x],x,Coth[a+b*x]]/b",Hold[
  Dist[1/Coefficient[v,x,1],Subst[Int[Regularize[SubstFor[Coth[v],u,x]/(1-x^2),x],x],x,Coth[v]]]]] /;
 NotFalseQ[v] && FunctionOfQ[Coth[v],u,x,True] && TryPureTanhSubst[u,x]] /;
SimplifyFlag,

Int[u_,x_Symbol] :=
  Module[{v=FunctionOfHyperbolic[u,x]},
  Dist[1/Coefficient[v,x,1],Subst[Int[Regularize[SubstFor[Coth[v],u,x]/(1-x^2),x],x],x,Coth[v]]] /;
 NotFalseQ[v] && FunctionOfQ[Coth[v],u,x,True] && TryPureTanhSubst[u,x]]]


(* ::PageBreak:: *)
(**)


(* ::Title::Bold::Closed:: *)
(*\[Integral]f[Tanh[u]]\!\( *)
(*\*SubscriptBox[\(\[PartialD]\), \(x\)]\(Tanh[u]\)\)\[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Derivation: Integration by substitution*)


(* ::Subsubsection:: *)
(*Basis: f[Tanh[z]] Sech[z]^2=f[Tanh[z]] \!\( *)
(*\*SubscriptBox[\(\[PartialD]\), \(z\)]\(Tanh[z]\)\)*)


(* ::Subsubsection:: *)
(*Rule:*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]f[Tanh[a+b x]]Sech[a+b x]^2 \[DifferentialD]x  \[LongRightArrow]  (1/b)Subst[\[Integral]f[x]\[DifferentialD]x,x,Tanh[a+b x]]*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[u_*Sech[c_.*(a_.+b_.*x_)]^2,x_Symbol] :=
  Dist[1/(b*c),Subst[Int[Regularize[SubstFor[Tanh[c*(a+b*x)],u,x],x],x],x,Tanh[c*(a+b*x)]]] /;
FreeQ[{a,b,c},x] && FunctionOfQ[Tanh[c*(a+b*x)],u,x,True] && NonsumQ[u]


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Derivation: Integration by substitution*)


(* ::Subsubsection:: *)
(*Basis: If  n\[Element]\[DoubleStruckCapitalZ], then f[Tanh[z]] Coth[z]^n=f[Tanh[z]]/(Tanh[z]^n (1-Tanh[z]^2)) \!\( *)
(*\*SubscriptBox[\(\[PartialD]\), \(z\)]\(Tanh[z]\)\)*)


(* ::Subsubsection:: *)
(*Rule: If  n\[Element]\[DoubleStruckCapitalZ], then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]f[Tanh[a+b x]]Coth[a+b x]^n \[DifferentialD]x  \[LongRightArrow]  (1/b)Subst[\[Integral]f[x]/(x^n (1-x^2)) \[DifferentialD]x,x,Tanh[a+b x]]*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[u_*Coth[c_.*(a_.+b_.*x_)]^n_.,x_Symbol] :=
  Dist[1/(b*c),Subst[Int[Regularize[SubstFor[Tanh[c*(a+b*x)],u,x]/(x^n*(1-x^2)),x],x],x,Tanh[c*(a+b*x)]]] /;
FreeQ[{a,b,c},x] && IntegerQ[n] && FunctionOfQ[Tanh[c*(a+b*x)],u,x,True] && TryPureTanhSubst[u*Coth[c*(a+b*x)]^n,x]


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Derivation: Integration by substitution*)


(* ::Subsubsection:: *)
(*Basis: f[Tanh[z]]=f[Tanh[z]]/(1-Tanh[z]^2) \!\( *)
(*\*SubscriptBox[\(\[PartialD]\), \(z\)]\(Tanh[z]\)\)*)


(* ::Subsubsection:: *)
(*Rule:*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]f[Tanh[a+b x]]\[DifferentialD]x  \[LongRightArrow]  (1/b)Subst[\[Integral]f[x]/(1-x^2) \[DifferentialD]x,x,Tanh[a+b x]]*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
If[ShowSteps,

Int[u_,x_Symbol] :=
  Module[{v=FunctionOfHyperbolic[u,x]},
  ShowStep["","Int[f[Tanh[a+b*x]],x]","Subst[Int[f[x]/(1-x^2),x],x,Tanh[a+b*x]]/b",Hold[
  Dist[1/Coefficient[v,x,1],Subst[Int[Regularize[SubstFor[Tanh[v],u,x]/(1-x^2),x],x],x,Tanh[v]]]]] /;
 NotFalseQ[v] && FunctionOfQ[Tanh[v],u,x,True] && TryPureTanhSubst[u,x]] /;
SimplifyFlag,

Int[u_,x_Symbol] :=
  Module[{v=FunctionOfHyperbolic[u,x]},
  Dist[1/Coefficient[v,x,1],Subst[Int[Regularize[SubstFor[Tanh[v],u,x]/(1-x^2),x],x],x,Tanh[v]]] /;
 NotFalseQ[v] && FunctionOfQ[Tanh[v],u,x,True] && TryPureTanhSubst[u,x]]]


(* ::PageBreak:: *)
(**)


(* ::Title::Bold::Closed:: *)
(*\[Integral]TrigSimplify[u]\[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Derivation: Algebraic simplification*)


(* ::Subsubsection:: *)
(*Note: TrigSimplify needs to be tried after trig and hyperbolic rules are tried, but before unrestricted trig and hyperbolic substitutions!*)


(* ::Subsubsection:: *)
(*Rule: If trig simplification simplifes u, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]u \[DifferentialD]x  \[LongRightArrow]  \[Integral]TrigSimplify[u]\[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[u_,x_Symbol] :=
  Module[{v=TrigSimplify[u]},
  Int[v,x] /;
 v=!=u] /;
Not[MatchQ[u,w_.*(a_.+b_.*v_)^m_.*(c_.+d_.*v_)^n_. /; 
		FreeQ[{a,b,c,d},x] && IntegersQ[m,n] && m<0 && n<0]]


(* ::PageBreak:: *)
(**)
