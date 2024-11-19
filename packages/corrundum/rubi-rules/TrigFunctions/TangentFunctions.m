(* ::Package:: *)

(* ::Title::Bold::Closed:: *)
(*\[Integral]Tan[a+b x]^n \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Reference: G&R 2.526.17, CRC 292, A&S 4.3.115*)


(* ::Subsubsection:: *)
(*Derivation: Reciprocal rule*)


(* ::Subsubsection:: *)
(*Basis: Tan[z]=Sin[z]/Cos[z]*)


(* ::Subsubsection:: *)
(*Rule:*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]Tan[a+b x]\[DifferentialD]x  \[LongRightArrow]  -(Log[Cos[a+b x]]/b)*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[Tan[a_.+b_.*x_],x_Symbol] :=
  -Log[Cos[a+b*x]]/b /;
FreeQ[{a,b},x]


(* ::Subsubsection:: *)
(*Reference: G&R 2.526.33, CRC 293, A&S 4.3.118*)


(* ::Code:: *)
Int[Cot[a_.+b_.*x_],x_Symbol] :=
  Log[Sin[a+b*x]]/b /;
FreeQ[{a,b},x]


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Reference: G&R 2.526.22, CRC 420*)


(* ::Subsubsection:: *)
(*Derivation: Algebraic expansion*)


(* ::Subsubsection:: *)
(*Basis: Tan[z]^2=-1+Sec[z]^2*)


(* ::Subsubsection:: *)
(*Rule:*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]Tan[a+b x]^2 \[DifferentialD]x  \[LongRightArrow]  -x+Tan[a+b x]/b*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[Tan[a_.+b_.*x_]^2,x_Symbol] :=
  -x + Tan[a+b*x]/b /;
FreeQ[{a,b},x]


(* ::Subsubsection:: *)
(*Reference: G&R 2.526.38, CRC 424*)


(* ::Code:: *)
Int[Cot[a_.+b_.*x_]^2,x_Symbol] :=
  -x - Cot[a+b*x]/b /;
FreeQ[{a,b},x]


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Reference: G&R 2.510.1, CRC 423, A&S 4.3.129*)


(* ::Subsubsection:: *)
(*Derivation: Integration by parts with a double-back flip*)


(* ::Subsubsection:: *)
(*Basis: Tan[z]^n=(Tan[z]^(n-1) Sin[z])/Cos[z]*)


(* ::Subsubsection:: *)
(*Rule: If  n>1, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral](c Tan[a+b x])^n \[DifferentialD]x  \[LongRightArrow]  ((c (c Tan[a+b x])^(n-1))/(b (n-1)))-c^2 \[Integral](c Tan[a+b x])^(n-2) \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[(c_.*Tan[a_.+b_.*x_])^n_,x_Symbol] :=
  c*(c*Tan[a+b*x])^(n-1)/(b*(n-1)) - 
  Dist[c^2,Int[(c*Tan[a+b*x])^(n-2),x]] /;
FreeQ[{a,b,c},x] && RationalQ[n] && n>1


(* ::Subsubsection:: *)
(*Reference: G&R 2.510.4, CRC 427, A&S 4.3.130*)


(* ::Code:: *)
Int[(c_.*Cot[a_.+b_.*x_])^n_,x_Symbol] :=
  -c*(c*Cot[a+b*x])^(n-1)/(b*(n-1)) - 
  Dist[c^2,Int[(c*Cot[a+b*x])^(n-2),x]] /;
FreeQ[{a,b,c},x] && RationalQ[n] && n>1


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Reference: G&R 2.510.4, CRC 427'*)


(* ::Subsubsection:: *)
(*Derivation: Inverted integration by parts with a double-back flip*)


(* ::Subsubsection:: *)
(*Basis: Tan[z]^n=(Tan[z]^(n-1) Sin[z])/Cos[z]*)


(* ::Subsubsection:: *)
(*Rule: If  n<-1, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral](c Tan[a+b x])^n \[DifferentialD]x  \[LongRightArrow]  ((c Tan[a+b x])^(n+1)/(b c (n+1)))-1/c^2 \[Integral](c Tan[a+b x])^(n+2) \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[(c_.*Tan[a_.+b_.*x_])^n_,x_Symbol] :=
  (c*Tan[a+b*x])^(n+1)/(b*c*(n+1)) - 
  Dist[1/c^2,Int[(c*Tan[a+b*x])^(n+2),x]] /;
FreeQ[{a,b,c},x] && RationalQ[n] && n<-1


