(* ::Package:: *)

(* ::Title::Bold::Closed:: *)
(*\[Integral]1/Sqrt[a+b x+c x^2] \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Reference: G&R 2.261.3 which is correct only for b+2 c x>0*)


(* ::Subsubsection:: *)
(*Derivation: Piecewise constant extraction*)


(* ::Subsubsection:: *)
(*Basis: If  b^2-4 a c=0, then \!\( *)
(*\*SubscriptBox[\(\[PartialD]\), \(x\)]*)
(*\*FractionBox[\(b + 2\ c\ x\), *)
(*SqrtBox[\(a + b\ x + c\ *)
(*\*SuperscriptBox[\(x\), \(2\)]\)]]\)=0*)


(* ::Subsubsection:: *)
(*Rule: If  b^2-4 a c=0, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]1/Sqrt[a+b x+c x^2] \[DifferentialD]x  \[LongRightArrow]  ((b+2 c x)/Sqrt[a+b x+c x^2])\[Integral]1/(b+2 c x) \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[1/Sqrt[a_+b_.*x_+c_.*x_^2],x_Symbol] :=
  (b+2*c*x)/Sqrt[a+b*x+c*x^2]*Int[1/(b+2*c*x),x] /;
FreeQ[{a,b,c},x] && ZeroQ[b^2-4*a*c]


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Reference: G&R 2.261.2, CRC 237b, A&S 3.3.34*)


(* ::Subsubsection:: *)
(*Derivation: Primitive rule*)


(* ::Subsubsection:: *)
(*Basis: \!\( *)
(*\*SubscriptBox[\(\[PartialD]\), \(x\)]\(ArcSinh[x]\)\)=1/Sqrt[1+x^2]*)


(* ::Subsubsection:: *)
(*Note: Unlike the formulas in the references, this rule is valid even if c is not positive.*)


(* ::Subsubsection:: *)
(*Rule: If  4 a-b^2/c>0 \[And] c>0, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]1/Sqrt[a+b x+c x^2] \[DifferentialD]x  \[LongRightArrow]  (1/Sqrt[c]) ArcSinh[(b+2 c x)/(Sqrt[c] Sqrt[4 a-b^2/c])]*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[1/Sqrt[a_.+b_.*x_+c_.*x_^2],x_Symbol] :=
  ArcSinh[(b+2*c*x)/(Rt[c,2]*Sqrt[4*a-b^2/c])]/Rt[c,2] /;
FreeQ[{a,b,c},x] && PositiveQ[4*a-b^2/c] && PosQ[c]


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Reference: G&R 2.261.3, CRC 238, A&S 3.3.36*)


(* ::Subsubsection:: *)
(*Derivation: Primitive rule*)


(* ::Subsubsection:: *)
(*Basis: \!\( *)
(*\*SubscriptBox[\(\[PartialD]\), \(x\)]\(ArcSin[x]\)\)=1/Sqrt[1-x^2]*)


(* ::Subsubsection:: *)
(*Note: Unlike the formulas in the references, this rule is valid even if c is not positive.*)


(* ::Subsubsection:: *)
(*Rule: If  4 a-b^2/c>0 \[And] \[Not](c>0), then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]1/Sqrt[a+b x+c x^2] \[DifferentialD]x  \[LongRightArrow]  -(1/Sqrt[-c])ArcSin[(b+2 c x)/(Sqrt[-c] Sqrt[4 a-b^2/c])]*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[1/Sqrt[a_.+b_.*x_+c_.*x_^2],x_Symbol] :=
  -ArcSin[(b+2*c*x)/(Rt[-c,2]*Sqrt[4*a-b^2/c])]/Rt[-c,2] /;
FreeQ[{a,b,c},x] && PositiveQ[4*a-b^2/c] && NegQ[c]


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Rule: If  \[Not](4 a-b^2/c>0) \[And] c>0, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]1/Sqrt[b x+c x^2] \[DifferentialD]x  \[LongRightArrow]  (2/Sqrt[c]) ArcTanh[(Sqrt[c] x)/Sqrt[b x+c x^2]]*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[1/Sqrt[b_.*x_+c_.*x_^2],x_Symbol] :=
  2*ArcTanh[Rt[c,2]*x/Sqrt[b*x+c*x^2]]/Rt[c,2] /;
FreeQ[{b,c},x] && Not[PositiveQ[-b^2/c]] && PosQ[c]


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Rule: If  \[Not](4 a-b^2/c>0) \[And] \[Not](c>0), then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]1/Sqrt[b x+c x^2] \[DifferentialD]x  \[LongRightArrow]  (2/Sqrt[-c]) ArcTan[(Sqrt[-c] x)/Sqrt[b x+c x^2]]*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[1/Sqrt[b_.*x_+c_.*x_^2],x_Symbol] :=
  2*ArcTan[Rt[-c,2]*x/Sqrt[b*x+c*x^2]]/Rt[-c,2] /;
FreeQ[{b,c},x] && Not[PositiveQ[-b^2/c]] && NegQ[c]


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Reference: G&R 2.261.1, CRC 237a, A&S 3.3.33*)


(* ::Subsubsection:: *)
(*Derivation: Primitive rule*)


(* ::Subsubsection:: *)
(*Rule: If  b^2-4 a c!=0 \[And] c>0, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]1/Sqrt[a+b x+c x^2] \[DifferentialD]x  \[LongRightArrow]  (1/Sqrt[c])ArcTanh[(b+2 c x)/(2 Sqrt[c] Sqrt[a+b x+c x^2])]*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[1/Sqrt[a_+b_.*x_+c_.*x_^2],x_Symbol] :=
  ArcTanh[(b+2*c*x)/(2*Rt[c,2]*Sqrt[a+b*x+c*x^2])]/Rt[c,2] /;
FreeQ[{a,b,c},x] && NonzeroQ[b^2-4*a*c] && PosQ[c]


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Reference: CRC 238*)


(* ::Subsubsection:: *)
(*Derivation: Primitive rule*)


(* ::Subsubsection:: *)
(*Rule: If  b^2-4 a c!=0 \[And] \[Not](c>0), then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]1/Sqrt[a+b x+c x^2] \[DifferentialD]x  \[LongRightArrow]  -(1/Sqrt[-c])ArcTan[(b+2 c x)/(2 Sqrt[-c] Sqrt[a+b x+c x^2])]*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[1/Sqrt[a_+b_.*x_+c_.*x_^2],x_Symbol] :=
  -ArcTan[(b+2*c*x)/(2*Rt[-c,2]*Sqrt[a+b*x+c*x^2])]/Rt[-c,2] /;
FreeQ[{a,b,c},x] && NonzeroQ[b^2-4*a*c] && NegQ[c]


(* ::PageBreak:: *)
(**)


(* ::Title::Bold::Closed:: *)
(*\[Integral](a+b x+c x^2)^n \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Rule: If  b^2-4 a c=0 \[And] 2n+1!=0 \[And] n\[NotElement]\[DoubleStruckCapitalZ], then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral](a+b x+c x^2)^n \[DifferentialD]x  \[LongRightArrow]  (((b+2c x) (a+b x+c x^2)^n)/(2c (2 n+1)))*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[(a_+b_.*x_+c_.*x_^2)^n_,x_Symbol] :=
  (b+2*c*x)*(a+b*x+c*x^2)^n/(2*c*(2*n+1)) /;
FreeQ[{a,b,c,n},x] && ZeroQ[b^2-4*a*c] && NonzeroQ[2*n+1] && Not[IntegerQ[n]]


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Reference: G&R 2.264.5, CRC 239*)


