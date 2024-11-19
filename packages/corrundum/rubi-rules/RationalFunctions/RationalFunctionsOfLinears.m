(* ::Package:: *)

(* ::Title::Bold::Closed:: *)
(*\[Integral]a u \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Reference: CRC 1*)


(* ::Subsubsection:: *)
(*Rule:*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]a \[DifferentialD]x  \[LongRightArrow]  a x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[a_,x_Symbol] :=
   a*x /;
IndependentQ[a,x]


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Derivation: Power rule for integration*)


(* ::Subsubsection:: *)
(*Rule:*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]c (a+b x)\[DifferentialD]x  \[LongRightArrow]  ((c (a+b x)^2)/(2 b))*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[c_*(a_+b_.*x_),x_Symbol] :=
  c*(a+b*x)^2/(2*b) /;
FreeQ[{a,b,c},x]


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Reference: G&R 2.02.1, CRC 2*)


(* ::Subsubsection:: *)
(*Derivation: Constant extraction*)


(* ::Subsubsection:: *)
(*Rule: If  n+1!=0, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]c (a+b x)^n \[DifferentialD]x  \[LongRightArrow]  c\[Integral](a+b x)^n \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[c_*(a_+b_.*x_)^n_,x_Symbol] :=
  Dist[c,Int[(a+b*x)^n,x]] /;
FreeQ[{a,b,c,n},x] && NonzeroQ[n+1]


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Reference: G&R 2.02.1, CRC 2*)


(* ::Subsubsection:: *)
(*Derivation: Constant extraction*)


(* ::Subsubsection:: *)
(*Rule:*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]a u \[DifferentialD]x  \[LongRightArrow]  a\[Integral]u \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
If[ShowSteps,

Int[a_*u_,x_Symbol] :=
  Module[{lst=ConstantFactor[u,x]},
  ShowStep["","Int[a*u,x]","a*Int[u,x]",Hold[
  Dist[a*lst[[1]],Int[lst[[2]],x]]]]] /;
SimplifyFlag && FreeQ[a,x] && Not[MatchQ[u,b_*v_ /; FreeQ[b,x]]],

Int[a_*u_,x_Symbol] :=
  Module[{lst=ConstantFactor[u,x]},
  Dist[a*lst[[1]],Int[lst[[2]],x]]] /;
FreeQ[a,x] && Not[MatchQ[u,b_*v_ /; FreeQ[b,x]]]]


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Derivation: Constant extraction*)


(* ::Subsubsection:: *)
(*Note: Constant factors in denominators are aggressively factored out to prevent them occurring unnecessarily in logarithm terms of antiderivatives!*)


(* ::Subsubsection:: *)
(*Rule:*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]a u \[DifferentialD]x  \[LongRightArrow]  a\[Integral]u \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
If[ShowSteps,

Int[u_,x_Symbol] :=
  Module[{lst=ConstantFactor[Simplify[Denominator[u]],x]},
  ShowStep["","Int[a*u,x]","a*Int[u,x]",Hold[
  Dist[1/lst[[1]],Int[Numerator[u]/lst[[2]],x]]]] /;
 lst[[1]]=!=1] /;
SimplifyFlag && (
	MatchQ[u,1/(a_+b_.*x) /; FreeQ[{a,b},x]] ||
	MatchQ[u,x^m_./(a_+b_.*x^n_) /; FreeQ[{a,b,m,n},x] && ZeroQ[m-n+1]] ||
	MatchQ[u,1/((a_.+b_.*x)*(c_+d_.*x)) /; FreeQ[{a,b,c,d},x]] ||
	MatchQ[u,(d_.+e_.*x)/(a_+b_.*x+c_.*x^2) /; FreeQ[{a,b,c,d,e},x]] ||
	MatchQ[u,(c_.*(a_.+b_.*x)^n_)^m_ /; FreeQ[{a,b,c,m,n},x] && ZeroQ[m*n+1]]),

Int[u_,x_Symbol] :=
  Module[{lst=ConstantFactor[Simplify[Denominator[u]],x]},
  Dist[1/lst[[1]],Int[Numerator[u]/lst[[2]],x]] /;
 lst[[1]]=!=1] /;
	MatchQ[u,1/(a_+b_.*x) /; FreeQ[{a,b},x]] ||
	MatchQ[u,x^m_./(a_+b_.*x^n_) /; FreeQ[{a,b,m,n},x] && ZeroQ[m-n+1]] ||
	MatchQ[u,1/((a_.+b_.*x)*(c_+d_.*x)) /; FreeQ[{a,b,c,d},x]] ||
	MatchQ[u,(d_.+e_.*x)/(a_+b_.*x+c_.*x^2) /; FreeQ[{a,b,c,d,e},x]] ||
	MatchQ[u,(c_.*(a_.+b_.*x)^n_)^m_ /; FreeQ[{a,b,c,m,n},x] && ZeroQ[m*n+1]]]


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Derivation: Constant extraction*)


