(* ::Package:: *)

(* ::Title::Bold::Closed:: *)
(*\[Integral]Log[c (a+b (d+e x)^n)^p]\[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Reference: G&R 2.728.1, CRC 499, A&S 4.1.49*)


(* ::Subsubsection:: *)
(*Derivation: Integration by parts*)


(* ::Subsubsection:: *)
(*Rule:*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]Log[c (b (d+e x)^n)^p]\[DifferentialD]x  \[LongRightArrow]  (((d+e x) Log[c (b (d+e x)^n)^p])/e)-n p x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[Log[c_.*(b_.*(d_.+e_.*x_)^n_.)^p_.],x_Symbol] :=
  (d+e*x)*Log[c*(b*(d+e*x)^n)^p]/e - n*p*x /;
FreeQ[{b,c,d,e,n,p},x]


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Reference: G&R 2.728.1*)


(* ::Subsubsection:: *)
(*Derivation: Integration by parts*)


(* ::Subsubsection:: *)
(*Rule: If  n<0, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]Log[c (a+b (d+e x)^n)^p]\[DifferentialD]x  \[LongRightArrow]  (((d+e x) Log[c (a+b (d+e x)^n)^p])/e)-b n p \[Integral]1/(b+a (d+e x)^-n) \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[Log[c_.*(a_+b_.*(d_.+e_.*x_)^n_)^p_.],x_Symbol] :=
  (d+e*x)*Log[c*(a+b*(d+e*x)^n)^p]/e -
  Dist[b*n*p,Int[1/(b+a*(d+e*x)^(-n)),x]] /;
FreeQ[{a,b,c,d,e,p},x] && RationalQ[n] && n<0


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Reference: G&R 2.728.1*)


(* ::Subsubsection:: *)
(*Derivation: Integration by parts*)


(* ::Subsubsection:: *)
(*Rule: If  \[Not](n<0), then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]Log[c (a+b (d+e x)^n)^p]\[DifferentialD]x  \[LongRightArrow]  (((d+e x) Log[c (a+b (d+e x)^n)^p])/e)-n p x+a n p \[Integral]1/(a+b (d+e x)^n) \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[Log[c_.*(a_+b_.*(d_.+e_.*x_)^n_.)^p_.],x_Symbol] :=
  (d+e*x)*Log[c*(a+b*(d+e*x)^n)^p]/e - n*p*x +
  Dist[a*n*p,Int[1/(a+b*(d+e*x)^n),x]] /;
FreeQ[{a,b,c,d,e,n,p},x] && Not[RationalQ[n] && n<0]


(* ::Title::Bold::Closed:: *)
(*\[Integral](a+b Log[c (d+e x)^n])^p \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Reference: CRC 492*)


(* ::Subsubsection:: *)
(*Derivation: Primitive rule*)


(* ::Subsubsection:: *)
(*Basis: \!\( *)
(*\*SubscriptBox[\(\[PartialD]\), \(x\)]\(LogIntegral[x]\)\)=1/Log[x]*)


(* ::Subsubsection:: *)
(*Rule:*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]1/Log[c (d+e x)] \[DifferentialD]x  \[LongRightArrow]  (LogIntegral[c (d+e x)]/(c e))*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[1/Log[c_.*(d_.+e_.*x_)],x_Symbol] :=
  LogIntegral[c*(d+e*x)]/(c*e) /;
FreeQ[{c,d,e},x]


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Derivation: Primitive rule*)


(* ::Subsubsection:: *)
(*Basis: \!\( *)
(*\*SubscriptBox[\(\[PartialD]\), \(x\)]\(ExpIntegralEi[x]\)\)=E^x/x*)


(* ::Subsubsection:: *)
(*Rule:*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]1/(a+b Log[c (d+e x)^n]) \[DifferentialD]x  \[LongRightArrow]  (((d+e x) ExpIntegralEi[(a+b Log[c (d+e x)^n])/(b n)])/(b e n E^(a/(b n)) (c (d+e x)^n)^(1/n)))*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[1/(a_.+b_.*Log[c_.*(d_.+e_.*x_)^n_.]),x_Symbol] :=
  (d+e*x)*ExpIntegralEi[(a+b*Log[c*(d+e*x)^n])/(b*n)]/(b*e*n*E^(a/(b*n))*(c*(d+e*x)^n)^(1/n)) /;
FreeQ[{a,b,c,d,e,n},x]


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Rule: If  b n>0, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]1/Sqrt[a+b Log[c (d+e x)^n]] \[DifferentialD]x  \[LongRightArrow]  ((Sqrt[\[Pi]] Sqrt[b n](d+e x) Erfi[Sqrt[a+b Log[c (d+e x)^n]]/Sqrt[b n]])/(b e n E^(a/(b n)) (c (d+e x)^n)^(1/n)))*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[1/Sqrt[a_.+b_.*Log[c_.*(d_.+e_.*x_)^n_.]],x_Symbol] :=
  Sqrt[Pi]*Rt[b*n,2]*(d+e*x)*Erfi[Sqrt[a+b*Log[c*(d+e*x)^n]]/Rt[b*n,2]]/
    (b*e*n*E^(a/(b*n))*(c*(d+e*x)^n)^(1/n)) /;
FreeQ[{a,b,c,d,e,n},x] && PosQ[b*n]


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Rule: If  \[Not](b n>0), then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]1/Sqrt[a+b Log[c (d+e x)^n]] \[DifferentialD]x  \[LongRightArrow]  ((Sqrt[\[Pi]] Sqrt[-b n] (d+e x) Erf[Sqrt[a+b Log[c (d+e x)^n]]/Sqrt[-b n]])/(b e n E^(a/(b n)) (c (d+e x)^n)^(1/n)))*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[1/Sqrt[a_.+b_.*Log[c_.*(d_.+e_.*x_)^n_.]],x_Symbol] :=
  Sqrt[Pi]*Rt[-b*n,2]*(d+e*x)*Erf[Sqrt[a+b*Log[c*(d+e*x)^n]]/Rt[-b*n,2]]/
    (b*e*n*E^(a/(b*n))*(c*(d+e*x)^n)^(1/n)) /;
FreeQ[{a,b,c,d,e,n},x] && NegQ[b*n]


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Reference: G&R 2.711.1, CRC 490*)


(* ::Subsubsection:: *)
(*Derivation: Integration by parts*)


