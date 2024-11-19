(* ::Package:: *)

(* ::Title::Plain:: *)
(* Integration Rules for *)
(*\[Integral](sin^j(z))^m (a+b sin^k(z))^n \[DifferentialD]z when j^2=1\[And]k^2=1*)


(* ::Subsubtitle::Plain::Closed:: *)
(*Domain Map *)


(* ::Input:: *)
(*Graphics[{{RGBColor[1, 0, 0], Rectangle[{-4, 2}, {-1, 4}]}, {GrayLevel[0], Inset[Style["Rule 1a\n\[LowerRightArrow]\[DownArrow]\[DownArrow]\[Diamond]", FontSize -> 10], {Rational[-5, 2], 3}]}, {RGBColor[1., 0.4, 0.4], Rectangle[{-4, 1}, {-1, 2}]}, {GrayLevel[0], Inset[Style["Rule 1b \[LowerRightArrow]\[DownArrow]\[Diamond]", FontSize -> 10], {Rational[-5, 2], Rational[3, 2]}]}, {RGBColor[1., 0.7, 0.7], Rectangle[{-4, 0}, {-1, 1}]}, {GrayLevel[0], Inset[Style["Rule 1c \[LowerRightArrow]\[Diamond]", FontSize -> 10], {Rational[-5, 2], 0.6}]}, {RGBColor[0.5, 0.5, 1.], Rectangle[{-1, 2}, {0, 4}]}, {GrayLevel[0], Inset[Style["Rule 2a\n\[DownArrow]\[DownArrow]\[DownArrow]\[Diamond]", FontSize -> 10], {Rational[-1, 2], 3}]}, {GrayLevel[0], Thickness[0.007], Dashing[{0.003, 0.02}], Line[{{-0.98, 3.98}, {-0.98, 2.02}}], {RGBColor[0.8, 0.8, 1.], Dashing[{}], Rectangle[{0, 1}, {1, 4}], {GrayLevel[0], Inset[Style["Rule 2b\n\[LowerLeftArrow]\[DownArrow]\[Diamond]", FontSize -> 10], {Rational[1, 2], 3}]}, {RGBColor[0, 1, 0], Rectangle[{2, -1}, {4, 4}]}, {GrayLevel[0], Inset[Style["Rule 3a\n\[LeftArrow]\[LeftArrow]\[LeftArrow]\[Diamond]", FontSize -> 10], {3, 3}]}, {GrayLevel[0], Thickness[0.007], Dashing[{0.003, 0.02}], Line[{{2.02, -0.98}, {3.98, -0.98}}], {RGBColor[0.7, 1., 0.7], Dashing[{}], Rectangle[{1, 0}, {2, 4}], {GrayLevel[0], Inset[Style["Rule 3b\n\[LowerLeftArrow]\[LeftArrow]\[Diamond]", FontSize -> 10], {Rational[3, 2], 3}]}, {RGBColor[1, 0.5, 0.5], Rectangle[{2, -4}, {4, -1}]}, {GrayLevel[0], Inset[Style["Rule 4a\n\[UpperLeftArrow]\[LeftArrow]\[LeftArrow]\[Diamond]", FontSize -> 10], {3, -2.6}]}, {RGBColor[1., 0.7, 0.7], Rectangle[{1, -4}, {2, -1}]}, {GrayLevel[0], Inset[Style["Rule 4b\n\[UpperLeftArrow]\[LeftArrow]\[Diamond]", FontSize -> 10], {Rational[3, 2], -2.6}]}, {RGBColor[1., 0.7, 1.], Rectangle[{0, -4}, {1, -1}]}, {GrayLevel[0], Inset[Style["Rule 5a\n\[UpperLeftArrow]\[Diamond]", FontSize -> 10], {Rational[1, 2], -2.6}]}, {RGBColor[1., 0.3, 1.], Rectangle[{-1, -4}, {0, -1}]}, {GrayLevel[0], Inset[Style["Rule 5b\n\[UpArrow]\[Diamond]", FontSize -> 10], {Rational[-1, 2], -2.6}]}, {GrayLevel[0], Thickness[0.007], Dashing[{0.003, 0.02}], Line[{{-0.98, -1.02}, {-0.98, -3.98}}], {RGBColor[1, 0.5, 0], Dashing[{}], Rectangle[{-4, -4}, {-1, 0}], {GrayLevel[0], Inset[Style["Rule 6\n\[RightArrow]\[Diamond]", FontSize -> 10], {Rational[-5, 2], -2.6}]}, {RGBColor[0, 1, 0], Thickness[Large], Line[{{0, -3.98}, {0, -1}}], {GrayLevel[0], GeometricTransformation[Inset[Style["  Rule 7\[LeftArrow]\[LeftArrow]", FontSize -> 10], {0.15, -3.25}], {{{0, 1}, {-1, 0}}, Center}]}, {RGBColor[1, 0, 0], Thickness[Large], Line[{{0, 1}, {0, 3.98}}], {GrayLevel[0], GeometricTransformation[Inset[Style["  Rule  8\[RightArrow]\[RightArrow]", FontSize -> 10], {0.15, 2}], {{{0, 1}, {-1, 0}}, Center}]}, {RGBColor[0, 1, 0], Thickness[Large], Line[{{-3.98, 0}, {-1, 0}}], {GrayLevel[0], Inset[Style["Rule 9 \[RightArrow]\[Diamond]", FontSize -> 10], {Rational[-5, 2], 0.13}]}, {RGBColor[1, 0, 0], Thickness[Large], Line[{{1, 0}, {3.98, 0}}], {GrayLevel[0], Inset[Style["Rule 10 \[LeftArrow]\[LeftArrow]\[Diamond]", FontSize -> 10], {3, 0.13}]}, {RGBColor[0.5, 0.5, 1.], Thickness[Large], Line[{{2, -1}, {2, -3.98}}], {GrayLevel[0], GeometricTransformation[Inset[Style[" Rule 11\[LowerLeftArrow]", FontSize -> 10], {2.15, -3.5}], {{{0, 1}, {-1, 0}}, Center}]}, {RGBColor[0, 0, 1], Thickness[Large], Line[{{2, -1}, {2, 3.98}}], {GrayLevel[0], GeometricTransformation[Inset[Style["Rule  12 \[DownArrow]", FontSize -> 10], {2.15, 2}], {{{0, 1}, {-1, 0}}, Center}]}, {GrayLevel[0], Thickness[Large], Line[{{-3.98, 1}, {3.98, 1}}]}, {GrayLevel[0], Thickness[Large], Line[{{1, 3.98}, {1, -3.98}}]}, {GrayLevel[0], Thickness[Large], Line[{{-3.98, 2}, {3.98, 2}}], {RGBColor[1., 0.3, 0.3], Disk[{0, 1}, Scaled[Rational[1, 60]]]}, {GrayLevel[1], Inset["a", {0.01, 1}]}, {RGBColor[1., 0.3, 0.3], Disk[{0, -1}, Scaled[Rational[1, 60]]]}, {GrayLevel[1], Inset["a", {0.01, -1}]}, {RGBColor[1., 0.3, 0.3], Disk[{0, 2}, Scaled[Rational[1, 60]]]}, {GrayLevel[1], Inset["b", {0.01, 2}]}, {RGBColor[1., 0.3, 0.3], Disk[{0, -2}, Scaled[Rational[1, 60]]]}, {GrayLevel[1], Inset["b", {0.01, -2}]}, {RGBColor[1., 0.3, 0.3], Disk[{-1, 0}, Scaled[Rational[1, 60]]]}, {GrayLevel[1], Inset["c", {-0.99, 0}]}, {RGBColor[0, 1, 1], Disk[{2, 0}, Scaled[Rational[1, 60]]]}, {GrayLevel[0], Inset["d", {2.01, 0}]}, {RGBColor[1., 0.3, 0.3], Disk[{Rational[1, 2], 0}, Scaled[Rational[1, 60]]]}, {GrayLevel[1], Inset["e", {0.51, 0}]}, {RGBColor[1., 0.3, 0.3], Disk[{Rational[-1, 2], 0}, Scaled[Rational[1, 60]]]}, {GrayLevel[1], Inset["f", {-0.49, 0}]}, {RGBColor[1., 0.3, 0.3], Disk[{0, Rational[1, 2]}, Scaled[Rational[1, 60]]]}, {GrayLevel[1], Inset["e", {0.01, Rational[1, 2]}]}, {RGBColor[1., 0.3, 0.3], Disk[{0, Rational[-1, 2]}, Scaled[Rational[1, 60]]]}, {GrayLevel[1], Inset["f", {0.01, Rational[-1, 2]}]}, {RGBColor[0, 1, 1], Disk[{-1, -1}, Scaled[Rational[1, 60]]]}, {GrayLevel[0], Inset["g", {-0.99, -1}]}, {RGBColor[1., 0.3, 0.3], Disk[{-1, Rational[-1, 2]}, Scaled[Rational[1, 60]]]}, {GrayLevel[1], Inset["h", {-0.99, Rational[-1, 2]}]}, {RGBColor[1., 0.3, 0.3], Disk[{Rational[-1, 2], -1}, Scaled[Rational[1, 60]]]}, {GrayLevel[1], Inset["h", {-0.49, -1}]}, {RGBColor[0, 1, 1], Disk[{Rational[1, 2], -1}, Scaled[Rational[1, 60]]]}, {GrayLevel[0], Inset["i", {0.51, -1}]}, {RGBColor[0, 1, 1], Disk[{-1, Rational[1, 2]}, Scaled[Rational[1, 60]]]}, {GrayLevel[0], Inset["i", {-0.99, Rational[1, 2]}]}, {RGBColor[0, 1, 1], Disk[{Rational[3, 2], -1}, Scaled[Rational[1, 60]]]}, {GrayLevel[0], Inset["j", {1.51, -1}]}, {RGBColor[0, 1, 1], Disk[{-1, Rational[3, 2]}, Scaled[Rational[1, 60]]]}, {GrayLevel[0], Inset["j", {-0.99, Rational[3, 2]}]}, {RGBColor[1., 0.3, 0.3], Disk[{Rational[-1, 2], Rational[-1, 2]}, Scaled[Rational[1, 60]]]}, {GrayLevel[1], Inset["k", {-0.49, Rational[-1, 2]}]}, {RGBColor[0, 1, 1], Disk[{Rational[1, 2], Rational[1, 2]}, Scaled[Rational[1, 60]]]}, {GrayLevel[0], Inset["l", {0.51, Rational[1, 2]}]}, {RGBColor[0, 1, 1], Disk[{Rational[1, 2], Rational[-1, 2]}, Scaled[Rational[1, 60]]]}, {GrayLevel[0], Inset["m", {0.51, Rational[-1, 2]}]}, {RGBColor[0, 1, 1], Disk[{Rational[-1, 2], Rational[1, 2]}, Scaled[Rational[1, 60]]]}, {GrayLevel[0], Inset["m", {-0.49, Rational[1, 2]}]}, {RGBColor[0, 1, 1], Disk[{Rational[1, 2], Rational[-3, 2]}, Scaled[Rational[1, 60]]]}, {GrayLevel[0], Inset["n", {0.51, Rational[-3, 2]}]}, {RGBColor[0, 1, 1], Disk[{Rational[-3, 2], Rational[1, 2]}, Scaled[Rational[1, 60]]]}, {GrayLevel[0], Inset["n", {-1.49, Rational[1, 2]}]}, {RGBColor[0, 1, 1], Disk[{Rational[3, 2], Rational[-1, 2]}, Scaled[Rational[1, 60]]]}, {GrayLevel[0], Inset["o", {1.51, Rational[-1, 2]}]}, {RGBColor[0, 1, 1], Disk[{Rational[-1, 2], Rational[3, 2]}, Scaled[Rational[1, 60]]]}, {GrayLevel[0], Inset["o", {-0.49, Rational[3, 2]}]}, {RGBColor[0, 1, 1], Disk[{Rational[3, 2], Rational[-3, 2]}, Scaled[Rational[1, 60]]]}, {GrayLevel[0], Inset["p", {1.51, Rational[-3, 2]}]}, {RGBColor[0, 1, 1], Disk[{Rational[-3, 2], Rational[3, 2]}, Scaled[Rational[1, 60]]]}, {GrayLevel[0], Inset["p", {-1.49, Rational[3, 2]}]}, {RGBColor[0, 1, 1], Disk[{Rational[-1, 2], Rational[-3, 2]}, Scaled[Rational[1, 60]]]}, {GrayLevel[0], Inset["q", {-0.49, Rational[-3, 2]}]}, {RGBColor[0, 1, 1], Disk[{Rational[-3, 2], Rational[-1, 2]}, Scaled[Rational[1, 60]]]}, {GrayLevel[0], Inset["q", {-1.49, Rational[-1, 2]}]}}}}}}}}}}}}}}}, Axes -> True, AxesLabel -> {$CellContext`n, $CellContext`j $CellContext`k $CellContext`m}, ImageSize -> Medium]*)


(* ::Text:: *)
(*Legend:*)
(*\[Bullet]  The rule number in a colored region indicates the rule to use for integrals in that region.*)
(*\[Bullet]  The rule number next to a colored line indicates the rule to use for integrals on that line.*)
(*\[Bullet]  A white region or line indicates there is no rule for integrals in that region or on that line.*)
(*\[Bullet]  A solid black line indicates integrals on that line are handled by rules in another section.*)
(*\[Bullet]  A dashed black line on the border of a region indicates integrals on that border are handled by the rule for that region.*)
(*\[Bullet]  The arrow(s) following a rule number indicates the direction the rule drives integrands in the n\[Cross]m exponent plane.*)
(*\[Bullet]  A \[Diamond] following a rule number indicates the rule transforms the integrand into a form handled by another section.*)
(*\[Bullet]  A red (stop) disk indicates the terminal rule to use for the point at the center of the disk.*)
(*\[Bullet]  A cyan disk indicates the non-terminal rule to use for the point at the center of the disk.*)


(* ::PageBreak:: *)
(**)


(* ::Title::Plain::Closed:: *)
(* Integration Rules for *)
(*\[Integral](sin^j(z))^m \[DifferentialD]z when j^2=1*)


(* ::Subsubtitle::Bold::Closed:: *)
(*Rule a:  \[Integral]Sin[c+d x]^j \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Reference: G&R 2.01.5, CRC 290, A&S 4.3.113*)


(* ::Subsubsection:: *)
(*Derivation: Rule 8b with m=1 and j=1*)


(* ::Subsubsection:: *)
(*Note: This rule is an unnecessary special case of rule 8b, but it saves a step.*)


(* ::Subsubsection:: *)
(*Rule a1:*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]Sin[c+d x]\[DifferentialD]x  \[LongRightArrow]  -(Cos[c+d x]/d)*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[sin[c_.+d_.*x_],x_Symbol] :=
  -Cos[c+d*x]/d /;
FreeQ[{c,d},x]


(* ::Subsubsection:: *)
(*Reference: G&R 2.01.6, CRC 291, A&S 4.3.114*)


(* ::Code:: *)
Int[Cos[a_.+b_.*x_],x_Symbol] :=
  Sin[a+b*x]/b /;
FreeQ[{a,b},x]


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Reference: G&R 2.526.1, CRC 295, A&S 4.3.116'*)


(* ::Subsubsection:: *)
(*Derivation: Integration by substitution*)


(* ::Subsubsection:: *)
(*Basis: Csc[z]=-(1/(1-Cos[z]^2))Derivative[1][Cos][z]*)


(* ::Subsubsection:: *)
(*Rule a2:*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]Csc[c+d x]\[DifferentialD]x  \[LongRightArrow]  -(ArcTanh[Cos[c+d x]]/d)*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[1/sin[c_.+d_.*x_],x_Symbol] :=
  -ArcTanh[Cos[c+d*x]]/d /;
FreeQ[{c,d},x]


(* ::Subsubsection:: *)
(*Reference: G&R 2.526.9', CRC 294', A&S 4.3.117'*)


(* ::Code:: *)
Int[Sec[a_.+b_.*x_],x_Symbol] :=
  ArcTanh[Sin[a+b*x]]/b /;
FreeQ[{a,b},x]


(* ::PageBreak:: *)
(**)


(* ::Subsubtitle::Bold::Closed:: *)
(*Rule b:  \[Integral]Sin[c+d x]^(2j) \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Reference: G&R 2.513.5, CRC 296*)


(* ::Subsubsection:: *)
(*Derivation: Rule 8b with m=2 and j=1*)


(* ::Subsubsection:: *)
(*Note: This rule is an unnecessary special case of rule 8b, but it saves a step.*)


(* ::Subsubsection:: *)
(*Rule b1:*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]Sin[c+d x]^2 \[DifferentialD]x  \[LongRightArrow]  (x/2)-(Cos[c+d x] Sin[c+d x])/(2 d)*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[sin[c_.+d_.*x_]^2,x_Symbol] :=
  x/2 - Cos[c+d*x]*Sin[c+d*x]/(2*d) /;
FreeQ[{c,d},x]


(* ::Subsubsection:: *)
(*Reference: G&R 2.513.11, CRC 302*)


(* ::Code:: *)
Int[Cos[a_.+b_.*x_]^2,x_Symbol] :=
  x/2 + Cos[a+b*x]*Sin[a+b*x]/(2*b) /;
FreeQ[{a,b},x]


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Reference: G&R 2.526.2, CRC 308*)