(* ::Subsubsection:: *)
(*Rule: If  b^2-4 a c!=0, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]1/(a+b x+c x^2)^(3/2) \[DifferentialD]x  \[LongRightArrow]  -((2 (b+2 c x))/((b^2-4 a c) Sqrt[a+b x+c x^2]))*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[1/(a_.+b_.*x_+c_.*x_^2)^(3/2),x_Symbol] :=
  -2*(b+2*c*x)/((b^2-4*a*c)*Sqrt[a+b*x+c*x^2]) /;
FreeQ[{a,b,c},x] && NonzeroQ[b^2-4*a*c]


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Reference: G&R 2.260.2, CRC 245, A&S 3.3.37*)


(* ::Subsubsection:: *)
(*Rule: If  b^2-4 a c!=0 \[And] n\[Element]\[DoubleStruckCapitalF] \[And] n>0, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral](a+b x+c x^2)^n \[DifferentialD]x  \[LongRightArrow]  (((b+2 c x) (a+b x+c x^2)^n)/(2 c (2 n+1)))-(n (b^2-4 a c))/(2 c (2 n+1)) \[Integral](a+b x+c x^2)^(n-1) \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[(a_.+b_.*x_+c_.*x_^2)^n_,x_Symbol] :=
  (b+2*c*x)*(a+b*x+c*x^2)^n/(2*c*(2*n+1)) -
  Dist[n*(b^2-4*a*c)/(2*c*(2*n+1)),Int[(a+b*x+c*x^2)^(n-1),x]] /;
FreeQ[{a,b,c},x] && NonzeroQ[b^2-4*a*c] && FractionQ[n] && n>0


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Reference: G&R 2.263.3, CRC 241*)


(* ::Subsubsection:: *)
(*Rule: If  b^2-4 a c!=0 \[And] n\[Element]\[DoubleStruckCapitalF] \[And] n<-1, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral](a+b x+c x^2)^n \[DifferentialD]x  \[LongRightArrow]  (((b+2 c x) (a+b x+c x^2)^(n+1))/((n+1) (b^2-4 a c)))-(2 c (2 n+3))/((n+1) (b^2-4 a c)) \[Integral](a+b x+c x^2)^(n+1) \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[(a_.+b_.*x_+c_.*x_^2)^n_,x_Symbol] :=
  (b+2*c*x)*(a+b*x+c*x^2)^(n+1)/((n+1)*(b^2-4*a*c)) -
  Dist[2*c*(2*n+3)/((n+1)*(b^2-4*a*c)),Int[(a+b*x+c*x^2)^(n+1),x]] /;
FreeQ[{a,b,c},x] && NonzeroQ[b^2-4*a*c] && FractionQ[n] && n<-1


(* ::PageBreak:: *)
(**)


(* ::Title::Bold::Closed:: *)
(*\[Integral]1/((d+e x) Sqrt[a+c x^2]) \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Reference: G&R 2.266.7, CRC 260*)


(* ::Subsubsection:: *)
(*Note: This is an unnecessary special case of the integration rule for (d+e x)^m (a+c x^2)^n when m+2 (n+1)=0.*)


(* ::Subsubsection:: *)
(*Rule: If  c d^2+a e^2=0, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]1/((d+e x) Sqrt[a+c x^2]) \[DifferentialD]x  \[LongRightArrow]  ((e Sqrt[a+c x^2])/(c d (d+e x)))*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
(* Int[1/((d_+e_.*x_)*Sqrt[a_.+c_.*x_^2]),x_Symbol] :=
   e*Sqrt[a+c*x^2]/(c*d*(d+e*x)) /;
FreeQ[{a,c,d,e},x] && ZeroQ[c*d^2+a*e^2] *)


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Reference: G&R 2.266.1, CRC 258*)


(* ::Subsubsection:: *)
(*Rule: If  c d^2+a e^2>0, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]1/((d+e x) Sqrt[a+c x^2]) \[DifferentialD]x  \[LongRightArrow]  -(1/Sqrt[c d^2+a e^2])ArcTanh[(a e-c d x)/(Sqrt[c d^2+a e^2] Sqrt[a+c x^2])]*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[1/((d_+e_.*x_)*Sqrt[a_.+c_.*x_^2]),x_Symbol] :=
  -ArcTanh[(a*e-c*d*x)/(Rt[c*d^2+a*e^2,2]*Sqrt[a+c*x^2])]/Rt[c*d^2+a*e^2,2] /;
FreeQ[{a,c,d,e},x] && PosQ[c*d^2+a*e^2]


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Reference: G&R 2.266.3, CRC 259*)


(* ::Subsubsection:: *)
(*Rule: If  \[Not](c d^2+a e^2>0), then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]1/((d+e x) Sqrt[a+c x^2]) \[DifferentialD]x  \[LongRightArrow]  (1/Sqrt[-c d^2-a e^2])ArcTan[(a e-c d x)/(Sqrt[-c d^2-a e^2] Sqrt[a+c x^2])]*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[1/((d_+e_.*x_)*Sqrt[a_.+c_.*x_^2]),x_Symbol] :=
  ArcTan[(a*e-c*d*x)/(Rt[-c*d^2-a*e^2,2]*Sqrt[a+c*x^2])]/Rt[-c*d^2-a*e^2,2] /;
FreeQ[{a,c,d,e},x] && NegQ[c*d^2+a*e^2]


(* ::PageBreak:: *)
(**)


(* ::Title::Bold::Closed:: *)
(*\[Integral]1/((d+e x) Sqrt[a+b x+c x^2]) \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Reference: G&R 2.266.7, CRC 260*)


(* ::Subsubsection:: *)
(*Rule: If  c d^2-b d e+a e^2=0 \[And] 2c d-b e!=0, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]1/((d+e x) Sqrt[a+b x+c x^2]) \[DifferentialD]x  \[LongRightArrow]  ((2 e Sqrt[a+b x+c x^2])/((2c d-b e) (d+e x)))*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[1/((d_.+e_.*x_)*Sqrt[a_.+b_.*x_+c_.*x_^2]),x_Symbol] :=
  2*e*Sqrt[a+b*x+c*x^2]/((2*c*d-b*e)*(d+e*x)) /;
FreeQ[{a,b,c,d,e},x] && ZeroQ[c*d^2-b*d*e+a*e^2] && NonzeroQ[2*c*d-b*e]


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Reference: G&R 2.266.6 which is correct only for 2a+b x>0*)


(* ::Subsubsection:: *)
(*Derivation: Piecewise constant extraction*)


(* ::Subsubsection:: *)
(*Basis: If  b^2-4 a c=0, then \!\( *)
(*\*SubscriptBox[\(\[PartialD]\), \(x\)]*)
(*\*FractionBox[\(b + 2\ c\ x\), *)
(*SqrtBox[\(a + b\ x + c\ *)
(*\*SuperscriptBox[\(x\), \(2\)]\)]]\)=0*)


(* ::Subsubsection:: *)
(*Rule: If  b^2-4 a c=0, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]1/((d+e x) Sqrt[a+b x+c x^2]) \[DifferentialD]x  \[LongRightArrow]  ((b+2 c x)/Sqrt[a+b x+c x^2])\[Integral]1/((d+e x) (b+2 c x)) \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[1/((d_.+e_.*x_)*Sqrt[a_+b_.*x_+c_.*x_^2]),x_Symbol] :=
  (b+2*c*x)/Sqrt[a+b*x+c*x^2]*Int[1/((d+e*x)*(b+2*c*x)),x] /;
FreeQ[{a,b,c,d,e},x] && ZeroQ[b^2-4*a*c]


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Rule: If  2c d-b e=0 \[And] (b^2-4 a c)/c>0, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]1/((d+e x) Sqrt[a+b x+c x^2]) \[DifferentialD]x  \[LongRightArrow]  (2/(e Sqrt[(b^2-4 a c)/c]))ArcTan[(2 Sqrt[a+b x+c x^2])/Sqrt[(b^2-4 a c)/c]]*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[1/((d_.+e_.*x_)*Sqrt[a_.+b_.*x_+c_.*x_^2]),x_Symbol] :=
  2/(e*Rt[(b^2-4*a*c)/c,2])*ArcTan[2*Sqrt[a+b*x+c*x^2]/Rt[(b^2-4*a*c)/c,2]] /;
