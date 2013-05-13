(* ::Package:: *)

(* ::Title::Bold::Closed:: *)
(*\[Integral]x^m (a+b Sinh[c+d x])^n \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Derivation: Algebraic simplification*)


(* ::Subsubsection:: *)
(*Basis: If  a^2+b^2=0, then a+b Sinh[z]=2 a Cosh[-((\[Pi] a)/(4 b))+z/2]^2*)


(* ::Subsubsection:: *)
(*Rule: If  a^2+b^2=0 \[And] m\[Element]\[DoubleStruckCapitalQ] \[And] n\[Element]\[DoubleStruckCapitalZ] \[And] n<0, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]x^m (a+b Sinh[c+d x])^n \[DifferentialD]x  \[LongRightArrow]  (2 a)^n\[Integral]x^m Cosh[-((\[Pi] a)/(4 b))+c/2+(d x)/2]^(2 n) \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[x_^m_.*(a_+b_.*Sinh[c_.+d_.*x_])^n_,x_Symbol] :=
  Dist[(2*a)^n,Int[x^m*Cosh[-Pi*a/(4*b)+c/2+d*x/2]^(2*n),x]] /;
FreeQ[{a,b,c,d},x] && ZeroQ[a^2+b^2] && RationalQ[m] && IntegerQ[n] && n<0


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Derivation: Algebraic simplification and piecewise constant extraction*)


(* ::Subsubsection:: *)
(*Basis: If  a^2+b^2=0, then a+b Sinh[z]=2 a Cosh[-((\[Pi] a)/(4 b))+z/2]^2*)


(* ::Subsubsection:: *)
(*Basis: If  a^2+b^2=0, then \!\( *)
(*\*SubscriptBox[\(\[PartialD]\), \(z\)]*)
(*\*FractionBox[*)
(*SqrtBox[\(a + b\ Sinh[z]\)], \(Cosh[\(-*)
(*\*FractionBox[\(\[Pi]\ a\), \(4\ b\)]\) + *)
(*\*FractionBox[\(z\), \(2\)]]\)]\)=0*)


(* ::Subsubsection:: *)
(*Rule: If  a^2+b^2=0 \[And] m\[Element]\[DoubleStruckCapitalQ] \[And] n-1/2\[Element]\[DoubleStruckCapitalZ], then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]x^m (a+b Sinh[c+d x])^n \[DifferentialD]x  \[LongRightArrow]  (((2 a)^(n-1/2) Sqrt[a+b Sinh[c+d x]])/Cosh[-((\[Pi] a)/(4 b))+c/2+(d x)/2])\[Integral]x^m Cosh[-((\[Pi] a)/(4 b))+c/2+(d x)/2]^(2 n) \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[x_^m_.*(a_+b_.*Sinh[c_.+d_.*x_])^n_,x_Symbol] :=
  Dist[(2*a)^(n-1/2)*Sqrt[a+b*Sinh[c+d*x]]/Cosh[-Pi*a/(4*b)+c/2+d*x/2],
    Int[x^m*Cosh[-Pi*a/(4*b)+c/2+d*x/2]^(2*n),x]] /;
FreeQ[{a,b,c,d},x] && ZeroQ[a^2+b^2] && RationalQ[m] && IntegerQ[n-1/2]


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Derivation: Algebraic expansion*)


(* ::Subsubsection:: *)
(*Basis: 1/(a+b z)^2=a/((a^2+b^2) (a+b z))+(b (b-a z))/((a^2+b^2) (a+b z)^2)*)


(* ::Subsubsection:: *)
(*Rule: If  a^2+b^2!=0, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]x/(a+b Sinh[c+d x])^2 \[DifferentialD]x  \[LongRightArrow]  (a/(a^2+b^2))\[Integral]x/(a+b Sinh[c+d x]) \[DifferentialD]x+b/(a^2+b^2) \[Integral](x (b-a Sinh[c+d x]))/(a+b Sinh[c+d x])^2 \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[x_/(a_+b_.*Sinh[c_.+d_.*x_])^2,x_Symbol] :=
  Dist[a/(a^2+b^2),Int[x/(a+b*Sinh[c+d*x]),x]] +
  Dist[b/(a^2+b^2),Int[x*(b-a*Sinh[c+d*x])/(a+b*Sinh[c+d*x])^2,x]] /;
FreeQ[{a,b,c,d},x] && NonzeroQ[a^2+b^2]


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Derivation: Algebraic expansion*)


(* ::Subsubsection:: *)
(*Basis: a+b Sinh[z]=(-b+2 a E^z+b E^(2 z))/(2 E^z)*)


(* ::Subsubsection:: *)
(*Rule: If  a^2+b^2!=0 \[And] m>0 \[And] n\[Element]\[DoubleStruckCapitalZ] \[And] n<0, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]x^m (a+b Sinh[c+d x])^n \[DifferentialD]x  \[LongRightArrow]  (1/2^n)\[Integral](x^m (-b+2 a E^(c+d x)+b E^(2 (c+d x)))^n)/E^(n (c+d x)) \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[x_^m_.*(a_+b_.*Sinh[c_.+d_.*x_])^n_,x_Symbol] :=
  Dist[1/2^n,Int[x^m*(-b+2*a*E^(c+d*x)+b*E^(2*(c+d*x)))^n/E^(n*(c+d*x)),x]] /;
FreeQ[{a,b,c,d},x] && NonzeroQ[a^2+b^2] && RationalQ[m] && m>0 && IntegerQ[n] && n<0


(* ::PageBreak:: *)
(**)


(* ::Title::Bold::Closed:: *)
(*\[Integral]x^m (a+b Cosh[c+d x])^n \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Derivation: Algebraic simplification*)


(* ::Subsubsection:: *)
(*Basis: 1+Cosh[z]=2 Cosh[z/2]^2*)


(* ::Subsubsection:: *)
(*Rule: If  a-b=0 \[And] m\[Element]\[DoubleStruckCapitalQ] \[And] n\[Element]\[DoubleStruckCapitalZ] \[And] n<0, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]x^m (a+b Cosh[c+d x])^n \[DifferentialD]x  \[LongRightArrow]  (2 a)^n\[Integral]x^m Cosh[c/2+(d x)/2]^(2 n) \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[x_^m_.*(a_+b_.*Cosh[c_.+d_.*x_])^n_,x_Symbol] :=
  Dist[(2*a)^n,Int[x^m*Cosh[c/2+d*x/2]^(2*n),x]] /;
FreeQ[{a,b,c,d},x] && ZeroQ[a-b] && RationalQ[m] && IntegerQ[n] && n<0


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Derivation: Algebraic simplification*)


(* ::Subsubsection:: *)
(*Basis: 1-Cosh[z]=-2 Sinh[z/2]^2*)


(* ::Subsubsection:: *)
(*Rule: If  a+b=0 \[And] m\[Element]\[DoubleStruckCapitalQ] \[And] n\[Element]\[DoubleStruckCapitalZ] \[And] n<0, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]x^m (a+b Cosh[c+d x])^n \[DifferentialD]x  \[LongRightArrow]  (-2 a)^n\[Integral]x^m Sinh[c/2+(d x)/2]^(2 n) \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[x_^m_.*(a_+b_.*Cosh[c_.+d_.*x_])^n_,x_Symbol] :=
  Dist[(-2*a)^n,Int[x^m*Sinh[c/2+d*x/2]^(2*n),x]] /;
FreeQ[{a,b,c,d},x] && ZeroQ[a+b] && RationalQ[m] && IntegerQ[n] && n<0


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Derivation: Algebraic simplification*)


(* ::Subsubsection:: *)
(*Basis: 1+Cosh[z]=2 Cosh[z/2]^2*)


(* ::Subsubsection:: *)
(*Basis: \!\( *)
(*\*SubscriptBox[\(\[PartialD]\), \(z\)]*)
(*\*FractionBox[*)
(*SqrtBox[\(a + a\ Cosh[z]\)], \(Cosh[*)
(*\*FractionBox[\(z\), \(2\)]]\)]\)=0*)


(* ::Subsubsection:: *)
(*Rule: If  a-b=0 \[And] m\[Element]\[DoubleStruckCapitalQ] \[And] n-1/2\[Element]\[DoubleStruckCapitalZ], then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]x^m (a+b Cosh[c+d x])^n \[DifferentialD]x  \[LongRightArrow]  (((2 a)^(n-1/2) Sqrt[a+b Cosh[c+d x]])/Cosh[c/2+(d x)/2])\[Integral]x^m Cosh[c/2+(d x)/2]^(2 n) \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[x_^m_.*(a_+b_.*Cosh[c_.+d_.*x_])^n_,x_Symbol] :=
  Dist[(2*a)^(n-1/2)*Sqrt[a+b*Cosh[c+d*x]]/Cosh[c/2+d*x/2],Int[x^m*Cosh[c/2+d*x/2]^(2*n),x]] /;
FreeQ[{a,b,c,d},x] && ZeroQ[a-b] && RationalQ[m] && IntegerQ[n-1/2]


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Derivation: Algebraic simplification*)


(* ::Subsubsection:: *)
(*Basis: 1-Cosh[z]=-2 Sinh[z/2]^2*)


(* ::Subsubsection:: *)
(*Basis: \!\( *)
(*\*SubscriptBox[\(\[PartialD]\), \(z\)]*)
(*\*FractionBox[*)
(*SqrtBox[\(a - a\ Cosh[z]\)], \(Sinh[*)
(*\*FractionBox[\(z\), \(2\)]]\)]\)=0*)


