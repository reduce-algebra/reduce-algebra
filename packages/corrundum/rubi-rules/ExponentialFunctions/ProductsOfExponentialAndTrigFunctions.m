(* ::Package:: *)

(* ::Title::Bold::Closed:: *)
(*\[Integral](f^(a+b x))^p Sin[c+d x]^n \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Reference: CRC 533, A&S 4.3.136*)


(* ::Subsubsection:: *)
(*Rule: If  d^2+b^2 p^2 Log[f]^2!=0, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral](f^(a+b x))^p Sin[c+d x]\[DifferentialD]x  \[LongRightArrow]  ((b p Log[f](f^(a+b x))^p Sin[c+d x])/(d^2+b^2 p^2 Log[f]^2))-(d (f^(a+b x))^p Cos[c+d x])/(d^2+b^2 p^2 Log[f]^2)*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[(f_^(a_.+b_.*x_))^p_.*Sin[c_.+d_.*x_],x_Symbol] :=
  b*p*Log[f]*(f^(a+b*x))^p*Sin[c+d*x]/(d^2+b^2*p^2*Log[f]^2) - 
  d*(f^(a+b*x))^p*Cos[c+d*x]/(d^2+b^2*p^2*Log[f]^2) /;
FreeQ[{a,b,c,d,f,p},x] && NonzeroQ[d^2+b^2*p^2*Log[f]^2]


(* ::Subsubsection:: *)
(*Reference: CRC 538, A&S 4.3.137*)


(* ::Code:: *)
Int[(f_^(a_.+b_.*x_))^p_.*Cos[c_.+d_.*x_],x_Symbol] :=
  b*p*Log[f]*(f^(a+b*x))^p*Cos[c+d*x]/(d^2+b^2*p^2*Log[f]^2) + 
  d*(f^(a+b*x))^p*Sin[c+d*x]/(d^2+b^2*p^2*Log[f]^2) /;
FreeQ[{a,b,c,d,f,p},x] && NonzeroQ[d^2+b^2*p^2*Log[f]^2]


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Reference: CRC 542, A&S 4.3.138*)


(* ::Subsubsection:: *)
(*Rule: If  d^2 n^2+b^2 p^2 Log[f]^2!=0 \[And] n>1, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral](f^(a+b x))^p Sin[c+d x]^n \[DifferentialD]x  \[LongRightArrow]  ((b p Log[f](f^(a+b x))^p Sin[c+d x]^n)/(d^2 n^2+b^2 p^2 Log[f]^2))-*)
(*(d n (f^(a+b x))^p Cos[c+d x] Sin[c+d x]^(n-1))/(d^2 n^2+b^2 p^2 Log[f]^2)+(n (n-1) d^2)/(d^2 n^2+b^2 p^2 Log[f]^2) \[Integral](f^(a+b x))^p Sin[c+d x]^(n-2) \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[(f_^(a_.+b_.*x_))^p_.*Sin[c_.+d_.*x_]^n_,x_Symbol] :=
  b*p*Log[f]*(f^(a+b*x))^p*Sin[c+d*x]^n/(d^2*n^2+b^2*p^2*Log[f]^2) - 
  d*n*(f^(a+b*x))^p*Cos[c+d*x]*Sin[c+d*x]^(n-1)/(d^2*n^2+b^2*p^2*Log[f]^2) + 
  Dist[(n*(n-1)*d^2)/(d^2*n^2+b^2*p^2*Log[f]^2),Int[(f^(a+b*x))^p*Sin[c+d*x]^(n-2),x]] /;
FreeQ[{a,b,c,d,f,p},x] && NonzeroQ[d^2*n^2+b^2*p^2*Log[f]^2] && RationalQ[n] && n>1


(* ::Subsubsection:: *)
(*Reference: CRC 543, A&S 4.3.139*)


(* ::Code:: *)
Int[(f_^(a_.+b_.*x_))^p_.*Cos[c_.+d_.*x_]^m_,x_Symbol] :=
  b*p*Log[f]*(f^(a+b*x))^p*Cos[c+d*x]^m/(d^2*m^2+b^2*p^2*Log[f]^2) + 
  d*m*(f^(a+b*x))^p*Sin[c+d*x]*Cos[c+d*x]^(m-1)/(d^2*m^2+b^2*p^2*Log[f]^2) + 
  Dist[(m*(m-1)*d^2)/(d^2*m^2+b^2*p^2*Log[f]^2),Int[(f^(a+b*x))^p*Cos[c+d*x]^(m-2),x]] /;
FreeQ[{a,b,c,d,f,p},x] && NonzeroQ[d^2*m^2+b^2*p^2*Log[f]^2] && RationalQ[m] && m>1


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Reference: CRC 551 when d^2 (n+2)^2+b^2 p^2 Log[f]^2=0*)