(* ::Subsubsection:: *)
(*Rule: If  p>0, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral](a+b Log[c (d+e x)^n])^p \[DifferentialD]x  \[LongRightArrow]  (((d+e x) (a+b Log[c (d+e x)^n])^p)/e)-b n p \[Integral](a+b Log[c (d+e x)^n])^(p-1) \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[(a_.+b_.*Log[c_.*(d_.+e_.*x_)^n_.])^p_,x_Symbol] :=
  (d+e*x)*(a+b*Log[c*(d+e*x)^n])^p/e -
  Dist[b*n*p,Int[(a+b*Log[c*(d+e*x)^n])^(p-1),x]] /;
FreeQ[{a,b,c,d,e,n},x] && RationalQ[p] && p>0


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Derivation: Inverted integration by parts*)


(* ::Subsubsection:: *)
(*Rule: If  p<-1, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral](a+b Log[c (d+e x)^n])^p \[DifferentialD]x  \[LongRightArrow]                                                                                                                                   *)
(*                              (((d+e x) (a+b Log[c (d+e x)^n])^(p+1))/(b e n (p+1)))-1/(b n (p+1)) \[Integral](a+b Log[c (d+e x)^n])^(p+1) \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[(a_.+b_.*Log[c_.*(d_.+e_.*x_)^n_.])^p_,x_Symbol] :=
  (d+e*x)*(a+b*Log[c*(d+e*x)^n])^(p+1)/(b*e*n*(p+1)) -
  Dist[1/(b*n*(p+1)),Int[(a+b*Log[c*(d+e*x)^n])^(p+1),x]] /;
FreeQ[{a,b,c,d,e,n},x] && RationalQ[p] && p<-1


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Derivation: Inverted integration by parts*)


(* ::Subsubsection:: *)
(*Rule: If  2p\[NotElement]\[DoubleStruckCapitalZ], then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral](a+b Log[c (d+e x)^n])^p \[DifferentialD]x  \[LongRightArrow]  (((d+e x) Gamma[p+1,-((a+b Log[c (d+e x)^n])/(b n))] (a+b Log[c (d+e x)^n])^p)/(e (-((a+b Log[c (d+e x)^n])/(b n)))^p E^(a/(b n)) (c (d+e x)^n)^(1/n)))*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[(a_.+b_.*Log[c_.*(d_.+e_.*x_)^n_.])^p_,x_Symbol] :=
  (d+e*x)*Gamma[p+1,-(a+b*Log[c*(d+e*x)^n])/(b*n)]*(a+b*Log[c*(d+e*x)^n])^p/
    (e*(-(a+b*Log[c*(d+e*x)^n])/(b*n))^p*E^(a/(b*n))*(c*(d+e*x)^n)^(1/n)) /;
FreeQ[{a,b,c,d,e,n,p},x] && Not[IntegerQ[2*p]]


(* ::PageBreak:: *)
(**)


(* ::Title::Bold::Closed:: *)
(*\[Integral]x^m Log[c (a+b x^n)^p]\[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Reference: G&R 2.728.2*)


(* ::Subsubsection:: *)
(*Derivation: Primitive rule*)


(* ::Subsubsection:: *)
(*Basis: \!\( *)
(*\*SubscriptBox[\(\[PartialD]\), \(x\)]\(PolyLog[2, \(-x\)]\)\)=-(Log[1+x]/x)*)


(* ::Subsubsection:: *)
(*Rule:*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]Log[1+b x^n]/x \[DifferentialD]x  \[LongRightArrow]  -(PolyLog[2,-b x^n]/n)*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[Log[1+b_.*x_^n_.]/x_,x_Symbol] :=
  -PolyLog[2,-b*x^n]/n /;
FreeQ[{b,n},x]


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Derivation: Derivation: Algebraic expansion*)


(* ::Subsubsection:: *)
(*Basis: If a>0, Log[a z]=Log[a]+Log[z]*)


(* ::Subsubsection:: *)
(*Rule: If  a c>0, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]Log[c(a+b x^n)]/x \[DifferentialD]x  \[LongRightArrow]  Log[a c] Log[x]+\[Integral]Log[1+(b x^n)/a]/x \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[Log[c_.*(a_+b_.*x_^n_.)]/x_,x_Symbol] :=
  Log[a*c]*Log[x] +
  Int[Log[1+b*x^n/a]/x,x] /;
FreeQ[{a,b,c,n},x] && PositiveQ[a*c]


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Derivation: Integration by parts*)


(* ::Subsubsection:: *)
(*Rule:*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]Log[c (a+b x^n)^p]/x \[DifferentialD]x  \[LongRightArrow]  ((Log[c (a+b x^n)^p] Log[-((b x^n)/a)])/n)-b p \[Integral](x^(n-1) Log[-((b x^n)/a)])/(a+b x^n) \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[Log[c_.*(a_+b_.*x_^n_.)^p_.]/x_,x_Symbol] :=
  Log[c*(a+b*x^n)^p]*Log[-b*x^n/a]/n -
  Dist[b*p,Int[x^(n-1)*Log[-b*x^n/a]/(a+b*x^n),x]] /;
FreeQ[{a,b,c,n,p},x]


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Reference: G&R 2.728.1, CRC 501, A&S 4.1.50'*)


(* ::Subsubsection:: *)
(*Rule: If  m+1!=0, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]x^m Log[c (b x^n)^p]\[DifferentialD]x  \[LongRightArrow]  ((x^(m+1) Log[c (b x^n)^p])/(m+1))-(n p x^(m+1))/(m+1)^2*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[x_^m_.*Log[c_.*(b_.*x_^n_.)^p_.],x_Symbol] :=
  x^(m+1)*Log[c*(b*x^n)^p]/(m+1) - n*p*x^(m+1)/(m+1)^2 /;
FreeQ[{b,c,m,n,p},x] && NonzeroQ[m+1]


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Reference: G&R 2.728.1, CRC 501, A&S 4.1.50'*)


(* ::Subsubsection:: *)
(*Rule: If  m+1!=0 \[And] m-n+1!=0, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]x^m Log[c (a+b x^n)^p]\[DifferentialD]x  \[LongRightArrow]  ((x^(m+1) Log[c (a+b x^n)^p])/(m+1))-(b n p)/(m+1) \[Integral]x^(m+n)/(a+b x^n) \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[x_^m_.*Log[c_.*(a_+b_.*x_^n_.)^p_.],x_Symbol] :=
  x^(m+1)*Log[c*(a+b*x^n)^p]/(m+1) -
  Dist[b*n*p/(m+1),Int[x^(m+n)/(a+b*x^n),x]] /;
