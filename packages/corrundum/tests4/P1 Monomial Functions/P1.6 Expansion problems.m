(* ::Package:: *)

(* ::Title:: *)
(*Expansion and Simplification Problems*)


(* ::Section::Closed:: *)
(*Integrands of the form x^m (a+b x+c x^2)^p (d+e x+f x^2)^q*)


(* ::Subsection::Closed:: *)
(*Integrands of the form x^m (a+b x+c x^2)^(p/2) / (d+e x+f x^2) when b=0*)


(* ::Subsubsection::Closed:: *)
(*p>0*)


{x^2*(a + c*x^2)^(1/2)/(d + e*x + f*x^2), x, 10, -((e*Sqrt[a + c*x^2])/f^2) + (x*Sqrt[a + c*x^2])/(2*f) + (a*ArcTanh[(Sqrt[c]*x)/Sqrt[a + c*x^2]])/(2*Sqrt[c]*f) + (Sqrt[c]*(e^2 - d*f)*ArcTanh[(Sqrt[c]*x)/Sqrt[a + c*x^2]])/f^3 - ((e*(e - Sqrt[e^2 - 4*d*f])*(a*f^2 + c*(e^2 - 2*d*f)) - 2*d*f*(a*f^2 + c*(e^2 - d*f)))*ArcTanh[(2*a*f - c*(e - Sqrt[e^2 - 4*d*f])*x)/(Sqrt[4*a*f^2 + c*(e - Sqrt[e^2 - 4*d*f])^2]*Sqrt[a + c*x^2])])/(f^3*Sqrt[e^2 - 4*d*f]*Sqrt[4*a*f^2 + c*(e - Sqrt[e^2 - 4*d*f])^2]) + ((e*(e + Sqrt[e^2 - 4*d*f])*(a*f^2 + c*(e^2 - 2*d*f)) - 2*d*f*(a*f^2 + c*(e^2 - d*f)))*ArcTanh[(2*a*f - c*(e + Sqrt[e^2 - 4*d*f])*x)/(Sqrt[4*a*f^2 + c*(e + Sqrt[e^2 - 4*d*f])^2]*Sqrt[a + c*x^2])])/(f^3*Sqrt[e^2 - 4*d*f]*Sqrt[4*a*f^2 + c*(e + Sqrt[e^2 - 4*d*f])^2])}
{x^1*(a + c*x^2)^(1/2)/(d + e*x + f*x^2), x, 6, Sqrt[a + c*x^2]/f - (Sqrt[c]*e*ArcTanh[(Sqrt[c]*x)/Sqrt[a + c*x^2]])/f^2 - ((2*c*d*e*f - (e - Sqrt[e^2 - 4*d*f])*(a*f^2 + c*(e^2 - d*f)))*ArcTanh[(2*a*f - c*(e - Sqrt[e^2 - 4*d*f])*x)/(Sqrt[4*a*f^2 + c*(e - Sqrt[e^2 - 4*d*f])^2]*Sqrt[a + c*x^2])])/(f^2*Sqrt[e^2 - 4*d*f]*Sqrt[4*a*f^2 + c*(e - Sqrt[e^2 - 4*d*f])^2]) + ((2*c*d*e*f - (e + Sqrt[e^2 - 4*d*f])*(a*f^2 + c*(e^2 - d*f)))*ArcTanh[(2*a*f - c*(e + Sqrt[e^2 - 4*d*f])*x)/(Sqrt[4*a*f^2 + c*(e + Sqrt[e^2 - 4*d*f])^2]*Sqrt[a + c*x^2])])/(f^2*Sqrt[e^2 - 4*d*f]*Sqrt[4*a*f^2 + c*(e + Sqrt[e^2 - 4*d*f])^2])}
{x^0*(a + c*x^2)^(1/2)/(d + e*x + f*x^2), x, 5, (Sqrt[c]*ArcTanh[(Sqrt[c]*x)/Sqrt[a + c*x^2]])/f - (Sqrt[2*a*f^2 + c*(e^2 - 2*d*f - e*Sqrt[e^2 - 4*d*f])]*ArcTanh[(2*a*f - c*(e - Sqrt[e^2 - 4*d*f])*x)/(Sqrt[4*a*f^2 + c*(e - Sqrt[e^2 - 4*d*f])^2]*Sqrt[a + c*x^2])])/(Sqrt[2]*f*Sqrt[e^2 - 4*d*f]) + (Sqrt[2*a*f^2 + c*(e^2 - 2*d*f + e*Sqrt[e^2 - 4*d*f])]*ArcTanh[(2*a*f - c*(e + Sqrt[e^2 - 4*d*f])*x)/(Sqrt[4*a*f^2 + c*(e + Sqrt[e^2 - 4*d*f])^2]*Sqrt[a + c*x^2])])/(Sqrt[2]*f*Sqrt[e^2 - 4*d*f])}
{1/x^1*(a + c*x^2)^(1/2)/(d + e*x + f*x^2), x, 11, ((2*a*e*f + (c*d - a*f)*(e - Sqrt[e^2 - 4*d*f]))*ArcTanh[(2*a*f - c*(e - Sqrt[e^2 - 4*d*f])*x)/(Sqrt[4*a*f^2 + c*(e - Sqrt[e^2 - 4*d*f])^2]*Sqrt[a + c*x^2])])/(d*Sqrt[e^2 - 4*d*f]*Sqrt[4*a*f^2 + c*(e - Sqrt[e^2 - 4*d*f])^2]) - ((2*a*e*f + (c*d - a*f)*(e + Sqrt[e^2 - 4*d*f]))*ArcTanh[(2*a*f - c*(e + Sqrt[e^2 - 4*d*f])*x)/(Sqrt[4*a*f^2 + c*(e + Sqrt[e^2 - 4*d*f])^2]*Sqrt[a + c*x^2])])/(d*Sqrt[e^2 - 4*d*f]*Sqrt[4*a*f^2 + c*(e + Sqrt[e^2 - 4*d*f])^2]) - (Sqrt[a]*ArcTanh[Sqrt[a + c*x^2]/Sqrt[a]])/d}
{1/x^2*(a + c*x^2)^(1/2)/(d + e*x + f*x^2), x, 13, -(Sqrt[a + c*x^2]/(d*x)) - (f*(2*c*d^2 + a*(e^2 - 2*d*f + e*Sqrt[e^2 - 4*d*f]))*ArcTanh[(2*a*f - c*(e - Sqrt[e^2 - 4*d*f])*x)/(Sqrt[4*a*f^2 + c*(e - Sqrt[e^2 - 4*d*f])^2]*Sqrt[a + c*x^2])])/(d^2*Sqrt[e^2 - 4*d*f]*Sqrt[4*a*f^2 + c*(e - Sqrt[e^2 - 4*d*f])^2]) + (f*(2*c*d^2 + a*(e^2 - 2*d*f - e*Sqrt[e^2 - 4*d*f]))*ArcTanh[(2*a*f - c*(e + Sqrt[e^2 - 4*d*f])*x)/(Sqrt[4*a*f^2 + c*(e + Sqrt[e^2 - 4*d*f])^2]*Sqrt[a + c*x^2])])/(d^2*Sqrt[e^2 - 4*d*f]*Sqrt[4*a*f^2 + c*(e + Sqrt[e^2 - 4*d*f])^2]) + (Sqrt[a]*e*ArcTanh[Sqrt[a + c*x^2]/Sqrt[a]])/d^2}
{1/x^3*(a + c*x^2)^(1/2)/(d + e*x + f*x^2), x, 16, -(Sqrt[a + c*x^2]/(2*d*x^2)) + (e*Sqrt[a + c*x^2])/(d^2*x) + (f*(2*e*(c*d^2 + a*(e^2 - 2*d*f)) - (e - Sqrt[e^2 - 4*d*f])*(c*d^2 + a*(e^2 - d*f)))*ArcTanh[(2*a*f - c*(e - Sqrt[e^2 - 4*d*f])*x)/(Sqrt[4*a*f^2 + c*(e - Sqrt[e^2 - 4*d*f])^2]*Sqrt[a + c*x^2])])/(d^3*Sqrt[e^2 - 4*d*f]*Sqrt[4*a*f^2 + c*(e - Sqrt[e^2 - 4*d*f])^2]) - (f*(2*e*(c*d^2 + a*(e^2 - 2*d*f)) - (e + Sqrt[e^2 - 4*d*f])*(c*d^2 + a*(e^2 - d*f)))*ArcTanh[(2*a*f - c*(e + Sqrt[e^2 - 4*d*f])*x)/(Sqrt[4*a*f^2 + c*(e + Sqrt[e^2 - 4*d*f])^2]*Sqrt[a + c*x^2])])/(d^3*Sqrt[e^2 - 4*d*f]*Sqrt[4*a*f^2 + c*(e + Sqrt[e^2 - 4*d*f])^2]) - (c*ArcTanh[Sqrt[a + c*x^2]/Sqrt[a]])/(2*Sqrt[a]*d) - (Sqrt[a]*(e^2 - d*f)*ArcTanh[Sqrt[a + c*x^2]/Sqrt[a]])/d^3}


{x^2*(a + c*x^2)^(3/2)/(d + e*x + f*x^2), x, 15, -((e*(a*f^2 + c*(e^2 - 2*d*f))*Sqrt[a + c*x^2])/f^4) + (3*a*x*Sqrt[a + c*x^2])/(8*f) + (c*(e^2 - d*f)*x*Sqrt[a + c*x^2])/(2*f^3) - (e*(a + c*x^2)^(3/2))/(3*f^2) + (x*(a + c*x^2)^(3/2))/(4*f) + (3*a^2*ArcTanh[(Sqrt[c]*x)/Sqrt[a + c*x^2]])/(8*Sqrt[c]*f) + (a*Sqrt[c]*(e^2 - d*f)*ArcTanh[(Sqrt[c]*x)/Sqrt[a + c*x^2]])/(2*f^3) + (Sqrt[c]*(a*f^2*(e^2 - d*f) + c*(e^4 - 3*d*e^2*f + d^2*f^2))*ArcTanh[(Sqrt[c]*x)/Sqrt[a + c*x^2]])/f^5 - ((e*(e - Sqrt[e^2 - 4*d*f])*(a*f^2 + c*(e^2 - 3*d*f))*(a*f^2 + c*(e^2 - d*f)) - 2*d*f*(a^2*f^4 + 2*a*c*f^2*(e^2 - d*f) + c^2*(e^4 - 3*d*e^2*f + d^2*f^2)))*ArcTanh[(2*a*f - c*(e - Sqrt[e^2 - 4*d*f])*x)/(Sqrt[4*a*f^2 + c*(e - Sqrt[e^2 - 4*d*f])^2]*Sqrt[a + c*x^2])])/(f^5*Sqrt[e^2 - 4*d*f]*Sqrt[4*a*f^2 + c*(e - Sqrt[e^2 - 4*d*f])^2]) + ((e*(e + Sqrt[e^2 - 4*d*f])*(a*f^2 + c*(e^2 - 3*d*f))*(a*f^2 + c*(e^2 - d*f)) - 2*d*f*(a^2*f^4 + 2*a*c*f^2*(e^2 - d*f) + c^2*(e^4 - 3*d*e^2*f + d^2*f^2)))*ArcTanh[(2*a*f - c*(e + Sqrt[e^2 - 4*d*f])*x)/(Sqrt[4*a*f^2 + c*(e + Sqrt[e^2 - 4*d*f])^2]*Sqrt[a + c*x^2])])/(f^5*Sqrt[e^2 - 4*d*f]*Sqrt[4*a*f^2 + c*(e + Sqrt[e^2 - 4*d*f])^2])}
{x^1*(a + c*x^2)^(3/2)/(d + e*x + f*x^2), x, 10, ((a*f^2 + c*(e^2 - d*f))*Sqrt[a + c*x^2])/f^3 - (c*e*x*Sqrt[a + c*x^2])/(2*f^2) + (a + c*x^2)^(3/2)/(3*f) - (a*Sqrt[c]*e*ArcTanh[(Sqrt[c]*x)/Sqrt[a + c*x^2]])/(2*f^2) - (Sqrt[c]*e*(a*f^2 + c*(e^2 - 2*d*f))*ArcTanh[(Sqrt[c]*x)/Sqrt[a + c*x^2]])/f^4 - ((2*c*d*e*f*(2*a*f^2 + c*(e^2 - 2*d*f)) + (e - Sqrt[e^2 - 4*d*f])*(c^2*d*e^2*f - (a*f^2 + c*(e^2 - d*f))^2))*ArcTanh[(2*a*f - c*(e - Sqrt[e^2 - 4*d*f])*x)/(Sqrt[4*a*f^2 + c*(e - Sqrt[e^2 - 4*d*f])^2]*Sqrt[a + c*x^2])])/(f^4*Sqrt[e^2 - 4*d*f]*Sqrt[4*a*f^2 + c*(e - Sqrt[e^2 - 4*d*f])^2]) + ((2*c*d*e*f*(2*a*f^2 + c*(e^2 - 2*d*f)) + (e + Sqrt[e^2 - 4*d*f])*(c^2*d*e^2*f - (a*f^2 + c*(e^2 - d*f))^2))*ArcTanh[(2*a*f - c*(e + Sqrt[e^2 - 4*d*f])*x)/(Sqrt[4*a*f^2 + c*(e + Sqrt[e^2 - 4*d*f])^2]*Sqrt[a + c*x^2])])/(f^4*Sqrt[e^2 - 4*d*f]*Sqrt[4*a*f^2 + c*(e + Sqrt[e^2 - 4*d*f])^2])}
{x^0*(a + c*x^2)^(3/2)/(d + e*x + f*x^2), x, 9, -((c*e*Sqrt[a + c*x^2])/f^2) + (c*x*Sqrt[a + c*x^2])/(2*f) + (a*Sqrt[c]*ArcTanh[(Sqrt[c]*x)/Sqrt[a + c*x^2]])/(2*f) + (Sqrt[c]*(a*f^2 + c*(e^2 - d*f))*ArcTanh[(Sqrt[c]*x)/Sqrt[a + c*x^2]])/f^3 + ((2*f*(c^2*d*e^2 - f*(c*d - a*f)^2) - c*e*(e - Sqrt[e^2 - 4*d*f])*(2*a*f^2 + c*(e^2 - 2*d*f)))*ArcTanh[(2*a*f - c*(e - Sqrt[e^2 - 4*d*f])*x)/(Sqrt[4*a*f^2 + c*(e - Sqrt[e^2 - 4*d*f])^2]*Sqrt[a + c*x^2])])/(f^3*Sqrt[e^2 - 4*d*f]*Sqrt[4*a*f^2 + c*(e - Sqrt[e^2 - 4*d*f])^2]) - ((2*f*(c^2*d*e^2 - f*(c*d - a*f)^2) - c*e*(e + Sqrt[e^2 - 4*d*f])*(2*a*f^2 + c*(e^2 - 2*d*f)))*ArcTanh[(2*a*f - c*(e + Sqrt[e^2 - 4*d*f])*x)/(Sqrt[4*a*f^2 + c*(e + Sqrt[e^2 - 4*d*f])^2]*Sqrt[a + c*x^2])])/(f^3*Sqrt[e^2 - 4*d*f]*Sqrt[4*a*f^2 + c*(e + Sqrt[e^2 - 4*d*f])^2])}
{1/x^1*(a + c*x^2)^(3/2)/(d + e*x + f*x^2), x, 15, (a*Sqrt[a + c*x^2])/d + ((c*d - a*f)*Sqrt[a + c*x^2])/(d*f) - (c^(3/2)*e*ArcTanh[(Sqrt[c]*x)/Sqrt[a + c*x^2]])/f^2 - ((2*e*f*(c^2*d^2 - a^2*f^2) - (e - Sqrt[e^2 - 4*d*f])*(2*a*c*d*f^2 - a^2*f^3 + c^2*d*(e^2 - d*f)))*ArcTanh[(2*a*f - c*(e - Sqrt[e^2 - 4*d*f])*x)/(Sqrt[4*a*f^2 + c*(e - Sqrt[e^2 - 4*d*f])^2]*Sqrt[a + c*x^2])])/(d*f^2*Sqrt[e^2 - 4*d*f]*Sqrt[4*a*f^2 + c*(e - Sqrt[e^2 - 4*d*f])^2]) + ((2*e*f*(c^2*d^2 - a^2*f^2) - (e + Sqrt[e^2 - 4*d*f])*(2*a*c*d*f^2 - a^2*f^3 + c^2*d*(e^2 - d*f)))*ArcTanh[(2*a*f - c*(e + Sqrt[e^2 - 4*d*f])*x)/(Sqrt[4*a*f^2 + c*(e + Sqrt[e^2 - 4*d*f])^2]*Sqrt[a + c*x^2])])/(d*f^2*Sqrt[e^2 - 4*d*f]*Sqrt[4*a*f^2 + c*(e + Sqrt[e^2 - 4*d*f])^2]) - (a^(3/2)*ArcTanh[Sqrt[a + c*x^2]/Sqrt[a]])/d}
{1/x^2*(a + c*x^2)^(3/2)/(d + e*x + f*x^2), x, 19, (c*x*Sqrt[a + c*x^2])/d - (a + c*x^2)^(3/2)/(d*x) + (a*Sqrt[c]*ArcTanh[(Sqrt[c]*x)/Sqrt[a + c*x^2]])/d + (Sqrt[c]*(c*d - a*f)*ArcTanh[(Sqrt[c]*x)/Sqrt[a + c*x^2]])/(d*f) - ((e*(c*d - a*f)*(c*d + a*f)*(e - Sqrt[e^2 - 4*d*f]) - 2*f*(c^2*d^3 - 2*a*c*d^2*f - a^2*f*(e^2 - d*f)))*ArcTanh[(2*a*f - c*(e - Sqrt[e^2 - 4*d*f])*x)/(Sqrt[4*a*f^2 + c*(e - Sqrt[e^2 - 4*d*f])^2]*Sqrt[a + c*x^2])])/(d^2*f*Sqrt[e^2 - 4*d*f]*Sqrt[4*a*f^2 + c*(e - Sqrt[e^2 - 4*d*f])^2]) + ((e*(c*d - a*f)*(c*d + a*f)*(e + Sqrt[e^2 - 4*d*f]) - 2*f*(c^2*d^3 - 2*a*c*d^2*f - a^2*f*(e^2 - d*f)))*ArcTanh[(2*a*f - c*(e + Sqrt[e^2 - 4*d*f])*x)/(Sqrt[4*a*f^2 + c*(e + Sqrt[e^2 - 4*d*f])^2]*Sqrt[a + c*x^2])])/(d^2*f*Sqrt[e^2 - 4*d*f]*Sqrt[4*a*f^2 + c*(e + Sqrt[e^2 - 4*d*f])^2]) + (a^(3/2)*e*ArcTanh[Sqrt[a + c*x^2]/Sqrt[a]])/d^2}
{1/x^3*(a + c*x^2)^(3/2)/(d + e*x + f*x^2), x, 23, (3*c*Sqrt[a + c*x^2])/(2*d) + (a*(e^2 - d*f)*Sqrt[a + c*x^2])/d^3 - ((c*d^2 + a*(e^2 - d*f))*Sqrt[a + c*x^2])/d^3 - (c*e*x*Sqrt[a + c*x^2])/d^2 - (a + c*x^2)^(3/2)/(2*d*x^2) + (e*(a + c*x^2)^(3/2))/(d^2*x) + ((2*a*e*f*(2*c*d^2 + a*(e^2 - 2*d*f)) + (e - Sqrt[e^2 - 4*d*f])*(c^2*d^3 - 2*a*c*d^2*f - a^2*f*(e^2 - d*f)))*ArcTanh[(2*a*f - c*(e - Sqrt[e^2 - 4*d*f])*x)/(Sqrt[4*a*f^2 + c*(e - Sqrt[e^2 - 4*d*f])^2]*Sqrt[a + c*x^2])])/(d^3*Sqrt[e^2 - 4*d*f]*Sqrt[4*a*f^2 + c*(e - Sqrt[e^2 - 4*d*f])^2]) - ((2*a*e*f*(2*c*d^2 + a*(e^2 - 2*d*f)) + (e + Sqrt[e^2 - 4*d*f])*(c^2*d^3 - 2*a*c*d^2*f - a^2*f*(e^2 - d*f)))*ArcTanh[(2*a*f - c*(e + Sqrt[e^2 - 4*d*f])*x)/(Sqrt[4*a*f^2 + c*(e + Sqrt[e^2 - 4*d*f])^2]*Sqrt[a + c*x^2])])/(d^3*Sqrt[e^2 - 4*d*f]*Sqrt[4*a*f^2 + c*(e + Sqrt[e^2 - 4*d*f])^2]) - (3*Sqrt[a]*c*ArcTanh[Sqrt[a + c*x^2]/Sqrt[a]])/(2*d) - (a^(3/2)*(e^2 - d*f)*ArcTanh[Sqrt[a + c*x^2]/Sqrt[a]])/d^3}


(* ::Subsubsection::Closed:: *)
(*p<0*)


{x^3/((a + c*x^2)^(1/2)*(d + e*x + f*x^2)), x, 7, Sqrt[a + c*x^2]/(c*f) - (e*ArcTanh[(Sqrt[c]*x)/Sqrt[a + c*x^2]])/(Sqrt[c]*f^2) - ((2*d*e*f - (e^2 - d*f)*(e - Sqrt[e^2 - 4*d*f]))*ArcTanh[(2*a*f - c*(e - Sqrt[e^2 - 4*d*f])*x)/(Sqrt[4*a*f^2 + c*(e - Sqrt[e^2 - 4*d*f])^2]*Sqrt[a + c*x^2])])/(f^2*Sqrt[e^2 - 4*d*f]*Sqrt[4*a*f^2 + c*(e - Sqrt[e^2 - 4*d*f])^2]) + ((2*d*e*f - (e^2 - d*f)*(e + Sqrt[e^2 - 4*d*f]))*ArcTanh[(2*a*f - c*(e + Sqrt[e^2 - 4*d*f])*x)/(Sqrt[4*a*f^2 + c*(e + Sqrt[e^2 - 4*d*f])^2]*Sqrt[a + c*x^2])])/(f^2*Sqrt[e^2 - 4*d*f]*Sqrt[4*a*f^2 + c*(e + Sqrt[e^2 - 4*d*f])^2])}
{x^2/((a + c*x^2)^(1/2)*(d + e*x + f*x^2)), x, 6, ArcTanh[(Sqrt[c]*x)/Sqrt[a + c*x^2]]/(Sqrt[c]*f) - ((e^2 - 2*d*f - e*Sqrt[e^2 - 4*d*f])*ArcTanh[(2*a*f - c*(e - Sqrt[e^2 - 4*d*f])*x)/(Sqrt[4*a*f^2 + c*(e - Sqrt[e^2 - 4*d*f])^2]*Sqrt[a + c*x^2])])/(f*Sqrt[e^2 - 4*d*f]*Sqrt[4*a*f^2 + c*(e - Sqrt[e^2 - 4*d*f])^2]) - ((2*d*f - e*(e + Sqrt[e^2 - 4*d*f]))*ArcTanh[(2*a*f - c*(e + Sqrt[e^2 - 4*d*f])*x)/(Sqrt[4*a*f^2 + c*(e + Sqrt[e^2 - 4*d*f])^2]*Sqrt[a + c*x^2])])/(f*Sqrt[e^2 - 4*d*f]*Sqrt[4*a*f^2 + c*(e + Sqrt[e^2 - 4*d*f])^2])}
{x^1/((a + c*x^2)^(1/2)*(d + e*x + f*x^2)), x, 3, ((e - Sqrt[e^2 - 4*d*f])*ArcTanh[(2*a*f - c*(e - Sqrt[e^2 - 4*d*f])*x)/(Sqrt[4*a*f^2 + c*(e - Sqrt[e^2 - 4*d*f])^2]*Sqrt[a + c*x^2])])/(Sqrt[e^2 - 4*d*f]*Sqrt[4*a*f^2 + c*(e - Sqrt[e^2 - 4*d*f])^2]) - ((e + Sqrt[e^2 - 4*d*f])*ArcTanh[(2*a*f - c*(e + Sqrt[e^2 - 4*d*f])*x)/(Sqrt[4*a*f^2 + c*(e + Sqrt[e^2 - 4*d*f])^2]*Sqrt[a + c*x^2])])/(Sqrt[e^2 - 4*d*f]*Sqrt[4*a*f^2 + c*(e + Sqrt[e^2 - 4*d*f])^2])}
{x^0/((a + c*x^2)^(1/2)*(d + e*x + f*x^2)), x, 3, -((2*f*ArcTanh[(2*a*f - c*(e - Sqrt[e^2 - 4*d*f])*x)/(Sqrt[4*a*f^2 + c*(e - Sqrt[e^2 - 4*d*f])^2]*Sqrt[a + c*x^2])])/(Sqrt[e^2 - 4*d*f]*Sqrt[4*a*f^2 + c*(e - Sqrt[e^2 - 4*d*f])^2])) + (2*f*ArcTanh[(2*a*f - c*(e + Sqrt[e^2 - 4*d*f])*x)/(Sqrt[4*a*f^2 + c*(e + Sqrt[e^2 - 4*d*f])^2]*Sqrt[a + c*x^2])])/(Sqrt[e^2 - 4*d*f]*Sqrt[4*a*f^2 + c*(e + Sqrt[e^2 - 4*d*f])^2])}
{1/(x^1*(a + c*x^2)^(1/2)*(d + e*x + f*x^2)), x, 7, (f*(e + Sqrt[e^2 - 4*d*f])*ArcTanh[(2*a*f - c*(e - Sqrt[e^2 - 4*d*f])*x)/(Sqrt[4*a*f^2 + c*(e - Sqrt[e^2 - 4*d*f])^2]*Sqrt[a + c*x^2])])/(d*Sqrt[e^2 - 4*d*f]*Sqrt[4*a*f^2 + c*(e - Sqrt[e^2 - 4*d*f])^2]) - (f*(e - Sqrt[e^2 - 4*d*f])*ArcTanh[(2*a*f - c*(e + Sqrt[e^2 - 4*d*f])*x)/(Sqrt[4*a*f^2 + c*(e + Sqrt[e^2 - 4*d*f])^2]*Sqrt[a + c*x^2])])/(d*Sqrt[e^2 - 4*d*f]*Sqrt[4*a*f^2 + c*(e + Sqrt[e^2 - 4*d*f])^2]) - ArcTanh[Sqrt[a + c*x^2]/Sqrt[a]]/(Sqrt[a]*d)}
{1/(x^2*(a + c*x^2)^(1/2)*(d + e*x + f*x^2)), x, 8, -(Sqrt[a + c*x^2]/(a*d*x)) - (f*(e^2 - 2*d*f + e*Sqrt[e^2 - 4*d*f])*ArcTanh[(2*a*f - c*(e - Sqrt[e^2 - 4*d*f])*x)/(Sqrt[4*a*f^2 + c*(e - Sqrt[e^2 - 4*d*f])^2]*Sqrt[a + c*x^2])])/(d^2*Sqrt[e^2 - 4*d*f]*Sqrt[4*a*f^2 + c*(e - Sqrt[e^2 - 4*d*f])^2]) + (f*(e^2 - 2*d*f - e*Sqrt[e^2 - 4*d*f])*ArcTanh[(2*a*f - c*(e + Sqrt[e^2 - 4*d*f])*x)/(Sqrt[4*a*f^2 + c*(e + Sqrt[e^2 - 4*d*f])^2]*Sqrt[a + c*x^2])])/(d^2*Sqrt[e^2 - 4*d*f]*Sqrt[4*a*f^2 + c*(e + Sqrt[e^2 - 4*d*f])^2]) + (e*ArcTanh[Sqrt[a + c*x^2]/Sqrt[a]])/(Sqrt[a]*d^2)}
{1/(x^3*(a + c*x^2)^(1/2)*(d + e*x + f*x^2)), x, 11, -(Sqrt[a + c*x^2]/(2*a*d*x^2)) + (e*Sqrt[a + c*x^2])/(a*d^2*x) + (f*(2*e^3 - 4*d*e*f - (e^2 - d*f)*(e - Sqrt[e^2 - 4*d*f]))*ArcTanh[(2*a*f - c*(e - Sqrt[e^2 - 4*d*f])*x)/(Sqrt[4*a*f^2 + c*(e - Sqrt[e^2 - 4*d*f])^2]*Sqrt[a + c*x^2])])/(d^3*Sqrt[e^2 - 4*d*f]*Sqrt[4*a*f^2 + c*(e - Sqrt[e^2 - 4*d*f])^2]) - (f*(2*e^3 - 4*d*e*f - (e^2 - d*f)*(e + Sqrt[e^2 - 4*d*f]))*ArcTanh[(2*a*f - c*(e + Sqrt[e^2 - 4*d*f])*x)/(Sqrt[4*a*f^2 + c*(e + Sqrt[e^2 - 4*d*f])^2]*Sqrt[a + c*x^2])])/(d^3*Sqrt[e^2 - 4*d*f]*Sqrt[4*a*f^2 + c*(e + Sqrt[e^2 - 4*d*f])^2]) + (c*ArcTanh[Sqrt[a + c*x^2]/Sqrt[a]])/(2*a^(3/2)*d) - ((e^2 - d*f)*ArcTanh[Sqrt[a + c*x^2]/Sqrt[a]])/(Sqrt[a]*d^3)}