(* ::Subsubsection:: *)
(*Rule: If  d^2 (n+2)^2+b^2 p^2 Log[f]^2=0 \[And] n+1!=0 \[And] n+2!=0, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral](f^(a+b x))^p Sin[c+d x]^n \[DifferentialD]x  \[LongRightArrow]  -((b p Log[f](f^(a+b x))^p Sin[c+d x]^(n+2))/(d^2 (n+1) (n+2)))+((f^(a+b x))^p Cos[c+d x]Sin[c+d x]^(n+1))/(d (n+1))*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[(f_^(a_.+b_.*x_))^p_.*Sin[c_.+d_.*x_]^n_,x_Symbol] :=
  -b*p*Log[f]*(f^(a+b*x))^p*Sin[c+d*x]^(n+2)/(d^2*(n+1)*(n+2)) + 
  (f^(a+b*x))^p*Cos[c+d*x]*Sin[c+d*x]^(n+1)/(d*(n+1)) /;
FreeQ[{a,b,c,d,f,n,p},x] && ZeroQ[d^2*(n+2)^2+b^2*p^2*Log[f]^2] && NonzeroQ[n+1] && NonzeroQ[n+2]


(* ::Subsubsection:: *)
(*Reference: CRC 552 when d^2 (n+2)^2+b^2 p^2 Log[f]^2=0*)


(* ::Code:: *)
Int[(f_^(a_.+b_.*x_))^p_.*Cos[c_.+d_.*x_]^n_,x_Symbol] :=
  -b*p*Log[f]*(f^(a+b*x))^p*Cos[c+d*x]^(n+2)/(d^2*(n+1)*(n+2)) - 
  (f^(a+b*x))^p*Sin[c+d*x]*Cos[c+d*x]^(n+1)/(d*(n+1)) /;
FreeQ[{a,b,c,d,f,n,p},x] && ZeroQ[d^2*(n+2)^2+b^2*p^2*Log[f]^2] && NonzeroQ[n+1] && NonzeroQ[n+2]


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Reference: CRC 551, CRC 542 inverted*)


(* ::Subsubsection:: *)
(*Rule: If  d^2 (n+2)^2+b^2 p^2 Log[f]^2!=0 \[And] n<-1 \[And] n!=-2, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral](f^(a+b x))^p Sin[c+d x]^n \[DifferentialD]x  \[LongRightArrow]  -((b p Log[f](f^(a+b x))^p Sin[c+d x]^(n+2))/(d^2 (n+1) (n+2)))+*)
(*((f^(a+b x))^p Cos[c+d x]Sin[c+d x]^(n+1))/(d (n+1))+(d^2 (n+2)^2+b^2 p^2 Log[f]^2)/(d^2 (n+1) (n+2)) \[Integral](f^(a+b x))^p Sin[c+d x]^(n+2) \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[(f_^(a_.+b_.*x_))^p_.*Sin[c_.+d_.*x_]^n_,x_Symbol] :=
  -b*p*Log[f]*(f^(a+b*x))^p*Sin[c+d*x]^(n+2)/(d^2*(n+1)*(n+2)) + 
  (f^(a+b*x))^p*Cos[c+d*x]*Sin[c+d*x]^(n+1)/(d*(n+1)) + 
  Dist[(d^2*(n+2)^2+b^2*p^2*Log[f]^2)/(d^2*(n+1)*(n+2)),Int[(f^(a+b*x))^p*Sin[c+d*x]^(n+2),x]] /;
FreeQ[{a,b,c,d,f,p},x] && NonzeroQ[d^2*(n+2)^2+b^2*p^2*Log[f]^2] && RationalQ[n] && n<-1 && n!=-2


(* ::Subsubsection:: *)
(*Reference: CRC 552, CRC 543 inverted*)


(* ::Code:: *)
Int[(f_^(a_.+b_.*x_))^p_.*Cos[c_.+d_.*x_]^n_,x_Symbol] :=
  -b*p*Log[f]*(f^(a+b*x))^p*Cos[c+d*x]^(n+2)/(d^2*(n+1)*(n+2)) - 
  (f^(a+b*x))^p*Sin[c+d*x]*Cos[c+d*x]^(n+1)/(d*(n+1)) + 
  Dist[(d^2*(n+2)^2+b^2*p^2*Log[f]^2)/(d^2*(n+1)*(n+2)),Int[(f^(a+b*x))^p*Cos[c+d*x]^(n+2),x]] /;
FreeQ[{a,b,c,d,f,p},x] && NonzeroQ[d^2*(n+2)^2+b^2*p^2*Log[f]^2] && RationalQ[n] && n<-1 && n!=-2


(* ::PageBreak:: *)
(**)


(* ::Title::Bold::Closed:: *)
(*\[Integral](f^(a+b x))^p Sec[c+d x]^n \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Reference: CRC 552 with  b^2 p^2 Log[f]^2+d^2 (n-2)^2=0*)


(* ::Subsubsection:: *)
(*Rule: If  b^2 p^2 Log[f]^2+d^2 (n-2)^2=0 \[And] n-1!=0 \[And] n-2!=0, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral](f^(a+b x))^p Sec[c+d x]^n \[DifferentialD]x  \[LongRightArrow]  -((b p Log[f](f^(a+b x))^p Sec[c+d x]^(n-2))/(d^2 (n-1) (n-2)))+((f^(a+b x))^p Sec[c+d x]^(n-1) Sin[c+d x])/(d (n-1))*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[(f_^(a_.+b_.*x_))^p_.*Sec[c_.+d_.*x_]^n_,x_Symbol] :=
  -b*p*Log[f]*(f^(a+b*x))^p*Sec[c+d*x]^(n-2)/(d^2*(n-1)*(n-2)) + 
  (f^(a+b*x))^p*Sec[c+d*x]^(n-1)*Sin[c+d*x]/(d*(n-1)) /;
FreeQ[{a,b,c,d,f,p,n},x] && ZeroQ[b^2*p^2*Log[f]^2+d^2*(n-2)^2] && NonzeroQ[n-1] && NonzeroQ[n-2]


(* ::Subsubsection:: *)
(*Reference: CRC 551 with  b^2 p^2 Log[f]^2+d^2 (n-2)^2=0*)


(* ::Code:: *)
Int[(f_^(a_.+b_.*x_))^p_.*Csc[c_.+d_.*x_]^n_,x_Symbol] :=
  -b*p*Log[f]*(f^(a+b*x))^p*Csc[c+d*x]^(n-2)/(d^2*(n-1)*(n-2)) + 
  (f^(a+b*x))^p*Csc[c+d*x]^(n-1)*Cos[c+d*x]/(d*(n-1)) /;
FreeQ[{a,b,c,d,f,p,n},x] && ZeroQ[b^2*p^2*Log[f]^2+d^2*(n-2)^2] && NonzeroQ[n-1] && NonzeroQ[n-2]


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Reference: CRC 552*)