FreeQ[{a,b,c,m,n,p},x] && NonzeroQ[m+1] && NonzeroQ[m-n+1]


(* ::PageBreak:: *)
(**)


(* ::Title::Bold::Closed:: *)
(*\[Integral]x^m (a+b Log[c x^n])^p\[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Rule: If  m+1!=0, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]x^m/(a+b Log[c x^n]) \[DifferentialD]x  \[LongRightArrow]  ((x^(m+1) ExpIntegralEi[((m+1) (a+b Log[c x^n]))/(b n)])/(b n E^((a (m+1))/(b n)) (c x^n)^((m+1)/n)))*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[x_^m_./(a_.+b_.*Log[c_.*x_^n_.]),x_Symbol] :=
  x^(m+1)*ExpIntegralEi[(m+1)*(a+b*Log[c*x^n])/(b*n)]/(b*n*E^(a*(m+1)/(b*n))*(c*x^n)^((m+1)/n)) /;
FreeQ[{a,b,c,m,n},x] && NonzeroQ[m+1]


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Rule: If  m+1!=0 \[And] (m+1)/(b n)>0, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]x^m/Sqrt[a+b Log[c x^n]] \[DifferentialD]x  \[LongRightArrow]  ((Sqrt[\[Pi]] x^(m+1) Erfi[Sqrt[(m+1)/(b n)] Sqrt[a+b Log[c x^n]]])/(b n Sqrt[(m+1)/(b n)] E^((a (m+1))/(b n)) (c x^n)^((m+1)/n)))*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[x_^m_./Sqrt[a_.+b_.*Log[c_.*x_^n_.]],x_Symbol] :=
  Sqrt[Pi]*x^(m+1)*Erfi[Rt[(m+1)/(b*n),2]*Sqrt[a+b*Log[c*x^n]]]/
    (b*n*Rt[(m+1)/(b*n),2]*E^(a*(m+1)/(b*n))*(c*x^n)^((m+1)/n)) /;
FreeQ[{a,b,c,m,n},x] && NonzeroQ[m+1] && PosQ[(m+1)/(b*n)]


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Rule: If  m+1!=0 \[And] \[Not]((m+1)/(b n)>0), then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]x^m/Sqrt[a+b Log[c x^n]] \[DifferentialD]x  \[LongRightArrow]  ((Sqrt[\[Pi]] x^(m+1) Erf[Sqrt[-((m+1)/(b n))] Sqrt[a+b Log[c x^n]]])/(b n Sqrt[-((m+1)/(b n))] E^((a (m+1))/(b n)) (c x^n)^((m+1)/n)))*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[x_^m_./Sqrt[a_.+b_.*Log[c_.*x_^n_.]],x_Symbol] :=
  Sqrt[Pi]*x^(m+1)*Erf[Rt[-(m+1)/(b*n),2]*Sqrt[a+b*Log[c*x^n]]]/
    (b*n*Rt[-(m+1)/(b*n),2]*E^(a*(m+1)/(b*n))*(c*x^n)^((m+1)/n)) /;
FreeQ[{a,b,c,m,n},x] && NonzeroQ[m+1] && NegQ[(m+1)/(b*n)]


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Reference: G&R 2.721.1, CRC 496, A&S 4.1.51*)


(* ::Subsubsection:: *)
(*Derivation: Integration by parts*)


(* ::Subsubsection:: *)
(*Rule: If  m+1!=0 \[And] p>0, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]x^m (a+b Log[c x^n])^p \[DifferentialD]x  \[LongRightArrow]  ((x^(m+1) (a+b Log[c x^n])^p)/(m+1))-(b n p)/(m+1) \[Integral]x^m (a+b Log[c x^n])^(p-1) \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[x_^m_.*(a_.+b_.*Log[c_.*x_^n_.])^p_,x_Symbol] :=
  x^(m+1)*(a+b*Log[c*x^n])^p/(m+1) -
  Dist[b*n*p/(m+1),Int[x^m*(a+b*Log[c*x^n])^(p-1),x]] /;
FreeQ[{a,b,c,m,n},x] && NonzeroQ[m+1] && RationalQ[p] && p>0


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Reference: G&R 2.724.1, CRC 495*)


(* ::Subsubsection:: *)
(*Derivation: Inverted integration by parts*)


(* ::Subsubsection:: *)
(*Rule: If  m+1!=0 \[And] p<-1, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]x^m (a+b Log[c x^n])^p \[DifferentialD]x  \[LongRightArrow]  ((x^(m+1) (a+b Log[c x^n])^p)/(m+1))-(b n p)/(m+1) \[Integral]x^m (a+b Log[c x^n])^(p-1) \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[x_^m_.*(a_.+b_.*Log[c_.*x_^n_.])^p_,x_Symbol] :=
  x^(m+1)*(a+b*Log[c*x^n])^(p+1)/(b*n*(p+1)) -
  Dist[(m+1)/(b*n*(p+1)),Int[x^m*(a+b*Log[c*x^n])^(p+1),x]] /;
FreeQ[{a,b,c,m,n},x] && NonzeroQ[m+1] && RationalQ[p] && p<-1


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Rule: If  m+1!=0, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]x^m (a+b Log[c x^n])^p \[DifferentialD]x  \[LongRightArrow]  ((x^(m+1) Gamma[p+1,-(((m+1) (a+b Log[c x^n]))/(b n))] (a+b Log[c x^n])^p)/((m+1) E^((a (m+1))/(b n)) (c x^n)^((m+1)/n) (-(((m+1) (a+b Log[c x^n]))/(b n)))^p))*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[x_^m_.*(a_.+b_.*Log[c_.*x_^n_.])^p_,x_Symbol] :=
  x^(m+1)*Gamma[p+1,-(m+1)*(a+b*Log[c*x^n])/(b*n)]*(a+b*Log[c*x^n])^p/
    ((m+1)*E^(a*(m+1)/(b*n))*(c*x^n)^((m+1)/n)*(-(m+1)*(a+b*Log[c*x^n])/(b*n))^p) /;
FreeQ[{a,b,c,m,n,p},x] && NonzeroQ[m+1]


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Note: Need a rule for arbitrarily deep nesting of powers!*)


