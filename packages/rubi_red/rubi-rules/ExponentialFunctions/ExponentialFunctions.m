(* ::Package:: *)

(* ::Title::Bold::Closed:: *)
(*\[Integral]f^(a+b x^n) \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Reference: G&R 2.311, CRC 519, A&S 4.2.54*)


(* ::Subsubsection:: *)
(*Derivation: Primitive rule*)


(* ::Subsubsection:: *)
(*Basis: \!\( *)
(*\*SubscriptBox[\(\[PartialD]\), \(x\)]*)
(*\*SuperscriptBox[\(E\), \(x\)]\)=E^x*)


(* ::Subsubsection:: *)
(*Rule: *)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]f^(a+b x) \[DifferentialD]x  \[LongRightArrow]  (f^(a+b x)/(b Log[f]))*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[E^(a_.+b_.*x_),x_Symbol] :=
  E^(a+b*x)/b /;
FreeQ[{a,b},x]


(* ::Code:: *)
Int[f_^(a_.+b_.*x_),x_Symbol] :=
  f^(a+b*x)/(b*Log[f]) /;
FreeQ[{a,b,f},x]


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Derivation: Primitive rule*)


(* ::Subsubsection:: *)
(*Basis: Derivative[1][Erfi][z]=(2 E^z^2)/Sqrt[\[Pi]]*)


(* ::Subsubsection:: *)
(*Rule: If b>0, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]f^(a+b x^2) \[DifferentialD]x  \[LongRightArrow]  ((f^a Sqrt[\[Pi]] Erfi[x Sqrt[b Log[f]]])/(2 Sqrt[b Log[f]]))*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[E^(a_.+b_.*x_^2),x_Symbol] :=
  E^a*Sqrt[Pi]*Erfi[x*Rt[b,2]]/(2*Rt[b,2]) /;
FreeQ[{a,b},x] && PosQ[b]


(* ::Code:: *)
Int[f_^(a_.+b_.*x_^2),x_Symbol] :=
  f^a*Sqrt[Pi]*Erfi[x*Rt[b*Log[f],2]]/(2*Rt[b*Log[f],2]) /;
FreeQ[{a,b,f},x] && PosQ[b*Log[f]]


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Derivation: Primitive rule*)


(* ::Subsubsection:: *)
(*Basis: Derivative[1][Erf][z]=(2 E^-z^2)/Sqrt[\[Pi]]*)


(* ::Subsubsection:: *)
(*Rule: If \[Not](b>0), then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]f^(a+b x^2) \[DifferentialD]x  \[LongRightArrow]  ((f^a Sqrt[\[Pi]] Erf[x Sqrt[-b Log[f]]])/(2 Sqrt[-b Log[f]]))*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[E^(a_.+b_.*x_^2),x_Symbol] :=
  E^a*Sqrt[Pi]*Erf[x*Rt[-b,2]]/(2*Rt[-b,2]) /;
FreeQ[{a,b},x] && NegQ[b]


(* ::Code:: *)
Int[f_^(a_.+b_.*x_^2),x_Symbol] :=
  f^a*Sqrt[Pi]*Erf[x*Rt[-b*Log[f],2]]/(2*Rt[-b*Log[f],2]) /;
FreeQ[{a,b,f},x] && NegQ[b*Log[f]]


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Derivation: Primitive rule*)


(* ::Subsubsection:: *)
(*Basis: \!\( *)
(*\*SubscriptBox[\(\[PartialD]\), \(x\)]\**)
(*FormBox[*)
(*TemplateBox[{"n","x"},*)
(*"Gamma2"],*)
(*TraditionalForm]\)=-E^-x x^(n-1)*)


(* ::Subsubsection:: *)
(*Rule: If \[Not](b>0), then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]f^(a+b x^n) \[DifferentialD]x  \[LongRightArrow]  -((f^a x \[CapitalGamma][1/n,-b x^n Log[f]])/(n (-b x^n Log[f])^(1/n)))*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[E^(a_.+b_.*x_^n_),x_Symbol] :=
  -E^a*x*Gamma[1/n,-b*x^n]/(n*(-b*x^n)^(1/n)) /;
FreeQ[{a,b,n},x] && Not[FractionOrNegativeQ[n]]


(* ::Code:: *)
Int[f_^(a_.+b_.*x_^n_),x_Symbol] :=
  -f^a*x*Gamma[1/n,-b*x^n*Log[f]]/(n*(-b*x^n*Log[f])^(1/n)) /;