(* ::Subsubsection:: *)
(*Rule: If  b^2 p^2 Log[f]^2+d^2 (n-2)^2!=0 \[And] n>1 \[And] n!=2, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral](f^(a+b x))^p Sec[c+d x]^n \[DifferentialD]x  \[LongRightArrow]  -((b p Log[f](f^(a+b x))^p Sec[c+d x]^(n-2))/(d^2 (n-1) (n-2)))+*)
(*((f^(a+b x))^p Sec[c+d x]^(n-1) Sin[c+d x])/(d (n-1))+(b^2 p^2 Log[f]^2+d^2 (n-2)^2)/(d^2 (n-1) (n-2)) \[Integral](f^(a+b x))^p Sec[c+d x]^(n-2) \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[(f_^(a_.+b_.*x_))^p_.*Sec[c_.+d_.*x_]^n_,x_Symbol] :=
  -b*p*Log[f]*(f^(a+b*x))^p*Sec[c+d*x]^(n-2)/(d^2*(n-1)*(n-2)) + 
  (f^(a+b*x))^p*Sec[c+d*x]^(n-1)*Sin[c+d*x]/(d*(n-1)) + 
  Dist[(b^2*p^2*Log[f]^2+d^2*(n-2)^2)/(d^2*(n-1)*(n-2)),Int[(f^(a+b*x))^p*Sec[c+d*x]^(n-2),x]] /;
FreeQ[{a,b,c,d,f,p},x] && NonzeroQ[b^2*p^2*Log[f]^2+d^2*(n-2)^2] && RationalQ[n] && n>1 && n!=2


(* ::Subsubsection:: *)
(*Reference: CRC 551*)


(* ::Code:: *)
Int[(f_^(a_.+b_.*x_))^p_.*Csc[c_.+d_.*x_]^n_,x_Symbol] :=
  -b*p*Log[f]*(f^(a+b*x))^p*Csc[c+d*x]^(n-2)/(d^2*(n-1)*(n-2)) - 
  (f^(a+b*x))^p*Csc[c+d*x]^(n-1)*Cos[c+d*x]/(d*(n-1)) + 
  Dist[(b^2*p^2*Log[f]^2+d^2*(n-2)^2)/(d^2*(n-1)*(n-2)),Int[(f^(a+b*x))^p*Csc[c+d*x]^(n-2),x]] /;
FreeQ[{a,b,c,d,f,p},x] && NonzeroQ[b^2*p^2*Log[f]^2+d^2*(n-2)^2] && RationalQ[n] && n>1 && n!=2


(* ::PageBreak:: *)
(**)


(* ::Title::Bold::Closed:: *)
(*\[Integral]x^m (f^(a+b x))^p Sin[c+d x]^n \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Derivation: Integration by parts*)


(* ::Subsubsection:: *)
(*Note: Each term of the sum  x^(m-1) u will be similar in form to the original integrand, but the degree of the monomial will be smaller by one. *)


(* ::Subsubsection:: *)
(*Rule: If  m>0 \[And] n\[Element]\[DoubleStruckCapitalZ] \[And] n>0, let  u=\[Integral](f^(a+b x))^p Sin[c+d x]\[DifferentialD]x, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]x^m (f^(a+b x))^p Sin[c+d x]^n \[DifferentialD]x  \[LongRightArrow]  x^mu-m \[Integral]x^(m-1) u \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[x_^m_.*(f_^(a_.+b_.*x_))^p_.*Sin[c_.+d_.*x_]^n_.,x_Symbol] :=
  Module[{u=Block[{ShowSteps=False,StepCounter=Null}, Int[(f^(a+b*x))^p*Sin[c+d*x]^n,x]]},
  x^m*u - Dist[m,Int[x^(m-1)*u,x]]] /;
FreeQ[{a,b,c,d,f,p},x] && RationalQ[m] && m>0 && IntegerQ[n] && n>0


(* ::Code:: *)
Int[x_^m_.*(f_^(a_.+b_.*x_))^p_.*Cos[c_.+d_.*x_]^n_.,x_Symbol] :=
  Module[{u=Block[{ShowSteps=False,StepCounter=Null}, Int[(f^(a+b*x))^p*Cos[c+d*x]^n,x]]},
  x^m*u - Dist[m,Int[x^(m-1)*u,x]]] /;
FreeQ[{a,b,c,d,f,p},x] && RationalQ[m] && m>0 && IntegerQ[n] && n>0


(* ::PageBreak:: *)
(**)


(* ::Title::Bold::Closed:: *)
(*\[Integral]f^v Sin[w]^n \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Derivation: Algebraic expansion*)


(* ::Subsubsection:: *)
(*Basis: Sin[z]=I/(2E^(I z))-(I E^(I z))/2 *)


(* ::Subsubsection:: *)
(*Rule: If  v and w are quadratic polynomials in x, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]f^v Sin[w]\[DifferentialD]x  \[LongRightArrow]  (I/2)\[Integral]f^v/E^(I w) \[DifferentialD]x-I/2 \[Integral]f^v E^(I w) \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[f_^v_*Sin[w_],x_Symbol] :=
  Dist[I/2,Int[f^v/E^(I*w),x]] - 
  Dist[I/2,Int[f^v*E^(I*w),x]] /;
FreeQ[f,x] && PolynomialQ[v,x] && Exponent[v,x]<=2 && PolynomialQ[w,x] && Exponent[w,x]<=2


(* ::Subsubsection:: *)
(*Basis: Cos[z]=E^(I z)/2+1/(2E^(I z)) *)


(* ::Code:: *)
Int[f_^v_*Cos[w_],x_Symbol] :=
  Dist[1/2,Int[f^v*E^(I*w),x]] + 
  Dist[1/2,Int[f^v/E^(I*w),x]] /;
FreeQ[f,x] && PolynomialQ[v,x] && Exponent[v,x]<=2 && PolynomialQ[w,x] && Exponent[w,x]<=2


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Derivation: Algebraic expansion*)


