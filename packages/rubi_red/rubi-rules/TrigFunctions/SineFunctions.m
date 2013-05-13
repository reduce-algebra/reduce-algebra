(* ::Package:: *)

(* ::Title::Bold::Closed:: *)
(*\[Integral]x^m (a+b Sin[c+d x])^n \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Derivation: Algebraic simplification*)


(* ::Subsubsection:: *)
(*Basis: If  a^2-b^2=0, then a+b Sin[z]=2 a Cos[-((\[Pi] a)/(4 b))+z/2]^2*)


(* ::Subsubsection:: *)
(*Rule: If  a^2-b^2=0 \[And] m\[Element]\[DoubleStruckCapitalQ] \[And] n\[Element]\[DoubleStruckCapitalZ] \[And] n<0, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]x^m (a+b Sin[c+d x])^n \[DifferentialD]x  \[LongRightArrow]  (2 a)^n\[Integral]x^m Cos[-((\[Pi] a)/(4 b))+c/2+(d x)/2]^(2 n) \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[x_^m_.*(a_+b_.*Sin[c_.+d_.*x_])^n_,x_Symbol] :=
  Dist[(2*a)^n,Int[x^m*Cos[-Pi*a/(4*b)+c/2+d*x/2]^(2*n),x]] /;
FreeQ[{a,b,c,d},x] && ZeroQ[a^2-b^2] && RationalQ[m] && IntegerQ[n] && n<0


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Derivation: Algebraic simplification and piecewise constant extraction*)


(* ::Subsubsection:: *)
(*Basis: If  a^2-b^2=0, then a+b Sin[z]=2 a Cos[-((\[Pi] a)/(4 b))+z/2]^2*)


(* ::Subsubsection:: *)
(*Basis: If  a^2-b^2=0, then \!\( *)
(*\*SubscriptBox[\(\[PartialD]\), \(z\)]*)
(*\*FractionBox[*)
(*SqrtBox[\(a + b\ Sin[z]\)], \(Cos[\(-*)
(*\*FractionBox[\(\[Pi]\ a\), \(4\ b\)]\) + *)
(*\*FractionBox[\(z\), \(2\)]]\)]\)=0*)


(* ::Subsubsection:: *)
(*Rule: If  a^2-b^2=0 \[And] m\[Element]\[DoubleStruckCapitalQ] \[And] n-1/2\[Element]\[DoubleStruckCapitalZ], then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]x^m (a+b Sin[c+d x])^n \[DifferentialD]x  \[LongRightArrow]  (((2 a)^(n-1/2) Sqrt[a+b Sin[c+d x]])/Cos[-((\[Pi] a)/(4 b))+c/2+(d x)/2])\[Integral]x^m Cos[-((\[Pi] a)/(4 b))+c/2+(d x)/2]^(2 n) \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[x_^m_.*(a_+b_.*Sin[c_.+d_.*x_])^n_,x_Symbol] :=
  Dist[(2*a)^(n-1/2)*Sqrt[a+b*Sin[c+d*x]]/Cos[-Pi*a/(4*b)+c/2+d*x/2],
    Int[x^m*Cos[-Pi*a/(4*b)+c/2+d*x/2]^(2*n),x]] /;
FreeQ[{a,b,c,d},x] && ZeroQ[a^2-b^2] && RationalQ[m] && IntegerQ[n-1/2]


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Derivation: Algebraic expansion*)


(* ::Subsubsection:: *)
(*Basis: 1/(a+b z)^2=a/((a^2-b^2) (a+b z))-(b (b+a z))/((a^2-b^2) (a+b z)^2)*)


(* ::Subsubsection:: *)
(*Rule: If  a^2-b^2!=0, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]x/(a+b Sin[c+d x])^2 \[DifferentialD]x  \[LongRightArrow]  (a/(a^2-b^2))\[Integral]x/(a+b Sin[c+d x]) \[DifferentialD]x-b/(a^2-b^2) \[Integral](x (b+a Sin[c+d x]))/(a+b Sin[c+d x])^2 \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[x_/(a_+b_.*Sin[c_.+d_.*x_])^2,x_Symbol] :=
  Dist[a/(a^2-b^2),Int[x/(a+b*Sin[c+d*x]),x]] -
  Dist[b/(a^2-b^2),Int[x*(b+a*Sin[c+d*x])/(a+b*Sin[c+d*x])^2,x]] /;
FreeQ[{a,b,c,d},x] && NonzeroQ[a^2-b^2]


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Derivation: Algebraic expansion*)


(* ::Subsubsection:: *)
(*Basis: a+b Sin[z]=(I b+2 a E^(I z)-I b E^(2 I z))/(2 E^(I z))*)


(* ::Subsubsection:: *)
(*Rule: If  a^2-b^2!=0 \[And] m>0 \[And] n\[Element]\[DoubleStruckCapitalZ] \[And] n<0, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]x^m (a+b Sin[c+d x])^n \[DifferentialD]x  \[LongRightArrow]  (1/2^n)\[Integral](x^m (I b+2 a E^(I c+I d x)-I b E^(2 (I c+I d x)))^n)/E^(n (I c+I d x)) \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[x_^m_.*(a_+b_.*Sin[c_.+d_.*x_])^n_,x_Symbol] :=
  Dist[1/2^n,Int[x^m*(I*b+2*a*E^(I*c+I*d*x)-I*b*E^(2*(I*c+I*d*x)))^n/E^(n*(I*c+I*d*x)),x]] /;
FreeQ[{a,b,c,d},x] && NonzeroQ[a^2-b^2] && RationalQ[m] && m>0 && IntegerQ[n] && n<0


(* ::PageBreak:: *)
(**)


(* ::Title::Bold::Closed:: *)
(*\[Integral]x^m (a+b Cos[c+d x])^n \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Derivation: Algebraic simplification*)


(* ::Subsubsection:: *)
(*Basis: If  a^2-b^2=0, then a+b Cos[z]=2 a Cos[-(1/4) \[Pi] (1-a/b)+z/2]^2*)


(* ::Subsubsection:: *)
(*Note: This rule unifies the following two rules, but superficially appears more complicated.*)


(* ::Subsubsection:: *)
(*Rule: If  a^2-b^2=0 \[And] m\[Element]\[DoubleStruckCapitalQ] \[And] n\[Element]\[DoubleStruckCapitalZ] \[And] n<0, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]x^m (a+b Cos[c+d x])^n \[DifferentialD]x  \[LongRightArrow]  (2 a)^n\[Integral]x^m Cos[1/4 (-\[Pi]) (1-a/b)+c/2+(d x)/2]^(2 n) \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
(* Int[x_^m_.*(a_+b_.*Cos[c_.+d_.*x_])^n_,x_Symbol] :=
  Dist[(2*a)^n,Int[x^m*Cos[-Pi/4*(1-a/b)+c/2+d*x/2]^(2*n),x]] /;
FreeQ[{a,b,c,d},x] && ZeroQ[a^2-b^2] && RationalQ[m] && IntegerQ[n] && n<0 *)


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Derivation: Algebraic simplification*)


(* ::Subsubsection:: *)
(*Basis: 1+Cos[z]=2 Cos[z/2]^2*)


(* ::Subsubsection:: *)
(*Rule: If  a-b=0 \[And] m\[Element]\[DoubleStruckCapitalQ] \[And] n\[Element]\[DoubleStruckCapitalZ] \[And] n<0, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]x^m (a+b Cos[c+d x])^n \[DifferentialD]x  \[LongRightArrow]  (2 a)^n\[Integral]x^m Cos[c/2+(d x)/2]^(2 n) \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[x_^m_.*(a_+b_.*Cos[c_.+d_.*x_])^n_,x_Symbol] :=
  Dist[(2*a)^n,Int[x^m*Cos[c/2+d*x/2]^(2*n),x]] /;
FreeQ[{a,b,c,d},x] && ZeroQ[a-b] && RationalQ[m] && IntegerQ[n] && n<0


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Derivation: Algebraic simplification*)


(* ::Subsubsection:: *)
(*Basis: 1-Cos[z]=2 Sin[z/2]^2*)


(* ::Subsubsection:: *)
(*Rule: If  a+b=0 \[And] m\[Element]\[DoubleStruckCapitalQ] \[And] n\[Element]\[DoubleStruckCapitalZ] \[And] n<0, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]x^m (a+b Cos[c+d x])^n \[DifferentialD]x  \[LongRightArrow]  (2 a)^n\[Integral]x^m Sin[c/2+(d x)/2]^(2 n) \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[x_^m_.*(a_+b_.*Cos[c_.+d_.*x_])^n_,x_Symbol] :=
  Dist[(2*a)^n,Int[x^m*Sin[c/2+d*x/2]^(2*n),x]] /;
FreeQ[{a,b,c,d},x] && ZeroQ[a+b] && RationalQ[m] && IntegerQ[n] && n<0


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Derivation: Algebraic simplification and piecewise constant extraction*)


(* ::Subsubsection:: *)
(*Basis: If  a^2-b^2=0, then a+b Cos[z]=2 a Cos[z/2-1/4 \[Pi] (1-a/b)]^2*)


(* ::Subsubsection:: *)
(*Basis: If  a^2-b^2=0, then \!\( *)
(*\*SubscriptBox[\(\[PartialD]\), \(z\)]*)
(*\*FractionBox[*)
(*SqrtBox[\(a + b\ Cos[z]\)], \(Cos[*)
(*\*FractionBox[\(z\), \(2\)] - *)
(*\*FractionBox[\(1\), \(4\)]\ \[Pi]\ \((1 - *)
(*\*FractionBox[\(a\), \(b\)])\)]\)]\)==0*)


(* ::Subsubsection:: *)
(*Note: This rule unifies the following two rules, but superficially appears more complicated.*)


(* ::Subsubsection:: *)
(*Rule: If  a^2-b^2=0 \[And] m\[Element]\[DoubleStruckCapitalQ] \[And] n-1/2\[Element]\[DoubleStruckCapitalZ], then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]x^m (a+b Cos[c+d x])^n \[DifferentialD]x  \[LongRightArrow]  (((2 a)^(n-1/2) Sqrt[a+b Cos[c+d x]])/Cos[1/4 (-\[Pi]) (1-a/b)+c/2+(d x)/2])\[Integral]x^m Cos[1/4 (-\[Pi]) (1-a/b)+c/2+(d x)/2]^(2 n) \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
(* Int[x_^m_.*(a_+b_.*Cos[c_.+d_.*x_])^n_,x_Symbol] :=
  Dist[(2*a)^(n-1/2)*Sqrt[a+b*Cos[c+d*x]]/Cos[-Pi/4*(1-a/b)+c/2+d*x/2],
    Int[x^m*Cos[-Pi/4*(1-a/b)+c/2+d*x/2]^(2*n),x]] /;
FreeQ[{a,b,c,d},x] && ZeroQ[a^2-b^2] && RationalQ[m] && IntegerQ[n-1/2] *)


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Derivation: Algebraic simplification*)