(* ::Subsubsection:: *)
(*Derivation: Rule 7b with m=-2 and j=1*)


(* ::Subsubsection:: *)
(*Note: This rule is an unnecessary special case of rule 7b, but it saves a step.*)


(* ::Subsubsection:: *)
(*Rule b2:*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]Csc[c+d x]^2 \[DifferentialD]x  \[LongRightArrow]  -(Cot[c+d x]/d)*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[1/sin[c_.+d_.*x_]^2,x_Symbol] :=
  -Cot[c+d*x]/d /;
FreeQ[{c,d},x]


(* ::Subsubsection:: *)
(*Reference: G&R 2.526.10, CRC 312*)


(* ::Code:: *)
Int[Sec[a_.+b_.*x_]^2,x_Symbol] :=
  Tan[a+b*x]/b /;
FreeQ[{a,b},x]


(* ::PageBreak:: *)
(**)


(* ::Subsubtitle::Bold::Closed:: *)
(*Rules 7-8:  \[Integral](Sin[c+d x]^j)^m \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Derivation: Integration by substitution*)


(* ::Subsubsection:: *)
(*Basis: If  m/2\[Element]\[DoubleStruckCapitalZ], then Csc[z]^m=-(1+Cot[z]^2)^(((m-2)/2)) Derivative[1][Cot][z]*)


(* ::Subsubsection:: *)
(*Note: This rule is used for odd m<-2 since it requires fewer steps and results in simpler antiderivatives than rule 7b.*)


(* ::Subsubsection:: *)
(*Rule 7a: If  m/2\[Element]\[DoubleStruckCapitalZ] \[And] m<-2, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]Sin[c+d x]^m \[DifferentialD]x  \[LongRightArrow]  -(1/d)Subst[\[Integral](1+x^2)^((-m-2)/2) \[DifferentialD]x,x,Cot[c+d x]]*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[sin[c_.+d_.*x_]^m_,x_Symbol] :=
  Dist[-1/d,Subst[Int[Expand[(1+x^2)^((-m-2)/2),x],x],x,Cot[c+d*x]]] /;
FreeQ[{c,d},x] && EvenQ[m] && m<-2


(* ::Code:: *)
Int[Sec[a_.+b_.*x_]^n_,x_Symbol] :=
  Dist[1/b,Subst[Int[Regularize[(1+x^2)^((n-2)/2),x],x],x,Tan[a+b*x]]] /;
FreeQ[{a,b},x] && EvenQ[n] && n>2


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Reference: G&R 2.510.3, CRC 309*)


(* ::Subsubsection:: *)
(*Reference: G&R 2.552.3 special case when a=0*)


(* ::Subsubsection:: *)
(*Derivation: Rule 5b with a=1, b=0, k=j and n=0*)


(* ::Subsubsection:: *)
(*Rule 7b: If  j^2=1 \[And] m/2\[NotElement]\[DoubleStruckCapitalZ] \[And] m<-1, then*)


(* ::Subsubtitle::Bold:: *)
(* \[Integral](Sin[c+d x]^j)^m \[DifferentialD]x  \[LongRightArrow]  ((2Cos[c+d x](Sin[c+d x]^j)^(m+1))/(d(2m+j+1)))+(2 m+j+3)/(2 m+j+1) \[Integral](Sin[c+d x]^j)^(m+2) \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[(sin[c_.+d_.*x_]^j_.)^m_,x_Symbol] :=
  2*Cos[c+d*x]*(Sin[c+d*x]^j)^(m+1)/(d*(2*m+j+1)) + 
  Dist[(2*m+j+3)/(2*m+j+1),Int[(sin[c+d*x]^j)^(m+2),x]] /;
FreeQ[{c,d},x] && OneQ[j^2] && Not[EvenQ[m]] && RationalQ[m] && m<-1


(* ::Subsubsection:: *)
(*Reference: G&R 2.510.6, CRC 313*)


(* ::Code:: *)
Int[Cos[a_.+b_.*x_]^n_,x_Symbol] :=
  -Sin[a+b*x]*Cos[a+b*x]^(n+1)/(b*(n+1)) +
  Dist[(n+2)/(n+1),Int[Cos[a+b*x]^(n+2),x]] /;
FreeQ[{a,b},x] && RationalQ[n] && n<-1


(* ::Code:: *)
Int[Sec[a_.+b_.*x_]^n_,x_Symbol] :=
  Sin[a+b*x]*Sec[a+b*x]^(n-1)/(b*(n-1)) + 
  Dist[(n-2)/(n-1),Int[Sec[a+b*x]^(n-2),x]] /;
FreeQ[{a,b},x] && RationalQ[n] && n>1


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Derivation: Integration by substitution*)


(* ::Subsubsection:: *)
(*Basis: If (m-1)/2\[Element]\[DoubleStruckCapitalZ], then Sin[z]^m=-(1-Cos[z]^2)^(((m-1)/2)) Derivative[1][Cos][z]*)


(* ::Subsubsection:: *)
(*Note: This rule is used for odd m>1 since it requires fewer steps and results in simpler antiderivatives than rule 8b.*)


(* ::Subsubsection:: *)
(*Rule 8a: If (m-1)/2\[Element]\[DoubleStruckCapitalZ] \[And] m>1, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]Sin[c+d x]^m \[DifferentialD]x  \[LongRightArrow]  -(1/d)Subst[\[Integral](1-x^2)^((m-1)/2) \[DifferentialD]x,x,Cos[c+d x]]*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[sin[c_.+d_.*x_]^m_,x_Symbol] :=
  Dist[-1/d,Subst[Int[Expand[(1-x^2)^((m-1)/2),x],x],x,Cos[c+d*x]]] /;
FreeQ[{c,d},x] && OddQ[m] && m>1


(* ::Code:: *)
Int[Cos[a_.+b_.*x_]^n_,x_Symbol] :=
  Dist[1/b,Subst[Int[Expand[(1-x^2)^((n-1)/2),x],x],x,Sin[a+b*x]]] /;
FreeQ[{a,b},x] && OddQ[n] && n>1


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Reference: G&R 2.510.2, CRC 299*)


(* ::Subsubsection:: *)
(*Reference: G&R 2.552.3 inverted special case when a=0*)


(* ::Subsubsection:: *)
(*Derivation: Rule 2b with k=j and n=0*)


(* ::Subsubsection:: *)
(*Rule 8b: If  j^2=1 \[And] (m-1)/2\[NotElement]\[DoubleStruckCapitalZ] \[And] m>1, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral](Sin[c+d x]^j)^m \[DifferentialD]x  \[LongRightArrow]  -((2Cos[c+d x](Sin[c+d x]^j)^(m-1))/(d (2m+j-1)))+(2m+j-3)/(2m+j-1) \[Integral](Sin[c+d x]^j)^(m-2) \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[(sin[c_.+d_.*x_]^j_.)^m_,x_Symbol] :=
  -2*Cos[c+d*x]*(Sin[c+d*x]^j)^(m-1)/(d*(2*m+j-1)) + 
  Dist[(2*m+j-3)/(2*m+j-1),Int[(sin[c+d*x]^j)^(m-2),x]] /;
FreeQ[{c,d},x] && OneQ[j^2] && Not[OddQ[m]] && RationalQ[m] && m>1


(* ::Subsubsection:: *)
(*Reference: G&R 2.510.5, CRC 305*)


(* ::Code:: *)
Int[Cos[a_.+b_.*x_]^n_,x_Symbol] :=
  Sin[a+b*x]*Cos[a+b*x]^(n-1)/(b*n) +
  Dist[(n-1)/n,Int[Cos[a+b*x]^(n-2),x]] /;
FreeQ[{a,b},x] && RationalQ[n] && n>1


(* ::Code:: *)
Int[Sec[a_.+b_.*x_]^n_,x_Symbol] :=
  -Sin[a+b*x]*Sec[a+b*x]^(n+1)/(b*n) + 
  Dist[(n+1)/n,Int[Sec[a+b*x]^(n+2),x]] /;
FreeQ[{a,b},x] && RationalQ[n] && n<-1


(* ::PageBreak:: *)
(**)


(* ::Title::Plain::Closed:: *)
(* Integration Rules for *)
(*\[Integral](a+b sin^k(z))^n \[DifferentialD]z when k^2=1*)


(* ::Subsubtitle::Bold::Closed:: *)
(*Rule c:  \[Integral]1/(a+b Sin[c+d x]^k) \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Note: Although this rule produces a slightly more complicated antiderivative than rule c2 and c4, it is continuous provided  a^2-b^2>0.*)


(* ::Subsubsection:: *)
(*Rule c1: If  a^2-b^2>0, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]1/(a+b Sin[c+d x]) \[DifferentialD]x  \[LongRightArrow]  (x/Sqrt[a^2-b^2])+2/(d Sqrt[a^2-b^2]) ArcTan[(b Cos[c+d x])/(a+Sqrt[a^2-b^2]+b Sin[c+d x])]*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[1/(a_+b_.*sin[c_.+d_.*x_]),x_Symbol] :=
  x/Rt[a^2-b^2,2] + 
  2/(d*Rt[a^2-b^2,2])*ArcTan[Sim[b*Cos[c+d*x]/(a+Rt[a^2-b^2,2]+b*Sin[c + d*x])]] /;
FreeQ[{a,b,c,d},x] && PositiveQ[a^2-b^2]


(* ::Code:: *)
Int[1/(a_+b_.*Cos[c_.+d_.*x_]),x_Symbol] :=
  x/Rt[a^2-b^2,2] - 2/(d*Rt[a^2-b^2,2])*ArcTan[Sim[b*Sin[c+d*x]/(a+Rt[a^2-b^2,2]+b*Cos[c + d*x])]] /;
FreeQ[{a,b,c,d},x] && PositiveQ[a^2-b^2]


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Reference: G&R 2.553.3a, A&S 4.3.133a*)


(* ::Subsubsection:: *)
(*Note: Although nonessential, this rule produces a slightly simpler antiderivative than rule c3.*)


(* ::Subsubsection:: *)
(*Rule c2: If  a^2-b^2>0, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]1/(a+b Cos[c+d x]) \[DifferentialD]x  \[LongRightArrow]  (2/(d Sqrt[a^2-b^2]))ArcTan[((a-b) Tan[1/2 (c+d x)])/Sqrt[a^2-b^2]]*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[1/(a_+b_.*sin[c_.+Pi/2+d_.*x_]),x_Symbol] :=
  2*ArcTan[(a-b)*Tan[(c+d*x)/2]/Rt[a^2-b^2,2]]/(d*Rt[a^2-b^2,2]) /;
FreeQ[{a,b,c,d},x] && PosQ[a^2-b^2]


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Reference: G&R 2.551.3a, A&S 4.3.131a*)


(* ::Subsubsection:: *)
(*Rule c3: If  a^2-b^2>0, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]1/(a+b Sin[c+d x]) \[DifferentialD]x  \[LongRightArrow]  (2/(d Sqrt[a^2-b^2]))ArcTan[(b+a Tan[1/2 (c+d x)])/Sqrt[a^2-b^2]]*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[1/(a_+b_.*sin[c_.+d_.*x_]),x_Symbol] :=
  2*ArcTan[(b+a*Tan[(c+d*x)/2])/Rt[a^2-b^2,2]]/(d*Rt[a^2-b^2,2]) /;
FreeQ[{a,b,c,d},x] && PosQ[a^2-b^2]


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Reference: G&R 2.553.3b', A&S 4.3.133b'*)


(* ::Subsubsection:: *)
(*Note: Although nonessential, this rule produces a slightly simpler antiderivative than rule c5.*)


(* ::Subsubsection:: *)
(*Rule c4: If  \[Not](a^2-b^2>0), then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]1/(a+b Cos[c+d x]) \[DifferentialD]x  \[LongRightArrow]  -(2/(d Sqrt[b^2-a^2]))ArcTanh[((a-b) Tan[1/2 (c+d x)])/Sqrt[b^2-a^2]]*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[1/(a_+b_.*sin[c_.+Pi/2+d_.*x_]),x_Symbol] :=
  -2*ArcTanh[(a-b)*Tan[(c+d*x)/2]/Rt[b^2-a^2,2]]/(d*Rt[b^2-a^2,2]) /;
FreeQ[{a,b,c,d},x] && NegQ[a^2-b^2]


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Reference: G&R 2.551.3b', A&S 4.3.131b'*)


(* ::Subsubsection:: *)
(*Rule c5: If  \[Not](a^2-b^2>0), then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]1/(a+b Sin[c+d x]) \[DifferentialD]x  \[LongRightArrow]  -(2/(d Sqrt[b^2-a^2]))ArcTanh[(b+a Tan[1/2 (c+d x)])/Sqrt[b^2-a^2]]*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[1/(a_+b_.*sin[c_.+d_.*x_]),x_Symbol] :=
  -2*ArcTanh[(b+a*Tan[(c+d*x)/2])/Rt[b^2-a^2,2]]/(d*Rt[b^2-a^2,2]) /;
FreeQ[{a,b,c,d},x] && NegQ[a^2-b^2]


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Derivation: Algebraic expansion*)


(* ::Subsubsection:: *)
(*Basis: 1/(a+b/z)=1/a-b/(a(b+a z))*)


(* ::Subsubsection:: *)
(*Rule c6: If a^2-b^2!=0, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]1/(a+b Csc[c+d x]) \[DifferentialD]x  \[LongRightArrow]  (x/a)-b/a \[Integral]1/(b+a Sin[c+d x]) \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[1/(a_+b_.*sin[c_.+d_.*x_]^(-1)),x_Symbol] :=
  x/a - Dist[b/a,Int[1/(b+a*sin[c+d*x]),x]] /;
FreeQ[{a,b,c,d},x] && NonzeroQ[a^2-b^2]


(* ::PageBreak:: *)
(**)


(* ::Subsubtitle::Bold::Closed:: *)
(*Rule d: \[Integral](a+b Sin[c+d x]^k)^2 \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Derivation: Rule 12 with m=0*)


(* ::Subsubsection:: *)
(*Rule d: If  k^2=1, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral](a+b Sin[c+d x]^k)^2 \[DifferentialD]x  \[LongRightArrow]  (a^2+(k+1)/(k+3) b^2)x-(2b^2 Cos[c+d x]Sin[c+d x]^k)/(d (k+3))+2a b \[Integral]Sin[c+d x]^k \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[(a_+b_.*sin[c_.+d_.*x_]^k_.)^2,x_Symbol] :=
  (a^2+(k+1)/(k+3)*b^2)*x - 2*b^2*Cos[c+d*x]*Sin[c+d*x]^k/(d*(k+3)) + 2*a*b*Int[sin[c+d*x]^k,x] /;
FreeQ[{a,b,c,d},x] && OneQ[k^2]


(* ::PageBreak:: *)
(**)


(* ::Subsubtitle::Bold::Closed:: *)
(*Rule e: \[Integral]Sqrt[a+b Sin[c+d x]]\[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Basis: \!\( *)
(*\*SubscriptBox[\(\[PartialD]\), \(z\)]\(EllipticE[z, n]\)\)=Sqrt[1-n Sin[z]^2]*)


(* ::Subsubsection:: *)
(*Basis: 1-(2 b)/(a+b) Sin[(c+d x)/2-\[Pi]/4]^2=a/(a+b)+(b Sin[c+d x])/(a+b)*)


(* ::Subsubsection:: *)
(*Rule e1: If a^2-b^2!=0 \[And] a+b>0, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]Sqrt[a+b Sin[c+d x]]\[DifferentialD]x  \[LongRightArrow]  -((2 Sqrt[a+b])/d)EllipticE[\[Pi]/4-(c+d x)/2,(2 b)/(a+b)]*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[Sqrt[a_.+b_.*sin[c_.+Pi/2+d_.*x_]],x_Symbol] :=
  2*Sqrt[Sim[a+b]]/d*EllipticE[(c+d*x)/2,Sim[2*b/(a+b)]] /;
FreeQ[{a,b,c,d},x] && NonzeroQ[a^2-b^2] && PositiveQ[a+b]


(* ::Code:: *)
Int[Sqrt[a_.+b_.*sin[c_.+d_.*x_]],x_Symbol] :=
  -2*Sqrt[Sim[a+b]]/d*EllipticE[Pi/4-(c+d*x)/2,Sim[2*b/(a+b)]] /;
FreeQ[{a,b,c,d},x] && NonzeroQ[a^2-b^2] && PositiveQ[a+b]


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Derivation: Piecewise constant extraction*)


(* ::Subsubsection:: *)
(*Basis: \!\( *)
(*\*SubscriptBox[\(\[PartialD]\), \(z\)]*)
(*\*FractionBox[*)
(*SqrtBox[\( *)
(*\*FractionBox[\(a\), \(a + b\)] + *)
(*\*FractionBox[\(b\), \(a + b\)] f[z]\)], *)
(*SqrtBox[\(a + b\ f[z]\)]]\)=0*)


(* ::Subsubsection:: *)
(*Note: Since a/(a+b)+b/(a+b)=1>0, rule e1 applies to the resulting integrand.*)


