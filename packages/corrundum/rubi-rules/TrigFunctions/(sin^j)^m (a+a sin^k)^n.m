(* ::Package:: *)

(* ::Title::Plain:: *)
(* Integration Rules for *)
(*\[Integral](sin^j(z))^m (a+b sin^k(z))^n \[DifferentialD]z when j^2=1\[And]k^2=1\[And]a^2=b^2*)


(* ::Subsubtitle::Bold::Closed:: *)
(*Domain Map *)


(* ::Input:: *)
(*Graphics[{{RGBColor[1, 0, 0], Rectangle[{-4, 1}, {-1, 4}]}, {GrayLevel[0], Inset[Style["Rule 1a \[LowerRightArrow]\[DownArrow]\[Diamond]", FontSize -> 10], {Rational[-5, 2], 3}]}, {GrayLevel[0], Thickness[0.007], Dashing[{0.003, 0.02}], Line[{{-1.02, 3.98}, {-1.02, 1.02}}], {RGBColor[1., 0.5, 0.5], Dashing[{}], Rectangle[{-4, 0}, {-1, 1}], {GrayLevel[0], Inset[Style["Rule 1b \[LowerRightArrow]\[Diamond]", FontSize -> 10], {-3.25, 0.5}]}, {GrayLevel[0], Thickness[0.007], Dashing[{0.003, 0.02}], Line[{{-1.02, 1}, {-1.02, 0}}], {RGBColor[0.7, 0.7, 1.], Dashing[{}], Rectangle[{-1, 1}, {0, 4}], {GrayLevel[0], Inset[Style["Rule 2\[DownArrow]\[DownArrow]\[Diamond]", FontSize -> 10], {Rational[-1, 2], 3}]}, {GrayLevel[1], Thickness[Large], Line[{{0, 1}, {Rational[1, 2], Rational[3, 2]}}], {RGBColor[0.2, 1., 0.2], Rectangle[{1, -1}, {4, 4}]}, {GrayLevel[0], Inset[Style["Rule 3a \[LeftArrow]\[LeftArrow]\[Diamond]", FontSize -> 10], {3, 3}]}, {GrayLevel[0], Thickness[0.007], Dashing[{0.003, 0.02}], Line[{{1.02, -0.98}, {3.98, -0.98}}], {RGBColor[0.7, 1., 0.7], Dashing[{}], Rectangle[{0, 0}, {1, 4}], {GrayLevel[0], Inset[Style["Rule 3b\n\[LowerLeftArrow]  \[Diamond]", FontSize -> 10], {Rational[1, 2], 3}]}, {RGBColor[1, 0.5, 0.5], Rectangle[{1, -1}, {4, -4}]}, {GrayLevel[0], Inset[Style["Rule 4a \[UpperLeftArrow]\[LeftArrow]\[Diamond]", FontSize -> 10], {3, Rational[-5, 2]}]}, {RGBColor[1., 0.8, 0.8], Rectangle[{0, -4}, {1, -1}]}, {GrayLevel[0], Inset[Style["Rule 4b  \n\[UpperLeftArrow]  \[Diamond]", FontSize -> 10], {Rational[1, 2], -2.1}]}, {RGBColor[1, 0, 1], Rectangle[{-1, -4}, {0, -1}]}, {GrayLevel[0], Inset[Style["Rule 5 \[UpArrow]\[Diamond]", FontSize -> 10], {Rational[-1, 2], Rational[-5, 2]}]}, {RGBColor[1, 0.5, 0], Rectangle[{-4, -4}, {-1, 0}]}, {GrayLevel[0], Inset[Style["Rule 6 \[RightArrow]\[Diamond]", FontSize -> 10], {Rational[-5, 2], -2}]}, {GrayLevel[0], Thickness[0.007], Dashing[{0.003, 0.02}], Line[{{-1.02, 0}, {-1.02, -3.98}}]}, {RGBColor[0, 1, 0], Thickness[Large], Dashing[{}], Line[{{-3.98, 0}, {-1, 0}}], {GrayLevel[0], Inset[Style["Rule 7 \[RightArrow]", FontSize -> 10], {-3, 0.13}]}, {RGBColor[1, 0, 0], Thickness[Large], Line[{{1, 0}, {3.98, 0}}], {GrayLevel[0], Inset[Style["Rule 8 \[LeftArrow]", FontSize -> 10], {3, 0.13}]}, {RGBColor[0, 1, 0], Thickness[Large], Line[{{Rational[1, 2], -1.02}, {Rational[1, 2], -3.98}}], {GrayLevel[0], GeometricTransformation[Inset[Style["Rule 9 \[LeftArrow]", FontSize -> 10], {0.65, -3.4}], {{{0, 1}, {-1, 0}}, Center}]}, {RGBColor[1, 0.5, 0], Thickness[Large], Line[{{Rational[1, 2], 3.98}, {Rational[1, 2], 0.02}}], {GrayLevel[0], GeometricTransformation[Inset[Style["Rule  10\[RightArrow]", FontSize -> 10], {0.65, 2}], {{{0, 1}, {-1, 0}}, Center}]}, {RGBColor[1, 1, 0], Thickness[Large], Line[{{0, -1}, {3, -4}}], {GrayLevel[0], GeometricTransformation[Inset[Style["Rule 11 \[LeftArrow]", FontSize -> 10], {2.6, -3.4}], {{{0.7071067811865475, 0.7071067811865475}, {-0.7071067811865475, 0.7071067811865475}}, Center}]}, {RGBColor[0, 0, 1], Thickness[Large], Line[{{-3.98, 2.98}, {-1.02, 0.02}}], {GrayLevel[0], GeometricTransformation[Inset[Style["Rule 12 \[RightArrow]", FontSize -> 10], {-2.3, 1.5}], {{{0.7071067811865475, 0.7071067811865475}, {-0.7071067811865475, 0.7071067811865475}}, Center}]}, {RGBColor[1, 1, 0], Thickness[Large], Line[{{-1, -1}, {2, -4}}], {GrayLevel[0], GeometricTransformation[Inset[Style["Rule 13 \[UpperLeftArrow]", FontSize -> 10], {1.6, -3.4}], {{{0.7071067811865475, 0.7071067811865475}, {-0.7071067811865475, 0.7071067811865475}}, Center}]}, {RGBColor[0, 0, 1], Thickness[Large], Line[{{-3.98, 1.98}, {-1.02, -0.98}}], {GrayLevel[0], GeometricTransformation[Inset[Style["Rule 14 \[UpperRightArrow]", FontSize -> 10], {-3.35, 1.55}], {{{0.7071067811865475, 0.7071067811865475}, {-0.7071067811865475, 0.7071067811865475}}, Center}]}, {GrayLevel[0], Thickness[Large], Line[{{0, 3.98}, {0, -3.98}}]}, {GrayLevel[0], Thickness[Large], Line[{{1, 3.98}, {1, -3.98}}]}, {GrayLevel[0], Thickness[Large], Line[{{2, 3.98}, {2, -3.98}}]}, {GrayLevel[0], Thickness[Large], Line[{{-3.98, 1}, {3.98, 1}}]}, {GrayLevel[0], Thickness[Large], Line[{{-3.98, 2}, {3.98, 2}}], {RGBColor[1., 0.3, 0.3], Disk[{-1, 0}, Scaled[Rational[1, 60]]]}, {GrayLevel[1], Inset["a", {-0.99, 0}]}, {RGBColor[1., 0.3, 0.3], Disk[{Rational[1, 2], 0}, Scaled[Rational[1, 60]]]}, {GrayLevel[1], Inset["b", {0.51, 0}]}, {RGBColor[1., 0.3, 0.3], Disk[{Rational[-1, 2], 0}, Scaled[Rational[1, 60]]]}, {GrayLevel[1], Inset["c", {-0.49, 0}]}, {RGBColor[1., 0.3, 0.3], Disk[{Rational[1, 2], -1}, Scaled[Rational[1, 60]]]}, {GrayLevel[1], Inset["d", {0.51, -1}]}, {RGBColor[0, 1, 1], Disk[{Rational[-1, 2], -1}, Scaled[Rational[1, 60]]]}, {GrayLevel[0], Inset["e", {-0.49, -1}]}, {RGBColor[1., 0.3, 0.3], Disk[{Rational[-1, 2], Rational[-1, 2]}, Scaled[Rational[1, 60]]]}, {GrayLevel[1], Inset["f", {-0.49, Rational[-1, 2]}]}, {RGBColor[1., 0.3, 0.3], Disk[{Rational[1, 2], Rational[-1, 2]}, Scaled[Rational[1, 60]]]}, {GrayLevel[1], Inset["g", {0.51, Rational[-1, 2]}]}, {RGBColor[0, 1, 1], Disk[{Rational[-1, 2], Rational[1, 2]}, Scaled[Rational[1, 60]]]}, {GrayLevel[0], Inset["h", {-0.49, Rational[1, 2]}]}, {RGBColor[0, 1, 1], Disk[{-2, Rational[1, 2]}, Scaled[Rational[1, 60]]]}, {GrayLevel[0], Inset["i", {-1.99, Rational[1, 2]}]}, {RGBColor[0, 1, 1], Disk[{-2, Rational[3, 2]}, Scaled[Rational[1, 60]]]}, {GrayLevel[0], Inset["i", {-1.99, Rational[3, 2]}]}}}}}}}}}}}}}}}}}}, Axes -> True, AxesLabel -> {$CellContext`n, $CellContext`j $CellContext`k $CellContext`m}, ImageSize -> Medium]*)


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
(*\[Integral](a+b sin^k(z))^n \[DifferentialD]z when k^2=1\[And]a^2=b^2*)


(* ::Subsubtitle::Bold::Closed:: *)
(*Rule a:  \[Integral]1/(a+b Sin[c+d x]^k) \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Reference: G&R 2.555.3', CRC 337', A&S 4.3.134'/5'*)


(* ::Subsubsection:: *)
(*Derivation: Rule 1b with m=0, k=1 and n=-1*)