FreeQ[{a,b,c,d,e},x] && ZeroQ[2*c*d-b*e] && PosQ[(b^2-4*a*c)/c]


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Rule: If  2c d-b e=0 \[And] \[Not]((b^2-4 a c)/c>0), then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]1/((d+e x) Sqrt[a+b x+c x^2]) \[DifferentialD]x  \[LongRightArrow]  -(2/(e Sqrt[(4 a c-b^2)/c]))ArcTanh[(2 Sqrt[a+b x+c x^2])/Sqrt[(4 a c-b^2)/c]]*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[1/((d_.+e_.*x_)*Sqrt[a_.+b_.*x_+c_.*x_^2]),x_Symbol] :=
  -2/(e*Rt[(4*a*c-b^2)/c,2])*ArcTanh[2*Sqrt[a+b*x+c*x^2]/Rt[(4*a*c-b^2)/c,2]] /;
FreeQ[{a,b,c,d,e},x] && ZeroQ[2*c*d-b*e] && NegQ[(b^2-4*a*c)/c]


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Reference: G&R 2.266.1, CRC 258*)


(* ::Subsubsection:: *)
(*Rule: If  b^2-4 a c!=0 \[And] 2c d-b e!=0 \[And] c d^2-b d e+a e^2>0, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]1/((d+e x) Sqrt[a+b x+c x^2]) \[DifferentialD]x  \[LongRightArrow]  -(1/Sqrt[c d^2-b d e+a e^2])ArcTanh[(2 a e-b d-(2c d-b e) x)/(2 Sqrt[c d^2-b d e+a e^2] Sqrt[a+b x+c x^2])]*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[1/((d_.+e_.*x_)*Sqrt[a_.+b_.*x_+c_.*x_^2]),x_Symbol] :=
  -1/Rt[c*d^2-b*d*e+a*e^2,2]*
  ArcTanh[(2*a*e-b*d-(2*c*d-b*e)*x)/(2*Rt[c*d^2-b*d*e+a*e^2,2]*Sqrt[a+b*x+c*x^2])] /;
FreeQ[{a,b,c,d,e},x] && NonzeroQ[b^2-4*a*c] && NonzeroQ[2*c*d-b*e] && PosQ[c*d^2-b*d*e+a*e^2]


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Reference: G&R 2.266.3, CRC 259*)


(* ::Subsubsection:: *)
(*Rule: If  b^2-4 a c!=0 \[And] 2c d-b e!=0 \[And] \[Not](c d^2-b d e+a e^2>0), then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]1/((d+e x) Sqrt[a+b x+c x^2]) \[DifferentialD]x  \[LongRightArrow]  (1/Sqrt[-c d^2+b d e-a e^2])ArcTan[(2 a e-b d-(2c d-b e) x)/(2 Sqrt[-c d^2+b d e-a e^2] Sqrt[a+b x+c x^2])]*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[1/((d_.+e_.*x_)*Sqrt[a_.+b_.*x_+c_.*x_^2]),x_Symbol] :=
  1/Rt[-c*d^2+b*d*e-a*e^2,2]*
  ArcTan[(2*a*e-b*d-(2*c*d-b*e)*x)/(2*Rt[-c*d^2+b*d*e-a*e^2,2]*Sqrt[a+b*x+c*x^2])] /;
FreeQ[{a,b,c,d,e},x] && NonzeroQ[b^2-4*a*c] && NonzeroQ[2*c*d-b*e] && NegQ[c*d^2-b*d*e+a*e^2]


(* ::PageBreak:: *)
(**)


(* ::Title::Bold::Closed:: *)
(*\[Integral](a+b x+c x^2)^n/(d+e x) \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Reference: G&R 2.265b*)


(* ::Subsubsection:: *)
(*Rule: If  n\[Element]\[DoubleStruckCapitalF] \[And] n>0 \[And] c d^2-b d e+a e^2=0, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral](a+b x+c x^2)^n/(d+e x) \[DifferentialD]x  \[LongRightArrow]  ((a+b x+c x^2)^n/(2 e n))-(2 c d-b e)/(2 e^2) \[Integral](a+b x+c x^2)^(n-1) \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[(a_.+b_.*x_+c_.*x_^2)^n_/(d_.+e_.*x_),x_Symbol] :=
  (a+b*x+c*x^2)^n/(2*e*n) -
  Dist[(2*c*d-b*e)/(2*e^2),Int[(a+b*x+c*x^2)^(n-1),x]] /;
FreeQ[{a,b,c,d,e},x] && FractionQ[n] && n>0 && ZeroQ[c*d^2-b*d*e+a*e^2]


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Reference: G&R 2.265b*)


(* ::Subsubsection:: *)
(*Rule: If  n\[Element]\[DoubleStruckCapitalF] \[And] n>0 \[And] 2 c d-b e=0, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral](a+b x+c x^2)^n/(d+e x) \[DifferentialD]x  \[LongRightArrow]  ((a+b x+c x^2)^n/(2 e n))+(c d^2-b d e+a e^2)/e^2 \[Integral](a+b x+c x^2)^(n-1)/(d+e x) \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[(a_.+b_.*x_+c_.*x_^2)^n_/(d_.+e_.*x_),x_Symbol] :=
  (a+b*x+c*x^2)^n/(2*e*n) +
  Dist[(c*d^2-b*d*e+a*e^2)/e^2,Int[(a+b*x+c*x^2)^(n-1)/(d+e*x),x]] /;
FreeQ[{a,b,c,d,e},x] && FractionQ[n] && n>0 && ZeroQ[2*c*d-b*e]


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Reference: G&R 2.265b*)


(* ::Subsubsection:: *)
(*Rule: If  n\[Element]\[DoubleStruckCapitalF] \[And] n>0, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral](a+b x+c x^2)^n/(d+e x) \[DifferentialD]x  \[LongRightArrow]  ((a+b x+c x^2)^n/(2 e n))-                                                                        *)
(*               (2 c d-b e)/(2 e^2) \[Integral](a+b x+c x^2)^(n-1) \[DifferentialD]x+(c d^2-b d e+a e^2)/e^2 \[Integral](a+b x+c x^2)^(n-1)/(d+e x) \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[(a_.+b_.*x_+c_.*x_^2)^n_/(d_.+e_.*x_),x_Symbol] :=
  (a+b*x+c*x^2)^n/(2*e*n) -
  Dist[(2*c*d-b*e)/(2*e^2), Int[(a+b*x+c*x^2)^(n-1),x]] +
  Dist[(c*d^2-b*d*e+a*e^2)/e^2,Int[(a+b*x+c*x^2)^(n-1)/(d+e*x),x]] /;
FreeQ[{a,b,c,d,e},x] && FractionQ[n] && n>0


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Reference: G&R 2.268b, CRC 122*)


(* ::Subsubsection:: *)
(*Rule: If  n\[Element]\[DoubleStruckCapitalF] \[And] n<-1 \[And] c d^2-b d e+a e^2!=0 \[And] b e-2 c d=0, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral](a+b x+c x^2)^n/(d+e x) \[DifferentialD]x  \[LongRightArrow]  -((e (a+b x+c x^2)^(n+1))/(2 (n+1) (c d^2-b d e+a e^2)))+e^2/(c d^2-b d e+a e^2) \[Integral](a+b x+c x^2)^(n+1)/(d+e x) \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[(a_.+b_.*x_+c_.*x_^2)^n_/(d_.+e_.*x_),x_Symbol] :=
  -e*(a+b*x+c*x^2)^(n+1)/(2*(n+1)*(c*d^2-b*d*e+a*e^2)) +
  Dist[e^2/(c*d^2-b*d*e+a*e^2),Int[(a+b*x+c*x^2)^(n+1)/(d+e*x),x]] /;