FreeQ[{a,b,f,n},x] && Not[FractionOrNegativeQ[n]]


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Derivation: Integration by parts*)


(* ::Subsubsection:: *)
(*Note: Although resulting integrand looks more complicated than the original, rules for improper binomials rectify it.*)


(* ::Subsubsection:: *)
(*Rule: If n\[Element]\[DoubleStruckCapitalZ] \[And] n<0, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]f^(a+b x^n) \[DifferentialD]x  \[LongRightArrow]  x f^(a+b x^n)-b n Log[f]\[Integral]x^n f^(a+b x^n) \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[E^(a_.+b_.*x_^n_.),x_Symbol] :=
  x*E^(a+b*x^n) - 
  Dist[b*n,Int[x^n*E^(a+b*x^n),x]] /;
FreeQ[{a,b},x] && IntegerQ[n] && n<0


(* ::Code:: *)
Int[f_^(a_.+b_.*x_^n_.),x_Symbol] :=
  x*f^(a+b*x^n) - 
  Dist[b*n*Log[f],Int[x^n*f^(a+b*x^n),x]] /;
FreeQ[{a,b,f},x] && IntegerQ[n] && n<0


(* ::PageBreak:: *)
(**)


(* ::Title::Bold::Closed:: *)
(*\[Integral]x^m f^(a+b x^n) \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Derivation: Primitive rule*)


(* ::Subsubsection:: *)
(*Basis: Derivative[1][ExpIntegralEi][z]=E^z/z*)


(* ::Subsubsection:: *)
(*Rule: *)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]f^(a+b x^n)/x \[DifferentialD]x  \[LongRightArrow]  ((f^a ExpIntegralEi[b x^n Log[f]])/n)*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[f_^(a_.+b_.*x_^n_.)/x_,x_Symbol] :=
  f^a*ExpIntegralEi[b*x^n*Log[f]]/n /;
FreeQ[{a,b,f,n},x]


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Reference: G&R 2.321.1, CRC 521, A&S 4.2.55*)


(* ::Subsubsection:: *)
(*Derivation: Integration by parts*)


(* ::Subsubsection:: *)
(*Basis: x^m f^(a+b x^n)=x^(m-n+1) (f^(a+b x^n) x^(n-1))*)


(* ::Subsubsection:: *)
(*Rule: If n\[Element]\[DoubleStruckCapitalZ] \[And] 0<n<=m, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]x^m f^(a+b x^n) \[DifferentialD]x  \[LongRightArrow]  ((x^(m-n+1) f^(a+b x^n))/(b n Log[f]))-(m-n+1)/(b n Log[f]) \[Integral]x^(m-n) f^(a+b x^n) \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[x_^m_.*f_^(a_.+b_.*x_^n_.),x_Symbol] :=
  x^(m-n+1)*f^(a+b*x^n)/(b*n*Log[f]) -
  Dist[(m-n+1)/(b*n*Log[f]),Int[x^(m-n)*f^(a+b*x^n),x]] /;
FreeQ[{a,b,f},x] && IntegerQ[n] && RationalQ[m] && 0<n<=m


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Reference: G&R 2.324.1, CRC 523, A&S 4.2.56*)


(* ::Subsubsection:: *)
(*Derivation: Integration by parts*)


(* ::Subsubsection:: *)
(*Rule: If n\[Element]\[DoubleStruckCapitalZ] \[And] (n>0 \[And] m<-1 \[Or] 0<-n<=m+1, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]x^m f^(a+b x^n) \[DifferentialD]x  \[LongRightArrow]  ((x^(m+1) f^(a+b x^n))/(m+1))-(b n Log[f])/(m+1) \[Integral]x^(m+n) f^(a+b x^n) \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[x_^m_.*f_^(a_.+b_.*x_^n_.),x_Symbol] :=
  x^(m+1)*f^(a+b*x^n)/(m+1) -
  Dist[b*n*Log[f]/(m+1),Int[x^(m+n)*f^(a+b*x^n),x]] /;
FreeQ[{a,b,f},x] && IntegerQ[n] && RationalQ[m] && (n>0 && m<-1 || 0<-n<=m+1)


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Rule: If m+1!=0 \[And] m-n+1!=0 \[And] \[Not](m=-(1/2) \[And] n=1), then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]x^m f^(a+b x^n) \[DifferentialD]x  \[LongRightArrow]  -((f^a x^(m+1) \[CapitalGamma][(m+1)/n,-b x^n Log[f]])/(n (-b x^n Log[f])^((m+1)/n)))*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[x_^m_.*f_^(a_.+b_.*x_^n_.),x_Symbol] :=
  -f^a*x^(m+1)*Gamma[(m+1)/n,-b*x^n*Log[f]]/(n*(-b*x^n*Log[f])^((m+1)/n)) /;
