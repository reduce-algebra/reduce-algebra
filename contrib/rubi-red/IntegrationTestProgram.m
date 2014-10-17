(* ::Package:: *)

(* ::Title:: *)
(*Integration test program*)


Unprotect[Sinc];
Sinc[u_] := Sin[u]/u;
Protect[Sinc];


Unprotect[Int];
DownValues[Int]={};


If[IntegrationFunction===Int,
  Get[RulesDirectory<>"ShowStep.m"];
  ShowSteps=True;
  Get[RulesDirectory<>"IntegrationUtilityFunctions.m"];
  Get[RulesDirectory<>"DebugFunctions.m"];

If[TIPTest===True,
  Get[RulesDirectory<>"SumRules.m"];
  Get[RulesDirectory<>"TR3.1 tan^m (a+b tan)^n.m"];
  Get[RulesDirectory<>"TR3.2 tan^m (A+B tan) (a+b tan)^n.m"];
  Get[RulesDirectory<>"TR3.3 tan^m (A+B tan+C tan^2) (a+b tan)^n.m"]];

If[Not[TIPTest===True],
  Get[RulesDirectory<>"R1 Monomial Functions\\R1 a u+b v+... .m"];

  Get[RulesDirectory<>"R2 Binomial Functions\\R2.1.1 (a+b x)^m.m"];
  Get[RulesDirectory<>"R2 Binomial Functions\\R2.1.2 (a+b x)^m (c+d x)^n.m"];
  Get[RulesDirectory<>"R2 Binomial Functions\\R2.1.3 (a+b x)^m (c+d x)^n (e+f x)^p.m"];
  Get[RulesDirectory<>"R2 Binomial Functions\\R2.1.4 (A+B x) (a+b x)^m (c+d x)^n (e+f x)^p.m"];

  Get[RulesDirectory<>"R2 Binomial Functions\\R2.2.1 (a+b x^n)^p.m"];
  Get[RulesDirectory<>"R2 Binomial Functions\\R2.2.2 x^m (a+b x^n)^p.m"];
  Get[RulesDirectory<>"R2 Binomial Functions\\R2.2.3 (a+b x^n)^m (c+d x^n)^p.m"];
  Get[RulesDirectory<>"R2 Binomial Functions\\R2.2.4 x^m (a+b x^n)^p (c+d x^n)^q.m"];
  Get[RulesDirectory<>"R2 Binomial Functions\\R2.2.5 (a+b x^n)^m (c+d x^n)^p (e+f x^n)^q.m"];
  Get[RulesDirectory<>"R2 Binomial Functions\\R2.2.6 x^m (A+B x^n) (a+b x^n)^p (c+d x^n)^q.m"];
  Get[RulesDirectory<>"R2 Binomial Functions\\R2.2.7 x^m P[x] (a+b x^n)^p.m"];

  Get[RulesDirectory<>"R2 Binomial Functions\\R2.3.1 (a x^q+b x^n)^p.m"];
  Get[RulesDirectory<>"R2 Binomial Functions\\R2.3.2 x^m (a x^q+b x^n)^p.m"];

  Get[RulesDirectory<>"R3 Trinomial Functions\\R3.1.1 (a+b x+c x^2)^p.m"];
  Get[RulesDirectory<>"R3 Trinomial Functions\\R3.1.2 (d+e x)^m (a+b x+c x^2)^p.m"];
  Get[RulesDirectory<>"R3 Trinomial Functions\\R3.1.3 (d+e x)^m (A+B x) (a+b x+c x^2)^p.m"];
  Get[RulesDirectory<>"R3 Trinomial Functions\\R3.1.4 (a+b x+c x^2)^m (d+e x+f x^2)^p.m"];
  Get[RulesDirectory<>"R3 Trinomial Functions\\R3.1.5 (A+B x) (a+b x+c x^2)^m (d+e x+f x^2)^p.m"];

  Get[RulesDirectory<>"R3 Trinomial Functions\\R3.2.1 (a+b x^n+c x^(2 n))^p.m"];
  Get[RulesDirectory<>"R3 Trinomial Functions\\R3.2.2 (A+B x^n) (a+b x^n+c x^(2 n))^p.m"];
  Get[RulesDirectory<>"R3 Trinomial Functions\\R3.2.3 x^m (a+b x^n+c x^(2 n))^p.m"];
  Get[RulesDirectory<>"R3 Trinomial Functions\\R3.2.4 x^m (A+B x^n) (a+b x^n+c x^(2 n))^p.m"];
  Get[RulesDirectory<>"R3 Trinomial Functions\\R3.2.5 x^m P[x] Q[x]^p.m"]; 

  Get[RulesDirectory<>"R3 Trinomial Functions\\R3.3.1 (a x^q+b x^n+c x^(2 n-q))^p.m"];
  Get[RulesDirectory<>"R3 Trinomial Functions\\R3.3.2 (A+B x^(n-q)) (a x^q+b x^n+c x^(2 n-q))^p.m"];
  Get[RulesDirectory<>"R3 Trinomial Functions\\R3.3.3 x^m (a x^q+b x^n+c x^(2 n-q))^p.m"];
  Get[RulesDirectory<>"R3 Trinomial Functions\\R3.3.4 x^m (A+B x^(n-q)) (a x^q+b x^n+c x^(2 n-q))^p.m"];

  Get[RulesDirectory<>"ExponentialFunctions\\ExponentialFunctions.m"];
  Get[RulesDirectory<>"ExponentialFunctions\\ProductsOfExponentialAndTrigFunctions.m"];
  Get[RulesDirectory<>"ExponentialFunctions\\ProductsOfExponentialAndHyperbolicFunctions.m"];
  Get[RulesDirectory<>"ExponentialFunctions\\LogarithmFunctions.m"];

  Get[RulesDirectory<>"TrigFunctions\\TR1.1 sin^m (a+b sin)^n.m"];
  Get[RulesDirectory<>"TrigFunctions\\TR1.2 sin^m (A+B sin) (a+b sin)^n.m"];
  Get[RulesDirectory<>"TrigFunctions\\TR1.3 sin^m (A+B sin+C sin^2) (a+b sin)^n.m"];

  Get[RulesDirectory<>"TrigFunctions\\TR2.1 csc^m (a+b csc)^n.m"];
  Get[RulesDirectory<>"TrigFunctions\\TR2.2 csc^m (A+B csc) (a+b csc)^n.m"];
  Get[RulesDirectory<>"TrigFunctions\\TR2.3 csc^m (A+B csc+C csc^2) (a+b csc)^n.m"];

  Get[RulesDirectory<>"TrigFunctions\\TR5.1 x^m sin(a+b x^n)^p.m"];
  Get[RulesDirectory<>"TrigFunctions\\TR5.2 x^m sec(a+b x^n)^p.m"];

  Get[RulesDirectory<>"TrigFunctions\\TrigNormalization.m"];
  Get[RulesDirectory<>"TrigFunctions\\SineFunctions.m"];
  Get[RulesDirectory<>"TrigFunctions\\TangentFunctions.m"];
  Get[RulesDirectory<>"TrigFunctions\\SecantFunctions.m"];
  Get[RulesDirectory<>"TrigFunctions\\RationalFunctionsOfSinesAndCosines.m"];
  Get[RulesDirectory<>"TrigFunctions\\TwoTrigFunctions.m"];
  Get[RulesDirectory<>"TrigFunctions\\TrigSubstitution.m"];

  Get[RulesDirectory<>"HyperbolicFunctions\\HyperbolicSineFunctions.m"];
  Get[RulesDirectory<>"HyperbolicFunctions\\HyperbolicTangentFunctions.m"];
  Get[RulesDirectory<>"HyperbolicFunctions\\HyperbolicSecantFunctions.m"];
  Get[RulesDirectory<>"HyperbolicFunctions\\RationalFunctionsOfHyperbolicSines.m"];
  Get[RulesDirectory<>"HyperbolicFunctions\\RationalFunctionsOfHyperbolicSinesAndCosines.m"];
  Get[RulesDirectory<>"HyperbolicFunctions\\TwoHyperbolicFunctions.m"];
  Get[RulesDirectory<>"HyperbolicFunctions\\HyperbolicSubstitution.m"];

  Get[RulesDirectory<>"InverseTrigFunctions\\InverseSineFunctions.m"];
  Get[RulesDirectory<>"InverseTrigFunctions\\InverseTangentFunctions.m"];
  Get[RulesDirectory<>"InverseTrigFunctions\\InverseSecantFunctions.m"];

  Get[RulesDirectory<>"InverseHyperbolicFunctions\\InverseHyperbolicSineFunctions.m"];
  Get[RulesDirectory<>"InverseHyperbolicFunctions\\InverseHyperbolicTangentFunctions.m"];
  Get[RulesDirectory<>"InverseHyperbolicFunctions\\InverseHyperbolicSecantFunctions.m"];

  Get[RulesDirectory<>"SpecialFunctions\\ErrorFunctions.m"];
  Get[RulesDirectory<>"SpecialFunctions\\FresnelIntegralFunctions.m"];
  Get[RulesDirectory<>"SpecialFunctions\\ExponentialIntegralFunctions.m"];
  Get[RulesDirectory<>"SpecialFunctions\\TrigIntegralFunctions.m"];
  Get[RulesDirectory<>"SpecialFunctions\\HyperbolicIntegralFunctions.m"];
  Get[RulesDirectory<>"SpecialFunctions\\LogarithmIntegralFunctions.m"];
  Get[RulesDirectory<>"SpecialFunctions\\GammaFunctions.m"];
  Get[RulesDirectory<>"SpecialFunctions\\ZetaFunctions.m"];
  Get[RulesDirectory<>"SpecialFunctions\\PolylogarithmFunctions.m"];
  Get[RulesDirectory<>"SpecialFunctions\\ProductLogarithmFunctions.m"];

  Get[RulesDirectory<>"MiscellaneousFunctions\\CalculusFunctions.m"];

  Get[RulesDirectory<>"R1 Monomial Functions\\R8 Miscellaneous integration rules.m"];
(*
  Get[RulesDirectory<>"GeneralIntegrationRules.m"];
*)];
  FixIntRules[];
  StepFunction[Int];

  ShowSteps=False,
Mods[u_] := ArcTan[Tan[Pi*u]]/Pi];