{x^3/((a + c*x^2)^(3/2)*(d + e*x + f*x^2)), x, 9, -(1/(c*f*Sqrt[a + c*x^2])) - (e*x)/(a*f^2*Sqrt[a + c*x^2]) + (a*f*(c*d^2 + a*(e^2 - d*f)) + c*e*(c*d^2 + a*(e^2 - 2*d*f))*x)/(a*f^2*(c^2*d^2 + a^2*f^2 + a*c*(e^2 - 2*d*f))*Sqrt[a + c*x^2]) - ((2*a*d*e*f - (e - Sqrt[e^2 - 4*d*f])*(c*d^2 + a*(e^2 - d*f)))*ArcTanh[(2*a*f - c*(e - Sqrt[e^2 - 4*d*f])*x)/(Sqrt[4*a*f^2 + c*(e - Sqrt[e^2 - 4*d*f])^2]*Sqrt[a + c*x^2])])/(Sqrt[e^2 - 4*d*f]*(c^2*d^2 + a^2*f^2 + a*c*(e^2 - 2*d*f))*Sqrt[4*a*f^2 + c*(e - Sqrt[e^2 - 4*d*f])^2]) + ((2*a*d*e*f - (e + Sqrt[e^2 - 4*d*f])*(c*d^2 + a*(e^2 - d*f)))*ArcTanh[(2*a*f - c*(e + Sqrt[e^2 - 4*d*f])*x)/(Sqrt[4*a*f^2 + c*(e + Sqrt[e^2 - 4*d*f])^2]*Sqrt[a + c*x^2])])/(Sqrt[e^2 - 4*d*f]*(c^2*d^2 + a^2*f^2 + a*c*(e^2 - 2*d*f))*Sqrt[4*a*f^2 + c*(e + Sqrt[e^2 - 4*d*f])^2])}
{x^2/((a + c*x^2)^(3/2)*(d + e*x + f*x^2)), x, 8, x/(a*f*Sqrt[a + c*x^2]) - (a^2*e*f + c*(c*d^2 + a*(e^2 - d*f))*x)/(a*f*(c^2*d^2 + a^2*f^2 + a*c*(e^2 - 2*d*f))*Sqrt[a + c*x^2]) - (f*(2*d*(c*d - a*f) + a*e*(e - Sqrt[e^2 - 4*d*f]))*ArcTanh[(2*a*f - c*(e - Sqrt[e^2 - 4*d*f])*x)/(Sqrt[4*a*f^2 + c*(e - Sqrt[e^2 - 4*d*f])^2]*Sqrt[a + c*x^2])])/(Sqrt[e^2 - 4*d*f]*(c^2*d^2 + a^2*f^2 + a*c*(e^2 - 2*d*f))*Sqrt[4*a*f^2 + c*(e - Sqrt[e^2 - 4*d*f])^2]) + (f*(2*d*(c*d - a*f) + a*e*(e + Sqrt[e^2 - 4*d*f]))*ArcTanh[(2*a*f - c*(e + Sqrt[e^2 - 4*d*f])*x)/(Sqrt[4*a*f^2 + c*(e + Sqrt[e^2 - 4*d*f])^2]*Sqrt[a + c*x^2])])/(Sqrt[e^2 - 4*d*f]*(c^2*d^2 + a^2*f^2 + a*c*(e^2 - 2*d*f))*Sqrt[4*a*f^2 + c*(e + Sqrt[e^2 - 4*d*f])^2])}
{x^1/((a + c*x^2)^(3/2)*(d + e*x + f*x^2)), x, 5, -((c*d - a*f - c*e*x)/((c^2*d^2 + a^2*f^2 + a*c*(e^2 - 2*d*f))*Sqrt[a + c*x^2])) + (f*(2*c*d*e - (c*d - a*f)*(e - Sqrt[e^2 - 4*d*f]))*ArcTanh[(2*a*f - c*(e - Sqrt[e^2 - 4*d*f])*x)/(Sqrt[4*a*f^2 + c*(e - Sqrt[e^2 - 4*d*f])^2]*Sqrt[a + c*x^2])])/(Sqrt[e^2 - 4*d*f]*(c^2*d^2 + a^2*f^2 + a*c*(e^2 - 2*d*f))*Sqrt[4*a*f^2 + c*(e - Sqrt[e^2 - 4*d*f])^2]) - (f*(2*c*d*e - (c*d - a*f)*(e + Sqrt[e^2 - 4*d*f]))*ArcTanh[(2*a*f - c*(e + Sqrt[e^2 - 4*d*f])*x)/(Sqrt[4*a*f^2 + c*(e + Sqrt[e^2 - 4*d*f])^2]*Sqrt[a + c*x^2])])/(Sqrt[e^2 - 4*d*f]*(c^2*d^2 + a^2*f^2 + a*c*(e^2 - 2*d*f))*Sqrt[4*a*f^2 + c*(e + Sqrt[e^2 - 4*d*f])^2])}
{x^0/((a + c*x^2)^(3/2)*(d + e*x + f*x^2)), x, 5, (c*(a*e + (c*d - a*f)*x))/(a*(c^2*d^2 + a^2*f^2 + a*c*(e^2 - 2*d*f))*Sqrt[a + c*x^2]) - (f*(2*a*f^2 + c*(e^2 - 2*d*f + e*Sqrt[e^2 - 4*d*f]))*ArcTanh[(2*a*f - c*(e - Sqrt[e^2 - 4*d*f])*x)/(Sqrt[4*a*f^2 + c*(e - Sqrt[e^2 - 4*d*f])^2]*Sqrt[a + c*x^2])])/(Sqrt[e^2 - 4*d*f]*(c^2*d^2 + a^2*f^2 + a*c*(e^2 - 2*d*f))*Sqrt[4*a*f^2 + c*(e - Sqrt[e^2 - 4*d*f])^2]) + (f*(2*a*f^2 + c*(e^2 - 2*d*f - e*Sqrt[e^2 - 4*d*f]))*ArcTanh[(2*a*f - c*(e + Sqrt[e^2 - 4*d*f])*x)/(Sqrt[4*a*f^2 + c*(e + Sqrt[e^2 - 4*d*f])^2]*Sqrt[a + c*x^2])])/(Sqrt[e^2 - 4*d*f]*(c^2*d^2 + a^2*f^2 + a*c*(e^2 - 2*d*f))*Sqrt[4*a*f^2 + c*(e + Sqrt[e^2 - 4*d*f])^2])}
{1/(x^1*(a + c*x^2)^(3/2)*(d + e*x + f*x^2)), x, 10, 1/(a*d*Sqrt[a + c*x^2]) - (a*(a*f^2 + c*(e^2 - d*f)) + c^2*d*e*x)/(a*d*(c^2*d^2 + a^2*f^2 + a*c*(e^2 - 2*d*f))*Sqrt[a + c*x^2]) + (f*(2*e*(a*f^2 + c*(e^2 - 2*d*f)) - (e - Sqrt[e^2 - 4*d*f])*(a*f^2 + c*(e^2 - d*f)))*ArcTanh[(2*a*f - c*(e - Sqrt[e^2 - 4*d*f])*x)/(Sqrt[4*a*f^2 + c*(e - Sqrt[e^2 - 4*d*f])^2]*Sqrt[a + c*x^2])])/(d*Sqrt[e^2 - 4*d*f]*(c^2*d^2 + a^2*f^2 + a*c*(e^2 - 2*d*f))*Sqrt[4*a*f^2 + c*(e - Sqrt[e^2 - 4*d*f])^2]) - (f*(2*e*(a*f^2 + c*(e^2 - 2*d*f)) - (e + Sqrt[e^2 - 4*d*f])*(a*f^2 + c*(e^2 - d*f)))*ArcTanh[(2*a*f - c*(e + Sqrt[e^2 - 4*d*f])*x)/(Sqrt[4*a*f^2 + c*(e + Sqrt[e^2 - 4*d*f])^2]*Sqrt[a + c*x^2])])/(d*Sqrt[e^2 - 4*d*f]*(c^2*d^2 + a^2*f^2 + a*c*(e^2 - 2*d*f))*Sqrt[4*a*f^2 + c*(e + Sqrt[e^2 - 4*d*f])^2]) - ArcTanh[Sqrt[a + c*x^2]/Sqrt[a]]/(a^(3/2)*d)}
{1/(x^2*(a + c*x^2)^(3/2)*(d + e*x + f*x^2)), x, 12, -(e/(a*d^2*Sqrt[a + c*x^2])) + 1/(a*d*x*Sqrt[a + c*x^2]) + (a*e*(a*f^2 + c*(e^2 - 2*d*f)) + c*d*(a*f^2 + c*(e^2 - d*f))*x)/(a*d^2*(c^2*d^2 + a^2*f^2 + a*c*(e^2 - 2*d*f))*Sqrt[a + c*x^2]) - (2*Sqrt[a + c*x^2])/(a^2*d*x) + (f*(e*(e - Sqrt[e^2 - 4*d*f])*(a*f^2 + c*(e^2 - 2*d*f)) + 2*(c*d*e^2*f - (e^2 - d*f)*(a*f^2 + c*(e^2 - d*f))))*ArcTanh[(2*a*f - c*(e - Sqrt[e^2 - 4*d*f])*x)/(Sqrt[4*a*f^2 + c*(e - Sqrt[e^2 - 4*d*f])^2]*Sqrt[a + c*x^2])])/(d^2*Sqrt[e^2 - 4*d*f]*(c^2*d^2 + a^2*f^2 + a*c*(e^2 - 2*d*f))*Sqrt[4*a*f^2 + c*(e - Sqrt[e^2 - 4*d*f])^2]) - (f*(e*(e + Sqrt[e^2 - 4*d*f])*(a*f^2 + c*(e^2 - 2*d*f)) + 2*(c*d*e^2*f - (e^2 - d*f)*(a*f^2 + c*(e^2 - d*f))))*ArcTanh[(2*a*f - c*(e + Sqrt[e^2 - 4*d*f])*x)/(Sqrt[4*a*f^2 + c*(e + Sqrt[e^2 - 4*d*f])^2]*Sqrt[a + c*x^2])])/(d^2*Sqrt[e^2 - 4*d*f]*(c^2*d^2 + a^2*f^2 + a*c*(e^2 - 2*d*f))*Sqrt[4*a*f^2 + c*(e + Sqrt[e^2 - 4*d*f])^2]) + (e*ArcTanh[Sqrt[a + c*x^2]/Sqrt[a]])/(a^(3/2)*d^2)}


(* ::Subsection::Closed:: *)
(*Integrands of the form x^m (a+b x+c x^2)^(p/2) / (d+e x+f x^2) when e=0*)


(* ::Subsubsection::Closed:: *)
(*p>0*)


{x^3*(a + b*x + c*x^2)^(1/2)/(d + f*x^2), x, 11, -((d*Sqrt[a + b*x + c*x^2])/f^2) - (b*(b + 2*c*x)*Sqrt[a + b*x + c*x^2])/(8*c^2*f) + (a + b*x + c*x^2)^(3/2)/(3*c*f) - (d*Sqrt[c*d + b*Sqrt[-d]*Sqrt[f] - a*f]*ArcTan[(b*Sqrt[-d] - 2*a*Sqrt[f] + (2*c*Sqrt[-d] - b*Sqrt[f])*x)/(2*Sqrt[c*d + b*Sqrt[-d]*Sqrt[f] - a*f]*Sqrt[a + b*x + c*x^2])])/(2*f^(5/2)) + (d*Sqrt[c*d - b*Sqrt[-d]*Sqrt[f] - a*f]*ArcTan[(b*Sqrt[-d] + 2*a*Sqrt[f] + (2*c*Sqrt[-d] + b*Sqrt[f])*x)/(2*Sqrt[c*d - b*Sqrt[-d]*Sqrt[f] - a*f]*Sqrt[a + b*x + c*x^2])])/(2*f^(5/2)) - (b*d*ArcTanh[(b + 2*c*x)/(2*Sqrt[c]*Sqrt[a + b*x + c*x^2])])/(2*Sqrt[c]*f^2) + (b*(b^2 - 4*a*c)*ArcTanh[(b + 2*c*x)/(2*Sqrt[c]*Sqrt[a + b*x + c*x^2])])/(16*c^(5/2)*f)}
{x^2*(a + b*x + c*x^2)^(1/2)/(d + f*x^2), x, 9, ((b + 2*c*x)*Sqrt[a + b*x + c*x^2])/(4*c*f) - (Sqrt[-d]*Sqrt[c*d + b*Sqrt[-d]*Sqrt[f] - a*f]*ArcTan[(b*Sqrt[-d] - 2*a*Sqrt[f] + (2*c*Sqrt[-d] - b*Sqrt[f])*x)/(2*Sqrt[c*d + b*Sqrt[-d]*Sqrt[f] - a*f]*Sqrt[a + b*x + c*x^2])])/(2*f^2) - (Sqrt[-d]*Sqrt[c*d - b*Sqrt[-d]*Sqrt[f] - a*f]*ArcTan[(b*Sqrt[-d] + 2*a*Sqrt[f] + (2*c*Sqrt[-d] + b*Sqrt[f])*x)/(2*Sqrt[c*d - b*Sqrt[-d]*Sqrt[f] - a*f]*Sqrt[a + b*x + c*x^2])])/(2*f^2) - (Sqrt[c]*d*ArcTanh[(b + 2*c*x)/(2*Sqrt[c]*Sqrt[a + b*x + c*x^2])])/f^2 - ((b^2 - 4*a*c)*ArcTanh[(b + 2*c*x)/(2*Sqrt[c]*Sqrt[a + b*x + c*x^2])])/(8*c^(3/2)*f)}
{x^1*(a + b*x + c*x^2)^(1/2)/(d + f*x^2), x, 6, Sqrt[a + b*x + c*x^2]/f + (Sqrt[c*d + b*Sqrt[-d]*Sqrt[f] - a*f]*ArcTan[(b*Sqrt[-d] - 2*a*Sqrt[f] + (2*c*Sqrt[-d] - b*Sqrt[f])*x)/(2*Sqrt[c*d + b*Sqrt[-d]*Sqrt[f] - a*f]*Sqrt[a + b*x + c*x^2])])/(2*f^(3/2)) - (Sqrt[c*d - b*Sqrt[-d]*Sqrt[f] - a*f]*ArcTan[(b*Sqrt[-d] + 2*a*Sqrt[f] + (2*c*Sqrt[-d] + b*Sqrt[f])*x)/(2*Sqrt[c*d - b*Sqrt[-d]*Sqrt[f] - a*f]*Sqrt[a + b*x + c*x^2])])/(2*f^(3/2)) + (b*ArcTanh[(b + 2*c*x)/(2*Sqrt[c]*Sqrt[a + b*x + c*x^2])])/(2*Sqrt[c]*f)}
{x^0*(a + b*x + c*x^2)^(1/2)/(d + f*x^2), x, 5, -((Sqrt[c*d + b*Sqrt[-d]*Sqrt[f] - a*f]*ArcTan[(b*Sqrt[-d] - 2*a*Sqrt[f] + (2*c*Sqrt[-d] - b*Sqrt[f])*x)/(2*Sqrt[c*d + b*Sqrt[-d]*Sqrt[f] - a*f]*Sqrt[a + b*x + c*x^2])])/(2*Sqrt[-d]*f)) - (Sqrt[c*d - b*Sqrt[-d]*Sqrt[f] - a*f]*ArcTan[(b*Sqrt[-d] + 2*a*Sqrt[f] + (2*c*Sqrt[-d] + b*Sqrt[f])*x)/(2*Sqrt[c*d - b*Sqrt[-d]*Sqrt[f] - a*f]*Sqrt[a + b*x + c*x^2])])/(2*Sqrt[-d]*f) + (Sqrt[c]*ArcTanh[(b + 2*c*x)/(2*Sqrt[c]*Sqrt[a + b*x + c*x^2])])/f}
{1/x^1*(a + b*x + c*x^2)^(1/2)/(d + f*x^2), x, 12, -((Sqrt[c*d + b*Sqrt[-d]*Sqrt[f] - a*f]*ArcTan[(b*Sqrt[-d] - 2*a*Sqrt[f] + (2*c*Sqrt[-d] - b*Sqrt[f])*x)/(2*Sqrt[c*d + b*Sqrt[-d]*Sqrt[f] - a*f]*Sqrt[a + b*x + c*x^2])])/(2*d*Sqrt[f])) + (Sqrt[c*d - b*Sqrt[-d]*Sqrt[f] - a*f]*ArcTan[(b*Sqrt[-d] + 2*a*Sqrt[f] + (2*c*Sqrt[-d] + b*Sqrt[f])*x)/(2*Sqrt[c*d - b*Sqrt[-d]*Sqrt[f] - a*f]*Sqrt[a + b*x + c*x^2])])/(2*d*Sqrt[f]) - (Sqrt[a]*ArcTanh[(2*a + b*x)/(2*Sqrt[a]*Sqrt[a + b*x + c*x^2])])/d}
{1/x^2*(a + b*x + c*x^2)^(1/2)/(d + f*x^2), x, 11, -(Sqrt[a + b*x + c*x^2]/(d*x)) - (Sqrt[c*d + b*Sqrt[-d]*Sqrt[f] - a*f]*ArcTan[(b*Sqrt[-d] - 2*a*Sqrt[f] + (2*c*Sqrt[-d] - b*Sqrt[f])*x)/(2*Sqrt[c*d + b*Sqrt[-d]*Sqrt[f] - a*f]*Sqrt[a + b*x + c*x^2])])/(2*(-d)^(3/2)) - (Sqrt[c*d - b*Sqrt[-d]*Sqrt[f] - a*f]*ArcTan[(b*Sqrt[-d] + 2*a*Sqrt[f] + (2*c*Sqrt[-d] + b*Sqrt[f])*x)/(2*Sqrt[c*d - b*Sqrt[-d]*Sqrt[f] - a*f]*Sqrt[a + b*x + c*x^2])])/(2*(-d)^(3/2)) - (b*ArcTanh[(2*a + b*x)/(2*Sqrt[a]*Sqrt[a + b*x + c*x^2])])/(2*Sqrt[a]*d)}
{1/x^3*(a + b*x + c*x^2)^(1/2)/(d + f*x^2), x, 14, -(((2*a + b*x)*Sqrt[a + b*x + c*x^2])/(4*a*d*x^2)) + (Sqrt[f]*Sqrt[c*d + b*Sqrt[-d]*Sqrt[f] - a*f]*ArcTan[(b*Sqrt[-d] - 2*a*Sqrt[f] + (2*c*Sqrt[-d] - b*Sqrt[f])*x)/(2*Sqrt[c*d + b*Sqrt[-d]*Sqrt[f] - a*f]*Sqrt[a + b*x + c*x^2])])/(2*d^2) - (Sqrt[f]*Sqrt[c*d - b*Sqrt[-d]*Sqrt[f] - a*f]*ArcTan[(b*Sqrt[-d] + 2*a*Sqrt[f] + (2*c*Sqrt[-d] + b*Sqrt[f])*x)/(2*Sqrt[c*d - b*Sqrt[-d]*Sqrt[f] - a*f]*Sqrt[a + b*x + c*x^2])])/(2*d^2) + ((b^2 - 4*a*c)*ArcTanh[(2*a + b*x)/(2*Sqrt[a]*Sqrt[a + b*x + c*x^2])])/(8*a^(3/2)*d) + (Sqrt[a]*f*ArcTanh[(2*a + b*x)/(2*Sqrt[a]*Sqrt[a + b*x + c*x^2])])/d^2}


