(* ::Package:: *)

(* ::Title::Bold::Closed:: *)
(*\[Integral]Tanh[a+b x]^n \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Reference: G&R 2.243.17, CRC 556, A&S 4.5.79*)


(* ::Subsubsection:: *)
(*Derivation: Reciprocal rule*)


(* ::Subsubsection:: *)
(*Basis: Tanh[z]=Sinh[z]/Cosh[z]*)


(* ::Subsubsection:: *)
(*Rule:*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]Tanh[a+b x]\[DifferentialD]x  \[LongRightArrow]  (Log[Cosh[a+b x]]/b)*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[Tanh[a_.+b_.*x_],x_Symbol] :=
  Log[Cosh[a+b*x]]/b /;
FreeQ[{a,b},x]


(* ::Subsubsection:: *)
(*Reference: G&R 2.423.33, CRC 557, A&S 4.5.82*)


(* ::Code:: *)
Int[Coth[a_.+b_.*x_],x_Symbol] :=
  Log[Sinh[a+b*x]]/b /;
FreeQ[{a,b},x]


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Reference: G&R 2.423.22, CRC 569*)


(* ::Subsubsection:: *)
(*Derivation: Algebraic expansion*)


(* ::Subsubsection:: *)
(*Basis: Tanh[z]^2=1-Sech[z]^2*)


(* ::Subsubsection:: *)
(*Rule:*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]Tanh[a+b x]^2 \[DifferentialD]x  \[LongRightArrow]  x-Tanh[a+b x]/b*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[Tanh[a_.+b_.*x_]^2,x_Symbol] :=
  x - Tanh[a+b*x]/b /;
FreeQ[{a,b},x]


(* ::Subsubsection:: *)
(*Reference: G&R 2.423.38, CRC 573*)


(* ::Code:: *)
Int[Coth[a_.+b_.*x_]^2,x_Symbol] :=
  x - Coth[a+b*x]/b /;
FreeQ[{a,b},x]


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Reference: G&R 2.411.3, CRC 570, A&S 4.5.87*)


(* ::Subsubsection:: *)
(*Derivation: Integration by parts with a double-back flip*)


(* ::Subsubsection:: *)
(*Basis: Tanh[z]^n=(Tanh[z]^(n-1) Sinh[z])/Cosh[z]*)


(* ::Subsubsection:: *)
(*Rule: If  n>1, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral](c Tanh[a+b x])^n \[DifferentialD]x  \[LongRightArrow]  -((c (c Tanh[a+b x])^(n-1))/(b (n-1)))+c^2 \[Integral](c Tanh[a+b x])^(n-2) \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[(c_.*Tanh[a_.+b_.*x_])^n_,x_Symbol] :=
  -c*(c*Tanh[a+b*x])^(n-1)/(b*(n-1)) + 
  Dist[c^2,Int[(c*Tanh[a+b*x])^(n-2),x]] /;
FreeQ[{a,b,c},x] && RationalQ[n] && n>1


(* ::Subsubsection:: *)
(*Reference: G&R 2.411.4, CRC 574, A&S 4.5.88*)


(* ::Code:: *)
Int[(c_.*Coth[a_.+b_.*x_])^n_,x_Symbol] :=
  -c*(c*Coth[a+b*x])^(n-1)/(b*(n-1)) + 
  Dist[c^2,Int[(c*Coth[a+b*x])^(n-2),x]] /;
FreeQ[{a,b,c},x] && RationalQ[n] && n>1


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Reference: G&R 2.411.4, CRC 574'*)


(* ::Subsubsection:: *)
(*Derivation: Inverted integration by parts with a double-back flip*)


(* ::Subsubsection:: *)
(*Rule: If  n<-1, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral](c Tanh[a+b x])^n \[DifferentialD]x  \[LongRightArrow]  ((c Tanh[a+b x])^(n+1)/(b c (n+1)))+1/c^2 \[Integral](c Tanh[a+b x])^(n+2) \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[(c_.*Tanh[a_.+b_.*x_])^n_,x_Symbol] :=
  (c*Tanh[a+b*x])^(n+1)/(b*c*(n+1)) + 
  Dist[1/c^2,Int[(c*Tanh[a+b*x])^(n+2),x]] /;