(* ::Subsubsection:: *)
(*Rule e2: If a^2-b^2!=0 \[And] \[Not](a+b>0), then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]Sqrt[a+b Sin[c+d x]]\[DifferentialD]x  \[LongRightArrow]  (((a+b)Sqrt[a/(a+b)+b/(a+b) Sin[c+d x]])/Sqrt[a+b Sin[c+d x]])\[Integral]Sqrt[a/(a+b)+b/(a+b) Sin[c+d x]]\[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[Sqrt[a_.+b_.*sin[c_.+d_.*x_]],x_Symbol] :=
  (a+b)*Sqrt[(a+b*Sin[c+d*x])/(a+b)]/Sqrt[a+b*Sin[c+d*x]]*Int[Sqrt[a/(a+b)+b/(a+b)*sin[c+d*x]],x] /;
FreeQ[{a,b,c,d},x] && NonzeroQ[a^2-b^2] && Not[PositiveQ[a+b]]


(* ::PageBreak:: *)
(**)


(* ::Subsubtitle::Bold::Closed:: *)
(*Rule f: \[Integral]1/Sqrt[a+b Sin[c+d x]] \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Basis: \!\( *)
(*\*SubscriptBox[\(\[PartialD]\), \(x\)]\(EllipticF[x, n]\)\)=1/Sqrt[1-n Sin[x]^2]*)


(* ::Subsubsection:: *)
(*Basis: 1-(2 b)/(a+b) Sin[(c+d x)/2-\[Pi]/4]^2=a/(a+b)+(b Sin[c+d x])/(a+b)*)


(* ::Subsubsection:: *)
(*Rule f1: If  a^2-b^2!=0 \[And] a+b>0, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]1/Sqrt[a+b Sin[c+d x]] \[DifferentialD]x  \[LongRightArrow]  -(2/(d Sqrt[a+b]))EllipticF[\[Pi]/4-(c+d x)/2,(2 b)/(a+b)]*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[1/Sqrt[a_.+b_.*sin[c_.+Pi/2+d_.*x_]],x_Symbol] :=
  2/(d*Sqrt[Sim[a+b]])*EllipticF[(c+d*x)/2,Sim[2*b/(a+b)]] /;
FreeQ[{a,b,c,d},x] && NonzeroQ[a^2-b^2] && PositiveQ[a+b]


(* ::Code:: *)
Int[1/Sqrt[a_.+b_.*sin[c_.+d_.*x_]],x_Symbol] :=
  -2/(d*Sqrt[Sim[a+b]])*EllipticF[Pi/4-(c+d*x)/2,Sim[2*b/(a+b)]] /;
FreeQ[{a,b,c,d},x] && NonzeroQ[a^2-b^2] && PositiveQ[a+b]


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Derivation: Piecewise constant extraction*)


(* ::Subsubsection:: *)
(*Basis: \!\( *)
(*\*SubscriptBox[\(\[PartialD]\), \(z\)]*)
(*\*FractionBox[*)
(*SqrtBox[*)
(*FractionBox[\(a + b\ f[z]\), \(a + b\)]], *)
(*SqrtBox[\(a + b\ f[z]\)]]\)=0*)


(* ::Subsubsection:: *)
(*Note: Since a/(a+b)+b/(a+b)=1>0, rule f1 applies to the resulting integrand.*)


(* ::Subsubsection:: *)
(*Rule f2: If  a^2-b^2!=0 \[And] \[Not](a+b>0), then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]1/Sqrt[a+b Sin[c+d x]] \[DifferentialD]x  \[LongRightArrow]  (Sqrt[a/(a+b)+b/(a+b) Sin[c+d x]]/Sqrt[a+b Sin[c+d x]])\[Integral]1/Sqrt[a/(a+b)+b/(a+b) Sin[c+d x]] \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[1/Sqrt[a_.+b_.*sin[c_.+d_.*x_]],x_Symbol] :=
  Sqrt[(a+b*Sin[c+d*x])/(a+b)]/Sqrt[a+b*Sin[c+d*x]]*Int[1/Sqrt[a/(a+b)+b/(a+b)*sin[c+d*x]],x] /;
FreeQ[{a,b,c,d},x] && NonzeroQ[a^2-b^2] && Not[PositiveQ[a+b]]


(* ::PageBreak:: *)
(**)


(* ::Subsubtitle::Bold::Closed:: *)
(*\[Integral](a+b Csc[c+d x])^(n/2) \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Derivation: Piecewise constant extraction*)


(* ::Subsubsection:: *)
(*Basis: \!\( *)
(*\*SubscriptBox[\(\[PartialD]\), \(z\)]\(( *)
(*\*SuperscriptBox[\(f[z]\), \(n/2\)] *)
(*\*SuperscriptBox[\((b/f[z])\), \(n/2\)])\)\)=0*)


(* ::Subsubsection:: *)
(*Rule: If  n^2=1, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral](b Csc[c+d x])^(n/2) \[DifferentialD]x  \[LongRightArrow]  (Sin[c+d x])^(n/2) (b Csc[c+d x])^(n/2) \[Integral]1/Sin[c+d x]^(n/2) \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[(b_.*sin[c_.+d_.*x_]^(-1))^n_,x_Symbol] :=
  Dist[Sin[c+d*x]^n*(b*Csc[c+d*x])^n,Int[1/sin[c+d*x]^n,x]] /;
FreeQ[{b,c,d},x] && ZeroQ[n^2-1/4]


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Derivation: Piecewise constant extraction*)


(* ::Subsubsection:: *)
(*Basis: \!\( *)
(*\*SubscriptBox[\(\[PartialD]\), \(z\)]*)
(*\*FractionBox[*)
(*SqrtBox[\(b + a\ f[z]\)], \( *)
(*\*SqrtBox[\(f[z]\)] *)
(*\*SqrtBox[\(a + b/f[z]\)]\)]\)=0*)


(* ::Subsubsection:: *)
(*Rule: If  a^2-b^2!=0 \[And] n-1/2\[Element]\[DoubleStruckCapitalZ] \[And] -2<n<2, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral](a+b Csc[c+d x])^n \[DifferentialD]x  \[LongRightArrow]  (Sqrt[b+a Sin[c+d x]]/(Sqrt[Sin[c+d x]] Sqrt[a+b Csc[c+d x]]))\[Integral](b+a Sin[c+d x])^n/Sin[c+d x]^n \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[(a_+b_.*sin[c_.+d_.*x_]^(-1))^n_,x_Symbol] :=
  Dist[Sqrt[b+a*Sin[c+d*x]]/(Sqrt[Sin[c+d*x]]*Sqrt[a+b*Csc[c+d*x]]),
    Int[(b+a*sin[c+d*x])^n/sin[c+d*x]^n,x]] /;
FreeQ[{a,b,c,d},x] && NonzeroQ[a^2-b^2] && IntegerQ[n-1/2] && -2<n<2


(* ::PageBreak:: *)
(**)


(* ::Subsubtitle::Bold::Closed:: *)
(*Rules 17-18:  \[Integral](a+b Csc[c+d x])^n \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Derivation: Rule 6 with m=0 and k=-1*)


(* ::Subsubsection:: *)
(*Rule 17: If  a^2-b^2!=0 \[And] n<-1, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral](a+b Csc[c+d x])^n \[DifferentialD]x  \[LongRightArrow]  *)
(*((b^2 Cot[c+d x](a+b Csc[c+d x])^(n+1))/(a d (n+1) (a^2-b^2)))+1/(a (n+1) (a^2-b^2))\[CenterDot]*)
(*\[Integral]((a^2-b^2) (n+1)-a b(n+1)Csc[c+d x]+b^2 (n+2)Csc[c+d x]^2)(a+b Csc[c+d x])^(n+1) \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[(a_+b_.*sin[c_.+d_.*x_]^(-1))^n_,x_Symbol] :=
  b^2*Cot[c+d*x]*(a+b*Csc[c+d*x])^(n+1)/(a*d*(n+1)*(a^2-b^2)) + 
  Dist[1/(a*(n+1)*(a^2-b^2)),
    Int[((a^2-b^2)*(n+1)-(a*b*(n+1))*sin[c+d*x]^(-1)+(b^2*(n+2))*sin[c+d*x]^(-2))*
      (a+b*sin[c+d*x]^(-1))^(n+1),x]] /;
FreeQ[{a,b,c,d},x] && NonzeroQ[a^2-b^2] && RationalQ[n] && n<-1


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Derivation: Rule 3a with m=0 and k=-1*)


(* ::Subsubsection:: *)
(*Rule 18: If  a^2-b^2!=0 \[And] n>2, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral](a+b Csc[c+d x])^n \[DifferentialD]x  \[LongRightArrow]  *)
(*-((b^2 Cot[c+d x](a+b Csc[c+d x])^(n-2))/(d(n-1)))+1/(n-1) \[CenterDot]*)
(*\[Integral](a^3 (n-1)+b(b^2 (n-2)+3 a^2 (n-1))Csc[c+d x]+a b^2 (3n-4)Csc[c+d x]^2)(a+b Csc[c+d x])^(n-3) \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[(a_+b_.*sin[c_.+d_.*x_]^(-1))^n_,x_Symbol] :=
  -b^2*Cot[c+d*x]*(a+b*Csc[c+d*x])^(n-2)/(d*(n-1)) + 
  Dist[1/(n-1),
    Int[(a^3*(n-1)+(b*(b^2*(n-2)+3*a^2*(n-1)))*sin[c+d*x]^(-1)+(a*b^2*(3*n-4))*sin[c+d*x]^(-2))*
      (a+b*sin[c+d*x]^(-1))^(n-3),x]] /;
FreeQ[{a,b,c,d},x] && NonzeroQ[a^2-b^2] && RationalQ[n] && n>2


(* ::PageBreak:: *)
(**)


(* ::Subsubtitle::Bold::Closed:: *)
(*Rules 15-16:  \[Integral](b Sin[c+d x]^k)^n \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Derivation: Rule 10a inverted*)


(* ::Subsubsection:: *)
(*Rule 15: If  k^2=1 \[And] n<-1, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral](b Sin[c+d x]^k)^n \[DifferentialD]x  \[LongRightArrow]  ((2Cos[c+d x](b Sin[c+d x]^k)^(n+1))/(b d (2n+k+1)))+(2n+k+3)/(b^2 (2n+k+1)) \[Integral](b Sin[c+d x]^k)^(n+2) \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[(b_.*sin[c_.+d_.*x_]^k_.)^n_,x_Symbol] :=
  2*Cos[c+d*x]*(b*Sin[c+d*x]^k)^(n+1)/(b*d*(2*n+k+1)) + 
  Dist[(2*n+k+3)/(b^2*(2*n+k+1)),Int[(b*sin[c+d*x]^k)^(n+2),x]] /;
FreeQ[{b,c,d},x] && OneQ[k^2] && RationalQ[n] && n<-1


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Derivation: Rule 3a or 3b with m=0 and a=0*)


(* ::Subsubsection:: *)
(*Rule 16: If  k^2=1 \[And] n>1, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral](b Sin[c+d x]^k)^n \[DifferentialD]x  \[LongRightArrow]  -((2b Cos[c+d x](b Sin[c+d x]^k)^(n-1))/(d (2n+k-1)))+(b^2 (2 n+k-3))/(2 n+k-1) \[Integral](b Sin[c+d x]^k)^(n-2) \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[(b_.*sin[c_.+d_.*x_]^k_.)^n_,x_Symbol] :=
  -2*b*Cos[c+d*x]*(b*Sin[c+d*x]^k)^(n-1)/(d*(2*n+k-1)) + 
  Dist[b^2*(2*n+k-3)/(2*n+k-1),Int[(b*sin[c+d*x]^k)^(n-2),x]] /;
FreeQ[{b,c,d},x] && OneQ[k^2] && RationalQ[n] && n>1


(* ::PageBreak:: *)
(**)


(* ::Title::Plain::Closed:: *)
(* Integration Rules for *)
(*\[Integral](sin^j(z))^m (a+b sin^k(z))^n \[DifferentialD]z when j^2=1\[And]k^2=1*)


(* ::Subsubtitle::Bold::Closed:: *)
(*Rule g:  \[Integral]1/(Sin[c+d x](a+b Sin[c+d x])) \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Derivation: Algebraic expansion*)


(* ::Subsubsection:: *)
(*Basis: 1/(z(a+b z))=1/(a z)-b/(a(a+b z))*)


(* ::Subsubsection:: *)
(*Rule g:*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]1/(Sin[c+d x](a+b Sin[c+d x])) \[DifferentialD]x  \[LongRightArrow]  (1/a)\[Integral]1/Sin[c+d x] \[DifferentialD]x-b/a \[Integral]1/(a+b Sin[c+d x]) \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[1/(sin[c_.+d_.*x_]*(a_.+b_.*sin[c_.+d_.*x_])),x_Symbol] :=
  1/a*Int[1/Sin[c+d*x],x] - b/a*Int[1/(a+b*Sin[c+d*x]),x] /;
FreeQ[{a,b,c,d},x]


(* ::Code:: *)
Int[1/((a_.+b_.*sin[c_.+d_.*x_])*(e_+f_.*sin[c_.+d_.*x_])),x_Symbol] :=
  b/(b*e-a*f)*Int[1/(a+b*sin[c+d*x]),x] - 
  f/(b*e-a*f)*Int[1/(e+f*sin[c+d*x]),x] /;
FreeQ[{a,b,c,d,e,f},x] && NonzeroQ[b*e-a*f]


(* ::PageBreak:: *)
(**)


(* ::Subsubtitle::Bold::Closed:: *)
(*Rule h:  \[Integral]1/((a+b Sin[c+d x])Sqrt[e+f Sin[c+d x]]) \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Basis: \!\( *)
(*\*SubscriptBox[\(\[PartialD]\), \(z\)]\(EllipticPi[2  m, *)
(*\*FractionBox[\(z\), \(2\)] - *)
(*\*FractionBox[\(\[Pi]\), \(4\)], 2  n]\)\)=1/(2 (1-m+m Sin[z]) Sqrt[1-n+n Sin[z]])*)


(* ::Subsubsection:: *)
(*Rule h1: If  a^2-b^2!=0 \[And] e^2-f^2!=0 \[And] e+f>0, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]1/((a+b Sin[c+d x])Sqrt[e+f Sin[c+d x]]) \[DifferentialD]x  \[LongRightArrow]  (2 /(d(a+b)Sqrt[e+f ]))EllipticPi[(2 b)/(a+b),(c+d x)/2-\[Pi]/4,(2 f)/(e+f)]*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[1/((a_.+b_.*sin[c_.+Pi/2+d_.*x_])*Sqrt[e_.+f_.*sin[c_.+Pi/2+d_.*x_]]),x_Symbol] :=
  2/(d*(a+b)*Rt[e+f,2])*EllipticPi[Sim[2*b/(a+b)],(c+d*x)/2,Sim[2*f/(e+f)]] /;
FreeQ[{a,b,c,d,e,f},x] && NonzeroQ[a^2-b^2] && NonzeroQ[e^2-f^2] && PositiveQ[e+f]


(* ::Code:: *)
Int[1/((a_.+b_.*sin[c_.+d_.*x_])*Sqrt[e_.+f_.*sin[c_.+d_.*x_]]),x_Symbol] :=
  2/(d*(a+b)*Rt[e+f,2])*EllipticPi[Sim[2*b/(a+b)],(c+d*x)/2-Pi/4,Sim[2*f/(e+f)]] /;
FreeQ[{a,b,c,d,e,f},x] && NonzeroQ[a^2-b^2] && NonzeroQ[e^2-f^2] && PositiveQ[e+f]


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Derivation: Piecewise constant extraction*)


(* ::Subsubsection:: *)
(*Basis: \!\( *)
(*\*SubscriptBox[\(\[PartialD]\), \(z\)]*)
(*\*FractionBox[*)
(*SqrtBox[*)
(*FractionBox[\(e + f\ g[z]\), \(e + f\)]], *)
(*SqrtBox[\(e + f\ g[z]\)]]\)=0*)


(* ::Subsubsection:: *)
(*Note: Since e/(e+f)+f/(e+f)=1>0, rule h1 applies to the resulting integrand.*)