(* ::Subsubsection:: *)
(*Basis: 1+Cos[z]=2 Cos[z/2]^2*)


(* ::Subsubsection:: *)
(*Basis: \!\( *)
(*\*SubscriptBox[\(\[PartialD]\), \(z\)]*)
(*\*FractionBox[*)
(*SqrtBox[\(a + a\ Cos[z]\)], \(Cos[*)
(*\*FractionBox[\(z\), \(2\)]]\)]\)=0*)


(* ::Subsubsection:: *)
(*Rule: If  a-b=0 \[And] m\[Element]\[DoubleStruckCapitalQ] \[And] n-1/2\[Element]\[DoubleStruckCapitalZ], then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]x^m (a+b Cos[c+d x])^n \[DifferentialD]x  \[LongRightArrow]  (((2 a)^(n-1/2) Sqrt[a+b Cos[c+d x]])/Cos[c/2+(d x)/2])\[Integral]x^m Cos[c/2+(d x)/2]^(2 n) \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[x_^m_.*(a_+b_.*Cos[c_.+d_.*x_])^n_,x_Symbol] :=
  Dist[(2*a)^(n-1/2)*Sqrt[a+b*Cos[c+d*x]]/Cos[c/2+d*x/2],Int[x^m*Cos[c/2+d*x/2]^(2*n),x]] /;
FreeQ[{a,b,c,d},x] && ZeroQ[a-b] && RationalQ[m] && IntegerQ[n-1/2]


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Derivation: Algebraic simplification*)


(* ::Subsubsection:: *)
(*Basis: 1-Cos[z]=2 Sin[z/2]^2*)


(* ::Subsubsection:: *)
(*Basis: \!\( *)
(*\*SubscriptBox[\(\[PartialD]\), \(z\)]*)
(*\*FractionBox[*)
(*SqrtBox[\(a - a\ Cos[z]\)], \(Sin[*)
(*\*FractionBox[\(z\), \(2\)]]\)]\)=0*)


(* ::Subsubsection:: *)
(*Rule: If  a+b=0 \[And] m\[Element]\[DoubleStruckCapitalQ] \[And] n-1/2\[Element]\[DoubleStruckCapitalZ], then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]x^m (a+b Cos[c+d x])^n \[DifferentialD]x  \[LongRightArrow]  (((2 a)^(n-1/2) Sqrt[a+b Cos[c+d x]])/Sin[c/2+(d x)/2])\[Integral]x^m Sin[c/2+(d x)/2]^(2 n) \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[x_^m_.*(a_+b_.*Cos[c_.+d_.*x_])^n_,x_Symbol] :=
  Dist[(2*a)^(n-1/2)*Sqrt[a+b*Cos[c+d*x]]/Sin[c/2+d*x/2],Int[x^m*Sin[c/2+d*x/2]^(2*n),x]] /;
FreeQ[{a,b,c,d},x] && ZeroQ[a+b] && RationalQ[m] && IntegerQ[n-1/2]


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Derivation: Algebraic expansion*)


(* ::Subsubsection:: *)
(*Basis: 1/(a+b z)^2=a/((a^2-b^2) (a+b z))-(b (b+a z))/((a^2-b^2) (a+b z)^2)*)


(* ::Subsubsection:: *)
(*Rule: If  a^2-b^2!=0, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]x/(a+b Cos[c+d x])^2 \[DifferentialD]x  \[LongRightArrow]  (a/(a^2-b^2))\[Integral]x/(a+b Cos[c+d x]) \[DifferentialD]x-b/(a^2-b^2) \[Integral](x (b+a Cos[c+d x]))/(a+b Cos[c+d x])^2 \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[x_/(a_+b_.*Cos[c_.+d_.*x_])^2,x_Symbol] :=
  Dist[a/(a^2-b^2),Int[x/(a+b*Cos[c+d*x]),x]] -
  Dist[b/(a^2-b^2),Int[x*(b+a*Cos[c+d*x])/(a+b*Cos[c+d*x])^2,x]] /;
FreeQ[{a,b,c,d},x] && NonzeroQ[a^2-b^2]


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Derivation: Algebraic expansion*)


(* ::Subsubsection:: *)
(*Basis: a+b Cos[z]=(b+2 a E^(I z)+b E^(2 I z))/(2 E^(I z))*)


(* ::Subsubsection:: *)
(*Rule: If  a^2-b^2!=0 \[And] m>0 \[And] n\[Element]\[DoubleStruckCapitalZ] \[And] n<0, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]x^m (a+b Cos[c+d x])^n \[DifferentialD]x  \[LongRightArrow]  (1/2^n)\[Integral](x^m (b+2 a E^(I c+I d x)+b E^(2 (I c+I d x)))^n)/E^(n (I c+I d x)) \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[x_^m_.*(a_+b_.*Cos[c_.+d_.*x_])^n_,x_Symbol] :=
  Dist[1/2^n,Int[x^m*(b+2*a*E^(I*c+I*d*x)+b*E^(2*(I*c+I*d*x)))^n/E^(n*(I*c+I*d*x)),x]] /;
FreeQ[{a,b,c,d},x] && NonzeroQ[a^2-b^2] && RationalQ[m] && m>0 && IntegerQ[n] && n<0


(* ::PageBreak:: *)
(**)


(* ::Title::Bold::Closed:: *)
(*\[Integral]u (a+b Sin[c+d x]^2)^n \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Derivation: Algebraic simplification*)


(* ::Subsubsection:: *)
(*Basis: Sin[z]^2=1/2 (1-Cos[2 z])*)


(* ::Subsubsection:: *)
(*Note: This rule should be replaced with rules that directly reduce the integrand rather than transforming it using trig power expansion!*)


(* ::Subsubsection:: *)
(*Rule: If  a+b!=0 \[And] n!=-1, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral](a+b Sin[c+d x]^2)^n \[DifferentialD]x  \[LongRightArrow]  (1/2^n)\[Integral](2 a+b-b Cos[2 c+2 d x])^n \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[(a_+b_.*Sin[c_.+d_.*x_]^2)^n_,x_Symbol] :=
  Dist[1/2^n,Int[(2*a+b-b*Cos[2*c+2*d*x])^n,x]] /;
FreeQ[{a,b,c,d},x] && NonzeroQ[a+b] && RationalQ[n] && n!=-1


(* ::Code:: *)
Int[(a_+b_.*Cos[c_.+d_.*x_]^2)^n_,x_Symbol] :=
  Dist[1/2^n,Int[(2*a+b+b*Cos[2*c+2*d*x])^n,x]] /;
FreeQ[{a,b,c,d},x] && NonzeroQ[a+b] && RationalQ[n] && n!=-1


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Derivation: Algebraic simplification*)


(* ::Subsubsection:: *)
(*Basis: Sin[z]^2=1/2 (1-Cos[2 z])*)


(* ::Subsubsection:: *)
(*Note: This rule should be replaced with rules that directly reduce the integrand rather than transforming it using trig power expansion!*)


(* ::Subsubsection:: *)
(*Rule: If  a+b!=0 \[And] m\[Element]\[DoubleStruckCapitalZ] \[And] m>0, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]x^m (a+b Sin[c+d x]^2)^n \[DifferentialD]x  \[LongRightArrow]  (1/2^n)\[Integral]x^m (2 a+b-b Cos[2 c+2 d x])^n \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[x_^m_.*(a_+b_.*Sin[c_.+d_.*x_]^2)^n_,x_Symbol] :=
  Dist[1/2^n,Int[x^m*(2*a+b-b*Cos[2*c+2*d*x])^n,x]] /;
FreeQ[{a,b,c,d},x] && NonzeroQ[a+b] && IntegersQ[m,n] && (m>0 && n==-1 || m==1 && n==-2)


(* ::Code:: *)
Int[x_^m_.*(a_+b_.*Cos[c_.+d_.*x_]^2)^n_,x_Symbol] :=
  Dist[1/2^n,Int[x^m*(2*a+b+b*Cos[2*c+2*d*x])^n,x]] /;
FreeQ[{a,b,c,d},x] && NonzeroQ[a+b] && IntegersQ[m,n] && (m>0 && n==-1 || m==1 && n==-2)


(* ::PageBreak:: *)
(**)


(* ::Title::Bold::Closed:: *)
(*\[Integral]Sin[a+b x^n]\[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Derivation: Primitive rule*)


(* ::Subsubsection:: *)
(*Basis: Derivative[1][FresnelS][z]=Sin[(\[Pi] z^2)/2]*)


(* ::Subsubsection:: *)
(*Rule:*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]Sin[b x^2]\[DifferentialD]x  \[LongRightArrow]  (Sqrt[(\[Pi]/2)]/Sqrt[b])FresnelS[(Sqrt[b] x)/Sqrt[\[Pi]/2]]*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[Sin[b_.*x_^2],x_Symbol] :=
  Sqrt[Pi/2]*FresnelS[Rt[b,2]*x/Sqrt[Pi/2]]/Rt[b,2] /;
FreeQ[b,x]


(* ::Code:: *)
Int[Cos[b_.*x_^2],x_Symbol] :=
  Sqrt[Pi/2]*FresnelC[Rt[b,2]*x/Sqrt[Pi/2]]/Rt[b,2] /;
FreeQ[b,x]


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Derivation: Algebraic expansion*)


(* ::Subsubsection:: *)
(*Basis: Sin[w+z]=Sin[w] Cos[z]+Cos[w] Sin[z]*)


(* ::Subsubsection:: *)
(*Rule:*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]Sin[a+b x^2]\[DifferentialD]x  \[LongRightArrow]  Sin[a]\[Integral]Cos[b x^2]\[DifferentialD]x+Cos[a]\[Integral]Sin[b x^2]\[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[Sin[a_+b_.*x_^2],x_Symbol] :=
  Dist[Sin[a],Int[Cos[b*x^2],x]] + 
  Dist[Cos[a],Int[Sin[b*x^2],x]] /;
FreeQ[{a,b},x]


(* ::Code:: *)
Int[Cos[a_+b_.*x_^2],x_Symbol] :=
  Dist[Cos[a],Int[Cos[b*x^2],x]] - 
  Dist[Sin[a],Int[Sin[b*x^2],x]] /;
FreeQ[{a,b},x]


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Derivation: Algebraic expansion*)