(* ::Subsubsection:: *)
(*Rule a1: If  a^2-b^2=0, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]1/(a+b Sin[c+d x]) \[DifferentialD]x  \[LongRightArrow]  -(Cos[c+d x]/(d (b+a Sin[c+d x])))*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[1/(a_+b_.*sin[c_.+d_.*x_]),x_Symbol] :=
  -Cos[c+d*x]/(d*(b+a*Sin[c+d*x])) /;
FreeQ[{a,b,c,d},x] && ZeroQ[a^2-b^2]


(* ::Subsubsection:: *)
(*Reference: G&R 2.555.4', CRC 338'/9', A&S 4.3.134'/5'*)


(* ::Code:: *)
Int[1/(a_+b_.*Cos[c_.+d_.*x_]),x_Symbol] :=
  Sin[c+d*x]/(d*(b+a*Cos[c+d*x])) /;
FreeQ[{a,b,c,d},x] && ZeroQ[a^2-b^2]


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Derivation: Algebraic expansion*)


(* ::Subsubsection:: *)
(*Basis: 1/(a+b z)=1/a-(b z)/(a(a+b z))*)


(* ::Subsubsection:: *)
(*Note: The rule for integrands of the same form when a^2-b^2!=0 could subsume this rule, but the resulting antiderivative will look less like the integrand involving sines instead of cosecants.*)


(* ::Subsubsection:: *)
(*Rule a2: If a^2-b^2=0, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]1/(a+b Csc[c+d x]) \[DifferentialD]x  \[LongRightArrow]  (x/a)-b/a \[Integral]Csc[c+d x]/(a+b Csc[c+d x]) \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[1/(a_+b_.*sin[c_.+d_.*x_]^(-1)),x_Symbol] :=
  x/a - Dist[b/a,Int[1/(sin[c+d*x]*(a+b/sin[c+d*x])),x]] /;
FreeQ[{a,b,c,d},x] && ZeroQ[a^2-b^2]


(* ::PageBreak:: *)
(**)


(* ::Subsubtitle::Bold::Closed:: *)
(*Rule b:  \[Integral]Sqrt[a+b Sin[c+d x]^k]\[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Derivation: Rule 3b with m=0, k=1 and n=1/2*)


(* ::Subsubsection:: *)
(*Rule b1: If a^2-b^2=0, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]Sqrt[a+b Sin[c+d x]]\[DifferentialD]x  \[LongRightArrow]  -((2 b Cos[c+d x])/(d Sqrt[a+b Sin[c+d x]]))*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[Sqrt[a_+b_.*sin[c_.+d_.*x_]],x_Symbol] :=
  -2*b*Cos[c+d*x]/(d*Sqrt[a+b*Sin[c+d*x]]) /;
FreeQ[{a,b,c,d},x] && ZeroQ[a^2-b^2]


(* ::Code:: *)
Int[Sqrt[a_+b_.*Cos[c_.+d_.*x_]],x_Symbol] :=
  2*b*Sin[c+d*x]/(d*Sqrt[a+b*Cos[c+d*x]]) /;
FreeQ[{a,b,c,d},x] && ZeroQ[a^2-b^2]


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Author: Martin on sci.math.symbolic on 10 March 2011*)


(* ::Subsubsection:: *)
(*Rule b2: If a^2-b^2=0, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]Sqrt[a+b Csc[c+d x]]\[DifferentialD]x  \[LongRightArrow]  -((2 Sqrt[a])/d)ArcTan[(Sqrt[a] Cot[c+d x])/Sqrt[a+b Csc[c+d x]]]*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[Sqrt[a_+b_.*sin[c_.+d_.*x_]^(-1)],x_Symbol] :=
  -2*Sqrt[a]/d*ArcTan[(Sqrt[a]*Cot[c+d*x])/Sqrt[a+b*Csc[c+d*x]]] /;
FreeQ[{a,b,c,d},x] && ZeroQ[a^2-b^2]


(* ::PageBreak:: *)
(**)


(* ::Subsubtitle::Bold::Closed:: *)
(*Rule c:  \[Integral]1/Sqrt[a+b Sin[c+d x]] \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Note: Although not essential, this rule produces a simpler antiderivative than rule c3.*)


(* ::Subsubsection:: *)
(*Rule c1: If  a-b=0, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]1/Sqrt[a+b Cos[c+d x]] \[DifferentialD]x  \[LongRightArrow]  (2/(d Sqrt[a+b Cos[c+d x]]))Cos[(c+d x)/2]ArcTanh[Sin[(c+d x)/2]]*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[1/Sqrt[a_+b_.*sin[c_.+Pi/2+d_.*x_]],x_Symbol] :=
  2/(d*Sqrt[a+b*Cos[c+d*x]])*Cos[(c+d*x)/2]*ArcTanh[Sin[(c+d*x)/2]] /;
FreeQ[{a,b,c,d},x] && ZeroQ[a-b]


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Note: Although not essential, this rule produces a simpler antiderivative than rule c3.*)


(* ::Subsubsection:: *)
(*Rule c2: If  a+b=0, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]1/Sqrt[a+b Cos[c+d x]] \[DifferentialD]x  \[LongRightArrow]  -(2/(d Sqrt[a+b Cos[c+d x]]))Sin[(c+d x)/2]ArcTanh[Cos[(c+d x)/2]]*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[1/Sqrt[a_+b_.*sin[c_.+Pi/2+d_.*x_]],x_Symbol] :=
  -2/(d*Sqrt[a+b*Cos[c+d*x]])*Sin[(c+d*x)/2]*ArcTanh[Cos[(c+d*x)/2]] /;
FreeQ[{a,b,c,d},x] && ZeroQ[a+b]


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Rule c3: If  a^2-b^2=0, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]1/Sqrt[a+b Sin[c+d x]] \[DifferentialD]x  \[LongRightArrow]  (2/(d Sqrt[a+b Sin[c+d x]]))Cos[(c+d x)/2-(\[Pi] b)/(4a)]ArcTanh[Sin[(c+d x)/2-(\[Pi] b)/(4a)]]*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[1/Sqrt[a_+b_.*sin[c_.+d_.*x_]],x_Symbol] :=
  2/(d*Sqrt[a+b*Sin[c+d*x]])*Cos[(c+d*x)/2-Pi*b/(4*a)]*ArcTanh[Sin[(c+d*x)/2-Pi*b/(4*a)]] /;
FreeQ[{a,b,c,d},x] && ZeroQ[a^2-b^2]


(* ::PageBreak:: *)
(**)


(* ::Subsubtitle::Bold::Closed:: *)
(*Rules 15-16:  \[Integral](a+b Csc[c+d x])^n \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Derivation: Rule 6 with m=0 and k=-1*)


(* ::Subsubsection:: *)
(*Rule 15: If  a^2-b^2=0 \[And] n<-1, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral](a+b Csc[c+d x])^n \[DifferentialD]x  \[LongRightArrow]  -((Cot[c+d x](a+b Csc[c+d x])^n)/(d (2n+1)))+*)
(*1/(a^2 (2n+1)) \[Integral](a(2n+1)-b(n+1)Csc[c+d x])(a+b Csc[c+d x])^(n+1) \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[(a_+b_.*sin[c_.+d_.*x_]^(-1))^n_,x_Symbol] :=
  -Cot[c+d*x]*(a+b*Csc[c+d*x])^n/(d*(2*n+1)) + 
  Dist[1/(a^2*(2*n+1)),Int[(a*(2*n+1)-(b*(n+1))*sin[c+d*x]^(-1))*(a+b*sin[c+d*x]^(-1))^(n+1),x]] /;
FreeQ[{a,b,c,d},x] && ZeroQ[a^2-b^2] && RationalQ[n] && n<-1


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Derivation: Rule 3a with m=0 and k=-1*)


(* ::Subsubsection:: *)
(*Rule 16: If  a^2-b^2=0 \[And] n>1 \[And] n!=2, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral](a+b Csc[c+d x])^n \[DifferentialD]x  \[LongRightArrow]  -((b^2 Cot[c+d x](a+b Csc[c+d x])^(n-2))/(d(n-1)))+*)
(*a/(n-1) \[Integral](a (n-1)+b (3 n-4)Csc[c+d x]) (a+b Csc[c+d x])^(n-2) \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[(a_+b_.*sin[c_.+d_.*x_]^(-1))^n_,x_Symbol] :=
  -b^2*Cot[c+d*x]*(a+b*Csc[c+d*x])^(n-2)/(d*(n-1)) + 
  Dist[a/(n-1),Int[(a*(n-1)+(b*(3*n-4))*sin[c+d*x]^(-1))*(a+b*sin[c+d*x]^(-1))^(n-2),x]] /;
FreeQ[{a,b,c,d},x] && ZeroQ[a^2-b^2] && RationalQ[n] && n>1 && n!=2


(* ::PageBreak:: *)
(**)


(* ::Title::Plain::Closed:: *)
(* Integration Rules for *)
(*\[Integral](sin^j(z))^m (a+b sin^k(z))^n \[DifferentialD]z when j^2=1\[And]k^2=1\[And]a^2=b^2*)


(* ::Subsubtitle::Bold::Closed:: *)
(*Rule d:  \[Integral]Sqrt[a+b Sin[c+d x]]/Sin[c+d x] \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Derivation: Piecewise constant extraction and trig substitution*)


(* ::Subsubsection:: *)
(*Basis:  If  a-b=0, then \!\( *)
(*\*SubscriptBox[\(\[PartialD]\), \(z\)]*)
(*\*FractionBox[\(Cos[*)
(*\*FractionBox[\(z\), \(2\)]]\), *)
(*SqrtBox[\(a + b\ Cos[z]\)]]\)=0*)


(* ::Subsubsection:: *)
(*Basis:  If  a-b=0, then a+b Cos[z]=2 a Cos[z/2]^2*)


(* ::Subsubsection:: *)
(*Note: Although not essential, this rule produces a simpler antiderivative than rule d3.*)


(* ::Subsubsection:: *)
(*Rule d1: If  a-b=0, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]Sqrt[a+b Cos[c+d x]]/Cos[c+d x] \[DifferentialD]x  \[LongRightArrow]  ((2a Cos[(c+d x)/2])/Sqrt[a+b Cos[c+d x]])\[Integral]Cos[(c+d x)/2]/Cos[c+d x] \[DifferentialD]x                                         *)
(*                                 \[LongRightArrow]  ((2 Sqrt[2] b  Cos[(c+d x)/2])/(d Sqrt[a+b Cos[c+d x]]))ArcTanh[Sqrt[2] Sin[(c+d x)/2]]*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[Sqrt[a_+b_.*sin[c_.+Pi/2+d_.*x_]]/sin[c_.+Pi/2+d_.*x_],x_Symbol] :=
  2*Sqrt[2]*b*Cos[(c+d*x)/2]/(d*Sqrt[a+b*Cos[c+d*x]])*ArcTanh[Sqrt[2]*Sin[(c+d*x)/2]] /;
FreeQ[{a,b,c,d},x] && ZeroQ[a-b]


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Derivation: Piecewise constant extraction and trig substitution*)


