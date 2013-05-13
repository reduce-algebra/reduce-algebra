(* ::Package:: *)

(* ::Title::Plain:: *)
(* Integration Rules for *)
(*\[Integral](sin^j(z))^m (A+B sin^k(z)+C sin^(2k)(z))(a+b sin^k(z))^n \[DifferentialD]z when j^2=1\[And]k^2=1*)


(* ::Subsubtitle::Plain::Closed:: *)
(*Domain Map *)


(* ::Input:: *)
(*Graphics[{{RGBColor[1, 0, 0], Rectangle[{-4, 0}, {-1, 4}]}, {GrayLevel[0], Inset[Style["Rule 1 \[LowerRightArrow]", FontSize -> 10], {Rational[-5, 2], Rational[5, 2]}]}, {RGBColor[0.5, 0.5, 1.], Rectangle[{-1, 0}, {0, 4}]}, {GrayLevel[0], Inset[Style["Rule 2 \[DownArrow]", FontSize -> 10], {Rational[-1, 2], Rational[5, 2]}]}, {RGBColor[0.5, 0.5, 1.], Thickness[Large], Line[{{-1, 3.98}, {-1, 0}}]}, {GrayLevel[0], Thickness[0.007], Dashing[{0.003, 0.02}], Line[{{-0.98, 3.98}, {-0.98, 0}}], {RGBColor[0, 1, 0], Dashing[{}], Rectangle[{0, -1}, {4, 4}], {GrayLevel[0], Inset[Style["Rule 3 \[LeftArrow]", FontSize -> 10], {2, Rational[5, 2]}]}, {GrayLevel[0], Thickness[0.007], Dashing[{0.003, 0.02}], Line[{{0.02, -0.98}, {3.98, -0.98}}], {RGBColor[1, 0.5, 0.5], Dashing[{}], Rectangle[{0, -4}, {4, -1}], {GrayLevel[0], Inset[Style["Rule 4 \[UpperLeftArrow]", FontSize -> 10], {2, Rational[-5, 2]}]}, {RGBColor[1, 0, 1], Rectangle[{-1, -4}, {0, -1}]}, {GrayLevel[0], Inset[Style["Rule 5 \[UpArrow]", FontSize -> 10], {Rational[-1, 2], -2.5}]}, {RGBColor[1, 0, 1], Thickness[Large], Line[{{-1, -1.02}, {-1, -3.98}}]}, {GrayLevel[0], Thickness[0.007], Dashing[{0.003, 0.02}], Line[{{-0.98, -1.04}, {-0.98, -3.98}}], {RGBColor[1, 0.5, 0], Dashing[{}], Rectangle[{-4, -4}, {-1, 0}], {GrayLevel[0], Inset[Style["Rule 6 \[RightArrow]", FontSize -> 10], {Rational[-5, 2], -2.5}]}, {GrayLevel[1], Thickness[Large], Line[{{-1, -0.02}, {-1, -1}}]}, {RGBColor[1, 1, 0], Thickness[Large], Line[{{0, -3.98}, {0, -1.02}}], {GrayLevel[0], GeometricTransformation[Inset[Style["Rule 7\[LeftArrow]\[Diamond]", FontSize -> 10], {0.15, -2.5}], {{{0, 1}, {-1, 0}}, Center}]}, {RGBColor[0.6, 0.4, 0.2], Thickness[Large], Line[{{0, -1}, {0, 3.98}}], {GrayLevel[0], GeometricTransformation[Inset[Style["Rule 8\[Diamond]", FontSize -> 10], {0.15, 2}], {{{0, 1}, {-1, 0}}, Center}]}, {RGBColor[0.3, 1., 0.3], Thickness[Large], Line[{{-3.98, 0}, {-1, 0}}], {GrayLevel[0], Inset[Style["Rule 9 \[RightArrow]\[Diamond]", FontSize -> 10], {Rational[-5, 2], 0.13}]}, {RGBColor[0, 0, 1], Thickness[Large], Line[{{-1, 0}, {3.98, 0}}], {GrayLevel[0], Inset[Style["Rule 10\[Diamond]", FontSize -> 10], {2, 0.13}]}, {RGBColor[0, 1, 1], Disk[{-1, 0}, Scaled[Rational[1, 60]]]}, {GrayLevel[0], Inset["a", {-0.99, 0}]}, {RGBColor[0, 1, 1], Disk[{-1, -1}, Scaled[Rational[1, 60]]]}, {GrayLevel[0], Inset["b", {-0.99, -1}]}, {RGBColor[0, 1, 1], Disk[{-1, Rational[-1, 2]}, Scaled[Rational[1, 60]]]}, {GrayLevel[0], Inset["c", {-0.99, Rational[-1, 2]}]}, {RGBColor[0, 1, 1], Disk[{Rational[-1, 2], -1}, Scaled[Rational[1, 60]]]}, {GrayLevel[0], Inset["d", {-0.49, -1}]}, {RGBColor[0, 1, 1], Disk[{Rational[-1, 2], Rational[-1, 2]}, Scaled[Rational[1, 60]]]}, {GrayLevel[0], Inset["e", {-0.49, Rational[-1, 2]}]}, {RGBColor[0, 1, 1], Disk[{Rational[-1, 2], Rational[-3, 2]}, Scaled[Rational[1, 60]]]}, {GrayLevel[0], Inset["f", {-0.49, Rational[-3, 2]}]}, {RGBColor[0, 1, 1], Disk[{Rational[-3, 2], Rational[-1, 2]}, Scaled[Rational[1, 60]]]}, {GrayLevel[0], Inset["g", {-1.49, Rational[-1, 2]}]}}}}}}}}}}}}, Axes -> True, AxesLabel -> {$CellContext`n, $CellContext`j $CellContext`k $CellContext`m}, ImageSize -> Medium]*)


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
(*\[Integral](sin^j(z))^m (A+B sin^k(z)+C sin^(2k)(z))\[DifferentialD]z when j^2=1\[And]k^2=1*)


(* ::Subsubtitle::Bold:: *)
(*Rules 7-8:  \[Integral](Sin[c+d x]^j)^m (A+B Sin[c+d x]^k+C Sin[c+d x]^(2k))\[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Derivation: Rule 7b with B=0 and A+(A+C)(m+(k+1)/2)=0*)


(* ::Subsubsection:: *)
(*Rule 7a: If  j^2=k^2=1 \[And] A+(A+C)(j k m+(k+1)/2)=0, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral](Sin[c+d x]^j)^m (A+C Sin[c+d x]^(2k))\[DifferentialD]x  \[LongRightArrow]  ((A Cos[c+d x](Sin[c+d x]^j)^(m+j k))/(d(j k m+(k+1)/2)))*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[(sin[c_.+d_.*x_]^j_.)^m_*(A_+C_.*sin[c_.+d_.*x_]^k2_),x_Symbol] :=
  A*Cos[c+d*x]*(Sin[c+d*x]^j)^(m+j*k2/2)/(d*(j*k2/2*m+(k2/2+1)/2)) /;
FreeQ[{c,d,A,C,m},x] && OneQ[j^2,k2^2/4] && ZeroQ[A+(A+C)*(j*k2/2*m+(k2/2+1)/2)]


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Derivation: Rule 5 with a=1, b=0 and  n=0*)


