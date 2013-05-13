(* ::Package:: *)

(* ::Title::Bold::Closed:: *)
(*\[Integral]FresnelS[a+b x]^n \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Derivation: Integration by parts*)


(* ::Subsubsection:: *)
(*Rule:*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]FresnelS[a+b x]\[DifferentialD]x  \[LongRightArrow]  (((a+b x) FresnelS[a+b x])/b)+Cos[\[Pi]/2 (a+b x)^2]/(b \[Pi])*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[FresnelS[a_.+b_.*x_],x_Symbol] :=
  (a+b*x)*FresnelS[a+b*x]/b + Cos[Pi/2*(a+b*x)^2]/(b*Pi) /;
FreeQ[{a,b},x]


(* ::Code:: *)
Int[FresnelC[a_.+b_.*x_],x_Symbol] :=
  (a+b*x)*FresnelC[a+b*x]/b - Sin[Pi/2*(a+b*x)^2]/(b*Pi) /;
FreeQ[{a,b},x]


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Derivation: Integration by parts*)


(* ::Subsubsection:: *)
(*Rule:*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]FresnelS[a+b x]^2 \[DifferentialD]x  \[LongRightArrow]  (((a+b x) FresnelS[a+b x]^2)/b)-2\[Integral](a+b x) Sin[\[Pi]/2 (a+b x)^2] FresnelS[a+b x]\[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[FresnelS[a_.+b_.*x_]^2,x_Symbol] :=
  (a+b*x)*FresnelS[a+b*x]^2/b -
  Dist[2,Int[(a+b*x)*Sin[Pi/2*(a+b*x)^2]*FresnelS[a+b*x],x]] /;
FreeQ[{a,b},x]


(* ::Code:: *)
Int[FresnelC[a_.+b_.*x_]^2,x_Symbol] :=
  (a+b*x)*FresnelC[a+b*x]^2/b -
  Dist[2,Int[(a+b*x)*Cos[Pi/2*(a+b*x)^2]*FresnelC[a+b*x],x]] /;
FreeQ[{a,b},x]


(* ::PageBreak:: *)
(**)


(* ::Title::Bold::Closed:: *)
(*\[Integral]x^m FresnelS[a+b x]^n \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Derivation: Integration by parts*)


(* ::Subsubsection:: *)
(*Rule: If  m+1!=0, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]x^m FresnelS[a+b x]\[DifferentialD]x  \[LongRightArrow]  ((x^(m+1) FresnelS[a+b x])/(m+1))-b/(m+1) \[Integral]x^(m+1) Sin[\[Pi]/2 (a+b x)^2]\[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[x_^m_.*FresnelS[a_.+b_.*x_],x_Symbol] :=
  x^(m+1)*FresnelS[a+b*x]/(m+1) -
  Dist[b/(m+1),Int[x^(m+1)*Sin[Pi/2*(a+b*x)^2],x]] /;
FreeQ[{a,b,m},x] && NonzeroQ[m+1]


(* ::Code:: *)
Int[x_^m_.*FresnelC[a_.+b_.*x_],x_Symbol] :=
  x^(m+1)*FresnelC[a+b*x]/(m+1) -
  Dist[b/(m+1),Int[x^(m+1)*Cos[Pi/2*(a+b*x)^2],x]] /;
FreeQ[{a,b,m},x] && NonzeroQ[m+1]


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Derivation: Integration by parts*)


(* ::Subsubsection:: *)
(*Note: Also apply rule when m mod 4 = 1 when a closed-form antiderivative is defined for Cos[(\[Pi] x^2)/2] FresnelS[x].*)


(* ::Subsubsection:: *)
(*Rule: If  m\[Element]\[DoubleStruckCapitalZ] \[And] m+1!=0 \[And] (m>0 \[And]  m/2\[Element]\[DoubleStruckCapitalZ] \[Or] m mod 4=3), then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]x^m FresnelS[b x]^2 \[DifferentialD]x  \[LongRightArrow]  ((x^(m+1) FresnelS[b x]^2)/(m+1))-(2 b)/(m+1) \[Integral]x^(m+1) Sin[\[Pi]/2 b^2 x^2] FresnelS[b x]\[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[x_^m_*FresnelS[b_.*x_]^2,x_Symbol] :=
  x^(m+1)*FresnelS[b*x]^2/(m+1) -
  Dist[2*b/(m+1),Int[x^(m+1)*Sin[Pi/2*b^2*x^2]*FresnelS[b*x],x]] /;
FreeQ[b,x] && IntegerQ[m] && m+1!=0 && (m>0 && EvenQ[m] || Mod[m,4]==3)


(* ::Code:: *)
Int[x_^m_*FresnelC[b_.*x_]^2,x_Symbol] :=
  x^(m+1)*FresnelC[b*x]^2/(m+1) -
  Dist[2*b/(m+1),Int[x^(m+1)*Cos[Pi/2*b^2*x^2]*FresnelC[b*x],x]] /;
FreeQ[b,x] && IntegerQ[m] && m+1!=0 && (m>0 && EvenQ[m] || Mod[m,4]==3)


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Derivation: Integration by substitution*)


(* ::Subsubsection:: *)
(*Basis: x^m f[a+b x]=1/b (-(a/b)+(a+b x)/b)^m f[a+b x] \!\( *)
(*\*SubscriptBox[\(\[PartialD]\), \(x\)]\((a + b\ x)\)\)*)


(* ::Subsubsection:: *)
(*Note: Rule not necessary until a closed-form antiderivative is defined for Cos[(\[Pi] x^2)/2] FresnelS[x].*)


(* ::Subsubsection:: *)
(*Rule: If  m\[Element]\[DoubleStruckCapitalZ] \[And] m>0, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]x^m FresnelS[a+b x]^2 \[DifferentialD]x  \[LongRightArrow]  (1/b) Subst[\[Integral](-(a/b)+x/b)^m FresnelS[x]^2 \[DifferentialD]x,x,a+b x]*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
(* Int[x_^m_.*FresnelS[a_+b_.*x_]^2,x_Symbol] :=
  Dist[1/b,Subst[Int[(-a/b+x/b)^m*FresnelS[x]^2,x],x,a+b*x]] /;
FreeQ[{a,b},x] && IntegerQ[m] && m>0 *)


(* ::Code:: *)
(* Int[x_^m_.*FresnelC[a_+b_.*x_]^2,x_Symbol] :=
  Dist[1/b,Subst[Int[(-a/b+x/b)^m*FresnelC[x]^2,x],x,a+b*x]] /;
FreeQ[{a,b},x] && IntegerQ[m] && m>0 *)


(* ::PageBreak:: *)
(**)


(* ::Title::Bold::Closed:: *)
(*\[Integral]x^m Sin[\[Pi]/2  b^2 x^2] FresnelS[b x]\[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Derivation: Integration by parts special case*)


(* ::Subsubsection:: *)
(*Rule:*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]x Sin[\[Pi]/2  b^2 x^2]FresnelS[b x]\[DifferentialD]x  \[LongRightArrow]  -((Cos[\[Pi]/2  b^2 x^2]FresnelS[b x])/(\[Pi] b^2))+1/(2\[Pi] b) \[Integral]Sin[\[Pi]  b^2 x^2]\[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[x_*Sin[c_.*x_^2]*FresnelS[b_.*x_],x_Symbol] :=
  -Cos[Pi/2*b^2*x^2]*FresnelS[b*x]/(Pi*b^2) +
  Dist[1/(2*Pi*b),Int[Sin[Pi*b^2*x^2],x]] /;
FreeQ[{b,c},x] && ZeroQ[c-Pi/2*b^2]


(* ::Code:: *)
Int[x_*Cos[c_.*x_^2]*FresnelC[b_.*x_],x_Symbol] :=
  Sin[Pi/2*b^2*x^2]*FresnelC[b*x]/(Pi*b^2) -
  Dist[1/(2*Pi*b),Int[Sin[Pi*b^2*x^2],x]] /;
FreeQ[{b,c},x] && ZeroQ[c-Pi/2*b^2]


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Derivation: Integration by parts*)


(* ::Subsubsection:: *)
(*Note: Also apply rule when m mod 4 = 2 when a closed-form antiderivative is defined for Cos[(\[Pi] x^2)/2] FresnelS[x].*)


(* ::Subsubsection:: *)
(*Rule: If  m\[Element]\[DoubleStruckCapitalZ] \[And] m>1 \[And] \[Not](m mod 4=2), then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]x^m Sin[\[Pi]/2  b^2 x^2]FresnelS[b x]\[DifferentialD]x  \[LongRightArrow]  -((x^(m-1) Cos[\[Pi]/2  b^2 x^2]FresnelS[b x])/(\[Pi] b^2))+                                        *)
(*                                              1/(2\[Pi] b) \[Integral]x^(m-1) Sin[\[Pi]  b^2 x^2]\[DifferentialD]x+(m-1)/(\[Pi] b^2) \[Integral]x^(m-2) Cos[\[Pi]/2  b^2 x^2]FresnelS[b x]\[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[x_^m_*Sin[c_.*x_^2]*FresnelS[b_.*x_],x_Symbol] :=
  -x^(m-1)*Cos[Pi/2*b^2*x^2]*FresnelS[b*x]/(Pi*b^2) +
  Dist[1/(2*Pi*b),Int[x^(m-1)*Sin[Pi*b^2*x^2],x]] +
  Dist[(m-1)/(Pi*b^2),Int[x^(m-2)*Cos[Pi/2*b^2*x^2]*FresnelS[b*x],x]] /;
FreeQ[{b,c},x] && ZeroQ[c-Pi/2*b^2] && IntegerQ[m] && m>1 && Not[Mod[m,4]==2]


(* ::Code:: *)
Int[x_^m_*Cos[c_.*x_^2]*FresnelC[b_.*x_],x_Symbol] :=
  x^(m-1)*Sin[Pi/2*b^2*x^2]*FresnelC[b*x]/(Pi*b^2) -
  Dist[1/(2*Pi*b),Int[x^(m-1)*Sin[Pi*b^2*x^2],x]] -
  Dist[(m-1)/(Pi*b^2),Int[x^(m-2)*Sin[Pi/2*b^2*x^2]*FresnelC[b*x],x]] /;
FreeQ[{b,c},x] && ZeroQ[c-Pi/2*b^2] && IntegerQ[m] && m>1 && Not[Mod[m,4]==2]


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Derivation: Inverted integration by parts*)


(* ::Subsubsection:: *)
(*Rule: If  m\[Element]\[DoubleStruckCapitalZ] \[And] m<-2 \[And] m mod 4=0, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]x^m Sin[\[Pi]/2  b^2 x^2]FresnelS[b x]\[DifferentialD]x  \[LongRightArrow]  ((x^(m+1) Sin[\[Pi]/2  b^2 x^2]FresnelS[b x])/(m+1))-(b x^(m+2))/(2 (m+1) (m+2))+*)
(*                                            b/(2 (m+1)) \[Integral]x^(m+1) Cos[\[Pi]  b^2 x^2]\[DifferentialD]x-(\[Pi] b^2)/(m+1) \[Integral]x^(m+2) Cos[\[Pi]/2  b^2 x^2]FresnelS[b x]\[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[x_^m_*Sin[c_.*x_^2]*FresnelS[b_.*x_],x_Symbol] :=
  x^(m+1)*Sin[Pi/2*b^2*x^2]*FresnelS[b*x]/(m+1) - b*x^(m+2)/(2*(m+1)*(m+2)) +
  Dist[b/(2*(m+1)),Int[x^(m+1)*Cos[Pi*b^2*x^2],x]] -
  Dist[Pi*b^2/(m+1),Int[x^(m+2)*Cos[Pi/2*b^2*x^2]*FresnelS[b*x],x]] /;
FreeQ[{b,c},x] && ZeroQ[c-Pi/2*b^2] && IntegerQ[m] && m<-2 && Mod[m,4]==0


(* ::Code:: *)
Int[x_^m_*Cos[c_.*x_^2]*FresnelC[b_.*x_],x_Symbol] :=
  x^(m+1)*Cos[Pi/2*b^2*x^2]*FresnelC[b*x]/(m+1) - b*x^(m+2)/(2*(m+1)*(m+2)) -
  Dist[b/(2*(m+1)),Int[x^(m+1)*Cos[Pi*b^2*x^2],x]] +
  Dist[Pi*b^2/(m+1),Int[x^(m+2)*Sin[Pi/2*b^2*x^2]*FresnelC[b*x],x]] /;
FreeQ[{b,c},x] && ZeroQ[c-Pi/2*b^2] && IntegerQ[m] && m<-2 && Mod[m,4]==0


(* ::PageBreak:: *)
(**)


(* ::Title::Bold::Closed:: *)
(*\[Integral]x^m Cos[\[Pi]/2  b^2 x^2] FresnelS[b x]\[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Derivation: Integration by parts special case*)


(* ::Subsubsection:: *)
(*Rule:*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]x Cos[\[Pi]/2  b^2 x^2]FresnelS[b x]\[DifferentialD]x  \[LongRightArrow]  ((Sin[\[Pi]/2  b^2 x^2]FresnelS[b x])/(\[Pi] b^2))-x/(2 \[Pi] b)+1/(2\[Pi] b) \[Integral]Cos[\[Pi]  b^2 x^2]\[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[x_*Cos[c_.*x_^2]*FresnelS[b_.*x_],x_Symbol] :=
  Sin[Pi/2*b^2*x^2]*FresnelS[b*x]/(Pi*b^2) - x/(2*Pi*b) +
  Dist[1/(2*Pi*b),Int[Cos[Pi*b^2*x^2],x]] /;
FreeQ[{b,c},x] && ZeroQ[c-Pi/2*b^2]


(* ::Code:: *)
Int[x_*Sin[c_.*x_^2]*FresnelC[b_.*x_],x_Symbol] :=
  -Cos[Pi/2*b^2*x^2]*FresnelC[b*x]/(Pi*b^2) + x/(2*Pi*b) +
  Dist[1/(2*Pi*b),Int[Cos[Pi*b^2*x^2],x]] /;
FreeQ[{b,c},x] && ZeroQ[c-Pi/2*b^2]


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Derivation: Integration by parts*)


(* ::Subsubsection:: *)
(*Rule: If  m\[Element]\[DoubleStruckCapitalZ] \[And] m>1 \[And] \[Not](m mod 4=0), then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]x^m Cos[\[Pi]/2  b^2 x^2]FresnelS[b x]\[DifferentialD]x  \[LongRightArrow]  ((x^(m-1) Sin[\[Pi]/2  b^2 x^2]FresnelS[b x])/(\[Pi] b^2))- x^m/(2 b m \[Pi])+                                  *)
(*                                                  1/(2\[Pi] b) \[Integral]x^(m-1) Cos[\[Pi]  b^2 x^2]\[DifferentialD]x-(m-1)/(\[Pi] b^2) \[Integral]x^(m-2) Sin[\[Pi]/2  b^2 x^2]FresnelS[b x]\[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[x_^m_*Cos[c_.*x_^2]*FresnelS[b_.*x_],x_Symbol] :=
  x^(m-1)*Sin[Pi/2*b^2*x^2]*FresnelS[b*x]/(Pi*b^2) - x^m/(2*b*m*Pi) +
  Dist[1/(2*Pi*b),Int[x^(m-1)*Cos[Pi*b^2*x^2],x]] -
  Dist[(m-1)/(Pi*b^2),Int[x^(m-2)*Sin[Pi/2*b^2*x^2]*FresnelS[b*x],x]] /;
FreeQ[{b,c},x] && ZeroQ[c-Pi/2*b^2] && IntegerQ[m] && m>1 && Not[Mod[m,4]==0]


(* ::Code:: *)
Int[x_^m_*Sin[c_.*x_^2]*FresnelC[b_.*x_],x_Symbol] :=
  -x^(m-1)*Cos[Pi/2*b^2*x^2]*FresnelC[b*x]/(Pi*b^2) + x^m/(2*b*m*Pi) +
  Dist[1/(2*Pi*b),Int[x^(m-1)*Cos[Pi*b^2*x^2],x]] +
  Dist[(m-1)/(Pi*b^2),Int[x^(m-2)*Cos[Pi/2*b^2*x^2]*FresnelC[b*x],x]] /;
FreeQ[{b,c},x] && ZeroQ[c-Pi/2*b^2] && IntegerQ[m] && m>1 && Not[Mod[m,4]==0]


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Derivation: Inverted integration by parts*)


(* ::Subsubsection:: *)
(*Rule: If  m\[Element]\[DoubleStruckCapitalZ] \[And] m<-1 \[And] m mod 4=2, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]x^m Cos[\[Pi]/2  b^2 x^2]FresnelS[b x]\[DifferentialD]x  \[LongRightArrow]  ((x^(m+1) Cos[\[Pi]/2  b^2 x^2]FresnelS[b x])/(m+1))-                                            *)
(*                                            b/(2 (m+1)) \[Integral]x^(m+1) Sin[\[Pi]  b^2 x^2]\[DifferentialD]x+(\[Pi] b^2)/(m+1) \[Integral]x^(m+2) Sin[\[Pi]/2  b^2 x^2]FresnelS[b x]\[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[x_^m_*Cos[c_.*x_^2]*FresnelS[b_.*x_],x_Symbol] :=
  x^(m+1)*Cos[Pi/2*b^2*x^2]*FresnelS[b*x]/(m+1) -
  Dist[b/(2*(m+1)),Int[x^(m+1)*Sin[Pi*b^2*x^2],x]] +
  Dist[Pi*b^2/(m+1),Int[x^(m+2)*Sin[Pi/2*b^2*x^2]*FresnelS[b*x],x]] /;
FreeQ[{b,c},x] && ZeroQ[c-Pi/2*b^2] && IntegerQ[m] && m<-1 && Mod[m,4]==2


(* ::Code:: *)
Int[x_^m_*Sin[c_.*x_^2]*FresnelC[b_.*x_],x_Symbol] :=
  x^(m+1)*Sin[Pi/2*b^2*x^2]*FresnelC[b*x]/(m+1) -
  Dist[b/(2*(m+1)),Int[x^(m+1)*Sin[Pi*b^2*x^2],x]] -
  Dist[Pi*b^2/(m+1),Int[x^(m+2)*Cos[Pi/2*b^2*x^2]*FresnelC[b*x],x]] /;
FreeQ[{b,c},x] && ZeroQ[c-Pi/2*b^2] && IntegerQ[m] && m<-1 && Mod[m,4]==2


(* ::PageBreak:: *)
(**)