(* ::Subsubsection:: *)
(*Basis: Sin[z]=1/2 I E^(-I z)-1/2 I E^(I z)*)


(* ::Subsubsection:: *)
(*Rule: If  \[Not](n\[Element]\[DoubleStruckCapitalF] \[Or] n<0), then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]Sin[a+b x^n]\[DifferentialD]x  \[LongRightArrow]  (I/2)\[Integral]E^(-a I-b I x^n) \[DifferentialD]x-I/2 \[Integral]E^(a I+b I x^n) \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[Sin[a_.+b_.*x_^n_],x_Symbol] :=
  Dist[I/2,Int[E^(-a*I-b*I*x^n),x]] - 
  Dist[I/2,Int[E^(a*I+b*I*x^n),x]] /;
FreeQ[{a,b,n},x] && Not[FractionOrNegativeQ[n]]


(* ::Subsubsection:: *)
(*Basis: Cos[z]=1/2 E^(-I z)+1/2 E^(I z)*)


(* ::Code:: *)
Int[Cos[a_.+b_.*x_^n_],x_Symbol] :=
  Dist[1/2,Int[E^(-a*I-b*I*x^n),x]] + 
  Dist[1/2,Int[E^(a*I+b*I*x^n),x]] /;
FreeQ[{a,b,n},x] && Not[FractionOrNegativeQ[n]]


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Derivation: Integration by parts*)


(* ::Subsubsection:: *)
(*Note: Although resulting integrand looks more complicated than the original, rules for improper binomials rectify it.*)


(* ::Subsubsection:: *)
(*Rule: If  n\[Element]\[DoubleStruckCapitalZ] \[Or] n<0, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]Sin[a+b x^n]\[DifferentialD]x  \[LongRightArrow]  x Sin[a+b x^n]-b n \[Integral]x^n Cos[a+b x^n]\[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[Sin[a_.+b_.*x_^n_],x_Symbol] :=
  x*Sin[a+b*x^n] -
  Dist[b*n,Int[x^n*Cos[a+b*x^n],x]] /;
FreeQ[{a,b},x] && IntegerQ[n] && n<0


(* ::Code:: *)
Int[Cos[a_.+b_.*x_^n_],x_Symbol] :=
  x*Cos[a+b*x^n] + 
  Dist[b*n,Int[x^n*Sin[a+b*x^n],x]] /;
FreeQ[{a,b},x] && IntegerQ[n] && n<0


(* ::PageBreak:: *)
(**)


(* ::Title::Bold::Closed:: *)
(*\[Integral]x^m Sin[a+b x^n]\[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Derivation: Primitive rule*)


(* ::Subsubsection:: *)
(*Basis: Derivative[1][SinIntegral][z]=Sin[z]/z*)


(* ::Subsubsection:: *)
(*Rule:*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]Sin[b x^n]/x \[DifferentialD]x  \[LongRightArrow]  (SinIntegral[b x^n]/n)*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[Sin[b_.*x_^n_.]/x_,x_Symbol] :=
  SinIntegral[b*x^n]/n /;
FreeQ[{b,n},x]


(* ::Code:: *)
Int[Cos[b_.*x_^n_.]/x_,x_Symbol] :=
  CosIntegral[b*x^n]/n /;
FreeQ[{b,n},x]


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Derivation: Algebraic expansion*)


(* ::Subsubsection:: *)
(*Basis: Sin[w+z]=Sin[w] Cos[z]+Cos[w] Sin[z]*)


(* ::Subsubsection:: *)
(*Rule:*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]Sin[a+b x^n]/x \[DifferentialD]x  \[LongRightArrow]  Sin[a]\[Integral]Cos[b x^n]/x \[DifferentialD]x+Cos[a]\[Integral]Sin[b x^n]/x \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[Sin[a_+b_.*x_^n_.]/x_,x_Symbol] :=
  Dist[Sin[a],Int[Cos[b*x^n]/x,x]] + 
  Dist[Cos[a],Int[Sin[b*x^n]/x,x]] /;
FreeQ[{a,b,n},x]


(* ::Code:: *)
Int[Cos[a_+b_.*x_^n_.]/x_,x_Symbol] :=
  Dist[Cos[a],Int[Cos[b*x^n]/x,x]] - 
  Dist[Sin[a],Int[Sin[b*x^n]/x,x]] /;
FreeQ[{a,b,n},x]


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Reference: CRC 392, A&S 4.3.119*)


(* ::Subsubsection:: *)
(*Derivation: Integration by parts*)


(* ::Subsubsection:: *)
(*Basis: x^m Sin[a+b x^n]=-((x^(m-n+1) \!\( *)
(*\*SubscriptBox[\(\[PartialD]\), \(x\)]\(Cos[a + b\ *)
(*\*SuperscriptBox[\(x\), \(n\)]]\)\))/(b n))*)


(* ::Subsubsection:: *)
(*Rule: If  n\[Element]\[DoubleStruckCapitalZ] \[And] 0<n<=m, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]x^m Sin[a+b x^n]\[DifferentialD]x  \[LongRightArrow]  -((x^(m-n+1) Cos[a+b x^n])/(b n))+(m-n+1)/(b n) \[Integral]x^(m-n) Cos[a+b x^n]\[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[x_^m_.*Sin[a_.+b_.*x_^n_.],x_Symbol] :=
  -x^(m-n+1)*Cos[a+b*x^n]/(b*n) +
  Dist[(m-n+1)/(b*n),Int[x^(m-n)*Cos[a+b*x^n],x]] /;
FreeQ[{a,b},x] && IntegerQ[n] && RationalQ[m] && 0<n<=m


(* ::Subsubsection:: *)
(*Reference: CRC 396, A&S 4.3.123*)


(* ::Code:: *)
Int[x_^m_.*Cos[a_.+b_.*x_^n_.],x_Symbol] :=
  x^(m-n+1)*Sin[a+b*x^n]/(b*n) -
  Dist[(m-n+1)/(b*n),Int[x^(m-n)*Sin[a+b*x^n],x]] /;
FreeQ[{a,b},x] && IntegerQ[n] && RationalQ[m] && 0<n<=m


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Reference: CRC 405, A&S 4.3.120*)


(* ::Subsubsection:: *)
(*Derivation: Integration by parts*)