FreeQ[{a,b,c},x] && RationalQ[n] && n<-1


(* ::Subsubsection:: *)
(*Reference: G&R 2.411.3, CRC 570'*)


(* ::Code:: *)
Int[(c_.*Coth[a_.+b_.*x_])^n_,x_Symbol] :=
  (c*Coth[a+b*x])^(n+1)/(b*c*(n+1)) + 
  Dist[1/c^2,Int[(c*Coth[a+b*x])^(n+2),x]] /;
FreeQ[{a,b,c},x] && RationalQ[n] && n<-1


(* ::PageBreak:: *)
(**)


(* ::Title::Bold::Closed:: *)
(*\[Integral](a+b Tanh[c+d x])^n \[DifferentialD]x  when  a^2-b^2=0*)


(* ::Subsubsection:: *)
(*Rule: If  a^2-b^2=0, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]1/(a+b Tanh[c+d x]) \[DifferentialD]x  \[LongRightArrow]  (x/(2 a))-a/(2 b d (a+b Tanh[c+d x]))*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[1/(a_+b_.*Tanh[c_.+d_.*x_]),x_Symbol] :=
  x/(2*a) - a/(2*b*d*(a+b*Tanh[c+d*x])) /;
FreeQ[{a,b,c,d},x] && ZeroQ[a^2-b^2]


(* ::Code:: *)
Int[1/(a_+b_.*Coth[c_.+d_.*x_]),x_Symbol] :=
  x/(2*a) - a/(2*b*d*(a+b*Coth[c+d*x])) /;
FreeQ[{a,b,c,d},x] && ZeroQ[a^2-b^2]


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Rule: If  a^2-b^2=0 \[And] a>0, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]Sqrt[a+b Tanh[c+d x]]\[DifferentialD]x  \[LongRightArrow]  ((Sqrt[2] b)/(d Sqrt[a]))ArcTanh[Sqrt[a+b Tanh[c+d x]]/(Sqrt[2] Sqrt[a])]*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[Sqrt[a_+b_.*Tanh[c_.+d_.*x_]],x_Symbol] :=
  Sqrt[2]*b/(d*Rt[a,2])*ArcTanh[Sqrt[a+b*Tanh[c+d*x]]/(Sqrt[2]*Rt[a,2])] /;
FreeQ[{a,b,c,d},x] && ZeroQ[a^2-b^2] && PosQ[a]


(* ::Code:: *)
Int[Sqrt[a_+b_.*Coth[c_.+d_.*x_]],x_Symbol] :=
  (Sqrt[2]*b/(d*Rt[a,2])*ArcCoth[Sqrt[a+b*Coth[c+d*x]]/(Sqrt[2]*Rt[a,2])]) /;
FreeQ[{a,b,c,d},x] && ZeroQ[a^2-b^2] && PosQ[a]


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Rule: If  a^2-b^2=0 \[And] \[Not](a>0), then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]Sqrt[a+b Tanh[c+d x]]\[DifferentialD]x  \[LongRightArrow]  -((Sqrt[2] b)/(d Sqrt[-a]))ArcTan[Sqrt[a+b Tanh[c+d x]]/(Sqrt[2] Sqrt[-a])]*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[Sqrt[a_+b_.*Tanh[c_.+d_.*x_]],x_Symbol] :=
  -Sqrt[2]*b/(d*Rt[-a,2])*ArcTan[Sqrt[a+b*Tanh[c+d*x]]/(Sqrt[2]*Rt[-a,2])] /;
FreeQ[{a,b,c,d},x] && ZeroQ[a^2-b^2] && NegQ[a]


(* ::Code:: *)
Int[Sqrt[a_+b_.*Coth[c_.+d_.*x_]],x_Symbol] :=
  Sqrt[2]*b/(d*Rt[-a,2])*ArcCot[Sqrt[a+b*Coth[c+d*x]]/(Sqrt[2]*Rt[-a,2])] /;
