(* ::Package:: *)

(* ::Title::Plain:: *)
(* Integration Rules for *)
(*\[Integral](sin^j(z))^m (A+B sin^k(z))(a+b sin^k(z))^n \[DifferentialD]z when j^2=1\[And]k^2=1\[And]a^2=b^2*)


(* ::Subsubtitle::Bold::Closed:: *)
(*Domain Map *)


(* ::Input:: *)
(*Graphics[{{RGBColor[1, 0, 0], Rectangle[{-4, 0}, {-1, 4}]}, {GrayLevel[0], Inset[Style["Rule 1 \[LowerRightArrow]", FontSize -> 10], {Rational[-5, 2], 2.5}]}, {GrayLevel[0], Thickness[0.007], Dashing[{0.003, 0.02}], Line[{{-1.02, 3.98}, {-1.02, 0.02}}], {RGBColor[0.7, 0.7, 1.], Dashing[{}], Rectangle[{-1, 0}, {0, 4}], {GrayLevel[0], Inset[Style["Rule 2 \[DownArrow]", FontSize -> 10], {Rational[-1, 2], 2.5}]}, {RGBColor[0, 1, 0], Rectangle[{0, -1.02}, {4, 4}]}, {GrayLevel[0], Inset[Style["Rule 3 \[LeftArrow]", FontSize -> 10], {2, 2.5}]}, {GrayLevel[0], Thickness[0.007], Dashing[{0.003, 0.02}], Line[{{0.02, -0.98}, {3.98, -0.98}}], {RGBColor[1, 0.5, 0.5], Dashing[{}], Rectangle[{0, -1}, {4, -4}], {GrayLevel[0], Inset[Style["Rule 4 \[UpperLeftArrow]", FontSize -> 10], {2, Rational[-5, 2]}]}, {RGBColor[1, 0, 1], Rectangle[{-1, -4}, {0, -1.02}]}, {GrayLevel[0], Inset[Style["Rule 5 \[UpArrow]", FontSize -> 10], {Rational[-1, 2], -2.5}]}, {RGBColor[1, 0.5, 0], Rectangle[{-4, -4}, {-1, 0}]}, {GrayLevel[0], Inset[Style["Rule 6 \[RightArrow]", FontSize -> 10], {Rational[-5, 2], -2.5}]}, {GrayLevel[0], Thickness[0.007], Dashing[{0.003, 0.02}], Line[{{-1.02, 0}, {-1.02, -3.98}}]}, {RGBColor[0, 1, 0], Thickness[Large], Dashing[{}], Line[{{-3.98, 0}, {-1, 0}}], {GrayLevel[0], Inset[Style["Rule 7 \[RightArrow]\[Diamond]", FontSize -> 10], {-3, 0.13}]}, {RGBColor[1, 0, 0], Thickness[Large], Line[{{-0.98, 0}, {3.98, 0}}], {GrayLevel[0], Inset[Style["Rule 8\[Diamond]", FontSize -> 10], {2, 0.13}]}, {RGBColor[1, 1, 0], Thickness[Large], Line[{{-1, -1}, {2, -4}}], {GrayLevel[0], GeometricTransformation[Inset[Style["Rule 11 \[UpperLeftArrow]\[Diamond]", FontSize -> 10], {1.6, -3.39}], {{{0.7071067811865475, 0.7071067811865475}, {-0.7071067811865475, 0.7071067811865475}}, Center}]}, {RGBColor[0, 0, 1], Thickness[Large], Line[{{-4, 2}, {-1.02, -1}}], {GrayLevel[0], GeometricTransformation[Inset[Style["Rule 12 \[UpperRightArrow]\[Diamond]", FontSize -> 10], {-2.5, 0.7}], {{{0.7071067811865475, 0.7071067811865475}, {-0.7071067811865475, 0.7071067811865475}}, Center}]}, {RGBColor[0, 1, 0], Thickness[Large], Line[{{Rational[1, 2], -1.02}, {Rational[1, 2], -3.98}}], {GrayLevel[0], GeometricTransformation[Inset[Style[" Rule 9 \[LeftArrow]\[Diamond]", FontSize -> 10], {0.65, -3.4}], {{{0, 1}, {-1, 0}}, Center}]}, {RGBColor[1, 0.5, 0], Thickness[Large], Line[{{Rational[1, 2], 3.98}, {Rational[1, 2], -0.98}}], {GrayLevel[0], GeometricTransformation[Inset[Style["Rule 10\[Diamond]", FontSize -> 10], {0.65, 1.5}], {{{0, 1}, {-1, 0}}, Center}]}, {RGBColor[0, 1, 1], Disk[{-1, 0}, Scaled[Rational[1, 60]]]}, {GrayLevel[0], Inset["a", {-0.99, 0}]}, {RGBColor[0, 1, 1], Disk[{Rational[-1, 2], 0}, Scaled[Rational[1, 60]]]}, {GrayLevel[0], Inset["b", {-0.49, 0}]}, {RGBColor[0, 1, 1], Disk[{Rational[-1, 2], -1}, Scaled[Rational[1, 60]]]}, {GrayLevel[0], Inset["c", {-0.49, -1}]}, {RGBColor[0, 1, 1], Disk[{Rational[-1, 2], Rational[-1, 2]}, Scaled[Rational[1, 60]]]}, {GrayLevel[0], Inset["d", {-0.49, Rational[-1, 2]}]}, {GrayLevel[0], Disk[{-1, 1}, Scaled[Rational[1, 120]]]}}}}}}}}}}}}, Axes -> True, AxesLabel -> {$CellContext`n, $CellContext`j $CellContext`k $CellContext`m}, ImageSize -> Medium]*)


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
(*\[Integral](A+B sin^k(z))(a+b sin^k(z))^n \[DifferentialD]z when k^2=1\[And]a^2=b^2*)


(* ::Subsubtitle::Bold::Closed:: *)
(*Rule a:  \[Integral](A+B Csc[c+d x])/(a+b Csc[c+d x]) \[DifferentialD]x*)


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Derivation: Algebraic expansion*)


(* ::Subsubsection:: *)
(*Basis: (A+B z)/(a+b z)=A/a-((b A-a B)z)/(a(a+b z))*)


(* ::Subsubsection:: *)
(*Note: The rule for integrands of the same form when a^2-b^2!=0 could subsume this rule, but the resulting antiderivative will look less like the integrand involving sines instead of cosecants.*)