(* ::Subsubsection:: *)
(*Note: Constant factors in denominators are aggressively factored out to prevent them occurring unnecessarily in logarithm terms of antiderivatives!*)


(* ::Subsubsection:: *)
(*Rule:*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]a u \[DifferentialD]x  \[LongRightArrow]  a\[Integral]u \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
If[ShowSteps,

Int[u_/v_,x_Symbol] :=
  Module[{lst=ConstantFactor[v,x]},
  ShowStep["","Int[a*u,x]","a*Int[u,x]",Hold[
  Dist[1/lst[[1]],Int[u/lst[[2]],x]]]] /;
 lst[[1]]=!=1] /;
SimplifyFlag && Not[FalseQ[DerivativeDivides[v,u,x]]],

Int[u_/v_,x_Symbol] :=
  Module[{lst=ConstantFactor[v,x]},
  Dist[1/lst[[1]],Int[u/lst[[2]],x]] /;
 lst[[1]]=!=1] /;
Not[FalseQ[DerivativeDivides[v,u,x]]]]


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Derivation: Piecewise constant extraction*)


(* ::Subsubsection:: *)
(*Basis: \!\( *)
(*\*SubscriptBox[\(\[PartialD]\), \(x\)]*)
(*\*FractionBox[*)
(*SuperscriptBox[\(f[x]\), \(m\)], *)
(*SuperscriptBox[\((\(-f[x]\))\), \(m\)]]\)=0*)


(* ::Subsubsection:: *)
(*Rule: If m+n=0 \[And] v+w=0*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]u v^m w^n \[DifferentialD]x  \[LongRightArrow]  v^m w^n \[Integral]u \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[u_.*v_^m_*w_^n_,x_Symbol] :=
  (v^m*w^n)*Int[u,x] /;
FreeQ[{m,n},x] && ZeroQ[m+n] && ZeroQ[v+w]


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Derivation: Piecewise constant extraction*)


(* ::Subsubsection:: *)
(*Basis: \!\( *)
(*\*SubscriptBox[\(\[PartialD]\), \(x\)]*)
(*\*FractionBox[*)
(*SuperscriptBox[\((a + b\ *)
(*\*SuperscriptBox[\(x\), \(m\)])\), \(p\)], \( *)
(*\*SuperscriptBox[\(x\), \(m\ p\)]\ *)
(*\*SuperscriptBox[\((\(-b\) - *)
(*\*FractionBox[\(a\), *)
(*SuperscriptBox[\(x\), \(m\)]])\), \(p\)]\)]\)=0*)


(* ::Subsubsection:: *)
(*Rule: If  a+d=0 \[And] b+c=0 \[And] m+n=0 \[And] p+q=0*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]u (a+b x^m)^p (c+d x^n)^q \[DifferentialD]x  \[LongRightArrow]  (((a+b x^m)^p (c+d x^n)^q)/x^(m p))\[Integral]u x^(m p) \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[u_.*(a_.+b_.*x_^m_.)^p_.*(c_.+d_.*x_^n_.)^q_., x_Symbol] :=
  (a+b*x^m)^p*(c+d*x^n)^q/x^(m*p)*Int[u*x^(m*p),x] /;
FreeQ[{a,b,c,d,m,n,p,q},x] && ZeroQ[a+d] && ZeroQ[b+c] && ZeroQ[m+n] && ZeroQ[p+q]


(* ::PageBreak:: *)
(**)


(* ::Title::Bold::Closed:: *)
(*\[Integral](a+b x)^n \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Reference: G&R 2.01.2, CRC 27, A&S 3.3.15*)


(* ::Subsubsection:: *)
(*Derivation: Reciprocal rule for integration*)


(* ::Subsubsection:: *)
(*Rule:*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]1/(-a+b x) \[DifferentialD]x  \[LongRightArrow]  (Log[a-b x]/b)*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[1/(a_+b_.*x_),x_Symbol] :=
  Log[-a-b*x]/b /;
FreeQ[{a,b},x] && NegativeCoefficientQ[a]


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Reference: G&R 2.01.2, CRC 27, A&S 3.3.15*)


(* ::Subsubsection:: *)
(*Derivation: Reciprocal rule for integration*)