(* ::Subsubsection:: *)
(*Basis:  If  a+b=0, then \!\( *)
(*\*SubscriptBox[\(\[PartialD]\), \(z\)]*)
(*\*FractionBox[\(Sin[*)
(*\*FractionBox[\(z\), \(2\)]]\), *)
(*SqrtBox[\(a + b\ Cos[z]\)]]\)=0*)


(* ::Subsubsection:: *)
(*Basis:  If  a+b=0, then a+b Cos[z]=2 a Sin[z/2]^2*)


(* ::Subsubsection:: *)
(*Note: Although not essential, this rule produces a simpler antiderivative than rule d3.*)


(* ::Subsubsection:: *)
(*Rule d2: If  a+b=0, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]Sqrt[a+b Cos[c+d x]]/Cos[c+d x] \[DifferentialD]x  \[LongRightArrow]  ((2a Sin[(c+d x)/2])/Sqrt[a+b Cos[c+d x]])\[Integral]Sin[(c+d x)/2]/Cos[c+d x] \[DifferentialD]x                                           *)
(*                                \[LongRightArrow]  ((2 Sqrt[2] a  Sin[(c+d x)/2])/(d Sqrt[a+b Cos[c+d x]]))ArcTanh[Sqrt[2] Cos[(c+d x)/2]]*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[Sqrt[a_+b_.*sin[c_.+Pi/2+d_.*x_]]/sin[c_.+Pi/2+d_.*x_],x_Symbol] :=
  2*Sqrt[2]*a*Sin[(c+d*x)/2]/(d*Sqrt[a+b*Cos[c+d*x]])*ArcTanh[Sqrt[2]*Cos[(c+d*x)/2]] /;
FreeQ[{a,b,c,d},x] && ZeroQ[a+b]


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Derivation: Piecewise constant extraction and trig substitution*)


(* ::Subsubsection:: *)
(*Rule d3: If  a^2-b^2=0, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]Sqrt[a+b Sin[c+d x]]/Sin[c+d x] \[DifferentialD]x  \[LongRightArrow]  ((2 Sqrt[2] b  Cos[(c+d x)/2-(\[Pi] b)/(4a)])/(d Sqrt[a+b Sin[c+d x]]))ArcTanh[Sqrt[2] Sin[(c+d x)/2-(\[Pi] b)/(4a)]]*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[Sqrt[a_+b_.*sin[c_.+d_.*x_]]/sin[c_.+d_.*x_],x_Symbol] :=
  2*Sqrt[2]*b*Cos[(c+d*x)/2-Pi*b/(4*a)]/(d*Sqrt[a+b*Sin[c+d*x]])*
    ArcTanh[Sqrt[2]*Sin[(c+d*x)/2-Pi*b/(4*a)]] /;
FreeQ[{a,b,c,d},x] && ZeroQ[a^2-b^2]


(* ::PageBreak:: *)
(**)


(* ::Subsubtitle::Bold::Closed:: *)
(*Rule e:    \[Integral]1/(Sin[c+d x]^((k+1)/2) Sqrt[a+b Sin[c+d x]^k]) \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Author: Martin on sci.math.symbolic on 10 March 2011*)


(* ::Subsubsection:: *)
(*Derivation: Algebraic expansion*)


(* ::Subsubsection:: *)
(*Basis: If  k^2=1, then 1/(z^((k+1)/2) Sqrt[a+b z^k])=Sqrt[a+b z^k]/(a z^((k+1)/2))-(b z^((k-1)/2))/(a Sqrt[a+b z^k])*)


(* ::Subsubsection:: *)
(*Rule e: If  k^2=1 \[And] a^2-b^2=0, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]1/(Sin[c+d x]^((k+1)/2) Sqrt[a+b Sin[c+d x]^k]) \[DifferentialD]x  \[LongRightArrow]  (1/a)\[Integral]Sqrt[a+b Sin[c+d x]^k]/Sin[c+d x]^((k+1)/2) \[DifferentialD]x-b/a \[Integral]Sin[c+d x]^((k-1)/2)/Sqrt[a+b Sin[c+d x]^k] \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[1/(sin[c_.+d_.*x_]*Sqrt[a_+b_.*sin[c_.+d_.*x_]]),x_Symbol] :=
  Dist[1/a,Int[Sqrt[a+b*sin[c+d*x]]/sin[c+d*x],x]] - 
  Dist[b/a,Int[1/Sqrt[a+b*sin[c+d*x]],x]] /;
FreeQ[{a,b,c,d},x] && ZeroQ[a^2-b^2]


(* ::Code:: *)
Int[1/Sqrt[a_+b_.*sin[c_.+d_.*x_]^(-1)],x_Symbol] :=
  1/a*Int[Sqrt[a+b*sin[c+d*x]^(-1)],x] - 
  b/a*Int[sin[c+d*x]^(-1)/Sqrt[a+b*sin[c+d*x]^(-1)],x] /;
FreeQ[{a,b,c,d},x] && ZeroQ[a^2-b^2]


(* ::PageBreak:: *)
(**)


(* ::Subsubtitle::Bold::Closed:: *)
(*Rule f:  \[Integral]1/(Sqrt[Sin[c+d x]] Sqrt[a+b Sin[c+d x]]) \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Basis: EllipticF[z,0]=z*)


(* ::Subsubsection:: *)
(*Note: This is a special case of the rule for a^2!=b^2.*)


(* ::Subsubsection:: *)
(*Rule f1: If  a-b=0 \[And] a>0, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]1/(Sqrt[Sin[c+d x]] Sqrt[a+b Sin[c+d x]]) \[DifferentialD]x  \[LongRightArrow]  (Sqrt[2]/(d Sqrt[a]))ArcSin[Tan[(c+d x)/2-\[Pi]/4]]*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[1/(Sqrt[sin[c_.+Pi/2+d_.*x_]]*Sqrt[a_+b_.*sin[c_.+Pi/2+d_.*x_]]),x_Symbol] :=
  Sqrt[2]/(d*Sqrt[a])*ArcSin[Tan[(c+d*x)/2]] /;
FreeQ[{a,b,c,d},x] && ZeroQ[a-b] && PositiveQ[a]


(* ::Code:: *)
Int[1/(Sqrt[sin[c_.+d_.*x_]]*Sqrt[a_+b_.*sin[c_.+d_.*x_]]),x_Symbol] :=
  Sqrt[2]/(d*Sqrt[a])*ArcSin[Tan[(c+d*x)/2-Pi/4]] /;
FreeQ[{a,b,c,d},x] && ZeroQ[a-b] && PositiveQ[a]


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Author: Martin 10 March 2011*)


(* ::Subsubsection:: *)
(*Derivation: ???*)


(* ::Subsubsection:: *)
(*Rule f2: If  a^2-b^2=0, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]1/(Sqrt[Sin[c+d x]] Sqrt[a+b Sin[c+d x]]) \[DifferentialD]x  \[LongRightArrow]  -((Sqrt[2] Sqrt[b])/(a d))ArcTan[(Sqrt[b] Cos[c+d x])/(Sqrt[2] Sqrt[Sin[c+d x]] Sqrt[a+b Sin[c+d x]])]*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[1/(Sqrt[sin[c_.+d_.*x_]]*Sqrt[a_+b_.*sin[c_.+d_.*x_]]),x_Symbol] :=
  -Sqrt[2]*Sqrt[b]/(a*d)*ArcTan[Sqrt[b]*Cos[c+d*x]/(Sqrt[2]*Sqrt[Sin[c+d*x]]*Sqrt[a+b*Sin[c+d*x]])] /;
FreeQ[{a,b,c,d},x] && ZeroQ[a^2-b^2] && Not[ZeroQ[a-b] && PositiveQ[a]]


(* ::PageBreak:: *)
(**)


(* ::Subsubtitle::Bold::Closed:: *)
(*Rule g:  \[Integral]Sqrt[a+b Sin[c+d x]]/Sqrt[Sin[c+d x]] \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Author: Martin 10 March 2011*)


(* ::Subsubsection:: *)
(*Derivation: ???*)


(* ::Subsubsection:: *)
(*Rule g: If  a^2-b^2=0, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]Sqrt[a+b Sin[c+d x]]/Sqrt[Sin[c+d x]] \[DifferentialD]x  \[LongRightArrow]  -((2 Sqrt[b])/d)ArcTan[(Sqrt[b] Cos[c+d x])/(Sqrt[Sin[c+d x]] Sqrt[a+b Sin[c+d x]])]*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[Sqrt[a_+b_.*sin[c_.+d_.*x_]]/Sqrt[sin[c_.+d_.*x_]],x_Symbol] :=
  -2*Sqrt[b]/d*ArcTan[Sqrt[b]*Cos[c+d*x]/(Sqrt[Sin[c+d*x]]*Sqrt[a+b*Sin[c+d*x]])] /;
FreeQ[{a,b,c,d},x] && ZeroQ[a^2-b^2]


(* ::PageBreak:: *)
(**)


(* ::Subsubtitle::Bold::Closed:: *)
(*Rule h:    \[Integral]Sqrt[Sin[c+d x]]/Sqrt[a+b Sin[c+d x]] \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Derivation: Algebraic expansion*)


