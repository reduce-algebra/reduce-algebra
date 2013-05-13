(* ::Package:: *)

(* ::Title::Plain:: *)
(* Integration Rules for *)
(*\[Integral](sin^j(z))^m (A+B sin^k(z))(a+b sin^k(z))^n \[DifferentialD]z when j^2=1\[And]k^2=1*)


(* ::Subsubtitle::Plain::Closed:: *)
(*Domain Map *)


(* ::Input:: *)
(*Graphics[{{RGBColor[1., 0.3, 0.3], Rectangle[{-4, 1}, {-1, 4}]}, {GrayLevel[0], Inset[Style["Rule 1a\n\[LowerRightArrow]\[DownArrow]\[Diamond]", FontSize -> 10], {Rational[-5, 2], Rational[5, 2]}]}, {RGBColor[1., 0.5, 0.5], Rectangle[{-4, 0}, {-1, 1}]}, {GrayLevel[0], Inset[Style["Rule 1b \[LowerRightArrow]\[Diamond]", FontSize -> 10], {Rational[-5, 2], Rational[1, 2]}]}, {GrayLevel[1], Thickness[Large], Line[{{-1, 0}, {-1, 1}}], {RGBColor[0.5, 0.5, 1.], Rectangle[{-1, 1}, {0, 4}]}, {GrayLevel[0], Inset[Style["Rule 2\n\[DownArrow]\[DownArrow]\[Diamond] ", FontSize -> 10], {Rational[-1, 2], Rational[5, 2]}]}, {GrayLevel[0], Thickness[0.007], Dashing[{0.003, 0.02}], Line[{{-0.98, 3.98}, {-0.98, 1}}], {RGBColor[0.2, 1., 0.2], Dashing[{}], Rectangle[{1, -1}, {4, 4}], {GrayLevel[0], Inset[Style["Rule 3a\n\[LeftArrow]\[LeftArrow]\[Diamond]", FontSize -> 10], {Rational[5, 2], Rational[5, 2]}]}, {GrayLevel[0], Thickness[0.007], Dashing[{0.003, 0.02}], Line[{{1.02, -0.98}, {3.98, -0.98}}], {RGBColor[0.7, 1., 0.7], Dashing[{}], Rectangle[{0, 0}, {1, 4}], {GrayLevel[0], Inset[Style["Rule 3b\n\[LowerLeftArrow]\[Diamond]", FontSize -> 10], {Rational[1, 2], Rational[5, 2]}]}, {RGBColor[1, 0.5, 0.5], Rectangle[{1, -4}, {4, -1}]}, {GrayLevel[0], Inset[Style["Rule 4a\n\[UpperLeftArrow]\[LeftArrow]\[Diamond]", FontSize -> 10], {Rational[5, 2], Rational[-5, 2]}]}, {RGBColor[1., 0.8, 0.8], Rectangle[{0, -4}, {1, -1}]}, {GrayLevel[0], Inset[Style["Rule 4b\n\[UpperLeftArrow]\[Diamond]", FontSize -> 10], {Rational[1, 2], Rational[-5, 2]}]}, {RGBColor[1, 0, 1], Rectangle[{-1, -4}, {0, -1.02}]}, {GrayLevel[0], Inset[Style["Rule 5\n\[UpArrow]\[Diamond]", FontSize -> 10], {Rational[-1, 2], Rational[-5, 2]}]}, {GrayLevel[0], Thickness[0.007], Dashing[{0.003, 0.02}], Line[{{-0.98, -1.04}, {-0.98, -3.98}}], {RGBColor[1, 0.5, 0], Dashing[{}], Rectangle[{-4, -4}, {-1, 0}], {GrayLevel[0], Inset[Style["Rule 6\n\[RightArrow]\[Diamond]", FontSize -> 10], {Rational[-5, 2], Rational[-5, 2]}]}, {GrayLevel[1], Thickness[Large], Line[{{-1, -0.02}, {-1, -1}}]}, {RGBColor[0.2, 1., 0.2], Thickness[Large], Line[{{0, -3.98}, {0, -1.02}}], {GrayLevel[0], GeometricTransformation[Inset[Style["Rule 7 \[LeftArrow]", FontSize -> 10], {0.15, -3.25}], {{{0, 1}, {-1, 0}}, Center}]}, {RGBColor[0, 0, 1], Thickness[Large], Line[{{0, 0}, {0, 3.98}}], {GrayLevel[0], GeometricTransformation[Inset[Style["Rule 8 \[RightArrow]", FontSize -> 10], {0.15, 1.7}], {{{0, 1}, {-1, 0}}, Center}]}, {RGBColor[0.2, 1., 0.2], Thickness[Large], Line[{{-3.98, 0}, {-1, 0}}], {GrayLevel[0], Inset[Style["Rule 9 \[RightArrow]", FontSize -> 10], {Rational[-5, 2], 0.13}]}, {RGBColor[0, 0, 1], Thickness[Large], Line[{{0.02, 0}, {3.98, 0}}], {GrayLevel[0], Inset[Style["Rule 10 \[LeftArrow]", FontSize -> 10], {Rational[5, 2], 0.13}]}, {RGBColor[1, 1, 0], Thickness[Large], Line[{{1, -1.02}, {1, -3.98}}], {GrayLevel[0], GeometricTransformation[Inset[Style["Rule 11 \[LowerLeftArrow]", FontSize -> 10], {1.15, Rational[-5, 2]}], {{{0, 1}, {-1, 0}}, Center}]}, {RGBColor[1., 0.5, 1.], Thickness[Large], Line[{{1, 3.98}, {1, -1}}], {GrayLevel[0], GeometricTransformation[Inset[Style["Rule 12 \[DownArrow]", FontSize -> 10], {1.15, 2}], {{{0, 1}, {-1, 0}}, Center}]}, {RGBColor[1, 1, 0], Thickness[Large], Line[{{-3.98, 1}, {-1.04, 1}}], {GrayLevel[0], Inset[Style["Rule 13 \[LowerRightArrow]", FontSize -> 10], {Rational[-5, 2], 1.13}]}, {RGBColor[1., 0.5, 1.], Thickness[Large], Line[{{-1, 1}, {3.98, 1}}], {GrayLevel[0], Inset[Style["Rule 14 \[DownArrow]", FontSize -> 10], {Rational[5, 2], 1.13}]}, {RGBColor[0, 1, 1], Disk[{0, -1}, Scaled[Rational[1, 60]]]}, {GrayLevel[0], Inset["a", {0.01, -1}]}, {RGBColor[0, 1, 1], Disk[{0, Rational[1, 2]}, Scaled[Rational[1, 60]]]}, {GrayLevel[0], Inset["b", {0.01, Rational[1, 2]}]}, {RGBColor[0, 1, 1], Disk[{0, Rational[-1, 2]}, Scaled[Rational[1, 60]]]}, {GrayLevel[0], Inset["b", {0.01, Rational[-1, 2]}]}, {RGBColor[0, 1, 1], Disk[{1, 0}, Scaled[Rational[1, 60]]]}, {GrayLevel[0], Inset["c", {1.01, 0}]}, {RGBColor[0, 1, 1], Disk[{-1, 0}, Scaled[Rational[1, 60]]]}, {GrayLevel[0], Inset["d", {-0.99, 0}]}, {RGBColor[0, 1, 1], Disk[{Rational[-1, 2], 0}, Scaled[Rational[1, 60]]]}, {GrayLevel[0], Inset["e", {-0.49, 0}]}, {RGBColor[0, 1, 1], Disk[{Rational[-3, 2], 0}, Scaled[Rational[1, 60]]]}, {GrayLevel[0], Inset["f", {-1.49, 0}]}, {RGBColor[0, 1, 1], Disk[{Rational[1, 2], 0}, Scaled[Rational[1, 60]]]}, {GrayLevel[0], Inset["f", {0.51, 0}]}, {RGBColor[0, 1, 1], Disk[{-1, -1}, Scaled[Rational[1, 60]]]}, {GrayLevel[0], Inset["g", {-0.99, -1}]}, {RGBColor[0, 1, 1], Disk[{-1, Rational[1, 2]}, Scaled[Rational[1, 60]]]}, {GrayLevel[0], Inset["h", {-0.99, Rational[1, 2]}]}, {RGBColor[0, 1, 1], Disk[{-1, Rational[-1, 2]}, Scaled[Rational[1, 60]]]}, {GrayLevel[0], Inset["h", {-0.99, Rational[-1, 2]}]}, {RGBColor[0, 1, 1], Disk[{Rational[1, 2], -1}, Scaled[Rational[1, 60]]]}, {GrayLevel[0], Inset["i", {0.51, -1}]}, {RGBColor[0, 1, 1], Disk[{Rational[-1, 2], -1}, Scaled[Rational[1, 60]]]}, {GrayLevel[0], Inset["i", {-0.49, -1}]}, {RGBColor[0, 1, 1], Disk[{Rational[-1, 2], Rational[-1, 2]}, Scaled[Rational[1, 60]]]}, {GrayLevel[0], Inset["j", {-0.49, Rational[-1, 2]}]}, {RGBColor[0, 1, 1], Disk[{Rational[1, 2], Rational[-1, 2]}, Scaled[Rational[1, 60]]]}, {GrayLevel[0], Inset["k", {0.51, Rational[-1, 2]}]}, {RGBColor[0, 1, 1], Disk[{Rational[-1, 2], Rational[1, 2]}, Scaled[Rational[1, 60]]]}, {GrayLevel[0], Inset["k", {-0.49, Rational[1, 2]}]}, {RGBColor[0, 1, 1], Disk[{Rational[-1, 2], Rational[-3, 2]}, Scaled[Rational[1, 60]]]}, {GrayLevel[0], Inset["l", {-0.49, Rational[-3, 2]}]}, {RGBColor[0, 1, 1], Disk[{Rational[-3, 2], Rational[-1, 2]}, Scaled[Rational[1, 60]]]}, {GrayLevel[0], Inset["m", {-1.49, Rational[-1, 2]}]}, {RGBColor[0, 1, 1], Disk[{Rational[1, 2], Rational[-3, 2]}, Scaled[Rational[1, 60]]]}, {GrayLevel[0], Inset["n", {0.51, Rational[-3, 2]}]}, {RGBColor[0, 1, 1], Disk[{Rational[-3, 2], Rational[1, 2]}, Scaled[Rational[1, 60]]]}, {GrayLevel[0], Inset["o", {-1.49, Rational[1, 2]}]}}}}}}}}}}}}}}}}}, Axes -> True, AxesLabel -> {$CellContext`n, $CellContext`j $CellContext`k $CellContext`m}, ImageSize -> Medium]*)


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


(* ::Subsubtitle::Plain::Closed:: *)
(* Integration Rules for *)
(*\[Integral](sin^j(z))^m (A+B sin^k(z))\[DifferentialD]z when j^2=1\[And]k^2=1*)