(* ::Subsubsection:: *)
(*Rule h2: If  a^2-b^2!=0 \[And] e^2-f^2!=0 \[And] \[Not](e+f>0), then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]1/((a+b Sin[c+d x])Sqrt[e+f Sin[c+d x]]) \[DifferentialD]x  \[LongRightArrow]  *)
(*(Sqrt[((e+f Sin[c+d x])/(e+f))]/Sqrt[e+f Sin[c+d x]])\[Integral]1/((a+b Sin[c+d x])Sqrt[e/(e+f)+f/(e+f) Sin[c+d x]]) \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[1/((a_.+b_.*sin[c_.+d_.*x_])*Sqrt[e_.+f_.*sin[c_.+d_.*x_]]),x_Symbol] :=
  Sqrt[(e+f*Sin[c+d*x])/(e+f)]/Sqrt[e+f*Sin[c+d*x]]*
    Int[1/((a+b*sin[c+d*x])*Sqrt[e/(e+f)+f/(e+f)*sin[c+d*x]]),x] /;
FreeQ[{a,b,c,d},x] && NonzeroQ[a^2-b^2] && NonzeroQ[e^2-f^2] && Not[PositiveQ[e+f]]


(* ::PageBreak:: *)
(**)


(* ::Subsubtitle::Bold::Closed:: *)
(*Rule i:  \[Integral]Sqrt[a+b Sin[c+d x]]/(e+f Sin[c+d x]) \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Derivation: Algebraic expansion*)


(* ::Subsubsection:: *)
(*Basis: Sqrt[a+b z]/(e+f z)=b/(f Sqrt[a+b z])+(a f-b e)/(f(e+f z)Sqrt[a +b z])*)


(* ::Subsubsection:: *)
(*Rule i: If  a^2-b^2!=0 \[And] e^2-f^2!=0 \[And] a f-b e!=0, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]Sqrt[a+b Sin[c+d x]]/(e+f Sin[c+d x]) \[DifferentialD]x  \[LongRightArrow]  *)
(*(b/f)\[Integral]1/Sqrt[a+b Sin[c+d x]] \[DifferentialD]x+(a f-b e)/f \[Integral]1/((e+f Sin[c+d x])Sqrt[a+b Sin[c+d x]]) \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[Sqrt[a_.+b_.*sin[c_.+d_.*x_]]/(e_.+f_.*sin[c_.+d_.*x_]),x_Symbol] :=
  b/f*Int[1/Sqrt[a+b*sin[c+d*x]],x] + 
  (a*f-b*e)/f*Int[1/((e+f*sin[c+d*x])*Sqrt[a+b*sin[c+d*x]]),x] /;
FreeQ[{a,b,c,d,e,f},x] && NonzeroQ[a^2-b^2] && NonzeroQ[e^2-f^2] && NonzeroQ[a*f-b*e]


(* ::PageBreak:: *)
(**)


(* ::Subsubtitle::Bold::Closed:: *)
(*Rule j:  \[Integral](a+b Sin[c+d x])^(3/2)/(e+f Sin[c+d x]) \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Derivation: Algebraic expansion*)


(* ::Subsubsection:: *)
(*Basis: (a+b z)^(3/2)/(e+f z)=(b Sqrt[a+b z])/f+((a f-b e)Sqrt[a +b z])/(f(e+f z))*)


(* ::Subsubsection:: *)
(*Rule j: If  a^2-b^2!=0 \[And] e^2-f^2!=0 \[And] a f-b e!=0, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral](a+b Sin[c+d x])^(3/2)/(e+f Sin[c+d x]) \[DifferentialD]x  \[LongRightArrow]  (b/f)\[Integral]Sqrt[a+b Sin[c+d x]]\[DifferentialD]x+(a f-b e)/f \[Integral]Sqrt[a+b Sin[c+d x]]/(e+f Sin[c+d x]) \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[(a_.+b_.*sin[c_.+d_.*x_])^(3/2)/(e_.+f_.*sin[c_.+d_.*x_]),x_Symbol] :=
  b/f*Int[Sqrt[a+b*sin[c+d*x]],x] + 
  Dist[(a*f-b*e)/f,Int[Sqrt[a+b*sin[c+d*x]]/(e+f*sin[c+d*x]),x]] /;
FreeQ[{a,b,c,d,e,f},x] && NonzeroQ[a^2-b^2] && NonzeroQ[e^2-f^2] && NonzeroQ[a*f-b*e]


(* ::PageBreak:: *)
(**)


(* ::Subsubtitle::Bold::Closed:: *)
(*Rule k:  \[Integral]1/(Sqrt[Sin[c+d x]] Sqrt[a+b Sin[c+d x]]) \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Derivation: Algebraic expansion*)


(* ::Subsubsection:: *)
(*Basis: If  b>0 \[And] b-a>0, then Sqrt[a+b z]=Sqrt[1+z] Sqrt[(a+b z)/(1+z)]*)


(* ::Subsubsection:: *)
(*Rule k1: If  b>0 \[And] b^2-a^2>0, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]1/(Sqrt[Sin[c+d x]] Sqrt[a+b Sin[c+d x]]) \[DifferentialD]x  \[LongRightArrow]  (2/(d Sqrt[a+b]))EllipticF[ArcSin[Tan[(c+d x)/2-\[Pi]/4]],-((a-b)/(a+b))]*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[1/(Sqrt[sin[c_.+d_.*x_]]*Sqrt[a_+b_.*sin[c_.+d_.*x_]]),x_Symbol] :=
  2/(d*Sqrt[a+b])*EllipticF[ArcSin[Tan[(c-Pi/2+d*x)/2]],-Sim[(a-b)/(a+b)]] /;
FreeQ[{a,b,c,d},x] && PositiveQ[b] && PositiveQ[b^2-a^2]


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Derivation: Piecewise constant extraction*)


(* ::Subsubsection:: *)
(*Basis:  \!\( *)
(*\*SubscriptBox[\(\[PartialD]\), \(z\)]\(( *)
(*\*FractionBox[*)
(*SqrtBox[\(1 + f[z]\)], *)
(*SqrtBox[\(a + b\ f[z]\)]] *)
(*\*SqrtBox[*)
(*FractionBox[\(a + b\ f[z]\), \(\((a + b)\)\ \((1 + f[z])\)\)]])\)\)=0*)


(* ::Subsubsection:: *)
(*Rule k2: If  a^2-b^2!=0, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral](1/(Sqrt[Sin[c+d x]] Sqrt[a+b Sin[c+d x]]))  \[LongRightArrow]  *)
(*((2Sqrt[1+Sin[c+d x]])/(d Sqrt[a+b Sin[c+d x]])) Sqrt[(a+b Sin[c+d x])/((a+b) (1+Sin[c+d x]))]EllipticF[ArcSin[Tan[(c+d x)/2-\[Pi]/4]],-((a-b)/(a+b))]*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[1/(Sqrt[sin[c_.+d_.*x_]]*Sqrt[a_+b_.*sin[c_.+d_.*x_]]),x_Symbol] :=
  2*Sqrt[1+Sin[c+d*x]]/(d*Sqrt[a+b*Sin[c+d*x]])*
  Sqrt[(a+b*Sin[c+d*x])/((a+b)*(1+Sin[c+d*x]))]*
  EllipticF[ArcSin[Tan[(c-Pi/2+d*x)/2]],-Sim[(a-b)/(a+b)]] /;
FreeQ[{a,b,c,d},x] && NonzeroQ[a^2-b^2]


(* ::PageBreak:: *)
(**)


(* ::Subsubtitle::Bold::Closed:: *)
(*Rule l:  \[Integral]Sqrt[Sin[c+d x]] Sqrt[a+b Sin[c+d x]]\[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Derivation: Algebraic expansion*)


(* ::Subsubsection:: *)
(*Rule l: If  a^2-b^2!=0, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]Sqrt[Sin[c+d x]] Sqrt[a+b Sin[c+d x]]\[DifferentialD]x  \[LongRightArrow]  *)
(*-a\[Integral]1/(Sqrt[Sin[c+d x]] Sqrt[a+b Sin[c+d x]]) \[DifferentialD]x+\[Integral](a+a Sin[c+d x]+b Sin[c+d x]^2)/(Sqrt[Sin[c+d x]] Sqrt[a+b Sin[c+d x]]) \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[Sqrt[sin[c_.+d_.*x_]]*Sqrt[a_+b_.*sin[c_.+d_.*x_]],x_Symbol] :=
  -a*Int[1/(Sqrt[sin[c+d*x]]*Sqrt[a+b*sin[c+d*x]]),x] + 
  Int[(a+a*sin[c+d*x]+b*sin[c+d*x]^2)/(Sqrt[sin[c+d*x]]*Sqrt[a+b*sin[c+d*x]]),x] /;
FreeQ[{a,b,c,d},x] && NonzeroQ[a^2-b^2]


(* ::PageBreak:: *)
(**)


(* ::Subsubtitle::Bold::Closed:: *)
(*Rule m:  \[Integral]Sqrt[a+b Sin[c+d x]]/ Sqrt[e+f Sin[c+d x]] \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Derivation: Algebraic expansion*)


(* ::Subsubsection:: *)
(*Rule m1: If  a^2-b^2!=0, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]Sqrt[Sin[c+d x]]/ Sqrt[a+b Sin[c+d x]] \[DifferentialD]x  \[LongRightArrow]  *)
(*-\[Integral]1/(Sqrt[Sin[c+d x]] Sqrt[a+b Sin[c+d x]]) \[DifferentialD]x+\[Integral](1+Sin[c+d x])/(Sqrt[Sin[c+d x]] Sqrt[a+b Sin[c+d x]]) \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[Sqrt[sin[c_.+d_.*x_]]/Sqrt[a_+b_.*sin[c_.+d_.*x_]],x_Symbol] :=
  -Int[1/(Sqrt[sin[c+d*x]]*Sqrt[a+b*sin[c+d*x]]),x] +
  Int[(1+sin[c+d*x])/(Sqrt[sin[c+d*x]]*Sqrt[a+b*sin[c+d*x]]),x] /;
FreeQ[{a,b,c,d},x] && NonzeroQ[a^2-b^2]


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Derivation: Algebraic expansion*)


(* ::Subsubsection:: *)
(*Rule m2: If  a^2-b^2!=0, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]Sqrt[a+b Sin[c+d x]]/ Sqrt[Sin[c+d x]] \[DifferentialD]x  \[LongRightArrow]  *)
(*(a-b)\[Integral]1/(Sqrt[Sin[c+d x]] Sqrt[a+b Sin[c+d x]]) \[DifferentialD]x+b \[Integral](1+Sin[c+d x])/(Sqrt[Sin[c+d x]] Sqrt[a+b Sin[c+d x]]) \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[Sqrt[a_+b_.*sin[c_.+d_.*x_]]/Sqrt[sin[c_.+d_.*x_]],x_Symbol] :=
  (a-b)*Int[1/(Sqrt[sin[c+d*x]]*Sqrt[a+b*sin[c+d*x]]),x] +
  Dist[b,Int[(1+sin[c+d*x])/(Sqrt[sin[c+d*x]]*Sqrt[a+b*sin[c+d*x]]),x]] /;
FreeQ[{a,b,c,d},x] && NonzeroQ[a^2-b^2]


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Derivation: Algebraic expansion*)


(* ::Subsubsection:: *)
(*Note: This rule unifies rules m1 and m2, but requires messy application conditions.*)


(* ::Subsubsection:: *)
(*Rule: If  a^2-b^2!=0 \[And] e^2-f^2!=0 \[And] b e-a f!=0, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]Sqrt[a+b Sin[c+d x]]/ Sqrt[e+f Sin[c+d x]] \[DifferentialD]x  \[LongRightArrow]  *)
(*(a-b)\[Integral]1/(Sqrt[a+b Sin[c+d x]] Sqrt[e+f Sin[c+d x]]) \[DifferentialD]x+b \[Integral](1+Sin[c+d x])/(Sqrt[a+b Sin[c+d x]] Sqrt[e+f Sin[c+d x]]) \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
(* Int[Sqrt[a_.+b_.*sin[c_.+d_.*x_]]/Sqrt[e_.+f_.*sin[c_.+d_.*x_]],x_Symbol] :=
  (a-b)*Int[1/(Sqrt[a+b*sin[c+d*x]]*Sqrt[e+f*sin[c+d*x]]),x] +
  Dist[b,Int[(1+sin[c+d*x])/(Sqrt[a+b*sin[c+d*x]]*Sqrt[e+f*sin[c+d*x]]),x]] /;
FreeQ[{a,b,c,d,e,f},x] && NonzeroQ[a^2-b^2] && NonzeroQ[e^2-f^2] && NonzeroQ[b*e-a*f] *)


(* ::PageBreak:: *)
(**)


(* ::Subsubtitle::Bold::Closed:: *)
(*Rule n:  \[Integral]Sqrt[a+b Sin[c+d x]]/ ((e+f Sin[c+d x])^(3/2)) \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Derivation: Algebraic expansion*)


(* ::Subsubsection:: *)
(*Rule n1: If  a^2-b^2!=0, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]Sqrt[Sin[c+d x]]/(a+b Sin[c+d x])^(3/2) \[DifferentialD]x  \[LongRightArrow]  *)
(*-(1/(a-b))\[Integral]1/(Sqrt[Sin[c+d x]] Sqrt[a+b Sin[c+d x]] ) \[DifferentialD]x+a/(a-b) \[Integral](1+Sin[c+d x])/(Sqrt[Sin[c+d x]] (a+b Sin[c+d x])^(3/2)) \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[Sqrt[sin[c_.+d_.*x_]]/(a_+b_.*sin[c_.+d_.*x_])^(3/2),x_Symbol] :=
  -1/(a-b)*Int[1/(Sqrt[sin[c+d*x]]*Sqrt[a+b*sin[c+d*x]]),x] + 
  Dist[a/(a-b),Int[(1+sin[c+d*x])/(Sqrt[sin[c+d*x]]*(a+b*sin[c+d*x])^(3/2)),x]] /; 
FreeQ[{a,b,c,d},x] && NonzeroQ[a^2-b^2]


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Derivation: Algebraic expansion*)


(* ::Subsubsection:: *)
(*Rule n2: If  a^2-b^2!=0, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]Sqrt[a+b Sin[c+d x]]/Sin[c+d x]^(3/2) \[DifferentialD]x  \[LongRightArrow]  *)
(*(a+b)\[Integral]1/(Sqrt[Sin[c+d x]] Sqrt[a+b Sin[c+d x]] ) \[DifferentialD]x+a \[Integral](1-Sin[c+d x])/(Sin[c+d x]^(3/2) Sqrt[a+b Sin[c+d x]]) \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[Sqrt[a_+b_.*sin[c_.+d_.*x_]]/sin[c_.+d_.*x_]^(3/2),x_Symbol] :=
  Dist[a+b,Int[1/(Sqrt[sin[c+d*x]]*Sqrt[a+b*sin[c+d*x]]),x]] + 
  Dist[a,Int[(1-sin[c+d*x])/(sin[c+d*x]^(3/2)*Sqrt[a+b*sin[c+d*x]]),x]] /; 
FreeQ[{a,b,c,d},x] && NonzeroQ[a^2-b^2]


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Derivation: Algebraic expansion*)


(* ::Subsubsection:: *)
(*Note: This rule unifies rules n1 and n2, but requires messy application conditions.*)


(* ::Subsubsection:: *)
(*Rule: If  a^2-b^2!=0 \[And] e^2-f^2!=0 \[And] b e-a f!=0, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]Sqrt[a+b Sin[c+d x]]/(e+f Sin[c+d x])^(3/2) \[DifferentialD]x  \[LongRightArrow]  *)
(*((a-b)/(e-f))\[Integral]1/(Sqrt[a+b Sin[c+d x]] Sqrt[e+f Sin[c+d x]] ) \[DifferentialD]x+(b e-a f)/(e-f) \[Integral](1+Sin[c+d x])/(Sqrt[a+b Sin[c+d x]] (e+f Sin[c+d x])^(3/2)) \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
(* Int[Sqrt[a_.+b_.*sin[c_.+d_.*x_]]/(e_.+f_.*sin[c_.+d_.*x_])^(3/2),x_Symbol] :=
  Dist[(a-b)/(e-f),Int[1/(Sqrt[a+b*sin[c+d*x]]*Sqrt[e+f*sin[c+d*x]]),x]] + 
  Dist[(b*e-a*f)/(e-f),Int[(1+sin[c+d*x])/(Sqrt[a+b*sin[c+d*x]]*(e+f*sin[c+d*x])^(3/2)),x]] /; 
FreeQ[{a,b,c,d,e,f},x] && NonzeroQ[a^2-b^2] && NonzeroQ[e^2-f^2] && NonzeroQ[b*e-a*f] *)


(* ::PageBreak:: *)
(**)


(* ::Subsubtitle::Bold::Closed:: *)
(*Rule o:  \[Integral](a+b Sin[c+d x])^(3/2)/Sqrt[e+f Sin[c+d x]] \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Derivation: Algebraic expansion*)


(* ::Subsubsection:: *)
(*Rule o1: If  a^2-b^2!=0, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]Sin[c+d x]^(3/2)/Sqrt[a+b Sin[c+d x]] \[DifferentialD]x  \[LongRightArrow]  *)
(*-(a/(2 b))\[Integral](1+Sin[c+d x])/(Sqrt[Sin[c+d x]] Sqrt[a+b Sin[c+d x]]) \[DifferentialD]x+1/(2b) \[Integral](a+a Sin[c+d x]+2 b Sin[c+d x]^2)/(Sqrt[Sin[c+d x]] Sqrt[a+b Sin[c+d x]]) \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[sin[c_.+d_.*x_]^(3/2)/Sqrt[a_+b_.*sin[c_.+d_.*x_]],x_Symbol] :=
  -a/(2*b)*Int[(1+sin[c+d*x])/(Sqrt[sin[c+d*x]]*Sqrt[a+b*sin[c+d*x]]),x] + 
  Dist[1/(2*b),
    Int[(a+a*sin[c+d*x]+2*b*sin[c+d*x]^2)/(Sqrt[sin[c+d*x]]*Sqrt[a+b*sin[c+d*x]]),x]] /;
FreeQ[{a,b,c,d},x] && NonzeroQ[a^2-b^2]


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Derivation: Algebraic expansion*)