(* ::Subsubsection:: *)
(*Rule a: If  a^2-b^2=0 \[And] b A-a B!=0, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral](A+B Csc[c+d x])/(a+b Csc[c+d x]) \[DifferentialD]x  \[LongRightArrow]  ((A x)/a)-(b A-a B)/a \[Integral]Csc[c+d x]/(a+b Csc[c+d x]) \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[(A_.+B_.*sin[c_.+d_.*x_]^(-1))/(a_+b_.*sin[c_.+d_.*x_]^(-1)),x_Symbol] :=
  A*x/a - Dist[(b*A-a*B)/a,Int[sin[c+d*x]^(-1)/(a+b*sin[c+d*x]^(-1)),x]] /;
FreeQ[{a,b,c,d,A,B},x] && ZeroQ[a^2-b^2] && NonzeroQ[b*A-a*B]


(* ::PageBreak:: *)
(**)


(* ::Subsubtitle::Bold::Closed:: *)
(*Rules 13-14:  \[Integral](A+B Csc[c+d x])(a+b Csc[c+d x])^n \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Derivation: Rule 6 with m=0 and k=-1*)


(* ::Subsubsection:: *)
(*Rule 13: If  a^2-b^2=0 \[And] b A-a B!=0 \[And] n<-1, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral](A+B Csc[c+d x]) (a+b Csc[c+d x])^n \[DifferentialD]x  \[LongRightArrow]  -(((b A-a B) Cot[c+d x](a+b Csc[c+d x])^n)/(b d (2n+1)))+*)
(*1/(b^2 (2n+1)) \[Integral](a A(2 n+1)-(b A-a B)(n+1)Csc[c+d x])(a+b Csc[c+d x])^(n+1) \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[(A_.+B_.*sin[c_.+d_.*x_]^(-1))*(a_+b_.*sin[c_.+d_.*x_]^(-1))^n_,x_Symbol] :=
  -(b*A-a*B)*Cot[c+d*x]*(a+b*Csc[c+d*x])^n/(b*d*(2*n+1)) + 
  Dist[1/(b^2*(2*n+1)),
    Int[Sim[a*A*(2*n+1)-((b*A-a*B)*(n+1))*sin[c+d*x]^(-1),x]*(a+b*sin[c+d*x]^(-1))^(n+1),x]] /;
FreeQ[{a,b,c,d,A,B},x] && ZeroQ[a^2-b^2] && NonzeroQ[b*A-a*B] && RationalQ[n] && n<-1


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Derivation: Rule 3 with m=0 and k=-1 *)


(* ::Subsubsection:: *)
(*Rule 14: If  a^2-b^2=0 \[And] b A-a B!=0 \[And] n>0, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral](A+B Csc[c+d x]) (a+b Csc[c+d x])^n \[DifferentialD]x  \[LongRightArrow]  -((b B Cot[c+d x](a+b Csc[c+d x])^(n-1))/(d n))+*)
(*1/n \[Integral](a A n+(a B(2 n-1)+b A n)Csc[c+d x])(a+b Csc[c+d x])^(n-1) \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[(A_+B_.*sin[c_.+d_.*x_]^(-1))*(a_+b_.*sin[c_.+d_.*x_]^(-1))^n_,x_Symbol] :=
  -b*B*Cot[c+d*x]*(a+b*Csc[c+d*x])^(n-1)/(d*n) + 
  Dist[1/n,
    Int[Sim[a*A*n+(a*B*(2*n-1)+b*A*n)*sin[c+d*x]^(-1),x]*(a+b*sin[c+d*x]^(-1))^(n-1),x]] /;
FreeQ[{a,b,c,d,A,B},x] && ZeroQ[a^2-b^2] && NonzeroQ[b*A-a*B] && RationalQ[n] && n>0


(* ::PageBreak:: *)
(**)


(* ::Title::Plain::Closed:: *)
(* Integration Rules for *)
(*\[Integral](sin^j(z))^m (A+B sin^k(z))(a+b sin^k(z))^n \[DifferentialD]z when j^2=1\[And]k^2=1\[And]a^2=b^2*)


(* ::Subsubtitle::Bold::Closed:: *)
(*Rule c:  \[Integral](A+B Sin[c+d x]^k)/(Sin[c+d x]^((k+1)/2) Sqrt[a+b Sin[c+d x]^k]) \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Derivation: Algebraic expansion*)


(* ::Subsubsection:: *)
(*Basis: (A+B z^k)/(z^((k+1)/2) Sqrt[a+b z^k])=(A Sqrt[a+b z^k])/(a z^((k+1)/2))-((b A-a B)z^((k-1)/2))/(a Sqrt[a+b z^k])*)


(* ::Subsubsection:: *)
(*Rule c: If  k^2=1 \[And] a^2-b^2=0 \[And] b A-a B!=0, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral](A+B Sin[c+d x]^k)/(Sin[c+d x]^((k+1)/2) Sqrt[a+b Sin[c+d x]^k]) \[DifferentialD]x  \[LongRightArrow]  (A/a)\[Integral]Sqrt[a+b Sin[c+d x]^k]/Sin[c+d x]^((k+1)/2) \[DifferentialD]x-(b A-a B)/a \[Integral]Sin[c+d x]^((k-1)/2)/Sqrt[a+b Sin[c+d x]^k] \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[(A_+B_.*sin[c_.+d_.*x_])/(sin[c_.+d_.*x_]*Sqrt[a_+b_.*sin[c_.+d_.*x_]]),x_Symbol] :=
  Dist[A/a,Int[Sqrt[a+b*sin[c+d*x]]/sin[c+d*x],x]] - 
  Dist[(a*A-b*B)/b,Int[1/Sqrt[a+b*sin[c+d*x]],x]] /;
FreeQ[{a,b,c,d,A,B},x] && ZeroQ[a^2-b^2] && NonzeroQ[b*A-a*B]


(* ::Code:: *)
Int[(A_+B_.*sin[c_.+d_.*x_]^(-1))/Sqrt[a_+b_.*sin[c_.+d_.*x_]^(-1)],x_Symbol] :=
  A/a*Int[Sqrt[a+b*sin[c+d*x]^(-1)],x] - 
  (b*A-a*B)/a*Int[sin[c+d*x]^(-1)/Sqrt[a+b*sin[c+d*x]^(-1)],x] /;
FreeQ[{a,b,c,d,A,B},x] && ZeroQ[a^2-b^2] && NonzeroQ[b*A-a*B]


(* ::PageBreak:: *)
(**)


(* ::Subsubtitle::Bold::Closed:: *)
(*Rule d:  \[Integral](A+B Sin[c+d x])/(Sqrt[Sin[c+d x]] Sqrt[a+b Sin[c+d x]]) \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Derivation: Algebraic expansion*)


(* ::Subsubsection:: *)
(*Rule d: If  a^2-b^2=0 \[And] b A-a B!=0, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral](A+B Sin[c+d x])/(Sqrt[Sin[c+d x]] Sqrt[a+b Sin[c+d x]]) \[DifferentialD]x  \[LongRightArrow]  *)
(*(B/b)\[Integral]Sqrt[a+b Sin[c+d x]]/Sqrt[Sin[c+d x]] \[DifferentialD]x+(b A-a B)/b \[Integral]1/(Sqrt[Sin[c+d x]] Sqrt[a+b Sin[c+d x]]) \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[(A_+B_.*sin[c_.+d_.*x_])/(Sqrt[sin[c_.+d_.*x_]]*Sqrt[a_+b_.*sin[c_.+d_.*x_]]),x_Symbol] :=
  Dist[B/b,Int[Sqrt[a+b*sin[c+d*x]]/Sqrt[sin[c+d*x]],x]] + 
  Dist[(b*A-a*B)/b,Int[1/(Sqrt[sin[c+d*x]]*Sqrt[a+b*sin[c+d*x]]),x]] /;
FreeQ[{a,b,c,d,A,B},x] && ZeroQ[a^2-b^2] && NonzeroQ[b*A-a*B]


(* ::PageBreak:: *)
(**)


(* ::Subsubtitle::Bold::Closed:: *)
(*\[Integral](Sin[c+d x]^j)^(m/2) (A+B Csc[c+d x])(a+b Csc[c+d x])^(n/2) \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Derivation: Rule 4 with j m=1/2, k=-1 and n=1/2*)


(* ::Subsubsection:: *)
(*Rule: If  j^2=1 \[And] a^2-b^2=0 \[And] j m=1/2, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral](Sin[c+d x]^j)^m (A+B Csc[c+d x])Sqrt[a+b Csc[c+d x]]\[DifferentialD]x  \[LongRightArrow]  *)
(*-((2a A Cos[c+d x])/(d (Sin[c+d x]^j)^m Sqrt[a+b Csc[c+d x]]))+B \[Integral]Sqrt[a+b Csc[c+d x]]/(Sin[c+d x]^j)^m \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[(sin[c_.+d_.*x_]^j_.)^m_*(A_+B_.*sin[c_.+d_.*x_]^(-1))*Sqrt[a_+b_.*sin[c_.+d_.*x_]^(-1)],x_Symbol] :=
  -2*a*A*Cos[c+d*x]/(d*(Sin[c+d*x]^j)^m*Sqrt[a+b*Csc[c+d*x]]) + 
  Dist[B,Int[Sqrt[a+b*sin[c+d*x]^(-1)]/(sin[c+d*x]^j)^m,x]] /;
FreeQ[{a,b,c,d,A,B},x] && OneQ[j^2] && ZeroQ[a^2-b^2] && RationalQ[m] && j*m==1/2


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Derivation: Algebraic expansion*)