(* ::Subsubsection:: *)
(*Rule 7b: If  j^2=k^2=1 \[And] j k m+(k+1)/2!=0  \[And] j k m<=-1 , then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral](Sin[c+d x]^j)^m (A+B Sin[c+d x]^k+C Sin[c+d x]^(2k))\[DifferentialD]x  \[LongRightArrow]  ((A Cos[c+d x](Sin[c+d x]^j)^(m+j k))/(d(j k m+(k+1)/2)))+*)
(*1/(j k m+(k+1)/2) \[Integral](Sin[c+d x]^j)^(m+j k) (B(j k m+(k+1)/2)+(A+(A+C)(j k m+(k+1)/2))Sin[c+d x]^k )\[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[(sin[c_.+d_.*x_]^j_.)^m_.*(A_.+B_.*sin[c_.+d_.*x_]^k_.+C_.*sin[c_.+d_.*x_]^k2_),x_Symbol] :=
  A*Cos[c+d*x]*(Sin[c+d*x]^j)^(m+j*k)/(d*(j*k*m+(k+1)/2)) + 
  Dist[1/(j*k*m+(k+1)/2),
    Int[(sin[c+d*x]^j)^(m+j*k)*Sim[B*(j*k*m+(k+1)/2)+(A+(A+C)*(j*k*m+(k+1)/2))*sin[c+d*x]^k,x],x]] /;
FreeQ[{c,d,A,B,C},x] && OneQ[j^2,k^2] && k2===2*k && RationalQ[m] && j*k*m+(k+1)/2!=0 && j*k*m<=-1


(* ::Code:: *)
Int[(sin[c_.+d_.*x_]^j_.)^m_.*(A_+C_.*sin[c_.+d_.*x_]^k2_),x_Symbol] :=
  A*Cos[c+d*x]*(Sin[c+d*x]^j)^(m+j*k2/2)/(d*(j*k2/2*m+(k2/2+1)/2)) + 
  Dist[(A+(A+C)*(j*k2/2*m+(k2/2+1)/2))/(j*k2/2*m+(k2/2+1)/2),Int[(sin[c+d*x]^j)^(m+j*k2),x]] /;
FreeQ[{c,d,A,C},x] && OneQ[j^2,k2^2/4] && RationalQ[m] && j*k2/2*m+(k2/2+1)/2!=0 && j*k2/2*m<=-1


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Derivation: Rule 2 with a=0, b=1 and  n=0*)


(* ::Subsubsection:: *)
(*Rule 8: If  j^2=k^2=1 \[And] j k m+(k+3)/2!=0  \[And] j k m>=-1, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral](Sin[c+d x]^j)^m (A+B Sin[c+d x]^k+C Sin[c+d x]^(2k))\[DifferentialD]x  \[LongRightArrow]  -((C Cos[c+d x](Sin[c+d x]^j)^(m+j k))/(d (j k m+(k+3)/2)))+*)
(*1/(j k m+(k+3)/2) \[Integral](Sin[c+d x]^j)^m (A+(A+C)(j k m+(k+1)/2)+B(j k m+(k+3)/2)Sin[c+d x]^k)\[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[(sin[c_.+d_.*x_]^j_.)^m_.*(A_.+B_.*sin[c_.+d_.*x_]^k_.+C_.*sin[c_.+d_.*x_]^k2_),x_Symbol] :=
  -C*Cos[c+d*x]*(Sin[c+d*x]^j)^(m+j*k)/(d*(j*k*m+(k+3)/2)) + 
  Dist[1/(j*k*m+(k+3)/2),
    Int[(sin[c+d*x]^j)^m*Sim[A+(A+C)*(j*k*m+(k+1)/2)+B*(j*k*m+(k+3)/2)*sin[c+d*x]^k,x],x]] /;
FreeQ[{c,d,A,B,C},x] && OneQ[j^2,k^2] && k2===2*k && RationalQ[m] && j*k*m+(k+3)/2!=0 && j*k*m>=-1


(* ::Code:: *)
Int[(sin[c_.+d_.*x_]^j_.)^m_.*(A_+C_.*sin[c_.+d_.*x_]^k2_),x_Symbol] :=
  -C*Cos[c+d*x]*(Sin[c+d*x]^j)^(m+j*k2/2)/(d*(j*k2/2*m+(k2/2+3)/2)) + 
  Dist[(A+(A+C)*(j*k2/2*m+(k2/2+1)/2))/(j*k2/2*m+(k2/2+3)/2),Int[(sin[c+d*x]^j)^m,x]] /;
FreeQ[{c,d,A,C},x] && OneQ[j^2,k2^2/4] && RationalQ[m] && j*k2/2*m+(k2/2+3)/2!=0 && j*k2/2*m>=-1


(* ::PageBreak:: *)
(**)


(* ::Title::Plain::Closed:: *)
(* Integration Rules for *)
(*\[Integral](A+B sin^k(z)+C sin^(2k)(z))(a+b sin^k(z))^n \[DifferentialD]z when k^2=1*)


(* ::Subsubtitle::Bold::Closed:: *)
(*Rule a:  \[Integral](A+B Sin[c+d x]^k+C Sin[c+d x]^(2k))/(a+b Sin[c+d x]^k) \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Derivation: Algebraic expansion*)


(* ::Subsubsection:: *)
(*Basis: (A+B z+C z^2)/(a+b z)=(C z)/b+(b A+(b B-a C)z)/(b(a+b z))*)


(* ::Subsubsection:: *)
(*Rule a1:*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral](A+B Sin[c+d x]+C Sin[c+d x]^2)/(a+b Sin[c+d x]) \[DifferentialD]x  \[LongRightArrow]  -((C Cos[c+d x])/(b d))+1/b \[Integral](b A+(b B-a C)Sin[c+d x])/(a+b Sin[c+d x]) \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[(A_.+B_.*sin[c_.+d_.*x_]+C_.*sin[c_.+d_.*x_]^2)/(a_+b_.*sin[c_.+d_.*x_]),x_Symbol] :=
  -C*Cos[c+d*x]/(b*d) + Dist[1/b,Int[(b*A+(b*B-a*C)*sin[c+d*x])/(a+b*sin[c+d*x]),x]] /;
FreeQ[{a,b,c,d,A,B,C},x]


(* ::Code:: *)
Int[(A_+C_.*sin[c_.+d_.*x_]^2)/(a_+b_.*sin[c_.+d_.*x_]),x_Symbol] :=
  -C*Cos[c+d*x]/(b*d) + Dist[1/b,Int[(b*A-a*C*sin[c+d*x])/(a+b*sin[c+d*x]),x]] /;
FreeQ[{a,b,c,d,A,C},x]


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Derivation: Algebraic expansion*)


(* ::Subsubsection:: *)
(*Basis: (A+B z^-1+C z^-2)/(a+b z^-1)=A/a+(a C-(b A-a B) z)/(a z (b+a z))*)


(* ::Subsubsection:: *)
(*Rule a2: If a^2-b^2!=0, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral](A+B Csc[c+d x]+C Csc[c+d x]^2)/(a+b Csc[c+d x]) \[DifferentialD]x  \[LongRightArrow]  ((A x)/a)+\[Integral](C+(B-b A/a)Sin[c+d x])/(Sin[c+d x](b+a Sin[c+d x])) \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[(A_.+B_.*sin[c_.+d_.*x_]^(-1)+C_.*sin[c_.+d_.*x_]^(-2))/(a_+b_.*sin[c_.+d_.*x_]^(-1)),x_Symbol] :=
  A*x/a + Int[(C+(B-b*A/a)*sin[c+d*x])/(sin[c+d*x]*(b+a*sin[c+d*x])),x] /;
FreeQ[{a,b,c,d,A,B,C},x] && NonzeroQ[a^2-b^2]


(* ::Code:: *)
Int[(A_+C_.*sin[c_.+d_.*x_]^(-2))/(a_+b_.*sin[c_.+d_.*x_]^(-1)),x_Symbol] :=
  A*x/a + Int[(C-b*A/a*sin[c+d*x])/(sin[c+d*x]*(b+a*sin[c+d*x])),x] /;
FreeQ[{a,b,c,d,A,C},x] && NonzeroQ[a^2-b^2]


(* ::PageBreak:: *)
(**)


(* ::Subsubtitle::Bold::Closed:: *)
(*\[Integral](A+B Csc[c+d x]+C Csc[c+d x]^2) (a+b Csc[c+d x])^(n/2) \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Derivation: Piecewise constant extraction*)


(* ::Subsubsection:: *)
(*Basis: \!\( *)
(*\*SubscriptBox[\(\[PartialD]\), \(z\)]\(( *)
(*\*SqrtBox[\(z\)] *)
(*\*SqrtBox[\(1/z\)])\)\)=0*)


(* ::Subsubsection:: *)
(*Rule: If  n^2=1, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral](A+B Csc[c+d x]+C Csc[c+d x]^2)(b Csc[c+d x])^(n/2) \[DifferentialD]x  \[LongRightArrow]*)
(*(Sin[c+d x])^(n/2) (b Csc[c+d x])^(n/2) \[Integral](C+B Sin[c+d x]+A Sin[c+d x]^2)/Sin[c+d x]^(n/2+2) \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[(A_+B_.*sin[c_.+d_.*x_]^(-1)+C_.*sin[c_.+d_.*x_]^(-2))*(b_.*sin[c_.+d_.*x_]^(-1))^n_,x_Symbol] :=
  Dist[Sin[c+d*x]^n*(b*Csc[c+d*x])^n,Int[(C+B*sin[c+d*x]+A*sin[c+d*x]^2)/sin[c+d*x]^(n+2),x]] /;
FreeQ[{b,c,d,A,B,C},x] && ZeroQ[n^2-1/4]


(* ::Code:: *)
Int[(A_+C_.*sin[c_.+d_.*x_]^(-2))*(b_.*sin[c_.+d_.*x_]^(-1))^n_,x_Symbol] :=
  Dist[Sin[c+d*x]^n*(b*Csc[c+d*x])^n,Int[(C+A*sin[c+d*x]^2)/sin[c+d*x]^(n+2),x]] /;
FreeQ[{b,c,d,A,C},x] && ZeroQ[n^2-1/4]


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
(*Rule: If  a^2-b^2!=0 \[And] n-1/2\[Element]\[DoubleStruckCapitalZ] \[And] -2<n<0, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral](A+B Csc[c+d x]+C Csc[c+d x]^2)(a+b Csc[c+d x])^n \[DifferentialD]x  \[LongRightArrow]  *)
(*(Sqrt[b+a Sin[c+d x]]/(Sqrt[Sin[c+d x]] Sqrt[a+b Csc[c+d x]]))\[Integral]((C+B Sin[c+d x]+A Sin[c+d x]^2)(b+a Sin[c+d x])^n)/Sin[c+d x]^(n+2) \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[(A_.+B_.*sin[c_.+d_.*x_]^(-1)+C_.*sin[c_+d_.*x_]^(-2))*(a_.+b_.*sin[c_.+d_.*x_]^(-1))^n_,x_Symbol] :=
  Dist[Sqrt[b+a*Sin[c+d*x]]/(Sqrt[Sin[c+d*x]]*Sqrt[a+b*Csc[c+d*x]]),
    Int[(C+B*sin[c+d*x]+A*sin[c+d*x]^2)*(b+a*sin[c+d*x])^n/sin[c+d*x]^(n+2),x]] /;
FreeQ[{a,b,c,d,A,B,C},x] && NonzeroQ[a^2-b^2] && IntegerQ[n-1/2] && -2<n<0


(* ::Code:: *)
Int[(A_.+C_.*sin[c_.+d_.*x_]^(-2))*(a_+b_.*sin[c_.+d_.*x_]^(-1))^n_,x_Symbol] :=
  Dist[Sqrt[b+a*Sin[c+d*x]]/(Sqrt[Sin[c+d*x]]*Sqrt[a+b*Csc[c+d*x]]),
    Int[(C+A*sin[c+d*x]^2)*(b+a*sin[c+d*x])^n/sin[c+d*x]^(n+2),x]] /;
FreeQ[{a,b,c,d,A,C},x] && NonzeroQ[a^2-b^2] && IntegerQ[n-1/2] && -2<n<0


(* ::PageBreak:: *)
(**)


(* ::Subsubtitle::Bold::Closed:: *)
(*\[Integral](A+B Sin[c+d x]^k+C Sin[c+d x]^(2k)) (a+b Sin[c+d x]^k)^n \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Derivation: Algebraic simplification*)


(* ::Subsubsection:: *)
(*Basis: If  a^2 C-a b B+b^2 A=0, then A+B z+C z^2=1/b^2 (b B-a C+b C z)(a+b z)*)


(* ::Subsubsection:: *)
(*Rule: If  k^2=1 \[And] a^2 C-a b B+b^2 A=0 \[And] n<-1, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral](A+B Sin[c+d x]^k+C Sin[c+d x]^(2k)) (a+b Sin[c+d x]^k)^n \[DifferentialD]x  \[LongRightArrow]  *)
(*(1 /b^2)\[Integral](b B-a C+b C Sin[c+d x]^k)(a+b Sin[c+d x]^k)^(n+1) \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[(A_.+B_.*sin[c_.+d_.*x_]^k_.+C_.*sin[c_.+d_.*x_]^k2_)*(a_+b_.*sin[c_.+d_.*x_]^k_.)^n_,x_Symbol] :=
  Dist[1/b^2,Int[Sim[b*B-a*C+b*C*sin[c+d*x]^k,x]*(a+b*sin[c+d*x]^k)^(n+1),x]] /;
FreeQ[{a,b,c,d,A,B,C},x] && OneQ[k^2] && k2===2*k && ZeroQ[a^2*C-a*b*B+b^2*A] && RationalQ[n] && 
  n<-1


(* ::Code:: *)
Int[(A_+C_.*sin[c_.+d_.*x_]^k2_)*(a_+b_.*sin[c_.+d_.*x_]^k_.)^n_.,x_Symbol] :=
  Dist[C/b^2,Int[Sim[-a+b*sin[c+d*x]^k,x]*(a+b*sin[c+d*x]^k)^(n+1),x]] /;
FreeQ[{a,b,c,d,A,C},x] && OneQ[k^2] && k2===2*k && ZeroQ[a^2*C+b^2*A] && RationalQ[n] && n<-1


(* ::PageBreak:: *)
(**)


(* ::Subsubtitle::Bold::Closed:: *)
(*Rules 17-18:  \[Integral](A+B Csc[c+d x]+C Csc[c+d x]^2) (a+b Csc[c+d x])^n \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Derivation: Rule 6 with m=0 and k=-1*)


(* ::Subsubsection:: *)
(*Rule 17: If  a^2-b^2!=0 \[And] a^2 C-a b B+b^2 A!=0 \[And] n<-1, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral](A+B Csc[c+d x]+C Csc[c+d x]^2) (a+b Csc[c+d x])^n \[DifferentialD]x  \[LongRightArrow]  *)
(*(((a^2 C-a b B+b^2 A) Cot[c+d x](a+b Csc[c+d x])^(n+1))/(a d (n+1) (a^2-b^2)))+1/(a (n+1) (a^2-b^2))\[CenterDot]*)
(* \[Integral](A (a^2-b^2) (n+1)-a(b A-a B+b C)(n+1)Csc[c+d x]+(a^2 C-a b B+b^2 A)(n+2)Csc[c+d x]^2)(a+b Csc[c+d x])^(n+1) \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[(A_.+B_.*sin[c_.+d_.*x_]^(-1)+C_.*sin[c_.+d_.*x_]^(-2))*(a_+b_.*sin[c_.+d_.*x_]^(-1))^n_,x_Symbol] :=
  (a^2*C-a*b*B+b^2*A)*Cot[c+d*x]*(a+b*Csc[c+d*x])^(n+1)/(a*d*(n+1)*(a^2-b^2)) + 
  Dist[1/(a*(n+1)*(a^2-b^2)),
    Int[Sim[A*(a^2-b^2)*(n+1)-(a*(b*A-a*B+b*C)*(n+1))*sin[c+d*x]^(-1)+
        (a^2*C-a*b*B+b^2*A)*(n+2)*sin[c+d*x]^(-2),x]*
      (a+b*sin[c+d*x]^(-1))^(n+1),x]] /;
FreeQ[{a,b,c,d,A,B,C},x] && NonzeroQ[a^2-b^2] && NonzeroQ[a^2*C-a*b*B+b^2*A] && RationalQ[n] && n<-1


(* ::Code:: *)
Int[(A_.+C_.*sin[c_.+d_.*x_]^(-2))*(a_+b_.*sin[c_.+d_.*x_]^(-1))^n_,x_Symbol] :=
  (a^2*C+b^2*A)*Cot[c+d*x]*(a+b*Csc[c+d*x])^(n+1)/(a*d*(n+1)*(a^2-b^2)) + 
  Dist[1/(a*(n+1)*(a^2-b^2)),
    Int[Sim[A*(a^2-b^2)*(n+1)-(a*b*(A+C)*(n+1))*sin[c+d*x]^(-1)+(a^2*C+b^2*A)*(n+2)*sin[c+d*x]^(-2),x]*
      (a+b*sin[c+d*x]^(-1))^(n+1),x]] /;
FreeQ[{a,b,c,d,A,C},x] && NonzeroQ[a^2-b^2] && NonzeroQ[a^2*C+b^2*A] && RationalQ[n] && n<-1


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Derivation: Rule 3 with m=0 and k=-1*)


(* ::Subsubsection:: *)
(*Note: If  A=B=a^2-b^2=0, there is an a^2-b^2=0 rule that simplifies resulting integrand to (a+b Csc[c+d x])^n.*)