FreeQ[{a,b,c,d},x] && ZeroQ[a^2-b^2] && NegQ[a]


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Rule: If  a^2-b^2=0 \[And] n\[Element]\[DoubleStruckCapitalF] \[And] n>1, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral](a+b Tanh[c+d x])^n \[DifferentialD]x  \[LongRightArrow]  -((a^2 (a+b Tanh[c+d x])^(n-1))/(b d (n-1)))+2 a \[Integral](a+b Tanh[c+d x])^(n-1) \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[(a_+b_.*Tanh[c_.+d_.*x_])^n_,x_Symbol] :=
  -a^2*(a+b*Tanh[c+d*x])^(n-1)/(b*d*(n-1)) + 
  Dist[2*a,Int[(a+b*Tanh[c+d*x])^(n-1),x]] /;
FreeQ[{a,b,c,d},x] && ZeroQ[a^2-b^2] && FractionQ[n] && n>1


(* ::Code:: *)
Int[(a_+b_.*Coth[c_.+d_.*x_])^n_,x_Symbol] :=
  -a^2*(a+b*Coth[c+d*x])^(n-1)/(b*d*(n-1)) + 
  Dist[2*a,Int[(a+b*Coth[c+d*x])^(n-1),x]] /;
FreeQ[{a,b,c,d},x] && ZeroQ[a^2-b^2] && FractionQ[n] && n>1


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Rule: If  a^2-b^2=0 \[And] n<0, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral](a+b Tanh[c+d x])^n \[DifferentialD]x  \[LongRightArrow]  ((a (a+b Tanh[c+d x])^n)/(2 b d n))+1/(2 a) \[Integral](a+b Tanh[c+d x])^(n+1) \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[(a_+b_.*Tanh[c_.+d_.*x_])^n_,x_Symbol] :=
  a*(a+b*Tanh[c+d*x])^n/(2*b*d*n) + 
  Dist[1/(2*a),Int[(a+b*Tanh[c+d*x])^(n+1),x]] /;
FreeQ[{a,b,c,d},x] && ZeroQ[a^2-b^2] && RationalQ[n] && n<0


(* ::Code:: *)
Int[(a_+b_.*Coth[c_.+d_.*x_])^n_,x_Symbol] :=
  a*(a+b*Coth[c+d*x])^n/(2*b*d*n) + 
  Dist[1/(2*a),Int[(a+b*Coth[c+d*x])^(n+1),x]] /;
FreeQ[{a,b,c,d},x] && ZeroQ[a^2-b^2] && RationalQ[n] && n<0


(* ::PageBreak:: *)
(**)


(* ::Title::Bold::Closed:: *)
(*\[Integral](a+b Tanh[c+d x])^n \[DifferentialD]x  when  a^2+b^2!=0*)


(* ::Subsubsection:: *)
(*Derivation: Algebraic expansion and integration by substitution*)


(* ::Subsubsection:: *)
(*Basis: 1/(a+b Tanh[z])=a/(a^2-b^2)-b/((a^2-b^2) (a Cosh[z]+b Sinh[z])) \!\( *)
(*\*SubscriptBox[\(\[PartialD]\), \(z\)]\((a\ Cosh[z] + b\ Sinh[z])\)\)*)


(* ::Subsubsection:: *)
(*Rule: If  a^2-b^2!=0, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]1/(a+b Tanh[c+d x]) \[DifferentialD]x  \[LongRightArrow]  ((a x)/(a^2-b^2))-(b Log[a Cosh[c+d x]+b Sinh[c+d x]])/(d (a^2-b^2))*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[1/(a_+b_.*Tanh[c_.+d_.*x_]),x_Symbol] :=
  a*x/(a^2-b^2) - b*Log[a*Cosh[c+d*x]+b*Sinh[c+d*x]]/(d*(a^2-b^2)) /;
