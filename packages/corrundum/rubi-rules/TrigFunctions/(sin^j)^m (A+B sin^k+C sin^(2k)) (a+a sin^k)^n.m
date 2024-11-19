(* ::Package:: *)

(* ::Title::Plain:: *)
(* Integration Rules for *)
(*\[Integral](sin^j(z))^m (A+B sin^k(z)+C sin^(2k)(z))(a+b sin^k(z))^n \[DifferentialD]z when j^2=1\[And]k^2=1\[And]a^2=b^2*)


(* ::Subsubtitle::Closed:: *)
(*Domain Map*)


(* ::Input:: *)
(*Graphics[{{RGBColor[1, 0, 0], Rectangle[{-4, -4}, {-1, 4}]}, {GrayLevel[0], Inset[Style["Rule 1 \[RightArrow]\[Diamond]", FontSize -> 10], {Rational[-5, 2], 2}]}, {GrayLevel[0], Thickness[0.007], Dashing[{0.003, 0.02}], Line[{{-1.02, 3.98}, {-1.02, -3.98}}], {RGBColor[1, 0, 1], Dashing[{}], Rectangle[{-1, -4}, {4, -1}], {GrayLevel[0], Inset[Style["Rule 2 \[UpArrow]\[Diamond]", FontSize -> 10], {2, Rational[-5, 2]}]}, {RGBColor[0, 1, 0], Rectangle[{-1, -1}, {4, 4}]}, {GrayLevel[0], Inset[Style["Rule 3\[Diamond]", FontSize -> 10], {2, 2}]}, {GrayLevel[0], Thickness[0.007], Dashing[{0.003, 0.02}], Line[{{-1.02, -0.98}, {3.98, -0.98}}]}, {RGBColor[0.5, 0.5, 1.], Thickness[Large], Dashing[{}], Line[{{-3.98, 0}, {-1.02, 0}}], {GrayLevel[0], Inset[Style["Rule 4 \[RightArrow]\[Diamond]", FontSize -> 10], {Rational[-5, 2], 0.13}]}, {GrayLevel[0], Thickness[Large], Line[{{-1, 0}, {3.98, 0}}]}}}}}, Axes -> True, AxesLabel -> {$CellContext`n, $CellContext`j $CellContext`k $CellContext`m}, ImageSize -> Medium]*)


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


(* ::Subsubtitle::Bold::Closed:: *)
(*Rule a:  \[Integral](A+B Csc[c+d x]+C Csc[c+d x]^2)/(a+b Csc[c+d x]) \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Derivation: Algebraic expansion*)


(* ::Subsubsection:: *)
(*Basis: (A+B z+C z^2)/(a+b z)=A/a-(z(b A-a B-a C z))/(a(a+b z))*)


(* ::Subsubsection:: *)
(*Note: The rule for integrands of the same form when a^2-b^2!=0 could subsume this rule, but the resulting antiderivative will look less like the integrand involving sines instead of cosecants.*)


(* ::Subsubsection:: *)
(*Rule a: If a^2-b^2=0, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral](A+B Csc[c+d x]+C Csc[c+d x]^2)/(a+b Csc[c+d x]) \[DifferentialD]x  \[LongRightArrow]  ((A x)/a)+C/b \[Integral]Csc[c+d x]\[DifferentialD]x-(b A-a B+b C)/a \[Integral]Csc[c+d x]/(a+b Csc[c+d x]) \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[(A_.+B_.*sin[c_.+d_.*x_]^(-1)+C_.*sin[c_.+d_.*x_]^(-2))/(a_+b_.*sin[c_.+d_.*x_]^(-1)),x_Symbol] :=
  A*x/a + 
  C/b*Int[sin[c+d*x]^(-1),x] - 
  (b*A-a*B+b*C)/a*Int[sin[c+d*x]^(-1)/(a+b*sin[c+d*x]^(-1)),x] /;
FreeQ[{a,b,c,d,A,B,C},x] && ZeroQ[a^2-b^2]


(* ::Code:: *)
Int[(A_.+C_.*sin[c_.+d_.*x_]^(-2))/(a_+b_.*sin[c_.+d_.*x_]^(-1)),x_Symbol] :=
  A*x/a + C/b*Int[sin[c+d*x]^(-1),x] - 
  (b*A+b*C)/a*Int[sin[c+d*x]^(-1)/(a+b*sin[c+d*x]^(-1)),x] /;
