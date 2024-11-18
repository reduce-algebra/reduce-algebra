(* ::Package:: *)

(* ::Title::Bold::Closed:: *)
(*\[Integral](f^(a+b x))^p Sinh[c+d x]^n \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Reference: CRC 533h*)


(* ::Subsubsection:: *)
(*Rule: If  d^2-b^2 p^2 Log[f]^2!=0, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral](f^(a+b x))^p Sinh[c+d x]\[DifferentialD]x  \[LongRightArrow]  *)
(*-((b p Log[f](f^(a+b x))^p Sinh[c+d x])/(d^2-b^2 p^2 Log[f]^2))+(d (f^(a+b x))^p Cosh[c+d x])/(d^2-b^2 p^2 Log[f]^2)*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[(f_^(a_.+b_.*x_))^p_.*Sinh[c_.+d_.*x_],x_Symbol] :=
  -b*p*Log[f]*(f^(a+b*x))^p*Sinh[c+d*x]/(d^2-b^2*p^2*Log[f]^2) + 
  d*(f^(a+b*x))^p*Cosh[c+d*x]/(d^2-b^2*p^2*Log[f]^2) /;
FreeQ[{a,b,c,d,f,p},x] && NonzeroQ[d^2-b^2*p^2*Log[f]^2]


(* ::Subsubsection:: *)
(*Reference: CRC 538h*)


(* ::Code:: *)
Int[(f_^(a_.+b_.*x_))^p_.*Cosh[c_.+d_.*x_],x_Symbol] :=
  -b*p*Log[f]*(f^(a+b*x))^p*Cosh[c+d*x]/(d^2-b^2*p^2*Log[f]^2) + 
  d*(f^(a+b*x))^p*Sinh[c+d*x]/(d^2-b^2*p^2*Log[f]^2) /;
FreeQ[{a,b,c,d,f,p},x] && NonzeroQ[d^2-b^2*p^2*Log[f]^2]


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Reference: CRC 542h*)


(* ::Subsubsection:: *)
(*Rule: If  d^2 n^2-b^2 p^2 Log[f]^2!=0 \[And] n>1, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral](f^(a+b x))^p Sinh[c+d x]^n \[DifferentialD]x  \[LongRightArrow]  -((b p Log[f](f^(a+b x))^p Sinh[c+d x]^n)/(d^2 n^2-b^2 p^2 Log[f]^2))+*)
(*(d n (f^(a+b x))^p Cosh[c+d x] Sinh[c+d x]^(n-1))/(d^2 n^2-b^2 p^2 Log[f]^2)-(n (n-1) d^2)/(d^2 n^2-b^2 p^2 Log[f]^2) \[Integral](f^(a+b x))^p Sinh[c+d x]^(n-2) \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[(f_^(a_.+b_.*x_))^p_.*Sinh[c_.+d_.*x_]^n_,x_Symbol] :=
  -b*p*Log[f]*(f^(a+b*x))^p*Sinh[c+d*x]^n/(d^2*n^2-b^2*p^2*Log[f]^2) + 
  d*n*(f^(a+b*x))^p*Cosh[c+d*x]*Sinh[c+d*x]^(n-1)/(d^2*n^2-b^2*p^2*Log[f]^2) - 
  Dist[n*(n-1)*d^2/(d^2*n^2-b^2*p^2*Log[f]^2),Int[(f^(a+b*x))^p*Sinh[c+d*x]^(n-2),x]] /;
FreeQ[{a,b,c,d,f,p},x] && NonzeroQ[d^2*n^2-b^2*p^2*Log[f]^2] && RationalQ[n] && n>1


(* ::Subsubsection:: *)
(*Reference: CRC 543h*)


(* ::Code:: *)
Int[(f_^(a_.+b_.*x_))^p_.*Cosh[c_.+d_.*x_]^n_,x_Symbol] :=
  -b*p*Log[f]*(f^(a+b*x))^p*Cosh[c+d*x]^n/(d^2*n^2-b^2*p^2*Log[f]^2) + 
  d*n*(f^(a+b*x))^p*Sinh[c+d*x]*Cosh[c+d*x]^(n-1)/(d^2*n^2-b^2*p^2*Log[f]^2) + 
  Dist[n*(n-1)*d^2/(d^2*n^2-b^2*p^2*Log[f]^2),Int[(f^(a+b*x))^p*Cosh[c+d*x]^(n-2),x]] /;
FreeQ[{a,b,c,d,f,p},x] && NonzeroQ[d^2*n^2-b^2*p^2*Log[f]^2] && RationalQ[n] && n>1


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Reference: CRC 551h when d^2 (n+2)^2-b^2 p^2 Log[f]^2=0*)