(* ::Subsubsection:: *)
(*Rule: If  a+b=0 \[And] m\[Element]\[DoubleStruckCapitalQ] \[And] n-1/2\[Element]\[DoubleStruckCapitalZ], then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]x^m (a+b Cosh[c+d x])^n \[DifferentialD]x  \[LongRightArrow]  (((-2 a)^(n-1/2) Sqrt[a+b Cosh[c+d x]])/Sinh[c/2+(d x)/2])\[Integral]x^m Sinh[c/2+(d x)/2]^(2 n) \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[x_^m_.*(a_+b_.*Cosh[c_.+d_.*x_])^n_,x_Symbol] :=
  Dist[(-2*a)^(n-1/2)*Sqrt[a+b*Cosh[c+d*x]]/Sinh[c/2+d*x/2],Int[x^m*Sinh[c/2+d*x/2]^(2*n),x]] /;
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
(*\[Integral]x/(a+b Cosh[c+d x])^2 \[DifferentialD]x  \[LongRightArrow]  (a/(a^2-b^2))\[Integral]x/(a+b Cosh[c+d x]) \[DifferentialD]x-b/(a^2-b^2) \[Integral](x (b+a Cosh[c+d x]))/(a+b Cosh[c+d x])^2 \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[x_/(a_+b_.*Cosh[c_.+d_.*x_])^2,x_Symbol] :=
  Dist[a/(a^2-b^2),Int[x/(a+b*Cosh[c+d*x]),x]] -
  Dist[b/(a^2-b^2),Int[x*(b+a*Cosh[c+d*x])/(a+b*Cosh[c+d*x])^2,x]] /;
FreeQ[{a,b,c,d},x] && NonzeroQ[a^2-b^2]


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Derivation: Algebraic expansion*)


(* ::Subsubsection:: *)
(*Basis: a+b Cosh[z]=(b+2 a E^z+b E^(2 z))/(2 E^z)*)


(* ::Subsubsection:: *)
(*Rule: If  a^2-b^2!=0 \[And] m>0 \[And] n\[Element]\[DoubleStruckCapitalZ] \[And] n<0, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]x^m (a+b Cosh[c+d x])^n \[DifferentialD]x  \[LongRightArrow]  (1/2^n)\[Integral](x^m (b+2 a E^(c+d x)+b E^(2 (c+d x)))^n)/E^(n (c+d x)) \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[x_^m_.*(a_+b_.*Cosh[c_.+d_.*x_])^n_,x_Symbol] :=
  Dist[1/2^n,Int[x^m*(b+2*a*E^(c+d*x)+b*E^(2*(c+d*x)))^n/E^(n*(c+d*x)),x]] /;
FreeQ[{a,b,c,d},x] && NonzeroQ[a^2-b^2] && RationalQ[m] && m>0 && IntegerQ[n] && n<0


(* ::PageBreak:: *)
(**)


(* ::Title::Bold::Closed:: *)
(*\[Integral]u (a+b Sinh[c+d x]^2)^n \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Derivation: Algebraic simplification*)


(* ::Subsubsection:: *)
(*Basis: Sinh[z]^2=1/2 (-1+Cosh[2 z])*)


(* ::Subsubsection:: *)
(*Note: This rule should be replaced with rules that directly reduce the integrand rather than transforming it using hyperbolic power expansion!*)


(* ::Subsubsection:: *)
(*Rule: If  a-b!=0 \[And] n!=-1, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral](a+b Sinh[c+d x]^2)^n \[DifferentialD]x  \[LongRightArrow]  (1/2^n)\[Integral](2 a-b+b Cosh[2 c+2 d x])^n \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[(a_+b_.*Sinh[c_.+d_.*x_]^2)^n_,x_Symbol] :=
  Dist[1/2^n,Int[(2*a-b+b*Cosh[2*c+2*d*x])^n,x]] /;
FreeQ[{a,b,c,d},x] && NonzeroQ[a-b] && RationalQ[n] && n!=-1


(* ::Subsubsection:: *)
(*Basis: Cosh[z]^2=1/2 (1+Cosh[2 z])*)


(* ::Code:: *)
Int[(a_+b_.*Cosh[c_.+d_.*x_]^2)^n_,x_Symbol] :=
  Dist[1/2^n,Int[(2*a+b+b*Cosh[2*c+2*d*x])^n,x]] /;
FreeQ[{a,b,c,d},x] && NonzeroQ[a+b] && RationalQ[n] && n!=-1


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Derivation: Algebraic simplification*)


(* ::Subsubsection:: *)
(*Basis: Sinh[z]^2=1/2 (-1+Cosh[2 z])*)


(* ::Subsubsection:: *)
(*Note: This rule should be replaced with rules that directly reduce the integrand rather than transforming it using hyperbolic power expansion!*)


(* ::Subsubsection:: *)
(*Rule: If  a-b!=0 \[And] m,n\[Element]\[DoubleStruckCapitalZ] \[And] m>0, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]x^m (a+b Sinh[c+d x]^2)^n \[DifferentialD]x  \[LongRightArrow]  (1/2^n)\[Integral]x^m (2 a-b+b Cosh[2 c+2 d x])^n \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[x_^m_.*(a_+b_.*Sinh[c_.+d_.*x_]^2)^n_,x_Symbol] :=
  Dist[1/2^n,Int[x^m*(2*a-b+b*Cosh[2*c+2*d*x])^n,x]] /;
FreeQ[{a,b,c,d},x] && NonzeroQ[a-b] && IntegersQ[m,n] && (m>0 && n==-1 || m==1 && n==-2)


(* ::Subsubsection:: *)
(*Basis: Cosh[z]^2=1/2 (1+Cosh[2 z])*)


(* ::Code:: *)
Int[x_^m_.*(a_+b_.*Cosh[c_.+d_.*x_]^2)^n_,x_Symbol] :=
  Dist[1/2^n,Int[x^m*(2*a+b+b*Cosh[2*c+2*d*x])^n,x]] /;
FreeQ[{a,b,c,d},x] && NonzeroQ[a+b] && IntegersQ[m,n] && (m>0 && n==-1 || m==1 && n==-2)


(* ::PageBreak:: *)
(**)


(* ::Title::Bold::Closed:: *)
(*\[Integral]Sinh[a+b x^n]\[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Derivation: Primitive rule*)


(* ::Subsubsection:: *)
(*Basis: Derivative[1][FresnelS][z]=-I Sinh[(I \[Pi] z^2)/2]*)


(* ::Subsubsection:: *)
(*Note: This rule is commented out since it introduces the imaginary unit I; whereas, converting the hyperbolic sine to exponential form does not.*)


(* ::Subsubsection:: *)
(*Rule:*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]Sinh[b x^2]\[DifferentialD]x  \[LongRightArrow]  -((I Sqrt[\[Pi]/2])/Sqrt[I b])FresnelS[(Sqrt[I b] x)/Sqrt[\[Pi]/2]]*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
(* Int[Sinh[b_.*x_^2],x_Symbol] :=
  -I*Sqrt[Pi/2]*FresnelS[Rt[I*b,2]*x/Sqrt[Pi/2]]/Rt[I*b,2] /;
FreeQ[b,x] *)


(* ::Subsubsection:: *)
(*Basis: Derivative[1][FresnelC][z]=Cosh[(I \[Pi] z^2)/2]*)


(* ::Code:: *)
(* Int[Cosh[b_.*x_^2],x_Symbol] :=
  Sqrt[Pi/2]*FresnelC[Rt[I*b,2]*x/Sqrt[Pi/2]]/Rt[I*b,2] /;
FreeQ[b,x] *)


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Derivation: Algebraic expansion*)


(* ::Subsubsection:: *)
(*Basis: Sinh[z]=E^z/2-E^-z/2*)


(* ::Subsubsection:: *)
(*Rule: If  \[Not](n\[Element]\[DoubleStruckCapitalF] \[Or] n<0), then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]Sinh[a+b x^n]\[DifferentialD]x  \[LongRightArrow]  (1/2)\[Integral]E^(a+b x^n) \[DifferentialD]x-1/2 \[Integral]E^(-a-b x^n) \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[Sinh[a_.+b_.*x_^n_],x_Symbol] :=
  Dist[1/2,Int[E^(a+b*x^n),x]] - 
  Dist[1/2,Int[E^(-a-b*x^n),x]] /;
FreeQ[{a,b,n},x] && Not[FractionOrNegativeQ[n]]