FreeQ[{a,b,c,d,A,C},x] && ZeroQ[a^2-b^2]


(* ::PageBreak:: *)
(**)


(* ::Subsubtitle::Bold::Closed:: *)
(*Rule b:  \[Integral](A+B Csc[c+d x]+C Csc[c+d x]^2)/Sqrt[a+b Csc[c+d x]] \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Derivation: Rule 3 with m=0, k=-1 and n=-(1/2)*)


(* ::Subsubsection:: *)
(*Rule b: If  a^2-b^2=0, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral](A+B Csc[c+d x]+C Csc[c+d x]^2)/Sqrt[a+b Csc[c+d x]] \[DifferentialD]x  \[LongRightArrow]  -((2 C Cot[c+d x])/(d Sqrt[a+b Csc[c+d x]]))+1/a \[Integral](a A+(a B-b C) Csc[c+d x])/Sqrt[a+b Csc[c+d x]] \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[(A_.+B_.*sin[c_.+d_.*x_]^(-1)+C_.*sin[c_.+d_.*x_]^(-2))/Sqrt[a_.+b_.*sin[c_.+d_.*x_]^(-1)],x_Symbol] :=
  -2*C*Cot[c+d*x]/(d*Sqrt[a+b*Csc[c + d*x]]) + 
  Dist[1/a,Int[Sim[a*A+(a*B-b*C)*sin[c+d*x]^(-1),x]/Sqrt[a+b*sin[c+d*x]^(-1)],x]] /;
FreeQ[{a,b,c,d,A,B,C},x] && ZeroQ[a^2-b^2]


(* ::Code:: *)
Int[(A_+C_.*sin[c_.+d_.*x_]^(-2))/Sqrt[a_.+b_.*sin[c_.+d_.*x_]^(-1)],x_Symbol] :=
  -2*C*Cot[c+d*x]/(d*Sqrt[a+b*Csc[c + d*x]]) + 
  Dist[1/a,Int[Sim[a*A-b*C*sin[c+d*x]^(-1),x]/Sqrt[a+b*sin[c+d*x]^(-1)],x]] /;
FreeQ[{a,b,c,d,A,C},x] && ZeroQ[a^2-b^2]


(* ::PageBreak:: *)
(**)


(* ::Subsubtitle::Bold::Closed:: *)
(*Rule c:  \[Integral]((Sin[c+d x]^j)^(m/2) (A+B Csc[c+d x]+C Csc[c+d x]^2))/Sqrt[a+b Csc[c+d x]] \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Derivation: Rule 2 with j m=1/2, k=-1 and n=-(1/2)*)