(* ::Subsubsection:: *)
(*Rule:*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]1/(a+b x) \[DifferentialD]x  \[LongRightArrow]  (Log[a+b x]/b)*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[1/(a_.+b_.*x_),x_Symbol] :=
  Log[a+b*x]/b /;
FreeQ[{a,b},x]


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Reference: G&R 2.01.1, CRC 7*)


(* ::Subsubsection:: *)
(*Derivation: Power rule for integration*)


(* ::Subsubsection:: *)
(*Rule: If n+1!=0, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]x^n \[DifferentialD]x  \[LongRightArrow]  (x^(n+1)/(n+1))*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[x_^n_.,x_Symbol] :=
  x^(n+1)/(n+1) /;
IndependentQ[n,x] && NonzeroQ[n+1]


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Reference: G&R 2.01.1, CRC 23, A&S 3.3.14*)


(* ::Subsubsection:: *)
(*Derivation: Power rule for integration*)


(* ::Subsubsection:: *)
(*Rule: If n+1!=0, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral](a+b x)^n \[DifferentialD]x  \[LongRightArrow]  ((a+b x)^(n+1)/(b (n+1)))*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[(a_.+b_.*x_)^n_,x_Symbol] :=
  (a+b*x)^(n+1)/(b*(n+1)) /;
FreeQ[{a,b,n},x] && NonzeroQ[n+1]


(* ::PageBreak:: *)
(**)


(* ::Title::Bold::Closed:: *)
(*\[Integral]a x^m+b x^n+\[CenterEllipsis] \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Reference: CRC 1,2,4,7,9*)


(* ::Subsubsection:: *)
(*Rule:*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]a+b x+c x^2+\[CenterEllipsis] \[DifferentialD]x  \[LongRightArrow]  a x+(b x^2)/2+(c x^3)/3+\[CenterEllipsis]*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
If[ShowSteps,

Int[u_,x_Symbol] :=
  If[PolynomialQ[u,x],
    ShowStep["","Int[a+b*x+c*x^2+\[CenterEllipsis],x]","a*x+b*x^2/2+c*x^3/3+\[CenterEllipsis]",Hold[
    IntegrateMonomialSum[u,x]]],
  ShowStep["","Int[a+b/x+c*x^m+\[CenterEllipsis],x]","a*x+b*Log[x]+c*x^(m+1)/(m+1)+\[CenterEllipsis]",Hold[
  IntegrateMonomialSum[u,x]]]] /;
SimplifyFlag && MonomialSumQ[u,x],

Int[u_,x_Symbol] :=
  IntegrateMonomialSum[u,x] /;
MonomialSumQ[u,x]]


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Reference: G&R 2.02.2, CRC 2,4*)


(* ::Subsubsection:: *)
(*Rule:*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]a u+b v+\[CenterEllipsis] \[DifferentialD]x  \[LongRightArrow]  a \[Integral]u \[DifferentialD]x+b \[Integral]v \[DifferentialD]x+\[CenterEllipsis]*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
If[ShowSteps,

Int[u_,x_Symbol] :=
  Module[{lst=SplitMonomialTerms[u,x]},
  ShowStep["","Int[a*u+b*v+\[CenterEllipsis],x]","a*Int[u,x]+b*Int[v,x]+\[CenterEllipsis]",Hold[
  Int[lst[[1]],x] + SplitFreeIntegrate[lst[[2]],x]]] /;
 SumQ[lst[[1]]] && Not[FreeQ[lst[[1]],x]] && lst[[2]]=!=0] /;
SimplifyFlag && SumQ[u],

Int[u_,x_Symbol] :=
  Module[{lst=SplitMonomialTerms[u,x]},
  Int[lst[[1]],x] + SplitFreeIntegrate[lst[[2]],x] /;
 SumQ[lst[[1]]] && Not[FreeQ[lst[[1]],x]] && lst[[2]]=!=0] /;
SumQ[u]]


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Derivation: Algebraic expansion*)


(* ::Subsubsection:: *)
(*Basis: z(u+v+\[CenterEllipsis])=z u+z v+\[CenterEllipsis]*)