(* ::Subsubsection:: *)
(*Rule o2: If  a^2-b^2!=0, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral](a+b Sin[c+d x])^(3/2)/Sqrt[Sin[c+d x]] \[DifferentialD]x  \[LongRightArrow]  *)
(*((3a b)/2)\[Integral](1+Sin[c+d x])/(Sqrt[Sin[c+d x]] Sqrt[a+b Sin[c+d x]]) \[DifferentialD]x+1/2 \[Integral](a (2 a-3 b)+a b Sin[c+d x]+2 b^2 Sin[c+d x]^2)/(Sqrt[Sin[c+d x]] Sqrt[a+b Sin[c+d x]]) \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[(a_+b_.*sin[c_.+d_.*x_])^(3/2)/Sqrt[sin[c_.+d_.*x_]],x_Symbol] :=
  3*a*b/2*Int[(1+sin[c+d*x])/(Sqrt[sin[c+d*x]]*Sqrt[a+b*sin[c+d*x]]),x] + 
  Dist[1/2,
    Int[(a*(2*a-3*b)+a*b*sin[c+d*x]+2*b^2*sin[c+d*x]^2)/(Sqrt[sin[c+d*x]]*Sqrt[a+b*sin[c+d*x]]),x]] /;
FreeQ[{a,b,c,d},x] && NonzeroQ[a^2-b^2]


(* ::PageBreak:: *)
(**)


(* ::Subsubtitle::Bold::Closed:: *)
(*Rule p:  \[Integral](a+b Sin[c+d x])^(3/2)/(e+f Sin[c+d x])^(3/2) \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Derivation: Algebraic expansion*)


(* ::Subsubsection:: *)
(*Rule p1: If  a^2-b^2!=0, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]Sin[c+d x]^(3/2)/(a+b Sin[c+d x])^(3/2) \[DifferentialD]x  \[LongRightArrow]  (1/b)\[Integral](1+Sin[c+d x])/(Sqrt[Sin[c+d x]] Sqrt[a+b Sin[c+d x]] ) \[DifferentialD]x+1/b \[Integral](-a-(a+b) Sin[c+d x])/(Sqrt[Sin[c+d x]] ((a+b Sin[c+d x])^(3/2)) ) \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[sin[c_.+d_.*x_]^(3/2)/(a_+b_.*sin[c_.+d_.*x_])^(3/2),x_Symbol] :=
  1/b*Int[(1+sin[c+d*x])/(Sqrt[sin[c+d*x]]*Sqrt[a+b*sin[c+d*x]]),x] + 
  Dist[1/b,Int[(-a-(a+b)*sin[c+d*x])/(Sqrt[sin[c+d*x]]*(a+b*sin[c+d*x])^(3/2)),x]] /;
FreeQ[{a,b,c,d},x] && NonzeroQ[a^2-b^2]


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Derivation: Algebraic expansion*)


(* ::Subsubsection:: *)
(*Rule p2: If  a^2-b^2!=0, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral](a+b Sin[c+d x])^(3/2)/Sin[c+d x]^(3/2) \[DifferentialD]x  \[LongRightArrow]  b^2\[Integral](1+Sin[c+d x])/(Sqrt[Sin[c+d x]] Sqrt[a+b Sin[c+d x]] ) \[DifferentialD]x+\[Integral](a^2+b(2 a-b) Sin[c+d x])/(((Sin[c+d x])^(3/2)) Sqrt[a+b Sin[c+d x]] ) \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[(a_+b_.*sin[c_.+d_.*x_])^(3/2)/sin[c_.+d_.*x_]^(3/2),x_Symbol] :=
  b^2*Int[(1+sin[c+d*x])/(Sqrt[sin[c+d*x]]*Sqrt[a+b*sin[c+d*x]]),x] + 
  Int[(a^2+b*(2*a-b)*sin[c+d*x])/(sin[c+d*x]^(3/2)*Sqrt[a+b*sin[c+d*x]]),x] /;
FreeQ[{a,b,c,d},x] && NonzeroQ[a^2-b^2]


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Derivation: Algebraic expansion*)


(* ::Subsubsection:: *)
(*Note: This rule unifies rules p1 and p2, but requires messy application conditions.*)


(* ::Subsubsection:: *)
(*Rule: If  a^2-b^2!=0 \[And] e^2-f^2!=0 \[And] b e-a f!=0, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral](a+b Sin[c+d x])^(3/2)/(e+f Sin[c+d x])^(3/2) \[DifferentialD]x  \[LongRightArrow]  (b^2/f)\[Integral](1+Sin[c+d x])/(Sqrt[a+b Sin[c+d x]] Sqrt[e+f Sin[c+d x]] ) \[DifferentialD]x+1/f \[Integral](a^2 f-b^2 e+b (2 a f-b (e+f)) Sin[c+d x])/(Sqrt[a+b Sin[c+d x]] ((e+f Sin[c+d x])^(3/2)) ) \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
(* Int[(a_.+b_.*sin[c_.+d_.*x_])^(3/2)/(e_.+f_.*sin[c_.+d_.*x_])^(3/2),x_Symbol] :=
  b^2/f*Int[(1+sin[c+d*x])/(Sqrt[a+b*sin[c+d*x]]*Sqrt[e+f*sin[c+d*x]]),x] + 
  Dist[1/f,
    Int[(a^2*f-b^2*e+b*(2*a*f-b*(e+f))*sin[c+d*x])/(Sqrt[a+b*sin[c+d*x]]*(e+f*sin[c+d*x])^(3/2)),x]] /;
FreeQ[{a,b,c,d,e,f},x] && NonzeroQ[a^2-b^2] && NonzeroQ[e^2-f^2] && NonzeroQ[b*e-a*f] *)


(* ::PageBreak:: *)
(**)


(* ::Subsubtitle::Bold::Closed:: *)
(*Rule q:  \[Integral]1/(Sqrt[a+b Sin[c+d x]] (e+f Sin[c+d x])^(3/2)) \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Derivation: Algebraic expansion*)


(* ::Subsubsection:: *)
(*Rule q1: If  a^2-b^2!=0, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]1/(Sqrt[Sin[c+d x]] (a+b Sin[c+d x])^(3/2)) \[DifferentialD]x  \[LongRightArrow]  *)
(*(1/(a-b))\[Integral]1/(Sqrt[Sin[c+d x]] Sqrt[a+b Sin[c+d x]]) \[DifferentialD]x-b/(a-b) \[Integral](1+Sin[c+d x])/(Sqrt[Sin[c+d x]] (a+b Sin[c+d x])^(3/2)) \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[1/(Sqrt[sin[c_.+d_.*x_]]*(a_+b_.*sin[c_.+d_.*x_])^(3/2)),x_Symbol] :=
  1/(a-b)*Int[1/(Sqrt[sin[c+d*x]]*Sqrt[a+b*sin[c+d*x]]),x] - 
  Dist[b/(a-b),Int[(1+sin[c+d*x])/(Sqrt[sin[c+d*x]]*(a+b*sin[c+d*x])^(3/2)),x]] /;
FreeQ[{a,b,c,d},x] && NonzeroQ[a^2-b^2]


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Derivation: Algebraic expansion*)


(* ::Subsubsection:: *)
(*Rule q2: If  a^2-b^2!=0, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]1/(Sin[c+d x]^(3/2) Sqrt[a+b Sin[c+d x]]) \[DifferentialD]x  \[LongRightArrow]  *)
(*\[Integral]1/(Sqrt[Sin[c+d x]] Sqrt[a+b Sin[c+d x]]) \[DifferentialD]x+\[Integral](1-Sin[c+d x])/(Sin[c+d x]^(3/2) Sqrt[a+b Sin[c+d x]]) \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[1/(sin[c_.+d_.*x_]^(3/2)*Sqrt[a_+b_.*sin[c_.+d_.*x_]]),x_Symbol] :=
  Int[1/(Sqrt[sin[c+d*x]]*Sqrt[a+b*sin[c+d*x]]),x] + 
  Int[(1-sin[c+d*x])/(sin[c+d*x]^(3/2)*Sqrt[a+b*sin[c+d*x]]),x] /;
FreeQ[{a,b,c,d},x] && NonzeroQ[a^2-b^2]


(* ::PageBreak:: *)
(**)


(* ::Subsubtitle::Bold::Closed:: *)
(*\[Integral]Sqrt[a+b Sin[c+d x]]/(Sqrt[Sin[c+d x]] (A+A Sin[c+d x])) \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Basis: If  b>0 \[And] b-a>0, then Sqrt[a+b z]=Sqrt[1+z] Sqrt[(a+b z)/(1+z)]*)


(* ::Subsubsection:: *)
(*Rule: If  b>0 \[And] b^2-a^2>0, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]Sqrt[a+b Sin[c+d x]]/(Sqrt[Sin[c+d x]] (A+A Sin[c+d x])) \[DifferentialD]x  \[LongRightArrow]  (Sqrt[a+b]/(d A))EllipticE[ArcSin[Tan[(c+d x)/2-\[Pi]/4]],-((a-b)/(a+b))]*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[Sqrt[a_+b_.*sin[c_.+d_.*x_]]/(Sqrt[sin[c_.+d_.*x_]]*(A_+B_.*sin[c_.+d_.*x_])),x_Symbol] :=
  Sqrt[a+b]/(d*A)*EllipticE[ArcSin[Tan[(c-Pi/2+d*x)/2]],-Sim[(a-b)/(a+b)]] /;
FreeQ[{a,b,c,d,A,B},x] && ZeroQ[A-B] && PositiveQ[b] && PositiveQ[b^2-a^2]


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Derivation: Piecewise constant extraction*)


(* ::Subsubsection:: *)
(*Basis:  \!\( *)
(*\*SubscriptBox[\(\[PartialD]\), \(z\)]\(( *)
(*\*FractionBox[*)
(*SqrtBox[\(1 + f[z]\)], *)
(*SqrtBox[\(a + b\ f[z]\)]] *)
(*\*SqrtBox[*)
(*FractionBox[\(a + b\ f[z]\), \(\((a + b)\)\ \((1 + f[z])\)\)]])\)\)=0*)


(* ::Subsubsection:: *)
(*Rule: If  a^2-b^2!=0, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral](Sqrt[a+b Sin[c+d x]]/(Sqrt[Sin[c+d x]] (A+A Sin[c+d x])))  \[LongRightArrow]  *)
(*(((a+b)Sqrt[1+ Sin[c+d x]])/(d A Sqrt[a+b Sin[c+d x]])) Sqrt[(a+b Sin[c+d x])/((a+b) (1+Sin[c+d x]))]EllipticE[ArcSin[Tan[(c+d x)/2-\[Pi]/4]],-((a-b)/(a+b))]*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[Sqrt[a_+b_.*sin[c_.+d_.*x_]]/(Sqrt[sin[c_.+d_.*x_]]*(A_+B_.*sin[c_.+d_.*x_])),x_Symbol] :=
  (a+b)*Sqrt[1+Sin[c+d*x]]/(d*A*Sqrt[a+b*Sin[c+d*x]])*Sqrt[(a+b*Sin[c+d*x])/((a+b)*(1+Sin[c+d*x]))]*
  EllipticE[ArcSin[Tan[(c-Pi/2+d*x)/2]],-Sim[(a-b)/(a+b)]] /;
FreeQ[{a,b,c,d,A,B},x] && ZeroQ[A-B] && NonzeroQ[a^2-b^2]


(* ::PageBreak:: *)
(**)


(* ::Subsubtitle::Bold::Closed:: *)
(*\[Integral]Sqrt[Sin[c+d x]]/(Sqrt[a+b Sin[c+d x]] (A+A Sin[c+d x])) \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Derivation: Algebraic expansion*)


(* ::Subsubsection:: *)
(*Basis:  Sqrt[z]/(Sqrt[a+b z](1+z))=a/((a-b)Sqrt[z] Sqrt[a+b z])-Sqrt[a+b z]/((a-b)Sqrt[z] (1+z))*)


(* ::Subsubsection:: *)
(*Rule: If  a^2-b^2!=0, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]Sqrt[Sin[c+d x]]/(Sqrt[a+b Sin[c+d x]] (A+A Sin[c+d x])) \[DifferentialD]x  \[LongRightArrow]  *)
(*(a/(A(a-b)))\[Integral]1/(Sqrt[Sin[c+d x]] Sqrt[a+b Sin[c+d x]]) \[DifferentialD]x-1/(a-b) \[Integral]Sqrt[a+b Sin[c+d x]]/(Sqrt[Sin[c+d x]] (A+A Sin[c+d x])) \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[Sqrt[sin[c_.+d_.*x_]]/(Sqrt[a_.+b_.*sin[c_.+d_.*x_]]*(A_+B_.*sin[c_.+d_.*x_])),x_Symbol] :=
  a/(A*(a-b))*Int[1/(Sqrt[sin[c+d*x]]*Sqrt[a+b*sin[c+d*x]]),x] - 
  1/(a-b)*Int[Sqrt[a+b*sin[c+d*x]]/(Sqrt[sin[c+d*x]]*(A+B*sin[c+d*x])),x] /;
FreeQ[{a,b,c,d,A,B},x] && ZeroQ[A-B] && NonzeroQ[a^2-b^2]


(* ::PageBreak:: *)
(**)


(* ::Subsubtitle::Bold::Closed:: *)
(*\[Integral](A+A Sin[c+d x])/(Sqrt[Sin[c+d x]] Sqrt[a+b Sin[c+d x]]) \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Derivation: Algebraic expansion*)


(* ::Subsubsection:: *)
(*Basis: If  b>0 \[And] b-a>0, then Sqrt[a+b z]=Sqrt[1+z] Sqrt[(a+b z)/(1+z)]*)


(* ::Subsubsection:: *)
(*Rule: If  b>0 \[And] b^2-a^2>0, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral](A+A Sin[c+d x])/(Sqrt[Sin[c+d x]] Sqrt[a+b Sin[c+d x]]) \[DifferentialD]x  \[LongRightArrow]  ((4A)/(d Sqrt[a+b]))EllipticPi[-1,ArcSin[Tan[(c+d x)/2-\[Pi]/4]],-((a-b)/(a+b))]*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[(A_+B_.*sin[c_.+d_.*x_])/(Sqrt[sin[c_.+d_.*x_]]*Sqrt[a_+b_.*sin[c_.+d_.*x_]]),x_Symbol] :=
  4*A/(d*Sqrt[a+b])*EllipticPi[-1,ArcSin[Tan[(c-Pi/2+d*x)/2]],-Sim[(a-b)/(a+b)]] /;
FreeQ[{a,b,c,d,A,B},x] && ZeroQ[A-B] && PositiveQ[b] && PositiveQ[b^2-a^2]


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Derivation: Piecewise constant extraction*)


(* ::Subsubsection:: *)
(*Basis:  \!\( *)
(*\*SubscriptBox[\(\[PartialD]\), \(z\)]\(( *)
(*\*FractionBox[*)
(*SqrtBox[\(1 + f[z]\)], *)
(*SqrtBox[\(a + b\ f[z]\)]] *)
(*\*SqrtBox[*)
(*FractionBox[\(a + b\ f[z]\), \(\((a + b)\)\ \((1 + f[z])\)\)]])\)\)=0*)


(* ::Subsubsection:: *)
(*Rule: If  a^2-b^2!=0, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]((A+A Sin[c+d x])/(Sqrt[Sin[c+d x]] Sqrt[a+b Sin[c+d x]]))  \[LongRightArrow]  *)
(*((4A Sqrt[1+Sin[c+d x]])/(d Sqrt[a+b Sin[c+d x]])) Sqrt[(a+b Sin[c+d x])/((a+b) (1+Sin[c+d x]))]EllipticPi[-1,ArcSin[Tan[(c+d x)/2-\[Pi]/4]],-((a-b)/(a+b))]*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[(A_+B_.*sin[c_.+d_.*x_])/(Sqrt[sin[c_.+d_.*x_]]*Sqrt[a_+b_.*sin[c_.+d_.*x_]]),x_Symbol] :=
  4*A*Sqrt[1+Sin[c+d*x]]/(d*Sqrt[a+b*Sin[c+d*x]])*
  Sqrt[(a+b*Sin[c+d*x])/((a+b)*(1+Sin[c+d*x]))]*
  EllipticPi[-1,ArcSin[Tan[(c-Pi/2+d*x)/2]],-Sim[(a-b)/(a+b)]] /;
FreeQ[{a,b,c,d,A,B},x] && ZeroQ[A-B] && NonzeroQ[a^2-b^2]


(* ::PageBreak:: *)
(**)


(* ::Subsubtitle::Bold::Closed:: *)
(*Rule r:  \[Integral](Sin[c+d x]^j)^m (b Sin[c+d x]^k)^n \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Derivation: Algebraic simplification*)


(* ::Subsubsection:: *)
(*Rule r1: If  k^2=1 \[And] m\[Element]\[DoubleStruckCapitalZ], then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]Sin[c+d x]^m (b Sin[c+d x]^k)^n \[DifferentialD]x  \[LongRightArrow]  (1/b^(k m))\[Integral](b Sin[c+d x]^k)^(k m+n) \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[sin[c_.+d_.*x_]^m_.*(b_.*sin[c_.+d_.*x_]^k_.)^n_.,x_Symbol] :=
  Dist[1/b^(k*m),Int[(b*sin[c+d*x]^k)^(k*m+n),x]] /;
FreeQ[{b,c,d,n},x] && OneQ[k^2] && IntegerQ[m]


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Derivation: Piecewise constant extraction*)