(* ::Subsubsection:: *)
(*Rule c: If  j^2=1 \[And] a^2-b^2=0 \[And] j m=1/2, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]((Sin[c+d x]^j)^(m/2) (A+B Csc[c+d x]+C Csc[c+d x]^2))/Sqrt[a+b Csc[c+d x]] \[DifferentialD]x  \[LongRightArrow]  *)
(*-((2A Cos[c+d x])/(d (Sin[c+d x]^j)^(m/2) Sqrt[a+b Csc[c+d x]]))-1/a \[Integral](b A-a B-a C Csc[c+d x])/((Sin[c+d x]^j)^(m/2) Sqrt[a+b Csc[c+d x]]) \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[(sin[c_.+d_.*x_]^j_.)^m_*(A_+B_.*sin[c_.+d_.*x_]^(-1)+C_.*sin[c_.+d_.*x_]^(-2))/
    Sqrt[a_.+b_.*sin[c_.+d_.*x_]^(-1)],x_Symbol] :=
  -2*A*Cos[c+d*x]/(d*(Sin[c+d*x]^j)^m*Sqrt[a+b*Csc[c+d*x]]) - 
  Dist[1/a,
    Int[Sim[b*A-a*B-a*C*sin[c+d*x]^(-1),x]/((sin[c+d*x]^j)^m*Sqrt[a+b*sin[c+d*x]^(-1)]),x]] /;
FreeQ[{a,b,c,d,A,B,C},x] && OneQ[j^2] && ZeroQ[a^2-b^2] && RationalQ[m] && j*m==1/2


(* ::Code:: *)
Int[(sin[c_.+d_.*x_]^j_.)^m_*(A_+C_.*sin[c_.+d_.*x_]^(-2))/Sqrt[a_.+b_.*sin[c_.+d_.*x_]^(-1)],x_Symbol] :=
  -2*A*Cos[c+d*x]/(d*(Sin[c+d*x]^j)^m*Sqrt[a+b*Csc[c+d*x]]) - 
  Dist[1/a,
    Int[Sim[b*A-a*C*sin[c+d*x]^(-1),x]/((sin[c+d*x]^j)^m*Sqrt[a+b*sin[c+d*x]^(-1)]),x]] /;
FreeQ[{a,b,c,d,A,C},x] && OneQ[j^2] && ZeroQ[a^2-b^2] && RationalQ[m] && j*m==1/2


(* ::PageBreak:: *)
(**)


(* ::Subsubtitle::Bold::Closed:: *)
(*Rule 4:  \[Integral](A+B Sin[c+d x]^k+C Sin[c+d x]^k) (a+b Sin[c+d x]^k)^n \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Derivation: Recurrence 7 with j m=0 and k=1 plus recurrence 7 with A=0, B=C and j m=k*)


(* ::Subsubsection:: *)
(*Rule 4a: If  a^2-b^2=0 \[And] n<-1, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral](A+B Sin[c+d x]+C Sin[c+d x]^2) (a+b Sin[c+d x])^n \[DifferentialD]x  \[LongRightArrow]  *)
(*(((b (A+C)-a B) Cos[c+d x](a+b Sin[c+d x])^n)/(a d (2n+1)))+*)
(*1/(a^2 (2n+1)) \[Integral](a A(n+1)+n(b B-a C)+b C (2n+1)Sin[c+d x])(a+b Sin[c+d x])^(n+1) \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[(A_.+B_.*sin[c_.+d_.*x_]+C_.*sin[c_.+d_.*x_]^2)*(a_+b_.*sin[c_.+d_.*x_])^n_,x_Symbol] :=
  (b*(A+C)-a*B)*Cos[c+d*x]*(a+b*Sin[c+d*x])^n/(a*d*(2*n+1)) + 
  Dist[1/(a^2*(2*n+1)),
    Int[Sim[a*A*(n+1)+n*(b*B-a*C)+b*C*(2*n+1)*sin[c+d*x],x]*(a+b*sin[c+d*x])^(n+1),x]] /;
FreeQ[{a,b,c,d,A,B,C},x] && ZeroQ[a^2-b^2] && RationalQ[n] && n<-1


(* ::Code:: *)
Int[(A_.+C_.*sin[c_.+d_.*x_]^2)*(a_+b_.*sin[c_.+d_.*x_])^n_,x_Symbol] :=
  b*(A+C)*Cos[c+d*x]*(a+b*Sin[c+d*x])^n/(a*d*(2*n+1)) + 
  Dist[1/(a^2*(2*n+1)),
    Int[Sim[a*A*(n+1)-a*C*n+b*C*(2*n+1)*sin[c+d*x],x]*(a+b*sin[c+d*x])^(n+1),x]] /;
FreeQ[{a,b,c,d,A,C},x] && ZeroQ[a^2-b^2] && RationalQ[n] && n<-1


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Derivation: Rule 1 with m=0 and k=-1*)