(* ::Subsubsection:: *)
(*Basis:  Sqrt[z]/Sqrt[a+b z]=Sqrt[a+b z]/(b Sqrt[z])-a/(b Sqrt[z] Sqrt[a+b z])*)


(* ::Subsubsection:: *)
(*Rule h: If  a^2-b^2=0, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]Sqrt[Sin[c+d x]]/Sqrt[a+b Sin[c+d x]] \[DifferentialD]x  \[LongRightArrow]  (1/b)\[Integral]Sqrt[a+b Sin[c+d x]]/Sqrt[Sin[c+d x]] \[DifferentialD]x-a/b \[Integral]1/(Sqrt[Sin[c+d x]] Sqrt[a+b Sin[c+d x]]) \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[Sqrt[sin[c_.+d_.*x_]]/Sqrt[a_+b_.*sin[c_.+d_.*x_]],x_Symbol] :=
  Dist[1/b,Int[Sqrt[a+b*sin[c+d*x]]/Sqrt[sin[c+d*x]],x]] - 
  Dist[a/b,Int[1/(Sqrt[sin[c+d*x]]*Sqrt[a+b*sin[c+d*x]]),x]] /;
FreeQ[{a,b,c,d},x] && ZeroQ[a^2-b^2]


(* ::PageBreak:: *)
(**)


(* ::Subsubtitle::Bold::Closed:: *)
(*Rule i:  \[Integral](Sin[c+d x]^j)^(m/2)/(a+b Sin[c+d x]^k)^2 \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Derivation: Rule 1b with n=-2 and 2j k m+k-2=0*)


(* ::Subsubsection:: *)
(*Rule i: If  j^2=k^2=1 \[And] a^2-b^2=0 \[And] 2j k m+k-2=0, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral](Sin[c+d x]^j)^m/(a+b Sin[c+d x]^k)^2 \[DifferentialD]x  \[LongRightArrow]  -((a Cos[c+d x] (Sin[c+d x]^j)^m)/(3b d (a+b Sin[c+d x]^k)^2))+1/(6 a b) \[Integral](Sin[c+d x]^j)^(m-j k) \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[(sin[c_.+d_.*x_]^j_.)^m_./(a_+b_.*sin[c_.+d_.*x_]^k_.)^2,x_Symbol] :=
  -a*Cos[c+d*x]*(Sin[c+d*x]^j)^m/(3*b*d*(a+b*Sin[c+d*x]^k)^2) + 
  1/(6*a*b)*Int[(sin[c+d*x]^j)^(m-j*k),x] /;
FreeQ[{a,b,c,d},x] && OneQ[j^2,k^2] && ZeroQ[a^2-b^2] && RationalQ[m] && 
  ZeroQ[2*j*k*m+k-2]


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Derivation: Rule 1b with 2j k m+n+k=0*)


(* ::Subsubsection:: *)
(*Note: Unfortunately this interesting looking rule seems to be of no use except for the above special case when n=-2.*)


(* ::Subsubsection:: *)
(*Rule: If  j^2=k^2=1 \[And] a^2-b^2=0 \[And] 2j k m+n+k=0 \[And] j k m>0 \[And] n<-1, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral](Sin[c+d x]^j)^m (a+b Sin[c+d x]^k)^n \[DifferentialD]x  \[LongRightArrow]  *)
(*((a Cos[c+d x] (Sin[c+d x]^j)^m (a+b Sin[c+d x]^k)^n)/(b d (2n+1)))+(n+1)/(2a b(2n+1)) \[Integral](Sin[c+d x]^j)^(m-j k) (a+b Sin[c+d x]^k)^(n+2) \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
(* Int[(sin[c_.+d_.*x_]^j_.)^m_.*(a_+b_.*sin[c_.+d_.*x_]^k_.)^n_,x_Symbol] :=
  a*Cos[c+d*x]*(Sin[c+d*x]^j)^m*(a+b*Sin[c+d*x]^k)^n/(b*d*(2*n+1)) + 
  Dist[(n+1)/(2*a*b*(2*n+1)),Int[(sin[c+d*x]^j)^(m-j*k)*(a+b*sin[c+d*x]^k)^(n+2),x]] /;
FreeQ[{a,b,c,d},x] && OneQ[j^2,k^2] && ZeroQ[a^2-b^2] && RationalQ[m,n] && 
  ZeroQ[2*j*k*m+n+k] && j*k*m>0 && n<-1 *)


(* ::PageBreak:: *)
(**)


(* ::Subsubtitle::Bold::Closed:: *)
(*\[Integral]Csc[c+d x](a+b Csc[c+d x])^n \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Note: Although the integrand equals 1/(b+a sin[c+d x]) which is easily integrated, this antiderivative is more similar in form to the integrand.*)


(* ::Subsubsection:: *)
(*Rule: If  a^2-b^2=0, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]Csc[c+d x]/(a+b Csc[c+d x]) \[DifferentialD]x  \[LongRightArrow]  -(Cot[c+d x]/(d (b+a Csc[c+d x])))*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[sin[c_.+d_.*x_]^(-1)/(a_+b_.*sin[c_.+d_.*x_]^(-1)),x_Symbol] :=
  -Cot[c+d*x]/(d*(b+a*Csc[c+d*x])) /;
FreeQ[{a,b,c,d},x] && ZeroQ[a^2-b^2]


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Derivation: Rule 3b with j m=-1, k=-1 and n=1/2*)


(* ::Subsubsection:: *)
(*Rule: If  a^2-b^2=0, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]Csc[c+d x]Sqrt[a+b Csc[c+d x]]\[DifferentialD]x  \[LongRightArrow]  -((2b Cot[c+d x])/(d Sqrt[a+b Csc[c+d x]]))*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[sin[c_.+d_.*x_]^(-1)*Sqrt[a_+b_.*sin[c_.+d_.*x_]^(-1)],x_Symbol] :=
  -2*b*Cot[c+d*x]/(d*Sqrt[a+b*Csc[c+d*x]]) /;
FreeQ[{a,b,c,d},x] && ZeroQ[a^2-b^2]


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Author: Martin on sci.math.symbolic on 10 March 2011*)


(* ::Subsubsection:: *)
(*Rule: If  a^2-b^2=0, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]Csc[c+d x]/Sqrt[a+b Csc[c+d x]] \[DifferentialD]x  \[LongRightArrow]  -(Sqrt[2a]/(b d))ArcTan[(Sqrt[a] Cot[c+d x])/(Sqrt[2] Sqrt[a+b Csc[c+d x]])]*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[1/(sin[c_.+d_.*x_]*Sqrt[a_+b_.*sin[c_.+d_.*x_]^(-1)]),x_Symbol] :=
  -Sqrt[2*a]/(b*d)*ArcTan[Sqrt[a]*Cot[c + d*x]/(Sqrt[2]*Sqrt[a + b*Csc[c + d*x]])] /;
FreeQ[{a,b,c,d},x] && ZeroQ[a^2-b^2]


(* ::PageBreak:: *)
(**)


(* ::Subsubtitle::Bold::Closed:: *)
(*\[Integral]Csc[c+d x]^2 (a+b Csc[c+d x])^n \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Derivation: Rule 1a with j m=-2 and k=-1*)


(* ::Subsubsection:: *)
(*Rule: If  a^2-b^2=0 \[And] n!=-1 \[And] n!=1 \[And] n!=2, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]Csc[c+d x]^2 (a+b Csc[c+d x])^n \[DifferentialD]x  \[LongRightArrow] *)
(* -((Cot[c+d x](a+b Csc[c+d x])^n)/(d (2n+1)))+n/(b (2n+1)) \[Integral]Csc[c+d x](a+b Csc[c+d x])^(n+1) \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[sin[c_.+d_.*x_]^(-2)*(a_+b_.*sin[c_.+d_.*x_]^(-1))^n_.,x_Symbol] :=
  -Cot[c+d*x]*(a+b*Csc[c+d*x])^n/(d*(2*n+1)) + 
  Dist[n/(b*(2*n+1)),Int[sin[c+d*x]^(-1)*(a+b*sin[c+d*x]^(-1))^(n+1),x]] /;
FreeQ[{a,b,c,d},x] && ZeroQ[a^2-b^2] && RationalQ[n] && n<-1


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Derivation: Rule 2 with j m=-2 and k=-1*)


(* ::Subsubsection:: *)
(*Rule: If  a^2-b^2=0 \[And] n>-1 \[And] n!=1 \[And] n!=2, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]Csc[c+d x]^2 (a+b Csc[c+d x])^n \[DifferentialD]x  \[LongRightArrow] *)
(* -((Cot[c+d x](a+b Csc[c+d x])^n)/(d (n+1)))+(b n)/(a (n+1)) \[Integral]Csc[c+d x](a+b Csc[c+d x])^n \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[sin[c_.+d_.*x_]^(-2)*(a_+b_.*sin[c_.+d_.*x_]^(-1))^n_.,x_Symbol] :=
  -Cot[c+d*x]*(a+b*Csc[c+d*x])^n/(d*(n+1)) + 
  Dist[b*n/(a*(n+1)),Int[sin[c+d*x]^(-1)*(a+b*sin[c+d*x]^(-1))^n,x]] /;
FreeQ[{a,b,c,d},x] && ZeroQ[a^2-b^2] && RationalQ[n] && n>-1 && n!=1 && n!=2


(* ::PageBreak:: *)
(**)


(* ::Subsubtitle::Bold::Closed:: *)
(*\[Integral](Sin[c+d x]^j)^(m/2) (a+b Csc[c+d x])^(n/2) \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Derivation: Algebraic expansion*)


(* ::Subsubsection:: *)
(*Basis: 1/Sqrt[a+b/z]=(z Sqrt[a+b/z])/b-(a z)/( b Sqrt[a+b/z])*)


(* ::Subsubsection:: *)
(*Rule: If  j^2=1 \[And] a^2-b^2=0 \[And] j m=-3, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral](Sin[c+d x]^j)^(m/2)/Sqrt[a+b Csc[c+d x]] \[DifferentialD]x  \[LongRightArrow]  (1/b)\[Integral](Sin[c+d x]^j)^(m/2+j) Sqrt[a+b Csc[c+d x]] \[DifferentialD]x-a/b \[Integral](Sin[c+d x]^j)^(m/2+j)/Sqrt[a+b Csc[c+d x]] \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[(sin[c_.+d_.*x_]^j_.)^m_/Sqrt[a_+b_.*sin[c_.+d_.*x_]^(-1)],x_Symbol] :=
  Dist[1/b,Int[(sin[c+d*x]^j)^(m+j)*Sqrt[a+b*sin[c+d*x]^(-1)],x]] - 
  Dist[a/b,Int[(sin[c+d*x]^j)^(m+j)/Sqrt[a+b*sin[c+d*x]^(-1)],x]] /;
FreeQ[{a,b,c,d},x] && OneQ[j^2] && ZeroQ[a^2-b^2] && RationalQ[m] && j*m==-3/2


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Derivation: Rule 5 with j m=1/2, k=-1 and n=-(1/2)*)