(* ::Subsubsection:: *)
(*Rule: If m\[Element]\[DoubleStruckCapitalZ], then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]x^m (u+v+\[CenterEllipsis])\[DifferentialD]x  \[LongRightArrow]  \[Integral]x^m u+x^m v+\[CenterEllipsis] \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
If[ShowSteps,

Int[x_^m_.*u_,x_Symbol] :=
  ShowStep["","Int[\!\(\*SuperscriptBox[\(x\), \(m\)]\)*(u+v+\[CenterEllipsis]),x]","Int[\!\(\*SuperscriptBox[\(x\), \(m\)]\)*u+\!\(\*SuperscriptBox[\(x\), \(m\)]\)*v+\[CenterEllipsis],x]",Hold[
  Int[Map[Function[x^m*#],u],x]]] /;
SimplifyFlag && IntegerQ[m] && SumQ[u],

Int[x_^m_.*u_,x_Symbol] :=
  Int[Map[Function[x^m*#],u],x] /;
IntegerQ[m] && SumQ[u]]


(* ::PageBreak:: *)
(**)


(* ::Title::Bold::Closed:: *)
(*\[Integral]1/(x (a+b x^n)) \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Derivation: Integration by substitution*)


(* ::Subsubsection:: *)
(*Basis: If  u=1+(2 b x^n)/a, then 1/(x (a+b x^n))=-(2/(a n)) 1/(1-u^2) \!\( *)
(*\*SubscriptBox[\(\[PartialD]\), \(x\)]u\)*)


(* ::Subsubsection:: *)
(*Rule: If  n>0 \[And] a\[Element]\[DoubleStruckCapitalQ], then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]1/(x (a+b x^n)) \[DifferentialD]x  \[LongRightArrow]  -(2/(a n))ArcTanh[1+(2 b x^n)/a]*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[1/(x_*(a_+b_.*x_^n_.)),x_Symbol] :=
  -2*ArcTanh[1+2*b*x^n/a]/(a*n) /;
FreeQ[{a,b,n},x] && PosQ[n] && (RationalQ[a] || RationalQ[b/a])


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Reference: G&R 2.118.1, CRC 84*)


(* ::Subsubsection:: *)
(*Derivation: Algebraic expansion and reciprocal rule for integration*)


(* ::Subsubsection:: *)
(*Basis: 1/(x (a+b x^n))=1/(a x)-(b x^(n-1))/(a(a+b x^n))*)


(* ::Subsubsection:: *)
(*Rule: If  n>0 \[And] \[Not](a\[Element]\[DoubleStruckCapitalQ]), then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]1/(x (a+b x^n)) \[DifferentialD]x  \[LongRightArrow]  (Log[x]/a)-Log[a+b x^n]/(a n)*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[1/(x_*(a_+b_.*x_^n_.)),x_Symbol] :=
  Log[x]/a - Log[a+b*x^n]/(a*n) /;
FreeQ[{a,b,n},x] && PosQ[n] && Not[RationalQ[a] || RationalQ[b/a]]


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Derivation: Reciprocal rule for integration*)


(* ::Subsubsection:: *)
(*Basis: 1/(x (a+b x^n))=1/(x^(n+1) (b+a/x^n))*)


(* ::Subsubsection:: *)
(*Rule: If  \[Not](n>0), then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]1/(x (a+b x^n)) \[DifferentialD]x  \[LongRightArrow]  -(Log[b+a x^-n]/(a n))*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[1/(x_*(a_+b_.*x_^n_.)),x_Symbol] :=
  -Log[b+a*x^(-n)]/(a*n) /;
FreeQ[{a,b,n},x] && NegQ[n]


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Derivation: Algebraic simplification*)


(* ::Subsubsection:: *)
(*Basis: a x+b x^n=x (a+b x^(n-1))*)


(* ::Subsubsection:: *)
(*Rule:*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]1/(a x+b x^n) \[DifferentialD]x  \[LongRightArrow]  \[Integral]1/(x (a+b x^(n-1))) \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[1/(a_.*x_+b_.*x_^n_),x_Symbol] :=
  Int[1/(x*(a+b*x^(n-1))),x] /;
FreeQ[{a,b,n},x]


(* ::PageBreak:: *)
(**)


(* ::Title::Bold::Closed:: *)
(*\[Integral]x^m (a+b x)^n \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Reference: G&R 2.110.2, CRC 26b special case with m+n+2=0*)


(* ::Subsubsection:: *)
(*Rule: If m+n+2=0 \[And] n+1!=0, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]x^m (a+b x)^n \[DifferentialD]x  \[LongRightArrow]  -((x^(m+1) (a+b x)^(n+1))/(a (n+1)))*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[x_^m_.*(a_+b_.*x_)^n_,x_Symbol] :=
  -x^(m+1)*(a+b*x)^(n+1)/(a*(n+1)) /;
FreeQ[{a,b,m,n},x] && ZeroQ[m+n+2] && NonzeroQ[n+1]


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Reference: G&R 2.110.2, CRC 26b*)


(* ::Subsubsection:: *)
(*Derivation: Integration by parts*)


(* ::Subsubsection:: *)
(*Basis: x^m (a+b x)^n=x^(m+n+2) (a+b x)^n/x^(n+2)*)


(* ::Subsubsection:: *)
(*Rule: If m,n\[Element]\[DoubleStruckCapitalZ] \[And] 0<m<-n-2 \[And] 2m+n+1>0, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]x^m (a+b x)^n \[DifferentialD]x  \[LongRightArrow]  -((x^(m+1) (a+b x)^(n+1))/(a (n+1)))+(m+n+2)/(a (n+1)) \[Integral]x^m (a+b x)^(n+1) \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[x_^m_.*(a_+b_.*x_)^n_,x_Symbol] :=
  -x^(m+1)*(a+b*x)^(n+1)/(a*(n+1)) +
  Dist[(m+n+2)/(a*(n+1)),Int[x^m*(a+b*x)^(n+1),x]] /;
FreeQ[{a,b},x] && IntegersQ[m,n] && 0<m<-n-2 && 2*m+n+1>0


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Reference: G&R 2.110.1, CRC 26a*)


(* ::Subsubsection:: *)
(*Derivation: Inverted integration by parts*)


(* ::Subsubsection:: *)
(*Rule: If m,n\[Element]\[DoubleStruckCapitalZ] \[And] 0<n<m/2, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]x^m (a+b x)^n \[DifferentialD]x  \[LongRightArrow]  ((x^(m+1) (a+b x)^n)/(m+n+1))+(a n)/(m+n+1) \[Integral]x^m (a+b x)^(n-1) \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[x_^m_*(a_.+b_.*x_)^n_.,x_Symbol] :=
  x^(m+1)*(a+b*x)^n/(m+n+1) +
  Dist[a*n/(m+n+1),Int[x^m*(a+b*x)^(n-1),x]] /;
FreeQ[{a,b},x] && IntegersQ[m,n] && 0<n<m/2


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Reference: G&R 2.110.6, CRC 88c*)


(* ::Subsubsection:: *)
(*Derivation: Integration by parts*)


(* ::Subsubsection:: *)
(*Basis: x^m (a+b x)^n=x^m/(a+b x)^(m+2) (a+b x)^(m+n+2)*)


(* ::Subsubsection:: *)
(*Rule: If m,n\[Element]\[DoubleStruckCapitalZ] \[And] 0<n<-m-2 \[And] m+2n-1>0, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]x^m (a+b x)^n \[DifferentialD]x  \[LongRightArrow]  ((x^(m+1) (a+b x)^(n+1))/(a (m+1)))-(b (m+n+2))/(a (m+1)) \[Integral]x^(m+1) (a+b x)^n \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[x_^m_*(a_.+b_.*x_)^n_.,x_Symbol] :=
  x^(m+1)*(a+b*x)^(n+1)/(a*(m+1)) -
  Dist[b*(m+n+2)/(a*(m+1)),Int[x^(m+1)*(a+b*x)^n,x]] /;
FreeQ[{a,b},x] && IntegersQ[m,n] && 0<n<-m-2 && m+2*n-1>0


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Reference: G&R 2.110.5, CRC 26c*)


(* ::Subsubsection:: *)
(*Derivation: Inverted integration by parts*)


(* ::Subsubsection:: *)
(*Rule: If m,n\[Element]\[DoubleStruckCapitalZ] \[And] 0<m<n/2, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]x^m (a+b x)^n \[DifferentialD]x  \[LongRightArrow]  ((x^m (a+b x)^(n+1))/(b (m+n+1)))-(a m)/(b (m+n+1)) \[Integral]x^(m-1) (a+b x)^n \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[x_^m_.*(a_.+b_.*x_)^n_,x_Symbol] :=
  x^m*(a+b*x)^(n+1)/(b*(m+n+1)) -
  Dist[a*m/(b*(m+n+1)),Int[x^(m-1)*(a+b*x)^n,x]] /;
FreeQ[{a,b},x] && IntegersQ[m,n] && 0<m<n/2


(* ::PageBreak:: *)
(**)


(* ::Title::Bold::Closed:: *)
(*\[Integral](a+b x)^m (c+d x)^n \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Derivation: Algebraic simplification*)


(* ::Subsubsection:: *)
(*Basis: If  b c+a d=0, then (a+b x) (c+d x)=a c+b d x^2*)


(* ::Subsubsection:: *)
(*Rule: If  n\[Element]\[DoubleStruckCapitalZ] \[And] b c+a d=0, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral](a+b x)^n (c+d x)^n \[DifferentialD]x  \[LongRightArrow]  \[Integral](a c+b d x^2)^n \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[(a_+b_.*x_)^n_.*(c_+d_.*x_)^n_.,x_Symbol] :=
  Int[(a*c+b*d*x^2)^n,x] /;
FreeQ[{a,b,c,d},x] && IntegerQ[n] && ZeroQ[b*c+a*d]


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Derivation: Algebraic simplification*)