FreeQ[{a,b,c,d},x] && NonzeroQ[a^2-b^2]


(* ::Code:: *)
Int[1/(a_+b_.*Coth[c_.+d_.*x_]),x_Symbol] :=
  a*x/(a^2-b^2) - b*Log[b*Cosh[c+d*x]+a*Sinh[c+d*x]]/(d*(a^2-b^2)) /;
FreeQ[{a,b,c,d},x] && NonzeroQ[a^2-b^2]


(* ::PageBreak:: *)
(**)


(* ::Title::Bold::Closed:: *)
(*\[Integral](A+B Tanh[c+d x])(a+b Tanh[c+d x])^n \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Derivation: Algebraic expansion*)


(* ::Subsubsection:: *)
(*Basis: (A+B z)/(a+b z)=B/b+(b A-a B)/b 1/(a+b z)*)


(* ::Subsubsection:: *)
(*Rule: If  b A-a B!=0, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral](A+B Tanh[c+d x])/(a+b Tanh[c+d x]) \[DifferentialD]x  \[LongRightArrow]  ((B x)/b)+(b A-a B)/b \[Integral]1/(a+b Tanh[c+d x]) \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[(A_.+B_.*Tanh[c_.+d_.*x_])/(a_.+b_.*Tanh[c_.+d_.*x_]),x_Symbol] :=
  B*x/b + Dist[(b*A-a*B)/b,Int[1/(a+b*Tanh[c+d*x]),x]] /;
FreeQ[{a,b,c,d,A,B},x] && NonzeroQ[b*A-a*B]


(* ::Code:: *)
Int[(A_.+B_.*Coth[c_.+d_.*x_])/(a_.+b_.*Coth[c_.+d_.*x_]),x_Symbol] :=
  B*x/b + Dist[(b*A-a*B)/b,Int[1/(a+b*Coth[c+d*x]),x]] /;
FreeQ[{a,b,c,d,A,B},x] && NonzeroQ[b*A-a*B]


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Note: This rule does not appear in published integral tables.*)


(* ::Subsubsection:: *)
(*Rule: If  A^2-B^2=0 \[And] b A+a B!=0, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral](A+B Tanh[c+d x])/Sqrt[a+b Tanh[c+d x]] \[DifferentialD]x  \[LongRightArrow]  ((2 B)/(d Sqrt[(b A+a B)/B]))ArcTanh[Sqrt[a+b Tanh[c+d x]]/Sqrt[(b A+a B)/B]]*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[(A_+B_.*Tanh[c_.+d_.*x_])/Sqrt[a_.+b_.*Tanh[c_.+d_.*x_]],x_Symbol] :=
  2*B/(d*Sqrt[(b*A+a*B)/B])*ArcTanh[Sqrt[a+b*Tanh[c+d*x]]/Sqrt[(b*A+a*B)/B]] /;
FreeQ[{a,b,c,d,A,B},x] && ZeroQ[A^2-B^2] && NonzeroQ[b*A+a*B]


(* ::Code:: *)
Int[(A_+B_.*Coth[c_.+d_.*x_])/Sqrt[a_.+b_.*Coth[c_.+d_.*x_]],x_Symbol] :=
  2*B/(d*Sqrt[(b*A+a*B)/B])*ArcTanh[Sqrt[a+b*Coth[c+d*x]]/Sqrt[(b*A+a*B)/B]] /;
FreeQ[{a,b,c,d,A,B},x] && ZeroQ[A^2-B^2] && NonzeroQ[b*A+a*B]


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Derivation: Algebraic expansion*)


(* ::Subsubsection:: *)
(*Basis: A+B z=(A+B)/2 (1+z)+(A-B)/2 (1-z)*)