(* ::Subsubsection:: *)
(*Rule 4b: If  a^2-b^2=0 \[And] n<-1, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral](A+B Csc[c+d x]+C Csc[c+d x]^2) (a+b Csc[c+d x])^n \[DifferentialD]x  \[LongRightArrow]  *)
(*(((a B-b(A+C))Cot[c+d x](a+b Csc[c+d x])^n)/(b d (2n+1)))+*)
(*1/(a^2 (2n+1)) \[Integral](a A(2 n+1)+(b C n-(b A-a B)(n+1))Csc[c+d x])(a+b Csc[c+d x])^(n+1) \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[(A_.+B_.*sin[c_.+d_.*x_]^(-1)+C_.*sin[c_.+d_.*x_]^(-2))*(a_+b_.*sin[c_.+d_.*x_]^(-1))^n_,x_Symbol] :=
  (a*B-b*(A+C))*Cot[c+d*x]*(a+b*Csc[c+d*x])^n/(b*d*(2*n+1)) + 
  Dist[1/(a^2*(2*n+1)),
    Int[Sim[a*A*(2*n+1)+(b*C*n-(b*A-a*B)*(n+1))*sin[c+d*x]^(-1),x]*(a+b*sin[c+d*x]^(-1))^(n+1),x]] /;
FreeQ[{a,b,c,d,A,B,C},x] && ZeroQ[a^2-b^2] && RationalQ[n] && n<-1


(* ::Code:: *)
Int[(A_.+C_.*sin[c_.+d_.*x_]^(-2))*(a_+b_.*sin[c_.+d_.*x_]^(-1))^n_,x_Symbol] :=
  -(A+C)*Cot[c+d*x]*(a+b*Csc[c+d*x])^n/(d*(2*n+1)) + 
  Dist[1/(a^2*(2*n+1)),
    Int[Sim[a*A*(2*n+1)+(b*C*n-b*A*(n+1))*sin[c+d*x]^(-1),x]*(a+b*sin[c+d*x]^(-1))^(n+1),x]] /;
FreeQ[{a,b,c,d,A,C},x] && ZeroQ[a^2-b^2] && RationalQ[n] && n<-1


(* ::PageBreak:: *)
(**)


(* ::Subsubtitle::Bold::Closed:: *)
(*Rules 1-3:  \[Integral](Sin[c+d x]^j)^m (A+B Sin[c+d x]^k+C Sin[c+d x]^(2k)) (a+b Sin[c+d x]^k)^n \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Derivation: Algebraic simplification*)


(* ::Subsubsection:: *)
(*Rule: If  j^2=k^2=1 \[And] a^2-b^2=0, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral](Sin[c+d x]^j)^m (B Sin[c+d x]^k+C Sin[c+d x]^(2k)) (a+b Sin[c+d x]^k)^n \[DifferentialD]x  \[LongRightArrow]*)
(*\[Integral](Sin[c+d x]^j)^(m+j k) (B+C Sin[c+d x]^k) (a+b Sin[c+d x]^k)^n \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[(sin[c_.+d_.*x_]^j_.)^m_.*(B_.*sin[c_.+d_.*x_]^k_.+C_.*sin[c_.+d_.*x_]^k2_)*
    (a_+b_.*sin[c_.+d_.*x_]^k_.)^n_.,x_Symbol] :=
  Int[(sin[c+d*x]^j)^(m+j*k)*(B+C*sin[c+d*x]^k)*(a+b*sin[c+d*x]^k)^n,x] /;
FreeQ[{a,b,c,d,B,C,m,n},x] && OneQ[j^2,k^2] && k2===2*k && ZeroQ[a^2-b^2]


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Derivation: Recurrence 12 plus recurrence 7 with A=0, B=C and m=m+j k*)