(* ::Subsubtitle::Bold::Closed:: *)
(*Rule a:  \[Integral]Sin[c+d x]^j (A+B Sin[c+d x]^-j)\[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Derivation: Algebraic expansion*)


(* ::Subsubsection:: *)
(*Rule a: If  j^2=1, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]Sin[c+d x]^j (A+B Sin[c+d x]^-j)\[DifferentialD]x  \[LongRightArrow]  B x+A \[Integral]Sin[c+d x]^j \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[sin[c_.+d_.*x_]^j_.*(A_+B_.*sin[c_.+d_.*x_]^k_.),x_Symbol] :=
  B*x + Dist[A,Int[sin[c+d*x]^j,x]] /;
FreeQ[{c,d,A,B},x] && OneQ[j^2] && ZeroQ[j+k]


(* ::PageBreak:: *)
(**)


(* ::Subsubtitle::Bold::Closed:: *)
(*Rule b:  \[Integral](Sin[c+d x]^j)^(m/2) (A+B Sin[c+d x]^-j)\[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Derivation: Algebraic expansion*)


(* ::Subsubsection:: *)
(*Rule b1:*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]Sqrt[Sin[c+d x]](A+B Csc[c+d x])\[DifferentialD]x  \[LongRightArrow]  A\[Integral]Sqrt[Sin[c+d x]]\[DifferentialD]x +B \[Integral]1/Sqrt[Sin[c+d x]] \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[Sqrt[sin[c_.+d_.*x_]]*(A_+B_.*sin[c_.+d_.*x_]^(-1)),x_Symbol] :=
  Dist[A,Int[Sqrt[sin[c+d*x]],x]] + 
  Dist[B,Int[1/Sqrt[sin[c+d*x]],x]] /;
FreeQ[{c,d,A,B},x]


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Derivation: Piecewise constant extraction*)


(* ::Subsubsection:: *)
(*Basis: \!\( *)
(*\*SubscriptBox[\(\[PartialD]\), \(z\)]\(( *)
(*\*SuperscriptBox[\(f[z]\), \(m\)] *)
(*\*SuperscriptBox[\((1/f[z])\), \(m\)])\)\)=0*)


(* ::Subsubsection:: *)
(*Note: For some strange reason, Mathematica overly agressively evaluates 1/(Sqrt[f[z]] Sqrt[1/f[z]]) to Sqrt[f[z]] Sqrt[1/f[z]].*)


(* ::Subsubsection:: *)
(*Rule b2: If  m^2=1, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]Csc[c+d x]^(m/2) (A+B Sin[c+d x])\[DifferentialD]x  \[LongRightArrow]  Sin[c+d x]^(m/2) Csc[c+d x]^(m/2) \[Integral](A+B Sin[c+d x])/Sin[c+d x]^(m/2) \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[(sin[c_.+d_.*x_]^(-1))^m_*(A_.+B_.*sin[c_.+d_.*x_]),x_Symbol] :=
  Dist[Sin[c+d*x]^m*Csc[c+d*x]^m,Int[(A+B*sin[c+d*x])/sin[c+d*x]^m,x]] /;
FreeQ[{c,d,A,B},x] && ZeroQ[m^2-1/4]


(* ::PageBreak:: *)
(**)


(* ::Subsubtitle::Bold::Closed:: *)
(*Rules 7-8:  \[Integral](Sin[c+d x]^j)^m (A+B Sin[c+d x]^k)\[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Derivation: Rule 5 with a=1, b=0 and  n=0*)


(* ::Subsubsection:: *)
(*Rule 7: If  j^2=k^2=1 \[And] j k m<-1, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral](Sin[c+d x]^j)^m (A+B Sin[c+d x]^k)\[DifferentialD]x  \[LongRightArrow]  ((A Cos[c+d x](Sin[c+d x]^j)^(m+j k))/(d(j k m+(k+1)/2)))+*)
(*1/(j k m+(k+1)/2) \[Integral](Sin[c+d x]^j)^(m+j k) (B(j k m+(k+1)/2)+A(j k m+(k+3)/2)Sin[c+d x]^k )\[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[(sin[c_.+d_.*x_]^j_.)^m_*(A_+B_.*sin[c_.+d_.*x_]^k_.),x_Symbol] :=
  A*Cos[c+d*x]*(Sin[c+d*x]^j)^(m+j*k)/(d*(j*k*m+(k+1)/2)) + 
  Dist[1/(j*k*m+(k+1)/2),
    Int[(sin[c+d*x]^j)^(m+j*k)*Sim[B*(j*k*m+(k+1)/2)+A*(j*k*m+(k+3)/2)*sin[c+d*x]^k,x],x]] /;
FreeQ[{c,d,A,B},x] && OneQ[j^2,k^2] && RationalQ[m] && j*k*m<-1


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Derivation: Rule 3b with n=0*)


(* ::Subsubsection:: *)
(*Rule 8: If  j^2=k^2=1 \[And] j k m>0 \[And] m^2!=1, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral](Sin[c+d x]^j)^m (A+B Sin[c+d x]^k)\[DifferentialD]x  \[LongRightArrow]  -((B Cos[c+d x](Sin[c+d x]^j)^m)/(d (j k m+(k+1)/2)))+*)
(*1/(j k m+(k+1)/2) \[Integral](Sin[c+d x]^j)^(m-j k)  (B (j k m+(k-1)/2)+A (j k m+(k+1)/2) Sin[c+d x]^k)\[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[(sin[c_.+d_.*x_]^j_.)^m_*(A_+B_.*sin[c_.+d_.*x_]^k_.),x_Symbol] :=
  -B*Cos[c+d*x]*(Sin[c+d*x]^j)^m/(d*(j*k*m+(k+1)/2)) + 
  Dist[1/(j*k*m+(k+1)/2),
    Int[(sin[c+d*x]^j)^(m-j*k)*(B*(j*k*m+(k-1)/2)+A*(j*k*m+(k+1)/2)*sin[c+d*x]^k),x]] /;
FreeQ[{c,d,A,B},x] && OneQ[j^2,k^2] && RationalQ[m] && j*k*m>0 && m^2!=1


(* ::PageBreak:: *)
(**)


(* ::Title::Plain::Closed:: *)
(* Integration Rules for *)
(*\[Integral](A+B sin^k(z))(a+b sin^k(z))^n \[DifferentialD]z when k^2=1*)


(* ::Subsubtitle::Bold::Closed:: *)
(*Rule c:  \[Integral](A+B Sin[c+d x]^k) (a+b Sin[c+d x]^k)\[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Derivation: Rule 3a with m=0 and n=1*)


(* ::Subsubsection:: *)
(*Rule c: If  k^2=1, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral](A+B Sin[c+d x]^k) (a+b Sin[c+d x]^k)\[DifferentialD]x  \[LongRightArrow] *)
(*(((4 a A+b B(k+1))x)/4)-(2b B Cos[c+d x]Sin[c+d x]^k)/(d(k+3))+(b A+a B)\[Integral]Sin[c+d x]^k \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[(A_.+B_.*sin[c_.+d_.*x_]^k_.)*(a_+b_.*sin[c_.+d_.*x_]^k_.),x_Symbol] :=
  (4*a*A+b*B*(k+1))*x/4 - (2*b*B*Cos[c+d*x]*Sin[c+d*x]^k)/(d*(k+3)) + (b*A+a*B)*Int[sin[c+d*x]^k,x] /;
FreeQ[{a,b,c,d,A,B},x] && OneQ[k^2]


(* ::PageBreak:: *)
(**)


(* ::Subsubtitle::Bold::Closed:: *)
(*Rule d:  \[Integral](A+B Sin[c+d x]^k)/(a+b Sin[c+d x]^k) \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Derivation: Algebraic simplification*)


(* ::Subsubsection:: *)
(*Basis: If  b A-a B=0, then (A+B z)/(a+b z)=B/b*)


(* ::Subsubsection:: *)
(*Rule d1: If  k^2=1 \[And] b A-a B=0, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral](A+B Sin[c+d x]^k)/(a+b Sin[c+d x]^k) \[DifferentialD]x  \[LongRightArrow]  ((B x)/b)*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[(A_+B_.*sin[c_.+d_.*x_]^k_.)/(a_+b_.*sin[c_.+d_.*x_]^k_.),x_Symbol] :=
  B*x/b /;
FreeQ[{a,b,c,d,A,B},x] && OneQ[k^2] && ZeroQ[b*A-a*B]


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Reference: G&R 2.551.2*)


(* ::Subsubsection:: *)
(*Derivation: Algebraic expansion*)


(* ::Subsubsection:: *)
(*Basis: (A+B z)/(a+b z)=B/b+(b A-a B)/(b(a+b z))*)


(* ::Subsubsection:: *)
(*Rule d2: If  a^2-b^2!=0 \[And] b A-a B!=0, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral](A+B Sin[c+d x])/(a+b Sin[c+d x]) \[DifferentialD]x  \[LongRightArrow]  ((B x)/b)+(b A-a B)/b \[Integral]1/(a+b Sin[c+d x]) \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[(A_.+B_.*sin[c_.+d_.*x_])/(a_+b_.*sin[c_.+d_.*x_]),x_Symbol] :=
  B*x/b + Dist[(b*A-a*B)/b,Int[1/(a+b*sin[c+d*x]),x]] /;
FreeQ[{a,b,c,d,A,B},x] && NonzeroQ[a^2-b^2] && NonzeroQ[b*A-a*B]


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Derivation: Algebraic expansion*)


(* ::Subsubsection:: *)
(*Basis: (A+B/z)/(a+b/z)=A/a-(b A-a B)/(a(b+a z))*)


(* ::Subsubsection:: *)
(*Rule d3: If  a^2-b^2!=0 \[And] b A-a B!=0, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral](A+B Csc[c+d x])/(a+b Csc[c+d x]) \[DifferentialD]x  \[LongRightArrow]  ((A x)/a)-(b A-a B)/a \[Integral]1/(b+a Sin[c+d x]) \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[(A_.+B_.*sin[c_.+d_.*x_]^(-1))/(a_+b_.*sin[c_.+d_.*x_]^(-1)),x_Symbol] :=
  A*x/a - Dist[(b*A-a*B)/a,Int[1/(b+a*sin[c+d*x]),x]] /;
FreeQ[{a,b,c,d,A,B},x] && NonzeroQ[a^2-b^2] && NonzeroQ[b*A-a*B]


(* ::PageBreak:: *)
(**)


(* ::Subsubtitle::Bold::Closed:: *)
(*Rule e:  \[Integral](A+B Sin[c+d x])/Sqrt[a+b Sin[c+d x]] \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Derivation: Algebraic expansion*)


(* ::Subsubsection:: *)
(*Basis: (A+B z)/Sqrt[a+b z]=B/b Sqrt[a+b z]+(b A-a B)/b 1/Sqrt[a+b z]*)


(* ::Subsubsection:: *)
(*Rule e: If  a^2-b^2!=0 \[And] b A-a B!=0, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral](A+B Sin[c+d x])/Sqrt[a+b Sin[c+d x]] \[DifferentialD]x  \[LongRightArrow]  (B/b)\[Integral]Sqrt[a+b Sin[c+d x]]\[DifferentialD]x+(b A-a B)/b \[Integral]1/Sqrt[a+b Sin[c+d x]] \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[(A_.+B_.*sin[c_.+d_.*x_])/Sqrt[a_.+b_.*sin[c_.+d_.*x_]],x_Symbol] :=
  Dist[B/b,Int[Sqrt[a+b*sin[c+d*x]],x]] +
  Dist[(b*A-a*B)/b,Int[1/Sqrt[a+b*sin[c+d*x]],x]] /;
FreeQ[{a,b,c,d,A,B},x] && NonzeroQ[a^2-b^2] && NonzeroQ[b*A-a*B]


(* ::PageBreak:: *)
(**)


(* ::Subsubtitle::Bold::Closed:: *)
(*Rule f:  \[Integral](A+B Csc[c+d x])(a+b Csc[c+d x])^(n/2) \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Derivation: Piecewise constant extraction*)


(* ::Subsubsection:: *)
(*Basis: \!\( *)
(*\*SubscriptBox[\(\[PartialD]\), \(z\)]*)
(*\*FractionBox[\(1\), \( *)
(*\*SqrtBox[\(f[z]\)] *)
(*\*SqrtBox[\(b/f[z]\)]\)]\)=0*)


(* ::Subsubsection:: *)
(*Rule f1:*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral](A+B Csc[c+d x])/Sqrt[b Csc[c+d x]] \[DifferentialD]x  \[LongRightArrow]  (1/(Sqrt[Sin[c+d x]] Sqrt[b Csc[c+d x]]))\[Integral](B+A Sin[c+d x])/Sqrt[Sin[c+d x]] \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[(A_+B_.*sin[c_.+d_.*x_]^(-1))/Sqrt[b_.*sin[c_.+d_.*x_]^(-1)],x_Symbol] :=
  Dist[1/(Sqrt[Sin[c+d*x]]*Sqrt[b*Csc[c+d*x]]),Int[(B+A*sin[c+d*x])/Sqrt[sin[c+d*x]],x]] /;
FreeQ[{b,c,d,A,B},x]


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
(*Rule f2: If  a^2-b^2!=0 \[And] b A-a B!=0 \[And] n-1/2\[Element]\[DoubleStruckCapitalZ] \[And] -2<n<1, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral](A+B Csc[c+d x])(a+b Csc[c+d x])^n \[DifferentialD]x  \[LongRightArrow]  *)
(*(Sqrt[b+a Sin[c+d x]]/(Sqrt[Sin[c+d x]] Sqrt[a+b Csc[c+d x]]))\[Integral]((B+A Sin[c+d x])(b+a Sin[c+d x])^n)/Sin[c+d x]^(n+1) \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[(A_.+B_.*sin[c_.+d_.*x_]^(-1))*(a_+b_.*sin[c_.+d_.*x_]^(-1))^n_,x_Symbol] :=
  Dist[Sqrt[b+a*Sin[c+d*x]]/(Sqrt[Sin[c+d*x]]*Sqrt[a+b*Csc[c+d*x]]),
    Int[(B+A*sin[c+d*x])*(b+a*sin[c+d*x])^n/sin[c+d*x]^(n+1),x]] /;
FreeQ[{a,b,c,d,A,B},x] && NonzeroQ[a^2-b^2] && NonzeroQ[b*A-a*B] && IntegerQ[n-1/2] && -2<n<1


(* ::PageBreak:: *)
(**)


(* ::Subsubtitle::Bold::Closed:: *)
(*\[Integral](A+B Sin[c+d x]^k) (a+b Sin[c+d x]^k)^n \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Derivation: Algebraic simplification*)


(* ::Subsubsection:: *)
(*Basis: If  b A-a B=0, then (A+B z) (a+b z)^n=B/b (a+b z)^(n+1)*)


(* ::Subsubsection:: *)
(*Rule: If  k^2=1 \[And] b A=a B \[And] n<0, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral](A+B Sin[c+d x]^k) (a+b Sin[c+d x]^k)^n \[DifferentialD]x  \[LongRightArrow]  (B/b)\[Integral](a+b Sin[c+d x]^k)^(n+1) \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[(A_.+B_.*sin[c_.+d_.*x_]^k_.)*(a_.+b_.*sin[c_.+d_.*x_]^k_.)^n_,x_Symbol] :=
  Dist[B/b,Int[(a+b*sin[c+d*x]^k)^(n+1),x]] /;
FreeQ[{a,b,c,d,A,B,n},x] && OneQ[k^2] && ZeroQ[b*A-a*B] && RationalQ[n] && n<0


(* ::PageBreak:: *)
(**)


(* ::Subsubtitle::Bold::Closed:: *)
(*Rules 17-18:  \[Integral](A+B Csc[c+d x]) (a+b Csc[c+d x])^n \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Derivation: Rule 6 with m=0 and k=-1*)


(* ::Subsubsection:: *)
(*Rule 17: If  a^2-b^2!=0 \[And] b A-a B!=0 \[And] n<-1, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral](A+B Csc[c+d x]) (a+b Csc[c+d x])^n \[DifferentialD]x  \[LongRightArrow]  *)
(*((b(b A-a B) Cot[c+d x](a+b Csc[c+d x])^(n+1))/(a d (n+1) (a^2-b^2)))+1/(a (n+1) (a^2-b^2)) \[CenterDot]*)
(*\[Integral](A (a^2-b^2) (n+1)-a(b A-a B)(n+1)Csc[c+d x]+b(b A-a B)(n+2)Csc[c+d x]^2)(a+b Csc[c+d x])^(n+1) \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[(A_+B_.*sin[c_.+d_.*x_]^(-1))*(a_+b_.*sin[c_.+d_.*x_]^(-1))^n_,x_Symbol] :=
  b*(b*A-a*B)*Cot[c+d*x]*(a+b*Csc[c+d*x])^(n+1)/(a*d*(n+1)*(a^2-b^2)) + 
  Dist[1/(a*(n+1)*(a^2-b^2)),
    Int[Sim[A*(a^2-b^2)*(n+1)-(a*(b*A-a*B)*(n+1))*sin[c+d*x]^(-1)+
        (b*(b*A-a*B)*(n+2))*sin[c+d*x]^(-2),x]*
      (a+b*sin[c+d*x]^(-1))^(n+1),x]] /;
FreeQ[{a,b,c,d,A,B},x] && NonzeroQ[a^2-b^2] && NonzeroQ[b*A-a*B] && RationalQ[n] && n<-1


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Derivation: Rule 3a with m=0 and k=-1*)


(* ::Subsubsection:: *)
(*Rule 18: If  a^2-b^2!=0 \[And] n>1, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral](A+B Csc[c+d x]) (a+b Csc[c+d x])^n \[DifferentialD]x  \[LongRightArrow]  *)
(*-((b B Cot[c+d x](a+b Csc[c+d x])^(n-1))/(d n))+1/n\[CenterDot]*)
(*\[Integral](a^2 A n+(b^2 B (n-1)+2 a A b n+a^2 B n)Csc[c+d x]+b(b A n+a B (2 n-1))Csc[c+d x]^2)(a+b Csc[c+d x])^(n-2) \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[(A_+B_.*sin[c_.+d_.*x_]^(-1))*(a_+b_.*sin[c_.+d_.*x_]^(-1))^n_,x_Symbol] :=
  -b*B*Cot[c+d*x]*(a+b*Csc[c+d*x])^(n-1)/(d*n) + 
  Dist[1/n,
    Int[Sim[a^2*A*n+(b^2*B*(n-1)+2*a*A*b*n+a^2*B*n)*sin[c+d*x]^(-1)+
        (b*(b*A*n+a*B*(2*n-1)))*sin[c+d*x]^(-2),x]*
      (a+b*sin[c+d*x]^(-1))^(n-2),x]] /;
FreeQ[{a,b,c,d,A,B},x] && NonzeroQ[a^2-b^2] && RationalQ[n] && n>1


(* ::PageBreak:: *)
(**)


(* ::Subsubtitle::Bold::Closed:: *)
(*Rules 15-16:  \[Integral](A+B Sin[c+d x]^k) (b Sin[c+d x]^k)^n \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Derivation: Rule 10a inverted*)


(* ::Subsubsection:: *)
(*Rule 15: If  k^2=1 \[And] n<-1, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral](A+B Sin[c+d x]^k)(b Sin[c+d x]^k)^n \[DifferentialD]x \[LongRightArrow]  ((2 A Cos[c+d x] (b Sin[c+d x]^k)^(n+1))/(b d (2 n+k+1)))+*)
(*1/(b(2 n+k+1)) \[Integral](B(2 n+k+1)+A(2n+k+3) Sin[c+d x]^k) (b Sin[c+d x]^k)^(n+1) \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[(A_+B_.*sin[c_.+d_.*x_]^k_.)*(b_.*sin[c_.+d_.*x_]^k_.)^n_,x_Symbol] :=
  2*A*Cos[c+d*x]*(b*Sin[c+d*x]^k)^(n+1)/(b*d*(2*n+k+1)) + 
  Dist[1/(b*(2*n+k+1)),
    Int[Sim[B*(2*n+k+1)+A*(2*n+k+3)*sin[c+d*x]^k,x]*(b*sin[c+d*x]^k)^(n+1),x]] /;
FreeQ[{b,c,d,A,B},x] && OneQ[k^2] && RationalQ[n] && n<-1


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Derivation: Rule 3a or 3b with m=0 and a=0*)