(* ::Subsubsection:: *)
(*Rule: If  A^2-B^2!=0 \[And] a^2-b^2!=0, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral](A+B Tanh[c+d x])/Sqrt[a+b Tanh[c+d x]] \[DifferentialD]x  \[LongRightArrow]  ((A+B)/2)\[Integral](1+Tanh[c+d x])/Sqrt[a+b Tanh[c+d x]] \[DifferentialD]x+(A-B)/2 \[Integral](1-Tanh[c+d x])/Sqrt[a+b Tanh[c+d x]] \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[(A_.+B_.*Tanh[c_.+d_.*x_])/Sqrt[a_.+b_.*Tanh[c_.+d_.*x_]],x_Symbol] :=
  Dist[(A+B)/2,Int[(1+Tanh[c+d*x])/Sqrt[a+b*Tanh[c+d*x]],x]] +
  Dist[(A-B)/2,Int[(1-Tanh[c+d*x])/Sqrt[a+b*Tanh[c+d*x]],x]] /;
FreeQ[{a,b,c,d,A,B},x] && NonzeroQ[A^2-B^2] && NonzeroQ[a^2-b^2]


(* ::Code:: *)
Int[(A_.+B_.*Coth[c_.+d_.*x_])/Sqrt[a_.+b_.*Coth[c_.+d_.*x_]],x_Symbol] :=
  Dist[(A+B)/2,Int[(1+Coth[c+d*x])/Sqrt[a+b*Coth[c+d*x]],x]] +
  Dist[(A-B)/2,Int[(1-Coth[c+d*x])/Sqrt[a+b*Coth[c+d*x]],x]] /;
FreeQ[{a,b,c,d,A,B},x] && NonzeroQ[A^2-B^2] && NonzeroQ[a^2-b^2]


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Note: This rule does not appear in published integral tables.*)


(* ::Subsubsection:: *)
(*Rule: If  n>0, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral](A+B Tanh[c+d x])(a+b Tanh[c+d x])^n \[DifferentialD]x  \[LongRightArrow]  *)
(*-((B (a+b Tanh[c+d x])^n)/(d n))+\[Integral](a A+b B+(b A+a B) Tanh[c+d x])(a+b Tanh[c+d x])^(n-1) \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[(A_.+B_.*Tanh[c_.+d_.*x_])*(a_+b_.*Tanh[c_.+d_.*x_])^n_.,x_Symbol] :=
  -B*(a+b*Tanh[c+d*x])^n/(d*n) + 
  Int[(a*A+b*B+(b*A+a*B)*Tanh[c+d*x])*(a+b*Tanh[c+d*x])^(n-1),x] /;
FreeQ[{a,b,c,d,A,B},x] && RationalQ[n] && n>0


(* ::Code:: *)
Int[(A_.+B_.*Coth[c_.+d_.*x_])*(a_+b_.*Coth[c_.+d_.*x_])^n_.,x_Symbol] :=
  -B*(a+b*Coth[c+d*x])^n/(d*n) + 
  Int[(a*A+b*B+(b*A+a*B)*Coth[c+d*x])*(a+b*Coth[c+d*x])^(n-1),x] /;
FreeQ[{a,b,c,d,A,B},x] && RationalQ[n] && n>0


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Note: This rule does not appear in published integral tables.*)