(* ::Subsubsection:: *)
(*Rule: If  d^2 (n+2)^2-b^2 p^2 Log[f]^2=0 \[And] n+1!=0 \[And] n+2!=0, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral](f^(a+b x))^p Sinh[c+d x]^n \[DifferentialD]x  \[LongRightArrow]  *)
(*-((b p Log[f](f^(a+b x))^p Sinh[c+d x]^(n+2))/(d^2 (n+1) (n+2)))+((f^(a+b x))^p Cosh[c+d x]Sinh[c+d x]^(n+1))/(d (n+1))*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[(f_^(a_.+b_.*x_))^p_.*Sinh[c_.+d_.*x_]^n_,x_Symbol] :=
  -b*p*Log[f]*(f^(a+b*x))^p*Sinh[c+d*x]^(n+2)/(d^2*(n+1)*(n+2)) + 
  (f^(a+b*x))^p*Cosh[c+d*x]*Sinh[c+d*x]^(n+1)/(d*(n+1)) /;
FreeQ[{a,b,c,d,f,n,p},x] && ZeroQ[d^2*(n+2)^2-b^2*p^2*Log[f]^2] && NonzeroQ[n+1] && NonzeroQ[n+2]


(* ::Subsubsection:: *)
(*Reference: CRC 552h when d^2 (n+2)^2-b^2 p^2 Log[f]^2=0*)


(* ::Code:: *)
Int[(f_^(a_.+b_.*x_))^p_.*Cosh[c_.+d_.*x_]^n_,x_Symbol] :=
  b*p*Log[f]*(f^(a+b*x))^p*Cosh[c+d*x]^(n+2)/(d^2*(n+1)*(n+2)) - 
  (f^(a+b*x))^p*Sinh[c+d*x]*Cosh[c+d*x]^(n+1)/(d*(n+1)) /;
FreeQ[{a,b,c,d,f,n,p},x] && ZeroQ[d^2*(n+2)^2-b^2*p^2*Log[f]^2] && NonzeroQ[n+1] && NonzeroQ[n+2]


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Reference: CRC 551h, CRC 542h inverted*)


(* ::Subsubsection:: *)
(*Rule: If  d^2 (n+2)^2-b^2 p^2 Log[f]^2!=0 \[And] n<-1 \[And] n!=-2, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral](f^(a+b x))^p Sinh[c+d x]^n \[DifferentialD]x  \[LongRightArrow]  -((b p Log[f](f^(a+b x))^p Sinh[c+d x]^(n+2))/(d^2 (n+1) (n+2)))+*)
(*((f^(a+b x))^p Cosh[c+d x]Sinh[c+d x]^(n+1))/(d (n+1))-(d^2 (n+2)^2-b^2 p^2 Log[f]^2)/(d^2 (n+1) (n+2)) \[Integral](f^(a+b x))^p Sinh[c+d x]^(n+2) \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[(f_^(a_.+b_.*x_))^p_.*Sinh[c_.+d_.*x_]^n_,x_Symbol] :=
  -b*p*Log[f]*(f^(a+b*x))^p*Sinh[c+d*x]^(n+2)/(d^2*(n+1)*(n+2)) + 
  (f^(a+b*x))^p*Cosh[c+d*x]*Sinh[c+d*x]^(n+1)/(d*(n+1)) - 
  Dist[(d^2*(n+2)^2-b^2*p^2*Log[f]^2)/(d^2*(n+1)*(n+2)),Int[(f^(a+b*x))^p*Sinh[c+d*x]^(n+2),x]] /;
FreeQ[{a,b,c,d,f,p},x] && NonzeroQ[d^2*(n+2)^2-b^2*p^2*Log[f]^2] && RationalQ[n] && n<-1 && n!=-2


(* ::Subsubsection:: *)
(*Reference: CRC 552h, CRC 543h inverted*)


(* ::Code:: *)
Int[(f_^(a_.+b_.*x_))^p_.*Cosh[c_.+d_.*x_]^n_,x_Symbol] :=
  b*p*Log[f]*(f^(a+b*x))^p*Cosh[c+d*x]^(n+2)/(d^2*(n+1)*(n+2)) - 
  (f^(a+b*x))^p*Sinh[c+d*x]*Cosh[c+d*x]^(n+1)/(d*(n+1)) + 
  Dist[(d^2*(n+2)^2-b^2*p^2*Log[f]^2)/(d^2*(n+1)*(n+2)),Int[(f^(a+b*x))^p*Cosh[c+d*x]^(n+2),x]] /;
FreeQ[{a,b,c,d,f,p},x] && NonzeroQ[d^2*(n+2)^2-b^2*p^2*Log[f]^2] && RationalQ[n] && n<-1 && n!=-2


(* ::PageBreak:: *)
(**)


(* ::Title::Bold::Closed:: *)
(*\[Integral](f^(a+b x))^p Sech[c+d x]^n \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Reference: CRC 552h with  b^2 p^2 Log[f]^2-d^2 (n-2)^2=0*)


(* ::Subsubsection:: *)
(*Rule: If  b^2 p^2 Log[f]^2-d^2 (n-2)^2=0 \[And] n-1!=0 \[And] n-2!=0, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral](f^(a+b x))^p Sech[c+d x]^n \[DifferentialD]x  \[LongRightArrow]  *)
(*((b p Log[f](f^(a+b x))^p Sech[c+d x]^(n-2))/(d^2 (n-1) (n-2)))+((f^(a+b x))^p Sech[c+d x]^(n-1) Sinh[c+d x])/(d (n-1))*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[(f_^(a_.+b_.*x_))^p_.*Sech[c_.+d_.*x_]^n_,x_Symbol] :=
  b*p*Log[f]*(f^(a+b*x))^p*Sech[c+d*x]^(n-2)/(d^2*(n-1)*(n-2)) + 
  (f^(a+b*x))^p*Sech[c+d*x]^(n-1)*Sinh[c+d*x]/(d*(n-1)) /;
FreeQ[{a,b,c,d,f,p,n},x] && ZeroQ[b^2*p^2*Log[f]^2-d^2*(n-2)^2] && NonzeroQ[n-1] && NonzeroQ[n-2]


(* ::Subsubsection:: *)
(*Reference: CRC 551h with  b^2 p^2 Log[f]^2-d^2 (n-2)^2=0*)


(* ::Code:: *)
Int[(f_^(a_.+b_.*x_))^p_.*Csch[c_.+d_.*x_]^n_,x_Symbol] :=
  -b*p*Log[f]*(f^(a+b*x))^p*Csch[c+d*x]^(n-2)/(d^2*(n-1)*(n-2)) - 
  (f^(a+b*x))^p*Csch[c+d*x]^(n-1)*Cosh[c+d*x]/(d*(n-1)) /;
FreeQ[{a,b,c,d,f,p,n},x] && ZeroQ[b^2*p^2*Log[f]^2-d^2*(n-2)^2] && NonzeroQ[n-1] && NonzeroQ[n-2]


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Reference: CRC 552h*)