(* ::Subsubsection:: *)
(*Rule 16: If  k^2=1 \[And] n>0, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral](A+B Sin[c+d x]^k) (b Sin[c+d x]^k)^n \[DifferentialD]x  \[LongRightArrow]  -((2B Cos[c+d x](b Sin[c+d x]^k)^n)/(d (2n+k+1)))+*)
(*1/(2n+k+1) \[Integral](b B(2n+k-1)+b A(2n+k+1)Sin[c+d x]^k)(b Sin[c+d x]^k)^(n-1) \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[(A_+B_.*sin[c_.+d_.*x_]^k_.)*(b_.*sin[c_.+d_.*x_]^k_.)^n_,x_Symbol] :=
  -2*B*Cos[c+d*x]*(b*Sin[c+d*x]^k)^n/(d*(2*n+k+1)) + 
  Dist[1/(2*n+k+1),
    Int[Sim[b*B*(2*n+k-1)+b*A*(2*n+k+1)*sin[c+d*x]^k,x]*(b*sin[c+d*x]^k)^(n-1),x]] /;
FreeQ[{b,c,d,A,B},x] && OneQ[k^2] && RationalQ[n] && n>0


(* ::PageBreak:: *)
(**)


(* ::Title::Plain::Closed:: *)
(* Integration Rules for *)
(*\[Integral](sin^j(z))^m (A+B sin^k(z))(a+b sin^k(z))^n \[DifferentialD]z when j^2=1\[And]k^2=1*)


(* ::Subsubtitle::Bold::Closed:: *)
(*Rule g:  \[Integral](A+B Sin[c+d x])/(Sin[c+d x](a+b Sin[c+d x])) \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Derivation: Algebraic expansion*)


(* ::Subsubsection:: *)
(*Basis: (A+B z)/(z(a+b z))=A/(a z)-(b A-a B)/(a(a+b z))*)


(* ::Subsubsection:: *)
(*Rule g: If  a B-b A!=0, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral](A+B Sin[c+d x])/(Sin[c+d x](a+b Sin[c+d x])) \[DifferentialD]x  \[LongRightArrow]  (A/a)\[Integral]1/Sin[c+d x] \[DifferentialD]x-(b A-a B)/a \[Integral]1/(a+b Sin[c+d x]) \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[(A_+B_.*sin[c_.+d_.*x_])/(sin[c_.+d_.*x_]*(a_+b_.*sin[c_.+d_.*x_])),x_Symbol] :=
  Dist[A/a,Int[1/sin[c+d*x],x]] - 
  Dist[(b*A-a*B)/a,Int[1/(a+b*sin[c+d*x]),x]] /;
FreeQ[{a,b,c,d,A,B},x] && NonzeroQ[b*A-a*B]


(* ::PageBreak:: *)
(**)


(* ::Subsubtitle::Bold::Closed:: *)
(*Rule h:  \[Integral](Sin[c+d x]^(m/2) (A+B Sin[c+d x]))/(a+b Sin[c+d x]) \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Derivation: Algebraic expansion*)


(* ::Subsubsection:: *)
(*Basis: (A+B z)/(a+b z)=B/b+(b A-a B)/(b(a+b z))*)


(* ::Subsubsection:: *)
(*Rule h: If  a^2-b^2!=0 \[And] b A-a B!=0 \[And] m^2=1, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral](Sin[c+d x]^(m/2) (A+B Sin[c+d x]))/(a+b Sin[c+d x]) \[DifferentialD]x  \[LongRightArrow] (B/b) \[Integral]Sin[c+d x]^(m/2) \[DifferentialD]x+(b A-a B)/b \[Integral]Sin[c+d x]^(m/2)/(a+b Sin[c+d x]) \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[sin[c_.+d_.*x_]^m_*(A_+B_.*sin[c_.+d_.*x_])/(a_+b_.*sin[c_.+d_.*x_]),x_Symbol] :=
  Dist[B/b,Int[sin[c+d*x]^m,x]] + 
  Dist[(b*A-a*B)/b,Int[sin[c+d*x]^m/(a+b*sin[c+d*x]),x]] /;
FreeQ[{a,b,c,d,A,B},x] && NonzeroQ[a^2-b^2] && NonzeroQ[b*A-a*B] && ZeroQ[m^2-1/4]


(* ::PageBreak:: *)
(**)


(* ::Subsubtitle::Bold::Closed:: *)
(*Rule i:  \[Integral]((A+B Sin[c+d x]) (a+b Sin[c+d x])^(n/2))/Sin[c+d x] \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Derivation: Algebraic expansion*)


(* ::Subsubsection:: *)
(*Basis: (A+B z)/z=B+A 1/z*)


(* ::Subsubsection:: *)
(*Rule i: If  a^2-b^2!=0 \[And] n^2=1, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]((A+B Sin[c+d x]) (a+b Sin[c+d x])^(n/2))/Sin[c+d x] \[DifferentialD]x  \[LongRightArrow]  *)
(*B\[Integral](a+b Sin[c+d x])^(n/2) \[DifferentialD]x+A \[Integral](a+b Sin[c+d x])^(n/2)/Sin[c+d x] \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[(A_+B_.*sin[c_.+d_.*x_])*(a_+b_.*sin[c_.+d_.*x_])^n_/sin[c_.+d_.*x_],x_Symbol] :=
  Dist[B,Int[(a+b*sin[c+d*x])^n,x]] + 
  Dist[A,Int[(a+b*sin[c+d*x])^n/sin[c+d*x],x]] /;
FreeQ[{a,b,c,d,A,B},x] && NonzeroQ[a^2-b^2] && ZeroQ[n^2-1/4]


(* ::PageBreak:: *)
(**)


(* ::Subsubtitle::Bold::Closed:: *)
(*Rule j:  \[Integral](A+B Sin[c+d x])/(Sqrt[Sin[c+d x]] Sqrt[a+b Sin[c+d x]]) \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Derivation: Algebraic expansion*)


(* ::Subsubsection:: *)
(*Rule j: If  a^2-b^2!=0 \[And] A-B!=0, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral](A+B Sin[c+d x])/(Sqrt[Sin[c+d x]] Sqrt[a+b Sin[c+d x]]) \[DifferentialD]x  \[LongRightArrow]  *)
(*B\[Integral](1+Sin[c+d x])/(Sqrt[Sin[c+d x]] Sqrt[a+b Sin[c+d x]]) \[DifferentialD]x+(A-B)\[Integral]1/(Sqrt[Sin[c+d x]] Sqrt[a+b Sin[c+d x]]) \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[(A_+B_.*sin[c_.+d_.*x_])/(Sqrt[sin[c_.+d_.*x_]]*Sqrt[a_+b_.*sin[c_.+d_.*x_]]),x_Symbol] :=
  B*Int[(1+sin[c+d*x])/(Sqrt[sin[c+d*x]]*Sqrt[a+b*sin[c+d*x]]),x] + 
  (A-B)*Int[1/(Sqrt[sin[c+d*x]]*Sqrt[a+b*sin[c+d*x]]),x] /;
FreeQ[{a,b,c,d,A,B},x] && NonzeroQ[a^2-b^2] && NonzeroQ[A-B]


(* ::PageBreak:: *)
(**)


(* ::Subsubtitle::Bold::Closed:: *)
(*Rule k:  \[Integral]((A+B Sin[c+d x])Sqrt[a+b Sin[c+d x]])/Sqrt[e+f Sin[c+d x]] \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Derivation: Algebraic transformation*)


(* ::Subsubsection:: *)
(*Basis: (A+B z)Sqrt[a+b z]=(a A+(b A+a B) z+b B z^2)/Sqrt[a+b z]*)


(* ::Subsubsection:: *)
(*Rule k: If  a^2-b^2!=0 \[And] e^2-f^2!=0, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]((A+B Sin[c+d x])Sqrt[a+b Sin[c+d x]])/Sqrt[e+f Sin[c+d x]] \[DifferentialD]x  \[LongRightArrow]  \[Integral](a A+(b A+a B) Sin[c+d x]+b B Sin[c+d x]^2)/(Sqrt[a+b Sin[c+d x]] Sqrt[e+f Sin[c+d x]]) \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[(A_+B_.*sin[c_.+d_.*x_])*Sqrt[a_.+b_.*sin[c_.+d_.*x_]]/Sqrt[e_.+f_.*sin[c_.+d_.*x_]],x_Symbol] :=
  Int[(a*A+(b*A+a*B)*sin[c+d*x]+b*B*sin[c+d*x]^2)/(Sqrt[a+b*sin[c+d*x]]*Sqrt[e+f*sin[c+d*x]]),x] /;
FreeQ[{a,b,c,d,e,f,A,B},x] && NonzeroQ[a^2-b^2] && NonzeroQ[e^2-f^2]


(* ::PageBreak:: *)
(**)


(* ::Subsubtitle::Bold::Closed:: *)
(*Rule l:  \[Integral](A+B Sin[c+d x])/(Sin[c+d x]^(3/2) Sqrt[a+b Sin[c+d x]]) \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Note: This rule is not essential, but produces simpler results.*)


(* ::Subsubsection:: *)
(*Rule l1: If  a^2-b^2!=0, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral](A-A Sin[c+d x])/(Sin[c+d x]^(3/2) Sqrt[a+b Sin[c+d x]]) \[DifferentialD]x  \[LongRightArrow]  *)
(*((2 A Sqrt[a+b Sin[c+d x]] Tan[1/2 (c-\[Pi]/2+d x)])/(a d Sqrt[Sin[c+d x]]))-(2 A)/a \[Integral]Sqrt[a+b Sin[c+d x]]/(Sqrt[Sin[c+d x]] (1+Sin[c+d x])) \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[(A_+B_.*sin[c_.+d_.*x_])/(sin[c_.+d_.*x_]^(3/2)*Sqrt[a_+b_.*sin[c_.+d_.*x_]]),x_Symbol] :=
  2*A*Sqrt[a+b*Sin[c+d*x]]*Tan[(c-Pi/2+d*x)/2]/(a*d*Sqrt[Sin[c+d*x]]) - 
  2*A/a*Int[Sqrt[a+b*sin[c+d*x]]/(Sqrt[sin[c+d*x]]*(1+sin[c+d*x])),x] /;
FreeQ[{a,b,c,d,A,B},x] && NonzeroQ[a^2-b^2] && ZeroQ[A+B]


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Derivation: Algebraic expansion*)