(* ::Subsubsection:: *)
(*Reference: G&R 2.510.1, CRC 423'*)


(* ::Code:: *)
Int[(c_.*Cot[a_.+b_.*x_])^n_,x_Symbol] :=
  -(c*Cot[a+b*x])^(n+1)/(b*c*(n+1)) - 
  Dist[1/c^2,Int[(c*Cot[a+b*x])^(n+2),x]] /;
FreeQ[{a,b,c},x] && RationalQ[n] && n<-1


(* ::PageBreak:: *)
(**)


(* ::Title::Bold::Closed:: *)
(*\[Integral](a+b Tan[c+d x])^n \[DifferentialD]x  when  a^2+b^2=0*)


(* ::Subsubsection:: *)
(*Rule: If  a^2+b^2=0, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]1/(a+b Tan[c+d x]) \[DifferentialD]x  \[LongRightArrow]  (x/(2 a))-a/(2 b d (a+b Tan[c+d x]))*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[1/(a_+b_.*Tan[c_.+d_.*x_]),x_Symbol] :=
  x/(2*a) - a/(2*b*d*(a+b*Tan[c+d*x])) /;
FreeQ[{a,b,c,d},x] && ZeroQ[a^2+b^2]


(* ::Code:: *)
Int[1/(a_+b_.*Cot[c_.+d_.*x_]),x_Symbol] :=
  x/(2*a) + a/(2*b*d*(a+b*Cot[c+d*x])) /;
FreeQ[{a,b,c,d},x] && ZeroQ[a^2+b^2]


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Rule: If  a^2+b^2=0 \[And] a>0, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]Sqrt[a+b Tan[c+d x]]\[DifferentialD]x  \[LongRightArrow]  -((Sqrt[2] b)/(d Sqrt[a]))ArcTanh[Sqrt[a+b Tan[c+d x]]/(Sqrt[2] Sqrt[a])]*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[Sqrt[a_+b_.*Tan[c_.+d_.*x_]],x_Symbol] :=
  -Sqrt[2]*b*ArcTanh[Sqrt[a+b*Tan[c+d*x]]/(Sqrt[2]*Rt[a,2])]/(d*Rt[a,2]) /;
FreeQ[{a,b,c,d},x] && ZeroQ[a^2+b^2] && PosQ[a]


(* ::Code:: *)
Int[Sqrt[a_+b_.*Cot[c_.+d_.*x_]],x_Symbol] :=
  Sqrt[2]*b*ArcCoth[Sqrt[a+b*Cot[c+d*x]]/(Sqrt[2]*Rt[a,2])]/(d*Rt[a,2]) /;
FreeQ[{a,b,c,d},x] && ZeroQ[a^2+b^2] && PosQ[a]


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Rule: If  a^2+b^2=0 \[And] \[Not](a>0), then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]Sqrt[a+b Tan[c+d x]]\[DifferentialD]x  \[LongRightArrow]  ((Sqrt[2] b)/(d Sqrt[-a]))ArcTan[Sqrt[a+b Tan[c+d x]]/(Sqrt[2] Sqrt[-a])]*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[Sqrt[a_+b_.*Tan[c_.+d_.*x_]],x_Symbol] :=
  Sqrt[2]*b*ArcTan[Sqrt[a+b*Tan[c+d*x]]/(Sqrt[2]*Rt[-a,2])]/(d*Rt[-a,2]) /;
FreeQ[{a,b,c,d},x] && ZeroQ[a^2+b^2] && NegQ[a]


(* ::Code:: *)
Int[Sqrt[a_+b_.*Cot[c_.+d_.*x_]],x_Symbol] :=
  Sqrt[2]*b*ArcCot[Sqrt[a+b*Cot[c+d*x]]/(Sqrt[2]*Rt[-a,2])]/(d*Rt[-a,2]) /;
FreeQ[{a,b,c,d},x] && ZeroQ[a^2+b^2] && NegQ[a]


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Rule: If  a^2+b^2=0 \[And] n\[Element]\[DoubleStruckCapitalF] \[And] n>1, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral](a+b Tan[c+d x])^n \[DifferentialD]x  \[LongRightArrow]  -((a^2 (a+b Tan[c+d x])^(n-1))/(b d (n-1)))+2 a \[Integral](a+b Tan[c+d x])^(n-1) \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[(a_+b_.*Tan[c_.+d_.*x_])^n_,x_Symbol] :=
  -a^2*(a+b*Tan[c+d*x])^(n-1)/(b*d*(n-1)) + 
  Dist[2*a,Int[(a+b*Tan[c+d*x])^(n-1),x]] /;
FreeQ[{a,b,c,d},x] && ZeroQ[a^2+b^2] && FractionQ[n] && n>1


(* ::Code:: *)
Int[(a_+b_.*Cot[c_.+d_.*x_])^n_,x_Symbol] :=
  a^2*(a+b*Cot[c+d*x])^(n-1)/(b*d*(n-1)) + 
  Dist[2*a,Int[(a+b*Cot[c+d*x])^(n-1),x]] /;