FreeQ[{a,b,c,d,e},x] && FractionQ[n] && n<-1 && NonzeroQ[c*d^2-b*d*e+a*e^2] && ZeroQ[2*c*d-b*e]


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Reference: G&R 2.268b, CRC 122*)


(* ::Subsubsection:: *)
(*Rule: If  n\[Element]\[DoubleStruckCapitalF] \[And] n<-1 \[And] c d^2-b d e+a e^2!=0, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral](a+b x+c x^2)^n/(d+e x) \[DifferentialD]x  \[LongRightArrow]  -((e (a+b x+c x^2)^(n+1))/(2 (n+1) (c d^2-b d e+a e^2)))+                                                                       *)
(*                      (2 c d-b e)/(2 (c d^2-b d e+a e^2)) \[Integral](a+b x+c x^2)^n \[DifferentialD]x+e^2/(c d^2-b d e+a e^2) \[Integral](a+b x+c x^2)^(n+1)/(d+e x) \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[(a_.+b_.*x_+c_.*x_^2)^n_/(d_.+e_.*x_),x_Symbol] :=
  -e*(a+b*x+c*x^2)^(n+1)/(2*(n+1)*(c*d^2-b*d*e+a*e^2)) +
  Dist[(2*c*d-b*e)/(2*(c*d^2-b*d*e+a*e^2)), Int[(a+b*x+c*x^2)^n,x]] +
  Dist[e^2/(c*d^2-b*d*e+a*e^2),Int[(a+b*x+c*x^2)^(n+1)/(d+e*x),x]] /;
FreeQ[{a,b,c,d,e},x] && FractionQ[n] && n<-1 && NonzeroQ[c*d^2-b*d*e+a*e^2]


(* ::PageBreak:: *)
(**)


(* ::Title::Bold::Closed:: *)
(*\[Integral]1/Sqrt[a+b x^2+c x^4] \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Derivation: Algebraic expansion and piecewise constant extraction*)


(* ::Subsubsection:: *)
(*Basis: If  q=Sqrt[b^2-4 a c], then  a+b x^2+c x^4=a (1+(2 c x^2)/(b-q)) (1+(2 c x^2)/(b+q))*)


(* ::Subsubsection:: *)
(*Basis: If  q=Sqrt[b^2-4 a c], then  \!\( *)
(*\*SubscriptBox[\(\[PartialD]\), \(x\)]*)
(*\*FractionBox[\( *)
(*\*SqrtBox[\(1 + *)
(*\*FractionBox[\(2\ c\ *)
(*\*SuperscriptBox[\(x\), \(2\)]\), \(b - q\)]\)]\ *)
(*\*SqrtBox[\(1 + *)
(*\*FractionBox[\(2\ c\ *)
(*\*SuperscriptBox[\(x\), \(2\)]\), \(b + q\)]\)]\), *)
(*SqrtBox[\(a + b\ *)
(*\*SuperscriptBox[\(x\), \(2\)] + c\ *)
(*\*SuperscriptBox[\(x\), \(4\)]\)]]\)=0*)


(* ::Subsubsection:: *)
(*Rule: If  b^2-4 a c!=0, let q=Sqrt[b^2-4 a c], then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]1/Sqrt[a+b x^2+c x^4] \[DifferentialD]x  \[LongRightArrow]  ((Sqrt[1+(2 c x^2)/(b-q)] Sqrt[1+(2 c x^2)/(b+q)])/Sqrt[a+b x^2+c x^4])\[Integral]1/(Sqrt[1+(2 c x^2)/(b-q)] Sqrt[1+(2 c x^2)/(b+q)]) \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[1/Sqrt[a_+b_.*x_^2+c_.*x_^4],x_Symbol] :=
  Module[{q=Rt[b^2-4*a*c,2]},
  Sqrt[1+2*c*x^2/(b-q)]*Sqrt[1+2*c*x^2/(b+q)]/Sqrt[a+b*x^2+c*x^4]*
  Int[1/(Sqrt[1+2*c*x^2/(b-q)]*Sqrt[1+2*c*x^2/(b+q)]),x]] /;
FreeQ[{a,b,c},x] && NonzeroQ[b^2-4*a*c]


(* ::PageBreak:: *)
(**)


(* ::Title::Bold::Closed:: *)
(*\[Integral](d+e x^2)/Sqrt[a+b x^2+c x^4] \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Derivation: Piecewise constant extraction*)


(* ::Subsubsection:: *)
(*Basis: If  b^2-4 a c=0, then  \!\( *)
(*\*SubscriptBox[\(\[PartialD]\), \(x\)]*)
(*\*FractionBox[\(b + 2\ c\ *)
(*\*SuperscriptBox[\(x\), \(2\)]\), *)
(*SqrtBox[\(a + b\ *)
(*\*SuperscriptBox[\(x\), \(2\)] + c\ *)
(*\*SuperscriptBox[\(x\), \(4\)]\)]]\)=0*)


(* ::Subsubsection:: *)
(*Rule: If  b^2-4 a c=0, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral](d+e x^2)/Sqrt[a+b x^2+c x^4] \[DifferentialD]x  \[LongRightArrow]  ((b+2 c x^2)/Sqrt[a+b x^2+c x^4])\[Integral](d+e x^2)/(b+2 c x^2) \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[(d_.+e_.*x_^2)/Sqrt[a_+b_.*x_^2+c_.*x_^4],x_Symbol] :=
  Dist[(b+2*c*x^2)/Sqrt[a+b*x^2+c*x^4],Int[(d+e*x^2)/(b+2*c*x^2),x]] /;
FreeQ[{a,b,c,d,e},x] && ZeroQ[b^2-4*a*c]


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Derivation: Algebraic expansion*)


(* ::Subsubsection:: *)
(*Basis: If  a>0, let q=Sqrt[b^2-4 a c], then  Sqrt[a+b x^2+c x^4]=Sqrt[a] Sqrt[1+(2 c x^2)/(b-q)] Sqrt[1+(2 c x^2)/(b+q)]*)


(* ::Subsubsection:: *)
(*Rule: If  b^2-4 a c!=0 \[And] a>0, let q=Sqrt[b^2-4 a c], then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral](d+e x^2)/Sqrt[a+b x^2+c x^4] \[DifferentialD]x  \[LongRightArrow]  (1/Sqrt[a])\[Integral](d+e x^2)/(Sqrt[1+(2 c x^2)/(b-q)] Sqrt[1+(2 c x^2)/(b+q)]) \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[(d_.+e_.*x_^2)/Sqrt[a_+b_.*x_^2+c_.*x_^4],x_Symbol] :=
  Module[{q=Rt[b^2-4*a*c,2]},
  Dist[1/Sqrt[a],Int[(d+e*x^2)/(Sqrt[1+2*c*x^2/(b-q)]*Sqrt[1+2*c*x^2/(b+q)]),x]]] /;
FreeQ[{a,b,c,d,e},x] && NonzeroQ[b^2-4*a*c] && PositiveQ[a]


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Derivation: Algebraic expansion and piecewise constant extraction*)


(* ::Subsubsection:: *)
(*Basis: If  q=Sqrt[b^2-4 a c], then  a+b x^2+c x^4=a (1+(2 c x^2)/(b-q)) (1+(2 c x^2)/(b+q))*)