(* ::Subsubsection:: *)
(*Note: This rule is not essential, but produces simpler results.*)


(* ::Subsubsection:: *)
(*Rule l2: If  a^2-b^2!=0 \[And] A+B!=0, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral](A+B Sin[c+d x])/(Sin[c+d x]^(3/2) Sqrt[a+b Sin[c+d x]]) \[DifferentialD]x  \[LongRightArrow]  *)
(*(A+B)\[Integral]1/(Sqrt[Sin[c+d x]] Sqrt[a+b Sin[c+d x]]) \[DifferentialD]x+A \[Integral](1-Sin[c+d x])/(Sin[c+d x]^(3/2) Sqrt[a+b Sin[c+d x]]) \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[(A_+B_.*sin[c_.+d_.*x_])/(sin[c_.+d_.*x_]^(3/2)*Sqrt[a_+b_.*sin[c_.+d_.*x_]]),x_Symbol] :=
  Dist[A+B,Int[1/(Sqrt[sin[c+d*x]]*Sqrt[a+b*sin[c+d*x]]),x]] + 
  Dist[A,Int[(1-sin[c+d*x])/(sin[c+d*x]^(3/2)*Sqrt[a+b*sin[c+d*x]]),x]] /;
FreeQ[{a,b,c,d,A,B},x] && NonzeroQ[a^2-b^2] && NonzeroQ[A+B]


(* ::PageBreak:: *)
(**)


(* ::Subsubtitle::Bold::Closed:: *)
(*Rule m:  \[Integral](A+B Sin[c+d x])/(Sqrt[Sin[c+d x]] (a+b Sin[c+d x])^(3/2)) \[DifferentialD]x*)


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Note: This rule is not essential, but produces simpler results.*)


(* ::Subsubsection:: *)
(*Rule m1: If  a^2-b^2!=0, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral](A+A Sin[c+d x])/(Sqrt[Sin[c+d x]] (a+b Sin[c+d x])^(3/2)) \[DifferentialD]x  \[LongRightArrow]  *)
(*((2A(a-b) Sqrt[Sin[c+d x]] Tan[1/2 (c-\[Pi]/2+d x)])/(a d(a+b) Sqrt[a+b Sin[c+d x]]))+(2 A)/(a(a+b)) \[Integral]Sqrt[a+b Sin[c+d x]]/(Sqrt[Sin[c+d x]] (1+Sin[c+d x])) \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[(A_+B_.*sin[c_.+d_.*x_])/(Sqrt[sin[c_.+d_.*x_]]*(a_+b_.*sin[c_.+d_.*x_])^(3/2)),x_Symbol] :=
  2*A*(a-b)*Sqrt[Sin[c+d*x]]*Tan[(c-Pi/2+d*x)/2]/(a*d*(a+b)*Sqrt[a+b*Sin[c+d*x]]) + 
  Dist[2*A/(a*(a+b)),Int[Sqrt[a+b*sin[c+d*x]]/(Sqrt[sin[c+d*x]]*(1+sin[c+d*x])),x]] /;
FreeQ[{a,b,c,d,A,B},x] && NonzeroQ[a^2-b^2] && ZeroQ[A-B]


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Derivation: Algebraic expansion*)


(* ::Subsubsection:: *)
(*Note: This rule is not essential, but produces simpler results.*)