(* ::Subsubsection:: *)
(*Basis: (A+B z)/Sqrt[a+b z]=(B Sqrt[a+b z])/b+(b A-a B)/(b Sqrt[a+b z])*)


(* ::Subsubsection:: *)
(*Rule: If  j^2=1 \[And] a^2-b^2=0 \[And] j m=-(1/2) \[And] b A-a B!=0, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]((Sin[c+d x]^j)^m (A+B Csc[c+d x]))/Sqrt[a+b Csc[c+d x]] \[DifferentialD]x  \[LongRightArrow]  *)
(*(B/b)\[Integral](sin[c+d x]^j)^m Sqrt[a+b Csc[c+d x]] \[DifferentialD]x+(b A-a B)/b \[Integral](Sin[c+d x]^j)^m/Sqrt[a+b Csc[c+d x]] \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[(sin[c_.+d_.*x_]^j_.)^m_*(A_.+B_.*sin[c_.+d_.*x_]^(-1))/Sqrt[a_+b_.*sin[c_.+d_.*x_]^(-1)],x_Symbol] :=
  Dist[B/b,Int[(sin[c+d*x]^j)^m*Sqrt[a+b*sin[c+d*x]^(-1)],x]] + 
  Dist[(b*A-a*B)/b,Int[(sin[c+d*x]^j)^m/Sqrt[a+b*sin[c+d*x]^(-1)],x]] /;
FreeQ[{a,b,c,d,A,B},x] && OneQ[j^2] && ZeroQ[a^2-b^2] && RationalQ[m] && j*m==-1/2 && 
  NonzeroQ[b*A-a*B]


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Derivation: Rule 5 with j m=1/2, k=-1 and n=-(1/2)*)