{x^3*(a + b*x + c*x^2)^(3/2)/(d + f*x^2), x, 16, (d*(c*d - a*f)*Sqrt[a + b*x + c*x^2])/f^3 - (b*d*(b + 2*c*x)*Sqrt[a + b*x + c*x^2])/(8*c*f^2) + (3*b*(b^2 - 4*a*c)*(b + 2*c*x)*Sqrt[a + b*x + c*x^2])/(128*c^3*f) - (d*(a + b*x + c*x^2)^(3/2))/(3*f^2) - (b*(b + 2*c*x)*(a + b*x + c*x^2)^(3/2))/(16*c^2*f) + (a + b*x + c*x^2)^(5/2)/(5*c*f) - (d*(b^2*d*f - 2*b*Sqrt[-d]*Sqrt[f]*(c*d - a*f) - (c*d - a*f)^2)*ArcTan[(b*Sqrt[-d] - 2*a*Sqrt[f] + (2*c*Sqrt[-d] - b*Sqrt[f])*x)/(2*Sqrt[c*d + b*Sqrt[-d]*Sqrt[f] - a*f]*Sqrt[a + b*x + c*x^2])])/(2*f^(7/2)*Sqrt[c*d + b*Sqrt[-d]*Sqrt[f] - a*f]) + (d*(b^2*d*f + 2*b*Sqrt[-d]*Sqrt[f]*(c*d - a*f) - (c*d - a*f)^2)*ArcTan[(b*Sqrt[-d] + 2*a*Sqrt[f] + (2*c*Sqrt[-d] + b*Sqrt[f])*x)/(2*Sqrt[c*d - b*Sqrt[-d]*Sqrt[f] - a*f]*Sqrt[a + b*x + c*x^2])])/(2*f^(7/2)*Sqrt[c*d - b*Sqrt[-d]*Sqrt[f] - a*f]) + (b*(b^2 - 4*a*c)*d*ArcTanh[(b + 2*c*x)/(2*Sqrt[c]*Sqrt[a + b*x + c*x^2])])/(16*c^(3/2)*f^2) - (3*b*(b^2 - 4*a*c)^2*ArcTanh[(b + 2*c*x)/(2*Sqrt[c]*Sqrt[a + b*x + c*x^2])])/(256*c^(7/2)*f) + (b*d*(3*c*d - a*f)*ArcTanh[(b + 2*c*x)/(2*Sqrt[c]*Sqrt[a + b*x + c*x^2])])/(2*Sqrt[c]*f^3)}
{x^2*(a + b*x + c*x^2)^(3/2)/(d + f*x^2), x, 14, -((b*d*Sqrt[a + b*x + c*x^2])/f^2) - (d*(b + 2*c*x)*Sqrt[a + b*x + c*x^2])/(4*f^2) - (3*(b^2 - 4*a*c)*(b + 2*c*x)*Sqrt[a + b*x + c*x^2])/(64*c^2*f) + ((b + 2*c*x)*(a + b*x + c*x^2)^(3/2))/(8*c*f) - (d*(2*b*Sqrt[f]*(c*d - a*f) - (b^2*d*f - (c*d - a*f)^2)/Sqrt[-d])*ArcTan[(b*Sqrt[-d] - 2*a*Sqrt[f] + (2*c*Sqrt[-d] - b*Sqrt[f])*x)/(2*Sqrt[c*d + b*Sqrt[-d]*Sqrt[f] - a*f]*Sqrt[a + b*x + c*x^2])])/(2*f^3*Sqrt[c*d + b*Sqrt[-d]*Sqrt[f] - a*f]) + (d*(2*b*Sqrt[f]*(c*d - a*f) + (b^2*d*f - (c*d - a*f)^2)/Sqrt[-d])*ArcTan[(b*Sqrt[-d] + 2*a*Sqrt[f] + (2*c*Sqrt[-d] + b*Sqrt[f])*x)/(2*Sqrt[c*d - b*Sqrt[-d]*Sqrt[f] - a*f]*Sqrt[a + b*x + c*x^2])])/(2*f^3*Sqrt[c*d - b*Sqrt[-d]*Sqrt[f] - a*f]) + ((b^2 - 4*a*c)*d*ArcTanh[(b + 2*c*x)/(2*Sqrt[c]*Sqrt[a + b*x + c*x^2])])/(8*Sqrt[c]*f^2) + (3*(b^2 - 4*a*c)^2*ArcTanh[(b + 2*c*x)/(2*Sqrt[c]*Sqrt[a + b*x + c*x^2])])/(128*c^(5/2)*f) + (d*(2*c^2*d - b^2*f - 2*a*c*f)*ArcTanh[(b + 2*c*x)/(2*Sqrt[c]*Sqrt[a + b*x + c*x^2])])/(2*Sqrt[c]*f^3)}
{x^1*(a + b*x + c*x^2)^(3/2)/(d + f*x^2), x, 10, -(((c*d - a*f)*Sqrt[a + b*x + c*x^2])/f^2) + (b*(b + 2*c*x)*Sqrt[a + b*x + c*x^2])/(8*c*f) + (a + b*x + c*x^2)^(3/2)/(3*f) + ((b^2*d*f - 2*b*Sqrt[-d]*Sqrt[f]*(c*d - a*f) - (c*d - a*f)^2)*ArcTan[(b*Sqrt[-d] - 2*a*Sqrt[f] + (2*c*Sqrt[-d] - b*Sqrt[f])*x)/(2*Sqrt[c*d + b*Sqrt[-d]*Sqrt[f] - a*f]*Sqrt[a + b*x + c*x^2])])/(2*f^(5/2)*Sqrt[c*d + b*Sqrt[-d]*Sqrt[f] - a*f]) - ((b^2*d*f + 2*b*Sqrt[-d]*Sqrt[f]*(c*d - a*f) - (c*d - a*f)^2)*ArcTan[(b*Sqrt[-d] + 2*a*Sqrt[f] + (2*c*Sqrt[-d] + b*Sqrt[f])*x)/(2*Sqrt[c*d - b*Sqrt[-d]*Sqrt[f] - a*f]*Sqrt[a + b*x + c*x^2])])/(2*f^(5/2)*Sqrt[c*d - b*Sqrt[-d]*Sqrt[f] - a*f]) - (b*(b^2 - 4*a*c)*ArcTanh[(b + 2*c*x)/(2*Sqrt[c]*Sqrt[a + b*x + c*x^2])])/(16*c^(3/2)*f) - (b*(3*c*d - a*f)*ArcTanh[(b + 2*c*x)/(2*Sqrt[c]*Sqrt[a + b*x + c*x^2])])/(2*Sqrt[c]*f^2)}
{x^0*(a + b*x + c*x^2)^(3/2)/(d + f*x^2), x, 9, (b*Sqrt[a + b*x + c*x^2])/f + ((b + 2*c*x)*Sqrt[a + b*x + c*x^2])/(4*f) + ((2*b*Sqrt[f]*(c*d - a*f) - (b^2*d*f - (c*d - a*f)^2)/Sqrt[-d])*ArcTan[(b*Sqrt[-d] - 2*a*Sqrt[f] + (2*c*Sqrt[-d] - b*Sqrt[f])*x)/(2*Sqrt[c*d + b*Sqrt[-d]*Sqrt[f] - a*f]*Sqrt[a + b*x + c*x^2])])/(2*f^2*Sqrt[c*d + b*Sqrt[-d]*Sqrt[f] - a*f]) - ((2*b*Sqrt[f]*(c*d - a*f) + (b^2*d*f - (c*d - a*f)^2)/Sqrt[-d])*ArcTan[(b*Sqrt[-d] + 2*a*Sqrt[f] + (2*c*Sqrt[-d] + b*Sqrt[f])*x)/(2*Sqrt[c*d - b*Sqrt[-d]*Sqrt[f] - a*f]*Sqrt[a + b*x + c*x^2])])/(2*f^2*Sqrt[c*d - b*Sqrt[-d]*Sqrt[f] - a*f]) - ((b^2 - 4*a*c)*ArcTanh[(b + 2*c*x)/(2*Sqrt[c]*Sqrt[a + b*x + c*x^2])])/(8*Sqrt[c]*f) - ((2*c^2*d - b^2*f - 2*a*c*f)*ArcTanh[(b + 2*c*x)/(2*Sqrt[c]*Sqrt[a + b*x + c*x^2])])/(2*Sqrt[c]*f^2)}
{1/x^1*(a + b*x + c*x^2)^(3/2)/(d + f*x^2), x, 17, ((c*d - a*f)*Sqrt[a + b*x + c*x^2])/(d*f) - (b*(b + 2*c*x)*Sqrt[a + b*x + c*x^2])/(8*c*d) + ((b^2 + 8*a*c + 2*b*c*x)*Sqrt[a + b*x + c*x^2])/(8*c*d) - ((b^2*d*f - 2*b*Sqrt[-d]*Sqrt[f]*(c*d - a*f) - (c*d - a*f)^2)*ArcTan[(b*Sqrt[-d] - 2*a*Sqrt[f] + (2*c*Sqrt[-d] - b*Sqrt[f])*x)/(2*Sqrt[c*d + b*Sqrt[-d]*Sqrt[f] - a*f]*Sqrt[a + b*x + c*x^2])])/(2*d*f^(3/2)*Sqrt[c*d + b*Sqrt[-d]*Sqrt[f] - a*f]) + ((b^2*d*f + 2*b*Sqrt[-d]*Sqrt[f]*(c*d - a*f) - (c*d - a*f)^2)*ArcTan[(b*Sqrt[-d] + 2*a*Sqrt[f] + (2*c*Sqrt[-d] + b*Sqrt[f])*x)/(2*Sqrt[c*d - b*Sqrt[-d]*Sqrt[f] - a*f]*Sqrt[a + b*x + c*x^2])])/(2*d*f^(3/2)*Sqrt[c*d - b*Sqrt[-d]*Sqrt[f] - a*f]) - (a^(3/2)*ArcTanh[(2*a + b*x)/(2*Sqrt[a]*Sqrt[a + b*x + c*x^2])])/d - (b*(b^2 - 12*a*c)*ArcTanh[(b + 2*c*x)/(2*Sqrt[c]*Sqrt[a + b*x + c*x^2])])/(16*c^(3/2)*d) + (b*(b^2 - 4*a*c)*ArcTanh[(b + 2*c*x)/(2*Sqrt[c]*Sqrt[a + b*x + c*x^2])])/(16*c^(3/2)*d) + (b*(3*c*d - a*f)*ArcTanh[(b + 2*c*x)/(2*Sqrt[c]*Sqrt[a + b*x + c*x^2])])/(2*Sqrt[c]*d*f)}
{1/x^2*(a + b*x + c*x^2)^(3/2)/(d + f*x^2), x, 16, -((b*Sqrt[a + b*x + c*x^2])/d) - ((b + 2*c*x)*Sqrt[a + b*x + c*x^2])/(4*d) + (3*(3*b + 2*c*x)*Sqrt[a + b*x + c*x^2])/(4*d) - (a + b*x + c*x^2)^(3/2)/(d*x) - ((2*b*Sqrt[f]*(c*d - a*f) - (b^2*d*f - (c*d - a*f)^2)/Sqrt[-d])*ArcTan[(b*Sqrt[-d] - 2*a*Sqrt[f] + (2*c*Sqrt[-d] - b*Sqrt[f])*x)/(2*Sqrt[c*d + b*Sqrt[-d]*Sqrt[f] - a*f]*Sqrt[a + b*x + c*x^2])])/(2*d*f*Sqrt[c*d + b*Sqrt[-d]*Sqrt[f] - a*f]) + ((2*b*Sqrt[f]*(c*d - a*f) + (b^2*d*f - (c*d - a*f)^2)/Sqrt[-d])*ArcTan[(b*Sqrt[-d] + 2*a*Sqrt[f] + (2*c*Sqrt[-d] + b*Sqrt[f])*x)/(2*Sqrt[c*d - b*Sqrt[-d]*Sqrt[f] - a*f]*Sqrt[a + b*x + c*x^2])])/(2*d*f*Sqrt[c*d - b*Sqrt[-d]*Sqrt[f] - a*f]) - (3*Sqrt[a]*b*ArcTanh[(2*a + b*x)/(2*Sqrt[a]*Sqrt[a + b*x + c*x^2])])/(2*d) + ((b^2 - 4*a*c)*ArcTanh[(b + 2*c*x)/(2*Sqrt[c]*Sqrt[a + b*x + c*x^2])])/(8*Sqrt[c]*d) + (3*(b^2 + 4*a*c)*ArcTanh[(b + 2*c*x)/(2*Sqrt[c]*Sqrt[a + b*x + c*x^2])])/(8*Sqrt[c]*d) + ((2*c^2*d - b^2*f - 2*a*c*f)*ArcTanh[(b + 2*c*x)/(2*Sqrt[c]*Sqrt[a + b*x + c*x^2])])/(2*Sqrt[c]*d*f)}
{1/x^3*(a + b*x + c*x^2)^(3/2)/(d + f*x^2), x, 22, -(((c*d - a*f)*Sqrt[a + b*x + c*x^2])/d^2) - (3*(b - 2*c*x)*Sqrt[a + b*x + c*x^2])/(4*d*x) + (b*f*(b + 2*c*x)*Sqrt[a + b*x + c*x^2])/(8*c*d^2) - (f*(b^2 + 8*a*c + 2*b*c*x)*Sqrt[a + b*x + c*x^2])/(8*c*d^2) - (a + b*x + c*x^2)^(3/2)/(2*d*x^2) + ((b^2*d*f - 2*b*Sqrt[-d]*Sqrt[f]*(c*d - a*f) - (c*d - a*f)^2)*ArcTan[(b*Sqrt[-d] - 2*a*Sqrt[f] + (2*c*Sqrt[-d] - b*Sqrt[f])*x)/(2*Sqrt[c*d + b*Sqrt[-d]*Sqrt[f] - a*f]*Sqrt[a + b*x + c*x^2])])/(2*d^2*Sqrt[f]*Sqrt[c*d + b*Sqrt[-d]*Sqrt[f] - a*f]) - ((b^2*d*f + 2*b*Sqrt[-d]*Sqrt[f]*(c*d - a*f) - (c*d - a*f)^2)*ArcTan[(b*Sqrt[-d] + 2*a*Sqrt[f] + (2*c*Sqrt[-d] + b*Sqrt[f])*x)/(2*Sqrt[c*d - b*Sqrt[-d]*Sqrt[f] - a*f]*Sqrt[a + b*x + c*x^2])])/(2*d^2*Sqrt[f]*Sqrt[c*d - b*Sqrt[-d]*Sqrt[f] - a*f]) - (3*(b^2 + 4*a*c)*ArcTanh[(2*a + b*x)/(2*Sqrt[a]*Sqrt[a + b*x + c*x^2])])/(8*Sqrt[a]*d) + (a^(3/2)*f*ArcTanh[(2*a + b*x)/(2*Sqrt[a]*Sqrt[a + b*x + c*x^2])])/d^2 + (3*b*Sqrt[c]*ArcTanh[(b + 2*c*x)/(2*Sqrt[c]*Sqrt[a + b*x + c*x^2])])/(2*d) + (b*(b^2 - 12*a*c)*f*ArcTanh[(b + 2*c*x)/(2*Sqrt[c]*Sqrt[a + b*x + c*x^2])])/(16*c^(3/2)*d^2) - (b*(b^2 - 4*a*c)*f*ArcTanh[(b + 2*c*x)/(2*Sqrt[c]*Sqrt[a + b*x + c*x^2])])/(16*c^(3/2)*d^2) - (b*(3*c*d - a*f)*ArcTanh[(b + 2*c*x)/(2*Sqrt[c]*Sqrt[a + b*x + c*x^2])])/(2*Sqrt[c]*d^2)}


{(a + b*x + c*x^2)^(3/2)/(1 - x^2), x, 9, (-b)*Sqrt[a + b*x + c*x^2] - (1/4)*(b + 2*c*x)*Sqrt[a + b*x + c*x^2] - (1/2)*(a - b + c)^(3/2)*ArcTanh[(2*a - b + (b - 2*c)*x)/(2*Sqrt[a - b + c]*Sqrt[a + b*x + c*x^2])] + ((b^2 - 4*a*c)*ArcTanh[(b + 2*c*x)/(2*Sqrt[c]*Sqrt[a + b*x + c*x^2])])/(8*Sqrt[c]) - ((b^2 + 2*c*(a + c))*ArcTanh[(b + 2*c*x)/(2*Sqrt[c]*Sqrt[a + b*x + c*x^2])])/(2*Sqrt[c]) + (1/2)*(a + b + c)^(3/2)*ArcTanh[(2*a + b + (b + 2*c)*x)/(2*Sqrt[a + b + c]*Sqrt[a + b*x + c*x^2])]}


{Sqrt[-1 - x + x^2]/(1 - x^2), x, 5, (-(1/2))*ArcTan[(3 - x)/(2*Sqrt[-1 - x + x^2])] + ArcTanh[(1 - 2*x)/(2*Sqrt[-1 - x + x^2])] + (1/2)*ArcTanh[(1 + 3*x)/(2*Sqrt[-1 - x + x^2])]}


{(x + x^2)^(3/2)/(1 + x^2), x, 11, (5*Sqrt[x + x^2])/4 + (1/2)*x*Sqrt[x + x^2] + ArcTan[(I - (1 - 2*I)*x)/(2*Sqrt[1 + I]*Sqrt[x + x^2])]/Sqrt[1 + I] - ArcTan[(I + (1 + 2*I)*x)/(2*Sqrt[1 - I]*Sqrt[x + x^2])]/Sqrt[1 - I] - (5/4)*ArcTanh[x/Sqrt[x + x^2]]}


(* ::Subsubsection::Closed:: *)
(*p<0*)


{x^4/((a + b*x + c*x^2)^(1/2)*(d + f*x^2)), x, 9, -((3*b*Sqrt[a + b*x + c*x^2])/(4*c^2*f)) + (x*Sqrt[a + b*x + c*x^2])/(2*c*f) - (d*ArcTanh[(b + 2*c*x)/(2*Sqrt[c]*Sqrt[a + b*x + c*x^2])])/(Sqrt[c]*f^2) + ((3*b^2 - 4*a*c)*ArcTanh[(b + 2*c*x)/(2*Sqrt[c]*Sqrt[a + b*x + c*x^2])])/(8*c^(5/2)*f) - ((-d)^(3/2)*ArcTanh[(b*Sqrt[-d] - 2*a*Sqrt[f] + (2*c*Sqrt[-d] - b*Sqrt[f])*x)/(2*Sqrt[(-c)*d - b*Sqrt[-d]*Sqrt[f] + a*f]*Sqrt[a + b*x + c*x^2])])/(2*f^2*Sqrt[(-c)*d - b*Sqrt[-d]*Sqrt[f] + a*f]) - ((-d)^(3/2)*ArcTanh[(b*Sqrt[-d] + 2*a*Sqrt[f] + (2*c*Sqrt[-d] + b*Sqrt[f])*x)/(2*Sqrt[(-c)*d + b*Sqrt[-d]*Sqrt[f] + a*f]*Sqrt[a + b*x + c*x^2])])/(2*f^2*Sqrt[(-c)*d + b*Sqrt[-d]*Sqrt[f] + a*f])}
{x^3/((a + b*x + c*x^2)^(1/2)*(d + f*x^2)), x, 7, Sqrt[a + b*x + c*x^2]/(c*f) + (d*ArcTan[(b*Sqrt[-d] - 2*a*Sqrt[f] + (2*c*Sqrt[-d] - b*Sqrt[f])*x)/(2*Sqrt[c*d + b*Sqrt[-d]*Sqrt[f] - a*f]*Sqrt[a + b*x + c*x^2])])/(2*f^(3/2)*Sqrt[c*d + b*Sqrt[-d]*Sqrt[f] - a*f]) - (d*ArcTan[(b*Sqrt[-d] + 2*a*Sqrt[f] + (2*c*Sqrt[-d] + b*Sqrt[f])*x)/(2*Sqrt[c*d - b*Sqrt[-d]*Sqrt[f] - a*f]*Sqrt[a + b*x + c*x^2])])/(2*f^(3/2)*Sqrt[c*d - b*Sqrt[-d]*Sqrt[f] - a*f]) - (b*ArcTanh[(b + 2*c*x)/(2*Sqrt[c]*Sqrt[a + b*x + c*x^2])])/(2*c^(3/2)*f)}
{x^2/((a + b*x + c*x^2)^(1/2)*(d + f*x^2)), x, 6, ArcTanh[(b + 2*c*x)/(2*Sqrt[c]*Sqrt[a + b*x + c*x^2])]/(Sqrt[c]*f) - (Sqrt[-d]*ArcTanh[(b*Sqrt[-d] - 2*a*Sqrt[f] + (2*c*Sqrt[-d] - b*Sqrt[f])*x)/(2*Sqrt[(-c)*d - b*Sqrt[-d]*Sqrt[f] + a*f]*Sqrt[a + b*x + c*x^2])])/(2*f*Sqrt[(-c)*d - b*Sqrt[-d]*Sqrt[f] + a*f]) - (Sqrt[-d]*ArcTanh[(b*Sqrt[-d] + 2*a*Sqrt[f] + (2*c*Sqrt[-d] + b*Sqrt[f])*x)/(2*Sqrt[(-c)*d + b*Sqrt[-d]*Sqrt[f] + a*f]*Sqrt[a + b*x + c*x^2])])/(2*f*Sqrt[(-c)*d + b*Sqrt[-d]*Sqrt[f] + a*f])}
{x^1/((a + b*x + c*x^2)^(1/2)*(d + f*x^2)), x, 3, -(ArcTan[(b*Sqrt[-d] - 2*a*Sqrt[f] + (2*c*Sqrt[-d] - b*Sqrt[f])*x)/(2*Sqrt[c*d + b*Sqrt[-d]*Sqrt[f] - a*f]*Sqrt[a + b*x + c*x^2])]/(2*Sqrt[f]*Sqrt[c*d + b*Sqrt[-d]*Sqrt[f] - a*f])) + ArcTan[(b*Sqrt[-d] + 2*a*Sqrt[f] + (2*c*Sqrt[-d] + b*Sqrt[f])*x)/(2*Sqrt[c*d - b*Sqrt[-d]*Sqrt[f] - a*f]*Sqrt[a + b*x + c*x^2])]/(2*Sqrt[f]*Sqrt[c*d - b*Sqrt[-d]*Sqrt[f] - a*f])}
{x^0/((a + b*x + c*x^2)^(1/2)*(d + f*x^2)), x, 3, -(ArcTanh[(b*Sqrt[-d] - 2*a*Sqrt[f] + (2*c*Sqrt[-d] - b*Sqrt[f])*x)/(2*Sqrt[(-c)*d - b*Sqrt[-d]*Sqrt[f] + a*f]*Sqrt[a + b*x + c*x^2])]/(2*Sqrt[-d]*Sqrt[(-c)*d - b*Sqrt[-d]*Sqrt[f] + a*f])) - ArcTanh[(b*Sqrt[-d] + 2*a*Sqrt[f] + (2*c*Sqrt[-d] + b*Sqrt[f])*x)/(2*Sqrt[(-c)*d + b*Sqrt[-d]*Sqrt[f] + a*f]*Sqrt[a + b*x + c*x^2])]/(2*Sqrt[-d]*Sqrt[(-c)*d + b*Sqrt[-d]*Sqrt[f] + a*f])}
{1/(x^1*(a + b*x + c*x^2)^(1/2)*(d + f*x^2)), x, 6, (Sqrt[f]*ArcTan[(b*Sqrt[-d] - 2*a*Sqrt[f] + (2*c*Sqrt[-d] - b*Sqrt[f])*x)/(2*Sqrt[c*d + b*Sqrt[-d]*Sqrt[f] - a*f]*Sqrt[a + b*x + c*x^2])])/(2*d*Sqrt[c*d + b*Sqrt[-d]*Sqrt[f] - a*f]) - (Sqrt[f]*ArcTan[(b*Sqrt[-d] + 2*a*Sqrt[f] + (2*c*Sqrt[-d] + b*Sqrt[f])*x)/(2*Sqrt[c*d - b*Sqrt[-d]*Sqrt[f] - a*f]*Sqrt[a + b*x + c*x^2])])/(2*d*Sqrt[c*d - b*Sqrt[-d]*Sqrt[f] - a*f]) - ArcTanh[(2*a + b*x)/(2*Sqrt[a]*Sqrt[a + b*x + c*x^2])]/(Sqrt[a]*d)}
{1/(x^2*(a + b*x + c*x^2)^(1/2)*(d + f*x^2)), x, 7, -(Sqrt[a + b*x + c*x^2]/(a*d*x)) + (b*ArcTanh[(2*a + b*x)/(2*Sqrt[a]*Sqrt[a + b*x + c*x^2])])/(2*a^(3/2)*d) - (f*ArcTanh[(b*Sqrt[-d] - 2*a*Sqrt[f] + (2*c*Sqrt[-d] - b*Sqrt[f])*x)/(2*Sqrt[(-c)*d - b*Sqrt[-d]*Sqrt[f] + a*f]*Sqrt[a + b*x + c*x^2])])/(2*(-d)^(3/2)*Sqrt[(-c)*d - b*Sqrt[-d]*Sqrt[f] + a*f]) - (f*ArcTanh[(b*Sqrt[-d] + 2*a*Sqrt[f] + (2*c*Sqrt[-d] + b*Sqrt[f])*x)/(2*Sqrt[(-c)*d + b*Sqrt[-d]*Sqrt[f] + a*f]*Sqrt[a + b*x + c*x^2])])/(2*(-d)^(3/2)*Sqrt[(-c)*d + b*Sqrt[-d]*Sqrt[f] + a*f])}
{1/(x^3*(a + b*x + c*x^2)^(1/2)*(d + f*x^2)), x, 10, -(Sqrt[a + b*x + c*x^2]/(2*a*d*x^2)) + (3*b*Sqrt[a + b*x + c*x^2])/(4*a^2*d*x) - (f^(3/2)*ArcTan[(b*Sqrt[-d] - 2*a*Sqrt[f] + (2*c*Sqrt[-d] - b*Sqrt[f])*x)/(2*Sqrt[c*d + b*Sqrt[-d]*Sqrt[f] - a*f]*Sqrt[a + b*x + c*x^2])])/(2*d^2*Sqrt[c*d + b*Sqrt[-d]*Sqrt[f] - a*f]) + (f^(3/2)*ArcTan[(b*Sqrt[-d] + 2*a*Sqrt[f] + (2*c*Sqrt[-d] + b*Sqrt[f])*x)/(2*Sqrt[c*d - b*Sqrt[-d]*Sqrt[f] - a*f]*Sqrt[a + b*x + c*x^2])])/(2*d^2*Sqrt[c*d - b*Sqrt[-d]*Sqrt[f] - a*f]) - ((3*b^2 - 4*a*c)*ArcTanh[(2*a + b*x)/(2*Sqrt[a]*Sqrt[a + b*x + c*x^2])])/(8*a^(5/2)*d) + (f*ArcTanh[(2*a + b*x)/(2*Sqrt[a]*Sqrt[a + b*x + c*x^2])])/(Sqrt[a]*d^2)}


{x^4/((a + b*x + c*x^2)^(3/2)*(d + f*x^2)), x, 11, (2*x*(2*a + b*x))/((b^2 - 4*a*c)*f*Sqrt[a + b*x + c*x^2]) + (2*d*(b + 2*c*x))/((b^2 - 4*a*c)*f^2*Sqrt[a + b*x + c*x^2]) - (2*d^2*(b*(c^2*d + b^2*f - 3*a*c*f) + c*(2*c^2*d + b^2*f - 2*a*c*f)*x))/((b^2 - 4*a*c)*f^2*(c^2*d^2 - 2*a*c*d*f + f*(b^2*d + a^2*f))*Sqrt[a + b*x + c*x^2]) - (2*b*Sqrt[a + b*x + c*x^2])/(c*(b^2 - 4*a*c)*f) + (d^2*(b*Sqrt[f] - (c*d - a*f)/Sqrt[-d])*ArcTan[(b*Sqrt[-d] - 2*a*Sqrt[f] + (2*c*Sqrt[-d] - b*Sqrt[f])*x)/(2*Sqrt[c*d + b*Sqrt[-d]*Sqrt[f] - a*f]*Sqrt[a + b*x + c*x^2])])/(2*f*Sqrt[c*d + b*Sqrt[-d]*Sqrt[f] - a*f]*(c^2*d^2 - 2*a*c*d*f + f*(b^2*d + a^2*f))) - (d^2*(b*Sqrt[f] + (c*d - a*f)/Sqrt[-d])*ArcTan[(b*Sqrt[-d] + 2*a*Sqrt[f] + (2*c*Sqrt[-d] + b*Sqrt[f])*x)/(2*Sqrt[c*d - b*Sqrt[-d]*Sqrt[f] - a*f]*Sqrt[a + b*x + c*x^2])])/(2*f*Sqrt[c*d - b*Sqrt[-d]*Sqrt[f] - a*f]*(c^2*d^2 - 2*a*c*d*f + f*(b^2*d + a^2*f))) + ArcTanh[(b + 2*c*x)/(2*Sqrt[c]*Sqrt[a + b*x + c*x^2])]/(c^(3/2)*f)}
{x^3/((a + b*x + c*x^2)^(3/2)*(d + f*x^2)), x, 8, (2*(2*a + b*x))/((b^2 - 4*a*c)*f*Sqrt[a + b*x + c*x^2]) - (2*d*(a*(2*c^2*d + b^2*f - 2*a*c*f) + b*c*(c*d + a*f)*x))/((b^2 - 4*a*c)*f*(c^2*d^2 - 2*a*c*d*f + f*(b^2*d + a^2*f))*Sqrt[a + b*x + c*x^2]) - (d*(c*d - b*Sqrt[-d]*Sqrt[f] - a*f)*ArcTan[(b*Sqrt[-d] - 2*a*Sqrt[f] + (2*c*Sqrt[-d] - b*Sqrt[f])*x)/(2*Sqrt[c*d + b*Sqrt[-d]*Sqrt[f] - a*f]*Sqrt[a + b*x + c*x^2])])/(2*Sqrt[f]*Sqrt[c*d + b*Sqrt[-d]*Sqrt[f] - a*f]*(c^2*d^2 - 2*a*c*d*f + f*(b^2*d + a^2*f))) + (d*(c*d + b*Sqrt[-d]*Sqrt[f] - a*f)*ArcTan[(b*Sqrt[-d] + 2*a*Sqrt[f] + (2*c*Sqrt[-d] + b*Sqrt[f])*x)/(2*Sqrt[c*d - b*Sqrt[-d]*Sqrt[f] - a*f]*Sqrt[a + b*x + c*x^2])])/(2*Sqrt[f]*Sqrt[c*d - b*Sqrt[-d]*Sqrt[f] - a*f]*(c^2*d^2 - 2*a*c*d*f + f*(b^2*d + a^2*f)))}
{x^2/((a + b*x + c*x^2)^(3/2)*(d + f*x^2)), x, 8, -((2*(b + 2*c*x))/((b^2 - 4*a*c)*f*Sqrt[a + b*x + c*x^2])) + (2*d*(b*(c^2*d + b^2*f - 3*a*c*f) + c*(2*c^2*d + b^2*f - 2*a*c*f)*x))/((b^2 - 4*a*c)*f*(c^2*d^2 - 2*a*c*d*f + f*(b^2*d + a^2*f))*Sqrt[a + b*x + c*x^2]) - (d*(b*Sqrt[f] - (c*d - a*f)/Sqrt[-d])*ArcTan[(b*Sqrt[-d] - 2*a*Sqrt[f] + (2*c*Sqrt[-d] - b*Sqrt[f])*x)/(2*Sqrt[c*d + b*Sqrt[-d]*Sqrt[f] - a*f]*Sqrt[a + b*x + c*x^2])])/(2*Sqrt[c*d + b*Sqrt[-d]*Sqrt[f] - a*f]*(c^2*d^2 - 2*a*c*d*f + f*(b^2*d + a^2*f))) + (d*(b*Sqrt[f] + (c*d - a*f)/Sqrt[-d])*ArcTan[(b*Sqrt[-d] + 2*a*Sqrt[f] + (2*c*Sqrt[-d] + b*Sqrt[f])*x)/(2*Sqrt[c*d - b*Sqrt[-d]*Sqrt[f] - a*f]*Sqrt[a + b*x + c*x^2])])/(2*Sqrt[c*d - b*Sqrt[-d]*Sqrt[f] - a*f]*(c^2*d^2 - 2*a*c*d*f + f*(b^2*d + a^2*f)))}
{x^1/((a + b*x + c*x^2)^(3/2)*(d + f*x^2)), x, 5, (2*(a*(2*c^2*d + b^2*f - 2*a*c*f) + b*c*(c*d + a*f)*x))/((b^2 - 4*a*c)*(c^2*d^2 - 2*a*c*d*f + f*(b^2*d + a^2*f))*Sqrt[a + b*x + c*x^2]) + (Sqrt[f]*(c*d - b*Sqrt[-d]*Sqrt[f] - a*f)*ArcTan[(b*Sqrt[-d] - 2*a*Sqrt[f] + (2*c*Sqrt[-d] - b*Sqrt[f])*x)/(2*Sqrt[c*d + b*Sqrt[-d]*Sqrt[f] - a*f]*Sqrt[a + b*x + c*x^2])])/(2*Sqrt[c*d + b*Sqrt[-d]*Sqrt[f] - a*f]*(c^2*d^2 - 2*a*c*d*f + f*(b^2*d + a^2*f))) - (Sqrt[f]*(c*d + b*Sqrt[-d]*Sqrt[f] - a*f)*ArcTan[(b*Sqrt[-d] + 2*a*Sqrt[f] + (2*c*Sqrt[-d] + b*Sqrt[f])*x)/(2*Sqrt[c*d - b*Sqrt[-d]*Sqrt[f] - a*f]*Sqrt[a + b*x + c*x^2])])/(2*Sqrt[c*d - b*Sqrt[-d]*Sqrt[f] - a*f]*(c^2*d^2 - 2*a*c*d*f + f*(b^2*d + a^2*f)))}
{x^0/((a + b*x + c*x^2)^(3/2)*(d + f*x^2)), x, 5, -((2*(b*(c^2*d + b^2*f - 3*a*c*f) + c*(2*c^2*d + b^2*f - 2*a*c*f)*x))/((b^2 - 4*a*c)*(c^2*d^2 - 2*a*c*d*f + f*(b^2*d + a^2*f))*Sqrt[a + b*x + c*x^2])) + (f*(b*Sqrt[f] - (c*d - a*f)/Sqrt[-d])*ArcTan[(b*Sqrt[-d] - 2*a*Sqrt[f] + (2*c*Sqrt[-d] - b*Sqrt[f])*x)/(2*Sqrt[c*d + b*Sqrt[-d]*Sqrt[f] - a*f]*Sqrt[a + b*x + c*x^2])])/(2*Sqrt[c*d + b*Sqrt[-d]*Sqrt[f] - a*f]*(c^2*d^2 - 2*a*c*d*f + f*(b^2*d + a^2*f))) - (f*(b*Sqrt[f] + (c*d - a*f)/Sqrt[-d])*ArcTan[(b*Sqrt[-d] + 2*a*Sqrt[f] + (2*c*Sqrt[-d] + b*Sqrt[f])*x)/(2*Sqrt[c*d - b*Sqrt[-d]*Sqrt[f] - a*f]*Sqrt[a + b*x + c*x^2])])/(2*Sqrt[c*d - b*Sqrt[-d]*Sqrt[f] - a*f]*(c^2*d^2 - 2*a*c*d*f + f*(b^2*d + a^2*f)))}
{1/(x^1*(a + b*x + c*x^2)^(3/2)*(d + f*x^2)), x, 9, (2*(b^2 - 2*a*c + b*c*x))/(a*(b^2 - 4*a*c)*d*Sqrt[a + b*x + c*x^2]) - (2*f*(a*(2*c^2*d + b^2*f - 2*a*c*f) + b*c*(c*d + a*f)*x))/((b^2 - 4*a*c)*d*(c^2*d^2 - 2*a*c*d*f + f*(b^2*d + a^2*f))*Sqrt[a + b*x + c*x^2]) - (f^(3/2)*(c*d - b*Sqrt[-d]*Sqrt[f] - a*f)*ArcTan[(b*Sqrt[-d] - 2*a*Sqrt[f] + (2*c*Sqrt[-d] - b*Sqrt[f])*x)/(2*Sqrt[c*d + b*Sqrt[-d]*Sqrt[f] - a*f]*Sqrt[a + b*x + c*x^2])])/(2*d*Sqrt[c*d + b*Sqrt[-d]*Sqrt[f] - a*f]*(c^2*d^2 - 2*a*c*d*f + f*(b^2*d + a^2*f))) + (f^(3/2)*(c*d + b*Sqrt[-d]*Sqrt[f] - a*f)*ArcTan[(b*Sqrt[-d] + 2*a*Sqrt[f] + (2*c*Sqrt[-d] + b*Sqrt[f])*x)/(2*Sqrt[c*d - b*Sqrt[-d]*Sqrt[f] - a*f]*Sqrt[a + b*x + c*x^2])])/(2*d*Sqrt[c*d - b*Sqrt[-d]*Sqrt[f] - a*f]*(c^2*d^2 - 2*a*c*d*f + f*(b^2*d + a^2*f))) - ArcTanh[(2*a + b*x)/(2*Sqrt[a]*Sqrt[a + b*x + c*x^2])]/(a^(3/2)*d)}
{1/(x^2*(a + b*x + c*x^2)^(3/2)*(d + f*x^2)), x, 11, (2*(b^2 - 2*a*c + b*c*x))/(a*(b^2 - 4*a*c)*d*x*Sqrt[a + b*x + c*x^2]) + (2*f*(b*(c^2*d + b^2*f - 3*a*c*f) + c*(2*c^2*d + b^2*f - 2*a*c*f)*x))/((b^2 - 4*a*c)*d*(c^2*d^2 - 2*a*c*d*f + f*(b^2*d + a^2*f))*Sqrt[a + b*x + c*x^2]) - ((3*b^2 - 8*a*c)*Sqrt[a + b*x + c*x^2])/(a^2*(b^2 - 4*a*c)*d*x) - (f^2*(b*Sqrt[f] - (c*d - a*f)/Sqrt[-d])*ArcTan[(b*Sqrt[-d] - 2*a*Sqrt[f] + (2*c*Sqrt[-d] - b*Sqrt[f])*x)/(2*Sqrt[c*d + b*Sqrt[-d]*Sqrt[f] - a*f]*Sqrt[a + b*x + c*x^2])])/(2*d*Sqrt[c*d + b*Sqrt[-d]*Sqrt[f] - a*f]*(c^2*d^2 - 2*a*c*d*f + f*(b^2*d + a^2*f))) + (f^2*(b*Sqrt[f] + (c*d - a*f)/Sqrt[-d])*ArcTan[(b*Sqrt[-d] + 2*a*Sqrt[f] + (2*c*Sqrt[-d] + b*Sqrt[f])*x)/(2*Sqrt[c*d - b*Sqrt[-d]*Sqrt[f] - a*f]*Sqrt[a + b*x + c*x^2])])/(2*d*Sqrt[c*d - b*Sqrt[-d]*Sqrt[f] - a*f]*(c^2*d^2 - 2*a*c*d*f + f*(b^2*d + a^2*f))) + (3*b*ArcTanh[(2*a + b*x)/(2*Sqrt[a]*Sqrt[a + b*x + c*x^2])])/(2*a^(5/2)*d)}