(* ::Subsubsection:: *)
(*Rule m2: If  a^2-b^2!=0 \[And] b A-a B!=0 \[And] A-B!=0, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral](A+B Sin[c+d x])/(Sqrt[Sin[c+d x]] (a+b Sin[c+d x])^(3/2)) \[DifferentialD]x  \[LongRightArrow]  *)
(*((A-B)/(a-b))\[Integral]1/(Sqrt[Sin[c+d x]] Sqrt[a+b Sin[c+d x]]) \[DifferentialD]x-(b A-a B)/(a-b) \[Integral](1+Sin[c+d x])/(Sqrt[Sin[c+d x]] (a+b Sin[c+d x])^(3/2)) \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[(A_+B_.*sin[c_.+d_.*x_])/(Sqrt[sin[c_.+d_.*x_]]*(a_+b_.*sin[c_.+d_.*x_])^(3/2)),x_Symbol] :=
  Dist[(A-B)/(a-b),Int[1/(Sqrt[sin[c+d*x]]*Sqrt[a+b*sin[c+d*x]]),x]] - 
  Dist[(b*A-a*B)/(a-b),Int[(1+sin[c+d*x])/(Sqrt[sin[c+d*x]]*(a+b*sin[c+d*x])^(3/2)),x]] /;
FreeQ[{a,b,c,d,A,B},x] && NonzeroQ[a^2-b^2] && NonzeroQ[b*A-a*B] && NonzeroQ[A-B]


(* ::PageBreak:: *)
(**)


(* ::Subsubtitle::Bold::Closed:: *)
(*Rule n:  \[Integral]((A+B Sin[c+d x])Sqrt[a+b Sin[c+d x]])/Sin[c+d x]^(3/2) \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Derivation: Algebraic expansion*)


(* ::Subsubsection:: *)
(*Note: This rule is not essential, but produces simpler results.*)


(* ::Subsubsection:: *)
(*Rule n: If  a^2-b^2!=0, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]((A+B Sin[c+d x])Sqrt[a+b Sin[c+d x]])/Sin[c+d x]^(3/2) \[DifferentialD]x  \[LongRightArrow]  *)
(*(b (A-B)+a (A+B))\[Integral]1/(Sqrt[Sin[c+d x]] Sqrt[a+b Sin[c+d x]]) \[DifferentialD]x+\[Integral](a A-(a A-b B) Sin[c+d x]+b B Sin[c+d x]^2)/(Sin[c+d x]^(3/2) Sqrt[a+b Sin[c+d x]]) \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[(A_+B_.*sin[c_.+d_.*x_])*Sqrt[a_+b_.*sin[c_.+d_.*x_]]/sin[c_.+d_.*x_]^(3/2),x_Symbol] :=
  (b*(A-B)+a*(A+B))*Int[1/(Sqrt[sin[c+d*x]]*Sqrt[a+b*sin[c+d*x]]),x] + 
  Int[Sim[a*A-(a*A-b*B)*sin[c+d*x]+b*B*sin[c+d*x]^2,x]/(sin[c+d*x]^(3/2)*Sqrt[a+b*sin[c+d*x]]),x] /;
FreeQ[{a,b,c,d,A,B},x] && NonzeroQ[a^2-b^2]


(* ::PageBreak:: *)
(**)


(* ::Subsubtitle::Bold::Closed:: *)
(*Rule o:  \[Integral](Sqrt[Sin[c+d x]] (A+B Sin[c+d x]))/(a+b Sin[c+d x])^(3/2) \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Derivation: Algebraic expansion*)


(* ::Subsubsection:: *)
(*Note: This rule is not essential, but produces simpler results.*)


(* ::Subsubsection:: *)
(*Rule o: If  a^2-b^2!=0 \[And] b A-a B!=0, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral](Sqrt[Sin[c+d x]] (A+B Sin[c+d x]))/(a+b Sin[c+d x])^(3/2) \[DifferentialD]x  \[LongRightArrow]  *)
(*(B/b)\[Integral](1+Sin[c+d x])/(Sqrt[Sin[c+d x]] Sqrt[a+b Sin[c+d x]]) \[DifferentialD]x+1/b \[Integral](-a B+(A b-(a+b) B) Sin[c+d x])/(Sqrt[Sin[c+d x]] (a+b Sin[c+d x])^(3/2)) \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[Sqrt[sin[c_.+d_.*x_]]*(A_+B_.*sin[c_.+d_.*x_])/(a_+b_.*sin[c_.+d_.*x_])^(3/2),x_Symbol] :=
  B/b*Int[(1+sin[c+d*x])/(Sqrt[sin[c+d*x]]*Sqrt[a+b*sin[c+d*x]]),x] + 
  Dist[1/b,Int[Sim[-a*B+(A*b-(a+b)*B)*sin[c+d*x],x]/(Sqrt[sin[c+d*x]]*(a+b*sin[c+d*x])^(3/2)),x]] /;
FreeQ[{a,b,c,d,A,B},x] && NonzeroQ[a^2-b^2] && NonzeroQ[b*A-a*B]


(* ::PageBreak:: *)
(**)


(* ::Subsubtitle::Bold::Closed:: *)
(*Rule p:  \[Integral](Sin[c+d x]^j)^m (A+B Sin[c+d x]^k)(b Sin[c+d x]^k)^n \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Derivation: Algebraic simplification*)


(* ::Subsubsection:: *)
(*Rule p1: If  k^2=1 \[And] m\[Element]\[DoubleStruckCapitalZ], then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]Sin[c+d x]^m (A+B Sin[c+d x]^k)(b Sin[c+d x]^k)^n \[DifferentialD]x  \[LongRightArrow]  *)
(*(1/b^(k m))\[Integral](A+B Sin[c+d x]^k)(b Sin[c+d x]^k)^(k m+n) \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[sin[c_.+d_.*x_]^m_.*(A_+B_.*sin[c_.+d_.*x_]^k_.)*(b_.*sin[c_.+d_.*x_]^k_.)^n_,x_Symbol] :=
  Dist[1/b^(k*m),Int[(A+B*sin[c+d*x]^k)*(b*sin[c+d*x]^k)^(k*m+n),x]] /;
FreeQ[{b,c,d,A,B,n},x] && OneQ[k^2] && IntegerQ[m]


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
(*Rule p2: If  j^2=k^2=1 \[And] m-1/2\[Element]\[DoubleStruckCapitalZ] \[And] n-1/2\[Element]\[DoubleStruckCapitalZ] \[And] n>0, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral](Sin[c+d x]^j)^m (A+B Sin[c+d x]^k)(b Sin[c+d x]^k)^n \[DifferentialD]x  \[LongRightArrow]  *)
(*((b^(n-1/2) Sqrt[b Sin[c+d x]^k])/(Sqrt[Sin[c+d x]^j])^(j k))\[Integral]Sin[c+d x]^(j m+k n) (A+B Sin[c+d x]^k)\[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[(sin[c_.+d_.*x_]^j_.)^m_*(A_+B_.*sin[c_.+d_.*x_]^k_.)*(b_*sin[c_.+d_.*x_]^k_.)^n_,x_Symbol] :=
  Dist[b^(n-1/2)*Sqrt[b*Sin[c+d*x]^k]/(Sqrt[Sin[c+d*x]^j])^(j*k),
    Int[sin[c+d*x]^(j*m+k*n)*(A+B*sin[c+d*x]^k),x]] /;
FreeQ[{b,c,d,A,B},x] && OneQ[j^2,k^2] && IntegerQ[m-1/2] && IntegerQ[n-1/2] && n>0


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
(*Rule p3: If  j^2=k^2=1 \[And] m-1/2\[Element]\[DoubleStruckCapitalZ] \[And] n-1/2\[Element]\[DoubleStruckCapitalZ] \[And] n<0, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral](Sin[c+d x]^j)^m (A+B Sin[c+d x]^k)(b Sin[c+d x]^k)^n \[DifferentialD]x  \[LongRightArrow]  *)
(*((b^(n+1/2) (Sqrt[Sin[c+d x]^j])^(j k))/Sqrt[b Sin[c+d x]^k])\[Integral]Sin[c+d x]^(j m+k n) (A+B Sin[c+d x]^k)\[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[(sin[c_.+d_.*x_]^j_.)^m_*(A_+B_.*sin[c_.+d_.*x_]^k_.)*(b_*sin[c_.+d_.*x_]^k_.)^n_,x_Symbol] :=
  Dist[b^(n+1/2)*(Sqrt[Sin[c+d*x]^j])^(j*k)/Sqrt[b*Sin[c+d*x]^k],
    Int[sin[c+d*x]^(j*m+k*n)*(A+B*sin[c+d*x]^k),x]] /;
FreeQ[{b,c,d,A,B},x] && OneQ[j^2,k^2] && IntegerQ[m-1/2] && IntegerQ[n-1/2] && n<0


(* ::PageBreak:: *)
(**)


(* ::Subsubtitle::Bold::Closed:: *)
(*Rule q:  \[Integral](Sin[c+d x]^j)^m (A+B Csc[c+d x])(a+b Csc[c+d x])^n \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Derivation: Algebraic simplification*)


(* ::Subsubsection:: *)
(*Rule q1: If  j^2=1 \[And] a^2-b^2!=0 \[And] -1<m<=1, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]((Sin[c+d x]^j)^m (A+B Csc[c+d x]))/(a+b Csc[c+d x]) \[DifferentialD]x  \[LongRightArrow]  \[Integral]((Sin[c+d x]^j)^m (B+A Sin[c+d x]))/(b+a Sin[c+d x]) \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[(sin[c_.+d_.*x_]^j_.)^m_.*(A_.+B_.*sin[c_.+d_.*x_]^(-1))/(a_+b_.*sin[c_.+d_.*x_]^(-1)),x_Symbol] :=
  Int[(sin[c+d*x]^j)^m*(B+A*sin[c+d*x])/(b+a*sin[c+d*x]),x] /;
FreeQ[{a,b,c,d,A,B},x] && OneQ[j^2] && NonzeroQ[a^2-b^2] && RationalQ[m] && -1<m<=1


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
(*Rule q2: If  a^2-b^2!=0 \[And] m\[Element]\[DoubleStruckCapitalZ] \[And] n-1/2\[Element]\[DoubleStruckCapitalZ] \[And] ((m=1 \[And] -1<n<1) \[Or] (m=-1 \[And] -2<n<0)), then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]Sin[c+d x]^m (A+B Csc[c+d x])(a+b Csc[c+d x])^n \[DifferentialD]x  \[LongRightArrow]  *)
(*( Sqrt[b+a Sin[c+d x]]/(Sqrt[Sin[c+d x]] Sqrt[a+b Csc[c+d x]]))\[Integral]Sin[c+d x]^(m-n-1) (B+A Sin[c+d x]) (b+a Sin[c+d x])^n \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[sin[c_.+d_.*x_]^m_.*(A_.+B_.*sin[c_.+d_.*x_]^(-1))*(a_.+b_.*sin[c_.+d_.*x_]^(-1))^n_,x_Symbol] :=
  Dist[Sqrt[b+a*Sin[c+d*x]]/(Sqrt[Sin[c+d*x]]*Sqrt[a+b*Csc[c+d*x]]),
    Int[sin[c+d*x]^(m-n-1)*(B+A*sin[c+d*x])*(b+a*sin[c+d*x])^n,x]] /;
FreeQ[{a,b,c,d,A,B},x] && NonzeroQ[a^2-b^2] && IntegerQ[m] && IntegerQ[n-1/2] &&
  (m==1 && -1<n<1 || m==-1 && -2<n<0)


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
(*\*SqrtBox[\(a + b\ *)
(*\*SuperscriptBox[\(f[z]\), \(-1\)]\)]\)]\)=0*)


(* ::Subsubsection:: *)
(*Rule q3: If  j^2=1 \[And] a^2-b^2!=0 \[And] m-1/2\[Element]\[DoubleStruckCapitalZ] \[And] n-1/2\[Element]\[DoubleStruckCapitalZ] \[And] 0<=j m-n<=1, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral](Sin[c+d x]^j)^m (A+B Csc[c+d x])(a+b Csc[c+d x])^n \[DifferentialD]x  \[LongRightArrow]  *)
(*( Sqrt[b+a Sin[c+d x]]/(Sqrt[Sin[c+d x]^j]^j Sqrt[a+b Csc[c+d x]]))\[Integral]Sin[c+d x]^(j m-n-1) (B+A Sin[c+d x])(b+a Sin[c+d x])^n \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[(sin[c_.+d_.*x_]^j_.)^m_*(A_.+B_.*sin[c_.+d_.*x_]^(-1))*(a_.+b_.*sin[c_.+d_.*x_]^(-1))^n_,x_Symbol] :=
  Dist[Sqrt[b+a*Sin[c+d*x]]/((Sqrt[Sin[c+d*x]^j])^j*Sqrt[a+b*Csc[c+d*x]]),
    Int[sin[c+d*x]^(j*m-n-1)*(B+A*sin[c+d*x])*(b+a*sin[c+d*x])^n,x]] /;
FreeQ[{a,b,c,d,A,B},x] && OneQ[j^2] && NonzeroQ[a^2-b^2] && 
  IntegerQ[m-1/2] && IntegerQ[n-1/2] && -1<n<1 && 0<=j*m-n<=1


(* ::PageBreak:: *)
(**)


(* ::Subsubtitle::Bold::Closed:: *)
(*Rule r:  \[Integral]Csc[c+d x]^m (A+B Sin[c+d x])(a+b Sin[c+d x])^n \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Derivation: Piecewise constant extraction*)


(* ::Subsubsection:: *)
(*Basis: \!\( *)
(*\*SubscriptBox[\(\[PartialD]\), \(z\)]\(( *)
(*\*SqrtBox[\(f[z]\)] *)
(*\*SqrtBox[\(1/f[z]\)])\)\)=0*)


(* ::Subsubsection:: *)
(*Rule r: If  m-1/2\[Element]\[DoubleStruckCapitalZ] \[And] -1<m<2 \[And] -2<n<1, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]Csc[c+d x]^m (A+B Sin[c+d x])(a+b Sin[c+d x])^n \[DifferentialD]x  \[LongRightArrow]  *)
(*Sqrt[Csc[c+d x]] Sqrt[Sin[c+d x]]\[Integral]((A+B Sin[c+d x])(a+b Sin[c+d x])^n)/Sin[c+d x]^m \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[(sin[c_.+d_.*x_]^(-1))^m_*(A_.+B_.*sin[c_.+d_.*x_])*(a_+b_.*sin[c_.+d_.*x_])^n_,x_Symbol] :=
  Dist[Sqrt[Csc[c+d*x]]*Sqrt[Sin[c+d*x]],
    Int[(A+B*sin[c+d*x])*(a+b*sin[c+d*x])^n/sin[c+d*x]^m,x]] /;
FreeQ[{a,b,c,d,A,B},x] && IntegerQ[m-1/2] && RationalQ[n] && -1<m<2 && -2<n<1


(* ::PageBreak:: *)
(**)


(* ::Subsubtitle::Bold::Closed:: *)
(*Rules 13-14:  \[Integral]Sin[c+d x](A+B Sin[c+d x])(a+b Sin[c+d x])^n \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Derivation: Rule 1a with j m=1 and k=1*)


(* ::Subsubsection:: *)
(*Rule 13: If  a^2-b^2!=0 \[And] b A-a B!=0 \[And] n<-1, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]Sin[c+d x](A+B Sin[c+d x]) (a+b Sin[c+d x])^n \[DifferentialD]x  \[LongRightArrow]  *)
(*((a (b A-a B) Cos[c+d x](a+b Sin[c+d x])^(n+1))/(b d(n+1)(a^2-b^2)))-1/(b(n+1) (a^2-b^2))\[CenterDot]*)
(*\[Integral](b (n+1)(b A-a B)+(a^2 B-a b A(n+2)+b^2 B(n+1)) Sin[c+d x]) (a+b Sin[c+d x])^(n+1) \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[sin[c_.+d_.*x_]*(A_+B_.*sin[c_.+d_.*x_])*(a_+b_.*sin[c_.+d_.*x_])^n_,x_Symbol] :=
  a*(b*A-a*B)*Cos[c+d*x]*(a+b*Sin[c+d*x])^(n+1)/(b*d*(n+1)*(a^2-b^2)) - 
  Dist[1/(b*(n+1)*(a^2-b^2)),
    Int[Sim[b*(n+1)*(b*A-a*B)+(a^2*B-a*b*A*(n+2)+b^2*B*(n+1))*sin[c+d*x],x]*
      (a+b*sin[c+d*x])^(n+1),x]] /;
FreeQ[{a,b,c,d,A,B},x] && NonzeroQ[a^2-b^2] && NonzeroQ[b*A-a*B] && RationalQ[n] && n<-1


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Derivation: Rule 14b with n=-1*)