(* ::Subsubsection:: *)
(*Rule:*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]Log[a (b x^n)^p]^q \[DifferentialD]x  \[LongRightArrow]  Subst[\[Integral]Log[x^(n p)]^q \[DifferentialD]x,x^(n p),a (b x^n)^p]*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[Log[a_.*(b_.*x_^n_.)^p_]^q_.,x_Symbol] :=
  Subst[Int[Log[x^(n*p)]^q,x],x^(n*p),a*(b*x^n)^p] /;
FreeQ[{a,b,n,p,q},x]


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Rule:*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]Log[a (b (c x^n)^p)^q]^r \[DifferentialD]x  \[LongRightArrow]  Subst[\[Integral]Log[x^(n p q)]^r \[DifferentialD]x,x^(n p q),a (b (c x^n)^p)^q]*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[Log[a_.*(b_.*(c_.*x_^n_.)^p_)^q_]^r_.,x_Symbol] :=
  Subst[Int[Log[x^(n*p*q)]^r,x],x^(n*p*q),a*(b*(c*x^n)^p)^q] /;
FreeQ[{a,b,c,n,p,q,r},x]


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Rule: If  m+1!=0, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]x^m Log[a (b x^n)^p]^q \[DifferentialD]x  \[LongRightArrow]  Subst[\[Integral]x^m Log[x^(n p)]^q \[DifferentialD]x,x^(n p),a (b x^n)^p]*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[x_^m_.*Log[a_.*(b_.*x_^n_.)^p_]^q_.,x_Symbol] :=
  Subst[Int[x^m*Log[x^(n*p)]^q,x],x^(n*p),a*(b*x^n)^p] /;
FreeQ[{a,b,m,n,p,q},x] && NonzeroQ[m+1] && Not[x^(n*p)===a*(b*x^n)^p]


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Rule: If  m+1!=0, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]x^m Log[a (b (c x^n)^p)^q]^r \[DifferentialD]x  \[LongRightArrow]  Subst[\[Integral]x^m Log[x^(n p q)]^r \[DifferentialD]x,x^(n p q),a (b (c x^n)^p)^q]*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[x_^m_.*Log[a_.*(b_.*(c_.*x_^n_.)^p_)^q_]^r_.,x_Symbol] :=
  Subst[Int[x^m*Log[x^(n*p*q)]^r,x],x^(n*p*q),a*(b*(c*x^n)^p)^q] /;
FreeQ[{a,b,c,m,n,p,q,r},x] && NonzeroQ[m+1] && Not[x^(n*p*q)===a*(b*(c*x^n)^p)^q]


(* ::PageBreak:: *)
(**)


(* ::Title::Bold::Closed:: *)
(*\[Integral]x^m Log[c (a+b x)^n]^p \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Rule: If  m>0 \[And] p>0, then*)


(* ::Subsubsection:: *)
(*Rule:*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]x^m Log[c (a+b x)^n]^p \[DifferentialD]x  \[LongRightArrow]  ((x^m (a+b x) Log[c (a+b x)^n]^p)/(b (m+1)))-                                                 *)
(*                        (a m)/(b (m+1)) \[Integral]x^(m-1) Log[c (a+b x)^n]^p \[DifferentialD]x-(n p)/(m+1) \[Integral]x^m Log[c (a+b x)^n]^(p-1) \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[x_^m_.*Log[c_.*(a_+b_.*x_)^n_.]^p_,x_Symbol] :=
  x^m*(a+b*x)*Log[c*(a+b*x)^n]^p/(b*(m+1)) -
  Dist[a*m/(b*(m+1)),Int[x^(m-1)*Log[c*(a+b*x)^n]^p,x]] -
  Dist[n*p/(m+1),Int[x^m*Log[c*(a+b*x)^n]^(p-1),x]] /;
FreeQ[{a,b,c,n},x] && RationalQ[{m,p}] && m>0 && p>0


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Rule: If  p>0, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]Log[c (a+b x)^n]^p/x^2 \[DifferentialD]x  \[LongRightArrow]  -(((a+b x) Log[c (a+b x)^n]^p)/(a x))+(b n p)/a \[Integral]Log[c (a+b x)^n]^(p-1)/x \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[Log[c_.*(a_+b_.*x_)^n_.]^p_/x_^2,x_Symbol] :=
  -(a+b*x)*Log[c*(a+b*x)^n]^p/(a*x) +
  Dist[b*n*p/a,Int[Log[c*(a+b*x)^n]^(p-1)/x,x]] /;
FreeQ[{a,b,c,n},x] && RationalQ[p] && p>0


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Rule: If  m<-1 \[And] m!=-2 \[And] p>0, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]x^m Log[c (a+b x)^n]^p \[DifferentialD]x  \[LongRightArrow]  ((x^(m+1) (a+b x) Log[c (a+b x)^n]^p)/(a (m+1)))-                                                                  *)
(*                                             (b (m+2))/(a (m+1)) \[Integral]x^(m+1) Log[c (a+b x)^n]^p \[DifferentialD]x-(b n p)/(a (m+1)) \[Integral]x^(m+1) Log[c (a+b x)^n]^(p-1) \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[x_^m_.*Log[c_.*(a_+b_.*x_)^n_.]^p_,x_Symbol] :=
  x^(m+1)*(a+b*x)*Log[c*(a+b*x)^n]^p/(a*(m+1)) -
  Dist[(b*(m+2))/(a*(m+1)),Int[x^(m+1)*Log[c*(a+b*x)^n]^p,x]] -
  Dist[b*n*p/(a*(m+1)),Int[x^(m+1)*Log[c*(a+b*x)^n]^(p-1),x]] /;
FreeQ[{a,b,c,n},x] && RationalQ[{m,p}] && m<-1 && m!=-2 && p>0


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Rule: If  m\[Element]\[DoubleStruckCapitalZ] \[And] m>0 \[And] \[Not](p\[Element]\[DoubleStruckCapitalQ] \[And] p>0), then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]x^m Log[c (a+b x)^n]^p \[DifferentialD]x  \[LongRightArrow]  (1/b)Subst[\[Integral](-(a/b)+x/b)^m Log[c x^n]^p \[DifferentialD]x,x,a+b x]*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[x_^m_.*Log[c_.*(a_+b_.*x_)^n_.]^p_,x_Symbol] :=
  Dist[1/b,Subst[Int[(-a/b+x/b)^m*Log[c*x^n]^p,x],x,a+b*x]] /;