(* ::Subsubsection:: *)
(*Rule 18: If  n>0 \[And] \[Not](A=B=a^2-b^2=0), then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral](A+B Csc[c+d x]+C Csc[c+d x]^2) (a+b Csc[c+d x])^n \[DifferentialD]x  \[LongRightArrow]  *)
(*-((C Cot[c+d x](a+b Csc[c+d x])^n)/(d (n+1)))+1/(n+1)\[CenterDot]*)
(*\[Integral](a A(n+1)+(b A+a B+n(b A+a B+b C))Csc[c+d x]+(a C n+b B (n+1))Csc[c+d x]^2)(a+b Csc[c+d x])^(n-1) \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[(A_.+B_.*sin[c_.+d_.*x_]^(-1)+C_.*sin[c_.+d_.*x_]^(-2))*(a_+b_.*sin[c_.+d_.*x_]^(-1))^n_.,x_Symbol] :=
  -C*Cot[c+d*x]*(a+b*Csc[c+d*x])^n/(d*(n+1)) + 
  Dist[1/(n+1),
    Int[Sim[a*A*(n+1)+(b*A+a*B+n*(b*A+a*B+b*C))*sin[c+d*x]^(-1)+(a*C*n+b*B*(n+1))*sin[c+d*x]^(-2),x]*
      (a+b*sin[c+d*x]^(-1))^(n-1),x]] /;
FreeQ[{a,b,c,d,A,B,C},x] && RationalQ[n] && n>0


(* ::Code:: *)
Int[(A_.+C_.*sin[c_.+d_.*x_]^(-2))*(a_+b_.*sin[c_.+d_.*x_]^(-1))^n_.,x_Symbol] :=
  -C*Cot[c+d*x]*(a+b*Csc[c+d*x])^n/(d*(n+1)) + 
  Dist[1/(n+1),
    Int[Sim[a*A*(n+1)+b*(A+n*(A+C))*sin[c+d*x]^(-1)+a*C*n*sin[c+d*x]^(-2),x]*
      (a+b*sin[c+d*x]^(-1))^(n-1),x]] /;
FreeQ[{a,b,c,d,A,C},x] && RationalQ[n] && n>0 && Not[ZeroQ[A] && ZeroQ[a^2-b^2]]


(* ::PageBreak:: *)
(**)


(* ::Subsubtitle::Bold::Closed:: *)
(*Rules 15-16:  \[Integral](A+B Sin[c+d x]^k+C Sin[c+d x]^(2k)) (b Sin[c+d x]^k)^n \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Derivation: For k=1, Rule 9b with k=1*)


(* ::Subsubsection:: *)
(*Derivation: For k=-1, ???*)


(* ::Subsubsection:: *)
(*Rule 15: If  k^2=1 \[And] n<-1, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral](A+B Sin[c+d x]^k+C Sin[c+d x]^(2k))(b Sin[c+d x]^k)^n \[DifferentialD]x  \[LongRightArrow]  ((2A Cos[c+d x](b Sin[c+d x]^k)^(n+1))/(b d (2n+k+1)))+*)
(*1/(b (2n+k+1)) \[Integral]((2n+k+1) B+(2A+(A+ C)(2n+k+1)) Sin[c+d x]^k)(b Sin[c+d x]^k)^(n+1) \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[(A_.+B_.*sin[c_.+d_.*x_]^k_.+C_.*sin[c_.+d_.*x_]^k2_)*(b_.*sin[c_.+d_.*x_]^k_.)^n_,x_Symbol] :=
  2*A*Cos[c+d*x]*(b*Sin[c+d*x]^k)^(n+1)/(b*d*(2*n+k+1)) + 
  Dist[1/(b*(2*n+k+1)),
    Int[Sim[(2*n+k+1)*B+(2*A+(A+C)*(2*n+k+1))*sin[c+d*x]^k,x]*(b*sin[c+d*x]^k)^(n+1),x]] /;
FreeQ[{b,c,d,A,B,C},x] && OneQ[k^2] && k2===2*k  && RationalQ[n] && n<-1


(* ::Code:: *)
Int[(A_+C_.*sin[c_.+d_.*x_]^k2_)*(b_.*sin[c_.+d_.*x_]^k_.)^n_,x_Symbol] :=
  2*A*Cos[c+d*x]*(b*Sin[c+d*x]^k)^(n+1)/(b*d*(2*n+k+1)) + 
  Dist[(2*A+(A+C)*(2*n+k+1))/(b^2*(2*n+k+1)),Int[(b*sin[c+d*x]^k)^(n+2),x]] /;
FreeQ[{b,c,d,A,C},x] && OneQ[k^2] && k2===2*k  && RationalQ[n] && n<-1


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Derivation: Rule 2 or 3 with m=0 and a=0*)


(* ::Subsubsection:: *)
(*Rule 16: If  k^2=1 \[And] n>-1, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral](A+B Sin[c+d x]^k+C Sin[c+d x]^(2k)) (b Sin[c+d x]^k)^n \[DifferentialD]x  \[LongRightArrow]  -((2C Cos[c+d x](b Sin[c+d x]^k)^(n+1))/(b d (2n+k+3)))+*)
(*1/(2n+k+3) \[Integral](2A+(A+C)(2n+k+1)+B(2n+k+3)Sin[c+d x]^k)(b Sin[c+d x]^k)^n \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[(A_.+B_.*sin[c_.+d_.*x_]^k_.+C_.*sin[c_.+d_.*x_]^k2_)*(b_.*sin[c_.+d_.*x_]^k_.)^n_.,x_Symbol] :=
  -2*C*Cos[c+d*x]*(b*Sin[c+d*x]^k)^(n+1)/(b*d*(2*n+k+3)) + 
  Dist[1/(2*n+k+3),
    Int[Sim[2*A+(A+C)*(2*n+k+1)+B*(2*n+k+3)*sin[c+d*x]^k,x]*(b*sin[c+d*x]^k)^n,x]] /;
FreeQ[{b,c,d,A,B,C},x] && OneQ[k^2] && k2===2*k && RationalQ[n] && n>-1


(* ::Code:: *)
Int[(A_+C_.*sin[c_.+d_.*x_]^k2_)*(b_.*sin[c_.+d_.*x_]^k_.)^n_.,x_Symbol] :=
  -2*C*Cos[c+d*x]*(b*Sin[c+d*x]^k)^(n+1)/(b*d*(2*n+k+3)) + 
  Dist[(2*A+(A+C)*(2*n+k+1))/(2*n+k+3),Int[(b*sin[c+d*x]^k)^n,x]] /;
FreeQ[{b,c,d,A,C},x] && OneQ[k^2] && k2===2*k && RationalQ[n] && n>-1


(* ::PageBreak:: *)
(**)


(* ::Title::Plain::Closed:: *)
(* Integration Rules for *)
(*\[Integral](sin^j(z))^m (A+B sin^k(z)+C sin^(2k)(z))(a+b sin^k(z))^n \[DifferentialD]z when j^2=1\[And]k^2=1*)


(* ::Subsubtitle::Bold::Closed:: *)
(*Rule b:  \[Integral](A+B Sin[c+d x]+C Sin[c+d x]^2)/(Sin[c+d x](a+b Sin[c+d x])) \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Derivation: Algebraic expansion*)


(* ::Subsubsection:: *)
(*Basis: (A+B z+C z^2)/(z(a+b z))=A/(a z)-(b A-a B-a C z)/(a(a+b z))*)


(* ::Subsubsection:: *)
(*Rule b: If  a^2-b^2!=0, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral](A+B Sin[c+d x]+C Sin[c+d x]^2)/(Sin[c+d x](a+b Sin[c+d x])) \[DifferentialD]x  \[LongRightArrow]  (A/a)\[Integral]1/Sin[c+d x] \[DifferentialD]x-1/a \[Integral](b A-a B-a C Sin[c+d x])/(a+b Sin[c+d x]) \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[(A_.+B_.*sin[c_.+d_.*x_]+C_.*sin[c_.+d_.*x_]^2)/(sin[c_.+d_.*x_]*(a_+b_.*sin[c_.+d_.*x_])),x_Symbol] :=
  A/a*Int[1/sin[c+d*x],x] - 
  Dist[1/a,Int[(b*A-a*B-a*C*sin[c+d*x])/(a+b*sin[c+d*x]),x]] /;
FreeQ[{a,b,c,d,A,B,C},x] && NonzeroQ[a^2-b^2]


(* ::Code:: *)
Int[(A_+C_.*sin[c_.+d_.*x_]^2)/(sin[c_.+d_.*x_]*(a_+b_.*sin[c_.+d_.*x_])),x_Symbol] :=
  A/a*Int[1/sin[c+d*x],x] - 
  Dist[1/a,Int[(b*A-a*C*sin[c+d*x])/(a+b*sin[c+d*x]),x]] /;
FreeQ[{a,b,c,d,A,C},x] && NonzeroQ[a^2-b^2]


(* ::PageBreak:: *)
(**)


(* ::Subsubtitle::Bold::Closed:: *)
(*Rule c:  \[Integral](A+B Sin[c+d x]+C Sin[c+d x]^2)/(Sqrt[Sin[c+d x]] (a+b Sin[c+d x])) \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Derivation: Algebraic expansion*)


(* ::Subsubsection:: *)
(*Rule c: If  a^2-b^2!=0, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral](A+B Sin[c+d x]+C Sin[c+d x]^2)/(Sqrt[Sin[c+d x]] (a+b Sin[c+d x])) \[DifferentialD]x  \[LongRightArrow]  *)
(*(C/b)\[Integral]Sqrt[Sin[c+d x]]\[DifferentialD]x+1/b \[Integral](b A+(b B-a C) Sin[c+d x])/(Sqrt[Sin[c+d x]] (a+b Sin[c+d x])) \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[(A_.+B_.*sin[c_.+d_.*x_]+C_.*sin[c_.+d_.*x_]^2)/(Sqrt[sin[c_.+d_.*x_]]*(a_+b_.*sin[c_.+d_.*x_])),x_Symbol] :=
  Dist[C/b,Int[Sqrt[sin[c+d*x]],x]] + 
  Dist[1/b,Int[Sim[b*A+(b*B-a*C)*sin[c+d*x],x]/(Sqrt[sin[c+d*x]]*(a+b*sin[c+d*x])),x]] /;
FreeQ[{a,b,c,d,A,B,C},x] && NonzeroQ[a^2-b^2]


(* ::Code:: *)
Int[(A_+C_.*sin[c_.+d_.*x_]^2)/(Sqrt[sin[c_.+d_.*x_]]*(a_+b_.*sin[c_.+d_.*x_])),x_Symbol] :=
  Dist[C/b,Int[Sqrt[sin[c+d*x]],x]] + 
  Dist[1/b,Int[(b*A-a*C*sin[c+d*x])/(Sqrt[sin[c+d*x]]*(a+b*sin[c+d*x])),x]] /;
FreeQ[{a,b,c,d,A,C},x] && NonzeroQ[a^2-b^2]


(* ::PageBreak:: *)
(**)


(* ::Subsubtitle::Bold::Closed:: *)
(*Rule d:  \[Integral](A+B Sin[c+d x]+C Sin[c+d x]^2)/(Sin[c+d x]Sqrt[a+b Sin[c+d x]]) \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Derivation: Algebraic expansion*)


(* ::Subsubsection:: *)
(*Rule d: If  a^2-b^2!=0, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral](A+B Sin[c+d x]+C Sin[c+d x]^2)/(Sin[c+d x]Sqrt[a+b Sin[c+d x]]) \[DifferentialD]x  \[LongRightArrow]  *)
(*(C/b)\[Integral]Sqrt[a+b Sin[c+d x]]\[DifferentialD]x+1/b \[Integral](b A+(b B-a C) Sin[c+d x])/(Sin[c+d x]Sqrt[a+b Sin[c+d x]]) \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[(A_.+B_.*sin[c_.+d_.*x_]+C_.*sin[c_.+d_.*x_]^2)/(sin[c_.+d_.*x_]*Sqrt[a_+b_.*sin[c_.+d_.*x_]]),x_Symbol] :=
  Dist[C/b,Int[Sqrt[a+b*sin[c+d*x]],x]] +
  Dist[1/b,Int[Sim[b*A+(b*B-a*C)*sin[c+d*x],x]/(sin[c+d*x]*Sqrt[a+b*sin[c+d*x]]),x]] /;
FreeQ[{a,b,c,d,A,B,C},x] && NonzeroQ[a^2-b^2]


(* ::Code:: *)
Int[(A_+C_.*sin[c_.+d_.*x_]^2)/(sin[c_.+d_.*x_]*Sqrt[a_+b_.*sin[c_.+d_.*x_]]),x_Symbol] :=
  Dist[C/b,Int[Sqrt[a+b*sin[c+d*x]],x]] + 
  Dist[1/b,Int[(A*b-a*C*sin[c+d*x])/(sin[c+d*x]*Sqrt[a+b*sin[c+d*x]]),x]] /;
FreeQ[{a,b,c,d,A,C},x] && NonzeroQ[a^2-b^2]


(* ::PageBreak:: *)
(**)


(* ::Subsubtitle::Bold::Closed:: *)
(*Rule e:  \[Integral](A+B Sin[c+d x]+C Sin[c+d x]^2)/(Sqrt[Sin[c+d x]] Sqrt[a+b Sin[c+d x]]) \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Rule e1: If  a^2-b^2!=0 \[And] 2 b A-a C=0, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral](A+A Sin[c+d x]+C Sin[c+d x]^2)/(Sqrt[Sin[c+d x]] Sqrt[a+b Sin[c+d x]]) \[DifferentialD]x  \[LongRightArrow]  *)
(*((C Sqrt[Sin[c+d x]] Sqrt[a+b Sin[c+d x]] Tan[1/2 (c-\[Pi]/2+d x)])/(b d))+C/b \[Integral]Sqrt[a+b Sin[c+d x]]/(Sqrt[Sin[c+d x]] (1+Sin[c+d x])) \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[(A_+B_.*sin[c_.+d_.*x_]+C_.*sin[c_.+d_.*x_]^2)/(Sqrt[sin[c_.+d_.*x_]]*Sqrt[a_+b_.*sin[c_.+d_.*x_]]),x_Symbol] :=
  C*Sqrt[Sin[c+d*x]]*Sqrt[a+b*Sin[c+d*x]]*Tan[(c-Pi/2+d*x)/2]/(b*d) + 
  C/b*Int[Sqrt[a+b*sin[c+d*x]]/(Sqrt[sin[c+d*x]]*(1+sin[c+d*x])),x] /;
FreeQ[{a,b,c,d,A,B,C},x] && NonzeroQ[a^2-b^2] && ZeroQ[A-B] && ZeroQ[2*b*A-a*C]


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Derivation: Algebraic expansion*)