(* ::Subsubsection:: *)
(*Basis: If  q=Sqrt[b^2-4 a c], then  \!\( *)
(*\*SubscriptBox[\(\[PartialD]\), \(x\)]*)
(*\*FractionBox[\( *)
(*\*SqrtBox[\(1 + *)
(*\*FractionBox[\(2\ c\ *)
(*\*SuperscriptBox[\(x\), \(2\)]\), \(b - q\)]\)]\ *)
(*\*SqrtBox[\(1 + *)
(*\*FractionBox[\(2\ c\ *)
(*\*SuperscriptBox[\(x\), \(2\)]\), \(b + q\)]\)]\), *)
(*SqrtBox[\(a + b\ *)
(*\*SuperscriptBox[\(x\), \(2\)] + c\ *)
(*\*SuperscriptBox[\(x\), \(4\)]\)]]\)=0*)


(* ::Subsubsection:: *)
(*Rule: If  b^2-4 a c!=0, let q=Sqrt[b^2-4 a c], then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral](d+e x^2)/Sqrt[a+b x^2+c x^4] \[DifferentialD]x  \[LongRightArrow]  ((Sqrt[1+(2 c x^2)/(b-q)] Sqrt[1+(2 c x^2)/(b+q)])/Sqrt[a+b x^2+c x^4])\[Integral](d+e x^2)/(Sqrt[1+(2 c x^2)/(b-q)] Sqrt[1+(2 c x^2)/(b+q)]) \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[(d_.+e_.*x_^2)/Sqrt[a_+b_.*x_^2+c_.*x_^4],x_Symbol] :=
  Module[{q=Rt[b^2-4*a*c,2]},
  Sqrt[1+2*c*x^2/(b-q)]*Sqrt[1+2*c*x^2/(b+q)]/Sqrt[a+b*x^2+c*x^4]*
  Int[(d+e*x^2)/(Sqrt[1+2*c*x^2/(b-q)]*Sqrt[1+2*c*x^2/(b+q)]),x]] /;
FreeQ[{a,b,c,d,e},x] && NonzeroQ[b^2-4*a*c]


(* ::PageBreak:: *)
(**)


(* ::Title::Bold::Closed:: *)
(*\[Integral]1/(x Sqrt[a+b x^n+c x^(2 n)]) \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Reference: G&R 2.266.7, CRC 260*)


(* ::Subsubsection:: *)
(*Rule:*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]1/(x Sqrt[b x^n+c x^(2 n)]) \[DifferentialD]x  \[LongRightArrow]  -((2 Sqrt[b x^n+c x^(2n)])/(b n x^n))*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[1/(x_*Sqrt[b_.*x_^n_.+c_.*x_^j_.]),x_Symbol] :=
  -2*Sqrt[b*x^n+c*x^j]/(b*n*x^n) /;
FreeQ[{b,c,n},x] && ZeroQ[j-2*n]


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Reference: G&R 2.266.1, CRC 258*)


(* ::Subsubsection:: *)
(*Rule: If   b^2-4 a c!=0 \[And] a>0, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]1/(x Sqrt[a+b x^n+c x^(2 n)]) \[DifferentialD]x  \[LongRightArrow]  -(1/(Sqrt[a] n))ArcTanh[(2 a+b x^n)/(2 Sqrt[a] Sqrt[a+b x^n+c x^(2 n)])]*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[1/(x_*Sqrt[a_+b_.*x_^n_.+c_.*x_^j_.]),x_Symbol] :=
  -ArcTanh[(2*a+b*x^n)/(2*Rt[a,2]*Sqrt[a+b*x^n+c*x^j])]/(n*Rt[a,2]) /;
FreeQ[{a,b,c,n},x] && ZeroQ[j-2*n] && NonzeroQ[b^2-4*a*c] && PosQ[a]


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Reference: G&R 2.266.3, CRC 259*)


(* ::Subsubsection:: *)
(*Rule: If   b^2-4 a c!=0 \[And] \[Not](a>0), then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]1/(x Sqrt[a+b x^n+c x^(2 n)]) \[DifferentialD]x  \[LongRightArrow]  (1/(Sqrt[-a] n))ArcTan[(2 a+b x^n)/(2 Sqrt[-a] Sqrt[a+b x^n+c x^(2 n)])]*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[1/(x_*Sqrt[a_+b_.*x_^n_.+c_.*x_^j_.]),x_Symbol] :=
  ArcTan[(2*a+b*x^n)/(2*Rt[-a,2]*Sqrt[a+b*x^n+c*x^j])]/(n*Rt[-a,2]) /;
FreeQ[{a,b,c,n},x] && ZeroQ[j-2*n] && NonzeroQ[b^2-4*a*c] && NegQ[a]


(* ::PageBreak:: *)
(**)


(* ::Title::Bold::Closed:: *)
(*\[Integral](a+b x^n+c x^(2 n))^p \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Derivation: Algebraic manipulation and piecewise constant extraction*)


(* ::Subsubsection:: *)
(*Basis: If  p-1/2\[Element]\[DoubleStruckCapitalZ] and b^2-4 a c=0, then (a+b x^n+c x^(2 n))^p=Sqrt[a+b x^n+c x^(2 n)]/((4 c)^(p-1/2) (b+2 c x^n)) (b+2 c x^n)^(2 p)*)


(* ::Subsubsection:: *)
(*Basis: If  b^2-4 a c=0, then \!\( *)
(*\*SubscriptBox[\(\[PartialD]\), \(x\)]*)
(*\*FractionBox[*)
(*SqrtBox[\(a + b\ *)
(*\*SuperscriptBox[\(x\), \(n\)] + c\ *)
(*\*SuperscriptBox[\(x\), \(2\ n\)]\)], \((b + 2\ c\ *)
(*\*SuperscriptBox[\(x\), \(n\)])\)]\)=0*)


(* ::Subsubsection:: *)
(*Rule: If  n,p-1/2\[Element]\[DoubleStruckCapitalZ] \[And] n>1 \[And] p>0 \[And] b^2-4 a c=0, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral](a+b x^n+c x^(2 n))^p \[DifferentialD]x  \[LongRightArrow]  (Sqrt[a+b x^n+c x^(2 n)]/((4 c)^(p-1/2) (b+2 c x^n)))\[Integral](b+2 c x^n)^(2 p) \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[(a_+b_.*x_^n_+c_.*x_^j_)^p_,x_Symbol] :=
  Sqrt[a+b*x^n+c*x^(2*n)]/(b+2*c*x^n)*Dist[1/(4*c)^(p-1/2),Int[(b+2*c*x^n)^(2*p),x]] /;
FreeQ[{a,b,c},x] && ZeroQ[j-2*n] && IntegersQ[n,p-1/2] && n>1 && p>0 && ZeroQ[b^2-4*a*c]


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Derivation: Algebraic manipulation and piecewise constant extraction*)


(* ::Subsubsection:: *)
(*Basis: If  p-1/2\[Element]\[DoubleStruckCapitalZ] and b^2-4 a c=0, then (a+b x^n+c x^(2 n))^p=(b+2 c x^n)/((4 c)^(p+1/2) Sqrt[a+b x^n+c x^(2 n)]) (b+2 c x^n)^(2 p)*)


(* ::Subsubsection:: *)
(*Basis: If  b^2-4 a c=0, then \!\( *)
(*\*SubscriptBox[\(\[PartialD]\), \(x\)]*)
(*\*FractionBox[\(b + 2\ c\ *)
(*\*SuperscriptBox[\(x\), \(n\)]\), *)
(*SqrtBox[\(a + b\ *)
(*\*SuperscriptBox[\(x\), \(n\)] + c\ *)
(*\*SuperscriptBox[\(x\), \(2\ n\)]\)]]\)=0*)