FreeQ[{a,b,c,n,p},x] && IntegerQ[m] && m>0 && Not[RationalQ[p] && p>0]


(* ::PageBreak:: *)
(**)


(* ::Title::Bold::Closed:: *)
(*\[Integral]Log[c (a+b x)^n]^p/(d+e x)^m \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Reference: G&R 2.728.2*)


(* ::Subsubsection:: *)
(*Derivation: Primitive rule*)


(* ::Subsubsection:: *)
(*Basis: \!\( *)
(*\*SubscriptBox[\(\[PartialD]\), \(x\)]\((\(-*)
(*\*FractionBox[\(PolyLog[2, d + e\ x]\), \(e\)]\))\)\)=Log[1-d-e x]/(d+e x)*)


(* ::Subsubsection:: *)
(*Rule: If a c e-b c d-e=0, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]Log[c (a+b x)]/(d+e x) \[DifferentialD]x  \[LongRightArrow]  -(PolyLog[2,1-a c-b c x]/e)*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[Log[c_.*(a_.+b_.*x_)]/(d_+e_.*x_),x_Symbol] :=
  -PolyLog[2,1-a*c-b*c*x]/e /;
FreeQ[{a,b,c,d,e},x] && ZeroQ[a*c*e-b*c*d-e]


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Derivation: Integration by parts*)


(* ::Subsubsection:: *)
(*Rule: If  b d-a e!=0, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]Log[c (a+b x)^n]/(d+e x) \[DifferentialD]x  \[LongRightArrow]  (1/e) Log[c (a+b x)^n] Log[(b (d+e x))/(b d-a e)]+n/e PolyLog[2,-((e (a+b x))/(b d-a e))]*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[Log[c_.*(a_.+b_.*x_)^n_.]/(d_+e_.*x_),x_Symbol] :=
  Log[c*(a+b*x)^n]*Log[b*(d+e*x)/(b*d-a*e)]/e +
  n*PolyLog[2,-e*(a+b*x)/(b*d-a*e)]/e /;
FreeQ[{a,b,c,d,e,n},x] && NonzeroQ[b*d-a*e]


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Derivation: Integration by parts*)


(* ::Subsubsection:: *)
(*Rule: If  p>0 \[And] b d-a e!=0, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]Log[c (a+b x)^n]^p/(d+e x) \[DifferentialD]x  \[LongRightArrow]  *)
(*(1/e) Log[c (a+b x)^n]^p Log[(b (d+e x))/(b d-a e)]-(b n p)/e \[Integral](Log[c (a+b x)^n]^(p-1) Log[(b (d+e x))/(b d-a e)])/(a+b x) \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[Log[c_.*(a_+b_.*x_)^n_.]^p_./(d_.+e_.*x_),x_Symbol] :=
  Log[c*(a+b*x)^n]^p*Log[b*(d+e*x)/(b*d-a*e)]/e -
  Dist[b*n*p/e,Int[Log[c*(a+b*x)^n]^(p-1)*Log[b*(d+e*x)/(b*d-a*e)]/(a+b*x),x]] /;
FreeQ[{a,b,c,d,e,n},x] && RationalQ[p] && p>0 && NonzeroQ[b*d-a*e]


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Note: Log[z]=-PolyLog[1,1-z]*)


(* ::Subsubsection:: *)
(*Rule: If  p>0 \[And] b d-a e=0 \[And] a g h-b (f h-1)=0, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral](Log[c (a+b x)^n]^p Log[h(f+g x)])/(d+e x) \[DifferentialD]x  \[LongRightArrow]  -((Log[c (a+b x)^n]^p PolyLog[2,1-h (f+g x)])/e)+*)
(*(b n p)/e \[Integral](Log[c (a+b x)^n]^(p-1) PolyLog[2,1-h (f+g x)])/(a+b x) \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[Log[c_.*(a_+b_.*x_)^n_.]^p_.*Log[h_.*(f_.+g_.*x_)]/(d_+e_.*x_),x_Symbol] :=
  Module[{q=Simplify[1-h*(f+g*x)]},
  -Log[c*(a+b*x)^n]^p*PolyLog[2,q]/e +
  Dist[b*n*p/e,Int[Log[c*(a+b*x)^n]^(p-1)*PolyLog[2,q]/(a+b*x),x]]] /;
FreeQ[{a,b,c,d,e,f,g,h,n},x] && RationalQ[p] && p>0 && ZeroQ[b*d-a*e] && ZeroQ[a*g*h-b*(f*h-1)]


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Rule: If  p>0 \[And] b d-a e=0 \[And] a g -b f=0, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral](Log[c (a+b x)^n]^p PolyLog[m,h(f+g x)])/(d+e x) \[DifferentialD]x  \[LongRightArrow]  *)
(*((Log[c (a+b x)^n]^p PolyLog[m+1,h (f+g x)])/e)-(b n p)/e \[Integral](Log[c (a+b x)^n]^(p-1) PolyLog[m+1,h (f+g x)])/(a+b x) \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[Log[c_.*(a_+b_.*x_)^n_.]^p_.*PolyLog[m_,h_.*(f_.+g_.*x_)]/(d_+e_.*x_),x_Symbol] :=
  Log[c*(a+b*x)^n]^p*PolyLog[m+1,h*(f+g*x)]/e -
  Dist[b*n*p/e,Int[Log[c*(a+b*x)^n]^(p-1)*PolyLog[m+1,h*(f+g*x)]/(a+b*x),x]] /;
FreeQ[{a,b,c,d,e,f,g,h,m,n},x] && RationalQ[p] && p>0 && ZeroQ[b*d-a*e] && ZeroQ[a*g-b*f]


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Derivation: Integration by parts*)


(* ::Subsubsection:: *)
(*Rule: If  m,p\[Element]\[DoubleStruckCapitalZ] \[And] m<-1 \[And] p>0, then*)