FreeQ[{a,b,f,m,n},x] &&
  NonzeroQ[m+1] &&
  NonzeroQ[m-n+1] &&
  Not[m===-1/2 && ZeroQ[n-1]] &&
  Not[IntegersQ[m,n] && n>0 && (m<-1 || m>=n)] &&
  Not[RationalQ[{m,n}] && (FractionQ[m] || FractionOrNegativeQ[n])]


(* ::PageBreak:: *)
(**)


(* ::Title::Bold::Closed:: *)
(*\[Integral]f^(a+b x+c x^2) \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Derivation: Algebraic expansion*)


(* ::Subsubsection:: *)
(*Basis: a+b x+c x^2=(4 a c-b^2)/(4 c)+(b+2 c x)^2/(4 c)*)


(* ::Subsubsection:: *)
(*Basis: f^(z+w)=f^z f^w*)


(* ::Subsubsection:: *)
(*Rule:*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]f^(a+b x+c x^2) \[DifferentialD]x  \[LongRightArrow]  f^(((4 a c-b^2)/(4 c))) \[Integral]f^((b+2 c x)^2/(4 c)) \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[f_^(a_.+b_.*x_+c_.*x_^2),x_Symbol] :=
  f^(a-b^2/(4*c))*Int[f^((b+2*c*x)^2/(4*c)),x] /;
FreeQ[{a,b,c,f},x]


(* ::PageBreak:: *)
(**)


(* ::Title::Bold::Closed:: *)
(*\[Integral](d+e x)^m f^(a+b x+c x^2) \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Derivation: Inverted integration by parts*)


(* ::Subsubsection:: *)
(*Rule: If  b e-2 c d!=0, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral](d+e x)f^(a+b x+c x^2) \[DifferentialD]x  \[LongRightArrow]  ((e f^(a+b x+c x^2))/(2 c Log[f]))-(b e-2 c d)/(2 c) \[Integral]f^(a+b x+c x^2) \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[(d_.+e_.*x_)*f_^(a_.+b_.*x_+c_.*x_^2),x_Symbol] :=
  e*f^(a+b*x+c*x^2)/(2*c*Log[f]) -
  Dist[(b*e-2*c*d)/(2*c),Int[f^(a+b*x+c*x^2),x]] /;
FreeQ[{a,b,c,d,e,f},x] && NonzeroQ[b*e-2*c*d]


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Derivation: Inverted integration by parts*)


(* ::Subsubsection:: *)
(*Rule: If  m>1 \[And] b e-2 c d=0, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral](d+e x)^m f^(a+b x+c x^2) \[DifferentialD]x  \[LongRightArrow]  ((e (d+e x)^(m-1) f^(a+b x+c x^2))/(2 c Log[f]))-((m-1) e^2)/(2 c Log[f]) \[Integral](d+e x)^(m-2) f^(a+b x+c x^2) \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[(d_.+e_.*x_)^m_*f_^(a_.+b_.*x_+c_.*x_^2),x_Symbol] :=
  e*(d+e*x)^(m-1)*f^(a+b*x+c*x^2)/(2*c*Log[f]) -
  Dist[(m-1)*e^2/(2*c*Log[f]),Int[(d+e*x)^(m-2)*f^(a+b*x+c*x^2),x]] /;
FreeQ[{a,b,c,d,e,f},x] && RationalQ[m] && m>1 && ZeroQ[b*e-2*c*d]


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Derivation: Inverted integration by parts*)