(* ::Subsection::Closed:: *)
(*Integrands of the form x^m (a+b x+c x^2)^(p/2) / (d+e x+f x^2)*)


(* ::Subsubsection::Closed:: *)
(*p>0*)


{x^2*(a + b*x + c*x^2)^(1/2)/(d + e*x + f*x^2), x, 10, -((e*Sqrt[a + b*x + c*x^2])/f^2) + ((b + 2*c*x)*Sqrt[a + b*x + c*x^2])/(4*c*f) - ((b^2 - 4*a*c)*ArcTanh[(b + 2*c*x)/(2*Sqrt[c]*Sqrt[a + b*x + c*x^2])])/(8*c^(3/2)*f) + ((2*c*e^2 - 2*c*d*f - b*e*f)*ArcTanh[(b + 2*c*x)/(2*Sqrt[c]*Sqrt[a + b*x + c*x^2])])/(2*Sqrt[c]*f^3) + ((2*d*f*(c*e^2 - c*d*f - b*e*f + a*f^2) + (e - Sqrt[e^2 - 4*d*f])*(f*(b*e^2 - b*d*f - a*e*f) - c*(e^3 - 2*d*e*f)))*ArcTanh[(4*a*f - b*(e - Sqrt[e^2 - 4*d*f]) + 2*(b*f - c*(e - Sqrt[e^2 - 4*d*f]))*x)/(2*Sqrt[4*a*f^2 - 2*b*f*(e - Sqrt[e^2 - 4*d*f]) + c*(e - Sqrt[e^2 - 4*d*f])^2]*Sqrt[a + b*x + c*x^2])])/(f^3*Sqrt[e^2 - 4*d*f]*Sqrt[4*a*f^2 - 2*b*f*(e - Sqrt[e^2 - 4*d*f]) + c*(e - Sqrt[e^2 - 4*d*f])^2]) - ((2*d*f*(c*e^2 - c*d*f - b*e*f + a*f^2) + (e + Sqrt[e^2 - 4*d*f])*(f*(b*e^2 - b*d*f - a*e*f) - c*(e^3 - 2*d*e*f)))*ArcTanh[(4*a*f - b*(e + Sqrt[e^2 - 4*d*f]) + 2*(b*f - c*(e + Sqrt[e^2 - 4*d*f]))*x)/(2*Sqrt[4*a*f^2 - 2*b*f*(e + Sqrt[e^2 - 4*d*f]) + c*(e + Sqrt[e^2 - 4*d*f])^2]*Sqrt[a + b*x + c*x^2])])/(f^3*Sqrt[e^2 - 4*d*f]*Sqrt[4*a*f^2 - 2*b*f*(e + Sqrt[e^2 - 4*d*f]) + c*(e + Sqrt[e^2 - 4*d*f])^2])}
{x^1*(a + b*x + c*x^2)^(1/2)/(d + e*x + f*x^2), x, 6, Sqrt[a + b*x + c*x^2]/f - ((2*c*e - b*f)*ArcTanh[(b + 2*c*x)/(2*Sqrt[c]*Sqrt[a + b*x + c*x^2])])/(2*Sqrt[c]*f^2) - ((2*d*f*(c*e - b*f) + (e - Sqrt[e^2 - 4*d*f])*(f*(b*e - a*f) - c*(e^2 - d*f)))*ArcTanh[(4*a*f - b*(e - Sqrt[e^2 - 4*d*f]) + 2*(b*f - c*(e - Sqrt[e^2 - 4*d*f]))*x)/(2*Sqrt[4*a*f^2 - 2*b*f*(e - Sqrt[e^2 - 4*d*f]) + c*(e - Sqrt[e^2 - 4*d*f])^2]*Sqrt[a + b*x + c*x^2])])/(f^2*Sqrt[e^2 - 4*d*f]*Sqrt[4*a*f^2 - 2*b*f*(e - Sqrt[e^2 - 4*d*f]) + c*(e - Sqrt[e^2 - 4*d*f])^2]) + ((2*d*f*(c*e - b*f) + (e + Sqrt[e^2 - 4*d*f])*(f*(b*e - a*f) - c*(e^2 - d*f)))*ArcTanh[(4*a*f - b*(e + Sqrt[e^2 - 4*d*f]) + 2*(b*f - c*(e + Sqrt[e^2 - 4*d*f]))*x)/(2*Sqrt[4*a*f^2 - 2*b*f*(e + Sqrt[e^2 - 4*d*f]) + c*(e + Sqrt[e^2 - 4*d*f])^2]*Sqrt[a + b*x + c*x^2])])/(f^2*Sqrt[e^2 - 4*d*f]*Sqrt[4*a*f^2 - 2*b*f*(e + Sqrt[e^2 - 4*d*f]) + c*(e + Sqrt[e^2 - 4*d*f])^2])}
{x^0*(a + b*x + c*x^2)^(1/2)/(d + e*x + f*x^2), x, 5, (Sqrt[c]*ArcTanh[(b + 2*c*x)/(2*Sqrt[c]*Sqrt[a + b*x + c*x^2])])/f - (Sqrt[c*(e^2 - 2*d*f - e*Sqrt[e^2 - 4*d*f]) + f*(2*a*f - b*(e - Sqrt[e^2 - 4*d*f]))]*ArcTanh[(4*a*f - b*(e - Sqrt[e^2 - 4*d*f]) + 2*(b*f - c*(e - Sqrt[e^2 - 4*d*f]))*x)/(2*Sqrt[4*a*f^2 - 2*b*f*(e - Sqrt[e^2 - 4*d*f]) + c*(e - Sqrt[e^2 - 4*d*f])^2]*Sqrt[a + b*x + c*x^2])])/(Sqrt[2]*f*Sqrt[e^2 - 4*d*f]) + (Sqrt[c*(e^2 - 2*d*f + e*Sqrt[e^2 - 4*d*f]) + f*(2*a*f - b*(e + Sqrt[e^2 - 4*d*f]))]*ArcTanh[(4*a*f - b*(e + Sqrt[e^2 - 4*d*f]) + 2*(b*f - c*(e + Sqrt[e^2 - 4*d*f]))*x)/(2*Sqrt[4*a*f^2 - 2*b*f*(e + Sqrt[e^2 - 4*d*f]) + c*(e + Sqrt[e^2 - 4*d*f])^2]*Sqrt[a + b*x + c*x^2])])/(Sqrt[2]*f*Sqrt[e^2 - 4*d*f])}
{1/x^1*(a + b*x + c*x^2)^(1/2)/(d + e*x + f*x^2), x, 12, -((Sqrt[a]*ArcTanh[(2*a + b*x)/(2*Sqrt[a]*Sqrt[a + b*x + c*x^2])])/d) - ((2*(b*d - a*e)*f - (c*d - a*f)*(e - Sqrt[e^2 - 4*d*f]))*ArcTanh[(4*a*f - b*(e - Sqrt[e^2 - 4*d*f]) + 2*(b*f - c*(e - Sqrt[e^2 - 4*d*f]))*x)/(2*Sqrt[4*a*f^2 - 2*b*f*(e - Sqrt[e^2 - 4*d*f]) + c*(e - Sqrt[e^2 - 4*d*f])^2]*Sqrt[a + b*x + c*x^2])])/(d*Sqrt[e^2 - 4*d*f]*Sqrt[4*a*f^2 - 2*b*f*(e - Sqrt[e^2 - 4*d*f]) + c*(e - Sqrt[e^2 - 4*d*f])^2]) + ((2*(b*d - a*e)*f - (c*d - a*f)*(e + Sqrt[e^2 - 4*d*f]))*ArcTanh[(4*a*f - b*(e + Sqrt[e^2 - 4*d*f]) + 2*(b*f - c*(e + Sqrt[e^2 - 4*d*f]))*x)/(2*Sqrt[4*a*f^2 - 2*b*f*(e + Sqrt[e^2 - 4*d*f]) + c*(e + Sqrt[e^2 - 4*d*f])^2]*Sqrt[a + b*x + c*x^2])])/(d*Sqrt[e^2 - 4*d*f]*Sqrt[4*a*f^2 - 2*b*f*(e + Sqrt[e^2 - 4*d*f]) + c*(e + Sqrt[e^2 - 4*d*f])^2])}
{1/x^2*(a + b*x + c*x^2)^(1/2)/(d + e*x + f*x^2), x, 16, -(Sqrt[a + b*x + c*x^2]/(d*x)) - (b*ArcTanh[(2*a + b*x)/(2*Sqrt[a]*Sqrt[a + b*x + c*x^2])])/(2*Sqrt[a]*d) + (Sqrt[a]*e*ArcTanh[(2*a + b*x)/(2*Sqrt[a]*Sqrt[a + b*x + c*x^2])])/d^2 + (Sqrt[c]*ArcTanh[(b + 2*c*x)/(2*Sqrt[c]*Sqrt[a + b*x + c*x^2])])/d - (b*e*ArcTanh[(b + 2*c*x)/(2*Sqrt[c]*Sqrt[a + b*x + c*x^2])])/(2*Sqrt[c]*d^2) - ((2*c*d - b*e)*ArcTanh[(b + 2*c*x)/(2*Sqrt[c]*Sqrt[a + b*x + c*x^2])])/(2*Sqrt[c]*d^2) - (f*(2*c*d^2 - b*d*(e + Sqrt[e^2 - 4*d*f]) + a*(e^2 - 2*d*f + e*Sqrt[e^2 - 4*d*f]))*ArcTanh[(4*a*f - b*(e - Sqrt[e^2 - 4*d*f]) + 2*(b*f - c*(e - Sqrt[e^2 - 4*d*f]))*x)/(2*Sqrt[4*a*f^2 - 2*b*f*(e - Sqrt[e^2 - 4*d*f]) + c*(e - Sqrt[e^2 - 4*d*f])^2]*Sqrt[a + b*x + c*x^2])])/(d^2*Sqrt[e^2 - 4*d*f]*Sqrt[4*a*f^2 - 2*b*f*(e - Sqrt[e^2 - 4*d*f]) + c*(e - Sqrt[e^2 - 4*d*f])^2]) + (f*((b*d - a*e)*(e + Sqrt[e^2 - 4*d*f]) + 2*(c*d^2 - b*d*e + a*(e^2 - d*f)))*ArcTanh[(4*a*f - b*(e + Sqrt[e^2 - 4*d*f]) + 2*(b*f - c*(e + Sqrt[e^2 - 4*d*f]))*x)/(2*Sqrt[4*a*f^2 - 2*b*f*(e + Sqrt[e^2 - 4*d*f]) + c*(e + Sqrt[e^2 - 4*d*f])^2]*Sqrt[a + b*x + c*x^2])])/(d^2*Sqrt[e^2 - 4*d*f]*Sqrt[4*a*f^2 - 2*b*f*(e + Sqrt[e^2 - 4*d*f]) + c*(e + Sqrt[e^2 - 4*d*f])^2])}
{1/x^3*(a + b*x + c*x^2)^(1/2)/(d + e*x + f*x^2), x, 18, (e*Sqrt[a + b*x + c*x^2])/(d^2*x) - ((2*a + b*x)*Sqrt[a + b*x + c*x^2])/(4*a*d*x^2) + ((b^2 - 4*a*c)*ArcTanh[(2*a + b*x)/(2*Sqrt[a]*Sqrt[a + b*x + c*x^2])])/(8*a^(3/2)*d) + (b*e*ArcTanh[(2*a + b*x)/(2*Sqrt[a]*Sqrt[a + b*x + c*x^2])])/(2*Sqrt[a]*d^2) - (Sqrt[a]*(e^2 - d*f)*ArcTanh[(2*a + b*x)/(2*Sqrt[a]*Sqrt[a + b*x + c*x^2])])/d^3 - (Sqrt[c]*e*ArcTanh[(b + 2*c*x)/(2*Sqrt[c]*Sqrt[a + b*x + c*x^2])])/d^2 + (b*(e^2 - d*f)*ArcTanh[(b + 2*c*x)/(2*Sqrt[c]*Sqrt[a + b*x + c*x^2])])/(2*Sqrt[c]*d^3) + ((2*c*d*e - b*e^2 + b*d*f)*ArcTanh[(b + 2*c*x)/(2*Sqrt[c]*Sqrt[a + b*x + c*x^2])])/(2*Sqrt[c]*d^3) - (f*((e - Sqrt[e^2 - 4*d*f])*(c*d^2 - b*d*e + a*(e^2 - d*f)) - 2*(c*d^2*e + a*e*(e^2 - 2*d*f) - b*d*(e^2 - d*f)))*ArcTanh[(4*a*f - b*(e - Sqrt[e^2 - 4*d*f]) + 2*(b*f - c*(e - Sqrt[e^2 - 4*d*f]))*x)/(2*Sqrt[4*a*f^2 - 2*b*f*(e - Sqrt[e^2 - 4*d*f]) + c*(e - Sqrt[e^2 - 4*d*f])^2]*Sqrt[a + b*x + c*x^2])])/(d^3*Sqrt[e^2 - 4*d*f]*Sqrt[4*a*f^2 - 2*b*f*(e - Sqrt[e^2 - 4*d*f]) + c*(e - Sqrt[e^2 - 4*d*f])^2]) + (f*((e + Sqrt[e^2 - 4*d*f])*(c*d^2 - b*d*e + a*(e^2 - d*f)) - 2*(c*d^2*e + a*e*(e^2 - 2*d*f) - b*d*(e^2 - d*f)))*ArcTanh[(4*a*f - b*(e + Sqrt[e^2 - 4*d*f]) + 2*(b*f - c*(e + Sqrt[e^2 - 4*d*f]))*x)/(2*Sqrt[4*a*f^2 - 2*b*f*(e + Sqrt[e^2 - 4*d*f]) + c*(e + Sqrt[e^2 - 4*d*f])^2]*Sqrt[a + b*x + c*x^2])])/(d^3*Sqrt[e^2 - 4*d*f]*Sqrt[4*a*f^2 - 2*b*f*(e + Sqrt[e^2 - 4*d*f]) + c*(e + Sqrt[e^2 - 4*d*f])^2])}