(* ::Subsubsection:: *)
(*Rule: If  j^2=1 \[And] a^2-b^2=0 \[And] j m=1/2 \[And] b A-a B!=0, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]((Sin[c+d x]^j)^m (A+B Csc[c+d x]))/Sqrt[a+b Csc[c+d x]] \[DifferentialD]x  \[LongRightArrow]  *)
(*-((2A Cos[c+d x])/(d (Sin[c+d x]^j)^m Sqrt[a+b Csc[c+d x]]))-(b A-a B)/a \[Integral]1/((Sin[c+d x]^j)^m Sqrt[a+b Csc[c+d x]]) \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[(sin[c_.+d_.*x_]^j_.)^m_*(A_+B_.*sin[c_.+d_.*x_]^(-1))/Sqrt[a_+b_.*sin[c_.+d_.*x_]^(-1)],x_Symbol] :=
  -2*A*Cos[c+d*x]/(d*(Sin[c+d*x]^j)^m*Sqrt[a+b*Csc[c+d*x]]) - 
  Dist[(b*A-a*B)/a,Int[1/((sin[c+d*x]^j)^m*Sqrt[a+b*sin[c+d*x]^(-1)]),x]] /;
FreeQ[{a,b,c,d,A,B},x] && OneQ[j^2] && ZeroQ[a^2-b^2] && RationalQ[m] && j*m==1/2 && 
  NonzeroQ[b*A-a*B]


(* ::PageBreak:: *)
(**)


(* ::Subsubtitle::Bold::Closed:: *)
(*Rules 9-10:  \[Integral](Sin[c+d x]^j)^m (A+B Sin[c+d x]^k)Sqrt[a+b Sin[c+d x]^k]\[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Derivation: Rule 4 with n=1/2 and a B (j k m+(k+1)/2)+b A (j k m+(k+2)/2)=0*)


(* ::Subsubsection:: *)
(*Derivation: Rule 3 with n=1/2 and a B (j k m+(k+1)/2)+b A (j k m+(k+2)/2)=0*)


(* ::Subsubsection:: *)
(*Rule 9a: If  j^2=k^2=1 \[And] a^2-b^2=0 \[And] b A-a B!=0 \[And] j k m+(k+1)/2!=0 \[And] a B (j k m+(k+1)/2)+b A (j k m+(k+2)/2)=0, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral](Sin[c+d x]^j)^m (A+B Sin[c+d x]^k)Sqrt[a+b Sin[c+d x]^k]\[DifferentialD]x  \[LongRightArrow]  ((a A Cos[c+d x] (Sin[c+d x]^j)^(m+j k))/(d(j k m+(k+1)/2)Sqrt[a+b Sin[c+d x]^k]))*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[(sin[c_.+d_.*x_]^j_.)^m_*(A_.+B_.*sin[c_.+d_.*x_]^k_.)*Sqrt[a_+b_.*sin[c_.+d_.*x_]^k_.],x_Symbol] :=
  a*A*Cos[c+d*x]*(Sin[c+d*x]^j)^(m+j*k)/(d*(j*k*m+(k+1)/2)*Sqrt[a+b*Sin[c+d*x]^k]) /;
FreeQ[{a,b,c,d,A,B,m},x] && OneQ[j^2,k^2] && ZeroQ[a^2-b^2] && NonzeroQ[b*A-a*B] && 
  NonzeroQ[j*k*m+(k+1)/2] && ZeroQ[a*B*(j*k*m+(k+1)/2)+b*A*(j*k*m+(k+2)/2)]


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Derivation: Rule 4 with n=1/2*)


(* ::Subsubsection:: *)
(*Rule 9b: If  j^2=k^2=1 \[And] a^2-b^2=0 \[And] b A-a B!=0 \[And] j k m+(k+1)/2!=0 \[And] j k m<=-1 \[And] a B (j k m+(k+1)/2)+b A (j k m+(k+2)/2)!=0, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral](Sin[c+d x]^j)^m (A+B Sin[c+d x]^k)Sqrt[a+b Sin[c+d x]^k]\[DifferentialD]x  \[LongRightArrow]  ((a A Cos[c+d x] (Sin[c+d x]^j)^(m+j k))/(d(j k m+(k+1)/2)Sqrt[a+b Sin[c+d x]^k]))+*)
(*(a B (j k m+(k+1)/2)+b A (j k m+(k+2)/2))/(a(j k m+(k+1)/2)) \[Integral](Sin[c+d x]^j)^(m+j k) Sqrt[a+b Sin[c+d x]^k]\[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[(sin[c_.+d_.*x_]^j_.)^m_.*(A_.+B_.*sin[c_.+d_.*x_]^k_.)*Sqrt[a_+b_.*sin[c_.+d_.*x_]^k_.],x_Symbol] :=
  a*A*Cos[c+d*x]*(Sin[c+d*x]^j)^(m+j*k)/(d*(j*k*m+(k+1)/2)*Sqrt[a+b*Sin[c+d*x]^k]) + 
  Dist[(a*B*(j*k*m+(k+1)/2)+b*A*(j*k*m+(k+2)/2))/(a*(j*k*m+(k+1)/2)),
    Int[(sin[c+d*x]^j)^(m+j*k)*Sqrt[a+b*sin[c+d*x]^k],x]] /;
FreeQ[{a,b,c,d,A,B},x] && OneQ[j^2,k^2] && ZeroQ[a^2-b^2] && NonzeroQ[b*A-a*B] && 
  RationalQ[m] && NonzeroQ[j*k*m+(k+1)/2] && j*k*m<=-1 && 
  NonzeroQ[a*B*(j*k*m+(k+1)/2)+b*A*(j*k*m+(k+2)/2)]


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Derivation: Rule 3 with n=1/2*)


(* ::Subsubsection:: *)
(*Rule 10: If  j^2=k^2=1 \[And] a^2-b^2=0 \[And] b A-a B!=0 \[And] j k m+(k+2)/2!=0 \[And] j k m>=-1 \[And] a B (j k m+(k+1)/2)+b A (j k m+(k+2)/2)!=0, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral](Sin[c+d x]^j)^m (A+B Sin[c+d x]^k)Sqrt[a+b Sin[c+d x]^k]\[DifferentialD]x  \[LongRightArrow]  -((b B Cos[c+d x] (Sin[c+d x]^j)^(m+j k))/(d(j k m+(k+2)/2)Sqrt[a+b Sin[c+d x]^k]))+*)
(*(a B (j k m+(k+1)/2)+b A (j k m+(k+2)/2))/(b(j k m+(k+2)/2)) \[Integral](Sin[c+d x]^j)^m Sqrt[a+b Sin[c+d x]^k]\[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[(sin[c_.+d_.*x_]^j_.)^m_*(A_.+B_.*sin[c_.+d_.*x_]^k_.)*Sqrt[a_+b_.*sin[c_.+d_.*x_]^k_.],x_Symbol] :=
  -b*B*Cos[c+d*x]*(Sin[c+d*x]^j)^(m+j*k)/(d*(j*k*m+(k+2)/2)*Sqrt[a+b*Sin[c+d*x]^k]) + 
  Dist[(a*B*(j*k*m+(k+1)/2)+b*A*(j*k*m+(k+2)/2))/(b*(j*k*m+(k+2)/2)),
    Int[(sin[c+d*x]^j)^m*Sqrt[a+b*sin[c+d*x]^k],x]] /;
FreeQ[{a,b,c,d,A,B},x] && OneQ[j^2,k^2] && ZeroQ[a^2-b^2] && NonzeroQ[b*A-a*B] && 
  RationalQ[m] && NonzeroQ[j*k*m+(k+2)/2] && j*k*m>=-1 && 
  NonzeroQ[a*B*(j*k*m+(k+1)/2)+b*A*(j*k*m+(k+2)/2)]


(* ::PageBreak:: *)
(**)


(* ::Subsubtitle::Bold::Closed:: *)
(*Rules 11-12:  \[Integral]((Sin[c+d x]^j)^m (A+B Sin[c+d x]^k))/(a+b Sin[c+d x]^k)^(j k m+(k+3)/2) \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Derivation: Rule 5 with j k m+n+(k+3)/2=0 and a B(n+1)+b A n=0*)


(* ::Subsubsection:: *)
(*Rule 11a: If  j^2=k^2=1 \[And] a^2-b^2=0 \[And] b A-a B!=0 \[And] j k m+n+(k+3)/2=0 \[And] n+1!=0 \[And] a B(n+1)+b A n=0, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral](Sin[c+d x]^j)^m (A+B Sin[c+d x]^k) (a+b Sin[c+d x]^k)^n \[DifferentialD]x  \[LongRightArrow]  *)
(*-((A Cos[c+d x] (Sin[c+d x]^j)^(m+j k) (a+b Sin[c+d x]^k)^n)/(d(n+1)))*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[(sin[c_.+d_.*x_]^j_.)^m_*(A_.+B_.*sin[c_.+d_.*x_]^k_.)*(a_+b_.*sin[c_.+d_.*x_]^k_.)^n_,x_Symbol] :=
  -A*Cos[c+d*x]*(Sin[c+d*x]^j)^(m+j*k)*(a+b*Sin[c+d*x]^k)^n/(d*(n+1)) /;
FreeQ[{a,b,c,d,A,B,m,n},x] && OneQ[j^2,k^2] && ZeroQ[a^2-b^2] && NonzeroQ[b*A-a*B] && 
  ZeroQ[j*k*m+n+(k+3)/2] && NonzeroQ[n+1] && ZeroQ[a*B*(n+1)+b*A*n]


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Derivation: Rule 5 with j k m+n+(k+3)/2=0*)


(* ::Subsubsection:: *)
(*Rule 11b: If  j^2=k^2=1 \[And] a^2-b^2=0 \[And] b A-a B!=0 \[And] j k m+n+(k+3)/2=0 \[And] n>-1 \[And] a B(n+1)+b A n!=0, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral](Sin[c+d x]^j)^m (A+B Sin[c+d x]^k) (a+b Sin[c+d x]^k)^n \[DifferentialD]x  \[LongRightArrow]  *)
(*-((A Cos[c+d x] (Sin[c+d x]^j)^(m+j k) (a+b Sin[c+d x]^k)^n)/(d(n+1)))+*)
(*(a B(n+1)+b A n)/(a(n+1)) \[Integral](Sin[c+d x]^j)^(m+j k) (a+b Sin[c+d x]^k)^n \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[(sin[c_.+d_.*x_]^j_.)^m_*(A_.+B_.*sin[c_.+d_.*x_]^k_.)*(a_+b_.*sin[c_.+d_.*x_]^k_.)^n_,x_Symbol] :=
  -A*Cos[c+d*x]*(Sin[c+d*x]^j)^(m+j*k)*(a+b*Sin[c+d*x]^k)^n/(d*(n+1)) + 
  Dist[(a*B*(n+1)+b*A*n)/(a*(n+1)),Int[(sin[c+d*x]^j)^(m+j*k)*(a+b*sin[c+d*x]^k)^n,x]] /;
FreeQ[{a,b,c,d,A,B},x] && OneQ[j^2,k^2] && ZeroQ[a^2-b^2] && NonzeroQ[b*A-a*B] && 
  RationalQ[m,n] && ZeroQ[j*k*m+n+(k+3)/2] && n>-1 && NonzeroQ[a*B*(n+1)+b*A*n]


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Derivation: Rule 6 with j k m+n+(k+3)/2=0 and b B(n+1)+a A n=0*)