(* ::Subsubsection:: *)
(*Note: This is an unnecessary special case of rule 14b, but it saves a trivial step.*)


(* ::Subsubsection:: *)
(*Rule 14a: If  b A-a B!=0, then*)


(* ::Input:: *)
(* *)


(* ::Subsubtitle::Bold:: *)
(*\[Integral](Sin[c+d x] (A+B Sin[c+d x]))/(a+b Sin[c+d x]) \[DifferentialD]x  \[LongRightArrow]  -((B Cos[c+d x])/(b d))+(b A-a B)/b \[Integral]Sin[c+d x]/(a+b Sin[c+d x]) \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[sin[c_.+d_.*x_]*(A_+B_.*sin[c_.+d_.*x_])/(a_+b_.*sin[c_.+d_.*x_]),x_Symbol] :=
  -B*Cos[c+d*x]/(b*d) + 
  Dist[(b*A-a*B)/b,Int[sin[c+d*x]/(a+b*sin[c+d*x]),x]] /;
FreeQ[{a,b,c,d,A,B},x] && NonzeroQ[b*A-a*B]


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Derivation: Rule 2 with j m=1 and k=1*)


(* ::Subsubsection:: *)
(*Rule 14b: If  n>-1 \[And] n!=1, then*)


(* ::Input:: *)
(* *)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]Sin[c+d x](A+B Sin[c+d x]) (a+b Sin[c+d x])^n \[DifferentialD]x  \[LongRightArrow]  *)
(*-((B Cos[c+d x](a+b Sin[c+d x])^(n+1))/(b d (n+2)))+*)
(*1/(b (n+2)) \[Integral](b B (n+1)-(a B-b A(n+2)) Sin[c+d x])(a+b Sin[c+d x])^n \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[sin[c_.+d_.*x_]*(A_+B_.*sin[c_.+d_.*x_])*(a_+b_.*sin[c_.+d_.*x_])^n_,x_Symbol] :=
  -B*Cos[c+d*x]*(a+b*Sin[c+d*x])^(n+1)/(b*d*(n+2)) + 
  Dist[1/(b*(n+2)),Int[Sim[b*B*(n+1)-(a*B-b*A*(n+2))*sin[c+d*x],x]*(a+b*sin[c+d*x])^n,x]] /;
FreeQ[{a,b,c,d,A,B},x] && RationalQ[n] && n>-1 && n!=1


(* ::PageBreak:: *)
(**)


(* ::Subsubtitle::Bold::Closed:: *)
(*Rules 11-12:  \[Integral](Sin[c+d x]^j)^m (A+B Sin[c+d x]^k) (a+b Sin[c+d x]^k)\[DifferentialD]x   j k m<-1???*)


(* ::Subsubsection:: *)
(*Derivation: Rule 4a with n=1*)


(* ::Subsubsection:: *)
(*Rule 11: If  j^2=k^2=1 \[And] a^2-b^2!=0 \[And] b A-a B!=0 \[And] j k m+(k+1)/2!=0  \[And] j k m<=-1 , then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral](Sin[c+d x]^j)^m (A+B Sin[c+d x]^k) (a+b Sin[c+d x]^k)\[DifferentialD]x  \[LongRightArrow]  *)
(*((a A Cos[c+d x] (Sin[c+d x]^j)^(m+j k))/(d(j k m+(k+1)/2)))+1/(j k m+(k+1)/2)\[CenterDot]*)
(*\[Integral](Sin[c+d x]^j)^(m+j k) ((b A+a B) (j k m+(k+1)/2)+(a A (j k m+(k+3)/2)+b B (j k m+(k+1)/2)) Sin[c+d x]^k)\[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[(sin[c_.+d_.*x_]^j_.)^m_.*(A_+B_.*sin[c_.+d_.*x_]^k_.)*(a_+b_.*sin[c_.+d_.*x_]^k_.),x_Symbol] :=
  a*A*Cos[c+d*x]*(Sin[c+d*x]^j)^(m+j*k)/(d*(j*k*m+(k+1)/2)) + 
  Dist[1/(j*k*m+(k+1)/2),
    Int[(sin[c+d*x]^j)^(m+j*k)*
      Sim[(b*A+a*B)*(j*k*m+(k+1)/2)+(a*A*(j*k*m+(k+3)/2)+b*B*(j*k*m+(k+1)/2))*sin[c+d*x]^k,x],x]] /;
FreeQ[{a,b,c,d,A,B},x] && OneQ[j^2,k^2] && NonzeroQ[a^2-b^2] && 
  RationalQ[m] && j*k*m+(k+1)/2!=0 && j*k*m<=-1


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Derivation: Rule 3a with n=1*)


(* ::Subsubsection:: *)
(*Rule 12: If  j^2=k^2=1 \[And] a^2-b^2!=0 \[And] b A-a B!=0 \[And] j k m>=-1, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral](Sin[c+d x]^j)^m (A+B Sin[c+d x]^k) (a+b Sin[c+d x]^k)\[DifferentialD]x  \[LongRightArrow]  *)
(*-((b B Cos[c+d x](Sin[c+d x]^j)^(m+j k))/(d (j k m+(k+3)/2)))+1/(j k m+(k+3)/2)\[CenterDot]*)
(*\[Integral](Sin[c+d x]^j)^m (a A (j k m+(k+3)/2)+b B (j k m+(k+1)/2)+(b A+a B) (j k m+(k+3)/2) Sin[c+d x]^k)\[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[(sin[c_.+d_.*x_]^j_.)^m_.*(A_+B_.*sin[c_.+d_.*x_]^k_.)*(a_+b_.*sin[c_.+d_.*x_]^k_.),x_Symbol] :=
  -b*B*Cos[c+d*x]*(Sin[c+d*x]^j)^(m+j*k)/(d*(j*k*m+(k+3)/2)) + 
  Dist[1/(j*k*m+(k+3)/2),
    Int[(sin[c+d*x]^j)^m*
      Sim[a*A*(j*k*m+(k+3)/2)+b*B*(j*k*m+(k+1)/2)+(b*A+a*B)*(j*k*m+(k+3)/2)*sin[c+d*x]^k,x],x]] /;
FreeQ[{a,b,c,d,A,B},x] && OneQ[j^2,k^2] && NonzeroQ[a^2-b^2] && 
  RationalQ[m] && j*k*m>=-1


(* ::PageBreak:: *)
(**)


(* ::Subsubtitle::Bold::Closed:: *)
(*Rules 9-10:  \[Integral]Sin[c+d x]^((k-1)/2) (A+B Sin[c+d x]^k)(a+b Sin[c+d x]^k)^n \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Reference: G&R 2.551.1*)


(* ::Subsubsection:: *)
(*Derivation: Rule 1b with j m=(k-1)/2*)


(* ::Subsubsection:: *)
(*Rule 9: If  k^2=1 \[And] a^2-b^2!=0 \[And] b A-a B!=0 \[And] n<-1, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]Sin[c+d x]^((k-1)/2) (A+B Sin[c+d x]^k) (a+b Sin[c+d x]^k)^n \[DifferentialD]x  \[LongRightArrow]  *)
(*-(((b A-a B) Cos[c+d x]Sin[c+d x]^((k-1)/2) (a+b Sin[c+d x]^k)^(n+1))/(d (n+1) (a^2-b^2)))+*)
(*1/((n+1) (a^2-b^2)) \[Integral]Sin[c+d x]^((k-1)/2) ((a A-b B)(n+1)-(b A-a B)(n+2)Sin[c+d x]^k) (a+b Sin[c+d x]^k)^(n+1) \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[(A_.+B_.*sin[c_.+d_.*x_])*(a_+b_.*sin[c_.+d_.*x_])^n_,x_Symbol] :=
  -(b*A-a*B)*Cos[c+d*x]*(a+b*Sin[c+d*x])^(n+1)/(d*(n+1)*(a^2-b^2)) +
  Dist[1/((n+1)*(a^2-b^2)),
    Int[Sim[(a*A-b*B)*(n+1)-(b*A-a*B)*(n+2)*sin[c+d*x],x]*(a+b*sin[c+d*x])^(n+1),x]] /;
FreeQ[{a,b,c,d,A,B},x] && NonzeroQ[a^2-b^2] && NonzeroQ[b*A-a*B] && RationalQ[n] && n<-1


(* ::Code:: *)
Int[sin[c_.+d_.*x_]^(-1)*(A_.+B_.*sin[c_.+d_.*x_]^(-1))*(a_+b_.*sin[c_.+d_.*x_]^(-1))^n_,x_Symbol] :=
  -(b*A-a*B)*Cot[c+d*x]*(a+b*Csc[c+d*x])^(n+1)/(d*(n+1)*(a^2-b^2)) + 
  Dist[1/((n+1)*(a^2-b^2)),
    Int[sin[c+d*x]^(-1)*
      Sim[(a*A-b*B)*(n+1)-(b*A-a*B)*(n+2)*sin[c+d*x]^(-1),x]*(a+b*sin[c+d*x]^(-1))^(n+1),x]] /;
FreeQ[{a,b,c,d,A,B},x] && NonzeroQ[a^2-b^2] && NonzeroQ[b*A-a*B] && RationalQ[n] && n<-1


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Reference: G&R 2.551.1 inverted*)


(* ::Subsubsection:: *)
(*Derivation: Rule 3b with j m=(k-1)/2*)


(* ::Subsubsection:: *)
(*Rule 10: If  k^2=1 \[And] a^2-b^2!=0 \[And] n>0 \[And] n!=1, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]Sin[c+d x]^((k-1)/2) (A+B Sin[c+d x]^k) (a+b Sin[c+d x]^k)^n \[DifferentialD]x  \[LongRightArrow]  *)
(*-((B Cos[c+d x]Sin[c+d x]^((k-1)/2) (a+b Sin[c+d x]^k)^n)/(d (n+1)))+*)
(*1/(n+1) \[Integral]Sin[c+d x]^((k-1)/2) (b B n+a A (n+1)+(a B n+b A (n+1)) Sin[c+d x]^k) (a+b Sin[c+d x]^k)^(n-1) \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[(A_.+B_.*sin[c_.+d_.*x_])*(a_.+b_.*sin[c_.+d_.*x_])^n_,x_Symbol] :=
  -B*Cos[c+d*x]*(a+b*Sin[c+d*x])^n/(d*(n+1)) + 
  Dist[1/(n+1),
    Int[Sim[b*B*n+a*A*(n+1)+(a*B*n+b*A*(n+1))*sin[c+d*x],x]*(a+b*sin[c+d*x])^(n-1),x]] /;
FreeQ[{a,b,c,d,A,B},x] && RationalQ[n] && n>0 && n!=1


(* ::Code:: *)
Int[sin[c_.+d_.*x_]^(-1)*(A_.+B_.*sin[c_.+d_.*x_]^(-1))*(a_+b_.*sin[c_.+d_.*x_]^(-1))^n_,x_Symbol] :=
  -B*Cot[c+d*x]*(a+b*Csc[c+d*x])^n/(d*(n+1)) + 
  Dist[1/(n+1),
    Int[sin[c+d*x]^(-1)*
      Sim[b*B*n+a*A*(n+1)+(a*B*n+b*A*(n+1))*sin[c+d*x]^(-1),x]*(a+b*sin[c+d*x]^(-1))^(n-1),x]] /;
FreeQ[{a,b,c,d,A,B},x] && RationalQ[n] && n>0 && n!=1


(* ::PageBreak:: *)
(**)


(* ::Subsubtitle::Bold::Closed:: *)
(*Rules 1-6:  \[Integral](Sin[c+d x]^j)^m (A+B Sin[c+d x]^k) (a+b Sin[c+d x]^k)^n \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Derivation: Rule 1a, 1b or 6 with b A-a B=0*)


(* ::Subsubsection:: *)
(*Derivation: Algebraic simplification*)


(* ::Subsubsection:: *)
(*Basis: If  b A-a B=0, then A+B z=B/b (a+b z)*)


(* ::Subsubsection:: *)
(*Rule: If  j^2=k^2=1 \[And] b A-a B=0 \[And] n<=-1, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral](Sin[c+d x]^j)^m (A+B Sin[c+d x]^k) (a+b Sin[c+d x]^k)^n \[DifferentialD]x  \[LongRightArrow]  *)
(*(B/b)\[Integral](Sin[c+d x]^j)^m (a+b Sin[c+d x]^k)^(n+1) \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[(sin[c_.+d_.*x_]^j_.)^m_.*(A_.+B_.*sin[c_.+d_.*x_]^k_.)*(a_+b_.*sin[c_.+d_.*x_]^k_.)^n_,x_Symbol] :=
  Dist[B/b,Int[(sin[c+d*x]^j)^m*(a+b*sin[c+d*x]^k)^(n+1),x]] /;
FreeQ[{a,b,c,d,A,B,m},x] && OneQ[j^2,k^2] && ZeroQ[b*A-a*B] && RationalQ[n] && n<0


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Derivation: Recurrence 1 with A=0, B=A, C=B and m=m-1*)