(* ::Subsubsection:: *)
(*Rule: If  m+n+1=0 \[Or] (n\[Element]\[DoubleStruckCapitalZ] \[And] ((n>0 \[And] m<-1) \[Or] 0<-n<m+1), then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]x^m Sin[a+b x^n]\[DifferentialD]x  \[LongRightArrow]  ((x^(m+1) Sin[a+b x^n])/(m+1))-(b n)/(m+1) \[Integral]x^(m+n) Cos[a+b x^n]\[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[x_^m_.*Sin[a_.+b_.*x_^n_.],x_Symbol] :=
  x^(m+1)*Sin[a+b*x^n]/(m+1) -
  Dist[b*n/(m+1),Int[x^(m+n)*Cos[a+b*x^n],x]] /;
FreeQ[{a,b,m,n},x] && (ZeroQ[m+n+1] || IntegerQ[n] && RationalQ[m] && (n>0 && m<-1 || 0<-n<m+1))


(* ::Subsubsection:: *)
(*Reference: CRC 406, A&S 4.3.124*)


(* ::Code:: *)
Int[x_^m_.*Cos[a_.+b_.*x_^n_.],x_Symbol] :=
  x^(m+1)*Cos[a+b*x^n]/(m+1) +
  Dist[b*n/(m+1),Int[x^(m+n)*Sin[a+b*x^n],x]] /;
FreeQ[{a,b,m,n},x] && (ZeroQ[m+n+1] || IntegerQ[n] && RationalQ[m] && (n>0 && m<-1 || 0<-n<m+1))


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Derivation: Algebraic expansion*)


(* ::Subsubsection:: *)
(*Basis: Sin[z]=1/2 I E^(-I z)-1/2 I E^(I z)*)


(* ::Subsubsection:: *)
(*Rule: If  m+1!=0 \[And] m-n+1!=0 \[And] \[Not](m\[Element]\[DoubleStruckCapitalF] \[Or] n\[Element]\[DoubleStruckCapitalF] \[Or] n<0), then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]x^m Sin[a+b x^n]\[DifferentialD]x  \[LongRightArrow]  (I/2)\[Integral]x^m E^(-a I-b I x^n) \[DifferentialD]x-I/2 \[Integral]x^m E^(a I+b I x^n) \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[x_^m_.*Sin[a_.+b_.*x_^n_.],x_Symbol] :=
  Dist[I/2,Int[x^m*E^(-a*I-b*I*x^n),x]] - 
  Dist[I/2,Int[x^m*E^(a*I+b*I*x^n),x]] /;
FreeQ[{a,b,m,n},x] && NonzeroQ[m+1] && NonzeroQ[m-n+1] && 
Not[FractionQ[m] || FractionOrNegativeQ[n]]


(* ::Subsubsection:: *)
(*Basis: Cos[z]=1/2 E^(-I z)+1/2 E^(I z)*)


(* ::Code:: *)
Int[x_^m_.*Cos[a_.+b_.*x_^n_.],x_Symbol] :=
  Dist[1/2,Int[x^m*E^(-a*I-b*I*x^n),x]] + 
  Dist[1/2,Int[x^m*E^(a*I+b*I*x^n),x]] /;
FreeQ[{a,b,m,n},x] && NonzeroQ[m+1] && NonzeroQ[m-n+1] && 
Not[FractionQ[m] || FractionOrNegativeQ[n]]


(* ::PageBreak:: *)
(**)


(* ::Title::Bold::Closed:: *)
(*\[Integral]x^m Sin[a+b x^n]^p \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Derivation: Integration by parts*)


(* ::Subsubsection:: *)
(*Rule: If  n,p\[Element]\[DoubleStruckCapitalZ] \[And] p>1 \[And] n-1!=0, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]Sin[a+b x^n]^p/x^n \[DifferentialD]x  \[LongRightArrow]  -(Sin[a+b x^n]^p/((n-1)x^(n-1)))+(b n p)/(n-1) \[Integral]Sin[a+b x^n]^(p-1) Cos[a+b x^n]\[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[x_^m_.*Sin[a_.+b_.*x_^n_.]^p_,x_Symbol] :=
  -Sin[a+b*x^n]^p/((n-1)*x^(n-1)) +
  Dist[b*n*p/(n-1),Int[Sin[a+b*x^n]^(p-1)*Cos[a+b*x^n],x]] /;
FreeQ[{a,b},x] && IntegersQ[n,p] && ZeroQ[m+n] && p>1 && NonzeroQ[n-1]


(* ::Code:: *)
Int[x_^m_.*Cos[a_.+b_.*x_^n_.]^p_,x_Symbol] :=
  -Cos[a+b*x^n]^p/((n-1)*x^(n-1)) -
  Dist[b*n*p/(n-1),Int[Cos[a+b*x^n]^(p-1)*Sin[a+b*x^n],x]] /;
FreeQ[{a,b},x] && IntegersQ[n,p] && ZeroQ[m+n] && p>1 && NonzeroQ[n-1]


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Reference: G&R 2.631.2' special case when m-2n+1=0*)


(* ::Subsubsection:: *)
(*Rule: If  p>1 \[And] m-2n+1=0, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]x^m Sin[a+b x^n]^p \[DifferentialD]x  \[LongRightArrow]  ((n Sin[a+b x^n]^p)/(b^2 n^2 p^2))-(x^n Cos[a+b x^n] Sin[a+b x^n]^(p-1))/(b n p)+(p-1)/p \[Integral]x^m Sin[a+b x^n]^(p-2) \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[x_^m_.*Sin[a_.+b_.*x_^n_.]^p_,x_Symbol] :=
  n*Sin[a+b*x^n]^p/(b^2*n^2*p^2) -
  x^n*Cos[a+b*x^n]*Sin[a+b*x^n]^(p-1)/(b*n*p) +
  Dist[(p-1)/p,Int[x^m*Sin[a+b*x^n]^(p-2),x]] /;
FreeQ[{a,b,m,n},x] && RationalQ[p] && p>1 && ZeroQ[m-2*n+1]


(* ::Subsubsection:: *)
(*Reference: G&R 2.631.3' special case with m-2n+1=0*)


(* ::Code:: *)
Int[x_^m_.*Cos[a_.+b_.*x_^n_.]^p_,x_Symbol] :=
  n*Cos[a+b*x^n]^p/(b^2*n^2*p^2) +
  x^n*Sin[a+b*x^n]*Cos[a+b*x^n]^(p-1)/(b*n*p) +
  Dist[(p-1)/p,Int[x^m*Cos[a+b*x^n]^(p-2),x]] /;
FreeQ[{a,b,m,n},x] && RationalQ[p] && p>1 && ZeroQ[m-2*n+1]


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Reference: G&R 2.631.2'*)


(* ::Subsubsection:: *)
(*Rule: If  m,n\[Element]\[DoubleStruckCapitalZ] \[And] p>1 \[And] 0<2n<m+1, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]x^m Sin[a+b x^n]^p \[DifferentialD]x  \[LongRightArrow]  (((m-n+1) x^(m-2 n+1) Sin[a+b x^n]^p)/(b^2 n^2 p^2))-(x^(m-n+1) Cos[a+b x^n] Sin[a+b x^n]^(p-1))/(b n p)+     *)
(*                                           (p-1)/p \[Integral]x^m Sin[a+b x^n]^(p-2) \[DifferentialD]x-((m-n+1) (m-2 n+1))/(b^2 n^2 p^2) \[Integral]x^(m-2 n) Sin[a+b x^n]^p \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[x_^m_.*Sin[a_.+b_.*x_^n_.]^p_,x_Symbol] :=
  (m-n+1)*x^(m-2*n+1)*Sin[a+b*x^n]^p/(b^2*n^2*p^2) -
  x^(m-n+1)*Cos[a+b*x^n]*Sin[a+b*x^n]^(p-1)/(b*n*p) +
  Dist[(p-1)/p,Int[x^m*Sin[a+b*x^n]^(p-2),x]] -
  Dist[(m-n+1)*(m-2*n+1)/(b^2*n^2*p^2),Int[x^(m-2*n)*Sin[a+b*x^n]^p,x]] /;
FreeQ[{a,b},x] && IntegersQ[m,n] && RationalQ[p] && p>1 && 0<2*n<m+1


(* ::Subsubsection:: *)
(*Reference: G&R 2.631.3'*)


(* ::Code:: *)
Int[x_^m_.*Cos[a_.+b_.*x_^n_.]^p_,x_Symbol] :=
  (m-n+1)*x^(m-2*n+1)*Cos[a+b*x^n]^p/(b^2*n^2*p^2) +
  x^(m-n+1)*Sin[a+b*x^n]*Cos[a+b*x^n]^(p-1)/(b*n*p) +
  Dist[(p-1)/p,Int[x^m*Cos[a+b*x^n]^(p-2),x]] -
  Dist[(m-n+1)*(m-2*n+1)/(b^2*n^2*p^2),Int[x^(m-2*n)*Cos[a+b*x^n]^p,x]] /;
FreeQ[{a,b},x] && IntegersQ[m,n] && RationalQ[p] && p>1 && 0<2*n<m+1


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Reference: G&R 2.643.1' special case when m-2n+1=0*)


(* ::Subsubsection:: *)
(*Rule: If  p<-1 \[And] p!=-2 \[And] m-2n+1=0, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]x^m Sin[a+b x^n]^p \[DifferentialD]x  \[LongRightArrow]                                                                                                                           *)
(*                           ((x^n Cos[a+b x^n] Sin[a+b x^n]^(p+1))/(b n (p+1)))-(n Sin[a+b x^n]^(p+2))/(b^2 n^2 (p+1) (p+2))+(p+2)/(p+1) \[Integral]x^m Sin[a+b x^n]^(p+2) \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[x_^m_.*Sin[a_.+b_.*x_^n_.]^p_,x_Symbol] :=
  x^n*Cos[a+b*x^n]*Sin[a+b*x^n]^(p+1)/(b*n*(p+1)) - 
  n*Sin[a+b*x^n]^(p+2)/(b^2*n^2*(p+1)*(p+2)) + 
  Dist[(p+2)/(p+1),Int[x^m*Sin[a+b*x^n]^(p+2),x]] /;
FreeQ[{a,b,m,n},x] && RationalQ[p] && p<-1 && p!=-2 && ZeroQ[m-2*n+1]


(* ::Subsubsection:: *)
(*Reference: G&R 2.643.2' special case with m-2n+1=0*)


(* ::Code:: *)
Int[x_^m_.*Cos[a_.+b_.*x_^n_.]^p_,x_Symbol] :=
  -x^n*Sin[a+b*x^n]*Cos[a+b*x^n]^(p+1)/(b*n*(p+1)) - 
  n*Cos[a+b*x^n]^(p+2)/(b^2*n^2*(p+1)*(p+2)) + 
  Dist[(p+2)/(p+1),Int[x^m*Cos[a+b*x^n]^(p+2),x]] /;
FreeQ[{a,b,m,n},x] && RationalQ[p] && p<-1 && p!=-2 && ZeroQ[m-2*n+1]


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Reference: G&R 2.643.1'*)


(* ::Subsubsection:: *)
(*Rule: If  m,n\[Element]\[DoubleStruckCapitalZ] \[And] p<-1 \[And] p!=-2 \[And] 0<2n<m+1, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]x^m Sin[a+b x^n]^p \[DifferentialD]x  \[LongRightArrow]  ((x^(m-n+1) Cos[a+b x^n] Sin[a+b x^n]^(p+1))/(b n (p+1)))-((m-n+1) x^(m-2 n+1) Sin[a+b x^n]^(p+2))/(b^2 n^2 (p+1) (p+2))+  *)
(*                                      (p+2)/(p+1) \[Integral]x^m Sin[a+b x^n]^(p+2) \[DifferentialD]x+((m-n+1) (m-2 n+1))/(b^2 n^2 (p+1) (p+2)) \[Integral]x^(m-2 n) Sin[a+b x^n]^(p+2) \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[x_^m_.*Sin[a_.+b_.*x_^n_.]^p_,x_Symbol] :=
  x^(m-n+1)*Cos[a+b*x^n]*Sin[a+b*x^n]^(p+1)/(b*n*(p+1)) -
  (m-n+1)*x^(m-2*n+1)*Sin[a+b*x^n]^(p+2)/(b^2*n^2*(p+1)*(p+2)) +
  Dist[(p+2)/(p+1),Int[x^m*Sin[a+b*x^n]^(p+2),x]] +
  Dist[(m-n+1)*(m-2*n+1)/(b^2*n^2*(p+1)*(p+2)),Int[x^(m-2*n)*Sin[a+b*x^n]^(p+2),x]] /;
FreeQ[{a,b},x] && IntegersQ[m,n] && RationalQ[p] && p<-1 && p!=-2 && 0<2*n<m+1 


(* ::Subsubsection:: *)
(*Reference: G&R 2.643.2*)


(* ::Code:: *)
Int[x_^m_.*Cos[a_.+b_.*x_^n_.]^p_,x_Symbol] :=
  -x^(m-n+1)*Sin[a+b*x^n]*Cos[a+b*x^n]^(p+1)/(b*n*(p+1)) -
  (m-n+1)*x^(m-2*n+1)*Cos[a+b*x^n]^(p+2)/(b^2*n^2*(p+1)*(p+2)) +
  Dist[(p+2)/(p+1),Int[x^m*Cos[a+b*x^n]^(p+2),x]] +
  Dist[(m-n+1)*(m-2*n+1)/(b^2*n^2*(p+1)*(p+2)),Int[x^(m-2*n)*Cos[a+b*x^n]^(p+2),x]] /;
FreeQ[{a,b},x] && IntegersQ[m,n] && RationalQ[p] && p<-1 && p!=-2 && 0<2*n<m+1 


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Reference: G&R 2.638.1'*)


(* ::Subsubsection:: *)
(*Rule: If  m,n\[Element]\[DoubleStruckCapitalZ] \[And] p>1 \[And] 0<2n<1-m \[And] m+n+1!=0, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]x^m Sin[a+b x^n]^p \[DifferentialD]x  \[LongRightArrow]  ((x^(m+1) Sin[a+b x^n]^p)/(m+1))-(b n p x^(m+n+1) Cos[a+b x^n] Sin[a+b x^n]^(p-1))/((m+1) (m+n+1))-          *)
(*          (b^2 n^2 p^2)/((m+1) (m+n+1)) \[Integral]x^(m+2 n) Sin[a+b x^n]^p \[DifferentialD]x+(b^2 n^2 p (p-1))/((m+1) (m+n+1)) \[Integral]x^(m+2 n) Sin[a+b x^n]^(p-2) \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[x_^m_.*Sin[a_.+b_.*x_^n_.]^p_,x_Symbol] :=
  x^(m+1)*Sin[a+b*x^n]^p/(m+1) - 
  b*n*p*x^(m+n+1)*Cos[a+b*x^n]*Sin[a+b*x^n]^(p-1)/((m+1)*(m+n+1)) - 
  Dist[b^2*n^2*p^2/((m+1)*(m+n+1)),Int[x^(m+2*n)*Sin[a+b*x^n]^p,x]] + 
  Dist[b^2*n^2*p*(p-1)/((m+1)*(m+n+1)),Int[x^(m+2*n)*Sin[a+b*x^n]^(p-2),x]] /;
FreeQ[{a,b},x] && IntegersQ[m,n] && RationalQ[p] && p>1 && 0<2*n<1-m && NonzeroQ[m+n+1]


(* ::Subsubsection:: *)
(*Reference: G&R 2.638.2'*)


(* ::Code:: *)
Int[x_^m_.*Cos[a_.+b_.*x_^n_.]^p_,x_Symbol] :=
  x^(m+1)*Cos[a+b*x^n]^p/(m+1) + 
  b*n*p*x^(m+n+1)*Sin[a+b*x^n]*Cos[a+b*x^n]^(p-1)/((m+1)*(m+n+1)) - 
  Dist[b^2*n^2*p^2/((m+1)*(m+n+1)),Int[x^(m+2*n)*Cos[a+b*x^n]^p,x]] + 
  Dist[b^2*n^2*p*(p-1)/((m+1)*(m+n+1)),Int[x^(m+2*n)*Cos[a+b*x^n]^(p-2),x]] /;
FreeQ[{a,b},x] && IntegersQ[m,n] && RationalQ[p] && p>1 && 0<2*n<1-m && NonzeroQ[m+n+1]


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Derivation: Algebraic expansion*)


(* ::Subsubsection:: *)
(*Basis: Sin[z]=1/2 I E^(-I z)-1/2 I E^(I z)*)


(* ::Subsubsection:: *)
(*Note: Not sure if this is useful or necessary.*)


(* ::Subsubsection:: *)
(*Rule: If  p\[Element]\[DoubleStruckCapitalZ] \[And] p>0 \[And] m+1!=0 \[And] m-n+1!=0, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]x^m Sin[a+b x^n]^p \[DifferentialD]x  \[LongRightArrow]  (I/2)^p\[Integral]x^m (E^(-a I-b I x^n)-E^(a I+b I x^n))^p \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
(* Int[x_^m_.*Sin[a_.+b_.*x_^n_.]^p_,x_Symbol] :=
  Dist[(I/2)^p,Int[x^m*(E^(-a*I-b*I*x^n)-E^(a*I+b*I*x^n))^p,x]] /;
FreeQ[{a,b,m,n},x] && IntegerQ[p] && p>0 && NonzeroQ[m+1] && NonzeroQ[m-n+1] && Not[FractionQ[m] || FractionOrNegativeQ[n]] *)


(* ::PageBreak:: *)
(**)


(* ::Title::Bold::Closed:: *)
(*\[Integral]x^m Sin[a+b (c+d x)^n]^p \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Derivation: Integration by linear substitution*)


(* ::Subsubsection:: *)
(*Rule: If  m\[Element]\[DoubleStruckCapitalZ] \[And] m>0 \[And] p\[Element]\[DoubleStruckCapitalQ], then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]x^m Sin[a+b (c+d x)^n]^p \[DifferentialD]x  \[LongRightArrow]  (1/d)Subst[\[Integral](-(c/d)+x/d)^m Sin[a+b x^n]^p \[DifferentialD]x,x,c+d x]*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[x_^m_.*Sin[a_.+b_.*(c_+d_.*x_)^n_]^p_.,x_Symbol] :=
  Dist[1/d,Subst[Int[(-c/d+x/d)^m*Sin[a+b*x^n]^p,x],x,c+d*x]] /;
FreeQ[{a,b,c,d,n},x] && IntegerQ[m] && m>0 && RationalQ[p]


(* ::Code:: *)
Int[x_^m_.*Cos[a_.+b_.*(c_+d_.*x_)^n_]^p_.,x_Symbol] :=
  Dist[1/d,Subst[Int[(-c/d+x/d)^m*Cos[a+b*x^n]^p,x],x,c+d*x]] /;
FreeQ[{a,b,c,d,n},x] && IntegerQ[m] && m>0 && RationalQ[p]


(* ::PageBreak:: *)
(**)


(* ::Title::Bold::Closed:: *)
(*\[Integral]Sin[a+b x+c x^2]\[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Derivation: Algebraic simplification*)


(* ::Subsubsection:: *)
(*Basis: If  b^2-4 a c=0, then a+b x+c x^2=(b+2 c x)^2/(4 c)*)


(* ::Subsubsection:: *)
(*Rule: If  b^2-4 a c=0, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]Sin[a+b x+c x^2]\[DifferentialD]x  \[LongRightArrow]  \[Integral]Sin[(b+2 c x)^2/(4 c)]\[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[Sin[a_.+b_.*x_+c_.*x_^2],x_Symbol] :=
  Int[Sin[(b+2*c*x)^2/(4*c)],x] /;
FreeQ[{a,b,c},x] && ZeroQ[b^2-4*a*c]


(* ::Code:: *)
Int[Cos[a_.+b_.*x_+c_.*x_^2],x_Symbol] :=
  Int[Cos[(b+2*c*x)^2/(4*c)],x] /;
FreeQ[{a,b,c},x] && ZeroQ[b^2-4*a*c]


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Derivation: Algebraic expansion*)


(* ::Subsubsection:: *)
(*Basis: a+b x+c x^2=(b+2 c x)^2/(4 c)-(b^2-4 a c)/(4 c)*)


(* ::Subsubsection:: *)
(*Basis: Sin[z-w]=Cos[w] Sin[z]-Sin[w] Cos[z]*)


(* ::Subsubsection:: *)
(*Rule: If  b^2-4 a c!=0, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]Sin[a+b x+c x^2]\[DifferentialD]x  \[LongRightArrow]  Cos[(b^2-4 a c)/(4 c)] \[Integral]Sin[(b+2 c x)^2/(4 c)]\[DifferentialD]x-Sin[(b^2-4 a c)/(4 c)] \[Integral]Cos[(b+2 c x)^2/(4 c)]\[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[Sin[a_.+b_.*x_+c_.*x_^2],x_Symbol] :=
  Cos[(b^2-4*a*c)/(4*c)]*Int[Sin[(b+2*c*x)^2/(4*c)],x] - 
  Sin[(b^2-4*a*c)/(4*c)]*Int[Cos[(b+2*c*x)^2/(4*c)],x] /;
FreeQ[{a,b,c},x] && NonzeroQ[b^2-4*a*c]


(* ::Code:: *)
Int[Cos[a_.+b_.*x_+c_.*x_^2],x_Symbol] :=
  Cos[(b^2-4*a*c)/(4*c)]*Int[Cos[(b+2*c*x)^2/(4*c)],x] + 
  Sin[(b^2-4*a*c)/(4*c)]*Int[Sin[(b+2*c*x)^2/(4*c)],x] /;
FreeQ[{a,b,c},x] && NonzeroQ[b^2-4*a*c]


(* ::PageBreak:: *)
(**)


(* ::Title::Bold::Closed:: *)
(*\[Integral](d+e x)^m Sin[a+b x+c x^2]\[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Rule: If  b e-2c d=0, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral](d+e x)Sin[a+b x+c x^2]\[DifferentialD]x  \[LongRightArrow]  -((e Cos[a+b x+c x^2])/(2 c))*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[(d_.+e_.*x_)*Sin[a_.+b_.*x_+c_.*x_^2],x_Symbol] :=
  -e*Cos[a+b*x+c*x^2]/(2*c) /;
FreeQ[{a,b,c,d,e},x] && ZeroQ[b*e-2*c*d]


(* ::Code:: *)
Int[(d_.+e_.*x_)*Cos[a_.+b_.*x_+c_.*x_^2],x_Symbol] :=
  e*Sin[a+b*x+c*x^2]/(2*c) /;
FreeQ[{a,b,c,d,e},x] && ZeroQ[b*e-2*c*d]


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Rule: If  b e-2c d!=0, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral](d+e x)Sin[a+b x+c x^2]\[DifferentialD]x  \[LongRightArrow]  -((e Cos[a+b x+c x^2])/(2 c))-(b e-2 c d)/(2 c) \[Integral]Sin[a+b x+c x^2]\[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[(d_.+e_.*x_)*Sin[a_.+b_.*x_+c_.*x_^2],x_Symbol] :=
  -e*Cos[a+b*x+c*x^2]/(2*c) -
  Dist[(b*e-2*c*d)/(2*c),Int[Sin[a+b*x+c*x^2],x]] /;
FreeQ[{a,b,c,d,e},x] && NonzeroQ[b*e-2*c*d]


(* ::Code:: *)
Int[(d_.+e_.*x_)*Cos[a_.+b_.*x_+c_.*x_^2],x_Symbol] :=
  e*Sin[a+b*x+c*x^2]/(2*c) -
  Dist[(b*e-2*c*d)/(2*c),Int[Cos[a+b*x+c*x^2],x]] /;
FreeQ[{a,b,c,d,e},x] && NonzeroQ[b*e-2*c*d]


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Rule: If  m>1 \[And] b e-2c d=0, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral](d+e x)^m Sin[a+b x+c x^2]\[DifferentialD]x  \[LongRightArrow]                                                                                                 *)
(*                       -((e (d+e x)^(m-1) Cos[a+b x+c x^2])/(2 c))+(e^2 (m-1))/(2 c) \[Integral](d+e x)^(m-2) Cos[a+b x+c x^2]\[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[(d_.+e_.*x_)^m_*Sin[a_.+b_.*x_+c_.*x_^2],x_Symbol] :=
  -e*(d+e*x)^(m-1)*Cos[a+b*x+c*x^2]/(2*c) + 
  Dist[e^2*(m-1)/(2*c),Int[(d+e*x)^(m-2)*Cos[a+b*x+c*x^2],x]] /;
FreeQ[{a,b,c,d,e},x] && RationalQ[m] && m>1 && ZeroQ[b*e-2*c*d]


(* ::Code:: *)
Int[(d_.+e_.*x_)^m_*Cos[a_.+b_.*x_+c_.*x_^2],x_Symbol] :=
  e*(d+e*x)^(m-1)*Sin[a+b*x+c*x^2]/(2*c) - 
  Dist[e^2*(m-1)/(2*c),Int[(d+e*x)^(m-2)*Sin[a+b*x+c*x^2],x]] /;
FreeQ[{a,b,c,d,e},x] && RationalQ[m] && m>1 && ZeroQ[b*e-2*c*d]


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Rule: If  m>1 \[And] b e-2c d!=0, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral](d+e x)^m Sin[a+b x+c x^2]\[DifferentialD]x  \[LongRightArrow]  -((e (d+e x)^(m-1) Cos[a+b x+c x^2])/(2 c))-                                                *)
(*                (b e-2 c d)/(2 c) \[Integral](d+e x)^(m-1) Sin[a+b x+c x^2]\[DifferentialD]x+(e^2 (m-1))/(2 c) \[Integral](d+e x)^(m-2) Cos[a+b x+c x^2]\[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[(d_.+e_.*x_)^m_*Sin[a_.+b_.*x_+c_.*x_^2],x_Symbol] :=
  -e*(d+e*x)^(m-1)*Cos[a+b*x+c*x^2]/(2*c) - 
  Dist[(b*e-2*c*d)/(2*c),Int[(d+e*x)^(m-1)*Sin[a+b*x+c*x^2],x]] + 
  Dist[e^2*(m-1)/(2*c),Int[(d+e*x)^(m-2)*Cos[a+b*x+c*x^2],x]] /;
FreeQ[{a,b,c,d,e},x] && RationalQ[m] && m>1 && NonzeroQ[b*e-2*c*d]


(* ::Code:: *)
Int[(d_.+e_.*x_)^m_*Cos[a_.+b_.*x_+c_.*x_^2],x_Symbol] :=
  e*(d+e*x)^(m-1)*Sin[a+b*x+c*x^2]/(2*c) - 
  Dist[(b*e-2*c*d)/(2*c),Int[(d+e*x)^(m-1)*Cos[a+b*x+c*x^2],x]] - 
  Dist[e^2*(m-1)/(2*c),Int[(d+e*x)^(m-2)*Sin[a+b*x+c*x^2],x]] /;
FreeQ[{a,b,c,d,e},x] && RationalQ[m] && m>1 && NonzeroQ[b*e-2*c*d]


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Rule: If  m<-1 \[And] b e-2c d=0, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral](d+e x)^m Sin[a+b x+c x^2]\[DifferentialD]x  \[LongRightArrow]                                                                                                                *)
(*                               (((d+e x)^(m+1) Sin[a+b x+c x^2])/(e (m+1)))-(2 c)/(e^2 (m+1)) \[Integral](d+e x)^(m+2) Cos[a+b x+c x^2]\[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[(d_.+e_.*x_)^m_*Sin[a_.+b_.*x_+c_.*x_^2],x_Symbol] :=
  (d+e*x)^(m+1)*Sin[a+b*x+c*x^2]/(e*(m+1)) -
  Dist[2*c/(e^2*(m+1)),Int[(d+e*x)^(m+2)*Cos[a+b*x+c*x^2],x]] /;
FreeQ[{a,b,c,d,e},x] && RationalQ[m] && m<-1 && ZeroQ[b*e-2*c*d]


(* ::Code:: *)
Int[(d_.+e_.*x_)^m_*Cos[a_.+b_.*x_+c_.*x_^2],x_Symbol] :=
  (d+e*x)^(m+1)*Cos[a+b*x+c*x^2]/(e*(m+1)) + 
  Dist[2*c/(e^2*(m+1)),Int[(d+e*x)^(m+2)*Sin[a+b*x+c*x^2],x]] /;
FreeQ[{a,b,c,d,e},x] && RationalQ[m] && m<-1 && ZeroQ[b*e-2*c*d]


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Rule: If  m<-1 \[And] b e-2c d!=0, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral](d+e x)^m Sin[a+b x+c x^2]\[DifferentialD]x  \[LongRightArrow]  (((d+e x)^(m+1) Sin[a+b x+c x^2])/(e (m+1)))-                                                *)
(*           (b e-2 c d)/(e^2 (m+1)) \[Integral](d+e x)^(m+1) Cos[a+b x+c x^2]\[DifferentialD]x-(2 c)/(e^2 (m+1)) \[Integral](d+e x)^(m+2) Cos[a+b x+c x^2]\[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[(d_.+e_.*x_)^m_*Sin[a_.+b_.*x_+c_.*x_^2],x_Symbol] :=
  (d+e*x)^(m+1)*Sin[a+b*x+c*x^2]/(e*(m+1)) -
  Dist[(b*e-2*c*d)/(e^2*(m+1)),Int[(d+e*x)^(m+1)*Cos[a+b*x+c*x^2],x]] -
  Dist[2*c/(e^2*(m+1)),Int[(d+e*x)^(m+2)*Cos[a+b*x+c*x^2],x]] /;
FreeQ[{a,b,c,d,e},x] && RationalQ[m] && m<-1 && NonzeroQ[b*e-2*c*d]


(* ::Code:: *)
Int[(d_.+e_.*x_)^m_*Cos[a_.+b_.*x_+c_.*x_^2],x_Symbol] :=
  (d+e*x)^(m+1)*Cos[a+b*x+c*x^2]/(e*(m+1)) + 
  Dist[(b*e-2*c*d)/(e^2*(m+1)),Int[(d+e*x)^(m+1)*Sin[a+b*x+c*x^2],x]] +
  Dist[2*c/(e^2*(m+1)),Int[(d+e*x)^(m+2)*Sin[a+b*x+c*x^2],x]] /;
FreeQ[{a,b,c,d,e},x] && RationalQ[m] && m<-1 && NonzeroQ[b*e-2*c*d]


(* ::PageBreak:: *)
(**)


(* ::Title::Bold::Closed:: *)
(*\[Integral]Sin[a+b Log[c x^n]]^p \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Rule: If  1+b^2 n^2!=0, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]Sin[a+b Log[c x^n]]\[DifferentialD]x  \[LongRightArrow]  ((x Sin[a+b Log[c x^n]])/(1+b^2 n^2))-(b n x Cos[a+b Log[c x^n]])/(1+b^2 n^2)*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[Sin[a_.+b_.*Log[c_.*x_^n_.]],x_Symbol] :=
  x*Sin[a+b*Log[c*x^n]]/(1+b^2*n^2) -
  b*n*x*Cos[a+b*Log[c*x^n]]/(1+b^2*n^2) /;
FreeQ[{a,b,c,n},x] && NonzeroQ[1+b^2*n^2]


(* ::Code:: *)
Int[Cos[a_.+b_.*Log[c_.*x_^n_.]],x_Symbol] :=
  x*Cos[a+b*Log[c*x^n]]/(1+b^2*n^2) +
  b*n*x*Sin[a+b*Log[c*x^n]]/(1+b^2*n^2) /;
FreeQ[{a,b,c,n},x] && NonzeroQ[1+b^2*n^2]


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Rule: If  p>1 \[And] 1+b^2 n^2 p^2!=0, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]Sin[a+b Log[c x^n]]^p \[DifferentialD]x  \[LongRightArrow]  ((x Sin[a+b Log[c x^n]]^p)/(1+b^2 n^2 p^2))-                                                                                *)
(*   (b n p x Cos[a+b Log[c x^n]] Sin[a+b Log[c x^n]]^(p-1))/(1+b^2 n^2 p^2)+(b^2 n^2 p (p-1))/(1+b^2 n^2 p^2) \[Integral]Sin[a+b Log[c x^n]]^(p-2) \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[Sin[a_.+b_.*Log[c_.*x_^n_.]]^p_,x_Symbol] :=
  x*Sin[a+b*Log[c*x^n]]^p/(1+b^2*n^2*p^2) -
  b*n*p*x*Cos[a+b*Log[c*x^n]]*Sin[a+b*Log[c*x^n]]^(p-1)/(1+b^2*n^2*p^2) +
  Dist[b^2*n^2*p*(p-1)/(1+b^2*n^2*p^2),Int[Sin[a+b*Log[c*x^n]]^(p-2),x]] /;
FreeQ[{a,b,c,n},x] && RationalQ[p] && p>1 && NonzeroQ[1+b^2*n^2*p^2]


(* ::Code:: *)
Int[Cos[a_.+b_.*Log[c_.*x_^n_.]]^p_,x_Symbol] :=
  x*Cos[a+b*Log[c*x^n]]^p/(1+b^2*n^2*p^2) +
  b*n*p*x*Cos[a+b*Log[c*x^n]]^(p-1)*Sin[a+b*Log[c*x^n]]/(1+b^2*n^2*p^2) +
  Dist[b^2*n^2*p*(p-1)/(1+b^2*n^2*p^2),Int[Cos[a+b*Log[c*x^n]]^(p-2),x]] /;
FreeQ[{a,b,c,n},x] && RationalQ[p] && p>1 && NonzeroQ[1+b^2*n^2*p^2]


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Rule: If  p!=-1 \[And] p!=-2 \[And] 1+b^2 n^2 (p+2)^2=0, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]Sin[a+b Log[c x^n]]^p \[DifferentialD]x  \[LongRightArrow]  ((x Cot[a+b Log[c x^n]] Sin[a+b Log[c x^n]]^(p+2))/(b n (p+1)))-(x Sin[a+b Log[c x^n]]^(p+2))/(b^2 n^2 (p+1) (p+2))*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[Sin[a_.+b_.*Log[c_.*x_^n_.]]^p_,x_Symbol] :=
  x*Cot[a+b*Log[c*x^n]]*Sin[a+b*Log[c*x^n]]^(p+2)/(b*n*(p+1)) -
  x*Sin[a+b*Log[c*x^n]]^(p+2)/(b^2*n^2*(p+1)*(p+2)) /;
FreeQ[{a,b,c,n,p},x] && NonzeroQ[p+1] && NonzeroQ[p+2] && ZeroQ[1+b^2*n^2*(p+2)^2]


(* ::Code:: *)
Int[Cos[a_.+b_.*Log[c_.*x_^n_.]]^p_,x_Symbol] :=
  -x*Tan[a+b*Log[c*x^n]]*Cos[a+b*Log[c*x^n]]^(p+2)/(b*n*(p+1)) -
  x*Cos[a+b*Log[c*x^n]]^(p+2)/(b^2*n^2*(p+1)*(p+2)) /;
FreeQ[{a,b,c,n,p},x] && NonzeroQ[p+1] && NonzeroQ[p+2] && ZeroQ[1+b^2*n^2*(p+2)^2]


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Rule: If  p<-1 \[And] p!=-2 \[And] 1+b^2 n^2 (p+2)^2!=0, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]Sin[a+b Log[c x^n]]^p \[DifferentialD]x  \[LongRightArrow]  ((x Cot[a+b Log[c x^n]] Sin[a+b Log[c x^n]]^(p+2))/(b n (p+1)))-                  *)
(*                      (x Sin[a+b Log[c x^n]]^(p+2))/(b^2 n^2 (p+1) (p+2))+(1+b^2 n^2 (p+2)^2)/(b^2 n^2 (p+1) (p+2)) \[Integral]Sin[a+b Log[c x^n]]^(p+2) \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[Sin[a_.+b_.*Log[c_.*x_^n_.]]^p_,x_Symbol] :=
  x*Cot[a+b*Log[c*x^n]]*Sin[a+b*Log[c*x^n]]^(p+2)/(b*n*(p+1)) -
  x*Sin[a+b*Log[c*x^n]]^(p+2)/(b^2*n^2*(p+1)*(p+2)) +
  Dist[(1+b^2*n^2*(p+2)^2)/(b^2*n^2*(p+1)*(p+2)),Int[Sin[a+b*Log[c*x^n]]^(p+2),x]] /;
FreeQ[{a,b,c,n},x] && RationalQ[p] && p<-1 && p!=-2 && NonzeroQ[1+b^2*n^2*(p+2)^2]


(* ::Code:: *)
Int[Cos[a_.+b_.*Log[c_.*x_^n_.]]^p_,x_Symbol] :=
  -x*Tan[a+b*Log[c*x^n]]*Cos[a+b*Log[c*x^n]]^(p+2)/(b*n*(p+1)) -
  x*Cos[a+b*Log[c*x^n]]^(p+2)/(b^2*n^2*(p+1)*(p+2)) +
  Dist[(1+b^2*n^2*(p+2)^2)/(b^2*n^2*(p+1)*(p+2)),Int[Cos[a+b*Log[c*x^n]]^(p+2),x]] /;
FreeQ[{a,b,c,n},x] && RationalQ[p] && p<-1 && p!=-2 && NonzeroQ[1+b^2*n^2*(p+2)^2]


(* ::PageBreak:: *)
(**)


(* ::Title::Bold::Closed:: *)
(*\[Integral]x^m Sin[a+b Log[c x^n]]^p \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Rule: If  b^2 n^2+(m+1)^2!=0 \[And] m+1!=0, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]x^m Sin[a+b Log[c x^n]]\[DifferentialD]x  \[LongRightArrow]  (((m+1) x^(m+1) Sin[a+b Log[c x^n]])/(b^2 n^2+(m+1)^2))-(b n x^(m+1) Cos[a+b Log[c x^n]])/(b^2 n^2+(m+1)^2)*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[x_^m_.*Sin[a_.+b_.*Log[c_.*x_^n_.]],x_Symbol] :=
  (m+1)*x^(m+1)*Sin[a+b*Log[c*x^n]]/(b^2*n^2+(m+1)^2) -
  b*n*x^(m+1)*Cos[a+b*Log[c*x^n]]/(b^2*n^2+(m+1)^2) /;
FreeQ[{a,b,c,m,n},x] && NonzeroQ[b^2*n^2+(m+1)^2] && NonzeroQ[m+1]


(* ::Code:: *)
Int[x_^m_.*Cos[a_.+b_.*Log[c_.*x_^n_.]],x_Symbol] :=
  (m+1)*x^(m+1)*Cos[a+b*Log[c*x^n]]/(b^2*n^2+(m+1)^2) +
  b*n*x^(m+1)*Sin[a+b*Log[c*x^n]]/(b^2*n^2+(m+1)^2) /;
FreeQ[{a,b,c,m,n},x] && NonzeroQ[b^2*n^2+(m+1)^2] && NonzeroQ[m+1]


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Rule: If  p>1 \[And] b^2 n^2 p^2+(m+1)^2!=0 \[And] m+1!=0, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]x^m Sin[a+b Log[c x^n]]^p \[DifferentialD]x  \[LongRightArrow]  (((m+1) x^(m+1) Sin[a+b Log[c x^n]]^p)/(b^2 n^2 p^2+(m+1)^2))-                                                                     *)
(* (b n p x^(m+1) Cos[a+b Log[c x^n]] Sin[a+b Log[c x^n]]^(p-1))/(b^2 n^2 p^2+(m+1)^2)+(b^2 n^2 p (p-1))/(b^2 n^2 p^2+(m+1)^2) \[Integral]x^m Sin[a+b Log[c x^n]]^(p-2) \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[x_^m_.*Sin[a_.+b_.*Log[c_.*x_^n_.]]^p_,x_Symbol] :=
  (m+1)*x^(m+1)*Sin[a+b*Log[c*x^n]]^p/(b^2*n^2*p^2+(m+1)^2) -
  b*n*p*x^(m+1)*Cos[a+b*Log[c*x^n]]*Sin[a+b*Log[c*x^n]]^(p-1)/(b^2*n^2*p^2+(m+1)^2) +
  Dist[b^2*n^2*p*(p-1)/(b^2*n^2*p^2+(m+1)^2),Int[x^m*Sin[a+b*Log[c*x^n]]^(p-2),x]] /;
FreeQ[{a,b,c,m,n},x] && RationalQ[p] && p>1 && NonzeroQ[b^2*n^2*p^2+(m+1)^2] && NonzeroQ[m+1]


(* ::Code:: *)
Int[x_^m_.*Cos[a_.+b_.*Log[c_.*x_^n_.]]^p_,x_Symbol] :=
  (m+1)*x^(m+1)*Cos[a+b*Log[c*x^n]]^p/(b^2*n^2*p^2+(m+1)^2) +
  b*n*p*x^(m+1)*Sin[a+b*Log[c*x^n]]*Cos[a+b*Log[c*x^n]]^(p-1)/(b^2*n^2*p^2+(m+1)^2) +
  Dist[b^2*n^2*p*(p-1)/(b^2*n^2*p^2+(m+1)^2),Int[x^m*Cos[a+b*Log[c*x^n]]^(p-2),x]] /;
FreeQ[{a,b,c,m,n},x] && RationalQ[p] && p>1 && NonzeroQ[b^2*n^2*p^2+(m+1)^2] && NonzeroQ[m+1]


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Rule: If  p<-1 \[And] p!=-2 \[And] m+1!=0, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]x^m Sin[a+b Log[c x^n]]^p \[DifferentialD]x  \[LongRightArrow]  ((x^(m+1) Cot[a+b Log[c x^n]] Sin[a+b Log[c x^n]]^(p+2))/(b n (p+1)))-                           *)
(*        ((m+1) x^(m+1) Sin[a+b Log[c x^n]]^(p+2))/(b^2 n^2 (p+1) (p+2))+(b^2 n^2 (p+2)^2+(m+1)^2)/(b^2 n^2 (p+1) (p+2)) \[Integral]x^m Sin[a+b Log[c x^n]]^(p+2) \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[x_^m_.*Sin[a_.+b_.*Log[c_.*x_^n_.]]^p_,x_Symbol] :=
  x^(m+1)*Cot[a+b*Log[c*x^n]]*Sin[a+b*Log[c*x^n]]^(p+2)/(b*n*(p+1)) -
  (m+1)*x^(m+1)*Sin[a+b*Log[c*x^n]]^(p+2)/(b^2*n^2*(p+1)*(p+2)) +
  Dist[(b^2*n^2*(p+2)^2+(m+1)^2)/(b^2*n^2*(p+1)*(p+2)),Int[x^m*Sin[a+b*Log[c*x^n]]^(p+2),x]] /;
FreeQ[{a,b,c,m,n},x] && RationalQ[p] && p<-1 && p!=-2 && NonzeroQ[m+1]


(* ::Code:: *)
Int[x_^m_.*Cos[a_.+b_.*Log[c_.*x_^n_.]]^p_,x_Symbol] :=
  -x^(m+1)*Tan[a+b*Log[c*x^n]]*Cos[a+b*Log[c*x^n]]^(p+2)/(b*n*(p+1)) -
  (m+1)*x^(m+1)*Cos[a+b*Log[c*x^n]]^(p+2)/(b^2*n^2*(p+1)*(p+2)) +
  Dist[(b^2*n^2*(p+2)^2+(m+1)^2)/(b^2*n^2*(p+1)*(p+2)),Int[x^m*Cos[a+b*Log[c*x^n]]^(p+2),x]] /;
FreeQ[{a,b,c,m,n},x] && RationalQ[p] && p<-1 && p!=-2 && NonzeroQ[m+1]


(* ::PageBreak:: *)
(**)


(* ::Title::Bold::Closed:: *)
(*\[Integral]Sin[a x^n Log[b x]^p] Log[b x]^p \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Rule: If  p>0, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]Sin[a x Log[b x]^p] Log[b x]^p \[DifferentialD]x  \[LongRightArrow]  -(Cos[a x Log[b x]^p]/a)-p \[Integral]Sin[a x Log[b x]^p] Log[b x]^(p-1) \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[Sin[a_.*x_*Log[b_.*x_]^p_.]*Log[b_.*x_]^p_.,x_Symbol] :=
  -Cos[a*x*Log[b*x]^p]/a -
  Dist[p,Int[Sin[a*x*Log[b*x]^p]*Log[b*x]^(p-1),x]] /;
FreeQ[{a,b},x] && RationalQ[p] && p>0


(* ::Code:: *)
Int[Cos[a_.*x_*Log[b_.*x_]^p_.]*Log[b_.*x_]^p_.,x_Symbol] :=
  Sin[a*x*Log[b*x]^p]/a -
  Dist[p,Int[Cos[a*x*Log[b*x]^p]*Log[b*x]^(p-1),x]] /;
FreeQ[{a,b},x] && RationalQ[p] && p>0


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Rule: If  p>0, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]Sin[a x^n Log[b x]^p] Log[b x]^p \[DifferentialD]x  \[LongRightArrow]  -(Cos[a x^n Log[b x]^p]/(a n x^(n-1)))-                              *)
(*                       p/n \[Integral]Sin[a x^n Log[b x]^p] Log[b x]^(p-1) \[DifferentialD]x-(n-1)/(a n) \[Integral]Cos[a x^n Log[b x]^p]/x^n \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[Sin[a_.*x_^n_*Log[b_.*x_]^p_.]*Log[b_.*x_]^p_.,x_Symbol] :=
  -Cos[a*x^n*Log[b*x]^p]/(a*n*x^(n-1)) -
  Dist[p/n,Int[Sin[a*x^n*Log[b*x]^p]*Log[b*x]^(p-1),x]] -
  Dist[(n-1)/(a*n),Int[Cos[a*x^n*Log[b*x]^p]/x^n,x]] /;
FreeQ[{a,b},x] && RationalQ[{n,p}] && p>0


(* ::Code:: *)
Int[Cos[a_.*x_^n_*Log[b_.*x_]^p_.]*Log[b_.*x_]^p_.,x_Symbol] :=
  Sin[a*x^n*Log[b*x]^p]/(a*n*x^(n-1)) -
  Dist[p/n,Int[Cos[a*x^n*Log[b*x]^p]*Log[b*x]^(p-1),x]] +
  Dist[(n-1)/(a*n),Int[Sin[a*x^n*Log[b*x]^p]/x^n,x]] /;
FreeQ[{a,b},x] && RationalQ[{n,p}] && p>0


(* ::PageBreak:: *)
(**)


(* ::Title::Bold::Closed:: *)
(*\[Integral]x^m Sin[a x^n Log[b x]^p] Log[b x]^p \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Rule: If  p>0 \[And] m-n+1=0, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]x^m Sin[a x^n Log[b x]^p] Log[b x]^p \[DifferentialD]x  \[LongRightArrow]  -(Cos[a x^n Log[b x]^p]/(a n))-p/n \[Integral]x^m Sin[a x^n Log[b x]^p] Log[b x]^(p-1) \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[x_^m_.*Sin[a_.*x_^n_.*Log[b_.*x_]^p_.]*Log[b_.*x_]^p_.,x_Symbol] :=
  -Cos[a*x^n*Log[b*x]^p]/(a*n) -
  Dist[p/n,Int[x^m*Sin[a*x^n*Log[b*x]^p]*Log[b*x]^(p-1),x]] /;
FreeQ[{a,b},x] && RationalQ[{m,n,p}] && p>0 && ZeroQ[m-n+1]


(* ::Code:: *)
Int[x_^m_.*Cos[a_.*x_^n_.*Log[b_.*x_]^p_.]*Log[b_.*x_]^p_.,x_Symbol] :=
  Sin[a*x^n*Log[b*x]^p]/(a*n) -
  Dist[p/n,Int[x^m*Cos[a*x^n*Log[b*x]^p]*Log[b*x]^(p-1),x]] /;
FreeQ[{a,b},x] && RationalQ[{m,n,p}] && p>0 && ZeroQ[m-n+1]


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Rule: If  p>0 \[And] m-n+1!=0, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]x^m Sin[a x^n Log[b x]^p] Log[b x]^p \[DifferentialD]x  \[LongRightArrow]  -((x^(m-n+1) Cos[a x^n Log[b x]^p])/(a n))-                                *)
(*           p/n \[Integral]x^m Sin[a x^n Log[b x]^p] Log[b x]^(p-1) \[DifferentialD]x+(m-n+1)/(a n) \[Integral]x^(m-n) Cos[a x^n Log[b x]^p]\[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[x_^m_.*Sin[a_.*x_^n_.*Log[b_.*x_]^p_.]*Log[b_.*x_]^p_.,x_Symbol] :=
  -x^(m-n+1)*Cos[a*x^n*Log[b*x]^p]/(a*n) -
  Dist[p/n,Int[x^m*Sin[a*x^n*Log[b*x]^p]*Log[b*x]^(p-1),x]] +
  Dist[(m-n+1)/(a*n),Int[x^(m-n)*Cos[a*x^n*Log[b*x]^p],x]] /;
FreeQ[{a,b},x] && RationalQ[{m,n,p}] && p>0 && NonzeroQ[m-n+1]


(* ::Code:: *)
Int[x_^m_*Cos[a_.*x_^n_.*Log[b_.*x_]^p_.]*Log[b_.*x_]^p_.,x_Symbol] :=
  x^(m-n+1)*Sin[a*x^n*Log[b*x]^p]/(a*n) -
  Dist[p/n,Int[x^m*Cos[a*x^n*Log[b*x]^p]*Log[b*x]^(p-1),x]] -
  Dist[(m-n+1)/(a*n),Int[x^(m-n)*Sin[a*x^n*Log[b*x]^p],x]] /;
FreeQ[{a,b},x] && RationalQ[{m,n,p}] && p>0 && NonzeroQ[m-n+1]


(* ::PageBreak:: *)
(**)


(* ::Title::Bold::Closed:: *)
(*\[Integral]u Sin[a+b x]^n \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Derivation: Algebraic expansion*)


(* ::Subsubsection:: *)
(*Basis: Sin[z]^2=1/2-1/2 Cos[2 z]*)


(* ::Subsubsection:: *)
(*Rule: If  (n-1)/2\[NotElement]\[DoubleStruckCapitalZ], then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]Sin[a/2+(b x)/2]^2 Sin[a+b x]^n \[DifferentialD]x  \[LongRightArrow]  (1/2)\[Integral]Sin[a+b x]^n \[DifferentialD]x-1/2 \[Integral]Cos[a+b x]Sin[a+b x]^n \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[Sin[c_.+d_.*x_]^2*Sin[a_.+b_.*x_]^n_.,x_Symbol] :=
  Dist[1/2,Int[Sin[a+b*x]^n,x]] - 
  Dist[1/2,Int[Cos[a+b*x]*Sin[a+b*x]^n,x]] /;
FreeQ[{a,b,c,d},x] && ZeroQ[c-a/2] && ZeroQ[d-b/2] && Not[OddQ[n]]


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Derivation: Algebraic expansion*)


(* ::Subsubsection:: *)
(*Basis: Cos[z]^2=1/2+1/2 Cos[2 z]*)


(* ::Subsubsection:: *)
(*Rule: If  (n-1)/2\[NotElement]\[DoubleStruckCapitalZ], then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]Cos[a/2+(b x)/2]^2 Sin[a+b x]^n \[DifferentialD]x  \[LongRightArrow]  (1/2)\[Integral]Sin[a+b x]^n \[DifferentialD]x+1/2 \[Integral]Cos[a+b x]Sin[a+b x]^n \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[Cos[c_.+d_.*x_]^2*Sin[a_.+b_.*x_]^n_.,x_Symbol] :=
  Dist[1/2,Int[Sin[a+b*x]^n,x]] + 
  Dist[1/2,Int[Cos[a+b*x]*Sin[a+b*x]^n,x]] /;
FreeQ[{a,b,c,d},x] && ZeroQ[c-a/2] && ZeroQ[d-b/2] && Not[OddQ[n]]


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Derivation: Algebraic simplification*)


