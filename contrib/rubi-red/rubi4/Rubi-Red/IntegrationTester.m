(* ::Package:: *)

IntegrationFunction=Int;
PrintProblems=False;
HideKnownProblems = False;
MakeTestSuite = False;
ShowDeficiencies = True;
UseSimpLite = False;
RulesDirectory="RulesArchive\\2011\\110615";
RulesDirectory="RulesArchive\\120514d";
RulesDirectory="Rules";


ProblemTimeLimit=10;
TimeLimit=5.0;


tan[z_] := Tan[z]


(* ::Subsection::Closed:: *)
(*Test control variables*)


(* This assignment designates the integration function (Int, Integrate or Internal) to be tested. *)
(* IntegrationFunction=Integrate; *) (* Use to test Mathematica's built-in integrator *)
(* IntegrationFunction=Internal; *)  (* Use to test correctness of test-suite antiderivatives *)


RulesDirectory=NotebookDirectory[]<>RulesDirectory<>"\\";


ProblemsDirectory="Problems";
(* ProblemsDirectory="ProblemsArchive\\091026"; *)
ProblemsDirectory=NotebookDirectory[]<>ProblemsDirectory<>"\\";


SimplifyResult=False;
FullTest=True;              (* Set to False when generating Maple/Mathematica/RBI spreadsheet *)
MaximumSteps=Null;
FlagProblemTime=Null;       (* Seconds of problem time for flagging slow problems *)


RationalFunctionTest=True;
AlgebraicFunctionTest=True;
ElementaryFunctionTest=True;
InverseFunctionTest=True;


int[u_] := Int[u,x];
ints[u_] := (ShowSteps=True; Int[u,x]);
intn[u_] := (ShowSteps=False; Int[u,x]);


Get[RulesDirectory<>"IntegrationTestProgram.m"];


(* ::Subsection::Closed:: *)
(*Monomial function integration test*)


If[RationalFunctionTest, IntegrationTest["P1 Monomial Functions\\P1.1 x^m (a x^r+b x^s+...)^n"]];


If[RationalFunctionTest, IntegrationTest["P1 Monomial Functions\\P1.2 x^m P[x] Q[x]^p"]];


If[RationalFunctionTest, IntegrationTest["P1 Monomial Functions\\P1.3 Normalization problems"]];


If[RationalFunctionTest, IntegrationTest["P1 Monomial Functions\\P1.4 Substitution problems"]];


If[RationalFunctionTest, IntegrationTest["P1 Monomial Functions\\P1.5 Piecewise constant extraction problems"]];


If[RationalFunctionTest, IntegrationTest["P1 Monomial Functions\\P1.6 Expansion problems"]];


If[RationalFunctionTest, IntegrationTest["P1 Monomial Functions\\P1.7 Miscellaneous problems"]];


(* ::Subsection::Closed:: *)
(*Binomial function integration test*)


If[RationalFunctionTest, IntegrationTest["P2 Binomial Functions\\P2.1.1 (a+b x)^m (c+d x)^n"]];


If[RationalFunctionTest, IntegrationTest["P2 Binomial Functions\\P2.1.2 (a+b x)^m (A+B x) (d+e x)^p"]];


If[RationalFunctionTest, IntegrationTest["P2 Binomial Functions\\P2.1.3 (a+b x)^m (c+d x)^n (e+f x)^p"]];


If[RationalFunctionTest, IntegrationTest["P2 Binomial Functions\\P2.2.1 x^m (a+b x^n)^p"]];


If[RationalFunctionTest, IntegrationTest["P2 Binomial Functions\\P2.2.2 (a+b x^n)^m (c+d x^n)^p"]];


If[RationalFunctionTest, IntegrationTest["P2 Binomial Functions\\P2.2.3 x^m (a+b x^n)^p (c+d x^n)^q"]];


If[RationalFunctionTest, IntegrationTest["P2 Binomial Functions\\P2.2.4 (a+b x^n)^m (c+d x^n)^p (e+f x^n)^q"]];


If[RationalFunctionTest, IntegrationTest["P2 Binomial Functions\\P2.2.5 x^m P[x] (a+b x^n)^p"]];


If[RationalFunctionTest, IntegrationTest["P2 Binomial Functions\\P2.3.1 x^m (a x^q+b x^n)^p"]];


(* ::Subsection::Closed:: *)
(*Trinomial function integration test*)


If[RationalFunctionTest, IntegrationTest["P3 Trinomial Functions\\P3.1.1 x^m (a+b x+c x^2)^p"]];


If[RationalFunctionTest, IntegrationTest["P3 Trinomial Functions\\P3.1.2 x^m (A+B x) (a+b x+c x^2)^p"]];


If[RationalFunctionTest, IntegrationTest["P3 Trinomial Functions\\P3.1.3 (d+e x)^m (a+b x+c x^2)^p"]];


If[RationalFunctionTest, IntegrationTest["P3 Trinomial Functions\\P3.1.4 (d+e x)^m (A+B x) (a+b x+c x^2)^p"]];


If[RationalFunctionTest, IntegrationTest["P3 Trinomial Functions\\P3.1.5 (a+b x+c x^2)^m (d+e x+f x^2)^p"]];


If[RationalFunctionTest, IntegrationTest["P3 Trinomial Functions\\P3.1.6 (A+B x) (a+b x+c x^2)^m (d+e x+f x^2)^p"]];


If[RationalFunctionTest, IntegrationTest["P3 Trinomial Functions\\P3.2.1 x^m (a+b x^2+c x^4)^p"]];


If[RationalFunctionTest, IntegrationTest["P3 Trinomial Functions\\P3.2.2 x^m (A+B x^2) (a+b x^2+c x^4)^p"]];


If[RationalFunctionTest, IntegrationTest["P3 Trinomial Functions\\P3.2.3 x^m (a+b x^n+c x^(2n))^p"]];


If[RationalFunctionTest, IntegrationTest["P3 Trinomial Functions\\P3.2.4 x^m (A+B x^n) (a+b x^n+c x^(2n))^p"]];


If[RationalFunctionTest, IntegrationTest["P3 Trinomial Functions\\P3.2.5 (d+e x^2)^m (a+b x^2+c x^4)^p"]];


If[RationalFunctionTest, IntegrationTest["P3 Trinomial Functions\\P3.3.1 x^m (a x^q+b x^n+c x^(2 n-q))^p"]];


(* ::Subsection::Closed:: *)
(*Exponential function integration test*)


If[InverseFunctionTest, IntegrationTest["ExponentialFunctions\\ExponentialFunctions"]];


If[InverseFunctionTest, IntegrationTest["ExponentialFunctions\\LogarithmFunctions"]];


(* ::Subsection::Closed:: *)
(*Trig function integration test*)


If[ElementaryFunctionTest, IntegrationTest["TrigFunctions\\SineFunctions"]];


If[ElementaryFunctionTest, IntegrationTest["TrigFunctions\\CosineFunctions"]];


If[ElementaryFunctionTest, IntegrationTest["TrigFunctions\\TangentFunctions"]];


If[ElementaryFunctionTest, IntegrationTest["TrigFunctions\\CotangentFunctions"]];


If[ElementaryFunctionTest, IntegrationTest["TrigFunctions\\SecantFunctions"]];


If[ElementaryFunctionTest, IntegrationTest["TrigFunctions\\CosecantFunctions"]];


If[ElementaryFunctionTest, IntegrationTest["TrigFunctions\\TwoTrigFunctions"]];


If[ElementaryFunctionTest, IntegrationTest["TrigFunctions\\TrigFunctions"]];


(* ::Subsection::Closed:: *)
(*Trig combo functions integration test*)


If[ElementaryFunctionTest, IntegrationTest["TrigFunctions\\TP1.1 x^m sin(a+b x^n)^p"]];


If[ElementaryFunctionTest, IntegrationTest["TrigFunctions\\TP1.2 x^m cos(a+b x^n)^p"]];


If[ElementaryFunctionTest, IntegrationTest["TrigFunctions\\TP1.5 x^m sec(a+b x^n)^p"]];


If[ElementaryFunctionTest, IntegrationTest["TrigFunctions\\TP1.6 x^m csc(a+b x^n)^p"]];


If[ElementaryFunctionTest, IntegrationTest["TrigFunctions\\sin(x)^m (a+a sin(x))^n"]];


If[ElementaryFunctionTest, IntegrationTest["TrigFunctions\\sin(x)^m (a+b sin(x))^n"]];


If[ElementaryFunctionTest, IntegrationTest["TrigFunctions\\cos(x)^m (b cos(x))^n"]];


If[ElementaryFunctionTest, IntegrationTest["TrigFunctions\\cos(x)^m (a+a cos(x))^n"]];


If[ElementaryFunctionTest, IntegrationTest["TrigFunctions\\cos(x)^m (a+b cos(x))^n"]];


If[ElementaryFunctionTest, IntegrationTest["TrigFunctions\\sec(x)^m (b sec(x))^n"]];


If[ElementaryFunctionTest, IntegrationTest["TrigFunctions\\sec(x)^m (a+a sec(x))^n"]];


If[ElementaryFunctionTest, IntegrationTest["TrigFunctions\\sec(x)^m (a+b sec(x))^n"]];


If[ElementaryFunctionTest, IntegrationTest["TrigFunctions\\csc(x)^m (a+a csc(x))^n"]];


If[ElementaryFunctionTest, IntegrationTest["TrigFunctions\\csc(x)^m (a+b csc(x))^n"]];


(* ::Subsection::Closed:: *)
(*Inverse trig function integration test*)


If[ElementaryFunctionTest, IntegrationTest["InverseTrigFunctions\\InverseSineFunctions"]];


If[ElementaryFunctionTest, IntegrationTest["InverseTrigFunctions\\InverseCosineFunctions"]];


If[ElementaryFunctionTest, IntegrationTest["InverseTrigFunctions\\InverseTangentFunctions"]];


If[ElementaryFunctionTest, IntegrationTest["InverseTrigFunctions\\InverseCotangentFunctions"]];


If[ElementaryFunctionTest, IntegrationTest["InverseTrigFunctions\\InverseSecantFunctions"]];


If[ElementaryFunctionTest, IntegrationTest["InverseTrigFunctions\\InverseCosecantFunctions"]];


(* ::Subsection::Closed:: *)
(*Hyperbolic function integration test*)


If[ElementaryFunctionTest, IntegrationTest["HyperbolicFunctions\\HyperbolicSineFunctions"]];


If[ElementaryFunctionTest, IntegrationTest["HyperbolicFunctions\\HyperbolicCosineFunctions"]];


If[ElementaryFunctionTest, IntegrationTest["HyperbolicFunctions\\HyperbolicTangentFunctions"]];


If[ElementaryFunctionTest, IntegrationTest["HyperbolicFunctions\\HyperbolicCotangentFunctions"]];


If[ElementaryFunctionTest, IntegrationTest["HyperbolicFunctions\\HyperbolicSecantFunctions"]];


If[ElementaryFunctionTest, IntegrationTest["HyperbolicFunctions\\HyperbolicCosecantFunctions"]];


If[ElementaryFunctionTest, IntegrationTest["HyperbolicFunctions\\TwoHyperbolicFunctions"]];


If[ElementaryFunctionTest, IntegrationTest["HyperbolicFunctions\\HyperbolicFunctions"]];


(* ::Subsection::Closed:: *)
(*Inverse hyperbolic function integration test*)


If[ElementaryFunctionTest, IntegrationTest["InverseHyperbolicFunctions\\InverseHyperbolicSineFunctions"]];


If[ElementaryFunctionTest, IntegrationTest["InverseHyperbolicFunctions\\InverseHyperbolicCosineFunctions"]];


If[ElementaryFunctionTest, IntegrationTest["InverseHyperbolicFunctions\\InverseHyperbolicTangentFunctions"]];


If[ElementaryFunctionTest, IntegrationTest["InverseHyperbolicFunctions\\InverseHyperbolicCotangentFunctions"]];


If[ElementaryFunctionTest, IntegrationTest["InverseHyperbolicFunctions\\InverseHyperbolicSecantFunctions"]];


If[ElementaryFunctionTest, IntegrationTest["InverseHyperbolicFunctions\\InverseHyperbolicCosecantFunctions"]];


(* ::Subsection::Closed:: *)
(*Special function integration test*)


If[InverseFunctionTest, IntegrationTest["SpecialFunctions\\ErrorFunctions"]];


If[InverseFunctionTest, IntegrationTest["SpecialFunctions\\FresnelIntegralFunctions"]];


If[InverseFunctionTest, IntegrationTest["SpecialFunctions\\ExponentialIntegralFunctions"]];


If[InverseFunctionTest, IntegrationTest["SpecialFunctions\\TrigIntegralFunctions"]];


If[InverseFunctionTest, IntegrationTest["SpecialFunctions\\HyperbolicIntegralFunctions"]];


If[InverseFunctionTest, IntegrationTest["SpecialFunctions\\LogarithmIntegralFunctions"]];


If[InverseFunctionTest, IntegrationTest["SpecialFunctions\\GammaFunctions"]];


If[InverseFunctionTest, IntegrationTest["SpecialFunctions\\ZetaFunctions"]];


If[InverseFunctionTest, IntegrationTest["SpecialFunctions\\PolylogarithmFunctions"]];


If[InverseFunctionTest, IntegrationTest["SpecialFunctions\\ProductLogarithmFunctions"]];


If[InverseFunctionTest, IntegrationTest["ContributedProblems"]];


(* ::Subsection:: *)
(*Test suite statistics*)


PrintTestStatistics[];