(* ::Subsubsection:: *)
(*Rule: If  m>1 \[And] b e-2 c d!=0, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral](d+e x)^m f^(a+b x+c x^2) \[DifferentialD]x  \[LongRightArrow]  ((e (d+e x)^(m-1) f^(a+b x+c x^2))/(2 c Log[f]))-                                                                        *)
(*                            (b e-2 c d)/(2 c) \[Integral](d+e x)^(m-1) f^(a+b x+c x^2) \[DifferentialD]x-((m-1) e^2)/(2 c Log[f]) \[Integral](d+e x)^(m-2) f^(a+b x+c x^2) \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[(d_.+e_.*x_)^m_*f_^(a_.+b_.*x_+c_.*x_^2),x_Symbol] :=
  e*(d+e*x)^(m-1)*f^(a+b*x+c*x^2)/(2*c*Log[f]) -
  Dist[(b*e-2*c*d)/(2*c),Int[(d+e*x)^(m-1)*f^(a+b*x+c*x^2),x]] -
  Dist[(m-1)*e^2/(2*c*Log[f]),Int[(d+e*x)^(m-2)*f^(a+b*x+c*x^2),x]] /;
FreeQ[{a,b,c,d,e,f},x] && RationalQ[m] && m>1 && NonzeroQ[b*e-2*c*d]


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Derivation: Integration by parts*)


(* ::Subsubsection:: *)
(*Rule: If  m<-1 \[And] b e-2 c d=0, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral](d+e x)^m f^(a+b x+c x^2) \[DifferentialD]x  \[LongRightArrow]  (((d+e x)^(m+1) f^(a+b x+c x^2))/(e (m+1)))-(2 c Log[f])/(e^2 (m+1)) \[Integral](d+e x)^(m+2) f^(a+b x+c x^2) \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[(d_.+e_.*x_)^m_*f_^(a_.+b_.*x_+c_.*x_^2),x_Symbol] :=
  (d+e*x)^(m+1)*f^(a+b*x+c*x^2)/(e*(m+1)) -
  Dist[2*c*Log[f]/(e^2*(m+1)),Int[(d+e*x)^(m+2)*f^(a+b*x+c*x^2),x]] /;
FreeQ[{a,b,c,d,e,f},x] && RationalQ[m] && m<-1 && ZeroQ[b*e-2*c*d]


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Derivation: Integration by parts*)


(* ::Subsubsection:: *)
(*Rule: If  m<-1 \[And] b e-2 c d!=0, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral](d+e x)^m f^(a+b x+c x^2) \[DifferentialD]x  \[LongRightArrow]  (((d+e x)^(m+1) f^(a+b x+c x^2))/(e (m+1)))-                                                                               *)
(*        ((b e-2 c d) Log[f])/(e^2 (m+1)) \[Integral](d+e x)^(m+1) f^(a+b x+c x^2) \[DifferentialD]x-(2 c Log[f])/(e^2 (m+1)) \[Integral](d+e x)^(m+2) f^(a+b x+c x^2) \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[(d_.+e_.*x_)^m_*f_^(a_.+b_.*x_+c_.*x_^2),x_Symbol] :=
  (d+e*x)^(m+1)*f^(a+b*x+c*x^2)/(e*(m+1)) -
  Dist[(b*e-2*c*d)*Log[f]/(e^2*(m+1)),Int[(d+e*x)^(m+1)*f^(a+b*x+c*x^2),x]] -
  Dist[2*c*Log[f]/(e^2*(m+1)),Int[(d+e*x)^(m+2)*f^(a+b*x+c*x^2),x]] /;
FreeQ[{a,b,c,d,e,f},x] && RationalQ[m] && m<-1 && NonzeroQ[b*e-2*c*d]


(* ::PageBreak:: *)
(**)


(* ::Title::Bold::Closed:: *)
(*\[Integral](a+b x)^m f^(c+d x)^n \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Derivation: Integration by parts*)


(* ::Subsubsection:: *)
(*Rule: If  m<-1 \[And] n\[Element]\[DoubleStruckCapitalZ] \[And] n>1, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral](a+b x)^m f^(c+d x)^n \[DifferentialD]x  \[LongRightArrow]  (((a+b x)^(m+1) f^(c+d x)^n)/(b (m+1)))-(d n Log[f])/(b (m+1)) \[Integral](a+b x)^(m+1) f^(c+d x)^n (c+d x)^(n-1) \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[(a_.+b_.*x_)^m_*f_^((c_.+d_.*x_)^n_.),x_Symbol] :=
  (a+b*x)^(m+1)*f^((c+d*x)^n)/(b*(m+1)) -
  Dist[d*n*Log[f]/(b*(m+1)),Int[(a+b*x)^(m+1)*f^((c+d*x)^n)*(c+d*x)^(n-1),x]] /;
FreeQ[{a,b,c,d},x] && RationalQ[m] && m<-1 && IntegerQ[n] && n>1


(* ::PageBreak:: *)
(**)


(* ::Title::Bold::Closed:: *)
(*\[Integral](a+b f^(c+d x))^n \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Reference: CRC 256*)


(* ::Subsubsection:: *)
(*Rule: If  d<0, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]1/(a+b f^(c+d x)) \[DifferentialD]x  \[LongRightArrow]  -(Log[b+a f^(-c-d x)]/(a d Log[f]))*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[1/(a_+b_.*f_^(c_.+d_.*x_)),x_Symbol] :=
  -Log[b+a*f^(-c-d*x)]/(a*d*Log[f]) /;
FreeQ[{a,b,c,d,f},x] && NegativeCoefficientQ[d]


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Reference: CRC 256*)