(* ::Subsubsection:: *)
(*Rule e2: If  a^2-b^2!=0, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral](A+C Sin[c+d x]^2)/(Sqrt[Sin[c+d x]] Sqrt[a+b Sin[c+d x]]) \[DifferentialD]x  \[LongRightArrow]  *)
(*A\[Integral]1/(Sqrt[Sin[c+d x]] Sqrt[a+b Sin[c+d x]]) \[DifferentialD]x+C \[Integral]Sin[c+d x]^(3/2)/Sqrt[a+b Sin[c+d x]] \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[(A_+C_.*sin[c_.+d_.*x_]^2)/(Sqrt[sin[c_.+d_.*x_]]*Sqrt[a_+b_.*sin[c_.+d_.*x_]]),x_Symbol] :=
  A*Int[1/(Sqrt[sin[c+d*x]]*Sqrt[a+b*sin[c+d*x]]),x] + 
  Dist[C,Int[sin[c+d*x]^(3/2)/Sqrt[a+b*sin[c+d*x]],x]] /;
FreeQ[{a,b,c,d,A,C},x] && NonzeroQ[a^2-b^2]


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Derivation: Algebraic expansion*)


(* ::Subsubsection:: *)
(*Rule e3: If  a^2-b^2!=0, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral](A+B Sin[c+d x]+C Sin[c+d x]^2)/(Sqrt[Sin[c+d x]] Sqrt[a+b Sin[c+d x]]) \[DifferentialD]x  \[LongRightArrow]  *)
(*(1/(2b)) \[Integral](2b A-a C+(2 b B-a C) Sin[c+d x])/(Sqrt[Sin[c+d x]] Sqrt[a+b Sin[c+d x]]) \[DifferentialD]x+C/(2b) \[Integral](a+a Sin[c+d x]+2 b Sin[c+d x]^2)/(Sqrt[Sin[c+d x]] Sqrt[a+b Sin[c+d x]]) \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[(A_.+B_.*sin[c_.+d_.*x_]+C_.*sin[c_.+d_.*x_]^2)/(Sqrt[sin[c_.+d_.*x_]]*Sqrt[a_+b_.*sin[c_.+d_.*x_]]),x_Symbol] :=
  Dist[1/(2*b),Int[(2*b*A-a*C+(2*b*B-a*C)*sin[c+d*x])/(Sqrt[sin[c+d*x]]*Sqrt[a+b*sin[c+d*x]]),x]] + 
  Dist[C/(2*b),Int[(a+a*sin[c+d*x]+2*b*sin[c+d*x]^2)/(Sqrt[sin[c+d*x]]*Sqrt[a+b*sin[c+d*x]]),x]] /;
FreeQ[{a,b,c,d,A,B,C},x] && NonzeroQ[a^2-b^2]


(* ::PageBreak:: *)
(**)


(* ::Subsubtitle::Bold::Closed:: *)
(*Rule f:  \[Integral](A+B Sin[c+d x]+C Sin[c+d x]^2)/(Sin[c+d x]^(3/2) Sqrt[a+b Sin[c+d x]]) \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Derivation: Algebraic expansion*)


(* ::Subsubsection:: *)
(*Note: This rule is not essential, but produces simpler results.*)


(* ::Subsubsection:: *)
(*Rule f: If  a^2-b^2!=0, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral](A+B Sin[c+d x]+C Sin[c+d x]^2)/(Sin[c+d x]^(3/2) Sqrt[a+b Sin[c+d x]]) \[DifferentialD]x  \[LongRightArrow]  *)
(*C\[Integral](1+Sin[c+d x])/(Sqrt[Sin[c+d x]] Sqrt[a+b Sin[c+d x]]) \[DifferentialD]x+\[Integral](A+(B-C)Sin[c+d x])/(Sin[c+d x]^(3/2) Sqrt[a+b Sin[c+d x]]) \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[(A_.+B_.*sin[c_.+d_.*x_]+C_.*sin[c_.+d_.*x_]^2)/(sin[c_.+d_.*x_]^(3/2)*Sqrt[a_+b_.*sin[c_.+d_.*x_]]),x_Symbol] :=
  Dist[C,Int[(1+sin[c+d*x])/(Sqrt[sin[c+d*x]]*Sqrt[a+b*sin[c+d*x]]),x]] + 
  Int[(A+(B-C)*sin[c+d*x])/(sin[c+d*x]^(3/2)*Sqrt[a+b*sin[c+d*x]]),x] /;
FreeQ[{a,b,c,d,A,B,C},x] && NonzeroQ[a^2-b^2]


(* ::Code:: *)
Int[(A_+C_.*sin[c_.+d_.*x_]^2)/(sin[c_.+d_.*x_]^(3/2)*Sqrt[a_+b_.*sin[c_.+d_.*x_]]),x_Symbol] :=
  Dist[C,Int[(1+sin[c+d*x])/(Sqrt[sin[c+d*x]]*Sqrt[a+b*sin[c+d*x]]),x]] + 
  Int[(A-C*sin[c+d*x])/(sin[c+d*x]^(3/2)*Sqrt[a+b*sin[c+d*x]]),x] /;
FreeQ[{a,b,c,d,A,C},x] && NonzeroQ[a^2-b^2]


(* ::PageBreak:: *)
(**)


(* ::Subsubtitle::Bold::Closed:: *)
(*Rule g:  \[Integral](A+B Sin[c+d x]+C Sin[c+d x]^2)/(Sqrt[Sin[c+d x]] (a+b Sin[c+d x])^(3/2)) \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Derivation: Algebraic expansion*)


(* ::Subsubsection:: *)
(*Note: This rule is not essential, but produces simpler results.*)


(* ::Subsubsection:: *)
(*Rule g: If  a^2-b^2!=0, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral](A+B Sin[c+d x]+C Sin[c+d x]^2)/(Sqrt[Sin[c+d x]] (a+b Sin[c+d x])^(3/2)) \[DifferentialD]x  \[LongRightArrow]  *)
(*(C/b)\[Integral](1+Sin[c+d x])/(Sqrt[Sin[c+d x]] Sqrt[a+b Sin[c+d x]]) \[DifferentialD]x+1/b \[Integral](b A-a C+(b B-C(a+b)) Sin[c+d x])/(Sqrt[Sin[c+d x]] (a+b Sin[c+d x])^(3/2)) \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[(A_.+B_.*sin[c_.+d_.*x_]+C_.*sin[c_.+d_.*x_]^2)/(Sqrt[sin[c_.+d_.*x_]]*(a_+b_.*sin[c_.+d_.*x_])^(3/2)),x_Symbol] :=
  Dist[C/b,Int[(1+sin[c+d*x])/(Sqrt[sin[c+d*x]]*Sqrt[a+b*sin[c+d*x]]),x]] + 
  Dist[1/b,Int[(b*A-a*C+(b*B-C*(a+b))*sin[c+d*x])/(Sqrt[sin[c+d*x]]*(a+b*sin[c+d*x])^(3/2)),x]] /;
FreeQ[{a,b,c,d,A,B,C},x] && NonzeroQ[a^2-b^2]


(* ::Code:: *)
Int[(A_+C_.*sin[c_.+d_.*x_]^2)/(Sqrt[sin[c_.+d_.*x_]]*(a_+b_.*sin[c_.+d_.*x_])^(3/2)),x_Symbol] :=
  Dist[C/b,Int[(1+sin[c+d*x])/(Sqrt[sin[c+d*x]]*Sqrt[a+b*sin[c+d*x]]),x]] + 
  Dist[1/b,Int[(b*A-a*C-C*(a+b)*sin[c+d*x])/(Sqrt[sin[c+d*x]]*(a+b*sin[c+d*x])^(3/2)),x]] /;
FreeQ[{a,b,c,d,A,C},x] && NonzeroQ[a^2-b^2]


(* ::PageBreak:: *)
(**)


(* ::Subsubtitle::Bold::Closed:: *)
(*Rule h:  \[Integral](Sin[c+d x]^j)^m (A+B Sin[c+d x]^k+C Sin[c+d x]^(2k))(b Sin[c+d x]^k)^n \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Derivation: Algebraic simplification*)


(* ::Subsubsection:: *)
(*Rule h1: If  k^2=1 \[And] m\[Element]\[DoubleStruckCapitalZ], then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]Sin[c+d x]^m (A+B Sin[c+d x]^k+C Sin[c+d x]^(2k))(b Sin[c+d x]^k)^n \[DifferentialD]x  \[LongRightArrow]  *)
(*(1/b^(k m))\[Integral](A+B Sin[c+d x]^k+C Sin[c+d x]^(2k))(b Sin[c+d x]^k)^(k m+n) \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[sin[c_.+d_.*x_]^m_.*(A_.+B_.*sin[c_.+d_.*x_]^k_.+C_.*sin[c_.+d_.*x_]^k2_)*
    (b_.*sin[c_.+d_.*x_]^k_.)^n_,x_Symbol] :=
  Dist[1/b^(k*m),Int[(A+B*sin[c+d*x]^k+C*sin[c+d*x]^(2*k))*(b*sin[c+d*x]^k)^(k*m+n),x]] /;
FreeQ[{b,c,d,A,B,C,n},x] && OneQ[k^2] && k2===2*k && IntegerQ[m]


(* ::Code:: *)
Int[sin[c_.+d_.*x_]^m_.*(A_+C_.*sin[c_.+d_.*x_]^k2_)*(b_.*sin[c_.+d_.*x_]^k_.)^n_,x_Symbol] :=
  Dist[1/b^(k*m),Int[(A+C*sin[c+d*x]^(2*k))*(b*sin[c+d*x]^k)^(k*m+n),x]] /;
FreeQ[{b,c,d,A,C,n},x] && OneQ[k^2] && k2===2*k && IntegerQ[m]


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
(*Rule h2: If  j^2=k^2=1 \[And] m-1/2\[Element]\[DoubleStruckCapitalZ] \[And] n-1/2\[Element]\[DoubleStruckCapitalZ] \[And] n>0, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral](Sin[c+d x]^j)^m (A+B Sin[c+d x]^k+C Sin[c+d x]^(2k))(b Sin[c+d x]^k)^n \[DifferentialD]x  \[LongRightArrow]  *)
(*((b^(n-1/2) Sqrt[b Sin[c+d x]^k])/(Sqrt[Sin[c+d x]^j])^(j k))\[Integral]Sin[c+d x]^(j m+k n) (A+B Sin[c+d x]^k+C Sin[c+d x]^(2k))\[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[(sin[c_.+d_.*x_]^j_.)^m_*(A_.+B_.*sin[c_.+d_.*x_]^k_.+C_.*sin[c_.+d_.*x_]^k2_)*
    (b_*sin[c_.+d_.*x_]^k_.)^n_,x_Symbol] :=
  Dist[b^(n-1/2)*Sqrt[b*Sin[c+d*x]^k]/(Sqrt[Sin[c+d*x]^j])^(j*k),
    Int[sin[c+d*x]^(j*m+k*n)*(A+B*sin[c+d*x]^k+C*sin[c+d*x]^(2*k)),x]] /;
FreeQ[{b,c,d,A,B,C},x] && OneQ[j^2,k^2] && IntegerQ[m-1/2] && IntegerQ[n-1/2] && n>0


(* ::Code:: *)
Int[(sin[c_.+d_.*x_]^j_.)^m_*(A_.+C_.*sin[c_.+d_.*x_]^k2_)*(b_*sin[c_.+d_.*x_]^k_.)^n_,x_Symbol] :=
  Dist[b^(n-1/2)*Sqrt[b*Sin[c+d*x]^k]/(Sqrt[Sin[c+d*x]^j])^(j*k),
    Int[sin[c+d*x]^(j*m+k*n)*(A+C*sin[c+d*x]^(2*k)),x]] /;
FreeQ[{b,c,d,A,C},x] && OneQ[j^2,k^2] && IntegerQ[m-1/2] && IntegerQ[n-1/2] && n>0


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
(*Rule h3: If  j^2=k^2=1 \[And] m-1/2\[Element]\[DoubleStruckCapitalZ] \[And] n-1/2\[Element]\[DoubleStruckCapitalZ] \[And] n<0, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral](Sin[c+d x]^j)^m (A+B Sin[c+d x]^k+C Sin[c+d x]^(2k))(b Sin[c+d x]^k)^n \[DifferentialD]x  \[LongRightArrow]  *)
(*((b^(n+1/2) (Sqrt[Sin[c+d x]^j])^(j k))/Sqrt[b Sin[c+d x]^k])\[Integral]Sin[c+d x]^(j m+k n) (A+B Sin[c+d x]^k+C Sin[c+d x]^(2k))\[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[(sin[c_.+d_.*x_]^j_.)^m_*(A_.+B_.*sin[c_.+d_.*x_]^k_.+C_.*sin[c_.+d_.*x_]^k2_)*
    (b_*sin[c_.+d_.*x_]^k_.)^n_,x_Symbol] :=
  Dist[b^(n+1/2)*(Sqrt[Sin[c+d*x]^j])^(j*k)/Sqrt[b*Sin[c+d*x]^k],
    Int[sin[c+d*x]^(j*m+k*n)*(A+B*sin[c+d*x]^k+C*sin[c+d*x]^(2*k)),x]] /;
FreeQ[{b,c,d,A,B,C},x] && OneQ[j^2,k^2] && IntegerQ[m-1/2] && IntegerQ[n-1/2] && n<0


(* ::Code:: *)
Int[(sin[c_.+d_.*x_]^j_.)^m_*(A_.+C_.*sin[c_.+d_.*x_]^k2_)*(b_*sin[c_.+d_.*x_]^k_.)^n_,x_Symbol] :=
  Dist[b^(n+1/2)*(Sqrt[Sin[c+d*x]^j])^(j*k)/Sqrt[b*Sin[c+d*x]^k],
    Int[sin[c+d*x]^(j*m+k*n)*(A+C*sin[c+d*x]^(2*k)),x]] /;
FreeQ[{b,c,d,A,C},x] && OneQ[j^2,k^2] && IntegerQ[m-1/2] && IntegerQ[n-1/2] && n<0


(* ::PageBreak:: *)
(**)


(* ::Subsubtitle::Bold::Closed:: *)
(*Rule i:  \[Integral](Sin[c+d x]^j)^m (A+B Csc[c+d x]+C Csc[c+d x]^2)(a+b Csc[c+d x])^n \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Derivation: Algebraic simplification*)


(* ::Subsubsection:: *)
(*Rule i1: If  j^2=1 \[And] a^2-b^2!=0 \[And] -1<m<=1, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]((Sin[c+d x]^j)^m (A+B Csc[c+d x]+C Csc[c+d x]^2))/(a+b Csc[c+d x]) \[DifferentialD]x  \[LongRightArrow]  *)
(*\[Integral]((Sin[c+d x]^j)^(m-j) (C+B Sin[c+d x]+A Sin[c+d x]^2))/(b+a Sin[c+d x]) \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[(sin[c_.+d_.*x_]^j_.)^m_.*(A_.+B_.*sin[c_.+d_.*x_]^(-1)+C_.*sin[c_.+d_.*x_]^(-2))/
    (a_+b_.*sin[c_.+d_.*x_]^(-1)),x_Symbol] :=
  Int[(sin[c+d*x]^j)^(m-j)*(C+B*sin[c+d*x]+A*sin[c+d*x]^2)/(b+a*sin[c+d*x]),x] /;
FreeQ[{a,b,c,d,A,B,C},x] && OneQ[j^2] && NonzeroQ[a^2-b^2] && RationalQ[m] && -1<m<=1


(* ::Code:: *)
Int[(sin[c_.+d_.*x_]^j_.)^m_.*(A_.+C_.*sin[c_.+d_.*x_]^(-2))/(a_+b_.*sin[c_.+d_.*x_]^(-1)),x_Symbol] :=
  Int[(sin[c+d*x]^j)^(m-j)*(C+A*sin[c+d*x]^2)/(b+a*sin[c+d*x]),x] /;
FreeQ[{a,b,c,d,A,C},x] && OneQ[j^2] && NonzeroQ[a^2-b^2] && RationalQ[m] && -1<m<=1


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
(*Rule i2: If  a^2-b^2!=0, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]( Sin[c+d x](A+B Csc[c+d x]+C Csc[c+d x]^2))/Sqrt[a+b Csc[c+d x]] \[DifferentialD]x  \[LongRightArrow]  *)
(*( Sqrt[b+a Sin[c+d x]]/(Sqrt[Sin[c+d x]] Sqrt[a+b Csc[c+d x]]))\[Integral]( C+B Sin[c+d x]+A Sin[c+d x]^2)/(Sqrt[Sin[c+d x]] Sqrt[b+a Sin[c+d x]]) \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[sin[c_.+d_.*x_]*(A_.+B_.*sin[c_.+d_.*x_]^(-1)+C_.*sin[c_.+d_.*x_]^(-2))/
    Sqrt[a_.+b_.*sin[c_.+d_.*x_]^(-1)],x_Symbol] :=
  Dist[Sqrt[b+a*Sin[c+d*x]]/(Sqrt[Sin[c+d*x]]*Sqrt[a+b*Csc[c+d*x]]),
    Int[(C+B*sin[c+d*x]+A*sin[c+d*x]^2)/(Sqrt[sin[c+d*x]]*Sqrt[b+a*sin[c+d*x]]),x]] /;
FreeQ[{a,b,c,d,A,B,C},x] && NonzeroQ[a^2-b^2]


(* ::Code:: *)
Int[sin[c_.+d_.*x_]*(A_.+C_.*sin[c_.+d_.*x_]^(-2))/Sqrt[a_.+b_.*sin[c_.+d_.*x_]^(-1)],x_Symbol] :=
  Dist[Sqrt[b+a*Sin[c+d*x]]/(Sqrt[Sin[c+d*x]]*Sqrt[a+b*Csc[c+d*x]]),
    Int[(C+A*sin[c+d*x]^2)/(Sqrt[sin[c+d*x]]*Sqrt[b+a*sin[c+d*x]]),x]] /;
FreeQ[{a,b,c,d,A,C},x] && NonzeroQ[a^2-b^2]


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
(*Rule i3: If  j^2=1 \[And] a^2-b^2!=0 \[And] j m=1/2, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]( (Sin[c+d x]^j)^m (A+B Csc[c+d x]+C Csc[c+d x]^2))/Sqrt[a+b Csc[c+d x]] \[DifferentialD]x  \[LongRightArrow]  *)
(*( Sqrt[b+a Sin[c+d x]]/(Sqrt[Sin[c+d x]^j]^j Sqrt[a+b Csc[c+d x]]))\[Integral](Sin[c+d x]^(j m-3/2) ( C+B Sin[c+d x]+A Sin[c+d x]^2))/Sqrt[b+a Sin[c+d x]] \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[(sin[c_.+d_.*x_]^j_.)^m_*(A_.+B_.*sin[c_.+d_.*x_]^(-1)+C_.*sin[c_.+d_.*x_]^(-2))/
    Sqrt[a_.+b_.*sin[c_.+d_.*x_]^(-1)],x_Symbol] :=
  Dist[Sqrt[b+a*Sin[c+d*x]]/((Sqrt[Sin[c+d*x]^j])^j*Sqrt[a+b*Csc[c+d*x]]),
    Int[sin[c+d*x]^(j*m-3/2)*(C+B*sin[c+d*x]+A*sin[c+d*x]^2)/Sqrt[b+a*sin[c+d*x]],x]] /;
FreeQ[{a,b,c,d,A,B,C},x] && OneQ[j^2] && NonzeroQ[a^2-b^2] && ZeroQ[j*m-1/2]


(* ::Code:: *)
Int[(sin[c_.+d_.*x_]^j_.)^m_*(A_.+C_.*sin[c_.+d_.*x_]^(-2))/Sqrt[a_.+b_.*sin[c_.+d_.*x_]^(-1)],x_Symbol] :=
  Dist[Sqrt[b+a*Sin[c+d*x]]/((Sqrt[Sin[c+d*x]^j])^j*Sqrt[a+b*Csc[c+d*x]]),
    Int[sin[c+d*x]^(j*m-3/2)*(C+A*sin[c+d*x]^2)/Sqrt[b+a*sin[c+d*x]],x]] /;
FreeQ[{a,b,c,d,A,C},x] && OneQ[j^2] && NonzeroQ[a^2-b^2] && ZeroQ[j*m-1/2]


(* ::PageBreak:: *)
(**)


(* ::Subsubtitle::Bold::Closed:: *)
(*Rule j:  \[Integral]Csc[c+d x]^m (A+B Sin[c+d x]+C Sin[c+d x]^2)(a+b Sin[c+d x])^n \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Derivation: Piecewise constant extraction*)


(* ::Subsubsection:: *)
(*Basis: \!\( *)
(*\*SubscriptBox[\(\[PartialD]\), \(z\)]\(( *)
(*\*SuperscriptBox[\(Sin[z]\), \(m\)] *)
(*\*SuperscriptBox[\(Csc[z]\), \(m\)])\)\)=0*)


(* ::Subsubsection:: *)
(*Rule j: If  m-1/2\[Element]\[DoubleStruckCapitalZ] \[And] 0<m<2 \[And] -2<n<0, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]Csc[c+d x]^m (A+B Sin[c+d x]+C Sin[c+d x]^2)(a+b Sin[c+d x])^n \[DifferentialD]x  \[LongRightArrow]  *)
(*Sqrt[Csc[c+d x]] Sqrt[Sin[c+d x]]\[Integral]((A+B Sin[c+d x]+C Sin[c+d x]^2)(a+b Sin[c+d x])^n)/Sin[c+d x]^m \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[(sin[c_.+d_.*x_]^(-1))^m_*(A_.+B_.*sin[c_.+d_.*x_]+C_.*sin[c_.+d_.*x_]^2)*
    (a_+b_.*sin[c_.+d_.*x_])^n_,x_Symbol] :=
  Dist[Sqrt[Csc[c+d*x]]*Sqrt[Sin[c+d*x]],
    Int[(A+B*sin[c+d*x]+C*sin[c+d*x]^2)*(a+b*sin[c+d*x])^n/sin[c+d*x]^m,x]] /;
FreeQ[{a,b,c,d,A,B,C},x] && IntegerQ[m-1/2] && RationalQ[n] && 0<m<2 && -2<n<0


(* ::Code:: *)
Int[(sin[c_.+d_.*x_]^(-1))^m_*(A_.+C_.*sin[c_.+d_.*x_]^2)*(a_+b_.*sin[c_.+d_.*x_])^n_,x_Symbol] :=
  Dist[Sqrt[Csc[c+d*x]]*Sqrt[Sin[c+d*x]],
    Int[(A+C*sin[c+d*x]^2)*(a+b*sin[c+d*x])^n/sin[c+d*x]^m,x]] /;
FreeQ[{a,b,c,d,A,C},x] && IntegerQ[m-1/2] && RationalQ[n] && 0<m<2 && -2<n<0


(* ::PageBreak:: *)
(**)


(* ::Subsubtitle::Bold::Closed:: *)
(*Rules 9-10:  \[Integral]Sin[c+d x]^((k-1)/2) (A+B Sin[c+d x]^k+C Sin[c+d x]^(2k)) (a+b Sin[c+d x]^k)^n \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Derivation: Rule 1 with m=(k-1)/2*)


(* ::Subsubsection:: *)
(*Rule 9: If  k^2=1 \[And] a^2-b^2!=0 \[And] a^2 C-a b B+b^2 A!=0 \[And] n<-1, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]Sin[c+d x]^((k-1)/2) (A+B Sin[c+d x]^k+C Sin[c+d x]^(2k)) (a+b Sin[c+d x]^k)^n \[DifferentialD]x  \[LongRightArrow]  *)
(*-(((a^2 C-a b B+b^2 A) Cos[c+d x] Sin[c+d x]^((k-1)/2) (a+b Sin[c+d x]^k)^(n+1))/(b d (n+1) (a^2-b^2)))+1/(b(n+1)(a^2-b^2))\[CenterDot]*)
(*\[Integral]Sin[c+d x]^((k-1)/2) (b(a A-b B+a C)(n+1)-(a^2 C-a b B+b^2 A+(b^2 A-a b B+b^2 C)(n+1))Sin[c+d x]^k)(a+b Sin[c+d x]^k)^(n+1) \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[(A_.+B_.*sin[c_.+d_.*x_]+C_.*sin[c_.+d_.*x_]^2)*(a_+b_.*sin[c_.+d_.*x_])^n_,x_Symbol] :=
  -(a^2*C-a*b*B+b^2*A)*Cos[c+d*x]*(a+b*Sin[c+d*x])^(n+1)/(b*d*(n+1)*(a^2-b^2)) + 
  Dist[1/(b*(n+1)*(a^2-b^2)),
    Int[Sim[b*(a*A-b*B+a*C)*(n+1)-(a^2*C-a*b*B+b^2*A+(b^2*A-a*b*B+b^2*C)*(n+1))*sin[c+d*x],x]*
      (a+b*sin[c+d*x])^(n+1),x]] /;
FreeQ[{a,b,c,d,A,B,C},x] && NonzeroQ[a^2-b^2] && NonzeroQ[a^2*C-a*b*B+b^2*A] && RationalQ[n] && n<-1


(* ::Code:: *)
Int[(A_.+C_.*sin[c_.+d_.*x_]^2)*(a_+b_.*sin[c_.+d_.*x_])^n_,x_Symbol] :=
  -(a^2*C+b^2*A)*Cos[c+d*x]*(a+b*Sin[c+d*x])^(n+1)/(b*d*(n+1)*(a^2-b^2)) + 
  Dist[1/(b*(n+1)*(a^2-b^2)),
    Int[Sim[a*b*(A+C)*(n+1)-(a^2*C+b^2*A+(b^2*A+b^2*C)*(n+1))*sin[c+d*x],x]*
      (a+b*sin[c+d*x])^(n+1),x]] /;
FreeQ[{a,b,c,d,A,C},x] && NonzeroQ[a^2-b^2] && NonzeroQ[a^2*C+b^2*A] && RationalQ[n] && n<-1


(* ::Code:: *)
Int[sin[c_.+d_.*x_]^(-1)*(A_.+B_.*sin[c_.+d_.*x_]^(-1)+C_.*sin[c_.+d_.*x_]^(-2))*
    (a_+b_.*sin[c_.+d_.*x_]^(-1))^n_,x_Symbol] :=
  -(a^2*C-a*b*B+b^2*A)*Cot[c+d*x]*(a+b*Csc[c+d*x])^(n+1)/(b*d*(n+1)*(a^2-b^2)) + 
  Dist[1/(b*(n+1)*(a^2-b^2)),
    Int[sin[c+d*x]^(-1)*
      Sim[b*(a*A-b*B+a*C)*(n+1)-(a^2*C-a*b*B+b^2*A+(b^2*A-a*b*B+b^2*C)*(n+1))*sin[c+d*x]^(-1),x]*
      (a+b*sin[c+d*x]^(-1))^(n+1),x]] /;
FreeQ[{a,b,c,d,A,B,C},x] && NonzeroQ[a^2-b^2] && NonzeroQ[a^2*C-a*b*B+b^2*A] && RationalQ[n] && n<-1


(* ::Code:: *)
Int[sin[c_.+d_.*x_]^(-1)*(A_.+C_.*sin[c_.+d_.*x_]^(-2))*(a_+b_.*sin[c_.+d_.*x_]^(-1))^n_,x_Symbol] :=
  -(a^2*C+b^2*A)*Cot[c+d*x]*(a+b*Csc[c+d*x])^(n+1)/(b*d*(n+1)*(a^2-b^2)) + 
  Dist[1/(b*(n+1)*(a^2-b^2)),
    Int[sin[c+d*x]^(-1)*
      Sim[a*b*(A+C)*(n+1)-(a^2*C+b^2*A+(b^2*A+b^2*C)*(n+1))*sin[c+d*x]^(-1),x]*
      (a+b*sin[c+d*x]^(-1))^(n+1),x]] /;
FreeQ[{a,b,c,d,A,C},x] && NonzeroQ[a^2-b^2] && NonzeroQ[a^2*C+b^2*A] && RationalQ[n] && n<-1


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Derivation: Rule 2 with m=(k-1)/2*)


(* ::Subsubsection:: *)
(*Rule 10: If  k^2=1 \[And] n>-1, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]Sin[c+d x]^((k-1)/2) (A+B Sin[c+d x]^k+C Sin[c+d x]^(2k)) (a+b Sin[c+d x]^k)^n \[DifferentialD]x  \[LongRightArrow]  *)
(*-((C Cos[c+d x]Sin[c+d x]^((k-1)/2) (a+b Sin[c+d x]^k)^(n+1))/(b d (n+2)))+1/(b (n+2))\[CenterDot]*)
(*\[Integral]Sin[c+d x]^((k-1)/2) (b A(n+2)+b C(n+1)+(b B(n+2)-a C)Sin[c+d x]^k)(a+b Sin[c+d x]^k)^n \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[(A_.+B_.*sin[c_.+d_.*x_]+C_.*sin[c_.+d_.*x_]^2)*(a_.+b_.*sin[c_.+d_.*x_])^n_.,x_Symbol] :=
  -C*Cos[c+d*x]*(a+b*Sin[c+d*x])^(n+1)/(b*d*(n+2)) + 
  Dist[1/(b*(n+2)),
    Int[Sim[b*A*(n+2)+b*C*(n+1)+(b*B*(n+2)-a*C)*sin[c+d*x],x]*(a+b*sin[c+d*x])^n,x]] /;
FreeQ[{a,b,c,d,A,B,C},x] && RationalQ[n] && n>-1


(* ::Code:: *)
Int[(A_.+C_.*sin[c_.+d_.*x_]^2)*(a_.+b_.*sin[c_.+d_.*x_])^n_.,x_Symbol] :=
  -C*Cos[c+d*x]*(a+b*Sin[c+d*x])^(n+1)/(b*d*(n+2)) + 
  Dist[1/(b*(n+2)),
    Int[Sim[b*A*(n+2)+b*C*(n+1)-a*C*sin[c+d*x],x]*(a+b*sin[c+d*x])^n,x]] /;
FreeQ[{a,b,c,d,A,C},x] && RationalQ[n] && n>-1


(* ::Code:: *)
Int[sin[c_.+d_.*x_]^(-1)*(A_.+B_.*sin[c_.+d_.*x_]^(-1)+C_.*sin[c_.+d_.*x_]^(-2))*
    (a_+b_.*sin[c_.+d_.*x_]^(-1))^n_.,x_Symbol] :=
  -C*Cot[c+d*x]*(a+b*Csc[c+d*x])^(n+1)/(b*d*(n+2)) + 
  Dist[1/(b*(n+2)),
    Int[sin[c+d*x]^(-1)*
      Sim[b*A*(n+2)+b*C*(n+1)+(b*B*(n+2)-a*C)*sin[c+d*x]^(-1),x]*(a+b*sin[c+d*x]^(-1))^n,x]] /;
FreeQ[{a,b,c,d,A,B,C},x] && RationalQ[n] && n>-1


(* ::Code:: *)
Int[sin[c_.+d_.*x_]^(-1)*(A_.+C_.*sin[c_.+d_.*x_]^(-2))*(a_+b_.*sin[c_.+d_.*x_]^(-1))^n_.,x_Symbol] :=
  -C*Cot[c+d*x]*(a+b*Csc[c+d*x])^(n+1)/(b*d*(n+2)) + 
  Dist[1/(b*(n+2)),
    Int[sin[c+d*x]^(-1)*
      Sim[b*A*(n+2)+b*C*(n+1)-a*C*sin[c+d*x]^(-1),x]*(a+b*sin[c+d*x]^(-1))^n,x]] /;
FreeQ[{a,b,c,d,A,C},x] && RationalQ[n] && n>-1


(* ::PageBreak:: *)
(**)


(* ::Subsubtitle::Bold::Closed:: *)
(*Rules 11-12:  \[Integral](Sin[c+d x]^j)^m (A+B Sin[c+d x]^k+C Sin[c+d x]^(2k)) (a+b Sin[c+d x]^k)\[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Note: The rules in this section would only generate slightly simpler antiderivatives and require as many steps as using rules 3 and 4 directly.*)


(* ::Subsubsection:: *)
(*Derivation: Rule 4 with n=1 and ???*)


(* ::Subsubsection:: *)
(*Rule 11: If  j^2=k^2=1 \[And] j k m<-1, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral](Sin[c+d x]^j)^m (A+B Sin[c+d x]^k+C Sin[c+d x]^(2k))(a+b Sin[c+d x]^k)\[DifferentialD]x  \[LongRightArrow]  *)
(*((a A Cos[c+d x](Sin[c+d x]^j)^(m+j k))/(d(j k m+(k+1)/2)))+1/(j k m+(k+1)/2) \[Integral](Sin[c+d x]^j)^(m+j k)\[CenterDot]*)
(*((j k m+(k+1)/2) (b A+a B)+((j k m+(k+3)/2) a A+(j k m+(k+1)/2)(b B+a C)) Sin[c+d x]^k+(j k m+(k+1)/2) b C Sin[c+d x]^(2k))\[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
(* Int[(sin[c_.+d_.*x_]^j_.)^m_.*(A_.+B_.*sin[c_.+d_.*x_]^k_.+C_.*sin[c_.+d_.*x_]^k2_)*
    (a_+b_.*sin[c_.+d_.*x_]^k_.),x_Symbol] :=
  a*A*Cos[c+d*x]*(Sin[c+d*x]^j)^(m+j*k)/(d*(j*k*m+(k+1)/2)) + 
  Dist[1/(j*k*m+(k+1)/2),
    Int[(sin[c+d*x]^j)^(m+j*k)*
      Sim[(j*k*m+(k+1)/2)*(b*A+a*B)+((j*k*m+(k+3)/2)*a*A+(j*k*m+(k+1)/2)*(b*B+a*C))*sin[c+d*x]^k+
        (j*k*m+(k+1)/2)*b*C*sin[c+d*x]^(2*k),x],x]] /;
FreeQ[{a,b,c,d,A,B,C},x] && OneQ[j^2,k^2] && k2===2*k && RationalQ[m] && j*k*m<-1 *)


(* ::Code:: *)
(* Int[(sin[c_.+d_.*x_]^j_.)^m_.*(A_.+C_.*sin[c_.+d_.*x_]^k2_)*
    (a_+b_.*sin[c_.+d_.*x_]^k_.),x_Symbol] :=
  a*A*Cos[c+d*x]*(Sin[c+d*x]^j)^(m+j*k)/(d*(j*k*m+(k+1)/2)) + 
  Dist[1/(j*k*m+(k+1)/2),
    Int[(sin[c+d*x]^j)^(m+j*k)*
      Sim[(j*k*m+(k+1)/2)*b*A+((j*k*m+(k+3)/2)*a*A+(j*k*m+(k+1)/2)*a*C)*sin[c+d*x]^k+
        (j*k*m+(k+1)/2)*b*C*sin[c+d*x]^(2*k),x],x]] /;
FreeQ[{a,b,c,d,A,C},x] && OneQ[j^2,k^2] && k2===2*k && RationalQ[m] && j*k*m<-1 *)


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Derivation: Rule 3 with n=1 and ???*)


(* ::Subsubsection:: *)
(*Rule 12: If  j^2=k^2=1 \[And] j k m>=-1, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral](Sin[c+d x]^j)^m (A+B Sin[c+d x]^k+C Sin[c+d x]^(2k))(a+b Sin[c+d x]^k)\[DifferentialD]x  \[LongRightArrow]  *)
(*-((b C Cos[c+d x](Sin[c+d x]^j)^(m+2j k))/(d(j k m+(k+5)/2)))+1/(j k m+(k+5)/2) \[Integral](Sin[c+d x]^j)^m\[CenterDot]*)
(*((j k m+(k+5)/2) a A+((j k m+(k+5)/2)(b A+a B)+(j k m+(k+3)/2)b C) Sin[c+d x]^k+(j k m+(k+5)/2)(b B+a C)Sin[c+d x]^(2k))\[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
(* Int[(sin[c_.+d_.*x_]^j_.)^m_.*(A_.+B_.*sin[c_.+d_.*x_]^k_.+C_.*sin[c_.+d_.*x_]^k2_)*
    (a_+b_.*sin[c_.+d_.*x_]^k_.),x_Symbol] :=
  -b*C*Cos[c+d*x]*(Sin[c+d*x]^j)^(m+2*j*k)/(d*(j*k*m+(k+5)/2)) + 
  Dist[1/(j*k*m+(k+5)/2),
    Int[(sin[c+d*x]^j)^m*
      Sim[(j*k*m+(k+5)/2)*a*A+((j*k*m+(k+5)/2)*(b*A+a*B)+(j*k*m+(k+3)/2)*b*C)*sin[c+d*x]^k+
        (j*k*m+(k+5)/2)*(b*B+a*C)*sin[c+d*x]^(2*k),x],x]] /;
FreeQ[{a,b,c,d,A,B,C},x] && OneQ[j^2,k^2] && k2===2*k && RationalQ[m] && j*k*m>=-1 *)


(* ::Code:: *)
(* Int[(sin[c_.+d_.*x_]^j_.)^m_.*(A_.+C_.*sin[c_.+d_.*x_]^k2_)*
    (a_+b_.*sin[c_.+d_.*x_]^k_.),x_Symbol] :=
  -b*C*Cos[c+d*x]*(Sin[c+d*x]^j)^(m+2*j*k)/(d*(j*k*m+(k+5)/2)) + 
  Dist[1/(j*k*m+(k+5)/2),
    Int[(sin[c+d*x]^j)^m*
      Sim[(j*k*m+(k+5)/2)*a*A+((j*k*m+(k+5)/2)*b*A+(j*k*m+(k+3)/2)*b*C)*sin[c+d*x]^k+
        (j*k*m+(k+5)/2)*a*C*sin[c+d*x]^(2*k),x],x]] /;
FreeQ[{a,b,c,d,A,C},x] && OneQ[j^2,k^2] && k2===2*k && RationalQ[m] && j*k*m>=-1 *)


(* ::PageBreak:: *)
(**)


(* ::Subsubtitle::Bold::Closed:: *)
(*Rules 1-6:  \[Integral](Sin[c+d x]^j)^m (A+B Sin[c+d x]^k+C Sin[c+d x]^(2k)) (a+b Sin[c+d x]^k)^n \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Derivation: Rule 1 or 6 with a^2 C-a b B+b^2 A=0*)


(* ::Subsubsection:: *)
(*Derivation: Algebraic simplification*)


(* ::Subsubsection:: *)
(*Basis:  If  a^2 C-a b B+b^2 A=0, then A+B z+C z^2=((b B-a C+b C z)(a+b z))/b^2*)


(* ::Subsubsection:: *)
(*Rule: If  j^2=k^2=1 \[And] a^2 C-a b B+b^2 A=0 \[And] n<-1, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral](Sin[c+d x]^j)^m (A+B Sin[c+d x]^k+C Sin[c+d x]^(2k)) (a+b Sin[c+d x]^k)^n \[DifferentialD]x  \[LongRightArrow]  *)
(*(1/b^2) \[Integral](Sin[c+d x]^j)^m (b B-a C+b C Sin[c+d x]^k) (a+b Sin[c+d x]^k)^(n+1) \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[(sin[c_.+d_.*x_]^j_.)^m_.*(A_.+B_.*sin[c_.+d_.*x_]^k_.+C_.*sin[c_.+d_.*x_]^k2_)*
    (a_+b_.*sin[c_.+d_.*x_]^k_.)^n_,x_Symbol] :=
  Dist[1/b^2,Int[(sin[c+d*x]^j)^m*Sim[b*B-a*C+b*C*sin[c+d*x]^k,x]*(a+b*sin[c+d*x]^k)^(n+1),x]] /;
FreeQ[{a,b,c,d,A,B,C,m},x] && OneQ[j^2,k^2] && k2===2*k && ZeroQ[a^2*C-a*b*B+b^2*A] && RationalQ[n] && n<-1


(* ::Code:: *)
Int[(sin[c_.+d_.*x_]^j_.)^m_.*(A_.+C_.*sin[c_.+d_.*x_]^k2_)*(a_+b_.*sin[c_.+d_.*x_]^k_.)^n_,x_Symbol] :=
  Dist[1/b^2,Int[(sin[c+d*x]^j)^m*Sim[-a*C+b*C*sin[c+d*x]^k,x]*(a+b*sin[c+d*x]^k)^(n+1),x]] /;
FreeQ[{a,b,c,d,A,C,m},x] && OneQ[j^2,k^2] && k2===2*k && ZeroQ[a^2*C+b^2*A] && RationalQ[n] && n<-1


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Derivation: Recurrence 1*)


(* ::Subsubsection:: *)
(*Rule 1: If  j^2=k^2=1 \[And] a^2-b^2!=0 \[And] a^2 C-a b B+b^2 A!=0 \[And] j k m>0 \[And] n<-1, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral](Sin[c+d x]^j)^m (A+B Sin[c+d x]^k+C Sin[c+d x]^(2k)) (a+b Sin[c+d x]^k)^n \[DifferentialD]x  \[LongRightArrow]  *)
(*-(((a^2 C-a b B+b^2 A) Cos[c+d x] (Sin[c+d x]^j)^m (a+b Sin[c+d x]^k)^(n+1))/(b d (n+1) (a^2-b^2)))+1/(b(n+1)(a^2-b^2)) \[Integral](Sin[c+d x]^j)^(m-j k)\[CenterDot]*)
(*((a^2 C-a b B+b^2 A)(j k m+(k-1)/2)+b(a A-b B+a C)(n+1)Sin[c+d x]^k-((b^2 A-a b B+b^2 C)(n+1)+(a^2 C-a b B+b^2 A)(j k m+(k+1)/2))Sin[c+d x]^(2k)) (a+b Sin[c+d x]^k)^(n+1) \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[(sin[c_.+d_.*x_]^j_.)^m_.*(A_.+B_.*sin[c_.+d_.*x_]^k_.+C_.*sin[c_.+d_.*x_]^k2_)*
    (a_+b_.*sin[c_.+d_.*x_]^k_.)^n_,x_Symbol] :=
  -(a^2*C-a*b*B+b^2*A)*Cos[c+d*x]*(Sin[c+d*x]^j)^m*(a+b*Sin[c+d*x]^k)^(n+1)/(b*d*(n+1)*(a^2-b^2)) + 
  Dist[1/(b*(n+1)*(a^2-b^2)),
    Int[(sin[c+d*x]^j)^(m-j*k)*
      Sim[(a^2*C-a*b*B+b^2*A)*(j*k*m+(k-1)/2)+b*(a*A-b*B+a*C)*(n+1)*sin[c+d*x]^k-
        ((b^2*A-a*b*B+b^2*C)*(n+1)+(a^2*C-a*b*B+b^2*A)*(j*k*m+(k+1)/2))*sin[c+d*x]^(2*k),x]*
      (a+b*sin[c+d*x]^k)^(n+1),x]] /;
FreeQ[{a,b,c,d,A,B,C},x] && OneQ[j^2,k^2] && k2===2*k && NonzeroQ[a^2-b^2] && 
  NonzeroQ[a^2*C-a*b*B+b^2*A] && RationalQ[m,n] && j*k*m>0 && n<-1


(* ::Code:: *)
Int[(sin[c_.+d_.*x_]^j_.)^m_.*(A_.+C_.*sin[c_.+d_.*x_]^k2_)*(a_+b_.*sin[c_.+d_.*x_]^k_.)^n_,x_Symbol] :=
  -(a^2*C+b^2*A)*Cos[c+d*x]*(Sin[c+d*x]^j)^m*(a+b*Sin[c+d*x]^k)^(n+1)/(b*d*(n+1)*(a^2-b^2)) + 
  Dist[1/(b*(n+1)*(a^2-b^2)),
    Int[(sin[c+d*x]^j)^(m-j*k)*
      Sim[(a^2*C+b^2*A)*(j*k*m+(k-1)/2)+b*(a*A+a*C)*(n+1)*sin[c+d*x]^k-
        ((b^2*A+b^2*C)*(n+1)+(a^2*C+b^2*A)*(j*k*m+(k+1)/2))*sin[c+d*x]^(2*k),x]*
      (a+b*sin[c+d*x]^k)^(n+1),x]] /;
FreeQ[{a,b,c,d,A,C},x] && OneQ[j^2,k^2] && k2===2*k && NonzeroQ[a^2-b^2] && 
  NonzeroQ[a^2*C+b^2*A] && RationalQ[m,n] && j*k*m>0 && n<-1


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Derivation: Recurrence 2*)


(* ::Subsubsection:: *)
(*Rule 2: If  j^2=k^2=1 \[And] a^2-b^2!=0 \[And] j k m>0 \[And] -1<=n<0, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral](Sin[c+d x]^j)^m (A+B Sin[c+d x]^k+C Sin[c+d x]^(2k)) (a+b Sin[c+d x]^k)^n \[DifferentialD]x  \[LongRightArrow]  *)
(*-((C Cos[c+d x](Sin[c+d x]^j)^m (a+b Sin[c+d x]^k)^(n+1))/(b d (j k m+n+(k+3)/2)))+1/(b (j k m+n+(k+3)/2)) \[Integral](Sin[c+d x]^j)^(m-j k)\[CenterDot]*)
(*(a C (j k m+(k-1)/2)+b(A+(A+C)(j k m+n+(k+1)/2))Sin[c+d x]^k+(b B(n+1)+(b B-a C)(j k m+(k+1)/2))Sin[c+d x]^(2k)) (a+b Sin[c+d x]^k)^n \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[(sin[c_.+d_.*x_]^j_.)^m_.*(A_.+B_.*sin[c_.+d_.*x_]^k_.+C_.*sin[c_.+d_.*x_]^k2_)*
    (a_+b_.*sin[c_.+d_.*x_]^k_.)^n_,x_Symbol] :=
  -C*Cos[c+d*x]*(Sin[c+d*x]^j)^m*(a+b*Sin[c+d*x]^k)^(n+1)/(b*d*(j*k*m+n+(k+3)/2)) + 
  Dist[1/(b*(j*k*m+n+(k+3)/2)),
    Int[(sin[c+d*x]^j)^(m-j*k)*
      Sim[a*C*(j*k*m+(k-1)/2)+b*(A+(A+C)*(j*k*m+n+(k+1)/2))*sin[c+d*x]^k+
        (b*B*(n+1)+(b*B-a*C)*(j*k*m+(k+1)/2))*sin[c+d*x]^(2*k),x]*
      (a+b*sin[c+d*x]^k)^n,x]] /;
FreeQ[{a,b,c,d,A,B,C},x] && OneQ[j^2,k^2] && k2===2*k && NonzeroQ[a^2-b^2] && 
  RationalQ[m,n] && j*k*m>0 && -1<=n<0


(* ::Code:: *)
Int[(sin[c_.+d_.*x_]^j_.)^m_.*(A_.+C_.*sin[c_.+d_.*x_]^k2_)*(a_+b_.*sin[c_.+d_.*x_]^k_.)^n_,x_Symbol] :=
  -C*Cos[c+d*x]*(Sin[c+d*x]^j)^m*(a+b*Sin[c+d*x]^k)^(n+1)/(b*d*(j*k*m+n+(k+1)/2+1)) + 
  Dist[1/(b*(j*k*m+n+(k+1)/2+1)),
    Int[(sin[c+d*x]^j)^(m-j*k)*
      Sim[a*C*(j*k*m+(k-1)/2)+b*(A+(A+C)*(j*k*m+n+(k+1)/2))*sin[c+d*x]^k-
        a*C*(j*k*m+(k+1)/2)*sin[c+d*x]^(2*k),x]*
      (a+b*sin[c+d*x]^k)^n,x]] /;
FreeQ[{a,b,c,d,A,C},x] && OneQ[j^2,k^2] && k2===2*k && NonzeroQ[a^2-b^2] && 
  RationalQ[m,n] && j*k*m>0 && -1<=n<0


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Derivation: Recurrence 3*)


(* ::Subsubsection:: *)
(*Note: Rule 4 is used if j k m=k=-1.*)


(* ::Subsubsection:: *)
(*Rule 3: If  j^2=k^2=1 \[And] a^2-b^2!=0 \[And] j k m>=-1 \[And] \[Not](m^2=1 \[And] k=-1) \[And] n>0, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral](Sin[c+d x]^j)^m (A+B Sin[c+d x]^k+C Sin[c+d x]^(2k)) (a+b Sin[c+d x]^k)^n \[DifferentialD]x  \[LongRightArrow]  *)
(*-((C Cos[c+d x](Sin[c+d x]^j)^(m+j k) (a+b Sin[c+d x]^k)^n)/(d (j k m+(k+3)/2+n)))+1/(j k m+(k+3)/2+n) \[Integral](Sin[c+d x]^j)^m\[CenterDot]*)
(*(a (A(n+1)+(A+C)(j k m+(k+1)/2))+(b A+a B+(b A+a B+b C)(j k m+(k+1)/2+n))Sin[c+d x]^k+(a C n+b B (j k m+(k+3)/2+n))Sin[c+d x]^(2k)) (a+b Sin[c+d x]^k)^(n-1) \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[(sin[c_.+d_.*x_]^j_.)^m_.*(A_.+B_.*sin[c_.+d_.*x_]^k_.+C_.*sin[c_.+d_.*x_]^k2_)*
    (a_+b_.*sin[c_.+d_.*x_]^k_.)^n_.,x_Symbol] :=
  -C*Cos[c+d*x]*(Sin[c+d*x]^j)^(m+j*k)*(a+b*Sin[c+d*x]^k)^n/(d*(j*k*m+(k+3)/2+n)) + 
  Dist[1/(j*k*m+(k+3)/2+n),
    Int[(sin[c+d*x]^j)^m*
      Sim[a*(A*(n+1)+(A+C)*(j*k*m+(k+1)/2))+(b*A+a*B+(b*A+a*B+b*C)*(j*k*m+(k+1)/2+n))*sin[c+d*x]^k+
        (a*C*n+b*B*(j*k*m+(k+3)/2+n))*sin[c+d*x]^(2*k),x]*
      (a+b*sin[c+d*x]^k)^(n-1),x]] /;
FreeQ[{a,b,c,d,A,B,C},x] && OneQ[j^2,k^2] && k2===2*k && NonzeroQ[a^2-b^2] && 
  RationalQ[m,n] && j*k*m>=-1 && Not[m^2==1 && k==-1] && n>0


(* ::Code:: *)
Int[(sin[c_.+d_.*x_]^j_.)^m_.*(A_.+C_.*sin[c_.+d_.*x_]^k2_)*(a_+b_.*sin[c_.+d_.*x_]^k_.)^n_.,x_Symbol] :=
  -C*Cos[c+d*x]*(Sin[c+d*x]^j)^(m+j*k)*(a+b*Sin[c+d*x]^k)^n/(d*(j*k*m+(k+3)/2+n)) + 
  Dist[1/(j*k*m+(k+3)/2+n),
    Int[(sin[c+d*x]^j)^m*
      Sim[a*(A*(n+1)+(A+C)*(j*k*m+(k+1)/2))+(b*A+(b*A+b*C)*(j*k*m+(k+1)/2+n))*sin[c+d*x]^k+
        a*C*n*sin[c+d*x]^(2*k),x]*
      (a+b*sin[c+d*x]^k)^(n-1),x]] /;
FreeQ[{a,b,c,d,A,C},x] && OneQ[j^2,k^2] && k2===2*k && NonzeroQ[a^2-b^2] && 
  RationalQ[m,n] && j*k*m>=-1 && Not[m^2==1 && k==-1] && n>0


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Derivation: Recurrence 4*)