(* ::Subsubsection:: *)
(*Basis: Sin[2 z]=2 Sin[z] Cos[z]*)


(* ::Subsubsection:: *)
(*Rule: If  n\[Element]\[DoubleStruckCapitalZ] and u is a function of trig functions of a/2+(b x)/2, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]u Sin[a+b x]^n \[DifferentialD]x  \[LongRightArrow]  2^n\[Integral]u Cos[a/2+(b x)/2]^n Sin[a/2+(b x)/2]^n \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[u_*Sin[a_.+b_.*x_]^n_.,x_Symbol] :=
  Dist[2^n,Int[u*Cos[a/2+b*x/2]^n*Sin[a/2+b*x/2]^n,x]] /;
FreeQ[{a,b},x] && IntegerQ[n] && ZeroQ[a/2+b*x/2-FunctionOfTrig[u,x]]


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Derivation: Algebraic simplification and piecewise constant extraction*)


(* ::Subsubsection:: *)
(*Basis: Sin[2 z]=2 Sin[z] Cos[z]*)


(* ::Subsubsection:: *)
(*Basis: \!\( *)
(*\*SubscriptBox[\(\[PartialD]\), \(x\)]*)
(*\*FractionBox[*)
(*SuperscriptBox[\(Sin[a + b\ x]\), \(n\)], \( *)
(*\*SuperscriptBox[\(Sin[*)
(*\*FractionBox[\(a\), \(2\)] + *)
(*\*FractionBox[\(b\ x\), \(2\)]]\), \(n\)]\ *)
(*\*SuperscriptBox[\(Cos[*)
(*\*FractionBox[\(a\), \(2\)] + *)
(*\*FractionBox[\(b\ x\), \(2\)]]\), \(n\)]\)]\)=0*)