(* ::Subsubsection:: *)
(*Basis: If  b c-a d=0 and n\[Element]\[DoubleStruckCapitalZ], then (a+b x)^m (c+d x)^n=(d/b)^n (a+b x)^(m+n)*)


(* ::Subsubsection:: *)
(*Rule: If  b c-a d=0 \[And] n\[Element]\[DoubleStruckCapitalZ], then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral](a+b x)^m (c+d x)^n \[DifferentialD]x  \[LongRightArrow]  (d/b)^n\[Integral](a+b x)^(m+n) \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[(a_+b_.*x_)^m_.*(c_+d_.*x_)^n_.,x_Symbol] :=
  Dist[(d/b)^n,Int[(a+b*x)^(m+n),x]] /;
FreeQ[{a,b,c,d,m},x] && ZeroQ[b*c-a*d] && IntegerQ[n] && 
(Not[IntegerQ[m]] || LeafCount[a+b*x]<=LeafCount[c+d*x])


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Derivation: Integration by substitution*)


(* ::Subsubsection:: *)
(*Basis: If  u=(b c+a d)/(b c-a d)+(2 b d x)/(b c-a d), then 1/((a+b x) (c+d x))=-(2/(b c-a d)) 1/(1-u^2) \!\( *)
(*\*SubscriptBox[\(\[PartialD]\), \(x\)]u\)*)