(* ::Subsubsection:: *)
(*Rule: If  \[Not](d<0), then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]1/(a+b f^(c+d x)) \[DifferentialD]x  \[LongRightArrow]  (x/a)-Log[a+b f^(c+d x)]/(a d Log[f])*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[1/(a_+b_.*f_^(c_.+d_.*x_)),x_Symbol] :=
  x/a-Log[a+b*f^(c+d*x)]/(a*d*Log[f]) /;
FreeQ[{a,b,c,d,f},x]


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Rule: If  a>0, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]1/Sqrt[a+b f^(c+d x)] \[DifferentialD]x  \[LongRightArrow]  -(2/(Sqrt[a] d Log[f]))ArcTanh[Sqrt[a+b f^(c+d x)]/Sqrt[a]]*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[1/Sqrt[a_+b_.*f_^(c_.+d_.*x_)],x_Symbol] :=
  -2*ArcTanh[Sqrt[a+b*f^(c+d*x)]/Sqrt[a]]/(Sqrt[a]*d*Log[f]) /;
FreeQ[{a,b,c,d,f},x] && PosQ[a]


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Rule: If  \[Not](a>0), then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]1/Sqrt[a+b f^(c+d x)] \[DifferentialD]x  \[LongRightArrow]  (2/(Sqrt[-a] d Log[f]))ArcTan[Sqrt[a+b f^(c+d x)]/Sqrt[-a]]*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[1/Sqrt[a_+b_.*f_^(c_.+d_.*x_)],x_Symbol] :=
  2*ArcTan[Sqrt[a+b*f^(c+d*x)]/Sqrt[-a]]/(Sqrt[-a]*d*Log[f]) /;
FreeQ[{a,b,c,d,f},x] && NegQ[a]


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Rule: If  n>0, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral](a+b f^(c+d x))^n \[DifferentialD]x  \[LongRightArrow]  ((a+b f^(c+d x))^n/(n d Log[f]))+a \[Integral](a+b f^(c+d x))^(n-1) \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[(a_+b_.*f_^(c_.+d_.*x_))^n_,x_Symbol] :=
  (a+b*f^(c+d*x))^n/(n*d*Log[f]) + 
  Dist[a,Int[(a+b*f^(c+d*x))^(n-1),x]] /;
FreeQ[{a,b,c,d,f},x] && FractionQ[n] && n>0


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Rule: If  n<-1, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral](a+b f^(c+d x))^n \[DifferentialD]x  \[LongRightArrow]  ((a+b f^(c+d x))^(n+1)/((n+1) a d Log[f]))+1/a \[Integral](a+b f^(c+d x))^(n+1) \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[(a_+b_.*f_^(c_.+d_.*x_))^n_,x_Symbol] :=
  -(a+b*f^(c+d*x))^(n+1)/((n+1)*a*d*Log[f]) + 
  Dist[1/a,Int[(a+b*f^(c+d*x))^(n+1),x]] /;
FreeQ[{a,b,c,d,f},x] && RationalQ[n] && n<-1


(* ::PageBreak:: *)
(**)


(* ::Title::Bold::Closed:: *)
(*\[Integral]x^m (a+b f^(c+d x))^n \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Derivation: Algebraic expansion*)


(* ::Subsubsection:: *)
(*Basis: 1/(a+b z)=1/a-(b z)/(a (a+b z))*)


(* ::Subsubsection:: *)
(*Rule: If  m>0, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]x^m/(a+b f^(c+d x)) \[DifferentialD]x  \[LongRightArrow]  (x^(m+1)/(a (m+1)))-b/a \[Integral](x^m f^(c+d x))/(a+b f^(c+d x)) \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[x_^m_./(a_+b_.*f_^(c_.+d_.*x_)), x_Symbol] :=
  x^(m+1)/(a*(m+1)) -
  Dist[b/a,Int[x^m*f^(c+d*x)/(a+b*f^(c+d*x)),x]] /;