(* ::Subsubsection:: *)
(*Basis: Sin[z]=I/2 (1/E^(I z)-E^(I z)) *)


(* ::Subsubsection:: *)
(*Rule: If  n\[Element]\[DoubleStruckCapitalZ] \[And] n>0 \[And] v and w are quadratic polynomials in x, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]f^v Sin[w]^n \[DifferentialD]x  \[LongRightArrow]  (I/2)^n\[Integral]f^v (1/E^(I w)-E^(I w))^n \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[f_^v_*Sin[w_]^n_,x_Symbol] :=
  Dist[(I/2)^n,Int[f^v*(1/E^(I*w)-E^(I*w))^n,x]] /;
FreeQ[f,x] && IntegerQ[n] && n>0 && PolynomialQ[v,x] && Exponent[v,x]<=2 && 
  PolynomialQ[w,x] && Exponent[w,x]<=2


(* ::Subsubsection:: *)
(*Basis: Cos[z]=1/2 (E^(I z)+1/E^(I z)) *)


(* ::Code:: *)
Int[f_^v_*Cos[w_]^n_,x_Symbol] :=
  Dist[1/2^n,Int[f^v*(E^(I*w)+1/E^(I*w))^n,x]] /;
FreeQ[f,x] && IntegerQ[n] && n>0 && PolynomialQ[v,x] && Exponent[v,x]<=2 && 
  PolynomialQ[w,x] && Exponent[w,x]<=2


(* ::PageBreak:: *)
(**)