(* ::Subsubsection:: *)
(*Rule: If  j^2=1 \[And] a^2-b^2=0 \[And] j m=1, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral](Sin[c+d x]^j)^(m/2)/Sqrt[a+b Csc[c+d x]] \[DifferentialD]x  \[LongRightArrow]  *)
(*-((2Cos[c+d x])/(d (Sin[c+d x]^j)^(m/2) Sqrt[a+b Csc[c+d x]]))-a/b \[Integral]1/((Sin[c+d x]^j)^(m/2) Sqrt[a+b Csc[c+d x]]) \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[(sin[c_.+d_.*x_]^j_.)^m_/Sqrt[a_+b_.*sin[c_.+d_.*x_]^(-1)],x_Symbol] :=
  -2*Cos[c+d*x]/(d*(Sin[c+d*x]^j)^m*Sqrt[a+b*Csc[c+d*x]]) - 
  Dist[a/b,Int[1/((sin[c+d*x]^j)^m*Sqrt[a+b*sin[c+d*x]^(-1)]),x]] /;
FreeQ[{a,b,c,d},x] && OneQ[j^2] && ZeroQ[a^2-b^2] && RationalQ[m] && j*m==1/2


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Derivation: Rule 4a with j m=1/2, k=-1 and n=3/2*)


(* ::Subsubsection:: *)
(*Rule: If  j^2=1 \[And] a^2-b^2=0 \[And] j m=1, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral](Sin[c+d x]^j)^(m/2) (a+b Csc[c+d x])^(3/2) \[DifferentialD]x  \[LongRightArrow]  *)
(*-((2a^2 Cos[c+d x])/(d (Sin[c+d x]^j)^(m/2) Sqrt[a+b Csc[c+d x]]))+b \[Integral]Sqrt[a+b Csc[c+d x]]/(Sin[c+d x]^j)^(m/2) \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[(sin[c_.+d_.*x_]^j_.)^m_*(a_+b_.*sin[c_.+d_.*x_]^(-1))^(3/2),x_Symbol] :=
  -2*a^2*Cos[c+d*x]/(d*(Sin[c+d*x]^j)^m*Sqrt[a+b*Csc[c+d*x]]) + 
  Dist[b,Int[Sqrt[a+b*sin[c+d*x]^(-1)]/(sin[c+d*x]^j)^m,x]] /;
FreeQ[{a,b,c,d},x] && OneQ[j^2] && ZeroQ[a^2-b^2] && RationalQ[m] && j*m==1/2


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Derivation: Piecewise constant extraction*)


(* ::Subsubsection:: *)
(*Basis: If \!\( *)
(*\*SubscriptBox[\(\[PartialD]\), \(z\)]*)
(*\*FractionBox[*)
(*SqrtBox[\(b + a\ f[z]\)], \( *)
(*\*SqrtBox[\(f[z]\)] *)
(*\*SqrtBox[\(a + b\ *)
(*\*SuperscriptBox[\(f[z]\), \(-1\)]\)]\)]\)=0*)


(* ::Subsubsection:: *)
(*Rule: If  j^2=1 \[And] a^2-b^2=0 \[And] j m=-1 \[And] n^2=1, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral](Sin[c+d x]^j)^(m/2) (a+b Csc[c+d x])^(n/2) \[DifferentialD]x  \[LongRightArrow]  *)
(*(((Sin[c+d x]^j)^(m/2) Sqrt[b+a Sin[c+d x]])/Sqrt[a+b Csc[c+d x]])\[Integral](b+a Sin[c+d x])^(n/2)/Sin[c+d x]^((n+1)/2) \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[(sin[c_.+d_.*x_]^j_.)^m_*(a_+b_.*sin[c_.+d_.*x_]^(-1))^n_,x_Symbol] :=
  Dist[(Sin[c+d*x]^j)^m*Sqrt[b+a*Sin[c+d*x]]/Sqrt[a+b*Csc[c+d*x]],
    Int[(b+a*sin[c+d*x])^n/sin[c+d*x]^(n+1/2),x]] /;
FreeQ[{a,b,c,d},x] && OneQ[j^2] && ZeroQ[a^2-b^2] && RationalQ[m,n] && j*m==-1/2 && n^2==1/4


(* ::PageBreak:: *)
(**)


(* ::Subsubtitle::Bold::Closed:: *)
(*\[Integral]Csc[c+d x]^(m/2) (a+b Sin[c+d x])^(n/2) \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Derivation: Algebraic expansion*)


(* ::Subsubsection:: *)
(*Basis: 1/(Sqrt[1/z] Sqrt[a+b z])=(Sqrt[1/z] Sqrt[a+b z])/b-(a Sqrt[1/z])/( b Sqrt[a+b z])*)


(* ::Subsubsection:: *)
(*Rule: If  a^2-b^2=0, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]1/(Sqrt[Csc[c+d x]] Sqrt[a+b Sin[c+d x]]) \[DifferentialD]x  \[LongRightArrow]  *)
(*(1/b)\[Integral]Sqrt[Csc[c+d x]] Sqrt[a+b Sin[c+d x]] \[DifferentialD]x-a/b \[Integral]Sqrt[Csc[c+d x]]/Sqrt[a+b Sin[c+d x]] \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[1/(Sqrt[sin[c_.+d_.*x_]^(-1)]*Sqrt[a_+b_.*sin[c_.+d_.*x_]]),x_Symbol] :=
  Dist[1/b,Int[Sqrt[sin[c+d*x]^(-1)]*Sqrt[a+b*sin[c+d*x]],x]] - 
  Dist[a/b,Int[Sqrt[sin[c+d*x]^(-1)]/Sqrt[a+b*sin[c+d*x]],x]] /;
FreeQ[{a,b,c,d},x] && ZeroQ[a^2-b^2]


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Derivation: Piecewise constant extraction*)


(* ::Subsubsection:: *)
(*Basis: \!\( *)
(*\*SubscriptBox[\(\[PartialD]\), \(z\)]\(( *)
(*\*SqrtBox[\(f[z]\)] *)
(*\*SqrtBox[*)
(*SuperscriptBox[\(f[z]\), \(-1\)]])\)\)=0*)