(* ::Subsubsection:: *)
(*Rule:*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral](d+e x)^m Log[c (a+b x)^n]^p \[DifferentialD]x  \[LongRightArrow]  *)
(*(((d+e x)^(m+1) Log[c (a+b x)^n]^p)/(e (m+1)))-(b n p)/(e (m+1)) \[Integral]((d+e x)^(m+1) Log[c (a+b x)^n]^(p-1))/(a+b x) \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[(d_.+e_.*x_)^m_.*Log[c_.*(a_.+b_.*x_)^n_.]^p_,x_Symbol] :=
  (d+e*x)^(m+1)*Log[c*(a+b*x)^n]^p/(e*(m+1)) -
  Dist[b*n*p/(e*(m+1)),Int[Regularize[(d+e*x)^(m+1)*Log[c*(a+b*x)^n]^(p-1)/(a+b*x),x],x]] /;
FreeQ[{a,b,c,d,e,n},x] && IntegersQ[m,p] && m<-1 && p>0


(* ::PageBreak:: *)
(**)


(* ::Title::Bold::Closed:: *)
(*\[Integral]Log[c (a+b x^m)^n]^p \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Note: The b/x in the resulting integrand will be transformed to b x by the rule \[Integral]f[x^n]/x \[DifferentialD]x \[LongRightArrow] (Subst[\[Integral]f[x]/x \[DifferentialD]x,x,x^n]/n)*)


(* ::Subsubsection:: *)
(*Rule: If  p\[Element]\[DoubleStruckCapitalZ] \[And] p>0, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]Log[c (a+b/x)^n]^p \[DifferentialD]x  \[LongRightArrow]  (((b+a x) Log[c (a+b/x)^n]^p)/a)+(b n p)/a \[Integral]Log[c (a+b/x)^n]^(p-1)/x \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[Log[c_.*(a_+b_./x_)^n_.]^p_, x_Symbol] :=
  (b+a*x)*Log[c*(a+b/x)^n]^p/a + 
  Dist[b/a*n*p,Int[Log[c*(a+b/x)^n]^(p-1)/x,x]] /;
FreeQ[{a,b,c,n},x] && IntegerQ[p] && p>0


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Rule:*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]Log[c (a+b x^2)^n]^2 \[DifferentialD]x  \[LongRightArrow]  x Log[c (a+b x^2)^n]^2+8 n^2 x-4 n x Log[c (a+b x^2)^n]+1/Sqrt[-b] (n Sqrt[a])*)
(*             (4 n Log[(-Sqrt[a]+Sqrt[-b] x)/(Sqrt[a]+Sqrt[-b] x)]-4 n ArcTanh[(Sqrt[-b] x)/Sqrt[a]] (Log[-(Sqrt[a]/Sqrt[-b])+x]+Log[Sqrt[a]/Sqrt[-b]+x])-*)
(*   n Log[-(Sqrt[a]/Sqrt[-b])+x]^2+n Log[Sqrt[a]/Sqrt[-b]+x]^2-2 n Log[Sqrt[a]/Sqrt[-b]+x] Log[1/2-(Sqrt[-b] x)/(2 Sqrt[a])]+*)
(*            2 n Log[-(Sqrt[a]/Sqrt[-b])+x] Log[1/2 (1+(Sqrt[-b] x)/Sqrt[a])]+4 ArcTanh[(Sqrt[-b] x)/Sqrt[a]] Log[c (a+b x^2)^n]+*)
(*2 n PolyLog[2,1/2-(Sqrt[-b] x)/(2 Sqrt[a])]-2 n PolyLog[2,1/2 (1+(Sqrt[-b] x)/Sqrt[a])])                          *)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[Log[c_.*(a_+b_.*x_^2)^n_.]^2, x_Symbol] :=
  x*Log[c*(a+b*x^2)^n]^2 + 
    8*n^2*x -
    4*n*x*Log[c*(a+b*x^2)^n] + 
    (n*Sqrt[a]/Sqrt[-b])*( 
      4*n*Log[(-Sqrt[a]+Sqrt[-b]*x)/(Sqrt[a]+Sqrt[-b]*x)] - 
      4*n*ArcTanh[Sqrt[-b]*x/Sqrt[a]]*(Log[-Sqrt[a]/Sqrt[-b]+x] + Log[Sqrt[a]/Sqrt[-b]+x]) -
      n*Log[-Sqrt[a]/Sqrt[-b]+x]^2 + 
      n*Log[Sqrt[a]/Sqrt[-b]+x]^2 - 
      2*n*Log[Sqrt[a]/Sqrt[-b]+x]*Log[1/2-Sqrt[-b]*x/(2*Sqrt[a])] + 
      2*n*Log[-Sqrt[a]/Sqrt[-b]+x]*Log[(1+Sqrt[-b]*x/Sqrt[a])/2] + 
      4*ArcTanh[Sqrt[-b]*x/Sqrt[a]]*Log[c*(a+b*x^2)^n] + 
      2*n*PolyLog[2,1/2-Sqrt[-b]*x/(2*Sqrt[a])] - 
      2*n*PolyLog[2,(1+Sqrt[-b]*x/Sqrt[a])/2]) /;
FreeQ[{a,b,c,n},x]


(* ::PageBreak:: *)
(**)


(* ::Title::Bold::Closed:: *)
(*\[Integral]Log[d (a+b x+c x^2)^n]^p \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Derivation: Integration by parts*)


(* ::Subsubsection:: *)
(*Rule:*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]Log[d (a+x (b+c x))^n]^2 \[DifferentialD]x  \[LongRightArrow]  x Log[d (a+b x+c x^2)^n]^2-                                 *)
(*                      2 b n \[Integral](x Log[d (a+b x+c x^2)^n])/(a+b x+c x^2) \[DifferentialD]x-4 c n \[Integral](x^2 Log[d (a+b x+c x^2)^n])/(a+b x+c x^2) \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[Log[d_.*(a_.+b_.*x_+c_.*x_^2)^n_.]^2,x_Symbol] :=
  x*Log[d*(a+b*x+c*x^2)^n]^2 -
  Dist[2*b*n,Int[x*Log[d*(a+b*x+c*x^2)^n]/(a+b*x+c*x^2),x]] - 
  Dist[4*c*n,Int[x^2*Log[d*(a+b*x+c*x^2)^n]/(a+b*x+c*x^2),x]] /;
FreeQ[{a,b,c,d,n},x]


(* ::PageBreak:: *)
(**)


(* ::Title::Bold::Closed:: *)
(*\[Integral]x^m Log[a Log[b x^n]^p]\[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Derivation: Integration by parts*)


(* ::Subsubsection:: *)
(*Rule:*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]Log[a Log[b x^n]^p]\[DifferentialD]x  \[LongRightArrow]  x Log[a Log[b x^n]^p]-n p \[Integral]1/Log[b x^n] \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[Log[a_.*Log[b_.*x_^n_.]^p_.],x_Symbol] :=
  x*Log[a*Log[b*x^n]^p] - 
  Dist[n*p,Int[1/Log[b*x^n],x]] /;
FreeQ[{a,b,n,p},x]


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Derivation: Integration by parts*)


(* ::Subsubsection:: *)
(*Rule:*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]Log[a Log[b x^n]^p]/x \[DifferentialD]x  \[LongRightArrow]  ((Log[b x^n] (-p+Log[a Log[b x^n]^p]))/n)*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[Log[a_.*Log[b_.*x_^n_.]^p_.]/x_,x_Symbol] :=
  Log[b*x^n]*(-p+Log[a*Log[b*x^n]^p])/n /;
FreeQ[{a,b,n,p},x]


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Derivation: Integration by parts*)


