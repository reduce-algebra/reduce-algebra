(* ::Package:: *)

(* ::Title::Plain:: *)
(* Integration Recurrence Equations for *)
(*\[Integral](sin^j(z))^m (A+B sin^k(z)+C sin^(2k)(z))(a+b sin^k(z))^n \[DifferentialD]z when j^2=1\[And]k^2=1\[And]a^2!=b^2*)


(* ::Subsubsection:: *)
(*Recurrence 1: If  j^2=k^2=1, then*)


(* ::Subsubtitle::Bold:: *)
(*2b(n+1)(a^2-b^2)\[Integral](Sin[z]^j)^m (A+B Sin[z]^k+C Sin[z]^(2k)) (a+b Sin[z]^k)^n \[DifferentialD]z =*)
(*-2(a^2 C-a b B+b^2 A) Cos[z](Sin[z]^j)^m (a+b Sin[z]^k)^(n+1)+*)
(*\[Integral](Sin[z]^j)^(m-j k) ((a^2 C-a b B+b^2 A)(2j k m+k-1)+2b(n+1)(a (C+A)-b B)Sin[z]^k-*)
(*(2(b^2 A-a b B+b^2 C)(n+1)+(a^2 C-a b B+b^2 A)(2j k m+k+1))Sin[z]^(2k))(a+b Sin[z]^k)^(n+1) \[DifferentialD]z*)


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Recurrence 2: If  j^2=k^2=1, then*)


(* ::Subsubtitle::Bold:: *)
(*b(2j k m+2n+k+3)\[Integral](Sin[z]^j)^m (A+B Sin[z]^k+C Sin[z]^(2k)) (a+b Sin[z]^k)^n \[DifferentialD]z=*)
(*-2C Cos[z](Sin[z]^j)^m (a+b Sin[z]^k)^(n+1)+*)
(*\[Integral](Sin[z]^j)^(m-j k) (a C (2j k m+k-1)+b(2A+(A+C)(2j k m+2n+k+1))Sin[z]^k+*)
(*(2b B(n+1)+(b B-a C)(2j k m+k+1))Sin[z]^(2k))(a+b Sin[z]^k)^n \[DifferentialD]z*)


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Recurrence 3: If  j^2=k^2=1, then*)


(* ::Subsubtitle::Bold:: *)
(*(2j k m+2n+k+3)\[Integral](Sin[z]^j)^m (A+B Sin[z]^k+C Sin[z]^(2k)) (a+b Sin[z]^k)^n \[DifferentialD]z=*)
(*-2C Cos[z](Sin[z]^j)^(m+j k) (a+b Sin[z]^k)^n+*)
(* \[Integral](Sin[z]^j)^m (a (2A(n+1)+(A+C)(2j k m+k+1))+(2b A+2a B+(b A+a B+b C)(2j k m+2n+k+1))Sin[z]^k+*)
(*(2a C n+b B (2j k m+2n+k+3))Sin[z]^(2k))(a+b Sin[z]^k)^(n-1) \[DifferentialD]z*)


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Recurrence 4: If  j^2=k^2=1, then*)


(* ::Subsubtitle::Bold:: *)
(*(2j k m+k+1)\[Integral](Sin[z]^j)^m (A+B Sin[z]^k+C Sin[z]^(2k)) (a+b Sin[z]^k)^n \[DifferentialD]z=*)
(*2A Cos[z](Sin[z]^j)^(m+j k) (a+b Sin[z]^k)^n+*)
(*\[Integral](Sin[z]^j)^(m+j k) (a B(2j k m+k+1)-2b A n+(2a A+(a A+a C+b B) (2j k m+k+1)) Sin[z]^k+*)
(*b(2A (n+1)+(A+C)(2j k m+k+1))Sin[z]^(2k))(a+b Sin[z]^k)^(n-1) \[DifferentialD]z*)


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Recurrence 5: If  j^2=k^2=1, then*)


(* ::Subsubtitle::Bold:: *)
(*a(2j k m+k+1)\[Integral](Sin[z]^j)^m (A+B Sin[z]^k+C Sin[z]^(2k)) (a+b Sin[z]^k)^n \[DifferentialD]z=*)
(*2A Cos[z](Sin[z]^j)^(m+j k) (a+b Sin[z]^k)^(n+1)+*)
(*\[Integral](Sin[z]^j)^(m+j k) ((a B-b A)(2j k m+k+1)-2b A (n+1)+a(2A+(A+C)(2j k m+k+1))Sin[z]^k+*)
(*b A(2j k m+2n+k+5)Sin[z]^(2k))(a+b Sin[z]^k)^n \[DifferentialD]z*)


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Recurrence 6: If  j^2=k^2=1, then*)


(* ::Subsubtitle::Bold:: *)
(*2a(n+1) (a^2-b^2)\[Integral](Sin[z]^j)^m (A+B Sin[z]^k+C Sin[z]^(2k)) (a+b Sin[z]^k)^n \[DifferentialD]z=*)
(*2(b^2 A-a b B+a^2 C) Cos[z](Sin[z]^j)^(m+j k) (a+b Sin[z]^k)^(n+1)+*)
(* \[Integral](Sin[z]^j)^m (2A (a^2-b^2) (n+1)-(a^2 C-a b B+b^2 A)(2j k m+k+1)-2a(b A-a B+b C)(n+1)Sin[z]^k+*)
(* (b^2 A-a b B+a^2 C)(2j k m+2n+k+5)Sin[z]^(2k))(a+b Sin[z]^k)^(n+1) \[DifferentialD]z*)