FreeQ[{a,b,c,d},x] && ZeroQ[a^2+b^2] && FractionQ[n] && n>1


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Rule: If  a^2+b^2=0 \[And] n<0, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral](a+b Tan[c+d x])^n \[DifferentialD]x  \[LongRightArrow]  ((a (a+b Tan[c+d x])^n)/(2 b d n))+1/(2 a) \[Integral](a+b Tan[c+d x])^(n+1) \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[(a_+b_.*Tan[c_.+d_.*x_])^n_,x_Symbol] :=
  a*(a+b*Tan[c+d*x])^n/(2*b*d*n) + 
  Dist[1/(2*a),Int[(a+b*Tan[c+d*x])^(n+1),x]] /;
FreeQ[{a,b,c,d},x] && ZeroQ[a^2+b^2] && RationalQ[n] && n<0


(* ::Code:: *)
Int[(a_+b_.*Cot[c_.+d_.*x_])^n_,x_Symbol] :=
  -a*(a+b*Cot[c+d*x])^n/(2*b*d*n) + 
  Dist[1/(2*a),Int[(a+b*Cot[c+d*x])^(n+1),x]] /;
FreeQ[{a,b,c,d},x] && ZeroQ[a^2+b^2] && RationalQ[n] && n<0


(* ::PageBreak:: *)
(**)


(* ::Title::Bold::Closed:: *)
(*\[Integral](a+b Tan[c+d x])^n \[DifferentialD]x  when  a^2+b^2!=0*)


(* ::Subsubsection:: *)
(*Derivation: Algebraic expansion and integration by substitution*)


(* ::Subsubsection:: *)
(*Basis: 1/(a+b Tan[z])=a/(a^2+b^2)+b/((a^2+b^2) (a Cos[z]+b Sin[z])) \!\( *)
(*\*SubscriptBox[\(\[PartialD]\), \(z\)]\((a\ Cos[z] + b\ Sin[z])\)\)*)


(* ::Subsubsection:: *)
(*Rule: If  a^2+b^2!=0, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]1/(a+b Tan[c+d x]) \[DifferentialD]x  \[LongRightArrow]  ((a x)/(a^2+b^2))+(b Log[a Cos[c+d x]+b Sin[c+d x]])/(d (a^2+b^2))*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[1/(a_+b_.*Tan[c_.+d_.*x_]),x_Symbol] :=
  a*x/(a^2+b^2) + b*Log[a*Cos[c+d*x]+b*Sin[c+d*x]]/(d*(a^2+b^2)) /;
FreeQ[{a,b,c,d},x] && NonzeroQ[a^2+b^2]


(* ::Code:: *)
Int[1/(a_+b_.*Cot[c_.+d_.*x_]),x_Symbol] :=
  a*x/(a^2+b^2) - b*Log[b*Cos[c+d*x]+a*Sin[c+d*x]]/(d*(a^2+b^2)) /;
FreeQ[{a,b,c,d},x] && NonzeroQ[a^2+b^2]


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Derivation: Algebraic expansion*)


(* ::Subsubsection:: *)
(*Basis: a+b z=(a-b I)/2 (1+I z)+(a+b I)/2 (1-I z)*)


(* ::Subsubsection:: *)
(*Note: Although the resulting integrands are more complicated than the original, they are of the form required for rules in the next section.*)


(* ::Subsubsection:: *)
(*Rule: If  a^2+b^2!=0, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]Sqrt[a+b Tan[c+d x]]\[DifferentialD]x  \[LongRightArrow]  ((a-b I)/2)\[Integral](1+I Tan[c+d x])/Sqrt[a+b Tan[c+d x]] \[DifferentialD]x+(a+b I)/2 \[Integral](1-I Tan[c+d x])/Sqrt[a+b Tan[c+d x]] \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[Sqrt[a_+b_.*Tan[c_.+d_.*x_]],x_Symbol] :=
  Dist[(a-b*I)/2,Int[(1+I*Tan[c+d*x])/Sqrt[a+b*Tan[c+d*x]],x]] +
  Dist[(a+b*I)/2,Int[(1-I*Tan[c+d*x])/Sqrt[a+b*Tan[c+d*x]],x]] /;
FreeQ[{a,b,c,d},x] && NonzeroQ[a^2+b^2]


(* ::Code:: *)
Int[Sqrt[a_+b_.*Cot[c_.+d_.*x_]],x_Symbol] :=
  Dist[(a-b*I)/2,Int[(1+I*Cot[c+d*x])/Sqrt[a+b*Cot[c+d*x]],x]] +
  Dist[(a+b*I)/2,Int[(1-I*Cot[c+d*x])/Sqrt[a+b*Cot[c+d*x]],x]] /;