(* ::Subsubsection:: *)
(*Rule 12a: If  j^2=k^2=1 \[And] a^2-b^2=0 \[And] b A-a B!=0 \[And] j k m+n+(k+3)/2=0 \[And] 2n+1!=0 \[And] b B(n+1)+a A n=0, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral](Sin[c+d x]^j)^m (A+B Sin[c+d x]^k) (a+b Sin[c+d x]^k)^n \[DifferentialD]x  \[LongRightArrow]  *)
(*-(((b A-a B) Cos[c+d x](Sin[c+d x]^j)^(m+j k) (a+b Sin[c+d x]^k)^n)/(b d (2n+1)))*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[(sin[c_.+d_.*x_]^j_.)^m_*(A_.+B_.*sin[c_.+d_.*x_]^k_.)*(a_+b_.*sin[c_.+d_.*x_]^k_.)^n_,x_Symbol] :=
  -(b*A-a*B)*Cos[c+d*x]*(Sin[c+d*x]^j)^(m+j*k)*(a+b*Sin[c+d*x]^k)^n/(b*d*(2*n+1)) /;
FreeQ[{a,b,c,d,A,B,m,n},x] && OneQ[j^2,k^2] && ZeroQ[a^2-b^2] && NonzeroQ[b*A-a*B] && 
  ZeroQ[j*k*m+n+(k+3)/2] && NonzeroQ[2*n+1] && ZeroQ[b*B*(n+1)+a*A*n]


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Derivation: Rule 6 with j k m+n+(k+3)/2=0*)


(* ::Subsubsection:: *)
(*Rule 12b: If  j^2=k^2=1 \[And] a^2-b^2=0 \[And] b A-a B!=0 \[And] j k m+n+(k+3)/2=0 \[And] n<=-1 \[And] b B(n+1)+a A n!=0, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral](Sin[c+d x]^j)^m (A+B Sin[c+d x]^k) (a+b Sin[c+d x]^k)^n \[DifferentialD]x  \[LongRightArrow]  *)
(*-(((b A-a B) Cos[c+d x](Sin[c+d x]^j)^(m+j k) (a+b Sin[c+d x]^k)^n)/(b d (2n+1)))+*)
(*(b B(n+1)+a A n)/(a^2 (2n+1)) \[Integral](Sin[c+d x]^j)^m (a+b Sin[c+d x]^k)^(n+1) \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[(sin[c_.+d_.*x_]^j_.)^m_*(A_.+B_.*sin[c_.+d_.*x_]^k_.)*(a_+b_.*sin[c_.+d_.*x_]^k_.)^n_,x_Symbol] :=
  -(b*A-a*B)*Cos[c+d*x]*(Sin[c+d*x]^j)^(m+j*k)*(a+b*Sin[c+d*x]^k)^n/(b*d*(2*n+1)) + 
  Dist[(b*B*(n+1)+a*A*n)/(a^2*(2*n+1)),Int[(sin[c+d*x]^j)^m*(a+b*sin[c+d*x]^k)^(n+1),x]] /;
FreeQ[{a,b,c,d,A,B},x] && OneQ[j^2,k^2] && ZeroQ[a^2-b^2] && NonzeroQ[b*A-a*B] && 
  RationalQ[m,n] && ZeroQ[j*k*m+n+(k+3)/2] && n<=-1 && NonzeroQ[b*B*(n+1)+a*A*n]


(* ::PageBreak:: *)
(**)


(* ::Subsubtitle::Bold::Closed:: *)
(*Rules 7-8:  \[Integral]Sin[c+d x]^((k-1)/2) (A+B Sin[c+d x]^k) (a+b Sin[c+d x]^k)^n \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Derivation: Rule 2 with j m=(k-1)/2 and a B n+b A(n+1)=0*)


(* ::Subsubsection:: *)
(*Rule: If  k^2=1 \[And] a^2-b^2=0 \[And] a B n+b A (n+1)=0 , then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]Sin[c+d x]^((k-1)/2) (A+B Sin[c+d x]^k) (a+b Sin[c+d x]^k)^n \[DifferentialD]x  \[LongRightArrow]  *)
(*-((B Cos[c+d x]Sin[c+d x]^((k-1)/2) (a+b Sin[c+d x]^k)^n)/(d(n+1)))*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[(A_.+B_.*sin[c_.+d_.*x_])*(a_+b_.*sin[c_.+d_.*x_])^n_.,x_Symbol] :=
  -B*Cos[c+d*x]*(a+b*Sin[c+d*x])^n/(d*(n+1)) /;
FreeQ[{a,b,c,d,A,B,n},x] && ZeroQ[a^2-b^2] && ZeroQ[a*B*n+b*A*(n+1)]


(* ::Code:: *)
Int[sin[c_.+d_.*x_]^(-1)*(A_+B_.*sin[c_.+d_.*x_]^(-1))*(a_+b_.*sin[c_.+d_.*x_]^(-1))^n_.,x_Symbol] :=
  -B*Cot[c+d*x]*(a+b*Csc[c+d*x])^n/(d*(n+1)) /;
FreeQ[{a,b,c,d,A,B,n},x] && ZeroQ[a^2-b^2] && ZeroQ[a*B*n+b*A*(n+1)]


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Derivation: Rule 1 with j m=(k-1)/2*)