(* ::Subsubsection:: *)
(*Note: If  b c-a d\[NotElement]\[DoubleStruckCapitalQ], partial fraction expansion produces two nicer looking log terms.*)


(* ::Subsubsection:: *)
(*Rule: If  b c-a d\[Element]\[DoubleStruckCapitalQ] \[And] b c-a d!=0, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]1/((a+b x) (c+d x)) \[DifferentialD]x  \[LongRightArrow]  -(2/(b c-a d))ArcTanh[(b c+a d)/(b c-a d)+(2 b d x)/(b c-a d)]*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[1/((a_+b_.*x_)*(c_+d_.*x_)),x_Symbol] :=
  -2*ArcTanh[(b*c+a*d)/(b*c-a*d) + 2*b*d*x/(b*c-a*d)]/(b*c-a*d) /;
FreeQ[{a,b,c,d},x] && RationalQ[b*c-a*d] && b*c-a*d!=0


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Reference: G&R 2.155, CRC 59a special case when m+n+2=0*)


(* ::Subsubsection:: *)
(*Rule: If m+n+2=0 \[And] b c-a d!=0 \[And] n+1!=0, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral](a+b x)^m (c+d x)^n \[DifferentialD]x  \[LongRightArrow]  -(((a+b x)^(m+1) (c+d x)^(n+1))/((n+1) (b c-a d)))*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[(a_+b_.*x_)^m_.*(c_+d_.*x_)^n_,x_Symbol] :=
  -(a+b*x)^(m+1)*(c+d*x)^(n+1)/((n+1)*(b*c-a*d)) /;
FreeQ[{a,b,c,d,m,n},x] && ZeroQ[m+n+2] && NonzeroQ[b*c-a*d] && NonzeroQ[n+1]


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Reference: G&R 2.155, CRC 59a*)


(* ::Subsubsection:: *)
(*Derivation: Integration by parts*)


(* ::Subsubsection:: *)
(*Basis: (a+b x)^m (c+d x)^n=(a+b x)^(m+n+2) (c+d x)^n/(a+b x)^(n+2)*)


(* ::Subsubsection:: *)
(*Rule: If m,n\[Element]\[DoubleStruckCapitalZ] \[And] b c-a d!=0 \[And] 0<m<-n-2 \[And] 2m+n+1>0, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral](a+b x)^m (c+d x)^n \[DifferentialD]x  \[LongRightArrow]  -(((a+b x)^(m+1) (c+d x)^(n+1))/((n+1) (b c-a d)))+(b (m+n+2))/((n+1) (b c-a d)) \[Integral](a+b x)^m (c+d x)^(n+1) \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[(a_+b_.*x_)^m_.*(c_+d_.*x_)^n_,x_Symbol] :=
  -(a+b*x)^(m+1)*(c+d*x)^(n+1)/((n+1)*(b*c-a*d)) +
  Dist[b*(m+n+2)/((n+1)*(b*c-a*d)),Int[(a+b*x)^m*(c+d*x)^(n+1),x]] /;