(* ::Subsubsection:: *)
(*Rule: If  a^2-b^2=0 \[And] n^2=1*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]Sqrt[Csc[c+d x]] (a+b Sin[c+d x])^(n/2) \[DifferentialD]x  \[LongRightArrow]  *)
(*Sqrt[Csc[c+d x]] Sqrt[Sin[c+d x]]\[Integral](a+b Sin[c+d x])^(n/2)/Sqrt[Sin[c+d x]] \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[Sqrt[sin[c_.+d_.*x_]^(-1)]*(a_+b_.*sin[c_.+d_.*x_])^n_,x_Symbol] :=
  Dist[Sqrt[Csc[c+d*x]]*Sqrt[Sin[c+d*x]],Int[(a+b*sin[c+d*x])^n/Sqrt[sin[c+d*x]],x]] /;
FreeQ[{a,b,c,d},x] && ZeroQ[a^2-b^2] && RationalQ[n] && n^2==1/4


(* ::PageBreak:: *)
(**)


(* ::Subsubtitle::Bold::Closed:: *)
(*Rules 9-10:  \[Integral](Sin[c+d x]^j)^m Sqrt[a+b Sin[c+d x]^k]\[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Derivation: Rule 9b with 2 j k m+k+2=0*)


(* ::Subsubsection:: *)
(*Rule 9a: If  j^2=k^2=1 \[And] a^2-b^2=0 \[And] 2 j k m+k+2=0, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral](Sin[c+d x]^j)^m Sqrt[a+b Sin[c+d x]^k]\[DifferentialD]x  \[LongRightArrow]  -((2a Cos[c+d x] (Sin[c+d x]^j)^(m+j k))/(d Sqrt[a+b Sin[c+d x]^k]))*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[(sin[c_.+d_.*x_]^j_.)^m_*Sqrt[a_+b_.*sin[c_.+d_.*x_]^k_.],x_Symbol] :=
  -2*a*Cos[c+d*x]*(Sin[c+d*x]^j)^(m+j*k)/(d*Sqrt[a+b*Sin[c+d*x]^k]) /;
FreeQ[{a,b,c,d,m},x] && OneQ[j^2,k^2] && ZeroQ[a^2-b^2] && ZeroQ[2*j*k*m+k+2]


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Derivation: Rule 4b with n=1/2*)


(* ::Subsubsection:: *)
(*Rule 9b: If  j^2=k^2=1 \[And] a^2-b^2=0 \[And]  j k m<=-1 \[And]  2 j k m+k+2!=0, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral](Sin[c+d x]^j)^m Sqrt[a+b Sin[c+d x]^k]\[DifferentialD]x  \[LongRightArrow]  *)
(*((2a Cos[c+d x] (Sin[c+d x]^j)^(m+j k))/(d(2j k m+k+1)Sqrt[a+b Sin[c+d x]^k]))+(b(2 j k m+k+2))/(a(2j k m+k+1)) \[Integral](Sin[c+d x]^j)^(m+j k) Sqrt[a+b Sin[c+d x]^k]\[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[(sin[c_.+d_.*x_]^j_.)^m_.*Sqrt[a_+b_.*sin[c_.+d_.*x_]^k_.],x_Symbol] :=
  2*a*Cos[c+d*x]*(Sin[c+d*x]^j)^(m+j*k)/(d*(2*j*k*m+k+1)*Sqrt[a+b*Sin[c+d*x]^k]) + 
  Dist[b*(2*j*k*m+k+2)/(a*(2*j*k*m+k+1)),Int[(sin[c+d*x]^j)^(m+j*k)*Sqrt[a+b*sin[c+d*x]^k],x]] /;
FreeQ[{a,b,c,d},x] && OneQ[j^2,k^2] && ZeroQ[a^2-b^2] && RationalQ[m] && 
  j*k*m<=-1 && NonzeroQ[2*j*k*m+k+2]


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Derivation: Rule 3b with n=1/2*)


(* ::Subsubsection:: *)
(*Rule 10: If  j^2=k^2=1 \[And] a^2-b^2=0 \[And] 2 j m+1!=0 \[And] j k m>0 \[And] j k m!=1 \[And] j k m!=2, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral](Sin[c+d x]^j)^m Sqrt[a+b Sin[c+d x]^k]\[DifferentialD]x \[LongRightArrow]  *)
(*-((2 b Cos[c+d x](Sin[c+d x]^j)^m)/(d k(2 j m+1) Sqrt[a+b Sin[c+d x]^k]))+(a (2j k m+k-1))/(b k(2 j m+1)) \[Integral](Sin[c+d x]^j)^(m-j k) Sqrt[a+b Sin[c+d x]^k]\[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[(sin[c_.+d_.*x_]^j_.)^m_.*Sqrt[a_+b_.*sin[c_.+d_.*x_]^k_.],x_Symbol] :=
  -2*b*Cos[c+d*x]*(Sin[c+d*x]^j)^m/(d*k*(2*j*m+1)*Sqrt[a+b*Sin[c+d*x]^k]) + 
  Dist[a*(2*j*k*m+k-1)/(b*k*(2*j*m+1)),Int[(sin[c+d*x]^j)^(m-j*k)*Sqrt[a+b*sin[c+d*x]^k],x]] /;
FreeQ[{a,b,c,d},x] && OneQ[j^2,k^2] && ZeroQ[a^2-b^2] && RationalQ[m] && 
  NonzeroQ[2*j*m+1] && j*k*m>0 && j*k*m!=1 && j*k*m!=2


(* ::PageBreak:: *)
(**)


(* ::Subsubtitle::Bold::Closed:: *)
(*Rules 13-14:  \[Integral](Sin[c+d x]^j)^m/(a+b Sin[c+d x]^k)^(j k m+(k+3)/2) \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Derivation: Rule 5 with j k m+n+(k+3)/2=0*)


(* ::Subsubsection:: *)
(*Rule 13: If  j^2=k^2=1 \[And] a^2-b^2=0 \[And] j k m+n+(k+3)/2=0 \[And] n>-1 \[And] n!=1 \[And] n!=2, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral](Sin[c+d x]^j)^m (a+b Sin[c+d x]^k)^n \[DifferentialD]x  \[LongRightArrow]  *)
(*-((Cos[c+d x] (Sin[c+d x]^j)^(m+j k) (a+b Sin[c+d x]^k)^n)/(d(n+1)))+(a n)/(b(n+1)) \[Integral](Sin[c+d x]^j)^(m+j k) (a+b Sin[c+d x]^k)^n \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[(sin[c_.+d_.*x_]^j_.)^m_.*(a_+b_.*sin[c_.+d_.*x_]^k_.)^n_,x_Symbol] :=
  -Cos[c+d*x]*(Sin[c+d*x]^j)^(m+j*k)*(a+b*Sin[c+d*x]^k)^n/(d*(n+1)) + 
  Dist[a*n/(b*(n+1)),Int[(sin[c+d*x]^j)^(m+j*k)*(a+b*sin[c+d*x]^k)^n,x]] /;
FreeQ[{a,b,c,d},x] && OneQ[j^2,k^2] && ZeroQ[a^2-b^2] && RationalQ[m,n] && 
  ZeroQ[j*k*m+n+(k+3)/2] && n>-1 && n!=1 && n!=2


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Derivation: Rule 6 with j k m+n+(k+3)/2=0*)


(* ::Subsubsection:: *)
(*Rule 14: If  j^2=k^2=1 \[And] a^2-b^2=0 \[And] j k m+n+(k+3)/2=0 \[And] j k m!=1 \[And] j k m!=2 \[And] n<-1, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral](Sin[c+d x]^j)^m (a+b Sin[c+d x]^k)^n \[DifferentialD]x  \[LongRightArrow]  *)
(*-((Cos[c+d x](Sin[c+d x]^j)^(m+j k) (a+b Sin[c+d x]^k)^n)/(d (2n+1)))+n/(a(2n+1)) \[Integral](Sin[c+d x]^j)^m (a+b Sin[c+d x]^k)^(n+1) \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[(sin[c_.+d_.*x_]^j_.)^m_.*(a_+b_.*sin[c_.+d_.*x_]^k_.)^n_,x_Symbol] :=
  -Cos[c+d*x]*(Sin[c+d*x]^j)^(m+j*k)*(a+b*Sin[c+d*x]^k)^n/(d*(2*n+1)) + 
  Dist[n/(a*(2*n+1)),Int[(sin[c+d*x]^j)^m*(a+b*sin[c+d*x]^k)^(n+1),x]] /;
FreeQ[{a,b,c,d},x] && OneQ[j^2,k^2] && ZeroQ[a^2-b^2] && RationalQ[m,n] && 
  ZeroQ[j*k*m+n+(k+3)/2] && j*k*m!=1 && j*k*m!=2 && n<-1


(* ::PageBreak:: *)
(**)


(* ::Subsubtitle::Bold::Closed:: *)
(*Rules 11-12:  \[Integral](Sin[c+d x]^j)^m/(a+b Sin[c+d x]^k)^(j k m+(k+1)/2) \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Derivation: Rule 4b with j k m+n+(k+1)/2=0*)


(* ::Subsubsection:: *)
(*Rule 11: If  j^2=k^2=1 \[And] a^2-b^2=0 \[And] j k m+n+(k+1)/2=0 \[And] n>0 \[And] n!=1/2 \[And] n!=1 \[And] n!=2, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral](Sin[c+d x]^j)^m (a+b Sin[c+d x]^k)^n \[DifferentialD]x  \[LongRightArrow]  *)
(*-((a Cos[c+d x] (Sin[c+d x]^j)^(m+j k) (a+b Sin[c+d x]^k)^(n-1))/(d n))+(b(2n-1))/n \[Integral](Sin[c+d x]^j)^(m+j k) (a+b Sin[c+d x]^k)^(n-1) \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[(sin[c_.+d_.*x_]^j_.)^m_.*(a_+b_.*sin[c_.+d_.*x_]^k_.)^n_,x_Symbol] :=
  -a*Cos[c+d*x]*(Sin[c+d*x]^j)^(m+j*k)*(a+b*Sin[c+d*x]^k)^(n-1)/(d*n) + 
  Dist[b*(2*n-1)/n,Int[(sin[c+d*x]^j)^(m+j*k)*(a+b*sin[c+d*x]^k)^(n-1),x]] /;
FreeQ[{a,b,c,d},x] && OneQ[j^2,k^2] && ZeroQ[a^2-b^2] && RationalQ[m,n] && 
  ZeroQ[j*k*m+n+(k+1)/2] && n>0 && n!=1/2 && n!=1 && n!=2


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Derivation: Rule 1b with j k m+n+(k+1)/2=0*)


(* ::Subsubsection:: *)
(*Rule 12: If  j^2=k^2=1 \[And] a^2-b^2=0 \[And] j k m+n+(k+1)/2=0 \[And] j k m!=1 \[And] j k m!=2 \[And] n<-1, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral](Sin[c+d x]^j)^m (a+b Sin[c+d x]^k)^n \[DifferentialD]x  \[LongRightArrow]  *)
(*((a Cos[c+d x] (Sin[c+d x]^j)^m (a+b Sin[c+d x]^k)^n)/(b d (2n+1)))+(n+1)/(b (2n+1)) \[Integral](Sin[c+d x]^j)^(m-j k) (a+b Sin[c+d x]^k)^(n+1) \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[(sin[c_.+d_.*x_]^j_.)^m_.*(a_+b_.*sin[c_.+d_.*x_]^k_.)^n_,x_Symbol] :=
  a*Cos[c+d*x]*(Sin[c+d*x]^j)^m*(a+b*Sin[c+d*x]^k)^n/(b*d*(2*n+1)) + 
  Dist[(n+1)/(b*(2*n+1)),Int[(sin[c+d*x]^j)^(m-j*k)*(a+b*sin[c+d*x]^k)^(n+1),x]] /;
FreeQ[{a,b,c,d},x] && OneQ[j^2,k^2] && ZeroQ[a^2-b^2] && RationalQ[m,n] && 
  ZeroQ[j*k*m+n+(k+1)/2] && j*k*m!=1 && j*k*m!=2 && n<-1


(* ::PageBreak:: *)
(**)


(* ::Subsubtitle::Bold::Closed:: *)
(*Rules 7-8:  \[Integral]Sin[c+d x]^((k-1)/2) (a+b Sin[c+d x]^k)^n \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Reference: G&R 2.555.?*)


(* ::Subsubsection:: *)
(*Derivation: Rule 1b with j m=(k-1)/2*)


(* ::Subsubsection:: *)
(*Rule 7: If  k^2=1 \[And] a^2-b^2=0 \[And] n<-1, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]Sin[c+d x]^((k-1)/2) (a+b Sin[c+d x]^k)^n \[DifferentialD]x  \[LongRightArrow]  *)
(*((b Cos[c+d x]Sin[c+d x]^((k-1)/2) (a+b Sin[c+d x]^k)^n)/(a d (2 n+1)))+(n+1)/(a (2 n+1)) \[Integral]Sin[c+d x]^((k-1)/2) (a+b Sin[c+d x]^k)^(n+1) \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[(a_+b_.*sin[c_.+d_.*x_])^n_,x_Symbol] :=
  b*Cos[c+d*x]*(a+b*Sin[c+d*x])^n/(a*d*(2*n+1)) +
  Dist[(n+1)/(a*(2*n+1)),Int[(a+b*sin[c+d*x])^(n+1),x]] /;
FreeQ[{a,b,c,d},x] && ZeroQ[a^2-b^2] && RationalQ[n] && n<-1


(* ::Code:: *)
Int[sin[c_.+d_.*x_]^(-1)*(a_+b_.*sin[c_.+d_.*x_]^(-1))^n_,x_Symbol] :=
  b*Cot[c+d*x]*(a+b*Csc[c+d*x])^n/(a*d*(2*n+1)) + 
  Dist[(n+1)/(a*(2*n+1)),Int[sin[c+d*x]^(-1)*(a+b/sin[c+d*x])^(n+1),x]] /;
FreeQ[{a,b,c,d},x] && ZeroQ[a^2-b^2] && RationalQ[n] && n<-1


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Reference: G&R 2.555.? inverted*)