(* ::Subsubsection:: *)
(*Rule: If  a^2-b^2!=0 \[And] n<-1, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral](A+B Tanh[c+d x])(a+b Tanh[c+d x])^n \[DifferentialD]x  \[LongRightArrow]  *)
(*-(((b A-a B) (a+b Tanh[c+d x])^(n+1))/(d(a^2-b^2)(n+1)))+1/(a^2-b^2) \[Integral](a A-b B-(b A-a B) Tanh[c+d x])(a+b Tanh[c+d x])^(n+1) \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[(A_.+B_.*Tanh[c_.+d_.*x_])*(a_+b_.*Tanh[c_.+d_.*x_])^n_,x_Symbol] :=
  -(b*A-a*B)*(a+b*Tanh[c+d*x])^(n+1)/(d*(a^2-b^2)*(n+1)) + 
  Dist[1/(a^2-b^2),Int[(a*A-b*B-(b*A-a*B)*Tanh[c+d*x])*(a+b*Tanh[c+d*x])^(n+1),x]] /;
FreeQ[{a,b,c,d,A,B},x] && NonzeroQ[a^2-b^2] && RationalQ[n] && n<-1


(* ::Code:: *)
Int[(A_.+B_.*Coth[c_.+d_.*x_])*(a_+b_.*Coth[c_.+d_.*x_])^n_,x_Symbol] :=
  -(b*A-a*B)*(a+b*Coth[c+d*x])^(n+1)/(d*(a^2-b^2)*(n+1)) + 
  Dist[1/(a^2-b^2),Int[(a*A-b*B-(b*A-a*B)*Coth[c+d*x])*(a+b*Coth[c+d*x])^(n+1),x]] /;
FreeQ[{a,b,c,d,A,B},x] && NonzeroQ[a^2-b^2] && RationalQ[n] && n<-1


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


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Rule: If  a+b!=0, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]1/(a+b Tanh[c+d x]^2) \[DifferentialD]x  \[LongRightArrow]  (x/(a+b))+Sqrt[b]/(Sqrt[a] d (a+b)) ArcTan[(Sqrt[b] Tanh[c+d x])/Sqrt[a]]*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[1/(a_+b_.*Tanh[c_.+d_.*x_]^2),x_Symbol] :=
  x/(a+b) + Sqrt[b]*ArcTan[Sqrt[b]*Tanh[c+d*x]/Sqrt[a]]/(Sqrt[a]*d*(a+b)) /;
FreeQ[{a,b,c,d},x] && NonzeroQ[a+b]


(* ::Code:: *)
Int[1/(a_+b_.*Coth[c_.+d_.*x_]^2),x_Symbol] :=
  x/(a+b) + Sqrt[b]*ArcTan[Sqrt[b]*Coth[c+d*x]/Sqrt[a]]/(Sqrt[a]*d*(a+b)) /;
FreeQ[{a,b,c,d},x] && NonzeroQ[a+b]


(* ::PageBreak:: *)
(**)


(* ::Title::Bold::Closed:: *)
(*\[Integral]x^m Tanh[a+b x^n]^p \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Derivation: Algebraic expansion*)


(* ::Subsubsection:: *)
(*Basis: Tanh[z]=1-2/(1+E^(2z))*)


(* ::Subsubsection:: *)
(*Rule: If  m\[Element]\[DoubleStruckCapitalZ] \[And] m>0 \[And] m-n+1!=0, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]x^m Tanh[a+b x^n]\[DifferentialD]x  \[LongRightArrow]  (x^(m+1)/(m+1))-2\[Integral]x^m/(1+E^(2a+2b x^n)) \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[x_^m_.*Tanh[a_.+b_.*x_^n_.],x_Symbol] :=
  x^(m+1)/(m+1) - 
  Dist[2,Int[x^m/(1+E^(2*a+2*b*x^n)),x]] /;
FreeQ[{a,b,n},x] && IntegerQ[m] && m>0 && NonzeroQ[m-n+1]


(* ::Code:: *)
Int[x_^m_.*Coth[a_.+b_.*x_^n_.],x_Symbol] :=
  x^(m+1)/(m+1) - 
  Dist[2,Int[x^m/(1-E^(2*a+2*b*x^n)),x]] /;
FreeQ[{a,b,n},x] && IntegerQ[m] && m>0 && NonzeroQ[m-n+1]


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Note: This rule does not appear in published integral tables.*)