(* ::Subsubsection:: *)
(*Rule: If  m+1!=0, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]x^m Log[a Log[b x^n]^p]\[DifferentialD]x  \[LongRightArrow]  ((x^(m+1) Log[a Log[b x^n]^p])/(m+1))-(n p)/(m+1) \[Integral]x^m/Log[b x^n] \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[x_^m_.*Log[a_.*Log[b_.*x_^n_.]^p_.],x_Symbol] :=
  x^(m+1)*Log[a*Log[b*x^n]^p]/(m+1) - 
  Dist[n*p/(m+1),Int[x^m/Log[b*x^n],x]] /;
FreeQ[{a,b,m,n,p},x] && NonzeroQ[m+1]


(* ::PageBreak:: *)
(**)


(* ::Title::Bold::Closed:: *)
(*\[Integral]Log[(a+b x)/(c+d x)]^m/x \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Basis: f[(a+b x)/(c+d x)]/x=f[a/c+((b c-a d) x)/(c(c+d x))]/(((b c-a d) x)/(c+d x)) \!\( *)
(*\*SubscriptBox[\(\[PartialD]\), \(x\)]*)
(*\*FractionBox[\(\((b\ c - a\ d)\)\ x\), \(c + d\ x\)]\)-f[b/d-(b c-a d)/((c+d x) d)]/((b c-a d)/(c+d x)) \!\( *)
(*\*SubscriptBox[\(\[PartialD]\), \(x\)]\(( *)
(*\*FractionBox[\(b\ c - a\ d\), \(c + d\ x\)])\)\)*)


(* ::Subsubsection:: *)
(*Note: This linearizing substitution is valid for any function of (a+b x)/(c+d x) over x.*)


(* ::Subsubsection:: *)
(*Rule: If  m\[Element]\[DoubleStruckCapitalZ] \[And] m>0 \[And] b c-a d!=0, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]Log[(a+b x)/(c+d x)]^m/x \[DifferentialD]x  \[LongRightArrow]  Subst[\[Integral]Log[a/c+x/c]^m/x \[DifferentialD]x,x,((b c-a d) x)/(c+d x)]-Subst[\[Integral]Log[b/d-x/d]^m/x \[DifferentialD]x,x,(b c-a d)/(c+d x)]*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[Log[(a_.+b_.*x_)/(c_+d_.*x_)]^m_./x_,x_Symbol] :=
  Subst[Int[Log[a/c+x/c]^m/x,x],x,(b*c-a*d)*x/(c+d*x)] - 
  Subst[Int[Log[b/d-x/d]^m/x,x],x,(b*c-a*d)/(c+d*x)] /;
FreeQ[{a,b,c,d},x] && IntegerQ[m] && m>0 && NonzeroQ[b*c-a*d]


(* ::PageBreak:: *)
(**)


(* ::Title::Bold::Closed:: *)
(*\[Integral](A+B Log[c+d x])/Sqrt[a+b Log[c+d x]] \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Derivation: Algebraic expansion*)


(* ::Subsubsection:: *)
(*Basis: (A+B z)/Sqrt[a+b z]=(b A-a B)/(b Sqrt[a+b z])+(B Sqrt[a+b z])/b*)


(* ::Subsubsection:: *)
(*Rule: If  b A-a B!=0, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral](A+B Log[c+d x])/Sqrt[a+b Log[c+d x]] \[DifferentialD]x  \[LongRightArrow]  ((b A-a B)/b)\[Integral]1/Sqrt[a+b Log[c+d x]] \[DifferentialD]x+B/b \[Integral]Sqrt[a+b Log[c+d x]]\[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[(A_.+B_.*Log[c_.+d_.*x_])/Sqrt[a_+b_.*Log[c_.+d_.*x_]],x_Symbol] :=
  Dist[(b*A-a*B)/b,Int[1/Sqrt[a+b*Log[c+d*x]],x]] +
  Dist[B/b,Int[Sqrt[a+b*Log[c+d*x]],x]] /;
FreeQ[{a,b,c,d,A,B},x] && NonzeroQ[b*A-a*B]


(* ::PageBreak:: *)
(**)


(* ::Title::Bold::Closed:: *)
(*\[Integral]f^(a Log[u]) \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Derivation: Algebraic simplification*)


(* ::Subsubsection:: *)
(*Basis: f^(a Log[g])=g^(a Log[f])*)


(* ::Subsubsection:: *)
(*Rule:*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]f^(a Log[u]) \[DifferentialD]x  \[LongRightArrow]  \[Integral]u^(a Log[f]) \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[f_^(a_.*Log[u_]),x_Symbol] :=
  Int[u^(a*Log[f]),x] /;
FreeQ[{a,f},x]


(* ::PageBreak:: *)
(**)


(* ::Title::Bold::Closed:: *)
(*\[Integral]f[Log[a x^n]]/x \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Derivation: Integration by substitution*)


(* ::Subsubsection:: *)
(*Basis: f[Log[a x^n]]/x=1/n f[Log[a x^n]] \!\( *)
(*\*SubscriptBox[\(\[PartialD]\), \(x\)]\(Log[a\ *)
(*\*SuperscriptBox[\(x\), \(n\)]]\)\)*)


(* ::Subsubsection:: *)
(*Rule:*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]f[Log[a x^n]]/x \[DifferentialD]x  \[LongRightArrow]  (1/n) Subst[\[Integral]f[x]\[DifferentialD]x,x,Log[a x^n]]*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
If[ShowSteps,

Int[u_/x_,x_Symbol] :=
  Module[{lst=FunctionOfLog[u,x]},
  ShowStep["","Int[f[Log[a*x^n]]/x,x]","Subst[Int[f[x],x],x,Log[a*x^n]]/n",Hold[
  Dist[1/lst[[3]],Subst[Int[lst[[1]],x],x,Log[lst[[2]]]]]]] /;
 Not[FalseQ[lst]]] /;
SimplifyFlag && NonsumQ[u],

Int[u_/x_,x_Symbol] :=
  Module[{lst=FunctionOfLog[u,x]},
  Dist[1/lst[[3]],Subst[Int[lst[[1]],x],x,Log[lst[[2]]]]] /;
 Not[FalseQ[lst]]] /;
NonsumQ[u]]


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Derivation: Algebraic simplification*)