(* ::PageBreak:: *)
(**)


(* ::Title::Plain:: *)
(* Integration Recurrence Equations for *)
(*\[Integral](sin^j(z))^m (A+B sin^k(z)+C sin^(2k)(z))(a+b sin^k(z))^n \[DifferentialD]z when j^2=1\[And]k^2=1\[And]a^2=b^2*)


(* ::Subsubsection:: *)
(*Recurrence 7: If  j^2=k^2=1 \[And] a^2-b^2=0, then*)


(* ::Subsubtitle::Bold:: *)
(*2a^2 (2n+1)\[Integral](Sin[z]^j)^m (A+B Sin[z]^k) (a+b Sin[z]^k)^n \[DifferentialD]z=*)
(*2a(b A-a B)Cos[z](Sin[z]^j)^m (a+b Sin[z]^k)^n+*)
(*\[Integral](Sin[z]^j)^(m-j k) (-(b A-a B)(2j k m+k-1)+(2 (b B n+a A (n+1))+(a A-b B)(2j k m+k-1)) Sin[z]^k) (a+b Sin[z]^k)^(n+1) \[DifferentialD]z*)


(* ::Subsubsection:: *)
(*Recurrence 8: If  j^2=k^2=1 \[And] a^2-b^2=0, then*)


(* ::Subsubtitle::Bold:: *)
(*a(2j k m+2n+k+1)\[Integral](Sin[z]^j)^m (A+B Sin[z]^k) (a+b Sin[z]^k)^n \[DifferentialD]z=*)
(*-2a B Cos[z](Sin[z]^j)^m (a+b Sin[z]^k)^n+*)
(*\[Integral](Sin[z]^j)^(m-j k) (a B(2j k m+k-1)+(2b B n+a A(2j k m+2n+k+1)) Sin[z]^k) (a+b Sin[z]^k)^n \[DifferentialD]z*)


(* ::Subsubsection:: *)
(*Recurrence 9: If  j^2=k^2=1 \[And] a^2-b^2=0, then*)


(* ::Subsubtitle::Bold:: *)
(*(2j k m+2n+k+1)\[Integral](Sin[z]^j)^m (A+B Sin[z]^k) (a+b Sin[z]^k)^n \[DifferentialD]z=*)
(*-2b B Cos[z](Sin[z]^j)^(m+j k) (a+b Sin[z]^k)^(n-1)+*)
(*\[Integral](Sin[z]^j)^m (2a A n+(a A+b B)(2j k m+k+1)+(2(b A+a B n)+(b A+a B)(2j k m+2n+k-1)) Sin[z]^k) (a+b Sin[z]^k)^(n-1) \[DifferentialD]z*)


(* ::Subsubsection:: *)
(*Recurrence 10: If  j^2=k^2=1 \[And] a^2-b^2=0, then*)


(* ::Subsubtitle::Bold:: *)
(*(2j k m+k+1)\[Integral](Sin[z]^j)^m (A+B Sin[z]^k) (a+b Sin[z]^k)^n \[DifferentialD]z=*)
(*2a A Cos[z](Sin[z]^j)^(m+j k) (a+b Sin[z]^k)^(n-1)+*)
(*\[Integral](Sin[z]^j)^(m+j k) ((b A+a B)(2j k m+k+1)-2b A(n-1)+(2a A n+(a A+b B)(2j k m+k+1))Sin[z]^k) (a+b Sin[z]^k)^(n-1) \[DifferentialD]z*)


(* ::Subsubsection:: *)
(*Recurrence 11: If  j^2=k^2=1 \[And] a^2-b^2=0, then*)


(* ::Subsubtitle::Bold:: *)
(*a (2j k m+k+1)\[Integral](Sin[z]^j)^m (A+B Sin[z]^k) (a+b Sin[z]^k)^n \[DifferentialD]z=*)
(*2a A Cos[z](Sin[z]^j)^(m+j k) (a+b Sin[z]^k)^n+*)
(*\[Integral](Sin[z]^j)^(m+j k) (a B (2j k m+k+1)-2b A n+a A(2 j k m+2n+k+3)Sin[z]^k) (a+b Sin[z]^k)^n \[DifferentialD]z*)


(* ::Subsubsection:: *)
(*Recurrence 12: If  j^2=k^2=1 \[And] a^2-b^2=0, then*)


(* ::Subsubtitle::Bold:: *)
(*2a^2 (2 n+1)\[Integral](Sin[z]^j)^m (A+B Sin[z]^k) (a+b Sin[z]^k)^n \[DifferentialD]z=*)
(*-2b (b A-a B) Cos[z](Sin[z]^j)^(m+j k) (a+b Sin[z]^k)^n+*)
(*\[Integral](Sin[z]^j)^m (2a A(2 n+1)+(a A-b B)(2j k m+k+1)-(b A-a B)(2j k m+2n+k+3)Sin[z]^k) (a+b Sin[z]^k)^(n+1) \[DifferentialD]z*)


(* ::PageBreak:: *)
(**)