FreeQ[{a,b,c,d,f},x] && RationalQ[m] && m>0


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Derivation: Integration by parts*)


(* ::Subsubsection:: *)
(*Rule: If  m>0 \[And] n<-1, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]x^m (a+b f^(c+d x))^n \[DifferentialD]x  \[LongRightArrow]  x^m \[Integral](a+b f^(c+d x))^n \[DifferentialD]x-m \[Integral](x^(m-1) \[Integral](a+b f^(c+d x))^n \[DifferentialD]x)\[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[x_^m_.*(a_+b_.*f_^(c_.+d_.*x_))^n_, x_Symbol] :=
  Module[{u=Block[{ShowSteps=False,StepCounter=Null}, Int[(a+b*f^(c+d*x))^n,x]]},
  x^m*u - Dist[m,Int[x^(m-1)*u,x]]] /;
FreeQ[{a,b,c,d,f},x] && RationalQ[{m,n}] && m>0 && n<-1


(* ::PageBreak:: *)
(**)


(* ::Title::Bold::Closed:: *)
(*\[Integral]x^m f^(c (a+b x)^n) \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Rule: If  m>1, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]x^m f^(c (a+b x)^2) \[DifferentialD]x  \[LongRightArrow]  \[Integral]x^m f^(a^2 c+2 a b c x+b^2 c x^2) \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[x_^m_*f_^(c_.*(a_+b_.*x_)^2),x_Symbol] :=
  Int[x^m*f^(a^2*c+2*a*b*c*x+b^2*c*x^2),x] /;
FreeQ[{a,b,c,f},x] && FractionQ[m] && m>1


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Rule: If  m\[Element]\[DoubleStruckCapitalZ] \[And] m>0, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]x^m (a+b f^(c+d x))^n \[DifferentialD]x  \[LongRightArrow]  (1/b^m)\[Integral]b^m x^m-(a+b x)^m f^(c (a+b x)^n) \[DifferentialD]x+1/b^(m+1) Subst[\[Integral]x^m f^(c x^n) \[DifferentialD]x,x,a+b x]*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[x_^m_.*f_^(c_.*(a_+b_.*x_)^n_),x_Symbol] :=
  Dist[1/b^m,Int[Expand[b^m*x^m-(a+b*x)^m,x]*f^(c*(a+b*x)^n),x]] +
  Dist[1/b^(m+1),Subst[Int[x^m*f^(c*x^n),x],x,a+b*x]] /;
FreeQ[{a,b,c,f,n},x] && IntegerQ[m] && m>0


(* ::PageBreak:: *)
(**)


(* ::Title::Bold::Closed:: *)
(*\[Integral]x^m f^(c+d x) (a+b f^(e+f x))^n \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Derivation: Integration by parts*)


(* ::Subsubsection:: *)
(*Rule: If  m>1, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral](x^m f^(c+d x))/(a+b f^(c+d x)) \[DifferentialD]x  \[LongRightArrow]  ((x^m Log[1+(b f^(c+d x))/a])/(b d Log[f]))-m/(b d Log[f]) \[Integral]x^(m-1) Log[1+(b f^(c+d x))/a]\[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[x_^m_.*f_^(c_.+d_.*x_)/(a_+b_.*f_^(c_.+d_.*x_)), x_Symbol] :=
  x^m*Log[1+b*f^(c+d*x)/a]/(b*d*Log[f]) -
  Dist[m/(b*d*Log[f]),Int[x^(m-1)*Log[1+b/a*f^(c+d*x)],x]] /;
FreeQ[{a,b,c,d,f},x] && RationalQ[m] && m>=1


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Derivation: Integration by parts*)