(* ::Code:: *)
Int[Cosh[a_.+b_.*x_^n_],x_Symbol] :=
  Dist[1/2,Int[E^(-a-b*x^n),x]] + 
  Dist[1/2,Int[E^(a+b*x^n),x]] /;
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
(*\[Integral]Sinh[a+b x^n]\[DifferentialD]x  \[LongRightArrow]  x Sinh[a+b x^n]-b n \[Integral]x^n Cosh[a+b x^n]\[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[Sinh[a_.+b_.*x_^n_],x_Symbol] :=
  x*Sinh[a+b*x^n] - 
  Dist[b*n,Int[x^n*Cosh[a+b*x^n],x]] /;
FreeQ[{a,b},x] && IntegerQ[n] && n<0


(* ::Code:: *)
Int[Cosh[a_.+b_.*x_^n_],x_Symbol] :=
  x*Cosh[a+b*x^n] - 
  Dist[b*n,Int[x^n*Sinh[a+b*x^n],x]] /;
FreeQ[{a,b},x] && IntegerQ[n] && n<0


(* ::PageBreak:: *)
(**)


(* ::Title::Bold::Closed:: *)
(*\[Integral]x^m Sinh[a+b x^n]\[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Derivation: Primitive rule*)


(* ::Subsubsection:: *)
(*Basis: Derivative[1][SinhIntegral][z]=Sinh[z]/z*)


(* ::Subsubsection:: *)
(*Rule:*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]Sinh[b x^n]/x \[DifferentialD]x  \[LongRightArrow]  (SinhIntegral[b x^n]/n)*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[Sinh[b_.*x_^n_.]/x_,x_Symbol] :=
  SinhIntegral[b*x^n]/n /;
FreeQ[{b,n},x]


(* ::Subsubsection:: *)
(*Basis: Derivative[1][CoshIntegral][z]=Cosh[z]/z*)


(* ::Code:: *)
Int[Cosh[b_.*x_^n_.]/x_,x_Symbol] :=
  CoshIntegral[b*x^n]/n /;
FreeQ[{b,n},x]


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Derivation: Algebraic expansion*)


(* ::Subsubsection:: *)
(*Basis: Sinh[w+z]=Sinh[w] Cosh[z]+Cosh[w] Sinh[z]*)


(* ::Subsubsection:: *)
(*Rule:*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]Sinh[a+b x^n]/x \[DifferentialD]x  \[LongRightArrow]  Sinh[a]\[Integral]Cosh[b x^n]/x \[DifferentialD]x+Cosh[a]\[Integral]Sinh[b x^n]/x \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[Sinh[a_+b_.*x_^n_.]/x_,x_Symbol] :=
  Dist[Sinh[a],Int[Cosh[b*x^n]/x,x]] + 
  Dist[Cosh[a],Int[Sinh[b*x^n]/x,x]] /;
FreeQ[{a,b,n},x]


(* ::Code:: *)
Int[Cosh[a_+b_.*x_^n_.]/x_,x_Symbol] :=
  Dist[Cosh[a],Int[Cosh[b*x^n]/x,x]] + 
  Dist[Sinh[a],Int[Sinh[b*x^n]/x,x]] /;
FreeQ[{a,b,n},x]


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Reference: CRC 392h, A&S 4.5.83*)


(* ::Subsubsection:: *)
(*Derivation: Integration by parts*)


(* ::Subsubsection:: *)
(*Basis: x^m Sinh[a+b x^n]=(x^(m-n+1) \!\( *)
(*\*SubscriptBox[\(\[PartialD]\), \(x\)]\(Cosh[a + b\ *)
(*\*SuperscriptBox[\(x\), \(n\)]]\)\))/(b n)*)


(* ::Subsubsection:: *)
(*Rule: If  n\[Element]\[DoubleStruckCapitalZ] \[And] 0<n<=m, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]x^m Sinh[a+b x^n]\[DifferentialD]x  \[LongRightArrow]  ((x^(m-n+1) Cosh[a+b x^n])/(b n))-(m-n+1)/(b n) \[Integral]x^(m-n) Cosh[a+b x^n]\[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[x_^m_.*Sinh[a_.+b_.*x_^n_.],x_Symbol] :=
  x^(m-n+1)*Cosh[a+b*x^n]/(b*n) -
  Dist[(m-n+1)/(b*n),Int[x^(m-n)*Cosh[a+b*x^n],x]] /;
FreeQ[{a,b},x] && IntegerQ[n] && RationalQ[m] && 0<n<=m


(* ::Subsubsection:: *)
(*Reference: CRC 396h, A&S 4.5.84*)


(* ::Code:: *)
Int[x_^m_.*Cosh[a_.+b_.*x_^n_.],x_Symbol] :=
  x^(m-n+1)*Sinh[a+b*x^n]/(b*n) -
  Dist[(m-n+1)/(b*n),Int[x^(m-n)*Sinh[a+b*x^n],x]] /;
FreeQ[{a,b},x] && IntegerQ[n] && RationalQ[m] && 0<n<=m


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Reference: CRC 405h*)


(* ::Subsubsection:: *)
(*Derivation: Integration by parts*)


(* ::Subsubsection:: *)
(*Rule: If  m+n+1=0 \[Or] (n\[Element]\[DoubleStruckCapitalZ] \[And] ((n>0 \[And] m<-1) \[Or] 0<-n<m+1), then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]x^m Sinh[a+b x^n]\[DifferentialD]x  \[LongRightArrow]  ((x^(m+1) Sinh[a+b x^n])/(m+1))-(b n)/(m+1) \[Integral]x^(m+n) Cosh[a+b x^n]\[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[x_^m_.*Sinh[a_.+b_.*x_^n_.],x_Symbol] :=
  x^(m+1)*Sinh[a+b*x^n]/(m+1) -
  Dist[b*n/(m+1),Int[x^(m+n)*Cosh[a+b*x^n],x]] /;
FreeQ[{a,b,m,n},x] && (ZeroQ[m+n+1] || IntegerQ[n] && RationalQ[m] && (n>0 && m<-1 || 0<-n<m+1))


(* ::Subsubsection:: *)
(*Reference: CRC 406h*)


(* ::Code:: *)
Int[x_^m_.*Cosh[a_.+b_.*x_^n_.],x_Symbol] :=
  x^(m+1)*Cosh[a+b*x^n]/(m+1) -
  Dist[b*n/(m+1),Int[x^(m+n)*Sinh[a+b*x^n],x]] /;
FreeQ[{a,b,m,n},x] && (ZeroQ[m+n+1] || IntegerQ[n] && RationalQ[m] && (n>0 && m<-1 || 0<-n<m+1))


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Derivation: Algebraic expansion*)


(* ::Subsubsection:: *)
(*Basis: Sinh[z]=E^z/2-E^-z/2*)


(* ::Subsubsection:: *)
(*Rule: If  m+1!=0 \[And] m-n+1!=0 \[And] \[Not](m\[Element]\[DoubleStruckCapitalF] \[Or] n\[Element]\[DoubleStruckCapitalF] \[Or] n<0), then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]x^m Sinh[a+b x^n]\[DifferentialD]x  \[LongRightArrow]  (1/2)\[Integral]x^m E^(a+b x^n) \[DifferentialD]x-1/2 \[Integral]x^m E^(-a-b x^n) \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[x_^m_.*Sinh[a_.+b_.*x_^n_.],x_Symbol] :=
  Dist[1/2,Int[x^m*E^(a+b*x^n),x]] - 
  Dist[1/2,Int[x^m*E^(-a-b*x^n),x]] /;
FreeQ[{a,b,m,n},x] && NonzeroQ[m+1] && NonzeroQ[m-n+1] &&
Not[FractionQ[m] || FractionOrNegativeQ[n]]


(* ::Code:: *)
Int[x_^m_.*Cosh[a_.+b_.*x_^n_.],x_Symbol] :=
  Dist[1/2,Int[x^m*E^(-a-b*x^n),x]] + 
  Dist[1/2,Int[x^m*E^(a+b*x^n),x]] /;
FreeQ[{a,b,m,n},x] && NonzeroQ[m+1] && NonzeroQ[m-n+1] && 
Not[FractionQ[m] || FractionOrNegativeQ[n]]


(* ::PageBreak:: *)
(**)


(* ::Title::Bold::Closed:: *)
(*\[Integral]x^m Sinh[a+b x^n]^p \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Derivation: Integration by parts*)


(* ::Subsubsection:: *)
(*Rule: If  n,p\[Element]\[DoubleStruckCapitalZ] \[And] p>1 \[And] n-1!=0, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]Sinh[a+b x^n]^p/x^n \[DifferentialD]x  \[LongRightArrow]  -(Sinh[a+b x^n]^p/((n-1)x^(n-1)))+(b n p)/(n-1) \[Integral]Sinh[a+b x^n]^(p-1) Cosh[a+b x^n]\[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[x_^m_.*Sinh[a_.+b_.*x_^n_.]^p_,x_Symbol] :=
  -Sinh[a+b*x^n]^p/((n-1)*x^(n-1)) +
  Dist[b*n*p/(n-1),Int[Sinh[a+b*x^n]^(p-1)*Cosh[a+b*x^n],x]] /;
FreeQ[{a,b},x] && IntegersQ[n,p] && ZeroQ[m+n] && p>1 && NonzeroQ[n-1]


(* ::Code:: *)
Int[x_^m_.*Cosh[a_.+b_.*x_^n_.]^p_,x_Symbol] :=
  -Cosh[a+b*x^n]^p/((n-1)*x^(n-1)) +
  Dist[b*n*p/(n-1),Int[Cosh[a+b*x^n]^(p-1)*Sinh[a+b*x^n],x]] /;
FreeQ[{a,b},x] && IntegersQ[n,p] && ZeroQ[m+n] && p>1 && NonzeroQ[n-1]


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Reference: G&R 2.471.1b' special case when m-2n+1=0*)


(* ::Subsubsection:: *)
(*Rule: If  p>1 \[And] m-2n+1=0, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]x^m Sinh[a+b x^n]^p \[DifferentialD]x  \[LongRightArrow]  -((n Sinh[a+b x^n]^p)/(b^2 n^2 p^2))+(x^n Cosh[a+b x^n] Sinh[a+b x^n]^(p-1))/(b n p)-(p-1)/p \[Integral]x^m Sinh[a+b x^n]^(p-2) \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[x_^m_.*Sinh[a_.+b_.*x_^n_.]^p_,x_Symbol] :=
  -n*Sinh[a+b*x^n]^p/(b^2*n^2*p^2) +
  x^n*Cosh[a+b*x^n]*Sinh[a+b*x^n]^(p-1)/(b*n*p) -
  Dist[(p-1)/p,Int[x^m*Sinh[a+b*x^n]^(p-2),x]] /;
FreeQ[{a,b,m,n},x] && RationalQ[p] && p>1 && ZeroQ[m-2*n+1]


(* ::Subsubsection:: *)
(*Reference: G&R 2.471.1a' special case with m-2n+1=0*)


(* ::Code:: *)
Int[x_^m_.*Cosh[a_.+b_.*x_^n_.]^p_,x_Symbol] :=
  -n*Cosh[a+b*x^n]^p/(b^2*n^2*p^2) +
  x^n*Sinh[a+b*x^n]*Cosh[a+b*x^n]^(p-1)/(b*n*p) +
  Dist[(p-1)/p,Int[x^m*Cosh[a+b*x^n]^(p-2),x]] /;
FreeQ[{a,b,m,n},x] && RationalQ[p] && p>1 && ZeroQ[m-2*n+1]


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Reference: G&R 2.471.1b'*)


(* ::Subsubsection:: *)
(*Rule: If  m,n\[Element]\[DoubleStruckCapitalZ] \[And] p>1 \[And] 0<2n<m+1, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]x^m Sinh[a+b x^n]^p \[DifferentialD]x  \[LongRightArrow]  -(((m-n+1) x^(m-2 n+1) Sinh[a+b x^n]^p)/(b^2 n^2 p^2))+(x^(m-n+1) Cosh[a+b x^n] Sinh[a+b x^n]^(p-1))/(b n p)-     *)
(*                                           (p-1)/p \[Integral]x^m Sinh[a+b x^n]^(p-2) \[DifferentialD]x+((m-n+1) (m-2 n+1))/(b^2 n^2 p^2) \[Integral]x^(m-2 n) Sinh[a+b x^n]^p \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[x_^m_.*Sinh[a_.+b_.*x_^n_.]^p_,x_Symbol] :=
  -(m-n+1)*x^(m-2*n+1)*Sinh[a+b*x^n]^p/(b^2*n^2*p^2) +
  x^(m-n+1)*Cosh[a+b*x^n]*Sinh[a+b*x^n]^(p-1)/(b*n*p) -
  Dist[(p-1)/p,Int[x^m*Sinh[a+b*x^n]^(p-2),x]] +
  Dist[(m-n+1)*(m-2*n+1)/(b^2*n^2*p^2),Int[x^(m-2*n)*Sinh[a+b*x^n]^p,x]] /;
FreeQ[{a,b},x] && IntegersQ[m,n] && RationalQ[p] && p>1 && 0<2*n<m+1


(* ::Subsubsection:: *)
(*Reference: G&R 2.631.3'*)


(* ::Code:: *)
Int[x_^m_.*Cosh[a_.+b_.*x_^n_.]^p_,x_Symbol] :=
  -(m-n+1)*x^(m-2*n+1)*Cosh[a+b*x^n]^p/(b^2*n^2*p^2) +
  x^(m-n+1)*Sinh[a+b*x^n]*Cosh[a+b*x^n]^(p-1)/(b*n*p) +
  Dist[(p-1)/p,Int[x^m*Cosh[a+b*x^n]^(p-2),x]] +
  Dist[(m-n+1)*(m-2*n+1)/(b^2*n^2*p^2),Int[x^(m-2*n)*Cosh[a+b*x^n]^p,x]] /;
FreeQ[{a,b},x] && IntegersQ[m,n] && RationalQ[p] && p>1 && 0<2*n<m+1


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Reference: G&R 2.477.1 special case when m-2n+1=0*)


(* ::Subsubsection:: *)
(*Rule: If  p<-1 \[And] p!=-2 \[And] m-2n+1=0, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]x^m Sinh[a+b x^n]^p \[DifferentialD]x  \[LongRightArrow]                                                                                                                           *)
(*                           ((x^n Cosh[a+b x^n] Sinh[a+b x^n]^(p+1))/(b n (p+1)))-(n Sinh[a+b x^n]^(p+2))/(b^2 n^2 (p+1) (p+2))-(p+2)/(p+1) \[Integral]x^m Sinh[a+b x^n]^(p+2) \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[x_^m_.*Sinh[a_.+b_.*x_^n_.]^p_,x_Symbol] :=
  x^n*Cosh[a+b*x^n]*Sinh[a+b*x^n]^(p+1)/(b*n*(p+1)) - 
  n*Sinh[a+b*x^n]^(p+2)/(b^2*n^2*(p+1)*(p+2)) - 
  Dist[(p+2)/(p+1),Int[x^m*Sinh[a+b*x^n]^(p+2),x]] /;
FreeQ[{a,b,m,n},x] && RationalQ[p] && p<-1 && p!=-2 && ZeroQ[m-2*n+1]


(* ::Subsubsection:: *)
(*Reference: G&R 2.477.2' special case with m-2n+1=0*)


(* ::Code:: *)
Int[x_^m_.*Cosh[a_.+b_.*x_^n_.]^p_,x_Symbol] :=
  -x^n*Sinh[a+b*x^n]*Cosh[a+b*x^n]^(p+1)/(b*n*(p+1)) + 
  n*Cosh[a+b*x^n]^(p+2)/(b^2*n^2*(p+1)*(p+2)) + 
  Dist[(p+2)/(p+1),Int[x^m*Cosh[a+b*x^n]^(p+2),x]] /;
FreeQ[{a,b,m,n},x] && RationalQ[p] && p<-1 && p!=-2 && ZeroQ[m-2*n+1]


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Reference: G&R 2.477.1*)


(* ::Subsubsection:: *)
(*Rule: If  m,n\[Element]\[DoubleStruckCapitalZ] \[And] p<-1 \[And] p!=-2 \[And] 0<2n<m+1, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]x^m Sinh[a+b x^n]^p \[DifferentialD]x  \[LongRightArrow]  ((x^(m-n+1) Cosh[a+b x^n] Sinh[a+b x^n]^(p+1))/(b n (p+1)))-((m-n+1) x^(m-2 n+1) Sinh[a+b x^n]^(p+2))/(b^2 n^2 (p+1) (p+2))-  *)
(*                                      (p+2)/(p+1) \[Integral]x^m Sinh[a+b x^n]^(p+2) \[DifferentialD]x+((m-n+1) (m-2 n+1))/(b^2 n^2 (p+1) (p+2)) \[Integral]x^(m-2 n) Sinh[a+b x^n]^(p+2) \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[x_^m_.*Sinh[a_.+b_.*x_^n_.]^p_,x_Symbol] :=
  x^(m-n+1)*Cosh[a+b*x^n]*Sinh[a+b*x^n]^(p+1)/(b*n*(p+1)) -
  (m-n+1)*x^(m-2*n+1)*Sinh[a+b*x^n]^(p+2)/(b^2*n^2*(p+1)*(p+2)) -
  Dist[(p+2)/(p+1),Int[x^m*Sinh[a+b*x^n]^(p+2),x]] +
  Dist[(m-n+1)*(m-2*n+1)/(b^2*n^2*(p+1)*(p+2)),Int[x^(m-2*n)*Sinh[a+b*x^n]^(p+2),x]] /;
FreeQ[{a,b},x] && IntegersQ[m,n] && RationalQ[p] && p<-1 && p!=-2 && 0<2*n<m+1


(* ::Subsubsection:: *)
(*Reference: G&R 2.477.2*)


(* ::Code:: *)
Int[x_^m_.*Cosh[a_.+b_.*x_^n_.]^p_,x_Symbol] :=
  -x^(m-n+1)*Sinh[a+b*x^n]*Cosh[a+b*x^n]^(p+1)/(b*n*(p+1)) +
  (m-n+1)*x^(m-2*n+1)*Cosh[a+b*x^n]^(p+2)/(b^2*n^2*(p+1)*(p+2)) +
  Dist[(p+2)/(p+1),Int[x^m*Cosh[a+b*x^n]^(p+2),x]] -
  Dist[(m-n+1)*(m-2*n+1)/(b^2*n^2*(p+1)*(p+2)),Int[x^(m-2*n)*Cosh[a+b*x^n]^(p+2),x]] /;
FreeQ[{a,b},x] && IntegersQ[m,n] && RationalQ[p] && p<-1 && p!=-2 && 0<2*n<m+1


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Reference: G&R 2.475.1'*)


(* ::Subsubsection:: *)
(*Rule: If  m,n\[Element]\[DoubleStruckCapitalZ] \[And] p>1 \[And] 0<2n<1-m \[And] m+n+1!=0, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]x^m Sinh[a+b x^n]^p \[DifferentialD]x  \[LongRightArrow]  ((x^(m+1) Sinh[a+b x^n]^p)/(m+1))-(b n p x^(m+n+1) Cosh[a+b x^n] Sinh[a+b x^n]^(p-1))/((m+1) (m+n+1))+          *)
(*          (b^2 n^2 p^2)/((m+1) (m+n+1)) \[Integral]x^(m+2 n) Sinh[a+b x^n]^p \[DifferentialD]x+(b^2 n^2 p (p-1))/((m+1) (m+n+1)) \[Integral]x^(m+2 n) Sinh[a+b x^n]^(p-2) \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[x_^m_.*Sinh[a_.+b_.*x_^n_.]^p_,x_Symbol] :=
  x^(m+1)*Sinh[a+b*x^n]^p/(m+1) - 
  b*n*p*x^(m+n+1)*Cosh[a+b*x^n]*Sinh[a+b*x^n]^(p-1)/((m+1)*(m+n+1)) + 
  Dist[b^2*n^2*p^2/((m+1)*(m+n+1)),Int[x^(m+2*n)*Sinh[a+b*x^n]^p,x]] + 
  Dist[b^2*n^2*p*(p-1)/((m+1)*(m+n+1)),Int[x^(m+2*n)*Sinh[a+b*x^n]^(p-2),x]] /;
FreeQ[{a,b},x] && IntegersQ[m,n] && RationalQ[p] && p>1 && 0<2*n<-m+1 && NonzeroQ[m+n+1]


(* ::Subsubsection:: *)
(*Reference: G&R 2.475.2'*)


(* ::Code:: *)
Int[x_^m_.*Cosh[a_.+b_.*x_^n_.]^p_,x_Symbol] :=
  x^(m+1)*Cosh[a+b*x^n]^p/(m+1) - 
  b*n*p*x^(m+n+1)*Sinh[a+b*x^n]*Cosh[a+b*x^n]^(p-1)/((m+1)*(m+n+1)) + 
  Dist[b^2*n^2*p^2/((m+1)*(m+n+1)),Int[x^(m+2*n)*Cosh[a+b*x^n]^p,x]] - 
  Dist[b^2*n^2*p*(p-1)/((m+1)*(m+n+1)),Int[x^(m+2*n)*Cosh[a+b*x^n]^(p-2),x]] /;
FreeQ[{a,b},x] && IntegersQ[m,n] && RationalQ[p] && p>1 && 0<2*n<-m+1 && NonzeroQ[m+n+1]


(* ::PageBreak:: *)
(**)


(* ::Title::Bold::Closed:: *)
(*\[Integral]x^m Sinh[a+b (c+d x)^n]^p \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Derivation: Integration by linear substitution*)


(* ::Subsubsection:: *)
(*Rule: If  m\[Element]\[DoubleStruckCapitalZ] \[And] m>0 \[And] p\[Element]\[DoubleStruckCapitalQ], then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]x^m Sinh[a+b (c+d x)^n]^p \[DifferentialD]x  \[LongRightArrow]  (1/d)Subst[\[Integral](-(c/d)+x/d)^m Sinh[a+b x^n]^p \[DifferentialD]x,x,c+d x]*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[x_^m_.*Sinh[a_.+b_.*(c_+d_.*x_)^n_]^p_.,x_Symbol] :=
  Dist[1/d,Subst[Int[(-c/d+x/d)^m*Sinh[a+b*x^n]^p,x],x,c+d*x]] /;
FreeQ[{a,b,c,d,n},x] && IntegerQ[m] && m>0 && RationalQ[p]


(* ::Code:: *)
Int[x_^m_.*Cosh[a_.+b_.*(c_+d_.*x_)^n_]^p_.,x_Symbol] :=
  Dist[1/d,Subst[Int[(-c/d+x/d)^m*Cosh[a+b*x^n]^p,x],x,c+d*x]] /;
FreeQ[{a,b,c,d,n},x] && IntegerQ[m] && m>0 && RationalQ[p]


(* ::PageBreak:: *)
(**)


(* ::Title::Bold::Closed:: *)
(*\[Integral]Sinh[a+b x+c x^2]\[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Derivation: Algebraic simplification*)


(* ::Subsubsection:: *)
(*Basis: If  b^2-4 a c=0, then a+b x+c x^2=(b+2 c x)^2/(4 c)*)


(* ::Subsubsection:: *)
(*Rule: If  b^2-4 a c=0, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]Sinh[a+b x+c x^2]\[DifferentialD]x  \[LongRightArrow]  \[Integral]Sinh[(b+2 c x)^2/(4 c)]\[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[Sinh[a_.+b_.*x_+c_.*x_^2],x_Symbol] :=
  Int[Sinh[(b+2*c*x)^2/(4*c)],x] /;
FreeQ[{a,b,c},x] && ZeroQ[b^2-4*a*c]


(* ::Code:: *)
Int[Cosh[a_.+b_.*x_+c_.*x_^2],x_Symbol] :=
  Int[Cosh[(b+2*c*x)^2/(4*c)],x] /;
FreeQ[{a,b,c},x] && ZeroQ[b^2-4*a*c]


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Derivation: Algebraic expansion*)


(* ::Subsubsection:: *)
(*Basis: Sinh[z]=E^z/2-E^-z/2*)


(* ::Subsubsection:: *)
(*Rule: If  b^2-4 a c!=0, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]Sinh[a+b x+c x^2]\[DifferentialD]x  \[LongRightArrow]  (1/2)\[Integral]E^(a+b x+c x^2) \[DifferentialD]x-1/2 \[Integral]E^(-a-b x-c x^2) \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[Sinh[a_.+b_.*x_+c_.*x_^2],x_Symbol] :=
  Dist[1/2,Int[E^(a+b*x+c*x^2),x]] - 
  Dist[1/2,Int[E^(-a-b*x-c*x^2),x]] /;
FreeQ[{a,b,c},x] && NonzeroQ[b^2-4*a*c]


(* ::Code:: *)
Int[Cosh[a_.+b_.*x_+c_.*x_^2],x_Symbol] :=
  Dist[1/2,Int[E^(a+b*x+c*x^2),x]] + 
  Dist[1/2,Int[E^(-a-b*x-c*x^2),x]] /;
FreeQ[{a,b,c},x] && NonzeroQ[b^2-4*a*c]


(* ::PageBreak:: *)
(**)


(* ::Title::Bold::Closed:: *)
(*\[Integral](d+e x)^m Sinh[a+b x+c x^2]\[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Rule: If  b e-2c d=0, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral](d+e x)Sinh[a+b x+c x^2]\[DifferentialD]x  \[LongRightArrow]  ((e Cosh[a+b x+c x^2])/(2 c))*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[(d_.+e_.*x_)*Sinh[a_.+b_.*x_+c_.*x_^2],x_Symbol] :=
  e*Cosh[a+b*x+c*x^2]/(2*c) /;
FreeQ[{a,b,c,d,e},x] && ZeroQ[b*e-2*c*d]


(* ::Code:: *)
Int[(d_.+e_.*x_)*Cosh[a_.+b_.*x_+c_.*x_^2],x_Symbol] :=
  e*Sinh[a+b*x+c*x^2]/(2*c) /;
FreeQ[{a,b,c,d,e},x] && ZeroQ[b*e-2*c*d]


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Rule: If  b e-2c d!=0, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral](d+e x)Sinh[a+b x+c x^2]\[DifferentialD]x  \[LongRightArrow]  ((e Cosh[a+b x+c x^2])/(2 c))-(b e-2 c d)/(2 c) \[Integral]Sinh[a+b x+c x^2]\[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[(d_.+e_.*x_)*Sinh[a_.+b_.*x_+c_.*x_^2],x_Symbol] :=
  e*Cosh[a+b*x+c*x^2]/(2*c) -
  Dist[(b*e-2*c*d)/(2*c),Int[Sinh[a+b*x+c*x^2],x]] /;
FreeQ[{a,b,c,d,e},x] && NonzeroQ[b*e-2*c*d]


(* ::Code:: *)
Int[(d_.+e_.*x_)*Cosh[a_.+b_.*x_+c_.*x_^2],x_Symbol] :=
  e*Sinh[a+b*x+c*x^2]/(2*c) - 
  Dist[(b*e-2*c*d)/(2*c),Int[Cosh[a+b*x+c*x^2],x]] /;
FreeQ[{a,b,c,d,e},x] && NonzeroQ[b*e-2*c*d]


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Rule: If  m>1 \[And] b e-2c d=0, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral](d+e x)^m Sinh[a+b x+c x^2]\[DifferentialD]x  \[LongRightArrow]                                                                                                 *)
(*                        ((e (d+e x)^(m-1) Cosh[a+b x+c x^2])/(2 c))+(e^2 (m-1))/(2 c) \[Integral](d+e x)^(m-2) Cosh[a+b x+c x^2]\[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[(d_.+e_.*x_)^m_*Sinh[a_.+b_.*x_+c_.*x_^2],x_Symbol] :=
  e*(d+e*x)^(m-1)*Cosh[a+b*x+c*x^2]/(2*c) -
  Dist[e^2*(m-1)/(2*c),Int[(d+e*x)^(m-2)*Cosh[a+b*x+c*x^2],x]] /;
FreeQ[{a,b,c,d,e},x] && RationalQ[m] && m>1 && ZeroQ[b*e-2*c*d]


(* ::Code:: *)
Int[(d_.+e_.*x_)^m_*Cosh[a_.+b_.*x_+c_.*x_^2],x_Symbol] :=
  e*(d+e*x)^(m-1)*Sinh[a+b*x+c*x^2]/(2*c) - 
  Dist[e^2*(m-1)/(2*c),Int[(d+e*x)^(m-2)*Sinh[a+b*x+c*x^2],x]] /;
FreeQ[{a,b,c,d,e},x] && RationalQ[m] && m>1 && ZeroQ[b*e-2*c*d]


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Rule: If  m>1 \[And] b e-2c d!=0, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral](d+e x)^m Sinh[a+b x+c x^2]\[DifferentialD]x  \[LongRightArrow]  ((e (d+e x)^(m-1) Cosh[a+b x+c x^2])/(2 c))-                                                *)
(*                (b e-2 c d)/(2 c) \[Integral](d+e x)^(m-1) Sinh[a+b x+c x^2]\[DifferentialD]x-(e^2 (m-1))/(2 c) \[Integral](d+e x)^(m-2) Cosh[a+b x+c x^2]\[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[(d_.+e_.*x_)^m_*Sinh[a_.+b_.*x_+c_.*x_^2],x_Symbol] :=
  e*(d+e*x)^(m-1)*Cosh[a+b*x+c*x^2]/(2*c) -
  Dist[(b*e-2*c*d)/(2*c),Int[(d+e*x)^(m-1)*Sinh[a+b*x+c*x^2],x]] -
  Dist[e^2*(m-1)/(2*c),Int[(d+e*x)^(m-2)*Cosh[a+b*x+c*x^2],x]] /;
FreeQ[{a,b,c,d,e},x] && RationalQ[m] && m>1 && NonzeroQ[b*e-2*c*d]


(* ::Code:: *)
Int[(d_.+e_.*x_)^m_*Cosh[a_.+b_.*x_+c_.*x_^2],x_Symbol] :=
  e*(d+e*x)^(m-1)*Sinh[a+b*x+c*x^2]/(2*c) - 
  Dist[(b*e-2*c*d)/(2*c),Int[(d+e*x)^(m-1)*Cosh[a+b*x+c*x^2],x]] - 
  Dist[e^2*(m-1)/(2*c),Int[(d+e*x)^(m-2)*Sinh[a+b*x+c*x^2],x]] /;
FreeQ[{a,b,c,d,e},x] && RationalQ[m] && m>1 && NonzeroQ[b*e-2*c*d]


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Rule: If  m<-1 \[And] b e-2c d=0, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral](d+e x)^m Sinh[a+b x+c x^2]\[DifferentialD]x  \[LongRightArrow]                                                                                                                *)
(*                               (((d+e x)^(m+1) Sinh[a+b x+c x^2])/(e (m+1)))-(2 c)/(e^2 (m+1)) \[Integral](d+e x)^(m+2) Cosh[a+b x+c x^2]\[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[(d_.+e_.*x_)^m_*Sinh[a_.+b_.*x_+c_.*x_^2],x_Symbol] :=
  (d+e*x)^(m+1)*Sinh[a+b*x+c*x^2]/(e*(m+1)) -
  Dist[2*c/(e^2*(m+1)),Int[(d+e*x)^(m+2)*Cosh[a+b*x+c*x^2],x]] /;
FreeQ[{a,b,c,d,e},x] && RationalQ[m] && m<-1 && ZeroQ[b*e-2*c*d]


(* ::Code:: *)
Int[(d_.+e_.*x_)^m_*Cosh[a_.+b_.*x_+c_.*x_^2],x_Symbol] :=
  (d+e*x)^(m+1)*Cosh[a+b*x+c*x^2]/(e*(m+1)) - 
  Dist[2*c/(e^2*(m+1)),Int[(d+e*x)^(m+2)*Sinh[a+b*x+c*x^2],x]] /;
FreeQ[{a,b,c,d,e},x] && RationalQ[m] && m<-1 && ZeroQ[b*e-2*c*d]


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Rule: If  m<-1 \[And] b e-2c d!=0, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral](d+e x)^m Sinh[a+b x+c x^2]\[DifferentialD]x  \[LongRightArrow]  (((d+e x)^(m+1) Sinh[a+b x+c x^2])/(e (m+1)))-                                                *)
(*           (b e-2 c d)/(e^2 (m+1)) \[Integral](d+e x)^(m+1) Cosh[a+b x+c x^2]\[DifferentialD]x-(2 c)/(e^2 (m+1)) \[Integral](d+e x)^(m+2) Cosh[a+b x+c x^2]\[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[(d_.+e_.*x_)^m_*Sinh[a_.+b_.*x_+c_.*x_^2],x_Symbol] :=
  (d+e*x)^(m+1)*Sinh[a+b*x+c*x^2]/(e*(m+1)) -
  Dist[(b*e-2*c*d)/(e^2*(m+1)),Int[(d+e*x)^(m+1)*Cosh[a+b*x+c*x^2],x]] -
  Dist[2*c/(e^2*(m+1)),Int[(d+e*x)^(m+2)*Cosh[a+b*x+c*x^2],x]] /;
FreeQ[{a,b,c,d,e},x] && RationalQ[m] && m<-1 && NonzeroQ[b*e-2*c*d]


(* ::Code:: *)
Int[(d_.+e_.*x_)^m_*Cosh[a_.+b_.*x_+c_.*x_^2],x_Symbol] :=
  (d+e*x)^(m+1)*Cosh[a+b*x+c*x^2]/(e*(m+1)) - 
  Dist[(b*e-2*c*d)/(e^2*(m+1)),Int[(d+e*x)^(m+1)*Sinh[a+b*x+c*x^2],x]] -
  Dist[2*c/(e^2*(m+1)),Int[(d+e*x)^(m+2)*Sinh[a+b*x+c*x^2],x]] /;
FreeQ[{a,b,c,d,e},x] && RationalQ[m] && m<-1 && NonzeroQ[b*e-2*c*d]


(* ::PageBreak:: *)
(**)


(* ::Title::Bold::Closed:: *)
(*\[Integral]Sinh[a+b Log[c x^n]]^p \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Derivation: Algebraic simplification*)


(* ::Subsubsection:: *)
(*Basis: Sinh[b Log[c x^n]]=1/2 (c x^n)^b-1/(2 (c x^n)^b)*)


(* ::Subsubsection:: *)
(*Rule:*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]Sinh[b Log[c x^n]]^p \[DifferentialD]x  \[LongRightArrow]  \[Integral]((c x^n)^b/2-1/(2 (c x^n)^b))^p \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[Sinh[b_.*Log[c_.*x_^n_.]]^p_.,x_Symbol] :=
  Int[((c*x^n)^b/2 - 1/(2*(c*x^n)^b))^p,x] /;
FreeQ[c,x] && RationalQ[{b,n,p}]


(* ::Subsubsection:: *)
(*Basis: Cosh[b Log[c x^n]]=1/2 (c x^n)^b+1/(2 (c x^n)^b)*)


(* ::Code:: *)
Int[Cosh[b_.*Log[c_.*x_^n_.]]^p_.,x_Symbol] :=
  Int[((c*x^n)^b/2 + 1/(2*(c*x^n)^b))^p,x] /;
FreeQ[c,x] && RationalQ[{b,n,p}]


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Rule: If  1-b^2 n^2!=0, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]Sinh[a+b Log[c x^n]]\[DifferentialD]x  \[LongRightArrow]  ((x Sinh[a+b Log[c x^n]])/(1-b^2 n^2))-(b n x Cosh[a+b Log[c x^n]])/(1-b^2 n^2)*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[Sinh[a_.+b_.*Log[c_.*x_^n_.]],x_Symbol] :=
  x*Sinh[a+b*Log[c*x^n]]/(1-b^2*n^2) -
  b*n*x*Cosh[a+b*Log[c*x^n]]/(1-b^2*n^2) /;
FreeQ[{a,b,c,n},x] && NonzeroQ[1-b^2*n^2]


(* ::Code:: *)
Int[Cosh[a_.+b_.*Log[c_.*x_^n_.]],x_Symbol] :=
  x*Cosh[a+b*Log[c*x^n]]/(1-b^2*n^2) -
  b*n*x*Sinh[a+b*Log[c*x^n]]/(1-b^2*n^2) /;
FreeQ[{a,b,c,n},x] && NonzeroQ[1-b^2*n^2]


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Derivation: Piecewise constant extraction*)


(* ::Subsubsection:: *)
(*Rule: If  b n-2=0, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]Sqrt[Sinh[a+b Log[c x^n]]]\[DifferentialD]x  \[LongRightArrow]  ((x Sqrt[Sinh[a+b Log[c x^n]]])/Sqrt[-1+E^(2 a) (c x^n)^(4/n)])\[Integral]Sqrt[-1+E^(2 a) (c x^n)^(4/n)]/x \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[Sqrt[Sinh[a_.+b_.*Log[c_.*x_^n_.]]],x_Symbol] :=
  x*Sqrt[Sinh[a+b*Log[c*x^n]]]/Sqrt[-1+E^(2*a)*(c*x^n)^(4/n)]*
    Int[Sqrt[-1+E^(2*a)*(c*x^n)^(4/n)]/x,x] /;
FreeQ[{a,b,c,n},x] && ZeroQ[b*n-2]


(* ::Code:: *)
Int[Sqrt[Cosh[a_.+b_.*Log[c_.*x_^n_.]]],x_Symbol] :=
  x*Sqrt[Cosh[a+b*Log[c*x^n]]]/Sqrt[1+E^(2*a)*(c*x^n)^(4/n)]*
    Int[Sqrt[1+E^(2*a)*(c*x^n)^(4/n)]/x,x] /;
FreeQ[{a,b,c,n},x] && ZeroQ[b*n-2]


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Rule: If  p>1 \[And] 1-b^2 n^2 p^2!=0, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]Sinh[a+b Log[c x^n]]^p \[DifferentialD]x  \[LongRightArrow]  ((x Sinh[a+b Log[c x^n]]^p)/(1-b^2 n^2 p^2))-                                                                                *)
(*   (b n p x Cosh[a+b Log[c x^n]] Sinh[a+b Log[c x^n]]^(p-1))/(1-b^2 n^2 p^2)+(b^2 n^2 p (p-1))/(1-b^2 n^2 p^2) \[Integral]Sinh[a+b Log[c x^n]]^(p-2) \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[Sinh[a_.+b_.*Log[c_.*x_^n_.]]^p_,x_Symbol] :=
  x*Sinh[a+b*Log[c*x^n]]^p/(1-b^2*n^2*p^2) -
  b*n*p*x*Cosh[a+b*Log[c*x^n]]*Sinh[a+b*Log[c*x^n]]^(p-1)/(1-b^2*n^2*p^2) +
  Dist[b^2*n^2*p*(p-1)/(1-b^2*n^2*p^2),Int[Sinh[a+b*Log[c*x^n]]^(p-2),x]] /;
FreeQ[{a,b,c,n},x] && RationalQ[p] && p>1 && NonzeroQ[1-b^2*n^2*p^2]


(* ::Code:: *)
Int[Cosh[a_.+b_.*Log[c_.*x_^n_.]]^p_,x_Symbol] :=
  x*Cosh[a+b*Log[c*x^n]]^p/(1-b^2*n^2*p^2) -
  b*n*p*x*Sinh[a+b*Log[c*x^n]]*Cosh[a+b*Log[c*x^n]]^(p-1)/(1-b^2*n^2*p^2) -
  Dist[b^2*n^2*p*(p-1)/(1-b^2*n^2*p^2),Int[Cosh[a+b*Log[c*x^n]]^(p-2),x]] /;
FreeQ[{a,b,c,n},x] && RationalQ[p] && p>1 && NonzeroQ[1-b^2*n^2*p^2]


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Rule: If  p!=-1 \[And] p!=-2 \[And] 1-b^2 n^2 (p+2)^2=0, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]Sinh[a+b Log[c x^n]]^p \[DifferentialD]x  \[LongRightArrow]  ((x Coth[a+b Log[c x^n]] Sinh[a+b Log[c x^n]]^(p+2))/(b n (p+1)))-(x Sinh[a+b Log[c x^n]]^(p+2))/(b^2 n^2 (p+1) (p+2))*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[Sinh[a_.+b_.*Log[c_.*x_^n_.]]^p_,x_Symbol] :=
  x*Coth[a+b*Log[c*x^n]]*Sinh[a+b*Log[c*x^n]]^(p+2)/(b*n*(p+1)) -
  x*Sinh[a+b*Log[c*x^n]]^(p+2)/(b^2*n^2*(p+1)*(p+2)) /;
FreeQ[{a,b,c,n,p},x] && NonzeroQ[p+1] && NonzeroQ[p+2] && ZeroQ[1-b^2*n^2*(p+2)^2]


(* ::Code:: *)
Int[Cosh[a_.+b_.*Log[c_.*x_^n_.]]^p_,x_Symbol] :=
  -x*Tanh[a+b*Log[c*x^n]]*Cosh[a+b*Log[c*x^n]]^(p+2)/(b*n*(p+1)) +
  x*Cosh[a+b*Log[c*x^n]]^(p+2)/(b^2*n^2*(p+1)*(p+2)) /;
FreeQ[{a,b,c,n,p},x] && NonzeroQ[p+1] && NonzeroQ[p+2] && ZeroQ[1-b^2*n^2*(p+2)^2]


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Rule: If  p<-1 \[And] p!=-2 \[And] 1-b^2 n^2 (p+2)^2!=0, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]Sinh[a+b Log[c x^n]]^p \[DifferentialD]x  \[LongRightArrow]  ((x Coth[a+b Log[c x^n]] Sinh[a+b Log[c x^n]]^(p+2))/(b n (p+1)))-                  *)
(*                      (x Sinh[a+b Log[c x^n]]^(p+2))/(b^2 n^2 (p+1) (p+2))+(1-b^2 n^2 (p+2)^2)/(b^2 n^2 (p+1) (p+2)) \[Integral]Sinh[a+b Log[c x^n]]^(p+2) \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[Sinh[a_.+b_.*Log[c_.*x_^n_.]]^p_,x_Symbol] :=
  x*Coth[a+b*Log[c*x^n]]*Sinh[a+b*Log[c*x^n]]^(p+2)/(b*n*(p+1)) -
  x*Sinh[a+b*Log[c*x^n]]^(p+2)/(b^2*n^2*(p+1)*(p+2)) +
  Dist[(1-b^2*n^2*(p+2)^2)/(b^2*n^2*(p+1)*(p+2)),Int[Sinh[a+b*Log[c*x^n]]^(p+2),x]] /;
FreeQ[{a,b,c,n},x] && RationalQ[p] && p<-1 && p!=-2 && NonzeroQ[1-b^2*n^2*(p+2)^2]


(* ::Code:: *)
Int[Cosh[a_.+b_.*Log[c_.*x_^n_.]]^p_,x_Symbol] :=
  -x*Tanh[a+b*Log[c*x^n]]*Cosh[a+b*Log[c*x^n]]^(p+2)/(b*n*(p+1)) +
  x*Cosh[a+b*Log[c*x^n]]^(p+2)/(b^2*n^2*(p+1)*(p+2)) -
  Dist[(1-b^2*n^2*(p+2)^2)/(b^2*n^2*(p+1)*(p+2)),Int[Cosh[a+b*Log[c*x^n]]^(p+2),x]] /;
FreeQ[{a,b,c,n},x] && RationalQ[p] && p<-1 && p!=-2 && NonzeroQ[1-b^2*n^2*(p+2)^2]


(* ::PageBreak:: *)
(**)


(* ::Title::Bold::Closed:: *)
(*\[Integral]x^m Sinh[a+b Log[c x^n]]^p \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Rule: If  (m+1)^2-b^2 n^2!=0 \[And] m+1!=0, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]x^m Sinh[a+b Log[c x^n]]\[DifferentialD]x  \[LongRightArrow]  (((m+1) x^(m+1) Sinh[a+b Log[c x^n]])/((m+1)^2-b^2 n^2))-(b n x^(m+1) Cosh[a+b Log[c x^n]])/((m+1)^2-b^2 n^2)*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[x_^m_.*Sinh[a_.+b_.*Log[c_.*x_^n_.]],x_Symbol] :=
  (m+1)*x^(m+1)*Sinh[a+b*Log[c*x^n]]/((m+1)^2-b^2*n^2) -
  b*n*x^(m+1)*Cosh[a+b*Log[c*x^n]]/((m+1)^2-b^2*n^2) /;
FreeQ[{a,b,c,m,n},x] && NonzeroQ[(m+1)^2-b^2*n^2] && NonzeroQ[m+1]


(* ::Code:: *)
Int[x_^m_.*Cosh[a_.+b_.*Log[c_.*x_^n_.]],x_Symbol] :=
  (m+1)*x^(m+1)*Cosh[a+b*Log[c*x^n]]/((m+1)^2-b^2*n^2) -
  b*n*x^(m+1)*Sinh[a+b*Log[c*x^n]]/((m+1)^2-b^2*n^2) /;
FreeQ[{a,b,c,m,n},x] && NonzeroQ[(m+1)^2-b^2*n^2] && NonzeroQ[m+1]


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Rule: If  (m+1)^2-b^2 n^2 p^2!=0 \[And] p>1 \[And] m+1!=0, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]x^m Sinh[a+b Log[c x^n]]^p \[DifferentialD]x  \[LongRightArrow]  (((m+1) x^(m+1) Sinh[a+b Log[c x^n]]^p)/((m+1)^2-b^2 n^2 p^2))-                                                                     *)
(* (b n p x^(m+1) Cosh[a+b Log[c x^n]] Sinh[a+b Log[c x^n]]^(p-1))/((m+1)^2-b^2 n^2 p^2)+(b^2 n^2 p (p-1))/((m+1)^2-b^2 n^2 p^2) \[Integral]x^m Sinh[a+b Log[c x^n]]^(p-2) \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[x_^m_.*Sinh[a_.+b_.*Log[c_.*x_^n_.]]^p_,x_Symbol] :=
  (m+1)*x^(m+1)*Sinh[a+b*Log[c*x^n]]^p/((m+1)^2-b^2*n^2*p^2) -
  b*n*p*x^(m+1)*Cosh[a+b*Log[c*x^n]]*Sinh[a+b*Log[c*x^n]]^(p-1)/((m+1)^2-b^2*n^2*p^2) +
  Dist[b^2*n^2*p*(p-1)/((m+1)^2-b^2*n^2*p^2),Int[x^m*Sinh[a+b*Log[c*x^n]]^(p-2),x]] /;
FreeQ[{a,b,c,m,n},x] && NonzeroQ[(m+1)^2-b^2*n^2*p^2] && RationalQ[p] && p>1 && NonzeroQ[m+1]


(* ::Code:: *)
Int[x_^m_.*Cosh[a_.+b_.*Log[c_.*x_^n_.]]^p_,x_Symbol] :=
  (m+1)*x^(m+1)*Cosh[a+b*Log[c*x^n]]^p/((m+1)^2-b^2*n^2*p^2) -
  b*n*p*x^(m+1)*Cosh[a+b*Log[c*x^n]]^(p-1)*Sinh[a+b*Log[c*x^n]]/((m+1)^2-b^2*n^2*p^2) -
  Dist[b^2*n^2*p*(p-1)/((m+1)^2-b^2*n^2*p^2),Int[x^m*Cosh[a+b*Log[c*x^n]]^(p-2),x]] /;
FreeQ[{a,b,c,m,n},x] && NonzeroQ[(m+1)^2-b^2*n^2*p^2] && RationalQ[p] && p>1 && NonzeroQ[m+1]


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Rule: If  (m+1)^2-b^2 n^2 (p+2)^2=0 \[And] p!=-1 \[And] p!=-2, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]x^m Sinh[a+b Log[c x^n]]^p \[DifferentialD]x  \[LongRightArrow]  ((x^(m+1) Coth[a+b Log[c x^n]] Sinh[a+b Log[c x^n]]^(p+2))/(b n (p+1)))-((m+1) x^(m+1) Sinh[a+b Log[c x^n]]^(p+2))/(b^2 n^2 (p+1) (p+2))*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[x_^m_.*Sinh[a_.+b_.*Log[c_.*x_^n_.]]^p_,x_Symbol] :=
  x^(m+1)*Coth[a+b*Log[c*x^n]]*Sinh[a+b*Log[c*x^n]]^(p+2)/(b*n*(p+1)) -
  (m+1)*x^(m+1)*Sinh[a+b*Log[c*x^n]]^(p+2)/(b^2*n^2*(p+1)*(p+2)) /;