IntegrationTest[fileName_]:=
  Module[{func=IntegrationFunction, computeTime=0, realTime=0,
		timeouts=0, unintegrables=0, nonidenticals=0, incorrects=0, corrects=0,
		problem, summary, integrand, variable, steps, answer1, answer2, result, stepctr,
        leafcountanswer,
		IntegrationTime, ProblemTime, tmp, lst},
  ShowSteps=False;
(*Print["Running integrator test suite file "<>ToString[fileName]<>".m ..."]; Print[]; *)
  lst=ReadList[ProblemsDirectory<>ToString[fileName]<>".m"];
  If[lst===$Failed,
    Return[False]];
  lst=Select[lst,Function[#=!=Null]];
  ( If[Length[lst]==1 && ListQ[lst[[1]]] && ListQ[lst[[1,1]]],
	  lst=lst[[1]]] );
  lst=Select[lst,Function[#=!=Null]];
  ( If[func===Internal,
	  lst=Select[lst,Function[FreeQ[#,Int]]]] );
  ( If[IntegerQ[MaximumSteps] && MaximumSteps>=0,
      lst=Select[lst,Function[#[[3]]<=MaximumSteps]]] );
  ( If[MakeTestSuite=!=True, Print[If[func===Int,"Testing Rubi on ",
        If[func===Integrate,"Testing Mathematica on ",
        If[func===Internal,"Testing validity of test suite antiderivatives on ",
        "IntegrationFunction has invalid value"]]],Length[lst]," integration problems..."]] );
  realTime=SessionTime[];
  KnownProblemCount=0;
  Monitor[
  Do[
    ClearSystemCache[];
    problem=lst[[i]];
	If[PrintProblems, Print["#",i,": ",Take[problem,3]]];
    ProblemTime=SessionTime[];
    integrand=problem[[1]];
    variable=problem[[2]];
    steps=problem[[3]];
    answer1=problem[[4]];
    answer2=If[Length[problem]>=5, problem[[5]], Null];
    summary={integrand, variable, steps, 0};
    leafcountanswer=LeafCount[answer1];
    result=0;

    If[func===Internal,                      (* Compare derivative of result with integrand *)
      IntegrationTime=0.1;
      If[answer1===0,
        Null,
      If[Not[FreeQ[answer1,Int]],
		If[answer2===Null ||Not[FreeQ[answer2,Int]],
		  corrects++,
        If[ValidAntiderivative[answer2,integrand,variable,40],
          corrects++,
        Beep[];
  	  incorrects++;
        DisplayDeficiency[{"Incorrect antiderivative:", summary, answer2}]]],
      If[ValidAntiderivative[answer1,integrand,variable,40],
		If[answer2===Null ||Not[FreeQ[answer2,Int]],
		  corrects++,
        If[ValidAntiderivative[answer2,integrand,variable,40],
          corrects++,
        Beep[];
  	  incorrects++;
        DisplayDeficiency[{"Incorrect antiderivative:", summary, answer2}]]],
      Beep[];
	  incorrects++;
      DisplayDeficiency[{"Incorrect antiderivative:", summary, answer1}]]]],

(* Following integrals causes an uninterruptable hang of Mathematica 8, but not 7! *) 
    If[func===Integrate && $VersionNumber==8.0 && (
		integrand===Cos[c + d*x]^(-7/2)*(A + B*Cos[c + d*x] + C*Cos[c + d*x]^2)*(a + b*Cos[c + d*x])^(1/2) ||
		integrand===Tan[x]/Sqrt[a + b*Cot[x]^2 + c*Cot[x]^4] ||
		integrand===Cot[x]^3/Sqrt[a + b*Cot[x]^2 + c*Cot[x]^4]),
	  unintegrables++;
      DisplayDeficiency[{"Unable to integrate:", summary, answer1, "* * *  Integration causes an uninterruptable hang of Mathematica 8!  * * *"}],

    StepCounter=0;
    {IntegrationTime,result}=TimeConstrained[Timing[func[integrand,variable]],60,{0,"Timed out"}];
	computeTime=computeTime + IntegrationTime;
    stepctr=StepCounter;
    TotalSteps=stepctr+TotalSteps;
    summary={integrand, variable, steps, stepctr};

	If[result==="Timed out",
	  timeouts++;
      DisplayDeficiency[{"Timed out after 60 seconds:", summary, answer1, "???"}],
    If[func===Integrate && Not[FreeQ[answer1,Int]],
      corrects++,

(* Compare result with desired result *)
    If[result===answer1,
      DisplayStepInfo[func,stepctr,steps,problem,answer2=!=Null];
	  corrects++,
    If[result===answer2,
      DisplayStepInfo[func,stepctr,steps,problem,False];
	  corrects++,

    If[LeafCount[result]>=10000,
	  nonidenticals++;
      DisplayDeficiency[{"Unnecessarily complicated antiderivative not verified due to huge size:", summary, answer1, 
		"* * *  Result of integration not displayed since its leaf count is "<>ToString[LeafCount[result]]<>"  * * *"}],

    If[result===answer1,
      DisplayStepInfo[func,stepctr,steps,problem,answer2=!=Null];
	  corrects++,
    If[result===answer2,
      DisplayStepInfo[func,stepctr,steps,problem,False];
	  corrects++,

    If[Not[FreeQ[result,func]] (* && Not[FreeQ[Simplify[result],func]] *),
      If[func===Int && Not[FreeQ[answer1,Int]],
  	  nonidenticals++;
        DisplayDeficiency[{"Valid but unnecessarily complicated antiderivative:", summary, answer1, result}],
      If[func===Integrate &&
			Head[result]===Integrate && Head[answer1]===Int &&
			result[[1]]===answer1[[1]],
	    corrects++,
	  unintegrables++;
      DisplayDeficiency[{"Unable to integrate:", summary, answer1, result}]]],
    If[Not[HypergeometricFreeQ[result]] && HypergeometricFreeQ[answer1],
	  nonidenticals++;
      DisplayDeficiency[{"Valid but unnecessarily complicated antiderivative:", summary, answer1, result}],

    ( If[func===Integrate,
        tmp=TimeConstrained[Simplify[result],30,False];
        If[tmp=!=False, result=tmp]] );
    If[result===answer1,
      DisplayStepInfo[func,stepctr,steps,problem,answer2=!=Null];
	  corrects++,
    If[result===answer2,
      DisplayStepInfo[func,stepctr,steps,problem,False];
	  corrects++,

(* Temporary hack!!! *)
(*  If[func===Int && stepctr==steps && FullSimplify[result-answer1]===0,
	  corrects++,
*)
    If[ValidAntiderivative[result,integrand,variable,60,answer1],
	  tmp=LeafCount[result]/leafcountanswer;
      If[func===Integrate && tmp<125/100,
	    corrects++;
        If[tmp<75/100 && leafcountanswer>10 && 
				Not[Not[FreeQ[result,Complex]] && FreeQ[answer1,Complex]] &&
				Not[PossibleZeroQ[Simplify[result-answer1]]],
          tmp=TimeConstrained[Simplify[answer1],10,False];
          If[tmp===False || LeafCount[result]/LeafCount[tmp]<75/100,
            DisplayDeficiency[{"Mathematica gives a simpler antiderivative!:", summary, answer1, result}]]],
	  nonidenticals++;
      DisplayDeficiency[If[Not[answer2===Null] && func===Int,
		{"Valid but not equal to optimal or suboptimal answer:", summary, answer1, answer2, result},
		{"Valid but unnecessarily complicated antiderivative:", summary, answer1, result}]]],
    Beep[];
	incorrects++;
    DisplayDeficiency[{"Incorrect antiderivative:", summary, answer1, result}]]]]]]]]]]]]]]];

    ProblemTime=SessionTime[]-ProblemTime;
    ( If[IntegerQ[ProblemTimeLimit] && ProblemTime>ProblemTimeLimit && MakeTestSuite=!=True,
        Print["Problem Time: ",NumberForm[ProblemTime,3], " seconds   Problem #",i,": ",Take[problem,3]]; Print[]] );
    ( If[func===Int && stepctr>MaxStep[[1]],
        MaxStep={stepctr, steps, integrand}] );
    ( If[Not[func===Internal] && LeafCount[result]>MaxSize[[1]],
        MaxSize={LeafCount[result], IntegrationTime, leafcountanswer, stepctr, integrand}] );
    ( If[Not[func===Internal] && IntegrationTime>MaxTime[[2]],
        MaxTime={LeafCount[result], IntegrationTime, leafcountanswer, stepctr, integrand}] );
    If[NumberQ[FlagProblemTime] && ProblemTime>=FlagProblemTime,
	   Print["#",i," time: ",NumberForm[IntegrationTime,3]," - ",NumberForm[ProblemTime,3],
			" problem: ",Take[problem,3]]],

	{i,1,Length[lst]}],
  ProgressIndicator[i,{1,Length[lst]+1}]];

  tmp=StringPosition[ToString[fileName],"\\"];
  tmp=If[Length[tmp]>0, StringDrop[ToString[fileName],First[Last[tmp]]], ToString[fileName]];
  computeTime=Max[computeTime,0.01];
  realTime=SessionTime[]-realTime;
  AppendTo[testStatistics, {tmp,
		corrects,nonidenticals,unintegrables,timeouts,incorrects,Length[lst],computeTime,realTime}];
  If[KnownProblemCount>0,
    Print[KnownProblemCount, " known problem", If[KnownProblemCount>1, "s", ""], " not displayed"]]];


HypergeometricFreeQ[u_] :=
  FreeQ[u,Hypergeometric1F1] && FreeQ[u,Hypergeometric2F1] && FreeQ[u,HypergeometricPFQ] && FreeQ[u,AppellF1] && FreeQ[u,RootSum]


DisplayStepInfo[func_,stepctr_,steps_,problem_,flag_] :=
  If[func===Int && ShowStepInfo=!=False,
    If[MakeTestSuite===True,
      PrintTestProblem[problem[[1]], problem[[2]], steps, problem[[4]]],
    If[flag, Print["Yea; optional answer unnecessary!"]; Print[problem]; Print[]];
    If[steps<0,
      Print["Yea; finally got a known problem in ",stepctr," steps!"]; Print[problem]; Print[],    
    If[stepctr>steps,
      Print["Boo; correct but ",stepctr," steps required!"]; Print[problem]; Print[],
    If[stepctr<steps,
      Print["Yea; correct and only ",stepctr," steps required!"]; Print[problem]; Print[]]]]]]


DisplayDeficiency[lst_] :=
  If[HideKnownProblems && IntegrationFunction===Int && IntegerQ[lst[[2,3]]] && lst[[2,3]]<0 && (-lst[[2,3]]===lst[[2,4]] || lst[[2,3]]===-1 && lst[[2,4]]===0),
    KnownProblemCount++,
  If[MakeTestSuite===True && (lst[[1]]==="Valid but unnecessarily complicated antiderivative:" || lst[[1]]==="Unable to integrate:"),
    PrintTestProblem[lst[[2,1]], lst[[2,2]], lst[[2,4]], lst[[4]]],
  If[ShowDeficiencies,
    Scan[Print,lst];
(*  Scan[Function[Print[Style[#,FontSize->10]]],lst]; *)
    Print[]]]]


PrintTestProblem[integrand_,variable_,steps_,antiderivative_] :=
  Print["{" <> ToString[integrand,InputForm] <> ", " <> ToString[variable,InputForm] <> ", " <> ToString[steps,InputForm] <> ", " <> ToString[antiderivative,InputForm] <> "}"]


(* If the derivative of antiderivative wrt variable equals integrand, 
	ValidAntiderivative[antiderivative,integrand,variable,maxtime] returns True; else it returns False. *)
ValidAntiderivative[antiderivative_,integrand_,variable_,maxtime_] :=
  Module[{dif}, 
  TimeConstrained[
      dif=If[Head[antiderivative]===Plus, Simplify[Map[Function[Simplify[D[#,variable]]],antiderivative]], Simplify[D[antiderivative,variable]]];
      dif===integrand ||
      TimeConstrained[PossibleZeroQ[FullSimplify[dif-integrand]],maxtime/2,False] ||
      TimeConstrained[PossibleZeroQ[FullSimplify[FullSimplify[dif]-integrand]],maxtime/2,False],
    maxtime,False]];

ValidAntiderivative[antiderivative_,integrand_,variable_,maxtime_,answer_] :=
  Module[{dif}, 
  TimeConstrained[
      dif=If[Head[antiderivative]===Plus, Simplify[Map[Function[Simplify[D[#,variable]]],antiderivative]], Simplify[D[antiderivative,variable]]];
      dif===integrand ||
      TimeConstrained[PossibleZeroQ[Simplify[dif-integrand]],maxtime/8,False] ||
      IntegrationFunction===Int && TimeConstrained[PossibleZeroQ[Simplify[dif-
		If[Head[answer]===Plus, Simplify[Map[Function[Simplify[D[#,variable]]],answer]], Simplify[D[answer,variable]]]]],maxtime/8,False] ||
      TimeConstrained[PossibleZeroQ[FullSimplify[dif-integrand]],maxtime/2,False] ||
      TimeConstrained[PossibleZeroQ[FullSimplify[FullSimplify[dif]-integrand]],maxtime/2,False],
    maxtime,False]]


testStatistics={};
MaxStep={0,0,0};
MaxSize={0,0,0,0,0};
MaxTime={0,0,0,0,0};
TotalSteps=0;

PrintTestStatistics[] :=
  Module[{lst=testStatistics,testFiles,problemCounts,integrationRates,realTimes,totalProblems,percentages},
  If[lst==={},
    Null,
  testStats=testStatistics;
  testStatistics={};
  lst=Transpose[lst];
  lst=Join[{Append[First[lst],"Totals"]}, Map[Function[Append[#,Apply[Plus,#]]],Rest[lst]]];
  testFiles=lst[[1]];
  integrationRates=Map2[Function[PaddedForm[N[#1/#2],{3,1}]],lst[[7]],lst[[8]]];
  realTimes=Map[Function[PaddedForm[#,{5,1}]],lst[[9]]];
  problemCounts=Take[lst,{2,7}];
  totalProblems=Last[Last[problemCounts]];
  percentages=Map[Function[Quiet[ToString[PaddedForm[N[100*#/totalProblems],{4,2}]]<>"%"]],Map[Last,problemCounts]];
  lst=Join[{{"File","Optimal"," Nonident"," Unintegrable"," Timeout"," Invalid","Total","Int/sec"," Time"}},
           Transpose[Join[{testFiles},problemCounts,{integrationRates,realTimes}]],
           {Join[{"Percentages"},percentages,{"",""}]}];
  lst=Transpose[lst];
  SetOptions[$Output[[1]],PageWidth->Infinity];
  Print[];
  Print["               * * *  Indefinite Integration Test Suite Results  * * *"];
  Print[];
  ( If[IntegrationFunction===Int,
      Print[" Integration function:  Rubi 4's user-defined Int function"],
    If[IntegrationFunction===Integrate,
      Print[" Integration function:  Mathematica's built-in Integrate function"]]] );
  ( If[IntegerQ[MaximumSteps] && MaximumSteps>=0,
      Print["   Maximum step limit:  ", MaximumSteps]] );
  Print["Time and date of test:  ",DateString[{"Hour24",":","Minute","  ","Day"," ","MonthName"," 2010"}]];
  Print["  Mathematica version:  ",$Version];
  Print[];
  ( If[IntegrationFunction===Int,
      Print["Integration rules defined: ",Quiet[Length[DownValues[Int]]]];
      Print["Integration rules applied: ",TotalSteps];
      TotalSteps=0] );
  ( If[IntegrationFunction===Int,
      Print["Maximum steps used: ",MaxStep[[1]]," steps   Optimal steps: ",MaxStep[[2]]," steps   Integrand: ",MaxStep[[3]]];
      MaxStep={0,0,0,0,0}] );
  Print["Largest result size: ",MaxSize[[1]]," leaves   Optimal size: ",MaxSize[[3]]," leaves   Integrand: ",MaxSize[[5]]];
  MaxSize={0,0,0,0,0};
  Print["Longest compute time: ",MaxTime[[2]]," seconds   Result size: ",MaxTime[[1]]," leaves   Integrand: ",MaxTime[[5]]];
  MaxSize={0,0,0,0,0};
  Print[];
  Apply[Print,Map[Function[Column[#,Center,1]],lst]];
  Speak["all pow"]; (* Beep[]; *)
  Null]]

Map2[func_,lst1_,lst2_] :=
  Reap[Do[Sow[func[lst1[[i]],lst2[[i]]]],{i,Length[lst1]}]][[2,1]]