(* ::Subsubsection:: *)
(*Rule: If  m>0 \[And] n\[Element]\[DoubleStruckCapitalZ]  \[And] n<0, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]x^m f^(c+d x) (a+b f^(2(c+d x)))^n \[DifferentialD]x  \[LongRightArrow]  *)
(*x^m \[Integral]f^(c+d x) (a+b f^(2(c+d x)))^n \[DifferentialD]x-m \[Integral]x^(m-1) (\[Integral]f^(c+d x) (a+b f^(2(c+d x)))^n \[DifferentialD]x)\[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[x_^m_.*f_^(c_.+d_.*x_)*(a_.+b_.*f_^v_)^n_,x_Symbol] :=
  Module[{u=Block[{ShowSteps=False,StepCounter=Null}, Int[f^(c+d*x)*(a+b*f^v)^n,x]]},
  x^m*u - Dist[m,Int[x^(m-1)*u,x]]] /;
FreeQ[{a,b,c,d,f},x] && ZeroQ[2*(c+d*x)-v] && RationalQ[m] && m>0 && IntegerQ[n] && n<0


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Derivation: Integration by parts*)


(* ::Subsubsection:: *)
(*Rule: If  m>0, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]x^m/(a f^(c+d x)+b f^-(c+d*x)) \[DifferentialD]x  \[LongRightArrow]  x^m \[Integral]1/(a f^(c+d x)+b f^-(c+d*x)) \[DifferentialD]x-m \[Integral]x^(m-1) \[Integral]1/(a f^(c+d x)+b f^-(c+d*x)) \[DifferentialD]x\[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[x_^m_./(a_.*f_^(c_.+d_.*x_)+b_.*f_^v_),x_Symbol] :=
  Module[{u=Block[{ShowSteps=False,StepCounter=Null}, Int[1/(a*f^(c+d*x)+b*f^v),x]]},
  x^m*u - Dist[m,Int[x^(m-1)*u,x]]] /;
FreeQ[{a,b,c,d,f},x] && ZeroQ[(c+d*x)+v] && RationalQ[m] && m>0


(* ::PageBreak:: *)
(**)


(* ::Title::Bold::Closed:: *)
(*\[Integral](a+b x)^m f^(e (c+d x)^n) \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Derivation: Integration by substitution*)


(* ::Subsubsection:: *)
(*Rule: If  p\[Element]\[DoubleStruckCapitalQ], then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral](x^m f^(c+d x))/(a+b f^(c+d x)) \[DifferentialD]x  \[LongRightArrow]  (1/b)Subst[\[Integral]x^m (f^(e (c-(a d)/b+(d x)/b)^n))^p \[DifferentialD]x,x,a+b x]*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[(a_.+b_.*x_)^m_.*(f_^(e_.*(c_.+d_.*x_)^n_.))^p_.,x_Symbol] :=
  Dist[1/b,Subst[Int[x^m*(f^(e*(c-a*d/b+d*x/b)^n))^p,x],x,a+b*x]] /;
FreeQ[{a,b,c,d,e,f,m,n},x] && RationalQ[p] && Not[a===0 && b===1]


(* ::PageBreak:: *)
(**)


(* ::Title::Bold::Closed:: *)
(*\[Integral]f^((a+b x^4)/x^2) \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Derivation: Integration by substitution*)


(* ::Subsubsection:: *)
(*Rule: If  p\[Element]\[DoubleStruckCapitalQ], then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]f^((a+b x^4)/x^2) \[DifferentialD]x  \[LongRightArrow]  ((Sqrt[\[Pi]] Exp[2 Sqrt[-a Log[f]] Sqrt[-b Log[f]]] Erf[(Sqrt[-a Log[f]]+Sqrt[-b Log[f]] x^2)/x])/(4 Sqrt[-b Log[f]]))-*)
(*                             (Sqrt[\[Pi]] Exp[-2 Sqrt[-a Log[f]] Sqrt[-b Log[f]]] Erf[(Sqrt[-a Log[f]]-Sqrt[-b Log[f]] x^2)/x])/(4 Sqrt[-b Log[f]])*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[f_^((a_.+b_.*x_^4)/x_^2),x_Symbol] :=
  Sqrt[Pi]*Exp[2*Sqrt[-a*Log[f]]*Sqrt[-b*Log[f]]]*Erf[(Sqrt[-a*Log[f]]+Sqrt[-b*Log[f]]*x^2)/x]/
    (4*Sqrt[-b*Log[f]]) -
  Sqrt[Pi]*Exp[-2*Sqrt[-a*Log[f]]*Sqrt[-b*Log[f]]]*Erf[(Sqrt[-a*Log[f]]-Sqrt[-b*Log[f]]*x^2)/x]/
    (4*Sqrt[-b*Log[f]]) /;
FreeQ[{a,b,f},x]


(* ::PageBreak:: *)
(**)


(* ::Title::Bold::Closed:: *)
(*\[Integral]u/(a+b f^(d+e x)+c f^(g+h x)) \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Derivation: Algebraic expansion*)


(* ::Subsubsection:: *)
(*Basis: 1/(a+b f^z+c f^(2 z))=1/a-(f^z (b+c f^z))/(a (a+b f^z+c f^(2 z)))*)


(* ::Subsubsection:: *)
(*Rule:*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]1/(a+b f^(d+e x)+c f^(2(d+e x))) \[DifferentialD]x  \[LongRightArrow]  (x/a)-1/a \[Integral](f^(d+e x) (b+c f^(d+e x)))/(a+b f^(d+e x)+c f^(2(d+e x))) \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[1/(a_+b_.*f_^u_+c_.*f_^v_), x_Symbol] :=
  x/a -
  Dist[1/a,Int[f^u*(b+c*f^u)/(a+b*f^u+c*f^v),x]] /;
FreeQ[{a,b,c,f},x] && LinearQ[u,x] && LinearQ[v,x] && ZeroQ[2*u-v] &&
Not[RationalQ[Rt[b^2-4*a*c,2]]]


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Derivation: Algebraic expansion*)


(* ::Subsubsection:: *)
(*Basis: (d+e f^z)/(a+b f^z+c f^(2 z))=d/a-(f^z (b d-a e+c d f^z))/(a (a+b f^z+c f^(2 z)))*)


(* ::Subsubsection:: *)
(*Rule:*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral](d+e f^(d+e x))/(a+b f^(d+e x)+c f^(2(d+e x))) \[DifferentialD]x  \[LongRightArrow]  ((d x)/a)-1/a \[Integral](f^(d+e x) (b d-a e+c d f^(d+e x)))/(a+b f^(d+e x)+c f^(2(d+e x))) \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[(d_+e_.*f_^u_)/(a_+b_.*f_^u_+c_.*f_^v_), x_Symbol] :=
  d*x/a -
  Dist[1/a,Int[f^u*(b*d-a*e+c*d*f^u)/(a+b*f^u+c*f^v),x]] /;
FreeQ[{a,b,c,d,e,f},x] && LinearQ[u,x] && LinearQ[v,x] && ZeroQ[2*u-v] &&
Not[RationalQ[Rt[b^2-4*a*c,2]]]


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Derivation: Algebraic simplification*)