(* ::Subsubsection:: *)
(*Rule 7: If  k^2=1 \[And] a^2-b^2=0 \[And] b A-a B!=0 \[And] n<=-1 \[And] a B n+b A (n+1)!=0, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]Sin[c+d x]^((k-1)/2) (A+B Sin[c+d x]^k) (a+b Sin[c+d x]^k)^n \[DifferentialD]x  \[LongRightArrow]  *)
(*(((b A-a B) Cos[c+d x]Sin[c+d x]^((k-1)/2) (a+b Sin[c+d x]^k)^n)/(a d (2n+1)))+*)
(*(a B n+b A(n+1))/(a b(2n+1)) \[Integral]Sin[c+d x]^((k-1)/2) (a+b Sin[c+d x]^k)^(n+1) \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[(A_.+B_.*sin[c_.+d_.*x_])*(a_+b_.*sin[c_.+d_.*x_])^n_,x_Symbol] :=
  (b*A-a*B)*Cos[c+d*x]*(a+b*Sin[c+d*x])^n/(a*d*(2*n+1)) + 
  Dist[(a*B*n+b*A*(n+1))/(a*b*(2*n+1)),Int[(a+b*sin[c+d*x])^(n+1),x]] /;
FreeQ[{a,b,c,d,A,B},x] && ZeroQ[a^2-b^2] && NonzeroQ[b*A-a*B] && RationalQ[n] && n<=-1 && 
  NonzeroQ[a*B*n+b*A*(n+1)]


(* ::Code:: *)
Int[sin[c_.+d_.*x_]^(-1)*(A_+B_.*sin[c_.+d_.*x_]^(-1))*(a_+b_.*sin[c_.+d_.*x_]^(-1))^n_,x_Symbol] :=
  (b*A-a*B)*Cot[c+d*x]*(a+b*Csc[c+d*x])^n/(a*d*(2*n+1)) + 
  Dist[(a*B*n+b*A*(n+1))/(a*b*(2*n+1)),Int[sin[c+d*x]^(-1)*(a+b*sin[c+d*x]^(-1))^(n+1),x]] /;
FreeQ[{a,b,c,d,A,B},x] && ZeroQ[a^2-b^2] && NonzeroQ[b*A-a*B] && RationalQ[n] && n<=-1 && 
  NonzeroQ[a*B*n+b*A*(n+1)]


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Derivation: Rule 2 with j m=(k-1)/2*)


(* ::Subsubsection:: *)
(*Rule 8: If  k^2=1 \[And] a^2-b^2=0 \[And] b A-a B!=0 \[And] n>-1 \[And] n!=1 \[And] a B n+b A (n+1)!=0 , then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]Sin[c+d x]^((k-1)/2) (A+B Sin[c+d x]^k) (a+b Sin[c+d x]^k)^n \[DifferentialD]x  \[LongRightArrow]  *)
(*-((B Cos[c+d x]Sin[c+d x]^((k-1)/2) (a+b Sin[c+d x]^k)^n)/(d(n+1)))+*)
(*(a B n+b A (n+1))/(b (n+1)) \[Integral] Sin[c+d x]^((k-1)/2) (a+b Sin[c+d x]^k)^n \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[(A_.+B_.*sin[c_.+d_.*x_])*(a_+b_.*sin[c_.+d_.*x_])^n_,x_Symbol] :=
  -B*Cos[c+d*x]*(a+b*Sin[c+d*x])^n/(d*(n+1)) + 
  Dist[(a*B*n+b*A*(n+1))/(b*(n+1)),Int[(a+b*sin[c+d*x])^n,x]] /;
FreeQ[{a,b,c,d,A,B},x] && ZeroQ[a^2-b^2] && NonzeroQ[b*A-a*B] && RationalQ[n] && 
  n>-1 && n!=1 && NonzeroQ[a*B*n+b*A*(n+1)]


(* ::Code:: *)
Int[sin[c_.+d_.*x_]^(-1)*(A_+B_.*sin[c_.+d_.*x_]^(-1))*(a_+b_.*sin[c_.+d_.*x_]^(-1))^n_,x_Symbol] :=
  -B*Cot[c+d*x]*(a+b*Csc[c+d*x])^n/(d*(n+1)) + 
  Dist[(a*B*n+b*A*(n+1))/(b*(n+1)),Int[sin[c+d*x]^(-1)*(a+b*sin[c+d*x]^(-1))^n,x]] /;
FreeQ[{a,b,c,d,A,B},x] && ZeroQ[a^2-b^2] && NonzeroQ[b*A-a*B] && RationalQ[n] && 
  n>-1 && n!=1 && NonzeroQ[a*B*n+b*A*(n+1)]


(* ::PageBreak:: *)
(**)


(* ::Subsubtitle::Bold::Closed:: *)
(*Rules 1-6:  \[Integral](Sin[c+d x]^j)^m (A+B Sin[c+d x]^k) (a+b Sin[c+d x]^k)^n \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Derivation: Recurrence 7*)


(* ::Subsubsection:: *)
(*Rule 1: If  j^2=k^2=1 \[And] a^2-b^2=0 \[And] b A-a B!=0 \[And] j k m>0 \[And] n<=-1, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral](Sin[c+d x]^j)^m (A+B Sin[c+d x]^k) (a+b Sin[c+d x]^k)^n \[DifferentialD]x  \[LongRightArrow]  *)
(*(((b A-a B) Cos[c+d x] (Sin[c+d x]^j)^m (a+b Sin[c+d x]^k)^n)/(a d (2n+1)))+*)
(*1/(a^2 (2n+1)) \[Integral](Sin[c+d x]^j)^(m-j k)\[CenterDot]*)
(*(-(b A-a B)(j k m+(k-1)/2)+(b B n+a A (n+1)+(a A-b B)(j k m+(k-1)/2))Sin[c+d x]^k) (a+b Sin[c+d x]^k)^(n+1) \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[(sin[c_.+d_.*x_]^j_.)^m_.*(A_.+B_.*sin[c_.+d_.*x_]^k_.)*(a_+b_.*sin[c_.+d_.*x_]^k_.)^n_,x_Symbol] :=
  (b*A-a*B)*Cos[c+d*x]*(Sin[c+d*x]^j)^m*(a+b*Sin[c+d*x]^k)^n/(a*d*(2*n+1)) + 
  Dist[1/(a^2*(2*n+1)),
    Int[(sin[c+d*x]^j)^(m-j*k)*
      Sim[-(b*A-a*B)*(j*k*m+(k-1)/2)+(b*B*n+a*A*(n+1)+(a*A-b*B)*(j*k*m+(k-1)/2))*sin[c+d*x]^k,x]*
      (a+b*sin[c+d*x]^k)^(n+1),x]] /;
FreeQ[{a,b,c,d,A,B},x] && OneQ[j^2,k^2] && ZeroQ[a^2-b^2] && NonzeroQ[b*A-a*B] && 
  RationalQ[m,n] && j*k*m>0 && n<=-1 && Not[j*k*m==1 && n==-1]


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Derivation: Recurrence 8*)