FreeQ[{a,b,c,d},x] && NonzeroQ[a^2+b^2]


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Derivation: Algebraic expansion*)


(* ::Subsubsection:: *)
(*Basis: 1=1/2 (1+I z)+1/2 (1-I z)*)


(* ::Subsubsection:: *)
(*Note: Although the resulting integrands are more complicated than the original, they are of the form required for rules in the next section.*)


(* ::Subsubsection:: *)
(*Rule: If  a^2+b^2!=0, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]1/Sqrt[a+b Tan[c+d x]] \[DifferentialD]x  \[LongRightArrow]  (1/2)\[Integral](1+I Tan[c+d x])/Sqrt[a+b Tan[c+d x]] \[DifferentialD]x+1/2 \[Integral](1-I Tan[c+d x])/Sqrt[a+b Tan[c+d x]] \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[1/Sqrt[a_+b_.*Tan[c_.+d_.*x_]],x_Symbol] :=
  Dist[1/2,Int[(1+I*Tan[c+d*x])/Sqrt[a+b*Tan[c+d*x]],x]] +
  Dist[1/2,Int[(1-I*Tan[c+d*x])/Sqrt[a+b*Tan[c+d*x]],x]] /;
FreeQ[{a,b,c,d},x] && NonzeroQ[a^2+b^2]


(* ::Code:: *)
Int[1/Sqrt[a_+b_.*Cot[c_.+d_.*x_]],x_Symbol] :=
  Dist[1/2,Int[(1+I*Cot[c+d*x])/Sqrt[a+b*Cot[c+d*x]],x]] +
  Dist[1/2,Int[(1-I*Cot[c+d*x])/Sqrt[a+b*Cot[c+d*x]],x]] /;
FreeQ[{a,b,c,d},x] && NonzeroQ[a^2+b^2]


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Rule: If  a^2+b^2!=0 \[And] n>1, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral](a+b Tan[c+d x])^n \[DifferentialD]x  \[LongRightArrow]                                                                                                                                             *)
(*                                  ((b (a+b Tan[c+d x])^(n-1))/(d(n-1)))+\[Integral](a^2-b^2+2 a b Tan[c+d x])(a+b Tan[c+d x])^(n-2) \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[(a_+b_.*Tan[c_.+d_.*x_])^n_,x_Symbol] :=
  b*(a+b*Tan[c+d*x])^(n-1)/(d*(n-1)) + 
  Int[(a^2-b^2+2*a*b*Tan[c+d*x])*(a+b*Tan[c+d*x])^(n-2),x] /;
FreeQ[{a,b,c,d},x] && NonzeroQ[a^2+b^2] && FractionQ[n] && n>1


(* ::Code:: *)
Int[(a_+b_.*Cot[c_.+d_.*x_])^n_,x_Symbol] :=
  -b*(a+b*Cot[c+d*x])^(n-1)/(d*(n-1)) + 
  Int[(a^2-b^2+2*a*b*Cot[c+d*x])*(a+b*Cot[c+d*x])^(n-2),x] /;
FreeQ[{a,b,c,d},x] && NonzeroQ[a^2+b^2] && FractionQ[n] && n>1


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Rule: If  a^2+b^2!=0 \[And] n<-1, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral](a+b Tan[c+d x])^n \[DifferentialD]x  \[LongRightArrow]                                                                                                                                                 *)
(*                                  ((b (a+b Tan[c+d x])^(n+1))/(d(a^2+b^2)(n+1)))+1/(a^2+b^2) \[Integral](a-b Tan[c+d x])(a+b Tan[c+d x])^(n+1) \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[(a_+b_.*Tan[c_.+d_.*x_])^n_,x_Symbol] :=
  (b*(a+b*Tan[c+d*x])^(n+1))/(d*(a^2+b^2)*(n+1)) + 
  Dist[1/(a^2+b^2),Int[(a-b*Tan[c+d*x])*(a+b*Tan[c+d*x])^(n+1),x]] /;
FreeQ[{a,b,c,d},x] && NonzeroQ[a^2+b^2] && RationalQ[n] && n<-1


(* ::Code:: *)
Int[(a_+b_.*Cot[c_.+d_.*x_])^n_,x_Symbol] :=
  -(b*(a+b*Cot[c+d*x])^(n+1))/(d*(a^2+b^2)*(n+1)) + 
  Dist[1/(a^2+b^2),Int[(a-b*Cot[c+d*x])*(a+b*Cot[c+d*x])^(n+1),x]] /;
FreeQ[{a,b,c,d},x] && NonzeroQ[a^2+b^2] && RationalQ[n] && n<-1


(* ::PageBreak:: *)
(**)


(* ::Title::Bold::Closed:: *)
(*\[Integral](A+B Tan[c+d x])(a+b Tan[c+d x])^n \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Note: None of these rules appear in published integral tables.*)


(* ::Subsubsection:: *)
(*Derivation: Algebraic expansion*)


(* ::Subsubsection:: *)
(*Basis: (A+B z)/(a+b z)=B/b+(b A-a B)/b 1/(a+b z)*)


(* ::Subsubsection:: *)
(*Rule: If  b A-a B!=0, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral](A+B Tan[c+d x])/(a+b Tan[c+d x]) \[DifferentialD]x  \[LongRightArrow]  ((B x)/b)+(b A-a B)/b \[Integral]1/(a+b Tan[c+d x]) \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[(A_.+B_.*Tan[c_.+d_.*x_])/(a_.+b_.*Tan[c_.+d_.*x_]),x_Symbol] :=
  B*x/b + Dist[(b*A-a*B)/b,Int[1/(a+b*Tan[c+d*x]),x]] /;
FreeQ[{a,b,c,d,A,B},x] && NonzeroQ[b*A-a*B]


(* ::Code:: *)
Int[(A_.+B_.*Cot[c_.+d_.*x_])/(a_.+b_.*Cot[c_.+d_.*x_]),x_Symbol] :=
  B*x/b + Dist[(b*A-a*B)/b,Int[1/(a+b*Cot[c+d*x]),x]] /;
FreeQ[{a,b,c,d,A,B},x] && NonzeroQ[b*A-a*B]


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Rule: If  A^2+B^2=0 \[And] b A+a B!=0, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral](A+B Tan[c+d x])/Sqrt[a+b Tan[c+d x]] \[DifferentialD]x  \[LongRightArrow]  -((2 B)/(d Sqrt[a+(b A)/B]))ArcTanh[Sqrt[a+b Tan[c+d x]]/Sqrt[a+(b A)/B]]*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[(A_+B_.*Tan[c_.+d_.*x_])/Sqrt[a_.+b_.*Tan[c_.+d_.*x_]],x_Symbol] :=
  -2*B*ArcTanh[Sqrt[a+b*Tan[c+d*x]]/Rt[a+b*A/B,2]]/(d*Rt[a+b*A/B,2]) /;