(* ::Subsubsection:: *)
(*Rule 4: If  j^2=k^2=1 \[And] a^2-b^2!=0 \[And] j k m+(k+1)/2!=0 \[And] j k m<=-1 \[And] n>0, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral](Sin[c+d x]^j)^m (A+B Sin[c+d x]^k+C Sin[c+d x]^(2k)) (a+b Sin[c+d x]^k)^n \[DifferentialD]x  \[LongRightArrow]  *)
(*((A Cos[c+d x] (Sin[c+d x]^j)^(m+j k) (a+b Sin[c+d x]^k)^n)/(d(j k m+(k+1)/2)))+1/(j k m+(k+1)/2) \[Integral](Sin[c+d x]^j)^(m+j k)\[CenterDot]*)
(*(a B(j k m+(k+1)/2)-b A n+(a A+(a A+a C+b B) (j k m+(k+1)/2)) Sin[c+d x]^k+b(A (n+1)+(A+C)(j k m+(k+1)/2))Sin[c+d x]^(2k)) (a+b Sin[c+d x]^k)^(n-1) \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[(sin[c_.+d_.*x_]^j_.)^m_.*(A_.+B_.*sin[c_.+d_.*x_]^k_.+C_.*sin[c_.+d_.*x_]^k2_)*
    (a_+b_.*sin[c_.+d_.*x_]^k_.)^n_.,x_Symbol] :=
  A*Cos[c+d*x]*(Sin[c+d*x]^j)^(m+j*k)*(a+b*Sin[c+d*x]^k)^n/(d*(j*k*m+(k+1)/2)) + 
  Dist[1/(j*k*m+(k+1)/2),
    Int[(sin[c+d*x]^j)^(m+j*k)*
      Sim[a*B*(j*k*m+(k+1)/2)-b*A*n+(a*A+(a*A+a*C+b*B)*(j*k*m+(k+1)/2))*sin[c+d*x]^k+
        b*(A*(n+1)+(A+C)*(j*k*m+(k+1)/2))*sin[c+d*x]^(2*k),x]*
      (a+b*sin[c+d*x]^k)^(n-1),x]] /;
FreeQ[{a,b,c,d,A,B,C},x] && OneQ[j^2,k^2] && k2===2*k && NonzeroQ[a^2-b^2] && 
  RationalQ[m,n] && j*k*m+(k+1)/2!=0 && j*k*m<=-1 && n>0


(* ::Code:: *)
Int[(sin[c_.+d_.*x_]^j_.)^m_.*(A_.+C_.*sin[c_.+d_.*x_]^k2_)*(a_+b_.*sin[c_.+d_.*x_]^k_.)^n_.,x_Symbol] :=
  A*Cos[c+d*x]*(Sin[c+d*x]^j)^(m+j*k)*(a+b*Sin[c+d*x]^k)^n/(d*(j*k*m+(k+1)/2)) + 
  Dist[1/(j*k*m+(k+1)/2),
    Int[(sin[c+d*x]^j)^(m+j*k)*
      Sim[-b*A*n+a*(A+(A+C)*(j*k*m+(k+1)/2))*sin[c+d*x]^k+
        b*(A*(n+1)+(A+C)*(j*k*m+(k+1)/2))*sin[c+d*x]^(2*k),x]*
      (a+b*sin[c+d*x]^k)^(n-1),x]] /;
FreeQ[{a,b,c,d,A,C},x] && OneQ[j^2,k^2] && k2===2*k && NonzeroQ[a^2-b^2] && 
  RationalQ[m,n] && j*k*m+(k+1)/2!=0 && j*k*m<=-1 && n>0


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Derivation: Recurrence 5*)