(* ::Subsubsection:: *)
(*Rule: If  n,p+1/2\[Element]\[DoubleStruckCapitalZ] \[And] n>1 \[And] p<0 \[And] b^2-4 a c=0, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral](a+b x^n+c x^(2 n))^p \[DifferentialD]x  \[LongRightArrow]  ((b+2 c x^n)/((4 c)^(p+1/2) Sqrt[a+b x^n+c x^(2 n)]))\[Integral](b+2 c x^n)^(2 p) \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[(a_+b_.*x_^n_+c_.*x_^j_)^p_,x_Symbol] :=
  (b+2*c*x^n)/Sqrt[a+b*x^n+c*x^(2*n)]*Dist[1/(4*c)^(p+1/2),Int[(b+2*c*x^n)^(2*p),x]] /;
FreeQ[{a,b,c},x] && ZeroQ[j-2*n] && IntegersQ[n,p+1/2] && n>1 && p<0 && ZeroQ[b^2-4*a*c]


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Note: Previously undiscovered rule?*)


(* ::Subsubsection:: *)
(*Note: Although the resulting integrand appears more complicated than the original, it has the form of another new rule.*)


(* ::Subsubsection:: *)
(*Rule: If  n\[Element]\[DoubleStruckCapitalZ] \[And] n>1 \[And] p\[Element]\[DoubleStruckCapitalF] \[And] p>0 \[And] b^2-4a c!=0 \[And] 2n p+1!=0, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral](a+b x^n+c x^(2 n))^p \[DifferentialD]x  \[LongRightArrow]  ((x (a+b x^n+c x^(2 n))^p)/(2 n p+1))+(n p)/(2 n p+1) \[Integral](2 a+b x^n) (a+b x^n+c x^(2 n))^(p-1) \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[(a_+b_.*x_^n_+c_.*x_^j_)^p_,x_Symbol] :=
  x*(a+b*x^n+c*x^(2*n))^p/(2*n*p+1) +
  Dist[n*p/(2*n*p+1),Int[(2*a+b*x^n)*(a+b*x^n+c*x^(2*n))^(p-1),x]] /;
FreeQ[{a,b,c},x] && ZeroQ[j-2*n] && IntegerQ[n] && n>1 && FractionQ[p] && p>0 && 
NonzeroQ[b^2-4*a*c] && NonzeroQ[2*n*p+1]


(* ::PageBreak:: *)
(**)


(* ::Title::Bold::Closed:: *)
(*\[Integral]x^m (a+b x^n+c x^(2 n))^p \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Reference: G&R 2.265c*)


(* ::Subsubsection:: *)
(*Rule: If   p\[Element]\[DoubleStruckCapitalF]\[And] p<-(1/2), then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral](b x+c x^2)^p/x \[DifferentialD]x  \[LongRightArrow]  ((b x+c x^2)^(p+1)/(b p x))-(c (2 p+1))/(b p) \[Integral](b x+c x^2)^p \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[(b_.*x_+c_.*x_^2)^p_/x_,x_Symbol] :=
  (b*x+c*x^2)^(p+1)/(b*p*x) -
  Dist[c*(2*p+1)/(b*p),Int[(b*x+c*x^2)^p,x]] /;
FreeQ[{b,c},x] && FractionQ[p] && p<-1/2


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Derivation: Algebraic manipulation and piecewise constant extraction*)


(* ::Subsubsection:: *)
(*Basis: If  p-1/2\[Element]\[DoubleStruckCapitalZ] and b^2-4 a c=0, then (a+b x^n+c x^(2 n))^p=Sqrt[a+b x^n+c x^(2 n)]/((4 c)^(p-1/2) (b+2 c x^n)) (b+2 c x^n)^(2 p)*)


(* ::Subsubsection:: *)
(*Basis: If  b^2-4 a c=0, then \!\( *)
(*\*SubscriptBox[\(\[PartialD]\), \(x\)]*)
(*\*FractionBox[*)
(*SqrtBox[\(a + b\ *)
(*\*SuperscriptBox[\(x\), \(n\)] + c\ *)
(*\*SuperscriptBox[\(x\), \(2\ n\)]\)], \((b + 2\ c\ *)
(*\*SuperscriptBox[\(x\), \(n\)])\)]\)=0*)


(* ::Subsubsection:: *)
(*Rule: If  m,n,p-1/2\[Element]\[DoubleStruckCapitalZ] \[And] n>0 \[And] p>0 \[And] b^2-4 a c=0 \[And] m-n+1!=0, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]x^m (a+b x^n+c x^(2 n))^p \[DifferentialD]x  \[LongRightArrow]  (Sqrt[a+b x^n+c x^(2 n)]/((4 c)^(p-1/2) (b+2 c x^n)))\[Integral]x^m (b+2 c x^n)^(2 p) \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[x_^m_.*(a_+b_.*x_^n_.+c_.*x_^j_)^p_,x_Symbol] :=
  Sqrt[a+b*x^n+c*x^(2*n)]/(b+2*c*x^n)*Dist[1/(4*c)^(p-1/2),Int[x^m*(b+2*c*x^n)^(2*p),x]] /;
FreeQ[{a,b,c},x] && ZeroQ[j-2*n] && IntegersQ[m,n,p-1/2] && n>0 && p>0 && ZeroQ[b^2-4*a*c] &&
NonzeroQ[m-n+1]


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Derivation: Algebraic manipulation and piecewise constant extraction*)


(* ::Subsubsection:: *)
(*Basis: If  p-1/2\[Element]\[DoubleStruckCapitalZ] and b^2-4 a c=0, then (a+b x^n+c x^(2 n))^p=(b+2 c x^n)/((4 c)^(p+1/2) Sqrt[a+b x^n+c x^(2 n)]) (b+2 c x^n)^(2 p)*)


(* ::Subsubsection:: *)
(*Basis: If  b^2-4 a c=0, then \!\( *)
(*\*SubscriptBox[\(\[PartialD]\), \(x\)]*)
(*\*FractionBox[\(b + 2\ c\ *)
(*\*SuperscriptBox[\(x\), \(n\)]\), *)
(*SqrtBox[\(a + b\ *)
(*\*SuperscriptBox[\(x\), \(n\)] + c\ *)
(*\*SuperscriptBox[\(x\), \(2\ n\)]\)]]\)=0*)


(* ::Subsubsection:: *)
(*Rule: If  m,n,p+1/2\[Element]\[DoubleStruckCapitalZ] \[And] n>0 \[And] p<0 \[And] b^2-4 a c=0 \[And] m-n+1!=0, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]x^m (a+b x^n+c x^(2 n))^p \[DifferentialD]x  \[LongRightArrow]  ((b+2 c x^n)/((4 c)^(p+1/2) Sqrt[a+b x^n+c x^(2 n)]))\[Integral]x^m (b+2 c x^n)^(2 p) \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[x_^m_.*(a_+b_.*x_^n_.+c_.*x_^j_)^p_,x_Symbol] :=
  (b+2*c*x^n)/Sqrt[a+b*x^n+c*x^(2*n)]*Dist[1/(4*c)^(p+1/2),Int[x^m*(b+2*c*x^n)^(2*p),x]] /;
FreeQ[{a,b,c},x] && ZeroQ[j-2*n] && IntegersQ[m,n,p+1/2] && n>0 && p<0 && ZeroQ[b^2-4*a*c] &&
NonzeroQ[m-n+1]


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Reference: G&R 2.174.2*)


(* ::Subsubsection:: *)
(*Note: Can this be generalized to handle any symmetric trinomial?*)