(* {x^2*(a + b*x + c*x^2)^(3/2)/(d + e*x + f*x^2), x, 15, ((d*f*(c*e - b*f) + e*(f*(c*d - a*f) - e*(c*e - b*f)))*Sqrt[a + b*x + c*x^2])/f^4 - (3*(b^2 - 4*a*c)*(b + 2*c*x)*Sqrt[a + b*x + c*x^2])/(64*c^2*f) + ((2*c*e^2 - 2*c*d*f - b*e*f)*(b + 2*c*x)*Sqrt[a + b*x + c*x^2])/(8*c*f^3) - (e*(a + b*x + c*x^2)^(3/2))/(3*f^2) + ((b + 2*c*x)*(a + b*x + c*x^2)^(3/2))/(8*c*f) + (3*(b^2 - 4*a*c)^2*ArcTanh[(b + 2*c*x)/(2*Sqrt[c]*Sqrt[a + b*x + c*x^2])])/(128*c^(5/2)*f) - ((b^2 - 4*a*c)*(2*c*e^2 - 2*c*d*f - b*e*f)*ArcTanh[(b + 2*c*x)/(2*Sqrt[c]*Sqrt[a + b*x + c*x^2])])/(16*c^(3/2)*f^3) - ((3*b*c*e^3*f - e*(6*b*c*d + (b^2 + 2*a*c)*e)*f^2 + (b^2*d + 2*a*c*d + a*b*e)*f^3 - 2*c^2*(e^4 - 3*d*e^2*f + d^2*f^2))*ArcTanh[(b + 2*c*x)/(2*Sqrt[c]*Sqrt[a + b*x + c*x^2])])/(2*Sqrt[c]*f^5) + (((f*(c*d - a*f) - e*(c*e - b*f))*(e - Sqrt[e^2 - 4*d*f])*(2*d*f*(c*e - b*f) + e*(f*(c*d - a*f) - e*(c*e - b*f))) - 2*d*f*(f*(c*d - a*f)*(f*(c*d - a*f) - e*(c*e - b*f)) - (c*e - b*f)*(d*f*(c*e - b*f) + e*(f*(c*d - a*f) - e*(c*e - b*f)))))*ArcTanh[(b*e - 4*a*f - b*Sqrt[e^2 - 4*d*f] + 2*(c*e - b*f - c*Sqrt[e^2 - 4*d*f])*x)/(2*Sqrt[2]*Sqrt[c*e^2 - 2*c*d*f - b*e*f + 2*a*f^2 - (c*e - b*f)*Sqrt[e^2 - 4*d*f]]*Sqrt[a + b*x + c*x^2])])/(f^5*Sqrt[e^2 - 4*d*f]*Sqrt[4*a*f^2 - 2*b*f*(e - Sqrt[e^2 - 4*d*f]) + c*(e - Sqrt[e^2 - 4*d*f])^2]) - (((f*(c*d - a*f) - e*(c*e - b*f))*(e + Sqrt[e^2 - 4*d*f])*(2*d*f*(c*e - b*f) + e*(f*(c*d - a*f) - e*(c*e - b*f))) - 2*d*f*(f*(c*d - a*f)*(f*(c*d - a*f) - e*(c*e - b*f)) - (c*e - b*f)*(d*f*(c*e - b*f) + e*(f*(c*d - a*f) - e*(c*e - b*f)))))*ArcTanh[(b*e - 4*a*f + b*Sqrt[e^2 - 4*d*f] + 2*(c*e - b*f + c*Sqrt[e^2 - 4*d*f])*x)/(2*Sqrt[2]*Sqrt[c*e^2 - 2*c*d*f - b*e*f + 2*a*f^2 + (c*e - b*f)*Sqrt[e^2 - 4*d*f]]*Sqrt[a + b*x + c*x^2])])/(f^5*Sqrt[e^2 - 4*d*f]*Sqrt[4*a*f^2 - 2*b*f*(e + Sqrt[e^2 - 4*d*f]) + c*(e + Sqrt[e^2 - 4*d*f])^2])}
{x^1*(a + b*x + c*x^2)^(3/2)/(d + e*x + f*x^2), x, 10, ((c*e^2 - c*d*f - b*e*f + a*f^2)*Sqrt[a + b*x + c*x^2])/f^3 - ((2*c*e - b*f)*(b + 2*c*x)*Sqrt[a + b*x + c*x^2])/(8*c*f^2) + (a + b*x + c*x^2)^(3/2)/(3*f) + ((b^2 - 4*a*c)*(2*c*e - b*f)*ArcTanh[(b + 2*c*x)/(2*Sqrt[c]*Sqrt[a + b*x + c*x^2])])/(16*c^(3/2)*f^2) + ((3*b*c*e^2*f - (3*b*c*d + b^2*e + 2*a*c*e)*f^2 + a*b*f^3 - 2*c^2*e*(e^2 - 2*d*f))*ArcTanh[(b + 2*c*x)/(2*Sqrt[c]*Sqrt[a + b*x + c*x^2])])/(2*Sqrt[c]*f^4) + ((2*d*f*(c*e - b*f)*(c*e^2 - 2*c*d*f - b*e*f + 2*a*f^2) + (e - Sqrt[e^2 - 4*d*f])*(2*b*c*e^3*f - e*(4*b*c*d + (b^2 + 2*a*c)*e)*f^2 + (b^2*d + 2*a*c*d + 2*a*b*e)*f^3 - a^2*f^4 - c^2*(e^4 - 3*d*e^2*f + d^2*f^2)))*ArcTanh[(b*e - 4*a*f - b*Sqrt[e^2 - 4*d*f] + 2*(c*e - b*f - c*Sqrt[e^2 - 4*d*f])*x)/(2*Sqrt[2]*Sqrt[c*e^2 - 2*c*d*f - b*e*f + 2*a*f^2 - (c*e - b*f)*Sqrt[e^2 - 4*d*f]]*Sqrt[a + b*x + c*x^2])])/(f^4*Sqrt[e^2 - 4*d*f]*Sqrt[4*a*f^2 - 2*b*f*(e - Sqrt[e^2 - 4*d*f]) + c*(e - Sqrt[e^2 - 4*d*f])^2]) - ((2*d*f*(c*e - b*f)*(c*e^2 - 2*c*d*f - b*e*f + 2*a*f^2) + (e + Sqrt[e^2 - 4*d*f])*(2*b*c*e^3*f - e*(4*b*c*d + (b^2 + 2*a*c)*e)*f^2 + (b^2*d + 2*a*c*d + 2*a*b*e)*f^3 - a^2*f^4 - c^2*(e^4 - 3*d*e^2*f + d^2*f^2)))*ArcTanh[(b*e - 4*a*f + b*Sqrt[e^2 - 4*d*f] + 2*(c*e - b*f + c*Sqrt[e^2 - 4*d*f])*x)/(2*Sqrt[2]*Sqrt[c*e^2 - 2*c*d*f - b*e*f + 2*a*f^2 + (c*e - b*f)*Sqrt[e^2 - 4*d*f]]*Sqrt[a + b*x + c*x^2])])/(f^4*Sqrt[e^2 - 4*d*f]*Sqrt[4*a*f^2 - 2*b*f*(e + Sqrt[e^2 - 4*d*f]) + c*(e + Sqrt[e^2 - 4*d*f])^2])}
{x^0*(a + b*x + c*x^2)^(3/2)/(d + e*x + f*x^2), x, 9, -(((c*e - b*f)*Sqrt[a + b*x + c*x^2])/f^2) + ((b + 2*c*x)*Sqrt[a + b*x + c*x^2])/(4*f) - ((b^2 - 4*a*c)*ArcTanh[(b + 2*c*x)/(2*Sqrt[c]*Sqrt[a + b*x + c*x^2])])/(8*Sqrt[c]*f) - ((3*b*c*e*f - (b^2 + 2*a*c)*f^2 - 2*c^2*(e^2 - d*f))*ArcTanh[(b + 2*c*x)/(2*Sqrt[c]*Sqrt[a + b*x + c*x^2])])/(2*Sqrt[c]*f^3) + (((c*e - b*f)*(c*e^2 - 2*c*d*f - b*e*f + 2*a*f^2)*(e - Sqrt[e^2 - 4*d*f]) + 2*f*(2*b*c*d*e*f - (b^2 + 2*a*c)*d*f^2 + a^2*f^3 - c^2*d*(e^2 - d*f)))*ArcTanh[(b*e - 4*a*f - b*Sqrt[e^2 - 4*d*f] + 2*(c*e - b*f - c*Sqrt[e^2 - 4*d*f])*x)/(2*Sqrt[2]*Sqrt[c*e^2 - 2*c*d*f - b*e*f + 2*a*f^2 - (c*e - b*f)*Sqrt[e^2 - 4*d*f]]*Sqrt[a + b*x + c*x^2])])/(f^3*Sqrt[e^2 - 4*d*f]*Sqrt[4*a*f^2 - 2*b*f*(e - Sqrt[e^2 - 4*d*f]) + c*(e - Sqrt[e^2 - 4*d*f])^2]) - (((c*e - b*f)*(c*e^2 - 2*c*d*f - b*e*f + 2*a*f^2)*(e + Sqrt[e^2 - 4*d*f]) + 2*f*(2*b*c*d*e*f - (b^2 + 2*a*c)*d*f^2 + a^2*f^3 - c^2*d*(e^2 - d*f)))*ArcTanh[(b*e - 4*a*f + b*Sqrt[e^2 - 4*d*f] + 2*(c*e - b*f + c*Sqrt[e^2 - 4*d*f])*x)/(2*Sqrt[2]*Sqrt[c*e^2 - 2*c*d*f - b*e*f + 2*a*f^2 + (c*e - b*f)*Sqrt[e^2 - 4*d*f]]*Sqrt[a + b*x + c*x^2])])/(f^3*Sqrt[e^2 - 4*d*f]*Sqrt[4*a*f^2 - 2*b*f*(e + Sqrt[e^2 - 4*d*f]) + c*(e + Sqrt[e^2 - 4*d*f])^2])}
{1/x^1*(a + b*x + c*x^2)^(3/2)/(d + e*x + f*x^2), x, 17, ((c*d - a*f)*Sqrt[a + b*x + c*x^2])/(d*f) - (b*(b + 2*c*x)*Sqrt[a + b*x + c*x^2])/(8*c*d) + ((b^2 + 8*a*c + 2*b*c*x)*Sqrt[a + b*x + c*x^2])/(8*c*d) - (a^(3/2)*ArcTanh[(2*a + b*x)/(2*Sqrt[a]*Sqrt[a + b*x + c*x^2])])/d - (b*(b^2 - 12*a*c)*ArcTanh[(b + 2*c*x)/(2*Sqrt[c]*Sqrt[a + b*x + c*x^2])])/(16*c^(3/2)*d) + (b*(b^2 - 4*a*c)*ArcTanh[(b + 2*c*x)/(2*Sqrt[c]*Sqrt[a + b*x + c*x^2])])/(16*c^(3/2)*d) - ((2*c^2*d*e - 3*b*c*d*f + a*b*f^2)*ArcTanh[(b + 2*c*x)/(2*Sqrt[c]*Sqrt[a + b*x + c*x^2])])/(2*Sqrt[c]*d*f^2) + ((2*f*(c*d - a*f)*(c*d*e - 2*b*d*f + a*e*f) + (e - Sqrt[e^2 - 4*d*f])*(2*b*c*d*e*f - (b^2 + 2*a*c)*d*f^2 + a^2*f^3 - c^2*d*(e^2 - d*f)))*ArcTanh[(b*e - 4*a*f - b*Sqrt[e^2 - 4*d*f] + 2*(c*e - b*f - c*Sqrt[e^2 - 4*d*f])*x)/(2*Sqrt[2]*Sqrt[c*e^2 - 2*c*d*f - b*e*f + 2*a*f^2 - (c*e - b*f)*Sqrt[e^2 - 4*d*f]]*Sqrt[a + b*x + c*x^2])])/(d*f^2*Sqrt[e^2 - 4*d*f]*Sqrt[4*a*f^2 - 2*b*f*(e - Sqrt[e^2 - 4*d*f]) + c*(e - Sqrt[e^2 - 4*d*f])^2]) - ((2*f*(c*d - a*f)*(c*d*e - 2*b*d*f + a*e*f) + (e + Sqrt[e^2 - 4*d*f])*(2*b*c*d*e*f - (b^2 + 2*a*c)*d*f^2 + a^2*f^3 - c^2*d*(e^2 - d*f)))*ArcTanh[(b*e - 4*a*f + b*Sqrt[e^2 - 4*d*f] + 2*(c*e - b*f + c*Sqrt[e^2 - 4*d*f])*x)/(2*Sqrt[2]*Sqrt[c*e^2 - 2*c*d*f - b*e*f + 2*a*f^2 + (c*e - b*f)*Sqrt[e^2 - 4*d*f]]*Sqrt[a + b*x + c*x^2])])/(d*f^2*Sqrt[e^2 - 4*d*f]*Sqrt[4*a*f^2 - 2*b*f*(e + Sqrt[e^2 - 4*d*f]) + c*(e + Sqrt[e^2 - 4*d*f])^2])}
{1/x^2*(a + b*x + c*x^2)^(3/2)/(d + e*x + f*x^2), x, 22, -(((b*d - a*e)*Sqrt[a + b*x + c*x^2])/d^2) - ((2*c*d - b*e)*(b + 2*c*x)*Sqrt[a + b*x + c*x^2])/(8*c*d^2) + (3*(3*b + 2*c*x)*Sqrt[a + b*x + c*x^2])/(4*d) - (e*(b^2 + 8*a*c + 2*b*c*x)*Sqrt[a + b*x + c*x^2])/(8*c*d^2) - (a + b*x + c*x^2)^(3/2)/(d*x) - (3*Sqrt[a]*b*ArcTanh[(2*a + b*x)/(2*Sqrt[a]*Sqrt[a + b*x + c*x^2])])/(2*d) + (a^(3/2)*e*ArcTanh[(2*a + b*x)/(2*Sqrt[a]*Sqrt[a + b*x + c*x^2])])/d^2 + (3*(b^2 + 4*a*c)*ArcTanh[(b + 2*c*x)/(2*Sqrt[c]*Sqrt[a + b*x + c*x^2])])/(8*Sqrt[c]*d) + (b*(b^2 - 12*a*c)*e*ArcTanh[(b + 2*c*x)/(2*Sqrt[c]*Sqrt[a + b*x + c*x^2])])/(16*c^(3/2)*d^2) + ((b^2 - 4*a*c)*(2*c*d - b*e)*ArcTanh[(b + 2*c*x)/(2*Sqrt[c]*Sqrt[a + b*x + c*x^2])])/(16*c^(3/2)*d^2) + ((2*c^2*d^2 - b^2*d*f - 2*a*c*d*f + a*b*e*f)*ArcTanh[(b + 2*c*x)/(2*Sqrt[c]*Sqrt[a + b*x + c*x^2])])/(2*Sqrt[c]*d^2*f) - ((2*a^2*d*f^3 + a*f^2*(2*b*d*e + 2*b*d*Sqrt[e^2 - 4*d*f] - a*e*(e + Sqrt[e^2 - 4*d*f])) + d^2*(2*f*(b*c*e - (b^2 + 2*a*c)*f - b*c*Sqrt[e^2 - 4*d*f]) + c^2*(2*d*f - e*(e - Sqrt[e^2 - 4*d*f]))))*ArcTanh[(b*e - 4*a*f - b*Sqrt[e^2 - 4*d*f] + 2*(c*e - b*f - c*Sqrt[e^2 - 4*d*f])*x)/(2*Sqrt[2]*Sqrt[c*e^2 - 2*c*d*f - b*e*f + 2*a*f^2 - (c*e - b*f)*Sqrt[e^2 - 4*d*f]]*Sqrt[a + b*x + c*x^2])])/(d^2*f*Sqrt[e^2 - 4*d*f]*Sqrt[4*a*f^2 - 2*b*f*(e - Sqrt[e^2 - 4*d*f]) + c*(e - Sqrt[e^2 - 4*d*f])^2]) + ((2*a^2*d*f^3 + a*f^2*(2*b*d*e - 2*b*d*Sqrt[e^2 - 4*d*f] - a*e*(e - Sqrt[e^2 - 4*d*f])) + d^2*(2*f*(b*c*e - (b^2 + 2*a*c)*f + b*c*Sqrt[e^2 - 4*d*f]) + c^2*(2*d*f - e*(e + Sqrt[e^2 - 4*d*f]))))*ArcTanh[(b*e - 4*a*f + b*Sqrt[e^2 - 4*d*f] + 2*(c*e - b*f + c*Sqrt[e^2 - 4*d*f])*x)/(2*Sqrt[2]*Sqrt[c*e^2 - 2*c*d*f - b*e*f + 2*a*f^2 + (c*e - b*f)*Sqrt[e^2 - 4*d*f]]*Sqrt[a + b*x + c*x^2])])/(d^2*f*Sqrt[e^2 - 4*d*f]*Sqrt[4*a*f^2 - 2*b*f*(e + Sqrt[e^2 - 4*d*f]) + c*(e + Sqrt[e^2 - 4*d*f])^2])}
{1/x^3*(a + b*x + c*x^2)^(3/2)/(d + e*x + f*x^2), x, 27, ((e*(c*e - b*f)*(e^2 - 2*d*f) + (e^2 - d*f)*(f*(c*d - a*f) - e*(c*e - b*f)))*Sqrt[a + b*x + c*x^2])/(d^3*f^2) - (3*(b - 2*c*x)*Sqrt[a + b*x + c*x^2])/(4*d*x) + ((2*c*d*e - b*e^2 + b*d*f)*(b + 2*c*x)*Sqrt[a + b*x + c*x^2])/(8*c*d^3) - (3*e*(3*b + 2*c*x)*Sqrt[a + b*x + c*x^2])/(4*d^2) + ((e^2 - d*f)*(b^2 + 8*a*c + 2*b*c*x)*Sqrt[a + b*x + c*x^2])/(8*c*d^3) - (a + b*x + c*x^2)^(3/2)/(2*d*x^2) + (e*(a + b*x + c*x^2)^(3/2))/(d^2*x) - (3*(b^2 + 4*a*c)*ArcTanh[(2*a + b*x)/(2*Sqrt[a]*Sqrt[a + b*x + c*x^2])])/(8*Sqrt[a]*d) + (3*Sqrt[a]*b*e*ArcTanh[(2*a + b*x)/(2*Sqrt[a]*Sqrt[a + b*x + c*x^2])])/(2*d^2) - (a^(3/2)*(e^2 - d*f)*ArcTanh[(2*a + b*x)/(2*Sqrt[a]*Sqrt[a + b*x + c*x^2])])/d^3 + (3*b*Sqrt[c]*ArcTanh[(b + 2*c*x)/(2*Sqrt[c]*Sqrt[a + b*x + c*x^2])])/(2*d) - (3*(b^2 + 4*a*c)*e*ArcTanh[(b + 2*c*x)/(2*Sqrt[c]*Sqrt[a + b*x + c*x^2])])/(8*Sqrt[c]*d^2) - (b*(b^2 - 12*a*c)*(e^2 - d*f)*ArcTanh[(b + 2*c*x)/(2*Sqrt[c]*Sqrt[a + b*x + c*x^2])])/(16*c^(3/2)*d^3) - ((b^2 - 4*a*c)*(2*c*d*e - b*e^2 + b*d*f)*ArcTanh[(b + 2*c*x)/(2*Sqrt[c]*Sqrt[a + b*x + c*x^2])])/(16*c^(3/2)*d^3) - ((3*b*c*d^2 - b^2*d*e - 2*a*c*d*e + a*b*e^2 - a*b*d*f)*ArcTanh[(b + 2*c*x)/(2*Sqrt[c]*Sqrt[a + b*x + c*x^2])])/(2*Sqrt[c]*d^3) - (1/(d^3*f^3*Sqrt[e^2 - 4*d*f]*Sqrt[4*a*f^2 - 2*b*f*(e - Sqrt[e^2 - 4*d*f]) + c*(e - Sqrt[e^2 - 4*d*f])^2]))*((2*f*(f*(c*d - a*f)*(e*(c*d - a*f)*(e^2 - 2*d*f) - d*(c*e - b*f)*(e^2 - d*f)) - d*(c*e - b*f)*(e*(c*e - b*f)*(e^2 - 2*d*f) + (e^2 - d*f)*(f*(c*d - a*f) - e*(c*e - b*f)))) - (e - Sqrt[e^2 - 4*d*f])*(f*(c*e - b*f)*(e*(c*d - a*f)*(e^2 - 2*d*f) - d*(c*e - b*f)*(e^2 - d*f)) + (f*(c*d - a*f) - e*(c*e - b*f))*(e*(c*e - b*f)*(e^2 - 2*d*f) + (e^2 - d*f)*(f*(c*d - a*f) - e*(c*e - b*f)))))*ArcTanh[(b*e - 4*a*f - b*Sqrt[e^2 - 4*d*f] + 2*(c*e - b*f - c*Sqrt[e^2 - 4*d*f])*x)/(2*Sqrt[2]*Sqrt[c*e^2 - 2*c*d*f - b*e*f + 2*a*f^2 - (c*e - b*f)*Sqrt[e^2 - 4*d*f]]*Sqrt[a + b*x + c*x^2])]) + (1/(d^3*f^3*Sqrt[e^2 - 4*d*f]*Sqrt[4*a*f^2 - 2*b*f*(e + Sqrt[e^2 - 4*d*f]) + c*(e + Sqrt[e^2 - 4*d*f])^2]))*((2*f*(f*(c*d - a*f)*(e*(c*d - a*f)*(e^2 - 2*d*f) - d*(c*e - b*f)*(e^2 - d*f)) - d*(c*e - b*f)*(e*(c*e - b*f)*(e^2 - 2*d*f) + (e^2 - d*f)*(f*(c*d - a*f) - e*(c*e - b*f)))) - (e + Sqrt[e^2 - 4*d*f])*(f*(c*e - b*f)*(e*(c*d - a*f)*(e^2 - 2*d*f) - d*(c*e - b*f)*(e^2 - d*f)) + (f*(c*d - a*f) - e*(c*e - b*f))*(e*(c*e - b*f)*(e^2 - 2*d*f) + (e^2 - d*f)*(f*(c*d - a*f) - e*(c*e - b*f)))))*ArcTanh[(b*e - 4*a*f + b*Sqrt[e^2 - 4*d*f] + 2*(c*e - b*f + c*Sqrt[e^2 - 4*d*f])*x)/(2*Sqrt[2]*Sqrt[c*e^2 - 2*c*d*f - b*e*f + 2*a*f^2 + (c*e - b*f)*Sqrt[e^2 - 4*d*f]]*Sqrt[a + b*x + c*x^2])])} *)


{Sqrt[-3 - 4*x - x^2]/(3 + 4*x + 2*x^2), x, 5, ArcTan[Sqrt[-1 - x]/Sqrt[3 + x]] + ArcTan[(1 - (3*Sqrt[-1 - x])/Sqrt[3 + x])/Sqrt[2]]/Sqrt[2] - ArcTan[(1 + (3*Sqrt[-1 - x])/Sqrt[3 + x])/Sqrt[2]]/Sqrt[2] - (1/4)*Log[1 - (3*(1 + x))/(3 + x) - (2*Sqrt[-1 - x])/Sqrt[3 + x]] + (1/4)*Log[1 - (3*(1 + x))/(3 + x) + (2*Sqrt[-1 - x])/Sqrt[3 + x]], (-(1/2))*ArcSin[2 + x] - ((I + 2*Sqrt[2])*ArcTanh[(2*I + Sqrt[2] + (I + Sqrt[2])*x)/(Sqrt[1 - 2*I*Sqrt[2]]*Sqrt[-3 - 4*x - x^2])])/(4*Sqrt[1 - 2*I*Sqrt[2]]) + ((I - 2*Sqrt[2])*ArcTanh[(2*(1 - I*Sqrt[2]) - I*(2*I + Sqrt[2])*x)/(Sqrt[2*(1 + 2*I*Sqrt[2])]*Sqrt[-3 - 4*x - x^2])])/(4*Sqrt[1 + 2*I*Sqrt[2]])}


(* ::Subsubsection::Closed:: *)
(*p<0*)


{x^3/((a + b*x + c*x^2)^(1/2)*(d + e*x + f*x^2)), x, 8, Sqrt[a + b*x + c*x^2]/(c*f) - (e*ArcTanh[(b + 2*c*x)/(2*Sqrt[c]*Sqrt[a + b*x + c*x^2])])/(Sqrt[c]*f^2) - (b*ArcTanh[(b + 2*c*x)/(2*Sqrt[c]*Sqrt[a + b*x + c*x^2])])/(2*c^(3/2)*f) - ((2*d*e*f - (e^2 - d*f)*(e - Sqrt[e^2 - 4*d*f]))*ArcTanh[(4*a*f - b*(e - Sqrt[e^2 - 4*d*f]) + 2*(b*f - c*(e - Sqrt[e^2 - 4*d*f]))*x)/(2*Sqrt[4*a*f^2 - 2*b*f*(e - Sqrt[e^2 - 4*d*f]) + c*(e - Sqrt[e^2 - 4*d*f])^2]*Sqrt[a + b*x + c*x^2])])/(f^2*Sqrt[e^2 - 4*d*f]*Sqrt[4*a*f^2 - 2*b*f*(e - Sqrt[e^2 - 4*d*f]) + c*(e - Sqrt[e^2 - 4*d*f])^2]) + ((2*d*e*f - (e^2 - d*f)*(e + Sqrt[e^2 - 4*d*f]))*ArcTanh[(4*a*f - b*(e + Sqrt[e^2 - 4*d*f]) + 2*(b*f - c*(e + Sqrt[e^2 - 4*d*f]))*x)/(2*Sqrt[4*a*f^2 - 2*b*f*(e + Sqrt[e^2 - 4*d*f]) + c*(e + Sqrt[e^2 - 4*d*f])^2]*Sqrt[a + b*x + c*x^2])])/(f^2*Sqrt[e^2 - 4*d*f]*Sqrt[4*a*f^2 - 2*b*f*(e + Sqrt[e^2 - 4*d*f]) + c*(e + Sqrt[e^2 - 4*d*f])^2])}
{x^2/((a + b*x + c*x^2)^(1/2)*(d + e*x + f*x^2)), x, 6, ArcTanh[(b + 2*c*x)/(2*Sqrt[c]*Sqrt[a + b*x + c*x^2])]/(Sqrt[c]*f) - ((e^2 - 2*d*f - e*Sqrt[e^2 - 4*d*f])*ArcTanh[(4*a*f - b*(e - Sqrt[e^2 - 4*d*f]) + 2*(b*f - c*(e - Sqrt[e^2 - 4*d*f]))*x)/(2*Sqrt[4*a*f^2 - 2*b*f*(e - Sqrt[e^2 - 4*d*f]) + c*(e - Sqrt[e^2 - 4*d*f])^2]*Sqrt[a + b*x + c*x^2])])/(f*Sqrt[e^2 - 4*d*f]*Sqrt[4*a*f^2 - 2*b*f*(e - Sqrt[e^2 - 4*d*f]) + c*(e - Sqrt[e^2 - 4*d*f])^2]) - ((2*d*f - e*(e + Sqrt[e^2 - 4*d*f]))*ArcTanh[(4*a*f - b*(e + Sqrt[e^2 - 4*d*f]) + 2*(b*f - c*(e + Sqrt[e^2 - 4*d*f]))*x)/(2*Sqrt[4*a*f^2 - 2*b*f*(e + Sqrt[e^2 - 4*d*f]) + c*(e + Sqrt[e^2 - 4*d*f])^2]*Sqrt[a + b*x + c*x^2])])/(f*Sqrt[e^2 - 4*d*f]*Sqrt[4*a*f^2 - 2*b*f*(e + Sqrt[e^2 - 4*d*f]) + c*(e + Sqrt[e^2 - 4*d*f])^2])}
{x^1/((a + b*x + c*x^2)^(1/2)*(d + e*x + f*x^2)), x, 3, ((e - Sqrt[e^2 - 4*d*f])*ArcTanh[(4*a*f - b*(e - Sqrt[e^2 - 4*d*f]) + 2*(b*f - c*(e - Sqrt[e^2 - 4*d*f]))*x)/(2*Sqrt[4*a*f^2 - 2*b*f*(e - Sqrt[e^2 - 4*d*f]) + c*(e - Sqrt[e^2 - 4*d*f])^2]*Sqrt[a + b*x + c*x^2])])/(Sqrt[e^2 - 4*d*f]*Sqrt[4*a*f^2 - 2*b*f*(e - Sqrt[e^2 - 4*d*f]) + c*(e - Sqrt[e^2 - 4*d*f])^2]) - ((e + Sqrt[e^2 - 4*d*f])*ArcTanh[(4*a*f - b*(e + Sqrt[e^2 - 4*d*f]) + 2*(b*f - c*(e + Sqrt[e^2 - 4*d*f]))*x)/(2*Sqrt[4*a*f^2 - 2*b*f*(e + Sqrt[e^2 - 4*d*f]) + c*(e + Sqrt[e^2 - 4*d*f])^2]*Sqrt[a + b*x + c*x^2])])/(Sqrt[e^2 - 4*d*f]*Sqrt[4*a*f^2 - 2*b*f*(e + Sqrt[e^2 - 4*d*f]) + c*(e + Sqrt[e^2 - 4*d*f])^2])}
{x^0/((a + b*x + c*x^2)^(1/2)*(d + e*x + f*x^2)), x, 3, -((2*f*ArcTanh[(4*a*f - b*(e - Sqrt[e^2 - 4*d*f]) + 2*(b*f - c*(e - Sqrt[e^2 - 4*d*f]))*x)/(2*Sqrt[4*a*f^2 - 2*b*f*(e - Sqrt[e^2 - 4*d*f]) + c*(e - Sqrt[e^2 - 4*d*f])^2]*Sqrt[a + b*x + c*x^2])])/(Sqrt[e^2 - 4*d*f]*Sqrt[4*a*f^2 - 2*b*f*(e - Sqrt[e^2 - 4*d*f]) + c*(e - Sqrt[e^2 - 4*d*f])^2])) + (2*f*ArcTanh[(4*a*f - b*(e + Sqrt[e^2 - 4*d*f]) + 2*(b*f - c*(e + Sqrt[e^2 - 4*d*f]))*x)/(2*Sqrt[4*a*f^2 - 2*b*f*(e + Sqrt[e^2 - 4*d*f]) + c*(e + Sqrt[e^2 - 4*d*f])^2]*Sqrt[a + b*x + c*x^2])])/(Sqrt[e^2 - 4*d*f]*Sqrt[4*a*f^2 - 2*b*f*(e + Sqrt[e^2 - 4*d*f]) + c*(e + Sqrt[e^2 - 4*d*f])^2])}
{1/(x^1*(a + b*x + c*x^2)^(1/2)*(d + e*x + f*x^2)), x, 6, -(ArcTanh[(2*a + b*x)/(2*Sqrt[a]*Sqrt[a + b*x + c*x^2])]/(Sqrt[a]*d)) + (f*(e + Sqrt[e^2 - 4*d*f])*ArcTanh[(4*a*f - b*(e - Sqrt[e^2 - 4*d*f]) + 2*(b*f - c*(e - Sqrt[e^2 - 4*d*f]))*x)/(2*Sqrt[4*a*f^2 - 2*b*f*(e - Sqrt[e^2 - 4*d*f]) + c*(e - Sqrt[e^2 - 4*d*f])^2]*Sqrt[a + b*x + c*x^2])])/(d*Sqrt[e^2 - 4*d*f]*Sqrt[4*a*f^2 - 2*b*f*(e - Sqrt[e^2 - 4*d*f]) + c*(e - Sqrt[e^2 - 4*d*f])^2]) - (f*(e - Sqrt[e^2 - 4*d*f])*ArcTanh[(4*a*f - b*(e + Sqrt[e^2 - 4*d*f]) + 2*(b*f - c*(e + Sqrt[e^2 - 4*d*f]))*x)/(2*Sqrt[4*a*f^2 - 2*b*f*(e + Sqrt[e^2 - 4*d*f]) + c*(e + Sqrt[e^2 - 4*d*f])^2]*Sqrt[a + b*x + c*x^2])])/(d*Sqrt[e^2 - 4*d*f]*Sqrt[4*a*f^2 - 2*b*f*(e + Sqrt[e^2 - 4*d*f]) + c*(e + Sqrt[e^2 - 4*d*f])^2])}
{1/(x^2*(a + b*x + c*x^2)^(1/2)*(d + e*x + f*x^2)), x, 8, -(Sqrt[a + b*x + c*x^2]/(a*d*x)) + (b*ArcTanh[(2*a + b*x)/(2*Sqrt[a]*Sqrt[a + b*x + c*x^2])])/(2*a^(3/2)*d) + (e*ArcTanh[(2*a + b*x)/(2*Sqrt[a]*Sqrt[a + b*x + c*x^2])])/(Sqrt[a]*d^2) - (f*(e^2 - 2*d*f + e*Sqrt[e^2 - 4*d*f])*ArcTanh[(4*a*f - b*(e - Sqrt[e^2 - 4*d*f]) + 2*(b*f - c*(e - Sqrt[e^2 - 4*d*f]))*x)/(2*Sqrt[4*a*f^2 - 2*b*f*(e - Sqrt[e^2 - 4*d*f]) + c*(e - Sqrt[e^2 - 4*d*f])^2]*Sqrt[a + b*x + c*x^2])])/(d^2*Sqrt[e^2 - 4*d*f]*Sqrt[4*a*f^2 - 2*b*f*(e - Sqrt[e^2 - 4*d*f]) + c*(e - Sqrt[e^2 - 4*d*f])^2]) + (f*(e^2 - 2*d*f - e*Sqrt[e^2 - 4*d*f])*ArcTanh[(4*a*f - b*(e + Sqrt[e^2 - 4*d*f]) + 2*(b*f - c*(e + Sqrt[e^2 - 4*d*f]))*x)/(2*Sqrt[4*a*f^2 - 2*b*f*(e + Sqrt[e^2 - 4*d*f]) + c*(e + Sqrt[e^2 - 4*d*f])^2]*Sqrt[a + b*x + c*x^2])])/(d^2*Sqrt[e^2 - 4*d*f]*Sqrt[4*a*f^2 - 2*b*f*(e + Sqrt[e^2 - 4*d*f]) + c*(e + Sqrt[e^2 - 4*d*f])^2])}
{1/(x^3*(a + b*x + c*x^2)^(1/2)*(d + e*x + f*x^2)), x, 12, -(Sqrt[a + b*x + c*x^2]/(2*a*d*x^2)) + (3*b*Sqrt[a + b*x + c*x^2])/(4*a^2*d*x) + (e*Sqrt[a + b*x + c*x^2])/(a*d^2*x) - ((3*b^2 - 4*a*c)*ArcTanh[(2*a + b*x)/(2*Sqrt[a]*Sqrt[a + b*x + c*x^2])])/(8*a^(5/2)*d) - (b*e*ArcTanh[(2*a + b*x)/(2*Sqrt[a]*Sqrt[a + b*x + c*x^2])])/(2*a^(3/2)*d^2) - ((e^2 - d*f)*ArcTanh[(2*a + b*x)/(2*Sqrt[a]*Sqrt[a + b*x + c*x^2])])/(Sqrt[a]*d^3) + (f*(2*e^3 - 4*d*e*f - (e^2 - d*f)*(e - Sqrt[e^2 - 4*d*f]))*ArcTanh[(4*a*f - b*(e - Sqrt[e^2 - 4*d*f]) + 2*(b*f - c*(e - Sqrt[e^2 - 4*d*f]))*x)/(2*Sqrt[4*a*f^2 - 2*b*f*(e - Sqrt[e^2 - 4*d*f]) + c*(e - Sqrt[e^2 - 4*d*f])^2]*Sqrt[a + b*x + c*x^2])])/(d^3*Sqrt[e^2 - 4*d*f]*Sqrt[4*a*f^2 - 2*b*f*(e - Sqrt[e^2 - 4*d*f]) + c*(e - Sqrt[e^2 - 4*d*f])^2]) - (f*(2*e^3 - 4*d*e*f - (e^2 - d*f)*(e + Sqrt[e^2 - 4*d*f]))*ArcTanh[(4*a*f - b*(e + Sqrt[e^2 - 4*d*f]) + 2*(b*f - c*(e + Sqrt[e^2 - 4*d*f]))*x)/(2*Sqrt[4*a*f^2 - 2*b*f*(e + Sqrt[e^2 - 4*d*f]) + c*(e + Sqrt[e^2 - 4*d*f])^2]*Sqrt[a + b*x + c*x^2])])/(d^3*Sqrt[e^2 - 4*d*f]*Sqrt[4*a*f^2 - 2*b*f*(e + Sqrt[e^2 - 4*d*f]) + c*(e + Sqrt[e^2 - 4*d*f])^2])}