(* ::Subsubsection:: *)
(*Rule 1: If  j^2=k^2=1 \[And] a^2-b^2=0 \[And] n<=-1, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral](Sin[c+d x]^j)^m (A+B Sin[c+d x]^k+C Sin[c+d x]^(2k)) (a+b Sin[c+d x]^k)^n \[DifferentialD]x  \[LongRightArrow]  *)
(*(((a B-b A-b C)Cos[c+d x](Sin[c+d x]^j)^(m+j k) (a+b Sin[c+d x]^k)^n)/(b d (2n+1)))+*)
(*1/(a^2 (2n+1)) \[Integral](Sin[c+d x]^j)^m\[CenterDot]*)
(*(a A(2 n+1)-(b B-a A-a C)(j k m+(k+1)/2)+(b C n-(b A-a B)(n+1)+(a B-b A-b C)(j k m+(k+1)/2))Sin[c+d x]^k) (a+b Sin[c+d x]^k)^(n+1) \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[(sin[c_.+d_.*x_]^j_.)^m_.*(A_+B_.*sin[c_.+d_.*x_]^k_.+C_.*sin[c_.+d_.*x_]^k2_)*
    (a_+b_.*sin[c_.+d_.*x_]^k_.)^n_,x_Symbol] :=
  (a*B-b*A-b*C)*Cos[c+d*x]*(Sin[c+d*x]^j)^(m+j*k)*(a+b*Sin[c+d*x]^k)^n/(b*d*(2*n+1)) + 
  Dist[1/(a^2*(2*n+1)),
    Int[(sin[c+d*x]^j)^m*
      Sim[a*A*(2*n+1)-(b*B-a*A-a*C)*(j*k*m+(k+1)/2)+
        (b*C*n-(b*A-a*B)*(n+1)+(a*B-b*A-b*C)*(j*k*m+(k+1)/2))*sin[c+d*x]^k,x]*
      (a+b*sin[c+d*x]^k)^(n+1),x]] /;
FreeQ[{a,b,c,d,A,B,C},x] && OneQ[j^2,k^2] && k2===2*k && ZeroQ[a^2-b^2] && 
  RationalQ[m,n] && n<=-1


(* ::Code:: *)
Int[(sin[c_.+d_.*x_]^j_.)^m_.*(A_.+C_.*sin[c_.+d_.*x_]^k2_)*(a_+b_.*sin[c_.+d_.*x_]^k_.)^n_,x_Symbol] :=
  -(A+C)*Cos[c+d*x]*(Sin[c+d*x]^j)^(m+j*k)*(a+b*Sin[c+d*x]^k)^n/(d*(2*n+1)) + 
  Dist[1/(a^2*(2*n+1)),
    Int[(sin[c+d*x]^j)^m*
      Sim[a*A*(2*n+1)+a*(A+C)*(j*k*m+(k+1)/2)+
        (b*C*n-b*A*(n+1)-b*(A+C)*(j*k*m+(k+1)/2))*sin[c+d*x]^k,x]*
      (a+b*sin[c+d*x]^k)^(n+1),x]] /;
FreeQ[{a,b,c,d,A,C},x] && OneQ[j^2,k^2] && k2===2*k && ZeroQ[a^2-b^2] && 
  RationalQ[m,n] && n<=-1


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Derivation: Recurrence 11 with B=0*)


(* ::Subsubsection:: *)
(*Rule 2: If  j^2=k^2=1 \[And] a^2-b^2=0 \[And] j k m<-1 \[And] n>-1, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral](Sin[c+d x]^j)^m (A+B Sin[c+d x]^k+C Sin[c+d x]^(2k)) (a+b Sin[c+d x]^k)^n \[DifferentialD]x  \[LongRightArrow]  *)
(*((A Cos[c+d x] (Sin[c+d x]^j)^(m+j k) (a+b Sin[c+d x]^k)^n)/(d(j k m+(k+1)/2)))+1/(a(j k m+(k+1)/2)) \[Integral](Sin[c+d x]^j)^(m+j k)\[CenterDot]*)
(*(a B(j k m+(k+1)/2)-b A n+a(A(n+1)+(A+C)(j k m+(k+1)/2))Sin[c+d x]^k) (a+b Sin[c+d x]^k)^n \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[(sin[c_.+d_.*x_]^j_.)^m_*(A_+B_.*sin[c_.+d_.*x_]^k_.+C_.*sin[c_.+d_.*x_]^k2_)*
    (a_+b_.*sin[c_.+d_.*x_]^k_.)^n_.,x_Symbol] :=
  A*Cos[c+d*x]*(Sin[c+d*x]^j)^(m+j*k)*(a+b*Sin[c+d*x]^k)^n/(d*(j*k*m+(k+1)/2)) + 
  Dist[1/(a*(j*k*m+(k+1)/2)),
    Int[(sin[c+d*x]^j)^(m+j*k)*
      Sim[a*B*(j*k*m+(k+1)/2)-b*A*n+a*(A*(n+1)+(A+C)*(j*k*m+(k+1)/2))*sin[c+d*x]^k,x]*
      (a+b*sin[c+d*x]^k)^n,x]] /;
FreeQ[{a,b,c,d,A,B,C},x] && OneQ[j^2,k^2] && k2===2*k && ZeroQ[a^2-b^2] && 
  RationalQ[m,n] && j*k*m<-1 && n>-1


(* ::Code:: *)
Int[(sin[c_.+d_.*x_]^j_.)^m_*(A_.+C_.*sin[c_.+d_.*x_]^k2_)*(a_+b_.*sin[c_.+d_.*x_]^k_.)^n_.,x_Symbol] :=
  A*Cos[c+d*x]*(Sin[c+d*x]^j)^(m+j*k)*(a+b*Sin[c+d*x]^k)^n/(d*(j*k*m+(k+1)/2)) + 
  Dist[1/(a*(j*k*m+(k+1)/2)),
    Int[(sin[c+d*x]^j)^(m+j*k)*
      Sim[-b*A*n+a*(A*(n+1)+(A+C)*(j*k*m+(k+1)/2))*sin[c+d*x]^k,x]*
      (a+b*sin[c+d*x]^k)^n,x]] /;
FreeQ[{a,b,c,d,A,C},x] && OneQ[j^2,k^2] && k2===2*k && ZeroQ[a^2-b^2] && 
  RationalQ[m,n] && j*k*m<-1 && n>-1


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Derivation: Recurrence 8 with A=0, B=C and m=m+j k*)