(* ::Subsubsection:: *)
(*Rule: If  b^2 p^2 Log[f]^2-d^2 (n-2)^2!=0 \[And] n>1 \[And] n!=2, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral](f^(a+b x))^p Sech[c+d x]^n \[DifferentialD]x  \[LongRightArrow]  ((b p Log[f](f^(a+b x))^p Sech[c+d x]^(n-2))/(d^2 (n-1) (n-2)))+*)
(*((f^(a+b x))^p Sech[c+d x]^(n-1) Sinh[c+d x])/(d (n-1))-(b^2 p^2 Log[f]^2-d^2 (n-2)^2)/(d^2 (n-1) (n-2)) \[Integral](f^(a+b x))^p Sech[c+d x]^(n-2) \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[(f_^(a_.+b_.*x_))^p_.*Sech[c_.+d_.*x_]^n_,x_Symbol] :=
  b*p*Log[f]*(f^(a+b*x))^p*Sech[c+d*x]^(n-2)/(d^2*(n-1)*(n-2)) + 
  (f^(a+b*x))^p*Sech[c+d*x]^(n-1)*Sinh[c+d*x]/(d*(n-1)) -
  Dist[(b^2*p^2*Log[f]^2-d^2*(n-2)^2)/(d^2*(n-1)*(n-2)),
    Int[(f^(a+b*x))^p*Sech[c+d*x]^(n-2),x]] /;
FreeQ[{a,b,c,d,f,p},x] && NonzeroQ[b^2*p^2*Log[f]^2-d^2*(n-2)^2] && 
  RationalQ[n] && n>1 && n!=2


(* ::Subsubsection:: *)
(*Reference: CRC 551h*)


(* ::Code:: *)
Int[(f_^(a_.+b_.*x_))^p_.*Csch[c_.+d_.*x_]^n_,x_Symbol] :=
  -b*p*Log[f]*(f^(a+b*x))^p*Csch[c+d*x]^(n-2)/(d^2*(n-1)*(n-2)) - 
  (f^(a+b*x))^p*Csch[c+d*x]^(n-1)*Cosh[c+d*x]/(d*(n-1)) +
  Dist[(b^2*p^2*Log[f]^2-d^2*(n-2)^2)/(d^2*(n-1)*(n-2)),
    Int[(f^(a+b*x))^p*Csch[c+d*x]^(n-2),x]] /;
FreeQ[{a,b,c,d,f,p},x] && NonzeroQ[b^2*p^2*Log[f]^2-d^2*(n-2)^2] && 
  RationalQ[n] && n>1 && n!=2


(* ::PageBreak:: *)
(**)


(* ::Title::Bold::Closed:: *)
(*\[Integral]x^m (f^(a+b x))^p Sinh[c+d x]^n \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Derivation: Integration by parts*)


(* ::Subsubsection:: *)
(*Note: Each term of the sum  x^(m-1) u will be similar in form to the original integrand, but the degree of the monomial will be smaller by one. *)


(* ::Subsubsection:: *)
(*Rule: If  m>0 \[And] n\[Element]\[DoubleStruckCapitalZ] \[And] n>0, let  u=\[Integral](f^(a+b x))^p Sinh[c+d x]\[DifferentialD]x, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]x^m (f^(a+b x))^p Sinh[c+d x]^n \[DifferentialD]x  \[LongRightArrow]  x^mu-m \[Integral]x^(m-1) u \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[x_^m_.*(f_^(a_.+b_.*x_))^p_.*Sinh[c_.+d_.*x_]^n_.,x_Symbol] :=
  Module[{u=Block[{ShowSteps=False,StepCounter=Null}, Int[(f^(a+b*x))^p*Sinh[c+d*x]^n,x]]},
  x^m*u - Dist[m,Int[x^(m-1)*u,x]]] /;
FreeQ[{a,b,c,d,f,p},x] && RationalQ[m] && m>0 && IntegerQ[n] && n>0


(* ::Code:: *)
Int[x_^m_.*(f_^(a_.+b_.*x_))^p_.*Cosh[c_.+d_.*x_]^n_.,x_Symbol] :=
  Module[{u=Block[{ShowSteps=False,StepCounter=Null}, Int[(f^(a+b*x))^p*Cosh[c+d*x]^n,x]]},
  x^m*u - Dist[m,Int[x^(m-1)*u,x]]] /;
FreeQ[{a,b,c,d,f,p},x] && RationalQ[m] && m>0 && IntegerQ[n] && n>0


(* ::PageBreak:: *)
(**)


(* ::Title::Bold::Closed:: *)
(*\[Integral]f^v Sinh[w]^n \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Derivation: Algebraic expansion*)


(* ::Subsubsection:: *)
(*Basis: Sinh[z]=E^z/2-1/(2E^z) *)


(* ::Subsubsection:: *)
(*Rule: If  v and w are quadratic polynomials in x, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]f^v Sinh[w]\[DifferentialD]x  \[LongRightArrow]  (1/2)\[Integral]f^v E^w \[DifferentialD]x-1/2 \[Integral]f^v/E^w \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[f_^v_*Sinh[w_],x_Symbol] :=
  Dist[1/2,Int[f^v*E^w,x]] - 
  Dist[1/2,Int[f^v/E^w,x]] /;
FreeQ[f,x] && PolynomialQ[v,x] && Exponent[v,x]<=2 && PolynomialQ[w,x] && Exponent[w,x]<=2


(* ::Subsubsection:: *)
(*Basis: Cosh[z]=E^z/2+1/(2E^z) *)


(* ::Code:: *)
Int[f_^v_*Cosh[w_],x_Symbol] :=
  Dist[1/2,Int[f^v*E^w,x]] + 
  Dist[1/2,Int[f^v/E^w,x]] /;
FreeQ[f,x] && PolynomialQ[v,x] && Exponent[v,x]<=2 && PolynomialQ[w,x] && Exponent[w,x]<=2


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Derivation: Algebraic expansion*)