FreeQ[{a,b,c,d,A,B},x] && ZeroQ[A^2+B^2] && NonzeroQ[b*A+a*B]


(* ::Code:: *)
Int[(A_+B_.*Cot[c_.+d_.*x_])/Sqrt[a_.+b_.*Cot[c_.+d_.*x_]],x_Symbol] :=
  2*B*ArcCoth[Sqrt[a+b*Cot[c+d*x]]/Rt[a+b*A/B,2]]/(d*Rt[a+b*A/B,2]) /;
FreeQ[{a,b,c,d,A,B},x] && ZeroQ[A^2+B^2] && NonzeroQ[b*A+a*B]


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Derivation: Algebraic expansion*)


(* ::Subsubsection:: *)
(*Basis: A+B z=(A-B I)/2 (1+I z)+(A+B I)/2 (1-I z)*)


(* ::Subsubsection:: *)
(*Rule: If  A^2+B^2!=0 \[And] a^2+b^2!=0, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral](A+B Tan[c+d x])/Sqrt[a+b Tan[c+d x]] \[DifferentialD]x  \[LongRightArrow]  ((A-B I)/2)\[Integral](1+I Tan[c+d x])/Sqrt[a+b Tan[c+d x]] \[DifferentialD]x+(A+B I)/2 \[Integral](1-I Tan[c+d x])/Sqrt[a+b Tan[c+d x]] \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[(A_.+B_.*Tan[c_.+d_.*x_])/Sqrt[a_.+b_.*Tan[c_.+d_.*x_]],x_Symbol] :=
  Dist[(A-B*I)/2,Int[(1+I*Tan[c+d*x])/Sqrt[a+b*Tan[c+d*x]],x]] +
  Dist[(A+B*I)/2,Int[(1-I*Tan[c+d*x])/Sqrt[a+b*Tan[c+d*x]],x]] /;
FreeQ[{a,b,c,d,A,B},x] && NonzeroQ[A^2+B^2] && NonzeroQ[a^2+b^2]


(* ::Code:: *)
Int[(A_.+B_.*Cot[c_.+d_.*x_])/Sqrt[a_.+b_.*Cot[c_.+d_.*x_]],x_Symbol] :=
  Dist[(A-B*I)/2,Int[(1+I*Cot[c+d*x])/Sqrt[a+b*Cot[c+d*x]],x]] +
  Dist[(A+B*I)/2,Int[(1-I*Cot[c+d*x])/Sqrt[a+b*Cot[c+d*x]],x]] /;