FreeQ[{a,b,c,m,n,p},x] && ZeroQ[(m+1)^2-b^2*n^2*(p+2)^2] && NonzeroQ[p+1] && NonzeroQ[p+2]


(* ::Code:: *)
Int[x_^m_.*Cosh[a_.+b_.*Log[c_.*x_^n_.]]^p_,x_Symbol] :=
  -x^(m+1)*Tanh[a+b*Log[c*x^n]]*Cosh[a+b*Log[c*x^n]]^(p+2)/(b*n*(p+1)) +
  (m+1)*x^(m+1)*Cosh[a+b*Log[c*x^n]]^(p+2)/(b^2*n^2*(p+1)*(p+2)) /;
FreeQ[{a,b,c,m,n,p},x] && ZeroQ[(m+1)^2-b^2*n^2*(p+2)^2] && NonzeroQ[p+1] && NonzeroQ[p+2]


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Rule: If  (m+1)^2-b^2 n^2 (p+2)^2!=0 \[And] p<-1 \[And] p!=-2 \[And] m+1!=0, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]x^m Sinh[a+b Log[c x^n]]^p \[DifferentialD]x  \[LongRightArrow]  ((x^(m+1) Coth[a+b Log[c x^n]] Sinh[a+b Log[c x^n]]^(p+2))/(b n (p+1)))-                           *)
(*        ((m+1) x^(m+1) Sinh[a+b Log[c x^n]]^(p+2))/(b^2 n^2 (p+1) (p+2))+((m+1)^2-b^2 n^2 (p+2)^2)/(b^2 n^2 (p+1) (p+2)) \[Integral]x^m Sinh[a+b Log[c x^n]]^(p+2) \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[x_^m_.*Sinh[a_.+b_.*Log[c_.*x_^n_.]]^p_,x_Symbol] :=
  x^(m+1)*Coth[a+b*Log[c*x^n]]*Sinh[a+b*Log[c*x^n]]^(p+2)/(b*n*(p+1)) -
  (m+1)*x^(m+1)*Sinh[a+b*Log[c*x^n]]^(p+2)/(b^2*n^2*(p+1)*(p+2)) +
  Dist[((m+1)^2-b^2*n^2*(p+2)^2)/(b^2*n^2*(p+1)*(p+2)),Int[x^m*Sinh[a+b*Log[c*x^n]]^(p+2),x]] /;
FreeQ[{a,b,c,m,n},x] && NonzeroQ[(m+1)^2-b^2*n^2*(p+2)^2] && RationalQ[p] && p<-1 && p!=-2 && NonzeroQ[m+1]


(* ::Code:: *)
Int[x_^m_.*Cosh[a_.+b_.*Log[c_.*x_^n_.]]^p_,x_Symbol] :=
  -x^(m+1)*Tanh[a+b*Log[c*x^n]]*Cosh[a+b*Log[c*x^n]]^(p+2)/(b*n*(p+1)) +
  (m+1)*x^(m+1)*Cosh[a+b*Log[c*x^n]]^(p+2)/(b^2*n^2*(p+1)*(p+2)) -
  Dist[((m+1)^2-b^2*n^2*(p+2)^2)/(b^2*n^2*(p+1)*(p+2)),Int[x^m*Cosh[a+b*Log[c*x^n]]^(p+2),x]] /;
FreeQ[{a,b,c,m,n},x] && NonzeroQ[(m+1)^2-b^2*n^2*(p+2)^2] && RationalQ[p] && p<-1 && p!=-2 && NonzeroQ[m+1]


(* ::PageBreak:: *)
(**)


(* ::Title::Bold::Closed:: *)
(*\[Integral]Sinh[a x^n Log[b x]^p] Log[b x]^p \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Rule: If  p>0, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]Sinh[a x Log[b x]^p] Log[b x]^p \[DifferentialD]x  \[LongRightArrow]  (Cosh[a x Log[b x]^p]/a)-p \[Integral]Sinh[a x Log[b x]^p] Log[b x]^(p-1) \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[Sinh[a_.*x_*Log[b_.*x_]^p_.]*Log[b_.*x_]^p_.,x_Symbol] :=
  Cosh[a*x*Log[b*x]^p]/a -
  Dist[p,Int[Sinh[a*x*Log[b*x]^p]*Log[b*x]^(p-1),x]] /;
FreeQ[{a,b},x] && RationalQ[p] && p>0


(* ::Code:: *)
Int[Cosh[a_.*x_*Log[b_.*x_]^p_.]*Log[b_.*x_]^p_.,x_Symbol] :=
  Sinh[a*x*Log[b*x]^p]/a -
  Dist[p,Int[Cosh[a*x*Log[b*x]^p]*Log[b*x]^(p-1),x]] /;
FreeQ[{a,b},x] && RationalQ[p] && p>0


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Rule: If  p>0, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]Sinh[a x^n Log[b x]^p] Log[b x]^p \[DifferentialD]x  \[LongRightArrow]  (Cosh[a x^n Log[b x]^p]/(a n x^(n-1)))-                              *)
(*                       p/n \[Integral]Sinh[a x^n Log[b x]^p] Log[b x]^(p-1) \[DifferentialD]x+(n-1)/(a n) \[Integral]Cosh[a x^n Log[b x]^p]/x^n \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[Sinh[a_.*x_^n_*Log[b_.*x_]^p_.]*Log[b_.*x_]^p_.,x_Symbol] :=
  Cosh[a*x^n*Log[b*x]^p]/(a*n*x^(n-1)) -
  Dist[p/n,Int[Sinh[a*x^n*Log[b*x]^p]*Log[b*x]^(p-1),x]] +
  Dist[(n-1)/(a*n),Int[Cosh[a*x^n*Log[b*x]^p]/x^n,x]] /;
FreeQ[{a,b},x] && RationalQ[{n,p}] && p>0


(* ::Code:: *)
Int[Cosh[a_.*x_^n_*Log[b_.*x_]^p_.]*Log[b_.*x_]^p_.,x_Symbol] :=
  Sinh[a*x^n*Log[b*x]^p]/(a*n*x^(n-1)) -
  Dist[p/n,Int[Cosh[a*x^n*Log[b*x]^p]*Log[b*x]^(p-1),x]] +
  Dist[(n-1)/(a*n),Int[Sinh[a*x^n*Log[b*x]^p]/x^n,x]] /;
FreeQ[{a,b},x] && RationalQ[{n,p}] && p>0


(* ::PageBreak:: *)
(**)


(* ::Title::Bold::Closed:: *)
(*\[Integral]x^m Sinh[a x^n Log[b x]^p] Log[b x]^p \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Rule: If  p>0 \[And] m-n+1=0, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]x^m Sinh[a x^n Log[b x]^p] Log[b x]^p \[DifferentialD]x  \[LongRightArrow]  (Cosh[a x^n Log[b x]^p]/(a n))-p/n \[Integral]x^m Sinh[a x^n Log[b x]^p] Log[b x]^(p-1) \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[x_^m_.*Sinh[a_.*x_^n_.*Log[b_.*x_]^p_.]*Log[b_.*x_]^p_.,x_Symbol] :=
  Cosh[a*x^n*Log[b*x]^p]/(a*n) -
  Dist[p/n,Int[x^m*Sinh[a*x^n*Log[b*x]^p]*Log[b*x]^(p-1),x]] /;
FreeQ[{a,b},x] && RationalQ[{m,n,p}] && p>0 && ZeroQ[m-n+1]


(* ::Code:: *)
Int[x_^m_.*Cosh[a_.*x_^n_.*Log[b_.*x_]^p_.]*Log[b_.*x_]^p_.,x_Symbol] :=
  Sinh[a*x^n*Log[b*x]^p]/(a*n) -
  Dist[p/n,Int[x^m*Cosh[a*x^n*Log[b*x]^p]*Log[b*x]^(p-1),x]] /;
FreeQ[{a,b},x] && RationalQ[{m,n,p}] && p>0 && ZeroQ[m-n+1]


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Rule: If  p>0 \[And] m-n+1!=0, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]x^m Sinh[a x^n Log[b x]^p] Log[b x]^p \[DifferentialD]x  \[LongRightArrow]  ((x^(m-n+1) Cosh[a x^n Log[b x]^p])/(a n))-                                *)
(*           p/n \[Integral]x^m Sinh[a x^n Log[b x]^p] Log[b x]^(p-1) \[DifferentialD]x-(m-n+1)/(a n) \[Integral]x^(m-n) Cosh[a x^n Log[b x]^p]\[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[x_^m_*Sinh[a_.*x_^n_.*Log[b_.*x_]^p_.]*Log[b_.*x_]^p_.,x_Symbol] :=
  x^(m-n+1)*Cosh[a*x^n*Log[b*x]^p]/(a*n) -
  Dist[p/n,Int[x^m*Sinh[a*x^n*Log[b*x]^p]*Log[b*x]^(p-1),x]] -
  Dist[(m-n+1)/(a*n),Int[x^(m-n)*Cosh[a*x^n*Log[b*x]^p],x]] /;
FreeQ[{a,b},x] && RationalQ[{m,n,p}] && p>0 && NonzeroQ[m-n+1]


(* ::Code:: *)
Int[x_^m_*Cosh[a_.*x_^n_.*Log[b_.*x_]^p_.]*Log[b_.*x_]^p_.,x_Symbol] :=
  x^(m-n+1)*Sinh[a*x^n*Log[b*x]^p]/(a*n) -
  Dist[p/n,Int[x^m*Cosh[a*x^n*Log[b*x]^p]*Log[b*x]^(p-1),x]] -
  Dist[(m-n+1)/(a*n),Int[x^(m-n)*Sinh[a*x^n*Log[b*x]^p],x]] /;
FreeQ[{a,b},x] && RationalQ[{m,n,p}] && p>0 && NonzeroQ[m-n+1]


(* ::PageBreak:: *)
(**)


(* ::Title::Bold::Closed:: *)
(*\[Integral]u Sinh[a+b x]^n \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Derivation: Algebraic expansion*)


(* ::Subsubsection:: *)
(*Basis: Sinh[z]^2=-(1/2)+1/2 Cosh[2 z]*)


(* ::Subsubsection:: *)
(*Rule: If  (n-1)/2\[NotElement]\[DoubleStruckCapitalZ], then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]Sinh[a/2+(b x)/2]^2 Sinh[a+b x]^n \[DifferentialD]x  \[LongRightArrow]  -(1/2)\[Integral]Sinh[a+b x]^n \[DifferentialD]x+1/2 \[Integral]Cosh[a+b x]Sinh[a+b x]^n \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[Sinh[c_.+d_.*x_]^2*Sinh[a_.+b_.*x_]^n_.,x_Symbol] :=
  -Dist[1/2,Int[Sinh[a+b*x]^n,x]] + 
  Dist[1/2,Int[Cosh[a+b*x]*Sinh[a+b*x]^n,x]] /;
FreeQ[{a,b,c,d},x] && ZeroQ[c-a/2] && ZeroQ[d-b/2] && Not[OddQ[n]]


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Derivation: Algebraic expansion*)


(* ::Subsubsection:: *)
(*Basis: Cosh[z]^2=1/2+1/2 Cosh[2 z]*)


(* ::Subsubsection:: *)
(*Rule: If  (n-1)/2\[NotElement]\[DoubleStruckCapitalZ], then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]Cosh[a/2+(b x)/2]^2 Sinh[a+b x]^n \[DifferentialD]x  \[LongRightArrow]  (1/2)\[Integral]Sinh[a+b x]^n \[DifferentialD]x+1/2 \[Integral]Cosh[a+b x]Sinh[a+b x]^n \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[Cosh[c_.+d_.*x_]^2*Sinh[a_.+b_.*x_]^n_.,x_Symbol] :=
  Dist[1/2,Int[Sinh[a+b*x]^n,x]] + 
  Dist[1/2,Int[Cosh[a+b*x]*Sinh[a+b*x]^n,x]] /;
FreeQ[{a,b,c,d},x] && ZeroQ[c-a/2] && ZeroQ[d-b/2] && Not[OddQ[n]]


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Derivation: Algebraic simplification*)