(* ::Subsubsection:: *)
(*Rule 5: If  j^2=k^2=1 \[And] a^2-b^2!=0 \[And] j k m+(k+1)/2!=0 \[And] j k m<=-1 \[And] -1<=n<0, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral](Sin[c+d x]^j)^m (A+B Sin[c+d x]^k+C Sin[c+d x]^(2k)) (a+b Sin[c+d x]^k)^n \[DifferentialD]x  \[LongRightArrow]  *)
(*((A Cos[c+d x](Sin[c+d x]^j)^(m+j k) (a+b Sin[c+d x]^k)^(n+1))/(a d(j k m+(k+1)/2)))+1/(a (j k m+(k+1)/2)) \[Integral](Sin[c+d x]^j)^(m+j k)\[CenterDot]*)
(*((a B-b A)(j k m+(k+1)/2)-b A (n+1)+a(A+(A+C)(j k m+(k+1)/2))Sin[c+d x]^k+b A(j k m+n+(k+5)/2)Sin[c+d x]^(2k) ) (a+b Sin[c+d x]^k)^n \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[(sin[c_.+d_.*x_]^j_.)^m_.*(A_.+B_.*sin[c_.+d_.*x_]^k_.+C_.*sin[c_.+d_.*x_]^k2_)*
    (a_+b_.*sin[c_.+d_.*x_]^k_.)^n_,x_Symbol] :=
  A*Cos[c+d*x]*(Sin[c+d*x]^j)^(m+j*k)*(a+b*Sin[c+d*x]^k)^(n+1)/(a*d*(j*k*m+(k+1)/2)) + 
  Dist[1/(a*(j*k*m+(k+1)/2)),
    Int[(sin[c+d*x]^j)^(m+j*k)*
      Sim[(a*B-b*A)*(j*k*m+(k+1)/2)-b*A*(n+1)+a*(A+(A+C)*(j*k*m+(k+1)/2))*sin[c+d*x]^k+
        b*A*(j*k*m+n+(k+5)/2)*sin[c+d*x]^(2*k),x]*
      (a+b*sin[c+d*x]^k)^n,x]] /;
FreeQ[{a,b,c,d,A,B,C},x] && OneQ[j^2,k^2] && k2===2*k && NonzeroQ[a^2-b^2] && 
  RationalQ[m,n] && j*k*m+(k+1)/2!=0 && j*k*m<=-1 && -1<=n<0


(* ::Code:: *)
Int[(sin[c_.+d_.*x_]^j_.)^m_.*(A_.+C_.*sin[c_.+d_.*x_]^k2_)*(a_+b_.*sin[c_.+d_.*x_]^k_.)^n_,x_Symbol] :=
  A*Cos[c+d*x]*(Sin[c+d*x]^j)^(m+j*k)*(a+b*Sin[c+d*x]^k)^(n+1)/(a*d*(j*k*m+(k+1)/2)) + 
  Dist[1/(a*(j*k*m+(k+1)/2)),
    Int[(sin[c+d*x]^j)^(m+j*k)*
      Sim[-b*A*(j*k*m+(k+1)/2)-b*A*(n+1)+a*(A+(A+C)*(j*k*m+(k+1)/2))*sin[c+d*x]^k+
        b*A*(j*k*m+n+(k+5)/2)*sin[c+d*x]^(2*k),x]*
      (a+b*sin[c+d*x]^k)^n,x]] /;
FreeQ[{a,b,c,d,A,C},x] && OneQ[j^2,k^2] && k2===2*k && NonzeroQ[a^2-b^2] && 
  RationalQ[m,n] && j*k*m+(k+1)/2!=0 && j*k*m<=-1 && -1<=n<0


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Derivation: Recurrence 6*)