FreeQ[{a,b,c,d,A,B},x] && NonzeroQ[A^2+B^2] && NonzeroQ[a^2+b^2]


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Rule: If  n\[Element]\[DoubleStruckCapitalF] \[And] n>0 \[And] b A+a B=0, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral](A+B Tan[c+d x])(a+b Tan[c+d x])^n \[DifferentialD]x  \[LongRightArrow]                                                                                           *)
(*                                                    ((B (a+b Tan[c+d x])^n)/(d n))+(a A-b B)\[Integral](a+b Tan[c+d x])^(n-1) \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[(A_.+B_.*Tan[c_.+d_.*x_])*(a_+b_.*Tan[c_.+d_.*x_])^n_,x_Symbol] :=
  B*(a+b*Tan[c+d*x])^n/(d*n) + 
  Dist[a*A-b*B,Int[(a+b*Tan[c+d*x])^(n-1),x]] /;
FreeQ[{a,b,c,d,A,B},x] && FractionQ[n] && n>0 && ZeroQ[b*A+a*B]


(* ::Code:: *)
Int[(A_.+B_.*Cot[c_.+d_.*x_])*(a_+b_.*Cot[c_.+d_.*x_])^n_,x_Symbol] :=
  -B*(a+b*Cot[c+d*x])^n/(d*n) + 
  Dist[a*A-b*B,Int[(a+b*Cot[c+d*x])^(n-1),x]] /;
FreeQ[{a,b,c,d,A,B},x] && FractionQ[n] && n>0 && ZeroQ[b*A+a*B]


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Rule: If  n\[Element]\[DoubleStruckCapitalF] \[And] n>0 \[And] b A+a B!=0, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral](A+B Tan[c+d x])(a+b Tan[c+d x])^n \[DifferentialD]x  \[LongRightArrow]                                                                                                       *)
(*                         ((B (a+b Tan[c+d x])^n)/(d n))+\[Integral](a A-b B+(b A+a B) Tan[c+d x])(a+b Tan[c+d x])^(n-1) \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[(A_.+B_.*Tan[c_.+d_.*x_])*(a_+b_.*Tan[c_.+d_.*x_])^n_,x_Symbol] :=
  B*(a+b*Tan[c+d*x])^n/(d*n) + 
  Int[(a*A-b*B+(b*A+a*B)*Tan[c+d*x])*(a+b*Tan[c+d*x])^(n-1),x] /;
FreeQ[{a,b,c,d,A,B},x] && FractionQ[n] && n>0 && NonzeroQ[b*A+a*B]


(* ::Code:: *)
Int[(A_.+B_.*Cot[c_.+d_.*x_])*(a_+b_.*Cot[c_.+d_.*x_])^n_,x_Symbol] :=
  -B*(a+b*Cot[c+d*x])^n/(d*n) + 
  Int[(a*A-b*B+(b*A+a*B)*Cot[c+d*x])*(a+b*Cot[c+d*x])^(n-1),x] /;
FreeQ[{a,b,c,d,A,B},x] && FractionQ[n] && n>0 && NonzeroQ[b*A+a*B]


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Rule: If  a^2+b^2!=0 \[And] n<-1 \[And] b A-a B!=0, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral](A+B Tan[c+d x])(a+b Tan[c+d x])^n \[DifferentialD]x  \[LongRightArrow]  (((b A-a B)(a+b Tan[c+d x])^(n+1))/(d(a^2+b^2)(n+1)))+    *)
(*                                           1/(a^2+b^2) \[Integral](a A+b B-(b A-a B) Tan[c+d x])(a+b Tan[c+d x])^(n+1) \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[(A_.+B_.*Tan[c_.+d_.*x_])*(a_+b_.*Tan[c_.+d_.*x_])^n_,x_Symbol] :=
  (b*A-a*B)*(a+b*Tan[c+d*x])^(n+1)/(d*(a^2+b^2)*(n+1)) + 
  Dist[1/(a^2+b^2),Int[(a*A+b*B-(b*A-a*B)*Tan[c+d*x])*(a+b*Tan[c+d*x])^(n+1),x]] /;
FreeQ[{a,b,c,d,A,B},x] && NonzeroQ[a^2+b^2] && RationalQ[n] && n<-1 && NonzeroQ[b*A-a*B]


(* ::Code:: *)
Int[(A_.+B_.*Cot[c_.+d_.*x_])*(a_+b_.*Cot[c_.+d_.*x_])^n_,x_Symbol] :=
  -(b*A-a*B)*(a+b*Cot[c+d*x])^(n+1)/(d*(a^2+b^2)*(n+1)) + 
  Dist[1/(a^2+b^2),Int[(a*A+b*B-(b*A-a*B)*Cot[c+d*x])*(a+b*Cot[c+d*x])^(n+1),x]] /;
FreeQ[{a,b,c,d,A,B},x] && NonzeroQ[a^2+b^2] && RationalQ[n] && n<-1 && NonzeroQ[b*A-a*B]


(* ::PageBreak:: *)
(**)


(* ::Title::Bold::Closed:: *)
(*\[Integral](a+b Tan[c+d x]^2)^n \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Derivation: Algebraic simplification*)


(* ::Subsubsection:: *)
(*Basis: If  a-b=0, then  a+b Tan[z]^2=b Sec[z]^2*)


(* ::Subsubsection:: *)
(*Rule: If  a-b=0 \[And] m\[Element]\[DoubleStruckCapitalZ], then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]u (a+b Tan[v]^2)^m \[DifferentialD]x  \[LongRightArrow]  b^m\[Integral]u Sec[v]^(2m) \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[u_.*(a_+b_.*Tan[v_]^2)^m_,x_Symbol] :=
  Dist[b^m,Int[u*Sec[v]^(2*m),x]] /;
FreeQ[{a,b,m},x] && ZeroQ[a-b] && IntegerQ[m]


(* ::Code:: *)
Int[u_.*(a_+b_.*Cot[v_]^2)^m_,x_Symbol] :=
  Dist[b^m,Int[u*Csc[v]^(2*m),x]] /;
FreeQ[{a,b,m},x] && ZeroQ[a-b] && IntegerQ[m]


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Derivation: Algebraic simplification*)