(* ::Subsubsection:: *)
(*Derivation: Rule 3b with j m=(k-1)/2*)


(* ::Subsubsection:: *)
(*Rule 8: If  k^2=1 \[And] a^2-b^2=0 \[And] n>0 \[And] n!=1/2 \[And] n!=1 \[And] n!=2, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]Sin[c+d x]^((k-1)/2) (a+b Sin[c+d x]^k)^n \[DifferentialD]x  \[LongRightArrow]  *)
(*-((b Cos[c+d x] Sin[c+d x]^((k-1)/2) (a+b Sin[c+d x]^k)^(n-1))/(d n))+(a (2 n-1))/n \[Integral]Sin[c+d x]^((k-1)/2) (a+b Sin[c+d x]^k)^(n-1) \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[(a_+b_.*sin[c_.+d_.*x_])^n_,x_Symbol] :=
  -b*Cos[c+d*x]*(a+b*Sin[c+d*x])^(n-1)/(d*n) +
  Dist[a*(2*n-1)/n,Int[(a+b*sin[c+d*x])^(n-1),x]] /;
FreeQ[{a,b,c,d},x] && ZeroQ[a^2-b^2] && RationalQ[n] && n>0 && n!=1 && n!=2


(* ::Code:: *)
Int[sin[c_.+d_.*x_]^(-1)*(a_+b_.*sin[c_.+d_.*x_]^(-1))^n_.,x_Symbol] :=
  -b*Cot[c+d*x]*(a+b*Csc[c+d*x])^(n-1)/(d*n) + 
  Dist[a*(2*n-1)/n,Int[sin[c+d*x]^(-1)*(a+b*sin[c+d*x]^(-1))^(n-1),x]] /;
FreeQ[{a,b,c,d},x] && ZeroQ[a^2-b^2] && RationalQ[n] && n>0 && n!=1/2 && n!=1 && n!=2


(* ::PageBreak:: *)
(**)


(* ::Subsubtitle::Bold::Closed:: *)
(*Rules 1-6:  \[Integral](Sin[c+d x]^j)^m (a+b Sin[c+d x]^k)^n \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Derivation: Recurrence 7 with A=0, B=1 and m=m-1*)


(* ::Subsubsection:: *)
(*Rule 1a: If  j^2=k^2=1 \[And] a^2-b^2=0 \[And] j k m>1 \[And] n<=-1, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral](Sin[c+d x]^j)^m (a+b Sin[c+d x]^k)^n \[DifferentialD]x  \[LongRightArrow]  *)
(*-((Cos[c+d x] (Sin[c+d x]^j)^(m-j k) (a+b Sin[c+d x]^k)^n)/(d(2 n+1)))+1/(a^2 (2 n+1))\[CenterDot]*)
(*\[Integral](Sin[c+d x]^j)^(m-2j k) (a (j k m+(k-3)/2)-b(j k m-n+(k-3)/2)Sin[c+d x]^k) (a+b Sin[c+d x]^k)^(n+1) \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[(sin[c_.+d_.*x_]^j_.)^m_.*(a_+b_.*sin[c_.+d_.*x_]^k_.)^n_,x_Symbol] :=
  -Cos[c+d*x]*(Sin[c+d*x]^j)^(m-j*k)*(a+b*Sin[c+d*x]^k)^n/(d*(2*n+1)) + 
  Dist[1/(a^2*(2*n+1)),
    Int[(sin[c+d*x]^j)^(m-2*j*k)*
      (a*(j*k*m+(k-3)/2)-b*(j*k*m-n+(k-3)/2)*sin[c+d*x]^k)*(a+b*sin[c+d*x]^k)^(n+1),x]] /;
FreeQ[{a,b,c,d},x] && OneQ[j^2,k^2] && ZeroQ[a^2-b^2] && RationalQ[m,n] && 
  j*k*m>1 && j*k*m!=2 && n<=-1


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Derivation: Recurrence 7 with A=1 and B=0*)


(* ::Subsubsection:: *)
(*Derivation: Recurrence 12 with A=0, B=1 and m=m-1*)


(* ::Subsubsection:: *)
(*Rule 1b: If  j^2=k^2=1 \[And] a^2-b^2=0 \[And] 0<j k m<1 \[And] n<=-1, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral](Sin[c+d x]^j)^m (a+b Sin[c+d x]^k)^n \[DifferentialD]x  \[LongRightArrow]  *)
(*((a Cos[c+d x] (Sin[c+d x]^j)^m (a+b Sin[c+d x]^k)^n)/(b d (2n+1)))+1/(b^2 (2n+1))\[CenterDot]*)
(*\[Integral](Sin[c+d x]^j)^(m-j k) (-b(j k m+(k-1)/2)+a(j k m+n+(k+1)/2)Sin[c+d x]^k)(a+b Sin[c+d x]^k)^(n+1) \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[(sin[c_.+d_.*x_]^j_.)^m_.*(a_+b_.*sin[c_.+d_.*x_]^k_.)^n_,x_Symbol] :=
  a*Cos[c+d*x]*(Sin[c+d*x]^j)^m*(a+b*Sin[c+d*x]^k)^n/(b*d*(2*n+1)) + 
  Dist[1/(b^2*(2*n+1)),
    Int[(sin[c+d*x]^j)^(m-j*k)*
      (-b*(j*k*m+(k-1)/2)+a*(j*k*m+n+(k+1)/2)*sin[c+d*x]^k)*(a+b*sin[c+d*x]^k)^(n+1),x]] /;
FreeQ[{a,b,c,d},x] && OneQ[j^2,k^2] && ZeroQ[a^2-b^2] && RationalQ[m,n] && 
  0<j*k*m<1 && n<=-1


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Derivation: Recurrence 8 with A=0, B=1 and m=m-1*)


(* ::Subsubsection:: *)
(*Rule 2: If  j^2=k^2=1 \[And] a^2-b^2=0 \[And] j k m+n+(k-1)/2!=0 \[And] j k m>1 \[And] -1<n<0 \[And] j k m-1!=n, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral](Sin[c+d x]^j)^m (a+b Sin[c+d x]^k)^n \[DifferentialD]x  \[LongRightArrow]  *)
(*-((Cos[c+d x] (Sin[c+d x]^j)^(m-j k) (a+b Sin[c+d x]^k)^n)/(d(j k m+n+(k-1)/2)))+1/(b (j k m+n+(k-1)/2))\[CenterDot]*)
(*\[Integral](Sin[c+d x]^j)^(m-2j k) (b(j k m+(k-3)/2)+a n Sin[c+d x]^k) (a+b Sin[c+d x]^k)^n \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[(sin[c_.+d_.*x_]^j_.)^m_.*(a_+b_.*sin[c_.+d_.*x_]^k_.)^n_,x_Symbol] :=
  -Cos[c+d*x]*(Sin[c+d*x]^j)^(m-j*k)*(a+b*Sin[c+d*x]^k)^n/(d*(j*k*m+n+(k-1)/2)) + 
  Dist[1/(b*(j*k*m+n+(k-1)/2)),
    Int[(sin[c+d*x]^j)^(m-2*j*k)*(b*(j*k*m+(k-3)/2)+a*n*sin[c+d*x]^k)*(a+b*sin[c+d*x]^k)^n,x]] /;
FreeQ[{a,b,c,d},x] && OneQ[j^2,k^2] && ZeroQ[a^2-b^2] && RationalQ[m,n] && 
  NonzeroQ[j*k*m+n+(k-1)/2] && j*k*m>1 && j*k*m!=2 && -1<n<0 && j*k*m-1!=n


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Derivation: Recurrence 9 with A=a, B=b and n=n-1*)


(* ::Subsubsection:: *)
(*Rule 3a: If  j^2=k^2=1 \[And] a^2-b^2=0 \[And] j k m+n+(k-1)/2!=0 \[And] j k m>=-1 \[And] j k m!=1 \[And] j k m!=2 \[And] n>1 \[And] n!=2, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral](Sin[c+d x]^j)^m (a+b Sin[c+d x]^k)^n \[DifferentialD]x  \[LongRightArrow]  *)
(*-((b^2 Cos[c+d x] (Sin[c+d x]^j)^(m+j k) (a+b Sin[c+d x]^k)^(n-2))/(d(j k m+n+(k-1)/2)))+a/(j k m+n+(k-1)/2)\[CenterDot]*)
(*\[Integral](Sin[c+d x]^j)^m (a (2 j k m+n+k)+b (2 j k m+3 n+k-3)Sin[c+d x]^k) (a+b Sin[c+d x]^k)^(n-2) \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[(sin[c_.+d_.*x_]^j_.)^m_.*(a_+b_.*sin[c_.+d_.*x_]^k_.)^n_,x_Symbol] :=
  -b^2*Cos[c+d*x]*(Sin[c+d*x]^j)^(m+j*k)*(a+b*Sin[c+d*x]^k)^(n-2)/(d*(j*k*m+n+(k-1)/2)) + 
  Dist[a/(j*k*m+n+(k-1)/2),
    Int[(sin[c+d*x]^j)^m*
      (a*(2*j*k*m+n+k)+b*(2*j*k*m+3*n+k-3)*sin[c+d*x]^k)*(a+b*sin[c+d*x]^k)^(n-2),x]] /;
FreeQ[{a,b,c,d},x] && OneQ[j^2,k^2] && ZeroQ[a^2-b^2] && RationalQ[m,n] && 
  NonzeroQ[j*k*m+n+(k-1)/2] && j*k*m>=-1 && j*k*m!=1 && j*k*m!=2 && n>1 && n!=2


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Derivation: Recurrence 8 with A=a, B=b and n=n-1*)