{x^3/((a + b*x + c*x^2)^(3/2)*(d + e*x + f*x^2)), x, 9, (2*(2*a + b*x))/((b^2 - 4*a*c)*f*Sqrt[a + b*x + c*x^2]) + (2*e*(b + 2*c*x))/((b^2 - 4*a*c)*f^2*Sqrt[a + b*x + c*x^2]) - (2*(b^3*d*e*f + b*c*e*(c*d^2 + a*(e^2 - 4*d*f)) + 2*a*c*f*(c*d^2 + a*(e^2 - d*f)) - b^2*(c*d*e^2 + a*f*(e^2 - d*f)) + c*(2*c^2*d^2*e + b*f*(b*d*e - a*e^2 + a*d*f) + c*(2*a*e*(e^2 - 2*d*f) - b*d*(2*e^2 - d*f)))*x))/((b^2 - 4*a*c)*f^2*(c^2*d^2 + f*(b^2*d - a*b*e + a^2*f) - c*(b*d*e - a*(e^2 - 2*d*f)))*Sqrt[a + b*x + c*x^2]) + ((2*d*(b*d - a*e)*f + (e - Sqrt[e^2 - 4*d*f])*(c*d^2 - b*d*e + a*(e^2 - d*f)))*ArcTanh[(4*a*f - b*(e - Sqrt[e^2 - 4*d*f]) + 2*(b*f - c*(e - Sqrt[e^2 - 4*d*f]))*x)/(2*Sqrt[4*a*f^2 - 2*b*f*(e - Sqrt[e^2 - 4*d*f]) + c*(e - Sqrt[e^2 - 4*d*f])^2]*Sqrt[a + b*x + c*x^2])])/(Sqrt[e^2 - 4*d*f]*Sqrt[4*a*f^2 - 2*b*f*(e - Sqrt[e^2 - 4*d*f]) + c*(e - Sqrt[e^2 - 4*d*f])^2]*(c^2*d^2 + f*(b^2*d - a*b*e + a^2*f) - c*(b*d*e - a*(e^2 - 2*d*f)))) - ((2*d*(b*d - a*e)*f + (e + Sqrt[e^2 - 4*d*f])*(c*d^2 - b*d*e + a*(e^2 - d*f)))*ArcTanh[(4*a*f - b*(e + Sqrt[e^2 - 4*d*f]) + 2*(b*f - c*(e + Sqrt[e^2 - 4*d*f]))*x)/(2*Sqrt[4*a*f^2 - 2*b*f*(e + Sqrt[e^2 - 4*d*f]) + c*(e + Sqrt[e^2 - 4*d*f])^2]*Sqrt[a + b*x + c*x^2])])/(Sqrt[e^2 - 4*d*f]*Sqrt[4*a*f^2 - 2*b*f*(e + Sqrt[e^2 - 4*d*f]) + c*(e + Sqrt[e^2 - 4*d*f])^2]*(c^2*d^2 + f*(b^2*d - a*b*e + a^2*f) - c*(b*d*e - a*(e^2 - 2*d*f))))}
{x^2/((a + b*x + c*x^2)^(3/2)*(d + e*x + f*x^2)), x, 8, -((2*(b + 2*c*x))/((b^2 - 4*a*c)*f*Sqrt[a + b*x + c*x^2])) + (2*(b^3*d*f + 2*a^2*c*e*f - b^2*e*(c*d + a*f) + b*c*(c*d^2 + a*(e^2 - 3*d*f)) + c*(2*c^2*d^2 + b*(b*d - a*e)*f - 2*c*(b*d*e - a*e^2 + a*d*f))*x))/((b^2 - 4*a*c)*f*(c^2*d^2 + f*(b^2*d - a*b*e + a^2*f) - c*(b*d*e - a*(e^2 - 2*d*f)))*Sqrt[a + b*x + c*x^2]) - (f*(2*d*(c*d - a*f) - (b*d - a*e)*(e - Sqrt[e^2 - 4*d*f]))*ArcTanh[(4*a*f - b*(e - Sqrt[e^2 - 4*d*f]) + 2*(b*f - c*(e - Sqrt[e^2 - 4*d*f]))*x)/(2*Sqrt[4*a*f^2 - 2*b*f*(e - Sqrt[e^2 - 4*d*f]) + c*(e - Sqrt[e^2 - 4*d*f])^2]*Sqrt[a + b*x + c*x^2])])/(Sqrt[e^2 - 4*d*f]*Sqrt[4*a*f^2 - 2*b*f*(e - Sqrt[e^2 - 4*d*f]) + c*(e - Sqrt[e^2 - 4*d*f])^2]*(c^2*d^2 + f*(b^2*d - a*b*e + a^2*f) - c*(b*d*e - a*(e^2 - 2*d*f)))) + (f*(2*d*(c*d - a*f) - (b*d - a*e)*(e + Sqrt[e^2 - 4*d*f]))*ArcTanh[(4*a*f - b*(e + Sqrt[e^2 - 4*d*f]) + 2*(b*f - c*(e + Sqrt[e^2 - 4*d*f]))*x)/(2*Sqrt[4*a*f^2 - 2*b*f*(e + Sqrt[e^2 - 4*d*f]) + c*(e + Sqrt[e^2 - 4*d*f])^2]*Sqrt[a + b*x + c*x^2])])/(Sqrt[e^2 - 4*d*f]*Sqrt[4*a*f^2 - 2*b*f*(e + Sqrt[e^2 - 4*d*f]) + c*(e + Sqrt[e^2 - 4*d*f])^2]*(c^2*d^2 + f*(b^2*d - a*b*e + a^2*f) - c*(b*d*e - a*(e^2 - 2*d*f))))}
{x^1/((a + b*x + c*x^2)^(3/2)*(d + e*x + f*x^2)), x, 5, (2*(a*(2*c^2*d + b^2*f - c*(b*e + 2*a*f)) + c*(b*c*d - 2*a*c*e + a*b*f)*x))/((b^2 - 4*a*c)*(c^2*d^2 + f*(b^2*d - a*b*e + a^2*f) - c*(b*d*e - a*(e^2 - 2*d*f)))*Sqrt[a + b*x + c*x^2]) + (f*(2*d*(c*e - b*f) - (c*d - a*f)*(e - Sqrt[e^2 - 4*d*f]))*ArcTanh[(4*a*f - b*(e - Sqrt[e^2 - 4*d*f]) + 2*(b*f - c*(e - Sqrt[e^2 - 4*d*f]))*x)/(2*Sqrt[4*a*f^2 - 2*b*f*(e - Sqrt[e^2 - 4*d*f]) + c*(e - Sqrt[e^2 - 4*d*f])^2]*Sqrt[a + b*x + c*x^2])])/(Sqrt[e^2 - 4*d*f]*Sqrt[4*a*f^2 - 2*b*f*(e - Sqrt[e^2 - 4*d*f]) + c*(e - Sqrt[e^2 - 4*d*f])^2]*(c^2*d^2 + f*(b^2*d - a*b*e + a^2*f) - c*(b*d*e - a*(e^2 - 2*d*f)))) - (f*(2*d*(c*e - b*f) - (c*d - a*f)*(e + Sqrt[e^2 - 4*d*f]))*ArcTanh[(4*a*f - b*(e + Sqrt[e^2 - 4*d*f]) + 2*(b*f - c*(e + Sqrt[e^2 - 4*d*f]))*x)/(2*Sqrt[4*a*f^2 - 2*b*f*(e + Sqrt[e^2 - 4*d*f]) + c*(e + Sqrt[e^2 - 4*d*f])^2]*Sqrt[a + b*x + c*x^2])])/(Sqrt[e^2 - 4*d*f]*Sqrt[4*a*f^2 - 2*b*f*(e + Sqrt[e^2 - 4*d*f]) + c*(e + Sqrt[e^2 - 4*d*f])^2]*(c^2*d^2 + f*(b^2*d - a*b*e + a^2*f) - c*(b*d*e - a*(e^2 - 2*d*f))))}
{x^0/((a + b*x + c*x^2)^(3/2)*(d + e*x + f*x^2)), x, 5, (2*(b^2*c*e - 2*a*c^2*e - b^3*f - b*c*(c*d - 3*a*f) - c*(2*c^2*d - b*c*e + b^2*f - 2*a*c*f)*x))/((b^2 - 4*a*c)*(c^2*d^2 + f*(b^2*d - a*b*e + a^2*f) - c*(b*d*e - a*(e^2 - 2*d*f)))*Sqrt[a + b*x + c*x^2]) - (f*(c*(e^2 - 2*d*f + e*Sqrt[e^2 - 4*d*f]) + f*(2*a*f - b*(e + Sqrt[e^2 - 4*d*f])))*ArcTanh[(4*a*f - b*(e - Sqrt[e^2 - 4*d*f]) + 2*(b*f - c*(e - Sqrt[e^2 - 4*d*f]))*x)/(2*Sqrt[4*a*f^2 - 2*b*f*(e - Sqrt[e^2 - 4*d*f]) + c*(e - Sqrt[e^2 - 4*d*f])^2]*Sqrt[a + b*x + c*x^2])])/(Sqrt[e^2 - 4*d*f]*Sqrt[4*a*f^2 - 2*b*f*(e - Sqrt[e^2 - 4*d*f]) + c*(e - Sqrt[e^2 - 4*d*f])^2]*(c^2*d^2 + f*(b^2*d - a*b*e + a^2*f) - c*(b*d*e - a*(e^2 - 2*d*f)))) - (f*((c*e - b*f)*(e + Sqrt[e^2 - 4*d*f]) + 2*(f*(b*e - a*f) - c*(e^2 - d*f)))*ArcTanh[(4*a*f - b*(e + Sqrt[e^2 - 4*d*f]) + 2*(b*f - c*(e + Sqrt[e^2 - 4*d*f]))*x)/(2*Sqrt[4*a*f^2 - 2*b*f*(e + Sqrt[e^2 - 4*d*f]) + c*(e + Sqrt[e^2 - 4*d*f])^2]*Sqrt[a + b*x + c*x^2])])/(Sqrt[e^2 - 4*d*f]*Sqrt[4*a*f^2 - 2*b*f*(e + Sqrt[e^2 - 4*d*f]) + c*(e + Sqrt[e^2 - 4*d*f])^2]*(c^2*d^2 + f*(b^2*d - a*b*e + a^2*f) - c*(b*d*e - a*(e^2 - 2*d*f))))}
{1/(x^1*(a + b*x + c*x^2)^(3/2)*(d + e*x + f*x^2)), x, 9, (2*(b^2 - 2*a*c + b*c*x))/(a*(b^2 - 4*a*c)*d*Sqrt[a + b*x + c*x^2]) + (2*(b*(c^2*d*e - b*c*e^2 + b*f*(b*e - a*f)) - 2*a*c*(f*(b*e - a*f) - c*(e^2 - d*f)) + c*(2*c^2*d*e + b*f*(b*e - a*f) - b*c*(e^2 + d*f))*x))/((b^2 - 4*a*c)*d*(c^2*d^2 + f*(b^2*d - a*b*e + a^2*f) - c*(b*d*e - a*(e^2 - 2*d*f)))*Sqrt[a + b*x + c*x^2]) - ArcTanh[(2*a + b*x)/(2*Sqrt[a]*Sqrt[a + b*x + c*x^2])]/(a^(3/2)*d) + (f*((e - Sqrt[e^2 - 4*d*f])*(f*(b*e - a*f) - c*(e^2 - d*f)) - 2*(f*(b*e^2 - b*d*f - a*e*f) - c*(e^3 - 2*d*e*f)))*ArcTanh[(4*a*f - b*(e - Sqrt[e^2 - 4*d*f]) + 2*(b*f - c*(e - Sqrt[e^2 - 4*d*f]))*x)/(2*Sqrt[4*a*f^2 - 2*b*f*(e - Sqrt[e^2 - 4*d*f]) + c*(e - Sqrt[e^2 - 4*d*f])^2]*Sqrt[a + b*x + c*x^2])])/(d*Sqrt[e^2 - 4*d*f]*Sqrt[4*a*f^2 - 2*b*f*(e - Sqrt[e^2 - 4*d*f]) + c*(e - Sqrt[e^2 - 4*d*f])^2]*(c^2*d^2 + f*(b^2*d - a*b*e + a^2*f) - c*(b*d*e - a*(e^2 - 2*d*f)))) - (f*((e + Sqrt[e^2 - 4*d*f])*(f*(b*e - a*f) - c*(e^2 - d*f)) - 2*(f*(b*e^2 - b*d*f - a*e*f) - c*(e^3 - 2*d*e*f)))*ArcTanh[(4*a*f - b*(e + Sqrt[e^2 - 4*d*f]) + 2*(b*f - c*(e + Sqrt[e^2 - 4*d*f]))*x)/(2*Sqrt[4*a*f^2 - 2*b*f*(e + Sqrt[e^2 - 4*d*f]) + c*(e + Sqrt[e^2 - 4*d*f])^2]*Sqrt[a + b*x + c*x^2])])/(d*Sqrt[e^2 - 4*d*f]*Sqrt[4*a*f^2 - 2*b*f*(e + Sqrt[e^2 - 4*d*f]) + c*(e + Sqrt[e^2 - 4*d*f])^2]*(c^2*d^2 + f*(b^2*d - a*b*e + a^2*f) - c*(b*d*e - a*(e^2 - 2*d*f))))}
{1/(x^2*(a + b*x + c*x^2)^(3/2)*(d + e*x + f*x^2)), x, 13, -((2*e*(b^2 - 2*a*c + b*c*x))/(a*(b^2 - 4*a*c)*d^2*Sqrt[a + b*x + c*x^2])) + (2*(b^2 - 2*a*c + b*c*x))/(a*(b^2 - 4*a*c)*d*x*Sqrt[a + b*x + c*x^2]) + (2*(2*a*c*(f*(b*e^2 - b*d*f - a*e*f) - c*(e^3 - 2*d*e*f)) - b*(a*e*f*(c*e - b*f) + (e^2 - d*f)*(c^2*d + b^2*f - c*(b*e + a*f))) + c*(b*c*e^3 - 2*a*c*d*f^2 - 2*c^2*d*(e^2 - d*f) - b*f*(b*e^2 - b*d*f - a*e*f))*x))/((b^2 - 4*a*c)*d^2*(c^2*d^2 + f*(b^2*d - a*b*e + a^2*f) - c*(b*d*e - a*(e^2 - 2*d*f)))*Sqrt[a + b*x + c*x^2]) - ((3*b^2 - 8*a*c)*Sqrt[a + b*x + c*x^2])/(a^2*(b^2 - 4*a*c)*d*x) + (3*b*ArcTanh[(2*a + b*x)/(2*Sqrt[a]*Sqrt[a + b*x + c*x^2])])/(2*a^(5/2)*d) + (e*ArcTanh[(2*a + b*x)/(2*Sqrt[a]*Sqrt[a + b*x + c*x^2])])/(a^(3/2)*d^2) - (f*((e - Sqrt[e^2 - 4*d*f])*(f*(b*e^2 - b*d*f - a*e*f) - c*(e^3 - 2*d*e*f)) - 2*(d*e*f*(c*e - b*f) + (e^2 - d*f)*(f*(b*e - a*f) - c*(e^2 - d*f))))*ArcTanh[(4*a*f - b*(e - Sqrt[e^2 - 4*d*f]) + 2*(b*f - c*(e - Sqrt[e^2 - 4*d*f]))*x)/(2*Sqrt[4*a*f^2 - 2*b*f*(e - Sqrt[e^2 - 4*d*f]) + c*(e - Sqrt[e^2 - 4*d*f])^2]*Sqrt[a + b*x + c*x^2])])/(d^2*Sqrt[e^2 - 4*d*f]*Sqrt[4*a*f^2 - 2*b*f*(e - Sqrt[e^2 - 4*d*f]) + c*(e - Sqrt[e^2 - 4*d*f])^2]*(c^2*d^2 + f*(b^2*d - a*b*e + a^2*f) - c*(b*d*e - a*(e^2 - 2*d*f)))) + (f*((e + Sqrt[e^2 - 4*d*f])*(f*(b*e^2 - b*d*f - a*e*f) - c*(e^3 - 2*d*e*f)) - 2*(d*e*f*(c*e - b*f) + (e^2 - d*f)*(f*(b*e - a*f) - c*(e^2 - d*f))))*ArcTanh[(4*a*f - b*(e + Sqrt[e^2 - 4*d*f]) + 2*(b*f - c*(e + Sqrt[e^2 - 4*d*f]))*x)/(2*Sqrt[4*a*f^2 - 2*b*f*(e + Sqrt[e^2 - 4*d*f]) + c*(e + Sqrt[e^2 - 4*d*f])^2]*Sqrt[a + b*x + c*x^2])])/(d^2*Sqrt[e^2 - 4*d*f]*Sqrt[4*a*f^2 - 2*b*f*(e + Sqrt[e^2 - 4*d*f]) + c*(e + Sqrt[e^2 - 4*d*f])^2]*(c^2*d^2 + f*(b^2*d - a*b*e + a^2*f) - c*(b*d*e - a*(e^2 - 2*d*f))))}


(* ::Section::Closed:: *)
(*Integrands requiring collection of products of fractional powers*)


{Sqrt[-1 + x^2]/Sqrt[-1 + x^4], x, 2, (Sqrt[-1 + x^2]*Sqrt[1 + x^2]*ArcSinh[x])/Sqrt[-1 + x^4]}
{Sqrt[1 + x^2]/Sqrt[-1 + x^4], x, 2, -((Sqrt[-1 + x^4]*ArcSin[x])/Sqrt[1 - x^4]), -((Sqrt[-1 + x^4]*ArcSin[x])/(Sqrt[1 - x^2]*Sqrt[1 + x^2]))}
{(-Sqrt[-1 + x^2] + Sqrt[1 + x^2])/Sqrt[-1 + x^4], x, 7, -((Sqrt[-1 + x^4]*ArcSin[x])/(Sqrt[1 - x^2]*Sqrt[1 + x^2])) + (Sqrt[-1 + x^2]*Sqrt[-1 + x^4]*ArcSinh[x])/((1 - x^2)*Sqrt[1 + x^2])}


(* ::Section::Closed:: *)
(*Integrands requiring simplification*)


(* Following pairs or triples of integrands are equal. *)
{x/(1 - x^2)^5, x, 1, 1/(8*(1 - x^2)^4)}
{-(1/(32*(-1 + x)^5)) + 3/(64*(-1 + x)^4) - 5/(128*(-1 + x)^3) + 5/(256*(-1 + x)^2) - 1/(32*(1 + x)^5) - 3/(64*(1 + x)^4) - 5/(128*(1 + x)^3) - 5/(256*(1 + x)^2), x, 0, 1/(8*(1 - x^2)^4)}

{(2 + x)/(-1 + 2*x + x^2), x, 3, (1/4)*(2 + Sqrt[2])*Log[1 - Sqrt[2] + x] - ((1 - Sqrt[2])*Log[1 + Sqrt[2] + x])/(2*Sqrt[2])}
{(-4 + x^2)/(2 - 5*x + x^3), x, 4, (1/4)*(2 + Sqrt[2])*Log[1 - Sqrt[2] + x] - ((1 - Sqrt[2])*Log[1 + Sqrt[2] + x])/(2*Sqrt[2])}

{(1 + 2*x^8)/(x*(1 + x^8)^(3/2)), x, 3, -(1/(4*Sqrt[1 + x^8])) - (1/4)*ArcTanh[Sqrt[1 + x^8]]}
{(Sqrt[1 + x^8]*(1 + 2*x^8))/(x + 2*x^9 + x^17), x, 4, -(1/(4*Sqrt[1 + x^8])) - (1/4)*ArcTanh[Sqrt[1 + x^8]]}

{1 - 9*x^2 + x/Sqrt[1 - 9*x^2], x, 2, x - 3*x^3 - (1/9)*Sqrt[1 - 9*x^2]}
{(x + (1 - 9*x^2)^(3/2))/Sqrt[1 - 9*x^2], x, 3, x - 3*x^3 - (1/9)*Sqrt[1 - 9*x^2]}

{(-3 + 2*x)*(-3*x + x^2)^(2/3), x, 1, (3/5)*(-3*x + x^2)^(5/3)}
{(-3 + 2*x)*(x*(-3 + x))^(2/3), x, 2, (3/5)*(-3*x + x^2)^(5/3)}
{(x*(9 - 9*x + 2*x^2))/(x*(-3 + x))^(1/3), x, 3, (3*(3 - x)^2*x^2)/(5*(-((3 - x)*x))^(1/3))}

{((-3 + 2*Sqrt[x])*(-3*Sqrt[x] + x)^(2/3))/Sqrt[x], x, 1, (6/5)*(-3*Sqrt[x] + x)^(5/3)}
{(9 - 9*Sqrt[x] + 2*x)/(-3*Sqrt[x] + x)^(1/3), x, 3, (6/5)*(-3*Sqrt[x] + x)^(5/3)}

{2/(-1 + 4*x^2), x, 2, -ArcTanh[2*x]}
{1/(-1 + 2*x) - 1/(1 + 2*x), x, 1, (1/2)*Log[1 - 2*x] - (1/2)*Log[1 + 2*x]}

{1/Sqrt[4 - 9*x^2], x, 1, (1/3)*ArcSin[(3*x)/2]}
{1/(Sqrt[2 - 3*x]*Sqrt[2 + 3*x]), x, 1, (1/3)*ArcSin[(3*x)/2]}
{1/Sqrt[(-(-2 + 3*x))*(2 + 3*x)], x, 2, (1/3)*ArcSin[(3*x)/2]}

{1/(Sqrt[3 - x]*Sqrt[5 + x]), x, 1, -ArcSin[(1/4)*(-1 - x)]}
{1/Sqrt[(-(-3 + x))*(5 + x)], x, 2, -ArcSin[(1/4)*(-1 - x)]}
{1/Sqrt[15 - 2*x - x^2], x, 1, -ArcSin[(1/4)*(-1 - x)]}

{1/(Sqrt[-3 - x]*Sqrt[5 + x]), x, 1, ArcSin[4 + x]}
{1/Sqrt[(-(3 + x))*(5 + x)], x, 2, ArcSin[4 + x]}
{1/Sqrt[-15 - 8*x - x^2], x, 1, ArcSin[4 + x]}

{1 - Sqrt[x], x, 1, x - (2*x^(3/2))/3}
{(1 - x)/(1 + Sqrt[x]), x, 2, x - (2*x^(3/2))/3}

{Sqrt[1/(1 - x^2)], x, 2, Sqrt[1/(1 - x^2)]*Sqrt[1 - x^2]*ArcSin[x]}
{Sqrt[(1 + x^2)/(1 - x^4)], x, 3, Sqrt[1/(1 - x^2)]*Sqrt[1 - x^2]*ArcSin[x]}

{Sqrt[1/(-1 + x^2)], x, 2, Sqrt[1/(-1 + x^2)]*Sqrt[-1 + x^2]*ArcTanh[x/Sqrt[-1 + x^2]]}
{Sqrt[(1 + x^2)/(-1 + x^4)], x, 3, Sqrt[1/(-1 + x^2)]*Sqrt[-1 + x^2]*ArcTanh[x/Sqrt[-1 + x^2]]}

{(1 + x^6)/(-1 + x^6), x, 8, x + ArcTan[(1 - 2*x)/Sqrt[3]]/Sqrt[3] - ArcTan[(1 + 2*x)/Sqrt[3]]/Sqrt[3] - (2*ArcTanh[x])/3 - (1/3)*ArcTanh[x/(1 + x^2)]}
{(1/x^3 + x^3)/(-(1/x^3) + x^3), x, 9, x + ArcTan[(1 - 2*x)/Sqrt[3]]/Sqrt[3] - ArcTan[(1 + 2*x)/Sqrt[3]]/Sqrt[3] - (2*ArcTanh[x])/3 - (1/3)*ArcTanh[x/(1 + x^2)]}


(* Following pairs of integrands are equal. *)
{1/Sqrt[1 - x], x, 1, -2*Sqrt[1 - x]}
{Sqrt[1 + x]/Sqrt[1 - x^2], x, 2, -2*Sqrt[1 - x]}

{1/Sqrt[1 + x], x, 1, 2*Sqrt[1 + x]}
{Sqrt[1 - x]/Sqrt[1 - x^2], x, 2, 2*Sqrt[1 + x]}

{Sqrt[1 - x], x, 1, (-(2/3))*(1 - x)^(3/2)}
{Sqrt[1 - x^2]/Sqrt[1 + x], x, 2, (-(2/3))*(1 - x)^(3/2)}

{Sqrt[1 + x], x, 1, (2/3)*(1 + x)^(3/2)}
{Sqrt[1 - x^2]/Sqrt[1 - x], x, 2, (2/3)*(1 + x)^(3/2)}

{Sqrt[2 + 3*x]/Sqrt[1 + x], x, 2, Sqrt[1 + x]*Sqrt[2 + 3*x] - ArcSinh[Sqrt[2 + 3*x]]/Sqrt[3]}
{(Sqrt[2 + 3*x]*Sqrt[1 - x])/Sqrt[1 - x^2], x, 3, Sqrt[1 + x]*Sqrt[2 + 3*x] - ArcSinh[Sqrt[2 + 3*x]]/Sqrt[3]}

{(1 + x)^(3/2)/(x*(1 - x)^(3/2)), x, 6, 2*Sqrt[1 - x]*Sqrt[1 + x] + (2*(1 + x)^(3/2))/Sqrt[1 - x] - ArcSin[x] - 2*ArcTanh[Sqrt[1 - x]/Sqrt[1 + x]]}
{(1 + x)^3/(x*(1 - x^2)^(3/2)), x, 9, 4/Sqrt[1 - x^2] + (4*x)/Sqrt[1 - x^2] - ArcSin[x] - ArcTanh[Sqrt[1 - x^2]]}