FreeQ[{a,b,c,d},x] && IntegersQ[m,n] && NonzeroQ[b*c-a*d] && 0<m<-n-2 && 2*m+n+1>0


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Reference: G&R 2.151, CRC 59b*)


(* ::Subsubsection:: *)
(*Derivation: Inverted integration by parts*)


(* ::Subsubsection:: *)
(*Rule: If  m,n\[Element]\[DoubleStruckCapitalZ] \[And] b c-a d!=0 \[And] 0<n<=m, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral](a+b x)^m (c+d x)^n \[DifferentialD]x  \[LongRightArrow]  (((a+b x)^(m+1) (c+d x)^n)/(b (m+n+1)))+(n (b c-a d))/(b (m+n+1)) \[Integral](a+b x)^m (c+d x)^(n-1) \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[(a_+b_.*x_)^m_*(c_+d_.*x_)^n_.,x_Symbol] :=
  (a+b*x)^(m+1)*(c+d*x)^n/(b*(m+n+1)) +
  Dist[n*(b*c-a*d)/(b*(m+n+1)),Int[(a+b*x)^m*(c+d*x)^(n-1),x]] /;
FreeQ[{a,b,c,d},x] && IntegersQ[m,n] && NonzeroQ[b*c-a*d] && 0<n<=m


(* ::PageBreak:: *)
(**)


(* ::Title::Bold::Closed:: *)
(*\[Integral]x^m (a+b x)^n (c+d x)^p \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Derivation: Algebraic simplification*)


(* ::Subsubsection:: *)
(*Basis: If  b c+a d=0, (a+b x) (c+d x)=a c+b d x^2*)


(* ::Subsubsection:: *)
(*Rule: If  n\[Element]\[DoubleStruckCapitalZ] \[And] b c+a d=0, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]x^m (a+b x)^n (c+d x)^n \[DifferentialD]x  \[LongRightArrow]  \[Integral]x^m (a c+b d x^2)^n \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[x_^m_.*(a_+b_.*x_)^n_.*(c_+d_.*x_)^n_.,x_Symbol] :=
  Int[x^m*(a*c+b*d*x^2)^n,x] /;
FreeQ[{a,b,c,d,m},x] && IntegerQ[n] && ZeroQ[b*c+a*d]


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Derivation: Integration by substitution*)


(* ::Subsubsection:: *)
(*Basis: \!\( *)
(*\*SubscriptBox[\(\[PartialD]\), \(x\)]\((x\ *)
(*\*SuperscriptBox[\((a + b\ *)
(*\*SuperscriptBox[\(x\), \(n\)])\), \(p + 1\)])\)\)=(a+b x^n)^p (a+b (n (p+1)+1) x^n)*)


(* ::Subsubsection:: *)
(*Rule: If  a d-b c (n (p+1)+1)=0, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral](a+b x^n)^p (c+d x^n)\[DifferentialD]x  \[LongRightArrow]  ((c x (a+b x^n)^(p+1))/a)*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[(a_+b_.*x_^n_.)^p_.*(c_+d_.*x_^n_.), x_Symbol] :=
  c*x*(a+b*x^n)^(p+1)/a /;
FreeQ[{a,b,c,d,n,p},x] && ZeroQ[a*d-b*c*(n*(p+1)+1)]


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Derivation: Integration by substitution*)


(* ::Subsubsection:: *)
(*Basis: \!\( *)
(*\*SubscriptBox[\(\[PartialD]\), \(x\)]\(( *)
(*\*SuperscriptBox[\(x\), \(m + 1\)]\ *)
(*\*SuperscriptBox[\((a + b\ *)
(*\*SuperscriptBox[\(x\), \(n\)])\), \(p + 1\)])\)\)=x^m (a+b x^n)^p (a (m+1)+b (m+n (p+1)+1) x^n)*)


(* ::Subsubsection:: *)
(*Rule: If  m+1!=0 \[And] a d (m+1)-b c (m+n (p+1)+1)=0, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]x^m (a+b x^n)^p (c+d x^n)\[DifferentialD]x  \[LongRightArrow]  ((c x^(m+1) (a+b x^n)^(p+1))/(a (m+1)))*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[x_^m_.*(a_+b_.*x_^n_.)^p_.*(c_+d_.*x_^n_.), x_Symbol] :=
  c*x^(m+1)*(a+b*x^n)^(p+1)/(a*(m+1)) /;
FreeQ[{a,b,c,d,m,n,p},x] && NonzeroQ[m+1] && ZeroQ[a*d*(m+1)-b*c*(m+n*(p+1)+1)]


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Derivation: Integration by substitution*)