(* ::Subsubsection:: *)
(*Basis: 1/(a x+b x z)=1/(x (a+b z))*)


(* ::Subsubsection:: *)
(*Rule:*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]1/(a x+b x Log[c x^n]^m) \[DifferentialD]x  \[LongRightArrow]  \[Integral]1/(x(a+b Log[c x^n]^m)) \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[1/(a_.*x_+b_.*x_*Log[c_.*x_^n_.]^m_.),x_Symbol] :=
  Int[1/(x*(a+b*Log[c*x^n]^m)),x] /;
FreeQ[{a,b,c,m,n},x]


(* ::PageBreak:: *)
(**)


(* ::Title::Bold::Closed:: *)
(*\[Integral]Log[c+d f^(a+b x)]\[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Derivation: Primitive rule*)


(* ::Subsubsection:: *)
(*Basis: \!\( *)
(*\*SubscriptBox[\(\[PartialD]\), \(x\)]\(PolyLog[2, \(-c\)\ *)
(*\*SuperscriptBox[\(E\), \(x\)]]\)\)=-Log[1+c E^x]*)


(* ::Subsubsection:: *)
(*Rule:*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]Log[1+c f^(a+b x)]\[DifferentialD]x  \[LongRightArrow]  -(PolyLog[2,-c f^(a+b x)]/(b Log[f]))*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[Log[1+c_.*f_^(a_.+b_.*x_)],x_Symbol] :=
  -PolyLog[2,-c*f^(a+b*x)]/(b*Log[f]) /;
FreeQ[{a,b,c,f},x]


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Derivation: Integration by parts*)


(* ::Subsubsection:: *)
(*Basis: \!\( *)
(*\*SubscriptBox[\(\[PartialD]\), \(x\)]\(Log[c + d\ g[x]]\)\)=\!\( *)
(*\*SubscriptBox[\(\[PartialD]\), \(x\)]\(Log[1 + *)
(*\*FractionBox[\(d\ g[x]\), \(c\)]]\)\)*)


(* ::Subsubsection:: *)
(*Rule: If c!=1, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]Log[c+d f^(a+b x)]\[DifferentialD]x  \[LongRightArrow]  x Log[c+d f^(a+b x)]-x Log[1+(d f^(a+b x))/c]+\[Integral]Log[1+(d f^(a+b x))/c]\[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[Log[c_+d_.*f_^(a_.+b_.*x_)],x_Symbol] :=
  x*Log[c+d*f^(a+b*x)] - x*Log[1+d/c*f^(a+b*x)] +
  Int[Log[1+d/c*f^(a+b*x)],x] /;
FreeQ[{a,b,c,d,f},x] && NonzeroQ[c-1]


(* ::PageBreak:: *)
(**)


(* ::Title::Bold::Closed:: *)
(*\[Integral]x^m Log[c+d f^(a+b x)]\[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Derivation: Integration by parts*)


(* ::Subsubsection:: *)
(*Rule: If m>0, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]x^m Log[1+c f^(a+b x)]\[DifferentialD]x  \[LongRightArrow]  -((x^m PolyLog[2,-c f^(a+b x)])/(b Log[f]))+m/(b Log[f]) \[Integral]x^(m-1) PolyLog[2,-c f^(a+b x)]\[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[x_^m_.*Log[1+c_.*f_^(a_.+b_.*x_)],x_Symbol] :=
  -x^m*PolyLog[2,-c*f^(a+b*x)]/(b*Log[f]) +
  Dist[m/(b*Log[f]),Int[x^(m-1)*PolyLog[2,-c*f^(a+b*x)],x]] /;
FreeQ[{a,b,c,f},x] && RationalQ[m] && m>0


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Derivation: Integration by parts*)


(* ::Subsubsection:: *)
(*Basis: \!\( *)
(*\*SubscriptBox[\(\[PartialD]\), \(x\)]\(Log[c + d\ g[x]]\)\)=\!\( *)
(*\*SubscriptBox[\(\[PartialD]\), \(x\)]\(Log[1 + *)
(*\*FractionBox[\(d\ g[x]\), \(c\)]]\)\)*)


(* ::Subsubsection:: *)
(*Rule: If c!=1 \[And] m>0, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]x^m Log[c+d f^(a+b x)]\[DifferentialD]x  \[LongRightArrow]  ((x^(m+1) Log[c+d f^(a+b x)])/(m+1))-(x^(m+1) Log[1+(d f^(a+b x))/c])/(m+1)+\[Integral]x^m Log[1+(d f^(a+b x))/c]\[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[x_^m_.*Log[c_+d_.*f_^(a_.+b_.*x_)],x_Symbol] :=
  x^(m+1)*Log[c+d*f^(a+b*x)]/(m+1) - x^(m+1)*Log[1+d/c*f^(a+b*x)]/(m+1) +
  Int[x^m*Log[1+d/c*f^(a+b*x)],x] /;
FreeQ[{a,b,c,d,f},x] && NonzeroQ[c-1] && RationalQ[m] && m>0


(* ::PageBreak:: *)
(**)


(* ::Title::Bold::Closed:: *)
(*\[Integral]Log[u]\[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Reference: A&S 4.1.53*)


(* ::Subsubsection:: *)
(*Derivation: Integration by parts*)


(* ::Subsubsection:: *)
(*Rule: If u is an algebraic function of x, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]Log[u]\[DifferentialD]x  \[LongRightArrow]  x Log[u]-\[Integral](x \!\( *)
(*\*SubscriptBox[\(\[PartialD]\), \(x\)]u\))/u \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[Log[u_],x_Symbol] :=
  x*Log[u] -
  Int[Regularize[x*D[u,x]/u,x],x] /;
AlgebraicFunctionQ[u,x]


(* ::PageBreak:: *)
(**)