(* ::Subsubsection:: *)
(*Derivation: Recurrence 9 with A=0, B=1 and m=m-1*)


(* ::Subsubsection:: *)
(*Note: In the case n=1/2, this rule simplifies to rule 10.*)


(* ::Subsubsection:: *)
(*Rule 3b: If  j^2=k^2=1 \[And] a^2-b^2=0 \[And] j k m>0 \[And] j k m!=1 \[And] j k m!=2 \[And] 0<n<1 \[And] n!=1/2, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral](Sin[c+d x]^j)^m (a+b Sin[c+d x]^k)^n \[DifferentialD]x  \[LongRightArrow]  *)
(*-((b Cos[c+d x] (Sin[c+d x]^j)^m (a+b Sin[c+d x]^k)^(n-1))/(d(j k m+n+(k-1)/2)))+1/(j k m+n+(k-1)/2)\[CenterDot]*)
(*\[Integral](Sin[c+d x]^j)^(m-j k) (b (j k m+(k-1)/2)+a(j k m+2n+(k-3)/2)Sin[c+d x]^k) (a+b Sin[c+d x]^k)^(n-1) \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[(sin[c_.+d_.*x_]^j_.)^m_.*(a_+b_.*sin[c_.+d_.*x_]^k_.)^n_,x_Symbol] :=
  -b*Cos[c+d*x]*(Sin[c+d*x]^j)^m*(a+b*Sin[c+d*x]^k)^(n-1)/(d*(j*k*m+n+(k-1)/2)) + 
  Dist[1/(j*k*m+n+(k-1)/2),
    Int[(sin[c+d*x]^j)^(m-j*k)*
      (b*(j*k*m+(k-1)/2)+a*(j*k*m+2*n+(k-3)/2)*sin[c+d*x]^k)*(a+b*sin[c+d*x]^k)^(n-1),x]] /;
FreeQ[{a,b,c,d},x] && OneQ[j^2,k^2] && ZeroQ[a^2-b^2] && RationalQ[m,n] && 
  j*k*m>0 && j*k*m!=1 && j*k*m!=2 && 0<n<1 && n!=1/2


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Derivation: Recurrence 10 with A=a, B=b and n=n-1*)


(* ::Subsubsection:: *)
(*Rule 4a: If  j^2=k^2=1 \[And] a^2-b^2=0 \[And] j k m<-1 \[And] n>1 \[And] n!=2, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral](Sin[c+d x]^j)^m (a+b Sin[c+d x]^k)^n \[DifferentialD]x  \[LongRightArrow]  *)
(*((a^2 Cos[c+d x] (Sin[c+d x]^j)^(m+j k) (a+b Sin[c+d x]^k)^(n-2))/(d(j k m+(k+1)/2)))+a/(j k m+(k+1)/2)\[CenterDot]*)
(*\[Integral](Sin[c+d x]^j)^(m+j k) (b(2j k m-n+k+3)+a(2j k m+n+k) Sin[c+d x]^k)(a+b Sin[c+d x]^k)^(n-2) \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[(sin[c_.+d_.*x_]^j_.)^m_.*(a_+b_.*sin[c_.+d_.*x_]^k_.)^n_,x_Symbol] :=
  a^2*Cos[c+d*x]*(Sin[c+d*x]^j)^(m+j*k)*(a+b*Sin[c+d*x]^k)^(n-2)/(d*(j*k*m+(k+1)/2)) + 
  Dist[a/(j*k*m+(k+1)/2),
    Int[(sin[c+d*x]^j)^(m+j*k)*
      (b*(2*j*k*m-n+k+3)+a*(2*j*k*m+n+k)*sin[c+d*x]^k)*(a+b*sin[c+d*x]^k)^(n-2),x]] /;
FreeQ[{a,b,c,d},x] && OneQ[j^2,k^2] && ZeroQ[a^2-b^2] && RationalQ[m,n] && 
  j*k*m<-1 && n>1 && n!=2


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Derivation: Recurrence 10 with A=1 and B=0*)


(* ::Subsubsection:: *)
(*Derivation: Recurrence 11 with A=a, B=b and n=n-1*)


(* ::Subsubsection:: *)
(*Note: In the case n=1/2, this rule simplifies to rule 9b.*)


(* ::Subsubsection:: *)
(*Rule 4b: If  j^2=k^2=1 \[And] a^2-b^2=0 \[And] j k m<-1 \[And] 0<n<1 \[And] n!=1/2, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral](Sin[c+d x]^j)^m (a+b Sin[c+d x]^k)^n \[DifferentialD]x  \[LongRightArrow]  *)
(*((a Cos[c+d x] (Sin[c+d x]^j)^(m+j k) (a+b Sin[c+d x]^k)^(n-1))/(d(j k m+(k+1)/2)))+1/(j k m+(k+1)/2)\[CenterDot]*)
(*\[Integral](Sin[c+d x]^j)^(m+j k) (b(j k m-n+(k+3)/2)+a(j k m+n+(k+1)/2) Sin[c+d x]^k)(a+b Sin[c+d x]^k)^(n-1) \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[(sin[c_.+d_.*x_]^j_.)^m_.*(a_+b_.*sin[c_.+d_.*x_]^k_.)^n_,x_Symbol] :=
  a*Cos[c+d*x]*(Sin[c+d*x]^j)^(m+j*k)*(a+b*Sin[c+d*x]^k)^(n-1)/(d*(j*k*m+(k+1)/2)) + 
  Dist[1/(j*k*m+(k+1)/2),
    Int[(sin[c+d*x]^j)^(m+j*k)*
      (b*(j*k*m-n+(k+3)/2)+a*(j*k*m+n+(k+1)/2)*sin[c+d*x]^k)*(a+b*sin[c+d*x]^k)^(n-1),x]] /;
FreeQ[{a,b,c,d},x] && OneQ[j^2,k^2] && ZeroQ[a^2-b^2] && RationalQ[m,n] && 
  j*k*m<-1 && 0<n<1 && n!=1/2


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Derivation: Recurrence 11 with A=1 and B=0*)


(* ::Subsubsection:: *)
(*Rule 5: If  j^2=k^2=1 \[And] a^2-b^2=0 \[And] j k m+(k+1)/2!=0 \[And] j k m<=-1 \[And] -1<n<0, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral](Sin[c+d x]^j)^m (a+b Sin[c+d x]^k)^n \[DifferentialD]x  \[LongRightArrow]  *)
(*((Cos[c+d x] (Sin[c+d x]^j)^(m+j k) (a+b Sin[c+d x]^k)^n)/(d(j k m+(k+1)/2)))+1/(b (j k m+(k+1)/2))\[CenterDot]*)
(*\[Integral](Sin[c+d x]^j)^(m+j k) (-a n+b(j k m+n+(k+3)/2)Sin[c+d x]^k) (a+b Sin[c+d x]^k)^n \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[(sin[c_.+d_.*x_]^j_.)^m_.*(a_+b_.*sin[c_.+d_.*x_]^k_.)^n_,x_Symbol] :=
  Cos[c+d*x]*(Sin[c+d*x]^j)^(m+j*k)*(a+b*Sin[c+d*x]^k)^n/(d*(j*k*m+(k+1)/2)) + 
  Dist[1/(b*(j*k*m+(k+1)/2)),
    Int[(sin[c+d*x]^j)^(m+j*k)*(-a*n+b*(j*k*m+n+(k+3)/2)*sin[c+d*x]^k)*(a+b*sin[c+d*x]^k)^n,x]] /;
FreeQ[{a,b,c,d},x] && OneQ[j^2,k^2] && ZeroQ[a^2-b^2] && RationalQ[m,n] && 
  NonzeroQ[j*k*m+(k+1)/2] && j*k*m<=-1 && -1<n<0


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Derivation: Recurrence 12 with A=1 and B=0*)


(* ::Subsubsection:: *)
(*Rule 6: If  j^2=k^2=1 \[And] a^2-b^2=0 \[And] j k m<0 \[And] n<=-1, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral](Sin[c+d x]^j)^m (a+b Sin[c+d x]^k)^n \[DifferentialD]x  \[LongRightArrow]  *)
(*-((Cos[c+d x](Sin[c+d x]^j)^(m+j k) (a+b Sin[c+d x]^k)^n)/(d (2n+1)))+1/(a^2 (2n+1))\[CenterDot]*)
(* \[Integral](Sin[c+d x]^j)^m (a(j k m+2n+(k+3)/2)-b(j k m+n+(k+3)/2)Sin[c+d x]^k)(a+b Sin[c+d x]^k)^(n+1) \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[(sin[c_.+d_.*x_]^j_.)^m_.*(a_+b_.*sin[c_.+d_.*x_]^k_.)^n_,x_Symbol] :=
  -Cos[c+d*x]*(Sin[c+d*x]^j)^(m+j*k)*(a+b*Sin[c+d*x]^k)^n/(d*(2*n+1)) + 
  Dist[1/(a^2*(2*n+1)),
    Int[(sin[c+d*x]^j)^m*
      (a*(j*k*m+2*n+(k+3)/2)-b*(j*k*m+n+(k+3)/2)*sin[c+d*x]^k)*(a+b*sin[c+d*x]^k)^(n+1),x]] /;
FreeQ[{a,b,c,d},x] && OneQ[j^2,k^2] && ZeroQ[a^2-b^2] && RationalQ[m,n] && 
  j*k*m<0 && n<=-1


(* ::PageBreak:: *)
(**)