(* ::Subsubsection:: *)
(*Rule 2: If  j^2=k^2=1 \[And] a^2-b^2=0 \[And] b A-a B!=0 \[And] j k m+n+(k+1)/2!=0 \[And] j k m>0 \[And] -1<n<0, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral](Sin[c+d x]^j)^m (A+B Sin[c+d x]^k) (a+b Sin[c+d x]^k)^n \[DifferentialD]x  \[LongRightArrow]  *)
(*-((B Cos[c+d x](Sin[c+d x]^j)^m (a+b Sin[c+d x]^k)^n)/(d (j k m+n+(k+1)/2)))+*)
(*1/(a (j k m+n+(k+1)/2)) \[Integral](Sin[c+d x]^j)^(m-j k)\[CenterDot]*)
(*(a B (j k m+(k-1)/2)+(b B n+a A(j k m+n+(k+1)/2))Sin[c+d x]^k) (a+b Sin[c+d x]^k)^n \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[(sin[c_.+d_.*x_]^j_.)^m_.*(A_.+B_.*sin[c_.+d_.*x_]^k_.)*(a_+b_.*sin[c_.+d_.*x_]^k_.)^n_,x_Symbol] :=
  -B*Cos[c+d*x]*(Sin[c+d*x]^j)^m*(a+b*Sin[c+d*x]^k)^n/(d*(j*k*m+n+(k+1)/2)) + 
  Dist[1/(a*(j*k*m+n+(k+1)/2)),
    Int[(sin[c+d*x]^j)^(m-j*k)*
      Sim[a*B*(j*k*m+(k-1)/2)+(b*B*n+a*A*(j*k*m+n+(k+1)/2))*sin[c+d*x]^k,x]*
      (a+b*sin[c+d*x]^k)^n,x]] /;
FreeQ[{a,b,c,d,A,B},x] && OneQ[j^2,k^2] && ZeroQ[a^2-b^2] && NonzeroQ[b*A-a*B] && 
  RationalQ[m,n] && NonzeroQ[j*k*m+n+(k+1)/2] && j*k*m>0 && -1<n<0 && Not[j*m==1 && k==1]


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Derivation: Recurrence 9*)


(* ::Subsubsection:: *)
(*Note: In the case n=1/2, this rule simplifies to rule 10.*)


(* ::Subsubsection:: *)
(*Rule 3: If  j^2=k^2=1 \[And] a^2-b^2=0 \[And] b A-a B!=0 \[And] j k m+n+(k+1)/2!=0 \[And] j k m>=-1 \[And] n>0 \[And] n!=1/2, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral](Sin[c+d x]^j)^m (A+B Sin[c+d x]^k) (a+b Sin[c+d x]^k)^n \[DifferentialD]x  \[LongRightArrow]  *)
(*-((b B Cos[c+d x](Sin[c+d x]^j)^(m+j k) (a+b Sin[c+d x]^k)^(n-1))/(d (j k m+n+(k+1)/2)))+*)
(*1/(j k m+n+(k+1)/2) \[Integral](Sin[c+d x]^j)^m\[CenterDot]*)
(*(a A n+(a A+b B)(j k m+(k+1)/2)+(b A+a B n+(b A+a B)(j k m+n+(k-1)/2))Sin[c+d x]^k) (a+b Sin[c+d x]^k)^(n-1) \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[(sin[c_.+d_.*x_]^j_.)^m_.*(A_.+B_.*sin[c_.+d_.*x_]^k_.)*(a_+b_.*sin[c_.+d_.*x_]^k_.)^n_.,x_Symbol] :=
  -b*B*Cos[c+d*x]*(Sin[c+d*x]^j)^(m+j*k)*(a+b*Sin[c+d*x]^k)^(n-1)/(d*(j*k*m+n+(k+1)/2)) + 
  Dist[1/(j*k*m+n+(k+1)/2),
    Int[(sin[c+d*x]^j)^m*
      Sim[a*A*n+(a*A+b*B)*(j*k*m+(k+1)/2)+(b*A+a*B*n+(b*A+a*B)*(j*k*m+n+(k-1)/2))*sin[c+d*x]^k,x]*
      (a+b*sin[c+d*x]^k)^(n-1),x]] /;
FreeQ[{a,b,c,d,A,B},x] && OneQ[j^2,k^2] && ZeroQ[a^2-b^2] && NonzeroQ[b*A-a*B] && 
  RationalQ[m,n] && NonzeroQ[j*k*m+n+(k+1)/2] && j*k*m>=-1 && n>0 && n!=1/2 && Not[j*m==1 && k==1]


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Derivation: Recurrence 10*)