(* ::Subsubsection:: *)
(*Basis: If  j^2=1, then \!\( *)
(*\*SubscriptBox[\(\[PartialD]\), \(z\)]*)
(*\*FractionBox[*)
(*SqrtBox[\(b\ *)
(*\*SuperscriptBox[\(f[z]\), \(k\)]\)], *)
(*SuperscriptBox[\(( *)
(*\*SqrtBox[*)
(*SuperscriptBox[\(f[z]\), \(j\)]])\), \(j\ k\)]]\)=0*)


(* ::Subsubsection:: *)
(*Rule r2: If  j^2=k^2=1 \[And] m-1/2\[Element]\[DoubleStruckCapitalZ] \[And] n-1/2\[Element]\[DoubleStruckCapitalZ] \[And] n>0, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral](Sin[c+d x]^j)^m (b Sin[c+d x]^k)^n \[DifferentialD]x  \[LongRightArrow]  ((b^(n-1/2) Sqrt[b Sin[c+d x]^k])/(Sqrt[Sin[c+d x]^j])^(j k))\[Integral]Sin[c+d x]^(j m+k n) \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[(sin[c_.+d_.*x_]^j_.)^m_*(b_*sin[c_.+d_.*x_]^k_.)^n_,x_Symbol] :=
  Dist[b^(n-1/2)*Sqrt[b*Sin[c+d*x]^k]/(Sqrt[Sin[c+d*x]^j])^(j*k),Int[sin[c+d*x]^(j*m+k*n),x]] /;
FreeQ[{b,c,d},x] && OneQ[j^2,k^2] && IntegerQ[m-1/2] && IntegerQ[n-1/2] && n>0


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Derivation: Piecewise constant extraction*)


(* ::Subsubsection:: *)
(*Basis: If  j^2=1, then \!\( *)
(*\*SubscriptBox[\(\[PartialD]\), \(z\)]*)
(*\*FractionBox[*)
(*SuperscriptBox[\(( *)
(*\*SqrtBox[*)
(*SuperscriptBox[\(f[z]\), \(j\)]])\), \(j\ k\)], *)
(*SqrtBox[\(b\ *)
(*\*SuperscriptBox[\(f[z]\), \(k\)]\)]]\)=0*)


(* ::Subsubsection:: *)
(*Rule r3: If  j^2=k^2=1 \[And] m-1/2\[Element]\[DoubleStruckCapitalZ] \[And] n-1/2\[Element]\[DoubleStruckCapitalZ] \[And] n<0, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral](Sin[c+d x]^j)^m (b Sin[c+d x]^k)^n \[DifferentialD]x  \[LongRightArrow]  ((b^(n+1/2) (Sqrt[Sin[c+d x]^j])^(j k))/Sqrt[b Sin[c+d x]^k])\[Integral]Sin[c+d x]^(j m+k n) \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[(sin[c_.+d_.*x_]^j_.)^m_*(b_*sin[c_.+d_.*x_]^k_.)^n_,x_Symbol] :=
  Dist[b^(n+1/2)*(Sqrt[Sin[c+d*x]^j])^(j*k)/Sqrt[b*Sin[c+d*x]^k],Int[sin[c+d*x]^(j*m+k*n),x]] /;
FreeQ[{b,c,d},x] && OneQ[j^2,k^2] && IntegerQ[m-1/2] && IntegerQ[n-1/2] && n<0


(* ::PageBreak:: *)
(**)


(* ::Subsubtitle::Bold::Closed:: *)
(*Rule s:  \[Integral](Sin[c+d x]^j)^m (a+b Csc[c+d x])^n \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Derivation: Algebraic simplification*)


(* ::Subsubsection:: *)
(*Rule s1: If  j^2=1 \[And] a^2-b^2!=0 \[And] -(1/2)<=m+j<=3/2, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral](Sin[c+d x]^j)^m/(a+b Csc[c+d x]) \[DifferentialD]x  \[LongRightArrow]  \[Integral](Sin[c+d x]^j)^(m+j)/(b+a Sin[c+d x]) \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[(sin[c_.+d_.*x_]^j_.)^m_./(a_+b_.*sin[c_.+d_.*x_]^(-1)),x_Symbol] :=
  Int[(sin[c+d*x]^j)^(m+j)/(b+a*sin[c+d*x]),x] /;
FreeQ[{a,b,c,d},x] && OneQ[j^2] && NonzeroQ[a^2-b^2] && RationalQ[m] && -1/2<=m+j<=3/2


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Derivation: Piecewise constant extraction*)


(* ::Subsubsection:: *)
(*Basis: \!\( *)
(*\*SubscriptBox[\(\[PartialD]\), \(z\)]*)
(*\*FractionBox[*)
(*SqrtBox[\(b + a\ f[z]\)], \( *)
(*\*SqrtBox[\(f[z]\)] *)
(*\*SqrtBox[\(a + b/f[z]\)]\)]\)=0*)


(* ::Subsubsection:: *)
(*Rule s2: If  a^2-b^2!=0 \[And] m\[Element]\[DoubleStruckCapitalZ] \[And] n-1/2\[Element]\[DoubleStruckCapitalZ] \[And] ((m=1 \[And] -1<n<2) \[Or] (m=-1 \[And] -2<n<1) \[Or] (m=-2 \[And] -2<n<0)), then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]Sin[c+d x]^m (a+b Csc[c+d x])^n \[DifferentialD]x  \[LongRightArrow]  *)
(*( Sqrt[b+a Sin[c+d x]]/(Sqrt[Sin[c+d x]] Sqrt[a+b Csc[c+d x]]))\[Integral]Sin[c+d x]^(m-n) (b+a Sin[c+d x])^n \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[sin[c_.+d_.*x_]^m_.*(a_+b_.*sin[c_.+d_.*x_]^(-1))^n_,x_Symbol] :=
  Dist[Sqrt[b+a*Sin[c+d*x]]/(Sqrt[Sin[c+d*x]]*Sqrt[a+b*Csc[c+d*x]]),
    Int[sin[c+d*x]^(m-n)*(b+a*sin[c+d*x])^n,x]] /;
FreeQ[{a,b,c,d},x] && NonzeroQ[a^2-b^2] && IntegerQ[m] && IntegerQ[n-1/2] && 
  (m==1 && -1<n<2 || m==-1 && -2<n<1  || m==-2 && -2<n<0)


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Derivation: Piecewise constant extraction*)


(* ::Subsubsection:: *)
(*Basis: If  j^2=1, then  \!\( *)
(*\*SubscriptBox[\(\[PartialD]\), \(z\)]*)
(*\*FractionBox[*)
(*SqrtBox[\(b + a\ f[z]\)], \( *)
(*\*SuperscriptBox[\(( *)
(*\*SqrtBox[*)
(*SuperscriptBox[\(f[z]\), \(j\)]])\), \(j\)] *)
(*\*SqrtBox[\(a + b/f[z]\)]\)]\)=0*)


(* ::Subsubsection:: *)
(*Rule s3: If  j^2=1 \[And] a^2-b^2!=0 \[And] m-1/2\[Element]\[DoubleStruckCapitalZ] \[And] n-1/2\[Element]\[DoubleStruckCapitalZ] \[And] -1<=j m-n<=1, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral](Sin[c+d x]^j)^m (a+b Csc[c+d x])^n \[DifferentialD]x  \[LongRightArrow]  *)
(*( Sqrt[b+a Sin[c+d x]]/(Sqrt[Sin[c+d x]^j]^j Sqrt[a+b Csc[c+d x]]))\[Integral]Sin[c+d x]^(j m-n) (b+a Sin[c+d x])^n \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[(sin[c_.+d_.*x_]^j_.)^m_*(a_+b_.*sin[c_.+d_.*x_]^(-1))^n_,x_Symbol] :=
  Dist[Sqrt[b+a*Sin[c+d*x]]/((Sqrt[Sin[c+d*x]^j])^j*Sqrt[a+b*Csc[c+d*x]]),
    Int[sin[c+d*x]^(j*m-n)*(b+a*sin[c+d*x])^n,x]] /;
FreeQ[{a,b,c,d},x] && OneQ[j^2] && NonzeroQ[a^2-b^2] && IntegerQ[m-1/2] && IntegerQ[n-1/2] && 
  -1<n<2 && -1<=j*m-n<=1


(* ::PageBreak:: *)
(**)


(* ::Subsubtitle::Bold::Closed:: *)
(*Rule t:  \[Integral]Csc[c+d x]^(m/2) (a+b Sin[c+d x]^k)^n \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Derivation: Piecewise constant extraction*)


(* ::Subsubsection:: *)
(*Basis: \!\( *)
(*\*SubscriptBox[\(\[PartialD]\), \(z\)]\(( *)
(*\*SqrtBox[\(f[z]\)] *)
(*\*SqrtBox[\(1/f[z]\)])\)\)=0*)


(* ::Subsubsection:: *)
(*Rule t: If  k^2=1 \[And] a^2-b^2!=0 \[And] m-1/2\[Element]\[DoubleStruckCapitalZ] \[And] -1<=n<1, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]Csc[c+d x]^m (a+b Sin[c+d x]^k)^n \[DifferentialD]x  \[LongRightArrow]  Sqrt[Csc[c+d x]] Sqrt[Sin[c+d x]]\[Integral](a+b Sin[c+d x]^k)^n/Sin[c+d x]^m \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[(sin[c_.+d_.*x_]^(-1))^m_*(a_+b_.*sin[c_.+d_.*x_]^k_.)^n_,x_Symbol] :=
  Dist[Sqrt[Csc[c+d*x]]*Sqrt[Sin[c+d*x]],
    Int[(a+b*sin[c+d*x]^k)^n/sin[c+d*x]^m,x]] /;
FreeQ[{a,b,c,d},x] && OneQ[k^2] && NonzeroQ[a^2-b^2] && IntegerQ[m-1/2] && RationalQ[n] && 
  (k===1 || -1<m<1 && -1<=n<1)


(* ::PageBreak:: *)
(**)


(* ::Subsubtitle::Bold::Closed:: *)
(*Rules 11-12:  \[Integral](Sin[c+d x]^j)^m (a+b Sin[c+d x]^k)^2 \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Derivation: Rule 4a with n=2*)


(* ::Subsubsection:: *)
(*Rule 11: If  j^2=k^2=1 \[And] j k m+(k+1)/2!=0 \[And] j k m<=-1, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral](Sin[c+d x]^j)^m (a+b Sin[c+d x]^k)^2 \[DifferentialD]x  \[LongRightArrow]  ((a^2 Cos[c+d x] (Sin[c+d x]^j)^(m+j k))/(d(j k m+(k+1)/2)))+*)
(*1/(j k m+(k+1)/2) \[Integral](Sin[c+d x]^j)^(m+j k) (2a b (j k m+(k+1)/2)+(a^2+(a^2+b^2) (j k m+(k+1)/2)) Sin[c+d x]^k)\[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[(sin[c_.+d_.*x_]^j_.)^m_.*(a_+b_.*sin[c_.+d_.*x_]^k_.)^2,x_Symbol] :=
  a^2*Cos[c+d*x]*(Sin[c+d*x]^j)^(m+j*k)/(d*(j*k*m+(k+1)/2)) + 
  Dist[1/(j*k*m+(k+1)/2),
    Int[(sin[c+d*x]^j)^(m+j*k)*
      Sim[2*a*b*(j*k*m+(k+1)/2)+(a^2+(a^2+b^2)*(j*k*m+(k+1)/2))*sin[c+d*x]^k,x],x]] /;
FreeQ[{a,b,c,d},x] && OneQ[j^2,k^2] && RationalQ[m] && j*k*m+(k+1)/2!=0 && j*k*m<=-1


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Derivation: Rule 3a with n=2*)


(* ::Subsubsection:: *)
(*Rule 12: If  j^2=k^2=1 \[And] j k m+(k+3)/2!=0 \[And] j k m>=-1, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral](Sin[c+d x]^j)^m (a+b Sin[c+d x]^k)^2 \[DifferentialD]x  \[LongRightArrow]  -((b^2 Cos[c+d x](Sin[c+d x]^j)^(m+j k))/(d (j k m+(k+3)/2)))+*)
(*1/(j k m+(k+3)/2) \[Integral](Sin[c+d x]^j)^m (a^2+(a^2+b^2)(j k m+(k+1)/2)+2 a b (j k m+(k+3)/2) Sin[c+d x]^k)\[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[(sin[c_.+d_.*x_]^j_.)^m_.*(a_+b_.*sin[c_.+d_.*x_]^k_.)^2,x_Symbol] :=
  -b^2*Cos[c+d*x]*(Sin[c+d*x]^j)^(m+j*k)/(d*(j*k*m+(k+3)/2)) + 
  Dist[1/(j*k*m+(k+3)/2),
    Int[(sin[c+d*x]^j)^m*
      Sim[a^2+(a^2+b^2)*(j*k*m+(k+1)/2)+2*a*b*(j*k*m+(k+3)/2)*sin[c+d*x]^k,x],x]] /;
FreeQ[{a,b,c,d},x] && OneQ[j^2,k^2] && RationalQ[m] && j*k*m+(k+3)/2!=0 && j*k*m>=-1


(* ::PageBreak:: *)
(**)


(* ::Subsubtitle::Bold::Closed:: *)
(*Rules 9-10:  \[Integral]Sin[c+d x]^((k-1)/2) (a+b Sin[c+d x]^k)^n \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Reference: G&R 2.552.3*)


(* ::Subsubsection:: *)
(*Derivation: Rule 1c with j m=(k-1)/2*)


(* ::Subsubsection:: *)
(*Rule 9: If  k^2=1 \[And] a^2-b^2!=0 \[And] n<-1, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]Sin[c+d x]^((k-1)/2) (a+b Sin[c+d x]^k)^n \[DifferentialD]x  \[LongRightArrow]  -((b Cos[c+d x] Sin[c+d x]^((k-1)/2) (a+b Sin[c+d x]^k)^(n+1))/(d (n+1) (a^2-b^2)))+*)
(*1/((n+1)(a^2-b^2)) \[Integral]Sin[c+d x]^((k-1)/2) (a (n+1)-b (n+2) Sin[c+d x]^k)(a+b Sin[c+d x]^k)^(n+1) \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[(a_+b_.*sin[c_.+d_.*x_])^n_,x_Symbol] :=
  -b*Cos[c+d*x]*(a+b*Sin[c+d*x])^(n+1)/(d*(n+1)*(a^2-b^2)) + 
  Dist[1/((n+1)*(a^2-b^2)),Int[(a*(n+1)-b*(n+2)*sin[c+d*x])*(a+b*sin[c+d*x])^(n+1),x]] /;
FreeQ[{a,b,c,d},x] && NonzeroQ[a^2-b^2] && RationalQ[n] && n<-1


(* ::Code:: *)
Int[sin[c_.+d_.*x_]^(-1)*(a_+b_.*sin[c_.+d_.*x_]^(-1))^n_,x_Symbol] :=
  -b*Cot[c+d*x]*(a+b*Csc[c+d*x])^(n+1)/(d*(n+1)*(a^2-b^2)) + 
  Dist[1/((n+1)*(a^2-b^2)),Int[sin[c+d*x]^(-1)*(a*(n+1)-b*(n+2)*sin[c+d*x]^(-1))*(a+b*sin[c+d*x]^(-1))^(n+1),x]] /;
FreeQ[{a,b,c,d},x] && NonzeroQ[a^2-b^2] && RationalQ[n] && n<-1


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Reference: G&R 2.552.3 inverted*)


(* ::Subsubsection:: *)
(*Derivation: Rule 3b with j m=(k-1)/2*)


(* ::Subsubsection:: *)
(*Rule 10: If  k^2=1 \[And] a^2-b^2!=0 \[And] n>1, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]Sin[c+d x]^((k-1)/2) (a+b Sin[c+d x]^k)^n \[DifferentialD]x  \[LongRightArrow]  -((b Cos[c+d x]Sin[c+d x]^((k-1)/2) (a+b Sin[c+d x]^k)^(n-1))/(d n))+*)
(*1/n \[Integral](Sin[c+d x])^((k-1)/2) (a^2 n+b^2 (n-1)+a b(2 n-1)Sin[c+d x]^k)(a+b Sin[c+d x]^k)^(n-2) \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[(a_.+b_.*sin[c_.+d_.*x_])^n_,x_Symbol] :=
  -b*Cos[c+d*x]*(a+b*Sin[c+d*x])^(n-1)/(d*n) + 
  Dist[1/n,Int[Sim[a^2*n+b^2*(n-1)+a*b*(2*n-1)*sin[c+d*x],x]*(a+b*sin[c+d*x])^(n-2),x]] /;
FreeQ[{a,b,c,d},x] && NonzeroQ[a^2-b^2] && RationalQ[n] && n>1


(* ::Code:: *)
Int[sin[c_.+d_.*x_]^(-1)*(a_+b_.*sin[c_.+d_.*x_]^(-1))^n_,x_Symbol] :=
  -b*Cot[c+d*x]*(a+b*Csc[c+d*x])^(n-1)/(d*n) + 
  Dist[1/n,Int[sin[c+d*x]^(-1)*(a^2*n+b^2*(n-1)+a*b*(2*n-1)*sin[c+d*x]^(-1))*(a+b*sin[c+d*x]^(-1))^(n-2),x]] /;
FreeQ[{a,b,c,d},x] && NonzeroQ[a^2-b^2] && RationalQ[n] && n>1


(* ::PageBreak:: *)
(**)


(* ::Subsubtitle::Bold::Closed:: *)
(*Rules 13-14:  \[Integral]Sin[c+d x]^((3k-1)/2) (a+b Sin[c+d x]^k)^n \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Derivation: Rule 1b with j m=(3k-1)/2*)


(* ::Subsubsection:: *)
(*Rule 13: If  k^2=1 \[And] a^2-b^2!=0 \[And] n<-1, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]Sin[c+d x]^((3k-1)/2) (a+b Sin[c+d x]^k)^n \[DifferentialD]x  \[LongRightArrow]  *)
(*((a Cos[c+d x] Sin[c+d x]^((k-1)/2) (a+b Sin[c+d x]^k)^(n+1))/(d (n+1) (a^2-b^2)))-*)
(*1/((n+1)(a^2-b^2)) \[Integral]Sin[c+d x]^((k-1)/2) (b(n+1)-a(n+2)Sin[c+d x]^k)(a+b Sin[c+d x]^k)^(n+1) \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[sin[c_.+d_.*x_]^m_*(a_+b_.*sin[c_.+d_.*x_]^k_.)^n_,x_Symbol] :=
  a*Cos[c+d*x]*Sin[c+d*x]^((k-1)/2)*(a+b*Sin[c+d*x]^k)^(n+1)/(d*(n+1)*(a^2-b^2)) - 
  Dist[1/((n+1)*(a^2-b^2)),
    Int[Sin[c+d*x]^((k-1)/2)*(b*(n+1)-a*(n+2)*Sin[c+d*x]^k)*(a+b*Sin[c+d*x]^k)^(n+1),x]] /;
FreeQ[{a,b,c,d},x] && OneQ[k^2] && ZeroQ[m-(3*k-1)/2] && NonzeroQ[a^2-b^2] && RationalQ[n] && n<-1


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Derivation: Algebraic expansion*)