(* ::Subsubsection:: *)
(*Basis: 1/(a+b z+c/z)=z/(c+a z+b z^2)*)


(* ::Subsubsection:: *)
(*Rule:*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]u/(a+b f^(d+e x)+c f^-(d+e x)) \[DifferentialD]x  \[LongRightArrow]  \[Integral](u f^(d+e x))/(c+a f^(d+e x)+b f^(2 (d+e x))) \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[u_/(a_+b_.*f_^v_+c_.*f_^w_), x_Symbol] :=
  Int[u*f^v/(c+a*f^v+b*f^(2*v)),x] /;
FreeQ[{a,b,c,f},x] && LinearQ[v,x] && LinearQ[w,x] && ZeroQ[v+w] &&
If[RationalQ[Coefficient[v,x,1]], Coefficient[v,x,1]>0, LeafCount[v]<LeafCount[w]]


(* ::PageBreak:: *)
(**)


(* ::Title::Bold::Closed:: *)
(*\[Integral]x^m (E^x+x^m)^n \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Derivation: Algebraic expansion*)


(* ::Subsubsection:: *)
(*Basis: \[Integral]f[x] (E^x+f[x])^n\[DifferentialD]x==-((E^x+f[x])^(n+1)/(n+1))+\[Integral](E^x+f[x])^(n+1) \[DifferentialD]x+\[Integral]Derivative[1][f][x] (E^x+f[x])^n\[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Rule: If  m>0 \[And] n+1!=0, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]x^m (E^x+x^m)^n \[DifferentialD]x  \[LongRightArrow]  -((E^x+x^m)^(n+1)/(n+1))+\[Integral](E^x+x^m)^(n+1) \[DifferentialD]x+m \[Integral]x^(m-1) (E^x+x^m)^n \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[x_^m_.*(E^x_+x_^m_.)^n_,x_Symbol] :=
  -(E^x+x^m)^(n+1)/(n+1) +
  Int[(E^x+x^m)^(n+1),x] +
  Dist[m,Int[x^(m-1)*(E^x+x^m)^n,x]] /;
RationalQ[{m,n}] && m>0 && NonzeroQ[n+1]