(* ::Subsubsection:: *)
(*Basis: \!\( *)
(*\*SubscriptBox[\(\[PartialD]\), \(x\)]\(( *)
(*\*SuperscriptBox[\(x\), \(m + 1\)]\ *)
(*\*SuperscriptBox[\((a + b\ *)
(*\*SuperscriptBox[\(x\), \(n\)])\), \(p + 1\)])\)\)=x^m (a+b x^n)^p (a (m+1)+b (m+n (p+1)+1) x^n)*)


(* ::Subsubsection:: *)
(*Rule: If  m+q+1!=0 \[And] a d (m+q+1)-b c (m+q+n (p+1)+1)=0, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]x^m (a+b x^n)^p (c x^q+d x^(n+q))\[DifferentialD]x  \[LongRightArrow]  ((c x^(m+q+1) (a+b x^n)^(p+1))/(a (m+q+1)))*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[x_^m_.*(a_+b_.*x_^n_.)^p_.*(c_.*x_^q_.+d_.*x_^r_.), x_Symbol] :=
  c*x^(m+q+1)*(a+b*x^n)^(p+1)/(a*(m+q+1)) /;
FreeQ[{a,b,c,d,m,n,p,q,r},x] && ZeroQ[r-n-q] && NonzeroQ[m+q+1] && 
	ZeroQ[a*d*(m+q+1)-b*c*(m+q+n*(p+1)+1)]


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Rule: If  m+n+2!=0 \[And] f (b c (m+1)+a d (n+1))-b d e (m+n+2)=0, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral](a+b x)^m (c+d x)^n (e+f x)\[DifferentialD]x  \[LongRightArrow]  ((f (a+b x)^(m+1) (c+d x)^(n+1))/(b d (m+n+2)))*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[(a_+b_.*x_)^m_.*(c_+d_.*x_)^n_.*(e_+f_.*x_), x_Symbol] :=
  f*(a+b*x)^(m+1)*(c+d*x)^(n+1)/(b*d*(m+n+2)) /;
FreeQ[{a,b,c,d,e,f,m,n},x] && NonzeroQ[m+n+2] && ZeroQ[f*(b*c*(m+1)+a*d*(n+1))-b*d*e*(m+n+2)]


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Rule: If  n,p\[Element]\[DoubleStruckCapitalZ] \[And] 0<n<=2 \[And] p>5, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]x (a+b x)^n (c+d x)^p \[DifferentialD]x  \[LongRightArrow]  (((a+b x)^(n+1) (c+d x)^(p+1))/(b d (2+n+p)))-(b c (n+1)+a d (p+1))/(b d (2+n+p)) \[Integral](a+b x)^n (c+d x)^p \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[x_*(a_+b_.*x_)^n_.*(c_+d_.*x_)^p_.,x_Symbol] :=
  (a+b*x)^(n+1)*(c+d*x)^(p+1)/(b*d*(2+n+p)) -
  Dist[(b*c*(n+1)+a*d*(p+1))/(b*d*(2+n+p)), Int[(a+b*x)^n*(c+d*x)^p, x]] /;
FreeQ[{a,b,c,d,n,p},x] && IntegersQ[n,p] && 0<n<=2 && p>5


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Rule: If  m,n,p\[Element]\[DoubleStruckCapitalZ] \[And] 0<m<=2 \[And] 0<n<=2 \[And] p>5, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]x^m (a+b x)^n (c+d x)^p \[DifferentialD]x  \[LongRightArrow]  ((x^(m-1) (a+b x)^(n+1) (c+d x)^(p+1))/(b d (1+m+n+p)))-                                                                                      *)
(*   (a c (m-1))/(b d (1+m+n+p)) \[Integral]x^(m-2) (a+b x)^n (c+d x)^p \[DifferentialD]x-(b c (m+n)+a d (m+p))/(b d (1+m+n+p)) \[Integral]x^(m-1) (a+b x)^n (c+d x)^p \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[x_^m_*(a_+b_.*x_)^n_.*(c_+d_.*x_)^p_.,x_Symbol] :=
  x^(m-1)*(a+b*x)^(n+1)*(c+d*x)^(p+1)/(b*d*(1+m+n+p)) -
  Dist[a*c*(m-1)/(b*d*(1+m+n+p)), Int[x^(m-2)*(a+b*x)^n*(c+d*x)^p, x]] -
  Dist[(b*c*(m+n)+a*d*(m+p))/(b*d*(1+m+n+p)), Int[x^(m-1)*(a+b*x)^n*(c+d*x)^p, x]] /;
FreeQ[{a,b,c,d,n,p},x] && IntegersQ[m,n,p] && 0<m<=2 && 0<n<=2 && p>5