(* ::Subsubsection:: *)
(*Rule: If   m\[Element]\[DoubleStruckCapitalZ] \[And] p\[Element]\[DoubleStruckCapitalF] \[And] p<-1\[And] m+2p+1=0, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]x^m (a+b x+c x^2)^p \[DifferentialD]x  \[LongRightArrow]  -((x^(m-1) (a+b x+c x^2)^(p+1))/(c (m-1)))-                                                  *)
(*                                                          b/(2 c) \[Integral]x^(m-1) (a+b x+c x^2)^p \[DifferentialD]x+1/c \[Integral]x^(m-2) (a+b x+c x^2)^(p+1) \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[x_^m_*(a_.+b_.*x_+c_.*x_^2)^p_,x_Symbol] :=
  -x^(m-1)*(a+b*x+c*x^2)^(p+1)/(c*(m-1)) -
  Dist[b/(2*c),Int[x^(m-1)*(a+b*x+c*x^2)^p,x]] +
  Dist[1/c,Int[x^(m-2)*(a+b*x+c*x^2)^(p+1),x]] /;
FreeQ[{a,b,c},x] && IntegerQ[m] && FractionQ[p] && p<-1 && ZeroQ[m+2*p+1]


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Reference: G&R 2.160.2*)


(* ::Subsubsection:: *)
(*Rule: If  m,n\[Element]\[DoubleStruckCapitalZ] \[And] m<-1 \[And] n>0 \[And] p\[Element]\[DoubleStruckCapitalF] \[And] p>0, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]x^m (a+b x^n+c x^(2 n))^p \[DifferentialD]x  \[LongRightArrow]  ((x^(m+1) (a+b x^n+c x^(2n))^p)/(m+1))-                                                                   *)
(*                          (b n p)/(m+1) \[Integral]x^(m+n) (a+b x^n+c x^(2n))^(p-1) \[DifferentialD]x-(2 c n p)/(m+1) \[Integral]x^(m+2 n) (a+b x^n+c x^(2n))^(p-1) \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[x_^m_*(a_+b_.*x_^n_.+c_.*x_^j_)^p_,x_Symbol] :=
  x^(m+1)*(a+b*x^n+c*x^(2*n))^p/(m+1) -
  Dist[b*n*p/(m+1),Int[x^(m+n)*(a+b*x^n+c*x^(2*n))^(p-1),x]] -
  Dist[2*c*n*p/(m+1),Int[x^(m+2*n)*(a+b*x^n+c*x^(2*n))^(p-1),x]] /;
FreeQ[{a,b,c},x] && ZeroQ[j-2*n] && IntegersQ[m,n] && m<-1 && n>0 && FractionQ[p] && p>0


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Reference: G&R 2.160.4*)


(* ::Subsubsection:: *)
(*Note: This rule is commented out since it seems inferior to G&R 2.160.2 above.*)


(* ::Subsubsection:: *)
(*Rule: If  m,n\[Element]\[DoubleStruckCapitalZ] \[And] m<-1 \[And] n>0 \[And] p\[Element]\[DoubleStruckCapitalF] \[And] p>0 \[And] m+2n p+1!=0, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]x^m (a+b x^n+c x^(2 n))^p \[DifferentialD]x  \[LongRightArrow]  ((x^(m+1) (a+b x^n+c x^(2 n))^p)/(m+2 n p+1))+                                                                                       *)
(*                             (2a n p)/(m+2 n p+1) \[Integral]x^m (a+b x^n+c x^(2 n))^(p-1) \[DifferentialD]x+(b n p)/(m+2 n p+1) \[Integral]x^(m+n) (a+b x^n+c x^(2 n))^(p-1) \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
(* Int[x_^m_*(a_+b_.*x_^n_.+c_.*x_^j_)^p_,x_Symbol] :=
  x^(m+1)*(a+b*x^n+c*x^(2*n))^p/(m+2*n*p+1) +
  Dist[2*a*n*p/(m+2*n*p+1),Int[x^m*(a+b*x^n+c*x^(2*n))^(p-1),x]] +
  Dist[b*n*p/(m+2*n*p+1),Int[x^(m+n)*(a+b*x^n+c*x^(2*n))^(p-1),x]] /;
FreeQ[{a,b,c},x] && ZeroQ[j-2*n] && IntegersQ[m,n] && m<-1 && n>0 && FractionQ[p] && p>0 &&
NonzeroQ[m+2*n*p+1] *)


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Reference: G&R 2.160.1*)


(* ::Subsubsection:: *)
(*Note: G&R 2.161.6 is a special case of G&R 2.160.1.*)


(* ::Subsubsection:: *)
(*Rule: If  m,n\[Element]\[DoubleStruckCapitalZ] \[And] m<-1 \[And] n>0 \[And] p\[Element]\[DoubleStruckCapitalF] \[And] m+n(p+1)+1!=0 \[And]  m+2n(p+1)+1!=0, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]x^m (a+b x^n+c x^(2 n))^p \[DifferentialD]x  \[LongRightArrow]  ((x^(m+1) (a+b x^n+c x^(2 n))^(p+1))/(a (m+1)))-                                                                                    *)
(*   (b (m+n (p+1)+1))/(a (m+1)) \[Integral]x^(m+n) (a+b x^n+c x^(2 n))^p \[DifferentialD]x-(c (m+2 n (p+1)+1))/(a (m+1)) \[Integral]x^(m+2 n) (a+b x^n+c x^(2 n))^p \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[x_^m_*(a_+b_.*x_^n_.+c_.*x_^j_)^p_,x_Symbol] :=
  x^(m+1)*(a+b*x^n+c*x^(2*n))^(p+1)/(a*(m+1)) -
  Dist[b*(m+n*(p+1)+1)/(a*(m+1)),Int[x^(m+n)*(a+b*x^n+c*x^(2*n))^p,x]] -
  Dist[c*(m+2*n*(p+1)+1)/(a*(m+1)),Int[x^(m+2*n)*(a+b*x^n+c*x^(2*n))^p,x]] /;
FreeQ[{a,b,c,p},x] && ZeroQ[j-2*n] && IntegersQ[m,n] && m<-1 && n>0 && FractionQ[p] &&
NonzeroQ[m+n*(p+1)+1] && NonzeroQ[m+2*n*(p+1)+1]


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Reference: G&R 2.160.3*)


(* ::Subsubsection:: *)
(*Rule: If  m,n\[Element]\[DoubleStruckCapitalZ] \[And] 2<2n<=m \[And] p\[Element]\[DoubleStruckCapitalF] \[And] m+n(p-1)+1=0, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]x^m (a+b x^n+c x^(2 n))^p \[DifferentialD]x  \[LongRightArrow]  ((x^(m-2 n+1) (a+b x^n+c x^(2 n))^(p+1))/(c n (p+1)))+a/c \[Integral]x^(m-2 n) (a+b x^n+c x^(2 n))^p \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[x_^m_*(a_+b_.*x_^n_.+c_.*x_^j_)^p_,x_Symbol] :=
  x^(m-2*n+1)*(a+b*x^n+c*x^(2*n))^(p+1)/(c*n*(p+1)) +
  Dist[a/c,Int[x^(m-2*n)*(a+b*x^n+c*x^(2*n))^p,x]] /;
FreeQ[{a,b,c,p},x] && ZeroQ[j-2*n] && IntegersQ[m,n] && 0<2*n<=m && FractionQ[p] &&
ZeroQ[m+n*(p-1)+1]


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Reference: G&R 2.160.3*)


(* ::Subsubsection:: *)
(*Note: G&R 2.174.1 is a special case of G&R 2.160.3.*)