(* ::Subsubsection:: *)
(*Rule 14a: If  k^2=1 \[And] a^2-b^2!=0, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]Sin[c+d x]^((3k-1)/2)/(a+b Sin[c+d x]^k) \[DifferentialD]x  \[LongRightArrow]  (1/b)\[Integral]Sin[c+d x]^((k-1)/2) \[DifferentialD]x-a/b \[Integral]Sin[c+d x]^((k-1)/2)/(a+b Sin[c+d x]^k) \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[sin[c_.+d_.*x_]^m_/(a_+b_.*sin[c_.+d_.*x_]^k_.),x_Symbol] :=
  1/b*Int[Sin[c+d*x]^((k-1)/2),x] - 
  a/b*Int[Sin[c+d*x]^((k-1)/2)/(a+b*Sin[c+d*x]^k),x] /;
FreeQ[{a,b,c,d},x] && OneQ[k^2] && ZeroQ[m-(3*k-1)/2] && NonzeroQ[a^2-b^2]


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Derivation: Rule 2b with j m=(3k-1)/2*)


(* ::Subsubsection:: *)
(*Rule 14b: If  k^2=1 \[And] n>1, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]Sin[c+d x]^((3k-1)/2) (a+b Sin[c+d x]^k)^n \[DifferentialD]x  \[LongRightArrow]  *)
(*-((Cos[c+d x]Sin[c+d x]^((k-1)/2) (a+b Sin[c+d x]^k)^n)/(d (n+1)))+*)
(*n/(n+1) \[Integral]Sin[c+d x]^((k-1)/2) (b+a Sin[c+d x]^k)(a+b Sin[c+d x]^k)^(n-1) \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[sin[c_.+d_.*x_]^m_*(a_+b_.*sin[c_.+d_.*x_]^k_.)^n_,x_Symbol] :=
  -Cos[c+d*x]*Sin[c+d*x]^((k-1)/2)*(a+b*Sin[c+d*x]^k)^n/(d*(n+1)) + 
  Dist[n/(n+1),
    Int[Sin[c+d*x]^((k-1)/2)*(b+a*Sin[c+d*x]^k)*(a+b*Sin[c+d*x]^k)^(n-1),x]] /;
FreeQ[{a,b,c,d},x] && OneQ[k^2] && ZeroQ[m-(3*k-1)/2] && RationalQ[n] && n>-1


(* ::PageBreak:: *)
(**)


(* ::Subsubtitle::Bold::Closed:: *)
(*Rules 20-21:  \[Integral]Sin[c+d x]^((5k-1)/2) (a+b Sin[c+d x]^k)^n \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Derivation: Rule 1a with j m=(5k-1)/2*)


(* ::Subsubsection:: *)
(*Rule 20: If  k^2=1 \[And] a^2-b^2!=0 \[And] n<-1, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]Sin[c+d x]^((5k-1)/2) (a+b Sin[c+d x]^k)^n \[DifferentialD]x  \[LongRightArrow]  *)
(*-((a^2 Cos[c+d x] Sin[c+d x]^((k-1)/2) (a+b Sin[c+d x]^k)^(n+1))/(b d (n+1) (a^2-b^2)))+*)
(*1/(b(n+1)(a^2-b^2)) \[Integral]Sin[c+d x]^((k-1)/2) (a b(n+1)-(a^2+b^2 (n+1))Sin[c+d x]^k)(a+b Sin[c+d x]^k)^(n+1) \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[sin[c_.+d_.*x_]^m_*(a_+b_.*sin[c_.+d_.*x_]^k_.)^n_,x_Symbol] :=
  -a^2*Cos[c+d*x]*Sin[c+d*x]^((k-1)/2)*(a+b*Sin[c+d*x]^k)^(n+1)/(b*d*(n+1)*(a^2-b^2)) + 
  Dist[1/(b*(n+1)*(a^2-b^2)),
    Int[Sin[c+d*x]^((k-1)/2)*(a*b*(n+1)-(a^2+b^2*(n+1))*Sin[c+d*x]^k)*(a+b*Sin[c+d*x]^k)^(n+1),x]] /;
FreeQ[{a,b,c,d},x] && OneQ[k^2] && ZeroQ[m-(5*k-1)/2] && NonzeroQ[a^2-b^2] && RationalQ[n] && n<-1


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Derivation: Rule 21b with n=-1*)


(* ::Subsubsection:: *)
(*Rule 21a: If  k^2=1, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]Sin[c+d x]^((5k-1)/2)/(a+b Sin[c+d x]^k) \[DifferentialD]x  \[LongRightArrow]  -((Cos[c+d x]Sin[c+d x]^((k-1)/2))/(b d))-a/b \[Integral]Sin[c+d x]^((3k-1)/2)/(a+b Sin[c+d x]^k) \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[sin[c_.+d_.*x_]^m_/(a_+b_.*sin[c_.+d_.*x_]^k_.),x_Symbol] :=
  -Cos[c+d*x]*Sin[c+d*x]^((k-1)/2)/(b*d) - 
  Dist[a/b,Int[Sin[c+d*x]^((3*k-1)/2)/(a+b*Sin[c+d*x]^k),x]] /;
FreeQ[{a,b,c,d},x] && OneQ[k^2] && ZeroQ[m-(5*k-1)/2]


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Derivation: Rule 2a with j m=(5k-1)/2*)


(* ::Subsubsection:: *)
(*Rule 21b: If  k^2=1 \[And] n>1, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]Sin[c+d x]^((5k-1)/2) (a+b Sin[c+d x]^k)^n \[DifferentialD]x  \[LongRightArrow]  *)
(*-((Cos[c+d x]Sin[c+d x]^((k-1)/2) (a+b Sin[c+d x]^k)^(n+1))/(b d (n+2)))+*)
(*1/(b (n+2)) \[Integral]Sin[c+d x]^((k-1)/2) (b(n+1)-a Sin[c+d x]^k)(a+b Sin[c+d x]^k)^n \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[sin[c_.+d_.*x_]^m_*(a_+b_.*sin[c_.+d_.*x_]^k_.)^n_,x_Symbol] :=
  -Cos[c+d*x]*Sin[c+d*x]^((k-1)/2)*(a+b*Sin[c+d*x]^k)^(n+1)/(b*d*(n+2)) + 
  Dist[1/(b*(n+2)),
    Int[Sin[c+d*x]^((k-1)/2)*(b*(n+1)-a*Sin[c+d*x]^k)*(a+b*Sin[c+d*x]^k)^n,x]] /;
FreeQ[{a,b,c,d},x] && OneQ[k^2] && ZeroQ[m-(5*k-1)/2] && RationalQ[n] && n>-1


(* ::PageBreak:: *)
(**)


(* ::Subsubtitle::Bold::Closed:: *)
(*Rules 1-6:  \[Integral](Sin[c+d x]^j)^m (a+b Sin[c+d x]^k)^n \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Derivation: Recurrence 1 with A=0, B=0, C=1 and m=m-2*)


(* ::Subsubsection:: *)
(*Rule 1a: If  j^2=k^2=1 \[And] a^2-b^2!=0 \[And] j k m>2 \[And] n<-1, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral](Sin[c+d x]^j)^m (a+b Sin[c+d x]^k)^n \[DifferentialD]x  \[LongRightArrow]  *)
(*-((a^2 Cos[c+d x] (Sin[c+d x]^j)^(m-2j k) (a+b Sin[c+d x]^k)^(n+1))/(b d (n+1) (a^2-b^2)))+1/(b(n+1)(a^2-b^2))\[CenterDot]*)
(*\[Integral](Sin[c+d x]^j)^(m-3j k) (a^2 (j k m+(k-1)/2-2)+a b(n+1)Sin[c+d x]^k-(b^2 (n+1)+a^2 (j k m+(k-1)/2-1))Sin[c+d x]^(2k))(a+b Sin[c+d x]^k)^(n+1) \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[(sin[c_.+d_.*x_]^j_.)^m_.*(a_+b_.*sin[c_.+d_.*x_]^k_.)^n_,x_Symbol] :=
  -a^2*Cos[c+d*x]*(Sin[c+d*x]^j)^(m-2*j*k)*(a+b*Sin[c+d*x]^k)^(n+1)/(b*d*(n+1)*(a^2-b^2)) + 
  Dist[1/(b*(n+1)*(a^2-b^2)),
    Int[(sin[c+d*x]^j)^(m-3*j*k)*
      Sim[a^2*(j*k*m+(k-1)/2-2)+a*b*(n+1)*sin[c+d*x]^k-
        (b^2*(n+1)+a^2*(j*k*m+(k-1)/2-1))*sin[c+d*x]^(2*k),x]*
      (a+b*sin[c+d*x]^k)^(n+1),x]] /;
FreeQ[{a,b,c,d},x] && OneQ[j^2,k^2] && NonzeroQ[a^2-b^2] && RationalQ[m,n] && j*k*m>2 && n<-1


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Derivation: Recurrence 1 with A=0, B=1, C=0 and m=m-1*)


(* ::Subsubsection:: *)
(*Derivation: Recurrence 6 with A=0, B=0, C=1 and m=m-2*)


(* ::Subsubsection:: *)
(*Rule 1b: If  j^2=k^2=1 \[And] a^2-b^2!=0 \[And] 1<j k m<2 \[And] n<-1, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral](Sin[c+d x]^j)^m (a+b Sin[c+d x]^k)^n \[DifferentialD]x  \[LongRightArrow]  *)
(*((a Cos[c+d x] (Sin[c+d x]^j)^(m-j k) (a+b Sin[c+d x]^k)^(n+1))/(d (n+1) (a^2-b^2)))-1/((n+1)(a^2-b^2))\[CenterDot]*)
(*\[Integral](Sin[c+d x]^j)^(m-2j k) (a(j k m+(k-1)/2-1)+b(n+1)Sin[c+d x]^k-a(j k m+n+(k+1)/2)Sin[c+d x]^(2k))(a+b Sin[c+d x]^k)^(n+1) \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[(sin[c_.+d_.*x_]^j_.)^m_*(a_+b_.*sin[c_.+d_.*x_]^k_.)^n_,x_Symbol] :=
  a*Cos[c+d*x]*(Sin[c+d*x]^j)^(m-j*k)*(a+b*Sin[c+d*x]^k)^(n+1)/(d*(n+1)*(a^2-b^2)) - 
  Dist[1/((n+1)*(a^2-b^2)),
    Int[(sin[c+d*x]^j)^(m-2*j*k)*
      Sim[a*(j*k*m+(k-1)/2-1)+b*(n+1)*sin[c+d*x]^k-a*(j*k*m+n+(k+1)/2)*sin[c+d*x]^(2*k),x]*
      (a+b*sin[c+d*x]^k)^(n+1),x]] /;
FreeQ[{a,b,c,d},x] && OneQ[j^2,k^2] && NonzeroQ[a^2-b^2] && RationalQ[m,n] && 
  1<j*k*m<2 && n<-1


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Derivation: Recurrence 1 with A=1, B=0 and C=0*)


(* ::Subsubsection:: *)
(*Derivation: Recurrence 6 with A=0, B=1, C=0 and m=m-1*)


(* ::Subsubsection:: *)
(*Rule 1c: If  j^2=k^2=1 \[And] a^2-b^2!=0 \[And] 0<j k m<1 \[And] n<-1, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral](Sin[c+d x]^j)^m (a+b Sin[c+d x]^k)^n \[DifferentialD]x  \[LongRightArrow]  *)
(*-((b Cos[c+d x] (Sin[c+d x]^j)^m (a+b Sin[c+d x]^k)^(n+1))/(d (n+1) (a^2-b^2)))+1/((n+1)(a^2-b^2))\[CenterDot]*)
(*\[Integral](Sin[c+d x]^j)^(m-j k) (b(j k m+(k-1)/2)+a(n+1)Sin[c+d x]^k-b(j k m+n+(k+1)/2+1)Sin[c+d x]^(2k))(a+b Sin[c+d x]^k)^(n+1) \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[(sin[c_.+d_.*x_]^j_.)^m_.*(a_+b_.*sin[c_.+d_.*x_]^k_.)^n_,x_Symbol] :=
  -b*Cos[c+d*x]*(Sin[c+d*x]^j)^m*(a+b*Sin[c+d*x]^k)^(n+1)/(d*(n+1)*(a^2-b^2)) + 
  Dist[1/((n+1)*(a^2-b^2)),
    Int[(sin[c+d*x]^j)^(m-j*k)*
      Sim[b*(j*k*m+(k-1)/2)+a*(n+1)*sin[c+d*x]^k-b*(j*k*m+n+(k+1)/2+1)*sin[c+d*x]^(2*k),x]*
      (a+b*sin[c+d*x]^k)^(n+1),x]] /;
FreeQ[{a,b,c,d},x] && OneQ[j^2,k^2] && NonzeroQ[a^2-b^2] && RationalQ[m,n] && 
  0<j*k*m<1 && n<-1


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Derivation: Recurrence 2 with A=0, B=0, C=1 and m=m-2*)


(* ::Subsubsection:: *)
(*Rule 2a: If  j^2=k^2=1 \[And] a^2-b^2!=0 \[And] j k m>2 \[And] -1<=n<0, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral](Sin[c+d x]^j)^m (a+b Sin[c+d x]^k)^n \[DifferentialD]x  \[LongRightArrow]  *)
(*-((Cos[c+d x](Sin[c+d x]^j)^(m-2j k) (a+b Sin[c+d x]^k)^(n+1))/(b d (j k m+n+(k-1)/2)))+1/(b (j k m+n+(k-1)/2))\[CenterDot]*)
(*\[Integral](Sin[c+d x]^j)^(m-3j k) (a(j k m+(k-1)/2-2)+b(j k m+n+(k-1)/2-1)Sin[c+d x]^k-a(j k m+(k-1)/2-1)Sin[c+d x]^(2k))(a+b Sin[c+d x]^k)^n \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[(sin[c_.+d_.*x_]^j_.)^m_*(a_.+b_.*sin[c_.+d_.*x_]^k_.)^n_,x_Symbol] :=
  -Cos[c+d*x]*(Sin[c+d*x]^j)^(m-2*j*k)*(a+b*Sin[c+d*x]^k)^(n+1)/(b*d*(j*k*m+n+(k-1)/2)) + 
  Dist[1/(b*(j*k*m+n+(k-1)/2)),
    Int[(sin[c+d*x]^j)^(m-3*j*k)*
      Sim[a*(j*k*m+(k-1)/2-2)+b*(j*k*m+n+(k-1)/2-1)*sin[c+d*x]^k-
        a*(j*k*m+(k-1)/2-1)*sin[c+d*x]^(2*k),x]*
      (a+b*sin[c+d*x]^k)^n,x]] /;
FreeQ[{a,b,c,d},x] && OneQ[j^2,k^2] && NonzeroQ[a^2-b^2] && RationalQ[m,n] && j*k*m>2 && -1<=n<0


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Derivation: Recurrence 2 with A=0, B=a, C=b, m=m-1 and n=n-1*)