{(1 + a*x)^(3/2)/(x*(1 - a*x)^(3/2)), x, 6, 2*Sqrt[1 - a*x]*Sqrt[1 + a*x] + (2*(1 + a*x)^(3/2))/Sqrt[1 - a*x] - ArcSin[a*x] - 2*ArcTanh[Sqrt[1 - a*x]/Sqrt[1 + a*x]]}
{(1 + a*x)^3/(x*(1 - a^2*x^2)^(3/2)), x, 9, 4/Sqrt[1 - a^2*x^2] + (4*a*x)/Sqrt[1 - a^2*x^2] - ArcSin[a*x] - ArcTanh[Sqrt[1 - a^2*x^2]]}


(* Following pairs of integrands are equal. *)
{1/Sqrt[1 - x^2], x, 1, ArcSin[x]}
{Sqrt[1 + x^2]/Sqrt[1 - x^4], x, 2, ArcSin[x]}

{1/Sqrt[1 + x^2], x, 1, ArcSinh[x]}
{Sqrt[1 - x^2]/Sqrt[1 - x^4], x, 2, ArcSinh[x]}

{Sqrt[1 - x^2], x, 2, (1/2)*x*Sqrt[1 - x^2] + ArcSin[x]/2}
{Sqrt[1 - x^4]/Sqrt[1 + x^2], x, 3, (1/2)*x*Sqrt[1 - x^2] + ArcSin[x]/2}

{Sqrt[1 + x^2], x, 2, (1/2)*x*Sqrt[1 + x^2] + ArcSinh[x]/2}
{Sqrt[1 - x^4]/Sqrt[1 - x^2], x, 3, (1/2)*x*Sqrt[1 + x^2] + ArcSinh[x]/2}


{((a + b + c*x^2)/d)^m, x, 2, (x*((a + b)/d + (c*x^2)/d)^m*Hypergeometric2F1[1/2, -m, 3/2, -((c*x^2)/(a + b))])/((a + b + c*x^2)/(a + b))^m}


(* ::Section::Closed:: *)
(*Integrands requiring rationalization of denominator*)


{1/(x - Sqrt[1 + x^2]), x, 4, -(x^2/2) - (1/2)*x*Sqrt[1 + x^2] - ArcSinh[x]/2}
{1/(x - Sqrt[1 - x^2]), x, 6, -(ArcSin[x]/2) - (1/2)*ArcTanh[x/Sqrt[1 - x^2]] + (1/4)*Log[1 - 2*x^2]}
{1/(x - Sqrt[1 + 2*x^2]), x, 6, -(Sqrt[2]*ArcSinh[Sqrt[2]*x]) + ArcTanh[x/Sqrt[1 + 2*x^2]] - Log[1 + x^2]/2}


(* Integrands are equal.  Denominators needs to be rationalized before expansion. *)
{(2*x - x^3 + x^2*Sqrt[2 - x^2])/(-2 + 2*x^2), x, 8, -(x^2/4) + (1/4)*x*Sqrt[2 - x^2] - (1/2)*ArcTanh[x/Sqrt[2 - x^2]] + (1/4)*Log[1 - x^2]}
{(x*Sqrt[2 - x^2])/(x - Sqrt[2 - x^2]), x, 11, -(x^2/4) + (1/4)*x*Sqrt[2 - x^2] - (1/2)*ArcTanh[x/Sqrt[2 - x^2]] + (1/4)*Log[1 - x] + (1/4)*Log[1 + x]}

{x/(-x + Sqrt[2*x - x^2]), x, 4, -(x/2) - (1/2)*Sqrt[2*x - x^2] + (1/2)*ArcTanh[Sqrt[2*x - x^2]] - (1/2)*Log[1 - x]}
{(x + Sqrt[2*x - x^2])/(2 - 2*x), x, 6, -(x/2) - (1/2)*Sqrt[2*x - x^2] + (1/2)*ArcTanh[Sqrt[2*x - x^2]] - (1/2)*Log[1 - x]}
{(Sqrt[2 - x]*Sqrt[x] + x)/(2 - 2*x), x, 7, -(x/2) - (1/2)*Sqrt[2*x - x^2] + (1/2)*ArcTanh[Sqrt[2*x - x^2]] - (1/2)*Log[1 - x]}
{Sqrt[x]/(Sqrt[2 - x] - Sqrt[x]), x, 0, -(x/2) - (1/2)*Sqrt[2*x - x^2] + (1/2)*ArcTanh[Sqrt[2*x - x^2]] - (1/2)*Log[1 - x]}


(* ::Section::Closed:: *)
(*Integrands requiring algebraic expansion*)


{Sqrt[1 - x]*(Sqrt[1 - x] + Sqrt[1 + x]), x, 4, x - x^2/2 + (1/2)*x*Sqrt[1 - x^2] + ArcSin[x]/2}
{(Sqrt[1 - x] + Sqrt[1 + x])^2, x, 4, 2*x + x*Sqrt[1 - x^2] + ArcSin[x]}
{(Sqrt[1 - x] + Sqrt[1 + x])^2/x, x, 5, 2*Sqrt[1 - x^2] - 2*ArcTanh[Sqrt[1 - x^2]] + 2*Log[x]}

{(-Sqrt[1 - x] - Sqrt[1 + x])*(Sqrt[1 - x] + Sqrt[1 + x]), x, 4, -2*x - x*Sqrt[1 - x^2] - ArcSin[x]}
{(-Sqrt[1 - x] - Sqrt[1 + x])*(Sqrt[1 - x] + Sqrt[1 + x])/x, x, 7, -2*Sqrt[1 - x^2] + 2*ArcTanh[Sqrt[1 - x^2]] - 2*Log[x]}
{(-Sqrt[-1 + x] + Sqrt[1 + x])/(Sqrt[-1 + x] + Sqrt[1 + x]), x, 6, x^2/2 - (1/2)*Sqrt[-1 + x]*x*Sqrt[1 + x] + ArcCosh[x]/2, x^2/2 - (1/2)*Sqrt[-1 + x]*Sqrt[1 + x] - (1/2)*(-1 + x)^(3/2)*Sqrt[1 + x] + ArcCosh[x]/2}
{(Sqrt[1 - x] + Sqrt[1 + x])/(-Sqrt[1 - x] + Sqrt[1 + x]), x, 8, Sqrt[1 - x^2] - ArcTanh[Sqrt[1 - x^2]] + Log[x]}

{(2*Sqrt[3 - x] + 3/Sqrt[1 + x])^2/x, x, 7, -4*x + 12*ArcSin[(1 - x)/2] - 24*Sqrt[3]*ArcTanh[(Sqrt[3]*Sqrt[1 + x])/Sqrt[3 - x]] + 21*Log[x] - 9*Log[1 + x]}


{(-1 + x + x^2)/(1 + Sqrt[1 + x^2]), x, 13, -(1/x) - x + Sqrt[1 + x^2] + Sqrt[1 + x^2]/x + (1/2)*x*Sqrt[1 + x^2] - ArcSinh[x]/2 - Log[1 + Sqrt[1 + x^2]]}
{(-1 + x + x^2)/(1 + x + Sqrt[1 + x^2]), x, 14, (6*x^2 + 2*x^3 + (4 - 3*x - 2*x^2)*Sqrt[1 + x^2] - 3*ArcSinh[x] - 6*Log[1 + Sqrt[1 + x^2]])/12, x^2/2 + x^3/6 + Sqrt[1 + x^2]/2 - (1/4)*x*Sqrt[1 + x^2] - (1/6)*(1 + x^2)^(3/2) - ArcSinh[x]/4 - (1/2)*ArcTanh[Sqrt[1 + x^2]] - Log[x]/2}


{(2*Sqrt[-1 + x] + x)/(Sqrt[-1 + x]*x), x, 2, 2*Sqrt[-1 + x] + 2*Log[x]}
{(-1 + 2*x^2)/(Sqrt[-1 + x]*Sqrt[1 + x]), x, 5, Sqrt[-1 + x]*x*Sqrt[1 + x]}


(* Positive integer powers of monomial sums *)
{(a + b*x^(2/3)+c*Sqrt[x])^2, x, 4, a^2*x + (4/3)*a*c*x^(3/2) + (6/5)*a*b*x^(5/3) + (c^2*x^2)/2 + (12/13)*b*c*x^(13/6) + (3/7)*b^2*x^(7/3)}
{(a + b*x^(2/3)+c*Sqrt[x])^3, x, 4, a^3*x + 2*a^2*c*x^(3/2) + (9/5)*a^2*b*x^(5/3) + (3/2)*a*c^2*x^2 + (36/13)*a*b*c*x^(13/6) + (9/7)*a*b^2*x^(7/3) + (2/5)*c^3*x^(5/2) + (9/8)*b*c^2*x^(8/3) + (18/17)*b^2*c*x^(17/6) + (b^3*x^3)/3}


{(-1 + x^2)/(Sqrt[a - b + b/x^2]*x^3), x, 5, Sqrt[a - b + b/x^2]/b + ArcTanh[Sqrt[a - b + b/x^2]/Sqrt[a - b]]/Sqrt[a - b]}
{(-1 + x^2)/(Sqrt[a + b*(-1 + 1/x^2)]*x^3), x, 6, Sqrt[a - b + b/x^2]/b + ArcTanh[Sqrt[a - b + b/x^2]/Sqrt[a - b]]/Sqrt[a - b]}


{(1 + x)/((4 + x^2)*Sqrt[9 + x^2]), x, 4, ArcTan[(Sqrt[5]*x)/(2*Sqrt[9 + x^2])]/(2*Sqrt[5]) - ArcTanh[Sqrt[9 + x^2]/Sqrt[5]]/Sqrt[5]}


(* Checks to ensure that expansion occurs before substitution for fractional powers of linears: *) 
{x*(1 + Sqrt[1 - x^2]), x, 3, x^2/2 - (1/3)*(1 - x^2)^(3/2)}
{x*(1 + Sqrt[1 - x]*Sqrt[1 + x]), x, 4, x^2/2 - (1/3)*(1 - x^2)^(3/2)}

{x*(1 + 1/(Sqrt[2 + x]*Sqrt[3 + x])), x, 4, x^2/2 + Sqrt[2 + x]*Sqrt[3 + x] - 5*ArcSinh[Sqrt[2 + x]]}


{(x - Sqrt[x^6])/(x*(1 - x^4)), x, 9, ArcTan[x]/2 + (Sqrt[x^6]*ArcTan[x])/(2*x^3) + ArcTanh[x]/2 - (Sqrt[x^6]*ArcTanh[x])/(2*x^3)}
{(1 - Sqrt[x^6]/x)/(1 - x^4), x, 9, ArcTan[x]/2 + (Sqrt[x^6]*ArcTan[x])/(2*x^3) + ArcTanh[x]/2 - (Sqrt[x^6]*ArcTanh[x])/(2*x^3)}
{(x - Sqrt[x^6])/(x - x^5), x, 10, ArcTan[x]/2 + (Sqrt[x^6]*ArcTan[x])/(2*x^3) + ArcTanh[x]/2 - (Sqrt[x^6]*ArcTanh[x])/(2*x^3)}
{x/(x + Sqrt[x^6]), x, 11, ArcTan[x]/2 + (Sqrt[x^6]*ArcTan[x])/(2*x^3) + ArcTanh[x]/2 - (Sqrt[x^6]*ArcTanh[x])/(2*x^3)}

{(Sqrt[x] - Sqrt[x^3])/(x - x^3), x, 12, ArcTan[Sqrt[x]] + (Sqrt[x^3]*ArcTan[Sqrt[x]])/x^(3/2) + ArcTanh[Sqrt[x]] - (Sqrt[x^3]*ArcTanh[Sqrt[x]])/x^(3/2)}
{1/(Sqrt[x] + Sqrt[x^3]), x, 13, ArcTan[Sqrt[x]] + (Sqrt[x^3]*ArcTan[Sqrt[x]])/x^(3/2) + ArcTanh[Sqrt[x]] - (Sqrt[x^3]*ArcTanh[Sqrt[x]])/x^(3/2)}
{1/(Sqrt[-1 + x] + Sqrt[(-1 + x)^3]), x, 14, ArcTan[Sqrt[-1 + x]] + (Sqrt[(-1 + x)^3]*ArcTan[Sqrt[-1 + x]])/(-1 + x)^(3/2) + ArcTanh[Sqrt[-1 + x]] - (Sqrt[(-1 + x)^3]*ArcTanh[Sqrt[-1 + x]])/(-1 + x)^(3/2)}


(* Following integrands are equal. *)
{(-5 - 4*x - 3*Sqrt[1 - x^2])/((4 + 5*x)^2*Sqrt[1 - x^2]), x, 7, 3/(5*(4 + 5*x)) + Sqrt[1 - x^2]/(4 + 5*x)}
{(-1 + Sqrt[1 - x^2])/(Sqrt[1 - x^2]*(2 + x - 2*Sqrt[1 - x^2])^2), x, 5, 3/(5*(4 + 5*x)) + Sqrt[1 - x^2]/(4 + 5*x)}
{((-5 - 4*x)*Sqrt[1 - x^2] + 3*(1 - x^2))^(-1), x, 14, 3/(5*(4 + 5*x)) + Sqrt[1 - x^2]/(4 + 5*x)}


(* Using the substitution u=x^(1-n) instead of algebraic expansion results in the nonoptimal result. *) 
{(a + b*x^(n-1))/(c*x + d*x^n), x, 5, (b*Log[x])/d - ((b*c - a*d)*Log[d + c*x^(1 - n)])/(c*d*(1 - n)), (b*Log[x^(1 - n)])/(d*(1 - n)) - ((b*c - a*d)*Log[d + c*x^(1 - n)])/(c*d*(1 - n))}


{1/(Sqrt[-7 + 2*x + 5*x^2]*(8 + 12*x + 5*x^2)), x, 3, (-(1/20) + I/10)*ArcTan[((1/50 + I/100)*((-164 - 8*I) - (100 + 40*I)*x))/Sqrt[-7 + 2*x + 5*x^2]] - (1/10 - I/20)*ArcTanh[((1/100 + I/50)*((-164 + 8*I) - (100 - 40*I)*x))/Sqrt[-7 + 2*x + 5*x^2]]}


{Sqrt[a + b*x + c*x^2]/((d + e*x)*(f + g*x)), x, 4, (Sqrt[c]*ArcTanh[(b + 2*c*x)/(2*Sqrt[c]*Sqrt[a + b*x + c*x^2])])/(e*g) + (Sqrt[c*d^2 - b*d*e + a*e^2]*ArcTanh[(b*d - 2*a*e + (2*c*d - b*e)*x)/(2*Sqrt[c*d^2 - b*d*e + a*e^2]*Sqrt[a + b*x + c*x^2])])/(e*(e*f - d*g)) - (Sqrt[c*f^2 - b*f*g + a*g^2]*ArcTanh[(b*f - 2*a*g + (2*c*f - b*g)*x)/(2*Sqrt[c*f^2 - g*(b*f - a*g)]*Sqrt[a + b*x + c*x^2])])/(g*(e*f - d*g))}


{(-x + 2*x^3 + 4*x^5)/(3 + 2*x^2 + x^4)^2, x, 4, (5 - 7*x^2)/(8*(3 + 2*x^2 + x^4)) + (9*ArcTan[(1 + x^2)/Sqrt[2]])/(8*Sqrt[2])}
{(x + x^5)/(1 + 2*x^2 + 2*x^4)^3, x, 5, (3 + 4*x^2)/(16*(1 + 2*x^2 + 2*x^4)^2) + (1 + 2*x^2)/(2*(1 + 2*x^2 + 2*x^4)) + ArcTan[1 + 2*x^2]}

{(a + b*x + c*x^2)/(d + e*x^2 + f*x^4), x, 7, ((2*a*f - c*(e - Sqrt[e^2 - 4*d*f]))*ArcTan[(Sqrt[2]*Sqrt[f]*x)/Sqrt[e - Sqrt[e^2 - 4*d*f]]])/(Sqrt[2]*Sqrt[f]*Sqrt[e^2 - 4*d*f]*Sqrt[e - Sqrt[e^2 - 4*d*f]]) - ((2*a*f - c*(e + Sqrt[e^2 - 4*d*f]))*ArcTan[(Sqrt[2]*Sqrt[f]*x)/Sqrt[e + Sqrt[e^2 - 4*d*f]]])/(Sqrt[2]*Sqrt[f]*Sqrt[e^2 - 4*d*f]*Sqrt[e + Sqrt[e^2 - 4*d*f]]) - (b*ArcTanh[(e + 2*f*x^2)/Sqrt[e^2 - 4*d*f]])/Sqrt[e^2 - 4*d*f]}
{(d + e*x)^2/(a + b*x^2 + c*x^4), x, 7, ((2*c*d^2 - (b - Sqrt[b^2 - 4*a*c])*e^2)*ArcTan[(Sqrt[2]*Sqrt[c]*x)/Sqrt[b - Sqrt[b^2 - 4*a*c]]])/(Sqrt[2]*Sqrt[c]*Sqrt[b^2 - 4*a*c]*Sqrt[b - Sqrt[b^2 - 4*a*c]]) - ((2*c*d^2 - (b + Sqrt[b^2 - 4*a*c])*e^2)*ArcTan[(Sqrt[2]*Sqrt[c]*x)/Sqrt[b + Sqrt[b^2 - 4*a*c]]])/(Sqrt[2]*Sqrt[c]*Sqrt[b^2 - 4*a*c]*Sqrt[b + Sqrt[b^2 - 4*a*c]]) - (2*d*e*ArcTanh[(b + 2*c*x^2)/Sqrt[b^2 - 4*a*c]])/Sqrt[b^2 - 4*a*c]}


{Sqrt[1 + 2*x^2]/(1 + Sqrt[1 + 2*x^2]), x, 6, -(1/(2*x)) + x + Sqrt[1 + 2*x^2]/(2*x) - ArcSinh[Sqrt[2]*x]/Sqrt[2]}
{Sqrt[-1 + 4*x^2]/(x + Sqrt[-1 + 4*x^2]), x, 7, (4*x)/3 - (1/3)*Sqrt[-1 + 4*x^2] - ArcTanh[Sqrt[3]*x]/(3*Sqrt[3]) + ArcTanh[Sqrt[3]*Sqrt[-1 + 4*x^2]]/(3*Sqrt[3])}


{x^2/((c + d*x)*(a + b*x^1)), x, 2, x/(b*d) + (a^2*Log[a + b*x])/(b^2*(b*c - a*d)) - (c^2*Log[c + d*x])/(d^2*(b*c - a*d))}
{x^2/((c + d*x)*(a + b*x^2)), x, 5, -((Sqrt[a]*c*ArcTan[(Sqrt[b]*x)/Sqrt[a]])/(Sqrt[b]*(b*c^2 + a*d^2))) + (c^2*Log[c + d*x])/(d*(b*c^2 + a*d^2)) + (a*d*Log[a + b*x^2])/(2*b*(b*c^2 + a*d^2))}
{x^2/((c + d*x)*(a + b*x^3)), x, 9, -((a^(1/3)*d*ArcTan[(a^(1/3) - 2*b^(1/3)*x)/(Sqrt[3]*a^(1/3))])/(Sqrt[3]*b^(2/3)*(b^(2/3)*c^2 + a^(1/3)*b^(1/3)*c*d + a^(2/3)*d^2))) + (a^(1/3)*d*(b^(1/3)*c + a^(1/3)*d)*Log[a^(1/3) + b^(1/3)*x])/(3*b^(2/3)*(b*c^3 - a*d^3)) - (c^2*Log[c + d*x])/(b*c^3 - a*d^3) - (a^(1/3)*d*(b^(1/3)*c + a^(1/3)*d)*Log[a^(2/3) - a^(1/3)*b^(1/3)*x + b^(2/3)*x^2])/(6*b^(2/3)*(b*c^3 - a*d^3)) + (c^2*Log[a + b*x^3])/(3*(b*c^3 - a*d^3))}
{x^2/((c + d*x)*(a + b*x^4)), x, 11, (c*(Sqrt[b]*c^2 - Sqrt[-a]*d^2)*ArcTan[(b^(1/4)*x)/(-a)^(1/4)])/(2*(-a)^(1/4)*b^(1/4)*(b*c^4 + a*d^4)) + (Sqrt[a]*d^3*ArcTan[(Sqrt[b]*x^2)/Sqrt[a]])/(2*Sqrt[b]*(b*c^4 + a*d^4)) - (c*(Sqrt[b]*c^2 + Sqrt[-a]*d^2)*ArcTanh[(b^(1/4)*x)/(-a)^(1/4)])/(2*(-a)^(1/4)*b^(1/4)*(b*c^4 + a*d^4)) + (c^2*d*Log[c + d*x])/(b*c^4 + a*d^4) - (c^2*d*Log[a + b*x^4])/(4*(b*c^4 + a*d^4))}


(* ::Section::Closed:: *)
(*Integrands requiring partial fraction expansion*)


(* ::Subsection::Closed:: *)
(*Problems from Calculus textbooks and competitions*)


{(9 + x + 3*x^2 + x^3)/((1 + x^2)*(3 + x^2)), x, 4, 3*ArcTan[x] + (1/2)*Log[3 + x^2]}
{(3 + x + x^2 + x^3)/((1 + x^2)*(3 + x^2)), x, 4, ArcTan[x] + Log[3 + x^2]/2}
{(-4 + 6*x - x^2 + 3*x^3)/((1 + x^2)*(2 + x^2)), x, 6, -3*ArcTan[x] + Sqrt[2]*ArcTan[x/Sqrt[2]] + (3*Log[1 + x^2])/2}


(* ::Subsubsection::Closed:: *)
(*Anton Calculus, 4th Edition*)


{(1 - 3*x^4)/((-2 + x)*(1 + x^2)^2), x, 7, -((1 - 2*x)/(5*(1 + x^2))) - (46*ArcTan[x])/25 - (47/25)*Log[2 - x] - (14/25)*Log[1 + x^2]}
{(-9 - 9*x + 2*x^2)/(-9*x + x^3), x, 3, -Log[3 - x] + Log[x] + 2*Log[3 + x]}
{(1 + 2*x^2 + x^5)/(-x + x^3), x, 3, x + x^3/3 + 2*Log[1 - x] - Log[x] + Log[1 + x]}
{(3 + 2*x^2)/((-1 + x)^2*x), x, 2, 5/(1 - x) - Log[1 - x] + 3*Log[x]}
{(-1 + 2*x^2)/((-1 + 4*x)*(1 + x^2)), x, 5, (3*ArcTan[x])/17 - (7/34)*Log[1 - 4*x] + (6/17)*Log[1 + x^2]}
{(-3 + 2*x - 3*x^2 + x^3)/(1 + x^2), x, 3, -3*x + x^2/2 + (1/2)*Log[1 + x^2]}
{(x + 10*x^2 + 6*x^3 + x^4)/(10 + 6*x + x^2), x, 6, x^3/3 - 3*ArcTan[3 + x] + Log[10 + 6*x + x^2]/2}
{(4 + 4*x + 4*x^2 + 4*x^3 + x^4 + x^5)/(2 + x^2)^3, x, 4, ArcTan[x/Sqrt[2]]/Sqrt[2] + (1/2)*Log[2 + x^2]}
{1/(-18 + 27*x - 7*x^2 - 3*x^3 + x^4), x, 2, (1/8)*Log[1 - x] - (1/5)*Log[2 - x] + (1/12)*Log[3 - x] - (1/120)*Log[3 + x]}
{1/(-1 + 4*x - 4*x^2 + 16*x^3), x, 5, (-(1/10))*ArcTan[2*x] + (1/5)*Log[1 - 4*x] - (1/10)*Log[1 + 4*x^2]}
{(1 + x^3)/(-2 + x), x, 2, 4*x + x^2 + x^3/3 + 9*Log[2 - x]}


(* ::Subsubsection::Closed:: *)
(*Apostol Calculus, Volume 1, 2nd Edition, Section 6.25*)


{x/(2 - 3*x + x^3), x, 2, 1/(3*(1 - x)) + (2/9)*Log[1 - x] - (2/9)*Log[2 + x]}
{(-6 + 2*x + x^4)/(-2*x + x^2 + x^3), x, 3, -x + x^2/2 - Log[1 - x] + 3*Log[x] + Log[2 + x]}
{(7 + 8*x^3)/((1 + x)*(1 + 2*x)^3), x, 2, -(3/(1 + 2*x)^2) + 3/(1 + 2*x) + Log[1 + x]}
{(1 + x^4)/(x*(1 + x^2)^2), x, 3, (1 + x^2)^(-1) + Log[x]}
{(1 - x^3)/(x*(1 + x^2)), x, 5, -x + ArcTan[x] + Log[x] - Log[1 + x^2]/2}


(* ::Subsubsection::Closed:: *)
(*Ayres Calculus, 1964 edition*)


{(3*x - 4*x^2 + 3*x^3)/(1 + x^2), x, 4, -4*x + (3*x^2)/2 + 4*ArcTan[x]}
{(5 + 3*x)/(1 - x - x^2 + x^3), x, 3, 4/(1 - x) + ArcTanh[x]}
{(-1 - x - x^3 + x^4)/(-x^2 + x^3), x, 3, -(1/x) + x^2/2 - 2*Log[1 - x] + 2*Log[x]}
{(2 + x + x^2 + x^3)/(2 + 3*x^2 + x^4), x, 4, ArcTan[x] + Log[2 + x^2]/2}
{(-4 + 8*x - 4*x^2 + 4*x^3 - x^4 + x^5)/(2 + x^2)^3, x, 6, -(1/(2 + x^2)^2) - ArcTan[x/Sqrt[2]]/Sqrt[2] + (1/2)*Log[2 + x^2]}
{(-1 - 3*x + x^2)/(-2*x + x^2 + x^3), x, 3, -Log[1 - x] + Log[x]/2 + (3/2)*Log[2 + x]}
{(3 - x + 3*x^2 - 2*x^3 + x^4)/(3*x - 2*x^2 + x^3), x, 4, x^2/2 + Log[x] - (1/2)*Log[3 - 2*x + x^2]}
{(-1 + x + x^3)/(1 + x^2)^2, x, 5, -(x/(2*(1 + x^2))) - ArcTan[x]/2 + (1/2)*Log[1 + x^2]}
{(1 + 2*x - x^2 + 8*x^3 + x^4)/((x + x^2)*(1 + x^3)), x, 6, -(3/(1 + x)) - (2*ArcTan[(1 - 2*x)/Sqrt[3]])/Sqrt[3] + Log[x] - 2*Log[1 + x] + Log[1 - x + x^2]}
{(15 - 5*x + x^2 + x^3)/((5 + x^2)*(3 + 2*x + x^2)), x, 6, (-Sqrt[5])*ArcTan[x/Sqrt[5]] + (5*ArcTan[(1 + x)/Sqrt[2]])/Sqrt[2] + (1/2)*Log[3 + 2*x + x^2]}
{(-3 + 25*x + 23*x^2 + 32*x^3 + 15*x^4 + 7*x^5 + x^6)/((1 + x^2)^2*(2 + x + x^2)^2), x, 6, -3/(1 + x^2) + (2 + x + x^2)^(-1) + Log[1 + x^2] - Log[2 + x + x^2]}


(* ::Subsubsection::Closed:: *)
(*Edwards and Penney Calculus*)