(* ::Subsubsection:: *)
(*Basis: Sinh[z]=1/2 (E^z-1/E^z) *)


(* ::Subsubsection:: *)
(*Rule: If  n\[Element]\[DoubleStruckCapitalZ] \[And] n>0 \[And] v and w are quadratic polynomials in x, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]f^v Sinh[w]^n \[DifferentialD]x  \[LongRightArrow]  (1/2^n)\[Integral]f^v (E^w-1/E^w)^n \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[f_^v_*Sinh[w_]^n_,x_Symbol] :=
  Dist[1/2^n,Int[f^v*(E^w-1/E^w)^n,x]] /;
FreeQ[f,x] && IntegerQ[n] && n>0 && PolynomialQ[v,x] && Exponent[v,x]<=2 && 
  PolynomialQ[w,x] && Exponent[w,x]<=2


(* ::Subsubsection:: *)
(*Basis: Cosh[z]=1/2 (E^z+1/E^z) *)


(* ::Code:: *)
Int[f_^v_*Cosh[w_]^n_,x_Symbol] :=
  Dist[1/2^n,Int[f^v*(E^w+1/E^w)^n,x]] /;
FreeQ[f,x] && IntegerQ[n] && n>0 && PolynomialQ[v,x] && Exponent[v,x]<=2 && 
  PolynomialQ[w,x] && Exponent[w,x]<=2


(* ::PageBreak:: *)
(**)