(* ::Subsubsection:: *)
(*Rule 6: If  j^2=k^2=1 \[And] a^2-b^2!=0 \[And] a^2 C-a b B+b^2 A!=0 \[And] j k m<0 \[And] n<-1, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral](Sin[c+d x]^j)^m (A+B Sin[c+d x]^k+C Sin[c+d x]^(2k)) (a+b Sin[c+d x]^k)^n \[DifferentialD]x  \[LongRightArrow]  *)
(*(((a^2 C-a b B+b^2 A) Cos[c+d x](Sin[c+d x]^j)^(m+j k) (a+b Sin[c+d x]^k)^(n+1))/(a d (n+1) (a^2-b^2)))+1/(a (n+1) (a^2-b^2)) \[Integral](Sin[c+d x]^j)^m\[CenterDot]*)
(*(A (a^2-b^2) (n+1)-(a^2 C-a b B+b^2 A)(j k m+(k+1)/2)-a(b A-a B+b C)(n+1)Sin[c+d x]^k+(a^2 C-a b B+b^2 A)(j k m+n+(k+5)/2)Sin[c+d x]^(2k)) (a+b Sin[c+d x]^k)^(n+1) \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[(sin[c_.+d_.*x_]^j_.)^m_.*(A_.+B_.*sin[c_.+d_.*x_]^k_.+C_.*sin[c_.+d_.*x_]^k2_)*
    (a_+b_.*sin[c_.+d_.*x_]^k_.)^n_,x_Symbol] :=
  (a^2*C-a*b*B+b^2*A)*Cos[c+d*x]*(Sin[c+d*x]^j)^(m+j*k)*(a+b*Sin[c+d*x]^k)^(n+1)/(a*d*(n+1)*(a^2-b^2)) + 
  Dist[1/(a*(n+1)*(a^2-b^2)),
    Int[(sin[c+d*x]^j)^m*
      Sim[A*(a^2-b^2)*(n+1)-(a^2*C-a*b*B+b^2*A)*(j*k*m+(k+1)/2)-a*(b*A-a*B+b*C)*(n+1)*sin[c+d*x]^k+
        (a^2*C-a*b*B+b^2*A)*(j*k*m+n+(k+5)/2)*sin[c+d*x]^(2*k),x]*
      (a+b*sin[c+d*x]^k)^(n+1),x]] /;
FreeQ[{a,b,c,d,A,B,C},x] && OneQ[j^2,k^2] && k2===2*k && NonzeroQ[a^2-b^2] && 
  NonzeroQ[a^2*C-a*b*B+b^2*A] && RationalQ[m,n] && j*k*m<0 && n<-1


(* ::Code:: *)
Int[(sin[c_.+d_.*x_]^j_.)^m_.*(A_.+C_.*sin[c_.+d_.*x_]^k2_)*(a_+b_.*sin[c_.+d_.*x_]^k_.)^n_,x_Symbol] :=
  (a^2*C+b^2*A)*Cos[c+d*x]*(Sin[c+d*x]^j)^(m+j*k)*(a+b*Sin[c+d*x]^k)^(n+1)/(a*d*(n+1)*(a^2-b^2)) + 
  Dist[1/(a*(n+1)*(a^2-b^2)),
    Int[(sin[c+d*x]^j)^m*
      Sim[A*(a^2-b^2)*(n+1)-(a^2*C+b^2*A)*(j*k*m+(k+1)/2)-a*b*(A+C)*(n+1)*sin[c+d*x]^k+
        (a^2*C+b^2*A)*(j*k*m+n+(k+5)/2)*sin[c+d*x]^(2*k),x]*
      (a+b*sin[c+d*x]^k)^(n+1),x]] /;
FreeQ[{a,b,c,d,A,C},x] && OneQ[j^2,k^2] && k2===2*k && NonzeroQ[a^2-b^2] && 
  NonzeroQ[a^2*C+b^2*A] && RationalQ[m,n] && j*k*m<0 && n<-1


(* ::PageBreak:: *)
(**)