(* ::Subsubsection:: *)
(*Basis: If  a-b=0, then  a+b Tan[z]^2=b Sec[z]^2*)


(* ::Subsubsection:: *)
(*Rule: If  a-b=0 \[And] m\[NotElement]\[DoubleStruckCapitalZ], then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]u (a+b Tan[v]^2)^m \[DifferentialD]x  \[LongRightArrow]  \[Integral]u (b Sec[v]^2)^m \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[u_.*(a_+b_.*Tan[v_]^2)^m_,x_Symbol] :=
  Int[u*(b*Sec[v]^2)^m,x] /;
FreeQ[{a,b,m},x] && ZeroQ[a-b] && Not[IntegerQ[m]]


(* ::Code:: *)
Int[u_.*(a_+b_.*Cot[v_]^2)^m_,x_Symbol] :=
  Int[u*(b*Csc[v]^2)^m,x] /;
FreeQ[{a,b,m},x] && ZeroQ[a-b] && Not[IntegerQ[m]]


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Rule: If  a-b!=0, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]1/(a+b Tan[c+d x]^2) \[DifferentialD]x  \[LongRightArrow]  (x/(a-b))-Sqrt[b]/(Sqrt[a] d (a-b)) ArcTan[(Sqrt[b] Tan[c+d x])/Sqrt[a]]*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[1/(a_+b_.*Tan[c_.+d_.*x_]^2),x_Symbol] :=
  x/(a-b) - Sqrt[b]*ArcTan[Sqrt[b]*Tan[c+d*x]/Sqrt[a]]/(Sqrt[a]*d*(a-b)) /;
FreeQ[{a,b,c,d},x] && NonzeroQ[a-b]


(* ::Code:: *)
Int[1/(a_+b_.*Cot[c_.+d_.*x_]^2),x_Symbol] :=
  x/(a-b) + Sqrt[b]*ArcTan[Sqrt[b]*Cot[c+d*x]/Sqrt[a]]/(Sqrt[a]*d*(a-b)) /;
FreeQ[{a,b,c,d},x] && NonzeroQ[a-b]


(* ::PageBreak:: *)
(**)


(* ::Title::Bold::Closed:: *)
(*\[Integral]x^m Tan[a+b x^n]^p \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Derivation: Algebraic expansion*)


(* ::Subsubsection:: *)
(*Basis: Tan[z]=-I+(2 I)/(1+E^(2 I z))*)


(* ::Subsubsection:: *)
(*Rule: If  m\[Element]\[DoubleStruckCapitalZ] \[And] m>0, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]x^m Tan[a+b x]\[DifferentialD]x  \[LongRightArrow]  -((I x^(m+1))/(m+1))+2 I \[Integral]x^m/(1+E^(2 I a+2 I b x)) \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[x_^m_.*Tan[a_.+b_.*x_^n_.],x_Symbol] :=
  -I*x^(m+1)/(m+1) + 
  Dist[2*I,Int[x^m/(1+E^(2*I*a+2*I*b*x^n)),x]] /;
FreeQ[{a,b,n},x] && IntegerQ[m] && m>0 && NonzeroQ[m-n+1] && n===1


(* ::Code:: *)
Int[x_^m_.*Cot[a_.+b_.*x_^n_.],x_Symbol] :=
  I*x^(m+1)/(m+1) - 
  Dist[2*I,Int[x^m/(1-E^(2*I*a+2*I*b*x^n)),x]] /;