(* ::Subsubsection:: *)
(*Note: In the case n=1/2, this rule simplifies to rule 9b.*)


(* ::Subsubsection:: *)
(*Rule 4: If  j^2=k^2=1 \[And] a^2-b^2=0 \[And] b A-a B!=0 \[And] j k m<-1 \[And] n>0 \[And] n!=1/2, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral](Sin[c+d x]^j)^m (A+B Sin[c+d x]^k) (a+b Sin[c+d x]^k)^n \[DifferentialD]x  \[LongRightArrow]  *)
(*((a A Cos[c+d x] (Sin[c+d x]^j)^(m+j k) (a+b Sin[c+d x]^k)^(n-1))/(d(j k m+(k+1)/2)))+*)
(*1/(j k m+(k+1)/2) \[Integral](Sin[c+d x]^j)^(m+j k)\[CenterDot]*)
(*((b A+a B)(j k m+(k+1)/2)-b A (n-1)+(a A n+(a A+b B)(j k m+(k+1)/2)) Sin[c+d x]^k) (a+b Sin[c+d x]^k)^(n-1) \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[(sin[c_.+d_.*x_]^j_.)^m_.*(A_.+B_.*sin[c_.+d_.*x_]^k_.)*(a_+b_.*sin[c_.+d_.*x_]^k_.)^n_,x_Symbol] :=
  a*A*Cos[c+d*x]*(Sin[c+d*x]^j)^(m+j*k)*(a+b*Sin[c+d*x]^k)^(n-1)/(d*(j*k*m+(k+1)/2)) + 
  Dist[1/(j*k*m+(k+1)/2),
    Int[(sin[c+d*x]^j)^(m+j*k)*
      Sim[(b*A+a*B)*(j*k*m+(k+1)/2)-b*A*(n-1)+(a*A*n+(a*A+b*B)*(j*k*m+(k+1)/2))*sin[c+d*x]^k,x]*
      (a+b*sin[c+d*x]^k)^(n-1),x]] /;
FreeQ[{a,b,c,d,A,B},x] && OneQ[j^2,k^2] && ZeroQ[a^2-b^2] && NonzeroQ[b*A-a*B] && 
  RationalQ[m,n] && j*k*m<-1 && n>0 && n!=1/2


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Derivation: Recurrence 11*)


(* ::Subsubsection:: *)
(*Rule 5: If  j^2=k^2=1 \[And] a^2-b^2=0 \[And] b A-a B!=0 \[And] j k m+(k+1)/2!=0 \[And] j k m<=-1 \[And] -1<n<0, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral](Sin[c+d x]^j)^m (A+B Sin[c+d x]^k) (a+b Sin[c+d x]^k)^n \[DifferentialD]x  \[LongRightArrow]  *)
(*((A Cos[c+d x] (Sin[c+d x]^j)^(m+j k) (a+b Sin[c+d x]^k)^n)/(d(j k m+(k+1)/2)))+*)
(*1/(a(j k m+(k+1)/2)) \[Integral](Sin[c+d x]^j)^(m+j k)\[CenterDot]*)
(*(a B(j k m+(k+1)/2)-b A n+a A(j k m+n+(k+3)/2) Sin[c+d x]^k) (a+b Sin[c+d x]^k)^n \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[(sin[c_.+d_.*x_]^j_.)^m_.*(A_.+B_.*sin[c_.+d_.*x_]^k_.)*(a_+b_.*sin[c_.+d_.*x_]^k_.)^n_.,x_Symbol] :=
  A*Cos[c+d*x]*(Sin[c+d*x]^j)^(m+j*k)*(a+b*Sin[c+d*x]^k)^n/(d*(j*k*m+(k+1)/2)) + 
  Dist[1/(a*(j*k*m+(k+1)/2)),
    Int[(sin[c+d*x]^j)^(m+j*k)*
      Sim[a*B*(j*k*m+(k+1)/2)-b*A*n+a*A*(j*k*m+n+(k+3)/2)*sin[c+d*x]^k,x]*
      (a+b*sin[c+d*x]^k)^n,x]] /;
FreeQ[{a,b,c,d,A,B},x] && OneQ[j^2,k^2] && ZeroQ[a^2-b^2] && NonzeroQ[b*A-a*B] && 
  RationalQ[m,n] && NonzeroQ[j*k*m+(k+1)/2] && j*k*m<=-1 && -1<n<0


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Derivation: Recurrence 12*)


(* ::Subsubsection:: *)
(*Rule 6: If  j^2=k^2=1 \[And] a^2-b^2!=0 \[And] b A-a B!=0 \[And] j k m<0 \[And] n<=-1, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral](Sin[c+d x]^j)^m (A+B Sin[c+d x]^k) (a+b Sin[c+d x]^k)^n \[DifferentialD]x  \[LongRightArrow]  *)
(*-(((b A-a B) Cos[c+d x](Sin[c+d x]^j)^(m+j k) (a+b Sin[c+d x]^k)^n)/(b d (2n+1)))+*)
(*1/(b^2 (2n+1)) \[Integral](Sin[c+d x]^j)^m\[CenterDot]*)
(*(a A(2 n+1)+(a A-b B)(j k m+(k+1)/2)-(b A-a B)(j k m+n+(k+3)/2)Sin[c+d x]^k) (a+b Sin[c+d x]^k)^(n+1) \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[(sin[c_.+d_.*x_]^j_.)^m_.*(A_.+B_.*sin[c_.+d_.*x_]^k_.)*(a_+b_.*sin[c_.+d_.*x_]^k_.)^n_,x_Symbol] :=
  -(b*A-a*B)*Cos[c+d*x]*(Sin[c+d*x]^j)^(m+j*k)*(a+b*Sin[c+d*x]^k)^n/(b*d*(2*n+1)) + 
  Dist[1/(b^2*(2*n+1)),
    Int[(sin[c+d*x]^j)^m*
      Sim[a*A*(2*n+1)+(a*A-b*B)*(j*k*m+(k+1)/2)-(b*A-a*B)*(j*k*m+n+(k+3)/2)*sin[c+d*x]^k,x]*
      (a+b*sin[c+d*x]^k)^(n+1),x]] /;
FreeQ[{a,b,c,d,A,B},x] && OneQ[j^2,k^2] && ZeroQ[a^2-b^2] && NonzeroQ[b*A-a*B] && 
  RationalQ[m,n] && j*k*m<0 && n<=-1


(* ::PageBreak:: *)
(**)
