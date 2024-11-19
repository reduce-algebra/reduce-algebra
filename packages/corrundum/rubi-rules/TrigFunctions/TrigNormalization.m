(* ::Package:: *)

(* ::Title::Plain::Closed:: *)
(* Integration Rules for *)
(*\[Integral](sin^j(z))^m (A (sin^k(z))^p+\!\(TraditionalForm\`B\ *)
(*\*SuperscriptBox[\(( *)
(*\*SuperscriptBox[\(sin\), \(k\)](z))\), \(p + 1\)]\)+C (sin^k(z))^(p+2))\[DifferentialD]z when j^2=1\[And]k^2=1*)


(* ::Subsubtitle::Bold::Closed:: *)
(*\[Integral](sin[c+d x]^j)^m (A (sin[c+d x]^k)^p+B (sin[c+d x]^k)^(p+1))\[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Derivation: Algebraic normalization*)


(* ::Subsubsection:: *)
(*Rule: If  j^2=k^2=1 \[And] (j=k \[Or] p\[Element]\[DoubleStruckCapitalZ]) \[And] p!=1 \[And] p!=-2, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral](sin[c+d x]^j)^m (A (sin[c+d x]^k)^p+B (sin[c+d x]^k)^(p+1))\[DifferentialD]x  \[LongRightArrow]*)
(*\[Integral](sin[c+d x]^j)^(m+j k p) (A+B sin[c+d x]^k)\[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[(sin[c_.+d_.*x_]^j_.)^m_.*(A_.*(sin[c_.+d_.*x_]^k_.)^p_+B_.*(sin[c_.+d_.*x_]^k_.)^q_),x_Symbol] :=
  Int[(sin[c+d*x]^j)^(m+j*k*p)*(A+B*sin[c+d*x]^k),x] /;
FreeQ[{c,d,A,B,m,p},x] && ZeroQ[j^2-1] && ZeroQ[k^2-1] && ZeroQ[p+1-q] && 
  (ZeroQ[j-k] || IntegerQ[p]) && p!=-2


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Derivation: Algebraic normalization*)


(* ::Subsubsection:: *)
(*Rule: If  k^2=1 \[And] m\[Element]\[DoubleStruckCapitalZ] \[And] p\[NotElement]\[DoubleStruckCapitalZ], then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral](sin[c+d x]^-k)^m (A (sin[c+d x]^k)^p+B (sin[c+d x]^k)^(p+1))\[DifferentialD]x  \[LongRightArrow]*)
(*\[Integral](sin[c+d x]^k)^(p-m) (A+B sin[c+d x]^k)\[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[(sin[c_.+d_.*x_]^j_.)^m_.*(A_.*(sin[c_.+d_.*x_]^k_.)^p_+B_.*(sin[c_.+d_.*x_]^k_.)^q_),x_Symbol] :=
  Int[(sin[c+d*x]^k)^(p-m)*(A+B*sin[c+d*x]^k),x] /;
FreeQ[{c,d,A,B,m,p},x] && ZeroQ[k^2-1] && ZeroQ[j+k] && ZeroQ[p+1-q] && IntegerQ[m] && 
  Not[IntegerQ[p]]


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Derivation: Piecewise constant extraction and algebraic normalization*)


(* ::Subsubsection:: *)
(*Basis: \!\( *)
(*\*SubscriptBox[\(\[PartialD]\), \(z\)]\(( *)
(*\*SqrtBox[\(Sec[z]\)] *)
(*\*SqrtBox[\(Cos[z]\)])\)\)=0*)


(* ::Subsubsection:: *)
(*Rule: If  k^2=1 \[And] m-1/2\[Element]\[DoubleStruckCapitalZ] \[And] p\[NotElement]\[DoubleStruckCapitalZ], then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral](sin[c+d x]^-k)^m (A (sin[c+d x]^k)^p+B (sin[c+d x]^k)^(p+1))\[DifferentialD]x  \[LongRightArrow]*)
(*Sqrt[Csc[c+d x]] Sqrt[Sin[c+d x]]\[Integral](sin[c+d x]^k)^(p-m) (A+B sin[c+d x]^k)\[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[(sin[c_.+d_.*x_]^j_.)^m_.*(A_.*(sin[c_.+d_.*x_]^k_.)^p_+B_.*(sin[c_.+d_.*x_]^k_.)^q_),x_Symbol] :=
  Dist[Sqrt[Csc[c+d*x]]*Sqrt[Sin[c+d*x]],
    Int[(sin[c+d*x]^k)^(p-m)*(A+B*sin[c+d*x]^k),x]] /;
FreeQ[{c,d,A,B,m,p},x] && ZeroQ[k^2-1] && ZeroQ[j+k] && ZeroQ[p+1-q] && IntegerQ[m-1/2] && 
  Not[IntegerQ[p]]


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Derivation: Piecewise constant extraction and algebraic normalization*)


(* ::Subsubsection:: *)
(*Basis: \!\( *)
(*\*SubscriptBox[\(\[PartialD]\), \(z\)]\(( *)
(*\*SqrtBox[\(Sec[z]\)] *)
(*\*SqrtBox[\(Cos[z]\)])\)\)=0*)


(* ::Subsubsection:: *)
(*Rule: If  k^2=1 \[And] p-1/2\[Element]\[DoubleStruckCapitalZ] \[And] 2m\[NotElement]\[DoubleStruckCapitalZ], then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral](sin[c+d x]^-k)^m (A (sin[c+d x]^k)^p+B (sin[c+d x]^k)^(p+1))\[DifferentialD]x  \[LongRightArrow]*)
(*Sqrt[Csc[c+d x]] Sqrt[Sin[c+d x]]\[Integral](sin[c+d x]^-k)^(m-p) (A+B sin[c+d x]^k)\[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[(sin[c_.+d_.*x_]^j_.)^m_.*(A_.*(sin[c_.+d_.*x_]^k_.)^p_+B_.*(sin[c_.+d_.*x_]^k_.)^q_),x_Symbol] :=
  Dist[Sqrt[Csc[c+d*x]]*Sqrt[Sin[c+d*x]],
    Int[(sin[c+d*x]^j)^(m-p)*(A+B*sin[c+d*x]^k),x]] /;
FreeQ[{c,d,A,B,m,p},x] && ZeroQ[k^2-1] && ZeroQ[j+k] && ZeroQ[p+1-q] && IntegerQ[p-1/2] && 
  Not[IntegerQ[2*m]]


(* ::PageBreak:: *)
(**)


(* ::Subsubtitle::Bold::Closed:: *)
(*\[Integral](sin[c+d x]^j)^m (A (sin[c+d x]^k)^p+C (sin[c+d x]^k)^(p+2))\[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Derivation: Algebraic normalization*)


(* ::Subsubsection:: *)
(*Rule: If  j^2=k^2=1 \[And] (j=k \[Or] p\[Element]\[DoubleStruckCapitalZ]), then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral](sin[c+d x]^j)^m (A (sin[c+d x]^k)^p+C (sin[c+d x]^k)^(p+2))\[DifferentialD]x  \[LongRightArrow]*)
(*\[Integral](sin[c+d x]^j)^(m+j k p) (A+C sin[c+d x]^(2k))\[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[(sin[c_.+d_.*x_]^j_.)^m_.*(A_.*(sin[c_.+d_.*x_]^k_.)^p_.+C_.*(sin[c_.+d_.*x_]^k_.)^r_),x_Symbol] :=
  Int[(sin[c+d*x]^j)^(m+j*k*p)*(A+C*sin[c+d*x]^(2*k)),x] /;
FreeQ[{c,d,A,C,m,p},x] && ZeroQ[j^2-1] && ZeroQ[k^2-1] && ZeroQ[p+2-r] && 
  (ZeroQ[j-k] || IntegerQ[p])


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Derivation: Algebraic normalization*)


(* ::Subsubsection:: *)
(*Rule: If  k^2=1 \[And] m\[Element]\[DoubleStruckCapitalZ] \[And] p\[NotElement]\[DoubleStruckCapitalZ], then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral](sin[c+d x]^-k)^m (A (sin[c+d x]^k)^p+C (sin[c+d x]^k)^(p+2))\[DifferentialD]x  \[LongRightArrow]*)
(*\[Integral](sin[c+d x]^k)^(p-m) (A+C sin[c+d x]^(2k))\[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[(sin[c_.+d_.*x_]^j_.)^m_.*(A_.*(sin[c_.+d_.*x_]^k_.)^p_+C_.*(sin[c_.+d_.*x_]^k_.)^r_),x_Symbol] :=
  Int[(sin[c+d*x]^k)^(p-m)*(A+C*sin[c+d*x]^(2*k)),x] /;
FreeQ[{c,d,A,C,m,p},x] && ZeroQ[k^2-1] && ZeroQ[j+k] && ZeroQ[p+2-r] && IntegerQ[m] && 
  Not[IntegerQ[p]]


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Derivation: Piecewise constant extraction and algebraic normalization*)


(* ::Subsubsection:: *)
(*Basis: \!\( *)
(*\*SubscriptBox[\(\[PartialD]\), \(z\)]\(( *)
(*\*SqrtBox[\(Sec[z]\)] *)
(*\*SqrtBox[\(Cos[z]\)])\)\)=0*)


(* ::Subsubsection:: *)
(*Rule: If  k^2=1 \[And] m-1/2\[Element]\[DoubleStruckCapitalZ] \[And] p\[NotElement]\[DoubleStruckCapitalZ], then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral](sin[c+d x]^-k)^m (A (sin[c+d x]^k)^p+C (sin[c+d x]^k)^(p+2))\[DifferentialD]x  \[LongRightArrow]*)
(*Sqrt[Csc[c+d x]] Sqrt[Sin[c+d x]]\[Integral](sin[c+d x]^k)^(p-m) (A+C sin[c+d x]^(2k))\[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[(sin[c_.+d_.*x_]^j_.)^m_.*(A_.*(sin[c_.+d_.*x_]^k_.)^p_+C_.*(sin[c_.+d_.*x_]^k_.)^r_),x_Symbol] :=
  Dist[Sqrt[Csc[c+d*x]]*Sqrt[Sin[c+d*x]],
    Int[(sin[c+d*x]^k)^(p-m)*(A+C*sin[c+d*x]^(2*k)),x]] /;
FreeQ[{c,d,A,C,m,p},x] && ZeroQ[k^2-1] && ZeroQ[j+k] && ZeroQ[p+2-r] && IntegerQ[m-1/2] && 
  Not[IntegerQ[p]]


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Derivation: Piecewise constant extraction and algebraic normalization*)


(* ::Subsubsection:: *)
(*Basis: \!\( *)
(*\*SubscriptBox[\(\[PartialD]\), \(z\)]\(( *)
(*\*SqrtBox[\(Sec[z]\)] *)
(*\*SqrtBox[\(Cos[z]\)])\)\)=0*)


(* ::Subsubsection:: *)
(*Rule: If  k^2=1 \[And] p-1/2\[Element]\[DoubleStruckCapitalZ] \[And] 2m\[NotElement]\[DoubleStruckCapitalZ], then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral](sin[c+d x]^-k)^m (A (sin[c+d x]^k)^p+C (sin[c+d x]^k)^(p+2))\[DifferentialD]x  \[LongRightArrow]*)
(*Sqrt[Csc[c+d x]] Sqrt[Sin[c+d x]]\[Integral](sin[c+d x]^-k)^(m-p) (A+C sin[c+d x]^(2k))\[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[(sin[c_.+d_.*x_]^j_.)^m_.*(A_.*(sin[c_.+d_.*x_]^k_.)^p_+C_.*(sin[c_.+d_.*x_]^k_.)^r_),x_Symbol] :=
  Dist[Sqrt[Csc[c+d*x]]*Sqrt[Sin[c+d*x]],
    Int[(sin[c+d*x]^j)^(m-p)*(A+C*sin[c+d*x]^(2*k)),x]] /;
FreeQ[{c,d,A,C,m,p},x] && ZeroQ[k^2-1] && ZeroQ[j+k] && ZeroQ[p+2-r] && IntegerQ[p-1/2] && 
  Not[IntegerQ[2*m]]


(* ::PageBreak:: *)
(**)


(* ::Subsubtitle::Bold::Closed:: *)
(*\[Integral](sin[c+d x]^j)^m (A+B sin[c+d x]+C sin[c+d x]^-1)\[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Derivation: Algebraic normalization*)


(* ::Subsubsection:: *)
(*Rule: If  j^2=1, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral](sin[c+d x]^j)^m (A+B sin[c+d x]+C sin[c+d x]^-1)\[DifferentialD]x  \[LongRightArrow]*)
(*\[Integral](sin[c+d x]^j)^(m-j) (C+A sin[c+d x]+B sin[c+d x]^2)\[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[(sin[c_.+d_.*x_]^j_.)^m_.*(A_.+B_.*sin[c_.+d_.*x_]+C_.*sin[c_.+d_.*x_]^(-1)),x_Symbol] :=
  Int[(sin[c+d*x]^j)^(m-j)*(C+A*sin[c+d*x]+B*sin[c+d*x]^2),x] /;
FreeQ[{c,d,A,B,C,m},x] && ZeroQ[j^2-1]


(* ::PageBreak:: *)
(**)


(* ::Subsubtitle::Bold::Closed:: *)
(*\[Integral](sin[c+d x]^j)^m (A (sin[c+d x]^k)^p+B (sin[c+d x]^k)^(p+1)+C (sin[c+d x]^k)^(p+2))\[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Derivation: Algebraic normalization*)


(* ::Subsubsection:: *)
(*Rule: If  j^2=k^2=1 \[And] (j=k \[Or] p\[Element]\[DoubleStruckCapitalZ]), then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral](sin[c+d x]^j)^m (A (sin[c+d x]^k)^p+B (sin[c+d x]^k)^(p+1)+C (sin[c+d x]^k)^(p+2))\[DifferentialD]x  \[LongRightArrow]*)
(*\[Integral](sin[c+d x]^j)^(m+j k p) (A+B sin[c+d x]^k+C sin[c+d x]^(2k))\[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[(sin[c_.+d_.*x_]^j_.)^m_.*
    (A_.*(sin[c_.+d_.*x_]^k_.)^p_.+B_.*(sin[c_.+d_.*x_]^k_.)^q_+C_.*(sin[c_.+d_.*x_]^k_.)^r_),x_Symbol] :=
  Int[(sin[c+d*x]^j)^(m+j*k*p)*(A+B*sin[c+d*x]^k+C*sin[c+d*x]^(2*k)),x] /;
FreeQ[{c,d,A,B,C,m,p},x] && ZeroQ[j^2-1] && ZeroQ[k^2-1] && ZeroQ[p+1-q] && ZeroQ[p+2-r] && 
  (ZeroQ[j-k] || IntegerQ[p])


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Derivation: Algebraic normalization*)


(* ::Subsubsection:: *)
(*Rule: If  k^2=1 \[And] m\[Element]\[DoubleStruckCapitalZ] \[And] p\[NotElement]\[DoubleStruckCapitalZ], then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral](sin[c+d x]^-k)^m (A (sin[c+d x]^k)^p+B (sin[c+d x]^k)^(p+1)+C (sin[c+d x]^k)^(p+2))\[DifferentialD]x  \[LongRightArrow]*)
(*\[Integral](sin[c+d x]^k)^(p-m) (A+B sin[c+d x]^k+C sin[c+d x]^(2k))\[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[(sin[c_.+d_.*x_]^j_.)^m_.*
    (A_.*(sin[c_.+d_.*x_]^k_.)^p_+B_.*(sin[c_.+d_.*x_]^k_.)^q_+C_.*(sin[c_.+d_.*x_]^k_.)^r_),x_Symbol] :=
  Int[(sin[c+d*x]^k)^(p-m)*(A+B*sin[c+d*x]^k+C*sin[c+d*x]^(2*k)),x] /;
FreeQ[{c,d,A,B,C,m,p},x] && ZeroQ[k^2-1] && ZeroQ[j+k] && ZeroQ[p+1-q] && ZeroQ[p+2-r] && 
  IntegerQ[m] && Not[IntegerQ[p]]


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Derivation: Piecewise constant extraction and algebraic normalization*)


(* ::Subsubsection:: *)
(*Basis: \!\( *)
(*\*SubscriptBox[\(\[PartialD]\), \(z\)]\(( *)
(*\*SqrtBox[\(Sec[z]\)] *)
(*\*SqrtBox[\(Cos[z]\)])\)\)=0*)


(* ::Subsubsection:: *)
(*Rule: If  k^2=1 \[And] m-1/2\[Element]\[DoubleStruckCapitalZ] \[And] p\[NotElement]\[DoubleStruckCapitalZ], then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral](sin[c+d x]^-k)^m (A (sin[c+d x]^k)^p+B (sin[c+d x]^k)^(p+1)+C (sin[c+d x]^k)^(p+2))\[DifferentialD]x  \[LongRightArrow]*)
(*Sqrt[Csc[c+d x]] Sqrt[Sin[c+d x]]\[Integral](sin[c+d x]^k)^(p-m) (A+B sin[c+d x]^k+C sin[c+d x]^(2k))\[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[(sin[c_.+d_.*x_]^j_.)^m_.*
    (A_.*(sin[c_.+d_.*x_]^k_.)^p_+B_.*(sin[c_.+d_.*x_]^k_.)^q_+C_.*(sin[c_.+d_.*x_]^k_.)^r_),x_Symbol] :=
  Dist[Sqrt[Csc[c+d*x]]*Sqrt[Sin[c+d*x]],
    Int[(sin[c+d*x]^k)^(p-m)*(A+B*sin[c+d*x]^k+C*sin[c+d*x]^(2*k)),x]] /;
FreeQ[{c,d,A,B,C,m,p},x] && ZeroQ[k^2-1] && ZeroQ[j+k] && ZeroQ[p+1-q] && ZeroQ[p+2-r] && 
  IntegerQ[m-1/2] && Not[IntegerQ[p]]


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Derivation: Piecewise constant extraction and algebraic normalization*)


(* ::Subsubsection:: *)
(*Basis: \!\( *)
(*\*SubscriptBox[\(\[PartialD]\), \(z\)]\(( *)
(*\*SqrtBox[\(Sec[z]\)] *)
(*\*SqrtBox[\(Cos[z]\)])\)\)=0*)


(* ::Subsubsection:: *)
(*Rule: If  k^2=1 \[And] p-1/2\[Element]\[DoubleStruckCapitalZ] \[And] 2m\[NotElement]\[DoubleStruckCapitalZ], then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral](sin[c+d x]^-k)^m (A (sin[c+d x]^k)^p+B (sin[c+d x]^k)^(p+1)+C (sin[c+d x]^k)^(p+2))\[DifferentialD]x  \[LongRightArrow]*)
(*Sqrt[Csc[c+d x]] Sqrt[Sin[c+d x]]\[Integral](sin[c+d x]^-k)^(m-p) (A+B sin[c+d x]^k+C sin[c+d x]^(2k))\[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[(sin[c_.+d_.*x_]^j_.)^m_.*
    (A_.*(sin[c_.+d_.*x_]^k_.)^p_+B_.*(sin[c_.+d_.*x_]^k_.)^q_+C_.*(sin[c_.+d_.*x_]^k_.)^r_),x_Symbol] :=
  Dist[Sqrt[Csc[c+d*x]]*Sqrt[Sin[c+d*x]],
    Int[(sin[c+d*x]^j)^(m-p)*(A+B*sin[c+d*x]^k+C*sin[c+d*x]^(2*k)),x]] /;
FreeQ[{c,d,A,B,C,m,p},x] && ZeroQ[k^2-1] && ZeroQ[j+k] && ZeroQ[p+1-q] && ZeroQ[p+2-r] && 
  IntegerQ[p-1/2] && Not[IntegerQ[2*m]]


(* ::PageBreak:: *)
(**)


(* ::Title::Plain::Closed:: *)
(* Integration Rules for *)
(*\[Integral](A (sin^i(z))^p+\!\(TraditionalForm\`B\ *)
(*\*SuperscriptBox[\(( *)
(*\*SuperscriptBox[\(sin\), \(i\)](z))\), \(p + 1\)]\)+C (sin^i(z))^(p+2))(a+b sin^k(z))^n \[DifferentialD]z when i^2=1\[And]k^2=1*)


(* ::Subsubtitle::Bold::Closed:: *)
(*\[Integral](A (sin[c+d x]^k)^p+B (sin[c+d x]^k)^(p+1)) (a+b sin[c+d x]^k)^n \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Derivation: Algebraic normalization*)


(* ::Subsubsection:: *)
(*Rule: If  k^2=1 \[And] p!=1, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral](A (sin[c+d x]^k)^p+B (sin[c+d x]^k)^(p+1)) (a+b sin[c+d x]^k)^n \[DifferentialD]x  \[LongRightArrow]*)
(*\[Integral](sin[c+d x]^k)^p (A+B sin[c+d x]^k) (a+b sin[c+d x]^k)^n \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[(A_.*(sin[c_.+d_.*x_]^k_.)^p_+B_.*(sin[c_.+d_.*x_]^k_.)^q_)*(a_.+b_.*sin[c_.+d_.*x_]^k_.)^n_.,x_Symbol] :=
  Int[(sin[c+d*x]^k)^p*(A+B*sin[c+d*x]^k)*(a+b*sin[c+d*x]^k)^n,x] /;
FreeQ[{a,b,c,d,A,B,n,p},x] && ZeroQ[k^2-1] && ZeroQ[p+1-q] && Not[a===0 && b===1]


(* ::PageBreak:: *)
(**)


(* ::Subsubtitle::Bold::Closed:: *)
(*\[Integral](A (sin[c+d x]^-k)^p+B (sin[c+d x]^-k)^(p+1)) (a+b sin[c+d x]^k)^n \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Derivation: Algebraic normalization*)


(* ::Subsubsection:: *)
(*Rule: If  k^2=1, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral](A+B sin[c+d x]^-k) (a+b sin[c+d x]^k)^n \[DifferentialD]x  \[LongRightArrow]*)
(*\[Integral]sin[c+d x]^-k (B+A sin[c+d x]^k) (a+b sin[c+d x]^k)^n \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[(A_+B_.*sin[c_.+d_.*x_]^i_.)*(a_.+b_.*sin[c_.+d_.*x_]^k_.)^n_.,x_Symbol] :=
  Int[sin[c+d*x]^(-k)*(B+A*sin[c+d*x]^k)*(a+b*sin[c+d*x]^k)^n,x] /;
FreeQ[{a,b,c,d,A,B,n},x] && ZeroQ[k^2-1] && ZeroQ[k+i] && Not[a===0 && b===1]


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Derivation: Algebraic normalization*)


(* ::Subsubsection:: *)
(*Rule: If  k^2=1 \[And] p!=1 \[And] p!=-2, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral](A (sin[c+d x]^-k)^p+B (sin[c+d x]^-k)^(p+1)) (a+b sin[c+d x]^k)^n \[DifferentialD]x  \[LongRightArrow]*)
(*\[Integral](sin[c+d x]^-k)^(p+1) (B+A sin[c+d x]^k) (a+b sin[c+d x]^k)^n \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[(A_.*(sin[c_.+d_.*x_]^i_.)^p_+B_.*(sin[c_.+d_.*x_]^i_.)^q_)*(a_.+b_.*sin[c_.+d_.*x_]^k_.)^n_.,x_Symbol] :=
  Int[(sin[c+d*x]^(-k))^(p+1)*(B+A*sin[c+d*x]^k)*(a+b*sin[c+d*x]^k)^n,x] /;
FreeQ[{a,b,c,d,A,B,n,p},x] && ZeroQ[k^2-1] && ZeroQ[k+i] && ZeroQ[p+1-q] && 
  Not[a===0 && b===1] && p!=-2


(* ::PageBreak:: *)
(**)


(* ::Subsubtitle::Bold::Closed:: *)
(*\[Integral](A (sin[c+d x]^k)^p+C (sin[c+d x]^k)^(p+2)) (a+b sin[c+d x]^k)^n \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Derivation: Algebraic normalization*)


(* ::Subsubsection:: *)
(*Rule: If  k^2=1, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral](A (sin[c+d x]^k)^p+C (sin[c+d x]^k)^(p+2)) (a+b sin[c+d x]^k)^n \[DifferentialD]x  \[LongRightArrow]*)
(*\[Integral](sin[c+d x]^k)^p (A+C sin[c+d x]^(2k)) (a+b sin[c+d x]^k)^n \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[(A_.*(sin[c_.+d_.*x_]^k_.)^p_.+C_.*(sin[c_.+d_.*x_]^k_.)^r_)*
    (a_.+b_.*sin[c_.+d_.*x_]^k_.)^n_.,x_Symbol] :=
  Int[(sin[c+d*x]^k)^p*(A+C*sin[c+d*x]^(2*k))*(a+b*sin[c+d*x]^k)^n,x] /;
FreeQ[{a,b,c,d,A,C,n,p},x] && ZeroQ[k^2-1] && ZeroQ[p+2-r]


(* ::PageBreak:: *)
(**)


(* ::Subsubtitle::Bold::Closed:: *)
(*\[Integral](A (sin[c+d x]^-k)^p+C (sin[c+d x]^-k)^(p+2)) (a+b sin[c+d x]^k)^n \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Derivation: Algebraic normalization*)


(* ::Subsubsection:: *)
(*Rule: If  k^2=1, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral](A+C sin[c+d x]^(-2 k)) (a+b sin[c+d x]^k)^n \[DifferentialD]x  \[LongRightArrow]*)
(*\[Integral]sin[c+d x]^(-2k) (C+A sin[c+d x]^(2k)) (a+b sin[c+d x]^k)^n \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[(A_+C_.*sin[c_.+d_.*x_]^i2_)*(a_.+b_.*sin[c_.+d_.*x_]^k_.)^n_.,x_Symbol] :=
  Int[sin[c+d*x]^(-2*k)*(C+A*sin[c+d*x]^(2*k))*(a+b*sin[c+d*x]^k)^n,x] /;
FreeQ[{a,b,c,d,A,C,n},x] && ZeroQ[k^2-1] && ZeroQ[k+i2/2]


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Derivation: Algebraic normalization*)


(* ::Subsubsection:: *)
(*Rule: If  k^2=1, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral](A (sin[c+d x]^-k)^p+C (sin[c+d x]^-k)^(p+2)) (a+b sin[c+d x]^k)^n \[DifferentialD]x  \[LongRightArrow]*)
(*\[Integral](sin[c+d x]^-k)^(p+2) (C+A sin[c+d x]^(2k)) (a+b sin[c+d x]^k)^n \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[(A_.*(sin[c_.+d_.*x_]^i_.)^p_.+C_.*(sin[c_.+d_.*x_]^i_.)^r_)*(a_.+b_.*sin[c_.+d_.*x_]^k_.)^n_.,x_Symbol] :=
  Int[(sin[c+d*x]^(-k))^(p+2)*(C+A*sin[c+d*x]^(2*k))*(a+b*sin[c+d*x]^k)^n,x] /;
FreeQ[{a,b,c,d,A,C,n,p},x] && ZeroQ[k^2-1] && ZeroQ[k+i] && ZeroQ[p+2-r]


(* ::PageBreak:: *)
(**)


(* ::Subsubtitle::Bold::Closed:: *)
(*\[Integral](A+B sin[c+d x]^k+C sin[c+d x]^-k) (a+b sin[c+d x]^k)^n \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Derivation: Algebraic normalization*)


(* ::Subsubsection:: *)
(*Rule: If  k^2=1, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral](A+B sin[c+d x]^k+C sin[c+d x]^-k) (a+b sin[c+d x]^k)^n \[DifferentialD]x  \[LongRightArrow]                                        *)
(*                    \[Integral]sin[c+d x]^-k (C+A sin[c+d x]^k+B sin[c+d x]^(2k)) (a+b sin[c+d x]^k)^n \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[(A_.+B_.*sin[c_.+d_.*x_]^k_.+C_.*sin[c_.+d_.*x_]^l_.)*(a_.+b_.*sin[c_.+d_.*x_]^k_.)^n_.,x_Symbol] :=
  Int[sin[c+d*x]^(-k)*(C+A*sin[c+d*x]^k+B*sin[c+d*x]^(2*k))*(a+b*sin[c+d*x]^k)^n,x] /;
FreeQ[{a,b,c,d,A,B,C,n},x] && ZeroQ[k^2-1] && ZeroQ[k+l]


(* ::PageBreak:: *)
(**)


(* ::Subsubtitle::Bold::Closed:: *)
(*\[Integral](A (sin[c+d x]^k)^p+B (sin[c+d x]^k)^(p+1)+C (sin[c+d x]^k)^(p+2)) (a+b sin[c+d x]^k)^n \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Derivation: Algebraic normalization*)


(* ::Subsubsection:: *)
(*Rule: If  k^2=1, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral](A (sin[c+d x]^k)^p+B (sin[c+d x]^k)^(p+1)+C (sin[c+d x]^k)^(p+2)) (a+b sin[c+d x]^k)^n \[DifferentialD]x  \[LongRightArrow]*)
(*\[Integral](sin[c+d x]^k)^p (A+B sin[c+d x]^k+C sin[c+d x]^(2k)) (a+b sin[c+d x]^k)^n \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[(A_.*(sin[c_.+d_.*x_]^k_.)^p_.+B_.*(sin[c_.+d_.*x_]^k_.)^q_+C_.*(sin[c_.+d_.*x_]^k_.)^r_)*
    (a_.+b_.*sin[c_.+d_.*x_]^k_.)^n_.,x_Symbol] :=
  Int[(sin[c+d*x]^k)^p*(A+B*sin[c+d*x]^k+C*sin[c+d*x]^(2*k))*(a+b*sin[c+d*x]^k)^n,x] /;
FreeQ[{a,b,c,d,A,B,C,n,p},x] && ZeroQ[k^2-1] && ZeroQ[p+1-q] && ZeroQ[p+2-r]


(* ::PageBreak:: *)
(**)


(* ::Subsubtitle::Bold::Closed:: *)
(*\[Integral](A (sin[c+d x]^-k)^p+B (sin[c+d x]^-k)^(p+1)+C (sin[c+d x]^-k)^(p+2)) (a+b sin[c+d x]^k)^n \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Derivation: Algebraic normalization*)


(* ::Subsubsection:: *)
(*Rule: If  k^2=1, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral](A+B sin[c+d x]^-k+C sin[c+d x]^(-2 k)) (a+b sin[c+d x]^k)^n \[DifferentialD]x  \[LongRightArrow]*)
(*\[Integral]sin[c+d x]^(-2k) (C+B sin[c+d x]^k+A sin[c+d x]^(2k)) (a+b sin[c+d x]^k)^n \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[(A_.+B_.*sin[c_.+d_.*x_]^i_.+C_.*sin[c_.+d_.*x_]^i2_)*(a_.+b_.*sin[c_.+d_.*x_]^k_.)^n_.,x_Symbol] :=
  Int[sin[c+d*x]^(-2*k)*(C+B*sin[c+d*x]^k+A*sin[c+d*x]^(2*k))*(a+b*sin[c+d*x]^k)^n,x] /;
FreeQ[{a,b,c,d,A,B,C,n},x] && ZeroQ[k^2-1] && ZeroQ[k+i] && ZeroQ[2*i-i2]


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Derivation: Algebraic normalization*)


(* ::Subsubsection:: *)
(*Rule: If  k^2=1, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral](A (sin[c+d x]^-k)^p+B (sin[c+d x]^-k)^(p+1)+C (sin[c+d x]^-k)^(p+2)) (a+b sin[c+d x]^k)^n \[DifferentialD]x  \[LongRightArrow]*)
(*\[Integral](sin[c+d x]^-k)^(p+2) (C+B sin[c+d x]^k+A sin[c+d x]^(2k)) (a+b sin[c+d x]^k)^n \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[(A_.*(sin[c_.+d_.*x_]^i_.)^p_.+B_.*(sin[c_.+d_.*x_]^i_.)^q_+C_.*(sin[c_.+d_.*x_]^i_.)^r_)*
    (a_.+b_.*sin[c_.+d_.*x_]^k_.)^n_.,x_Symbol] :=
  Int[(sin[c+d*x]^(-k))^(p+2)*(C+B*sin[c+d*x]^k+A*sin[c+d*x]^(2*k))*(a+b*sin[c+d*x]^k)^n,x] /;
FreeQ[{a,b,c,d,A,B,C,n,p},x] && ZeroQ[k^2-1] && ZeroQ[k+i] && ZeroQ[p+1-q] && ZeroQ[p+2-r]


(* ::PageBreak:: *)
(**)


(* ::Title::Plain::Closed:: *)
(* Integration Rules for *)
(*\[Integral](sin^j(z))^m (A (sin^i(z))^p+\!\(TraditionalForm\`B\ *)
(*\*SuperscriptBox[\(( *)
(*\*SuperscriptBox[\(sin\), \(i\)](z))\), \(p + 1\)]\)+C (sin^i(z))^(p+2))(a+b sin^k(z))^n \[DifferentialD]z when j^2=1\[And]i^2=1\[And]k^2=1*)


(* ::Subsubtitle::Bold::Closed:: *)
(*\[Integral](sin[c+d x]^j)^m (A (sin[c+d x]^k)^p+B (sin[c+d x]^k)^(p+1)) (a+b sin[c+d x]^k)^n \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Derivation: Algebraic normalization*)


(* ::Subsubsection:: *)
(*Rule: If  j^2=k^2=1 \[And] (j=k \[Or] p\[Element]\[DoubleStruckCapitalZ]) \[And] p!=1, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral](sin[c+d x]^j)^m (A (sin[c+d x]^k)^p+B (sin[c+d x]^k)^(p+1)) (a+b sin[c+d x]^k)^n \[DifferentialD]x  \[LongRightArrow]*)
(*\[Integral](sin[c+d x]^j)^(m+j k p) (A+B sin[c+d x]^k) (a+b sin[c+d x]^k)^n \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[(sin[c_.+d_.*x_]^j_.)^m_.*(A_.*(sin[c_.+d_.*x_]^k_.)^p_+B_.*(sin[c_.+d_.*x_]^k_.)^q_)*
    (a_.+b_.*sin[c_.+d_.*x_]^k_.)^n_.,x_Symbol] :=
  Int[(sin[c+d*x]^j)^(m+j*k*p)*(A+B*sin[c+d*x]^k)*(a+b*sin[c+d*x]^k)^n,x] /;
FreeQ[{a,b,c,d,A,B,m,n,p},x] && ZeroQ[j^2-1] && ZeroQ[k^2-1] && ZeroQ[p+1-q] && 
  (ZeroQ[j-k] || IntegerQ[p])


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Derivation: Algebraic normalization*)


(* ::Subsubsection:: *)
(*Rule: If  k^2=1 \[And] m\[Element]\[DoubleStruckCapitalZ] \[And] p\[NotElement]\[DoubleStruckCapitalZ], then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral](sin[c+d x]^-k)^m (A (sin[c+d x]^k)^p+B (sin[c+d x]^k)^(p+1)) (a+b sin[c+d x]^k)^n \[DifferentialD]x  \[LongRightArrow]*)
(*\[Integral](sin[c+d x]^k)^(p-m) (A+B sin[c+d x]^k) (a+b sin[c+d x]^k)^n \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[(sin[c_.+d_.*x_]^j_.)^m_.*(A_.*(sin[c_.+d_.*x_]^k_.)^p_+B_.*(sin[c_.+d_.*x_]^k_.)^q_)*
    (a_.+b_.*sin[c_.+d_.*x_]^k_.)^n_.,x_Symbol] :=
  Int[(sin[c+d*x]^k)^(p-m)*(A+B*sin[c+d*x]^k)*(a+b*sin[c+d*x]^k)^n,x] /;
FreeQ[{a,b,c,d,A,B,m,n,p},x] && ZeroQ[k^2-1] && ZeroQ[j+k] && ZeroQ[p+1-q] && 
  IntegerQ[m] && Not[IntegerQ[p]]


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Derivation: Piecewise constant extraction and algebraic normalization*)


(* ::Subsubsection:: *)
(*Basis: \!\( *)
(*\*SubscriptBox[\(\[PartialD]\), \(z\)]\(( *)
(*\*SqrtBox[\(Sec[z]\)] *)
(*\*SqrtBox[\(Cos[z]\)])\)\)=0*)


(* ::Subsubsection:: *)
(*Rule: If  k^2=1 \[And] m-1/2\[Element]\[DoubleStruckCapitalZ] \[And] p\[NotElement]\[DoubleStruckCapitalZ], then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral](sin[c+d x]^-k)^m (A (sin[c+d x]^k)^p+B (sin[c+d x]^k)^(p+1)) (a+b sin[c+d x]^k)^n \[DifferentialD]x  \[LongRightArrow]*)
(*Sqrt[Csc[c+d x]] Sqrt[Sin[c+d x]]\[Integral](sin[c+d x]^k)^(p-m) (A+B sin[c+d x]^k) (a+b sin[c+d x]^k)^n \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[(sin[c_.+d_.*x_]^j_.)^m_.*(A_.*(sin[c_.+d_.*x_]^k_.)^p_+B_.*(sin[c_.+d_.*x_]^k_.)^q_)*
    (a_.+b_.*sin[c_.+d_.*x_]^k_.)^n_.,x_Symbol] :=
  Dist[Sqrt[Csc[c+d*x]]*Sqrt[Sin[c+d*x]],
    Int[(sin[c+d*x]^k)^(p-m)*(A+B*sin[c+d*x]^k)*(a+b*sin[c+d*x]^k)^n,x]] /;
FreeQ[{a,b,c,d,A,B,m,n,p},x] && ZeroQ[k^2-1] && ZeroQ[j+k] && ZeroQ[p+1-q] && 
  IntegerQ[m-1/2] && Not[IntegerQ[p]]


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Derivation: Piecewise constant extraction and algebraic normalization*)


(* ::Subsubsection:: *)
(*Basis: \!\( *)
(*\*SubscriptBox[\(\[PartialD]\), \(z\)]\(( *)
(*\*SqrtBox[\(Sec[z]\)] *)
(*\*SqrtBox[\(Cos[z]\)])\)\)=0*)


(* ::Subsubsection:: *)
(*Rule: If  k^2=1 \[And] p-1/2\[Element]\[DoubleStruckCapitalZ] \[And] 2m\[NotElement]\[DoubleStruckCapitalZ], then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral](sin[c+d x]^-k)^m (A (sin[c+d x]^k)^p+B (sin[c+d x]^k)^(p+1)) (a+b sin[c+d x]^k)^n \[DifferentialD]x  \[LongRightArrow]*)
(*Sqrt[Csc[c+d x]] Sqrt[Sin[c+d x]]\[Integral](sin[c+d x]^-k)^(m-p) (A+B sin[c+d x]^k) (a+b sin[c+d x]^k)^n \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[(sin[c_.+d_.*x_]^j_.)^m_.*(A_.*(sin[c_.+d_.*x_]^k_.)^p_+B_.*(sin[c_.+d_.*x_]^k_.)^q_)*
    (a_.+b_.*sin[c_.+d_.*x_]^k_.)^n_.,x_Symbol] :=
  Dist[Sqrt[Csc[c+d*x]]*Sqrt[Sin[c+d*x]],
    Int[(sin[c+d*x]^j)^(m-p)*(A+B*sin[c+d*x]^k)*(a+b*sin[c+d*x]^k)^n,x]] /;
FreeQ[{a,b,c,d,A,B,m,n,p},x] && ZeroQ[k^2-1] && ZeroQ[j+k] && ZeroQ[p+1-q] && 
  IntegerQ[p-1/2] && Not[IntegerQ[2*m]]


(* ::PageBreak:: *)
(**)


(* ::Subsubtitle::Bold::Closed:: *)
(*\[Integral](sin[c+d x]^j)^m (A (sin[c+d x]^-k)^p+B (sin[c+d x]^-k)^(p+1)) (a+b sin[c+d x]^k)^n \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Derivation: Algebraic normalization*)


(* ::Subsubsection:: *)
(*Rule: If  j^2=k^2=1, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral](sin[c+d x]^j)^m (A+B sin[c+d x]^-k) (a+b sin[c+d x]^k)^n \[DifferentialD]x  \[LongRightArrow]*)
(*\[Integral](sin[c+d x]^j)^(m-j k) (B+A sin[c+d x]^k) (a+b sin[c+d x]^k)^n \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[(sin[c_.+d_.*x_]^j_.)^m_.*(A_.+B_.*sin[c_.+d_.*x_]^i_.)*(a_.+b_.*sin[c_.+d_.*x_]^k_.)^n_.,x_Symbol] :=
  Int[(sin[c+d*x]^j)^(m-j*k)*(B+A*sin[c+d*x]^k)*(a+b*sin[c+d*x]^k)^n,x] /;
FreeQ[{a,b,c,d,A,B,m,n},x] && ZeroQ[j^2-1] && ZeroQ[k^2-1] && ZeroQ[k+i]


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Derivation: Algebraic normalization*)


(* ::Subsubsection:: *)
(*Rule: If  j^2=k^2=1 \[And] (j+k=0 \[Or] p\[Element]\[DoubleStruckCapitalZ]) \[And] p!=1 \[And] p!=-2, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral](sin[c+d x]^j)^m (A (sin[c+d x]^-k)^p+B (sin[c+d x]^-k)^(p+1)) (a+b sin[c+d x]^k)^n \[DifferentialD]x  \[LongRightArrow]*)
(*\[Integral](sin[c+d x]^j)^(m-j k(p+1)) (B+A sin[c+d x]^k) (a+b sin[c+d x]^k)^n \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[(sin[c_.+d_.*x_]^j_.)^m_.*(A_.*(sin[c_.+d_.*x_]^i_.)^p_+B_.*(sin[c_.+d_.*x_]^i_.)^q_)*
    (a_.+b_.*sin[c_.+d_.*x_]^k_.)^n_.,x_Symbol] :=
  Int[(sin[c+d*x]^j)^(m-j*k*(p+1))*(B+A*sin[c+d*x]^k)*(a+b*sin[c+d*x]^k)^n,x] /;
FreeQ[{a,b,c,d,A,B,m,n,p},x] && ZeroQ[j^2-1] && ZeroQ[k^2-1] && ZeroQ[k+i] && 
  ZeroQ[p+1-q] && (ZeroQ[j+k] || IntegerQ[p]) && p!=-2


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Derivation: Algebraic normalization*)


(* ::Subsubsection:: *)
(*Rule: If  k^2=1 \[And] m\[Element]\[DoubleStruckCapitalZ] \[And] p\[NotElement]\[DoubleStruckCapitalZ], then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral](sin[c+d x]^k)^m (A (sin[c+d x]^-k)^p+B (sin[c+d x]^-k)^(p+1)) (a+b sin[c+d x]^k)^n \[DifferentialD]x  \[LongRightArrow]*)
(*\[Integral](sin[c+d x]^-k)^(p-m+1) (B+A sin[c+d x]^k) (a+b sin[c+d x]^k)^n \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[(sin[c_.+d_.*x_]^k_.)^m_.*(A_.*(sin[c_.+d_.*x_]^i_.)^p_+B_.*(sin[c_.+d_.*x_]^i_.)^q_)*
    (a_.+b_.*sin[c_.+d_.*x_]^k_.)^n_.,x_Symbol] :=
  Int[(sin[c+d*x]^(-k))^(p-m+1)*(B+A*sin[c+d*x]^k)*(a+b*sin[c+d*x]^k)^n,x] /;
FreeQ[{a,b,c,d,A,B,m,n,p},x] && ZeroQ[k^2-1] && ZeroQ[k+i] && ZeroQ[p+1-q] && 
  IntegerQ[m] && Not[IntegerQ[p]]


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Derivation: Piecewise constant extraction and algebraic normalization*)


(* ::Subsubsection:: *)
(*Basis: \!\( *)
(*\*SubscriptBox[\(\[PartialD]\), \(z\)]\(( *)
(*\*SqrtBox[\(Sec[z]\)] *)
(*\*SqrtBox[\(Cos[z]\)])\)\)=0*)


(* ::Subsubsection:: *)
(*Rule: If  k^2=1 \[And] m-1/2\[Element]\[DoubleStruckCapitalZ] \[And] p\[NotElement]\[DoubleStruckCapitalZ], then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral](sin[c+d x]^k)^m (A (sin[c+d x]^-k)^p+B (sin[c+d x]^-k)^(p+1)) (a+b sin[c+d x]^k)^n \[DifferentialD]x  \[LongRightArrow]*)
(*Sqrt[Csc[c+d x]] Sqrt[Sin[c+d x]]\[Integral](sin[c+d x]^-k)^(p-m+1) (B+A sin[c+d x]^k) (a+b sin[c+d x]^k)^n \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[(sin[c_.+d_.*x_]^k_.)^m_.*(A_.*(sin[c_.+d_.*x_]^i_.)^p_+B_.*(sin[c_.+d_.*x_]^i_.)^q_)*
    (a_.+b_.*sin[c_.+d_.*x_]^k_.)^n_.,x_Symbol] :=
  Dist[Sqrt[Csc[c+d*x]]*Sqrt[Sin[c+d*x]],
    Int[(sin[c+d*x]^(-k))^(p-m+1)*(B+A*sin[c+d*x]^k)*(a+b*sin[c+d*x]^k)^n,x]] /;
FreeQ[{a,b,c,d,A,B,m,n,p},x] && ZeroQ[k^2-1] && ZeroQ[k+i] && ZeroQ[p+1-q] && 
  IntegerQ[m-1/2] && Not[IntegerQ[p]]


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Derivation: Piecewise constant extraction and algebraic normalization*)


(* ::Subsubsection:: *)
(*Basis: \!\( *)
(*\*SubscriptBox[\(\[PartialD]\), \(z\)]\(( *)
(*\*SqrtBox[\(Sec[z]\)] *)
(*\*SqrtBox[\(Cos[z]\)])\)\)=0*)


(* ::Subsubsection:: *)
(*Rule: If  k^2=1 \[And] p-1/2\[Element]\[DoubleStruckCapitalZ] \[And] 2m\[NotElement]\[DoubleStruckCapitalZ], then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral](sin[c+d x]^k)^m (A (sin[c+d x]^-k)^p+B (sin[c+d x]^-k)^(p+1)) (a+b sin[c+d x]^k)^n \[DifferentialD]x  \[LongRightArrow]*)
(*Sqrt[Csc[c+d x]] Sqrt[Sin[c+d x]]\[Integral](sin[c+d x]^k)^(m-p-1) (B+A sin[c+d x]^k) (a+b sin[c+d x]^k)^n \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[(sin[c_.+d_.*x_]^k_.)^m_.*(A_.*(sin[c_.+d_.*x_]^i_.)^p_+B_.*(sin[c_.+d_.*x_]^i_.)^q_)*
    (a_.+b_.*sin[c_.+d_.*x_]^k_.)^n_.,x_Symbol] :=
  Dist[Sqrt[Csc[c+d*x]]*Sqrt[Sin[c+d*x]],
    Int[(sin[c+d*x]^k)^(m-p-1)*(B+A*sin[c+d*x]^k)*(a+b*sin[c+d*x]^k)^n,x]] /;
FreeQ[{a,b,c,d,A,B,m,n,p},x] && ZeroQ[k^2-1] && ZeroQ[k+i] && ZeroQ[p+1-q] && 
  IntegerQ[p-1/2] && Not[IntegerQ[2*m]]


(* ::PageBreak:: *)
(**)


(* ::Subsubtitle::Bold::Closed:: *)
(*\[Integral](sin[c+d x]^j)^m (A (sin[c+d x]^k)^p+C (sin[c+d x]^k)^(p+2)) (a+b sin[c+d x]^k)^n \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Derivation: Algebraic normalization*)


(* ::Subsubsection:: *)
(*Rule: If  j^2=k^2=1 \[And] (j=k \[Or] p\[Element]\[DoubleStruckCapitalZ]), then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral](sin[c+d x]^j)^m (A (sin[c+d x]^k)^p+C (sin[c+d x]^k)^(p+2)) (a+b sin[c+d x]^k)^n \[DifferentialD]x  \[LongRightArrow]*)
(*\[Integral](sin[c+d x]^j)^(m+j k p) (A+C sin[c+d x]^(2k)) (a+b sin[c+d x]^k)^n \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[(sin[c_.+d_.*x_]^j_.)^m_.*(A_.*(sin[c_.+d_.*x_]^k_.)^p_.+C_.*(sin[c_.+d_.*x_]^k_.)^r_)*
    (a_.+b_.*sin[c_.+d_.*x_]^k_.)^n_.,x_Symbol] :=
  Int[(sin[c+d*x]^j)^(m+j*k*p)*(A+C*sin[c+d*x]^(2*k))*(a+b*sin[c+d*x]^k)^n,x] /;
FreeQ[{a,b,c,d,A,C,m,n,p},x] && ZeroQ[j^2-1] && ZeroQ[k^2-1] && ZeroQ[p+2-r] && 
  (ZeroQ[j-k] || IntegerQ[p])


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Derivation: Algebraic normalization*)


(* ::Subsubsection:: *)
(*Rule: If  k^2=1 \[And] m\[Element]\[DoubleStruckCapitalZ] \[And] p\[NotElement]\[DoubleStruckCapitalZ], then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral](sin[c+d x]^-k)^m (A (sin[c+d x]^k)^p+C (sin[c+d x]^k)^(p+2)) (a+b sin[c+d x]^k)^n \[DifferentialD]x  \[LongRightArrow]*)
(*\[Integral](sin[c+d x]^k)^(p-m) (A+C sin[c+d x]^(2k)) (a+b sin[c+d x]^k)^n \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[(sin[c_.+d_.*x_]^j_.)^m_.*(A_.*(sin[c_.+d_.*x_]^k_.)^p_+C_.*(sin[c_.+d_.*x_]^k_.)^r_)*
    (a_.+b_.*sin[c_.+d_.*x_]^k_.)^n_.,x_Symbol] :=
  Int[(sin[c+d*x]^k)^(p-m)*(A+C*sin[c+d*x]^(2*k))*(a+b*sin[c+d*x]^k)^n,x] /;
FreeQ[{a,b,c,d,A,C,m,n,p},x] && ZeroQ[k^2-1] && ZeroQ[j+k] && ZeroQ[p+2-r] && 
  IntegerQ[m] && Not[IntegerQ[p]]


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Derivation: Piecewise constant extraction and algebraic normalization*)


(* ::Subsubsection:: *)
(*Basis: \!\( *)
(*\*SubscriptBox[\(\[PartialD]\), \(z\)]\(( *)
(*\*SqrtBox[\(Sec[z]\)] *)
(*\*SqrtBox[\(Cos[z]\)])\)\)=0*)


(* ::Subsubsection:: *)
(*Rule: If  k^2=1 \[And] m-1/2\[Element]\[DoubleStruckCapitalZ] \[And] p\[NotElement]\[DoubleStruckCapitalZ], then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral](sin[c+d x]^-k)^m (A (sin[c+d x]^k)^p+C (sin[c+d x]^k)^(p+2)) (a+b sin[c+d x]^k)^n \[DifferentialD]x  \[LongRightArrow]*)
(*Sqrt[Csc[c+d x]] Sqrt[Sin[c+d x]]\[Integral](sin[c+d x]^k)^(p-m) (A+C sin[c+d x]^(2k)) (a+b sin[c+d x]^k)^n \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[(sin[c_.+d_.*x_]^j_.)^m_.*(A_.*(sin[c_.+d_.*x_]^k_.)^p_+C_.*(sin[c_.+d_.*x_]^k_.)^r_)*
    (a_.+b_.*sin[c_.+d_.*x_]^k_.)^n_.,x_Symbol] :=
  Dist[Sqrt[Csc[c+d*x]]*Sqrt[Sin[c+d*x]],
    Int[(sin[c+d*x]^k)^(p-m)*(A+C*sin[c+d*x]^(2*k))*(a+b*sin[c+d*x]^k)^n,x]] /;
FreeQ[{a,b,c,d,A,C,m,n,p},x] && ZeroQ[k^2-1] && ZeroQ[j+k] && ZeroQ[p+2-r] && 
  IntegerQ[m-1/2] && Not[IntegerQ[p]]


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Derivation: Piecewise constant extraction and algebraic normalization*)


(* ::Subsubsection:: *)
(*Basis: \!\( *)
(*\*SubscriptBox[\(\[PartialD]\), \(z\)]\(( *)
(*\*SqrtBox[\(Sec[z]\)] *)
(*\*SqrtBox[\(Cos[z]\)])\)\)=0*)


(* ::Subsubsection:: *)
(*Rule: If  k^2=1 \[And] p-1/2\[Element]\[DoubleStruckCapitalZ] \[And] 2m\[NotElement]\[DoubleStruckCapitalZ], then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral](sin[c+d x]^-k)^m (A (sin[c+d x]^k)^p+C (sin[c+d x]^k)^(p+2)) (a+b sin[c+d x]^k)^n \[DifferentialD]x  \[LongRightArrow]*)
(*Sqrt[Csc[c+d x]] Sqrt[Sin[c+d x]]\[Integral](sin[c+d x]^-k)^(m-p) (A+C sin[c+d x]^(2k)) (a+b sin[c+d x]^k)^n \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[(sin[c_.+d_.*x_]^j_.)^m_.*(A_.*(sin[c_.+d_.*x_]^k_.)^p_+C_.*(sin[c_.+d_.*x_]^k_.)^r_)*
    (a_.+b_.*sin[c_.+d_.*x_]^k_.)^n_.,x_Symbol] :=
  Dist[Sqrt[Csc[c+d*x]]*Sqrt[Sin[c+d*x]],
    Int[(sin[c+d*x]^j)^(m-p)*(A+C*sin[c+d*x]^(2*k))*(a+b*sin[c+d*x]^k)^n,x]] /;
FreeQ[{a,b,c,d,A,C,m,n,p},x] && ZeroQ[k^2-1] && ZeroQ[j+k] && ZeroQ[p+2-r] && 
  IntegerQ[p-1/2] && Not[IntegerQ[2*m]]


(* ::PageBreak:: *)
(**)


(* ::Subsubtitle::Bold::Closed:: *)
(*\[Integral](sin[c+d x]^j)^m (A (sin[c+d x]^-k)^p+C (sin[c+d x]^-k)^(p+2)) (a+b sin[c+d x]^k)^n \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Derivation: Algebraic normalization*)


(* ::Subsubsection:: *)
(*Rule: If  j^2=k^2=1, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral](sin[c+d x]^j)^m (A+C sin[c+d x]^(-2 k)) (a+b sin[c+d x]^k)^n \[DifferentialD]x  \[LongRightArrow]*)
(*\[Integral](sin[c+d x]^j)^(m-2j k) (C+A sin[c+d x]^(2k)) (a+b sin[c+d x]^k)^n \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[(sin[c_.+d_.*x_]^j_.)^m_.*(A_.+C_.*sin[c_.+d_.*x_]^i2_)*(a_.+b_.*sin[c_.+d_.*x_]^k_.)^n_.,x_Symbol] :=
  Int[(sin[c+d*x]^j)^(m-2*j*k)*(C+A*sin[c+d*x]^(2*k))*(a+b*sin[c+d*x]^k)^n,x] /;
FreeQ[{a,b,c,d,A,C,m,n},x] && ZeroQ[j^2-1] && ZeroQ[k^2-1] && ZeroQ[k+i2/2]


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Derivation: Algebraic normalization*)


(* ::Subsubsection:: *)
(*Rule: If  j^2=k^2=1 \[And] (j+k=0 \[Or] p\[Element]\[DoubleStruckCapitalZ]), then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral](sin[c+d x]^j)^m (A (sin[c+d x]^-k)^p+C (sin[c+d x]^-k)^(p+2)) (a+b sin[c+d x]^k)^n \[DifferentialD]x  \[LongRightArrow]*)
(*\[Integral](sin[c+d x]^j)^(m-j k(p+2)) (C+A sin[c+d x]^(2k)) (a+b sin[c+d x]^k)^n \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[(sin[c_.+d_.*x_]^j_.)^m_.*(A_.*(sin[c_.+d_.*x_]^i_.)^p_.+C_.*(sin[c_.+d_.*x_]^i_.)^r_)*
    (a_.+b_.*sin[c_.+d_.*x_]^k_.)^n_.,x_Symbol] :=
  Int[(sin[c+d*x]^j)^(m-j*k*(p+2))*(C+A*sin[c+d*x]^(2*k))*(a+b*sin[c+d*x]^k)^n,x] /;
FreeQ[{a,b,c,d,A,C,m,n,p},x] && ZeroQ[j^2-1] && ZeroQ[k^2-1] && ZeroQ[k+i] && 
  ZeroQ[p+2-r] && (ZeroQ[j+k] || IntegerQ[p])


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Derivation: Algebraic normalization*)


(* ::Subsubsection:: *)
(*Rule: If  k^2=1 \[And] m\[Element]\[DoubleStruckCapitalZ] \[And] p\[NotElement]\[DoubleStruckCapitalZ], then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral](sin[c+d x]^k)^m (A (sin[c+d x]^-k)^p+C (sin[c+d x]^-k)^(p+2)) (a+b sin[c+d x]^k)^n \[DifferentialD]x  \[LongRightArrow]*)
(*\[Integral](sin[c+d x]^-k)^(p-m+2) (C+A sin[c+d x]^(2k)) (a+b sin[c+d x]^k)^n \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[(sin[c_.+d_.*x_]^k_.)^m_.*(A_.*(sin[c_.+d_.*x_]^i_.)^p_+C_.*(sin[c_.+d_.*x_]^i_.)^r_)*
    (a_.+b_.*sin[c_.+d_.*x_]^k_.)^n_.,x_Symbol] :=
  Int[(sin[c+d*x]^(-k))^(p-m+2)*(C+A*sin[c+d*x]^(2*k))*(a+b*sin[c+d*x]^k)^n,x] /;
FreeQ[{a,b,c,d,A,C,m,n,p},x] && ZeroQ[k^2-1] && ZeroQ[k+i] && ZeroQ[p+2-r] && 
  IntegerQ[m] && Not[IntegerQ[p]]


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Derivation: Piecewise constant extraction and algebraic normalization*)


(* ::Subsubsection:: *)
(*Basis: \!\( *)
(*\*SubscriptBox[\(\[PartialD]\), \(z\)]\(( *)
(*\*SqrtBox[\(Sec[z]\)] *)
(*\*SqrtBox[\(Cos[z]\)])\)\)=0*)


(* ::Subsubsection:: *)
(*Rule: If  k^2=1 \[And] m-1/2\[Element]\[DoubleStruckCapitalZ] \[And] p\[NotElement]\[DoubleStruckCapitalZ], then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral](sin[c+d x]^k)^m (A (sin[c+d x]^-k)^p+C (sin[c+d x]^-k)^(p+2)) (a+b sin[c+d x]^k)^n \[DifferentialD]x  \[LongRightArrow]*)
(*Sqrt[Csc[c+d x]] Sqrt[Sin[c+d x]]\[Integral](sin[c+d x]^-k)^(p-m+2) (C+A sin[c+d x]^(2k)) (a+b sin[c+d x]^k)^n \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[(sin[c_.+d_.*x_]^k_.)^m_.*(A_.*(sin[c_.+d_.*x_]^i_.)^p_+C_.*(sin[c_.+d_.*x_]^i_.)^r_)*
    (a_.+b_.*sin[c_.+d_.*x_]^k_.)^n_.,x_Symbol] :=
  Dist[Sqrt[Csc[c+d*x]]*Sqrt[Sin[c+d*x]],
    Int[(sin[c+d*x]^(-k))^(p-m+2)*(C+A*sin[c+d*x]^(2*k))*(a+b*sin[c+d*x]^k)^n,x]] /;
FreeQ[{a,b,c,d,A,C,m,n,p},x] && ZeroQ[k^2-1] && ZeroQ[k+i] && ZeroQ[p+2-r] && 
  IntegerQ[m-1/2] && Not[IntegerQ[p]]


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Derivation: Piecewise constant extraction and algebraic normalization*)


(* ::Subsubsection:: *)
(*Basis: \!\( *)
(*\*SubscriptBox[\(\[PartialD]\), \(z\)]\(( *)
(*\*SqrtBox[\(Sec[z]\)] *)
(*\*SqrtBox[\(Cos[z]\)])\)\)=0*)


(* ::Subsubsection:: *)
(*Rule: If  k^2=1 \[And] p-1/2\[Element]\[DoubleStruckCapitalZ] \[And] 2m\[NotElement]\[DoubleStruckCapitalZ], then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral](sin[c+d x]^k)^m (A (sin[c+d x]^-k)^p+C (sin[c+d x]^-k)^(p+2)) (a+b sin[c+d x]^k)^n \[DifferentialD]x  \[LongRightArrow]*)
(*Sqrt[Csc[c+d x]] Sqrt[Sin[c+d x]]\[Integral](sin[c+d x]^k)^(m-p-2) (C+A sin[c+d x]^(2k)) (a+b sin[c+d x]^k)^n \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[(sin[c_.+d_.*x_]^k_.)^m_.*(A_.*(sin[c_.+d_.*x_]^i_.)^p_+C_.*(sin[c_.+d_.*x_]^i_.)^r_)*
    (a_.+b_.*sin[c_.+d_.*x_]^k_.)^n_.,x_Symbol] :=
  Dist[Sqrt[Csc[c+d*x]]*Sqrt[Sin[c+d*x]],
    Int[(sin[c+d*x]^k)^(m-p-2)*(C+A*sin[c+d*x]^(2*k))*(a+b*sin[c+d*x]^k)^n,x]] /;
FreeQ[{a,b,c,d,A,C,m,n,p},x] && ZeroQ[k^2-1] && ZeroQ[k+i] && ZeroQ[p+2-r] && 
  IntegerQ[p-1/2] && Not[IntegerQ[2*m]]


(* ::PageBreak:: *)
(**)


(* ::Subsubtitle::Bold::Closed:: *)
(*\[Integral](sin[c+d x]^j)^m (A+B sin[c+d x]^k+C sin[c+d x]^-k) (a+b sin[c+d x]^k)^n \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Derivation: Algebraic normalization*)


(* ::Subsubsection:: *)
(*Rule: If  j^2=k^2=1, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral](sin[c+d x]^j)^m (A+B sin[c+d x]^k+C sin[c+d x]^-k) (a+b sin[c+d x]^k)^n \[DifferentialD]x  \[LongRightArrow]*)
(*\[Integral](sin[c+d x]^j)^(m-j k) (C+A sin[c+d x]^k+B sin[c+d x]^(2k)) (a+b sin[c+d x]^k)^n \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[(sin[c_.+d_.*x_]^j_.)^m_.*(A_.+B_.*sin[c_.+d_.*x_]^k_.+C_.*sin[c_.+d_.*x_]^l_.)*
    (a_.+b_.*sin[c_.+d_.*x_]^k_.)^n_.,x_Symbol] :=
  Int[(sin[c+d*x]^j)^(m-j*k)*(C+A*sin[c+d*x]^k+B*sin[c+d*x]^(2*k))*(a+b*sin[c+d*x]^k)^n,x] /;
FreeQ[{a,b,c,d,A,B,C,m,n},x] && ZeroQ[j^2-1] && ZeroQ[k^2-1] && ZeroQ[k+l]


(* ::PageBreak:: *)
(**)


(* ::Subsubtitle::Bold::Closed:: *)
(*\[Integral](sin[c+d x]^j)^m (A (sin[c+d x]^k)^p+B (sin[c+d x]^k)^(p+1)+C (sin[c+d x]^k)^(p+2)) (a+b sin[c+d x]^k)^n \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Derivation: Algebraic normalization*)


(* ::Subsubsection:: *)
(*Rule: If  j^2=k^2=1 \[And] (j=k \[Or] p\[Element]\[DoubleStruckCapitalZ]), then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral](sin[c+d x]^j)^m (A (sin[c+d x]^k)^p+B (sin[c+d x]^k)^(p+1)+C (sin[c+d x]^k)^(p+2)) (a+b sin[c+d x]^k)^n \[DifferentialD]x  \[LongRightArrow]*)
(*\[Integral](sin[c+d x]^j)^(m+j k p) (A+B sin[c+d x]^k+C sin[c+d x]^(2k)) (a+b sin[c+d x]^k)^n \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[(sin[c_.+d_.*x_]^j_.)^m_.*
    (A_.*(sin[c_.+d_.*x_]^k_.)^p_.+B_.*(sin[c_.+d_.*x_]^k_.)^q_+C_.*(sin[c_.+d_.*x_]^k_.)^r_)*
    (a_.+b_.*sin[c_.+d_.*x_]^k_.)^n_.,x_Symbol] :=
  Int[(sin[c+d*x]^j)^(m+j*k*p)*(A+B*sin[c+d*x]^k+C*sin[c+d*x]^(2*k))*(a+b*sin[c+d*x]^k)^n,x] /;
FreeQ[{a,b,c,d,A,B,C,m,n,p},x] && ZeroQ[j^2-1] && ZeroQ[k^2-1] && ZeroQ[p+1-q] && 
  ZeroQ[p+2-r] && (ZeroQ[j-k] || IntegerQ[p])


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Derivation: Algebraic normalization*)


(* ::Subsubsection:: *)
(*Rule: If  k^2=1 \[And] m\[Element]\[DoubleStruckCapitalZ] \[And] p\[NotElement]\[DoubleStruckCapitalZ], then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral](sin[c+d x]^-k)^m (A (sin[c+d x]^k)^p+B (sin[c+d x]^k)^(p+1)+C (sin[c+d x]^k)^(p+2)) (a+b sin[c+d x]^k)^n \[DifferentialD]x  \[LongRightArrow]*)
(*\[Integral](sin[c+d x]^k)^(p-m) (A+B sin[c+d x]^k+C sin[c+d x]^(2k)) (a+b sin[c+d x]^k)^n \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[(sin[c_.+d_.*x_]^j_.)^m_.*
    (A_.*(sin[c_.+d_.*x_]^k_.)^p_+B_.*(sin[c_.+d_.*x_]^k_.)^q_+C_.*(sin[c_.+d_.*x_]^k_.)^r_)*
    (a_.+b_.*sin[c_.+d_.*x_]^k_.)^n_.,x_Symbol] :=
  Int[(sin[c+d*x]^k)^(p-m)*(A+B*sin[c+d*x]^k+C*sin[c+d*x]^(2*k))*(a+b*sin[c+d*x]^k)^n,x] /;
FreeQ[{a,b,c,d,A,B,C,m,n,p},x] && ZeroQ[k^2-1] && ZeroQ[j+k] && ZeroQ[p+1-q] && 
  ZeroQ[p+2-r] && IntegerQ[m] && Not[IntegerQ[p]]


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Derivation: Piecewise constant extraction and algebraic normalization*)


(* ::Subsubsection:: *)
(*Basis: \!\( *)
(*\*SubscriptBox[\(\[PartialD]\), \(z\)]\(( *)
(*\*SqrtBox[\(Sec[z]\)] *)
(*\*SqrtBox[\(Cos[z]\)])\)\)=0*)


(* ::Subsubsection:: *)
(*Rule: If  k^2=1 \[And] m-1/2\[Element]\[DoubleStruckCapitalZ] \[And] p\[NotElement]\[DoubleStruckCapitalZ], then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral](sin[c+d x]^-k)^m (A (sin[c+d x]^k)^p+B (sin[c+d x]^k)^(p+1)+C (sin[c+d x]^k)^(p+2)) (a+b sin[c+d x]^k)^n \[DifferentialD]x  \[LongRightArrow]*)
(*Sqrt[Csc[c+d x]] Sqrt[Sin[c+d x]]\[Integral](sin[c+d x]^k)^(p-m) (A+B sin[c+d x]^k+C sin[c+d x]^(2k)) (a+b sin[c+d x]^k)^n \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[(sin[c_.+d_.*x_]^j_.)^m_.*
    (A_.*(sin[c_.+d_.*x_]^k_.)^p_+B_.*(sin[c_.+d_.*x_]^k_.)^q_+C_.*(sin[c_.+d_.*x_]^k_.)^r_)*
    (a_.+b_.*sin[c_.+d_.*x_]^k_.)^n_.,x_Symbol] :=
  Dist[Sqrt[Csc[c+d*x]]*Sqrt[Sin[c+d*x]],
    Int[(sin[c+d*x]^k)^(p-m)*(A+B*sin[c+d*x]^k+C*sin[c+d*x]^(2*k))*(a+b*sin[c+d*x]^k)^n,x]] /;
FreeQ[{a,b,c,d,A,B,C,m,n,p},x] && ZeroQ[k^2-1] && ZeroQ[j+k] && ZeroQ[p+1-q] && 
  ZeroQ[p+2-r] && IntegerQ[m-1/2] && Not[IntegerQ[p]]


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Derivation: Piecewise constant extraction and algebraic normalization*)


(* ::Subsubsection:: *)
(*Basis: \!\( *)
(*\*SubscriptBox[\(\[PartialD]\), \(z\)]\(( *)
(*\*SqrtBox[\(Sec[z]\)] *)
(*\*SqrtBox[\(Cos[z]\)])\)\)=0*)


(* ::Subsubsection:: *)
(*Rule: If  k^2=1 \[And] p-1/2\[Element]\[DoubleStruckCapitalZ] \[And] 2m\[NotElement]\[DoubleStruckCapitalZ], then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral](sin[c+d x]^-k)^m (A (sin[c+d x]^k)^p+B (sin[c+d x]^k)^(p+1)+C (sin[c+d x]^k)^(p+2)) (a+b sin[c+d x]^k)^n \[DifferentialD]x  \[LongRightArrow]*)
(*Sqrt[Csc[c+d x]] Sqrt[Sin[c+d x]]\[Integral](sin[c+d x]^-k)^(m-p) (A+B sin[c+d x]^k+C sin[c+d x]^(2k)) (a+b sin[c+d x]^k)^n \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[(sin[c_.+d_.*x_]^j_.)^m_.*
    (A_.*(sin[c_.+d_.*x_]^k_.)^p_+B_.*(sin[c_.+d_.*x_]^k_.)^q_+C_.*(sin[c_.+d_.*x_]^k_.)^r_)*
    (a_.+b_.*sin[c_.+d_.*x_]^k_.)^n_.,x_Symbol] :=
  Dist[Sqrt[Csc[c+d*x]]*Sqrt[Sin[c+d*x]],
    Int[(sin[c+d*x]^j)^(m-p)*(A+B*sin[c+d*x]^k+C*sin[c+d*x]^(2*k))*(a+b*sin[c+d*x]^k)^n,x]] /;
FreeQ[{a,b,c,d,A,B,C,m,n,p},x] && ZeroQ[k^2-1] && ZeroQ[j+k] && ZeroQ[p+1-q] && 
  ZeroQ[p+2-r] && IntegerQ[p-1/2] && Not[IntegerQ[2*m]]


(* ::PageBreak:: *)
(**)


(* ::Subsubtitle::Bold::Closed:: *)
(*\[Integral](sin[c+d x]^j)^m (A (sin[c+d x]^-k)^p+B (sin[c+d x]^-k)^(p+1)+C (sin[c+d x]^-k)^(p+2)) (a+b sin[c+d x]^k)^n \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Derivation: Algebraic normalization*)


(* ::Subsubsection:: *)
(*Rule: If  j^2=k^2=1, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral](sin[c+d x]^j)^m (A+B sin[c+d x]^-k+C sin[c+d x]^(-2 k)) (a+b sin[c+d x]^k)^n \[DifferentialD]x  \[LongRightArrow]*)
(*\[Integral](sin[c+d x]^j)^(m-2j k) (C+B sin[c+d x]^k+A sin[c+d x]^(2k)) (a+b sin[c+d x]^k)^n \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[(sin[c_.+d_.*x_]^j_.)^m_.*(A_.+B_.*sin[c_.+d_.*x_]^i_.+C_.*sin[c_.+d_.*x_]^i2_)*
    (a_.+b_.*sin[c_.+d_.*x_]^k_.)^n_.,x_Symbol] :=
  Int[(sin[c+d*x]^j)^(m-2*j*k)*(C+B*sin[c+d*x]^k+A*sin[c+d*x]^(2*k))*(a+b*sin[c+d*x]^k)^n,x] /;
FreeQ[{a,b,c,d,A,B,C,m,n},x] && ZeroQ[j^2-1] && ZeroQ[k^2-1] && ZeroQ[k+i] && 
  ZeroQ[2*i-i2]


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Derivation: Algebraic normalization*)


(* ::Subsubsection:: *)
(*Rule: If  j^2=k^2=1 \[And] (j+k=0 \[Or] p\[Element]\[DoubleStruckCapitalZ]), then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral](sin[c+d x]^j)^m (A (sin[c+d x]^-k)^p+B (sin[c+d x]^-k)^(p+1)+C (sin[c+d x]^-k)^(p+2)) (a+b sin[c+d x]^k)^n \[DifferentialD]x  \[LongRightArrow]*)
(*\[Integral](sin[c+d x]^j)^(m-j k(p+2)) (C+B sin[c+d x]^k+A sin[c+d x]^(2k)) (a+b sin[c+d x]^k)^n \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[(sin[c_.+d_.*x_]^j_.)^m_.*
    (A_.*(sin[c_.+d_.*x_]^i_.)^p_.+B_.*(sin[c_.+d_.*x_]^i_.)^q_+C_.*(sin[c_.+d_.*x_]^i_.)^r_)*
    (a_.+b_.*sin[c_.+d_.*x_]^k_.)^n_.,x_Symbol] :=
  Int[(sin[c+d*x]^j)^(m-j*k*(p+2))*(C+B*sin[c+d*x]^k+A*sin[c+d*x]^(2*k))*(a+b*sin[c+d*x]^k)^n,x] /;
FreeQ[{a,b,c,d,A,B,C,m,n,p},x] && ZeroQ[j^2-1] && ZeroQ[k^2-1] && ZeroQ[k+i] && 
  ZeroQ[p+1-q] && ZeroQ[p+2-r] && (ZeroQ[j+k] || IntegerQ[p])


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Derivation: Algebraic normalization*)


(* ::Subsubsection:: *)
(*Rule: If  k^2=1 \[And] m\[Element]\[DoubleStruckCapitalZ] \[And] p\[NotElement]\[DoubleStruckCapitalZ], then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral](sin[c+d x]^k)^m (A (sin[c+d x]^-k)^p+B (sin[c+d x]^-k)^(p+1)+C (sin[c+d x]^-k)^(p+2)) (a+b sin[c+d x]^k)^n \[DifferentialD]x  \[LongRightArrow]*)
(*\[Integral](sin[c+d x]^-k)^(p-m+2) (C+B sin[c+d x]^k+A sin[c+d x]^(2k)) (a+b sin[c+d x]^k)^n \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[(sin[c_.+d_.*x_]^k_.)^m_.*
    (A_.*(sin[c_.+d_.*x_]^i_.)^p_+B_.*(sin[c_.+d_.*x_]^i_.)^q_+C_.*(sin[c_.+d_.*x_]^i_.)^r_)*
    (a_.+b_.*sin[c_.+d_.*x_]^k_.)^n_.,x_Symbol] :=
  Int[(sin[c+d*x]^(-k))^(p-m+2)*(C+B*sin[c+d*x]^k+A*sin[c+d*x]^(2*k))*(a+b*sin[c+d*x]^k)^n,x] /;
FreeQ[{a,b,c,d,A,B,C,m,n,p},x] && ZeroQ[k^2-1] && ZeroQ[k+i] && ZeroQ[p+1-q] && 
  ZeroQ[p+2-r] && IntegerQ[m] && Not[IntegerQ[p]]


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Derivation: Piecewise constant extraction and algebraic normalization*)


(* ::Subsubsection:: *)
(*Basis: \!\( *)
(*\*SubscriptBox[\(\[PartialD]\), \(z\)]\(( *)
(*\*SqrtBox[\(Sec[z]\)] *)
(*\*SqrtBox[\(Cos[z]\)])\)\)=0*)


(* ::Subsubsection:: *)
(*Rule: If  k^2=1 \[And] m-1/2\[Element]\[DoubleStruckCapitalZ] \[And] p\[NotElement]\[DoubleStruckCapitalZ], then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral](sin[c+d x]^k)^m (A (sin[c+d x]^-k)^p+B (sin[c+d x]^-k)^(p+1)+C (sin[c+d x]^-k)^(p+2)) (a+b sin[c+d x]^k)^n \[DifferentialD]x  \[LongRightArrow]*)
(*Sqrt[Csc[c+d x]] Sqrt[Sin[c+d x]]\[Integral](sin[c+d x]^-k)^(p-m+2) (C+B sin[c+d x]^k+A sin[c+d x]^(2k)) (a+b sin[c+d x]^k)^n \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[(sin[c_.+d_.*x_]^k_.)^m_.*
    (A_.*(sin[c_.+d_.*x_]^i_.)^p_+B_.*(sin[c_.+d_.*x_]^i_.)^q_+C_.*(sin[c_.+d_.*x_]^i_.)^r_)*
    (a_.+b_.*sin[c_.+d_.*x_]^k_.)^n_.,x_Symbol] :=
  Dist[Sqrt[Csc[c+d*x]]*Sqrt[Sin[c+d*x]],
    Int[(sin[c+d*x]^(-k))^(p-m+2)*(C+B*sin[c+d*x]^k+A*sin[c+d*x]^(2*k))*(a+b*sin[c+d*x]^k)^n,x]] /;
FreeQ[{a,b,c,d,A,B,C,m,n,p},x] && ZeroQ[k^2-1] && ZeroQ[k+i] && ZeroQ[p+1-q] && 
  ZeroQ[p+2-r] && IntegerQ[m-1/2] && Not[IntegerQ[p]]


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Derivation: Piecewise constant extraction and algebraic normalization*)


(* ::Subsubsection:: *)
(*Basis: \!\( *)
(*\*SubscriptBox[\(\[PartialD]\), \(z\)]\(( *)
(*\*SqrtBox[\(Sec[z]\)] *)
(*\*SqrtBox[\(Cos[z]\)])\)\)=0*)


(* ::Subsubsection:: *)
(*Rule: If  k^2=1 \[And] p-1/2\[Element]\[DoubleStruckCapitalZ] \[And] 2m\[NotElement]\[DoubleStruckCapitalZ], then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral](sin[c+d x]^k)^m (A (sin[c+d x]^-k)^p+B (sin[c+d x]^-k)^(p+1)+C (sin[c+d x]^-k)^(p+2)) (a+b sin[c+d x]^k)^n \[DifferentialD]x  \[LongRightArrow]*)
(*Sqrt[Csc[c+d x]] Sqrt[Sin[c+d x]]\[Integral](sin[c+d x]^k)^(m-p-2) (C+B sin[c+d x]^k+A sin[c+d x]^(2k)) (a+b sin[c+d x]^k)^n \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[(sin[c_.+d_.*x_]^k_.)^m_.*
    (A_.*(sin[c_.+d_.*x_]^i_.)^p_+B_.*(sin[c_.+d_.*x_]^i_.)^q_+C_.*(sin[c_.+d_.*x_]^i_.)^r_)*
    (a_.+b_.*sin[c_.+d_.*x_]^k_.)^n_.,x_Symbol] :=
  Dist[Sqrt[Csc[c+d*x]]*Sqrt[Sin[c+d*x]],
    Int[(sin[c+d*x]^k)^(m-p-2)*(C+B*sin[c+d*x]^k+A*sin[c+d*x]^(2*k))*(a+b*sin[c+d*x]^k)^n,x]] /;
FreeQ[{a,b,c,d,A,B,C,m,n,p},x] && ZeroQ[k^2-1] && ZeroQ[k+i] && ZeroQ[p+1-q] && 
  ZeroQ[p+2-r] && IntegerQ[p-1/2] && Not[IntegerQ[2*m]]


(* ::PageBreak:: *)
(**)


(* ::Code:: *)
If[ShowSteps,

Int[u_,x_Symbol] :=
  Int[SubstInertSineForTrigOfLinear[u,x],x] /;
SimplifyFlag && FunctionOfTrigOfLinearQ[u,x],

Int[u_,x_Symbol] :=
  Int[SubstInertSineForTrigOfLinear[u,x],x] /;
FunctionOfTrigOfLinearQ[u,x]]


(* ::Code:: *)
Int[u_,x_Symbol] :=
  Defer[Int[u,x]] /;
RecognizedFunctionOfTrigQ[u,x]
