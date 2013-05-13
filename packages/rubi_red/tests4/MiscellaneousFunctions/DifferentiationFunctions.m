(* ::Package:: *)

(* ::Title:: *)
(*Differentiation Function Integration Problems*)


{f'[x], x, 1, f[x]}
{f''[x], x, 1, f'[x]}
{f'''[x], x, 1, f''[x]}
{Derivative[n][f][x], x, 1, Derivative[n-1][f][x]}
{Derivative[1][u][x]*Derivative[2][u][x], x, 2, Derivative[1][u][x]^2/2}


{f'[x]/f[x], x, 2, Log[f[x]]}
{f'[x]/(a+b*f[x]), x, 2, Log[a+b*f[x]]/b}

{f[x]*f'[x], x, 2, f[x]^2/2}
{(a+b*f[x])*f'[x], x, 2, a*f[x] + (1/2)*b*f[x]^2}

{f'[x]/Sqrt[f[x]], x, 2, 2*Sqrt[f[x]]}
{f'[x]/Sqrt[a+b*f[x]], x, 2, (2*Sqrt[a+b*f[x]])/b}

{f[x]^n*f'[x], x, 2, f[x]^(n+1)/(n+1)}
{(a+b*f[x])^n*f'[x], x, 2, (a+b*f[x])^(n+1)/(b*(n+1))}


{f''[x]/f'[x], x, 2, Log[f'[x]]}
{f''[x]/(a+b*f'[x]), x, 2, Log[a+b*f'[x]]/b}

{f'[x]*f''[x], x, 2, f'[x]^2/2}
{(a+b*f'[x])*f''[x], x, 2, a*f'[x] + (1/2)*b*f'[x]^2}

{f''[x]/Sqrt[f'[x]], x, 2, 2*Sqrt[f'[x]]}
{f''[x]/Sqrt[a+b*f'[x]], x, 2, (2*Sqrt[a+b*f'[x]])/b}

{f'[x]^n*f''[x], x, 2, f'[x]^(n+1)/(n+1)}
{(a+b*f'[x])^n*f''[x], x, 2, (a+b*f'[x])^(n+1)/(b*(n+1))}


{f[g[x]]*g'[x], x, 1, Subst[Int[f[x], x], x, g[x]]}
{f[g'[x]]*g''[x], x, 1, Subst[Int[f[x], x], x, g'[x]]}


{f'[x]*g[x] + f[x]*g'[x], x, 1, f[x]*g[x]}
{(f'[x]*g[x] - f[x]*g'[x])/g[x]^2, x, 1, f[x]/g[x]}
{(f'[x]*g[x] - f[x]*g'[x])/(f[x]*g[x]), x, 1, Log[f[x]/g[x]]}
{(f'[x]*g[x] - f[x]*g'[x])/(f[x]^2 + g[x]^2), x, 1, ArcTan[f[x]/g[x]]}
{(f'[x]*g[x] - f[x]*g'[x])/(f[x]^2 - g[x]^2), x, 1, Log[(f[x]-g[x])/(f[x]+g[x])]/2}


{Cos[x]*g[E^x]*


\!\(\*SuperscriptBox["f", "\[Prime]",
MultilineFunction->None]\)[Sin[x]] + E^x*f[Sin[x]]*


\!\(\*SuperscriptBox["g", "\[Prime]",
MultilineFunction->None]\)[E^x], x, 1, f[Sin[x]]*g[E^x]}