(* ::Subsubsection:: *)
(*Rule: If  m,n\[Element]\[DoubleStruckCapitalZ] \[And] 2<2n<=m \[And] p\[Element]\[DoubleStruckCapitalF] \[And] m+2 n p+1!=0 \[And] m+n(p-1)+1!=0, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]x^m (a+b x^n+c x^(2 n))^p \[DifferentialD]x  \[LongRightArrow]  ((x^(m-2 n+1) (a+b x^n+c x^(2n))^(p+1))/(c (m+2 n p+1)))-                                                                                *)
(*            (b (m+n (p-1)+1))/(c (m+2 n p+1)) \[Integral]x^(m-n) (a+b x^n+c x^(2n))^p \[DifferentialD]x-(a (m-2 n+1))/(c (m+2 n p+1)) \[Integral]x^(m-2 n) (a+b x^n+c x^(2n))^p \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[x_^m_*(a_+b_.*x_^n_.+c_.*x_^j_)^p_,x_Symbol] :=
  x^(m-2*n+1)*(a+b*x^n+c*x^(2*n))^(p+1)/(c*(m+2*n*p+1)) -
  Dist[b*(m+n*(p-1)+1)/(c*(m+2*n*p+1)),Int[x^(m-n)*(a+b*x^n+c*x^(2*n))^p,x]] -
  Dist[a*(m-2*n+1)/(c*(m+2*n*p+1)),Int[x^(m-2*n)*(a+b*x^n+c*x^(2*n))^p,x]] /;
FreeQ[{a,b,c,p},x] && ZeroQ[j-2*n] && IntegersQ[m,n] && 0<2*n<=m && FractionQ[p] &&
NonzeroQ[m+2*n*p+1] && NonzeroQ[m+n*(p-1)+1]


(* ::PageBreak:: *)
(**)


(* ::Title::Bold::Closed:: *)
(*\[Integral](d+e x^n) (a+b x^n+c x^(2 n))^p \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Note: Previously undiscovered rule?*)


(* ::Subsubsection:: *)
(*Note: Although the resulting integrand has complicated coefficients, it is has the same form as the original integrand so recursion can occur. *)


(* ::Subsubsection:: *)
(*Rule: If  n\[Element]\[DoubleStruckCapitalZ] \[And] n>1 \[And] p\[Element]\[DoubleStruckCapitalF] \[And] p>0 \[And] b^2-4a c!=0 \[And] 2n p+1!=0 \[And] 2n p+n+1!=0, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral](d+e x^n) (a+b x^n+c x^(2 n))^p \[DifferentialD]x  \[LongRightArrow]                                                                                                                                              *)
(*((x (b e n p+c d (2 n p+n+1)+c e (2 n p+1) x^n))/(c (2 n p+1)(2 n p+n+1))) (a+b x^n+c x^(2 n))^p-(n p)/(c (2 n p+1)(2 n p+n+1))\[CenterDot]             *)
(*    \[Integral](a b e-2 a c d (2 n p+n+1)-(2 a c e (2 n p+1)+b c d (2 n p+n+1)-b^2 e(n p+1))x^n)\[CenterDot]                  *)
(*                                                                                                                                             (a+b x^n+c x^(2 n))^(p-1)\[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[(d_.+e_.*x_^n_)*(a_+b_.*x_^n_+c_.*x_^j_)^p_,x_Symbol] :=
  x*(b*e*n*p+c*d*(2*n*p+n+1)+c*e*(2*n*p+1)*x^n)*(a+b*x^n+c*x^(2*n))^p/(c*(2*n*p+1)*(2*n*p+n+1)) -
  Dist[n*p/(c*(2*n*p+1)*(2*n*p+n+1)),
    Int[(a*b*e-2*a*c*d*(2*n*p+n+1)-(2*a*c*e*(2*n*p+1)+b*c*d*(2*n*p+n+1)-b^2*e*(n*p+1))*x^n)*
      (a+b*x^n+c*x^(2*n))^(p-1),x]] /;
FreeQ[{a,b,c,d,e},x] && ZeroQ[j-2*n] && IntegerQ[n] && n>1 && FractionQ[p] && p>0 && 
NonzeroQ[b^2-4*a*c] && NonzeroQ[2*n*p+1] && NonzeroQ[2*n*p+n+1] 


(* ::PageBreak:: *)
(**)


(* ::Title::Bold::Closed:: *)
(*\[Integral](a+b x+c x^2+d x^3+e x^4)^p \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Derivation: Integration by substitution*)


(* ::Subsubsection:: *)
(*Basis: If  d^3-4 c d e+8 b e^2=0 and t=d/(4 e)+x, then  a+b x+c x^2+d x^3+e x^4=a+(5 d^4)/(256 e^3)-(c d^2)/(16 e^2)+(c-(3 d^2)/(8 e)) t^2+e t^4*)


(* ::Subsubsection:: *)
(*Note: The substitution transforms a dense quartic polynomial into a symmetric quartic trinomial. *)


(* ::Subsubsection:: *)
(*Rule: If  p-1/2\[Element]\[DoubleStruckCapitalZ]  \[And] d^3-4 c d e+8 b e^2=0, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral](a+b x+c x^2+d x^3+e x^4)^p \[DifferentialD]x  \[LongRightArrow]  Subst[\[Integral](a+(5 d^4)/(256 e^3)-(c d^2)/(16 e^2)+(c-(3 d^2)/(8 e)) x^2+e x^4)^p \[DifferentialD]x,x,d/(4 e)+x]*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[(a_.+b_.*x_+c_.*x_^2+d_.*x_^3+e_.*x_^4)^p_,x_Symbol] :=
  Subst[Int[(a+5*d^4/(256*e^3)-c*d^2/(16*e^2)+(c-3*d^2/(8*e))*x^2+e*x^4)^p,x],x,d/(4*e)+x] /;
FreeQ[{a,b,c,d,e},x] && IntegerQ[p-1/2] && ZeroQ[d^3-4*c*d*e+8*b*e^2]


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Derivation: Integration by substitution*)


(* ::Subsubsection:: *)
(*Basis: If  b^3-4 a b c+8 a^2 d=0 and t=b/(4 a)+1/x, then  a+b x+c x^2+d x^3+e x^4=(a (-3 b^4+16 a b^2 c-64 a^2 b d+256 a^3 e-32 a^2 (3 b^2-8 a c) t^2+256 a^4 t^4))/(b-4 a t)^4*)


(* ::Subsubsection:: *)
(*Note: The substitution transforms a dense quartic polynomial into a symmetric quartic trinomial over the 4th power of a linear.*)


(* ::Subsubsection:: *)
(*Rule: If  p-1/2\[Element]\[DoubleStruckCapitalZ]  \[And] b^3-4 a b c+8 a^2 d=0, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral](a+b x+c x^2+d x^3+e x^4)^p \[DifferentialD]x  \[LongRightArrow]  -16 a^2 Subst[\[Integral]((a(-3 b^4+16 a b^2 c-64 a^2 b d+256 a^3 e-32 a^2 (3 b^2-8 a c) x^2+256 a^4 x^4))/(b-4 a x)^4)^p/(b-4 a x)^2\[DifferentialD]x,x,b/(4 a)+1/x]*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[(a_.+b_.*x_+c_.*x_^2+d_.*x_^3+e_.*x_^4)^p_,x_Symbol] :=
  Dist[-16*a^2,Subst[
    Int[(a*(-3*b^4+16*a*b^2*c-64*a^2*b*d+256*a^3*e-32*a^2*(3*b^2-8*a*c)*x^2+256*a^4*x^4)/(b-4*a*x)^4)^p/(b-4*a*x)^2,x],x,b/(4*a)+1/x]] /;
FreeQ[{a,b,c,d,e},x] && IntegerQ[p-1/2] && ZeroQ[b^3-4*a*b*c+8*a^2*d]


(* ::Code:: *)
Int[u_^p_,x_Symbol] :=
  Module[{v=Expand[u,x]},
  Int[v^p,x] /;
 v=!=u && (
 MatchQ[v,a_+b_.*x^2+c_.*x^4 /; FreeQ[{a,b,c},x]] ||
 MatchQ[v,a_.+b_.*x+c_.*x^2+d_.*x^3+e_.*x^4 /; FreeQ[{a,b,c,d,e},x] && ZeroQ[d^3-4*c*d*e+8*b*e^2]])] /;
PolynomialQ[u,x] && Exponent[u,x]==4 && IntegerQ[p-1/2]