FreeQ[{a,b,n},x] && IntegerQ[m] && m>0 && NonzeroQ[m-n+1] && n===1


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Note: This rule does not appear in published integral tables.*)


(* ::Subsubsection:: *)
(*Rule: If  p>1 \[And] m-n+1!=0 \[And] 0<n<=m, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]x^m Tan[a+b x^n]^p \[DifferentialD]x  \[LongRightArrow]  ((x^(m-n+1) Tan[a+b x^n]^(p-1))/(b n (p-1)))-                                                      *)
(*                                                      (m-n+1)/(b n (p-1)) \[Integral]x^(m-n) Tan[a+b x^n]^(p-1) \[DifferentialD]x-\[Integral]x^m Tan[a+b x^n]^(p-2) \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[x_^m_.*Tan[a_.+b_.*x_^n_.]^p_,x_Symbol] :=
  x^(m-n+1)*Tan[a+b*x^n]^(p-1)/(b*n*(p-1)) - 
  Dist[(m-n+1)/(b*n*(p-1)),Int[x^(m-n)*Tan[a+b*x^n]^(p-1),x]] - 
  Int[x^m*Tan[a+b*x^n]^(p-2),x] /;
FreeQ[{a,b},x] && RationalQ[{m,n,p}] && p>1 && NonzeroQ[m-n+1] && 0<n<=m


(* ::Code:: *)
Int[x_^m_.*Cot[a_.+b_.*x_^n_.]^p_,x_Symbol] :=
  -x^(m-n+1)*Cot[a+b*x^n]^(p-1)/(b*n*(p-1)) + 
  Dist[(m-n+1)/(b*n*(p-1)),Int[x^(m-n)*Cot[a+b*x^n]^(p-1),x]] - 
  Int[x^m*Cot[a+b*x^n]^(p-2),x] /;
FreeQ[{a,b},x] && RationalQ[{m,n,p}] && p>1 && NonzeroQ[m-n+1] && 0<n<=m


(* ::PageBreak:: *)
(**)


(* ::Title::Bold::Closed:: *)
(*\[Integral]x^m Tan[a+b x+c x^2]\[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Rule:*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]x Tan[a+b x+c x^2]\[DifferentialD]x  \[LongRightArrow]  -(Log[Cos[a+b x+c x^2]]/(2 c))-b/(2 c) \[Integral]Tan[a+b x+c x^2]\[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[x_*Tan[a_.+b_.*x_+c_.*x_^2],x_Symbol] :=
  -Log[Cos[a+b*x+c*x^2]]/(2*c) -
  Dist[b/(2*c),Int[Tan[a+b*x+c*x^2],x]] /;
FreeQ[{a,b,c},x]


(* ::Code:: *)
Int[x_*Cot[a_.+b_.*x_+c_.*x_^2],x_Symbol] :=
  Log[Sin[a+b*x+c*x^2]]/(2*c) -
  Dist[b/(2*c),Int[Cot[a+b*x+c*x^2],x]] /;
FreeQ[{a,b,c},x]


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Note: This rule is valid, but to be useful need a rule for reducing integrands of the form x^m Log[Cos[a+b x+c x^2]].*)


(* ::Subsubsection:: *)
(*Rule: If  m>1, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]x^m Tan[a+b x+c x^2]\[DifferentialD]x  \[LongRightArrow]  -((x^(m-1) Log[Cos[a+b x+c x^2]])/(2 c))-                                                        *)
(*                                                   b/(2 c) \[Integral]x^(m-1) Tan[a+b x+c x^2]\[DifferentialD]x+(m-1)/(2 c) \[Integral]x^(m-2) Log[Cos[a+b x+c x^2]]\[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
(* Int[x_^m_*Tan[a_.+b_.*x_+c_.*x_^2],x_Symbol] :=
  -x^(m-1)*Log[Cos[a+b*x+c*x^2]]/(2*c) - 
  Dist[b/(2*c),Int[x^(m-1)*Tan[a+b*x+c*x^2],x]] + 
  Dist[(m-1)/(2*c),Int[x^(m-2)*Log[Cos[a+b*x+c*x^2]],x]] /;
FreeQ[{a,b,c},x] && RationalQ[m] && m>1 *)


(* ::Code:: *)
(* Int[x_^m_*Cot[a_.+b_.*x_+c_.*x_^2],x_Symbol] :=
  x^(m-1)*Log[Sin[a+b*x+c*x^2]]/(2*c) -
  Dist[b/(2*c),Int[x^(m-1)*Cot[a+b*x+c*x^2],x]] -
  Dist[(m-1)/(2*c),Int[x^(m-2)*Log[Sin[a+b*x+c*x^2]],x]] /;
FreeQ[{a,b,c},x] && RationalQ[m] && m>1*)


(* ::PageBreak:: *)
(**)