{1/((1 + x^2)*(4 + x^2)), x, 3, (-(1/6))*ArcTan[x/2] + ArcTan[x]/3}
{(a + b*x^3)/(1 + x^2), x, 5, (b*x^2)/2 + a*ArcTan[x] - (1/2)*b*Log[1 + x^2]}
{(x + x^2)/((4 + x)*(-4 + x^2)), x, 4, (-(1/2))*ArcTanh[x/2] + Log[4 + x]}
{(4 + x^2)/((1 + x^2)*(2 + x^2)), x, 3, 3*ArcTan[x] - Sqrt[2]*ArcTan[x/Sqrt[2]]}
{(5 - 4*x + 3*x^2 + x^4)/((-1 + x)^2*(1 + x^2)), x, 5, 5/(2*(1 - x)) + x + 2*ArcTan[x] + (1/2)*Log[1 - x] + (3/4)*Log[1 + x^2]}
{(1 + x^4)/(2 + x^2), x, 3, -2*x + x^3/3 + (5*ArcTan[x/Sqrt[2]])/Sqrt[2]}
{(2 + 2*x + x^4)/(x^4 + x^5), x, 3, -2/(3*x^3) + Log[1 + x]}
{(-1 - 5*x + 2*x^2)/(2 - x - 2*x^2 + x^3), x, 2, 2*Log[1 - x] - Log[2 - x] + Log[1 + x]}
{(2 + x + x^3)/(1 + 2*x^2 + x^4), x, 8, x/(1 + x^2) + ArcTan[x] + Log[1 + x^2]/2}
{(1 + 2*x + x^2 + x^3)/(1 + 2*x^2 + x^4), x, 8, -(1/(2*(1 + x^2))) + ArcTan[x] + (1/2)*Log[1 + x^2]}
{(3 + 4*x)/((1 + x^2)*(2 + x^2)), x, 8, 3*ArcTan[x] - (3*ArcTan[x/Sqrt[2]])/Sqrt[2] + 2*Log[1 + x^2] - 2*Log[2 + x^2]}
{(2 + x)/((1 + x^2)*(4 + x^2)), x, 8, (-(1/3))*ArcTan[x/2] + (2*ArcTan[x])/3 + (1/6)*Log[1 + x^2] - (1/6)*Log[4 + x^2]}


(* ::Subsubsection::Closed:: *)
(*Grossman Calculus*)


{(2 - x + x^3)/(-7 - 6*x + x^2), x, 5, 6*x + x^2/2 + (169/4)*Log[7 - x] - (1/4)*Log[1 + x]}
{(-1 + x^5)/(-1 + x^2), x, 4, x^2/2 + x^4/4 + Log[1 + x]}
{(5 + 2*x - x^2 + x^3)/(1 + x + x^2), x, 5, -2*x + x^2/2 + (11*ArcTan[(1 + 2*x)/Sqrt[3]])/Sqrt[3] + (3/2)*Log[1 + x + x^2]}
{(-3 + x - 2*x^3 + x^4)/(10 - 8*x + 2*x^2), x, 5, (3*x)/2 + x^2/2 + x^3/6 + 6*ArcTan[2 - x] + (3/4)*Log[5 - 4*x + x^2]}
{(1 + 2*x + 3*x^2 + x^3)/((-3 + x)*(-2 + x)*(-1 + x)), x, 2, x + (7/2)*Log[1 - x] - 25*Log[2 - x] + (61/2)*Log[3 - x]}
{(2 - 7*x + x^2 - x^3 + x^4)/(-24 - 14*x + x^2 + x^3), x, 4, -2*x + x^2/2 + (13/3)*Log[4 - x] - (22/3)*Log[2 + x] + 20*Log[3 + x]}
{(2 + x^2)/((-1 + x)^2*x*(1 + x)), x, 2, 3/(2*(1 - x)) - (5/4)*Log[1 - x] + 2*Log[x] - (3/4)*Log[1 + x]}
{(3 + x^2 + x^3)/(2 + x^2)^2, x, 7, (4 + x)/(4*(2 + x^2)) + (5*ArcTan[x/Sqrt[2]])/(4*Sqrt[2]) + (1/2)*Log[2 + x^2]}
{(-35 + 70*x - 4*x^2 + 2*x^3)/((26 - 10*x + x^2)*(17 - 2*x + x^2)), x, 8, -((15033*ArcTan[5 - x])/1025) + (4607*ArcTan[1/4 - x/4])/4100 + (1003*Log[26 - 10*x + x^2])/1025 + (22*Log[17 - 2*x + x^2])/1025}
{(2 + x^2)/((-5 + x)*(-3 + x)*(4 + x)), x, 2, (-(11/14))*Log[3 - x] + (3/2)*Log[5 - x] + (2/7)*Log[4 + x]}
{x^4/((-1 + x)*(2 + x^2)), x, 5, x + x^2/2 - (2/3)*Sqrt[2]*ArcTan[x/Sqrt[2]] + (1/3)*Log[1 - x] - (2/3)*Log[2 + x^2]}


(* ::Subsubsection::Closed:: *)
(*Spivak Calculus*)


{(-1 + 7*x + 2*x^2)/(-1 - x + x^2 + x^3), x, 2, -3/(1 + x) + 2*Log[1 - x]}
{(1 + 2*x)/(-1 + 3*x - 3*x^2 + x^3), x, 2, -((1 + 2*x)^2/(6*(1 - x)^2))}
{(5 - 5*x + 7*x^2 + x^3)/((-1 + x)^2*(1 + x)^3), x, 2, (1 - x)^(-1) - 2/(1 + x)^2}
{(1 + 3*x + 3*x^2)/(1 + 2*x + 2*x^2 + x^3), x, 5, (-2*ArcTan[(1 + 2*x)/Sqrt[3]])/Sqrt[3] + Log[1 + x] + Log[1 + x + x^2]}


(* ::Subsubsection::Closed:: *)
(*Stewart Calculus*)


{(-1 + 2*x + x^2)/(-2*x + 3*x^2 + 2*x^3), x, 3, (1/10)*Log[1 - 2*x] + Log[x]/2 - (1/10)*Log[2 + x]}
{(1 + 4*x - 2*x^2 + x^4)/(1 - x - x^2 + x^3), x, 5, 2/(1 - x) + x + x^2/2 - 2*ArcTanh[x]}
{(4 - x + 2*x^2)/(4*x + x^3), x, 6, (-(1/2))*ArcTan[x/2] + Log[x] + (1/2)*Log[4 + x^2]}
{(1 + x^2 + x^3)/((-1 + x)*x*(1 + x^2)^3*(1 + x + x^2)), x, 13, (1 + x)/(8*(1 + x^2)^2) - (3*(1 - x))/(8*(1 + x^2)) + (3*x)/(16*(1 + x^2)) + (7*ArcTan[x])/16 - ArcTan[(1 + 2*x)/Sqrt[3]]/Sqrt[3] + (1/8)*Log[1 - x] - Log[x] + (15/16)*Log[1 + x^2] - (1/2)*Log[1 + x + x^2]}
{(1 - 3*x + 2*x^2 - x^3)/(1 + x^2)^2, x, 7, (2 - x)/(2*(1 + x^2)) + (3*ArcTan[x])/2 - (1/2)*Log[1 + x^2]}
{(1 - 3*x + 2*x^2 - x^3)/(x*(1 + x^2)^2), x, 7, -((1 + 2*x)/(2*(1 + x^2))) - 2*ArcTan[x] + Log[x] - (1/2)*Log[1 + x^2]}
{(1 - x - x^2 + x^3 + x^4)/(-x + x^3), x, 4, x + x^2/2 - Log[x] + (1/2)*Log[1 - x^2]}
{(2 - 4*x^2 + x^3)/((1 + x^2)*(2 + x^2)), x, 8, 6*ArcTan[x] - 5*Sqrt[2]*ArcTan[x/Sqrt[2]] - Log[1 + x^2]/2 + Log[2 + x^2]}
{(1 + x^2 + x^4)/((1 + x^2)*(4 + x^2)^2), x, 6, -((13*x)/(24*(4 + x^2))) + (25/144)*ArcTan[x/2] + ArcTan[x]/9}
{(1 + x^2 + x^3)/(2*x^2 + x^3 + x^4), x, 6, -(1/(2*x)) + ArcTan[(1 + 2*x)/Sqrt[7]]/(4*Sqrt[7]) - Log[x]/4 + (5/8)*Log[2 + x + x^2]}
{(1 - 12*x + x^2 + x^3)/(-12 + x + x^2), x, 5, x^2/2 - (2/7)*ArcTanh[(1/7)*(1 + 2*x)], x^2/2 + (1/7)*Log[3 - x] - (1/7)*Log[4 + x]}
{(-3 + 5*x + 6*x^2)/(-3*x + 2*x^2 + x^3), x, 3, 2*Log[1 - x] + Log[x] + 3*Log[3 + x]}
{(-2 + 3*x + 5*x^2)/(2*x^2 + x^3), x, 3, x^(-1) + 2*Log[x] + 3*Log[2 + x]}
{(18 - 2*x - 4*x^2)/(-6 + x + 4*x^2 + x^3), x, 2, Log[1 - x] - 2*Log[2 + x] - 3*Log[3 + x]}
{(1 + x - 2*x^2 + x^3)/(4 + 5*x^2 + x^4), x, 6, (-(3/2))*ArcTan[x/2] + ArcTan[x] + (1/2)*Log[4 + x^2]}
{(-32 + 5*x - 27*x^2 + 4*x^3)/(-70 - 299*x - 286*x^2 + 50*x^3 - 13*x^4 + 30*x^5), x, 5, (3988*ArcTan[(1 + 2*x)/Sqrt[19]])/(13685*Sqrt[19]) - (3146*Log[7 - 3*x])/80155 - (334/323)*Log[1 + 2*x] + (4822*Log[2 + 5*x])/4879 + (11049*Log[5 + x + x^2])/260015}
{(8 - 13*x^2 - 7*x^3 + 12*x^5)/(4 - 20*x + 41*x^2 - 80*x^3 + 116*x^4 - 80*x^5 + 100*x^6), x, 8, 5828/(9075*(2 - 5*x)) - (313 + 502*x)/(1452*(1 + 2*x^2)) + (503*ArcTan[Sqrt[2]*x])/(7986*Sqrt[2]) - (59096*Log[2 - 5*x])/99825 + (2843*Log[1 + 2*x^2])/7986, 5828/(9075*(2 - 5*x)) - (313 + 502*x)/(1452*(1 + 2*x^2)) - (251*ArcTan[Sqrt[2]*x])/(726*Sqrt[2]) + (272*Sqrt[2]*ArcTan[Sqrt[2]*x])/1331 - (59096*Log[2 - 5*x])/99825 + (2843*Log[1 + 2*x^2])/7986}
{1/(1 + x + x^2 + x^3), x, 5, ArcTan[x]/2 + (1/2)*Log[1 + x] - (1/4)*Log[1 + x^2]}


(* ::Subsubsection::Closed:: *)
(*Thomas Calculus, 8th Edition*)


{(9 + x^4)/(x^2*(9 + x^2)), x, 3, -x^(-1) + x - (10*ArcTan[x/3])/3}
{(2*x + x^4)/(1 + x^2), x, 6, -x + x^3/3 + ArcTan[x] + Log[1 + x^2]}
{(-x + x^3)/((-1 + x)^2*(1 + x^2)), x, 5, ArcTan[x] + Log[1 - x]}
{(2 + 5*x + 3*x^2 + 2*x^3)/(1 + x + x^2), x, 3, x + x^2 + Log[1 + x + x^2]}
{(3 - 4*x - 5*x^2 + 3*x^3)/(x^3*(-1 + x + x^2)), x, 5, 3/(2*x^2) - 1/x + 3*Log[x] - (1/10)*(15 - Sqrt[5])*Log[1 - Sqrt[5] + 2*x] - (1/10)*(15 + Sqrt[5])*Log[1 + Sqrt[5] + 2*x]}
{(4 + 8*x + 5*x^2 + 2*x^3)/(2 + 2*x + x^2)^2, x, 6, -(1/(2 + 2*x + x^2)) - ArcTan[1 + x] + Log[2 + 2*x + x^2]}
{((-1 + x)^4*x^4)/(1 + x^2), x, 3, 4*x - (4*x^3)/3 + x^5 - (2*x^6)/3 + x^7/7 - 4*ArcTan[x]}
{(-20*x + 4*x^2)/(9 - 10*x^2 + x^4), x, 3, Log[1 - x] - (1/2)*Log[3 - x] + (3/2)*Log[1 + x] - 2*Log[3 + x]}
{(-1 + x + 4*x^3)/((-1 + x)*x^2*(1 + x^2)), x, 5, -x^(-1) + ArcTan[x] + 2*Log[1 - x] - Log[1 + x^2]}

{(1 - 3*x + 2*x^2 - 4*x^3 + x^4)/(1 + x^2)^3, x, 6, -(1/(4*(1 + x^2)^2)) + 2/(1 + x^2) + ArcTan[x]}
{(1 - 3*x + 2*x^2 - 4*x^3 + x^4)/(1 + 3*x^2 + 3*x^4 + x^6), x, 6, -(1/(4*(1 + x^2)^2)) + 2/(1 + x^2) + ArcTan[x]}


(* ::Subsubsection::Closed:: *)
(*North Texas University Integration Competition*)


{(1 + x + 2*x^2 + 2*x^3)/(x^2 + x^3 + x^4), x, 4, -x^(-1) + Log[1 + x + x^2]}


(* ::Subsection::Closed:: *)
(*Miscellaneous problems*)


{1/((4 - 4*x + x^2)*(5 - 4*x + x^2)), x, 3, 1/(2 - x) + ArcTan[2 - x]}

{(-3 + x + x^2)/((-3 + x)*x^2), x, 2, -(1/x) + Log[3 - x]}
{(1 + x + 4*x^2)/(x + 4*x^3), x, 4, ArcTan[2*x]/2 + Log[x]}
{(1 - x + 3*x^2)/(-x^2 + x^3), x, 3, 1/x + 3*Log[1 - x]}
{(4 + 3*x + x^2)/(x + x^2), x, 3, x + 4*Log[x] - 2*Log[1 + x]}
{(4 + x + 3*x^2)/(x + x^3), x, 6, ArcTan[x] + 4*Log[x] - Log[1 + x^2]/2}

{(7 - 4*x + 8*x^2)/((1 + 4*x)*(1 + x^2)), x, 3, -ArcTan[x] + 2*Log[1 + 4*x]}
{x^2/((-1 + x)*(1 + 2*x + x^2)), x, 3, 1/(2*(1 + x)) + (1/4)*Log[1 - x] + (3/4)*Log[1 + x]}
{(-4 + 3*x + x^2)/((-1 + 2*x)^2*(3 + 2*x)), x, 2, -(9/(32*(1 - 2*x))) + (41/128)*Log[1 - 2*x] - (25/128)*Log[3 + 2*x]}
{(5 - 4*x + 3*x^2)/((-1 + x)*(1 + x^2)), x, 5, -3*ArcTan[x] + 2*Log[1 - x] + (1/2)*Log[1 + x^2]}
{(-1 - 2*x + x^2)/((-1 + x)^2*(1 + x^2)), x, 5, 1/(-1 + x) + ArcTan[x] + Log[1 - x] - (1/2)*Log[1 + x^2]}
{(5 + x^3)/((10 - 6*x + x^2)*(1/2 - x + x^2)), x, 8, (-(261/221))*ArcTan[1 - 2*x] - (1026/221)*ArcTan[3 - x] + (56/221)*Log[10 - 6*x + x^2] + (109/442)*Log[1 - 2*x + 2*x^2]}

{(4 + 3*x + x^2)/((-3 + x)*(-2 + x)*(-1 + x)), x, 2, 4*Log[1 - x] - 14*Log[2 - x] + 11*Log[3 - x]}
{(1 + 16*x)/((5 + x)^2*(-3 + 2*x)*(1 + x + x^2)), x, 5, -(79/(273*(5 + x))) + (451*ArcTan[(1 + 2*x)/Sqrt[3]])/(2793*Sqrt[3]) + (200*Log[3 - 2*x])/3211 + (2731*Log[5 + x])/24843 - (481*Log[1 + x + x^2])/5586}


{(-1 + x^3)/(1 + x + x^2), x, 2, -x + x^2/2}
{(-3 + x^3)/(-7 - 6*x + x^2), x, 5, 6*x + x^2/2 + (85/2)*Log[7 - x] + (1/2)*Log[1 + x]}

{(1 + x^3)/(13 + 4*x + x^2)^2, x, 7, (67 + 47*x)/(18*(13 + 4*x + x^2)) - (61/54)*ArcTan[2/3 + x/3] + (1/2)*Log[13 + 4*x + x^2]}


{(-32 + 36*x - 42*x^2 + 21*x^3 - 10*x^4 + 3*x^5)/(x*(1 + x^2)*(4 + x^2)^2), x, 7, (4 + x^2)^(-1) + ArcTan[x/2]/2 + 2*ArcTan[x] - 2*Log[x] + Log[4 + x^2]}


{(-1 + x^4 + 7*x^5 + x^9)/(-7 + 6*x^4 + x^8), x, 13, x^2/2 - ArcTan[1 - (Sqrt[2]*x)/7^(1/4)]/(2*Sqrt[2]*7^(3/4)) + ArcTan[1 + (Sqrt[2]*x)/7^(1/4)]/(2*Sqrt[2]*7^(3/4)) + (1/4)*Log[1 - x^2] - (1/4)*Log[1 + x^2] - Log[Sqrt[7] - Sqrt[2]*7^(1/4)*x + x^2]/(4*Sqrt[2]*7^(3/4)) + Log[Sqrt[7] + Sqrt[2]*7^(1/4)*x + x^2]/(4*Sqrt[2]*7^(3/4))}
{(1 + x^3 + x^6)/(x + x^5), x, 16, x^2/2 - ArcTan[x^2]/2 - ArcTan[1 - Sqrt[2]*x]/(2*Sqrt[2]) + ArcTan[1 + Sqrt[2]*x]/(2*Sqrt[2]) + Log[x] + Log[1 - Sqrt[2]*x + x^2]/(4*Sqrt[2]) - Log[1 + Sqrt[2]*x + x^2]/(4*Sqrt[2]) - (1/4)*Log[1 + x^4]}


(* Note: This test problem formerly caused stack overflow because the degree of the polynomial 
	was not properly reduced by the Ostrogradskiy-Hermite method code. *)
(* {(a + 2*b*x - a*x^2)^4/(-1 + x^2)^5, x, 14, -((4*a*b*(3*a^2 - 2*b^2))/(3*(1 - x^2)^4)) + (11*a^4*x)/(5*(1 - x^2)^4) - (48*a^2*b^2*x)/(5*(1 - x^2)^4) + (6*b^4*x)/(5*(1 - x^2)^4) + (4*a*b*(9*a^2 - 8*b^2)*x^2)/(3*(1 - x^2)^4) - ((73*a^4 - 264*a^2*b^2 + 48*b^4)*x^3)/(15*(1 - x^2)^4) - (4*a*b*(3*a^2 - 2*b^2)*x^4)/(1 - x^2)^4 + (a^2*(11*a^2 - 24*b^2)*x^5)/(3*(1 - x^2)^4) + (4*a^3*b*x^6)/(1 - x^2)^4 - (a^4*x^7)/(1 - x^2)^4 - ((8*a^4 - 24*a^2*b^2 + 3*b^4)*x)/(15*(1 - x^2)^3) - ((8*a^4 - 24*a^2*b^2 + 3*b^4)*x)/(12*(1 - x^2)^2) - ((8*a^4 - 24*a^2*b^2 + 3*b^4)*x)/(8*(1 - x^2)) - (1/8)*(8*a^4 - 24*a^2*b^2 + 3*b^4)*ArcTanh[x]} *)


(* Integrands of the form (a+b*x^m)/(c*x^n+d*x^p) where m, n and p are integers *)
{(1 + x^2)/(-x + x^2), x, 3, x + 2*Log[1 - x] - Log[x]}

{(1 + x^3)/(-x + x^3), x, 4, x + Log[1 - x] - Log[x]}
{(1 + x^3)/(-x^2 + x^3), x, 3, x^(-1) + x + 2*Log[1 - x] - Log[x]}
{(-1 + x^5)/(-x + x^3), x, 4, x + x^3/3 + Log[x] - Log[1 + x]}
{(1 + x^4)/(x^3 + x^5), x, 4, -1/(2*x^2) - Log[x] + Log[1 + x^2]}


(* Integrands of the form (a+b*x^m)/(c*x^n+d*x^p+e*x^q) where m, n, p and q are integers *)
{(1 + x^2)/(x + 2*x^2 + x^3), x, 4, 2/(1 + x) + Log[x]}
{(1 + x^5)/(-10*x - 3*x^2 + x^3), x, 3, 19*x + (3*x^2)/2 + x^3/3 + (3126*Log[5 - x])/35 - Log[x]/10 - (31*Log[2 + x])/14}


{(15 - 5*x + x^2 + x^3)/((5 + x^2)*(3 + 2*x + x^2)), x, 6, (-Sqrt[5])*ArcTan[x/Sqrt[5]] + (5*ArcTan[(1 + x)/Sqrt[2]])/Sqrt[2] + (1/2)*Log[3 + 2*x + x^2]}

{1/((1 + x^2)*(3 + 10*x/(1 + x^2))), x, 4, (-(1/8))*Log[3 + x] + (1/8)*Log[1 + 3*x]}


(* Integrands of the form x^m/(a*x^n+b*x^p+c*x^q) where m, n, p and q are integers *)
(* In some of the following examples gcd cancellation should occur without also partial fraction 
	expansion, since that will result in unnecessary expansion. *)
{x^3/(13 + 2/x + 15*x), x, 2, (139*x)/3375 - (13*x^2)/450 + x^3/45 - (16/567)*Log[2 + 3*x] + Log[1 + 5*x]/4375}
{x^2/(13 + 2/x + 15*x), x, 2, -((13*x)/225) + x^2/30 + (8/189)*Log[2 + 3*x] - (1/875)*Log[1 + 5*x]}
{x/(13 + 2/x + 15*x), x, 2, x/15 - (4/63)*Log[2 + 3*x] + (1/175)*Log[1 + 5*x]}
{1/(13 + 2/x + 15*x), x, 2, (2/21)*Log[2 + 3*x] - (1/35)*Log[1 + 5*x]}
{1/(x*(13 + 2/x + 15*x)), x, 4, (-(1/7))*Log[2 + 3*x] + (1/7)*Log[1 + 5*x]}
{1/(x^2*(13 + 2/x + 15*x)), x, 6, Log[x]/2 + (3/14)*Log[2 + 3*x] - (5/7)*Log[1 + 5*x]}
{1/(x^3*(13 + 2/x + 15*x)), x, 7, -(1/(2*x)) - (13*Log[x])/4 - (9/28)*Log[2 + 3*x] + (25/7)*Log[1 + 5*x]}
{1/(x^4*(13 + 2/x + 15*x)), x, 8, -(1/(4*x^2)) + 13/(4*x) + (139*Log[x])/8 + (27/56)*Log[2 + 3*x] - (125/7)*Log[1 + 5*x]}
{1/(x^5*(13 + 2/x + 15*x)), x, 9, -(1/(6*x^3)) + 13/(8*x^2) - 139/(8*x) - (1417*Log[x])/16 - (81/112)*Log[2 + 3*x] + (625/7)*Log[1 + 5*x]}


{(1 - x^2)/(a + b*(1 - x^2)^4), x, 9, -(ArcTan[(b^(1/8)*x)/Sqrt[(-a)^(1/4) - b^(1/4)]]/(4*Sqrt[-a]*Sqrt[(-a)^(1/4) - b^(1/4)]*b^(3/8))) + ((-1)^(3/4)*ArcTan[((-1)^(3/4)*b^(1/8)*x)/Sqrt[(-a)^(1/4) + I*b^(1/4)]])/(4*Sqrt[-a]*Sqrt[(-a)^(1/4) + I*b^(1/4)]*b^(3/8)) - ((-1)^(3/4)*ArcTanh[((-1)^(3/4)*b^(1/8)*x)/Sqrt[(-a)^(1/4) - I*b^(1/4)]])/(4*Sqrt[-a]*Sqrt[(-a)^(1/4) - I*b^(1/4)]*b^(3/8)) + ArcTanh[(b^(1/8)*x)/Sqrt[(-a)^(1/4) + b^(1/4)]]/(4*Sqrt[-a]*Sqrt[(-a)^(1/4) + b^(1/4)]*b^(3/8))}
{(1 - x^2)/(a + b*(-1 + x^2)^4), x, 9, -(ArcTan[(b^(1/8)*x)/Sqrt[(-a)^(1/4) - b^(1/4)]]/(4*Sqrt[-a]*Sqrt[(-a)^(1/4) - b^(1/4)]*b^(3/8))) + ((-1)^(3/4)*ArcTan[((-1)^(3/4)*b^(1/8)*x)/Sqrt[(-a)^(1/4) + I*b^(1/4)]])/(4*Sqrt[-a]*Sqrt[(-a)^(1/4) + I*b^(1/4)]*b^(3/8)) - ((-1)^(3/4)*ArcTanh[((-1)^(3/4)*b^(1/8)*x)/Sqrt[(-a)^(1/4) - I*b^(1/4)]])/(4*Sqrt[-a]*Sqrt[(-a)^(1/4) - I*b^(1/4)]*b^(3/8)) + ArcTanh[(b^(1/8)*x)/Sqrt[(-a)^(1/4) + b^(1/4)]]/(4*Sqrt[-a]*Sqrt[(-a)^(1/4) + b^(1/4)]*b^(3/8))}


(* ::Section::Closed:: *)
(*Integrands requiring the Ostrogradskiy-Hermite method*)


{(-1 + 4*x^5)/(1 + x + x^5)^2, x, 1, -(x/(1 + x + x^5))}
{(b*c - a*d - 2*a*e*x - b*e*x^2 - 3*a*f*x^2 - 2*b*f*x^3)/(c + d*x + e*x^2 + f*x^3)^2, x, 2, a/(c + d*x + e*x^2 + f*x^3) + (b*x)/(c + d*x + e*x^2 + f*x^3)}
{(9 - 40*x - 18*x^2 + 174*x^4 + 24*x^5 + 26*x^6 - 39*x^8)/(3 + 2*x^2 + x^4)^3, x, 6, 2/(3 + 2*x^2 + x^4)^2 + (3*x)/(3 + 2*x^2 + x^4)^2 - (4*x^2)/(3 + 2*x^2 + x^4)^2 + (13*x^5)/(3 + 2*x^2 + x^4)^2}


(* Following integrands are equal. *)
{-((15 - 36*x + 5*x^2 + 12*x^3 - 34*x^4 + 140*x^5 + 15*x^6 + 8*x^7 - 30*x^9)/(3 + x + x^4)^4), x, 5, 2/(3 + x + x^4)^3 - (3*x)/(3 + x + x^4)^3 + (5*x^2)/(3 + x + x^4)^3 + x^4/(3 + x + x^4)^3 - (5*x^6)/(3 + x + x^4)^3}
{(3*(-47 + 228*x + 120*x^2 + 19*x^3))/(3 + x + x^4)^4 + (42 - 320*x - 75*x^2 - 8*x^3)/(3 + x + x^4)^3 + (30*x)/(3 + x + x^4)^2, x, 0, (2 - 3*x + 5*x^2 + x^4 - 5*x^6)/(3 + x + x^4)^3}
{(-3 + 10*x + 4*x^3 - 30*x^5)/(3 + x + x^4)^3 - (3*(1 + 4*x^3)*(2 - 3*x + 5*x^2 + x^4 - 5*x^6))/(3 + x + x^4)^4, x, 0, (2 - 3*x + 5*x^2 + x^4 - 5*x^6)/(3 + x + x^4)^3}