(* ::Subsubsection:: *)
(*Rule: If  p>1 \[And] m-n+1!=0 \[And] 0<n<=m, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]x^m Tanh[a+b x^n]^p \[DifferentialD]x  \[LongRightArrow]  -((x^(m-n+1) Tanh[a+b x^n]^(p-1))/(b n (p-1)))+*)
(*(m-n+1)/(b n (p-1)) \[Integral]x^(m-n) Tanh[a+b x^n]^(p-1) \[DifferentialD]x+\[Integral]x^m Tanh[a+b x^n]^(p-2) \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[x_^m_.*Tanh[a_.+b_.*x_^n_.]^p_,x_Symbol] :=
  -x^(m-n+1)*Tanh[a+b*x^n]^(p-1)/(b*n*(p-1)) + 
  Dist[(m-n+1)/(b*n*(p-1)),Int[x^(m-n)*Tanh[a+b*x^n]^(p-1),x]] + 
  Int[x^m*Tanh[a+b*x^n]^(p-2),x] /;
FreeQ[{a,b},x] && RationalQ[{m,n,p}] && p>1 && NonzeroQ[m-n+1] && 0<n<=m


(* ::Code:: *)
Int[x_^m_.*Coth[a_.+b_.*x_^n_.]^p_,x_Symbol] :=
  -x^(m-n+1)*Coth[a+b*x^n]^(p-1)/(b*n*(p-1)) + 
  Dist[(m-n+1)/(b*n*(p-1)),Int[x^(m-n)*Coth[a+b*x^n]^(p-1),x]] + 
  Int[x^m*Coth[a+b*x^n]^(p-2),x] /;
FreeQ[{a,b},x] && RationalQ[{m,n,p}] && p>1 && NonzeroQ[m-n+1] && 0<n<=m


(* ::PageBreak:: *)
(**)


(* ::Title::Bold::Closed:: *)
(*\[Integral]x^m Tanh[a+b x+c x^2]\[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Rule:*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]x Tanh[a+b x+c x^2]\[DifferentialD]x  \[LongRightArrow]  (Log[Cosh[a+b x+c x^2]]/(2 c))-b/(2 c) \[Integral]Tanh[a+b x+c x^2]\[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[x_*Tanh[a_.+b_.*x_+c_.*x_^2],x_Symbol] :=
  Log[Cosh[a+b*x+c*x^2]]/(2*c) -
  Dist[b/(2*c),Int[Tanh[a+b*x+c*x^2],x]] /;
FreeQ[{a,b,c},x]


(* ::Code:: *)
Int[x_*Coth[a_.+b_.*x_+c_.*x_^2],x_Symbol] :=
  Log[Sinh[a+b*x+c*x^2]]/(2*c) -
  Dist[b/(2*c),Int[Coth[a+b*x+c*x^2],x]] /;
FreeQ[{a,b,c},x]


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Note: This rule is valid, but to be useful need a rule for reducing integrands of the form x^m Log[Cosh[a+b x+c x^2]].*)


(* ::Subsubsection:: *)
(*Rule: If  m>1, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]x^m Tanh[a+b x+c x^2]\[DifferentialD]x  \[LongRightArrow]  ((x^(m-1) Log[Cosh[a+b x+c x^2]])/(2 c))-*)
(*b/(2 c) \[Integral]x^(m-1) Tanh[a+b x+c x^2]\[DifferentialD]x-(m-1)/(2 c) \[Integral]x^(m-2) Log[Cosh[a+b x+c x^2]]\[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
(* Int[x_^m_*Tanh[a_.+b_.*x_+c_.*x_^2],x_Symbol] :=
  x^(m-1)*Log[Cosh[a+b*x+c*x^2]]/(2*c) -
  Dist[b/(2*c),Int[x^(m-1)*Tanh[a+b*x+c*x^2],x]] -
  Dist[(m-1)/(2*c),Int[x^(m-2)*Log[Cosh[a+b*x+c*x^2]],x]] /;
FreeQ[{a,b,c},x] && RationalQ[m] && m>1 *)


(* ::Code:: *)
(* Int[x_^m_*Coth[a_.+b_.*x_+c_.*x_^2],x_Symbol] :=
  x^(m-1)*Log[Sinh[a+b*x+c*x^2]]/(2*c) -
  Dist[b/(2*c),Int[x^(m-1)*Coth[a+b*x+c*x^2],x]] -
  Dist[(m-1)/(2*c),Int[x^(m-2)*Log[Sinh[a+b*x+c*x^2]],x]] /;
FreeQ[{a,b,c},x] && RationalQ[m] && m>1 *)


(* ::PageBreak:: *)
(**)