(* ::Subsubsection:: *)
(*Rule 3: If  j^2=k^2=1 \[And] a^2-b^2=0 \[And] j k m+n+(k+3)/2!=0 \[And] j k m>=-1 \[And] n>-1, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral](Sin[c+d x]^j)^m (A+B Sin[c+d x]^k+C Sin[c+d x]^(2k)) (a+b Sin[c+d x]^k)^n \[DifferentialD]x  \[LongRightArrow]  *)
(*-((C Cos[c+d x](Sin[c+d x]^j)^(m+j k) (a+b Sin[c+d x]^k)^n)/(d (j k m+n+(k+3)/2)))+1/(a (j k m+n+(k+3)/2)) \[Integral](Sin[c+d x]^j)^m\[CenterDot]*)
(*(a A (n+1)+a(A+C)(j k m+(k+1)/2)+(b C n+a B (j k m+n+(k+3)/2)) Sin[c+d x]^k) (a+b Sin[c+d x]^k)^n \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[(sin[c_.+d_.*x_]^j_.)^m_.*(A_+B_.*sin[c_.+d_.*x_]^k_.+C_.*sin[c_.+d_.*x_]^k2_)*
    (a_+b_.*sin[c_.+d_.*x_]^k_.)^n_.,x_Symbol] :=
  -C*Cos[c+d*x]*(Sin[c+d*x]^j)^(m+j*k)*(a+b*Sin[c+d*x]^k)^n/(d*(j*k*m+n+(k+3)/2)) + 
  Dist[1/(a*(j*k*m+n+(k+3)/2)),
    Int[(sin[c+d*x]^j)^m*
      Sim[a*A*(n+1)+a*(A+C)*(j*k*m+(k+1)/2)+(b*C*n+a*B*(j*k*m+n+(k+3)/2))*sin[c+d*x]^k,x]*
      (a+b*sin[c+d*x]^k)^n,x]] /;
FreeQ[{a,b,c,d,A,B,C},x] && OneQ[j^2,k^2] && k2===2*k && ZeroQ[a^2-b^2] && 
  RationalQ[m,n] && NonzeroQ[j*k*m+n+(k+3)/2] && j*k*m>=-1 && n>-1


(* ::Code:: *)
Int[(sin[c_.+d_.*x_]^j_.)^m_.*(A_.+C_.*sin[c_.+d_.*x_]^k2_)*(a_+b_.*sin[c_.+d_.*x_]^k_.)^n_.,x_Symbol] :=
  -C*Cos[c+d*x]*(Sin[c+d*x]^j)^(m+j*k)*(a+b*Sin[c+d*x]^k)^n/(d*(j*k*m+n+(k+3)/2)) + 
  Dist[1/(a*(j*k*m+n+(k+3)/2)),
    Int[(sin[c+d*x]^j)^m*
      Sim[a*A*(n+1)+a*(A+C)*(j*k*m+(k+1)/2)+b*C*n*sin[c+d*x]^k,x]*
      (a+b*sin[c+d*x]^k)^n,x]] /;
FreeQ[{a,b,c,d,A,C},x] && OneQ[j^2,k^2] && k2===2*k && ZeroQ[a^2-b^2] && 
  RationalQ[m,n] && NonzeroQ[j*k*m+n+(k+3)/2] && j*k*m>=-1 && n>-1


(* ::PageBreak:: *)
(**)