(* ::Subsubsection:: *)
(*Rule 1a: If  j^2=k^2=1 \[And] a^2-b^2!=0 \[And] b A-a B!=0 \[And] j k m>1 \[And] n<-1, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral](Sin[c+d x]^j)^m (A+B Sin[c+d x]^k) (a+b Sin[c+d x]^k)^n \[DifferentialD]x  \[LongRightArrow]  *)
(*((a(b A-a B) Cos[c+d x] (Sin[c+d x]^j)^(m-j k) (a+b Sin[c+d x]^k)^(n+1))/(b d (n+1) (a^2-b^2)))-*)
(*1/(b(n+1)(a^2-b^2)) \[Integral](Sin[c+d x]^j)^(m-2j k)\[CenterDot]*)
(*(a(b A-a B)(j k m+(k-3)/2)+b(b A-a B)(n+1)Sin[c+d x]^k-(b(a A-b B)(n+1)+a(b A-a B)(j k m+(k-1)/2))Sin[c+d x]^(2k))\[CenterDot]*)
(*(a+b Sin[c+d x]^k)^(n+1)\[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[(sin[c_.+d_.*x_]^j_.)^m_*(A_.+B_.*sin[c_.+d_.*x_]^k_.)*(a_+b_.*sin[c_.+d_.*x_]^k_.)^n_,x_Symbol] :=
  a*(b*A-a*B)*Cos[c+d*x]*(Sin[c+d*x]^j)^(m-j*k)*(a+b*Sin[c+d*x]^k)^(n+1)/(b*d*(n+1)*(a^2-b^2)) - 
  Dist[1/(b*(n+1)*(a^2-b^2)),
    Int[(sin[c+d*x]^j)^(m-2*j*k)*
      Sim[a*(b*A-a*B)*(j*k*m+(k-3)/2)+b*(b*A-a*B)*(n+1)*sin[c+d*x]^k-
        (b*(a*A-b*B)*(n+1)+a*(b*A-a*B)*(j*k*m+(k-1)/2))*sin[c+d*x]^(2*k),x]*
      (a+b*sin[c+d*x]^k)^(n+1),x]] /;
FreeQ[{a,b,c,d,A,B},x] && OneQ[j^2,k^2] && NonzeroQ[a^2-b^2] && NonzeroQ[b*A-a*B] && 
  RationalQ[m,n] && j*k*m>1 && n<-1


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Derivation: Recurrence 1 with C=0*)


(* ::Subsubsection:: *)
(*Derivation: Recurrence 6 with A=0, B=A, C=B and m=m-1*)


(* ::Subsubsection:: *)
(*Rule 1b: If  j^2=k^2=1 \[And] a^2-b^2!=0 \[And] b A-a B!=0 \[And] 0<j k m<1  \[And] n<-1, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral](Sin[c+d x]^j)^m (A+B Sin[c+d x]^k) (a+b Sin[c+d x]^k)^n \[DifferentialD]x  \[LongRightArrow]  *)
(*-(((b A-a B) Cos[c+d x] (Sin[c+d x]^j)^m (a+b Sin[c+d x]^k)^(n+1))/(d (n+1) (a^2-b^2)))+*)
(*1/((n+1)(a^2-b^2)) \[Integral](Sin[c+d x]^j)^(m-j k)\[CenterDot]*)
(*((b A-a B)(j k m+(k-1)/2)+(a A-b B)(n+1)Sin[c+d x]^k-(b A-a B)(j k m+n+(k+3)/2)Sin[c+d x]^(2k))\[CenterDot]*)
(*(a+b Sin[c+d x]^k)^(n+1)\[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[(sin[c_.+d_.*x_]^j_.)^m_*(A_.+B_.*sin[c_.+d_.*x_]^k_.)*(a_+b_.*sin[c_.+d_.*x_]^k_.)^n_,x_Symbol] :=
  -(b*A-a*B)*Cos[c+d*x]*(Sin[c+d*x]^j)^m*(a+b*Sin[c+d*x]^k)^(n+1)/(d*(n+1)*(a^2-b^2)) + 
  Dist[1/((n+1)*(a^2-b^2)),
    Int[(sin[c+d*x]^j)^(m-j*k)*
      Sim[(b*A-a*B)*(j*k*m+(k-1)/2)+(a*A-b*B)*(n+1)*sin[c+d*x]^k-
        (b*A-a*B)*(j*k*m+n+(k+3)/2)*sin[c+d*x]^(2*k),x]*
      (a+b*sin[c+d*x]^k)^(n+1),x]] /;
FreeQ[{a,b,c,d,A,B},x] && OneQ[j^2,k^2] && NonzeroQ[a^2-b^2] && NonzeroQ[b*A-a*B] && 
  RationalQ[m,n] && 0<j*k*m<1 && n<-1


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Derivation: Recurrence 2 with A=0, B=A, C=B and m=m-1*)


(* ::Subsubsection:: *)
(*Rule 2: If  j^2=k^2=1 \[And] a^2-b^2!=0 \[And] j k m>1 \[And] -1<=n<0, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral](Sin[c+d x]^j)^m (A+B Sin[c+d x]^k) (a+b Sin[c+d x]^k)^n \[DifferentialD]x  \[LongRightArrow]  *)
(*-((B Cos[c+d x](Sin[c+d x]^j)^(m-j k) (a+b Sin[c+d x]^k)^(n+1))/(b d (j k m+n+(k+1)/2)))+*)
(*1/(b (j k m+n+(k+1)/2)) \[Integral](Sin[c+d x]^j)^(m-2j k)\[CenterDot]*)
(*(a B (j k m+(k-3)/2)+b B(j k m+n+(k-1)/2)Sin[c+d x]^k+(b A(n+1)+(b A-a B)(j k m+(k-1)/2))Sin[c+d x]^(2k))\[CenterDot]*)
(*(a+b Sin[c+d x]^k)^n\[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[(sin[c_.+d_.*x_]^j_.)^m_*(A_.+B_.*sin[c_.+d_.*x_]^k_.)*(a_+b_.*sin[c_.+d_.*x_]^k_.)^n_,x_Symbol] :=
  -B*Cos[c+d*x]*(Sin[c+d*x]^j)^(m-j*k)*(a+b*Sin[c+d*x]^k)^(n+1)/(b*d*(j*k*m+n+(k+1)/2)) + 
  Dist[1/(b*(j*k*m+n+(k+1)/2)),
    Int[(sin[c+d*x]^j)^(m-2*j*k)*
      Sim[a*B*(j*k*m+(k-3)/2)+b*B*(j*k*m+n+(k-1)/2)*sin[c+d*x]^k+
        (b*A*(n+1)+(b*A-a*B)*(j*k*m+(k-1)/2))*sin[c+d*x]^(2*k),x]*
      (a+b*sin[c+d*x]^k)^n,x]] /;
FreeQ[{a,b,c,d,A,B},x] && OneQ[j^2,k^2] && NonzeroQ[a^2-b^2] && RationalQ[m,n] && 
  j*k*m>1 && -1<=n<0


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Derivation: Recurrence 3 with A=a A, B=b A+a B, C=b B and n=n-1*)


(* ::Subsubsection:: *)
(*Rule 3a: If  j^2=k^2=1 \[And] a^2-b^2!=0 \[And] j k m>=-1 \[And] j k m!=1 \[And] n>1, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral](Sin[c+d x]^j)^m (A+B Sin[c+d x]^k) (a+b Sin[c+d x]^k)^n \[DifferentialD]x  \[LongRightArrow]  *)
(*-((b B Cos[c+d x](Sin[c+d x]^j)^(m+j k) (a+b Sin[c+d x]^k)^(n-1))/(d (j k m+n+(k+1)/2)))+*)
(*1/(j k m+n+(k+1)/2) \[Integral](Sin[c+d x]^j)^m\[CenterDot]*)
(*(a (a A n+(a A+b B)(j k m+(k+1)/2))+(a (2b A+a B)+(a^2 B+2 a b A+b^2 B)(j k m+n+(k-1)/2))Sin[c+d x]^k+b(a B (n-1)+(b A+a B) (j k m+n+(k+1)/2))Sin[c+d x]^(2k))\[CenterDot]*)
(*(a+b Sin[c+d x]^k)^(n-2)\[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[(sin[c_.+d_.*x_]^j_.)^m_.*(A_.+B_.*sin[c_.+d_.*x_]^k_.)*(a_+b_.*sin[c_.+d_.*x_]^k_.)^n_.,x_Symbol] :=
  -b*B*Cos[c+d*x]*(Sin[c+d*x]^j)^(m+j*k)*(a+b*Sin[c+d*x]^k)^(n-1)/(d*(j*k*m+n+(k+1)/2)) + 
  Dist[1/(j*k*m+n+(k+1)/2),
    Int[(sin[c+d*x]^j)^m*
      Sim[a*(a*A*n+(a*A+b*B)*(j*k*m+(k+1)/2))+
        (a*(2*b*A+a*B)+(a^2*B+2*a*b*A+b^2*B)*(j*k*m+n+(k-1)/2))*sin[c+d*x]^k+
        b*(a*B*(n-1)+(b*A+a*B)*(j*k*m+n+(k+1)/2))*sin[c+d*x]^(2*k),x]*
      (a+b*sin[c+d*x]^k)^(n-2),x]] /;
FreeQ[{a,b,c,d,A,B},x] && OneQ[j^2,k^2] && NonzeroQ[a^2-b^2] && RationalQ[m,n] && 
  j*k*m>=-1 && j*k*m!=1 && n>1


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Derivation: Recurrence 2 with A=a A, B=b A+a B, C=b B and n=n-1*)


(* ::Subsubsection:: *)
(*Derivation: Recurrence 3 with A=0, B=A, C=B and m=m-1*)


(* ::Subsubsection:: *)
(*Rule 3b: If  j^2=k^2=1 \[And] a^2-b^2!=0 \[And] j k m>0 \[And] j k m!=1 \[And] 0<n<1, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral](Sin[c+d x]^j)^m (A+B Sin[c+d x]^k) (a+b Sin[c+d x]^k)^n \[DifferentialD]x  \[LongRightArrow]  *)
(*-((B Cos[c+d x](Sin[c+d x]^j)^m (a+b Sin[c+d x]^k)^n)/(d (j k m+n+(k+1)/2)))+*)
(*1/(j k m+n+(k+1)/2) \[Integral](Sin[c+d x]^j)^(m-j k)\[CenterDot]*)
(*(a B(j k m+(k-1)/2)+(a A+(a A+b B)(j k m+n+(k-1)/2))Sin[c+d x]^k+(n(b A+a B)+b A(j k m+(k+1)/2))Sin[c+d x]^(2k))\[CenterDot]*)
(*(a+b Sin[c+d x]^k)^(n-1)\[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[(sin[c_.+d_.*x_]^j_.)^m_.*(A_.+B_.*sin[c_.+d_.*x_]^k_.)*(a_+b_.*sin[c_.+d_.*x_]^k_.)^n_.,x_Symbol] :=
  -B*Cos[c+d*x]*(Sin[c+d*x]^j)^m*(a+b*Sin[c+d*x]^k)^n/(d*(j*k*m+n+(k+1)/2)) + 
  Dist[1/(j*k*m+n+(k+1)/2),
    Int[(sin[c+d*x]^j)^(m-j*k)*
      Sim[a*B*(j*k*m+(k-1)/2)+(a*A+(a*A+b*B)*(j*k*m+n+(k-1)/2))*sin[c+d*x]^k+
        (n*(b*A+a*B)+b*A*(j*k*m+(k+1)/2))*sin[c+d*x]^(2*k),x]*
      (a+b*sin[c+d*x]^k)^(n-1),x]] /;
FreeQ[{a,b,c,d,A,B},x] && OneQ[j^2,k^2] && NonzeroQ[a^2-b^2] && RationalQ[m,n] && 
  j*k*m>0 && j*k*m!=1 && 0<n<1


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Derivation: Recurrence 4 with A=a A, B=b A+a B, C=b B and n=n-1*)


(* ::Subsubsection:: *)
(*Rule 4a: If  j^2=k^2=1 \[And] a^2-b^2!=0 \[And] j k m<-1 \[And] n>1, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral](Sin[c+d x]^j)^m (A+B Sin[c+d x]^k) (a+b Sin[c+d x]^k)^n \[DifferentialD]x  \[LongRightArrow]  *)
(*((a A Cos[c+d x] (Sin[c+d x]^j)^(m+j k) (a+b Sin[c+d x]^k)^(n-1))/(d(j k m+(k+1)/2)))+*)
(*1/(j k m+(k+1)/2) \[Integral](Sin[c+d x]^j)^(m+j k)\[CenterDot]*)
(*(a ((b A+a B)(j k m+(k+1)/2)-b A (n-1))+(a^2 A+(a^2 A+2 a b B+b^2 A) (j k m+(k+1)/2)) Sin[c+d x]^k+b(a A n+(a A+b B)(j k m+(k+1)/2))Sin[c+d x]^(2k))\[CenterDot]*)
(*(a+b Sin[c+d x]^k)^(n-2)\[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[(sin[c_.+d_.*x_]^j_.)^m_.*(A_.+B_.*sin[c_.+d_.*x_]^k_.)*(a_+b_.*sin[c_.+d_.*x_]^k_.)^n_,x_Symbol] :=
  a*A*Cos[c+d*x]*(Sin[c+d*x]^j)^(m+j*k)*(a+b*Sin[c+d*x]^k)^(n-1)/(d*(j*k*m+(k+1)/2)) + 
  Dist[1/(j*k*m+(k+1)/2),
    Int[(sin[c+d*x]^j)^(m+j*k)*
      Sim[a*((b*A+a*B)*(j*k*m+(k+1)/2)-b*A*(n-1))+
        (a^2*A+(a^2*A+2*a*b*B+b^2*A)*(j*k*m+(k+1)/2))*sin[c+d*x]^k+
        b*(a*A*n+(a*A+b*B)*(j*k*m+(k+1)/2))*sin[c+d*x]^(2*k),x]*
      (a+b*sin[c+d*x]^k)^(n-2),x]] /;
FreeQ[{a,b,c,d,A,B},x] && OneQ[j^2,k^2] && NonzeroQ[a^2-b^2] && RationalQ[m,n] && 
  j*k*m<-1 && n>1


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Derivation: Recurrence 4 with C=0*)


(* ::Subsubsection:: *)
(*Rule 4b: If  j^2=k^2=1 \[And] a^2-b^2!=0 \[And] j k m<-1 \[And] 0<n<=1, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral](Sin[c+d x]^j)^m (A+B Sin[c+d x]^k) (a+b Sin[c+d x]^k)^n \[DifferentialD]x  \[LongRightArrow]  *)
(*((A Cos[c+d x] (Sin[c+d x]^j)^(m+j k) (a+b Sin[c+d x]^k)^n)/(d(j k m+(k+1)/2)))+*)
(*1/(j k m+(k+1)/2) \[Integral](Sin[c+d x]^j)^(m+j k)\[CenterDot]*)
(*(a B(j k m+(k+1)/2)-b A n+(a A+(a A+b B) (j k m+(k+1)/2)) Sin[c+d x]^k+b A(j k m+n+(k+3)/2)Sin[c+d x]^(2k))\[CenterDot]*)
(*(a+b Sin[c+d x]^k)^(n-1)\[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[(sin[c_.+d_.*x_]^j_.)^m_.*(A_.+B_.*sin[c_.+d_.*x_]^k_.)*(a_+b_.*sin[c_.+d_.*x_]^k_.)^n_.,x_Symbol] :=
  A*Cos[c+d*x]*(Sin[c+d*x]^j)^(m+j*k)*(a+b*Sin[c+d*x]^k)^n/(d*(j*k*m+(k+1)/2)) + 
  Dist[1/(j*k*m+(k+1)/2),
    Int[(sin[c+d*x]^j)^(m+j*k)*
      Sim[a*B*(j*k*m+(k+1)/2)-b*A*n+(a*A+(a*A+b*B)*(j*k*m+(k+1)/2))*sin[c+d*x]^k+
        b*A*(j*k*m+n+(k+3)/2)*sin[c+d*x]^(2*k),x]*
      (a+b*sin[c+d*x]^k)^(n-1),x]] /;
FreeQ[{a,b,c,d,A,B},x] && OneQ[j^2,k^2] && NonzeroQ[a^2-b^2] && RationalQ[m,n] && 
  j*k*m<-1 && 0<n<=1


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Derivation: Recurrence 5 with C=0*)


(* ::Subsubsection:: *)
(*Rule 5: If  j^2=k^2=1 \[And] a^2-b^2!=0 \[And] j k m+(k+1)/2!=0 \[And] j k m<=-1 \[And] -1<=n<0, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral](Sin[c+d x]^j)^m (A+B Sin[c+d x]^k) (a+b Sin[c+d x]^k)^n \[DifferentialD]x  \[LongRightArrow]  *)
(*((A Cos[c+d x](Sin[c+d x]^j)^(m+j k) (a+b Sin[c+d x]^k)^(n+1))/(a d(j k m+(k+1)/2)))+*)
(*1/(a (j k m+(k+1)/2)) \[Integral](Sin[c+d x]^j)^(m+j k)\[CenterDot]*)
(*((a B-b A)(j k m+(k+1)/2)-b A (n+1)+a A(j k m+(k+3)/2)Sin[c+d x]^k+b A(j k m+n+(k+3)/2)Sin[c+d x]^(2k) )\[CenterDot]*)
(*(a+b Sin[c+d x]^k)^n\[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[(sin[c_.+d_.*x_]^j_.)^m_.*(A_.+B_.*sin[c_.+d_.*x_]^k_.)*(a_+b_.*sin[c_.+d_.*x_]^k_.)^n_,x_Symbol] :=
  A*Cos[c+d*x]*(Sin[c+d*x]^j)^(m+j*k)*(a+b*Sin[c+d*x]^k)^(n+1)/(a*d*(j*k*m+(k+1)/2)) + 
  Dist[1/(a*(j*k*m+(k+1)/2)),
    Int[(sin[c+d*x]^j)^(m+j*k)*
      Sim[(a*B-b*A)*(j*k*m+(k+1)/2)-b*A*(n+1)+a*A*(j*k*m+(k+3)/2)*sin[c+d*x]^k+
        b*A*(j*k*m+n+(k+1)/2+2)*sin[c+d*x]^(2*k),x]*
      (a+b*sin[c+d*x]^k)^n,x]] /;
FreeQ[{a,b,c,d,A,B},x] && OneQ[j^2,k^2] && NonzeroQ[a^2-b^2] && RationalQ[m,n] && 
  j*k*m+(k+1)/2!=0 && j*k*m<=-1 && -1<=n<0


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Derivation: Recurrence 6 with C=0*)


(* ::Subsubsection:: *)
(*Rule 6: If  j^2=k^2=1 \[And] a^2-b^2!=0 \[And] b A-a B!=0 \[And] j k m<0 \[And] n<-1, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral](Sin[c+d x]^j)^m (A+B Sin[c+d x]^k) (a+b Sin[c+d x]^k)^n \[DifferentialD]x  \[LongRightArrow]  *)
(*((b(b A-a B) Cos[c+d x](Sin[c+d x]^j)^(m+j k) (a+b Sin[c+d x]^k)^(n+1))/(a d (n+1) (a^2-b^2)))+*)
(*1/(a (n+1) (a^2-b^2)) \[Integral](Sin[c+d x]^j)^m\[CenterDot]*)
(*(A (a^2-b^2) (n+1)-b(b A-a B)(j k m+(k+1)/2)-a(b A-a B)(n+1)Sin[c+d x]^k+b(b A-a B)(j k m+n+(k+5)/2)Sin[c+d x]^(2k))\[CenterDot]*)
(*(a+b Sin[c+d x]^k)^(n+1)\[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[(sin[c_.+d_.*x_]^j_.)^m_.*(A_.+B_.*sin[c_.+d_.*x_]^k_.)*(a_+b_.*sin[c_.+d_.*x_]^k_.)^n_,x_Symbol] :=
  b*(b*A-a*B)*Cos[c+d*x]*(Sin[c+d*x]^j)^(m+j*k)*(a+b*Sin[c+d*x]^k)^(n+1)/(a*d*(n+1)*(a^2-b^2)) + 
  Dist[1/(a*(n+1)*(a^2-b^2)),
    Int[(sin[c+d*x]^j)^m*
      Sim[A*(a^2-b^2)*(n+1)-b*(b*A-a*B)*(j*k*m+(k+1)/2)-a*(b*A-a*B)*(n+1)*sin[c+d*x]^k+
        b*(b*A-a*B)*(j*k*m+n+(k+5)/2)*sin[c+d*x]^(2*k),x]*
      (a+b*sin[c+d*x]^k)^(n+1),x]] /;
FreeQ[{a,b,c,d,A,B},x] && OneQ[j^2,k^2] && NonzeroQ[a^2-b^2] && NonzeroQ[b*A-a*B] && 
  RationalQ[m,n] && j*k*m<0 && n<-1


(* ::PageBreak:: *)
(**)