(* ::Subsubsection:: *)
(*Rule: If  n\[Element]\[DoubleStruckCapitalZ] and u is a function of trig functions of a/2+(b x)/2, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]u Sin[a+b x]^n \[DifferentialD]x  \[LongRightArrow]  (Sin[a+b x]^n/(Sin[a/2+(b x)/2]^n Cos[a/2+(b x)/2]^n))\[Integral]u Cos[a/2+(b x)/2]^n Sin[a/2+(b x)/2]^n \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
(* Int[u_*Sin[a_.+b_.*x_]^n_,x_Symbol] :=
  Sin[a+b*x]^n/(Sin[a/2+b*x/2]^n*Cos[a/2+b*x/2]^n)*Int[u*Cos[a/2+b*x/2]^n*Sin[a/2+b*x/2]^n,x] /;
FreeQ[{a,b},x] && FractionQ[n] && ZeroQ[a/2+b*x/2-FunctionOfTrig[u,x]] *)


(* ::PageBreak:: *)
(**)


(* ::Title::Bold::Closed:: *)
(*\[Integral]u Sin[v]^2 \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Derivation: Algebraic expansion*)


(* ::Subsubsection:: *)
(*Basis: Sin[z]^2=1/2-1/2 Cos[2 z]*)


(* ::Subsubsection:: *)
(*Rule: If u is a function of trig functions of 2 v, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]u Sin[v]^2 \[DifferentialD]x  \[LongRightArrow]  (1/2)\[Integral]u \[DifferentialD]x-1/2 \[Integral]u Cos[2 v]\[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
(* Int[u_*Sin[v_]^2,x_Symbol] :=
  Dist[1/2,Int[u,x]] - 
  Dist[1/2,Int[u*Cos[2*v],x]] /;
FunctionOfTrigQ[u,2*v,x] *)


(* ::Code:: *)
(* Int[u_*Cos[v_]^2,x_Symbol] :=
  Dist[1/2,Int[u,x]] + 
  Dist[1/2,Int[u*Cos[2*v],x]] /;
FunctionOfTrigQ[u,2*v,x] *)


(* ::PageBreak:: *)
(**)