(* ::Subsubsection:: *)
(*Derivation: Recurrence 3 with A=0, B=0, C=1 and m=m-2*)


(* ::Subsubsection:: *)
(*Rule 2b: If  j^2=k^2=1 \[And] a^2-b^2!=0 \[And] j k m>1 \[And] j k m!=2 \[And] 0<n<1, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral](Sin[c+d x]^j)^m (a+b Sin[c+d x]^k)^n \[DifferentialD]x  \[LongRightArrow]  *)
(*-((Cos[c+d x](Sin[c+d x]^j)^(m-j k) (a+b Sin[c+d x]^k)^n)/(d (j k m+n+(k-1)/2)))+1/(j k m+n+(k-1)/2)\[CenterDot]*)
(* \[Integral](Sin[c+d x]^j)^(m-2j k) (a (j k m+(k-1)/2-1)+b(j k m+n+(k-1)/2-1)Sin[c+d x]^k+a n Sin[c+d x]^(2k))(a+b Sin[c+d x]^k)^(n-1) \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[(sin[c_.+d_.*x_]^j_.)^m_*(a_.+b_.*sin[c_.+d_.*x_]^k_.)^n_,x_Symbol] :=
  -Cos[c+d*x]*(Sin[c+d*x]^j)^(m-j*k)*(a+b*Sin[c+d*x]^k)^n/(d*(j*k*m+n+(k-1)/2)) + 
  Dist[1/(j*k*m+n+(k-1)/2),
    Int[(sin[c+d*x]^j)^(m-2*j*k)*
      Sim[a*(j*k*m+(k-1)/2-1)+b*(j*k*m+n+(k-1)/2-1)*sin[c+d*x]^k+a*n*sin[c+d*x]^(2*k),x]*
      (a+b*sin[c+d*x]^k)^(n-1),x]] /;
FreeQ[{a,b,c,d},x] && OneQ[j^2,k^2] && NonzeroQ[a^2-b^2] && RationalQ[m,n] && 
  j*k*m>1 && j*k*m!=2 && 0<n<1


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Derivation: Recurrence 3 with A=a^2, B=2a b, C=b^2 and n=n-2*)


(* ::Subsubsection:: *)
(*Rule 3a: If  j^2=k^2=1 \[And] a^2-b^2!=0 \[And] j k m>=-1 \[And] j k m!=1 \[And] j k m!=2 \[And] n>2, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral](Sin[c+d x]^j)^m (a+b Sin[c+d x]^k)^n \[DifferentialD]x  \[LongRightArrow]  *)
(*-((b^2 Cos[c+d x](Sin[c+d x]^j)^(m+j k) (a+b Sin[c+d x]^k)^(n-2))/(d (j k m+n+(k-1)/2)))+1/(j k m+n+(k-1)/2)\[CenterDot]*)
(* \[Integral](Sin[c+d x]^j)^m (a (a^2 (n-1)+(a^2+b^2)(j k m+(k+1)/2))+b(-b^2+(3a^2+b^2)(j k m+n+(k-1)/2))Sin[c+d x]^k+a b^2 (2j k m+3 n+k-3)Sin[c+d x]^(2k))(a+b Sin[c+d x]^k)^(n-3) \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[(sin[c_.+d_.*x_]^j_.)^m_.*(a_.+b_.*sin[c_.+d_.*x_]^k_.)^n_,x_Symbol] :=
  -b^2*Cos[c+d*x]*(Sin[c+d*x]^j)^(m+j*k)*(a+b*Sin[c+d*x]^k)^(n-2)/(d*(j*k*m+n+(k-1)/2)) + 
  Dist[1/(j*k*m+n+(k-1)/2),
   Int[(sin[c+d*x]^j)^m*
    Sim[a*(a^2*(n-1)+(a^2+b^2)*(j*k*m+(k+1)/2))+b*(-b^2+(3*a^2+b^2)*(j*k*m+n+(k-1)/2))*sin[c+d*x]^k+
      a*b^2*(2*j*k*m+3*n+k-3)*sin[c+d*x]^(2*k),x]*
    (a+b*sin[c+d*x]^k)^(n-3),x]] /;
FreeQ[{a,b,c,d},x] && OneQ[j^2,k^2] && NonzeroQ[a^2-b^2] && RationalQ[m,n] && 
  j*k*m>=-1 && j*k*m!=1 && j*k*m!=2 && n>2


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Derivation: Recurrence 3 with A=0, B=a, C=b, m=m-1 and n=n-1*)


(* ::Subsubsection:: *)
(*Rule 3b: If  j^2=k^2=1 \[And] a^2-b^2!=0 \[And] j k m>0 \[And] j k m!=1 \[And] j k m!=2 \[And] 1<n<2, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral](Sin[c+d x]^j)^m (a+b Sin[c+d x]^k)^n \[DifferentialD]x  \[LongRightArrow]  *)
(*-((b Cos[c+d x](Sin[c+d x]^j)^m (a+b Sin[c+d x]^k)^(n-1))/(d (j k m+n+(k-1)/2)))+1/(j k m+n+(k-1)/2)\[CenterDot]*)
(* \[Integral](Sin[c+d x]^j)^(m-j k) (a b(j k m+(k-1)/2)+((a^2+b^2)(j k m+n+(k-1)/2)-b^2)Sin[c+d x]^k+a b(j k m+2n+(k-1)/2-1)Sin[c+d x]^(2k))(a+b Sin[c+d x]^k)^(n-2) \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[(sin[c_.+d_.*x_]^j_.)^m_.*(a_.+b_.*sin[c_.+d_.*x_]^k_.)^n_,x_Symbol] :=
  -b*Cos[c+d*x]*(Sin[c+d*x]^j)^m*(a+b*Sin[c+d*x]^k)^(n-1)/(d*(j*k*m+n+(k-1)/2)) + 
  Dist[1/(j*k*m+n+(k-1)/2),
    Int[(sin[c+d*x]^j)^(m-j*k)*
      Sim[a*b*(j*k*m+(k-1)/2)+((a^2+b^2)*(j*k*m+n+(k-1)/2)-b^2)*sin[c+d*x]^k+
        a*b*(j*k*m+2*n+(k-1)/2-1)*sin[c+d*x]^(2*k),x]*
      (a+b*sin[c+d*x]^k)^(n-2),x]] /;
FreeQ[{a,b,c,d},x] && OneQ[j^2,k^2] && NonzeroQ[a^2-b^2] && RationalQ[m,n] && 
  j*k*m>0 && j*k*m!=1 && j*k*m!=2 && 1<n<2


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Derivation: Recurrence 4 with A=a^2, B=2a b, C=b^2 and n=n-2*)


(* ::Subsubsection:: *)
(*Rule 4a: If  j^2=k^2=1 \[And] a^2-b^2!=0 \[And] j k m<-1 \[And] n>2, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral](Sin[c+d x]^j)^m (a+b Sin[c+d x]^k)^n \[DifferentialD]x  \[LongRightArrow]  *)
(*((a^2 Cos[c+d x] (Sin[c+d x]^j)^(m+j k) (a+b Sin[c+d x]^k)^(n-2))/(d(j k m+(k+1)/2)))+1/(j k m+(k+1)/2)\[CenterDot]*)
(*\[Integral](Sin[c+d x]^j)^(m+j k) (a^2 b(2j k m-n+k+3)+a(a^2+(a^2+3b^2) (j k m+(k+1)/2)) Sin[c+d x]^k+b(a^2 (n-1)+(a^2+b^2)(j k m+(k+1)/2))Sin[c+d x]^(2k))(a+b Sin[c+d x]^k)^(n-3) \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[(sin[c_.+d_.*x_]^j_.)^m_.*(a_+b_.*sin[c_.+d_.*x_]^k_.)^n_,x_Symbol] :=
  a^2*Cos[c+d*x]*(Sin[c+d*x]^j)^(m+j*k)*(a+b*Sin[c+d*x]^k)^(n-2)/(d*(j*k*m+(k+1)/2)) + 
  Dist[1/(j*k*m+(k+1)/2),
    Int[(sin[c+d*x]^j)^(m+j*k)*
      Sim[a^2*b*(2*j*k*m-n+k+3)+a*(a^2+(a^2+3*b^2)*(j*k*m+(k+1)/2))*sin[c+d*x]^k+
        b*(a^2*(n-1)+(a^2+b^2)*(j*k*m+(k+1)/2))*sin[c+d*x]^(2*k),x]*
      (a+b*sin[c+d*x]^k)^(n-3),x]] /;
FreeQ[{a,b,c,d},x] && OneQ[j^2,k^2] && NonzeroQ[a^2-b^2] && RationalQ[m,n] && 
  j*k*m<-1 && n>2


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Derivation: Recurrence 4 with A=a, B=b, C=0 and n=n-1*)


(* ::Subsubsection:: *)
(*Rule 4b: If  j^2=k^2=1 \[And] a^2-b^2!=0 \[And] j k m<-1 \[And] 1<n<2, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral](Sin[c+d x]^j)^m (a+b Sin[c+d x]^k)^n \[DifferentialD]x  \[LongRightArrow]  *)
(*((a Cos[c+d x] (Sin[c+d x]^j)^(m+j k) (a+b Sin[c+d x]^k)^(n-1))/(d(j k m+(k+1)/2)))+1/(j k m+(k+1)/2)\[CenterDot]*)
(*\[Integral](Sin[c+d x]^j)^(m+j k) (a b(j k m-n+(k+1)/2+1)+(a^2+(a^2+b^2) (j k m+(k+1)/2)) Sin[c+d x]^k+a b(j k m+n+(k+1)/2)Sin[c+d x]^(2k))(a+b Sin[c+d x]^k)^(n-2) \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[(sin[c_.+d_.*x_]^j_.)^m_.*(a_+b_.*sin[c_.+d_.*x_]^k_.)^n_,x_Symbol] :=
  a*Cos[c+d*x]*(Sin[c+d*x]^j)^(m+j*k)*(a+b*Sin[c+d*x]^k)^(n-1)/(d*(j*k*m+(k+1)/2)) + 
  Dist[1/(j*k*m+(k+1)/2),
    Int[(sin[c+d*x]^j)^(m+j*k)*
      Sim[a*b*(j*k*m-n+(k+1)/2+1)+(a^2+(a^2+b^2)*(j*k*m+(k+1)/2))*sin[c+d*x]^k+
        a*b*(j*k*m+n+(k+1)/2)*sin[c+d*x]^(2*k),x]*
      (a+b*sin[c+d*x]^k)^(n-2),x]] /;
FreeQ[{a,b,c,d},x] && OneQ[j^2,k^2] && NonzeroQ[a^2-b^2] && RationalQ[m,n] && 
  j*k*m<-1 && 1<n<2


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Derivation: Recurrence 4 with A=1, B=0 and C=0*)


(* ::Subsubsection:: *)
(*Derivation: Recurrence 5 with A=a, B=b, C=0 and n=n-1*)


(* ::Subsubsection:: *)
(*Rule 5a: If  j^2=k^2=1 \[And] a^2-b^2!=0 \[And] j k m+(k+1)/2!=0 \[And] j k m<=-1 \[And] 0<n<1, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral](Sin[c+d x]^j)^m (a+b Sin[c+d x]^k)^n \[DifferentialD]x  \[LongRightArrow]  *)
(*((Cos[c+d x] (Sin[c+d x]^j)^(m+j k) (a+b Sin[c+d x]^k)^n)/(d(j k m+(k+1)/2)))+1/(j k m+(k+1)/2)\[CenterDot]*)
(*\[Integral](Sin[c+d x]^j)^(m+j k) (-b n+a(j k m+(k+1)/2+1) Sin[c+d x]^k+b(j k m+n+(k+1)/2+1)Sin[c+d x]^(2k))(a+b Sin[c+d x]^k)^(n-1) \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[(sin[c_.+d_.*x_]^j_.)^m_.*(a_.+b_.*sin[c_.+d_.*x_]^k_.)^n_,x_Symbol] :=
  Cos[c+d*x]*(Sin[c+d*x]^j)^(m+j*k)*(a+b*Sin[c+d*x]^k)^n/(d*(j*k*m+(k+1)/2)) + 
  Dist[1/(j*k*m+(k+1)/2),
    Int[(sin[c+d*x]^j)^(m+j*k)*
      Sim[-b*n+a*(j*k*m+(k+1)/2+1)*sin[c+d*x]^k+b*(j*k*m+n+(k+1)/2+1)*sin[c+d*x]^(2*k),x]*
      (a+b*sin[c+d*x]^k)^(n-1),x]] /;
FreeQ[{a,b,c,d},x] && OneQ[j^2,k^2] && NonzeroQ[a^2-b^2] && RationalQ[m,n] && 
  j*k*m+(k+1)/2!=0 && j*k*m<=-1 && 0<n<1


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Derivation: Recurrence 5 with A=1, B=0 and C=0*)


(* ::Subsubsection:: *)
(*Rule 5b: If  j^2=k^2=1 \[And] a^2-b^2!=0 \[And] j k m+(k+1)/2!=0 \[And] j k m<=-1 \[And] -1<=n<0, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral](Sin[c+d x]^j)^m (a+b Sin[c+d x]^k)^n \[DifferentialD]x  \[LongRightArrow]  *)
(*((Cos[c+d x](Sin[c+d x]^j)^(m+j k) (a+b Sin[c+d x]^k)^(n+1))/(a d(j k m+(k+1)/2)))+1/(a (j k m+(k+1)/2))\[CenterDot]*)
(*\[Integral](Sin[c+d x]^j)^(m+j k) (-b(j k m+n+(k+1)/2+1)+a(j k m+(k+1)/2+1)Sin[c+d x]^k+b(j k m+n+(k+1)/2+2)Sin[c+d x]^(2k) )(a+b Sin[c+d x]^k)^n \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[(sin[c_.+d_.*x_]^j_.)^m_.*(a_+b_.*sin[c_.+d_.*x_]^k_.)^n_,x_Symbol] :=
  Cos[c+d*x]*(Sin[c+d*x]^j)^(m+j*k)*(a+b*Sin[c+d*x]^k)^(n+1)/(a*d*(j*k*m+(k+1)/2)) + 
  Dist[1/(a*(j*k*m+(k+1)/2)),
    Int[(sin[c+d*x]^j)^(m+j*k)*
      Sim[-b*(j*k*m+n+(k+1)/2+1)+a*(j*k*m+(k+1)/2+1)*sin[c+d*x]^k+
        b*(j*k*m+n+(k+1)/2+2)*sin[c+d*x]^(2*k),x]*
      (a+b*sin[c+d*x]^k)^n,x]] /;
FreeQ[{a,b,c,d},x] && OneQ[j^2,k^2] && NonzeroQ[a^2-b^2] && RationalQ[m,n] && 
  j*k*m+(k+1)/2!=0 && j*k*m<=-1 && -1<=n<0


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Derivation: Recurrence 6 with A=1, B=0 and C=0*)


(* ::Subsubsection:: *)
(*Rule 6: If  j^2=k^2=1 \[And] a^2-b^2!=0 \[And] j k m<0 \[And] n<-1, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral](Sin[c+d x]^j)^m (a+b Sin[c+d x]^k)^n \[DifferentialD]x  \[LongRightArrow]  *)
(*((b^2 Cos[c+d x](Sin[c+d x]^j)^(m+j k) (a+b Sin[c+d x]^k)^(n+1))/(a d (n+1) (a^2-b^2)))+1/(a (n+1) (a^2-b^2))\[CenterDot]*)
(* \[Integral](Sin[c+d x]^j)^m ((a^2-b^2) (n+1)-b^2 (j k m+(k+1)/2)-a b(n+1)Sin[c+d x]^k+b^2 (j k m+n+(k+1)/2+2)Sin[c+d x]^(2k))(a+b Sin[c+d x]^k)^(n+1) \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[(sin[c_.+d_.*x_]^j_.)^m_.*(a_+b_.*sin[c_.+d_.*x_]^k_.)^n_,x_Symbol] :=
  b^2*Cos[c+d*x]*(Sin[c+d*x]^j)^(m+j*k)*(a+b*Sin[c+d*x]^k)^(n+1)/(a*d*(n+1)*(a^2-b^2)) + 
  Dist[1/(a*(n+1)*(a^2-b^2)),
    Int[(sin[c+d*x]^j)^m*
      Sim[(a^2-b^2)*(n+1)-b^2*(j*k*m+(k+1)/2)-a*b*(n+1)*sin[c+d*x]^k+
        b^2*(j*k*m+n+(k+1)/2+2)*sin[c+d*x]^(2*k),x]*
      (a+b*sin[c+d*x]^k)^(n+1),x]] /;
FreeQ[{a,b,c,d},x] && OneQ[j^2,k^2] && NonzeroQ[a^2-b^2] && RationalQ[m,n] && 
  j*k*m<0 && n<-1


(* ::PageBreak:: *)
(**)