(* ::Subsubsection:: *)
(*Basis: Sinh[2 z]=2 Sinh[z] Cosh[z]*)


(* ::Subsubsection:: *)
(*Rule: If  n\[Element]\[DoubleStruckCapitalZ] and u is a function of trig functions of a/2+(b x)/2, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]u Sinh[a+b x]^n \[DifferentialD]x  \[LongRightArrow]  2^n\[Integral]u Cosh[a/2+(b x)/2]^n Sinh[a/2+(b x)/2]^n \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[u_*Sinh[a_.+b_.*x_]^n_.,x_Symbol] :=
  Dist[2^n,Int[u*Cosh[a/2+b*x/2]^n*Sinh[a/2+b*x/2]^n,x]] /;
FreeQ[{a,b},x] && IntegerQ[n] && ZeroQ[a/2+b*x/2-FunctionOfHyperbolic[u,x]]


(* ::PageBreak:: *)
(**)


(* ::Title::Bold::Closed:: *)
(*\[Integral]u Sinh[v]^2 \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Derivation: Algebraic expansion*)


(* ::Subsubsection:: *)
(*Basis: Sinh[z]^2=-(1/2)+1/2 Cosh[2 z]*)


(* ::Subsubsection:: *)
(*Rule: If u is a function of hyperbolic functions of 2 v, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]u Sinh[v]^2 \[DifferentialD]x  \[LongRightArrow]  -(1/2)\[Integral]u \[DifferentialD]x+1/2 \[Integral]u Cosh[2 v]\[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[u_*Sinh[v_]^2,x_Symbol] :=
  Dist[-1/2,Int[u,x]] + 
  Dist[1/2,Int[u*Cosh[2*v],x]] /;
FunctionOfHyperbolicQ[u,2*v,x]


(* ::Code:: *)
Int[u_*Cosh[v_]^2,x_Symbol] :=
  Dist[1/2,Int[u,x]] + 
  Dist[1/2,Int[u*Cosh[2*v],x]] /;
FunctionOfHyperbolicQ[u,2*v,x]


(* ::PageBreak:: *)
(**)
